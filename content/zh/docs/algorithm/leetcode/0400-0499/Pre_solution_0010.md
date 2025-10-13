---
title: "0490_迷宫 🔒"
date: 2025-10-08T18:36:10+08:00
weight: 10
tags: [二分查找, 位运算, 分治, 前缀和, 动态规划, 单调栈, 哈希表, 回溯, 图, 堆（优先队列）, 字符串, 广度优先搜索, 归并排序, 数学, 数组, 最短路, 有序集合, 栈, 树状数组, 模拟, 水塘抽样, 深度优先搜索, 矩阵, 线段树, 随机化]
---

{{< markmap >}}
### [0490_迷宫 🔒](#490)
#### [深度优先搜索](#490)
#### [广度优先搜索](#490)
#### [数组](#490)
#### [矩阵](#490)
### [0491_非递减子序列](#491)
#### [位运算](#491)
#### [数组](#491)
#### [哈希表](#491)
#### [回溯](#491)
### [0492_构造矩形](#492)
#### [数学](#492)
### [0493_翻转对](#493)
#### [树状数组](#493)
#### [线段树](#493)
#### [数组](#493)
#### [二分查找](#493)
#### [分治](#493)
#### [有序集合](#493)
#### [归并排序](#493)
### [0494_目标和](#494)
#### [数组](#494)
#### [动态规划](#494)
#### [回溯](#494)
### [0495_提莫攻击](#495)
#### [数组](#495)
#### [模拟](#495)
### [0496_下一个更大元素 I](#496)
#### [栈](#496)
#### [数组](#496)
#### [哈希表](#496)
#### [单调栈](#496)
### [0497_非重叠矩形中的随机点](#497)
#### [水塘抽样](#497)
#### [数组](#497)
#### [数学](#497)
#### [二分查找](#497)
#### [有序集合](#497)
#### [前缀和](#497)
#### [随机化](#497)
### [0498_对角线遍历](#498)
#### [数组](#498)
#### [矩阵](#498)
#### [模拟](#498)
### [0499_迷宫 III 🔒](#499)
#### [深度优先搜索](#499)
#### [广度优先搜索](#499)
#### [图](#499)
#### [数组](#499)
#### [字符串](#499)
#### [矩阵](#499)
#### [最短路](#499)
#### [堆（优先队列）](#499)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0490_迷宫 🔒
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 数组
___
#### 矩阵
---
### 0491_非递减子序列
___
#### 位运算
___
#### 数组
___
#### 哈希表
___
#### 回溯
---
### 0492_构造矩形
___
#### 数学
---
### 0493_翻转对
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
### 0494_目标和
___
#### 数组
___
#### 动态规划
___
#### 回溯
---
### 0495_提莫攻击
___
#### 数组
___
#### 模拟
---
### 0496_下一个更大元素 I
___
#### 栈
___
#### 数组
___
#### 哈希表
___
#### 单调栈
---
### 0497_非重叠矩形中的随机点
___
#### 水塘抽样
___
#### 数组
___
#### 数学
___
#### 二分查找
___
#### 有序集合
___
#### 前缀和
___
#### 随机化
---
### 0498_对角线遍历
___
#### 数组
___
#### 矩阵
___
#### 模拟
---
### 0499_迷宫 III 🔒
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 图
___
#### 数组
___
#### 字符串
___
#### 矩阵
___
#### 最短路
___
#### 堆（优先队列）
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 位运算 | 分治 |
| 前缀和 | 动态规划 | 单调栈 |
| 哈希表 | 回溯 | 图 |
| 堆（优先队列） | 字符串 | 广度优先搜索 |
| 归并排序 | 数学 | 数组 |
| 最短路 | 有序集合 | 栈 |
| 树状数组 | 模拟 | 水塘抽样 |
| 深度优先搜索 | 矩阵 | 线段树 |
| 随机化 |  |  |

# [490. 迷宫 🔒](https://leetcode.cn/problems/the-maze){#490}

{{< tabs "490" >}}

{{% tab "python" %}}
```python
class Solution:
    def hasPath(
        self, maze: List[List[int]], start: List[int], destination: List[int]
    ) -> bool:
        m, n = len(maze), len(maze[0])
        q = deque([start])
        rs, cs = start
        vis = {(rs, cs)}
        while q:
            i, j = q.popleft()
            for a, b in [[0, -1], [0, 1], [-1, 0], [1, 0]]:
                x, y = i, j
                while 0 <= x + a < m and 0 <= y + b < n and maze[x + a][y + b] == 0:
                    x, y = x + a, y + b
                if [x, y] == destination:
                    return True
                if (x, y) not in vis:
                    vis.add((x, y))
                    q.append((x, y))
        return False
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean hasPath(int[][] maze, int[] start, int[] destination) {
        int m = maze.length;
        int n = maze[0].length;
        boolean[][] vis = new boolean[m][n];
        vis[start[0]][start[1]] = true;
        Deque<int[]> q = new LinkedList<>();
        q.offer(start);
        int[] dirs = {-1, 0, 1, 0, -1};
        while (!q.isEmpty()) {
            int[] p = q.poll();
            int i = p[0], j = p[1];
            for (int k = 0; k < 4; ++k) {
                int x = i, y = j;
                int a = dirs[k], b = dirs[k + 1];
                while (
                    x + a >= 0 && x + a < m && y + b >= 0 && y + b < n && maze[x + a][y + b] == 0) {
                    x += a;
                    y += b;
                }
                if (x == destination[0] && y == destination[1]) {
                    return true;
                }
                if (!vis[x][y]) {
                    vis[x][y] = true;
                    q.offer(new int[] {x, y});
                }
            }
        }
        return false;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size();
        int n = maze[0].size();
        queue<vector<int>> q{{start}};
        vector<vector<bool>> vis(m, vector<bool>(n));
        vis[start[0]][start[1]] = true;
        vector<int> dirs = {-1, 0, 1, 0, -1};
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            int i = p[0], j = p[1];
            for (int k = 0; k < 4; ++k) {
                int x = i, y = j;
                int a = dirs[k], b = dirs[k + 1];
                while (x + a >= 0 && x + a < m && y + b >= 0 && y + b < n && maze[x + a][y + b] == 0) {
                    x += a;
                    y += b;
                }
                if (x == destination[0] && y == destination[1]) return 1;
                if (!vis[x][y]) {
                    vis[x][y] = true;
                    q.push({x, y});
                }
            }
        }
        return 0;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func hasPath(maze [][]int, start []int, destination []int) bool {
	m, n := len(maze), len(maze[0])
	vis := make([][]bool, m)
	for i := range vis {
		vis[i] = make([]bool, n)
	}
	vis[start[0]][start[1]] = true
	q := [][]int{start}
	dirs := []int{-1, 0, 1, 0, -1}
	for len(q) > 0 {
		i, j := q[0][0], q[0][1]
		q = q[1:]
		for k := 0; k < 4; k++ {
			x, y := i, j
			a, b := dirs[k], dirs[k+1]
			for x+a >= 0 && x+a < m && y+b >= 0 && y+b < n && maze[x+a][y+b] == 0 {
				x += a
				y += b
			}
			if x == destination[0] && y == destination[1] {
				return true
			}
			if !vis[x][y] {
				vis[x][y] = true
				q = append(q, []int{x, y})
			}
		}
	}
	return false
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

由空地（用 <code>0</code> 表示）和墙（用 <code>1</code> 表示）组成的迷宫 <code>maze</code> 中有一个球。球可以途经空地向<strong> 上、下、左、右 </strong>四个方向滚动，且在遇到墙壁前不会停止滚动。当球停下时，可以选择向下一个方向滚动。

<div class="top-view__1vxA">
<div class="original__bRMd">
<div>
<p>给你一个大小为 <code>m x n</code> 的迷宫 <code>maze</code> ，以及球的初始位置 <code>start</code> 和目的地 <code>destination</code> ，其中 <code>start = [start<sub>row</sub>, start<sub>col</sub>]</code> 且 <code>destination = [destination<sub>row</sub>, destination<sub>col</sub>]</code> 。请你判断球能否在目的地停下：如果可以，返回 <code>true</code> ；否则，返回 <code>false</code> 。</p>

<p>你可以 <strong>假定迷宫的边缘都是墙壁</strong>（参考示例）。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0400-0499/0490.The%20Maze/images/maze1-1-grid.jpg" style="width: 573px; height: 573px;" />
<pre>
<strong>输入：</strong>maze = [[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]], start = [0,4], destination = [4,4]
<strong>输出：</strong>true
<strong>解释：</strong>一种可能的路径是 : 左 -&gt; 下 -&gt; 左 -&gt; 下 -&gt; 右 -&gt; 下 -&gt; 右。
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0400-0499/0490.The%20Maze/images/maze1-2-grid.jpg" style="width: 573px; height: 573px;" />
<pre>
<strong>输入：</strong>maze = [[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]], start = [0,4], destination = [3,2]
<strong>输出：</strong>false
<strong>解释：</strong>不存在能够使球停在目的地的路径。注意，球可以经过目的地，但无法在那里停驻。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>maze = [[0,0,0,0,0],[1,1,0,0,1],[0,0,0,0,0],[0,1,0,0,1],[0,1,0,0,0]], start = [4,3], destination = [0,1]
<strong>输出：</strong>false
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == maze.length</code></li>
	<li><code>n == maze[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 100</code></li>
	<li><code>maze[i][j]</code> is <code>0</code> or <code>1</code>.</li>
	<li><code>start.length == 2</code></li>
	<li><code>destination.length == 2</code></li>
	<li><code>0 &lt;= start<sub>row</sub>, destination<sub>row</sub> &lt;&nbsp;m</code></li>
	<li><code>0 &lt;= start<sub>col</sub>, destination<sub>col</sub> &lt;&nbsp;n</code></li>
	<li>球和目的地都在空地上，且初始时它们不在同一位置</li>
	<li>迷宫 <strong>至少包括 2 块空地</strong></li>
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

### 方法一

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def hasPath(
        self, maze: List[List[int]], start: List[int], destination: List[int]
    ) -> bool:
        def dfs(i, j):
            if vis[i][j]:
                return
            vis[i][j] = True
            if [i, j] == destination:
                return
            for a, b in [[0, -1], [0, 1], [1, 0], [-1, 0]]:
                x, y = i, j
                while 0 <= x + a < m and 0 <= y + b < n and maze[x + a][y + b] == 0:
                    x, y = x + a, y + b
                dfs(x, y)

        m, n = len(maze), len(maze[0])
        vis = [[False] * n for _ in range(m)]
        dfs(start[0], start[1])
        return vis[destination[0]][destination[1]]
```

#### Java

```java
class Solution {
    private boolean[][] vis;
    private int[][] maze;
    private int[] d;
    private int m;
    private int n;

    public boolean hasPath(int[][] maze, int[] start, int[] destination) {
        m = maze.length;
        n = maze[0].length;
        d = destination;
        this.maze = maze;
        vis = new boolean[m][n];
        dfs(start[0], start[1]);
        return vis[d[0]][d[1]];
    }

    private void dfs(int i, int j) {
        if (vis[i][j]) {
            return;
        }
        vis[i][j] = true;
        if (i == d[0] && j == d[1]) {
            return;
        }
        int[] dirs = {-1, 0, 1, 0, -1};
        for (int k = 0; k < 4; ++k) {
            int x = i, y = j;
            int a = dirs[k], b = dirs[k + 1];
            while (x + a >= 0 && x + a < m && y + b >= 0 && y + b < n && maze[x + a][y + b] == 0) {
                x += a;
                y += b;
            }
            dfs(x, y);
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<vector<int>> maze;
    vector<vector<bool>> vis;
    vector<int> d;
    int m;
    int n;

    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        m = maze.size();
        n = maze[0].size();
        d = destination;
        vis.resize(m, vector<bool>(n, false));
        this->maze = maze;
        dfs(start[0], start[1]);
        return vis[d[0]][d[1]];
    }

    void dfs(int i, int j) {
        if (vis[i][j]) return;
        vis[i][j] = true;
        if (i == d[0] && j == d[1]) return;
        vector<int> dirs = {-1, 0, 1, 0, -1};
        for (int k = 0; k < 4; ++k) {
            int x = i, y = j;
            int a = dirs[k], b = dirs[k + 1];
            while (x + a >= 0 && x + a < m && y + b >= 0 && y + b < n && maze[x + a][y + b] == 0) {
                x += a;
                y += b;
            }
            dfs(x, y);
        }
    }
};
```

#### Go

