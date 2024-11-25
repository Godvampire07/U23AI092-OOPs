package lab1;
import java.util.regex.Pattern;

public class Q9 {

    private static boolean hasImmediateRepeatingPattern(String password) {
        for (int i = 0; i < password.length() - 1; i++) {
            if (password.substring(i + 1).startsWith(password.substring(i, i + 1))) {
                return true;
            }
        }
        return false;
    }
 
    public static boolean isValidPassword(String password) {
        //  have at least one lowercase letter and one digit
        boolean hasLowerCase = password.chars().anyMatch(Character::isLowerCase);
        boolean hasDigit = password.chars().anyMatch(Character::isDigit);

        // No uppercase letters and no special characters
        boolean noUpperCase = password.chars().noneMatch(Character::isUpperCase);
        boolean noSpecialChar = password.chars().allMatch(ch -> Character.isLetterOrDigit(ch));

        //  Length between 5 and 12 characters
        boolean validLength = password.length() >= 5 && password.length() <= 12;

        //  No immediate repeating patterns
        boolean noImmediateRepeatingPattern = !hasImmediateRepeatingPattern(password);

        return hasLowerCase && hasDigit && noUpperCase && noSpecialChar && validLength && noImmediateRepeatingPattern;
    }

    public static void main(String[] args) {
        // Test cases
        String[] testPasswords = { "abcanan1", "abc11se", "123sd123", "adfasdsdf", "Aasdfasd12", "abc123" };

        for (String password : testPasswords) {
            System.out.printf("Password: %s -> %s%n", password, isValidPassword(password) ? "Valid" : "Invalid");
        }
    }
}
