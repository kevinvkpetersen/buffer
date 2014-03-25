/* Producers and Consumers - unix.h
 * Copyright 2014, Kevin Petersen. All rights reserved.
 */

// Generic mutex pseudo-class
typedef struct {

} mutex;

mutex mutex_init(void) {
	mutex m;
	return m;
}

void mutex_lock(mutex* m) {

}

void mutex_unlock(mutex* m) {

}

void mutex_destroy(mutex* m) {

}

// Generic semaphore pseudo-class
typedef struct {

} semaphore;

semaphore semaphore_init(int init, int max) {
	semaphore s;
	return s;
}

void semaphore_lock(semaphore* s) {

}

void semaphore_unlock(semaphore* s) {

}

void semaphore_destroy(semaphore* s) {

}

// Generic thread pseudo-class
typedef struct {

} thread;

typedef void* LPTHREAD_START_ROUTINE;

thread thread_create(LPTHREAD_START_ROUTINE target) {
	thread t;
	return t;
}

int thread_getID(void) {
	return 0;
}

void thread_exit(void) {

}

void thread_destroy(thread *t) {

}

// Sleeps for a random interval between 250ms and 500ms
void randSleep(void) {
	int time = rand() % 250;
	time += 250;
	usleep(time*1000);
}
