package data_structure;

public class MyLinkedList {
    static class Node {
        int val;
        Node prev;	// 指向前一个结点，第一个结点的前驱是 null
        Node next;	// 指向下一个结点，最后一个结点的后继是 null

        Node(int val) { this.val = val; }
    }

    /**
     * 指向链表的第一个结点，如果链表中没结点，则 == null
     */
    Node first = null;
    /**
     * 指向链表的最后一个结点，如果链表中没结点，则 == null
     */
    Node last = null;

    void addFirst(int val) {
        Node node = new Node(val);
        node.next = first;
        if (first != null) {
            first.prev = node;
        } else {
            last = node;
        }
        first = node;
    }
    void addLast(int val) {
        Node node = new Node(val);
        node.prev = last;
        if (last != null) {
            last.next = node;
        } else {
            first = node;
        }
        last = node;
    }
    int pollFirst() throws Exception {
        if (first == null) {
            throw new Exception("空的链表");
        }
        Node oldFirst = first;
        first = first.next;
        if (first == null) {
            last = null;
        } else {
            first.prev = null;
        }
        return oldFirst.val;
    }
    int pollLast() throws Exception {
        if (last == null) {
            throw new Exception("空的链表");
        }
        Node oldLast = last;
        last = last.prev;
        if (last == null) {
            first = null;
        } else {
            last.next = null;
        }
        return oldLast.val;
    }

    void print() {
        System.out.println("打印链表");
        for (Node c = first; c != null; c = c.next) {
            System.out.println(c.val);
        }
        System.out.println("==================");
        for (Node c = last; c != null; c = c.prev) {
            System.out.println(c.val);
        }
    }

    public static void main(String[] args) throws Exception {
        MyLinkedList list = new MyLinkedList();
        list.print();
        list.addFirst(1);   // 空的头插
        list.print();
        list.addFirst(2);   // 非空头插
        list.print();
        list.addLast(3);    // 非空尾插
        list.print();
        list.pollFirst();        //  5.
        list.print();
        list.pollLast();         // 6
        list.print();
        list.pollFirst();       // 7
        list.print();
        list.addLast(4);
        list.print();
        list.pollLast();
        list.print();
        /**
         * 1. 空的头插
         * 2. 非空的头插
         * 3. 空的尾插
         * 4. 非空的尾插
         * 5. > 1 结点的头删
         * 6. > 1 结点的尾删
         * 7. == 1 结点的头删
         * 8. == 1 结点的尾删
         * 9. 空链表的头删
         * 10. 空链表的尾删
         *
         * 1. 打印
         * 2. 调试
         */
    }
}
