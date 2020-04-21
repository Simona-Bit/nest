
#include<stdio.h>
int main()
{
	double sum;
	int i;
	for (i = 1; i <= 100; i++)
	{
		if (i % 2 == 1) //表示分母为奇数
		{
			sum += 1.0 / i;
		}
		else if (i % 2 == 0)
		{
			sum -= 1.0 / i;
		}
	}
	printf("求得的值为：%f",sum);
	system("pause");
	return 0;
}


















