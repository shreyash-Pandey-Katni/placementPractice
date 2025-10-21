package bitsPlay;

import java.util.ArrayList;
import java.util.Collections;

public class minXORValue {
    public int findMinXor(ArrayList<Integer> A) {
        int min = Integer.MAX_VALUE;
        int n = A.size();
        Collections.sort(A);
        for (int i = 0; i < n-1; i++) {
            min = Math.min(min, A.get(i)^A.get(i+1));
        }
        return min;
    }
}
