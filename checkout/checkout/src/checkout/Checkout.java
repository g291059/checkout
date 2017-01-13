package checkout;

import java.util.*;

public class Checkout {
	private Queue<Item> checkoutQue;
	private Queue<PromotionRule> ruleQue;
	private DataBase db;    
	
	PromotionRule[]  rules = {new Rule1(), new Rule2()};
	
	public Checkout(DataBase db){
		// init 
		this.db = db;
		checkoutQue = new LinkedList<Item>();
		ruleQue = new LinkedList<PromotionRule>();
		for(int i = 0 ; i < rules.length ; i++){ ruleQue.add(rules[i]); }
	}
	
	public void reset(){
		checkoutQue.clear();
	}
	
	public void scan(String key){
		Item item = db.get(key);
        try {
    		Item ii = (Item) item.clone();
    		checkoutQue.add(ii);		
        }
        catch (CloneNotSupportedException e) {
            // This should never happen
        }
	}

	public double total(){
		Iterator<PromotionRule> it = ruleQue.iterator();
		while(it.hasNext()){
			it.next().rule(checkoutQue);
		}
		
		double total=0.;
		Iterator<Item> itr = checkoutQue.iterator();
		while(itr.hasNext()){
			total += itr.next().price;
		}
		return total;
	}
}
