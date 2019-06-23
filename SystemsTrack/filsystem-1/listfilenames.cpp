#include "filesystem_level.h"

int listallfilenames()
{
	int count = 0;
	FILE *fileptr;
	char flag;
	unsigned int a;
	char file_name[200] ;
	fileptr = fopen(HARD_DISK, "rb");
	if (fileptr == NULL)
		exit(0);
	if (fileptr != NULL){

		fread(&a, sizeof(a), 1, fileptr);
		while (ftell(fileptr) < size)
		{
			int x=fread(&flag, 1, 1, fileptr);
			if (flag == 0||x==0)
				fseek(fileptr, 24, SEEK_CUR);
			else
			{
				fread(&file_name, 16, 1, fileptr);
				printf("%s\n", file_name);
				fseek(fileptr, 8, SEEK_CUR);
				count++;
			}
		}
	}
	fclose(fileptr);
	if (count == 0)
		printf("no files");
	else
	return count;
	return 0;
}

