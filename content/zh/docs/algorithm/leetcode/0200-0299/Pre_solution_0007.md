---
title: "0260_只出现一次的数字 III"
date: 2025-10-08T18:35:28+08:00
weight: 7
tags: [二分查找, 位运算, 动态规划, 哈希表, 回溯, 图, 堆（优先队列）, 字符串, 并查集, 广度优先搜索, 拓扑排序, 排序, 数学, 数据库, 数组, 深度优先搜索]
---

{{< markmap >}}
### [0260_只出现一次的数字 III](#260)
#### [位运算](#260)
#### [数组](#260)
### [0261_以图判树 🔒](#261)
#### [深度优先搜索](#261)
#### [广度优先搜索](#261)
#### [并查集](#261)
#### [图](#261)
### [0262_行程和用户](#262)
#### [数据库](#262)
### [0263_丑数](#263)
#### [数学](#263)
### [0264_丑数 II](#264)
#### [哈希表](#264)
#### [数学](#264)
#### [动态规划](#264)
#### [堆（优先队列）](#264)
### [0265_粉刷房子 II 🔒](#265)
#### [数组](#265)
#### [动态规划](#265)
### [0266_回文排列 🔒](#266)
#### [位运算](#266)
#### [哈希表](#266)
#### [字符串](#266)
### [0267_回文排列 II 🔒](#267)
#### [哈希表](#267)
#### [字符串](#267)
#### [回溯](#267)
### [0268_丢失的数字](#268)
#### [位运算](#268)
#### [数组](#268)
#### [哈希表](#268)
#### [数学](#268)
#### [二分查找](#268)
#### [排序](#268)
### [0269_火星词典 🔒](#269)
#### [深度优先搜索](#269)
#### [广度优先搜索](#269)
#### [图](#269)
#### [拓扑排序](#269)
#### [数组](#269)
#### [字符串](#269)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0260_只出现一次的数字 III
___
#### 位运算
___
#### 数组
---
### 0261_以图判树 🔒
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 并查集
___
#### 图
---
### 0262_行程和用户
___
#### 数据库
---
### 0263_丑数
___
#### 数学
---
### 0264_丑数 II
___
#### 哈希表
___
#### 数学
___
#### 动态规划
___
#### 堆（优先队列）
---
### 0265_粉刷房子 II 🔒
___
#### 数组
___
#### 动态规划
---
### 0266_回文排列 🔒
___
#### 位运算
___
#### 哈希表
___
#### 字符串
---
### 0267_回文排列 II 🔒
___
#### 哈希表
___
#### 字符串
___
#### 回溯
---
### 0268_丢失的数字
___
#### 位运算
___
#### 数组
___
#### 哈希表
___
#### 数学
___
#### 二分查找
___
#### 排序
---
### 0269_火星词典 🔒
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 图
___
#### 拓扑排序
___
#### 数组
___
#### 字符串
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 位运算 | 动态规划 |
| 哈希表 | 回溯 | 图 |
| 堆（优先队列） | 字符串 | 并查集 |
| 广度优先搜索 | 拓扑排序 | 排序 |
| 数学 | 数据库 | 数组 |
| 深度优先搜索 |  |  |

# [260. 只出现一次的数字 III](https://leetcode.cn/problems/single-number-iii){#260}

{{< tabs "260" >}}

{{% tab "python" %}}
```python
class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        xs = reduce(xor, nums)
        a = 0
        lb = xs & -xs
        for x in nums:
            if x & lb:
                a ^= x
        b = xs ^ a
        return [a, b]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] singleNumber(int[] nums) {
        int xs = 0;
        for (int x : nums) {
            xs ^= x;
        }
        int lb = xs & -xs;
        int a = 0;
        for (int x : nums) {
            if ((x & lb) != 0) {
                a ^= x;
            }
        }
        int b = xs ^ a;
        return new int[] {a, b};
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xs = 0;
        for (int& x : nums) {
            xs ^= x;
        }
        int lb = xs & -xs;
        int a = 0;
        for (int& x : nums) {
            if (x & lb) {
                a ^= x;
            }
        }
        int b = xs ^ a;
        return {a, b};
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func singleNumber(nums []int) []int {
	xs := 0
	for _, x := range nums {
		xs ^= x
	}
	lb := xs & -xs
	a := 0
	for _, x := range nums {
		if x&lb != 0 {
			a ^= x
		}
	}
	b := xs ^ a
	return []int{a, b}
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function singleNumber(nums: number[]): number[] {
    const set = new Set<number>();

    for (const x of nums) {
        if (set.has(x)) set.delete(x);
        else set.add(x);
    }

    return [...set];
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn single_number(nums: Vec<i32>) -> Vec<i32> {
        let xs = nums.iter().fold(0, |r, v| r ^ v);
        let lb = xs & -xs;
        let mut a = 0;
        for x in &nums {
            if (x & lb) != 0 {
                a ^= x;
            }
        }
        let b = xs ^ a;
        vec![a, b]
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} nums
 * @return {number[]}
 */
function singleNumber(nums) {
    const set = new Set();

    for (const x of nums) {
        if (set.has(x)) set.delete(x);
        else set.add(x);
    }

    return [...set];
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int[] SingleNumber(int[] nums) {
        int xs = nums.Aggregate(0, (a, b) => a ^ b);
        int lb = xs & -xs;
        int a = 0;
        foreach(int x in nums) {
            if ((x & lb) != 0) {
                a ^= x;
            }
        }
        int b = xs ^ a;
        return new int[] {a, b};
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组&nbsp;<code>nums</code>，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。你可以按 <strong>任意顺序</strong> 返回答案。</p>

<p>你必须设计并实现线性时间复杂度的算法且仅使用常量额外空间来解决此问题。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,1,3,2,5]
<strong>输出：</strong>[3,5]
<strong>解释：</strong>[5, 3] 也是有效的答案。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [-1,0]
<strong>输出：</strong>[-1,0]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [0,1]
<strong>输出：</strong>[1,0]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>-2<sup>31</sup> &lt;= nums[i] &lt;= 2<sup>31</sup> - 1</code></li>
	<li>除两个只出现一次的整数外，<code>nums</code> 中的其他数字都出现两次</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：位运算

异或运算有以下性质：

-   任何数和 $0$ 做异或运算，结果仍然是原来的数，即 $x \oplus 0 = x$；
-   任何数和其自身做异或运算，结果是 $0$，即 $x \oplus x = 0$；

由于数组中除了两个数字之外，其他数字都出现了两次，因此我们对数组中的所有数字进行异或运算，得到的结果即为两个只出现一次的数字的异或结果。

而由于这两个数字不相等，因此异或结果中至少存在一位为 $1$。我们可以通过 `lowbit` 运算找到异或结果中最低位的 $1$，并将数组中的所有数字按照该位是否为 $1$ 分为两组，这样两个只出现一次的数字就被分到了不同的组中。

对两个组分别进行异或运算，即可得到两个只出现一次的数字 $a$ 和 $b$。

时间复杂度 $O(n)$，其中 $n$ 为数组长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        xs = reduce(xor, nums)
        a = 0
        lb = xs & -xs
        for x in nums:
            if x & lb:
                a ^= x
        b = xs ^ a
        return [a, b]
```

#### Java

```java
class Solution {
    public int[] singleNumber(int[] nums) {
        int xs = 0;
        for (int x : nums) {
            xs ^= x;
        }
        int lb = xs & -xs;
        int a = 0;
        for (int x : nums) {
            if ((x & lb) != 0) {
                a ^= x;
            }
        }
        int b = xs ^ a;
        return new int[] {a, b};
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xs = 0;
        for (int& x : nums) {
            xs ^= x;
        }
        int lb = xs & -xs;
        int a = 0;
        for (int& x : nums) {
            if (x & lb) {
                a ^= x;
            }
        }
        int b = xs ^ a;
        return {a, b};
    }
};
```

#### Go

```go
func singleNumber(nums []int) []int {
	xs := 0
	for _, x := range nums {
		xs ^= x
	}
	lb := xs & -xs
	a := 0
	for _, x := range nums {
		if x&lb != 0 {
			a ^= x
		}
	}
	b := xs ^ a
	return []int{a, b}
}
```

#### TypeScript

```ts
function singleNumber(nums: number[]): number[] {
    const xs = nums.reduce((a, b) => a ^ b);
    const lb = xs & -xs;
    let a = 0;
    for (const x of nums) {
        if (x & lb) {
            a ^= x;
        }
    }
    const b = xs ^ a;
    return [a, b];
}
```

#### Rust

```rust
impl Solution {
    pub fn single_number(nums: Vec<i32>) -> Vec<i32> {
        let xs = nums.iter().fold(0, |r, v| r ^ v);
        let lb = xs & -xs;
        let mut a = 0;
        for x in &nums {
            if (x & lb) != 0 {
                a ^= x;
            }
        }
        let b = xs ^ a;
        vec![a, b]
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var singleNumber = function (nums) {
    const xs = nums.reduce((a, b) => a ^ b);
    const lb = xs & -xs;
    let a = 0;
    for (const x of nums) {
        if (x & lb) {
            a ^= x;
        }
    }
    const b = xs ^ a;
    return [a, b];
};
```

#### C#

