#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main3()
{
	int i = 0;
	char password[20] = { 0 };
	for (i = 0; i < 3; i++)
	{
		printf("���������룺>");
		scanf("%s",password );//123456
		if (strcmp(password, "123456") == 0)//string compare
		{
			printf("��½�ɹ�\n");
			break;
		}
		else
		{
			printf("����������������룡\n");
		}
	}
	if (i == 3)
	    printf("����������������˳�����\n");
	system("pause");
	return 0;
}