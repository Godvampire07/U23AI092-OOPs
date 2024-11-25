 package lab1;
class DrivingCostCalculator {
    // Class members to store input data
    private double totalMiles;
    private double costPerGallon;
    private double averageMilesPerGallon;
    private double parkingFees;
    private double tolls;

    // Constructor to initialize the class members
    public DrivingCostCalculator(double totalMiles, double costPerGallon, double averageMilesPerGallon, double parkingFees, double tolls) {
        this.totalMiles = totalMiles;
        this.costPerGallon = costPerGallon;
        this.averageMilesPerGallon = averageMilesPerGallon;
        this.parkingFees = parkingFees;
        this.tolls = tolls;
    }

    // Method to calculate the daily driving cost
    public double calculateDailyCost() {
        double dailyGasCost = (totalMiles / averageMilesPerGallon) * costPerGallon;
        return dailyGasCost + parkingFees + tolls;
    }

    // Method to display the daily driving cost
    public void displayDailyCost() {
        double totalDailyCost = calculateDailyCost();
        System.out.printf("Your total daily driving cost is: $%.2f%n", totalDailyCost);
    }
}

public class Q1 {

       public static void main(String[] args) {
		DrivingCostCalculator calculator = new DrivingCostCalculator(12.99,3.99,3.49,1.99,4);
		calculator.calculateDailyCost();
		calculator.displayDailyCost();
	}
}
