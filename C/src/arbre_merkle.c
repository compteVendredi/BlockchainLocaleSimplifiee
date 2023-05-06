#include "arbre_merkle.h"
#include <string.h>
#include "sha256.h"
#include "sha256_utils.h"

char **hashTransaction(Bloc *b){
	// Tableau de hash en héxadécimal
	char **hashTransactions;
	hashTransactions = malloc(sizeof(char*)*b->listeTX->nbTransaction);
	for(int i = 0; i < b->listeTX->nbTransaction; i++)
		hashTransactions[i] = malloc(sizeof(char)*(SHA256_BLOCK_SIZE*2 + 1));

	//On calcule les hash de chaque transaction
	for(int i = 0; i < b->listeTX->nbTransaction; i++)
		sha256ofString((BYTE *)b->listeTX->transactions[i],hashTransactions[i]);

	return hashTransactions;
}

//Version itérative
Bloc *calculehashRoot(Bloc *b, char **hashTransactions){
	//Calcul des hash intermédiaires et final
	char *hashRoot;
	hashRoot = malloc(sizeof(char)*(SHA256_BLOCK_SIZE*2 + 1));
	int diviseur = 1;
	while(b->listeTX->nbTransaction/diviseur >= 2){
		int nonPair = (b->listeTX->nbTransaction)%diviseur;
		//On calcule les hash deux par deux
		for(int i = 0; i < (b->listeTX->nbTransaction)-nonPair; i+=diviseur*2){
			hashTransactions[i] = strcat(hashTransactions[i], hashTransactions[i+diviseur]);
			sha256ofString((BYTE *)b->listeTX->transactions[i],hashTransactions[i]);
		}
		//Si impair on fait remonter (sauf que c'est le cas seulement pour le tout premier niveau
		if(nonPair){
			hashTransactions[0] = strcat(hashTransactions[(b->listeTX->nbTransaction)-2], hashTransactions[(b->listeTX->nbTransaction)-1]);
			sha256ofString((BYTE *)b->listeTX->transactions[(b->listeTX->nbTransaction)-2],hashTransactions[(b->listeTX->nbTransaction)-2]);
		}
		diviseur*=2;
	}
	//On RECOPIE la hash final hashTransactions[0] dans le bloc
	b->hashRootMerkleTransactions = malloc(sizeof(char)*(SHA256_BLOCK_SIZE*2 + 1));
	strcpy(hashRoot, b->hashRootMerkleTransactions);

	return b;
}

