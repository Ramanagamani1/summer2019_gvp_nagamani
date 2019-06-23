///*finding words in dictionary*/
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<conio.h>
//#include<malloc.h>
//int direction(char **a, char *str,int rows,int cols,int rowind,int colind,int strptr,int dir ){
//	if (str[strptr] == '\0')
//		return 1;
//	else{
//		if (str[strptr] == a[rowind][colind]){
//			if (dir == 0&&rowind!=0){
//				direction(a, str, rows,cols,rowind-1 , colind, strptr + 1, 0);
//			}
//			if (dir == 1&&rowind!=rows){
//				direction(a, str, rows,cols , rowind+1,colind, strptr + 1, 1);
//			}
//			if (dir == 2&&rowind!=rows&&colind!=cols){
//				direction(a, str, rows, cols,rowind+1, colind+1, strptr + 1, 2);
//			}
//			if (dir == 3&&rowind!=0&&colind!=0){
//				direction(a, str, rows,cols, rowind-1, colind-1, strptr + 1, 3);
//			}
//			if (dir == 4&&rowind!=rows&&colind!=0){
//				direction(a, str, rows,cols, rowind+1, colind-1, strptr + 1, 4);
//			}
//			if (dir == 5&&rowind!=0&&colind!=cols){
//				direction(a, str, rows, cols,rowind-1, colind+1, strptr + 1, 5);
//			}
//			if (dir == 6&&colind!=0){
//				direction(a, str, rows,cols, rowind, colind-1, strptr + 1, 6);
//			}
//			if (dir == 7&&colind!=cols){
//				direction(a, str, rows, cols,rowind, colind+1, strptr + 1, 7);
//			}
//		}
//	}
//	return 0;
//}
//int search(char **a,char *str,int r,int c){
//	int count = 0;
//	int t = 0, b = 1, drd=2,dlu=3,dld=4,dru=5,l=6,r1=7;
//	int k = 0;
//	for (int i = 0; i < r; i++){
//		for (int j = 0; j < c; j++){
//			if (str[k] == a[i][j]){
//				if (str[k+1] == a[i - 1][j]&&i!=0)
//					count+=direction(a, str+2, r,c, i - 1, j,k+2,0);
//				if (str[k+1] == a[i + 1][j]&&i!=r)
//					count += direction(a, str+2, r,c, i + 1, j,k+2,1);
//				if (str[k+1] == a[i + 1][j+1]&&i!=r&&j!=c)
//					count += direction(a, str + 2, r,c, i + 1, j + 1, k + 2,2);
//				if (str[k+1] == a[i -1][j-1]&&i!=0&&j!=0)
//					count += direction(a, str + 2, r, c,i -1, j-1, k + 2,3);
//				if (str[k+1] == a[i+1][j-1]&&j!=0)
//					count += direction(a, str + 2, r, c,i + 1, j-1, k + 2,4);
//				if (str[k+1] == a[i-1][j+1]&&j!=c)
//					count += direction(a, str + 2, r,c, i - 1, j+1, k + 2,5);
//				if (str[k+1] == a[i][j-1]&&i!=0&&j!=c)
//					count += direction(a, str + 2, r, c,i , j-1, k + 2,6);
//				if (str[k+1] == a[i][j+1]&&i!=r&&j!=0)
//					count += direction(a, str + 2, r,c, i , j+1, k + 2,7);
//			}
//		}
//	}
//	return count;
//}
//
//int main(){
//    int  r,c;
//	char *s = (char *)malloc(10 * sizeof(int));
//	printf("enter the string:");
//	scanf("%s", s);
//
//	printf("enter no of rows and columns");
//	scanf("%d %d", &r, &c);
//	char **a = (char **)malloc(r* sizeof(char*));
//	
//	for (int i = 0; i < r; i++)
//		a[i] = (char *)malloc(c* sizeof(char));
//	
//	printf("enter the matrix");
//
//	for (int i = 0; i < r; i++){
//		for (int j = 0; j < c; j++)
//			scanf(" %c", &a[i][j]);
//	} 
//  int count=search(a, s, r, c);
//  printf("%d", count);
//  _getch();
//}
