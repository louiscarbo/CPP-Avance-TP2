/*************************************************************************
                           Traitement  -  Gestion des options en ligne de commande
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Traitement> (fichier Traitement.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>


//------------------------------------------------------ Include personnel
#include "Traitement.h"

using namespace std;

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques



void Traitement::genererGraphe(unordered_map<string, unordered_map<string, int>> &graphe, Lecture &lecture, LogLine &logLine)
{   
    bool finLog = false;
    while(!finLog) // gérer l'utilisation de l'autre classe, faut il une instance de "Lecture"
    {

        finLog = lecture.getLog(logLine);

        if (optionsInt["heureDep"] != -1 && logLine.timeStamp.tm_hour != optionsInt["heureDep"]) // voir la suite de la logique)
        {
            continue;
        }
        if (optionsBool["exclureTypes"] && formatsExclus.find(logLine.documentType) != formatsExclus.end()) // voir la suite de la logique
        {
            continue;
        }

        stats->remplirGraphe(logLine);

    }

    if (optionsBool["dotFile"]){ // gérer les extensions 
        // générer un fichier dot
        stats->generateDotFile(cheminFichier);


    }


}


//------------------------------------------------- Surcharge d'opérateurs



//-------------------------------------------- Constructeurs - destructeur

Traitement::Traitement(const Traitement & unTraitement)
// Algorithme : Constructeur de copie
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Traitement>" << endl;
#endif
} //----- Fin de Traitement (constructeur de copie)

Traitement::Traitement(int argc, char* argv[], string unServeurURL)
// Algorithme : Initialise les valeurs par défaut
{
#ifdef MAP
    cout << "Appel au constructeur de <Traitement>" << endl;
#endif

{
    cheminFichier = argv[1];  // Premier argument : fichier log
    stats = new Statistiques();// créer un objet statistiques
    formatsExclus = {"jpg", "jpeg", "png", "gif", "webp", "avif", "svg", "apng","js","css"};


    if (argc < 2) {
        optionsBool["dotFile"] = false;
        optionsBool["exclureTypes"] = false;
        optionsInt["heureDep"] = -1;
    }

    else {

    string arg;

    // Parcourir les options
    for (int i = 2; i < argc; i++) {
        arg = argv[i];

        // Gestion de l'option pour générer un fichier .dot
        if (arg == "-g" && i + 1 < argc) {
            optionsBool["dotFile"] = true;  // Activation de l'option
        } 

        // Gestion de l'option pour spécifier l'heure de départ
        else if (arg == "-t" && i + 1 < argc) {
            optionsInt["heureDep"] = stoi(argv[++i]);  // Conversion en entier
            if (optionsInt["heureDep"] < 0 || optionsInt["heureDep"] > 23) {
                cerr << "Erreur : L'heure doit être comprise entre 0 et 23." << endl;
                exit(1);

            }
        } 

        // Gestion de l'option pour exclure les types
        else if (arg == "-e"  && i + 1 < argc) {
            optionsBool["exclureTypes"] = true;  // Activation de l'option
        } 

        // Si l'option n'est pas reconnue
        else {
            cerr << "Option invalide : " << arg << endl;
            exit(1);
        }
    }
    }
}

} //----- Fin de Traitement



Traitement::~Traitement()
// Algorithme :
{
#ifdef MAP
    cout << "Appel au destructeur de <Traitement>" << endl;
#endif
    delete stats;
} //----- Fin de ~Traitement

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
