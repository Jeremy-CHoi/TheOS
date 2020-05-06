#ifndef FILE_OPERATION_H
#define FILE_OPERATION_H

#define dir_table_max_size 100
struct dir_unit{
    char file_name[100];
    char type; //0 for dic, 1 for file
    int start_block;
};

struct dir_table{
    int unit_amount;
    dir_unit  dirs[dir_table_max_size];
};

struct fcb{
    int block_number;
    int file_size;
    int data_size;
    int read_ptr;
    int link;
};

#endif // FILE_OPERATION_H
