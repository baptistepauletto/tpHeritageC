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
	
	char * action = new char[50];
	cin >> action;	
	while(strcmp(action,"quit") != 0){
		if(strcmp(action,"insert") == 0){
			cout<<"rentré insert" << endl;
			cin >> action;
			if(strcmp(action,"TS") == 0){
				cout<< "rentré T" << endl;
				cin >> action;
				strcpy(villeDepartInit,action);
				cin >> action;
				strcpy(villeArriveeInit,action);
				cin >> action;
				strcpy(moyenDeTransportInit,action);
				static TrajetSimple trajetS(villeDepartInit,villeArriveeInit,moyenDeTransportInit);
				catalogue.AjouterTrajet(trajetS);
			}
			if(strcmp(action,"TC") == 0){
				cout << "rentré TS"<<endl;
			}
		}
		if(strcmp(action,"afficher") == 0){
			catalogue.Afficher();
		}
		cin >> action;
	}
	
	delete [] action;	
	delete [] villeDepartInit;	
	delete [] villeArriveeInit;	
	delete [] moyenDeTransportInit;	

	return 0;
}
