#include "Galapagoat.h"

Galapagoat::Galapagoat()
{
	setName("Galapagoat");
	setType(grass);
	setNumber(6);
	setLevel(5);
	setCExp(0);
	setNExp();
	setBHealth(80);
	setBStrength(40);
	setBDefense(75);
	setBSpeed(35);
	setMaxHealth();
	setMaxStrength();
	setMaxDefense();
	setMaxSpeed();
	setCHealth();
	HeadBonk attack1; LeafTouch attack2; Attack attack3; Attack attack4;
	setMoves(attack1, attack2, attack3, attack4);
}

Galapagoat::~Galapagoat()
{
}
