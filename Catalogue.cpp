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
    Trajet iemeTrajet = trajetsDisponibles.EnvoyerNiemeTrajet(i);
    cout << iemeTrajet.Afficher() << '\n';
  }
}

void Catalogue::AjouterTrajet(const Trajet & t)
{
  trajetsDisponibles.Ajouter(t);
}

void Catalogue::rechercherParcoursSimple(const std::string & vDep,
      const std::string & vFin) const{

}




//-------------------------------------------- Constructeurs - destructeur
Catalogue::Catalogue ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
  trajetsDisponibles();

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
