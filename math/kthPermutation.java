package math;

import java.util.ArrayList;
import java.util.HashMap;

public class kthPermutation {

    HashMap<Long, Long> factorialCache = new HashMap<>();
    int mod = 1000000007;

    public long factorial(int A) {
        if (A <= 1) {
            return 1;
        }
        if (factorialCache.containsKey((long) A) && factorialCache.get((long) A) != null) {
            return factorialCache.get((long) A);
        }
        long result = 1;
        for (int i = 2; i <= A; i++) {
            result *= i;
            // result %= mod; // Keep the result within bounds
            factorialCache.put((long) i, result);
        }
        factorialCache.put((long) A, result);
        return result;
    }

    public ArrayList<Integer> findPerm(int A, Long B) {
        ArrayList<Integer> result = new ArrayList<>();
        ArrayList<Integer> available = new ArrayList<>();
        for (int i = 1; i <= A; i++) {
            available.add(i);
        }
        factorial(Math.min(A, 20)); // Precompute factorials up to 20 to avoid overflow
        for (int i = 1; i <= (A - 20); i++) {
            available.remove(0);
            result.add(i);
        }
        if (B > factorial(A)) {
            return result; // If B is greater than the total permutations, return empty
        }
        B--;
        while (B > 0) {
            long fact = factorial(available.size() - 1);
            int div = (int) (B / fact) + 1; // Find the index of the next number to add
            result.add(available.get(div - 1));
            available.remove(div - 1);
            B %= fact;
        }
        for (int i = 0; i < available.size(); i++) {
            result.add(available.get(i)); // Add remaining numbers
        }
        return result;
    }

    public static void main(String[] args) {
        kthPermutation kp = new kthPermutation();
        ArrayList<Integer> result = kp.findPerm(100000, 603828039791327040L);
        System.out.println("The 603828039791327040th permutation of the first 100000 natural numbers is: " + result);
    }
}
