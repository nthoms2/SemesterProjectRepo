#include "Elechick.h"

Elechick::Elechick()
{
	setName("Elechick");
	setType(lightning);
	setNumber(1);
	setLevel(5);
	setCExp(0);
	setNExp();
	setBHealth(70);
	setBStrength(45);
	setBDefense(25);
	setBSpeed(50);
	setMaxHealth();
	setMaxStrength();
	setMaxDefense();
	setMaxSpeed();
	setCHealth();
	Peck attack1; StaticShock attack2; Attack attack3; Attack attack4;
	setMoves(attack1, attack2, attack3, attack4);
}

Elechick::~Elechick()
{
}
