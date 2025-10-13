---
title: "2360_图中的最长环"
date: 2025-10-08T18:39:12+08:00
weight: 7
tags: [动态规划, 双指针, 哈希表, 图, 并查集, 广度优先搜索, 拓扑排序, 排序, 数学, 数据库, 数组, 有序集合, 枚举, 树, 模拟, 深度优先搜索, 计数, 贪心]
---

{{< markmap >}}
### [2360_图中的最长环](#2360)
#### [深度优先搜索](#2360)
#### [广度优先搜索](#2360)
#### [图](#2360)
#### [拓扑排序](#2360)
### [2361_乘坐火车路线的最少费用 🔒](#2361)
#### [数组](#2361)
#### [动态规划](#2361)
### [2362_生成发票 🔒](#2362)
#### [数据库](#2362)
### [2363_合并相似的物品](#2363)
#### [数组](#2363)
#### [哈希表](#2363)
#### [有序集合](#2363)
#### [排序](#2363)
### [2364_统计坏数对的数目](#2364)
#### [数组](#2364)
#### [哈希表](#2364)
#### [数学](#2364)
#### [计数](#2364)
### [2365_任务调度器 II](#2365)
#### [数组](#2365)
#### [哈希表](#2365)
#### [模拟](#2365)
### [2366_将数组排序的最少替换次数](#2366)
#### [贪心](#2366)
#### [数组](#2366)
#### [数学](#2366)
### [2367_等差三元组的数目](#2367)
#### [数组](#2367)
#### [哈希表](#2367)
#### [双指针](#2367)
#### [枚举](#2367)
### [2368_受限条件下可到达节点的数目](#2368)
#### [树](#2368)
#### [深度优先搜索](#2368)
#### [广度优先搜索](#2368)
#### [并查集](#2368)
#### [图](#2368)
#### [数组](#2368)
#### [哈希表](#2368)
### [2369_检查数组是否存在有效划分](#2369)
#### [数组](#2369)
#### [动态规划](#2369)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2360_图中的最长环
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 图
___
#### 拓扑排序
---
### 2361_乘坐火车路线的最少费用 🔒
___
#### 数组
___
#### 动态规划
---
### 2362_生成发票 🔒
___
#### 数据库
---
### 2363_合并相似的物品
___
#### 数组
___
#### 哈希表
___
#### 有序集合
___
#### 排序
---
### 2364_统计坏数对的数目
___
#### 数组
___
#### 哈希表
___
#### 数学
___
#### 计数
---
### 2365_任务调度器 II
___
#### 数组
___
#### 哈希表
___
#### 模拟
---
### 2366_将数组排序的最少替换次数
___
#### 贪心
___
#### 数组
___
#### 数学
---
### 2367_等差三元组的数目
___
#### 数组
___
#### 哈希表
___
#### 双指针
___
#### 枚举
---
### 2368_受限条件下可到达节点的数目
___
#### 树
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 并查集
___
#### 图
___
#### 数组
___
#### 哈希表
---
### 2369_检查数组是否存在有效划分
___
#### 数组
___
#### 动态规划
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 动态规划 | 双指针 | 哈希表 |
| 图 | 并查集 | 广度优先搜索 |
| 拓扑排序 | 排序 | 数学 |
| 数据库 | 数组 | 有序集合 |
| 枚举 | 树 | 模拟 |
| 深度优先搜索 | 计数 | 贪心 |

# [2360. 图中的最长环](https://leetcode.cn/problems/longest-cycle-in-a-graph){#2360}

{{< tabs "2360" >}}

{{% tab "python" %}}
```python
class Solution:
    def longestCycle(self, edges: List[int]) -> int:
        n = len(edges)
        vis = [False] * n
        ans = -1
        for i in range(n):
            if vis[i]:
                continue
            j = i
            cycle = []
            while j != -1 and not vis[j]:
                vis[j] = True
                cycle.append(j)
                j = edges[j]
            if j == -1:
                continue
            m = len(cycle)
            k = next((k for k in range(m) if cycle[k] == j), inf)
            ans = max(ans, m - k)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int longestCycle(int[] edges) {
        int n = edges.length;
        boolean[] vis = new boolean[n];
        int ans = -1;
        for (int i = 0; i < n; ++i) {
            if (vis[i]) {
                continue;
            }
            int j = i;
            List<Integer> cycle = new ArrayList<>();
            for (; j != -1 && !vis[j]; j = edges[j]) {
                vis[j] = true;
                cycle.add(j);
            }
            if (j == -1) {
                continue;
            }
            for (int k = 0; k < cycle.size(); ++k) {
                if (cycle.get(k) == j) {
                    ans = Math.max(ans, cycle.size() - k);
                    break;
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
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<bool> vis(n);
        int ans = -1;
        for (int i = 0; i < n; ++i) {
            if (vis[i]) {
                continue;
            }
            int j = i;
            vector<int> cycle;
            for (; j != -1 && !vis[j]; j = edges[j]) {
                vis[j] = true;
                cycle.push_back(j);
            }
            if (j == -1) {
                continue;
            }
            for (int k = 0; k < cycle.size(); ++k) {
                if (cycle[k] == j) {
                    ans = max(ans, (int) cycle.size() - k);
                    break;
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
func longestCycle(edges []int) int {
	vis := make([]bool, len(edges))
	ans := -1
	for i := range edges {
		if vis[i] {
			continue
		}
		j := i
		cycle := []int{}
		for ; j != -1 && !vis[j]; j = edges[j] {
			vis[j] = true
			cycle = append(cycle, j)
		}
		if j == -1 {
			continue
		}
		for k := range cycle {
			if cycle[k] == j {
				ans = max(ans, len(cycle)-k)
				break
			}
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function longestCycle(edges: number[]): number {
    const n = edges.length;
    const vis: boolean[] = Array(n).fill(false);
    let ans = -1;
    for (let i = 0; i < n; ++i) {
        if (vis[i]) {
            continue;
        }
        let j = i;
        const cycle: number[] = [];
        for (; j !== -1 && !vis[j]; j = edges[j]) {
            vis[j] = true;
            cycle.push(j);
        }
        if (j === -1) {
            continue;
        }
        for (let k = 0; k < cycle.length; ++k) {
            if (cycle[k] === j) {
                ans = Math.max(ans, cycle.length - k);
                break;
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
    pub fn longest_cycle(edges: Vec<i32>) -> i32 {
        let n = edges.len();
        let mut vis = vec![false; n];
        let mut ans = -1;

        for i in 0..n {
            if vis[i] {
                continue;
            }
            let mut j = i as i32;
            let mut cycle = Vec::new();

            while j != -1 && !vis[j as usize] {
                vis[j as usize] = true;
                cycle.push(j);
                j = edges[j as usize];
            }

            if j == -1 {
                continue;
            }

            for k in 0..cycle.len() {
                if cycle[k] == j {
                    ans = ans.max((cycle.len() - k) as i32);
                    break;
                }
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

<p>给你一个 <code>n</code>&nbsp;个节点的 <b>有向图</b>&nbsp;，节点编号为&nbsp;<code>0</code>&nbsp;到&nbsp;<code>n - 1</code>&nbsp;，其中每个节点&nbsp;<strong>至多</strong>&nbsp;有一条出边。</p>

<p>图用一个大小为 <code>n</code>&nbsp;下标从<strong>&nbsp;0</strong>&nbsp;开始的数组&nbsp;<code>edges</code>&nbsp;表示，节点 <code>i</code>&nbsp;到节点&nbsp;<code>edges[i]</code>&nbsp;之间有一条有向边。如果节点&nbsp;<code>i</code>&nbsp;没有出边，那么&nbsp;<code>edges[i] == -1</code>&nbsp;。</p>

<p>请你返回图中的 <strong>最长</strong>&nbsp;环，如果没有任何环，请返回 <code>-1</code>&nbsp;。</p>

<p>一个环指的是起点和终点是 <strong>同一个</strong>&nbsp;节点的路径。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2300-2399/2360.Longest%20Cycle%20in%20a%20Graph/images/graph4drawio-5.png" style="width: 335px; height: 191px;" /></p>

<pre>
<b>输入：</b>edges = [3,3,4,2,3]
<b>输出去：</b>3
<b>解释：</b>图中的最长环是：2 -&gt; 4 -&gt; 3 -&gt; 2 。
这个环的长度为 3 ，所以返回 3 。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2300-2399/2360.Longest%20Cycle%20in%20a%20Graph/images/graph4drawio-1.png" style="width: 171px; height: 161px;" /></p>

<pre>
<b>输入：</b>edges = [2,-1,3,1]
<b>输出：</b>-1
<b>解释：</b>图中没有任何环。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == edges.length</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>-1 &lt;= edges[i] &lt; n</code></li>
	<li><code>edges[i] != i</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：遍历出发点

我们可以遍历 $[0,..,n-1]$ 范围内的每个节点，如果该节点未被访问过，则从该节点出发，搜索邻边节点，直到遇到环或者遇到已经访问过的节点。如果遇到环，则更新答案。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为节点数。

相似题目：

-   [2127. 参加会议的最多员工数](https://github.com/doocs/leetcode/blob/main/solution/2100-2199/2127.Maximum%20Employees%20to%20Be%20Invited%20to%20a%20Meeting/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def longestCycle(self, edges: List[int]) -> int:
        n = len(edges)
        vis = [False] * n
        ans = -1
        for i in range(n):
            if vis[i]:
                continue
            j = i
            cycle = []
            while j != -1 and not vis[j]:
                vis[j] = True
                cycle.append(j)
                j = edges[j]
            if j == -1:
                continue
            m = len(cycle)
            k = next((k for k in range(m) if cycle[k] == j), inf)
            ans = max(ans, m - k)
        return ans
```

#### Java

```java
class Solution {
    public int longestCycle(int[] edges) {
        int n = edges.length;
        boolean[] vis = new boolean[n];
        int ans = -1;
        for (int i = 0; i < n; ++i) {
            if (vis[i]) {
                continue;
            }
            int j = i;
            List<Integer> cycle = new ArrayList<>();
            for (; j != -1 && !vis[j]; j = edges[j]) {
                vis[j] = true;
                cycle.add(j);
            }
            if (j == -1) {
                continue;
            }
            for (int k = 0; k < cycle.size(); ++k) {
                if (cycle.get(k) == j) {
                    ans = Math.max(ans, cycle.size() - k);
                    break;
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
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<bool> vis(n);
        int ans = -1;
        for (int i = 0; i < n; ++i) {
            if (vis[i]) {
                continue;
            }
            int j = i;
            vector<int> cycle;
            for (; j != -1 && !vis[j]; j = edges[j]) {
                vis[j] = true;
                cycle.push_back(j);
            }
            if (j == -1) {
                continue;
            }
            for (int k = 0; k < cycle.size(); ++k) {
                if (cycle[k] == j) {
                    ans = max(ans, (int) cycle.size() - k);
                    break;
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func longestCycle(edges []int) int {
	vis := make([]bool, len(edges))
	ans := -1
	for i := range edges {
		if vis[i] {
			continue
		}
		j := i
		cycle := []int{}
		for ; j != -1 && !vis[j]; j = edges[j] {
			vis[j] = true
			cycle = append(cycle, j)
		}
		if j == -1 {
			continue
		}
		for k := range cycle {
			if cycle[k] == j {
				ans = max(ans, len(cycle)-k)
				break
			}
		}
	}
	return ans
}
```

