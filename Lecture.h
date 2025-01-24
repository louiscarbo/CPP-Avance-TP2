/*************************************************************************
                    Lecture  -  Permet de lire les logs
                             -------------------
    début                : 24/01/2025
*************************************************************************/

//---------- Interface de la classe Lecture (fichier Lecture.h) ----------
#include <fstream>
#include <iostream>
#include <string>
#include <ctime>
#if ! defined ( LECTURE_H )
#define LECTURE_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
typedef struct {
    string ip;
    tm timeStamp;
    string url;
    int returnCode;
    int dataSize;
    string referer;
    string navigator;
} Log;

//------------------------------------------------------------------------
// Rôle de la classe Lecture
//  Permet de lire les fichiers de Log et retourne une structure
//  contenant les informations des logs
//------------------------------------------------------------------------

class Lecture
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

    Lecture ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    ~Lecture ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    ifstream fileStream;
    string filePath;
};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // LECTURE_H

