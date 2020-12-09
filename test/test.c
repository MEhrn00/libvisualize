#include "libvisualize.h"

int main() {

    volatile char foo[] = {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', '\0'};

    visualize_stack();

    return 0;
}
