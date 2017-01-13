package checkout;

public class Item implements Cloneable {
	String name; double price;
	public Item(String name, double price){
		this.name  = name;
		this.price = price;
	}
	@Override
    protected Object clone() throws CloneNotSupportedException {
        return super.clone();
    }
/*	
	public Object clone() {
        try {
            return (Object)super.clone();
        }
        catch (CloneNotSupportedException e) {
            // This should never happen
        }
    }
*/    
}
