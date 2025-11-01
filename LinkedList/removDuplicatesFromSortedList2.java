package LinkedList;

public class removDuplicatesFromSortedList2 {
    public ListNode deleteDuplicates(ListNode A) {
        if (A == null) {
            return A;
        }
        ListNode dummyNode = new ListNode(0);
        dummyNode.next = A;
        ListNode currNode = A, prevNode = dummyNode;
        int val;
        while (currNode != null) {
            if (currNode.next != null && currNode.val == currNode.next.val) {
                val = currNode.val;
                while (currNode != null && currNode.val == val) {
                    currNode = currNode.next;
                }
            } else {
                prevNode.next = currNode;
                prevNode = currNode;
                currNode = currNode.next;
            }
        }
        prevNode.next = null;
        return dummyNode.next;
    }
}
