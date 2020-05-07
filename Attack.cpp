#include "Attack.h"

Attack::Attack()
{
	setAtkName("debug");
	setAtkPwr(0);
	setAtkType(neutral);
	setAtkEffect(none);
	setEffectChance(0);
}

Attack::~Attack()
{
}

void Attack::specialEffect()
{
}
