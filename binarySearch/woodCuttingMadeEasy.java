package binarySearch;

import java.util.ArrayList;

public class woodCuttingMadeEasy {
    public int solve(ArrayList<Integer> A, int B) {
        int max = 0;
        for (int i = 0; i < A.size(); i++) {
            if (A.get(i) > max)
                max = A.get(i);
        }
        int lower = 0, upper = max;
        int mid;
        long sum;
        int res = 0;
        while (lower <= upper) {
            mid = lower + (upper - lower) / 2;
            sum = 0;
            for (int i = 0; i < A.size(); i++) {
                if (A.get(i) > mid) {
                    sum += A.get(i) - mid;
                }
            }
            if (sum == B) {
                return mid;
            } else if (sum < B) {
                upper = mid - 1;
            } else {
                res = mid;
                lower = mid + 1;
            }
        }
        return res;
    }

    public static void main(String[] args) {
        ArrayList<Integer> A = new ArrayList<>();
        // A : [ 4, 8, 7, 6, 5 ]
        // B : 10
        A.add(4);
        A.add(8);
        A.add(7);
        A.add(6);
        A.add(5);
        int B = 10;
        woodCuttingMadeEasy obj = new woodCuttingMadeEasy();
        int result = obj.solve(A, B);
        System.out.println(result); // Expected output: 5
    }
}
