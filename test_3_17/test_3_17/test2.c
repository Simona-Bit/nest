//3. ��д������һ�� 1�� 100 �����������г��ֶ��ٴ�����9��
//��������ŵ����ĸ�������Χ��1~100��������
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i = 0;
	int count = 0;//ͳ��9�ĸ���
	for (i = 0; i <= 100; i++)
	{
		if (i % 10 == 9 )
		    count++;
		if (i/10 == 9)
			count++;
	}
	printf("9�ĸ���Ϊ��%d\n", count);
	system("pause");
	return 0;
}