#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

#include "libvisualize.h"

void timeout(int sig) {
    if (sig == SIGALRM) {
        printf("Sorry too slow.....\n");
        _exit(0);
    }
}

// Invoke this function before main
__attribute__((constructor))
void setup() {
    // Turn off buffering for stdin/stdout
    setbuf(stdout, NULL);
    setbuf(stdin, NULL);

    // Set an alarm for 60 seconds to prevent abuse
    signal(SIGALRM, timeout);
    alarm(60);
}

void win() {
    system("/bin/sh");
}

void vuln() {
    char buffer[0x80];

    visualize_stack();

    printf("Overflow the stack: ");
    gets(buffer);

    visualize_stack();
}

int main(void) {

    vuln();

    return 0;
}
