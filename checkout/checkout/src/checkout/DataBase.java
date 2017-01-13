package checkout;

import java.util.Hashtable;

public class DataBase {
	private Hashtable<String,Item> db = new Hashtable<String,Item>();
	public DataBase(){
		db.put("001", new Item("Chocolate Cake", 9.25));
		db.put("002", new Item("Whisky", 45.00));
		db.put("003", new Item("T-shirt", 19.95));
	}
	Item get(String key){ return db.get(key);}
}
