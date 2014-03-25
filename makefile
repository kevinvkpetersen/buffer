# Producers and Consumers - makefile
# Copyright 2014, Kevin Petersen. All rights reserved.

CC=gcc
EXECUTABLE=buffer
SOURCES=main.c buffer.h

all: clean $(EXECUTABLE)

$(EXECUTABLE): $(SOURCES)
	$(CC) $< -o $@

clean:
	-rm -f $(EXECUTABLE)