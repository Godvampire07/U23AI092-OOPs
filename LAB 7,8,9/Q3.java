package lab1;
class Employee{
	private String name;
	private String lastname;
	private double salary;
	public Employee(String name , String lastname , double salary) {
		this.lastname = lastname;
		this.name = name;
		this.salary = salary;
	}
	public void setname(String name) {
		this.name = name;
	}
	public void setlname(String lastname) {
		this.lastname = lastname;
	}
	public void setsalary(double salary) {
		if (salary <= 0) {
			salary = 0;
		}
		this.salary = salary;
	}
	public String getname() {
		return name;
	}
    public String getlname() {
    	return lastname;
    }
    public double getsalary() {
    	return salary*12;
    }
    public double hike() {
    	return salary*12 + salary*(1.2);
    }
    public void displaydata() {
    	System.out.println("Employee Detail:");
    	System.out.println("Name:"+getname());
    	System.out.println("Last Name:"+getlname());
    	System.out.println("Salary:$"+getsalary());
    	System.out.println("Salary after 10% raise:$"+hike());
    }
}

public class Q3 {
    public static void main(String[] args) {
		Employee e1 = new Employee("Mihir","Hajare",12000);
		Employee e2 = new Employee("Makrand","Hajare",24000);
		e1.displaydata();
		e2.displaydata();
	}
}
