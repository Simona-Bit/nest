
#include<stdio.h>
int main()
{
	double sum,sum1 = 0,sum2 = 0;
	int i;
	for (i = 1; i <= 100; i++)
	{
		if (i % 2 == 1) //��ʾ��ĸΪ����
		{
			sum1 += 1.0 / i;
		}
		else if (i % 2 == 0)
		{
			sum2 -= 1.0 / i;
		}
	}
	sum = sum1 + sum2;
	printf("��õ�ֵΪ��%f", sum);
	system("pause");
	return 0;
	
}