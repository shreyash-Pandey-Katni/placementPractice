package backtracking;

import java.util.ArrayList;
import java.util.Collections;

import javax.lang.model.util.Elements;

public class subset {
    // Given a set of distinct integers, A, return all possible subsets.

    // Note:
    // Elements in a subset must be in non-descending order.
    // The solution set must not contain duplicate subsets.
    // Also, the subsets should be sorted in ascending ( lexicographic ) order.
    // The list is not necessarily sorted.

    public ArrayList<ArrayList<Integer>> subsets(ArrayList<Integer> A) {
        // Sort A
        Collections.sort(A);
        ArrayList<ArrayList<Integer>> result = new ArrayList<>();
        backtrack(result, new ArrayList<>(), A, 0);
        return result;
    }

    private void backtrack(ArrayList<ArrayList<Integer>> result, ArrayList<Integer> tempList, ArrayList<Integer> A,
            int start) {
        result.add(new ArrayList<>(tempList));
        for (int i = start; i < A.size(); i++) {
            if (i > start && A.get(i).equals(A.get(i - 1)))
                continue; // Skip duplicates
            tempList.add(A.get(i));
            backtrack(result, tempList, A, i + 1);
            tempList.remove(tempList.size() - 1);
        }
    }
}
