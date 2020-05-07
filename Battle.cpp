#include "Battle.h"

Battle::Battle()
{
	monNum = 0;
	caught = false;
	run = false;
}

Battle::~Battle()
{
}

void Battle::battlePhase(Player& player, Dopeymon wildMon)
{
	if (atf(player)==true)
	{
		cout << "you encountered a wild " << wildMon.getName() << endl;
		cout << "press anything" << endl;
		char input; cin >> input;
		while (atf(player) == true && watf(wildMon)== true)
		{
			bool valid = true;
			while (valid)
			{
				Attack temp;
				playerAttack = temp;
				char input;
				battleDisplay(player.getMons(monNum), wildMon);
				inputDisplayA();
				cin >> input;

				switch (input)
				{
				case '1': valid = monAttack(player.getMons(monNum), wildMon); //attack
					break;
				case '2': valid = bag(wildMon, player);//bag
					break;
				case '3': valid = switchMon(player);//dopeymon
					break;
				case '4': valid = false;//flee
					run = true;
					break;
				default: valid = true;
					break;
				}
			}

			if (caught == true)
				break;
			if (run == true)
				break;

			wildAttack(wildMon);
			attackEval(player.getMons(monNum), wildMon, player);

		}
		// outside the loop
		if (run == true)
		{
			system("CLS");
			cout << "you got away safely" << endl;
		}
		else if (caught == true)
		{
			system("CLS");
			cout << "doo da dooo, congradulations you caught a wild " << wildMon.getName() <<endl;
		}
		else if (atf(player) == false)
		{
			system("CLS");
			cout << "dang all of your friends are dead, better go heal up" << endl;
		}
		else if (watf(wildMon) == false)
		{
			system("CLS");
			cout << "Hooray!! you beat up the wild" << wildMon.getName() << endl;
		}



	}
	else
	{

	}
	
}

//-------------------------------------------------------------------------------------------
bool Battle::atf(Player& player)
{
	int numFaint = 0;
	int j = 0;
	while (j < 6)
	{
		if (player.getMons(j).getNumber() == 0)
			numFaint++;
		else if (player.getMons(j).getCHealth() == 0)
			numFaint++;
		j++;
	}
		
	if (numFaint == 6)
		return false;
	else
		return true;
}

bool Battle::watf(Dopeymon wildMon)
{
	if (wildMon.getCHealth() == 0)
		return false;
	else
		return true;
}

bool Battle::monAttack(Dopeymon mon, Dopeymon wildMon)
{
	system("CLS");
	battleDisplay(mon, wildMon);
	cout << "1 "; moveDisplay(mon.getMoves().attack1); 
	cout << "\n2 "; moveDisplay(mon.getMoves().attack2);
	cout << "\n3 "; moveDisplay(mon.getMoves().attack3);
	cout << "\n4 "; moveDisplay(mon.getMoves().attack4);
	cout << "\npress anything else to go back, also do not chose empty move" << endl;

	char input;
	cin >> input;

	switch (input)
	{
	case '1':
		if (mon.getMoves().attack1.getAtkName() == "debug")
			return true;
		else
			playerAttack = mon.getMoves().attack1; return false;
		break;
	case '2':
		if (mon.getMoves().attack2.getAtkName() == "debug")
			return true;
		else
			playerAttack = mon.getMoves().attack2; return false;
		break;
	case '3': 
		if (mon.getMoves().attack3.getAtkName() == "debug")
			return true;
		else
			playerAttack = mon.getMoves().attack3; return false;
		break;
	case '4': 
		if (mon.getMoves().attack4.getAtkName() == "debug")
			return true;
		else
			playerAttack = mon.getMoves().attack4; return false;
		break;
	default: return true;
		break;
	}
}

