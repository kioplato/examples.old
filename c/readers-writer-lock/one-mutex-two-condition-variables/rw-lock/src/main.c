#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>

#include "rw-lock.h"

struct thread_args {
	uint32_t thr_id;

	bool reader;
	bool writer;

	struct rw_lock *lock;
};

void* worker_main(void *memory)
{
	struct thread_args args = *(struct thread_args*)memory;

	printf("[thread %u]: I'm reader = %d. I'm writer = %d\n", args.thr_id, args.reader, args.writer);

	if (args.reader) {
		rw_lock_read_begin(args.lock);

		printf("[thread %u]: I'm reading\n", args.thr_id);
		sleep(5);
		printf("[thread %u]: Done reading\n", args.thr_id);

		rw_lock_read_end(args.lock);
	}
	else if (args.writer) {
		rw_lock_write_begin(args.lock);

		printf("[thread %u]: I'm writting\n", args.thr_id);
		sleep(5);
		printf("[thread %u]: Done writting\n", args.thr_id);

		rw_lock_write_end(args.lock);
	}

	return NULL;
}

int main()
{
	struct rw_lock lock;
	rw_lock_init(&lock);

	pthread_t writer;
	struct thread_args writer_args = {
		.thr_id = 20,
		.reader = false,
		.writer = true,
		.lock = &lock
	};
	pthread_create(&writer, NULL, worker_main, &writer_args);

	pthread_t readers[20];
	struct thread_args thread_args[20];
	for (uint32_t c_reader = 0; c_reader < 20; ++c_reader) {
		struct thread_args args = {
			.thr_id = c_reader,
			.reader = true,
			.writer = false,
			.lock = &lock
		};
		thread_args[c_reader] = args;

		pthread_create(&readers[c_reader], NULL, worker_main, &thread_args[c_reader]);
	}

	pthread_t readers_second_batch[40];
	struct thread_args readers_args[40];
	for (uint32_t c_reader = 0; c_reader < 40; ++c_reader) {
		struct thread_args args = {
			.thr_id = 21 + c_reader,
			.reader = true,
			.writer = false,
			.lock = &lock
		};
		readers_args[c_reader] = args;

		pthread_create(&readers_second_batch[c_reader], NULL, worker_main, &readers_args[c_reader]);
	}

	for (uint32_t i = 0; i < 20; ++i)
		pthread_join(readers[i], NULL);
	pthread_join(writer, NULL);
	for (uint32_t i = 0; i < 40; ++i)
		pthread_join(readers_second_batch[i], NULL);

	//// Create a reader.
	//pthread_t thread1;
	//struct thread_args thread1_args = {
	//	.thr_id = 0,
	//	.reader = true,
	//	.writer = false,
	//	.lock = &lock
	//};
	//pthread_create(&thread1, NULL, worker_main, &thread1_args);


	//pthread_t thread2;
	//struct thread_args thread2_args = {
	//	.thr_id = 1,
	//	.reader = true,
	//	.writer = false,
	//	.lock = &lock
	//};
	//pthread_create(&thread2, NULL, worker_main, &thread2_args);

	//// Wait for workers.
	//pthread_join(thread1, NULL);
	//pthread_join(thread2, NULL);
	//pthread_join(thread3, NULL);

	rw_lock_free(&lock);
}
