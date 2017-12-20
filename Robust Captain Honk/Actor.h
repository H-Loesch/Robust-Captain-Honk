#ifndef ACTOR_H
#define ACTOR_H

#include <string>

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

	std::string outputStatement;
public:

	//default constructor
	Actor();

	//specified constructor, with name
	Actor(int healthStart, int magicStart, std::string Name);

	//specified constructor, without name
	Actor(int healthStart, int magicStart);

	//decreases enemy health
	void attack(Actor* enemy);
	//increases health, decreases magic
	void heal();
	//increases magic
	void recharge();
	//increases magic, decreases enemy magic
	void steal(Actor* enemy);

	int get_health();
	int get_magic();
	std::string getName();
	std::string getOut();

	void set_health(int newHealth);
	//changes health by provided amount
	void mod_health(int change);
	void set_magic(int newMagic);
	//changes magic by provided amount
	void mod_magic(int change);
};
#endif
//TODO: will the various min/max values need getters?