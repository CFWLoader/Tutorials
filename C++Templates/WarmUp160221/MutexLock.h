#ifndef MUTEXLOCK_H_
#define MUTEXLOCK_H_

#include <pthread.h>


class MutexLock 
{
public:

	MutexLock();

	~MutexLock();

	void lock();

	void unlock();

private:
	pthread_mutex_t theMutexLock;
};

class MutexLockGuard
{
public:

	explicit MutexLockGuard(MutexLock&);

	~MutexLockGuard();

private:

	MutexLock& theLock;
	
};

#endif