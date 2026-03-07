CC = gcc
CFLAGS = -Wall -Wextra -O2
TARGET = wstaion
SRC = src/main.c

PREFIX = /usr/local

VERSION := $(shell git describe --tags --always)

all: $(TARGET)

$(TARGET):
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) -DVERSION=\"$(VERSION)\"

install: $(TARGET)
	sudo cp $(TARGET) $(PREFIX)/bin/
	sudo chmod +x $(PREFIX)/bin/$(TARGET)

uninstall:
	sudo rm -f $(PREFIX)/bin/$(TARGET)

clean:
	rm -f $(TARGET)