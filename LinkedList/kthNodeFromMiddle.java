package LinkedList;

public class kthNodeFromMiddle {
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

    public int solve(ListNode A, int B) {
        if (A == null || B <0) {
            return -1;
        }
        int count = 0;
        ListNode currNode = A;
        while (currNode != null) {
            currNode = currNode.next;
            count++;
        }
        int middleNodeIndex = (count / 2) + 1;
        int target = middleNodeIndex-B;
        if (target<0) {
            return -1;
        }
        currNode = A;
        for (int i = 0; i < target; i++) {
            currNode = currNode.next;
        }
        return currNode.val;
    }
    public static void main(String[] args) {
        // A : [ 725 -> 479 -> 359 -> 963 -> 465 -> 706 -> 146 -> 282 -> 828 -> 962 ]
        // B : 2
        ListNode head = new ListNode(725);
        // head.next = new ListNode(479);
        // head.next.next = new ListNode(359);
        // head.next.next.next = new ListNode(963);
        // head.next.next.next.next = new ListNode(465);
        // head.next.next.next.next.next = new ListNode(706);
        // head.next.next.next.next.next.next = new ListNode(146);
        // head.next.next.next.next.next.next.next = new ListNode(282);
        // head.next.next.next.next.next.next.next.next = new ListNode(828);
        // head.next.next.next.next.next.next.next.next.next = new ListNode(962);
        int k = 1;
        kthNodeFromMiddle obj = new kthNodeFromMiddle();
        System.out.println(obj.solve(head, k));
    }
}
