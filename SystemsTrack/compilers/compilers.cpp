#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
using namespace std;
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

struct symboltable
{
	char name[20];
	int address;
	int size;
};

struct labeltable
{
	char blockname[20];
	int address;
};
struct memorytable
{
	char name[20];
	int value;
};
struct opcode
{
	int inst_no;
	int op_code;
	int parameters[4];
};
struct registercodes
{
	char *register1;
	int val;
};
void push(int stack[], int *top, int *inst_no)
{
	*top = *top + 1;
	stack[*top] = *inst_no;
}
int pop(int stack[], int *top)
{
	int value = stack[*top];
	*top = *top - 1;
	return value;
}
void get_tokens(char string[], char token_collect[10][10])
{
	int i = 0;
	char * pch;
	pch = strtok(string, " ,.-[]=\n\t:");
	while (pch != NULL)
	{
		strcpy(token_collect[i], pch);
		pch = strtok(NULL, " ,.-[]=\n\t:");
		i++;
	}
	if (i == 1)
		token_collect[1][0] = '\0';
	if (i == 2)
		token_collect[2][0] = '1';
	if (i == 3)
		token_collect[3][0] = '\0';
}
void generate_opcode(struct opcode *op, char token_collect[10][10], int *inst_no, struct symboltable *st)
{
	char opcode_inst[15][20] = { "MOV", "MOVX", "ADD", "SUB", "MUL", "JMP", "IF", "EQ", "LT", "GT", "LTEQ", "GTEQ", "PRINT", "READ" };
	char registercodes[8][4] = { "AX", "BX", "CX", "DX", "EX", "FX", "GX", "HX" };
	int index = *inst_no;
	int flag = 0;
	if (strcmp(token_collect[0], "MOV") == 0){
		if (strcmp(token_collect[1], "AX") == 0 || strcmp(token_collect[1], "BX") == 0 || strcmp(token_collect[1], "CX") == 0 || strcmp(token_collect[1], "DX") == 0 || strcmp(token_collect[1], "EX") == 0 || strcmp(token_collect[1], "FX") == 0 || strcmp(token_collect[1], "GX") == 0 || strcmp(token_collect[1], "HX") == 0){
			flag = 1;
		}
	}
	op[index].inst_no = index;
	int i;
	for (i = 0; i < 15; i++)
	{
		if (flag != 1 && strcmp(token_collect[0], opcode_inst[i]) == 0){
			op[index].op_code = i + 1;
			break;
		}
	}
	if (flag == 1)
		op[index].op_code = 2;
	//printf("%d ", op[index].op_code);
	int k = 1, j = 0, indx = 0, f, c;

	for (int j = 0; j < 5; j++)
	{
		f = 0;
		for (int i = 0; i < 8; i++)
		{

			if (strcmp(registercodes[i], token_collect[k]) == 0){
				op[index].parameters[indx] = i;
				k++;
				f = 1;
				indx++;
				break;
			}
		}

		c = 0;
		for (int i = 0; i < 6; i++)
		{

			if (strcmp(st[i].name, token_collect[k]) == 0){

				op[index].parameters[indx] = st[i].address;
				indx++;
				k++;
				if (strcmp(token_collect[k], "0") == 0 || strcmp(token_collect[k], "1") == 0 || strcmp(token_collect[k], "2") == 0 || strcmp(token_collect[k], "3") == 0 || strcmp(token_collect[k], "4") == 0 || strcmp(token_collect[k], "5") == 0 || strcmp(token_collect[k], "6") == 0 || strcmp(token_collect[k], "7") == 0 || strcmp(token_collect[k], "8") == 0 || strcmp(token_collect[k], "9") == 0)
					k = k + 1;
				c = 1;
				break;
			}

		}
		if (strcmp(token_collect[0], "IF") == 0){
			for (int i = 0; i < 15; i++)
			{
				if (flag != 1 && strcmp(token_collect[k], opcode_inst[i]) == 0){
					op[index].parameters[2] = i + 1;
					//indx++;
					k++;
					break;
				}
			}

		}


	}

	//for (int k = 0; k <indx; k++)
	//printf("%d ", op[index].parameters[k]);
	if (strcmp(token_collect[0], "IF") == 0){

		//printf("%d ", op[index].parameters[indx]);
		indx = indx + 1;
	}
	for (int k = indx; k < 4; k++)
	{

		op[index].parameters[k] = -1;
		//printf("%d ", op[index].parameters[k]);// = -1;
	}
	//printf("\n");

	*inst_no = *inst_no + 1;
}
void labeltable_allocate(char *symbol_name, int *address, struct labeltable *lt, int *label_indx)
{
	strcpy(lt[*label_indx].blockname, symbol_name);
	lt[*label_indx].address = *address;
	*label_indx = *label_indx + 1;
}
void memorytable_allocate(char *symbol_name, int *address, int value, struct memorytable *mt)
{
	strcpy(mt[*address].name, symbol_name);
	mt[*address].value = value;
}

