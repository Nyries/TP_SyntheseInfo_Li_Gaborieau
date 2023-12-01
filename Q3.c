#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//Exit Function
void exitFunction(){
    write(STDOUT_FILENO,"\t Bye bye \n\n",strlen("\t Bye bye \n\n"));
    exit(EXIT_SUCCESS);
}