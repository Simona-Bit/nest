//1.��д������
//unsigned int reverse_bit(unsigned int value);
//��������ķ���ֵvalue�Ķ�����λģʽ�����ҷ�ת���ֵ��
//
//�磺
//��32λ������25���ֵ�������и�λ��
//00000000000000000000000000011001
//��ת�󣺣�2550136832��
//10011000000000000000000000000000
//���������أ�
//2550136832
//

//#include<stdio.h>
//#include<stdlib.h>
//
//unsigned int reverse_bit(unsigned int value)
//{
//	int i, count = 0;
//	int tmp, sum = 0;
//	for (i = 0; i < 32; i++, value /= 2)
//	{
//		tmp = value % 2;
//		sum = sum * 2 + tmp;
//	}
//	return sum;
//}
//
//int main()
//{
//	printf("%u", reverse_bit(25));
//	system("pause");
//	return 0;
//}
//2.��ʹ�ã�a + b�� / 2���ַ�ʽ������������ƽ��ֵ��
//
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	int num1 = 0;
//	int num2 = 0;
//	scanf("%d%d", &num1, &num2);
//	int avg = num1 - (num1 - num2) / 2;
//	printf("%d", avg);
//	system("pause");
//	return 0;
//}

//3.���ʵ�֣�
//һ��������ֻ��һ�����ֳ�����һ�Ρ������������ֶ��ǳɶԳ��ֵġ�
//���ҳ�������֡���ʹ��λ���㣩
//
#include<stdio.h>
#include<stdlib.h>

//int main()
//{
//	int arr[] = { 4, 45, 6, 4, 6, 8, 8, 45, 5 };
//	int num = sizeof(arr) / sizeof(arr[0]);
//	int t = arr[0];
//	for (int i = 1; i < num; i++)
//	{
//		t = t ^ arr[i];
//	}
//	printf("%d\n", t);
//	system("pause");
//	return 0;
//}
//4.
//��һ���ַ����������Ϊ:"student a am i",
//			���㽫��������ݸ�Ϊ"i am a student".
//			Ҫ��
//			����ʹ�ÿ⺯����
//			ֻ�ܿ������޸��ռ䣨�ռ�������ַ����ĳ����޹أ���
//
//			student a am i
//			i ma a tneduts
//			i am a student

//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <assert.h>
//void reverve_swap(char *left, char *right)
//{
//	assert(left != NULL); //���Բ��ǿ�ָ��
//	assert(right != NULL);
//	while (left < right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//char *reverve(char *p)
//{
//	int len = strlen(p);
//	char *start = p;
//	char *end = NULL;
//	char *ret = p;
//	reverve_swap(p, p + len - 1); //���������ַ���
//	while (*p)
//	{
//		start = p;
//		while ((*p != ' ') && (*p != '\0')) //�ҵ�һ�鵥��
//		{
//			p++;
//		}
//		end = p - 1;
//		reverve_swap(start, end);//���򵥸�����
//		if (*p == ' ') //�ҵ��ո�
//			p++;
//	}
//	return ret;
//
//}
//int main()
//{
//	char arr[] = "student a am I";
//	printf("����ǰ��%s\n", arr);
//	printf("������%s\n", reverve(arr));
//	system("pause");
//	return 0;
//}
