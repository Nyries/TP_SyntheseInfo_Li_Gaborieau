#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


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
void readCommand() {
    char command[256];
    int number;

    number = read(STDOUT_FILENO, command, 256);

    command[number - 1] = '\0';
    executeCommand(command);
    write(STDOUT_FILENO, "enseash %", strlen("enseash %"));
}