//5.ʵ��һ���������ж�һ�����ǲ���������
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void su_print(int m)/*�����Խ�ѭ����m���� / 2����sqrtm * **/
{
	int i = 0;
	for (i = 2; i<m; i++)
	{
		if (m%i == 0)
		{
			break;
		}
	}
	if (i >= m)
	{
		printf("�����������\n");
	}
	else
	{
		printf("�������������\n");
	}

}
int main5()
{
	int input = 0;
	printf("��������Ҫ�жϵ���\n");
	scanf("%d", &input);
	su_print(input);
	system("pause");
	return 0;
}