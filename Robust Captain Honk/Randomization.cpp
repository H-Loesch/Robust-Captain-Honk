#include "stdafx.h"
#include "overarch.h"

std::string enemy_name()
{
	//since name/type of monster has LITERALLY no effect on anything else, don't need to link this with anything
	int dingus;
	dingus = get_random(1, 6);
	std::string part1;
	//god I hate if/else's. 
	//I know there's a better way to do this, with arrays or something, but iunno how to do those yet. 
	//it's with case statements u dummy
	if (dingus == 1) {
		part1 = "Robust ";
	} if (dingus == 2) {
		part1 = "Space ";
	} if (dingus == 3) {
		part1 = "Lord ";
	} if (dingus == 4) {
		part1 = "Robust ";
	} if (dingus == 5) {
		part1 = "Dangerous ";
	} if (dingus == 6) {
		part1 = "Rowdy ";
	}

	int bingus{ get_random(1,9) };
	std::string part2;
	if (bingus == 1) {
		part2 = "Goat";
	} if (bingus == 2) {
		part2 = "Mercenary";
	} if (bingus == 3) {
		part2 = "Tree Man";
	} if (bingus == 4) {
		part2 = "Bear";
	} if (bingus == 5) {
		part2 = "Ghost";
	} if (bingus == 6) {
		part2 = "Radiation";
	} if (bingus == 7) {
		part2 = "Dingus";
	} if (bingus == 8) {
		part1 = "";
		part2 = "Lord Singuloth";
	} if (bingus == 9) {
		part1 = "";
		part2 = "Cuban Pete";
	}
	std::string name;
	name = part1 + part2;
	return name;
}

std::string random_action()
{
	int trash = get_random(1, 5);
	std::string action;
	if (trash == 1) {
		action = "Robust";
	} if (trash == 2) {
		action = "Explode";
	} if (trash == 3) {
		action = "Defeat";
	} if (trash == 4) {
		action = "Combat";
	} if (trash == 5) {
		action = "Debate";
	}
	return action;
}

std::string random_prize()
{
	int prize = get_random(1, 9);
	std::string item;
	if (prize == 1) {
		item = "Cool Rock";
	} if (prize == 2) {
		item = "Gumball";
	} if (prize == 3) {
		item = "Teddy Bear";
	} if (prize == 4) {
		item = "Physics Textbook";
	} if (prize == 5) {
		item = "Fountain Pen (no ink)";
	} if (prize == 6) {
		item = "Spool of White Thread";
	} if (prize == 7) {
		item = "Headphones (broken)";
	} if (prize == 8) {
		item = "Faith";
	} if (prize == 9) {
		item = "3 Cubic Inches of Meat!";
	}
	return item;
}