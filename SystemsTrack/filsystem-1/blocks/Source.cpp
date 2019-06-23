#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include "files.h"


int main()
{
	struct metadata *meta = (struct metadata*)calloc(1, sizeof(struct metadata));
	char buffer[16384];

	char command[10], source[20], destination[20];
	int i;
	while (true)
	{
		read_block(0, buffer);
		memcpy(meta, buffer, sizeof(struct metadata));
		printf(">");
		scanf("%s", &command);
		if (strcmp(command, "format")==0)
		{
			meta = (struct metadata*)calloc(1, sizeof(struct metadata));
			meta->magic_no = 0x444E524D;
			memcpy(buffer, meta, sizeof(struct metadata));
			write_block(0, buffer);
		}

		else if (strcmp(command, "copytodisk")==0)
		{
			scanf("%s", &source);
			scanf("%s", &destination);
			copytodisk(meta, source, buffer);
		}

		else if (strcmp(command, "copyfromdisk")==0)
		{
			scanf("%s", &source);
			scanf("%s", &destination);
			copyfromdisk(meta, source, destination, buffer);
		}

		else if (strcmp(command, "del")==0)
		{
			scanf("%s", &source);
			del(meta, source, buffer);
		}

		else if (strcmp(command, "exit")==0)
		{
			break;
		}

		else
		{
			printf("invalid command");
		}

	}
	return 0;
}