/*************************************************************************
                           Statistiques  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Statistiques> (fichier Statistiques.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
using namespace std;
//------------------------------------------------------ Include personnel
#include "Statistiques.h"
#include "Lecture.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Statistiques::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur

Statistiques::remplirGraphe(const LogLine &logline){

    NodesPonderation.insert({logline.url, 0});
    NodesPonderation[logline.url]++;

   /* if (Graphe.find(logline.source)!=Graphe.end())
            {
                NodesPonderation[log.navigator]
            }
            NodesPonderation[log.referer]=log.navigator;*/

    unordered_map<string, int> tmp;
    tmp.insert({logline.url,0});
    Graphe.insert({logline.source, tmp});
    //Graphe[logline.source].insert({logline.source, })
    Graphe[logline.source][logline.url]++;

}

Statistiques::Statistiques ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Statistiques>" << endl;
#endif
} //----- Fin de Statistiques


Statistiques::~Statistiques ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Statistiques>" << endl;
#endif
} //----- Fin de ~Statistiques


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

