//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>  
//#include<stdlib.h>  
//#define maxsize 100  
//typedef struct SqStack
//{
//	int data[maxsize];
//	int top;
//}SqStack;
//
//
//void SqStackEmpty(SqStack *st)//判断栈是否为空
//{
//	st->top == -1 ? printf("栈仍为空,操作可能有风险建议重新调试程序\n") : printf("栈不为空，操作可正常进行\n");
//}
//
//void push(SqStack *st, int i)//进栈
//{
//	if (st->top + i >= maxsize - 1)
//	{
//		printf("overflow! 不能进栈！\n");
//	}
//	else
//	{
//		printf("请输入你要进栈的%d个数据:\n", i);
//		for (int a = 0; a<i; a++)
//			scanf("%d", &st->data[++st->top]);
//	}
//}
//
//void pop(SqStack *st, int j)//出栈
//{
//	if (st->top == -1)
//	{
//		printf("空栈怎能出栈！\n");
//	}
//	else if (st->top - j<-1)
//	{
//		printf("要求出栈的元素过多，已超出栈的存储量");
//	}
//	else
//	{
//		printf("出栈的数据是:\n");
//		for (int a = 0; a<j; a++)
//			printf("%d  ", st->data[st->top--]);
//	}
//	printf("\n");
//}
//
//void printStack(SqStack *st)//打印栈内当前所有的栈元素
//{
//	while (st->top != -1)
//	{
//		printf("栈元素：%d\n", st->data[st->top--]);
//	}
//}
//
//
//void main1(){
//	int i, j, a;
//	SqStack st = { { 1, 2, 3, 4 }, 3 };  //存入四个数据，以及top的位置即4-1=3，top来指示当前栈顶元素的位置
//	SqStackEmpty(&st);
//	while (1)
//	{
//		printf("输入1进栈、2出栈、3打印栈\n");
//		scanf("%d", &a);
//		if (a == 1)
//		{
//			printf("输入你要进栈数据的个数：\n");
//			scanf("%d", &i);
//			push(&st, i);
//			continue;
//		}
//		if (a == 2)
//		{
//			printf("输入你要出栈数据的个数：\n");
//			scanf("%d", &j);
//			pop(&st, j);
//			continue;
//		}
//		if (a == 3)
//		{
//			printf("栈内数据:\n");
//			printStack(&st);
//			continue;
//		}
//		else
//		{
//			printf("输入有误，请重新输入！\n");
//			continue;
//		}
//	}
//}