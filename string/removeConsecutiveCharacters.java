package string;

public class removeConsecutiveCharacters {
    public String solve(String A, int B) {
        int changeIndex=-1;
        if (A.isEmpty() || B == 0) {
            return A;
        }
        StringBuilder stringBuilder = new StringBuilder();
        int i = 0;
        int n = A.length();
        while (i<n) {
            char current = A.charAt(i);
            int startIndex = i++;
            while (i<n && A.charAt(i) == current) {
                i++;
            }
            if (i-startIndex != B) {
                stringBuilder.append(A.substring(startIndex, i));
            }
        }
        return stringBuilder.toString();
    }
    public static void main(String[] args) {
        removeConsecutiveCharacters obj = new removeConsecutiveCharacters();
        System.out.println(obj.solve("aabcd", 2));   // Expected: "bcd"
        System.out.println(obj.solve("aabbccd", 2));
    }
}
