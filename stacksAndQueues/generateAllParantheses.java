package stacksAndQueues;

import java.util.Stack;

public class generateAllParantheses {
    public int isValid(String A) {
        Stack<Character> characters = new Stack<>();
        for (int i = 0; i < A.length(); i++) {
            Character character = A.charAt(i);
            if (character == '(' || character == '{' || character == '[') {
                characters.push(character);
            } else {
                if (characters.isEmpty()) {
                    return 0;
                }
                Character topCharacter = characters.pop();
                if ((character == ')' && topCharacter != '(') ||
                        (character == '}' && topCharacter != '{') ||
                        (character == ']' && topCharacter != '[')) {
                    return 0;
                }
                
            }
        }
        return characters.isEmpty() ? 1 : 0;
    }
}
