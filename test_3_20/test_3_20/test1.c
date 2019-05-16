#include<stdio.h>
#include<math.h>
int main2()
{
	int i = 0;
	for (; i <= 999; i++)
	{
		int tmp = 0;
		int sum = 0;
		int count = 1;
		tmp = i//把i赋值给tmp
			while (tmp / 10)//用while循环判断有几位数
			{
			count++;//满足条件，计数器++
			tmp /= 10;
			}
		tmp = i;//重新赋值
		while (tmp)//判断i是否为水仙花数
		{
			sum += pow((tmp % 10), count);//pow函数，求一个数的次方，如输入参数pow（3,3），即得27
			tmp /= 10;
		}
		if (sum == i)//如果sum等于i，找到了，并且输出
			printf("%d ", i);


	}
	return 0;
}