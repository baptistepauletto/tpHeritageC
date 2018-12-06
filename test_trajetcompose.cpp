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
	std::cout << "t20" << '\n';
	TrajetSimple t20(villeA,villeE,Velo);
	std::cout << "catalogue1 ajout 1" << '\n';
	CollectionTrajet collection(t1,3);
	collection.Ajouter(t20);
	std::cout << "trajet composé :" << '\n';
	TrajetCompose tc1(collection);
	std::cout << "afficher de trajet composé" << '\n';
	tc1.Afficher();


	delete [] villeD;
	delete [] villeA;
	delete [] villeC;
	delete [] villeE;
	return 0;
}
