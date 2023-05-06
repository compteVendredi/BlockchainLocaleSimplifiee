/**\file Bloc.java
 * \date mars 2020
 */
public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		/*Code test pour voir si ça plante*/
		Bloc b = new Bloc();
		b.getListeTX().ajouterTransaction("AA", "YAV", 10);

		ListeTransaction lt = new ListeTransaction();
		lt.ajouterTransaction("AA", "YAV", 10);

		Blockchain bc = new Blockchain(3);
		bc.ajouterBloc(b);

		System.out.println("aaa");
	}

}
