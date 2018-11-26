/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include "CollectionTrajet.h"
#include <cstring>

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Catalogue::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void Catalogue::Afficher() const
{
  const int nbTrajets = trajetsDisponibles.EnvoyerCard();
  for (int i(0) ; i < nbTrajets; i++)
  {
    cout << i+1 << "  : ";
    Trajet iemeTrajet = trajetsDisponibles.EnvoyerNiemeTrajet(i);
    iemeTrajet.Afficher();
    cout << '\n';
  }
}

void Catalogue::AjouterTrajet(const Trajet & t)
{
  trajetsDisponibles.Ajouter(t);
}

void Catalogue::rechercherParcoursSimple(const char * & vDep, const char * & vFin) const
{
    cout << "Version simple :" << endl;
    const int nbTrajets = trajetsDisponibles.EnvoyerCard();
    for (int i(0) ; i < nbTrajets; i++)
    {
      Trajet iemeTrajet = trajetsDisponibles.EnvoyerNiemeTrajet(i);
      if (strcmp(iemeTrajet.EnvoyerVilleDepart(),vDep) == 0 && strcmp(iemeTrajet.EnvoyerVilleArrivee(),vFin) == 0)
      {
        cout << i+1 << "  : ";
        iemeTrajet.Afficher();
        cout << '\n';
      }
    }
}




//-------------------------------------------- Constructeurs - destructeur
Catalogue::Catalogue ( ) : trajetsDisponibles()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif

} //----- Fin de Catalogue


Catalogue::~Catalogue ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
} //----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
