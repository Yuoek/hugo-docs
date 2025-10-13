---
title: "0980_不同路径 III"
date: 2025-10-08T18:36:43+08:00
weight: 9
tags: [二分查找, 二叉树, 位运算, 动态规划, 双指针, 哈希表, 回溯, 字符串, 广度优先搜索, 扫描线, 排序, 数学, 数组, 树, 模拟, 深度优先搜索, 矩阵, 设计, 贪心]
---

{{< markmap >}}
### [0980_不同路径 III](#980)
#### [位运算](#980)
#### [数组](#980)
#### [回溯](#980)
#### [矩阵](#980)
### [0981_基于时间的键值存储](#981)
#### [设计](#981)
#### [哈希表](#981)
#### [字符串](#981)
#### [二分查找](#981)
### [0982_按位与为零的三元组](#982)
#### [位运算](#982)
#### [数组](#982)
#### [哈希表](#982)
### [0983_最低票价](#983)
#### [数组](#983)
#### [动态规划](#983)
### [0984_不含 AAA 或 BBB 的字符串](#984)
#### [贪心](#984)
#### [字符串](#984)
### [0985_查询后的偶数和](#985)
#### [数组](#985)
#### [模拟](#985)
### [0986_区间列表的交集](#986)
#### [数组](#986)
#### [双指针](#986)
#### [扫描线](#986)
### [0987_二叉树的垂序遍历](#987)
#### [树](#987)
#### [深度优先搜索](#987)
#### [广度优先搜索](#987)
#### [哈希表](#987)
#### [二叉树](#987)
#### [排序](#987)
### [0988_从叶结点开始的最小字符串](#988)
#### [树](#988)
#### [深度优先搜索](#988)
#### [字符串](#988)
#### [回溯](#988)
#### [二叉树](#988)
### [0989_数组形式的整数加法](#989)
#### [数组](#989)
#### [数学](#989)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0980_不同路径 III
___
#### 位运算
___
#### 数组
___
#### 回溯
___
#### 矩阵
---
### 0981_基于时间的键值存储
___
#### 设计
___
#### 哈希表
___
#### 字符串
___
#### 二分查找
---
### 0982_按位与为零的三元组
___
#### 位运算
___
#### 数组
___
#### 哈希表
---
### 0983_最低票价
___
#### 数组
___
#### 动态规划
---
### 0984_不含 AAA 或 BBB 的字符串
___
#### 贪心
___
#### 字符串
---
### 0985_查询后的偶数和
___
#### 数组
___
#### 模拟
---
### 0986_区间列表的交集
___
#### 数组
___
#### 双指针
___
#### 扫描线
---
### 0987_二叉树的垂序遍历
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
### 0988_从叶结点开始的最小字符串
___
#### 树
___
#### 深度优先搜索
___
#### 字符串
___
#### 回溯
___
#### 二叉树
---
### 0989_数组形式的整数加法
___
#### 数组
___
#### 数学
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 二叉树 | 位运算 |
| 动态规划 | 双指针 | 哈希表 |
| 回溯 | 字符串 | 广度优先搜索 |
| 扫描线 | 排序 | 数学 |
| 数组 | 树 | 模拟 |
| 深度优先搜索 | 矩阵 | 设计 |
| 贪心 |  |  |

# [980. 不同路径 III](https://leetcode.cn/problems/unique-paths-iii){#980}

{{< tabs "980" >}}

{{% tab "python" %}}
```python
class Solution:
    def uniquePathsIII(self, grid: List[List[int]]) -> int:
        def dfs(i: int, j: int, k: int) -> int:
            if grid[i][j] == 2:
                return int(k == cnt + 1)
            ans = 0
            for a, b in pairwise(dirs):
                x, y = i + a, j + b
                if 0 <= x < m and 0 <= y < n and (x, y) not in vis and grid[x][y] != -1:
                    vis.add((x, y))
                    ans += dfs(x, y, k + 1)
                    vis.remove((x, y))
            return ans

        m, n = len(grid), len(grid[0])
        start = next((i, j) for i in range(m) for j in range(n) if grid[i][j] == 1)
        dirs = (-1, 0, 1, 0, -1)
        cnt = sum(row.count(0) for row in grid)
        vis = {start}
        return dfs(*start, 0)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int m;
    private int n;
    private int cnt;
    private int[][] grid;
    private boolean[][] vis;

    public int uniquePathsIII(int[][] grid) {
        m = grid.length;
        n = grid[0].length;
        this.grid = grid;
        int x = 0, y = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    ++cnt;
                } else if (grid[i][j] == 1) {
                    x = i;
                    y = j;
                }
            }
        }
        vis = new boolean[m][n];
        vis[x][y] = true;
        return dfs(x, y, 0);
    }

    private int dfs(int i, int j, int k) {
        if (grid[i][j] == 2) {
            return k == cnt + 1 ? 1 : 0;
        }
        int ans = 0;
        int[] dirs = {-1, 0, 1, 0, -1};
        for (int h = 0; h < 4; ++h) {
            int x = i + dirs[h], y = j + dirs[h + 1];
            if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && grid[x][y] != -1) {
                vis[x][y] = true;
                ans += dfs(x, y, k + 1);
                vis[x][y] = false;
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
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int cnt = 0;
        for (auto& row : grid) {
            for (auto& x : row) {
                cnt += x == 0;
            }
        }
        int dirs[5] = {-1, 0, 1, 0, -1};
        bool vis[m][n];
        memset(vis, false, sizeof vis);
        function<int(int, int, int)> dfs = [&](int i, int j, int k) -> int {
            if (grid[i][j] == 2) {
                return k == cnt + 1 ? 1 : 0;
            }
            int ans = 0;
            for (int h = 0; h < 4; ++h) {
                int x = i + dirs[h], y = j + dirs[h + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && grid[x][y] != -1) {
                    vis[x][y] = true;
                    ans += dfs(x, y, k + 1);
                    vis[x][y] = false;
                }
            }
            return ans;
        };
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    vis[i][j] = true;
                    return dfs(i, j, 0);
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
func uniquePathsIII(grid [][]int) int {
	m, n := len(grid), len(grid[0])
	cnt := 0
	vis := make([][]bool, m)
	x, y := 0, 0
	for i, row := range grid {
		vis[i] = make([]bool, n)
		for j, v := range row {
			if v == 0 {
				cnt++
			} else if v == 1 {
				x, y = i, j
			}
		}
	}
	dirs := [5]int{-1, 0, 1, 0, -1}
	var dfs func(i, j, k int) int
	dfs = func(i, j, k int) int {
		if grid[i][j] == 2 {
			if k == cnt+1 {
				return 1
			}
			return 0
		}
		ans := 0
		for h := 0; h < 4; h++ {
			x, y := i+dirs[h], j+dirs[h+1]
			if x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && grid[x][y] != -1 {
				vis[x][y] = true
				ans += dfs(x, y, k+1)
				vis[x][y] = false
			}
		}
		return ans
	}
	vis[x][y] = true
	return dfs(x, y, 0)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function uniquePathsIII(grid: number[][]): number {
    const m = grid.length;
    const n = grid[0].length;
    let [x, y] = [0, 0];
    let cnt = 0;
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            if (grid[i][j] === 0) {
                ++cnt;
            } else if (grid[i][j] == 1) {
                [x, y] = [i, j];
            }
        }
    }
    const vis: boolean[][] = Array.from({ length: m }, () => Array(n).fill(false));
    vis[x][y] = true;
    const dirs = [-1, 0, 1, 0, -1];
    const dfs = (i: number, j: number, k: number): number => {
        if (grid[i][j] === 2) {
            return k === cnt + 1 ? 1 : 0;
        }
        let ans = 0;
        for (let d = 0; d < 4; ++d) {
            const [x, y] = [i + dirs[d], j + dirs[d + 1]];
            if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && grid[x][y] !== -1) {
                vis[x][y] = true;
                ans += dfs(x, y, k + 1);
                vis[x][y] = false;
            }
        }
        return ans;
    };
    return dfs(x, y, 0);
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[][]} grid
 * @return {number}
 */
var uniquePathsIII = function (grid) {
    const m = grid.length;
    const n = grid[0].length;
    let [x, y] = [0, 0];
    let cnt = 0;
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            if (grid[i][j] === 0) {
                ++cnt;
            } else if (grid[i][j] === 1) {
                [x, y] = [i, j];
            }
        }
    }
    const vis = Array.from({ length: m }, () => Array(n).fill(false));
    vis[x][y] = true;
    const dirs = [-1, 0, 1, 0, -1];
    const dfs = function (i, j, k) {
        if (grid[i][j] === 2) {
            return k === cnt + 1 ? 1 : 0;
        }
        let ans = 0;
        for (let d = 0; d < 4; ++d) {
            const x = i + dirs[d];
            const y = j + dirs[d + 1];
            if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && grid[x][y] !== -1) {
                vis[x][y] = true;
                ans += dfs(x, y, k + 1);
                vis[x][y] = false;
            }
        }
        return ans;
    };
    return dfs(x, y, 0);
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>在二维网格 <code>grid</code> 上，有 4 种类型的方格：</p>

<ul>
	<li><code>1</code> 表示起始方格。且只有一个起始方格。</li>
	<li><code>2</code> 表示结束方格，且只有一个结束方格。</li>
	<li><code>0</code> 表示我们可以走过的空方格。</li>
	<li><code>-1</code> 表示我们无法跨越的障碍。</li>
</ul>

<p>返回在四个方向（上、下、左、右）上行走时，从起始方格到结束方格的不同路径的数目<strong>。</strong></p>

<p><strong>每一个无障碍方格都要通过一次，但是一条路径中不能重复通过同一个方格</strong>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>[[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
<strong>输出：</strong>2
<strong>解释：</strong>我们有以下两条路径：
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>[[1,0,0,0],[0,0,0,0],[0,0,0,2]]
<strong>输出：</strong>4
<strong>解释：</strong>我们有以下四条路径： 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>[[0,1],[2,0]]
<strong>输出：</strong>0
<strong>解释：</strong>
没有一条路能完全穿过每一个空的方格一次。
请注意，起始和结束方格可以位于网格中的任意位置。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= grid.length * grid[0].length &lt;= 20</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：回溯

我们可以先遍历整个网格，找出起点 $(x, y)$，并且统计空白格的数量 $cnt$。

接下来，我们可以从起点开始搜索，得到所有的路径数。我们设计一个函数 $dfs(i, j, k)$ 表示从 $(i, j)$ 出发，且当前已经走过的单元格数量为 $k$ 的路径数。

在函数中，我们首先判断当前单元格是否为终点，如果是，则判断 $k$ 是否等于 $cnt + 1$，如果是，则说明当前路径是一条有效路径，返回 $1$，否则返回 $0$。

如果当前单元格不是终点，则我们枚举当前单元格的上下左右四个邻接单元格，如果邻接单元格未被访问过，则我们将该邻接单元格标记为已访问，然后继续搜索从该邻接单元格出发的路径数，搜索完成后，我们再将该邻接单元格标记为未访问。在搜索完成后，我们返回所有邻接单元格的路径数之和。

最后，我们返回从起点出发的路径数即可，即 $dfs(x, y, 1)$。

时间复杂度 $O(3^{m \times n})$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别为网格的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def uniquePathsIII(self, grid: List[List[int]]) -> int:
        def dfs(i: int, j: int, k: int) -> int:
            if grid[i][j] == 2:
                return int(k == cnt + 1)
            ans = 0
            for a, b in pairwise(dirs):
                x, y = i + a, j + b
                if 0 <= x < m and 0 <= y < n and (x, y) not in vis and grid[x][y] != -1:
                    vis.add((x, y))
                    ans += dfs(x, y, k + 1)
                    vis.remove((x, y))
            return ans

        m, n = len(grid), len(grid[0])
        start = next((i, j) for i in range(m) for j in range(n) if grid[i][j] == 1)
        dirs = (-1, 0, 1, 0, -1)
        cnt = sum(row.count(0) for row in grid)
        vis = {start}
        return dfs(*start, 0)
```

