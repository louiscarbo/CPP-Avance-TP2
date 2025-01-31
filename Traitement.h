/*************************************************************************
                  Traitement  -  Gestion des options en ligne de commande
                             -------------------
    début                : 31/01/2025
*************************************************************************/


//----- Interface de la classe <Traitement> (fichier Traitement.h) -------
#if !defined(Traitement_H)
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
//  Permet de gérer les options en ligne de commande et de générer le
//  graphe des pages web visitées.
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

    void construireStatistiques();

    void printAttributs();

    //------------------------------------------------- Surcharge d'opérateurs
    Traitement &operator=(const Traitement &unTraitement);
    // Mode d'emploi :
    //
    // Contrat :
    //

    //-------------------------------------------- Constructeurs - destructeur
    Traitement(const Traitement &unTraitement);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Traitement(int argc, char *argv[], string unServeurURL);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Traitement();
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
    string nomFichierDot; // Pour dotFile
    map<string, bool> optionsBool; // Pour dotFile et exclureTypes
    int heureDep;   // Pour heureDep
    Statistiques *stats;
    unordered_set<string> formatsExclus;
};

//-------------------------------- Autres définitions dépendantes de <Traitement>

#endif // Traitement_H
