/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
char * TrajetSimple::EnvoyerVilleDepart() const
{
	return villeDepart;
}
char * TrajetSimple::EnvoyerVilleArrivee() const
{
	return villeArrivee;
}



void TrajetSimple::Afficher(void) const
// Algorithme :
//
{
	cout << "De " << villeDepart << " à " << villeArrivee << " en " <<
	moyenDeTransport;
}//----- Fin de Afficher

//-------------------------------------------- Constructeurs - destructeur
TrajetSimple::TrajetSimple ( char * vDepart, char * vArrivee, eMoyenDeTransport mTransport)
: 	Trajet(vDepart, vArrivee),
	moyenDeTransport(mTransport)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <TrajetSimple>" << endl;
#endif

} //----- Fin de TrajetSimple (constructeur de copie)


TrajetSimple::~TrajetSimple ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif
} //----- Fin de ~TrajetSimple


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
