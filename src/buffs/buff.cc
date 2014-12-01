#include "buff.h"
#include "../debug.h"

Buff::Buff(PlayerCharacter *pc) : PlayerCharacter(0, 0, 0, 0), component(pc) {}

Buff::~Buff() {
  if (dynamic_cast<Buff*>(component)) {
    delete component;
  }
}

void Buff::set_pos(Cell *pos) {
  component->set_pos(pos);
}

Cell *Buff::get_pos() const {
  return component->get_pos();
}

bool Buff::is_pathable(terrain_t t) const {
  return component->is_pathable(t);
}

bool Buff::move(direction_t dir) {
  return component->move(dir);
}

int Buff::attack(Character &other) {
  DEBUG("1");
  int tmp = component->get_atk();
  DEBUG("2");
  int atk = get_atk();
  DEBUG("2.5");
  component->set_atk(atk);
  DEBUG("3");
  int dmg = component->attack(other);
  DEBUG("4");
  component->set_atk(tmp);
  DEBUG("5");
  return dmg;
}

int Buff::attack(Merchant &other) {
  int tmp = component->get_atk();
  component->set_atk(get_atk());
  int dmg = component->attack(other);
  component->set_atk(tmp);
  return dmg;
}

int Buff::defend(Character &other) {
  int tmp = component->get_def();
  component->set_def(get_def());
  int dmg = component->defend(other);
  component->set_def(tmp);
  return dmg;
}

bool Buff::did_move() {
  return component->did_move();
}

void Buff::reset() {
  return component->reset();
}

int Buff::get_health() {
  return component->get_health();
}

int Buff::get_atk() {
  return component->get_atk();
}

int Buff::get_def() {
  return component->get_def();
}

int Buff::get_gold() {
  return component->get_gold();
}

void Buff::set_health(int new_amount) {
  return component->set_health(new_amount);
}

void Buff::set_atk(int new_amount) {
  return component->set_atk(new_amount);
}

void Buff::set_def(int new_amount) {
  return component->set_def(new_amount);
}

void Buff::set_gold(int new_amount) {
  return component->set_gold(new_amount);
}

bool Buff::is_alive() {
  return component->is_alive();
}

int Buff::score() {
  return component->score();
}

char Buff::to_char() const {
  return component->to_char();
}

bool Buff::has_reached_stair() const {
  return component->has_reached_stair();
}

bool Buff::attacks_merchants() {
  return component->attacks_merchants();
}

void Buff::take_turn() {
  component->take_turn();
}

void Buff::did_kill(Character &c) {
  component->did_kill(c);
}

std::string Buff::race() {
  return component->race();
}
