#include<stdio.h>
#include<windows.h> 
int main1()
{
	int i = 0;
	int line = 0;
	scanf("%d", &line);//�������к�����һ������i���ͻ�õ���2*i-1����ͼ��
	for (i = 0; i < line; i++)
	{
		int j = 0;
		for (j = 0; j < line - i - 1; j++)
		{
			printf(" ");
		}
		for (j = 0; j < 2 * i + 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	for (i = 0; i < line; i++)
	{
		int j = 0;
		for (j = 0; j < i + 1; j++)
		{
			printf(" ");
		}
		for (j = 0; j < 2 * (line - i - 1) - 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	system("pause");
	return 0;
}