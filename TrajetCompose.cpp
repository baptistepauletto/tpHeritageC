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

char * TrajetCompose::EnvoyerVilleDepart() const
{
  //on récupère le premier trajet de la collection et on affiche son départ
  const Trajet& premierTrajet = trajetsComposants.EnvoyerNiemeTrajet(0);
	return premierTrajet.EnvoyerVilleDepart();
}

char * TrajetCompose::EnvoyerVilleArrivee() const
{
  //on récupère le dernier trajet de la collection et on affiche son arrivée
  const int nbTrajets = trajetsComposants.EnvoyerCard();
  const Trajet& dernierTrajet = trajetsComposants.EnvoyerNiemeTrajet(nbTrajets);
  return dernierTrajet.EnvoyerVilleArrivee();
}




void TrajetCompose::Afficher ( void ) const
// Algorithme :
//
{
  const int nbTrajets = trajetsComposants.EnvoyerCard();
  for (int i(0) ; i < nbTrajets; i++)
  {
    const Trajet& iemeTrajet = trajetsComposants.EnvoyerNiemeTrajet(i);
    iemeTrajet.Afficher();
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
TrajetCompose::TrajetCompose ( CollectionTrajet collection ) :
  Trajet(EnvoyerVilleDepart(),EnvoyerVilleArrivee()),
  trajetsComposants(collection)
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
