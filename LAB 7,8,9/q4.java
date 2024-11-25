package lab1;
public class q4 {
    private int month;
    private int day;
    private int year;

    // Constructor to initialize the instance variables
    public q4(int month, int day, int year) {
        this.month = month;
        this.day = day;
        this.year = year;
    }

    public void setMonth(int month) {
        this.month = month;
    }

    public int getMonth() {
        return month;
    }

    public void setDay(int day) {
        this.day = day;
    }

    public int getDay() {
        return day;
    }

    // Setter and getter for year
    public void setYear(int year) {
        this.year = year;
    }

    public int getYear() {
        return year;
    }

    public void displayDate() {
        System.out.println(month + "/" + day + "/" + year);
    }
    public static void main(String[] args) {
       
        q4 date = new q4(10, 16, 2024);

    
        System.out.print("Initial date: ");
        date.displayDate();

        date.setMonth(12);
        date.setDay(25);
        date.setYear(2023);

        System.out.print("Updated date: ");
        date.displayDate();
    }
}

