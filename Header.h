#ifndef Worlds_H
#define Worlds_H

#include<string>
using namespace std;

struct worldChunk
{
	char symbol;
	char playerSymbol;
	bool player?;
};

struct playerLoc
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



private:
	//all of the arrays needed for the world
	worldChunk home[5][6];
	worldChunk house1[3][4];
	worldChunk Town1[11][15];
	worldChunk Lab[6][7];

};

#endif