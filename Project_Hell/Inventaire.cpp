#include "Inventaire.h"
#include <vector>

void Inventaire::Inventory()
{
	setOpen(true);
	std::cout << " INVENTAIRE" << endl << endl;
	for (Object_Hell object : Inventaire) {
		std::cout << "--------------------------" << endl;
		std::cout << object.getName() << endl;
		std::cout << object.getPassive() << endl;
		std::cout << object.getBonus() << endl;
		std::cout << object.getDescription() << endl << endl;
		if (object.getPassive() == "Actif")
		{
			std::cout << " Pour utiliser l'Objet, ecrire \"" << object.getUseName() << "\"" <<  endl << endl;

		}
		std::cout << "--------------------------" << endl;
	}
	
}

void Inventaire::AddObject(Object_Hell object)
{
	Inventaire.push_back(object);
	
}

vector <Object_Hell> Inventaire::ValueObj()
{
	return Inventaire;
}

void Inventaire::setOpen(bool o)
{
	OpenInvent = o;
}

bool Inventaire::getOpen()
{
	return OpenInvent;
}


void Inventaire::SuppObject(Object_Hell* object) // Fonction which remove the object from the bag
{	
	int i = 0;
	while (i <= Inventaire.size()) {
		if (object->getUseName() == Inventaire[i].getUseName()) {
			Inventaire.erase(Inventaire.begin() + i);
			break;
		}
		else {

			i++;
		}
	}

}