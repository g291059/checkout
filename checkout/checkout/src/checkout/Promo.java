package checkout;

import java.util.Iterator;
import java.util.Queue;

interface PromotionRule {	public void rule(Queue<Item> queue);}

class Rule1 implements PromotionRule{
	public void rule(Queue<Item> queue){
		int num = 0;
		Iterator<Item> it = queue.iterator();
		while(it.hasNext()){
			if(it.next().name.equalsIgnoreCase("Chocolate cake")) num++;				
		}
		if(num > 1){
			it = queue.iterator();
			while(it.hasNext()){
				Item item = it.next();
				if(item.name.equalsIgnoreCase("Chocolate cake")) item.price=8.50;				
			}
			
		}
	}
}

class Rule2 implements PromotionRule{
	public void rule(Queue<Item> queue){
		double total =0.;
		Iterator<Item> it = queue.iterator();
		while(it.hasNext()){
			total += it.next().price;				
		}
		if(total > 60.){
			it = queue.iterator();
			while(it.hasNext()){
				it.next().price *= 0.9;				
			}			
		}		
	}	
}

public class Promo {
	
}
