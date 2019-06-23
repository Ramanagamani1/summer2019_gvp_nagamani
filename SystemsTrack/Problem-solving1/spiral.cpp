///*spiral*/
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<string.h>
//#include<malloc.h>
//#include<conio.h>
//void spiral(int **a, int row, int col){
//	int r = 0, c = 0;
//	int r1 = row, c1 = col;
//	while (r<r1 && c<c1){
//		for (int i = c; i < c1; i++)
//			printf("%d ", a[r][i]);
//		r++;
//		for (int j = r; j < r1; j++){
//			printf("%d ", a[j][c1 - 1]);
//		}
//		c1--;
//		if (r <r1){
//			for (int i = c1 - 1; i >=c; --i)
//				if (r<r1)
//				printf("%d ", a[r1 - 1][i]);
//			r1--;
//		}
//		if (c <c1){
//			for (int i = r1 - 1; i >= r; --i)
//				printf("%d ", a[i][c]);
//			c++;
//		}
//	}
//}
//int main(){
//	int row, column;
//	printf("enter no of rows and columns");
//	scanf("%d %d", &row, &column);
//	int **a = (int **)malloc(row*sizeof(int));
//	for (int i = 0; i < row; i++)
//		a[i] = (int *)malloc(column*sizeof(int));
//	for (int i = 0; i < row; i++){
//		for (int j = 0; j < column; j++){
//			scanf("%d", &a[i][j]);
//		}
//	}
//	spiral(a, row, column);
//	_getch();
//}