package lab1;
import java.util.Random;

public class Q7 {
    
    private static final Random randomNumbers = new Random();
    private static final int TWO = 2;
    private static final int THREE = 3;
    private static final int SEVEN = 7;
    private static final int ELEVEN = 11;
    private static final int BOX_CARS = 12;

    public static void main(String[] args) {
        int myPoint = 0; 
        boolean gameWon = false;
        boolean gameOver = false;

        int sumOfDice = rollDice(); // First roll of the dice

        switch (sumOfDice) {
            case SEVEN:  // Win with 7 on first roll
            case ELEVEN:  // Win with 11 on first roll
                gameWon = true;
                gameOver = true;
                break;
            case TWO:  // Lose with 2
            case THREE: // Lose with 3
            case BOX_CARS:  // Lose with 12
                gameOver = true;
                break;
            default:  // No win or loss, so remember the point
                myPoint = sumOfDice;
                System.out.printf("Your point is %d%n", myPoint);
                break;
        }

       
        while (!gameOver) {
            sumOfDice = rollDice(); 

            // Check if the player rolled the point again or rolled a 7
            if (sumOfDice == myPoint) {
                gameWon = true;
                gameOver = true;
            } else if (sumOfDice == SEVEN) {
                gameOver = true;
            }
        }

        // Display win or lose message
        if (gameWon) {
            System.out.println("Player wins!");
        } else {
            System.out.println("Player loses.");
        }
    }

    public static int rollDice() {
   
        int die1 = 1 + randomNumbers.nextInt(6);
        int die2 = 1 + randomNumbers.nextInt(6);

        int sum = die1 + die2;  // Sum of the dice
        System.out.printf("Player rolled %d + %d = %d%n", die1, die2, sum);
        return sum;
    }
}
