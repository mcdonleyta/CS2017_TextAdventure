// TextAdventure.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"  //Remove if not using Visual Studio
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string location = "start";
	string choice = "";

	while (choice != "q" && choice != "Q")
	{
		if (location == "start")
		{
			cout << "You find yourself at the end of a drive way.\nThere is a road to the north and west.\n";
			cout << ">";
			cin >> choice;

			if (choice == "look")
			{
				cout << "There is a mailbox here.\n";
			}
			else if (choice == "mail")
			{
				cout << "You have found a package with a key inside.\n";
				cout << "There is also note in strange handwriting that says \"Get Out!\"\n";
			}
			else if (choice == "n" || choice == "north")
			{
				location = "roadN";
			}
			else if (choice == "w" || choice == "west")
			{
				location = "roadW";
			}
			else if (choice != "q" && choice != "Q")
			{
				cout << "I don't understand.\n";
			}
		}
		else if (location == "roadN")
		{
			cout << "You find yourself on a grassy road that looks less traveled.\n";
			cout << ">";
			cin >> choice;

			if (choice == "s" || choice == "south")
			{
				location = "start";
			}
			else if (choice != "q" && choice != "Q")
			{
				cout << "I don't understand.\n";
			}

		}
		else if (location == "roadW")
		{
			cout << "You find yourself on a paved road with a few homes.\n";
			cout << ">";
			cin >> choice;

			if (choice == "e" || choice == "east")
			{
				location = "start";
			}
			else if (choice != "q" || choice != "Q")
			{
				cout << "I don't understand.\n";
			}
		}
	}
	return 0;
}

