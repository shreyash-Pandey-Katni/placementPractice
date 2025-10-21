package string;

public class atoi {
    public int atoi(final String A) {
        long res = 0L;
        String splitedString = "";
        if (A == null || A.isEmpty()) {
            return 0;
        }
        int i = 0;
        while (i < A.length() && A.charAt(i) == ' ') {
            i++;
        }
        boolean isNegative = false;
        if (i < A.length() && (A.charAt(i) == '-' || A.charAt(i) == '+')) {
            isNegative = A.charAt(i) == '-';
            i++;
        }
        while (i<A.length() && Character.isDigit(A.charAt(i))) {
            res = res * 10 + (A.charAt(i) - '0');
            if (!isNegative && res > Integer.MAX_VALUE) {
                return Integer.MAX_VALUE;
            }
            if (isNegative && -res < Integer.MIN_VALUE) {
                return Integer.MIN_VALUE;
            }
            i++;
        }
        return isNegative ? (int) -res : (int) res;
    }
    public static void main(String[] args) {
        String A = "   -42";
        atoi converter = new atoi();
        System.out.println("Input: " + A);
        int result = converter.atoi(A);
        System.out.println("Output: " + result); // Expected output: -42
    }
}
