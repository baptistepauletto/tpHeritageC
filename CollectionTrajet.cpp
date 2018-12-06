/*************************************************************************
                           CollectionTrajet  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <CollectionTrajet> (fichier CollectionTrajet.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "CollectionTrajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void CollectionTrajet::Ajouter (const Trajet & tAjouter)
// Algorithme : Verification de l'absence d'un trajet identique via
// les méthodes disponibles dans les classes enfants de Trajet
// à l'intérieur de l'ensemble des trajets puis ajout de ce dernier.
//
{
	// for(unsigned i(0); i < cardActuelle; i++ )
	// {
	// 	if (strcmp(tAjouter.EnvoyerVilleDepart(),trajets[i]->EnvoyerVilleDepart()) == 0
	// 	&& strcmp(tAjouter.EnvoyerVilleArrivee(),trajets[i]->EnvoyerVilleArrivee()) == 0)
	// 	{
	// 		return; //déjà présent !
	// 	}
	// }

	if (cardActuelle == cardMax){
		return; // C'est plein !
	}
	trajets[cardActuelle] = &tAjouter;
	++cardActuelle;
} //----- Fin de Ajouter

unsigned CollectionTrajet::EnvoyerCard () const
// Algorithme : Renvoie simplement la valeur de l'attribut CardActuelle;
{
	return cardActuelle;
} //----- Fin de EnvoyerCard

const Trajet & CollectionTrajet::EnvoyerNiemeTrajet(const unsigned numTrajet) const
// Algorithme : Renvoie simplement par référence le trajet numéro i
// après vérification de la valeur;
{
		return  *trajets[numTrajet];
}

//------------------------------------------------- Surcharge d'opérateurs
//CollectionTrajet & CollectionTrajet::operator = ( const CollectionTrajet & uneCollectionTrajet )
// Algorithme :
//
//{
//} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
CollectionTrajet::CollectionTrajet ( const CollectionTrajet & uneCollectionTrajet )
// Algorithme :
//
:	trajets (nullptr),
cardMax(uneCollectionTrajet.cardMax),
cardActuelle(uneCollectionTrajet.cardActuelle)

{
	trajets = uneCollectionTrajet.trajets;
#ifdef MAP
    cout << "Appel au constructeur de copie de <CollectionTrajet>" << endl;
#endif
} //----- Fin de CollectionTrajet (constructeur de copie)


CollectionTrajet::CollectionTrajet (Trajet & trajet, unsigned cardinaliteMaximale)
: 	trajets (nullptr),
	cardMax (cardinaliteMaximale),
	cardActuelle (1)
// Algorithme :
//
{
	trajets = new const Trajet * [cardMax];
	trajets[0] = &trajet;
#ifdef MAP
    cout << "Appel au constructeur de <CollectionTrajet>" << endl;
#endif
} //----- Fin de CollectionTrajet


CollectionTrajet::~CollectionTrajet ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <CollectionTrajet>" << endl;
		cout << "		|card max était :" << cardMax << endl;
		cout << "		|card actuelle était :" << cardActuelle << endl;

#endif
	delete [] trajets;

} //----- Fin de ~CollectionTrajet


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
