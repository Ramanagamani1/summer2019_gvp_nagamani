/*#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
int isOperator(char ch){
	if (ch == '*' || ch == '+' || ch == '-' || ch == '/' || ch == '%' || ch == ')' || ch == '(')
	{
		return 1;
	}
	return 0;
}
void push(char *stack, int *top,char ch)
{
	*top = (*top)+1;
	stack[*top] = ch;
	
}
char pop(char *stack, int *top)
{
	char value = stack[*top];
	*top = (*top)-1;
	return value;
}
int precedence(char op)
{
	if (op == '(')
		return 1;
	else if (op == '-' || op == '+')
		return 3;
	else if (op == '%')
		return 2;
	else if (op == '/' || op == '*')
		return 4;
	return 0;
}

char *postfix(char *s)
{
	char *stack = (char *)malloc(100 * sizeof(char));
	char *post = (char *)malloc(100 * sizeof(char));
	int k = 0;
	int top = -1;
	char op;
	for (int i = 0; s[i] != '\0'; i++){
		if (isOperator(s[i])){
			if (top == -1){
				if (k != 0){
					post[k] = ',';
					k = k + 1;
				}
				push(stack, &top, s[i]);
			}
			else if (s[i]=='('){
				push(stack, &top, s[i]);
			}
			else if (s[i] == ')')
			{
				while (stack[top] != '(')
				{
					if (isOperator(stack[top])){
						post[k] = ',';
						k = k + 1;
						op = pop(stack, &top);
						if (op != '('){
							post[k] = ',';
							k = k + 1;
							post[k] = op;
							k = k + 1;
						}
					}
					else{
						post[k] = ',';
						k = k + 1;
						post[k] = s[i];
						k=k+1;
					}
				}
				
				pop(stack, &top);
				
			}
			else if (top != -1 && precedence(s[i])<precedence(stack[top])){
				post[k] = ',';
				k = k + 1;
				op = pop(stack,&top);
				push(stack, &top, s[i]);
				post[k] = op;
				k=k+1;
				post[k] = ',';
				k = k + 1;
			}
			else if (top != -1 && precedence(s[i]) >= precedence(stack[top])){
				post[k] = ',';
				k = k + 1;
				push(stack, &top, s[i]);
				
			}
			else{
				post[k] = ',';
				k = k + 1;
				post[k] = s[i];
				k=k+1;
			}
			
		}
		else{
			post[k] = s[i];
			k=k+1;
		}
		
	}
	
	while (top != -1){
		post[k ] = ',';
		post[k+1] = pop(stack, &top);
		
		k=k+2;
	}
	post[k] = '\0';
	return post;
}
int main(){
	char *s = "A1+1";
	char *res = postfix(s);
	printf("%s", res);
	_getch();
}*/