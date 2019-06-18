#include "files.h"

unsigned int get_file_size(char* file_name)
{
	FILE* fp = fopen(file_name, "rb");
	fseek(fp, 0, SEEK_END);
	unsigned int size = ftell(fp);
	fclose(fp);
	return size;
}

void copytodisk(struct metadata* meta, char* filename, char*buffer)
{
	int i, size = get_file_size(filename);
	int  j, blocks, offset;
	blocks = size / (16384);
	if (size % (16384))
		blocks++;
	for (i = 1; i < 6400 - blocks; i++)
	{
		if (!meta->freeblock_available[i])
		{
			j = i;
			while (!meta->freeblock_available[j] && j - i + 1 < blocks) j++;
			if (j - i + 1 == blocks)
			{
				FILE* fp = fopen(filename, "r");
				for (int k = i; k < j; k++)
				{
					meta->freeblock_available[k] = 1;
					fread(buffer, 1, 16384, fp);
					write_block(k, buffer);
				}
				if (blocks == size / (16384))
					offset = 16 * 1024;
				else
					offset = size % (16384);


				fread(buffer, 1, offset, fp);
				write_block(j, buffer);
				meta->freeblock_available[j] = 1;
				meta->files[meta->no_of_files].file_length = size;
				strcpy(meta->files[meta->no_of_files].file_name, filename);
				meta->files[meta->no_of_files].no_of_blocks = blocks;
				meta->files[meta->no_of_files].starting_block = i;
				meta->no_of_files++;
				memcpy(buffer, meta, sizeof(struct metadata));
				write_block(0, buffer);
				fclose(fp);
				return;

			}
			else 
				i = j;
		}
	}

}

void copyfromdisk(struct metadata* meta, char* filename,char *destination, char*buffer)
{
	int i, size, blocks, start;
	for (i = 0; i < meta->no_of_files; i++)
	{
		
		if (!strcmp(filename, meta->files[i].file_name))
			break;
	}
	if (i >= meta->no_of_files)
	{
		printf("the file cannot be copied\n");
		return;
	}
	size = meta->files[i].file_length;
	start = meta->files[i].starting_block;
	blocks = meta->files[i].no_of_blocks;

	FILE* fp = fopen(destination, "w+");
	for (i = 0; i < blocks - 1; i++)
	{
		read_block(i + start, buffer);
		fwrite(buffer, 1, 16384, fp);
	}
	if (size % (16384))
	{
		read_block(i + start, buffer);
		fwrite(buffer, 1, size % (16384), fp);
	}
	else
	{
		read_block(i + start, buffer);
		fwrite(buffer, 1, 16384, fp);
	}
	fclose(fp);
}

void del(struct metadata* meta, char* filename, char*buffer)
{
	int i, size, j, blocks, start;
	for (i = 0; i < meta->no_of_files; i++)
	{
		if (!strcmp(filename, meta->files[i].file_name))
			break;
	}
	if (i >= meta->no_of_files)
	{
		printf("the file cannot not be deleted\n");
		return;
	}
	start = meta->files[i].starting_block;
	blocks = meta->files[i].no_of_blocks;
	meta->files[i] = meta->files[meta->no_of_files];
	meta->no_of_files--;
	for (i = start; i < blocks - 1; i++)
	{
		meta->freeblock_available[i] = 0;
	}
	memcpy(buffer, meta, sizeof(struct metadata));
	write_block(0, buffer);
}