---
title: "2290_到达角落需要移除障碍物的最小数目"
date: 2025-10-08T18:39:07+08:00
weight: 10
tags: [动态规划, 单调栈, 双向链表, 哈希表, 图, 堆（优先队列）, 字符串, 广度优先搜索, 排序, 数据库, 数组, 最短路, 栈, 模拟, 矩阵, 设计, 贪心, 链表]
---

{{< markmap >}}
### [2290_到达角落需要移除障碍物的最小数目](#2290)
#### [广度优先搜索](#2290)
#### [图](#2290)
#### [数组](#2290)
#### [矩阵](#2290)
#### [最短路](#2290)
#### [堆（优先队列）](#2290)
### [2291_最大股票收益 🔒](#2291)
#### [数组](#2291)
#### [动态规划](#2291)
### [2292_连续两年有 3 个及以上订单的产品 🔒](#2292)
#### [数据库](#2292)
### [2293_极大极小游戏](#2293)
#### [数组](#2293)
#### [模拟](#2293)
### [2294_划分数组使最大差为 K](#2294)
#### [贪心](#2294)
#### [数组](#2294)
#### [排序](#2294)
### [2295_替换数组中的元素](#2295)
#### [数组](#2295)
#### [哈希表](#2295)
#### [模拟](#2295)
### [2296_设计一个文本编辑器](#2296)
#### [栈](#2296)
#### [设计](#2296)
#### [链表](#2296)
#### [字符串](#2296)
#### [双向链表](#2296)
#### [模拟](#2296)
### [2297_跳跃游戏 VIII 🔒](#2297)
#### [栈](#2297)
#### [图](#2297)
#### [数组](#2297)
#### [动态规划](#2297)
#### [最短路](#2297)
#### [单调栈](#2297)
### [2298_周末任务计数 🔒](#2298)
#### [数据库](#2298)
### [2299_强密码检验器 II](#2299)
#### [字符串](#2299)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2290_到达角落需要移除障碍物的最小数目
___
#### 广度优先搜索
___
#### 图
___
#### 数组
___
#### 矩阵
___
#### 最短路
___
#### 堆（优先队列）
---
### 2291_最大股票收益 🔒
___
#### 数组
___
#### 动态规划
---
### 2292_连续两年有 3 个及以上订单的产品 🔒
___
#### 数据库
---
### 2293_极大极小游戏
___
#### 数组
___
#### 模拟
---
### 2294_划分数组使最大差为 K
___
#### 贪心
___
#### 数组
___
#### 排序
---
### 2295_替换数组中的元素
___
#### 数组
___
#### 哈希表
___
#### 模拟
---
### 2296_设计一个文本编辑器
___
#### 栈
___
#### 设计
___
#### 链表
___
#### 字符串
___
#### 双向链表
___
#### 模拟
---
### 2297_跳跃游戏 VIII 🔒
___
#### 栈
___
#### 图
___
#### 数组
___
#### 动态规划
___
#### 最短路
___
#### 单调栈
---
### 2298_周末任务计数 🔒
___
#### 数据库
---
### 2299_强密码检验器 II
___
#### 字符串
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 动态规划 | 单调栈 | 双向链表 |
| 哈希表 | 图 | 堆（优先队列） |
| 字符串 | 广度优先搜索 | 排序 |
| 数据库 | 数组 | 最短路 |
| 栈 | 模拟 | 矩阵 |
| 设计 | 贪心 | 链表 |

# [2290. 到达角落需要移除障碍物的最小数目](https://leetcode.cn/problems/minimum-obstacle-removal-to-reach-corner){#2290}

