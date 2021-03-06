#include "stdafx.h"
#include <iostream>
#include <time.h>
#include "overarch.h"
#include "actor.h"
#include "actor_functions.h"
#include "randomization.h"

//TODO: make sure the output functions work.
//TODO: Change player's name to "you"
//TODO: add high score list (.txt), include prize list

int main()
{
	//initializes rand() using the time.
	srand(time(NULL));

	std::cout << "What's your name? " << std::endl;
	std::string playerName;
	std::cin >> playerName;
	std::cin.ignore(256, '\n');

	//initializing actors, and names.
	std::string enemyName = enemy_name();
	Actor player{ 30, 15, playerName };
	Actor enemy{ 45, 12, enemyName };
	player.become_player();
	enemy.become_enemy();

	std::string action{ random_action() };
	std::string title{ action + " " + enemyName };

	//declaring variables.
	int looper{ 1 };
	char input;
	bool inputFailure{ false };
	bool winner;
	std::string menuString{ "Attack, Heal, or Charge?\n" };

	//primary loop. Game is only able to run once, because that's how arcade games work. Put in another quarter, nerd.
	while (looper == 1) {
		//clear screen. Only works in windows, but that's fine considering aim of this project
		system("cls");
		std::cout << title << std::endl << std::endl;

		//Print messages of what happened last turn.
		std::cout << player.get_out() << enemy.get_out() << std::endl;
		//statuses
		std::cout << "Health: " << player.get_health() << " | Magic: " << player.get_magic() << " | Enemy Health: " 
			<< enemy.get_health() << "\n";
		//Action list, or else game over message.
		std::cout << menuString;

		//receive input 
		std::cin >> input;
		std::cin.ignore(INT_MAX, '\n'); //erase extraneous input

		//player input tree
		if (input == 'A' || input == 'a') {
			player.attack(enemy);
			// playerOut = attack(player, enemy, 2, 8);
		}
		else if (input == 'H' || input == 'h') {
			//heal between 3 and 9, using 1 to 3 magic
			player.heal();
			// playerOut = heal(player, 6, 14);
		}
		else if (input == 'C' || input == 'c') {
			//recharge between 4 and 7
			player.recharge();
			// playerOut = recharge(player);
		}
		else if (input == 'L') {
			enemy.mod_health(-40);
		}
		else {
			inputFailure = true;
			player.set_out("Input not understood. \n");
		}

		//Enemy AI tree
		if (!inputFailure) {
			if (enemy.get_health() > 10) {
				//attacks for 3-6 damage
				enemy.attack(player);
			}
			else if (enemy.get_magic() > 3) {
				//heals for 4, using 4
				enemy.heal();
			}
			else {
				//steal 1-3 magic
				enemy.steal(player);
			}
		}
		else {
			enemy.set_out("\n");
			inputFailure = false;
		}

		//Game over checks.
		if (player.get_health() < 1) {
			menuString = "You are dead now! Game over!\n"; //not sure why these end in \n instead of just using std::endl above.
			looper = false;
			winner = false;
		}
		else if (player.get_magic() < 1) {
			menuString = "Your magic has been drained, leaving your body a lifeless husk! \n";
			looper = false;
			winner = false;
		}
		else if (enemy.get_health() < 1) {
			menuString = "Wow, you did it! The evil is defeated!\n";
			looper = false;
			winner = true;
		}
	}

	std::cout << title << std::endl << std::endl;

	//All the menu stuff, cuz I want that to show up in the game over screen. 
	system("cls");
	std::cout << title << std::endl << std::endl;
	std::cout << player.get_out() << enemy.get_out() << std::endl;
	std::cout << "Health: " << player.get_health() << " | Magic: " << player.get_magic() << " | Enemy Health: "
		<< enemy.get_health() << std::endl;
	std::cout << menuString;

	if (winner) {
		std::cout << "Here is your prize: " << random_prize() << std::endl;
	}
	else {
		std::cout << "GAME OVER!" << std::endl;
	} 
	system("pause");

	std::cout << "\nPlease enter your name to continue!\n"; //what is this for?
	//std::cin >> input;
	return 0;
}

