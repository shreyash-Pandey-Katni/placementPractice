package twoPointers;

import java.util.ArrayList;

public class countingSubArrays {
    public int solve(ArrayList<Integer> A, int B) {
        if (A == null || A.isEmpty()) {
            return 0;
        }
        int left=0, currentSum=0, count=0, n=A.size();
        for (int right=0; right<n; right++) {
            currentSum += A.get(right);
            while (left<=right && currentSum>=B) {
                currentSum -= A.get(left);
                left++;
            }
            count += (right-left+1);
        }
        return count;
    }
    public static void main(String[] args) {
        ArrayList<Integer> A = new ArrayList<>();
        A.add(2);
        A.add(5);
        A.add(6);
        int B = 10;
        countingSubArrays obj = new countingSubArrays();
        System.out.println(obj.solve(A, B));
    }
}
