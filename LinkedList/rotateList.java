package LinkedList;

public class rotateList {
    public ListNode rotateRight(ListNode A, int B) {
        if (A == null || A.next == null || B == 0) {
            return A;
        }
        ListNode curr = A, kthNode = null;
        int count = 1;
        while (curr.next != null) {
            curr = curr.next;
            count++;
        }
        int k = B%count;
        if (k == 0) {
            return A;
        }
        ListNode fastNode = A;
        for (int i = 0; i < k; i++) fastNode = fastNode.next;
        ListNode slowNode = A;
        while (fastNode.next != null) {
            slowNode = slowNode.next;
            fastNode = fastNode.next;
        }
        kthNode = slowNode;
        ListNode newHead = kthNode.next;
        kthNode.next = null;
        curr.next = A;
        return newHead;
    }
    public static void main(String[] args) {
        ListNode head = new ListNode(1);
        head.next = new ListNode(2);
        head.next.next = new ListNode(3);
        head.next.next.next = new ListNode(4);
        head.next.next.next.next = new ListNode(5);
        rotateList obj = new rotateList();
        ListNode result = obj.rotateRight(head, 2);
        while (result != null) {
            System.out.print(result.val + " ");
            result = result.next;
        }
    }
}
