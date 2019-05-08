#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int Mypow(int n, int k)
{
	if (k == 0)
	{
		return 1;
	}
	else if (k == 1)
	{
		return n;
	}
	else
	{
		return n*Mypow(n, k - 1);
	}
}

int main2()
{
	int n = 2;
	int k = 5;
	int c = Mypow(n, k);
	printf("%d^%d = %d\n", n, k, c);
	system("pause");
	return 0;
}