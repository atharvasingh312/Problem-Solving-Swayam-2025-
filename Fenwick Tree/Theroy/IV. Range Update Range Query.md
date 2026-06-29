# Fenwick Tree (Binary Indexed Tree) - Part 4: Range Update + Range Query (1-Based Indexing)

---

# Problem Statement

Support the following operations efficiently:

```
1. Add x to every element in [l,r]

2. Find Sum(l,r)
```

Goal

| Operation | Complexity |
|-----------|------------|
| Range Update | O(logN) |
| Range Query | O(logN) |

---

# Why Isn't One BIT Enough?

In **Pattern 2**, the Fenwick Tree stores the **Difference Array**.

```
query(i)

↓

ΣD

↓

A[i]
```

It can recover **one element** of the original array.

But for a range query, we need

```
Prefix(i)

=

A1+A2+...+Ai
```

So one BIT is no longer sufficient.

---

# Derivation

We know

```
A1 = D1

A2 = D1+D2

A3 = D1+D2+D3

...
```

Therefore

```
Prefix(3)

=

A1+A2+A3

=

D1

+

(D1+D2)

+

(D1+D2+D3)
```

Collect terms

```
3D1

+

2D2

+

1D3
```

Generalizing,

```
Prefix(i)

=

i·D1

+

(i-1)·D2

+

(i-2)·D3

...

+

1·Di
```

The coefficient of `Dj` is

```
(i-j+1)
```

Rewrite it as

```
(i-j+1)

=

i-(j-1)
```

Now distribute

```
Prefix(i)

=

Σ(i-(j-1))Dj

=

iΣD

-

Σ((j-1)Dj)
```

This is the key observation.

To compute the prefix sum, we need two quantities:

```
ΣD
```

and

```
Σ((j-1)D)
```

---

# What Do We Store?

## BIT1

Stores

```
Difference Array
```

```
D
```

---

## BIT2

Stores

```
(index-1) × Difference Array
```

```
(index-1) × D
```

Both are just **normal Fenwick Trees**.

---

# Range Update

Suppose

```
[l,r] += x
```

Difference array changes as

```
D[l] += x

D[r+1] -= x
```

---

## Update BIT1

```cpp
update(bit1,l,+x);
update(bit1,r+1,-x);
```

---

## Update BIT2

Since BIT2 stores

```
(index-1) × D
```

Update

```cpp
update(bit2,l,+x*(l-1));
update(bit2,r+1,-x*r);
```

Notice

```
(r+1-1)=r
```

Hence

```
-x*r
```

---

# Prefix Query

From the derivation,

```
Prefix(i)

=

iΣD

-

Σ((index-1)D)
```

Fenwick computes both prefix sums.

Therefore

```cpp
long long prefixQuery(int idx)
{
    return query(bit1,idx)*idx-query(bit2,idx);
}
```

---

# Range Query

```
Sum(l,r)

=

Prefix(r)

-

Prefix(l-1)
```

```cpp
long long rangeQuery(int l,int r)
{
    return prefixQuery(r)-prefixQuery(l-1);
}
```

---

# Complete Implementation

```cpp
class Fenwick
{
public:

    int n;
    vector<long long> bit1,bit2;

    Fenwick(int size)
    {
        n=size;
        bit1.assign(n+1,0);
        bit2.assign(n+1,0);
    }

    void update(vector<long long>& bit,int idx,long long val)
    {
        while(idx<=n)
        {
            bit[idx]+=val;
            idx+=idx&-idx;
        }
    }

    long long query(vector<long long>& bit,int idx)
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
        update(bit1,l,val);
        update(bit1,r+1,-val);

        update(bit2,l,val*(l-1));
        update(bit2,r+1,-val*r);
    }

    long long prefixQuery(int idx)
    {
        return query(bit1,idx)*idx-query(bit2,idx);
    }

    long long rangeQuery(int l,int r)
    {
        return prefixQuery(r)-prefixQuery(l-1);
    }
};
```

---

# Formula Sheet

## Store

```
BIT1

↓

Difference Array
```

```
BIT2

↓

(index-1) × Difference Array
```

---

## Range Update

```cpp
update(bit1,l,+x);
update(bit1,r+1,-x);

update(bit2,l,+x*(l-1));
update(bit2,r+1,-x*r);
```

---

## Prefix Query

```cpp
prefix(i)

=

query(bit1,i)*i

-

query(bit2,i)
```

---

## Range Query

```cpp
range(l,r)

=

prefix(r)

-

prefix(l-1)
```

---

# Visualization

```
Original Array

↓

Difference Array

↓

BIT1
```

```
Difference Array

↓

Multiply every value by

(index-1)

↓

BIT2
```

```
Need

Prefix(i)

↓

i × ΣD

-

Σ((index-1) × D)
```

---

# Complexity

| Operation | Complexity |
|-----------|------------|
| Range Update | O(logN) |
| Prefix Query | O(logN) |
| Range Query | O(logN) |
| Memory | O(2N) |

---

# Fenwick Tree Patterns Summary

| Pattern | Stored Array | Update | Query |
|---------|--------------|--------|-------|
| Pattern 1 | Original Array | Point Update | Range Sum |
| Pattern 2 | Difference Array | Range Update | Point Query |
| Pattern 3 | Difference Array + (index-1)×Difference Array | Range Update | Range Sum |

---

# Final Takeaway

The **Fenwick Tree algorithm never changes**.

Only **what we choose to store** changes.

```
Need Point Update + Range Query

↓

Store Original Array

↓

1 BIT
```

```
Need Range Update + Point Query

↓

Store Difference Array

↓

1 BIT
```

```
Need Range Update + Range Query

↓

Store Difference Array

+

(index-1) × Difference Array

↓

2 BITs
```

> **Think of a Fenwick Tree as a data structure that efficiently computes prefix sums on whatever array you decide to store.**
