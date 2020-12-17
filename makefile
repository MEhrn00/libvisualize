SOURCES = $(wildcard ./src/*.c)
INCLUDES = -I./includes
LDFLAGS =
TESTFLAGS =
CFLAGS = -fno-stack-protector -Wall -Wno-frame-address -shared -fPIC -std=gnu99
TARGET = libvisualize
BUILDDIR = build
CC = gcc

.PHONY: all clean build

all: build

clean:
	rm -f $(BUILDDIR)/$(TARGET).o

build: $(SOURCES)
	$(CC) -o $(BUILDDIR)/$(TARGET).o -c $(INCLUDES) $(CFLAGS) $(SOURCES) $(LDFLAGS)

debug: $(SOURCES)
	$(CC) -o $(BUILDDIR)/$(TARGET).o -g $(CFLAGS) $(SOURCES) $(LDFLAGS)
	$(CC) -o test/test test/test.c -Wno-stringop-overflow $(TESTFLAGS) -I./$(INCLUDESDIR)/ -L./$(BUILDDIR) -l:$(TARGET).o

test: $(TARGET)
	$(CC) -o test/test test/test.c -Wno-stringop-overflow $(TESTFLAGS) -I./$(INCLUDESDIR)/ -L./$(BUILDDIR) -l:$(TARGET).o
	./test/test
