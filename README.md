# libvisualize
Stack/Heap visualizer library to help aid in teaching binary exploitation.  

**STILL IN DEVELOPMENT**

**ONLY WORKS ON 64-BIT**
PLANS ON 32-BIT IN THE FUTURE

## Building
```bash
$ mkdir build
$ make
```
This will produce a `libvisualize.o` object file in `build/`.  

## Usage
```c
#include <stdio.h>

#include "libvisualize.h"

int main() {
    char buffer[80];

    visualize_stack();

    return 0;
}
```

## Linking
Copy the `includes/libvisualize.h` and built `build/libvisualize.o` files to you project directory.  
Add an includes path to where you put the library and a linking path to where you put the `libvisualize.o` file.  
A basic example is as follows:
```bash
$ ls
challenge.c  libvisualize.h  libvisualize.o
$ gcc -o challenge -I./ -L./ challenge.c -l:libvisualize.o
$ ls
challenge  challenge.c  libvisualize.h  libvisualize.o
```

Look at the `examples/stack/` directory for an example of a challenge utilizing it.
