#include<stdio.h>
#include<assert.h>
int my_strlen(const char *p)
{
	assert(p != NULL);
	int num = 0;
	while (*p)
	{
		num++;
		p++;
	}
	return num;
}
int main()
{
	char *p = "abcdefg";
	int ret = my_strlen(p);
	printf("%d", ret);
	return 0;
}