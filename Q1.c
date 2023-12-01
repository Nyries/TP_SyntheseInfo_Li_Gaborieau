#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define linestart "ensea % "
#define WelcomeMessage \
" \nWelcome to Ensea Shell \nWrite 'exit' if you want to quit!\n"

void welcome(){

    write(STDOUT_FILENO,linestart,sizeof(linestart));
    write(STDOUT_FILENO, WelcomeMessage,strlen(WelcomeMessage));
}

void prompt(){
    write(STDOUT_FILENO, linestart, strlen(linestart));
}
