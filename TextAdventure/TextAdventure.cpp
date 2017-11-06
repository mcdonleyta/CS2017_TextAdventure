//
//  main.cpp
//  Text game
//
//  Created by Darion Cela on 9/28/17.
//  Copyright © 2017 Darion Cela. All rights reserved.
//
#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <list>
#include <algorithm>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
	/* MAP:
	House (inside)
	|
	|
	House (outside)                                          Sword Room
	|                                                      |
	|                                                      |
	NewRoom     ---     River      ---       Forest      ---     Power plant (out)     ---      Power plant (in)
	|                                                      |
	|                                                      |
	Hole                                              Flashlight Room
	*/
	string Location = "Hole";
	string userChoice = "option";
	string inventory = "empty";
	bool hasOrb = false;
	bool hasKey = false;
	bool hasSword = false;
	bool hasFlashlight = false;
	bool hasAxe = false;
	bool hasFoughtBoar = false;
	//vector<string> inventory;
	//inventory.push back("empty");
	//list<string> inventory;
	//inventory.push_back("empty");
	bool hasdrankwater = false;
	bool hasfoughtWolf = false;
	bool knockedTreeDown = false;
	int attack = 1;
	int health = 10;
	int wolfHP = 5;
	int wolfATK = 3;
	int boarHP = 7; // You can change these if you want it to be more difficult or easier 
	int boarATK = 2;// You can change these if you want it to be more difficult or easier
	std::cout << "Tips: \n1. If you want to quit, just input 'q' or 'Q'\n";
	std::cout << "2. It is usually a GOOD idea to look around in each room\n";
	std::cout << "3. If you input something and the program does nothing, then it probably is not a valid input\n";
	std::cout << "4. Everything you input will be a number. If you don't enter a number then the computer will do nothing with it\n";
	std::cout << "5. The only time your input will NOT be a number is if you want to view your stats/inventory. Just enter 'info' anytime\n";
	std::cout << "6. This game is a mix between a text and RPG game. Don't forget about either!\n\n";
	while (userChoice != "q" && userChoice != "Q") {
		if (userChoice == "info") {
			std::cout << "Inventory: ";
			if (hasOrb == true)
				std::cout << "Orb ";
			if (hasKey == true)
				std::cout << "Key ";
			if (hasSword == true)
				std::cout << "Sword ";
			if (hasFlashlight == true)
				std::cout << "Flashlight ";
			if (hasAxe == true)
				std::cout << "Axe ";
			std::cout << "\nAttack: " << attack;
			std::cout << "\nHP: " << health << "\n\n";
		}
		if (userChoice == "TEEMO") { //just in case you want to have a cheat code
			hasKey = true;
			hasOrb = true;
			hasSword = true;
			hasFlashlight = true;
			hasAxe = true;
			knockedTreeDown = true;
			health = 1000;
			attack = 1000;
			std::cin >> Location; // I added this so I could test the new location I added - Max
		}
		if (Location == "Hole")
		{
			std::cout << "You are in a dark, cold hole with a beam of light shining in the top\n";
			std::cout << "You can\n";
			std::cout << "1)Climb out of the hole\n";
			std::cout << "2)Look around\n";
			std::cin >> userChoice;
			if (userChoice == "1") {
				Location = "Forest";
				std::cout << "You climbed out of the dark hole\n";
			}
			if (userChoice == "2") {
				if (hasFlashlight == false) {
					std::cout << "You can't see much, so you feel your way around the hole. At one point, you feel an engraving on the wall, but it is too dark to tell what it says\n";
				}
				if (hasFlashlight == true) {
					std::cout << "You turn on your flashlight and wave it around the hole. A couple feet away from you, you see an engraving on the wall. It says '43628'\n";
				}
			}
		}
		else if (Location == "Forest")
		{
			std::cout << "You are in a forest\n";
			std::cout << "You can\n";
			std::cout << "1)Go back down into the hole\n";
			std::cout << "2)Go north\n";
			std::cout << "3)Go east\n";
			std::cout << "4)Go west\n";
			std::cout << "5)Look around\n";
			std::cin >> userChoice;
			if (userChoice == "1") {
				Location = "Hole";
			}
			if (userChoice == "2") {
				Location = "HouseOut";
			}
			if (userChoice == "3") {
				Location = "PowerplantOut";
			}
			if (userChoice == "4") {
				Location = "River";
			}
			if (userChoice == "5") {
				std::cout << "You are in a dense forest. There is lots of tall grass and bushes. Would you like to search for stuff? (1=yes 2=no)\n";
				std::cin >> userChoice;
				if (userChoice == "1") {
					if (hasOrb == false) {
						hasOrb = true;
						std::cout << "You looked around and found a strange glowing orb. You put it in your backpack\n";
					}
					else if (hasOrb == true) {
						std::cout << "You look around but don't find anything useful.\n";
					}
				}
				if (userChoice == "2") {
				}
			}
		}
		else if (Location == "HouseOut")
		{
			std::cout << "You are standing in the driveway of a small brick house\n";
			std::cout << "You can\n";
			std::cout << "1)Go back south\n";
			std::cout << "2)Go in the house\n";
			std::cout << "3)Look around\n";
			std::cin >> userChoice;
			if (userChoice == "1") {
				Location = "Forest";
			}
			else if (userChoice == "2") {
				Location = "HouseIn";
			}
			else if (userChoice == "3") {
				std::cout << "Around the driveway there are a lot of overgrown weeds and there is a forest south of you. You can tell that the roof of the house in front of you is severely damaged\n";
			}
		}
		else if (Location == "PowerplantOut")
		{
			std::cout << "You are at the edge of a power plant\n";
			std::cout << "You can\n";
			std::cout << "1)Go back west\n";
			std::cout << "2)Go east into the power plant\n";
			std::cout << "3)Look around\n";
			std::cin >> userChoice;
			if (userChoice == "1") {
				Location = "Forest";
			}
			if (userChoice == "2") {
				if (hasKey == true) {
					Location = "PowerplantIn";
					std::cout << "You try to open the door but it is locked. You then try to use the key that you found before and it opened the door\n";
				}
				else if (hasKey == false) {
					std::cout << "You try to open the door but it is locked and won't budge\n";
				}
			}
			if (userChoice == "3") {
				std::cout << "The power plant has a barbed wire fence surrounding it. The only opening you can see is a door in front of you\n";
			}
		}
		else if (Location == "River")
		{
			if (knockedTreeDown == false) {
				std::cout << "You are standing in front of a fast-moving river. There are a few leaning trees nearby\n";
				std::cout << "You can\n";
				std::cout << "1)Go back east\n";
				std::cout << "2)Try to make a tree fall down\n";
				std::cout << "3)Cross the river\n";
				std::cin >> userChoice;
				if (userChoice == "1") {
					Location = "Forest";
				}
				if (userChoice == "2") {
					if (hasAxe == false) {
						std::cout << "You try to push down a few leaning trees but they are still locked into the ground.\n";
					}
					else if (hasAxe == true) {
						std::cout << "You try to push down a few leaning trees, but they won't budge. You then decide to cut the side of one with your axe, and it falls down across the river\n";
						knockedTreeDown = true;
					}
				}
				else if (userChoice == "3") {
					std::cout << "You try to cross the river but the swift current of the river swept you off your feet and drowned you.";
					health = 0;
				}
			}
			else if (knockedTreeDown == true) {
				std::cout << "You are standing in front of a fast-moving river with a fallen tree over it.\n";
				std::cout << "You can\n";
				std::cout << "1)Go back east\n";
				std::cout << "2)Cross the river\n";
				std::cin >> userChoice;
				if (userChoice == "1") {
					Location = "Forest";
				}
				if (userChoice == "2") {
					std::cout << "You slowly walk across the tree trunk, watching the deadly river that is only a few feet away from you.\nMAKE ANOTHER ROOM HERE. Maybe a fight?\n";
				}
			}
		}
		else if (Location == "HouseIn")
		{
			std::cout << "You are in the house. There is fresh mud on the ground leading to the door at the end of the hallway\n";
			std::cout << "You can\n";
			std::cout << "1)Go back south (out of the house)\n";
			std::cout << "2)Rummage through the drawers\n";
			std::cout << "3)Go into the room at the end of the hallway\n";
			std::cout << "4)Look around\n";
			std::cin >> userChoice;
			if (userChoice == "1") {
				Location = "HouseOut";
			}
			else if (userChoice == "2") {
				if (hasKey == false) {
					hasKey = true;
					std::cout << "You found a key!\n";
				}
				else if (hasKey == true) {
					std::cout << "The only thing you see is the cabinets you already looked through\n";
				}
			}

			else if (userChoice == "3") // So basically what I did was make different locations for each stage of the wolf fight. There is "wolf", "wolfIntro", "wolfFight", and "wolfDeath".  They are a little out of order, but it works. - Max
			{
				Location = "wolf";
			} // By creating these seperate loactions, now they can't just enter something random and escape either dieing or fighting the wolf - Max

			if (userChoice == "4") {
				std::cout << "You are in a small brick house. The roof is collapsed, so there is no point in trying to go upstairs. There are a few cabinets beside you\n";
			}
		}

		// The idea is that I have broken your code down into different segments and assigned a location to each. - Max

		if (Location == "wolfFight") { // This is the third location - Max
			std::cout << "You take a few steps back, get a running start and then kick the door down. As the door falls, you see a flash of grey run around the corner. You go around the corner and are now looking at a huge wolf only a few feet away from you. Do you want to attack it or run away? (1=attack 2=run)\n"; // You had no if statement for running away so I added one
			std::cin >> userChoice;
			if (userChoice == "1" && hasSword == false) {
				Location = "wolfDeath";
			}
			else if (userChoice == "2")
			{
				cout << "You tried to run away but the wolf jumped on you and killed you before you could.\n";
				health = 0;
			}
			else if (userChoice == "1" && hasSword == true) {
				while (wolfHP > 1) {
					std::cout << "You stabbed the wolf with your sword.\n";
					wolfHP = wolfHP - attack;
					std::cout << "Wolf HP: " << wolfHP << "\n";
					std::cout << "The wolf attacks back\n";
					health = health - wolfATK;
					std::cout << "Your HP: " << health << "\n";
					std::cout << "Enter anything to continue the fight\n";
					std::cin >> userChoice;
				}
				std::cout << "You killed the wolf!\n";
				hasfoughtWolf = true;
			}

			else if (userChoice != "1" || userChoice != "2" || userChoice != "3" || userChoice != "4")
			{
				std::cout << "Choose one of the given choices.\n";
				Location = "wolfFight";
			}
			else if (hasfoughtWolf == true) {
				std::cout << "You go back into the room, but all you find is the dead wolf and some other victims\n";
			}

		}


		if (Location == "wolfIntro") {// This is the second location - Max
			if (hasfoughtWolf == false) {
				cout << "You are now at the end of the hallway and the door is slightly open. Open it slowly with your hand or kick it open? (1=hand 2=kick)\n";
				cin >> userChoice;
				if (userChoice == "1") {
					std::cout << "As you touch the door, the growling noise stops. You slowly push open the door, frightned of what you will find on the other side. ";
					std::cout << "As you take a step into the room, a wolf comes sprinting around the corner, snarling with its blood-stained teeth. It leaped onto your and ripped your head off.\n";
					health = 0;
				}
				else if (userChoice == "2")
				{
					Location = "wolfFight";
				}
				else if (userChoice != "1" || userChoice != "2" || userChoice != "3" || userChoice != "4")
				{
					std::cout << "Choose one of the given choices.\n";
					Location = "wolfIntro";
				}
				else if (hasfoughtWolf == true) {
					std::cout << "You go back into the room, but all you find is the dead wolf and some other victims\n";
				}
			}
		}

		if (Location == "wolfDeath") {// This is the fourth location, but you can only die here - Max
			if (hasSword == false) {
				std::cout << "You try to punch the wolf with your fist but it bites your hand and then jumps on you and throws you down. You manage to throw the wolf off of you and get back up. Your fist is now severly bleeding\n";
				std::cout << "The wolf is looking angrier than ever. Do you want to attack it or run away? (1=attack 2=run)\n";
				std::cin >> userChoice;
				if (userChoice == "1") {
					std::cout << "You took another swing at the wolf with your left hand, but this time the wolf dodges it, knocks you out, and kills you. You died, but at least you died trying.\n";
					health = 0;
				}
				else if (userChoice == "2") {
					std::cout << "You try to run away but the wolf jumps on your back, knocking you out, and then kills you. You died, but at least you died trying\n";
					health = 0;
				}
				else if (userChoice != "1" || userChoice != "2" || userChoice != "3" || userChoice != "4")
				{
					std::cout << "Choose one of the given choices.\n";
					Location = "wolfDeath";
				}
			}
		}

		if (Location == "wolf") {// This is the first location - Max
			if (hasfoughtWolf == false) {
				std::cout << "You slowly make your way to the door at the end of the hallway. As you get closer, you start to smell rotting flesh and hear a low growling noise. Would you like to proceed? (1=yes 2=no)\n";
				std::cin >> userChoice;
				if (userChoice == "1") {
					Location = "wolfIntro";
				}
				else if (userChoice == "2") {
					std::cout << "You try to run away, but a large, heavy creature jumps on your back, knocks you out, and kills you before you get to even look behind you.\n";
					health = 0;
				}
				else if (userChoice != "1" || userChoice != "2" || userChoice != "3" || userChoice != "4")
				{
					std::cout << "Choose one of the given choices.\n";
					Location = "wolf";
				}
				else if (hasfoughtWolf == true) {
					std::cout << "You go back into the room, but all you find is the dead wolf and some other victims\n";
				}
			}
		}

		//Now they can't randomly type something to escape, and it works for every stage of the fight - Max

		if (Location == "PowerplantIn") {
			std::cout << "You are inside the power plant\n";
			std::cout << "You can\n";
			std::cout << "1)Go back west outside the power plant\n";
			std::cout << "2)Go into the room north of you\n";
			std::cout << "3)Go into the room south of you\n";
			std::cout << "4)Look around\n";
			std::cin >> userChoice;
			if (userChoice == "1") {
				Location = "PowerplantOut";
			}
			if (userChoice == "2") {
				std::cout << "You walk up to the room in front of you and see that it is heavily protected. You try to open the thick metal door, but it is locked. There is a keypad next to the door. Enter a code into the keypad. \n> ";
				std::cin >> userChoice;
				if (userChoice == "43628") {
					Location = "SwordRoom";
					std::cout << "\n";
				}
				else
					std::cout << "All the keypad did was make a long beep\n";
			}
			if (userChoice == "3") {
				Location = "FlashlightRoom";
			}
			if (userChoice == "4") {
				std::cout << "There are two rooms in front of you, but you can't tell what is in them. You can smell smoke coming from somewhere, but you don't know from where. The power plant looks abandoned as if nobody has been there in a while, but the blood stains marks on the floor look new\n";
				if (hasdrankwater == false) {
					std::cout << "There is a strange blue liquid dripping from a pipe above you.\n";
					std::cout << "You are thirsty. Do you want to drink the liquid? (1=yes 2=no)\n";
					std::cin >> userChoice;
					if (userChoice == "1") {
						std::cout << "You feel... energized (Your attack has been increased and your hitpoints have been decreased)\n";
						attack = attack + 2;
						health = health - 4;
						hasdrankwater = true;
					}
					else if (userChoice == "2") {
						std::cout << "You are extremley thirsty but decide not to risk it\n";
					}
				}
			}
		}
		else if (Location == "SwordRoom") {
			std::cout << "You are in a room that looks to be a weapons storage. There are guns, axes, and other things on display cases but most of them are behind thick glass.\n";
			std::cout << "You can \n1)Go back into the main room of the power plant \n3)Look around\n";
			std::cin >> userChoice;
			if (userChoice == "1") {
				Location = "PowerplantIn";
			}
			else if (userChoice == "3") {
				if (hasSword == false) {
					std::cout << "You look at each of the weapon displays. There are a lot that have been already broken and stolen, but in one, all you can see is steam. You reach in the display and feel a cold metal. You then pull it out and find that it is a light sword about 3 feet long\n";
					std::cout << "You found a sword!\n";
					hasSword = true;
					attack += 3;
				}
				else if (hasSword == true) {
					std::cout << "You look at each of the weapon displays. There are a lot that have been already broken and stolen, but in the one you got your sword out of, all you can see is steam. You reach in the display again, but nothing is there.\n";
				}
			}
		}
		else if (Location == "FlashlightRoom") {
			if (hasFlashlight == false) {
				std::cout << "You are now in a dark room. Close to the doorway, you can see a few tools\n";
				std::cout << "You can \n1)Go back north into the main room of the power plant \n3)Look around\n";
				std::cin >> userChoice;
				if (userChoice == "1") {
					Location = "PowerplantIn";
				}
				else if (userChoice == "3") {
					std::cout << "You can't see much, so you feel your way around the room. You find a flashlight on a shelf\n";
					std::cout << "You found a flashlight!\n";
					hasFlashlight = true;
				}
			}
			else if (hasFlashlight == true && hasAxe == false) {
				std::cout << "You are now in a dark room. Close to the doorway, you can see a few tools\n";
				std::cout << "You can \n1)Go back north into the main room of the power plant \n3)Look around\n";
				std::cin >> userChoice;
				if (userChoice == "1") {
					Location = "PowerplantIn";
				}
				else if (userChoice == "3") {
					std::cout << "You turn on the flashlight and wave it around the room. You find a selection of hammers, axes, drills, and screwdrivers. You decide to pick up the axe, since it might be pretty useful\n";
					std::cout << "You found an axe!\n";
					hasAxe = true;
				}
			}
			if (hasAxe == true) {
				std::cout << "You can \n1)Go back north into the main room of the power plant \n3)Look around\n";
				std::cin >> userChoice;
				if (userChoice == "1") {
					Location = "PowerplantIn";
				}
				else if (userChoice == "3") {
					std::cout << "You turn on your flashlight again and wave it around the room, but nothing has changed since you last were here\n";
				}
			} //No need for a    if (hasFlashlight == false && hasAxe == true)  because you can't get the axe without the flashlight
		}
		if (Location == "Field") {
			std::cout << "You stand in a large field.\n";
			std::cout << "You can:\n";
			std::cout << "1) Go back\n";
			std::cout << "2) Look around\n";
			std::cout << "3) Go into the field\n";
			std::cin >> userChoice;

			if (userChoice == "1")
			{
				Location = "place"; // You can change this to wherever you want them to go. - Max
			}

			else if (userChoice == "2")
			{
				std::cout << "You stand at the beginning of a large field. It is filled with tall grass. You think to youself that there might be something useful in it. You hear the tall grass shift next to you, you realize you aren't alone.";
			}

			else if (userChoice == "3"&& hasFoughtBoar == false)
			{
				std::cout << "When you get a couple steps in, a wild boar approaches you to fight.\n";
				while (boarHP > 0) {
					std::cout << "You stabbed the boar with your sword.\n";
					boarHP = boarHP - attack;
					std::cout << "Boar HP: " << boarHP << "\n";
					std::cout << "The boar attacks back\n";
					health = health - boarATK;
					std::cout << "Your HP: " << health << "\n";
					std::cout << "Enter anything to continue the fight\n";
					std::cin >> userChoice;
				}
				std::cout << "You killed the boar!\n";
				std::cout << "You picked up a \n"; // You can add whatever you want them to obtain when they kill the boar - Max
				hasFoughtBoar = true;
			}

			if (userChoice == "3" && hasFoughtBoar == true)
			{
				std::cout << "The dead body of the boar lays here.\n";
			}
		}
		if (health == 0 || health < 0) {
			userChoice = "q";
		}
	}


	std::cout << "\n\nGAME OVER\n";
	std::cout << "Here are your final stats:\n";
	std::cout << "Inventory: ";
	if (hasOrb == true)
		std::cout << "Orb ";
	if (hasKey == true)
		std::cout << "Key ";
	if (hasSword == true)
		std::cout << "Sword ";
	if (hasFlashlight == true)
		std::cout << "Flashlight ";
	if (hasAxe == true)
		std::cout << "Axe ";
	std::cout << "\nAttack: " << attack;
	std::cout << "\nHealth: " << health << "\n\n";
	cin >> userChoice;
	// When you lost, the program would just end, so I added this std::cin so the user can read their stats then type in something to end it - Max
	return 0;

}