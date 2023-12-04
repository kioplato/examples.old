# Implementation of readers writer lock using two mutexes and one counter

To implement this readers-writer lock we need two mutexes and one counter.
This lock is readers-preferring since it will block writers from accessing
the shared resource until no readers are reading it, even though the readers
that were reading the shared resource when the writer arrived have completed
their work and others have taken their place.

Required components of the lock:
* $b$ counter
* $r$ mutex
* $g$ mutex

# States of the lock

__Initialize lock__:
* Set $b = 0$
* $r$ is unlocked
* $g$ is unlocked

__Read begin__:
1. Lock $r$
2. Increment $b$
3. if $b == 1$, lock $g$
4. Unlock $r$

__End read__:
1. Lock $r$
2. Decrement $b$
3. if $b == 0$, unlock $g$
4. Unlock $r$

__Begin write__:
* Lock $g$

__End write__:
* Unlock $g$
