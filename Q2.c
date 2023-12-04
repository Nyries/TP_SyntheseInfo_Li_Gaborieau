#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>
#include "Q1.h"

#define charBuf_size 256

void mainQuestion2() {
    char command[charBuf_size];
    welcome();

    while (1) {
        prompt();

        read(STDIN_FILENO, command, sizeof(command));
        command[strcspn(command, "\n")] = '\0';

        pid_t pid = fork();
        if (pid == -1) {
            perror("Fork impossible\n");
        }
        if (pid == 0) {

            execlp(command, command, NULL);

        } else {
            waitpid(pid, NULL, 0);
        }
    }
}
