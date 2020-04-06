#include <iostream>
#include <vector>
#include "World.h"
using namespace std;

World::World()
{
	playerArea = 0;
	playerCords.xPos = 6;
	playerCords.yPos = 4;
	setHome(); // something wrong here
	setAreas();
}

World::~World()
{

}

void World::setHome()
{
	for (int i = 0; i < 8; i++)
	{
		homeColms.push_back(worldChunk());
	}
	for (int i = 0; i < 7; i++);
	{
		homeRows.push_back(homeColms);
	}

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
			homeRows[rows][colms].symbol = '*';
			homeRows[rows][colms].playerSymbol = 'o';
			homeRows[rows][colms].player = false;
		}
	}
	homeRows[1][6].symbol = '-'; homeRows[1][5].symbol = '-'; homeRows[2][6].symbol = '|'; homeRows[2][5].symbol = '|'; homeRows[3][6].symbol = '|'; homeRows[3][5].symbol = '|';
	homeRows[2][2].symbol = '-'; homeRows[2][3].symbol = '-'; homeRows[3][2].symbol = '-'; homeRows[3][3].symbol = '-'; homeRows[3][1].symbol = 'O'; homeRows[4][2].symbol = 'v'; homeRows[4][3].symbol = 'v';
	
}

void World::setHouse1()
{
}

void World::setTown1()
{
}

void World::setLab()
{
}

void World::setTrainingIsle()
{
}

void World::setAreas()
{
	areas.push_back(homeRows);
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
				cout << areas[playerArea][rows][colms].symbol;
			}
		}
		break;
	case 1:
		break;
	}

}

void World::adventure()
{
}


