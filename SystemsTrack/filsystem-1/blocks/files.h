#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include"files.h"
#include"diskio.h"
#include<string.h>

struct filedetails{
	char file_name[20];
	unsigned int starting_block;
	unsigned int no_of_blocks;
	unsigned int file_length;
};


struct metadata{
	int magic_no;
	filedetails files[32];
	int no_of_files;
	bool freeblock_available[6400];
};


unsigned int get_file_size(char* file_name);

void copytodisk(struct metadata* meta, char* filename, char*buffer);

void copyfromdisk(struct metadata* meta, char* filename, char *destination,char*buffer);

void del(struct metadata* meta, char* filename, char*buffer);