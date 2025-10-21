package string;

public class convertTheAmountInNumberToWords {

    private static final String[] ones = {
        "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
        "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"
    };

    private static final String[] tens = {
        "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"
    };

    /**
     * Converts a number from 1-99 into its word representation.
     */
    private String convertUptoTwoDigits(int n) {
        if (n < 20) {
            return ones[n];
        } else {
            String ten = tens[n / 10];
            String one = ones[n % 10];
            if (n % 10 != 0) {
                return ten + "-" + one;
            } else {
                return ten;
            }
        }
    }

    /**
     * Converts the number string into words based on the Indian Numbering System.
     */
    private String numberToWords(String numStr) {
        if (numStr.equals("0")) return "zero";

        StringBuilder result = new StringBuilder();
        long num = Long.parseLong(numStr);

        // Crores (1,00,00,000)
        int crores = (int) (num / 10000000);
        if (crores > 0) {
            result.append(convertUptoTwoDigits(crores)).append("-crore-");
            num %= 10000000;
        }

        // Lakhs (1,00,000)
        int lakhs = (int) (num / 100000);
        if (lakhs > 0) {
            result.append(convertUptoTwoDigits(lakhs)).append("-lakh-");
            num %= 100000;
        }

        // Thousands (1,000)
        int thousands = (int) (num / 1000);
        if (thousands > 0) {
            result.append(convertUptoTwoDigits(thousands)).append("-thousand-");
            num %= 1000;
        }

        // Hundreds (100)
        int hundreds = (int) (num / 100);
        if (hundreds > 0) {
            result.append(convertUptoTwoDigits(hundreds)).append("-hundred-");
            num %= 100;
        }

        // The "and" part
        if (result.length() > 0 && num > 0) {
            result.append("and-");
        }

        // Last two digits (1-99)
        if (num > 0) {
            result.append(convertUptoTwoDigits((int) num));
        }

        // Clean up trailing hyphens if any
        if (result.length() > 0 && result.charAt(result.length() - 1) == '-') {
            result.setLength(result.length() - 1);
        }

        return result.toString();
    }

    /**
     * Main solve method to compare the generated words with the input words.
     */
    public int solve(String num, String words) {
        String generatedWords = numberToWords(num);
        if (generatedWords.equals(words)) {
            return 1;
        }
        return 0;
    }

    public static void main(String[] args) {
        convertTheAmountInNumberToWords converter = new convertTheAmountInNumberToWords();
        String num = "1234";
        String words = "one-thousand-two-hundred-and-thirty-four";
        System.out.println("Input: " + num + ", " + words);
        System.out.println("Output: " + converter.solve(num, words)); // Expected: 1

        String num2 = "1";
        String words2 = "one";
        System.out.println("Input: " + num2 + ", " + words2);
        System.out.println("Output: " + converter.solve(num2, words2)); // Expected: 1
    }
}