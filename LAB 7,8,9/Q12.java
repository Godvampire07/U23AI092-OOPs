package lab1;

import java.util.Scanner;

public class Q12 {

    // Function to count occurrences of the pattern in the range [a, b]
    public static int countPatternOccurrences(int a, int b, String pattern) {
        int count = 0;

        // Loop through the range from 'a' to 'b'
        for (int i = a; i <= b; i++) {
            // Convert the number to a string and check if it contains the pattern
            if (String.valueOf(i).contains(pattern)) {
                count++;
            }
        }

        return count;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input the range (a, b) from the user
        System.out.println("Enter the range (a and b):");
        int a = scanner.nextInt();
        int b = scanner.nextInt();

        // Input the pattern to search for
        System.out.println("Enter the pattern:");
        String pattern = scanner.next();

        // Call the function to count occurrences of the pattern in the range
        int result = countPatternOccurrences(a, b, pattern);

        // Print the result
        System.out.println("The number of times '" + pattern + "' occurred between " + a + " and " + b + " is: " + result);
    }
}
