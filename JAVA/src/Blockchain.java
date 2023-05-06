/**\file blockchain.h
 * \date mars 2020
 * \brief La structure pour le blockchain
 */

public class Blockchain {
	public static final int MAX_BLOC = 10;
	private int difficulte;//critère de difficulté pour le minage
	private int nbBlock;//nombre de blocks de la chaîne (en comptant le génésis)
	Bloc listeBlocks[];
	
	/** Constructeur de blockchain
	 * @param la difficulte du minage de bloc
	 */
	public Blockchain(int difficulte) {
		nbBlock = 1;
		this.difficulte = difficulte;
		listeBlocks = new Bloc[MAX_BLOC];
		//Bloc[0] = bloc génésis
		listeBlocks[0] = new Bloc();
		listeBlocks[0].setIndex(0);
		listeBlocks[0].setHashBlocPrecedent("");
		listeBlocks[0].setNonce(0);
		listeBlocks[0].getListeTX().ajouterTransaction("Genesis", "Genesis", 1);
	}
	
	/**
	 * Rattache un bloc à la blockchain (celui de fin)
	 * @param b le bloc
	 * A noter que l'index du bloc ajouté est modifié pour correspondre 
	 * à la blockchain
	 */
	public void ajouterBloc(Bloc b) {
		assert(nbBlock+1 < MAX_BLOC);
		listeBlocks[nbBlock] = b;
		listeBlocks[nbBlock].setIndex(nbBlock);
		nbBlock++;
	}
	
	public boolean estValide() {
		return false;
	}

	/**
	 * @return the difficulte
	 */
	public int getDifficulte() {
		return difficulte;
	}

	/**
	 * @return the listeBlocks
	 */
	public Bloc[] getListeBlocks() {
		return listeBlocks;
	}
}
