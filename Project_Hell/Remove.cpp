#include "Remove.h"

void Remove::RemovObj()
{
	setName("9eme cercle");
	setPassive(true);
	setBonus(true);
	setDescription(" Un objet qui se détruit avec un autre objet");
	setUseName("remove");
	setTimeRemove();
	setRemove();

}

void Remove::setTimeRemove()
{
	RemoveVar = 3;
}

int Remove::getTimeRemove()
{
	return RemoveVar;
}

void Remove::CooldownRemove()
{
	RemoveVar--;
}

void Remove::setRemove(bool d)
{
	RemoveSupp = d;
}

bool Remove::getRemove()
{
	return RemoveSupp;
}


