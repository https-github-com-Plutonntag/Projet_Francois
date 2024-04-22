#include <iostream>
#include <vector>
#include "Object_Hell.h"
#include "vision.h"
#include "Backloop.h"
#include "Death.h"
#include "Inventaire.h"
#include "Remove.h"
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#include <fstream>
#include <string>



using namespace std;


bool VerifObject(std::string u, Object_Hell object)
{
    if (u == object.getUseName())
    {
        return true;
    }
    else
    {
        return false;
    }

}

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
// Fonction qui affiche l'inventaire
void OpenInventaire(Inventaire inventaire, vision* object1, Backloop* object2) {

    inventaire.Inventory();
    while (inventaire.getOpen()) {
        // choisir l'objet a utiliser
        std::string choix;
        std::cout << " Choisie quel objet tu veux utiliser : \"X\" pour fermer l'inventaire : ";
        std::cin >> choix;
        
        if (VerifObject(choix, *object1)) // Véfifie si le mot marqué est bien celui de la vision
        {
            inventaire.SuppObject(object1);
            cout << endl;
            object1->SeePath();
            cout << endl;
            inventaire.Inventory();


        }
        else if (VerifObject(choix, *object2)) { // Véfifie si le mot marqué est bien celui de la backloop

            inventaire.SuppObject(object2);
            object2->setUseBackloop(false);
            inventaire.Inventory();
        }
        else if (choix == "X" && inventaire.getOpen() == true) {// Ferme l'Inventaire

            inventaire.setOpen(false);
            system("cls");
            
        }
        else {
            inventaire.setOpen(false);
            system("cls");
            cout << "Eh bah non !!! ecoute quoi !";
        }
    }
}

void initial_death(Death* object) { // initialise l'objet death et crée le cooldown

    if (object->getDeath() > 0) {

        object->cooldownDeath();
        std::cout << "Il reste " << object ->getDeath() << " Tour avant la mort";
    }
}

void initial_remove(Remove* object) { // Initialise le cooldown de l'objet Remove et appelle son effet
    object->CooldownRemove();
    if (object->getTimeRemove() == 0) {
        object->setRemove(true);
    }
}

void afficheText(string endroitFichier) {
    fstream file(endroitFichier);

    while (!file.eof()) {
        string temp;
        if (getline(file, temp)) {
            cout << temp << endl;
        }
    }
}


