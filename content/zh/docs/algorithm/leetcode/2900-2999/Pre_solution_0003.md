---
title: "2920_收集所有金币可获得的最大积分"
date: 2025-10-08T18:39:48+08:00
weight: 3
tags: [二分查找, 位运算, 动态规划, 图, 数学, 数据库, 数组, 枚举, 树, 树状数组, 深度优先搜索, 矩阵, 线段树, 组合数学, 记忆化搜索]
---

{{< markmap >}}
### [2920_收集所有金币可获得的最大积分](#2920)
#### [位运算](#2920)
#### [树](#2920)
#### [深度优先搜索](#2920)
#### [记忆化搜索](#2920)
#### [数组](#2920)
#### [动态规划](#2920)
### [2921_价格递增的最大利润三元组 II 🔒](#2921)
#### [树状数组](#2921)
#### [线段树](#2921)
#### [数组](#2921)
### [2922_市场分析 III 🔒](#2922)
#### [数据库](#2922)
### [2923_找到冠军 I](#2923)
#### [数组](#2923)
#### [矩阵](#2923)
### [2924_找到冠军 II](#2924)
#### [图](#2924)
### [2925_在树上执行操作以后得到的最大分数](#2925)
#### [树](#2925)
#### [深度优先搜索](#2925)
#### [动态规划](#2925)
### [2926_平衡子序列的最大和](#2926)
#### [树状数组](#2926)
#### [线段树](#2926)
#### [数组](#2926)
#### [二分查找](#2926)
#### [动态规划](#2926)
### [2927_给小朋友们分糖果 III 🔒](#2927)
#### [数学](#2927)
#### [组合数学](#2927)
### [2928_给小朋友们分糖果 I](#2928)
#### [数学](#2928)
#### [组合数学](#2928)
#### [枚举](#2928)
### [2929_给小朋友们分糖果 II](#2929)
#### [数学](#2929)
#### [组合数学](#2929)
#### [枚举](#2929)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2920_收集所有金币可获得的最大积分
___
#### 位运算
___
#### 树
___
#### 深度优先搜索
___
#### 记忆化搜索
___
#### 数组
___
#### 动态规划
---
### 2921_价格递增的最大利润三元组 II 🔒
___
#### 树状数组
___
#### 线段树
___
#### 数组
---
### 2922_市场分析 III 🔒
___
#### 数据库
---
### 2923_找到冠军 I
___
#### 数组
___
#### 矩阵
---
### 2924_找到冠军 II
___
#### 图
---
### 2925_在树上执行操作以后得到的最大分数
___
#### 树
___
#### 深度优先搜索
___
#### 动态规划
---
### 2926_平衡子序列的最大和
___
#### 树状数组
___
#### 线段树
___
#### 数组
___
#### 二分查找
___
#### 动态规划
---
### 2927_给小朋友们分糖果 III 🔒
___
#### 数学
___
#### 组合数学
---
### 2928_给小朋友们分糖果 I
___
#### 数学
___
#### 组合数学
___
#### 枚举
---
### 2929_给小朋友们分糖果 II
___
#### 数学
___
#### 组合数学
___
#### 枚举
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 位运算 | 动态规划 |
| 图 | 数学 | 数据库 |
| 数组 | 枚举 | 树 |
| 树状数组 | 深度优先搜索 | 矩阵 |
| 线段树 | 组合数学 | 记忆化搜索 |

# [2920. 收集所有金币可获得的最大积分](https://leetcode.cn/problems/maximum-points-after-collecting-coins-from-all-nodes){#2920}

