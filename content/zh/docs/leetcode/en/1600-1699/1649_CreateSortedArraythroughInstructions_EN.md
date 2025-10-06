---
title: "1649_CreateSortedArraythroughInstructions"
date: 2025-10-06T00:42:37+08:00
weight: 1649
tags: [Binary Indexed Tree, Segment Tree, Array, Binary Search, Divide and Conquer, Ordered Set, Merge Sort]
---


{{< katex />}}

{{< badge title="Difficulty" value="Hard" >}}

<!-- problem:start -->

# [1649. Create Sorted Array through Instructions](https://leetcode.com/problems/create-sorted-array-through-instructions)

[中文文档](/solution/1600-1699/1649.Create%20Sorted%20Array%20through%20Instructions/README.md)

## Description

<!-- description:start -->

<p>Given an integer array <code>instructions</code>, you are asked to create a sorted array from the elements in <code>instructions</code>. You start with an empty container <code>nums</code>. For each element from <strong>left to right</strong> in <code>instructions</code>, insert it into <code>nums</code>. The <strong>cost</strong> of each insertion is the <b>minimum</b> of the following:</p>

<ul>

    <li>The number of elements currently in <code>nums</code> that are <strong>strictly less than</strong> <code>instructions[i]</code>.</li>

    <li>The number of elements currently in <code>nums</code> that are <strong>strictly greater than</strong> <code>instructions[i]</code>.</li>

</ul>

<p>For example, if inserting element <code>3</code> into <code>nums = [1,2,3,5]</code>, the <strong>cost</strong> of insertion is <code>min(2, 1)</code> (elements <code>1</code> and <code>2</code> are less than <code>3</code>, element <code>5</code> is greater than <code>3</code>) and <code>nums</code> will become <code>[1,2,3,3,5]</code>.</p>

<p>Return <em>the <strong>total cost</strong> to insert all elements from </em><code>instructions</code><em> into </em><code>nums</code>. Since the answer may be large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code></p>

<p>&nbsp;</p>

<p><strong class="example">Example 1:</strong></p>

<pre>

<strong>Input:</strong> instructions = [1,5,6,2]

<strong>Output:</strong> 1

<strong>Explanation:</strong> Begin with nums = [].

Insert 1 with cost min(0, 0) = 0, now nums = [1].

Insert 5 with cost min(1, 0) = 0, now nums = [1,5].

Insert 6 with cost min(2, 0) = 0, now nums = [1,5,6].

Insert 2 with cost min(1, 2) = 1, now nums = [1,2,5,6].

The total cost is 0 + 0 + 0 + 1 = 1.</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>

<strong>Input:</strong> instructions = [1,2,3,6,5,4]

<strong>Output:</strong> 3

<strong>Explanation:</strong> Begin with nums = [].

Insert 1 with cost min(0, 0) = 0, now nums = [1].

Insert 2 with cost min(1, 0) = 0, now nums = [1,2].

Insert 3 with cost min(2, 0) = 0, now nums = [1,2,3].

Insert 6 with cost min(3, 0) = 0, now nums = [1,2,3,6].

Insert 5 with cost min(3, 1) = 1, now nums = [1,2,3,5,6].

Insert 4 with cost min(3, 2) = 2, now nums = [1,2,3,4,5,6].

The total cost is 0 + 0 + 0 + 0 + 1 + 2 = 3.

</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>

<strong>Input:</strong> instructions = [1,3,3,3,2,4,2,1,2]

<strong>Output:</strong> 4

<strong>Explanation:</strong> Begin with nums = [].

Insert 1 with cost min(0, 0) = 0, now nums = [1].

Insert 3 with cost min(1, 0) = 0, now nums = [1,3].

Insert 3 with cost min(1, 0) = 0, now nums = [1,3,3].

Insert 3 with cost min(1, 0) = 0, now nums = [1,3,3,3].

Insert 2 with cost min(1, 3) = 1, now nums = [1,2,3,3,3].

Insert 4 with cost min(5, 0) = 0, now nums = [1,2,3,3,3,4].

​​​​​​​Insert 2 with cost min(1, 4) = 1, now nums = [1,2,2,3,3,3,4].

​​​​​​​Insert 1 with cost min(0, 6) = 0, now nums = [1,1,2,2,3,3,3,4].

​​​​​​​Insert 2 with cost min(2, 4) = 2, now nums = [1,1,2,2,2,3,3,3,4].

