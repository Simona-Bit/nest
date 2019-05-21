#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

//***********************链式存储实现栈的初始化、入栈、出栈*******************//
typedef int DataType;
typedef struct Node
{
	DataType data;
	struct Node* next;
}LinkStackNode, *LinkStack;

//链式存储实现栈的初始化
void InitStack_Link(LinkStack* top)
{
	LinkStackNode *tmp = (LinkStackNode *)malloc(sizeof(LinkStackNode));//头结点
	if (tmp == NULL)
		return;
	tmp->data = 0;
	tmp->next = NULL;
	*top = tmp;
}

//链式存储实现栈的入栈
void Push_Link(LinkStack top, DataType x)     //将数据元素x压入栈top中
{
	LinkStackNode* tmp;
	tmp = (LinkStackNode*)malloc(sizeof(LinkStackNode));//申请空间
	if (tmp == NULL)
		return;            //申请空间失败
	tmp->data = x;
	tmp->next = top->next;
	top->next = tmp;       //修改当前栈顶指针
}

//链式存储实现栈的出栈
void Pop_Link(LinkStack top, DataType* x)   //将栈top的栈顶元素弹出，放到x所指的储存空间中
{
	LinkStackNode* tmp;
	tmp = top->next;
	if (tmp == NULL)//空栈
	{
		return;
	}
	*x = tmp->data;
	top->next = tmp->next;
	free(tmp);       //释放存储空间
}

void Print(LinkStack top)
{
	LinkStackNode* ss = top->next;
	if (top == NULL)
		return;
	else
	{
		while (ss != NULL)
		{
			printf("%d ", ss->data);
			ss = ss->next;
		}
		printf("\n");
	}
}

//***************顺序存储实现栈的初始化、入栈、出栈操作***************//
#define Size 20
typedef struct
{
	DataType arr[Size];
	int top;
}SeqStack;

//顺序存储实现栈的初始化
void InitStack_Seq(SeqStack* s)
{   //构造一个空栈s
	s->top = -1;
}

//顺序存储实现栈的入栈
int Push_Seq(SeqStack* s, DataType x)
{
	if (s->top == Size - 1)//栈满
		return 0;
	s->top++;
	s->arr[s->top] = x;
	return 1;
}

//顺序存储实现栈的出栈
int Pop_Seq(SeqStack* s, DataType* x)
{  //将s栈顶元素弹出，放到x所指的储存空间中带出
	if (s->top == -1)//栈空
		return 0;
	else
	{
		*x = s->arr[s->top];
		s->top--;     //修改栈顶指针
		return 1;
	}
}

void Print_Seq_Stack(SeqStack s)
{
	int i = 0;
	for (i = 0; i <= s.top; i++)
	{
		printf("%d ", s.arr[i]);
	}
	printf("\n");
}

//******************采用链式存储实现队列的初始化、入队、出队操作***************//
typedef struct qNode
{
	DataType data;
	struct qNode* next;
}LinkQueueNode;

typedef struct
{
	LinkQueueNode* front;
	LinkQueueNode* rear;
}LinkQueue;

//链式存储实现队列的初始化
void InitQue(LinkQueue* q)
{
	q->front = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
	if (q->front == NULL)
	{
		return;
	}
	else
	{
		q->rear = q->front;
		q->front->next = NULL;
	}
}

//链式存储实现队列的入队
void EnterQueue(LinkQueue* q, DataType x)
{
	LinkQueueNode* NewNode;
	NewNode = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
	if (NewNode != NULL)
	{
		NewNode->data = x;
		NewNode->next = NULL;
		q->rear->next = NewNode;
		q->rear = NewNode;
	}
	else
		return;
}

//链式存储实现队列的出队
void OutQueue(LinkQueue* q, DataType* x)
{
	LinkQueueNode* first = q->front->next;
	if (first == NULL)//队列为空
		return;
	if (first->next == NULL)//队列中只有一个元素
	{
		*x = first->data;
		q->rear = q->front;
		q->front->next = NULL;
	}
	else
	{
		*x = first->data;
		q->front->next = first->next;
	}
	free(first);
	first = NULL;
}

void Print_Link_Queue(LinkQueue* q)
{
	LinkQueueNode* cur = q->front;
	if (q->front == q->rear)
		return;
	while (cur != q->rear)
	{
		cur = cur->next;
		printf("%d ", cur->data);
	}
	printf("\n");
}


//***********************顺序存储实现队列的初始化、入栈、出栈操作*****************//
#define Size 20
typedef struct
{
	DataType arr[Size];
	int front;
	int rear;
}SeqQueue;

//顺序存储实现循环队列的初始化
void SInitQueue(SeqQueue* q)
{
	q->front = q->rear = 0;
}

//顺序存储实现循环队列的入队
int SEnterQueue(SeqQueue* q, DataType data)
{
	if ((q->rear + 1) % Size == q->front)//队列满
		return 0;

	q->arr[q->rear] = data;
	q->rear = (q->rear + 1) % Size;
	return 1;
}

//顺序存储实现循环队列的出队
int SOutQueue(SeqQueue* q, DataType* x)
{
	if (q->front == q->rear)//队列空
		return 0;
	*x = q->arr[q->front];
	q->front = (q->front + 1) % Size;
	return 1;
}

void Print_SQueue(SeqQueue* q)
{
	int i = q->front;
	if (q->front == q->rear)
	{
		printf("此时队列为空！\n");
	}
	while (i != q->rear)
	{
		printf("%d ", q->arr[i]);
		i++;
		i = i % Size;
	}
	printf("\n");
}

