package twoPointers;

import java.util.ArrayList;

public class maximumOnesAfterModification {
    public int solve(ArrayList<Integer> A, int B) {
        if (A == null || A.isEmpty()) {
            return 0;
        }
        int left = 0, currentlen = 0, maxLen =0, n = A.size();
        for (int right = 0; right < n; right++) {
            if (A.get(right)==0) {
                currentlen++;
            }
            while (currentlen>B) {
                currentlen -= (A.get(left) == 0?1:0);
                left++;
            }
            maxLen = Math.max(maxLen, right-left+1);
        }
        return maxLen;
    }
    public static void main(String[] args) {
        ArrayList<Integer> A = new ArrayList<>();
        A.add(1);
        A.add(0);
        int B = 1;
        maximumOnesAfterModification obj = new maximumOnesAfterModification();
        System.out.println(obj.solve(A, B));
    }
}
