SOURCES:=$(shell ls ./src/*.c)
INCLUDESDIR:=includes
LDFLAGS:=
TESTFLAGS:=
CFLAGS:=-c -Wall -shared -fstack-protector-all -fPIC -std=gnu99 -I./$(INCLUDESDIR)/
TARGET:=libvisualize
BUILDDIR:=build
CC:=gcc

.PHONY: all clean $(TARGET)

all: $(TARGET)

clean:
	rm -f $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) -o $(BUILDDIR)/$(TARGET).o $(CFLAGS) $(SOURCES) $(LDFLAGS)

test: $(TARGET)
	$(CC) -o test/test test/test.c -Wno-stringop-overflow $(TESTFLAGS) -I./$(INCLUDESDIR)/ -L./$(BUILDDIR) -l:$(TARGET).o
	./test/test
