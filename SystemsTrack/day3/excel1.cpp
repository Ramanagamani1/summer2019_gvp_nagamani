///*version 1*/
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<conio.h>
//#include<stdlib.h>
//#include<string.h>
//void callimport(int **matrix, char *string, int index){
//	int val;
//	while (string[index] == ' ')
//		index++;
//	FILE *fp = fopen(string + index, "r");
//	if (fp == NULL)
//		printf("file does not exist");
//	else{
//		for (int i = 0; i < 10; i++){
//			for (int j = 0; j < 10; j++){
//				fscanf(fp, "%d, ", &val);
//				matrix[i][j] = val;
//			}
//			fscanf(fp, "\n");
//
//		}
//	}
//}
//
//void callexport(int **matrix, char *string, int index){
//	while (string[index] == ' ')
//		index++;
//	FILE *fp = fopen(string + index, "w");
//	for (int i = 0; i < 10; i++){
//		for (int j = 0; j < 10; j++){
//			fprintf(fp, "%d, ", matrix[i][j]);
//		}
//		fprintf(fp, "\n");
//	}
//	fclose(fp);
//}
//void callprint(int **matrix){
//	for (int i = 0; i < 10; i++){
//		for (int j = 0; j < 10; j++){
//			printf("%d ", matrix[i][j]);
//		}
//		printf("\n");
//	}
//}
//int callset(char *string, int index, int **matrix){
//	int row, col;
//	int val = 0;
//	for (int i = index; string[i] != '\0';){
//		if (string[i] == ' '){
//			i++;
//		}
//		if (string[i] >= 'A' && string[i] <= 'J'){
//			row = string[i] - 'A';
//			i++;
//		}
//		if (string[i] >= '0' && string[i] <= '9'){
//			col = string[i] - '0' - 1;
//			i++;
//		}
//		int j = 1;
//		if (string[i] == '='){
//			while (string[i + 1] != '\0' && string[i + 1] >= '0' && string[i + 1] <= '9'){
//				int num = string[i + 1] - '0';
//				val += num * j;
//				j = j * 10;
//				i++;
//			}
//		}
//		i = i + 1;
//	}
//	matrix[row][col] = val;
//	return matrix[row][col];
//}
//
//int callget(char *string, int index, int **matrix){
//	FILE *fp;
//	int val = 0;
//	int row, col;
//	fp = fopen("excel1.csv", "r");
//	for (int i = index; string[i] != '\0';){
//		if (string[i] == ' '){
//			i++;
//		}
//		if (string[i] >= 'A' && string[i] <= 'J'){
//			row = string[i] - 'A';
//			i++;
//		}
//		if (string[i] >= '0' && string[i] <= '9'){
//			col = string[i] - '0' - 1;
//			i++;
//		}
//	}
//
//	return matrix[row][col];
//}
//int main(){
//	int **matrix = (int **)calloc(10, sizeof(int*));
//	for (int i = 0; i < 10; i++){
//		matrix[i] = (int *)calloc(10, sizeof(int));
//	}
//	while (1){
//		char *string = (char *)malloc(100 * sizeof(char));
//		printf(">");
//		gets(string);
//		int i;
//		char *command = (char *)malloc(100 * sizeof(char));
//		for (i = 0; (string[i] != ' '&&string[i] != '\0'); i++){
//			command[i] = string[i];
//		}
//		command[i] = '\0';
//		if (strcmp(command, "GET") == 0){
//			int result = callget(string, i, matrix);
//			printf("%d", result);
//		}
//		if (strcmp(command, "SET") == 0){
//			int res1 = callset(string, i, matrix);
//		}
//		if (strcmp(command, "PRINT") == 0){
//			callprint(matrix);
//		}
//		if (strcmp(command, "EXPORT") == 0){
//			callexport(matrix, string, i);
//		}
//		if (strcmp(command, "IMPORT") == 0){
//			callimport(matrix, string, i);
//		}
//
//		printf("\n");
//	}
//
//}