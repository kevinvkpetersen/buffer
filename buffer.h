/* Producers and Consumers - buffer.h
 * Copyright 2014, Kevin Petersen. All rights reserved.
 */

#include <stdio.h>

#define		BUFFER_SIZE		8

// Buffer Data structure
struct Buffer {
	int contents[BUFFER_SIZE];
	// Index of the next item to be put in or taken out of the array
	int in, out;
};

void buf_insert(struct Buffer* b, int item) {
	// Put 'item' in contents
	b->contents[b->in] = item;
	b->in = (b->in + 1) % BUFFER_SIZE;
	printf("Produced %d.\n", item);
}

int buf_remove(struct Buffer* b) {
	// Remove an item from contents
	int item = b->contents[b->out];
	b->out = (b->out + 1) % BUFFER_SIZE;
	printf("Consumed %d.\n", item);

	// Return the removed item
	return item;
}