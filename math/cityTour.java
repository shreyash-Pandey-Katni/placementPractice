package math;

import java.util.ArrayList;
import java.util.HashMap;

public class cityTour {
    HashMap<Integer, Long> memo = new HashMap<>();
    int mod = 1000000007;

    public long factorial(int n) {
        if (n < 0) {
            return 1; // Factorial is not defined for negative numbers
        }
        if (n == 0 || n == 1) {
            return 1; // Base case: 0! = 1 and 1! = 1
        }
        if (memo.containsKey(n)) {
            return memo.get(n); // Return the cached result if it exists
        }
        long result = 1;
        for (int i = 2; i <= n; i++) {
            result *= i;
            result %= mod; // Keep the result within bounds
            memo.put(i, result); // Store the factorial in the memoization map
        }
        return result;
    }

    private long modPow(long base, int exp, int mod) {
        long result = 1;
        base %= mod;
        while (exp > 0) {
            if ((exp & 1) == 1)
                result = (result * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return result;
    }

    private long modInverse(long a, int mod) {
        return modPow(a, mod - 2, mod);
    }

    public int solve(int A, ArrayList<Integer> B) {
        int numberOfVisitedCities = B.size();
        int numberOfUnvisitedCities = A - numberOfVisitedCities;
        if (numberOfUnvisitedCities < 0) {
            return 0; // Invalid case where visited cities exceed total cities
        }
        if (numberOfVisitedCities == 0) {
            return 1; // If no cities are visited, there's only one way (no tour)
        }
        long allPermutations = factorial(numberOfUnvisitedCities);
        B.add(A + 1); // Add a sentinel value to handle the last city
        B.add(0); // Add a sentinel value to handle the first city
        B.sort((Integer o1, Integer o2) -> Integer.compare(o1, o2));
        numberOfVisitedCities += 2; // Adjust for the two sentinel values
        ArrayList<Integer> gaps = new ArrayList<>();
        for (int i = 1; i < numberOfVisitedCities; i++) {
            gaps.add(B.get(i) - B.get(i - 1) - 1);
        }
        int numberOfgaps = gaps.size();
        for (int i = 0; i < numberOfgaps; i++) {
            allPermutations = (allPermutations * modInverse(factorial(gaps.get(i)), mod)) % mod;
        }

        for (int i = 0; i < numberOfgaps; i++) {
            if (i > 0 && i < numberOfgaps - 1) {
                allPermutations *= modPow(2, gaps.get(i) - 1, mod);
            }
            allPermutations %= mod;
        }

        return (int) allPermutations;
    }

    public static void main(String[] args) {
        cityTour tour = new cityTour();
        ArrayList<Integer> visitedCities = new ArrayList<>();
        // A : 588
        // B : [ 10, 44, 160, 150, 288, 200, 555, 294, 254, 395, 182, 308, 416, 474,
        // 186, 387, 71, 364, 242, 40, 513, 263, 201, 156, 270, 506, 551 ]
        visitedCities.add(10);
        visitedCities.add(44);
        visitedCities.add(160);
        visitedCities.add(150);
        visitedCities.add(288);
        visitedCities.add(200);
        visitedCities.add(555);
        visitedCities.add(294);
        visitedCities.add(254);
        visitedCities.add(395);
        visitedCities.add(182);
        visitedCities.add(308);
        visitedCities.add(416);
        visitedCities.add(474);
        visitedCities.add(186);
        visitedCities.add(387);
        visitedCities.add(71);
        visitedCities.add(364);
        visitedCities.add(242);
        visitedCities.add(40);
        visitedCities.add(513);
        visitedCities.add(263);
        visitedCities.add(201);
        visitedCities.add(156);
        visitedCities.add(270);
        visitedCities.add(506);
        visitedCities.add(551);
        int totalCities = 588;
        int result = tour.solve(totalCities, visitedCities);
        System.out.println("Total number of tours: " + result);

    }
}
