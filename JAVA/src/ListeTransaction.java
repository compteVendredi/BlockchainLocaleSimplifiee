/**\file ListeTransaction.java
 * \date mars 2020
 * \brief La classe pour les listes de transactions simplifiées
 */

public class ListeTransaction {
	public static final int MAX_VALUE = 17;//10^max_value
	public static final int MAX_TRANSACTION = 10;
	private String transactions[];
	private int nbTransaction = 0;
	
	/** Constructeur de listeTransaction
	 */
	public ListeTransaction() {
		transactions = new String[MAX_TRANSACTION];
	}
	
	/** @param lt l'adresse de la liste de transactions.
	 *  @param source le nom de la personne émettrice.
	 *  @param destinataire le nom de la personne réceptrice.
	 *  @param montant la somme de la transaction EN SATOSHI.
	 *  @pre montant <= MAX_VALUE (10^18) et montant>=1
	 */
	public void ajouterTransaction(String source, String destinataire, long montant) {
		assert(montant <= Math.pow(10,MAX_VALUE) && montant >= 1);
		transactions[nbTransaction] = "Source user" + source + "-Destination"
			+ destinataire + " " + montant;
		nbTransaction++;
	}
	
	/**
	 * 
	 * @return transactions
	 */
	public String[] getTransactions() {
		return transactions;
	}
	
	public int getnbTransaction() {
		return nbTransaction;
	}
	
}
