package LinkedList;

import java.util.ArrayList;
import java.util.Arrays;

public class partitionList {
    public ListNode partition(ListNode A, int B) {
        ListNode lessThanNodeHead = new ListNode(0), lessthanNode = lessThanNodeHead,
                moreThanListNodeHead = new ListNode(1), morethanListNode = moreThanListNodeHead;
        while (A != null) {
            if (A.val < B) {
                lessthanNode.next = A;
                lessthanNode = lessthanNode.next;
            } else {
                morethanListNode.next = A;
                morethanListNode = morethanListNode.next;
            }
            A = A.next;
        }
        morethanListNode.next = null;
        if (lessThanNodeHead.next == null) {
            return moreThanListNodeHead.next;
        } else if (moreThanListNodeHead.next == null) {
            return lessThanNodeHead.next;
        }
        lessthanNode.next = moreThanListNodeHead.next;
        return lessThanNodeHead.next;
    }
    public static void main(String[] args) {
        // A : [ 401 -> 143 -> 654 -> 910 -> 559 -> 582 -> 332 -> 26 -> 914 -> 611 -> 13 -> 160 -> 883 -> 212 -> 100 -> 341 -> 999 -> 436 -> 95 -> 969 -> 210 -> 181 -> 318 -> 330 -> 753 -> 422 -> 180 -> 271 -> 127 -> 299 -> 10 ]
        // B : 88
        ArrayList<Integer> values = new ArrayList<>(Arrays.asList(401, 143, 654, 910, 559, 582, 332, 26, 914, 611, 13, 160, 883, 212, 100, 341, 999, 436, 95, 969, 210, 181, 318, 330, 753, 422, 180, 271, 127, 299, 10));
        ListNode head = new ListNode(values.get(0));
        ListNode current = head;
        for (int i = 1; i < values.size(); i++) {
            current.next = new ListNode(values.get(i));
            current = current.next;
        }
        int B = 88;
        partitionList obj = new partitionList();
        ListNode result = obj.partition(head, B);
        // Print the resulting linked list
        while (result != null) {
            System.out.print(result.val + " -> ");
            result = result.next;
        }
    }
}
