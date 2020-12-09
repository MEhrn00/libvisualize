#include <stddef.h>
#include <stdio.h>
#include <stdint.h>

#include "libvisualize.h"

// #defines for colors
#define COLOR_RED       "\x1b[31m"
#define COLOR_GREEN     "\x1b[32m"
#define COLOR_BLUE      "\x1b[34m"
#define COLOR_YELLOW    "\x1b[33m"
#define COLOR_RESET     "\x1b[0m"


// TODO: Implement canary checking and displaying
void visualize_stack() {
    uint64_t arr[1];
    uint64_t *rbp;
    uint64_t *ret_p;
    uint64_t *saved_rbp;
    int delta;

    // Get the value of RSP
    uint64_t *rsp = __builtin_frame_address(0) + 0x10;

    // Get the value of RBP
    rbp = (uint64_t *)arr[2];

    // Set the saved rbp value to the value of rbp.
    saved_rbp = rbp;

    // Get the saved return address
    ret_p = saved_rbp + 1;

    // Calculate the difference between RBP and RSP
    delta = rbp - rsp;

    // Print the legend at the top containing the registers and return address
    printf("\n");
    printf("RSP = %p\n", rsp);
    printf("RBP = %p\n", rbp);

    printf("RET = %p -> ", ret_p);
    printf(COLOR_RED);
    printf("%#018lx", *ret_p);
    printf(COLOR_RESET);
    printf("\n\n");

    // Print out a hexdump of the stack
    printf("Stack:\n");
    for (int i = 0; i <= delta; i++) {
        printf("%p | ", rsp);
        for (int j = 0; j < 8; j++) {
            printf("%02x ", *((uint8_t *)rsp + j));
        }
        printf("|\n");
        rsp++;
    }

    // Print out the color hexdump of the return address
    printf("%p | ", rsp);
    printf(COLOR_RED);
    for (int i = 0; i < 8; i++) {
        printf("%02x ", *((uint8_t *)rsp + i));
    }
    printf(COLOR_RESET);
    printf("|\n");

    printf("\n");
}

void visualize_heap() {
    // TODO: Implement
}
