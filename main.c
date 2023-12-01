
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "Q1.h"
#include "Q2.h"

int main(){
    DisplayShell();

    while(1){
        readCommand();
    }
    return EXIT_SUCCESS;
}