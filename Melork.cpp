#include "Melork.h"

Melork::Melork()
{
	setName("Melork");
	setNumber(7);
	setType(melon);
	setLevel(5);
	setCExp(0);
	setNExp();
	setBHealth(85);
	setBStrength(37);
	setBDefense(73);
	setBSpeed(27);
	setMaxHealth();
	setMaxStrength();
	setMaxDefense();
	setMaxSpeed();
	setCHealth();
	Peck attack1; Juice attack2; Attack attack3; Attack attack4;
	setMoves(attack1, attack2, attack3, attack4);
}

Melork::~Melork()
{

}
