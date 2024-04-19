#pragma once
#include <iostream>



class Object_Hell
{
	std::string Name;
	std::string Passive;
	std::string Bonus;
	std::string Description;
	std::string UseName;


public:

	Object_Hell();
	Object_Hell(std::string n, bool p, bool b, std::string d);


	 
	~Object_Hell();


	std::string getName();
	void setName(std::string n); // Ajoute un nom

	std::string getPassive();
	void setPassive(bool p);// Ajoute un passif

	std::string getBonus();
	void setBonus(bool b);// Ajoute si un bonus ou non

	//Pour malus, si pas utiliser se transforme en Death

	std::string getDescription();
	void setDescription(std::string d);// Ajoute une description

	std::string getUseName();
	void setUseName(std::string u);// Ajoute un nom d'utilisation





};




