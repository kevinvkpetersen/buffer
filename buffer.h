/* Producers and Consumers - buffer.h
 * Copyright 2014, Kevin Petersen. All rights reserved.
 */

#include <stdio.h>

#ifdef _WIN32
	#include "win.h"
#else
	#include "unix.h"
#endif

#define		BUFFER_SIZE		8
typedef		int				buffer_item;

// Buffer Data structure
typedef struct {
	buffer_item contents[BUFFER_SIZE];
	// Index of the next item to be put in or taken out of the array
	int in, out;
	// Semaphores
	mutex mutex;
	semaphore empty, full;
} buffer;

// Pseudo-Constructor
buffer buf_init(void) {
	buffer b;

	b.in = 0;
	b.out = 0;

	b.mutex = mutex_init();
	b.empty = semaphore_init(BUFFER_SIZE, BUFFER_SIZE);
	b.full = semaphore_init(0, BUFFER_SIZE);

	return b;
}

void buf_insert(buffer* b, buffer_item item) {
	// Wait for a slot to be empty
	semaphore_lock(&b->empty);
	mutex_lock(&b->mutex);

	// Put 'item' in contents
	b->contents[b->in] = item;
	b->in = (b->in + 1) % BUFFER_SIZE;
	printf("Produced %d.\n", item);

	// Release locks
	mutex_unlock(&b->mutex);
	semaphore_unlock(&b->full);
}

buffer_item buf_remove(buffer* b) {
	buffer_item item;

	// Wait for there to be at least one item in the buffer
	semaphore_lock(&b->full);
	mutex_lock(&b->mutex);

	// Remove an item from contents
	item = b->contents[b->out];
	b->out = (b->out + 1) % BUFFER_SIZE;
	printf("Consumed %d.\n", item);

	// Release locks
	mutex_unlock(&b->mutex);
	semaphore_unlock(&b->empty);

	// Return the removed item
	return item;
}
