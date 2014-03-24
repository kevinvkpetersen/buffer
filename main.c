/* Producers and Consumers - main.c
 * Copyright 2014, Kevin Petersen. All rights reserved.
 */

#include <stdlib.h>
#include "buffer.h"

#define		MAX_THREADS		20
#define		MAX_VALUE		100

buffer b;
int shouldLoop = TRUE;

void producer(void* arg) {
	buffer_item item;
	srand(thread_getID());

	while(shouldLoop) {
		// Insert a random number into the buffer
		item = rand() % MAX_VALUE;
		buf_insert(&b, item);
		// Sleep for a random slice of time
		randSleep();
	}

	thread_exit();
}

void consumer(void* arg) {
	srand(thread_getID());

	while(shouldLoop) {
		// Remove the number from the next position in the buffer
		buf_remove(&b);
		// Sleep for a random slice of time
		randSleep();
	}

	thread_exit();
}

int main(int argc, char **argv) {
	int execTime, numProd, numCon;
	thread producers[MAX_THREADS];
	thread consumers[MAX_THREADS];
	int i;

	if(argc != 4) {
		printf("Usage: buffer [execution time] [# producers] [# consumers]\n");
		return 1;
	}

	// Get arguments from command line
	execTime = atoi(argv[1]);
	numProd = atoi(argv[2]);
	numCon = atoi(argv[3]);

	// Initialize buffer
	b = buf_init();
	
	// Create Producers
	for(i = 0; i < numProd; i++) {
		producers[i] = thread_create((LPTHREAD_START_ROUTINE) producer);
	}

	// Create Consumers
	for(i = 0; i < numCon; i++) {
		consumers[i] = thread_create((LPTHREAD_START_ROUTINE) consumer);
	}

	// Run for the given amount of time
	sleep(execTime);

	// Tell the threads to exit loops
	shouldLoop = FALSE;

	// Wait for threads to exit
	for(i = 0; i < numProd; i++) {
		thread_destroy(&producers[i]);
	}

	for(i = 0; i < numCon; i++) {
		thread_destroy(&consumers[i]);
	}

	// Exit
	return 0;
}