---
title: "1250_检查「好数组」"
date: 2025-10-08T18:37:06+08:00
weight: 6
tags: [位运算, 动态规划, 哈希表, 回溯, 字符串, 并查集, 广度优先搜索, 排序, 数学, 数据库, 数组, 数论, 树, 模拟, 深度优先搜索, 状态压缩, 矩阵, 贪心]
---

{{< markmap >}}
### [1250_检查「好数组」](#1250)
#### [数组](#1250)
#### [数学](#1250)
#### [数论](#1250)
### [1251_平均售价](#1251)
#### [数据库](#1251)
### [1252_奇数值单元格的数目](#1252)
#### [数组](#1252)
#### [数学](#1252)
#### [模拟](#1252)
### [1253_重构 2 行二进制矩阵](#1253)
#### [贪心](#1253)
#### [数组](#1253)
#### [矩阵](#1253)
### [1254_统计封闭岛屿的数目](#1254)
#### [深度优先搜索](#1254)
#### [广度优先搜索](#1254)
#### [并查集](#1254)
#### [数组](#1254)
#### [矩阵](#1254)
### [1255_得分最高的单词集合](#1255)
#### [位运算](#1255)
#### [数组](#1255)
#### [字符串](#1255)
#### [动态规划](#1255)
#### [回溯](#1255)
#### [状态压缩](#1255)
### [1256_加密数字 🔒](#1256)
#### [位运算](#1256)
#### [数学](#1256)
#### [字符串](#1256)
### [1257_最小公共区域 🔒](#1257)
#### [树](#1257)
#### [深度优先搜索](#1257)
#### [广度优先搜索](#1257)
#### [数组](#1257)
#### [哈希表](#1257)
#### [字符串](#1257)
### [1258_近义词句子 🔒](#1258)
#### [排序](#1258)
#### [并查集](#1258)
#### [数组](#1258)
#### [哈希表](#1258)
#### [字符串](#1258)
#### [回溯](#1258)
### [1259_不相交的握手 🔒](#1259)
#### [数学](#1259)
#### [动态规划](#1259)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1250_检查「好数组」
___
#### 数组
___
#### 数学
___
#### 数论
---
### 1251_平均售价
___
#### 数据库
---
### 1252_奇数值单元格的数目
___
#### 数组
___
#### 数学
___
#### 模拟
---
### 1253_重构 2 行二进制矩阵
___
#### 贪心
___
#### 数组
___
#### 矩阵
---
### 1254_统计封闭岛屿的数目
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
### 1255_得分最高的单词集合
___
#### 位运算
___
#### 数组
___
#### 字符串
___
#### 动态规划
___
#### 回溯
___
#### 状态压缩
---
### 1256_加密数字 🔒
___
#### 位运算
___
#### 数学
___
#### 字符串
---
### 1257_最小公共区域 🔒
___
#### 树
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 数组
___
#### 哈希表
___
#### 字符串
---
### 1258_近义词句子 🔒
___
#### 排序
___
#### 并查集
___
#### 数组
___
#### 哈希表
___
#### 字符串
___
#### 回溯
---
### 1259_不相交的握手 🔒
___
#### 数学
___
#### 动态规划
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 位运算 | 动态规划 | 哈希表 |
| 回溯 | 字符串 | 并查集 |
| 广度优先搜索 | 排序 | 数学 |
| 数据库 | 数组 | 数论 |
| 树 | 模拟 | 深度优先搜索 |
| 状态压缩 | 矩阵 | 贪心 |

# [1250. 检查「好数组」](https://leetcode.cn/problems/check-if-it-is-a-good-array){#1250}

{{< tabs "1250" >}}

{{% tab "python" %}}
```python
class Solution:
    def isGoodArray(self, nums: List[int]) -> bool:
        return reduce(gcd, nums) == 1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean isGoodArray(int[] nums) {
        int g = 0;
        for (int x : nums) {
            g = gcd(x, g);
        }
        return g == 1;
    }

    private int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int g = 0;
        for (int x : nums) {
            g = gcd(x, g);
        }
        return g == 1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func isGoodArray(nums []int) bool {
	g := 0
	for _, x := range nums {
		g = gcd(x, g)
	}
	return g == 1
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function isGoodArray(nums: number[]): boolean {
    return nums.reduce(gcd) === 1;
}

function gcd(a: number, b: number): number {
    return b === 0 ? a : gcd(b, a % b);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个正整数数组 <code>nums</code>，你需要从中任选一些子集，然后将子集中每一个数乘以一个 <strong>任意整数</strong>，并求出他们的和。</p>

<p>假如该和结果为&nbsp;<code>1</code>，那么原数组就是一个「<strong>好数组</strong>」，则返回 <code>True</code>；否则请返回 <code>False</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [12,5,7,23]
<strong>输出：</strong>true
<strong>解释：</strong>挑选数字 5 和 7。
5*3 + 7*(-2) = 1
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [29,6,10]
<strong>输出：</strong>true
<strong>解释：</strong>挑选数字 29, 6 和 10。
29*1 + 6*(-3) + 10*(-1) = 1
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>nums = [3,6]
<strong>输出：</strong>false
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10^5</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10^9</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数学（裴蜀定理）

我们先可以考虑选取两个数的情况，若选取的数是 $a$ 和 $b$，那么根据题目的要求，我们需要满足 $a \times x + b \times y = 1$，其中 $x$ 和 $y$ 是任意整数。

根据裴蜀定理，可以得知，如果 $a$ 和 $b$ 互质，那么上述等式一定有解。实际上，裴蜀定理也可以推广到多个数的情况，即如果 $a_1, a_2, \cdots, a_i$ 互质，那么 $a_1 \times x_1 + a_2 \times x_2 + \cdots + a_i \times x_i = 1$ 一定有解，其中 $x_1, x_2, \cdots, x_i$ 是任意整数。

因此，我们只需要判断在数组 `nums` 中是否存在 $i$ 个互质的数即可。两个数互质的充要条件是它们的最大公约数为 $1$。如果数组 `nums` 存在 $i$ 个互质的数，那么数组 `nums` 中的所有数的最大公约数也为 $1$。

所以我们将题目转化为：判断数组 `nums` 中的所有数的最大公约数是否为 $1$。遍历数组 `nums`，求出数组 `nums` 中的所有数的最大公约数即可。

时间复杂度 $O(n + log m)$，空间复杂度 $O(1)$，其中 $n$ 是数组 `nums` 的长度，而 $m$ 是数组 `nums` 中的最大值。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def isGoodArray(self, nums: List[int]) -> bool:
        return reduce(gcd, nums) == 1
```

#### Java

```java
class Solution {
    public boolean isGoodArray(int[] nums) {
        int g = 0;
        for (int x : nums) {
            g = gcd(x, g);
        }
        return g == 1;
    }

    private int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int g = 0;
        for (int x : nums) {
            g = gcd(x, g);
        }
        return g == 1;
    }
};
```

#### Go

```go
func isGoodArray(nums []int) bool {
	g := 0
	for _, x := range nums {
		g = gcd(x, g)
	}
	return g == 1
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}
```

#### TypeScript

