#include<stdio.h>
#include<stdlib.h>

int searchArray(int arr[], int size, int f)//找功能点，原料......
{
	int i;
	for (i = 0; i < size; i++)
	{
		if (arr[i] == f)
		{
			return i;
		}
	}
	return -1;
}

int main1()
{
	int a[10] = { 2, 3, 4, 5, 6, 7, 8, 75, 18, 11};
	printf("%d\n",searchArray);
	system("pause");
	return 0;
}