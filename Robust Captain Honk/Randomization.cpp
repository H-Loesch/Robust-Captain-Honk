#include "stdafx.h"
#include "Randomization.h"
#include <string>
#include <vector>

int get_random(int min, int max)
{
	int range = max - min + 1;
	return (rand() % range) + min;
}

//returns a randomized enemy name
std::string enemy_name()
{
	//since name/type of monster has LITERALLY no effect on anything else, don't need to link this with anything
	int dingus{ get_random(0,6) };
	std::vector<std::string> name1Vector{"Robust ", "Space ", "Lord ", "Robust ", "Dangerous ", "Rowdy ", "Captain "};
	std::string part1;
	part1 = name1Vector.at(dingus);

	int bingus{ get_random(0,9) };
	std::vector<std::string> name2Vector{ "Goat", "Mercenary", "Tree Man", "Bear", "Space Bear", "Ghost", "Radiation", "Dingus",
		"Lord Singuloth", "Cuban Pete" }; //chick chicky boom
	std::string part2;
	part2 = name2Vector.at(bingus);
	if (bingus >= 9) {
		part1 = "";
	}
	std::string name{ part1 + " " + part2 };
	if (bingus >= 9) {
		name = part2; 
	}
	return name;
}

std::string random_action()
{
	/*"Robust robust noun" is a possibility. That's intentional and fine, as robust is used as a verb and adjective here
	"Robust": To beat or batter, esp. with a blunt instrument not designed as a weapon*/
	int trash = get_random(0, 5);
	std::vector<std::string> actionVector{ "Robust", "Explode", "Defeat", "Combat", "Debate", "Vigorously Debate" };
	return actionVector.at(trash);
}

std::string random_prize()
{
	int prize = get_random(0, 10);
	std::vector<std::string> itemVector{ "Cool Rock", "Gumball", "Teddy Bear", "Space Teddy Bear", "Teddy Space Bear", "Physics Textbook",
		"Fountain Pen (no ink)", "Spool of White Thread", "Headphones (broken)", "Faith", "3 Cubic Inches of Meat!" };
	//the concept of receiving 3 cubic inches of meat as a prize, to this day, both haunts and amuses me.
	return itemVector.at(prize);
}