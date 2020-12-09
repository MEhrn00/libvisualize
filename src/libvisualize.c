#include <stddef.h>
#include <stdio.h>
#include <stdint.h>

#include "libvisualize.h"

#define DEPTH 20

void visualize_stack() {
    uint64_t arr[1];
    uint64_t *savedrbp;

    savedrbp = (uint64_t *)arr[2];
    printf("Return -> %p\n", __builtin_return_address(0));
    printf("SavedRBP -> %p\n\n", savedrbp);

    for (int i = 0; i < DEPTH; i++) {
        printf("%p: 0x%08lx\n", savedrbp + i, savedrbp[i]);
    }
}

void visualize_heap() {
}
