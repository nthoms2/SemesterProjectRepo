#ifndef Dopeymon_H
#define Dopeymon_H
#include<cmath>
#include"Attack.h"
#include"Juice.h"
#include"HeadBonk.h"
#include"LeafTouch.h"
#include"MagmaBelch.h"
#include"MarkTerritory.h"
#include"MudBall.h"
#include"Munch.h"
#include"Peck.h"
#include"SandBlast.h"
#include"Scratch.h"
#include"SloberShot.h"
#include"StaticShock.h"
#include"Stomp.h"
#include"Wiggle.h"
using namespace std;

struct  moveSet
{
	Attack attack1;
	Attack attack2;
	Attack attack3;
	Attack attack4;
};

class Dopeymon
{
public:
	//constructor
	Dopeymon();
	//deconstructor
	~Dopeymon();

	virtual void abillity();
	virtual void display();
	//set and get functions
	void setName(string name_) { name = name_; };
	string getName() { return name; };

	void setNumber(int num) { number = num; };
	int getNumber() { return number; };

	void setType(type type_) { type = type_; };
	type getType() { return type; };

	void setLevel(int level_) { level = level_; };
	int getLevel() { return level; };

	void setCExp(int cExp_) { cExp = cExp_; };
	int getCExp() { return cExp; };

	void setNExp();
	int getNExp() { return nExp; };

	void setBHealth(int bHealth_) { bHealth = bHealth_; };
	int getBHealth() { return bHealth; };

	void setBStrength(int bStrength_) { bStrength = bStrength_;};
	int getBStrength() { return bStrength; }; 

	void setBDefense(int bDefense_) { bDefense = bDefense_; };
	int getBDefense() { return bStrength; };

	void setBSpeed(int bSpeed_) { bSpeed = bSpeed_; };
	int getBSpeed() { return bSpeed; };

	void setMaxHealth();
	int getMaxHealth() { return maxHealth; };

	void setMaxStrength();
	int getMaxStrength() { return maxStrength; }; 

	void setMaxDefense();
	int getMaxDefense() {return maxDefense; };

	void setMaxSpeed();
	int getMaxSpeed() { return maxSpeed; }; 

	void setCHealth() { cHealth = maxHealth; };
	void changeCHealth(int change) { cHealth = change; };
	int getCHealth() { return cHealth; };

	void setMoves(Attack attack1, Attack attack2, Attack attack3, Attack attack4);
	moveSet getMoves() { return moves; };
private:
	//basic attributes
	string name;
	int number;
	type type;

	//level
	int level;
	int cExp; // current amount of exp
	int nExp; // amount needed to reach next level

	//base Stats 
	int bHealth;
	int bStrength;
	int bDefense;
	int bSpeed;

	//changing stats based on level
	int maxHealth;
	int maxStrength;
	int maxDefense;
	int maxSpeed;

	//changing stats based on battle
	int cHealth;

	//moves
	moveSet moves;

};

#endif
