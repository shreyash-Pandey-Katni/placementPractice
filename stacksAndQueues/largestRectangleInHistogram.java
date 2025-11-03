package stacksAndQueues;

import java.util.ArrayList;
import java.util.Stack;

public class largestRectangleInHistogram {
    private int MOD = 1000000007;
    public int largestRectangleArea(ArrayList<Integer> A) {
        int n = A.size();
        Stack<Integer> stack = new Stack<>();
        int[] left = new int[n];
        int[] right = new int[n];
        for (int i = 0; i < n; i++) {
            while (!stack.empty() && A.get(stack.peek()) >= A.get(i)) {
                stack.pop();
            }
            left[i] = stack.isEmpty()?-1:stack.peek();
            stack.push(i);
        }
        stack = new Stack<>();
        for (int i = n-1; i >= 0; i--) {
            while (!stack.isEmpty() && A.get(stack.peek()) >= A.get(i)) {
                stack.pop();
            }
            right[i] = stack.isEmpty()?n:stack.peek();
            stack.push(i);
        }
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            maxArea = Math.max(maxArea, (right[i] - left[i] - 1)*(A.get(i)));
        }
        return maxArea;
    }
    public static void main(String[] args) {
        // A : [ 2, 1, 5, 6, 2, 3 ]
        ArrayList<Integer> A = new ArrayList<>();
        // A.add(2);
        A.add(1);
        // A.add(5);
        // A.add(6);
        // A.add(2);
        // A.add(3);
        largestRectangleInHistogram obj = new largestRectangleInHistogram();
        System.out.println(obj.largestRectangleArea(A));
    }
}
