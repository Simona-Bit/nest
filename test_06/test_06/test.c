//1.ʵ��һ����������ӡ�˷��ھ����ھ���������������Լ�ָ����
//����9�����9 * 9�ھ�������12�����12 * 12�ĳ˷��ھ���
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

int main1()
{
	int n = 0;
	scanf("n = %d",n);
	int i = 0;
	int j = 0;
	printf("�����������ӡ������:\n");
	scanf("%d", &n);
	for (i = 0; i <= n; i++)
	{
		for (j = 0; j <= i; j++)
		{
			printf("%d*%d=%d\t", j, i, j*i);
		}
		//ÿ����������
		printf("\n");
	}
	system("pause");
	return 0;
}