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
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

char * TrajetCompose::EnvoyerVilleDepart() const
{
  //on récupère le premier trajet de la collection et on affiche son départ
  return trajetsComposants.EnvoyerNiemeTrajet(0).EnvoyerVilleDepart();
}

char * TrajetCompose::EnvoyerVilleArrivee() const
{
  //on récupère le dernier trajet de la collection et on affiche son arrivée
  return trajetsComposants.EnvoyerNiemeTrajet(trajetsComposants.EnvoyerCard()-1).EnvoyerVilleArrivee();
}




void TrajetCompose::Afficher ( void ) const
// Algorithme :
//
{
  const int nbTrajets = trajetsComposants.EnvoyerCard();
  for (int i(0) ; i < nbTrajets; i++)
  {
    #ifdef MAP
        cout << "affichage du "<< i<< "eme trajet" << endl;
    #endif
    const Trajet& iemeTrajet = trajetsComposants.EnvoyerNiemeTrajet(i);
    iemeTrajet.Afficher();
    if(i != nbTrajets-1)
    {
      cout << " - ";
    }
  }
  cout <<endl;
} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
// TrajetCompose & TrajetCompose::operator = ( const TrajetCompose & unTrajetCompose )
// // Algorithme :
// //
// {
// } //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
TrajetCompose::TrajetCompose ( CollectionTrajet collection ) :
  trajetsComposants(collection)
// Algorithme :
//
{

#ifdef MAP
    cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif
  villeDepart = new char [20];
  villeArrivee = new char [20];
  strcpy(villeDepart,collection.EnvoyerNiemeTrajet(0).EnvoyerVilleDepart());
  strcpy(villeArrivee,collection.EnvoyerNiemeTrajet(collection.EnvoyerCard()-1).EnvoyerVilleArrivee());

} //----- Fin de TrajetCompose


TrajetCompose::~TrajetCompose ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif
  delete [] villeDepart;
  delete [] villeArrivee;
} //----- Fin de ~TrajetCompose


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
