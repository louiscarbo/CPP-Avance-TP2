/*************************************************************************
                           Traitement  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
******************************************************************** *****/

//---------- Interface de la classe <Traitement> (fichier Traitement.h) ----------------
#if ! defined ( Traitement_H )
#define Traitement_H

//--------------------------------------------------- Interfaces utilisées

#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>

#include "Lecture.h"
#include "Statistiques.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Traitement>
//
//
//------------------------------------------------------------------------

class Traitement 

{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    void genererGraphe(unordered_map<string, unordered_map<string, int>> &graphe, Lecture &lecture, LogLine &logLine);

//------------------------------------------------- Surcharge d'opérateurs
    Traitement & operator = ( const Traitement & unTraitement );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Traitement ( const Traitement & unTraitement );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Traitement (int argc, char* argv[], string unServeurURL);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Traitement ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

    string cheminFichier; // Chemin du fichier log
    string serveurURL;
    map<string, bool> optionsBool; // Pour dotFile et exclureTypes
    map<string, int> optionsInt;   // Pour heureDep
    Statistiques* stats;
    unordered_set<string> formatsExclus;


};

//-------------------------------- Autres définitions dépendantes de <Traitement>

#endif // Traitement_H

