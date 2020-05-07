#ifndef World_H
#define World_H
#include<vector>
#include<string>
#include<time.h>
#include"AllDopeymon.h"
#include"Player.h"
using namespace std;

enum decision {normal, redo, text, menu};

struct worldChunk
{
	char symbol;
	char playerSymbol;
	bool player;
};

struct coordinates
{
	int xPos;
	int yPos;
};

class World
{
public:
	//Constructor.
	World();

	//Deconstructor.
	~World();

	//Set functions for arrays.
	void setHome();
	void setHouse1();
	void setTown1();
	void setLab();
	void setTrainingIsle();
	void setAreas();

	//Functions that display each area to screen.
	void displayArray();

	//
	decision changePos(char direction, Player& player, int& NPCnum_);

	//get functions
	int getArea() { return playerArea; };
	char getSymbol() { return areas[playerArea][playerCords.yPos][playerCords.xPos].symbol; };


private:

	worldChunk chunk;

	//Variable that keeps track of which array the player is in.
	int playerArea; // 0: home, 1: house1, 2: dumTown, 3: Lab, 4: trainingIsle,

	//Keeps track of player's speciffic coordinates
	coordinates playerCords;

	//keeps track of the coordinates where the player is trying to move.
	coordinates nextCords;

	//Vectors that I will need:

	vector<worldChunk> homeColms; //need 8
	vector<vector<worldChunk> > homeRows; //need 7

	vector<worldChunk> house1Colms; //need 6
	vector<vector<worldChunk> > house1Rows; //need 5

	vector<worldChunk> dumTownColms; //need 17
	vector<vector<worldChunk> > dumTownRows; //need 13

	vector<worldChunk> labColms; //need 9
	vector<vector<worldChunk> > labRows; //need 8

	vector<worldChunk> tIsleColms; //need 14
	vector<vector<worldChunk> > tIsleRows; //need 11

	vector<vector<vector<worldChunk> > > areas; 

	void dHelp(int rows, int colms);
	//--------------------------------------------------------
	//function that help with change position
	void changeArea();

	void interact(Player& player, int& NPCnum_);
	int eNumLab; // number of encounters at lab
	int eNumMom; // number of encounters with mom

	void moveBack(char direction);
	//---------------------------------------------------------
};

#endif
