#include "MutexLock.h"

MutexLock::MutexLock()
{
	pthread_mutex_init(&theMutexLock, nullptr);
}

MutexLock::~MutexLock()
{
	pthread_mutex_destroy(&theMutexLock);
}

void MutexLock::lock()
{
	pthread_mutex_lock(&theMutexLock);
}

void MutexLock::unlock()
{
	pthread_mutex_unlock(&theMutexLock);
}

MutexLockGuard::MutexLockGuard(MutexLock& theMutexLock) : theLock(theMutexLock)
{
	theLock.lock();
}

MutexLockGuard::~MutexLockGuard()
{
	theLock.unlock();
}