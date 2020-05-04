#include "file_system.h"

using namespace std;

void init_root_dir(){
    int start = get_block(1);

    if(start == -1){
        return;
    }else{
        root_dir_table = (dir_table*)get_block_addr(start);
        root_dir_table->unit_amount = 0;

        add_dir_unit(root_dir_table, "..", 0, start);
        current_dir_table = root_dir_table;
        path[0] = '\\';
        path[1] = '\0';
    }
}

char* get_path(){
    return path;
}

void show_dir(){
    int unit_amount = current_dir_table->unit_amount;

    printf("Total: %d\n", unit_amount);
    printf("Name(Dir/File)\tType\tSize\tFCB\tStart Block\n");

    for(int i = 0; i < unit_amount; i++){
        dir_unit tmp = current_dir_table->dirs[i];
        printf("%s\t%d\t", tmp.file_name, tmp.type);

        if(tmp.type == 1){
            int fcb_block = tmp.start_block;
            fcb* file_fcb = (fcb*)get_block_addr(fcb_block);
            printf("%d\t%d\t%d\n", file_fcb->file_size, fcb_block, file_fcb->block_number);
        }else{
            int dir_block = tmp.start_block;
            dir_table* current_table = (dir_table*)get_block_addr(dir_block);
            printf("%d\t%d\n", current_table->unit_amount, tmp.start_block);
        }
    }
}

int find_unit_in_table(dir_table* system_dir_table, char unit_name[]){
    int dir_unit_amount = system_dir_table->unit_amount;
    int unit_index = -1;

    for(int i = 0; i < dir_unit_amount; i++){
        if(strcmp(unit_name, system_dir_table->dirs[i].file_name) == 0){
            unit_index = i;
        }
    }
    return unit_index;

}
int change_dir(char dir_name[]){
    int unit_index = find_unit_in_table(current_dir_table, dir_name);
    if(unit_index == -1){
        printf("File cannot be found! Please check again.");
    }
    if(current_dir_table->dirs[unit_index].type == 1){
        printf("Not a Dir, please check again");
    }

    int dir_block = current_dir_table->dirs[unit_index].start_block;
    current_dir_table = (dir_table*)get_block_addr(dir_block);

    if(strcmp(dir_name, "..") == 0){
        int len = strlen(path);
        for(int i = len -2; i >= 0; i--){
            if(path[i] =='\\'){
                path[i + 1] = '0';
                break;
            }
        }
    }else{
        strcat(path, dir_name);
        strcat(path, "\\");
    }
    return 0;
}

int change_name(char pre_name[], char new_name[]){
    int unit_index = find_unit_in_table(current_dir_table, pre_name);
    if(unit_index == -1){
        printf("File cannot be found! Please check again.");
        return -1;
    }
    strcpy(current_dir_table->dirs[unit_index].file_name, new_name);
    return 0;
}

int add_dir_unit(dir_table* system_dir_table, char file_name[], int type, int fcb_block_number){
    int dir_unit_amount = system_dir_table->unit_amount;

    if(dir_unit_amount == dir_table_max_size){
        printf("Directory Table Has Already Full, "
               "Please Try to Delete Some of the Directory Table!\n");
        return -1;
    }

    if(find_unit_in_table(system_dir_table, file_name)){
        printf("There Is A File Already Stored in The System,"
               "Please Try To Rename the Original File or Change"
               "the Current File Name! \n");
        return -1;
    }

    dir_unit* new_dir_unit = &system_dir_table->dirs[dir_unit_amount];
    system_dir_table->unit_amount++;

    strcpy(new_dir_unit->file_name, file_name);
    new_dir_unit->type = type;
    new_dir_unit->start_block = fcb_block_number;

    return 0;
}

int creat_fcb(int fcb_block_num, int file_block_number, int file_size){
    fcb* current_fcb = (fcb*) get_block_addr(fcb_block_num);

    current_fcb->block_number = file_block_number;
    current_fcb->file_size = file_size;
    current_fcb->link = 1;
    current_fcb->data_size = 0;
    current_fcb->read_ptr = 0;
    return 0;
}

int create_file(char file_name[], int file_size){
    if(strlen(file_name) >= 99){
        printf("File Name TOO LONG, Please Try Again");
        return -1;
    }

    int fcb_block = get_block(1);
    if(fcb_block == -1){
        return -1;
    }
    int file_block = get_block(file_size);

    if(creat_fcb(fcb_block, file_block, file_size) == -1){
        return -1;
    }
    if(add_dir_unit(current_dir_table, file_name, 1, fcb_block) == -1){
        return -1;
    }
    return 0;
}

int delete_file(char file_name[]){
    if(strcmp(file_name, "...") == 0){
        printf("Sorry, You Cannot Delete Parent in Current Directory!");
        return -1;
    }

    int unit_index = find_unit_in_table(current_dir_table, file_name);

    if(unit_index == -1){
        printf("The File with name %s Cannot Be Found! Please"
               "Correct the Spelling!", file_name);
        return -1;
    }

    dir_unit current_unit = current_dir_table->dirs[unit_index];

    if(current_unit.type == 0){
        printf("The Name You Entered is Not a File Name But A Direcroty Name,"
               "You Cannot Delete Directory with File-Delecting Instruction\n");
        return -1;
    }




    return 0;
}

int creat_dir(char dir_name[]){
    if(strlen(dir_name) >= 99){
        printf("Directory Name Too Long, Please Try Again!\n");
        return -1;
    }
    int dir_block = get_block(1);
    if(dir_block == -1){
        return -1;
    }

    if(add_dir_unit(current_dir_table, dir_name, 0, dir_block) == -1){
        return -1;
    }

    dir_table* new_table = (dir_table*)get_block_addr(dir_block);
    new_table->unit_amount = 0;

    char parent[] = "...";

    if(add_dir_unit(new_table, parent, 0, get_addr_block((char*)current_dir_table)) == -1){
        return -1;
    }
    return 0;
}