```cs
public class Solution {
    public int[] SingleNumber(int[] nums) {
        int xs = nums.Aggregate(0, (a, b) => a ^ b);
        int lb = xs & -xs;
        int a = 0;
        foreach(int x in nums) {
            if ((x & lb) != 0) {
                a ^= x;
            }
        }
        int b = xs ^ a;
        return new int[] {a, b};
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：哈希表

<!-- tabs:start -->

#### TypeScript

```ts
function singleNumber(nums: number[]): number[] {
    const set = new Set<number>();

    for (const x of nums) {
        if (set.has(x)) set.delete(x);
        else set.add(x);
    }

    return [...set];
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @return {number[]}
 */
function singleNumber(nums) {
    const set = new Set();

    for (const x of nums) {
        if (set.has(x)) set.delete(x);
        else set.add(x);
    }

    return [...set];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [261. 以图判树 🔒](https://leetcode.cn/problems/graph-valid-tree){#261}

{{< tabs "261" >}}

{{% tab "python" %}}
```python
class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        def dfs(i: int):
            vis.add(i)
            for j in g[i]:
                if j not in vis:
                    dfs(j)

        if len(edges) != n - 1:
            return False
        g = [[] for _ in range(n)]
        for a, b in edges:
            g[a].append(b)
            g[b].append(a)
        vis = set()
        dfs(0)
        return len(vis) == n
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private List<Integer>[] g;
    private Set<Integer> vis = new HashSet<>();

    public boolean validTree(int n, int[][] edges) {
        if (edges.length != n - 1) {
            return false;
        }
        g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (var e : edges) {
            int a = e[0], b = e[1];
            g[a].add(b);
            g[b].add(a);
        }
        dfs(0);
        return vis.size() == n;
    }

    private void dfs(int i) {
        vis.add(i);
        for (int j : g[i]) {
            if (!vis.contains(j)) {
                dfs(j);
            }
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) {
            return false;
        }
        vector<int> g[n];
        vector<int> vis(n);
        function<void(int)> dfs = [&](int i) {
            vis[i] = true;
            --n;
            for (int j : g[i]) {
                if (!vis[j]) {
                    dfs(j);
                }
            }
        };
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        dfs(0);
        return n == 0;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func validTree(n int, edges [][]int) bool {
	if len(edges) != n-1 {
		return false
	}
	g := make([][]int, n)
	vis := make([]bool, n)
	for _, e := range edges {
		a, b := e[0], e[1]
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}
	var dfs func(int)
	dfs = func(i int) {
		vis[i] = true
		n--
		for _, j := range g[i] {
			if !vis[j] {
				dfs(j)
			}
		}
	}
	dfs(0)
	return n == 0
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number} n
 * @param {number[][]} edges
 * @return {boolean}
 */
var validTree = function (n, edges) {
    if (edges.length !== n - 1) {
        return false;
    }
    const g = Array.from({ length: n }, () => []);
    const vis = Array.from({ length: n }, () => false);
    for (const [a, b] of edges) {
        g[a].push(b);
        g[b].push(a);
    }
    const dfs = i => {
        vis[i] = true;
        --n;
        for (const j of g[i]) {
            if (!vis[j]) {
                dfs(j);
            }
        }
    };
    dfs(0);
    return n === 0;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定编号从 <code>0</code> 到 <code>n - 1</code>&nbsp;的&nbsp;<code>n</code> 个结点。给定一个整数&nbsp;<code>n</code>&nbsp;和一个&nbsp;<code>edges</code>&nbsp;列表，其中&nbsp;<code>edges[i] = [a<sub>i</sub>, b<sub>i</sub>]</code>&nbsp;表示图中节点&nbsp;<code>a<sub>i</sub></code>&nbsp;和&nbsp;<code>b<sub>i</sub></code>&nbsp;之间存在一条无向边。</p>

<p>如果这些边能够形成一个合法有效的树结构，则返回 <code>true</code> ，否则返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0200-0299/0261.Graph%20Valid%20Tree/images/tree1-graph.jpg" /></p>

<pre>
<strong>输入:</strong> <code>n = 5</code>, edges<code> = [[0,1],[0,2],[0,3],[1,4]]</code>
<strong>输出:</strong> true</pre>

<p><strong>示例 2:</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0200-0299/0261.Graph%20Valid%20Tree/images/tree2-graph.jpg" /></p>

<pre>
<strong>输入:</strong> <code>n = 5, </code>edges<code> = [[0,1],[1,2],[2,3],[1,3],[1,4]]</code>
<strong>输出:</strong> false</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 2000</code></li>
	<li><code>0 &lt;= edges.length &lt;= 5000</code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub>&nbsp;&lt; n</code></li>
	<li><code>a<sub>i</sub>&nbsp;!= b<sub>i</sub></code></li>
	<li>不存在自循环或重复的边</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：并查集

判断是否是树，需要满足以下两个条件：

1. 边的数量等于节点数减一；
2. 不存在环。

我们可以使用并查集来判断是否存在环。遍历边，如果两个节点已经在同一个集合中，说明存在环。否则，我们将两个节点合并到同一个集合中。然后将连通分量的数量减一，最后判断连通分量的数量是否为 $1$。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 是节点数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        def find(x: int) -> int:
            if p[x] != x:
                p[x] = find(p[x])
            return p[x]

        p = list(range(n))
        for a, b in edges:
            pa, pb = find(a), find(b)
            if pa == pb:
                return False
            p[pa] = pb
            n -= 1
        return n == 1
```

#### Java

```java
class Solution {
    private int[] p;

    public boolean validTree(int n, int[][] edges) {
        p = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
        }
        for (var e : edges) {
            int pa = find(e[0]), pb = find(e[1]);
            if (pa == pb) {
                return false;
            }
            p[pa] = pb;
            --n;
        }
        return n == 1;
    }

    private int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> p(n);
        iota(p.begin(), p.end(), 0);
        function<int(int)> find = [&](int x) {
            if (p[x] != x) {
                p[x] = find(p[x]);
            }
            return p[x];
        };
        for (auto& e : edges) {
            int pa = find(e[0]), pb = find(e[1]);
            if (pa == pb) {
                return false;
            }
            p[pa] = pb;
            --n;
        }
        return n == 1;
    }
};
```

#### Go

```go
func validTree(n int, edges [][]int) bool {
	p := make([]int, n)
	for i := range p {
		p[i] = i
	}
	var find func(int) int
	find = func(x int) int {
		if p[x] != x {
			p[x] = find(p[x])
		}
		return p[x]
	}
	for _, e := range edges {
		pa, pb := find(e[0]), find(e[1])
		if pa == pb {
			return false
		}
		p[pa] = pb
		n--
	}
	return n == 1
}
```

#### JavaScript

```js
/**
 * @param {number} n
 * @param {number[][]} edges
 * @return {boolean}
 */
var validTree = function (n, edges) {
    const p = Array.from({ length: n }, (_, i) => i);
    const find = x => {
        if (p[x] !== x) {
            p[x] = find(p[x]);
        }
        return p[x];
    };
    for (const [a, b] of edges) {
        const pa = find(a);
        const pb = find(b);
        if (pa === pb) {
            return false;
        }
        p[pa] = pb;
        --n;
    }
    return n === 1;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：DFS

我们也可以使用深度优先搜索来判断是否存在环。我们可以使用一个数组 $vis$ 来记录访问过的节点，搜索时，我们先将节点标记为已访问，然后遍历与该节点相邻的节点，如果相邻节点已经访问过，则跳过，否则递归访问相邻节点。最后，我们判断是否所有节点都被访问过，如果有未访问过的节点，说明无法构成树，返回 `false`。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是节点数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        def dfs(i: int):
            vis.add(i)
            for j in g[i]:
                if j not in vis:
                    dfs(j)

        if len(edges) != n - 1:
            return False
        g = [[] for _ in range(n)]
        for a, b in edges:
            g[a].append(b)
            g[b].append(a)
        vis = set()
        dfs(0)
        return len(vis) == n
```

#### Java

```java
class Solution {
    private List<Integer>[] g;
    private Set<Integer> vis = new HashSet<>();

    public boolean validTree(int n, int[][] edges) {
        if (edges.length != n - 1) {
            return false;
        }
        g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (var e : edges) {
            int a = e[0], b = e[1];
            g[a].add(b);
            g[b].add(a);
        }
        dfs(0);
        return vis.size() == n;
    }

    private void dfs(int i) {
        vis.add(i);
        for (int j : g[i]) {
            if (!vis.contains(j)) {
                dfs(j);
            }
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) {
            return false;
        }
        vector<int> g[n];
        vector<int> vis(n);
        function<void(int)> dfs = [&](int i) {
            vis[i] = true;
            --n;
            for (int j : g[i]) {
                if (!vis[j]) {
                    dfs(j);
                }
            }
        };
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        dfs(0);
        return n == 0;
    }
};
```

#### Go

```go
func validTree(n int, edges [][]int) bool {
	if len(edges) != n-1 {
		return false
	}
	g := make([][]int, n)
	vis := make([]bool, n)
	for _, e := range edges {
		a, b := e[0], e[1]
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}
	var dfs func(int)
	dfs = func(i int) {
		vis[i] = true
		n--
		for _, j := range g[i] {
			if !vis[j] {
				dfs(j)
			}
		}
	}
	dfs(0)
	return n == 0
}
```

#### JavaScript

```js
/**
 * @param {number} n
 * @param {number[][]} edges
 * @return {boolean}
 */
var validTree = function (n, edges) {
    if (edges.length !== n - 1) {
        return false;
    }
    const g = Array.from({ length: n }, () => []);
    const vis = Array.from({ length: n }, () => false);
    for (const [a, b] of edges) {
        g[a].push(b);
        g[b].push(a);
    }
    const dfs = i => {
        vis[i] = true;
        --n;
        for (const j of g[i]) {
            if (!vis[j]) {
                dfs(j);
            }
        }
    };
    dfs(0);
    return n === 0;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [262. 行程和用户](https://leetcode.cn/problems/trips-and-users){#262}

{{< tabs "262" >}}

{{% tab "python" %}}
```python
import pandas as pd


def trips_and_users(trips: pd.DataFrame, users: pd.DataFrame) -> pd.DataFrame:
    # 1) temporal filtering
    trips = trips[trips["request_at"].between("2013-10-01", "2013-10-03")].rename(
        columns={"request_at": "Day"}
    )

    # 2) filtering based not banned
    # 2.1) mappning the column 'banned' to `client_id` and `driver_id`
    df_client = (
        pd.merge(trips, users, left_on="client_id", right_on="users_id", how="left")
        .drop(["users_id", "role"], axis=1)
        .rename(columns={"banned": "banned_client"})
    )
    df_driver = (
        pd.merge(trips, users, left_on="driver_id", right_on="users_id", how="left")
        .drop(["users_id", "role"], axis=1)
        .rename(columns={"banned": "banned_driver"})
    )
    df = pd.merge(
        df_client,
        df_driver,
        left_on=["id", "driver_id", "client_id", "city_id", "status", "Day"],
        right_on=["id", "driver_id", "client_id", "city_id", "status", "Day"],
        how="left",
    )
    # 2.2) filtering based on not banned
    df = df[(df["banned_client"] == "No") & (df["banned_driver"] == "No")]

    # 3) counting the cancelled and total trips per day
    df["status_cancelled"] = df["status"].str.contains("cancelled")
    df = df[["Day", "status_cancelled"]]
    df = df.groupby("Day").agg(
        {"status_cancelled": [("total_cancelled", "sum"), ("total", "count")]}
    )
    df.columns = df.columns.droplevel()
    df = df.reset_index()

    # 4) calculating the ratio
    df["Cancellation Rate"] = (df["total_cancelled"] / df["total"]).round(2)
    return df[["Day", "Cancellation Rate"]]
```
{{% /tab %}}
{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT
    request_at AS Day,
    ROUND(AVG(status != 'completed'), 2) AS 'Cancellation Rate'
FROM
    Trips AS t
    JOIN Users AS u1 ON (t.client_id = u1.users_id AND u1.banned = 'No')
    JOIN Users AS u2 ON (t.driver_id = u2.users_id AND u2.banned = 'No')
WHERE request_at BETWEEN '2013-10-01' AND '2013-10-03'
GROUP BY request_at;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

表：<code>Trips</code>

<div class="original__bRMd">
<div>
<pre>
+-------------+----------+
| Column Name | Type     |
+-------------+----------+
| id          | int      |
| client_id   | int      |
| driver_id   | int      |
| city_id     | int      |
| status      | enum     |
| request_at  | varchar  |     
+-------------+----------+
id 是这张表的主键（具有唯一值的列）。
这张表中存所有出租车的行程信息。每段行程有唯一 id ，其中 client_id 和 driver_id 是 Users 表中 users_id 的外键。
status 是一个表示行程状态的枚举类型，枚举成员为(‘completed’, ‘cancelled_by_driver’, ‘cancelled_by_client’) 。
</pre>

<div class="original__bRMd">
<div>
<p>表：<code>Users</code></p>
</div>
</div>

<pre>
+-------------+----------+
| Column Name | Type     |
+-------------+----------+
| users_id    | int      |
| banned      | enum     |
| role        | enum     |
+-------------+----------+
users_id 是这张表的主键（具有唯一值的列）。
这张表中存所有用户，每个用户都有一个唯一的 users_id ，role 是一个表示用户身份的枚举类型，枚举成员为 (‘client’, ‘driver’, ‘partner’) 。
banned 是一个表示用户是否被禁止的枚举类型，枚举成员为 (‘Yes’, ‘No’) 。
</pre>

<p><strong>取消率</strong> 的计算方式如下：(被司机或乘客取消的非禁止用户生成的订单数量) / (非禁止用户生成的订单总数)。</p>

<p>编写解决方案找出&nbsp;<code>"2013-10-01"</code><strong>&nbsp;</strong>至&nbsp;<code>"2013-10-03"</code><strong>&nbsp;</strong>期间有&nbsp;<strong>至少&nbsp;</strong>一次行程的非禁止用户（<strong>乘客和司机都必须未被禁止</strong>）的 <strong>取消率</strong>。非禁止用户即 banned 为 No 的用户，禁止用户即 banned 为 Yes 的用户。其中取消率 <code>Cancellation Rate</code> 需要四舍五入保留 <strong>两位小数</strong> 。</p>

<p>返回结果表中的数据 <strong>无顺序要求</strong> 。</p>

<p>结果格式如下例所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong> 
Trips 表：
+----+-----------+-----------+---------+---------------------+------------+
| id | client_id | driver_id | city_id | status              | request_at |
+----+-----------+-----------+---------+---------------------+------------+
| 1  | 1         | 10        | 1       | completed           | 2013-10-01 |
| 2  | 2         | 11        | 1       | cancelled_by_driver | 2013-10-01 |
| 3  | 3         | 12        | 6       | completed           | 2013-10-01 |
| 4  | 4         | 13        | 6       | cancelled_by_client | 2013-10-01 |
| 5  | 1         | 10        | 1       | completed           | 2013-10-02 |
| 6  | 2         | 11        | 6       | completed           | 2013-10-02 |
| 7  | 3         | 12        | 6       | completed           | 2013-10-02 |
| 8  | 2         | 12        | 12      | completed           | 2013-10-03 |
| 9  | 3         | 10        | 12      | completed           | 2013-10-03 |
| 10 | 4         | 13        | 12      | cancelled_by_driver | 2013-10-03 |
+----+-----------+-----------+---------+---------------------+------------+
Users 表：
+----------+--------+--------+
| users_id | banned | role   |
+----------+--------+--------+
| 1        | No     | client |
| 2        | Yes    | client |
| 3        | No     | client |
| 4        | No     | client |
| 10       | No     | driver |
| 11       | No     | driver |
| 12       | No     | driver |
| 13       | No     | driver |
+----------+--------+--------+
<strong>输出：</strong>
+------------+-------------------+
| Day        | Cancellation Rate |
+------------+-------------------+
| 2013-10-01 | 0.33              |
| 2013-10-02 | 0.00              |
| 2013-10-03 | 0.50              |
+------------+-------------------+
<strong>解释：</strong>
2013-10-01：
  - 共有 4 条请求，其中 2 条取消。
  - 然而，id=2 的请求是由禁止用户（user_id=2）发出的，所以计算时应当忽略它。
  - 因此，总共有 3 条非禁止请求参与计算，其中 1 条取消。
  - 取消率为 (1 / 3) = 0.33
2013-10-02：
  - 共有 3 条请求，其中 0 条取消。
  - 然而，id=6 的请求是由禁止用户发出的，所以计算时应当忽略它。
  - 因此，总共有 2 条非禁止请求参与计算，其中 0 条取消。
  - 取消率为 (0 / 2) = 0.00
2013-10-03：
  - 共有 3 条请求，其中 1 条取消。
  - 然而，id=8 的请求是由禁止用户发出的，所以计算时应当忽略它。
  - 因此，总共有 2 条非禁止请求参与计算，其中 1 条取消。
  - 取消率为 (1 / 2) = 0.50
</pre>
</div>
</div>

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
import pandas as pd


def trips_and_users(trips: pd.DataFrame, users: pd.DataFrame) -> pd.DataFrame:
    # 1) temporal filtering
    trips = trips[trips["request_at"].between("2013-10-01", "2013-10-03")].rename(
        columns={"request_at": "Day"}
    )

    # 2) filtering based not banned
    # 2.1) mappning the column 'banned' to `client_id` and `driver_id`
    df_client = (
        pd.merge(trips, users, left_on="client_id", right_on="users_id", how="left")
        .drop(["users_id", "role"], axis=1)
        .rename(columns={"banned": "banned_client"})
    )
    df_driver = (
        pd.merge(trips, users, left_on="driver_id", right_on="users_id", how="left")
        .drop(["users_id", "role"], axis=1)
        .rename(columns={"banned": "banned_driver"})
    )
    df = pd.merge(
        df_client,
        df_driver,
        left_on=["id", "driver_id", "client_id", "city_id", "status", "Day"],
        right_on=["id", "driver_id", "client_id", "city_id", "status", "Day"],
        how="left",
    )
    # 2.2) filtering based on not banned
    df = df[(df["banned_client"] == "No") & (df["banned_driver"] == "No")]

    # 3) counting the cancelled and total trips per day
    df["status_cancelled"] = df["status"].str.contains("cancelled")
    df = df[["Day", "status_cancelled"]]
    df = df.groupby("Day").agg(
        {"status_cancelled": [("total_cancelled", "sum"), ("total", "count")]}
    )
    df.columns = df.columns.droplevel()
    df = df.reset_index()

    # 4) calculating the ratio
    df["Cancellation Rate"] = (df["total_cancelled"] / df["total"]).round(2)
    return df[["Day", "Cancellation Rate"]]
```

#### MySQL

```sql
# Write your MySQL query statement below
SELECT
    request_at AS Day,
    ROUND(AVG(status != 'completed'), 2) AS 'Cancellation Rate'
FROM
    Trips AS t
    JOIN Users AS u1 ON (t.client_id = u1.users_id AND u1.banned = 'No')
    JOIN Users AS u2 ON (t.driver_id = u2.users_id AND u2.banned = 'No')
WHERE request_at BETWEEN '2013-10-01' AND '2013-10-03'
GROUP BY request_at;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [263. 丑数](https://leetcode.cn/problems/ugly-number){#263}

{{< tabs "263" >}}

{{% tab "python" %}}
```python
class Solution:
    def isUgly(self, n: int) -> bool:
        if n < 1:
            return False
        for x in [2, 3, 5]:
            while n % x == 0:
                n //= x
        return n == 1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean isUgly(int n) {
        if (n < 1) return false;
        while (n % 2 == 0) {
            n /= 2;
        }
        while (n % 3 == 0) {
            n /= 3;
        }
        while (n % 5 == 0) {
            n /= 5;
        }
        return n == 1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool isUgly(int n) {
        if (n < 1) return false;
        while (n % 2 == 0) {
            n /= 2;
        }
        while (n % 3 == 0) {
            n /= 3;
        }
        while (n % 5 == 0) {
            n /= 5;
        }
        return n == 1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func isUgly(n int) bool {
	if n < 1 {
		return false
	}
	for _, x := range []int{2, 3, 5} {
		for n%x == 0 {
			n /= x
		}
	}
	return n == 1
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number} n
 * @return {boolean}
 */
var isUgly = function (n) {
    if (n < 1) return false;
    while (n % 2 === 0) {
        n /= 2;
    }
    while (n % 3 === 0) {
        n /= 3;
    }
    while (n % 5 === 0) {
        n /= 5;
    }
    return n === 1;
};
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param Integer $n
     * @return Boolean
     */
    function isUgly($n) {
        while ($n) {
            if ($n % 2 == 0) {
                $n = $n / 2;
            } elseif ($n % 3 == 0) {
                $n = $n / 3;
            } elseif ($n % 5 == 0) {
                $n = $n / 5;
            } else {
                break;
            }
        }
        return $n == 1;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p><strong>丑数 </strong>就是只包含质因数&nbsp;<code>2</code>、<code>3</code> 和 <code>5</code>&nbsp;的&nbsp;<em>正&nbsp;</em>整数。</p>

<p>给你一个整数 <code>n</code> ，请你判断 <code>n</code> 是否为 <strong>丑数</strong> 。如果是，返回 <code>true</code> ；否则，返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 6
<strong>输出：</strong>true
<strong>解释：</strong>6 = 2 × 3</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 1
<strong>输出：</strong>true
<strong>解释：</strong>1 没有质因数。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 14
<strong>输出：</strong>false
<strong>解释：</strong>14 不是丑数，因为它包含了另外一个质因数&nbsp;<code>7 </code>。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>-2<sup>31</sup> &lt;= n &lt;= 2<sup>31</sup> - 1</code></li>
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
    def isUgly(self, n: int) -> bool:
        if n < 1:
            return False
        for x in [2, 3, 5]:
            while n % x == 0:
                n //= x
        return n == 1
```

#### Java

```java
class Solution {
    public boolean isUgly(int n) {
        if (n < 1) return false;
        while (n % 2 == 0) {
            n /= 2;
        }
        while (n % 3 == 0) {
            n /= 3;
        }
        while (n % 5 == 0) {
            n /= 5;
        }
        return n == 1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool isUgly(int n) {
        if (n < 1) return false;
        while (n % 2 == 0) {
            n /= 2;
        }
        while (n % 3 == 0) {
            n /= 3;
        }
        while (n % 5 == 0) {
            n /= 5;
        }
        return n == 1;
    }
};
```

#### Go

```go
func isUgly(n int) bool {
	if n < 1 {
		return false
	}
	for _, x := range []int{2, 3, 5} {
		for n%x == 0 {
			n /= x
		}
	}
	return n == 1
}
```

#### JavaScript

```js
/**
 * @param {number} n
 * @return {boolean}
 */
var isUgly = function (n) {
    if (n < 1) return false;
    while (n % 2 === 0) {
        n /= 2;
    }
    while (n % 3 === 0) {
        n /= 3;
    }
    while (n % 5 === 0) {
        n /= 5;
    }
    return n === 1;
};
```

#### PHP

```php
class Solution {
    /**
     * @param Integer $n
     * @return Boolean
     */
    function isUgly($n) {
        while ($n) {
            if ($n % 2 == 0) {
                $n = $n / 2;
            } elseif ($n % 3 == 0) {
                $n = $n / 3;
            } elseif ($n % 5 == 0) {
                $n = $n / 5;
            } else {
                break;
            }
        }
        return $n == 1;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [264. 丑数 II](https://leetcode.cn/problems/ugly-number-ii){#264}

{{< tabs "264" >}}

{{% tab "python" %}}
```python
class Solution:
    def nthUglyNumber(self, n: int) -> int:
        dp = [1] * n
        p2 = p3 = p5 = 0
        for i in range(1, n):
            next2, next3, next5 = dp[p2] * 2, dp[p3] * 3, dp[p5] * 5
            dp[i] = min(next2, next3, next5)
            if dp[i] == next2:
                p2 += 1
            if dp[i] == next3:
                p3 += 1
            if dp[i] == next5:
                p5 += 1
        return dp[-1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int nthUglyNumber(int n) {
        int[] dp = new int[n];
        dp[0] = 1;
        int p2 = 0, p3 = 0, p5 = 0;
        for (int i = 1; i < n; ++i) {
            int next2 = dp[p2] * 2, next3 = dp[p3] * 3, next5 = dp[p5] * 5;
            dp[i] = Math.min(next2, Math.min(next3, next5));
            if (dp[i] == next2) ++p2;
            if (dp[i] == next3) ++p3;
            if (dp[i] == next5) ++p5;
        }
        return dp[n - 1];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0] = 1;
        int p2 = 0, p3 = 0, p5 = 0;
        for (int i = 1; i < n; ++i) {
            int next2 = dp[p2] * 2, next3 = dp[p3] * 3, next5 = dp[p5] * 5;
            dp[i] = min(next2, min(next3, next5));
            if (dp[i] == next2) ++p2;
            if (dp[i] == next3) ++p3;
            if (dp[i] == next5) ++p5;
        }
        return dp[n - 1];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func nthUglyNumber(n int) int {
	dp := make([]int, n)
	dp[0] = 1
	p2, p3, p5 := 0, 0, 0
	for i := 1; i < n; i++ {
		next2, next3, next5 := dp[p2]*2, dp[p3]*3, dp[p5]*5
		dp[i] = min(next2, min(next3, next5))
		if dp[i] == next2 {
			p2++
		}
		if dp[i] == next3 {
			p3++
		}
		if dp[i] == next5 {
			p5++
		}
	}
	return dp[n-1]
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number} n
 * @return {number}
 */
var nthUglyNumber = function (n) {
    let dp = [1];
    let p2 = 0,
        p3 = 0,
        p5 = 0;
    for (let i = 1; i < n; ++i) {
        const next2 = dp[p2] * 2,
            next3 = dp[p3] * 3,
            next5 = dp[p5] * 5;
        dp[i] = Math.min(next2, Math.min(next3, next5));
        if (dp[i] == next2) ++p2;
        if (dp[i] == next3) ++p3;
        if (dp[i] == next5) ++p5;
        dp.push(dp[i]);
    }
    return dp[n - 1];
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int NthUglyNumber(int n) {
        int[] dp = new int[n];
        dp[0] = 1;
        int p2 = 0, p3 = 0, p5 = 0;
        for (int i = 1; i < n; ++i) {
            int next2 = dp[p2] * 2, next3 = dp[p3] * 3, next5 = dp[p5] * 5;
            dp[i] = Math.Min(next2, Math.Min(next3, next5));
            if (dp[i] == next2) {
                ++p2;
            }
            if (dp[i] == next3) {
                ++p3;
            }
            if (dp[i] == next5) {
                ++p5;
            }
        }
        return dp[n - 1];
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数 <code>n</code> ，请你找出并返回第 <code>n</code> 个 <strong>丑数</strong> 。</p>

<p><strong>丑数 </strong>就是质因子只包含&nbsp;<code>2</code>、<code>3</code> 和&nbsp;<code>5</code>&nbsp;的正整数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 10
<strong>输出：</strong>12
<strong>解释：</strong>[1, 2, 3, 4, 5, 6, 8, 9, 10, 12] 是由前 10 个丑数组成的序列。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 1
<strong>输出：</strong>1
<strong>解释：</strong>1 通常被视为丑数。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 1690</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：优先队列（最小堆）

初始时，将第一个丑数 $1$ 加入堆。每次取出堆顶元素 $x$，由于 $2x$, $3x$, $5x$ 也是丑数，因此将它们加入堆中。为了避免重复元素，可以用哈希表 $vis$ 去重。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def nthUglyNumber(self, n: int) -> int:
        h = [1]
        vis = {1}
        ans = 1
        for _ in range(n):
            ans = heappop(h)
            for v in [2, 3, 5]:
                nxt = ans * v
                if nxt not in vis:
                    vis.add(nxt)
                    heappush(h, nxt)
        return ans
```

#### Java

```java
class Solution {
    public int nthUglyNumber(int n) {
        Set<Long> vis = new HashSet<>();
        PriorityQueue<Long> q = new PriorityQueue<>();
        int[] f = new int[] {2, 3, 5};
        q.offer(1L);
        vis.add(1L);
        long ans = 0;
        while (n-- > 0) {
            ans = q.poll();
            for (int v : f) {
                long next = ans * v;
                if (vis.add(next)) {
                    q.offer(next);
                }
            }
        }
        return (int) ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long, vector<long>, greater<long>> q;
        q.push(1l);
        unordered_set<long> vis{{1l}};
        long ans = 1;
        vector<int> f = {2, 3, 5};
        while (n--) {
            ans = q.top();
            q.pop();
            for (int& v : f) {
                long nxt = ans * v;
                if (!vis.count(nxt)) {
                    vis.insert(nxt);
                    q.push(nxt);
                }
            }
        }
        return (int) ans;
    }
};
```

#### Go

```go
func nthUglyNumber(n int) int {
	h := IntHeap([]int{1})
	heap.Init(&h)
	ans := 1
	vis := map[int]bool{1: true}
	for n > 0 {
		ans = heap.Pop(&h).(int)
		for _, v := range []int{2, 3, 5} {
			nxt := ans * v
			if !vis[nxt] {
				vis[nxt] = true
				heap.Push(&h, nxt)
			}
		}
		n--
	}
	return ans
}

type IntHeap []int

func (h IntHeap) Len() int           { return len(h) }
func (h IntHeap) Less(i, j int) bool { return h[i] < h[j] }
func (h IntHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *IntHeap) Push(x any) {
	*h = append(*h, x.(int))
}
func (h *IntHeap) Pop() any {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}
```

#### JavaScript

```js
/**
 * @param {number} n
 * @return {number}
 */
var nthUglyNumber = function (n) {
    let dp = [1];
    let p2 = 0,
        p3 = 0,
        p5 = 0;
    for (let i = 1; i < n; ++i) {
        const next2 = dp[p2] * 2,
            next3 = dp[p3] * 3,
            next5 = dp[p5] * 5;
        dp[i] = Math.min(next2, Math.min(next3, next5));
        if (dp[i] == next2) ++p2;
        if (dp[i] == next3) ++p3;
        if (dp[i] == next5) ++p5;
        dp.push(dp[i]);
    }
    return dp[n - 1];
};
```

#### C#

```cs
public class Solution {
    public int NthUglyNumber(int n) {
        int[] dp = new int[n];
        dp[0] = 1;
        int p2 = 0, p3 = 0, p5 = 0;
        for (int i = 1; i < n; ++i) {
            int next2 = dp[p2] * 2, next3 = dp[p3] * 3, next5 = dp[p5] * 5;
            dp[i] = Math.Min(next2, Math.Min(next3, next5));
            if (dp[i] == next2) {
                ++p2;
            }
            if (dp[i] == next3) {
                ++p3;
            }
            if (dp[i] == next5) {
                ++p5;
            }
        }
        return dp[n - 1];
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：动态规划

定义数组 $dp$，其中 $dp[i-1]$ 表示第 $i$ 个丑数，那么第 $n$ 个丑数就是 $dp[n - 1]$。最小的丑数是 $1$，所以 $dp[0]=1$。

定义 $3$ 个指针 $p_2$, $p_3$ 和 $p_5$，表示下一个丑数是当前指针指向的丑数乘以对应的质因数。初始时，三个指针的值都指向 $0$。

当 $i$ 在 $[1,2..n-1]$ 范围内，我们更新 $dp[i]=\min(dp[p_2] \times 2, dp[p_3] \times 3, dp[p_5] \times 5)$，然后分别比较 $dp[i]$ 与 $dp[p_2] \times 2$, $dp[p_3] \times 3$, $dp[p_5] \times 5$ 是否相等，若是，则对应的指针加 $1$。

最后返回 $dp[n - 1]$ 即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def nthUglyNumber(self, n: int) -> int:
        dp = [1] * n
        p2 = p3 = p5 = 0
        for i in range(1, n):
            next2, next3, next5 = dp[p2] * 2, dp[p3] * 3, dp[p5] * 5
            dp[i] = min(next2, next3, next5)
            if dp[i] == next2:
                p2 += 1
            if dp[i] == next3:
                p3 += 1
            if dp[i] == next5:
                p5 += 1
        return dp[-1]
```

#### Java

```java
class Solution {
    public int nthUglyNumber(int n) {
        int[] dp = new int[n];
        dp[0] = 1;
        int p2 = 0, p3 = 0, p5 = 0;
        for (int i = 1; i < n; ++i) {
            int next2 = dp[p2] * 2, next3 = dp[p3] * 3, next5 = dp[p5] * 5;
            dp[i] = Math.min(next2, Math.min(next3, next5));
            if (dp[i] == next2) ++p2;
            if (dp[i] == next3) ++p3;
            if (dp[i] == next5) ++p5;
        }
        return dp[n - 1];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0] = 1;
        int p2 = 0, p3 = 0, p5 = 0;
        for (int i = 1; i < n; ++i) {
            int next2 = dp[p2] * 2, next3 = dp[p3] * 3, next5 = dp[p5] * 5;
            dp[i] = min(next2, min(next3, next5));
            if (dp[i] == next2) ++p2;
            if (dp[i] == next3) ++p3;
            if (dp[i] == next5) ++p5;
        }
        return dp[n - 1];
    }
};
```

#### Go

```go
func nthUglyNumber(n int) int {
	dp := make([]int, n)
	dp[0] = 1
	p2, p3, p5 := 0, 0, 0
	for i := 1; i < n; i++ {
		next2, next3, next5 := dp[p2]*2, dp[p3]*3, dp[p5]*5
		dp[i] = min(next2, min(next3, next5))
		if dp[i] == next2 {
			p2++
		}
		if dp[i] == next3 {
			p3++
		}
		if dp[i] == next5 {
			p5++
		}
	}
	return dp[n-1]
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [265. 粉刷房子 II 🔒](https://leetcode.cn/problems/paint-house-ii){#265}

{{< tabs "265" >}}

{{% tab "python" %}}
```python
class Solution:
    def minCostII(self, costs: List[List[int]]) -> int:
        n, k = len(costs), len(costs[0])
        f = costs[0][:]
        for i in range(1, n):
            g = costs[i][:]
            for j in range(k):
                t = min(f[h] for h in range(k) if h != j)
                g[j] += t
            f = g
        return min(f)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minCostII(int[][] costs) {
        int n = costs.length, k = costs[0].length;
        int[] f = costs[0].clone();
        for (int i = 1; i < n; ++i) {
            int[] g = costs[i].clone();
            for (int j = 0; j < k; ++j) {
                int t = Integer.MAX_VALUE;
                for (int h = 0; h < k; ++h) {
                    if (h != j) {
                        t = Math.min(t, f[h]);
                    }
                }
                g[j] += t;
            }
            f = g;
        }
        return Arrays.stream(f).min().getAsInt();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size(), k = costs[0].size();
        vector<int> f = costs[0];
        for (int i = 1; i < n; ++i) {
            vector<int> g = costs[i];
            for (int j = 0; j < k; ++j) {
                int t = INT_MAX;
                for (int h = 0; h < k; ++h) {
                    if (h != j) {
                        t = min(t, f[h]);
                    }
                }
                g[j] += t;
            }
            f = move(g);
        }
        return *min_element(f.begin(), f.end());
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minCostII(costs [][]int) int {
	n, k := len(costs), len(costs[0])
	f := cp(costs[0])
	for i := 1; i < n; i++ {
		g := cp(costs[i])
		for j := 0; j < k; j++ {
			t := math.MaxInt32
			for h := 0; h < k; h++ {
				if h != j && t > f[h] {
					t = f[h]
				}
			}
			g[j] += t
		}
		f = g
	}
	return slices.Min(f)
}

func cp(arr []int) []int {
	t := make([]int, len(arr))
	copy(t, arr)
	return t
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>假如有一排房子共有&nbsp;<code>n</code>&nbsp;幢，每个房子可以被粉刷成 <code>k</code>&nbsp;种颜色中的一种。房子粉刷成不同颜色的花费成本也是不同的。你需要粉刷所有的房子并且使其相邻的两个房子颜色不能相同。</p>

<p>每个房子粉刷成不同颜色的花费以一个 <code>n x k</code> 的矩阵表示。</p>

<ul>
	<li>例如，<code>costs[0][0]</code> 表示第 <code>0</code>&nbsp;幢房子粉刷成 <code>0</code> 号颜色的成本；<code>costs[1][2]</code>&nbsp;表示第 <code>1</code> 幢房子粉刷成 <code>2</code> 号颜色的成本，以此类推。</li>
</ul>

<p>返回 <em>粉刷完所有房子的最低成本</em>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入: </strong>costs = [[1,5,3],[2,9,4]]
<strong>输出: </strong>5
<strong>解释: 
</strong>将房子 0 刷成 0 号颜色，房子 1 刷成 2 号颜色。花费: 1 + 4 = 5; 
或者将 房子 0 刷成 2 号颜色，房子 1 刷成 0 号颜色。花费: 3 + 2 = 5. </pre>

<p><strong>示例&nbsp;<strong>2:</strong></strong></p>

<pre>
<strong>输入:</strong> costs = [[1,3],[2,4]]
<strong>输出:</strong> 5
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>costs.length == n</code></li>
	<li><code>costs[i].length == k</code></li>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>2 &lt;= k &lt;= 20</code></li>
	<li><code>1 &lt;= costs[i][j] &lt;= 20</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>您能否在&nbsp;<code>O(nk)</code> 的时间复杂度下解决此问题？</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

定义 $f[i][j]$ 表示粉刷前 $i$ 个房子，且最后一个房子被粉刷成第 $j$ 种颜色的最小花费。答案为 $\min_{0 \leq j < k} f[n][j]$。

对于 $f[i][j]$，可以从 $f[i - 1][j']$ 转移而来，其中 $j' \neq j$。因此，可以得到状态转移方程：

$$
f[i][j] = \min_{0 \leq j' < k, j' \neq j} f[i - 1][j'] + costs[i - 1][j]
$$

由于 $f[i][j]$ 只与 $f[i - 1][j']$ 有关，因此可以使用滚动数组优化空间复杂度。

时间复杂度 $O(n \times k^2)$，空间复杂度 $O(k)$。其中 $n$ 和 $k$ 分别为房子数量和颜色数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minCostII(self, costs: List[List[int]]) -> int:
        n, k = len(costs), len(costs[0])
        f = costs[0][:]
        for i in range(1, n):
            g = costs[i][:]
            for j in range(k):
                t = min(f[h] for h in range(k) if h != j)
                g[j] += t
            f = g
        return min(f)
```

#### Java

```java
class Solution {
    public int minCostII(int[][] costs) {
        int n = costs.length, k = costs[0].length;
        int[] f = costs[0].clone();
        for (int i = 1; i < n; ++i) {
            int[] g = costs[i].clone();
            for (int j = 0; j < k; ++j) {
                int t = Integer.MAX_VALUE;
                for (int h = 0; h < k; ++h) {
                    if (h != j) {
                        t = Math.min(t, f[h]);
                    }
                }
                g[j] += t;
            }
            f = g;
        }
        return Arrays.stream(f).min().getAsInt();
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size(), k = costs[0].size();
        vector<int> f = costs[0];
        for (int i = 1; i < n; ++i) {
            vector<int> g = costs[i];
            for (int j = 0; j < k; ++j) {
                int t = INT_MAX;
                for (int h = 0; h < k; ++h) {
                    if (h != j) {
                        t = min(t, f[h]);
                    }
                }
                g[j] += t;
            }
            f = move(g);
        }
        return *min_element(f.begin(), f.end());
    }
};
```

#### Go

```go
func minCostII(costs [][]int) int {
	n, k := len(costs), len(costs[0])
	f := cp(costs[0])
	for i := 1; i < n; i++ {
		g := cp(costs[i])
		for j := 0; j < k; j++ {
			t := math.MaxInt32
			for h := 0; h < k; h++ {
				if h != j && t > f[h] {
					t = f[h]
				}
			}
			g[j] += t
		}
		f = g
	}
	return slices.Min(f)
}

func cp(arr []int) []int {
	t := make([]int, len(arr))
	copy(t, arr)
	return t
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [266. 回文排列 🔒](https://leetcode.cn/problems/palindrome-permutation){#266}

{{< tabs "266" >}}

{{% tab "python" %}}
```python
class Solution:
    def canPermutePalindrome(self, s: str) -> bool:
        return sum(v & 1 for v in Counter(s).values()) < 2
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean canPermutePalindrome(String s) {
        int[] cnt = new int[26];
        for (char c : s.toCharArray()) {
            ++cnt[c - 'a'];
        }
        int odd = 0;
        for (int x : cnt) {
            odd += x & 1;
        }
        return odd < 2;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool canPermutePalindrome(string s) {
        vector<int> cnt(26);
        for (char& c : s) {
            ++cnt[c - 'a'];
        }
        int odd = 0;
        for (int x : cnt) {
            odd += x & 1;
        }
        return odd < 2;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func canPermutePalindrome(s string) bool {
	cnt := [26]int{}
	for _, c := range s {
		cnt[c-'a']++
	}
	odd := 0
	for _, x := range cnt {
		odd += x & 1
	}
	return odd < 2
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function canPermutePalindrome(s: string): boolean {
    const cnt: number[] = Array(26).fill(0);
    for (const c of s) {
        ++cnt[c.charCodeAt(0) - 97];
    }
    return cnt.filter(c => c % 2 === 1).length < 2;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {string} s
 * @return {boolean}
 */
var canPermutePalindrome = function (s) {
    const cnt = new Map();
    for (const c of s) {
        cnt.set(c, (cnt.get(c) || 0) + 1);
    }
    return [...cnt.values()].filter(v => v % 2 === 1).length < 2;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串 <code>s</code> ，如果该字符串的某个排列是 <span data-keyword="palindrome-string">回文串</span> ，则返回 <code>true</code> ；否则，返回<em> </em><code>false</code><em> </em>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "code"
<strong>输出：</strong>false
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "aab"
<strong>输出：</strong>true
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "carerac"
<strong>输出：</strong>true
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 5000</code></li>
	<li><code>s</code> 仅由小写英文字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数

如果一个字符串是回文串，那么至多只有一个字符出现奇数次数，其余字符都出现偶数次数。因此我们只需要统计每个字符出现的次数，然后判断是否满足这个条件即可。

时间复杂度 $O(n)$，空间复杂度 $O(|\Sigma|)$。其中 $n$ 是字符串的长度，而 $|\Sigma|$ 是字符集的大小，本题中字符集为小写字母，因此 $|\Sigma|=26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def canPermutePalindrome(self, s: str) -> bool:
        return sum(v & 1 for v in Counter(s).values()) < 2
```

#### Java

```java
class Solution {
    public boolean canPermutePalindrome(String s) {
        int[] cnt = new int[26];
        for (char c : s.toCharArray()) {
            ++cnt[c - 'a'];
        }
        int odd = 0;
        for (int x : cnt) {
            odd += x & 1;
        }
        return odd < 2;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool canPermutePalindrome(string s) {
        vector<int> cnt(26);
        for (char& c : s) {
            ++cnt[c - 'a'];
        }
        int odd = 0;
        for (int x : cnt) {
            odd += x & 1;
        }
        return odd < 2;
    }
};
```

#### Go

```go
func canPermutePalindrome(s string) bool {
	cnt := [26]int{}
	for _, c := range s {
		cnt[c-'a']++
	}
	odd := 0
	for _, x := range cnt {
		odd += x & 1
	}
	return odd < 2
}
```

#### TypeScript

```ts
function canPermutePalindrome(s: string): boolean {
    const cnt: number[] = Array(26).fill(0);
    for (const c of s) {
        ++cnt[c.charCodeAt(0) - 97];
    }
    return cnt.filter(c => c % 2 === 1).length < 2;
}
```

#### JavaScript

```js
/**
 * @param {string} s
 * @return {boolean}
 */
var canPermutePalindrome = function (s) {
    const cnt = new Map();
    for (const c of s) {
        cnt.set(c, (cnt.get(c) || 0) + 1);
    }
    return [...cnt.values()].filter(v => v % 2 === 1).length < 2;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [267. 回文排列 II 🔒](https://leetcode.cn/problems/palindrome-permutation-ii){#267}

{{< tabs "267" >}}

{{% tab "python" %}}
```python
class Solution:
    def generatePalindromes(self, s: str) -> List[str]:
        def dfs(t):
            if len(t) == len(s):
                ans.append(t)
                return
            for c, v in cnt.items():
                if v > 1:
                    cnt[c] -= 2
                    dfs(c + t + c)
                    cnt[c] += 2

        cnt = Counter(s)
        mid = ''
        for c, v in cnt.items():
            if v & 1:
                if mid:
                    return []
                mid = c
                cnt[c] -= 1
        ans = []
        dfs(mid)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private List<String> ans = new ArrayList<>();
    private int[] cnt = new int[26];
    private int n;

    public List<String> generatePalindromes(String s) {
        n = s.length();
        for (char c : s.toCharArray()) {
            ++cnt[c - 'a'];
        }
        String mid = "";
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] % 2 == 1) {
                if (!"".equals(mid)) {
                    return ans;
                }
                mid = String.valueOf((char) (i + 'a'));
            }
        }
        dfs(mid);
        return ans;
    }

    private void dfs(String t) {
        if (t.length() == n) {
            ans.add(t);
            return;
        }
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] > 1) {
                String c = String.valueOf((char) (i + 'a'));
                cnt[i] -= 2;
                dfs(c + t + c);
                cnt[i] += 2;
            }
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int n;
    vector<string> ans;
    unordered_map<char, int> cnt;

    vector<string> generatePalindromes(string s) {
        n = s.size();
        for (char c : s) ++cnt[c];
        string mid = "";
        for (auto& [k, v] : cnt) {
            if (v & 1) {
                if (mid != "") {
                    return ans;
                }
                mid += k;
            }
        }
        dfs(mid);
        return ans;
    }

    void dfs(string t) {
        if (t.size() == n) {
            ans.push_back(t);
            return;
        }
        for (auto& [k, v] : cnt) {
            if (v > 1) {
                v -= 2;
                dfs(k + t + k);
                v += 2;
            }
        }
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func generatePalindromes(s string) []string {
	cnt := map[byte]int{}
	for i := range s {
		cnt[s[i]]++
	}
	mid := ""
	ans := []string{}
	for k, v := range cnt {
		if v%2 == 1 {
			if mid != "" {
				return ans
			}
			mid = string(k)
		}
	}
	var dfs func(t string)
	dfs = func(t string) {
		if len(t) == len(s) {
			ans = append(ans, t)
			return
		}
		for k, v := range cnt {
			if v > 1 {
				cnt[k] -= 2
				c := string(k)
				dfs(c + t + c)
				cnt[k] += 2
			}
		}
	}
	dfs(mid)
	return ans
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个字符串 <code>s</code>&nbsp;，返回 <em>其重新排列组合后可能构成的所有回文字符串，并去除重复的组合</em>&nbsp;。</p>

<p>你可以按 <strong>任意顺序</strong> 返回答案。如果&nbsp;<code>s</code>&nbsp;不能形成任何回文排列时，则返回一个空列表。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入: </strong>s = <code>"aabb"</code>
<strong>输出: </strong><code>["abba", "baab"]</code></pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入: </strong>s = <code>"abc"</code>
<strong>输出: </strong><code>[]</code>
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<p><meta charset="UTF-8" /></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 16</code></li>
	<li><code>s</code>&nbsp;仅由小写英文字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：回溯

回文排列需要满足至多有一个字符出现奇数次数。若不满足条件，答案提前返回。

找到出现奇数次的字符，作为中间字符（可以为空），分别向两边扩展，构造回文串。若串的长度与原串长度相等，将该串添加到答案中。

时间复杂度 $O(n \times \frac{n}{2}!)$。其中 $n$ 为字符串 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def generatePalindromes(self, s: str) -> List[str]:
        def dfs(t):
            if len(t) == len(s):
                ans.append(t)
                return
            for c, v in cnt.items():
                if v > 1:
                    cnt[c] -= 2
                    dfs(c + t + c)
                    cnt[c] += 2

        cnt = Counter(s)
        mid = ''
        for c, v in cnt.items():
            if v & 1:
                if mid:
                    return []
                mid = c
                cnt[c] -= 1
        ans = []
        dfs(mid)
        return ans
```

#### Java

```java
class Solution {
    private List<String> ans = new ArrayList<>();
    private int[] cnt = new int[26];
    private int n;

    public List<String> generatePalindromes(String s) {
        n = s.length();
        for (char c : s.toCharArray()) {
            ++cnt[c - 'a'];
        }
        String mid = "";
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] % 2 == 1) {
                if (!"".equals(mid)) {
                    return ans;
                }
                mid = String.valueOf((char) (i + 'a'));
            }
        }
        dfs(mid);
        return ans;
    }

    private void dfs(String t) {
        if (t.length() == n) {
            ans.add(t);
            return;
        }
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] > 1) {
                String c = String.valueOf((char) (i + 'a'));
                cnt[i] -= 2;
                dfs(c + t + c);
                cnt[i] += 2;
            }
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    int n;
    vector<string> ans;
    unordered_map<char, int> cnt;

    vector<string> generatePalindromes(string s) {
        n = s.size();
        for (char c : s) ++cnt[c];
        string mid = "";
        for (auto& [k, v] : cnt) {
            if (v & 1) {
                if (mid != "") {
                    return ans;
                }
                mid += k;
            }
        }
        dfs(mid);
        return ans;
    }

    void dfs(string t) {
        if (t.size() == n) {
            ans.push_back(t);
            return;
        }
        for (auto& [k, v] : cnt) {
            if (v > 1) {
                v -= 2;
                dfs(k + t + k);
                v += 2;
            }
        }
    }
};
```

#### Go

```go
func generatePalindromes(s string) []string {
	cnt := map[byte]int{}
	for i := range s {
		cnt[s[i]]++
	}
	mid := ""
	ans := []string{}
	for k, v := range cnt {
		if v%2 == 1 {
			if mid != "" {
				return ans
			}
			mid = string(k)
		}
	}
	var dfs func(t string)
	dfs = func(t string) {
		if len(t) == len(s) {
			ans = append(ans, t)
			return
		}
		for k, v := range cnt {
			if v > 1 {
				cnt[k] -= 2
				c := string(k)
				dfs(c + t + c)
				cnt[k] += 2
			}
		}
	}
	dfs(mid)
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [268. 丢失的数字](https://leetcode.cn/problems/missing-number){#268}

{{< tabs "268" >}}

{{% tab "python" %}}
```python
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums)
        return (1 + n) * n // 2 - sum(nums)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int missingNumber(int[] nums) {
        int n = nums.length;
        int ans = n;
        for (int i = 0; i < n; ++i) {
            ans += i - nums[i];
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
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        return (1 + n) * n / 2 - accumulate(nums.begin(), nums.end(), 0);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func missingNumber(nums []int) (ans int) {
	n := len(nums)
	ans = n
	for i, v := range nums {
		ans += i - v
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function missingNumber(nums: number[]): number {
    const n = nums.length;
    let ans = n;
    for (let i = 0; i < n; ++i) {
        ans += i - nums[i];
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn missing_number(nums: Vec<i32>) -> i32 {
        let n = nums.len() as i32;
        let mut ans = n;
        for (i, &v) in nums.iter().enumerate() {
            ans += (i as i32) - v;
        }
        ans
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var missingNumber = function (nums) {
    const n = nums.length;
    let ans = n;
    for (let i = 0; i < n; ++i) {
        ans += i - nums[i];
    }
    return ans;
};
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function missingNumber($nums) {
        $n = count($nums);
        $sumN = (($n + 1) * $n) / 2;
        for ($i = 0; $i < $n; $i++) {
            $sumN -= $nums[$i];
        }
        return $sumN;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个包含 <code>[0, n]</code>&nbsp;中&nbsp;<code>n</code>&nbsp;个数的数组 <code>nums</code> ，找出 <code>[0, n]</code> 这个范围内没有出现在数组中的那个数。</p>

<ul>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong>nums = [3,0,1]</p>

<p><strong>输出：</strong>2</p>

<p><b>解释：</b><code>n = 3</code>，因为有 3 个数字，所以所有的数字都在范围 <code>[0,3]</code> 内。2 是丢失的数字，因为它没有出现在 <code>nums</code> 中。</p>
</div>

<p><strong>示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong>nums = [0,1]</p>

<p><strong>输出：</strong>2</p>

<p><b>解释：</b><code>n = 2</code>，因为有 2 个数字，所以所有的数字都在范围 <code>[0,2]</code> 内。2 是丢失的数字，因为它没有出现在 <code>nums</code> 中。</p>
</div>

<p><strong>示例 3：</strong></p>

<div class="example-block">
<p><strong>输入：</strong>nums = [9,6,4,2,3,5,7,0,1]</p>

<p><strong>输出：</strong>8</p>

<p><b>解释：</b><code>n = 9</code>，因为有 9 个数字，所以所有的数字都在范围 <code>[0,9]</code> 内。8 是丢失的数字，因为它没有出现在 <code>nums</code> 中。</p>
</div>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= n</code></li>
	<li><code>nums</code> 中的所有数字都 <strong>独一无二</strong></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>你能否实现线性时间复杂度、仅使用额外常数空间的算法解决此问题?</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：位运算

异或运算的性质：

-   任何数和 $0$ 做异或运算，结果仍然是原来的数，即 $x \oplus 0 = x$；
-   任何数和其自身做异或运算，结果是 $0$，即 $x \oplus x = 0$；

因此，我们可以遍历数组，将数字 $[0,..n]$ 与数组中的元素进行异或运算，最后的结果就是缺失的数字。

时间复杂度 $O(n)$，空间复杂度 $O(1)$。其中 $n$ 为数组长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        return reduce(xor, (i ^ v for i, v in enumerate(nums, 1)))
```

#### Java

```java
class Solution {
    public int missingNumber(int[] nums) {
        int n = nums.length;
        int ans = n;
        for (int i = 0; i < n; ++i) {
            ans ^= (i ^ nums[i]);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = n;
        for (int i = 0; i < n; ++i) {
            ans ^= (i ^ nums[i]);
        }
        return ans;
    }
};
```

#### Go

```go
func missingNumber(nums []int) (ans int) {
	n := len(nums)
	ans = n
	for i, v := range nums {
		ans ^= (i ^ v)
	}
	return
}
```

#### TypeScript

```ts
function missingNumber(nums: number[]): number {
    const n = nums.length;
    let ans = n;
    for (let i = 0; i < n; ++i) {
        ans ^= i ^ nums[i];
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn missing_number(nums: Vec<i32>) -> i32 {
        let n = nums.len() as i32;
        let mut ans = n;
        for (i, v) in nums.iter().enumerate() {
            ans ^= (i as i32) ^ v;
        }
        ans
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var missingNumber = function (nums) {
    const n = nums.length;
    let ans = n;
    for (let i = 0; i < n; ++i) {
        ans ^= i ^ nums[i];
    }
    return ans;
};
```

#### PHP

```php
class Solution {
    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function missingNumber($nums) {
        $n = count($nums);
        $sumN = (($n + 1) * $n) / 2;
        for ($i = 0; $i < $n; $i++) {
            $sumN -= $nums[$i];
        }
        return $sumN;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：数学

我们也可以用数学求解。求出 $[0,..n]$ 的和，减去数组中所有数的和，就得到了缺失的数字。

时间复杂度 $O(n)$，其中 $n$ 为数组长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums)
        return (1 + n) * n // 2 - sum(nums)
```

#### Java

```java
class Solution {
    public int missingNumber(int[] nums) {
        int n = nums.length;
        int ans = n;
        for (int i = 0; i < n; ++i) {
            ans += i - nums[i];
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        return (1 + n) * n / 2 - accumulate(nums.begin(), nums.end(), 0);
    }
};
```

#### Go

```go
func missingNumber(nums []int) (ans int) {
	n := len(nums)
	ans = n
	for i, v := range nums {
		ans += i - v
	}
	return
}
```

#### TypeScript

```ts
function missingNumber(nums: number[]): number {
    const n = nums.length;
    let ans = n;
    for (let i = 0; i < n; ++i) {
        ans += i - nums[i];
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn missing_number(nums: Vec<i32>) -> i32 {
        let n = nums.len() as i32;
        let mut ans = n;
        for (i, &v) in nums.iter().enumerate() {
            ans += (i as i32) - v;
        }
        ans
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var missingNumber = function (nums) {
    const n = nums.length;
    let ans = n;
    for (let i = 0; i < n; ++i) {
        ans += i - nums[i];
    }
    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [269. 火星词典 🔒](https://leetcode.cn/problems/alien-dictionary){#269}

{{< tabs "269" >}}

{{% tab "python" %}}
```python
class Solution:
    def alienOrder(self, words: List[str]) -> str:
        g = [[False] * 26 for _ in range(26)]
        s = [False] * 26
        cnt = 0
        n = len(words)
        for i in range(n - 1):
            for c in words[i]:
                if cnt == 26:
                    break
                o = ord(c) - ord('a')
                if not s[o]:
                    cnt += 1
                    s[o] = True
            m = len(words[i])
            for j in range(m):
                if j >= len(words[i + 1]):
                    return ''
                c1, c2 = words[i][j], words[i + 1][j]
                if c1 == c2:
                    continue
                o1, o2 = ord(c1) - ord('a'), ord(c2) - ord('a')
                if g[o2][o1]:
                    return ''
                g[o1][o2] = True
                break
        for c in words[n - 1]:
            if cnt == 26:
                break
            o = ord(c) - ord('a')
            if not s[o]:
                cnt += 1
                s[o] = True

        indegree = [0] * 26
        for i in range(26):
            for j in range(26):
                if i != j and s[i] and s[j] and g[i][j]:
                    indegree[j] += 1
        q = deque()
        ans = []
        for i in range(26):
            if s[i] and indegree[i] == 0:
                q.append(i)
        while q:
            t = q.popleft()
            ans.append(chr(t + ord('a')))
            for i in range(26):
                if s[i] and i != t and g[t][i]:
                    indegree[i] -= 1
                    if indegree[i] == 0:
                        q.append(i)
        return '' if len(ans) < cnt else ''.join(ans)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {

    public String alienOrder(String[] words) {
        boolean[][] g = new boolean[26][26];
        boolean[] s = new boolean[26];
        int cnt = 0;
        int n = words.length;
        for (int i = 0; i < n - 1; ++i) {
            for (char c : words[i].toCharArray()) {
                if (cnt == 26) {
                    break;
                }
                c -= 'a';
                if (!s[c]) {
                    ++cnt;
                    s[c] = true;
                }
            }
            int m = words[i].length();
            for (int j = 0; j < m; ++j) {
                if (j >= words[i + 1].length()) {
                    return "";
                }
                char c1 = words[i].charAt(j), c2 = words[i + 1].charAt(j);
                if (c1 == c2) {
                    continue;
                }
                if (g[c2 - 'a'][c1 - 'a']) {
                    return "";
                }
                g[c1 - 'a'][c2 - 'a'] = true;
                break;
            }
        }
        for (char c : words[n - 1].toCharArray()) {
            if (cnt == 26) {
                break;
            }
            c -= 'a';
            if (!s[c]) {
                ++cnt;
                s[c] = true;
            }
        }

        int[] indegree = new int[26];
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                if (i != j && s[i] && s[j] && g[i][j]) {
                    ++indegree[j];
                }
            }
        }
        Deque<Integer> q = new LinkedList<>();
        for (int i = 0; i < 26; ++i) {
            if (s[i] && indegree[i] == 0) {
                q.offerLast(i);
            }
        }
        StringBuilder ans = new StringBuilder();
        while (!q.isEmpty()) {
            int t = q.pollFirst();
            ans.append((char) (t + 'a'));
            for (int i = 0; i < 26; ++i) {
                if (i != t && s[i] && g[t][i]) {
                    if (--indegree[i] == 0) {
                        q.offerLast(i);
                    }
                }
            }
        }
        return ans.length() < cnt ? "" : ans.toString();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string alienOrder(vector<string>& words) {
        vector<vector<bool>> g(26, vector<bool>(26));
        vector<bool> s(26);
        int cnt = 0;
        int n = words.size();
        for (int i = 0; i < n - 1; ++i) {
            for (char c : words[i]) {
                if (cnt == 26) break;
                c -= 'a';
                if (!s[c]) {
                    ++cnt;
                    s[c] = true;
                }
            }
            int m = words[i].size();
            for (int j = 0; j < m; ++j) {
                if (j >= words[i + 1].size()) return "";
                char c1 = words[i][j], c2 = words[i + 1][j];
                if (c1 == c2) continue;
                if (g[c2 - 'a'][c1 - 'a']) return "";
                g[c1 - 'a'][c2 - 'a'] = true;
                break;
            }
        }
        for (char c : words[n - 1]) {
            if (cnt == 26) break;
            c -= 'a';
            if (!s[c]) {
                ++cnt;
                s[c] = true;
            }
        }
        vector<int> indegree(26);
        for (int i = 0; i < 26; ++i)
            for (int j = 0; j < 26; ++j)
                if (i != j && s[i] && s[j] && g[i][j])
                    ++indegree[j];
        queue<int> q;
        for (int i = 0; i < 26; ++i)
            if (s[i] && indegree[i] == 0)
                q.push(i);
        string ans = "";
        while (!q.empty()) {
            int t = q.front();
            ans += (t + 'a');
            q.pop();
            for (int i = 0; i < 26; ++i)
                if (i != t && s[i] && g[t][i])
                    if (--indegree[i] == 0)
                        q.push(i);
        }
        return ans.size() < cnt ? "" : ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func alienOrder(words []string) string {
	g := [26][26]bool{}
	s := [26]bool{}
	cnt := 0
	n := len(words)
	for i := 0; i < n-1; i++ {
		for _, c := range words[i] {
			if cnt == 26 {
				break
			}
			c -= 'a'
			if !s[c] {
				cnt++
				s[c] = true
			}
		}
		m := len(words[i])
		for j := 0; j < m; j++ {
			if j >= len(words[i+1]) {
				return ""
			}
			c1, c2 := words[i][j]-'a', words[i+1][j]-'a'
			if c1 == c2 {
				continue
			}
			if g[c2][c1] {
				return ""
			}
			g[c1][c2] = true
			break
		}
	}
	for _, c := range words[n-1] {
		if cnt == 26 {
			break
		}
		c -= 'a'
		if !s[c] {
			cnt++
			s[c] = true
		}
	}

	inDegree := [26]int{}
	for _, out := range g {
		for i, v := range out {
			if v {
				inDegree[i]++
			}
		}
	}
	q := []int{}
	for i, in := range inDegree {
		if in == 0 && s[i] {
			q = append(q, i)
		}
	}
	ans := ""
	for len(q) > 0 {
		t := q[0]
		q = q[1:]
		ans += string(t + 'a')
		for i, v := range g[t] {
			if v {
				inDegree[i]--
				if inDegree[i] == 0 && s[i] {
					q = append(q, i)
				}
			}
		}
	}
	if len(ans) < cnt {
		return ""
	}
	return ans
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>现有一种使用英语字母的火星语言，这门语言的字母顺序对你来说是未知的。</p>

<p>给你一个来自这种外星语言字典的字符串列表 <code>words</code> ，<code>words</code> 中的字符串已经 <strong>按这门新语言的<span data-keyword="lexicographically-smaller-string-alien">字典序</span>进行了排序</strong> 。</p>

<p>如果这种说法是错误的，并且给出的 <code>words</code> 不能对应任何字母的顺序，则返回 <code>""</code> 。</p>

<p>否则，返回一个按新语言规则的&nbsp;<strong>字典递增顺序 </strong>排序的独特字符串。如果有多个解决方案，则返回其中 <strong>任意一个</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>words = ["wrt","wrf","er","ett","rftt"]
<strong>输出：</strong>"wertf"
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>words = ["z","x"]
<strong>输出：</strong>"zx"
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>words = ["z","x","z"]
<strong>输出：</strong>""
<strong>解释：</strong>不存在合法字母顺序，因此返回 <code>"" 。</code>
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 100</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 100</code></li>
	<li><code>words[i]</code> 仅由小写英文字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：拓扑排序 + BFS

用数组 $g$ 记录在火星字典中的字母先后关系，$g[i][j] = true$ 表示字母 $i + 'a'$ 在字母 $j + 'a'$ 的前面；用数组 $s$ 记录当前字典出现过的字母，$cnt$ 表示出现过的字母数。

一个很简单的想法是遍历每一个单词，比较该单词和其后的所有单词，把所有的先后关系更新进数组 $g$，这样遍历时间复杂度为 $O(n^3)$；但是我们发现其实比较相邻的两个单词就可以了，比如 $a < b < c$ 则比较 $a < b$ 和 $b < c$， $a$ 和 $c$ 的关系便确定了。因此算法可以优化成比较相邻两个单词，时间复杂度为 $O(n²)$。

出现矛盾的情况：

-   $g[i][j]$ = $g[j][i]$ = $true$；
-   后一个单词是前一个单词的前缀；
-   在拓扑排序后 $ans$ 的长度小于统计到的字母个数。

拓扑排序：

-   统计所有出现的字母入度；
-   将所有入度为 $0$ 的字母加入队列；
-   当队列不空，出队并更新其他字母的入度，入度为 $0$ 则入队，同时出队时将当前字母加入 $ans$ 的结尾；
-   得到的便是字母的拓扑序，也就是火星字典的字母顺序。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def alienOrder(self, words: List[str]) -> str:
        g = [[False] * 26 for _ in range(26)]
        s = [False] * 26
        cnt = 0
        n = len(words)
        for i in range(n - 1):
            for c in words[i]:
                if cnt == 26:
                    break
                o = ord(c) - ord('a')
                if not s[o]:
                    cnt += 1
                    s[o] = True
            m = len(words[i])
            for j in range(m):
                if j >= len(words[i + 1]):
                    return ''
                c1, c2 = words[i][j], words[i + 1][j]
                if c1 == c2:
                    continue
                o1, o2 = ord(c1) - ord('a'), ord(c2) - ord('a')
                if g[o2][o1]:
                    return ''
                g[o1][o2] = True
                break
        for c in words[n - 1]:
            if cnt == 26:
                break
            o = ord(c) - ord('a')
            if not s[o]:
                cnt += 1
                s[o] = True

        indegree = [0] * 26
        for i in range(26):
            for j in range(26):
                if i != j and s[i] and s[j] and g[i][j]:
                    indegree[j] += 1
        q = deque()
        ans = []
        for i in range(26):
            if s[i] and indegree[i] == 0:
                q.append(i)
        while q:
            t = q.popleft()
            ans.append(chr(t + ord('a')))
            for i in range(26):
                if s[i] and i != t and g[t][i]:
                    indegree[i] -= 1
                    if indegree[i] == 0:
                        q.append(i)
        return '' if len(ans) < cnt else ''.join(ans)
```

#### Java

```java
class Solution {

    public String alienOrder(String[] words) {
        boolean[][] g = new boolean[26][26];
        boolean[] s = new boolean[26];
        int cnt = 0;
        int n = words.length;
        for (int i = 0; i < n - 1; ++i) {
            for (char c : words[i].toCharArray()) {
                if (cnt == 26) {
                    break;
                }
                c -= 'a';
                if (!s[c]) {
                    ++cnt;
                    s[c] = true;
                }
            }
            int m = words[i].length();
            for (int j = 0; j < m; ++j) {
                if (j >= words[i + 1].length()) {
                    return "";
                }
                char c1 = words[i].charAt(j), c2 = words[i + 1].charAt(j);
                if (c1 == c2) {
                    continue;
                }
                if (g[c2 - 'a'][c1 - 'a']) {
                    return "";
                }
                g[c1 - 'a'][c2 - 'a'] = true;
                break;
            }
        }
        for (char c : words[n - 1].toCharArray()) {
            if (cnt == 26) {
                break;
            }
            c -= 'a';
            if (!s[c]) {
                ++cnt;
                s[c] = true;
            }
        }

        int[] indegree = new int[26];
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                if (i != j && s[i] && s[j] && g[i][j]) {
                    ++indegree[j];
                }
            }
        }
        Deque<Integer> q = new LinkedList<>();
        for (int i = 0; i < 26; ++i) {
            if (s[i] && indegree[i] == 0) {
                q.offerLast(i);
            }
        }
        StringBuilder ans = new StringBuilder();
        while (!q.isEmpty()) {
            int t = q.pollFirst();
            ans.append((char) (t + 'a'));
            for (int i = 0; i < 26; ++i) {
                if (i != t && s[i] && g[t][i]) {
                    if (--indegree[i] == 0) {
                        q.offerLast(i);
                    }
                }
            }
        }
        return ans.length() < cnt ? "" : ans.toString();
    }
}
```

#### C++

```cpp
class Solution {
public:
    string alienOrder(vector<string>& words) {
        vector<vector<bool>> g(26, vector<bool>(26));
        vector<bool> s(26);
        int cnt = 0;
        int n = words.size();
        for (int i = 0; i < n - 1; ++i) {
            for (char c : words[i]) {
                if (cnt == 26) break;
                c -= 'a';
                if (!s[c]) {
                    ++cnt;
                    s[c] = true;
                }
            }
            int m = words[i].size();
            for (int j = 0; j < m; ++j) {
                if (j >= words[i + 1].size()) return "";
                char c1 = words[i][j], c2 = words[i + 1][j];
                if (c1 == c2) continue;
                if (g[c2 - 'a'][c1 - 'a']) return "";
                g[c1 - 'a'][c2 - 'a'] = true;
                break;
            }
        }
        for (char c : words[n - 1]) {
            if (cnt == 26) break;
            c -= 'a';
            if (!s[c]) {
                ++cnt;
                s[c] = true;
            }
        }
        vector<int> indegree(26);
        for (int i = 0; i < 26; ++i)
            for (int j = 0; j < 26; ++j)
                if (i != j && s[i] && s[j] && g[i][j])
                    ++indegree[j];
        queue<int> q;
        for (int i = 0; i < 26; ++i)
            if (s[i] && indegree[i] == 0)
                q.push(i);
        string ans = "";
        while (!q.empty()) {
            int t = q.front();
            ans += (t + 'a');
            q.pop();
            for (int i = 0; i < 26; ++i)
                if (i != t && s[i] && g[t][i])
                    if (--indegree[i] == 0)
                        q.push(i);
        }
        return ans.size() < cnt ? "" : ans;
    }
};
```

#### Go

```go
func alienOrder(words []string) string {
	g := [26][26]bool{}
	s := [26]bool{}
	cnt := 0
	n := len(words)
	for i := 0; i < n-1; i++ {
		for _, c := range words[i] {
			if cnt == 26 {
				break
			}
			c -= 'a'
			if !s[c] {
				cnt++
				s[c] = true
			}
		}
		m := len(words[i])
		for j := 0; j < m; j++ {
			if j >= len(words[i+1]) {
				return ""
			}
			c1, c2 := words[i][j]-'a', words[i+1][j]-'a'
			if c1 == c2 {
				continue
			}
			if g[c2][c1] {
				return ""
			}
			g[c1][c2] = true
			break
		}
	}
	for _, c := range words[n-1] {
		if cnt == 26 {
			break
		}
		c -= 'a'
		if !s[c] {
			cnt++
			s[c] = true
		}
	}

	inDegree := [26]int{}
	for _, out := range g {
		for i, v := range out {
			if v {
				inDegree[i]++
			}
		}
	}
	q := []int{}
	for i, in := range inDegree {
		if in == 0 && s[i] {
			q = append(q, i)
		}
	}
	ans := ""
	for len(q) > 0 {
		t := q[0]
		q = q[1:]
		ans += string(t + 'a')
		for i, v := range g[t] {
			if v {
				inDegree[i]--
				if inDegree[i] == 0 && s[i] {
					q = append(q, i)
				}
			}
		}
	}
	if len(ans) < cnt {
		return ""
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
