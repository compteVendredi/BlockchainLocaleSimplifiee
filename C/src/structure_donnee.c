#include "structure_donnee.h"
#include <time.h>

/*-----------------------------------------------------------------*/

char * getTimeStamp(){
	time_t ltime;
	time(&ltime);
	return ctime(&ltime);
}

/*-----------------------------------------------------------------*/

ListeTransaction* listeTransaction_create(){
	ListeTransaction *lt = malloc(sizeof(struct s_Bloc));
	lt->transactions = malloc(sizeof(char*)*MAX_TRANSACTION);
	lt->nbTransaction = 0;
	return lt;
}

/*-----------------------------------------------------------------*/

void listeTransaction_delete(ptrListeTransaction *lt){
	for(int i = 0; i < (*lt)->nbTransaction; i++)
		free((*lt)->transactions[i]);
	free((*lt)->transactions);
	free(*lt);
	*lt = NULL;
}

/*-----------------------------------------------------------------*/

void ajouterTransaction(ListeTransaction *lt, char* source, char* destinataire, long int montant){
	assert(montant<= MAX_VALUE && montant>=1);
	char cMontant[20];//Assez pour contenir les extrêmes d'un long int
	sprintf(cMontant, "%ld", montant);
	lt->transactions[lt->nbTransaction] = malloc(strlen(source)+strlen(destinataire)
	+strlen(cMontant)+50);//50 pour le texte
	sprintf(lt->transactions[lt->nbTransaction], "Source user%s-Destination : user%s %s", source, destinataire,
	cMontant);
	(lt->nbTransaction)++;
}

/*-----------------------------------------------------------------*/

Bloc* bloc_create(){
	Bloc *b = malloc(sizeof(struct s_Bloc));
	b->listeTX = listeTransaction_create();
	b->timestamp=getTimeStamp();
	b->hashBlocPrecedent=NULL;
	b->hashBlockCourant=NULL;
	b->hashRootMerkleTransactions=NULL;
	return b;
}

/*-----------------------------------------------------------------*/

void bloc_delete(ptrBloc *b){
	//free((*b)->timestamp); Pas de malloc pour le getTimeStamp
	free((*b)->hashBlocPrecedent);
	free((*b)->hashRootMerkleTransactions);
	free((*b)->hashBlockCourant);
	listeTransaction_delete(&((*b)->listeTX));
	free(*b);
	*b = NULL;
}
