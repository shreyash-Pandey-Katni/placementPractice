package string;

public class VowelAndConsonantSubStrings {
    int MOD = 1_000_000_007;
    public int solve(String A) {
        long vowelCount = 0, consonantCount = 0, n = A.length();
        for (int i = 0; i < n; i++) {
            char current = A.charAt(i);
            if (current == 'a' || current == 'e' || current == 'i' || current == 'o' || current == 'u') {
                vowelCount++;
            } else {
                consonantCount++;
            }
        }
        return (int) ((vowelCount%MOD)*(consonantCount%MOD))%MOD;
    }
}
