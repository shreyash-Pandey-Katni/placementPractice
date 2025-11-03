package stacksAndQueues;

import java.util.ArrayList;
import java.util.Stack;

public class maxsprprod {
    private int MOD = 1000000007;
    public int maxSpecialProduct(ArrayList<Integer> A) {
        int n = A.size();
        Stack<Integer> stack = new Stack<>();
        int[] left = new int[n];
        for (int i = 0; i < n; i++) {
            while (!stack.isEmpty() && A.get(stack.peek()) <= A.get(i)) {
                stack.pop();
            }
            if (!stack.isEmpty()) {
                left[i] = stack.peek();
            } else {
                left[i] = 0;
            }
            stack.push(i);
        }
        int[] right = new int[n];
        stack = new Stack<>();
        for (int i = n-1; i >= 0; i--) {
            while (!stack.isEmpty() && A.get(stack.peek()) <= A.get(i)) {
                stack.pop();
            }
            if (!stack.isEmpty()) {
                right[i] = stack.peek();
            } else {
                right[i] = 0;
            }
            stack.push(i);
        }
        long maxProduct = Long.MIN_VALUE;
        for (int i = 0; i < n; i++) {
            long prod = ((long) left[i] * (long) right[i]);
            maxProduct = Math.max(maxProduct, prod) % MOD;
        }
        return (int)(maxProduct % MOD);
    }
    public static void main(String[] args) {
        // A : [ 5, 9, 6, 8, 6, 4, 6, 9, 5, 4, 9 ]
        ArrayList<Integer> A = new ArrayList<>();
        A.add(5);
        A.add(9);
        A.add(6);
        A.add(8);
        A.add(6);
        A.add(4);
        A.add(6);
        A.add(9);
        A.add(5);
        A.add(4);
        A.add(9);
        maxsprprod obj = new maxsprprod();
        System.out.println(obj.maxSpecialProduct(A));
    }
}
