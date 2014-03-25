/* Producers and Consumers - unix.h
 * Copyright 2014, Kevin Petersen. All rights reserved.
 */

#include <pthread.h>
#include <semaphore.h>

// Generic mutex pseudo-class
typedef struct {
	pthread_mutex_t mutex;
} mutex;

mutex mutex_init(void) {
	mutex m;
	pthread_mutex_init(&m.mutex, NULL);
	return m;
}

void mutex_lock(mutex* m) {
	pthread_mutex_lock(&m->mutex);
}

void mutex_unlock(mutex* m) {
	pthread_mutex_unlock(&m->mutex);
}

void mutex_destroy(mutex* m) {
}

// Generic semaphore pseudo-class
typedef struct {
	sem_t semaphore;
} semaphore;

semaphore semaphore_init(int init, int max) {
	semaphore s;
	sem_init(&s.semaphore, 0, init);
	return s;
}

void semaphore_lock(semaphore* s) {
	sem_wait(&s->semaphore);
}

void semaphore_unlock(semaphore* s) {
	sem_post(&s->semaphore);
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
