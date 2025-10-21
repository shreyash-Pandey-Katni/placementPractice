package string;

public class minimumCharactersRequiredToMakeStringPalindromic {
    private int KMP(String A){
        int length = A.length();
        int len = 0;
        int[] lps = new int[length];
        lps[0] = 0;
        int i = 1;
        while (i<length) {
            if (A.charAt(i) == A.charAt(len)) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len-1];
                } else{
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps[length-1];
    }
    private String reverseString(String A){
        StringBuilder stringBuilder = new StringBuilder();
        int n = A.length();
        for (int i = n-1; i >= 0; i--) {
            stringBuilder.append(A.charAt(i));
        }
        return stringBuilder.toString();
    }
    public int solve(String A) {
        return A.length() - KMP(A+"#"+reverseString(A));
    }
    public static void main(String[] args) {
        String A = "ABC";
        minimumCharactersRequiredToMakeStringPalindromic obj = new minimumCharactersRequiredToMakeStringPalindromic();
        System.out.println(obj.solve(A));
    }
}
