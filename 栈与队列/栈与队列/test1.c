////1）采用链式存储实现栈的初始化、入栈、出栈操作。
////
////（2）采用顺序存储实现栈的初始化、入栈、出栈操作。
////
////（3）采用链式存储实现队列的初始化、入队、出队操作。
////
////（4）采用顺序存储实现循环队列的初始化、入队、出队操作。
////
////（5）在主函数中设计一个简单的菜单，分别测试上述算法。
//
/////
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#define TRUE   1
//#define FALSE  0
//#define ERROR 0
//#define OVERFLOW -2
//#define STACK_INIT_SIZE 100
//#define STACKINCREMENT  20
//
//////////////////////采用链式存储实现栈的初始化、入栈、出栈操作
//
//typedef struct stacklist{
//	int data;
//	struct stacklist *next;
//}stacklist, *linkstack;
//
//linkstack top, head;
//
//linkstack create()
//{
//	linkstack p;
//	p = (linkstack)malloc(sizeof(stacklist));
//	p->next = NULL;
//	return p;
//}
//
//void bulidstack()
//{
//	linkstack p, q;
//	int data;
//	p = top;
//	printf("请输入进栈的元素:");
//	scanf("%d", &data);
//	q = create();
//	q->data = data;
//	q->next = p->next;
//	top->next = q;
//}
//
//void outstack()//出栈
//{
//	linkstack p;
//	p = top->next;
//	if (p != NULL)
//	{
//		printf("%d 出栈\n", p->data);
//		top->next = p->next;
//		free(p);
//	}
//	else
//		printf("栈为空\n");
//}
//
//void tip1()
//{
//	printf("**********\n");
//	printf("*1 进栈  *\n");
//	printf("*2 出栈  *\n");
//	printf("*0 退出  *\n");
//	printf("*请选择：*\n");
//	printf("**********\n");
//}
//
////////////
//
//
/////////////////////////下面为采用顺序存储实现栈的初始化、入栈、出栈操作
//
//typedef struct Stack{//顺序栈
//	int  *base;
//	int  *top;
//	int    stacksize;      //栈可使用的最大容量
//} SqStack;
//
//int  InitStack(SqStack &S){ //0栈的初始化 
//	S.base = (int *)malloc(STACK_INIT_SIZE *sizeof(int));
//	if (!S.base)  exit(OVERFLOW);
//	S.top = S.base;
//	S.stacksize = STACK_INIT_SIZE;//栈的空间大小
//	return 1;
//}
//
//int Push(SqStack &S, int e){//1入栈
//	if (S.top - S.base >= S.stacksize){
//		S.base = (int*)realloc(S.base, (S.stacksize + STACKINCREMENT)*sizeof(int));
//		if (!S.base) exit(OVERFLOW);//如果分配失败，则退出
//		S.top = S.base + S.stacksize;//栈顶
//		S.stacksize += STACKINCREMENT;//栈空间
//	}
//	*S.top++ = e;
//	return 1;
//}
//
//int Pop(SqStack &S){//2出栈
//	int e;
//	if (S.top == S.base)
//	{
//		printf("栈为空\n");
//		return ERROR;//空栈
//	}
//	e = *--S.top;
//	return e;//返回栈顶元素
//}
//
//void Print(SqStack &S){//输出
//
//	if (S.top == S.base)
//	{
//		printf("栈为空\n");
//		return;//空栈
//	}
//	while (S.top>S.base)
//	{
//		printf("%d  ", *S.base);
//		S.base++;
//	}
//	printf("\n");
//	return;
//
//}
//
//
//void tip2()
//{
//	printf("*********计科101陈东东*************\n");
//	printf("*输入1进栈                        *\n");
//	printf("*输入2出栈                        *\n");
//	printf("*输入0退出                        *\n");
//	printf("***********************************\n");
//}
//
////////////////////////////////
//////////////////////采用链式存储实现队列的初始化、入队、出队操作
//
//typedef struct QNode{//创建队成员
//	int  data;//数据成员
//	struct QNode *next;
//}QNode, *QueuePtr;
//
//typedef struct{//队头队尾指针
//	QueuePtr  front;
//	QueuePtr  rear;
//}LinkQueue;
//
//void InitQueue(LinkQueue &Q)//初始化队列
//{
//	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));//开辟空间
//	if (!Q.front) exit(OVERFLOW);//开辟失败则退出
//	Q.front->next = NULL;
//	//return 1;
//}
//
//int EnQueue(LinkQueue &Q)//入队操作 
//{
//	int e;
//	QueuePtr p;
//	printf("请输入入队元素:");
//	scanf("%d", &e);
//	p = (QueuePtr)malloc(sizeof(QNode));
//	if (p == NULL) exit(OVERFLOW);
//	p->data = e;  p->next = NULL;
//	Q.rear->next = p;//把p插入队尾
//	Q.rear = p;//把p变为队尾
//	return 1;
//}
//
//int DeQueue(LinkQueue &Q)//出队操作 
//{
//	QueuePtr p;
//	int e;
//	if (Q.front == Q.rear){
//		printf("队列为空\n");
//		return -1;
//	}
//	p = Q.front->next;//头指针为空
//	e = p->data;
//	printf("%d  出对\n", e);
//	Q.front->next = p->next;//指针后移
//	if (Q.rear == p) Q.rear = Q.front;//如果p为队尾
//	free(p);//释放p
//	return 1;
//}
//
//void tip3()
//{
//	printf("*************\n");
//	printf("*输入1 进队 *\n");
//	printf("*输入2 出对 *\n");
//	printf("*输入0 退出 *\n");
//	printf("*请选择:    *\n");
//	printf("*************\n");
//}
//
//
///////////////////
//
////////////////////////下面为循环队列
//
//#define MAXQSIZE 100  /*队列的最大长度*/
//typedef struct {
//	int *base;   // 队列的元素空间头指针指示器
//	int  front;
//	int  rear;   /*尾指针指示器*/
//}SqQueue;
//
//int InitQueue(SqQueue &Q) {//初始化操作 
//	Q.base = (int *)malloc(MAXQSIZE*sizeof(int));
//	if (!Q.base) exit(OVERFLOW);
//	Q.front = Q.rear = 0;
//	return 1;
//}
//
//int EnQueue(SqQueue &Q) {//入队操作 
//	int e;
//	if ((Q.rear + 1) % MAXQSIZE == Q.front)
//	{
//		printf("队列已满,不能进队\n");
//		return -1;//满标志 
//	}
//	printf("请输入进队元素:");
//	scanf("%d", &e);
//	Q.base[Q.rear] = e;//进队
//	Q.rear = (Q.rear + 1) % MAXQSIZE;//队尾指针后移
//	return 1;
//}
//
//int DeQueue(SqQueue &Q) {//出队操作 
//	int e;
//	if (Q.front == Q.rear) {
//		printf("队列已经为空\n");
//		return -1;
//	}
//	e = Q.base[Q.front];//队头出队
//	printf("%d  出队\n", e);
//	Q.front = (Q.front + 1) % MAXQSIZE;//队头下标后移
//	return 1;
//}
//
//void tip4()
//{
//	printf("*************\n");
//	printf("*输入1 进队 *\n");
//	printf("*输入2 出对 *\n");
//	printf("*输入0 退出 *\n");
//	printf("*请选择:    *\n");
//	printf("*************\n");
//}
//
//
////////////////////
//void tip0()
//{
//	printf("**********计科101陈东东******************************\n");
//	printf("*Case=1,采用链式存储实现栈的初始化、入栈、出栈操作  *\n");
//	printf("*Case=2,采用顺序存储实现栈的初始化、入栈、出栈操作  *\n");
//	printf("*Case=3,采用链式存储实现队列的初始化、入队、出队操作*\n");
//	printf("*Case=4,采用链式存储实现队列的初始化、入队、出队操作*\n");
//	printf("*Case=0,退出                                        *\n");
//	printf("*请输入Case:                                        *\n");
//	printf("*****************************************************\n");
//
//}
//int main2()
//{
//	int Case;
//	tip0();
//	while (scanf("%d", &Case), Case)
//	{
//		int k;
//		if (Case == 1)//采用链式存储实现栈的初始化、入栈、出栈操作
//		{
//			top = create();
//
//			tip1();
//			while (scanf("%d", &k), k)
//			{
//				switch (k)
//				{
//				case 1:
//					bulidstack();
//					printf("操作完成\n");
//					tip1();
//					break;
//				case 2:
//					outstack();
//					printf("操作完成\n");
//					tip1();
//					break;
//				}
//			}
//
//		}
//		else if (Case == 2)//下面为采用顺序存储实现栈的初始化、入栈、出栈操作
//		{
//			int x;
//			SqStack S;
//			//struct Stack S;
//			tip2();
//			InitStack(S);
//			while (scanf("%d", &k), k)
//			{
//				switch (k)
//				{
//				case 1:
//					printf("请输入进栈元素：");
//					scanf("%d", &x);
//					Push(S, x);
//					printf("操作完毕\n");
//					tip2();
//					break;
//				case 2:
//
//					printf("%d 出栈\n", Pop(S));
//					printf("操作完毕\n");
//					tip2();
//					break;
//				}
//			}
//
//		}
//		else if (Case == 3)//采用链式存储实现队列的初始化、入队、出队操作
//		{
//			LinkQueue Q;
//			InitQueue(Q);//初始化队列
//			tip3();
//			while (scanf("%d", &k), k)
//			{
//				switch (k)
//				{
//				case 1:
//					EnQueue(Q);
//					tip3();
//					printf("操作完毕\n");
//					break;
//				case 2:
//					DeQueue(Q);
//					tip3();
//					printf("操作完毕\n");
//					break;
//				}
//
//			}
//
//		}
//		else if (Case == 4)//采用链式存储实现队列的初始化、入队、出队操作
//		{
//			SqQueue Q;
//			InitQueue(Q);//初始化
//			tip4();
//			while (scanf("%d", &k), k)
//			{
//				switch (k)
//				{
//				case 1:
//					EnQueue(Q);
//					tip4();
//					printf("操作完毕\n");
//					break;
//				case 2:
//					DeQueue(Q);
//					tip4();
//					printf("操作完毕\n");
//					break;
//				}
//			}
//
//		}
//		tip0();
//	}
//	return 0;
//}