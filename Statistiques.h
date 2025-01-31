/*************************************************************************
                           Statistiques  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
******************************************************************** *****/

//---------- Interface de la classe <Statistiques> (fichier Statistiques.h) ----------------
#if ! defined ( STATISTIQUES_H )
#define STATISTIQUES_H
using namespace std;

//--------------------------------------------------- Interfaces utilisées
#include <map>
#include <unordered_map>
#include <string>
#include <vector>

#if ! defined ( LECTURE_H )
    #include "Lecture.h"
#endif
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Statistiques>
//
//
//------------------------------------------------------------------------

class Statistiques 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    void remplirGraphe(const LogLine& logline);
    // Mode d'emploi :Incrémente le poids de la flèche entre deux URLs.
    // Si les URLs n’existent pas encore dans nodes, elles y sont ajoutées.
    //
    // Contrat :
    //


    void generateDotFile(void);
    // Mode d'emploi :Génère un fichier .dot pour GraphViz à partir du graphe.
    //
    // Contrat :
    //

    void TopDix();
    // Mode d'emploi :Affiche les 10 URLs les plus consultées.
    //
    // Contrat :
    //
    
    


//------------------------------------------------- Surcharge d'opérateurs
//-------------------------------------------- Constructeurs - destructeur
    Statistiques ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Statistiques ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    map<string,int> NodesPonderation;
    unordered_map<string,unordered_map<string,int>> Graphe;
};

//-------------------------------- Autres définitions dépendantes de <Statistiques>

#endif // Statistiques_H

