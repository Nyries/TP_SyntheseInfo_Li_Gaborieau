#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//Exit Function
void exitFunction(){
    write(STDOUT_FILENO,"\t Bye bye \n\n",strlen("\t Bye bye \n\n"));
    exit(EXIT_SUCCESS);
}

void executeCommand(char *command){
    pid_t pid;
    int status;
    pid = fork();
    if(pid==-1){
        perror("Fork impossible\n");
    }
    if(pid==0){
        execlp(command,command,NULL);
    }
    else{
        wait(&status);
    }
}