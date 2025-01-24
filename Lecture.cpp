/*************************************************************************
                    Lecture  -  Permet de lire les logs
                             -------------------
    début                : 24/01/2025
*************************************************************************/

//----- Réalisation de la classe Lecture (fichier Lecture.cpp) -----------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;

//------------------------------------------------------ Include personnel
#include "Lecture.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Xxx::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

Lecture::Lecture ( )
// Algorithme :
//  Ouvrir le fichier fileStream, attribut de la classe, à partir de
//  filePath, attribut de la classe.
{
#ifdef MAP
    cout << "Appel au constructeur de <Xxx>" << endl;
#endif
    fileStream.open(filePath);
    if (!fileStream.is_open()) {
        cerr << "Erreur lors de l'ouverture du fichier : " << filePath << endl;
    }
} //----- Fin de Xxx


Lecture::~Lecture ( )
// Algorithme :
// Fermer le fichier fileStream, attribut de la classe.
{
#ifdef MAP
    cout << "Appel au destructeur de <Xxx>" << endl;
#endif
    fileStream.close();
} //----- Fin de ~Xxx

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

