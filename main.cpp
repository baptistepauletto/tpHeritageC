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
	strcpy(moyenDeTransportInit,"TGV");
	
	TrajetSimple trajetInit(villeDepartInit,villeArriveeInit,moyenDeTransportInit);
	Catalogue catalogue(trajetInit);
	cout << "Bienvenue dans notre mini application de gestion de trajet ! \r\n"
	     << "Si vous souhaitez consulter la liste des commandes, tapez help." << endl;
	char * action = new char[50];
	TrajetSimple * trajetsSimples[50];
	const TrajetSimple * trajetsSimplesComposants[50];
	TrajetCompose * trajetsComposes[50];
	unsigned cptTrajetsSimples = 0;
	unsigned cptTrajetsComposes = 0;
	unsigned cptTrajetsSimplesComposants = 0;
	//TrajetSimple * trajetS = nullptr;
	//TrajetCompose * trajetC = nullptr;
	cin >> action;	
	while(strcmp(action,"quit") != 0){
		if(strcmp(action,"insert") == 0){
			cout<<"rentré insert" << endl;
			cin >> action;
			if(strcmp(action,"TS") == 0){
				cin >> action;
				strcpy(villeDepartInit,action);
				cin >> action;
				strcpy(villeArriveeInit,action);
				cin >> action;
				strcpy(moyenDeTransportInit,action);
				trajetsSimples[cptTrajetsSimples] = new TrajetSimple(villeDepartInit,villeArriveeInit,moyenDeTransportInit);
				catalogue.AjouterTrajet(*trajetsSimples[cptTrajetsSimples]);
				cptTrajetsSimples++;
			}
			if(strcmp(action,"TC") == 0){
				cout << "rentré TC"<<endl;
				unsigned cptTrajet = 0;
				cin >> cptTrajet;
				for(unsigned i (0); i < cptTrajet; i++){	
					cin >> action;
					strcpy(villeDepartInit,action);
					cin >> action;
					strcpy(villeArriveeInit,action);
					cin >> action;
					strcpy(moyenDeTransportInit,action);
					trajetsSimplesComposants[cptTrajetsSimplesComposants] = new TrajetSimple(villeDepartInit,villeArriveeInit,moyenDeTransportInit);
					if(i==0){
						trajetsComposes[cptTrajetsComposes] = new TrajetCompose(*trajetsSimplesComposants[cptTrajetsSimplesComposants]);
					} else {
						trajetsComposes[cptTrajetsComposes]->Ajouter(*trajetsSimplesComposants[cptTrajetsSimplesComposants]);
					}
					cptTrajetsSimplesComposants++;
				}
				catalogue.AjouterTrajet(*trajetsComposes[cptTrajetsComposes]);
				cptTrajetsComposes++;
			}
		}
		if(strcmp(action,"afficher") == 0){
			catalogue.Afficher();
		}
		if(strcmp(action,"recherche") == 0){
			cin >> action;
			if(strcmp(action,"V1") == 0){
				cin >> action;
				strcpy(villeDepartInit,action);
				cin >> action;
				strcpy(villeArriveeInit,action);
				catalogue.RechercherParcoursSimple(villeDepartInit,villeArriveeInit);
			}
		}
		if(strcmp(action,"help") == 0){
			cout << "Les commandes disponibles sont : \r\n"
			     << "Ajouter un trajet simple : insert TS <villeDepart> <villeArrivee> <moyenDeTransport> \r\n"
			     << "Ajouter un trajet composé : insert TC <n> [<villeDepart> <villeArrivee> <moyenDeTransport>] avec [] n>0 fois \r\n"
			     << "Afficher l'état actuel du catalogue : afficher \r\n"
			     << "Effectuer l'algorithme de recherche d'un trajet V1 : recherche V1 <villeDepart> <villeArrivee> \r\n"
			     << "Effectuer l'algorithme de recherche d'un trajet V2 : recherche V2 <villeDepart> <villeArrivee> \r\n"
			     << "--Fin de la liste des commandes disponibles-- \r\n";
		}
		cin >> action;
	}
	
	delete [] action;
	for(unsigned i(0); i<cptTrajetsSimples;i++){
		delete trajetsSimples[i];
	}
	for(unsigned i(0); i<cptTrajetsSimplesComposants;i++){
		delete trajetsSimplesComposants[i];
	}
	for(unsigned i(0); i<cptTrajetsComposes;i++){
		delete trajetsComposes[i];
	}
	delete [] villeDepartInit;	
	delete [] villeArriveeInit;	
	delete [] moyenDeTransportInit;	

	return 0;
}
