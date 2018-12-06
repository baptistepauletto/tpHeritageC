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
#include "Trajet.h"
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
  virtual void Afficher () const;
  virtual char * EnvoyerVilleDepart() const;
  virtual char * EnvoyerVilleArrivee() const;
  char * EnvoyerMoyenDeTransport() const;

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
    TrajetSimple ( char * vDepart, char * vArrivee, char * mTransport );
    // Mode d'emploi:
    //
    // Contrat :
    // moyenDeTransport doit être un des élements suivants : {Train, Auto, Bateau, Avion, Velo}
    // Référence à l'ancienne version utilisant alors une énum pour réprésenter les moyens de transport

    virtual ~TrajetSimple ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	char * moyenDeTransport;
};

//-------------------------------- Autres définitions dépendantes de <TrajetSimple>

#endif // TRAJETSIMPLE_H
