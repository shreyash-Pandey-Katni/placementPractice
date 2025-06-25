package math;

public class verifyPrime {
    public int isPrime(int A) {
        int half = A / 2;
        if (A < 2) {
            return 0; // 0 and 1 are not prime numbers
        }
        for (int i = 2; i <= half; i++) {
            if (A%i == 0) {
                return 0;
            }
        }
        return 1;
    }
    public static void main(String[] args) {
        verifyPrime vp = new verifyPrime();
        System.out.println(vp.isPrime(4)); // Output: 0 (not prime)
        System.out.println(vp.isPrime(5)); // Output: 1 (prime)
        System.out.println(vp.isPrime(9)); // Output: 0 (not prime)
        System.out.println(vp.isPrime(11)); // Output: 1 (prime)
    }
}
