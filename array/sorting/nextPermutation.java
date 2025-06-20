import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class nextPermutation {
    public ArrayList<Integer> getNextPermutation(ArrayList<Integer> A) {
        int n = A.size();
        boolean isSwapped = false;
        int swapIndex = -1;
        for (int i = n - 2; i >= 0; i--) {
            if (A.get(i) < A.get(i + 1)) {
                System.out.println("Found pivot at index " + i + " with value " + A.get(i));
                int swapElement = Integer.MAX_VALUE;
                for (int j = i + 1; j < n; j++) {
                    if (A.get(j) > A.get(i) && A.get(j) < swapElement) {
                        swapElement = A.get(j);
                        swapIndex = j;
                        isSwapped = true;
                        break;
                    }
                }
                if (isSwapped) {
                    System.out.println("Swapping " + A.get(i) + " with " + swapElement + " at index " + swapIndex);
                    A.set(swapIndex, A.get(i));
                    A.set(i, swapElement);
                    Collections.sort(A.subList(i + 1, n));
                    return A;
                }
            }
        }
        if (!isSwapped) {
            Collections.reverse(A);
            return A;
        }
        return A;
    }

    public static void main(String[] args) {
        ArrayList<Integer> A = new ArrayList<>();
        int[] testCase = { 251, 844, 767, 778, 658, 337, 10, 252, 632, 262, 707, 506, 701, 475, 410, 696, 631, 903, 516,
                149, 344, 101, 42, 891, 991 };
        for (int num : testCase) {
            A.add(num);
        }

        System.out.println("Input: " + A);
        nextPermutation np = new nextPermutation();
        ArrayList<Integer> result = np.getNextPermutation(A);
        System.out.println("Output: " + result);
    }
}
