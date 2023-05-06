#ifndef STRUCTURE_DONNEE_H
#define STRUCTURE_DONNEE_H

#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

#define MAX_TRANSACTION 10
#define MAX_VALUE 100000000000000000

/**\file structure_donnee.h
 * \date mars 2020
 * \brief Les structures de données pour les blocs et les listes de transactions simplifiées
 */

/**
 * Définition de listeTransaction
 */

struct s_ListeTransaction{
	char** transactions;
	int nbTransaction;
};

typedef struct s_ListeTransaction ListeTransaction;


/**
 * Définition de Bloc
 */

struct s_Bloc{
	int index;//Numéro du block dans la chaîne (le génésis est numéroté zéro)
	char* timestamp;//La date au moment de la création
	char* hashBlocPrecedent;//Hash du block précédent dans la chaîne
	ListeTransaction* listeTX;
	//Pour nbTransaction voir listeTransaction
	char* hashRootMerkleTransactions;//Hash root de l’arbre de Merkle des transactions 
	char* hashBlockCourant;
	int nonce;
};

typedef struct s_Bloc Bloc;


/**
 * Définition pointeur d'un bloc
 */

typedef Bloc * ptrBloc;

/**
 * Définition pointeur d'une listeTransaction
 */

typedef ListeTransaction * ptrListeTransaction;

/** Constructeur.
 *  @return un pointeur du bloc crée.
 */

Bloc* bloc_create();

/** Destructeur.
 *  Libère les ressources allouées par le constructeur
 *  @param b l'adresse du bloc.
 *  Après l'appel *b devient null.
 */

void bloc_delete(ptrBloc *b);

/** Constructeur.
 *  @return un pointeur de la liste de transaction créée.
 */

ListeTransaction* listeTransaction_create();


/** Destructeur.
 *  Libère les ressources allouées par le constructeur.
 *  @param lt l'adresse de la liste de transactions.
 *  Après l'appel *lt devient null.
 */

void listeTransaction_delete(ptrListeTransaction *lt);

/** @param lt l'adresse de la liste de transactions.
 *  @param source le nom de la personne émettrice.
 *  @param destinataire le nom de la personne réceptrice.
 *  @param montant la somme de la transaction EN SATOSHI.
 *  @pre montant <= MAX_VALUE (10^18) et montant>=1
 */

void ajouterTransaction(ListeTransaction *lt, char* source, char* destinataire, long int montant);
																		
#endif
