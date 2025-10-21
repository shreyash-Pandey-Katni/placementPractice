package string;

public class isPalindrome {
    public int isPalindrome(String A) {
        StringBuilder stringBuilder = new StringBuilder();
        for (char characters : A.toCharArray()) {
            if (Character.isLetterOrDigit(characters)) {
                stringBuilder.append(characters);
            }
        }
        A = stringBuilder.toString();
        int n = A.length();
        A = A.toLowerCase();
        for (int i = 0; i < n/2; i++) {
            if (A.charAt(i) != A.charAt(n-i-1)) {
                return 0;
            }
        }
        return 1;
    }
    public static void main(String[] args) {
        isPalindrome obj = new isPalindrome();
        System.out.println(obj.isPalindrome("\"")); // Should return 1
        System.out.println(obj.isPalindrome("race a car")); // Should return 0
    }
}
