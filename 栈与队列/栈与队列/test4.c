//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<malloc.h>
//
////��ʽ�洢ʵ��ջ�ĳ�ʼ������ջ����ջ
//typedef struct node
//{
//	StackElementType data;
//	struct node *next;
//}LinkStackNode;
//typedef LinkStackNode *LinkStack;
//
////��ջ��ջ����
//int Push(LinkStack top, StackElementType x)  /*������Ԫ��xѹ��ջtop��*/
//{
//	LinkStackNode * temp;
//	temp = (LinkStackNode *)malloc(sizeof(LinkStackNode));
//	if (temp == NULL) return(FALSE);     /*����ռ�ʧ��*/
//	temp->data = x;
//	temp->next = top->next;
//	top->next = temp;
//	return(TRUE);      /*�޸ĵ�ǰջ��ָ��*/
//}
//
////��ջ��ջ����
//int Pop(LinkStack top, StackElementType x)  /*��ջtop��ջ��Ԫ�ص������ŵ�x��ָ�Ĵ���ռ���*/
//{
//	LinkStackNode * temp;
//	temp = top->next;
//	if (temp == NULL) 
//		return(FALSE);     /*����ռ�ʧ��*/
//	top->next = temp->next;
//	*x = temp->data;
//	free(temp);
//	return(TRUE);      /*�޸ĵ�ǰջ��ָ��*/
//}
//
//int main(){
//	system("pause");
//	return 0;
//}