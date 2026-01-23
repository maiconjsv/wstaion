CC = gcc
CFLAGS = -Wall -Wextra
TARGET = wstaon

SRC = src/main.c src/launcher.c

all: $(TARGET)

$(TARGET):
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET).exe

clean:
	del $(TARGET).exe
