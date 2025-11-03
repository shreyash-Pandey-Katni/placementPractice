package stacksAndQueues;

import java.util.Stack;

public class redundantBraces {
    public int braces(String A) {
        Stack<Character> characters = new Stack<>();
        int length = A.length();
        for (int i = 0; i < length; i++) {
            char currentChar = A.charAt(i);
            if (currentChar == '(' || currentChar == '+' || currentChar == '-' || currentChar == '*' || currentChar =='/') {
                characters.push(currentChar);
            } else if (currentChar == ')') {
                if (characters.peek() == '(') {
                    return 1;
                } else {
                    while (characters.peek() != '(') {
                        characters.pop();
                    }
                    characters.pop();
                }
            }
        }
        return 0;
    }
}
