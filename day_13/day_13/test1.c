//1.调整数组使奇数全部都位于偶数前面。
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

int main(){
	int a[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int i = 0, j = 9;
	int tmp;

	while (a[i++] % 2 && i < 10);
	while (a[j--] % 2 == 0 && j >= 0);
	while (i - 1 < j + 1){
		tmp = a[i - 1];
		a[i - 1] = a[j + 1];
		a[j + 1] = tmp;

		while (a[i++] % 2);
		while (a[j--] % 2 == 0);
	}
	/*while (a[i] % 2){
	i++;
	}*/     //多判断一次已经判断过的内容（换过来的数字已经知道奇偶）

	/*while (a[j] % 2 == 0){
	j--;
	}*/

	/*if (i >= j){
	break;
	}*/

	/*tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;*/


	int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int s[10] = { 0 };
	int d[10] = { 0 };
	int i, counts = 0, countd = 0;

	for (i = 0; i < counts; i++){
		a[i] = s[i];
	}

	for (i = 0; i < countd; i++){
		a[counts + i] = s[i];
	}

	for (i = 0; i < 10; i++){
		printf("%d", a[i]);
	}

	system("pause");
	return 0;
}
