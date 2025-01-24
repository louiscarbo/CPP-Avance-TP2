/*************************************************************************
                    Lecture  -  Permet de lire les logs
                             -------------------
    début                : 24/01/2025
*************************************************************************/

//----- Réalisation de la classe Lecture (fichier Lecture.cpp) -----------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <sstream>
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Lecture.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

bool Lecture::getLog(LogLine &logLine)
// Algorithme :
//  Lire une ligne du fichier fileStream, attribut de la classe.
//  Si la lecture est un succès, retourner true et remplir la structure
//  logLine avec les informations lues.
{
    string line;
    if (getline(fileStream, line)) {
        istringstream iss(line);
        string ip, timeStampStr, request, returnCode, dataSize, source, navigator;
        char discard;

        // Lire l'adresse IP
        iss >> ip;
        logLine.ip = ip;

        // Ignorer les deux tirets
        iss >> discard >> discard;

        // Lire le timestamp entre crochets
        iss >> discard; // '['
        getline(iss, timeStampStr, ']');
        struct tm timeStamp;
        strptime(timeStampStr.c_str(), "%d/%b/%Y:%H:%M:%S", &timeStamp);
        logLine.timeStamp = timeStamp;

        // Lire la requête entre guillemets
        iss >> discard; // '"'
        getline(iss, request, '"');
        logLine.url = request;

        // Lire le code de retour et la taille des données
        iss >> returnCode >> dataSize;
        logLine.returnCode = stoi(returnCode);
        logLine.dataSize = stoi(dataSize);

        // Lire la source entre guillemets
        iss >> discard; // '"'
        getline(iss, source, '"');
        logLine.source = source;

        // Lire le navigateur entre guillemets
        iss >> discard; // '"'
        getline(iss, navigator, '"');
        logLine.navigator = navigator;

        return true;
    } else {
        return false;
    }
}

// type Lecture::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

Lecture::Lecture (string filePath)
// Algorithme :
//  Ouvrir le fichier fileStream, attribut de la classe, à partir de
//  filePath, attribut de la classe.
{
#ifdef MAP
    cout << "Appel au constructeur de <Lecture>" << endl;
#endif
    fileStream.open(filePath);
    if (!fileStream.is_open()) {
        cerr << "Erreur lors de l'ouverture du fichier : " << filePath << endl;
    }
} //----- Fin de Lecture


Lecture::~Lecture ( )
// Algorithme :
// Fermer le fichier fileStream, attribut de la classe.
{
#ifdef MAP
    cout << "Appel au destructeur de <Lecture>" << endl;
#endif
    fileStream.close();
} //----- Fin de ~Lecture

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

