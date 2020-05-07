#include "Guppy.h"

Guppy::Guppy()
{
	setName("Guppy");
	setNumber(9);
	setType(water);
	setLevel(5);
	setCExp(0);
	setNExp();
	setBHealth(30);
	setBStrength(30);
	setBDefense(30);
	setBSpeed(45);
	setMaxHealth();
	setMaxStrength();
	setMaxDefense();
	setMaxSpeed();
	setCHealth();
	Wiggle attack1; MarkTerritory attack2; Attack attack3; Attack attack4;
	setMoves(attack1, attack2, attack3, attack4);
}

Guppy::~Guppy()
{

}
