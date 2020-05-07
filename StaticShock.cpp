#include "StaticShock.h"

StaticShock::StaticShock()
{
	setAtkName("Static Shock");
	setAtkPwr(25);
	setAtkType(lightning);
	setAtkEffect(stun);
	setEffectChance(20);
}

StaticShock::~StaticShock()
{
	
}
