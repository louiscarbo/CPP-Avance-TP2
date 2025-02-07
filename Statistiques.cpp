/*************************************************************************
                 Statistiques  -  Calcul des statistiques
                             -------------------
    début                : 24/01/2025
*************************************************************************/

//--- Réalisation de la classe <Statistiques> (fichier Statistiques.cpp) -

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

void Statistiques::RemplirGraphe(const LogLine &logline)
// Algorithme : insert va ajouter si le logline n'existe
// pas et il rien fait s'il existe deja
{
    NodesPonderation.insert({logline.url, 0});
    NodesPonderation[logline.url]++;
    Graphe[logline.source].insert({logline.url, 0});
    Graphe[logline.source][logline.url]++;
} //----- Fin de RemplirGraphe

void Statistiques::GenerateDotFile(string namefichier)
{
    // namefichier = namefichier + ".dot";
    ofstream fichier_w(namefichier);

    if (!fichier_w)
    {
        cerr << "Erreur d'ouverture du fichier !" << endl;
        return;
    }
    fichier_w << "digraph {" << endl;
    int i = 0;
    // Creation d'un map pour stocker les noms de noeuds
    // Ex: (noeud1,insa.fr),(noeud2,/page1.html)
    map<string, string> noeuds;
    unordered_map<string, unordered_map<string, int>>::iterator it = Graphe.begin(); // iterator

    while (it != Graphe.end())
    {
        string nom = "Node";
        // On vérifie si le nom existe deja dans le noeud
        if (noeuds.size() == 0 || noeuds.find(it->first) == noeuds.end())
        {
            noeuds.insert({it->first, nom + to_string(i)});
            fichier_w << nom + to_string(i++) << "[label=" << '"' << it->first << '"' << "];" << endl;
        }
        unordered_map<string, int>::iterator it2 = it->second.begin();
        while (it2 != it->second.end())
        {
            // Même étape qu'avant
            if (noeuds.find(it2->first) == noeuds.end())
            {
                noeuds.insert({it2->first, nom + to_string(i)});
                fichier_w << nom + to_string(i++) << "[label=" << '"' << it2->first << '"' << "];" << endl;
            }
            fichier_w << noeuds[it->first] << " -> " << noeuds[it2->first] << "[label=" << '"' << it2->second << '"' << "];" << endl;
            it2++;
        }
        it++;
    }
    fichier_w << '}' << endl;
} //----- Fin de GenerateDotFile

void Statistiques::TopDix()
{
    using Pair = pair<int, string>; // Ponderation, Clé

    // Comparateur personnalisé pour créer un min-heap
    struct Comparateur
    {
        bool operator()(const Pair &gauche, const Pair &droite) const
        {
            return gauche.first > droite.first; // Min-heap : garde les 10 plus grands éléments
        }
    };

    // Création d'une file de priorité avec un comparateur personnalisé
    priority_queue<Pair, vector<Pair>, Comparateur> minHeap;

    // Parcourir la map avec un itérateur
    map<string, int>::iterator it;
    for (it = NodesPonderation.begin(); it != NodesPonderation.end(); ++it)
    {
        minHeap.push(make_pair(it->second, it->first));
        if (minHeap.size() > 10)
            minHeap.pop(); // Supprime les sites les moins visités parmi les plus grands
    }

    // Stockage des résultats pour les afficher dans l'ordre décroissant
    vector<Pair> top;
    while (!minHeap.empty())
    {
        top.push_back(minHeap.top());
        minHeap.pop();
    }

    // Afficher les résultats en ordre décroissant
    reverse(top.begin(), top.end());

    for (vector<Pair>::iterator jt = top.begin(); jt != top.end(); ++jt)
    {
        cout << jt->second << " (" << jt->first << " hits)" << endl;
    }
} //----- Fin TopDix

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

Statistiques::Statistiques()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Statistiques>" << endl;
#endif
} //----- Fin de Statistiques

Statistiques::~Statistiques()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Statistiques>" << endl;
#endif
} //----- Fin de ~Statistiques

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
