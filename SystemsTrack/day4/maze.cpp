/*#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

int solve(int **matrix,int row,int col, int endx, int endy,int **path,int i,int j){
	if (i < 0 || i>=row||j >= col||j<0||matrix[i][j] == 0)
		return 0;
	if (i == endx&&j == endy)
		return 1;
	    matrix[i][j] = 0;
			if (solve(matrix, row, col, endx, endy, path, i - 1, j) == 1){
				path[i][j] = 1;
				return 1;
			}
			 if (solve(matrix, row, col,  endx, endy, path, i + 1, j) == 1){
				path[i][j] = 1;
				return 1;
			}
			 if (solve(matrix, row, col,  endx, endy, path, i, j - 1) == 1){
				path[i][j] = 1;
				return 1;
			}
			 if (solve(matrix, row, col, endx, endy, path, i, j + 1) == 1){
				path[i][j] = 1;
				return 1;
			}
	return 0;
}
int main(){
	int r, c;
	printf("enter no of rows:");
	scanf("%d", &r);
	printf("enter no. of cols:");
	scanf("%d", &c);
	int **matrix = (int **)malloc(r*sizeof(int*));
	for (int i = 0; i < c; i++)
		matrix[i] = (int *)malloc(c*sizeof(int));
	int startx, starty, endx, endy;
	printf("enter the start coordinates:");
	scanf("%d %d", &startx, &starty);
	printf("enter the end cordinates:");
	scanf("%d %d", &endx, &endy);
	printf("enter the matrix:");
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++)
			scanf("%d", &matrix[i][j]);
	}
	int **path = (int **)calloc(r,sizeof(int*));
	for (int i = 0; i < c; i++)
		path[i] = (int *)calloc(c,sizeof(int));
	path[startx][starty] = 1;
	path[endx][endy]= 1;
	if (solve(matrix,r,c,endx,endy,path,startx,starty)==1){
		printf("the path is:");
		for (int i = 0; i < r; i++){
			for (int j = 0; j < c; j++)
				printf("%d ", path[i][j]);
			printf("\n");
		}
	}
	else{
		printf("no path");
	}
	_getch();
}*/