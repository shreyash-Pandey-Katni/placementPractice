package binarySearch;

import java.util.List;

public class countElementOccurence {

    private int binarySearch(final List<Integer> A, int B, int upperBound, int lowerBound) {
        if (upperBound < lowerBound)
            return -1;
        int mid = (upperBound + lowerBound) / 2;
        if (A.get(mid) == B) {
            return mid;
        } else if (A.get(mid) > B) {
            return binarySearch(A, B, mid - 1, lowerBound);
        }
        return binarySearch(A, B, upperBound, mid + 1);
    }

    public int findCount(final List<Integer> A, int B) {
        int lengthOfA = A.size();
        int pos = binarySearch(A, B, lengthOfA - 1, 0);
        int res = 0;
        if (pos != -1) {
            int i = 1;
            res += 1;
            while (pos + i < lengthOfA && pos - i >= 0 && A.get(pos + i) == B && A.get(pos - i) == B) {
                i++;
                res += 2;
            }
            while (pos + i < lengthOfA && A.get(pos + i) == B) {
                i++;
                res++;
            }
            while (pos - i >= 0 && A.get(pos - i) == B) {
                i++;
                res++;
            }
        }
        return res;
    }
}
