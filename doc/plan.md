# CC3k Plan of Attack

**Group Members**: Jesse Rogers (20415011)

## Project Breakdown

1. Generate/write header files for all classes
     - estimate: 2h, nov. 22
2. Implement basic functionality in `Game`, `PlayerCharacter`, `Floor`, `Chamber`, `Cell`,
   `Character`, `Widget` and `TextDisplay` in order to be able to display the game board.
     - implementing game loop (checking `player.is_alive()`)
     - implementing command interpreter
     - reading default layout into floor, creating cells for each
     - creating chambers from cells
     - creating a basic `Character` implementation
     - creating a basic `PlayerCharacter` implementation
     - placing `PlayerCharacter` at a fixed location
     - implementing `TextDisplay` using observer pattern
     - estimate: 5h, nov. 23
3. Implement movement
     - hostile random movement
     - player directed movement
     - estimate: 0.5h, nov. 24
8. Implement `attack` and `defend` using visitor pattern
     - estimate: 0.5h, nov. 24
4. Implement `PlayerCharacter` classes
     - estimate: 2h, nov. 25
5. Implement `Item` classes
     - estimate 1h, nov. 26
6. Implement `Hostile` classes
     - estimate 2h, nov. 27
7. Implement `Buff` classes using decorator pattern
     - estimate 2h, nov. 28
8. Testing
     - estimate 5h, nov. 29

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