#### TypeScript

```ts
function longestCycle(edges: number[]): number {
    const n = edges.length;
    const vis: boolean[] = Array(n).fill(false);
    let ans = -1;
    for (let i = 0; i < n; ++i) {
        if (vis[i]) {
            continue;
        }
        let j = i;
        const cycle: number[] = [];
        for (; j !== -1 && !vis[j]; j = edges[j]) {
            vis[j] = true;
            cycle.push(j);
        }
        if (j === -1) {
            continue;
        }
        for (let k = 0; k < cycle.length; ++k) {
            if (cycle[k] === j) {
                ans = Math.max(ans, cycle.length - k);
                break;
            }
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn longest_cycle(edges: Vec<i32>) -> i32 {
        let n = edges.len();
        let mut vis = vec![false; n];
        let mut ans = -1;

        for i in 0..n {
            if vis[i] {
                continue;
            }
            let mut j = i as i32;
            let mut cycle = Vec::new();

            while j != -1 && !vis[j as usize] {
                vis[j as usize] = true;
                cycle.push(j);
                j = edges[j as usize];
            }

            if j == -1 {
                continue;
            }

            for k in 0..cycle.len() {
                if cycle[k] == j {
                    ans = ans.max((cycle.len() - k) as i32);
                    break;
                }
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

# [2361. 乘坐火车路线的最少费用 🔒](https://leetcode.cn/problems/minimum-costs-using-the-train-line){#2361}

{{< tabs "2361" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumCosts(
        self, regular: List[int], express: List[int], expressCost: int
    ) -> List[int]:
        n = len(regular)
        f, g = 0, inf
        cost = [0] * n
        for i, (a, b) in enumerate(zip(regular, express), 1):
            ff = min(f + a, g + a)
            gg = min(f + expressCost + b, g + b)
            f, g = ff, gg
            cost[i - 1] = min(f, g)
        return cost
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long[] minimumCosts(int[] regular, int[] express, int expressCost) {
        int n = regular.length;
        long f = 0;
        long g = 1 << 30;
        long[] cost = new long[n];
        for (int i = 0; i < n; ++i) {
            int a = regular[i];
            int b = express[i];
            long ff = Math.min(f + a, g + a);
            long gg = Math.min(f + expressCost + b, g + b);
            f = ff;
            g = gg;
            cost[i] = Math.min(f, g);
        }
        return cost;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<long long> minimumCosts(vector<int>& regular, vector<int>& express, int expressCost) {
        int n = regular.size();
        long long f = 0;
        long long g = 1 << 30;
        vector<long long> cost(n);
        for (int i = 0; i < n; ++i) {
            int a = regular[i];
            int b = express[i];
            long long ff = min(f + a, g + a);
            long long gg = min(f + expressCost + b, g + b);
            f = ff;
            g = gg;
            cost[i] = min(f, g);
        }
        return cost;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumCosts(regular []int, express []int, expressCost int) []int64 {
	f, g := 0, 1<<30
	cost := make([]int64, len(regular))
	for i, a := range regular {
		b := express[i]
		ff := min(f+a, g+a)
		gg := min(f+expressCost+b, g+b)
		f, g = ff, gg
		cost[i] = int64(min(f, g))
	}
	return cost
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumCosts(regular: number[], express: number[], expressCost: number): number[] {
    const n = regular.length;
    let f = 0;
    let g = 1 << 30;
    const cost: number[] = new Array(n).fill(0);
    for (let i = 0; i < n; ++i) {
        const [a, b] = [regular[i], express[i]];
        const ff = Math.min(f + a, g + a);
        const gg = Math.min(f + expressCost + b, g + b);
        [f, g] = [ff, gg];
        cost[i] = Math.min(f, g);
    }
    return cost;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>城市中的火车有两条路线，分别是常规路线和特快路线。两条路线经过 <strong>相同 </strong>的 <code>n + 1</code> 个车站，车站编号从 <code>0</code> 到 <code>n</code>。初始时，你位于车站 <code>0</code> 的常规路线。</p>

<p>给你两个<strong> 下标从 1 开始 </strong>、长度均为 <code>n</code> 的两个整数数组 <code>regular</code> 和 <code>express</code> ，其中 <code>regular[i]</code> 表示乘坐常规路线从车站&nbsp;<code>i - 1</code> 到车站&nbsp;<code>i</code> 的费用，<code>express[i]</code> 表示乘坐特快路线从车站&nbsp;<code>i - 1</code> 到车站&nbsp;<code>i</code> 的费用。</p>

<p>另外给你一个整数 <code>expressCost</code>，表示从常规路线转换到特快路线的费用。</p>

<p>注意：</p>

<ul>
	<li>从特快路线转换回常规路线没有费用。</li>
	<li><strong>每次 </strong>从常规路线转换到特快路线，你都需要支付 <code>expressCost</code> 的费用。</li>
	<li>留在特快路线上没有额外费用。</li>
</ul>

<p>返回<strong> 下标从 1 开始</strong> 、长度为 <code>n</code> 的数组 <code>costs</code>，其中 <code>costs[i]</code> 是从车站 <code>0</code> 到车站 <code>i</code> 的最少费用。</p>

<p>注意：每个车站都可以从任意一条路线 <strong>到达 </strong>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2300-2399/2361.Minimum%20Costs%20Using%20the%20Train%20Line/images/ex1drawio.png" style="width: 442px; height: 150px;" />
<pre>
<strong>输入：</strong>regular = [1,6,9,5], express = [5,2,3,10], expressCost = 8
<strong>输出：</strong>[1,7,14,19]
<strong>解释：</strong>上图展示了从车站 0 到车站 4 的最少费用方法。
- 乘坐常规路线从车站 0 到车站 1，费用是 1。
- 乘坐特快路线从车站 1 到车站 2，费用是 8 + 2 = 10。
- 乘坐特快路线从车站 2 到车站 3，费用是 3。
- 乘坐常规路线从车站 3 到车站 4，费用是 5。
总费用是 1 + 10 + 3 + 5 + 19。
注意到达其他车站的最少费用方法可以选择不同的路线。
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2300-2399/2361.Minimum%20Costs%20Using%20the%20Train%20Line/images/ex2drawio.png" style="width: 346px; height: 150px;" />
<pre>
<strong>输入：</strong>regular = [11,5,13], express = [7,10,6], expressCost = 3
<strong>输出：</strong>[10,15,24]
<strong>解释：</strong>上图展示了从车站 0 到车站 3 的最少费用方法。
- 乘坐特快路线从车站 0 到车站 1，费用是 3 + 7 = 10。
- 乘坐常规路线从车站 1 到车站 2，费用是 5。
- 乘坐特快路线从车站 2 到车站 3，费用是 3 + 6 = 9。
总费用是 10 + 5 + 9 = 24。
注意转换回特快路线时需要再次支付 expressCost 的费用。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == regular.length == express.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= regular[i], express[i], expressCost &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i]$ 表示从车站 $0$ 到车站 $i$ 且到达车站 $i$ 时乘坐常规路线的最少费用，定义 $g[i]$ 表示从车站 $0$ 到车站 $i$ 且到达车站 $i$ 时乘坐特快路线的最少费用。初始时 $f[0]=0, g[0]=\infty$。

接下来，我们考虑 $f[i]$ 和 $g[i]$ 如何进行状态转移。

如果我们到达车站 $i$ 乘坐的是常规路线，那么我们可以从车站 $i-1$ 乘坐常规路线或者从车站 $i-1$ 乘坐特快路线转换到常规路线。因此我们可以得到状态转移方程：

$$
f[i]=\min\{f[i-1]+a_i, g[i-1]+a_i\}
$$

其中 $a_i$ 表示从车站 $i-1$ 到车站 $i$ 乘坐常规路线的费用。

如果我们到达车站 $i$ 乘坐的是特快路线，那么我们可以从车站 $i-1$ 乘坐常规路线转换到特快路线或者从车站 $i-1$ 乘坐特快路线。因此我们可以得到状态转移方程：

$$
g[i]=\min\{f[i-1]+expressCost+b_i, g[i-1]+b_i\}
$$

其中 $b_i$ 表示从车站 $i-1$ 到车站 $i$ 乘坐特快路线的费用。

我们记答案数组为 $cost$，其中 $cost[i]$ 表示从车站 $0$ 到车站 $i$ 的最少费用。由于我们可以从任意一条路线到达车站 $i$，因此我们有 $cost[i]=\min\{f[i], g[i]\}$。

最后返回 $cost$ 即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 表示车站的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumCosts(
        self, regular: List[int], express: List[int], expressCost: int
    ) -> List[int]:
        n = len(regular)
        f = [0] * (n + 1)
        g = [inf] * (n + 1)
        cost = [0] * n
        for i, (a, b) in enumerate(zip(regular, express), 1):
            f[i] = min(f[i - 1] + a, g[i - 1] + a)
            g[i] = min(f[i - 1] + expressCost + b, g[i - 1] + b)
            cost[i - 1] = min(f[i], g[i])
        return cost
```

#### Java

```java
class Solution {
    public long[] minimumCosts(int[] regular, int[] express, int expressCost) {
        int n = regular.length;
        long[] f = new long[n + 1];
        long[] g = new long[n + 1];
        g[0] = 1 << 30;
        long[] cost = new long[n];
        for (int i = 1; i <= n; ++i) {
            int a = regular[i - 1];
            int b = express[i - 1];
            f[i] = Math.min(f[i - 1] + a, g[i - 1] + a);
            g[i] = Math.min(f[i - 1] + expressCost + b, g[i - 1] + b);
            cost[i - 1] = Math.min(f[i], g[i]);
        }
        return cost;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<long long> minimumCosts(vector<int>& regular, vector<int>& express, int expressCost) {
        int n = regular.size();
        long long f[n + 1];
        long long g[n + 1];
        f[0] = 0;
        g[0] = 1 << 30;
        vector<long long> cost(n);
        for (int i = 1; i <= n; ++i) {
            int a = regular[i - 1];
            int b = express[i - 1];
            f[i] = min(f[i - 1] + a, g[i - 1] + a);
            g[i] = min(f[i - 1] + expressCost + b, g[i - 1] + b);
            cost[i - 1] = min(f[i], g[i]);
        }
        return cost;
    }
};
```

#### Go

```go
func minimumCosts(regular []int, express []int, expressCost int) []int64 {
	n := len(regular)
	f := make([]int, n+1)
	g := make([]int, n+1)
	g[0] = 1 << 30
	cost := make([]int64, n)
	for i := 1; i <= n; i++ {
		a, b := regular[i-1], express[i-1]
		f[i] = min(f[i-1]+a, g[i-1]+a)
		g[i] = min(f[i-1]+expressCost+b, g[i-1]+b)
		cost[i-1] = int64(min(f[i], g[i]))
	}
	return cost
}
```

#### TypeScript

