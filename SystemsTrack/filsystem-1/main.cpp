#include "filesystem_level.h"

int main()
{
	char string[300];
	char command[200];
	char source[300];
	char destination[300];
	while (1)
	{
		int cindx = 0, source_indx = 0, dest_indx = 0, i = 0;
		printf(">");
		gets(string);
		while (string[i] != '\0'&&string[i]!='\n')
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
		if (strcmp(command, "format") == 0)
		{
			format();
		}
		else if (strcmp(command, "ls") == 0)
		{
			int x=listallfilenames();
		}
		else if (strcmp(command, "copytodisk") == 0)
		{
			copyToDisk(source, destination);
		}
		else if (strcmp(command, "copyfromdisk") == 0)
		{
			copy_from_disk(source, destination);
		}
		else if (strcmp(command, "exit") == 0)
			exit(0);
		else
			printf("invalid command\n");
	}
}