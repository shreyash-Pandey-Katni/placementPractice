package twoPointers;

import java.util.ArrayList;
import java.util.Collections;

public class threeSum {
    public int threeSumClosest(ArrayList<Integer> A, int B) {
        if (A == null || A.size() < 3) {
            return 0;
        }
        Collections.sort(A);
        int left, right, n = A.size(), closestSum = 0, diff = Integer.MAX_VALUE;
        for (int i = 0; i < n - 2; i++) {
            int current = A.get(i);
            left = i + 1;
            right = n-1;
            while (left < n && right > left) {
                int sum = current + A.get(left) + A.get(right);
                int currentDiff = Math.abs(B - sum);
                if (currentDiff < diff) {
                    diff = currentDiff;
                    closestSum = sum;
                }
                if (sum == B) {
                    return sum;
                } else if (sum < B) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return closestSum;
    }
    public static void main(String[] args) {
        ArrayList<Integer> A = new ArrayList<>();
        A.add(-1);
        A.add(2);
        A.add(1);
        A.add(-4);
        threeSum obj = new threeSum();
        System.out.println(obj.threeSumClosest(A, 1)); // Output: 2
    }
}
