/* Producers and Consumers - buffer.h
 * Copyright 2014, Kevin Petersen. All rights reserved.
 */

#include <stdio.h>

#define		BUFFER_SIZE		8
typedef		int				buffer_item;

// Buffer Data structure
typedef struct {
	buffer_item contents[BUFFER_SIZE];
	// Index of the next item to be put in or taken out of the array
	int in, out;
} buffer;

// Pseudo-Constructor
buffer buf_init(void) {
	buffer b;

	b.in = 0;
	b.out = 0;

	return b;
}

void buf_insert(buffer* b, buffer_item item) {
	// Put 'item' in contents
	b->contents[b->in] = item;
	b->in = (b->in + 1) % BUFFER_SIZE;
	printf("Produced %d.\n", item);
}

buffer_item buf_remove(buffer* b) {
	// Remove an item from contents
	buffer_item item = b->contents[b->out];
	b->out = (b->out + 1) % BUFFER_SIZE;
	printf("Consumed %d.\n", item);

	// Return the removed item
	return item;
}