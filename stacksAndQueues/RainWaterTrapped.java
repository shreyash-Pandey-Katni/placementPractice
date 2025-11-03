package stacksAndQueues;

import java.util.Arrays;
import java.util.List;
import java.util.Stack;

public class RainWaterTrapped {
    public int trap(final List<Integer> A) {
        int n = A.size();
        if (n<3) {
            return 0;
        }
        Stack<Integer> stack = new Stack<>();
        int res = 0;
        int[] leftMax = new int[n];
        int[] rightMax = new int[n];
        leftMax[0] = A.get(0);
        rightMax[n-1] = A.get(n-1);
        for (int i=1;i<n;i++) {
            leftMax[i] = Math.max(leftMax[i-1], A.get(i));
        }
        for (int i=n-2;i>=0;i--) {
            rightMax[i] = Math.max(rightMax[i+1], A.get(i));
        }
        for (int i=1;i<n-1;i++) {
            res += Math.min(leftMax[i], rightMax[i]) - A.get(i);
        }
        return res;
    }
    public static void main(String[] args) {
        RainWaterTrapped rwt = new RainWaterTrapped();
        List<Integer> heights = Arrays.asList(0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1);
        System.out.println("Trapped rainwater: " + rwt.trap(heights));
    }
}
