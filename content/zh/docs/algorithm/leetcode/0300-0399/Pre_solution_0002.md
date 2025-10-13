---
title: "0310_最小高度树"
date: 2025-10-08T18:35:54+08:00
weight: 2
tags: [二分查找, 二叉树, 位运算, 分治, 动态规划, 单调栈, 哈希表, 图, 字符串, 广度优先搜索, 归并排序, 拓扑排序, 排序, 数学, 数组, 有序集合, 栈, 树, 树状数组, 深度优先搜索, 矩阵, 线段树, 脑筋急转弯, 贪心]
---

{{< markmap >}}
### [0310_最小高度树](#310)
#### [深度优先搜索](#310)
#### [广度优先搜索](#310)
#### [图](#310)
#### [拓扑排序](#310)
### [0311_稀疏矩阵的乘法 🔒](#311)
#### [数组](#311)
#### [哈希表](#311)
#### [矩阵](#311)
### [0312_戳气球](#312)
#### [数组](#312)
#### [动态规划](#312)
### [0313_超级丑数](#313)
#### [数组](#313)
#### [数学](#313)
#### [动态规划](#313)
### [0314_二叉树的垂直遍历 🔒](#314)
#### [树](#314)
#### [深度优先搜索](#314)
#### [广度优先搜索](#314)
#### [哈希表](#314)
#### [二叉树](#314)
#### [排序](#314)
### [0315_计算右侧小于当前元素的个数](#315)
#### [树状数组](#315)
#### [线段树](#315)
#### [数组](#315)
#### [二分查找](#315)
#### [分治](#315)
#### [有序集合](#315)
#### [归并排序](#315)
### [0316_去除重复字母](#316)
#### [栈](#316)
#### [贪心](#316)
#### [字符串](#316)
#### [单调栈](#316)
### [0317_离建筑物最近的距离 🔒](#317)
#### [广度优先搜索](#317)
#### [数组](#317)
#### [矩阵](#317)
### [0318_最大单词长度乘积](#318)
#### [位运算](#318)
#### [数组](#318)
#### [字符串](#318)
### [0319_灯泡开关](#319)
#### [脑筋急转弯](#319)
#### [数学](#319)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0310_最小高度树
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 图
___
#### 拓扑排序
---
### 0311_稀疏矩阵的乘法 🔒
___
#### 数组
___
#### 哈希表
___
#### 矩阵
---
### 0312_戳气球
___
#### 数组
___
#### 动态规划
---
### 0313_超级丑数
___
#### 数组
___
#### 数学
___
#### 动态规划
---
### 0314_二叉树的垂直遍历 🔒
___
#### 树
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 哈希表
___
#### 二叉树
___
#### 排序
---
### 0315_计算右侧小于当前元素的个数
___
#### 树状数组
___
#### 线段树
___
#### 数组
___
#### 二分查找
___
#### 分治
___
#### 有序集合
___
#### 归并排序
---
### 0316_去除重复字母
___
#### 栈
___
#### 贪心
___
#### 字符串
___
#### 单调栈
---
### 0317_离建筑物最近的距离 🔒
___
#### 广度优先搜索
___
#### 数组
___
#### 矩阵
---
### 0318_最大单词长度乘积
___
#### 位运算
___
#### 数组
___
#### 字符串
---
### 0319_灯泡开关
___
#### 脑筋急转弯
___
#### 数学
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 二叉树 | 位运算 |
| 分治 | 动态规划 | 单调栈 |
| 哈希表 | 图 | 字符串 |
| 广度优先搜索 | 归并排序 | 拓扑排序 |
| 排序 | 数学 | 数组 |
| 有序集合 | 栈 | 树 |
| 树状数组 | 深度优先搜索 | 矩阵 |
| 线段树 | 脑筋急转弯 | 贪心 |

# [310. 最小高度树](https://leetcode.cn/problems/minimum-height-trees){#310}

{{< tabs "310" >}}

{{% tab "python" %}}
```python
class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        if n == 1:
            return [0]
        g = [[] for _ in range(n)]
        degree = [0] * n
        for a, b in edges:
            g[a].append(b)
            g[b].append(a)
            degree[a] += 1
            degree[b] += 1
        q = deque(i for i in range(n) if degree[i] == 1)
        ans = []
        while q:
            ans.clear()
            for _ in range(len(q)):
                a = q.popleft()
                ans.append(a)
                for b in g[a]:
                    degree[b] -= 1
                    if degree[b] == 1:
                        q.append(b)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
        if (n == 1) {
            return List.of(0);
        }
        List<Integer>[] g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        int[] degree = new int[n];
        for (int[] e : edges) {
            int a = e[0], b = e[1];
            g[a].add(b);
            g[b].add(a);
            ++degree[a];
            ++degree[b];
        }
        Deque<Integer> q = new ArrayDeque<>();
        for (int i = 0; i < n; ++i) {
            if (degree[i] == 1) {
                q.offer(i);
            }
        }
        List<Integer> ans = new ArrayList<>();
        while (!q.isEmpty()) {
            ans.clear();
            for (int i = q.size(); i > 0; --i) {
                int a = q.poll();
                ans.add(a);
                for (int b : g[a]) {
                    if (--degree[b] == 1) {
                        q.offer(b);
                    }
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
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) {
            return {0};
        }
        vector<vector<int>> g(n);
        vector<int> degree(n);
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            g[a].push_back(b);
            g[b].push_back(a);
            ++degree[a];
            ++degree[b];
        }
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (degree[i] == 1) {
                q.push(i);
            }
        }
        vector<int> ans;
        while (!q.empty()) {
            ans.clear();
            for (int i = q.size(); i > 0; --i) {
                int a = q.front();
                q.pop();
                ans.push_back(a);
                for (int b : g[a]) {
                    if (--degree[b] == 1) {
                        q.push(b);
                    }
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
func findMinHeightTrees(n int, edges [][]int) (ans []int) {
	if n == 1 {
		return []int{0}
	}
	g := make([][]int, n)
	degree := make([]int, n)
	for _, e := range edges {
		a, b := e[0], e[1]
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
		degree[a]++
		degree[b]++
	}
	q := []int{}
	for i, d := range degree {
		if d == 1 {
			q = append(q, i)
		}
	}
	for len(q) > 0 {
		ans = []int{}
		for i := len(q); i > 0; i-- {
			a := q[0]
			q = q[1:]
			ans = append(ans, a)
			for _, b := range g[a] {
				degree[b]--
				if degree[b] == 1 {
					q = append(q, b)
				}
			}
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findMinHeightTrees(n: number, edges: number[][]): number[] {
    if (n === 1) {
        return [0];
    }
    const g: number[][] = Array.from({ length: n }, () => []);
    const degree: number[] = Array(n).fill(0);
    for (const [a, b] of edges) {
        g[a].push(b);
        g[b].push(a);
        ++degree[a];
        ++degree[b];
    }
    const q: number[] = [];
    for (let i = 0; i < n; ++i) {
        if (degree[i] === 1) {
            q.push(i);
        }
    }
    const ans: number[] = [];
    while (q.length > 0) {
        ans.length = 0;
        const t: number[] = [];
        for (const a of q) {
            ans.push(a);
            for (const b of g[a]) {
                if (--degree[b] === 1) {
                    t.push(b);
                }
            }
        }
        q.splice(0, q.length, ...t);
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

<p>树是一个无向图，其中任何两个顶点只通过一条路径连接。 换句话说，任何一个没有简单环路的连通图都是一棵树。</p>

<p>给你一棵包含&nbsp;<code>n</code>&nbsp;个节点的树，标记为&nbsp;<code>0</code>&nbsp;到&nbsp;<code>n - 1</code> 。给定数字&nbsp;<code>n</code>&nbsp;和一个有 <code>n - 1</code> 条无向边的 <code>edges</code>&nbsp;列表（每一个边都是一对标签），其中 <code>edges[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> 表示树中节点 <code>a<sub>i</sub></code> 和 <code>b<sub>i</sub></code> 之间存在一条无向边。</p>

<p>可选择树中任何一个节点作为根。当选择节点 <code>x</code> 作为根节点时，设结果树的高度为 <code>h</code> 。在所有可能的树中，具有最小高度的树（即，<code>min(h)</code>）被称为 <strong>最小高度树</strong> 。</p>

<p>请你找到所有的 <strong>最小高度树</strong> 并按 <strong>任意顺序</strong> 返回它们的根节点标签列表。</p>
树的 <strong>高度</strong> 是指根节点和叶子节点之间最长向下路径上边的数量。

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0300-0399/0310.Minimum%20Height%20Trees/images/e1.jpg" style="height: 213px; width: 800px;" />
<pre>
<strong>输入：</strong>n = 4, edges = [[1,0],[1,2],[1,3]]
<strong>输出：</strong>[1]
<strong>解释：</strong>如图所示，当根是标签为 1 的节点时，树的高度是 1 ，这是唯一的最小高度树。</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0300-0399/0310.Minimum%20Height%20Trees/images/e2.jpg" style="height: 321px; width: 800px;" />
<pre>
<strong>输入：</strong>n = 6, edges = [[3,0],[3,1],[3,2],[3,4],[5,4]]
<strong>输出：</strong>[3,4]
</pre>

<p>&nbsp;</p>

<ul>
</ul>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>edges.length == n - 1</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt; n</code></li>
	<li><code>a<sub>i</sub> != b<sub>i</sub></code></li>
	<li>所有 <code>(a<sub>i</sub>, b<sub>i</sub>)</code> 互不相同</li>
	<li>给定的输入 <strong>保证</strong> 是一棵树，并且 <strong>不会有重复的边</strong></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：拓扑排序

如果这棵树只有一个节点，那么这个节点就是最小高度树的根节点，直接返回这个节点即可。

如果这棵树有多个节点，那么一定存在叶子节点。叶子节点是只有一个相邻节点的节点。我们可以利用拓扑排序，从外向内剥离叶子节点，当我们到达最后一层的时候，剩下的节点就是最小高度树的根节点。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为节点数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        if n == 1:
            return [0]
        g = [[] for _ in range(n)]
        degree = [0] * n
        for a, b in edges:
            g[a].append(b)
            g[b].append(a)
            degree[a] += 1
            degree[b] += 1
        q = deque(i for i in range(n) if degree[i] == 1)
        ans = []
        while q:
            ans.clear()
            for _ in range(len(q)):
                a = q.popleft()
                ans.append(a)
                for b in g[a]:
                    degree[b] -= 1
                    if degree[b] == 1:
                        q.append(b)
        return ans
```

#### Java

```java
class Solution {
    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
        if (n == 1) {
            return List.of(0);
        }
        List<Integer>[] g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        int[] degree = new int[n];
        for (int[] e : edges) {
            int a = e[0], b = e[1];
            g[a].add(b);
            g[b].add(a);
            ++degree[a];
            ++degree[b];
        }
        Deque<Integer> q = new ArrayDeque<>();
        for (int i = 0; i < n; ++i) {
            if (degree[i] == 1) {
                q.offer(i);
            }
        }
        List<Integer> ans = new ArrayList<>();
        while (!q.isEmpty()) {
            ans.clear();
            for (int i = q.size(); i > 0; --i) {
                int a = q.poll();
                ans.add(a);
                for (int b : g[a]) {
                    if (--degree[b] == 1) {
                        q.offer(b);
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
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) {
            return {0};
        }
        vector<vector<int>> g(n);
        vector<int> degree(n);
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            g[a].push_back(b);
            g[b].push_back(a);
            ++degree[a];
            ++degree[b];
        }
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (degree[i] == 1) {
                q.push(i);
            }
        }
        vector<int> ans;
        while (!q.empty()) {
            ans.clear();
            for (int i = q.size(); i > 0; --i) {
                int a = q.front();
                q.pop();
                ans.push_back(a);
                for (int b : g[a]) {
                    if (--degree[b] == 1) {
                        q.push(b);
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
func findMinHeightTrees(n int, edges [][]int) (ans []int) {
	if n == 1 {
		return []int{0}
	}
	g := make([][]int, n)
	degree := make([]int, n)
	for _, e := range edges {
		a, b := e[0], e[1]
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
		degree[a]++
		degree[b]++
	}
	q := []int{}
	for i, d := range degree {
		if d == 1 {
			q = append(q, i)
		}
	}
	for len(q) > 0 {
		ans = []int{}
		for i := len(q); i > 0; i-- {
			a := q[0]
			q = q[1:]
			ans = append(ans, a)
			for _, b := range g[a] {
				degree[b]--
				if degree[b] == 1 {
					q = append(q, b)
				}
			}
		}
	}
	return
}
```

