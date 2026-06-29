# Fenwick Tree (Binary Indexed Tree) - Part 1: Basic Introduction & Idea

# 1. Why Do We Need a Fenwick Tree?

Suppose we have an array

```
Index : 1 2 3 4 5
Value : 2 3 5 7 1
```

We need to support two operations efficiently:

1. Update an element

```
A[3] += 4
```

2. Find the sum of a range

```
sum(2,5)
```

---

## Naive Solution

### Query

Simply iterate over the range.

```cpp
int sum(int l, int r) {
    int ans = 0;
    for(int i=l;i<=r;i++)
        ans += A[i];
    return ans;
}
```

Time Complexity

```
O(N)
```

---

### Update

```cpp
A[idx] += val;
```

Time Complexity

```
O(1)
```

Problem:

If there are 2×10^5 queries,

```
O(NQ)
```

is too slow.

---

# Prefix Sum Array

We can precompute

```
prefix[i]
=
A1+A2+...+Ai
```

Example

```
Array

2 3 5 7 1

Prefix

2 5 10 17 18
```

Now

```
sum(l,r)

=

prefix[r]-prefix[l-1]
```

Example

```
sum(2,4)

=

17-2

=

15
```

Query

```
O(1)
```

Amazing!

---

## But Updates Become Slow

Suppose

```
A[3]+=10
```

Old array

```
2 3 5 7 1
```

New array

```
2 3 15 7 1
```

Every prefix after index 3 changes.

```
Old Prefix

2 5 10 17 18

↓

New Prefix

2 5 20 27 28
```

Need to update

```
prefix[3]

prefix[4]

prefix[5]

...

prefix[N]
```

Complexity

```
O(N)
```

---

# Segment Tree

Segment Tree solves both operations.

```
Update

O(logN)

Query

O(logN)
```

But

- More code
- More memory
- Harder to implement

---

# Fenwick Tree

Fenwick Tree also supports

```
Point Update

O(logN)

Prefix Query

O(logN)
```

using

```
Only N memory
```

and

```
Very small code
```

---

# Core Idea

Fenwick Tree **does NOT store every prefix sum.**

Instead, every node stores the sum of **a specific block**.

Example

Array

```
Index

1 2 3 4 5 6 7 8

Value

2 3 5 7 1 6 4 8
```

Fenwick stores

```
BIT[1]

2


BIT[2]

2+3


BIT[3]

5


BIT[4]

2+3+5+7


BIT[5]

1


BIT[6]

1+6


BIT[7]

4


BIT[8]

2+3+5+7+1+6+4+8
```

Notice

Every node stores a block whose size is a power of two.

---

# Visualization

<img width="406" height="320" alt="image" src="https://github.com/user-attachments/assets/86e53e85-5371-4082-900e-5d238a382fda" />


---

# Query Path

Suppose

```
Query(13)
```

Binary

```
13

1101
```

Remove one lowbit each time.

```
13

↓

12

↓

8

↓

0
```

Visited nodes

```
BIT[13]

+

BIT[12]

+

BIT[8]
```

---

# Update Path

Suppose

```
Update index 5
```

Binary

```
5

0101
```

Add lowbit each time.

```
5

↓

6

↓

8

↓

16

...
```

Reason

Every interval containing index 5 must be updated.

---

# Summary

Fenwick Tree stores

```
Partial sums
```

NOT

```
Entire prefix sums
```

Each node stores

```
Largest power-of-two block ending at that index.
```

---

# Operations

| Operation | Complexity |
|-----------|------------|
| Point Update | O(logN) |
| Prefix Query | O(logN) |
| Range Query | O(logN) |
| Memory | O(N) |
