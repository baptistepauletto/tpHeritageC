/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------------
#if ! defined ( CATALOGUE_H )
#define CATALOGUE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include "CollectionTrajet.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
// La classe catalogue a pour objectif de recenser l'ensemble des  trajets
// dans l'attribut : trajetsDisponibles,
// ainsi que de proposer des parcours pour deux paramètres donnés suivants
// - villeDepart : ville de départ du voyage demandé
// - villeFin : ville où se termine le voyage
// On peut enfin ajouter des trajets ainsi qu'afficher l'état du catalogue
//------------------------------------------------------------------------

class Catalogue
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void Afficher() const;
    // Mode d'emploi : Nous affichons de manière ordonée le contenu du
    // catalogue à l'instant T, où la fonction est appellée
    // Contrat : Elle ne modifiera pas le contenu de l'instance catalogue

    void AjouterTrajet(const Trajet & t);
    // Mode d'emploi : Le trajet passé en paramètre, s'il est différent
    // de ceux déjà présents, sera ajouté au catalogue via un placement
    // au premier index libre via la méthode Ajouter de CollectionTrajet.
    // Contrat : Le trajet doit exister, bien entendu.
    //

    void rechercherParcoursSimple(const std::string & vDep,
			    const std::string & vFin) const;
    // Mode d'emploi : Nous récupérons dans la collection de trajets,
    // ceux qui possèdent une ville de départ ET une ville d'arrivée
    // égales aux paramètres, nous les affichons alors.
    // Contrat : vDep (et vFin) appartiennent à l'ensemble des villes
    // de départ (et fin, respectivement) dans le catalogue.

//-------------------------------------------- Constructeurs - destructeur
    //Catalogue ( const std::string & Catalogue );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Catalogue ( );
    // Mode d'emploi :
    // Constructeur de catalogue, ne prend pas de paramètres en entrée.
    // Contrat :
    //

    virtual ~Catalogue ( );
    // Mode d'emploi :
    // Destructeur de catalogue.
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	CollectionTrajet trajetsDisponibles;
};

//-------------------------------- Autres définitions dépendantes de <Catalogue>

#endif // CATALOGUE_H