void Battle::moveDisplay(Attack attack)
{
	if (attack.getAtkName() == "debug")
		cout << "none" << endl;

	else
	{
		cout << attack.getAtkName()  << ": type = ";
		switch (attack.getAtkType())
		{
		case neutral: cout << "neutral" << endl;
			break;
		case fire: cout << "fire" << endl;
			break;
		case water: cout << "water" << endl;
			break;
		case earth: cout << "earth" << endl;
			break;
		case lightning: cout << "ligthning" << endl;
			break;
		case grass: cout << "grass" << endl;
			break;
		case melon: cout << "melon" << endl;
			break;
		case poop: cout << "poop" << endl;
			break;
		}
	}
}

bool Battle::bag(Dopeymon wildMon, Player& player)
{
	system("CLS");
	cout << "bag items:" << endl;
	cout << "1: ordinary snack (used to befriend dopeymon)";
	cout << "\npress anything else to go back" << endl;

	char input;
	cin >> input;
	switch (input)
	{
	case '1': monCatch(wildMon, player); return false;
		break;
	default: return true;
		break;
	}
}

void Battle::monCatch(Dopeymon wildMon, Player& player)
{
	float oneX = (float(wildMon.getMaxHealth()) / 10);
	int cRate = ((wildMon.getCHealth()+10) / oneX);

	srand(unsigned int(time(NULL)));
	int num = (rand() % cRate)+1 ;

	if (num == 1)
	{
		player.addMons(wildMon);
		caught = true;
	}
}

bool Battle::switchMon(Player& player)
{
	system("CLS");
	cout << "your dopeymon:" << endl;
	for (int i = 0; i < 6; i++)
	{
		if (player.getMons(i).getName() == "debug")
			cout << i + 1 << ": empty" << endl;
		else
			cout << i + 1 << ": " << player.getMons(i).getName() << endl;
	}
	cout << "\n" << "press number to swap out or anything else to exit" << endl;

	char input;
	cin >> input;
	switch (input)
	{
	case '1':
		if (player.getMons(0).getName() == "debug" || player.getMons(0).getCHealth() == 0 || monNum == 0)
			return true;
		else
			monNum = 0; return false;
		break;
	case '2': 
		if (player.getMons(1).getName() == "debug" || player.getMons(1).getCHealth() == 0 || monNum == 1)
			return true;
		else
			monNum = 1; return false;
		break;
	case '3': 
		if (player.getMons(2).getName() == "debug" || player.getMons(2).getCHealth() == 0 || monNum == 2)
			return true;
		else
			monNum = 2; return false;
		break;
	case '4': 
		if (player.getMons(3).getName() == "debug" || player.getMons(3).getCHealth() == 0 || monNum == 3)
			return true;
		else
			monNum = 3; return false;
		break;
	case '5': 
		if (player.getMons(4).getName() == "debug" || player.getMons(4).getCHealth() == 0 || monNum == 4)
			return true;
		else
			monNum = 4; return false;
		break;
	case '6':
		if (player.getMons(5).getName() == "debug" || player.getMons(5).getCHealth() == 0 || monNum == 5)
			return true;
		else
			monNum = 5; return false;
		break;
	default: return true;
		break;
	}
}

void Battle::wildAttack(Dopeymon wildMon)
{
	bool valid = true;
	while (valid)
	{
		srand(unsigned int(time(NULL)));
		int num = (rand() % 4) + 1;

		switch (num)
		{
		case 1:
			if (wildMon.getMoves().attack1.getAtkName() == "debug")
				valid = true;
			else
				foeAttack = wildMon.getMoves().attack1; valid = false;
			break;
		case 2:
			if (wildMon.getMoves().attack2.getAtkName() == "debug")
				valid = true;
			else
				foeAttack = wildMon.getMoves().attack2; valid = false;
			break;
		case 3:
			if (wildMon.getMoves().attack3.getAtkName() == "debug")
				valid = true;
			else
				foeAttack = wildMon.getMoves().attack3; valid = false;
			break;
		case 4:
			if (wildMon.getMoves().attack4.getAtkName() == "debug")
				valid = true;
			else
				foeAttack = wildMon.getMoves().attack4; valid = false;
			break;
		}
	}

}

