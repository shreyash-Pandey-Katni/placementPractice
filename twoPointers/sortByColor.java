package twoPointers;

import java.util.ArrayList;

public class sortByColor {
    public void sortColors(ArrayList<Integer> a) {
        int n = a.size(), i = 0, j = 0, k = 0, current;
        for (int l = 0; l < n; l++) {
            current = a.get(l);
            switch (current) {
                case 0:
                    i++;
                    break;
                case 1:
                    j++;
                    break;
                case 2:
                    k++;
                    break;
                default:
                    break;
            }
        }
        for (int l = 0; l < i; l++) {
            a.set(l, 0);
        }
        for (int l = i; l < j+i; l++) {
            a.set(l, 1);
        }
        for (int l = i+j; l < i+j+k; l++) {
            a.set(l, 2);
        }
    }
}