```ts
function minimumCosts(regular: number[], express: number[], expressCost: number): number[] {
    const n = regular.length;
    const f: number[] = new Array(n + 1).fill(0);
    const g: number[] = new Array(n + 1).fill(0);
    g[0] = 1 << 30;
    const cost: number[] = new Array(n).fill(0);
    for (let i = 1; i <= n; ++i) {
        const [a, b] = [regular[i - 1], express[i - 1]];
        f[i] = Math.min(f[i - 1] + a, g[i - 1] + a);
        g[i] = Math.min(f[i - 1] + expressCost + b, g[i - 1] + b);
        cost[i - 1] = Math.min(f[i], g[i]);
    }
    return cost;
}
```

<!-- tabs:end -->

我们注意到 $f[i]$ 和 $g[i]$ 的状态转移方程中，我们只需要用到 $f[i-1]$ 和 $g[i-1]$，因此我们可以使用两个变量 $f$ 和 $g$ 分别记录 $f[i-1]$ 和 $g[i-1]$ 的值，这样可以将空间复杂度优化到 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumCosts(
        self, regular: List[int], express: List[int], expressCost: int
    ) -> List[int]:
        n = len(regular)
        f, g = 0, inf
        cost = [0] * n
        for i, (a, b) in enumerate(zip(regular, express), 1):
            ff = min(f + a, g + a)
            gg = min(f + expressCost + b, g + b)
            f, g = ff, gg
            cost[i - 1] = min(f, g)
        return cost
