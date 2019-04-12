#include "std_testcase.h"
#include <pthread.h>
#include "std_thread.h"

struct _stdThread {
    pthread_t handle;
    stdThreadRoutine start;
    void *args;
};



static void *internal_start(void *args)
{
    stdThread thread = (stdThread)args;

    thread->start(thread->args);

    pthread_exit(NULL);
    /* dead code, but return to avoid warnings */
    return NULL;
}

int stdThreadCreate(stdThreadRoutine start, void *args, stdThread *thread)
{

    pthread_t handle;
    stdThread my_thread;

    *thread = NULL;

    my_thread = (stdThread)malloc(sizeof(*my_thread));
    if (my_thread == NULL) {
        return 0;
    }

    my_thread->start = start;
    my_thread->args = args;

    if (0 != pthread_create(&handle, NULL, internal_start, my_thread)) {
        free(my_thread);
        return 0;
    }
    /* clearly, you cannot access _stdThread.handle from within the thread
     * itself, because initialization of this field is not synchronized w.r.t.
     * multiple threads
     */
    my_thread->handle = handle;

    *thread = my_thread;

    return 1;
}

int stdThreadJoin(stdThread thread)
{
    void *dummy;
    if (0 != pthread_join(thread->handle, &dummy)) return 0;
    return 1;
}

int stdThreadDestroy(stdThread thread)
{
    free(thread);
    return 1;
}

struct _stdThreadLock {
    pthread_mutex_t mutex;
};

int stdThreadLockCreate(stdThreadLock *lock)
{
    stdThreadLock my_lock = NULL;

    *lock = NULL;

    my_lock = (stdThreadLock)malloc(sizeof(*my_lock));
    if (my_lock == NULL) return 0;

    if (0 != pthread_mutex_init(&my_lock->mutex, NULL)) {
        free(lock);
        return 0;
    }
    *lock = my_lock;

    return 1;
}

void stdThreadLockAcquire(stdThreadLock lock)
{
    /* pthread_mutex's and CRITICAL_SECTIONS differ
     *
     * CRITICAL_SECTION's are recursive, meaning a thread can acquire a
     * CRITICAL_SECTION multiple times, so long as it then releases it
     * the same number of times.
     *
     * pthread_mutex's seem to be undefined with regards to recursion,
     * meaning that acquiring the same mutex twice leads to undefined
     * behavior (it could deadlock, crash, act recursively, who knows)
     *
     * Therefore, we will define multiple acquisitions of a lock in a
     * single thread as "undefined" behavior, thereby allowing us to
     * ignore the platform compatibility issues here.
     */

    pthread_mutex_lock(&lock->mutex);
}

void stdThreadLockRelease(stdThreadLock lock)
{
    /* see comments in stdThreadLockAcquire with regards to lock
     * recursion */

    pthread_mutex_unlock(&lock->mutex);
}

void stdThreadLockDestroy(stdThreadLock lock)\
{
    pthread_mutex_destroy(&lock->mutex);
    free(lock);
}

