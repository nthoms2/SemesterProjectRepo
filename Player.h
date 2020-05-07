#ifndef Player_H
#define Player_H
#include"AllDopeymon.h"
#include<vector>

class Player
{
public:
	//constructor
	Player();
	//deconstructor
	~Player();

	//adds dopeymon into list
	void addMons(Dopeymon mons);

	//gets monster from the list
	Dopeymon getMons(int num);

	void changeMonHealth(int num, int nHealth);

private:
	//where player's dopeymon are stored.
	vector<Dopeymon> playersMons;

	//max number of dopeymon allowed in vector 
	int maxMons;
	//current size of vector
	int cSize;
};

#endif
