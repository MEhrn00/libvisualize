SOURCES:=$(shell ls ./src/*.c)
INCLUDESDIR:=includes
LDFLAGS:=
CFLAGS:=-Wall -shared -fstack-protector-all -fPIC -std=gnu99 -I./$(INCLUDESDIR)/
TARGET:=libvisualize.so
BUILDDIR:=build
CC:=gcc

.PHONY: all clean $(TARGET)

all: $(TARGET)

clean:
	rm -f $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) -o $(BUILDDIR)/$(TARGET) $(CFLAGS) $(SOURCES) $(LDFLAGS)

test: $(TARGET)
	$(CC) -o test/test test/test.c -Wall -I./includes/ -L./build -l:libvisualize.so
	LD_LIBRARY_PATH=./build ./test/test
