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
  return villeDepart;
}

char * TrajetCompose::EnvoyerVilleArrivee() const
{
  //on récupère le dernier trajet de la collection et on affiche son arrivée
  return villeArrivee;
}


bool TrajetCompose::Ajouter(const Trajet & t)
{
  if(strcmp(t.EnvoyerVilleDepart(),villeArrivee) == 0)
  {
    #ifdef MAP
    cout << "Ajout du trajet au trajetCompose" << endl;
    #endif
    trajetsComposants.Ajouter(t);
    strcpy(villeArrivee,t.EnvoyerVilleArrivee());
    return true;
  }
    #ifdef MAP
    cout << "Pas d'ajout du trajet au trajetCompose" << endl;
    #endif
  return false;
}

void TrajetCompose::Afficher ( void ) const
// Algorithme : Une simple boucle fait alors appel à la méthode Afficher()
// de tous les objets hétérogènes de la collection (TrajetSimple ou TrajetCompose)
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
  cout <<endl;
} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
// TrajetCompose & TrajetCompose::operator = ( const TrajetCompose & unTrajetCompose )
// // Algorithme :
// //
// {
// } //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
TrajetCompose::TrajetCompose (const Trajet & t ) :
  trajetsComposants(t)
// Algorithme : La logique utilisée est la même que pour les TrajetSimple,
// ce dernier dispose simplement d'une CollectionTrajet en plus et ses attributs
// sont déterminés automatiquement
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif
  villeDepart = new char [20];
  villeArrivee = new char [20];
  strcpy(villeDepart,t.EnvoyerVilleDepart());
  strcpy(villeArrivee,t.EnvoyerVilleArrivee());

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
