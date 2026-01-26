package backtracking;

import java.util.ArrayList;
import java.util.Collections;

public class subset2 {
    private void backtrack(ArrayList<ArrayList<Integer>> result, ArrayList<Integer> tempList, ArrayList<Integer> A, int start) {
        result.add(new ArrayList<>(tempList));
        for (int i = start; i < A.size(); i++) {
            if (i > start && A.get(i).equals(A.get(i - 1))) continue; // skip duplicates
            tempList.add(A.get(i));
            backtrack(result, tempList, A, i + 1);
            tempList.remove(tempList.size() - 1);
        }
    }
    public ArrayList<ArrayList<Integer>> subsetsWithDup(ArrayList<Integer> A) {
        Collections.sort(A);
        ArrayList<ArrayList<Integer>> result = new ArrayList<>();
        backtrack(result, new ArrayList<>(), A, 0);
        return result;
    }
}
