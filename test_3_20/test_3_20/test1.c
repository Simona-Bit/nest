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
		tmp = i//��i��ֵ��tmp
			while (tmp / 10)//��whileѭ���ж��м�λ��
			{
			count++;//����������������++
			tmp /= 10;
			}
		tmp = i;//���¸�ֵ
		while (tmp)//�ж�i�Ƿ�Ϊˮ�ɻ���
		{
			sum += pow((tmp % 10), count);//pow��������һ�����Ĵη������������pow��3,3��������27
			tmp /= 10;
		}
		if (sum == i)//���sum����i���ҵ��ˣ��������
			printf("%d ", i);


	}
	return 0;
}