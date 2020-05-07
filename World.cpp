#include <iostream>
#include <vector>
#include "World.h"

using namespace std;

World::World()
{
	playerArea = 0;

	playerCords.xPos = 6;
	playerCords.yPos = 4;

	nextCords.xPos = 6;
	nextCords.yPos = 4;

	setHome(); 
	setHouse1();
	setTown1();
	setLab();
	setTrainingIsle();
	setAreas();

	int eNumLab = 0;
	int eNumMom = 0;
}

World::~World()
{

}

void World::setHome()
{
	/*
	for (int i = 0; i < 8; i++)
	{
		homeColms.push_back(worldChunk());
	}
	for (int i = 0; i < 7; i++);
	{
		homeRows.push_back(homeColms);
	}
	*/
	vector<vector<worldChunk> > vec0(7, vector<worldChunk>(8));
	homeRows = vec0;

	for (int rows = 0; rows < 7; rows++)
	{
		for (int colms = 0; colms < 8; colms++)
		{
			homeRows[rows][colms].symbol = 'X';
			homeRows[rows][colms].playerSymbol = 'o';
			homeRows[rows][colms].player = false;
		}
	}

	for (int rows = 1; rows < 6; rows++)
	{
		for (int colms = 1; colms < 7; colms++)
		{
			homeRows[rows][colms].symbol = ' ';
		}
	}
	homeRows[1][6].symbol = '-'; homeRows[1][5].symbol = '-'; homeRows[2][6].symbol = '|'; homeRows[2][5].symbol = '|'; homeRows[3][6].symbol = '|'; homeRows[3][5].symbol = '|';
	homeRows[2][2].symbol = '-'; homeRows[2][3].symbol = '-'; homeRows[3][2].symbol = '-'; homeRows[3][3].symbol = '-'; homeRows[3][1].symbol = 'O'; homeRows[5][2].symbol = 'V'; homeRows[5][3].symbol = 'V';
	homeRows[4][6].player = true;
}

void World::setHouse1()
{
	vector<vector<worldChunk> > vec1(5, vector<worldChunk>(6));
	house1Rows = vec1;

	for (int rows = 0; rows < 5; rows++)
	{
		for (int colms = 0; colms < 6; colms++)
		{
			house1Rows[rows][colms].symbol = 'X';
			house1Rows[rows][colms].playerSymbol = 'o';
			house1Rows[rows][colms].player = false;
		}
	}

	for (int rows = 1; rows < 4; rows++)
	{
		for (int colms = 1; colms < 5; colms++)
		{
			house1Rows[rows][colms].symbol = ' ';
		}
	}
	house1Rows[3][2].symbol = 'V'; house1Rows[3][3].symbol = 'V'; house1Rows[1][4].symbol = 'O';
}

void World::setTown1()
{
	vector<vector<worldChunk> > vec2(13, vector<worldChunk>(17));
	dumTownRows = vec2;

	for (int rows = 0; rows < 13; rows++)
	{
		for (int colms = 0; colms < 17; colms++)
		{
			dumTownRows[rows][colms].symbol = 'X';
			dumTownRows[rows][colms].playerSymbol = 'o';
			dumTownRows[rows][colms].player = false;
		}
	}

	for (int rows = 1; rows < 12; rows++)
	{
		for (int colms = 1; colms < 16; colms++)
		{
			dumTownRows[rows][colms].symbol = '~';
		}
	}

	for (int rows = 2; rows < 11; rows++)
	{
		for (int colms = 2; colms < 15; colms++)
		{
			dumTownRows[rows][colms].symbol = ' ';
		}
	}

	for (int rows = 3; rows < 6; rows++)
	{
		for (int colms = 3; colms < 7; colms++)
		{
			dumTownRows[rows][colms].symbol = '#';
		}
	}
	dumTownRows[5][4].symbol = 'V';

	for (int rows = 3; rows < 5; rows++)
	{
		for (int colms = 11; colms < 14; colms++)
		{
			dumTownRows[rows][colms].symbol = '#';
		}
	}
	dumTownRows[4][12].symbol = 'V';

	for (int rows = 8; rows < 11; rows++)
	{
		for (int colms = 8; colms < 12; colms++)
		{
			dumTownRows[rows][colms].symbol = '#';
		}
	}
	dumTownRows[8][10].symbol = 'V';

	for (int colms = 2; colms < 5; colms++)
	{
		dumTownRows[7][colms].symbol = '=';
	}

	for (int colms = 4; colms < 10; colms++)
	{
		dumTownRows[6][colms].symbol = '=';
	}

	for (int colms = 11; colms < 13; colms++)
	{
		dumTownRows[5][colms].symbol = '=';
	}

	for (int rows = 2; rows < 8; rows++)
	{
		dumTownRows[rows][10].symbol = '=';
	}
	dumTownRows[1][10].symbol = 'V'; dumTownRows[7][1].symbol = 'V';
}

