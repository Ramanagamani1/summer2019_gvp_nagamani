///*fibonacci memoization*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
int fib(int n,int *a){
	if (n == 0 || n == 1){
		a[n] = n;
		return n;
	}
	else{

		a[n] = fib(n - 1, a) + fib(n - 2, a);
		return a[n];
	}
	return a[n];
}
int main(){
	int n;
	printf("enter a number");
	scanf("%d", &n);
	int *a = (int *)malloc(10 * sizeof(int));
	for (int i = 0; i < 10; i++)
		a[i] = 0;
	int x=fib(n,a);
	printf("%d", x);
	_getch();
}
