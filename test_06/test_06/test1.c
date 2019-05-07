//2.使用函数实现两个数的交换。
#include<stdio.h>
#include<stdlib.h>
  
void my_swap(int* a, int* b)  //形式参数其实只是一份临时的拷贝
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
int main2()
{
	int a = 1;
	int b = 2;
	printf("%d %d\n", a, b);
	my_swap(&a, &b); //给函数传地址否则最后的输出不发生变化
	printf("%d %d\n", a, b);
	system("pause");
	return 0;
}