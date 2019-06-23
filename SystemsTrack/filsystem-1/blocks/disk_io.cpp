#include "diskio.h"

void write_block(int block, void* buffer)
{
	FILE* fp = fopen("harddisk.hdd", "rb+");
	fseek(fp, block * 16 * 1024, SEEK_SET);
	fwrite(buffer, 1, 16 * 1024, fp);
	fclose(fp);
}

void read_block(int block, void* buffer)
{
	FILE* fp = fopen("harddisk.hdd", "rb+");
	fseek(fp, block * 16 * 1024, SEEK_SET);
	fread(buffer, 1, 16 * 1024, fp);
	fclose(fp);
}