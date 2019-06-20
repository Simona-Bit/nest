#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define M 100

typedef char ElemType;
typedef struct BiTNode{	/* 二叉链表存储结构 */
	ElemType data;   /*数据域*/
	struct BiTNode *lchild, *rchild;   /*左右子孩子*/
}BiTNode, *BiTree;

typedef BiTNode* DataType;	/* 栈中数据元素类型，栈中保存结点指针 */
typedef struct{
	DataType data[M];
	int top;
}SeqStack;					/* 栈的类型定义，顺序栈 */

void InitSeqStack(SeqStack* s){ /* 初始化栈 */
    /* 首先建立栈空间，然后初始化栈顶指针 */
	s->top = -1;
}

//置空栈
int IsEmpty(SeqStack *s){
	if (s->top == -1)
		return 1;
	else
		return 0;
}

//进栈
int Push(SeqStack* p, BiTree x){
	if (p->top == M - 1){
		printf("error");
		return 0;
	}else{
		p->top++;
		p->data[p->top] = x;
		return 1;
	}
}

//出栈
int Pop(SeqStack* p, BiTree *x){
	if (p->top == -1){
		return 0;
	}else{
		*x = p->data[p->top];
		p->top--;
		return 1;
	}
}

//取栈顶元素
int GetTop(SeqStack* p, BiTree* x){
	if (p->top == -1)
		return 0;
	else{
		*x = p->data[p->top];
		return 1;
	}
}

/* 创建二叉树 */
BiTree createBiTree(){
	BiTree T;
	ElemType ch;
	ch = getchar();
	if (ch == '0') 
		T = NULL;
	else {
		T = (BiTree)malloc(sizeof(BiTNode));
		T->data = ch;
		T->lchild = createBiTree();
		T->rchild = createBiTree();
	}
	return T;
}

/*先序遍历*/
void PreOrderBiTree(BiTree t){
	BiTree p;
	SeqStack S;
	p = t;
	InitSeqStack(&S);
	/*判栈空*/
	while (p != NULL || !IsEmpty(&S)){
		while (p != NULL){
			printf("%c", p->data);  /*访问结点*/
			Push(&S, p);
			p = p->lchild;    /*继续搜索左子树*/
		}
		if (!IsEmpty(&S)){
			Pop(&S, &p);
			p = p->rchild;
		}
	}
}

/* 中序遍历二叉树的非递归算法 */
void InOrderBiTree(BiTree t){
	SeqStack S;
	InitSeqStack(&S);
	BiTree p;
	p = t;
	/*判栈空*/
	while (p != NULL || !IsEmpty(&S)){
		while (p != NULL){
			Push(&S, p);
			p = p->lchild;
		}
		if (!IsEmpty(&S)){
			Pop(&S, &p);
			printf("%c", p->data);
			p = p->rchild;
		}
	}
}

/*后序遍历*/
void PostOrderBiTree(BiTree t){
	BiTNode *p, *q;
	SeqStack S;
	p = t;
	q = NULL;
	InitSeqStack(&S);
	/*判栈空*/
	while (p != NULL || !IsEmpty(&S)){
		while (p != NULL){
			Push(&S, p);
			p = p->lchild;
		}
		if (!IsEmpty(&S)){
			GetTop(&S, &p);
			if ((p->rchild == NULL) || (p->rchild == q)){
				printf("%c", p->data);  /*访问该结点*/
				q = p;
				Pop(&S, &p);
				p = NULL;   /*置p为空，为下一个结点出栈准备*/
			}else 
				p = p->rchild;
		}
	}
}

void menu(){
	printf("\t\t*************  二叉树的遍历  ******************\n");
	printf("\t\t-----------------------------------------------\n");
	printf("\t\t*************1.先序遍历二叉树******************\n");
	printf("\t\t*************2.中序遍历二叉树******************\n");
	printf("\t\t*************3.后序遍历二叉树******************\n");
	printf("\t\t*************0.退出系统      ******************\n");
	printf("\t\t-----------------------------------------------\n");
}

int main(){
	BiTree t;
	int m = 1;
	menu();
	printf("\n\t请输入创建的二叉树:0表示空: ");
	t = createBiTree(&m);
	printf("Succeed!\n");
	while (m != 0){
		printf("请选择：");
		scanf("%d", &m);
		switch (m){
		case 1:{
			printf("\n\t先序遍历二叉树: ");
			PreOrderBiTree(t);
			printf("\n");
			break;
		}
		case 2:{
			printf("\n\t中序遍历二叉树 ");
			InOrderBiTree(t);
			printf("\n");
			break;
		}
		case 3:{
			printf("\n\t后序遍历二叉树: ");
			PostOrderBiTree(t);
			printf("\n");
			break;
		}
		case 0:{
			m = 0;
		}
		default:printf("输入错误,请重新输入\n");
		}
	}
	system("pause");
	return 0;
}