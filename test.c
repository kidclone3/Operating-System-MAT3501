// #include <fork>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int pid = fork();
    if (pid == 0) {
        pid = fork();
        printf("Small\n");
        if (pid != 0) fork();
        fork(); printf("Medium\n");
    } else printf("Grand\n");
    return 0;
}