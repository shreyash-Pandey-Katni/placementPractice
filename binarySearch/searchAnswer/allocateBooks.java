package binarySearch.searchAnswer;

import java.util.ArrayList;

public class allocateBooks {
    public int books(ArrayList<Integer> A, int B) {
        int max = A.get(0), sum = 0, n = A.size(), val;
        if (n < B)
            return -1;
        for (int i = 0; i < n; i++) {
            val = A.get(i);
            max = Math.max(val, max);
            sum += val;
        }
        int partition = 1, mid, res = -1;
        int lower = max, upper = sum;
        long tempSum;
        while (lower <= upper) {
            tempSum = 0;
            partition = 1;
            mid = lower + (upper - lower) / 2;
            for (int i = 0; i < n; i++) {
                if (tempSum + A.get(i) > mid) {
                    partition++;
                    tempSum = A.get(i);
                } else {
                    tempSum += A.get(i);
                }
            }
            if (partition <= B) {
                res = mid;
                upper = mid - 1;
            } else {
                lower = mid + 1;
            }
        }
        return res;
    }
}
