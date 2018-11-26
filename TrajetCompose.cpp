/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <stdio.h>
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

string TrajetCompose::EnvoyerVilleDepart() const
{
  //on récupère le premier trajet de la collection et on affiche son départ
  Trajet premierTrajet = trajetsComposants.EnvoyerNiemeTrajet(0);
	return premierTrajet.EnvoyerVilleDepart();
}

string TrajetCompose::EnvoyerVilleArrive() const
{
  //on récupère le dernier trajet de la collection et on affiche son arrivée
  const int nbTrajets = trajetsComposants.EnvoyerCard();
  Trajet dernierTrajet = trajetsComposants.EnvoyerNiemeTrajet(nbTrajets);
  return dernierTrajet.EnvoyerVilleArrive();
}




void TrajetCompose::Afficher ( void ) const
// Algorithme :
//
{
  const int nbTrajets = trajetsDisponibles.EnvoyerCard();
  for (int i(0) ; i < nbTrajets; i++)
  {
    Trajet iemeTrajet = trajetsDisponibles.EnvoyerNiemeTrajet(i);
    iemeTrajet.Afficher()
    if(i != nbTrajets-1)
    {
      cout << " - ";
    }
  }
} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
// TrajetCompose & TrajetCompose::operator = ( const TrajetCompose & unTrajetCompose )
// // Algorithme :
// //
// {
// } //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
TrajetCompose::TrajetCompose ( const TrajetCompose & unTrajetCompose ) :
  trajetsComposant(unTrajetCompose.trajetsComposant),
  villeDepart(unTrajetCompose.villeDepart),
  villeFin(unTrajetCompose.villeFin)
// Algorithme :
//
{

#ifdef MAP
    cout << "Appel au constructeur de copie de <TrajetCompose>" << endl;
#endif
} //----- Fin de TrajetCompose (constructeur de copie)


TrajetCompose::TrajetCompose ( CollectionTrajet collection ) :
  trajetsComposant(collection),
  villeDepart(trajetsComposant.EnvoyerPremier()),
  villeFin(trajetsComposant.EnvoyerDernier())
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif
} //----- Fin de TrajetCompose


TrajetCompose::~TrajetCompose ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif
} //----- Fin de ~TrajetCompose


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
