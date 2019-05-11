#include <stdio.h>
#include<stdlib.h>
#include <string.h>
int binary_search(int arr[], int k, int left, int right)
{
	int mid = 0;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (arr[mid] > k)
		{
			right = mid - 1;
		}
		else if (arr[mid] < k)
		{
			left = mid + 1;
		}
		else
		{
			return mid; //找到了，返回下标
		}
	}
	return -1;
}
int main2()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int k = 7;
	int left = 0;
	int right = sz - 1;
	//调用二分查找函数
	int ret = binary_search(arr, k, left, right);
	if (ret == -1)
	{
		printf("没有找到\n");
	}
	else
	{
		printf("找到了，下标为：%d\n", ret);
	}
	system("pause");
	return 0;
}