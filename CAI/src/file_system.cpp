#include "file_system.h"

using namespace std;

char path[500];
dir_table* root_dir_table;
dir_table* current_dir_table;


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

char* get_path(){
    return path;
}

int change_name(char pre_name[], char new_name[]){
    int unit_index = find_unit_in_table(current_dir_table, pre_name);
    if(unit_index == -1){
        printf("File cannot be found! Please check again.\n");
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

int delete_dir_unit(dir_table* system_dir_table, int unit_index){
    int dir_unit_amount = system_dir_table->unit_amount;

    for(int i = unit_index; i < dir_unit_amount - 1; i++){
        system_dir_table->dirs[i] = system_dir_table->dirs[i+1];
    }
    system_dir_table->unit_amount--;
    return 0;
}

int create_dir(char dir_name[]){
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

    char parent[] = "..";

    if(add_dir_unit(new_table, parent, 0, get_addr_block((char*)current_dir_table)) == -1){
        return -1;
    }
    return 0;
}

int delete_dir(char dir_name[]){
    int unit_index = find_unit_in_table(current_dir_table, dir_name);

    if(strcmp(dir_name, "..") == 0){
        printf("Cannot Delete the Parent Directory at Current Position."
               "Pleas Try Anoter File Again!\n");
        return -1;
    }
    dir_unit current_unit = current_dir_table->dirs[unit_index];

    if(current_unit.type == 0){
        delete_file_in_table(current_dir_table, unit_index);
    }else{
        printf("It's Not A Directory, You Cannot Use This Instruction "
               "To Delete This File\n");
        return -1;
    }
    delete_dir_unit(current_dir_table, unit_index);
    return 0;
}

int create_fcb(int fcb_block_num, int file_block_number, int file_size){
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

    if(create_fcb(fcb_block, file_block, file_size) == -1){
        return -1;
    }
    if(add_dir_unit(current_dir_table, file_name, 1, fcb_block) == -1){
        return -1;
    }
    return 0;
}

int delete_file(char file_name[]){
    if(strcmp(file_name, "..") == 0){
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

    int fcb_block = current_unit.start_block;

    release_file(fcb_block);

    delete_dir_unit(current_dir_table, unit_index);
    return 0;
}

int delete_file_in_table(dir_table* system_dir_table, int unit_index){
    dir_unit current_unit = system_dir_table->dirs[unit_index];

    if(current_unit.type == 0){
        int fcb_block = current_unit.start_block;
        dir_table* table = (dir_table*) get_block_addr(fcb_block);

        printf("You Have Deleted All the File in the Directory %s\n", current_unit.file_name);

        int unit_count = table->unit_amount;

        for(int i = 1; i < unit_count; i++){
            printf(("Delete %s\n"), table->dirs[i].file_name);
            delete_file_in_table(table, i);
        }
        release_block(fcb_block, 1);
    }else{
        int fcb_block = current_unit.start_block;
        release_file(fcb_block);
    }
    return 0;
}

int release_file(int fcb_block){
    fcb* currrent_fcb = (fcb*)get_block_addr(fcb_block);

    currrent_fcb->link--;

    if(currrent_fcb->link == 0){
        release_block(fcb_block, 1);
    }
    release_block(fcb_block, 1);

    return 0;
}

int write(char file_name[], char content[]){
    int unit_index = find_unit_in_table(current_dir_table, file_name);

    if(unit_index == -1){
        printf("Cannot Find the File, Please Check the Entered File Name!\n");
        return -1;
    }

    int fcb_block = current_dir_table->dirs[unit_index].start_block;
    fcb* system_fcb = (fcb*)get_block_addr(fcb_block);
    write_exec(system_fcb, content);

    return 0;
}

int rewrite(char file_name[], char content[]){
    int unit_index = find_unit_in_table(current_dir_table, file_name);

    if(unit_index == -1){
        printf("Cannot Find the File with Name You Entered in, Please Check And Try Again!\n");
        return -1;
    }

    int fcb_block = current_dir_table->dirs[unit_index].start_block;

    fcb* system_fcb = (fcb*)get_block_addr(fcb_block);

    system_fcb->data_size = 0;
    system_fcb->read_ptr = 0;

    write_exec(system_fcb, content);

    return 0;
}

int write_exec(fcb* system_fcb, char content[]){
    int len = strlen(content);
    int file_size = system_fcb->file_size * block_size;

    char* data = (char*)get_block_addr(system_fcb->block_number);

    for(int i = 0; i < len && system_fcb->data_size < file_size; i ++, system_fcb->data_size++){
        *(data + system_fcb->data_size) = content[i];
    }
    if(system_fcb->data_size == file_size){
        printf("This File Has Reached Its File Size, You Can Try to Resize the "
               "File or Create A New File to Store It!\n");
    }
    return 0;
}

int read(char file_name[], int length){
    int unit_index = find_unit_in_table(current_dir_table, file_name);

    if(unit_index == -1){
        printf("Cannot Find the File, Please Check the Entered File Name!\n");
        return -1;
    }

    int fcb_block = current_dir_table->dirs[unit_index].start_block;
    fcb* system_fcb = (fcb*)get_block_addr(fcb_block);

    read_exec(system_fcb, length);

    return 0;
}

int reread(char file_name[], int length){
    int unit_index = find_unit_in_table(current_dir_table, file_name);

    if(unit_index == -1){
        printf("Cannot Find the File, Please Check the Entered File Name!\n");
        return -1;
    }

    int fcb_block = current_dir_table->dirs[unit_index].start_block;
    fcb* system_fcb = (fcb*)get_block_addr(fcb_block);
    system_fcb->read_ptr = 0;

    read_exec(system_fcb, length);

    return 0;
}

int read_exec(fcb* system_fcb, int length){
    int data_size = system_fcb->data_size;

    char* data = (char*)get_block_addr(system_fcb->block_number);

    for(int i = 0; i < length && system_fcb->read_ptr < data_size; i++, system_fcb->read_ptr++){
        printf("%c", *(data + system_fcb->read_ptr));
    }

    if(system_fcb->read_ptr == data_size){
        printf("#");
    }
    printf("\n");

    return 0;
}
