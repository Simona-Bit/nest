public class Solution{
	//第一题
	public ListNode FindKthToTail(ListNode head,int k){
		int length = 0;
		Node cur = head;
        while(cur != null){
			cur = cur.next;
			length++;
		}
		
		
	}
	
	public ListNode FindKthToTail(ListNode head,int k){
		ListNode front = head;
		ListNode back = head;
		
		for(int i = 0; i < k; i++){
			if(front == null){
				return null;
			}
			
			while(front != null){
				front = front.next;
				back = back.next;
			}
			
			return back;
		}
	}
	
	//第二题
	public ListNode middleNode(ListNode head){
		ListNode front = head;
		ListNode back = head;
		
		while(front != null){
			front = front.next;
			if(front == null){
				break;
			}
		    back = back.next;
			front = front.next;
		}
			
			return back;
	}
	
	//合并有序链表
	public ListNode mergeTwoLists(ListNode l1, ListNode l2){
		if(l1 == null){return l2;}
		if(l2 == null){return l1;}
		
		ListNode cur1 = l1;
		ListNode cur2 = l2;
		ListNode result = null;
		ListNode last = null;
		
		while(cur1 != null && cur2 != null){
			if(cur1.val <= cur2.val){
				ListNode next = cur1.next;
				//把 cur1 尾插到 result 上
				//两种情况：空链表/非空链表
				if(result == null){
					//头插
					cur1.next = result;
					result = cur1; 
				}else{
					//确定最后一个结点（利用last记录）
					//最后一个结点的 next = cur1
					cur1.next = null;
					last.next = cur1;
				}
				last = cur1;
				cur1 = next;
			
			}else{
				//cur    current当前
				ListNode next = cur2.next;
				//把 cur1 尾插到 result 上
				//两种情况：空链表/非空链表
				if(result == null){
					//头插
					cur2.next = result;
					result = cur2;  
				}else{
					//确定最后一个结点（利用last记录）
					//最后一个结点的 next = cur1
					cur2.next = null;
					last.next = cur2;
				}
				//保证 last 永远指向最后一个结点
				last = cur2;  
				cur2 = next;   //让循环走起来
			}
		}
		if(cur1 != null){
			last.next = cur1;
		}
		if(cur2 != null){
			last.next = cur2;
		}
		return result;
	}
	
}