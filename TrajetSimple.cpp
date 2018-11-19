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
void TrajetSimple::Afficher(void)
// Algorithme :
//
{
	cout << "de" << villeDepart << "à" << villeArrivee << "en" << MoyenDeTransport << endl;
}//----- Fin de Afficher

//-------------------------------------------- Constructeurs - destructeur
TrajetSimple::TrajetSimple ( string vDepart, string vArrivee, eMoyenDeTransport mTransport)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <TrajetSimple>" << endl;
#endif
	villeDepart = vDepart;
	villeArrivee = vArrivee;
	moyenDeTransport = mTransport;
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