#### TypeScript

```ts
function findMinHeightTrees(n: number, edges: number[][]): number[] {
    if (n === 1) {
        return [0];
    }
    const g: number[][] = Array.from({ length: n }, () => []);
    const degree: number[] = Array(n).fill(0);
    for (const [a, b] of edges) {
        g[a].push(b);
        g[b].push(a);
        ++degree[a];
        ++degree[b];
    }
    const q: number[] = [];
    for (let i = 0; i < n; ++i) {
        if (degree[i] === 1) {
            q.push(i);
        }
    }
    const ans: number[] = [];
    while (q.length > 0) {
        ans.length = 0;
        const t: number[] = [];
        for (const a of q) {
            ans.push(a);
            for (const b of g[a]) {
                if (--degree[b] === 1) {
                    t.push(b);
                }
            }
        }
        q.splice(0, q.length, ...t);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [311. 稀疏矩阵的乘法 🔒](https://leetcode.cn/problems/sparse-matrix-multiplication){#311}

{{< tabs "311" >}}

{{% tab "python" %}}
```python
class Solution:
    def multiply(self, mat1: List[List[int]], mat2: List[List[int]]) -> List[List[int]]:
        def f(mat: List[List[int]]) -> List[List[int]]:
            g = [[] for _ in range(len(mat))]
            for i, row in enumerate(mat):
                for j, x in enumerate(row):
                    if x:
                        g[i].append((j, x))
            return g

        g1 = f(mat1)
        g2 = f(mat2)
        m, n = len(mat1), len(mat2[0])
        ans = [[0] * n for _ in range(m)]
        for i in range(m):
            for k, x in g1[i]:
                for j, y in g2[k]:
                    ans[i][j] += x * y
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[][] multiply(int[][] mat1, int[][] mat2) {
        int m = mat1.length, n = mat2[0].length;
        int[][] ans = new int[m][n];
        var g1 = f(mat1);
        var g2 = f(mat2);
        for (int i = 0; i < m; ++i) {
            for (int[] p : g1[i]) {
                int k = p[0], x = p[1];
                for (int[] q : g2[k]) {
                    int j = q[0], y = q[1];
                    ans[i][j] += x * y;
                }
            }
        }
        return ans;
    }

    private List<int[]>[] f(int[][] mat) {
        int m = mat.length, n = mat[0].length;
        List<int[]>[] g = new List[m];
        Arrays.setAll(g, i -> new ArrayList<>());
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] != 0) {
                    g[i].add(new int[] {j, mat[i][j]});
                }
            }
        }
        return g;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int m = mat1.size(), n = mat2[0].size();
        vector<vector<int>> ans(m, vector<int>(n));
        auto g1 = f(mat1), g2 = f(mat2);
        for (int i = 0; i < m; ++i) {
            for (auto& [k, x] : g1[i]) {
                for (auto& [j, y] : g2[k]) {
                    ans[i][j] += x * y;
                }
            }
        }
        return ans;
    }

    vector<vector<pair<int, int>>> f(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<pair<int, int>>> g(m);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j]) {
                    g[i].emplace_back(j, mat[i][j]);
                }
            }
        }
        return g;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func multiply(mat1 [][]int, mat2 [][]int) [][]int {
	m, n := len(mat1), len(mat2[0])
	ans := make([][]int, m)
	for i := range ans {
		ans[i] = make([]int, n)
	}
	f := func(mat [][]int) [][][2]int {
		m, n := len(mat), len(mat[0])
		g := make([][][2]int, m)
		for i := range g {
			g[i] = make([][2]int, 0, n)
			for j := range mat[i] {
				if mat[i][j] != 0 {
					g[i] = append(g[i], [2]int{j, mat[i][j]})
				}
			}
		}
		return g
	}
	g1, g2 := f(mat1), f(mat2)
	for i := range g1 {
		for _, p := range g1[i] {
			k, x := p[0], p[1]
			for _, q := range g2[k] {
				j, y := q[0], q[1]
				ans[i][j] += x * y
			}
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function multiply(mat1: number[][], mat2: number[][]): number[][] {
    const [m, n] = [mat1.length, mat2[0].length];
    const ans: number[][] = Array.from({ length: m }, () => Array.from({ length: n }, () => 0));
    const f = (mat: number[][]): number[][][] => {
        const [m, n] = [mat.length, mat[0].length];
        const ans: number[][][] = Array.from({ length: m }, () => []);
        for (let i = 0; i < m; ++i) {
            for (let j = 0; j < n; ++j) {
                if (mat[i][j] !== 0) {
                    ans[i].push([j, mat[i][j]]);
                }
            }
        }
        return ans;
    };
    const g1 = f(mat1);
    const g2 = f(mat2);
    for (let i = 0; i < m; ++i) {
        for (const [k, x] of g1[i]) {
            for (const [j, y] of g2[k]) {
                ans[i][j] += x * y;
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

<p>给定两个&nbsp;<a href="https://baike.baidu.com/item/%E7%A8%80%E7%96%8F%E7%9F%A9%E9%98%B5" target="_blank">稀疏矩阵</a>&nbsp;：大小为 <code>m x k</code> 的稀疏矩阵 <code>mat1</code> 和大小为 <code>k x n</code> 的稀疏矩阵 <code>mat2</code> ，返回 <code>mat1 x mat2</code> 的结果。你可以假设乘法总是可能的。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0300-0399/0311.Sparse%20Matrix%20Multiplication/images/mult-grid.jpg" style="height: 142px; width: 500px;" /></p>

<pre>
<strong>输入：</strong>mat1 = [[1,0,0],[-1,0,3]], mat2 = [[7,0,0],[0,0,0],[0,0,1]]
<strong>输出：</strong>[[7,0,0],[-7,0,3]]
</pre>

<p><strong>&nbsp;示例 2:</strong></p>

<pre>
<b>输入：</b>mat1 = [[0]], mat2 = [[0]]
<b>输出：</b>[[0]]
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>m == mat1.length</code></li>
	<li><code>k == mat1[i].length == mat2.length</code></li>
	<li><code>n == mat2[i].length</code></li>
	<li><code>1 &lt;= m, n, k &lt;= 100</code></li>
	<li><code>-100 &lt;= mat1[i][j], mat2[i][j] &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：直接相乘

我们可以直接按照矩阵乘法的定义，计算出结果矩阵中的每一个元素。

时间复杂度 $O(m \times n \times k)$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别是矩阵 $mat1$ 的行数和矩阵 $mat2$ 的列数，而 $k$ 是矩阵 $mat1$ 的列数或矩阵 $mat2$ 的行数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def multiply(self, mat1: List[List[int]], mat2: List[List[int]]) -> List[List[int]]:
        m, n = len(mat1), len(mat2[0])
        ans = [[0] * n for _ in range(m)]
        for i in range(m):
            for j in range(n):
                for k in range(len(mat2)):
                    ans[i][j] += mat1[i][k] * mat2[k][j]
        return ans
```

#### Java

```java
class Solution {
    public int[][] multiply(int[][] mat1, int[][] mat2) {
        int m = mat1.length, n = mat2[0].length;
        int[][] ans = new int[m][n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < mat2.length; ++k) {
                    ans[i][j] += mat1[i][k] * mat2[k][j];
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
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int m = mat1.size(), n = mat2[0].size();
        vector<vector<int>> ans(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < mat2.size(); ++k) {
                    ans[i][j] += mat1[i][k] * mat2[k][j];
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func multiply(mat1 [][]int, mat2 [][]int) [][]int {
	m, n := len(mat1), len(mat2[0])
	ans := make([][]int, m)
	for i := range ans {
		ans[i] = make([]int, n)
	}
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			for k := 0; k < len(mat2); k++ {
				ans[i][j] += mat1[i][k] * mat2[k][j]
			}
		}
	}
	return ans
}
```

#### TypeScript

```ts
function multiply(mat1: number[][], mat2: number[][]): number[][] {
    const [m, n] = [mat1.length, mat2[0].length];
    const ans: number[][] = Array.from({ length: m }, () => Array.from({ length: n }, () => 0));
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            for (let k = 0; k < mat2.length; ++k) {
                ans[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：预处理

我们可以预处理出两个矩阵的稀疏表示，即 $g1[i]$ 表示矩阵 $mat1$ 第 $i$ 行中所有非零元素的列下标和值，而 $g2[i]$ 表示矩阵 $mat2$ 第 $i$ 行中所有非零元素的列下标和值。

接下来，我们遍历每一行 $i$，遍历 $g1[i]$ 中的每一个元素 $(k, x)$，遍历 $g2[k]$ 中的每一个元素 $(j, y)$，那么最终 $mat1[i][k] \times mat2[k][j]$ 就会对应到结果矩阵中的 $ans[i][j]$，我们将所有的结果累加即可。

时间复杂度 $O(m \times n \times k)$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别是矩阵 $mat1$ 的行数和矩阵 $mat2$ 的列数，而 $k$ 是矩阵 $mat1$ 的列数或矩阵 $mat2$ 的行数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def multiply(self, mat1: List[List[int]], mat2: List[List[int]]) -> List[List[int]]:
        def f(mat: List[List[int]]) -> List[List[int]]:
            g = [[] for _ in range(len(mat))]
            for i, row in enumerate(mat):
                for j, x in enumerate(row):
                    if x:
                        g[i].append((j, x))
            return g

        g1 = f(mat1)
        g2 = f(mat2)
        m, n = len(mat1), len(mat2[0])
        ans = [[0] * n for _ in range(m)]
        for i in range(m):
            for k, x in g1[i]:
                for j, y in g2[k]:
                    ans[i][j] += x * y
        return ans
```

#### Java

```java
class Solution {
    public int[][] multiply(int[][] mat1, int[][] mat2) {
        int m = mat1.length, n = mat2[0].length;
        int[][] ans = new int[m][n];
        var g1 = f(mat1);
        var g2 = f(mat2);
        for (int i = 0; i < m; ++i) {
            for (int[] p : g1[i]) {
                int k = p[0], x = p[1];
                for (int[] q : g2[k]) {
                    int j = q[0], y = q[1];
                    ans[i][j] += x * y;
                }
            }
        }
        return ans;
    }

    private List<int[]>[] f(int[][] mat) {
        int m = mat.length, n = mat[0].length;
        List<int[]>[] g = new List[m];
        Arrays.setAll(g, i -> new ArrayList<>());
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] != 0) {
                    g[i].add(new int[] {j, mat[i][j]});
                }
            }
        }
        return g;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int m = mat1.size(), n = mat2[0].size();
        vector<vector<int>> ans(m, vector<int>(n));
        auto g1 = f(mat1), g2 = f(mat2);
        for (int i = 0; i < m; ++i) {
            for (auto& [k, x] : g1[i]) {
                for (auto& [j, y] : g2[k]) {
                    ans[i][j] += x * y;
                }
            }
        }
        return ans;
    }

    vector<vector<pair<int, int>>> f(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<pair<int, int>>> g(m);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j]) {
                    g[i].emplace_back(j, mat[i][j]);
                }
            }
        }
        return g;
    }
};
```

#### Go

```go
func multiply(mat1 [][]int, mat2 [][]int) [][]int {
	m, n := len(mat1), len(mat2[0])
	ans := make([][]int, m)
	for i := range ans {
		ans[i] = make([]int, n)
	}
	f := func(mat [][]int) [][][2]int {
		m, n := len(mat), len(mat[0])
		g := make([][][2]int, m)
		for i := range g {
			g[i] = make([][2]int, 0, n)
			for j := range mat[i] {
				if mat[i][j] != 0 {
					g[i] = append(g[i], [2]int{j, mat[i][j]})
				}
			}
		}
		return g
	}
	g1, g2 := f(mat1), f(mat2)
	for i := range g1 {
		for _, p := range g1[i] {
			k, x := p[0], p[1]
			for _, q := range g2[k] {
				j, y := q[0], q[1]
				ans[i][j] += x * y
			}
		}
	}
	return ans
}
```

#### TypeScript

```ts
function multiply(mat1: number[][], mat2: number[][]): number[][] {
    const [m, n] = [mat1.length, mat2[0].length];
    const ans: number[][] = Array.from({ length: m }, () => Array.from({ length: n }, () => 0));
    const f = (mat: number[][]): number[][][] => {
        const [m, n] = [mat.length, mat[0].length];
        const ans: number[][][] = Array.from({ length: m }, () => []);
        for (let i = 0; i < m; ++i) {
            for (let j = 0; j < n; ++j) {
                if (mat[i][j] !== 0) {
                    ans[i].push([j, mat[i][j]]);
                }
            }
        }
        return ans;
    };
    const g1 = f(mat1);
    const g2 = f(mat2);
    for (let i = 0; i < m; ++i) {
        for (const [k, x] of g1[i]) {
            for (const [j, y] of g2[k]) {
                ans[i][j] += x * y;
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

# [312. 戳气球](https://leetcode.cn/problems/burst-balloons){#312}

{{< tabs "312" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        n = len(nums)
        arr = [1] + nums + [1]
        f = [[0] * (n + 2) for _ in range(n + 2)]
        for i in range(n - 1, -1, -1):
            for j in range(i + 2, n + 2):
                for k in range(i + 1, j):
                    f[i][j] = max(f[i][j], f[i][k] + f[k][j] + arr[i] * arr[k] * arr[j])
        return f[0][-1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxCoins(int[] nums) {
        int n = nums.length;
        int[] arr = new int[n + 2];
        arr[0] = 1;
        arr[n + 1] = 1;
        System.arraycopy(nums, 0, arr, 1, n);
        int[][] f = new int[n + 2][n + 2];
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 2; j <= n + 1; j++) {
                for (int k = i + 1; k < j; k++) {
                    f[i][j] = Math.max(f[i][j], f[i][k] + f[k][j] + arr[i] * arr[k] * arr[j]);
                }
            }
        }
        return f[0][n + 1];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n + 2, 1);
        for (int i = 0; i < n; ++i) {
            arr[i + 1] = nums[i];
        }

        vector<vector<int>> f(n + 2, vector<int>(n + 2, 0));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 2; j <= n + 1; ++j) {
                for (int k = i + 1; k < j; ++k) {
                    f[i][j] = max(f[i][j], f[i][k] + f[k][j] + arr[i] * arr[k] * arr[j]);
                }
            }
        }
        return f[0][n + 1];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxCoins(nums []int) int {
    n := len(nums)
    arr := make([]int, n+2)
    arr[0] = 1
    arr[n+1] = 1
    copy(arr[1:], nums)

    f := make([][]int, n+2)
    for i := range f {
        f[i] = make([]int, n+2)
    }

    for i := n - 1; i >= 0; i-- {
        for j := i + 2; j <= n+1; j++ {
            for k := i + 1; k < j; k++ {
                f[i][j] = max(f[i][j], f[i][k] + f[k][j] + arr[i]*arr[k]*arr[j])
            }
        }
    }

    return f[0][n+1]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxCoins(nums: number[]): number {
    const n = nums.length;
    const arr = Array(n + 2).fill(1);
    for (let i = 0; i < n; i++) {
        arr[i + 1] = nums[i];
    }

    const f: number[][] = Array.from({ length: n + 2 }, () => Array(n + 2).fill(0));
    for (let i = n - 1; i >= 0; i--) {
        for (let j = i + 2; j <= n + 1; j++) {
            for (let k = i + 1; k < j; k++) {
                f[i][j] = Math.max(f[i][j], f[i][k] + f[k][j] + arr[i] * arr[k] * arr[j]);
            }
        }
    }
    return f[0][n + 1];
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn max_coins(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut arr = vec![1; n + 2];
        for i in 0..n {
            arr[i + 1] = nums[i];
        }

        let mut f = vec![vec![0; n + 2]; n + 2];
        for i in (0..n).rev() {
            for j in i + 2..n + 2 {
                for k in i + 1..j {
                    f[i][j] = f[i][j].max(f[i][k] + f[k][j] + arr[i] * arr[k] * arr[j]);
                }
            }
        }
        f[0][n + 1]
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>有 <code>n</code> 个气球，编号为<code>0</code> 到 <code>n - 1</code>，每个气球上都标有一个数字，这些数字存在数组&nbsp;<code>nums</code>&nbsp;中。</p>

<p>现在要求你戳破所有的气球。戳破第 <code>i</code> 个气球，你可以获得&nbsp;<code>nums[i - 1] * nums[i] * nums[i + 1]</code> 枚硬币。&nbsp;这里的 <code>i - 1</code> 和 <code>i + 1</code> 代表和&nbsp;<code>i</code>&nbsp;相邻的两个气球的序号。如果 <code>i - 1</code>或 <code>i + 1</code> 超出了数组的边界，那么就当它是一个数字为 <code>1</code> 的气球。</p>

<p>求所能获得硬币的最大数量。</p>

<p>&nbsp;</p>
<strong>示例 1：</strong>

<pre>
<strong>输入：</strong>nums = [3,1,5,8]
<strong>输出：</strong>167
<strong>解释：</strong>
nums = [3,1,5,8] --&gt; [3,5,8] --&gt; [3,8] --&gt; [8] --&gt; []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,5]
<strong>输出：</strong>10
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 &lt;= n &lt;= 300</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们记数组 $nums$ 的长度为 $n$。根据题目描述，我们可以在数组 $nums$ 的左右两端各添加一个 $1$，记为 $arr$。

然后，我们定义 $f[i][j]$ 表示戳破区间 $[i, j]$ 内的所有气球能得到的最多硬币数，那么答案即为 $f[0][n+1]$。

对于 $f[i][j]$，我们枚举区间 $[i, j]$ 内的所有位置 $k$，假设 $k$ 是最后一个戳破的气球，那么我们可以得到如下状态转移方程：

$$
f[i][j] = \max(f[i][j], f[i][k] + f[k][j] + arr[i] \times arr[k] \times arr[j])
$$

在实现上，由于 $f[i][j]$ 的状态转移方程中涉及到 $f[i][k]$ 和 $f[k][j]$，其中 $i < k < j$，因此我们需要从大到小地遍历 $i$，从小到大地遍历 $j$，这样才能保证当计算 $f[i][j]$ 时 $f[i][k]$ 和 $f[k][j]$ 已经被计算出来。

最后，我们返回 $f[0][n+1]$ 即可。

时间复杂度 $O(n^3)$，空间复杂度 $O(n^2)$。其中 $n$ 为数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        n = len(nums)
        arr = [1] + nums + [1]
        f = [[0] * (n + 2) for _ in range(n + 2)]
        for i in range(n - 1, -1, -1):
            for j in range(i + 2, n + 2):
                for k in range(i + 1, j):
                    f[i][j] = max(f[i][j], f[i][k] + f[k][j] + arr[i] * arr[k] * arr[j])
        return f[0][-1]
```

#### Java

```java
class Solution {
    public int maxCoins(int[] nums) {
        int n = nums.length;
        int[] arr = new int[n + 2];
        arr[0] = 1;
        arr[n + 1] = 1;
        System.arraycopy(nums, 0, arr, 1, n);
        int[][] f = new int[n + 2][n + 2];
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 2; j <= n + 1; j++) {
                for (int k = i + 1; k < j; k++) {
                    f[i][j] = Math.max(f[i][j], f[i][k] + f[k][j] + arr[i] * arr[k] * arr[j]);
                }
            }
        }
        return f[0][n + 1];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n + 2, 1);
        for (int i = 0; i < n; ++i) {
            arr[i + 1] = nums[i];
        }

        vector<vector<int>> f(n + 2, vector<int>(n + 2, 0));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 2; j <= n + 1; ++j) {
                for (int k = i + 1; k < j; ++k) {
                    f[i][j] = max(f[i][j], f[i][k] + f[k][j] + arr[i] * arr[k] * arr[j]);
                }
            }
        }
        return f[0][n + 1];
    }
};
```

#### Go

```go
func maxCoins(nums []int) int {
    n := len(nums)
    arr := make([]int, n+2)
    arr[0] = 1
    arr[n+1] = 1
    copy(arr[1:], nums)

    f := make([][]int, n+2)
    for i := range f {
        f[i] = make([]int, n+2)
    }

    for i := n - 1; i >= 0; i-- {
        for j := i + 2; j <= n+1; j++ {
            for k := i + 1; k < j; k++ {
                f[i][j] = max(f[i][j], f[i][k] + f[k][j] + arr[i]*arr[k]*arr[j])
            }
        }
    }

    return f[0][n+1]
}
```

#### TypeScript

```ts
function maxCoins(nums: number[]): number {
    const n = nums.length;
    const arr = Array(n + 2).fill(1);
    for (let i = 0; i < n; i++) {
        arr[i + 1] = nums[i];
    }

    const f: number[][] = Array.from({ length: n + 2 }, () => Array(n + 2).fill(0));
    for (let i = n - 1; i >= 0; i--) {
        for (let j = i + 2; j <= n + 1; j++) {
            for (let k = i + 1; k < j; k++) {
                f[i][j] = Math.max(f[i][j], f[i][k] + f[k][j] + arr[i] * arr[k] * arr[j]);
            }
        }
    }
    return f[0][n + 1];
}
```

#### Rust

```rust
impl Solution {
    pub fn max_coins(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut arr = vec![1; n + 2];
        for i in 0..n {
            arr[i + 1] = nums[i];
        }

        let mut f = vec![vec![0; n + 2]; n + 2];
        for i in (0..n).rev() {
            for j in i + 2..n + 2 {
                for k in i + 1..j {
                    f[i][j] = f[i][j].max(f[i][k] + f[k][j] + arr[i] * arr[k] * arr[j]);
                }
            }
        }
        f[0][n + 1]
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [313. 超级丑数](https://leetcode.cn/problems/super-ugly-number){#313}

{{< tabs "313" >}}

{{% tab "python" %}}
```python
class Solution:
    def nthSuperUglyNumber(self, n: int, primes: List[int]) -> int:
        q = [1]
        x = 0
        mx = (1 << 31) - 1
        for _ in range(n):
            x = heappop(q)
            for k in primes:
                if x <= mx // k:
                    heappush(q, k * x)
                if x % k == 0:
                    break
        return x
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int nthSuperUglyNumber(int n, int[] primes) {
        PriorityQueue<Integer> q = new PriorityQueue<>();
        q.offer(1);
        int x = 0;
        while (n-- > 0) {
            x = q.poll();
            while (!q.isEmpty() && q.peek() == x) {
                q.poll();
            }
            for (int k : primes) {
                if (k <= Integer.MAX_VALUE / x) {
                    q.offer(k * x);
                }
                if (x % k == 0) {
                    break;
                }
            }
        }
        return x;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue<int, vector<int>, greater<int>> q;
        q.push(1);
        int x = 0;
        while (n--) {
            x = q.top();
            q.pop();
            for (int& k : primes) {
                if (x <= INT_MAX / k) {
                    q.push(k * x);
                }
                if (x % k == 0) {
                    break;
                }
            }
        }
        return x;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
type Ugly struct{ value, prime, index int }
type Queue []Ugly

func (u Queue) Len() int           { return len(u) }
func (u Queue) Swap(i, j int)      { u[i], u[j] = u[j], u[i] }
func (u Queue) Less(i, j int) bool { return u[i].value < u[j].value }
func (u *Queue) Push(v any)        { *u = append(*u, v.(Ugly)) }
func (u *Queue) Pop() any {
	old, x := *u, (*u)[len(*u)-1]
	*u = old[:len(old)-1]
	return x
}

func nthSuperUglyNumber(n int, primes []int) int {
	ugly, pq, p := make([]int, n+1), &Queue{}, 2
	ugly[1] = 1
	heap.Init(pq)
	for _, v := range primes {
		heap.Push(pq, Ugly{value: v, prime: v, index: 2})
	}
	for p <= n {
		top := heap.Pop(pq).(Ugly)
		if ugly[p-1] != top.value {
			ugly[p], p = top.value, p+1
		}
		top.value, top.index = ugly[top.index]*top.prime, top.index+1
		heap.Push(pq, top)
	}
	return ugly[n]
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p><strong>超级丑数</strong> 是一个正整数，并满足其所有质因数都出现在质数数组 <code>primes</code> 中。</p>

<p>给你一个整数 <code>n</code> 和一个整数数组 <code>primes</code> ，返回第 <code>n</code> 个 <strong>超级丑数</strong> 。</p>

<p>题目数据保证第 <code>n</code> 个 <strong>超级丑数</strong> 在 <strong>32-bit</strong> 带符号整数范围内。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 12, <code>primes</code> = <code>[2,7,13,19]</code>
<strong>输出：</strong>32 
<strong>解释：</strong>给定长度为 4 的质数数组 primes = [2,7,13,19]，前 12 个超级丑数序列为：[1,2,4,7,8,13,14,16,19,26,28,32] 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 1, primes = [2,3,5]
<strong>输出：</strong>1
<strong>解释：</strong>1 不含质因数，因此它的所有质因数都在质数数组 primes = [2,3,5] 中。
</pre>

&nbsp;

<div class="top-view__1vxA">
<div class="original__bRMd">
<div>
<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= primes.length &lt;= 100</code></li>
	<li><code>2 &lt;= primes[i] &lt;= 1000</code></li>
	<li>题目数据<strong> 保证</strong> <code>primes[i]</code> 是一个质数</li>
	<li><code>primes</code> 中的所有值都 <strong>互不相同</strong> ，且按 <strong>递增顺序</strong> 排列</li>
</ul>
</div>
</div>
</div>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：优先队列（小根堆）

我们用一个优先队列（小根堆）维护所有可能的超级丑数，初始时将 $1$ 放入队列中。

每次从队列中取出最小的超级丑数 $x$，将 $x$ 乘以数组 `primes` 中的每个数，将乘积放入队列中，然后重复上述操作 $n$ 次即可得到第 $n$ 个超级丑数。

由于题目保证第 $n$ 个超级丑数在 $32$ 位带符号整数范围内，因此，我们将乘积放入队列之前，可以先判断乘积是否超过 $2^{31} - 1$，如果超过，则不需要将乘积放入队列中。另外，可以使用欧拉筛优化。

时间复杂度 $O(n \times m \times \log (n \times m))$，空间复杂度 $O(n \times m)$。其中 $m$ 和 $n$ 分别为数组 `primes` 的长度和给定的整数 $n$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def nthSuperUglyNumber(self, n: int, primes: List[int]) -> int:
        q = [1]
        x = 0
        mx = (1 << 31) - 1
        for _ in range(n):
            x = heappop(q)
            for k in primes:
                if x <= mx // k:
                    heappush(q, k * x)
                if x % k == 0:
                    break
        return x
```

#### Java

```java
class Solution {
    public int nthSuperUglyNumber(int n, int[] primes) {
        PriorityQueue<Integer> q = new PriorityQueue<>();
        q.offer(1);
        int x = 0;
        while (n-- > 0) {
            x = q.poll();
            while (!q.isEmpty() && q.peek() == x) {
                q.poll();
            }
            for (int k : primes) {
                if (k <= Integer.MAX_VALUE / x) {
                    q.offer(k * x);
                }
                if (x % k == 0) {
                    break;
                }
            }
        }
        return x;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue<int, vector<int>, greater<int>> q;
        q.push(1);
        int x = 0;
        while (n--) {
            x = q.top();
            q.pop();
            for (int& k : primes) {
                if (x <= INT_MAX / k) {
                    q.push(k * x);
                }
                if (x % k == 0) {
                    break;
                }
            }
        }
        return x;
    }
};
```

#### Go

```go
func nthSuperUglyNumber(n int, primes []int) (x int) {
	q := hp{[]int{1}}
	for n > 0 {
		n--
		x = heap.Pop(&q).(int)
		for _, k := range primes {
			if x <= math.MaxInt32/k {
				heap.Push(&q, k*x)
			}
			if x%k == 0 {
				break
			}
		}
	}
	return
}

type hp struct{ sort.IntSlice }

func (h *hp) Push(v any) { h.IntSlice = append(h.IntSlice, v.(int)) }
func (h *hp) Pop() any {
	a := h.IntSlice
	v := a[len(a)-1]
	h.IntSlice = a[:len(a)-1]
	return v
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### Go

```go
type Ugly struct{ value, prime, index int }
type Queue []Ugly

func (u Queue) Len() int           { return len(u) }
func (u Queue) Swap(i, j int)      { u[i], u[j] = u[j], u[i] }
func (u Queue) Less(i, j int) bool { return u[i].value < u[j].value }
func (u *Queue) Push(v any)        { *u = append(*u, v.(Ugly)) }
func (u *Queue) Pop() any {
	old, x := *u, (*u)[len(*u)-1]
	*u = old[:len(old)-1]
	return x
}

func nthSuperUglyNumber(n int, primes []int) int {
	ugly, pq, p := make([]int, n+1), &Queue{}, 2
	ugly[1] = 1
	heap.Init(pq)
	for _, v := range primes {
		heap.Push(pq, Ugly{value: v, prime: v, index: 2})
	}
	for p <= n {
		top := heap.Pop(pq).(Ugly)
		if ugly[p-1] != top.value {
			ugly[p], p = top.value, p+1
		}
		top.value, top.index = ugly[top.index]*top.prime, top.index+1
		heap.Push(pq, top)
	}
	return ugly[n]
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [314. 二叉树的垂直遍历 🔒](https://leetcode.cn/problems/binary-tree-vertical-order-traversal){#314}

{{< tabs "314" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def verticalOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if root is None:
            return []
        q = deque([(root, 0)])
        d = defaultdict(list)
        while q:
            for _ in range(len(q)):
                root, offset = q.popleft()
                d[offset].append(root.val)
                if root.left:
                    q.append((root.left, offset - 1))
                if root.right:
                    q.append((root.right, offset + 1))
        return [v for _, v in sorted(d.items())]
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
    public List<List<Integer>> verticalOrder(TreeNode root) {
        List<List<Integer>> ans = new ArrayList<>();
        if (root == null) {
            return ans;
        }
        Deque<Pair<TreeNode, Integer>> q = new ArrayDeque<>();
        q.offer(new Pair<>(root, 0));
        TreeMap<Integer, List<Integer>> d = new TreeMap<>();
        while (!q.isEmpty()) {
            for (int n = q.size(); n > 0; --n) {
                var p = q.pollFirst();
                root = p.getKey();
                int offset = p.getValue();
                d.computeIfAbsent(offset, k -> new ArrayList()).add(root.val);
                if (root.left != null) {
                    q.offer(new Pair<>(root.left, offset - 1));
                }
                if (root.right != null) {
                    q.offer(new Pair<>(root.right, offset + 1));
                }
            }
        }
        return new ArrayList<>(d.values());
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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        map<int, vector<int>> d;
        queue<pair<TreeNode*, int>> q{{{root, 0}}};
        while (!q.empty()) {
            for (int n = q.size(); n; --n) {
                auto p = q.front();
                q.pop();
                root = p.first;
                int offset = p.second;
                d[offset].push_back(root->val);
                if (root->left) q.push({root->left, offset - 1});
                if (root->right) q.push({root->right, offset + 1});
            }
        }
        for (auto& [_, v] : d) {
            ans.push_back(v);
        }
        return ans;
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
func verticalOrder(root *TreeNode) [][]int {
	ans := [][]int{}
	if root == nil {
		return ans
	}
	d := map[int][]int{}
	q := []pair{pair{root, 0}}
	for len(q) > 0 {
		for n := len(q); n > 0; n-- {
			p := q[0]
			q = q[1:]
			root = p.node
			offset := p.offset
			d[offset] = append(d[offset], root.Val)
			if root.Left != nil {
				q = append(q, pair{root.Left, offset - 1})
			}
			if root.Right != nil {
				q = append(q, pair{root.Right, offset + 1})
			}
		}
	}
	idx := []int{}
	for i := range d {
		idx = append(idx, i)
	}
	sort.Ints(idx)
	for _, i := range idx {
		ans = append(ans, d[i])
	}
	return ans
}

type pair struct {
	node   *TreeNode
	offset int
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个二叉树的根结点，返回其结点按 <strong>垂直方向</strong>（从上到下，逐列）遍历的结果。</p>

<p>如果两个结点在同一行和列，那么顺序则为&nbsp;<strong>从左到右</strong>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0300-0399/0314.Binary%20Tree%20Vertical%20Order%20Traversal/images/1727276130-UOKFsu-image.png" style="width: 400px; height: 273px;" />
<pre>
<strong>输入：</strong>root = [3,9,20,null,null,15,7]
<strong>输出：</strong>[[9],[3,15],[20],[7]]
</pre>

<p><strong class="example">示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0300-0399/0314.Binary%20Tree%20Vertical%20Order%20Traversal/images/1727276212-bzuKab-image.png" style="width: 400px; height: 253px;" />
<pre>
<strong>输入：</strong>root = [3,9,8,4,0,1,7]
<strong>输出：</strong>[[4],[9],[3,0,1],[8],[7]]
</pre>

<p><strong class="example">示例 3：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0300-0399/0314.Binary%20Tree%20Vertical%20Order%20Traversal/images/1727276242-EGdtNz-image.png" style="width: 400px; height: 391px;" />
<pre>
<strong>输入：</strong>root = [1,2,3,4,10,9,11,null,5,null,null,null,null,null,null,null,6]
<strong>输出：</strong>[[4],[2,5],[1,10,9,6],[3],[11]]</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中结点的数目在范围 <code>[0, 100]</code> 内</li>
	<li><code>-100 &lt;= Node.val &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS

DFS 遍历二叉树，记录每个节点的值、深度，以及横向的偏移量。然后对所有节点按照横向偏移量从小到大排序，再按照深度从小到大排序，最后按照横向偏移量分组。

时间复杂度 $O(n\log \log n)$，空间复杂度 $O(n)$。其中 $n$ 为二叉树的节点个数。

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
    def verticalOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        def dfs(root, depth, offset):
            if root is None:
                return
            d[offset].append((depth, root.val))
            dfs(root.left, depth + 1, offset - 1)
            dfs(root.right, depth + 1, offset + 1)

        d = defaultdict(list)
        dfs(root, 0, 0)
        ans = []
        for _, v in sorted(d.items()):
            v.sort(key=lambda x: x[0])
            ans.append([x[1] for x in v])
        return ans
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
    private TreeMap<Integer, List<int[]>> d = new TreeMap<>();

    public List<List<Integer>> verticalOrder(TreeNode root) {
        dfs(root, 0, 0);
        List<List<Integer>> ans = new ArrayList<>();
        for (var v : d.values()) {
            Collections.sort(v, (a, b) -> a[0] - b[0]);
            List<Integer> t = new ArrayList<>();
            for (var e : v) {
                t.add(e[1]);
            }
            ans.add(t);
        }
        return ans;
    }

    private void dfs(TreeNode root, int depth, int offset) {
        if (root == null) {
            return;
        }
        d.computeIfAbsent(offset, k -> new ArrayList<>()).add(new int[] {depth, root.val});
        dfs(root.left, depth + 1, offset - 1);
        dfs(root.right, depth + 1, offset + 1);
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
using pii = pair<int, int>;

class Solution {
public:
    map<int, vector<pii>> d;

    vector<vector<int>> verticalOrder(TreeNode* root) {
        dfs(root, 0, 0);
        vector<vector<int>> ans;
        for (auto& [_, v] : d) {
            sort(v.begin(), v.end(), [&](pii& a, pii& b) {
                return a.first < b.first;
            });
            vector<int> t;
            for (auto& x : v) {
                t.push_back(x.second);
            }
            ans.push_back(t);
        }
        return ans;
    }

    void dfs(TreeNode* root, int depth, int offset) {
        if (!root) return;
        d[offset].push_back({depth, root->val});
        dfs(root->left, depth + 1, offset - 1);
        dfs(root->right, depth + 1, offset + 1);
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
func verticalOrder(root *TreeNode) [][]int {
	d := map[int][][]int{}
	var dfs func(*TreeNode, int, int)
	dfs = func(root *TreeNode, depth, offset int) {
		if root == nil {
			return
		}
		d[offset] = append(d[offset], []int{depth, root.Val})
		dfs(root.Left, depth+1, offset-1)
		dfs(root.Right, depth+1, offset+1)
	}
	dfs(root, 0, 0)
	idx := []int{}
	for i := range d {
		idx = append(idx, i)
	}
	sort.Ints(idx)
	ans := [][]int{}
	for _, i := range idx {
		v := d[i]
		sort.SliceStable(v, func(i, j int) bool { return v[i][0] < v[j][0] })
		t := []int{}
		for _, x := range v {
			t = append(t, x[1])
		}
		ans = append(ans, t)
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：BFS

本题较好的做法应该是 BFS，从上往下逐层进行遍历。

时间复杂度 $O(n\log n)$，空间复杂度 $O(n)$。其中 $n$ 是二叉树的结点数。

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
    def verticalOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if root is None:
            return []
        q = deque([(root, 0)])
        d = defaultdict(list)
        while q:
            for _ in range(len(q)):
                root, offset = q.popleft()
                d[offset].append(root.val)
                if root.left:
                    q.append((root.left, offset - 1))
                if root.right:
                    q.append((root.right, offset + 1))
        return [v for _, v in sorted(d.items())]
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
    public List<List<Integer>> verticalOrder(TreeNode root) {
        List<List<Integer>> ans = new ArrayList<>();
        if (root == null) {
            return ans;
        }
        Deque<Pair<TreeNode, Integer>> q = new ArrayDeque<>();
        q.offer(new Pair<>(root, 0));
        TreeMap<Integer, List<Integer>> d = new TreeMap<>();
        while (!q.isEmpty()) {
            for (int n = q.size(); n > 0; --n) {
                var p = q.pollFirst();
                root = p.getKey();
                int offset = p.getValue();
                d.computeIfAbsent(offset, k -> new ArrayList()).add(root.val);
                if (root.left != null) {
                    q.offer(new Pair<>(root.left, offset - 1));
                }
                if (root.right != null) {
                    q.offer(new Pair<>(root.right, offset + 1));
                }
            }
        }
        return new ArrayList<>(d.values());
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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        map<int, vector<int>> d;
        queue<pair<TreeNode*, int>> q{{{root, 0}}};
        while (!q.empty()) {
            for (int n = q.size(); n; --n) {
                auto p = q.front();
                q.pop();
                root = p.first;
                int offset = p.second;
                d[offset].push_back(root->val);
                if (root->left) q.push({root->left, offset - 1});
                if (root->right) q.push({root->right, offset + 1});
            }
        }
        for (auto& [_, v] : d) {
            ans.push_back(v);
        }
        return ans;
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
func verticalOrder(root *TreeNode) [][]int {
	ans := [][]int{}
	if root == nil {
		return ans
	}
	d := map[int][]int{}
	q := []pair{pair{root, 0}}
	for len(q) > 0 {
		for n := len(q); n > 0; n-- {
			p := q[0]
			q = q[1:]
			root = p.node
			offset := p.offset
			d[offset] = append(d[offset], root.Val)
			if root.Left != nil {
				q = append(q, pair{root.Left, offset - 1})
			}
			if root.Right != nil {
				q = append(q, pair{root.Right, offset + 1})
			}
		}
	}
	idx := []int{}
	for i := range d {
		idx = append(idx, i)
	}
	sort.Ints(idx)
	for _, i := range idx {
		ans = append(ans, d[i])
	}
	return ans
}

type pair struct {
	node   *TreeNode
	offset int
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [315. 计算右侧小于当前元素的个数](https://leetcode.cn/problems/count-of-smaller-numbers-after-self){#315}

{{< tabs "315" >}}

{{% tab "python" %}}
```python
class Node:
    def __init__(self):
        self.l = 0
        self.r = 0
        self.v = 0


class SegmentTree:
    def __init__(self, n):
        self.tr = [Node() for _ in range(n << 2)]
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

    def query(self, u, l, r):
        if self.tr[u].l >= l and self.tr[u].r <= r:
            return self.tr[u].v
        mid = (self.tr[u].l + self.tr[u].r) >> 1
        v = 0
        if l <= mid:
            v += self.query(u << 1, l, r)
        if r > mid:
            v += self.query(u << 1 | 1, l, r)
        return v

    def pushup(self, u):
        self.tr[u].v = self.tr[u << 1].v + self.tr[u << 1 | 1].v


class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        s = sorted(set(nums))
        m = {v: i for i, v in enumerate(s, 1)}
        tree = SegmentTree(len(s))
        ans = []
        for v in nums[::-1]:
            x = m[v]
            ans.append(tree.query(1, 1, x - 1))
            tree.modify(1, x, 1)
        return ans[::-1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<Integer> countSmaller(int[] nums) {
        Set<Integer> s = new HashSet<>();
        for (int v : nums) {
            s.add(v);
        }
        List<Integer> alls = new ArrayList<>(s);
        alls.sort(Comparator.comparingInt(a -> a));
        int n = alls.size();
        Map<Integer, Integer> m = new HashMap<>(n);
        for (int i = 0; i < n; ++i) {
            m.put(alls.get(i), i + 1);
        }
        SegmentTree tree = new SegmentTree(n);
        LinkedList<Integer> ans = new LinkedList<>();
        for (int i = nums.length - 1; i >= 0; --i) {
            int x = m.get(nums[i]);
            tree.modify(1, x, 1);
            ans.addFirst(tree.query(1, 1, x - 1));
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
        if (l <= mid) v += query(u << 1, l, r);
        if (r > mid) v += query(u << 1 | 1, l, r);
        return v;
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        vector<int> alls(s.begin(), s.end());
        sort(alls.begin(), alls.end());
        unordered_map<int, int> m;
        int n = alls.size();
        for (int i = 0; i < n; ++i) m[alls[i]] = i + 1;
        SegmentTree* tree = new SegmentTree(n);
        vector<int> ans(nums.size());
        for (int i = nums.size() - 1; i >= 0; --i) {
            int x = m[nums[i]];
            tree->modify(1, x, 1);
            ans[i] = tree->query(1, 1, x - 1);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
type Pair struct {
	val   int
	index int
}

var (
	tmp   []Pair
	count []int
)

func countSmaller(nums []int) []int {
	tmp, count = make([]Pair, len(nums)), make([]int, len(nums))
	array := make([]Pair, len(nums))
	for i, v := range nums {
		array[i] = Pair{val: v, index: i}
	}
	sorted(array, 0, len(array)-1)
	return count
}

func sorted(arr []Pair, low, high int) {
	if low >= high {
		return
	}
	mid := low + (high-low)/2
	sorted(arr, low, mid)
	sorted(arr, mid+1, high)
	merge(arr, low, mid, high)
}

func merge(arr []Pair, low, mid, high int) {
	left, right := low, mid+1
	idx := low
	for left <= mid && right <= high {
		if arr[left].val <= arr[right].val {
			count[arr[left].index] += right - mid - 1
			tmp[idx], left = arr[left], left+1
		} else {
			tmp[idx], right = arr[right], right+1
		}
		idx++
	}
	for left <= mid {
		count[arr[left].index] += right - mid - 1
		tmp[idx] = arr[left]
		idx, left = idx+1, left+1
	}
	for right <= high {
		tmp[idx] = arr[right]
		idx, right = idx+1, right+1
	}
	// 排序
	for i := low; i <= high; i++ {
		arr[i] = tmp[i]
	}
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>nums</code><em> </em>，按要求返回一个新数组&nbsp;<code>counts</code><em> </em>。数组 <code>counts</code> 有该性质： <code>counts[i]</code> 的值是&nbsp; <code>nums[i]</code> 右侧小于&nbsp;<code>nums[i]</code> 的元素的数量。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [5,2,6,1]
<strong>输出：</strong><code>[2,1,1,0] 
<strong>解释：</strong></code>
5 的右侧有 <strong>2 </strong>个更小的元素 (2 和 1)
2 的右侧仅有 <strong>1 </strong>个更小的元素 (1)
6 的右侧有 <strong>1 </strong>个更小的元素 (1)
1 的右侧有 <strong>0 </strong>个更小的元素
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [-1]
<strong>输出：</strong>[0]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [-1,-1]
<strong>输出：</strong>[0,0]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：树状数组

树状数组，也称作“二叉索引树”（Binary Indexed Tree）或 Fenwick 树。 它可以高效地实现如下两个操作：

1. **单点更新** `update(x, delta)`： 把序列 x 位置的数加上一个值 delta；
1. **前缀和查询** `query(x)`：查询序列 `[1,...x]` 区间的区间和，即位置 x 的前缀和。

这两个操作的时间复杂度均为 $O(\log n)$。

树状数组最基本的功能就是求比某点 x 小的点的个数（这里的比较是抽象的概念，可以是数的大小、坐标的大小、质量的大小等等）。

比如给定数组 `a[5] = {2, 5, 3, 4, 1}`，求 `b[i] = 位置 i 左边小于等于 a[i] 的数的个数`。对于此例，`b[5] = {0, 1, 1, 2, 0}`。

解决方案是直接遍历数组，每个位置先求出 `query(a[i])`，然后再修改树状数组 `update(a[i], 1)` 即可。当数的范围比较大时，需要进行离散化，即先进行去重并排序，然后对每个数字进行编号。

<!-- tabs:start -->

#### Python3

```python
class BinaryIndexedTree:
    def __init__(self, n):
        self.n = n
        self.c = [0] * (n + 1)

    @staticmethod
    def lowbit(x):
        return x & -x

    def update(self, x, delta):
        while x <= self.n:
            self.c[x] += delta
            x += BinaryIndexedTree.lowbit(x)

    def query(self, x):
        s = 0
        while x > 0:
            s += self.c[x]
            x -= BinaryIndexedTree.lowbit(x)
        return s


class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        alls = sorted(set(nums))
        m = {v: i for i, v in enumerate(alls, 1)}
        tree = BinaryIndexedTree(len(m))
        ans = []
        for v in nums[::-1]:
            x = m[v]
            tree.update(x, 1)
            ans.append(tree.query(x - 1))
        return ans[::-1]
```

#### Java

```java
class Solution {
    public List<Integer> countSmaller(int[] nums) {
        Set<Integer> s = new HashSet<>();
        for (int v : nums) {
            s.add(v);
        }
        List<Integer> alls = new ArrayList<>(s);
        alls.sort(Comparator.comparingInt(a -> a));
        int n = alls.size();
        Map<Integer, Integer> m = new HashMap<>(n);
        for (int i = 0; i < n; ++i) {
            m.put(alls.get(i), i + 1);
        }
        BinaryIndexedTree tree = new BinaryIndexedTree(n);
        LinkedList<Integer> ans = new LinkedList<>();
        for (int i = nums.length - 1; i >= 0; --i) {
            int x = m.get(nums[i]);
            tree.update(x, 1);
            ans.addFirst(tree.query(x - 1));
        }
        return ans;
    }
}

class BinaryIndexedTree {
    private int n;
    private int[] c;

    public BinaryIndexedTree(int n) {
        this.n = n;
        c = new int[n + 1];
    }

    public void update(int x, int delta) {
        while (x <= n) {
            c[x] += delta;
            x += lowbit(x);
        }
    }

    public int query(int x) {
        int s = 0;
        while (x > 0) {
            s += c[x];
            x -= lowbit(x);
        }
        return s;
    }

    public static int lowbit(int x) {
        return x & -x;
    }
}
```

#### C++

```cpp
class BinaryIndexedTree {
public:
    int n;
    vector<int> c;

    BinaryIndexedTree(int _n)
        : n(_n)
        , c(_n + 1) {}

    void update(int x, int delta) {
        while (x <= n) {
            c[x] += delta;
            x += lowbit(x);
        }
    }

    int query(int x) {
        int s = 0;
        while (x > 0) {
            s += c[x];
            x -= lowbit(x);
        }
        return s;
    }

    int lowbit(int x) {
        return x & -x;
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        vector<int> alls(s.begin(), s.end());
        sort(alls.begin(), alls.end());
        unordered_map<int, int> m;
        int n = alls.size();
        for (int i = 0; i < n; ++i) m[alls[i]] = i + 1;
        BinaryIndexedTree* tree = new BinaryIndexedTree(n);
        vector<int> ans(nums.size());
        for (int i = nums.size() - 1; i >= 0; --i) {
            int x = m[nums[i]];
            tree->update(x, 1);
            ans[i] = tree->query(x - 1);
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

func newBinaryIndexedTree(n int) *BinaryIndexedTree {
	c := make([]int, n+1)
	return &BinaryIndexedTree{n, c}
}

func (this *BinaryIndexedTree) lowbit(x int) int {
	return x & -x
}

func (this *BinaryIndexedTree) update(x, delta int) {
	for x <= this.n {
		this.c[x] += delta
		x += this.lowbit(x)
	}
}

func (this *BinaryIndexedTree) query(x int) int {
	s := 0
	for x > 0 {
		s += this.c[x]
		x -= this.lowbit(x)
	}
	return s
}

func countSmaller(nums []int) []int {
	s := make(map[int]bool)
	for _, v := range nums {
		s[v] = true
	}
	var alls []int
	for v := range s {
		alls = append(alls, v)
	}
	sort.Ints(alls)
	m := make(map[int]int)
	for i, v := range alls {
		m[v] = i + 1
	}
	ans := make([]int, len(nums))
	tree := newBinaryIndexedTree(len(alls))
	for i := len(nums) - 1; i >= 0; i-- {
		x := m[nums[i]]
		tree.update(x, 1)
		ans[i] = tree.query(x - 1)
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：线段树

线段树将整个区间分割为多个不连续的子区间，子区间的数量不超过 `log(width)`。更新某个元素的值，只需要更新 `log(width)` 个区间，并且这些区间都包含在一个包含该元素的大区间内。

-   线段树的每个节点代表一个区间；
-   线段树具有唯一的根节点，代表的区间是整个统计范围，如 `[1, N]`；
-   线段树的每个叶子节点代表一个长度为 1 的元区间 `[x, x]`；
-   对于每个内部节点 `[l, r]`，它的左儿子是 `[l, mid]`，右儿子是 `[mid + 1, r]`, 其中 `mid = ⌊(l + r) / 2⌋` (即向下取整)。

<!-- tabs:start -->

#### Python3

```python
class Node:
    def __init__(self):
        self.l = 0
        self.r = 0
        self.v = 0


class SegmentTree:
    def __init__(self, n):
        self.tr = [Node() for _ in range(n << 2)]
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

    def query(self, u, l, r):
        if self.tr[u].l >= l and self.tr[u].r <= r:
            return self.tr[u].v
        mid = (self.tr[u].l + self.tr[u].r) >> 1
        v = 0
        if l <= mid:
            v += self.query(u << 1, l, r)
        if r > mid:
            v += self.query(u << 1 | 1, l, r)
        return v

    def pushup(self, u):
        self.tr[u].v = self.tr[u << 1].v + self.tr[u << 1 | 1].v


class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        s = sorted(set(nums))
        m = {v: i for i, v in enumerate(s, 1)}
        tree = SegmentTree(len(s))
        ans = []
        for v in nums[::-1]:
            x = m[v]
            ans.append(tree.query(1, 1, x - 1))
            tree.modify(1, x, 1)
        return ans[::-1]
```

#### Java

```java
class Solution {
    public List<Integer> countSmaller(int[] nums) {
        Set<Integer> s = new HashSet<>();
        for (int v : nums) {
            s.add(v);
        }
        List<Integer> alls = new ArrayList<>(s);
        alls.sort(Comparator.comparingInt(a -> a));
        int n = alls.size();
        Map<Integer, Integer> m = new HashMap<>(n);
        for (int i = 0; i < n; ++i) {
            m.put(alls.get(i), i + 1);
        }
        SegmentTree tree = new SegmentTree(n);
        LinkedList<Integer> ans = new LinkedList<>();
        for (int i = nums.length - 1; i >= 0; --i) {
            int x = m.get(nums[i]);
            tree.modify(1, x, 1);
            ans.addFirst(tree.query(1, 1, x - 1));
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

#### C++

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
        if (l <= mid) v += query(u << 1, l, r);
        if (r > mid) v += query(u << 1 | 1, l, r);
        return v;
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        vector<int> alls(s.begin(), s.end());
        sort(alls.begin(), alls.end());
        unordered_map<int, int> m;
        int n = alls.size();
        for (int i = 0; i < n; ++i) m[alls[i]] = i + 1;
        SegmentTree* tree = new SegmentTree(n);
        vector<int> ans(nums.size());
        for (int i = nums.size() - 1; i >= 0; --i) {
            int x = m[nums[i]];
            tree->modify(1, x, 1);
            ans[i] = tree->query(1, 1, x - 1);
        }
        return ans;
    }
};
```

#### Go

```go
type Pair struct {
	val   int
	index int
}

var (
	tmp   []Pair
	count []int
)

func countSmaller(nums []int) []int {
	tmp, count = make([]Pair, len(nums)), make([]int, len(nums))
	array := make([]Pair, len(nums))
	for i, v := range nums {
		array[i] = Pair{val: v, index: i}
	}
	sorted(array, 0, len(array)-1)
	return count
}

func sorted(arr []Pair, low, high int) {
	if low >= high {
		return
	}
	mid := low + (high-low)/2
	sorted(arr, low, mid)
	sorted(arr, mid+1, high)
	merge(arr, low, mid, high)
}

func merge(arr []Pair, low, mid, high int) {
	left, right := low, mid+1
	idx := low
	for left <= mid && right <= high {
		if arr[left].val <= arr[right].val {
			count[arr[left].index] += right - mid - 1
			tmp[idx], left = arr[left], left+1
		} else {
			tmp[idx], right = arr[right], right+1
		}
		idx++
	}
	for left <= mid {
		count[arr[left].index] += right - mid - 1
		tmp[idx] = arr[left]
		idx, left = idx+1, left+1
	}
	for right <= high {
		tmp[idx] = arr[right]
		idx, right = idx+1, right+1
	}
	// 排序
	for i := low; i <= high; i++ {
		arr[i] = tmp[i]
	}
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法三：归并排序

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [316. 去除重复字母](https://leetcode.cn/problems/remove-duplicate-letters){#316}

{{< tabs "316" >}}

{{% tab "python" %}}
```python
class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        count, in_stack = [0] * 128, [False] * 128
        stack = []
        for c in s:
            count[ord(c)] += 1
        for c in s:
            count[ord(c)] -= 1
            if in_stack[ord(c)]:
                continue
            while len(stack) and stack[-1] > c:
                peek = stack[-1]
                if count[ord(peek)] < 1:
                    break
                in_stack[ord(peek)] = False
                stack.pop()
            stack.append(c)
            in_stack[ord(c)] = True
        return ''.join(stack)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String removeDuplicateLetters(String s) {
        int n = s.length();
        int[] last = new int[26];
        for (int i = 0; i < n; ++i) {
            last[s.charAt(i) - 'a'] = i;
        }
        Deque<Character> stk = new ArrayDeque<>();
        int mask = 0;
        for (int i = 0; i < n; ++i) {
            char c = s.charAt(i);
            if (((mask >> (c - 'a')) & 1) == 1) {
                continue;
            }
            while (!stk.isEmpty() && stk.peek() > c && last[stk.peek() - 'a'] > i) {
                mask ^= 1 << (stk.pop() - 'a');
            }
            stk.push(c);
            mask |= 1 << (c - 'a');
        }
        StringBuilder ans = new StringBuilder();
        for (char c : stk) {
            ans.append(c);
        }
        return ans.reverse().toString();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        int last[26] = {0};
        for (int i = 0; i < n; ++i) {
            last[s[i] - 'a'] = i;
        }
        string ans;
        int mask = 0;
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if ((mask >> (c - 'a')) & 1) {
                continue;
            }
            while (!ans.empty() && ans.back() > c && last[ans.back() - 'a'] > i) {
                mask ^= 1 << (ans.back() - 'a');
                ans.pop_back();
            }
            ans.push_back(c);
            mask |= 1 << (c - 'a');
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func removeDuplicateLetters(s string) string {
	count, in_stack, stack := make([]int, 128), make([]bool, 128), make([]rune, 0)
	for _, c := range s {
		count[c] += 1
	}

	for _, c := range s {
		count[c] -= 1
		if in_stack[c] {
			continue
		}
		for len(stack) > 0 && stack[len(stack)-1] > c && count[stack[len(stack)-1]] > 0 {
			peek := stack[len(stack)-1]
			stack = stack[0 : len(stack)-1]
			in_stack[peek] = false
		}
		stack = append(stack, c)
		in_stack[c] = true
	}
	return string(stack)
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串 <code>s</code> ，请你去除字符串中重复的字母，使得每个字母只出现一次。需保证 <strong>返回结果的<span data-keyword="lexicographically-smaller-string-alien">字典序</span>最小</strong>（要求不能打乱其他字符的相对位置）。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong><code>s = "bcabc"</code>
<strong>输出<code>：</code></strong><code>"abc"</code>
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong><code>s = "cbacdcbc"</code>
<strong>输出：</strong><code>"acdb"</code></pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>4</sup></code></li>
	<li><code>s</code> 由小写英文字母组成</li>
</ul>

<p>&nbsp;</p>

<p><strong>注意：</strong>该题与 1081 <a href="https://leetcode.cn/problems/smallest-subsequence-of-distinct-characters">https://leetcode.cn/problems/smallest-subsequence-of-distinct-characters</a> 相同</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：栈

我们用一个数组 `last` 记录每个字符最后一次出现的位置，用栈来保存结果字符串，用一个数组 `vis` 或者一个整型变量 `mask` 记录当前字符是否在栈中。

遍历字符串 $s$，对于每个字符 $c$，如果 $c$ 不在栈中，我们就需要判断栈顶元素是否大于 $c$，如果大于 $c$，且栈顶元素在后面还会出现，我们就将栈顶元素弹出，将 $c$ 压入栈中。

最后将栈中元素拼接成字符串作为结果返回。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为字符串 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        last = {c: i for i, c in enumerate(s)}
        stk = []
        vis = set()
        for i, c in enumerate(s):
            if c in vis:
                continue
            while stk and stk[-1] > c and last[stk[-1]] > i:
                vis.remove(stk.pop())
            stk.append(c)
            vis.add(c)
        return ''.join(stk)
```

#### Java

```java
class Solution {
    public String removeDuplicateLetters(String s) {
        int n = s.length();
        int[] last = new int[26];
        for (int i = 0; i < n; ++i) {
            last[s.charAt(i) - 'a'] = i;
        }
        Deque<Character> stk = new ArrayDeque<>();
        int mask = 0;
        for (int i = 0; i < n; ++i) {
            char c = s.charAt(i);
            if (((mask >> (c - 'a')) & 1) == 1) {
                continue;
            }
            while (!stk.isEmpty() && stk.peek() > c && last[stk.peek() - 'a'] > i) {
                mask ^= 1 << (stk.pop() - 'a');
            }
            stk.push(c);
            mask |= 1 << (c - 'a');
        }
        StringBuilder ans = new StringBuilder();
        for (char c : stk) {
            ans.append(c);
        }
        return ans.reverse().toString();
    }
}
```

#### C++

```cpp
class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        int last[26] = {0};
        for (int i = 0; i < n; ++i) {
            last[s[i] - 'a'] = i;
        }
        string ans;
        int mask = 0;
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if ((mask >> (c - 'a')) & 1) {
                continue;
            }
            while (!ans.empty() && ans.back() > c && last[ans.back() - 'a'] > i) {
                mask ^= 1 << (ans.back() - 'a');
                ans.pop_back();
            }
            ans.push_back(c);
            mask |= 1 << (c - 'a');
        }
        return ans;
    }
};
```

#### Go

```go
func removeDuplicateLetters(s string) string {
	last := make([]int, 26)
	for i, c := range s {
		last[c-'a'] = i
	}
	stk := []rune{}
	vis := make([]bool, 128)
	for i, c := range s {
		if vis[c] {
			continue
		}
		for len(stk) > 0 && stk[len(stk)-1] > c && last[stk[len(stk)-1]-'a'] > i {
			vis[stk[len(stk)-1]] = false
			stk = stk[:len(stk)-1]
		}
		stk = append(stk, c)
		vis[c] = true
	}
	return string(stk)
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
    def removeDuplicateLetters(self, s: str) -> str:
        count, in_stack = [0] * 128, [False] * 128
        stack = []
        for c in s:
            count[ord(c)] += 1
        for c in s:
            count[ord(c)] -= 1
            if in_stack[ord(c)]:
                continue
            while len(stack) and stack[-1] > c:
                peek = stack[-1]
                if count[ord(peek)] < 1:
                    break
                in_stack[ord(peek)] = False
                stack.pop()
            stack.append(c)
            in_stack[ord(c)] = True
        return ''.join(stack)
```

#### Go

```go
func removeDuplicateLetters(s string) string {
	count, in_stack, stack := make([]int, 128), make([]bool, 128), make([]rune, 0)
	for _, c := range s {
		count[c] += 1
	}

	for _, c := range s {
		count[c] -= 1
		if in_stack[c] {
			continue
		}
		for len(stack) > 0 && stack[len(stack)-1] > c && count[stack[len(stack)-1]] > 0 {
			peek := stack[len(stack)-1]
			stack = stack[0 : len(stack)-1]
			in_stack[peek] = false
		}
		stack = append(stack, c)
		in_stack[c] = true
	}
	return string(stack)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [317. 离建筑物最近的距离 🔒](https://leetcode.cn/problems/shortest-distance-from-all-buildings){#317}

{{< tabs "317" >}}

{{% tab "python" %}}
```python
class Solution:
    def shortestDistance(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        q = deque()
        total = 0
        cnt = [[0] * n for _ in range(m)]
        dist = [[0] * n for _ in range(m)]
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    total += 1
                    q.append((i, j))
                    d = 0
                    vis = set()
                    while q:
                        d += 1
                        for _ in range(len(q)):
                            r, c = q.popleft()
                            for a, b in [[0, 1], [0, -1], [1, 0], [-1, 0]]:
                                x, y = r + a, c + b
                                if (
                                    0 <= x < m
                                    and 0 <= y < n
                                    and grid[x][y] == 0
                                    and (x, y) not in vis
                                ):
                                    cnt[x][y] += 1
                                    dist[x][y] += d
                                    q.append((x, y))
                                    vis.add((x, y))
        ans = inf
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 0 and cnt[i][j] == total:
                    ans = min(ans, dist[i][j])
        return -1 if ans == inf else ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int shortestDistance(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        Deque<int[]> q = new LinkedList<>();
        int total = 0;
        int[][] cnt = new int[m][n];
        int[][] dist = new int[m][n];
        int[] dirs = {-1, 0, 1, 0, -1};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    ++total;
                    q.offer(new int[] {i, j});
                    int d = 0;
                    boolean[][] vis = new boolean[m][n];
                    while (!q.isEmpty()) {
                        ++d;
                        for (int k = q.size(); k > 0; --k) {
                            int[] p = q.poll();
                            for (int l = 0; l < 4; ++l) {
                                int x = p[0] + dirs[l];
                                int y = p[1] + dirs[l + 1];
                                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 0
                                    && !vis[x][y]) {
                                    ++cnt[x][y];
                                    dist[x][y] += d;
                                    q.offer(new int[] {x, y});
                                    vis[x][y] = true;
                                }
                            }
                        }
                    }
                }
            }
        }
        int ans = Integer.MAX_VALUE;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0 && cnt[i][j] == total) {
                    ans = Math.min(ans, dist[i][j]);
                }
            }
        }
        return ans == Integer.MAX_VALUE ? -1 : ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        typedef pair<int, int> pii;
        queue<pii> q;
        int total = 0;
        vector<vector<int>> cnt(m, vector<int>(n));
        vector<vector<int>> dist(m, vector<int>(n));
        vector<int> dirs = {-1, 0, 1, 0, -1};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    ++total;
                    q.push({i, j});
                    vector<vector<bool>> vis(m, vector<bool>(n));
                    int d = 0;
                    while (!q.empty()) {
                        ++d;
                        for (int k = q.size(); k > 0; --k) {
                            auto p = q.front();
                            q.pop();
                            for (int l = 0; l < 4; ++l) {
                                int x = p.first + dirs[l];
                                int y = p.second + dirs[l + 1];
                                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 0 && !vis[x][y]) {
                                    ++cnt[x][y];
                                    dist[x][y] += d;
                                    q.push({x, y});
                                    vis[x][y] = true;
                                }
                            }
                        }
                    }
                }
            }
        }
        int ans = INT_MAX;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == 0 && cnt[i][j] == total)
                    ans = min(ans, dist[i][j]);
        return ans == INT_MAX ? -1 : ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func shortestDistance(grid [][]int) int {
	m, n := len(grid), len(grid[0])
	var q [][]int
	total := 0
	cnt := make([][]int, m)
	dist := make([][]int, m)
	for i := range cnt {
		cnt[i] = make([]int, n)
		dist[i] = make([]int, n)
	}
	dirs := []int{-1, 0, 1, 0, -1}
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if grid[i][j] == 1 {
				total++
				q = append(q, []int{i, j})
				vis := make([]bool, m*n)
				d := 0
				for len(q) > 0 {
					d++
					for k := len(q); k > 0; k-- {
						p := q[0]
						q = q[1:]
						for l := 0; l < 4; l++ {
							x, y := p[0]+dirs[l], p[1]+dirs[l+1]
							if x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 0 && !vis[x*n+y] {
								cnt[x][y]++
								dist[x][y] += d
								q = append(q, []int{x, y})
								vis[x*n+y] = true
							}
						}
					}
				}
			}
		}
	}

	ans := math.MaxInt32
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if grid[i][j] == 0 && cnt[i][j] == total {
				if ans > dist[i][j] {
					ans = dist[i][j]
				}
			}
		}
	}
	if ans == math.MaxInt32 {
		return -1
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

<p>给你一个 <code>m × n</code> 的网格，值为 <code>0</code> 、 <code>1</code> 或 <code>2</code> ，其中:</p>

<ul>
	<li>每一个 <code>0</code> 代表一块你可以自由通过的 <strong>空地</strong>&nbsp;</li>
	<li>每一个 <code>1</code> 代表一个你不能通过的 <strong>建筑</strong></li>
	<li>每个 <code>2</code> 标记一个你不能通过的 <strong>障碍</strong>&nbsp;</li>
</ul>

<p>你想要在一块空地上建造一所房子，在 <strong>最短的总旅行距离</strong> 内到达所有的建筑。你只能上下左右移动。</p>

<p>返回到该房子的 <strong>最短旅行距离</strong> 。如果根据上述规则无法建造这样的房子，则返回 <code>-1</code> 。</p>

<p><strong>总旅行距离&nbsp;</strong>是朋友们家到聚会地点的距离之和。</p>

<p>&nbsp;</p>

<p><strong>示例&nbsp; 1：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0300-0399/0317.Shortest%20Distance%20from%20All%20Buildings/images/buildings-grid.jpg" /></p>

<pre>
<strong>输入：</strong>grid = [[1,0,2,0,1],[0,0,0,0,0],[0,0,1,0,0]]
<strong>输出：</strong>7 
<strong>解析：</strong>给定<code>三个建筑物 (0,0)、</code><code>(0,4) 和</code> <code>(2,2) 以及一个</code>位于 <code>(0,2) 的障碍物。
由于总距离之和 3+3+1=7 最优，所以位置</code> <code>(1,2)</code> 是符合要求的最优地点。
故返回7。
</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre>
<strong>输入:</strong> grid = [[1,0]]
<strong>输出:</strong> 1
</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入:</strong> grid = [[1]]
<strong>输出:</strong> -1
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 50</code></li>
	<li><code>grid[i][j]</code>&nbsp;是&nbsp;<code>0</code>,&nbsp;<code>1</code>&nbsp;或&nbsp;<code>2</code></li>
	<li><code>grid</code>&nbsp;中 <strong>至少</strong>&nbsp;有 <strong>一幢</strong> 建筑</li>
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
    def shortestDistance(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        q = deque()
        total = 0
        cnt = [[0] * n for _ in range(m)]
        dist = [[0] * n for _ in range(m)]
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    total += 1
                    q.append((i, j))
                    d = 0
                    vis = set()
                    while q:
                        d += 1
                        for _ in range(len(q)):
                            r, c = q.popleft()
                            for a, b in [[0, 1], [0, -1], [1, 0], [-1, 0]]:
                                x, y = r + a, c + b
                                if (
                                    0 <= x < m
                                    and 0 <= y < n
                                    and grid[x][y] == 0
                                    and (x, y) not in vis
                                ):
                                    cnt[x][y] += 1
                                    dist[x][y] += d
                                    q.append((x, y))
                                    vis.add((x, y))
        ans = inf
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 0 and cnt[i][j] == total:
                    ans = min(ans, dist[i][j])
        return -1 if ans == inf else ans
```

#### Java

```java
class Solution {
    public int shortestDistance(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        Deque<int[]> q = new LinkedList<>();
        int total = 0;
        int[][] cnt = new int[m][n];
        int[][] dist = new int[m][n];
        int[] dirs = {-1, 0, 1, 0, -1};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    ++total;
                    q.offer(new int[] {i, j});
                    int d = 0;
                    boolean[][] vis = new boolean[m][n];
                    while (!q.isEmpty()) {
                        ++d;
                        for (int k = q.size(); k > 0; --k) {
                            int[] p = q.poll();
                            for (int l = 0; l < 4; ++l) {
                                int x = p[0] + dirs[l];
                                int y = p[1] + dirs[l + 1];
                                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 0
                                    && !vis[x][y]) {
                                    ++cnt[x][y];
                                    dist[x][y] += d;
                                    q.offer(new int[] {x, y});
                                    vis[x][y] = true;
                                }
                            }
                        }
                    }
                }
            }
        }
        int ans = Integer.MAX_VALUE;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0 && cnt[i][j] == total) {
                    ans = Math.min(ans, dist[i][j]);
                }
            }
        }
        return ans == Integer.MAX_VALUE ? -1 : ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        typedef pair<int, int> pii;
        queue<pii> q;
        int total = 0;
        vector<vector<int>> cnt(m, vector<int>(n));
        vector<vector<int>> dist(m, vector<int>(n));
        vector<int> dirs = {-1, 0, 1, 0, -1};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    ++total;
                    q.push({i, j});
                    vector<vector<bool>> vis(m, vector<bool>(n));
                    int d = 0;
                    while (!q.empty()) {
                        ++d;
                        for (int k = q.size(); k > 0; --k) {
                            auto p = q.front();
                            q.pop();
                            for (int l = 0; l < 4; ++l) {
                                int x = p.first + dirs[l];
                                int y = p.second + dirs[l + 1];
                                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 0 && !vis[x][y]) {
                                    ++cnt[x][y];
                                    dist[x][y] += d;
                                    q.push({x, y});
                                    vis[x][y] = true;
                                }
                            }
                        }
                    }
                }
            }
        }
        int ans = INT_MAX;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == 0 && cnt[i][j] == total)
                    ans = min(ans, dist[i][j]);
        return ans == INT_MAX ? -1 : ans;
    }
};
```

#### Go

```go
func shortestDistance(grid [][]int) int {
	m, n := len(grid), len(grid[0])
	var q [][]int
	total := 0
	cnt := make([][]int, m)
	dist := make([][]int, m)
	for i := range cnt {
		cnt[i] = make([]int, n)
		dist[i] = make([]int, n)
	}
	dirs := []int{-1, 0, 1, 0, -1}
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if grid[i][j] == 1 {
				total++
				q = append(q, []int{i, j})
				vis := make([]bool, m*n)
				d := 0
				for len(q) > 0 {
					d++
					for k := len(q); k > 0; k-- {
						p := q[0]
						q = q[1:]
						for l := 0; l < 4; l++ {
							x, y := p[0]+dirs[l], p[1]+dirs[l+1]
							if x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 0 && !vis[x*n+y] {
								cnt[x][y]++
								dist[x][y] += d
								q = append(q, []int{x, y})
								vis[x*n+y] = true
							}
						}
					}
				}
			}
		}
	}

	ans := math.MaxInt32
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if grid[i][j] == 0 && cnt[i][j] == total {
				if ans > dist[i][j] {
					ans = dist[i][j]
				}
			}
		}
	}
	if ans == math.MaxInt32 {
		return -1
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [318. 最大单词长度乘积](https://leetcode.cn/problems/maximum-product-of-word-lengths){#318}

{{< tabs "318" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxProduct(self, words: List[str]) -> int:
        mask = defaultdict(int)
        ans = 0
        for s in words:
            a = len(s)
            x = 0
            for c in s:
                x |= 1 << (ord(c) - ord("a"))
            for y, b in mask.items():
                if (x & y) == 0:
                    ans = max(ans, a * b)
            mask[x] = max(mask[x], a)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxProduct(String[] words) {
        Map<Integer, Integer> mask = new HashMap<>();
        int ans = 0;
        for (var s : words) {
            int a = s.length();
            int x = 0;
            for (char c : s.toCharArray()) {
                x |= 1 << (c - 'a');
            }
            for (var e : mask.entrySet()) {
                int y = e.getKey(), b = e.getValue();
                if ((x & y) == 0) {
                    ans = Math.max(ans, a * b);
                }
            }
            mask.merge(x, a, Math::max);
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
    int maxProduct(vector<string>& words) {
        unordered_map<int, int> mask;
        int ans = 0;
        for (auto& s : words) {
            int a = s.size();
            int x = 0;
            for (char& c : s) {
                x |= 1 << (c - 'a');
            }
            for (auto& [y, b] : mask) {
                if ((x & y) == 0) {
                    ans = max(ans, a * b);
                }
            }
            mask[x] = max(mask[x], a);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxProduct(words []string) (ans int) {
	mask := map[int]int{}
	for _, s := range words {
		a := len(s)
		x := 0
		for _, c := range s {
			x |= 1 << (c - 'a')
		}
		for y, b := range mask {
			if x&y == 0 {
				ans = max(ans, a*b)
			}
		}
		mask[x] = max(mask[x], a)
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxProduct(words: string[]): number {
    const mask: Map<number, number> = new Map();
    let ans = 0;
    for (const s of words) {
        const a = s.length;
        let x = 0;
        for (const c of s) {
            x |= 1 << (c.charCodeAt(0) - 'a'.charCodeAt(0));
        }
        for (const [y, b] of mask.entries()) {
            if ((x & y) === 0) {
                ans = Math.max(ans, a * b);
            }
        }
        mask.set(x, Math.max(mask.get(x) || 0, a));
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

<p>给你一个字符串数组&nbsp;<code>words</code> ，找出并返回 <code>length(words[i]) * length(words[j])</code>&nbsp;的最大值，并且这两个单词不含有公共字母。如果不存在这样的两个单词，返回 <code>0</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例&nbsp;1：</strong></p>

<pre>
<strong>输入：</strong>words = <code>["abcw","baz","foo","bar","xtfn","abcdef"]</code>
<strong>输出：</strong><code>16 
<strong>解释</strong></code><strong>：</strong><code>这两个单词为<strong> </strong>"abcw", "xtfn"</code>。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>words = <code>["a","ab","abc","d","cd","bcd","abcd"]</code>
<strong>输出：</strong><code>4 
<strong>解释</strong></code><strong>：</strong>这两个单词为 <code>"ab", "cd"</code>。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>words = <code>["a","aa","aaa","aaaa"]</code>
<strong>输出：</strong><code>0 
<strong>解释</strong></code><strong>：</strong><code>不存在这样的两个单词。</code>
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= words.length &lt;= 1000</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 1000</code></li>
	<li><code>words[i]</code>&nbsp;仅包含小写字母</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：位运算

题目需要我们找到两个没有公共字母的字符串，使得它们的长度乘积最大。我们可以将每个字符串用一个二进制数 $mask[i]$ 表示，这个二进制数的每一位表示字符串中是否含有某个字母。如果两个字符串没有公共字母，那么这两个字符串对应的二进制数的按位与的结果为 $0$，即 $mask[i] \& mask[j] = 0$。

我们遍历每个字符串，对于当前遍历到的字符串 $words[i]$，我们先算出对应的二进制数 $mask[i]$，然后再遍历 $j \in [0, i)$ 的所有字符串 $words[j]$，检查 $mask[i] \& mask[j] = 0$ 是否成立，如果成立就更新答案为 $\max(ans, |words[i]| \times |words[j]|)$。

遍历结束后，返回答案即可。

时间复杂度 $O(n^2 + L)$，空间复杂度 $O(n)$。其中 $n$ 是字符串数组 $words$ 的长度，而 $L$ 是字符串数组所有字符串的长度之和。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxProduct(self, words: List[str]) -> int:
        mask = [0] * len(words)
        ans = 0
        for i, s in enumerate(words):
            for c in s:
                mask[i] |= 1 << (ord(c) - ord("a"))
            for j, t in enumerate(words[:i]):
                if (mask[i] & mask[j]) == 0:
                    ans = max(ans, len(s) * len(t))
        return ans
```

#### Java

```java
class Solution {
    public int maxProduct(String[] words) {
        int n = words.length;
        int[] mask = new int[n];
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (char c : words[i].toCharArray()) {
                mask[i] |= 1 << (c - 'a');
            }
            for (int j = 0; j < i; ++j) {
                if ((mask[i] & mask[j]) == 0) {
                    ans = Math.max(ans, words[i].length() * words[j].length());
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
    int maxProduct(vector<string>& words) {
        int n = words.size();
        int mask[n];
        memset(mask, 0, sizeof(mask));
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (char& c : words[i]) {
                mask[i] |= 1 << (c - 'a');
            }
            for (int j = 0; j < i; ++j) {
                if ((mask[i] & mask[j]) == 0) {
                    ans = max(ans, (int) (words[i].size() * words[j].size()));
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func maxProduct(words []string) (ans int) {
	n := len(words)
	mask := make([]int, n)
	for i, s := range words {
		for _, c := range s {
			mask[i] |= 1 << (c - 'a')
		}
		for j, t := range words[:i] {
			if mask[i]&mask[j] == 0 {
				ans = max(ans, len(s)*len(t))
			}
		}
	}
	return
}
```

#### TypeScript

```ts
function maxProduct(words: string[]): number {
    const n = words.length;
    const mask: number[] = Array(n).fill(0);
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        for (const c of words[i]) {
            mask[i] |= 1 << (c.charCodeAt(0) - 'a'.charCodeAt(0));
        }
        for (let j = 0; j < i; ++j) {
            if ((mask[i] & mask[j]) === 0) {
                ans = Math.max(ans, words[i].length * words[j].length);
            }
        }
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
    def maxProduct(self, words: List[str]) -> int:
        mask = defaultdict(int)
        ans = 0
        for s in words:
            a = len(s)
            x = 0
            for c in s:
                x |= 1 << (ord(c) - ord("a"))
            for y, b in mask.items():
                if (x & y) == 0:
                    ans = max(ans, a * b)
            mask[x] = max(mask[x], a)
        return ans
```

#### Java

```java
class Solution {
    public int maxProduct(String[] words) {
        Map<Integer, Integer> mask = new HashMap<>();
        int ans = 0;
        for (var s : words) {
            int a = s.length();
            int x = 0;
            for (char c : s.toCharArray()) {
                x |= 1 << (c - 'a');
            }
            for (var e : mask.entrySet()) {
                int y = e.getKey(), b = e.getValue();
                if ((x & y) == 0) {
                    ans = Math.max(ans, a * b);
                }
            }
            mask.merge(x, a, Math::max);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxProduct(vector<string>& words) {
        unordered_map<int, int> mask;
        int ans = 0;
        for (auto& s : words) {
            int a = s.size();
            int x = 0;
            for (char& c : s) {
                x |= 1 << (c - 'a');
            }
            for (auto& [y, b] : mask) {
                if ((x & y) == 0) {
                    ans = max(ans, a * b);
                }
            }
            mask[x] = max(mask[x], a);
        }
        return ans;
    }
};
```

#### Go

```go
func maxProduct(words []string) (ans int) {
	mask := map[int]int{}
	for _, s := range words {
		a := len(s)
		x := 0
		for _, c := range s {
			x |= 1 << (c - 'a')
		}
		for y, b := range mask {
			if x&y == 0 {
				ans = max(ans, a*b)
			}
		}
		mask[x] = max(mask[x], a)
	}
	return
}
```

#### TypeScript

```ts
function maxProduct(words: string[]): number {
    const mask: Map<number, number> = new Map();
    let ans = 0;
    for (const s of words) {
        const a = s.length;
        let x = 0;
        for (const c of s) {
            x |= 1 << (c.charCodeAt(0) - 'a'.charCodeAt(0));
        }
        for (const [y, b] of mask.entries()) {
            if ((x & y) === 0) {
                ans = Math.max(ans, a * b);
            }
        }
        mask.set(x, Math.max(mask.get(x) || 0, a));
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [319. 灯泡开关](https://leetcode.cn/problems/bulb-switcher){#319}

{{< tabs "319" >}}

{{% tab "python" %}}
```python
class Solution:
    def bulbSwitch(self, n: int) -> int:
        return int(sqrt(n))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int bulbSwitch(int n) {
        return (int) Math.sqrt(n);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int bulbSwitch(int n) {
        return (int) sqrt(n);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func bulbSwitch(n int) int {
	return int(math.Sqrt(float64(n)))
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function bulbSwitch(n: number): number {
    return Math.floor(Math.sqrt(n));
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>初始时有&nbsp;<code>n</code><em> </em>个灯泡处于关闭状态。第一轮，你将会打开所有灯泡。接下来的第二轮，你将会每两个灯泡关闭第二个。</p>

<p>第三轮，你每三个灯泡就切换第三个灯泡的开关（即，打开变关闭，关闭变打开）。第 <code>i</code> 轮，你每 <code>i</code> 个灯泡就切换第 <code>i</code> 个灯泡的开关。直到第 <code>n</code> 轮，你只需要切换最后一个灯泡的开关。</p>

<p>找出并返回 <code>n</code><em>&nbsp;</em>轮后有多少个亮着的灯泡。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0300-0399/0319.Bulb%20Switcher/images/bulb.jpg" style="width: 421px; height: 321px;" /></p>

<pre>
<strong>输入：</strong>n =<strong> </strong>3
<strong>输出：</strong>1 
<strong>解释：</strong>
初始时, 灯泡状态 <strong>[关闭, 关闭, 关闭]</strong>.
第一轮后, 灯泡状态 <strong>[开启, 开启, 开启]</strong>.
第二轮后, 灯泡状态 <strong>[开启, 关闭, 开启]</strong>.
第三轮后, 灯泡状态 <strong>[开启, 关闭, 关闭]</strong>. 

你应该返回 1，因为只有一个灯泡还亮着。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 0
<strong>输出：</strong>0
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 1
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= n &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数学

我们不妨将 $n$ 个灯泡编号为 $1, 2, 3, \cdots, n$，那么对于第 $i$ 个灯泡，它会在第 $d$ 轮被操作，当且仅当 $d$ 是 $i$ 的因子。

对于一个数 $i$，它的因子个数是有限的，且因子个数为奇数时，最后的状态是开启的，否则是关闭的。

因此，我们只需要找到 $1$ 到 $n$ 中因子个数为奇数的数的个数即可。

对于一个数 $i$，如果它有因子 $d$，那么它一定有因子 $i/d$，因此因子个数为奇数的数一定是平方数。

举个例子，数字 $12$ 的因子有 $1, 2, 3, 4, 6, 12$，因子个数为 $6$，是偶数；而对于数字 $16$ 这个平方数，因子有 $1, 2, 4, 8, 16$，因子个数为 $5$，是奇数。

因此，我们只需要找到 $1$ 到 $n$ 中有多少个平方数即可，即 $\lfloor \sqrt{n} \rfloor$。

时间复杂度 $O(1)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def bulbSwitch(self, n: int) -> int:
        return int(sqrt(n))
```

#### Java

```java
class Solution {
    public int bulbSwitch(int n) {
        return (int) Math.sqrt(n);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int bulbSwitch(int n) {
        return (int) sqrt(n);
    }
};
```

#### Go

```go
func bulbSwitch(n int) int {
	return int(math.Sqrt(float64(n)))
}
```

#### TypeScript

```ts
function bulbSwitch(n: number): number {
    return Math.floor(Math.sqrt(n));
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
