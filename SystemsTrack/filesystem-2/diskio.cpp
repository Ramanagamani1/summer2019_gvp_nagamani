#include "header.h"
#include "diskio.h"

static char harddisk_file[50];
static int blocksize;

int findSize(char* sourcefile) 
{
	FILE* source = fopen(sourcefile, "rb+");
	if (source == NULL)
		exit(0);
	rewind(source);
	char ch;
	int count = 0;
	while (fread(&ch, 1, 1, source) != 0){
		count++;
	}
	int ssize = count;
	fclose(source);
	return ssize;
}


/*void init(char *filename,int block_size)
{
	strcpy(harddisk_file, filename);
	blocksize = block_size;
	char buffer[16 * 1024];
	int number;
	read_block(0, buffer);
	
}*/

void write_block(int block, void* buffer)
{
	FILE* fp = fopen("harddisk.hdd", "rb+");
	if (fp == NULL)
		exit(0);
	fseek(fp, block * 16 * 1024, SEEK_SET);
	fwrite(buffer, 1, 16 * 1024, fp);
	fclose(fp);
}

void read_block(int block, void* buffer)
{
	FILE* fp = fopen("harddisk.hdd", "rb+");
	if (fp == NULL)
		exit(0);
	fseek(fp, block * 16 * 1024, SEEK_SET);
	fread(buffer, 1, 16 * 1024, fp);
	fclose(fp);
}