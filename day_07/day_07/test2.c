//дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮��.
//���磬����DigitSum(1729)����Ӧ�÷���1+7+2+9�����ĺ���19
#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>

int DigitSum(int n)
{
	int sum = 0;
	int m = 0;
	if (n != 0)
	{
		m = n % 10;
		n = n / 10;
		sum = m + DigitSum(n);
	}
	return sum;
}
int main3()
{
	int a;
	printf("������һ�������� ");
	scanf("%d", &a);
	printf("��λ��֮��Ϊ��%d\n", DigitSum(a));
	system("pause");
	return 0;
}