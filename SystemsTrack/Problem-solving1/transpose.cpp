///*transpose*/
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<string.h>
//#include<malloc.h>
//#include<conio.h>
//void transpose(int **a, int row, int column){
//	/*int res[10][10];
//	for (int i = 0; i < row; i++){
//		for (int j = 0; j < column; j++){
//			res[i][j] = a[j][i];
//		}
//	}*/
//	for (int i = 0; i < column; i++){
//		for (int j = 0; j < row; j++)
//			printf("%d ", a[j][i]);
//		printf("\n");
//	}
//}
//int main(){
//	int n, m;
//	printf("enter no of rows and columns");
//	scanf("%d %d", &n, &m);
//	int **a = (int **)malloc(n*sizeof(int));
//	for (int i = 0; i < n; i++)
//		a[i] = (int *)malloc(m*sizeof(int));
//	for (int i = 0; i < n; i++){
//		for (int j = 0; j < m; j++){
//			scanf("%d", &a[i][j]);
//		}
//	}
//	transpose(a, n, m);
//
//	_getch();
//	return 0;
//}