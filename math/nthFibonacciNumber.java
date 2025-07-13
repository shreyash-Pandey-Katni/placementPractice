package math;

import java.util.HashMap;

public class nthFibonacciNumber {
    HashMap<Integer, Long> map = new HashMap<>();
    int mod = 1000000007;

    public int solve(int A) {
        return (int) (solveOptimized(A) % mod);
    }

    // Optimized approach using matrix exponentiation
    public long solveOptimized(int A) {
        if (A == 1 || A == 2) {
            return 1;
        }
        if (map.containsKey(A)) {
            return map.get(A).intValue();
        }
        long result;
        if (A % 2 == 1) {
            long firstHalf = solveOptimized((A - 1) / 2 + 1) % mod;
            long secondHalf = solveOptimized((A - 1) / 2) % mod;
            result = ((firstHalf * firstHalf) % mod) + ((secondHalf * secondHalf) % mod);
            result %= mod;
            map.put(A, result);
        } else {
            int k = A / 2;
            long firstHalf = (solveOptimized(k) % mod);
            long secondHalf = (solveOptimized(k + 1) % mod);
            long diffVal = ((2 * secondHalf) % mod) - firstHalf;
            diffVal = diffVal < 0 ? (diffVal + mod) : diffVal;
            result = (firstHalf % mod) * ((diffVal) % mod);
            result %= mod;
            map.put(A, result);
        }
        return (result);
    }

    public static void main(String[] args) {
        nthFibonacciNumber fib = new nthFibonacciNumber();
        // System.out.println(fib.solve(5)); // Output: 5
        // System.out.println(fib.solve(10)); // Output: 55
        System.out.println(fib.solve(1000)); // Output: 687995182
    }
}
