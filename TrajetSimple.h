/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h) ----------------
#if ! defined ( TRAJETSIMPLE_H )
#define TRAJETSIMPLE_H

//--------------------------------------------------- Interfaces utilisées
#include Trajet.h
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
enum eMoyenDeTransport {Train, Auto, Bateau, Avion, Velo};
//------------------------------------------------------------------------
// Rôle de la classe <TrajetSimple>
//	Définir	un trajet par sa ville de départ, sa ville d'arrivée et son moyen de transport
//
//------------------------------------------------------------------------

class TrajetSimple : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    //TrajetSimple & operator = ( const TrajetSimple & unXxx );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    TrajetSimple ( String villeDepart, String villeArrivee, eMoyenDeTransport moyenDeTransport );
    // Mode d'emploi (constructeur de copie) :
    // 
    // Contrat :
    // moyenDeTransport doit être un des élements suivants : {Train, Auto, Bateau, Avion, Velo}

    virtual ~TrajetSimple ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	eMoyenDeTransport moyenDeTransport;
};

//-------------------------------- Autres définitions dépendantes de <TrajetSimple>

#endif // TRAJETSIMPLE_H

