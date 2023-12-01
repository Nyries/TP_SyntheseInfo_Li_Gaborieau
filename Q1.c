#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void DisplayShell(){
    char *WelcomeMessage = " Welcome to Ensea Shell \nWrite 'exit' if you want to quit!\n";
    char *prompt= "enseash %";
    write(STDOUT_FILENO,"./enseash\n",strlen("./enseash\n"));
    write(STDOUT_FILENO, WelcomeMessage,strlen(WelcomeMessage));
    write(STDOUT_FILENO, prompt, strlen(prompt));
}

