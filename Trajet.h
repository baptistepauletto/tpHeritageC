/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------------
#if ! defined ( TRAJET_H )
#define TRAJET_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
//
//
//------------------------------------------------------------------------

class Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual void Afficher () const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual char * EnvoyerVilleDepart() const;
    virtual char * EnvoyerVilleArrivee() const;
    virtual char * EnvoyerMoyenDeTransport() const;

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
  Trajet(char * vDep, char * vArr) : villeDepart(vDep), villeArrivee(vArr)
  {}
//----------------------------------------------------- Attributs protégés
   char * villeDepart;
   char * villeArrivee;

};

//-------------------------------- Autres définitions dépendantes de <Trajet>

#endif // TRAJET_H
