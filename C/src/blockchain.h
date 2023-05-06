#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#define MAX_BLOC 10

#include "structure_donnee.h"

/**\file blockchain.h
 * \date mars 2020
 * \brief La structure pour le blockchain
 */

/**
 * Définition de blockchain
 */

struct s_Blockchain{
	int difficulte;//critère de difficulté pour le minage
	int nbBlock;//nombre de blocks de la chaîne (en comptant le génésis)
	Bloc* listeBlocks[MAX_BLOC];
};

typedef struct s_Blockchain Blockchain;

/**
 * Définition pointeur d'un blockchain
 */

typedef Blockchain * ptrBlockchain;

/** Constructeur.
 *  @return un pointeur du blockchain crée.
 */

Blockchain* blockchain_create(int difficulte);

/** Destructeur.
 *  Libère les ressources allouées par le constructeur et les données ciblées (les blocs)
 *  @param bc l'adresse du bloc.
 *  Après l'appel *bc devient null.
 */

void blockchain_delete(ptrBlockchain *bc);

/**
 * Rattache un bloc à la blockchain (celui de fin)
 * @param bc l'adresse du blockchain, b le bloc
 * A noter que l'index du bloc ajouté est modifié pour correspondre à la blockchain
 */

void ajouterBloc(Blockchain *bc, Bloc *b);

#endif
