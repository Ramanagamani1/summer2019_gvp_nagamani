#define no_file_records 32

struct file_details
{
	char file_name[20];
	unsigned int size;
	unsigned int no_of_blocks;
	unsigned int starting_block;
};

struct metadata_details
{
    unsigned int magic_number;
	unsigned int block_size;
	unsigned int total_no_of_blocks;
	//unsigned int free_available_blocks;
	char freeblockavailable[6400];
	char bytevector[1];
	file_details filerecords[no_file_records];
	int no_of_files;
};

unsigned int get_file_size(char* file_name);

void copytodisk(metadata_details* meta, char* filename, char*buff);