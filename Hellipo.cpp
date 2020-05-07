#include "Hellipo.h"

Hellipo::Hellipo()
{
	setName("Hellipo");
	setNumber(4);
	setType(fire);
	setLevel(5);
	setCExp(0);
	setNExp();
	setBHealth(85);
	setBStrength(45);
	setBDefense(50);
	setBSpeed(25);
	setMaxHealth();
	setMaxStrength();
	setMaxDefense();
	setMaxSpeed();
	setCHealth();
	Stomp attack1; MagmaBelch attack2; Attack attack3; Attack attack4;
	setMoves(attack1, attack2, attack3, attack4);
}

Hellipo::~Hellipo()
{
}
