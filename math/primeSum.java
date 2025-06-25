package math;

import java.util.ArrayList;

public class primeSum {
    // Helper class to verify if a number is prime
    public int isPrime(int n) {
        if (n <= 1)
            return 0; // 0 and 1 are not prime
        if (n <= 3)
            return 1; // 2 and 3 are prime
        if (n % 2 == 0 || n % 3 == 0)
            return 0; // eliminate multiples of 2 and 3
        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0)
                return 0;
        }
        return 1; // n is prime
    }

    public ArrayList<Integer> primesum(int A) {
        ArrayList<Integer> result = new ArrayList<>();
        int firstPrime = 2;
        int secondPrime = 2;
        if (A == 4) {
            result.add(firstPrime);
            result.add(secondPrime);
            return result;
        }
        for (int index = 2; index < A/2; index++) {
            if (isPrime(index) == 1 && isPrime(A - index) == 1) {
                firstPrime = index;
                secondPrime = A - index;
                break;
            }
        }
        result.add(firstPrime);
        result.add(secondPrime);
        return result;
    }

    public static void main(String[] args) {
        primeSum ps = new primeSum();
        int A = 10; // Example input
        ArrayList<Integer> result = ps.primesum(A);
        System.out
                .println("The two prime numbers that sum to " + A + " are: " + result.get(0) + " and " + result.get(1));
    }
}
