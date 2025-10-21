package string;

import java.util.ArrayList;

public class justifiedText {
    private boolean isWithinLimit(ArrayList<String> currentRow, int limit){
        int currentLength = 0;
        for (String word : currentRow) {
            currentLength += word.length();
        }
        currentLength += currentRow.size() - 1; // spaces between words
        return currentLength <= limit;
    }
    private String generateString(ArrayList<String> currentRow, int limit, boolean isLastLine){
        if (isLastLine || currentRow.size() == 1) {
            StringBuilder line = new StringBuilder();
            for (int i = 0; i < currentRow.size(); i++) {
                line.append(currentRow.get(i));
                if (i != currentRow.size() - 1) {
                    line.append(" ");
                }
            }
            while (line.length() < limit) {
                line.append(" ");
            }
            return line.toString();
            
        }
        int remainingLimit = limit;
        for (String word : currentRow) {
            remainingLimit -= word.length();
        }
        int gaps = currentRow.size() - 1;
        StringBuilder justifiedLine = new StringBuilder(currentRow.get(0));
        int baseSpaces = gaps == 0 ? remainingLimit : remainingLimit / gaps;
        int extraSpaces = gaps == 0 ? 0 : remainingLimit % gaps;
        for (int i = 0; i < gaps; i++) {
            int spacesToAdd = baseSpaces + (i < extraSpaces ? 1 : 0);
            for (int s = 0; s < spacesToAdd; s++) {
                justifiedLine.append(" ");
            }
            justifiedLine.append(currentRow.get(i + 1));
            remainingLimit -= spacesToAdd;
        }
        if (remainingLimit > 0) {
            for (int s = 0; s < remainingLimit; s++) {
                justifiedLine.append(" ");
            }
        }
        return justifiedLine.toString();
    }
    public ArrayList<String> fullJustify(ArrayList<String> A, int B) {
        ArrayList<String> lastRow = new ArrayList<>();
        int n = A.size();
        ArrayList<String> res = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String word = A.get(i);
            lastRow.add(word);
            if (!isWithinLimit(lastRow, B)) {
                lastRow.remove(lastRow.size() - 1);
                res.add(generateString(lastRow, B, false));
                lastRow = new ArrayList<>();
                lastRow.add(word);
            }
        }
        if (!lastRow.isEmpty()) {
            res.add(generateString(lastRow, B, true));
        }
        return res;
    }
    public static void main(String[] args) {
        justifiedText obj = new justifiedText();
        ArrayList<String> words = new ArrayList<>();
        // A : [ "What", "must", "be", "shall", "be." ]
        // B : 12
        
        words.add("What");
        words.add("must");
        words.add("be");
        words.add("shall");
        words.add("be.");

        int limit = 12;
        ArrayList<String> justifiedText = obj.fullJustify(words, limit);
        for (String line : justifiedText) {
            System.out.println("'" + line + "'");
        }
    }
}