```go
func hasPath(maze [][]int, start []int, destination []int) bool {
	m, n := len(maze), len(maze[0])
	vis := make([][]bool, m)
	for i := range vis {
		vis[i] = make([]bool, n)
	}
	var dfs func(i, j int)
	dfs = func(i, j int) {
		if vis[i][j] {
			return
		}
		vis[i][j] = true
		if i == destination[0] && j == destination[1] {
			return
		}
		dirs := []int{-1, 0, 1, 0, -1}
		for k := 0; k < 4; k++ {
			x, y := i, j
			a, b := dirs[k], dirs[k+1]
			for x+a >= 0 && x+a < m && y+b >= 0 && y+b < n && maze[x+a][y+b] == 0 {
				x += a
				y += b
			}
			dfs(x, y)
		}
	}
	dfs(start[0], start[1])
	return vis[destination[0]][destination[1]]
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
    def hasPath(
        self, maze: List[List[int]], start: List[int], destination: List[int]
    ) -> bool:
        m, n = len(maze), len(maze[0])
        q = deque([start])
        rs, cs = start
        vis = {(rs, cs)}
        while q:
            i, j = q.popleft()
            for a, b in [[0, -1], [0, 1], [-1, 0], [1, 0]]:
                x, y = i, j
                while 0 <= x + a < m and 0 <= y + b < n and maze[x + a][y + b] == 0:
                    x, y = x + a, y + b
                if [x, y] == destination:
                    return True
                if (x, y) not in vis:
                    vis.add((x, y))
                    q.append((x, y))
        return False
```

#### Java

```java
class Solution {
    public boolean hasPath(int[][] maze, int[] start, int[] destination) {
        int m = maze.length;
        int n = maze[0].length;
        boolean[][] vis = new boolean[m][n];
        vis[start[0]][start[1]] = true;
        Deque<int[]> q = new LinkedList<>();
        q.offer(start);
        int[] dirs = {-1, 0, 1, 0, -1};
        while (!q.isEmpty()) {
            int[] p = q.poll();
            int i = p[0], j = p[1];
            for (int k = 0; k < 4; ++k) {
                int x = i, y = j;
                int a = dirs[k], b = dirs[k + 1];
                while (
                    x + a >= 0 && x + a < m && y + b >= 0 && y + b < n && maze[x + a][y + b] == 0) {
                    x += a;
                    y += b;
                }
                if (x == destination[0] && y == destination[1]) {
                    return true;
                }
                if (!vis[x][y]) {
                    vis[x][y] = true;
                    q.offer(new int[] {x, y});
                }
            }
        }
        return false;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size();
        int n = maze[0].size();
        queue<vector<int>> q{{start}};
        vector<vector<bool>> vis(m, vector<bool>(n));
        vis[start[0]][start[1]] = true;
        vector<int> dirs = {-1, 0, 1, 0, -1};
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            int i = p[0], j = p[1];
            for (int k = 0; k < 4; ++k) {
                int x = i, y = j;
                int a = dirs[k], b = dirs[k + 1];
                while (x + a >= 0 && x + a < m && y + b >= 0 && y + b < n && maze[x + a][y + b] == 0) {
                    x += a;
                    y += b;
                }
                if (x == destination[0] && y == destination[1]) return 1;
                if (!vis[x][y]) {
                    vis[x][y] = true;
                    q.push({x, y});
                }
            }
        }
        return 0;
    }
};
```

#### Go

