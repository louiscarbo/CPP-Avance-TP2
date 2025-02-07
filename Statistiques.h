/*************************************************************************
                 Statistiques  -  Calcul des statistiques
                             -------------------
    début                : 24/01/2025
*************************************************************************/

//---- Interface de la classe <Statistiques> (fichier Statistiques.h) ----
#if ! defined ( STATISTIQUES_H )
#define STATISTIQUES_H
using namespace std;

//--------------------------------------------------- Interfaces utilisées
#include <map>
#include <unordered_map>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

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

    void RemplirGraphe(const LogLine& logline);
    // Mode d'emploi :
    //  Fournir un logline à ajouter au graphe

    void GenerateDotFile(string namefichier);
    // Mode d'emploi :
    //  Fournir le nom du fichier .dot à générer, génère un fichier .dot

    void TopDix();
    // Mode d'emploi :
    //  Affiche les 10 sites les plus visités

//------------------------------------------------- Surcharge d'opérateurs
//-------------------------------------------- Constructeurs - destructeur
    Statistiques ( );
    // Mode d'emploi : Appeler pour construire un objet

    virtual ~Statistiques ( );
    // Mode d'emploi : Appeler pour détruire l'objet

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    map<string,int> NodesPonderation; // Stocke le nombre de visites de chaque URL
    unordered_map<string,unordered_map<string,int>> Graphe; // Stocke les flèches entre les URLs
};

//-------------------------------- Autres définitions dépendantes de <Statistiques>

#endif // Statistiques_H

