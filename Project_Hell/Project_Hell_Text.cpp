#include <iostream>
#include "Object_Hell.h"
using namespace std;

void infoObject(Object_Hell nameObj)
{
    cout << nameObj.getName() << endl;
    cout << nameObj.getPassive() << endl;

}

int main()
{
    std::cout << "Hello World!\n";

    Object_Hell d1("Potion", false, false, Type::Death, "TG");

    infoObject(d1);

}

