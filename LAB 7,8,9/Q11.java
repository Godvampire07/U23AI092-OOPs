package lab1;

import java.util.HashSet;
import java.util.Scanner;

public class Q11 {

    // Function to check if the string is perfect (no duplicate characters)
    public static boolean isPerfectString(String input) {
        // Create a HashSet to store encountered characters
        HashSet<Character> charSet = new HashSet<>();

        // Iterate through each character in the string
        for (char ch : input.toCharArray()) {
            // If the character is already in the set, it's a duplicate
            if (charSet.contains(ch)) {
                return false;
            }
            // Add the character to the set
            charSet.add(ch);
        }

        // If no duplicates were found, the string is perfect
        return true;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input the string from the user
        System.out.println("Enter the string:");
        String input = scanner.nextLine();

        // Check if the string is perfect
        if (isPerfectString(input)) {
            System.out.println("The string is a perfect string.");
        } else {
            System.out.println("The string is not a perfect string.");
        }
    }
}

