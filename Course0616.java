class Node{
	int val;
	Node next;
	
	//构造方法
	Node(int val){
		this.val = val;
	}
}

class CNode{
	int val;
	CNode random; //random默认值是null
    CNode next;
	
	CNode(int val){
		this.val = val;
	}
}


class Solution{
	//逆置
    Node reverseList(Node head){
		//遍历链表，进行头插
		Node result = null;  //结果链表
		Node cur = head;
		while(cur != null){
			Node next = cur.next;
			
			cur.next = result;
			result = cur;
			
			cur = next;
		}
		return result;
	}
	
	//删除所有
	Node removeAll(Node head,int val){
		if(head == null){
			return null;
		}
		//如果相等，则删除
		//一开始先跳过第一个结点
		Node prev = head;
		Node cur = head.next;
		
		while(cur != null){
			if(cur.val == val){
				prev.next = cur.next;
			}else{
				prev = cur;
			}
			cur = cur.next;
		}
		
		//处理第一个结点
		if(head.val == val){
			return head.next;
		}
		return head;
	}
	
	//合并两个有序链表
	Node merge(Node head1, Node head2){
		if(head1 == null){
			return head2;
		}
		
		if(head2 == null){
			return head1;
		}
		
		Node result = null;
		Node last = null;
		
		Node cur1 = head1;
		Node cur2 = head2;
		
		while(cur1 != null && cur2 != null){
			if(cur1.val <= cur2.val){
				//将cur1尾插过去
				if(result == null){
					result = cur1;
				}else{
					last.next = cur1;
				}
				last = cur1;
				cur1 = cur1.next;
			}else{
				//将cur2尾插过去
				if(result == null){
					return cur2;			
				}else{
					last.next = cur2;
				}
				last = cur2;
				cur2 = cur2.next;
			}
		}
		
		if(cur1 == null){
			last.next = cur2;
		}else{
			last.next = cur1;
		}
		return result;
	}
	
	//删除重复结点
	Node deleteDuplicate(Node head){
		if(head == null){
			return null;
		}
		//对head做解引用
		Node prev = null;
		Node p1 = head;
		Node p2 = head.next;
		
		while(p2 != null){
			if(p1.val != p2.val){
				prev = p1;
				p1 = p2;
				p2 = p2.next;
			}else{
				while(p2 != null && p1.val == p2.val){
					p2 = p2.next;
				}
				
				if(prev == null){
					head = p2;
				}else{
					prev.next = p2;
				}
				
				p1 = p2;
				if(p2 != null){
					p2 = p2.next;
				}
			}
		}
		return head;
	}
	
	//复制复杂链表
	CNode copy(CNode head){
		if(head == null){
			return null;
		}
		
		CNode cur = head;
		while(cur != null){
			CNode node = new CNode(cur.val);//新建一个结点
			
			node.next = cur.next;
			cur.next = node;
			
			cur = node.next;  //cur直接往后走两步
		}
		
		//random的复制
		cur = head;
		while(cur != null){
			if(cur.random != null){
			    cur.next.random = cur.random.next;
		    }
			
			cur = cur.next.next;
		}
		
		//拆分
		CNode newHead = head.next;
		cur = head;
		
		while(cur != null){
			CNode node = cur.next;
			
			cur.next = node.next;
			if(node.next != null){
				node.next = node.next.next;
			}
			
			cur = cur.next;
		}
		return newHead;
	}
}

public class Course0616{
	static void testReverseList(){
		//1、构建一个链表
		//2、调用逆置方法
		//3、打印
		
		Node n1 = new Node(1);
		Node n2 = new Node(3);
		Node n3 = new Node(6);
		Node n4 = new Node(9);
		Node n5 = new Node(2);
		Node n6 = new Node(5);
		Node n7 = new Node(8);  //七个独立的结点，之后串起来
		
		n1.next = n2;
		
		n2.next = n3;
		n3.next = n4;
		n4.next = n5;
		n5.next = n6;
		n6.next = n7;
		
		//普通方法的调用需要构建一个对象
		//如果只用一次，则可以只new Solution().reverseList(n1);
     	Node result = new Solution().reverseList(n1);
		
		//测试有结点的情况
		//打印所有结点
		for(Node cur = result; cur != null; cur = cur.next){
			System.out.printf("%d --> ", cur.val);//cur.val指属性
		}
		System.out.println();  //换行
		
		//测试没有结点的情况
		result = new Solution().reverseList(null);
		
		for(Node cur = result; cur != null; cur = cur.next){
			System.out.printf("%d --> ", cur.val);
		}
		System.out.println();
	}

	//删除所有的测试
	static void testRemoveAll(){
		Node n1 = new Node(1);
		Node n2 = new Node(2);
		Node n3 = new Node(3);
		Node n4 = new Node(4);
		Node n5 = new Node(5);
		
		n1.next = n2;
		n2.next = n3;
		n3.next = n4;
		n4.next = n5;
		
		for(Node cur = n1; cur != null; cur = cur.next){
			System.out.printf("%d --> ", cur.val);//cur.val指属性
		}
		System.out.println();
		
		Node result = new Solution().removeAll(n1,n1.val);
		
		for(Node cur = result; cur != null; cur = cur.next){
			System.out.printf("%d --> ", cur.val);//cur.val指属性
		}
		System.out.println();
		
		result = new Solution().removeAll(n2,n2.val);
		for(Node cur = result; cur != null; cur = cur.next){
			System.out.printf("%d --> ", cur.val);//cur.val指属性
		}
		System.out.println();
		
		result = new Solution().removeAll(n3,n3.val);
		for(Node cur = result; cur != null; cur = cur.next){
			System.out.printf("%d --> ", cur.val);//cur.val指属性
		}
		System.out.println();
		
		result = new Solution().removeAll(n4,n4.val);
		for(Node cur = result; cur != null; cur = cur.next){
			System.out.printf("%d --> ", cur.val);//cur.val指属性
		}
		System.out.println();
		
		result = new Solution().removeAll(n5,n5.val);
		for(Node cur = result; cur != null; cur = cur.next){
			System.out.printf("%d --> ", cur.val);//cur.val指属性
		}
		System.out.println();
	}
	
	//复制复杂链表测试
	static void testCopy(){
		CNode n1 = new CNode(1);
		CNode n2 = new CNode(2);
		CNode n3 = new CNode(3);
		CNode n4 = new CNode(4);
		
		n1.next = n2; n2.next = n3; n3.next = n4;
		n1.random = n2; n2.random = n1; n3.random = n3;//n4.random = null;(可不写)
		
		CNode result = new Solution().copy(n1);
		//打印val和地址
		for(CNode cur = n1; cur != null; cur = cur.next){
			System.out.printf("CNode(%s, %d, %s) --> %n", cur, cur.val, cur.random);
		}   //因为cur和cur.random本身是node形式，也未定义toString,所以打印出是地址形式%s
		System.out. println();
		System.out. println();
		
		for(CNode cur = result; cur != null; cur = cur.next){
			System.out.printf("CNode(%s, %d, %s) --> %n", cur, cur.val, cur.random);
		}
		System.out. println();
	}
	
	//main函数
	public static void main(String[] args){
		/*testReverseList();*/
		testCopy();
		testRemoveAll();
	}
}