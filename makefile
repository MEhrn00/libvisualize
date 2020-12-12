SOURCES:=$(shell ls ./src/*.c)
INCLUDESDIR:=includes
LDFLAGS:=
TESTFLAGS:=
CFLAGS:=-c -fno-stack-protector -Wall -Wno-frame-address -shared -fPIC -std=gnu99 -I./$(INCLUDESDIR)/
TARGET:=libvisualize
BUILDDIR:=build
CC:=gcc

.PHONY: all clean $(TARGET)

all: $(TARGET)

clean:
	rm -f $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) -o $(BUILDDIR)/$(TARGET).o $(CFLAGS) $(SOURCES) $(LDFLAGS)

debug: $(SOURCES)
	$(CC) -o $(BUILDDIR)/$(TARGET).o -g $(CFLAGS) $(SOURCES) $(LDFLAGS)
	$(CC) -o test/test test/test.c -Wno-stringop-overflow $(TESTFLAGS) -I./$(INCLUDESDIR)/ -L./$(BUILDDIR) -l:$(TARGET).o

test: $(TARGET)
	$(CC) -o test/test test/test.c -Wno-stringop-overflow $(TESTFLAGS) -I./$(INCLUDESDIR)/ -L./$(BUILDDIR) -l:$(TARGET).o
	./test/test
