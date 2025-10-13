---
title: "2580_统计将重叠区间合并成组的方案数"
date: 2025-10-08T18:39:23+08:00
weight: 9
tags: [二分查找, 二叉树, 位运算, 前缀和, 动态规划, 哈希表, 字符串, 广度优先搜索, 排序, 数学, 数组, 数论, 栈, 树, 模拟, 深度优先搜索, 计数, 贪心]
---

{{< markmap >}}
### [2580_统计将重叠区间合并成组的方案数](#2580)
#### [数组](#2580)
#### [排序](#2580)
### [2581_统计可能的树根数目](#2581)
#### [树](#2581)
#### [深度优先搜索](#2581)
#### [数组](#2581)
#### [哈希表](#2581)
#### [动态规划](#2581)
### [2582_递枕头](#2582)
#### [数学](#2582)
#### [模拟](#2582)
### [2583_二叉树中的第 K 大层和](#2583)
#### [树](#2583)
#### [广度优先搜索](#2583)
#### [二叉树](#2583)
#### [排序](#2583)
### [2584_分割数组使乘积互质](#2584)
#### [数组](#2584)
#### [哈希表](#2584)
#### [数学](#2584)
#### [数论](#2584)
### [2585_获得分数的方法数](#2585)
#### [数组](#2585)
#### [动态规划](#2585)
### [2586_统计范围内的元音字符串数](#2586)
#### [数组](#2586)
#### [字符串](#2586)
#### [计数](#2586)
### [2587_重排数组以得到最大前缀分数](#2587)
#### [贪心](#2587)
#### [数组](#2587)
#### [前缀和](#2587)
#### [排序](#2587)
### [2588_统计美丽子数组数目](#2588)
#### [位运算](#2588)
#### [数组](#2588)
#### [哈希表](#2588)
#### [前缀和](#2588)
### [2589_完成所有任务的最少时间](#2589)
#### [栈](#2589)
#### [贪心](#2589)
#### [数组](#2589)
#### [二分查找](#2589)
#### [排序](#2589)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2580_统计将重叠区间合并成组的方案数
___
#### 数组
___
#### 排序
---
### 2581_统计可能的树根数目
___
#### 树
___
#### 深度优先搜索
___
#### 数组
___
#### 哈希表
___
#### 动态规划
---
### 2582_递枕头
___
#### 数学
___
#### 模拟
---
### 2583_二叉树中的第 K 大层和
___
#### 树
___
#### 广度优先搜索
___
#### 二叉树
___
#### 排序
---
### 2584_分割数组使乘积互质
___
#### 数组
___
#### 哈希表
___
#### 数学
___
#### 数论
---
### 2585_获得分数的方法数
___
#### 数组
___
#### 动态规划
---
### 2586_统计范围内的元音字符串数
___
#### 数组
___
#### 字符串
___
#### 计数
---
### 2587_重排数组以得到最大前缀分数
___
#### 贪心
___
#### 数组
___
#### 前缀和
___
#### 排序
---
### 2588_统计美丽子数组数目
___
#### 位运算
___
#### 数组
___
#### 哈希表
___
#### 前缀和
---
### 2589_完成所有任务的最少时间
___
#### 栈
___
#### 贪心
___
#### 数组
___
#### 二分查找
___
#### 排序
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 二叉树 | 位运算 |
| 前缀和 | 动态规划 | 哈希表 |
| 字符串 | 广度优先搜索 | 排序 |
| 数学 | 数组 | 数论 |
| 栈 | 树 | 模拟 |
| 深度优先搜索 | 计数 | 贪心 |

# [2580. 统计将重叠区间合并成组的方案数](https://leetcode.cn/problems/count-ways-to-group-overlapping-ranges){#2580}

{{< tabs "2580" >}}

{{% tab "python" %}}
```python
class Solution:
    def countWays(self, ranges: List[List[int]]) -> int:
        ranges.sort()
        mx = -1
        mod = 10**9 + 7
        ans = 1
        for start, end in ranges:
            if start > mx:
                ans = ans * 2 % mod
            mx = max(mx, end)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countWays(int[][] ranges) {
        Arrays.sort(ranges, (a, b) -> a[0] - b[0]);
        int mx = -1;
        int ans = 1;
        final int mod = (int) 1e9 + 7;
        for (int[] e : ranges) {
            if (e[0] > mx) {
                ans = ans * 2 % mod;
            }
            mx = Math.max(mx, e[1]);
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
    int countWays(vector<vector<int>>& ranges) {
        sort(ranges.begin(), ranges.end());
        int ans = 1, mx = -1;
        const int mod = 1e9 + 7;
        for (auto& e : ranges) {
            if (e[0] > mx) {
                ans = ans * 2 % mod;
            }
            mx = max(mx, e[1]);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countWays(ranges [][]int) int {
	sort.Slice(ranges, func(i, j int) bool { return ranges[i][0] < ranges[j][0] })
	ans, mx := 1, -1
	const mod = 1e9 + 7
	for _, e := range ranges {
		if e[0] > mx {
			ans = ans * 2 % mod
		}
		if mx < e[1] {
			mx = e[1]
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countWays(ranges: number[][]): number {
    ranges.sort((a, b) => a[0] - b[0]);
    let mx = -1;
    let ans = 1;
    const mod = 10 ** 9 + 7;
    for (const [start, end] of ranges) {
        if (start > mx) {
            ans = (ans * 2) % mod;
        }
        mx = Math.max(mx, end);
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

<p>给你一个二维整数数组&nbsp;<code>ranges</code>&nbsp;，其中&nbsp;<code>ranges[i] = [start<sub>i</sub>, end<sub>i</sub>]</code>&nbsp;表示&nbsp;<code>start<sub>i</sub></code>&nbsp;到&nbsp;<code>end<sub>i</sub></code>&nbsp;之间（包括二者）的所有整数都包含在第&nbsp;<code>i</code>&nbsp;个区间中。</p>

<p>你需要将&nbsp;<code>ranges</code>&nbsp;分成 <strong>两个</strong>&nbsp;组（可以为空），满足：</p>

<ul>
	<li>每个区间只属于一个组。</li>
	<li>两个有 <strong>交集</strong>&nbsp;的区间必须在 <strong>同一个&nbsp;</strong>组内。</li>
</ul>

<p>如果两个区间有至少 <strong>一个</strong>&nbsp;公共整数，那么这两个区间是 <b>有交集</b>&nbsp;的。</p>

<ul>
	<li>比方说，区间&nbsp;<code>[1, 3]</code> 和&nbsp;<code>[2, 5]</code>&nbsp;有交集，因为&nbsp;<code>2</code>&nbsp;和&nbsp;<code>3</code>&nbsp;在两个区间中都被包含。</li>
</ul>

<p>请你返回将 <code>ranges</code>&nbsp;划分成两个组的 <strong>总方案数</strong>&nbsp;。由于答案可能很大，将它对&nbsp;<code>10<sup>9</sup> + 7</code>&nbsp;<strong>取余</strong>&nbsp;后返回。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>ranges = [[6,10],[5,15]]
<b>输出：</b>2
<b>解释：</b>
两个区间有交集，所以它们必须在同一个组内。
所以有两种方案：
- 将两个区间都放在第 1 个组中。
- 将两个区间都放在第 2 个组中。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>ranges = [[1,3],[10,20],[2,5],[4,8]]
<b>输出：</b>4
<b>解释：</b>
区间 [1,3] 和 [2,5] 有交集，所以它们必须在同一个组中。
同理，区间 [2,5] 和 [4,8] 也有交集，所以它们也必须在同一个组中。
所以总共有 4 种分组方案：
- 所有区间都在第 1 组。
- 所有区间都在第 2 组。
- 区间 [1,3] ，[2,5] 和 [4,8] 在第 1 个组中，[10,20] 在第 2 个组中。
- 区间 [1,3] ，[2,5] 和 [4,8] 在第 2 个组中，[10,20] 在第 1 个组中。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= ranges.length &lt;= 10<sup>5</sup></code></li>
	<li><code>ranges[i].length == 2</code></li>
	<li><code>0 &lt;= start<sub>i</sub> &lt;= end<sub>i</sub> &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 计数 + 快速幂

我们可以先对区间进行排序，相交的区间进行合并，统计有多少个不相交的区间，记为 $cnt$。

每个不相交的区间可以选择放在第一组或第二组，所以方案数为 $2^{cnt}$。注意到 $2^{cnt}$ 可能很大，所以需要对 $10^9 + 7$ 取模。这里可以使用快速幂求解。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 为区间个数。

我们也可以不使用快速幂，一旦发现有新的不相交的区间，就将方案数乘 $2$ 后对 $10^9 + 7$ 取模。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countWays(self, ranges: List[List[int]]) -> int:
        ranges.sort()
        cnt, mx = 0, -1
        for start, end in ranges:
            if start > mx:
                cnt += 1
            mx = max(mx, end)
        mod = 10**9 + 7
        return pow(2, cnt, mod)
```

#### Java

```java
class Solution {
    public int countWays(int[][] ranges) {
        Arrays.sort(ranges, (a, b) -> a[0] - b[0]);
        int cnt = 0, mx = -1;
        for (int[] e : ranges) {
            if (e[0] > mx) {
                ++cnt;
            }
            mx = Math.max(mx, e[1]);
        }
        return qpow(2, cnt, (int) 1e9 + 7);
    }

    private int qpow(long a, int n, int mod) {
        long ans = 1;
        for (; n > 0; n >>= 1) {
            if ((n & 1) == 1) {
                ans = ans * a % mod;
            }
            a = a * a % mod;
        }
        return (int) ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int countWays(vector<vector<int>>& ranges) {
        sort(ranges.begin(), ranges.end());
        int cnt = 0, mx = -1;
        for (auto& e : ranges) {
            cnt += e[0] > mx;
            mx = max(mx, e[1]);
        }
        using ll = long long;
        auto qpow = [&](ll a, int n, int mod) {
            ll ans = 1;
            for (; n; n >>= 1) {
                if (n & 1) {
                    ans = ans * a % mod;
                }
                a = a * a % mod;
            }
            return ans;
        };
        return qpow(2, cnt, 1e9 + 7);
    }
};
```

#### Go

```go
func countWays(ranges [][]int) int {
	sort.Slice(ranges, func(i, j int) bool { return ranges[i][0] < ranges[j][0] })
	cnt, mx := 0, -1
	for _, e := range ranges {
		if e[0] > mx {
			cnt++
		}
		if mx < e[1] {
			mx = e[1]
		}
	}
	qpow := func(a, n, mod int) int {
		ans := 1
		for ; n > 0; n >>= 1 {
			if n&1 == 1 {
				ans = ans * a % mod
			}
			a = a * a % mod
		}
		return ans
	}
	return qpow(2, cnt, 1e9+7)
}
```

#### TypeScript

```ts
function countWays(ranges: number[][]): number {
    ranges.sort((a, b) => a[0] - b[0]);
    let mx = -1;
    let ans = 1;
    const mod = 10 ** 9 + 7;
    for (const [start, end] of ranges) {
        if (start > mx) {
            ans = (ans * 2) % mod;
        }
        mx = Math.max(mx, end);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countWays(self, ranges: List[List[int]]) -> int:
        ranges.sort()
        mx = -1
        mod = 10**9 + 7
        ans = 1
        for start, end in ranges:
            if start > mx:
                ans = ans * 2 % mod
            mx = max(mx, end)
        return ans
```

#### Java

