#pragma once
#include <iostream>
#include <vector>
#include "Object_Hell.h"
using namespace std;

class Inventaire
{

private:
	vector <Object_Hell> Inventaire;
	bool OpenInvent;

public:

	void Inventory(); // Affiche l'inventaire
	void AddObject(Object_Hell object); // Ajoute un objet a l'inventaire
	vector <Object_Hell> ValueObj(); // retourne l'inventaire
	void setOpen(bool o); // Modifie si l'inventaire est ouvert ou non
	bool getOpen(); // Retourne la valeur de l'inventaire ouvert ou non


	void SuppObject(Object_Hell* object); // Supprime un objet de l'inventaire


};

