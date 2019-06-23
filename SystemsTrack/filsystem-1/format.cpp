#define _CRT_SECURE_NO_WARNINGS

#include "filesystem_level.h"

/*FILE* f_open(char *filename,char *mode)
{
	FILE *fp = fopen(filename, mode);
	if (fp == NULL)
	{
		
		exit(0);
	}
	return fp;
}*/

void format()
{
	FILE *fp = fopen(HARD_DISK, "w+b");
	fseek(fp, 4, SEEK_SET);
	int pos = 0;
	while (ftell(fp) < 1024)
	{
		char ch = 0;
		fwrite(&ch, 1, 1, fp);
		fseek(fp, 24, SEEK_CUR);
		pos = ftell(fp);
	}
	fclose(fp);
}