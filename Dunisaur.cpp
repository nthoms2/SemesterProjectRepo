#include "Dunisaur.h"

Dunisaur::Dunisaur()
{
	setName("Dunisaur");
	setType(earth);
	setNumber(8);
	setLevel(5);
	setCExp(0);
	setNExp();
	setBHealth(72);
	setBStrength(52);
	setBDefense(20);
	setBSpeed(42);
	setMaxHealth();
	setMaxStrength();
	setMaxDefense();
	setMaxSpeed();
	setCHealth();
	Munch attack1; SandBlast attack2; Attack attack3; Attack attack4;
	setMoves(attack1, attack2, attack3, attack4);
}

Dunisaur::~Dunisaur()
{
}
