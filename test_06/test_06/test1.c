//2.ʹ�ú���ʵ���������Ľ�����
#include<stdio.h>
#include<stdlib.h>
  
void my_swap(int* a, int* b)  //��ʽ������ʵֻ��һ����ʱ�Ŀ���
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
	my_swap(&a, &b); //����������ַ������������������仯
	printf("%d %d\n", a, b);
	system("pause");
	return 0;
}