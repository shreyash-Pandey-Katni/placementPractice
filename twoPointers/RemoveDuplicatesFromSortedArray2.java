package twoPointers;

import java.util.ArrayList;

public class RemoveDuplicatesFromSortedArray2 {
    public int removeDuplicates(ArrayList<Integer> a) {
        int i = 0, firstIndex = 0, n = a.size(), currentValue = -1, writeIndex = 0;
        while (i<n) {
            if (currentValue != a.get(i)) {
                currentValue = a.get(i);
                firstIndex = i;
                a.set(writeIndex++, currentValue);
            } else {
                if (i-firstIndex<2) {
                    a.set(writeIndex++, currentValue);
                }
            }
            i++;
        }
        a.subList(writeIndex, a.size()).clear();
        return writeIndex ;
    }
    public static void main(String[] args) {
        RemoveDuplicatesFromSortedArray2 obj = new RemoveDuplicatesFromSortedArray2();
        ArrayList<Integer> A = new ArrayList<>();
        // A.add(1);
        // A.add(1);
        // A.add(1);
        // A.add(2);
        // A.add(2);
        // A.add(3);
        A.add(0);
        System.out.println(obj.removeDuplicates(A));
    }
}