#### Java

```java
class Solution {
    private int m;
    private int n;
    private int cnt;
    private int[][] grid;
    private boolean[][] vis;

    public int uniquePathsIII(int[][] grid) {
        m = grid.length;
        n = grid[0].length;
        this.grid = grid;
        int x = 0, y = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    ++cnt;
                } else if (grid[i][j] == 1) {
                    x = i;
                    y = j;
                }
            }
        }
        vis = new boolean[m][n];
        vis[x][y] = true;
        return dfs(x, y, 0);
    }

    private int dfs(int i, int j, int k) {
        if (grid[i][j] == 2) {
            return k == cnt + 1 ? 1 : 0;
        }
        int ans = 0;
        int[] dirs = {-1, 0, 1, 0, -1};
        for (int h = 0; h < 4; ++h) {
            int x = i + dirs[h], y = j + dirs[h + 1];
            if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && grid[x][y] != -1) {
                vis[x][y] = true;
                ans += dfs(x, y, k + 1);
                vis[x][y] = false;
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
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int cnt = 0;
        for (auto& row : grid) {
            for (auto& x : row) {
                cnt += x == 0;
            }
        }
        int dirs[5] = {-1, 0, 1, 0, -1};
        bool vis[m][n];
        memset(vis, false, sizeof vis);
        function<int(int, int, int)> dfs = [&](int i, int j, int k) -> int {
            if (grid[i][j] == 2) {
                return k == cnt + 1 ? 1 : 0;
            }
            int ans = 0;
            for (int h = 0; h < 4; ++h) {
                int x = i + dirs[h], y = j + dirs[h + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && grid[x][y] != -1) {
                    vis[x][y] = true;
                    ans += dfs(x, y, k + 1);
                    vis[x][y] = false;
                }
            }
            return ans;
        };
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    vis[i][j] = true;
                    return dfs(i, j, 0);
                }
            }
        }
        return 0;
    }
};
```

#### Go

```go
func uniquePathsIII(grid [][]int) int {
	m, n := len(grid), len(grid[0])
	cnt := 0
	vis := make([][]bool, m)
	x, y := 0, 0
	for i, row := range grid {
		vis[i] = make([]bool, n)
		for j, v := range row {
			if v == 0 {
				cnt++
			} else if v == 1 {
				x, y = i, j
			}
		}
	}
	dirs := [5]int{-1, 0, 1, 0, -1}
	var dfs func(i, j, k int) int
	dfs = func(i, j, k int) int {
		if grid[i][j] == 2 {
			if k == cnt+1 {
				return 1
			}
			return 0
		}
		ans := 0
		for h := 0; h < 4; h++ {
			x, y := i+dirs[h], j+dirs[h+1]
			if x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && grid[x][y] != -1 {
				vis[x][y] = true
				ans += dfs(x, y, k+1)
				vis[x][y] = false
			}
		}
		return ans
	}
	vis[x][y] = true
	return dfs(x, y, 0)
}
```

#### TypeScript

```ts
function uniquePathsIII(grid: number[][]): number {
    const m = grid.length;
    const n = grid[0].length;
    let [x, y] = [0, 0];
    let cnt = 0;
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            if (grid[i][j] === 0) {
                ++cnt;
            } else if (grid[i][j] == 1) {
                [x, y] = [i, j];
            }
        }
    }
    const vis: boolean[][] = Array.from({ length: m }, () => Array(n).fill(false));
    vis[x][y] = true;
    const dirs = [-1, 0, 1, 0, -1];
    const dfs = (i: number, j: number, k: number): number => {
        if (grid[i][j] === 2) {
            return k === cnt + 1 ? 1 : 0;
        }
        let ans = 0;
        for (let d = 0; d < 4; ++d) {
            const [x, y] = [i + dirs[d], j + dirs[d + 1]];
            if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && grid[x][y] !== -1) {
                vis[x][y] = true;
                ans += dfs(x, y, k + 1);
                vis[x][y] = false;
            }
        }
        return ans;
    };
    return dfs(x, y, 0);
}
```

#### JavaScript

```js
/**
 * @param {number[][]} grid
 * @return {number}
 */
var uniquePathsIII = function (grid) {
    const m = grid.length;
    const n = grid[0].length;
    let [x, y] = [0, 0];
    let cnt = 0;
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            if (grid[i][j] === 0) {
                ++cnt;
            } else if (grid[i][j] === 1) {
                [x, y] = [i, j];
            }
        }
    }
    const vis = Array.from({ length: m }, () => Array(n).fill(false));
    vis[x][y] = true;
    const dirs = [-1, 0, 1, 0, -1];
    const dfs = function (i, j, k) {
        if (grid[i][j] === 2) {
            return k === cnt + 1 ? 1 : 0;
        }
        let ans = 0;
        for (let d = 0; d < 4; ++d) {
            const x = i + dirs[d];
            const y = j + dirs[d + 1];
            if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && grid[x][y] !== -1) {
                vis[x][y] = true;
                ans += dfs(x, y, k + 1);
                vis[x][y] = false;
            }
        }
        return ans;
    };
    return dfs(x, y, 0);
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [981. 基于时间的键值存储](https://leetcode.cn/problems/time-based-key-value-store){#981}

{{< tabs "981" >}}

{{% tab "python" %}}
```python
class TimeMap:
    def __init__(self):
        self.ktv = defaultdict(list)

    def set(self, key: str, value: str, timestamp: int) -> None:
        self.ktv[key].append((timestamp, value))

    def get(self, key: str, timestamp: int) -> str:
        if key not in self.ktv:
            return ''
        tv = self.ktv[key]
        i = bisect_right(tv, (timestamp, chr(127)))
        return tv[i - 1][1] if i else ''


# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class TimeMap {
    private Map<String, TreeMap<Integer, String>> ktv = new HashMap<>();

    public TimeMap() {
    }

    public void set(String key, String value, int timestamp) {
        ktv.computeIfAbsent(key, k -> new TreeMap<>()).put(timestamp, value);
    }

    public String get(String key, int timestamp) {
        if (!ktv.containsKey(key)) {
            return "";
        }
        var tv = ktv.get(key);
        Integer t = tv.floorKey(timestamp);
        return t == null ? "" : tv.get(t);
    }
}

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap obj = new TimeMap();
 * obj.set(key,value,timestamp);
 * String param_2 = obj.get(key,timestamp);
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class TimeMap {
public:
    TimeMap() {
    }

    void set(string key, string value, int timestamp) {
        ktv[key].emplace_back(timestamp, value);
    }

    string get(string key, int timestamp) {
        auto& pairs = ktv[key];
        pair<int, string> p = {timestamp, string({127})};
        auto i = upper_bound(pairs.begin(), pairs.end(), p);
        return i == pairs.begin() ? "" : (i - 1)->second;
    }

private:
    unordered_map<string, vector<pair<int, string>>> ktv;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type TimeMap struct {
	ktv map[string][]pair
}

func Constructor() TimeMap {
	return TimeMap{map[string][]pair{}}
}

func (this *TimeMap) Set(key string, value string, timestamp int) {
	this.ktv[key] = append(this.ktv[key], pair{timestamp, value})
}

func (this *TimeMap) Get(key string, timestamp int) string {
	pairs := this.ktv[key]
	i := sort.Search(len(pairs), func(i int) bool { return pairs[i].t > timestamp })
	if i > 0 {
		return pairs[i-1].v
	}
	return ""
}

type pair struct {
	t int
	v string
}

/**
 * Your TimeMap object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Set(key,value,timestamp);
 * param_2 := obj.Get(key,timestamp);
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>设计一个基于时间的键值数据结构，该结构可以在不同时间戳存储对应同一个键的多个值，并针对特定时间戳检索键对应的值。</p>

<p>实现 <code>TimeMap</code> 类：</p>

<ul>
	<li><code>TimeMap()</code> 初始化数据结构对象</li>
	<li><code>void set(String key, String value, int timestamp)</code> 存储给定时间戳&nbsp;<code>timestamp</code>&nbsp;时的键&nbsp;<code>key</code>&nbsp;和值&nbsp;<code>value</code>。</li>
	<li><code>String get(String key, int timestamp)</code>&nbsp;返回一个值，该值在之前调用了 <code>set</code>，其中&nbsp;<code>timestamp_prev &lt;= timestamp</code>&nbsp;。如果有多个这样的值，它将返回与最大 &nbsp;<code>timestamp_prev</code>&nbsp;关联的值。如果没有值，则返回空字符串（<code>""</code>）。</li>
</ul>
&nbsp;

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
["TimeMap", "set", "get", "get", "set", "get", "get"]
[[], ["foo", "bar", 1], ["foo", 1], ["foo", 3], ["foo", "bar2", 4], ["foo", 4], ["foo", 5]]
<strong>输出：</strong>
[null, null, "bar", "bar", null, "bar2", "bar2"]

<strong>解释：</strong>
TimeMap timeMap = new TimeMap();
timeMap.set("foo", "bar", 1);  // 存储键 "foo" 和值 "bar" ，时间戳 timestamp = 1 &nbsp; 
timeMap.get("foo", 1);         // 返回 "bar"
timeMap.get("foo", 3);         // 返回 "bar", 因为在时间戳 3 和时间戳 2 处没有对应 "foo" 的值，所以唯一的值位于时间戳 1 处（即 "bar"） 。
timeMap.set("foo", "bar2", 4); // 存储键 "foo" 和值 "bar2" ，时间戳 timestamp = 4&nbsp; 
timeMap.get("foo", 4);         // 返回 "bar2"
timeMap.get("foo", 5);         // 返回 "bar2"
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= key.length, value.length &lt;= 100</code></li>
	<li><code>key</code> 和 <code>value</code> 由小写英文字母和数字组成</li>
	<li><code>1 &lt;= timestamp &lt;= 10<sup>7</sup></code></li>
	<li><code>set</code> 操作中的时间戳 <code>timestamp</code> 都是严格递增的</li>
	<li>最多调用&nbsp;<code>set</code> 和 <code>get</code> 操作 <code>2 * 10<sup>5</sup></code> 次</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 有序集合（或二分查找）

我们可以用哈希表 $\textit{kvt}$ 记录键值对，其中键为字符串 $\textit{key}$，值为一个有序集合，集合中的每个元素为一个二元组 $(\textit{timestamp}, \textit{value})$，表示键 $\textit{key}$ 在时间戳 $\textit{timestamp}$ 时对应的值为 $\textit{value}$。

当我们需要查询键 $\textit{key}$ 在时间戳 $\textit{timestamp}$ 时对应的值时，我们可以通过有序集合的方法找到最大的时间戳 $\textit{timestamp}'$，使得 $\textit{timestamp}' \leq \textit{timestamp}$，然后返回对应的值即可。

时间复杂度方面，对于 $\textit{set}$ 操作，由于哈希表的插入操作的时间复杂度为 $O(1)$，因此时间复杂度为 $O(1)$。对于 $\textit{get}$ 操作，由于哈希表的查找操作的时间复杂度为 $O(1)$，而有序集合的查找操作的时间复杂度为 $O(\log n)$，因此时间复杂度为 $O(\log n)$。空间复杂度为 $O(n)$，其中 $n$ 为 $\textit{set}$ 操作的次数。

<!-- tabs:start -->

#### Python3

```python
class TimeMap:
    def __init__(self):
        self.ktv = defaultdict(list)

    def set(self, key: str, value: str, timestamp: int) -> None:
        self.ktv[key].append((timestamp, value))

    def get(self, key: str, timestamp: int) -> str:
        if key not in self.ktv:
            return ''
        tv = self.ktv[key]
        i = bisect_right(tv, (timestamp, chr(127)))
        return tv[i - 1][1] if i else ''


# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)
```

#### Java

```java
class TimeMap {
    private Map<String, TreeMap<Integer, String>> ktv = new HashMap<>();

    public TimeMap() {
    }

    public void set(String key, String value, int timestamp) {
        ktv.computeIfAbsent(key, k -> new TreeMap<>()).put(timestamp, value);
    }

    public String get(String key, int timestamp) {
        if (!ktv.containsKey(key)) {
            return "";
        }
        var tv = ktv.get(key);
        Integer t = tv.floorKey(timestamp);
        return t == null ? "" : tv.get(t);
    }
}

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap obj = new TimeMap();
 * obj.set(key,value,timestamp);
 * String param_2 = obj.get(key,timestamp);
 */
```

#### C++

```cpp
class TimeMap {
public:
    TimeMap() {
    }

    void set(string key, string value, int timestamp) {
        ktv[key].emplace_back(timestamp, value);
    }

    string get(string key, int timestamp) {
        auto& pairs = ktv[key];
        pair<int, string> p = {timestamp, string({127})};
        auto i = upper_bound(pairs.begin(), pairs.end(), p);
        return i == pairs.begin() ? "" : (i - 1)->second;
    }

private:
    unordered_map<string, vector<pair<int, string>>> ktv;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
```

#### Go

```go
type TimeMap struct {
	ktv map[string][]pair
}

func Constructor() TimeMap {
	return TimeMap{map[string][]pair{}}
}

func (this *TimeMap) Set(key string, value string, timestamp int) {
	this.ktv[key] = append(this.ktv[key], pair{timestamp, value})
}

func (this *TimeMap) Get(key string, timestamp int) string {
	pairs := this.ktv[key]
	i := sort.Search(len(pairs), func(i int) bool { return pairs[i].t > timestamp })
	if i > 0 {
		return pairs[i-1].v
	}
	return ""
}

type pair struct {
	t int
	v string
}

/**
 * Your TimeMap object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Set(key,value,timestamp);
 * param_2 := obj.Get(key,timestamp);
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [982. 按位与为零的三元组](https://leetcode.cn/problems/triples-with-bitwise-and-equal-to-zero){#982}

{{< tabs "982" >}}

{{% tab "python" %}}
```python
class Solution:
    def countTriplets(self, nums: List[int]) -> int:
        cnt = Counter(x & y for x in nums for y in nums)
        return sum(v for xy, v in cnt.items() for z in nums if xy & z == 0)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countTriplets(int[] nums) {
        int mx = 0;
        for (int x : nums) {
            mx = Math.max(mx, x);
        }
        int[] cnt = new int[mx + 1];
        for (int x : nums) {
            for (int y : nums) {
                cnt[x & y]++;
            }
        }
        int ans = 0;
        for (int xy = 0; xy <= mx; ++xy) {
            for (int z : nums) {
                if ((xy & z) == 0) {
                    ans += cnt[xy];
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
    int countTriplets(vector<int>& nums) {
        int mx = ranges::max(nums);
        int cnt[mx + 1];
        memset(cnt, 0, sizeof cnt);
        for (int& x : nums) {
            for (int& y : nums) {
                cnt[x & y]++;
            }
        }
        int ans = 0;
        for (int xy = 0; xy <= mx; ++xy) {
            for (int& z : nums) {
                if ((xy & z) == 0) {
                    ans += cnt[xy];
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
func countTriplets(nums []int) (ans int) {
	mx := slices.Max(nums)
	cnt := make([]int, mx+1)
	for _, x := range nums {
		for _, y := range nums {
			cnt[x&y]++
		}
	}
	for xy := 0; xy <= mx; xy++ {
		for _, z := range nums {
			if xy&z == 0 {
				ans += cnt[xy]
			}
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countTriplets(nums: number[]): number {
    const mx = Math.max(...nums);
    const cnt: number[] = Array(mx + 1).fill(0);
    for (const x of nums) {
        for (const y of nums) {
            cnt[x & y]++;
        }
    }
    let ans = 0;
    for (let xy = 0; xy <= mx; ++xy) {
        for (const z of nums) {
            if ((xy & z) === 0) {
                ans += cnt[xy];
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

<p>给你一个整数数组 <code>nums</code> ，返回其中 <strong>按位与三元组</strong> 的数目。</p>

<p><strong>按位与三元组</strong> 是由下标 <code>(i, j, k)</code> 组成的三元组，并满足下述全部条件：</p>

<ul>
	<li><code>0 &lt;= i &lt; nums.length</code></li>
	<li><code>0 &lt;= j &lt; nums.length</code></li>
	<li><code>0 &lt;= k &lt; nums.length</code></li>
	<li><code>nums[i] &amp; nums[j] &amp; nums[k] == 0</code> ，其中 <code>&amp;</code> 表示按位与运算符。</li>
</ul>
&nbsp;

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,1,3]
<strong>输出：</strong>12
<strong>解释：</strong>可以选出如下 i, j, k 三元组：
(i=0, j=0, k=1) : 2 &amp; 2 &amp; 1
(i=0, j=1, k=0) : 2 &amp; 1 &amp; 2
(i=0, j=1, k=1) : 2 &amp; 1 &amp; 1
(i=0, j=1, k=2) : 2 &amp; 1 &amp; 3
(i=0, j=2, k=1) : 2 &amp; 3 &amp; 1
(i=1, j=0, k=0) : 1 &amp; 2 &amp; 2
(i=1, j=0, k=1) : 1 &amp; 2 &amp; 1
(i=1, j=0, k=2) : 1 &amp; 2 &amp; 3
(i=1, j=1, k=0) : 1 &amp; 1 &amp; 2
(i=1, j=2, k=0) : 1 &amp; 3 &amp; 2
(i=2, j=0, k=1) : 3 &amp; 2 &amp; 1
(i=2, j=1, k=0) : 3 &amp; 1 &amp; 2
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [0,0,0]
<strong>输出：</strong>27
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>0 &lt;= nums[i] &lt; 2<sup>16</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举 + 计数

我们可以先枚举任意两个数 $x$ 和 $y$，用哈希表或数组 $cnt$ 统计它们的按位与结果 $x \& y$ 出现的次数。

然后我们枚举 $x$ 和 $y$ 的按位与结果 $xy$，再枚举 $z$，如果 $xy \& z = 0$，则将 $cnt[xy]$ 的值加入答案。

最后返回答案即可。

时间复杂度 $O(n^2 + n \times M)$，空间复杂度 $O(M)$，其中 $n$ 是数组 $nums$ 的长度；而 $M$ 是数组 $nums$ 中的最大值，本题中 $M \leq 2^{16}$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countTriplets(self, nums: List[int]) -> int:
        cnt = Counter(x & y for x in nums for y in nums)
        return sum(v for xy, v in cnt.items() for z in nums if xy & z == 0)
```

#### Java

```java
class Solution {
    public int countTriplets(int[] nums) {
        int mx = 0;
        for (int x : nums) {
            mx = Math.max(mx, x);
        }
        int[] cnt = new int[mx + 1];
        for (int x : nums) {
            for (int y : nums) {
                cnt[x & y]++;
            }
        }
        int ans = 0;
        for (int xy = 0; xy <= mx; ++xy) {
            for (int z : nums) {
                if ((xy & z) == 0) {
                    ans += cnt[xy];
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
    int countTriplets(vector<int>& nums) {
        int mx = ranges::max(nums);
        int cnt[mx + 1];
        memset(cnt, 0, sizeof cnt);
        for (int& x : nums) {
            for (int& y : nums) {
                cnt[x & y]++;
            }
        }
        int ans = 0;
        for (int xy = 0; xy <= mx; ++xy) {
            for (int& z : nums) {
                if ((xy & z) == 0) {
                    ans += cnt[xy];
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func countTriplets(nums []int) (ans int) {
	mx := slices.Max(nums)
	cnt := make([]int, mx+1)
	for _, x := range nums {
		for _, y := range nums {
			cnt[x&y]++
		}
	}
	for xy := 0; xy <= mx; xy++ {
		for _, z := range nums {
			if xy&z == 0 {
				ans += cnt[xy]
			}
		}
	}
	return
}
```

#### TypeScript

```ts
function countTriplets(nums: number[]): number {
    const mx = Math.max(...nums);
    const cnt: number[] = Array(mx + 1).fill(0);
    for (const x of nums) {
        for (const y of nums) {
            cnt[x & y]++;
        }
    }
    let ans = 0;
    for (let xy = 0; xy <= mx; ++xy) {
        for (const z of nums) {
            if ((xy & z) === 0) {
                ans += cnt[xy];
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

# [983. 最低票价](https://leetcode.cn/problems/minimum-cost-for-tickets){#983}

{{< tabs "983" >}}

{{% tab "python" %}}
```python
class Solution:
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        m = days[-1]
        f = [0] * (m + 1)
        valid = [1, 7, 30]
        j = 0
        for i in range(1, m + 1):
            if i == days[j]:
                f[i] = inf
                for c, v in zip(costs, valid):
                    f[i] = min(f[i], f[max(0, i - v)] + c)
                j += 1
            else:
                f[i] = f[i - 1]
        return f[m]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int mincostTickets(int[] days, int[] costs) {
        int m = days[days.length - 1];
        int[] f = new int[m + 1];
        final int[] valid = {1, 7, 30};
        for (int i = 1, j = 0; i <= m; ++i) {
            if (i == days[j]) {
                f[i] = Integer.MAX_VALUE;
                for (int k = 0; k < 3; ++k) {
                    int c = costs[k], v = valid[k];
                    f[i] = Math.min(f[i], f[Math.max(0, i - v)] + c);
                }
                ++j;
            } else {
                f[i] = f[i - 1];
            }
        }
        return f[m];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int m = days.back();
        int f[m + 1];
        f[0] = 0;
        int valid[3] = {1, 7, 30};
        for (int i = 1, j = 0; i <= m; ++i) {
            if (i == days[j]) {
                f[i] = INT_MAX;
                for (int k = 0; k < 3; ++k) {
                    int c = costs[k], v = valid[k];
                    f[i] = min(f[i], f[max(0, i - v)] + c);
                }
                ++j;
            } else {
                f[i] = f[i - 1];
            }
        }
        return f[m];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func mincostTickets(days []int, costs []int) int {
	m := days[len(days)-1]
	f := make([]int, m+1)
	valid := [3]int{1, 7, 30}
	for i, j := 1, 0; i <= m; i++ {
		if i == days[j] {
			f[i] = 1 << 30
			for k, v := range valid {
				c := costs[k]
				f[i] = min(f[i], f[max(0, i-v)]+c)
			}
			j++
		} else {
			f[i] = f[i-1]
		}
	}
	return f[m]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function mincostTickets(days: number[], costs: number[]): number {
    const m = days.at(-1)!;
    const f: number[] = Array(m).fill(0);
    const valid: number[] = [1, 7, 30];
    for (let i = 1, j = 0; i <= m; ++i) {
        if (i === days[j]) {
            f[i] = Infinity;
            for (let k = 0; k < 3; ++k) {
                const [c, v] = [costs[k], valid[k]];
                f[i] = Math.min(f[i], f[Math.max(0, i - v)] + c);
            }
            ++j;
        } else {
            f[i] = f[i - 1];
        }
    }
    return f[m];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>在一个火车旅行很受欢迎的国度，你提前一年计划了一些火车旅行。在接下来的一年里，你要旅行的日子将以一个名为&nbsp;<code>days</code>&nbsp;的数组给出。每一项是一个从&nbsp;<code>1</code>&nbsp;到&nbsp;<code>365</code>&nbsp;的整数。</p>

<p>火车票有 <strong>三种不同的销售方式</strong> ：</p>

<ul>
	<li>一张 <strong>为期一天</strong> 的通行证售价为&nbsp;<code>costs[0]</code> 美元；</li>
	<li>一张 <strong>为期七天</strong> 的通行证售价为&nbsp;<code>costs[1]</code> 美元；</li>
	<li>一张 <strong>为期三十天</strong> 的通行证售价为&nbsp;<code>costs[2]</code> 美元。</li>
</ul>

<p>通行证允许数天无限制的旅行。 例如，如果我们在第 <code>2</code> 天获得一张 <strong>为期 7 天</strong> 的通行证，那么我们可以连着旅行 7 天：第 <code>2</code> 天、第 <code>3</code> 天、第 <code>4</code> 天、第 <code>5</code> 天、第 <code>6</code> 天、第 <code>7</code> 天和第 <code>8</code> 天。</p>

<p>返回 <em>你想要完成在给定的列表&nbsp;<code>days</code>&nbsp;中列出的每一天的旅行所需要的最低消费&nbsp;</em>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>days = [1,4,6,7,8,20], costs = [2,7,15]
<strong>输出：</strong>11
<strong>解释： </strong>
例如，这里有一种购买通行证的方法，可以让你完成你的旅行计划：
在第 1 天，你花了 costs[0] = $2 买了一张为期 1 天的通行证，它将在第 1 天生效。
在第 3 天，你花了 costs[1] = $7 买了一张为期 7 天的通行证，它将在第 3, 4, ..., 9 天生效。
在第 20 天，你花了 costs[0] = $2 买了一张为期 1 天的通行证，它将在第 20 天生效。
你总共花了 $11，并完成了你计划的每一天旅行。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>days = [1,2,3,4,5,6,7,8,9,10,30,31], costs = [2,7,15]
<strong>输出：</strong>17
<strong>解释：
</strong>例如，这里有一种购买通行证的方法，可以让你完成你的旅行计划： 
在第 1 天，你花了 costs[2] = $15 买了一张为期 30 天的通行证，它将在第 1, 2, ..., 30 天生效。
在第 31 天，你花了 costs[0] = $2 买了一张为期 1 天的通行证，它将在第 31 天生效。 
你总共花了 $17，并完成了你计划的每一天旅行。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= days.length &lt;= 365</code></li>
	<li><code>1 &lt;= days[i] &lt;= 365</code></li>
	<li><code>days</code>&nbsp;按顺序严格递增</li>
	<li><code>costs.length == 3</code></li>
	<li><code>1 &lt;= costs[i] &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索 + 二分查找

我们定义一个函数 $\textit{dfs(i)}$，表示从第 $i$ 次出行开始到最后一次出行结束所需的最小花费。那么答案为 $\textit{dfs(0)}$。

函数 $\textit{dfs(i)}$ 的执行过程如下：

-   如果 $i \geq n$，表示所有出行已经结束，返回 $0$；
-   否则，我们需要考虑三种购买方式，分别是购买 $1$ 天通行证、购买 $7$ 天通行证和购买 $30$ 天通行证。我们分别计算这三种购买方式的花费，并且利用二分查找，找到下一次出行的下标 $j$，然后递归调用 $\textit{dfs(j)}$，最后返回这三种购买方式的最小花费。

为了避免重复计算，我们使用记忆化搜索，将已经计算过的结果保存起来。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 表示出行的次数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        @cache
        def dfs(i: int) -> int:
            if i >= n:
                return 0
            ans = inf
            for c, v in zip(costs, valid):
                j = bisect_left(days, days[i] + v)
                ans = min(ans, c + dfs(j))
            return ans

        n = len(days)
        valid = [1, 7, 30]
        return dfs(0)
```

#### Java

```java
class Solution {
    private final int[] valid = {1, 7, 30};
    private int[] days;
    private int[] costs;
    private Integer[] f;
    private int n;

    public int mincostTickets(int[] days, int[] costs) {
        n = days.length;
        f = new Integer[n];
        this.days = days;
        this.costs = costs;
        return dfs(0);
    }

    private int dfs(int i) {
        if (i >= n) {
            return 0;
        }
        if (f[i] != null) {
            return f[i];
        }
        f[i] = Integer.MAX_VALUE;
        for (int k = 0; k < 3; ++k) {
            int j = Arrays.binarySearch(days, days[i] + valid[k]);
            j = j < 0 ? -j - 1 : j;
            f[i] = Math.min(f[i], dfs(j) + costs[k]);
        }
        return f[i];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int valid[3] = {1, 7, 30};
        int n = days.size();
        int f[n];
        memset(f, 0, sizeof(f));
        function<int(int)> dfs = [&](int i) {
            if (i >= n) {
                return 0;
            }
            if (f[i]) {
                return f[i];
            }
            f[i] = INT_MAX;
            for (int k = 0; k < 3; ++k) {
                int j = lower_bound(days.begin(), days.end(), days[i] + valid[k]) - days.begin();
                f[i] = min(f[i], dfs(j) + costs[k]);
            }
            return f[i];
        };
        return dfs(0);
    }
};
```

#### Go

```go
func mincostTickets(days []int, costs []int) int {
	valid := [3]int{1, 7, 30}
	n := len(days)
	f := make([]int, n)
	var dfs func(int) int
	dfs = func(i int) int {
		if i >= n {
			return 0
		}
		if f[i] > 0 {
			return f[i]
		}
		f[i] = 1 << 30
		for k := 0; k < 3; k++ {
			j := sort.SearchInts(days, days[i]+valid[k])
			f[i] = min(f[i], dfs(j)+costs[k])
		}
		return f[i]
	}
	return dfs(0)
}
```

#### TypeScript

```ts
function mincostTickets(days: number[], costs: number[]): number {
    const n = days.length;
    const f: number[] = Array(n).fill(0);
    const valid: number[] = [1, 7, 30];
    const search = (x: number): number => {
        let [l, r] = [0, n];
        while (l < r) {
            const mid = (l + r) >> 1;
            if (days[mid] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    };
    const dfs = (i: number): number => {
        if (i >= n) {
            return 0;
        }
        if (f[i]) {
            return f[i];
        }
        f[i] = Infinity;
        for (let k = 0; k < 3; ++k) {
            const j = search(days[i] + valid[k]);
            f[i] = Math.min(f[i], dfs(j) + costs[k]);
        }
        return f[i];
    };
    return dfs(0);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：动态规划

我们不妨记 $\textit{days}$ 数组中的最后一天为 $m$，那么我们可以定义一个长度为 $m + 1$ 的数组 $f$，其中 $f[i]$ 表示从第 $1$ 天到第 $i$ 天的最小花费。

我们可以按照 $\textit{days}$ 数组中的日期递增的顺序，从第 $1$ 天开始，依次计算 $f[i]$ 的值。如果第 $i$ 天是出行的日期，那么我们可以考虑三种购买方式，分别是购买 $1$ 天通行证、购买 $7$ 天通行证和购买 $30$ 天通行证。我们分别计算这三种购买方式的花费，并且取这三种购买方式的最小花费作为 $f[i]$ 的值。如果第 $i$ 天不是出行的日期，那么 $f[i] = f[i - 1]$。

最终答案为 $f[m]$。

时间复杂度 $O(m)$，空间复杂度 $O(m)$。其中 $m$ 表示出行的最后一天。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        m = days[-1]
        f = [0] * (m + 1)
        valid = [1, 7, 30]
        j = 0
        for i in range(1, m + 1):
            if i == days[j]:
                f[i] = inf
                for c, v in zip(costs, valid):
                    f[i] = min(f[i], f[max(0, i - v)] + c)
                j += 1
            else:
                f[i] = f[i - 1]
        return f[m]
```

#### Java

```java
class Solution {
    public int mincostTickets(int[] days, int[] costs) {
        int m = days[days.length - 1];
        int[] f = new int[m + 1];
        final int[] valid = {1, 7, 30};
        for (int i = 1, j = 0; i <= m; ++i) {
            if (i == days[j]) {
                f[i] = Integer.MAX_VALUE;
                for (int k = 0; k < 3; ++k) {
                    int c = costs[k], v = valid[k];
                    f[i] = Math.min(f[i], f[Math.max(0, i - v)] + c);
                }
                ++j;
            } else {
                f[i] = f[i - 1];
            }
        }
        return f[m];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int m = days.back();
        int f[m + 1];
        f[0] = 0;
        int valid[3] = {1, 7, 30};
        for (int i = 1, j = 0; i <= m; ++i) {
            if (i == days[j]) {
                f[i] = INT_MAX;
                for (int k = 0; k < 3; ++k) {
                    int c = costs[k], v = valid[k];
                    f[i] = min(f[i], f[max(0, i - v)] + c);
                }
                ++j;
            } else {
                f[i] = f[i - 1];
            }
        }
        return f[m];
    }
};
```

#### Go

```go
func mincostTickets(days []int, costs []int) int {
	m := days[len(days)-1]
	f := make([]int, m+1)
	valid := [3]int{1, 7, 30}
	for i, j := 1, 0; i <= m; i++ {
		if i == days[j] {
			f[i] = 1 << 30
			for k, v := range valid {
				c := costs[k]
				f[i] = min(f[i], f[max(0, i-v)]+c)
			}
			j++
		} else {
			f[i] = f[i-1]
		}
	}
	return f[m]
}
```

#### TypeScript

```ts
function mincostTickets(days: number[], costs: number[]): number {
    const m = days.at(-1)!;
    const f: number[] = Array(m).fill(0);
    const valid: number[] = [1, 7, 30];
    for (let i = 1, j = 0; i <= m; ++i) {
        if (i === days[j]) {
            f[i] = Infinity;
            for (let k = 0; k < 3; ++k) {
                const [c, v] = [costs[k], valid[k]];
                f[i] = Math.min(f[i], f[Math.max(0, i - v)] + c);
            }
            ++j;
        } else {
            f[i] = f[i - 1];
        }
    }
    return f[m];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [984. 不含 AAA 或 BBB 的字符串](https://leetcode.cn/problems/string-without-aaa-or-bbb){#984}

{{< tabs "984" >}}

{{% tab "python" %}}
```python
class Solution:
    def strWithout3a3b(self, a: int, b: int) -> str:
        ans = []
        while a and b:
            if a > b:
                ans.append('aab')
                a, b = a - 2, b - 1
            elif a < b:
                ans.append('bba')
                a, b = a - 1, b - 2
            else:
                ans.append('ab')
                a, b = a - 1, b - 1
        if a:
            ans.append('a' * a)
        if b:
            ans.append('b' * b)
        return ''.join(ans)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String strWithout3a3b(int a, int b) {
        StringBuilder ans = new StringBuilder();
        while (a > 0 && b > 0) {
            if (a > b) {
                ans.append("aab");
                a -= 2;
                b -= 1;
            } else if (a < b) {
                ans.append("bba");
                a -= 1;
                b -= 2;
            } else {
                ans.append("ab");
                --a;
                --b;
            }
        }
        if (a > 0) {
            ans.append("a".repeat(a));
        }
        if (b > 0) {
            ans.append("b".repeat(b));
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
    string strWithout3a3b(int a, int b) {
        string ans;
        while (a && b) {
            if (a > b) {
                ans += "aab";
                a -= 2;
                b -= 1;
            } else if (a < b) {
                ans += "bba";
                a -= 1;
                b -= 2;
            } else {
                ans += "ab";
                --a;
                --b;
            }
        }
        if (a) ans += string(a, 'a');
        if (b) ans += string(b, 'b');
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func strWithout3a3b(a int, b int) string {
	var ans strings.Builder
	for a > 0 && b > 0 {
		if a > b {
			ans.WriteString("aab")
			a -= 2
			b -= 1
		} else if a < b {
			ans.WriteString("bba")
			a -= 1
			b -= 2
		} else {
			ans.WriteString("ab")
			a--
			b--
		}
	}
	if a > 0 {
		ans.WriteString(strings.Repeat("a", a))
	}
	if b > 0 {
		ans.WriteString(strings.Repeat("b", b))
	}
	return ans.String()
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定两个整数 <code>a</code>&nbsp;和 <code>b</code>&nbsp;，返回&nbsp;<strong>任意</strong>&nbsp;字符串 <code>s</code>&nbsp;，要求满足：</p>

<ul>
	<li><code>s</code>&nbsp;的长度为 <code>a + b</code>，且正好包含&nbsp;<code>a</code>&nbsp;个 <code>'a'</code>&nbsp;字母与&nbsp;<code>b</code> 个 <code>'b'</code>&nbsp;字母；</li>
	<li>子串&nbsp;<code>'aaa'</code>&nbsp;没有出现在 <code>s</code>&nbsp;中；</li>
	<li>子串&nbsp;<code>'bbb'</code> 没有出现在 <code>s</code>&nbsp;中。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>a = 1, b = 2
<strong>输出：</strong>"abb"
<strong>解释：</strong>"abb", "bab" 和 "bba" 都是正确答案。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>a = 4, b = 1
<strong>输出：</strong>"aabaa"</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= a, b&nbsp;&lt;= 100</code></li>
	<li>对于给定的 <code>a</code> 和 <code>b</code>，保证存在满足要求的 <code>s</code>&nbsp;</li>
</ul>
<span style="display:block"><span style="height:0px"><span style="position:absolute">​​​</span></span></span>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 构造

循环构造字符串，当 $a$ 和 $b$ 都大于 `0` 时：

1. 如果 $a\gt b$，添加字符串 "aab"
1. 如果 $b\gt a$，添加字符串 "bba"
1. 如果 $a=b$，添加字符串 "ab"

循环结束，若 $a$ 有剩余，则添加 $a$ 个字符串 "a"；若 $b$ 有剩余，则添加 $b$ 个字符串 "b"。

时间复杂度 $O(a+b)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def strWithout3a3b(self, a: int, b: int) -> str:
        ans = []
        while a and b:
            if a > b:
                ans.append('aab')
                a, b = a - 2, b - 1
            elif a < b:
                ans.append('bba')
                a, b = a - 1, b - 2
            else:
                ans.append('ab')
                a, b = a - 1, b - 1
        if a:
            ans.append('a' * a)
        if b:
            ans.append('b' * b)
        return ''.join(ans)
```

#### Java

```java
class Solution {
    public String strWithout3a3b(int a, int b) {
        StringBuilder ans = new StringBuilder();
        while (a > 0 && b > 0) {
            if (a > b) {
                ans.append("aab");
                a -= 2;
                b -= 1;
            } else if (a < b) {
                ans.append("bba");
                a -= 1;
                b -= 2;
            } else {
                ans.append("ab");
                --a;
                --b;
            }
        }
        if (a > 0) {
            ans.append("a".repeat(a));
        }
        if (b > 0) {
            ans.append("b".repeat(b));
        }
        return ans.toString();
    }
}
```

#### C++

```cpp
class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string ans;
        while (a && b) {
            if (a > b) {
                ans += "aab";
                a -= 2;
                b -= 1;
            } else if (a < b) {
                ans += "bba";
                a -= 1;
                b -= 2;
            } else {
                ans += "ab";
                --a;
                --b;
            }
        }
        if (a) ans += string(a, 'a');
        if (b) ans += string(b, 'b');
        return ans;
    }
};
```

#### Go

```go
func strWithout3a3b(a int, b int) string {
	var ans strings.Builder
	for a > 0 && b > 0 {
		if a > b {
			ans.WriteString("aab")
			a -= 2
			b -= 1
		} else if a < b {
			ans.WriteString("bba")
			a -= 1
			b -= 2
		} else {
			ans.WriteString("ab")
			a--
			b--
		}
	}
	if a > 0 {
		ans.WriteString(strings.Repeat("a", a))
	}
	if b > 0 {
		ans.WriteString(strings.Repeat("b", b))
	}
	return ans.String()
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [985. 查询后的偶数和](https://leetcode.cn/problems/sum-of-even-numbers-after-queries){#985}

{{< tabs "985" >}}

{{% tab "python" %}}
```python
class Solution:
    def sumEvenAfterQueries(
        self, nums: List[int], queries: List[List[int]]
    ) -> List[int]:
        s = sum(x for x in nums if x % 2 == 0)
        ans = []
        for v, i in queries:
            if nums[i] % 2 == 0:
                s -= nums[i]
            nums[i] += v
            if nums[i] % 2 == 0:
                s += nums[i]
            ans.append(s)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] sumEvenAfterQueries(int[] nums, int[][] queries) {
        int s = 0;
        for (int x : nums) {
            if (x % 2 == 0) {
                s += x;
            }
        }
        int m = queries.length;
        int[] ans = new int[m];
        int k = 0;
        for (var q : queries) {
            int v = q[0], i = q[1];
            if (nums[i] % 2 == 0) {
                s -= nums[i];
            }
            nums[i] += v;
            if (nums[i] % 2 == 0) {
                s += nums[i];
            }
            ans[k++] = s;
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
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int s = 0;
        for (int x : nums) {
            if (x % 2 == 0) {
                s += x;
            }
        }
        vector<int> ans;
        for (auto& q : queries) {
            int v = q[0], i = q[1];
            if (nums[i] % 2 == 0) {
                s -= nums[i];
            }
            nums[i] += v;
            if (nums[i] % 2 == 0) {
                s += nums[i];
            }
            ans.push_back(s);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func sumEvenAfterQueries(nums []int, queries [][]int) (ans []int) {
	s := 0
	for _, x := range nums {
		if x%2 == 0 {
			s += x
		}
	}
	for _, q := range queries {
		v, i := q[0], q[1]
		if nums[i]%2 == 0 {
			s -= nums[i]
		}
		nums[i] += v
		if nums[i]%2 == 0 {
			s += nums[i]
		}
		ans = append(ans, s)
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function sumEvenAfterQueries(nums: number[], queries: number[][]): number[] {
    let s = nums.reduce((acc, x) => acc + (x % 2 === 0 ? x : 0), 0);
    const ans: number[] = [];
    for (const [v, i] of queries) {
        if (nums[i] % 2 === 0) {
            s -= nums[i];
        }
        nums[i] += v;
        if (nums[i] % 2 === 0) {
            s += nums[i];
        }
        ans.push(s);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn sum_even_after_queries(mut nums: Vec<i32>, queries: Vec<Vec<i32>>) -> Vec<i32> {
        let mut s: i32 = nums.iter().filter(|&x| x % 2 == 0).sum();
        let mut ans = Vec::with_capacity(queries.len());

        for query in queries {
            let (v, i) = (query[0], query[1] as usize);
            if nums[i] % 2 == 0 {
                s -= nums[i];
            }
            nums[i] += v;
            if nums[i] % 2 == 0 {
                s += nums[i];
            }
            ans.push(s);
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
 * @param {number[][]} queries
 * @return {number[]}
 */
var sumEvenAfterQueries = function (nums, queries) {
    let s = nums.reduce((acc, cur) => acc + (cur % 2 === 0 ? cur : 0), 0);
    const ans = [];
    for (const [v, i] of queries) {
        if (nums[i] % 2 === 0) {
            s -= nums[i];
        }
        nums[i] += v;
        if (nums[i] % 2 === 0) {
            s += nums[i];
        }
        ans.push(s);
    }
    return ans;
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int[] SumEvenAfterQueries(int[] nums, int[][] queries) {
        int s = nums.Where(x => x % 2 == 0).Sum();
        int[] ans = new int[queries.Length];

        for (int j = 0; j < queries.Length; j++) {
            int v = queries[j][0], i = queries[j][1];
            if (nums[i] % 2 == 0) {
                s -= nums[i];
            }
            nums[i] += v;
            if (nums[i] % 2 == 0) {
                s += nums[i];
            }
            ans[j] = s;
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

<p>给出一个整数数组&nbsp;<code>A</code>&nbsp;和一个查询数组&nbsp;<code>queries</code>。</p>

<p>对于第&nbsp;<code>i</code>&nbsp;次查询，有&nbsp;<code>val =&nbsp;queries[i][0], index&nbsp;= queries[i][1]</code>，我们会把&nbsp;<code>val</code>&nbsp;加到&nbsp;<code>A[index]</code>&nbsp;上。然后，第&nbsp;<code>i</code>&nbsp;次查询的答案是 <code>A</code> 中偶数值的和。</p>

<p><em>（此处给定的&nbsp;<code>index = queries[i][1]</code>&nbsp;是从 0 开始的索引，每次查询都会永久修改数组&nbsp;<code>A</code>。）</em></p>

<p>返回所有查询的答案。你的答案应当以数组&nbsp;<code>answer</code>&nbsp;给出，<code>answer[i]</code>&nbsp;为第&nbsp;<code>i</code>&nbsp;次查询的答案。</p>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre><strong>输入：</strong>A = [1,2,3,4], queries = [[1,0],[-3,1],[-4,0],[2,3]]
<strong>输出：</strong>[8,6,2,4]
<strong>解释：</strong>
开始时，数组为 [1,2,3,4]。
将 1 加到 A[0] 上之后，数组为 [2,2,3,4]，偶数值之和为 2 + 2 + 4 = 8。
将 -3 加到 A[1] 上之后，数组为 [2,-1,3,4]，偶数值之和为 2 + 4 = 6。
将 -4 加到 A[0] 上之后，数组为 [-2,-1,3,4]，偶数值之和为 -2 + 4 = 2。
将 2 加到 A[3] 上之后，数组为 [-2,-1,3,6]，偶数值之和为 -2 + 6 = 4。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ol>
	<li><code>1 &lt;= A.length &lt;= 10000</code></li>
	<li><code>-10000 &lt;= A[i] &lt;= 10000</code></li>
	<li><code>1 &lt;= queries.length &lt;= 10000</code></li>
	<li><code>-10000 &lt;= queries[i][0] &lt;= 10000</code></li>
	<li><code>0 &lt;= queries[i][1] &lt; A.length</code></li>
</ol>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们用一个整型变量 $\textit{s}$ 记录数组 $\textit{nums}$ 中所有偶数的和，初始时 $\textit{s}$ 为数组 $\textit{nums}$ 中所有偶数的和。

对于每次查询 $(v, i)$，我们首先判断 $\textit{nums}[i]$ 是否为偶数，若 $\textit{nums}[i]$ 为偶数，则将 $\textit{s}$ 减去 $\textit{nums}[i]$；然后将 $\textit{nums}[i]$ 加上 $v$；若 $\textit{nums}[i]$ 为偶数，则将 $\textit{s}$ 加上 $\textit{nums}[i]$，然后将 $\textit{s}$ 加入答案数组。

时间复杂度 $O(n + m)$，其中 $n$ 和 $m$ 分别为数组 $\textit{nums}$ 和 $\textit{queries}$ 的长度。忽略答案数组的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def sumEvenAfterQueries(
        self, nums: List[int], queries: List[List[int]]
    ) -> List[int]:
        s = sum(x for x in nums if x % 2 == 0)
        ans = []
        for v, i in queries:
            if nums[i] % 2 == 0:
                s -= nums[i]
            nums[i] += v
            if nums[i] % 2 == 0:
                s += nums[i]
            ans.append(s)
        return ans
```

#### Java

```java
class Solution {
    public int[] sumEvenAfterQueries(int[] nums, int[][] queries) {
        int s = 0;
        for (int x : nums) {
            if (x % 2 == 0) {
                s += x;
            }
        }
        int m = queries.length;
        int[] ans = new int[m];
        int k = 0;
        for (var q : queries) {
            int v = q[0], i = q[1];
            if (nums[i] % 2 == 0) {
                s -= nums[i];
            }
            nums[i] += v;
            if (nums[i] % 2 == 0) {
                s += nums[i];
            }
            ans[k++] = s;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int s = 0;
        for (int x : nums) {
            if (x % 2 == 0) {
                s += x;
            }
        }
        vector<int> ans;
        for (auto& q : queries) {
            int v = q[0], i = q[1];
            if (nums[i] % 2 == 0) {
                s -= nums[i];
            }
            nums[i] += v;
            if (nums[i] % 2 == 0) {
                s += nums[i];
            }
            ans.push_back(s);
        }
        return ans;
    }
};
```

#### Go

```go
func sumEvenAfterQueries(nums []int, queries [][]int) (ans []int) {
	s := 0
	for _, x := range nums {
		if x%2 == 0 {
			s += x
		}
	}
	for _, q := range queries {
		v, i := q[0], q[1]
		if nums[i]%2 == 0 {
			s -= nums[i]
		}
		nums[i] += v
		if nums[i]%2 == 0 {
			s += nums[i]
		}
		ans = append(ans, s)
	}
	return
}
```

#### TypeScript

```ts
function sumEvenAfterQueries(nums: number[], queries: number[][]): number[] {
    let s = nums.reduce((acc, x) => acc + (x % 2 === 0 ? x : 0), 0);
    const ans: number[] = [];
    for (const [v, i] of queries) {
        if (nums[i] % 2 === 0) {
            s -= nums[i];
        }
        nums[i] += v;
        if (nums[i] % 2 === 0) {
            s += nums[i];
        }
        ans.push(s);
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn sum_even_after_queries(mut nums: Vec<i32>, queries: Vec<Vec<i32>>) -> Vec<i32> {
        let mut s: i32 = nums.iter().filter(|&x| x % 2 == 0).sum();
        let mut ans = Vec::with_capacity(queries.len());

        for query in queries {
            let (v, i) = (query[0], query[1] as usize);
            if nums[i] % 2 == 0 {
                s -= nums[i];
            }
            nums[i] += v;
            if nums[i] % 2 == 0 {
                s += nums[i];
            }
            ans.push(s);
        }

        ans
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @param {number[][]} queries
 * @return {number[]}
 */
var sumEvenAfterQueries = function (nums, queries) {
    let s = nums.reduce((acc, cur) => acc + (cur % 2 === 0 ? cur : 0), 0);
    const ans = [];
    for (const [v, i] of queries) {
        if (nums[i] % 2 === 0) {
            s -= nums[i];
        }
        nums[i] += v;
        if (nums[i] % 2 === 0) {
            s += nums[i];
        }
        ans.push(s);
    }
    return ans;
};
```

#### C#

```cs
public class Solution {
    public int[] SumEvenAfterQueries(int[] nums, int[][] queries) {
        int s = nums.Where(x => x % 2 == 0).Sum();
        int[] ans = new int[queries.Length];

        for (int j = 0; j < queries.Length; j++) {
            int v = queries[j][0], i = queries[j][1];
            if (nums[i] % 2 == 0) {
                s -= nums[i];
            }
            nums[i] += v;
            if (nums[i] % 2 == 0) {
                s += nums[i];
            }
            ans[j] = s;
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

# [986. 区间列表的交集](https://leetcode.cn/problems/interval-list-intersections){#986}

{{< tabs "986" >}}

{{% tab "python" %}}
```python
class Solution:
    def intervalIntersection(
        self, firstList: List[List[int]], secondList: List[List[int]]
    ) -> List[List[int]]:
        i = j = 0
        ans = []
        while i < len(firstList) and j < len(secondList):
            s1, e1, s2, e2 = *firstList[i], *secondList[j]
            l, r = max(s1, s2), min(e1, e2)
            if l <= r:
                ans.append([l, r])
            if e1 < e2:
                i += 1
            else:
                j += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[][] intervalIntersection(int[][] firstList, int[][] secondList) {
        List<int[]> ans = new ArrayList<>();
        int m = firstList.length, n = secondList.length;
        for (int i = 0, j = 0; i < m && j < n;) {
            int l = Math.max(firstList[i][0], secondList[j][0]);
            int r = Math.min(firstList[i][1], secondList[j][1]);
            if (l <= r) {
                ans.add(new int[] {l, r});
            }
            if (firstList[i][1] < secondList[j][1]) {
                ++i;
            } else {
                ++j;
            }
        }
        return ans.toArray(new int[ans.size()][]);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ans;
        int m = firstList.size(), n = secondList.size();
        for (int i = 0, j = 0; i < m && j < n;) {
            int l = max(firstList[i][0], secondList[j][0]);
            int r = min(firstList[i][1], secondList[j][1]);
            if (l <= r) ans.push_back({l, r});
            if (firstList[i][1] < secondList[j][1])
                ++i;
            else
                ++j;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func intervalIntersection(firstList [][]int, secondList [][]int) [][]int {
	m, n := len(firstList), len(secondList)
	var ans [][]int
	for i, j := 0, 0; i < m && j < n; {
		l := max(firstList[i][0], secondList[j][0])
		r := min(firstList[i][1], secondList[j][1])
		if l <= r {
			ans = append(ans, []int{l, r})
		}
		if firstList[i][1] < secondList[j][1] {
			i++
		} else {
			j++
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function intervalIntersection(firstList: number[][], secondList: number[][]): number[][] {
    const n = firstList.length;
    const m = secondList.length;
    const res = [];
    let i = 0;
    let j = 0;
    while (i < n && j < m) {
        const start = Math.max(firstList[i][0], secondList[j][0]);
        const end = Math.min(firstList[i][1], secondList[j][1]);
        if (start <= end) {
            res.push([start, end]);
        }
        if (firstList[i][1] < secondList[j][1]) {
            i++;
        } else {
            j++;
        }
    }
    return res;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn interval_intersection(
        first_list: Vec<Vec<i32>>,
        second_list: Vec<Vec<i32>>,
    ) -> Vec<Vec<i32>> {
        let n = first_list.len();
        let m = second_list.len();
        let mut res = Vec::new();
        let (mut i, mut j) = (0, 0);
        while i < n && j < m {
            let start = first_list[i][0].max(second_list[j][0]);
            let end = first_list[i][1].min(second_list[j][1]);
            if start <= end {
                res.push(vec![start, end]);
            }
            if first_list[i][1] < second_list[j][1] {
                i += 1;
            } else {
                j += 1;
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

<p>给定两个由一些<strong> 闭区间 </strong>组成的列表，<code>firstList</code> 和 <code>secondList</code> ，其中 <code>firstList[i] = [start<sub>i</sub>, end<sub>i</sub>]</code> 而 <code>secondList[j] = [start<sub>j</sub>, end<sub>j</sub>]</code> 。每个区间列表都是成对 <strong>不相交</strong> 的，并且 <strong>已经排序</strong> 。</p>

<p>返回这 <strong>两个区间列表的交集</strong> 。</p>

<p>形式上，<strong>闭区间</strong> <code>[a, b]</code>（其中 <code>a <= b</code>）表示实数 <code>x</code> 的集合，而 <code>a <= x <= b</code> 。</p>

<p>两个闭区间的 <strong>交集</strong> 是一组实数，要么为空集，要么为闭区间。例如，<code>[1, 3]</code> 和 <code>[2, 4]</code> 的交集为 <code>[2, 3]</code> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0900-0999/0986.Interval%20List%20Intersections/images/interval1.png" style="width: 700px; height: 194px;" />
<pre>
<strong>输入：</strong>firstList = [[0,2],[5,10],[13,23],[24,25]], secondList = [[1,5],[8,12],[15,24],[25,26]]
<strong>输出：</strong>[[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>firstList = [[1,3],[5,9]], secondList = []
<strong>输出：</strong>[]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>firstList = [], secondList = [[4,8],[10,12]]
<strong>输出：</strong>[]
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>firstList = [[1,7]], secondList = [[3,10]]
<strong>输出：</strong>[[3,7]]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 <= firstList.length, secondList.length <= 1000</code></li>
	<li><code>firstList.length + secondList.length >= 1</code></li>
	<li><code>0 <= start<sub>i</sub> < end<sub>i</sub> <= 10<sup>9</sup></code></li>
	<li><code>end<sub>i</sub> < start<sub>i+1</sub></code></li>
	<li><code>0 <= start<sub>j</sub> < end<sub>j</sub> <= 10<sup>9</sup> </code></li>
	<li><code>end<sub>j</sub> < start<sub>j+1</sub></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双指针

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def intervalIntersection(
        self, firstList: List[List[int]], secondList: List[List[int]]
    ) -> List[List[int]]:
        i = j = 0
        ans = []
        while i < len(firstList) and j < len(secondList):
            s1, e1, s2, e2 = *firstList[i], *secondList[j]
            l, r = max(s1, s2), min(e1, e2)
            if l <= r:
                ans.append([l, r])
            if e1 < e2:
                i += 1
            else:
                j += 1
        return ans
```

#### Java

```java
class Solution {
    public int[][] intervalIntersection(int[][] firstList, int[][] secondList) {
        List<int[]> ans = new ArrayList<>();
        int m = firstList.length, n = secondList.length;
        for (int i = 0, j = 0; i < m && j < n;) {
            int l = Math.max(firstList[i][0], secondList[j][0]);
            int r = Math.min(firstList[i][1], secondList[j][1]);
            if (l <= r) {
                ans.add(new int[] {l, r});
            }
            if (firstList[i][1] < secondList[j][1]) {
                ++i;
            } else {
                ++j;
            }
        }
        return ans.toArray(new int[ans.size()][]);
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ans;
        int m = firstList.size(), n = secondList.size();
        for (int i = 0, j = 0; i < m && j < n;) {
            int l = max(firstList[i][0], secondList[j][0]);
            int r = min(firstList[i][1], secondList[j][1]);
            if (l <= r) ans.push_back({l, r});
            if (firstList[i][1] < secondList[j][1])
                ++i;
            else
                ++j;
        }
        return ans;
    }
};
```

#### Go

```go
func intervalIntersection(firstList [][]int, secondList [][]int) [][]int {
	m, n := len(firstList), len(secondList)
	var ans [][]int
	for i, j := 0, 0; i < m && j < n; {
		l := max(firstList[i][0], secondList[j][0])
		r := min(firstList[i][1], secondList[j][1])
		if l <= r {
			ans = append(ans, []int{l, r})
		}
		if firstList[i][1] < secondList[j][1] {
			i++
		} else {
			j++
		}
	}
	return ans
}
```

#### TypeScript

```ts
function intervalIntersection(firstList: number[][], secondList: number[][]): number[][] {
    const n = firstList.length;
    const m = secondList.length;
    const res = [];
    let i = 0;
    let j = 0;
    while (i < n && j < m) {
        const start = Math.max(firstList[i][0], secondList[j][0]);
        const end = Math.min(firstList[i][1], secondList[j][1]);
        if (start <= end) {
            res.push([start, end]);
        }
        if (firstList[i][1] < secondList[j][1]) {
            i++;
        } else {
            j++;
        }
    }
    return res;
}
```

#### Rust

```rust
impl Solution {
    pub fn interval_intersection(
        first_list: Vec<Vec<i32>>,
        second_list: Vec<Vec<i32>>,
    ) -> Vec<Vec<i32>> {
        let n = first_list.len();
        let m = second_list.len();
        let mut res = Vec::new();
        let (mut i, mut j) = (0, 0);
        while i < n && j < m {
            let start = first_list[i][0].max(second_list[j][0]);
            let end = first_list[i][1].min(second_list[j][1]);
            if start <= end {
                res.push(vec![start, end]);
            }
            if first_list[i][1] < second_list[j][1] {
                i += 1;
            } else {
                j += 1;
            }
        }
        res
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [987. 二叉树的垂序遍历](https://leetcode.cn/problems/vertical-order-traversal-of-a-binary-tree){#987}

{{< tabs "987" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def verticalTraversal(self, root: Optional[TreeNode]) -> List[List[int]]:
        def dfs(root: Optional[TreeNode], i: int, j: int):
            if root is None:
                return
            nodes.append((j, i, root.val))
            dfs(root.left, i + 1, j - 1)
            dfs(root.right, i + 1, j + 1)

        nodes = []
        dfs(root, 0, 0)
        nodes.sort()
        ans = []
        prev = -2000
        for j, _, val in nodes:
            if prev != j:
                ans.append([])
                prev = j
            ans[-1].append(val)
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
    private List<int[]> nodes = new ArrayList<>();

    public List<List<Integer>> verticalTraversal(TreeNode root) {
        dfs(root, 0, 0);
        Collections.sort(nodes, (a, b) -> {
            if (a[0] != b[0]) {
                return Integer.compare(a[0], b[0]);
            }
            if (a[1] != b[1]) {
                return Integer.compare(a[1], b[1]);
            }
            return Integer.compare(a[2], b[2]);
        });
        List<List<Integer>> ans = new ArrayList<>();
        int prev = -2000;
        for (int[] node : nodes) {
            int j = node[0], val = node[2];
            if (prev != j) {
                ans.add(new ArrayList<>());
                prev = j;
            }
            ans.get(ans.size() - 1).add(val);
        }

        return ans;
    }

    private void dfs(TreeNode root, int i, int j) {
        if (root == null) {
            return;
        }
        nodes.add(new int[] {j, i, root.val});
        dfs(root.left, i + 1, j - 1);
        dfs(root.right, i + 1, j + 1);
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<tuple<int, int, int>> nodes;
        function<void(TreeNode*, int, int)> dfs = [&](TreeNode* root, int i, int j) {
            if (!root) {
                return;
            }
            nodes.emplace_back(j, i, root->val);
            dfs(root->left, i + 1, j - 1);
            dfs(root->right, i + 1, j + 1);
        };
        dfs(root, 0, 0);
        sort(nodes.begin(), nodes.end());
        vector<vector<int>> ans;
        int prev = -2000;
        for (auto [j, _, val] : nodes) {
            if (j != prev) {
                prev = j;
                ans.emplace_back();
            }
            ans.back().push_back(val);
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
func verticalTraversal(root *TreeNode) (ans [][]int) {
	nodes := [][3]int{}
	var dfs func(*TreeNode, int, int)
	dfs = func(root *TreeNode, i, j int) {
		if root == nil {
			return
		}
		nodes = append(nodes, [3]int{j, i, root.Val})
		dfs(root.Left, i+1, j-1)
		dfs(root.Right, i+1, j+1)
	}
	dfs(root, 0, 0)
	sort.Slice(nodes, func(i, j int) bool {
		a, b := nodes[i], nodes[j]
		return a[0] < b[0] || a[0] == b[0] && (a[1] < b[1] || a[1] == b[1] && a[2] < b[2])
	})
	prev := -2000
	for _, node := range nodes {
		j, val := node[0], node[2]
		if j != prev {
			ans = append(ans, nil)
			prev = j
		}
		ans[len(ans)-1] = append(ans[len(ans)-1], val)
	}
	return
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

function verticalTraversal(root: TreeNode | null): number[][] {
    const nodes: [number, number, number][] = [];
    const dfs = (root: TreeNode | null, i: number, j: number) => {
        if (!root) {
            return;
        }
        nodes.push([j, i, root.val]);
        dfs(root.left, i + 1, j - 1);
        dfs(root.right, i + 1, j + 1);
    };
    dfs(root, 0, 0);
    nodes.sort((a, b) => a[0] - b[0] || a[1] - b[1] || a[2] - b[2]);
    const ans: number[][] = [];
    let prev = -2000;
    for (const [j, _, val] of nodes) {
        if (j !== prev) {
            prev = j;
            ans.push([]);
        }
        ans.at(-1)!.push(val);
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

<p>给你二叉树的根结点 <code>root</code> ，请你设计算法计算二叉树的<em> </em><strong>垂序遍历</strong> 序列。</p>

<p>对位于&nbsp;<code>(row, col)</code>&nbsp;的每个结点而言，其左右子结点分别位于&nbsp;<code>(row + 1, col - 1)</code>&nbsp;和&nbsp;<code>(row + 1, col + 1)</code> 。树的根结点位于 <code>(0, 0)</code> 。</p>

<p>二叉树的 <strong>垂序遍历</strong> 从最左边的列开始直到最右边的列结束，按列索引每一列上的所有结点，形成一个按出现位置从上到下排序的有序列表。如果同行同列上有多个结点，则按结点的值从小到大进行排序。</p>

<p>返回二叉树的 <strong>垂序遍历</strong> 序列。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0900-0999/0987.Vertical%20Order%20Traversal%20of%20a%20Binary%20Tree/images/vtree1.jpg" style="width: 431px; height: 304px;" />
<pre>
<strong>输入：</strong>root = [3,9,20,null,null,15,7]
<strong>输出：</strong>[[9],[3,15],[20],[7]]
<strong>解释：</strong>
列 -1 ：只有结点 9 在此列中。
列  0 ：只有结点 3 和 15 在此列中，按从上到下顺序。
列  1 ：只有结点 20 在此列中。
列  2 ：只有结点 7 在此列中。</pre>

<p><strong class="example">示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0900-0999/0987.Vertical%20Order%20Traversal%20of%20a%20Binary%20Tree/images/vtree2.jpg" style="width: 512px; height: 304px;" />
<pre>
<strong>输入：</strong>root = [1,2,3,4,5,6,7]
<strong>输出：</strong>[[4],[2],[1,5,6],[3],[7]]
<strong>解释：</strong>
列 -2 ：只有结点 4 在此列中。
列 -1 ：只有结点 2 在此列中。
列  0 ：结点 1 、5 和 6 都在此列中。
          1 在上面，所以它出现在前面。
          5 和 6 位置都是 (2, 0) ，所以按值从小到大排序，5 在 6 的前面。
列  1 ：只有结点 3 在此列中。
列  2 ：只有结点 7 在此列中。
</pre>

<p><strong class="example">示例 3：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0900-0999/0987.Vertical%20Order%20Traversal%20of%20a%20Binary%20Tree/images/vtree3.jpg" style="width: 512px; height: 304px;" />
<pre>
<strong>输入：</strong>root = [1,2,3,4,6,5,7]
<strong>输出：</strong>[[4],[2],[1,5,6],[3],[7]]
<strong>解释：</strong>
这个示例实际上与示例 2 完全相同，只是结点 5 和 6 在树中的位置发生了交换。
因为 5 和 6 的位置仍然相同，所以答案保持不变，仍然按值从小到大排序。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中结点数目总数在范围 <code>[1, 1000]</code> 内</li>
	<li><code>0 &lt;= Node.val &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS + 排序

我们设计一个函数 $dfs(root, i, j)$，其中 $i$ 和 $j$ 表示当前节点的行和列。我们可以通过深度优先搜索的方式，将节点的行和列信息记录下来，存储在一个数组或列表 $nodes$ 中，然后对 $nodes$ 按照列、行、值的顺序进行排序。

接着，我们遍历 $nodes$，将相同列的节点值放到同一个列表中，最后返回这些列表。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 是二叉树的节点数。

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
    def verticalTraversal(self, root: Optional[TreeNode]) -> List[List[int]]:
        def dfs(root: Optional[TreeNode], i: int, j: int):
            if root is None:
                return
            nodes.append((j, i, root.val))
            dfs(root.left, i + 1, j - 1)
            dfs(root.right, i + 1, j + 1)

        nodes = []
        dfs(root, 0, 0)
        nodes.sort()
        ans = []
        prev = -2000
        for j, _, val in nodes:
            if prev != j:
                ans.append([])
                prev = j
            ans[-1].append(val)
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
    private List<int[]> nodes = new ArrayList<>();

    public List<List<Integer>> verticalTraversal(TreeNode root) {
        dfs(root, 0, 0);
        Collections.sort(nodes, (a, b) -> {
            if (a[0] != b[0]) {
                return Integer.compare(a[0], b[0]);
            }
            if (a[1] != b[1]) {
                return Integer.compare(a[1], b[1]);
            }
            return Integer.compare(a[2], b[2]);
        });
        List<List<Integer>> ans = new ArrayList<>();
        int prev = -2000;
        for (int[] node : nodes) {
            int j = node[0], val = node[2];
            if (prev != j) {
                ans.add(new ArrayList<>());
                prev = j;
            }
            ans.get(ans.size() - 1).add(val);
        }

        return ans;
    }

    private void dfs(TreeNode root, int i, int j) {
        if (root == null) {
            return;
        }
        nodes.add(new int[] {j, i, root.val});
        dfs(root.left, i + 1, j - 1);
        dfs(root.right, i + 1, j + 1);
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<tuple<int, int, int>> nodes;
        function<void(TreeNode*, int, int)> dfs = [&](TreeNode* root, int i, int j) {
            if (!root) {
                return;
            }
            nodes.emplace_back(j, i, root->val);
            dfs(root->left, i + 1, j - 1);
            dfs(root->right, i + 1, j + 1);
        };
        dfs(root, 0, 0);
        sort(nodes.begin(), nodes.end());
        vector<vector<int>> ans;
        int prev = -2000;
        for (auto [j, _, val] : nodes) {
            if (j != prev) {
                prev = j;
                ans.emplace_back();
            }
            ans.back().push_back(val);
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
func verticalTraversal(root *TreeNode) (ans [][]int) {
	nodes := [][3]int{}
	var dfs func(*TreeNode, int, int)
	dfs = func(root *TreeNode, i, j int) {
		if root == nil {
			return
		}
		nodes = append(nodes, [3]int{j, i, root.Val})
		dfs(root.Left, i+1, j-1)
		dfs(root.Right, i+1, j+1)
	}
	dfs(root, 0, 0)
	sort.Slice(nodes, func(i, j int) bool {
		a, b := nodes[i], nodes[j]
		return a[0] < b[0] || a[0] == b[0] && (a[1] < b[1] || a[1] == b[1] && a[2] < b[2])
	})
	prev := -2000
	for _, node := range nodes {
		j, val := node[0], node[2]
		if j != prev {
			ans = append(ans, nil)
			prev = j
		}
		ans[len(ans)-1] = append(ans[len(ans)-1], val)
	}
	return
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

function verticalTraversal(root: TreeNode | null): number[][] {
    const nodes: [number, number, number][] = [];
    const dfs = (root: TreeNode | null, i: number, j: number) => {
        if (!root) {
            return;
        }
        nodes.push([j, i, root.val]);
        dfs(root.left, i + 1, j - 1);
        dfs(root.right, i + 1, j + 1);
    };
    dfs(root, 0, 0);
    nodes.sort((a, b) => a[0] - b[0] || a[1] - b[1] || a[2] - b[2]);
    const ans: number[][] = [];
    let prev = -2000;
    for (const [j, _, val] of nodes) {
        if (j !== prev) {
            prev = j;
            ans.push([]);
        }
        ans.at(-1)!.push(val);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [988. 从叶结点开始的最小字符串](https://leetcode.cn/problems/smallest-string-starting-from-leaf){#988}

{{< tabs "988" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def smallestFromLeaf(self, root: TreeNode) -> str:
        ans = chr(ord('z') + 1)

        def dfs(root, path):
            nonlocal ans
            if root:
                path.append(chr(ord('a') + root.val))
                if root.left is None and root.right is None:
                    ans = min(ans, ''.join(reversed(path)))
                dfs(root.left, path)
                dfs(root.right, path)
                path.pop()

        dfs(root, [])
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
    private StringBuilder path;
    private String ans;

    public String smallestFromLeaf(TreeNode root) {
        path = new StringBuilder();
        ans = String.valueOf((char) ('z' + 1));
        dfs(root, path);
        return ans;
    }

    private void dfs(TreeNode root, StringBuilder path) {
        if (root != null) {
            path.append((char) ('a' + root.val));
            if (root.left == null && root.right == null) {
                String t = path.reverse().toString();
                if (t.compareTo(ans) < 0) {
                    ans = t;
                }
                path.reverse();
            }
            dfs(root.left, path);
            dfs(root.right, path);
            path.deleteCharAt(path.length() - 1);
        }
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
    string ans = "";

    string smallestFromLeaf(TreeNode* root) {
        string path = "";
        dfs(root, path);
        return ans;
    }

    void dfs(TreeNode* root, string& path) {
        if (!root) return;
        path += 'a' + root->val;
        if (!root->left && !root->right) {
            string t = path;
            reverse(t.begin(), t.end());
            if (ans == "" || t < ans) ans = t;
        }
        dfs(root->left, path);
        dfs(root->right, path);
        path.pop_back();
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
func smallestFromLeaf(root *TreeNode) string {
	ans := ""
	var dfs func(root *TreeNode, path string)
	dfs = func(root *TreeNode, path string) {
		if root == nil {
			return
		}
		path = string('a'+root.Val) + path
		if root.Left == nil && root.Right == nil {
			if ans == "" || path < ans {
				ans = path
			}
			return
		}
		dfs(root.Left, path)
		dfs(root.Right, path)
	}

	dfs(root, "")
	return ans
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一颗根结点为&nbsp;<code>root</code>&nbsp;的二叉树，树中的每一个结点都有一个&nbsp;<code>[0, 25]</code>&nbsp;范围内的值，分别代表字母&nbsp;<code>'a'</code> 到&nbsp;<code>'z'</code>。</p>

<p>返回 <em><strong>按字典序最小</strong> 的字符串，该字符串从这棵树的一个叶结点开始，到根结点结束</em>。</p>

<blockquote>
<p>注<strong>：</strong>字符串中任何较短的前缀在 <strong>字典序上</strong> 都是 <strong>较小</strong> 的：</p>

<ul>
	<li>例如，在字典序上&nbsp;<code>"ab"</code> 比&nbsp;<code>"aba"</code>&nbsp;要小。叶结点是指没有子结点的结点。&nbsp;</li>
</ul>
</blockquote>

<p>节点的叶节点是没有子节点的节点。</p>

<p>&nbsp;</p>

<ol>
</ol>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0900-0999/0988.Smallest%20String%20Starting%20From%20Leaf/images/tree1.png" style="height: 358px; width: 534px;" /></strong></p>

<pre>
<strong>输入：</strong>root = [0,1,2,3,4,3,4]
<strong>输出：</strong>"dba"
</pre>

<p><strong>示例 2：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0900-0999/0988.Smallest%20String%20Starting%20From%20Leaf/images/tree2.png" /></p>

<pre>
<strong>输入：</strong>root = [25,1,3,1,3,0,2]
<strong>输出：</strong>"adz"
</pre>

<p><strong>示例 3：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0900-0999/0988.Smallest%20String%20Starting%20From%20Leaf/images/tree3.png" style="height: 513px; width: 490px;" /></p>

<pre>
<strong>输入：</strong>root = [2,2,1,null,1,0,null,0]
<strong>输出：</strong>"abc"
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>给定树的结点数在&nbsp;<code>[1, 8500]</code> 范围内</li>
	<li><code>0 &lt;= Node.val &lt;= 25</code></li>
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
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def smallestFromLeaf(self, root: TreeNode) -> str:
        ans = chr(ord('z') + 1)

        def dfs(root, path):
            nonlocal ans
            if root:
                path.append(chr(ord('a') + root.val))
                if root.left is None and root.right is None:
                    ans = min(ans, ''.join(reversed(path)))
                dfs(root.left, path)
                dfs(root.right, path)
                path.pop()

        dfs(root, [])
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
    private StringBuilder path;
    private String ans;

    public String smallestFromLeaf(TreeNode root) {
        path = new StringBuilder();
        ans = String.valueOf((char) ('z' + 1));
        dfs(root, path);
        return ans;
    }

    private void dfs(TreeNode root, StringBuilder path) {
        if (root != null) {
            path.append((char) ('a' + root.val));
            if (root.left == null && root.right == null) {
                String t = path.reverse().toString();
                if (t.compareTo(ans) < 0) {
                    ans = t;
                }
                path.reverse();
            }
            dfs(root.left, path);
            dfs(root.right, path);
            path.deleteCharAt(path.length() - 1);
        }
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
    string ans = "";

    string smallestFromLeaf(TreeNode* root) {
        string path = "";
        dfs(root, path);
        return ans;
    }

    void dfs(TreeNode* root, string& path) {
        if (!root) return;
        path += 'a' + root->val;
        if (!root->left && !root->right) {
            string t = path;
            reverse(t.begin(), t.end());
            if (ans == "" || t < ans) ans = t;
        }
        dfs(root->left, path);
        dfs(root->right, path);
        path.pop_back();
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
func smallestFromLeaf(root *TreeNode) string {
	ans := ""
	var dfs func(root *TreeNode, path string)
	dfs = func(root *TreeNode, path string) {
		if root == nil {
			return
		}
		path = string('a'+root.Val) + path
		if root.Left == nil && root.Right == nil {
			if ans == "" || path < ans {
				ans = path
			}
			return
		}
		dfs(root.Left, path)
		dfs(root.Right, path)
	}

	dfs(root, "")
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [989. 数组形式的整数加法](https://leetcode.cn/problems/add-to-array-form-of-integer){#989}

{{< tabs "989" >}}

{{% tab "python" %}}
```python
class Solution:
    def addToArrayForm(self, num: List[int], k: int) -> List[int]:
        ans = []
        i = len(num) - 1
        while i >= 0 or k:
            k += 0 if i < 0 else num[i]
            k, x = divmod(k, 10)
            ans.append(x)
            i -= 1
        return ans[::-1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<Integer> addToArrayForm(int[] num, int k) {
        List<Integer> ans = new ArrayList<>();
        for (int i = num.length - 1; i >= 0 || k > 0; --i) {
            k += (i >= 0 ? num[i] : 0);
            ans.add(k % 10);
            k /= 10;
        }
        Collections.reverse(ans);
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> ans;
        for (int i = num.size() - 1; i >= 0 || k > 0; --i) {
            k += (i >= 0 ? num[i] : 0);
            ans.push_back(k % 10);
            k /= 10;
        }
        ranges::reverse(ans);
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func addToArrayForm(num []int, k int) (ans []int) {
	for i := len(num) - 1; i >= 0 || k > 0; i-- {
		if i >= 0 {
			k += num[i]
		}
		ans = append(ans, k%10)
		k /= 10
	}
	slices.Reverse(ans)
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function addToArrayForm(num: number[], k: number): number[] {
    const ans: number[] = [];
    for (let i = num.length - 1; i >= 0 || k > 0; --i) {
        k += i >= 0 ? num[i] : 0;
        ans.push(k % 10);
        k = Math.floor(k / 10);
    }
    return ans.reverse();
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn add_to_array_form(num: Vec<i32>, k: i32) -> Vec<i32> {
        let mut ans = Vec::new();
        let mut k = k;
        let mut i = num.len() as i32 - 1;

        while i >= 0 || k > 0 {
            if i >= 0 {
                k += num[i as usize];
            }
            ans.push(k % 10);
            k /= 10;
            i -= 1;
        }

        ans.reverse();
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

<p>整数的 <strong>数组形式</strong> &nbsp;<code>num</code>&nbsp;是按照从左到右的顺序表示其数字的数组。</p>

<ul>
	<li>例如，对于 <code>num = 1321</code> ，数组形式是 <code>[1,3,2,1]</code> 。</li>
</ul>

<p>给定 <code>num</code> ，整数的 <strong>数组形式</strong> ，和整数 <code>k</code> ，返回 <em>整数 <code>num + k</code> 的 <strong>数组形式</strong></em> 。</p>

<p>&nbsp;</p>

<ol>
</ol>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>num = [1,2,0,0], k = 34
<strong>输出：</strong>[1,2,3,4]
<strong>解释：</strong>1200 + 34 = 1234
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>num = [2,7,4], k = 181
<strong>输出：</strong>[4,5,5]
<strong>解释：</strong>274 + 181 = 455
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>num = [2,1,5], k = 806
<strong>输出：</strong>[1,0,2,1]
<strong>解释：</strong>215 + 806 = 1021
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= num.length &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= num[i] &lt;= 9</code></li>
	<li><code>num</code>&nbsp;不包含任何前导零，除了零本身</li>
	<li><code>1 &lt;= k &lt;= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们可以从数组的最后一位开始，将数组的每一位与 $k$ 相加，然后将 $k$ 除以 $10$，并将余数作为当前位的值，将商作为进位。一直循环，直到数组遍历完并且 $k = 0$。最后将答案数组反转即可。

时间复杂度 $O(n)$，其中 $n$ 表示 $\textit{num}$ 的长度。忽略答案数组的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def addToArrayForm(self, num: List[int], k: int) -> List[int]:
        ans = []
        i = len(num) - 1
        while i >= 0 or k:
            k += 0 if i < 0 else num[i]
            k, x = divmod(k, 10)
            ans.append(x)
            i -= 1
        return ans[::-1]
```

#### Java

```java
class Solution {
    public List<Integer> addToArrayForm(int[] num, int k) {
        List<Integer> ans = new ArrayList<>();
        for (int i = num.length - 1; i >= 0 || k > 0; --i) {
            k += (i >= 0 ? num[i] : 0);
            ans.add(k % 10);
            k /= 10;
        }
        Collections.reverse(ans);
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> ans;
        for (int i = num.size() - 1; i >= 0 || k > 0; --i) {
            k += (i >= 0 ? num[i] : 0);
            ans.push_back(k % 10);
            k /= 10;
        }
        ranges::reverse(ans);
        return ans;
    }
};
```

#### Go

```go
func addToArrayForm(num []int, k int) (ans []int) {
	for i := len(num) - 1; i >= 0 || k > 0; i-- {
		if i >= 0 {
			k += num[i]
		}
		ans = append(ans, k%10)
		k /= 10
	}
	slices.Reverse(ans)
	return
}
```

#### TypeScript

```ts
function addToArrayForm(num: number[], k: number): number[] {
    const ans: number[] = [];
    for (let i = num.length - 1; i >= 0 || k > 0; --i) {
        k += i >= 0 ? num[i] : 0;
        ans.push(k % 10);
        k = Math.floor(k / 10);
    }
    return ans.reverse();
}
```

#### Rust

```rust
impl Solution {
    pub fn add_to_array_form(num: Vec<i32>, k: i32) -> Vec<i32> {
        let mut ans = Vec::new();
        let mut k = k;
        let mut i = num.len() as i32 - 1;

        while i >= 0 || k > 0 {
            if i >= 0 {
                k += num[i as usize];
            }
            ans.push(k % 10);
            k /= 10;
            i -= 1;
        }

        ans.reverse();
        ans
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
