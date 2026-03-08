CC = gcc
CFLAGS = -Wall -Wextra -O2
TARGET = wstaion
SRC = src/main.c

PREFIX = /usr/local

VERSION := $(shell git describe --tags --always)

# cross compiler windows
WINCC = x86_64-w64-mingw32-gcc
WINTARGET = wstaion.exe

all: $(TARGET)

$(TARGET):
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) -DVERSION=\"$(VERSION)\"

windows:
	$(WINCC) $(CFLAGS) $(SRC) -o $(WINTARGET) -DVERSION=\"$(VERSION)\"

install: $(TARGET)
	sudo cp $(TARGET) $(PREFIX)/bin/
	sudo chmod +x $(PREFIX)/bin/$(TARGET)

uninstall:
	sudo rm -f $(PREFIX)/bin/$(TARGET)

clean:
	rm -f $(TARGET)