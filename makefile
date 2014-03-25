# Producers and Consumers - makefile
# Copyright 2014, Kevin Petersen. All rights reserved.

CC=gcc
EXECUTABLE=buffer
SOURCES=main.c buffer.h
FLAGS=-lpthread

all: clean $(EXECUTABLE)

$(EXECUTABLE): $(SOURCES)
	$(CC) $< -o $@ $(FLAGS)

test: all
	./$(EXECUTABLE) 2 3 4

clean:
	-rm -f $(EXECUTABLE)