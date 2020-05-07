#include "Snoth.h"

Snoth::Snoth()
{
	setName("Snoth");
	setType(earth);
	setNumber(3);
	setLevel(5);
	setCExp(0);
	setNExp();
	setBHealth(85);
	setBStrength(40);
	setBDefense(50);
	setBSpeed(15);
	setMaxHealth();
	setMaxStrength();
	setMaxDefense();
	setMaxSpeed();
	setCHealth();
	Scratch attack1; MudBall attack2; Attack attack3; Attack attack4;
	setMoves(attack1, attack2, attack3, attack4);
}

Snoth::~Snoth()
{
}
