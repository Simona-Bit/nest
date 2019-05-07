//3.实现一个函数判断year是不是润年。
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int my_YEAR(int n)
{
	if ((n % 4 == 0) && (n % 100 != 0) || (n % 400 == 0))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main3()
{
	int input = 0;
	printf("请输入一个年份\n");
	scanf("%d",&input);
	my_YEAR(input);
	if (my_YEAR(input))
	{
		printf("是闰年\n");
	}
	else
	{
		printf("不是闰年\n");	
	}
	system("pause");
	return 0;
}

