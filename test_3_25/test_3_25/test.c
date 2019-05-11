//猜数字游戏
#define _CRT_SECURE_NO_WARNINGS 1  //define后面必须有空格
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
	//初始指针
	//int *p = NULL;
	//1、生成随机数
	int ret = 0;
	int guess = 0;
	ret = rand()%100+1;
	//printf("%d\n", ret);
	//2、猜数字
	while (1)
	{
		printf("请输入你要猜的数字：>");
		scanf("%d",&guess);
		if (guess > ret)
		{
			printf("猜大了\n");
		}
		else if (guess < ret)
		{
			printf("猜小了\n");
		}
		else
		{
			printf("恭喜你，猜对了！\n");
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
		printf("请选择：>");
		scanf("%d",&input);
		switch (input)
		{
		case 1:
			//玩游戏
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择!\n");
			break;
		}
	} while (input);
	system("pause");
	return 0;
}