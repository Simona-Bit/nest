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
//SqStack InitStacka()		//˳��洢ʵ��ջ�ĳ�ʼ��
//{
//	SqStack S;
//	S.base = (SElemType *)malloc(MAX*sizeof(SElemType));
//	if (!S.base) exit(OVERFLOW);
//	S.top = S.base;
//	return(S);
//}
//
//void Pusha(SqStack &S, int x)		//˳��洢ʵ��ջ����ջ����
//{
//	if (S.top - S.base >= MAX)
//		exit(OVERFLOW);
//	*S.top++ = x;
//}
//
//void Popa(SqStack &S)		//˳��洢ʵ��ջ�ĳ�ջ����
//{
//	SElemType *p;
//	int x;
//	if (S.top == S.base) return;
//	else {
//		p = S.top;
//		x = *--S.top;
//		printf("\tɾ����ջ��Ԫ����%d\n\t��ջ������ɺ��ջΪ:\n", x);
//	}
//}
//
//void printa(SqStack S)    //���
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
//Stack InitStackb()    //��ʽ�洢ʵ��ջ�ĳ�ʼ��
//{
//	Stack S;
//	S.top = (Sqptr)malloc(sizeof(NODE));
//	if (!S.top)
//		exit(OVERFLOW);
//	S.top->Link = NULL;
//	return(S);
//}
//
//void Pushb(Stack &S, int x)    //��ʽ�洢ʵ��ջ����ջ����
//{
//	Sqptr p;
//	p = (Sqptr)malloc(sizeof(NODE));
//	if (!p) return;
//	p->data = x;
//	p->Link = S.top->Link;
//	S.top->Link = p;
//}
//
//void Popb(Stack &S)    //��ʽ�洢ʵ��ջ�ĳ�ջ����
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
//		printf("\tɾ����ջ��Ԫ����%d\n", x);
//		free(p);
//	}
//}
//
//typedef struct QNode
//{
//	QElemType data;    //������
//	struct QNode *next;    //ָ����
//}*QueuePtr, QNode;
//
//
//typedef struct
//{
//	QueuePtr front;    //��ͷ
//	QueuePtr rear;    //��β
//}LinkQueue;
//
//
//LinkQueue InitQueue()		//��ʽ�洢ʵ�ֶ��еĳ�ʼ��
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
//void EnQueue(LinkQueue &Q, QElemType x)		//��ʽ�洢ʵ�ֶ��е����
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
//void DeQueue(LinkQueue &Q)		//��ʽ�洢ʵ�ֶ��еĳ���
//{
//	int x;
//	if (Q.front == Q.rear) return;
//	QueuePtr p;
//	p = Q.front->next;
//	x = p->data;
//	printf("\tɾ���Ķ�ͷԪ���ǣ�%d\n", x);
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
//SqQueue InitQueueb()    //˳��洢ʵ�ֶ��еĳ�ʼ��
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
//void EnQueueb(SqQueue &S, int x)	    //˳��洢ʵ�ֶ��е����
//{
//	if ((S.rear + 1) % MAX == S.front)
//		return;
//	S.base[S.rear] = x;
//	S.rear = (S.rear + 1) % MAX;
//}
//
//
//void DeQueueb(SqQueue &S)    //˳��洢ʵ�ֶ��еĳ���
//{
//	int x;
//	if (S.front == S.rear) return;
//	x = S.base[S.front];
//	S.front = (S.front + 1) % MAX;
//	printf("\tɾ���Ķ�ͷԪ����:%d\n", x);
//}
//
//
//void main()          //������
//{
//	int choice;
//	int n, x;
//	printf("\n\n");
//	printf("\t--------------------���˵�--------------------\n");
//	printf("\t1.������ʽ�洢ʵ��ջ�ĳ�ʼ������ջ����ջ����\n");
//	printf("\t2.����˳��洢ʵ��ջ�ĳ�ʼ������ջ����ջ����\n");
//	printf("\t3.������ʽ�洢ʵ�ֶ��еĳ�ʼ������ӡ����Ӳ���\n");
//	printf("\t4.����˳��洢ʵ�ֶ��еĳ�ʼ������ӡ����Ӳ���\n");
//	printf("\t-----------------------------------------------\n");
//	printf("\t��ѡ����Ӧ�Ĺ���:");
//	scanf("%d", &choice);
//	switch (choice)
//	{
//	case 1:Stack Sa;
//		printf("\t1.��ʽ�洢ʵ��ջ�ĳ�ʼ��\n");
//		printf("\t2.��ʽ�洢ʵ��ջ����ջ����\n");
//		printf("\t3.��ʽ�洢ʵ��ջ�ĳ�ջ����\n");
//		while (1)
//		{
//			printf("\t��ѡ����Ӧ�Ĺ���:");
//			scanf("%d", &n);
//			switch (n)
//			{
//			case 1:Sa = InitStackb();
//				printf("\t��ʽ�洢ջ�ĳ�ʼ�����!\n");
//				break;
//			case 2:printf("\t������ջ��Ԫ�أ���'0'��������\n");
//				printf("\t");
//				scanf("%d", &x);
//				while (x)
//				{
//					Pushb(Sa, x); scanf("%d", &x);
//				}
//				printf("\t��ʽ�洢ջ����ջ�������!\n"); break;
//			case 3:Popb(Sa); break;
//			}
//		}break;
//
//
//	case 2:SqStack S;
//		printf("\t1.˳��洢ʵ��ջ�ĳ�ʼ��\n");
//		printf("\t2.˳��洢ʵ��ջ����ջ����\n");
//		printf("\t3.˳��洢ʵ��ջ�ĳ�ջ����\n");
//		while (1)
//		{
//			printf("\t��ѡ����Ӧ�Ĺ���:");
//			scanf("%d", &n);
//			switch (n)
//			{
//			case 1:S = InitStacka();
//				printf("\t˳��洢ջ�ĳ�ʼ�����!\n"); break;
//			case 2:printf("\t������ջ��Ԫ�أ���'0'��������\n");
//				printf("\t");
//				scanf("%d", &x);
//				while (x)
//				{
//					Pusha(S, x);
//					scanf("%d", &x);
//				}
//				printf("\t˳��洢ջ����ջ�������!\n");
//				printa(S); break;
//			case 3:Popa(S);
//				printa(S); break;
//			}
//		}break;
//
//
//	case 3:LinkQueue Q;
//		printf("\t1.��ʽ�洢ʵ�ֶӵĳ�ʼ��\n");
//		printf("\t2.��ʽ�洢ʵ�ֶӵ���ջ����\n");
//		printf("\t3.��ʽ�洢ʵ�ֶӵĳ�ջ����\n");
//		while (1)
//		{
//			printf("\t��ѡ����Ӧ�Ĺ���:");
//			scanf("%d", &n);
//			switch (n)
//			{
//			case 1:Q = InitQueue();
//				printf("\t��ʽ�洢�ӵĳ�ʼ�����!\n"); break;
//			case 2:printf("\t�����������Ԫ�أ���'0'��������\n");
//				printf("\t");
//				scanf("%d", &x);
//				while (x)
//				{
//					EnQueue(Q, x); scanf("%d", &x);
//				}
//				printf("\t��ʽ�洢�ӵ���Ӳ������!\n");
//				break;
//			case 3:DeQueue(Q); break;
//			}
//		}break;
//
//
//	case 4:SqQueue Sv;
//		printf("\t1.˳��洢ʵ�ֶӵĳ�ʼ��\n");
//		printf("\t2.˳��洢ʵ�ֶӵ���ջ����\n");
//		printf("\t3.˳��洢ʵ�ֶӵĳ�ջ����\n");
//		while (1)
//		{
//			printf("\t��ѡ����Ӧ�Ĺ���:");
//			scanf("%d", &n);
//			switch (n)
//			{
//			case 1:Sv = InitQueueb();
//				printf("\t��ʽ�洢���еĳ�ʼ�����!\n"); break;
//			case 2:printf("\t���������Ԫ�أ���'0'��������\n"); printf("\t"); scanf("%d", &x);
//				while (x)
//				{
//					EnQueueb(Sv, x); scanf("%d", &x);
//				}
//				printf("\t��ʽ�洢���е���Ӳ������!\n");
//				break;
//			case 3:DeQueueb(Sv);
//				break;
//			}
//		}break;
//	}
//}
