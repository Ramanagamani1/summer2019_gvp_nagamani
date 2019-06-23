#include "diskio.h"
#include "header.h"

int main()
{
	char string[300];
	char command[200];
	char source[300];
	char destination[300];
	struct metadata_details *meta = (struct metadata_details *)calloc(1, sizeof(metadata_details));
	char buffer[16384];
	while (1)
	{
		read_block(0,buffer);
		memcpy(meta, buffer, sizeof(metadata_details));
		int cindx = 0, source_indx = 0, dest_indx = 0, i = 0;
		printf(">");
		gets(string);
		while (string[i] != '\0'&&string[i] != '\n')
		{
			while (string[i] != ' ')
			{
				command[cindx++] = string[i++];

			}
			command[cindx++] = '\0';
			if (string[i] != '\0'&&string[i] != '\n')
			{
				i++;
				while (string[i] != ' ')
				{
					source[source_indx++] = string[i++];
				}
				source[source_indx] = '\0';
				i++;
				while (string[i] != '\0'&&string[i] != '\n')
				{
					destination[dest_indx++] = string[i++];
				}
				destination[dest_indx] = '\0';
			}
		}
		if (strcmp(command, "MOUNT") == 0)
		{
			int i = 0,j=1;
			unsigned int block=0;
			while (destination[i] != '\0')
			{
				block = block + destination[i] - '0'*j;
				j = j * 10;
			}
			//mount(source, block);
		}
		else if (strcmp(command, "COPYTOFS")==0)
		{
			copytodisk(meta, source, buffer);
		}
	}
	return 0;
}
