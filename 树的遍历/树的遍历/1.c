#include<stdio.h>
#include<stdlib.h>

typedef struct tree{
	char data;
	struct tree *lchild;
	struct tree *rchild;
}*Ptree;

Ptree createTree(){   //���Ľ���
	char ch;
	Ptree t;
	ch = getchar();   //�������������
	if (ch == ' ')    //�ж϶������Ƿ�Ϊ��
		t = NULL;
	else{
		t = (Ptree)malloc(sizeof(Ptree));  //������������
		t->data = ch;
		t->lchild = createTree();
		t->rchild = createTree();
	}
	return t;
}

void preOrder(Ptree t){   //�������
	if (t){
		printf("%c", t->data);
		preOrder(t->lchild);
		preOrder(t->rchild);
	}
}

void intOrder(Ptree t){   //�������
	if (t){
		intOrder(t->lchild);
		printf("%c", t->data);
		intOrder(t->rchild);
	}
}

void postOrder(Ptree t){   //�������
	if (t){
		postOrder(t->lchild);
		postOrder(t->rchild);
		printf("%c", t->data);
	}
}

void main(){
	Ptree t;
	printf("���򴴽����������ÿո�������㣺\n");
	t = createTree();
	printf("���������");
	preOrder(t);
	printf("\n");
	printf("���������");
	intOrder(t);
	printf("\n");
	printf("���������");
	postOrder(t);
	printf("\n");
	system("pause");
	return 0;
}