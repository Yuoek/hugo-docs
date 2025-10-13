---
title: "1020_飞地的数量"
date: 2025-10-08T18:36:50+08:00
weight: 3
tags: [二分查找, 二叉树, 动态规划, 博弈, 双指针, 哈希表, 字典树, 字符串, 字符串匹配, 并查集, 广度优先搜索, 排序, 数学, 数组, 栈, 树, 深度优先搜索, 矩阵, 脑筋急转弯, 贪心]
---

{{< markmap >}}
### [1020_飞地的数量](#1020)
#### [深度优先搜索](#1020)
#### [广度优先搜索](#1020)
#### [并查集](#1020)
#### [数组](#1020)
#### [矩阵](#1020)
### [1021_删除最外层的括号](#1021)
#### [栈](#1021)
#### [字符串](#1021)
### [1022_从根到叶的二进制数之和](#1022)
#### [树](#1022)
#### [深度优先搜索](#1022)
#### [二叉树](#1022)
### [1023_驼峰式匹配](#1023)
#### [字典树](#1023)
#### [数组](#1023)
#### [双指针](#1023)
#### [字符串](#1023)
#### [字符串匹配](#1023)
### [1024_视频拼接](#1024)
#### [贪心](#1024)
#### [数组](#1024)
#### [动态规划](#1024)
### [1025_除数博弈](#1025)
#### [脑筋急转弯](#1025)
#### [数学](#1025)
#### [动态规划](#1025)
#### [博弈](#1025)
### [1026_节点与其祖先之间的最大差值](#1026)
#### [树](#1026)
#### [深度优先搜索](#1026)
#### [二叉树](#1026)
### [1027_最长等差数列](#1027)
#### [数组](#1027)
#### [哈希表](#1027)
#### [二分查找](#1027)
#### [动态规划](#1027)
### [1028_从先序遍历还原二叉树](#1028)
#### [树](#1028)
#### [深度优先搜索](#1028)
#### [字符串](#1028)
#### [二叉树](#1028)
### [1029_两地调度](#1029)
#### [贪心](#1029)
#### [数组](#1029)
#### [排序](#1029)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1020_飞地的数量
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 并查集
___
#### 数组
___
#### 矩阵
---
### 1021_删除最外层的括号
___
#### 栈
___
#### 字符串
---
### 1022_从根到叶的二进制数之和
___
#### 树
___
#### 深度优先搜索
___
#### 二叉树
---
### 1023_驼峰式匹配
___
#### 字典树
___
#### 数组
___
#### 双指针
___
#### 字符串
___
#### 字符串匹配
---
### 1024_视频拼接
___
#### 贪心
___
#### 数组
___
#### 动态规划
---
### 1025_除数博弈
___
#### 脑筋急转弯
___
#### 数学
___
#### 动态规划
___
#### 博弈
---
### 1026_节点与其祖先之间的最大差值
___
#### 树
___
#### 深度优先搜索
___
#### 二叉树
---
### 1027_最长等差数列
___
#### 数组
___
#### 哈希表
___
#### 二分查找
___
#### 动态规划
---
### 1028_从先序遍历还原二叉树
___
#### 树
___
#### 深度优先搜索
___
#### 字符串
___
#### 二叉树
---
### 1029_两地调度
___
#### 贪心
___
#### 数组
___
#### 排序
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 二叉树 | 动态规划 |
| 博弈 | 双指针 | 哈希表 |
| 字典树 | 字符串 | 字符串匹配 |
| 并查集 | 广度优先搜索 | 排序 |
| 数学 | 数组 | 栈 |
| 树 | 深度优先搜索 | 矩阵 |
| 脑筋急转弯 | 贪心 |  |

# [1020. 飞地的数量](https://leetcode.cn/problems/number-of-enclaves){#1020}

{{< tabs "1020" >}}

{{% tab "python" %}}
```python
class Solution:
    def numEnclaves(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        q = deque()
        for j in range(n):
            for i in (0, m - 1):
                if grid[i][j]:
                    q.append((i, j))
                    grid[i][j] = 0
        for i in range(m):
            for j in (0, n - 1):
                if grid[i][j]:
                    q.append((i, j))
                    grid[i][j] = 0
        dirs = (-1, 0, 1, 0, -1)
        while q:
            i, j = q.popleft()
            for a, b in pairwise(dirs):
                x, y = i + a, j + b
                if 0 <= x < m and 0 <= y < n and grid[x][y]:
                    q.append((x, y))
                    grid[x][y] = 0
        return sum(sum(row) for row in grid)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numEnclaves(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        Deque<int[]> q = new ArrayDeque<>();
        for (int j = 0; j < n; ++j) {
            for (int i : List.of(0, m - 1)) {
                if (grid[i][j] == 1) {
                    q.offer(new int[] {i, j});
                    grid[i][j] = 0;
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j : List.of(0, n - 1)) {
                if (grid[i][j] == 1) {
                    q.offer(new int[] {i, j});
                    grid[i][j] = 0;
                }
            }
        }
        final int[] dirs = {-1, 0, 1, 0, -1};
        while (!q.isEmpty()) {
            int[] p = q.poll();
            int i = p[0], j = p[1];
            for (int k = 0; k < 4; ++k) {
                int x = i + dirs[k], y = j + dirs[k + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) {
                    q.offer(new int[] {x, y});
                    grid[x][y] = 0;
                }
            }
        }
        int ans = 0;
        for (var row : grid) {
            for (int x : row) {
                ans += x;
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
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int dirs[5] = {-1, 0, 1, 0, -1};
        queue<pair<int, int>> q;
        for (int j = 0; j < n; ++j) {
            for (int i : {0, m - 1}) {
                if (grid[i][j] == 1) {
                    q.emplace(i, j);
                    grid[i][j] = 0;
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j : {0, n - 1}) {
                if (grid[i][j] == 1) {
                    q.emplace(i, j);
                    grid[i][j] = 0;
                }
            }
        }
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            for (int k = 0; k < 4; ++k) {
                int x = i + dirs[k], y = j + dirs[k + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) {
                    q.emplace(x, y);
                    grid[x][y] = 0;
                }
            }
        }
        int ans = 0;
        for (const auto& row : grid) {
            ans += accumulate(row.begin(), row.end(), 0);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numEnclaves(grid [][]int) (ans int) {
	m, n := len(grid), len(grid[0])
	dirs := [5]int{-1, 0, 1, 0, -1}
	q := [][2]int{}
	for j := 0; j < n; j++ {
		for _, i := range []int{0, m - 1} {
			if grid[i][j] == 1 {
				q = append(q, [2]int{i, j})
				grid[i][j] = 0
			}
		}
	}
	for i := 0; i < m; i++ {
		for _, j := range []int{0, n - 1} {
			if grid[i][j] == 1 {
				q = append(q, [2]int{i, j})
				grid[i][j] = 0
			}
		}
	}
	for len(q) > 0 {
		i, j := q[0][0], q[0][1]
		q = q[1:]
		for k := 0; k < 4; k++ {
			x, y := i+dirs[k], j+dirs[k+1]
			if x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1 {
				q = append(q, [2]int{x, y})
				grid[x][y] = 0
			}
		}
	}
	for _, row := range grid {
		for _, x := range row {
			ans += x
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numEnclaves(grid: number[][]): number {
    const [m, n] = [grid.length, grid[0].length];
    const dirs = [-1, 0, 1, 0, -1];
    const q: number[][] = [];
    for (let j = 0; j < n; ++j) {
        for (let i of [0, m - 1]) {
            if (grid[i][j] === 1) {
                q.push([i, j]);
                grid[i][j] = 0;
            }
        }
    }
    for (let i = 0; i < m; ++i) {
        for (let j of [0, n - 1]) {
            if (grid[i][j] === 1) {
                q.push([i, j]);
                grid[i][j] = 0;
            }
        }
    }
    while (q.length) {
        const [i, j] = q.pop()!;
        for (let k = 0; k < 4; ++k) {
            const x = i + dirs[k];
            const y = j + dirs[k + 1];
            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] === 1) {
                q.push([x, y]);
                grid[x][y] = 0;
            }
        }
    }
    return grid.flat().reduce((acc, cur) => acc + cur, 0);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn num_enclaves(mut grid: Vec<Vec<i32>>) -> i32 {
        let m = grid.len();
        let n = grid[0].len();
        let dirs = [-1, 0, 1, 0, -1];

        fn dfs(grid: &mut Vec<Vec<i32>>, i: usize, j: usize, dirs: &[i32; 5]) {
            grid[i][j] = 0;
            for k in 0..4 {
                let (x, y) = (i as i32 + dirs[k], j as i32 + dirs[k + 1]);
                if let Some(row) = grid.get_mut(x as usize) {
                    if let Some(&mut 1) = row.get_mut(y as usize) {
                        dfs(grid, x as usize, y as usize, dirs);
                    }
                }
            }
        }

        for j in 0..n {
            if grid[0][j] == 1 {
                dfs(&mut grid, 0, j, &dirs);
            }
            if grid[m - 1][j] == 1 {
                dfs(&mut grid, m - 1, j, &dirs);
            }
        }

        for i in 0..m {
            if grid[i][0] == 1 {
                dfs(&mut grid, i, 0, &dirs);
            }
            if grid[i][n - 1] == 1 {
                dfs(&mut grid, i, n - 1, &dirs);
            }
        }

        grid.into_iter().flatten().filter(|&x| x == 1).count() as i32
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个大小为 <code>m x n</code> 的二进制矩阵 <code>grid</code> ，其中 <code>0</code> 表示一个海洋单元格、<code>1</code> 表示一个陆地单元格。</p>

<p>一次 <strong>移动</strong> 是指从一个陆地单元格走到另一个相邻（<strong>上、下、左、右</strong>）的陆地单元格或跨过 <code>grid</code> 的边界。</p>

<p>返回网格中<strong> 无法 </strong>在任意次数的移动中离开网格边界的陆地单元格的数量。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1000-1099/1020.Number%20of%20Enclaves/images/enclaves1.jpg" style="height: 200px; width: 200px;" />
<pre>
<strong>输入：</strong>grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
<strong>输出：</strong>3
<strong>解释：</strong>有三个 1 被 0 包围。一个 1 没有被包围，因为它在边界上。
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1000-1099/1020.Number%20of%20Enclaves/images/enclaves2.jpg" style="height: 200px; width: 200px;" />
<pre>
<strong>输入：</strong>grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
<strong>输出：</strong>0
<strong>解释：</strong>所有 1 都在边界上或可以到达边界。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 500</code></li>
	<li><code>grid[i][j]</code> 的值为 <code>0</code> 或 <code>1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS

我们可以从边界上的陆地开始进行深度优先搜索，将所有与边界相连的陆地都标记为 $0$。最后，统计剩余的 $1$ 的个数，即为答案。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别为矩阵的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numEnclaves(self, grid: List[List[int]]) -> int:
        def dfs(i: int, j: int):
            grid[i][j] = 0
            for a, b in pairwise(dirs):
                x, y = i + a, j + b
                if 0 <= x < m and 0 <= y < n and grid[x][y]:
                    dfs(x, y)

        m, n = len(grid), len(grid[0])
        dirs = (-1, 0, 1, 0, -1)
        for j in range(n):
            for i in (0, m - 1):
                if grid[i][j]:
                    dfs(i, j)
        for i in range(m):
            for j in (0, n - 1):
                if grid[i][j]:
                    dfs(i, j)
        return sum(sum(row) for row in grid)
```