```

#### Java

```java
class Solution {
    public long[] minimumCosts(int[] regular, int[] express, int expressCost) {
        int n = regular.length;
        long f = 0;
        long g = 1 << 30;
        long[] cost = new long[n];
        for (int i = 0; i < n; ++i) {
            int a = regular[i];
            int b = express[i];
            long ff = Math.min(f + a, g + a);
            long gg = Math.min(f + expressCost + b, g + b);
            f = ff;
            g = gg;
            cost[i] = Math.min(f, g);
        }
        return cost;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<long long> minimumCosts(vector<int>& regular, vector<int>& express, int expressCost) {
        int n = regular.size();
        long long f = 0;
        long long g = 1 << 30;
        vector<long long> cost(n);
        for (int i = 0; i < n; ++i) {
            int a = regular[i];
            int b = express[i];
            long long ff = min(f + a, g + a);
            long long gg = min(f + expressCost + b, g + b);
            f = ff;
            g = gg;
            cost[i] = min(f, g);
        }
        return cost;
    }
};
```

#### Go

```go
func minimumCosts(regular []int, express []int, expressCost int) []int64 {
	f, g := 0, 1<<30
	cost := make([]int64, len(regular))
	for i, a := range regular {
		b := express[i]
		ff := min(f+a, g+a)
		gg := min(f+expressCost+b, g+b)
		f, g = ff, gg
		cost[i] = int64(min(f, g))
	}
	return cost
}
```

#### TypeScript

```ts
function minimumCosts(regular: number[], express: number[], expressCost: number): number[] {
    const n = regular.length;
    let f = 0;
    let g = 1 << 30;
    const cost: number[] = new Array(n).fill(0);
    for (let i = 0; i < n; ++i) {
        const [a, b] = [regular[i], express[i]];
        const ff = Math.min(f + a, g + a);
        const gg = Math.min(f + expressCost + b, g + b);
        [f, g] = [ff, gg];
        cost[i] = Math.min(f, g);
    }
    return cost;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2362. 生成发票 🔒](https://leetcode.cn/problems/generate-the-invoice){#2362}

{{< tabs "2362" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    P AS (
        SELECT *
        FROM
            Purchases
            JOIN Products USING (product_id)
    ),
    T AS (
        SELECT invoice_id, SUM(price * quantity) AS amount
        FROM P
        GROUP BY invoice_id
        ORDER BY 2 DESC, 1
        LIMIT 1
    )
SELECT product_id, quantity, (quantity * price) AS price
FROM
    P
    JOIN T USING (invoice_id);
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表: <code>Products</code></p>

<pre>
+-------------+------+
| Column Name | Type |
+-------------+------+
| product_id  | int  |
| price       | int  |
+-------------+------+
product_id 包含唯一值。
该表中的每一行显示了一个产品的 ID 和一个单位的价格。
</pre>

<p>&nbsp;</p>

<p>表: <code>Purchases</code></p>

<pre>
+-------------+------+
| Column Name | Type |
+-------------+------+
| invoice_id  | int  |
| product_id  | int  |
| quantity    | int  |
+-------------+------+
(invoice_id, product_id) 是该表的主键（具有唯一值的列的组合）
该表中的每一行都显示了从发票中的一种产品订购的数量。
</pre>

<p>&nbsp;</p>

<p>编写解决方案，展示价格最高的发票的详细信息。如果两个或多个发票具有相同的价格，则返回 <code>invoice_id</code> 最小的发票的详细信息。</p>

<p data-group="1-1">以 <strong>任意顺序</strong> 返回结果表。</p>

<p>结果格式示例如下。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> 
Products 表:
+------------+-------+
| product_id | price |
+------------+-------+
| 1          | 100   |
| 2          | 200   |
+------------+-------+
Purchases 表:
+------------+------------+----------+
| invoice_id | product_id | quantity |
+------------+------------+----------+
| 1          | 1          | 2        |
| 3          | 2          | 1        |
| 2          | 2          | 3        |
| 2          | 1          | 4        |
| 4          | 1          | 10       |
+------------+------------+----------+
<strong>输出:</strong> 
+------------+----------+-------+
| product_id | quantity | price |
+------------+----------+-------+
| 2          | 3        | 600   |
| 1          | 4        | 400   |
+------------+----------+-------+
<strong>解释:</strong> 
发票 1: price = (2 * 100) = $200
发票 2: price = (4 * 100) + (3 * 200) = $1000
发票 3: price = (1 * 200) = $200
发票 4: price = (10 * 100) = $1000

最高价格是 1000 美元，最高价格的发票是 2 和 4。我们返回 ID 最小的发票 2 的详细信息。</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
WITH
    P AS (
        SELECT *
        FROM
            Purchases
            JOIN Products USING (product_id)
    ),
    T AS (
        SELECT invoice_id, SUM(price * quantity) AS amount
        FROM P
        GROUP BY invoice_id
        ORDER BY 2 DESC, 1
        LIMIT 1
    )
SELECT product_id, quantity, (quantity * price) AS price
FROM
    P
    JOIN T USING (invoice_id);
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2363. 合并相似的物品](https://leetcode.cn/problems/merge-similar-items){#2363}

{{< tabs "2363" >}}

{{% tab "python" %}}
```python
class Solution:
    def mergeSimilarItems(
        self, items1: List[List[int]], items2: List[List[int]]
    ) -> List[List[int]]:
        cnt = Counter()
        for v, w in chain(items1, items2):
            cnt[v] += w
        return sorted(cnt.items())
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<List<Integer>> mergeSimilarItems(int[][] items1, int[][] items2) {
        int[] cnt = new int[1010];
        for (var x : items1) {
            cnt[x[0]] += x[1];
        }
        for (var x : items2) {
            cnt[x[0]] += x[1];
        }
        List<List<Integer>> ans = new ArrayList<>();
        for (int i = 0; i < cnt.length; ++i) {
            if (cnt[i] > 0) {
                ans.add(List.of(i, cnt[i]));
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
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        int cnt[1010]{};
        for (auto& x : items1) {
            cnt[x[0]] += x[1];
        }
        for (auto& x : items2) {
            cnt[x[0]] += x[1];
        }
        vector<vector<int>> ans;
        for (int i = 0; i < 1010; ++i) {
            if (cnt[i]) {
                ans.push_back({i, cnt[i]});
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func mergeSimilarItems(items1 [][]int, items2 [][]int) (ans [][]int) {
	cnt := [1010]int{}
	for _, x := range items1 {
		cnt[x[0]] += x[1]
	}
	for _, x := range items2 {
		cnt[x[0]] += x[1]
	}
	for i, x := range cnt {
		if x > 0 {
			ans = append(ans, []int{i, x})
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function mergeSimilarItems(items1: number[][], items2: number[][]): number[][] {
    const count = new Array(1001).fill(0);
    for (const [v, w] of items1) {
        count[v] += w;
    }
    for (const [v, w] of items2) {
        count[v] += w;
    }
    return [...count.entries()].filter(v => v[1] !== 0);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn merge_similar_items(items1: Vec<Vec<i32>>, items2: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let mut count = [0; 1001];
        for item in items1.iter() {
            count[item[0] as usize] += item[1];
        }
        for item in items2.iter() {
            count[item[0] as usize] += item[1];
        }
        count
            .iter()
            .enumerate()
            .filter_map(|(i, &v)| {
                if v == 0 {
                    return None;
                }
                Some(vec![i as i32, v])
            })
            .collect()
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** mergeSimilarItems(int** items1, int items1Size, int* items1ColSize, int** items2, int items2Size,
    int* items2ColSize, int* returnSize, int** returnColumnSizes) {
    int count[1001] = {0};
    for (int i = 0; i < items1Size; i++) {
        count[items1[i][0]] += items1[i][1];
    }
    for (int i = 0; i < items2Size; i++) {
        count[items2[i][0]] += items2[i][1];
    }
    int** ans = malloc(sizeof(int*) * (items1Size + items2Size));
    *returnColumnSizes = malloc(sizeof(int) * (items1Size + items2Size));
    int size = 0;
    for (int i = 0; i < 1001; i++) {
        if (count[i]) {
            ans[size] = malloc(sizeof(int) * 2);
            ans[size][0] = i;
            ans[size][1] = count[i];
            (*returnColumnSizes)[size] = 2;
            size++;
        }
    }
    *returnSize = size;
    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个二维整数数组&nbsp;<code>items1</code> 和&nbsp;<code>items2</code>&nbsp;，表示两个物品集合。每个数组&nbsp;<code>items</code>&nbsp;有以下特质：</p>

<ul>
	<li><code>items[i] = [value<sub>i</sub>, weight<sub>i</sub>]</code> 其中&nbsp;<code>value<sub>i</sub></code>&nbsp;表示第&nbsp;<code>i</code>&nbsp;件物品的&nbsp;<strong>价值</strong>&nbsp;，<code>weight<sub>i</sub></code>&nbsp;表示第 <code>i</code>&nbsp;件物品的 <strong>重量</strong>&nbsp;。</li>
	<li><code>items</code>&nbsp;中每件物品的价值都是 <strong>唯一的</strong>&nbsp;。</li>
</ul>

<p>请你返回一个二维数组&nbsp;<code>ret</code>，其中&nbsp;<code>ret[i] = [value<sub>i</sub>, weight<sub>i</sub>]</code>，&nbsp;<code>weight<sub>i</sub></code>&nbsp;是所有价值为&nbsp;<code>value<sub>i</sub></code><sub>&nbsp;</sub>物品的&nbsp;<strong>重量之和</strong>&nbsp;。</p>

<p><strong>注意：</strong><code>ret</code>&nbsp;应该按价值 <strong>升序</strong>&nbsp;排序后返回。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>items1 = [[1,1],[4,5],[3,8]], items2 = [[3,1],[1,5]]
<b>输出：</b>[[1,6],[3,9],[4,5]]
<b>解释：</b>
value = 1 的物品在 items1 中 weight = 1 ，在 items2 中 weight = 5 ，总重量为 1 + 5 = 6 。
value = 3 的物品再 items1 中 weight = 8 ，在 items2 中 weight = 1 ，总重量为 8 + 1 = 9 。
value = 4 的物品在 items1 中 weight = 5 ，总重量为 5 。
所以，我们返回 [[1,6],[3,9],[4,5]] 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>items1 = [[1,1],[3,2],[2,3]], items2 = [[2,1],[3,2],[1,3]]
<b>输出：</b>[[1,4],[2,4],[3,4]]
<b>解释：</b>
value = 1 的物品在 items1 中 weight = 1 ，在 items2 中 weight = 3 ，总重量为 1 + 3 = 4 。
value = 2 的物品在 items1 中 weight = 3 ，在 items2 中 weight = 1 ，总重量为 3 + 1 = 4 。
value = 3 的物品在 items1 中 weight = 2 ，在 items2 中 weight = 2 ，总重量为 2 + 2 = 4 。
所以，我们返回 [[1,4],[2,4],[3,4]] 。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>items1 = [[1,3],[2,2]], items2 = [[7,1],[2,2],[1,4]]
<b>输出：</b>[[1,7],[2,4],[7,1]]
<strong>解释：
</strong>value = 1 的物品在 items1 中 weight = 3 ，在 items2 中 weight = 4 ，总重量为 3 + 4 = 7 。
value = 2 的物品在 items1 中 weight = 2 ，在 items2 中 weight = 2 ，总重量为 2 + 2 = 4 。
value = 7 的物品在 items2 中 weight = 1 ，总重量为 1 。
所以，我们返回 [[1,7],[2,4],[7,1]] 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= items1.length, items2.length &lt;= 1000</code></li>
	<li><code>items1[i].length == items2[i].length == 2</code></li>
	<li><code>1 &lt;= value<sub>i</sub>, weight<sub>i</sub> &lt;= 1000</code></li>
	<li><code>items1</code>&nbsp;中每个 <code>value<sub>i</sub></code>&nbsp;都是 <b>唯一的</b>&nbsp;。</li>
	<li><code>items2</code>&nbsp;中每个 <code>value<sub>i</sub></code>&nbsp;都是 <b>唯一的</b>&nbsp;。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表或数组

我们可以用哈希表或数组 `cnt` 统计 `items1` 和 `items2` 中每个物品的总重量，然后从小到大遍历价值，将每个价值以及对应的总重量加入结果数组即可。

时间复杂度 $O(n + m)$，空间复杂度 $O(n + m)$。其中 $n$ 和 $m$ 分别是 `items1` 和 `items2` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def mergeSimilarItems(
        self, items1: List[List[int]], items2: List[List[int]]
    ) -> List[List[int]]:
        cnt = Counter()
        for v, w in chain(items1, items2):
            cnt[v] += w
        return sorted(cnt.items())
```

#### Java

```java
class Solution {
    public List<List<Integer>> mergeSimilarItems(int[][] items1, int[][] items2) {
        int[] cnt = new int[1010];
        for (var x : items1) {
            cnt[x[0]] += x[1];
        }
        for (var x : items2) {
            cnt[x[0]] += x[1];
        }
        List<List<Integer>> ans = new ArrayList<>();
        for (int i = 0; i < cnt.length; ++i) {
            if (cnt[i] > 0) {
                ans.add(List.of(i, cnt[i]));
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
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        int cnt[1010]{};
        for (auto& x : items1) {
            cnt[x[0]] += x[1];
        }
        for (auto& x : items2) {
            cnt[x[0]] += x[1];
        }
        vector<vector<int>> ans;
        for (int i = 0; i < 1010; ++i) {
            if (cnt[i]) {
                ans.push_back({i, cnt[i]});
            }
        }
        return ans;
    }
};
```

#### Go

```go
func mergeSimilarItems(items1 [][]int, items2 [][]int) (ans [][]int) {
	cnt := [1010]int{}
	for _, x := range items1 {
		cnt[x[0]] += x[1]
	}
	for _, x := range items2 {
		cnt[x[0]] += x[1]
	}
	for i, x := range cnt {
		if x > 0 {
			ans = append(ans, []int{i, x})
		}
	}
	return
}
```

#### TypeScript

```ts
function mergeSimilarItems(items1: number[][], items2: number[][]): number[][] {
    const count = new Array(1001).fill(0);
    for (const [v, w] of items1) {
        count[v] += w;
    }
    for (const [v, w] of items2) {
        count[v] += w;
    }
    return [...count.entries()].filter(v => v[1] !== 0);
}
```

#### Rust

```rust
impl Solution {
    pub fn merge_similar_items(items1: Vec<Vec<i32>>, items2: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let mut count = [0; 1001];
        for item in items1.iter() {
            count[item[0] as usize] += item[1];
        }
        for item in items2.iter() {
            count[item[0] as usize] += item[1];
        }
        count
            .iter()
            .enumerate()
            .filter_map(|(i, &v)| {
                if v == 0 {
                    return None;
                }
                Some(vec![i as i32, v])
            })
            .collect()
    }
}
```

#### C

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** mergeSimilarItems(int** items1, int items1Size, int* items1ColSize, int** items2, int items2Size,
    int* items2ColSize, int* returnSize, int** returnColumnSizes) {
    int count[1001] = {0};
    for (int i = 0; i < items1Size; i++) {
        count[items1[i][0]] += items1[i][1];
    }
    for (int i = 0; i < items2Size; i++) {
        count[items2[i][0]] += items2[i][1];
    }
    int** ans = malloc(sizeof(int*) * (items1Size + items2Size));
    *returnColumnSizes = malloc(sizeof(int) * (items1Size + items2Size));
    int size = 0;
    for (int i = 0; i < 1001; i++) {
        if (count[i]) {
            ans[size] = malloc(sizeof(int) * 2);
            ans[size][0] = i;
            ans[size][1] = count[i];
            (*returnColumnSizes)[size] = 2;
            size++;
        }
    }
    *returnSize = size;
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2364. 统计坏数对的数目](https://leetcode.cn/problems/count-number-of-bad-pairs){#2364}

{{< tabs "2364" >}}

{{% tab "python" %}}
```python
class Solution:
    def countBadPairs(self, nums: List[int]) -> int:
        cnt = Counter()
        ans = 0
        for i, x in enumerate(nums):
            ans += i - cnt[i - x]
            cnt[i - x] += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long countBadPairs(int[] nums) {
        Map<Integer, Integer> cnt = new HashMap<>();
        long ans = 0;
        for (int i = 0; i < nums.length; ++i) {
            int x = i - nums[i];
            ans += i - cnt.merge(x, 1, Integer::sum) + 1;
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
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, int> cnt;
        long long ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int x = i - nums[i];
            ans += i - cnt[x]++;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countBadPairs(nums []int) (ans int64) {
	cnt := map[int]int{}
	for i, x := range nums {
		x = i - x
		ans += int64(i - cnt[x])
		cnt[x]++
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countBadPairs(nums: number[]): number {
    const cnt = new Map<number, number>();
    let ans = 0;
    for (let i = 0; i < nums.length; ++i) {
        const x = i - nums[i];
        ans += i - (cnt.get(x) ?? 0);
        cnt.set(x, (cnt.get(x) ?? 0) + 1);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashMap;

impl Solution {
    pub fn count_bad_pairs(nums: Vec<i32>) -> i64 {
        let mut cnt: HashMap<i32, i64> = HashMap::new();
        let mut ans: i64 = 0;
        for (i, &num) in nums.iter().enumerate() {
            let x = i as i32 - num;
            let count = *cnt.get(&x).unwrap_or(&0);
            ans += i as i64 - count;
            *cnt.entry(x).or_insert(0) += 1;
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

<p>给你一个下标从<strong>&nbsp;0</strong>&nbsp;开始的整数数组&nbsp;<code>nums</code>&nbsp;。如果 <code>i &lt; j</code>&nbsp;且&nbsp;<code>j - i != nums[j] - nums[i]</code>&nbsp;，那么我们称&nbsp;<code>(i, j)</code>&nbsp;是一个 <strong>坏</strong><strong>数对</strong>&nbsp;。</p>

<p>请你返回 <code>nums</code>&nbsp;中 <strong>坏数对</strong>&nbsp;的总数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [4,1,3,3]
<b>输出：</b>5
<b>解释：</b>数对 (0, 1) 是坏数对，因为 1 - 0 != 1 - 4 。
数对 (0, 2) 是坏数对，因为 2 - 0 != 3 - 4, 2 != -1 。
数对 (0, 3) 是坏数对，因为 3 - 0 != 3 - 4, 3 != -1 。
数对 (1, 2) 是坏数对，因为 2 - 1 != 3 - 1, 1 != 2 。
数对 (2, 3) 是坏数对，因为 3 - 2 != 3 - 3, 1 != 0 。
总共有 5 个坏数对，所以我们返回 5 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [1,2,3,4,5]
<b>输出：</b>0
<strong>解释：</strong>没有坏数对。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：式子转换 + 哈希表

根据题目描述，我们可以得知，对于任意的 $i \lt j$，如果 $j - i \neq \textit{nums}[j] - \textit{nums}[i]$，则 $(i, j)$ 是一个坏数对。

我们可以将式子转换为 $i - \textit{nums}[i] \neq j - \textit{nums}[j]$。这启发我们用哈希表 $cnt$ 来统计 $i - \textit{nums}[i]$ 的出现次数。

遍历数组，对于当前元素 $\textit{nums}[i]$，我们将 $i - cnt[i - \textit{nums}[i]]$ 加到答案中，然后将 $i - \textit{nums}[i]$ 的出现次数加 $1$。

最后，我们返回答案即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $\textit{nums}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countBadPairs(self, nums: List[int]) -> int:
        cnt = Counter()
        ans = 0
        for i, x in enumerate(nums):
            ans += i - cnt[i - x]
            cnt[i - x] += 1
        return ans
```

#### Java

```java
class Solution {
    public long countBadPairs(int[] nums) {
        Map<Integer, Integer> cnt = new HashMap<>();
        long ans = 0;
        for (int i = 0; i < nums.length; ++i) {
            int x = i - nums[i];
            ans += i - cnt.merge(x, 1, Integer::sum) + 1;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, int> cnt;
        long long ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int x = i - nums[i];
            ans += i - cnt[x]++;
        }
        return ans;
    }
};
```

#### Go

```go
func countBadPairs(nums []int) (ans int64) {
	cnt := map[int]int{}
	for i, x := range nums {
		x = i - x
		ans += int64(i - cnt[x])
		cnt[x]++
	}
	return
}
```

#### TypeScript

```ts
function countBadPairs(nums: number[]): number {
    const cnt = new Map<number, number>();
    let ans = 0;
    for (let i = 0; i < nums.length; ++i) {
        const x = i - nums[i];
        ans += i - (cnt.get(x) ?? 0);
        cnt.set(x, (cnt.get(x) ?? 0) + 1);
    }
    return ans;
}
```

#### Rust

```rust
use std::collections::HashMap;

impl Solution {
    pub fn count_bad_pairs(nums: Vec<i32>) -> i64 {
        let mut cnt: HashMap<i32, i64> = HashMap::new();
        let mut ans: i64 = 0;
        for (i, &num) in nums.iter().enumerate() {
            let x = i as i32 - num;
            let count = *cnt.get(&x).unwrap_or(&0);
            ans += i as i64 - count;
            *cnt.entry(x).or_insert(0) += 1;
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

# [2365. 任务调度器 II](https://leetcode.cn/problems/task-scheduler-ii){#2365}

{{< tabs "2365" >}}

{{% tab "python" %}}
```python
class Solution:
    def taskSchedulerII(self, tasks: List[int], space: int) -> int:
        day = defaultdict(int)
        ans = 0
        for task in tasks:
            ans += 1
            ans = max(ans, day[task])
            day[task] = ans + space + 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long taskSchedulerII(int[] tasks, int space) {
        Map<Integer, Long> day = new HashMap<>();
        long ans = 0;
        for (int task : tasks) {
            ++ans;
            ans = Math.max(ans, day.getOrDefault(task, 0L));
            day.put(task, ans + space + 1);
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
    long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<int, long long> day;
        long long ans = 0;
        for (int& task : tasks) {
            ++ans;
            ans = max(ans, day[task]);
            day[task] = ans + space + 1;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func taskSchedulerII(tasks []int, space int) (ans int64) {
	day := map[int]int64{}
	for _, task := range tasks {
		ans++
		if ans < day[task] {
			ans = day[task]
		}
		day[task] = ans + int64(space) + 1
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function taskSchedulerII(tasks: number[], space: number): number {
    const day = new Map<number, number>();
    let ans = 0;
    for (const task of tasks) {
        ++ans;
        ans = Math.max(ans, day.get(task) ?? 0);
        day.set(task, ans + space + 1);
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

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的正整数数组&nbsp;<code>tasks</code>&nbsp;，表示需要 <strong>按顺序</strong>&nbsp;完成的任务，其中&nbsp;<code>tasks[i]</code>&nbsp;表示第&nbsp;<code>i</code>&nbsp;件任务的 <strong>类型</strong>&nbsp;。</p>

<p>同时给你一个正整数&nbsp;<code>space</code>&nbsp;，表示一个任务完成&nbsp;<strong>后</strong>&nbsp;，另一个&nbsp;<strong>相同</strong>&nbsp;类型任务完成前需要间隔的&nbsp;<strong>最少</strong>&nbsp;天数。</p>

<p>在所有任务完成前的每一天，你都必须进行以下两种操作中的一种：</p>

<ul>
	<li>完成&nbsp;<code>tasks</code>&nbsp;中的下一个任务</li>
	<li>休息一天</li>
</ul>

<p>请你返回完成所有任务所需的 <strong>最少</strong>&nbsp;天数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>tasks = [1,2,1,2,3,1], space = 3
<b>输出：</b>9
<strong>解释：</strong>
9 天完成所有任务的一种方法是：
第 1 天：完成任务 0 。
第 2 天：完成任务 1 。
第 3 天：休息。
第 4 天：休息。
第 5 天：完成任务 2 。
第 6 天：完成任务 3 。
第 7 天：休息。
第 8 天：完成任务 4 。
第 9 天：完成任务 5 。
可以证明无法少于 9 天完成所有任务。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>tasks = [5,8,8,5], space = 2
<b>输出：</b>6
<strong>解释：</strong>
6 天完成所有任务的一种方法是：
第 1 天：完成任务 0 。
第 2 天：完成任务 1 。
第 3 天：休息。
第 4 天：休息。
第 5 天：完成任务 2 。
第 6 天：完成任务 3 。
可以证明无法少于 6 天完成所有任务。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= tasks.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= tasks[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= space &lt;= tasks.length</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 模拟

我们可以用哈希表 $day$ 记录每个任务下一次可以被执行的时间，初始时 $day$ 中的所有值都为 $0$，用变量 $ans$ 记录当前时间。

遍历数组 $tasks$，对于每个任务 $task$，当前时间 $ans$ 加一，表示从上一次执行任务到现在已经过去了一天，如果此时 $day[task] \gt ans$，说明任务 $task$ 需要在第 $day[task]$ 天才能被执行，因此我们更新当前时间 $ans = \max(ans, day[task])$。然后更新 $day[task]$ 的值为 $ans + space + 1$，表示任务 $task$ 下一次可以被执行的时间为 $ans + space + 1$。

遍历结束后，将 $ans$ 返回即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $tasks$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def taskSchedulerII(self, tasks: List[int], space: int) -> int:
        day = defaultdict(int)
        ans = 0
        for task in tasks:
            ans += 1
            ans = max(ans, day[task])
            day[task] = ans + space + 1
        return ans
```

#### Java

```java
class Solution {
    public long taskSchedulerII(int[] tasks, int space) {
        Map<Integer, Long> day = new HashMap<>();
        long ans = 0;
        for (int task : tasks) {
            ++ans;
            ans = Math.max(ans, day.getOrDefault(task, 0L));
            day.put(task, ans + space + 1);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<int, long long> day;
        long long ans = 0;
        for (int& task : tasks) {
            ++ans;
            ans = max(ans, day[task]);
            day[task] = ans + space + 1;
        }
        return ans;
    }
};
```

#### Go

```go
func taskSchedulerII(tasks []int, space int) (ans int64) {
	day := map[int]int64{}
	for _, task := range tasks {
		ans++
		if ans < day[task] {
			ans = day[task]
		}
		day[task] = ans + int64(space) + 1
	}
	return
}
```

#### TypeScript

```ts
function taskSchedulerII(tasks: number[], space: number): number {
    const day = new Map<number, number>();
    let ans = 0;
    for (const task of tasks) {
        ++ans;
        ans = Math.max(ans, day.get(task) ?? 0);
        day.set(task, ans + space + 1);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2366. 将数组排序的最少替换次数](https://leetcode.cn/problems/minimum-replacements-to-sort-the-array){#2366}

{{< tabs "2366" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumReplacement(self, nums: List[int]) -> int:
        ans = 0
        n = len(nums)
        mx = nums[-1]
        for i in range(n - 2, -1, -1):
            if nums[i] <= mx:
                mx = nums[i]
                continue
            k = (nums[i] + mx - 1) // mx
            ans += k - 1
            mx = nums[i] // k
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long minimumReplacement(int[] nums) {
        long ans = 0;
        int n = nums.length;
        int mx = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] <= mx) {
                mx = nums[i];
                continue;
            }
            int k = (nums[i] + mx - 1) / mx;
            ans += k - 1;
            mx = nums[i] / k;
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
    long long minimumReplacement(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        int mx = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] <= mx) {
                mx = nums[i];
                continue;
            }
            int k = (nums[i] + mx - 1) / mx;
            ans += k - 1;
            mx = nums[i] / k;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumReplacement(nums []int) (ans int64) {
	n := len(nums)
	mx := nums[n-1]
	for i := n - 2; i >= 0; i-- {
		if nums[i] <= mx {
			mx = nums[i]
			continue
		}
		k := (nums[i] + mx - 1) / mx
		ans += int64(k - 1)
		mx = nums[i] / k
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumReplacement(nums: number[]): number {
    const n = nums.length;
    let mx = nums[n - 1];
    let ans = 0;
    for (let i = n - 2; i >= 0; --i) {
        if (nums[i] <= mx) {
            mx = nums[i];
            continue;
        }
        const k = Math.ceil(nums[i] / mx);
        ans += k - 1;
        mx = Math.floor(nums[i] / k);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    #[allow(dead_code)]
    pub fn minimum_replacement(nums: Vec<i32>) -> i64 {
        if nums.len() == 1 {
            return 0;
        }

        let n = nums.len();
        let mut max = *nums.last().unwrap();
        let mut ret = 0;

        for i in (0..=n - 2).rev() {
            if nums[i] <= max {
                max = nums[i];
                continue;
            }
            // Otherwise make the substitution
            let k = (nums[i] + max - 1) / max;
            ret += (k - 1) as i64;
            // Update the max value, which should be the minimum among the substitution
            max = nums[i] / k;
        }

        ret
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>nums</code>&nbsp;。每次操作中，你可以将数组中任何一个元素替换为&nbsp;<strong>任意两个</strong>&nbsp;和为该元素的数字。</p>

<ul>
	<li>比方说，<code>nums = [5,6,7]</code>&nbsp;。一次操作中，我们可以将&nbsp;<code>nums[1]</code> 替换成&nbsp;<code>2</code> 和&nbsp;<code>4</code>&nbsp;，将&nbsp;<code>nums</code>&nbsp;转变成&nbsp;<code>[5,2,4,7]</code>&nbsp;。</li>
</ul>

<p>请你执行上述操作，将数组变成元素按 <strong>非递减</strong> 顺序排列的数组，并返回所需的最少操作次数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [3,9,3]
<b>输出：</b>2
<b>解释：</b>以下是将数组变成非递减顺序的步骤：
- [3,9,3] ，将9 变成 3 和 6 ，得到数组 [3,3,6,3] 
- [3,3,6,3] ，将 6 变成 3 和 3 ，得到数组 [3,3,3,3,3] 
总共需要 2 步将数组变成非递减有序，所以我们返回 2 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [1,2,3,4,5]
<b>输出：</b>0
<b>解释：</b>数组已经是非递减顺序，所以我们返回 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心

我们观察发现，要使得数组 $nums$ 变成非递减有序，也即单调递增，那么数组后面的元素应该尽可能大，所以，将数组 $nums$ 的最后一个元素 $nums[n-1]$ 替换成多个更小的数是没有必要的。

也即是说，我们可以从后往前遍历数组 $nums$，并且维护当前的最大值 $mx$，初始时 $mx = nums[n-1]$。

-   若当前遍历到的元素 $nums[i] \leq mx$，此时不需要将 $nums[i]$ 进行替换，我们直接更新 $mx = nums[i]$ 即可。
-   否则，我们需要将 $nums[i]$ 替换成多个和为 $nums[i]$ 的数，这些数的最大值为 $mx$，总共替换成 $k=\left \lceil \frac{nums[i]}{mx} \right \rceil$ 个数，所以需要进行 $k-1$ 次操作，累加到答案中。这 $k$ 个数中，最小的数为 $\left \lfloor \frac{nums[i]}{k} \right \rfloor$，因此，我们更新 $mx = \left \lfloor \frac{nums[i]}{k} \right \rfloor$。

遍历结束，返回总的操作次数即可。

时间复杂度 $O(n)$，其中 $n$ 为数组 $nums$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumReplacement(self, nums: List[int]) -> int:
        ans = 0
        n = len(nums)
        mx = nums[-1]
        for i in range(n - 2, -1, -1):
            if nums[i] <= mx:
                mx = nums[i]
                continue
            k = (nums[i] + mx - 1) // mx
            ans += k - 1
            mx = nums[i] // k
        return ans
```

#### Java

```java
class Solution {
    public long minimumReplacement(int[] nums) {
        long ans = 0;
        int n = nums.length;
        int mx = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] <= mx) {
                mx = nums[i];
                continue;
            }
            int k = (nums[i] + mx - 1) / mx;
            ans += k - 1;
            mx = nums[i] / k;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        int mx = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] <= mx) {
                mx = nums[i];
                continue;
            }
            int k = (nums[i] + mx - 1) / mx;
            ans += k - 1;
            mx = nums[i] / k;
        }
        return ans;
    }
};
```

#### Go

```go
func minimumReplacement(nums []int) (ans int64) {
	n := len(nums)
	mx := nums[n-1]
	for i := n - 2; i >= 0; i-- {
		if nums[i] <= mx {
			mx = nums[i]
			continue
		}
		k := (nums[i] + mx - 1) / mx
		ans += int64(k - 1)
		mx = nums[i] / k
	}
	return
}
```

#### TypeScript

```ts
function minimumReplacement(nums: number[]): number {
    const n = nums.length;
    let mx = nums[n - 1];
    let ans = 0;
    for (let i = n - 2; i >= 0; --i) {
        if (nums[i] <= mx) {
            mx = nums[i];
            continue;
        }
        const k = Math.ceil(nums[i] / mx);
        ans += k - 1;
        mx = Math.floor(nums[i] / k);
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    #[allow(dead_code)]
    pub fn minimum_replacement(nums: Vec<i32>) -> i64 {
        if nums.len() == 1 {
            return 0;
        }

        let n = nums.len();
        let mut max = *nums.last().unwrap();
        let mut ret = 0;

        for i in (0..=n - 2).rev() {
            if nums[i] <= max {
                max = nums[i];
                continue;
            }
            // Otherwise make the substitution
            let k = (nums[i] + max - 1) / max;
            ret += (k - 1) as i64;
            // Update the max value, which should be the minimum among the substitution
            max = nums[i] / k;
        }

        ret
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2367. 等差三元组的数目](https://leetcode.cn/problems/number-of-arithmetic-triplets){#2367}

{{< tabs "2367" >}}

{{% tab "python" %}}
```python
class Solution:
    def arithmeticTriplets(self, nums: List[int], diff: int) -> int:
        vis = set(nums)
        return sum(x + diff in vis and x + diff * 2 in vis for x in nums)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int arithmeticTriplets(int[] nums, int diff) {
        boolean[] vis = new boolean[301];
        for (int x : nums) {
            vis[x] = true;
        }
        int ans = 0;
        for (int x : nums) {
            if (vis[x + diff] && vis[x + diff + diff]) {
                ++ans;
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
    int arithmeticTriplets(vector<int>& nums, int diff) {
        bitset<301> vis;
        for (int x : nums) {
            vis[x] = 1;
        }
        int ans = 0;
        for (int x : nums) {
            ans += vis[x + diff] && vis[x + diff + diff];
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func arithmeticTriplets(nums []int, diff int) (ans int) {
	vis := [301]bool{}
	for _, x := range nums {
		vis[x] = true
	}
	for _, x := range nums {
		if vis[x+diff] && vis[x+diff+diff] {
			ans++
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function arithmeticTriplets(nums: number[], diff: number): number {
    const vis: boolean[] = new Array(301).fill(false);
    for (const x of nums) {
        vis[x] = true;
    }
    let ans = 0;
    for (const x of nums) {
        if (vis[x + diff] && vis[x + diff + diff]) {
            ++ans;
        }
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

<p>给你一个下标从 <strong>0</strong> 开始、<strong>严格递增</strong> 的整数数组 <code>nums</code> 和一个正整数 <code>diff</code> 。如果满足下述全部条件，则三元组 <code>(i, j, k)</code> 就是一个 <strong>等差三元组</strong> ：</p>

<ul>
	<li><code>i &lt; j &lt; k</code> ，</li>
	<li><code>nums[j] - nums[i] == diff</code> 且</li>
	<li><code>nums[k] - nums[j] == diff</code></li>
</ul>

<p>返回不同 <strong>等差三元组</strong> 的数目<em>。</em></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [0,1,4,6,7,10], diff = 3
<strong>输出：</strong>2
<strong>解释：</strong>
(1, 2, 4) 是等差三元组：7 - 4 == 3 且 4 - 1 == 3 。
(2, 4, 5) 是等差三元组：10 - 7 == 3 且 7 - 4 == 3 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [4,5,6,7,8,9], diff = 2
<strong>输出：</strong>2
<strong>解释：</strong>
(0, 2, 4) 是等差三元组：8 - 6 == 2 且 6 - 4 == 2 。
(1, 3, 5) 是等差三元组：9 - 7 == 2 且 7 - 5 == 2 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= nums.length &lt;= 200</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 200</code></li>
	<li><code>1 &lt;= diff &lt;= 50</code></li>
	<li><code>nums</code> <strong>严格</strong> 递增</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：暴力枚举

我们注意到，数组 $nums$ 的长度只有不超过 $200$，因此可以直接暴力枚举 $i$, $j$, $k$，判断是否满足条件，若满足，累加三元组数目。

时间复杂度 $O(n^3)$，其中 $n$ 为数组 $nums$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def arithmeticTriplets(self, nums: List[int], diff: int) -> int:
        return sum(b - a == diff and c - b == diff for a, b, c in combinations(nums, 3))
```

#### Java

```java
class Solution {
    public int arithmeticTriplets(int[] nums, int diff) {
        int ans = 0;
        int n = nums.length;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    if (nums[j] - nums[i] == diff && nums[k] - nums[j] == diff) {
                        ++ans;
                    }
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
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    if (nums[j] - nums[i] == diff && nums[k] - nums[j] == diff) {
                        ++ans;
                    }
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func arithmeticTriplets(nums []int, diff int) (ans int) {
	n := len(nums)
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			for k := j + 1; k < n; k++ {
				if nums[j]-nums[i] == diff && nums[k]-nums[j] == diff {
					ans++
				}
			}
		}
	}
	return
}
```

#### TypeScript

```ts
function arithmeticTriplets(nums: number[], diff: number): number {
    const n = nums.length;
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        for (let j = i + 1; j < n; ++j) {
            for (let k = j + 1; k < n; ++k) {
                if (nums[j] - nums[i] === diff && nums[k] - nums[j] === diff) {
                    ++ans;
                }
            }
        }
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：数组或哈希表

我们可以先将 $nums$ 中的元素存入哈希表或数组 $vis$ 中，然后枚举 $nums$ 中的每个元素 $x$，判断 $x+diff$, $x+diff+diff$ 是否也在 $vis$ 中，若是，累加三元组数目。

枚举结束后，返回答案。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def arithmeticTriplets(self, nums: List[int], diff: int) -> int:
        vis = set(nums)
        return sum(x + diff in vis and x + diff * 2 in vis for x in nums)
```

#### Java

```java
class Solution {
    public int arithmeticTriplets(int[] nums, int diff) {
        boolean[] vis = new boolean[301];
        for (int x : nums) {
            vis[x] = true;
        }
        int ans = 0;
        for (int x : nums) {
            if (vis[x + diff] && vis[x + diff + diff]) {
                ++ans;
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
    int arithmeticTriplets(vector<int>& nums, int diff) {
        bitset<301> vis;
        for (int x : nums) {
            vis[x] = 1;
        }
        int ans = 0;
        for (int x : nums) {
            ans += vis[x + diff] && vis[x + diff + diff];
        }
        return ans;
    }
};
```

#### Go

```go
func arithmeticTriplets(nums []int, diff int) (ans int) {
	vis := [301]bool{}
	for _, x := range nums {
		vis[x] = true
	}
	for _, x := range nums {
		if vis[x+diff] && vis[x+diff+diff] {
			ans++
		}
	}
	return
}
```

#### TypeScript

```ts
function arithmeticTriplets(nums: number[], diff: number): number {
    const vis: boolean[] = new Array(301).fill(false);
    for (const x of nums) {
        vis[x] = true;
    }
    let ans = 0;
    for (const x of nums) {
        if (vis[x + diff] && vis[x + diff + diff]) {
            ++ans;
        }
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2368. 受限条件下可到达节点的数目](https://leetcode.cn/problems/reachable-nodes-with-restrictions){#2368}

{{< tabs "2368" >}}

{{% tab "python" %}}
```python
class Solution:
    def reachableNodes(
        self, n: int, edges: List[List[int]], restricted: List[int]
    ) -> int:
        g = defaultdict(list)
        for a, b in edges:
            g[a].append(b)
            g[b].append(a)
        vis = set(restricted + [0])
        q = deque([0])
        ans = 0
        while q:
            i = q.popleft()
            ans += 1
            for j in g[i]:
                if j not in vis:
                    q.append(j)
                    vis.add(j)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int reachableNodes(int n, int[][] edges, int[] restricted) {
        List<Integer>[] g = new List[n];
        boolean[] vis = new boolean[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (var e : edges) {
            int a = e[0], b = e[1];
            g[a].add(b);
            g[b].add(a);
        }
        for (int v : restricted) {
            vis[v] = true;
        }
        Deque<Integer> q = new ArrayDeque<>();
        q.offer(0);
        int ans = 0;
        for (vis[0] = true; !q.isEmpty(); ++ans) {
            int i = q.pollFirst();
            for (int j : g[i]) {
                if (!vis[j]) {
                    q.offer(j);
                    vis[j] = true;
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
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<int> g[n];
        vector<int> vis(n);
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            g[a].emplace_back(b);
            g[b].emplace_back(a);
        }
        for (int i : restricted) {
            vis[i] = true;
        }
        queue<int> q{{0}};
        int ans = 0;
        for (vis[0] = true; !q.empty(); ++ans) {
            int i = q.front();
            q.pop();
            for (int j : g[i]) {
                if (!vis[j]) {
                    vis[j] = true;
                    q.push(j);
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
func reachableNodes(n int, edges [][]int, restricted []int) (ans int) {
	g := make([][]int, n)
	vis := make([]bool, n)
	for _, e := range edges {
		a, b := e[0], e[1]
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}
	for _, i := range restricted {
		vis[i] = true
	}
	q := []int{0}
	for vis[0] = true; len(q) > 0; ans++ {
		i := q[0]
		q = q[1:]
		for _, j := range g[i] {
			if !vis[j] {
				vis[j] = true
				q = append(q, j)
			}
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function reachableNodes(n: number, edges: number[][], restricted: number[]): number {
    const vis: boolean[] = Array(n).fill(false);
    const g: number[][] = Array.from({ length: n }, () => []);
    for (const [a, b] of edges) {
        g[a].push(b);
        g[b].push(a);
    }
    for (const i of restricted) {
        vis[i] = true;
    }
    const q: number[] = [0];
    let ans = 0;
    for (vis[0] = true; q.length; ++ans) {
        const i = q.pop()!;
        for (const j of g[i]) {
            if (!vis[j]) {
                vis[j] = true;
                q.push(j);
            }
        }
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

<p>现有一棵由 <code>n</code> 个节点组成的无向树，节点编号从 <code>0</code> 到 <code>n - 1</code> ，共有 <code>n - 1</code> 条边。</p>

<p>给你一个二维整数数组 <code>edges</code> ，长度为 <code>n - 1</code> ，其中 <code>edges[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> 表示树中节点 <code>a<sub>i</sub></code> 和 <code>b<sub>i</sub></code> 之间存在一条边。另给你一个整数数组 <code>restricted</code> 表示 <strong>受限</strong> 节点。</p>

<p>在不访问受限节点的前提下，返回你可以从节点<em> </em><code>0</code><em> </em>到达的 <strong>最多</strong> 节点数目<em>。</em></p>

<p>注意，节点 <code>0</code> <strong>不</strong> 会标记为受限节点。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2300-2399/2368.Reachable%20Nodes%20With%20Restrictions/images/ex1drawio.png" style="width: 402px; height: 322px;">
<pre><strong>输入：</strong>n = 7, edges = [[0,1],[1,2],[3,1],[4,0],[0,5],[5,6]], restricted = [4,5]
<strong>输出：</strong>4
<strong>解释：</strong>上图所示正是这棵树。
在不访问受限节点的前提下，只有节点 [0,1,2,3] 可以从节点 0 到达。</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2300-2399/2368.Reachable%20Nodes%20With%20Restrictions/images/ex2drawio.png" style="width: 412px; height: 312px;">
<pre><strong>输入：</strong>n = 7, edges = [[0,1],[0,2],[0,5],[0,4],[3,2],[6,5]], restricted = [4,2,1]
<strong>输出：</strong>3
<strong>解释：</strong>上图所示正是这棵树。
在不访问受限节点的前提下，只有节点 [0,5,6] 可以从节点 0 到达。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>edges.length == n - 1</code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt; n</code></li>
	<li><code>a<sub>i</sub> != b<sub>i</sub></code></li>
	<li><code>edges</code> 表示一棵有效的树</li>
	<li><code>1 &lt;= restricted.length &lt; n</code></li>
	<li><code>1 &lt;= restricted[i] &lt; n</code></li>
	<li><code>restricted</code> 中的所有值 <strong>互不相同</strong></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS

我们首先根据给定的边构建一个邻接表 $g$，其中 $g[i]$ 表示与节点 $i$ 相邻的节点列表。然后我们定义一个哈希表 $vis$，用于记录受限节点或者已经访问过的节点，初始时将受限节点加入到 $vis$ 中。

接下来我们定义一个深度优先搜索函数 $dfs(i)$，表示从节点 $i$ 出发，可以到达的节点数。在 $dfs(i)$ 函数中，我们首先将节点 $i$ 加入到 $vis$ 中，然后遍历节点 $i$ 的相邻节点 $j$，如果 $j$ 不在 $vis$ 中，我们递归调用 $dfs(j)$，并将返回值加到结果中。

最后我们返回 $dfs(0)$ 即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为节点数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def reachableNodes(
        self, n: int, edges: List[List[int]], restricted: List[int]
    ) -> int:
        def dfs(i: int) -> int:
            vis.add(i)
            return 1 + sum(j not in vis and dfs(j) for j in g[i])

        g = defaultdict(list)
        for a, b in edges:
            g[a].append(b)
            g[b].append(a)
        vis = set(restricted)
        return dfs(0)
```

#### Java

```java
class Solution {
    private List<Integer>[] g;
    private boolean[] vis;

    public int reachableNodes(int n, int[][] edges, int[] restricted) {
        g = new List[n];
        vis = new boolean[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (var e : edges) {
            int a = e[0], b = e[1];
            g[a].add(b);
            g[b].add(a);
        }
        for (int i : restricted) {
            vis[i] = true;
        }
        return dfs(0);
    }

    private int dfs(int i) {
        vis[i] = true;
        int ans = 1;
        for (int j : g[i]) {
            if (!vis[j]) {
                ans += dfs(j);
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
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<int> g[n];
        vector<int> vis(n);
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            g[a].emplace_back(b);
            g[b].emplace_back(a);
        }
        for (int i : restricted) {
            vis[i] = true;
        }
        function<int(int)> dfs = [&](int i) {
            vis[i] = true;
            int ans = 1;
            for (int j : g[i]) {
                if (!vis[j]) {
                    ans += dfs(j);
                }
            }
            return ans;
        };
        return dfs(0);
    }
};
```

#### Go

```go
func reachableNodes(n int, edges [][]int, restricted []int) int {
	g := make([][]int, n)
	for _, e := range edges {
		a, b := e[0], e[1]
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}
	vis := make([]bool, n)
	for _, v := range restricted {
		vis[v] = true
	}
	ans := 0
	var dfs func(u int)
	dfs = func(u int) {
		if vis[u] {
			return
		}
		vis[u] = true
		ans++
		for _, v := range g[u] {
			dfs(v)
		}
	}
	dfs(0)
	return ans
}
```

#### TypeScript

```ts
function reachableNodes(n: number, edges: number[][], restricted: number[]): number {
    const vis: boolean[] = Array(n).fill(false);
    const g: number[][] = Array.from({ length: n }, () => []);
    for (const [a, b] of edges) {
        g[a].push(b);
        g[b].push(a);
    }
    for (const i of restricted) {
        vis[i] = true;
    }
    const dfs = (i: number): number => {
        vis[i] = true;
        let ans = 1;
        for (const j of g[i]) {
            if (!vis[j]) {
                ans += dfs(j);
            }
        }
        return ans;
    };
    return dfs(0);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：BFS

与方法一类似，我们首先根据给定的边构建一个邻接表 $g$，然后定义一个哈希表 $vis$，用于记录受限节点或者已经访问过的节点，初始时将受限节点加入到 $vis$ 中。

接下来我们使用广度优先搜索遍历整个图，统计可以到达的节点数。我们定义一个队列 $q$，初始时将节点 $0$ 加入到 $q$ 中，并且将节点 $0$ 加入到 $vis$ 中。然后我们不断从 $q$ 中取出节点 $i$，累加答案，并将节点 $i$ 的相邻节点中未访问过的节点加入到 $q$ 中，并将这些节点加入到 $vis$ 中。

遍历结束后，返回答案即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为节点数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def reachableNodes(
        self, n: int, edges: List[List[int]], restricted: List[int]
    ) -> int:
        g = defaultdict(list)
        for a, b in edges:
            g[a].append(b)
            g[b].append(a)
        vis = set(restricted + [0])
        q = deque([0])
        ans = 0
        while q:
            i = q.popleft()
            ans += 1
            for j in g[i]:
                if j not in vis:
                    q.append(j)
                    vis.add(j)
        return ans
```

#### Java

```java
class Solution {
    public int reachableNodes(int n, int[][] edges, int[] restricted) {
        List<Integer>[] g = new List[n];
        boolean[] vis = new boolean[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (var e : edges) {
            int a = e[0], b = e[1];
            g[a].add(b);
            g[b].add(a);
        }
        for (int v : restricted) {
            vis[v] = true;
        }
        Deque<Integer> q = new ArrayDeque<>();
        q.offer(0);
        int ans = 0;
        for (vis[0] = true; !q.isEmpty(); ++ans) {
            int i = q.pollFirst();
            for (int j : g[i]) {
                if (!vis[j]) {
                    q.offer(j);
                    vis[j] = true;
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
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<int> g[n];
        vector<int> vis(n);
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            g[a].emplace_back(b);
            g[b].emplace_back(a);
        }
        for (int i : restricted) {
            vis[i] = true;
        }
        queue<int> q{{0}};
        int ans = 0;
        for (vis[0] = true; !q.empty(); ++ans) {
            int i = q.front();
            q.pop();
            for (int j : g[i]) {
                if (!vis[j]) {
                    vis[j] = true;
                    q.push(j);
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func reachableNodes(n int, edges [][]int, restricted []int) (ans int) {
	g := make([][]int, n)
	vis := make([]bool, n)
	for _, e := range edges {
		a, b := e[0], e[1]
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}
	for _, i := range restricted {
		vis[i] = true
	}
	q := []int{0}
	for vis[0] = true; len(q) > 0; ans++ {
		i := q[0]
		q = q[1:]
		for _, j := range g[i] {
			if !vis[j] {
				vis[j] = true
				q = append(q, j)
			}
		}
	}
	return
}
```

#### TypeScript

```ts
function reachableNodes(n: number, edges: number[][], restricted: number[]): number {
    const vis: boolean[] = Array(n).fill(false);
    const g: number[][] = Array.from({ length: n }, () => []);
    for (const [a, b] of edges) {
        g[a].push(b);
        g[b].push(a);
    }
    for (const i of restricted) {
        vis[i] = true;
    }
    const q: number[] = [0];
    let ans = 0;
    for (vis[0] = true; q.length; ++ans) {
        const i = q.pop()!;
        for (const j of g[i]) {
            if (!vis[j]) {
                vis[j] = true;
                q.push(j);
            }
        }
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2369. 检查数组是否存在有效划分](https://leetcode.cn/problems/check-if-there-is-a-valid-partition-for-the-array){#2369}

{{< tabs "2369" >}}

{{% tab "python" %}}
```python
class Solution:
    def validPartition(self, nums: List[int]) -> bool:
        n = len(nums)
        f = [True] + [False] * n
        for i, x in enumerate(nums, 1):
            a = i - 2 >= 0 and nums[i - 2] == x
            b = i - 3 >= 0 and nums[i - 3] == nums[i - 2] == x
            c = i - 3 >= 0 and x - nums[i - 2] == 1 and nums[i - 2] - nums[i - 3] == 1
            f[i] = (a and f[i - 2]) or ((b or c) and f[i - 3])
        return f[n]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean validPartition(int[] nums) {
        int n = nums.length;
        boolean[] f = new boolean[n + 1];
        f[0] = true;
        for (int i = 1; i <= n; ++i) {
            boolean a = i - 2 >= 0 && nums[i - 1] == nums[i - 2];
            boolean b = i - 3 >= 0 && nums[i - 1] == nums[i - 2] && nums[i - 2] == nums[i - 3];
            boolean c
                = i - 3 >= 0 && nums[i - 1] - nums[i - 2] == 1 && nums[i - 2] - nums[i - 3] == 1;
            f[i] = (a && f[i - 2]) || ((b || c) && f[i - 3]);
        }
        return f[n];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<bool> f(n + 1);
        f[0] = true;
        for (int i = 1; i <= n; ++i) {
            bool a = i - 2 >= 0 && nums[i - 1] == nums[i - 2];
            bool b = i - 3 >= 0 && nums[i - 1] == nums[i - 2] && nums[i - 2] == nums[i - 3];
            bool c = i - 3 >= 0 && nums[i - 1] - nums[i - 2] == 1 && nums[i - 2] - nums[i - 3] == 1;
            f[i] = (a && f[i - 2]) || ((b || c) && f[i - 3]);
        }
        return f[n];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func validPartition(nums []int) bool {
	n := len(nums)
	f := make([]bool, n+1)
	f[0] = true
	for i := 1; i <= n; i++ {
		x := nums[i-1]
		a := i-2 >= 0 && nums[i-2] == x
		b := i-3 >= 0 && nums[i-3] == nums[i-2] && nums[i-2] == x
		c := i-3 >= 0 && x-nums[i-2] == 1 && nums[i-2]-nums[i-3] == 1
		f[i] = (a && f[i-2]) || ((b || c) && f[i-3])
	}
	return f[n]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function validPartition(nums: number[]): boolean {
    const n = nums.length;
    const f: boolean[] = Array(n + 1).fill(false);
    f[0] = true;
    for (let i = 1; i <= n; ++i) {
        const a = i - 2 >= 0 && nums[i - 1] === nums[i - 2];
        const b = i - 3 >= 0 && nums[i - 1] === nums[i - 2] && nums[i - 2] === nums[i - 3];
        const c = i - 3 >= 0 && nums[i - 1] - nums[i - 2] === 1 && nums[i - 2] - nums[i - 3] === 1;
        f[i] = (a && f[i - 2]) || ((b || c) && f[i - 3]);
    }
    return f[n];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong> 开始的整数数组 <code>nums</code> ，你必须将数组划分为一个或多个 <strong>连续</strong> 子数组。</p>

<p>如果获得的这些子数组中每个都能满足下述条件<strong> 之一</strong> ，则可以称其为数组的一种 <strong>有效</strong> 划分：</p>

<ol>
	<li>子数组 <strong>恰</strong> 由 <code>2</code> 个相等元素组成，例如，子数组 <code>[2,2]</code> 。</li>
	<li>子数组 <strong>恰</strong> 由 <code>3</code> 个相等元素组成，例如，子数组 <code>[4,4,4]</code> 。</li>
	<li>子数组 <strong>恰</strong> 由 <code>3</code> 个连续递增元素组成，并且相邻元素之间的差值为 <code>1</code> 。例如，子数组 <code>[3,4,5]</code> ，但是子数组 <code>[1,3,5]</code> 不符合要求。</li>
</ol>

<p>如果数组 <strong>至少</strong> 存在一种有效划分，返回 <code>true</code><em> </em>，否则，返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [4,4,4,5,6]
<strong>输出：</strong>true
<strong>解释：</strong>数组可以划分成子数组 [4,4] 和 [4,5,6] 。
这是一种有效划分，所以返回 true 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,1,1,2]
<strong>输出：</strong>false
<strong>解释：</strong>该数组不存在有效划分。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

我们设计一个函数 $dfs(i)$，表示从下标 $i$ 开始是否存在一种有效划分。那么答案就是 $dfs(0)$。

函数 $dfs(i)$ 的执行过程如下：

-   如果 $i \ge n$，返回 $true$。
-   如果 $i$ 和 $i+1$ 下标的元素相等，那么可以选择将 $i$ 和 $i+1$ 作为一个子数组，递归调用 $dfs(i+2)$。
-   如果 $i$, $i+1$ 和 $i+2$ 下标的元素相等，那么可以选择将 $i$, $i+1$ 和 $i+2$ 作为一个子数组，递归调用 $dfs(i+3)$。
-   如果 $i$, $i+1$ 和 $i+2$ 下标的元素依次递增 $1$，那么可以选择将 $i$, $i+1$ 和 $i+2$ 作为一个子数组，递归调用 $dfs(i+3)$。
-   如果上述情况都不满足，返回 $false$，否则返回 $true$。

即：

$$
dfs(i) = \textit{OR}
\begin{cases}
true,&i \ge n\\
dfs(i+2),&i+1 < n\ \textit{and}\ \textit{nums}[i] = \textit{nums}[i+1]\\
dfs(i+3),&i+2 < n\ \textit{and}\ \textit{nums}[i] = \textit{nums}[i+1] = \textit{nums}[i+2]\\
dfs(i+3),&i+2 < n\ \textit{and}\ \textit{nums}[i+1] - \textit{nums}[i] = 1\ \textit{and}\ \textit{nums}[i+2] - \textit{nums}[i+1] = 1
\end{cases}
$$

为了避免重复计算，我们使用记忆化搜索的方法。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def validPartition(self, nums: List[int]) -> bool:
        @cache
        def dfs(i: int) -> bool:
            if i >= n:
                return True
            a = i + 1 < n and nums[i] == nums[i + 1]
            b = i + 2 < n and nums[i] == nums[i + 1] == nums[i + 2]
            c = (
                i + 2 < n
                and nums[i + 1] - nums[i] == 1
                and nums[i + 2] - nums[i + 1] == 1
            )
            return (a and dfs(i + 2)) or ((b or c) and dfs(i + 3))

        n = len(nums)
        return dfs(0)
```

#### Java

```java
class Solution {
    private int n;
    private int[] nums;
    private Boolean[] f;

    public boolean validPartition(int[] nums) {
        n = nums.length;
        this.nums = nums;
        f = new Boolean[n];
        return dfs(0);
    }

    private boolean dfs(int i) {
        if (i >= n) {
            return true;
        }
        if (f[i] != null) {
            return f[i];
        }
        boolean a = i + 1 < n && nums[i] == nums[i + 1];
        boolean b = i + 2 < n && nums[i] == nums[i + 1] && nums[i + 1] == nums[i + 2];
        boolean c = i + 2 < n && nums[i + 1] - nums[i] == 1 && nums[i + 2] - nums[i + 1] == 1;
        return f[i] = ((a && dfs(i + 2)) || ((b || c) && dfs(i + 3)));
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool validPartition(vector<int>& nums) {
        n = nums.size();
        this->nums = nums;
        f.assign(n, -1);
        return dfs(0);
    }

private:
    int n;
    vector<int> f;
    vector<int> nums;

    bool dfs(int i) {
        if (i >= n) {
            return true;
        }
        if (f[i] != -1) {
            return f[i] == 1;
        }
        bool a = i + 1 < n && nums[i] == nums[i + 1];
        bool b = i + 2 < n && nums[i] == nums[i + 1] && nums[i + 1] == nums[i + 2];
        bool c = i + 2 < n && nums[i + 1] - nums[i] == 1 && nums[i + 2] - nums[i + 1] == 1;
        f[i] = ((a && dfs(i + 2)) || ((b || c) && dfs(i + 3))) ? 1 : 0;
        return f[i] == 1;
    }
};
```

#### Go

```go
func validPartition(nums []int) bool {
	n := len(nums)
	f := make([]int, n)
	for i := range f {
		f[i] = -1
	}
	var dfs func(int) bool
	dfs = func(i int) bool {
		if i == n {
			return true
		}
		if f[i] != -1 {
			return f[i] == 1
		}
		a := i+1 < n && nums[i] == nums[i+1]
		b := i+2 < n && nums[i] == nums[i+1] && nums[i+1] == nums[i+2]
		c := i+2 < n && nums[i+1]-nums[i] == 1 && nums[i+2]-nums[i+1] == 1
		f[i] = 0
		if a && dfs(i+2) || b && dfs(i+3) || c && dfs(i+3) {
			f[i] = 1
		}
		return f[i] == 1
	}
	return dfs(0)
}
```

#### TypeScript

```ts
function validPartition(nums: number[]): boolean {
    const n = nums.length;
    const f: number[] = Array(n).fill(-1);
    const dfs = (i: number): boolean => {
        if (i >= n) {
            return true;
        }
        if (f[i] !== -1) {
            return f[i] === 1;
        }
        const a = i + 1 < n && nums[i] == nums[i + 1];
        const b = i + 2 < n && nums[i] == nums[i + 1] && nums[i + 1] == nums[i + 2];
        const c = i + 2 < n && nums[i + 1] - nums[i] == 1 && nums[i + 2] - nums[i + 1] == 1;
        f[i] = (a && dfs(i + 2)) || ((b || c) && dfs(i + 3)) ? 1 : 0;
        return f[i] == 1;
    };
    return dfs(0);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：动态规划

我们可以将方法一中的记忆化搜索转换为动态规划。

设 $f[i]$ 表示数组的前 $i$ 个元素是否存在一种有效划分，初始时 $f[0] = true$，答案就是 $f[n]$。

状态转移方程如下：

$$
f[i] = \textit{OR}
\begin{cases}
true,&i = 0\\
f[i-2],&i-2 \ge 0\ \textit{and}\ \textit{nums}[i-1] = \textit{nums}[i-2]\\
f[i-3],&i-3 \ge 0\ \textit{and}\ \textit{nums}[i-1] = \textit{nums}[i-2] = \textit{nums}[i-3]\\
f[i-3],&i-3 \ge 0\ \textit{and}\ \textit{nums}[i-1] - \textit{nums}[i-2] = 1\ \textit{and}\ \textit{nums}[i-2] - \textit{nums}[i-3] = 1
\end{cases}
$$

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def validPartition(self, nums: List[int]) -> bool:
        n = len(nums)
        f = [True] + [False] * n
        for i, x in enumerate(nums, 1):
            a = i - 2 >= 0 and nums[i - 2] == x
            b = i - 3 >= 0 and nums[i - 3] == nums[i - 2] == x
            c = i - 3 >= 0 and x - nums[i - 2] == 1 and nums[i - 2] - nums[i - 3] == 1
            f[i] = (a and f[i - 2]) or ((b or c) and f[i - 3])
        return f[n]
```

#### Java

```java
class Solution {
    public boolean validPartition(int[] nums) {
        int n = nums.length;
        boolean[] f = new boolean[n + 1];
        f[0] = true;
        for (int i = 1; i <= n; ++i) {
            boolean a = i - 2 >= 0 && nums[i - 1] == nums[i - 2];
            boolean b = i - 3 >= 0 && nums[i - 1] == nums[i - 2] && nums[i - 2] == nums[i - 3];
            boolean c
                = i - 3 >= 0 && nums[i - 1] - nums[i - 2] == 1 && nums[i - 2] - nums[i - 3] == 1;
            f[i] = (a && f[i - 2]) || ((b || c) && f[i - 3]);
        }
        return f[n];
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<bool> f(n + 1);
        f[0] = true;
        for (int i = 1; i <= n; ++i) {
            bool a = i - 2 >= 0 && nums[i - 1] == nums[i - 2];
            bool b = i - 3 >= 0 && nums[i - 1] == nums[i - 2] && nums[i - 2] == nums[i - 3];
            bool c = i - 3 >= 0 && nums[i - 1] - nums[i - 2] == 1 && nums[i - 2] - nums[i - 3] == 1;
            f[i] = (a && f[i - 2]) || ((b || c) && f[i - 3]);
        }
        return f[n];
    }
};
```

#### Go

```go
func validPartition(nums []int) bool {
	n := len(nums)
	f := make([]bool, n+1)
	f[0] = true
	for i := 1; i <= n; i++ {
		x := nums[i-1]
		a := i-2 >= 0 && nums[i-2] == x
		b := i-3 >= 0 && nums[i-3] == nums[i-2] && nums[i-2] == x
		c := i-3 >= 0 && x-nums[i-2] == 1 && nums[i-2]-nums[i-3] == 1
		f[i] = (a && f[i-2]) || ((b || c) && f[i-3])
	}
	return f[n]
}
```

#### TypeScript

```ts
function validPartition(nums: number[]): boolean {
    const n = nums.length;
    const f: boolean[] = Array(n + 1).fill(false);
    f[0] = true;
    for (let i = 1; i <= n; ++i) {
        const a = i - 2 >= 0 && nums[i - 1] === nums[i - 2];
        const b = i - 3 >= 0 && nums[i - 1] === nums[i - 2] && nums[i - 2] === nums[i - 3];
        const c = i - 3 >= 0 && nums[i - 1] - nums[i - 2] === 1 && nums[i - 2] - nums[i - 3] === 1;
        f[i] = (a && f[i - 2]) || ((b || c) && f[i - 3]);
    }
    return f[n];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
