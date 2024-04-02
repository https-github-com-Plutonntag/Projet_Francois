#pragma once
#include <iostream>



class Object_Hell
{
	std::string Name;
	bool Passive;
	bool Bonus;



public:

	Object_Hell();
	Object_Hell(std::string n, bool p, bool b);


	 
	~Object_Hell();


	std::string getName();
	void setName(std::string n);

	bool getPassive();
	void setPassive(bool p);

	bool getBonus();
	void setBonus(bool b);



};



