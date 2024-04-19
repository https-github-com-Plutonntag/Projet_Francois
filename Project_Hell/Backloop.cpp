#include "Backloop.h"

void Backloop::ObjBackLoop()
{
	setName("Montre de Dante");
	setBonus(true);
	setPassive(false);
	setDescription("Cette montre permet de remonter a la dernière salle si l'utilisateur meurt");
	setUseName("backloop");
}

void Backloop::setBackLoop(int b)
{
	RetourArriere = b;
}

void Backloop::setUseBackloop(bool v)
{
	UseBackloop = v;
}

bool Backloop::getUseBackloop()
{
	return UseBackloop;
}

int Backloop::BackLoop()
{
	return RetourArriere;
}


