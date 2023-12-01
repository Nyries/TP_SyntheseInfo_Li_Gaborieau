
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "main.h"
#include "Q1.h"
#include "Q2.h"

int main(){
    DisplayShell();
    char command[256];
    int number;

    while(1){
        write(STDOUT_FILENO,"enseash %",strlen("enseash %"));
        number=read(STDOUT_FILENO,command,256);

        command[number-1]='\0';
        executeCommand(command);
    }
    return EXIT_SUCCESS;
}