package LinkedList;

public class insertionSortList {
    public ListNode insertionSortList(ListNode A) {
        if (A == null || A.next == null) {
            return A;
        }
        int val;
        ListNode headNode = new ListNode(Integer.MIN_VALUE), currNode = headNode, prevNode = null, tempNode;
        while (A != null) {
            currNode = headNode;
            val = A.val;
            while (currNode != null && currNode.val < val) {
                prevNode = currNode;
                currNode = currNode.next;
            }
            tempNode = currNode;
            currNode = new ListNode(val);
            currNode.next = tempNode;
            prevNode.next = currNode;
            A = A.next;
        }
        return headNode.next;
    }
    public static void main(String[] args) {
        // Create a linked list: 4 -> 2 -> 1 -> 3
        ListNode head = new ListNode(4);
        head.next = new ListNode(2);
        head.next.next = new ListNode(1);
        head.next.next.next = new ListNode(3);

        // Sort the linked list
        insertionSortList obj = new insertionSortList();
        ListNode sortedHead = obj.insertionSortList(head);

        // Print the sorted linked list
        while (sortedHead != null) {
            System.out.print(sortedHead.val + " -> ");
            sortedHead = sortedHead.next;
        }
    }
}
