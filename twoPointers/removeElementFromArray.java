package twoPointers;

import java.util.ArrayList;

public class removeElementFromArray {
    public int removeElement(ArrayList<Integer> a, int b) {
        int writeIndex = 0, n = a.size();
        for (int i = 0; i < n; i++) {
            if (a.get(i) != b) {
                a.set(writeIndex++, a.get(i));
            }
        }
        a.subList(writeIndex, a.size()).clear();
        return writeIndex;
	}
}
