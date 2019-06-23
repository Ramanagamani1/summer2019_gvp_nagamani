///*twocolor1*/
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<string.h>
//#include<conio.h>
//#include<malloc.h>
//void twocolorsort(int a[],int n){
//	int sum = 0;
//	for (int i = 0; i < n; i++){
//		sum = sum + a[i];
//	}
//	for (int j = n - 1; j>= 0; j--){
//		if (sum == 0){
//			a[j] = 0;
//		}
//		else{
//			a[j] = 1;
//			sum = sum - 1;
//		}
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
//	twocolorsort(a,n);
//	for (int i = 0; i < n; i++){
//		printf("%d ", a[i]);
//	}
//	_getch();
//}