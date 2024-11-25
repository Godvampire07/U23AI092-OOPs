package lab1;
class Invoice{
	private String number;
	private String desp;
    private int quantity;
    private double price;
    public Invoice(String number,String desp,int quantity, double price) {
    	this.number = number;
    	this.desp= desp;
    	this.price = price;
    	this.quantity = quantity;
    }
    public void setnum(String number) {
    	this.number = number;
    }
    public void setdesp(String desp) {
    	this.desp = desp;
    }
    public void setquantity(int quantity) {
    	if(quantity > 0 ) {
    		this.quantity = quantity;
    	}
    	else {
    		this.quantity = 0;
    	}
    }
    public void setprice(double price) {
    	if(price > 0 ) {
    		this.price = price;
    	}
    	else{
    		price = 0;
    	}
    }
    public String getnum() {
    	return  number;
    }
    public String getdesp() {
    	return desp;
    }
    public int getquantity() {
    	return quantity;
    }
    public double getprice() {
        return price;
    }   
    
    public double getinAmount() {
    	return quantity*price;
    }
}
public class Q2 { //Q2 is invoicetest
       public static void main(String[] args) {
		Invoice i = new Invoice("123456","ABCEFG",40,4.99);
		System.out.println("Invoice Details:");
		System.out.println("Invoice Number:"+i.getnum());
		System.out.println("Invoice Description:"+i.getdesp());
		System.out.println("Quantity:"+i.getquantity());
		System.out.println("Price per item:"+i.getprice());
		System.out.println("Total Price: $"+i.getinAmount());
	}
}
