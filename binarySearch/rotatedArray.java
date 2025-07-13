package binarySearch;

import java.util.List;

public class rotatedArray {
    public int findMin(final List<Integer> a) {
        int lower = 0, upper = a.size() - 1;
        int mid;
        while (lower < upper) {
            mid = (upper + lower) / 2;
            if (a.get(mid) < a.get(upper))
                upper = mid;
            else
                lower = mid + 1;
        }
        return a.get(lower);
    }
    public static void main(String[] args) {
        
    }
}
