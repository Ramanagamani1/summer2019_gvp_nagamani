///*twocolorsort approach2.*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<malloc.h>
void twocolorsort(int a[], int n){
	int start = 0, end = n - 1;
	for (int i = start; start < end; ){
		if (a[start]>a[end]){
			int temp = a[start];
			a[start] = a[end];
			a[end] = temp;
			start++;
			end--;
		}
		else if(a[start]<a[end]){
			start++;
			end--;
		}
		else{
			end--;
		}
	}
}
int main(){
	int *a = (int *)malloc(100 * sizeof(int));
	int n;
	printf("enter no of elements");
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	twocolorsort(a, n);
	for (int i = 0; i < n; i++){
		printf("%d ", a[i]);
	}
	_getch();
}
