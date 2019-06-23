
#include"filesystem_level.h"

// returns the size of the file in bytes
int findSize(char* sourcefile) {
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

// function to check whether we can fit the file in the harddisk
int canFit(char* diskfile, char* sourcefile) {
	unsigned int start; 
	int ssize = findSize(sourcefile); 
	FILE* disk = fopen(diskfile, "wb+"); 
	if (disk == NULL)
		exit(0);
	fread(&start, sizeof(start), 1, disk);
	fclose(disk);
	if ((start + ssize) < 104857600)
		return 0;
	else
		return 1;
}

void copyToDisk(char* source, char* destination) {
	if (canFit(destination, source) == 0) {
		printf("No available space\n");
	}

	unsigned int write_pos; //offset
	unsigned int len_of_source_file = findSize(source); //length
	FILE* disk = fopen(HARD_DISK, "rb+"); 
	FILE* sourceptr = fopen(source, "rb"); 
	if (disk == NULL || sourceptr == NULL)
		exit(0);

	// position of file pointer to start writing
	
	if (fread(&write_pos, sizeof(write_pos), 1, disk)==0){
		
		write_pos = 1024;
	}
	
	// find the position to write in the metadata
	char flag=0; 
	fread(&flag , 1, 1, disk);
	while (flag != 0) {
		fseek(disk, 24, SEEK_CUR); 
		fread(&flag, 1, 1, disk); 
	}

	// write metadata for the file
	flag = 1;
	fwrite(&flag, 1, 1, disk);
	char name[16]; 
	strcpy(name, destination); 
	fwrite(name, 1, 16, disk); 
	fwrite(&write_pos, sizeof(write_pos), 1, disk); 
	fwrite(&len_of_source_file, sizeof(len_of_source_file), 1, disk); 
	fseek(disk, write_pos, SEEK_SET); 

	// read a character from the source and write it to the disk
	char character;
	while (fread(&character, 1, 1, sourceptr) != 0) {
		fwrite(&character, 1, 1, disk); 
	}
	fclose(sourceptr); 
	write_pos = ftell(disk); 
	rewind(disk); 
	fwrite(&write_pos, sizeof(write_pos), 1, disk); 
	fclose(disk); 
}