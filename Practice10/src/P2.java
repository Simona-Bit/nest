import java.util.HashMap;
import java.util.Map;

public class P2 {
    public static class Node{
        int val;
        Node next;
        Node random;
    }
    static Node copy(Node head){
        Node p = head;
        while (p != null){
            Node q = new Node();
            q.val = p.val;

            q.next = p.next;
            p.next = q;

            p = q.next;
        }

        p = head;
        while (p != null){
            Node q = p.next;
            if (p.random != null){
                q.random = p.random.next;
            }else {
                q.random = null;
            }
            p = q.next;
        }
        //把两个链表拆开
        return head;
    }

    Node copy2(Node head){
        Node p = head;
        Node result = null;
        Node last = null;
        Map<Node, Node> map = new HashMap<>();
        while (p != null){
            Node q = new Node();
            q.val = p.val;
            if (result == null){
                return q;
            }else {
                last.next = q;
            }
            last = q;
            map.put(p, q);
            p = p.next;
        }
        p = head;
        Node q = result;

        while (p != null){
            q.random = map.get(p.random);

            p = p.next;
            q = q.next;
        }
        return result;
    }
}
