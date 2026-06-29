# Fenwick Tree (Binary Indexed Tree) - Part 3: Range Update + Point Query

---

# Problem Statement

Support the following operations efficiently:

```
1. Add x to every element in [l,r]

2. Query A[i]
```

Goal

| Operation | Complexity |
|-----------|------------|
| Range Update | O(logN) |
| Point Query | O(logN) |

---

# Key Idea

A normal Fenwick Tree supports

```
Point Update

↓

Prefix Sum Query
```

A range update changes many elements.

```
+5 on [2,5]

↓

0 5 5 5 5 0
```

Updating every element individually is

```
O(NlogN)
```

Too slow.

---

# Difference Array

Instead of storing the original array, store the **Difference Array**.

Definition

```
D[1] = A[1]

D[i] = A[i] - A[i-1]
```

Example

```
A

2 3 5 7
```

Difference Array

```
D

2 1 2 2
```

---

# Why Difference Array?

Suppose

```
Add +5 to [2,5]
```

Original Array changes

```
0 5 5 5 5 0
```

Four elements changed.

Difference Array changes

```
Before

0 0 0 0 0 0
```

```
After

0 5 0 0 0 -5
```

Only **2 positions** changed.

Specifically,

```
D[l] += x

D[r+1] -= x
```

Hence

```
One Range Update

↓

Two Point Updates
```

Exactly what a Fenwick Tree is good at!

---

# What Does the Fenwick Tree Store?

```
Fenwick Tree

↓

Difference Array
```

NOT

```
Original Array
```

---

# Building from an Existing Array

If the initial array is

```
A

2 3 5 7
```

First compute

```
D

2 1 2 2
```

Then build a **normal Fenwick Tree** on `D`.

```cpp
for(int i=1;i<=n;i++)
    update(i,D[i]);
```

---

# Range Update

To add

```
x

to

[l,r]
```

Update only two positions.

```cpp
update(l,x);
update(r+1,-x);
```

---

# Why Does Point Query Work?

Remember

```
A[i]

=

D[1]+D[2]+...+D[i]
```

Fenwick computes

```
Prefix Sum of D
```

Therefore

```
query(i)

=

A[i]
```

---

# Visualization

Suppose

```
Add +5 to [2,4]
```

Difference Array

```
0 5 0 0 -5
```

Query

```
A[1]

=

0
```

Query

```
A[2]

=

0+5

=

5
```

Query

```
A[3]

=

0+5+0

=

5
```

Query

```
A[4]

=

0+5+0+0

=

5
```

Query

```
A[5]

=

0+5+0+0-5

=

0
```

The `-5` cancels the update after index `r`.

---

# Code

```cpp
class Fenwick
{
public:

    int n;
    vector<long long> bit;

    Fenwick(int size)
    {
        n=size;
        bit.assign(n+1,0);
    }

    void update(int idx,long long val)
    {
        while(idx<=n)
        {
            bit[idx]+=val;
            idx+=idx&-idx;
        }
    }

    long long query(int idx)
    {
        long long ans=0;

        while(idx>0)
        {
            ans+=bit[idx];
            idx-=idx&-idx;
        }

        return ans;
    }

    void rangeUpdate(int l,int r,long long val)
    {
        update(l,val);
        update(r+1,-val);
    }

    long long pointQuery(int idx)
    {
        return query(idx);
    }
};
```

---

# Summary

```
Store

↓

Difference Array
```

```
Range Update

↓

2 Point Updates
```

```
Point Query

↓

Prefix Sum of Difference Array
```

---

# Formula

Difference Array

```
D[l] += x

D[r+1] -= x
```

Point Query

```
A[i]

=

ΣD
```

---

# Complexity

| Operation | Complexity |
|-----------|------------|
| Range Update | O(logN) |
| Point Query | O(logN) |
| Memory | O(N) |

---

# Pattern Comparison

| Pattern | Stored Array | Update | Query |
|---------|--------------|--------|-------|
| Normal Fenwick | Original Array | Point | Range Sum |
| This Pattern | Difference Array | Range | Point |

---

# Key Takeaways

✅ We changed **what the Fenwick Tree stores**, not the Fenwick algorithm.

✅ A range update on the original array becomes **two point updates** on the difference array.

✅ Prefix sum of the difference array reconstructs the original array.

```
query(i)

↓

ΣD

↓

A[i]
```

---

# Practice Problems

### Easy

- SPOJ - UPDATEIT

### Medium

- CSES - Range Update Queries

### Advanced

- Any problem with:
  - Range additions
  - Point value queries
```
