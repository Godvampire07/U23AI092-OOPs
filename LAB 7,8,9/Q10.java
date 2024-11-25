package lab1;

import java.util.HashMap;
import java.util.Scanner;

public class Q10{
    
    // Function to find and print characters that exceed a given count
    public static void printFrequentCharacters(String input, int n) {
        // HashMap to store character frequencies
        HashMap<Character, Integer> charCountMap = new HashMap<>();

        // Count occurrences of each character in the input string
        for (char ch : input.toCharArray()) {
            charCountMap.put(ch, charCountMap.getOrDefault(ch, 0) + 1);
        }

        // Print characters that appear more than 'n' times
        System.out.println("Characters that appear more than " + n + " times:");
        for (char ch : charCountMap.keySet()) {
            if (charCountMap.get(ch) > n) {
                System.out.println(ch + " appears " + charCountMap.get(ch) + " times");
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Take input string from the user
        //System.out.println("Enter the string:");
        //String input = scanner.nextLine();

        System.out.println("Enter the threshold number (n):");
        int n = scanner.nextInt();

        printFrequentCharacters("aabcdeaabcjlkjerwlaaabbsadfdsf", n);
    }
}

