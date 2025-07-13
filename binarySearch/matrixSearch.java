package binarySearch;

import java.util.ArrayList;
import java.util.List;

public class matrixSearch {
    public int searchMatrix(ArrayList<ArrayList<Integer>> A, int B) {
        int n = A.size();
        int m = A.get(0).size();
        int row, col;
        int lower = 0, upper = n * m - 1;
        int mid, val;
        while (lower <= upper) {
            mid = lower + (upper - lower) / 2;
            row = mid / m;
            col = mid % m;
            val = A.get(row).get(col);
            if (val == B)
                return 1;
            else if (val < B)
                lower = mid + 1;
            else
                upper = mid - 1;
        }
        return 0;
    }

    public static void main(String[] args) {
        matrixSearch obj = new matrixSearch();
        ArrayList<ArrayList<Integer>> A = new ArrayList<>();
        A.add(new ArrayList<>(List.of(1, 2, 3)));
        A.add(new ArrayList<>(List.of(4, 5, 6)));
        A.add(new ArrayList<>(List.of(7, 8, 9)));
        int B = 3;
        System.out.println(obj.searchMatrix(A, B)); // Output: 1

        ArrayList<ArrayList<Integer>> B1 = new ArrayList<>();
        B1.add(new ArrayList<>(List.of(10, 20, 30)));
        B1.add(new ArrayList<>(List.of(40, 50, 60)));
        System.out.println(obj.searchMatrix(B1, 25)); // Output: 0
    }
}
