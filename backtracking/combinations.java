package backtracking;

import java.util.ArrayList;

public class combinations {

    private void backtrack(int start, int A, int B, ArrayList<Integer> current, ArrayList<ArrayList<Integer>> result){
        if (current.size() == B){
            result.add(new ArrayList<>(current));
            return;
        }
        for (int i = start; i<=A;i++){
            current.add(i);
            backtrack(i+1, A, B, current, result);
            current.remove(current.size()-1);
        }
    }

    public ArrayList<ArrayList<Integer>> combine(int A, int B) {
        ArrayList<ArrayList<Integer>> result = new ArrayList<>();
        backtrack(1, A, B, new ArrayList<>(), result);
        return result;
    }
}
