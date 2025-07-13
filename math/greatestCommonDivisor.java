package math;

public class greatestCommonDivisor {
    public int gcd(int A, int B) {
        if (A == 0 || B == 0) {
            return Math.max(A, B);
        }
        if (A < 2 || B < 2) {
            return 1;
        }
        int i = Math.min(A, B);
        while (A % i != 0 || B % i != 0) {
            i--;
        }
        return i;
    }
    public static void main(String[] args) {
        greatestCommonDivisor gcd = new greatestCommonDivisor();
        System.out.println(gcd.gcd(12, 15)); // Output: 3
        System.out.println(gcd.gcd(100, 25)); // Output: 25
        System.out.println(gcd.gcd(7, 1)); // Output: 1
    }
}