```ts
function isGoodArray(nums: number[]): boolean {
    return nums.reduce(gcd) === 1;
}

function gcd(a: number, b: number): number {
    return b === 0 ? a : gcd(b, a % b);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1251. 平均售价](https://leetcode.cn/problems/average-selling-price){#1251}

{{< tabs "1251" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT
    p.product_id,
    IFNULL(ROUND(SUM(price * units) / SUM(units), 2), 0) AS average_price
FROM
    Prices AS p
    LEFT JOIN UnitsSold AS u
        ON p.product_id = u.product_id AND purchase_date BETWEEN start_date AND end_date
GROUP BY 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code>Prices</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| product_id    | int     |
| start_date    | date    |
| end_date      | date    |
| price         | int     |
+---------------+---------+
(product_id，start_date，end_date) 是 <code>prices</code> 表的主键（具有唯一值的列的组合）。
<code>prices</code> 表的每一行表示的是某个产品在一段时期内的价格。
每个产品的对应时间段是不会重叠的，这也意味着同一个产品的价格时段不会出现交叉。</pre>

<p>&nbsp;</p>

<p>表：<code>UnitsSold</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| product_id    | int     |
| purchase_date | date    |
| units         | int     |
+---------------+---------+
<span style="white-space: pre-wrap;">该表可能包含重复数据</span>。
<span style="white-space: pre-wrap;">该</span>表的每一行表示的是每种产品的出售日期，单位和产品 id。</pre>

<p>&nbsp;</p>

<p>编写解决方案以查找每种产品的平均售价。<code>average_price</code> 应该 <strong>四舍五入到小数点后两位</strong>。如果产品没有任何售出，则假设其平均售价为 0。</p>

<p>返回结果表 <strong>无顺序要求</strong> 。</p>

<p>结果格式如下例所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
Prices table:
+------------+------------+------------+--------+
| product_id | start_date | end_date   | price  |
+------------+------------+------------+--------+
| 1          | 2019-02-17 | 2019-02-28 | 5      |
| 1          | 2019-03-01 | 2019-03-22 | 20     |
| 2          | 2019-02-01 | 2019-02-20 | 15     |
| 2          | 2019-02-21 | 2019-03-31 | 30     |
+------------+------------+------------+--------+
UnitsSold table:
+------------+---------------+-------+
| product_id | purchase_date | units |
+------------+---------------+-------+
| 1          | 2019-02-25    | 100   |
| 1          | 2019-03-01    | 15    |
| 2          | 2019-02-10    | 200   |
| 2          | 2019-03-22    | 30    |
+------------+---------------+-------+
<strong>输出：</strong>
+------------+---------------+
| product_id | average_price |
+------------+---------------+
| 1          | 6.96          |
| 2          | 16.96         |
+------------+---------------+
<strong>解释：</strong>
平均售价 = 产品总价 / 销售的产品数量。
产品 1 的平均售价 = ((100 * 5)+(15 * 20) )/ 115 = 6.96
产品 2 的平均售价 = ((200 * 15)+(30 * 30) )/ 230 = 16.96</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：左连接 + 分组统计

我们可以使用左连接，将 `Prices` 表和 `UnitsSold` 表连接起来，连接条件为 `product_id` 相等，并且 `purchase_date` 在 `start_date` 和 `end_date` 之间。然后使用 `GROUP BY` 子句对 `product_id` 进行分组，使用 `AVG` 函数计算平均价格。注意，如果某个产品没有销售记录，那么 `AVG` 函数会返回 `NULL`，因此我们可以使用 `IFNULL` 函数将其转换为 $0$。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT
    p.product_id,
    IFNULL(ROUND(SUM(price * units) / SUM(units), 2), 0) AS average_price
FROM
    Prices AS p
    LEFT JOIN UnitsSold AS u
        ON p.product_id = u.product_id AND purchase_date BETWEEN start_date AND end_date
GROUP BY 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1252. 奇数值单元格的数目](https://leetcode.cn/problems/cells-with-odd-values-in-a-matrix){#1252}

{{< tabs "1252" >}}

{{% tab "python" %}}
```python
class Solution:
    def oddCells(self, m: int, n: int, indices: List[List[int]]) -> int:
        row = [0] * m
        col = [0] * n
        for r, c in indices:
            row[r] += 1
            col[c] += 1
        cnt1 = sum(v % 2 for v in row)
        cnt2 = sum(v % 2 for v in col)
        return cnt1 * (n - cnt2) + cnt2 * (m - cnt1)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int oddCells(int m, int n, int[][] indices) {
        int[] row = new int[m];
        int[] col = new int[n];
        for (int[] e : indices) {
            int r = e[0], c = e[1];
            row[r]++;
            col[c]++;
        }
        int cnt1 = 0, cnt2 = 0;
        for (int v : row) {
            cnt1 += v % 2;
        }
        for (int v : col) {
            cnt2 += v % 2;
        }
        return cnt1 * (n - cnt2) + cnt2 * (m - cnt1);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<int> row(m);
        vector<int> col(n);
        for (auto& e : indices) {
            int r = e[0], c = e[1];
            row[r]++;
            col[c]++;
        }
        int cnt1 = 0, cnt2 = 0;
        for (int v : row) {
            cnt1 += v % 2;
        }
        for (int v : col) {
            cnt2 += v % 2;
        }
        return cnt1 * (n - cnt2) + cnt2 * (m - cnt1);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func oddCells(m int, n int, indices [][]int) int {
	row := make([]int, m)
	col := make([]int, n)
	for _, e := range indices {
		r, c := e[0], e[1]
		row[r]++
		col[c]++
	}
	cnt1, cnt2 := 0, 0
	for _, v := range row {
		cnt1 += v % 2
	}
	for _, v := range col {
		cnt2 += v % 2
	}
	return cnt1*(n-cnt2) + cnt2*(m-cnt1)
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个 <code>m x n</code> 的矩阵，最开始的时候，每个单元格中的值都是 <code>0</code>。</p>

<p>另有一个二维索引数组 <code>indices</code>，<code>indices[i] = [ri, ci]</code> 指向矩阵中的某个位置，其中 <code>ri</code> 和 <code>ci</code> 分别表示指定的行和列（<strong>从 <code>0</code> 开始编号</strong>）。</p>

<p>对 <code>indices[i]</code> 所指向的每个位置，应同时执行下述增量操作：</p>

<ol>
	<li><code>r<sub>i</sub></code> 行上的所有单元格，加 <code>1</code> 。</li>
	<li><code>c<sub>i</sub></code> 列上的所有单元格，加 <code>1</code> 。</li>
</ol>

<p>给你 <code>m</code>、<code>n</code> 和 <code>indices</code> 。请你在执行完所有 <code>indices</code> 指定的增量操作后，返回矩阵中 <strong>奇数值单元格</strong> 的数目。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1200-1299/1252.Cells%20with%20Odd%20Values%20in%20a%20Matrix/images/e1.png" style="height: 118px; width: 600px;" /></p>

<pre>
<strong>输入：</strong>m = 2, n = 3, indices = [[0,1],[1,1]]
<strong>输出：</strong>6
<strong>解释：</strong>最开始的矩阵是 [[0,0,0],[0,0,0]]。
第一次增量操作后得到 [[1,2,1],[0,1,0]]。
最后的矩阵是 [[1,3,1],[1,3,1]]，里面有 6 个奇数。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1200-1299/1252.Cells%20with%20Odd%20Values%20in%20a%20Matrix/images/e2.png" style="height: 150px; width: 600px;" /></p>

<pre>
<strong>输入：</strong>m = 2, n = 2, indices = [[1,1],[0,0]]
<strong>输出：</strong>0
<strong>解释：</strong>最后的矩阵是 [[2,2],[2,2]]，里面没有奇数。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= m, n <= 50</code></li>
	<li><code>1 <= indices.length <= 100</code></li>
	<li><code>0 <= r<sub>i</sub> < m</code></li>
	<li><code>0 <= c<sub>i</sub> < n</code></li>
</ul>

<p> </p>

<p><strong>进阶：</strong>你可以设计一个时间复杂度为 <code>O(n + m + indices.length)</code> 且仅用 <code>O(n + m)</code> 额外空间的算法来解决此问题吗？</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们创建一个矩阵 $g$ 来存放操作的结果。对于 $\textit{indices}$ 中的每一对 $(r_i, c_i)$，我们将矩阵第 $r_i$ 行的所有数加 $1$，第 $c_i$ 列的所有元素加 $1$。

模拟结束后，遍历矩阵，统计奇数的个数。

时间复杂度 $O(k \times (m + n) + m \times n)$，空间复杂度 $O(m \times n)$。其中 $k$ 为 $\textit{indices}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def oddCells(self, m: int, n: int, indices: List[List[int]]) -> int:
        g = [[0] * n for _ in range(m)]
        for r, c in indices:
            for i in range(m):
                g[i][c] += 1
            for j in range(n):
                g[r][j] += 1
        return sum(v % 2 for row in g for v in row)
```

#### Java

```java
class Solution {
    public int oddCells(int m, int n, int[][] indices) {
        int[][] g = new int[m][n];
        for (int[] e : indices) {
            int r = e[0], c = e[1];
            for (int i = 0; i < m; ++i) {
                g[i][c]++;
            }
            for (int j = 0; j < n; ++j) {
                g[r][j]++;
            }
        }
        int ans = 0;
        for (int[] row : g) {
            for (int v : row) {
                ans += v % 2;
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
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<vector<int>> g(m, vector<int>(n));
        for (auto& e : indices) {
            int r = e[0], c = e[1];
            for (int i = 0; i < m; ++i) {
                ++g[i][c];
            }
            for (int j = 0; j < n; ++j) {
                ++g[r][j];
            }
        }
        int ans = 0;
        for (auto& row : g) {
            for (int v : row) {
                ans += v % 2;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func oddCells(m int, n int, indices [][]int) int {
	g := make([][]int, m)
	for i := range g {
		g[i] = make([]int, n)
	}
	for _, e := range indices {
		r, c := e[0], e[1]
		for i := 0; i < m; i++ {
			g[i][c]++
		}
		for j := 0; j < n; j++ {
			g[r][j]++
		}
	}
	ans := 0
	for _, row := range g {
		for _, v := range row {
			ans += v % 2
		}
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：空间优化

我们可以使用行数组 $\textit{row}$ 和列数组 $\textit{col}$ 来记录每一行、每一列被增加的次数。对于 $\textit{indices}$ 中的每一对 $(r_i, c_i)$，我们将 $\textit{row}[r_i]$ 和 $\textit{col}[c_i]$ 分别加 $1$。

操作结束后，可以算出 $(i, j)$ 位置的计数为 $\textit{row}[i]+\textit{col}[j]$。遍历矩阵，统计奇数的个数。

时间复杂度 $O(k + m \times n)$，空间复杂度 $O(m + n)$。其中 $k$ 为 $\textit{indices}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def oddCells(self, m: int, n: int, indices: List[List[int]]) -> int:
        row = [0] * m
        col = [0] * n
        for r, c in indices:
            row[r] += 1
            col[c] += 1
        return sum((i + j) % 2 for i in row for j in col)
```

#### Java

```java
class Solution {
    public int oddCells(int m, int n, int[][] indices) {
        int[] row = new int[m];
        int[] col = new int[n];
        for (int[] e : indices) {
            int r = e[0], c = e[1];
            row[r]++;
            col[c]++;
        }
        int ans = 0;
        for (int i : row) {
            for (int j : col) {
                ans += (i + j) % 2;
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
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<int> row(m);
        vector<int> col(n);
        for (auto& e : indices) {
            int r = e[0], c = e[1];
            row[r]++;
            col[c]++;
        }
        int ans = 0;
        for (int i : row) {
            for (int j : col) {
                ans += (i + j) % 2;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func oddCells(m int, n int, indices [][]int) int {
	row := make([]int, m)
	col := make([]int, n)
	for _, e := range indices {
		r, c := e[0], e[1]
		row[r]++
		col[c]++
	}
	ans := 0
	for _, i := range row {
		for _, j := range col {
			ans += (i + j) % 2
		}
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法三：数学优化

我们注意到，只有当 $\textit{row}[i]$ 和 $\textit{col}[j]$ 中恰好为“一奇一偶”时，矩阵 $(i, j)$ 位置的数才会是奇数。

我们统计 $\textit{row}$ 中的奇数个数，记为 $\textit{cnt1}$；而 $\textit{col}$ 中的奇数个数，记为 $\textit{cnt2}$。那么最终得到的奇数个数为 $\textit{cnt1} \times (n - \textit{cnt2}) + \textit{cnt2} \times (m - \textit{cnt1})$。

时间复杂度 $O(k + m + n)$，空间复杂度 $O(m + n)$。其中 $k$ 为 $\textit{indices}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def oddCells(self, m: int, n: int, indices: List[List[int]]) -> int:
        row = [0] * m
        col = [0] * n
        for r, c in indices:
            row[r] += 1
            col[c] += 1
        cnt1 = sum(v % 2 for v in row)
        cnt2 = sum(v % 2 for v in col)
        return cnt1 * (n - cnt2) + cnt2 * (m - cnt1)
```

#### Java

```java
class Solution {
    public int oddCells(int m, int n, int[][] indices) {
        int[] row = new int[m];
        int[] col = new int[n];
        for (int[] e : indices) {
            int r = e[0], c = e[1];
            row[r]++;
            col[c]++;
        }
        int cnt1 = 0, cnt2 = 0;
        for (int v : row) {
            cnt1 += v % 2;
        }
        for (int v : col) {
            cnt2 += v % 2;
        }
        return cnt1 * (n - cnt2) + cnt2 * (m - cnt1);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<int> row(m);
        vector<int> col(n);
        for (auto& e : indices) {
            int r = e[0], c = e[1];
            row[r]++;
            col[c]++;
        }
        int cnt1 = 0, cnt2 = 0;
        for (int v : row) {
            cnt1 += v % 2;
        }
        for (int v : col) {
            cnt2 += v % 2;
        }
        return cnt1 * (n - cnt2) + cnt2 * (m - cnt1);
    }
};
```

#### Go

```go
func oddCells(m int, n int, indices [][]int) int {
	row := make([]int, m)
	col := make([]int, n)
	for _, e := range indices {
		r, c := e[0], e[1]
		row[r]++
		col[c]++
	}
	cnt1, cnt2 := 0, 0
	for _, v := range row {
		cnt1 += v % 2
	}
	for _, v := range col {
		cnt2 += v % 2
	}
	return cnt1*(n-cnt2) + cnt2*(m-cnt1)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1253. 重构 2 行二进制矩阵](https://leetcode.cn/problems/reconstruct-a-2-row-binary-matrix){#1253}

{{< tabs "1253" >}}

{{% tab "python" %}}
```python
class Solution:
    def reconstructMatrix(
        self, upper: int, lower: int, colsum: List[int]
    ) -> List[List[int]]:
        n = len(colsum)
        ans = [[0] * n for _ in range(2)]
        for j, v in enumerate(colsum):
            if v == 2:
                ans[0][j] = ans[1][j] = 1
                upper, lower = upper - 1, lower - 1
            if v == 1:
                if upper > lower:
                    upper -= 1
                    ans[0][j] = 1
                else:
                    lower -= 1
                    ans[1][j] = 1
            if upper < 0 or lower < 0:
                return []
        return ans if lower == upper == 0 else []
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<List<Integer>> reconstructMatrix(int upper, int lower, int[] colsum) {
        int n = colsum.length;
        List<Integer> first = new ArrayList<>();
        List<Integer> second = new ArrayList<>();
        for (int j = 0; j < n; ++j) {
            int a = 0, b = 0;
            if (colsum[j] == 2) {
                a = b = 1;
                upper--;
                lower--;
            } else if (colsum[j] == 1) {
                if (upper > lower) {
                    upper--;
                    a = 1;
                } else {
                    lower--;
                    b = 1;
                }
            }
            if (upper < 0 || lower < 0) {
                break;
            }
            first.add(a);
            second.add(b);
        }
        return upper == 0 && lower == 0 ? List.of(first, second) : List.of();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int n = colsum.size();
        vector<vector<int>> ans(2, vector<int>(n));
        for (int j = 0; j < n; ++j) {
            if (colsum[j] == 2) {
                ans[0][j] = ans[1][j] = 1;
                upper--;
                lower--;
            }
            if (colsum[j] == 1) {
                if (upper > lower) {
                    upper--;
                    ans[0][j] = 1;
                } else {
                    lower--;
                    ans[1][j] = 1;
                }
            }
            if (upper < 0 || lower < 0) {
                break;
            }
        }
        return upper || lower ? vector<vector<int>>() : ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func reconstructMatrix(upper int, lower int, colsum []int) [][]int {
	n := len(colsum)
	ans := make([][]int, 2)
	for i := range ans {
		ans[i] = make([]int, n)
	}
	for j, v := range colsum {
		if v == 2 {
			ans[0][j], ans[1][j] = 1, 1
			upper--
			lower--
		}
		if v == 1 {
			if upper > lower {
				upper--
				ans[0][j] = 1
			} else {
				lower--
				ans[1][j] = 1
			}
		}
		if upper < 0 || lower < 0 {
			break
		}
	}
	if upper != 0 || lower != 0 {
		return [][]int{}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function reconstructMatrix(upper: number, lower: number, colsum: number[]): number[][] {
    const n = colsum.length;
    const ans: number[][] = Array(2)
        .fill(0)
        .map(() => Array(n).fill(0));
    for (let j = 0; j < n; ++j) {
        if (colsum[j] === 2) {
            ans[0][j] = ans[1][j] = 1;
            upper--;
            lower--;
        } else if (colsum[j] === 1) {
            if (upper > lower) {
                ans[0][j] = 1;
                upper--;
            } else {
                ans[1][j] = 1;
                lower--;
            }
        }
        if (upper < 0 || lower < 0) {
            break;
        }
    }
    return upper || lower ? [] : ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个&nbsp;<code>2</code>&nbsp;行 <code>n</code> 列的二进制数组：</p>

<ul>
	<li>矩阵是一个二进制矩阵，这意味着矩阵中的每个元素不是&nbsp;<code>0</code>&nbsp;就是&nbsp;<code>1</code>。</li>
	<li>第 <code>0</code> 行的元素之和为&nbsp;<code>upper</code>。</li>
	<li>第 <code>1</code> 行的元素之和为 <code>lower</code>。</li>
	<li>第 <code>i</code> 列（从 <code>0</code> 开始编号）的元素之和为&nbsp;<code>colsum[i]</code>，<code>colsum</code>&nbsp;是一个长度为&nbsp;<code>n</code>&nbsp;的整数数组。</li>
</ul>

<p>你需要利用&nbsp;<code>upper</code>，<code>lower</code>&nbsp;和&nbsp;<code>colsum</code>&nbsp;来重构这个矩阵，并以二维整数数组的形式返回它。</p>

<p>如果有多个不同的答案，那么任意一个都可以通过本题。</p>

<p>如果不存在符合要求的答案，就请返回一个空的二维数组。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>upper = 2, lower = 1, colsum = [1,1,1]
<strong>输出：</strong>[[1,1,0],[0,0,1]]
<strong>解释：</strong>[[1,0,1],[0,1,0]] 和 [[0,1,1],[1,0,0]] 也是正确答案。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>upper = 2, lower = 3, colsum = [2,2,1,1]
<strong>输出：</strong>[]
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>upper = 5, lower = 5, colsum = [2,1,2,0,1,0,1,2,0,1]
<strong>输出：</strong>[[1,1,1,0,1,0,0,1,0,0],[1,0,1,0,0,0,1,1,0,1]]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= colsum.length &lt;= 10^5</code></li>
	<li><code>0 &lt;= upper, lower &lt;= colsum.length</code></li>
	<li><code>0 &lt;= colsum[i] &lt;= 2</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心

我们先创建一个答案数组 $ans$，其中 $ans[0]$ 和 $ans[1]$ 分别表示矩阵的第一行和第二行。

接下来，从左到右遍历数组 $colsum$，对于当前遍历到的元素 $colsum[j]$，我们有以下几种情况：

-   如果 $colsum[j] = 2$，那么我们将 $ans[0][j]$ 和 $ans[1][j]$ 都置为 $1$。此时 $upper$ 和 $lower$ 都减去 $1$。
-   如果 $colsum[j] = 1$，那么我们将 $ans[0][j]$ 或 $ans[1][j]$ 置为 $1$。如果 $upper \gt lower$，那么我们优先将 $ans[0][j]$ 置为 $1$，否则我们优先将 $ans[1][j]$ 置为 $1$。此时 $upper$ 或 $lower$ 减去 $1$。
-   如果 $colsum[j] = 0$，那么我们将 $ans[0][j]$ 和 $ans[1][j]$ 都置为 $0$。
-   如果 $upper \lt 0$ 或 $lower \lt 0$，那么说明无法构造出满足要求的矩阵，我们返回一个空数组。

遍历结束，如果 $upper$ 和 $lower$ 都为 $0$，那么我们返回 $ans$，否则我们返回一个空数组。

时间复杂度 $O(n)$，其中 $n$ 是数组 $colsum$ 的长度。忽略答案数组的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def reconstructMatrix(
        self, upper: int, lower: int, colsum: List[int]
    ) -> List[List[int]]:
        n = len(colsum)
        ans = [[0] * n for _ in range(2)]
        for j, v in enumerate(colsum):
            if v == 2:
                ans[0][j] = ans[1][j] = 1
                upper, lower = upper - 1, lower - 1
            if v == 1:
                if upper > lower:
                    upper -= 1
                    ans[0][j] = 1
                else:
                    lower -= 1
                    ans[1][j] = 1
            if upper < 0 or lower < 0:
                return []
        return ans if lower == upper == 0 else []
```

#### Java

```java
class Solution {
    public List<List<Integer>> reconstructMatrix(int upper, int lower, int[] colsum) {
        int n = colsum.length;
        List<Integer> first = new ArrayList<>();
        List<Integer> second = new ArrayList<>();
        for (int j = 0; j < n; ++j) {
            int a = 0, b = 0;
            if (colsum[j] == 2) {
                a = b = 1;
                upper--;
                lower--;
            } else if (colsum[j] == 1) {
                if (upper > lower) {
                    upper--;
                    a = 1;
                } else {
                    lower--;
                    b = 1;
                }
            }
            if (upper < 0 || lower < 0) {
                break;
            }
            first.add(a);
            second.add(b);
        }
        return upper == 0 && lower == 0 ? List.of(first, second) : List.of();
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int n = colsum.size();
        vector<vector<int>> ans(2, vector<int>(n));
        for (int j = 0; j < n; ++j) {
            if (colsum[j] == 2) {
                ans[0][j] = ans[1][j] = 1;
                upper--;
                lower--;
            }
            if (colsum[j] == 1) {
                if (upper > lower) {
                    upper--;
                    ans[0][j] = 1;
                } else {
                    lower--;
                    ans[1][j] = 1;
                }
            }
            if (upper < 0 || lower < 0) {
                break;
            }
        }
        return upper || lower ? vector<vector<int>>() : ans;
    }
};
```

#### Go

```go
func reconstructMatrix(upper int, lower int, colsum []int) [][]int {
	n := len(colsum)
	ans := make([][]int, 2)
	for i := range ans {
		ans[i] = make([]int, n)
	}
	for j, v := range colsum {
		if v == 2 {
			ans[0][j], ans[1][j] = 1, 1
			upper--
			lower--
		}
		if v == 1 {
			if upper > lower {
				upper--
				ans[0][j] = 1
			} else {
				lower--
				ans[1][j] = 1
			}
		}
		if upper < 0 || lower < 0 {
			break
		}
	}
	if upper != 0 || lower != 0 {
		return [][]int{}
	}
	return ans
}
```

#### TypeScript

```ts
function reconstructMatrix(upper: number, lower: number, colsum: number[]): number[][] {
    const n = colsum.length;
    const ans: number[][] = Array(2)
        .fill(0)
        .map(() => Array(n).fill(0));
    for (let j = 0; j < n; ++j) {
        if (colsum[j] === 2) {
            ans[0][j] = ans[1][j] = 1;
            upper--;
            lower--;
        } else if (colsum[j] === 1) {
            if (upper > lower) {
                ans[0][j] = 1;
                upper--;
            } else {
                ans[1][j] = 1;
                lower--;
            }
        }
        if (upper < 0 || lower < 0) {
            break;
        }
    }
    return upper || lower ? [] : ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1254. 统计封闭岛屿的数目](https://leetcode.cn/problems/number-of-closed-islands){#1254}

{{< tabs "1254" >}}

{{% tab "python" %}}
```python
class UnionFind:
    def __init__(self, n: int):
        self.p = list(range(n))
        self.size = [1] * n

    def find(self, x: int) -> int:
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]

    def union(self, a: int, b: int):
        pa, pb = self.find(a), self.find(b)
        if pa != pb:
            if self.size[pa] > self.size[pb]:
                self.p[pb] = pa
                self.size[pa] += self.size[pb]
            else:
                self.p[pa] = pb
                self.size[pb] += self.size[pa]


class Solution:
    def closedIsland(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        uf = UnionFind(m * n + 1)
        for i in range(m):
            for j in range(n):
                if i == 0 or i == m - 1 or j == 0 or j == n - 1:
                    uf.union(i * n + j, m * n)
                if grid[i][j] == 0:
                    if i < m - 1 and grid[i + 1][j] == 0:
                        uf.union(i * n + j, (i + 1) * n + j)
                    if j < n - 1 and grid[i][j + 1] == 0:
                        uf.union(i * n + j, i * n + j + 1)
        ans = 0
        for i in range(m):
            for j in range(n):
                ans += grid[i][j] == 0 and uf.find(i * n + j) == i * n + j
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class UnionFind {
    private int[] p;
    private int[] size;

    public UnionFind(int n) {
        p = new int[n];
        size = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
            size[i] = 1;
        }
    }

    public int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    public void union(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa != pb) {
            if (size[pa] > size[pb]) {
                p[pb] = pa;
                size[pa] += size[pb];
            } else {
                p[pa] = pb;
                size[pb] += size[pa];
            }
        }
    }
}

class Solution {
    public int closedIsland(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        UnionFind uf = new UnionFind(m * n + 1);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    uf.union(i * n + j, m * n);
                }
                if (grid[i][j] == 0) {
                    if (i + 1 < m && grid[i + 1][j] == 0) {
                        uf.union(i * n + j, (i + 1) * n + j);
                    }
                    if (j + 1 < n && grid[i][j + 1] == 0) {
                        uf.union(i * n + j, i * n + j + 1);
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0 && uf.find(i * n + j) == i * n + j) {
                    ++ans;
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
class UnionFind {
public:
    UnionFind(int n) {
        p = vector<int>(n);
        size = vector<int>(n, 1);
        iota(p.begin(), p.end(), 0);
    }

    void unite(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa != pb) {
            if (size[pa] > size[pb]) {
                p[pb] = pa;
                size[pa] += size[pb];
            } else {
                p[pa] = pb;
                size[pb] += size[pa];
            }
        }
    }

    int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

private:
    vector<int> p, size;
};

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        UnionFind uf(m * n + 1);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    uf.unite(i * n + j, m * n);
                }
                if (grid[i][j] == 0) {
                    if (i + 1 < m && grid[i + 1][j] == 0) {
                        uf.unite(i * n + j, (i + 1) * n + j);
                    }
                    if (j + 1 < n && grid[i][j + 1] == 0) {
                        uf.unite(i * n + j, i * n + j + 1);
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans += grid[i][j] == 0 && uf.find(i * n + j) == i * n + j;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
type unionFind struct {
	p, size []int
}

func newUnionFind(n int) *unionFind {
	p := make([]int, n)
	size := make([]int, n)
	for i := range p {
		p[i] = i
		size[i] = 1
	}
	return &unionFind{p, size}
}

func (uf *unionFind) find(x int) int {
	if uf.p[x] != x {
		uf.p[x] = uf.find(uf.p[x])
	}
	return uf.p[x]
}

func (uf *unionFind) union(a, b int) {
	pa, pb := uf.find(a), uf.find(b)
	if pa != pb {
		if uf.size[pa] > uf.size[pb] {
			uf.p[pb] = pa
			uf.size[pa] += uf.size[pb]
		} else {
			uf.p[pa] = pb
			uf.size[pb] += uf.size[pa]
		}
	}
}

func closedIsland(grid [][]int) (ans int) {
	m, n := len(grid), len(grid[0])
	uf := newUnionFind(m*n + 1)
	for i, row := range grid {
		for j, v := range row {
			if i == 0 || i == m-1 || j == 0 || j == n-1 {
				uf.union(i*n+j, m*n)
			}
			if v == 0 {
				if i+1 < m && grid[i+1][j] == 0 {
					uf.union(i*n+j, (i+1)*n+j)
				}
				if j+1 < n && grid[i][j+1] == 0 {
					uf.union(i*n+j, i*n+j+1)
				}
			}
		}
	}
	for i, row := range grid {
		for j, v := range row {
			if v == 0 && uf.find(i*n+j) == i*n+j {
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
function closedIsland(grid: number[][]): number {
    const m = grid.length;
    const n = grid[0].length;
    const uf = new UnionFind(m * n + 1);
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            if (i === 0 || i === m - 1 || j === 0 || j === n - 1) {
                uf.union(i * n + j, m * n);
            }
            if (grid[i][j] === 0) {
                if (i + 1 < m && grid[i + 1][j] === 0) {
                    uf.union(i * n + j, (i + 1) * n + j);
                }
                if (j + 1 < n && grid[i][j + 1] === 0) {
                    uf.union(i * n + j, i * n + j + 1);
                }
            }
        }
    }
    let ans = 0;
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j] === 0 && uf.find(i * n + j) === i * n + j) {
                ++ans;
            }
        }
    }
    return ans;
}

class UnionFind {
    private p: number[];
    private size: number[];

    constructor(n: number) {
        this.p = Array(n)
            .fill(0)
            .map((_, i) => i);
        this.size = Array(n).fill(1);
    }

    find(x: number): number {
        if (this.p[x] !== x) {
            this.p[x] = this.find(this.p[x]);
        }
        return this.p[x];
    }

    union(a: number, b: number): void {
        const [pa, pb] = [this.find(a), this.find(b)];
        if (pa === pb) {
            return;
        }
        if (this.size[pa] > this.size[pb]) {
            this.p[pb] = pa;
            this.size[pa] += this.size[pb];
        } else {
            this.p[pa] = pb;
            this.size[pb] += this.size[pa];
        }
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
class UnionFind {
    private int[] p;
    private int[] size;

    public UnionFind(int n) {
        p = new int[n];
        size = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
            size[i] = 1;
        }
    }

    public int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    public void union(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa != pb) {
            if (size[pa] > size[pb]) {
                p[pb] = pa;
                size[pa] += size[pb];
            } else {
                p[pa] = pb;
                size[pb] += size[pa];
            }
        }
    }
}

public class Solution {
    public int ClosedIsland(int[][] grid) {
        int m = grid.Length, n = grid[0].Length;
        UnionFind uf = new UnionFind(m * n + 1);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    uf.union(i * n + j, m * n);
                }
                if (grid[i][j] == 0) {
                    if (i + 1 < m && grid[i + 1][j] == 0) {
                        uf.union(i * n + j, (i + 1) * n + j);
                    }
                    if (j + 1 < n && grid[i][j + 1] == 0) {
                        uf.union(i * n + j, i * n + j + 1);
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0 && uf.find(i * n + j) == i * n + j) {
                    ++ans;
                }
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

<p>二维矩阵 <code>grid</code>&nbsp;由 <code>0</code>&nbsp;（土地）和 <code>1</code>&nbsp;（水）组成。岛是由最大的4个方向连通的 <code>0</code>&nbsp;组成的群，封闭岛是一个&nbsp;<code>完全</code> 由1包围（左、上、右、下）的岛。</p>

<p>请返回 <em>封闭岛屿</em> 的数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1200-1299/1254.Number%20of%20Closed%20Islands/images/sample_3_1610.png" style="height: 151px; width: 240px;" /></p>

<pre>
<strong>输入：</strong>grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
<strong>输出：</strong>2
<strong>解释：</strong>
灰色区域的岛屿是封闭岛屿，因为这座岛屿完全被水域包围（即被 1 区域包围）。</pre>

<p><strong>示例 2：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1200-1299/1254.Number%20of%20Closed%20Islands/images/sample_4_1610.png" style="height: 98px; width: 160px;" /></p>

<pre>
<strong>输入：</strong>grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
<strong>输出：</strong>1
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>grid = [[1,1,1,1,1,1,1],
&nbsp;            [1,0,0,0,0,0,1],
&nbsp;            [1,0,1,1,1,0,1],
&nbsp;            [1,0,1,0,1,0,1],
&nbsp;            [1,0,1,1,1,0,1],
&nbsp;            [1,0,0,0,0,0,1],
             [1,1,1,1,1,1,1]]
<strong>输出：</strong>2
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= grid.length, grid[0].length &lt;= 100</code></li>
	<li><code>0 &lt;= grid[i][j] &lt;=1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS

遍历矩阵，对于每个陆地，我们进行深度优先搜索，找到与其相连的所有陆地，然后判断是否存在边界上的陆地，如果存在，则不是封闭岛屿，否则是封闭岛屿，答案加一。

最后返回答案即可。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别是矩阵的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def closedIsland(self, grid: List[List[int]]) -> int:
        def dfs(i: int, j: int) -> int:
            res = int(0 < i < m - 1 and 0 < j < n - 1)
            grid[i][j] = 1
            for a, b in pairwise(dirs):
                x, y = i + a, j + b
                if 0 <= x < m and 0 <= y < n and grid[x][y] == 0:
                    res &= dfs(x, y)
            return res

        m, n = len(grid), len(grid[0])
        dirs = (-1, 0, 1, 0, -1)
        return sum(grid[i][j] == 0 and dfs(i, j) for i in range(m) for j in range(n))
```

#### Java

```java
class Solution {
    private int m;
    private int n;
    private int[][] grid;

    public int closedIsland(int[][] grid) {
        m = grid.length;
        n = grid[0].length;
        this.grid = grid;
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    ans += dfs(i, j);
                }
            }
        }
        return ans;
    }

    private int dfs(int i, int j) {
        int res = i > 0 && i < m - 1 && j > 0 && j < n - 1 ? 1 : 0;
        grid[i][j] = 1;
        int[] dirs = {-1, 0, 1, 0, -1};
        for (int k = 0; k < 4; ++k) {
            int x = i + dirs[k], y = j + dirs[k + 1];
            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 0) {
                res &= dfs(x, y);
            }
        }
        return res;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        int dirs[5] = {-1, 0, 1, 0, -1};
        function<int(int, int)> dfs = [&](int i, int j) -> int {
            int res = i > 0 && i < m - 1 && j > 0 && j < n - 1 ? 1 : 0;
            grid[i][j] = 1;
            for (int k = 0; k < 4; ++k) {
                int x = i + dirs[k], y = j + dirs[k + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 0) {
                    res &= dfs(x, y);
                }
            }
            return res;
        };
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans += grid[i][j] == 0 && dfs(i, j);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func closedIsland(grid [][]int) (ans int) {
	m, n := len(grid), len(grid[0])
	dirs := [5]int{-1, 0, 1, 0, -1}
	var dfs func(i, j int) int
	dfs = func(i, j int) int {
		res := 1
		if i == 0 || i == m-1 || j == 0 || j == n-1 {
			res = 0
		}
		grid[i][j] = 1
		for k := 0; k < 4; k++ {
			x, y := i+dirs[k], j+dirs[k+1]
			if x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 0 {
				res &= dfs(x, y)
			}
		}
		return res
	}
	for i, row := range grid {
		for j, v := range row {
			if v == 0 {
				ans += dfs(i, j)
			}
		}
	}
	return
}
```

#### TypeScript

```ts
function closedIsland(grid: number[][]): number {
    const m = grid.length;
    const n = grid[0].length;
    const dirs = [-1, 0, 1, 0, -1];
    const dfs = (i: number, j: number): number => {
        let res = i > 0 && j > 0 && i < m - 1 && j < n - 1 ? 1 : 0;
        grid[i][j] = 1;
        for (let k = 0; k < 4; ++k) {
            const [x, y] = [i + dirs[k], j + dirs[k + 1]];
            if (x >= 0 && y >= 0 && x < m && y < n && grid[x][y] === 0) {
                res &= dfs(x, y);
            }
        }
        return res;
    };
    let ans = 0;
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j] === 0) {
                ans += dfs(i, j);
            }
        }
    }
    return ans;
}
```

#### C#

```cs
public class Solution {
    private int m;
    private int n;
    private int[][] grid;

    public int ClosedIsland(int[][] grid) {
        m = grid.Length;
        n = grid[0].Length;
        this.grid = grid;
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    ans += dfs(i, j);
                }
            }
        }
        return ans;
    }

    private int dfs(int i, int j) {
        int res = i > 0 && i < m - 1 && j > 0 && j < n - 1 ? 1 : 0;
        grid[i][j] = 1;
        int[] dirs = {-1, 0, 1, 0, -1};
        for (int k = 0; k < 4; ++k) {
            int x = i + dirs[k], y = j + dirs[k + 1];
            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 0) {
                res &= dfs(x, y);
            }
        }
        return res;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：并查集

我们可以用并查集维护每一块连通的陆地。

遍历矩阵，如果当前位置是在边界上，我们将其与虚拟节点 $m \times n$ 连接。如果当前位置是陆地，我们将其与下方和右方的陆地连接。

接着，我们再次遍历矩阵，对于每一块陆地，如果其根节点就是本身，那么答案加一。

最后返回答案即可。

时间复杂度 $O(m \times n \times \alpha(m \times n))$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别是矩阵的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class UnionFind:
    def __init__(self, n: int):
        self.p = list(range(n))
        self.size = [1] * n

    def find(self, x: int) -> int:
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]

    def union(self, a: int, b: int):
        pa, pb = self.find(a), self.find(b)
        if pa != pb:
            if self.size[pa] > self.size[pb]:
                self.p[pb] = pa
                self.size[pa] += self.size[pb]
            else:
                self.p[pa] = pb
                self.size[pb] += self.size[pa]


class Solution:
    def closedIsland(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        uf = UnionFind(m * n + 1)
        for i in range(m):
            for j in range(n):
                if i == 0 or i == m - 1 or j == 0 or j == n - 1:
                    uf.union(i * n + j, m * n)
                if grid[i][j] == 0:
                    if i < m - 1 and grid[i + 1][j] == 0:
                        uf.union(i * n + j, (i + 1) * n + j)
                    if j < n - 1 and grid[i][j + 1] == 0:
                        uf.union(i * n + j, i * n + j + 1)
        ans = 0
        for i in range(m):
            for j in range(n):
                ans += grid[i][j] == 0 and uf.find(i * n + j) == i * n + j
        return ans
```

#### Java

```java
class UnionFind {
    private int[] p;
    private int[] size;

    public UnionFind(int n) {
        p = new int[n];
        size = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
            size[i] = 1;
        }
    }

    public int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    public void union(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa != pb) {
            if (size[pa] > size[pb]) {
                p[pb] = pa;
                size[pa] += size[pb];
            } else {
                p[pa] = pb;
                size[pb] += size[pa];
            }
        }
    }
}

class Solution {
    public int closedIsland(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        UnionFind uf = new UnionFind(m * n + 1);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    uf.union(i * n + j, m * n);
                }
                if (grid[i][j] == 0) {
                    if (i + 1 < m && grid[i + 1][j] == 0) {
                        uf.union(i * n + j, (i + 1) * n + j);
                    }
                    if (j + 1 < n && grid[i][j + 1] == 0) {
                        uf.union(i * n + j, i * n + j + 1);
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0 && uf.find(i * n + j) == i * n + j) {
                    ++ans;
                }
            }
        }
        return ans;
    }
}
```

#### C++

```cpp
class UnionFind {
public:
    UnionFind(int n) {
        p = vector<int>(n);
        size = vector<int>(n, 1);
        iota(p.begin(), p.end(), 0);
    }

    void unite(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa != pb) {
            if (size[pa] > size[pb]) {
                p[pb] = pa;
                size[pa] += size[pb];
            } else {
                p[pa] = pb;
                size[pb] += size[pa];
            }
        }
    }

    int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

private:
    vector<int> p, size;
};

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        UnionFind uf(m * n + 1);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    uf.unite(i * n + j, m * n);
                }
                if (grid[i][j] == 0) {
                    if (i + 1 < m && grid[i + 1][j] == 0) {
                        uf.unite(i * n + j, (i + 1) * n + j);
                    }
                    if (j + 1 < n && grid[i][j + 1] == 0) {
                        uf.unite(i * n + j, i * n + j + 1);
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans += grid[i][j] == 0 && uf.find(i * n + j) == i * n + j;
            }
        }
        return ans;
    }
};
```

#### Go

```go
type unionFind struct {
	p, size []int
}

func newUnionFind(n int) *unionFind {
	p := make([]int, n)
	size := make([]int, n)
	for i := range p {
		p[i] = i
		size[i] = 1
	}
	return &unionFind{p, size}
}

func (uf *unionFind) find(x int) int {
	if uf.p[x] != x {
		uf.p[x] = uf.find(uf.p[x])
	}
	return uf.p[x]
}

func (uf *unionFind) union(a, b int) {
	pa, pb := uf.find(a), uf.find(b)
	if pa != pb {
		if uf.size[pa] > uf.size[pb] {
			uf.p[pb] = pa
			uf.size[pa] += uf.size[pb]
		} else {
			uf.p[pa] = pb
			uf.size[pb] += uf.size[pa]
		}
	}
}

func closedIsland(grid [][]int) (ans int) {
	m, n := len(grid), len(grid[0])
	uf := newUnionFind(m*n + 1)
	for i, row := range grid {
		for j, v := range row {
			if i == 0 || i == m-1 || j == 0 || j == n-1 {
				uf.union(i*n+j, m*n)
			}
			if v == 0 {
				if i+1 < m && grid[i+1][j] == 0 {
					uf.union(i*n+j, (i+1)*n+j)
				}
				if j+1 < n && grid[i][j+1] == 0 {
					uf.union(i*n+j, i*n+j+1)
				}
			}
		}
	}
	for i, row := range grid {
		for j, v := range row {
			if v == 0 && uf.find(i*n+j) == i*n+j {
				ans++
			}
		}
	}
	return
}
```

#### TypeScript

```ts
function closedIsland(grid: number[][]): number {
    const m = grid.length;
    const n = grid[0].length;
    const uf = new UnionFind(m * n + 1);
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            if (i === 0 || i === m - 1 || j === 0 || j === n - 1) {
                uf.union(i * n + j, m * n);
            }
            if (grid[i][j] === 0) {
                if (i + 1 < m && grid[i + 1][j] === 0) {
                    uf.union(i * n + j, (i + 1) * n + j);
                }
                if (j + 1 < n && grid[i][j + 1] === 0) {
                    uf.union(i * n + j, i * n + j + 1);
                }
            }
        }
    }
    let ans = 0;
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j] === 0 && uf.find(i * n + j) === i * n + j) {
                ++ans;
            }
        }
    }
    return ans;
}

