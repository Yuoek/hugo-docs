---
title: "0370_区间加法 🔒"
date: 2025-10-08T18:35:54+08:00
weight: 8
tags: [二分查找, 交互, 位运算, 分治, 前缀和, 动态规划, 博弈, 哈希表, 堆（优先队列）, 排序, 数学, 数组, 矩阵, 设计, 贪心, 链表, 队列]
---

{{< markmap >}}
### [0370_区间加法 🔒](#370)
#### [数组](#370)
#### [前缀和](#370)
### [0371_两整数之和](#371)
#### [位运算](#371)
#### [数学](#371)
### [0372_超级次方](#372)
#### [数学](#372)
#### [分治](#372)
### [0373_查找和最小的 K 对数字](#373)
#### [数组](#373)
#### [堆（优先队列）](#373)
### [0374_猜数字大小](#374)
#### [二分查找](#374)
#### [交互](#374)
### [0375_猜数字大小 II](#375)
#### [数学](#375)
#### [动态规划](#375)
#### [博弈](#375)
### [0376_摆动序列](#376)
#### [贪心](#376)
#### [数组](#376)
#### [动态规划](#376)
### [0377_组合总和 Ⅳ](#377)
#### [数组](#377)
#### [动态规划](#377)
### [0378_有序矩阵中第 K 小的元素](#378)
#### [数组](#378)
#### [二分查找](#378)
#### [矩阵](#378)
#### [排序](#378)
#### [堆（优先队列）](#378)
### [0379_电话目录管理系统 🔒](#379)
#### [设计](#379)
#### [队列](#379)
#### [数组](#379)
#### [哈希表](#379)
#### [链表](#379)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0370_区间加法 🔒
___
#### 数组
___
#### 前缀和
---
### 0371_两整数之和
___
#### 位运算
___
#### 数学
---
### 0372_超级次方
___
#### 数学
___
#### 分治
---
### 0373_查找和最小的 K 对数字
___
#### 数组
___
#### 堆（优先队列）
---
### 0374_猜数字大小
___
#### 二分查找
___
#### 交互
---
### 0375_猜数字大小 II
___
#### 数学
___
#### 动态规划
___
#### 博弈
---
### 0376_摆动序列
___
#### 贪心
___
#### 数组
___
#### 动态规划
---
### 0377_组合总和 Ⅳ
___
#### 数组
___
#### 动态规划
---
### 0378_有序矩阵中第 K 小的元素
___
#### 数组
___
#### 二分查找
___
#### 矩阵
___
#### 排序
___
#### 堆（优先队列）
---
### 0379_电话目录管理系统 🔒
___
#### 设计
___
#### 队列
___
#### 数组
___
#### 哈希表
___
#### 链表
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 交互 | 位运算 |
| 分治 | 前缀和 | 动态规划 |
| 博弈 | 哈希表 | 堆（优先队列） |
| 排序 | 数学 | 数组 |
| 矩阵 | 设计 | 贪心 |
| 链表 | 队列 |  |

# [370. 区间加法 🔒](https://leetcode.cn/problems/range-addition){#370}

{{< tabs "370" >}}

{{% tab "python" %}}
```python
class BinaryIndexedTree:
    __slots__ = "n", "c"

    def __init__(self, n: int):
        self.n = n
        self.c = [0] * (n + 1)

    def update(self, x: int, delta: int) -> None:
        while x <= self.n:
            self.c[x] += delta
            x += x & -x

    def query(self, x: int) -> int:
        s = 0
        while x:
            s += self.c[x]
            x -= x & -x
        return s


class Solution:
    def getModifiedArray(self, length: int, updates: List[List[int]]) -> List[int]:
        tree = BinaryIndexedTree(length)
        for l, r, c in updates:
            tree.update(l + 1, c)
            tree.update(r + 2, -c)
        return [tree.query(i + 1) for i in range(length)]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class BinaryIndexedTree {
    private int n;
    private int[] c;

    public BinaryIndexedTree(int n) {
        this.n = n;
        this.c = new int[n + 1];
    }

    public void update(int x, int delta) {
        for (; x <= n; x += x & -x) {
            c[x] += delta;
        }
    }

    public int query(int x) {
        int s = 0;
        for (; x > 0; x -= x & -x) {
            s += c[x];
        }
        return s;
    }
}

class Solution {
    public int[] getModifiedArray(int length, int[][] updates) {
        var tree = new BinaryIndexedTree(length);
        for (var e : updates) {
            int l = e[0], r = e[1], c = e[2];
            tree.update(l + 1, c);
            tree.update(r + 2, -c);
        }
        int[] ans = new int[length];
        for (int i = 0; i < length; ++i) {
            ans[i] = tree.query(i + 1);
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class BinaryIndexedTree {
private:
    int n;
    vector<int> c;

public:
    BinaryIndexedTree(int n)
        : n(n)
        , c(n + 1) {}

    void update(int x, int delta) {
        for (; x <= n; x += x & -x) {
            c[x] += delta;
        }
    }

    int query(int x) {
        int s = 0;
        for (; x > 0; x -= x & -x) {
            s += c[x];
        }
        return s;
    }
};

class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        BinaryIndexedTree* tree = new BinaryIndexedTree(length);
        for (const auto& e : updates) {
            int l = e[0], r = e[1], c = e[2];
            tree->update(l + 1, c);
            tree->update(r + 2, -c);
        }
        vector<int> ans;
        for (int i = 0; i < length; ++i) {
            ans.push_back(tree->query(i + 1));
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

func NewBinaryIndexedTree(n int) *BinaryIndexedTree {
	return &BinaryIndexedTree{n: n, c: make([]int, n+1)}
}

func (bit *BinaryIndexedTree) update(x, delta int) {
	for ; x <= bit.n; x += x & -x {
		bit.c[x] += delta
	}
}

func (bit *BinaryIndexedTree) query(x int) int {
	s := 0
	for ; x > 0; x -= x & -x {
		s += bit.c[x]
	}
	return s
}

func getModifiedArray(length int, updates [][]int) (ans []int) {
	bit := NewBinaryIndexedTree(length)
	for _, e := range updates {
		l, r, c := e[0], e[1], e[2]
		bit.update(l+1, c)
		bit.update(r+2, -c)
	}
	for i := 1; i <= length; i++ {
		ans = append(ans, bit.query(i))
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
        this.c = Array(n + 1).fill(0);
    }

    update(x: number, delta: number): void {
        for (; x <= this.n; x += x & -x) {
            this.c[x] += delta;
        }
    }

    query(x: number): number {
        let s = 0;
        for (; x > 0; x -= x & -x) {
            s += this.c[x];
        }
        return s;
    }
}

function getModifiedArray(length: number, updates: number[][]): number[] {
    const bit = new BinaryIndexedTree(length);
    for (const [l, r, c] of updates) {
        bit.update(l + 1, c);
        bit.update(r + 2, -c);
    }
    return Array.from({ length }, (_, i) => bit.query(i + 1));
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number} length
 * @param {number[][]} updates
 * @return {number[]}
 */
var getModifiedArray = function (length, updates) {
    class BinaryIndexedTree {
        constructor(n) {
            this.n = n;
            this.c = Array(n + 1).fill(0);
        }

        update(x, delta) {
            while (x <= this.n) {
                this.c[x] += delta;
                x += x & -x;
            }
        }

        query(x) {
            let s = 0;
            while (x > 0) {
                s += this.c[x];
                x -= x & -x;
            }
            return s;
        }
    }

    const bit = new BinaryIndexedTree(length);
    for (const [l, r, c] of updates) {
        bit.update(l + 1, c);
        bit.update(r + 2, -c);
    }
    return Array.from({ length }, (_, i) => bit.query(i + 1));
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>假设你有一个长度为&nbsp;<em><strong>n</strong></em>&nbsp;的数组，初始情况下所有的数字均为&nbsp;<strong>0</strong>，你将会被给出&nbsp;<em><strong>k</strong></em>​​​​​​<em>​</em> 个更新的操作。</p>

<p>其中，每个操作会被表示为一个三元组：<strong>[startIndex, endIndex, inc]</strong>，你需要将子数组&nbsp;<strong>A[startIndex ... endIndex]</strong>（包括 startIndex 和 endIndex）增加&nbsp;<strong>inc</strong>。</p>

<p>请你返回&nbsp;<strong><em>k</em></strong>&nbsp;次操作后的数组。</p>

<p><strong>示例:</strong></p>

<pre><strong>输入: </strong>length = 5, updates = [[1,3,2],[2,4,3],[0,2,-2]]
<strong>输出: </strong>[-2,0,3,5,3]
</pre>

<p><strong>解释:</strong></p>

<pre>初始状态:
[0,0,0,0,0]

进行了操作 [1,3,2] 后的状态:
[0,2,2,2,0]

进行了操作 [2,4,3] 后的状态:
[0,2,5,5,3]

进行了操作 [0,2,-2] 后的状态:
[-2,0,3,5,3]
</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：差分数组

差分数组模板题。

我们定义 $d$ 为差分数组。给区间 $[l,..r]$ 中的每一个数加上 $c$，那么有 $d[l] += c$，并且 $d[r+1] -= c$。最后我们对差分数组求前缀和，即可得到原数组。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def getModifiedArray(self, length: int, updates: List[List[int]]) -> List[int]:
        d = [0] * length
        for l, r, c in updates:
            d[l] += c
            if r + 1 < length:
                d[r + 1] -= c
        return list(accumulate(d))
```

#### Java

