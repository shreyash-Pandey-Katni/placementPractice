package twoPointers;

import java.util.ArrayList;
import java.util.List;

public class intersectionOfSortedArrays {
    public ArrayList<Integer> intersect(final List<Integer> A, final List<Integer> B) {
        int i = 0, j = 0;
        ArrayList<Integer> result = new ArrayList<>();
        while (i < A.size() && j < B.size()) {
            if (A.get(i).equals(B.get(j))) {
                result.add(A.get(i));
                i++;
                j++;
            } else if (A.get(i) < B.get(j)) {
                i++;
            } else {
                j++;
            }
        }
        return result;
    }
}