void Battle::attackEval(Dopeymon mon, Dopeymon& wildMon, Player& player)
{
	bool valid = true;
	while(valid)
	{
		if (mon.getMaxSpeed() > wildMon.getMaxSpeed())
		{
			damageEval(mon, wildMon, playerAttack);

			if (wildMon.getCHealth() == 0)
				break;

			damageEval(wildMon, mon, foeAttack);
			player.changeMonHealth(monNum, mon.getCHealth());
			
			system("CLS");
			cout << "your " << mon.getName() << " used " << playerAttack.getAtkName() << endl;
			cout << "the wild " << wildMon.getName() << " used " << foeAttack.getAtkName() << endl;
			cout << "press anything" << endl;
			char input; cin >> input;
		}
		else
		{
			damageEval(wildMon, mon, foeAttack);
			player.changeMonHealth(monNum, mon.getCHealth());

			if (mon.getCHealth() == 0)
			{
				switchMon(player);
				break;
			}
			
			damageEval(mon, wildMon, playerAttack);

		}system("CLS");
		cout << "the wild " << wildMon.getName() << " used " << foeAttack.getAtkName() << endl;
		cout << "your " << mon.getName() << " used " << playerAttack.getAtkName() << endl;
		cout << "press anything" << endl;
		char input; cin >> input;


		valid = false;
	}
	
}
//mon 1 is attacking and mon 2 is receiving damage
void Battle::damageEval(Dopeymon mon1, Dopeymon& mon2, Attack attack)
{
	int damage = (float(attack.getAtkPwr()) / 2);
	damage = (float(damage) + (float(mon1.getMaxStrength()) / 3));

	if (mon1.getType() == attack.getAtkType())
		damage = (float(damage) * 1.1);

	switch (effectiveEval(attack.getAtkType(), mon2.getType()))
	{
	case sEffective: damage = (float(damage) * 1.5);
		break;
	case nEffective: damage = (float(damage) / 1.5 );
	}

	damage = (float(damage) - (float(mon2.getMaxDefense()) / 4));

	if (damage <= 0)
		damage = 1;
	mon2.changeCHealth((mon2.getCHealth() - damage));

	if (mon2.getCHealth() <= 0)
		mon2.changeCHealth(0);


}

effectiveness Battle::effectiveEval(type type1, type type2)
{
	switch (type1)
	{
	case neutral:
		switch (type2)
		{
		case neutral: return Effective;
			break;
		case fire: return Effective;
			break;
		case water: return Effective;
			break;
		case earth: return Effective;
			break;
		case lightning: return Effective;
			break;
		case grass: return Effective;
			break;
		case melon: return Effective;
			break;
		case poop: return Effective;
			break;
		}
		break;
	case fire:
		switch (type2)
		{
		case neutral: return Effective;
			break;
		case fire: return Effective;
			break;
		case water: return nEffective;
			break;
		case earth: return nEffective;
			break;
		case lightning: return Effective;
			break;
		case grass: return sEffective;
			break;
		case melon: return Effective;
			break;
		case poop: return sEffective;
			break;
		}
		break;
	case water:
		switch (type2)
		{
		case neutral: return Effective;
			break;
		case fire: return sEffective;
			break;
		case water: return Effective;
			break;
		case earth: return sEffective;
			break;
		case lightning: return nEffective;
			break;
		case grass: return nEffective;
			break;
		case melon: return Effective;
			break;
		case poop: return sEffective;
			break;
		}
		break;
	case earth:
		switch (type2)
		{
		case neutral: return Effective;
			break;
		case fire: return sEffective;
			break;
		case water: return nEffective;
			break;
		case earth: return Effective;
			break;
		case lightning: return sEffective;
			break;
		case grass: return Effective;
			break;
		case melon: return Effective;
			break;
		case poop: return sEffective;
			break;
		}
		break;
	case lightning:
		switch (type2)
		{
		case neutral: return Effective;
			break;
		case fire: return Effective;
			break;
		case water: return sEffective;
			break;
		case earth: return nEffective;
			break;
		case lightning: return Effective;
			break;
		case grass: return nEffective;
			break;
		case melon: return Effective;
			break;
		case poop: return sEffective;
			break;
		}
		break;
	case grass:
		switch (type2)
		{
		case neutral: return Effective;
			break;
		case fire: return nEffective;
			break;
		case water: return sEffective;
			break;
		case earth: return sEffective;
			break;
		case lightning: return nEffective;
			break;
		case grass: return Effective;
			break;
		case melon: return nEffective;
			break;
		case poop: return sEffective;
			break;
		}
		break;
	case melon:
		switch (type2)
		{
		case neutral: return Effective;
			break;
		case fire: return Effective;
			break;
		case water: return Effective;
			break;
		case earth: return Effective;
			break;
		case lightning: return Effective;
			break;
		case grass: return Effective;
			break;
		case melon: return Effective;
			break;
		case poop: return sEffective;
			break;
		}
		break;
	case poop:
		switch (type2)
		{
		case neutral: return sEffective;
			break;
		case fire: return sEffective;
			break;
		case water: return sEffective;
			break;
		case earth: return sEffective;
			break;
		case lightning: return sEffective;
			break;
		case grass: return sEffective;
			break;
		case melon: return sEffective;
			break;
		case poop: return Effective;
			break;
		}
		break;
	}
}

