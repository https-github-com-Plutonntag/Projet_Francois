#include "vision.h"

void vision::VisObjet()
{
	setName("Le casque d'Hades");
	setPassive(false);
	setBonus(true);
	setDescription("Ce casque permet a son activation de verifier un chemin sans y rentrer");
	setUseName("vision");

}


void vision::enterPath(int u)
{
	NextPath = u;
}

void vision::SeePath()
{
	std::cout << "---------Le prochain chemin se trouve dans la porte " << NextPath << "---------------"<<std::endl;
}

