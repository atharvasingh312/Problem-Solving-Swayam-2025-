# Fenwick Tree (Binary Indexed Tree) - Part 2: Normal Fenwick Tree (Point Update + Range Query)

---

# Problem Statement

We want to efficiently support two operations on an array.

```
1. Point Update

A[i] += x
```

```
2. Range Sum Query

sum(l,r)
```

A Fenwick Tree solves both in

```
O(logN)
```

---

# What Does the Fenwick Tree Store?

Unlike a Prefix Sum Array, a Fenwick Tree **does not store every prefix sum**.

It stores **partial sums (blocks).**

Consider

```
Index

1  2  3  4  5  6  7  8

Value

2  3  5  7  1  6  4  8
```

Fenwick stores

```
BIT[1] = 2

BIT[2] = 2+3

BIT[3] = 5

BIT[4] = 2+3+5+7

BIT[5] = 1

BIT[6] = 1+6

BIT[7] = 4

BIT[8] = 2+3+5+7+1+6+4+8
```

Graphically

<img width="406" height="320" alt="image" src="https://github.com/user-attachments/assets/b9fdc06a-4b19-4b79-a43a-56c0082cea35" />

Every node stores

> **Largest power-of-two sized block ending at that index.**

---

# Query Code

```cpp
int query(int idx)
{
    int sum = 0;

    while(idx > 0)
    {
        sum += bit[idx];
        idx -= (idx & -idx);
    }

    return sum;
}
```

---

# Range Query

Once prefix sums are available,

```
sum(l,r)

=

Prefix(r)-Prefix(l-1)
```

Code

```cpp
int rangeQuery(int l,int r)
{
    return query(r)-query(l-1);
}
```

---

# Update Code

```cpp
void update(int idx,int val)
{
    while(idx <= n)
    {
        bit[idx] += val;
        idx += (idx & -idx);
    }
}
```

---

# Complete Fenwick Tree

```cpp
class FenwickTree
{
public:

    int n;
    vector<long long> bit;

    FenwickTree(int size)
    {
        n = size;
        bit.assign(n + 1, 0);
    }

    void update(int idx,long long val)
    {
        while(idx <= n)
        {
            bit[idx] += val;
            idx += (idx & -idx);
        }
    }

    long long query(int idx)
    {
        long long sum = 0;

        while(idx > 0)
        {
            sum += bit[idx];
            idx -= (idx & -idx);
        }

        return sum;
    }

    long long rangeQuery(int l,int r)
    {
        return query(r)-query(l-1);
    }
};
```

---

# Building the Tree

## Method 1 (Most Common)

Simply insert every element.

```cpp
for(int i=1;i<=n;i++)
    update(i,A[i]);
```

Complexity

```
O(NlogN)
```

---

## Method 2 (Linear Build)

Less common but useful.

```cpp
for(int i=1;i<=n;i++)
{
    bit[i]+=A[i];

    int j=i+(i&-i);

    if(j<=n)
        bit[j]+=bit[i];
}
```

Complexity

```
O(N)
```

---

# Dry Run

Array

```
2 3 5 7
```

Initially

```
BIT

0 0 0 0
```

Insert 2

```
update(1,2)

↓

BIT

2 2 0 2
```

Insert 3

```
update(2,3)

↓

BIT

2 5 0 5
```

Insert 5

```
update(3,5)

↓

BIT

2 5 5 10
```

Insert 7

```
update(4,7)

↓

BIT

2 5 5 17
```

Final

```
BIT

2 5 5 17
```

Notice

This is **NOT** the original array.

Nor is it the prefix sum array.

It is Fenwick's internal representation.

---

# Common Mistakes

### Forgetting 1-based indexing

Fenwick Tree is much simpler with

```
1-based indexing.
```

---

### Thinking BIT stores Prefix Sums

Wrong.

It stores

```
Partial Sums.
```

---

### Forgetting

```
range(l,r)

=

query(r)-query(l-1)
```

---

### Mixing Update and Query Directions

Update

```
+

lowbit
```

Query

```
-

lowbit
```

Remember

```
Update

Move UP the tree.
```

```
Query

Move DOWN the tree.
```

---

# Complexity

| Operation | Complexity |
|-----------|------------|
| Point Update | O(logN) |
| Prefix Query | O(logN) |
| Range Query | O(logN) |
| Build | O(NlogN) |
| Linear Build | O(N) |
| Memory | O(N) |

---

# Practice Problems

## Easy

1. LeetCode 307 - Range Sum Query - Mutable
2. CSES - Dynamic Range Sum Queries

---

## Medium

3. SPOJ - MATSUM
4. LightOJ 1112 - Curious Robin Hood

---

## Advanced (Classic BIT)

5. LeetCode 315 - Count of Smaller Numbers After Self
6. LeetCode 493 - Reverse Pairs
7. LeetCode 1649 - Create Sorted Array through Instructions

---

# Key Takeaways

✅ Fenwick Tree stores **partial sums**, not complete prefix sums.

✅ Query moves **backward** by removing the least significant set bit.

```
idx -= (idx & -idx)
```

✅ Update moves **forward** by adding the least significant set bit.

```
idx += (idx & -idx)
```

✅ Range queries are simply

```
query(r)-query(l-1)
```

In the next part, we'll **change what the Fenwick Tree stores**. Instead of storing the original array, we'll store the **Difference Array**, allowing us to support **Range Update + Point Query** without changing the Fenwick Tree implementation.
