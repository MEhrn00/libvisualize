SOURCES = $(shell ls ./src/*.c)
LDFLAGS = -l:libvisualize.o
CFLAGS = -fno-stack-protector -no-pie
INCLUDES = -I./includes
LIBS = -L./libs
TARGET = challenge
CC = gcc

.PHONY: all clean $(TARGET)

all: $(TARGET)

clean:
	rm -f $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) -o $(TARGET) $(INCLUDES) $(LIBS) $(CFLAGS) $(SOURCES) $(LDFLAGS)
