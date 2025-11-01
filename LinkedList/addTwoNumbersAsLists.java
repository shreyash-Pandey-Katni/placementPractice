package LinkedList;

public class addTwoNumbersAsLists {
    public ListNode addTwoNumbers(ListNode A, ListNode B) {
        int carry = 0;
        ListNode dummyHead = new ListNode(0);
        ListNode current = dummyHead;
        while (A != null || B != null || carry != 0) {
            int sum = carry;
            if (A != null) {
                sum += A.val;
                A = A.next;
            }
            if (B != null) {
                sum += B.val;
                B = B.next;
            }
            carry = sum / 10;
            current.next = new ListNode(sum % 10);
            current = current.next;
        }
        return dummyHead.next;
    }
}
