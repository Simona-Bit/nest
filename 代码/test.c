
#include<stdio.h>
int main()
{
	double sum;
	int i;
	for (i = 1; i <= 100; i++)
	{
		if (i % 2 == 1) //��ʾ��ĸΪ����
		{
			sum += 1.0 / i;
		}
		else if (i % 2 == 0)
		{
			sum -= 1.0 / i;
		}
	}
	printf("��õ�ֵΪ��%f",sum);
	system("pause");
	return 0;
}


















