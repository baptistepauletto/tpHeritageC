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
	TrajetSimple t10(villeD,villeC,Train);
	TrajetSimple t100(villeC,villeA,Velo);

	TrajetSimple t4(villeC,villeD,Train);

	t1.Afficher();
	std::cout << "t20" << '\n';
	TrajetSimple t20(villeA,villeE,Velo);
	std::cout << "catalogue1 ajout 1" << '\n';
	CollectionTrajet collection(t1,3);
	collection.Ajouter(t20);
	std::cout << "trajet composé :" << '\n';
	TrajetCompose tc1(t1);
	std::cout << "afficher de trajet composé" << '\n';
	tc1.Afficher();
	std::cout << "ajout ?" << '\n';
	tc1.Ajouter(t20);
	std::cout << "afficher de trajet composé" << '\n';
	tc1.Afficher();

	TrajetCompose tc100(t10);
	tc100.Ajouter(t100);

	TrajetCompose tc2(t4);
	tc2.Ajouter(tc1);

	tc2.Afficher();

	 Catalogue c(t1);
	 c.AjouterTrajet(tc1);
	 c.AjouterTrajet(tc2);
	 c.AjouterTrajet(t4);
	 c.AjouterTrajet(tc100);
	 c.Afficher();

	 c.rechercherParcoursSimple(villeD,villeA);

	delete [] villeD;
	delete [] villeA;
	delete [] villeC;
	delete [] villeE;
	return 0;
}
