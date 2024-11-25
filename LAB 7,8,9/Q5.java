package lab1;

import java.util.Scanner;

public class Q5 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        double milesDriven, gallonsUsed;
        double totalMiles = 0, totalGallons = 0;
        double milesPerGallon;
        
        // Sentinel-controlled loop
        while (true) {
            System.out.print("Enter miles driven (or -1 to quit): ");
            milesDriven = input.nextDouble();

            if (milesDriven == -1) {
                break;
            }

            System.out.print("Enter gallons used: ");
            gallonsUsed = input.nextDouble();
          
            milesPerGallon = milesDriven / gallonsUsed;
            System.out.printf("Miles per gallon for this trip: %.2f\n", milesPerGallon);
            
         
            totalMiles += milesDriven;
            totalGallons += gallonsUsed;
          
            double combinedMilesPerGallon = totalMiles / totalGallons;
            System.out.printf("Combined miles per gallon for all trips: %.2f\n\n", combinedMilesPerGallon);
        }
        
        // Check if no trips were entered
        if (totalMiles == 0 && totalGallons == 0) {
            System.out.println("No data entered.");
        } else {
            System.out.printf("Final combined miles per gallon for all trips: %.2f\n", totalMiles / totalGallons);
        }
        
        input.close();  
    }
}

