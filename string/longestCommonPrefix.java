package string;

import java.util.ArrayList;

public class longestCommonPrefix {
    public String longestCommonPrefix(ArrayList<String> A) {
        if (A == null || A.isEmpty()) {
            return "";
        } else if(A.size() == 1){
            return A.get(0);
        }
        String firstSring = A.get(0);
        for (int i = 0; i < firstSring.length(); i++) {
            char currentChar = firstSring.charAt(i);
            for (int j = 1; j < A.size(); j++) {
                String currentString = A.get(j);
                if (i >= currentString.length() || currentString.charAt(i) != currentChar) {
                    return firstSring.substring(0, i);
                }
            }
        }
        return firstSring;
    }
    public static void main(String[] args) {
        longestCommonPrefix obj = new longestCommonPrefix();
        
        // Test case 1
        ArrayList<String> test1 = new ArrayList<>();
        test1.add("abcdefgh");
        test1.add("aefghijk");
        test1.add("abcefgh");
        System.out.println("Test 1: " + obj.longestCommonPrefix(test1)); // Expected: "a"
        
        // Test case 2
        ArrayList<String> test2 = new ArrayList<>();
        test2.add("abab");
        test2.add("ab");
        test2.add("abcd");
        System.out.println("Test 2: " + obj.longestCommonPrefix(test2)); // Expected: "ab"
        
        // Edge case: empty array
        ArrayList<String> test3 = new ArrayList<>();
        System.out.println("Test 3: " + obj.longestCommonPrefix(test3)); // Expected: ""
    }
}
