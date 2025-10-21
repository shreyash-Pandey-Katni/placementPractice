package string;

public class lengthOfLastWord {
    public int lengthOfLastWord(final String A) {
        int end = A.length()-1;
        int start = 0;
        while (end>start && A.charAt(end) == ' ') {
            end--;
        }
        start = end;
        while (start>=0 && Character.isAlphabetic(A.charAt(start))) {
            start--;
        }
        return end-start;
    }
    public static void main(String[] args) {
        lengthOfLastWord obj = new lengthOfLastWord();
        String test1 = "Hello World  ";
        System.out.println("Length of last word in '" + test1 + "': " + obj.lengthOfLastWord(test1)); // Expected: 5

        String test2 = "   ";
        System.out.println("Length of last word in '" + test2 + "': " + obj.lengthOfLastWord(test2)); // Expected: 0
    }
}
