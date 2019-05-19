//2.
//杨氏矩阵 
//有一个二维数组.
//数组的每行从左到右是递增的，每列从上到下是递增的.
//在这样的数组中查找一个数字是否存在。
//时间复杂度小于O(N);
//
//一、
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int findNum(int a[][3], int x, int y, int f){   //此时的a是指针，与(*a)[3]等价
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
	{ 5, 7, 9 } };//数组定义
	if (findNum(a, 3, 3, 6)){
		printf("It has been found!\n");
	}
	else{
		printf("It hasn't been found!\n");
	}


	system("pause");
	return 0;
}
//数组：
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
//二、
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Point  //定义一个结构体
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
	//返回一个结构体变量
	if ((ret.i != -1) && (ret.j != -1))
		printf("找到了，坐标为：%d %d\n", ret.i, ret.j);
	else
		printf("找不到\n");
	system("pause");
	return 0;
}