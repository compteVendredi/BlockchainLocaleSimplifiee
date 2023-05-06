#include "fonction_de_calcul.h"
#include "sha256.h"
#include "sha256_utils.h"
#include "arbre_merkle.h"
#include "structure_donnee.h"


//Retourne i qui est le nombre de '0' du début à i d'un hash
int nbZeroHashDebut(char *hashRoot){
	int i;
	for(i = 0; hashRoot[i] != '\0'; i++)
	{
		if(hashRoot[i] != '0')
			return i;
	}
	return i;
}

//Retourne le hash d'un bloc
char* calculerHashBloc(Bloc *b){
	char* tempo = NULL;//Faut faire un malloc avec la taille de timestamp + hashBloc + root
	char* hash = malloc(sizeof(char)*(SHA256_BLOCK_SIZE + 1));
	//On concatène tout 
	strcpy(tempo,b->timestamp);
	strcat(tempo,b->hashBlocPrecedent);
	strcat(tempo,b->hashRootMerkleTransactions);
	//Puis on calcul l'hash
	sha256ofString((BYTE *)hash,tempo);
	free(tempo);

	return hash;
}

//Mine un bloc en respectant sa difficulté
void minerBloc(Bloc *b, int difficulte){
	b->hashBlockCourant = calculerHashBloc(b);
	while(nbZeroHashDebut(b->hashBlockCourant) < difficulte)
	{
		(b->nonce)++;
		b->hashBlockCourant = calculerHashBloc(b);
	}
}

//0 = invalide 1 = valide
int estValide(Blockchain *bc){

	//1 on vérifie le block genesis
	if(bc->listeBlocks[0]->index != 0)
		return 0;
	char* tempo = calculerHashBloc(bc->listeBlocks[0]);
	if(nbZeroHashDebut(bc->listeBlocks[0]->hashBlockCourant) != bc->difficulte
	|| !strcmp(tempo, bc->listeBlocks[0]->hashBlockCourant))
	{
		free(tempo);
		return 0;
	}
	free(tempo);

	//2 on vérifie la validité de chaque merkle hash root des blocs qui composent la blockchain
	for(int i = 1; i < bc->nbBlock; i++)
	{
		Bloc* tempo = bloc_create();	
		calculehashRoot(tempo, hashTransaction(tempo));
		if(!strcmp(tempo->hashRootMerkleTransactions, bc->listeBlocks[i]->hashRootMerkleTransactions))
		{
			bloc_delete(&tempo);
			return 0;
		}
		bloc_delete(&tempo);
	}

	//3 voir pdf
	//...
	
	return 1;
}
