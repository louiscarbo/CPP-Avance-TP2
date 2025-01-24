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
} LogLine;

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
    LogLine getLog();
    // Mode d'emploi :
    //   Retourne une structure contenant les informations du prochain log
    //   du fichier.

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

    Lecture ( );
    // Mode d'emploi :
    //  Constructeur par défaut, ouvre le fichier

    ~Lecture ( );
    // Mode d'emploi :
    //  Destructeur par défaut, ferme le fichier

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    ifstream fileStream;
    string filePath;
};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // LECTURE_H

