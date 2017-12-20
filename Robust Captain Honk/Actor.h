#ifndef ACTOR_H
#define ACTOR_H

#include <string>
#include <sstream>

class Actor{
private: 
	int health;
	int magic;
	std::string name;
	
	//Describes the min and max outcomes for various actions
	//these are unique to the actor, so they have to be stored in object
	int damageLow;
	int damageHigh;
	int healLow;
	int healHigh;
	int healCostLow;
	int healCostHigh;
	int rechargeLow;
	int rechargeHigh;
	int stealLow;
	int stealHigh;

	std::stringstream outputStatement;
public:

	//default constructor
	Actor();

	//specified constructor, with name
	Actor(int healthStart, int magicStart, std::string Name);

	//specified constructor, without name
	Actor(int healthStart, int magicStart);

	//sets default min/max values for player
	void Actor::become_player();
	//sets default min/max values for enemy
	void Actor::become_enemy();

	//decreases enemy health
	void attack(Actor& enemy);
	//increases health, decreases magic
	void heal();
	//increases magic
	void recharge();
	//increases magic, decreases enemy magic
	void steal(Actor& enemy);

	int get_health();
	int get_magic();
	std::string get_name();
	std::string get_out();

	void set_health(int newHealth);
	//changes health by provided amount
	void mod_health(int change);
	void set_magic(int newMagic);
	//changes magic by provided amount
	void mod_magic(int change);
	void set_out(std::string newString);
};
#endif
//TODO: will the various min/max values need getters?