package binarySearch;

import java.util.ArrayList;

public class searchInBiotonicArray {

    private int binarySearch(ArrayList<Integer> A, int key, int lower, int upper) {
        int mid;
        while (lower <= upper) {
            mid = (upper + lower) / 2;
            if (A.get(mid) == key)
                return mid;
            else if (A.get(mid) < key)
                lower = mid + 1;
            else
                upper = mid-1;
        }
        return -1;
    }

    private int binarySearchReverse(ArrayList<Integer> A, int key, int lower, int upper) {
        int mid;
        while (lower <= upper) {
            mid = (upper + lower) / 2;
            if (A.get(mid) == key)
                return mid;
            else if (A.get(mid) < key)
                upper = mid - 1;
            else
                lower = mid + 1;
        }
        return -1;
    }

    private int findPeak(ArrayList<Integer> A) {
        int lower = 1, upper = A.size() - 2;
        int mid;
        while (lower < upper) {
            mid = (upper + lower) / 2;
            if (A.get(mid) > A.get(mid - 1) && A.get(mid) > A.get(mid + 1))
                return mid;
            else if (A.get(mid) > A.get(mid - 1))
                lower = mid + 1;
            upper = mid - 1;
        }
        return lower;
    }

    public int solve(ArrayList<Integer> A, int B) {
        int peakIndex = findPeak(A);
        if (A.get(peakIndex) == B)
            return peakIndex;
        int resFirst = binarySearch(A, B, 0, peakIndex - 1);
        int resLast = binarySearchReverse(A, B, peakIndex + 1, A.size() - 1);
        if (resFirst == -1 && resLast == -1)
            return -1;
        else if (resFirst == -1)
            return resLast;
        return resFirst;
    }

    public static void main(String[] args) {
        // A : [ 1, 20, 50, 40, 10 ]
        // B : 5
        ArrayList<Integer> A = new ArrayList<>();
        A.add(1);
        A.add(20);
        A.add(50);
        A.add(40);
        A.add(10);
        int B = 5;
        searchInBiotonicArray obj = new searchInBiotonicArray();
        int result = obj.solve(A, B);
        System.out.println(result);
    }
}
