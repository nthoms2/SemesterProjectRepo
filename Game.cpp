#include "Game.h"
#include <iostream>

Game::Game()
{
	NPCnum = 0;
}

Game::~Game()
{

}

void Game::adventure()
{

	bool playing = true;
	world.displayArray();
	while (playing)
	{
		switch (move(NPCnum))
		{
		case normal:
			system("CLS");
			world.displayArray();
			break;
		case text:
			system("CLS");
			talk();
			world.displayArray();
			break;
		case menu:
			system("CLS");
			menuDisplay();
			system("CLS");
			world.displayArray();
			break;
		}
		wildCheck();
	}

}

decision Game::move(int& NPCnum_)
{
	bool valid = true;
	do
	{
		char input;
		cin >> input;

		switch (world.changePos(input, player, NPCnum_))
		{
		case normal: valid = true;
			return normal;
			break;
		case redo: valid = false;
			break;
		case text: valid = true;
			return text;
			break;
		case menu: valid - true;
			return menu;
			break;
		}

	} while (valid == false);
}

void Game::talk()
{
	switch (NPCnum)
	{
	case 1: cout << "Hello I am your mom." << endl;
		break;
	case 2: cout << "I smell pennies!!!" << endl;
		break;
	case 3: cout << "Hello there young child, take this monster and go fight some stuff." << endl;
		break;
	case 4: cout << "Get out of here and go smell some toes you scamp." << endl;
		break;
	case 5: cout << "Why don't you and your dopeymon take a rest, deer." << endl;
	}
}

void Game::menuDisplay()
{
	bool valid = true;
	while (valid)
	{
		system("CLS");
		char input;
		cout << "1: dopeymon" << endl;
		cout << "2: map key" << endl;
		cout << "\npress a number or anything else to exit" << endl;

		cin >> input;

		switch (input)
		{
		case '1':
			menuDopeymon();
			break;
		case '2':
			menuKey();
			break;
		default: valid = false;
			break;
		}
	}
}

void Game::menuKey()
{
	system("CLS");
	cout << "map key:" << endl;
	cout << "X = out of bounds" << endl;
	cout << "O = people" << endl;
	cout << "|, - =  furniture " << endl;
	cout << "# = buildings" << endl;
	cout << "~ = water" << endl;
	cout << "M = tall grass" << endl;
	cout << ": = sand " << endl;
	cout << "\npress anything to exit" << endl;

	char input;
	cin >> input;
}

void Game::menuDopeymon()
{
	bool valid = true;
	while (valid)
	{
		system("CLS");
		cout << "your dopeymon:" << endl;
		for (int i = 0; i < 6; i++)
		{
			if (player.getMons(i).getName() == "debug")
				cout << i + 1 << ": empty" << endl;
			else
				cout << i + 1 << ": " << player.getMons(i).getName() << endl;
		}
		cout << "\n" << "press a number or anything else to exit" << endl;

		char input;
		cin >> input;

		int temp = 7;
		switch (input)
		{
		case '1':
			temp = 0;
			displayStats(temp);
			break;
		case '2':
			temp = 1;
			displayStats(temp);
			break;
		case '3':
			temp = 2;
			displayStats(temp);
			break;
		case '4':
			temp = 3;
			displayStats(temp);
			break;
		case '5':
			temp = 4;
			displayStats(temp);
			break;
		case '6':
			temp = 5;
			displayStats(temp);
			break;
		default: valid = false;
			break;
		}
	}
	
}

void Game::displayStats(int i)
{
	if (player.getMons(i).getName() == "debug")
	{
		system("CLS");
		cout << "This slot is empty." << endl;
		char input;
		cout << "\n press anything to exit" << endl;
		cin >> input;
	}
	else
	{
		system("CLS");
		cout << player.getMons(i).getName() << endl;
		cout << "level: " << player.getMons(i).getLevel() << endl;
		cout << "type: "; 
		switch (player.getMons(i).getType())
		{
		case neutral: cout << "neutral" << endl;
			break;
		case fire: cout << "fire" << endl;
			break;
		case water: cout << "water" << endl;
			break;
		case earth: cout << "earth" << endl;
			break;
		case lightning: cout << "ligthning" << endl;
			break;
		case grass: cout << "grass" << endl;
			break;
		case melon: cout << "melon" << endl;
			break;
		case poop: cout << "poop" << endl;
			break;
		}
		cout << "health: " << player.getMons(i).getCHealth() << "/" << player.getMons(i).getMaxHealth() << endl;
		cout << "strength: " << player.getMons(i).getMaxStrength() << endl;
		cout << "defense: " << player.getMons(i).getMaxDefense() << endl;
		cout << "speed: " << player.getMons(i).getMaxSpeed() << endl;
		cout << "-------------------------------" << endl;
		cout << "moves:" << endl;
		for (int j = 1; j <= 4; j++)
		{
			switch (j)
			{
			case 1: 
				moveDisplay(player.getMons(i).getMoves().attack1);
				break;
			case 2:
				moveDisplay(player.getMons(i).getMoves().attack2);
				break;
			case 3:
				moveDisplay(player.getMons(i).getMoves().attack3);
				break;
			case 4:
				moveDisplay(player.getMons(i).getMoves().attack4);
				break;
			}
		}

		char input;
		cout << "\npress anything to exit" << endl;
		cin >> input;

	}
}

//helps with above function
void Game::moveDisplay(Attack attack)
{
	if (attack.getAtkName() == "debug")
		cout << "none" << endl;

	else
	{
		cout << attack.getAtkName() << ": power = " << attack.getAtkPwr() << ", type = ";
		switch (attack.getAtkType())
		{
		case neutral: cout << "neutral" << endl;
			break;
		case fire: cout << "fire" << endl;
			break;
		case water: cout << "water" << endl;
			break;
		case earth: cout << "earth" << endl;
			break;
		case lightning: cout << "ligthning" << endl;
			break;
		case grass: cout << "grass" << endl;
			break;
		case melon: cout << "melon" << endl;
			break;
		case poop: cout << "poop" << endl;
			break;
		}
	}
	
}

void Game::wildCheck()
{
	if (world.getSymbol() == 'M' || world.getSymbol() == ':')
	{
		srand(unsigned int(time(NULL)));
		int num = (rand() % 5);
		if (num == 4)
		{
			switch (world.getSymbol())
			{
			case 'M': grassEncounters();
				break;
			case ':': sandEncounters();
				break;
			}
		}
	}
}

void Game::grassEncounters()
{
	Battle battle;
	vector<Dopeymon> temp;
	int size = 0;
	 
	switch (world.getArea())
	{
	case 4:
		Galapagoat mon0; temp.push_back(mon0); size++;
		Melork mon1; temp.push_back(mon1); size++;
		break;
	}

	int num = (rand() % size);
	for (int i = 0; i < size; i++)
	{
		if (i == num)
		{ 
			battle.battlePhase(player, temp[i]);
			world.displayArray();
		}

	}
}

void Game::sandEncounters()
{
	Battle battle;
	vector<Dopeymon> temp;
	int size = 0;

	switch (world.getArea())
	{
	case 4:
		Dunisaur mon0; temp.push_back(mon0); size++;
		Guppy mon1; temp.push_back(mon1); size++;
		break;
	}

	int num = (rand() % size);
	for (int i = 0; i < size; i++)
	{
		if (i == num)
		{
			battle.battlePhase(player, temp[i]);
			world.displayArray();
		}
			
	}
}

