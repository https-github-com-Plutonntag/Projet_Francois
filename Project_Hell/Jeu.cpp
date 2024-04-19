#include <iostream>
#include <vector>
#include "Object_Hell.h"
#include "vision.h"
#include "Backloop.h"
#include "Death.h"
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
using namespace std;

void showGrid(char grid[4][100], int nbPortes, int nbChemin) {
    for (int i = 0; i < 4; i++) {
        cout << endl << "-";
        for (int j = 0; j < nbChemin; j++) {
            cout << grid[i][j] << "-";
        }
        cout << endl;

        if (i != 3) {
            for (int j = 0; j < nbPortes; j++) {
                cout << grid[i][j] << "        |";
            }
        }
    }

    cout << ' ';
    for (int i = 0; i < nbPortes && i < 10; i++) {
        cout << "        " << i + 1 << ' ';
    }
    for (int y = 10; y < nbPortes; y++) {
        cout << "       " << y + 1 << ' ';
    }

    cout << endl;
}


void infoObject(Object_Hell nameObj)
{
    system("cls");
    cout << nameObj.getName() << endl;
    cout << nameObj.getPassive() << endl;
    cout << nameObj.getBonus() << endl;
    cout << nameObj.getDescription() << endl;
}

bool ClassVision(vision nameObj)
{
    system("cls");
    cout << nameObj.getName() << endl;
    cout << nameObj.getPassive() << endl;
    cout << nameObj.getBonus() << endl;
    cout << nameObj.getDescription() << endl;
    char UseIt;
    cout << "Voulez vous utiliser cette objet ? \'O\' ou \'N\'" << endl;
    cin >> UseIt;
    if (UseIt == 'O')
    {

        return true;

    }
    else
    {
        return false;
    }

}
bool ClassBaclLoop(Backloop nameObj)
{
    system("cls");
    cout << nameObj.getName() << endl;
    cout << nameObj.getPassive() << endl;
    cout << nameObj.getBonus() << endl;
    cout << nameObj.getDescription() << endl;
    char UseIt;
    cout << "Voulez vous utiliser cette objet ? \'O\' ou \'N\'" << endl;
    cin >> UseIt;
    if (UseIt == 'O')
    {
        nameObj.getBackLoop();
        return true;

    }
    else
    {
        return false;
    }



}

bool ClassDeath(Death nameObj)
{
    system("cls");
    cout << nameObj.getName() << endl;
    cout << nameObj.getPassive() << endl;
    cout << nameObj.getBonus() << endl;
    cout << nameObj.getDescription() << endl;
    char UseIt;
    cout << "Voulez vous utiliser cette objet ? \'O\' ou \'N\'" << endl;
    cin >> UseIt;
    if (UseIt == 'O')
    {

        return true;

    }
    else
    {
        return false;
    }

}

void ViewInventory(vision dt1, Backloop db1, Death dd1)
{
    int choix;
    system("cls");
    cout << dt1.getName() << endl;
    cout << db1.getName() << endl;
    cout << dd1.getName() << endl;
    cout << "Choisie ";
    cin >> choix;
    switch (choix)
    {
    case (1):
        if (ClassVision(dt1))
            return;

        ViewInventory(dt1, db1, dd1);
        break;
    case (2):
        if (ClassBaclLoop(db1))
            return;

        ViewInventory(dt1, db1, dd1);
        break;
    case (3):
        if (ClassDeath(dd1))
            return;
        ViewInventory(dt1, db1, dd1);
        break;
    }


}
int main() {



    vision dt1;
    Backloop db1;
    Death dd1;


    dt1.VisObjet();
    db1.ObjBackLoop();
    dd1.ObjDeath();

    //int difficulte;
    //cout << "Choisi la difficulte 1 = facile 2 = moyen 3 = difficile ): ";
    //cin >> difficulte;

    //int nbPortes, nbChemin, sequenceLength;
    //switch (difficulte) {
    //case 1:
    //    nbPortes = 5; nbChemin = 25; sequenceLength = 5;
    //    break; // Easy mode
    //case 2:
    //    nbPortes = 10; nbChemin = 50; sequenceLength = 10;
    //    break; // Medium mode
    //case 3:
    //    nbPortes = 20; nbChemin = 100; sequenceLength = 20;
    //    break; // Hard mode
    //default:
    //    cout << "On a dit 1 - 2 ou 3 allez ouste!  " << endl;
    //    return 1;
    //}

    //char grid[4][100];
    //for (int i = 0; i < 4; i++) {
    //    for (int j = 0; j < nbChemin; j++) {
    //        grid[i][j] = ' ';
    //    }
    //}

    //showGrid(grid, nbPortes, nbChemin);

    //// Seed the random number generator
    //srand(time(0));
    //int correctGuesses = 0;
    //int* sequence = new int[sequenceLength];

    //for (int i = 0; i < sequenceLength; ++i) {
    //    sequence[i] = rand() % 3 + 1;
    //}

    //while (correctGuesses < sequenceLength) {
    //    cout << "Devinez la porte numero " << correctGuesses + 1 <<" choisissez parmis les differents chemins (1, 2 ou 3) : ";
    //    int userChoice;
    //    cin >> userChoice;
    //    if (userChoice == 4)
    //    {
    //        ViewInventory(dt1, db1, dd1);
    //    }

    //    if (userChoice == sequence[correctGuesses]) {
    //        cout << "C'est vrai ! Vous avez devine la bonne porte ." << endl;
    //        correctGuesses++;
    //    }
    //    else {
    //        
    //        correctGuesses = 0;
    //        system("cls");
    //        showGrid(grid, nbPortes, nbChemin);
    //        cout << "Perdu ! Retour a la case depart!" << endl;
    //    }
    //}

    //delete[] sequence;
    //cout << "Felicitations ! Vous avez devine la bonne sequence !" << endl;

    //return 0;
}