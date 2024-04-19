#include "Death.h"

void Death::ObjDeath()
{
	setName("Plan C");
	setPassive(true);
	setBonus(false);
	setDescription(" A utilisé en dernier recours");
	setUseName("death");
	TimeDeath();


}

void Death::TimeDeath()
{
	RetryDeath = 3;
}

void Death::cooldownDeath()
{
	RetryDeath--;
}

int Death::getDeath()
{
	return RetryDeath;
}
