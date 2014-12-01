# Final Design Document

The final design of this version of cc3k was very similar to the original UML proposed. The main differences were the inclusion
of singleton classes as factories to generate new widgets for each floor as well as sub-classing each type of gold so that it
behaves well with this new factory design. On a more granular level there were many more functions which were needed and many
that were not needed but provided nicer interfaces and thus were included.

## Implementation notes

### Attack/Defence

Attack and defence were accomplished using the visitor pattern so that the complex relationships between characters because of
their various abilities could be implemented. That way if a Vampire attacks any character he gains 5 HP, but by adding an
overloaded attack method for type Dwarf the vampire loses 5 HP:

```c++
class Vampire {
    ...
    public:
      Vampire();
      int attack(Character &other);
      int attack(Dwarf &other);
    ...
};
```

The defend method works in a similar way and is counterpart to attack; that is `attack` is equivalent to the `visit` method,
thus calling `defend` on the given character, and `defend` is the `accept` method, which resolves the result of the two
character's combat.

This code is dispersed throughout `src/characters`.

### Generators

All the generators for this project were written using the factory design pattern. Each type of generated widget had its
respective factory which would generate random objects of that type. All factories were singleton classes which used
shared much of their code via a template class which they all owned an instance of. This made it easy to generate the
required number of widgets of each type, which was done similar to

```c++
std::vector<Hostile*> hostiles(20);
std::generate(hostiles.begin(), hostiles.end(), HostileFactory::generate);
```

To be able to use function pointers to constructors a small template function was used. Overall it resulted in an interface
which registered generator functions like this:

```c++
int probability_a = 10;
int probability_b = 20;

Factory<Hostile*> factory;

factory.add(probability_a, creator<Hostile, Dwarf>);
factory.add(probability_a, creator<Hostile, Human>);
```

Which allowed it to be easily used for all generators.

This code can be found in `src/factories`.

### Temporary potion effects (Buffs)

Using the decorator pattern the temporary potion effects were modelled. This actually did present some problems because
it seems that the visitor pattern and the decorator pattern don't always get along so well (since your decorator sub-
classes a different class than the object it is decorating thus invoking different attack/defend methods than intended).
The implementation therefore temporarily adjusts the inner component atk/def then invokes attack/defend on the component.
Afterwards, I have thought of potentially better implementations such as `PlayerCharacter` being a decorator for buffs
but this seems to work fine for now and I didn't want to venture down a rabbit hole.

This code can be found in `src/buffs`.

## Conclusion

Throughout this project I strived to use good design practice and I think for in large part I have achieved that goal.
I noticed myself relying on dynamic casts in a few places which I would like to have avoided and perhaps with more time
I would have been able to come up with better approaches but they do seem efficient for some problems. I would also like
to make my display better since it could use a lot more information but that seemed less important than building the
functionality to me. I was also able to stick with the answers to the questions from my plan (included below for reference)
which was reassuring. `gdb` and a little debug macro I wrote found in `src/debug.h` came in great use over the course
of the project, as well as my `Makefile` and `git`.

Working by myself was both good and bad. This was much more work than I anticipated but it also meant I learnt a lot about
the design patterns I used because I had to implement them all myself. It also meant I could relax on documentation--which
is probably actually a bad thing even though it seems nice at the time, since it can really bite you later. Thankfully I was
naming my functions well enough I could mostly guess what I had previously written in their implementations.

If I could start over I would definitely spend more time on the planning phase trying to narrow down exactly what methods
I needed on each object to avoid object bloating and to reduce the coupling between objects. Since I wasn't 100% sure I ended
up making compromises which led to some strange circular dependencies which were sometimes tricky to resolve.

# Appendix

## Answers to Questions

**Question.** How could your design your system so that each race could be easily generated?
Additionally, how difficult does such a solution make adding additional classes?

If all the races are polymorphic are on a base player character class which implements most of the
functionality and the only tweaks are to the methods which it implements then all races can be
easily generated. It also makes it very easy to add additional classes because they can subclass
the basic player character class and implement the extra functionality. For instance, the vampire
class can overload the attack method so that any time it attacks it also gains 5 HP.

**Question.** How does your system handle generating different enemies? Is it different from how
you generate the player character? Why or why not?

The system will use a sort of factory method to generate 20 enemies (part 1). They will then be assigned
to chambers and the chamber will assign it to a random tile (part 2). The player character will not be
randomly selected; the human player will choose it, but after that it will be assigned to a chamber
and assigned to a random tile, just like part 2 of the enemy spawner. In fact, that code will most likely
be the same.

**Question.** How could you implement the various abilities for the enemy characters? Do you use
the same techniques as for the player character races? Explain.

All abilities, both enemy and player, will be implemented using the visitor pattern if they relate to
attack mechanics (which is almost all of them). They will use the default abstract character implementation
of attack and defend unless it is overridden by the attacker or defender. This allows for abilities to be
made by defining a custom attack/defend method.

**Question.** What design pattern could you use to model the effects of temporary potions (Wound/Boost
Atk/Def) so that you do not need to explicitly track which potions the player character has consumed on
any particular floor?

The decorator pattern could be used. In the UML diagram they are specified as buffs which are player
character decorators. The floor will keep a reference to the decorated (or, initially, undecorated)
player character object and the game will keep a reference to the undecorated object for when it needs
to initialize the next floor. Thus, when the character leaves the floor, the references to the
decorators won't be saved.

**Question.** How could you generate items so that the generation of Treasure and Potions reuses as
much code as possible? That is, how would you structure your system so that the generation of a potion
and then generation of treasure does not duplicate code?

By using a template method which acts as a factory you could reuse the exact same code to produce
different types of objects. The factory produces the different subclasses of a particular type (i.e.
all the different potions). The type and its respective probability of each subclass will be registered
with the factory and it will have a create function which returns an object of that the template type.
Separately, that method will be used in the standard library's generate algorithm which will result in a
list of objects of various subtypes of the template type.

![UML](doc/uml.svg)
