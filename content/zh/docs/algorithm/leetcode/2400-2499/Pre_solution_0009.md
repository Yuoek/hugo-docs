---
title: "2480_形成化学键 🔒"
date: 2025-10-08T18:39:18+08:00
weight: 9
tags: [几何, 前缀和, 动态规划, 单调栈, 双指针, 哈希表, 字符串, 数学, 数据库, 数组, 栈, 模拟, 矩阵, 贪心, 递归, 链表]
---

{{< markmap >}}
### [2480_形成化学键 🔒](#2480)
#### [数据库](#2480)
### [2481_分割圆的最少切割次数](#2481)
#### [几何](#2481)
#### [数学](#2481)
### [2482_行和列中一和零的差值](#2482)
#### [数组](#2482)
#### [矩阵](#2482)
#### [模拟](#2482)
### [2483_商店的最少代价](#2483)
#### [字符串](#2483)
#### [前缀和](#2483)
### [2484_统计回文子序列数目](#2484)
#### [字符串](#2484)
#### [动态规划](#2484)
### [2485_找出中枢整数](#2485)
#### [数学](#2485)
#### [前缀和](#2485)
### [2486_追加字符以获得子序列](#2486)
#### [贪心](#2486)
#### [双指针](#2486)
#### [字符串](#2486)
### [2487_从链表中移除节点](#2487)
#### [栈](#2487)
#### [递归](#2487)
#### [链表](#2487)
#### [单调栈](#2487)
### [2488_统计中位数为 K 的子数组](#2488)
#### [数组](#2488)
#### [哈希表](#2488)
#### [前缀和](#2488)
### [2489_固定比率的子字符串数 🔒](#2489)
#### [哈希表](#2489)
#### [数学](#2489)
#### [字符串](#2489)
#### [前缀和](#2489)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2480_形成化学键 🔒
___
#### 数据库
---
### 2481_分割圆的最少切割次数
___
#### 几何
___
#### 数学
---
### 2482_行和列中一和零的差值
___
#### 数组
___
#### 矩阵
___
#### 模拟
---
### 2483_商店的最少代价
___
#### 字符串
___
#### 前缀和
---
### 2484_统计回文子序列数目
___
#### 字符串
___
#### 动态规划
---
### 2485_找出中枢整数
___
#### 数学
___
#### 前缀和
---
### 2486_追加字符以获得子序列
___
#### 贪心
___
#### 双指针
___
#### 字符串
---
### 2487_从链表中移除节点
___
#### 栈
___
#### 递归
___
#### 链表
___
#### 单调栈
---
### 2488_统计中位数为 K 的子数组
___
#### 数组
___
#### 哈希表
___
#### 前缀和
---
### 2489_固定比率的子字符串数 🔒
___
#### 哈希表
___
#### 数学
___
#### 字符串
___
#### 前缀和
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 几何 | 前缀和 | 动态规划 |
| 单调栈 | 双指针 | 哈希表 |
| 字符串 | 数学 | 数据库 |
| 数组 | 栈 | 模拟 |
| 矩阵 | 贪心 | 递归 |
| 链表 |  |  |

# [2480. 形成化学键 🔒](https://leetcode.cn/problems/form-a-chemical-bond){#2480}

{{< tabs "2480" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT a.symbol AS metal, b.symbol AS nonmetal
FROM
    Elements AS a,
    Elements AS b
WHERE a.type = 'Metal' AND b.type = 'Nonmetal';
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表: <code>Elements</code></p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| symbol      | varchar |
| type        | enum    |
| electrons   | int     |
+-------------+---------+
symbol 是该表的主键(具有唯一值的列)。
该表的每一行包含一个元素的信息。
type 是 ENUM&nbsp;类型，它的值是 ('Metal', 'Nonmetal', 'Noble') 之一
 - 如果 type 是 Noble, electrons 是 0。
 - 如果 type 是 Metal, electrons 是这种元素的一个原子所能给出的电子数。
 - 如果 type 是 Nonmetal, electrons 这种元素的一个原子所需要的电子数。
</pre>

<p>&nbsp;</p>

<p>如果一个元素是&nbsp;<code>'Metal'</code>，另外一个元素是&nbsp;<code>'Nonmetal'</code>&nbsp;，那么它们可以形成键。</p>

<p>编写一个解决方案找出所有可以形成键的元素对。</p>

<p data-group="1-1">以&nbsp;<strong>任意顺序&nbsp;</strong>返回结果表。</p>

<p>查询结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> 
Elements 表:
+--------+----------+-----------+
| symbol | type     | electrons |
+--------+----------+-----------+
| He     | Noble    | 0         |
| Na     | Metal    | 1         |
| Ca     | Metal    | 2         |
| La     | Metal    | 3         |
| Cl     | Nonmetal | 1         |
| O      | Nonmetal | 2         |
| N      | Nonmetal | 3         |
+--------+----------+-----------+
<strong>输出:</strong> 
+-------+----------+
| metal | nonmetal |
+-------+----------+
| La    | Cl       |
| Ca    | Cl       |
| Na    | Cl       |
| La    | O        |
| Ca    | O        |
| Na    | O        |
| La    | N        |
| Ca    | N        |
| Na    | N        |
+-------+----------+
<strong>解释:</strong> 
Metal 元素包括 La, Ca, and Na.
Nonmetal 元素包括 Cl, O, and N.
每个 Metal 元素与输出表中的 Nonmeal 元素配对。</pre>

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
SELECT a.symbol AS metal, b.symbol AS nonmetal
FROM
    Elements AS a,
    Elements AS b
WHERE a.type = 'Metal' AND b.type = 'Nonmetal';
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2481. 分割圆的最少切割次数](https://leetcode.cn/problems/minimum-cuts-to-divide-a-circle){#2481}

{{< tabs "2481" >}}

{{% tab "python" %}}
```python
class Solution:
    def numberOfCuts(self, n: int) -> int:
        return n if (n > 1 and n & 1) else n >> 1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numberOfCuts(int n) {
        return n > 1 && n % 2 == 1 ? n : n >> 1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int numberOfCuts(int n) {
        return n > 1 && n % 2 == 1 ? n : n >> 1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numberOfCuts(n int) int {
	if n > 1 && n%2 == 1 {
		return n
	}
	return n >> 1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numberOfCuts(n: number): number {
    return n > 1 && n & 1 ? n : n >> 1;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn number_of_cuts(n: i32) -> i32 {
        if n > 1 && n % 2 == 1 {
            return n;
        }
        n >> 1
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int NumberOfCuts(int n) {
        return n > 1 && n % 2 == 1 ? n : n >> 1;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>圆内一个 <strong>有效切割</strong>&nbsp;，符合以下二者之一：</p>

<ul>
	<li>该切割是两个端点在圆上的线段，且该线段经过圆心。</li>
	<li>该切割是一端在圆心另一端在圆上的线段。</li>
</ul>

<p>一些有效和无效的切割如下图所示。</p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2400-2499/2481.Minimum%20Cuts%20to%20Divide%20a%20Circle/images/alldrawio.png" style="width: 450px; height: 174px;" /></p>

<p>给你一个整数&nbsp;<code>n</code>&nbsp;，请你返回将圆切割成相等的&nbsp;<code>n</code>&nbsp;等分的&nbsp;<strong>最少</strong>&nbsp;切割次数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2400-2499/2481.Minimum%20Cuts%20to%20Divide%20a%20Circle/images/11drawio.png" style="width: 200px; height: 200px;" /></p>

<pre>
<b>输入：</b>n = 4
<b>输出：</b>2
<b>解释：</b>
上图展示了切割圆 2 次，得到四等分。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2400-2499/2481.Minimum%20Cuts%20to%20Divide%20a%20Circle/images/22drawio.png" style="width: 200px; height: 201px;" /></p>

<pre>
<b>输入：</b>n = 3
<b>输出：</b>3
<strong>解释：</strong>
最少需要切割 3 次，将圆切成三等分。
少于 3 次切割无法将圆切成大小相等面积相同的 3 等分。
同时可以观察到，第一次切割无法将圆切割开。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：分类讨论

-   当 $n=1$ 时，不需要切割，即切割次数为 $0$；
-   当 $n$ 为奇数时，不存在共线的情况，最少需要 $n$ 次切割；
-   当 $n$ 为偶数时，可以两两共线，最少需要 $\frac{n}{2}$ 次切割。

综上，可以得到：

$$
\textit{ans} = \begin{cases}
n, & n \gt 1 \textit{ 且 } n \textit{ 为奇数} \\
\frac{n}{2}, & n \textit{ 为其它} \\
\end{cases}
$$

时间复杂度 $O(1)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numberOfCuts(self, n: int) -> int:
        return n if (n > 1 and n & 1) else n >> 1
```

#### Java

```java
class Solution {
    public int numberOfCuts(int n) {
        return n > 1 && n % 2 == 1 ? n : n >> 1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numberOfCuts(int n) {
        return n > 1 && n % 2 == 1 ? n : n >> 1;
    }
};
```

#### Go

```go
func numberOfCuts(n int) int {
	if n > 1 && n%2 == 1 {
		return n
	}
	return n >> 1
}
```

#### TypeScript

```ts
function numberOfCuts(n: number): number {
    return n > 1 && n & 1 ? n : n >> 1;
}
```

#### Rust

```rust
impl Solution {
    pub fn number_of_cuts(n: i32) -> i32 {
        if n > 1 && n % 2 == 1 {
            return n;
        }
        n >> 1
    }
}
```

#### C#

```cs
public class Solution {
    public int NumberOfCuts(int n) {
        return n > 1 && n % 2 == 1 ? n : n >> 1;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2482. 行和列中一和零的差值](https://leetcode.cn/problems/difference-between-ones-and-zeros-in-row-and-column){#2482}

{{< tabs "2482" >}}

{{% tab "python" %}}
```python
class Solution:
    def onesMinusZeros(self, grid: List[List[int]]) -> List[List[int]]:
        m, n = len(grid), len(grid[0])
        rows = [0] * m
        cols = [0] * n
        for i, row in enumerate(grid):
            for j, v in enumerate(row):
                rows[i] += v
                cols[j] += v
        diff = [[0] * n for _ in range(m)]
        for i, r in enumerate(rows):
            for j, c in enumerate(cols):
                diff[i][j] = r + c - (n - r) - (m - c)
        return diff
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[][] onesMinusZeros(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int[] rows = new int[m];
        int[] cols = new int[n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int v = grid[i][j];
                rows[i] += v;
                cols[j] += v;
            }
        }
        int[][] diff = new int[m][n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                diff[i][j] = rows[i] + cols[j] - (n - rows[i]) - (m - cols[j]);
            }
        }
        return diff;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> rows(m);
        vector<int> cols(n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int v = grid[i][j];
                rows[i] += v;
                cols[j] += v;
            }
        }
        vector<vector<int>> diff(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                diff[i][j] = rows[i] + cols[j] - (n - rows[i]) - (m - cols[j]);
            }
        }
        return diff;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func onesMinusZeros(grid [][]int) [][]int {
	m, n := len(grid), len(grid[0])
	rows := make([]int, m)
	cols := make([]int, n)
	diff := make([][]int, m)
	for i, row := range grid {
		diff[i] = make([]int, n)
		for j, v := range row {
			rows[i] += v
			cols[j] += v
		}
	}
	for i, r := range rows {
		for j, c := range cols {
			diff[i][j] = r + c - (n - r) - (m - c)
		}
	}
	return diff
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function onesMinusZeros(grid: number[][]): number[][] {
    const m = grid.length;
    const n = grid[0].length;
    const rows = new Array(m).fill(0);
    const cols = new Array(n).fill(0);
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j]) {
                rows[i]++;
                cols[j]++;
            }
        }
    }
    const ans = Array.from({ length: m }, () => new Array(n).fill(0));
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            ans[i][j] = rows[i] + cols[j] - (m - rows[i]) - (n - cols[j]);
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn ones_minus_zeros(grid: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let m = grid.len();
        let n = grid[0].len();
        let mut rows = vec![0; m];
        let mut cols = vec![0; n];
        for i in 0..m {
            for j in 0..n {
                if grid[i][j] == 1 {
                    rows[i] += 1;
                    cols[j] += 1;
                }
            }
        }
        let mut ans = vec![vec![0; n]; m];
        for i in 0..m {
            for j in 0..n {
                ans[i][j] = (rows[i] + cols[j] - (m - rows[i]) - (n - cols[j])) as i32;
            }
        }
        ans
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
int** onesMinusZeros(int** grid, int gridSize, int* gridColSize, int* returnSize, int** returnColumnSizes) {
    int* rows = malloc(sizeof(int) * gridSize);
    int* cols = malloc(sizeof(int) * gridColSize[0]);
    memset(rows, 0, sizeof(int) * gridSize);
    memset(cols, 0, sizeof(int) * gridColSize[0]);
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[0]; j++) {
            if (grid[i][j]) {
                rows[i]++;
                cols[j]++;
            }
        }
    }
    int** ans = malloc(sizeof(int*) * gridSize);
    for (int i = 0; i < gridSize; i++) {
        ans[i] = malloc(sizeof(int) * gridColSize[0]);
        for (int j = 0; j < gridColSize[0]; j++) {
            ans[i][j] = rows[i] + cols[j] - (gridSize - rows[i]) - (gridColSize[0] - cols[j]);
        }
    }
    *returnSize = gridSize;
    *returnColumnSizes = gridColSize;
    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的&nbsp;<code>m x n</code>&nbsp;二进制矩阵&nbsp;<code>grid</code>&nbsp;。</p>

