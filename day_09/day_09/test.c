#include<stdio.h>
#include<stdlib.h>

void game()
{
	int ret = 0;
	init_mine();   //初始化棋盘
	set_mine();    //棋盘布雷
	print_mine();  //打印设计者棋盘
	printf("\n");
	print_player();  //打印玩家棋盘

	safe_mine();  //避免第一次踩雷

	if (count_show_mine() == COUNT) //一步就赢的情况
	{
		printf
	}
}
int main()
{
	system("pause");
	return 0;
}