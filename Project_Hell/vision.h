#pragma once
#include "Object_Hell.h"


class vision : public Object_Hell
{

private:
	std::string description;
	int cheminVision;
	int NextPath;

public:


	void VisObjet();// initialise l'objet
	void enterPath(int u);// Chemin a prendre
	void SeePath(); // Affiche le chemin a prendre

	

};

