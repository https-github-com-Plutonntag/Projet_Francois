#include <iostream>
#include <fstream>
#include <string>

using namespace std;

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

    int rien;

    afficheText("Name.txt"); //Francois
    afficheText("your_hell.txt"); //welcome to your hell
    afficheText("Accueil.txt"); //image accueil

    cout << "continuer <oui>";
    cin >> rien;
    system("cls"); // clear la console


    afficheText("texte_debut.txt"); // texte intro au jeu


    afficheText("texte_fin.txt"); //fin du jeu


    afficheText("diablotin_image.txt"); //image diablotin, ne pas separe de diablotin.txt
    afficheText("diablotin.txt"); //texte apparition diablotin

    cout << "continuer <oui>";
    cin >> rien;
    system("cls");

    afficheText("diable_oui.txt"); //le joueur accepte
    afficheText("diable_non.txt"); //le joueur refuse l'objet



}