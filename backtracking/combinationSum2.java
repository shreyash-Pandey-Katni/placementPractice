package backtracking;

import java.util.ArrayList;
import java.util.Collections;

public class combinationSum2 {
    private void backtrack(int index, int target, ArrayList<Integer> temp, ArrayList<ArrayList<Integer>> result, ArrayList<Integer> A){
        if (target == 0 && !result.contains(temp)) {
            result.add(new ArrayList<>(temp));
            return;
        } else if(target <0){
            return;
        }
        for (int i = index; i < A.size(); i++) {
            temp.add(A.get(i));
            backtrack(i+1, target-A.get(i), temp, result, A);
            temp.remove(temp.size()-1);
        }
    }
    public ArrayList<ArrayList<Integer>> combinationSum(ArrayList<Integer> a, int b) {
        Collections.sort(a);
        ArrayList<ArrayList<Integer>> result = new ArrayList<>();
        backtrack(0, b, new ArrayList<>(), result, a);
        return result;
    }
    public static void main(String[] args) {
        combinationSum2 obj = new combinationSum2();
        ArrayList<Integer> A = new ArrayList<>();
        A.add(10);
        A.add(1);
        A.add(2);
        A.add(7);
        A.add(6);
        A.add(1);
        A.add(5);
        int B = 8;
        ArrayList<ArrayList<Integer>> result = obj.combinationSum(A, B);
        for (ArrayList<Integer> list : result) {
            System.out.println(list);
        }
    }
}
