#include "file_system.h"

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int help();

int main(){
    init_system();

    init_root_dir();

    char input_command[100];
    char user_name[100] = "Supper User";
    printf("TheOS\%s>",user_name);

    scanf("%s", input_command);

    while(strcmp(input_command, "quit") != 0){
        if(strcmp(input_command, "help") == 0){
            help();
        }else if(strcmp(input_command, "cd") == 0){
            char dir_name[100];
            scanf("%s", dir_name);
            change_dir(dir_name);
        }else if(strcmp(input_command, "ls") == 0){
            show_dir();
        }else if(strcmp(input_command, "pwd") == 0){
            printf("%s\n", get_path());
        }else if(strcmp(input_command, "mkdir") == 0){
            char dir_name[100];
            scanf("%s", dir_name);
            create_dir(dir_name);
        }else if(strcmp(input_command, "rmdir") == 0){
            char dir_name[100];
            scanf("%s", dir_name);
            delete_dir(dir_name);
        }else if(strcmp(input_command, "mv") == 0){
            char old_dir_name[100], new_dir_name[100];
            scanf("%s", old_dir_name);
            scanf("%s", new_dir_name);

            change_name(old_dir_name, new_dir_name);
        }else if(strcmp(input_command, "touch") == 0){
            char file_name[100];
            int file_size;

            scanf("%s", file_name);
            scanf("%d", &file_size);
            create_file(file_name, file_size);
        }else if(strcmp(input_command, "rm") == 0){
            char file_name[100];
            scanf("%s", file_name);

            delete_file(file_name);
        }else if(strcmp(input_command, "read") == 0){
            char file_name[100];
            int length;
            scanf("%s", file_name);
            scanf("%d", &length);

            read(file_name, length);
        }else if(strcmp(input_command, "reread") == 0){ //read again from the beginning
            char file_name[100];
            int length;
            scanf("%s", file_name);
            scanf("%d", &length);

            reread(file_name, length);
        }else if(strcmp(input_command, "write") == 0){
            char file_name[100];
            char content[1024];
            scanf("%s", file_name);
            scanf("%s", content);

            write(file_name, content);
        }else if(strcmp(input_command, "rewrite") == 0){
            char file_name[100];
            char content[1024];
            scanf("%s", file_name);
            scanf("%s", content);

            rewrite(file_name, content);
        }else{
            printf("Command Not Found. Enter \"help\" If Needed!\n");
        }

        printf("TheOS\%s\%s>",user_name, get_path());
        scanf("%s", input_command);
    }
    return 0;
}

int help(){
    printf("This is a demonstration of a file system.\n"
           "In the command line, you can enter in the \n"
           "instruction you like in terms of following \n"
           "listed researved user instructions, the command\n"
           "is similar to those in UNIX/LINUX systems.");

    printf("Help instructions (ommited for now)");

    return 0;
}
