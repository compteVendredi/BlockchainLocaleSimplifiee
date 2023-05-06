#ifndef ARBRE_MERKLE_H
#define ARBRE_MERKLE_H

/**\file arbre_merkle.h
 * \date avril 2020
 * \brief L'arbre de Merkle
 */

#include "structure_donnee.h"


/** 
 *  Tableau contenant tout les hash transactions du bloc b
 *  @param b le bloc contenant les transactions
 *  @return un tableau de hash transactions
 */
char **hashTransaction(Bloc *b);

/** 
 *  Calcule d'un hash à partir d'un tableau de hash en utilisant l'algorithme de l'abre de Merkle
 *  @param b le bloc contenant les transactions
 *  @return un tableau de hash transactions
 */
Bloc* calculehashRoot(Bloc *b, char **hashTransactions);

#endif

