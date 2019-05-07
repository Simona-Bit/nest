//1.实现一个函数，打印乘法口诀表，口诀表的行数和列数自己指定，
//输入9，输出9 * 9口诀表，输入12，输出12 * 12的乘法口诀表。
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

int main1()
{
	int n = 0;
	scanf("n = %d",n);
	int i = 0;
	int j = 0;
	printf("请输入你想打印的行数:\n");
	scanf("%d", &n);
	for (i = 0; i <= n; i++)
	{
		for (j = 0; j <= i; j++)
		{
			printf("%d*%d=%d\t", j, i, j*i);
		}
		//每行输出完后换行
		printf("\n");
	}
	system("pause");
	return 0;
}