#include<stdio.h>
#include<stdlib.h>

void PrintMap(char map[MAX_ROW][MAX_COL]){
	for (int row = 0; row < MAX_ROW; ++row){
		for (int col = 0; col < MAX_COL; ++col){
			printf("%c ", map[row][col]);
		}
		printf("\n");
	}
}

void UpdateShowMap(char show_map[MAX_ROW][MAX_COL],
	char mine_map[MAX_ROW][MAX_COL], int row, int col){
	//�ж���ǰλ�ã�row,col������Χ8�������м�����
	int count = 0;
	if (row - 1 >= 0 && col - 1 >= 0 &&
		mine_map[row - 1][col - 1] == '1'){
		++count;
	}
	if (row - 1 >= 0 &&
		mine_map[row - 1][col] == '1'){
		++count;
	}
}

int main1()
{
	system("pause");
	return 0;
}