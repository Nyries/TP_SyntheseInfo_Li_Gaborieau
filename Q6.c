#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <fcntl.h>
#include "Q3.h"
#include "Q1.h"

char linestart6[256]= "enseash % ";


void executeCommand6(char** command){  //Function to execute a complex command with arguments and measure execution time

    struct timespec time_start, time_stop;
    pid_t pid=fork();
    int status;
    clock_gettime(CLOCK_REALTIME, &time_start);
    if (pid==-1){
        perror("Fork impossible\n");
    }
    else if (pid==0){
        execvp(command[0], command);
        exit(EXIT_SUCCESS);
    }
    else{
        while ((pid=wait(&status))!=-1){
            clock_gettime(CLOCK_REALTIME, &time_stop);
            unsigned long long int duration = time_stop.tv_nsec-time_start.tv_nsec;
            if (WIFEXITED(status)) {
                sprintf( linestart6,"enseash [exit:%d|%lldms] %% ", WEXITSTATUS(status),duration/1000000);
            } else if (WIFSIGNALED(status)) {
                sprintf(linestart6,"enseash [sign:%d|%lldms] %% ", WTERMSIG(status), duration/1000000);
            }
            write(STDOUT_FILENO,linestart6, strlen(linestart6));
        }
    }
}
int mainQuestion6(){
    welcome();
    char command[256],*argv[100];
    ssize_t number;
    int i=1;
    write(STDOUT_FILENO,linestart6, strlen(linestart6));
    while((number = read(STDIN_FILENO, command, sizeof(command)))>0) {
        if (number != 0) {
            command[number - 1] = '\0';
        }
        argv[0] = strtok(command, " ");     // helps us to detect spaces, so we can detect arguments in commands.
        while((argv[i] = strtok(NULL, " "))!=NULL) {   // We could also try to detect '-' to find arguments.
            i++;
        }
        if (strcmp(command, "exit") == 0 || number == 0) {
            exitFunction();
        }
        executeCommand6(argv);
    }
    if (number ==-1){
        perror("read");
    }
    exit(EXIT_SUCCESS);
}
