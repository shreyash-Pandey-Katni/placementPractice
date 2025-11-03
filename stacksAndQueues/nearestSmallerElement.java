package stacksAndQueues;

import java.util.ArrayList;
import java.util.Stack;

public class nearestSmallerElement {
    public ArrayList<Integer> prevSmaller(ArrayList<Integer> A) {
        int n = A.size();
        ArrayList<Integer> res = new ArrayList<>();
        Stack<Integer> stack = new Stack<>();
        for (int i = 0; i < n; i++) {
            while(!stack.isEmpty() && stack.peek() >= A.get(i)) stack.pop();
            if (stack.isEmpty()) {
                res.add(-1);
            } else {
                res.add(stack.peek());
            }
            stack.push(A.get(i));
        }
        return res;
    }
}
