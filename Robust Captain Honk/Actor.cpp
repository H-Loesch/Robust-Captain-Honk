#include "stdafx.h"
#include "Actor.h"
#include "Randomization.h"
#include <string>
#include <sstream>

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
	name = "Player"; //You?
}

int Actor::get_health() {
	return health;
}

int Actor::get_magic() {
	return magic;
}

std::string Actor::get_name() {
	return name;
}

//action functions

void Actor::heal() {
	//increase health by amount equal to random number within healLow-healHigh, decrease magic by amount
	int healAmount = get_random(healLow, healHigh);
	int healCost = get_random(healCostLow, healCostHigh);
	mod_health(healAmount);
	mod_magic(-healCost);
	outputStatement << name << " uses " << healCost << " magic to heal for " << healAmount << "!" << std::endl;
}

void Actor::attack(Actor& enemy) {
	//decrease enemy health by amount within the attacker's damageLow-damageHigh range
	int damage = get_random(damageLow, damageHigh);
	enemy.mod_health(-damage);
	outputStatement << name << " attacks " << enemy.get_name() << " for " << damage << " damage!" << std::endl;
}

void Actor::recharge() {
	int magicGain = get_random(rechargeLow, rechargeHigh);
	mod_magic(magicGain);
	outputStatement << name << " recharges for " << magicGain << " magic!" << std::endl;
}

void Actor::steal(Actor& enemy) {
	int change = get_random(stealLow, stealHigh);
	mod_magic(change);
	enemy.mod_magic(-change);
	outputStatement << name << " steals " << change << " magic from " << enemy.get_name() << std::endl;
}

//internal functions

void Actor::become_player() {
	damageLow = 2;
	damageHigh = 6;
	healLow = 6;
	healHigh = 8;
	healCostLow = 1;
	healCostHigh = 3;
	rechargeLow = 4;
	rechargeHigh = 7;
	stealLow = 1;
	stealHigh = 1;
}

void Actor::become_enemy() {
	damageLow = 3;
	damageHigh = 6;
	healLow = 4;
	healHigh = 4;
	healCostLow = 4;
	healCostHigh = 4;
	rechargeLow = 0;
	rechargeHigh = 0;
	stealLow = 2;
	stealHigh = 3;
}

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

std::string Actor::get_out() {
	return outputStatement.str();
}

void Actor::set_out(std::string newString) {
	outputStatement.str(newString);
}