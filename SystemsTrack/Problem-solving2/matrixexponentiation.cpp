///*matrix exponentiation*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
void multiply(int **matrix1,int row,int col){
	
	int res[2][2];
	int matrix[2][2];
	matrix[0][0] = 0, matrix[0][1] = 1, matrix[1][0] = 1, matrix[1][1] = 1;
	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++){
			res[i][j] = 0;
			for (int k = 0; k < row; k++)
				res[i][j] += matrix1[i][k] * matrix[k][j];
		}
	}
	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++){
			matrix1[i][j] = res[i][j];
		}
	}
}
int matrix(int n){
	int **matrix1 = (int **)malloc(2 * sizeof(int));
	for (int i = 0; i < 2; i++)
		matrix1[i] = (int *)malloc(2 * sizeof(int));
	matrix1[0][0] = 0;
	matrix1[0][1] = 1;
	matrix1[1][0] = 1;
	matrix1[1][1] = 1;
	for (int i = 1; i < n; i++){
		multiply(matrix1, 2, 2);
	}
	return matrix1[1][1];
}
int main(){
	int n;
	printf("enter the number:");
	scanf("%d", &n);
	int num=matrix(n);
	printf("the fibonacci no is %d", num);
	_getch();
}
