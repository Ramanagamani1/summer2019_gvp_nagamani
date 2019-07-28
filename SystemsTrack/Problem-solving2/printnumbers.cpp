///*print numbers 0 to 99 if n=3*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
void numberprint(int prev[],int n,int currstate,int limit ){
	int  end = 0;
	if (limit == n){
		for (int i = 0; i < currstate; i++){
			printf("%d", prev[i]);
		}
		printf("\n");
	}
	else{
		for (int i = 0; i <=9; i++){
			prev[currstate] = i;
			numberprint(prev, n,currstate + 1, limit + 1);
		}
	}

}
int main(){
	int n;
	printf("enter a number:");
	scanf("%d", &n);
	int *prev = (int *)malloc(10 * sizeof(int));
	for (int i = 0; i < 10; i++)
		prev[i] = 0;
	numberprint(prev,n,0,1);
	_getch();
}