#### Java

```java
class Solution {
    private int[][] grid;

    public int numEnclaves(int[][] grid) {
        this.grid = grid;
        int m = grid.length, n = grid[0].length;
        for (int j = 0; j < n; j++) {
            for (int i : List.of(0, m - 1)) {
                if (grid[i][j] == 1) {
                    dfs(i, j);
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j : List.of(0, n - 1)) {
                if (grid[i][j] == 1) {
                    dfs(i, j);
                }
            }
        }
        int ans = 0;
        for (var row : grid) {
            for (int x : row) {
                ans += x;
            }
        }
        return ans;
    }

    private void dfs(int i, int j) {
        grid[i][j] = 0;
        final int[] dirs = {-1, 0, 1, 0, -1};
        for (int k = 0; k < 4; k++) {
            int x = i + dirs[k], y = j + dirs[k + 1];
            if (x >= 0 && x < grid.length && y >= 0 && y < grid[0].length && grid[x][y] == 1) {
                dfs(x, y);
            }
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        const int dirs[5] = {-1, 0, 1, 0, -1};
        function<void(int, int)> dfs = [&](int i, int j) {
            grid[i][j] = 0;
            for (int k = 0; k < 4; ++k) {
                int x = i + dirs[k], y = j + dirs[k + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) {
                    dfs(x, y);
                }
            }
        };
        for (int j = 0; j < n; ++j) {
            for (int i : {0, m - 1}) {
                if (grid[i][j] == 1) {
                    dfs(i, j);
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j : {0, n - 1}) {
                if (grid[i][j] == 1) {
                    dfs(i, j);
                }
            }
        }
        int ans = 0;
        for (const auto& row : grid) {
            ans += accumulate(row.begin(), row.end(), 0);
        }
        return ans;
    }
};
```

#### Go

```go
func numEnclaves(grid [][]int) (ans int) {
	m, n := len(grid), len(grid[0])
	dirs := [5]int{-1, 0, 1, 0, -1}
	var dfs func(i, j int)
	dfs = func(i, j int) {
		grid[i][j] = 0
		for k := 0; k < 4; k++ {
			x, y := i+dirs[k], j+dirs[k+1]
			if x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1 {
				dfs(x, y)
			}
		}
	}
	for j := 0; j < n; j++ {
		for _, i := range [2]int{0, m - 1} {
			if grid[i][j] == 1 {
				dfs(i, j)
			}
		}
	}
	for i := 0; i < m; i++ {
		for _, j := range [2]int{0, n - 1} {
			if grid[i][j] == 1 {
				dfs(i, j)
			}
		}
	}
	for _, row := range grid {
		for _, x := range row {
			ans += x
		}
	}
	return
}
```

#### TypeScript

```ts
function numEnclaves(grid: number[][]): number {
    const [m, n] = [grid.length, grid[0].length];
    const dirs: number[] = [-1, 0, 1, 0, -1];
    const dfs = (i: number, j: number) => {
        grid[i][j] = 0;
        for (let k = 0; k < 4; ++k) {
            const x = i + dirs[k];
            const y = j + dirs[k + 1];
            if (x >= 0 && x < m && y >= 0 && y <= n && grid[x][y] === 1) {
                dfs(x, y);
            }
        }
    };
    for (let j = 0; j < n; ++j) {
        for (let i of [0, m - 1]) {
            if (grid[i][j] === 1) {
                dfs(i, j);
            }
        }
    }
    for (let i = 0; i < m; ++i) {
        for (let j of [0, n - 1]) {
            if (grid[i][j] === 1) {
                dfs(i, j);
            }
        }
    }
    return grid.flat().reduce((acc, cur) => acc + cur, 0);
}
```

#### Rust

```rust
impl Solution {
    pub fn num_enclaves(mut grid: Vec<Vec<i32>>) -> i32 {
        let m = grid.len();
        let n = grid[0].len();
        let dirs = [-1, 0, 1, 0, -1];

        fn dfs(grid: &mut Vec<Vec<i32>>, i: usize, j: usize, dirs: &[i32; 5]) {
            grid[i][j] = 0;
            for k in 0..4 {
                let (x, y) = (i as i32 + dirs[k], j as i32 + dirs[k + 1]);
                if let Some(row) = grid.get_mut(x as usize) {
                    if let Some(&mut 1) = row.get_mut(y as usize) {
                        dfs(grid, x as usize, y as usize, dirs);
                    }
                }
            }
        }

        for j in 0..n {
            if grid[0][j] == 1 {
                dfs(&mut grid, 0, j, &dirs);
            }
            if grid[m - 1][j] == 1 {
                dfs(&mut grid, m - 1, j, &dirs);
            }
        }

        for i in 0..m {
            if grid[i][0] == 1 {
                dfs(&mut grid, i, 0, &dirs);
            }
            if grid[i][n - 1] == 1 {
                dfs(&mut grid, i, n - 1, &dirs);
            }
        }

        grid.into_iter().flatten().filter(|&x| x == 1).count() as i32
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：BFS

我们也可以使用广度优先搜索的方法，将边界上的陆地入队，然后进行广度优先搜索，将所有与边界相连的陆地都标记为 $0$。最后，统计剩余的 $1$ 的个数，即为答案。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别为矩阵的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numEnclaves(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        q = deque()
        for j in range(n):
            for i in (0, m - 1):
                if grid[i][j]:
                    q.append((i, j))
                    grid[i][j] = 0
        for i in range(m):
            for j in (0, n - 1):
                if grid[i][j]:
                    q.append((i, j))
                    grid[i][j] = 0
        dirs = (-1, 0, 1, 0, -1)
        while q:
            i, j = q.popleft()
            for a, b in pairwise(dirs):
                x, y = i + a, j + b
                if 0 <= x < m and 0 <= y < n and grid[x][y]:
                    q.append((x, y))
                    grid[x][y] = 0
        return sum(sum(row) for row in grid)
```

#### Java

```java
class Solution {
    public int numEnclaves(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        Deque<int[]> q = new ArrayDeque<>();
        for (int j = 0; j < n; ++j) {
            for (int i : List.of(0, m - 1)) {
                if (grid[i][j] == 1) {
                    q.offer(new int[] {i, j});
                    grid[i][j] = 0;
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j : List.of(0, n - 1)) {
                if (grid[i][j] == 1) {
                    q.offer(new int[] {i, j});
                    grid[i][j] = 0;
                }
            }
        }
        final int[] dirs = {-1, 0, 1, 0, -1};
        while (!q.isEmpty()) {
            int[] p = q.poll();
            int i = p[0], j = p[1];
            for (int k = 0; k < 4; ++k) {
                int x = i + dirs[k], y = j + dirs[k + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) {
                    q.offer(new int[] {x, y});
                    grid[x][y] = 0;
                }
            }
        }
        int ans = 0;
        for (var row : grid) {
            for (int x : row) {
                ans += x;
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
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int dirs[5] = {-1, 0, 1, 0, -1};
        queue<pair<int, int>> q;
        for (int j = 0; j < n; ++j) {
            for (int i : {0, m - 1}) {
                if (grid[i][j] == 1) {
                    q.emplace(i, j);
                    grid[i][j] = 0;
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j : {0, n - 1}) {
                if (grid[i][j] == 1) {
                    q.emplace(i, j);
                    grid[i][j] = 0;
                }
            }
        }
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            for (int k = 0; k < 4; ++k) {
                int x = i + dirs[k], y = j + dirs[k + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) {
                    q.emplace(x, y);
                    grid[x][y] = 0;
                }
            }
        }
        int ans = 0;
        for (const auto& row : grid) {
            ans += accumulate(row.begin(), row.end(), 0);
        }
        return ans;
    }
};
```

#### Go

```go
func numEnclaves(grid [][]int) (ans int) {
	m, n := len(grid), len(grid[0])
	dirs := [5]int{-1, 0, 1, 0, -1}
	q := [][2]int{}
	for j := 0; j < n; j++ {
		for _, i := range []int{0, m - 1} {
			if grid[i][j] == 1 {
				q = append(q, [2]int{i, j})
				grid[i][j] = 0
			}
		}
	}
	for i := 0; i < m; i++ {
		for _, j := range []int{0, n - 1} {
			if grid[i][j] == 1 {
				q = append(q, [2]int{i, j})
				grid[i][j] = 0
			}
		}
	}
	for len(q) > 0 {
		i, j := q[0][0], q[0][1]
		q = q[1:]
		for k := 0; k < 4; k++ {
			x, y := i+dirs[k], j+dirs[k+1]
			if x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1 {
				q = append(q, [2]int{x, y})
				grid[x][y] = 0
			}
		}
	}
	for _, row := range grid {
		for _, x := range row {
			ans += x
		}
	}
	return
}
```

#### TypeScript

