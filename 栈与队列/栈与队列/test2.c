//#include<stdio.h>
//#include<stdlib.h>
//#define OVERFLOW -2
//#define ERROR 0
//#define OK 1
//#define MAX 100
//typedef int SElemType;
//typedef int QElemType;
//typedef struct
//{
//	SElemType *base;
//	SElemType *top;
//}SqStack;
//
//SqStack InitStacka()		//顺序存储实现栈的初始化
//{
//	SqStack S;
//	S.base = (SElemType *)malloc(MAX*sizeof(SElemType));
//	if (!S.base) exit(OVERFLOW);
//	S.top = S.base;
//	return(S);
//}
//
//void Pusha(SqStack &S, int x)		//顺序存储实现栈的入栈操作
//{
//	if (S.top - S.base >= MAX)
//		exit(OVERFLOW);
//	*S.top++ = x;
//}
//
//void Popa(SqStack &S)		//顺序存储实现栈的出栈操作
//{
//	SElemType *p;
//	int x;
//	if (S.top == S.base) return;
//	else {
//		p = S.top;
//		x = *--S.top;
//		printf("\t删除的栈顶元素是%d\n\t出栈操作完成后的栈为:\n", x);
//	}
//}
//
//void printa(SqStack S)    //输出
//{
//	SElemType *p;
//	p = S.base;
//	printf("\t");
//	while (p != S.top)
//	{
//		printf("%d ", *(p++));
//	}
//	printf("\n");
//}
//
//typedef struct SqNode
//{
//	SElemType data;
//	SqNode *Link;
//}*Sqptr, NODE;
//
//
//typedef struct
//{
//	Sqptr top;
//}Stack;
//
//Stack InitStackb()    //链式存储实现栈的初始化
//{
//	Stack S;
//	S.top = (Sqptr)malloc(sizeof(NODE));
//	if (!S.top)
//		exit(OVERFLOW);
//	S.top->Link = NULL;
//	return(S);
//}
//
//void Pushb(Stack &S, int x)    //链式存储实现栈的入栈操作
//{
//	Sqptr p;
//	p = (Sqptr)malloc(sizeof(NODE));
//	if (!p) return;
//	p->data = x;
//	p->Link = S.top->Link;
//	S.top->Link = p;
//}
//
//void Popb(Stack &S)    //链式存储实现栈的出栈操作
//{
//	int x;
//	Sqptr p;
//	if (S.top->Link == NULL)
//		return;
//	else
//	{
//		p = S.top->Link;
//		x = p->data;
//		S.top->Link = p->Link;
//		printf("\t删除的栈顶元素是%d\n", x);
//		free(p);
//	}
//}
//
//typedef struct QNode
//{
//	QElemType data;    //数据域
//	struct QNode *next;    //指针域
//}*QueuePtr, QNode;
//
//
//typedef struct
//{
//	QueuePtr front;    //队头
//	QueuePtr rear;    //队尾
//}LinkQueue;
//
//
//LinkQueue InitQueue()		//链式存储实现队列的初始化
//{
//	LinkQueue Q;
//	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
//	if (!Q.front)
//		exit(OVERFLOW);
//	Q.front->next = NULL;
//	return(Q);
//}
//
//
//void EnQueue(LinkQueue &Q, QElemType x)		//链式存储实现队列的入队
//{
//	QueuePtr p;
//	p = (QueuePtr)malloc(sizeof(QNode));
//	if (!p) exit(OVERFLOW);
//	p->data = x;
//	p->next = NULL;
//	Q.rear->next = p;
//	Q.rear = p;
//}
//
//
//void DeQueue(LinkQueue &Q)		//链式存储实现队列的出队
//{
//	int x;
//	if (Q.front == Q.rear) return;
//	QueuePtr p;
//	p = Q.front->next;
//	x = p->data;
//	printf("\t删除的队头元素是：%d\n", x);
//	Q.front->next = p->next;
//	if (Q.rear == p)
//		Q.rear = Q.front;
//	free(p);
//	return;
//}
//
//
//typedef struct
//{
//	SElemType *base;
//	int front, rear;
//}SqQueue;
//
//
//SqQueue InitQueueb()    //顺序存储实现队列的初始化
//{
//	SqQueue S;
//	S.base = (SElemType *)malloc(MAX*sizeof(SElemType));
//	if (!S.base)
//		exit(OVERFLOW);
//	S.front = S.rear = 0;
//	return(S);
//}
//
//
//void EnQueueb(SqQueue &S, int x)	    //顺序存储实现队列的入队
//{
//	if ((S.rear + 1) % MAX == S.front)
//		return;
//	S.base[S.rear] = x;
//	S.rear = (S.rear + 1) % MAX;
//}
//
//
//void DeQueueb(SqQueue &S)    //顺序存储实现队列的出队
//{
//	int x;
//	if (S.front == S.rear) return;
//	x = S.base[S.front];
//	S.front = (S.front + 1) % MAX;
//	printf("\t删除的队头元素是:%d\n", x);
//}
//
//
//void main()          //主函数
//{
//	int choice;
//	int n, x;
//	printf("\n\n");
//	printf("\t--------------------主菜单--------------------\n");
//	printf("\t1.采用链式存储实现栈的初始化、入栈、出栈操作\n");
//	printf("\t2.采用顺序存储实现栈的初始化、入栈、出栈操作\n");
//	printf("\t3.采用链式存储实现队列的初始化、入队、出队操作\n");
//	printf("\t4.采用顺序存储实现队列的初始化、入队、出队操作\n");
//	printf("\t-----------------------------------------------\n");
//	printf("\t请选择相应的功能:");
//	scanf("%d", &choice);
//	switch (choice)
//	{
//	case 1:Stack Sa;
//		printf("\t1.链式存储实现栈的初始化\n");
//		printf("\t2.链式存储实现栈的入栈操作\n");
//		printf("\t3.链式存储实现栈的出栈操作\n");
//		while (1)
//		{
//			printf("\t请选择相应的功能:");
//			scanf("%d", &n);
//			switch (n)
//			{
//			case 1:Sa = InitStackb();
//				printf("\t链式存储栈的初始化完成!\n");
//				break;
//			case 2:printf("\t请输入栈内元素，以'0'结束输入\n");
//				printf("\t");
//				scanf("%d", &x);
//				while (x)
//				{
//					Pushb(Sa, x); scanf("%d", &x);
//				}
//				printf("\t链式存储栈的入栈操作完成!\n"); break;
//			case 3:Popb(Sa); break;
//			}
//		}break;
//
//
//	case 2:SqStack S;
//		printf("\t1.顺序存储实现栈的初始化\n");
//		printf("\t2.顺序存储实现栈的入栈操作\n");
//		printf("\t3.顺序存储实现栈的出栈操作\n");
//		while (1)
//		{
//			printf("\t请选择相应的功能:");
//			scanf("%d", &n);
//			switch (n)
//			{
//			case 1:S = InitStacka();
//				printf("\t顺序存储栈的初始化完成!\n"); break;
//			case 2:printf("\t请输入栈内元素，以'0'结束输入\n");
//				printf("\t");
//				scanf("%d", &x);
//				while (x)
//				{
//					Pusha(S, x);
//					scanf("%d", &x);
//				}
//				printf("\t顺序存储栈的入栈操作完成!\n");
//				printa(S); break;
//			case 3:Popa(S);
//				printa(S); break;
//			}
//		}break;
//
//
//	case 3:LinkQueue Q;
//		printf("\t1.链式存储实现队的初始化\n");
//		printf("\t2.链式存储实现队的入栈操作\n");
//		printf("\t3.链式存储实现队的出栈操作\n");
//		while (1)
//		{
//			printf("\t请选择相应的功能:");
//			scanf("%d", &n);
//			switch (n)
//			{
//			case 1:Q = InitQueue();
//				printf("\t链式存储队的初始化完成!\n"); break;
//			case 2:printf("\t请输入队列内元素，以'0'结束输入\n");
//				printf("\t");
//				scanf("%d", &x);
//				while (x)
//				{
//					EnQueue(Q, x); scanf("%d", &x);
//				}
//				printf("\t链式存储队的入队操作完成!\n");
//				break;
//			case 3:DeQueue(Q); break;
//			}
//		}break;
//
//
//	case 4:SqQueue Sv;
//		printf("\t1.顺序存储实现队的初始化\n");
//		printf("\t2.顺序存储实现队的入栈操作\n");
//		printf("\t3.顺序存储实现队的出栈操作\n");
//		while (1)
//		{
//			printf("\t请选择相应的功能:");
//			scanf("%d", &n);
//			switch (n)
//			{
//			case 1:Sv = InitQueueb();
//				printf("\t链式存储队列的初始化完成!\n"); break;
//			case 2:printf("\t请输入队内元素，以'0'结束输入\n"); printf("\t"); scanf("%d", &x);
//				while (x)
//				{
//					EnQueueb(Sv, x); scanf("%d", &x);
//				}
//				printf("\t链式存储队列的入队操作完成!\n");
//				break;
//			case 3:DeQueueb(Sv);
//				break;
//			}
//		}break;
//	}
//}
