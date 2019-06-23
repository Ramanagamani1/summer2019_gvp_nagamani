#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
void callprint(struct node **matrix);
int toNum(char *n);
int evaluate(char *op1, char *op2, char op, struct node **matrix);
int parse(char *string, int index,int row,int col, struct node **matrix);
void callset(char *string, int index, struct node **matrix);
int callget(char *string, int index, struct node **matrix);
void push1(int *resstack, int *top1, int val);
int pop1(int *resstack, int *top1);

struct node{
	int val;
	char *formula;
};
int postfixeval(struct node **matrix, char *str,char *ostr,int row,int col){
	int k = 0, l = 0,top1=-1;
	int *resstack = (int *)malloc(30 * sizeof(int));
	
	char *op2 = (char *)malloc(100 * sizeof(char));
	int val = 0,val1=0,val2=0;
	for (int i = 0; str[i] != '\0';)
	{
		val = 0;
		k = 0, l = 0;
		char *op1 = (char *)malloc(100 * sizeof(char));
		if (str[i] == '+'||str[i] == '-'||str[i] == '*'||str[i] == '/'||str[i] == '%'){
			val1 = pop1(resstack, &top1);
			val2 = pop1(resstack, &top1);
			if (str[i] == '+')
				push1(resstack, &top1, val1 + val2);
			else if (str[i] == '-')
				push1(resstack, &top1, val1 - val2);
			else if (str[i] == '*')
				push1(resstack, &top1, val1 * val2);
			else if (str[i] == '/')
				push1(resstack, &top1, val1 / val2);
			else if (str[i] == '%')
				push1(resstack, &top1, val1 % val2);
			i++;
			if (str[i] == ',')
				i++;
		}
		else{
			while (str[i] != ','&&str[i] != '+'&&str[i] != '-'&&str[i] != '*'&&str[i] != '/'&&str[i] != '%'&&str[i] != '\0'){
				op1[k] = str[i];
				k++, i++;
			}
			op1[k] = '\0';
			matrix[row][col].formula = ostr;
			if (str[i] == '\0'){
				if (op1[0] >= '0'&&op1[0] <= '9'){
					val1 = toNum(op1);
					matrix[row][col].formula = NULL;
				}
				else{
					val1 = callget(op1, 0, matrix);
				}
				return val1;
			}
			if (op1[0] >= '0'&&op1[0] <= '9'){
				val1 = toNum(op1);
			}
			else{
				val1 = callget(op1, 0, matrix);
			}
			matrix[row][col].formula = ostr;
			k = 0;
			push1(resstack, &top1, val1);
			if (str[i] == ',')
				i++;
			while (str[i] != ','&&str[i] != '+'&&str[i] != '-'&&str[i] != '*'&&str[i] != '/'&&str[i] != '%'&&str[i] != '\0'){
				op2[k] = str[i];
				k++, i++;
			}
			op2[k] = '\0';
			if (op2[0] >= '0'&&op2[0] <= '9'){
				val2 = toNum(op2);
			}
			else{
				val2 = callget(op2, 0, matrix);
			}
			push1(resstack, &top1, val2);
			if (str[i] == ',')
				i++;
		}
	}
	return resstack[top1];
}
void callimportstudent(struct node **matrix, char *string, int index){
	char *val = (char *)malloc(10 * sizeof(char));
	while (string[index] == ' ')
		index++;
	FILE *fp = fopen(string + index, "r");
	if (fp == NULL)
		printf("file does not exist");
	else{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				fscanf(fp, "%s, ", val);
				if (val[0] >= '0'&& val[0] <= '9')
					matrix[i][j].val = toNum(val);
				else
					matrix[i][j].formula = val;
			}
			fscanf(fp, "\n");

		}
	}
	fclose(fp);

}
void callimport(struct node **matrix, char *string, int index)
{
	char *val = (char *)malloc(10 * sizeof(char));
	while (string[index] == ' ')
		index++;
	FILE *fp = fopen(string + index, "r");
	if (fp == NULL)
		printf("file does not exist");
	else{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				fscanf(fp, "%s, ", val);
				if (val[0] >= '0'&& val[0] <= '9')
					matrix[i][j].val = toNum(val);
				else
					matrix[i][j].formula = val;
			}
			fscanf(fp, "\n");

		}
	}
}

