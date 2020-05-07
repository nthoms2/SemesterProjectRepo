#include "Keechi.h"

Keechi::Keechi()
{
	setName("Keechi");
	setNumber(5);
	setType(grass);
	setLevel(5);
	setCExp(0);
	setNExp();
	setBHealth(68);
	setBStrength(45);
	setBDefense(35);
	setBSpeed(50);
	setMaxHealth();
	setMaxStrength();
	setMaxDefense();
	setMaxSpeed();
	setCHealth();
	Scratch attack1; LeafTouch attack2; Attack attack3; Attack attack4;
	setMoves(attack1, attack2, attack3, attack4);
}

Keechi::~Keechi()
{
}
