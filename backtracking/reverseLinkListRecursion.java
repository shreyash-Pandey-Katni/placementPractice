package backtracking;

public class reverseLinkListRecursion {
    public ListNode reverseList(ListNode A) {
        if (A == null || A.next == null) {
            return A;
        }
        ListNode newHeadNode = reverseList(A.next);
        A.next.next = A;
        A.next = null;
        return newHeadNode;
    }
}