{{< tabs "2920" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumPoints(self, edges: List[List[int]], coins: List[int], k: int) -> int:
        @cache
        def dfs(i: int, fa: int, j: int) -> int:
            a = (coins[i] >> j) - k
            b = coins[i] >> (j + 1)
            for c in g[i]:
                if c != fa:
                    a += dfs(c, i, j)
                    if j < 14:
                        b += dfs(c, i, j + 1)
            return max(a, b)

        n = len(coins)
        g = [[] for _ in range(n)]
        for a, b in edges:
            g[a].append(b)
            g[b].append(a)
        ans = dfs(0, -1, 0)
        dfs.cache_clear()
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int k;
    private int[] coins;
    private Integer[][] f;
    private List<Integer>[] g;

    public int maximumPoints(int[][] edges, int[] coins, int k) {
        this.k = k;
        this.coins = coins;
        int n = coins.length;
        f = new Integer[n][15];
        g = new List[n];
        Arrays.setAll(g, i -> new ArrayList<>());
        for (var e : edges) {
            int a = e[0], b = e[1];
            g[a].add(b);
            g[b].add(a);
        }
        return dfs(0, -1, 0);
    }

    private int dfs(int i, int fa, int j) {
        if (f[i][j] != null) {
            return f[i][j];
        }
        int a = (coins[i] >> j) - k;
        int b = coins[i] >> (j + 1);
        for (int c : g[i]) {
            if (c != fa) {
                a += dfs(c, i, j);
                if (j < 14) {
                    b += dfs(c, i, j + 1);
                }
            }
        }
        return f[i][j] = Math.max(a, b);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        int n = coins.size();
        int f[n][15];
        memset(f, -1, sizeof(f));
        vector<int> g[n];
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            g[a].emplace_back(b);
            g[b].emplace_back(a);
        }
        auto dfs = [&](this auto&& dfs, int i, int fa, int j) -> int {
            if (f[i][j] != -1) {
                return f[i][j];
            }
            int a = (coins[i] >> j) - k;
            int b = coins[i] >> (j + 1);
            for (int c : g[i]) {
                if (c != fa) {
                    a += dfs(c, i, j);
                    if (j < 14) {
                        b += dfs(c, i, j + 1);
                    }
                }
            }
            return f[i][j] = max(a, b);
        };
        return dfs(0, -1, 0);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumPoints(edges [][]int, coins []int, k int) int {
	n := len(coins)
	f := make([][]int, n)
	for i := range f {
		f[i] = make([]int, 15)
		for j := range f[i] {
			f[i][j] = -1
		}
	}
	g := make([][]int, n)
	for _, e := range edges {
		a, b := e[0], e[1]
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}
	var dfs func(int, int, int) int
	dfs = func(i, fa, j int) int {
		if f[i][j] != -1 {
			return f[i][j]
		}
		a := (coins[i] >> j) - k
		b := coins[i] >> (j + 1)
		for _, c := range g[i] {
			if c != fa {
				a += dfs(c, i, j)
				if j < 14 {
					b += dfs(c, i, j+1)
				}
			}
		}
		f[i][j] = max(a, b)
		return f[i][j]
	}
	return dfs(0, -1, 0)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumPoints(edges: number[][], coins: number[], k: number): number {
    const n = coins.length;
    const f: number[][] = Array.from({ length: n }, () => Array(15).fill(-1));
    const g: number[][] = Array.from({ length: n }, () => []);
    for (const [a, b] of edges) {
        g[a].push(b);
        g[b].push(a);
    }
    const dfs = (i: number, fa: number, j: number): number => {
        if (f[i][j] !== -1) {
            return f[i][j];
        }
        let a = (coins[i] >> j) - k;
        let b = coins[i] >> (j + 1);
        for (const c of g[i]) {
            if (c !== fa) {
                a += dfs(c, i, j);
                if (j < 14) {
                    b += dfs(c, i, j + 1);
                }
            }
        }
        return (f[i][j] = Math.max(a, b));
    };
    return dfs(0, -1, 0);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>有一棵由 <code>n</code> 个节点组成的无向树，以&nbsp;<code>0</code>&nbsp; 为根节点，节点编号从 <code>0</code> 到 <code>n - 1</code> 。给你一个长度为 <code>n - 1</code> 的二维 <strong>整数</strong> 数组 <code>edges</code> ，其中 <code>edges[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> 表示在树上的节点 <code>a<sub>i</sub></code> 和 <code>b<sub>i</sub></code> 之间存在一条边。另给你一个下标从 <strong>0</strong> 开始、长度为 <code>n</code> 的数组 <code>coins</code> 和一个整数 <code>k</code> ，其中 <code>coins[i]</code> 表示节点 <code>i</code> 处的金币数量。</p>

<p>从根节点开始，你必须收集所有金币。要想收集节点上的金币，必须先收集该节点的祖先节点上的金币。</p>

<p>节点 <code>i</code> 上的金币可以用下述方法之一进行收集：</p>

<ul>
	<li>收集所有金币，得到共计 <code>coins[i] - k</code> 点积分。如果 <code>coins[i] - k</code> 是负数，你将会失去 <code>abs(coins[i] - k)</code> 点积分。</li>
	<li>收集所有金币，得到共计 <code>floor(coins[i] / 2)</code> 点积分。如果采用这种方法，节点 <code>i</code> 子树中所有节点 <code>j</code> 的金币数 <code>coins[j]</code> 将会减少至 <code>floor(coins[j] / 2)</code> 。</li>
</ul>

<p>返回收集 <strong>所有</strong> 树节点的金币之后可以获得的最大积分。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2900-2999/2920.Maximum%20Points%20After%20Collecting%20Coins%20From%20All%20Nodes/images/ex1-copy.png" style="width: 60px; height: 316px; padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem;" />
<pre>
<strong>输入：</strong>edges = [[0,1],[1,2],[2,3]], coins = [10,10,3,3], k = 5
<strong>输出：</strong>11                        
<strong>解释：</strong>
使用第一种方法收集节点 0 上的所有金币。总积分 = 10 - 5 = 5 。
使用第一种方法收集节点 1 上的所有金币。总积分 = 5 + (10 - 5) = 10 。
使用第二种方法收集节点 2 上的所有金币。所以节点 3 上的金币将会变为 floor(3 / 2) = 1 ，总积分 = 10 + floor(3 / 2) = 11 。
使用第二种方法收集节点 3 上的所有金币。总积分 =  11 + floor(1 / 2) = 11.
可以证明收集所有节点上的金币能获得的最大积分是 11 。 
</pre>

<p><strong class="example">示例 2：</strong></p>
<strong class="example"> <img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2900-2999/2920.Maximum%20Points%20After%20Collecting%20Coins%20From%20All%20Nodes/images/ex2.png" style="width: 140px; height: 147px; padding: 10px; background: #fff; border-radius: .5rem;" /></strong>

<pre>
<strong>输入：</strong>edges = [[0,1],[0,2]], coins = [8,4,4], k = 0
<strong>输出：</strong>16
<strong>解释：</strong>
使用第一种方法收集所有节点上的金币，因此，总积分 = (8 - 0) + (4 - 0) + (4 - 0) = 16 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == coins.length</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code><font face="monospace">0 &lt;= coins[i] &lt;= 10<sup>4</sup></font></code></li>
	<li><code>edges.length == n - 1</code></li>
	<li><code><font face="monospace">0 &lt;= edges[i][0], edges[i][1] &lt; n</font></code></li>
	<li><code><font face="monospace">0 &lt;= k &lt;= 10<sup>4</sup></font></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

我们先根据题目给定的边构建图 $g$，其中 $g[i]$ 表示节点 $i$ 的所有邻接节点。然后我们可以使用记忆化搜索的方法求解本题。

我们设计一个函数 $dfs(i, fa, j)$，表示当前节点为 $i$，父节点为 $fa$，当前节点的金币数需要右移 $j$ 位，所能获得的最大积分。

函数 $dfs(i, fa, j)$ 的执行过程如下：

如果我们使用第一种方法收集当前节点的金币，那么当前节点的积分为 $(coins[i] >> j) - k$，然后我们遍历当前节点的所有邻接节点 $c$，如果 $c$ 不等于 $fa$，那么我们将 $dfs(c, i, j)$ 的结果累加到当前节点的积分中。

如果我们使用第二种方法收集当前节点的金币，那么当前节点的积分为 $coins[i] >> (j + 1)$，然后我们遍历当前节点的所有邻接节点 $c$，如果 $c$ 不等于 $fa$，那么我们将 $dfs(c, i, j + 1)$ 的结果累加到当前节点的积分中。注意，由于题目中给定的 $coins[i]$ 最大值为 $10^4$，因此我们最多只能右移 $14$ 位，就使得 $coins[i] >> (j + 1)$ 的值为 $0$。

最后，我们返回当前节点使用两种方法中能获得的最大积分。

为了避免重复计算，我们使用记忆化搜索的方法，将 $dfs(i, fa, j)$ 的结果存储到 $f[i][j]$ 中，其中 $f[i][j]$ 表示当前节点为 $i$，父节点为 $fa$，当前节点的金币数需要右移 $j$ 位，所能获得的最大
时间复杂度 $O(n \times \log M)$，空间复杂度 $O(n \times \log M)$。其中 $M$ 表示 $coins[i]$ 的最大值。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumPoints(self, edges: List[List[int]], coins: List[int], k: int) -> int:
        @cache
        def dfs(i: int, fa: int, j: int) -> int:
            a = (coins[i] >> j) - k
            b = coins[i] >> (j + 1)
            for c in g[i]:
                if c != fa:
                    a += dfs(c, i, j)
                    if j < 14:
                        b += dfs(c, i, j + 1)
            return max(a, b)

        n = len(coins)
        g = [[] for _ in range(n)]
        for a, b in edges:
            g[a].append(b)
            g[b].append(a)
        ans = dfs(0, -1, 0)
        dfs.cache_clear()
        return ans
```

#### Java

```java
class Solution {
    private int k;
    private int[] coins;
    private Integer[][] f;
    private List<Integer>[] g;

    public int maximumPoints(int[][] edges, int[] coins, int k) {
        this.k = k;
        this.coins = coins;
        int n = coins.length;
        f = new Integer[n][15];
        g = new List[n];
        Arrays.setAll(g, i -> new ArrayList<>());
        for (var e : edges) {
            int a = e[0], b = e[1];
            g[a].add(b);
            g[b].add(a);
        }
        return dfs(0, -1, 0);
    }

    private int dfs(int i, int fa, int j) {
        if (f[i][j] != null) {
            return f[i][j];
        }
        int a = (coins[i] >> j) - k;
        int b = coins[i] >> (j + 1);
        for (int c : g[i]) {
            if (c != fa) {
                a += dfs(c, i, j);
                if (j < 14) {
                    b += dfs(c, i, j + 1);
                }
            }
        }
        return f[i][j] = Math.max(a, b);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        int n = coins.size();
        int f[n][15];
        memset(f, -1, sizeof(f));
        vector<int> g[n];
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            g[a].emplace_back(b);
            g[b].emplace_back(a);
        }
        auto dfs = [&](this auto&& dfs, int i, int fa, int j) -> int {
            if (f[i][j] != -1) {
                return f[i][j];
            }
            int a = (coins[i] >> j) - k;
            int b = coins[i] >> (j + 1);
            for (int c : g[i]) {
                if (c != fa) {
                    a += dfs(c, i, j);
                    if (j < 14) {
                        b += dfs(c, i, j + 1);
                    }
                }
            }
            return f[i][j] = max(a, b);
        };
        return dfs(0, -1, 0);
    }
};
```

#### Go

```go
func maximumPoints(edges [][]int, coins []int, k int) int {
	n := len(coins)
	f := make([][]int, n)
	for i := range f {
		f[i] = make([]int, 15)
		for j := range f[i] {
			f[i][j] = -1
		}
	}
	g := make([][]int, n)
	for _, e := range edges {
		a, b := e[0], e[1]
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}
	var dfs func(int, int, int) int
	dfs = func(i, fa, j int) int {
		if f[i][j] != -1 {
			return f[i][j]
		}
		a := (coins[i] >> j) - k
		b := coins[i] >> (j + 1)
		for _, c := range g[i] {
			if c != fa {
				a += dfs(c, i, j)
				if j < 14 {
					b += dfs(c, i, j+1)
				}
			}
		}
		f[i][j] = max(a, b)
		return f[i][j]
	}
	return dfs(0, -1, 0)
}
```

#### TypeScript

```ts
function maximumPoints(edges: number[][], coins: number[], k: number): number {
    const n = coins.length;
    const f: number[][] = Array.from({ length: n }, () => Array(15).fill(-1));
    const g: number[][] = Array.from({ length: n }, () => []);
    for (const [a, b] of edges) {
        g[a].push(b);
        g[b].push(a);
    }
    const dfs = (i: number, fa: number, j: number): number => {
        if (f[i][j] !== -1) {
            return f[i][j];
        }
        let a = (coins[i] >> j) - k;
        let b = coins[i] >> (j + 1);
        for (const c of g[i]) {
            if (c !== fa) {
                a += dfs(c, i, j);
                if (j < 14) {
                    b += dfs(c, i, j + 1);
                }
            }
        }
        return (f[i][j] = Math.max(a, b));
    };
    return dfs(0, -1, 0);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2921. 价格递增的最大利润三元组 II 🔒](https://leetcode.cn/problems/maximum-profitable-triplets-with-increasing-prices-ii){#2921}

{{< tabs "2921" >}}

{{% tab "python" %}}
```python
class BinaryIndexedTree:
    def __init__(self, n: int):
        self.n = n
        self.c = [0] * (n + 1)

    def update(self, x: int, v: int):
        while x <= self.n:
            self.c[x] = max(self.c[x], v)
            x += x & -x

    def query(self, x: int) -> int:
        mx = 0
        while x:
            mx = max(mx, self.c[x])
            x -= x & -x
        return mx


class Solution:
    def maxProfit(self, prices: List[int], profits: List[int]) -> int:
        n = len(prices)
        left = [0] * n
        right = [0] * n

        m = max(prices)
        tree1 = BinaryIndexedTree(m + 1)
        tree2 = BinaryIndexedTree(m + 1)

        for i, x in enumerate(prices):
            left[i] = tree1.query(x - 1)
            tree1.update(x, profits[i])
        for i in range(n - 1, -1, -1):
            x = m + 1 - prices[i]
            right[i] = tree2.query(x - 1)
            tree2.update(x, profits[i])

        return max(
            (l + x + r for l, x, r in zip(left, profits, right) if l and r), default=-1
        )
```
{{% /tab %}}
{{% tab "java" %}}
```java
class BinaryIndexedTree {
    private int n;
    private int[] c;

    public BinaryIndexedTree(int n) {
        this.n = n;
        c = new int[n + 1];
    }

    public void update(int x, int v) {
        while (x <= n) {
            c[x] = Math.max(c[x], v);
            x += x & -x;
        }
    }

    public int query(int x) {
        int mx = 0;
        while (x > 0) {
            mx = Math.max(mx, c[x]);
            x -= x & -x;
        }
        return mx;
    }
}

class Solution {
    public int maxProfit(int[] prices, int[] profits) {
        int n = prices.length;
        int[] left = new int[n];
        int[] right = new int[n];
        int m = 0;
        for (int x : prices) {
            m = Math.max(m, x);
        }
        BinaryIndexedTree tree1 = new BinaryIndexedTree(m + 1);
        BinaryIndexedTree tree2 = new BinaryIndexedTree(m + 1);
        for (int i = 0; i < n; ++i) {
            int x = prices[i];
            left[i] = tree1.query(x - 1);
            tree1.update(x, profits[i]);
        }
        for (int i = n - 1; i >= 0; --i) {
            int x = m + 1 - prices[i];
            right[i] = tree2.query(x - 1);
            tree2.update(x, profits[i]);
        }
        int ans = -1;
        for (int i = 0; i < n; ++i) {
            if (left[i] > 0 && right[i] > 0) {
                ans = Math.max(ans, left[i] + profits[i] + right[i]);
            }
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
    BinaryIndexedTree(int n) {
        this->n = n;
        c.resize(n + 1, 0);
    }

    void update(int x, int v) {
        while (x <= n) {
            c[x] = max(c[x], v);
            x += x & -x;
        }
    }

    int query(int x) {
        int mx = 0;
        while (x > 0) {
            mx = max(mx, c[x]);
            x -= x & -x;
        }
        return mx;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices, vector<int>& profits) {
        int n = prices.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        int m = *max_element(prices.begin(), prices.end());
        BinaryIndexedTree tree1(m + 1);
        BinaryIndexedTree tree2(m + 1);
        for (int i = 0; i < n; ++i) {
            int x = prices[i];
            left[i] = tree1.query(x - 1);
            tree1.update(x, profits[i]);
        }
        for (int i = n - 1; i >= 0; --i) {
            int x = m + 1 - prices[i];
            right[i] = tree2.query(x - 1);
            tree2.update(x, profits[i]);
        }
        int ans = -1;
        for (int i = 0; i < n; ++i) {
            if (left[i] > 0 && right[i] > 0) {
                ans = max(ans, left[i] + profits[i] + right[i]);
            }
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

func NewBinaryIndexedTree(n int) BinaryIndexedTree {
	c := make([]int, n+1)
	return BinaryIndexedTree{n: n, c: c}
}

func (bit *BinaryIndexedTree) update(x, v int) {
	for x <= bit.n {
		bit.c[x] = max(bit.c[x], v)
		x += x & -x
	}
}

func (bit *BinaryIndexedTree) query(x int) int {
	mx := 0
	for x > 0 {
		mx = max(mx, bit.c[x])
		x -= x & -x
	}
	return mx
}

func maxProfit(prices []int, profits []int) int {
	n := len(prices)
	left := make([]int, n)
	right := make([]int, n)
	m := slices.Max(prices)

	tree1 := NewBinaryIndexedTree(m + 1)
	tree2 := NewBinaryIndexedTree(m + 1)

	for i, x := range prices {
		left[i] = tree1.query(x - 1)
		tree1.update(x, profits[i])
	}

	for i := n - 1; i >= 0; i-- {
		x := m + 1 - prices[i]
		right[i] = tree2.query(x - 1)
		tree2.update(x, profits[i])
	}

	ans := -1

	for i := 0; i < n; i++ {
		if left[i] > 0 && right[i] > 0 {
			ans = max(ans, left[i]+profits[i]+right[i])
		}
	}

	return ans
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

    update(x: number, v: number): void {
        while (x <= this.n) {
            this.c[x] = Math.max(this.c[x], v);
            x += x & -x;
        }
    }

    query(x: number): number {
        let mx = 0;
        while (x > 0) {
            mx = Math.max(mx, this.c[x]);
            x -= x & -x;
        }
        return mx;
    }
}

function maxProfit(prices: number[], profits: number[]): number {
    const n: number = prices.length;
    const left: number[] = Array(n).fill(0);
    const right: number[] = Array(n).fill(0);
    const m = Math.max(...prices);

    const tree1: BinaryIndexedTree = new BinaryIndexedTree(m + 1);
    const tree2: BinaryIndexedTree = new BinaryIndexedTree(m + 1);

    for (let i = 0; i < n; i++) {
        const x: number = prices[i];
        left[i] = tree1.query(x - 1);
        tree1.update(x, profits[i]);
    }

    for (let i = n - 1; i >= 0; i--) {
        const x: number = m + 1 - prices[i];
        right[i] = tree2.query(x - 1);
        tree2.update(x, profits[i]);
    }

    let ans: number = -1;

    for (let i = 0; i < n; i++) {
        if (left[i] > 0 && right[i] > 0) {
            ans = Math.max(ans, left[i] + profits[i] + right[i]);
        }
    }

    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
struct BinaryIndexedTree {
    n: usize,
    c: Vec<i32>,
}

impl BinaryIndexedTree {
    fn new(n: usize) -> BinaryIndexedTree {
        BinaryIndexedTree {
            n,
            c: vec![0; n + 1],
        }
    }

    fn update(&mut self, x: usize, v: i32) {
        let mut x = x;
        while x <= self.n {
            self.c[x] = self.c[x].max(v);
            x += x & x.wrapping_neg();
        }
    }

    fn query(&self, x: usize) -> i32 {
        let mut x = x;
        let mut mx = 0;
        while x > 0 {
            mx = mx.max(self.c[x]);
            x -= x & x.wrapping_neg();
        }
        mx
    }
}

impl Solution {
    pub fn max_profit(prices: Vec<i32>, profits: Vec<i32>) -> i32 {
        let n = prices.len();
        let mut left = vec![0; n];
        let mut right = vec![0; n];
        let m = prices.iter().cloned().max().unwrap_or(0);

        let mut tree1 = BinaryIndexedTree::new((m as usize) + 1);
        let mut tree2 = BinaryIndexedTree::new((m as usize) + 1);

        for i in 0..n {
            let x = prices[i] as usize;
            left[i] = tree1.query(x - 1);
            tree1.update(x, profits[i]);
        }

        for i in (0..n).rev() {
            let x = (m + 1 - prices[i]) as usize;
            right[i] = tree2.query(x - 1);
            tree2.update(x, profits[i]);
        }

        let mut ans = -1;
        for i in 0..n {
            if left[i] > 0 && right[i] > 0 {
                ans = ans.max(left[i] + profits[i] + right[i]);
            }
        }

        ans
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定长度为 <code>n</code>&nbsp; 的数组&nbsp;<code>prices</code>&nbsp;和&nbsp;<code>profits</code>&nbsp;（<strong>下标从 0 开始</strong>）。一个商店有&nbsp;<code>n</code>&nbsp;个商品，第&nbsp;<code>i</code>&nbsp;个商品的价格为&nbsp;<code>prices[i]</code>，利润为&nbsp;<code>profits[i]</code>。</p>

<p>需要选择三个商品，满足以下条件：</p>

<ul>
	<li><code>prices[i] &lt; prices[j] &lt; prices[k]</code>，其中&nbsp;<code>i &lt; j &lt; k</code>。</li>
</ul>

<p>如果选择的商品&nbsp;<code>i</code>, <code>j</code>&nbsp;和&nbsp;<code>k</code>&nbsp;满足以下条件，那么利润将等于&nbsp;<code>profits[i] + profits[j] + profits[k]</code>。</p>

<p>返回能够获得的<em>&nbsp;<strong>最大利润</strong>，如果不可能满足给定条件，</em>返回<em>&nbsp;</em><code>-1</code><em>。</em></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>prices = [10,2,3,4], profits = [100,2,7,10]
<b>输出：</b>19
<b>解释：</b>不能选择下标 i=0 的商品，因为没有下标 j 和 k 的商品满足条件。
只能选择下标为 1、2、3 的三个商品，这是有效的选择，因为 prices[1] &lt; prices[2] &lt; prices[3]。
答案是它们的利润之和，即 2 + 7 + 10 = 19。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>prices = [1,2,3,4,5], profits = [1,5,3,4,6]
<b>输出：</b>15
<b>解释：</b>可以选择任意三个商品，因为对于每组满足下标为 i &lt; j &lt; k 的三个商品，条件都成立。
因此，能得到的最大利润就是利润和最大的三个商品，即下标为 1，3 和 4 的商品。
答案就是它们的利润之和，即 5 + 4 + 6 = 15。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>prices = [4,3,2,1], profits = [33,20,19,87]
<b>输出：</b>-1
<b>解释：</b>找不到任何可以满足条件的三个商品，所以返回 -1.
</pre>

<p>&nbsp;</p>

<p><b>提示：</b></p>

<ul>
	<li><code>3 &lt;= prices.length == profits.length &lt;= 50000</code></li>
	<li><code>1 &lt;= prices[i] &lt;= 5000</code></li>
	<li><code>1 &lt;= profits[i] &lt;= 10<sup>6</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：树状数组

我们可以用两个树状数组分别维护每个价格左边以及右边的最大利润，然后枚举中间的价格，通过树状数组查询左右两边的最大利润，最后取最大值即可。

时间复杂度 $O(n \times \log M)$，空间复杂度 $O(M)$。其中 $n$ 是数组 $prices$ 的长度，而 $M$ 是数组 $prices$ 中的最大值，本题中 $M \le 5000$。

<!-- tabs:start -->

#### Python3

```python
class BinaryIndexedTree:
    def __init__(self, n: int):
        self.n = n
        self.c = [0] * (n + 1)

    def update(self, x: int, v: int):
        while x <= self.n:
            self.c[x] = max(self.c[x], v)
            x += x & -x

    def query(self, x: int) -> int:
        mx = 0
        while x:
            mx = max(mx, self.c[x])
            x -= x & -x
        return mx


class Solution:
    def maxProfit(self, prices: List[int], profits: List[int]) -> int:
        n = len(prices)
        left = [0] * n
        right = [0] * n

        m = max(prices)
        tree1 = BinaryIndexedTree(m + 1)
        tree2 = BinaryIndexedTree(m + 1)

        for i, x in enumerate(prices):
            left[i] = tree1.query(x - 1)
            tree1.update(x, profits[i])
        for i in range(n - 1, -1, -1):
            x = m + 1 - prices[i]
            right[i] = tree2.query(x - 1)
            tree2.update(x, profits[i])

        return max(
            (l + x + r for l, x, r in zip(left, profits, right) if l and r), default=-1
        )
```

#### Java

```java
class BinaryIndexedTree {
    private int n;
    private int[] c;

    public BinaryIndexedTree(int n) {
        this.n = n;
        c = new int[n + 1];
    }

    public void update(int x, int v) {
        while (x <= n) {
            c[x] = Math.max(c[x], v);
            x += x & -x;
        }
    }

    public int query(int x) {
        int mx = 0;
        while (x > 0) {
            mx = Math.max(mx, c[x]);
            x -= x & -x;
        }
        return mx;
    }
}

class Solution {
    public int maxProfit(int[] prices, int[] profits) {
        int n = prices.length;
        int[] left = new int[n];
        int[] right = new int[n];
        int m = 0;
        for (int x : prices) {
            m = Math.max(m, x);
        }
        BinaryIndexedTree tree1 = new BinaryIndexedTree(m + 1);
        BinaryIndexedTree tree2 = new BinaryIndexedTree(m + 1);
        for (int i = 0; i < n; ++i) {
            int x = prices[i];
            left[i] = tree1.query(x - 1);
            tree1.update(x, profits[i]);
        }
        for (int i = n - 1; i >= 0; --i) {
            int x = m + 1 - prices[i];
            right[i] = tree2.query(x - 1);
            tree2.update(x, profits[i]);
        }
        int ans = -1;
        for (int i = 0; i < n; ++i) {
            if (left[i] > 0 && right[i] > 0) {
                ans = Math.max(ans, left[i] + profits[i] + right[i]);
            }
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
    BinaryIndexedTree(int n) {
        this->n = n;
        c.resize(n + 1, 0);
    }

    void update(int x, int v) {
        while (x <= n) {
            c[x] = max(c[x], v);
            x += x & -x;
        }
    }

    int query(int x) {
        int mx = 0;
        while (x > 0) {
            mx = max(mx, c[x]);
            x -= x & -x;
        }
        return mx;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices, vector<int>& profits) {
        int n = prices.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        int m = *max_element(prices.begin(), prices.end());
        BinaryIndexedTree tree1(m + 1);
        BinaryIndexedTree tree2(m + 1);
        for (int i = 0; i < n; ++i) {
            int x = prices[i];
            left[i] = tree1.query(x - 1);
            tree1.update(x, profits[i]);
        }
        for (int i = n - 1; i >= 0; --i) {
            int x = m + 1 - prices[i];
            right[i] = tree2.query(x - 1);
            tree2.update(x, profits[i]);
        }
        int ans = -1;
        for (int i = 0; i < n; ++i) {
            if (left[i] > 0 && right[i] > 0) {
                ans = max(ans, left[i] + profits[i] + right[i]);
            }
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

func NewBinaryIndexedTree(n int) BinaryIndexedTree {
	c := make([]int, n+1)
	return BinaryIndexedTree{n: n, c: c}
}

func (bit *BinaryIndexedTree) update(x, v int) {
	for x <= bit.n {
		bit.c[x] = max(bit.c[x], v)
		x += x & -x
	}
}

func (bit *BinaryIndexedTree) query(x int) int {
	mx := 0
	for x > 0 {
		mx = max(mx, bit.c[x])
		x -= x & -x
	}
	return mx
}

func maxProfit(prices []int, profits []int) int {
	n := len(prices)
	left := make([]int, n)
	right := make([]int, n)
	m := slices.Max(prices)

	tree1 := NewBinaryIndexedTree(m + 1)
	tree2 := NewBinaryIndexedTree(m + 1)

	for i, x := range prices {
		left[i] = tree1.query(x - 1)
		tree1.update(x, profits[i])
	}

	for i := n - 1; i >= 0; i-- {
		x := m + 1 - prices[i]
		right[i] = tree2.query(x - 1)
		tree2.update(x, profits[i])
	}

	ans := -1

	for i := 0; i < n; i++ {
		if left[i] > 0 && right[i] > 0 {
			ans = max(ans, left[i]+profits[i]+right[i])
		}
	}

	return ans
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

    update(x: number, v: number): void {
        while (x <= this.n) {
            this.c[x] = Math.max(this.c[x], v);
            x += x & -x;
        }
    }

    query(x: number): number {
        let mx = 0;
        while (x > 0) {
            mx = Math.max(mx, this.c[x]);
            x -= x & -x;
        }
        return mx;
    }
}

function maxProfit(prices: number[], profits: number[]): number {
    const n: number = prices.length;
    const left: number[] = Array(n).fill(0);
    const right: number[] = Array(n).fill(0);
    const m = Math.max(...prices);

    const tree1: BinaryIndexedTree = new BinaryIndexedTree(m + 1);
    const tree2: BinaryIndexedTree = new BinaryIndexedTree(m + 1);

    for (let i = 0; i < n; i++) {
        const x: number = prices[i];
        left[i] = tree1.query(x - 1);
        tree1.update(x, profits[i]);
    }

    for (let i = n - 1; i >= 0; i--) {
        const x: number = m + 1 - prices[i];
        right[i] = tree2.query(x - 1);
        tree2.update(x, profits[i]);
    }

    let ans: number = -1;

    for (let i = 0; i < n; i++) {
        if (left[i] > 0 && right[i] > 0) {
            ans = Math.max(ans, left[i] + profits[i] + right[i]);
        }
    }

    return ans;
}
```

#### Rust

```rust
struct BinaryIndexedTree {
    n: usize,
    c: Vec<i32>,
}

impl BinaryIndexedTree {
    fn new(n: usize) -> BinaryIndexedTree {
        BinaryIndexedTree {
            n,
            c: vec![0; n + 1],
        }
    }

    fn update(&mut self, x: usize, v: i32) {
        let mut x = x;
        while x <= self.n {
            self.c[x] = self.c[x].max(v);
            x += x & x.wrapping_neg();
        }
    }

    fn query(&self, x: usize) -> i32 {
        let mut x = x;
        let mut mx = 0;
        while x > 0 {
            mx = mx.max(self.c[x]);
            x -= x & x.wrapping_neg();
        }
        mx
    }
}

impl Solution {
    pub fn max_profit(prices: Vec<i32>, profits: Vec<i32>) -> i32 {
        let n = prices.len();
        let mut left = vec![0; n];
        let mut right = vec![0; n];
        let m = prices.iter().cloned().max().unwrap_or(0);

        let mut tree1 = BinaryIndexedTree::new((m as usize) + 1);
        let mut tree2 = BinaryIndexedTree::new((m as usize) + 1);

        for i in 0..n {
            let x = prices[i] as usize;
            left[i] = tree1.query(x - 1);
            tree1.update(x, profits[i]);
        }

        for i in (0..n).rev() {
            let x = (m + 1 - prices[i]) as usize;
            right[i] = tree2.query(x - 1);
            tree2.update(x, profits[i]);
        }

        let mut ans = -1;
        for i in 0..n {
            if left[i] > 0 && right[i] > 0 {
                ans = ans.max(left[i] + profits[i] + right[i]);
            }
        }

        ans
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2922. 市场分析 III 🔒](https://leetcode.cn/problems/market-analysis-iii){#2922}

{{< tabs "2922" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT seller_id, COUNT(DISTINCT item_id) AS num_items
        FROM
            Orders
            JOIN Users USING (seller_id)
            JOIN Items USING (item_id)
        WHERE item_brand != favorite_brand
        GROUP BY 1
    )
SELECT seller_id, num_items
FROM T
WHERE num_items = (SELECT MAX(num_items) FROM T)
ORDER BY 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：&nbsp;<code>Users</code></p>

<pre>
+----------------+---------+
| Column Name    | Type    |
+----------------+---------+
| seller_id      | int     |
| join_date      | date    |
| favorite_brand | varchar |
+----------------+---------+
seller_id 是该表具有唯一值的列。
该表包含卖家的 ID, 加入日期以及最喜欢的品牌。
</pre>

<p>表：&nbsp;<code>Items</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| item_id       | int     |
| item_brand    | varchar |
+---------------+---------+
item_id 是该表具有唯一值的列。
该表包含商品 ID 和商品品牌。</pre>

<p>表：&nbsp;<code>Orders</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| order_id      | int     |
| order_date    | date    |
| item_id       | int     |
| seller_id     | int     |
+---------------+---------+
order_id 是该表具有唯一值的列。
item_id 是指向 Items 表的外键。
seller_id 是指向 Users 表的外键。
该表包含订单 ID、下单日期、商品 ID 和卖家 ID。
</pre>

<p>编写一个解决方案，找到卖出数量 <strong>最多&nbsp;</strong>的&nbsp;<strong>非</strong> 最喜欢的品牌的 <strong>不同</strong> 商品的顶级卖家。如果有多个卖家有相同的最高卖出数量，返回所有这些卖家。</p>

<p>返回按&nbsp;<code>seller_id</code><em>&nbsp;<strong>升序排序</strong>&nbsp;的结果表。</em></p>

<p>结果格式如下示例所示。</p>

<p>&nbsp;</p>

<p><b>示例 1:</b></p>

<pre>
<b>输入：</b>
Users table:
+-----------+------------+----------------+
| seller_id | join_date  | favorite_brand |
+-----------+------------+----------------+
| 1         | 2019-01-01 | Lenovo         |
| 2         | 2019-02-09 | Samsung        |
| 3         | 2019-01-19 | LG             |
+-----------+------------+----------------+
Orders table:
+----------+------------+---------+-----------+
| order_id | order_date | item_id | seller_id |
+----------+------------+---------+-----------+
| 1        | 2019-08-01 | 4       | 2         |
| 2        | 2019-08-02 | 2       | 3         |
| 3        | 2019-08-03 | 3       | 3         |
| 4        | 2019-08-04 | 1       | 2         |
| 5        | 2019-08-04 | 4       | 2         |
+----------+------------+---------+-----------+
Items table:
+---------+------------+
| item_id | item_brand |
+---------+------------+
| 1       | Samsung    |
| 2       | Lenovo     |
| 3       | LG         |
| 4       | HP         |
+---------+------------+
<b>输出：</b>
+-----------+-----------+
| seller_id | num_items |
+-----------+-----------+
| 2         | 1         |
| 3         | 1         |
+-----------+-----------+
<b>解释：</b>
- 卖家 ID 为 2 的用户销售了三件商品，但只有两件不是他最喜欢的商品。由于这两个商品相同，所以我们只计数 1。 
- 卖家 ID 为 3 的用户销售了两件商品，但只有一件不是他最喜欢的商品。我们将只把非最喜欢商品列入计数中。
因为卖家 ID 为 2 和 3 的卖家都有一件商品列入计数，所以他们都将显示在输出中。
</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：等值连接 + 分组 + 子查询

我们可以使用等值连接，将 `Orders` 表和 `Users` 表按照 `seller_id` 进行连接，接着再按照 `item_id` 连接 `Items`，筛选出 `item_brand` 不等于 `favorite_brand` 的记录，然后按照 `seller_id` 进行分组，统计每个 `seller_id` 对应的 `item_id` 的个数，最后再使用子查询，找出 `item_id` 个数最多的 `seller_id`。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT seller_id, COUNT(DISTINCT item_id) AS num_items
        FROM
            Orders
            JOIN Users USING (seller_id)
            JOIN Items USING (item_id)
        WHERE item_brand != favorite_brand
        GROUP BY 1
    )
SELECT seller_id, num_items
FROM T
WHERE num_items = (SELECT MAX(num_items) FROM T)
ORDER BY 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2923. 找到冠军 I](https://leetcode.cn/problems/find-champion-i){#2923}

{{< tabs "2923" >}}

{{% tab "python" %}}
```python
class Solution:
    def findChampion(self, grid: List[List[int]]) -> int:
        for i, row in enumerate(grid):
            if all(x == 1 for j, x in enumerate(row) if i != j):
                return i
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int findChampion(int[][] grid) {
        int n = grid.length;
        for (int i = 0;; ++i) {
            int cnt = 0;
            for (int j = 0; j < n; ++j) {
                if (i != j && grid[i][j] == 1) {
                    ++cnt;
                }
            }
            if (cnt == n - 1) {
                return i;
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
    int findChampion(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int i = 0;; ++i) {
            int cnt = 0;
            for (int j = 0; j < n; ++j) {
                if (i != j && grid[i][j] == 1) {
                    ++cnt;
                }
            }
            if (cnt == n - 1) {
                return i;
            }
        }
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findChampion(grid [][]int) int {
	n := len(grid)
	for i := 0; ; i++ {
		cnt := 0
		for j, x := range grid[i] {
			if i != j && x == 1 {
				cnt++
			}
		}
		if cnt == n-1 {
			return i
		}
	}
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findChampion(grid: number[][]): number {
    for (let i = 0, n = grid.length; ; ++i) {
        let cnt = 0;
        for (let j = 0; j < n; ++j) {
            if (i !== j && grid[i][j] === 1) {
                ++cnt;
            }
        }
        if (cnt === n - 1) {
            return i;
        }
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>一场比赛中共有 <code>n</code> 支队伍，按从 <code>0</code> 到&nbsp; <code>n - 1</code> 编号。</p>

<p>给你一个下标从 <strong>0</strong> 开始、大小为 <code>n * n</code> 的二维布尔矩阵 <code>grid</code> 。对于满足&nbsp;<code>0 &lt;= i, j &lt;= n - 1</code> 且 <code>i != j</code> 的所有 <code>i, j</code> ：如果 <code>grid[i][j] == 1</code>，那么 <code>i</code> 队比 <code>j</code> 队 <strong>强</strong> ；否则，<code>j</code> 队比 <code>i</code> 队 <strong>强</strong> 。</p>

<p>在这场比赛中，如果不存在某支强于 <code>a</code> 队的队伍，则认为 <code>a</code> 队将会是 <strong>冠军</strong> 。</p>

<p>返回这场比赛中将会成为冠军的队伍。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>grid = [[0,1],[0,0]]
<strong>输出：</strong>0
<strong>解释：</strong>比赛中有两支队伍。
grid[0][1] == 1 表示 0 队比 1 队强。所以 0 队是冠军。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>grid = [[0,0,1],[1,0,1],[0,0,0]]
<strong>输出：</strong>1
<strong>解释：</strong>比赛中有三支队伍。
grid[1][0] == 1 表示 1 队比 0 队强。
grid[1][2] == 1 表示 1 队比 2 队强。
所以 1 队是冠军。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>2 &lt;= n &lt;= 100</code></li>
	<li><code>grid[i][j]</code> 的值为 <code>0</code> 或 <code>1</code><meta charset="UTF-8" /></li>
	<li>对于所有&nbsp;<code>i</code>，<code> grid[i][i]</code>&nbsp;等于&nbsp;<code>0.</code></li>
	<li>对于满足&nbsp;<code>i != j</code> 的所有 <code>i, j</code> ，<code>grid[i][j] != grid[j][i]</code> 均成立</li>
	<li>生成的输入满足：如果 <code>a</code> 队比 <code>b</code> 队强，<code>b</code> 队比 <code>c</code> 队强，那么 <code>a</code> 队比 <code>c</code> 队强</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举

我们可以枚举每一支队伍 $i$，如果 $i$ 队的每一场比赛都赢了，那么 $i$ 队就是冠军，直接返回 $i$ 即可。

时间复杂度 $O(n^2)$，其中 $n$ 是队伍数量。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findChampion(self, grid: List[List[int]]) -> int:
        for i, row in enumerate(grid):
            if all(x == 1 for j, x in enumerate(row) if i != j):
                return i
```

#### Java

```java
class Solution {
    public int findChampion(int[][] grid) {
        int n = grid.length;
        for (int i = 0;; ++i) {
            int cnt = 0;
            for (int j = 0; j < n; ++j) {
                if (i != j && grid[i][j] == 1) {
                    ++cnt;
                }
            }
            if (cnt == n - 1) {
                return i;
            }
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int i = 0;; ++i) {
            int cnt = 0;
            for (int j = 0; j < n; ++j) {
                if (i != j && grid[i][j] == 1) {
                    ++cnt;
                }
            }
            if (cnt == n - 1) {
                return i;
            }
        }
    }
};
```

#### Go

```go
func findChampion(grid [][]int) int {
	n := len(grid)
	for i := 0; ; i++ {
		cnt := 0
		for j, x := range grid[i] {
			if i != j && x == 1 {
				cnt++
			}
		}
		if cnt == n-1 {
			return i
		}
	}
}
```

#### TypeScript

```ts
function findChampion(grid: number[][]): number {
    for (let i = 0, n = grid.length; ; ++i) {
        let cnt = 0;
        for (let j = 0; j < n; ++j) {
            if (i !== j && grid[i][j] === 1) {
                ++cnt;
            }
        }
        if (cnt === n - 1) {
            return i;
        }
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2924. 找到冠军 II](https://leetcode.cn/problems/find-champion-ii){#2924}

{{< tabs "2924" >}}

{{% tab "python" %}}
```python
class Solution:
    def findChampion(self, n: int, edges: List[List[int]]) -> int:
        indeg = [0] * n
        for _, v in edges:
            indeg[v] += 1
        return -1 if indeg.count(0) != 1 else indeg.index(0)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int findChampion(int n, int[][] edges) {
        int[] indeg = new int[n];
        for (var e : edges) {
            ++indeg[e[1]];
        }
        int ans = -1, cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (indeg[i] == 0) {
                ++cnt;
                ans = i;
            }
        }
        return cnt == 1 ? ans : -1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        int indeg[n];
        memset(indeg, 0, sizeof(indeg));
        for (auto& e : edges) {
            ++indeg[e[1]];
        }
        int ans = -1, cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (indeg[i] == 0) {
                ++cnt;
                ans = i;
            }
        }
        return cnt == 1 ? ans : -1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findChampion(n int, edges [][]int) int {
	indeg := make([]int, n)
	for _, e := range edges {
		indeg[e[1]]++
	}
	ans, cnt := -1, 0
	for i, x := range indeg {
		if x == 0 {
			cnt++
			ans = i
		}
	}
	if cnt == 1 {
		return ans
	}
	return -1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findChampion(n: number, edges: number[][]): number {
    const vertexes = new Set<number>(Array.from({ length: n }, (_, i) => i));

    for (const [_, v] of edges) {
        vertexes.delete(v);
    }

    return vertexes.size === 1 ? vertexes[Symbol.iterator]().next().value! : -1;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
function findChampion(n, edges) {
    const vertexes = new Set(Array.from({ length: n }, (_, i) => i));
    for (const [_, v] of edges) {
        vertexes.delete(v);
    }
    return vertexes.size === 1 ? vertexes[Symbol.iterator]().next().value : -1;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>一场比赛中共有 <code>n</code> 支队伍，按从 <code>0</code> 到&nbsp; <code>n - 1</code> 编号。每支队伍也是 <strong>有向无环图（DAG）</strong> 上的一个节点。</p>

<p>给你一个整数 <code>n</code> 和一个下标从 <strong>0</strong> 开始、长度为 <code>m</code> 的二维整数数组 <code>edges</code> 表示这个有向无环图，其中 <code>edges[i] = [u<sub>i</sub>, v<sub>i</sub>]</code> 表示图中存在一条从 <code>u<sub>i</sub></code> 队到 <code>v<sub>i</sub></code> 队的有向边。</p>

<p>从 <code>a</code> 队到 <code>b</code> 队的有向边意味着 <code>a</code> 队比 <code>b</code> 队 <strong>强</strong> ，也就是 <code>b</code> 队比 <code>a</code> 队 <strong>弱</strong> 。</p>

<p>在这场比赛中，如果不存在某支强于 <code>a</code> 队的队伍，则认为 <code>a</code> 队将会是 <strong>冠军</strong> 。</p>

<p>如果这场比赛存在 <strong>唯一</strong> 一个冠军，则返回将会成为冠军的队伍。否则，返回<em> </em><code>-1</code><em> 。</em></p>

<p><strong>注意</strong></p>

<ul>
	<li><strong>环</strong> 是形如 <code>a<sub>1</sub>, a<sub>2</sub>, ..., a<sub>n</sub>, a<sub>n+1</sub></code> 的一个序列，且满足：节点 <code>a<sub>1</sub></code> 与节点 <code>a<sub>n+1</sub></code> 是同一个节点；节点 <code>a<sub>1</sub>, a<sub>2</sub>, ..., a<sub>n</sub></code> 互不相同；对于范围&nbsp;<code>[1, n]</code> 中的每个 <code>i</code> ，均存在一条从节点 <code>a<sub>i</sub></code> 到节点 <code>a<sub>i+1</sub></code> 的有向边。</li>
	<li><strong>有向无环图</strong> 是不存在任何环的有向图。</li>
</ul>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<p><img height="300" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2900-2999/2924.Find%20Champion%20II/images/graph-3.png" width="300" /></p>

<pre>
<strong>输入：</strong>n = 3, edges = [[0,1],[1,2]]
<strong>输出：</strong>0
<strong>解释：</strong>1 队比 0 队弱。2 队比 1 队弱。所以冠军是 0 队。
</pre>

<p><strong class="example">示例 2：</strong></p>

<p><img height="300" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2900-2999/2924.Find%20Champion%20II/images/graph-4.png" width="300" /></p>

<pre>
<strong>输入：</strong>n = 4, edges = [[0,2],[1,3],[1,2]]
<strong>输出：</strong>-1
<strong>解释：</strong>2 队比 0 队和 1 队弱。3 队比 1 队弱。但是 1 队和 0 队之间不存在强弱对比。所以答案是 -1 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>m == edges.length</code></li>
	<li><code>0 &lt;= m &lt;= n * (n - 1) / 2</code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>0 &lt;= edge[i][j] &lt;= n - 1</code></li>
	<li><code>edges[i][0] != edges[i][1]</code></li>
	<li>生成的输入满足：如果 <code>a</code> 队比 <code>b</code> 队强，就不存在 <code>b</code> 队比 <code>a</code> 队强</li>
	<li>生成的输入满足：如果 <code>a</code> 队比 <code>b</code> 队强，<code>b</code> 队比 <code>c</code> 队强，那么 <code>a</code> 队比 <code>c</code> 队强</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：统计入度

根据题目描述，我们只需要统计每个节点的入度，记录在数组 $indeg$ 中。如果只有一个节点的入度为 $0$，那么这个节点就是冠军，否则不存在唯一的冠军。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是节点的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findChampion(self, n: int, edges: List[List[int]]) -> int:
        indeg = [0] * n
        for _, v in edges:
            indeg[v] += 1
        return -1 if indeg.count(0) != 1 else indeg.index(0)
```

#### Java

```java
class Solution {
    public int findChampion(int n, int[][] edges) {
        int[] indeg = new int[n];
        for (var e : edges) {
            ++indeg[e[1]];
        }
        int ans = -1, cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (indeg[i] == 0) {
                ++cnt;
                ans = i;
            }
        }
        return cnt == 1 ? ans : -1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        int indeg[n];
        memset(indeg, 0, sizeof(indeg));
        for (auto& e : edges) {
            ++indeg[e[1]];
        }
        int ans = -1, cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (indeg[i] == 0) {
                ++cnt;
                ans = i;
            }
        }
        return cnt == 1 ? ans : -1;
    }
};
```

#### Go

```go
func findChampion(n int, edges [][]int) int {
	indeg := make([]int, n)
	for _, e := range edges {
		indeg[e[1]]++
	}
	ans, cnt := -1, 0
	for i, x := range indeg {
		if x == 0 {
			cnt++
			ans = i
		}
	}
	if cnt == 1 {
		return ans
	}
	return -1
}
```

#### TypeScript

```ts
function findChampion(n: number, edges: number[][]): number {
    const indeg: number[] = Array(n).fill(0);
    for (const [_, v] of edges) {
        ++indeg[v];
    }
    let [ans, cnt] = [-1, 0];
    for (let i = 0; i < n; ++i) {
        if (indeg[i] === 0) {
            ++cnt;
            ans = i;
        }
    }
    return cnt === 1 ? ans : -1;
}
```

#### JavaScript

```js
function findChampion(n, edges) {
    const indeg = Array(n).fill(0);
    for (const [_, v] of edges) {
        ++indeg[v];
    }
    let [ans, cnt] = [-1, 0];
    for (let i = 0; i < n; ++i) {
        if (indeg[i] === 0) {
            ++cnt;
            ans = i;
        }
    }
    return cnt === 1 ? ans : -1;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### TypeScript

```ts
function findChampion(n: number, edges: number[][]): number {
    const vertexes = new Set<number>(Array.from({ length: n }, (_, i) => i));

    for (const [_, v] of edges) {
        vertexes.delete(v);
    }

    return vertexes.size === 1 ? vertexes[Symbol.iterator]().next().value! : -1;
}
```

#### JavaScript

```js
function findChampion(n, edges) {
    const vertexes = new Set(Array.from({ length: n }, (_, i) => i));
    for (const [_, v] of edges) {
        vertexes.delete(v);
    }
    return vertexes.size === 1 ? vertexes[Symbol.iterator]().next().value : -1;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2925. 在树上执行操作以后得到的最大分数](https://leetcode.cn/problems/maximum-score-after-applying-operations-on-a-tree){#2925}

{{< tabs "2925" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumScoreAfterOperations(
        self, edges: List[List[int]], values: List[int]
    ) -> int:
        def dfs(i: int, fa: int = -1) -> (int, int):
            a = b = 0
            leaf = True
            for j in g[i]:
                if j != fa:
                    leaf = False
                    aa, bb = dfs(j, i)
                    a += aa
                    b += bb
            if leaf:
                return values[i], 0
            return values[i] + a, max(values[i] + b, a)

        g = [[] for _ in range(len(values))]
        for a, b in edges:
            g[a].append(b)
            g[b].append(a)
        return dfs(0)[1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private List<Integer>[] g;
    private int[] values;

    public long maximumScoreAfterOperations(int[][] edges, int[] values) {
        int n = values.length;
        g = new List[n];
        this.values = values;
        Arrays.setAll(g, k -> new ArrayList<>());
        for (var e : edges) {
            int a = e[0], b = e[1];
            g[a].add(b);
            g[b].add(a);
        }
        return dfs(0, -1)[1];
    }

    private long[] dfs(int i, int fa) {
        long a = 0, b = 0;
        boolean leaf = true;
        for (int j : g[i]) {
            if (j != fa) {
                leaf = false;
                var t = dfs(j, i);
                a += t[0];
                b += t[1];
            }
        }
        if (leaf) {
            return new long[] {values[i], 0};
        }
        return new long[] {values[i] + a, Math.max(values[i] + b, a)};
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        int n = values.size();
        vector<int> g[n];
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            g[a].emplace_back(b);
            g[b].emplace_back(a);
        }
        using ll = long long;
        function<pair<ll, ll>(int, int)> dfs = [&](int i, int fa) -> pair<ll, ll> {
            ll a = 0, b = 0;
            bool leaf = true;
            for (int j : g[i]) {
                if (j != fa) {
                    auto [aa, bb] = dfs(j, i);
                    a += aa;
                    b += bb;
                    leaf = false;
                }
            }
            if (leaf) {
                return {values[i], 0LL};
            }
            return {values[i] + a, max(values[i] + b, a)};
        };
        auto [_, b] = dfs(0, -1);
        return b;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumScoreAfterOperations(edges [][]int, values []int) int64 {
	g := make([][]int, len(values))
	for _, e := range edges {
		a, b := e[0], e[1]
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}
	var dfs func(int, int) (int64, int64)
	dfs = func(i, fa int) (int64, int64) {
		a, b := int64(0), int64(0)
		leaf := true
		for _, j := range g[i] {
			if j != fa {
				leaf = false
				aa, bb := dfs(j, i)
				a += aa
				b += bb
			}
		}
		if leaf {
			return int64(values[i]), int64(0)
		}
		return int64(values[i]) + a, max(int64(values[i])+b, a)
	}
	_, b := dfs(0, -1)
	return b
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumScoreAfterOperations(edges: number[][], values: number[]): number {
    const g: number[][] = Array.from({ length: values.length }, () => []);
    for (const [a, b] of edges) {
        g[a].push(b);
        g[b].push(a);
    }
    const dfs = (i: number, fa: number): [number, number] => {
        let [a, b] = [0, 0];
        let leaf = true;
        for (const j of g[i]) {
            if (j !== fa) {
                const [aa, bb] = dfs(j, i);
                a += aa;
                b += bb;
                leaf = false;
            }
        }
        if (leaf) {
            return [values[i], 0];
        }
        return [values[i] + a, Math.max(values[i] + b, a)];
    };
    return dfs(0, -1)[1];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>有一棵 <code>n</code>&nbsp;个节点的无向树，节点编号为 <code>0</code>&nbsp;到 <code>n - 1</code>&nbsp;，根节点编号为 <code>0</code>&nbsp;。给你一个长度为 <code>n - 1</code>&nbsp;的二维整数数组&nbsp;<code>edges</code>&nbsp;表示这棵树，其中&nbsp;<code>edges[i] = [a<sub>i</sub>, b<sub>i</sub>]</code>&nbsp;表示树中节点&nbsp;<code>a<sub>i</sub></code>&nbsp;和&nbsp;<code>b<sub>i</sub></code>&nbsp;有一条边。</p>

<p>同时给你一个长度为 <code>n</code>&nbsp;下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>values</code>&nbsp;，其中&nbsp;<code>values[i]</code>&nbsp;表示第 <code>i</code>&nbsp;个节点的值。</p>

<p>一开始你的分数为 <code>0</code>&nbsp;，每次操作中，你将执行：</p>

<ul>
	<li>选择节点&nbsp;<code>i</code>&nbsp;。</li>
	<li>将&nbsp;<code>values[i]</code>&nbsp;加入你的分数。</li>
	<li>将&nbsp;<code>values[i]</code>&nbsp;变为&nbsp;<code>0</code>&nbsp;。</li>
</ul>

<p>如果从根节点出发，到任意叶子节点经过的路径上的节点值之和都不等于 0 ，那么我们称这棵树是 <strong>健康的</strong>&nbsp;。</p>

<p>你可以对这棵树执行任意次操作，但要求执行完所有操作以后树是&nbsp;<strong>健康的</strong>&nbsp;，请你返回你可以获得的 <strong>最大分数</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2900-2999/2925.Maximum%20Score%20After%20Applying%20Operations%20on%20a%20Tree/images/graph-13-1.png" style="width: 515px; height: 443px;" /></p>

<pre>
<b>输入：</b>edges = [[0,1],[0,2],[0,3],[2,4],[4,5]], values = [5,2,5,2,1,1]
<b>输出：</b>11
<b>解释：</b>我们可以选择节点 1 ，2 ，3 ，4 和 5 。根节点的值是非 0 的。所以从根出发到任意叶子节点路径上节点值之和都不为 0 。所以树是健康的。你的得分之和为 values[1] + values[2] + values[3] + values[4] + values[5] = 11 。
11 是你对树执行任意次操作以后可以获得的最大得分之和。
</pre>

<p><strong class="example">示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2900-2999/2925.Maximum%20Score%20After%20Applying%20Operations%20on%20a%20Tree/images/graph-14-2.png" style="width: 522px; height: 245px;" /></p>

<pre>
<b>输入：</b>edges = [[0,1],[0,2],[1,3],[1,4],[2,5],[2,6]], values = [20,10,9,7,4,3,5]
<b>输出：</b>40
<b>解释：</b>我们选择节点 0 ，2 ，3 和 4 。
- 从 0 到 4 的节点值之和为 10 。
- 从 0 到 3 的节点值之和为 10 。
- 从 0 到 5 的节点值之和为 3 。
- 从 0 到 6 的节点值之和为 5 。
所以树是健康的。你的得分之和为 values[0] + values[2] + values[3] + values[4] = 40 。
40 是你对树执行任意次操作以后可以获得的最大得分之和。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>edges.length == n - 1</code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt; n</code></li>
	<li><code>values.length == n</code></li>
	<li><code>1 &lt;= values[i] &lt;= 10<sup>9</sup></code></li>
	<li>输入保证&nbsp;<code>edges</code>&nbsp;构成一棵合法的树。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：树形 DP

题目实际上是让我们从树的所有节点中选出一些节点，使得这些节点的值之和最大，并且每条从根节点到叶子节点的路径上都有一个点没有被选中。

我们可以使用树形 DP 的方法解决这个问题。

我们设计一个函数 $dfs(i, fa)$，其中 $i$ 表示当前以节点 $i$ 作为子树的根节点，且 $fa$ 表示 $i$ 的父节点，函数返回一个长度为 $2$ 的数组，其中 $[0]$ 表示该子树中所有节点的值之和，而 $[1]$ 表示该子树满足每条路径上都有一个点没有被选中的最大值。

其中 $[0]$ 的值可以直接通过 DFS 累加每个节点的值得到，而 $[1]$ 的值，则需要考虑两种情况，即节点 $i$ 是否被选中。如果被选中，那么节点 $i$ 的每个子树得必须满足每条路径上都有一个点没有被选中；如果没有被选中，那么节点 $i$ 的每个子树可以选取所有节点。我们取这两种情况中的最大值即可。

需要注意的是，叶子节点的 $[1]$ 的值为 $0$，因为叶子节点没有子树，所以不需要考虑每条路径上都有一个点没有被选中的情况。

答案为 $dfs(0, -1)[1]$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为节点数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumScoreAfterOperations(
        self, edges: List[List[int]], values: List[int]
    ) -> int:
        def dfs(i: int, fa: int = -1) -> (int, int):
            a = b = 0
            leaf = True
            for j in g[i]:
                if j != fa:
                    leaf = False
                    aa, bb = dfs(j, i)
                    a += aa
                    b += bb
            if leaf:
                return values[i], 0
            return values[i] + a, max(values[i] + b, a)

        g = [[] for _ in range(len(values))]
        for a, b in edges:
            g[a].append(b)
            g[b].append(a)
        return dfs(0)[1]
```

#### Java

```java
class Solution {
    private List<Integer>[] g;
    private int[] values;

    public long maximumScoreAfterOperations(int[][] edges, int[] values) {
        int n = values.length;
        g = new List[n];
        this.values = values;
        Arrays.setAll(g, k -> new ArrayList<>());
        for (var e : edges) {
            int a = e[0], b = e[1];
            g[a].add(b);
            g[b].add(a);
        }
        return dfs(0, -1)[1];
    }

    private long[] dfs(int i, int fa) {
        long a = 0, b = 0;
        boolean leaf = true;
        for (int j : g[i]) {
            if (j != fa) {
                leaf = false;
                var t = dfs(j, i);
                a += t[0];
                b += t[1];
            }
        }
        if (leaf) {
            return new long[] {values[i], 0};
        }
        return new long[] {values[i] + a, Math.max(values[i] + b, a)};
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        int n = values.size();
        vector<int> g[n];
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            g[a].emplace_back(b);
            g[b].emplace_back(a);
        }
        using ll = long long;
        function<pair<ll, ll>(int, int)> dfs = [&](int i, int fa) -> pair<ll, ll> {
            ll a = 0, b = 0;
            bool leaf = true;
            for (int j : g[i]) {
                if (j != fa) {
                    auto [aa, bb] = dfs(j, i);
                    a += aa;
                    b += bb;
                    leaf = false;
                }
            }
            if (leaf) {
                return {values[i], 0LL};
            }
            return {values[i] + a, max(values[i] + b, a)};
        };
        auto [_, b] = dfs(0, -1);
        return b;
    }
};
```

#### Go

```go
func maximumScoreAfterOperations(edges [][]int, values []int) int64 {
	g := make([][]int, len(values))
	for _, e := range edges {
		a, b := e[0], e[1]
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}
	var dfs func(int, int) (int64, int64)
	dfs = func(i, fa int) (int64, int64) {
		a, b := int64(0), int64(0)
		leaf := true
		for _, j := range g[i] {
			if j != fa {
				leaf = false
				aa, bb := dfs(j, i)
				a += aa
				b += bb
			}
		}
		if leaf {
			return int64(values[i]), int64(0)
		}
		return int64(values[i]) + a, max(int64(values[i])+b, a)
	}
	_, b := dfs(0, -1)
	return b
}
```

#### TypeScript

```ts
function maximumScoreAfterOperations(edges: number[][], values: number[]): number {
    const g: number[][] = Array.from({ length: values.length }, () => []);
    for (const [a, b] of edges) {
        g[a].push(b);
        g[b].push(a);
    }
    const dfs = (i: number, fa: number): [number, number] => {
        let [a, b] = [0, 0];
        let leaf = true;
        for (const j of g[i]) {
            if (j !== fa) {
                const [aa, bb] = dfs(j, i);
                a += aa;
                b += bb;
                leaf = false;
            }
        }
        if (leaf) {
            return [values[i], 0];
        }
        return [values[i] + a, Math.max(values[i] + b, a)];
    };
    return dfs(0, -1)[1];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2926. 平衡子序列的最大和](https://leetcode.cn/problems/maximum-balanced-subsequence-sum){#2926}

{{< tabs "2926" >}}

{{% tab "python" %}}
```python
class BinaryIndexedTree:
    def __init__(self, n: int):
        self.n = n
        self.c = [-inf] * (n + 1)

    def update(self, x: int, v: int):
        while x <= self.n:
            self.c[x] = max(self.c[x], v)
            x += x & -x

    def query(self, x: int) -> int:
        mx = -inf
        while x:
            mx = max(mx, self.c[x])
            x -= x & -x
        return mx


class Solution:
    def maxBalancedSubsequenceSum(self, nums: List[int]) -> int:
        arr = [x - i for i, x in enumerate(nums)]
        s = sorted(set(arr))
        tree = BinaryIndexedTree(len(s))
        for i, x in enumerate(nums):
            j = bisect_left(s, x - i) + 1
            v = max(tree.query(j), 0) + x
            tree.update(j, v)
        return tree.query(len(s))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class BinaryIndexedTree {
    private int n;
    private long[] c;
    private final long inf = 1L << 60;

    public BinaryIndexedTree(int n) {
        this.n = n;
        c = new long[n + 1];
        Arrays.fill(c, -inf);
    }

    public void update(int x, long v) {
        while (x <= n) {
            c[x] = Math.max(c[x], v);
            x += x & -x;
        }
    }

    public long query(int x) {
        long mx = -inf;
        while (x > 0) {
            mx = Math.max(mx, c[x]);
            x -= x & -x;
        }
        return mx;
    }
}

class Solution {
    public long maxBalancedSubsequenceSum(int[] nums) {
        int n = nums.length;
        int[] arr = new int[n];
        for (int i = 0; i < n; ++i) {
            arr[i] = nums[i] - i;
        }
        Arrays.sort(arr);
        int m = 0;
        for (int i = 0; i < n; ++i) {
            if (i == 0 || arr[i] != arr[i - 1]) {
                arr[m++] = arr[i];
            }
        }
        BinaryIndexedTree tree = new BinaryIndexedTree(m);
        for (int i = 0; i < n; ++i) {
            int j = search(arr, nums[i] - i, m) + 1;
            long v = Math.max(tree.query(j), 0) + nums[i];
            tree.update(j, v);
        }
        return tree.query(m);
    }

    private int search(int[] nums, int x, int r) {
        int l = 0;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class BinaryIndexedTree {
private:
    int n;
    vector<long long> c;
    const long long inf = 1e18;

public:
    BinaryIndexedTree(int n) {
        this->n = n;
        c.resize(n + 1, -inf);
    }

    void update(int x, long long v) {
        while (x <= n) {
            c[x] = max(c[x], v);
            x += x & -x;
        }
    }

    long long query(int x) {
        long long mx = -inf;
        while (x > 0) {
            mx = max(mx, c[x]);
            x -= x & -x;
        }
        return mx;
    }
};

class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = nums[i] - i;
        }
        sort(arr.begin(), arr.end());
        arr.erase(unique(arr.begin(), arr.end()), arr.end());
        int m = arr.size();
        BinaryIndexedTree tree(m);
        for (int i = 0; i < n; ++i) {
            int j = lower_bound(arr.begin(), arr.end(), nums[i] - i) - arr.begin() + 1;
            long long v = max(tree.query(j), 0LL) + nums[i];
            tree.update(j, v);
        }
        return tree.query(m);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
const inf int = 1e18

type BinaryIndexedTree struct {
	n int
	c []int
}

func NewBinaryIndexedTree(n int) BinaryIndexedTree {
	c := make([]int, n+1)
	for i := range c {
		c[i] = -inf
	}
	return BinaryIndexedTree{n: n, c: c}
}

func (bit *BinaryIndexedTree) update(x, v int) {
	for x <= bit.n {
		bit.c[x] = max(bit.c[x], v)
		x += x & -x
	}
}

func (bit *BinaryIndexedTree) query(x int) int {
	mx := -inf
	for x > 0 {
		mx = max(mx, bit.c[x])
		x -= x & -x
	}
	return mx
}

func maxBalancedSubsequenceSum(nums []int) int64 {
	n := len(nums)
	arr := make([]int, n)
	for i, x := range nums {
		arr[i] = x - i
	}
	sort.Ints(arr)
	m := 0
	for i, x := range arr {
		if i == 0 || x != arr[i-1] {
			arr[m] = x
			m++
		}
	}
	arr = arr[:m]
	tree := NewBinaryIndexedTree(m)
	for i, x := range nums {
		j := sort.SearchInts(arr, x-i) + 1
		v := max(tree.query(j), 0) + x
		tree.update(j, v)
	}
	return int64(tree.query(m))
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
        this.c = Array(n + 1).fill(-Infinity);
    }

    update(x: number, v: number): void {
        while (x <= this.n) {
            this.c[x] = Math.max(this.c[x], v);
            x += x & -x;
        }
    }

    query(x: number): number {
        let mx = -Infinity;
        while (x > 0) {
            mx = Math.max(mx, this.c[x]);
            x -= x & -x;
        }
        return mx;
    }
}

function maxBalancedSubsequenceSum(nums: number[]): number {
    const n = nums.length;
    const arr = Array(n).fill(0);
    for (let i = 0; i < n; ++i) {
        arr[i] = nums[i] - i;
    }
    arr.sort((a, b) => a - b);
    let m = 0;
    for (let i = 0; i < n; ++i) {
        if (i === 0 || arr[i] !== arr[i - 1]) {
            arr[m++] = arr[i];
        }
    }
    arr.length = m;
    const tree = new BinaryIndexedTree(m);
    const search = (nums: number[], x: number): number => {
        let [l, r] = [0, nums.length];
        while (l < r) {
            const mid = (l + r) >> 1;
            if (nums[mid] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    };
    for (let i = 0; i < n; ++i) {
        const j = search(arr, nums[i] - i) + 1;
        const v = Math.max(tree.query(j), 0) + nums[i];
        tree.update(j, v);
    }
    return tree.query(m);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>nums</code>&nbsp;。</p>

<p><code>nums</code>&nbsp;一个长度为 <code>k</code>&nbsp;的 <strong>子序列</strong>&nbsp;指的是选出 <code>k</code>&nbsp;个 <strong>下标</strong>&nbsp;<code>i<sub>0</sub>&nbsp;&lt;&nbsp;i<sub>1</sub> &lt;&nbsp;... &lt; i<sub>k-1</sub></code>&nbsp;，如果这个子序列满足以下条件，我们说它是 <strong>平衡的</strong>&nbsp;：</p>

<ul>
	<li>对于范围&nbsp;<code>[1, k - 1]</code>&nbsp;内的所有&nbsp;<code>j</code>&nbsp;，<code>nums[i<sub>j</sub>] - nums[i<sub>j-1</sub>] &gt;= i<sub>j</sub> - i<sub>j-1</sub></code>&nbsp;都成立。</li>
</ul>

<p><code>nums</code>&nbsp;长度为 <code>1</code>&nbsp;的 <strong>子序列</strong>&nbsp;是平衡的。</p>

<p>请你返回一个整数，表示 <code>nums</code>&nbsp;<strong>平衡</strong>&nbsp;子序列里面的 <strong>最大元素和</strong>&nbsp;。</p>

<p>一个数组的 <strong>子序列</strong>&nbsp;指的是从原数组中删除一些元素（<strong>也可能一个元素也不删除</strong>）后，剩余元素保持相对顺序得到的 <strong>非空</strong>&nbsp;新数组。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [3,3,5,6]
<b>输出：</b>14
<b>解释：</b>这个例子中，选择子序列 [3,5,6] ，下标为 0 ，2 和 3 的元素被选中。
nums[2] - nums[0] &gt;= 2 - 0 。
nums[3] - nums[2] &gt;= 3 - 2 。
所以，这是一个平衡子序列，且它的和是所有平衡子序列里最大的。
包含下标 1 ，2 和 3 的子序列也是一个平衡的子序列。
最大平衡子序列和为 14 。</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [5,-1,-3,8]
<b>输出：</b>13
<b>解释：</b>这个例子中，选择子序列 [5,8] ，下标为 0 和 3 的元素被选中。
nums[3] - nums[0] &gt;= 3 - 0 。
所以，这是一个平衡子序列，且它的和是所有平衡子序列里最大的。
最大平衡子序列和为 13 。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>nums = [-2,-1]
<b>输出：</b>-1
<b>解释：</b>这个例子中，选择子序列 [-1] 。
这是一个平衡子序列，而且它的和是 nums 所有平衡子序列里最大的。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划 + 树状数组

根据题目描述，我们可以将不等式 $nums[i] - nums[j] \ge i - j$ 转化为 $nums[i] - i \ge nums[j] - j$，因此，我们考虑定义一个新数组 $arr$，其中 $arr[i] = nums[i] - i$，那么平衡子序列满足对于任意 $j \lt i$，都有 $arr[j] \le arr[i]$。即题目转换为求在 $arr$ 中选出一个递增子序列，使得对应的 $nums$ 的和最大。

假设 $i$ 是子序列中最后一个元素的下标，那么我们考虑子序列倒数第二个元素的下标 $j$，如果 $arr[j] \le arr[i]$，我们可以考虑是否要将 $j$ 加入到子序列中。

因此，我们定义 $f[i]$ 表示子序列最后一个元素的下标为 $i$ 时，对应的 $nums$ 的最大和，那么答案为 $\max_{i=0}^{n-1} f[i]$。

状态转移方程为：

$$
f[i] = \max(\max_{j=0}^{i-1} f[j], 0) + nums[i]
$$

其中 $j$ 满足 $arr[j] \le arr[i]$。

我们可以使用树状数组来维护前缀的最大值，即对于每个 $arr[i]$，我们维护前缀 $arr[0..i]$ 中 $f[i]$ 的最大值。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class BinaryIndexedTree:
    def __init__(self, n: int):
        self.n = n
        self.c = [-inf] * (n + 1)

    def update(self, x: int, v: int):
        while x <= self.n:
            self.c[x] = max(self.c[x], v)
            x += x & -x

    def query(self, x: int) -> int:
        mx = -inf
        while x:
            mx = max(mx, self.c[x])
            x -= x & -x
        return mx


class Solution:
    def maxBalancedSubsequenceSum(self, nums: List[int]) -> int:
        arr = [x - i for i, x in enumerate(nums)]
        s = sorted(set(arr))
        tree = BinaryIndexedTree(len(s))
        for i, x in enumerate(nums):
            j = bisect_left(s, x - i) + 1
            v = max(tree.query(j), 0) + x
            tree.update(j, v)
        return tree.query(len(s))
```

#### Java

```java
class BinaryIndexedTree {
    private int n;
    private long[] c;
    private final long inf = 1L << 60;

    public BinaryIndexedTree(int n) {
        this.n = n;
        c = new long[n + 1];
        Arrays.fill(c, -inf);
    }

    public void update(int x, long v) {
        while (x <= n) {
            c[x] = Math.max(c[x], v);
            x += x & -x;
        }
    }

    public long query(int x) {
        long mx = -inf;
        while (x > 0) {
            mx = Math.max(mx, c[x]);
            x -= x & -x;
        }
        return mx;
    }
}

class Solution {
    public long maxBalancedSubsequenceSum(int[] nums) {
        int n = nums.length;
        int[] arr = new int[n];
        for (int i = 0; i < n; ++i) {
            arr[i] = nums[i] - i;
        }
        Arrays.sort(arr);
        int m = 0;
        for (int i = 0; i < n; ++i) {
            if (i == 0 || arr[i] != arr[i - 1]) {
                arr[m++] = arr[i];
            }
        }
        BinaryIndexedTree tree = new BinaryIndexedTree(m);
        for (int i = 0; i < n; ++i) {
            int j = search(arr, nums[i] - i, m) + 1;
            long v = Math.max(tree.query(j), 0) + nums[i];
            tree.update(j, v);
        }
        return tree.query(m);
    }

    private int search(int[] nums, int x, int r) {
        int l = 0;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
}
```

#### C++

```cpp
class BinaryIndexedTree {
private:
    int n;
    vector<long long> c;
    const long long inf = 1e18;

public:
    BinaryIndexedTree(int n) {
        this->n = n;
        c.resize(n + 1, -inf);
    }

    void update(int x, long long v) {
        while (x <= n) {
            c[x] = max(c[x], v);
            x += x & -x;
        }
    }

    long long query(int x) {
        long long mx = -inf;
        while (x > 0) {
            mx = max(mx, c[x]);
            x -= x & -x;
        }
        return mx;
    }
};

class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = nums[i] - i;
        }
        sort(arr.begin(), arr.end());
        arr.erase(unique(arr.begin(), arr.end()), arr.end());
        int m = arr.size();
        BinaryIndexedTree tree(m);
        for (int i = 0; i < n; ++i) {
            int j = lower_bound(arr.begin(), arr.end(), nums[i] - i) - arr.begin() + 1;
            long long v = max(tree.query(j), 0LL) + nums[i];
            tree.update(j, v);
        }
        return tree.query(m);
    }
};
```

#### Go

```go
const inf int = 1e18

type BinaryIndexedTree struct {
	n int
	c []int
}

func NewBinaryIndexedTree(n int) BinaryIndexedTree {
	c := make([]int, n+1)
	for i := range c {
		c[i] = -inf
	}
	return BinaryIndexedTree{n: n, c: c}
}

func (bit *BinaryIndexedTree) update(x, v int) {
	for x <= bit.n {
		bit.c[x] = max(bit.c[x], v)
		x += x & -x
	}
}

func (bit *BinaryIndexedTree) query(x int) int {
	mx := -inf
	for x > 0 {
		mx = max(mx, bit.c[x])
		x -= x & -x
	}
	return mx
}

func maxBalancedSubsequenceSum(nums []int) int64 {
	n := len(nums)
	arr := make([]int, n)
	for i, x := range nums {
		arr[i] = x - i
	}
	sort.Ints(arr)
	m := 0
	for i, x := range arr {
		if i == 0 || x != arr[i-1] {
			arr[m] = x
			m++
		}
	}
	arr = arr[:m]
	tree := NewBinaryIndexedTree(m)
	for i, x := range nums {
		j := sort.SearchInts(arr, x-i) + 1
		v := max(tree.query(j), 0) + x
		tree.update(j, v)
	}
	return int64(tree.query(m))
}
```

#### TypeScript

```ts
class BinaryIndexedTree {
    private n: number;
    private c: number[];

    constructor(n: number) {
        this.n = n;
        this.c = Array(n + 1).fill(-Infinity);
    }

    update(x: number, v: number): void {
        while (x <= this.n) {
            this.c[x] = Math.max(this.c[x], v);
            x += x & -x;
        }
    }

    query(x: number): number {
        let mx = -Infinity;
        while (x > 0) {
            mx = Math.max(mx, this.c[x]);
            x -= x & -x;
        }
        return mx;
    }
}

function maxBalancedSubsequenceSum(nums: number[]): number {
    const n = nums.length;
    const arr = Array(n).fill(0);
    for (let i = 0; i < n; ++i) {
        arr[i] = nums[i] - i;
    }
    arr.sort((a, b) => a - b);
    let m = 0;
    for (let i = 0; i < n; ++i) {
        if (i === 0 || arr[i] !== arr[i - 1]) {
            arr[m++] = arr[i];
        }
    }
    arr.length = m;
    const tree = new BinaryIndexedTree(m);
    const search = (nums: number[], x: number): number => {
        let [l, r] = [0, nums.length];
        while (l < r) {
            const mid = (l + r) >> 1;
            if (nums[mid] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    };
    for (let i = 0; i < n; ++i) {
        const j = search(arr, nums[i] - i) + 1;
        const v = Math.max(tree.query(j), 0) + nums[i];
        tree.update(j, v);
    }
    return tree.query(m);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2927. 给小朋友们分糖果 III 🔒](https://leetcode.cn/problems/distribute-candies-among-children-iii){#2927}

{{< tabs "2927" >}}

{{% tab "python" %}}
```python
class Solution:
    def distributeCandies(self, n: int, limit: int) -> int:
        if n > 3 * limit:
            return 0
        ans = comb(n + 2, 2)
        if n > limit:
            ans -= 3 * comb(n - limit + 1, 2)
        if n - 2 >= 2 * limit:
            ans += 3 * comb(n - 2 * limit, 2)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long distributeCandies(int n, int limit) {
        if (n > 3 * limit) {
            return 0;
        }
        long ans = comb2(n + 2);
        if (n > limit) {
            ans -= 3 * comb2(n - limit + 1);
        }
        if (n - 2 >= 2 * limit) {
            ans += 3 * comb2(n - 2 * limit);
        }
        return ans;
    }

    private long comb2(int n) {
        return 1L * n * (n - 1) / 2;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    long long distributeCandies(int n, int limit) {
        auto comb2 = [](int n) {
            return 1LL * n * (n - 1) / 2;
        };
        if (n > 3 * limit) {
            return 0;
        }
        long long ans = comb2(n + 2);
        if (n > limit) {
            ans -= 3 * comb2(n - limit + 1);
        }
        if (n - 2 >= 2 * limit) {
            ans += 3 * comb2(n - 2 * limit);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func distributeCandies(n int, limit int) int64 {
	comb2 := func(n int) int {
		return n * (n - 1) / 2
	}
	if n > 3*limit {
		return 0
	}
	ans := comb2(n + 2)
	if n > limit {
		ans -= 3 * comb2(n-limit+1)
	}
	if n-2 >= 2*limit {
		ans += 3 * comb2(n-2*limit)
	}
	return int64(ans)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function distributeCandies(n: number, limit: number): number {
    const comb2 = (n: number) => (n * (n - 1)) / 2;
    if (n > 3 * limit) {
        return 0;
    }
    let ans = comb2(n + 2);
    if (n > limit) {
        ans -= 3 * comb2(n - limit + 1);
    }
    if (n - 2 >= 2 * limit) {
        ans += 3 * comb2(n - 2 * limit);
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

<p>你被给定两个正整数 <code>n</code> 和 <code>limit</code>。</p>

<p>返回 <em>在每个孩子得到不超过&nbsp;</em><code>limit</code><em> 个糖果的情况下，将</em> <code>n</code> <em>个糖果分发给</em>&nbsp;<code>3</code> <em>个孩子的&nbsp;<strong>总方法数</strong>。</em></p>

<p>&nbsp;</p>

<p><b>示例 1:</b></p>

<pre>
<b>输入：</b>n = 5, limit = 2
<b>输出：</b>3
<b>解释：</b>有 3 种方式将 5 个糖果分发给 3 个孩子，使得每个孩子得到不超过 2 个糖果：(1, 2, 2), (2, 1, 2) 和 (2, 2, 1)。
</pre>

<p><b>示例 2:</b></p>

<pre>
<b>输入：</b>n = 3, limit = 3
<b>输出：</b>10
<b>解释：</b>有 10 种方式将 3 个糖果分发给 3 个孩子，使得每个孩子得到不超过 3 个糖果：(0, 0, 3), (0, 1, 2), (0, 2, 1), (0, 3, 0), (1, 0, 2), (1, 1, 1), (1, 2, 0), (2, 0, 1), (2, 1, 0) 和 (3, 0, 0)。
</pre>

<p>&nbsp;</p>

<p><b>提示：</b></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>8</sup></code></li>
	<li><code>1 &lt;= limit &lt;= 10<sup>8</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：组合数学 + 容斥原理

根据题目描述，我们需要将 $n$ 个糖果分给 $3$ 个小孩，每个小孩分到的糖果数在 $[0, limit]$ 之间。

这实际上等价于把 $n$ 个球放入 $3$ 个盒子中。由于盒子可以为空，我们可以再增加 $3$ 个虚拟球，然后再利用隔板法，即一共有 $n + 3$ 个球，我们在其中 $n + 3 - 1$ 个位置插入 $2$ 个隔板，从而将实际的 $n$ 个球分成 $3$ 组，并且允许盒子为空，因此初始方案数为 $C_{n + 2}^2$。

我们需要在这些方案中，排除掉存在盒子分到的小球数超过 $limit$ 的方案。考虑其中有一个盒子分到的小球数超过 $limit$，那么剩下的球（包括虚拟球）最多有 $n + 3 - (limit + 1) = n - limit + 2$ 个，位置数为 $n - limit + 1$，因此方案数为 $C_{n - limit + 1}^2$。由于存在 $3$ 个盒子，因此这样的方案数为 $3 \times C_{n - limit + 1}^2$。这样子算，我们会多排除掉同时存在两个盒子分到的小球数超过 $limit$ 的方案，因此我们需要再加上这样的方案数，即 $3 \times C_{n - 2 \times limit}^2$。

时间复杂度 $O(1)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def distributeCandies(self, n: int, limit: int) -> int:
        if n > 3 * limit:
            return 0
        ans = comb(n + 2, 2)
        if n > limit:
            ans -= 3 * comb(n - limit + 1, 2)
        if n - 2 >= 2 * limit:
            ans += 3 * comb(n - 2 * limit, 2)
        return ans
```

#### Java

```java
class Solution {
    public long distributeCandies(int n, int limit) {
        if (n > 3 * limit) {
            return 0;
        }
        long ans = comb2(n + 2);
        if (n > limit) {
            ans -= 3 * comb2(n - limit + 1);
        }
        if (n - 2 >= 2 * limit) {
            ans += 3 * comb2(n - 2 * limit);
        }
        return ans;
    }

    private long comb2(int n) {
        return 1L * n * (n - 1) / 2;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long distributeCandies(int n, int limit) {
        auto comb2 = [](int n) {
            return 1LL * n * (n - 1) / 2;
        };
        if (n > 3 * limit) {
            return 0;
        }
        long long ans = comb2(n + 2);
        if (n > limit) {
            ans -= 3 * comb2(n - limit + 1);
        }
        if (n - 2 >= 2 * limit) {
            ans += 3 * comb2(n - 2 * limit);
        }
        return ans;
    }
};
```

#### Go

```go
func distributeCandies(n int, limit int) int64 {
	comb2 := func(n int) int {
		return n * (n - 1) / 2
	}
	if n > 3*limit {
		return 0
	}
	ans := comb2(n + 2)
	if n > limit {
		ans -= 3 * comb2(n-limit+1)
	}
	if n-2 >= 2*limit {
		ans += 3 * comb2(n-2*limit)
	}
	return int64(ans)
}
```

#### TypeScript

```ts
function distributeCandies(n: number, limit: number): number {
    const comb2 = (n: number) => (n * (n - 1)) / 2;
    if (n > 3 * limit) {
        return 0;
    }
    let ans = comb2(n + 2);
    if (n > limit) {
        ans -= 3 * comb2(n - limit + 1);
    }
    if (n - 2 >= 2 * limit) {
        ans += 3 * comb2(n - 2 * limit);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2928. 给小朋友们分糖果 I](https://leetcode.cn/problems/distribute-candies-among-children-i){#2928}

{{< tabs "2928" >}}

{{% tab "python" %}}
```python
class Solution:
    def distributeCandies(self, n: int, limit: int) -> int:
        if n > 3 * limit:
            return 0
        ans = comb(n + 2, 2)
        if n > limit:
            ans -= 3 * comb(n - limit + 1, 2)
        if n - 2 >= 2 * limit:
            ans += 3 * comb(n - 2 * limit, 2)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int distributeCandies(int n, int limit) {
        if (n > 3 * limit) {
            return 0;
        }
        long ans = comb2(n + 2);
        if (n > limit) {
            ans -= 3 * comb2(n - limit + 1);
        }
        if (n - 2 >= 2 * limit) {
            ans += 3 * comb2(n - 2 * limit);
        }
        return (int) ans;
    }

    private long comb2(int n) {
        return 1L * n * (n - 1) / 2;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int distributeCandies(int n, int limit) {
        auto comb2 = [](int n) {
            return 1LL * n * (n - 1) / 2;
        };
        if (n > 3 * limit) {
            return 0;
        }
        long long ans = comb2(n + 2);
        if (n > limit) {
            ans -= 3 * comb2(n - limit + 1);
        }
        if (n - 2 >= 2 * limit) {
            ans += 3 * comb2(n - 2 * limit);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func distributeCandies(n int, limit int) int {
	comb2 := func(n int) int {
		return n * (n - 1) / 2
	}
	if n > 3*limit {
		return 0
	}
	ans := comb2(n + 2)
	if n > limit {
		ans -= 3 * comb2(n-limit+1)
	}
	if n-2 >= 2*limit {
		ans += 3 * comb2(n-2*limit)
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function distributeCandies(n: number, limit: number): number {
    const comb2 = (n: number) => (n * (n - 1)) / 2;
    if (n > 3 * limit) {
        return 0;
    }
    let ans = comb2(n + 2);
    if (n > limit) {
        ans -= 3 * comb2(n - limit + 1);
    }
    if (n - 2 >= 2 * limit) {
        ans += 3 * comb2(n - 2 * limit);
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

<p>给你两个正整数&nbsp;<code>n</code> 和&nbsp;<code>limit</code>&nbsp;。</p>

<p>请你将 <code>n</code>&nbsp;颗糖果分给 <code>3</code>&nbsp;位小朋友，确保没有任何小朋友得到超过 <code>limit</code>&nbsp;颗糖果，请你返回满足此条件下的&nbsp;<strong>总方案数</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>n = 5, limit = 2
<b>输出：</b>3
<b>解释：</b>总共有 3 种方法分配 5 颗糖果，且每位小朋友的糖果数不超过 2 ：(1, 2, 2) ，(2, 1, 2) 和 (2, 2, 1) 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>n = 3, limit = 3
<b>输出：</b>10
<b>解释：</b>总共有 10 种方法分配 3 颗糖果，且每位小朋友的糖果数不超过 3 ：(0, 0, 3) ，(0, 1, 2) ，(0, 2, 1) ，(0, 3, 0) ，(1, 0, 2) ，(1, 1, 1) ，(1, 2, 0) ，(2, 0, 1) ，(2, 1, 0) 和 (3, 0, 0) 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 50</code></li>
	<li><code>1 &lt;= limit &lt;= 50</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：组合数学 + 容斥原理

根据题目描述，我们需要将 $n$ 个糖果分给 $3$ 个小孩，每个小孩分到的糖果数在 $[0, limit]$ 之间。

这实际上等价于把 $n$ 个球放入 $3$ 个盒子中。由于盒子可以为空，我们可以再增加 $3$ 个虚拟球，然后再利用隔板法，即一共有 $n + 3$ 个球，我们在其中 $n + 3 - 1$ 个位置插入 $2$ 个隔板，从而将实际的 $n$ 个球分成 $3$ 组，并且允许盒子为空，因此初始方案数为 $C_{n + 2}^2$。

我们需要在这些方案中，排除掉存在盒子分到的小球数超过 $limit$ 的方案。考虑其中有一个盒子分到的小球数超过 $limit$，那么剩下的球（包括虚拟球）最多有 $n + 3 - (limit + 1) = n - limit + 2$ 个，位置数为 $n - limit + 1$，因此方案数为 $C_{n - limit + 1}^2$。由于存在 $3$ 个盒子，因此这样的方案数为 $3 \times C_{n - limit + 1}^2$。这样子算，我们会多排除掉同时存在两个盒子分到的小球数超过 $limit$ 的方案，因此我们需要再加上这样的方案数，即 $3 \times C_{n - 2 \times limit}^2$。

时间复杂度 $O(1)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def distributeCandies(self, n: int, limit: int) -> int:
        if n > 3 * limit:
            return 0
        ans = comb(n + 2, 2)
        if n > limit:
            ans -= 3 * comb(n - limit + 1, 2)
        if n - 2 >= 2 * limit:
            ans += 3 * comb(n - 2 * limit, 2)
        return ans
```

#### Java

```java
class Solution {
    public int distributeCandies(int n, int limit) {
        if (n > 3 * limit) {
            return 0;
        }
        long ans = comb2(n + 2);
        if (n > limit) {
            ans -= 3 * comb2(n - limit + 1);
        }
        if (n - 2 >= 2 * limit) {
            ans += 3 * comb2(n - 2 * limit);
        }
        return (int) ans;
    }

    private long comb2(int n) {
        return 1L * n * (n - 1) / 2;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int distributeCandies(int n, int limit) {
        auto comb2 = [](int n) {
            return 1LL * n * (n - 1) / 2;
        };
        if (n > 3 * limit) {
            return 0;
        }
        long long ans = comb2(n + 2);
        if (n > limit) {
            ans -= 3 * comb2(n - limit + 1);
        }
        if (n - 2 >= 2 * limit) {
            ans += 3 * comb2(n - 2 * limit);
        }
        return ans;
    }
};
```

#### Go

```go
func distributeCandies(n int, limit int) int {
	comb2 := func(n int) int {
		return n * (n - 1) / 2
	}
	if n > 3*limit {
		return 0
	}
	ans := comb2(n + 2)
	if n > limit {
		ans -= 3 * comb2(n-limit+1)
	}
	if n-2 >= 2*limit {
		ans += 3 * comb2(n-2*limit)
	}
	return ans
}
```

#### TypeScript

```ts
function distributeCandies(n: number, limit: number): number {
    const comb2 = (n: number) => (n * (n - 1)) / 2;
    if (n > 3 * limit) {
        return 0;
    }
    let ans = comb2(n + 2);
    if (n > limit) {
        ans -= 3 * comb2(n - limit + 1);
    }
    if (n - 2 >= 2 * limit) {
        ans += 3 * comb2(n - 2 * limit);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2929. 给小朋友们分糖果 II](https://leetcode.cn/problems/distribute-candies-among-children-ii){#2929}

{{< tabs "2929" >}}

{{% tab "python" %}}
```python
class Solution:
    def distributeCandies(self, n: int, limit: int) -> int:
        if n > 3 * limit:
            return 0
        ans = comb(n + 2, 2)
        if n > limit:
            ans -= 3 * comb(n - limit + 1, 2)
        if n - 2 >= 2 * limit:
            ans += 3 * comb(n - 2 * limit, 2)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long distributeCandies(int n, int limit) {
        if (n > 3 * limit) {
            return 0;
        }
        long ans = comb2(n + 2);
        if (n > limit) {
            ans -= 3 * comb2(n - limit + 1);
        }
        if (n - 2 >= 2 * limit) {
            ans += 3 * comb2(n - 2 * limit);
        }
        return ans;
    }

    private long comb2(int n) {
        return 1L * n * (n - 1) / 2;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    long long distributeCandies(int n, int limit) {
        auto comb2 = [](int n) {
            return 1LL * n * (n - 1) / 2;
        };
        if (n > 3 * limit) {
            return 0;
        }
        long long ans = comb2(n + 2);
        if (n > limit) {
            ans -= 3 * comb2(n - limit + 1);
        }
        if (n - 2 >= 2 * limit) {
            ans += 3 * comb2(n - 2 * limit);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func distributeCandies(n int, limit int) int64 {
	comb2 := func(n int) int {
		return n * (n - 1) / 2
	}
	if n > 3*limit {
		return 0
	}
	ans := comb2(n + 2)
	if n > limit {
		ans -= 3 * comb2(n-limit+1)
	}
	if n-2 >= 2*limit {
		ans += 3 * comb2(n-2*limit)
	}
	return int64(ans)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function distributeCandies(n: number, limit: number): number {
    const comb2 = (n: number) => (n * (n - 1)) / 2;
    if (n > 3 * limit) {
        return 0;
    }
    let ans = comb2(n + 2);
    if (n > limit) {
        ans -= 3 * comb2(n - limit + 1);
    }
    if (n - 2 >= 2 * limit) {
        ans += 3 * comb2(n - 2 * limit);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn distribute_candies(n: i32, limit: i32) -> i64 {
        if n > 3 * limit {
            return 0;
        }
        let mut ans = Self::comb2(n + 2);
        if n > limit {
            ans -= 3 * Self::comb2(n - limit + 1);
        }
        if n - 2 >= 2 * limit {
            ans += 3 * Self::comb2(n - 2 * limit);
        }
        ans
    }

    fn comb2(n: i32) -> i64 {
        (n as i64) * (n as i64 - 1) / 2
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个正整数&nbsp;<code>n</code> 和&nbsp;<code>limit</code>&nbsp;。</p>

<p>请你将 <code>n</code>&nbsp;颗糖果分给 <code>3</code>&nbsp;位小朋友，确保没有任何小朋友得到超过 <code>limit</code>&nbsp;颗糖果，请你返回满足此条件下的&nbsp;<strong>总方案数</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>n = 5, limit = 2
<b>输出：</b>3
<b>解释：</b>总共有 3 种方法分配 5 颗糖果，且每位小朋友的糖果数不超过 2 ：(1, 2, 2) ，(2, 1, 2) 和 (2, 2, 1) 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>n = 3, limit = 3
<b>输出：</b>10
<b>解释：</b>总共有 10 种方法分配 3 颗糖果，且每位小朋友的糖果数不超过 3 ：(0, 0, 3) ，(0, 1, 2) ，(0, 2, 1) ，(0, 3, 0) ，(1, 0, 2) ，(1, 1, 1) ，(1, 2, 0) ，(2, 0, 1) ，(2, 1, 0) 和 (3, 0, 0) 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>6</sup></code></li>
	<li><code>1 &lt;= limit &lt;= 10<sup>6</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：组合数学 + 容斥原理

根据题目描述，我们需要将 $n$ 个糖果分给 $3$ 个小孩，每个小孩分到的糖果数在 $[0, limit]$ 之间。

这实际上等价于把 $n$ 个球放入 $3$ 个盒子中。由于盒子可以为空，我们可以再增加 $3$ 个虚拟球，然后再利用隔板法，即一共有 $n + 3$ 个球，我们在其中 $n + 3 - 1$ 个位置插入 $2$ 个隔板，从而将实际的 $n$ 个球分成 $3$ 组，并且允许盒子为空，因此初始方案数为 $C_{n + 2}^2$。

我们需要在这些方案中，排除掉存在盒子分到的小球数超过 $limit$ 的方案。考虑其中有一个盒子分到的小球数超过 $limit$，那么剩下的球（包括虚拟球）最多有 $n + 3 - (limit + 1) = n - limit + 2$ 个，位置数为 $n - limit + 1$，因此方案数为 $C_{n - limit + 1}^2$。由于存在 $3$ 个盒子，因此这样的方案数为 $3 \times C_{n - limit + 1}^2$。这样子算，我们会多排除掉同时存在两个盒子分到的小球数超过 $limit$ 的方案，因此我们需要再加上这样的方案数，即 $3 \times C_{n - 2 \times limit}^2$。

时间复杂度 $O(1)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def distributeCandies(self, n: int, limit: int) -> int:
        if n > 3 * limit:
            return 0
        ans = comb(n + 2, 2)
        if n > limit:
            ans -= 3 * comb(n - limit + 1, 2)
        if n - 2 >= 2 * limit:
            ans += 3 * comb(n - 2 * limit, 2)
        return ans
```

#### Java

```java
class Solution {
    public long distributeCandies(int n, int limit) {
        if (n > 3 * limit) {
            return 0;
        }
        long ans = comb2(n + 2);
        if (n > limit) {
            ans -= 3 * comb2(n - limit + 1);
        }
        if (n - 2 >= 2 * limit) {
            ans += 3 * comb2(n - 2 * limit);
        }
        return ans;
    }

    private long comb2(int n) {
        return 1L * n * (n - 1) / 2;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long distributeCandies(int n, int limit) {
        auto comb2 = [](int n) {
            return 1LL * n * (n - 1) / 2;
        };
        if (n > 3 * limit) {
            return 0;
        }
        long long ans = comb2(n + 2);
        if (n > limit) {
            ans -= 3 * comb2(n - limit + 1);
        }
        if (n - 2 >= 2 * limit) {
            ans += 3 * comb2(n - 2 * limit);
        }
        return ans;
    }
};
```

#### Go

```go
func distributeCandies(n int, limit int) int64 {
	comb2 := func(n int) int {
		return n * (n - 1) / 2
	}
	if n > 3*limit {
		return 0
	}
	ans := comb2(n + 2)
	if n > limit {
		ans -= 3 * comb2(n-limit+1)
	}
	if n-2 >= 2*limit {
		ans += 3 * comb2(n-2*limit)
	}
	return int64(ans)
}
```

#### TypeScript

```ts
function distributeCandies(n: number, limit: number): number {
    const comb2 = (n: number) => (n * (n - 1)) / 2;
    if (n > 3 * limit) {
        return 0;
    }
    let ans = comb2(n + 2);
    if (n > limit) {
        ans -= 3 * comb2(n - limit + 1);
    }
    if (n - 2 >= 2 * limit) {
        ans += 3 * comb2(n - 2 * limit);
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn distribute_candies(n: i32, limit: i32) -> i64 {
        if n > 3 * limit {
            return 0;
        }
        let mut ans = Self::comb2(n + 2);
        if n > limit {
            ans -= 3 * Self::comb2(n - limit + 1);
        }
        if n - 2 >= 2 * limit {
            ans += 3 * Self::comb2(n - 2 * limit);
        }
        ans
    }

    fn comb2(n: i32) -> i64 {
        (n as i64) * (n as i64 - 1) / 2
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
