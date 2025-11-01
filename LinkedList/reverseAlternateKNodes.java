package LinkedList;

public class reverseAlternateKNodes {
    public ListNode solve(ListNode A, int B) {
        if (A == null || B <= 1) {
            return A;
        }
        int count = 0;
        ListNode head = A, currNode = head, temp, prev = null;
        while (currNode != null && count++ < B) {
            temp = currNode.next;
            currNode.next = prev;
            prev = currNode;
            currNode = temp;
        }
        A.next = currNode;
        count = 0;
        while (currNode != null && count++ < B-1) {
            currNode = currNode.next;
        }
        if (currNode != null && currNode.next != null) {
            currNode.next = solve(currNode.next, B);
        }
        return prev;
    }
    public static void main(String[] args) {
        ListNode head = new ListNode(1);
        head.next = new ListNode(2);
        head.next.next = new ListNode(3);
        head.next.next.next = new ListNode(4);
        head.next.next.next.next = new ListNode(5);
        head.next.next.next.next.next = new ListNode(6);
        head.next.next.next.next.next.next = new ListNode(7);
        head.next.next.next.next.next.next.next = new ListNode(8);
        head.next.next.next.next.next.next.next.next = new ListNode(9);
        head.next.next.next.next.next.next.next.next.next = new ListNode(10);
        head.next.next.next.next.next.next.next.next.next.next = new ListNode(11);
        head.next.next.next.next.next.next.next.next.next.next.next = new ListNode(12);
        head.next.next.next.next.next.next.next.next.next.next.next.next = new ListNode(13);
        head.next.next.next.next.next.next.next.next.next.next.next.next.next = new ListNode(14);
        head.next.next.next.next.next.next.next.next.next.next.next.next.next.next = new ListNode(15);

        reverseAlternateKNodes solution = new reverseAlternateKNodes();
        ListNode newHead = solution.solve(head, 3);
        while (newHead != null) {
            System.out.print(newHead.val + " ");
            newHead = newHead.next;
        }
    }
}
