#include <stdio.h>
#include "blockchain.h"
#include "arbre_merkle.h"

int main()
{
	/*Code test pour voir s'il y a des fuites de mémoires*/
	Bloc *b = bloc_create();
	ajouterTransaction(b->listeTX, "AA", "YAV", 10);
	calculehashRoot(b, hashTransaction(b));

	ListeTransaction *lt = listeTransaction_create();
	ajouterTransaction(lt, "AA", "YAV", 10);
	listeTransaction_delete(&lt);

	Blockchain *bc = blockchain_create(3);
	ajouterBloc(bc, b);
	minerBloc(bc->listeBlocks[0], bc->difficulte);

	blockchain_delete(&bc);
	//bloc_delete(&b);


	fprintf(stderr, "aaaa\n");
	return 0;
}