//-------------------------------------------------------------------------------------------
void Battle::battleDisplay(Dopeymon playersMon, Dopeymon wildMon)
{
	system("CLS");
	cout << "wild dopeymon:" << endl;
	monDisplay(wildMon);
	cout << "\nyour dopeymon:" << endl;
	monDisplay(playersMon);
}

void Battle::monDisplay(Dopeymon mon)
{
	switch (mon.getNumber())
	{
	case 1: elechickDisplay(mon);
		break;
	case 2: lazatorDisplay(mon);
		break;
	case 3: snothDisplay(mon);
		break;
	case 4: hellipoDisplay(mon);
		break;
	case 5: keechiDisplay(mon);
		break;
	case 6: galapagoatDisplay(mon);
		break;
	case 7: melorkDisplay(mon);
		break;
	case 8: dunisaurDisplay(mon);
		break;
	case 9: guppyDisplay(mon);
		break;

	}
}
//-------------------------------------------------------------------------------------------
void Battle::elechickDisplay(Dopeymon mon)
{
	
/*
 cout << "X X X X X X X X X X X X X X X X X X X X X X X X X X X X X" << endl;
 cout << "X	                       \ \ /                          X" << endl;
 cout << "X	                ________\//                           X" << endl;
 cout << "X                /          \                           X" << endl;
 cout << "X	          ____/     __     |                          X" << endl;
 cout << "X        __/   |     /  \     |                         X" << endl;
 cout << "X	      /______|   \ \__/     |                         X" << endl;
 cout << "X         \____|    -        |                          X" << endl;
 cout << "X               \___________ \                          X" << endl;
 cout << "X                           \ \        |_               X" << endl;
 cout << "X                            \ \___      |              X" << endl;
 cout << "X                             |     ---_                X" << endl;
 cout << "X                            /          \               X" << endl;
 cout << "X                           |     |_ \   ---_           X" << endl;
 cout << "X                       |_   \      \|   ____)          X" << endl;
 cout << "X                          |   \___  ___/               X" << endl;
 cout << "X                             / /   ||                  X" << endl;
 cout << "X                             U     U                   X" << endl;
 cout << "X	                          _/     _|                   X" << endl;
 cout << "X X X X X X X X X X X X X X X X X X X X X X X X X X X X X" << endl;
 */
	cout << "---------------------------" << endl;
	cout << "elechick           lvl: " << mon.getLevel() << endl;
	cout << "     hp: "; numXs(mon); cout << endl;
	cout << "                  " << mon.getCHealth() << "/" << mon.getMaxHealth();
	cout << "\n---------------------------" << endl;

}