```ts
function numEnclaves(grid: number[][]): number {
    const [m, n] = [grid.length, grid[0].length];
    const dirs = [-1, 0, 1, 0, -1];
    const q: number[][] = [];
    for (let j = 0; j < n; ++j) {
        for (let i of [0, m - 1]) {
            if (grid[i][j] === 1) {
                q.push([i, j]);
                grid[i][j] = 0;
            }
        }
    }
    for (let i = 0; i < m; ++i) {
        for (let j of [0, n - 1]) {
            if (grid[i][j] === 1) {
                q.push([i, j]);
                grid[i][j] = 0;
            }
        }
    }
    while (q.length) {
        const [i, j] = q.pop()!;
        for (let k = 0; k < 4; ++k) {
            const x = i + dirs[k];
            const y = j + dirs[k + 1];
            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] === 1) {
                q.push([x, y]);
                grid[x][y] = 0;
            }
        }
    }
    return grid.flat().reduce((acc, cur) => acc + cur, 0);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1021. 删除最外层的括号](https://leetcode.cn/problems/remove-outermost-parentheses){#1021}

{{< tabs "1021" >}}

{{% tab "python" %}}
```python
class Solution:
    def removeOuterParentheses(self, s: str) -> str:
        ans = []
        cnt = 0
        for c in s:
            if c == '(':
                cnt += 1
            if cnt > 1:
                ans.append(c)
            if c == ')':
                cnt -= 1
        return ''.join(ans)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String removeOuterParentheses(String s) {
        StringBuilder ans = new StringBuilder();
        int cnt = 0;
        for (int i = 0; i < s.length(); ++i) {
            char c = s.charAt(i);
            if (c == '(') {
                ++cnt;
            }
            if (cnt > 1) {
                ans.append(c);
            }
            if (c == ')') {
                --cnt;
            }
        }
        return ans.toString();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int cnt = 0;
        for (char& c : s) {
            if (c == '(') {
                ++cnt;
            }
            if (cnt > 1) {
                ans.push_back(c);
            }
            if (c == ')') {
                --cnt;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func removeOuterParentheses(s string) string {
	ans := []rune{}
	cnt := 0
	for _, c := range s {
		if c == '(' {
			cnt++
		}
		if cnt > 1 {
			ans = append(ans, c)
		}
		if c == ')' {
			cnt--
		}
	}
	return string(ans)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function removeOuterParentheses(s: string): string {
    let res = '';
    let depth = 0;
    for (const c of s) {
        if (c === '(') {
            depth++;
        }
        if (depth !== 1) {
            res += c;
        }
        if (c === ')') {
            depth--;
        }
    }
    return res;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn remove_outer_parentheses(s: String) -> String {
        let mut res = String::new();
        let mut depth = 0;
        for c in s.chars() {
            if c == '(' {
                depth += 1;
            }
            if depth != 1 {
                res.push(c);
            }
            if c == ')' {
                depth -= 1;
            }
        }
        res
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>有效括号字符串为空 <code>""</code>、<code>"(" + A + ")"</code> 或 <code>A + B</code> ，其中 <code>A</code> 和 <code>B</code> 都是有效的括号字符串，<code>+</code> 代表字符串的连接。</p>

<ul>
	<li>例如，<code>""</code>，<code>"()"</code>，<code>"(())()"</code> 和 <code>"(()(()))"</code> 都是有效的括号字符串。</li>
</ul>

<p>如果有效字符串 <code>s</code> 非空，且不存在将其拆分为 <code>s = A + B</code> 的方法，我们称其为<strong>原语（primitive）</strong>，其中 <code>A</code> 和 <code>B</code> 都是非空有效括号字符串。</p>

<p>给出一个非空有效字符串 <code>s</code>，考虑将其进行原语化分解，使得：<code>s = P_1 + P_2 + ... + P_k</code>，其中 <code>P_i</code> 是有效括号字符串原语。</p>

<p>对 <code>s</code> 进行原语化分解，删除分解中每个原语字符串的最外层括号，返回 <code>s</code> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "(()())(())"
<strong>输出：</strong>"()()()"
<strong>解释：
</strong>输入字符串为 "(()())(())"，原语化分解得到 "(()())" + "(())"，
删除每个部分中的最外层括号后得到 "()()" + "()" = "()()()"。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "(()())(())(()(()))"
<strong>输出：</strong>"()()()()(())"
<strong>解释：</strong>
输入字符串为 "(()())(())(()(()))"，原语化分解得到 "(()())" + "(())" + "(()(()))"，
删除每个部分中的最外层括号后得到 "()()" + "()" + "()(())" = "()()()()(())"。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "()()"
<strong>输出：</strong>""
<strong>解释：</strong>
输入字符串为 "()()"，原语化分解得到 "()" + "()"，
删除每个部分中的最外层括号后得到 "" + "" = ""。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= s.length <= 10<sup>5</sup></code></li>
	<li><code>s[i]</code> 为 <code>'('</code> 或 <code>')'</code></li>
	<li><code>s</code> 是一个有效括号字符串</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数

遍历字符串，遇到左括号 `'('` 计数器加一，此时计数器不为 $1$ 时，说明当前括号不是最外层括号，将其加入结果字符串。遇到右括号 `')'` 计数器减一，此时计数器不为 $0$ 时，说明当前括号不是最外层括号，将其加入结果字符串。

时间复杂度 $O(n)$，其中 $n$ 为字符串长度。忽略答案字符串的空间开销，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def removeOuterParentheses(self, s: str) -> str:
        ans = []
        cnt = 0
        for c in s:
            if c == '(':
                cnt += 1
                if cnt > 1:
                    ans.append(c)
            else:
                cnt -= 1
                if cnt > 0:
                    ans.append(c)
        return ''.join(ans)
```

#### Java

```java
class Solution {
    public String removeOuterParentheses(String s) {
        StringBuilder ans = new StringBuilder();
        int cnt = 0;
        for (int i = 0; i < s.length(); ++i) {
            char c = s.charAt(i);
            if (c == '(') {
                if (++cnt > 1) {
                    ans.append(c);
                }
            } else {
                if (--cnt > 0) {
                    ans.append(c);
                }
            }
        }
        return ans.toString();
    }
}
```

#### C++

```cpp
class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int cnt = 0;
        for (char& c : s) {
            if (c == '(') {
                if (++cnt > 1) {
                    ans.push_back(c);
                }
            } else {
                if (--cnt) {
                    ans.push_back(c);
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func removeOuterParentheses(s string) string {
	ans := []rune{}
	cnt := 0
	for _, c := range s {
		if c == '(' {
			cnt++
			if cnt > 1 {
				ans = append(ans, c)
			}
		} else {
			cnt--
			if cnt > 0 {
				ans = append(ans, c)
			}
		}
	}
	return string(ans)
}
```

#### TypeScript

```ts
function removeOuterParentheses(s: string): string {
    let res = '';
    let depth = 0;
    for (const c of s) {
        if (c === '(') {
            depth++;
        }
        if (depth !== 1) {
            res += c;
        }
        if (c === ')') {
            depth--;
        }
    }
    return res;
}
```

#### Rust

```rust
impl Solution {
    pub fn remove_outer_parentheses(s: String) -> String {
        let mut res = String::new();
        let mut depth = 0;
        for c in s.chars() {
            if c == '(' {
                depth += 1;
            }
            if depth != 1 {
                res.push(c);
            }
            if c == ')' {
                depth -= 1;
            }
        }
        res
    }
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
    def removeOuterParentheses(self, s: str) -> str:
        ans = []
        cnt = 0
        for c in s:
            if c == '(':
                cnt += 1
            if cnt > 1:
                ans.append(c)
            if c == ')':
                cnt -= 1
        return ''.join(ans)
```

#### Java

```java
class Solution {
    public String removeOuterParentheses(String s) {
        StringBuilder ans = new StringBuilder();
        int cnt = 0;
        for (int i = 0; i < s.length(); ++i) {
            char c = s.charAt(i);
            if (c == '(') {
                ++cnt;
            }
            if (cnt > 1) {
                ans.append(c);
            }
            if (c == ')') {
                --cnt;
            }
        }
        return ans.toString();
    }
}
```

#### C++

```cpp
class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int cnt = 0;
        for (char& c : s) {
            if (c == '(') {
                ++cnt;
            }
            if (cnt > 1) {
                ans.push_back(c);
            }
            if (c == ')') {
                --cnt;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func removeOuterParentheses(s string) string {
	ans := []rune{}
	cnt := 0
	for _, c := range s {
		if c == '(' {
			cnt++
		}
		if cnt > 1 {
			ans = append(ans, c)
		}
		if c == ')' {
			cnt--
		}
	}
	return string(ans)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1022. 从根到叶的二进制数之和](https://leetcode.cn/problems/sum-of-root-to-leaf-binary-numbers){#1022}

{{< tabs "1022" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumRootToLeaf(self, root: TreeNode) -> int:
        def dfs(root, t):
            if root is None:
                return 0
            t = (t << 1) | root.val
            if root.left is None and root.right is None:
                return t
            return dfs(root.left, t) + dfs(root.right, t)

        return dfs(root, 0)
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
    public int sumRootToLeaf(TreeNode root) {
        return dfs(root, 0);
    }

    private int dfs(TreeNode root, int t) {
        if (root == null) {
            return 0;
        }
        t = (t << 1) | root.val;
        if (root.left == null && root.right == null) {
            return t;
        }
        return dfs(root.left, t) + dfs(root.right, t);
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
    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
    }

    int dfs(TreeNode* root, int t) {
        if (!root) return 0;
        t = (t << 1) | root->val;
        if (!root->left && !root->right) return t;
        return dfs(root->left, t) + dfs(root->right, t);
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
func sumRootToLeaf(root *TreeNode) int {
	var dfs func(root *TreeNode, t int) int
	dfs = func(root *TreeNode, t int) int {
		if root == nil {
			return 0
		}
		t = (t << 1) | root.Val
		if root.Left == nil && root.Right == nil {
			return t
		}
		return dfs(root.Left, t) + dfs(root.Right, t)
	}

	return dfs(root, 0)
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

function sumRootToLeaf(root: TreeNode | null): number {
    const dfs = (root: TreeNode | null, num: number) => {
        if (root == null) {
            return 0;
        }
        const { val, left, right } = root;
        num = (num << 1) | val;
        if (left == null && right == null) {
            return num;
        }
        return dfs(left, num) + dfs(right, num);
    };
    return dfs(root, 0);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
//
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::cell::RefCell;
use std::rc::Rc;
impl Solution {
    fn dfs(root: &Option<Rc<RefCell<TreeNode>>>, mut num: i32) -> i32 {
        if root.is_none() {
            return 0;
        }
        let root = root.as_ref().unwrap().borrow();
        num = (num << 1) | root.val;
        if root.left.is_none() && root.right.is_none() {
            return num;
        }
        Self::dfs(&root.left, num) + Self::dfs(&root.right, num)
    }

    pub fn sum_root_to_leaf(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        Self::dfs(&root, 0)
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给出一棵二叉树，其上每个结点的值都是&nbsp;<code>0</code>&nbsp;或&nbsp;<code>1</code>&nbsp;。每一条从根到叶的路径都代表一个从最高有效位开始的二进制数。</p>

<ul>
	<li>例如，如果路径为&nbsp;<code>0 -&gt; 1 -&gt; 1 -&gt; 0 -&gt; 1</code>，那么它表示二进制数&nbsp;<code>01101</code>，也就是&nbsp;<code>13</code>&nbsp;。</li>
</ul>

<p>对树上的每一片叶子，我们都要找出从根到该叶子的路径所表示的数字。</p>

<p>返回这些数字之和。题目数据保证答案是一个 <strong>32 位 </strong>整数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1000-1099/1022.Sum%20of%20Root%20To%20Leaf%20Binary%20Numbers/images/sum-of-root-to-leaf-binary-numbers.png" />
<pre>
<strong>输入：</strong>root = [1,0,1,0,1,0,1]
<strong>输出：</strong>22
<strong>解释：</strong>(100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>root = [0]
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中的节点数在&nbsp;<code>[1, 1000]</code>&nbsp;范围内</li>
	<li><code>Node.val</code>&nbsp;仅为 <code>0</code> 或 <code>1</code>&nbsp;</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：递归

我们设计一个递归函数 `dfs(root, t)`，它接收两个参数：当前节点 `root` 和当前节点的父节点对应的二进制数 `t`。函数的返回值是从当前节点到叶子节点的路径所表示的二进制数之和。答案即为 `dfs(root, 0)`。

递归函数的逻辑如下：

-   如果当前节点 `root` 为空，则返回 `0`，否则计算当前节点对应的二进制数 `t`，即 `t = t << 1 | root.val`。
-   如果当前节点是叶子节点，则返回 `t`，否则返回 `dfs(root.left, t)` 和 `dfs(root.right, t)` 的和。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是二叉树的节点数。对每个节点访问一次；递归栈需要 $O(n)$ 的空间。

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
    def sumRootToLeaf(self, root: TreeNode) -> int:
        def dfs(root, t):
            if root is None:
                return 0
            t = (t << 1) | root.val
            if root.left is None and root.right is None:
                return t
            return dfs(root.left, t) + dfs(root.right, t)

        return dfs(root, 0)
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
    public int sumRootToLeaf(TreeNode root) {
        return dfs(root, 0);
    }

    private int dfs(TreeNode root, int t) {
        if (root == null) {
            return 0;
        }
        t = (t << 1) | root.val;
        if (root.left == null && root.right == null) {
            return t;
        }
        return dfs(root.left, t) + dfs(root.right, t);
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
    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
    }

    int dfs(TreeNode* root, int t) {
        if (!root) return 0;
        t = (t << 1) | root->val;
        if (!root->left && !root->right) return t;
        return dfs(root->left, t) + dfs(root->right, t);
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
func sumRootToLeaf(root *TreeNode) int {
	var dfs func(root *TreeNode, t int) int
	dfs = func(root *TreeNode, t int) int {
		if root == nil {
			return 0
		}
		t = (t << 1) | root.Val
		if root.Left == nil && root.Right == nil {
			return t
		}
		return dfs(root.Left, t) + dfs(root.Right, t)
	}

	return dfs(root, 0)
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

function sumRootToLeaf(root: TreeNode | null): number {
    const dfs = (root: TreeNode | null, num: number) => {
        if (root == null) {
            return 0;
        }
        const { val, left, right } = root;
        num = (num << 1) | val;
        if (left == null && right == null) {
            return num;
        }
        return dfs(left, num) + dfs(right, num);
    };
    return dfs(root, 0);
}
```

#### Rust

```rust
// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
//
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::cell::RefCell;
use std::rc::Rc;
impl Solution {
    fn dfs(root: &Option<Rc<RefCell<TreeNode>>>, mut num: i32) -> i32 {
        if root.is_none() {
            return 0;
        }
        let root = root.as_ref().unwrap().borrow();
        num = (num << 1) | root.val;
        if root.left.is_none() && root.right.is_none() {
            return num;
        }
        Self::dfs(&root.left, num) + Self::dfs(&root.right, num)
    }

    pub fn sum_root_to_leaf(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        Self::dfs(&root, 0)
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1023. 驼峰式匹配](https://leetcode.cn/problems/camelcase-matching){#1023}

{{< tabs "1023" >}}

{{% tab "python" %}}
```python
class Solution:
    def camelMatch(self, queries: List[str], pattern: str) -> List[bool]:
        def check(s, t):
            m, n = len(s), len(t)
            i = j = 0
            while j < n:
                while i < m and s[i] != t[j] and s[i].islower():
                    i += 1
                if i == m or s[i] != t[j]:
                    return False
                i, j = i + 1, j + 1
            while i < m and s[i].islower():
                i += 1
            return i == m

        return [check(q, pattern) for q in queries]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<Boolean> camelMatch(String[] queries, String pattern) {
        List<Boolean> ans = new ArrayList<>();
        for (var q : queries) {
            ans.add(check(q, pattern));
        }
        return ans;
    }

    private boolean check(String s, String t) {
        int m = s.length(), n = t.length();
        int i = 0, j = 0;
        for (; j < n; ++i, ++j) {
            while (i < m && s.charAt(i) != t.charAt(j) && Character.isLowerCase(s.charAt(i))) {
                ++i;
            }
            if (i == m || s.charAt(i) != t.charAt(j)) {
                return false;
            }
        }
        while (i < m && Character.isLowerCase(s.charAt(i))) {
            ++i;
        }
        return i == m;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans;
        auto check = [](string& s, string& t) {
            int m = s.size(), n = t.size();
            int i = 0, j = 0;
            for (; j < n; ++i, ++j) {
                while (i < m && s[i] != t[j] && islower(s[i])) {
                    ++i;
                }
                if (i == m || s[i] != t[j]) {
                    return false;
                }
            }
            while (i < m && islower(s[i])) {
                ++i;
            }
            return i == m;
        };
        for (auto& q : queries) {
            ans.push_back(check(q, pattern));
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func camelMatch(queries []string, pattern string) (ans []bool) {
	check := func(s, t string) bool {
		m, n := len(s), len(t)
		i, j := 0, 0
		for ; j < n; i, j = i+1, j+1 {
			for i < m && s[i] != t[j] && (s[i] >= 'a' && s[i] <= 'z') {
				i++
			}
			if i == m || s[i] != t[j] {
				return false
			}
		}
		for i < m && s[i] >= 'a' && s[i] <= 'z' {
			i++
		}
		return i == m
	}
	for _, q := range queries {
		ans = append(ans, check(q, pattern))
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function camelMatch(queries: string[], pattern: string): boolean[] {
    const check = (s: string, t: string) => {
        const m = s.length;
        const n = t.length;
        let i = 0;
        let j = 0;
        for (; j < n; ++i, ++j) {
            while (i < m && s[i] !== t[j] && s[i].codePointAt(0) >= 97) {
                ++i;
            }
            if (i === m || s[i] !== t[j]) {
                return false;
            }
        }
        while (i < m && s[i].codePointAt(0) >= 97) {
            ++i;
        }
        return i == m;
    };
    const ans: boolean[] = [];
    for (const q of queries) {
        ans.push(check(q, pattern));
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

<p>给你一个字符串数组 <code>queries</code>，和一个表示模式的字符串&nbsp;<code>pattern</code>，请你返回一个布尔数组 <code>answer</code> 。只有在待查项&nbsp;<code>queries[i]</code> 与模式串&nbsp;<code>pattern</code> 匹配时，&nbsp;<code>answer[i]</code>&nbsp;才为 <code>true</code>，否则为 <code>false</code>。</p>

<p>如果可以将&nbsp;<strong>小写字母&nbsp;</strong>插入模式串&nbsp;<code>pattern</code>&nbsp;得到待查询项&nbsp;<code>queries[i]</code>，那么待查询项与给定模式串匹配。您可以在模式串中的任何位置插入字符，也可以选择不插入任何字符。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FB"
<strong>输出：</strong>[true,false,true,true,false]
<strong>示例：</strong>
"FooBar" 可以这样生成："F" + "oo" + "B" + "ar"。
"FootBall" 可以这样生成："F" + "oot" + "B" + "all".
"FrameBuffer" 可以这样生成："F" + "rame" + "B" + "uffer".</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FoBa"
<strong>输出：</strong>[true,false,true,false,false]
<strong>解释：</strong>
"FooBar" 可以这样生成："Fo" + "o" + "Ba" + "r".
"FootBall" 可以这样生成："Fo" + "ot" + "Ba" + "ll".
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FoBaT"
<strong>输出：</strong>[false,true,false,false,false]
<strong>解释： </strong>
"FooBarTest" 可以这样生成："Fo" + "o" + "Ba" + "r" + "T" + "est".
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= pattern.length, queries.length &lt;= 100</code></li>
	<li><code>1 &lt;= queries[i].length &lt;= 100</code></li>
	<li><code>queries[i]</code> 和 <code>pattern</code> 由英文字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双指针

我们可以遍历 `queries` 中的每个字符串，判断其是否与 `pattern` 匹配，若匹配则将 `true` 加入答案数组，否则加入 `false`。

接下来，我们实现一个 $check(s, t)$ 函数，用于判断字符串 $s$ 和 $t$ 是否匹配。

我们可以使用双指针 $i$ 和 $j$，分别指向两个字符串的首字符，然后遍历两个字符串。如果指针 $i$ 和 $j$ 指向的字符不同，并且 $s[i]$ 为小写字母，则指针 $i$ 循环向后移动一位。

如果指针 $i$ 已经到达字符串 $s$ 的末尾，或者指针 $i$ 和 $j$ 指向的字符不同，则返回 `false`。否则，指针 $i$ 和 $j$ 同时向后移动一位。当指针 $j$ 到达字符串 $t$ 的末尾时，我们需要判断字符串 $s$ 中剩余的字符是否都为小写字母，若是则返回 `true`，否则返回 `false`。

时间复杂度 $(n \times m)$，其中 $n$ 和 $m$ 分别为数组 `queries` 的长度和字符串 `pattern` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def camelMatch(self, queries: List[str], pattern: str) -> List[bool]:
        def check(s, t):
            m, n = len(s), len(t)
            i = j = 0
            while j < n:
                while i < m and s[i] != t[j] and s[i].islower():
                    i += 1
                if i == m or s[i] != t[j]:
                    return False
                i, j = i + 1, j + 1
            while i < m and s[i].islower():
                i += 1
            return i == m

        return [check(q, pattern) for q in queries]
```

#### Java

```java
class Solution {
    public List<Boolean> camelMatch(String[] queries, String pattern) {
        List<Boolean> ans = new ArrayList<>();
        for (var q : queries) {
            ans.add(check(q, pattern));
        }
        return ans;
    }

    private boolean check(String s, String t) {
        int m = s.length(), n = t.length();
        int i = 0, j = 0;
        for (; j < n; ++i, ++j) {
            while (i < m && s.charAt(i) != t.charAt(j) && Character.isLowerCase(s.charAt(i))) {
                ++i;
            }
            if (i == m || s.charAt(i) != t.charAt(j)) {
                return false;
            }
        }
        while (i < m && Character.isLowerCase(s.charAt(i))) {
            ++i;
        }
        return i == m;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans;
        auto check = [](string& s, string& t) {
            int m = s.size(), n = t.size();
            int i = 0, j = 0;
            for (; j < n; ++i, ++j) {
                while (i < m && s[i] != t[j] && islower(s[i])) {
                    ++i;
                }
                if (i == m || s[i] != t[j]) {
                    return false;
                }
            }
            while (i < m && islower(s[i])) {
                ++i;
            }
            return i == m;
        };
        for (auto& q : queries) {
            ans.push_back(check(q, pattern));
        }
        return ans;
    }
};
```

#### Go

```go
func camelMatch(queries []string, pattern string) (ans []bool) {
	check := func(s, t string) bool {
		m, n := len(s), len(t)
		i, j := 0, 0
		for ; j < n; i, j = i+1, j+1 {
			for i < m && s[i] != t[j] && (s[i] >= 'a' && s[i] <= 'z') {
				i++
			}
			if i == m || s[i] != t[j] {
				return false
			}
		}
		for i < m && s[i] >= 'a' && s[i] <= 'z' {
			i++
		}
		return i == m
	}
	for _, q := range queries {
		ans = append(ans, check(q, pattern))
	}
	return
}
```

#### TypeScript

```ts
function camelMatch(queries: string[], pattern: string): boolean[] {
    const check = (s: string, t: string) => {
        const m = s.length;
        const n = t.length;
        let i = 0;
        let j = 0;
        for (; j < n; ++i, ++j) {
            while (i < m && s[i] !== t[j] && s[i].codePointAt(0) >= 97) {
                ++i;
            }
            if (i === m || s[i] !== t[j]) {
                return false;
            }
        }
        while (i < m && s[i].codePointAt(0) >= 97) {
            ++i;
        }
        return i == m;
    };
    const ans: boolean[] = [];
    for (const q of queries) {
        ans.push(check(q, pattern));
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1024. 视频拼接](https://leetcode.cn/problems/video-stitching){#1024}

{{< tabs "1024" >}}

{{% tab "python" %}}
```python
class Solution:
    def videoStitching(self, clips: List[List[int]], time: int) -> int:
        last = [0] * time
        for a, b in clips:
            if a < time:
                last[a] = max(last[a], b)
        ans = mx = pre = 0
        for i, v in enumerate(last):
            mx = max(mx, v)
            if mx <= i:
                return -1
            if pre == i:
                ans += 1
                pre = mx
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int videoStitching(int[][] clips, int time) {
        int[] last = new int[time];
        for (var e : clips) {
            int a = e[0], b = e[1];
            if (a < time) {
                last[a] = Math.max(last[a], b);
            }
        }
        int ans = 0, mx = 0, pre = 0;
        for (int i = 0; i < time; ++i) {
            mx = Math.max(mx, last[i]);
            if (mx <= i) {
                return -1;
            }
            if (pre == i) {
                ++ans;
                pre = mx;
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
    int videoStitching(vector<vector<int>>& clips, int time) {
        vector<int> last(time);
        for (auto& v : clips) {
            int a = v[0], b = v[1];
            if (a < time) {
                last[a] = max(last[a], b);
            }
        }
        int mx = 0, ans = 0;
        int pre = 0;
        for (int i = 0; i < time; ++i) {
            mx = max(mx, last[i]);
            if (mx <= i) {
                return -1;
            }
            if (pre == i) {
                ++ans;
                pre = mx;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func videoStitching(clips [][]int, time int) int {
	last := make([]int, time)
	for _, v := range clips {
		a, b := v[0], v[1]
		if a < time {
			last[a] = max(last[a], b)
		}
	}
	ans, mx, pre := 0, 0, 0
	for i, v := range last {
		mx = max(mx, v)
		if mx <= i {
			return -1
		}
		if pre == i {
			ans++
			pre = mx
		}
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

<p>你将会获得一系列视频片段，这些片段来自于一项持续时长为&nbsp;<code>time</code>&nbsp;秒的体育赛事。这些片段可能有所重叠，也可能长度不一。</p>

<p>使用数组&nbsp;<code>clips</code> 描述所有的视频片段，其中 <code>clips[i] = [start<sub>i</sub>, end<sub>i</sub>]</code> 表示：某个视频片段开始于&nbsp;<code>start<sub>i</sub></code>&nbsp;并于&nbsp;<code>end<sub>i</sub></code>&nbsp;结束。</p>

<p>甚至可以对这些片段自由地再剪辑：</p>

<ul>
	<li>例如，片段&nbsp;<code>[0, 7]</code>&nbsp;可以剪切成&nbsp;<code>[0, 1] +&nbsp;[1, 3] + [3, 7]</code>&nbsp;三部分。</li>
</ul>

<p>我们需要将这些片段进行再剪辑，并将剪辑后的内容拼接成覆盖整个运动过程的片段（<code>[0, time]</code>）。返回所需片段的最小数目，如果无法完成该任务，则返回&nbsp;<code>-1</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>clips = [[0,2],[4,6],[8,10],[1,9],[1,5],[5,9]], time = 10
<strong>输出：</strong>3
<strong>解释：</strong>
选中 [0,2], [8,10], [1,9] 这三个片段。
然后，按下面的方案重制比赛片段：
将 [1,9] 再剪辑为 [1,2] + [2,8] + [8,9] 。
现在手上的片段为 [0,2] + [2,8] + [8,10]，而这些覆盖了整场比赛 [0, 10]。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>clips = [[0,1],[1,2]], time = 5
<strong>输出：</strong>-1
<strong>解释：</strong>
无法只用 [0,1] 和 [1,2] 覆盖 [0,5] 的整个过程。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>clips = [[0,1],[6,8],[0,2],[5,6],[0,4],[0,3],[6,7],[1,3],[4,7],[1,4],[2,5],[2,6],[3,4],[4,5],[5,7],[6,9]], time = 9
<strong>输出：</strong>3
<strong>解释： </strong>
选取片段 [0,4], [4,7] 和 [6,9] 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= clips.length &lt;= 100</code></li>
	<li><code>0 &lt;= start<sub>i</sub> &lt;= end<sub>i</sub> &lt;= 100</code></li>
	<li><code>1 &lt;= time &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心

注意到，如果相同起点的子区间有多个，那么选择右端点最大的那个子区间是最优的。

因此，我们可以预处理所有子区间，对于每一个位置 $i$，算出所有以 $i$ 为起点的子区间中，右端点最大的那个位置，记录在数组 $last[i]$ 中。

我们定义变量 `mx` 表示当前能够到达的最远位置，变量 `ans` 表示当前需要的最少子区间数，变量 `pre` 表示上一个被使用的子区间的右端点。

接下来，我们从 $0$ 开始枚举所有位置 $i$，用 $last[i]$ 来更新 `mx`。如果更新后 $mx = i$，说明无法覆盖下一个位置，因此无法完成任务，返回 $-1$。

同时我们记录上一个被使用的子区间的右端点 `pre`，如果 $pre = i$，说明需要使用一个新的子区间，因此我们将 `ans` 加 $1$，并将 `pre` 更新为 `mx`。

遍历结束后，返回 `ans` 即可。

时间复杂度 $O(n+m)$，空间复杂度 $O(m)$。其中 $n$ 和 $m$ 分别是数组 `clips` 的长度和 `time` 的值。

相似题目：

-   [45. 跳跃游戏 II](https://github.com/doocs/leetcode/blob/main/solution/0000-0099/0045.Jump%20Game%20II/README.md)
-   [55. 跳跃游戏](https://github.com/doocs/leetcode/blob/main/solution/0000-0099/0055.Jump%20Game/README.md)
-   [1326. 灌溉花园的最少水龙头数目](https://github.com/doocs/leetcode/blob/main/solution/1300-1399/1326.Minimum%20Number%20of%20Taps%20to%20Open%20to%20Water%20a%20Garden/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def videoStitching(self, clips: List[List[int]], time: int) -> int:
        last = [0] * time
        for a, b in clips:
            if a < time:
                last[a] = max(last[a], b)
        ans = mx = pre = 0
        for i, v in enumerate(last):
            mx = max(mx, v)
            if mx <= i:
                return -1
            if pre == i:
                ans += 1
                pre = mx
        return ans
```

#### Java

```java
class Solution {
    public int videoStitching(int[][] clips, int time) {
        int[] last = new int[time];
        for (var e : clips) {
            int a = e[0], b = e[1];
            if (a < time) {
                last[a] = Math.max(last[a], b);
            }
        }
        int ans = 0, mx = 0, pre = 0;
        for (int i = 0; i < time; ++i) {
            mx = Math.max(mx, last[i]);
            if (mx <= i) {
                return -1;
            }
            if (pre == i) {
                ++ans;
                pre = mx;
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
    int videoStitching(vector<vector<int>>& clips, int time) {
        vector<int> last(time);
        for (auto& v : clips) {
            int a = v[0], b = v[1];
            if (a < time) {
                last[a] = max(last[a], b);
            }
        }
        int mx = 0, ans = 0;
        int pre = 0;
        for (int i = 0; i < time; ++i) {
            mx = max(mx, last[i]);
            if (mx <= i) {
                return -1;
            }
            if (pre == i) {
                ++ans;
                pre = mx;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func videoStitching(clips [][]int, time int) int {
	last := make([]int, time)
	for _, v := range clips {
		a, b := v[0], v[1]
		if a < time {
			last[a] = max(last[a], b)
		}
	}
	ans, mx, pre := 0, 0, 0
	for i, v := range last {
		mx = max(mx, v)
		if mx <= i {
			return -1
		}
		if pre == i {
			ans++
			pre = mx
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

# [1025. 除数博弈](https://leetcode.cn/problems/divisor-game){#1025}

{{< tabs "1025" >}}

{{% tab "python" %}}
```python
class Solution:
    def divisorGame(self, n: int) -> bool:
        return n % 2 == 0
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean divisorGame(int n) {
        return n % 2 == 0;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool divisorGame(int n) {
        return n % 2 == 0;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func divisorGame(n int) bool {
	return n%2 == 0
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
var divisorGame = function (n) {
    return n % 2 === 0;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>爱丽丝和鲍勃一起玩游戏，他们轮流行动。爱丽丝先手开局。</p>

<p>最初，黑板上有一个数字&nbsp;<code>n</code>&nbsp;。在每个玩家的回合，玩家需要执行以下操作：</p>

<ul>
	<li>选出任一&nbsp;<code>x</code>，满足&nbsp;<code>0 &lt; x &lt; n</code>&nbsp;且&nbsp;<code>n % x == 0</code>&nbsp;。</li>
	<li>用 <code>n - x</code>&nbsp;替换黑板上的数字&nbsp;<code>n</code> 。</li>
</ul>

<p>如果玩家无法执行这些操作，就会输掉游戏。</p>

<p><em>只有在爱丽丝在游戏中取得胜利时才返回&nbsp;<code>true</code>&nbsp;。假设两个玩家都以最佳状态参与游戏。</em></p>

<p>&nbsp;</p>

<ol>
</ol>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 2
<strong>输出：</strong>true
<strong>解释：</strong>爱丽丝选择 1，鲍勃无法进行操作。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 3
<strong>输出：</strong>false
<strong>解释：</strong>爱丽丝选择 1，鲍勃也选择 1，然后爱丽丝无法进行操作。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数学归纳法

-   当 $n=1$，先手败
-   当 $n=2$，先手拿 $1$，剩下 $1$，后手败，先手胜
-   当 $n=3$，先手拿 $1$，剩下 $2$，后手胜，先手败
-   当 $n=4$，先手拿 $1$，剩下 $3$，后手败，先手胜
-   ...

猜想，当 $n$ 为奇数时，先手败；当 $n$ 为偶数时，先手胜。

证明：

1. 若 $n=1$ 或 $n=2$，结论成立；
1. 若 $n \gt 2$，假设 $n \le k$ 时，该结论成立，则 $n=k+1$ 时：
    - 若 $k+1$ 为奇数，由于 $x$ 是 $k+1$ 的因数，那么 $x$ 只可能是奇数，因此 $k+1-x$ 为偶数，后手胜，先手败；
    - 若 $k+1$ 为偶数，此时 $x$ 既可以是奇数 $1$，也可以是偶数，若 $x$ 取奇数，那么 $k+1-x$ 为奇数，后手败，先手胜。

综上，当 $n$ 为奇数时，先手败；当 $n$ 为偶数时，先手胜。结论正确。

时间复杂度 $O(1)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def divisorGame(self, n: int) -> bool:
        return n % 2 == 0
```

#### Java

```java
class Solution {
    public boolean divisorGame(int n) {
        return n % 2 == 0;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool divisorGame(int n) {
        return n % 2 == 0;
    }
};
```

#### Go

```go
func divisorGame(n int) bool {
	return n%2 == 0
}
```

#### JavaScript

```js
var divisorGame = function (n) {
    return n % 2 === 0;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1026. 节点与其祖先之间的最大差值](https://leetcode.cn/problems/maximum-difference-between-node-and-ancestor){#1026}

{{< tabs "1026" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxAncestorDiff(self, root: Optional[TreeNode]) -> int:
        def dfs(root: Optional[TreeNode], mi: int, mx: int):
            if root is None:
                return
            nonlocal ans
            ans = max(ans, abs(mi - root.val), abs(mx - root.val))
            mi = min(mi, root.val)
            mx = max(mx, root.val)
            dfs(root.left, mi, mx)
            dfs(root.right, mi, mx)

        ans = 0
        dfs(root, root.val, root.val)
        return ans
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
    private int ans;

    public int maxAncestorDiff(TreeNode root) {
        dfs(root, root.val, root.val);
        return ans;
    }

    private void dfs(TreeNode root, int mi, int mx) {
        if (root == null) {
            return;
        }
        int x = Math.max(Math.abs(mi - root.val), Math.abs(mx - root.val));
        ans = Math.max(ans, x);
        mi = Math.min(mi, root.val);
        mx = Math.max(mx, root.val);
        dfs(root.left, mi, mx);
        dfs(root.right, mi, mx);
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
    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        function<void(TreeNode*, int, int)> dfs = [&](TreeNode* root, int mi, int mx) {
            if (!root) {
                return;
            }
            ans = max({ans, abs(mi - root->val), abs(mx - root->val)});
            mi = min(mi, root->val);
            mx = max(mx, root->val);
            dfs(root->left, mi, mx);
            dfs(root->right, mi, mx);
        };
        dfs(root, root->val, root->val);
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
func maxAncestorDiff(root *TreeNode) (ans int) {
	var dfs func(*TreeNode, int, int)
	dfs = func(root *TreeNode, mi, mx int) {
		if root == nil {
			return
		}
		ans = max(ans, max(abs(mi-root.Val), abs(mx-root.Val)))
		mi = min(mi, root.Val)
		mx = max(mx, root.Val)
		dfs(root.Left, mi, mx)
		dfs(root.Right, mi, mx)
	}
	dfs(root, root.Val, root.Val)
	return
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
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

function maxAncestorDiff(root: TreeNode | null): number {
    const dfs = (root: TreeNode | null, mi: number, mx: number): void => {
        if (!root) {
            return;
        }
        ans = Math.max(ans, Math.abs(root.val - mi), Math.abs(root.val - mx));
        mi = Math.min(mi, root.val);
        mx = Math.max(mx, root.val);
        dfs(root.left, mi, mx);
        dfs(root.right, mi, mx);
    };
    let ans: number = 0;
    dfs(root, root.val, root.val);
    return ans;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var maxAncestorDiff = function (root) {
    let ans = 0;
    const dfs = (root, mi, mx) => {
        if (!root) {
            return;
        }
        ans = Math.max(ans, Math.abs(mi - root.val), Math.abs(mx - root.val));
        mi = Math.min(mi, root.val);
        mx = Math.max(mx, root.val);
        dfs(root.left, mi, mx);
        dfs(root.right, mi, mx);
    };
    dfs(root, root.val, root.val);
    return ans;
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
    private int ans;

    public int MaxAncestorDiff(TreeNode root) {
        dfs(root, root.val, root.val);
        return ans;
    }

    private void dfs(TreeNode root, int mi, int mx) {
        if (root == null) {
            return;
        }
        int x = Math.Max(Math.Abs(mi - root.val), Math.Abs(mx - root.val));
        ans = Math.Max(ans, x);
        mi = Math.Min(mi, root.val);
        mx = Math.Max(mx, root.val);
        dfs(root.left, mi, mx);
        dfs(root.right, mi, mx);
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定二叉树的根节点 <code>root</code>，找出存在于 <strong>不同</strong> 节点 <code>A</code> 和 <code>B</code> 之间的最大值 <code>V</code>，其中 <code>V = |A.val - B.val|</code>，且 <code>A</code> 是 <code>B</code> 的祖先。</p>

<p>（如果 A 的任何子节点之一为 B，或者 A 的任何子节点是 B 的祖先，那么我们认为 A 是 B 的祖先）</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1000-1099/1026.Maximum%20Difference%20Between%20Node%20and%20Ancestor/images/tmp-tree.jpg" style="width: 400px; height: 390px;" /></p>

<pre>
<strong>输入：</strong>root = [8,3,10,1,6,null,14,null,null,4,7,13]
<strong>输出：</strong>7
<strong>解释： </strong>
我们有大量的节点与其祖先的差值，其中一些如下：
|8 - 3| = 5
|3 - 7| = 4
|8 - 1| = 7
|10 - 13| = 3
在所有可能的差值中，最大值 7 由 |8 - 1| = 7 得出。
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1000-1099/1026.Maximum%20Difference%20Between%20Node%20and%20Ancestor/images/tmp-tree-1.jpg" style="width: 250px; height: 349px;" />
<pre>
<strong>输入：</strong>root = [1,null,2,null,0,3]
<strong>输出：</strong>3
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中的节点数在 <code>2</code> 到 <code>5000</code> 之间。</li>
	<li><code>0 <= Node.val <= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS

对于每个节点，求其与祖先节点的最大差值，我们只需要求出该节点与祖先节点最大值和最小值的差值。取所有节点与祖先节点差值的最大值即可。

因此，我们设计一个函数 $dfs(root, mi, mx)$，表示当前搜索到的节点为 $root$，其祖先节点的最大值为 $mx$，最小值为 $mi$，函数内更新最大差值 $ans$。

函数 $dfs(root, mi, mx)$ 的逻辑如下：

-   若 $root$ 为空，直接返回。
-   否则，我们更新 $ans = max(ans, |mi - root.val|, |mx - root.val|)$。
-   然后更新 $mi = min(mi, root.val)$, $mx = max(mx, root.val)$，并且递归搜索左右子树。

在主函数中，我们调用 $dfs(root, root.val, root.val)$，最后返回 $ans$ 即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为二叉树节点个数。

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
    def maxAncestorDiff(self, root: Optional[TreeNode]) -> int:
        def dfs(root: Optional[TreeNode], mi: int, mx: int):
            if root is None:
                return
            nonlocal ans
            ans = max(ans, abs(mi - root.val), abs(mx - root.val))
            mi = min(mi, root.val)
            mx = max(mx, root.val)
            dfs(root.left, mi, mx)
            dfs(root.right, mi, mx)

        ans = 0
        dfs(root, root.val, root.val)
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
    private int ans;

    public int maxAncestorDiff(TreeNode root) {
        dfs(root, root.val, root.val);
        return ans;
    }

    private void dfs(TreeNode root, int mi, int mx) {
        if (root == null) {
            return;
        }
        int x = Math.max(Math.abs(mi - root.val), Math.abs(mx - root.val));
        ans = Math.max(ans, x);
        mi = Math.min(mi, root.val);
        mx = Math.max(mx, root.val);
        dfs(root.left, mi, mx);
        dfs(root.right, mi, mx);
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
    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        function<void(TreeNode*, int, int)> dfs = [&](TreeNode* root, int mi, int mx) {
            if (!root) {
                return;
            }
            ans = max({ans, abs(mi - root->val), abs(mx - root->val)});
            mi = min(mi, root->val);
            mx = max(mx, root->val);
            dfs(root->left, mi, mx);
            dfs(root->right, mi, mx);
        };
        dfs(root, root->val, root->val);
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
func maxAncestorDiff(root *TreeNode) (ans int) {
	var dfs func(*TreeNode, int, int)
	dfs = func(root *TreeNode, mi, mx int) {
		if root == nil {
			return
		}
		ans = max(ans, max(abs(mi-root.Val), abs(mx-root.Val)))
		mi = min(mi, root.Val)
		mx = max(mx, root.Val)
		dfs(root.Left, mi, mx)
		dfs(root.Right, mi, mx)
	}
	dfs(root, root.Val, root.Val)
	return
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
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

function maxAncestorDiff(root: TreeNode | null): number {
    const dfs = (root: TreeNode | null, mi: number, mx: number): void => {
        if (!root) {
            return;
        }
        ans = Math.max(ans, Math.abs(root.val - mi), Math.abs(root.val - mx));
        mi = Math.min(mi, root.val);
        mx = Math.max(mx, root.val);
        dfs(root.left, mi, mx);
        dfs(root.right, mi, mx);
    };
    let ans: number = 0;
    dfs(root, root.val, root.val);
    return ans;
}
```

#### JavaScript

```js
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var maxAncestorDiff = function (root) {
    let ans = 0;
    const dfs = (root, mi, mx) => {
        if (!root) {
            return;
        }
        ans = Math.max(ans, Math.abs(mi - root.val), Math.abs(mx - root.val));
        mi = Math.min(mi, root.val);
        mx = Math.max(mx, root.val);
        dfs(root.left, mi, mx);
        dfs(root.right, mi, mx);
    };
    dfs(root, root.val, root.val);
    return ans;
};
```

#### C#

```cs
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
    private int ans;

    public int MaxAncestorDiff(TreeNode root) {
        dfs(root, root.val, root.val);
        return ans;
    }

    private void dfs(TreeNode root, int mi, int mx) {
        if (root == null) {
            return;
        }
        int x = Math.Max(Math.Abs(mi - root.val), Math.Abs(mx - root.val));
        ans = Math.Max(ans, x);
        mi = Math.Min(mi, root.val);
        mx = Math.Max(mx, root.val);
        dfs(root.left, mi, mx);
        dfs(root.right, mi, mx);
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1027. 最长等差数列](https://leetcode.cn/problems/longest-arithmetic-subsequence){#1027}

{{< tabs "1027" >}}

{{% tab "python" %}}
```python
class Solution:
    def longestArithSeqLength(self, nums: List[int]) -> int:
        n = len(nums)
        f = [[1] * 1001 for _ in range(n)]
        ans = 0
        for i in range(1, n):
            for k in range(i):
                j = nums[i] - nums[k] + 500
                f[i][j] = max(f[i][j], f[k][j] + 1)
                ans = max(ans, f[i][j])
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int longestArithSeqLength(int[] nums) {
        int n = nums.length;
        int ans = 0;
        int[][] f = new int[n][1001];
        for (int i = 1; i < n; ++i) {
            for (int k = 0; k < i; ++k) {
                int j = nums[i] - nums[k] + 500;
                f[i][j] = Math.max(f[i][j], f[k][j] + 1);
                ans = Math.max(ans, f[i][j]);
            }
        }
        return ans + 1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        int f[n][1001];
        memset(f, 0, sizeof(f));
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            for (int k = 0; k < i; ++k) {
                int j = nums[i] - nums[k] + 500;
                f[i][j] = max(f[i][j], f[k][j] + 1);
                ans = max(ans, f[i][j]);
            }
        }
        return ans + 1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func longestArithSeqLength(nums []int) int {
	n := len(nums)
	f := make([][]int, n)
	for i := range f {
		f[i] = make([]int, 1001)
	}
	ans := 0
	for i := 1; i < n; i++ {
		for k := 0; k < i; k++ {
			j := nums[i] - nums[k] + 500
			f[i][j] = max(f[i][j], f[k][j]+1)
			ans = max(ans, f[i][j])
		}
	}
	return ans + 1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function longestArithSeqLength(nums: number[]): number {
    const n = nums.length;
    let ans = 0;
    const f: number[][] = Array.from({ length: n }, () => new Array(1001).fill(0));
    for (let i = 1; i < n; ++i) {
        for (let k = 0; k < i; ++k) {
            const j = nums[i] - nums[k] + 500;
            f[i][j] = Math.max(f[i][j], f[k][j] + 1);
            ans = Math.max(ans, f[i][j]);
        }
    }
    return ans + 1;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组&nbsp;<code>nums</code>，返回 <code>nums</code>&nbsp;中最长等差子序列的<strong>长度</strong>。</p>

<p>回想一下，<code>nums</code> 的子序列是一个列表&nbsp;<code>nums[i<sub>1</sub>], nums[i<sub>2</sub>], ..., nums[i<sub>k</sub>]</code> ，且&nbsp;<code>0 &lt;= i<sub>1</sub> &lt; i<sub>2</sub> &lt; ... &lt; i<sub>k</sub> &lt;= nums.length - 1</code>。并且如果&nbsp;<code>seq[i+1] - seq[i]</code>(&nbsp;<code>0 &lt;= i &lt; seq.length - 1</code>) 的值都相同，那么序列&nbsp;<code>seq</code>&nbsp;是等差的。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [3,6,9,12]
<strong>输出：</strong>4
<strong>解释： </strong>
整个数组是公差为 3 的等差数列。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [9,4,7,2,10]
<strong>输出：</strong>3
<strong>解释：</strong>
最长的等差子序列是 [4,7,10]。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [20,1,15,3,10,5,8]
<strong>输出：</strong>4
<strong>解释：</strong>
最长的等差子序列是 [20,15,10,5]。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 500</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i][j]$ 表示以 $nums[i]$ 结尾且公差为 $j$ 的等差数列的最大长度。初始时 $f[i][j]=1$，即每个元素自身都是一个长度为 $1$ 的等差数列。

> 由于公差可能为负数，且最大差值为 $500$，因此，我们可以将统一将公差加上 $500$，这样公差的范围就变成了 $[0, 1000]$。

考虑 $f[i]$，我们可以枚举 $nums[i]$ 的前一个元素 $nums[k]$，那么公差 $j=nums[i]-nums[k]+500$，此时有 $f[i][j]=\max(f[i][j], f[k][j]+1)$，然后我们更新答案 $ans=\max(ans, f[i][j])$。

最后返回答案即可。

> 如果初始时 $f[i][j]=0$，那么我们需要在最后返回答案时加上 $1$。

时间复杂度 $O(n \times (d + n))$，空间复杂度 $O(n \times d)$。其中 $n$ 和 $d$ 分别是数组 $nums$ 的长度以及数组 $nums$ 中元素的最大值与最小值的差值。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def longestArithSeqLength(self, nums: List[int]) -> int:
        n = len(nums)
        f = [[1] * 1001 for _ in range(n)]
        ans = 0
        for i in range(1, n):
            for k in range(i):
                j = nums[i] - nums[k] + 500
                f[i][j] = max(f[i][j], f[k][j] + 1)
                ans = max(ans, f[i][j])
        return ans
```

#### Java

```java
class Solution {
    public int longestArithSeqLength(int[] nums) {
        int n = nums.length;
        int ans = 0;
        int[][] f = new int[n][1001];
        for (int i = 1; i < n; ++i) {
            for (int k = 0; k < i; ++k) {
                int j = nums[i] - nums[k] + 500;
                f[i][j] = Math.max(f[i][j], f[k][j] + 1);
                ans = Math.max(ans, f[i][j]);
            }
        }
        return ans + 1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        int f[n][1001];
        memset(f, 0, sizeof(f));
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            for (int k = 0; k < i; ++k) {
                int j = nums[i] - nums[k] + 500;
                f[i][j] = max(f[i][j], f[k][j] + 1);
                ans = max(ans, f[i][j]);
            }
        }
        return ans + 1;
    }
};
```

#### Go

```go
func longestArithSeqLength(nums []int) int {
	n := len(nums)
	f := make([][]int, n)
	for i := range f {
		f[i] = make([]int, 1001)
	}
	ans := 0
	for i := 1; i < n; i++ {
		for k := 0; k < i; k++ {
			j := nums[i] - nums[k] + 500
			f[i][j] = max(f[i][j], f[k][j]+1)
			ans = max(ans, f[i][j])
		}
	}
	return ans + 1
}
```

#### TypeScript

```ts
function longestArithSeqLength(nums: number[]): number {
    const n = nums.length;
    let ans = 0;
    const f: number[][] = Array.from({ length: n }, () => new Array(1001).fill(0));
    for (let i = 1; i < n; ++i) {
        for (let k = 0; k < i; ++k) {
            const j = nums[i] - nums[k] + 500;
            f[i][j] = Math.max(f[i][j], f[k][j] + 1);
            ans = Math.max(ans, f[i][j]);
        }
    }
    return ans + 1;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1028. 从先序遍历还原二叉树](https://leetcode.cn/problems/recover-a-tree-from-preorder-traversal){#1028}

{{< tabs "1028" >}}

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
    public TreeNode recoverFromPreorder(String traversal) {
        Stack<TreeNode> stack = new Stack<>();
        int i = 0;

        while (i < traversal.length()) {
            int depth = 0;
            while (i < traversal.length() && traversal.charAt(i) == '-') {
                depth++;
                i++;
            }

            int num = 0;
            while (i < traversal.length() && Character.isDigit(traversal.charAt(i))) {
                num = num * 10 + (traversal.charAt(i) - '0');
                i++;
            }

            // Create the new node
            TreeNode newNode = new TreeNode(num);

            while (stack.size() > depth) {
                stack.pop();
            }
            if (!stack.isEmpty()) {
                if (stack.peek().left == null) {
                    stack.peek().left = newNode;
                } else {
                    stack.peek().right = newNode;
                }
            }

            stack.push(newNode);
        }
        return stack.isEmpty() ? null : stack.get(0);
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* recoverFromPreorder(string S) {
        stack<TreeNode*> st;
        int depth = 0;
        int num = 0;
        for (int i = 0; i < S.length(); ++i) {
            if (S[i] == '-') {
                depth++;
            } else {
                num = 10 * num + S[i] - '0';
            }
            if (i + 1 >= S.length() || (isdigit(S[i]) && S[i + 1] == '-')) {
                TreeNode* newNode = new TreeNode(num);
                while (st.size() > depth) {
                    st.pop();
                }
                if (!st.empty()) {
                    if (st.top()->left == nullptr) {
                        st.top()->left = newNode;
                    } else {
                        st.top()->right = newNode;
                    }
                }
                st.push(newNode);
                depth = 0;
                num = 0;
            }
        }
        TreeNode* res;
        while (!st.empty()) {
            res = st.top();
            st.pop();
        }
        return res;
    }
};
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function recoverFromPreorder(traversal: string): TreeNode | null {
    const stack: TreeNode[] = [];
    let i = 0;

    while (i < traversal.length) {
        let depth = 0;
        while (i < traversal.length && traversal[i] === '-') {
            depth++;
            i++;
        }

        let num = 0;
        while (i < traversal.length && !Number.isNaN(+traversal[i])) {
            num = num * 10 + +traversal[i];
            i++;
        }

        // Create the new node
        const newNode = new TreeNode(num);

        while (stack.length > depth) {
            stack.pop();
        }

        if (stack.length > 0) {
            const i = stack.length - 1;
            if (stack[i].left === null) {
                stack[i].left = newNode;
            } else {
                stack[i].right = newNode;
            }
        }

        stack.push(newNode);
    }

    return stack.length ? stack[0] : null;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
function recoverFromPreorder(traversal) {
    const stack = [];
    let i = 0;

    while (i < traversal.length) {
        let depth = 0;
        while (i < traversal.length && traversal[i] === '-') {
            depth++;
            i++;
        }

        let num = 0;
        while (i < traversal.length && !Number.isNaN(+traversal[i])) {
            num = num * 10 + +traversal[i];
            i++;
        }

        // Create the new node
        const newNode = new TreeNode(num);

        while (stack.length > depth) {
            stack.pop();
        }

        if (stack.length > 0) {
            const i = stack.length - 1;
            if (stack[i].left === null) {
                stack[i].left = newNode;
            } else {
                stack[i].right = newNode;
            }
        }

        stack.push(newNode);
    }

    return stack.length ? stack[0] : null;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>我们从二叉树的根节点 <code>root</code>&nbsp;开始进行深度优先搜索。</p>

<p>在遍历中的每个节点处，我们输出&nbsp;<code>D</code>&nbsp;条短划线（其中&nbsp;<code>D</code>&nbsp;是该节点的深度），然后输出该节点的值。（<em>如果节点的深度为 <code>D</code>，则其直接子节点的深度为 <code>D + 1</code>。根节点的深度为 <code>0</code>）。</em></p>

<p>如果节点只有一个子节点，那么保证该子节点为左子节点。</p>

<p>给出遍历输出&nbsp;<code>S</code>，还原树并返回其根节点&nbsp;<code>root</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1000-1099/1028.Recover%20a%20Tree%20From%20Preorder%20Traversal/images/recover-a-tree-from-preorder-traversal.png" style="height: 200px; width: 320px;"></strong></p>

<pre><strong>输入：</strong>&quot;1-2--3--4-5--6--7&quot;
<strong>输出：</strong>[1,2,5,3,4,6,7]
</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1000-1099/1028.Recover%20a%20Tree%20From%20Preorder%20Traversal/images/screen-shot-2019-04-10-at-114101-pm.png" style="height: 250px; width: 256px;"></strong></p>

<pre><strong>输入：</strong>&quot;1-2--3---4-5--6---7&quot;
<strong>输出：</strong>[1,2,5,3,null,6,null,4,null,7]
</pre>

<p><strong>示例 3：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1000-1099/1028.Recover%20a%20Tree%20From%20Preorder%20Traversal/images/screen-shot-2019-04-10-at-114955-pm.png" style="height: 250px; width: 276px;"></p>

<pre><strong>输入：</strong>&quot;1-401--349---90--88&quot;
<strong>输出：</strong>[1,401,null,349,88,90]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>原始树中的节点数介于 <code>1</code> 和 <code>1000</code> 之间。</li>
	<li>每个节点的值介于 <code>1</code> 和 <code>10 ^ 9</code> 之间。</li>
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
    public TreeNode recoverFromPreorder(String traversal) {
        Stack<TreeNode> stack = new Stack<>();
        int i = 0;

        while (i < traversal.length()) {
            int depth = 0;
            while (i < traversal.length() && traversal.charAt(i) == '-') {
                depth++;
                i++;
            }

            int num = 0;
            while (i < traversal.length() && Character.isDigit(traversal.charAt(i))) {
                num = num * 10 + (traversal.charAt(i) - '0');
                i++;
            }

            // Create the new node
            TreeNode newNode = new TreeNode(num);

            while (stack.size() > depth) {
                stack.pop();
            }
            if (!stack.isEmpty()) {
                if (stack.peek().left == null) {
                    stack.peek().left = newNode;
                } else {
                    stack.peek().right = newNode;
                }
            }

            stack.push(newNode);
        }
        return stack.isEmpty() ? null : stack.get(0);
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* recoverFromPreorder(string S) {
        stack<TreeNode*> st;
        int depth = 0;
        int num = 0;
        for (int i = 0; i < S.length(); ++i) {
            if (S[i] == '-') {
                depth++;
            } else {
                num = 10 * num + S[i] - '0';
            }
            if (i + 1 >= S.length() || (isdigit(S[i]) && S[i + 1] == '-')) {
                TreeNode* newNode = new TreeNode(num);
                while (st.size() > depth) {
                    st.pop();
                }
                if (!st.empty()) {
                    if (st.top()->left == nullptr) {
                        st.top()->left = newNode;
                    } else {
                        st.top()->right = newNode;
                    }
                }
                st.push(newNode);
                depth = 0;
                num = 0;
            }
        }
        TreeNode* res;
        while (!st.empty()) {
            res = st.top();
            st.pop();
        }
        return res;
    }
};
```

#### TypeScript

```ts
function recoverFromPreorder(traversal: string): TreeNode | null {
    const stack: TreeNode[] = [];
    let i = 0;

    while (i < traversal.length) {
        let depth = 0;
        while (i < traversal.length && traversal[i] === '-') {
            depth++;
            i++;
        }

        let num = 0;
        while (i < traversal.length && !Number.isNaN(+traversal[i])) {
            num = num * 10 + +traversal[i];
            i++;
        }

        // Create the new node
        const newNode = new TreeNode(num);

        while (stack.length > depth) {
            stack.pop();
        }

        if (stack.length > 0) {
            const i = stack.length - 1;
            if (stack[i].left === null) {
                stack[i].left = newNode;
            } else {
                stack[i].right = newNode;
            }
        }

        stack.push(newNode);
    }

    return stack.length ? stack[0] : null;
}
```

#### JavaScript

```js
function recoverFromPreorder(traversal) {
    const stack = [];
    let i = 0;

    while (i < traversal.length) {
        let depth = 0;
        while (i < traversal.length && traversal[i] === '-') {
            depth++;
            i++;
        }

        let num = 0;
        while (i < traversal.length && !Number.isNaN(+traversal[i])) {
            num = num * 10 + +traversal[i];
            i++;
        }

        // Create the new node
        const newNode = new TreeNode(num);

        while (stack.length > depth) {
            stack.pop();
        }

        if (stack.length > 0) {
            const i = stack.length - 1;
            if (stack[i].left === null) {
                stack[i].left = newNode;
            } else {
                stack[i].right = newNode;
            }
        }

        stack.push(newNode);
    }

    return stack.length ? stack[0] : null;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1029. 两地调度](https://leetcode.cn/problems/two-city-scheduling){#1029}

{{< tabs "1029" >}}

{{% tab "python" %}}
```python
class Solution:
    def twoCitySchedCost(self, costs: List[List[int]]) -> int:
        costs.sort(key=lambda x: x[0] - x[1])
        n = len(costs) >> 1
        return sum(costs[i][0] + costs[i + n][1] for i in range(n))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int twoCitySchedCost(int[][] costs) {
        Arrays.sort(costs, (a, b) -> { return a[0] - a[1] - (b[0] - b[1]); });
        int ans = 0;
        int n = costs.length >> 1;
        for (int i = 0; i < n; ++i) {
            ans += costs[i][0] + costs[i + n][1];
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
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] - a[1] < b[0] - b[1];
        });
        int n = costs.size() / 2;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += costs[i][0] + costs[i + n][1];
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func twoCitySchedCost(costs [][]int) (ans int) {
	sort.Slice(costs, func(i, j int) bool {
		return costs[i][0]-costs[i][1] < costs[j][0]-costs[j][1]
	})
	n := len(costs) >> 1
	for i, a := range costs[:n] {
		ans += a[0] + costs[i+n][1]
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function twoCitySchedCost(costs: number[][]): number {
    costs.sort((a, b) => a[0] - a[1] - (b[0] - b[1]));
    const n = costs.length >> 1;
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        ans += costs[i][0] + costs[i + n][1];
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

<p>公司计划面试 <code>2n</code> 人。给你一个数组 <code>costs</code> ，其中 <code>costs[i] = [aCost<sub>i</sub>, bCost<sub>i</sub>]</code> 。第 <code>i</code> 人飞往 <code>a</code> 市的费用为 <code>aCost<sub>i</sub></code> ，飞往 <code>b</code> 市的费用为 <code>bCost<sub>i</sub></code> 。</p>

<p>返回将每个人都飞到 <code>a</code> 、<code>b</code> 中某座城市的最低费用，要求每个城市都有 <code>n</code> 人抵达<strong>。</strong></p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>costs = [[10,20],[30,200],[400,50],[30,20]]
<strong>输出：</strong>110
<strong>解释：</strong>
第一个人去 a 市，费用为 10。
第二个人去 a 市，费用为 30。
第三个人去 b 市，费用为 50。
第四个人去 b 市，费用为 20。

最低总费用为 10 + 30 + 50 + 20 = 110，每个城市都有一半的人在面试。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>costs = [[259,770],[448,54],[926,667],[184,139],[840,118],[577,469]]
<strong>输出：</strong>1859
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>costs = [[515,563],[451,713],[537,709],[343,819],[855,779],[457,60],[650,359],[631,42]]
<strong>输出：</strong>3086
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 * n == costs.length</code></li>
	<li><code>2 <= costs.length <= 100</code></li>
	<li><code>costs.length</code> 为偶数</li>
	<li><code>1 <= aCost<sub>i</sub>, bCost<sub>i</sub> <= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 贪心

我们不妨先假设所有人都去 $b$ 市，然后我们要从中选出 $n$ 个人去 $a$ 市，使得总费用最小。如果一个人去 $a$ 市的费用比去 $b$ 市的费用小，我们把这个人从 $b$ 市调到 $a$ 市，这样总费用就会减少。因此，我们可以将所有人按照去 $a$ 市的费用与去 $b$ 市的费用的差值从小到大排序，然后选出前 $n$ 个人去 $a$ 市，剩下的人去 $b$ 市，这样总费用就是最小的。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 为数组 `costs` 的长度。

相似题目：

-   [2611. 老鼠和奶酪](https://github.com/doocs/leetcode/blob/main/solution/2600-2699/2611.Mice%20and%20Cheese/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def twoCitySchedCost(self, costs: List[List[int]]) -> int:
        costs.sort(key=lambda x: x[0] - x[1])
        n = len(costs) >> 1
        return sum(costs[i][0] + costs[i + n][1] for i in range(n))
```

#### Java

```java
class Solution {
    public int twoCitySchedCost(int[][] costs) {
        Arrays.sort(costs, (a, b) -> { return a[0] - a[1] - (b[0] - b[1]); });
        int ans = 0;
        int n = costs.length >> 1;
        for (int i = 0; i < n; ++i) {
            ans += costs[i][0] + costs[i + n][1];
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] - a[1] < b[0] - b[1];
        });
        int n = costs.size() / 2;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += costs[i][0] + costs[i + n][1];
        }
        return ans;
    }
};
```

#### Go

```go
func twoCitySchedCost(costs [][]int) (ans int) {
	sort.Slice(costs, func(i, j int) bool {
		return costs[i][0]-costs[i][1] < costs[j][0]-costs[j][1]
	})
	n := len(costs) >> 1
	for i, a := range costs[:n] {
		ans += a[0] + costs[i+n][1]
	}
	return
}
```

#### TypeScript

```ts
function twoCitySchedCost(costs: number[][]): number {
    costs.sort((a, b) => a[0] - a[1] - (b[0] - b[1]));
    const n = costs.length >> 1;
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        ans += costs[i][0] + costs[i + n][1];
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
