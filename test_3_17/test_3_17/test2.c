//3. 编写程序数一下 1到 100 的所有整数中出现多少次数字9。
//输出包含九的数的个数，范围：1~100所有整数
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i = 0;
	int count = 0;//统计9的个数
	for (i = 0; i <= 100; i++)
	{
		if (i % 10 == 9 )
		    count++;
		if (i/10 == 9)
			count++;
	}
	printf("9的个数为：%d\n", count);
	system("pause");
	return 0;
}