package binarySearch.searchAnswer;

import java.util.ArrayList;

public class matrixMedian {

    private int binarySearch(ArrayList<Integer> A, int key) {
        int lower = 0, upper = A.size() - 1;
        int mid, val, res = -1;
        while (lower <= upper) {
            mid = lower + (upper - lower) / 2;
            val = A.get(mid);
            if (val <= key) {
                res = mid;
                lower = mid + 1;
            } else {
                upper = mid - 1;
            }
        }
        return res;
    }

    public int findMedian(ArrayList<ArrayList<Integer>> A) {
        int min = Integer.MAX_VALUE, max = Integer.MIN_VALUE;
        int n = A.size();
        int m = A.get(0).size();
        for (int i = 0; i < n; i++) {
            min = Math.min(min, A.get(i).get(0));
            max = Math.max(max, A.get(i).get(m - 1));
        }
        int median = n * m / 2 + 1;
        int lower = min, upper = max, mid;
        int countLessThanOrEqualVal = 0;
        int res = -1;
        while (lower <= upper) {
            mid = lower + (upper - lower) / 2;
            countLessThanOrEqualVal = 0;
            for (int i = 0; i < n; i++)
                countLessThanOrEqualVal += binarySearch(A.get(i), mid) + 1;
            if (countLessThanOrEqualVal >= median) {
                res = mid;
                upper = mid - 1;
            } else

                lower = mid + 1;
        }
        return res;
    }

    public static void main(String[] args) {
        matrixMedian mm = new matrixMedian();
        ArrayList<ArrayList<Integer>> matrix = new ArrayList<>();
        // Example matrix
        matrix.add(new ArrayList<>(java.util.Arrays.asList(1, 3, 5)));
        matrix.add(new ArrayList<>(java.util.Arrays.asList(2, 6, 9)));
        matrix.add(new ArrayList<>(java.util.Arrays.asList(3, 6, 9)));

        int median = mm.findMedian(matrix);
        System.out.println("The median of the matrix is: " + median);
    }
}