void World::setLab()
{
	vector<vector<worldChunk> > vec3(8, vector<worldChunk>(9));
	labRows = vec3;

	for (int rows = 0; rows < 8; rows++)
	{
		for (int colms = 0; colms < 9; colms++)
		{
			labRows[rows][colms].symbol = 'X';
			labRows[rows][colms].playerSymbol = 'o';
			labRows[rows][colms].player = false;
		}
	}

	for (int rows = 1; rows < 7; rows++)
	{
		for (int colms = 1; colms < 8; colms++)
		{
			labRows[rows][colms].symbol = ' ';
		}
	}

	labRows[2][1].symbol = '-'; labRows[2][2].symbol = '-'; labRows[1][2].symbol = '-'; labRows[1][1].symbol = '-'; 
	labRows[2][7].symbol = '-'; labRows[3][7].symbol = '-'; labRows[3][6].symbol = '-';
	labRows[5][1].symbol = '-'; labRows[5][2].symbol = '-'; labRows[6][1].symbol = '-'; labRows[6][2].symbol = '-'; labRows[5][3].symbol = '-'; labRows[6][3].symbol = '-';
	labRows[6][5].symbol = '-'; labRows[6][6].symbol = '-'; labRows[6][7].symbol = '-'; labRows[5][6].symbol = '-'; labRows[5][7].symbol = '-'; labRows[5][5].symbol = 'O'; labRows[1][4].symbol = 'V';
}

void World::setTrainingIsle()
{
	vector<vector<worldChunk> > vec4(11, vector<worldChunk>(14));
	tIsleRows = vec4;

	for (int rows = 0; rows < 11; rows++)
	{
		for (int colms = 0; colms < 14; colms++)
		{
			tIsleRows[rows][colms].symbol = 'X';
			tIsleRows[rows][colms].playerSymbol = 'o';
			tIsleRows[rows][colms].player = false;
		}
	}

	for (int rows = 1; rows < 10; rows++)
	{
		for (int colms = 1; colms < 13; colms++)
		{
			tIsleRows[rows][colms].symbol = '~';
			
		}
	}

	for (int rows = 2; rows < 9; rows++)
	{
		for (int colms = 4; colms < 8; colms++)
		{
			tIsleRows[rows][colms].symbol = ':';

		}
	}

	for (int rows = 2; rows < 9; rows++)
	{
		for (int colms = 4; colms < 8; colms++)
		{
			tIsleRows[rows][colms].symbol = ':';

		}
	}

	for (int rows = 3; rows < 9; rows++)
	{
		tIsleRows[rows][3].symbol = ':';
	}

	for (int rows = 3; rows < 8; rows++)
	{
		tIsleRows[rows][8].symbol = ':';
	}
	tIsleRows[4][2].symbol = ':'; tIsleRows[5][2].symbol = ':'; tIsleRows[6][2].symbol = ':'; tIsleRows[5][9].symbol = ':'; tIsleRows[6][9].symbol = ':'; tIsleRows[7][9].symbol = ':';

	for (int rows = 3; rows < 8; rows++)
	{
		tIsleRows[rows][6].symbol = 'M';
	}
	for (int rows = 3; rows < 8; rows++)
	{
		tIsleRows[rows][5].symbol = 'M';
	}
	for (int rows = 4; rows < 8; rows++)
	{
		tIsleRows[rows][4].symbol = 'M';
	}
	tIsleRows[5][3].symbol = 'M'; tIsleRows[4][7].symbol = 'M'; tIsleRows[5][7].symbol = 'M'; tIsleRows[6][7].symbol = 'M'; tIsleRows[6][8].symbol = 'M';
	tIsleRows[6][10].symbol = '='; tIsleRows[6][11].symbol = '='; tIsleRows[6][12].symbol = 'V';
}

