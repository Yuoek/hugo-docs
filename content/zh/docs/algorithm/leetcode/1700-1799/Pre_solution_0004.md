---
title: "1730_获取食物的最短路径 🔒"
date: 2025-10-08T18:38:17+08:00
weight: 4
tags: [二分查找, 位运算, 分治, 前缀和, 动态规划, 哈希表, 堆（优先队列）, 字符串, 广度优先搜索, 快速选择, 排序, 数学, 数据库, 数组, 数论, 矩阵, 组合数学, 计数, 贪心]
---

{{< markmap >}}
### [1730_获取食物的最短路径 🔒](#1730)
#### [广度优先搜索](#1730)
#### [数组](#1730)
#### [矩阵](#1730)
### [1731_每位经理的下属员工数量](#1731)
#### [数据库](#1731)
### [1732_找到最高海拔](#1732)
#### [数组](#1732)
#### [前缀和](#1732)
### [1733_需要教语言的最少人数](#1733)
#### [贪心](#1733)
#### [数组](#1733)
#### [哈希表](#1733)
### [1734_解码异或后的排列](#1734)
#### [位运算](#1734)
#### [数组](#1734)
### [1735_生成乘积数组的方案数](#1735)
#### [数组](#1735)
#### [数学](#1735)
#### [动态规划](#1735)
#### [组合数学](#1735)
#### [数论](#1735)
### [1736_替换隐藏数字得到的最晚时间](#1736)
#### [贪心](#1736)
#### [字符串](#1736)
### [1737_满足三条件之一需改变的最少字符数](#1737)
#### [哈希表](#1737)
#### [字符串](#1737)
#### [计数](#1737)
#### [前缀和](#1737)
### [1738_找出第 K 大的异或坐标值](#1738)
#### [位运算](#1738)
#### [数组](#1738)
#### [分治](#1738)
#### [矩阵](#1738)
#### [前缀和](#1738)
#### [快速选择](#1738)
#### [排序](#1738)
#### [堆（优先队列）](#1738)
### [1739_放置盒子](#1739)
#### [贪心](#1739)
#### [数学](#1739)
#### [二分查找](#1739)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1730_获取食物的最短路径 🔒
___
#### 广度优先搜索
___
#### 数组
___
#### 矩阵
---
### 1731_每位经理的下属员工数量
___
#### 数据库
---
### 1732_找到最高海拔
___
#### 数组
___
#### 前缀和
---
### 1733_需要教语言的最少人数
___
#### 贪心
___
#### 数组
___
#### 哈希表
---
### 1734_解码异或后的排列
___
#### 位运算
___
#### 数组
---
### 1735_生成乘积数组的方案数
___
#### 数组
___
#### 数学
___
#### 动态规划
___
#### 组合数学
___
#### 数论
---
### 1736_替换隐藏数字得到的最晚时间
___
#### 贪心
___
#### 字符串
---
### 1737_满足三条件之一需改变的最少字符数
___
#### 哈希表
___
#### 字符串
___
#### 计数
___
#### 前缀和
---
### 1738_找出第 K 大的异或坐标值
___
#### 位运算
___
#### 数组
___
#### 分治
___
#### 矩阵
___
#### 前缀和
___
#### 快速选择
___
#### 排序
___
#### 堆（优先队列）
---
### 1739_放置盒子
___
#### 贪心
___
#### 数学
___
#### 二分查找
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 位运算 | 分治 |
| 前缀和 | 动态规划 | 哈希表 |
| 堆（优先队列） | 字符串 | 广度优先搜索 |
| 快速选择 | 排序 | 数学 |
| 数据库 | 数组 | 数论 |
| 矩阵 | 组合数学 | 计数 |
| 贪心 |  |  |

# [1730. 获取食物的最短路径 🔒](https://leetcode.cn/problems/shortest-path-to-get-food){#1730}

{{< tabs "1730" >}}

{{% tab "python" %}}
```python
class Solution:
    def getFood(self, grid: List[List[str]]) -> int:
        m, n = len(grid), len(grid[0])
        i, j = next((i, j) for i in range(m) for j in range(n) if grid[i][j] == '*')
        q = deque([(i, j)])
        dirs = (-1, 0, 1, 0, -1)
        ans = 0
        while q:
            ans += 1
            for _ in range(len(q)):
                i, j = q.popleft()
                for a, b in pairwise(dirs):
                    x, y = i + a, j + b
                    if 0 <= x < m and 0 <= y < n:
                        if grid[x][y] == '#':
                            return ans
                        if grid[x][y] == 'O':
                            grid[x][y] = 'X'
                            q.append((x, y))
        return -1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[] dirs = {-1, 0, 1, 0, -1};

    public int getFood(char[][] grid) {
        int m = grid.length, n = grid[0].length;
        Deque<int[]> q = new ArrayDeque<>();
        for (int i = 0, x = 1; i < m && x == 1; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '*') {
                    q.offer(new int[] {i, j});
                    x = 0;
                    break;
                }
            }
        }
        int ans = 0;
        while (!q.isEmpty()) {
            ++ans;
            for (int t = q.size(); t > 0; --t) {
                var p = q.poll();
                for (int k = 0; k < 4; ++k) {
                    int x = p[0] + dirs[k];
                    int y = p[1] + dirs[k + 1];
                    if (x >= 0 && x < m && y >= 0 && y < n) {
                        if (grid[x][y] == '#') {
                            return ans;
                        }
                        if (grid[x][y] == 'O') {
                            grid[x][y] = 'X';
                            q.offer(new int[] {x, y});
                        }
                    }
                }
            }
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
    const static inline vector<int> dirs = {-1, 0, 1, 0, -1};

    int getFood(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        for (int i = 0, x = 1; i < m && x == 1; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '*') {
                    q.emplace(i, j);
                    x = 0;
                    break;
                }
            }
        }
        int ans = 0;
        while (!q.empty()) {
            ++ans;
            for (int t = q.size(); t; --t) {
                auto [i, j] = q.front();
                q.pop();
                for (int k = 0; k < 4; ++k) {
                    int x = i + dirs[k], y = j + dirs[k + 1];
                    if (x >= 0 && x < m && y >= 0 && y < n) {
                        if (grid[x][y] == '#') return ans;
                        if (grid[x][y] == 'O') {
                            grid[x][y] = 'X';
                            q.emplace(x, y);
                        }
                    }
                }
            }
        }
        return -1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func getFood(grid [][]byte) (ans int) {
	m, n := len(grid), len(grid[0])
	dirs := []int{-1, 0, 1, 0, -1}
	type pair struct{ i, j int }
	q := []pair{}
	for i, x := 0, 1; i < m && x == 1; i++ {
		for j := 0; j < n; j++ {
			if grid[i][j] == '*' {
				q = append(q, pair{i, j})
				x = 0
				break
			}
		}
	}
	for len(q) > 0 {
		ans++
		for t := len(q); t > 0; t-- {
			p := q[0]
			q = q[1:]
			for k := 0; k < 4; k++ {
				x, y := p.i+dirs[k], p.j+dirs[k+1]
				if x >= 0 && x < m && y >= 0 && y < n {
					if grid[x][y] == '#' {
						return ans
					}
					if grid[x][y] == 'O' {
						grid[x][y] = 'X'
						q = append(q, pair{x, y})
					}
				}
			}
		}
	}
	return -1
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {character[][]} grid
 * @return {number}
 */
var getFood = function (grid) {
    const m = grid.length;
    const n = grid[0].length;
    const dirs = [-1, 0, 1, 0, -1];
    const q = [];
    for (let i = 0, x = 1; i < m && x == 1; ++i) {
        for (let j = 0; j < n; ++j) {
            if (grid[i][j] == '*') {
                q.push([i, j]);
                x = 0;
                break;
            }
        }
    }
    let ans = 0;
    while (q.length) {
        ++ans;
        for (let t = q.length; t > 0; --t) {
            const [i, j] = q.shift();
            for (let k = 0; k < 4; ++k) {
                const x = i + dirs[k];
                const y = j + dirs[k + 1];
                if (x >= 0 && x < m && y >= 0 && y < n) {
                    if (grid[x][y] == '#') {
                        return ans;
                    }
                    if (grid[x][y] == 'O') {
                        grid[x][y] = 'X';
                        q.push([x, y]);
                    }
                }
            }
        }
    }
    return -1;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你现在很饿，想要尽快找东西吃。你需要找到最短的路径到达一个食物所在的格子。</p>

<p>给定一个&nbsp;<code>m x n</code>&nbsp;的字符矩阵&nbsp;<code>grid</code>&nbsp;，包含下列不同类型的格子：</p>

<ul>
	<li><code>'*'</code>&nbsp;是你的位置。矩阵中<strong>有且只有一个&nbsp;</strong><code>'*'</code>&nbsp;格子。</li>
	<li><code>'#'</code> 是食物。矩阵中可能存在<strong>多个</strong>食物。</li>
	<li><code>'O'</code>&nbsp;是空地，你可以穿过这些格子。</li>
	<li><code>'X'</code>&nbsp;是障碍，你不可以穿过这些格子。</li>
</ul>

<p>返回你到任意食物的最短路径的长度。如果不存在你到任意食物的路径，返回&nbsp;<code>-1</code>。</p>

<p>&nbsp;</p>

<p><b>示例 1:</b></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1700-1799/1730.Shortest%20Path%20to%20Get%20Food/images/img1.jpg" style="width: 300px; height: 201px;" />
<pre>
<b>输入：</b> grid = [["X","X","X","X","X","X"],["X","*","O","O","O","X"],["X","O","O","#","O","X"],["X","X","X","X","X","X"]]
<b>输出：</b> 3
<b>解释： </b>要拿到食物，你需要走 3 步。</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1700-1799/1730.Shortest%20Path%20to%20Get%20Food/images/img2.jpg" style="width: 300px; height: 241px;" />
<pre>
<b>输入：</b> grid = [["X","X","X","X","X"],["X","*","X","O","X"],["X","O","X","#","X"],["X","X","X","X","X"]]
<b>输出：</b> -1
<b>解释：</b> 你不可能拿到食物。
</pre>

<p><strong>示例&nbsp;3:</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1700-1799/1730.Shortest%20Path%20to%20Get%20Food/images/img3.jpg" style="width: 300px; height: 188px;" />
<pre>
<strong>输入:</strong> grid = [["X","X","X","X","X","X","X","X"],["X","*","O","X","O","#","O","X"],["X","O","O","X","O","O","X","X"],["X","O","O","O","O","#","O","X"],["X","X","X","X","X","X","X","X"]]
<strong>输出:</strong> 6
<strong>解释:</strong> 这里有多个食物。拿到下边的食物仅需走 6 步。</pre>

<p><strong class="example">示例 4：</strong></p>

<pre>
<b>输入：</b>grid = [["X","X","X","X","X","X","X","X"],["X","*","O","X","O","#","O","X"],["X","O","O","X","O","O","X","X"],["X","O","O","O","O","#","O","X"],["O","O","O","O","O","O","O","O"]]
<b>输出：</b>5</pre>

<p>&nbsp;</p>

<p><b>提示：</b></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 200</code></li>
	<li><code>grid[row][col]</code>&nbsp;是&nbsp;<code>'*'</code>、&nbsp;<code>'X'</code>、&nbsp;<code>'O'</code>&nbsp;或&nbsp;<code>'#'</code>&nbsp;。</li>
	<li><code>grid</code>&nbsp;中<strong>有且只有一个</strong>&nbsp;<code>'*'</code>&nbsp;。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：BFS

根据题意，我们需要从 `*` 出发，找到最近的 `#`，返回最短路径长度。

