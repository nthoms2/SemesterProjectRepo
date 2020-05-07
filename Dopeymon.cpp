#include "Dopeymon.h"

Dopeymon::Dopeymon()
{
	setName("debug");
	setNumber(0);
	setType(neutral);
	setLevel(5);
	setCExp(0);
	setNExp();
	setBHealth(10);
	setBStrength(10);
	setBDefense(10);
	setBSpeed(10);
	setMaxHealth();
	setMaxStrength();
	setMaxDefense();
	setMaxSpeed();
	setCHealth();
	Attack attack1; Attack attack2; Attack attack3; Attack attack4;
	setMoves(attack1, attack2, attack3, attack4);
}

Dopeymon::~Dopeymon()
{
}

void Dopeymon::abillity()
{
}

void Dopeymon::display()
{
}

void Dopeymon::setNExp()
{
	nExp = (((6 / 5) * (pow(level, 3))) - (15 * (pow(level, 2))) + (100 * level) - 140);
}

void Dopeymon::setMaxHealth()
{
	maxHealth = ((level * (6 / 4)) + bHealth); 
}

void Dopeymon::setMaxStrength()
{
	maxStrength = ((level * (6 / 4)) + bStrength);
}

void Dopeymon::setMaxDefense()
{
	maxDefense = ((level * (6 / 4)) + bDefense);
}

void Dopeymon::setMaxSpeed()
{
	maxSpeed = ((level * (6 / 4)) + bSpeed);
}

void Dopeymon::setMoves(Attack attack1, Attack attack2, Attack attack3, Attack attack4)
{
	moves.attack1 = attack1; moves.attack2 = attack2; moves.attack3 = attack3; moves.attack4 = attack4;
}
