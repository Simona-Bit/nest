//5.实现一个函数，判断一个数是不是素数。
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void su_print(int m)/*还可以将循环的m换成 / 2或者sqrtm * **/
{
	int i = 0;
	for (i = 2; i<m; i++)
	{
		if (m%i == 0)
		{
			break;
		}
	}
	if (i >= m)
	{
		printf("这个数是素数\n");
	}
	else
	{
		printf("这个数不是素数\n");
	}

}
int main5()
{
	int input = 0;
	printf("请输入你要判断的数\n");
	scanf("%d", &input);
	su_print(input);
	system("pause");
	return 0;
}