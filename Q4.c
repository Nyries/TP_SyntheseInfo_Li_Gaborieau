#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "Q3.h"
#include "Q1.h"

char linestart[256]= "enseash % ";


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
        while ((pid=wait(&status))!=-1){
            if (WIFEXITED(status)) {
                sprintf( linestart,"enseash [exit:%d] %% ", WEXITSTATUS(status));
            } else if (WIFSIGNALED(status)) {
                sprintf(linestart,"enseash [sign:%d] %% ", WTERMSIG(status));
            }
        }
    }
}
int mainQuestion4(){
    welcome();
    char command[256];
    int number;

    while(1){
        write(STDOUT_FILENO,linestart, strlen(linestart));
        number=read(STDOUT_FILENO,command,sizeof(command));
        if (number!=0){
            command[number-1]= '\0';
        }
        if (strcmp(command,"exit")==0 ||number==0){
            exitFunction();
        }
        executeCommand4(command);
    }
    exit(EXIT_SUCCESS);
}
