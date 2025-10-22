package twoPointers;

import java.util.ArrayList;
import java.util.Collections;

public class countingTriangles {
    private int MOD = 1_000_000_007;
    public int nTriang(ArrayList<Integer> A) {
        int result = 0;
        int n = A.size();
        Collections.sort(A);
        for (int i = n - 1; i >= 2; i--) {
            int left = 0, right = i - 1;
            while (left < right) {
                if (A.get(left) + A.get(right) > A.get(i)) {
                    result += ((right - left)%MOD);
                    result %= MOD;
                    right--;
                } else {
                    left++;
                }
            }
        }
        return result;
    }
}
