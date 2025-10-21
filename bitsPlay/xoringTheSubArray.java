package bitsPlay;

import java.util.ArrayList;

public class xoringTheSubArray {
    public int solve(ArrayList<Integer> A) {
        int res = 0;
        int n = A.size();
        for (int i = 0; i < n; i++) {
            if (((i+1)*(n-i))%2 != 0) {
                res ^= A.get(i);
            }
        }
        return res;
    }
}
