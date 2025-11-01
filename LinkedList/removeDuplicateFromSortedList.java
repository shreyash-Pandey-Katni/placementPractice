package LinkedList;

public class removeDuplicateFromSortedList {
    public ListNode deleteDuplicates(ListNode A) {
        if (A == null || A.next == null) {
            return A;
        }
        ListNode currNode = A;
        while (currNode != null && currNode.next != null) {
            if (currNode.val == currNode.next.val) {
                currNode.next = currNode.next.next;
            } else {
                currNode = currNode.next;
            }
        }
        return A;
    }
}
