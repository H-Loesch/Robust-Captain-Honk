#pragma once
#include <string>

class Actor{
private: 
	int health;
	int magic;
	std::string name = "player";
	
	//Describes the min and max outcomes for various actions
	//these are unique to the actor, so they have to be stored in object
	int damageLow;
	int damageHigh;
	int healLow;
	int healHigh;
	int rechargeLow;
	int rechargeHigh;
	int stealLow;
	int stealHigh;

public:

	Actor();

	Actor(int healthStart, int magicStart, std::string Name);

	//decreases enemy health
	void attack(Actor* enemy);

	//increases health, decreases magic
	void heal();

	//increases magic
	void recharge();

	void steal();

	//writes a statement to the user
	void UIOutput();

	int getHealth();
	int getMagic();
	int getName();
}

//TODO: will the various min/max values need getters?