package stacksAndQueues;

import java.util.ArrayList;
import java.util.Stack;

public class evaluateExpression {
    public int evalRPN(ArrayList<String> A) {
        Stack<Integer> numbers = new Stack<>();
        int n = A.size();
        String current;
        int res, temp;
        for (int i = 0; i < n; i++) {
            current = A.get(i);
            switch (current) {
                case "+":
                    temp = numbers.pop()+numbers.pop();
                    numbers.push(temp);
                    break;
                case "-":
                    temp = numbers.pop();
                    res = numbers.pop();
                    numbers.push(res - temp);
                    break;
                case "*":
                    temp = numbers.pop()*numbers.pop();
                    numbers.push(temp);
                    break;
                case "/":
                    temp = numbers.pop();
                    res = numbers.pop();
                    numbers.push(res/temp);
                    break;
                default:
                    numbers.push(Integer.parseInt(current));
                    break;
            }
        }
        return numbers.peek();
    }
    public static void main(String[] args) {
        
    }
}
