#ifndef Attack_H
#define Attack_H
#include<string>
using namespace std;

enum type{neutral, fire, water, grass, earth, lightning, melon, poop};
enum effect{none, burn, poison, sleep, stun, freeze};

class Attack
{
public:
	//constructor
	Attack();
	//deconstructor
	~Attack();

	virtual void specialEffect();

	//set and get functions
	void setAtkName(string atkName_) { atkName = atkName_; };
	string getAtkName() { return atkName; };

	void setAtkPwr(int atkPwr_) { atkPwr = atkPwr_; };
	int getAtkPwr() {return atkPwr; };

	void setAtkType(type atkType_) { atkType = atkType_; };
	type getAtkType() { return atkType; };

	void setAtkEffect(effect atkEffect_) { atkEffect = atkEffect_; };
	effect getAtkEffect() { return atkEffect; };

	void setEffectChance(int effectChance_) { effectChance = effectChance_; };

private:
	string atkName; //(attack name)
	int atkPwr; //(attack power)
	type atkType; //(attack type)
	effect atkEffect; //(attack efect)
	int effectChance;

};

#endif