int main() {
    bool DeathInven = false; // rendre True quand l'objet Death et dans l'inventaire
    bool RemoveInven = false;
    std::string choix;
    vision Object_vision; // Objet Vision
    Backloop Object_Backloop; // Objet retour arrière
    Death Object_Death; // Objet Death
    Remove Object_Remove; // Objet supprime

    // Initialisation des objets
    Object_vision.VisObjet();
    Object_Backloop.ObjBackLoop();
    Object_Backloop.setUseBackloop(true);
    Object_Death.ObjDeath();
    Object_Remove.RemovObj();

    // Inventaire
    Inventaire inventaire;

    //inventaire.AddObject(Object_vision);
    //inventaire.AddObject(Object_Backloop);
    //inventaire.AddObject(Object_Death);
    //inventaire.AddObject(Object_Remove);
    //RemoveInven = true;
    //DeathInven = true;
    
    std::string rien;

    //          Affichage

    //afficheText("Name.txt"); //Francois
    //afficheText("your_hell.txt"); //welcome to your hell
    //afficheText("Accueil.txt"); //image accueil
    afficheText("texte_debut.txt"); // texte intro au jeu

    cout << "continuer <oui>";
    cin >> rien;
    system("cls"); // clear la console


    


    





    //afficheText("diable_oui.txt"); //le joueur accepte






    int difficulte;
    int ApparGobelin = 0;

    cout <<"Choisi la difficulte 1 = facile 2 = moyen 3 = difficile ): ";
    cin >> difficulte;
    // Choisir la difficulté des chemins
    int nbPortes, nbChemin, sequenceLength;
    switch (difficulte) {
    case 1:
        nbPortes = 5; nbChemin = 25; sequenceLength = 5;
        break; // Easy mode
    case 2:
        nbPortes = 10; nbChemin = 50; sequenceLength = 10;
        break; // Medium mode
    case 3:
        nbPortes = 20; nbChemin = 100; sequenceLength = 20;
        break; // Hard mode
    default:
        cout << "On a dit 1 - 2 ou 3 allez ouste!  " << endl;
        return 1;
    }

    char grid[4][100];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < nbChemin; j++) {
            grid[i][j] = ' ';
        }
    }
    // Affichage des chemins
    afficheText("Accueil.txt");
    afficheText("your_hell.txt");
    afficheText("Name.txt");
    showGrid(grid, nbPortes, nbChemin);

    // Seed the random number generator
    srand(time(0));
    int correctGuesses = 0;
    int* sequence = new int[sequenceLength];

    for (int i = 0; i < sequenceLength; ++i) {
        sequence[i] = rand() % 3 + 1;
    }

    // Boucle du jeu

    while (correctGuesses < sequenceLength) {
        cout << "Devinez la porte numero " << correctGuesses + 1 << " choisissez parmis les differents chemins (1, 2 ou 3) : ";
        int userChoice;
        // Sauvegarde le bon chemin dans l'objet Vision
        
        

        Object_vision.enterPath(sequence[correctGuesses]);
        std::string InvenOp;
        cout << " Voulez vous ouvrir l'inventaire ? \"N\": ";
        cin >> InvenOp;

        // Si appuyer sur "N", Ouvrir l'inventaire

        if (InvenOp == "N") {
            OpenInventaire(inventaire, &Object_vision, &Object_Backloop);
        }
        // Si pas utiliser, Sauvegarde la dernière porte emprunter 

        if (Object_Backloop.getUseBackloop()) {
            Object_Backloop.setBackLoop(correctGuesses);
        }
        // Si utiliser, Remez la dernière porte enregistrer
        else {
            correctGuesses = Object_Backloop.BackLoop();
            Object_Backloop.setUseBackloop(true);
            system("cls");
            showGrid(grid, nbPortes, nbChemin);
            cout << "Devinez la porte numero " << correctGuesses + 1 << " choisissez parmis les differents chemins (1, 2 ou 3) : ";

        }

        //  Si l'objet death est actif, mettre cooldown
        if (DeathInven == true) {
            initial_death(&Object_Death);
            
        }
        // Si cooldown atteint 0, recommence et supprime l'objet de l'inventaire
        if (Object_Death.getDeath() == 0) {
            cout << " La mort vient vous chercher" << endl;
            inventaire.SuppObject(&Object_Death);
            correctGuesses = 0;
            DeathInven = false;
            system("cls");
            showGrid(grid, nbPortes, nbChemin);
            cout << "Devinez la porte numero " << correctGuesses + 1 << " choisissez parmis les differents chemins (1, 2 ou 3) : ";
        }
        // Si l'objet est dans l'inventaire, commence le cooldown
        if (RemoveInven == true) {
            initial_remove(&Object_Remove);
            cout << " Il reste " << Object_Remove.getTimeRemove() << " tour avant la suppression d'un objet" << endl;;
        }
        // Si cooldown = 0; Prend une valeur aléatoire et supprime un objet de l'inventaire
        if (Object_Remove.getRemove() == true) {

            int random = rand() % inventaire.ValueObj().size();
            cout << random << " Taille tableau" << inventaire.ValueObj().size() << endl;
            inventaire.SuppObject(&inventaire.ValueObj()[random-1]);
            inventaire.SuppObject(&Object_Remove);
            RemoveInven = false;

        }

        if (ApparGobelin == 5) {
            system("cls");
            afficheText("diablotin_image.txt"); //image diablotin, ne pas separe de diablotin.txt
            afficheText("diablotin.txt"); //texte apparition diablotin
            cout << "continuer <oui>";
            cin >> rien;
            system("cls");

            if (rien == "oui") {
                afficheText("diable_oui.txt"); //le joueur accepte
                int RandomObj = rand() % 3;
                cout << RandomObj;
                switch (RandomObj) {

                case 0:
                    inventaire.AddObject(Object_vision);
                    cout << "Vous avez Obtenue \" Le casque d\'Hades \"" << endl;
                    break;
                case 1:
                    inventaire.AddObject(Object_Backloop);
                    cout << "Vous avez Obtenue \" La montre de Dante \"" << endl;
                    break;
                case 2:
                    inventaire.AddObject(Object_Death);
                    DeathInven = true;
                    cout << "Vous avez Obtenue \" Plan C \"" << endl;
                    break;
                case 3:
                    inventaire.AddObject(Object_Remove);
                    RemoveInven = true;
                    cout << "Vous avez Obtenue \" 9eme Cercle \"" << endl;
                    break;
                }

            }
            else {
                afficheText("diable_non.txt"); //le joueur refuse l'objet
            }
            
            ApparGobelin = 0;

        }



        showGrid(grid, nbPortes, nbChemin);
        cout << " Votre choix : ";
        cin >> userChoice;
       
        
        // Si Le choix es bon, continue 
        
        if (userChoice == sequence[correctGuesses]) {
            cout << "C'est vrai ! Vous avez devine la bonne porte ." << endl;
            correctGuesses++;
        }
        // Sinon, Recommence
        else {

            correctGuesses = 0;
            system("cls");
            showGrid(grid, nbPortes, nbChemin);
            cout << "Perdu ! Retour a la case depart!" << endl;
        }
        ApparGobelin++;

    }

    delete[] sequence;
    cout << "Felicitations ! Vous avez devine la bonne sequence !" << endl;
    afficheText("texte_fin.txt"); //fin du jeu

    return 0;
}