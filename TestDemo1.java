//合并两个有序链表
class Node{
    public int val;
    public Node next;//下一个结点的引用
    Node(int val){
        this.val = val;
    }

    @Override
    public String toString() {
        return "val="+val;
    }
}
public class TestDemo1 {
    private static Node merge(Node head1, Node head2) {
        if (head1 == null) {
            return head2;
        }
        if (head2 == null) {
            return head1;
        }
        //1、分别遍历两个链表，取值比较小的结点，尾插到新链表中
        //2、把剩余链表接到新链表的后边
        Node c1 = head1;
        Node c2 = head2;
        Node rhead = null;
        Node rlast = null;

        while (c1 != null && c2 != null) {
            //取值比较小的结点
            if (c1.val <= c2.val) {
                //把c1尾插到新链表
                //如果链表中没有结点，更新链表的第一个结点
                //否则，找到链表的最后一个结点，让它的next = 要插入的结点
                if (rhead == null) {
                    rhead = c1;
                } else {
                    rlast.next = c1;
                }
                //再更新下链表的最后一个结点
                rlast = c1;
                //让c1指向原来的下一个结点
                c1 = c1.next;
            } else {
                //把c2尾插到新链表
                if (rhead == null) {
                    rhead = c2;
                } else {
                    rlast.next = c2;
                }
                rlast = c2;
                c2 = c2.next;
            }
            if (c1 != null) {
                rlast.next = c1;
            } else {
                rlast.next = c2;
            }
        }
        return rhead;
    }
    private static Node createList1(){
        Node n1 = new Node(1);
        Node n2 = new Node(3);
        Node n3 = new Node(3);
        Node n4 = new Node(5);
        Node n5 = new Node(6);
        Node n6 = new Node(9);
        n1.next = n2; n2.next = n3; n3.next = n4; n4.next = n5; n5.next = n6;
        return n1;
    }
    private static Node createList2(){
        Node n1 = new Node(1);
        Node n2 = new Node(5);
        Node n3 = new Node(9);
        n1.next = n2; n2.next = n3;
        return n1;
    }

    public static void main(String[] args) {
       Node n1 = createList1();
       Node n2 = createList2();
       Node result = merge(n1,n2);
       for(Node cur = result;cur!=null;cur=cur.next){
           System.out.println(cur);
       }
    }
}
