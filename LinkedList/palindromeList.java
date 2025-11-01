package LinkedList;

public class palindromeList {
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
    private ListNode findMiddleNode(ListNode A){
        ListNode slowListNode = A, fastListNode = A;
        while (fastListNode.next !=null && fastListNode.next.next != null) {
            slowListNode = slowListNode.next;
            fastListNode = fastListNode.next.next;
        }
        return slowListNode;
    }
    public int lPalin(ListNode A) {
        if (A.next == null) {
            return 1;
        }
        ListNode middleNode = findMiddleNode(A);
        ListNode rightHeadNode = middleNode.next;
        middleNode.next = null;
        ListNode reverseListNode = reverseList(rightHeadNode);
        while (A != null && reverseListNode != null) {
            if (A.val != reverseListNode.val) {
                return 0;
            }
            A = A.next;
            reverseListNode = reverseListNode.next;
        }
        return 1;
    }
}
