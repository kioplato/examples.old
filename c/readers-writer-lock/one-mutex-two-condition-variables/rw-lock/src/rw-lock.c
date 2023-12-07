#include <stdint.h>
#include <stdbool.h>
#include <pthread.h>

#include "rw-lock.h"

void rw_lock_init(struct rw_lock *lock)
{
	pthread_mutex_init(&lock->global, NULL);

	pthread_cond_init(&lock->accept_readers, NULL);
	pthread_cond_init(&lock->accept_writer, NULL);

	lock->n_readers_active = 0;
	lock->n_readers_waiting = 0;

	lock->writer_active = false;
}

void rw_lock_free(struct rw_lock *lock)
{
	pthread_mutex_destroy(&lock->global);

	pthread_cond_destroy(&lock->accept_readers);
	pthread_cond_destroy(&lock->accept_writer);
}

void rw_lock_read_begin(struct rw_lock *lock)
{
	pthread_mutex_lock(&lock->global);

	++lock->n_readers_waiting;

	if (lock->writer_active)
		pthread_cond_wait(&lock->accept_readers , &lock->global);

	--lock->n_readers_waiting;
	++lock->n_readers_active;

	pthread_mutex_unlock(&lock->global);
}

void rw_lock_read_end(struct rw_lock *lock)
{
	pthread_mutex_lock(&lock->global);

	--lock->n_readers_active;

	if (lock->n_readers_active == 0)
		pthread_cond_signal(&lock->accept_writer);

	pthread_mutex_unlock(&lock->global);
}

void rw_lock_write_begin(struct rw_lock *lock)
{
	pthread_mutex_lock(&lock->global);

	while (lock->n_readers_active || lock->n_readers_waiting || lock->writer_active)
		pthread_cond_wait(&lock->accept_writer, &lock->global);

	lock->writer_active = true;

	pthread_mutex_unlock(&lock->global);
}

void rw_lock_write_end(struct rw_lock *lock)
{
	pthread_mutex_lock(&lock->global);

	lock->writer_active = false;

	if (lock->n_readers_waiting)
		pthread_cond_broadcast(&lock->accept_readers);
	else
		pthread_cond_signal(&lock->accept_writer);

	pthread_mutex_unlock(&lock->global);
}
