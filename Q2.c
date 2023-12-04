#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "Q1.h"

#define charBuf_size 256

void mainQuestion2() {
    char command[charBuf_size];
    welcome();

    while (1) {
        prompt();  // Display prompt and wait for user input

        read(STDIN_FILENO, command, sizeof(command));
        command[strcspn(command, "\n")] = '\0'; // Remove the newline character from the user input

        pid_t pid = fork();
        if (pid == -1) { //perror
            perror("Fork impossible\n");
        }
        if (pid == 0) { //child

            execlp(command, command, NULL);

        } else { //father
            waitpid(pid, NULL, 0);
        }
    }
}
