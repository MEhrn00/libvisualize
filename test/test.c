#include <stdio.h>
#include <string.h>

#include "libvisualize.h"

#define BUFSIZE 0x20

void vuln() {
    char buf[BUFSIZE];

    printf("Stack for vuln.\n");
    visualize_stack();

    getchar();

    memset(buf, 0xff, BUFSIZE + 16);
    visualize_stack();

}

int main() {
    char buf[0x40];

    printf("Stack for main.\n");
    visualize_stack();

    vuln();

    return 0;
}
