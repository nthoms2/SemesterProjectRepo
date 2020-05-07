#include "Lazator.h"

Lazator::Lazator()
{
	setName("Lazator");
	setType(water);
	setNumber(2);
	setLevel(5);
	setCExp(0);
	setNExp();
	setBHealth(80);
	setBStrength(45);
	setBDefense(40);
	setBSpeed(25);
	setMaxHealth();
	setMaxStrength();
	setMaxDefense();
	setMaxSpeed();
	setCHealth();
	Munch attack1; SloberShot attack2; Attack attack3; Attack attack4;
	setMoves(attack1, attack2, attack3, attack4);
}

Lazator::~Lazator()
{
}
