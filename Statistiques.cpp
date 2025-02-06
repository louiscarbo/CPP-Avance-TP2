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

    void Statistiques::remplirGraphe(const LogLine &logline)
    // Algorithme : insert va ajouter si le logline n'existe 
    // pas et il rien fait s'il existe deja
    {
        NodesPonderation.insert({logline.url, 0});
        NodesPonderation[logline.url]++;
        Graphe[logline.source].insert({logline.url, 0});
        Graphe[logline.source][logline.url]++;
    }//----- Fin de Méthode remplirGraphe

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
    void Statistiques::generateDotFile(string namefichier)
    {
        //namefichier = namefichier + ".dot";
        ofstream fichier_w(namefichier);

        if (!fichier_w) 
        {
            cerr << "Erreur d'ouverture du fichier !" << endl;
            return;
        }
        fichier_w<<"digraph {"<<endl;
        int i=0;
        //Creation d'un map pour stocker les noms de noeuds
        //Ex: (noeud1,insa.fr),(noeud2,/page1.html)
        map<string,string> noeuds;
        unordered_map<string,unordered_map<string,int>>::iterator it = Graphe.begin(); //iterator

        while (it != Graphe.end()){
            string nom="Node";
            //on voit si le nom existe deja dans le noeuds
            if(noeuds.size()==0 || noeuds.find(it->first) == noeuds.end())
            {
                noeuds.insert({it->first,nom+to_string(i)});
                fichier_w<<nom+to_string(i++)<<"[label="<<'"'<<it->first<<'"'<<"];"<<endl;
            }
            unordered_map<string,int>::iterator it2 = it->second.begin(); 
            while (it2 != it->second.end())
            {
                //meme l'etape que l'avant
                if(noeuds.find(it2->first) == noeuds.end())
                {
                    noeuds.insert({it2->first, nom+to_string(i)});
                    fichier_w<<nom+to_string(i++)<<"[label="<<'"'<<it2->first<<'"'<<"];"<<endl;
                }
                fichier_w<<noeuds[it->first]<<" -> "<<noeuds[it2->first]<<"[label="<<'"'<<it2->second<<'"'<<"];"<<endl;
                it2++;
            }
            it++;
        }
        fichier_w<<'}'<<endl;
    }//----- Fin de Méthode
    
    void Statistiques::TopDix()
{
    using Pair = pair<int, string>; // Ponderation, Clé
    priority_queue<Pair, vector<Pair>, less<Pair>> maxHeap;
    // Pair : le type de la queue,
    // vector<Pair>, contenueur
    //greater<Pair, regle pour stocker

    map<string,int>::iterator it;
    for (it = NodesPonderation.begin(); it!=NodesPonderation.end();it++)
    {
        maxHeap.push({it->second, it->first});
        if (maxHeap.size() > 10)
            maxHeap.pop(); // On enleve les site le moins visité parmi les plus grandes
    }
    
    while (!maxHeap.empty())
    {
        cout << maxHeap.top().second << " (" << maxHeap.top().first <<" hits)"<< endl;
        maxHeap.pop();
    }
}//----- Fin de Méthode


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

