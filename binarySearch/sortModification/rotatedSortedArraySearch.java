package binarySearch.sortModification;

import java.util.List;

import binarySearch.smallerOrEqualElements;

public class rotatedSortedArraySearch {
    public int searchSmallestInteger(final List<Integer> A) {
        int low = 0, high = A.size()-1, mid=-1, finalMid=-1;
        int previousLow = Integer.MAX_VALUE;
        while (low<=high) {
            mid = (high+low)/2;
            if (A.get(mid) <= A.get(high)) {
                if (A.get(mid) < previousLow) {
                    previousLow = A.get(mid);
                    finalMid = mid;
                }
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        if (finalMid == -1){
            return 0;
        }

        return finalMid;
    }
    public int binarySearch(final List<Integer> A, int B, int low, int high){
        int mid = -1;
        while (low<=high) {
            mid = (low+high)/2;
            if(A.get(mid) == B) return mid;
            else if(A.get(mid) > B) {
                high = mid -1;
            } else {
                low = mid+1;
            }
        }
        return -1;
    }
    public int search(final List<Integer> A, int B) {
        int pivotIndex = searchSmallestInteger(A);
        if (pivotIndex == 0) return binarySearch(A, B, 0, A.size()-1);
        int leftHalfResult = binarySearch(A, B, 0, pivotIndex-1);
        if (leftHalfResult != -1) return leftHalfResult;
        else return binarySearch(A, B, pivotIndex, A.size()-1);
    }
    public static void main(String[] args) {
        // A : [ 194, 195, 196, 197, 198, 199, 201, 203, 204, 1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 13, 14, 15, 16, 17, 18, 20, 21, 22, 23, 24, 25, 26, 27, 29, 30, 31, 32, 33, 34, 35, 36, 37, 39, 40, 42, 43, 44, 45, 47, 48, 49, 50, 51, 52, 53, 54, 55, 57, 58, 59, 60, 61, 63, 65, 66, 68, 69, 70, 71, 73, 74, 76, 77, 79, 80, 81, 82, 83, 84, 86, 87, 88, 89, 91, 92, 93, 94, 95, 97, 98, 99, 101, 103, 104, 105, 106, 107, 108, 109, 110, 113, 114, 115, 117, 118, 120, 121, 122, 123, 124, 127, 128, 130, 131, 133, 134, 135, 136, 137, 139, 140, 141, 142, 143, 144, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 158, 159, 160, 161, 162, 163, 164, 166, 167, 169, 170, 171, 172, 174, 175, 177, 178, 179, 181, 182, 184, 185, 187, 189, 190, 192, 193 ]
        // B : 1
        rotatedSortedArraySearch obj = new rotatedSortedArraySearch();
        List<Integer> A = List.of(194, 195, 196, 197, 198, 199, 201, 203, 204, 1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 13, 14, 15, 16, 17, 18, 20, 21, 22, 23, 24, 25, 26, 27, 29, 30, 31, 32, 33, 34, 35, 36, 37, 39, 40, 42, 43, 44, 45, 47, 48, 49, 50, 51, 52, 53, 54, 55, 57, 58, 59, 60, 61, 63, 65, 66, 68, 69, 70, 71, 73, 74, 76, 77, 79, 80, 81, 82, 83, 84, 86, 87, 88, 89, 91, 92, 93, 94, 95, 97, 98, 99, 101, 103, 104, 105, 106, 107, 108, 109, 110, 113, 114, 115, 117, 118, 120, 121, 122, 123, 124, 127, 128, 130, 131, 133, 134, 135, 136, 137, 139, 140, 141, 142, 143, 144, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 158, 159, 160, 161, 162, 163, 164, 166, 167, 169, 170, 171, 172, 174, 175, 177, 178, 179, 181, 182, 184, 185, 187, 189, 190, 192, 193);
        int B = 1;
        int result = obj.search(A, B);
        System.out.println("Index of " + B + " is: " + result);
    }
}
