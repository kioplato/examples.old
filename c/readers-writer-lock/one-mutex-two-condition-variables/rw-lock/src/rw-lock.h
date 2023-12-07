#pragma once

#include <stdint.h>
#include <pthread.h>

// The readers writer lock structure.
struct rw_lock {
	pthread_mutex_t global;

	pthread_cond_t accept_readers;
	pthread_cond_t accept_writer;

	// The number of readers currently writting.
	uint32_t n_readers_active;
	uint32_t n_readers_waiting;

	// Whether or not there's a writer currently writting.
	bool writer_active;
};

/***** Constructor and destructor *********************************************/

/**
 */
void rw_lock_init(struct rw_lock *lock);

void rw_lock_free(struct rw_lock *lock);

/***** Reader lock ************************************************************/

void rw_lock_read_begin(struct rw_lock *lock);

void rw_lock_read_end(struct rw_lock *lock);

/***** Writer lock ************************************************************/

void rw_lock_write_begin(struct rw_lock *lock);

void rw_lock_write_end(struct rw_lock *lock);