首先，我们遍历整个二维数组，找到 `*` 的位置，将其作为 BFS 的起点，放入队列中。

然后，我们开始 BFS，遍历队列中的元素，每次遍历到一个元素，我们将其上下左右四个方向的元素加入队列中，直到遇到 `#`，返回当前层数。

时间复杂度 $O(m \times n)$，空间复杂度 $O(1)$。其中 $m$ 和 $n$ 分别为二维数组的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def getFood(self, grid: List[List[str]]) -> int:
        m, n = len(grid), len(grid[0])
        i, j = next((i, j) for i in range(m) for j in range(n) if grid[i][j] == '*')
        q = deque([(i, j)])
        dirs = (-1, 0, 1, 0, -1)
        ans = 0
        while q:
            ans += 1
            for _ in range(len(q)):
                i, j = q.popleft()
                for a, b in pairwise(dirs):
                    x, y = i + a, j + b
                    if 0 <= x < m and 0 <= y < n:
                        if grid[x][y] == '#':
                            return ans
                        if grid[x][y] == 'O':
                            grid[x][y] = 'X'
                            q.append((x, y))
        return -1
```

#### Java

```java
class Solution {
    private int[] dirs = {-1, 0, 1, 0, -1};

    public int getFood(char[][] grid) {
        int m = grid.length, n = grid[0].length;
        Deque<int[]> q = new ArrayDeque<>();
        for (int i = 0, x = 1; i < m && x == 1; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '*') {
                    q.offer(new int[] {i, j});
                    x = 0;
                    break;
                }
            }
        }
        int ans = 0;
        while (!q.isEmpty()) {
            ++ans;
            for (int t = q.size(); t > 0; --t) {
                var p = q.poll();
                for (int k = 0; k < 4; ++k) {
                    int x = p[0] + dirs[k];
                    int y = p[1] + dirs[k + 1];
                    if (x >= 0 && x < m && y >= 0 && y < n) {
                        if (grid[x][y] == '#') {
                            return ans;
                        }
                        if (grid[x][y] == 'O') {
                            grid[x][y] = 'X';
                            q.offer(new int[] {x, y});
                        }
                    }
                }
            }
        }
        return -1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    const static inline vector<int> dirs = {-1, 0, 1, 0, -1};

    int getFood(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        for (int i = 0, x = 1; i < m && x == 1; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '*') {
                    q.emplace(i, j);
                    x = 0;
                    break;
                }
            }
        }
        int ans = 0;
        while (!q.empty()) {
            ++ans;
            for (int t = q.size(); t; --t) {
                auto [i, j] = q.front();
                q.pop();
                for (int k = 0; k < 4; ++k) {
                    int x = i + dirs[k], y = j + dirs[k + 1];
                    if (x >= 0 && x < m && y >= 0 && y < n) {
                        if (grid[x][y] == '#') return ans;
                        if (grid[x][y] == 'O') {
                            grid[x][y] = 'X';
                            q.emplace(x, y);
                        }
                    }
                }
            }
        }
        return -1;
    }
};
```

#### Go

```go
func getFood(grid [][]byte) (ans int) {
	m, n := len(grid), len(grid[0])
	dirs := []int{-1, 0, 1, 0, -1}
	type pair struct{ i, j int }
	q := []pair{}
	for i, x := 0, 1; i < m && x == 1; i++ {
		for j := 0; j < n; j++ {
			if grid[i][j] == '*' {
				q = append(q, pair{i, j})
				x = 0
				break
			}
		}
	}
	for len(q) > 0 {
		ans++
		for t := len(q); t > 0; t-- {
			p := q[0]
			q = q[1:]
			for k := 0; k < 4; k++ {
				x, y := p.i+dirs[k], p.j+dirs[k+1]
				if x >= 0 && x < m && y >= 0 && y < n {
					if grid[x][y] == '#' {
						return ans
					}
					if grid[x][y] == 'O' {
						grid[x][y] = 'X'
						q = append(q, pair{x, y})
					}
				}
			}
		}
	}
	return -1
}
```

#### JavaScript

```js
/**
 * @param {character[][]} grid
 * @return {number}
 */
