package twoPointers;

import java.util.ArrayList;

public class RemoveDuplicatesFromSortedArray {
    public int removeDuplicates(ArrayList<Integer> a) {
        int i = 0;
        for (int j = 1; j < a.size(); j++) {
            if (!a.get(i).equals(a.get(j))) {
                i++;
                a.set(i, a.get(j));
            }
        }
        a.subList(i + 1, a.size()).clear();
        return i + 1;
    }
}
