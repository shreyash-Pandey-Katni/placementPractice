package backtracking;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;

public class combinationSum {
    
    private void backtrack(int index, int target, ArrayList<Integer> temp, ArrayList<ArrayList<Integer>> result, ArrayList<Integer> A){
        if (target == 0 && !result.contains(temp)) {
            result.add(new ArrayList<>(temp));
            return;
        } else if(target <0){
            return;
        }
        for (int i = index; i < A.size(); i++) {
            temp.add(A.get(i));
            backtrack(i, target-A.get(i), temp, result, A);
            temp.remove(temp.size()-1);
        }
    }

    public ArrayList<ArrayList<Integer>> combinationSum(ArrayList<Integer> A, int B) {
        Collections.sort(A);
        ArrayList<ArrayList<Integer>> result = new ArrayList<>();
        backtrack(0, B, new ArrayList<>(), result, A);
        return result;
    }
    public static void main(String[] args) {
        combinationSum cs = new combinationSum();
        ArrayList<Integer> A = new ArrayList<>();
        A.add(2);
        A.add(3);
        A.add(6);
        A.add(7);
        int B = 7;
        ArrayList<ArrayList<Integer>> result = cs.combinationSum(A, B);
        for (ArrayList<Integer> combination : result) {
            System.out.println(combination);
        }
    }
}
