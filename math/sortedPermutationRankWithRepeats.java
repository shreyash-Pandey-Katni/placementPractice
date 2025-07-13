package math;

import java.util.HashMap;

public class sortedPermutationRankWithRepeats {
    HashMap<Long, Long> factorialCache = new HashMap<>();
    int mod = 1000003;

    public long factorial(int A) {
        if (A <= 1) {
            return 1;
        }
        if (factorialCache.containsKey((long) A)) {
            return factorialCache.get((long) A);
        }
        long result = 1;
        for (int i = 2; i <= A; i++) {
            result *= i;
            result %= mod; // Keep the result within bounds
            factorialCache.put((long) i, result);
        }
        factorialCache.put((long) A, result);
        return result;
    }

    public long modInverse(long a, long m) {
        long m0 = m, t, q;
        long x0 = 0, x1 = 1;

        if (m == 1) {
            return 0;
        }

        while (a > 1) {
            q = a / m;
            t = m;

            m = a % m;
            a = t;
            t = x0;

            x0 = x1 - q * x0;
            x1 = t;
        }

        if (x1 < 0) {
            x1 += m0;
        }

        return x1;
    }

    public int findRank(String A) {
        int n = A.length();
        if (n <= 1) {
            return 1;
        }
        int[] freq = new int[256];
        for (int i = 0; i < n; i++) {
            freq[A.charAt(i)]++;
        }

        int result = 1;

        for (int i = 0; i < n; i++) {
            for (char ch = 0; ch < A.charAt(i); ch++) {
                if (freq[ch] > 0) {
                    freq[ch]--;
                    long numerator = factorial(n - 1 - i) % mod;
                    long denominator = 1;
                    for (int j = 0; j < 256; j++) {
                        if (freq[j] > 0) {
                            denominator *= factorial(freq[j]);
                            denominator %= mod;
                        }
                    }
                    result += (numerator * modInverse(denominator, mod)) % mod;
                    result %= mod;
                    freq[ch]++;
                }
            }
            freq[A.charAt(i)]--;
        }
        return (int) result;
    }

    public static void main(String[] args) {
        sortedPermutationRankWithRepeats spr = new sortedPermutationRankWithRepeats();
        String A = "bbbbaaaa";
        int rank = spr.findRank(A);
        System.out.println("The rank of the string \"" + A + "\" is: " + rank);
    }
}
