package binarySearch;

import java.util.ArrayList;

public class smallerOrEqualElements {
    public int solve(ArrayList<Integer> A, int B) {
        int lower = 0, upper = A.size() - 1;
        int mid;
        int result = -1;
        while (lower <= upper) {
            mid = (upper + lower) / 2;
            int val = A.get(mid);
            if (val <= B) {
                result = mid; // Store the last position where A[mid] <= B
                lower = mid + 1;
            } else
                upper = mid - 1;
        }
        return result + 1;
    }

    public static void main(String[] args) {
        ArrayList<Integer> A = new ArrayList<>();
        // A : [ 1, 3, 4, 4, 6 ]
        // B : 4
        A.add(1);
        A.add(3);
        A.add(4);
        A.add(4);
        A.add(6);
        int B = 4;
        smallerOrEqualElements obj = new smallerOrEqualElements();
        int result = obj.solve(A, B);
        System.out.println(result);

    }
}
