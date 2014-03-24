/* Producers and Consumers - main.c
 * Copyright 2014, Kevin Petersen. All rights reserved.
 */

#include <stdlib.h>
#include "buffer.h"

#define		MAX_THREADS		20

thread_return producer(void* arg) {
	printf("P");
	thread_exit();
}

thread_return consumer(void* arg) {
	printf("C");
	thread_exit();
}

int main(int argc, char **argv) {
	int execTime, numProd, numCon;
	thread producers[MAX_THREADS];
	thread consumers[MAX_THREADS];
	buffer b;
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