void World::setAreas()
{
	areas.push_back(homeRows);
	areas.push_back(house1Rows);
	areas.push_back(dumTownRows);
	areas.push_back(labRows);
	areas.push_back(tIsleRows);
}
//-------------------------------------------------------------------------------------------------------
void World::displayArray()
{
	switch (playerArea)
	{
	case 0: 
		for (int rows = 0; rows < 7; rows++)
		{
			for (int colms = 0; colms < 8; colms++)
			{
				dHelp(rows, colms);
			}
			cout << "\n";
		}
		break;
	case 1:
		for (int rows = 0; rows < 5; rows++)
		{
			for (int colms = 0; colms < 6; colms++)
			{
				dHelp(rows, colms);
			}
			cout << "\n";
		}
		break;
	case 2: 
		for (int rows = 0; rows < 13; rows++)
		{
			for (int colms = 0; colms < 17; colms++)
			{
				dHelp(rows, colms);
			}
			cout << "\n";
		}
		break;
	case 3: 
		for (int rows = 0; rows < 8; rows++)
		{
			for (int colms = 0; colms < 9; colms++)
			{
				dHelp(rows, colms);
			}
			cout << "\n";
		}
		break;
	case 4: 
		for (int rows = 0; rows < 11; rows++)
		{
			for (int colms = 0; colms < 14; colms++)
			{
				dHelp(rows, colms);
			}
			cout << "\n";
		}
		break;
	}

}

decision World::changePos(char direction, Player& player, int& NPCnum_)
{
	bool help = true;

	switch(direction)
	{
		//lefft
	case 'a': nextCords.xPos--;
		break;
		//right
	case 'd': nextCords.xPos++;
		break;
		//up
	case 'w': nextCords.yPos--;
		break;
		//down
	case 's': nextCords.yPos++;
		break;
	case'm':
		return menu;
		break;
	default: help = false;
		break;
	}

	//if valid direction is given
	if (help)
	{
		//Running into an obstacle
		if (areas[playerArea][nextCords.yPos][nextCords.xPos].symbol == 'X' || areas[playerArea][nextCords.yPos][nextCords.xPos].symbol == '~' || areas[playerArea][nextCords.yPos][nextCords.xPos].symbol == '#' || areas[playerArea][nextCords.yPos][nextCords.xPos].symbol == '-' || areas[playerArea][nextCords.yPos][nextCords.xPos].symbol == '|')
		{
			moveBack(direction);
			return normal;
		}
		//Traveling to different section
		else if(areas[playerArea][nextCords.yPos][nextCords.xPos].symbol == 'V')
		{
			changeArea();
			return normal;
		}
		//Interaction with NPC
		else if (areas[playerArea][nextCords.yPos][nextCords.xPos].symbol == 'O')
		{
			interact(player, NPCnum_);
			moveBack(direction);
			return text;
		}
		//Moving to next space
		else
		{
			areas[playerArea][playerCords.yPos][playerCords.xPos].player = false;
			playerCords = nextCords;
			areas[playerArea][playerCords.yPos][playerCords.xPos].player = true;
			return normal;

		}
	}
	else
	{
		return redo;
	}
}

// helps with the display array function.
void World::dHelp(int rows, int colms)
{
	if (areas[playerArea][rows][colms].player)
		cout << areas[playerArea][rows][colms].playerSymbol << " ";

	else
		cout << areas[playerArea][rows][colms].symbol << " ";
}