```java
class Solution {
    public int countWays(int[][] ranges) {
        Arrays.sort(ranges, (a, b) -> a[0] - b[0]);
        int mx = -1;
        int ans = 1;
        final int mod = (int) 1e9 + 7;
        for (int[] e : ranges) {
            if (e[0] > mx) {
                ans = ans * 2 % mod;
            }
            mx = Math.max(mx, e[1]);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int countWays(vector<vector<int>>& ranges) {
        sort(ranges.begin(), ranges.end());
        int ans = 1, mx = -1;
        const int mod = 1e9 + 7;
        for (auto& e : ranges) {
            if (e[0] > mx) {
                ans = ans * 2 % mod;
            }
            mx = max(mx, e[1]);
        }
        return ans;
    }
};
```

#### Go

```go
func countWays(ranges [][]int) int {
	sort.Slice(ranges, func(i, j int) bool { return ranges[i][0] < ranges[j][0] })
	ans, mx := 1, -1
	const mod = 1e9 + 7
	for _, e := range ranges {
		if e[0] > mx {
			ans = ans * 2 % mod
		}
		if mx < e[1] {
			mx = e[1]
		}
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2581. 统计可能的树根数目](https://leetcode.cn/problems/count-number-of-possible-root-nodes){#2581}

{{< tabs "2581" >}}

{{% tab "python" %}}
```python
class Solution:
    def rootCount(
        self, edges: List[List[int]], guesses: List[List[int]], k: int
    ) -> int:
        def dfs1(i, fa):
            nonlocal cnt
            for j in g[i]:
                if j != fa:
                    cnt += gs[(i, j)]
                    dfs1(j, i)

        def dfs2(i, fa):
            nonlocal ans, cnt
            ans += cnt >= k
            for j in g[i]:
                if j != fa:
                    cnt -= gs[(i, j)]
                    cnt += gs[(j, i)]
                    dfs2(j, i)
                    cnt -= gs[(j, i)]
                    cnt += gs[(i, j)]

        g = defaultdict(list)
        for a, b in edges:
            g[a].append(b)
            g[b].append(a)
        gs = Counter((u, v) for u, v in guesses)
        cnt = 0
        dfs1(0, -1)
        ans = 0
        dfs2(0, -1)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private List<Integer>[] g;
    private Map<Long, Integer> gs = new HashMap<>();
    private int ans;
    private int k;
    private int cnt;
    private int n;

    public int rootCount(int[][] edges, int[][] guesses, int k) {
        this.k = k;
        n = edges.length + 1;
        g = new List[n];
        Arrays.setAll(g, e -> new ArrayList<>());
        for (var e : edges) {
            int a = e[0], b = e[1];
            g[a].add(b);
            g[b].add(a);
        }
        for (var e : guesses) {
            int a = e[0], b = e[1];
            gs.merge(f(a, b), 1, Integer::sum);
        }
        dfs1(0, -1);
        dfs2(0, -1);
        return ans;
    }

    private void dfs1(int i, int fa) {
        for (int j : g[i]) {
            if (j != fa) {
                cnt += gs.getOrDefault(f(i, j), 0);
                dfs1(j, i);
            }
        }
    }

    private void dfs2(int i, int fa) {
        ans += cnt >= k ? 1 : 0;
        for (int j : g[i]) {
            if (j != fa) {
                int a = gs.getOrDefault(f(i, j), 0);
                int b = gs.getOrDefault(f(j, i), 0);
                cnt -= a;
                cnt += b;
                dfs2(j, i);
                cnt -= b;
                cnt += a;
            }
        }
    }

    private long f(int i, int j) {
        return 1L * i * n + j;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        int n = edges.size() + 1;
        vector<int> g[n];
        unordered_map<long long, int> gs;
        auto f = [&](int i, int j) {
            return 1LL * i * n + j;
        };
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        for (auto& e : guesses) {
            int a = e[0], b = e[1];
            gs[f(a, b)]++;
        }
        int ans = 0;
        int cnt = 0;

        function<void(int, int)> dfs1 = [&](int i, int fa) {
            for (int& j : g[i]) {
                if (j != fa) {
                    cnt += gs[f(i, j)];
                    dfs1(j, i);
                }
            }
        };

        function<void(int, int)> dfs2 = [&](int i, int fa) {
            ans += cnt >= k;
            for (int& j : g[i]) {
                if (j != fa) {
                    int a = gs[f(i, j)];
                    int b = gs[f(j, i)];
                    cnt -= a;
                    cnt += b;
                    dfs2(j, i);
                    cnt -= b;
                    cnt += a;
                }
            }
        };
        dfs1(0, -1);
        dfs2(0, -1);
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func rootCount(edges [][]int, guesses [][]int, k int) (ans int) {
	n := len(edges) + 1
	g := make([][]int, n)
	gs := map[int]int{}
	for _, e := range edges {
		a, b := e[0], e[1]
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}
	f := func(i, j int) int {
		return i*n + j
	}
	for _, e := range guesses {
		a, b := e[0], e[1]
		gs[f(a, b)]++
	}

	cnt := 0
	var dfs1 func(i, fa int)
	var dfs2 func(i, fa int)
	dfs1 = func(i, fa int) {
		for _, j := range g[i] {
			if j != fa {
				cnt += gs[f(i, j)]
				dfs1(j, i)
			}
		}
	}
	dfs2 = func(i, fa int) {
		if cnt >= k {
			ans++
		}
		for _, j := range g[i] {
			if j != fa {
				a, b := gs[f(i, j)], gs[f(j, i)]
				cnt -= a
				cnt += b
				dfs2(j, i)
				cnt -= b
				cnt += a
			}
		}
	}
	dfs1(0, -1)
	dfs2(0, -1)
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function rootCount(edges: number[][], guesses: number[][], k: number): number {
    const n = edges.length + 1;
    const g: number[][] = Array.from({ length: n }, () => []);
    const gs: Map<number, number> = new Map();
    const f = (i: number, j: number) => i * n + j;
    for (const [a, b] of edges) {
        g[a].push(b);
        g[b].push(a);
    }
    for (const [a, b] of guesses) {
        const x = f(a, b);
        gs.set(x, gs.has(x) ? gs.get(x)! + 1 : 1);
    }
    let ans = 0;
    let cnt = 0;
    const dfs1 = (i: number, fa: number): void => {
        for (const j of g[i]) {
            if (j !== fa) {
                cnt += gs.get(f(i, j)) || 0;
                dfs1(j, i);
            }
        }
    };
    const dfs2 = (i: number, fa: number): void => {
        ans += cnt >= k ? 1 : 0;
        for (const j of g[i]) {
            if (j !== fa) {
                const a = gs.get(f(i, j)) || 0;
                const b = gs.get(f(j, i)) || 0;
                cnt -= a;
                cnt += b;
                dfs2(j, i);
                cnt -= b;
                cnt += a;
            }
        }
    };
    dfs1(0, -1);
    dfs2(0, -1);
    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>Alice 有一棵 <code>n</code> 个节点的树，节点编号为 <code>0</code> 到 <code>n - 1</code> 。树用一个长度为 <code>n - 1</code> 的二维整数数组 <code>edges</code> 表示，其中 <code>edges[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> ，表示树中节点 <code>a<sub>i</sub></code> 和 <code>b<sub>i</sub></code> 之间有一条边。</p>

<p>Alice 想要 Bob 找到这棵树的根。她允许 Bob 对这棵树进行若干次 <strong>猜测</strong> 。每一次猜测，Bob 做如下事情：</p>

<ul>
	<li>选择两个 <strong>不相等</strong>&nbsp;的整数&nbsp;<code>u</code> 和&nbsp;<code>v</code>&nbsp;，且树中必须存在边&nbsp;<code>[u, v]</code>&nbsp;。</li>
	<li>Bob 猜测树中&nbsp;<code>u</code>&nbsp;是&nbsp;<code>v</code>&nbsp;的 <strong>父节点</strong>&nbsp;。</li>
</ul>

<p>Bob 的猜测用二维整数数组&nbsp;<code>guesses</code> 表示，其中&nbsp;<code>guesses[j] = [u<sub>j</sub>, v<sub>j</sub>]</code>&nbsp;表示 Bob 猜&nbsp;<code>u<sub>j</sub></code> 是&nbsp;<code>v<sub>j</sub></code>&nbsp;的父节点。</p>

<p>Alice 非常懒，她不想逐个回答&nbsp;Bob 的猜测，只告诉 Bob 这些猜测里面 <strong>至少</strong>&nbsp;有&nbsp;<code>k</code>&nbsp;个猜测的结果为&nbsp;<code>true</code>&nbsp;。</p>

<p>给你二维整数数组 <code>edges</code>&nbsp;，Bob 的所有猜测和整数&nbsp;<code>k</code>&nbsp;，请你返回可能成为树根的&nbsp;<strong>节点数目</strong>&nbsp;。如果没有这样的树，则返回 <code>0</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2500-2599/2581.Count%20Number%20of%20Possible%20Root%20Nodes/images/ex-1.png" style="width: 727px; height: 250px;" /></p>

<pre>
<b>输入：</b>edges = [[0,1],[1,2],[1,3],[4,2]], guesses = [[1,3],[0,1],[1,0],[2,4]], k = 3
<b>输出：</b>3
<b>解释：</b>
根为节点 0 ，正确的猜测为 [1,3], [0,1], [2,4]
根为节点 1 ，正确的猜测为 [1,3], [1,0], [2,4]
根为节点 2 ，正确的猜测为 [1,3], [1,0], [2,4]
根为节点 3 ，正确的猜测为 [1,0], [2,4]
根为节点 4 ，正确的猜测为 [1,3], [1,0]
节点 0 ，1 或 2 为根时，可以得到 3 个正确的猜测。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2500-2599/2581.Count%20Number%20of%20Possible%20Root%20Nodes/images/ex-2.png" style="width: 600px; height: 303px;" /></p>

<pre>
<b>输入：</b>edges = [[0,1],[1,2],[2,3],[3,4]], guesses = [[1,0],[3,4],[2,1],[3,2]], k = 1
<b>输出：</b>5
<b>解释：</b>
根为节点 0 ，正确的猜测为 [3,4]
根为节点 1 ，正确的猜测为 [1,0], [3,4]
根为节点 2 ，正确的猜测为 [1,0], [2,1], [3,4]
根为节点 3 ，正确的猜测为 [1,0], [2,1], [3,2], [3,4]
根为节点 4 ，正确的猜测为 [1,0], [2,1], [3,2]
任何节点为根，都至少有 1 个正确的猜测。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>edges.length == n - 1</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= guesses.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub>, u<sub>j</sub>, v<sub>j</sub> &lt;= n - 1</code></li>
	<li><code>a<sub>i</sub> != b<sub>i</sub></code></li>
	<li><code>u<sub>j</sub> != v<sub>j</sub></code></li>
	<li><code>edges</code>&nbsp;表示一棵有效的树。</li>
	<li><code>guesses[j]</code>&nbsp;是树中的一条边。</li>
	<li><code>guesses</code>&nbsp;是唯一的。</li>
	<li><code>0 &lt;= k &lt;= guesses.length</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：树形 DP（换根）

我们先遍历题目给定的边集合 $edges$，将其转换为邻接表 $g$，其中 $g[i]$ 表示节点 $i$ 的所有邻接节点。用哈希表 $gs$ 记录题目给定的猜测集合 $guesses$。

接下来，我们先从节点 $0$ 开始，进行一次 DFS，统计从节点 $0$ 出发，能够到达的所有节点中，有多少条边在 $guesses$ 中。我们用变量 $cnt$ 记录这个数量。

然后，我们再从节点 $0$ 开始，进行一次 DFS，统计以每个点为根的树中，有多少条边在 $guesses$ 中。如果这个数量大于等于 $k$，则说明该节点是一个可能的根节点，我们将答案加 $1$。

因此，问题就转化为了求以每个点为根的树中，有多少条边在 $guesses$ 中。我们已经知道了从节点 $0$ 出发，能够到达的所有节点中，有多少条边在 $guesses$ 中，即 $cnt$。我们可以通过在 DFS 中，将 $cnt$ 的值加上或减去当前边是否在 $guesses$ 中，来维护这个值。

假设我们当前遍历到节点 $i$，此时 $cnt$ 表示以 $i$ 为根节点，有多少条边在 $guesses$ 中。那么对于 $i$ 的每个邻接节点 $j$，我们要计算以 $j$ 为根节点，有多少条边在 $guesses$ 中。如果 $(i, j)$ 在 $guesses$ 中，那么以 $j$ 为根节点的，就不存在 $(i, j)$ 这条边，因此 $cnt$ 的值要减去 $1$。如果 $(j, i)$ 在 $guesses$ 中，那么以 $j$ 为根节点的，要多出一条 $(i, j)$ 这条边，因此 $cnt$ 的值要加上 $1$。即 $f[j] = f[i] + (j, i) \in guesses - (i, j) \in guesses$。其中 $f[i]$ 表示以 $i$ 为根节点，有多少条边在 $guesses$ 中。

时间复杂度 $O(n + m)$，空间复杂度 $O(n + m)$。其中 $n$ 和 $m$ 分别为 $edges$ 和 $guesses$ 的长度。

相似题目：

-   [834. 树中距离之和](https://github.com/doocs/leetcode/blob/main/solution/0800-0899/0834.Sum%20of%20Distances%20in%20Tree/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def rootCount(
        self, edges: List[List[int]], guesses: List[List[int]], k: int
    ) -> int:
        def dfs1(i, fa):
            nonlocal cnt
            for j in g[i]:
                if j != fa:
                    cnt += gs[(i, j)]
                    dfs1(j, i)

        def dfs2(i, fa):
            nonlocal ans, cnt
            ans += cnt >= k
            for j in g[i]:
                if j != fa:
                    cnt -= gs[(i, j)]
                    cnt += gs[(j, i)]
                    dfs2(j, i)
                    cnt -= gs[(j, i)]
                    cnt += gs[(i, j)]

        g = defaultdict(list)
        for a, b in edges:
            g[a].append(b)
            g[b].append(a)
        gs = Counter((u, v) for u, v in guesses)
        cnt = 0
        dfs1(0, -1)
        ans = 0
        dfs2(0, -1)
        return ans
```

#### Java

```java
class Solution {
    private List<Integer>[] g;
    private Map<Long, Integer> gs = new HashMap<>();
    private int ans;
    private int k;
    private int cnt;
    private int n;

    public int rootCount(int[][] edges, int[][] guesses, int k) {
        this.k = k;
        n = edges.length + 1;
        g = new List[n];
        Arrays.setAll(g, e -> new ArrayList<>());
        for (var e : edges) {
            int a = e[0], b = e[1];
            g[a].add(b);
            g[b].add(a);
        }
        for (var e : guesses) {
            int a = e[0], b = e[1];
            gs.merge(f(a, b), 1, Integer::sum);
        }
        dfs1(0, -1);
        dfs2(0, -1);
        return ans;
    }

    private void dfs1(int i, int fa) {
        for (int j : g[i]) {
            if (j != fa) {
                cnt += gs.getOrDefault(f(i, j), 0);
                dfs1(j, i);
            }
        }
    }

    private void dfs2(int i, int fa) {
        ans += cnt >= k ? 1 : 0;
        for (int j : g[i]) {
            if (j != fa) {
                int a = gs.getOrDefault(f(i, j), 0);
                int b = gs.getOrDefault(f(j, i), 0);
                cnt -= a;
                cnt += b;
                dfs2(j, i);
                cnt -= b;
                cnt += a;
            }
        }
    }

    private long f(int i, int j) {
        return 1L * i * n + j;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        int n = edges.size() + 1;
        vector<int> g[n];
        unordered_map<long long, int> gs;
        auto f = [&](int i, int j) {
            return 1LL * i * n + j;
        };
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        for (auto& e : guesses) {
            int a = e[0], b = e[1];
            gs[f(a, b)]++;
        }
        int ans = 0;
        int cnt = 0;

        function<void(int, int)> dfs1 = [&](int i, int fa) {
            for (int& j : g[i]) {
                if (j != fa) {
                    cnt += gs[f(i, j)];
                    dfs1(j, i);
                }
            }
        };

        function<void(int, int)> dfs2 = [&](int i, int fa) {
            ans += cnt >= k;
            for (int& j : g[i]) {
                if (j != fa) {
                    int a = gs[f(i, j)];
                    int b = gs[f(j, i)];
                    cnt -= a;
                    cnt += b;
                    dfs2(j, i);
                    cnt -= b;
                    cnt += a;
                }
            }
        };
        dfs1(0, -1);
        dfs2(0, -1);
        return ans;
    }
};
```

#### Go

```go
func rootCount(edges [][]int, guesses [][]int, k int) (ans int) {
	n := len(edges) + 1
	g := make([][]int, n)
	gs := map[int]int{}
	for _, e := range edges {
		a, b := e[0], e[1]
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}
	f := func(i, j int) int {
		return i*n + j
	}
	for _, e := range guesses {
		a, b := e[0], e[1]
		gs[f(a, b)]++
	}

	cnt := 0
	var dfs1 func(i, fa int)
	var dfs2 func(i, fa int)
	dfs1 = func(i, fa int) {
		for _, j := range g[i] {
			if j != fa {
				cnt += gs[f(i, j)]
				dfs1(j, i)
			}
		}
	}
	dfs2 = func(i, fa int) {
		if cnt >= k {
			ans++
		}
		for _, j := range g[i] {
			if j != fa {
				a, b := gs[f(i, j)], gs[f(j, i)]
				cnt -= a
				cnt += b
				dfs2(j, i)
				cnt -= b
				cnt += a
			}
		}
	}
	dfs1(0, -1)
	dfs2(0, -1)
	return
}
```

#### TypeScript

```ts
function rootCount(edges: number[][], guesses: number[][], k: number): number {
    const n = edges.length + 1;
    const g: number[][] = Array.from({ length: n }, () => []);
    const gs: Map<number, number> = new Map();
    const f = (i: number, j: number) => i * n + j;
    for (const [a, b] of edges) {
        g[a].push(b);
        g[b].push(a);
    }
    for (const [a, b] of guesses) {
        const x = f(a, b);
        gs.set(x, gs.has(x) ? gs.get(x)! + 1 : 1);
    }
    let ans = 0;
    let cnt = 0;
    const dfs1 = (i: number, fa: number): void => {
        for (const j of g[i]) {
            if (j !== fa) {
                cnt += gs.get(f(i, j)) || 0;
                dfs1(j, i);
            }
        }
    };
    const dfs2 = (i: number, fa: number): void => {
        ans += cnt >= k ? 1 : 0;
        for (const j of g[i]) {
            if (j !== fa) {
                const a = gs.get(f(i, j)) || 0;
                const b = gs.get(f(j, i)) || 0;
                cnt -= a;
                cnt += b;
                dfs2(j, i);
                cnt -= b;
                cnt += a;
            }
        }
    };
    dfs1(0, -1);
    dfs2(0, -1);
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2582. 递枕头](https://leetcode.cn/problems/pass-the-pillow){#2582}

{{< tabs "2582" >}}

{{% tab "python" %}}
```python
class Solution:
    def passThePillow(self, n: int, time: int) -> int:
        k, mod = divmod(time, n - 1)
        return n - mod if k & 1 else mod + 1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int passThePillow(int n, int time) {
        int k = time / (n - 1);
        int mod = time % (n - 1);
        return (k & 1) == 1 ? n - mod : mod + 1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int passThePillow(int n, int time) {
        int k = time / (n - 1);
        int mod = time % (n - 1);
        return k & 1 ? n - mod : mod + 1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func passThePillow(n int, time int) int {
	k, mod := time/(n-1), time%(n-1)
	if k&1 == 1 {
		return n - mod
	}
	return mod + 1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function passThePillow(n: number, time: number): number {
    const k = time / (n - 1);
    const mod = time % (n - 1);
    return (k & 1) == 1 ? n - mod : mod + 1;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn pass_the_pillow(n: i32, time: i32) -> i32 {
        let mut k = time / (n - 1);
        let mut _mod = time % (n - 1);

        if (k & 1) == 1 {
            return n - _mod;
        }

        _mod + 1
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p><code>n</code> 个人站成一排，按从 <code>1</code> 到 <code>n</code> 编号。最初，排在队首的第一个人拿着一个枕头。每秒钟，拿着枕头的人会将枕头传递给队伍中的下一个人。一旦枕头到达队首或队尾，传递方向就会改变，队伍会继续沿相反方向传递枕头。</p>

<ul>
	<li>例如，当枕头到达第 <code>n</code> 个人时，TA 会将枕头传递给第 <code>n - 1</code> 个人，然后传递给第 <code>n - 2</code> 个人，依此类推。</li>
</ul>

<p>给你两个正整数 <code>n</code> 和 <code>time</code> ，返回 <code>time</code> 秒后拿着枕头的人的编号。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 4, time = 5
<strong>输出：</strong>2
<strong>解释：</strong>队伍中枕头的传递情况为：1 -&gt; 2 -&gt; 3 -&gt; 4 -&gt; 3 -&gt; 2 。
5 秒后，枕头传递到第 2 个人手中。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 3, time = 2
<strong>输出：</strong>3
<strong>解释：</strong>队伍中枕头的传递情况为：1 -&gt; 2 -&gt; 3 。
2 秒后，枕头传递到第 3 个人手中。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 1000</code></li>
	<li><code>1 &lt;= time &lt;= 1000</code></li>
</ul>

<p>&nbsp;</p>

<p><b>注意：</b>本题与 <a href="https://leetcode.cn/problems/find-the-child-who-has-the-ball-after-k-seconds/">3178.找出 K 秒后拿着球的孩子</a>&nbsp;一致。</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们可以模拟枕头传递的过程，每次传递枕头时，如果枕头到达队首或队尾，传递方向就会改变，队伍会继续沿相反方向传递枕头。

时间复杂度 $O(time)$，空间复杂度 $O(1)$。其中 $time$ 为给定的时间。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def passThePillow(self, n: int, time: int) -> int:
        ans = k = 1
        for _ in range(time):
            ans += k
            if ans == 1 or ans == n:
                k *= -1
        return ans
```

#### Java

```java
class Solution {
    public int passThePillow(int n, int time) {
        int ans = 1, k = 1;
        while (time-- > 0) {
            ans += k;
            if (ans == 1 || ans == n) {
                k *= -1;
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
    int passThePillow(int n, int time) {
        int ans = 1, k = 1;
        while (time--) {
            ans += k;
            if (ans == 1 || ans == n) {
                k *= -1;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func passThePillow(n int, time int) int {
	ans, k := 1, 1
	for ; time > 0; time-- {
		ans += k
		if ans == 1 || ans == n {
			k *= -1
		}
	}
	return ans
}
```

#### TypeScript

```ts
function passThePillow(n: number, time: number): number {
    let ans = 1,
        k = 1;
    while (time-- > 0) {
        ans += k;
        if (ans === 1 || ans === n) {
            k *= -1;
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn pass_the_pillow(n: i32, time: i32) -> i32 {
        let mut ans = 1;
        let mut k = 1;

        for i in 1..=time {
            ans += k;

            if ans == 1 || ans == n {
                k *= -1;
            }
        }

        ans
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：数学

我们注意到，每一轮有 $n - 1$ 次传递，因此我们可以将 $time$ 除以 $n - 1$ 得到枕头传递的轮数 $k$，然后再将 $time$ 对 $n - 1$ 取余得到枕头在当前轮的剩余传递次数 $mod$。

接下来我们判断当前的轮数 $k$：

-   如果 $k$ 为奇数，那么枕头当前的传递方向是从队尾到队首，因此枕头会传递到编号为 $n - mod$ 的人手中；
-   如果 $k$ 为偶数，那么枕头当前的传递方向是从队首到队尾，因此枕头会传递到编号为 $mod + 1$ 的人手中。

时间复杂度 $O(1)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def passThePillow(self, n: int, time: int) -> int:
        k, mod = divmod(time, n - 1)
        return n - mod if k & 1 else mod + 1
```

#### Java

```java
class Solution {
    public int passThePillow(int n, int time) {
        int k = time / (n - 1);
        int mod = time % (n - 1);
        return (k & 1) == 1 ? n - mod : mod + 1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int passThePillow(int n, int time) {
        int k = time / (n - 1);
        int mod = time % (n - 1);
        return k & 1 ? n - mod : mod + 1;
    }
};
```

#### Go

```go
func passThePillow(n int, time int) int {
	k, mod := time/(n-1), time%(n-1)
	if k&1 == 1 {
		return n - mod
	}
	return mod + 1
}
```

#### TypeScript

```ts
function passThePillow(n: number, time: number): number {
    const k = time / (n - 1);
    const mod = time % (n - 1);
    return (k & 1) == 1 ? n - mod : mod + 1;
}
```

#### Rust

```rust
impl Solution {
    pub fn pass_the_pillow(n: i32, time: i32) -> i32 {
        let mut k = time / (n - 1);
        let mut _mod = time % (n - 1);

        if (k & 1) == 1 {
            return n - _mod;
        }

        _mod + 1
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2583. 二叉树中的第 K 大层和](https://leetcode.cn/problems/kth-largest-sum-in-a-binary-tree){#2583}

{{< tabs "2583" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthLargestLevelSum(self, root: Optional[TreeNode], k: int) -> int:
        def dfs(root, d):
            if root is None:
                return
            if len(arr) <= d:
                arr.append(0)
            arr[d] += root.val
            dfs(root.left, d + 1)
            dfs(root.right, d + 1)

        arr = []
        dfs(root, 0)
        return -1 if len(arr) < k else nlargest(k, arr)[-1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private List<Long> arr = new ArrayList<>();

    public long kthLargestLevelSum(TreeNode root, int k) {
        dfs(root, 0);
        if (arr.size() < k) {
            return -1;
        }
        Collections.sort(arr, Collections.reverseOrder());
        return arr.get(k - 1);
    }

    private void dfs(TreeNode root, int d) {
        if (root == null) {
            return;
        }
        if (arr.size() <= d) {
            arr.add(0L);
        }
        arr.set(d, arr.get(d) + root.val);
        dfs(root.left, d + 1);
        dfs(root.right, d + 1);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> arr;
        function<void(TreeNode*, int)> dfs = [&](TreeNode* root, int d) {
            if (!root) {
                return;
            }
            if (arr.size() <= d) {
                arr.push_back(0);
            }
            arr[d] += root->val;
            dfs(root->left, d + 1);
            dfs(root->right, d + 1);
        };
        dfs(root, 0);
        if (arr.size() < k) {
            return -1;
        }
        sort(arr.rbegin(), arr.rend());
        return arr[k - 1];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func kthLargestLevelSum(root *TreeNode, k int) int64 {
	arr := []int{}
	var dfs func(*TreeNode, int)
	dfs = func(root *TreeNode, d int) {
		if root == nil {
			return
		}
		if len(arr) <= d {
			arr = append(arr, 0)
		}
		arr[d] += root.Val
		dfs(root.Left, d+1)
		dfs(root.Right, d+1)
	}

	dfs(root, 0)
	if n := len(arr); n >= k {
		sort.Ints(arr)
		return int64(arr[n-k])
	}
	return -1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function kthLargestLevelSum(root: TreeNode | null, k: number): number {
    const dfs = (root: TreeNode, d: number) => {
        if (!root) {
            return;
        }
        if (arr.length <= d) {
            arr.push(0);
        }
        arr[d] += root.val;
        dfs(root.left, d + 1);
        dfs(root.right, d + 1);
    };
    const arr: number[] = [];
    dfs(root, 0);
    if (arr.length < k) {
        return -1;
    }
    arr.sort((a, b) => b - a);
    return arr[k - 1];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一棵二叉树的根节点 <code>root</code> 和一个正整数 <code>k</code> 。</p>

<p>树中的 <strong>层和</strong> 是指 <strong>同一层</strong> 上节点值的总和。</p>

<p>返回树中第 <code>k</code> 大的层和（不一定不同）。如果树少于 <code>k</code> 层，则返回 <code>-1</code> 。</p>

<p><strong>注意</strong>，如果两个节点与根节点的距离相同，则认为它们在同一层。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2500-2599/2583.Kth%20Largest%20Sum%20in%20a%20Binary%20Tree/images/binaryytreeedrawio-2.png" style="width: 301px; height: 284px;" /></p>

<pre>
<strong>输入：</strong>root = [5,8,9,2,1,3,7,4,6], k = 2
<strong>输出：</strong>13
<strong>解释：</strong>树中每一层的层和分别是：
- Level 1: 5
- Level 2: 8 + 9 = 17
- Level 3: 2 + 1 + 3 + 7 = 13
- Level 4: 4 + 6 = 10
第 2 大的层和等于 13 。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2500-2599/2583.Kth%20Largest%20Sum%20in%20a%20Binary%20Tree/images/treedrawio-3.png" style="width: 181px; height: 181px;" /></p>

<pre>
<strong>输入：</strong>root = [1,2,null,3], k = 1
<strong>输出：</strong>3
<strong>解释：</strong>最大的层和是 3 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中的节点数为 <code>n</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= Node.val &lt;= 10<sup>6</sup></code></li>
	<li><code>1 &lt;= k &lt;= n</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：BFS + 排序

我们可以使用 BFS 遍历二叉树，同时记录每一层的节点和，然后对节点和数组进行排序，最后返回第 $k$ 大的节点和即可。注意，如果二叉树的层数小于 $k$，则返回 $-1$。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为二叉树的节点数。

<!-- tabs:start -->

#### Python3

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthLargestLevelSum(self, root: Optional[TreeNode], k: int) -> int:
        arr = []
        q = deque([root])
        while q:
            t = 0
            for _ in range(len(q)):
                root = q.popleft()
                t += root.val
                if root.left:
                    q.append(root.left)
                if root.right:
                    q.append(root.right)
            arr.append(t)
        return -1 if len(arr) < k else nlargest(k, arr)[-1]
```

#### Java

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public long kthLargestLevelSum(TreeNode root, int k) {
        List<Long> arr = new ArrayList<>();
        Deque<TreeNode> q = new ArrayDeque<>();
        q.offer(root);
        while (!q.isEmpty()) {
            long t = 0;
            for (int n = q.size(); n > 0; --n) {
                root = q.pollFirst();
                t += root.val;
                if (root.left != null) {
                    q.offer(root.left);
                }
                if (root.right != null) {
                    q.offer(root.right);
                }
            }
            arr.add(t);
        }
        if (arr.size() < k) {
            return -1;
        }
        Collections.sort(arr, Collections.reverseOrder());
        return arr.get(k - 1);
    }
}
```

#### C++

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> arr;
        queue<TreeNode*> q{{root}};
        while (!q.empty()) {
            long long t = 0;
            for (int n = q.size(); n; --n) {
                root = q.front();
                q.pop();
                t += root->val;
                if (root->left) {
                    q.push(root->left);
                }
                if (root->right) {
                    q.push(root->right);
                }
            }
            arr.push_back(t);
        }
        if (arr.size() < k) {
            return -1;
        }
        sort(arr.rbegin(), arr.rend());
        return arr[k - 1];
    }
};
```

#### Go

```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func kthLargestLevelSum(root *TreeNode, k int) int64 {
	arr := []int{}
	q := []*TreeNode{root}
	for len(q) > 0 {
		t := 0
		for n := len(q); n > 0; n-- {
			root = q[0]
			q = q[1:]
			t += root.Val
			if root.Left != nil {
				q = append(q, root.Left)
			}
			if root.Right != nil {
				q = append(q, root.Right)
			}
		}
		arr = append(arr, t)
	}
	if n := len(arr); n >= k {
		sort.Ints(arr)
		return int64(arr[n-k])
	}
	return -1
}
```

#### TypeScript

```ts
/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function kthLargestLevelSum(root: TreeNode | null, k: number): number {
    const arr: number[] = [];
    const q = [root];
    while (q.length) {
        let t = 0;
        for (let n = q.length; n > 0; --n) {
            root = q.shift();
            t += root.val;
            if (root.left) {
                q.push(root.left);
            }
            if (root.right) {
                q.push(root.right);
            }
        }
        arr.push(t);
    }
    if (arr.length < k) {
        return -1;
    }
    arr.sort((a, b) => b - a);
    return arr[k - 1];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：DFS + 排序

我们也可以使用 DFS 遍历二叉树，同时记录每一层的节点和，然后对节点和数组进行排序，最后返回第 $k$ 大的节点和即可。注意，如果二叉树的层数小于 $k$，则返回 $-1$。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为二叉树的节点数。

<!-- tabs:start -->

#### Python3

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthLargestLevelSum(self, root: Optional[TreeNode], k: int) -> int:
        def dfs(root, d):
            if root is None:
                return
            if len(arr) <= d:
                arr.append(0)
            arr[d] += root.val
            dfs(root.left, d + 1)
            dfs(root.right, d + 1)

        arr = []
        dfs(root, 0)
        return -1 if len(arr) < k else nlargest(k, arr)[-1]
```

#### Java

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private List<Long> arr = new ArrayList<>();

    public long kthLargestLevelSum(TreeNode root, int k) {
        dfs(root, 0);
        if (arr.size() < k) {
            return -1;
        }
        Collections.sort(arr, Collections.reverseOrder());
        return arr.get(k - 1);
    }

    private void dfs(TreeNode root, int d) {
        if (root == null) {
            return;
        }
        if (arr.size() <= d) {
            arr.add(0L);
        }
        arr.set(d, arr.get(d) + root.val);
        dfs(root.left, d + 1);
        dfs(root.right, d + 1);
    }
}
```

#### C++

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> arr;
        function<void(TreeNode*, int)> dfs = [&](TreeNode* root, int d) {
            if (!root) {
                return;
            }
            if (arr.size() <= d) {
                arr.push_back(0);
            }
            arr[d] += root->val;
            dfs(root->left, d + 1);
            dfs(root->right, d + 1);
        };
        dfs(root, 0);
        if (arr.size() < k) {
            return -1;
        }
        sort(arr.rbegin(), arr.rend());
        return arr[k - 1];
    }
};
```

#### Go

```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func kthLargestLevelSum(root *TreeNode, k int) int64 {
	arr := []int{}
	var dfs func(*TreeNode, int)
	dfs = func(root *TreeNode, d int) {
		if root == nil {
			return
		}
		if len(arr) <= d {
			arr = append(arr, 0)
		}
		arr[d] += root.Val
		dfs(root.Left, d+1)
		dfs(root.Right, d+1)
	}

	dfs(root, 0)
	if n := len(arr); n >= k {
		sort.Ints(arr)
		return int64(arr[n-k])
	}
	return -1
}
```

#### TypeScript

```ts
/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function kthLargestLevelSum(root: TreeNode | null, k: number): number {
    const dfs = (root: TreeNode, d: number) => {
        if (!root) {
            return;
        }
        if (arr.length <= d) {
            arr.push(0);
        }
        arr[d] += root.val;
        dfs(root.left, d + 1);
        dfs(root.right, d + 1);
    };
    const arr: number[] = [];
    dfs(root, 0);
    if (arr.length < k) {
        return -1;
    }
    arr.sort((a, b) => b - a);
    return arr[k - 1];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2584. 分割数组使乘积互质](https://leetcode.cn/problems/split-the-array-to-make-coprime-products){#2584}

{{< tabs "2584" >}}

{{% tab "python" %}}
```python
class Solution:
    def findValidSplit(self, nums: List[int]) -> int:
        first = {}
        n = len(nums)
        last = list(range(n))
        for i, x in enumerate(nums):
            j = 2
            while j <= x // j:
                if x % j == 0:
                    if j in first:
                        last[first[j]] = i
                    else:
                        first[j] = i
                    while x % j == 0:
                        x //= j
                j += 1
            if x > 1:
                if x in first:
                    last[first[x]] = i
                else:
                    first[x] = i
        mx = last[0]
        for i, x in enumerate(last):
            if mx < i:
                return mx
            mx = max(mx, x)
        return -1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int findValidSplit(int[] nums) {
        Map<Integer, Integer> first = new HashMap<>();
        int n = nums.length;
        int[] last = new int[n];
        for (int i = 0; i < n; ++i) {
            last[i] = i;
        }
        for (int i = 0; i < n; ++i) {
            int x = nums[i];
            for (int j = 2; j <= x / j; ++j) {
                if (x % j == 0) {
                    if (first.containsKey(j)) {
                        last[first.get(j)] = i;
                    } else {
                        first.put(j, i);
                    }
                    while (x % j == 0) {
                        x /= j;
                    }
                }
            }
            if (x > 1) {
                if (first.containsKey(x)) {
                    last[first.get(x)] = i;
                } else {
                    first.put(x, i);
                }
            }
        }
        int mx = last[0];
        for (int i = 0; i < n; ++i) {
            if (mx < i) {
                return mx;
            }
            mx = Math.max(mx, last[i]);
        }
        return -1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int findValidSplit(vector<int>& nums) {
        unordered_map<int, int> first;
        int n = nums.size();
        vector<int> last(n);
        iota(last.begin(), last.end(), 0);
        for (int i = 0; i < n; ++i) {
            int x = nums[i];
            for (int j = 2; j <= x / j; ++j) {
                if (x % j == 0) {
                    if (first.count(j)) {
                        last[first[j]] = i;
                    } else {
                        first[j] = i;
                    }
                    while (x % j == 0) {
                        x /= j;
                    }
                }
            }
            if (x > 1) {
                if (first.count(x)) {
                    last[first[x]] = i;
                } else {
                    first[x] = i;
                }
            }
        }
        int mx = last[0];
        for (int i = 0; i < n; ++i) {
            if (mx < i) {
                return mx;
            }
            mx = max(mx, last[i]);
        }
        return -1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findValidSplit(nums []int) int {
	first := map[int]int{}
	n := len(nums)
	last := make([]int, n)
	for i := range last {
		last[i] = i
	}
	for i, x := range nums {
		for j := 2; j <= x/j; j++ {
			if x%j == 0 {
				if k, ok := first[j]; ok {
					last[k] = i
				} else {
					first[j] = i
				}
				for x%j == 0 {
					x /= j
				}
			}
		}
		if x > 1 {
			if k, ok := first[x]; ok {
				last[k] = i
			} else {
				first[x] = i
			}
		}
	}
	mx := last[0]
	for i, x := range last {
		if mx < i {
			return mx
		}
		mx = max(mx, x)
	}
	return -1
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个长度为 <code>n</code> 的整数数组 <code>nums</code> ，下标从 <strong>0</strong> 开始。</p>

<p>如果在下标 <code>i</code> 处 <strong>分割</strong> 数组，其中 <code>0 &lt;= i &lt;= n - 2</code> ，使前 <code>i + 1</code> 个元素的乘积和剩余元素的乘积互质，则认为该分割 <strong>有效</strong> 。</p>

<ul>
	<li>例如，如果 <code>nums = [2, 3, 3]</code> ，那么在下标 <code>i = 0</code> 处的分割有效，因为 <code>2</code> 和 <code>9</code> 互质，而在下标 <code>i = 1</code> 处的分割无效，因为 <code>6</code> 和 <code>3</code> 不互质。在下标 <code>i = 2</code> 处的分割也无效，因为 <code>i == n - 1</code> 。</li>
</ul>

<p>返回可以有效分割数组的最小下标 <code>i</code> ，如果不存在有效分割，则返回 <code>-1</code> 。</p>

<p>当且仅当 <code>gcd(val1, val2) == 1</code> 成立时，<code>val1</code> 和 <code>val2</code> 这两个值才是互质的，其中 <code>gcd(val1, val2)</code> 表示 <code>val1</code> 和 <code>val2</code> 的最大公约数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2500-2599/2584.Split%20the%20Array%20to%20Make%20Coprime%20Products/images/second.png" style="width: 450px; height: 211px;" /></p>

<pre>
<strong>输入：</strong>nums = [4,7,8,15,3,5]
<strong>输出：</strong>2
<strong>解释：</strong>上表展示了每个下标 i 处的前 i + 1 个元素的乘积、剩余元素的乘积和它们的最大公约数的值。
唯一一个有效分割位于下标 2 。</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2500-2599/2584.Split%20the%20Array%20to%20Make%20Coprime%20Products/images/capture.png" style="width: 450px; height: 215px;" /></p>

<pre>
<strong>输入：</strong>nums = [4,7,15,8,3,5]
<strong>输出：</strong>-1
<strong>解释：</strong>上表展示了每个下标 i 处的前 i + 1 个元素的乘积、剩余元素的乘积和它们的最大公约数的值。
不存在有效分割。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：质因数分解

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findValidSplit(self, nums: List[int]) -> int:
        first = {}
        n = len(nums)
        last = list(range(n))
        for i, x in enumerate(nums):
            j = 2
            while j <= x // j:
                if x % j == 0:
                    if j in first:
                        last[first[j]] = i
                    else:
                        first[j] = i
                    while x % j == 0:
                        x //= j
                j += 1
            if x > 1:
                if x in first:
                    last[first[x]] = i
                else:
                    first[x] = i
        mx = last[0]
        for i, x in enumerate(last):
            if mx < i:
                return mx
            mx = max(mx, x)
        return -1
```

#### Java

```java
class Solution {
    public int findValidSplit(int[] nums) {
        Map<Integer, Integer> first = new HashMap<>();
        int n = nums.length;
        int[] last = new int[n];
        for (int i = 0; i < n; ++i) {
            last[i] = i;
        }
        for (int i = 0; i < n; ++i) {
            int x = nums[i];
            for (int j = 2; j <= x / j; ++j) {
                if (x % j == 0) {
                    if (first.containsKey(j)) {
                        last[first.get(j)] = i;
                    } else {
                        first.put(j, i);
                    }
                    while (x % j == 0) {
                        x /= j;
                    }
                }
            }
            if (x > 1) {
                if (first.containsKey(x)) {
                    last[first.get(x)] = i;
                } else {
                    first.put(x, i);
                }
            }
        }
        int mx = last[0];
        for (int i = 0; i < n; ++i) {
            if (mx < i) {
                return mx;
            }
            mx = Math.max(mx, last[i]);
        }
        return -1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int findValidSplit(vector<int>& nums) {
        unordered_map<int, int> first;
        int n = nums.size();
        vector<int> last(n);
        iota(last.begin(), last.end(), 0);
        for (int i = 0; i < n; ++i) {
            int x = nums[i];
            for (int j = 2; j <= x / j; ++j) {
                if (x % j == 0) {
                    if (first.count(j)) {
                        last[first[j]] = i;
                    } else {
                        first[j] = i;
                    }
                    while (x % j == 0) {
                        x /= j;
                    }
                }
            }
            if (x > 1) {
                if (first.count(x)) {
                    last[first[x]] = i;
                } else {
                    first[x] = i;
                }
            }
        }
        int mx = last[0];
        for (int i = 0; i < n; ++i) {
            if (mx < i) {
                return mx;
            }
            mx = max(mx, last[i]);
        }
        return -1;
    }
};
```

#### Go

```go
func findValidSplit(nums []int) int {
	first := map[int]int{}
	n := len(nums)
	last := make([]int, n)
	for i := range last {
		last[i] = i
	}
	for i, x := range nums {
		for j := 2; j <= x/j; j++ {
			if x%j == 0 {
				if k, ok := first[j]; ok {
					last[k] = i
				} else {
					first[j] = i
				}
				for x%j == 0 {
					x /= j
				}
			}
		}
		if x > 1 {
			if k, ok := first[x]; ok {
				last[k] = i
			} else {
				first[x] = i
			}
		}
	}
	mx := last[0]
	for i, x := range last {
		if mx < i {
			return mx
		}
		mx = max(mx, x)
	}
	return -1
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2585. 获得分数的方法数](https://leetcode.cn/problems/number-of-ways-to-earn-points){#2585}

{{< tabs "2585" >}}

{{% tab "python" %}}
```python
class Solution:
    def waysToReachTarget(self, target: int, types: List[List[int]]) -> int:
        n = len(types)
        mod = 10**9 + 7
        f = [[0] * (target + 1) for _ in range(n + 1)]
        f[0][0] = 1
        for i in range(1, n + 1):
            count, marks = types[i - 1]
            for j in range(target + 1):
                for k in range(count + 1):
                    if j >= k * marks:
                        f[i][j] = (f[i][j] + f[i - 1][j - k * marks]) % mod
        return f[n][target]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int waysToReachTarget(int target, int[][] types) {
        int n = types.length;
        final int mod = (int) 1e9 + 7;
        int[][] f = new int[n + 1][target + 1];
        f[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            int count = types[i - 1][0], marks = types[i - 1][1];
            for (int j = 0; j <= target; ++j) {
                for (int k = 0; k <= count; ++k) {
                    if (j >= k * marks) {
                        f[i][j] = (f[i][j] + f[i - 1][j - k * marks]) % mod;
                    }
                }
            }
        }
        return f[n][target];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        int n = types.size();
        const int mod = 1e9 + 7;
        int f[n + 1][target + 1];
        memset(f, 0, sizeof(f));
        f[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            int count = types[i - 1][0], marks = types[i - 1][1];
            for (int j = 0; j <= target; ++j) {
                for (int k = 0; k <= count; ++k) {
                    if (j >= k * marks) {
                        f[i][j] = (f[i][j] + f[i - 1][j - k * marks]) % mod;
                    }
                }
            }
        }
        return f[n][target];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func waysToReachTarget(target int, types [][]int) int {
	n := len(types)
	f := make([][]int, n+1)
	for i := range f {
		f[i] = make([]int, target+1)
	}
	f[0][0] = 1
	const mod = 1e9 + 7
	for i := 1; i <= n; i++ {
		count, marks := types[i-1][0], types[i-1][1]
		for j := 0; j <= target; j++ {
			for k := 0; k <= count; k++ {
				if j >= k*marks {
					f[i][j] = (f[i][j] + f[i-1][j-k*marks]) % mod
				}
			}
		}
	}
	return f[n][target]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function waysToReachTarget(target: number, types: number[][]): number {
    const n = types.length;
    const mod = 10 ** 9 + 7;
    const f: number[][] = Array.from({ length: n + 1 }, () => Array(target + 1).fill(0));
    f[0][0] = 1;
    for (let i = 1; i <= n; ++i) {
        const [count, marks] = types[i - 1];
        for (let j = 0; j <= target; ++j) {
            for (let k = 0; k <= count; ++k) {
                if (j >= k * marks) {
                    f[i][j] = (f[i][j] + f[i - 1][j - k * marks]) % mod;
                }
            }
        }
    }
    return f[n][target];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>考试中有 <code>n</code> 种类型的题目。给你一个整数 <code>target</code> 和一个下标从 <strong>0</strong> 开始的二维整数数组 <code>types</code> ，其中 <code>types[i] = [count<sub>i</sub>, marks<sub>i</sub>] </code>表示第 <code>i</code> 种类型的题目有 <code>count<sub>i</sub></code> 道，每道题目对应 <code>marks<sub>i</sub></code> 分。</p>

<p>返回你在考试中恰好得到 <code>target</code> 分的方法数。由于答案可能很大，结果需要对 <code>10<sup>9</sup> +7</code> 取余。</p>

<p><strong>注意</strong>，同类型题目无法区分。</p>

<ul>
	<li>比如说，如果有 <code>3</code> 道同类型题目，那么解答第 <code>1</code> 和第 <code>2</code> 道题目与解答第 <code>1</code> 和第 <code>3</code> 道题目或者第 <code>2</code> 和第 <code>3</code> 道题目是相同的。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>target = 6, types = [[6,1],[3,2],[2,3]]
<strong>输出：</strong>7
<strong>解释：</strong>要获得 6 分，你可以选择以下七种方法之一：
- 解决 6 道第 0 种类型的题目：1 + 1 + 1 + 1 + 1 + 1 = 6
- 解决 4 道第 0 种类型的题目和 1 道第 1 种类型的题目：1 + 1 + 1 + 1 + 2 = 6
- 解决 2 道第 0 种类型的题目和 2 道第 1 种类型的题目：1 + 1 + 2 + 2 = 6
- 解决 3 道第 0 种类型的题目和 1 道第 2 种类型的题目：1 + 1 + 1 + 3 = 6
- 解决 1 道第 0 种类型的题目、1 道第 1 种类型的题目和 1 道第 2 种类型的题目：1 + 2 + 3 = 6
- 解决 3 道第 1 种类型的题目：2 + 2 + 2 = 6
- 解决 2 道第 2 种类型的题目：3 + 3 = 6
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>target = 5, types = [[50,1],[50,2],[50,5]]
<strong>输出：</strong>4
<strong>解释：</strong>要获得 5 分，你可以选择以下四种方法之一：
- 解决 5 道第 0 种类型的题目：1 + 1 + 1 + 1 + 1 = 5
- 解决 3 道第 0 种类型的题目和 1 道第 1 种类型的题目：1 + 1 + 1 + 2 = 5
- 解决 1 道第 0 种类型的题目和 2 道第 1 种类型的题目：1 + 2 + 2 = 5
- 解决 1 道第 2 种类型的题目：5
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>target = 18, types = [[6,1],[3,2],[2,3]]
<strong>输出：</strong>1
<strong>解释：</strong>只有回答所有题目才能获得 18 分。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= target &lt;= 1000</code></li>
	<li><code>n == types.length</code></li>
	<li><code>1 &lt;= n &lt;= 50</code></li>
	<li><code>types[i].length == 2</code></li>
	<li><code>1 &lt;= count<sub>i</sub>, marks<sub>i</sub> &lt;= 50</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i][j]$ 表示前 $i$ 种类型的题目中，恰好得到 $j$ 分的方法数。初始时 $f[0][0] = 1$，其余 $f[i][j] = 0$。答案即为 $f[n][target]$。

我们可以枚举第 $i$ 种类型的题目，假设该类型题目的数量为 $count$，分数为 $marks$，那么我们可以得到如下状态转移方程：

$$
f[i][j] = \sum_{k=0}^{count} f[i-1][j-k \times marks]
$$

其中 $k$ 表示第 $i$ 种类型的题目的数量。

最终的答案即为 $f[n][target]$。注意答案可能很大，需要对 $10^9 + 7$ 取模。

时间复杂度 $O(n \times target \times count)$，空间复杂度 $O(n \times target)$。其中 $n$ 为题目类型的数量；而 $target$ 和 $count$ 分别为题目的目标分数和每种类型题目的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def waysToReachTarget(self, target: int, types: List[List[int]]) -> int:
        n = len(types)
        mod = 10**9 + 7
        f = [[0] * (target + 1) for _ in range(n + 1)]
        f[0][0] = 1
        for i in range(1, n + 1):
            count, marks = types[i - 1]
            for j in range(target + 1):
                for k in range(count + 1):
                    if j >= k * marks:
                        f[i][j] = (f[i][j] + f[i - 1][j - k * marks]) % mod
        return f[n][target]
```

#### Java

```java
class Solution {
    public int waysToReachTarget(int target, int[][] types) {
        int n = types.length;
        final int mod = (int) 1e9 + 7;
        int[][] f = new int[n + 1][target + 1];
        f[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            int count = types[i - 1][0], marks = types[i - 1][1];
            for (int j = 0; j <= target; ++j) {
                for (int k = 0; k <= count; ++k) {
                    if (j >= k * marks) {
                        f[i][j] = (f[i][j] + f[i - 1][j - k * marks]) % mod;
                    }
                }
            }
        }
        return f[n][target];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        int n = types.size();
        const int mod = 1e9 + 7;
        int f[n + 1][target + 1];
        memset(f, 0, sizeof(f));
        f[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            int count = types[i - 1][0], marks = types[i - 1][1];
            for (int j = 0; j <= target; ++j) {
                for (int k = 0; k <= count; ++k) {
                    if (j >= k * marks) {
                        f[i][j] = (f[i][j] + f[i - 1][j - k * marks]) % mod;
                    }
                }
            }
        }
        return f[n][target];
    }
};
```

#### Go

```go
func waysToReachTarget(target int, types [][]int) int {
	n := len(types)
	f := make([][]int, n+1)
	for i := range f {
		f[i] = make([]int, target+1)
	}
	f[0][0] = 1
	const mod = 1e9 + 7
	for i := 1; i <= n; i++ {
		count, marks := types[i-1][0], types[i-1][1]
		for j := 0; j <= target; j++ {
			for k := 0; k <= count; k++ {
				if j >= k*marks {
					f[i][j] = (f[i][j] + f[i-1][j-k*marks]) % mod
				}
			}
		}
	}
	return f[n][target]
}
```

#### TypeScript

```ts
function waysToReachTarget(target: number, types: number[][]): number {
    const n = types.length;
    const mod = 10 ** 9 + 7;
    const f: number[][] = Array.from({ length: n + 1 }, () => Array(target + 1).fill(0));
    f[0][0] = 1;
    for (let i = 1; i <= n; ++i) {
        const [count, marks] = types[i - 1];
        for (let j = 0; j <= target; ++j) {
            for (let k = 0; k <= count; ++k) {
                if (j >= k * marks) {
                    f[i][j] = (f[i][j] + f[i - 1][j - k * marks]) % mod;
                }
            }
        }
    }
    return f[n][target];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2586. 统计范围内的元音字符串数](https://leetcode.cn/problems/count-the-number-of-vowel-strings-in-range){#2586}

{{< tabs "2586" >}}

{{% tab "python" %}}
```python
class Solution:
    def vowelStrings(self, words: List[str], left: int, right: int) -> int:
        return sum(
            w[0] in 'aeiou' and w[-1] in 'aeiou' for w in words[left : right + 1]
        )
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int vowelStrings(String[] words, int left, int right) {
        int ans = 0;
        for (int i = left; i <= right; ++i) {
            var w = words[i];
            if (check(w.charAt(0)) && check(w.charAt(w.length() - 1))) {
                ++ans;
            }
        }
        return ans;
    }

    private boolean check(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        auto check = [](char c) -> bool {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };
        int ans = 0;
        for (int i = left; i <= right; ++i) {
            auto w = words[i];
            ans += check(w[0]) && check(w[w.size() - 1]);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func vowelStrings(words []string, left int, right int) (ans int) {
	check := func(c byte) bool {
		return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
	}
	for _, w := range words[left : right+1] {
		if check(w[0]) && check(w[len(w)-1]) {
			ans++
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function vowelStrings(words: string[], left: number, right: number): number {
    let ans = 0;
    const check: string[] = ['a', 'e', 'i', 'o', 'u'];
    for (let i = left; i <= right; ++i) {
        const w = words[i];
        if (check.includes(w[0]) && check.includes(w.at(-1))) {
            ++ans;
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn vowel_strings(words: Vec<String>, left: i32, right: i32) -> i32 {
        let check =
            |c: u8| -> bool { c == b'a' || c == b'e' || c == b'i' || c == b'o' || c == b'u' };

        let mut ans = 0;
        for i in left..=right {
            let w = words[i as usize].as_bytes();
            if check(w[0]) && check(w[w.len() - 1]) {
                ans += 1;
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

<p>给你一个下标从 <strong>0</strong> 开始的字符串数组 <code>words</code> 和两个整数：<code>left</code> 和 <code>right</code> 。</p>

<p>如果字符串以元音字母开头并以元音字母结尾，那么该字符串就是一个 <strong>元音字符串</strong> ，其中元音字母是 <code>'a'</code>、<code>'e'</code>、<code>'i'</code>、<code>'o'</code>、<code>'u'</code> 。</p>

<p>返回<em> </em><code>words[i]</code> 是元音字符串的数目，其中<em> </em><code>i</code> 在闭区间 <code>[left, right]</code> 内。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>words = ["are","amy","u"], left = 0, right = 2
<strong>输出：</strong>2
<strong>解释：</strong>
- "are" 是一个元音字符串，因为它以 'a' 开头并以 'e' 结尾。
- "amy" 不是元音字符串，因为它没有以元音字母结尾。
- "u" 是一个元音字符串，因为它以 'u' 开头并以 'u' 结尾。
在上述范围中的元音字符串数目为 2 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>words = ["hey","aeo","mu","ooo","artro"], left = 1, right = 4
<strong>输出：</strong>3
<strong>解释：</strong>
- "aeo" 是一个元音字符串，因为它以 'a' 开头并以 'o' 结尾。
- "mu" 不是元音字符串，因为它没有以元音字母开头。
- "ooo" 是一个元音字符串，因为它以 'o' 开头并以 'o' 结尾。
- "artro" 是一个元音字符串，因为它以 'a' 开头并以 'o' 结尾。
在上述范围中的元音字符串数目为 3 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 1000</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 10</code></li>
	<li><code>words[i]</code> 仅由小写英文字母组成</li>
	<li><code>0 &lt;= left &lt;= right &lt; words.length</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们只需要遍历区间 $[left,.. right]$ 内的字符串，判断其是否以元音字母开头和结尾即可。若是，则答案加一。

遍历结束后，返回答案即可。

时间复杂度 $O(m)$，空间复杂度 $O(1)$。其中 $m = right - left + 1$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def vowelStrings(self, words: List[str], left: int, right: int) -> int:
        return sum(
            w[0] in 'aeiou' and w[-1] in 'aeiou' for w in words[left : right + 1]
        )
```

#### Java

```java
class Solution {
    public int vowelStrings(String[] words, int left, int right) {
        int ans = 0;
        for (int i = left; i <= right; ++i) {
            var w = words[i];
            if (check(w.charAt(0)) && check(w.charAt(w.length() - 1))) {
                ++ans;
            }
        }
        return ans;
    }

    private boolean check(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
}
```

#### C++

```cpp
class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        auto check = [](char c) -> bool {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };
        int ans = 0;
        for (int i = left; i <= right; ++i) {
            auto w = words[i];
            ans += check(w[0]) && check(w[w.size() - 1]);
        }
        return ans;
    }
};
```

#### Go

```go
func vowelStrings(words []string, left int, right int) (ans int) {
	check := func(c byte) bool {
		return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
	}
	for _, w := range words[left : right+1] {
		if check(w[0]) && check(w[len(w)-1]) {
			ans++
		}
	}
	return
}
```

#### TypeScript

```ts
function vowelStrings(words: string[], left: number, right: number): number {
    let ans = 0;
    const check: string[] = ['a', 'e', 'i', 'o', 'u'];
    for (let i = left; i <= right; ++i) {
        const w = words[i];
        if (check.includes(w[0]) && check.includes(w.at(-1))) {
            ++ans;
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn vowel_strings(words: Vec<String>, left: i32, right: i32) -> i32 {
        let check =
            |c: u8| -> bool { c == b'a' || c == b'e' || c == b'i' || c == b'o' || c == b'u' };

        let mut ans = 0;
        for i in left..=right {
            let w = words[i as usize].as_bytes();
            if check(w[0]) && check(w[w.len() - 1]) {
                ans += 1;
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

# [2587. 重排数组以得到最大前缀分数](https://leetcode.cn/problems/rearrange-array-to-maximize-prefix-score){#2587}

{{< tabs "2587" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxScore(self, nums: List[int]) -> int:
        nums.sort(reverse=True)
        s = 0
        for i, x in enumerate(nums):
            s += x
            if s <= 0:
                return i
        return len(nums)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxScore(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        long s = 0;
        for (int i = 0; i < n; ++i) {
            s += nums[n - i - 1];
            if (s <= 0) {
                return i;
            }
        }
        return n;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        long long s = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            s += nums[i];
            if (s <= 0) {
                return i;
            }
        }
        return n;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxScore(nums []int) int {
	sort.Ints(nums)
	n := len(nums)
	s := 0
	for i := range nums {
		s += nums[n-i-1]
		if s <= 0 {
			return i
		}
	}
	return n
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxScore(nums: number[]): number {
    nums.sort((a, b) => a - b);
    const n = nums.length;
    let s = 0;
    for (let i = 0; i < n; ++i) {
        s += nums[n - i - 1];
        if (s <= 0) {
            return i;
        }
    }
    return n;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn max_score(mut nums: Vec<i32>) -> i32 {
        nums.sort_by(|a, b| b.cmp(a));
        let mut s: i64 = 0;
        for (i, &x) in nums.iter().enumerate() {
            s += x as i64;
            if s <= 0 {
                return i as i32;
            }
        }
        nums.len() as i32
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong> 开始的整数数组 <code>nums</code> 。你可以将 <code>nums</code> 中的元素按 <strong>任意顺序</strong> 重排（包括给定顺序）。</p>

<p>令 <code>prefix</code> 为一个数组，它包含了 <code>nums</code> 重新排列后的前缀和。换句话说，<code>prefix[i]</code> 是 <code>nums</code> 重新排列后下标从 <code>0</code> 到 <code>i</code> 的元素之和。<code>nums</code> 的 <strong>分数</strong> 是 <code>prefix</code> 数组中正整数的个数。</p>

<p>返回可以得到的最大分数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [2,-1,0,1,-3,3,-3]
<strong>输出：</strong>6
<strong>解释：</strong>数组重排为 nums = [2,3,1,-1,-3,0,-3] 。
prefix = [2,5,6,5,2,2,-1] ，分数为 6 。
可以证明 6 是能够得到的最大分数。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [-2,-3,0]
<strong>输出：</strong>0
<strong>解释：</strong>不管怎么重排数组得到的分数都是 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>6</sup> &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 排序

要使得前缀和数组中正整数的个数最多，就要使得前缀和数组中的元素尽可能大，即尽可能多的正整数相加。因此，我们可以将数组 $nums$ 降序排序，然后遍历数组，维护前缀和 $s$，如果 $s \leq 0$，则说明当前位置以及之后的位置都不可能再有正整数，因此直接返回当前位置即可。

否则，遍历结束后，返回数组长度。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 为数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxScore(self, nums: List[int]) -> int:
        nums.sort(reverse=True)
        s = 0
        for i, x in enumerate(nums):
            s += x
            if s <= 0:
                return i
        return len(nums)
```

#### Java

```java
class Solution {
    public int maxScore(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        long s = 0;
        for (int i = 0; i < n; ++i) {
            s += nums[n - i - 1];
            if (s <= 0) {
                return i;
            }
        }
        return n;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        long long s = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            s += nums[i];
            if (s <= 0) {
                return i;
            }
        }
        return n;
    }
};
```

#### Go

```go
func maxScore(nums []int) int {
	sort.Ints(nums)
	n := len(nums)
	s := 0
	for i := range nums {
		s += nums[n-i-1]
		if s <= 0 {
			return i
		}
	}
	return n
}
```

#### TypeScript

```ts
function maxScore(nums: number[]): number {
    nums.sort((a, b) => a - b);
    const n = nums.length;
    let s = 0;
    for (let i = 0; i < n; ++i) {
        s += nums[n - i - 1];
        if (s <= 0) {
            return i;
        }
    }
    return n;
}
```

#### Rust

```rust
impl Solution {
    pub fn max_score(mut nums: Vec<i32>) -> i32 {
        nums.sort_by(|a, b| b.cmp(a));
        let mut s: i64 = 0;
        for (i, &x) in nums.iter().enumerate() {
            s += x as i64;
            if s <= 0 {
                return i as i32;
            }
        }
        nums.len() as i32
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2588. 统计美丽子数组数目](https://leetcode.cn/problems/count-the-number-of-beautiful-subarrays){#2588}

{{< tabs "2588" >}}

{{% tab "python" %}}
```python
class Solution:
    def beautifulSubarrays(self, nums: List[int]) -> int:
        cnt = Counter({0: 1})
        ans = mask = 0
        for x in nums:
            mask ^= x
            ans += cnt[mask]
            cnt[mask] += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long beautifulSubarrays(int[] nums) {
        Map<Integer, Integer> cnt = new HashMap<>();
        cnt.put(0, 1);
        long ans = 0;
        int mask = 0;
        for (int x : nums) {
            mask ^= x;
            ans += cnt.merge(mask, 1, Integer::sum) - 1;
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
    long long beautifulSubarrays(vector<int>& nums) {
        unordered_map<int, int> cnt{{0, 1}};
        long long ans = 0;
        int mask = 0;
        for (int x : nums) {
            mask ^= x;
            ans += cnt[mask]++;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func beautifulSubarrays(nums []int) (ans int64) {
	cnt := map[int]int{0: 1}
	mask := 0
	for _, x := range nums {
		mask ^= x
		ans += int64(cnt[mask])
		cnt[mask]++
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function beautifulSubarrays(nums: number[]): number {
    const cnt = new Map();
    cnt.set(0, 1);
    let ans = 0;
    let mask = 0;
    for (const x of nums) {
        mask ^= x;
        ans += cnt.get(mask) || 0;
        cnt.set(mask, (cnt.get(mask) || 0) + 1);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashMap;

impl Solution {
    pub fn beautiful_subarrays(nums: Vec<i32>) -> i64 {
        let mut cnt = HashMap::new();
        cnt.insert(0, 1);
        let mut ans = 0;
        let mut mask = 0;
        for &x in nums.iter() {
            mask ^= x;
            ans += *cnt.get(&mask).unwrap_or(&0);
            *cnt.entry(mask).or_insert(0) += 1;
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

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组<code>nums</code>&nbsp;。每次操作中，你可以：</p>

<ul>
	<li>选择两个满足&nbsp;<code>0 &lt;= i, j &lt; nums.length</code>&nbsp;的不同下标&nbsp;<code>i</code>&nbsp;和&nbsp;<code>j</code>&nbsp;。</li>
	<li>选择一个非负整数&nbsp;<code>k</code>&nbsp;，满足 <code>nums[i]</code>&nbsp;和 <code>nums[j]</code>&nbsp;在二进制下的第 <code>k</code>&nbsp;位（下标编号从 <strong>0</strong>&nbsp;开始）是 <code>1</code>&nbsp;。</li>
	<li>将 <code>nums[i]</code>&nbsp;和 <code>nums[j]</code>&nbsp;都减去&nbsp;<code>2<sup>k</sup></code>&nbsp;。</li>
</ul>

<p>如果一个子数组内执行上述操作若干次（包括 0 次）后，该子数组可以变成一个全为 <code>0</code>&nbsp;的数组，那么我们称它是一个 <strong>美丽</strong>&nbsp;的子数组。</p>

<p>请你返回数组 <code>nums</code>&nbsp;中 <strong>美丽子数组</strong>&nbsp;的数目。</p>

<p>子数组是一个数组中一段连续 <strong>非空</strong>&nbsp;的元素序列。</p>

<p><strong>注意：</strong>所有元素最初都是 0 的子数组被认为是美丽的，因为不需要进行任何操作。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [4,3,1,2,4]
<b>输出：</b>2
<b>解释：</b>nums 中有 2 个美丽子数组：[4,<em><strong>3,1,2</strong></em>,4] 和 [<em><strong>4,3,1,2,4</strong></em>] 。
- 按照下述步骤，我们可以将子数组 [3,1,2] 中所有元素变成 0 ：
  - 选择 [<em><strong>3</strong></em>, 1, <em><strong>2</strong></em>] 和 k = 1 。将 2 个数字都减去 2<sup>1</sup> ，子数组变成 [1, 1, 0] 。
  - 选择 [<em><strong>1</strong></em>, <em><strong>1</strong></em>, 0] 和 k = 0 。将 2 个数字都减去 2<sup>0</sup> ，子数组变成 [0, 0, 0] 。
- 按照下述步骤，我们可以将子数组 [4,3,1,2,4] 中所有元素变成 0 ：
  - 选择 [<em><strong>4</strong></em>, 3, 1, 2, <em><strong>4</strong></em>] 和 k = 2 。将 2 个数字都减去 2<sup>2</sup> ，子数组变成 [0, 3, 1, 2, 0] 。
  - 选择 [0, <em><strong>3</strong></em>, <em><strong>1</strong></em>, 2, 0] 和 k = 0 。将 2 个数字都减去 2<sup>0</sup> ，子数组变成 [0, 2, 0, 2, 0] 。
  - 选择 [0, <em><strong>2</strong></em>, 0, <em><strong>2</strong></em>, 0] 和 k = 1 。将 2 个数字都减去 2<sup>1</sup> ，子数组变成 [0, 0, 0, 0, 0] 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [1,10,4]
<b>输出：</b>0
<b>解释：</b>nums 中没有任何美丽子数组。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前缀异或 + 哈希表

我们观察发现，一个子数组能变成一个全为 $0$ 的数组，当且仅当该子数组中的所有元素，每一个二进制位上的 $1$ 的个数都是偶数个。

如果存在下标 $i$ 和 $j$，满足 $i \lt j$，且子数组 $nums[0,..,i]$ 和 $nums[0,..,j]$ 二进制位上的 $1$ 的个数同奇同偶，那么就可以将子数组 $nums[i + 1,..,j]$ 变成一个全为 $0$ 的数组。

因此，我们可以用前缀异或的方法，用哈希表 $cnt$ 统计每个前缀异或值出现的次数。遍历数组，对于每个元素 $x$，我们计算出它的前缀异或值 $mask$，然后将 $mask$ 出现的次数加到答案中。然后，我们将 $mask$ 的出现次数加 $1$。

最后，我们返回答案即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def beautifulSubarrays(self, nums: List[int]) -> int:
        cnt = Counter({0: 1})
        ans = mask = 0
        for x in nums:
            mask ^= x
            ans += cnt[mask]
            cnt[mask] += 1
        return ans
```

#### Java

```java
class Solution {
    public long beautifulSubarrays(int[] nums) {
        Map<Integer, Integer> cnt = new HashMap<>();
        cnt.put(0, 1);
        long ans = 0;
        int mask = 0;
        for (int x : nums) {
            mask ^= x;
            ans += cnt.merge(mask, 1, Integer::sum) - 1;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        unordered_map<int, int> cnt{{0, 1}};
        long long ans = 0;
        int mask = 0;
        for (int x : nums) {
            mask ^= x;
            ans += cnt[mask]++;
        }
        return ans;
    }
};
```

#### Go

```go
func beautifulSubarrays(nums []int) (ans int64) {
	cnt := map[int]int{0: 1}
	mask := 0
	for _, x := range nums {
		mask ^= x
		ans += int64(cnt[mask])
		cnt[mask]++
	}
	return
}
```

#### TypeScript

```ts
function beautifulSubarrays(nums: number[]): number {
    const cnt = new Map();
    cnt.set(0, 1);
    let ans = 0;
    let mask = 0;
    for (const x of nums) {
        mask ^= x;
        ans += cnt.get(mask) || 0;
        cnt.set(mask, (cnt.get(mask) || 0) + 1);
    }
    return ans;
}
```

#### Rust

```rust
use std::collections::HashMap;

impl Solution {
    pub fn beautiful_subarrays(nums: Vec<i32>) -> i64 {
        let mut cnt = HashMap::new();
        cnt.insert(0, 1);
        let mut ans = 0;
        let mut mask = 0;
        for &x in nums.iter() {
            mask ^= x;
            ans += *cnt.get(&mask).unwrap_or(&0);
            *cnt.entry(mask).or_insert(0) += 1;
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

# [2589. 完成所有任务的最少时间](https://leetcode.cn/problems/minimum-time-to-complete-all-tasks){#2589}

{{< tabs "2589" >}}

{{% tab "python" %}}
```python
class Solution:
    def findMinimumTime(self, tasks: List[List[int]]) -> int:
        tasks.sort(key=lambda x: x[1])
        vis = [0] * 2010
        ans = 0
        for start, end, duration in tasks:
            duration -= sum(vis[start : end + 1])
            i = end
            while i >= start and duration > 0:
                if not vis[i]:
                    duration -= 1
                    vis[i] = 1
                    ans += 1
                i -= 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int findMinimumTime(int[][] tasks) {
        Arrays.sort(tasks, (a, b) -> a[1] - b[1]);
        int[] vis = new int[2010];
        int ans = 0;
        for (var task : tasks) {
            int start = task[0], end = task[1], duration = task[2];
            for (int i = start; i <= end; ++i) {
                duration -= vis[i];
            }
            for (int i = end; i >= start && duration > 0; --i) {
                if (vis[i] == 0) {
                    --duration;
                    ans += vis[i] = 1;
                }
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
    int findMinimumTime(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [&](auto& a, auto& b) { return a[1] < b[1]; });
        bitset<2010> vis;
        int ans = 0;
        for (auto& task : tasks) {
            int start = task[0], end = task[1], duration = task[2];
            for (int i = start; i <= end; ++i) {
                duration -= vis[i];
            }
            for (int i = end; i >= start && duration > 0; --i) {
                if (!vis[i]) {
                    --duration;
                    ans += vis[i] = 1;
                }
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findMinimumTime(tasks [][]int) (ans int) {
	sort.Slice(tasks, func(i, j int) bool { return tasks[i][1] < tasks[j][1] })
	vis := [2010]int{}
	for _, task := range tasks {
		start, end, duration := task[0], task[1], task[2]
		for _, x := range vis[start : end+1] {
			duration -= x
		}
		for i := end; i >= start && duration > 0; i-- {
			if vis[i] == 0 {
				vis[i] = 1
				duration--
				ans++
			}
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findMinimumTime(tasks: number[][]): number {
    tasks.sort((a, b) => a[1] - b[1]);
    const vis: number[] = Array(2010).fill(0);
    let ans = 0;
    for (let [start, end, duration] of tasks) {
        for (let i = start; i <= end; ++i) {
            duration -= vis[i];
        }
        for (let i = end; i >= start && duration > 0; --i) {
            if (vis[i] === 0) {
                --duration;
                ans += vis[i] = 1;
            }
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn find_minimum_time(tasks: Vec<Vec<i32>>) -> i32 {
        let mut tasks = tasks;
        tasks.sort_by(|a, b| a[1].cmp(&b[1]));
        let mut vis = vec![0; 2010];
        let mut ans = 0;

        for task in tasks {
            let start = task[0] as usize;
            let end = task[1] as usize;
            let mut duration = task[2] - vis[start..=end].iter().sum::<i32>();
            let mut i = end;

            while i >= start && duration > 0 {
                if vis[i] == 0 {
                    duration -= 1;
                    vis[i] = 1;
                    ans += 1;
                }
                i -= 1;
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

<p>你有一台电脑，它可以 <strong>同时</strong>&nbsp;运行无数个任务。给你一个二维整数数组&nbsp;<code>tasks</code>&nbsp;，其中&nbsp;<code>tasks[i] = [start<sub>i</sub>, end<sub>i</sub>, duration<sub>i</sub>]</code>&nbsp;表示第&nbsp;<code>i</code>&nbsp;个任务需要在 <strong>闭区间</strong>&nbsp;时间段&nbsp;<code>[start<sub>i</sub>, end<sub>i</sub>]</code>&nbsp;内运行&nbsp;<code>duration<sub>i</sub></code>&nbsp;个整数时间点（但不需要连续）。</p>

<p>当电脑需要运行任务时，你可以打开电脑，如果空闲时，你可以将电脑关闭。</p>

<p>请你返回完成所有任务的情况下，电脑最少需要运行多少秒。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>tasks = [[2,3,1],[4,5,1],[1,5,2]]
<b>输出：</b>2
<b>解释：</b>
- 第一个任务在闭区间 [2, 2] 运行。
- 第二个任务在闭区间 [5, 5] 运行。
- 第三个任务在闭区间 [2, 2] 和 [5, 5] 运行。
电脑总共运行 2 个整数时间点。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>tasks = [[1,3,2],[2,5,3],[5,6,2]]
<b>输出：</b>4
<b>解释：</b>
- 第一个任务在闭区间 [2, 3] 运行
- 第二个任务在闭区间 [2, 3] 和 [5, 5] 运行。
- 第三个任务在闭区间 [5, 6] 运行。
电脑总共运行 4 个整数时间点。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= tasks.length &lt;= 2000</code></li>
	<li><code>tasks[i].length == 3</code></li>
	<li><code>1 &lt;= start<sub>i</sub>, end<sub>i</sub> &lt;= 2000</code></li>
	<li><code>1 &lt;= duration<sub>i</sub> &lt;= end<sub>i</sub> - start<sub>i</sub> + 1 </code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 排序

我们观察发现，题目相当于在每一个区间 $[start,..,end]$ 中，选择 $duration$ 个整数时间点，使得总共选择的整数时间点最少。

因此，我们可以先对 $tasks$ 按照结束时间 $end$ 从小到大排序。然后贪心地进行选择，对于每一个任务，我们从结束时间 $end$ 开始，从后往前选择尽可能靠后的点，这样这些点更有可能被后面的任务重复利用。

我们在实现上，可以用一个长度为 $2010$ 的数组 $vis$ 记录每个时间点是否被选择过。然后对于每一个任务，我们先统计 $[start,..,end]$ 区间内已经被选择过的点的个数 $cnt$，然后从后往前选择 $duration - cnt$ 个点，同时记录选择的点的个数 $ans$ 以及更新 $vis$ 数组。

最后，我们返回 $ans$ 即可。

时间复杂度 $O(n \times \log n + n \times m)$，空间复杂度 $O(m)$。其中 $n$ 和 $m$ 分别为 $tasks$ 的长度和 $vis$ 数组的长度。本题中 $m = 2010$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findMinimumTime(self, tasks: List[List[int]]) -> int:
        tasks.sort(key=lambda x: x[1])
        vis = [0] * 2010
        ans = 0
        for start, end, duration in tasks:
            duration -= sum(vis[start : end + 1])
            i = end
            while i >= start and duration > 0:
                if not vis[i]:
                    duration -= 1
                    vis[i] = 1
                    ans += 1
                i -= 1
        return ans
```

#### Java

```java
class Solution {
    public int findMinimumTime(int[][] tasks) {
        Arrays.sort(tasks, (a, b) -> a[1] - b[1]);
        int[] vis = new int[2010];
        int ans = 0;
        for (var task : tasks) {
            int start = task[0], end = task[1], duration = task[2];
            for (int i = start; i <= end; ++i) {
                duration -= vis[i];
            }
            for (int i = end; i >= start && duration > 0; --i) {
                if (vis[i] == 0) {
                    --duration;
                    ans += vis[i] = 1;
                }
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
    int findMinimumTime(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [&](auto& a, auto& b) { return a[1] < b[1]; });
        bitset<2010> vis;
        int ans = 0;
        for (auto& task : tasks) {
            int start = task[0], end = task[1], duration = task[2];
            for (int i = start; i <= end; ++i) {
                duration -= vis[i];
            }
            for (int i = end; i >= start && duration > 0; --i) {
                if (!vis[i]) {
                    --duration;
                    ans += vis[i] = 1;
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func findMinimumTime(tasks [][]int) (ans int) {
	sort.Slice(tasks, func(i, j int) bool { return tasks[i][1] < tasks[j][1] })
	vis := [2010]int{}
	for _, task := range tasks {
		start, end, duration := task[0], task[1], task[2]
		for _, x := range vis[start : end+1] {
			duration -= x
		}
		for i := end; i >= start && duration > 0; i-- {
			if vis[i] == 0 {
				vis[i] = 1
				duration--
				ans++
			}
		}
	}
	return
}
```

#### TypeScript

```ts
function findMinimumTime(tasks: number[][]): number {
    tasks.sort((a, b) => a[1] - b[1]);
    const vis: number[] = Array(2010).fill(0);
    let ans = 0;
    for (let [start, end, duration] of tasks) {
        for (let i = start; i <= end; ++i) {
            duration -= vis[i];
        }
        for (let i = end; i >= start && duration > 0; --i) {
            if (vis[i] === 0) {
                --duration;
                ans += vis[i] = 1;
            }
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn find_minimum_time(tasks: Vec<Vec<i32>>) -> i32 {
        let mut tasks = tasks;
        tasks.sort_by(|a, b| a[1].cmp(&b[1]));
        let mut vis = vec![0; 2010];
        let mut ans = 0;

        for task in tasks {
            let start = task[0] as usize;
            let end = task[1] as usize;
            let mut duration = task[2] - vis[start..=end].iter().sum::<i32>();
            let mut i = end;

            while i >= start && duration > 0 {
                if vis[i] == 0 {
                    duration -= 1;
                    vis[i] = 1;
                    ans += 1;
                }
                i -= 1;
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
