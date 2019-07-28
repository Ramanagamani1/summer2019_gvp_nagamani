#include "header.h"

char *converttostr(int filenum)
{

	char *num = (char *)malloc(1000000 * sizeof(char));
	if (filenum == 0){
		num[0] = '0';
		num[1] = '\0';
		return num;
	}
	int len = 0;
	int n = filenum;
	while (n != 0){
		len++;
		n /= 10;
	}
	num[len] = '\0';
	while (filenum != 0){
		num[len - 1] = filenum % 10 + '0';
		filenum /= 10;
		len--;
	}
	return num;
}
void merge(file *sorted1, file *sorted2, file *output)
{
	
	/*int val1, val2;
	if (fp1 != null&&fp2 != null)
	{
		while ( !feof(fp1) && !feof(fp2))
		{
			fscanf(fp1, "%d", &val1);
			fscanf(fp2, "%d", &val2);
			if (val1 < val2)
				fprintf(f3, "%d\n", val1);
			else
				fprintf(f3, "%d\n", val2);
		}
		if (feof(fp1)){
			while (!feof(fp2)){
				fscanf(fp2, "%d", &val1);
				fprintf(f3, "%d\n", val1);
			}
		}
		if(feof(fp2)){
			while (!feof(fp1))
			{
				fscanf(fp1, "%d", &val1);
				fprintf(f3, "%d\n", val1);
			}
		}
		fclose(fp1);
		fclose(fp2);
        fclose(f3);
	}*/
	int val = -1, val1 = -1;
	int flag = 0;
	if (fscanf(sorted1, "%d", &val) != eof && fscanf(sorted2, "%d", &val1) != eof)
	{
		while (1)
		{
			if (val1 != -1 && val < val1)
			{
				fprintf(output, "%d\n", val);
				if (fscanf(sorted1, "%d", &val) == eof)
				{
					flag = 1;
					break;
				}
			}
			else if (val != -1 && val >= val1)
			{
				fprintf(output, "%d\n", val1);
				if (fscanf(sorted2, "%d", &val1) == eof)
				{
					flag = 2;
					break;
				}
			}
		}
	}
	if (flag == 1)
		fprintf(output, "%d\n", val1);
	else
		fprintf(output, "%d\n", val1);
	while (fscanf(sorted1, "%d", &val) != eof)
	{
		fprintf(output, "%d\n", val1);
	}
	while (fscanf(sorted2, "%d", &val1) != eof)
	{
		fprintf(output, "%d\n", val1);
	}
	fclose(sorted1);
	fclose(sorted2);
	fclose(output);

}
int comparator(const void *num1, const void *num2){
	return *(int*)num1 - *(int *)num2;
}
void mergesort(int start,int end)
{
	file *f1, *f2,*f3;
	int i = start,j=end;
	char file1[1000], file2[1000], output[100];
	char *num;
	while(i <= end)
	{
		num = converttostr(i++);
		strcpy(file1, "file");
		strcat(file1, num);
		strcat(file1, ".txt");
		f1 = fopen(file1, "r");

		num = converttostr(i++);
		strcpy(file2, "file");
		strcat(file2, num);
		strcat(file2, ".txt");
		f2 = fopen(file2, "r");

		num = converttostr(j++);
		strcpy(output, "file");
		strcat(output, num);
		strcat(output, ".txt");
		f3 = fopen(output, "w");
		merge(f1, f2, f3);
	}
	if (end + 1 <= j)
		mergesort(start, end);
}

void sortfile(char *filename,int filenum,file *fp)
{
	
	int i;
	int *data = (int *)malloc(20 * sizeof(int));
	for ( i = 0; i < 5; i++)
	{
		fscanf(fp, "%d\n", &data[i]);
     }
	i = 0;
	qsort(data, 5, sizeof(int), comparator);
	file *fp1;
	char *output =(char *)malloc(100*sizeof(char));
	char *num = converttostr(filenum);
	strcpy(output, "file");
	strcat(output, num);
	strcat(output, ".txt");
	fp1 = fopen(output, "w");
	for (int i = 0; i < 5; i++){
		fprintf(fp1, "%d\n", data[i]);
	}
	fclose(fp1);
}
int main()
{
	char *file=(char *)malloc(20*sizeof(char));
	printf("enter the file name:");
	scanf("%s", file);
	int filenum = 0;
	file *fp;
	fp = fopen(file, "r");
	for (int i = 0; i < 4;i++)
	{
		sortfile(file, filenum,fp);
		filenum += 1;
	}
	mergesort(0, filenum);
	
}
