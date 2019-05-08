#include <stdio.h>
#include <stdlib.h>

int fac2(int n)
{
	if (n <= 1)
	{
		return 1;
	}
	else
	{
		return n*fac(n - 1);
	}

}
int main6()
{
	int n = 0;
	printf("请输入一个数：");
	scanf_s("%d", &n);
	int fac(n);
	printf("%d\n", fac(n));
	system("pause");
	return 0;
}