//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<malloc.h>
//
////链式存储实现栈的初始化、入栈、出栈
//typedef struct node
//{
//	StackElementType data;
//	struct node *next;
//}LinkStackNode;
//typedef LinkStackNode *LinkStack;
//
////链栈进栈操作
//int Push(LinkStack top, StackElementType x)  /*将数据元素x压入栈top中*/
//{
//	LinkStackNode * temp;
//	temp = (LinkStackNode *)malloc(sizeof(LinkStackNode));
//	if (temp == NULL) return(FALSE);     /*申请空间失败*/
//	temp->data = x;
//	temp->next = top->next;
//	top->next = temp;
//	return(TRUE);      /*修改当前栈顶指针*/
//}
//
////链栈出栈操作
//int Pop(LinkStack top, StackElementType x)  /*将栈top的栈顶元素弹出，放到x所指的储存空间中*/
//{
//	LinkStackNode * temp;
//	temp = top->next;
//	if (temp == NULL) 
//		return(FALSE);     /*申请空间失败*/
//	top->next = temp->next;
//	*x = temp->data;
//	free(temp);
//	return(TRUE);      /*修改当前栈顶指针*/
//}
//
//int main(){
//	system("pause");
//	return 0;
//}