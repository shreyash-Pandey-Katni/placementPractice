package LinkedList;

import java.util.List;

public class reorderList {
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
    public ListNode reorderList(ListNode A) {
        if (A == null || A.next == null) {
            return A;
        }
        // Find middle using slow/fast pointer
        ListNode slow = A, fast = A, prev = null;
        while (fast != null && fast.next != null) {
            fast = fast.next.next;
            slow = slow.next;
        }
        // If odd length, skip middle element
        ListNode second = slow;
        ListNode first = A;
        // Unlink first half from second half
        prev = null;
        ListNode curr = A;
        while (curr != slow) {
            prev = curr;
            curr = curr.next;
        }
        if (prev != null) {
            prev.next = null;
        }
        // Reverse second half
        second = reverseList(second);
        ListNode currNode = null;
        // Merge reversed first half with second half
        while (first != null && second != null) {
            ListNode temp1 = first.next;
            ListNode temp2 = second.next;
            first.next = second;
            if (temp1 == null) {
                break;
            }
            second.next = temp1;
            first = temp1;
            second = temp2;
            currNode = temp1;
        }
        if (second != null && currNode != null) {
            currNode.next = second;
        }
        return A;
    }
    public static void main(String[] args) {
        // A : [ 90 -> 94 -> 25 -> 51 -> 45 -> 29 -> 55 -> 63 -> 48 -> 27 -> 72 -> 10 -> 36 -> 68 -> 16 -> 20 -> 31 -> 7 -> 95 -> 70 -> 89 -> 23 -> 22 -> 9 -> 74 -> 71 -> 35 -> 5 -> 80 -> 11 -> 49 -> 92 -> 69 -> 6 -> 37 -> 84 -> 78 -> 28 -> 43 -> 64 -> 96 -> 57 -> 83 -> 13 -> 73 -> 97 -> 75 -> 59 -> 53 -> 52 -> 19 -> 18 -> 98 -> 12 -> 81 -> 24 -> 15 -> 60 -> 79 -> 34 -> 1 -> 54 -> 93 -> 65 -> 44 -> 4 -> 87 -> 14 -> 67 -> 26 -> 30 -> 77 -> 58 -> 85 -> 33 -> 21 -> 46 -> 82 -> 76 -> 88 -> 66 -> 101 -> 61 -> 47 -> 8 ]
        int[] values = {90, 94, 25, 51, 45, 29, 55, 63, 48, 27, 72, 10, 36, 68, 16, 20, 31, 7, 95, 70, 89, 23, 22, 9, 74, 71, 35, 5, 80, 11, 49, 92, 69, 6, 37, 84, 78, 28, 43, 64, 96, 57, 83, 13, 73, 97, 75, 59, 53, 52, 19, 18, 98, 12, 81, 24, 15, 60, 79, 34, 1, 54, 93, 65, 44, 4, 87, 14, 67, 26, 30, 77, 58, 85, 33, 21, 46, 82, 76, 88, 66, 101, 61, 47, 8};
        ListNode head = new ListNode(values[0]);
        ListNode curr = head;
        for (int i = 1; i < values.length; i++) {
            curr.next = new ListNode(values[i]);
            curr = curr.next;
        }
        reorderList solution = new reorderList();
        ListNode newHead = solution.reorderList(head);
        while (newHead != null) {
            System.out.print(newHead.val + "->");
            newHead = newHead.next;
        }
        System.out.println("null");
    }
}
