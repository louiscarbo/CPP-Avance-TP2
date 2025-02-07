#include "Traitement.h"

#include <string>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    // Demander à l'utilisateur l'URL du serveur à analyser
    string serverURL;
    cout << "Entrez l'URL du serveur à analyser (de http à .extension) : ";
    getline(cin, serverURL);

    // Créer un objet Traitement avec les arguments de la ligne de commande et l'URL du serveur
    Traitement traitement(argc, argv, serverURL);

    // Effectuer le traitement
    // Par exemple, générer le graphe
    traitement.construireStatistiques();

    return 0;
}