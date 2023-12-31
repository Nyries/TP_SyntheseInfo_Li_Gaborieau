#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include "Q3.h"
#include "Q1.h"

char linestart5[256]= "enseash % ";


void executeCommand5(char* command){   // Function to execute a given command and measure the execution time
    pid_t pid;
    pid =fork();
    struct timespec time_start, time_stop;
    int status;
    clock_gettime(CLOCK_REALTIME, &time_start); // Get the start time before executing the command
    if (pid==-1){
        perror("Fork impossible");
    }
    else if (pid==0){ //child
        execlp(command, command, NULL);
        exit(EXIT_SUCCESS);
    }
    else{ //parent
        while ((pid=wait(&status))!=-1){
            clock_gettime(CLOCK_REALTIME, &time_stop);   // Get the stop time after the command execution
            unsigned long long int duration = time_stop.tv_nsec-time_start.tv_nsec;    // Calculate the duration
            if (WIFEXITED(status)) {
                sprintf( linestart5,"enseash [exit:%d|%lldms] %% ", WEXITSTATUS(status),duration/1000000);
            } else if (WIFSIGNALED(status)) {
                sprintf(linestart5,"enseash [sign:%d|%lldms] %% ", WTERMSIG(status), duration/1000000);
            }
        }
    }
}
int mainQuestion5(){
    welcome();
    char command[256];
    ssize_t number;
    write(STDOUT_FILENO,linestart5, strlen(linestart5));
    while((number = read(STDIN_FILENO, command, sizeof(command)))>0) {
        write(STDOUT_FILENO,linestart5, strlen(linestart5));
        if (number != 0) {
            command[number - 1] = '\0';
        }
        if (strcmp(command, "exit") == 0 || number == 0) {
            exitFunction();
        }
        executeCommand5(command);  // Execute the entered command, measure the execution time, and display the information in the prompt
    }
    if (number ==-1){
        perror("read");
    }
    exit(EXIT_SUCCESS);
}