var getFood = function (grid) {
    const m = grid.length;
    const n = grid[0].length;
    const dirs = [-1, 0, 1, 0, -1];
    const q = [];
    for (let i = 0, x = 1; i < m && x == 1; ++i) {
        for (let j = 0; j < n; ++j) {
            if (grid[i][j] == '*') {
                q.push([i, j]);
                x = 0;
                break;
            }
        }
    }
    let ans = 0;
    while (q.length) {
        ++ans;
        for (let t = q.length; t > 0; --t) {
            const [i, j] = q.shift();
            for (let k = 0; k < 4; ++k) {
                const x = i + dirs[k];
                const y = j + dirs[k + 1];
                if (x >= 0 && x < m && y >= 0 && y < n) {
                    if (grid[x][y] == '#') {
                        return ans;
                    }
                    if (grid[x][y] == 'O') {
                        grid[x][y] = 'X';
                        q.push([x, y]);
                    }
                }
            }
        }
    }
    return -1;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1731. 每位经理的下属员工数量](https://leetcode.cn/problems/the-number-of-employees-which-report-to-each-employee){#1731}

{{< tabs "1731" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT
    e2.employee_id,
    e2.name,
    COUNT(1) AS reports_count,
    ROUND(AVG(e1.age)) AS average_age
FROM
    Employees AS e1
    JOIN Employees AS e2 ON e1.reports_to = e2.employee_id
GROUP BY 1
ORDER BY 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code>Employees</code></p>

<pre>
+-------------+----------+
| Column Name | Type     |
+-------------+----------+
| employee_id | int      |
| name        | varchar  |
| reports_to  | int      |
| age         | int      |
+-------------+----------+
employee_id 是这个表中具有不同值的列。
该表包含员工以及需要听取他们汇报的上级经理的 ID 的信息。 有些员工不需要向任何人汇报（reports_to 为空）。
</pre>

<p>&nbsp;</p>

<p>对于此问题，我们将至少有一个其他员工需要向他汇报的员工，视为一个经理。</p>

<p>编写一个解决方案来返回需要听取汇报的所有经理的 ID、名称、直接向该经理汇报的员工人数，以及这些员工的平均年龄，其中该平均年龄需要四舍五入到最接近的整数。</p>

<p>返回的结果集需要按照&nbsp;<code>employee_id</code> 进行排序。</p>

<p>结果的格式如下：</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入：</strong>
Employees 表：
+-------------+---------+------------+-----+
| employee_id | name    | reports_to | age |
+-------------+---------+------------+-----+
| 9           | Hercy   | null       | 43  |
| 6           | Alice   | 9          | 41  |
| 4           | Bob     | 9          | 36  |
| 2           | Winston | null       | 37  |
+-------------+---------+------------+-----+
<strong>输出：</strong>
+-------------+-------+---------------+-------------+
| employee_id | name  | reports_count | average_age |
+-------------+-------+---------------+-------------+
| 9           | Hercy | 2             | 39          |
+-------------+-------+---------------+-------------+
<strong>解释：
</strong>Hercy 有两个需要向他汇报的员工, 他们是 Alice and Bob. 他们的平均年龄是 (41+36)/2 = 38.5, 四舍五入的结果是 39.
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入：</strong> 
Employees 表：
+-------------+---------+------------+-----+ 
| employee_id | name &nbsp; &nbsp;| reports_to | age |
|-------------|---------|------------|-----|
| 1 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; | Michael | null &nbsp; &nbsp; &nbsp; | 45 &nbsp;|
| 2 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; | Alice &nbsp; | 1 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;| 38 &nbsp;|
| 3 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; | Bob &nbsp; &nbsp; | 1 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;| 42 &nbsp;|
| 4 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; | Charlie | 2 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;| 34 &nbsp;|
| 5 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; | David &nbsp; | 2 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;| 40 &nbsp;|
| 6 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; | Eve &nbsp; &nbsp; | 3 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;| 37 &nbsp;|
| 7 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; | Frank &nbsp; | null &nbsp; &nbsp; &nbsp; | 50 &nbsp;|
| 8 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; | Grace &nbsp; | null &nbsp; &nbsp; &nbsp; | 48 &nbsp;|
+-------------+---------+------------+-----+ 
<strong>输出：</strong> 
+-------------+---------+---------------+-------------+
| employee_id | name &nbsp; &nbsp;| reports_count | average_age |
| ----------- | ------- | ------------- | ----------- |
| 1 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; | Michael | 2 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; | 40 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;|
| 2 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; | Alice &nbsp; | 2 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; | 37 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;|
| 3 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; | Bob &nbsp; &nbsp; | 1 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; | 37 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;|
+-------------+---------+---------------+-------------+</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：自连接 + 分组统计

我们可以通过自连接的方式，将每个员工的上级经理信息连接到每个员工的信息上，然后再通过分组统计的方式，统计每个经理的下属员工数量和平均年龄。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT
    e2.employee_id,
    e2.name,
    COUNT(1) AS reports_count,
    ROUND(AVG(e1.age)) AS average_age
FROM
    Employees AS e1
    JOIN Employees AS e2 ON e1.reports_to = e2.employee_id
GROUP BY 1
ORDER BY 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1732. 找到最高海拔](https://leetcode.cn/problems/find-the-highest-altitude){#1732}

{{< tabs "1732" >}}

{{% tab "python" %}}
```python
class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        return max(accumulate(gain, initial=0))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int largestAltitude(int[] gain) {
        int ans = 0, h = 0;
        for (int v : gain) {
            h += v;
            ans = Math.max(ans, h);
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
    int largestAltitude(vector<int>& gain) {
        int ans = 0, h = 0;
        for (int v : gain) h += v, ans = max(ans, h);
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func largestAltitude(gain []int) (ans int) {
	h := 0
	for _, v := range gain {
		h += v
		if ans < h {
			ans = h
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn largest_altitude(gain: Vec<i32>) -> i32 {
        let mut ans = 0;
        let mut h = 0;
        for v in gain.iter() {
            h += v;
            ans = ans.max(h);
        }
        ans
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} gain
 * @return {number}
 */
var largestAltitude = function (gain) {
    let ans = 0;
    let h = 0;
    for (const v of gain) {
        h += v;
        ans = Math.max(ans, h);
    }
    return ans;
};
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param Integer[] $gain
     * @return Integer
     */
    function largestAltitude($gain) {
        $max = 0;
        for ($i = 0; $i < count($gain); $i++) {
            $tmp += $gain[$i];
            if ($tmp > $max) {
                $max = $tmp;
            }
        }
        return $max;
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
#define max(a, b) (((a) > (b)) ? (a) : (b))

int largestAltitude(int* gain, int gainSize) {
    int ans = 0;
    int h = 0;
    for (int i = 0; i < gainSize; i++) {
        h += gain[i];
        ans = max(ans, h);
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

<p>有一个自行车手打算进行一场公路骑行，这条路线总共由 <code>n + 1</code> 个不同海拔的点组成。自行车手从海拔为 <code>0</code> 的点 <code>0</code> 开始骑行。</p>

<p>给你一个长度为 <code>n</code> 的整数数组 <code>gain</code> ，其中 <code>gain[i]</code> 是点 <code>i</code> 和点 <code>i + 1</code> 的 <strong>净海拔高度差</strong>（<code>0 <= i < n</code>）。请你返回 <strong>最高点的海拔</strong> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>gain = [-5,1,5,0,-7]
<b>输出：</b>1
<b>解释：</b>海拔高度依次为 [0,-5,-4,1,1,-6] 。最高海拔为 1 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>gain = [-4,-3,-2,-1,4,3,2]
<b>输出：</b>0
<b>解释：</b>海拔高度依次为 [0,-4,-7,-9,-10,-6,-3,-1] 。最高海拔为 0 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == gain.length</code></li>
	<li><code>1 <= n <= 100</code></li>
	<li><code>-100 <= gain[i] <= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前缀和（差分数组）

我们假设每个点的海拔为 $h_i$，由于 $gain[i]$ 表示第 $i$ 个点和第 $i + 1$ 个点的海拔差，因此 $gain[i] = h_{i + 1} - h_i$。那么：

$$
\sum_{i = 0}^{n-1} gain[i] = h_1 - h_0 + h_2 - h_1 + \cdots + h_n - h_{n - 1} = h_n - h_0 = h_n
$$

即：

$$
h_{i+1} = \sum_{j = 0}^{i} gain[j]
$$

可以发现，每个点的海拔都可以通过前缀和的方式计算出来。因此，我们只需要遍历一遍数组，求出前缀和的最大值，即为最高点的海拔。

> 实际上题目中的 $gain$ 数组是一个差分数组，对差分数组求前缀和即可得到原海拔数组。然后求出原海拔数组的最大值即可。

时间复杂度 $O(n)$，空间复杂度 $O(1)$。其中 $n$ 为数组 $gain$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        return max(accumulate(gain, initial=0))
```

#### Java

```java
class Solution {
    public int largestAltitude(int[] gain) {
        int ans = 0, h = 0;
        for (int v : gain) {
            h += v;
            ans = Math.max(ans, h);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0, h = 0;
        for (int v : gain) h += v, ans = max(ans, h);
        return ans;
    }
};
```

#### Go

```go
func largestAltitude(gain []int) (ans int) {
	h := 0
	for _, v := range gain {
		h += v
		if ans < h {
			ans = h
		}
	}
	return
}
```

#### Rust

```rust
impl Solution {
    pub fn largest_altitude(gain: Vec<i32>) -> i32 {
        let mut ans = 0;
        let mut h = 0;
        for v in gain.iter() {
            h += v;
            ans = ans.max(h);
        }
        ans
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} gain
 * @return {number}
 */
var largestAltitude = function (gain) {
    let ans = 0;
    let h = 0;
    for (const v of gain) {
        h += v;
        ans = Math.max(ans, h);
    }
    return ans;
};
```

#### PHP

```php
class Solution {
    /**
     * @param Integer[] $gain
     * @return Integer
     */
    function largestAltitude($gain) {
        $max = 0;
        for ($i = 0; $i < count($gain); $i++) {
            $tmp += $gain[$i];
            if ($tmp > $max) {
                $max = $tmp;
            }
        }
        return $max;
    }
}
```

#### C

```c
#define max(a, b) (((a) > (b)) ? (a) : (b))

int largestAltitude(int* gain, int gainSize) {
    int ans = 0;
    int h = 0;
    for (int i = 0; i < gainSize; i++) {
        h += gain[i];
        ans = max(ans, h);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1733. 需要教语言的最少人数](https://leetcode.cn/problems/minimum-number-of-people-to-teach){#1733}

{{< tabs "1733" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumTeachings(
        self, n: int, languages: List[List[int]], friendships: List[List[int]]
    ) -> int:
        def check(u: int, v: int) -> bool:
            for x in languages[u - 1]:
                for y in languages[v - 1]:
                    if x == y:
                        return True
            return False

        s = set()
        for u, v in friendships:
            if not check(u, v):
                s.add(u)
                s.add(v)
        cnt = Counter()
        for u in s:
            for l in languages[u - 1]:
                cnt[l] += 1
        return len(s) - max(cnt.values(), default=0)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumTeachings(int n, int[][] languages, int[][] friendships) {
        Set<Integer> s = new HashSet<>();
        for (var e : friendships) {
            int u = e[0], v = e[1];
            if (!check(u, v, languages)) {
                s.add(u);
                s.add(v);
            }
        }
        if (s.isEmpty()) {
            return 0;
        }
        int[] cnt = new int[n + 1];
        for (int u : s) {
            for (int l : languages[u - 1]) {
                ++cnt[l];
            }
        }
        int mx = 0;
        for (int v : cnt) {
            mx = Math.max(mx, v);
        }
        return s.size() - mx;
    }

    private boolean check(int u, int v, int[][] languages) {
        for (int x : languages[u - 1]) {
            for (int y : languages[v - 1]) {
                if (x == y) {
                    return true;
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
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_set<int> s;
        auto check = [&](int u, int v) {
            for (int x : languages[u - 1]) {
                for (int y : languages[v - 1]) {
                    if (x == y) {
                        return true;
                    }
                }
            }
            return false;
        };
        for (auto& e : friendships) {
            int u = e[0], v = e[1];
            if (!check(u, v)) {
                s.insert(u);
                s.insert(v);
            }
        }
        if (s.empty()) {
            return 0;
        }
        vector<int> cnt(n + 1);
        for (int u : s) {
            for (int& l : languages[u - 1]) {
                ++cnt[l];
            }
        }
        return s.size() - ranges::max(cnt);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumTeachings(n int, languages [][]int, friendships [][]int) int {
	check := func(u, v int) bool {
		for _, x := range languages[u-1] {
			for _, y := range languages[v-1] {
				if x == y {
					return true
				}
			}
		}
		return false
	}
	s := map[int]bool{}
	for _, e := range friendships {
		u, v := e[0], e[1]
		if !check(u, v) {
			s[u], s[v] = true, true
		}
	}
	if len(s) == 0 {
		return 0
	}
	cnt := make([]int, n+1)
	for u := range s {
		for _, l := range languages[u-1] {
			cnt[l]++
		}
	}
	return len(s) - slices.Max(cnt)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumTeachings(n: number, languages: number[][], friendships: number[][]): number {
    function check(u: number, v: number): boolean {
        for (const x of languages[u - 1]) {
            for (const y of languages[v - 1]) {
                if (x === y) {
                    return true;
                }
            }
        }
        return false;
    }

    const s = new Set<number>();
    for (const [u, v] of friendships) {
        if (!check(u, v)) {
            s.add(u);
            s.add(v);
        }
    }

    const cnt = new Map<number, number>();
    for (const u of s) {
        for (const l of languages[u - 1]) {
            cnt.set(l, (cnt.get(l) || 0) + 1);
        }
    }

    return s.size - Math.max(0, ...cnt.values());
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::{HashSet, HashMap};

impl Solution {
    pub fn minimum_teachings(n: i32, languages: Vec<Vec<i32>>, friendships: Vec<Vec<i32>>) -> i32 {
        fn check(u: usize, v: usize, languages: &Vec<Vec<i32>>) -> bool {
            for &x in &languages[u - 1] {
                for &y in &languages[v - 1] {
                    if x == y {
                        return true;
                    }
                }
            }
            false
        }

        let mut s: HashSet<usize> = HashSet::new();
        for edge in friendships.iter() {
            let u = edge[0] as usize;
            let v = edge[1] as usize;
            if !check(u, v, &languages) {
                s.insert(u);
                s.insert(v);
            }
        }

        let mut cnt: HashMap<i32, i32> = HashMap::new();
        for &u in s.iter() {
            for &l in &languages[u - 1] {
                *cnt.entry(l).or_insert(0) += 1;
            }
        }

        let mx = cnt.values().cloned().max().unwrap_or(0);
        (s.len() as i32) - mx
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>在一个由 <code>m</code> 个用户组成的社交网络里，我们获取到一些用户之间的好友关系。两个用户之间可以相互沟通的条件是他们都掌握同一门语言。</p>

<p>给你一个整数 <code>n</code> ，数组 <code>languages</code> 和数组 <code>friendships</code> ，它们的含义如下：</p>

<ul>
	<li>总共有 <code>n</code> 种语言，编号从 <code>1</code> 到 <code>n</code> 。</li>
	<li><code>languages[i]</code> 是第 <code>i</code> 位用户掌握的语言集合。</li>
	<li><code>friendships[i] = [u<sub>​​​​​​i</sub>​​​, v<sub>​​​​​​i</sub>]</code> 表示 <code>u<sup>​​​​​</sup><sub>​​​​​​i</sub></code>​​​​​ 和 <code>v<sub>i</sub></code> 为好友关系。</li>
</ul>

<p>你可以选择 <strong>一门</strong> 语言并教会一些用户，使得所有好友之间都可以相互沟通。请返回你 <strong>最少</strong> 需要教会多少名用户。</p>
请注意，好友关系没有传递性，也就是说如果 <code>x</code> 和 <code>y</code> 是好友，且 <code>y</code> 和 <code>z</code> 是好友， <code>x</code> 和 <code>z</code> 不一定是好友。

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>n = 2, languages = [[1],[2],[1,2]], friendships = [[1,2],[1,3],[2,3]]
<b>输出：</b>1
<b>解释：</b>你可以选择教用户 1 第二门语言，也可以选择教用户 2 第一门语言。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>n = 3, languages = [[2],[1,3],[1,2],[3]], friendships = [[1,4],[1,2],[3,4],[2,3]]
<b>输出：</b>2
<b>解释：</b>教用户 1 和用户 3 第三门语言，需要教 2 名用户。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 <= n <= 500</code></li>
	<li><code>languages.length == m</code></li>
	<li><code>1 <= m <= 500</code></li>
	<li><code>1 <= languages[i].length <= n</code></li>
	<li><code>1 <= languages[i][j] <= n</code></li>
	<li><code>1 <= u<sub>​​​​​​i</sub> < v<sub>​​​​​​i</sub> <= languages.length</code></li>
	<li><code>1 <= friendships.length <= 500</code></li>
	<li>所有的好友关系 <code>(u<sub>​​​​​i, </sub>v<sub>​​​​​​i</sub>)</code> 都是唯一的。</li>
	<li><code>languages[i]</code> 中包含的值互不相同。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟 + 统计

对于每个好友关系，如果两个人掌握的语言集合不相交，则需要教一门语言，使得两个人可以相互沟通，我们将这些人放入一个哈希集合 $s$ 中。

然后在这个集合 $s$ 中，统计每种语言掌握的人数，获取最大的人数，我们记为 $mx$，那么答案就是 $|s| - mx$。其中 $|s|$ 表示集合 $s$ 的大小。

时间复杂度 $O(m^2 \times k)$。其中 $m$ 为语言的数量，而 $k$ 为好友关系的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumTeachings(
        self, n: int, languages: List[List[int]], friendships: List[List[int]]
    ) -> int:
        def check(u: int, v: int) -> bool:
            for x in languages[u - 1]:
                for y in languages[v - 1]:
                    if x == y:
                        return True
            return False

        s = set()
        for u, v in friendships:
            if not check(u, v):
                s.add(u)
                s.add(v)
        cnt = Counter()
        for u in s:
            for l in languages[u - 1]:
                cnt[l] += 1
        return len(s) - max(cnt.values(), default=0)
```

#### Java

```java
class Solution {
    public int minimumTeachings(int n, int[][] languages, int[][] friendships) {
        Set<Integer> s = new HashSet<>();
        for (var e : friendships) {
            int u = e[0], v = e[1];
            if (!check(u, v, languages)) {
                s.add(u);
                s.add(v);
            }
        }
        if (s.isEmpty()) {
            return 0;
        }
        int[] cnt = new int[n + 1];
        for (int u : s) {
            for (int l : languages[u - 1]) {
                ++cnt[l];
            }
        }
        int mx = 0;
        for (int v : cnt) {
            mx = Math.max(mx, v);
        }
        return s.size() - mx;
    }

    private boolean check(int u, int v, int[][] languages) {
        for (int x : languages[u - 1]) {
            for (int y : languages[v - 1]) {
                if (x == y) {
                    return true;
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
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_set<int> s;
        auto check = [&](int u, int v) {
            for (int x : languages[u - 1]) {
                for (int y : languages[v - 1]) {
                    if (x == y) {
                        return true;
                    }
                }
            }
            return false;
        };
        for (auto& e : friendships) {
            int u = e[0], v = e[1];
            if (!check(u, v)) {
                s.insert(u);
                s.insert(v);
            }
        }
        if (s.empty()) {
            return 0;
        }
        vector<int> cnt(n + 1);
        for (int u : s) {
            for (int& l : languages[u - 1]) {
                ++cnt[l];
            }
        }
        return s.size() - ranges::max(cnt);
    }
};
```

#### Go

```go
func minimumTeachings(n int, languages [][]int, friendships [][]int) int {
	check := func(u, v int) bool {
		for _, x := range languages[u-1] {
			for _, y := range languages[v-1] {
				if x == y {
					return true
				}
			}
		}
		return false
	}
	s := map[int]bool{}
	for _, e := range friendships {
		u, v := e[0], e[1]
		if !check(u, v) {
			s[u], s[v] = true, true
		}
	}
	if len(s) == 0 {
		return 0
	}
	cnt := make([]int, n+1)
	for u := range s {
		for _, l := range languages[u-1] {
			cnt[l]++
		}
	}
	return len(s) - slices.Max(cnt)
}
```

#### TypeScript

```ts
function minimumTeachings(n: number, languages: number[][], friendships: number[][]): number {
    function check(u: number, v: number): boolean {
        for (const x of languages[u - 1]) {
            for (const y of languages[v - 1]) {
                if (x === y) {
                    return true;
                }
            }
        }
        return false;
    }

    const s = new Set<number>();
    for (const [u, v] of friendships) {
        if (!check(u, v)) {
            s.add(u);
            s.add(v);
        }
    }

    const cnt = new Map<number, number>();
    for (const u of s) {
        for (const l of languages[u - 1]) {
            cnt.set(l, (cnt.get(l) || 0) + 1);
        }
    }

    return s.size - Math.max(0, ...cnt.values());
}
```

#### Rust

```rust
use std::collections::{HashSet, HashMap};

impl Solution {
    pub fn minimum_teachings(n: i32, languages: Vec<Vec<i32>>, friendships: Vec<Vec<i32>>) -> i32 {
        fn check(u: usize, v: usize, languages: &Vec<Vec<i32>>) -> bool {
            for &x in &languages[u - 1] {
                for &y in &languages[v - 1] {
                    if x == y {
                        return true;
                    }
                }
            }
            false
        }

        let mut s: HashSet<usize> = HashSet::new();
        for edge in friendships.iter() {
            let u = edge[0] as usize;
            let v = edge[1] as usize;
            if !check(u, v, &languages) {
                s.insert(u);
                s.insert(v);
            }
        }

        let mut cnt: HashMap<i32, i32> = HashMap::new();
        for &u in s.iter() {
            for &l in &languages[u - 1] {
                *cnt.entry(l).or_insert(0) += 1;
            }
        }

        let mx = cnt.values().cloned().max().unwrap_or(0);
        (s.len() as i32) - mx
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1734. 解码异或后的排列](https://leetcode.cn/problems/decode-xored-permutation){#1734}

{{< tabs "1734" >}}

{{% tab "python" %}}
```python
class Solution:
    def decode(self, encoded: List[int]) -> List[int]:
        n = len(encoded) + 1
        a = b = 0
        for i in range(0, n - 1, 2):
            a ^= encoded[i]
        for i in range(1, n + 1):
            b ^= i
        perm = [0] * n
        perm[-1] = a ^ b
        for i in range(n - 2, -1, -1):
            perm[i] = encoded[i] ^ perm[i + 1]
        return perm
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] decode(int[] encoded) {
        int n = encoded.length + 1;
        int a = 0, b = 0;
        for (int i = 0; i < n - 1; i += 2) {
            a ^= encoded[i];
        }
        for (int i = 1; i <= n; ++i) {
            b ^= i;
        }
        int[] perm = new int[n];
        perm[n - 1] = a ^ b;
        for (int i = n - 2; i >= 0; --i) {
            perm[i] = encoded[i] ^ perm[i + 1];
        }
        return perm;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int n = encoded.size() + 1;
        int a = 0, b = 0;
        for (int i = 0; i < n - 1; i += 2) {
            a ^= encoded[i];
        }
        for (int i = 1; i <= n; ++i) {
            b ^= i;
        }
        vector<int> perm(n);
        perm[n - 1] = a ^ b;
        for (int i = n - 2; ~i; --i) {
            perm[i] = encoded[i] ^ perm[i + 1];
        }
        return perm;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func decode(encoded []int) []int {
	n := len(encoded) + 1
	a, b := 0, 0
	for i := 0; i < n-1; i += 2 {
		a ^= encoded[i]
	}
	for i := 1; i <= n; i++ {
		b ^= i
	}
	perm := make([]int, n)
	perm[n-1] = a ^ b
	for i := n - 2; i >= 0; i-- {
		perm[i] = encoded[i] ^ perm[i+1]
	}
	return perm
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>perm</code> ，它是前 <code>n</code> 个正整数的排列，且 <code>n</code> 是个 <strong>奇数</strong> 。</p>

<p>它被加密成另一个长度为 <code>n - 1</code> 的整数数组 <code>encoded</code> ，满足 <code>encoded[i] = perm[i] XOR perm[i + 1]</code> 。比方说，如果 <code>perm = [1,3,2]</code> ，那么 <code>encoded = [2,1]</code> 。</p>

<p>给你 <code>encoded</code> 数组，请你返回原始数组 <code>perm</code> 。题目保证答案存在且唯一。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>encoded = [3,1]
<b>输出：</b>[1,2,3]
<b>解释：</b>如果 perm = [1,2,3] ，那么 encoded = [1 XOR 2,2 XOR 3] = [3,1]
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>encoded = [6,5,4,6]
<b>输出：</b>[2,4,1,5,3]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= n &lt; 10<sup>5</sup></code></li>
	<li><code>n</code> 是奇数。</li>
	<li><code>encoded.length == n - 1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：位运算

我们注意到，数组 $perm$ 是前 $n$ 个正整数的排列，因此 $perm$ 的所有元素的异或和为 $1 \oplus 2 \oplus \cdots \oplus n$，记为 $a$。而 $encode[i]=perm[i] \oplus perm[i+1]$，如果我们将 $encode[0],encode[2],\cdots,encode[n-3]$ 的所有元素的异或和记为 $b$，则 $perm[n-1]=a \oplus b$。知道了 $perm$ 的最后一个元素，我们就可以通过逆序遍历数组 $encode$ 求出 $perm$ 的所有元素。

时间复杂度 $O(n)$，其中 $n$ 为数组 $perm$ 的长度。忽略答案数组的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def decode(self, encoded: List[int]) -> List[int]:
        n = len(encoded) + 1
        a = b = 0
        for i in range(0, n - 1, 2):
            a ^= encoded[i]
        for i in range(1, n + 1):
            b ^= i
        perm = [0] * n
        perm[-1] = a ^ b
        for i in range(n - 2, -1, -1):
            perm[i] = encoded[i] ^ perm[i + 1]
        return perm
```

#### Java

```java
class Solution {
    public int[] decode(int[] encoded) {
        int n = encoded.length + 1;
        int a = 0, b = 0;
        for (int i = 0; i < n - 1; i += 2) {
            a ^= encoded[i];
        }
        for (int i = 1; i <= n; ++i) {
            b ^= i;
        }
        int[] perm = new int[n];
        perm[n - 1] = a ^ b;
        for (int i = n - 2; i >= 0; --i) {
            perm[i] = encoded[i] ^ perm[i + 1];
        }
        return perm;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int n = encoded.size() + 1;
        int a = 0, b = 0;
        for (int i = 0; i < n - 1; i += 2) {
            a ^= encoded[i];
        }
        for (int i = 1; i <= n; ++i) {
            b ^= i;
        }
        vector<int> perm(n);
        perm[n - 1] = a ^ b;
        for (int i = n - 2; ~i; --i) {
            perm[i] = encoded[i] ^ perm[i + 1];
        }
        return perm;
    }
};
```

#### Go

```go
func decode(encoded []int) []int {
	n := len(encoded) + 1
	a, b := 0, 0
	for i := 0; i < n-1; i += 2 {
		a ^= encoded[i]
	}
	for i := 1; i <= n; i++ {
		b ^= i
	}
	perm := make([]int, n)
	perm[n-1] = a ^ b
	for i := n - 2; i >= 0; i-- {
		perm[i] = encoded[i] ^ perm[i+1]
	}
	return perm
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1735. 生成乘积数组的方案数](https://leetcode.cn/problems/count-ways-to-make-array-with-product){#1735}

{{< tabs "1735" >}}

{{% tab "python" %}}
```python
N = 10020
MOD = 10**9 + 7
f = [1] * N
g = [1] * N
p = defaultdict(list)
for i in range(1, N):
    f[i] = f[i - 1] * i % MOD
    g[i] = pow(f[i], MOD - 2, MOD)
    x = i
    j = 2
    while j <= x // j:
        if x % j == 0:
            cnt = 0
            while x % j == 0:
                cnt += 1
                x //= j
            p[i].append(cnt)
        j += 1
    if x > 1:
        p[i].append(1)


def comb(n, k):
    return f[n] * g[k] * g[n - k] % MOD


class Solution:
    def waysToFillArray(self, queries: List[List[int]]) -> List[int]:
        ans = []
        for n, k in queries:
            t = 1
            for x in p[k]:
                t = t * comb(x + n - 1, n - 1) % MOD
            ans.append(t)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private static final int N = 10020;
    private static final int MOD = (int) 1e9 + 7;
    private static final long[] F = new long[N];
    private static final long[] G = new long[N];
    private static final List<Integer>[] P = new List[N];

    static {
        F[0] = 1;
        G[0] = 1;
        Arrays.setAll(P, k -> new ArrayList<>());
        for (int i = 1; i < N; ++i) {
            F[i] = F[i - 1] * i % MOD;
            G[i] = qmi(F[i], MOD - 2, MOD);
            int x = i;
            for (int j = 2; j <= x / j; ++j) {
                if (x % j == 0) {
                    int cnt = 0;
                    while (x % j == 0) {
                        ++cnt;
                        x /= j;
                    }
                    P[i].add(cnt);
                }
            }
            if (x > 1) {
                P[i].add(1);
            }
        }
    }

    public static long qmi(long a, long k, long p) {
        long res = 1;
        while (k != 0) {
            if ((k & 1) == 1) {
                res = res * a % p;
            }
            k >>= 1;
            a = a * a % p;
        }
        return res;
    }

    public static long comb(int n, int k) {
        return (F[n] * G[k] % MOD) * G[n - k] % MOD;
    }

    public int[] waysToFillArray(int[][] queries) {
        int m = queries.length;
        int[] ans = new int[m];
        for (int i = 0; i < m; ++i) {
            int n = queries[i][0], k = queries[i][1];
            long t = 1;
            for (int x : P[k]) {
                t = t * comb(x + n - 1, n - 1) % MOD;
            }
            ans[i] = (int) t;
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
int N = 10020;
int MOD = 1e9 + 7;
long f[10020];
long g[10020];
vector<int> p[10020];

long qmi(long a, long k, long p) {
    long res = 1;
    while (k != 0) {
        if ((k & 1) == 1) {
            res = res * a % p;
        }
        k >>= 1;
        a = a * a % p;
    }
    return res;
}

int init = []() {
    f[0] = 1;
    g[0] = 1;
    for (int i = 1; i < N; ++i) {
        f[i] = f[i - 1] * i % MOD;
        g[i] = qmi(f[i], MOD - 2, MOD);
        int x = i;
        for (int j = 2; j <= x / j; ++j) {
            if (x % j == 0) {
                int cnt = 0;
                while (x % j == 0) {
                    ++cnt;
                    x /= j;
                }
                p[i].push_back(cnt);
            }
        }
        if (x > 1) {
            p[i].push_back(1);
        }
    }
    return 0;
}();

int comb(int n, int k) {
    return (f[n] * g[k] % MOD) * g[n - k] % MOD;
}

class Solution {
public:
    vector<int> waysToFillArray(vector<vector<int>>& queries) {
        vector<int> ans;
        for (auto& q : queries) {
            int n = q[0], k = q[1];
            long long t = 1;
            for (int x : p[k]) {
                t = t * comb(x + n - 1, n - 1) % MOD;
            }
            ans.push_back(t);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
const n = 1e4 + 20
const mod = 1e9 + 7

var f = make([]int, n)
var g = make([]int, n)
var p = make([][]int, n)

func qmi(a, k, p int) int {
	res := 1
	for k != 0 {
		if k&1 == 1 {
			res = res * a % p
		}
		k >>= 1
		a = a * a % p
	}
	return res
}

func init() {
	f[0], g[0] = 1, 1
	for i := 1; i < n; i++ {
		f[i] = f[i-1] * i % mod
		g[i] = qmi(f[i], mod-2, mod)
		x := i
		for j := 2; j <= x/j; j++ {
			if x%j == 0 {
				cnt := 0
				for x%j == 0 {
					cnt++
					x /= j
				}
				p[i] = append(p[i], cnt)
			}
		}
		if x > 1 {
			p[i] = append(p[i], 1)
		}
	}
}

func comb(n, k int) int {
	return (f[n] * g[k] % mod) * g[n-k] % mod
}

func waysToFillArray(queries [][]int) (ans []int) {
	for _, q := range queries {
		n, k := q[0], q[1]
		t := 1
		for _, x := range p[k] {
			t = t * comb(x+n-1, n-1) % mod
		}
		ans = append(ans, t)
	}
	return
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个二维整数数组 <code>queries</code> ，其中 <code>queries[i] = [n<sub>i</sub>, k<sub>i</sub>]</code> 。第 <code>i</code> 个查询 <code>queries[i]</code> 要求构造长度为 <code>n<sub>i</sub></code> 、每个元素都是正整数的数组，且满足所有元素的乘积为 <code>k<sub>i</sub></code><sub> </sub>，请你找出有多少种可行的方案。由于答案可能会很大，方案数需要对 <code>10<sup>9</sup> + 7</code> <strong>取余</strong> 。</p>

<p>请你返回一个整数数组<em> </em><code>answer</code>，满足<em> </em><code>answer.length == queries.length</code> ，其中<em> </em><code>answer[i]</code>是第<em> </em><code>i</code> 个查询的结果。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>queries = [[2,6],[5,1],[73,660]]
<b>输出：</b>[4,1,50734910]
<b>解释：</b>每个查询之间彼此独立。
[2,6]：总共有 4 种方案得到长度为 2 且乘积为 6 的数组：[1,6]，[2,3]，[3,2]，[6,1]。
[5,1]：总共有 1 种方案得到长度为 5 且乘积为 1 的数组：[1,1,1,1,1]。
[73,660]：总共有 1050734917 种方案得到长度为 73 且乘积为 660 的数组。1050734917 对 10<sup>9</sup> + 7 取余得到 50734910 。
</pre>

<p><strong>示例 2 ：</strong></p>

<pre>
<b>输入：</b>queries = [[1,1],[2,2],[3,3],[4,4],[5,5]]
<b>输出：</b>[1,2,3,10,5]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= queries.length <= 10<sup>4</sup> </code></li>
	<li><code>1 <= n<sub>i</sub>, k<sub>i</sub> <= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：质因数分解 + 组合数学

我们可以对 $k$ 进行质因数分解，即 $k = p_1^{x_1} \times p_2^{x_2} \times \cdots \times p_m^{x_m}$，其中 $p_i$ 为质数，而 $x_i$ 为 $p_i$ 的指数。那么题目实际上等价于：把 $x_1$ 个 $p_1$, $x_2$ 个 $p_2$, $\cdots$, $x_m$ 个 $p_m$ 分别放到 $n$ 个位置上，单个位置可以为空，问有多少种方案。

根据组合数学的知识，我们把 $x$ 个球放入 $n$ 个盒子中，有两种情况：

如果盒子不能为空，那么方案数为 $C_{x-1}^{n-1}$，这里是利用隔板法，即一共 $x$ 个球，我们在其中 $x-1$ 个位置插入 $n-1$ 个隔板，从而将 $x$ 个球分成 $n$ 组。

如果盒子可以为空，那么我们可以再增加 $n$ 个虚拟球，然后再利用隔板法，即一共 $x+n$ 个球，我们在其中 $x+n-1$ 个位置插入 $n-1$ 个隔板，从而将实际的 $x$ 个球分成 $n$ 组，并且允许盒子为空，因此方案数为 $C_{x+n-1}^{n-1}$。

因此，对于每个查询 $queries[i]$，我们可以先对 $k$ 进行质因数分解，得到指数 $x_1, x_2, \cdots, x_m$，然后计算 $C_{x_1+n-1}^{n-1}, C_{x_2+n-1}^{n-1}, \cdots, C_{x_m+n-1}^{n-1}$，最后将所有的方案数相乘即可。

所以，问题转化为如何快速计算 $C_m^n$，根据公式 $C_m^n = \frac{m!}{n!(m-n)!}$，我们可以先预处理出 $m!$，然后利用逆元快速计算 $C_m^n$。

时间复杂度 $O(K \times \log \log K + N + m \times \log K)$，空间复杂度 $O(N)$。

<!-- tabs:start -->

#### Python3

```python
N = 10020
MOD = 10**9 + 7
f = [1] * N
g = [1] * N
p = defaultdict(list)
for i in range(1, N):
    f[i] = f[i - 1] * i % MOD
    g[i] = pow(f[i], MOD - 2, MOD)
    x = i
    j = 2
    while j <= x // j:
        if x % j == 0:
            cnt = 0
            while x % j == 0:
                cnt += 1
                x //= j
            p[i].append(cnt)
        j += 1
    if x > 1:
        p[i].append(1)


def comb(n, k):
    return f[n] * g[k] * g[n - k] % MOD


class Solution:
    def waysToFillArray(self, queries: List[List[int]]) -> List[int]:
        ans = []
        for n, k in queries:
            t = 1
            for x in p[k]:
                t = t * comb(x + n - 1, n - 1) % MOD
            ans.append(t)
        return ans
```

#### Java

```java
class Solution {
    private static final int N = 10020;
    private static final int MOD = (int) 1e9 + 7;
    private static final long[] F = new long[N];
    private static final long[] G = new long[N];
    private static final List<Integer>[] P = new List[N];

    static {
        F[0] = 1;
        G[0] = 1;
        Arrays.setAll(P, k -> new ArrayList<>());
        for (int i = 1; i < N; ++i) {
            F[i] = F[i - 1] * i % MOD;
            G[i] = qmi(F[i], MOD - 2, MOD);
            int x = i;
            for (int j = 2; j <= x / j; ++j) {
                if (x % j == 0) {
                    int cnt = 0;
                    while (x % j == 0) {
                        ++cnt;
                        x /= j;
                    }
                    P[i].add(cnt);
                }
            }
            if (x > 1) {
                P[i].add(1);
            }
        }
    }

    public static long qmi(long a, long k, long p) {
        long res = 1;
        while (k != 0) {
            if ((k & 1) == 1) {
                res = res * a % p;
            }
            k >>= 1;
            a = a * a % p;
        }
        return res;
    }

    public static long comb(int n, int k) {
        return (F[n] * G[k] % MOD) * G[n - k] % MOD;
    }

    public int[] waysToFillArray(int[][] queries) {
        int m = queries.length;
        int[] ans = new int[m];
        for (int i = 0; i < m; ++i) {
            int n = queries[i][0], k = queries[i][1];
            long t = 1;
            for (int x : P[k]) {
                t = t * comb(x + n - 1, n - 1) % MOD;
            }
            ans[i] = (int) t;
        }
        return ans;
    }
}
```

#### C++

```cpp
int N = 10020;
int MOD = 1e9 + 7;
long f[10020];
long g[10020];
vector<int> p[10020];

long qmi(long a, long k, long p) {
    long res = 1;
    while (k != 0) {
        if ((k & 1) == 1) {
            res = res * a % p;
        }
        k >>= 1;
        a = a * a % p;
    }
    return res;
}

int init = []() {
    f[0] = 1;
    g[0] = 1;
    for (int i = 1; i < N; ++i) {
        f[i] = f[i - 1] * i % MOD;
        g[i] = qmi(f[i], MOD - 2, MOD);
        int x = i;
        for (int j = 2; j <= x / j; ++j) {
            if (x % j == 0) {
                int cnt = 0;
                while (x % j == 0) {
                    ++cnt;
                    x /= j;
                }
                p[i].push_back(cnt);
            }
        }
        if (x > 1) {
            p[i].push_back(1);
        }
    }
    return 0;
}();

int comb(int n, int k) {
    return (f[n] * g[k] % MOD) * g[n - k] % MOD;
}

class Solution {
public:
    vector<int> waysToFillArray(vector<vector<int>>& queries) {
        vector<int> ans;
        for (auto& q : queries) {
            int n = q[0], k = q[1];
            long long t = 1;
            for (int x : p[k]) {
                t = t * comb(x + n - 1, n - 1) % MOD;
            }
            ans.push_back(t);
        }
        return ans;
    }
};
```

#### Go

```go
const n = 1e4 + 20
const mod = 1e9 + 7

var f = make([]int, n)
var g = make([]int, n)
var p = make([][]int, n)

func qmi(a, k, p int) int {
	res := 1
	for k != 0 {
		if k&1 == 1 {
			res = res * a % p
		}
		k >>= 1
		a = a * a % p
	}
	return res
}

func init() {
	f[0], g[0] = 1, 1
	for i := 1; i < n; i++ {
		f[i] = f[i-1] * i % mod
		g[i] = qmi(f[i], mod-2, mod)
		x := i
		for j := 2; j <= x/j; j++ {
			if x%j == 0 {
				cnt := 0
				for x%j == 0 {
					cnt++
					x /= j
				}
				p[i] = append(p[i], cnt)
			}
		}
		if x > 1 {
			p[i] = append(p[i], 1)
		}
	}
}

func comb(n, k int) int {
	return (f[n] * g[k] % mod) * g[n-k] % mod
}

func waysToFillArray(queries [][]int) (ans []int) {
	for _, q := range queries {
		n, k := q[0], q[1]
		t := 1
		for _, x := range p[k] {
			t = t * comb(x+n-1, n-1) % mod
		}
		ans = append(ans, t)
	}
	return
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1736. 替换隐藏数字得到的最晚时间](https://leetcode.cn/problems/latest-time-by-replacing-hidden-digits){#1736}

{{< tabs "1736" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumTime(self, time: str) -> str:
        t = list(time)
        if t[0] == '?':
            t[0] = '1' if '4' <= t[1] <= '9' else '2'
        if t[1] == '?':
            t[1] = '3' if t[0] == '2' else '9'
        if t[3] == '?':
            t[3] = '5'
        if t[4] == '?':
            t[4] = '9'
        return ''.join(t)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String maximumTime(String time) {
        char[] t = time.toCharArray();
        if (t[0] == '?') {
            t[0] = t[1] >= '4' && t[1] <= '9' ? '1' : '2';
        }
        if (t[1] == '?') {
            t[1] = t[0] == '2' ? '3' : '9';
        }
        if (t[3] == '?') {
            t[3] = '5';
        }
        if (t[4] == '?') {
            t[4] = '9';
        }
        return new String(t);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string maximumTime(string time) {
        if (time[0] == '?') {
            time[0] = (time[1] >= '4' && time[1] <= '9') ? '1' : '2';
        }
        if (time[1] == '?') {
            time[1] = (time[0] == '2') ? '3' : '9';
        }
        if (time[3] == '?') {
            time[3] = '5';
        }
        if (time[4] == '?') {
            time[4] = '9';
        }
        return time;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumTime(time string) string {
	t := []byte(time)
	if t[0] == '?' {
		if t[1] >= '4' && t[1] <= '9' {
			t[0] = '1'
		} else {
			t[0] = '2'
		}
	}
	if t[1] == '?' {
		if t[0] == '2' {
			t[1] = '3'
		} else {
			t[1] = '9'
		}
	}
	if t[3] == '?' {
		t[3] = '5'
	}
	if t[4] == '?' {
		t[4] = '9'
	}
	return string(t)
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {string} time
 * @return {string}
 */
var maximumTime = function (time) {
    const t = Array.from(time);
    if (t[0] === '?') {
        t[0] = t[1] >= '4' && t[1] <= '9' ? '1' : '2';
    }
    if (t[1] === '?') {
        t[1] = t[0] == '2' ? '3' : '9';
    }
    if (t[3] === '?') {
        t[3] = '5';
    }
    if (t[4] === '?') {
        t[4] = '9';
    }
    return t.join('');
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串 <code>time</code> ，格式为 <code> hh:mm</code>（小时：分钟），其中某几位数字被隐藏（用 <code>?</code> 表示）。</p>

<p>有效的时间为 <code>00:00</code> 到 <code>23:59</code> 之间的所有时间，包括 <code>00:00</code> 和 <code>23:59</code> 。</p>

<p>替换 <code>time</code> 中隐藏的数字，返回你可以得到的最晚有效时间。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>time = "2?:?0"
<strong>输出：</strong>"23:50"
<strong>解释：</strong>以数字 '2' 开头的最晚一小时是 23 ，以 '0' 结尾的最晚一分钟是 50 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>time = "0?:3?"
<strong>输出：</strong>"09:39"
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>time = "1?:22"
<strong>输出：</strong>"19:22"
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>time</code> 的格式为 <code>hh:mm</code></li>
	<li>题目数据保证你可以由输入的字符串生成有效的时间</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心

我们依次处理字符串的每一位，处理的规则如下：

1. 第一位：若第二位的值已确定，且值落在区间 $[4, 9]$ 内，那么第一位只能取 $1$，否则第一位最大取 $2$；
1. 第二位：若第一位的值已确定，且值为 $2$，那么第二位最大取 $3$，否则第二位最大取 $9$；
1. 第三位：第三位最大取 $5$；
1. 第四位：第四位最大取 $9$。

时间复杂度 $O(1)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumTime(self, time: str) -> str:
        t = list(time)
        if t[0] == '?':
            t[0] = '1' if '4' <= t[1] <= '9' else '2'
        if t[1] == '?':
            t[1] = '3' if t[0] == '2' else '9'
        if t[3] == '?':
            t[3] = '5'
        if t[4] == '?':
            t[4] = '9'
        return ''.join(t)
```

#### Java

```java
class Solution {
    public String maximumTime(String time) {
        char[] t = time.toCharArray();
        if (t[0] == '?') {
            t[0] = t[1] >= '4' && t[1] <= '9' ? '1' : '2';
        }
        if (t[1] == '?') {
            t[1] = t[0] == '2' ? '3' : '9';
        }
        if (t[3] == '?') {
            t[3] = '5';
        }
        if (t[4] == '?') {
            t[4] = '9';
        }
        return new String(t);
    }
}
```

#### C++

```cpp
class Solution {
public:
    string maximumTime(string time) {
        if (time[0] == '?') {
            time[0] = (time[1] >= '4' && time[1] <= '9') ? '1' : '2';
        }
        if (time[1] == '?') {
            time[1] = (time[0] == '2') ? '3' : '9';
        }
        if (time[3] == '?') {
            time[3] = '5';
        }
        if (time[4] == '?') {
            time[4] = '9';
        }
        return time;
    }
};
```

#### Go

```go
func maximumTime(time string) string {
	t := []byte(time)
	if t[0] == '?' {
		if t[1] >= '4' && t[1] <= '9' {
			t[0] = '1'
		} else {
			t[0] = '2'
		}
	}
	if t[1] == '?' {
		if t[0] == '2' {
			t[1] = '3'
		} else {
			t[1] = '9'
		}
	}
	if t[3] == '?' {
		t[3] = '5'
	}
	if t[4] == '?' {
		t[4] = '9'
	}
	return string(t)
}
```

#### JavaScript

```js
/**
 * @param {string} time
 * @return {string}
 */
var maximumTime = function (time) {
    const t = Array.from(time);
    if (t[0] === '?') {
        t[0] = t[1] >= '4' && t[1] <= '9' ? '1' : '2';
    }
    if (t[1] === '?') {
        t[1] = t[0] == '2' ? '3' : '9';
    }
    if (t[3] === '?') {
        t[3] = '5';
    }
    if (t[4] === '?') {
        t[4] = '9';
    }
    return t.join('');
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1737. 满足三条件之一需改变的最少字符数](https://leetcode.cn/problems/change-minimum-characters-to-satisfy-one-of-three-conditions){#1737}

{{< tabs "1737" >}}

{{% tab "python" %}}
```python
class Solution:
    def minCharacters(self, a: str, b: str) -> int:
        def f(cnt1, cnt2):
            for i in range(1, 26):
                t = sum(cnt1[i:]) + sum(cnt2[:i])
                nonlocal ans
                ans = min(ans, t)

        m, n = len(a), len(b)
        cnt1 = [0] * 26
        cnt2 = [0] * 26
        for c in a:
            cnt1[ord(c) - ord('a')] += 1
        for c in b:
            cnt2[ord(c) - ord('a')] += 1
        ans = m + n
        for c1, c2 in zip(cnt1, cnt2):
            ans = min(ans, m + n - c1 - c2)
        f(cnt1, cnt2)
        f(cnt2, cnt1)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int ans;

    public int minCharacters(String a, String b) {
        int m = a.length(), n = b.length();
        int[] cnt1 = new int[26];
        int[] cnt2 = new int[26];
        for (int i = 0; i < m; ++i) {
            ++cnt1[a.charAt(i) - 'a'];
        }
        for (int i = 0; i < n; ++i) {
            ++cnt2[b.charAt(i) - 'a'];
        }
        ans = m + n;
        for (int i = 0; i < 26; ++i) {
            ans = Math.min(ans, m + n - cnt1[i] - cnt2[i]);
        }
        f(cnt1, cnt2);
        f(cnt2, cnt1);
        return ans;
    }

    private void f(int[] cnt1, int[] cnt2) {
        for (int i = 1; i < 26; ++i) {
            int t = 0;
            for (int j = i; j < 26; ++j) {
                t += cnt1[j];
            }
            for (int j = 0; j < i; ++j) {
                t += cnt2[j];
            }
            ans = Math.min(ans, t);
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minCharacters(string a, string b) {
        int m = a.size(), n = b.size();
        vector<int> cnt1(26);
        vector<int> cnt2(26);
        for (char& c : a) ++cnt1[c - 'a'];
        for (char& c : b) ++cnt2[c - 'a'];
        int ans = m + n;
        for (int i = 0; i < 26; ++i) ans = min(ans, m + n - cnt1[i] - cnt2[i]);
        auto f = [&](vector<int>& cnt1, vector<int>& cnt2) {
            for (int i = 1; i < 26; ++i) {
                int t = 0;
                for (int j = i; j < 26; ++j) t += cnt1[j];
                for (int j = 0; j < i; ++j) t += cnt2[j];
                ans = min(ans, t);
            }
        };
        f(cnt1, cnt2);
        f(cnt2, cnt1);
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minCharacters(a string, b string) int {
	cnt1 := [26]int{}
	cnt2 := [26]int{}
	for _, c := range a {
		cnt1[c-'a']++
	}
	for _, c := range b {
		cnt2[c-'a']++
	}
	m, n := len(a), len(b)
	ans := m + n
	for i := 0; i < 26; i++ {
		ans = min(ans, m+n-cnt1[i]-cnt2[i])
	}
	f := func(cnt1, cnt2 [26]int) {
		for i := 1; i < 26; i++ {
			t := 0
			for j := i; j < 26; j++ {
				t += cnt1[j]
			}
			for j := 0; j < i; j++ {
				t += cnt2[j]
			}
			ans = min(ans, t)
		}
	}
	f(cnt1, cnt2)
	f(cnt2, cnt1)
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minCharacters(a: string, b: string): number {
    const m = a.length,
        n = b.length;
    let count1 = new Array(26).fill(0);
    let count2 = new Array(26).fill(0);
    const base = 'a'.charCodeAt(0);

    for (let char of a) {
        count1[char.charCodeAt(0) - base]++;
    }
    for (let char of b) {
        count2[char.charCodeAt(0) - base]++;
    }

    let pre1 = 0,
        pre2 = 0;
    let ans = m + n;
    for (let i = 0; i < 25; i++) {
        pre1 += count1[i];
        pre2 += count2[i];
        // case1， case2， case3
        ans = Math.min(ans, m - pre1 + pre2, pre1 + n - pre2, m + n - count1[i] - count2[i]);
    }
    ans = Math.min(ans, m + n - count1[25] - count2[25]);

    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个字符串 <code>a</code> 和 <code>b</code> ，二者均由小写字母组成。一步操作中，你可以将 <code>a</code> 或 <code>b</code> 中的 <strong>任一字符</strong> 改变为 <strong>任一小写字母</strong> 。</p>

<p>操作的最终目标是满足下列三个条件 <strong>之一</strong> ：</p>

<ul>
	<li><code>a</code> 中的 <strong>每个字母</strong> 在字母表中 <strong>严格小于</strong> <code>b</code> 中的 <strong>每个字母</strong> 。</li>
	<li><code>b</code> 中的 <strong>每个字母</strong> 在字母表中 <strong>严格小于</strong> <code>a</code> 中的 <strong>每个字母</strong> 。</li>
	<li><code>a</code> 和 <code>b</code> <strong>都</strong> 由 <strong>同一个</strong> 字母组成。</li>
</ul>

<p>返回达成目标所需的 <strong>最少</strong> 操作数<em>。</em></p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>a = "aba", b = "caa"
<strong>输出：</strong>2
<strong>解释：</strong>满足每个条件的最佳方案分别是：
1) 将 b 变为 "ccc"，2 次操作，满足 a 中的每个字母都小于 b 中的每个字母；
2) 将 a 变为 "bbb" 并将 b 变为 "aaa"，3 次操作，满足 b 中的每个字母都小于 a 中的每个字母；
3) 将 a 变为 "aaa" 并将 b 变为 "aaa"，2 次操作，满足 a 和 b 由同一个字母组成。
最佳的方案只需要 2 次操作（满足条件 1 或者条件 3）。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>a = "dabadd", b = "cda"
<strong>输出：</strong>3
<strong>解释：</strong>满足条件 1 的最佳方案是将 b 变为 "eee" 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= a.length, b.length &lt;= 10<sup>5</sup></code></li>
	<li><code>a</code> 和 <code>b</code> 只由小写字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数 + 枚举

我们先统计字符串 $a$ 和 $b$ 中每个字母出现的次数，记为 $cnt_1$ 和 $cnt_2$。

然后考虑条件 $3$，即 $a$ 和 $b$ 中的每个字母都相同。我们只需要枚举最终的字母 $c$，然后统计 $a$ 和 $b$ 中不是 $c$ 的字母的个数，即为需要改变的字符个数。

然后考虑条件 $1$ 和 $2$，即 $a$ 中的每个字母都小于 $b$ 中的每个字母，或者 $b$ 中的每个字母都小于 $a$ 中的每个字母。对于条件 $1$，我们令字符串 $a$ 所有字符都小于字符 $c$，字符串 $b$ 所有字符都不小于 $c$，枚举 $c$ 找出最小的答案即可。条件 $2$ 同理。

最终的答案即为上述三种情况的最小值。

时间复杂度 $O(m + n + C^2)$，其中 $m$ 和 $n$ 分别为字符串 $a$ 和 $b$ 的长度，而 $C$ 为字符集大小。本题中 $C = 26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minCharacters(self, a: str, b: str) -> int:
        def f(cnt1, cnt2):
            for i in range(1, 26):
                t = sum(cnt1[i:]) + sum(cnt2[:i])
                nonlocal ans
                ans = min(ans, t)

        m, n = len(a), len(b)
        cnt1 = [0] * 26
        cnt2 = [0] * 26
        for c in a:
            cnt1[ord(c) - ord('a')] += 1
        for c in b:
            cnt2[ord(c) - ord('a')] += 1
        ans = m + n
        for c1, c2 in zip(cnt1, cnt2):
            ans = min(ans, m + n - c1 - c2)
        f(cnt1, cnt2)
        f(cnt2, cnt1)
        return ans
```

#### Java

```java
class Solution {
    private int ans;

    public int minCharacters(String a, String b) {
        int m = a.length(), n = b.length();
        int[] cnt1 = new int[26];
        int[] cnt2 = new int[26];
        for (int i = 0; i < m; ++i) {
            ++cnt1[a.charAt(i) - 'a'];
        }
        for (int i = 0; i < n; ++i) {
            ++cnt2[b.charAt(i) - 'a'];
        }
        ans = m + n;
        for (int i = 0; i < 26; ++i) {
            ans = Math.min(ans, m + n - cnt1[i] - cnt2[i]);
        }
        f(cnt1, cnt2);
        f(cnt2, cnt1);
        return ans;
    }

    private void f(int[] cnt1, int[] cnt2) {
        for (int i = 1; i < 26; ++i) {
            int t = 0;
            for (int j = i; j < 26; ++j) {
                t += cnt1[j];
            }
            for (int j = 0; j < i; ++j) {
                t += cnt2[j];
            }
            ans = Math.min(ans, t);
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minCharacters(string a, string b) {
        int m = a.size(), n = b.size();
        vector<int> cnt1(26);
        vector<int> cnt2(26);
        for (char& c : a) ++cnt1[c - 'a'];
        for (char& c : b) ++cnt2[c - 'a'];
        int ans = m + n;
        for (int i = 0; i < 26; ++i) ans = min(ans, m + n - cnt1[i] - cnt2[i]);
        auto f = [&](vector<int>& cnt1, vector<int>& cnt2) {
            for (int i = 1; i < 26; ++i) {
                int t = 0;
                for (int j = i; j < 26; ++j) t += cnt1[j];
                for (int j = 0; j < i; ++j) t += cnt2[j];
                ans = min(ans, t);
            }
        };
        f(cnt1, cnt2);
        f(cnt2, cnt1);
        return ans;
    }
};
```

#### Go

```go
func minCharacters(a string, b string) int {
	cnt1 := [26]int{}
	cnt2 := [26]int{}
	for _, c := range a {
		cnt1[c-'a']++
	}
	for _, c := range b {
		cnt2[c-'a']++
	}
	m, n := len(a), len(b)
	ans := m + n
	for i := 0; i < 26; i++ {
		ans = min(ans, m+n-cnt1[i]-cnt2[i])
	}
	f := func(cnt1, cnt2 [26]int) {
		for i := 1; i < 26; i++ {
			t := 0
			for j := i; j < 26; j++ {
				t += cnt1[j]
			}
			for j := 0; j < i; j++ {
				t += cnt2[j]
			}
			ans = min(ans, t)
		}
	}
	f(cnt1, cnt2)
	f(cnt2, cnt1)
	return ans
}
```

#### TypeScript

```ts
function minCharacters(a: string, b: string): number {
    const m = a.length,
        n = b.length;
    let count1 = new Array(26).fill(0);
    let count2 = new Array(26).fill(0);
    const base = 'a'.charCodeAt(0);

    for (let char of a) {
        count1[char.charCodeAt(0) - base]++;
    }
    for (let char of b) {
        count2[char.charCodeAt(0) - base]++;
    }

    let pre1 = 0,
        pre2 = 0;
    let ans = m + n;
    for (let i = 0; i < 25; i++) {
        pre1 += count1[i];
        pre2 += count2[i];
        // case1， case2， case3
        ans = Math.min(ans, m - pre1 + pre2, pre1 + n - pre2, m + n - count1[i] - count2[i]);
    }
    ans = Math.min(ans, m + n - count1[25] - count2[25]);

    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1738. 找出第 K 大的异或坐标值](https://leetcode.cn/problems/find-kth-largest-xor-coordinate-value){#1738}

{{< tabs "1738" >}}

{{% tab "python" %}}
```python
class Solution:
    def kthLargestValue(self, matrix: List[List[int]], k: int) -> int:
        m, n = len(matrix), len(matrix[0])
        s = [[0] * (n + 1) for _ in range(m + 1)]
        ans = []
        for i in range(m):
            for j in range(n):
                s[i + 1][j + 1] = s[i + 1][j] ^ s[i][j + 1] ^ s[i][j] ^ matrix[i][j]
                ans.append(s[i + 1][j + 1])
        return nlargest(k, ans)[-1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int kthLargestValue(int[][] matrix, int k) {
        int m = matrix.length, n = matrix[0].length;
        int[][] s = new int[m + 1][n + 1];
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                s[i + 1][j + 1] = s[i + 1][j] ^ s[i][j + 1] ^ s[i][j] ^ matrix[i][j];
                ans.add(s[i + 1][j + 1]);
            }
        }
        Collections.sort(ans);
        return ans.get(ans.size() - k);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> s(m + 1, vector<int>(n + 1));
        vector<int> ans;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                s[i + 1][j + 1] = s[i + 1][j] ^ s[i][j + 1] ^ s[i][j] ^ matrix[i][j];
                ans.push_back(s[i + 1][j + 1]);
            }
        }
        sort(ans.begin(), ans.end());
        return ans[ans.size() - k];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func kthLargestValue(matrix [][]int, k int) int {
	m, n := len(matrix), len(matrix[0])
	s := make([][]int, m+1)
	for i := range s {
		s[i] = make([]int, n+1)
	}
	var ans []int
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			s[i+1][j+1] = s[i+1][j] ^ s[i][j+1] ^ s[i][j] ^ matrix[i][j]
			ans = append(ans, s[i+1][j+1])
		}
	}
	sort.Ints(ans)
	return ans[len(ans)-k]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function kthLargestValue(matrix: number[][], k: number): number {
    const m: number = matrix.length;
    const n: number = matrix[0].length;
    const s = Array.from({ length: m + 1 }, () => Array.from({ length: n + 1 }, () => 0));
    const ans: number[] = [];
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            s[i + 1][j + 1] = s[i + 1][j] ^ s[i][j + 1] ^ s[i][j] ^ matrix[i][j];
            ans.push(s[i + 1][j + 1]);
        }
    }
    ans.sort((a, b) => b - a);
    return ans[k - 1];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个二维矩阵 <code>matrix</code> 和一个整数 <code>k</code> ，矩阵大小为&nbsp;<code>m x n</code> 由非负整数组成。</p>

<p>矩阵中坐标 <code>(a, b)</code> 的 <strong>目标值</strong>&nbsp;可以通过对所有元素 <code>matrix[i][j]</code>&nbsp;执行异或运算得到，其中&nbsp;<code>i</code>&nbsp;和&nbsp;<code>j</code> 满足 <code>0 &lt;= i &lt;= a &lt; m</code> 且 <code>0 &lt;= j &lt;= b &lt; n</code>（<strong>下标从 0 开始计数</strong>）。</p>

<p>请你找出&nbsp;<code>matrix</code> 的所有坐标中第 <code>k</code> 大的目标值（<strong><code>k</code> 的值从 1 开始计数</strong>）。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>matrix = [[5,2],[1,6]], k = 1
<strong>输出：</strong>7
<strong>解释：</strong>坐标 (0,1) 的目标值是 5 XOR 2 = 7 ，为最大的目标值。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>matrix = [[5,2],[1,6]], k = 2
<strong>输出：</strong>5
<strong>解释：</strong>坐标 (0,0) 的目标值是 5 = 5 ，为第 2 大的目标值。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>matrix = [[5,2],[1,6]], k = 3
<strong>输出：</strong>4
<strong>解释：</strong>坐标 (1,0) 的目标值是 5 XOR 1 = 4 ，为第 3 大的目标值。</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>matrix = [[5,2],[1,6]], k = 4
<strong>输出：</strong>0
<strong>解释：</strong>坐标 (1,1) 的目标值是 5 XOR 2 XOR 1 XOR 6 = 0 ，为第 4 大的目标值。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == matrix.length</code></li>
	<li><code>n == matrix[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 1000</code></li>
	<li><code>0 &lt;= matrix[i][j] &lt;= 10<sup>6</sup></code></li>
	<li><code>1 &lt;= k &lt;= m * n</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二维前缀异或 + 排序或快速选择

我们定义一个二维前缀异或数组 $s$，其中 $s[i][j]$ 表示矩阵前 $i$ 行和前 $j$ 列的元素异或运算的结果，即：

$$
s[i][j] = \bigoplus_{0 \leq x \leq i, 0 \leq y \leq j} matrix[x][y]
$$

而 $s[i][j]$ 可以由 $s[i - 1][j]$, $s[i][j - 1]$ 和 $s[i - 1][j - 1]$ 三个元素计算得到，即：

$$
s[i][j] = s[i - 1][j] \oplus s[i][j - 1] \oplus s[i - 1][j - 1] \oplus matrix[i - 1][j - 1]
$$

我们遍历矩阵，计算出所有的 $s[i][j]$，然后将其排序，最后返回第 $k$ 大的元素即可。如果不想使用排序，也可以使用快速选择算法，这样可以优化时间复杂度。

时间复杂度 $O(m \times n \times \log (m \times n))$ 或 $O(m \times n)$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别是矩阵的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def kthLargestValue(self, matrix: List[List[int]], k: int) -> int:
        m, n = len(matrix), len(matrix[0])
        s = [[0] * (n + 1) for _ in range(m + 1)]
        ans = []
        for i in range(m):
            for j in range(n):
                s[i + 1][j + 1] = s[i + 1][j] ^ s[i][j + 1] ^ s[i][j] ^ matrix[i][j]
                ans.append(s[i + 1][j + 1])
        return nlargest(k, ans)[-1]
```

#### Java

```java
class Solution {
    public int kthLargestValue(int[][] matrix, int k) {
        int m = matrix.length, n = matrix[0].length;
        int[][] s = new int[m + 1][n + 1];
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                s[i + 1][j + 1] = s[i + 1][j] ^ s[i][j + 1] ^ s[i][j] ^ matrix[i][j];
                ans.add(s[i + 1][j + 1]);
            }
        }
        Collections.sort(ans);
        return ans.get(ans.size() - k);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> s(m + 1, vector<int>(n + 1));
        vector<int> ans;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                s[i + 1][j + 1] = s[i + 1][j] ^ s[i][j + 1] ^ s[i][j] ^ matrix[i][j];
                ans.push_back(s[i + 1][j + 1]);
            }
        }
        sort(ans.begin(), ans.end());
        return ans[ans.size() - k];
    }
};
```

#### Go

```go
func kthLargestValue(matrix [][]int, k int) int {
	m, n := len(matrix), len(matrix[0])
	s := make([][]int, m+1)
	for i := range s {
		s[i] = make([]int, n+1)
	}
	var ans []int
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			s[i+1][j+1] = s[i+1][j] ^ s[i][j+1] ^ s[i][j] ^ matrix[i][j]
			ans = append(ans, s[i+1][j+1])
		}
	}
	sort.Ints(ans)
	return ans[len(ans)-k]
}
```

#### TypeScript

```ts
function kthLargestValue(matrix: number[][], k: number): number {
    const m: number = matrix.length;
    const n: number = matrix[0].length;
    const s = Array.from({ length: m + 1 }, () => Array.from({ length: n + 1 }, () => 0));
    const ans: number[] = [];
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            s[i + 1][j + 1] = s[i + 1][j] ^ s[i][j + 1] ^ s[i][j] ^ matrix[i][j];
            ans.push(s[i + 1][j + 1]);
        }
    }
    ans.sort((a, b) => b - a);
    return ans[k - 1];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1739. 放置盒子](https://leetcode.cn/problems/building-boxes){#1739}

{{< tabs "1739" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumBoxes(self, n: int) -> int:
        s, k = 0, 1
        while s + k * (k + 1) // 2 <= n:
            s += k * (k + 1) // 2
            k += 1
        k -= 1
        ans = k * (k + 1) // 2
        k = 1
        while s < n:
            ans += 1
            s += k
            k += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumBoxes(int n) {
        int s = 0, k = 1;
        while (s + k * (k + 1) / 2 <= n) {
            s += k * (k + 1) / 2;
            ++k;
        }
        --k;
        int ans = k * (k + 1) / 2;
        k = 1;
        while (s < n) {
            ++ans;
            s += k;
            ++k;
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
    int minimumBoxes(int n) {
        int s = 0, k = 1;
        while (s + k * (k + 1) / 2 <= n) {
            s += k * (k + 1) / 2;
            ++k;
        }
        --k;
        int ans = k * (k + 1) / 2;
        k = 1;
        while (s < n) {
            ++ans;
            s += k;
            ++k;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumBoxes(n int) int {
	s, k := 0, 1
	for s+k*(k+1)/2 <= n {
		s += k * (k + 1) / 2
		k++
	}
	k--
	ans := k * (k + 1) / 2
	k = 1
	for s < n {
		ans++
		s += k
		k++
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

<p>有一个立方体房间，其长度、宽度和高度都等于 <code>n</code> 个单位。请你在房间里放置 <code>n</code> 个盒子，每个盒子都是一个单位边长的立方体。放置规则如下：</p>

<ul>
	<li>你可以把盒子放在地板上的任何地方。</li>
	<li>如果盒子 <code>x</code> 需要放置在盒子 <code>y</code> 的顶部，那么盒子 <code>y</code> 竖直的四个侧面都 <strong>必须</strong> 与另一个盒子或墙相邻。</li>
</ul>

<p>给你一个整数 <code>n</code> ，返回接触地面的盒子的 <strong>最少</strong> 可能数量<em>。</em></p>

<p> </p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1700-1799/1739.Building%20Boxes/images/3-boxes.png" style="width: 135px; height: 143px;" /></p>

<pre>
<strong>输入：</strong>n = 3
<strong>输出：</strong>3
<strong>解释：</strong>上图是 3 个盒子的摆放位置。
这些盒子放在房间的一角，对应左侧位置。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1700-1799/1739.Building%20Boxes/images/4-boxes.png" style="width: 135px; height: 179px;" /></p>

<pre>
<strong>输入：</strong>n = 4
<strong>输出：</strong>3
<strong>解释：</strong>上图是 3 个盒子的摆放位置。
这些盒子放在房间的一角，对应左侧位置。
</pre>

<p><strong>示例 3：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1700-1799/1739.Building%20Boxes/images/10-boxes.png" style="width: 271px; height: 257px;" /></p>

<pre>
<strong>输入：</strong>n = 10
<strong>输出：</strong>6
<strong>解释：</strong>上图是 10 个盒子的摆放位置。
这些盒子放在房间的一角，对应后方位置。</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= n <= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数学规律

根据题目描述，层数最高的盒子需要放在墙角，并且盒子的摆放呈阶梯状，这样可以使得接触地面的盒子数量最少。

假设盒子摆放 $k$ 层，从上到下，每一层如果摆满，那么个数分别是 $1, 1+2, 1+2+3, \cdots, 1+2+\cdots+k$。

如果此时盒子还有剩余，那么可以从最低一层继续摆放，假设摆放 $i$ 个，那么累计可摆放的盒子个数为 $1+2+\cdots+i$。

时间复杂度 $O(\sqrt{n})$，其中 $n$ 为题目给定的盒子数量。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumBoxes(self, n: int) -> int:
        s, k = 0, 1
        while s + k * (k + 1) // 2 <= n:
            s += k * (k + 1) // 2
            k += 1
        k -= 1
        ans = k * (k + 1) // 2
        k = 1
        while s < n:
            ans += 1
            s += k
            k += 1
        return ans
```

#### Java

```java
class Solution {
    public int minimumBoxes(int n) {
        int s = 0, k = 1;
        while (s + k * (k + 1) / 2 <= n) {
            s += k * (k + 1) / 2;
            ++k;
        }
        --k;
        int ans = k * (k + 1) / 2;
        k = 1;
        while (s < n) {
            ++ans;
            s += k;
            ++k;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumBoxes(int n) {
        int s = 0, k = 1;
        while (s + k * (k + 1) / 2 <= n) {
            s += k * (k + 1) / 2;
            ++k;
        }
        --k;
        int ans = k * (k + 1) / 2;
        k = 1;
        while (s < n) {
            ++ans;
            s += k;
            ++k;
        }
        return ans;
    }
};
```

#### Go

```go
func minimumBoxes(n int) int {
	s, k := 0, 1
	for s+k*(k+1)/2 <= n {
		s += k * (k + 1) / 2
		k++
	}
	k--
	ans := k * (k + 1) / 2
	k = 1
	for s < n {
		ans++
		s += k
		k++
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