void Battle::lazatorDisplay(Dopeymon mon)
{
	cout << "---------------------------" << endl;
	cout << "lazator            lvl: " << mon.getLevel() << endl;
	cout << "     hp: "; numXs(mon); cout << endl;
	cout << "                  " << mon.getCHealth() << "/" << mon.getMaxHealth();
	cout << "\n---------------------------" << endl;
}

void Battle::snothDisplay(Dopeymon mon)
{
	cout << "---------------------------" << endl;
	cout << "snoth              lvl: " << mon.getLevel() << endl;
	cout << "     hp: "; numXs(mon); cout << endl;
	cout << "                  " << mon.getCHealth() << "/" << mon.getMaxHealth();
	cout << "\n---------------------------" << endl;
}

void Battle::hellipoDisplay(Dopeymon mon)
{
	cout << "---------------------------" << endl;
	cout << "hellipo            lvl: " << mon.getLevel() << endl;
	cout << "     hp: "; numXs(mon); cout << endl;
	cout << "                  " << mon.getCHealth() << "/" << mon.getMaxHealth();
	cout << "\n---------------------------" << endl;
}

void Battle::keechiDisplay(Dopeymon mon)
{
	cout << "---------------------------" << endl;
	cout << "keechi             lvl: " << mon.getLevel() << endl;
	cout << "     hp: "; numXs(mon); cout << endl;
	cout << "                  " << mon.getCHealth() << "/" << mon.getMaxHealth();
	cout << "\n---------------------------" << endl;
}

void Battle::galapagoatDisplay(Dopeymon mon)
{
	cout << "---------------------------" << endl;
	cout << "galapagoat         lvl: " << mon.getLevel() << endl;
	cout << "     hp: "; numXs(mon); cout << endl;
	cout << "                  " << mon.getCHealth() << "/" << mon.getMaxHealth();
	cout << "\n---------------------------" << endl;
}

void Battle::melorkDisplay(Dopeymon mon)
{
	cout << "---------------------------" << endl;
	cout << "melork             lvl: " << mon.getLevel() << endl;
	cout << "     hp: "; numXs(mon); cout << endl;
	cout << "                  " << mon.getCHealth() << "/" << mon.getMaxHealth();
	cout << "\n---------------------------" << endl;
}

void Battle::dunisaurDisplay(Dopeymon mon)
{
	cout << "---------------------------" << endl;
	cout << "dunisaur           lvl: " << mon.getLevel() << endl;
	cout << "     hp: "; numXs(mon); cout << endl;
	cout << "                  " << mon.getCHealth() << "/" << mon.getMaxHealth();
	cout << "\n---------------------------" << endl;
}

void Battle::guppyDisplay(Dopeymon mon)
{
	cout << "---------------------------" << endl;
	cout << "guppy              lvl: " << mon.getLevel() << endl;
	cout << "     hp: "; numXs(mon); cout << endl;
	cout << "                  " << mon.getCHealth() << "/" << mon.getMaxHealth();
	cout << "\n---------------------------" << endl;
}
//----------------------------------------------------------------------------------------
void Battle::numXs(Dopeymon mon)
{
	float oneX = (float(mon.getMaxHealth()) / 18);
	int numXs = (mon.getCHealth() / oneX);
	for (int i = 1; i <= numXs; i++)
	{
		cout << "x";
	}
}

void Battle::inputDisplayA()
{
	cout << " ______________ ______________ " << endl;
	cout << "|              |              |" << endl;
	cout << "|   1 attack   |    2 bag     |" << endl;
	cout << "|______________|______________|" << endl;
	cout << "|              |              |" << endl;
	cout << "|  3 dopeymon  |    4 flee    |" << endl;
	cout << "|______________|______________|" << endl;
}
