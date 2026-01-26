package backtracking;

import java.util.ArrayList;

public class allPossibleCombinations {
    public ArrayList<String> combinations;

    private void generateStrings(int target, int index, ArrayList<String> result, ArrayList<String> A, StringBuilder stringBuilder){
        if (stringBuilder.length() == target) {
            result.add(stringBuilder.toString());
            return;
        }
        String currentString = A.get(index);
        for (int i = 0; i < currentString.length(); i++) {
            stringBuilder.append(currentString.charAt(i));
            generateStrings(target, index+1, result, A, stringBuilder);
            stringBuilder.deleteCharAt(stringBuilder.length()-1);
        }
    }

    public ArrayList<String> specialStrings(ArrayList<String> A) {
        int n = A.size();
        ArrayList<String> res = new ArrayList<>();
        generateStrings(n, 0, res, A, new StringBuilder());
        return res;
    }
}
