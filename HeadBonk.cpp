#include "HeadBonk.h"

HeadBonk::HeadBonk()
{
	setAtkName("Head Bonk");
	setAtkPwr(43);
	setAtkType(neutral);
	setAtkEffect(stun);
	setEffectChance(15);
}

HeadBonk::~HeadBonk()
{
}
