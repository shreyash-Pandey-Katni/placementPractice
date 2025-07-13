package math;

public class trailingZerosInFactorial {
    public int trailingZeroes(int A) {
        int count = 0;
        while (A > 1) {
            A /= 5;
            count += A;
        }
        return count;
    }

    public static void main(String[] args) {
        trailingZerosInFactorial tzf = new trailingZerosInFactorial();
        int A = 5;
        int result = tzf.trailingZeroes(A);
        System.out.println("Trailing zeros in " + A + "! is: " + result);
    }
}
