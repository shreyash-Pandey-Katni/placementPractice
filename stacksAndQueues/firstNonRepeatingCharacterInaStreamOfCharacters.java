package stacksAndQueues;

import java.util.Queue;

public class firstNonRepeatingCharacterInaStreamOfCharacters {
    public String solve(String A) {
        int[] charCount = new int[26];
        StringBuilder result = new StringBuilder();
        Queue<Character> queue = new java.util.LinkedList<>();
        for (int i = 0; i < A.length(); i++) {
            char currentChar = A.charAt(i);
            charCount[currentChar - 'a']++;
            queue.add(currentChar);
            while (!queue.isEmpty() && charCount[queue.peek() - 'a'] > 1) {
                queue.poll();
            }
            if (!queue.isEmpty()) {
                result.append(queue.peek());
            } else {
                result.append('#');
            }
        }
        return result.toString();
    }
}