void menu()
{
	printf("****************   Menu   ****************\n");
	printf("**1.链栈入栈             2.链栈出栈*******\n");
	printf("**3.顺序栈入栈           4.顺序栈出栈*****\n");
	printf("**5.链队入队             6.链队出队*******\n");
	printf("**7.顺序队列入队         8.顺序队列出队***\n");
	printf("******************************************\n");
}

int main()
{
	int n = 0;
	DataType a;
	LinkQueue q;
	SeqQueue q1;
	SeqStack s;
	LinkStackNode* head = NULL;

	menu();
	while (1)
	{
		printf("Please select：>");
		scanf("%d", &n);
		switch (n)     //switch多分支结构
		{
		case 1:
			printf("链栈入栈过程：\n");
			InitStack_Link(&head);
			Push_Link(head, 1);
			Print(head);
			Push_Link(head, 3);
			Print(head);
			Push_Link(head, 5);
			Print(head);
			Push_Link(head, 7);
			Print(head);
			Push_Link(head, 9);
			Print(head);
			Push_Link(head, 11);
			Print(head);
			break;
		case 2:
			printf("链栈出栈过程：\n");
			InitStack_Link(&head);
			Push_Link(head, 1);
			Push_Link(head, 3);
			Push_Link(head, 5);
			Push_Link(head, 7);
			Push_Link(head, 9);
			Push_Link(head, 11);
			Print(head);

			Pop_Link(head, &a);
			Print(head);
			Pop_Link(head, &a);
			Print(head);
			Pop_Link(head, &a);
			Print(head);
			Pop_Link(head, &a);
			Print(head);
			Pop_Link(head, &a);
			Print(head);
			Pop_Link(head, &a);
			Print(head);
			break;
		case 3:
			printf("顺序栈入栈过程：\n");
			InitStack_Seq(&s);
			Push_Seq(&s, 2);
			Print_Seq_Stack(s);
			Push_Seq(&s, 4);
			Print_Seq_Stack(s);
			Push_Seq(&s, 6);
			Print_Seq_Stack(s);
			Push_Seq(&s, 8);
			Print_Seq_Stack(s);
			Push_Seq(&s, 10);
			Print_Seq_Stack(s);
			Push_Seq(&s, 12);
			Print_Seq_Stack(s);
			break;
		case 4:
			printf("顺序栈出栈过程：\n");
			InitStack_Seq(&s);
			Push_Seq(&s, 2);
			Push_Seq(&s, 4);
			Push_Seq(&s, 6);
			Push_Seq(&s, 8);
			Push_Seq(&s, 10);
			Push_Seq(&s, 12);
			Print_Seq_Stack(s);

			Pop_Seq(&s, &a);
			Print_Seq_Stack(s);
			Pop_Seq(&s, &a);
			Print_Seq_Stack(s);
			Pop_Seq(&s, &a);
			Print_Seq_Stack(s);
			Pop_Seq(&s, &a);
			Print_Seq_Stack(s);
			Pop_Seq(&s, &a);
			Print_Seq_Stack(s);
			Pop_Seq(&s, &a);
			Print_Seq_Stack(s);
			break;
		case 5:
			printf("链队列入队过程：\n");
			InitQue(&q);
			EnterQueue(&q, 6);
			Print_Link_Queue(&q);
			EnterQueue(&q, 5);
			Print_Link_Queue(&q);
			EnterQueue(&q, 4);
			Print_Link_Queue(&q);
			EnterQueue(&q, 3);
			Print_Link_Queue(&q);
			EnterQueue(&q, 2);
			Print_Link_Queue(&q);
			EnterQueue(&q, 1);
			Print_Link_Queue(&q);
			break;
		case 6:
			printf("链队列出队过程：\n");
			InitQue(&q);
			EnterQueue(&q, 6);
			EnterQueue(&q, 5);
			EnterQueue(&q, 4);
			EnterQueue(&q, 3);
			EnterQueue(&q, 2);
			EnterQueue(&q, 1);
			Print_Link_Queue(&q);

			OutQueue(&q, &a);
			Print_Link_Queue(&q);
			OutQueue(&q, &a);
			Print_Link_Queue(&q);
			OutQueue(&q, &a);
			Print_Link_Queue(&q);
			OutQueue(&q, &a);
			Print_Link_Queue(&q);
			OutQueue(&q, &a);
			Print_Link_Queue(&q);
			OutQueue(&q, &a);
			Print_Link_Queue(&q);
			break;
		case 7:
			printf("循环队列入队过程：\n");
			SInitQueue(&q1);
			SEnterQueue(&q1, 6);
			Print_SQueue(&q1);
			SEnterQueue(&q1, 5);
			Print_SQueue(&q1);
			SEnterQueue(&q1, 4);
			Print_SQueue(&q1);
			SEnterQueue(&q1, 3);
			Print_SQueue(&q1);
			SEnterQueue(&q1, 2);
			Print_SQueue(&q1);
			break;
		case 8:
			printf("循环队列出队过程：\n");
			SInitQueue(&q1);
			SEnterQueue(&q1, 6);
			SEnterQueue(&q1, 5);
			SEnterQueue(&q1, 4);
			SEnterQueue(&q1, 3);
			SEnterQueue(&q1, 2);
			Print_SQueue(&q1);

			SOutQueue(&q1, &a);
			Print_SQueue(&q1);
			SOutQueue(&q1, &a);
			Print_SQueue(&q1);
			SOutQueue(&q1, &a);
			Print_SQueue(&q1);
			SOutQueue(&q1, &a);
			Print_SQueue(&q1);
			break;
		default:
			printf("Selection error,please re-select!\n");
		}
	}
	system("pause:");
	return 0;
}
