// Note:Your choice is C++ IDE
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//结点定义，为Node起别名
typedef int Datatype;
typedef struct Node
{
	Datatype data;
	struct Node*Next;
}Node, *ListNode;

Node*NewLinkList()
{
	Node*head;
	Node*temp;
	Node*ptr;
	int c;
	int count;
	head = (Node*)malloc(sizeof(Node));
	head->Next = NULL;
	ptr = head;
	printf("请输入链表长度:");
	scanf("%d", &count);
	printf("请输入数据:");
	while (count--)
	{
		scanf("%d", &c);
		temp = (Node*)malloc(sizeof(Node));
		if (!temp)
		{
			perror("use malloc");
			exit(1);
		}
		else
		{
			temp->data = c;
			temp->Next = NULL;
			ptr->Next = temp;
			ptr = ptr->Next;
		}
	}
	return head;
}

void Reverse(ListNode list)           //编写函数,实现把单向链表中元素逆置
{
	Node*p = list->Next;
	list->Next = NULL;
	while (p != NULL)
	{
		Node*q = p->Next;
		p->Next = list->Next;
		list->Next = p;
		p = q;
	}
}

Node*OrderList()     //建立一个非递减有序单链表
{
	Node*head;
	Node*ptr;
	Node*cur;
	Node*pcur;
	head = NewLinkList();
	ptr = head->Next;

	while (ptr != NULL)
	{
		cur = head->Next;
		ptr = ptr->Next;
		pcur = ptr;
		while (pcur != NULL)
		{
			if (cur->data>cur->Next->data)
			{
				Datatype temp = cur->data;
				cur->data = cur->Next->data;
				cur->Next->data = temp;
			}
			cur = cur->Next;
			pcur = pcur->Next;
		}
	}
	return head;
}

Node*Merge(ListNode head1, ListNode head2)  //合并两个有序链表
{
	Node*newhead;
	Node*p1 = head1->Next;
	Node*p2 = head2->Next;
	Node*ptr;
	newhead = head1;
	ptr = newhead;
	while ((p1 != NULL) && (p2 != NULL))
	{
		if (p1->data<p2->data)
		{
			ptr->Next = p1;
			p1 = p1->Next;
		}
		else
		{
			ptr->Next = p2;
			p2 = p2->Next;
		}
		ptr = ptr->Next;
	}
	if (p1 == NULL)
	{
		ptr->Next = p2;
	}
	else
	{
		ptr->Next = p1;
	}
	free(head2);
	return newhead;
}

void insertOrderList(ListNode head, Datatype data)
{
	Node*temp;
	Node*cur = head->Next;
	Node*ptr = head->Next;
	temp = (Node*)malloc(sizeof(Node));
	if (!temp)
	{
		perror("use malloc");
		exit(1);
	}
	else
	{
		temp->data = data;
		temp->Next = NULL;
	}
	while (ptr != NULL)
	{
		if (data <= ptr->data)
		{
			temp->Next = cur->Next;
			cur->Next = temp;
			break;
		}
		cur = ptr;
		ptr = ptr->Next;
	}
	if (NULL == temp->Next)
	{
		cur->Next = temp;
	}
}

void Delete(ListNode head, Datatype k)//删除有序链表中值为k的节点
{
	Node*cur;
	Node*ptr;
	cur = head->Next;
	ptr = head->Next;
	int flag = 0;
	while (ptr != NULL)
	{
		if (k == ptr->data)
		{
			cur->Next = ptr->Next;
			free(ptr);
			ptr = NULL;
			flag = 1;
			break;
		}
		cur = ptr;
		ptr = ptr->Next;
	}
	if (flag == 0)
	{
		printf("删除元素不存在\n");
	}
	else
	{
		printf("删除元素成功\n");
	}
}

void Display(Node*list)
{
	Node*ret = list->Next;
	while (ret)
	{
		printf("%d", ret->data);
		ret = ret->Next;
	}
	printf("\n");
}

//创建菜单
void menu()
{
	printf("*********************************************\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("********1.创建新链表  2.打印链表      *******\n");
	printf("********3.逆序链表    4.建立有序链表  *******\n");
	printf("********5.合并链表    6.插入节点仍有序*******\n");
	printf("********7.删除节点    0.退出          *******\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("*********************************************\n");
}

int main()     //创建主函数
{
	menu();
	int input = 0;
	Node*head = NULL;
	Node*head1;
	Node*head2;
	do{
		printf("\n");
		printf("请输入指令：");
		scanf("%d", &input);
		printf("\n");
		switch (input)
		{
		case 1:head = NewLinkList(); break;
		case 2:Display(head); break;
		case 3:Reverse(head); break;
		case 4:head = OrderList(); break;
		case 5:
			head1 = OrderList();
			Display(head1);
			head2 = OrderList();
			Display(head2);
			head = Merge(head1, head2);
			break;
		case 6:
			head = OrderList();
			int data;
			printf("请输入插入元素：");
			scanf("%d", &data);
			insertOrderList(head, data);
			break;
		case 7:
			head = NewLinkList();
			int d;
			printf("请输入删除元素：");
			scanf("%d", &d);
			Delete(head, d);
			break;
		case 0:
			break;
		default:
			printf("您的输入有误，请重新输入：");
		}
	} while (input);
	system("pause");
	return 0;
}