void callsave(struct node **matrix, char *string, int index, int *flag)
{
	if (*flag == 0)
		printf("file not exported");
	else{
		FILE *fp = fopen(string + index, "w");
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (matrix[i][j].formula != NULL)
					fprintf(fp, "%s, ", matrix[i][j].formula);
				else
					fprintf(fp, "%d, ", matrix[i][j].val);
			}
			fprintf(fp, "\n");
		}
		fclose(fp);
	}


}
char *callexport(struct node **matrix, char *string, int index, int *flag)
{
	int indice = index + 1, k = 0;
	char *path = (char *)malloc(10 * sizeof(char));
	while (string[indice] != '\0')
		path[k++] = string[indice++];
	path[k] = '\0';
	while (string[index] == ' ')
		index++;
	FILE *fp = fopen(string + index, "w");
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (matrix[i][j].formula != NULL)
				fprintf(fp, "%s, ", matrix[i][j].formula);
			else
				fprintf(fp, "%d, ", matrix[i][j].val);
		}
		fprintf(fp, "\n");
	}
	*flag = 1;
	fclose(fp);
	return path;
}
void callprint(struct node **matrix){
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (matrix[i][j].formula == NULL)
				printf("%d ", matrix[i][j].val);
			else
			{
				printf("%s ", matrix[i][j].formula);

			}
		}
		printf("\n");
	}
}
int toNum(char *n)
{
	int i = 0, j = 1;
	int val = 0;
	while (n[i] != '\0')
	{
		int num = n[i] - '0';
		val += num * j;
		j = j * 10;
		i++;
	}
	return val;
}
int isOperator(char ch){
	if (ch == '*' || ch == '+' || ch == '-' || ch == '/' || ch == '%' || ch == ')' || ch == '(')
	{
		return 1;
	}
	return 0;
}
void push1(int *resstack, int *top1, int val)
{
	*top1 = (*top1) + 1;
	resstack[*top1] = val;

}
int pop1(int *resstack, int *top1)
{
	int value = resstack[*top1];
	*top1 = (*top1) - 1;
	return value;
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
int evaluate(char *op1, char *op2, char op, struct node **matrix)
{
	int val1, val2;
	if (op1[0] >= 'A')
		val1 = callget(op1, 0, matrix);
	else
		val1 = toNum(op1);
	if (op2[0] >= 'A')
		val2 = callget(op2, 0, matrix);
	else
		val2 = toNum(op2);

	if (op == '+'){
		return val1 + val2;
	}
	if (op == '*')
		return val1 * val2;
	if (op == '/')
		return val1 / val2;
	if (op == '-')
		return val1 - val2;
	if (op == '%')
		return val1 % val2;

	return 0;
}

int parse(char *str, int index, int row,int col,struct node **matrix)
{
	int i = 0,k=0,l=0;
	char op;
	int val1=0, val2=0;
	char *op1 = (char *)malloc(100 * sizeof(char));
	char *op2 = (char *)malloc(100 * sizeof(char));
	
    matrix[row][col].formula = str;

	
	while (str[i] != '\0'&&str[i] != '+'&&str[i] != '-'&&str[i] != '*'&&str[i] != '/'&&str[i] != '%'){
			op1[k++] = str[i];
		i++;
	}
	op1[k] = '\0';
	if (str[i] == '\0'){
		if (op1[0] >= '0'&&op1[0] <= '9'){
			 val1 = toNum(op1);
			matrix[row][col].formula = NULL;
		}
		else{
			val1 = callget(op1, 0, matrix);
		}
		matrix[row][col].val = val1;
	}
	else{
		op = str[i];
		i++;
		while (str[i] != '\0'){
			
				op2[l++] = str[i];

			i++;
		}
		op2[l] = '\0';
		matrix[row][col].val = evaluate(op1, op2, op, matrix);
	}
	return matrix[row][col].val;
}
int cycledetection(char *string, struct node **matrix,char cycle[])
{
	char dum[3];
	int row, col;
	int i = 0,flag=1;
	while (string[i] != '\0')
	{
		int j = 0;
		while (string[i] != '+' && string[i] != '-' && string[i] != '*' && string[i] != '/' && string[i] != '%' && string[i] != '\0'){
			dum[j++] = string[i];
			i++;
		}
		dum[j] = '\0';
		if (string[i] == '\0')
			flag = 0;
		if (string[i] == '+' || string[i] == '-' || string[i] == '*' || string[i] == '/' || string[i] == '%')
			i++;
		if (flag == 0 && dum[0] >= '0'&& dum[0] <= '9')
			return 0;
		col = dum[0] - 'A';
		row = dum[1] - '0' - 1;
		if (matrix[row][col].formula != NULL)
		{
			char formula[3];
			int i = 0;
			//printf("%s", matrix[row][col].formula);
			while (matrix[row][col].formula[i] != '\0'){
				int j = 0;
				while (matrix[row][col].formula[i] != '+' && matrix[row][col].formula[i] != '-' && matrix[row][col].formula[i] != '*' && matrix[row][col].formula[i] != '/' && matrix[row][col].formula[i] != '%' && matrix[row][col].formula[i] != '\0'){
					formula[j++] = matrix[row][col].formula[i];
					i++;
				}
				formula[j] = '\0';
               if (strcmp(formula, cycle) == 0){
					printf("there is a loop");
					return 1;
				}
			   if (matrix[row][col].formula[i] == '+' || matrix[row][col].formula[i] == '-' || matrix[row][col].formula[i] == '*' || matrix[row][col].formula[i] == '/' || matrix[row][col].formula[i] == '%')
				   i++;
			}
		}
	}
	return 0;
}
	

void callset(char *string, int index, struct node **matrix)
{
	char cycle[3];
	int row, col;
	while (*string!= ' ')
		string++;
	while (*string == ' ')
		string++;
	cycle[0] = string[0];
	cycle[1] = string[1];
	cycle[2] = '\0';
	col = string[0] - 'A';
	row = string[1] - '0' - 1;
	while (*string != '=')
		string++;
	char *s;
	if (cycledetection(string + 1, matrix,cycle) == 1)
		return;
		s = postfix(string + 1);
	matrix[row][col].val = postfixeval(matrix,s,string+1,row,col);

	//else
		//printf("invalid command");
}

int callget(char *string, int index, struct node **matrix)
{
	int val = 0;
	int row, col;
	int i=0;
	for (int i = index; string[i] != '\0';){
		if (string[i] == ' '){
			i++;
		}
		if (string[i] >= 'A' && string[i] <= 'J'){
			col = string[i] - 'A';
			i++;
		}
		if (string[i] >= '0' && string[i] <= '9'){
			row = string[i] - '0' - 1;
			i++;
		}
	}
	
         	if (matrix[row][col].formula == NULL)
		return matrix[row][col].val;
	else{
		char *s;
		s= postfix(matrix[row][col].formula);
		int res = postfixeval(matrix, s, matrix[row][col].formula, row, col);
		return res;
	}
}



int main()
{
	int flag = 0;
	struct node **matrix = (struct node **)calloc(10, sizeof(struct node*));
	for (int i = 0; i < 10; i++){
		matrix[i] = (struct node *)calloc(10, sizeof(struct node));
	}
	while (1){
		char *string = (char *)malloc(100 * sizeof(char));
		char *s = (char *)malloc(10 * sizeof(char));
		printf(">");
		gets(string);
		int i;
		char *command = (char *)malloc(100 * sizeof(char));
		for (i = 0; (string[i] != ' '&&string[i] != '\0'); i++){
			command[i] = string[i];
		}
		command[i] = '\0';
		if (strcmp(command, "GET") == 0){
			int result = callget(string, i, matrix);
			printf("%d", result);
		}
		if (strcmp(command, "SET") == 0){
			callset(string, i, matrix);
		}
		if (strcmp(command, "PRINT") == 0){
			callprint(matrix);
		}
		if (strcmp(command, "EXPORT") == 0){
			s = callexport(matrix, string, i, &flag);
			printf("%s", s);
		}
		if (strcmp(command, "IMPORT") == 0){
			callimportstudent(matrix, string, i);
		}
		if (strcmp(command, "SAVE") == 0)
			callsave(matrix, s, i, &flag);
		if (strcmp(command, "EXIT") == 0)
			exit(0);
		printf("\n");
	}

}