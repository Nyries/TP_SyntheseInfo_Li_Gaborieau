#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "Q3.h"
#include "Q1.h"

char linestart4[256]= "enseash % ";


void executeCommand4(char* command){
    pid_t pid;
    pid =fork();
    int status;
    if (pid==-1){
        perror("Fork impossible");
    }
    else if (pid==0){
        execlp(command, command, NULL);
        exit(EXIT_SUCCESS);
    }
    else{
        while((pid=wait(&status))!=-1) {
            if (WIFEXITED(status)) {
                sprintf(linestart4, "enseash [exit:%d] %% ", WEXITSTATUS(status));
            } else if (WIFSIGNALED(status)) {
                sprintf(linestart4, "enseash [sign:%d] %% ", WTERMSIG(status));
            }
        }
    }
}
int mainQuestion4(){
    welcome();
    char command[256];
    ssize_t number;
    write(STDOUT_FILENO,linestart4, strlen(linestart4));
    while((number = read(STDIN_FILENO, command, sizeof(command)))>0) {
        write(STDOUT_FILENO,linestart4, strlen(linestart4));
        if (number != 0) {
            command[number - 1] = '\0';
        }
        if (strcmp(command, "exit") == 0 || number == 0) {
            exitFunction();
        }
        executeCommand4(command);
    }
    if (number ==-1){
        perror("read");
    }

    exit(EXIT_SUCCESS);
}
