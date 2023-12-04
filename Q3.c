#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "Q1.h"
//For the 3rd question
//Exit Function
void exitFunction(){
    write(STDOUT_FILENO,"Bye bye... \n",strlen("Bye bye... \n"));
    exit(EXIT_SUCCESS);
}
void executeCommand(char *command){
    pid_t pid;
    pid =fork();
    if (pid==-1){
        perror("Fork impossible\n");
    }
    else if (pid==0){
        execlp(command, command, NULL);
        exit(EXIT_SUCCESS);
    }
    else{
        waitpid(pid,NULL,0);
    }
}

int mainQuestion3(){
    welcome();
    char command[256];
    int number;

    while(1){
        prompt();
        number=read(STDOUT_FILENO,command,sizeof(command));
        if (number!=0){
            command[number-1]= '\0';
        }
        if (strcmp(command,"exit")==0 ||number==0){
            exitFunction();
        }
        executeCommand(command);
    }
    exit(EXIT_SUCCESS);
}

