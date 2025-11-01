package LinkedList;

public class intersectionOfTwoLinkedList {
    public ListNode getIntersectionNode(ListNode a, ListNode b) {
        if (a == null || b == null) {
            return null;
        }
        ListNode currA = a, currB = b;
        while (currA != currB) {
            currA = (currA == null)? b : currA.next;
            currB = (currB == null)?a: currB.next;
        }
        return currA;
	}
}
