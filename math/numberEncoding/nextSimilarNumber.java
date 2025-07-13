package math.numberEncoding;

import java.util.Arrays;

public class nextSimilarNumber {
    public String solve(String A) {
        int n = A.length();
        int max = A.charAt(n - 1);
        for (int i = n - 2; i > -1; i--) {
            if (max > A.charAt(i)) {
                // swapping
                for (int j = n - 1; j > i; j--) {
                    if (A.charAt(i) < A.charAt(j)) {
                        char[] characterArray = A.toCharArray();
                        char temp = characterArray[i];
                        characterArray[i] = characterArray[j];
                        characterArray[j] = temp;
                        A = new String(characterArray);
                        StringBuilder stringBuilder = new StringBuilder(A.substring(0, i+1));
                        characterArray = A.substring(i + 1).toCharArray();
                        Arrays.sort(characterArray);
                        stringBuilder.append(characterArray);                        
                        return stringBuilder.toString();
                    }
                }
            } else {
                max = A.charAt(i);
            }
        }
        return "-1";
    }

    public static void main(String[] args) {
        nextSimilarNumber n = new nextSimilarNumber();
        String A = "218765";
        String result = n.solve(A);
        System.out.println("The next similar number after " + A + " is: " + result); // Output should be 1243
    }
}
