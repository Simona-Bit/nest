//��������Ϸ
#define _CRT_SECURE_NO_WARNINGS 1  //define��������пո�
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>

void menu()
{
	printf("*********************************\n");
	printf("******       1.play        ******\n");
	printf("******       2.exit        ******\n");
	printf("*********************************\n");
}

//time_t
void game()
{
	//0-RAND_MAX(32767)
	//NULL-0
	//��ʼָ��
	//int *p = NULL;
	//1�����������
	int ret = 0;
	int guess = 0;
	ret = rand()%100+1;
	//printf("%d\n", ret);
	//2��������
	while (1)
	{
		printf("��������Ҫ�µ����֣�>");
		scanf("%d",&guess);
		if (guess > ret)
		{
			printf("�´���\n");
		}
		else if (guess < ret)
		{
			printf("��С��\n");
		}
		else
		{
			printf("��ϲ�㣬�¶��ˣ�\n");
			break;
		}
	}
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��>");
		scanf("%d",&input);
		switch (input)
		{
		case 1:
			//����Ϸ
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����������ѡ��!\n");
			break;
		}
	} while (input);
	system("pause");
	return 0;
}