#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h> 

int fabonacci(int n)
{
	if (n <= 2)
		return 1;
	else
		return fabonacci(n - 1) + fabonacci(n - 2);
}

int main1()
{
	int n = 3;
	printf("������Ҫ��ڼ�������");
	scanf("%d", &n);
	int ret = fabonacci(n);
	printf("ret=%d\n", ret);
	system("pause");
	return 0;
}