The total cost is 0 + 0 + 0 + 0 + 1 + 0 + 1 + 0 + 2 = 4.

</pre>

<p>&nbsp;</p>

<p><strong>Constraints:</strong></p>

<ul>

    <li><code>1 &lt;= instructions.length &lt;= 10<sup>5</sup></code></li>

    <li><code>1 &lt;= instructions[i] &lt;= 10<sup>5</sup></code></li>

</ul>

<!-- description:end -->

## Solutions

<!-- solution:start -->

### Solution 1

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### Solution 2

<!-- tabs:start -->

#### Python3



#### Java



#### C++



<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->

{{< tabs id >}}
{{% tab "python" %}}
```python
class Node:
    def __init__(self):
        self.l = 0
        self.r = 0
        self.v = 0


class SegmentTree:
    def __init__(self, n):
        self.tr = [Node() for _ in range(4 * n)]
        self.build(1, 1, n)

    def build(self, u, l, r):
        self.tr[u].l = l
        self.tr[u].r = r
        if l == r:
            return
        mid = (l + r) >> 1
        self.build(u << 1, l, mid)
        self.build(u << 1 | 1, mid + 1, r)

    def modify(self, u, x, v):
        if self.tr[u].l == x and self.tr[u].r == x:
            self.tr[u].v += v
            return
        mid = (self.tr[u].l + self.tr[u].r) >> 1
        if x <= mid:
            self.modify(u << 1, x, v)
        else:
            self.modify(u << 1 | 1, x, v)
        self.pushup(u)

    def pushup(self, u):
        self.tr[u].v = self.tr[u << 1].v + self.tr[u << 1 | 1].v

    def query(self, u, l, r):
        if self.tr[u].l >= l and self.tr[u].r <= r:
            return self.tr[u].v
        mid = (self.tr[u].l + self.tr[u].r) >> 1
        v = 0
        if l <= mid:
            v = self.query(u << 1, l, r)
        if r > mid:
            v += self.query(u << 1 | 1, l, r)
        return v


class Solution:
    def createSortedArray(self, instructions: List[int]) -> int:
        n = max(instructions)
        tree = SegmentTree(n)
        ans = 0
        for num in instructions:
            a = tree.query(1, 1, num - 1)
            b = tree.query(1, 1, n) - tree.query(1, 1, num)
            ans += min(a, b)
            tree.modify(1, num, 1)
        return ans % int((1e9 + 7))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int createSortedArray(int[] instructions) {
        int n = 100010;
        int mod = (int) 1e9 + 7;
        SegmentTree tree = new SegmentTree(n);
        int ans = 0;
        for (int num : instructions) {
            int a = tree.query(1, 1, num - 1);
            int b = tree.query(1, 1, n) - tree.query(1, 1, num);
            ans += Math.min(a, b);
            ans %= mod;
            tree.modify(1, num, 1);
        }
        return ans;
    }
}

class Node {
    int l;
    int r;
    int v;
}

class SegmentTree {
    private Node[] tr;

    public SegmentTree(int n) {
        tr = new Node[4 * n];
        for (int i = 0; i < tr.length; ++i) {
            tr[i] = new Node();
        }
        build(1, 1, n);
    }

    public void build(int u, int l, int r) {
        tr[u].l = l;
        tr[u].r = r;
        if (l == r) {
            return;
        }
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
    }

    public void modify(int u, int x, int v) {
        if (tr[u].l == x && tr[u].r == x) {
            tr[u].v += v;
            return;
        }
        int mid = (tr[u].l + tr[u].r) >> 1;
        if (x <= mid) {
            modify(u << 1, x, v);
        } else {
            modify(u << 1 | 1, x, v);
        }
        pushup(u);
    }

    public void pushup(int u) {
        tr[u].v = tr[u << 1].v + tr[u << 1 | 1].v;
    }

    public int query(int u, int l, int r) {
        if (tr[u].l >= l && tr[u].r <= r) {
            return tr[u].v;
        }
        int mid = (tr[u].l + tr[u].r) >> 1;
        int v = 0;
        if (l <= mid) {
            v += query(u << 1, l, r);
        }
        if (r > mid) {
            v += query(u << 1 | 1, l, r);
        }
        return v;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Node {
public:
    int l;
    int r;
    int v;
};

class SegmentTree {
public:
    vector<Node*> tr;

    SegmentTree(int n) {
        tr.resize(4 * n);
        for (int i = 0; i < tr.size(); ++i) tr[i] = new Node();
        build(1, 1, n);
    }

    void build(int u, int l, int r) {
        tr[u]->l = l;
        tr[u]->r = r;
        if (l == r) return;
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
    }

    void modify(int u, int x, int v) {
        if (tr[u]->l == x && tr[u]->r == x) {
            tr[u]->v += v;
            return;
        }
        int mid = (tr[u]->l + tr[u]->r) >> 1;
        if (x <= mid)
            modify(u << 1, x, v);
        else
            modify(u << 1 | 1, x, v);
        pushup(u);
    }

    void pushup(int u) {
        tr[u]->v = tr[u << 1]->v + tr[u << 1 | 1]->v;
    }

    int query(int u, int l, int r) {
        if (tr[u]->l >= l && tr[u]->r <= r) return tr[u]->v;
        int mid = (tr[u]->l + tr[u]->r) >> 1;
        int v = 0;
        if (l <= mid) v = query(u << 1, l, r);
        if (r > mid) v += query(u << 1 | 1, l, r);
        return v;
    }
};

class Solution {
public:
    int createSortedArray(vector<int>& instructions) {
        int n = *max_element(instructions.begin(), instructions.end());
        int mod = 1e9 + 7;
        SegmentTree* tree = new SegmentTree(n);
        int ans = 0;
        for (int num : instructions) {
            int a = tree->query(1, 1, num - 1);
            int b = tree->query(1, 1, n) - tree->query(1, 1, num);
            ans += min(a, b);
            ans %= mod;
            tree->modify(1, num, 1);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
type BinaryIndexedTree struct {
	n int
	c []int
}

func newBinaryIndexedTree(n int) *BinaryIndexedTree {
	c := make([]int, n+1)
	return &BinaryIndexedTree{n, c}
}

func (this *BinaryIndexedTree) update(x, delta int) {
	for x <= this.n {
		this.c[x] += delta
		x += x & -x
	}
}

func (this *BinaryIndexedTree) query(x int) int {
	s := 0
	for x > 0 {
		s += this.c[x]
		x -= x & -x
	}
	return s
}

func createSortedArray(instructions []int) (ans int) {
	m := slices.Max(instructions)
	tree := newBinaryIndexedTree(m)
	const mod = 1e9 + 7
	for i, x := range instructions {
		cost := min(tree.query(x-1), i-tree.query(x))
		ans = (ans + cost) % mod
		tree.update(x, 1)
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class BinaryIndexedTree {
    private n: number;
    private c: number[];

    constructor(n: number) {
        this.n = n;
        this.c = new Array(n + 1).fill(0);
    }

    public update(x: number, v: number): void {
        while (x <= this.n) {
            this.c[x] += v;
            x += x & -x;
        }
    }

    public query(x: number): number {
        let s = 0;
        while (x > 0) {
            s += this.c[x];
            x -= x & -x;
        }
        return s;
    }
}

function createSortedArray(instructions: number[]): number {
    const m = Math.max(...instructions);
    const tree = new BinaryIndexedTree(m);
    let ans = 0;
    const mod = 10 ** 9 + 7;
    for (let i = 0; i < instructions.length; ++i) {
        const x = instructions[i];
        const cost = Math.min(tree.query(x - 1), i - tree.query(x));
        ans = (ans + cost) % mod;
        tree.update(x, 1);
    }
    return ans;
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Node:
    def __init__(self):
        self.l = 0
        self.r = 0
        self.v = 0


class SegmentTree:
    def __init__(self, n):
        self.tr = [Node() for _ in range(4 * n)]
        self.build(1, 1, n)

    def build(self, u, l, r):
        self.tr[u].l = l
        self.tr[u].r = r
        if l == r:
            return
        mid = (l + r) >> 1
        self.build(u << 1, l, mid)
        self.build(u << 1 | 1, mid + 1, r)

    def modify(self, u, x, v):
        if self.tr[u].l == x and self.tr[u].r == x:
            self.tr[u].v += v
            return
        mid = (self.tr[u].l + self.tr[u].r) >> 1
        if x <= mid:
            self.modify(u << 1, x, v)
        else:
            self.modify(u << 1 | 1, x, v)
        self.pushup(u)

    def pushup(self, u):
        self.tr[u].v = self.tr[u << 1].v + self.tr[u << 1 | 1].v

    def query(self, u, l, r):
        if self.tr[u].l >= l and self.tr[u].r <= r:
            return self.tr[u].v
        mid = (self.tr[u].l + self.tr[u].r) >> 1
        v = 0
        if l <= mid:
            v = self.query(u << 1, l, r)
        if r > mid:
            v += self.query(u << 1 | 1, l, r)
        return v


class Solution:
    def createSortedArray(self, instructions: List[int]) -> int:
        n = max(instructions)
        tree = SegmentTree(n)
        ans = 0
        for num in instructions:
            a = tree.query(1, 1, num - 1)
            b = tree.query(1, 1, n) - tree.query(1, 1, num)
            ans += min(a, b)
            tree.modify(1, num, 1)
        return ans % int((1e9 + 7))
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public int createSortedArray(int[] instructions) {
        int n = 100010;
        int mod = (int) 1e9 + 7;
        SegmentTree tree = new SegmentTree(n);
        int ans = 0;
        for (int num : instructions) {
            int a = tree.query(1, 1, num - 1);
            int b = tree.query(1, 1, n) - tree.query(1, 1, num);
            ans += Math.min(a, b);
            ans %= mod;
            tree.modify(1, num, 1);
        }
        return ans;
    }
}

class Node {
    int l;
    int r;
    int v;
}

class SegmentTree {
    private Node[] tr;

    public SegmentTree(int n) {
        tr = new Node[4 * n];
        for (int i = 0; i < tr.length; ++i) {
            tr[i] = new Node();
        }
        build(1, 1, n);
    }

    public void build(int u, int l, int r) {
        tr[u].l = l;
        tr[u].r = r;
        if (l == r) {
            return;
        }
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
    }

    public void modify(int u, int x, int v) {
        if (tr[u].l == x && tr[u].r == x) {
            tr[u].v += v;
            return;
        }
        int mid = (tr[u].l + tr[u].r) >> 1;
        if (x <= mid) {
            modify(u << 1, x, v);
        } else {
            modify(u << 1 | 1, x, v);
        }
        pushup(u);
    }

    public void pushup(int u) {
        tr[u].v = tr[u << 1].v + tr[u << 1 | 1].v;
    }

    public int query(int u, int l, int r) {
        if (tr[u].l >= l && tr[u].r <= r) {
            return tr[u].v;
        }
        int mid = (tr[u].l + tr[u].r) >> 1;
        int v = 0;
        if (l <= mid) {
            v += query(u << 1, l, r);
        }
        if (r > mid) {
            v += query(u << 1 | 1, l, r);
        }
        return v;
    }
}
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "cpp 可视化" %}}
{{< pythontutor width="100%" height="800" language="cpp" >}}
class Node {
public:
    int l;
    int r;
    int v;
};

class SegmentTree {
public:
    vector<Node*> tr;

    SegmentTree(int n) {
        tr.resize(4 * n);
        for (int i = 0; i < tr.size(); ++i) tr[i] = new Node();
        build(1, 1, n);
    }

    void build(int u, int l, int r) {
        tr[u]->l = l;
        tr[u]->r = r;
        if (l == r) return;
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
    }

    void modify(int u, int x, int v) {
        if (tr[u]->l == x && tr[u]->r == x) {
            tr[u]->v += v;
            return;
        }
        int mid = (tr[u]->l + tr[u]->r) >> 1;
        if (x <= mid)
            modify(u << 1, x, v);
        else
            modify(u << 1 | 1, x, v);
        pushup(u);
    }

    void pushup(int u) {
        tr[u]->v = tr[u << 1]->v + tr[u << 1 | 1]->v;
    }

    int query(int u, int l, int r) {
        if (tr[u]->l >= l && tr[u]->r <= r) return tr[u]->v;
        int mid = (tr[u]->l + tr[u]->r) >> 1;
        int v = 0;
        if (l <= mid) v = query(u << 1, l, r);
        if (r > mid) v += query(u << 1 | 1, l, r);
        return v;
    }
};

class Solution {
public:
    int createSortedArray(vector<int>& instructions) {
        int n = *max_element(instructions.begin(), instructions.end());
        int mod = 1e9 + 7;
        SegmentTree* tree = new SegmentTree(n);
        int ans = 0;
        for (int num : instructions) {
            int a = tree->query(1, 1, num - 1);
            int b = tree->query(1, 1, n) - tree->query(1, 1, num);
            ans += min(a, b);
            ans %= mod;
            tree->modify(1, num, 1);
        }
        return ans;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}