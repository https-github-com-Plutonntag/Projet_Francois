#include <iostream>
#include "Object_Hell.h"
using namespace std;

void infoObject(Object_Hell nameObj)
{
    nameObj.getName();
    nameObj.GetTypeString();
    nameObj.getPassive();

}

int main()
{
    std::cout << "Hello World!\n";

    Object_Hell d1("Potion", false, false, Type::Death, "TG");

    cout << d1.getName();

}

