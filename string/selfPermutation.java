package string;

public class selfPermutation {
    public int permuteStrings(String A, String B) {
        int[] countA = new int[26], countB = new int[26];
        int lengthA = A.length(), lengthB = B.length();
        if (lengthA != lengthB) {
            return 0;
        }
        for (int i = 0; i < lengthA; i++) {
            countA[A.charAt(i) - 'a']++;
            countB[B.charAt(i) - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (countA[i] != countB[i]) {
                return 0;
            }
        }
        return 1;
    }
}
