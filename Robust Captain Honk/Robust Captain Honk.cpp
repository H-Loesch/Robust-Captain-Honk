#include "stdafx.h"
#include <iostream>
#include <time.h>
#include "overarch.h"
#include "actor.h"
#include "actor_functions.h"
#include "randomization.h"

//TODO: Figure out how to receive user input
//TODO: AI if/else
//TODO: End conditions for Loop
//TODO: print actor function

int main()
{
	//makes a new random sequence of numbers for rand() to use.
	srand(time(NULL));

	//initializing actors, and names.
	Actor player{ 30, 15, "Player" };
	Actor enemy{ 45, 12, "placeholder" };
	/*
	std::string action{ random_action() };
	std::string enemyName{ enemy_name() };
	enemy.name = enemyName;
	std::string title{ action + " " + enemyName };

	//declaring variables.
	std::string playerOut;
	std::string enemyOut;
	int looper{ 1 };
	char input;
	bool inputFailure{ false };
	bool winner;
	std::string menuString{ "Attack, Heal, or Charge?\n" };

	//primary loop. Game is only able to run once, because that's how arcade games work. Put in another quarter, nerd.
	while (looper == 1) {
		//clear screen. This DOES make this only work in windows, but uh... this isn't really designed to spread around much.
		system("cls");
		std::cout << title << std::endl << std::endl;

		//remember that playerOut and enemyOut must both end in "\n"
		//Print messages of what happened last turn.
		std::cout << playerOut << enemyOut << std::endl;
		//statuses
		std::cout << "Health: " + std::to_string(player.health) + " | Magic: " + std::to_string(player.magic) + " | Enemy Health: " + std::to_string(enemy.health) + "\n";
		//Action list, or else game over message.
		std::cout << menuString;
		std::cin >> input;
		std::cin.ignore(INT_MAX, '\n');


		//Player input tree
		/*
		Yeah. Initially, all these were done with functions, but then I remembered that I couldn't actually do that without utilizing global variables
		So... now it's just here. The functions were mostly just to clean things up, anyway. This already has like 5 other scaling issues anyway
		What's one more?
		*//*
		if (input == 'A' || input == 'a') {
			int damage{ get_random(2,8) };
			enemy.health -= damage;
			playerOut = "You attack for " + std::to_string(damage) + " damage!\n";
			// playerOut = attack(player, enemy, 2, 8);
		}
		else if (input == 'H' || input == 'h') {
			int healing{ get_random(6,14) };
			int fee{ get_random(1,4) };
			player.health += healing;
			player.magic -= fee;
			playerOut = "You heal for " + std::to_string(healing) + " health, using " + std::to_string(fee) + " magic!\n";
			// playerOut = heal(player, 6, 14);
		}
		else if (input == 'C' || input == 'c') {
			int gains{ get_random(4,11) };
			player.magic += gains;
			playerOut = "You recharge for " + std::to_string(gains) + " magic!\n";
			// playerOut = recharge(player);
		}
		else {
			inputFailure = true;
			playerOut = "What?\n";
		}

		//Enemy AI tree
		if (!inputFailure) {
			if (enemy.health > 10) {
				int damage{ get_random(3,9) };
				player.health -= damage;
				enemyOut = enemy.name + " attacks for " + std::to_string(damage) + " damage!\n";
				// enemyOut = attack(enemy, player, 3, 9);
			}
			else if (enemy.magic > 3) {
				int healing{ get_random(3,5) };
				enemy.health += healing;
				enemy.magic -= get_random(1, 4);
				enemyOut = enemy.name + " heals for " + std::to_string(healing) + " health!\n";
				//enemyOut = heal(enemy, 4, 4);
			}
			else {
				//enemy steals magic. Sneaky.
				int illGoods{ get_random(3,5) };
				player.magic -= illGoods;
				enemy.magic += illGoods;
				enemyOut = enemy.name + " steals " + std::to_string(illGoods) + " magic!\n";
				//enemyOut = steal(enemy, player);
			}
		}
		else {
			enemyOut = "\n";
			inputFailure = false;
		}

		//Game over checks.
		if (player.health < 1) {
			menuString = "You are dead now! Game over!\n";
			looper = false;
			winner = false;
		}
		else if (player.magic < 1) {
			menuString = "Your magic is all gone, and so you die!\n";
			looper = false;
			winner = false;
		}
		else if (enemy.health < 1) {
			menuString = "Wow, you did it! The evil is defeated!\n";
			looper = false;
			winner = true;
		}
	}

	std::cout << title << std::endl << std::endl;

	//All the menu stuff, cuz I want that to show up in the game over screen. 
	system("cls");
	std::cout << title << std::endl << std::endl;
	std::cout << playerOut << enemyOut << std::endl;
	std::cout << "Health: " + std::to_string(player.health) + " | Magic: " + std::to_string(player.magic) + " | Enemy Health: " + std::to_string(enemy.health) + "\n";
	std::cout << menuString;

	if (winner) {
		std::cout << "Here is your prize: " << random_prize();
	}
	else {
		std::cout << "GAME OVER! \n";
	} */

	std::cout << "\nPlease enter your name to continue!\n";
	std::cin >> input;
	return 0;
}

