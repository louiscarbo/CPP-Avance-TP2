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

void Statistiques::remplirGraphe(const LogLine &logline){

    NodesPonderation.insert({logline.url, 0});
    NodesPonderation[logline.url]++;
    Graphe[logline.source].insert({logline.url, 0});
    Graphe[logline.source][logline.url]++;

}

/*void Statistiques::remplirGraphe(const LogLine &logline) {
    // Ajouter la clé dans NodesPonderation si elle n'existe pas
    if (NodesPonderation.find(logline.url) == NodesPonderation.end()) {
        NodesPonderation[logline.url] = 0;
    }
    NodesPonderation[logline.url]++;

    // Ajouter la clé dans Graphe si elle n'existe pas
    if (Graphe.find(logline.source) == Graphe.end()) {
        Graphe[logline.source] = unordered_map<string, int>();
    }
    
    // Ajouter la clé logline.url dans Graphe[logline.source] si elle n'existe pas
    if (Graphe[logline.source].find(logline.url) == Graphe[logline.source].end()) {
        Graphe[logline.source][logline.url] = 0;
    }
    Graphe[logline.source][logline.url]++;
}*/
    void Statistiques::TopDix()
    {
        vector<string> top;
        map<string, int>::iterator it = NodesPonderation.begin(); //creation d'un iterateur

        // Iterate through the map and print the elements
        while (it != NodesPonderation.end()) {
            if (top.size()==0)
            {
                top.push_back(it->first);
            }
            else
            {
                int i=0,insert=0;
                while (i<=top.size() && insert==0) 
                {
                    if (it->second < NodesPonderation[top[i]] && i!=top.size())
                    {
                        i++;
                    }
                    else
                    {
                        top.insert(top.begin()+i,it->first);
                        insert=1;
                    }  
                }
            }
            ++it;
        }
        for (int j=0;j<10;j++)
        {
            cout<<"nombre d'acces"<<top[j]<<"est"<<NodesPonderation[top[j]]<<endl;
        }

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

