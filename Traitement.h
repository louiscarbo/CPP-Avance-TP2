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

    void construireStatistiques();
    // Mode d'emploi :
    //  Construit les statistiques à partir du fichier log et des options
    //  spécifiées.

    void printAttributs();
    // Mode d'emploi :
    //  Fonction de test qui affiche les attributs de l'objet Traitement
    //  pour déboguer.

    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - destructeur

    Traitement(int argc, char *argv[], string unServeurURL);
    // Mode d'emploi :
    //  Construit un objet Traitement à partir des arguments de la ligne de
    //  commande et de l'URL du serveur.

    virtual ~Traitement();
    // Mode d'emploi :
    //  Destructeur de la classe Traitement

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    string cheminFichier; // Chemin du fichier log
    string serveurURL; 
    string nomFichierDot;
    map<string, bool> optionsBool; // Stocker les options
    int heureDep;
    Statistiques *stats; // Objet pour les statistiques
    unordered_set<string> formatsExclus;
};

//-------------------------------- Autres définitions dépendantes de <Traitement>

#endif // Traitement_H
