#include <stdio.h>

#include "libvisualize.h"

int main() {

    char buf[0x20];

    visualize_stack();

    printf("input > ");
    fgets(buf, 0x20 + 17, stdin);

    visualize_stack();

    return 0;
}
