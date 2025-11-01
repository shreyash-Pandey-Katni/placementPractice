package LinkedList;

public class reverseLinklist2 {
    public ListNode reverseBetween(ListNode A, int B, int C) {
        if (A == null || B >= C) {
            return A;
        }
        ListNode curr = A, prev = null;
        int position = 1;
        while (curr != null && position < B) {
            prev = curr;
            curr = curr.next;
            position++;
        }
        ListNode connection = prev;
        ListNode tail = curr;
        ListNode next = null;
        while (curr != null && position <= C) {
            next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
            position++;
        }
        if (connection != null) {
            connection.next = prev;
        } else {
            A = prev;
        }
        tail.next = curr;
        return A;
    }
}
