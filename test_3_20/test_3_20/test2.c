#include<stdio.h>

int main()

{

	int i = 0;

	int a = 0;

	int sum = 0;

	int num = 0;

	scanf("%d", &num);

	for (i = 0; i < 5; i++)

	{

		a = a * 10 + num;

		sum = sum + a;

	}

	printf("%d", sum);

	return 0;

}