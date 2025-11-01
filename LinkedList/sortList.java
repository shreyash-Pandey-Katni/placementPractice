package LinkedList;

public class sortList {
    private ListNode findMiddleNode(ListNode A){
        ListNode slowListNode = A, fastListNode = A;
        while (fastListNode.next !=null && fastListNode.next.next != null) {
            slowListNode = slowListNode.next;
            fastListNode = fastListNode.next.next;
        }
        return slowListNode;
    }

    private ListNode mergeListNodes(ListNode A, ListNode B){
        if (A == null) {
            return B;
        } else if (B == null) {
            return A;
        }
        ListNode head = new ListNode(0), currNode = head;
        while (A != null && B != null) {
            if (A.val < B.val) {
                currNode.next = A;
                A = A.next;
            } else {
                currNode.next = B;
                B = B.next;
            }
            currNode = currNode.next;
        }
        while (A != null) {
            currNode.next = A;
            A = A.next;
            currNode = currNode.next;
        }
        while (B != null) {
            currNode.next = B;
            B = B.next;
            currNode = currNode.next;
        }
        return head.next;
    }

    public ListNode sortList(ListNode A) {
        if (A == null || A.next == null) {
            return A;
        }
        ListNode mid = findMiddleNode(A);
        ListNode rightHeadNode = mid.next;
        mid.next = null;
        ListNode leftSortedList = sortList(A);
        ListNode rightSortedList = sortList(rightHeadNode);
        return mergeListNodes(leftSortedList, rightSortedList);
    }
    public static void main(String[] args) {
        sortList obj = new sortList();
        ListNode head = new ListNode(4);
        head.next = new ListNode(2);
        head.next.next = new ListNode(1);
        head.next.next.next = new ListNode(3);

        ListNode sortedHead = obj.sortList(head);
        while (sortedHead != null) {
            System.out.print(sortedHead.val + " ");
            sortedHead = sortedHead.next;
        }
    }
}