// helps with changeArea
void World::changeArea()
{
	switch (playerArea)
	{
	case 0: // going from home to town
		areas[playerArea][playerCords.yPos][playerCords.xPos].player = false;
		playerArea = 2;
		playerCords.xPos = 4; playerCords.yPos = 6;
		areas[playerArea][playerCords.yPos][playerCords.xPos].player = true;
		nextCords = playerCords;
		break;
	case 1: // going from house1 to town
		areas[playerArea][playerCords.yPos][playerCords.xPos].player = false;
		playerArea = 2;
		playerCords.xPos = 12; playerCords.yPos = 5;
		areas[playerArea][playerCords.yPos][playerCords.xPos].player = true;
		nextCords = playerCords;
		break;
	case 2: // leaving town
		switch (nextCords.yPos)
		{
		case 1:// under construction
			break;
		case 4: // entering house1
			areas[playerArea][playerCords.yPos][playerCords.xPos].player = false;
			playerArea = 1;
			playerCords.xPos = 2; playerCords.yPos = 2;
			areas[playerArea][playerCords.yPos][playerCords.xPos].player = true;
			nextCords = playerCords;
			break;
		case 5: // entering home
			areas[playerArea][playerCords.yPos][playerCords.xPos].player = false;
			playerArea = 0;
			playerCords.xPos = 2; playerCords.yPos = 4;
			areas[playerArea][playerCords.yPos][playerCords.xPos].player = true;
			nextCords = playerCords;
			break;
		case 7: // entering tIsle
			areas[playerArea][playerCords.yPos][playerCords.xPos].player = false;
			playerArea = 4;
			playerCords.xPos = 11; playerCords.yPos = 6;
			areas[playerArea][playerCords.yPos][playerCords.xPos].player = true;
			nextCords = playerCords;
			break;
		case 8: // entering lab
			areas[playerArea][playerCords.yPos][playerCords.xPos].player = false;
			playerArea = 3;
			playerCords.xPos = 4; playerCords.yPos = 2;
			areas[playerArea][playerCords.yPos][playerCords.xPos].player = true;
			nextCords = playerCords;
			break;
		}
		break;
	case 3: // leaving lab
		areas[playerArea][playerCords.yPos][playerCords.xPos].player = false;
		playerArea = 2;
		playerCords.xPos = 10; playerCords.yPos = 7;
		areas[playerArea][playerCords.yPos][playerCords.xPos].player = true;
		nextCords = playerCords;
		break;
	case 4: // leaving tIsle
		areas[playerArea][playerCords.yPos][playerCords.xPos].player = false;
		playerArea = 2;
		playerCords.xPos = 2; playerCords.yPos = 7;
		areas[playerArea][playerCords.yPos][playerCords.xPos].player = true;
		nextCords = playerCords;
		break;
	}
}

void World::interact(Player& player, int& NPCnum_)
{
	switch (playerArea)
	{
	case 0: 
		if (eNumMom == 0)
		{
			NPCnum_ = 1;
			eNumMom++;
		}
		else
		{
			//should heal all dopeymon in party.
			for (int i = 0; i < 6; i++)
			{
				player.changeMonHealth(i, player.getMons(i).getMaxHealth());
			}
			NPCnum_ = 5;
		}
		
		break;
	case 1:
		NPCnum_ = 2;
		break;
	case 3: 
		if (eNumLab == 0)
		{
			NPCnum_ = 3;
			srand(unsigned int(time(NULL)));
			int num = (rand() % 5);

			vector<Dopeymon> temp;
			Elechick mon0; temp.push_back(mon0);
			Lazator mon1; temp.push_back(mon1);
			Snoth mon2; temp.push_back(mon2);
			Hellipo mon3; temp.push_back(mon3);
			Keechi mon4; temp.push_back(mon4);

			for (int i = 0; i < 5; i++)
			{
				if (i == num)
					player.addMons(temp[i]);
			}
			eNumLab++;
		}
		else
		{
			NPCnum_ = 4;
		}
		
	}
}

void World::moveBack(char direction)
{
	switch (direction)
	{
		//lefft
	case 'a': nextCords.xPos++;
		break;
		//right
	case 'd': nextCords.xPos--;
		break;
		//up
	case 'w': nextCords.yPos++;
		break;
		//down
	case 's': nextCords.yPos--;
		break;
	default:
		break;
	}
}


