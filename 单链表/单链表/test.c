// Note:Your choice is C++ IDE
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//��㶨�壬ΪNode�����
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
	printf("������������:");
	scanf("%d", &count);
	printf("����������:");
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

void Reverse(ListNode list)           //��д����,ʵ�ְѵ���������Ԫ������
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

Node*OrderList()     //����һ���ǵݼ���������
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

Node*Merge(ListNode head1, ListNode head2)  //�ϲ�������������
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

void Delete(ListNode head, Datatype k)//ɾ������������ֵΪk�Ľڵ�
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
		printf("ɾ��Ԫ�ز�����\n");
	}
	else
	{
		printf("ɾ��Ԫ�سɹ�\n");
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

//�����˵�
void menu()
{
	printf("*********************************************\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("********1.����������  2.��ӡ����      *******\n");
	printf("********3.��������    4.������������  *******\n");
	printf("********5.�ϲ�����    6.����ڵ�������*******\n");
	printf("********7.ɾ���ڵ�    0.�˳�          *******\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("*********************************************\n");
}

int main()     //����������
{
	menu();
	int input = 0;
	Node*head = NULL;
	Node*head1;
	Node*head2;
	do{
		printf("\n");
		printf("������ָ�");
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
			printf("���������Ԫ�أ�");
			scanf("%d", &data);
			insertOrderList(head, data);
			break;
		case 7:
			head = NewLinkList();
			int d;
			printf("������ɾ��Ԫ�أ�");
			scanf("%d", &d);
			Delete(head, d);
			break;
		case 0:
			break;
		default:
			printf("���������������������룺");
		}
	} while (input);
	system("pause");
	return 0;
}

