package math;

public class reverseInteger {
    public int reverse(int A) {
        boolean isNegativeNumber = A < 0 ? true : false;
        int result = 0;
        int i = 0;
        A = Math.abs(A);
        if (A == 0) {
            return 0; // If the input is 0, return 0

        }
        int lengthOfA = (int) Math.log10(A) + 1;
        while (i < lengthOfA) {
            result *= 10;
            int digit = A % 10; // Get the last digit
            if (result > (Integer.MAX_VALUE - digit) || result < (Integer.MIN_VALUE + digit) || (result > Integer.MAX_VALUE) || (result > Integer.MAX_VALUE/10 && i < lengthOfA - 1)) {
                return 0;
            }
            result += A % 10;
            A /= 10;
            i++;
        }
        return isNegativeNumber ? (-1 * result) : result;
    }

    public static void main(String[] args) {
        reverseInteger solution = new reverseInteger();
        int number = 12345; // Example input
        int reversedNumber = solution.reverse(number);
        System.out.println("The reverse of " + number + " is: " + reversedNumber);

        // number = -6789; // Example input
        // reversedNumber = solution.reverse(number);
        // System.out.println("The reverse of " + number + " is: " + reversedNumber);

        // number = 0; // Example input
        // reversedNumber = solution.reverse(number);
        // System.out.println("The reverse of " + number + " is: " + reversedNumber);
        // Check for overflow
        number = -1146467285; // Example input
        reversedNumber = solution.reverse(number);
        System.out.println("The reverse of " + number + " is: " + reversedNumber);
    }
}
