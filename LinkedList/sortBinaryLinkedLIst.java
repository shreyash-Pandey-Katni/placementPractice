package LinkedList;

public class sortBinaryLinkedLIst {
    public ListNode solve(ListNode A) {
        if(A == null) return null;
        ListNode curr = A, zeroHeadNode = new ListNode(0), onesHeadNode = new ListNode(1), zeros = zeroHeadNode, ones = onesHeadNode;
        while (curr != null) {
            if (curr.val == 0){
                zeros.next = curr;
                zeros = zeros.next;
            } else {
                ones.next = curr;
                ones = ones.next;
            }
            curr = curr.next;
        }
        ones.next = null;
        zeros.next = onesHeadNode.next;
        return zeroHeadNode.next;
    }
}
