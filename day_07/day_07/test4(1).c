//非递归
#include <stdio.h>
#include <stdlib.h>

int fac1(int n)
{
	int ret = 1;
	int i = 0;
	for (i = 1; i <= n; i++)
	{
		ret = ret*i;
	}
	return ret;
}
int main5()
{
	int n = 0;
	printf("请输入一个数：");
	scanf_s("%d", &n);
	int fac(n);
	printf("%d\n", fac(n));
	system("pause");
	return 0;
}