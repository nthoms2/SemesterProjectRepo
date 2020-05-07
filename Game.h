#ifndef Game_H
#define Game_H
#include<string>
#include"Battle.h"
#include "World.h"
#include "Player.h"
using namespace std;

class Game
{
public:
	//constructor
	Game();
	//deconstructor
	~Game();

	void adventure();

private:
	World world;
	Player player;
	int NPCnum;

	decision move(int& NPCnum_);
	void talk();

	//menu function
	void menuDisplay();

	//functions with in menu
	void menuKey();

	void menuDopeymon();
	void displayStats(int i);
	void moveDisplay(Attack attack);

	//wild encounter functions
	void wildCheck();
	void grassEncounters();
	void sandEncounters();
};


#endif
