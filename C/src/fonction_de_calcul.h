#ifndef FONCTION_DE_CALCUL_H
#define FONCTION_DE_CALCUL_H

/**\file arbre_merkle.h
 * \date avril 2020
 * \brief Contient les fonctions pour miner un bloc et vérifier l'intégrité
 * \d'une blockchain
 */

#include "structure_donnee.h"
#include "blockchain.h"

/** 
 *  Calcul la hash d'un bloc
 *  @param b le bloc à signer et sa difficulté
 */

void minerBloc(Bloc *b, int difficulte);

/** 
 *  Détermine si une blockchain est valide ou non
 *  @param b la blockchain à vérifier
 *  @return 1 si son integrité est correct 0 sinon
 */

int estValide(Blockchain *bc);

#endif
