package lab1;
import java.util.Scanner;
class Car{
	private String type;
	private String model;
	public Car() {
		System.out.println("Tata Motors Ltd.");
	}
	public String gettype() {
		return type;
	}
	public String getmodel() {
		return model;
	}
	public void settype(String type) {
		this.type = type;
		
	}
	public void setmodel(String model) {
        this.model = model;
		
	}
	
}
class Info extends Car{
	public Info() {
		super();
		
	}
	public void getdata() {
		String x;
		Scanner s = new Scanner(System.in);
		System.out.println("Enter Car type: 1.(SUV) 2.(SEDAN) 3.(ECONOMY) 4. (MINI)");
	    int n = s.nextInt();
	    switch(n) {
	    case 1:
	    	x = "Tata Safari";
	    	break;
	    case 2:
	    	x = "Tata Indigo";
	    	break;
	    case 3:
	    	x = "Tata Indica";
	    	break;
	    case 4:
	    	x = "Tata Nano";
	    	break;
	    default :
	    	x ="Error";
	    }
	    settype(x);
	    
		System.out.println("The model for the given type is :"+gettype());
	}
} 
public class Tatamotors {
          public static void main(String[] args) {
			Info i = new Info();
			i.getdata();
		}
}
