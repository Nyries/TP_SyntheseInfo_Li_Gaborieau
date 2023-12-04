#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <fcntl.h>
#include "Q3.h"
#include "Q1.h"

char linestart7[256]= "enseash % ";


void executeCommand7(char** command){

    struct timespec time_start, time_stop;
    pid_t pid=fork();

    char *filename,**tok=command;
    int chevrons,in=0,out=0,status;
    clock_gettime(CLOCK_REALTIME, &time_start);

    while (*tok!=NULL) {
        if (strcmp(*tok, "<") == 0) {
            chevrons = 1;
            in = 1;
            *tok = NULL;
        }
        if (strcmp(*tok, ">") == 0) {
            chevrons = 1;
            out = 1;
            *tok = NULL;
        }
        tok++;
        if (chevrons == 1) {
            filename = *tok;
            break;
        }
    }
    if (pid==-1){
        perror("Fork impossible\n");
    }
    else if (pid==0){
        if (in) {
            int fd0=open(filename,O_RDONLY);
            dup2(fd0,STDIN_FILENO);
            close(fd0);
            in=0;
        }
        if (out){
            int fd1 = creat(filename, S_IROTH|S_IRGRP|S_IRUSR);
            dup2(fd1, STDOUT_FILENO);
            close(fd1);
            out = 0;
        }
        execvp(command[0], command);
        exit(EXIT_SUCCESS);
    }
    else{
        while ((pid=wait(&status))!=-1){
            clock_gettime(CLOCK_REALTIME, &time_stop);
            unsigned long long int duration = time_stop.tv_nsec-time_start.tv_nsec;
            if (WIFEXITED(status)) {
                sprintf( linestart7,"enseash [exit:%d|%lldms] %% ", WEXITSTATUS(status),duration/1000000);
            } else if (WIFSIGNALED(status)) {
                sprintf(linestart7,"enseash [sign:%d|%lldms] %% ", WTERMSIG(status), duration/1000000);
            }
            write(STDOUT_FILENO,linestart7, strlen(linestart7));
        }
    }
}
int mainQuestion7(){
    welcome();
    char command[256],*argv[100];
    ssize_t number;
    int i=1;
    write(STDOUT_FILENO,linestart7, strlen(linestart7));
    while((number = read(STDIN_FILENO, command, sizeof(command)))>0) {
        if (number != 0) {
            command[number - 1] = '\0';
        }
        argv[0] = strtok(command, " "); //helps us to detect spaces, so we can detect arguments in commands.
        while((argv[i] = strtok(NULL, " "))!=NULL) {//We could also try to detect '-' to find arguments.
            i++;
        }
        if (strcmp(command, "exit") == 0 || number == 0) {
            exitFunction();
        }
        executeCommand7(argv);
    }
    if (number ==-1){
        perror("read");
    }
    exit(EXIT_SUCCESS);
}
