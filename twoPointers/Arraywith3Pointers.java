package twoPointers;

import java.util.List;

public class Arraywith3Pointers {
    public int minimize(final List<Integer> A, final List<Integer> B, final List<Integer> C) {
        int max = Integer.MIN_VALUE, min = Integer.MAX_VALUE, gap = 0, bestGap = Integer.MAX_VALUE, a, b, c, i = 0,
                j = 0, k = 0;
        while (i<A.size() && j < B.size() && k < C.size()) {
            a = A.get(i);
            b = B.get(j);
            c = C.get(k);
            max = Math.max(a, Math.max(b, c));
            min = Math.min(a, Math.min(c, b));
            if (min == a) {
                i++;
            } else if (min == b) {
                j++;
            } else {
                k++;
            }
            bestGap = Math.min(bestGap, max-min);
        }
        return bestGap;
    }
}
