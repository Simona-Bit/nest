#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAXNODE 300
#define MAX 100
typedef int datatype;
typedef struct Node{
	datatype data;
	struct Node *Lchild, *Rchild;
}NodeType;

// 建立有序表, 采用折半查找实现某一已知的关键字的查找(采用顺序表存储结构)
int Binary_Search(int data[], int key, int n){
	int mid;
	int low = 1, high = n;
	while (low <= high){
		mid = (low + high) / 2;
		if (key == data[mid]){
			return mid;
		}else if (key < data[mid]){
			high = mid - 1;
		}else{
			low = mid + 1;
		}
	}
	return 0;
}

void zhebansearch(){
	int data[MAX];
	int n, i, key, j;
	printf("输入数组长度：");
	scanf("%d", &n);
	printf("输入一组数据:");
	for (i = 1; i <= n; i++){
		scanf("%d", &data[i]);
	}
	printf("输入要找的数据:");
	scanf("%d", &key);
	j = Binary_Search(data, key, n);
	if (j == 0){
		printf("没有此数据!\n");
	}else{
		printf("数据:%d\n", data[j]);
	}
}

//随机产生一组关键字, 利用二叉排序树的插入算法建立二叉排序树
int SearchData(NodeType *T, NodeType **p, NodeType **q, datatype kx){
	int flag = 0; *q = T;
	while (*q){
		if (kx>(*q)->data){
			*p = *q;
			*q = (*q)->Rchild;
		}else{
			if (kx<(*q)->data){
				*p = *q; *q = (*q)->Lchild;
			}else{
				flag = 1;
				break;
			}
		}
	}
	return flag;
}

int InsertNode(NodeType **T, datatype kx){
	int flag = 0;
	NodeType *p = *T, *q, *s;
	if (!SearchData(*T, &p, &q, kx)){
		s = (NodeType*)malloc(sizeof(NodeType));
		s->data = kx;
		s->Lchild = NULL;
		s->Rchild = NULL;
		if (p == NULL){
			*T = s;
		}else{
			if (kx > p->data){
				p->Rchild = s;
			}else{
				p->Lchild = s;
			}
		}
		flag = 1;
	}
	return flag;
}
// 在以上二叉排序树中删除某一指定关键字元素
int DeleteNode(NodeType **T, datatype kx){
	int flag = 0;
	NodeType *p = *T, *q, *s, **f;
	if (SearchData(*T, &p, &q, kx)){
		if (p == q){
			f = T;
		}else{
			f = &(p->Lchild);
			if (kx>p->data)
				f = &(p->Rchild);
		}
		if (q->Rchild == NULL){
			*f = q->Lchild;
		}else{
			if (q->Lchild == NULL){
				*f = q->Rchild;
			}else{
				p = q->Rchild;
				s = p;
				while (p->Lchild){
					s = p;
					p = p->Lchild;
				}
				*f = p;
				p->Lchild = q->Lchild;
				if (s != p){
					s->Lchild = p->Rchild;
					p->Lchild = q->Rchild;
				}
			}
		}
		free(q);
		flag = 1;
	}
	return flag;
}

void InOrder(NodeType *bt){
	if (bt == NULL){
		return;
	}
	InOrder(bt->Lchild);
	printf("%5d", bt->data);
	InOrder(bt->Rchild);
}
//编写一个主函数, 在主函数中设计一个简单的菜单, 分别调试上述算法
void menu(){
	printf("\t\t\t************************************************************\n\n");
	printf("\t\t\t1、建立有序表,采用折半查找实现某一已知的关键字的查找\n\n");
	printf("\t\t\t2、随机产生一组关键字,利用二叉排序树的插入算法建立二叉排序树\n\n");
	printf("\t\t\t3、在以上二叉排序树中删除某一指定关键字元素\n\n");
	printf("\t\t\t4、退出程序！\n\n");
	printf("\t\t\t************************************************************\n\n");
	printf("\t\t\t请选择你要进行的操作：");
}

int main(){
	int n, i;
	NodeType *T = NULL;
	while (1){
		menu();
		scanf("%d", &i);
		if (i == 4){
			break;
		}
		switch (i){
		case 1:{
			zhebansearch();
			break; }
		case 2:{
			int flag, b, d[MAX], i = 1;
			datatype kx;
			printf("请输入数组长度:");
			scanf("%d", &n);
			b = n;
			srand(time(0));
			kx = rand() % 100;
			d[0] = kx;
			while (n != 0){
				flag = InsertNode(&T, kx);
				if (flag == 0){
					printf("Insert Failed\n");
					break;
				}
				kx = rand() % 100;
				d[i] = kx;
				n--;
				i++;
			}
			printf("随机产生的数据:");
			for (i = 0; i < b; i++){
				printf("%4d", d[i]);
			}
			printf("\n");
			printf("二叉树建立后的遍历:");
			InOrder(T);
			printf("\n\n");
			break; }
		case 3:{
			int flag;
			datatype kx;
			printf("请输入要删除的节点数:");
			scanf("%d", &kx);
			flag = DeleteNode(&T, kx);
			if (flag == 0){
				printf("Deleted Failed\n");
			}else{
				printf("Deleted successed\n");
				printf("删除后的遍历:");
				InOrder(T);
				printf("\n\n");
			}
			break; }
		}
	}
	return 0;
}
