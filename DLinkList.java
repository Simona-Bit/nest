public DNode{
	int val;
	DNode prev; //指向前驱结点，如果是第一个结点，则是null
	DNode next; //指向后继结点，如果是最后一个结点，则是null
}

public class DLinkList{
	private DNode head; //指向第一个结点，没有结点时是null
	private DNode last; //指向最后一个结点，没有结点时是null
	private int size;
	
	public int size(){  //size方法名
		return size;    //size属性名（java允许同名）
	}
	
	public void pushFront(int val){
		DNode node = new DNode(val);
		node.next = head;
		if(head != null){
			head.prev = node;
		}
		head = node;
		if(last == null){
			last = node;
		}
		size++;
	}
	
	public void pushBack(int val){
		if(head == null){
			pushFront(val);
		}else{
			last.next = new DNode(val);
			last.next.prev = last;
			last = last.next;
			size++;
		}
	}
	
	public void popFront(){
	    if(head == null){
			return;
		}else{
			head = head.next;
			if(head == null){
				last = null;
			}else{
				head.prev = null;
			}
			size--;
		}
	}
	
	public void popBack(){
		if(head == null){
			return;
		}else if(head.next == null){
			popFront();
		}else{
			last = last.next;
			last.next = null;
			size--;
		}
	}
}