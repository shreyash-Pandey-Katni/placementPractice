package twoPointers;

import java.util.ArrayList;

public class diffK {
    public int diffPossible(ArrayList<Integer> A, int B) {
        int n = A.size();
        int left, right, target, mid;
        for (int i = 0; i < n-1; i++) {
            left = i+1;
            right = n-1;
            target = B+A.get(i);
            while (left<=right) {
                mid = left+(right-left)/2;
                if (A.get(mid) == target) {
                    return 1;
                } else if (A.get(mid) > target) {
                    right = mid -1;
                } else {
                    left = mid+1;
                }
            }
        }
        return 0;
    }
    public static void main(String[] args) {
        ArrayList<Integer> A = new ArrayList<>();
        A.add(1);
        // A.add(2);
        // A.add(2);
        // A.add(3);
        A.add(5);
        int B = 4;
        diffK obj = new diffK();
        System.out.println(obj.diffPossible(A, B));
    }
}