class UnionFind {
    private p: number[];
    private size: number[];

    constructor(n: number) {
        this.p = Array(n)
            .fill(0)
            .map((_, i) => i);
        this.size = Array(n).fill(1);
    }

    find(x: number): number {
        if (this.p[x] !== x) {
            this.p[x] = this.find(this.p[x]);
        }
        return this.p[x];
    }

    union(a: number, b: number): void {
        const [pa, pb] = [this.find(a), this.find(b)];
        if (pa === pb) {
            return;
        }
        if (this.size[pa] > this.size[pb]) {
            this.p[pb] = pa;
            this.size[pa] += this.size[pb];
        } else {
            this.p[pa] = pb;
            this.size[pb] += this.size[pa];
        }
    }
}
```

#### C#

```cs
class UnionFind {
    private int[] p;
    private int[] size;

    public UnionFind(int n) {
        p = new int[n];
        size = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
            size[i] = 1;
        }
    }

    public int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    public void union(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa != pb) {
            if (size[pa] > size[pb]) {
                p[pb] = pa;
                size[pa] += size[pb];
            } else {
                p[pa] = pb;
                size[pb] += size[pa];
            }
        }
    }
}

public class Solution {
    public int ClosedIsland(int[][] grid) {
        int m = grid.Length, n = grid[0].Length;
        UnionFind uf = new UnionFind(m * n + 1);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    uf.union(i * n + j, m * n);
                }
                if (grid[i][j] == 0) {
                    if (i + 1 < m && grid[i + 1][j] == 0) {
                        uf.union(i * n + j, (i + 1) * n + j);
                    }
                    if (j + 1 < n && grid[i][j + 1] == 0) {
                        uf.union(i * n + j, i * n + j + 1);
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0 && uf.find(i * n + j) == i * n + j) {
                    ++ans;
                }
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

# [1255. 得分最高的单词集合](https://leetcode.cn/problems/maximum-score-words-formed-by-letters){#1255}

{{< tabs "1255" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxScoreWords(
        self, words: List[str], letters: List[str], score: List[int]
    ) -> int:
        cnt = Counter(letters)
        n = len(words)
        ans = 0
        for i in range(1 << n):
            cur = Counter(''.join([words[j] for j in range(n) if i >> j & 1]))
            if all(v <= cnt[c] for c, v in cur.items()):
                t = sum(v * score[ord(c) - ord('a')] for c, v in cur.items())
                ans = max(ans, t)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxScoreWords(String[] words, char[] letters, int[] score) {
        int[] cnt = new int[26];
        for (int i = 0; i < letters.length; ++i) {
            cnt[letters[i] - 'a']++;
        }
        int n = words.length;
        int ans = 0;
        for (int i = 0; i < 1 << n; ++i) {
            int[] cur = new int[26];
            for (int j = 0; j < n; ++j) {
                if (((i >> j) & 1) == 1) {
                    for (int k = 0; k < words[j].length(); ++k) {
                        cur[words[j].charAt(k) - 'a']++;
                    }
                }
            }
            boolean ok = true;
            int t = 0;
            for (int j = 0; j < 26; ++j) {
                if (cur[j] > cnt[j]) {
                    ok = false;
                    break;
                }
                t += cur[j] * score[j];
            }
            if (ok && ans < t) {
                ans = t;
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
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int cnt[26]{};
        for (char& c : letters) {
            cnt[c - 'a']++;
        }
        int n = words.size();
        int ans = 0;
        for (int i = 0; i < 1 << n; ++i) {
            int cur[26]{};
            for (int j = 0; j < n; ++j) {
                if (i >> j & 1) {
                    for (char& c : words[j]) {
                        cur[c - 'a']++;
                    }
                }
            }
            bool ok = true;
            int t = 0;
            for (int j = 0; j < 26; ++j) {
                if (cur[j] > cnt[j]) {
                    ok = false;
                    break;
                }
                t += cur[j] * score[j];
            }
            if (ok && ans < t) {
                ans = t;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxScoreWords(words []string, letters []byte, score []int) (ans int) {
	cnt := [26]int{}
	for _, c := range letters {
		cnt[c-'a']++
	}
	n := len(words)
	for i := 0; i < 1<<n; i++ {
		cur := [26]int{}
		for j := 0; j < n; j++ {
			if i>>j&1 == 1 {
				for _, c := range words[j] {
					cur[c-'a']++
				}
			}
		}
		ok := true
		t := 0
		for i, v := range cur {
			if v > cnt[i] {
				ok = false
				break
			}
			t += v * score[i]
		}
		if ok && ans < t {
			ans = t
		}
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

<p>你将会得到一份单词表&nbsp;<code>words</code>，一个字母表&nbsp;<code>letters</code>&nbsp;（可能会有重复字母），以及每个字母对应的得分情况表&nbsp;<code>score</code>。</p>

<p>请你帮忙计算玩家在单词拼写游戏中所能获得的「最高得分」：能够由&nbsp;<code>letters</code>&nbsp;里的字母拼写出的&nbsp;<strong>任意</strong>&nbsp;属于 <code>words</code>&nbsp;单词子集中，分数最高的单词集合的得分。</p>

<p>单词拼写游戏的规则概述如下：</p>

<ul>
	<li>玩家需要用字母表&nbsp;<code>letters</code> 里的字母来拼写单词表&nbsp;<code>words</code>&nbsp;中的单词。</li>
	<li>可以只使用字母表&nbsp;<code>letters</code> 中的部分字母，但是每个字母最多被使用一次。</li>
	<li>单词表 <code>words</code>&nbsp;中每个单词只能计分（使用）一次。</li>
	<li>根据字母得分情况表<code>score</code>，字母 <code>&#39;a&#39;</code>,&nbsp;<code>&#39;b&#39;</code>,&nbsp;<code>&#39;c&#39;</code>, ... ,&nbsp;<code>&#39;z&#39;</code> 对应的得分分别为 <code>score[0]</code>, <code>score[1]</code>,&nbsp;...,&nbsp;<code>score[25]</code>。</li>
	<li>本场游戏的「得分」是指：玩家所拼写出的单词集合里包含的所有字母的得分之和。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>words = [&quot;dog&quot;,&quot;cat&quot;,&quot;dad&quot;,&quot;good&quot;], letters = [&quot;a&quot;,&quot;a&quot;,&quot;c&quot;,&quot;d&quot;,&quot;d&quot;,&quot;d&quot;,&quot;g&quot;,&quot;o&quot;,&quot;o&quot;], score = [1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0]
<strong>输出：</strong>23
<strong>解释：</strong>
字母得分为  a=1, c=9, d=5, g=3, o=2
使用给定的字母表 letters，我们可以拼写单词 &quot;dad&quot; (5+1+5)和 &quot;good&quot; (3+2+2+5)，得分为 23 。
而单词 &quot;dad&quot; 和 &quot;dog&quot; 只能得到 21 分。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>words = [&quot;xxxz&quot;,&quot;ax&quot;,&quot;bx&quot;,&quot;cx&quot;], letters = [&quot;z&quot;,&quot;a&quot;,&quot;b&quot;,&quot;c&quot;,&quot;x&quot;,&quot;x&quot;,&quot;x&quot;], score = [4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,10]
<strong>输出：</strong>27
<strong>解释：</strong>
字母得分为  a=4, b=4, c=4, x=5, z=10
使用给定的字母表 letters，我们可以组成单词 &quot;ax&quot; (4+5)， &quot;bx&quot; (4+5) 和 &quot;cx&quot; (4+5) ，总得分为 27 。
单词 &quot;xxxz&quot; 的得分仅为 25 。</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>words = [&quot;leetcode&quot;], letters = [&quot;l&quot;,&quot;e&quot;,&quot;t&quot;,&quot;c&quot;,&quot;o&quot;,&quot;d&quot;], score = [0,0,1,1,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0]
<strong>输出：</strong>0
<strong>解释：</strong>
字母 &quot;e&quot; 在字母表 letters 中只出现了一次，所以无法组成单词表 words 中的单词。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 14</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 15</code></li>
	<li><code>1 &lt;= letters.length &lt;= 100</code></li>
	<li><code>letters[i].length == 1</code></li>
	<li><code>score.length ==&nbsp;26</code></li>
	<li><code>0 &lt;= score[i] &lt;= 10</code></li>
	<li><code>words[i]</code>&nbsp;和&nbsp;<code>letters[i]</code>&nbsp;只包含小写的英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二进制枚举

我们注意到题目的数据范围不大，因此对于给定的单词表，我们可以使用二进制枚举的方法，枚举出所有的单词组合，然后判断每个单词组合是否满足题目要求，如果满足则计算其得分，最后取得分最大的单词组合。

我们首先用哈希表或数组 $cnt$ 记录字母表 $letters$ 中每个字母出现的次数。

接下来，我们使用二进制枚举的方法，枚举出所有的单词组合。二进制的每一位表示单词表中的每一个单词是否被选中，如果第 $i$ 位为 $1$，则表示第 $i$ 个单词被选中，否则表示第 $i$ 个单词没有被选中。

然后我们统计当前单词组合中每个字母出现的次数，记录在哈希表或数组 $cur$ 中。如果 $cur$ 中的每个字母的出现次数都不大于 $cnt$ 中的对应字母的出现次数，则说明当前单词组合满足题目要求，我们计算当前单词组合的得分，取得分最大的单词组合。

时间复杂度 $(2^n \times n \times M)$，空间复杂度 $O(C)$。其中 $n$ 和 $M$ 分别为单词集合中单词的个数和单词的最大长度；而 $C$ 为字母表中字母的个数，本题中 $C=26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxScoreWords(
        self, words: List[str], letters: List[str], score: List[int]
    ) -> int:
        cnt = Counter(letters)
        n = len(words)
        ans = 0
        for i in range(1 << n):
            cur = Counter(''.join([words[j] for j in range(n) if i >> j & 1]))
            if all(v <= cnt[c] for c, v in cur.items()):
                t = sum(v * score[ord(c) - ord('a')] for c, v in cur.items())
                ans = max(ans, t)
        return ans
```

#### Java

```java
class Solution {
    public int maxScoreWords(String[] words, char[] letters, int[] score) {
        int[] cnt = new int[26];
        for (int i = 0; i < letters.length; ++i) {
            cnt[letters[i] - 'a']++;
        }
        int n = words.length;
        int ans = 0;
        for (int i = 0; i < 1 << n; ++i) {
            int[] cur = new int[26];
            for (int j = 0; j < n; ++j) {
                if (((i >> j) & 1) == 1) {
                    for (int k = 0; k < words[j].length(); ++k) {
                        cur[words[j].charAt(k) - 'a']++;
                    }
                }
            }
            boolean ok = true;
            int t = 0;
            for (int j = 0; j < 26; ++j) {
                if (cur[j] > cnt[j]) {
                    ok = false;
                    break;
                }
                t += cur[j] * score[j];
            }
            if (ok && ans < t) {
                ans = t;
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
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int cnt[26]{};
        for (char& c : letters) {
            cnt[c - 'a']++;
        }
        int n = words.size();
        int ans = 0;
        for (int i = 0; i < 1 << n; ++i) {
            int cur[26]{};
            for (int j = 0; j < n; ++j) {
                if (i >> j & 1) {
                    for (char& c : words[j]) {
                        cur[c - 'a']++;
                    }
                }
            }
            bool ok = true;
            int t = 0;
            for (int j = 0; j < 26; ++j) {
                if (cur[j] > cnt[j]) {
                    ok = false;
                    break;
                }
                t += cur[j] * score[j];
            }
            if (ok && ans < t) {
                ans = t;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func maxScoreWords(words []string, letters []byte, score []int) (ans int) {
	cnt := [26]int{}
	for _, c := range letters {
		cnt[c-'a']++
	}
	n := len(words)
	for i := 0; i < 1<<n; i++ {
		cur := [26]int{}
		for j := 0; j < n; j++ {
			if i>>j&1 == 1 {
				for _, c := range words[j] {
					cur[c-'a']++
				}
			}
		}
		ok := true
		t := 0
		for i, v := range cur {
			if v > cnt[i] {
				ok = false
				break
			}
			t += v * score[i]
		}
		if ok && ans < t {
			ans = t
		}
	}
	return
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1256. 加密数字 🔒](https://leetcode.cn/problems/encode-number){#1256}

{{< tabs "1256" >}}

{{% tab "python" %}}
```python
class Solution:
    def encode(self, num: int) -> str:
        return bin(num + 1)[3:]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String encode(int num) {
        return Integer.toBinaryString(num + 1).substring(1);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string encode(int num) {
        bitset<32> bs(++num);
        string ans = bs.to_string();
        int i = 0;
        while (ans[i] == '0') {
            ++i;
        }
        return ans.substr(i + 1);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func encode(num int) string {
	num++
	s := strconv.FormatInt(int64(num), 2)
	return s[1:]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function encode(num: number): string {
    ++num;
    let s = num.toString(2);
    return s.slice(1);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个非负整数 <code>num</code> ，返回它的「加密字符串」。</p>

<p>加密的过程是把一个整数用某个未知函数进行转化，你需要从下表推测出该转化函数：</p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1200-1299/1256.Encode%20Number/images/encode_number.png" style="height: 360px; width: 164px;"></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>num = 23
<strong>输出：</strong>&quot;1000&quot;
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>num = 107
<strong>输出：</strong>&quot;101100&quot;
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= num &lt;= 10^9</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：位运算

我们将 $num$ 加一，然后将其转换为二进制字符串，去掉最高位的 $1$ 即可。

时间复杂度 $O(\log n)$，空间复杂度 $O(\log n)$。其中 $n$ 为 $num$ 的大小。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def encode(self, num: int) -> str:
        return bin(num + 1)[3:]
```

#### Java

```java
class Solution {
    public String encode(int num) {
        return Integer.toBinaryString(num + 1).substring(1);
    }
}
```

#### C++

```cpp
class Solution {
public:
    string encode(int num) {
        bitset<32> bs(++num);
        string ans = bs.to_string();
        int i = 0;
        while (ans[i] == '0') {
            ++i;
        }
        return ans.substr(i + 1);
    }
};
```

#### Go

```go
func encode(num int) string {
	num++
	s := strconv.FormatInt(int64(num), 2)
	return s[1:]
}
```

#### TypeScript

```ts
function encode(num: number): string {
    ++num;
    let s = num.toString(2);
    return s.slice(1);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1257. 最小公共区域 🔒](https://leetcode.cn/problems/smallest-common-region){#1257}

{{< tabs "1257" >}}

{{% tab "python" %}}
```python
class Solution:
    def findSmallestRegion(
        self, regions: List[List[str]], region1: str, region2: str
    ) -> str:
        g = {}
        for r in regions:
            x = r[0]
            for y in r[1:]:
                g[y] = x
        s = set()
        x = region1
        while x in g:
            s.add(x)
            x = g[x]
        x = region2
        while x in g and x not in s:
            x = g[x]
        return x
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String findSmallestRegion(List<List<String>> regions, String region1, String region2) {
        Map<String, String> g = new HashMap<>();
        for (var r : regions) {
            String x = r.get(0);
            for (String y : r.subList(1, r.size())) {
                g.put(y, x);
            }
        }
        Set<String> s = new HashSet<>();
        for (String x = region1; x != null; x = g.get(x)) {
            s.add(x);
        }
        String x = region2;
        while (g.get(x) != null && !s.contains(x)) {
            x = g.get(x);
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
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        unordered_map<string, string> g;
        for (const auto& r : regions) {
            string x = r[0];
            for (size_t i = 1; i < r.size(); ++i) {
                g[r[i]] = x;
            }
        }
        unordered_set<string> s;
        for (string x = region1; !x.empty(); x = g[x]) {
            s.insert(x);
        }
        string x = region2;
        while (!g[x].empty() && s.find(x) == s.end()) {
            x = g[x];
        }
        return x;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findSmallestRegion(regions [][]string, region1 string, region2 string) string {
	g := make(map[string]string)

	for _, r := range regions {
		x := r[0]
		for _, y := range r[1:] {
			g[y] = x
		}
	}

	s := make(map[string]bool)
	for x := region1; x != ""; x = g[x] {
		s[x] = true
	}

	x := region2
	for g[x] != "" && !s[x] {
		x = g[x]
	}

	return x
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findSmallestRegion(regions: string[][], region1: string, region2: string): string {
    const g: Record<string, string> = {};

    for (const r of regions) {
        const x = r[0];
        for (const y of r.slice(1)) {
            g[y] = x;
        }
    }

    const s: Set<string> = new Set();
    for (let x: string = region1; x !== undefined; x = g[x]) {
        s.add(x);
    }

    let x: string = region2;
    while (g[x] !== undefined && !s.has(x)) {
        x = g[x];
    }

    return x;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::{HashMap, HashSet};

impl Solution {
    pub fn find_smallest_region(regions: Vec<Vec<String>>, region1: String, region2: String) -> String {
        let mut g: HashMap<String, String> = HashMap::new();

        for r in &regions {
            let x = &r[0];
            for y in &r[1..] {
                g.insert(y.clone(), x.clone());
            }
        }

        let mut s: HashSet<String> = HashSet::new();
        let mut x = Some(region1);
        while let Some(region) = x {
            s.insert(region.clone());
            x = g.get(&region).cloned();
        }

        let mut x = Some(region2);
        while let Some(region) = x {
            if s.contains(&region) {
                return region;
            }
            x = g.get(&region).cloned();
        }

        String::new()
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一些区域列表&nbsp;<code>regions</code> ，每个列表的第一个区域都&nbsp;<strong>直接</strong> 包含这个列表内所有其他区域。</p>

<p>如果一个区域 <code>x</code> 直接包含区域 <code>y</code>，并且区域 <code>y</code> 直接包含区域 <code>z</code>，那么说区域 <code>x</code> <strong>间接</strong> 包含区域 <code>z</code>。请注意，区域 <code>x</code> 也 <strong>间接</strong> 包含所有在 <code>y</code> 中 <strong>间接</strong> 包含的区域。</p>

<p>很自然地，如果区域&nbsp;<code>x</code> 包含区域&nbsp;<code>y</code> ，那么区域&nbsp;<code>x</code> &nbsp;比区域&nbsp;<code>y</code> 大。同时根据定义，区域&nbsp;<code>x</code> 包含自身。</p>

<p>给定两个区域&nbsp;<code>region1</code>&nbsp;和&nbsp;<code>region2</code> ，找到同时包含这两个区域的&nbsp;<strong>最小&nbsp;</strong>区域。</p>

<p>数据同样保证最小区域一定存在。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：
</strong>regions = [["Earth","North America","South America"],
["North America","United States","Canada"],
["United States","New York","Boston"],
["Canada","Ontario","Quebec"],
["South America","Brazil"]],
region1 = "Quebec",
region2 = "New York"
<strong>输出：</strong>"North America"
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>regions = [["Earth", "North America", "South America"],["North America", "United States", "Canada"],["United States", "New York", "Boston"],["Canada", "Ontario", "Quebec"],["South America", "Brazil"]], region1 = "Canada", region2 = "South America"
<b>输出：</b>"Earth"
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= regions.length &lt;= 10<sup>4</sup></code></li>
	<li><code>2 &lt;= regions[i].length &lt;= 20</code></li>
	<li><code>1 &lt;= regions[i][j].length, region1.length, region2.length &lt;= 20</code></li>
	<li><code>region1 != region2</code></li>
	<li><code>regions[i][j]</code>，<code>region1</code>&nbsp;和&nbsp;<code>region2</code> 由英语字母组成。</li>
	<li>输入保证存在一个区域直接或间接包含所有其他区域。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

我们可以用一个哈希表 $\textit{g}$ 来存储每个区域的父区域，然后从 $\textit{region1}$ 开始，不断向上找到所有的父区域，直到根区域，将这些区域放入集合 $\textit{s}$ 中。然后从 $\textit{region2}$ 开始，不断向上找到第一个在 $\textit{s}$ 中的区域，即为最小公共区域。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为区域列表 $\textit{regions}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findSmallestRegion(
        self, regions: List[List[str]], region1: str, region2: str
    ) -> str:
        g = {}
        for r in regions:
            x = r[0]
            for y in r[1:]:
                g[y] = x
        s = set()
        x = region1
        while x in g:
            s.add(x)
            x = g[x]
        x = region2
        while x in g and x not in s:
            x = g[x]
        return x
```

#### Java

```java
class Solution {
    public String findSmallestRegion(List<List<String>> regions, String region1, String region2) {
        Map<String, String> g = new HashMap<>();
        for (var r : regions) {
            String x = r.get(0);
            for (String y : r.subList(1, r.size())) {
                g.put(y, x);
            }
        }
        Set<String> s = new HashSet<>();
        for (String x = region1; x != null; x = g.get(x)) {
            s.add(x);
        }
        String x = region2;
        while (g.get(x) != null && !s.contains(x)) {
            x = g.get(x);
        }
        return x;
    }
}
```

#### C++

```cpp
class Solution {
public:
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        unordered_map<string, string> g;
        for (const auto& r : regions) {
            string x = r[0];
            for (size_t i = 1; i < r.size(); ++i) {
                g[r[i]] = x;
            }
        }
        unordered_set<string> s;
        for (string x = region1; !x.empty(); x = g[x]) {
            s.insert(x);
        }
        string x = region2;
        while (!g[x].empty() && s.find(x) == s.end()) {
            x = g[x];
        }
        return x;
    }
};
```

#### Go

```go
func findSmallestRegion(regions [][]string, region1 string, region2 string) string {
	g := make(map[string]string)

	for _, r := range regions {
		x := r[0]
		for _, y := range r[1:] {
			g[y] = x
		}
	}

	s := make(map[string]bool)
	for x := region1; x != ""; x = g[x] {
		s[x] = true
	}

	x := region2
	for g[x] != "" && !s[x] {
		x = g[x]
	}

	return x
}
```

#### TypeScript

```ts
function findSmallestRegion(regions: string[][], region1: string, region2: string): string {
    const g: Record<string, string> = {};

    for (const r of regions) {
        const x = r[0];
        for (const y of r.slice(1)) {
            g[y] = x;
        }
    }

    const s: Set<string> = new Set();
    for (let x: string = region1; x !== undefined; x = g[x]) {
        s.add(x);
    }

    let x: string = region2;
    while (g[x] !== undefined && !s.has(x)) {
        x = g[x];
    }

    return x;
}
```

#### Rust

```rust
use std::collections::{HashMap, HashSet};

impl Solution {
    pub fn find_smallest_region(regions: Vec<Vec<String>>, region1: String, region2: String) -> String {
        let mut g: HashMap<String, String> = HashMap::new();

        for r in &regions {
            let x = &r[0];
            for y in &r[1..] {
                g.insert(y.clone(), x.clone());
            }
        }

        let mut s: HashSet<String> = HashSet::new();
        let mut x = Some(region1);
        while let Some(region) = x {
            s.insert(region.clone());
            x = g.get(&region).cloned();
        }

        let mut x = Some(region2);
        while let Some(region) = x {
            if s.contains(&region) {
                return region;
            }
            x = g.get(&region).cloned();
        }

        String::new()
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1258. 近义词句子 🔒](https://leetcode.cn/problems/synonymous-sentences){#1258}

{{< tabs "1258" >}}

{{% tab "python" %}}
```python
class UnionFind:
    def __init__(self, n):
        self.p = list(range(n))
        self.size = [1] * n

    def find(self, x):
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]

    def union(self, a, b):
        pa, pb = self.find(a), self.find(b)
        if pa != pb:
            if self.size[pa] > self.size[pb]:
                self.p[pb] = pa
                self.size[pa] += self.size[pb]
            else:
                self.p[pa] = pb
                self.size[pb] += self.size[pa]


class Solution:
    def generateSentences(self, synonyms: List[List[str]], text: str) -> List[str]:
        def dfs(i):
            if i >= len(sentence):
                ans.append(' '.join(t))
                return
            if sentence[i] not in d:
                t.append(sentence[i])
                dfs(i + 1)
                t.pop()
            else:
                root = uf.find(d[sentence[i]])
                for j in g[root]:
                    t.append(words[j])
                    dfs(i + 1)
                    t.pop()

        words = list(set(chain.from_iterable(synonyms)))
        d = {w: i for i, w in enumerate(words)}
        uf = UnionFind(len(d))
        for a, b in synonyms:
            uf.union(d[a], d[b])
        g = defaultdict(list)
        for i in range(len(words)):
            g[uf.find(i)].append(i)
        for k in g.keys():
            g[k].sort(key=lambda i: words[i])
        sentence = text.split()
        ans = []
        t = []
        dfs(0)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class UnionFind {
    private int[] p;
    private int[] size;

    public UnionFind(int n) {
        p = new int[n];
        size = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
            size[i] = 1;
        }
    }

    public int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    public void union(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa != pb) {
            if (size[pa] > size[pb]) {
                p[pb] = pa;
                size[pa] += size[pb];
            } else {
                p[pa] = pb;
                size[pb] += size[pa];
            }
        }
    }
}

class Solution {
    private List<String> ans = new ArrayList<>();
    private List<String> t = new ArrayList<>();
    private List<String> words;
    private Map<String, Integer> d;
    private UnionFind uf;
    private List<Integer>[] g;
    private String[] sentence;

    public List<String> generateSentences(List<List<String>> synonyms, String text) {
        Set<String> ss = new HashSet<>();
        for (List<String> pairs : synonyms) {
            ss.addAll(pairs);
        }
        words = new ArrayList<>(ss);
        int n = words.size();
        d = new HashMap<>(n);
        for (int i = 0; i < words.size(); ++i) {
            d.put(words.get(i), i);
        }
        uf = new UnionFind(n);
        for (List<String> pairs : synonyms) {
            uf.union(d.get(pairs.get(0)), d.get(pairs.get(1)));
        }
        g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (int i = 0; i < n; ++i) {
            g[uf.find(i)].add(i);
        }
        for (List<Integer> e : g) {
            e.sort((i, j) -> words.get(i).compareTo(words.get(j)));
        }
        sentence = text.split(" ");
        dfs(0);
        return ans;
    }

    private void dfs(int i) {
        if (i >= sentence.length) {
            ans.add(String.join(" ", t));
            return;
        }
        if (!d.containsKey(sentence[i])) {
            t.add(sentence[i]);
            dfs(i + 1);
            t.remove(t.size() - 1);
        } else {
            for (int j : g[uf.find(d.get(sentence[i]))]) {
                t.add(words.get(j));
                dfs(i + 1);
                t.remove(t.size() - 1);
            }
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class UnionFind {
public:
    UnionFind(int n) {
        p = vector<int>(n);
        size = vector<int>(n, 1);
        iota(p.begin(), p.end(), 0);
    }

    void unite(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa != pb) {
            if (size[pa] > size[pb]) {
                p[pb] = pa;
                size[pa] += size[pb];
            } else {
                p[pa] = pb;
                size[pb] += size[pa];
            }
        }
    }

    int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

private:
    vector<int> p, size;
};

class Solution {
public:
    vector<string> generateSentences(vector<vector<string>>& synonyms, string text) {
        unordered_set<string> ss;
        for (auto& pairs : synonyms) {
            ss.insert(pairs[0]);
            ss.insert(pairs[1]);
        }
        vector<string> words{ss.begin(), ss.end()};
        unordered_map<string, int> d;
        int n = words.size();
        for (int i = 0; i < n; ++i) {
            d[words[i]] = i;
        }
        UnionFind uf(n);
        for (auto& pairs : synonyms) {
            uf.unite(d[pairs[0]], d[pairs[1]]);
        }
        vector<vector<int>> g(n);
        for (int i = 0; i < n; ++i) {
            g[uf.find(i)].push_back(i);
        }
        for (int i = 0; i < n; ++i) {
            sort(g[i].begin(), g[i].end(), [&](int a, int b) {
                return words[a] < words[b];
            });
        }
        vector<string> sentence;
        string s;
        istringstream iss(text);
        while (iss >> s) {
            sentence.emplace_back(s);
        }
        vector<string> ans;
        vector<string> t;
        function<void(int)> dfs = [&](int i) {
            if (i >= sentence.size()) {
                string s;
                for (int j = 0; j < t.size(); ++j) {
                    if (j) {
                        s += " ";
                    }
                    s += t[j];
                }
                ans.emplace_back(s);
                return;
            }
            if (!d.count(sentence[i])) {
                t.emplace_back(sentence[i]);
                dfs(i + 1);
                t.pop_back();
            } else {
                for (int j : g[uf.find(d[sentence[i]])]) {
                    t.emplace_back(words[j]);
                    dfs(i + 1);
                    t.pop_back();
                }
            }
        };
        dfs(0);
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
type unionFind struct {
	p, size []int
}

func newUnionFind(n int) *unionFind {
	p := make([]int, n)
	size := make([]int, n)
	for i := range p {
		p[i] = i
		size[i] = 1
	}
	return &unionFind{p, size}
}

func (uf *unionFind) find(x int) int {
	if uf.p[x] != x {
		uf.p[x] = uf.find(uf.p[x])
	}
	return uf.p[x]
}

func (uf *unionFind) union(a, b int) {
	pa, pb := uf.find(a), uf.find(b)
	if pa != pb {
		if uf.size[pa] > uf.size[pb] {
			uf.p[pb] = pa
			uf.size[pa] += uf.size[pb]
		} else {
			uf.p[pa] = pb
			uf.size[pb] += uf.size[pa]
		}
	}
}

func generateSentences(synonyms [][]string, text string) (ans []string) {
	ss := map[string]bool{}
	for _, pairs := range synonyms {
		ss[pairs[0]] = true
		ss[pairs[1]] = true
	}
	words := []string{}
	for w := range ss {
		words = append(words, w)
	}
	d := map[string]int{}
	for i, w := range words {
		d[w] = i
	}
	uf := newUnionFind(len(words))
	for _, pairs := range synonyms {
		uf.union(d[pairs[0]], d[pairs[1]])
	}
	g := make([][]int, len(words))
	for i := range g {
		g[uf.find(i)] = append(g[uf.find(i)], i)
	}
	for i := range g {
		sort.Slice(g[i], func(a, b int) bool { return words[g[i][a]] < words[g[i][b]] })
	}
	t := []string{}
	sentences := strings.Split(text, " ")
	var dfs func(int)
	dfs = func(i int) {
		if i >= len(sentences) {
			ans = append(ans, strings.Join(t, " "))
			return
		}
		if _, ok := ss[sentences[i]]; !ok {
			t = append(t, sentences[i])
			dfs(i + 1)
			t = t[:len(t)-1]
			return
		} else {
			for _, j := range g[uf.find(d[sentences[i]])] {
				t = append(t, words[j])
				dfs(i + 1)
				t = t[:len(t)-1]
			}
		}
	}
	dfs(0)
	return
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个近义词表&nbsp;<code>synonyms</code> 和一个句子&nbsp;<code>text</code>&nbsp;，&nbsp;<code>synonyms</code> 表中是一些近义词对 ，你可以将句子&nbsp;<code>text</code> 中每个单词用它的近义词来替换。</p>

<p>请你找出所有用近义词替换后的句子，按&nbsp;<strong>字典序排序</strong>&nbsp;后返回。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：
</strong>synonyms = [[&quot;happy&quot;,&quot;joy&quot;],[&quot;sad&quot;,&quot;sorrow&quot;],[&quot;joy&quot;,&quot;cheerful&quot;]],
text = &quot;I am happy today but was sad yesterday&quot;
<strong>输出：
</strong>[&quot;I am cheerful today but was sad yesterday&quot;,
&quot;I am cheerful today but was sorrow yesterday&quot;,
&quot;I am happy today but was sad yesterday&quot;,
&quot;I am happy today but was sorrow yesterday&quot;,
&quot;I am joy today but was sad yesterday&quot;,
&quot;I am joy today but was sorrow yesterday&quot;]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;=&nbsp;synonyms.length &lt;= 10</code></li>
	<li><code>synonyms[i].length == 2</code></li>
	<li><code>synonyms[0] != synonyms[1]</code></li>
	<li>所有单词仅包含英文字母，且长度最多为&nbsp;<code>10</code> 。</li>
	<li><code>text</code>&nbsp;最多包含&nbsp;<code>10</code> 个单词，且单词间用单个空格分隔开。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：并查集 + DFS

我们可以发现，题目中的近义词是可以传递的，即如果 `a` 和 `b` 是近义词，`b` 和 `c` 是近义词，那么 `a` 和 `c` 也是近义词。因此，我们可以用并查集找出近义词的连通分量，每个连通分量中的单词都是近义词，并且按字典序从小到大排列。

接下来，我们将字符串 `text` 按空格分割成单词数组 `sentence`，对于每个单词 `sentence[i]`，如果它是近义词，那么我们就将它替换成连通分量中的所有单词，否则不替换。这样，我们就可以得到所有的句子。这可以通过 DFS 搜索实现。

我们设计一个函数 $dfs(i)$，表示从 `sentence` 的第 $i$ 个单词开始，将其替换成连通分量中的所有单词，然后递归地处理后面的单词。

如果 $i$ 大于等于 `sentence` 的长度，那么说明我们已经处理完了所有的单词，此时将当前的句子加入答案数组中。否则，如果 `sentence[i]` 不是近义词，那么我们不替换它，直接将它加入当前的句子中，然后递归地处理后面的单词。否则，我们将 `sentence[i]` 替换成连通分量中的所有单词，同样递归地处理后面的单词。

最后，返回答案数组即可。

时间复杂度 $O(n^2)$，空间复杂度 $O(n)$。其中 $n$ 是单词的数量。

<!-- tabs:start -->

#### Python3

```python
class UnionFind:
    def __init__(self, n):
        self.p = list(range(n))
        self.size = [1] * n

    def find(self, x):
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]

    def union(self, a, b):
        pa, pb = self.find(a), self.find(b)
        if pa != pb:
            if self.size[pa] > self.size[pb]:
                self.p[pb] = pa
                self.size[pa] += self.size[pb]
            else:
                self.p[pa] = pb
                self.size[pb] += self.size[pa]


class Solution:
    def generateSentences(self, synonyms: List[List[str]], text: str) -> List[str]:
        def dfs(i):
            if i >= len(sentence):
                ans.append(' '.join(t))
                return
            if sentence[i] not in d:
                t.append(sentence[i])
                dfs(i + 1)
                t.pop()
            else:
                root = uf.find(d[sentence[i]])
                for j in g[root]:
                    t.append(words[j])
                    dfs(i + 1)
                    t.pop()

        words = list(set(chain.from_iterable(synonyms)))
        d = {w: i for i, w in enumerate(words)}
        uf = UnionFind(len(d))
        for a, b in synonyms:
            uf.union(d[a], d[b])
        g = defaultdict(list)
        for i in range(len(words)):
            g[uf.find(i)].append(i)
        for k in g.keys():
            g[k].sort(key=lambda i: words[i])
        sentence = text.split()
        ans = []
        t = []
        dfs(0)
        return ans
```

#### Java

```java
class UnionFind {
    private int[] p;
    private int[] size;

    public UnionFind(int n) {
        p = new int[n];
        size = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
            size[i] = 1;
        }
    }

    public int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    public void union(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa != pb) {
            if (size[pa] > size[pb]) {
                p[pb] = pa;
                size[pa] += size[pb];
            } else {
                p[pa] = pb;
                size[pb] += size[pa];
            }
        }
    }
}

class Solution {
    private List<String> ans = new ArrayList<>();
    private List<String> t = new ArrayList<>();
    private List<String> words;
    private Map<String, Integer> d;
    private UnionFind uf;
    private List<Integer>[] g;
    private String[] sentence;

    public List<String> generateSentences(List<List<String>> synonyms, String text) {
        Set<String> ss = new HashSet<>();
        for (List<String> pairs : synonyms) {
            ss.addAll(pairs);
        }
        words = new ArrayList<>(ss);
        int n = words.size();
        d = new HashMap<>(n);
        for (int i = 0; i < words.size(); ++i) {
            d.put(words.get(i), i);
        }
        uf = new UnionFind(n);
        for (List<String> pairs : synonyms) {
            uf.union(d.get(pairs.get(0)), d.get(pairs.get(1)));
        }
        g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (int i = 0; i < n; ++i) {
            g[uf.find(i)].add(i);
        }
        for (List<Integer> e : g) {
            e.sort((i, j) -> words.get(i).compareTo(words.get(j)));
        }
        sentence = text.split(" ");
        dfs(0);
        return ans;
    }

    private void dfs(int i) {
        if (i >= sentence.length) {
            ans.add(String.join(" ", t));
            return;
        }
        if (!d.containsKey(sentence[i])) {
            t.add(sentence[i]);
            dfs(i + 1);
            t.remove(t.size() - 1);
        } else {
            for (int j : g[uf.find(d.get(sentence[i]))]) {
                t.add(words.get(j));
                dfs(i + 1);
                t.remove(t.size() - 1);
            }
        }
    }
}
```

#### C++

```cpp
class UnionFind {
public:
    UnionFind(int n) {
        p = vector<int>(n);
        size = vector<int>(n, 1);
        iota(p.begin(), p.end(), 0);
    }

    void unite(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa != pb) {
            if (size[pa] > size[pb]) {
                p[pb] = pa;
                size[pa] += size[pb];
            } else {
                p[pa] = pb;
                size[pb] += size[pa];
            }
        }
    }

    int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

private:
    vector<int> p, size;
};

class Solution {
public:
    vector<string> generateSentences(vector<vector<string>>& synonyms, string text) {
        unordered_set<string> ss;
        for (auto& pairs : synonyms) {
            ss.insert(pairs[0]);
            ss.insert(pairs[1]);
        }
        vector<string> words{ss.begin(), ss.end()};
        unordered_map<string, int> d;
        int n = words.size();
        for (int i = 0; i < n; ++i) {
            d[words[i]] = i;
        }
        UnionFind uf(n);
        for (auto& pairs : synonyms) {
            uf.unite(d[pairs[0]], d[pairs[1]]);
        }
        vector<vector<int>> g(n);
        for (int i = 0; i < n; ++i) {
            g[uf.find(i)].push_back(i);
        }
        for (int i = 0; i < n; ++i) {
            sort(g[i].begin(), g[i].end(), [&](int a, int b) {
                return words[a] < words[b];
            });
        }
        vector<string> sentence;
        string s;
        istringstream iss(text);
        while (iss >> s) {
            sentence.emplace_back(s);
        }
        vector<string> ans;
        vector<string> t;
        function<void(int)> dfs = [&](int i) {
            if (i >= sentence.size()) {
                string s;
                for (int j = 0; j < t.size(); ++j) {
                    if (j) {
                        s += " ";
                    }
                    s += t[j];
                }
                ans.emplace_back(s);
                return;
            }
            if (!d.count(sentence[i])) {
                t.emplace_back(sentence[i]);
                dfs(i + 1);
                t.pop_back();
            } else {
                for (int j : g[uf.find(d[sentence[i]])]) {
                    t.emplace_back(words[j]);
                    dfs(i + 1);
                    t.pop_back();
                }
            }
        };
        dfs(0);
        return ans;
    }
};
```

#### Go

```go
type unionFind struct {
	p, size []int
}

func newUnionFind(n int) *unionFind {
	p := make([]int, n)
	size := make([]int, n)
	for i := range p {
		p[i] = i
		size[i] = 1
	}
	return &unionFind{p, size}
}

func (uf *unionFind) find(x int) int {
	if uf.p[x] != x {
		uf.p[x] = uf.find(uf.p[x])
	}
	return uf.p[x]
}

func (uf *unionFind) union(a, b int) {
	pa, pb := uf.find(a), uf.find(b)
	if pa != pb {
		if uf.size[pa] > uf.size[pb] {
			uf.p[pb] = pa
			uf.size[pa] += uf.size[pb]
		} else {
			uf.p[pa] = pb
			uf.size[pb] += uf.size[pa]
		}
	}
}

func generateSentences(synonyms [][]string, text string) (ans []string) {
	ss := map[string]bool{}
	for _, pairs := range synonyms {
		ss[pairs[0]] = true
		ss[pairs[1]] = true
	}
	words := []string{}
	for w := range ss {
		words = append(words, w)
	}
	d := map[string]int{}
	for i, w := range words {
		d[w] = i
	}
	uf := newUnionFind(len(words))
	for _, pairs := range synonyms {
		uf.union(d[pairs[0]], d[pairs[1]])
	}
	g := make([][]int, len(words))
	for i := range g {
		g[uf.find(i)] = append(g[uf.find(i)], i)
	}
	for i := range g {
		sort.Slice(g[i], func(a, b int) bool { return words[g[i][a]] < words[g[i][b]] })
	}
	t := []string{}
	sentences := strings.Split(text, " ")
	var dfs func(int)
	dfs = func(i int) {
		if i >= len(sentences) {
			ans = append(ans, strings.Join(t, " "))
			return
		}
		if _, ok := ss[sentences[i]]; !ok {
			t = append(t, sentences[i])
			dfs(i + 1)
			t = t[:len(t)-1]
			return
		} else {
			for _, j := range g[uf.find(d[sentences[i]])] {
				t = append(t, words[j])
				dfs(i + 1)
				t = t[:len(t)-1]
			}
		}
	}
	dfs(0)
	return
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1259. 不相交的握手 🔒](https://leetcode.cn/problems/handshakes-that-dont-cross){#1259}

{{< tabs "1259" >}}

{{% tab "python" %}}
```python
class Solution:
    def numberOfWays(self, numPeople: int) -> int:
        @cache
        def dfs(i: int) -> int:
            if i < 2:
                return 1
            ans = 0
            for l in range(0, i, 2):
                r = i - l - 2
                ans += dfs(l) * dfs(r)
                ans %= mod
            return ans

        mod = 10**9 + 7
        return dfs(numPeople)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[] f;
    private final int mod = (int) 1e9 + 7;

    public int numberOfWays(int numPeople) {
        f = new int[numPeople + 1];
        return dfs(numPeople);
    }

    private int dfs(int i) {
        if (i < 2) {
            return 1;
        }
        if (f[i] != 0) {
            return f[i];
        }
        for (int l = 0; l < i; l += 2) {
            int r = i - l - 2;
            f[i] = (int) ((f[i] + (1L * dfs(l) * dfs(r) % mod)) % mod);
        }
        return f[i];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int numberOfWays(int numPeople) {
        const int mod = 1e9 + 7;
        int f[numPeople + 1];
        memset(f, 0, sizeof(f));
        function<int(int)> dfs = [&](int i) {
            if (i < 2) {
                return 1;
            }
            if (f[i]) {
                return f[i];
            }
            for (int l = 0; l < i; l += 2) {
                int r = i - l - 2;
                f[i] = (f[i] + 1LL * dfs(l) * dfs(r) % mod) % mod;
            }
            return f[i];
        };
        return dfs(numPeople);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numberOfWays(numPeople int) int {
	const mod int = 1e9 + 7
	f := make([]int, numPeople+1)
	var dfs func(int) int
	dfs = func(i int) int {
		if i < 2 {
			return 1
		}
		if f[i] != 0 {
			return f[i]
		}
		for l := 0; l < i; l += 2 {
			r := i - l - 2
			f[i] = (f[i] + dfs(l)*dfs(r)) % mod
		}
		return f[i]
	}
	return dfs(numPeople)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numberOfWays(numPeople: number): number {
    const mod = 10 ** 9 + 7;
    const f: number[] = Array(numPeople + 1).fill(0);
    const dfs = (i: number): number => {
        if (i < 2) {
            return 1;
        }
        if (f[i] !== 0) {
            return f[i];
        }
        for (let l = 0; l < i; l += 2) {
            const r = i - l - 2;
            f[i] += Number((BigInt(dfs(l)) * BigInt(dfs(r))) % BigInt(mod));
            f[i] %= mod;
        }
        return f[i];
    };
    return dfs(numPeople);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p><strong>偶数</strong>&nbsp;个人站成一个圆，总人数为&nbsp;<code>num_people</code>&nbsp;。每个人与除自己外的一个人握手，所以总共会有&nbsp;<code>num_people / 2</code>&nbsp;次握手。</p>

<p>将握手的人之间连线，请你返回连线不会相交的握手方案数。</p>

<p>由于结果可能会很大，请你返回答案 <strong>模</strong>&nbsp;<strong><code>10^9+7</code></strong>&nbsp;后的结果。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>num_people = 2
<strong>输出：</strong>1
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1200-1299/1259.Handshakes%20That%20Don%27t%20Cross/images/5125_example_2.png" style="height: 311px; width: 651px;"></p>

<pre><strong>输入：</strong>num_people = 4
<strong>输出：</strong>2
<strong>解释：</strong>总共有两种方案，第一种方案是 [(1,2),(3,4)] ，第二种方案是 [(2,3),(4,1)] 。
</pre>

<p><strong>示例 3：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1200-1299/1259.Handshakes%20That%20Don%27t%20Cross/images/5125_example_3.png" style="height: 992px; width: 664px;"></p>

<pre><strong>输入：</strong>num_people = 6
<strong>输出：</strong>5
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>num_people = 8
<strong>输出：</strong>14
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= num_people &lt;= 1000</code></li>
	<li><code>num_people % 2 == 0</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

我们设计一个函数 $dfs(i)$，表示 $i$ 个人的握手方案数。答案为 $dfs(n)$。

函数 $dfs(i)$ 的执行逻辑如下：

-   如果 $i \lt 2$，那么只有一种握手方案，即不握手，返回 $1$。
-   否则，我们可以枚举第一个人与谁握手，记剩余的左边的人数为 $l$，右边的人数为 $r=i-l-2$，那么有 $dfs(i)= \sum_{l=0}^{i-1} dfs(l) \times dfs(r)$。

为了避免重复计算，我们使用记忆化搜索的方法。

时间复杂度 $O(n^2)$，空间复杂度 $O(n)$。其中 $n$ 为 $numPeople$ 的大小。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numberOfWays(self, numPeople: int) -> int:
        @cache
        def dfs(i: int) -> int:
            if i < 2:
                return 1
            ans = 0
            for l in range(0, i, 2):
                r = i - l - 2
                ans += dfs(l) * dfs(r)
                ans %= mod
            return ans

        mod = 10**9 + 7
        return dfs(numPeople)
```

#### Java

```java
class Solution {
    private int[] f;
    private final int mod = (int) 1e9 + 7;

    public int numberOfWays(int numPeople) {
        f = new int[numPeople + 1];
        return dfs(numPeople);
    }

    private int dfs(int i) {
        if (i < 2) {
            return 1;
        }
        if (f[i] != 0) {
            return f[i];
        }
        for (int l = 0; l < i; l += 2) {
            int r = i - l - 2;
            f[i] = (int) ((f[i] + (1L * dfs(l) * dfs(r) % mod)) % mod);
        }
        return f[i];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numberOfWays(int numPeople) {
        const int mod = 1e9 + 7;
        int f[numPeople + 1];
        memset(f, 0, sizeof(f));
        function<int(int)> dfs = [&](int i) {
            if (i < 2) {
                return 1;
            }
            if (f[i]) {
                return f[i];
            }
            for (int l = 0; l < i; l += 2) {
                int r = i - l - 2;
                f[i] = (f[i] + 1LL * dfs(l) * dfs(r) % mod) % mod;
            }
            return f[i];
        };
        return dfs(numPeople);
    }
};
```

#### Go

```go
func numberOfWays(numPeople int) int {
	const mod int = 1e9 + 7
	f := make([]int, numPeople+1)
	var dfs func(int) int
	dfs = func(i int) int {
		if i < 2 {
			return 1
		}
		if f[i] != 0 {
			return f[i]
		}
		for l := 0; l < i; l += 2 {
			r := i - l - 2
			f[i] = (f[i] + dfs(l)*dfs(r)) % mod
		}
		return f[i]
	}
	return dfs(numPeople)
}
```

#### TypeScript

```ts
function numberOfWays(numPeople: number): number {
    const mod = 10 ** 9 + 7;
    const f: number[] = Array(numPeople + 1).fill(0);
    const dfs = (i: number): number => {
        if (i < 2) {
            return 1;
        }
        if (f[i] !== 0) {
            return f[i];
        }
        for (let l = 0; l < i; l += 2) {
            const r = i - l - 2;
            f[i] += Number((BigInt(dfs(l)) * BigInt(dfs(r))) % BigInt(mod));
            f[i] %= mod;
        }
        return f[i];
    };
    return dfs(numPeople);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
