package stacksAndQueues;

import java.util.ArrayList;
import java.util.Stack;

public class minStack {
    ArrayList<Integer> stack = new ArrayList<>();
    Stack<Integer> minVal = new Stack<>();
    public void push(int x) {
        stack.add(x);
        if (minVal.isEmpty() || minVal.peek() > x) {
            minVal.push(x);
        }
    }

    public void pop() {
        if (stack.size() == 0) {
            return;
        }
        int elem = stack.get(stack.size() - 1);
        if (minVal.peek() == elem) {
            minVal.pop();
        }
        stack.remove(stack.size() - 1);
    }

    public int top() {
        if (stack.size() == 0) {
            return -1;
        }
        return stack.get(stack.size()-1);
    }

    public int getMin() {
        if (minVal.isEmpty()) {
            return -1;
        }
        return minVal.peek();
    }
}