```go
func hasPath(maze [][]int, start []int, destination []int) bool {
	m, n := len(maze), len(maze[0])
	vis := make([][]bool, m)
	for i := range vis {
		vis[i] = make([]bool, n)
	}
	vis[start[0]][start[1]] = true
	q := [][]int{start}
	dirs := []int{-1, 0, 1, 0, -1}
	for len(q) > 0 {
		i, j := q[0][0], q[0][1]
		q = q[1:]
		for k := 0; k < 4; k++ {
			x, y := i, j
			a, b := dirs[k], dirs[k+1]
			for x+a >= 0 && x+a < m && y+b >= 0 && y+b < n && maze[x+a][y+b] == 0 {
				x += a
				y += b
			}
			if x == destination[0] && y == destination[1] {
				return true
			}
			if !vis[x][y] {
				vis[x][y] = true
				q = append(q, []int{x, y})
			}
		}
	}
	return false
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [491. 非递减子序列](https://leetcode.cn/problems/non-decreasing-subsequences){#491}

{{< tabs "491" >}}

{{% tab "python" %}}
```python
class Solution:
    def findSubsequences(self, nums: List[int]) -> List[List[int]]:
        def dfs(u, last, t):
            if u == len(nums):
                if len(t) > 1:
                    ans.append(t[:])
                return
            if nums[u] >= last:
                t.append(nums[u])
                dfs(u + 1, nums[u], t)
                t.pop()
            if nums[u] != last:
                dfs(u + 1, last, t)

        ans = []
        dfs(0, -1000, [])
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[] nums;
    private List<List<Integer>> ans;

    public List<List<Integer>> findSubsequences(int[] nums) {
        this.nums = nums;
        ans = new ArrayList<>();
        dfs(0, -1000, new ArrayList<>());
        return ans;
    }

    private void dfs(int u, int last, List<Integer> t) {
        if (u == nums.length) {
            if (t.size() > 1) {
                ans.add(new ArrayList<>(t));
            }
            return;
        }
        if (nums[u] >= last) {
            t.add(nums[u]);
            dfs(u + 1, nums[u], t);
            t.remove(t.size() - 1);
        }
        if (nums[u] != last) {
            dfs(u + 1, last, t);
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> t;
        dfs(0, -1000, t, nums, ans);
        return ans;
    }

    void dfs(int u, int last, vector<int>& t, vector<int>& nums, vector<vector<int>>& ans) {
        if (u == nums.size()) {
            if (t.size() > 1) ans.push_back(t);
            return;
        }
        if (nums[u] >= last) {
            t.push_back(nums[u]);
            dfs(u + 1, nums[u], t, nums, ans);
            t.pop_back();
        }
        if (nums[u] != last) dfs(u + 1, last, t, nums, ans);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findSubsequences(nums []int) [][]int {
	var ans [][]int
	var dfs func(u, last int, t []int)
	dfs = func(u, last int, t []int) {
		if u == len(nums) {
			if len(t) > 1 {
				ans = append(ans, slices.Clone(t))
			}
			return
		}
		if nums[u] >= last {
			t = append(t, nums[u])
			dfs(u+1, nums[u], t)
			t = t[:len(t)-1]
		}
		if nums[u] != last {
			dfs(u+1, last, t)
		}
	}
	var t []int
	dfs(0, -1000, t)
	return ans
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>nums</code> ，找出并返回所有该数组中不同的递增子序列，递增子序列中 <strong>至少有两个元素</strong> 。你可以按 <strong>任意顺序</strong> 返回答案。</p>

<p>数组中可能含有重复元素，如出现两个整数相等，也可以视作递增序列的一种特殊情况。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [4,6,7,7]
<strong>输出：</strong>[[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [4,4,3,2,1]
<strong>输出：</strong>[[4,4]]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 15</code></li>
	<li><code>-100 &lt;= nums[i] &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS

DFS 递归枚举每个数字选中或不选中，这里需要满足两个条件：

1. 子序列需要递增（非严格递增），因此序列的后一个数要大于等于前一个数；
1. 子序列需要去重，这里重复的问题在于前后两个数相等并且不选中的情况，我们只在前后两个数不等的情况下，执行不选中的操作即可达到去重的效果。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findSubsequences(self, nums: List[int]) -> List[List[int]]:
        def dfs(u, last, t):
            if u == len(nums):
                if len(t) > 1:
                    ans.append(t[:])
                return
            if nums[u] >= last:
                t.append(nums[u])
                dfs(u + 1, nums[u], t)
                t.pop()
            if nums[u] != last:
                dfs(u + 1, last, t)

        ans = []
        dfs(0, -1000, [])
        return ans
```

#### Java

```java
class Solution {
    private int[] nums;
    private List<List<Integer>> ans;

    public List<List<Integer>> findSubsequences(int[] nums) {
        this.nums = nums;
        ans = new ArrayList<>();
        dfs(0, -1000, new ArrayList<>());
        return ans;
    }

    private void dfs(int u, int last, List<Integer> t) {
        if (u == nums.length) {
            if (t.size() > 1) {
                ans.add(new ArrayList<>(t));
            }
            return;
        }
        if (nums[u] >= last) {
            t.add(nums[u]);
            dfs(u + 1, nums[u], t);
            t.remove(t.size() - 1);
        }
        if (nums[u] != last) {
            dfs(u + 1, last, t);
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> t;
        dfs(0, -1000, t, nums, ans);
        return ans;
    }

    void dfs(int u, int last, vector<int>& t, vector<int>& nums, vector<vector<int>>& ans) {
        if (u == nums.size()) {
            if (t.size() > 1) ans.push_back(t);
            return;
        }
        if (nums[u] >= last) {
            t.push_back(nums[u]);
            dfs(u + 1, nums[u], t, nums, ans);
            t.pop_back();
        }
        if (nums[u] != last) dfs(u + 1, last, t, nums, ans);
    }
};
```

#### Go

```go
func findSubsequences(nums []int) [][]int {
	var ans [][]int
	var dfs func(u, last int, t []int)
	dfs = func(u, last int, t []int) {
		if u == len(nums) {
			if len(t) > 1 {
				ans = append(ans, slices.Clone(t))
			}
			return
		}
		if nums[u] >= last {
			t = append(t, nums[u])
			dfs(u+1, nums[u], t)
			t = t[:len(t)-1]
		}
		if nums[u] != last {
			dfs(u+1, last, t)
		}
	}
	var t []int
	dfs(0, -1000, t)
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [492. 构造矩形](https://leetcode.cn/problems/construct-the-rectangle){#492}

{{< tabs "492" >}}

{{% tab "python" %}}
```python
class Solution:
    def constructRectangle(self, area: int) -> List[int]:
        w = int(sqrt(area))
        while area % w != 0:
            w -= 1
        return [area // w, w]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] constructRectangle(int area) {
        int w = (int) Math.sqrt(area);
        while (area % w != 0) {
            --w;
        }
        return new int[] {area / w, w};
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> constructRectangle(int area) {
        int w = sqrt(1.0 * area);
        while (area % w != 0) --w;
        return {area / w, w};
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func constructRectangle(area int) []int {
	w := int(math.Sqrt(float64(area)))
	for area%w != 0 {
		w--
	}
	return []int{area / w, w}
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>作为一位web开发者， 懂得怎样去规划一个页面的尺寸是很重要的。 所以，现给定一个具体的矩形页面面积，你的任务是设计一个长度为 L 和宽度为 W 且满足以下要求的矩形的页面。要求：</p>

<ol>
	<li>你设计的矩形页面必须等于给定的目标面积。</li>
	<li>宽度 <code>W</code>&nbsp;不应大于长度 <code>L</code> ，换言之，要求 <code>L &gt;= W </code>。</li>
	<li>长度 <code>L</code> 和宽度 <code>W</code>&nbsp;之间的差距应当尽可能小。</li>
</ol>

<p>返回一个&nbsp;<em>数组</em>&nbsp;<code>[L, W]</code>，其中 <em><code>L</code> 和 <code>W</code> 是你按照顺序设计的网页的长度和宽度</em>。<br />
&nbsp;</p>

<p><strong>示例1：</strong></p>

<pre>
<strong>输入:</strong> 4
<strong>输出:</strong> [2, 2]
<strong>解释:</strong> 目标面积是 4， 所有可能的构造方案有 [1,4], [2,2], [4,1]。
但是根据要求2，[1,4] 不符合要求; 根据要求3，[2,2] 比 [4,1] 更能符合要求. 所以输出长度 L 为 2， 宽度 W 为 2。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> area = 37
<strong>输出:</strong> [37,1]
</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入:</strong> area = 122122
<strong>输出:</strong> [427,286]
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= area &lt;= 10<sup>7</sup></code></li>
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
    def constructRectangle(self, area: int) -> List[int]:
        w = int(sqrt(area))
        while area % w != 0:
            w -= 1
        return [area // w, w]
```

#### Java

```java
class Solution {
    public int[] constructRectangle(int area) {
        int w = (int) Math.sqrt(area);
        while (area % w != 0) {
            --w;
        }
        return new int[] {area / w, w};
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> constructRectangle(int area) {
        int w = sqrt(1.0 * area);
        while (area % w != 0) --w;
        return {area / w, w};
    }
};
```

#### Go

```go
func constructRectangle(area int) []int {
	w := int(math.Sqrt(float64(area)))
	for area%w != 0 {
		w--
	}
	return []int{area / w, w}
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [493. 翻转对](https://leetcode.cn/problems/reverse-pairs){#493}

{{< tabs "493" >}}

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
            self.tr[u].v += 1
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
            v += self.query(u << 1, l, r)
        if r > mid:
            v += self.query(u << 1 | 1, l, r)
        return v


class Solution:
    def reversePairs(self, nums: List[int]) -> int:
        s = set()
        for num in nums:
            s.add(num)
            s.add(num * 2)
        alls = sorted(s)
        m = {v: i for i, v in enumerate(alls, 1)}
        tree = SegmentTree(len(m))
        ans = 0
        for v in nums[::-1]:
            x = m[v]
            ans += tree.query(1, 1, x - 1)
            tree.modify(1, m[v * 2], 1)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int reversePairs(int[] nums) {
        TreeSet<Long> ts = new TreeSet<>();
        for (int num : nums) {
            ts.add((long) num);
            ts.add((long) num * 2);
        }
        Map<Long, Integer> m = new HashMap<>();
        int idx = 0;
        for (long num : ts) {
            m.put(num, ++idx);
        }
        SegmentTree tree = new SegmentTree(m.size());
        int ans = 0;
        for (int i = nums.length - 1; i >= 0; --i) {
            int x = m.get((long) nums[i]);
            ans += tree.query(1, 1, x - 1);
            tree.modify(1, m.get((long) nums[i] * 2), 1);
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
    int reversePairs(vector<int>& nums) {
        set<long long> s;
        for (int num : nums) {
            s.insert(num);
            s.insert(num * 2ll);
        }
        unordered_map<long long, int> m;
        int idx = 0;
        for (long long num : s) m[num] = ++idx;
        SegmentTree* tree = new SegmentTree(m.size());
        int ans = 0;
        for (int i = nums.size() - 1; i >= 0; --i) {
            ans += tree->query(1, 1, m[nums[i]] - 1);
            tree->modify(1, m[nums[i] * 2ll], 1);
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

func reversePairs(nums []int) int {
	s := make(map[int]bool)
	for _, num := range nums {
		s[num] = true
		s[num*2] = true
	}
	var alls []int
	for num := range s {
		alls = append(alls, num)
	}
	sort.Ints(alls)
	m := make(map[int]int)
	for i, num := range alls {
		m[num] = i + 1
	}
	tree := newBinaryIndexedTree(len(m))
	ans := 0
	for i := len(nums) - 1; i >= 0; i-- {
		ans += tree.query(m[nums[i]] - 1)
		tree.update(m[nums[i]*2], 1)
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

<p>给定一个数组&nbsp;<code>nums</code>&nbsp;，如果&nbsp;<code>i &lt; j</code>&nbsp;且&nbsp;<code>nums[i] &gt; 2*nums[j]</code>&nbsp;我们就将&nbsp;<code>(i, j)</code>&nbsp;称作一个<strong><em>重要翻转对</em></strong>。</p>

<p>你需要返回给定数组中的重要翻转对的数量。</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入</strong>: [1,3,2,3,1]
<strong>输出</strong>: 2
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入</strong>: [2,4,3,5,1]
<strong>输出</strong>: 3
</pre>

<p><strong>注意:</strong></p>

<ol>
	<li>给定数组的长度不会超过<code>50000</code>。</li>
	<li>输入数组中的所有数字都在32位整数的表示范围内。</li>
</ol>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：归并排序

归并排序的过程中，如果左边的数大于右边的数，则右边的数与左边的数之后的数都构成逆序对。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为数组长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def reversePairs(self, nums: List[int]) -> int:
        def merge_sort(l, r):
            if l >= r:
                return 0
            mid = (l + r) >> 1
            ans = merge_sort(l, mid) + merge_sort(mid + 1, r)
            t = []
            i, j = l, mid + 1
            while i <= mid and j <= r:
                if nums[i] <= 2 * nums[j]:
                    i += 1
                else:
                    ans += mid - i + 1
                    j += 1
            i, j = l, mid + 1
            while i <= mid and j <= r:
                if nums[i] <= nums[j]:
                    t.append(nums[i])
                    i += 1
                else:
                    t.append(nums[j])
                    j += 1
            t.extend(nums[i : mid + 1])
            t.extend(nums[j : r + 1])
            nums[l : r + 1] = t
            return ans

        return merge_sort(0, len(nums) - 1)
```

#### Java

```java
class Solution {
    private int[] nums;
    private int[] t;

    public int reversePairs(int[] nums) {
        this.nums = nums;
        int n = nums.length;
        this.t = new int[n];
        return mergeSort(0, n - 1);
    }

    private int mergeSort(int l, int r) {
        if (l >= r) {
            return 0;
        }
        int mid = (l + r) >> 1;
        int ans = mergeSort(l, mid) + mergeSort(mid + 1, r);
        int i = l, j = mid + 1, k = 0;
        while (i <= mid && j <= r) {
            if (nums[i] <= nums[j] * 2L) {
                ++i;
            } else {
                ans += mid - i + 1;
                ++j;
            }
        }
        i = l;
        j = mid + 1;
        while (i <= mid && j <= r) {
            if (nums[i] <= nums[j]) {
                t[k++] = nums[i++];
            } else {
                t[k++] = nums[j++];
            }
        }
        while (i <= mid) {
            t[k++] = nums[i++];
        }
        while (j <= r) {
            t[k++] = nums[j++];
        }
        for (i = l; i <= r; ++i) {
            nums[i] = t[i - l];
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int t[n];
        function<int(int, int)> mergeSort = [&](int l, int r) -> int {
            if (l >= r) {
                return 0;
            }
            int mid = (l + r) >> 1;
            int ans = mergeSort(l, mid) + mergeSort(mid + 1, r);
            int i = l, j = mid + 1, k = 0;
            while (i <= mid && j <= r) {
                if (nums[i] <= nums[j] * 2LL) {
                    ++i;
                } else {
                    ans += mid - i + 1;
                    ++j;
                }
            }
            i = l;
            j = mid + 1;
            while (i <= mid && j <= r) {
                if (nums[i] <= nums[j]) {
                    t[k++] = nums[i++];
                } else {
                    t[k++] = nums[j++];
                }
            }
            while (i <= mid) {
                t[k++] = nums[i++];
            }
            while (j <= r) {
                t[k++] = nums[j++];
            }
            for (i = l; i <= r; ++i) {
                nums[i] = t[i - l];
            }
            return ans;
        };
        return mergeSort(0, n - 1);
    }
};
```

#### Go

```go
func reversePairs(nums []int) int {
	n := len(nums)
	t := make([]int, n)
	var mergeSort func(l, r int) int
	mergeSort = func(l, r int) int {
		if l >= r {
			return 0
		}
		mid := (l + r) >> 1
		ans := mergeSort(l, mid) + mergeSort(mid+1, r)
		i, j, k := l, mid+1, 0
		for i <= mid && j <= r {
			if nums[i] <= nums[j]*2 {
				i++
			} else {
				ans += mid - i + 1
				j++
			}
		}
		i, j = l, mid+1
		for i <= mid && j <= r {
			if nums[i] <= nums[j] {
				t[k] = nums[i]
				k, i = k+1, i+1
			} else {
				t[k] = nums[j]
				k, j = k+1, j+1
			}
		}
		for ; i <= mid; i, k = i+1, k+1 {
			t[k] = nums[i]
		}
		for ; j <= r; j, k = j+1, k+1 {
			t[k] = nums[j]
		}
		for i = l; i <= r; i++ {
			nums[i] = t[i-l]
		}
		return ans
	}
	return mergeSort(0, n-1)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：树状数组

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
    def reversePairs(self, nums: List[int]) -> int:
        s = set()
        for num in nums:
            s.add(num)
            s.add(num * 2)
        alls = sorted(s)
        m = {v: i for i, v in enumerate(alls, 1)}
        ans = 0
        tree = BinaryIndexedTree(len(m))
        for num in nums[::-1]:
            ans += tree.query(m[num] - 1)
            tree.update(m[num * 2], 1)
        return ans
```

#### Java

```java
class Solution {
    public int reversePairs(int[] nums) {
        TreeSet<Long> ts = new TreeSet<>();
        for (int num : nums) {
            ts.add((long) num);
            ts.add((long) num * 2);
        }
        Map<Long, Integer> m = new HashMap<>();
        int idx = 0;
        for (long num : ts) {
            m.put(num, ++idx);
        }
        BinaryIndexedTree tree = new BinaryIndexedTree(m.size());
        int ans = 0;
        for (int i = nums.length - 1; i >= 0; --i) {
            int x = m.get((long) nums[i]);
            ans += tree.query(x - 1);
            tree.update(m.get((long) nums[i] * 2), 1);
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
    int reversePairs(vector<int>& nums) {
        set<long long> s;
        for (int num : nums) {
            s.insert(num);
            s.insert(num * 2ll);
        }
        unordered_map<long long, int> m;
        int idx = 0;
        for (long long num : s) m[num] = ++idx;
        BinaryIndexedTree* tree = new BinaryIndexedTree(m.size());
        int ans = 0;
        for (int i = nums.size() - 1; i >= 0; --i) {
            ans += tree->query(m[nums[i]] - 1);
            tree->update(m[nums[i] * 2ll], 1);
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

func reversePairs(nums []int) int {
	s := make(map[int]bool)
	for _, num := range nums {
		s[num] = true
		s[num*2] = true
	}
	var alls []int
	for num := range s {
		alls = append(alls, num)
	}
	sort.Ints(alls)
	m := make(map[int]int)
	for i, num := range alls {
		m[num] = i + 1
	}
	tree := newBinaryIndexedTree(len(m))
	ans := 0
	for i := len(nums) - 1; i >= 0; i-- {
		ans += tree.query(m[nums[i]] - 1)
		tree.update(m[nums[i]*2], 1)
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法三：线段树

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
            self.tr[u].v += 1
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
            v += self.query(u << 1, l, r)
        if r > mid:
            v += self.query(u << 1 | 1, l, r)
        return v


class Solution:
    def reversePairs(self, nums: List[int]) -> int:
        s = set()
        for num in nums:
            s.add(num)
            s.add(num * 2)
        alls = sorted(s)
        m = {v: i for i, v in enumerate(alls, 1)}
        tree = SegmentTree(len(m))
        ans = 0
        for v in nums[::-1]:
            x = m[v]
            ans += tree.query(1, 1, x - 1)
            tree.modify(1, m[v * 2], 1)
        return ans
```

#### Java

```java
class Solution {
    public int reversePairs(int[] nums) {
        TreeSet<Long> ts = new TreeSet<>();
        for (int num : nums) {
            ts.add((long) num);
            ts.add((long) num * 2);
        }
        Map<Long, Integer> m = new HashMap<>();
        int idx = 0;
        for (long num : ts) {
            m.put(num, ++idx);
        }
        SegmentTree tree = new SegmentTree(m.size());
        int ans = 0;
        for (int i = nums.length - 1; i >= 0; --i) {
            int x = m.get((long) nums[i]);
            ans += tree.query(1, 1, x - 1);
            tree.modify(1, m.get((long) nums[i] * 2), 1);
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
        if (l <= mid) v = query(u << 1, l, r);
        if (r > mid) v += query(u << 1 | 1, l, r);
        return v;
    }
};

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        set<long long> s;
        for (int num : nums) {
            s.insert(num);
            s.insert(num * 2ll);
        }
        unordered_map<long long, int> m;
        int idx = 0;
        for (long long num : s) m[num] = ++idx;
        SegmentTree* tree = new SegmentTree(m.size());
        int ans = 0;
        for (int i = nums.size() - 1; i >= 0; --i) {
            ans += tree->query(1, 1, m[nums[i]] - 1);
            tree->modify(1, m[nums[i] * 2ll], 1);
        }
        return ans;
    }
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [494. 目标和](https://leetcode.cn/problems/target-sum){#494}

{{< tabs "494" >}}

{{% tab "python" %}}
```python
class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        s = sum(nums)
        if s < target or (s - target) % 2:
            return 0
        n = (s - target) // 2
        f = [0] * (n + 1)
        f[0] = 1
        for x in nums:
            for j in range(n, x - 1, -1):
                f[j] += f[j - x]
        return f[n]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int findTargetSumWays(int[] nums, int target) {
        int s = Arrays.stream(nums).sum();
        if (s < target || (s - target) % 2 != 0) {
            return 0;
        }
        int n = (s - target) / 2;
        int[] f = new int[n + 1];
        f[0] = 1;
        for (int num : nums) {
            for (int j = n; j >= num; --j) {
                f[j] += f[j - num];
            }
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
    int findTargetSumWays(vector<int>& nums, int target) {
        int s = accumulate(nums.begin(), nums.end(), 0);
        if (s < target || (s - target) % 2) {
            return 0;
        }
        int n = (s - target) / 2;
        int f[n + 1];
        memset(f, 0, sizeof(f));
        f[0] = 1;
        for (int x : nums) {
            for (int j = n; j >= x; --j) {
                f[j] += f[j - x];
            }
        }
        return f[n];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findTargetSumWays(nums []int, target int) int {
	s := 0
	for _, x := range nums {
		s += x
	}
	if s < target || (s-target)%2 != 0 {
		return 0
	}
	n := (s - target) / 2
	f := make([]int, n+1)
	f[0] = 1
	for _, x := range nums {
		for j := n; j >= x; j-- {
			f[j] += f[j-x]
		}
	}
	return f[n]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findTargetSumWays(nums: number[], target: number): number {
    const s = nums.reduce((a, b) => a + b, 0);
    if (s < target || (s - target) % 2) {
        return 0;
    }
    const n = ((s - target) / 2) | 0;
    const f = Array(n + 1).fill(0);
    f[0] = 1;
    for (const x of nums) {
        for (let j = n; j >= x; j--) {
            f[j] += f[j - x];
        }
    }
    return f[n];
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn find_target_sum_ways(nums: Vec<i32>, target: i32) -> i32 {
        let s: i32 = nums.iter().sum();
        if s < target || (s - target) % 2 != 0 {
            return 0;
        }
        let n = ((s - target) / 2) as usize;
        let mut f = vec![0; n + 1];
        f[0] = 1;
        for x in nums {
            for j in (x as usize..=n).rev() {
                f[j] += f[j - x as usize];
            }
        }
        f[n]
    }
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
var findTargetSumWays = function (nums, target) {
    const s = nums.reduce((a, b) => a + b, 0);
    if (s < target || (s - target) % 2) {
        return 0;
    }
    const n = (s - target) / 2;
    const f = Array(n + 1).fill(0);
    f[0] = 1;
    for (const x of nums) {
        for (let j = n; j >= x; j--) {
            f[j] += f[j - x];
        }
    }
    return f[n];
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个非负整数数组 <code>nums</code> 和一个整数 <code>target</code> 。</p>

<p>向数组中的每个整数前添加&nbsp;<code>'+'</code> 或 <code>'-'</code> ，然后串联起所有整数，可以构造一个 <strong>表达式</strong> ：</p>

<ul>
	<li>例如，<code>nums = [2, 1]</code> ，可以在 <code>2</code> 之前添加 <code>'+'</code> ，在 <code>1</code> 之前添加 <code>'-'</code> ，然后串联起来得到表达式 <code>"+2-1"</code> 。</li>
</ul>

<p>返回可以通过上述方法构造的、运算结果等于 <code>target</code> 的不同 <strong>表达式</strong> 的数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,1,1,1,1], target = 3
<strong>输出：</strong>5
<strong>解释：</strong>一共有 5 种方法让最终目标和为 3 。
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1], target = 1
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 20</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 1000</code></li>
	<li><code>0 &lt;= sum(nums[i]) &lt;= 1000</code></li>
	<li><code>-1000 &lt;= target &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们记数组 $\textit{nums}$ 所有元素的和为 $s$，添加负号的元素之和为 $x$，则添加正号的元素之和为 $s - x$，则有：

$$
(s - x) - x = \textit{target} \Rightarrow x = \frac{s - \textit{target}}{2}
$$

由于 $x \geq 0$，且 $x$ 为整数，所以 $s \geq \textit{target}$ 且 $s - \textit{target}$ 为偶数。如果不满足这两个条件，则直接返回 $0$。

接下来，我们可以将问题转化为：在数组 $\textit{nums}$ 中选取若干元素，使得这些元素之和等于 $\frac{s - \textit{target}}{2}$，问有多少种选取方法。

我们可以使用动态规划来解决这个问题。定义 $f[i][j]$ 表示在数组 $\textit{nums}$ 的前 $i$ 个元素中选取若干元素，使得这些元素之和等于 $j$ 的选取方案数。

对于 $\textit{nums}[i - 1]$，我们有两种选择：选取或不选取。如果我们不选取 $\textit{nums}[i - 1]$，则 $f[i][j] = f[i - 1][j]$；如果我们选取 $\textit{nums}[i - 1]$，则 $f[i][j] = f[i - 1][j - \textit{nums}[i - 1]]$。因此，状态转移方程为：

$$
f[i][j] = f[i - 1][j] + f[i - 1][j - \textit{nums}[i - 1]]
$$

其中，选取的前提是 $j \geq \textit{nums}[i - 1]$。

最终答案即为 $f[m][n]$。其中 $m$ 为数组 $\textit{nums}$ 的长度，而 $n = \frac{s - \textit{target}}{2}$。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m \times n)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        s = sum(nums)
        if s < target or (s - target) % 2:
            return 0
        m, n = len(nums), (s - target) // 2
        f = [[0] * (n + 1) for _ in range(m + 1)]
        f[0][0] = 1
        for i, x in enumerate(nums, 1):
            for j in range(n + 1):
                f[i][j] = f[i - 1][j]
                if j >= x:
                    f[i][j] += f[i - 1][j - x]
        return f[m][n]
```

#### Java

```java
class Solution {
    public int findTargetSumWays(int[] nums, int target) {
        int s = Arrays.stream(nums).sum();
        if (s < target || (s - target) % 2 != 0) {
            return 0;
        }
        int m = nums.length;
        int n = (s - target) / 2;
        int[][] f = new int[m + 1][n + 1];
        f[0][0] = 1;
        for (int i = 1; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                f[i][j] = f[i - 1][j];
                if (j >= nums[i - 1]) {
                    f[i][j] += f[i - 1][j - nums[i - 1]];
                }
            }
        }
        return f[m][n];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int s = accumulate(nums.begin(), nums.end(), 0);
        if (s < target || (s - target) % 2) {
            return 0;
        }
        int m = nums.size();
        int n = (s - target) / 2;
        int f[m + 1][n + 1];
        memset(f, 0, sizeof(f));
        f[0][0] = 1;
        for (int i = 1; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                f[i][j] = f[i - 1][j];
                if (j >= nums[i - 1]) {
                    f[i][j] += f[i - 1][j - nums[i - 1]];
                }
            }
        }
        return f[m][n];
    }
};
```

#### Go

```go
func findTargetSumWays(nums []int, target int) int {
	s := 0
	for _, x := range nums {
		s += x
	}
	if s < target || (s-target)%2 != 0 {
		return 0
	}
	m, n := len(nums), (s-target)/2
	f := make([][]int, m+1)
	for i := range f {
		f[i] = make([]int, n+1)
	}
	f[0][0] = 1
	for i := 1; i <= m; i++ {
		for j := 0; j <= n; j++ {
			f[i][j] = f[i-1][j]
			if j >= nums[i-1] {
				f[i][j] += f[i-1][j-nums[i-1]]
			}
		}
	}
	return f[m][n]
}
```

#### TypeScript

```ts
function findTargetSumWays(nums: number[], target: number): number {
    const s = nums.reduce((a, b) => a + b, 0);
    if (s < target || (s - target) % 2) {
        return 0;
    }
    const [m, n] = [nums.length, ((s - target) / 2) | 0];
    const f: number[][] = Array.from({ length: m + 1 }, () => Array(n + 1).fill(0));
    f[0][0] = 1;
    for (let i = 1; i <= m; i++) {
        for (let j = 0; j <= n; j++) {
            f[i][j] = f[i - 1][j];
            if (j >= nums[i - 1]) {
                f[i][j] += f[i - 1][j - nums[i - 1]];
            }
        }
    }
    return f[m][n];
}
```

#### Rust

```rust
impl Solution {
    pub fn find_target_sum_ways(nums: Vec<i32>, target: i32) -> i32 {
        let s: i32 = nums.iter().sum();
        if s < target || (s - target) % 2 != 0 {
            return 0;
        }
        let m = nums.len();
        let n = ((s - target) / 2) as usize;
        let mut f = vec![vec![0; n + 1]; m + 1];
        f[0][0] = 1;
        for i in 1..=m {
            for j in 0..=n {
                f[i][j] = f[i - 1][j];
                if j as i32 >= nums[i - 1] {
                    f[i][j] += f[i - 1][j - nums[i - 1] as usize];
                }
            }
        }
        f[m][n]
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var findTargetSumWays = function (nums, target) {
    const s = nums.reduce((a, b) => a + b, 0);
    if (s < target || (s - target) % 2) {
        return 0;
    }
    const [m, n] = [nums.length, ((s - target) / 2) | 0];
    const f = Array.from({ length: m + 1 }, () => Array(n + 1).fill(0));
    f[0][0] = 1;
    for (let i = 1; i <= m; i++) {
        for (let j = 0; j <= n; j++) {
            f[i][j] = f[i - 1][j];
            if (j >= nums[i - 1]) {
                f[i][j] += f[i - 1][j - nums[i - 1]];
            }
        }
    }
    return f[m][n];
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：动态规划（空间优化）

我们可以发现，方法一中的状态转移方程中，$f[i][j]$ 的值只和 $f[i - 1][j]$ 以及 $f[i - 1][j - \textit{nums}[i - 1]]$ 有关，因此我们去掉第一维空间，只使用一维数组即可。

时间复杂度 $O(m \times n)$，空间复杂度 $O(n)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        s = sum(nums)
        if s < target or (s - target) % 2:
            return 0
        n = (s - target) // 2
        f = [0] * (n + 1)
        f[0] = 1
        for x in nums:
            for j in range(n, x - 1, -1):
                f[j] += f[j - x]
        return f[n]
```

#### Java

```java
class Solution {
    public int findTargetSumWays(int[] nums, int target) {
        int s = Arrays.stream(nums).sum();
        if (s < target || (s - target) % 2 != 0) {
            return 0;
        }
        int n = (s - target) / 2;
        int[] f = new int[n + 1];
        f[0] = 1;
        for (int num : nums) {
            for (int j = n; j >= num; --j) {
                f[j] += f[j - num];
            }
        }
        return f[n];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int s = accumulate(nums.begin(), nums.end(), 0);
        if (s < target || (s - target) % 2) {
            return 0;
        }
        int n = (s - target) / 2;
        int f[n + 1];
        memset(f, 0, sizeof(f));
        f[0] = 1;
        for (int x : nums) {
            for (int j = n; j >= x; --j) {
                f[j] += f[j - x];
            }
        }
        return f[n];
    }
};
```

#### Go

```go
func findTargetSumWays(nums []int, target int) int {
	s := 0
	for _, x := range nums {
		s += x
	}
	if s < target || (s-target)%2 != 0 {
		return 0
	}
	n := (s - target) / 2
	f := make([]int, n+1)
	f[0] = 1
	for _, x := range nums {
		for j := n; j >= x; j-- {
			f[j] += f[j-x]
		}
	}
	return f[n]
}
```

#### TypeScript

```ts
function findTargetSumWays(nums: number[], target: number): number {
    const s = nums.reduce((a, b) => a + b, 0);
    if (s < target || (s - target) % 2) {
        return 0;
    }
    const n = ((s - target) / 2) | 0;
    const f = Array(n + 1).fill(0);
    f[0] = 1;
    for (const x of nums) {
        for (let j = n; j >= x; j--) {
            f[j] += f[j - x];
        }
    }
    return f[n];
}
```

#### Rust

```rust
impl Solution {
    pub fn find_target_sum_ways(nums: Vec<i32>, target: i32) -> i32 {
        let s: i32 = nums.iter().sum();
        if s < target || (s - target) % 2 != 0 {
            return 0;
        }
        let n = ((s - target) / 2) as usize;
        let mut f = vec![0; n + 1];
        f[0] = 1;
        for x in nums {
            for j in (x as usize..=n).rev() {
                f[j] += f[j - x as usize];
            }
        }
        f[n]
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var findTargetSumWays = function (nums, target) {
    const s = nums.reduce((a, b) => a + b, 0);
    if (s < target || (s - target) % 2) {
        return 0;
    }
    const n = (s - target) / 2;
    const f = Array(n + 1).fill(0);
    f[0] = 1;
    for (const x of nums) {
        for (let j = n; j >= x; j--) {
            f[j] += f[j - x];
        }
    }
    return f[n];
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [495. 提莫攻击](https://leetcode.cn/problems/teemo-attacking){#495}

{{< tabs "495" >}}

{{% tab "python" %}}
```python
class Solution:
    def findPoisonedDuration(self, timeSeries: List[int], duration: int) -> int:
        ans = duration
        for a, b in pairwise(timeSeries):
            ans += min(duration, b - a)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int findPoisonedDuration(int[] timeSeries, int duration) {
        int n = timeSeries.length;
        int ans = duration;
        for (int i = 1; i < n; ++i) {
            ans += Math.min(duration, timeSeries[i] - timeSeries[i - 1]);
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
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ans = duration;
        int n = timeSeries.size();
        for (int i = 1; i < n; ++i) {
            ans += min(duration, timeSeries[i] - timeSeries[i - 1]);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findPoisonedDuration(timeSeries []int, duration int) (ans int) {
	ans = duration
	for i, x := range timeSeries[1:] {
		ans += min(duration, x-timeSeries[i])
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findPoisonedDuration(timeSeries: number[], duration: number): number {
    const n = timeSeries.length;
    let ans = duration;
    for (let i = 1; i < n; ++i) {
        ans += Math.min(duration, timeSeries[i] - timeSeries[i - 1]);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int FindPoisonedDuration(int[] timeSeries, int duration) {
        int ans = duration;
        int n = timeSeries.Length;
        for (int i = 1; i < n; ++i) {
            ans += Math.Min(duration, timeSeries[i] - timeSeries[i - 1]);
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

<p>在《英雄联盟》的世界中，有一个叫 “提莫” 的英雄。他的攻击可以让敌方英雄艾希（编者注：寒冰射手）进入中毒状态。</p>

<p>当提莫攻击艾希，艾希的中毒状态正好持续&nbsp;<code>duration</code> 秒。</p>

<p>正式地讲，提莫在 <code>t</code> 发起攻击意味着艾希在时间区间 <code>[t, t + duration - 1]</code>（含 <code>t</code> 和 <code>t + duration - 1</code>）处于中毒状态。如果提莫在中毒影响结束 <strong>前</strong> 再次攻击，中毒状态计时器将会 <strong>重置</strong> ，在新的攻击之后，中毒影响将会在 <code>duration</code> 秒后结束。</p>

<p>给你一个 <strong>非递减</strong> 的整数数组 <code>timeSeries</code> ，其中 <code>timeSeries[i]</code> 表示提莫在 <code>timeSeries[i]</code> 秒时对艾希发起攻击，以及一个表示中毒持续时间的整数 <code>duration</code> 。</p>

<p>返回艾希处于中毒状态的 <strong>总</strong> 秒数。</p>
&nbsp;

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>timeSeries = [1,4], duration = 2
<strong>输出：</strong>4
<strong>解释：</strong>提莫攻击对艾希的影响如下：
- 第 1 秒，提莫攻击艾希并使其立即中毒。中毒状态会维持 2 秒，即第 1 秒和第 2 秒。
- 第 4 秒，提莫再次攻击艾希，艾希中毒状态又持续 2 秒，即第 4 秒和第 5 秒。
艾希在第 1、2、4、5 秒处于中毒状态，所以总中毒秒数是 4 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>timeSeries = [1,2], duration = 2
<strong>输出：</strong>3
<strong>解释：</strong>提莫攻击对艾希的影响如下：
- 第 1 秒，提莫攻击艾希并使其立即中毒。中毒状态会维持 2 秒，即第 1 秒和第 2 秒。
- 第 2 秒，提莫再次攻击艾希，并重置中毒计时器，艾希中毒状态需要持续 2 秒，即第 2 秒和第 3 秒。
艾希在第 1、2、3 秒处于中毒状态，所以总中毒秒数是 3 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= timeSeries.length &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= timeSeries[i], duration &lt;= 10<sup>7</sup></code></li>
	<li><code>timeSeries</code> 按 <strong>非递减</strong> 顺序排列</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：一次遍历

我们先考虑最后一次攻击，此次攻击一定可以使得艾希处于中毒状态，所以总中毒时间至少为 `duration`。

接下来，我们考虑前 $n-1$ 次攻击，每一次攻击的中毒持续时间为 $min(duration, timeSeries[i] - timeSeries[i-1])$，其中 $i$ 从 1 开始。我们将这些中毒持续时间累加起来，即为总中毒时间。

时间复杂度 $O(n)$，空间复杂度 $O(1)$。其中 $n$ 为数组 `timeSeries` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findPoisonedDuration(self, timeSeries: List[int], duration: int) -> int:
        ans = duration
        for a, b in pairwise(timeSeries):
            ans += min(duration, b - a)
        return ans
```

#### Java

```java
class Solution {
    public int findPoisonedDuration(int[] timeSeries, int duration) {
        int n = timeSeries.length;
        int ans = duration;
        for (int i = 1; i < n; ++i) {
            ans += Math.min(duration, timeSeries[i] - timeSeries[i - 1]);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ans = duration;
        int n = timeSeries.size();
        for (int i = 1; i < n; ++i) {
            ans += min(duration, timeSeries[i] - timeSeries[i - 1]);
        }
        return ans;
    }
};
```

#### Go

```go
func findPoisonedDuration(timeSeries []int, duration int) (ans int) {
	ans = duration
	for i, x := range timeSeries[1:] {
		ans += min(duration, x-timeSeries[i])
	}
	return
}
```

#### TypeScript

```ts
function findPoisonedDuration(timeSeries: number[], duration: number): number {
    const n = timeSeries.length;
    let ans = duration;
    for (let i = 1; i < n; ++i) {
        ans += Math.min(duration, timeSeries[i] - timeSeries[i - 1]);
    }
    return ans;
}
```

#### C#

```cs
public class Solution {
    public int FindPoisonedDuration(int[] timeSeries, int duration) {
        int ans = duration;
        int n = timeSeries.Length;
        for (int i = 1; i < n; ++i) {
            ans += Math.Min(duration, timeSeries[i] - timeSeries[i - 1]);
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

# [496. 下一个更大元素 I](https://leetcode.cn/problems/next-greater-element-i){#496}

{{< tabs "496" >}}

{{% tab "python" %}}
```python
class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        stk = []
        d = {}
        for x in nums2[::-1]:
            while stk and stk[-1] < x:
                stk.pop()
            if stk:
                d[x] = stk[-1]
            stk.append(x)
        return [d.get(x, -1) for x in nums1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        Deque<Integer> stk = new ArrayDeque<>();
        int m = nums1.length, n = nums2.length;
        Map<Integer, Integer> d = new HashMap(n);
        for (int i = n - 1; i >= 0; --i) {
            int x = nums2[i];
            while (!stk.isEmpty() && stk.peek() < x) {
                stk.pop();
            }
            if (!stk.isEmpty()) {
                d.put(x, stk.peek());
            }
            stk.push(x);
        }
        int[] ans = new int[m];
        for (int i = 0; i < m; ++i) {
            ans[i] = d.getOrDefault(nums1[i], -1);
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
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> stk;
        unordered_map<int, int> d;
        ranges::reverse(nums2);
        for (int x : nums2) {
            while (!stk.empty() && stk.top() < x) {
                stk.pop();
            }
            if (!stk.empty()) {
                d[x] = stk.top();
            }
            stk.push(x);
        }
        vector<int> ans;
        for (int x : nums1) {
            ans.push_back(d.contains(x) ? d[x] : -1);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func nextGreaterElement(nums1 []int, nums2 []int) (ans []int) {
	stk := []int{}
	d := map[int]int{}
	for i := len(nums2) - 1; i >= 0; i-- {
		x := nums2[i]
		for len(stk) > 0 && stk[len(stk)-1] < x {
			stk = stk[:len(stk)-1]
		}
		if len(stk) > 0 {
			d[x] = stk[len(stk)-1]
		}
		stk = append(stk, x)
	}
	for _, x := range nums1 {
		if v, ok := d[x]; ok {
			ans = append(ans, v)
		} else {
			ans = append(ans, -1)
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function nextGreaterElement(nums1: number[], nums2: number[]): number[] {
    const stk: number[] = [];
    const d: Record<number, number> = {};
    for (const x of nums2.reverse()) {
        while (stk.length && stk.at(-1)! < x) {
            stk.pop();
        }
        d[x] = stk.length ? stk.at(-1)! : -1;
        stk.push(x);
    }
    return nums1.map(x => d[x]);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashMap;

impl Solution {
    pub fn next_greater_element(nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<i32> {
        let mut stk = Vec::new();
        let mut d = HashMap::new();
        for &x in nums2.iter().rev() {
            while let Some(&top) = stk.last() {
                if top <= x {
                    stk.pop();
                } else {
                    break;
                }
            }
            if let Some(&top) = stk.last() {
                d.insert(x, top);
            }
            stk.push(x);
        }

        nums1
            .into_iter()
            .map(|x| *d.get(&x).unwrap_or(&-1))
            .collect()
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var nextGreaterElement = function (nums1, nums2) {
    const stk = [];
    const d = {};
    for (const x of nums2.reverse()) {
        while (stk.length && stk.at(-1) < x) {
            stk.pop();
        }
        d[x] = stk.length ? stk.at(-1) : -1;
        stk.push(x);
    }
    return nums1.map(x => d[x]);
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p><code>nums1</code>&nbsp;中数字&nbsp;<code>x</code>&nbsp;的 <strong>下一个更大元素</strong> 是指&nbsp;<code>x</code>&nbsp;在&nbsp;<code>nums2</code> 中对应位置 <strong>右侧</strong> 的 <strong>第一个</strong> 比&nbsp;<code>x</code><strong>&nbsp;</strong>大的元素。</p>

<p>给你两个<strong> 没有重复元素</strong> 的数组&nbsp;<code>nums1</code> 和&nbsp;<code>nums2</code> ，下标从 <strong>0</strong> 开始计数，其中<code>nums1</code>&nbsp;是&nbsp;<code>nums2</code>&nbsp;的子集。</p>

<p>对于每个 <code>0 &lt;= i &lt; nums1.length</code> ，找出满足 <code>nums1[i] == nums2[j]</code> 的下标 <code>j</code> ，并且在 <code>nums2</code> 确定 <code>nums2[j]</code> 的 <strong>下一个更大元素</strong> 。如果不存在下一个更大元素，那么本次查询的答案是 <code>-1</code> 。</p>

<p>返回一个长度为&nbsp;<code>nums1.length</code> 的数组<em> </em><code>ans</code><em> </em>作为答案，满足<em> </em><code>ans[i]</code><em> </em>是如上所述的 <strong>下一个更大元素</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums1 = [4,1,2], nums2 = [1,3,4,2].
<strong>输出：</strong>[-1,3,-1]
<strong>解释：</strong>nums1 中每个值的下一个更大元素如下所述：
- 4 ，用加粗斜体标识，nums2 = [1,3,<strong>4</strong>,2]。不存在下一个更大元素，所以答案是 -1 。
- 1 ，用加粗斜体标识，nums2 = [<em><strong>1</strong></em>,3,4,2]。下一个更大元素是 3 。
- 2 ，用加粗斜体标识，nums2 = [1,3,4,<em><strong>2</strong></em>]。不存在下一个更大元素，所以答案是 -1 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums1 = [2,4], nums2 = [1,2,3,4].
<strong>输出：</strong>[3,-1]
<strong>解释：</strong>nums1 中每个值的下一个更大元素如下所述：
- 2 ，用加粗斜体标识，nums2 = [1,<em><strong>2</strong></em>,3,4]。下一个更大元素是 3 。
- 4 ，用加粗斜体标识，nums2 = [1,2,3,<em><strong>4</strong></em>]。不存在下一个更大元素，所以答案是 -1 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums1.length &lt;= nums2.length &lt;= 1000</code></li>
	<li><code>0 &lt;= nums1[i], nums2[i] &lt;= 10<sup>4</sup></code></li>
	<li><code>nums1</code>和<code>nums2</code>中所有整数 <strong>互不相同</strong></li>
	<li><code>nums1</code> 中的所有整数同样出现在 <code>nums2</code> 中</li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>你可以设计一个时间复杂度为 <code>O(nums1.length + nums2.length)</code> 的解决方案吗？</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：单调栈

我们可以从右往左遍历数组 $\textit{nums2}$，维护一个从栈顶到栈底单调递增的栈 $\textit{stk}$，并且用哈希表 $\textit{d}$ 记录每个元素的下一个更大元素。

遍历到元素 $x$ 时，如果栈不为空且栈顶元素小于 $x$，我们就不断弹出栈顶元素，直到栈为空或者栈顶元素大于等于 $x$。此时，如果栈不为空，栈顶元素就是 $x$ 的下一个更大元素，否则 $x$ 没有下一个更大元素。

最后我们遍历数组 $\textit{nums1}$，根据哈希表 $\textit{d}$ 得到答案。

时间复杂度 $O(m + n)$，空间复杂度 $O(n)$。其中 $m$ 和 $n$ 分别为数组 $\textit{nums1}$ 和 $\textit{nums2}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        stk = []
        d = {}
        for x in nums2[::-1]:
            while stk and stk[-1] < x:
                stk.pop()
            if stk:
                d[x] = stk[-1]
            stk.append(x)
        return [d.get(x, -1) for x in nums1]
```

#### Java

```java
class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        Deque<Integer> stk = new ArrayDeque<>();
        int m = nums1.length, n = nums2.length;
        Map<Integer, Integer> d = new HashMap(n);
        for (int i = n - 1; i >= 0; --i) {
            int x = nums2[i];
            while (!stk.isEmpty() && stk.peek() < x) {
                stk.pop();
            }
            if (!stk.isEmpty()) {
                d.put(x, stk.peek());
            }
            stk.push(x);
        }
        int[] ans = new int[m];
        for (int i = 0; i < m; ++i) {
            ans[i] = d.getOrDefault(nums1[i], -1);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> stk;
        unordered_map<int, int> d;
        ranges::reverse(nums2);
        for (int x : nums2) {
            while (!stk.empty() && stk.top() < x) {
                stk.pop();
            }
            if (!stk.empty()) {
                d[x] = stk.top();
            }
            stk.push(x);
        }
        vector<int> ans;
        for (int x : nums1) {
            ans.push_back(d.contains(x) ? d[x] : -1);
        }
        return ans;
    }
};
```

#### Go

```go
func nextGreaterElement(nums1 []int, nums2 []int) (ans []int) {
	stk := []int{}
	d := map[int]int{}
	for i := len(nums2) - 1; i >= 0; i-- {
		x := nums2[i]
		for len(stk) > 0 && stk[len(stk)-1] < x {
			stk = stk[:len(stk)-1]
		}
		if len(stk) > 0 {
			d[x] = stk[len(stk)-1]
		}
		stk = append(stk, x)
	}
	for _, x := range nums1 {
		if v, ok := d[x]; ok {
			ans = append(ans, v)
		} else {
			ans = append(ans, -1)
		}
	}
	return
}
```

#### TypeScript

```ts
function nextGreaterElement(nums1: number[], nums2: number[]): number[] {
    const stk: number[] = [];
    const d: Record<number, number> = {};
    for (const x of nums2.reverse()) {
        while (stk.length && stk.at(-1)! < x) {
            stk.pop();
        }
        d[x] = stk.length ? stk.at(-1)! : -1;
        stk.push(x);
    }
    return nums1.map(x => d[x]);
}
```

#### Rust

```rust
use std::collections::HashMap;

impl Solution {
    pub fn next_greater_element(nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<i32> {
        let mut stk = Vec::new();
        let mut d = HashMap::new();
        for &x in nums2.iter().rev() {
            while let Some(&top) = stk.last() {
                if top <= x {
                    stk.pop();
                } else {
                    break;
                }
            }
            if let Some(&top) = stk.last() {
                d.insert(x, top);
            }
            stk.push(x);
        }

        nums1
            .into_iter()
            .map(|x| *d.get(&x).unwrap_or(&-1))
            .collect()
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var nextGreaterElement = function (nums1, nums2) {
    const stk = [];
    const d = {};
    for (const x of nums2.reverse()) {
        while (stk.length && stk.at(-1) < x) {
            stk.pop();
        }
        d[x] = stk.length ? stk.at(-1) : -1;
        stk.push(x);
    }
    return nums1.map(x => d[x]);
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [497. 非重叠矩形中的随机点](https://leetcode.cn/problems/random-point-in-non-overlapping-rectangles){#497}

{{< tabs "497" >}}

{{% tab "python" %}}
```python
class Solution:
    def __init__(self, rects: List[List[int]]):
        self.rects = rects
        self.s = [0] * len(rects)
        for i, (x1, y1, x2, y2) in enumerate(rects):
            self.s[i] = self.s[i - 1] + (x2 - x1 + 1) * (y2 - y1 + 1)

    def pick(self) -> List[int]:
        v = random.randint(1, self.s[-1])
        idx = bisect_left(self.s, v)
        x1, y1, x2, y2 = self.rects[idx]
        return [random.randint(x1, x2), random.randint(y1, y2)]


# Your Solution object will be instantiated and called as such:
# obj = Solution(rects)
# param_1 = obj.pick()
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[] s;
    private int[][] rects;
    private Random random = new Random();

    public Solution(int[][] rects) {
        int n = rects.length;
        s = new int[n + 1];
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + (rects[i][2] - rects[i][0] + 1) * (rects[i][3] - rects[i][1] + 1);
        }
        this.rects = rects;
    }

    public int[] pick() {
        int n = rects.length;
        int v = 1 + random.nextInt(s[n]);
        int left = 0, right = n;
        while (left < right) {
            int mid = (left + right) >> 1;
            if (s[mid] >= v) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        int[] rect = rects[left - 1];
        return new int[] {rect[0] + random.nextInt(rect[2] - rect[0] + 1),
            rect[1] + random.nextInt(rect[3] - rect[1] + 1)};
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(rects);
 * int[] param_1 = obj.pick();
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> s;
    vector<vector<int>> rects;

    Solution(vector<vector<int>>& rects) {
        int n = rects.size();
        s.resize(n + 1);
        for (int i = 0; i < n; ++i) s[i + 1] = s[i] + (rects[i][2] - rects[i][0] + 1) * (rects[i][3] - rects[i][1] + 1);
        this->rects = rects;
        srand(time(nullptr));
    }

    vector<int> pick() {
        int n = rects.size();
        int v = 1 + rand() % s[n];
        int idx = lower_bound(s.begin(), s.end(), v) - s.begin();
        auto& rect = rects[idx - 1];
        int x = rect[0] + rand() % (rect[2] - rect[0] + 1);
        int y = rect[1] + rand() % (rect[3] - rect[1] + 1);
        return {x, y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type Solution struct {
	s     []int
	rects [][]int
}

func Constructor(rects [][]int) Solution {
	n := len(rects)
	s := make([]int, n+1)
	for i, v := range rects {
		s[i+1] = s[i] + (v[2]-v[0]+1)*(v[3]-v[1]+1)
	}
	return Solution{s, rects}
}

func (this *Solution) Pick() []int {
	n := len(this.rects)
	v := 1 + rand.Intn(this.s[len(this.s)-1])
	left, right := 0, n
	for left < right {
		mid := (left + right) >> 1
		if this.s[mid] >= v {
			right = mid
		} else {
			left = mid + 1
		}
	}
	rect := this.rects[left-1]
	x, y := rect[0]+rand.Intn(rect[2]-rect[0]+1), rect[1]+rand.Intn(rect[3]-rect[1]+1)
	return []int{x, y}
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个由非重叠的轴对齐矩形的数组 <code>rects</code> ，其中 <code>rects[i] = [ai, bi, xi, yi]</code> 表示 <code>(ai, bi)</code> 是第 <code>i</code> 个矩形的左下角点，<code>(xi, yi)</code> 是第 <code>i</code> 个矩形的右上角点。设计一个算法来随机挑选一个被某一矩形覆盖的整数点。矩形周长上的点也算做是被矩形覆盖。所有满足要求的点必须等概率被返回。</p>

<p>在给定的矩形覆盖的空间内的任何整数点都有可能被返回。</p>

<p><strong>请注意&nbsp;</strong>，整数点是具有整数坐标的点。</p>

<p>实现&nbsp;<code>Solution</code>&nbsp;类:</p>

<ul>
	<li><code>Solution(int[][] rects)</code>&nbsp;用给定的矩形数组&nbsp;<code>rects</code> 初始化对象。</li>
	<li><code>int[] pick()</code>&nbsp;返回一个随机的整数点 <code>[u, v]</code> 在给定的矩形所覆盖的空间内。</li>
</ul>

<ol>
</ol>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0400-0499/0497.Random%20Point%20in%20Non-overlapping%20Rectangles/images/lc-pickrandomrec.jpg" style="height: 539px; width: 419px;" /></p>

<pre>
<strong>输入: 
</strong>["Solution", "pick", "pick", "pick", "pick", "pick"]
[[[[-2, -2, 1, 1], [2, 2, 4, 6]]], [], [], [], [], []]
<strong>输出: 
</strong>[null, [1, -2], [1, -1], [-1, -2], [-2, -2], [0, 0]]

<strong>解释：</strong>
Solution solution = new Solution([[-2, -2, 1, 1], [2, 2, 4, 6]]);
solution.pick(); // 返回 [1, -2]
solution.pick(); // 返回 [1, -1]
solution.pick(); // 返回 [-1, -2]
solution.pick(); // 返回 [-2, -2]
solution.pick(); // 返回 [0, 0]</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= rects.length &lt;= 100</code></li>
	<li><code>rects[i].length == 4</code></li>
	<li><code>-10<sup>9</sup>&nbsp;&lt;= a<sub>i</sub>&nbsp;&lt; x<sub>i</sub>&nbsp;&lt;= 10<sup>9</sup></code></li>
	<li><code>-10<sup>9</sup>&nbsp;&lt;= b<sub>i</sub>&nbsp;&lt; y<sub>i</sub>&nbsp;&lt;= 10<sup>9</sup></code></li>
	<li><code>x<sub>i</sub>&nbsp;- a<sub>i</sub>&nbsp;&lt;= 2000</code></li>
	<li><code>y<sub>i</sub>&nbsp;- b<sub>i</sub>&nbsp;&lt;= 2000</code></li>
	<li>所有的矩形不重叠。</li>
	<li><code>pick</code> 最多被调用&nbsp;<code>10<sup>4</sup></code>&nbsp;次。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前缀和 + 二分查找

将矩形面积求前缀和 $s$，然后随机获取到一个面积 $v$，利用二分查找定位到是哪个矩形，然后继续随机获取该矩形的其中一个整数点坐标即可。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def __init__(self, rects: List[List[int]]):
        self.rects = rects
        self.s = [0] * len(rects)
        for i, (x1, y1, x2, y2) in enumerate(rects):
            self.s[i] = self.s[i - 1] + (x2 - x1 + 1) * (y2 - y1 + 1)

    def pick(self) -> List[int]:
        v = random.randint(1, self.s[-1])
        idx = bisect_left(self.s, v)
        x1, y1, x2, y2 = self.rects[idx]
        return [random.randint(x1, x2), random.randint(y1, y2)]


# Your Solution object will be instantiated and called as such:
# obj = Solution(rects)
# param_1 = obj.pick()
```

#### Java

```java
class Solution {
    private int[] s;
    private int[][] rects;
    private Random random = new Random();

    public Solution(int[][] rects) {
        int n = rects.length;
        s = new int[n + 1];
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + (rects[i][2] - rects[i][0] + 1) * (rects[i][3] - rects[i][1] + 1);
        }
        this.rects = rects;
    }

    public int[] pick() {
        int n = rects.length;
        int v = 1 + random.nextInt(s[n]);
        int left = 0, right = n;
        while (left < right) {
            int mid = (left + right) >> 1;
            if (s[mid] >= v) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        int[] rect = rects[left - 1];
        return new int[] {rect[0] + random.nextInt(rect[2] - rect[0] + 1),
            rect[1] + random.nextInt(rect[3] - rect[1] + 1)};
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(rects);
 * int[] param_1 = obj.pick();
 */
```

#### C++

```cpp
class Solution {
public:
    vector<int> s;
    vector<vector<int>> rects;

    Solution(vector<vector<int>>& rects) {
        int n = rects.size();
        s.resize(n + 1);
        for (int i = 0; i < n; ++i) s[i + 1] = s[i] + (rects[i][2] - rects[i][0] + 1) * (rects[i][3] - rects[i][1] + 1);
        this->rects = rects;
        srand(time(nullptr));
    }

    vector<int> pick() {
        int n = rects.size();
        int v = 1 + rand() % s[n];
        int idx = lower_bound(s.begin(), s.end(), v) - s.begin();
        auto& rect = rects[idx - 1];
        int x = rect[0] + rand() % (rect[2] - rect[0] + 1);
        int y = rect[1] + rand() % (rect[3] - rect[1] + 1);
        return {x, y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
```

#### Go

```go
type Solution struct {
	s     []int
	rects [][]int
}

func Constructor(rects [][]int) Solution {
	n := len(rects)
	s := make([]int, n+1)
	for i, v := range rects {
		s[i+1] = s[i] + (v[2]-v[0]+1)*(v[3]-v[1]+1)
	}
	return Solution{s, rects}
}

func (this *Solution) Pick() []int {
	n := len(this.rects)
	v := 1 + rand.Intn(this.s[len(this.s)-1])
	left, right := 0, n
	for left < right {
		mid := (left + right) >> 1
		if this.s[mid] >= v {
			right = mid
		} else {
			left = mid + 1
		}
	}
	rect := this.rects[left-1]
	x, y := rect[0]+rand.Intn(rect[2]-rect[0]+1), rect[1]+rand.Intn(rect[3]-rect[1]+1)
	return []int{x, y}
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [498. 对角线遍历](https://leetcode.cn/problems/diagonal-traverse){#498}

{{< tabs "498" >}}

{{% tab "python" %}}
```python
class Solution:
    def findDiagonalOrder(self, mat: List[List[int]]) -> List[int]:
        m, n = len(mat), len(mat[0])
        ans = []
        for k in range(m + n - 1):
            t = []
            i = 0 if k < n else k - n + 1
            j = k if k < n else n - 1
            while i < m and j >= 0:
                t.append(mat[i][j])
                i += 1
                j -= 1
            if k % 2 == 0:
                t = t[::-1]
            ans.extend(t)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] findDiagonalOrder(int[][] mat) {
        int m = mat.length, n = mat[0].length;
        int[] ans = new int[m * n];
        int idx = 0;
        List<Integer> t = new ArrayList<>();
        for (int k = 0; k < m + n - 1; ++k) {
            int i = k < n ? 0 : k - n + 1;
            int j = k < n ? k : n - 1;
            while (i < m && j >= 0) {
                t.add(mat[i][j]);
                ++i;
                --j;
            }
            if (k % 2 == 0) {
                Collections.reverse(t);
            }
            for (int v : t) {
                ans[idx++] = v;
            }
            t.clear();
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
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> ans;
        vector<int> t;
        for (int k = 0; k < m + n - 1; ++k) {
            int i = (k < n) ? 0 : k - n + 1;
            int j = (k < n) ? k : n - 1;
            while (i < m && j >= 0) {
                t.push_back(mat[i][j]);
                ++i;
                --j;
            }
            if (k % 2 == 0) {
                ranges::reverse(t);
            }
            ans.insert(ans.end(), t.begin(), t.end());
            t.clear();
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findDiagonalOrder(mat [][]int) []int {
	m := len(mat)
	n := len(mat[0])
	ans := make([]int, 0, m*n)
	for k := 0; k < m+n-1; k++ {
		t := make([]int, 0)
		var i, j int
		if k < n {
			i = 0
			j = k
		} else {
			i = k - n + 1
			j = n - 1
		}
		for i < m && j >= 0 {
			t = append(t, mat[i][j])
			i++
			j--
		}
		if k%2 == 0 {
			slices.Reverse(t)
		}
		ans = append(ans, t...)
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findDiagonalOrder(mat: number[][]): number[] {
    const m = mat.length;
    const n = mat[0].length;
    const ans: number[] = [];
    for (let k = 0; k < m + n - 1; k++) {
        const t: number[] = [];
        let i = k < n ? 0 : k - n + 1;
        let j = k < n ? k : n - 1;
        while (i < m && j >= 0) {
            t.push(mat[i][j]);
            i++;
            j--;
        }
        if (k % 2 === 0) {
            t.reverse();
        }
        ans.push(...t);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn find_diagonal_order(mat: Vec<Vec<i32>>) -> Vec<i32> {
        let m = mat.len();
        let n = mat[0].len();
        let mut ans = Vec::with_capacity(m * n);
        for k in 0..(m + n - 1) {
            let mut t = Vec::new();
            let (mut i, mut j) = if k < n {
                (0, k)
            } else {
                (k - n + 1, n - 1)
            };
            while i < m && j < n {
                t.push(mat[i][j]);
                i += 1;
                if j == 0 { break; }
                j -= 1;
            }
            if k % 2 == 0 {
                t.reverse();
            }
            ans.extend(t);
        }
        ans
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int[] FindDiagonalOrder(int[][] mat) {
        int m = mat.Length;
        int n = mat[0].Length;
        List<int> ans = new List<int>();
        for (int k = 0; k < m + n - 1; k++) {
            List<int> t = new List<int>();
            int i = k < n ? 0 : k - n + 1;
            int j = k < n ? k : n - 1;
            while (i < m && j >= 0) {
                t.Add(mat[i][j]);
                i++;
                j--;
            }
            if (k % 2 == 0) {
                t.Reverse();
            }
            ans.AddRange(t);
        }
        return ans.ToArray();
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个大小为 <code>m x n</code> 的矩阵 <code>mat</code> ，请以对角线遍历的顺序，用一个数组返回这个矩阵中的所有元素。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0400-0499/0498.Diagonal%20Traverse/images/diag1-grid.jpg" style="width: 334px; height: 334px;" />
<pre>
<strong>输入：</strong>mat = [[1,2,3],[4,5,6],[7,8,9]]
<strong>输出：</strong>[1,2,4,7,5,3,6,8,9]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>mat = [[1,2],[3,4]]
<strong>输出：</strong>[1,2,3,4]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == mat.length</code></li>
	<li><code>n == mat[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= m * n &lt;= 10<sup>4</sup></code></li>
	<li><code>-10<sup>5</sup> &lt;= mat[i][j] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：定点遍历

对于每一轮 $k$，我们固定从右上方开始往左下方遍历，得到 $t$。如果 $k$ 为偶数，再将 $t$ 逆序。然后将 $t$ 添加到结果数组 $\textit{ans}$ 中。

问题的关键在于确定轮数以及每一轮的起始坐标点 $(i, j)$。

时间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别为矩阵的行数和列数。忽略答案的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findDiagonalOrder(self, mat: List[List[int]]) -> List[int]:
        m, n = len(mat), len(mat[0])
        ans = []
        for k in range(m + n - 1):
            t = []
            i = 0 if k < n else k - n + 1
            j = k if k < n else n - 1
            while i < m and j >= 0:
                t.append(mat[i][j])
                i += 1
                j -= 1
            if k % 2 == 0:
                t = t[::-1]
            ans.extend(t)
        return ans
```

#### Java

```java
class Solution {
    public int[] findDiagonalOrder(int[][] mat) {
        int m = mat.length, n = mat[0].length;
        int[] ans = new int[m * n];
        int idx = 0;
        List<Integer> t = new ArrayList<>();
        for (int k = 0; k < m + n - 1; ++k) {
            int i = k < n ? 0 : k - n + 1;
            int j = k < n ? k : n - 1;
            while (i < m && j >= 0) {
                t.add(mat[i][j]);
                ++i;
                --j;
            }
            if (k % 2 == 0) {
                Collections.reverse(t);
            }
            for (int v : t) {
                ans[idx++] = v;
            }
            t.clear();
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> ans;
        vector<int> t;
        for (int k = 0; k < m + n - 1; ++k) {
            int i = (k < n) ? 0 : k - n + 1;
            int j = (k < n) ? k : n - 1;
            while (i < m && j >= 0) {
                t.push_back(mat[i][j]);
                ++i;
                --j;
            }
            if (k % 2 == 0) {
                ranges::reverse(t);
            }
            ans.insert(ans.end(), t.begin(), t.end());
            t.clear();
        }
        return ans;
    }
};
```

#### Go

```go
func findDiagonalOrder(mat [][]int) []int {
	m := len(mat)
	n := len(mat[0])
	ans := make([]int, 0, m*n)
	for k := 0; k < m+n-1; k++ {
		t := make([]int, 0)
		var i, j int
		if k < n {
			i = 0
			j = k
		} else {
			i = k - n + 1
			j = n - 1
		}
		for i < m && j >= 0 {
			t = append(t, mat[i][j])
			i++
			j--
		}
		if k%2 == 0 {
			slices.Reverse(t)
		}
		ans = append(ans, t...)
	}
	return ans
}
```

#### TypeScript

```ts
function findDiagonalOrder(mat: number[][]): number[] {
    const m = mat.length;
    const n = mat[0].length;
    const ans: number[] = [];
    for (let k = 0; k < m + n - 1; k++) {
        const t: number[] = [];
        let i = k < n ? 0 : k - n + 1;
        let j = k < n ? k : n - 1;
        while (i < m && j >= 0) {
            t.push(mat[i][j]);
            i++;
            j--;
        }
        if (k % 2 === 0) {
            t.reverse();
        }
        ans.push(...t);
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn find_diagonal_order(mat: Vec<Vec<i32>>) -> Vec<i32> {
        let m = mat.len();
        let n = mat[0].len();
        let mut ans = Vec::with_capacity(m * n);
        for k in 0..(m + n - 1) {
            let mut t = Vec::new();
            let (mut i, mut j) = if k < n {
                (0, k)
            } else {
                (k - n + 1, n - 1)
            };
            while i < m && j < n {
                t.push(mat[i][j]);
                i += 1;
                if j == 0 { break; }
                j -= 1;
            }
            if k % 2 == 0 {
                t.reverse();
            }
            ans.extend(t);
        }
        ans
    }
}
```

#### C#

```cs
public class Solution {
    public int[] FindDiagonalOrder(int[][] mat) {
        int m = mat.Length;
        int n = mat[0].Length;
        List<int> ans = new List<int>();
        for (int k = 0; k < m + n - 1; k++) {
            List<int> t = new List<int>();
            int i = k < n ? 0 : k - n + 1;
            int j = k < n ? k : n - 1;
            while (i < m && j >= 0) {
                t.Add(mat[i][j]);
                i++;
                j--;
            }
            if (k % 2 == 0) {
                t.Reverse();
            }
            ans.AddRange(t);
        }
        return ans.ToArray();
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [499. 迷宫 III 🔒](https://leetcode.cn/problems/the-maze-iii){#499}

{{< tabs "499" >}}

{{% tab "python" %}}
```python
class Solution:
    def findShortestWay(
        self, maze: List[List[int]], ball: List[int], hole: List[int]
    ) -> str:
        m, n = len(maze), len(maze[0])
        r, c = ball
        rh, ch = hole
        q = deque([(r, c)])
        dist = [[inf] * n for _ in range(m)]
        dist[r][c] = 0
        path = [[None] * n for _ in range(m)]
        path[r][c] = ''
        while q:
            i, j = q.popleft()
            for a, b, d in [(-1, 0, 'u'), (1, 0, 'd'), (0, -1, 'l'), (0, 1, 'r')]:
                x, y, step = i, j, dist[i][j]
                while (
                    0 <= x + a < m
                    and 0 <= y + b < n
                    and maze[x + a][y + b] == 0
                    and (x != rh or y != ch)
                ):
                    x, y = x + a, y + b
                    step += 1
                if dist[x][y] > step or (
                    dist[x][y] == step and path[i][j] + d < path[x][y]
                ):
                    dist[x][y] = step
                    path[x][y] = path[i][j] + d
                    if x != rh or y != ch:
                        q.append((x, y))
        return path[rh][ch] or 'impossible'
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String findShortestWay(int[][] maze, int[] ball, int[] hole) {
        int m = maze.length;
        int n = maze[0].length;
        int r = ball[0], c = ball[1];
        int rh = hole[0], ch = hole[1];
        Deque<int[]> q = new LinkedList<>();
        q.offer(new int[] {r, c});
        int[][] dist = new int[m][n];
        for (int i = 0; i < m; ++i) {
            Arrays.fill(dist[i], Integer.MAX_VALUE);
        }
        dist[r][c] = 0;
        String[][] path = new String[m][n];
        path[r][c] = "";
        int[][] dirs = {{-1, 0, 'u'}, {1, 0, 'd'}, {0, -1, 'l'}, {0, 1, 'r'}};
        while (!q.isEmpty()) {
            int[] p = q.poll();
            int i = p[0], j = p[1];
            for (int[] dir : dirs) {
                int a = dir[0], b = dir[1];
                String d = String.valueOf((char) (dir[2]));
                int x = i, y = j;
                int step = dist[i][j];
                while (x + a >= 0 && x + a < m && y + b >= 0 && y + b < n && maze[x + a][y + b] == 0
                    && (x != rh || y != ch)) {
                    x += a;
                    y += b;
                    ++step;
                }
                if (dist[x][y] > step
                    || (dist[x][y] == step && (path[i][j] + d).compareTo(path[x][y]) < 0)) {
                    dist[x][y] = step;
                    path[x][y] = path[i][j] + d;
                    if (x != rh || y != ch) {
                        q.offer(new int[] {x, y});
                    }
                }
            }
        }
        return path[rh][ch] == null ? "impossible" : path[rh][ch];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        int m = maze.size();
        int n = maze[0].size();
        int r = ball[0], c = ball[1];
        int rh = hole[0], ch = hole[1];
        queue<pair<int, int>> q;
        q.push({r, c});
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[r][c] = 0;
        vector<vector<string>> path(m, vector<string>(n, ""));
        vector<vector<int>> dirs = {{-1, 0, 'u'}, {1, 0, 'd'}, {0, -1, 'l'}, {0, 1, 'r'}};
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            int i = p.first, j = p.second;
            for (auto& dir : dirs) {
                int a = dir[0], b = dir[1];
                char d = (char) dir[2];
                int x = i, y = j;
                int step = dist[i][j];
                while (x + a >= 0 && x + a < m && y + b >= 0 && y + b < n && maze[x + a][y + b] == 0 && (x != rh || y != ch)) {
                    x += a;
                    y += b;
                    ++step;
                }
                if (dist[x][y] > step || (dist[x][y] == step && (path[i][j] + d < path[x][y]))) {
                    dist[x][y] = step;
                    path[x][y] = path[i][j] + d;
                    if (x != rh || y != ch) q.push({x, y});
                }
            }
        }
        return path[rh][ch] == "" ? "impossible" : path[rh][ch];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
import "math"

func findShortestWay(maze [][]int, ball []int, hole []int) string {
	m, n := len(maze), len(maze[0])
	r, c := ball[0], ball[1]
	rh, ch := hole[0], hole[1]
	q := [][]int{[]int{r, c}}
	dist := make([][]int, m)
	path := make([][]string, m)
	for i := range dist {
		dist[i] = make([]int, n)
		path[i] = make([]string, n)
		for j := range dist[i] {
			dist[i][j] = math.MaxInt32
			path[i][j] = ""
		}
	}
	dist[r][c] = 0
	dirs := map[string][]int{"u": {-1, 0}, "d": {1, 0}, "l": {0, -1}, "r": {0, 1}}
	for len(q) > 0 {
		p := q[0]
		q = q[1:]
		i, j := p[0], p[1]
		for d, dir := range dirs {
			a, b := dir[0], dir[1]
			x, y := i, j
			step := dist[i][j]
			for x+a >= 0 && x+a < m && y+b >= 0 && y+b < n && maze[x+a][y+b] == 0 && (x != rh || y != ch) {
				x += a
				y += b
				step++
			}
			if dist[x][y] > step || (dist[x][y] == step && (path[i][j]+d) < path[x][y]) {
				dist[x][y] = step
				path[x][y] = path[i][j] + d
				if x != rh || y != ch {
					q = append(q, []int{x, y})
				}
			}
		}
	}
	if path[rh][ch] == "" {
		return "impossible"
	}
	return path[rh][ch]
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>由空地和墙组成的迷宫中有一个<strong>球</strong>。球可以向<strong>上（u）下（d）左（l）右（r）</strong>四个方向滚动，但在遇到墙壁前不会停止滚动。当球停下时，可以选择下一个方向（必须与上一个选择的方向不同）。迷宫中还有一个<strong>洞</strong>，当球运动经过洞时，就会掉进洞里。</p>

<p>给定球的<strong>起始位置，目的地</strong>和<strong>迷宫</strong>，找出让球以最短距离掉进洞里的路径。&nbsp;距离的定义是球从起始位置（不包括）到目的地（包括）经过的<strong>空地</strong>个数。通过'u', 'd', 'l' 和&nbsp;'r'输出球的移动<strong>方向</strong>。&nbsp;由于可能有多条最短路径，&nbsp;请输出<strong>字典序最小</strong>的路径<strong>。</strong>如果球无法进入洞，输出"impossible"。</p>

<p>迷宫由一个0和1的二维数组表示。 1表示墙壁，0表示空地。你可以假定迷宫的边缘都是墙壁。起始位置和目的地的坐标通过行号和列号给出。</p>

<p>&nbsp;</p>

<p><strong>示例1:</strong></p>

<pre>
<strong>输入 1:</strong> 迷宫由以下二维数组表示

0 0 0 0 0
1 1 0 0 1
0 0 0 0 0
0 1 0 0 1
0 1 0 0 0

<strong>输入 2:</strong> 球的初始位置 (rowBall, colBall) = (4, 3)
<strong>输入 3:</strong> 洞的位置 (rowHole, colHole) = (0, 1)

<strong>输出:</strong> "lul"

<strong>解析:</strong> 有两条让球进洞的最短路径。
第一条路径是 左 -&gt; 上 -&gt; 左, 记为 "lul".
第二条路径是 上 -&gt; 左, 记为 'ul'.
两条路径都具有最短距离6, 但'l' &lt; 'u'，故第一条路径字典序更小。因此输出"lul"。
<img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0400-0499/0499.The%20Maze%20III/images/maze_2_example_1.png" style="width: 100%;" />
</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre>
<strong>输入 1:</strong> 迷宫由以下二维数组表示

0 0 0 0 0
1 1 0 0 1
0 0 0 0 0
0 1 0 0 1
0 1 0 0 0

<strong>输入 2:</strong> 球的初始位置 (rowBall, colBall) = (4, 3)
<strong>输入 3:</strong> 洞的位置 (rowHole, colHole) = (3, 0)

<strong>输出:</strong> "impossible"

<strong>示例:</strong> 球无法到达洞。
<img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0400-0499/0499.The%20Maze%20III/images/maze_2_example_2.png" style="width: 100%;" />
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>maze = [[0,0,0,0,0,0,0],[0,0,1,0,0,1,0],[0,0,0,0,1,0,0],[0,0,0,0,0,0,1]], ball = [0,4], hole = [3,5]
<b>输出：</b>"dldr"
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == maze.length</code></li>
	<li><code>n == maze[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 100</code></li>
	<li><code>maze[i][j]</code> is <code>0</code> or <code>1</code>.</li>
	<li><code>ball.length == 2</code></li>
	<li><code>hole.length == 2</code></li>
	<li><code>0 &lt;= ball<sub>row</sub>, hole<sub>row</sub> &lt;= m</code></li>
	<li><code>0 &lt;= ball<sub>col</sub>, hole<sub>col</sub> &lt;= n</code></li>
	<li>球和洞都存在于一个空地中，它们最初不会处于同一位置。</li>
	<li>迷宫中至少有 <code>2</code> 个空地。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：BFS

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findShortestWay(
        self, maze: List[List[int]], ball: List[int], hole: List[int]
    ) -> str:
        m, n = len(maze), len(maze[0])
        r, c = ball
        rh, ch = hole
        q = deque([(r, c)])
        dist = [[inf] * n for _ in range(m)]
        dist[r][c] = 0
        path = [[None] * n for _ in range(m)]
        path[r][c] = ''
        while q:
            i, j = q.popleft()
            for a, b, d in [(-1, 0, 'u'), (1, 0, 'd'), (0, -1, 'l'), (0, 1, 'r')]:
                x, y, step = i, j, dist[i][j]
                while (
                    0 <= x + a < m
                    and 0 <= y + b < n
                    and maze[x + a][y + b] == 0
                    and (x != rh or y != ch)
                ):
                    x, y = x + a, y + b
                    step += 1
                if dist[x][y] > step or (
                    dist[x][y] == step and path[i][j] + d < path[x][y]
                ):
                    dist[x][y] = step
                    path[x][y] = path[i][j] + d
                    if x != rh or y != ch:
                        q.append((x, y))
        return path[rh][ch] or 'impossible'
```

#### Java

```java
class Solution {
    public String findShortestWay(int[][] maze, int[] ball, int[] hole) {
        int m = maze.length;
        int n = maze[0].length;
        int r = ball[0], c = ball[1];
        int rh = hole[0], ch = hole[1];
        Deque<int[]> q = new LinkedList<>();
        q.offer(new int[] {r, c});
        int[][] dist = new int[m][n];
        for (int i = 0; i < m; ++i) {
            Arrays.fill(dist[i], Integer.MAX_VALUE);
        }
        dist[r][c] = 0;
        String[][] path = new String[m][n];
        path[r][c] = "";
        int[][] dirs = {{-1, 0, 'u'}, {1, 0, 'd'}, {0, -1, 'l'}, {0, 1, 'r'}};
        while (!q.isEmpty()) {
            int[] p = q.poll();
            int i = p[0], j = p[1];
            for (int[] dir : dirs) {
                int a = dir[0], b = dir[1];
                String d = String.valueOf((char) (dir[2]));
                int x = i, y = j;
                int step = dist[i][j];
                while (x + a >= 0 && x + a < m && y + b >= 0 && y + b < n && maze[x + a][y + b] == 0
                    && (x != rh || y != ch)) {
                    x += a;
                    y += b;
                    ++step;
                }
                if (dist[x][y] > step
                    || (dist[x][y] == step && (path[i][j] + d).compareTo(path[x][y]) < 0)) {
                    dist[x][y] = step;
                    path[x][y] = path[i][j] + d;
                    if (x != rh || y != ch) {
                        q.offer(new int[] {x, y});
                    }
                }
            }
        }
        return path[rh][ch] == null ? "impossible" : path[rh][ch];
    }
}
```

#### C++

```cpp
class Solution {
public:
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        int m = maze.size();
        int n = maze[0].size();
        int r = ball[0], c = ball[1];
        int rh = hole[0], ch = hole[1];
        queue<pair<int, int>> q;
        q.push({r, c});
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[r][c] = 0;
        vector<vector<string>> path(m, vector<string>(n, ""));
        vector<vector<int>> dirs = {{-1, 0, 'u'}, {1, 0, 'd'}, {0, -1, 'l'}, {0, 1, 'r'}};
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            int i = p.first, j = p.second;
            for (auto& dir : dirs) {
                int a = dir[0], b = dir[1];
                char d = (char) dir[2];
                int x = i, y = j;
                int step = dist[i][j];
                while (x + a >= 0 && x + a < m && y + b >= 0 && y + b < n && maze[x + a][y + b] == 0 && (x != rh || y != ch)) {
                    x += a;
                    y += b;
                    ++step;
                }
                if (dist[x][y] > step || (dist[x][y] == step && (path[i][j] + d < path[x][y]))) {
                    dist[x][y] = step;
                    path[x][y] = path[i][j] + d;
                    if (x != rh || y != ch) q.push({x, y});
                }
            }
        }
        return path[rh][ch] == "" ? "impossible" : path[rh][ch];
    }
};
```

#### Go

```go
import "math"

func findShortestWay(maze [][]int, ball []int, hole []int) string {
	m, n := len(maze), len(maze[0])
	r, c := ball[0], ball[1]
	rh, ch := hole[0], hole[1]
	q := [][]int{[]int{r, c}}
	dist := make([][]int, m)
	path := make([][]string, m)
	for i := range dist {
		dist[i] = make([]int, n)
		path[i] = make([]string, n)
		for j := range dist[i] {
			dist[i][j] = math.MaxInt32
			path[i][j] = ""
		}
	}
	dist[r][c] = 0
	dirs := map[string][]int{"u": {-1, 0}, "d": {1, 0}, "l": {0, -1}, "r": {0, 1}}
	for len(q) > 0 {
		p := q[0]
		q = q[1:]
		i, j := p[0], p[1]
		for d, dir := range dirs {
			a, b := dir[0], dir[1]
			x, y := i, j
			step := dist[i][j]
			for x+a >= 0 && x+a < m && y+b >= 0 && y+b < n && maze[x+a][y+b] == 0 && (x != rh || y != ch) {
				x += a
				y += b
				step++
			}
			if dist[x][y] > step || (dist[x][y] == step && (path[i][j]+d) < path[x][y]) {
				dist[x][y] = step
				path[x][y] = path[i][j] + d
				if x != rh || y != ch {
					q = append(q, []int{x, y})
				}
			}
		}
	}
	if path[rh][ch] == "" {
		return "impossible"
	}
	return path[rh][ch]
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
