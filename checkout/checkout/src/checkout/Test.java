/************************************************ 
 * Developed and Executed on Eclipse IDE for Java
 */
package checkout;

import java.util.*;

public class Test {
	static String[] test1 = new String[]{"001","002","003"};
	static String[] test2 = new String[]{"001","003","001"};
	static String[] test3 = new String[]{"001","002","001","003"};
	public static void main(String[] args) {
		DataBase db  = new DataBase();
		Checkout chk = new Checkout(db);
		
		for(int i = 0 ; i < test1.length ; i++) chk.scan(test1[i]);
		double total = chk.total();
		System.out.printf("%5.2f\n",total); 
		
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		chk.reset();
		for(int i = 0 ; i < test2.length ; i++) chk.scan(test2[i]);
		total = chk.total();
		System.out.printf("%5.2f\n",total); 		
		
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		chk.reset();
		for(int i = 0 ; i < test3.length ; i++) chk.scan(test3[i]);
		total = chk.total();
		System.out.printf("%5.2f\n",total); 		
	}
}
