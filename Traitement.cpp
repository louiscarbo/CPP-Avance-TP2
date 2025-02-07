/*************************************************************************
                  Traitement  -  Gestion des options en ligne de commande
                             -------------------
    début                : 31/01/2025
*************************************************************************/

//--- Réalisation de la classe <Traitement> (fichier Traitement.cpp) -----

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <stdexcept> // Pour std::invalid_argument

//------------------------------------------------------ Include personnel
#include "Traitement.h"

using namespace std;

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Traitement::construireStatistiques(void)
{
    Lecture lecture(cheminFichier, serveurURL);
    LogLine logLine;
    bool finLog = true;

    while (finLog) // gérer l'utilisation de l'autre classe, faut il une instance de "Lecture"
    {

        finLog = lecture.getLog(logLine);

        if (heureDep != -1 && logLine.timeStamp.tm_hour != heureDep) // voir la suite de la logique)
        {
            continue;
        }
        if (optionsBool["exclureTypes"] && formatsExclus.find(logLine.documentType) != formatsExclus.end()) // voir la suite de la logique
        {
            continue;
        }
        if(finLog){
        stats->remplirGraphe(logLine);}
    }

    if (optionsBool["dotFile"])
    { // gérer les extensions
        // générer un fichier dot
        stats->generateDotFile(nomFichierDot);
    }

    stats->TopDix();
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

#include <stdexcept> // Pour std::invalid_argument

Traitement::Traitement(int argc, char *argv[], string unServeurURL)
// Algorithme : Initialise les valeurs par défaut
{
#ifdef MAP
    cout << "Appel au constructeur de <Traitement>" << endl;
#endif

    if (argc < 2)
    {
        cerr << "Il n'y a pas assez d'arguments : indiquez au moins le chemin vers le fichier" << endl;
        exit(EXIT_FAILURE);
    }

    serveurURL = unServeurURL;
    cheminFichier = argv[argc - 1]; // Dernier argument : fichier log
    stats = new Statistiques(); // créer un objet statistiques
    formatsExclus = {"jpg", "jpeg", "png", "gif", "webp", "avif", "svg", "apng", "js", "css", "ico"};

    // Initialiser les options par défaut
    optionsBool["dotFile"] = false;
    optionsBool["exclureTypes"] = false;
    heureDep = -1;

    // Parcourir les arguments pour détecter les options
    for (int i = 1; i < argc - 1; ++i) {
        string arg = argv[i];
        if (arg == "-g" && i + 1 < argc - 1) {
            optionsBool["dotFile"] = true;
            nomFichierDot = argv[++i];
        } else if (arg == "-e") {
            optionsBool["exclureTypes"] = true;
        } else if (arg == "-t" && i + 1 < argc - 1) {
            try {
                heureDep = stoi(argv[++i]);
                if (heureDep < 0 || heureDep > 23) {
                    cerr << "Heure invalide pour l'option -t : " << argv[i] << endl;
                }
            } catch (const std::invalid_argument &e) {
                cerr << "Argument invalide pour l'option -t : " << argv[i] << endl;
                exit(EXIT_FAILURE);
            }
        } else {
            cerr << "Option invalide : " << arg << endl;
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

// Fonction de test pour printer les attributs
void Traitement::printAttributs()
{
    cout << "Chemin du fichier : " << cheminFichier << endl;
    cout << "URL du serveur : " << serveurURL << endl;

    cout << "Options : " << endl;
    if (optionsBool["dotFile"]) {
        cout << "  Générer un .dot : OUI" << endl;
        cout << "  Nom du fichier dot : " << nomFichierDot << endl;
    } else {
        cout << "  Générer un .dot : NON" << endl;
    }

    cout << "  Exclure types : " << (optionsBool["exclureTypes"] ? "OUI" : "NON") << endl;
    cout << "  Heure de départ : " << (heureDep != -1 ? to_string(heureDep) : "non spécifiée") << endl;
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
