package binarySearch;

import java.util.ArrayList;
import java.util.List;

public class searchForARange {
    private int findLast(List<Integer> A, int key) {
        int mid, val;
        int lower = 0, upper = A.size() - 1;
        int res = -1;
        while (lower <= upper) {
            mid = lower + (upper - lower) / 2;
            val = A.get(mid);
            if (val == key) {
                res = mid;
                lower = mid + 1; 
            }
            else if (val < key) {
                lower = mid + 1;
            } else
                upper = mid - 1;
        }
        return res;
    }

    private int findFirst(List<Integer> A, int key) {
        int mid, val;
        int lower = 0, upper = A.size() - 1;
        int res = -1;
        while (lower <= upper) {
            mid = lower + (upper - lower) / 2;
            val = A.get(mid);
            if (val == key) {
                res = mid;
                upper = mid - 1; // Move left to find the first occurrence
            } else if (val > key) {
                upper = mid - 1;
            } else {
                lower = mid + 1;
            }
        }
        return res;
    }

    public ArrayList<Integer> searchRange(final List<Integer> A, int B) {
        ArrayList<Integer> res = new ArrayList<>();
        res.add(findFirst(A, B));
        res.add(findLast(A, B));
        return res;
    }

    public static void main(String[] args) {
        List<Integer> A = List.of(5, 7, 7, 8, 8, 10);
        int B = 8;
        searchForARange obj = new searchForARange();
        ArrayList<Integer> result = obj.searchRange(A, B);
        System.out.println(result); // Output: [3, 4]
    }
}
