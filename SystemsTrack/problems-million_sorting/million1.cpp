#include "header.h"
#define arraylimit 16000;

void filecopy()
{
	FILE *output = fopen("out.txt", "r+");
	FILE *sorted = fopen("sorted.txt", "w+");
	char *str = (char*)malloc(100 * sizeof(char));
	printf("filecopy");
	while (fgets(str, 10, output))
	{
		printf("%s\n", str);
		fprintf(sorted, "%s", str);
	}
	printf("filecopy");
	fclose(output);
	fclose(sorted);
}
void merge(int a[], int low, int high, int mid)
{
	int k[16000];
	int i = low, j = mid + 1, h = low;
	while (i <= mid && j <= high)
	{
		if (a[i] < a[j])
		{
			k[h] = a[i];
			i++;
		}
		else
		{
			k[h] = a[j];
			j++;
		}
		h++;
	}
	while (i <= mid)
	{
		k[h] = a[i];
		h++;
		i++;
	}
	while (j <= high)
	{
		k[h] = a[j];
		h++;
		j++;
	}
	for (int i = low; i <= high; i++)
		a[i] = k[i];
}
void mergesort(int a[], int low, int high)
{
	if (low == high)
		return;
	int mid = (low + high) / 2;
	mergesort(a, low, mid);
	mergesort(a, mid + 1, high);
	merge(a, low, high, mid);
}
void mergetwofiles()
{
	FILE *sorted1 = fopen("temp.txt", "r+");
	FILE *sorted2 = fopen("sorted.txt", "r+");
	FILE *output = fopen("out.txt", "w+");
	int val = -1, val1 = -1;
	int flag = 0;
	if (fscanf(sorted1, "%d", &val) != EOF && fscanf(sorted2, "%d", &val1) != EOF)
	{
		while (1)
		{
			if (val1 != -1 && val < val1)
			{
				fprintf(output, "%d\n", val);
				if (fscanf(sorted1, "%d", &val) == EOF)
				{
					flag = 1;
					break;
				}
			}
			else if (val != -1 && val >= val1)
			{
				fprintf(output, "%d\n", val1);
				if (fscanf(sorted2, "%d", &val1) == EOF)
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
	while (fscanf(sorted1, "%d", &val) != EOF)
	{
		fprintf(output, "%d\n", val1);
	}
	while (fscanf(sorted2, "%d", &val1) != EOF)
	{
		fprintf(output, "%d\n", val1);
	}
	fclose(sorted1);
	fclose(sorted2);
	fclose(output);
}
int main()
{
	FILE *fp, *temp, *fp1;
	int a[16000];
	int val, i, j;
	fp = fopen("sample.txt", "r+");
	fp1 = fopen("sorted.txt", "w+");
	for (i = 0; i < 16000; i++)
	{
		if (fscanf(fp, "%d", &val) == EOF)
			break;
		a[i] = val;
	}
	mergesort(a, 0, i - 1);
	for (int j = 0; j < 16000; j++)
		fprintf(fp1, "%d\n", a[j]);
	while (1)
	{
		temp = fopen("temp.txt", "w+");
		for (i = 0; i < 16000; i++)
		{
			if (fscanf(fp, "%d", &val) == EOF)
				break;
			a[i] = val;
		}
		if (i == 0)
			break;
		mergesort(a, 0, i - 1);
		for (int j = 0; j < 16000; j++)
			fprintf(temp, "%d\n", a[j]);
		fclose(temp);
		fclose(fp1);
		mergetwofiles();
		filecopy();
		if (i < 16000)
			break;
	}
	fclose(fp);
	system("pause");
}