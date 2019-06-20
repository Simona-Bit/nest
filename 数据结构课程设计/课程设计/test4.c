#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define M 100

typedef char ElemType;
typedef struct BiTNode{	/* ��������洢�ṹ */
	ElemType data;   /*������*/
	struct BiTNode *lchild, *rchild;   /*�����Ӻ���*/
}BiTNode, *BiTree;

typedef BiTNode* DataType;	/* ջ������Ԫ�����ͣ�ջ�б�����ָ�� */
typedef struct{
	DataType data[M];
	int top;
}SeqStack;					/* ջ�����Ͷ��壬˳��ջ */

void InitSeqStack(SeqStack* s){ /* ��ʼ��ջ */
    /* ���Ƚ���ջ�ռ䣬Ȼ���ʼ��ջ��ָ�� */
	s->top = -1;
}

//�ÿ�ջ
int IsEmpty(SeqStack *s){
	if (s->top == -1)
		return 1;
	else
		return 0;
}

//��ջ
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

//��ջ
int Pop(SeqStack* p, BiTree *x){
	if (p->top == -1){
		return 0;
	}else{
		*x = p->data[p->top];
		p->top--;
		return 1;
	}
}

//ȡջ��Ԫ��
int GetTop(SeqStack* p, BiTree* x){
	if (p->top == -1)
		return 0;
	else{
		*x = p->data[p->top];
		return 1;
	}
}

/* ���������� */
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

/*�������*/
void PreOrderBiTree(BiTree t){
	BiTree p;
	SeqStack S;
	p = t;
	InitSeqStack(&S);
	/*��ջ��*/
	while (p != NULL || !IsEmpty(&S)){
		while (p != NULL){
			printf("%c", p->data);  /*���ʽ��*/
			Push(&S, p);
			p = p->lchild;    /*��������������*/
		}
		if (!IsEmpty(&S)){
			Pop(&S, &p);
			p = p->rchild;
		}
	}
}

/* ��������������ķǵݹ��㷨 */
void InOrderBiTree(BiTree t){
	SeqStack S;
	InitSeqStack(&S);
	BiTree p;
	p = t;
	/*��ջ��*/
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

/*�������*/
void PostOrderBiTree(BiTree t){
	BiTNode *p, *q;
	SeqStack S;
	p = t;
	q = NULL;
	InitSeqStack(&S);
	/*��ջ��*/
	while (p != NULL || !IsEmpty(&S)){
		while (p != NULL){
			Push(&S, p);
			p = p->lchild;
		}
		if (!IsEmpty(&S)){
			GetTop(&S, &p);
			if ((p->rchild == NULL) || (p->rchild == q)){
				printf("%c", p->data);  /*���ʸý��*/
				q = p;
				Pop(&S, &p);
				p = NULL;   /*��pΪ�գ�Ϊ��һ������ջ׼��*/
			}else 
				p = p->rchild;
		}
	}
}

void menu(){
	printf("\t\t*************  �������ı���  ******************\n");
	printf("\t\t-----------------------------------------------\n");
	printf("\t\t*************1.�������������******************\n");
	printf("\t\t*************2.�������������******************\n");
	printf("\t\t*************3.�������������******************\n");
	printf("\t\t*************0.�˳�ϵͳ      ******************\n");
	printf("\t\t-----------------------------------------------\n");
}

int main(){
	BiTree t;
	int m = 1;
	menu();
	printf("\n\t�����봴���Ķ�����:0��ʾ��: ");
	t = createBiTree(&m);
	printf("Succeed!\n");
	while (m != 0){
		printf("��ѡ��");
		scanf("%d", &m);
		switch (m){
		case 1:{
			printf("\n\t�������������: ");
			PreOrderBiTree(t);
			printf("\n");
			break;
		}
		case 2:{
			printf("\n\t������������� ");
			InOrderBiTree(t);
			printf("\n");
			break;
		}
		case 3:{
			printf("\n\t�������������: ");
			PostOrderBiTree(t);
			printf("\n");
			break;
		}
		case 0:{
			m = 0;
		}
		default:printf("�������,����������\n");
		}
	}
	system("pause");
	return 0;
}