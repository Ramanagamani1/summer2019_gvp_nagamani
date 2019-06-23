#include"header.h"
#include "diskio.h"

unsigned int get_file_size(char* file_name)
{
	FILE* fp = fopen(file_name, "r");
	fseek(fp, 0, SEEK_END);
	unsigned int size = ftell(fp);
	fclose(fp);
	return size;
}

void copytodisk(metadata_details* meta, char* filename, char*buff)
{
	int i, size = get_file_size(filename), j, blocks, offset;
	blocks = size / (16 * 1024);
	if (size % (16 * 1024))
		blocks++;
	//printf("%d\n", size);
	for (i = 1; i < 6400 - blocks; i++)
	{
		if (!meta->freeblockavailable[i])
		{
			j = i;
			while (!meta->freeblockavailable[j] && j - i + 1 < blocks) j++;
			if (j - i + 1 == blocks)
			{
				FILE* fp = fopen(filename, "r");
				for (int k = i; k < j; k++)
				{
					meta->freeblockavailable[k] = 1;
					fread(buff, 1, 16 * 1024, fp);
					write_block(k, buff);
				}
				if (blocks == size / (16 * 1024))
					offset = 16 * 1024;
				else
					offset = size % (16 * 1024);
				fread(buff, 1, offset, fp);
				write_block(j, buff);
				meta->freeblockavailable[j] = 1;
				strcpy(meta->filerecords[meta->no_of_files].file_name, filename);
				meta->filerecords[meta->no_of_files].no_of_blocks = blocks;
				meta->filerecords[meta->no_of_files].starting_block = i;
				meta->no_of_files++;
				memcpy(buff, meta, sizeof(metadata_details));
				write_block(0, buff);
				fclose(fp);
				return;
			}
			else i = j;
		}
	}
	printf("the file could not be stored\n");
	
}