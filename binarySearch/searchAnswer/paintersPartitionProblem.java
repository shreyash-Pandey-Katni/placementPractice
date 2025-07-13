package binarySearch.searchAnswer;

import java.util.ArrayList;

public class paintersPartitionProblem {
    public int paint(int A, int B, ArrayList<Integer> C) {
        int n = C.size();
        int max = Integer.MIN_VALUE, sum = 0, val;
        for (int i = 0; i < n; i++) {
            val = C.get(i);
            sum += val;
            max = Math.max(val, max);
        }
        if (n < A) {
            return max*B;
        }
        int lower = max, upper = sum;
        int res = -1, mid;
        int partition;
        long tempSum;
        while (lower <= upper) {
            mid = lower + (upper - lower) / 2;
            partition = 1;
            tempSum = 0;
            for (int i = 0; i < n; i++) {
                if (tempSum + C.get(i) > mid) {
                    partition++;
                    tempSum = C.get(i);
                } else {
                    tempSum += C.get(i);
                }
            }
            if (partition <= A) {
                res = mid;
                upper = mid - 1;
            } else
                lower = mid + 1;
        }
        return (int) (((long) res * B) % 10000003);
    }
}
