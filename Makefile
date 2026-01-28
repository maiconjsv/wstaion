CC = gcc
CFLAGS = -Wall -Wextra -O2
TARGET = wstation
PREFIX = /usr/local

SRC = src/main.c

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

install:
	sudo cp $(TARGET) $(PREFIX)/bin/
	sudo chmod +x $(PREFIX)/bin/$(TARGET)

uninstall:
	sudo rm -f $(PREFIX)/bin/$(TARGET)

clean:
	rm -f $(TARGET)
