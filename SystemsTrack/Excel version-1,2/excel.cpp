///*version1 of excel sheet*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
void callprint(struct node **matrix);
int toNum(char *n);
int evaluate(char *op1, char *op2, char op, struct node **matrix);
int parse(char *string, int index, struct node **matrix);
void callset(char *string, int index, struct node **matrix);

int callget(char *string, int index, struct node **matrix);
struct node{
	int val;
	char *formula;
};
void callimport(struct node **matrix, char *string, int index){
	char *val=(char *)malloc(10*sizeof(char));
	while (string[index] == ' ')
		index++;
	FILE *fp = fopen(string + index, "r");
	if (fp == NULL)
		printf("file does not exist");
	else{
		for (int i = 0; i < 10; i++){
			for (int j = 0; j < 10; j++){
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
void callsave(struct node **matrix, char *string, int index,int *flag){
	if (*flag == 0)
		printf("file not exported");
	else{
		FILE *fp = fopen(string + index, "w");
		for (int i = 0; i < 10; i++){
			for (int j = 0; j < 10; j++){
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
char *callexport(struct node **matrix, char *string, int index,int *flag){
	int indice = index+1,k=0;
	char *path = (char *)malloc(10 * sizeof(char));
	while (string[indice] != '\0')
		path[k++] = string[indice++];
	path[k] = '\0';
	while (string[index] == ' ')
		index++;
	FILE *fp = fopen(string+index, "w");
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			if (matrix[i][j].formula!=NULL)
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
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			if (matrix[i][j].formula==NULL)
			printf("%d ", matrix[i][j].val);
			else{
				printf("%s ", matrix[i][j].formula);
				
			}
		}
		printf("\n");
	}
}
int toNum(char *n){
	int i = 0, j = 1;
	int val = 0;
	while (n[i] != '\0'){
		int num = n[i] - '0';
		val += num * j;
		j = j * 10;
		i++;
	}
	return val;
}
int evaluate(char *op1, char *op2, char op, struct node **matrix){
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

int parse(char *string, int index, struct node **matrix){
	int row, col, i;
	int k = 0,z=index;
	char op = ' ';
	char *op1 = (char *)malloc(10 * sizeof(char));
	char *op2 = (char *)malloc(10 * sizeof(char));
	for (i = index; string[i] != '='&&string[i] != '\0'&&string[i] != '+'&&string[i] != '*'&&string[i] != '/'&&string[i] != '%'&&string[i] != '-';){
		if (string[i] == ' '){
			i++;
			z = i;
		}
		
		if (string[i] >= 'A' && string[i] <= 'J'){
			col = string[i] - 'A';
			op1[k] = string[i];
			i++,k++;
		}
		if (string[i] >= '0' && string[i] <= '9'){
			row = string[i] - '0' - 1;
			op1[k] = string[i];
			i++,k++;
		}
	}
	if (string[i] == '\0'){
		op1[k] = '\0';
		int res = callget(op1, 0, matrix);
		matrix[row][col].val = res;
	}
	else{
		int f= 0,m=0;
		int index = i+1;
		if (string[i] == '+' || string[i] == '*' || string[i] == '/' || string[i] == '*' || string[i] == '-'||string[i]=='\0'){
			f = 1;
		}
		if ((string[i] != '+' || string[i] != '*' || string[i] != '/' || string[i] != '*' || string[i] != '-')){
			int l = 0;
	     while (f!=1&&string[i + 1] != '\0'&&string[i + 1] != '+'&&string[i + 1] != '*'&&string[i + 1] != '-'&&string[i + 1] != '/'&&string[i + 1] != '%'){
					op1[l] = string[i + 1];
					l++, i++;
				}
		 if (f == 1){
			 op1[k] = '\0';
			 matrix[row][col].formula = string + z;
		 }
		 else
				op1[l] = '\0';
			
			if (string[i + 1] == '\0'){
				if (op1[0] >= '0'&&op1[0] <= '9'){
					matrix[row][col].val = toNum(op1);
					matrix[row][col].formula = NULL;
				}
				else{
					matrix[row][col].val = callget(op1, 0, matrix);
					if (f!=1)
					matrix[row][col].formula = string + index;
				}
			}
			else{
				if (f == 1)
					op = string[i];
				 else if(string[i + 1] != '\0'){
					op = string[i + 1];
					i++;
				}
				while (string[i + 1] != '\0'){
					op2[m] = string[i + 1];
					i++, m++;
				}
				op2[m] = '\0';
	
				if (string[index] >= 'A'&&string[index] <= 'J'&&f!=1)
				matrix[row][col].formula = string + index;
				matrix[row][col].val = evaluate(op1, op2, op, matrix);
					
			
			}
		}
	}
	return matrix[row][col].val;
}
void callset(char *string, int index, struct node **matrix){
	int res = parse(string, index, matrix);
}

int callget(char *string, int index, struct node **matrix){
	int val = 0;
	int row, col;
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
	if (matrix[row][col].formula==NULL)
	   return matrix[row][col].val;
	else{
		int res= parse(matrix[row][col].formula, 0, matrix);
		return res;
	}
}



int main(){
	int flag=0;
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
		for (i = 0; (string[i] != ' '&&string[i]!='\0'); i++){
			command[i] = string[i];
		}
		command[i] = '\0';
		if (strcmp(command, "GET") == 0){
			int result = callget(string, i,matrix);
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
			callimport(matrix, string, i);
		}
		if (strcmp(command, "SAVE") == 0)
			callsave(matrix,s,i,&flag);
		if (strcmp(command, "EXIT") == 0)
			exit(0);
		printf("\n");
	}

}
