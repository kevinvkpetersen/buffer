/* Producers and Consumers - win.h
 * Copyright 2014, Kevin Petersen. All rights reserved.
 */

#include <Windows.h>

// Generic mutex pseudo-class
typedef struct {
	HANDLE handle;
} mutex;

mutex mutex_init(void) {
	mutex m;
	m.handle = CreateMutex(NULL, FALSE, NULL);
	return m;
}

void mutex_lock(mutex* m) {
	WaitForSingleObject(m->handle, INFINITE);
}

void mutex_unlock(mutex* m) {
	ReleaseMutex(m->handle);
}

void mutex_destroy(mutex* m) {
	CloseHandle(m->handle);
}

// Generic semaphore pseudo-class
typedef struct {
	HANDLE handle;
} semaphore;

semaphore semaphore_init(int init, int max) {
	semaphore s;
	s.handle = CreateSemaphore(NULL, init, max, NULL);
	return s;
}

void semaphore_lock(semaphore* s) {
	WaitForSingleObject(s->handle, INFINITE);
}

void semaphore_unlock(semaphore* s) {
	ReleaseSemaphore(s->handle, 1, NULL);
}

void semaphore_destroy(semaphore* s) {
	CloseHandle(s->handle);
}

// Generic thread pseudo-class
typedef struct {
	HANDLE handle;
} thread;

thread thread_create(LPTHREAD_START_ROUTINE target) {
	thread t;
	t.handle = CreateThread(NULL, 0, target, NULL, 0, NULL);
	return t;
}

int thread_getID(void) {
	return GetCurrentThreadId();
}

void thread_exit(void) {
	ExitThread(0);
}

void thread_destroy(thread *t) {
	CloseHandle(t->handle);
}

// Unix-style sleep function
void sleep(int sec) {
	Sleep(sec*1000);
}

// Sleeps for a random interval between 250ms and 500ms
void randSleep(void) {
	int time = rand() % 250;
	time += 250;
	Sleep(time);
}