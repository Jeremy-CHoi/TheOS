#include "disk_operation.h"

//This file is referring to CSDN blog.csdn.net/little_qi/article/details/73801336

char* system_start_addr;

void init_system(){
    system_start_addr = (char*)malloc(system_storage * sizeof (char));
    int i;

    for(i = 0; i < block_count; i++){
        system_start_addr[i] = '0';
    }

   int bit_map_size = block_count * sizeof (char) / block_size;

   for(i = 0; i < bit_map_size; i++){
       system_start_addr[i] = '1';
   }
}

int get_block(int size){
    int start = 0;
    int sum = 0;
    int i, j;

    for(i = 0; i < block_count; i++){
        if(system_start_addr[i] == '0'){
            if(sum == 0){
                start = i;
            }
            sum++;

            if(sum == size){
                for(j = start; j < start + size; j++){
                    system_start_addr[j] = '1';
                }
                return start;
            }
        }else{
            sum = 0;
        }
    }
    std::cout<<"Cannot get series of memory or the memory is already full!"<<std::endl;
    return -1;
}

char* get_block_addr(int block_number){
    return system_start_addr + block_number * block_size;
}

int get_addr_block(char* addr){
    return (addr - system_start_addr) / block_size;
}

int release_block(int block_number, int size){
    int end_block = block_number + size;

    for(int i = 0; i < end_block; i++){
        system_start_addr[i] = '0';
    }
    return 0;
}


void exit_system(){
    free(system_start_addr);
}






