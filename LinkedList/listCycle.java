package LinkedList;

public class listCycle {
    public ListNode detectCycle(ListNode a) {
        if (a == null || a.next == null) {
            return null;
        }
        ListNode slowNode = a, fastNode = a;
        while (fastNode != null && fastNode.next != null) {
            fastNode = fastNode.next.next;
            slowNode = slowNode.next;
            if (fastNode == slowNode) {
                slowNode = a;
                while (slowNode != fastNode) {
                    slowNode = slowNode.next;
                    fastNode = fastNode.next;
                }
                return slowNode;
            }
        }
        return null;
	}
}