```java
class Solution {
    public int[] getModifiedArray(int length, int[][] updates) {
        int[] d = new int[length];
        for (var e : updates) {
            int l = e[0], r = e[1], c = e[2];
            d[l] += c;
            if (r + 1 < length) {
                d[r + 1] -= c;
            }
        }
        for (int i = 1; i < length; ++i) {
            d[i] += d[i - 1];
        }
        return d;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> d(length);
        for (const auto& e : updates) {
            int l = e[0], r = e[1], c = e[2];
            d[l] += c;
            if (r + 1 < length) {
                d[r + 1] -= c;
            }
        }
        for (int i = 1; i < length; ++i) {
            d[i] += d[i - 1];
        }
        return d;
    }
};
```

#### Go

```go
func getModifiedArray(length int, updates [][]int) []int {
	d := make([]int, length)
	for _, e := range updates {
		l, r, c := e[0], e[1], e[2]
		d[l] += c
		if r+1 < length {
			d[r+1] -= c
		}
	}
	for i := 1; i < length; i++ {
		d[i] += d[i-1]
	}
	return d
}
```

#### TypeScript

```ts
function getModifiedArray(length: number, updates: number[][]): number[] {
    const d: number[] = Array(length).fill(0);
    for (const [l, r, c] of updates) {
        d[l] += c;
        if (r + 1 < length) {
            d[r + 1] -= c;
        }
    }
    for (let i = 1; i < length; ++i) {
        d[i] += d[i - 1];
    }
    return d;
}
```

#### JavaScript

```js
/**
 * @param {number} length
 * @param {number[][]} updates
 * @return {number[]}
 */
var getModifiedArray = function (length, updates) {
    const d = Array(length).fill(0);
    for (const [l, r, c] of updates) {
        d[l] += c;
        if (r + 1 < length) {
            d[r + 1] -= c;
        }
    }
    for (let i = 1; i < length; ++i) {
        d[i] += d[i - 1];
    }
    return d;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：树状数组 + 差分思想

时间复杂度 $O(n\times \log n)$。

树状数组，也称作“二叉索引树”（Binary Indexed Tree）或 Fenwick 树。 它可以高效地实现如下两个操作：

1. **单点更新** `update(x, delta)`： 把序列 $x$ 位置的数加上一个值 $delta$；
1. **前缀和查询** `query(x)`：查询序列 $[1,...x]$ 区间的区间和，即位置 $x$ 的前缀和。

这两个操作的时间复杂度均为 $O(\log n)$。

<!-- tabs:start -->

#### Python3

```python
class BinaryIndexedTree:
    __slots__ = "n", "c"

    def __init__(self, n: int):
        self.n = n
        self.c = [0] * (n + 1)

    def update(self, x: int, delta: int) -> None:
        while x <= self.n:
            self.c[x] += delta
            x += x & -x

    def query(self, x: int) -> int:
        s = 0
        while x:
            s += self.c[x]
            x -= x & -x
        return s


class Solution:
    def getModifiedArray(self, length: int, updates: List[List[int]]) -> List[int]:
        tree = BinaryIndexedTree(length)
        for l, r, c in updates:
            tree.update(l + 1, c)
            tree.update(r + 2, -c)
        return [tree.query(i + 1) for i in range(length)]
```

#### Java

```java
class BinaryIndexedTree {
    private int n;
    private int[] c;

    public BinaryIndexedTree(int n) {
        this.n = n;
        this.c = new int[n + 1];
    }

    public void update(int x, int delta) {
        for (; x <= n; x += x & -x) {
            c[x] += delta;
        }
    }

    public int query(int x) {
        int s = 0;
        for (; x > 0; x -= x & -x) {
            s += c[x];
        }
        return s;
    }
}

class Solution {
    public int[] getModifiedArray(int length, int[][] updates) {
        var tree = new BinaryIndexedTree(length);
        for (var e : updates) {
            int l = e[0], r = e[1], c = e[2];
            tree.update(l + 1, c);
            tree.update(r + 2, -c);
        }
        int[] ans = new int[length];
        for (int i = 0; i < length; ++i) {
            ans[i] = tree.query(i + 1);
        }
        return ans;
    }
}
```

#### C++

```cpp
class BinaryIndexedTree {
private:
    int n;
    vector<int> c;

public:
    BinaryIndexedTree(int n)
        : n(n)
        , c(n + 1) {}

    void update(int x, int delta) {
        for (; x <= n; x += x & -x) {
            c[x] += delta;
        }
    }

    int query(int x) {
        int s = 0;
        for (; x > 0; x -= x & -x) {
            s += c[x];
        }
        return s;
    }
};

class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        BinaryIndexedTree* tree = new BinaryIndexedTree(length);
        for (const auto& e : updates) {
            int l = e[0], r = e[1], c = e[2];
            tree->update(l + 1, c);
            tree->update(r + 2, -c);
        }
        vector<int> ans;
        for (int i = 0; i < length; ++i) {
            ans.push_back(tree->query(i + 1));
        }
        return ans;
    }
};
```

#### Go

```go
type BinaryIndexedTree struct {
	n int
	c []int
}

func NewBinaryIndexedTree(n int) *BinaryIndexedTree {
	return &BinaryIndexedTree{n: n, c: make([]int, n+1)}
}

func (bit *BinaryIndexedTree) update(x, delta int) {
	for ; x <= bit.n; x += x & -x {
		bit.c[x] += delta
	}
}

func (bit *BinaryIndexedTree) query(x int) int {
	s := 0
	for ; x > 0; x -= x & -x {
		s += bit.c[x]
	}
	return s
}

func getModifiedArray(length int, updates [][]int) (ans []int) {
	bit := NewBinaryIndexedTree(length)
	for _, e := range updates {
		l, r, c := e[0], e[1], e[2]
		bit.update(l+1, c)
		bit.update(r+2, -c)
	}
	for i := 1; i <= length; i++ {
		ans = append(ans, bit.query(i))
	}
	return
}
```

#### TypeScript

```ts
class BinaryIndexedTree {
    private n: number;
    private c: number[];

    constructor(n: number) {
        this.n = n;
        this.c = Array(n + 1).fill(0);
    }

    update(x: number, delta: number): void {
        for (; x <= this.n; x += x & -x) {
            this.c[x] += delta;
        }
    }

    query(x: number): number {
        let s = 0;
        for (; x > 0; x -= x & -x) {
            s += this.c[x];
        }
        return s;
    }
}

function getModifiedArray(length: number, updates: number[][]): number[] {
    const bit = new BinaryIndexedTree(length);
    for (const [l, r, c] of updates) {
        bit.update(l + 1, c);
        bit.update(r + 2, -c);
    }
    return Array.from({ length }, (_, i) => bit.query(i + 1));
}
```

#### JavaScript

```js
/**
 * @param {number} length
 * @param {number[][]} updates
 * @return {number[]}
 */
