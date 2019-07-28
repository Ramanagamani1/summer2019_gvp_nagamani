///*three color sort*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<malloc.h>
void threecolorsort(int s[], int n){
	int start = 0, end = n - 1, p = 0;
	int temp;
	while (p <= end){
		if (s[p] == 0){
			temp = s[start];
			s[start] = s[p];
			s[p] = temp;
			start++;
			p++;
		}
		else if (s[p] == 1)
			p++;
		else if (s[p] == 2){
			temp = s[end];
			s[end] = s[p];
			s[p] = temp;
			end--;
		}
	}
}
int main(){
	int *a = (int *)malloc(100 * sizeof(int));
	int n;
	printf("enter no of elements");
	scanf("%d", &n);
	printf("enter numbers 0,1,2");
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	threecolorsort(a, n);
	printf("the sorted elements are:");
	for (int i = 0; i < n; i++){
		printf("%d ", a[i]);
	}
	_getch();
}
