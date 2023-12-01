#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
//For the 3rd we modified the Q2.c file
//Exit Function
void exitFunction(){
    write(STDOUT_FILENO,"Bye bye... \n",strlen("Bye bye... \n"));
    exit(EXIT_SUCCESS);
}

void dateFunction(){
    time_t t = time(NULL);
    char *date;
    sprintf(date,"%ld",t);
    write(STDOUT_FILENO,date,strlen(date));
}