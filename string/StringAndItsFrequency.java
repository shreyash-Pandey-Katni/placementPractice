package string;

import java.util.HashMap;

public class StringAndItsFrequency {
    public String solve(String A) {
        int[][] charFrequency = new int[26][2];
        int lastFilledLocation = -1;
        HashMap<Character, Integer> characterLocationHashMap = new HashMap<>();
        for (char character : A.toCharArray()) {
            if (characterLocationHashMap.containsKey(character)) {
                charFrequency[characterLocationHashMap.get(character)][1]++;
            } else {
                charFrequency[++lastFilledLocation][0] = character;
                charFrequency[lastFilledLocation][1] = 1;
                characterLocationHashMap.put(character, lastFilledLocation);
            }
        }
        StringBuilder stringBuilder = new StringBuilder();
        for (int i = 0; i < charFrequency.length && charFrequency[i][0] != 0; i++) {
            stringBuilder.append((char) charFrequency[i][0]);
            stringBuilder.append(String.valueOf(charFrequency[i][1]));
        }
        return stringBuilder.toString();
    }
    public static void main(String[] args) {
        StringAndItsFrequency obj = new StringAndItsFrequency();
        System.out.println(obj.solve("abbhuabcfghh")); // Expected: a2b3h3u1c1f1g1
        System.out.println(obj.solve("a"));  
    }
}
