package twoPointers;

import java.util.ArrayList;

public class subArraysWithDistinctIntegers {
    public int solve(ArrayList<Integer> A, int B) {
        if (B == 0) {
            return 0;
        } else if (B == 1) {
            return A.size();
        }
    }
}
