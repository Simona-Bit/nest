//封装

class Node{
	private int val;
	private Node next;
	
	Node(int val){
		this.val = val;
	}	
}

class LinkedList{
	int size;
	Node head;
	//Node last;
	
	public int size(){
		return size;
	}
	
	//头插
	public void pushFront(int val){
		Node node = new Node(val);
		node.next = head;
		this.head = node;
		
		size++;
	}
	
	//尾插
	public void pushBack(int val){
		if(head == null){
			pushFront(val);
		}else{
			Node last = head;
			while(last.next != null){
				last = last.next;
			}
			last.next = new Node(val);
			size++;
		}
	}
	
	//头删
	public void popFront(){
		if(head == null){
			System.out.println("应该是用异常处理");
		}else{
			head = head.next;
			size--;
		}
	}
	
	//尾删
	public void popBack(){
		if(head == null){
			System.out.println("应该是用异常处理");
		}else if(head.next == null){
			head = null;
			size = 0;
		}else{
			Node lastSecond = head;
			while(lastSecond.next.next != null){
				lastSecond = lastSecond.next;
			}
			
			lastSecond.next = null;
			size--;
		}
	}
}

class ArrayList{
	private int[] array;//private int[] array = new int[10];
	private int size;
	
	//不写，编译器就会默认生成这么一个无参构造方法
	public ArrayList(){
		this(10);
	}
	
	public ArrayList(int size){  //这里的size指容器大小capacity
		array = new int[size];
	}
	
	public int size(){
		return size;
	}
	
	public void pushBack(int val){
		//TODO:先不考虑扩容问题
		array[size++] = val;
	}
	
	public void pushFront(int val){
		for(int i = size; i > 0; i--){
			array[i] = array[i-1];
		}
		
		array[0] = val;
		size++;
	}
	
	public void popBack(){
		if(size == 0){
			System.out.println("应该是用异常处理")；
		}else{
			for(int i = 0; i < size - 1; i++){
				array[i] = array[i+1];
			}
			size--;
		}
	}
}

public class List{
	public static void main(String[] args){
		LinkedList linkedList = new LinkedList();
		linkedList.pushBack(1);
		linkedList.pushBack(2);
		linkedList.pushBack(3);
		linkedList.pushBack(4);
		
		ArrayList arrayList = new ArrayList();
		arrayList.pushBack(1);
		arrayList.pushBack(2);
		arrayList.pushBack(3);
		arrayList.pushBack(4);
		
		int size = arrayList.size();
		System.out.println(arrayList.size());
	}
}