{{< tabs "2290" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumObstacles(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        q = deque([(0, 0, 0)])
        vis = set()
        dirs = (-1, 0, 1, 0, -1)
        while 1:
            i, j, k = q.popleft()
            if i == m - 1 and j == n - 1:
                return k
            if (i, j) in vis:
                continue
            vis.add((i, j))
            for a, b in pairwise(dirs):
                x, y = i + a, j + b
                if 0 <= x < m and 0 <= y < n:
                    if grid[x][y] == 0:
                        q.appendleft((x, y, k))
                    else:
                        q.append((x, y, k + 1))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumObstacles(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        Deque<int[]> q = new ArrayDeque<>();
        q.offer(new int[] {0, 0, 0});
        int[] dirs = {-1, 0, 1, 0, -1};
        boolean[][] vis = new boolean[m][n];
        while (true) {
            var p = q.poll();
            int i = p[0], j = p[1], k = p[2];
            if (i == m - 1 && j == n - 1) {
                return k;
            }
            if (vis[i][j]) {
                continue;
            }
            vis[i][j] = true;
            for (int h = 0; h < 4; ++h) {
                int x = i + dirs[h], y = j + dirs[h + 1];
                if (x >= 0 && x < m && y >= 0 && y < n) {
                    if (grid[x][y] == 0) {
                        q.offerFirst(new int[] {x, y, k});
                    } else {
                        q.offerLast(new int[] {x, y, k + 1});
                    }
                }
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
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        deque<tuple<int, int, int>> q{{0, 0, 0}};
        bool vis[m][n];
        memset(vis, 0, sizeof vis);
        int dirs[5] = {-1, 0, 1, 0, -1};
        while (1) {
            auto [i, j, k] = q.front();
            q.pop_front();
            if (i == m - 1 && j == n - 1) {
                return k;
            }
            if (vis[i][j]) {
                continue;
            }
            vis[i][j] = true;
            for (int h = 0; h < 4; ++h) {
                int x = i + dirs[h], y = j + dirs[h + 1];
                if (x >= 0 && x < m && y >= 0 && y < n) {
                    if (grid[x][y] == 0) {
                        q.push_front({x, y, k});
                    } else {
                        q.push_back({x, y, k + 1});
                    }
                }
            }
        }
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumObstacles(grid [][]int) int {
	m, n := len(grid), len(grid[0])
	q := doublylinkedlist.New()
	type tuple struct{ i, j, k int }
	q.Add(tuple{0, 0, 0})
	vis := make([][]bool, m)
	for i := range vis {
		vis[i] = make([]bool, n)
	}
	dirs := [5]int{-1, 0, 1, 0, -1}
	for {
		v, _ := q.Get(0)
		p := v.(tuple)
		q.Remove(0)
		i, j, k := p.i, p.j, p.k
		if i == m-1 && j == n-1 {
			return k
		}
		if vis[i][j] {
			continue
		}
		vis[i][j] = true
		for h := 0; h < 4; h++ {
			x, y := i+dirs[h], j+dirs[h+1]
			if x >= 0 && x < m && y >= 0 && y < n {
				if grid[x][y] == 0 {
					q.Insert(0, tuple{x, y, k})
				} else {
					q.Add(tuple{x, y, k + 1})
				}
			}
		}
	}
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumObstacles(grid: number[][]): number {
    const m = grid.length,
        n = grid[0].length;
    const dirs = [
        [0, 1],
        [0, -1],
        [1, 0],
        [-1, 0],
    ];
    let ans = Array.from({ length: m }, v => new Array(n).fill(Infinity));
    ans[0][0] = 0;
    let deque = [[0, 0]];
    while (deque.length) {
        let [x, y] = deque.shift();
        for (let [dx, dy] of dirs) {
            let [i, j] = [x + dx, y + dy];
            if (i < 0 || i > m - 1 || j < 0 || j > n - 1) continue;
            const cost = grid[i][j];
            if (ans[x][y] + cost >= ans[i][j]) continue;
            ans[i][j] = ans[x][y] + cost;
            deque.push([i, j]);
        }
    }
    return ans[m - 1][n - 1];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong> 开始的二维整数数组 <code>grid</code> ，数组大小为 <code>m x n</code> 。每个单元格都是两个值之一：</p>

<ul>
	<li><code>0</code> 表示一个 <strong>空</strong> 单元格，</li>
	<li><code>1</code> 表示一个可以移除的 <strong>障碍物</strong> 。</li>
</ul>

<p>你可以向上、下、左、右移动，从一个空单元格移动到另一个空单元格。</p>

<p>现在你需要从左上角&nbsp;<code>(0, 0)</code> 移动到右下角 <code>(m - 1, n - 1)</code> ，返回需要移除的障碍物的 <strong>最小</strong> 数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2200-2299/2290.Minimum%20Obstacle%20Removal%20to%20Reach%20Corner/images/example1drawio-1.png" style="width: 605px; height: 246px;" /></p>

<pre>
<strong>输入：</strong>grid = [[0,1,1],[1,1,0],[1,1,0]]
<strong>输出：</strong>2
<strong>解释：</strong>可以移除位于 (0, 1) 和 (0, 2) 的障碍物来创建从 (0, 0) 到 (2, 2) 的路径。
可以证明我们至少需要移除两个障碍物，所以返回 2 。
注意，可能存在其他方式来移除 2 个障碍物，创建出可行的路径。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2200-2299/2290.Minimum%20Obstacle%20Removal%20to%20Reach%20Corner/images/example1drawio.png" style="width: 405px; height: 246px;" /></p>

<pre>
<strong>输入：</strong>grid = [[0,1,0,0,0],[0,1,0,1,0],[0,0,0,1,0]]
<strong>输出：</strong>0
<strong>解释：</strong>不移除任何障碍物就能从 (0, 0) 到 (2, 4) ，所以返回 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 10<sup>5</sup></code></li>
	<li><code>2 &lt;= m * n &lt;= 10<sup>5</sup></code></li>
	<li><code>grid[i][j]</code> 为 <code>0</code> <strong>或</strong> <code>1</code></li>
	<li><code>grid[0][0] == grid[m - 1][n - 1] == 0</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双端队列 BFS

本题实际上也是最短路模型，只不过求解的是移除障碍物的最小数目。

在一个边权只有 $0$, $1$ 的无向图中搜索最短路径可以使用双端队列进行 $BFS$。其原理是当前可以扩展到的点的权重为 $0$ 时，将其加入队首；权重为 $1$ 时，将其加入队尾。

> 如果某条边权值为 $0$，那么新拓展出的节点权值就和当前队首节点权值相同，显然可以作为下一次拓展的起点。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别是网格的行数和列数。

相似题目：

-   [1368. 使网格图至少有一条有效路径的最小代价](https://github.com/doocs/leetcode/blob/main/solution/1300-1399/1368.Minimum%20Cost%20to%20Make%20at%20Least%20One%20Valid%20Path%20in%20a%20Grid/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumObstacles(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        q = deque([(0, 0, 0)])
        vis = set()
        dirs = (-1, 0, 1, 0, -1)
        while 1:
            i, j, k = q.popleft()
            if i == m - 1 and j == n - 1:
                return k
            if (i, j) in vis:
                continue
            vis.add((i, j))
            for a, b in pairwise(dirs):
                x, y = i + a, j + b
                if 0 <= x < m and 0 <= y < n:
                    if grid[x][y] == 0:
                        q.appendleft((x, y, k))
                    else:
                        q.append((x, y, k + 1))
```

#### Java

```java
class Solution {
    public int minimumObstacles(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        Deque<int[]> q = new ArrayDeque<>();
        q.offer(new int[] {0, 0, 0});
        int[] dirs = {-1, 0, 1, 0, -1};
        boolean[][] vis = new boolean[m][n];
        while (true) {
            var p = q.poll();
            int i = p[0], j = p[1], k = p[2];
            if (i == m - 1 && j == n - 1) {
                return k;
            }
            if (vis[i][j]) {
                continue;
            }
            vis[i][j] = true;
            for (int h = 0; h < 4; ++h) {
                int x = i + dirs[h], y = j + dirs[h + 1];
                if (x >= 0 && x < m && y >= 0 && y < n) {
                    if (grid[x][y] == 0) {
                        q.offerFirst(new int[] {x, y, k});
                    } else {
                        q.offerLast(new int[] {x, y, k + 1});
                    }
                }
            }
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        deque<tuple<int, int, int>> q{{0, 0, 0}};
        bool vis[m][n];
        memset(vis, 0, sizeof vis);
        int dirs[5] = {-1, 0, 1, 0, -1};
        while (1) {
            auto [i, j, k] = q.front();
            q.pop_front();
            if (i == m - 1 && j == n - 1) {
                return k;
            }
            if (vis[i][j]) {
                continue;
            }
            vis[i][j] = true;
            for (int h = 0; h < 4; ++h) {
                int x = i + dirs[h], y = j + dirs[h + 1];
                if (x >= 0 && x < m && y >= 0 && y < n) {
                    if (grid[x][y] == 0) {
                        q.push_front({x, y, k});
                    } else {
                        q.push_back({x, y, k + 1});
                    }
                }
            }
        }
    }
};
```

#### Go

```go
func minimumObstacles(grid [][]int) int {
	m, n := len(grid), len(grid[0])
	q := doublylinkedlist.New()
	type tuple struct{ i, j, k int }
	q.Add(tuple{0, 0, 0})
	vis := make([][]bool, m)
	for i := range vis {
		vis[i] = make([]bool, n)
	}
	dirs := [5]int{-1, 0, 1, 0, -1}
	for {
		v, _ := q.Get(0)
		p := v.(tuple)
		q.Remove(0)
		i, j, k := p.i, p.j, p.k
		if i == m-1 && j == n-1 {
			return k
		}
		if vis[i][j] {
			continue
		}
		vis[i][j] = true
		for h := 0; h < 4; h++ {
			x, y := i+dirs[h], j+dirs[h+1]
			if x >= 0 && x < m && y >= 0 && y < n {
				if grid[x][y] == 0 {
					q.Insert(0, tuple{x, y, k})
				} else {
					q.Add(tuple{x, y, k + 1})
				}
			}
		}
	}
}
```

#### TypeScript

```ts
function minimumObstacles(grid: number[][]): number {
    const m = grid.length,
        n = grid[0].length;
    const dirs = [
        [0, 1],
        [0, -1],
        [1, 0],
        [-1, 0],
    ];
    let ans = Array.from({ length: m }, v => new Array(n).fill(Infinity));
    ans[0][0] = 0;
    let deque = [[0, 0]];
    while (deque.length) {
        let [x, y] = deque.shift();
        for (let [dx, dy] of dirs) {
            let [i, j] = [x + dx, y + dy];
            if (i < 0 || i > m - 1 || j < 0 || j > n - 1) continue;
            const cost = grid[i][j];
            if (ans[x][y] + cost >= ans[i][j]) continue;
            ans[i][j] = ans[x][y] + cost;
            deque.push([i, j]);
        }
    }
    return ans[m - 1][n - 1];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2291. 最大股票收益 🔒](https://leetcode.cn/problems/maximum-profit-from-trading-stocks){#2291}

{{< tabs "2291" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumProfit(self, present: List[int], future: List[int], budget: int) -> int:
        f = [0] * (budget + 1)
        for a, b in zip(present, future):
            for j in range(budget, a - 1, -1):
                f[j] = max(f[j], f[j - a] + b - a)
        return f[-1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maximumProfit(int[] present, int[] future, int budget) {
        int n = present.length;
        int[] f = new int[budget + 1];
        for (int i = 0; i < n; ++i) {
            int a = present[i], b = future[i];
            for (int j = budget; j >= a; --j) {
                f[j] = Math.max(f[j], f[j - a] + b - a);
            }
        }
        return f[budget];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maximumProfit(vector<int>& present, vector<int>& future, int budget) {
        int n = present.size();
        int f[budget + 1];
        memset(f, 0, sizeof f);
        for (int i = 0; i < n; ++i) {
            int a = present[i], b = future[i];
            for (int j = budget; j >= a; --j) {
                f[j] = max(f[j], f[j - a] + b - a);
            }
        }
        return f[budget];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumProfit(present []int, future []int, budget int) int {
	f := make([]int, budget+1)
	for i, a := range present {
		for j := budget; j >= a; j-- {
			f[j] = max(f[j], f[j-a]+future[i]-a)
		}
	}
	return f[budget]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumProfit(present: number[], future: number[], budget: number): number {
    const f = new Array(budget + 1).fill(0);
    for (let i = 0; i < present.length; ++i) {
        const [a, b] = [present[i], future[i]];
        for (let j = budget; j >= a; --j) {
            f[j] = Math.max(f[j], f[j - a] + b - a);
        }
    }
    return f[budget];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个下标从 <strong>0</strong>&nbsp;开始的数组 <code>present</code> 和 <code>future</code> ，<code>present[i]</code> 和 <code>future[i]</code> 分别代表第 <code>i</code> 支股票现在和将来的价格。每支股票你最多购买 <strong>一次</strong> ，你的预算为 <code>budget</code> 。</p>

<p>求最大的收益。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>present = [5,4,6,2,3], future = [8,5,4,3,5], budget = 10
<strong>输出：</strong>6
<strong>解释：</strong>你可以选择购买第 0,3,4 支股票获得最大收益：6 。总开销为：5 + 2 + 3 = 10 , 总收益是: 8 + 3 + 5 - 10 = 6 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>present = [2,2,5], future = [3,4,10], budget = 6
<strong>输出：</strong>5
<strong>解释：</strong>你可以选择购买第 2 支股票获得最大收益：5 。总开销为：5 , 总收益是: 10 - 5 = 5 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>present = [3,3,12], future = [0,3,15], budget = 10
<strong>输出：</strong>0
<strong>解释：</strong>你无法购买唯一一支正收益股票 2 ，因此你的收益是 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == present.length == future.length</code></li>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
	<li><code>0 &lt;= present[i], future[i] &lt;= 100</code></li>
	<li><code>0 &lt;= budget &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i][j]$ 表示前 $i$ 支股票，预算为 $j$ 时的最大收益。那么答案就是 $f[n][\textit{budget}]$。

对于第 $i$ 支股票，我们有两种选择：

-   不购买，那么 $f[i][j] = f[i - 1][j]$；
-   购买，那么 $f[i][j] = f[i - 1][j - \textit{present}[i]] + \textit{future}[i] - \textit{present}[i]$。

最后返回 $f[n][\textit{budget}]$ 即可。

时间复杂度 $O(n \times \textit{budget})$，空间复杂度 $O(n \times \textit{budget})$。其中 $n$ 为数组长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumProfit(self, present: List[int], future: List[int], budget: int) -> int:
        f = [[0] * (budget + 1) for _ in range(len(present) + 1)]
        for i, w in enumerate(present, 1):
            for j in range(budget + 1):
                f[i][j] = f[i - 1][j]
                if j >= w and future[i - 1] > w:
                    f[i][j] = max(f[i][j], f[i - 1][j - w] + future[i - 1] - w)
        return f[-1][-1]
```

#### Java

```java
class Solution {
    public int maximumProfit(int[] present, int[] future, int budget) {
        int n = present.length;
        int[][] f = new int[n + 1][budget + 1];
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= budget; ++j) {
                f[i][j] = f[i - 1][j];
                if (j >= present[i - 1]) {
                    f[i][j] = Math.max(
                        f[i][j], f[i - 1][j - present[i - 1]] + future[i - 1] - present[i - 1]);
                }
            }
        }
        return f[n][budget];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maximumProfit(vector<int>& present, vector<int>& future, int budget) {
        int n = present.size();
        int f[n + 1][budget + 1];
        memset(f, 0, sizeof f);
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= budget; ++j) {
                f[i][j] = f[i - 1][j];
                if (j >= present[i - 1]) {
                    f[i][j] = max(f[i][j], f[i - 1][j - present[i - 1]] + future[i - 1] - present[i - 1]);
                }
            }
        }
        return f[n][budget];
    }
};
```

#### Go

```go
func maximumProfit(present []int, future []int, budget int) int {
	n := len(present)
	f := make([][]int, n+1)
	for i := range f {
		f[i] = make([]int, budget+1)
	}
	for i := 1; i <= n; i++ {
		for j := 0; j <= budget; j++ {
			f[i][j] = f[i-1][j]
			if j >= present[i-1] {
				f[i][j] = max(f[i][j], f[i-1][j-present[i-1]]+future[i-1]-present[i-1])
			}
		}
	}
	return f[n][budget]
}
```

#### TypeScript

```ts
function maximumProfit(present: number[], future: number[], budget: number): number {
    const f = new Array(budget + 1).fill(0);
    for (let i = 0; i < present.length; ++i) {
        const [a, b] = [present[i], future[i]];
        for (let j = budget; j >= a; --j) {
            f[j] = Math.max(f[j], f[j - a] + b - a);
        }
    }
    return f[budget];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：动态规划（空间优化）

我们可以发现，对于每一行，我们只需要用到上一行的值，因此可以将空间复杂度优化到 $O(\text{budget})$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumProfit(self, present: List[int], future: List[int], budget: int) -> int:
        f = [0] * (budget + 1)
        for a, b in zip(present, future):
            for j in range(budget, a - 1, -1):
                f[j] = max(f[j], f[j - a] + b - a)
        return f[-1]
```

#### Java

```java
class Solution {
    public int maximumProfit(int[] present, int[] future, int budget) {
        int n = present.length;
        int[] f = new int[budget + 1];
        for (int i = 0; i < n; ++i) {
            int a = present[i], b = future[i];
            for (int j = budget; j >= a; --j) {
                f[j] = Math.max(f[j], f[j - a] + b - a);
            }
        }
        return f[budget];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maximumProfit(vector<int>& present, vector<int>& future, int budget) {
        int n = present.size();
        int f[budget + 1];
        memset(f, 0, sizeof f);
        for (int i = 0; i < n; ++i) {
            int a = present[i], b = future[i];
            for (int j = budget; j >= a; --j) {
                f[j] = max(f[j], f[j - a] + b - a);
            }
        }
        return f[budget];
    }
};
```

#### Go

```go
func maximumProfit(present []int, future []int, budget int) int {
	f := make([]int, budget+1)
	for i, a := range present {
		for j := budget; j >= a; j-- {
			f[j] = max(f[j], f[j-a]+future[i]-a)
		}
	}
	return f[budget]
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2292. 连续两年有 3 个及以上订单的产品 🔒](https://leetcode.cn/problems/products-with-three-or-more-orders-in-two-consecutive-years){#2292}

{{< tabs "2292" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    P AS (
        SELECT product_id, YEAR(purchase_date) AS y
        FROM Orders
        GROUP BY 1, 2
        HAVING COUNT(1) >= 3
    )
SELECT DISTINCT p1.product_id
FROM
    P AS p1
    JOIN P AS p2 ON p1.y = p2.y - 1 AND p1.product_id = p2.product_id;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表: <code>Orders</code></p>

<pre>
+---------------+------+
| Column Name   | Type |
+---------------+------+
| order_id      | int  |
| product_id    | int  |
| quantity      | int  |
| purchase_date | date |
+---------------+------+
order_id 包含唯一值。
该表中的每一行都包含订单 ID、购买的产品 ID、数量和购买日期。
</pre>

<p>&nbsp;</p>

<p>编写解决方案，获取连续两年订购三次或三次以上的所有产品的 id。</p>

<p data-group="1-1">以&nbsp;<strong>任意顺序&nbsp;</strong>返回结果表。</p>

<p>结果格式示例如下。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1:</strong></p>

<pre>
<strong>输入:</strong> 
Orders 表:
+----------+------------+----------+---------------+
| order_id | product_id | quantity | purchase_date |
+----------+------------+----------+---------------+
| 1        | 1          | 7        | 2020-03-16    |
| 2        | 1          | 4        | 2020-12-02    |
| 3        | 1          | 7        | 2020-05-10    |
| 4        | 1          | 6        | 2021-12-23    |
| 5        | 1          | 5        | 2021-05-21    |
| 6        | 1          | 6        | 2021-10-11    |
| 7        | 2          | 6        | 2022-10-11    |
+----------+------------+----------+---------------+
<strong>输出:</strong> 
+------------+
| product_id |
+------------+
| 1          |
+------------+
<strong>解释:</strong> 
产品 1 在 2020 年和 2021 年都分别订购了三次。由于连续两年订购了三次，所以我们将其包含在答案中。
产品 2 在 2022 年订购了一次。我们不把它包括在答案中。
</pre>

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
        SELECT product_id, YEAR(purchase_date) AS y, COUNT(1) >= 3 AS mark
        FROM Orders
        GROUP BY 1, 2
    )
SELECT DISTINCT p1.product_id
FROM
    P AS p1
    JOIN P AS p2 ON p1.y = p2.y - 1 AND p1.product_id = p2.product_id
WHERE p1.mark AND p2.mark;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
WITH
    P AS (
        SELECT product_id, YEAR(purchase_date) AS y
        FROM Orders
        GROUP BY 1, 2
        HAVING COUNT(1) >= 3
    )
SELECT DISTINCT p1.product_id
FROM
    P AS p1
    JOIN P AS p2 ON p1.y = p2.y - 1 AND p1.product_id = p2.product_id;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2293. 极大极小游戏](https://leetcode.cn/problems/min-max-game){#2293}

{{< tabs "2293" >}}

{{% tab "python" %}}
```python
class Solution:
    def minMaxGame(self, nums: List[int]) -> int:
        n = len(nums)
        while n > 1:
            n >>= 1
            for i in range(n):
                a, b = nums[i << 1], nums[i << 1 | 1]
                nums[i] = min(a, b) if i % 2 == 0 else max(a, b)
        return nums[0]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minMaxGame(int[] nums) {
        for (int n = nums.length; n > 1;) {
            n >>= 1;
            for (int i = 0; i < n; ++i) {
                int a = nums[i << 1], b = nums[i << 1 | 1];
                nums[i] = i % 2 == 0 ? Math.min(a, b) : Math.max(a, b);
            }
        }
        return nums[0];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        for (int n = nums.size(); n > 1;) {
            n >>= 1;
            for (int i = 0; i < n; ++i) {
                int a = nums[i << 1], b = nums[i << 1 | 1];
                nums[i] = i % 2 == 0 ? min(a, b) : max(a, b);
            }
        }
        return nums[0];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minMaxGame(nums []int) int {
	for n := len(nums); n > 1; {
		n >>= 1
		for i := 0; i < n; i++ {
			a, b := nums[i<<1], nums[i<<1|1]
			if i%2 == 0 {
				nums[i] = min(a, b)
			} else {
				nums[i] = max(a, b)
			}
		}
	}
	return nums[0]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minMaxGame(nums: number[]): number {
    for (let n = nums.length; n > 1; ) {
        n >>= 1;
        for (let i = 0; i < n; ++i) {
            const a = nums[i << 1];
            const b = nums[(i << 1) | 1];
            nums[i] = i % 2 == 0 ? Math.min(a, b) : Math.max(a, b);
        }
    }
    return nums[0];
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn min_max_game(mut nums: Vec<i32>) -> i32 {
        let mut n = nums.len();
        while n != 1 {
            n >>= 1;
            for i in 0..n {
                nums[i] = (if (i & 1) == 1 { i32::max } else { i32::min })(
                    nums[i << 1],
                    nums[(i << 1) | 1],
                );
            }
        }
        nums[0]
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

int minMaxGame(int* nums, int numsSize) {
    while (numsSize != 1) {
        numsSize >>= 1;
        for (int i = 0; i < numsSize; i++) {
            int a = nums[i << 1];
            int b = nums[i << 1 | 1];
            nums[i] = i & 1 ? max(a, b) : min(a, b);
        }
    }
    return nums[0];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong> 开始的整数数组 <code>nums</code> ，其长度是 <code>2</code> 的幂。</p>

<p>对 <code>nums</code> 执行下述算法：</p>

<ol>
	<li>设 <code>n</code> 等于 <code>nums</code> 的长度，如果 <code>n == 1</code> ，<strong>终止</strong> 算法过程。否则，<strong>创建</strong> 一个新的整数数组&nbsp;<code>newNums</code> ，新数组长度为 <code>n / 2</code> ，下标从 <strong>0</strong> 开始。</li>
	<li>对于满足&nbsp;<code>0 &lt;= i &lt; n / 2</code> 的每个 <strong>偶数</strong> 下标 <code>i</code> ，将 <code>newNums[i]</code> <strong>赋值</strong> 为 <code>min(nums[2 * i], nums[2 * i + 1])</code> 。</li>
	<li>对于满足&nbsp;<code>0 &lt;= i &lt; n / 2</code> 的每个 <strong>奇数</strong> 下标 <code>i</code> ，将 <code>newNums[i]</code> <strong>赋值</strong> 为 <code>max(nums[2 * i], nums[2 * i + 1])</code> 。</li>
	<li>用 <code>newNums</code> 替换 <code>nums</code> 。</li>
	<li>从步骤 1 开始 <strong>重复</strong> 整个过程。</li>
</ol>

<p>执行算法后，返回 <code>nums</code> 中剩下的那个数字。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2200-2299/2293.Min%20Max%20Game/images/example1drawio-1.png" style="width: 500px; height: 240px;" /></p>

<pre>
<strong>输入：</strong>nums = [1,3,5,2,4,8,2,2]
<strong>输出：</strong>1
<strong>解释：</strong>重复执行算法会得到下述数组。
第一轮：nums = [1,5,4,2]
第二轮：nums = [1,4]
第三轮：nums = [1]
1 是最后剩下的那个数字，返回 1 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [3]
<strong>输出：</strong>3
<strong>解释：</strong>3 就是最后剩下的数字，返回 3 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1024</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>nums.length</code> 是 <code>2</code> 的幂</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

根据题意，我们可以模拟整个过程，最后剩下的数字即为答案。在实现上，我们不需要额外创建数组，直接在原数组上进行操作即可。

时间复杂度 $O(n)$，其中 $n$ 是数组 $\textit{nums}$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minMaxGame(self, nums: List[int]) -> int:
        n = len(nums)
        while n > 1:
            n >>= 1
            for i in range(n):
                a, b = nums[i << 1], nums[i << 1 | 1]
                nums[i] = min(a, b) if i % 2 == 0 else max(a, b)
        return nums[0]
```

#### Java

```java
class Solution {
    public int minMaxGame(int[] nums) {
        for (int n = nums.length; n > 1;) {
            n >>= 1;
            for (int i = 0; i < n; ++i) {
                int a = nums[i << 1], b = nums[i << 1 | 1];
                nums[i] = i % 2 == 0 ? Math.min(a, b) : Math.max(a, b);
            }
        }
        return nums[0];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        for (int n = nums.size(); n > 1;) {
            n >>= 1;
            for (int i = 0; i < n; ++i) {
                int a = nums[i << 1], b = nums[i << 1 | 1];
                nums[i] = i % 2 == 0 ? min(a, b) : max(a, b);
            }
        }
        return nums[0];
    }
};
```

#### Go

```go
func minMaxGame(nums []int) int {
	for n := len(nums); n > 1; {
		n >>= 1
		for i := 0; i < n; i++ {
			a, b := nums[i<<1], nums[i<<1|1]
			if i%2 == 0 {
				nums[i] = min(a, b)
			} else {
				nums[i] = max(a, b)
			}
		}
	}
	return nums[0]
}
```

#### TypeScript

```ts
function minMaxGame(nums: number[]): number {
    for (let n = nums.length; n > 1; ) {
        n >>= 1;
        for (let i = 0; i < n; ++i) {
            const a = nums[i << 1];
            const b = nums[(i << 1) | 1];
            nums[i] = i % 2 == 0 ? Math.min(a, b) : Math.max(a, b);
        }
    }
    return nums[0];
}
```

#### Rust

```rust
impl Solution {
    pub fn min_max_game(mut nums: Vec<i32>) -> i32 {
        let mut n = nums.len();
        while n != 1 {
            n >>= 1;
            for i in 0..n {
                nums[i] = (if (i & 1) == 1 { i32::max } else { i32::min })(
                    nums[i << 1],
                    nums[(i << 1) | 1],
                );
            }
        }
        nums[0]
    }
}
```

#### C

```c
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

int minMaxGame(int* nums, int numsSize) {
    while (numsSize != 1) {
        numsSize >>= 1;
        for (int i = 0; i < numsSize; i++) {
            int a = nums[i << 1];
            int b = nums[i << 1 | 1];
            nums[i] = i & 1 ? max(a, b) : min(a, b);
        }
    }
    return nums[0];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2294. 划分数组使最大差为 K](https://leetcode.cn/problems/partition-array-such-that-maximum-difference-is-k){#2294}

{{< tabs "2294" >}}

{{% tab "python" %}}
```python
class Solution:
    def partitionArray(self, nums: List[int], k: int) -> int:
        nums.sort()
        ans, a = 1, nums[0]
        for b in nums:
            if b - a > k:
                a = b
                ans += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int partitionArray(int[] nums, int k) {
        Arrays.sort(nums);
        int ans = 1, a = nums[0];
        for (int b : nums) {
            if (b - a > k) {
                a = b;
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
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 1, a = nums[0];
        for (int& b : nums) {
            if (b - a > k) {
                a = b;
                ++ans;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func partitionArray(nums []int, k int) int {
	sort.Ints(nums)
	ans, a := 1, nums[0]
	for _, b := range nums {
		if b-a > k {
			a = b
			ans++
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function partitionArray(nums: number[], k: number): number {
    nums.sort((a, b) => a - b);
    let ans = 1;
    let a = nums[0];
    for (const b of nums) {
        if (b - a > k) {
            a = b;
            ++ans;
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
public class Solution {
    public int PartitionArray(int[] nums, int k) {
        Array.Sort(nums);
        int ans = 1;
        int a = nums[0];

        foreach (int b in nums) {
            if (b - a > k) {
                a = b;
                ans++;
            }
        }

        return ans;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>nums</code> 和一个整数 <code>k</code> 。你可以将 <code>nums</code> 划分成一个或多个 <strong>子序列</strong> ，使 <code>nums</code> 中的每个元素都 <strong>恰好</strong> 出现在一个子序列中。</p>

<p>在满足每个子序列中最大值和最小值之间的差值最多为 <code>k</code> 的前提下，返回需要划分的 <strong>最少</strong> 子序列数目。</p>

<p><strong>子序列</strong> 本质是一个序列，可以通过删除另一个序列中的某些元素（或者不删除）但不改变剩下元素的顺序得到。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [3,6,1,2,5], k = 2
<strong>输出：</strong>2
<strong>解释：</strong>
可以将 nums 划分为两个子序列 [3,1,2] 和 [6,5] 。
第一个子序列中最大值和最小值的差值是 3 - 1 = 2 。
第二个子序列中最大值和最小值的差值是 6 - 5 = 1 。
由于创建了两个子序列，返回 2 。可以证明需要划分的最少子序列数目就是 2 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3], k = 1
<strong>输出：</strong>2
<strong>解释：</strong>
可以将 nums 划分为两个子序列 [1,2] 和 [3] 。
第一个子序列中最大值和最小值的差值是 2 - 1 = 1 。
第二个子序列中最大值和最小值的差值是 3 - 3 = 0 。
由于创建了两个子序列，返回 2 。注意，另一种最优解法是将 nums 划分成子序列 [1] 和 [2,3] 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,2,4,5], k = 0
<strong>输出：</strong>3
<strong>解释：</strong>
可以将 nums 划分为三个子序列 [2,2]、[4] 和 [5] 。
第一个子序列中最大值和最小值的差值是 2 - 2 = 0 。
第二个子序列中最大值和最小值的差值是 4 - 4 = 0 。
第三个子序列中最大值和最小值的差值是 5 - 5 = 0 。
由于创建了三个子序列，返回 3 。可以证明需要划分的最少子序列数目就是 3 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= k &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 排序

题目要求划分子序列，而不是子数组，因此子序列中的元素可以不连续。我们可以将数组 $\textit{nums}$ 排序，假设当前子序列的第一个元素为 $a$，则子序列中的最大值和最小值的差值不会超过 $k$。因此我们可以遍历数组 $\textit{nums}$，如果当前元素 $b$ 与 $a$ 的差值大于 $k$，则更新 $a$ 为 $b$，并将子序列数目加 1。遍历结束后，即可得到最少子序列数目，注意初始时子序列数目为 $1$。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 为数组 $\textit{nums}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def partitionArray(self, nums: List[int], k: int) -> int:
        nums.sort()
        ans, a = 1, nums[0]
        for b in nums:
            if b - a > k:
                a = b
                ans += 1
        return ans
```

#### Java

```java
class Solution {
    public int partitionArray(int[] nums, int k) {
        Arrays.sort(nums);
        int ans = 1, a = nums[0];
        for (int b : nums) {
            if (b - a > k) {
                a = b;
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
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 1, a = nums[0];
        for (int& b : nums) {
            if (b - a > k) {
                a = b;
                ++ans;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func partitionArray(nums []int, k int) int {
	sort.Ints(nums)
	ans, a := 1, nums[0]
	for _, b := range nums {
		if b-a > k {
			a = b
			ans++
		}
	}
	return ans
}
```

#### TypeScript

```ts
function partitionArray(nums: number[], k: number): number {
    nums.sort((a, b) => a - b);
    let ans = 1;
    let a = nums[0];
    for (const b of nums) {
        if (b - a > k) {
            a = b;
            ++ans;
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn partition_array(mut nums: Vec<i32>, k: i32) -> i32 {
        nums.sort();
        let mut ans = 1;
        let mut a = nums[0];

        for &b in nums.iter() {
            if b - a > k {
                a = b;
                ans += 1;
            }
        }

        ans
    }
}
```

#### Rust

```rust
public class Solution {
    public int PartitionArray(int[] nums, int k) {
        Array.Sort(nums);
        int ans = 1;
        int a = nums[0];

        foreach (int b in nums) {
            if (b - a > k) {
                a = b;
                ans++;
            }
        }

        return ans;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2295. 替换数组中的元素](https://leetcode.cn/problems/replace-elements-in-an-array){#2295}

{{< tabs "2295" >}}

{{% tab "python" %}}
```python
class Solution:
    def arrayChange(self, nums: List[int], operations: List[List[int]]) -> List[int]:
        d = {x: i for i, x in enumerate(nums)}
        for x, y in operations:
            nums[d[x]] = y
            d[y] = d[x]
        return nums
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] arrayChange(int[] nums, int[][] operations) {
        int n = nums.length;
        Map<Integer, Integer> d = new HashMap<>(n);
        for (int i = 0; i < n; ++i) {
            d.put(nums[i], i);
        }
        for (var op : operations) {
            int x = op[0], y = op[1];
            nums[d.get(x)] = y;
            d.put(y, d.get(x));
        }
        return nums;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int, int> d;
        for (int i = 0; i < nums.size(); ++i) {
            d[nums[i]] = i;
        }
        for (auto& op : operations) {
            int x = op[0], y = op[1];
            nums[d[x]] = y;
            d[y] = d[x];
        }
        return nums;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func arrayChange(nums []int, operations [][]int) []int {
	d := map[int]int{}
	for i, x := range nums {
		d[x] = i
	}
	for _, op := range operations {
		x, y := op[0], op[1]
		nums[d[x]] = y
		d[y] = d[x]
	}
	return nums
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function arrayChange(nums: number[], operations: number[][]): number[] {
    const d: Map<number, number> = new Map(nums.map((x, i) => [x, i]));
    for (const [x, y] of operations) {
        nums[d.get(x)!] = y;
        d.set(y, d.get(x)!);
    }
    return nums;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的数组&nbsp;<code>nums</code>&nbsp;，它包含 <code>n</code>&nbsp;个 <strong>互不相同</strong>&nbsp;的正整数。请你对这个数组执行 <code>m</code>&nbsp;个操作，在第 <code>i</code>&nbsp;个操作中，你需要将数字&nbsp;<code>operations[i][0]</code> 替换成&nbsp;<code>operations[i][1]</code>&nbsp;。</p>

<p>题目保证在第 <code>i</code>&nbsp;个操作中：</p>

<ul>
	<li><code>operations[i][0]</code>&nbsp;在&nbsp;<code>nums</code>&nbsp;中存在。</li>
	<li><code>operations[i][1]</code>&nbsp;在&nbsp;<code>nums</code>&nbsp;中不存在。</li>
</ul>

<p>请你返回执行完所有操作后的数组。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [1,2,4,6], operations = [[1,3],[4,7],[6,1]]
<b>输出：</b>[3,2,7,1]
<b>解释：</b>我们对 nums 执行以下操作：
- 将数字 1 替换为 3 。nums 变为 [<em><strong>3</strong></em>,2,4,6] 。
- 将数字 4 替换为 7 。nums 变为 [3,2,<em><strong>7</strong></em>,6] 。
- 将数字 6 替换为 1 。nums 变为 [3,2,7,<em><strong>1</strong></em>] 。
返回最终数组 [3,2,7,1] 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [1,2], operations = [[1,3],[2,1],[3,2]]
<b>输出：</b>[2,1]
<b>解释：</b>我们对 nums 执行以下操作：
- 将数字 1 替换为 3 。nums 变为 [<em><strong>3</strong></em>,2] 。
- 将数字 2 替换为 1 。nums 变为 [3,<em><strong>1</strong></em>] 。
- 将数字 3 替换为 2 。nums 变为 [<em><strong>2</strong></em>,1] 。
返回最终数组 [2,1] 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>m == operations.length</code></li>
	<li><code>1 &lt;= n, m &lt;= 10<sup>5</sup></code></li>
	<li><code>nums</code>&nbsp;中所有数字 <strong>互不相同</strong>&nbsp;。</li>
	<li><code>operations[i].length == 2</code></li>
	<li><code>1 &lt;= nums[i], operations[i][0], operations[i][1] &lt;= 10<sup>6</sup></code></li>
	<li>在执行第&nbsp;<code>i</code> 个操作时，<code>operations[i][0]</code>&nbsp;在&nbsp;<code>nums</code>&nbsp;中存在。</li>
	<li>在执行第&nbsp;<code>i</code>&nbsp;个操作时，<code>operations[i][1]</code>&nbsp;在&nbsp;<code>nums</code>&nbsp;中不存在。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

我们先用哈希表 $d$ 记录数组 $\textit{nums}$ 中每个数字的下标，然后遍历操作数组 $\textit{operations}$，对于每个操作 $[x, y]$，我们将 $x$ 在 $\textit{nums}$ 中的下标 $d[x]$ 对应的数字替换为 $y$，并更新 $d$ 中 $y$ 的下标为 $d[x]$。

最后返回 $\textit{nums}$ 即可。

时间复杂度 $O(n + m)$，空间复杂度 $O(n)$。其中 $n$ 和 $m$ 分别是数组 $\textit{nums}$ 的长度和操作数组 $\textit{operations}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def arrayChange(self, nums: List[int], operations: List[List[int]]) -> List[int]:
        d = {x: i for i, x in enumerate(nums)}
        for x, y in operations:
            nums[d[x]] = y
            d[y] = d[x]
        return nums
```

#### Java

```java
class Solution {
    public int[] arrayChange(int[] nums, int[][] operations) {
        int n = nums.length;
        Map<Integer, Integer> d = new HashMap<>(n);
        for (int i = 0; i < n; ++i) {
            d.put(nums[i], i);
        }
        for (var op : operations) {
            int x = op[0], y = op[1];
            nums[d.get(x)] = y;
            d.put(y, d.get(x));
        }
        return nums;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int, int> d;
        for (int i = 0; i < nums.size(); ++i) {
            d[nums[i]] = i;
        }
        for (auto& op : operations) {
            int x = op[0], y = op[1];
            nums[d[x]] = y;
            d[y] = d[x];
        }
        return nums;
    }
};
```

#### Go

```go
func arrayChange(nums []int, operations [][]int) []int {
	d := map[int]int{}
	for i, x := range nums {
		d[x] = i
	}
	for _, op := range operations {
		x, y := op[0], op[1]
		nums[d[x]] = y
		d[y] = d[x]
	}
	return nums
}
```

#### TypeScript

```ts
function arrayChange(nums: number[], operations: number[][]): number[] {
    const d: Map<number, number> = new Map(nums.map((x, i) => [x, i]));
    for (const [x, y] of operations) {
        nums[d.get(x)!] = y;
        d.set(y, d.get(x)!);
    }
    return nums;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2296. 设计一个文本编辑器](https://leetcode.cn/problems/design-a-text-editor){#2296}

{{< tabs "2296" >}}

{{% tab "python" %}}
```python
class TextEditor:
    def __init__(self):
        self.left = []
        self.right = []

    def addText(self, text: str) -> None:
        self.left.extend(list(text))

    def deleteText(self, k: int) -> int:
        k = min(k, len(self.left))
        for _ in range(k):
            self.left.pop()
        return k

    def cursorLeft(self, k: int) -> str:
        k = min(k, len(self.left))
        for _ in range(k):
            self.right.append(self.left.pop())
        return ''.join(self.left[-10:])

    def cursorRight(self, k: int) -> str:
        k = min(k, len(self.right))
        for _ in range(k):
            self.left.append(self.right.pop())
        return ''.join(self.left[-10:])


# Your TextEditor object will be instantiated and called as such:
# obj = TextEditor()
# obj.addText(text)
# param_2 = obj.deleteText(k)
# param_3 = obj.cursorLeft(k)
# param_4 = obj.cursorRight(k)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class TextEditor {
    private StringBuilder left = new StringBuilder();
    private StringBuilder right = new StringBuilder();

    public TextEditor() {
    }

    public void addText(String text) {
        left.append(text);
    }

    public int deleteText(int k) {
        k = Math.min(k, left.length());
        left.setLength(left.length() - k);
        return k;
    }

    public String cursorLeft(int k) {
        k = Math.min(k, left.length());
        for (int i = 0; i < k; ++i) {
            right.append(left.charAt(left.length() - 1));
            left.deleteCharAt(left.length() - 1);
        }
        return left.substring(Math.max(left.length() - 10, 0));
    }

    public String cursorRight(int k) {
        k = Math.min(k, right.length());
        for (int i = 0; i < k; ++i) {
            left.append(right.charAt(right.length() - 1));
            right.deleteCharAt(right.length() - 1);
        }
        return left.substring(Math.max(left.length() - 10, 0));
    }
}

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor obj = new TextEditor();
 * obj.addText(text);
 * int param_2 = obj.deleteText(k);
 * String param_3 = obj.cursorLeft(k);
 * String param_4 = obj.cursorRight(k);
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class TextEditor {
public:
    TextEditor() {
    }

    void addText(string text) {
        left += text;
    }

    int deleteText(int k) {
        k = min(k, (int) left.size());
        left.resize(left.size() - k);
        return k;
    }

    string cursorLeft(int k) {
        k = min(k, (int) left.size());
        while (k--) {
            right += left.back();
            left.pop_back();
        }
        return left.substr(max(0, (int) left.size() - 10));
    }

    string cursorRight(int k) {
        k = min(k, (int) right.size());
        while (k--) {
            left += right.back();
            right.pop_back();
        }
        return left.substr(max(0, (int) left.size() - 10));
    }

private:
    string left, right;
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type TextEditor struct {
	left, right []byte
}

func Constructor() TextEditor {
	return TextEditor{}
}

func (this *TextEditor) AddText(text string) {
	this.left = append(this.left, text...)
}

func (this *TextEditor) DeleteText(k int) int {
	k = min(k, len(this.left))
	if k < len(this.left) {
		this.left = this.left[:len(this.left)-k]
	} else {
		this.left = []byte{}
	}
	return k
}

func (this *TextEditor) CursorLeft(k int) string {
	k = min(k, len(this.left))
	for ; k > 0; k-- {
		this.right = append(this.right, this.left[len(this.left)-1])
		this.left = this.left[:len(this.left)-1]
	}
	return string(this.left[max(len(this.left)-10, 0):])
}

func (this *TextEditor) CursorRight(k int) string {
	k = min(k, len(this.right))
	for ; k > 0; k-- {
		this.left = append(this.left, this.right[len(this.right)-1])
		this.right = this.right[:len(this.right)-1]
	}
	return string(this.left[max(len(this.left)-10, 0):])
}

/**
 * Your TextEditor object will be instantiated and called as such:
 * obj := Constructor();
 * obj.AddText(text);
 * param_2 := obj.DeleteText(k);
 * param_3 := obj.CursorLeft(k);
 * param_4 := obj.CursorRight(k);
 */
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class TextEditor {
    private left: string[];
    private right: string[];

    constructor() {
        this.left = [];
        this.right = [];
    }

    addText(text: string): void {
        this.left.push(...text);
    }

    deleteText(k: number): number {
        k = Math.min(k, this.left.length);
        for (let i = 0; i < k; i++) {
            this.left.pop();
        }
        return k;
    }

    cursorLeft(k: number): string {
        k = Math.min(k, this.left.length);
        for (let i = 0; i < k; i++) {
            this.right.push(this.left.pop()!);
        }
        return this.left.slice(-10).join('');
    }

    cursorRight(k: number): string {
        k = Math.min(k, this.right.length);
        for (let i = 0; i < k; i++) {
            this.left.push(this.right.pop()!);
        }
        return this.left.slice(-10).join('');
    }
}

/**
 * Your TextEditor object will be instantiated and called as such:
 * var obj = new TextEditor()
 * obj.addText(text)
 * var param_2 = obj.deleteText(k)
 * var param_3 = obj.cursorLeft(k)
 * var param_4 = obj.cursorRight(k)
 */
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
struct TextEditor {
    left: String,
    right: String,
}

impl TextEditor {
    fn new() -> Self {
        TextEditor {
            left: String::new(),
            right: String::new(),
        }
    }

    fn add_text(&mut self, text: String) {
        self.left.push_str(&text);
    }

    fn delete_text(&mut self, k: i32) -> i32 {
        let k = k.min(self.left.len() as i32) as usize;
        self.left.truncate(self.left.len() - k);
        k as i32
    }

    fn cursor_left(&mut self, k: i32) -> String {
        let k = k.min(self.left.len() as i32) as usize;
        for _ in 0..k {
            if let Some(c) = self.left.pop() {
                self.right.push(c);
            }
        }
        self.get_last_10_chars()
    }

    fn cursor_right(&mut self, k: i32) -> String {
        let k = k.min(self.right.len() as i32) as usize;
        for _ in 0..k {
            if let Some(c) = self.right.pop() {
                self.left.push(c);
            }
        }
        self.get_last_10_chars()
    }

    fn get_last_10_chars(&self) -> String {
        let len = self.left.len();
        self.left[len.saturating_sub(10)..].to_string()
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>请你设计一个带光标的文本编辑器，它可以实现以下功能：</p>

<ul>
	<li><strong>添加：</strong>在光标所在处添加文本。</li>
	<li><strong>删除：</strong>在光标所在处删除文本（模拟键盘的删除键）。</li>
	<li><strong>移动：</strong>将光标往左或者往右移动。</li>
</ul>

<p>当删除文本时，只有光标左边的字符会被删除。光标会留在文本内，也就是说任意时候&nbsp;<code>0 &lt;= cursor.position &lt;= currentText.length</code>&nbsp;都成立。</p>

<p>请你实现&nbsp;<code>TextEditor</code>&nbsp;类：</p>

<ul>
	<li><code>TextEditor()</code>&nbsp;用空文本初始化对象。</li>
	<li><code>void addText(string text)</code>&nbsp;将&nbsp;<code>text</code>&nbsp;添加到光标所在位置。添加完后光标在&nbsp;<code>text</code>&nbsp;的右边。</li>
	<li><code>int deleteText(int k)</code>&nbsp;删除光标左边&nbsp;<code>k</code>&nbsp;个字符。返回实际删除的字符数目。</li>
	<li><code>string cursorLeft(int k)</code> 将光标向左移动&nbsp;<code>k</code>&nbsp;次。返回移动后光标左边&nbsp;<code>min(10, len)</code>&nbsp;个字符，其中&nbsp;<code>len</code>&nbsp;是光标左边的字符数目。</li>
	<li><code>string cursorRight(int k)</code>&nbsp;将光标向右移动&nbsp;<code>k</code>&nbsp;次。返回移动后光标左边&nbsp;<code>min(10, len)</code>&nbsp;个字符，其中&nbsp;<code>len</code>&nbsp;是光标左边的字符数目。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
["TextEditor", "addText", "deleteText", "addText", "cursorRight", "cursorLeft", "deleteText", "cursorLeft", "cursorRight"]
[[], ["leetcode"], [4], ["practice"], [3], [8], [10], [2], [6]]
<strong>输出：</strong>
[null, null, 4, null, "etpractice", "leet", 4, "", "practi"]

<strong>解释：</strong>
TextEditor textEditor = new TextEditor(); // 当前 text 为 "|" 。（'|' 字符表示光标）
textEditor.addText("leetcode"); // 当前文本为 "leetcode|" 。
textEditor.deleteText(4); // 返回 4
                          // 当前文本为 "leet|" 。
                          // 删除了 4 个字符。
textEditor.addText("practice"); // 当前文本为 "leetpractice|" 。
textEditor.cursorRight(3); // 返回 "etpractice"
                           // 当前文本为 "leetpractice|". 
                           // 光标无法移动到文本以外，所以无法移动。
                           // "etpractice" 是光标左边的 10 个字符。
textEditor.cursorLeft(8); // 返回 "leet"
                          // 当前文本为 "leet|practice" 。
                          // "leet" 是光标左边的 min(10, 4) = 4 个字符。
textEditor.deleteText(10); // 返回 4
                           // 当前文本为 "|practice" 。
                           // 只有 4 个字符被删除了。
textEditor.cursorLeft(2); // 返回 ""
                          // 当前文本为 "|practice" 。
                          // 光标无法移动到文本以外，所以无法移动。
                          // "" 是光标左边的 min(10, 0) = 0 个字符。
textEditor.cursorRight(6); // 返回 "practi"
                           // 当前文本为 "practi|ce" 。
                           // "practi" 是光标左边的 min(10, 6) = 6 个字符。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= text.length, k &lt;= 40</code></li>
	<li><code>text</code>&nbsp;只含有小写英文字母。</li>
	<li>调用 <code>addText</code>&nbsp;，<code>deleteText</code>&nbsp;，<code>cursorLeft</code> 和&nbsp;<code>cursorRight</code>&nbsp;的 <strong>总</strong> 次数不超过&nbsp;<code>2 * 10<sup>4</sup></code>&nbsp;次。</li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>你能设计并实现一个每次调用时间复杂度为 <code>O(k)</code> 的解决方案吗？</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：左右栈

我们可以使用两个栈 $\textit{left}$ 和 $\textit{right}$，其中栈 $\textit{left}$ 存储光标左边的字符，另一个栈 $\textit{right}$ 存储光标右边的字符。

-   当调用 $\text{addText}$ 方法时，我们将 $\text{text}$ 中的字符依次入栈 $\text{left}$。时间复杂度 $O(|\text{text}|)$。
-   当调用 $\text{deleteText}$ 方法时，我们将 $\text{left}$ 中的字符出栈最多 $k$ 次。时间复杂度 $O(k)$。
-   当调用 $\text{cursorLeft}$ 方法时，我们将 $\text{left}$ 中的字符出栈最多 $k$ 次，然后将出栈的字符依次入栈 $\text{right}$，最后返回 $\text{left}$ 栈最多 $10$ 个字符。时间复杂度 $O(k)$。
-   当调用 $\text{cursorRight}$ 方法时，我们将 $\text{right}$ 中的字符出栈最多 $k$ 次，然后将出栈的字符依次入栈 $\text{left}$，最后返回 $\text{left}$ 栈最多 $10$ 个字符。时间复杂度 $O(k)$。

<!-- tabs:start -->

#### Python3

```python
class TextEditor:
    def __init__(self):
        self.left = []
        self.right = []

    def addText(self, text: str) -> None:
        self.left.extend(list(text))

    def deleteText(self, k: int) -> int:
        k = min(k, len(self.left))
        for _ in range(k):
            self.left.pop()
        return k

    def cursorLeft(self, k: int) -> str:
        k = min(k, len(self.left))
        for _ in range(k):
            self.right.append(self.left.pop())
        return ''.join(self.left[-10:])

    def cursorRight(self, k: int) -> str:
        k = min(k, len(self.right))
        for _ in range(k):
            self.left.append(self.right.pop())
        return ''.join(self.left[-10:])


# Your TextEditor object will be instantiated and called as such:
# obj = TextEditor()
# obj.addText(text)
# param_2 = obj.deleteText(k)
# param_3 = obj.cursorLeft(k)
# param_4 = obj.cursorRight(k)
```

#### Java

```java
class TextEditor {
    private StringBuilder left = new StringBuilder();
    private StringBuilder right = new StringBuilder();

    public TextEditor() {
    }

    public void addText(String text) {
        left.append(text);
    }

    public int deleteText(int k) {
        k = Math.min(k, left.length());
        left.setLength(left.length() - k);
        return k;
    }

    public String cursorLeft(int k) {
        k = Math.min(k, left.length());
        for (int i = 0; i < k; ++i) {
            right.append(left.charAt(left.length() - 1));
            left.deleteCharAt(left.length() - 1);
        }
        return left.substring(Math.max(left.length() - 10, 0));
    }

    public String cursorRight(int k) {
        k = Math.min(k, right.length());
        for (int i = 0; i < k; ++i) {
            left.append(right.charAt(right.length() - 1));
            right.deleteCharAt(right.length() - 1);
        }
        return left.substring(Math.max(left.length() - 10, 0));
    }
}

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor obj = new TextEditor();
 * obj.addText(text);
 * int param_2 = obj.deleteText(k);
 * String param_3 = obj.cursorLeft(k);
 * String param_4 = obj.cursorRight(k);
 */
```

#### C++

```cpp
class TextEditor {
public:
    TextEditor() {
    }

    void addText(string text) {
        left += text;
    }

    int deleteText(int k) {
        k = min(k, (int) left.size());
        left.resize(left.size() - k);
        return k;
    }

    string cursorLeft(int k) {
        k = min(k, (int) left.size());
        while (k--) {
            right += left.back();
            left.pop_back();
        }
        return left.substr(max(0, (int) left.size() - 10));
    }

    string cursorRight(int k) {
        k = min(k, (int) right.size());
        while (k--) {
            left += right.back();
            right.pop_back();
        }
        return left.substr(max(0, (int) left.size() - 10));
    }

private:
    string left, right;
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */
```

#### Go

```go
type TextEditor struct {
	left, right []byte
}

func Constructor() TextEditor {
	return TextEditor{}
}

func (this *TextEditor) AddText(text string) {
	this.left = append(this.left, text...)
}

func (this *TextEditor) DeleteText(k int) int {
	k = min(k, len(this.left))
	if k < len(this.left) {
		this.left = this.left[:len(this.left)-k]
	} else {
		this.left = []byte{}
	}
	return k
}

func (this *TextEditor) CursorLeft(k int) string {
	k = min(k, len(this.left))
	for ; k > 0; k-- {
		this.right = append(this.right, this.left[len(this.left)-1])
		this.left = this.left[:len(this.left)-1]
	}
	return string(this.left[max(len(this.left)-10, 0):])
}

func (this *TextEditor) CursorRight(k int) string {
	k = min(k, len(this.right))
	for ; k > 0; k-- {
		this.left = append(this.left, this.right[len(this.right)-1])
		this.right = this.right[:len(this.right)-1]
	}
	return string(this.left[max(len(this.left)-10, 0):])
}

/**
 * Your TextEditor object will be instantiated and called as such:
 * obj := Constructor();
 * obj.AddText(text);
 * param_2 := obj.DeleteText(k);
 * param_3 := obj.CursorLeft(k);
 * param_4 := obj.CursorRight(k);
 */
```

#### TypeScript

```ts
class TextEditor {
    private left: string[];
    private right: string[];

    constructor() {
        this.left = [];
        this.right = [];
    }

    addText(text: string): void {
        this.left.push(...text);
    }

    deleteText(k: number): number {
        k = Math.min(k, this.left.length);
        for (let i = 0; i < k; i++) {
            this.left.pop();
        }
        return k;
    }

    cursorLeft(k: number): string {
        k = Math.min(k, this.left.length);
        for (let i = 0; i < k; i++) {
            this.right.push(this.left.pop()!);
        }
        return this.left.slice(-10).join('');
    }

    cursorRight(k: number): string {
        k = Math.min(k, this.right.length);
        for (let i = 0; i < k; i++) {
            this.left.push(this.right.pop()!);
        }
        return this.left.slice(-10).join('');
    }
}

/**
 * Your TextEditor object will be instantiated and called as such:
 * var obj = new TextEditor()
 * obj.addText(text)
 * var param_2 = obj.deleteText(k)
 * var param_3 = obj.cursorLeft(k)
 * var param_4 = obj.cursorRight(k)
 */
```

#### Rust

```rust
struct TextEditor {
    left: String,
    right: String,
}

impl TextEditor {
    fn new() -> Self {
        TextEditor {
            left: String::new(),
            right: String::new(),
        }
    }

    fn add_text(&mut self, text: String) {
        self.left.push_str(&text);
    }

    fn delete_text(&mut self, k: i32) -> i32 {
        let k = k.min(self.left.len() as i32) as usize;
        self.left.truncate(self.left.len() - k);
        k as i32
    }

    fn cursor_left(&mut self, k: i32) -> String {
        let k = k.min(self.left.len() as i32) as usize;
        for _ in 0..k {
            if let Some(c) = self.left.pop() {
                self.right.push(c);
            }
        }
        self.get_last_10_chars()
    }

    fn cursor_right(&mut self, k: i32) -> String {
        let k = k.min(self.right.len() as i32) as usize;
        for _ in 0..k {
            if let Some(c) = self.right.pop() {
                self.left.push(c);
            }
        }
        self.get_last_10_chars()
    }

    fn get_last_10_chars(&self) -> String {
        let len = self.left.len();
        self.left[len.saturating_sub(10)..].to_string()
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2297. 跳跃游戏 VIII 🔒](https://leetcode.cn/problems/jump-game-viii){#2297}

{{< tabs "2297" >}}

{{% tab "python" %}}
```python
class Solution:
    def minCost(self, nums: List[int], costs: List[int]) -> int:
        n = len(nums)
        g = defaultdict(list)
        stk = []
        for i in range(n - 1, -1, -1):
            while stk and nums[stk[-1]] < nums[i]:
                stk.pop()
            if stk:
                g[i].append(stk[-1])
            stk.append(i)

        stk = []
        for i in range(n - 1, -1, -1):
            while stk and nums[stk[-1]] >= nums[i]:
                stk.pop()
            if stk:
                g[i].append(stk[-1])
            stk.append(i)

        f = [inf] * n
        f[0] = 0
        for i in range(n):
            for j in g[i]:
                f[j] = min(f[j], f[i] + costs[j])
        return f[n - 1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long minCost(int[] nums, int[] costs) {
        int n = nums.length;
        List<Integer>[] g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        Deque<Integer> stk = new ArrayDeque<>();
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.isEmpty() && nums[stk.peek()] < nums[i]) {
                stk.pop();
            }
            if (!stk.isEmpty()) {
                g[i].add(stk.peek());
            }
            stk.push(i);
        }
        stk.clear();
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.isEmpty() && nums[stk.peek()] >= nums[i]) {
                stk.pop();
            }
            if (!stk.isEmpty()) {
                g[i].add(stk.peek());
            }
            stk.push(i);
        }
        long[] f = new long[n];
        Arrays.fill(f, 1L << 60);
        f[0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j : g[i]) {
                f[j] = Math.min(f[j], f[i] + costs[j]);
            }
        }
        return f[n - 1];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& costs) {
        int n = nums.size();
        vector<int> g[n];
        stack<int> stk;
        for (int i = n - 1; ~i; --i) {
            while (!stk.empty() && nums[stk.top()] < nums[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                g[i].push_back(stk.top());
            }
            stk.push(i);
        }
        stk = stack<int>();
        for (int i = n - 1; ~i; --i) {
            while (!stk.empty() && nums[stk.top()] >= nums[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                g[i].push_back(stk.top());
            }
            stk.push(i);
        }
        vector<long long> f(n, 1e18);
        f[0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j : g[i]) {
                f[j] = min(f[j], f[i] + costs[j]);
            }
        }
        return f[n - 1];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minCost(nums []int, costs []int) int64 {
	n := len(nums)
	g := make([][]int, n)
	stk := []int{}
	for i := n - 1; i >= 0; i-- {
		for len(stk) > 0 && nums[stk[len(stk)-1]] < nums[i] {
			stk = stk[:len(stk)-1]
		}
		if len(stk) > 0 {
			g[i] = append(g[i], stk[len(stk)-1])
		}
		stk = append(stk, i)
	}
	stk = []int{}
	for i := n - 1; i >= 0; i-- {
		for len(stk) > 0 && nums[stk[len(stk)-1]] >= nums[i] {
			stk = stk[:len(stk)-1]
		}
		if len(stk) > 0 {
			g[i] = append(g[i], stk[len(stk)-1])
		}
		stk = append(stk, i)
	}
	f := make([]int64, n)
	for i := 1; i < n; i++ {
		f[i] = math.MaxInt64
	}
	for i := 0; i < n; i++ {
		for _, j := range g[i] {
			f[j] = min(f[j], f[i]+int64(costs[j]))
		}
	}
	return f[n-1]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minCost(nums: number[], costs: number[]): number {
    const n = nums.length;
    const g: number[][] = Array.from({ length: n }, () => []);
    const stk: number[] = [];
    for (let i = n - 1; i >= 0; --i) {
        while (stk.length && nums[stk[stk.length - 1]] < nums[i]) {
            stk.pop();
        }
        if (stk.length) {
            g[i].push(stk[stk.length - 1]);
        }
        stk.push(i);
    }
    stk.length = 0;
    for (let i = n - 1; i >= 0; --i) {
        while (stk.length && nums[stk[stk.length - 1]] >= nums[i]) {
            stk.pop();
        }
        if (stk.length) {
            g[i].push(stk[stk.length - 1]);
        }
        stk.push(i);
    }
    const f: number[] = Array.from({ length: n }, () => Infinity);
    f[0] = 0;
    for (let i = 0; i < n; ++i) {
        for (const j of g[i]) {
            f[j] = Math.min(f[j], f[i] + costs[j]);
        }
    }
    return f[n - 1];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个长度为 n 的下标从 <strong>0</strong>&nbsp;开始的整数数组 <code>nums</code>。初始位置为下标 <code>0</code>。当 <code>i &lt; j</code> 时，你可以从下标 <code>i</code> 跳转到下标 <code>j</code>:</p>

<ul>
	<li>对于在&nbsp;<code>i &lt; k &lt; j</code>&nbsp;范围内的所有下标 <code>k</code> 有&nbsp;<code>nums[i] &lt;= nums[j]</code> 和&nbsp;<code>nums[k] &lt; nums[i]</code> , 或者</li>
	<li>对于在&nbsp;<code>i &lt; k &lt; j</code>&nbsp;范围内的所有下标 <code>k</code>&nbsp;有&nbsp;<code>nums[i] &gt; nums[j]</code> 和&nbsp;<code>nums[k] &gt;= nums[i]</code>&nbsp;。</li>
</ul>

<p>你还得到了一个长度为 <code>n</code> 的整数数组 <code>costs</code>，其中 <code>costs[i]</code> 表示跳转<strong>到</strong>下标 <code>i</code> 的代价。</p>

<p>返回<em>跳转到</em>下标 <em><code>n - 1</code> 的最小代价。</em></p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> nums = [3,2,4,4,1], costs = [3,7,6,4,2]
<strong>输出:</strong> 8
<strong>解释:</strong> 从下标 0 开始。
- 以 costs[2]= 6 的代价跳转到下标 2。
- 以 costs[4]= 2 的代价跳转到下标 4。
总代价是 8。可以证明，8 是所需的最小代价。
另外两个可能的路径是:下标 0 -&gt; 1 -&gt; 4 和下标 0 -&gt; 2 -&gt; 3 -&gt; 4。
它们的总代价分别为9和12。
</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre>
<strong>输入:</strong> nums = [0,1,2], costs = [1,1,1]
<strong>输出:</strong> 2
<strong>解释:</strong> 从下标 0 开始。
- 以 costs[1] = 1 的代价跳转到下标 1。
- 以 costs[2] = 1 的代价跳转到下标 2。
总代价是 2。注意您不能直接从下标 0 跳转到下标 2，因为 nums[0] &lt;= nums[1]。
</pre>

<p>&nbsp;</p>

<p><strong>解释:</strong></p>

<ul>
	<li><code>n == nums.length == costs.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i], costs[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：单调栈 + 动态规划

根据题目描述，我们实际上需要找到 $\textit{nums}[i]$ 的下一个大于等于 $\textit{nums}[i]$ 的位置 $j$，以及下一个小于 $\textit{nums}[i]$ 的位置 $j$。我们利用单调栈可以在 $O(n)$ 的时间内找到这两个位置，然后构建邻接表 $g$，其中 $g[i]$ 表示下标 $i$ 可以跳转到的下标。

然后我们使用动态规划求解最小代价。设 $f[i]$ 表示跳转到下标 $i$ 的最小代价，初始时 $f[0] = 0$，其余 $f[i] = \infty$。我们从小到大枚举下标 $i$，对于每个 $i$，我们枚举 $g[i]$ 中的每个下标 $j$，进行状态转移 $f[j] = \min(f[j], f[i] + \textit{costs}[j])$。答案为 $f[n - 1]$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minCost(self, nums: List[int], costs: List[int]) -> int:
        n = len(nums)
        g = defaultdict(list)
        stk = []
        for i in range(n - 1, -1, -1):
            while stk and nums[stk[-1]] < nums[i]:
                stk.pop()
            if stk:
                g[i].append(stk[-1])
            stk.append(i)

        stk = []
        for i in range(n - 1, -1, -1):
            while stk and nums[stk[-1]] >= nums[i]:
                stk.pop()
            if stk:
                g[i].append(stk[-1])
            stk.append(i)

        f = [inf] * n
        f[0] = 0
        for i in range(n):
            for j in g[i]:
                f[j] = min(f[j], f[i] + costs[j])
        return f[n - 1]
```

#### Java

```java
class Solution {
    public long minCost(int[] nums, int[] costs) {
        int n = nums.length;
        List<Integer>[] g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        Deque<Integer> stk = new ArrayDeque<>();
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.isEmpty() && nums[stk.peek()] < nums[i]) {
                stk.pop();
            }
            if (!stk.isEmpty()) {
                g[i].add(stk.peek());
            }
            stk.push(i);
        }
        stk.clear();
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.isEmpty() && nums[stk.peek()] >= nums[i]) {
                stk.pop();
            }
            if (!stk.isEmpty()) {
                g[i].add(stk.peek());
            }
            stk.push(i);
        }
        long[] f = new long[n];
        Arrays.fill(f, 1L << 60);
        f[0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j : g[i]) {
                f[j] = Math.min(f[j], f[i] + costs[j]);
            }
        }
        return f[n - 1];
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& costs) {
        int n = nums.size();
        vector<int> g[n];
        stack<int> stk;
        for (int i = n - 1; ~i; --i) {
            while (!stk.empty() && nums[stk.top()] < nums[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                g[i].push_back(stk.top());
            }
            stk.push(i);
        }
        stk = stack<int>();
        for (int i = n - 1; ~i; --i) {
            while (!stk.empty() && nums[stk.top()] >= nums[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                g[i].push_back(stk.top());
            }
            stk.push(i);
        }
        vector<long long> f(n, 1e18);
        f[0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j : g[i]) {
                f[j] = min(f[j], f[i] + costs[j]);
            }
        }
        return f[n - 1];
    }
};
```

#### Go

```go
func minCost(nums []int, costs []int) int64 {
	n := len(nums)
	g := make([][]int, n)
	stk := []int{}
	for i := n - 1; i >= 0; i-- {
		for len(stk) > 0 && nums[stk[len(stk)-1]] < nums[i] {
			stk = stk[:len(stk)-1]
		}
		if len(stk) > 0 {
			g[i] = append(g[i], stk[len(stk)-1])
		}
		stk = append(stk, i)
	}
	stk = []int{}
	for i := n - 1; i >= 0; i-- {
		for len(stk) > 0 && nums[stk[len(stk)-1]] >= nums[i] {
			stk = stk[:len(stk)-1]
		}
		if len(stk) > 0 {
			g[i] = append(g[i], stk[len(stk)-1])
		}
		stk = append(stk, i)
	}
	f := make([]int64, n)
	for i := 1; i < n; i++ {
		f[i] = math.MaxInt64
	}
	for i := 0; i < n; i++ {
		for _, j := range g[i] {
			f[j] = min(f[j], f[i]+int64(costs[j]))
		}
	}
	return f[n-1]
}
```

#### TypeScript

```ts
function minCost(nums: number[], costs: number[]): number {
    const n = nums.length;
    const g: number[][] = Array.from({ length: n }, () => []);
    const stk: number[] = [];
    for (let i = n - 1; i >= 0; --i) {
        while (stk.length && nums[stk[stk.length - 1]] < nums[i]) {
            stk.pop();
        }
        if (stk.length) {
            g[i].push(stk[stk.length - 1]);
        }
        stk.push(i);
    }
    stk.length = 0;
    for (let i = n - 1; i >= 0; --i) {
        while (stk.length && nums[stk[stk.length - 1]] >= nums[i]) {
            stk.pop();
        }
        if (stk.length) {
            g[i].push(stk[stk.length - 1]);
        }
        stk.push(i);
    }
    const f: number[] = Array.from({ length: n }, () => Infinity);
    f[0] = 0;
    for (let i = 0; i < n; ++i) {
        for (const j of g[i]) {
            f[j] = Math.min(f[j], f[i] + costs[j]);
        }
    }
    return f[n - 1];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2298. 周末任务计数 🔒](https://leetcode.cn/problems/tasks-count-in-the-weekend){#2298}

{{< tabs "2298" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT
    SUM(WEEKDAY(submit_date) IN (5, 6)) AS weekend_cnt,
    SUM(WEEKDAY(submit_date) NOT IN (5, 6)) AS working_cnt
FROM Tasks;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表: <code>Tasks</code></p>

<pre>
+-------------+------+
| Column Name | Type |
+-------------+------+
| task_id     | int  |
| assignee_id | int  |
| submit_date | date |
+-------------+------+
<code>task_id</code> 是该表的主键（具有唯一值的列）。
此表中的每一行都包含任务 ID、委托人 ID 和提交日期。
</pre>

<p>&nbsp;</p>

<p>编写一个解决方案来报告：</p>

<ul>
	<li>在周末 (周六，周日) 提交的任务的数量&nbsp;<code>weekend_cnt</code>，以及</li>
	<li>工作日内提交的任务数 <code>working_cnt</code>。</li>
</ul>

<p>按 <strong>任意顺序</strong> 返回结果表。<br />
返回结果格式如以下示例所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> 
Tasks 表:
+---------+-------------+-------------+
| task_id | assignee_id | submit_date |
+---------+-------------+-------------+
| 1       | 1           | 2022-06-13  |
| 2       | 6           | 2022-06-14  |
| 3       | 6           | 2022-06-15  |
| 4       | 3           | 2022-06-18  |
| 5       | 5           | 2022-06-19  |
| 6       | 7           | 2022-06-19  |
+---------+-------------+-------------+
<strong>输出:</strong> 
+-------------+-------------+
| weekend_cnt | working_cnt |
+-------------+-------------+
| 3           | 3           |
+-------------+-------------+
<strong>解释:</strong> 
Task 1 是在周一提交的。
Task 2 是在周二提交的。
Task 3 是在周三提交的。
Task 4 是在周六提交的。
Task 5 是在周日提交的。
Task 6 是在周日提交的。
3 个任务是在周末提交的。
3 个任务是在工作日提交的。
</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：WEEKDAY() 函数

`WEEKDAY()` 函数返回日期的工作日编号，从 0 开始，0 表示星期一，1 表示星期二，以此类推，6 表示星期日。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT
    SUM(WEEKDAY(submit_date) IN (5, 6)) AS weekend_cnt,
    SUM(WEEKDAY(submit_date) NOT IN (5, 6)) AS working_cnt
FROM Tasks;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2299. 强密码检验器 II](https://leetcode.cn/problems/strong-password-checker-ii){#2299}

{{< tabs "2299" >}}

{{% tab "python" %}}
```python
class Solution:
    def strongPasswordCheckerII(self, password: str) -> bool:
        if len(password) < 8:
            return False
        mask = 0
        for i, c in enumerate(password):
            if i and c == password[i - 1]:
                return False
            if c.islower():
                mask |= 1
            elif c.isupper():
                mask |= 2
            elif c.isdigit():
                mask |= 4
            else:
                mask |= 8
        return mask == 15
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean strongPasswordCheckerII(String password) {
        if (password.length() < 8) {
            return false;
        }
        int mask = 0;
        for (int i = 0; i < password.length(); ++i) {
            char c = password.charAt(i);
            if (i > 0 && c == password.charAt(i - 1)) {
                return false;
            }
            if (Character.isLowerCase(c)) {
                mask |= 1;
            } else if (Character.isUpperCase(c)) {
                mask |= 2;
            } else if (Character.isDigit(c)) {
                mask |= 4;
            } else {
                mask |= 8;
            }
        }
        return mask == 15;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        if (password.size() < 8) {
            return false;
        }
        int mask = 0;
        for (int i = 0; i < password.size(); ++i) {
            char c = password[i];
            if (i && c == password[i - 1]) {
                return false;
            }
            if (c >= 'a' && c <= 'z') {
                mask |= 1;
            } else if (c >= 'A' && c <= 'Z') {
                mask |= 2;
            } else if (c >= '0' && c <= '9') {
                mask |= 4;
            } else {
                mask |= 8;
            }
        }
        return mask == 15;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func strongPasswordCheckerII(password string) bool {
	if len(password) < 8 {
		return false
	}
	mask := 0
	for i, c := range password {
		if i > 0 && byte(c) == password[i-1] {
			return false
		}
		if unicode.IsLower(c) {
			mask |= 1
		} else if unicode.IsUpper(c) {
			mask |= 2
		} else if unicode.IsDigit(c) {
			mask |= 4
		} else {
			mask |= 8
		}
	}
	return mask == 15
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function strongPasswordCheckerII(password: string): boolean {
    if (password.length < 8) {
        return false;
    }
    let mask = 0;
    for (let i = 0; i < password.length; ++i) {
        const c = password[i];
        if (i && c == password[i - 1]) {
            return false;
        }
        if (c >= 'a' && c <= 'z') {
            mask |= 1;
        } else if (c >= 'A' && c <= 'Z') {
            mask |= 2;
        } else if (c >= '0' && c <= '9') {
            mask |= 4;
        } else {
            mask |= 8;
        }
    }
    return mask == 15;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn strong_password_checker_ii(password: String) -> bool {
        let s = password.as_bytes();
        let n = password.len();
        if n < 8 {
            return false;
        }
        let mut mask = 0;
        let mut prev = b' ';
        for &c in s.iter() {
            if c == prev {
                return false;
            }
            mask |= if c.is_ascii_uppercase() {
                0b1000
            } else if c.is_ascii_lowercase() {
                0b100
            } else if c.is_ascii_digit() {
                0b10
            } else {
                0b1
            };
            prev = c;
        }
        mask == 0b1111
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
bool strongPasswordCheckerII(char* password) {
    int n = strlen(password);
    if (n < 8) {
        return false;
    }
    int mask = 0;
    char prev = ' ';
    for (int i = 0; i < n; i++) {
        if (prev == password[i]) {
            return false;
        }
        if (islower(password[i])) {
            mask |= 0b1000;
        } else if (isupper(password[i])) {
            mask |= 0b100;
        } else if (isdigit(password[i])) {
            mask |= 0b10;
        } else {
            mask |= 0b1;
        }
        prev = password[i];
    }
    return mask == 0b1111;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>如果一个密码满足以下所有条件，我们称它是一个 <strong>强</strong>&nbsp;密码：</p>

<ul>
	<li>它有至少 <code>8</code>&nbsp;个字符。</li>
	<li>至少包含 <strong>一个小写英文</strong>&nbsp;字母。</li>
	<li>至少包含 <strong>一个大写英文</strong>&nbsp;字母。</li>
	<li>至少包含 <strong>一个数字</strong>&nbsp;。</li>
	<li>至少包含 <strong>一个特殊字符</strong>&nbsp;。特殊字符为：<code>"!@#$%^&amp;*()-+"</code>&nbsp;中的一个。</li>
	<li>它 <strong>不</strong>&nbsp;包含&nbsp;<code>2</code>&nbsp;个连续相同的字符（比方说&nbsp;<code>"aab"</code>&nbsp;不符合该条件，但是&nbsp;<code>"aba"</code>&nbsp;符合该条件）。</li>
</ul>

<p>给你一个字符串&nbsp;<code>password</code>&nbsp;，如果它是一个&nbsp;<strong>强</strong>&nbsp;密码，返回&nbsp;<code>true</code>，否则返回&nbsp;<code>false</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>password = "IloveLe3tcode!"
<b>输出：</b>true
<b>解释：</b>密码满足所有的要求，所以我们返回 true 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>password = "Me+You--IsMyDream"
<b>输出：</b>false
<b>解释：</b>密码不包含数字，且包含 2 个连续相同的字符。所以我们返回 false 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>password = "1aB!"
<b>输出：</b>false
<b>解释：</b>密码不符合长度要求。所以我们返回 false 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= password.length &lt;= 100</code></li>
	<li><code>password</code>&nbsp;包含字母，数字和&nbsp;<code>"!@#$%^&amp;*()-+"</code>&nbsp;这些特殊字符。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟 + 位运算

根据题目描述，我们可以模拟检查密码是否满足题目要求的过程。

首先，我们检查密码的长度是否小于 $8$，如果是，则返回 $\textit{false}$。

接下来，我们用一个掩码 $\textit{mask}$ 来记录密码是否包含小写字母、大写字母、数字和特殊字符。我们遍历密码，每次遍历到一个字符，先判断它是否和前一个字符相同，如果是，则返回 $\textit{false}$。然后，根据字符的类型更新掩码 $\textit{mask}$。最后，我们检查掩码 $\textit{mask}$ 是否为 $15$，如果是，则返回 $\textit{true}$，否则返回 $\textit{false}$。

时间复杂度 $O(n)$，空间复杂度 $O(1)$。其中 $n$ 为密码的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def strongPasswordCheckerII(self, password: str) -> bool:
        if len(password) < 8:
            return False
        mask = 0
        for i, c in enumerate(password):
            if i and c == password[i - 1]:
                return False
            if c.islower():
                mask |= 1
            elif c.isupper():
                mask |= 2
            elif c.isdigit():
                mask |= 4
            else:
                mask |= 8
        return mask == 15
```

#### Java

```java
class Solution {
    public boolean strongPasswordCheckerII(String password) {
        if (password.length() < 8) {
            return false;
        }
        int mask = 0;
        for (int i = 0; i < password.length(); ++i) {
            char c = password.charAt(i);
            if (i > 0 && c == password.charAt(i - 1)) {
                return false;
            }
            if (Character.isLowerCase(c)) {
                mask |= 1;
            } else if (Character.isUpperCase(c)) {
                mask |= 2;
            } else if (Character.isDigit(c)) {
                mask |= 4;
            } else {
                mask |= 8;
            }
        }
        return mask == 15;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        if (password.size() < 8) {
            return false;
        }
        int mask = 0;
        for (int i = 0; i < password.size(); ++i) {
            char c = password[i];
            if (i && c == password[i - 1]) {
                return false;
            }
            if (c >= 'a' && c <= 'z') {
                mask |= 1;
            } else if (c >= 'A' && c <= 'Z') {
                mask |= 2;
            } else if (c >= '0' && c <= '9') {
                mask |= 4;
            } else {
                mask |= 8;
            }
        }
        return mask == 15;
    }
};
```

#### Go

```go
func strongPasswordCheckerII(password string) bool {
	if len(password) < 8 {
		return false
	}
	mask := 0
	for i, c := range password {
		if i > 0 && byte(c) == password[i-1] {
			return false
		}
		if unicode.IsLower(c) {
			mask |= 1
		} else if unicode.IsUpper(c) {
			mask |= 2
		} else if unicode.IsDigit(c) {
			mask |= 4
		} else {
			mask |= 8
		}
	}
	return mask == 15
}
```

#### TypeScript

```ts
function strongPasswordCheckerII(password: string): boolean {
    if (password.length < 8) {
        return false;
    }
    let mask = 0;
    for (let i = 0; i < password.length; ++i) {
        const c = password[i];
        if (i && c == password[i - 1]) {
            return false;
        }
        if (c >= 'a' && c <= 'z') {
            mask |= 1;
        } else if (c >= 'A' && c <= 'Z') {
            mask |= 2;
        } else if (c >= '0' && c <= '9') {
            mask |= 4;
        } else {
            mask |= 8;
        }
    }
    return mask == 15;
}
```

#### Rust

```rust
impl Solution {
    pub fn strong_password_checker_ii(password: String) -> bool {
        let s = password.as_bytes();
        let n = password.len();
        if n < 8 {
            return false;
        }
        let mut mask = 0;
        let mut prev = b' ';
        for &c in s.iter() {
            if c == prev {
                return false;
            }
            mask |= if c.is_ascii_uppercase() {
                0b1000
            } else if c.is_ascii_lowercase() {
                0b100
            } else if c.is_ascii_digit() {
                0b10
            } else {
                0b1
            };
            prev = c;
        }
        mask == 0b1111
    }
}
```

#### C

```c
bool strongPasswordCheckerII(char* password) {
    int n = strlen(password);
    if (n < 8) {
        return false;
    }
    int mask = 0;
    char prev = ' ';
    for (int i = 0; i < n; i++) {
        if (prev == password[i]) {
            return false;
        }
        if (islower(password[i])) {
            mask |= 0b1000;
        } else if (isupper(password[i])) {
            mask |= 0b100;
        } else if (isdigit(password[i])) {
            mask |= 0b10;
        } else {
            mask |= 0b1;
        }
        prev = password[i];
    }
    return mask == 0b1111;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
