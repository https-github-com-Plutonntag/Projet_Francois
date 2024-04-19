#include "Object_Hell.h"
#include "vision.h"




Object_Hell::Object_Hell()
{


}

Object_Hell::Object_Hell(std::string n, bool p, bool b, std::string d)
{
	setName(n);
	setPassive(p);
	setBonus(b);

}

Object_Hell::~Object_Hell()
{

}


		//NAME

std::string Object_Hell::getName()
{
	return Name;
}

void Object_Hell::setName(std::string n)
{
	Name = n;
}

		//PASSIVE

void Object_Hell::setPassive(bool p)
{
	if (p) {
		Passive = "Passif";
	}
	else {
		Passive =  "Actif";
	}

}

std::string Object_Hell::getPassive()
{
	return Passive;
}

		//BONUS

std::string Object_Hell::getBonus()
{
	return Bonus;
}

void Object_Hell::setBonus(bool b)
{
	if (b) {
		Bonus = "Bonus";
	}
	else {
		Bonus = "Malus";
	}
}


void Object_Hell::setDescription(std::string d)
{
	Description = d;

}

std::string Object_Hell::getUseName()
{
	return UseName;
}

void Object_Hell::setUseName(std::string u)
{
	UseName = u;
}





std::string Object_Hell::getDescription()
{
	return Description;
}






		//Type 

//
//Type Object_Hell::getType()
//{
//	return ElementType;
//}
//
//void Object_Hell::setType(Type e)
//{
//	ElementType = e;
//}
//
//std::string Object_Hell::GetTypeString()
//{
//	switch (ElementType) {
//	case Type::heal:
//		return "heal";
//	case Type::vision:
//		return "vision";
//	case Type::Truth:
//		return "Truth";
//	case Type::Backloop:
//		return "Backloop";
//	case Type::Luck:
//		return "Luck";
//	case Type::Withdraw:
//		return "Withdraw";
//	case Type::Death:
//		return "Death";
//	
//	}
//}
//
//		//DESCRIPTION
//
//std::string Object_Hell::getDes()
//{
//	return Name;
//}
//
//void Object_Hell::setDes(std::string d)
//
//{
//	Description = d;
//}
//
