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
//void SqStackEmpty(SqStack *st)//�ж�ջ�Ƿ�Ϊ��
//{
//	st->top == -1 ? printf("ջ��Ϊ��,���������з��ս������µ��Գ���\n") : printf("ջ��Ϊ�գ���������������\n");
//}
//
//void push(SqStack *st, int i)//��ջ
//{
//	if (st->top + i >= maxsize - 1)
//	{
//		printf("overflow! ���ܽ�ջ��\n");
//	}
//	else
//	{
//		printf("��������Ҫ��ջ��%d������:\n", i);
//		for (int a = 0; a<i; a++)
//			scanf("%d", &st->data[++st->top]);
//	}
//}
//
//void pop(SqStack *st, int j)//��ջ
//{
//	if (st->top == -1)
//	{
//		printf("��ջ���ܳ�ջ��\n");
//	}
//	else if (st->top - j<-1)
//	{
//		printf("Ҫ���ջ��Ԫ�ع��࣬�ѳ���ջ�Ĵ洢��");
//	}
//	else
//	{
//		printf("��ջ��������:\n");
//		for (int a = 0; a<j; a++)
//			printf("%d  ", st->data[st->top--]);
//	}
//	printf("\n");
//}
//
//void printStack(SqStack *st)//��ӡջ�ڵ�ǰ���е�ջԪ��
//{
//	while (st->top != -1)
//	{
//		printf("ջԪ�أ�%d\n", st->data[st->top--]);
//	}
//}
//
//
//void main1(){
//	int i, j, a;
//	SqStack st = { { 1, 2, 3, 4 }, 3 };  //�����ĸ����ݣ��Լ�top��λ�ü�4-1=3��top��ָʾ��ǰջ��Ԫ�ص�λ��
//	SqStackEmpty(&st);
//	while (1)
//	{
//		printf("����1��ջ��2��ջ��3��ӡջ\n");
//		scanf("%d", &a);
//		if (a == 1)
//		{
//			printf("������Ҫ��ջ���ݵĸ�����\n");
//			scanf("%d", &i);
//			push(&st, i);
//			continue;
//		}
//		if (a == 2)
//		{
//			printf("������Ҫ��ջ���ݵĸ�����\n");
//			scanf("%d", &j);
//			pop(&st, j);
//			continue;
//		}
//		if (a == 3)
//		{
//			printf("ջ������:\n");
//			printStack(&st);
//			continue;
//		}
//		else
//		{
//			printf("�����������������룡\n");
//			continue;
//		}
//	}
//}