package string;

public class bullsAndCows {
    public String solve(String A, String B) {
        int bulls = 0;
        int cows = 0;
        int n = A.length();
        int[] secretCount = new int[10];
        int[] guessCount = new int[10];
        for (int i = 0; i < n; i++) {
            char secretChar = A.charAt(i), guessChar = B.charAt(i);
            if (secretChar == guessChar) {
                bulls++;
            } else {
                secretCount[secretChar - '0']++;
                guessCount[guessChar - '0']++;
            }
        }
        for (int i = 0; i < 10; i++) {
            cows += Math.min(secretCount[i], guessCount[i]);
        }
        return String.valueOf(bulls) + "A" + String.valueOf(cows) + "B";
    }
}
