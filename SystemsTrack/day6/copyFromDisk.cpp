#define _CRT_SECURE_NO_WARNINGS

#include "filesystem_level.h"

void reading_metadata(char *filename,unsigned int *offset,unsigned int *length)
{
	FILE *fptr = fopen(HARD_DISK, "r");
	if (fptr == NULL)
		exit(0);
	int flag;
	char *temp_filename = (char*)malloc(sizeof(char) * 16);
	int temp_offset;
	int temp_length;
	int check_e = 0;
	fseek(fptr, 4, SEEK_SET);
	while (ftell(fptr) < 1024)
	{
		fread(&flag, 1, 1, fptr);
		fread(temp_filename, 16, 1, fptr);
		fread(&temp_offset, 4, 1, fptr);
		fread(&temp_length, 4, 1, fptr);

		if (strcmp(temp_filename, filename) == 0)
		{
			if (flag == 1)
			{
				check_e = 1;
				*offset = temp_offset;
				*length = temp_length;
				return;
			}
		}

	}
	if (check_e == 0)
	{
		*offset = -1;
		*length = -1;
		return;
	}
}

void write_to_file(char *destination_file, unsigned int offset, unsigned int length){
	FILE *dest_file_ptr = fopen(destination_file, "w");
	FILE *hard_disk_ptr = fopen(HARD_DISK, "r");
	if (dest_file_ptr == NULL || hard_disk_ptr == NULL)
		exit(0);
	fseek(hard_disk_ptr, offset, 0);
	char temp_char;
	for (unsigned int count = 0; count < length; count++){
		temp_char = fgetc(hard_disk_ptr);
		fputc(temp_char, dest_file_ptr);
	}

	fclose(dest_file_ptr);
	fclose(hard_disk_ptr);
}

void copy_from_disk(char *source_file, char *destination_file){
	unsigned int offset, length;
	reading_metadata(source_file, &offset, &length);
	write_to_file(destination_file,offset, length);
}

