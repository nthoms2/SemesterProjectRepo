#ifndef World_H
#define World_H
#include<vector>
#include<string>
using namespace std;

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
	void adventure();

private:

	worldChunk chunk;

	//Variable that keeps track of which array the player is in.
	int playerArea; // 0: home, 1: house1, 2: dumTown, 3: Lab, 4: trainingIsle,

	//Keeps track of player's speciffic coordinates
	coordinates playerCords;

	//Vectors that I will need:

	vector<worldChunk> homeColms; //need 8
	vector<vector<worldChunk> > homeRows; //need 7
	vector<vector<worldChunk> > home(7, vector<worldChunk>(8));

	vector<worldChunk> house1Colms; //need 6
	vector<vector<worldChunk> > house1Rows; //need 5

	vector<worldChunk> dumTownColms; //need 17
	vector<vector<worldChunk> > dumTownRows; //need 13

	vector<worldChunk> LabColms; //need 9
	vector<vector<worldChunk> > LabRows; //need 8

	vector<worldChunk> tIsleColms; //need 14
	vector<vector<worldChunk> > tIsleRows; //need 11

	vector<vector<vector<worldChunk> > > areas; 
};

#endif
