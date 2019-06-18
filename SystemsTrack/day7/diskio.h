#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


void write_block(int block, void* buffer);

void read_block(int block, void* buffer);

void mount(char *filename, int block_size);