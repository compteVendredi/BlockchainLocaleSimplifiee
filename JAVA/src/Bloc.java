/**\file Bloc.java
 * \date mars 2020
 * \brief La classe pour les blocs
 */

//Pour la timestamp
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;

public class Bloc {
	private int index;//Numéro du block dans la chaîne (le génésis est numéroté zéro)
	private String timestamp;//La date au moment de la création
	private String hashBlocPrecedent;//Hash du block précédent dans la chaîne
	private ListeTransaction listeTX;
	//Pour nbTransaction voir listeTransaction
	private String hashRootMerkleTransactions;//Hash root de l’arbre de Merkle des transactions 
	private String hashBlockCourant;
	private int nonce;
	
	/** Constructeur de Bloc
	 */
	public Bloc() {
		listeTX = new ListeTransaction();
		DateFormat format = new SimpleDateFormat("yyyy/MM/dd HH:mm:ss");
		Date date = new Date();
		timestamp = format.format(date);
	}
	
	public void minerBloc() {
		//...
	}

	/**
	 * Arbre de Merkle
	 */
	//Version itérative
	public void ajouterArbreMerkle() {
		// contiendra les hashs en hexadécimal
		String[] hashRes = new String[listeTX.getnbTransaction()];
		for(int i = 0; i < listeTX.getnbTransaction(); i++)
			hashRes[i] = HashUtil.applySha256(listeTX.getTransactions()[i]);
		
		//...
	} 
	
	/**
	 * @return the index
	 */
	public int getIndex() {
		return index;
	}

	/**
	 * @param index the index to set
	 */
	public void setIndex(int index) {
		this.index = index;
	}

	/**
	 * @return the timestamp
	 */
	public String getTimestamp() {
		return timestamp;
	}

	/**
	 * @param timestamp the timestamp to set
	 */
	public void setTimestamp(String timestamp) {
		this.timestamp = timestamp;
	}

	/**
	 * @return the hashBlocPrecedent
	 */
	public String getHashBlocPrecedent() {
		return hashBlocPrecedent;
	}

	/**
	 * @param hashBlocPrecedent the hashBlocPrecedent to set
	 */
	public void setHashBlocPrecedent(String hashBlocPrecedent) {
		this.hashBlocPrecedent = hashBlocPrecedent;
	}

	/**
	 * @return the listeTX
	 */
	public ListeTransaction getListeTX() {
		return listeTX;
	}

	/**
	 * @param listeTX the listeTX to set
	 */
	public void setListeTX(ListeTransaction listeTX) {
		this.listeTX = listeTX;
	}

	/**
	 * @return the hashRootMerkleTransactions
	 */
	public String getHashRootMerkleTransactions() {
		return hashRootMerkleTransactions;
	}

	/**
	 * @param hashRootMerkleTransactions the hashRootMerkleTransactions to set
	 */
	public void setHashRootMerkleTransactions(String hashRootMerkleTransactions) {
		this.hashRootMerkleTransactions = hashRootMerkleTransactions;
	}

	/**
	 * @return the hashBlockCourant
	 */
	public String getHashBlockCourant() {
		return hashBlockCourant;
	}

	/**
	 * @param hashBlockCourant the hashBlockCourant to set
	 */
	public void setHashBlockCourant(String hashBlockCourant) {
		this.hashBlockCourant = hashBlockCourant;
	}

	/**
	 * @return the nonce
	 */
	public int getNonce() {
		return nonce;
	}

	/**
	 * @param nonce the nonce to set
	 */
	public void setNonce(int nonce) {
		this.nonce = nonce;
	}
}
