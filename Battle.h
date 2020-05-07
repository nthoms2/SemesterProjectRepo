#ifndef Battle_H
#define Battle_H
#include"Player.h"
#include<stdlib.h>
#include<time.h>
#include<iostream>

enum effectiveness{sEffective, Effective, nEffective};

class Battle
{
public:
	//constructor
	Battle();
	//deconstructor
	~Battle();

	//main function of Battle, call all other nescisarry functions within battle
	void battlePhase(Player& player, Dopeymon wildMon); 

private:
	int monNum;
	bool run;
	Attack playerAttack;
	Attack foeAttack;
	bool caught; // checks to see if the dopeymon is caught

	//these function return a bool value, either true or false
	//the main loop in battle function uses their values to see if the battle
	//should continue and run.
	bool atf(Player& player); //player is able to fight
	bool watf(Dopeymon wildMon);//wild dopeymon is able to fight
	
	//4 option funtions
	//this collection of functions is used to go within each segment of the battle menu
	bool monAttack(Dopeymon mon, Dopeymon wildMon);
	void moveDisplay(Attack attack);
	bool bag(Dopeymon wildMon, Player& player);
	void monCatch(Dopeymon wildMon, Player& player);
	bool switchMon(Player& player);

	//this collection of functions involve generating a random attack for the wild mon
	//and then taking the attacks that were selected and evalulating the damage done
	//to each mon.
	void wildAttack(Dopeymon wildMon);
	void attackEval(Dopeymon mon, Dopeymon& wildMon, Player& player);
	void damageEval(Dopeymon mon1, Dopeymon& mon2, Attack attack);
	effectiveness effectiveEval(type type1, type type2);

	//base display function
	void battleDisplay(Dopeymon playersMon, Dopeymon wildMon);
	//displays info for an individual dopeymon(will be called twice in the base display function
	void monDisplay(Dopeymon mon);
	//individual dopeymon display functions
	void elechickDisplay(Dopeymon mon);
	void lazatorDisplay(Dopeymon mon);
	void snothDisplay(Dopeymon mon);
	void hellipoDisplay(Dopeymon mon);
	void keechiDisplay(Dopeymon mon);
	void galapagoatDisplay(Dopeymon mon);
	void melorkDisplay(Dopeymon mon);
	void dunisaurDisplay(Dopeymon mon);
	void guppyDisplay(Dopeymon mon);
	//goes with above functions
	void numXs(Dopeymon mon);
	//---------------------------------------------------------------------------------------
	void inputDisplayA();
};
#endif