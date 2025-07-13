package math;

import java.util.Arrays;
import java.util.HashMap;

public class sortedPermutationRank {
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
            result %= 1000003; // Keep the result within bounds
            factorialCache.put((long) i, result);
        }
        factorialCache.put((long) A, result);
        return result;
    }

    public int findRank(String A) {
        int n = A.length();
        if (n <= 1) {
            return 1;
        }
        char[] characterArray = A.toCharArray();
        Arrays.sort(characterArray);
        long result = 1;
        for (int i = 0; i < n; i++) {
            int smallerCount = 0;
            for (int j = i + 1; j < n; j++) {
                if (A.charAt(j) < A.charAt(i)) {
                    smallerCount++;
                }
            }
            result += (factorial(n - 1 - i) % mod) * (smallerCount % mod);
            result %= mod;
        }
        return (int) result;
    }

    public static void main(String[] args) {
        sortedPermutationRank spr = new sortedPermutationRank();
        String A = "aba";
        int rank = spr.findRank(A);
        System.out.println("The rank of the string \"" + A + "\" is: " + rank);
    }
}
