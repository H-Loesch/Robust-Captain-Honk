#include "stdafx.h"
/*#include "actor.h"
#include "overarch.h"
#include <string>
#include <iostream>

//this is all commented out because I couldn't get it to work the first time I wrote this program

void print_actor(Actor involved)
{
//std::cout << involved.name;
}


//This should PROBABLY have a thing where the attacking/healing/whatever character has its own values for damage/stuff, but...
//This program isn't really built to be expanded upon.
std::string attack(Actor attacker, Actor defender, int min, int max)
{
// player does 2-8 damage, enemy does 3-9
int damage = get_random(min, max);
defender.health -= damage;
//This will present problems if the player attacks themselves, but that shouldn't happen.
if (attacker.name == "Player") {
return "You attack for " + std::to_string(damage) + "damage!\n";
} else {
return attacker.name + " attacks for " + std::to_string(damage) + "!\n";
}
}

std::string heal(Actor involved, int min, int max)
{
//restores 6-14 health, uses 1-4 magic
//enemy restores 4 health always.
int healing{ get_random(min,max) };
int fee{ get_random(1,4) };
involved.health += healing;
involved.magic -= fee;
if (involved.name == "Player") {
return "You heal for " + std::to_string(healing) + ", using " + std::to_string(fee) + " magic.\n";
}
else {
return involved.name + " heals for " + std::to_string(healing) + "\n";
}
}

//enemy can't do this, so no min/max needed.
std::string recharge(Actor involved)
{
int gains{ get_random(4,11) };
involved.magic += gains;
return "You recharge for " + std::to_string(gains) + " magic!\n";
}

//player can't do this, so no min/max needed.
std::string steal(Actor thief, Actor target)
{
int illGoods{ get_random(3,5) };
thief.magic += illGoods;
target.magic -= illGoods;
return thief.name + "steals " + std::to_string(illGoods) + "magic!\n";
}*/