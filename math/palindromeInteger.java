package math;

public class palindromeInteger {
    public int reverseNumber(int A) {
        int reversedNumber = 0;
        while (A > 0) {
            int digit = A % 10; // Get the last digit
            reversedNumber = reversedNumber * 10 + digit; // Append it to the reversed number
            A /= 10; // Remove the last digit from A
        }
        return reversedNumber;
    }

    public int isPalindrome(int A) {
        int i = 0;
        if (A == 0) {
            return 1;
        }
        if (A < 0) {
            return 0; // Negative numbers are not considered palindromes

        }
        int lengthOfA = (int) (Math.log10(A) / 1.0) + 1;
        if (lengthOfA == 1) {
            return 1;
        }
        while (i <= lengthOfA / 2) {
            int leastSignificantDigit = (int) ((A % Math.pow(10, i + 1)) / Math.pow(10, i));
            int mostSignificantDigit = (int) ((A / Math.pow(10, lengthOfA - i - 1)) % 10);
            if (leastSignificantDigit != mostSignificantDigit) {
                return 0;
            }
            i++;
        }
        return 1;
    }
    public int isPalindromeUsingReverse(int A) {
        if (A < 0) {
            return 0; // Negative numbers are not considered palindromes
        }
        int reversedNumber = reverseNumber(A);
        return A == reversedNumber ? 1 : 0;
    }

    public static void main(String[] args) {
        palindromeInteger solution = new palindromeInteger();
        int number = 12321; // Example input
        int result = solution.isPalindrome(number);
        System.out.println("Is " + number + " a palindrome? " + (result == 1 ? "Yes" : "No"));

        number = 12345; // Example input
        result = solution.isPalindrome(number);
        System.out.println("Is " + number + " a palindrome? " + (result == 1 ? "Yes" : "No"));

        number = 0; // Example input
        result = solution.isPalindrome(number);
        System.out.println("Is " + number + " a palindrome? " + (result == 1 ? "Yes" : "No"));
    }
}
