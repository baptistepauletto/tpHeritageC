#include <cstring>
#include <stdio.h>
#include <iostream>
#include "Catalogue.h"
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"

using namespace std;

int main(){
	char * villeDepartInit = new char[20];
	char * villeArriveeInit = new char[20];
	char * moyenDeTransportInit = new char[20];
	strcpy(villeDepartInit,"Lyon");
	strcpy(villeArriveeInit,"Avignon");
	strcpy(moyenDeTransportInit,"Vélo");
	
	TrajetSimple trajetInit(villeDepartInit,villeArriveeInit,moyenDeTransportInit);
	Catalogue catalogue(trajetInit);

	delete [] villeDepartInit;	
	delete [] villeArriveeInit;	
	delete [] moyenDeTransportInit;	

	return 0;
}
