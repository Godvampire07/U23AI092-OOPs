package lab1;

interface Function {
 int evaluate(int value);
}

class Half implements Function {
 @Override
 public int evaluate(int value) {
     return value / 2; // Return half the value
 }
}

public class Q13{
 
 // Method to create a new array with halved values
 public static int[] halfArray(int[] values) {
     int[] halvedValues = new int[values.length]; 
     Half half = new Half(); // Create an instance of Half

     // Loop through the original array and fill the new array with halved values
     for (int i = 0; i < values.length; i++) {
         halvedValues[i] = half.evaluate(values[i]); // Use the evaluate method
     }

     return halvedValues; // Return the new array
 }

 public static void main(String[] args) {
     // Sample input array
     int[] inputArray = {10, 20, 30, 40, 50};

     // Get the new array with halved values
     int[] resultArray = halfArray(inputArray);

     // Print the original and the new array
     System.out.println("Original Array:");
     for (int value : inputArray) {
         System.out.print(value + " ");
     }
     
     System.out.println("\nHalved Array:");
     for (int value : resultArray) {
         System.out.print(value + " ");
     }
 }
}
