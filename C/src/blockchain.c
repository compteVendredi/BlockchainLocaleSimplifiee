#include "blockchain.h"

/*-----------------------------------------------------------------*/

Blockchain* blockchain_create(int difficulte){
	Blockchain *bc = malloc(sizeof(struct s_Blockchain));
	bc->nbBlock = 1;
	bc->difficulte = difficulte;
	//Bloc[0] = bloc génésis
	bc->listeBlocks[0] = bloc_create();
	bc->listeBlocks[0]->index = 0;
	bc->listeBlocks[0]->hashBlocPrecedent = NULL;
	bc->listeBlocks[0]->nonce = 0;
	ajouterTransaction(bc->listeBlocks[0]->listeTX, "Genesis", "Genesis", 1);
	return bc;
}

/*-----------------------------------------------------------------*/

void blockchain_delete(ptrBlockchain *bc){
	for(int i = 0; i < (*bc)->nbBlock; i++)
	{
		bloc_delete(&((*bc)->listeBlocks[i]));
		free((*bc)->listeBlocks[i]);
	}
	free(*bc);
}

/*-----------------------------------------------------------------*/

void ajouterBloc(Blockchain *bc, Bloc *b){
	assert(bc->nbBlock+1 < MAX_BLOC);
	bc->listeBlocks[bc->nbBlock] = b;
	bc->listeBlocks[bc->nbBlock]->index = bc->nbBlock;
	bc->nbBlock++;
}
