//2.
//���Ͼ��� 
//��һ����ά����.
//�����ÿ�д������ǵ����ģ�ÿ�д��ϵ����ǵ�����.
//�������������в���һ�������Ƿ���ڡ�
//ʱ�临�Ӷ�С��O(N);
//
//һ��
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int findNum(int a[][3], int x, int y, int f){   //��ʱ��a��ָ�룬��(*a)[3]�ȼ�
	int i = 0, j = y - 1;
	while (j >= 0 && i < x){
		if (a[i][j] < f){
			i++;
		}
		else{
			j--;
		}

	}
	return 0;
}
int main(){
	int a[3][3] = { { 1, 3, 5 },
	{ 3, 5, 7 },
	{ 5, 7, 9 } };//���鶨��
	if (findNum(a, 3, 3, 6)){
		printf("It has been found!\n");
	}
	else{
		printf("It hasn't been found!\n");
	}


	system("pause");
	return 0;
}
//���飺
//1 2 3
//2 3 4
//3 4 5
//
//
//1 3 4
//2 4 5
//4 5 6
//
//1 2 3
//4 5 6
//7 8 9
//����
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Point  //����һ���ṹ��
{
	int i;
	int j;
};
struct Point Reseach_sou(int arr[][3], int row, int col, int key)
{
	int i = 0;
	int j = col - 1;
	struct Point ret = { -1, -1 };
	while ((j >= 0) && (i <= 2))
	{
		if (arr[i][j] == key)
		{
			ret.i = i;
			ret.j = j;
			return ret;
		}
		else if (arr[i][j] < key)
			i++;
		else
			j--;
	}
	return ret;
}
int main()
{
	int arr[][3] = { 1, 2, 3, 2, 3, 4, 3, 4, 5 };
	int row = 3;
	int col = 3;
	struct Point ret = Reseach_sou(arr, row, col, 5);
	//����һ���ṹ�����
	if ((ret.i != -1) && (ret.j != -1))
		printf("�ҵ��ˣ�����Ϊ��%d %d\n", ret.i, ret.j);
	else
		printf("�Ҳ���\n");
	system("pause");
	return 0;
}