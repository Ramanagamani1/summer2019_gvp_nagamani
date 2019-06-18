///*twocolor1*/
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<string.h>
//#include<conio.h>
//#include<malloc.h>
//void twocolorsort(int a[], int n){
//	int count = 0;
//	int i=0;
//	for (int i = 0; i < n; i++){
//		if (a[i] == 0)
//			count++;
//	}
//	while (count != 0){
//		a[i++] = 0;
//		count--;
//	}
//	for (int j = i; j < n; j++){
//		a[j] = 1;
//	}
//}
//int main(){
//	int *a = (int *)malloc(100 * sizeof(int));
//	int n;
//	printf("enter no of elements");
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++){
//		scanf("%d", &a[i]);
//	}
//	twocolorsort(a, n);
//	for (int i = 0; i < n; i++){
//		printf("%d ", a[i]);
//	}
//	_getch();
//}