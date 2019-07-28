///*spiralrecursive*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<conio.h>
void spiral(int **a,int start_row,int start_column, int row, int col){
	for (int i = start_column; i <=col; i++)
		printf("%d ", a[start_row][i]);
	for (int i = start_row +1; i <=row; i++)
		printf("%d ", a[i][col]);
	if (start_row <=row){
		for (int i = col-1; i >=start_column;i--)
			if (start_row <= row)
			printf("%d ", a[row][i]);
	}
	if (start_column <=col){
		for (int i = row-1; i >start_row; i--)
			printf("%d ", a[i][start_column]);
	}
	if (start_row <=row&&start_column <=col)
		spiral(a, start_row + 1, start_column + 1, row - 1, col - 1);

}
int main(){
	int row, column;
	printf("enter no of rows and columns");
	scanf("%d %d", &row, &column);
	int **a = (int **)malloc(row*sizeof(int));
	for (int i = 0; i < row; i++)
		a[i] = (int *)malloc(column*sizeof(int));
	for (int i = 0; i < row; i++){
		for (int j = 0; j < column; j++){
			scanf("%d", &a[i][j]);
		}
	}
	spiral(a, 0,0,row-1, column-1);
	_getch();
}
