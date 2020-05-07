#include "Player.h"

Player::Player()
{
	maxMons = 6;
	cSize = 0; 
	Dopeymon mons;
	for (int i = 0; i < 6; i++)
	{
		playersMons.push_back(mons);
	}
}

Player::~Player()
{
}

void Player::addMons(Dopeymon mons)
{
	if (cSize < maxMons)
	{
		bool help = true;

		for (int i = 0; i < 6; i++)
		{
			if (help)
			{
				if (playersMons[i].getName() == "debug")
				{
					playersMons[i] = mons;
					cSize++;
					help = false;
				}
			}
			
		}
	}
	
}

Dopeymon Player::getMons(int num)
{
	return playersMons[num];
}

void Player::changeMonHealth(int num, int nHealth)
{
	playersMons[num].changeCHealth(nHealth);
}