var getModifiedArray = function (length, updates) {
    class BinaryIndexedTree {
        constructor(n) {
            this.n = n;
            this.c = Array(n + 1).fill(0);
        }

        update(x, delta) {
            while (x <= this.n) {
                this.c[x] += delta;
                x += x & -x;
            }
        }

        query(x) {
            let s = 0;
            while (x > 0) {
                s += this.c[x];
                x -= x & -x;
            }
            return s;
        }
    }

    const bit = new BinaryIndexedTree(length);
    for (const [l, r, c] of updates) {
        bit.update(l + 1, c);
        bit.update(r + 2, -c);
    }
    return Array.from({ length }, (_, i) => bit.query(i + 1));
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [371. 两整数之和](https://leetcode.cn/problems/sum-of-two-integers){#371}

{{< tabs "371" >}}

{{% tab "python" %}}
```python
class Solution:
    def getSum(self, a: int, b: int) -> int:
        a, b = a & 0xFFFFFFFF, b & 0xFFFFFFFF
        while b:
            carry = ((a & b) << 1) & 0xFFFFFFFF
            a, b = a ^ b, carry
        return a if a < 0x80000000 else ~(a ^ 0xFFFFFFFF)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int getSum(int a, int b) {
        return b == 0 ? a : getSum(a ^ b, (a & b) << 1);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int getSum(int a, int b) {
        while (b) {
            unsigned int carry = (unsigned int) (a & b) << 1;
            a = a ^ b;
            b = carry;
        }
        return a;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func getSum(a int, b int) int {
	for b != 0 {
		s := a ^ b
		b = (a & b) << 1
		a = s
	}
	return a
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个整数 <code>a</code> 和 <code>b</code> ，<strong>不使用 </strong>运算符&nbsp;<code>+</code> 和&nbsp;<code>-</code>&nbsp;​​​​​​​，计算并返回两整数之和。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>a = 1, b = 2
<strong>输出：</strong>3
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>a = 2, b = 3
<strong>输出：</strong>5
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>-1000 &lt;= a, b &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：位运算

两数字的二进制形式 a,b ，求和 s = a + b ，a(i)、b(i) 分别表示 a、b 的第 i 个二进制位。一共有 4 种情况：

| a(i) | b(i) | 不进位的和 | 进位 |
| ---- | ---- | ---------- | ---- |
| 0    | 0    | 0          | 0    |
| 0    | 1    | 1          | 0    |
| 1    | 0    | 1          | 0    |
| 1    | 1    | 0          | 1    |

观察可以发现，“不进位的和”与“异或运算”有相同规律，而进位则与“与”运算规律相同，并且需要左移一位。

-   对两数进行按位 `^` 异或运算，得到不进位的和；
-   对两数进行按位 `&` 与运算，然后左移一位，得到进位；
-   问题转换为求：“不进位的数 + 进位” 之和；
-   循环，直至进位为 0，返回不进位的数即可（也可以用递归实现）。

时间复杂度 $O(\log n)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def getSum(self, a: int, b: int) -> int:
        a, b = a & 0xFFFFFFFF, b & 0xFFFFFFFF
        while b:
            carry = ((a & b) << 1) & 0xFFFFFFFF
            a, b = a ^ b, carry
        return a if a < 0x80000000 else ~(a ^ 0xFFFFFFFF)
```

#### Java

```java
class Solution {
    public int getSum(int a, int b) {
        return b == 0 ? a : getSum(a ^ b, (a & b) << 1);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int getSum(int a, int b) {
        while (b) {
            unsigned int carry = (unsigned int) (a & b) << 1;
            a = a ^ b;
            b = carry;
        }
        return a;
    }
};
```

#### Go

```go
func getSum(a int, b int) int {
	for b != 0 {
		s := a ^ b
		b = (a & b) << 1
		a = s
	}
	return a
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [372. 超级次方](https://leetcode.cn/problems/super-pow){#372}

{{< tabs "372" >}}

{{% tab "python" %}}
```python
class Solution:
    def superPow(self, a: int, b: List[int]) -> int:
        mod = 1337
        ans = 1
        for e in b[::-1]:
            ans = ans * pow(a, e, mod) % mod
            a = pow(a, 10, mod)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private final int mod = 1337;

    public int superPow(int a, int[] b) {
        long ans = 1;
        for (int i = b.length - 1; i >= 0; --i) {
            ans = ans * qpow(a, b[i]) % mod;
            a = qpow(a, 10);
        }
        return (int) ans;
    }

    private long qpow(long a, int n) {
        long ans = 1;
        for (; n > 0; n >>= 1) {
            if ((n & 1) == 1) {
                ans = ans * a % mod;
            }
            a = a * a % mod;
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int superPow(int a, vector<int>& b) {
        using ll = long long;
        const int mod = 1337;
        ll ans = 1;
        auto qpow = [&](ll a, int n) {
            ll ans = 1;
            for (; n; n >>= 1) {
                if (n & 1) {
                    ans = ans * a % mod;
                }
                a = a * a % mod;
            }
            return (int) ans;
        };
        for (int i = b.size() - 1; ~i; --i) {
            ans = ans * qpow(a, b[i]) % mod;
            a = qpow(a, 10);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func superPow(a int, b []int) int {
	const mod int = 1337
	ans := 1
	qpow := func(a, n int) int {
		ans := 1
		for ; n > 0; n >>= 1 {
			if n&1 == 1 {
				ans = ans * a % mod
			}
			a = a * a % mod
		}
		return ans
	}
	for i := len(b) - 1; i >= 0; i-- {
		ans = ans * qpow(a, b[i]) % mod
		a = qpow(a, 10)
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function superPow(a: number, b: number[]): number {
    let ans = 1;
    const mod = 1337;
    const qpow = (a: number, n: number): number => {
        let ans = 1;
        for (; n; n >>= 1) {
            if (n & 1) {
                ans = Number((BigInt(ans) * BigInt(a)) % BigInt(mod));
            }
            a = Number((BigInt(a) * BigInt(a)) % BigInt(mod));
        }
        return ans;
    };
    for (let i = b.length - 1; ~i; --i) {
        ans = Number((BigInt(ans) * BigInt(qpow(a, b[i]))) % BigInt(mod));
        a = qpow(a, 10);
    }
    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你的任务是计算 <code>a<sup>b</sup></code> 对 <code>1337</code> 取模，<code>a</code> 是一个正整数，<code>b</code> 是一个非常大的正整数且会以数组形式给出。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>a = 2, b = [3]
<strong>输出：</strong>8
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>a = 2, b = [1,0]
<strong>输出：</strong>1024
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>a = 1, b = [4,3,3,8,5,2]
<strong>输出：</strong>1
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>a = 2147483647, b = [2,0,0]
<strong>输出：</strong>1198
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= a <= 2<sup>31</sup> - 1</code></li>
	<li><code>1 <= b.length <= 2000</code></li>
	<li><code>0 <= b[i] <= 9</code></li>
	<li><code>b</code> 不含前导 0</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：快速幂

我们初始化答案变量 $ans = 1$。

接下来，倒序遍历数组 $b$，每次遍历到一个元素 $e$，我们将答案变量 $ans$ 自乘 $a^e$ 并对 $1337$ 取模，然后将 $a$ 自乘 $10$ 次并对 $1337$ 取模。这里需要用到快速幂。

遍历完数组后，返回答案即可。

时间复杂度 $O(\sum_{i=0}^{n-1} \log b_i)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def superPow(self, a: int, b: List[int]) -> int:
        mod = 1337
        ans = 1
        for e in b[::-1]:
            ans = ans * pow(a, e, mod) % mod
            a = pow(a, 10, mod)
        return ans
```

#### Java

```java
class Solution {
    private final int mod = 1337;

    public int superPow(int a, int[] b) {
        long ans = 1;
        for (int i = b.length - 1; i >= 0; --i) {
            ans = ans * qpow(a, b[i]) % mod;
            a = qpow(a, 10);
        }
        return (int) ans;
    }

    private long qpow(long a, int n) {
        long ans = 1;
        for (; n > 0; n >>= 1) {
            if ((n & 1) == 1) {
                ans = ans * a % mod;
            }
            a = a * a % mod;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int superPow(int a, vector<int>& b) {
        using ll = long long;
        const int mod = 1337;
        ll ans = 1;
        auto qpow = [&](ll a, int n) {
            ll ans = 1;
            for (; n; n >>= 1) {
                if (n & 1) {
                    ans = ans * a % mod;
                }
                a = a * a % mod;
            }
            return (int) ans;
        };
        for (int i = b.size() - 1; ~i; --i) {
            ans = ans * qpow(a, b[i]) % mod;
            a = qpow(a, 10);
        }
        return ans;
    }
};
```

#### Go

```go
func superPow(a int, b []int) int {
	const mod int = 1337
	ans := 1
	qpow := func(a, n int) int {
		ans := 1
		for ; n > 0; n >>= 1 {
			if n&1 == 1 {
				ans = ans * a % mod
			}
			a = a * a % mod
		}
		return ans
	}
	for i := len(b) - 1; i >= 0; i-- {
		ans = ans * qpow(a, b[i]) % mod
		a = qpow(a, 10)
	}
	return ans
}
```

#### TypeScript

```ts
function superPow(a: number, b: number[]): number {
    let ans = 1;
    const mod = 1337;
    const qpow = (a: number, n: number): number => {
        let ans = 1;
        for (; n; n >>= 1) {
            if (n & 1) {
                ans = Number((BigInt(ans) * BigInt(a)) % BigInt(mod));
            }
            a = Number((BigInt(a) * BigInt(a)) % BigInt(mod));
        }
        return ans;
    };
    for (let i = b.length - 1; ~i; --i) {
        ans = Number((BigInt(ans) * BigInt(qpow(a, b[i]))) % BigInt(mod));
        a = qpow(a, 10);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [373. 查找和最小的 K 对数字](https://leetcode.cn/problems/find-k-pairs-with-smallest-sums){#373}

{{< tabs "373" >}}

{{% tab "python" %}}
```python
class Solution:
    def kSmallestPairs(
        self, nums1: List[int], nums2: List[int], k: int
    ) -> List[List[int]]:
        q = [[u + nums2[0], i, 0] for i, u in enumerate(nums1[:k])]
        heapify(q)
        ans = []
        while q and k > 0:
            _, i, j = heappop(q)
            ans.append([nums1[i], nums2[j]])
            k -= 1
            if j + 1 < len(nums2):
                heappush(q, [nums1[i] + nums2[j + 1], i, j + 1])
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<List<Integer>> kSmallestPairs(int[] nums1, int[] nums2, int k) {
        PriorityQueue<int[]> q = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        for (int i = 0; i < Math.min(nums1.length, k); ++i) {
            q.offer(new int[] {nums1[i] + nums2[0], i, 0});
        }
        List<List<Integer>> ans = new ArrayList<>();
        while (!q.isEmpty() && k > 0) {
            int[] e = q.poll();
            ans.add(Arrays.asList(nums1[e[1]], nums2[e[2]]));
            --k;
            if (e[2] + 1 < nums2.length) {
                q.offer(new int[] {nums1[e[1]] + nums2[e[2] + 1], e[1], e[2] + 1});
            }
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        auto cmp = [&nums1, &nums2](const pair<int, int>& a, const pair<int, int>& b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };

        int m = nums1.size();
        int n = nums2.size();
        vector<vector<int>> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < min(k, m); i++)
            pq.emplace(i, 0);
        while (k-- && !pq.empty()) {
            auto [x, y] = pq.top();
            pq.pop();
            ans.emplace_back(initializer_list<int>{nums1[x], nums2[y]});
            if (y + 1 < n)
                pq.emplace(x, y + 1);
        }

        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func kSmallestPairs(nums1, nums2 []int, k int) (ans [][]int) {
	m, n := len(nums1), len(nums2)
	h := hp{nil, nums1, nums2}
	for i := 0; i < k && i < m; i++ {
		h.data = append(h.data, pair{i, 0})
	}
	for h.Len() > 0 && len(ans) < k {
		p := heap.Pop(&h).(pair)
		i, j := p.i, p.j
		ans = append(ans, []int{nums1[i], nums2[j]})
		if j+1 < n {
			heap.Push(&h, pair{i, j + 1})
		}
	}
	return
}

type pair struct{ i, j int }
type hp struct {
	data         []pair
	nums1, nums2 []int
}

func (h hp) Len() int { return len(h.data) }
func (h hp) Less(i, j int) bool {
	a, b := h.data[i], h.data[j]
	return h.nums1[a.i]+h.nums2[a.j] < h.nums1[b.i]+h.nums2[b.j]
}
func (h hp) Swap(i, j int) { h.data[i], h.data[j] = h.data[j], h.data[i] }
func (h *hp) Push(v any)   { h.data = append(h.data, v.(pair)) }
func (h *hp) Pop() any     { a := h.data; v := a[len(a)-1]; h.data = a[:len(a)-1]; return v }
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定两个以 <strong>非递减顺序排列</strong> 的整数数组 <code>nums1</code> 和<strong> </strong><code>nums2</code><strong>&nbsp;</strong>,&nbsp;以及一个整数 <code>k</code><strong>&nbsp;</strong>。</p>

<p>定义一对值&nbsp;<code>(u,v)</code>，其中第一个元素来自&nbsp;<code>nums1</code>，第二个元素来自 <code>nums2</code><strong>&nbsp;</strong>。</p>

<p>请找到和最小的 <code>k</code>&nbsp;个数对&nbsp;<code>(u<sub>1</sub>,v<sub>1</sub>)</code>, <code>&nbsp;(u<sub>2</sub>,v<sub>2</sub>)</code> &nbsp;... &nbsp;<code>(u<sub>k</sub>,v<sub>k</sub>)</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1:</strong></p>

<pre>
<strong>输入:</strong> nums1 = [1,7,11], nums2 = [2,4,6], k = 3
<strong>输出:</strong> [1,2],[1,4],[1,6]
<strong>解释: </strong>返回序列中的前 3 对数：
     [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
</pre>

<p><strong class="example">示例 2:</strong></p>

<pre>
<strong>输入: </strong>nums1 = [1,1,2], nums2 = [1,2,3], k = 2
<strong>输出: </strong>[1,1],[1,1]
<strong>解释: </strong>返回序列中的前 2 对数：
&nbsp;    [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= nums1.length, nums2.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= nums1[i], nums2[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>nums1</code> 和 <code>nums2</code> 均为 <strong>升序排列</strong></li>
	<li><meta charset="UTF-8" /><code>1 &lt;= k &lt;= 10<sup>4</sup></code></li>
	<li><code>k &lt;=&nbsp;nums1.length *&nbsp;nums2.length</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def kSmallestPairs(
        self, nums1: List[int], nums2: List[int], k: int
    ) -> List[List[int]]:
        q = [[u + nums2[0], i, 0] for i, u in enumerate(nums1[:k])]
        heapify(q)
        ans = []
        while q and k > 0:
            _, i, j = heappop(q)
            ans.append([nums1[i], nums2[j]])
            k -= 1
            if j + 1 < len(nums2):
                heappush(q, [nums1[i] + nums2[j + 1], i, j + 1])
        return ans
```

#### Java

```java
class Solution {
    public List<List<Integer>> kSmallestPairs(int[] nums1, int[] nums2, int k) {
        PriorityQueue<int[]> q = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        for (int i = 0; i < Math.min(nums1.length, k); ++i) {
            q.offer(new int[] {nums1[i] + nums2[0], i, 0});
        }
        List<List<Integer>> ans = new ArrayList<>();
        while (!q.isEmpty() && k > 0) {
            int[] e = q.poll();
            ans.add(Arrays.asList(nums1[e[1]], nums2[e[2]]));
            --k;
            if (e[2] + 1 < nums2.length) {
                q.offer(new int[] {nums1[e[1]] + nums2[e[2] + 1], e[1], e[2] + 1});
            }
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        auto cmp = [&nums1, &nums2](const pair<int, int>& a, const pair<int, int>& b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };

        int m = nums1.size();
        int n = nums2.size();
        vector<vector<int>> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < min(k, m); i++)
            pq.emplace(i, 0);
        while (k-- && !pq.empty()) {
            auto [x, y] = pq.top();
            pq.pop();
            ans.emplace_back(initializer_list<int>{nums1[x], nums2[y]});
            if (y + 1 < n)
                pq.emplace(x, y + 1);
        }

        return ans;
    }
};
```

#### Go

```go
func kSmallestPairs(nums1, nums2 []int, k int) (ans [][]int) {
	m, n := len(nums1), len(nums2)
	h := hp{nil, nums1, nums2}
	for i := 0; i < k && i < m; i++ {
		h.data = append(h.data, pair{i, 0})
	}
	for h.Len() > 0 && len(ans) < k {
		p := heap.Pop(&h).(pair)
		i, j := p.i, p.j
		ans = append(ans, []int{nums1[i], nums2[j]})
		if j+1 < n {
			heap.Push(&h, pair{i, j + 1})
		}
	}
	return
}

type pair struct{ i, j int }
type hp struct {
	data         []pair
	nums1, nums2 []int
}

func (h hp) Len() int { return len(h.data) }
func (h hp) Less(i, j int) bool {
	a, b := h.data[i], h.data[j]
	return h.nums1[a.i]+h.nums2[a.j] < h.nums1[b.i]+h.nums2[b.j]
}
func (h hp) Swap(i, j int) { h.data[i], h.data[j] = h.data[j], h.data[i] }
func (h *hp) Push(v any)   { h.data = append(h.data, v.(pair)) }
func (h *hp) Pop() any     { a := h.data; v := a[len(a)-1]; h.data = a[:len(a)-1]; return v }
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [374. 猜数字大小](https://leetcode.cn/problems/guess-number-higher-or-lower){#374}

{{< tabs "374" >}}

{{% tab "python" %}}
```python
# The guess API is already defined for you.
# @param num, your guess
# @return -1 if num is higher than the picked number
#          1 if num is lower than the picked number
#          otherwise return 0
# def guess(num: int) -> int:


class Solution:
    def guessNumber(self, n: int) -> int:
        return bisect.bisect(range(1, n + 1), 0, key=lambda x: -guess(x))
```
{{% /tab %}}
{{% tab "java" %}}
```java
/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

public class Solution extends GuessGame {
    public int guessNumber(int n) {
        int left = 1, right = n;
        while (left < right) {
            int mid = (left + right) >>> 1;
            if (guess(mid) <= 0) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int left = 1, right = n;
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (guess(mid) <= 0) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * func guess(num int) int;
 */

func guessNumber(n int) int {
	return sort.Search(n, func(i int) bool {
		i++
		return guess(i) <= 0
	}) + 1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
/**
 * Forward declaration of guess API.
 * @param {number} num   your guess
 * @return 	            -1 if num is lower than the guess number
 *			             1 if num is higher than the guess number
 *                       otherwise return 0
 * var guess = function(num) {}
 */

function guessNumber(n: number): number {
    let l = 1;
    let r = n;
    while (l < r) {
        const mid = (l + r) >>> 1;
        if (guess(mid) <= 0) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * unsafe fn guess(num: i32) -> i32 {}
 */

impl Solution {
    unsafe fn guessNumber(n: i32) -> i32 {
        let mut l = 1;
        let mut r = n;
        loop {
            let mid = l + (r - l) / 2;
            match guess(mid) {
                -1 => {
                    r = mid - 1;
                }
                1 => {
                    l = mid + 1;
                }
                _ => {
                    break mid;
                }
            }
        }
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

public class Solution : GuessGame {
    public int GuessNumber(int n) {
        int left = 1, right = n;
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (guess(mid) <= 0) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>我们正在玩猜数字游戏。猜数字游戏的规则如下：</p>

<p>我会从&nbsp;<code>1</code>&nbsp;到&nbsp;<code>n</code> 随机选择一个数字。 请你猜选出的是哪个数字。（我选的数字在整个游戏中保持不变）。</p>

<p>如果你猜错了，我会告诉你，我选出的数字比你猜测的数字大了还是小了。</p>

<p>你可以通过调用一个预先定义好的接口 <code>int guess(int num)</code> 来获取猜测结果，返回值一共有三种可能的情况：</p>

<ul>
	<li><code>-1</code>：你猜的数字比我选出的数字大 （即&nbsp;<code>num &gt; pick</code>）。</li>
	<li><code>1</code>：你猜的数字比我选出的数字小&nbsp;（即&nbsp;<code>num &lt;&nbsp;pick</code>）。</li>
	<li><code>0</code>：你猜的数字与我选出的数字相等。（即&nbsp;<code>num&nbsp;== pick</code>）。</li>
</ul>

<p>返回我选出的数字。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 10, pick = 6
<strong>输出：</strong>6
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 1, pick = 1
<strong>输出：</strong>1
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 2, pick = 1
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 2<sup>31</sup> - 1</code></li>
	<li><code>1 &lt;= pick &lt;= n</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二分查找

我们在区间 $[1,..n]$ 进行二分查找，找到第一个满足 `guess(x) <= 0` 的数，即为答案。

时间复杂度 $O(\log n)$。其中 $n$ 为题目给定的上限。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
# The guess API is already defined for you.
# @param num, your guess
# @return -1 if num is higher than the picked number
#          1 if num is lower than the picked number
#          otherwise return 0
# def guess(num: int) -> int:


class Solution:
    def guessNumber(self, n: int) -> int:
        return bisect.bisect(range(1, n + 1), 0, key=lambda x: -guess(x))
```

#### Java

```java
/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

public class Solution extends GuessGame {
    public int guessNumber(int n) {
        int left = 1, right = n;
        while (left < right) {
            int mid = (left + right) >>> 1;
            if (guess(mid) <= 0) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
}
```

#### C++

```cpp
/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int left = 1, right = n;
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (guess(mid) <= 0) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
```

#### Go

```go
/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * func guess(num int) int;
 */

func guessNumber(n int) int {
	return sort.Search(n, func(i int) bool {
		i++
		return guess(i) <= 0
	}) + 1
}
```

#### TypeScript

```ts
/**
 * Forward declaration of guess API.
 * @param {number} num   your guess
 * @return 	            -1 if num is lower than the guess number
 *			             1 if num is higher than the guess number
 *                       otherwise return 0
 * var guess = function(num) {}
 */

function guessNumber(n: number): number {
    let l = 1;
    let r = n;
    while (l < r) {
        const mid = (l + r) >>> 1;
        if (guess(mid) <= 0) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}
```

#### Rust

```rust
/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * unsafe fn guess(num: i32) -> i32 {}
 */

impl Solution {
    unsafe fn guessNumber(n: i32) -> i32 {
        let mut l = 1;
        let mut r = n;
        loop {
            let mid = l + (r - l) / 2;
            match guess(mid) {
                -1 => {
                    r = mid - 1;
                }
                1 => {
                    l = mid + 1;
                }
                _ => {
                    break mid;
                }
            }
        }
    }
}
```

#### C#

```cs
/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

public class Solution : GuessGame {
    public int GuessNumber(int n) {
        int left = 1, right = n;
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (guess(mid) <= 0) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [375. 猜数字大小 II](https://leetcode.cn/problems/guess-number-higher-or-lower-ii){#375}

{{< tabs "375" >}}

{{% tab "python" %}}
```python
class Solution:
    def getMoneyAmount(self, n: int) -> int:
        f = [[0] * (n + 1) for _ in range(n + 1)]
        for i in range(n - 1, 0, -1):
            for j in range(i + 1, n + 1):
                f[i][j] = j + f[i][j - 1]
                for k in range(i, j):
                    f[i][j] = min(f[i][j], max(f[i][k - 1], f[k + 1][j]) + k)
        return f[1][n]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int getMoneyAmount(int n) {
        int[][] f = new int[n + 1][n + 1];
        for (int i = n - 1; i > 0; --i) {
            for (int j = i + 1; j <= n; ++j) {
                f[i][j] = j + f[i][j - 1];
                for (int k = i; k < j; ++k) {
                    f[i][j] = Math.min(f[i][j], Math.max(f[i][k - 1], f[k + 1][j]) + k);
                }
            }
        }
        return f[1][n];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int getMoneyAmount(int n) {
        int f[n + 1][n + 1];
        memset(f, 0, sizeof(f));
        for (int i = n - 1; i; --i) {
            for (int j = i + 1; j <= n; ++j) {
                f[i][j] = j + f[i][j - 1];
                for (int k = i; k < j; ++k) {
                    f[i][j] = min(f[i][j], max(f[i][k - 1], f[k + 1][j]) + k);
                }
            }
        }
        return f[1][n];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func getMoneyAmount(n int) int {
	f := make([][]int, n+1)
	for i := range f {
		f[i] = make([]int, n+1)
	}
	for i := n - 1; i > 0; i-- {
		for j := i + 1; j <= n; j++ {
			f[i][j] = j + f[i][j-1]
			for k := i; k < j; k++ {
				f[i][j] = min(f[i][j], k+max(f[i][k-1], f[k+1][j]))
			}
		}
	}
	return f[1][n]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function getMoneyAmount(n: number): number {
    const f: number[][] = Array.from({ length: n + 1 }, () => Array(n + 1).fill(0));
    for (let i = n - 1; i; --i) {
        for (let j = i + 1; j <= n; ++j) {
            f[i][j] = j + f[i][j - 1];
            for (let k = i; k < j; ++k) {
                f[i][j] = Math.min(f[i][j], k + Math.max(f[i][k - 1], f[k + 1][j]));
            }
        }
    }
    return f[1][n];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>我们正在玩一个猜数游戏，游戏规则如下：</p>

<ol>
	<li>我从&nbsp;<code>1</code><strong>&nbsp;</strong>到 <code>n</code> 之间选择一个数字。</li>
	<li>你来猜我选了哪个数字。</li>
	<li>如果你猜到正确的数字，就会 <strong>赢得游戏</strong> 。</li>
	<li>如果你猜错了，那么我会告诉你，我选的数字比你的 <strong>更大或者更小</strong> ，并且你需要继续猜数。</li>
	<li>每当你猜了数字 <code>x</code> 并且猜错了的时候，你需要支付金额为 <code>x</code> 的现金。如果你花光了钱，就会<strong> 输掉游戏</strong> 。</li>
</ol>

<p>给你一个特定的数字 <code>n</code> ，返回能够 <strong>确保你获胜</strong> 的最小现金数，<strong>不管我选择那个数字</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0300-0399/0375.Guess%20Number%20Higher%20or%20Lower%20II/images/graph.png" style="width: 505px; height: 388px;" />
<pre>
<strong>输入：</strong>n = 10
<strong>输出：</strong>16
<strong>解释：</strong>制胜策略如下：
- 数字范围是 [1,10] 。你先猜测数字为 7 。
&nbsp;   - 如果这是我选中的数字，你的总费用为 $0 。否则，你需要支付 $7 。
&nbsp;   - 如果我的数字更大，则下一步需要猜测的数字范围是 [8,10] 。你可以猜测数字为 9 。
&nbsp;       - 如果这是我选中的数字，你的总费用为 $7 。否则，你需要支付 $9 。
&nbsp;       - 如果我的数字更大，那么这个数字一定是 10 。你猜测数字为 10 并赢得游戏，总费用为 $7 + $9 = $16 。
&nbsp;       - 如果我的数字更小，那么这个数字一定是 8 。你猜测数字为 8 并赢得游戏，总费用为 $7 + $9 = $16 。
&nbsp;   - 如果我的数字更小，则下一步需要猜测的数字范围是 [1,6] 。你可以猜测数字为 3 。
&nbsp;       - 如果这是我选中的数字，你的总费用为 $7 。否则，你需要支付 $3 。
&nbsp;       - 如果我的数字更大，则下一步需要猜测的数字范围是 [4,6] 。你可以猜测数字为 5 。
&nbsp;           - 如果这是我选中的数字，你的总费用为 $7 + $3 = $10 。否则，你需要支付 $5 。
&nbsp;           - 如果我的数字更大，那么这个数字一定是 6 。你猜测数字为 6 并赢得游戏，总费用为 $7 + $3 + $5 = $15 。
&nbsp;           - 如果我的数字更小，那么这个数字一定是 4 。你猜测数字为 4 并赢得游戏，总费用为 $7 + $3 + $5 = $15 。
&nbsp;       - 如果我的数字更小，则下一步需要猜测的数字范围是 [1,2] 。你可以猜测数字为 1 。
&nbsp;           - 如果这是我选中的数字，你的总费用为 $7 + $3 = $10 。否则，你需要支付 $1 。
&nbsp;           - 如果我的数字更大，那么这个数字一定是 2 。你猜测数字为 2 并赢得游戏，总费用为 $7 + $3 + $1 = $11 。
在最糟糕的情况下，你需要支付 $16 。因此，你只需要 $16 就可以确保自己赢得游戏。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 1
<strong>输出：</strong>0
<strong>解释：</strong>只有一个可能的数字，所以你可以直接猜 1 并赢得游戏，无需支付任何费用。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 2
<strong>输出：</strong>1
<strong>解释：</strong>有两个可能的数字 1 和 2 。
- 你可以先猜 1 。
&nbsp;   - 如果这是我选中的数字，你的总费用为 $0 。否则，你需要支付 $1 。
&nbsp;   - 如果我的数字更大，那么这个数字一定是 2 。你猜测数字为 2 并赢得游戏，总费用为 $1 。
最糟糕的情况下，你需要支付 $1 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 200</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i][j]$ 表示在区间 $[i, j]$ 中猜中任意一个数最少需要花费的钱数。初始时 $f[i][i] = 0$，因为猜中了唯一的数不需要花费，对于 $i \gt j$ 的情况，也有 $f[i][j] = 0$。答案即为 $f[1][n]$。

对于 $f[i][j]$，我们可以枚举 $[i, j]$ 中的任意一个数 $k$，将区间 $[i, j]$ 分为 $[i, k - 1]$ 和 $[k + 1, j]$ 两部分，选择其中的较大值加上 $k$ 的花费，即 $\max(f[i][k - 1], f[k + 1][j]) + k$ 的最小值。

时间复杂度 $O(n^3)$，空间复杂度 $O(n^2)$。其中 $n$ 为猜测的数字范围。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def getMoneyAmount(self, n: int) -> int:
        f = [[0] * (n + 1) for _ in range(n + 1)]
        for i in range(n - 1, 0, -1):
            for j in range(i + 1, n + 1):
                f[i][j] = j + f[i][j - 1]
                for k in range(i, j):
                    f[i][j] = min(f[i][j], max(f[i][k - 1], f[k + 1][j]) + k)
        return f[1][n]
```

#### Java

```java
class Solution {
    public int getMoneyAmount(int n) {
        int[][] f = new int[n + 1][n + 1];
        for (int i = n - 1; i > 0; --i) {
            for (int j = i + 1; j <= n; ++j) {
                f[i][j] = j + f[i][j - 1];
                for (int k = i; k < j; ++k) {
                    f[i][j] = Math.min(f[i][j], Math.max(f[i][k - 1], f[k + 1][j]) + k);
                }
            }
        }
        return f[1][n];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int getMoneyAmount(int n) {
        int f[n + 1][n + 1];
        memset(f, 0, sizeof(f));
        for (int i = n - 1; i; --i) {
            for (int j = i + 1; j <= n; ++j) {
                f[i][j] = j + f[i][j - 1];
                for (int k = i; k < j; ++k) {
                    f[i][j] = min(f[i][j], max(f[i][k - 1], f[k + 1][j]) + k);
                }
            }
        }
        return f[1][n];
    }
};
```

#### Go

```go
func getMoneyAmount(n int) int {
	f := make([][]int, n+1)
	for i := range f {
		f[i] = make([]int, n+1)
	}
	for i := n - 1; i > 0; i-- {
		for j := i + 1; j <= n; j++ {
			f[i][j] = j + f[i][j-1]
			for k := i; k < j; k++ {
				f[i][j] = min(f[i][j], k+max(f[i][k-1], f[k+1][j]))
			}
		}
	}
	return f[1][n]
}
```

#### TypeScript

```ts
function getMoneyAmount(n: number): number {
    const f: number[][] = Array.from({ length: n + 1 }, () => Array(n + 1).fill(0));
    for (let i = n - 1; i; --i) {
        for (let j = i + 1; j <= n; ++j) {
            f[i][j] = j + f[i][j - 1];
            for (let k = i; k < j; ++k) {
                f[i][j] = Math.min(f[i][j], k + Math.max(f[i][k - 1], f[k + 1][j]));
            }
        }
    }
    return f[1][n];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [376. 摆动序列](https://leetcode.cn/problems/wiggle-subsequence){#376}

{{< tabs "376" >}}

{{% tab "python" %}}
```python
class Solution:
    def wiggleMaxLength(self, nums: List[int]) -> int:
        n = len(nums)
        ans = 1
        f = [1] * n
        g = [1] * n
        for i in range(1, n):
            for j in range(i):
                if nums[j] < nums[i]:
                    f[i] = max(f[i], g[j] + 1)
                elif nums[j] > nums[i]:
                    g[i] = max(g[i], f[j] + 1)
            ans = max(ans, f[i], g[i])
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int wiggleMaxLength(int[] nums) {
        int n = nums.length;
        int ans = 1;
        int[] f = new int[n];
        int[] g = new int[n];
        f[0] = 1;
        g[0] = 1;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    f[i] = Math.max(f[i], g[j] + 1);
                } else if (nums[j] > nums[i]) {
                    g[i] = Math.max(g[i], f[j] + 1);
                }
            }
            ans = Math.max(ans, Math.max(f[i], g[i]));
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;
        vector<int> f(n, 1);
        vector<int> g(n, 1);
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    f[i] = max(f[i], g[j] + 1);
                } else if (nums[j] > nums[i]) {
                    g[i] = max(g[i], f[j] + 1);
                }
            }
            ans = max({ans, f[i], g[i]});
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func wiggleMaxLength(nums []int) int {
	n := len(nums)
	f := make([]int, n)
	g := make([]int, n)
	f[0], g[0] = 1, 1
	ans := 1
	for i := 1; i < n; i++ {
		for j := 0; j < i; j++ {
			if nums[j] < nums[i] {
				f[i] = max(f[i], g[j]+1)
			} else if nums[j] > nums[i] {
				g[i] = max(g[i], f[j]+1)
			}
		}
		ans = max(ans, max(f[i], g[i]))
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function wiggleMaxLength(nums: number[]): number {
    const n = nums.length;
    const f: number[] = Array(n).fill(1);
    const g: number[] = Array(n).fill(1);
    let ans = 1;
    for (let i = 1; i < n; ++i) {
        for (let j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
                f[i] = Math.max(f[i], g[j] + 1);
            } else if (nums[i] < nums[j]) {
                g[i] = Math.max(g[i], f[j] + 1);
            }
        }
        ans = Math.max(ans, f[i], g[i]);
    }
    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>如果连续数字之间的差严格地在正数和负数之间交替，则数字序列称为<strong> 摆动序列 。</strong>第一个差（如果存在的话）可能是正数或负数。仅有一个元素或者含两个不等元素的序列也视作摆动序列。</p>

<ul>
	<li>
	<p>例如， <code>[1, 7, 4, 9, 2, 5]</code> 是一个 <strong>摆动序列</strong> ，因为差值 <code>(6, -3, 5, -7, 3)</code> 是正负交替出现的。</p>
	</li>
	<li>相反，<code>[1, 4, 7, 2, 5]</code> 和 <code>[1, 7, 4, 5, 5]</code> 不是摆动序列，第一个序列是因为它的前两个差值都是正数，第二个序列是因为它的最后一个差值为零。</li>
</ul>

<p><strong>子序列</strong> 可以通过从原始序列中删除一些（也可以不删除）元素来获得，剩下的元素保持其原始顺序。</p>

<p>给你一个整数数组 <code>nums</code> ，返回 <code>nums</code> 中作为 <strong>摆动序列 </strong>的 <strong>最长子序列的长度</strong> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,7,4,9,2,5]
<strong>输出：</strong>6
<strong>解释：</strong>整个序列均为摆动序列，各元素之间的差值为 (6, -3, 5, -7, 3) 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,17,5,10,13,15,10,5,16,8]
<strong>输出：</strong>7
<strong>解释：</strong>这个序列包含几个长度为 7 摆动序列。
其中一个是 [1, 17, 10, 13, 10, 16, 8] ，各元素之间的差值为 (16, -7, 3, -3, 6, -8) 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3,4,5,6,7,8,9]
<strong>输出：</strong>2
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= nums.length <= 1000</code></li>
	<li><code>0 <= nums[i] <= 1000</code></li>
</ul>

<p> </p>

<p><strong>进阶：</strong>你能否用 <code>O(n)</code><em> </em>时间复杂度完成此题?</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i]$ 表示以第 $i$ 个元素结尾且最后是上升趋势的摆动序列的长度，定义 $g[i]$ 表示以第 $i$ 个元素结尾且最后是下降趋势的摆动序列的长度。初始时 $f[0] = g[0] = 1$，因为只有一个元素时，摆动序列的长度为 $1$。初始化答案为 $1$。

对于 $f[i]$，其中 $i \geq 1$，我们在 $[0, i)$ 的范围内枚举 $j$，如果 $nums[j] < nums[i]$，则说明 $i$ 可以接在 $j$ 的后面形成一个上升的摆动序列，此时 $f[i] = \max(f[i], g[j] + 1)$；如果 $nums[j] > nums[i]$，则说明 $i$ 可以接在 $j$ 的后面形成一个下降的摆动序列，此时 $g[i] = \max(g[i], f[j] + 1)$。然后我们更新答案为 $\max(f[i], g[i])$。

最后，我们返回答案。

时间复杂度 $O(n^2)$，空间复杂度 $O(n)$。其中 $n$ 是数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def wiggleMaxLength(self, nums: List[int]) -> int:
        n = len(nums)
        ans = 1
        f = [1] * n
        g = [1] * n
        for i in range(1, n):
            for j in range(i):
                if nums[j] < nums[i]:
                    f[i] = max(f[i], g[j] + 1)
                elif nums[j] > nums[i]:
                    g[i] = max(g[i], f[j] + 1)
            ans = max(ans, f[i], g[i])
        return ans
```

#### Java

```java
class Solution {
    public int wiggleMaxLength(int[] nums) {
        int n = nums.length;
        int ans = 1;
        int[] f = new int[n];
        int[] g = new int[n];
        f[0] = 1;
        g[0] = 1;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    f[i] = Math.max(f[i], g[j] + 1);
                } else if (nums[j] > nums[i]) {
                    g[i] = Math.max(g[i], f[j] + 1);
                }
            }
            ans = Math.max(ans, Math.max(f[i], g[i]));
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;
        vector<int> f(n, 1);
        vector<int> g(n, 1);
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    f[i] = max(f[i], g[j] + 1);
                } else if (nums[j] > nums[i]) {
                    g[i] = max(g[i], f[j] + 1);
                }
            }
            ans = max({ans, f[i], g[i]});
        }
        return ans;
    }
};
```

#### Go

```go
func wiggleMaxLength(nums []int) int {
	n := len(nums)
	f := make([]int, n)
	g := make([]int, n)
	f[0], g[0] = 1, 1
	ans := 1
	for i := 1; i < n; i++ {
		for j := 0; j < i; j++ {
			if nums[j] < nums[i] {
				f[i] = max(f[i], g[j]+1)
			} else if nums[j] > nums[i] {
				g[i] = max(g[i], f[j]+1)
			}
		}
		ans = max(ans, max(f[i], g[i]))
	}
	return ans
}
```

#### TypeScript

```ts
function wiggleMaxLength(nums: number[]): number {
    const n = nums.length;
    const f: number[] = Array(n).fill(1);
    const g: number[] = Array(n).fill(1);
    let ans = 1;
    for (let i = 1; i < n; ++i) {
        for (let j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
                f[i] = Math.max(f[i], g[j] + 1);
            } else if (nums[i] < nums[j]) {
                g[i] = Math.max(g[i], f[j] + 1);
            }
        }
        ans = Math.max(ans, f[i], g[i]);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [377. 组合总和 Ⅳ](https://leetcode.cn/problems/combination-sum-iv){#377}

{{< tabs "377" >}}

{{% tab "python" %}}
```python
class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        f = [1] + [0] * target
        for i in range(1, target + 1):
            for x in nums:
                if i >= x:
                    f[i] += f[i - x]
        return f[target]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int combinationSum4(int[] nums, int target) {
        int[] f = new int[target + 1];
        f[0] = 1;
        for (int i = 1; i <= target; ++i) {
            for (int x : nums) {
                if (i >= x) {
                    f[i] += f[i - x];
                }
            }
        }
        return f[target];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int f[target + 1];
        memset(f, 0, sizeof(f));
        f[0] = 1;
        for (int i = 1; i <= target; ++i) {
            for (int x : nums) {
                if (i >= x && f[i - x] < INT_MAX - f[i]) {
                    f[i] += f[i - x];
                }
            }
        }
        return f[target];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func combinationSum4(nums []int, target int) int {
	f := make([]int, target+1)
	f[0] = 1
	for i := 1; i <= target; i++ {
		for _, x := range nums {
			if i >= x {
				f[i] += f[i-x]
			}
		}
	}
	return f[target]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function combinationSum4(nums: number[], target: number): number {
    const f: number[] = Array(target + 1).fill(0);
    f[0] = 1;
    for (let i = 1; i <= target; ++i) {
        for (const x of nums) {
            if (i >= x) {
                f[i] += f[i - x];
            }
        }
    }
    return f[target];
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var combinationSum4 = function (nums, target) {
    const f = Array(target + 1).fill(0);
    f[0] = 1;
    for (let i = 1; i <= target; ++i) {
        for (const x of nums) {
            if (i >= x) {
                f[i] += f[i - x];
            }
        }
    }
    return f[target];
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int CombinationSum4(int[] nums, int target) {
        int[] f = new int[target + 1];
        f[0] = 1;
        for (int i = 1; i <= target; ++i) {
            foreach (int x in nums) {
                if (i >= x) {
                    f[i] += f[i - x];
                }
            }
        }
        return f[target];
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个由 <strong>不同</strong> 整数组成的数组 <code>nums</code> ，和一个目标整数 <code>target</code> 。请你从 <code>nums</code> 中找出并返回总和为 <code>target</code> 的元素组合的个数。</p>

<p>题目数据保证答案符合 32 位整数范围。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3], target = 4
<strong>输出：</strong>7
<strong>解释：</strong>
所有可能的组合为：
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
请注意，顺序不同的序列被视作不同的组合。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [9], target = 3
<strong>输出：</strong>0
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= nums.length <= 200</code></li>
	<li><code>1 <= nums[i] <= 1000</code></li>
	<li><code>nums</code> 中的所有元素 <strong>互不相同</strong></li>
	<li><code>1 <= target <= 1000</code></li>
</ul>

<p> </p>

<p><strong>进阶：</strong>如果给定的数组中含有负数会发生什么？问题会产生何种变化？如果允许负数出现，需要向题目中添加哪些限制条件？</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i]$ 表示总和为 $i$ 的元素组合的个数，初始时 $f[0] = 1$，其余 $f[i] = 0$。最终答案即为 $f[target]$。

对于 $f[i]$，我们可以枚举数组中的每个元素 $x$，如果 $i \ge x$，则 $f[i] = f[i] + f[i - x]$。

最后返回 $f[target]$ 即可。

时间复杂度 $O(n \times target)$，空间复杂度 $O(target)$。其中 $n$ 为数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        f = [1] + [0] * target
        for i in range(1, target + 1):
            for x in nums:
                if i >= x:
                    f[i] += f[i - x]
        return f[target]
```

#### Java

```java
class Solution {
    public int combinationSum4(int[] nums, int target) {
        int[] f = new int[target + 1];
        f[0] = 1;
        for (int i = 1; i <= target; ++i) {
            for (int x : nums) {
                if (i >= x) {
                    f[i] += f[i - x];
                }
            }
        }
        return f[target];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int f[target + 1];
        memset(f, 0, sizeof(f));
        f[0] = 1;
        for (int i = 1; i <= target; ++i) {
            for (int x : nums) {
                if (i >= x && f[i - x] < INT_MAX - f[i]) {
                    f[i] += f[i - x];
                }
            }
        }
        return f[target];
    }
};
```

#### Go

```go
func combinationSum4(nums []int, target int) int {
	f := make([]int, target+1)
	f[0] = 1
	for i := 1; i <= target; i++ {
		for _, x := range nums {
			if i >= x {
				f[i] += f[i-x]
			}
		}
	}
	return f[target]
}
```

#### TypeScript

```ts
function combinationSum4(nums: number[], target: number): number {
    const f: number[] = Array(target + 1).fill(0);
    f[0] = 1;
    for (let i = 1; i <= target; ++i) {
        for (const x of nums) {
            if (i >= x) {
                f[i] += f[i - x];
            }
        }
    }
    return f[target];
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var combinationSum4 = function (nums, target) {
    const f = Array(target + 1).fill(0);
    f[0] = 1;
    for (let i = 1; i <= target; ++i) {
        for (const x of nums) {
            if (i >= x) {
                f[i] += f[i - x];
            }
        }
    }
    return f[target];
};
```

#### C#

```cs
public class Solution {
    public int CombinationSum4(int[] nums, int target) {
        int[] f = new int[target + 1];
        f[0] = 1;
        for (int i = 1; i <= target; ++i) {
            foreach (int x in nums) {
                if (i >= x) {
                    f[i] += f[i - x];
                }
            }
        }
        return f[target];
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [378. 有序矩阵中第 K 小的元素](https://leetcode.cn/problems/kth-smallest-element-in-a-sorted-matrix){#378}

{{< tabs "378" >}}

{{% tab "python" %}}
```python
class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        def check(matrix, mid, k, n):
            count = 0
            i, j = n - 1, 0
            while i >= 0 and j < n:
                if matrix[i][j] <= mid:
                    count += i + 1
                    j += 1
                else:
                    i -= 1
            return count >= k

        n = len(matrix)
        left, right = matrix[0][0], matrix[n - 1][n - 1]
        while left < right:
            mid = (left + right) >> 1
            if check(matrix, mid, k, n):
                right = mid
            else:
                left = mid + 1
        return left
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int kthSmallest(int[][] matrix, int k) {
        int n = matrix.length;
        int left = matrix[0][0], right = matrix[n - 1][n - 1];
        while (left < right) {
            int mid = (left + right) >>> 1;
            if (check(matrix, mid, k, n)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    private boolean check(int[][] matrix, int mid, int k, int n) {
        int count = 0;
        int i = n - 1, j = 0;
        while (i >= 0 && j < n) {
            if (matrix[i][j] <= mid) {
                count += (i + 1);
                ++j;
            } else {
                --i;
            }
        }
        return count >= k;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0], right = matrix[n - 1][n - 1];
        while (left < right) {
            int mid = left + right >> 1;
            if (check(matrix, mid, k, n)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

private:
    bool check(vector<vector<int>>& matrix, int mid, int k, int n) {
        int count = 0;
        int i = n - 1, j = 0;
        while (i >= 0 && j < n) {
            if (matrix[i][j] <= mid) {
                count += (i + 1);
                ++j;
            } else {
                --i;
            }
        }
        return count >= k;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func kthSmallest(matrix [][]int, k int) int {
	n := len(matrix)
	left, right := matrix[0][0], matrix[n-1][n-1]
	for left < right {
		mid := (left + right) >> 1
		if check(matrix, mid, k, n) {
			right = mid
		} else {
			left = mid + 1
		}
	}
	return left
}

func check(matrix [][]int, mid, k, n int) bool {
	count := 0
	i, j := n-1, 0
	for i >= 0 && j < n {
		if matrix[i][j] <= mid {
			count += (i + 1)
			j++
		} else {
			i--
		}
	}
	return count >= k
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个&nbsp;<code>n x n</code><em>&nbsp;</em>矩阵&nbsp;<code>matrix</code> ，其中每行和每列元素均按升序排序，找到矩阵中第 <code>k</code> 小的元素。<br />
请注意，它是 <strong>排序后</strong> 的第 <code>k</code> 小元素，而不是第 <code>k</code> 个 <strong>不同</strong> 的元素。</p>

<p>你必须找到一个内存复杂度优于&nbsp;<code>O(n<sup>2</sup>)</code> 的解决方案。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
<strong>输出：</strong>13
<strong>解释：</strong>矩阵中的元素为 [1,5,9,10,11,12,13,<strong>13</strong>,15]，第 8 小元素是 13
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>matrix = [[-5]], k = 1
<strong>输出：</strong>-5
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == matrix.length</code></li>
	<li><code>n == matrix[i].length</code></li>
	<li><code>1 &lt;= n &lt;= 300</code></li>
	<li><code>-10<sup>9</sup> &lt;= matrix[i][j] &lt;= 10<sup>9</sup></code></li>
	<li>题目数据 <strong>保证</strong> <code>matrix</code> 中的所有行和列都按 <strong>非递减顺序</strong> 排列</li>
	<li><code>1 &lt;= k &lt;= n<sup>2</sup></code></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong></p>

<ul>
	<li>你能否用一个恒定的内存(即 <code>O(1)</code> 内存复杂度)来解决这个问题?</li>
	<li>你能在 <code>O(n)</code> 的时间复杂度下解决这个问题吗?这个方法对于面试来说可能太超前了，但是你会发现阅读这篇文章（&nbsp;<a href="http://www.cse.yorku.ca/~andy/pubs/X+Y.pdf" target="_blank">this paper</a>&nbsp;）很有趣。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        def check(matrix, mid, k, n):
            count = 0
            i, j = n - 1, 0
            while i >= 0 and j < n:
                if matrix[i][j] <= mid:
                    count += i + 1
                    j += 1
                else:
                    i -= 1
            return count >= k

        n = len(matrix)
        left, right = matrix[0][0], matrix[n - 1][n - 1]
        while left < right:
            mid = (left + right) >> 1
            if check(matrix, mid, k, n):
                right = mid
            else:
                left = mid + 1
        return left
```

#### Java

```java
class Solution {
    public int kthSmallest(int[][] matrix, int k) {
        int n = matrix.length;
        int left = matrix[0][0], right = matrix[n - 1][n - 1];
        while (left < right) {
            int mid = (left + right) >>> 1;
            if (check(matrix, mid, k, n)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    private boolean check(int[][] matrix, int mid, int k, int n) {
        int count = 0;
        int i = n - 1, j = 0;
        while (i >= 0 && j < n) {
            if (matrix[i][j] <= mid) {
                count += (i + 1);
                ++j;
            } else {
                --i;
            }
        }
        return count >= k;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0], right = matrix[n - 1][n - 1];
        while (left < right) {
            int mid = left + right >> 1;
            if (check(matrix, mid, k, n)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

private:
    bool check(vector<vector<int>>& matrix, int mid, int k, int n) {
        int count = 0;
        int i = n - 1, j = 0;
        while (i >= 0 && j < n) {
            if (matrix[i][j] <= mid) {
                count += (i + 1);
                ++j;
            } else {
                --i;
            }
        }
        return count >= k;
    }
};
```

#### Go

```go
func kthSmallest(matrix [][]int, k int) int {
	n := len(matrix)
	left, right := matrix[0][0], matrix[n-1][n-1]
	for left < right {
		mid := (left + right) >> 1
		if check(matrix, mid, k, n) {
			right = mid
		} else {
			left = mid + 1
		}
	}
	return left
}

func check(matrix [][]int, mid, k, n int) bool {
	count := 0
	i, j := n-1, 0
	for i >= 0 && j < n {
		if matrix[i][j] <= mid {
			count += (i + 1)
			j++
		} else {
			i--
		}
	}
	return count >= k
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [379. 电话目录管理系统 🔒](https://leetcode.cn/problems/design-phone-directory){#379}

{{< tabs "379" >}}

{{% tab "python" %}}
```python
class PhoneDirectory:

    def __init__(self, maxNumbers: int):
        self.available = set(range(maxNumbers))

    def get(self) -> int:
        if not self.available:
            return -1
        return self.available.pop()

    def check(self, number: int) -> bool:
        return number in self.available

    def release(self, number: int) -> None:
        self.available.add(number)


# Your PhoneDirectory object will be instantiated and called as such:
# obj = PhoneDirectory(maxNumbers)
# param_1 = obj.get()
# param_2 = obj.check(number)
# obj.release(number)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class PhoneDirectory {
    private Set<Integer> available = new HashSet<>();

    public PhoneDirectory(int maxNumbers) {
        for (int i = 0; i < maxNumbers; ++i) {
            available.add(i);
        }
    }

    public int get() {
        if (available.isEmpty()) {
            return -1;
        }
        int x = available.iterator().next();
        available.remove(x);
        return x;
    }

    public boolean check(int number) {
        return available.contains(number);
    }

    public void release(int number) {
        available.add(number);
    }
}

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * boolean param_2 = obj.check(number);
 * obj.release(number);
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class PhoneDirectory {
public:
    PhoneDirectory(int maxNumbers) {
        for (int i = 0; i < maxNumbers; ++i) {
            available.insert(i);
        }
    }

    int get() {
        if (available.empty()) {
            return -1;
        }
        int x = *available.begin();
        available.erase(x);
        return x;
    }

    bool check(int number) {
        return available.contains(number);
    }

    void release(int number) {
        available.insert(number);
    }

private:
    unordered_set<int> available;
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type PhoneDirectory struct {
	available map[int]bool
}

func Constructor(maxNumbers int) PhoneDirectory {
	available := make(map[int]bool)
	for i := 0; i < maxNumbers; i++ {
		available[i] = true
	}
	return PhoneDirectory{available}
}

func (this *PhoneDirectory) Get() int {
	for k := range this.available {
		delete(this.available, k)
		return k
	}
	return -1
}

func (this *PhoneDirectory) Check(number int) bool {
	_, ok := this.available[number]
	return ok
}

func (this *PhoneDirectory) Release(number int) {
	this.available[number] = true
}

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * obj := Constructor(maxNumbers);
 * param_1 := obj.Get();
 * param_2 := obj.Check(number);
 * obj.Release(number);
 */
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class PhoneDirectory {
    private available: Set<number> = new Set();

    constructor(maxNumbers: number) {
        for (let i = 0; i < maxNumbers; ++i) {
            this.available.add(i);
        }
    }

    get(): number {
        const [x] = this.available;
        if (x === undefined) {
            return -1;
        }
        this.available.delete(x);
        return x;
    }

    check(number: number): boolean {
        return this.available.has(number);
    }

    release(number: number): void {
        this.available.add(number);
    }
}

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * var obj = new PhoneDirectory(maxNumbers)
 * var param_1 = obj.get()
 * var param_2 = obj.check(number)
 * obj.release(number)
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>设计一个电话目录管理系统，一开始有&nbsp;<code>maxNumbers</code>&nbsp;个位置能够储存号码。系统应该存储号码，检查某个位置是否为空，并清空给定的位置。</p>

<p>实现&nbsp;<code>PhoneDirectory</code>&nbsp;类：</p>

<ul>
	<li><code>PhoneDirectory(int maxNumbers)</code>&nbsp;电话目录初始有 <code>maxNumbers</code> 个可用位置。</li>
	<li><code>int get()</code> 提供一个未分配给任何人的号码。如果没有可用号码则返回&nbsp;<code>-1</code>。</li>
	<li><code>bool check(int number)</code>&nbsp;如果位置&nbsp;<code>number</code>&nbsp;可用返回 <code>true</code>&nbsp;否则返回&nbsp;<code>false</code>。</li>
	<li><code>void release(int number)</code> 回收或释放位置&nbsp;<code>number</code>。</li>
</ul>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>
["PhoneDirectory", "get", "get", "check", "get", "check", "release", "check"]
[[3], [], [], [2], [], [2], [2], [2]]
<strong>输出：</strong>
[null, 0, 1, true, 2, false, null, true]

<strong>解释：</strong>
PhoneDirectory phoneDirectory = new PhoneDirectory(3);
phoneDirectory.get();      // 它可以返回任意可用的数字。这里我们假设它返回 0。
phoneDirectory.get();      // 假设它返回 1。
phoneDirectory.check(2);   // 数字 2 可用，所以返回 true。
phoneDirectory.get();      // 返回剩下的唯一一个数字 2。
phoneDirectory.check(2);   // 数字 2 不再可用，所以返回 false。
phoneDirectory.release(2); // 将数字 2 释放回号码池。
phoneDirectory.check(2);   // 数字 2 重新可用，返回 true。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= maxNumbers &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= number &lt; maxNumbers</code></li>
	<li><code>get</code>，<code>check</code>&nbsp;和&nbsp;<code>release</code>&nbsp;最多被调用&nbsp;<code>2 * 10<sup>4</sup></code>&nbsp;次。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

我们可以使用一个哈希集合 `available` 来存储未被分配的电话号码，初始时，哈希表中存储的是 `[0, 1, 2, ..., maxNumbers - 1]`。

调用 `get` 方法时，我们从 `available` 中取出一个未被分配的电话号码，如果 `available` 为空，则返回 `-1`。时间复杂度 $O(1)$。

调用 `check` 方法时，我们只需要判断 `number` 是否在 `available` 中即可。时间复杂度 $O(1)$。

调用 `release` 方法时，我们将 `number` 添加到 `available` 中。时间复杂度 $O(1)$。

空间复杂度 $O(n)$，其中 $n$ 是 `maxNumbers` 的值。

<!-- tabs:start -->

#### Python3

```python
class PhoneDirectory:

    def __init__(self, maxNumbers: int):
        self.available = set(range(maxNumbers))

    def get(self) -> int:
        if not self.available:
            return -1
        return self.available.pop()

    def check(self, number: int) -> bool:
        return number in self.available

    def release(self, number: int) -> None:
        self.available.add(number)


# Your PhoneDirectory object will be instantiated and called as such:
# obj = PhoneDirectory(maxNumbers)
# param_1 = obj.get()
# param_2 = obj.check(number)
# obj.release(number)
```

#### Java

```java
class PhoneDirectory {
    private Set<Integer> available = new HashSet<>();

    public PhoneDirectory(int maxNumbers) {
        for (int i = 0; i < maxNumbers; ++i) {
            available.add(i);
        }
    }

    public int get() {
        if (available.isEmpty()) {
            return -1;
        }
        int x = available.iterator().next();
        available.remove(x);
        return x;
    }

    public boolean check(int number) {
        return available.contains(number);
    }

    public void release(int number) {
        available.add(number);
    }
}

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * boolean param_2 = obj.check(number);
 * obj.release(number);
 */
```

#### C++

```cpp
class PhoneDirectory {
public:
    PhoneDirectory(int maxNumbers) {
        for (int i = 0; i < maxNumbers; ++i) {
            available.insert(i);
        }
    }

    int get() {
        if (available.empty()) {
            return -1;
        }
        int x = *available.begin();
        available.erase(x);
        return x;
    }

    bool check(int number) {
        return available.contains(number);
    }

    void release(int number) {
        available.insert(number);
    }

private:
    unordered_set<int> available;
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */
```

#### Go

```go
type PhoneDirectory struct {
	available map[int]bool
}

func Constructor(maxNumbers int) PhoneDirectory {
	available := make(map[int]bool)
	for i := 0; i < maxNumbers; i++ {
		available[i] = true
	}
	return PhoneDirectory{available}
}

func (this *PhoneDirectory) Get() int {
	for k := range this.available {
		delete(this.available, k)
		return k
	}
	return -1
}

func (this *PhoneDirectory) Check(number int) bool {
	_, ok := this.available[number]
	return ok
}

func (this *PhoneDirectory) Release(number int) {
	this.available[number] = true
}

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * obj := Constructor(maxNumbers);
 * param_1 := obj.Get();
 * param_2 := obj.Check(number);
 * obj.Release(number);
 */
```

#### TypeScript

```ts
class PhoneDirectory {
    private available: Set<number> = new Set();

    constructor(maxNumbers: number) {
        for (let i = 0; i < maxNumbers; ++i) {
            this.available.add(i);
        }
    }

    get(): number {
        const [x] = this.available;
        if (x === undefined) {
            return -1;
        }
        this.available.delete(x);
        return x;
    }

    check(number: number): boolean {
        return this.available.has(number);
    }

    release(number: number): void {
        this.available.add(number);
    }
}

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * var obj = new PhoneDirectory(maxNumbers)
 * var param_1 = obj.get()
 * var param_2 = obj.check(number)
 * obj.release(number)
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
