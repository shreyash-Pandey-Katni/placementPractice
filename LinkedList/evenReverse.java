package LinkedList;

public class evenReverse {
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

    public ListNode solve(ListNode A) {
        ListNode currNode = A, oddNodeHead = new ListNode(0), oddNode = oddNodeHead, evenNodeHead = new ListNode(0),
                evenNode = evenNodeHead;
        int count = 1;
        while (currNode != null) {
            if (count % 2 != 0) {
                oddNode.next = currNode;
                oddNode = oddNode.next;
            } else {
                evenNode.next = currNode;
                evenNode = evenNode.next;
            }
            currNode = currNode.next;
            count++;
        }
        oddNode.next = null;
        evenNode.next = null;
        evenNodeHead = reverseList(evenNodeHead.next);
        oddNodeHead = oddNodeHead.next;
        ListNode res = new ListNode(0), curr = res;
        while (oddNodeHead != null && evenNodeHead != null) {
            ListNode tempOdd = oddNodeHead.next;
            ListNode tempEven = evenNodeHead.next;
            curr.next = oddNodeHead;
            curr = curr.next;
            curr.next = evenNodeHead;
            curr = curr.next;
            oddNodeHead = tempOdd;
            evenNodeHead = tempEven;
        }
        if (oddNodeHead != null) {
            curr.next = oddNodeHead;
            curr = curr.next;
        }
        curr.next = null;
        return res.next;
    }
    public static void main(String[] args) {
        ListNode head = new ListNode(1);
        head.next = new ListNode(2);
        head.next.next = new ListNode(3);
        head.next.next.next = new ListNode(4);
        head.next.next.next.next = new ListNode(5);
        evenReverse obj = new evenReverse();
        ListNode result = obj.solve(head);
        while (result != null) {
            System.out.print(result.val + " ");
            result = result.next;
        }
    }
}
