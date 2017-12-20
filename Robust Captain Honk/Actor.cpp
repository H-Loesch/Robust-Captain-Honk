#include "stdafx.h"
#include "Actor.h"
#include "Randomization.h"
#include <string>

Actor::Actor() {
	health = 45;
	magic = 30;
	name = "placeholder";
}

Actor::Actor(int healthStart, int magicStart, std::string nameStart) {
	health = healthStart;
	magic = magicStart;
	name = nameStart;
}

Actor::Actor(int healthStart, int magicStart) {
	health = healthStart;
	magic = magicStart;
	name = enemy_name();
}

int Actor::get_health() {
	return health;
}

int Actor::get_magic() {
	return magic;
}

std::string Actor::getName() {
	return name;
}

//action functions

void Actor::heal() {
	//increase health by amount equal to random number within healLow-healHigh, decrease magic by amount
	mod_health(get_random(healLow, healHigh));
	mod_magic(-get_random(healCostLow, healCostHigh));
}

void Actor::attack(Actor* enemy) {
	//decrease enemy health by amount within the attacker's damageLow-damageHigh range
	enemy->mod_health(-get_random(damageLow, damageHigh));
}

void Actor::recharge() {
	mod_magic(get_random(rechargeLow, rechargeHigh));
}

void Actor::steal(Actor* enemy) {
	int change = get_random(stealLow, stealHigh);
	mod_magic(change);
	enemy->mod_magic(-change);
}

//internal functions

void Actor::set_health(int newHealth) {
	health = newHealth;
}

void Actor::set_magic(int newMagic) {
	magic = newMagic;
}

void Actor::mod_health(int change) {
	health += change;
}

void Actor::mod_magic(int change) {
	magic += change;
}

std::string Actor::getOut() {
	return outputStatement;
}