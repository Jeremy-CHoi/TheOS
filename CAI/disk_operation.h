#ifndef DISK_OPERATION_H
#define DISK_OPERATION_H

#include <stdio.h>
#include <stdlib.h>

#define system_storage 100*1024*1024
#define block_size 1024
#define block_count system_storage/block_size

void init_system();

int get_block(int size);

char* get_block_addr(int block_number);

int get_addr_block(char* addr);

int release_block(int block_numebr, int size);

void exit_system();

#endif // DISK_OPERATION_H
