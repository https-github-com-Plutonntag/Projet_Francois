#pragma once
#include "Object_Hell.h"
class Death : public Object_Hell
{

private:

	int RetryDeath;

public:

	void ObjDeath();// Initialise l'objet 
	void TimeDeath(); // Nombre de tour avant l'activation de l'objet
	void cooldownDeath(); // Active le cooldown
	int getDeath(); // Active la fonction mort


};

