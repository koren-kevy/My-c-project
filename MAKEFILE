CC = gcc
CFLAGS = -Wall -ansi -pedantic
TARGET = letters
SRCS = letters.c

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET)

.PHONY: all clean
