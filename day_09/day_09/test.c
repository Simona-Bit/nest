#include<stdio.h>
#include<stdlib.h>

void game()
{
	int ret = 0;
	init_mine();   //��ʼ������
	set_mine();    //���̲���
	print_mine();  //��ӡ���������
	printf("\n");
	print_player();  //��ӡ�������

	safe_mine();  //�����һ�β���

	if (count_show_mine() == COUNT) //һ����Ӯ�����
	{
		printf
	}
}
int main()
{
	system("pause");
	return 0;
}