package string;

public class amazingSubarrays {
    int mod = 10003;
    public int solve(String A) {
        int n = A.length();
        int res = 0;
        for (int i = 0; i < n; i++) {
            char current = A.charAt(i);
            if (current == 'a' || current == 'e' || current == 'i' || current == 'o' || current == 'u' ||
                current == 'A' || current == 'E' || current == 'I' || current == 'O' || current == 'U') {
                res += (n - i)%mod;
                
            }
        }
        return res%mod;
    }
}
