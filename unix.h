/* Producers and Consumers - unix.h
 * Copyright 2014, Kevin Petersen. All rights reserved.
 */

#include <pthread.h>
#include <semaphore.h>
#include <fcntl.h>

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
	sem_t* semaphore;
	char* name;
} semaphore;

semaphore semaphore_init(char*name, int init, int max) {
	semaphore s;
	s.name = name;
	s.semaphore = sem_open(name, O_CREAT, S_IRUSR | S_IWUSR, init);
	return s;
}

void semaphore_lock(semaphore* s) {
	sem_wait(s->semaphore);
}

void semaphore_unlock(semaphore* s) {
	sem_post(s->semaphore);
}

void semaphore_destroy(semaphore* s) {
	sem_close(s->semaphore);
	sem_unlink(s->name);
}

// Generic thread pseudo-class
typedef struct {
	pthread_t thread;
} thread;

typedef void* LPTHREAD_START_ROUTINE;

thread thread_create(LPTHREAD_START_ROUTINE target) {
	pthread_attr_t attr;
	thread t;

	pthread_attr_init(&attr);
	pthread_create(&t.thread, &attr, target, NULL);

	return t;
}

int thread_getID(void) {
	return pthread_self();
}

void thread_exit(void) {
	pthread_exit(NULL);
}

void thread_destroy(thread* t) {
	pthread_join(t->thread, NULL);
}

// Sleeps for a random interval between 250ms and 500ms
void randSleep(void) {
	int time = rand() % 250;
	time += 250;
	usleep(time*1000);
}
