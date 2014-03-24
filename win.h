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