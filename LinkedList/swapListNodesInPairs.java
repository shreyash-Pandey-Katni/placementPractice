package LinkedList;

public class swapListNodesInPairs {
    public ListNode reverseList(ListNode A) {
        ListNode prev = null, curr = A, temp;
        while (curr != null) {
            temp = curr.next;
            curr.next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    public ListNode reverseList(ListNode A, int B) {
        if (A == null || A.next == null) {
            return A;
        }
        ListNode curr = A, prev = null;
        int count = 0;
        while (curr != null && count < B) {
            curr = curr.next;
            count++;
        }
        if (count<B){
            return reverseList(prev);
        }
        prev = null;
        curr = A;
        ListNode next = null;
        count = 0;
        while (curr != null && count < B) {
            next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        if (next != null) {
            A.next = reverseList(next, B);
        }
        return prev;
    }
    public ListNode swapPairs(ListNode A) {
        return reverseList(A, 2);
    }
}
