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
#include <cstring>
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

char * TrajetSimple::EnvoyerMoyenDeTransport() const
{
	return moyenDeTransport;
}


void TrajetSimple::Afficher(void) const
// Algorithme :
//
{
	cout << "De " << villeDepart << " à " << villeArrivee << " en " <<
	moyenDeTransport;
}//----- Fin de Afficher

//-------------------------------------------- Constructeurs - destructeur
TrajetSimple::TrajetSimple ( char * vDepart, char * vArrivee, char * mTransport)
// Algorithme :
//
{

#ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif
	villeDepart = new char [20];
	villeArrivee = new char [20];
	moyenDeTransport = new char [20];
	strcpy(villeDepart,vDepart);
	strcpy(villeArrivee,vArrivee);
	strcpy(moyenDeTransport,mTransport);


} //----- Fin de TrajetSimple (constructeur de copie)


TrajetSimple::~TrajetSimple ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif
	delete [] villeDepart;
	delete [] villeArrivee;
	delete [] moyenDeTransport;
} //----- Fin de ~TrajetSimple


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
