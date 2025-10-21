package string;

public class convertToPalindrome {
    private boolean isPalindrome(String A, int start, int end){
        while (start < end) {
            if (A.charAt(start) != A.charAt(end)) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    public int solve(String A) {
        int left = 0, right = A.length() - 1;
        while (left<right) {
            if (A.charAt(left) == A.charAt(right)) {
                left++;
                right--;
            } else {
                if (isPalindrome(A, left+1, right) || isPalindrome(A, left, right-1)) {
                    return 1;
                } else {
                    return 0;
                }
            }
        }
        return 1;
    }
    public static void main(String[] args) {
        String A = "baccaba";
        convertToPalindrome obj = new convertToPalindrome();
        System.out.println(obj.solve(A));
    }
}
