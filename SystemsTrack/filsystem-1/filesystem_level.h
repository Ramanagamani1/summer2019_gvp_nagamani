#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define size 1024
#define HARD_DISK "hardDisk.hdd"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int findSize(char*);

int canFit(char*, char*);

void copyToDisk(char*, char*);

void format();

int listallfilenames();

void reading_metadata(char *filename, int *offset, int *length);

FILE* f_open(char *filename, char *mode);

void write_to_file(char *destination_file, unsigned int offset, unsigned int length);

void copy_from_disk(char *source_file, char *destination_file);