void symboltable_allocation(char *symbol_name, int *address, int size, struct symboltable *st, int index)
{

	strcpy(st[index].name, symbol_name);
	st[index].address = *address;
	st[index].size = size;
	*address = st[index].address + st[index].size;
}

int main()
{
	char filename[20], outputfile[20], string[100];
	printf("enter the filename:");
	scanf("%s", filename);
	printf("enter the output file:");
	scanf("%s", outputfile);
	char token_collect[10][10];
	struct symboltable *st = (symboltable *)malloc(100 * sizeof(symboltable));
	struct memorytable *mt = (memorytable *)malloc(100 * sizeof(memorytable));
	struct labeltable *lt = (labeltable *)malloc(100 * sizeof(labeltable));
	struct opcode *op = (opcode *)malloc(100 * sizeof(opcode));
	//struct registercodes *rc = (registercodes *)malloc(8 * sizeof(registercodes));
	op[0].inst_no = 0;
	op[0].op_code = 0;
	op[0].parameters[0] = 0;
	int stack[100], top = -1;
	int if_inst = 0, else_inst = 0;
	FILE *fp;
	fp = fopen(filename, "r");
	int index = 0, address = 0, inst_no = 0, label_indx = 0;
	while (!feof(fp))
	{
		fgets(string, 100, fp);
		//char **token_collect = (char*)calloc()
		get_tokens(string, token_collect);
		if (strcmp(token_collect[0], "DATA") == 0)
		{
			symboltable_allocation(token_collect[1], &address, token_collect[2][0] - '0', st, index);
			index++;
		}
		else if (strcmp(token_collect[0], "CONST") == 0)
		{
			symboltable_allocation(token_collect[1], &address, token_collect[2][0] - '0', st, index);
			memorytable_allocate(token_collect[1], &address, token_collect[2][0] - '0', mt);
			index++;
		}
		else if (strcmp(token_collect[0], "START") == 0)
		{
			inst_no = 1;
		}
		else if (strcmp(token_collect[0], "X") == 0)
		{
			labeltable_allocate(token_collect[0], &inst_no, lt, &label_indx);
		}
		else if (strcmp(token_collect[0], "IF") == 0)
		{

			push(stack, &top, &inst_no);
			op[inst_no].parameters[3] = -1;
			generate_opcode(op, token_collect, &inst_no, st);

		}
		else if (strcmp(token_collect[0], "ELSE") == 0)
		{

			labeltable_allocate(token_collect[0], &inst_no, lt, &label_indx);
			push(stack, &top, &inst_no);
			op[inst_no].parameters[0] = '-1';
			strcpy(token_collect[0], "JMP");
			generate_opcode(op, token_collect, &inst_no, st);

		}
		else if (strcmp(token_collect[0], "JUMP") == 0)
		{
			for (int i = 0; i < label_indx; i++)
			{
				if (strcmp(token_collect[1], lt[i].blockname) == 0)
					op[inst_no].parameters[0] = lt[i].address;
			}
			op[inst_no].inst_no = inst_no;
			op[inst_no].op_code = 6;
			for (int i = 1; i < 4; i++)
				op[inst_no].parameters[i] = -1;
		}
		else if (strcmp(token_collect[0], "END") == 0)
		{
			labeltable_allocate(token_collect[0], &inst_no, lt, &label_indx);
			else_inst = pop(stack, &top);
			if_inst = pop(stack, &top);
			for (int i = 0; i < 5; i++)
			{
				if (strcmp(lt[i].blockname, "ELSE") == 0)
					op[if_inst].parameters[3] = lt[i].address + 1;
				if (strcmp(lt[i].blockname, "END") == 0)
					op[else_inst].parameters[1] = lt[i].address;
			}

			break;
		}
		else
		{
			generate_opcode(op, token_collect, &inst_no, st);
		}
	}
	//FILE *fp1 = fopen("out.txt", "w");
	for (int i = 1; i <= inst_no; i++){
		printf("%d ", op[i].inst_no);
		printf("%d ", op[i].op_code);
		for (int j = 0; j < 4; j++){
			if (op[i].parameters[j] != -1)
				printf("%d ", op[i].parameters[j]);

		}
		printf("\n");
	}
	_getch();
}