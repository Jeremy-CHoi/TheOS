#ifndef FILE_SYSTEM_H
#define FILE_SYSTEM_H

#include "map.h"
#include "error.h"
#include "console.h"
#include "file_operation.h"
#include "disk_operation.h"
#include <string.h>
#include <stdio.h>
#include <set>


using namespace std;

char path[500];
dir_table* root_dir_table;
dir_table* current_dir_table;


void init_root_dir();

char* get_path();
void show_dir(char dir_name[]);
int create_dir(char dir_name[]);
int change_dir(char dir_name[]);
int delete_dir(char file_name[]);
int change_name(char pre_name[], char new_name[]);

int creat_fcb(int fcb_block_number, int file_block_number, int file_size);
int add_dir_unit(dir_table* system_dir_table, char file_name[], int type, int fcb_block_number);

int find_unit(dir_table* system_dir_table, char unit_name[]);

int delete_file(char file_name[]);
int release_file(int fcb_block);
int delete_file_in_table(dir_table* system_dir_table, int unit_index);
int delete_dir_unit(dir_table* current_dir_tabe, int unit_index);

int find_unit_in_table(dir_table* current_dir_table, int unit_index);

int change_dir(char dir_name[]);

int read(char file_name[], int length);
int reread(char file_name[], int length);
int read_exec(fcb* system_fcb, int length);

int write(char file_name[], char content[]);
int rewrite(char file_name[], int length);
int write_exec(fcb* system_fcb, char content[]);

void show_dir();

#endif // FILE_SYSTEM_H