<p>我们按照如下过程，定义一个下标从 <strong>0</strong>&nbsp;开始的&nbsp;<code>m x n</code>&nbsp;差值矩阵&nbsp;<code>diff</code>&nbsp;：</p>

<ul>
	<li>令第&nbsp;<code>i</code>&nbsp;行一的数目为&nbsp;<code>onesRow<sub>i</sub></code>&nbsp;。</li>
	<li>令第&nbsp;<code>j</code>&nbsp;列一的数目为&nbsp;<code>onesCol<sub>j</sub></code><sub>&nbsp;</sub>。</li>
	<li>令第&nbsp;<code>i</code>&nbsp;行零的数目为&nbsp;<code>zerosRow<sub>i</sub></code>&nbsp;。</li>
	<li>令第&nbsp;<code>j</code>&nbsp;列零的数目为&nbsp;<code>zerosCol<sub>j</sub></code>&nbsp;。</li>
	<li><code>diff[i][j] = onesRow<sub>i</sub> + onesCol<sub>j</sub> - zerosRow<sub>i</sub> - zerosCol<sub>j</sub></code></li>
</ul>

<p>请你返回差值矩阵<em>&nbsp;</em><code>diff</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2400-2499/2482.Difference%20Between%20Ones%20and%20Zeros%20in%20Row%20and%20Column/images/image-20221106171729-5.png" style="width: 400px; height: 208px;"></p>

<pre><b>输入：</b>grid = [[0,1,1],[1,0,1],[0,0,1]]
<b>输出：</b>[[0,0,4],[0,0,4],[-2,-2,2]]
<b>解释：</b>
- diff[0][0] = <code>onesRow<sub>0</sub> + onesCol<sub>0</sub> - zerosRow<sub>0</sub> - zerosCol<sub>0</sub></code> = 2 + 1 - 1 - 2 = 0 
- diff[0][1] = <code>onesRow<sub>0</sub> + onesCol<sub>1</sub> - zerosRow<sub>0</sub> - zerosCol<sub>1</sub></code> = 2 + 1 - 1 - 2 = 0 
- diff[0][2] = <code>onesRow<sub>0</sub> + onesCol<sub>2</sub> - zerosRow<sub>0</sub> - zerosCol<sub>2</sub></code> = 2 + 3 - 1 - 0 = 4 
- diff[1][0] = <code>onesRow<sub>1</sub> + onesCol<sub>0</sub> - zerosRow<sub>1</sub> - zerosCol<sub>0</sub></code> = 2 + 1 - 1 - 2 = 0 
- diff[1][1] = <code>onesRow<sub>1</sub> + onesCol<sub>1</sub> - zerosRow<sub>1</sub> - zerosCol<sub>1</sub></code> = 2 + 1 - 1 - 2 = 0 
- diff[1][2] = <code>onesRow<sub>1</sub> + onesCol<sub>2</sub> - zerosRow<sub>1</sub> - zerosCol<sub>2</sub></code> = 2 + 3 - 1 - 0 = 4 
- diff[2][0] = <code>onesRow<sub>2</sub> + onesCol<sub>0</sub> - zerosRow<sub>2</sub> - zerosCol<sub>0</sub></code> = 1 + 1 - 2 - 2 = -2
- diff[2][1] = <code>onesRow<sub>2</sub> + onesCol<sub>1</sub> - zerosRow<sub>2</sub> - zerosCol<sub>1</sub></code> = 1 + 1 - 2 - 2 = -2
- diff[2][2] = <code>onesRow<sub>2</sub> + onesCol<sub>2</sub> - zerosRow<sub>2</sub> - zerosCol<sub>2</sub></code> = 1 + 3 - 2 - 0 = 2
</pre>

<p><strong>示例 2：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2400-2499/2482.Difference%20Between%20Ones%20and%20Zeros%20in%20Row%20and%20Column/images/image-20221106171747-6.png" style="width: 358px; height: 150px;"></p>

<pre><b>输入：</b>grid = [[1,1,1],[1,1,1]]
<b>输出：</b>[[5,5,5],[5,5,5]]
<strong>解释：</strong>
- diff[0][0] = onesRow<sub>0</sub> + onesCol<sub>0</sub> - zerosRow<sub>0</sub> - zerosCol<sub>0</sub> = 3 + 2 - 0 - 0 = 5
- diff[0][1] = onesRow<sub>0</sub> + onesCol<sub>1</sub> - zerosRow<sub>0</sub> - zerosCol<sub>1</sub> = 3 + 2 - 0 - 0 = 5
- diff[0][2] = onesRow<sub>0</sub> + onesCol<sub>2</sub> - zerosRow<sub>0</sub> - zerosCol<sub>2</sub> = 3 + 2 - 0 - 0 = 5
- diff[1][0] = onesRow<sub>1</sub> + onesCol<sub>0</sub> - zerosRow<sub>1</sub> - zerosCol<sub>0</sub> = 3 + 2 - 0 - 0 = 5
- diff[1][1] = onesRow<sub>1</sub> + onesCol<sub>1</sub> - zerosRow<sub>1</sub> - zerosCol<sub>1</sub> = 3 + 2 - 0 - 0 = 5
- diff[1][2] = onesRow<sub>1</sub> + onesCol<sub>2</sub> - zerosRow<sub>1</sub> - zerosCol<sub>2</sub> = 3 + 2 - 0 - 0 = 5
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= m * n &lt;= 10<sup>5</sup></code></li>
	<li><code>grid[i][j]</code>&nbsp;要么是&nbsp;<code>0</code>&nbsp;，要么是&nbsp;<code>1</code> 。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

根据题意模拟即可。

