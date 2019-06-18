///*distinct permutations*/
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<conio.h>
//#include<malloc.h>
//int checkdistinct(int a[],int start,int end){
//	for (int i = start; i < end; i++){
//		if (a[i] == a[end])
//			return 0;
//	}
//	return 1;
//}
//void permutations(int a[], int start, int end){
//	if (start == end)
//	{
//		for (int i = 0; i < end; i++)
//			printf("%d", a[i]);
//		printf("\n");
//	}
//	else{
//		for (int i = start; i < end; i++){
//			int flag = checkdistinct(a, start, i);
//				if (flag == 1){
//					int temp = a[i];
//					a[i] = a[start];
//					a[start] = temp;
//
//
//					permutations(a, start + 1, end);
//					temp = a[i];
//					a[i] = a[start];
//					a[start] = temp;
//				}
//		}
//	}
//}
//int main(){
//	int n;
//	int *a = (int *)malloc(100 * sizeof(int));
//	printf("enter the no of elements:");
//	scanf("%d", &n);
//	printf("enter the array elements:");
//	for (int i = 0; i < n; i++)
//		scanf("%d", &a[i]);
//	int *prev = (int *)malloc(10 * sizeof(int));
//	for (int i = 0; i < 10; i++)
//		prev[i] = 0;
//	permutations(a, 0, n);
//	_getch();
//}*/