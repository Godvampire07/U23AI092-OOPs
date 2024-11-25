package lab1;
abstract class Figure{
	protected double r,a,v;
	protected static double pi = 3.1428;
	public abstract void calcArea();
	public abstract void calcVol();
	public abstract void disArea();
	public abstract void disVol();  
}
class Cone extends Figure{
	public Cone() {}
	public Cone(double r, double a ,double v) {
		this.r = r;
		this.a = a;
		this.v = v;
	}
      private double s;
     public void calcArea(){
    	 a = (pi*r*s)+(pi*r*r);
     }
     public void disArea() {
    	 System.out.println("The area for the given cone is:"+a);
     }
     public void calcVol(){
    	 v = (pi*r*r*s)/3;
     }
     public void disVol() {
    	 System.out.println("The volume for the given cone is :"+v);
     }
}
class Sphere extends Figure{
	public Sphere(double r) {
		this.r = r;
	}
     public void calcArea(){
    	 a = (4*pi*r*r);
     }
     public void disArea() {
    	 System.out.println("The area for the given sphere is:"+a);
     }
     public void calcVol(){
    	 v = 4*(pi*r*r*r)/3;
     }
     public void disVol() {
    	 System.out.println("The volume for the given sphere is :"+v);
     }
}
class Cylinder extends Figure{
	private double h;
	public Cylinder(double r, double h ) {
		this.r = r;
		this.h = h;
	}
     public void calcArea(){
    	 a = (2*pi*r*h)+(2*pi*r*r);
     }
     public void disArea() {
    	 System.out.println("The area for the given cone is:"+a);
     }
     public void calcVol(){
    	 v = 2*(pi*r*r*h);
     }
     public void disVol() {
    	 System.out.println("The volume for the given cone is :"+v);
     }
}
public class Figures {
	public static void main(String[] args) {
          Cone c = new Cone(10,5,2);
          c.calcArea();
          c.disArea();
          c.calcVol();
          c.disVol();
          Sphere s = new Sphere(10);
          s.calcArea();
          s.disArea();
          s.calcVol();
          s.disVol();
          Cylinder r = new Cylinder(10,5);
          r.calcArea();
          r.disArea();
          r.calcVol();
          r.disVol();
	}
}

