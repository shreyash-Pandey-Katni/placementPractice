package stacksAndQueues;

import java.util.Stack;

public class balancedParantheses {
    public int solve(String A) {
        Stack<Character> characters = new Stack<>();
        for (int i = 0; i < A.length(); i++) {
            Character character = A.charAt(i);
            if (character == '(') {
                characters.push(character);
            } else {
                if (characters.isEmpty()) {
                    return 0;
                }
                characters.pop();
            }
        }
        return characters.isEmpty() ? 1 : 0;
    }
}
