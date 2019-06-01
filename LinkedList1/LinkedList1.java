class Node{
	public int value;
	public Node next;
	
	public Node(int value){
		this.value = value;
		this.next = null;
	}
}

public class LinkedList1{
	public static void display(Node head){
		for(Node cur = head; cur != null; cur = cur.next){
			System.out.printf("(%d)--> ", cur.value);
		}
		System.out.println("null");
	}
	 
	//Node与void是两种类型
	public static Node pushFront(Node head, int value){
		Node node = new Node(value);
		node.next = head;
		return node;
	}
	
	public static Node pushBack(Node head, int value){
		Node node = new Node(value);
		if(head == null){
			//空链表
			return pushFront(node, value);
		}else{
			//非空链表
		    Node last = getLast(head);
			last.next = node;
		    return head;
		}
	}
	
	public static Node getLast(Node head){
		Node last = head;
	    while(last.next != null){
			last = last.next;
		}
		return last;
	}
	
	public static void main(String[] args){
		Node head = null;
		head = pushBack(head,1);
		head = pushBack(head,2);
		head = pushBack(head,3);
		display(head);  //1 --> 2 --> 3 --> null
		head = pushFront(head,10);
		head = pushFront(head,20);
		head = pushFront(head,30);
		display(head);  //30 --> 20 --> 10 --> 1 --> 2 --> 3 --> null
	}
	
}