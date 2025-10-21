package string;

public class reverseTheString {
    public String solve(String A) {
        String[] words = A.split(" ");
        StringBuilder reversedString = new StringBuilder();
        for (int i = words.length - 1; i >= 0; i--) {
            if (!words[i].isEmpty()) {
                reversedString.append(words[i]);
                if (i != 0) {
                    reversedString.append(" ");
                }
            }
        }
        for (int i = reversedString.length() - 1; i >= 0; i--) {
            if (reversedString.charAt(i) == ' ') {
                reversedString.deleteCharAt(i);
            } else {
                break;
            }
        }
        return reversedString.toString();
    }
    public static void main(String[] args) {
        reverseTheString obj = new reverseTheString();
        String test1 = "  Hello   World  ";
        System.out.println("Reversed string of '" + test1 + "': '" + obj.solve(test1) + "'"); // Expected: 'World Hello'

        String test2 = "   ";
        System.out.println("Reversed string of '" + test2 + "': '" + obj.solve(test2) + "'"); // Expected: ''
    }
}
