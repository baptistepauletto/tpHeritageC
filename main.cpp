#include <cstring>
#include <stdio.h>
#include <iostream>
#include "Catalogue.h"
#include "CollectionTrajet.h"
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"

using namespace std;

int main(){


	char * villeD = new char[20];
	strcpy(villeD,"Sénas");
	char * villeA = new char[20];
	strcpy(villeA,"Barcelonette");
	char * villeC = new char[20];
	strcpy(villeC,"Villeurbanne");
	char * villeE = new char[20];
	strcpy(villeE,"Lyon");
	std::cout << "t1" << '\n';
	TrajetSimple t1(villeD,villeA,Velo);
	t1.Afficher();

	// std::cout << "t2" << '\n';
	// TrajetSimple t2(villeA,villeD,Velo);
	std::cout << "t20" << '\n';
	TrajetSimple t20(villeA,villeE,Velo);
	// std::cout << "t3" << '\n';
	//
	// TrajetSimple t3(villeD,villeC,Train);
	// std::cout << "t4" << '\n';
	// TrajetSimple t4(villeC,villeE,Train);
	//Init catalogue avec un trajet
	std::cout << "catalogue1" << '\n';
	Catalogue catalogue1(t1);
	//catalogue1.AjouterTrajet(t1);
	std::cout << "catalogue1 ajout 1" << '\n';

	catalogue1.AjouterTrajet(t20);

	CollectionTrajet collection(t1,2);
	collection.Ajouter(t20);
	TrajetCompose tc1(collection);
	tc1.Afficher();
	catalogue1.AjouterTrajet(tc1);
	catalogue1.Afficher();

	delete [] villeD;
	delete [] villeA;
	delete [] villeC;
	delete [] villeE;
	return 0;
}
