package LinkedList;

public class removeNthNodeFromListEnd {
    public ListNode removeNthFromEnd(ListNode A, int B) {
        ListNode headNode = A;
        ListNode fastListNode = headNode, slowListNode = headNode;
        for (int i = 0; i <= B; i++) {
            if (fastListNode == null) {
                return A.next;
            }
            fastListNode = fastListNode.next;
        }
        while (fastListNode!=null) {
            fastListNode = fastListNode.next;
            slowListNode = slowListNode.next;
        }
        if (slowListNode.next != null)
        slowListNode.next = slowListNode.next.next;
        return headNode;
    }
    public static void main(String[] args) {
        ListNode head = new ListNode(1);
        int B = 1;
        ListNode result = new removeNthNodeFromListEnd().removeNthFromEnd(head, B);
        while (result != null) {
            System.out.print(result.val + " ");
            result = result.next;
        }
    }
}
