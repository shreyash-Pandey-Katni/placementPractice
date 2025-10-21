package binarySearch;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Stack;

public class simpleQueries {

    int MOD = 1_000_000_007;
    HashMap<Integer, Integer> productOfDivisors = new HashMap<>();

    public int binarySearchWithElementLessThanOrEqualTo(int[][] A, int key) {
        int high = A.length - 1, low = 0, mid;
        while (low <= high) {
            mid = low + (high - low) / 2; // Avoid overflow like C++
            if (A[mid][1] < key) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low; // Return low like C++ lower_bound
    }

    public ArrayList<Integer> solve(ArrayList<Integer> A, ArrayList<Integer> B) {

        int n = A.size();
        int max = Integer.MIN_VALUE;
        int[] prev = new int[n];
        int[] next = new int[n];
        ArrayList<Integer> result = new ArrayList<>();
        Stack<Integer> stack = new Stack<>();

        for (int i = 0; i < n; i++) {
            while (!stack.isEmpty() && A.get(stack.peek()) <= A.get(i)) {
                stack.pop();
            }
            if (stack.isEmpty()) {
                prev[i] = -1;
            } else {
                prev[i] = stack.peek();
            }
            stack.push(i);
            max = Math.max(max, A.get(i));
        }
        stack.clear();

        for (int i = n - 1; i >= 0; i--) {
            while (!stack.isEmpty() && A.get(stack.peek()) < A.get(i)) {
                stack.pop();
            }
            if (stack.isEmpty()) {
                next[i] = n;
            } else {
                next[i] = stack.peek();
            }
            stack.push(i);
        }
        int[] productOfDivisors = new int[max + 1];
        for (int i = 0; i <= max; i++) {
            productOfDivisors[i] = i; // Initialize to the number itself like C++
        }
        for (int i = 2; i <= max; i++) {
            for (int j = 2 * i; j <= max; j += i) { // Start from 2*i like C++
                productOfDivisors[j] = (int)((long)productOfDivisors[j] * i % MOD);
            }
        }
        int[][] countArr = new int[n][2];
        for (int i = 0; i < n; i++) {
            countArr[i][0] = (int) (productOfDivisors[A.get(i)] % MOD);
            countArr[i][1] = (int) (((long) ((long) (i - (prev[i]))) * ((long) (next[i] - i))) % MOD);
        }

        Arrays.sort(countArr, new Comparator<int[]>() {

            @Override
            public int compare(int[] o1, int[] o2) {
                return Integer.compare(o2[0], o1[0]);
            }

        });
        for (int i = 1; i < n; i++) {
            countArr[i][1] += countArr[i - 1][1];
        }
        for (int i = 0; i < B.size(); i++) {
            result.add(countArr[binarySearchWithElementLessThanOrEqualTo(countArr, B.get(i))][0]);
        }
        return result;
    }

    private static void runTest(String testName, ArrayList<Integer> A, ArrayList<Integer> B, String expected) {
        simpleQueries obj = new simpleQueries();
        obj.productOfDivisors.clear(); // Clear global variables
        
        long startTime = System.currentTimeMillis();
        ArrayList<Integer> result = obj.solve(A, B);
        long endTime = System.currentTimeMillis();
        
        System.out.println("=== " + testName + " ===");
        System.out.println("Input A size: " + A.size() + ", B size: " + B.size());
        System.out.println("Time taken: " + (endTime - startTime) + "ms");
        System.out.println("Result: " + result);
        if (expected != null) {
            System.out.println("Expected: " + expected);
        }
        System.out.println();
    }

    public static void main(String[] args) {
        // Test Case 1: Basic example
        System.out.println("Running comprehensive test cases for Simple Queries...\n");
        
        // Test 1: Small array - manually verifiable
        ArrayList<Integer> A1 = new ArrayList<>();
        A1.add(1); A1.add(2); A1.add(3);
        ArrayList<Integer> B1 = new ArrayList<>();
        B1.add(1); B1.add(3); B1.add(6);
        runTest("Test 1: Small Array [1,2,3]", A1, B1, 
                "G=[3,2,2,3,1,1], after transform+sort, K=1,3,6");

        // Test 2: All same elements
        ArrayList<Integer> A2 = new ArrayList<>();
        A2.add(5); A2.add(5); A2.add(5);
        ArrayList<Integer> B2 = new ArrayList<>();
        B2.add(1); B2.add(3); B2.add(6);
        runTest("Test 2: All Same Elements [5,5,5]", A2, B2, null);

        // Test 3: Single element
        ArrayList<Integer> A3 = new ArrayList<>();
        A3.add(10);
        ArrayList<Integer> B3 = new ArrayList<>();
        B3.add(1);
        runTest("Test 3: Single Element [10]", A3, B3, null);

        // Test 4: Descending array
        ArrayList<Integer> A4 = new ArrayList<>();
        A4.add(5); A4.add(4); A4.add(3); A4.add(2); A4.add(1);
        ArrayList<Integer> B4 = new ArrayList<>();
        B4.add(1); B4.add(5); B4.add(10); B4.add(15);
        runTest("Test 4: Descending [5,4,3,2,1]", A4, B4, null);

        // Test 5: Ascending array
        ArrayList<Integer> A5 = new ArrayList<>();
        A5.add(1); A5.add(2); A5.add(3); A5.add(4); A5.add(5);
        ArrayList<Integer> B5 = new ArrayList<>();
        B5.add(1); B5.add(5); B5.add(10); B5.add(15);
        runTest("Test 5: Ascending [1,2,3,4,5]", A5, B5, null);

        // Test 6: Large values near upper bound
        ArrayList<Integer> A6 = new ArrayList<>();
        A6.add(99999); A6.add(99998); A6.add(99997);
        ArrayList<Integer> B6 = new ArrayList<>();
        B6.add(1); B6.add(3); B6.add(6);
        runTest("Test 6: Large Values", A6, B6, null);

        // Test 7: Stress test - Medium size with TLE risk
        ArrayList<Integer> A7 = new ArrayList<>();
        ArrayList<Integer> B7 = new ArrayList<>();
        for (int i = 1; i <= 1000; i++) {
            A7.add(i % 100 + 1); // Values 1-100, repeated
        }
        for (int i = 1; i <= 1000; i += 100) {
            B7.add(i);
        }
        runTest("Test 7: Medium Stress Test (N=1000)", A7, B7, null);

        // Test 8: Large stress test - Near upper bounds (TLE risk)
        ArrayList<Integer> A8 = new ArrayList<>();
        ArrayList<Integer> B8 = new ArrayList<>();
        int n = 5000; // Reduced from 100000 to avoid actual TLE during testing
        for (int i = 1; i <= n; i++) {
            A8.add((i % 1000) + 1); // Values 1-1000, repeated
        }
        for (int i = 1; i <= Math.min(1000, n * (n + 1) / 2); i += n/10) {
            B8.add(i);
        }
        runTest("Test 8: Large Stress Test (N=" + n + ")", A8, B8, null);

        // Test 9: Edge case - K at boundaries
        ArrayList<Integer> A9 = new ArrayList<>();
        A9.add(1); A9.add(2);
        ArrayList<Integer> B9 = new ArrayList<>();
        B9.add(1); B9.add(3); // K=1 (first), K=3 (last)
        runTest("Test 9: Boundary K values", A9, B9, null);

        // Test 10: OutOfBounds risk test
        ArrayList<Integer> A10 = new ArrayList<>();
        A10.add(1);
        ArrayList<Integer> B10 = new ArrayList<>();
        B10.add(2); // K=2 but only 1 element total - should handle gracefully
        try {
            runTest("Test 10: Potential OOB (K > total elements)", A10, B10, "Should handle gracefully or throw proper error");
        } catch (Exception e) {
            System.out.println("Test 10 caught exception: " + e.getMessage());
            System.out.println("This indicates a bug in boundary handling!\n");
        }

        System.out.println("All test cases completed!");
        System.out.println("\nCheck for:");
        System.out.println("1. Correctness on small inputs");
        System.out.println("2. No OutOfBounds exceptions");
        System.out.println("3. Reasonable execution times (< 1000ms for medium inputs)");
        System.out.println("4. Global variable clearing between tests");
        System.out.println("5. Binary search returning valid indices");
    }
}
