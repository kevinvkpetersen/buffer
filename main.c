/* Producers and Consumers - main.c
 * Copyright 2014, Kevin Petersen. All rights reserved.
 */

#include <stdlib.h>
#include "buffer.h"

int main(int argc, char **argv) {
	int i;

	// Initialize buffer
	buffer b = buf_init();
	
	// Create Producers
	for(i = 1; i < argc; i++) {
		buf_insert(&b, atoi(argv[i]));
	}

	// Create Consumers
	for(i = 1; i < argc; i++) {
		buf_remove(&b);
	}

	// Exit
	return 0;
}