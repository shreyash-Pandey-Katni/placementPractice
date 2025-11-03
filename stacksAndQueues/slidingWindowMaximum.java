package stacksAndQueues;

import java.util.ArrayList;
import java.util.Deque;
import java.util.LinkedList;
import java.util.List;

public class slidingWindowMaximum {
    public ArrayList<Integer> slidingMaximum(final List<Integer> A, int B) {

        ArrayList<Integer> res = new ArrayList<>();
        if (B == 1) {
            res.addAll(A);
            return res;
        }
        Deque<Integer> deque = new LinkedList<>();
        for (int i = 0; i < A.size(); i++) {
            while (!deque.isEmpty() && deque.getFirst() <= i-B) {
                deque.removeFirst();
            }
            while (!deque.isEmpty() && A.get(deque.getLast()) < A.get(i)) {
                deque.removeLast();
            }
            deque.addLast(i);
            if (i>=B-1) {
                res.add(A.get(deque.getFirst()));
            }
        }
        return res;
    }
}
