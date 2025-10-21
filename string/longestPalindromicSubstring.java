package string;

public class longestPalindromicSubstring {
    private int start = 0, maxLength = 0;
    private void expandAroundCenter(String A, int left, int right){
        while (left>=0 && right<A.length() && A.charAt(left) == A.charAt(right)) {
            left--;
            right++;
        }
        int currentLength = (right-1) - (left+1) + 1;
        if (currentLength>maxLength) {
            maxLength = currentLength;
            start = left+1;
        }
    }
    public String longestPalindrome(String A) {
        if (A == null || A.isEmpty()) {
            return A;
        }
        start = 0;
        maxLength = 0;
        for (int i = 0; i < A.length(); i++) {
            expandAroundCenter(A, i, i);
            expandAroundCenter(A, i, i+1);
        }
        return A.substring(start, start+maxLength);
    }
    public static void main(String[] args) {
        String A = "aaaabaaa";
        longestPalindromicSubstring obj = new longestPalindromicSubstring();
        System.out.println(obj.longestPalindrome(A));
    }
}
