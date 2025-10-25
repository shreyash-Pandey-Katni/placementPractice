package twoPointers;

import java.util.ArrayList;

public class mergeTwoSortedLists2 {
    public void merge(ArrayList<Integer> a, ArrayList<Integer> b) {
        ArrayList<Integer> merged = new ArrayList<>();
        int i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            if (a.get(i) <= b.get(j)) {
                merged.add(a.get(i));
                i++;
            } else {
                merged.add(b.get(j));
                j++;
            }
        }
        while (i < a.size()) {
            merged.add(a.get(i));
            i++;
        }
        while (j < b.size()) {
            merged.add(b.get(j));
            j++;
        }
        a.clear();
        a.addAll(merged);
	}
}