时间复杂度 $O(m \times n)$，忽略答案的空间消耗，空间复杂度 $O(m + n)$。其中 $m$ 和 $n$ 分别为矩阵的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def onesMinusZeros(self, grid: List[List[int]]) -> List[List[int]]:
        m, n = len(grid), len(grid[0])
        rows = [0] * m
        cols = [0] * n
        for i, row in enumerate(grid):
            for j, v in enumerate(row):
                rows[i] += v
                cols[j] += v
        diff = [[0] * n for _ in range(m)]
        for i, r in enumerate(rows):
            for j, c in enumerate(cols):
                diff[i][j] = r + c - (n - r) - (m - c)
        return diff
```

#### Java

```java
class Solution {
    public int[][] onesMinusZeros(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int[] rows = new int[m];
        int[] cols = new int[n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int v = grid[i][j];
                rows[i] += v;
                cols[j] += v;
            }
        }
        int[][] diff = new int[m][n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                diff[i][j] = rows[i] + cols[j] - (n - rows[i]) - (m - cols[j]);
            }
        }
        return diff;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> rows(m);
        vector<int> cols(n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int v = grid[i][j];
                rows[i] += v;
                cols[j] += v;
            }
        }
        vector<vector<int>> diff(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                diff[i][j] = rows[i] + cols[j] - (n - rows[i]) - (m - cols[j]);
            }
        }
        return diff;
    }
};
```

#### Go

```go
func onesMinusZeros(grid [][]int) [][]int {
	m, n := len(grid), len(grid[0])
	rows := make([]int, m)
	cols := make([]int, n)
	diff := make([][]int, m)
	for i, row := range grid {
		diff[i] = make([]int, n)
		for j, v := range row {
			rows[i] += v
			cols[j] += v
		}
	}
	for i, r := range rows {
		for j, c := range cols {
			diff[i][j] = r + c - (n - r) - (m - c)
		}
	}
	return diff
}
```

#### TypeScript

```ts
function onesMinusZeros(grid: number[][]): number[][] {
    const m = grid.length;
    const n = grid[0].length;
    const rows = new Array(m).fill(0);
    const cols = new Array(n).fill(0);
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j]) {
                rows[i]++;
                cols[j]++;
            }
        }
    }
    const ans = Array.from({ length: m }, () => new Array(n).fill(0));
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            ans[i][j] = rows[i] + cols[j] - (m - rows[i]) - (n - cols[j]);
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn ones_minus_zeros(grid: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let m = grid.len();
        let n = grid[0].len();
        let mut rows = vec![0; m];
        let mut cols = vec![0; n];
        for i in 0..m {
            for j in 0..n {
                if grid[i][j] == 1 {
                    rows[i] += 1;
                    cols[j] += 1;
                }
            }
        }
        let mut ans = vec![vec![0; n]; m];
        for i in 0..m {
            for j in 0..n {
                ans[i][j] = (rows[i] + cols[j] - (m - rows[i]) - (n - cols[j])) as i32;
            }
        }
        ans
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
int** onesMinusZeros(int** grid, int gridSize, int* gridColSize, int* returnSize, int** returnColumnSizes) {
    int* rows = malloc(sizeof(int) * gridSize);
    int* cols = malloc(sizeof(int) * gridColSize[0]);
    memset(rows, 0, sizeof(int) * gridSize);
    memset(cols, 0, sizeof(int) * gridColSize[0]);
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[0]; j++) {
            if (grid[i][j]) {
                rows[i]++;
                cols[j]++;
            }
        }
    }
    int** ans = malloc(sizeof(int*) * gridSize);
    for (int i = 0; i < gridSize; i++) {
        ans[i] = malloc(sizeof(int) * gridColSize[0]);
        for (int j = 0; j < gridColSize[0]; j++) {
            ans[i][j] = rows[i] + cols[j] - (gridSize - rows[i]) - (gridColSize[0] - cols[j]);
        }
    }
    *returnSize = gridSize;
    *returnColumnSizes = gridColSize;
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2483. 商店的最少代价](https://leetcode.cn/problems/minimum-penalty-for-a-shop){#2483}

{{< tabs "2483" >}}

{{% tab "python" %}}
```python
class Solution:
    def bestClosingTime(self, customers: str) -> int:
        n = len(customers)
        s = [0] * (n + 1)
        for i, c in enumerate(customers):
            s[i + 1] = s[i] + int(c == 'Y')
        ans, cost = 0, inf
        for j in range(n + 1):
            t = j - s[j] + s[-1] - s[j]
            if cost > t:
                ans, cost = j, t
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int bestClosingTime(String customers) {
        int n = customers.length();
        int[] s = new int[n + 1];
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + (customers.charAt(i) == 'Y' ? 1 : 0);
        }
        int ans = 0, cost = 1 << 30;
        for (int j = 0; j <= n; ++j) {
            int t = j - s[j] + s[n] - s[j];
            if (cost > t) {
                ans = j;
                cost = t;
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
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> s(n + 1);
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + (customers[i] == 'Y');
        }
        int ans = 0, cost = 1 << 30;
        for (int j = 0; j <= n; ++j) {
            int t = j - s[j] + s[n] - s[j];
            if (cost > t) {
                ans = j;
                cost = t;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func bestClosingTime(customers string) (ans int) {
	n := len(customers)
	s := make([]int, n+1)
	for i, c := range customers {
		s[i+1] = s[i]
		if c == 'Y' {
			s[i+1]++
		}
	}
	cost := 1 << 30
	for j := 0; j <= n; j++ {
		t := j - s[j] + s[n] - s[j]
		if cost > t {
			ans, cost = j, t
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    #[allow(dead_code)]
    pub fn best_closing_time(customers: String) -> i32 {
        let n = customers.len();
        let mut penalty = i32::MAX;
        let mut ret = -1;
        let mut prefix_sum = vec![0; n + 1];

        // Initialize the vector
        for (i, c) in customers.chars().enumerate() {
            prefix_sum[i + 1] = prefix_sum[i] + (if c == 'Y' { 1 } else { 0 });
        }

        // Calculate the answer
        for i in 0..=n {
            if penalty > ((prefix_sum[n] - prefix_sum[i]) as i32) + ((i - prefix_sum[i]) as i32) {
                penalty = ((prefix_sum[n] - prefix_sum[i]) as i32) + ((i - prefix_sum[i]) as i32);
                ret = i as i32;
            }
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

<p>给你一个顾客访问商店的日志，用一个下标从 <strong>0</strong>&nbsp;开始且只包含字符&nbsp;<code>'N'</code> 和&nbsp;<code>'Y'</code>&nbsp;的字符串&nbsp;<code>customers</code>&nbsp;表示：</p>

<ul>
	<li>如果第&nbsp;<code>i</code>&nbsp;个字符是&nbsp;<code>'Y'</code>&nbsp;，它表示第&nbsp;<code>i</code>&nbsp;小时有顾客到达。</li>
	<li>如果第&nbsp;<code>i</code>&nbsp;个字符是&nbsp;<code>'N'</code>&nbsp;，它表示第 <code>i</code>&nbsp;小时没有顾客到达。</li>
</ul>

<p>如果商店在第&nbsp;<code>j</code>&nbsp;小时关门（<code>0 &lt;= j &lt;= n</code>），代价按如下方式计算：</p>

<ul>
	<li>在开门期间，如果某一个小时没有顾客到达，代价增加 <code>1</code>&nbsp;。</li>
	<li>在关门期间，如果某一个小时有顾客到达，代价增加&nbsp;<code>1</code>&nbsp;。</li>
</ul>

<p>请你返回在确保代价 <strong>最小</strong>&nbsp;的前提下，商店的&nbsp;<strong>最早</strong>&nbsp;关门时间。</p>

<p>注意，商店在第 <code>j</code>&nbsp;小时关门表示在第 <code>j</code> 小时以及之后商店处于关门状态。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>customers = "YYNY"
<b>输出：</b>2
<b>解释：</b>
- 第 0 小时关门，总共 1+1+0+1 = 3 代价。
- 第 1 小时关门，总共 0+1+0+1 = 2 代价。
- 第 2 小时关门，总共 0+0+0+1 = 1 代价。
- 第 3 小时关门，总共 0+0+1+1 = 2 代价。
- 第 4 小时关门，总共 0+0+1+0 = 1 代价。
在第 2 或第 4 小时关门代价都最小。由于第 2 小时更早，所以最优关门时间是 2 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>customers = "NNNNN"
<b>输出：</b>0
<b>解释：</b>最优关门时间是 0 ，因为自始至终没有顾客到达。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>customers = "YYYY"
<b>输出：</b>4
<b>解释：</b>最优关门时间是 4 ，因为每一小时均有顾客到达。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= customers.length &lt;= 10<sup>5</sup></code></li>
	<li><code>customers</code>&nbsp;只包含字符&nbsp;<code>'Y'</code>&nbsp;和&nbsp;<code>'N'</code>&nbsp;。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前缀和 + 枚举

我们先算出前 $i$ 小时有多少顾客到达，记录在前缀和数组 $s$ 中。

然后枚举商店关门的时间 $j$，计算代价，取代价最小且时间最早的关门时间即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为字符串 $customers$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def bestClosingTime(self, customers: str) -> int:
        n = len(customers)
        s = [0] * (n + 1)
        for i, c in enumerate(customers):
            s[i + 1] = s[i] + int(c == 'Y')
        ans, cost = 0, inf
        for j in range(n + 1):
            t = j - s[j] + s[-1] - s[j]
            if cost > t:
                ans, cost = j, t
        return ans
```

#### Java

```java
class Solution {
    public int bestClosingTime(String customers) {
        int n = customers.length();
        int[] s = new int[n + 1];
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + (customers.charAt(i) == 'Y' ? 1 : 0);
        }
        int ans = 0, cost = 1 << 30;
        for (int j = 0; j <= n; ++j) {
            int t = j - s[j] + s[n] - s[j];
            if (cost > t) {
                ans = j;
                cost = t;
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
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> s(n + 1);
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + (customers[i] == 'Y');
        }
        int ans = 0, cost = 1 << 30;
        for (int j = 0; j <= n; ++j) {
            int t = j - s[j] + s[n] - s[j];
            if (cost > t) {
                ans = j;
                cost = t;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func bestClosingTime(customers string) (ans int) {
	n := len(customers)
	s := make([]int, n+1)
	for i, c := range customers {
		s[i+1] = s[i]
		if c == 'Y' {
			s[i+1]++
		}
	}
	cost := 1 << 30
	for j := 0; j <= n; j++ {
		t := j - s[j] + s[n] - s[j]
		if cost > t {
			ans, cost = j, t
		}
	}
	return
}
```

#### Rust

```rust
impl Solution {
    #[allow(dead_code)]
    pub fn best_closing_time(customers: String) -> i32 {
        let n = customers.len();
        let mut penalty = i32::MAX;
        let mut ret = -1;
        let mut prefix_sum = vec![0; n + 1];

        // Initialize the vector
        for (i, c) in customers.chars().enumerate() {
            prefix_sum[i + 1] = prefix_sum[i] + (if c == 'Y' { 1 } else { 0 });
        }

        // Calculate the answer
        for i in 0..=n {
            if penalty > ((prefix_sum[n] - prefix_sum[i]) as i32) + ((i - prefix_sum[i]) as i32) {
                penalty = ((prefix_sum[n] - prefix_sum[i]) as i32) + ((i - prefix_sum[i]) as i32);
                ret = i as i32;
            }
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

# [2484. 统计回文子序列数目](https://leetcode.cn/problems/count-palindromic-subsequences){#2484}

{{< tabs "2484" >}}

{{% tab "python" %}}
```python
class Solution:
    def countPalindromes(self, s: str) -> int:
        mod = 10**9 + 7
        n = len(s)
        pre = [[[0] * 10 for _ in range(10)] for _ in range(n + 2)]
        suf = [[[0] * 10 for _ in range(10)] for _ in range(n + 2)]
        t = list(map(int, s))
        c = [0] * 10
        for i, v in enumerate(t, 1):
            for j in range(10):
                for k in range(10):
                    pre[i][j][k] = pre[i - 1][j][k]
            for j in range(10):
                pre[i][j][v] += c[j]
            c[v] += 1
        c = [0] * 10
        for i in range(n, 0, -1):
            v = t[i - 1]
            for j in range(10):
                for k in range(10):
                    suf[i][j][k] = suf[i + 1][j][k]
            for j in range(10):
                suf[i][j][v] += c[j]
            c[v] += 1
        ans = 0
        for i in range(1, n + 1):
            for j in range(10):
                for k in range(10):
                    ans += pre[i - 1][j][k] * suf[i + 1][j][k]
                    ans %= mod
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private static final int MOD = (int) 1e9 + 7;

    public int countPalindromes(String s) {
        int n = s.length();
        int[][][] pre = new int[n + 2][10][10];
        int[][][] suf = new int[n + 2][10][10];
        int[] t = new int[n];
        for (int i = 0; i < n; ++i) {
            t[i] = s.charAt(i) - '0';
        }
        int[] c = new int[10];
        for (int i = 1; i <= n; ++i) {
            int v = t[i - 1];
            for (int j = 0; j < 10; ++j) {
                for (int k = 0; k < 10; ++k) {
                    pre[i][j][k] = pre[i - 1][j][k];
                }
            }
            for (int j = 0; j < 10; ++j) {
                pre[i][j][v] += c[j];
            }
            c[v]++;
        }
        c = new int[10];
        for (int i = n; i > 0; --i) {
            int v = t[i - 1];
            for (int j = 0; j < 10; ++j) {
                for (int k = 0; k < 10; ++k) {
                    suf[i][j][k] = suf[i + 1][j][k];
                }
            }
            for (int j = 0; j < 10; ++j) {
                suf[i][j][v] += c[j];
            }
            c[v]++;
        }
        long ans = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 10; ++j) {
                for (int k = 0; k < 10; ++k) {
                    ans += (long) pre[i - 1][j][k] * suf[i + 1][j][k];
                    ans %= MOD;
                }
            }
        }
        return (int) ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    const int mod = 1e9 + 7;

    int countPalindromes(string s) {
        int n = s.size();
        int pre[n + 2][10][10];
        int suf[n + 2][10][10];
        memset(pre, 0, sizeof pre);
        memset(suf, 0, sizeof suf);
        int t[n];
        for (int i = 0; i < n; ++i) t[i] = s[i] - '0';
        int c[10] = {0};
        for (int i = 1; i <= n; ++i) {
            int v = t[i - 1];
            for (int j = 0; j < 10; ++j) {
                for (int k = 0; k < 10; ++k) {
                    pre[i][j][k] = pre[i - 1][j][k];
                }
            }
            for (int j = 0; j < 10; ++j) {
                pre[i][j][v] += c[j];
            }
            c[v]++;
        }
        memset(c, 0, sizeof c);
        for (int i = n; i > 0; --i) {
            int v = t[i - 1];
            for (int j = 0; j < 10; ++j) {
                for (int k = 0; k < 10; ++k) {
                    suf[i][j][k] = suf[i + 1][j][k];
                }
            }
            for (int j = 0; j < 10; ++j) {
                suf[i][j][v] += c[j];
            }
            c[v]++;
        }
        long ans = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 10; ++j) {
                for (int k = 0; k < 10; ++k) {
                    ans += 1ll * pre[i - 1][j][k] * suf[i + 1][j][k];
                    ans %= mod;
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
func countPalindromes(s string) int {
	n := len(s)
	pre := [10010][10][10]int{}
	suf := [10010][10][10]int{}
	t := make([]int, n)
	for i, c := range s {
		t[i] = int(c - '0')
	}
	c := [10]int{}
	for i := 1; i <= n; i++ {
		v := t[i-1]
		for j := 0; j < 10; j++ {
			for k := 0; k < 10; k++ {
				pre[i][j][k] = pre[i-1][j][k]
			}
		}
		for j := 0; j < 10; j++ {
			pre[i][j][v] += c[j]
		}
		c[v]++
	}
	c = [10]int{}
	for i := n; i > 0; i-- {
		v := t[i-1]
		for j := 0; j < 10; j++ {
			for k := 0; k < 10; k++ {
				suf[i][j][k] = suf[i+1][j][k]
			}
		}
		for j := 0; j < 10; j++ {
			suf[i][j][v] += c[j]
		}
		c[v]++
	}
	ans := 0
	const mod int = 1e9 + 7
	for i := 1; i <= n; i++ {
		for j := 0; j < 10; j++ {
			for k := 0; k < 10; k++ {
				ans += pre[i-1][j][k] * suf[i+1][j][k]
				ans %= mod
			}
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

<p>给你数字字符串&nbsp;<code>s</code>&nbsp;，请你返回&nbsp;<code>s</code>&nbsp;中长度为&nbsp;<code>5</code>&nbsp;的 <b>回文子序列</b>&nbsp;数目。由于答案可能很大，请你将答案对&nbsp;<code>10<sup>9</sup> + 7</code>&nbsp;<strong>取余</strong>&nbsp;后返回。</p>

<p><strong>提示：</strong></p>

<ul>
	<li>如果一个字符串从前往后和从后往前读相同，那么它是 <strong>回文字符串</strong>&nbsp;。</li>
	<li>子序列是一个字符串中删除若干个字符后，不改变字符顺序，剩余字符构成的字符串。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = "103301"
<b>输出：</b>2
<b>解释：</b>
总共有 6 长度为 5 的子序列："10330" ，"10331" ，"10301" ，"10301" ，"13301" ，"03301" 。
它们中有两个（都是 "10301"）是回文的。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>s = "0000000"
<b>输出：</b>21
<b>解释：</b>所有 21 个长度为 5 的子序列都是 "00000" ，都是回文的。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>s = "9999900000"
<b>输出：</b>2
<b>解释：</b>仅有的两个回文子序列是 "99999" 和 "00000" 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>4</sup></code></li>
	<li><code>s</code>&nbsp;只包含数字字符。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举 + 计数

时间复杂度 $O(100 \times n)$，空间复杂度 $O(100 \times n)$。其中 $n$ 为字符串 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countPalindromes(self, s: str) -> int:
        mod = 10**9 + 7
        n = len(s)
        pre = [[[0] * 10 for _ in range(10)] for _ in range(n + 2)]
        suf = [[[0] * 10 for _ in range(10)] for _ in range(n + 2)]
        t = list(map(int, s))
        c = [0] * 10
        for i, v in enumerate(t, 1):
            for j in range(10):
                for k in range(10):
                    pre[i][j][k] = pre[i - 1][j][k]
            for j in range(10):
                pre[i][j][v] += c[j]
            c[v] += 1
        c = [0] * 10
        for i in range(n, 0, -1):
            v = t[i - 1]
            for j in range(10):
                for k in range(10):
                    suf[i][j][k] = suf[i + 1][j][k]
            for j in range(10):
                suf[i][j][v] += c[j]
            c[v] += 1
        ans = 0
        for i in range(1, n + 1):
            for j in range(10):
                for k in range(10):
                    ans += pre[i - 1][j][k] * suf[i + 1][j][k]
                    ans %= mod
        return ans
```

#### Java

```java
class Solution {
    private static final int MOD = (int) 1e9 + 7;

    public int countPalindromes(String s) {
        int n = s.length();
        int[][][] pre = new int[n + 2][10][10];
        int[][][] suf = new int[n + 2][10][10];
        int[] t = new int[n];
        for (int i = 0; i < n; ++i) {
            t[i] = s.charAt(i) - '0';
        }
        int[] c = new int[10];
        for (int i = 1; i <= n; ++i) {
            int v = t[i - 1];
            for (int j = 0; j < 10; ++j) {
                for (int k = 0; k < 10; ++k) {
                    pre[i][j][k] = pre[i - 1][j][k];
                }
            }
            for (int j = 0; j < 10; ++j) {
                pre[i][j][v] += c[j];
            }
            c[v]++;
        }
        c = new int[10];
        for (int i = n; i > 0; --i) {
            int v = t[i - 1];
            for (int j = 0; j < 10; ++j) {
                for (int k = 0; k < 10; ++k) {
                    suf[i][j][k] = suf[i + 1][j][k];
                }
            }
            for (int j = 0; j < 10; ++j) {
                suf[i][j][v] += c[j];
            }
            c[v]++;
        }
        long ans = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 10; ++j) {
                for (int k = 0; k < 10; ++k) {
                    ans += (long) pre[i - 1][j][k] * suf[i + 1][j][k];
                    ans %= MOD;
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
    const int mod = 1e9 + 7;

    int countPalindromes(string s) {
        int n = s.size();
        int pre[n + 2][10][10];
        int suf[n + 2][10][10];
        memset(pre, 0, sizeof pre);
        memset(suf, 0, sizeof suf);
        int t[n];
        for (int i = 0; i < n; ++i) t[i] = s[i] - '0';
        int c[10] = {0};
        for (int i = 1; i <= n; ++i) {
            int v = t[i - 1];
            for (int j = 0; j < 10; ++j) {
                for (int k = 0; k < 10; ++k) {
                    pre[i][j][k] = pre[i - 1][j][k];
                }
            }
            for (int j = 0; j < 10; ++j) {
                pre[i][j][v] += c[j];
            }
            c[v]++;
        }
        memset(c, 0, sizeof c);
        for (int i = n; i > 0; --i) {
            int v = t[i - 1];
            for (int j = 0; j < 10; ++j) {
                for (int k = 0; k < 10; ++k) {
                    suf[i][j][k] = suf[i + 1][j][k];
                }
            }
            for (int j = 0; j < 10; ++j) {
                suf[i][j][v] += c[j];
            }
            c[v]++;
        }
        long ans = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 10; ++j) {
                for (int k = 0; k < 10; ++k) {
                    ans += 1ll * pre[i - 1][j][k] * suf[i + 1][j][k];
                    ans %= mod;
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func countPalindromes(s string) int {
	n := len(s)
	pre := [10010][10][10]int{}
	suf := [10010][10][10]int{}
	t := make([]int, n)
	for i, c := range s {
		t[i] = int(c - '0')
	}
	c := [10]int{}
	for i := 1; i <= n; i++ {
		v := t[i-1]
		for j := 0; j < 10; j++ {
			for k := 0; k < 10; k++ {
				pre[i][j][k] = pre[i-1][j][k]
			}
		}
		for j := 0; j < 10; j++ {
			pre[i][j][v] += c[j]
		}
		c[v]++
	}
	c = [10]int{}
	for i := n; i > 0; i-- {
		v := t[i-1]
		for j := 0; j < 10; j++ {
			for k := 0; k < 10; k++ {
				suf[i][j][k] = suf[i+1][j][k]
			}
		}
		for j := 0; j < 10; j++ {
			suf[i][j][v] += c[j]
		}
		c[v]++
	}
	ans := 0
	const mod int = 1e9 + 7
	for i := 1; i <= n; i++ {
		for j := 0; j < 10; j++ {
			for k := 0; k < 10; k++ {
				ans += pre[i-1][j][k] * suf[i+1][j][k]
				ans %= mod
			}
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

# [2485. 找出中枢整数](https://leetcode.cn/problems/find-the-pivot-integer){#2485}

{{< tabs "2485" >}}

{{% tab "python" %}}
```python
class Solution:
    def pivotInteger(self, n: int) -> int:
        y = n * (n + 1) // 2
        x = int(sqrt(y))
        return x if x * x == y else -1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int pivotInteger(int n) {
        int y = n * (n + 1) / 2;
        int x = (int) Math.sqrt(y);
        return x * x == y ? x : -1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int pivotInteger(int n) {
        int y = n * (n + 1) / 2;
        int x = sqrt(y);
        return x * x == y ? x : -1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func pivotInteger(n int) int {
	y := n * (n + 1) / 2
	x := int(math.Sqrt(float64(y)))
	if x*x == y {
		return x
	}
	return -1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function pivotInteger(n: number): number {
    const y = Math.floor((n * (n + 1)) / 2);
    const x = Math.floor(Math.sqrt(y));
    return x * x === y ? x : -1;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn pivot_integer(n: i32) -> i32 {
        let y = (n * (n + 1)) / 2;
        let x = (y as f64).sqrt() as i32;

        if x * x == y {
            return x;
        }

        -1
    }
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param Integer $n
     * @return Integer
     */
    function pivotInteger($n) {
        $sum = ($n * ($n + 1)) / 2;
        $pre = 0;
        for ($i = 1; $i <= $n; $i++) {
            if ($pre + $i === $sum - $pre) {
                return $i;
            }
            $pre += $i;
        }
        return -1;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个正整数 <code>n</code> ，找出满足下述条件的<strong> 中枢整数</strong> <code>x</code> ：</p>

<ul>
	<li><code>1</code> 和 <code>x</code> 之间的所有元素之和等于 <code>x</code> 和 <code>n</code> 之间所有元素之和。</li>
</ul>

<p>返回中枢整数<em> </em><code>x</code> 。如果不存在中枢整数，则返回 <code>-1</code> 。题目保证对于给定的输入，至多存在一个中枢整数。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 8
<strong>输出：</strong>6
<strong>解释：</strong>6 是中枢整数，因为 1 + 2 + 3 + 4 + 5 + 6 = 6 + 7 + 8 = 21 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 1
<strong>输出：</strong>1
<strong>解释：</strong>1 是中枢整数，因为 1 = 1 。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 4
<strong>输出：</strong>-1
<strong>解释：</strong>可以证明不存在满足题目要求的整数。</pre>

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

### 方法一：枚举

我们可以直接在 $[1,..n]$ 的范围内枚举 $x$，判断以下等式是否成立。若成立，则 $x$ 为中枢整数，直接返回 $x$ 即可。

$$
(1 + x) \times x = (x + n) \times (n - x + 1)
$$

时间复杂度 $O(n)$，其中 $n$ 为给定的正整数 $n$。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def pivotInteger(self, n: int) -> int:
        for x in range(1, n + 1):
            if (1 + x) * x == (x + n) * (n - x + 1):
                return x
        return -1
```

#### Java

```java
class Solution {
    public int pivotInteger(int n) {
        for (int x = 1; x <= n; ++x) {
            if ((1 + x) * x == (x + n) * (n - x + 1)) {
                return x;
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
    int pivotInteger(int n) {
        for (int x = 1; x <= n; ++x) {
            if ((1 + x) * x == (x + n) * (n - x + 1)) {
                return x;
            }
        }
        return -1;
    }
};
```

#### Go

```go
func pivotInteger(n int) int {
	for x := 1; x <= n; x++ {
		if (1+x)*x == (x+n)*(n-x+1) {
			return x
		}
	}
	return -1
}
```

#### TypeScript

```ts
function pivotInteger(n: number): number {
    for (let x = 1; x <= n; ++x) {
        if ((1 + x) * x === (x + n) * (n - x + 1)) {
            return x;
        }
    }
    return -1;
}
```

#### Rust

```rust
impl Solution {
    pub fn pivot_integer(n: i32) -> i32 {
        let y = (n * (n + 1)) / 2;
        let x = (y as f64).sqrt() as i32;

        if x * x == y {
            return x;
        }

        -1
    }
}
```

#### PHP

```php
class Solution {
    /**
     * @param Integer $n
     * @return Integer
     */
    function pivotInteger($n) {
        $sum = ($n * ($n + 1)) / 2;
        $pre = 0;
        for ($i = 1; $i <= $n; $i++) {
            if ($pre + $i === $sum - $pre) {
                return $i;
            }
            $pre += $i;
        }
        return -1;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：数学

我们可以将上述等式进行变形，得到：

$$
n \times (n + 1) = 2 \times x^2
$$

即：

$$
x = \sqrt{\frac{n \times (n + 1)}{2}}
$$

如果 $x$ 为整数，则 $x$ 为中枢整数，否则不存在中枢整数。

时间复杂度 $O(1)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def pivotInteger(self, n: int) -> int:
        y = n * (n + 1) // 2
        x = int(sqrt(y))
        return x if x * x == y else -1
```

#### Java

```java
class Solution {
    public int pivotInteger(int n) {
        int y = n * (n + 1) / 2;
        int x = (int) Math.sqrt(y);
        return x * x == y ? x : -1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int pivotInteger(int n) {
        int y = n * (n + 1) / 2;
        int x = sqrt(y);
        return x * x == y ? x : -1;
    }
};
```

#### Go

```go
func pivotInteger(n int) int {
	y := n * (n + 1) / 2
	x := int(math.Sqrt(float64(y)))
	if x*x == y {
		return x
	}
	return -1
}
```

#### TypeScript

```ts
function pivotInteger(n: number): number {
    const y = Math.floor((n * (n + 1)) / 2);
    const x = Math.floor(Math.sqrt(y));
    return x * x === y ? x : -1;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2486. 追加字符以获得子序列](https://leetcode.cn/problems/append-characters-to-string-to-make-subsequence){#2486}

{{< tabs "2486" >}}

{{% tab "python" %}}
```python
class Solution:
    def appendCharacters(self, s: str, t: str) -> int:
        n, j = len(t), 0
        for c in s:
            if j < n and c == t[j]:
                j += 1
        return n - j
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int appendCharacters(String s, String t) {
        int n = t.length(), j = 0;
        for (int i = 0; i < s.length() && j < n; ++i) {
            if (s.charAt(i) == t.charAt(j)) {
                ++j;
            }
        }
        return n - j;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int appendCharacters(string s, string t) {
        int n = t.length(), j = 0;
        for (int i = 0; i < s.size() && j < n; ++i) {
            if (s[i] == t[j]) {
                ++j;
            }
        }
        return n - j;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func appendCharacters(s string, t string) int {
	n, j := len(t), 0
	for _, c := range s {
		if j < n && byte(c) == t[j] {
			j++
		}
	}
	return n - j
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function appendCharacters(s: string, t: string): number {
    let j = 0;
    for (const c of s) {
        if (c === t[j]) {
            ++j;
        }
    }
    return t.length - j;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个仅由小写英文字母组成的字符串 <code>s</code> 和 <code>t</code> 。</p>

<p>现在需要通过向 <code>s</code> 末尾追加字符的方式使 <code>t</code> 变成 <code>s</code> 的一个 <strong>子序列</strong> ，返回需要追加的最少字符数。</p>

<p>子序列是一个可以由其他字符串删除部分（或不删除）字符但不改变剩下字符顺序得到的字符串。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "coaching", t = "coding"
<strong>输出：</strong>4
<strong>解释：</strong>向 s 末尾追加字符串 "ding" ，s = "coachingding" 。
现在，t 是 s ("<em><strong>co</strong></em>aching<em><strong>ding</strong></em>") 的一个子序列。
可以证明向 s 末尾追加任何 3 个字符都无法使 t 成为 s 的一个子序列。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "abcde", t = "a"
<strong>输出：</strong>0
<strong>解释：</strong>t 已经是 s ("<em><strong>a</strong></em>bcde") 的一个子序列。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "z", t = "abcde"
<strong>输出：</strong>5
<strong>解释：</strong>向 s 末尾追加字符串 "abcde" ，s = "zabcde" 。
现在，t 是 s ("z<em><strong>abcde</strong></em>") 的一个子序列。 
可以证明向 s 末尾追加任何 4 个字符都无法使 t 成为 s 的一个子序列。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length, t.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> 和 <code>t</code> 仅由小写英文字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双指针

我们定义两个指针 $i$ 和 $j$，分别指向字符串 $s$ 和 $t$ 的首字符。遍历字符串 $s$，如果 $s[i] = t[j]$，则将 $j$ 向后移动一位。最终返回 $n - j$，其中 $n$ 是字符串 $t$ 的长度。

时间复杂度 $(m + n)$，其中 $m$ 和 $n$ 分别是字符串 $s$ 和 $t$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def appendCharacters(self, s: str, t: str) -> int:
        n, j = len(t), 0
        for c in s:
            if j < n and c == t[j]:
                j += 1
        return n - j
```

#### Java

```java
class Solution {
    public int appendCharacters(String s, String t) {
        int n = t.length(), j = 0;
        for (int i = 0; i < s.length() && j < n; ++i) {
            if (s.charAt(i) == t.charAt(j)) {
                ++j;
            }
        }
        return n - j;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int appendCharacters(string s, string t) {
        int n = t.length(), j = 0;
        for (int i = 0; i < s.size() && j < n; ++i) {
            if (s[i] == t[j]) {
                ++j;
            }
        }
        return n - j;
    }
};
```

#### Go

```go
func appendCharacters(s string, t string) int {
	n, j := len(t), 0
	for _, c := range s {
		if j < n && byte(c) == t[j] {
			j++
		}
	}
	return n - j
}
```

#### TypeScript

```ts
function appendCharacters(s: string, t: string): number {
    let j = 0;
    for (const c of s) {
        if (c === t[j]) {
            ++j;
        }
    }
    return t.length - j;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2487. 从链表中移除节点](https://leetcode.cn/problems/remove-nodes-from-linked-list){#2487}

{{< tabs "2487" >}}

{{% tab "python" %}}
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(inf, head)
        cur = head
        stk = [dummy]
        while cur:
            while stk[-1].val < cur.val:
                stk.pop()
            stk[-1].next = cur
            stk.append(cur)
            cur = cur.next
        return dummy.next
```
{{% /tab %}}
{{% tab "java" %}}
```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeNodes(ListNode head) {
        ListNode dummy = new ListNode(1 << 30, head);
        Deque<ListNode> stk = new ArrayDeque<>();
        stk.offerLast(dummy);
        for (ListNode cur = head; cur != null; cur = cur.next) {
            while (stk.peekLast().val < cur.val) {
                stk.pollLast();
            }
            stk.peekLast().next = cur;
            stk.offerLast(cur);
        }
        return dummy.next;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        ListNode* dummy = new ListNode(1e9, head);
        ListNode* cur = head;
        vector<ListNode*> stk = {dummy};
        for (ListNode* cur = head; cur; cur = cur->next) {
            while (stk.back()->val < cur->val) {
                stk.pop_back();
            }
            stk.back()->next = cur;
            stk.push_back(cur);
        }
        return dummy->next;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeNodes(head *ListNode) *ListNode {
	dummy := &ListNode{1 << 30, head}
	stk := []*ListNode{dummy}
	for cur := head; cur != nil; cur = cur.Next {
		for stk[len(stk)-1].Val < cur.Val {
			stk = stk[:len(stk)-1]
		}
		stk[len(stk)-1].Next = cur
		stk = append(stk, cur)
	}
	return dummy.Next
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function removeNodes(head: ListNode | null): ListNode | null {
    const dummy = new ListNode(Infinity, head);
    const stk: ListNode[] = [dummy];
    for (let cur = head; cur; cur = cur.next) {
        while (stk.at(-1)!.val < cur.val) {
            stk.pop();
        }
        stk.at(-1)!.next = cur;
        stk.push(cur);
    }
    return dummy.next;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个链表的头节点 <code>head</code> 。</p>

<p>移除每个右侧有一个更大数值的节点。</p>

<p>返回修改后链表的头节点<em> </em><code>head</code><em> </em>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2400-2499/2487.Remove%20Nodes%20From%20Linked%20List/images/drawio.png" style="width: 631px; height: 51px;" /></p>

<pre>
<strong>输入：</strong>head = [5,2,13,3,8]
<strong>输出：</strong>[13,8]
<strong>解释：</strong>需要移除的节点是 5 ，2 和 3 。
- 节点 13 在节点 5 右侧。
- 节点 13 在节点 2 右侧。
- 节点 8 在节点 3 右侧。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>head = [1,1,1,1]
<strong>输出：</strong>[1,1,1,1]
<strong>解释：</strong>每个节点的值都是 1 ，所以没有需要移除的节点。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>给定列表中的节点数目在范围 <code>[1, 10<sup>5</sup>]</code> 内</li>
	<li><code>1 &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：单调栈模拟

我们可以先将链表中的节点值存入数组 $nums$，然后遍历数组 $nums$，维护一个从栈底到栈顶单调递减的栈 $stk$，如果当前元素比栈顶元素大，则将栈顶元素出栈，直到当前元素小于等于栈顶元素，将当前元素入栈。

最后，我们从栈底到栈顶构造出结果链表，即为答案。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是链表的长度。

我们也可以不使用数组 $nums$，直接遍历链表，维护一个从栈底到栈顶单调递减的栈 $stk$，如果当前元素比栈顶元素大，则将栈顶元素出栈，直到当前元素小于等于栈顶元素。然后，如果栈不为空，则将栈顶元素的 $next$ 指针指向当前元素，否则将答案链表的虚拟头节点的 $next$ 指针指向当前元素。最后，将当前元素入栈，继续遍历链表。

遍历结束后，将虚拟头节点的 $next$ 指针作为答案返回。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是链表的长度。

<!-- tabs:start -->

#### Python3

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        nums = []
        while head:
            nums.append(head.val)
            head = head.next
        stk = []
        for v in nums:
            while stk and stk[-1] < v:
                stk.pop()
            stk.append(v)
        dummy = ListNode()
        head = dummy
        for v in stk:
            head.next = ListNode(v)
            head = head.next
        return dummy.next
```

#### Java

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeNodes(ListNode head) {
        List<Integer> nums = new ArrayList<>();
        while (head != null) {
            nums.add(head.val);
            head = head.next;
        }
        Deque<Integer> stk = new ArrayDeque<>();
        for (int v : nums) {
            while (!stk.isEmpty() && stk.peekLast() < v) {
                stk.pollLast();
            }
            stk.offerLast(v);
        }
        ListNode dummy = new ListNode();
        head = dummy;
        while (!stk.isEmpty()) {
            head.next = new ListNode(stk.pollFirst());
            head = head.next;
        }
        return dummy.next;
    }
}
```

#### C++

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        vector<int> nums;
        while (head) {
            nums.emplace_back(head->val);
            head = head->next;
        }
        vector<int> stk;
        for (int v : nums) {
            while (!stk.empty() && stk.back() < v) {
                stk.pop_back();
            }
            stk.push_back(v);
        }
        ListNode* dummy = new ListNode();
        head = dummy;
        for (int v : stk) {
            head->next = new ListNode(v);
            head = head->next;
        }
        return dummy->next;
    }
};
```

#### Go

```go
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeNodes(head *ListNode) *ListNode {
	nums := []int{}
	for head != nil {
		nums = append(nums, head.Val)
		head = head.Next
	}
	stk := []int{}
	for _, v := range nums {
		for len(stk) > 0 && stk[len(stk)-1] < v {
			stk = stk[:len(stk)-1]
		}
		stk = append(stk, v)
	}
	dummy := &ListNode{}
	head = dummy
	for _, v := range stk {
		head.Next = &ListNode{Val: v}
		head = head.Next
	}
	return dummy.Next
}
```

#### TypeScript

```ts
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function removeNodes(head: ListNode | null): ListNode | null {
    const nums = [];
    for (; head; head = head.next) {
        nums.push(head.val);
    }
    const stk: number[] = [];
    for (const v of nums) {
        while (stk.length && stk.at(-1)! < v) {
            stk.pop();
        }
        stk.push(v);
    }
    const dummy = new ListNode();
    head = dummy;
    for (const v of stk) {
        head.next = new ListNode(v);
        head = head.next;
    }
    return dummy.next;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### Python3

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(inf, head)
        cur = head
        stk = [dummy]
        while cur:
            while stk[-1].val < cur.val:
                stk.pop()
            stk[-1].next = cur
            stk.append(cur)
            cur = cur.next
        return dummy.next
```

#### Java

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeNodes(ListNode head) {
        ListNode dummy = new ListNode(1 << 30, head);
        Deque<ListNode> stk = new ArrayDeque<>();
        stk.offerLast(dummy);
        for (ListNode cur = head; cur != null; cur = cur.next) {
            while (stk.peekLast().val < cur.val) {
                stk.pollLast();
            }
            stk.peekLast().next = cur;
            stk.offerLast(cur);
        }
        return dummy.next;
    }
}
```

#### C++

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        ListNode* dummy = new ListNode(1e9, head);
        ListNode* cur = head;
        vector<ListNode*> stk = {dummy};
        for (ListNode* cur = head; cur; cur = cur->next) {
            while (stk.back()->val < cur->val) {
                stk.pop_back();
            }
            stk.back()->next = cur;
            stk.push_back(cur);
        }
        return dummy->next;
    }
};
```

#### Go

```go
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeNodes(head *ListNode) *ListNode {
	dummy := &ListNode{1 << 30, head}
	stk := []*ListNode{dummy}
	for cur := head; cur != nil; cur = cur.Next {
		for stk[len(stk)-1].Val < cur.Val {
			stk = stk[:len(stk)-1]
		}
		stk[len(stk)-1].Next = cur
		stk = append(stk, cur)
	}
	return dummy.Next
}
```

#### TypeScript

```ts
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function removeNodes(head: ListNode | null): ListNode | null {
    const dummy = new ListNode(Infinity, head);
    const stk: ListNode[] = [dummy];
    for (let cur = head; cur; cur = cur.next) {
        while (stk.at(-1)!.val < cur.val) {
            stk.pop();
        }
        stk.at(-1)!.next = cur;
        stk.push(cur);
    }
    return dummy.next;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2488. 统计中位数为 K 的子数组](https://leetcode.cn/problems/count-subarrays-with-median-k){#2488}

{{< tabs "2488" >}}

{{% tab "python" %}}
```python
class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        i = nums.index(k)
        cnt = Counter()
        ans = 1
        x = 0
        for v in nums[i + 1 :]:
            x += 1 if v > k else -1
            ans += 0 <= x <= 1
            cnt[x] += 1
        x = 0
        for j in range(i - 1, -1, -1):
            x += 1 if nums[j] > k else -1
            ans += 0 <= x <= 1
            ans += cnt[-x] + cnt[-x + 1]
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countSubarrays(int[] nums, int k) {
        int n = nums.length;
        int i = 0;
        for (; nums[i] != k; ++i) {
        }
        int[] cnt = new int[n << 1 | 1];
        int ans = 1;
        int x = 0;
        for (int j = i + 1; j < n; ++j) {
            x += nums[j] > k ? 1 : -1;
            if (x >= 0 && x <= 1) {
                ++ans;
            }
            ++cnt[x + n];
        }
        x = 0;
        for (int j = i - 1; j >= 0; --j) {
            x += nums[j] > k ? 1 : -1;
            if (x >= 0 && x <= 1) {
                ++ans;
            }
            ans += cnt[-x + n] + cnt[-x + 1 + n];
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
    int countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int i = find(nums.begin(), nums.end(), k) - nums.begin();
        int cnt[n << 1 | 1];
        memset(cnt, 0, sizeof(cnt));
        int ans = 1;
        int x = 0;
        for (int j = i + 1; j < n; ++j) {
            x += nums[j] > k ? 1 : -1;
            if (x >= 0 && x <= 1) {
                ++ans;
            }
            ++cnt[x + n];
        }
        x = 0;
        for (int j = i - 1; ~j; --j) {
            x += nums[j] > k ? 1 : -1;
            if (x >= 0 && x <= 1) {
                ++ans;
            }
            ans += cnt[-x + n] + cnt[-x + 1 + n];
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countSubarrays(nums []int, k int) int {
	i, n := 0, len(nums)
	for nums[i] != k {
		i++
	}
	ans := 1
	cnt := make([]int, n<<1|1)
	x := 0
	for j := i + 1; j < n; j++ {
		if nums[j] > k {
			x++
		} else {
			x--
		}
		if x >= 0 && x <= 1 {
			ans++
		}
		cnt[x+n]++
	}
	x = 0
	for j := i - 1; j >= 0; j-- {
		if nums[j] > k {
			x++
		} else {
			x--
		}
		if x >= 0 && x <= 1 {
			ans++
		}
		ans += cnt[-x+n] + cnt[-x+1+n]
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countSubarrays(nums: number[], k: number): number {
    const i = nums.indexOf(k);
    const n = nums.length;
    const cnt = new Array((n << 1) | 1).fill(0);
    let ans = 1;
    let x = 0;
    for (let j = i + 1; j < n; ++j) {
        x += nums[j] > k ? 1 : -1;
        ans += x >= 0 && x <= 1 ? 1 : 0;
        ++cnt[x + n];
    }
    x = 0;
    for (let j = i - 1; ~j; --j) {
        x += nums[j] > k ? 1 : -1;
        ans += x >= 0 && x <= 1 ? 1 : 0;
        ans += cnt[-x + n] + cnt[-x + 1 + n];
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

<p>给你一个长度为 <code>n</code> 的数组 <code>nums</code> ，该数组由从 <code>1</code> 到 <code>n</code> 的 <strong>不同</strong> 整数组成。另给你一个正整数 <code>k</code> 。</p>

<p>统计并返回 <code>nums</code> 中的 <strong>中位数</strong> 等于 <code>k</code> 的非空子数组的数目。</p>

<p><strong>注意：</strong></p>

<ul>
	<li>数组的中位数是按 <strong>递增</strong> 顺序排列后位于 <strong>中间</strong> 的那个元素，如果数组长度为偶数，则中位数是位于中间靠 <strong>左</strong> 的那个元素。

    <ul>
    	<li>例如，<code>[2,3,1,4]</code> 的中位数是 <code>2</code> ，<code>[8,4,3,5,1]</code> 的中位数是 <code>4</code> 。</li>
    </ul>
    </li>
    <li>子数组是数组中的一个连续部分。</li>

</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [3,2,1,4,5], k = 4
<strong>输出：</strong>3
<strong>解释：</strong>中位数等于 4 的子数组有：[4]、[4,5] 和 [1,4,5] 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,3,1], k = 3
<strong>输出：</strong>1
<strong>解释：</strong>[3] 是唯一一个中位数等于 3 的子数组。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i], k &lt;= n</code></li>
	<li><code>nums</code> 中的整数互不相同</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：遍历 + 计数

我们先找到中位数 $k$ 在数组中的位置 $i$，然后从 $i$ 开始向两边遍历，统计中位数为 $k$ 的子数组的数目。

定义一个答案变量 $ans$，表示中位数为 $k$ 的子数组的数目。初始时 $ans = 1$，表示当前有一个长度为 $1$ 的子数组，其中位数为 $k$。另外，定义一个计数器 $cnt$，用于统计当前遍历过的数组中，「比 $k$ 大的元素的个数」与「比 $k$ 小的元素的个数」的差值的个数。

接下来，从 $i + 1$ 开始向右遍历，我们维护一个变量 $x$，表示当前右侧子数组中「比 $k$ 大的元素的个数」与「比 $k$ 小的元素的个数」的差值。如果 $x \in [0, 1]$，则当前右侧子数组的中位数为 $k$，答案变量 $ans$ 自增 $1$。然后，我们将 $x$ 的值加入计数器 $cnt$ 中。

同理，从 $i - 1$ 开始向左遍历，同样维护一个变量 $x$，表示当前左侧子数组中「比 $k$ 大的元素的个数」与「比 $k$ 小的元素的个数」的差值。如果 $x \in [0, 1]$，则当前左侧子数组的中位数为 $k$，答案变量 $ans$ 自增 $1$。如果 $-x$ 或 $-x + 1$ 也在计数器中，说明当前存在跨越 $i$ 左右两侧的子数组，其中位数为 $k$，答案变量 $ans$ 增加计数器中对应的值，即 $ans += cnt[-x] + cnt[-x + 1]$。

最后，返回答案变量 $ans$ 即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组的长度。

> 在编码上，我们可以直接开一个长度为 $2 \times n + 1$ 的数组，用于统计当前数组中，比 $k$ 大的元素的个数与比 $k$ 小的元素的个数的差值，每一次我们将差值加上 $n$，即可将差值的范围从 $[-n, n]$ 转换为 $[0, 2n]$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        i = nums.index(k)
        cnt = Counter()
        ans = 1
        x = 0
        for v in nums[i + 1 :]:
            x += 1 if v > k else -1
            ans += 0 <= x <= 1
            cnt[x] += 1
        x = 0
        for j in range(i - 1, -1, -1):
            x += 1 if nums[j] > k else -1
            ans += 0 <= x <= 1
            ans += cnt[-x] + cnt[-x + 1]
        return ans
```

#### Java

```java
class Solution {
    public int countSubarrays(int[] nums, int k) {
        int n = nums.length;
        int i = 0;
        for (; nums[i] != k; ++i) {
        }
        int[] cnt = new int[n << 1 | 1];
        int ans = 1;
        int x = 0;
        for (int j = i + 1; j < n; ++j) {
            x += nums[j] > k ? 1 : -1;
            if (x >= 0 && x <= 1) {
                ++ans;
            }
            ++cnt[x + n];
        }
        x = 0;
        for (int j = i - 1; j >= 0; --j) {
            x += nums[j] > k ? 1 : -1;
            if (x >= 0 && x <= 1) {
                ++ans;
            }
            ans += cnt[-x + n] + cnt[-x + 1 + n];
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int i = find(nums.begin(), nums.end(), k) - nums.begin();
        int cnt[n << 1 | 1];
        memset(cnt, 0, sizeof(cnt));
        int ans = 1;
        int x = 0;
        for (int j = i + 1; j < n; ++j) {
            x += nums[j] > k ? 1 : -1;
            if (x >= 0 && x <= 1) {
                ++ans;
            }
            ++cnt[x + n];
        }
        x = 0;
        for (int j = i - 1; ~j; --j) {
            x += nums[j] > k ? 1 : -1;
            if (x >= 0 && x <= 1) {
                ++ans;
            }
            ans += cnt[-x + n] + cnt[-x + 1 + n];
        }
        return ans;
    }
};
```

#### Go

```go
func countSubarrays(nums []int, k int) int {
	i, n := 0, len(nums)
	for nums[i] != k {
		i++
	}
	ans := 1
	cnt := make([]int, n<<1|1)
	x := 0
	for j := i + 1; j < n; j++ {
		if nums[j] > k {
			x++
		} else {
			x--
		}
		if x >= 0 && x <= 1 {
			ans++
		}
		cnt[x+n]++
	}
	x = 0
	for j := i - 1; j >= 0; j-- {
		if nums[j] > k {
			x++
		} else {
			x--
		}
		if x >= 0 && x <= 1 {
			ans++
		}
		ans += cnt[-x+n] + cnt[-x+1+n]
	}
	return ans
}
```

#### TypeScript

```ts
function countSubarrays(nums: number[], k: number): number {
    const i = nums.indexOf(k);
    const n = nums.length;
    const cnt = new Array((n << 1) | 1).fill(0);
    let ans = 1;
    let x = 0;
    for (let j = i + 1; j < n; ++j) {
        x += nums[j] > k ? 1 : -1;
        ans += x >= 0 && x <= 1 ? 1 : 0;
        ++cnt[x + n];
    }
    x = 0;
    for (let j = i - 1; ~j; --j) {
        x += nums[j] > k ? 1 : -1;
        ans += x >= 0 && x <= 1 ? 1 : 0;
        ans += cnt[-x + n] + cnt[-x + 1 + n];
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2489. 固定比率的子字符串数 🔒](https://leetcode.cn/problems/number-of-substrings-with-fixed-ratio){#2489}

{{< tabs "2489" >}}

{{% tab "python" %}}
```python
class Solution:
    def fixedRatio(self, s: str, num1: int, num2: int) -> int:
        n0 = n1 = 0
        ans = 0
        cnt = Counter({0: 1})
        for c in s:
            n0 += c == '0'
            n1 += c == '1'
            x = n1 * num1 - n0 * num2
            ans += cnt[x]
            cnt[x] += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long fixedRatio(String s, int num1, int num2) {
        long n0 = 0, n1 = 0;
        long ans = 0;
        Map<Long, Long> cnt = new HashMap<>();
        cnt.put(0L, 1L);
        for (char c : s.toCharArray()) {
            n0 += c == '0' ? 1 : 0;
            n1 += c == '1' ? 1 : 0;
            long x = n1 * num1 - n0 * num2;
            ans += cnt.getOrDefault(x, 0L);
            cnt.put(x, cnt.getOrDefault(x, 0L) + 1);
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
using ll = long long;

class Solution {
public:
    long long fixedRatio(string s, int num1, int num2) {
        ll n0 = 0, n1 = 0;
        ll ans = 0;
        unordered_map<ll, ll> cnt;
        cnt[0] = 1;
        for (char& c : s) {
            n0 += c == '0';
            n1 += c == '1';
            ll x = n1 * num1 - n0 * num2;
            ans += cnt[x];
            ++cnt[x];
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func fixedRatio(s string, num1 int, num2 int) int64 {
	n0, n1 := 0, 0
	ans := 0
	cnt := map[int]int{0: 1}
	for _, c := range s {
		if c == '0' {
			n0++
		} else {
			n1++
		}
		x := n1*num1 - n0*num2
		ans += cnt[x]
		cnt[x]++
	}
	return int64(ans)
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个二进制字符串 <code>s</code>&nbsp;和两个整数 <code>num1</code> 和 <code>num2</code>。<code>num1</code> 和 <code>num2</code> 为互质。</p>

<p><strong>比率子串&nbsp;</strong>是 s 的子串，其中子串中 <code>0</code> 的数量与 <code>1</code>&nbsp;的数量之比正好是&nbsp;<code>num1 : num2</code>。</p>

<ul>
	<li>例如，如果 <code>num1 = 2</code>&nbsp;和 <code>num2 = 3</code>，那么 <code>"01011"</code>&nbsp;和 <code>"1110000111"</code>&nbsp;是比率子串，而 <code>"11000"</code>&nbsp;不是。</li>
</ul>

<p>返回 <em><code>s</code> 的&nbsp;<strong>非空&nbsp;</strong>比率子串的个数。</em></p>

<p><b>注意</b>:</p>

<ul>
	<li><strong>子串&nbsp;</strong>是字符串中连续的字符序列。</li>
	<li>如果 <code>gcd(x, y) == 1</code>，则 <code>x</code> 和 <code>y</code> 为&nbsp;<strong>互质</strong>，其中 <code>gcd(x, y)</code>&nbsp;为 <code>x</code>&nbsp;和 <code>y</code> 的最大公约数。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> s = "0110011", num1 = 1, num2 = 2
<strong>输出:</strong> 4
<strong>解释:</strong> 有 4 个非空的比率子串。
- 子字符串 s[0..2]: "<u>011</u>0011"。它包含一个 0 和两个 1。比例是 1:2。
- 子字符串 s[1..4]: "0<u>110</u>011"。它包含一个 0 和两个 1。比例是 1:2。
- 子字符串 s[4..6]: "0110<u>011</u>"。它包含一个 0 和两个 1。比例是 1:2。
- 子字符串 s[1..6]: "0<u>110011</u>"。它包含两个 0 和四个 1。比例是 2:4 == 1:2。
它可以显示没有更多的比率子串。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> s = "10101", num1 = 3, num2 = 1
<strong>输出:</strong> 0
<strong>解释:</strong> s 没有比率子串，返回 0。
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= num1, num2 &lt;= s.length</code></li>
	<li><code>num1</code> 和&nbsp;<code>num2</code> 互质。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前缀和 + 计数

我们用 $one[i]$ 表示字符串 $s[0,..i]$ 中 $1$ 的个数，用 $zero[i]$ 表示字符串 $s[0,..i]$ 中 $0$ 的个数。子串符合条件，需要满足

$$
\frac{zero[j] - zero[i]}{one[j] - one[i]} = \frac{num1}{num2}
$$

其中 $i < j$。我们可以将上式转化为

$$
one[j] \times num1 - zero[j] \times num2 = one[i] \times num1 - zero[i] \times num2
$$

遍历到下标 $j$ 时，我们只需要统计有多少个下标 $i$ 满足上式即可。因此，我们可以用哈希表记录 $one[i] \times num1 - zero[i] \times num2$ 出现的次数，遍历到下标 $j$ 时，只需要统计 $one[j] \times num1 - zero[j] \times num2$ 出现的次数即可。

哈希表初始时只有一个键值对 $(0, 1)$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为字符串 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def fixedRatio(self, s: str, num1: int, num2: int) -> int:
        n0 = n1 = 0
        ans = 0
        cnt = Counter({0: 1})
        for c in s:
            n0 += c == '0'
            n1 += c == '1'
            x = n1 * num1 - n0 * num2
            ans += cnt[x]
            cnt[x] += 1
        return ans
```

#### Java

```java
class Solution {
    public long fixedRatio(String s, int num1, int num2) {
        long n0 = 0, n1 = 0;
        long ans = 0;
        Map<Long, Long> cnt = new HashMap<>();
        cnt.put(0L, 1L);
        for (char c : s.toCharArray()) {
            n0 += c == '0' ? 1 : 0;
            n1 += c == '1' ? 1 : 0;
            long x = n1 * num1 - n0 * num2;
            ans += cnt.getOrDefault(x, 0L);
            cnt.put(x, cnt.getOrDefault(x, 0L) + 1);
        }
        return ans;
    }
}
```

#### C++

```cpp
using ll = long long;

class Solution {
public:
    long long fixedRatio(string s, int num1, int num2) {
        ll n0 = 0, n1 = 0;
        ll ans = 0;
        unordered_map<ll, ll> cnt;
        cnt[0] = 1;
        for (char& c : s) {
            n0 += c == '0';
            n1 += c == '1';
            ll x = n1 * num1 - n0 * num2;
            ans += cnt[x];
            ++cnt[x];
        }
        return ans;
    }
};
```

#### Go

```go
func fixedRatio(s string, num1 int, num2 int) int64 {
	n0, n1 := 0, 0
	ans := 0
	cnt := map[int]int{0: 1}
	for _, c := range s {
		if c == '0' {
			n0++
		} else {
			n1++
		}
		x := n1*num1 - n0*num2
		ans += cnt[x]
		cnt[x]++
	}
	return int64(ans)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
