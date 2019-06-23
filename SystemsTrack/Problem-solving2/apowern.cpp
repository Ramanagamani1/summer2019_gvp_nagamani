/*apower*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
int power(int a, int n){
	if (n == 1)
		return a;
	else if (n % 2 == 1)
		return (power(a, n / 2)*power(a, n / 2)*a);
	else
		return (power(a, n / 2)*power(a, n / 2));
}
int main(){
	int a, n;
	printf("enter the base:");
	scanf("%d", &a);
	printf("enter the exponent:");
	scanf("%d", &n);
	int result = power(a, n);
	printf("the power is %d", result);
	_getch();
}