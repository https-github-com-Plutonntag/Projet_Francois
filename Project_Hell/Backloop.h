#pragma once
#include "Object_Hell.h"
class Backloop : public Object_Hell
{


private:
	
	int RetourArriere;
	bool UseBackloop;

public:

	void ObjBackLoop(); // Initialise l'objet

	void setBackLoop(int b); // Sauvegarde le booleen
	void setUseBackloop(bool v); // Sauvegarde la progression du joueur
	bool getUseBackloop(); // Si false, va activer le retour arrière
	int BackLoop(); // Active le retour arrière



};

