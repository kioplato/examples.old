# Cache misses demo

Two examples perform a similar operation:
1. Allocate 1,000,000 `uint32_t` items in heap.
2. Assign a random value to each such item.
3. Print the items to standard output.

The `cache-unfriendly.c` program does this by randomly picking an index to write
the random value from the 1,000,000 `uint32_t` items. Then, randomly again prints
them to standard output. This, obviously, messes up the cache line.

The `cache-friendly.c` program does this by iterating the items from index 0
towards the last item at index 999,999. Then prints the items again, from 0
towards 999,999. This is more friendly towards the cache.

## Cache-unfriendly results

```
I refs:        14,476,953,990
I1  misses:             1,265
LLi misses:             1,257
I1  miss rate:           0.00%
LLi miss rate:           0.00%

D refs:         5,337,524,579  (3,245,093,776 rd   + 2,092,430,803 wr)
D1  misses:        19,978,183  (    9,989,860 rd   +     9,988,323 wr)
LLd misses:        13,745,638  (    6,854,079 rd   +     6,891,559 wr)
D1  miss rate:            0.4% (          0.3%     +           0.5%  )
LLd miss rate:            0.3% (          0.2%     +           0.3%  )

LL refs:           19,979,448  (    9,991,125 rd   +     9,988,323 wr)
LL misses:         13,746,895  (    6,855,336 rd   +     6,891,559 wr)
LL miss rate:             0.1% (          0.0%     +           0.3%  )
```

## Cache-friendly results

```
I refs:        13,657,712,596
I1  misses:             1,263
LLi misses:             1,255
I1  miss rate:           0.00%
LLi miss rate:           0.00%

D refs:         4,835,596,857  (2,897,810,281 rd   + 1,937,786,576 wr)
D1  misses:         1,251,699  (      626,287 rd   +       625,412 wr)
LLd misses:         1,251,561  (      626,166 rd   +       625,395 wr)
D1  miss rate:            0.0% (          0.0%     +           0.0%  )
LLd miss rate:            0.0% (          0.0%     +           0.0%  )

LL refs:            1,252,962  (      627,550 rd   +       625,412 wr)
LL misses:          1,252,816  (      627,421 rd   +       625,395 wr)
LL miss rate:             0.0% (          0.0%     +           0.0%  )
```
