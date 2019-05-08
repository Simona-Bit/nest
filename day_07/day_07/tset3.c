//当条件不成立时，跳出if，输出\0前面的字母，再跳出这个递归，输出倒数第二个，直到递归结束。

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

void reverse_string(char *string)
{
	if ('\0' != *(++string))
		reverse_string(string);
	printf("%c", *(string - 1));
}

int main4()
{
	char *a = "abcde";
	reverse_string(a);
	printf("\n");
	system("pause");
	return 0;
}