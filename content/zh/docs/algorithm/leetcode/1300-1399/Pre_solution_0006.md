---
title: "1350_院系无效的学生 🔒"
date: 2025-10-08T18:37:12+08:00
weight: 6
tags: [二分查找, 位运算, 前缀和, 动态规划, 哈希表, 堆（优先队列）, 字符串, 排序, 数学, 数据库, 数据流, 数组, 滑动窗口, 矩阵, 组合数学, 计数, 设计, 贪心]
---

{{< markmap >}}
### [1350_院系无效的学生 🔒](#1350)
#### [数据库](#1350)
### [1351_统计有序矩阵中的负数](#1351)
#### [数组](#1351)
#### [二分查找](#1351)
#### [矩阵](#1351)
### [1352_最后 K 个数的乘积](#1352)
#### [设计](#1352)
#### [数组](#1352)
#### [数学](#1352)
#### [数据流](#1352)
#### [前缀和](#1352)
### [1353_最多可以参加的会议数目](#1353)
#### [贪心](#1353)
#### [数组](#1353)
#### [排序](#1353)
#### [堆（优先队列）](#1353)
### [1354_多次求和构造目标数组](#1354)
#### [数组](#1354)
#### [堆（优先队列）](#1354)
### [1355_活动参与者 🔒](#1355)
#### [数据库](#1355)
### [1356_根据数字二进制下 1 的数目排序](#1356)
#### [位运算](#1356)
#### [数组](#1356)
#### [计数](#1356)
#### [排序](#1356)
### [1357_每隔 n 个顾客打折](#1357)
#### [设计](#1357)
#### [数组](#1357)
#### [哈希表](#1357)
### [1358_包含所有三种字符的子字符串数目](#1358)
#### [哈希表](#1358)
#### [字符串](#1358)
#### [滑动窗口](#1358)
### [1359_有效的快递序列数目](#1359)
#### [数学](#1359)
#### [动态规划](#1359)
#### [组合数学](#1359)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1350_院系无效的学生 🔒
___
#### 数据库
---
### 1351_统计有序矩阵中的负数
___
#### 数组
___
#### 二分查找
___
#### 矩阵
---
### 1352_最后 K 个数的乘积
___
#### 设计
___
#### 数组
___
#### 数学
___
#### 数据流
___
#### 前缀和
---
### 1353_最多可以参加的会议数目
___
#### 贪心
___
#### 数组
___
#### 排序
___
#### 堆（优先队列）
---
### 1354_多次求和构造目标数组
___
#### 数组
___
#### 堆（优先队列）
---
### 1355_活动参与者 🔒
___
#### 数据库
---
### 1356_根据数字二进制下 1 的数目排序
___
#### 位运算
___
#### 数组
___
#### 计数
___
#### 排序
---
### 1357_每隔 n 个顾客打折
___
#### 设计
___
#### 数组
___
#### 哈希表
---
### 1358_包含所有三种字符的子字符串数目
___
#### 哈希表
___
#### 字符串
___
#### 滑动窗口
---
### 1359_有效的快递序列数目
___
#### 数学
___
#### 动态规划
___
#### 组合数学
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 位运算 | 前缀和 |
| 动态规划 | 哈希表 | 堆（优先队列） |
| 字符串 | 排序 | 数学 |
| 数据库 | 数据流 | 数组 |
| 滑动窗口 | 矩阵 | 组合数学 |
| 计数 | 设计 | 贪心 |

# [1350. 院系无效的学生 🔒](https://leetcode.cn/problems/students-with-invalid-departments){#1350}

{{< tabs "1350" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT s.id, s.name
FROM
    Students AS s
    LEFT JOIN Departments AS d ON s.department_id = d.id
WHERE d.id IS NULL;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>院系表: <code>Departments</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| id            | int     |
| name          | varchar |
+---------------+---------+
在 SQL 中，id 是该表的主键
该表包含一所大学每个院系的 id 信息
</pre>

<p>&nbsp;</p>

<p>学生表: <code>Students</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| id            | int     |
| name          | varchar |
| department_id | int     |
+---------------+---------+
在 SQL 中，id 是该表的主键
该表包含一所大学每个学生的 id 和他/她就读的院系信息
</pre>

<p>&nbsp;</p>

<p>找出那些所在院系不存在的学生的 id 和姓名</p>

<p>可以以 <strong>任何顺序</strong> 返回结果。</p>

<p>下面是返回结果格式的例子。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
Departments 表:
+------+--------------------------+
| id   | name                     |
+------+--------------------------+
| 1    | Electrical Engineering   |
| 7    | Computer Engineering     |
| 13   | Bussiness Administration |
+------+--------------------------+
Students 表:
+------+----------+---------------+
| id   | name     | department_id |
+------+----------+---------------+
| 23   | Alice    | 1             |
| 1    | Bob      | 7             |
| 5    | Jennifer | 13            |
| 2    | John     | 14            |
| 4    | Jasmine  | 77            |
| 3    | Steve    | 74            |
| 6    | Luis     | 1             |
| 8    | Jonathan | 7             |
| 7    | Daiana   | 33            |
| 11   | Madelynn | 1             |
+------+----------+---------------+
<strong>输出：</strong>
+------+----------+
| id   | name     |
+------+----------+
| 2    | John     |
| 7    | Daiana   |
| 4    | Jasmine  |
| 3    | Steve    |
+------+----------+
<strong>解释：</strong>
John, Daiana, Steve 和 Jasmine 所在的院系分别是 14, 33, 74 和 77， 其中 14, 33, 74 和 77 并不存在于院系表</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：子查询

我们直接使用子查询的方式，找出所有不在院系表中的学生即可。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT id, name
FROM Students
WHERE department_id NOT IN (SELECT id FROM Departments);
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：左连接

我们也可以使用左连接，将 `Students` 表和 `Departments` 连接，连接条件为 `Students.department_id = Departments.id`，然后筛选出 `Departments.id` 为空的学生即可。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT s.id, s.name
FROM
    Students AS s
    LEFT JOIN Departments AS d ON s.department_id = d.id
WHERE d.id IS NULL;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1351. 统计有序矩阵中的负数](https://leetcode.cn/problems/count-negative-numbers-in-a-sorted-matrix){#1351}

{{< tabs "1351" >}}

{{% tab "python" %}}
```python
class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        return sum(bisect_left(row[::-1], 0) for row in grid)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countNegatives(int[][] grid) {
        int ans = 0;
        int n = grid[0].length;
        for (int[] row : grid) {
            int left = 0, right = n;
            while (left < right) {
                int mid = (left + right) >> 1;
                if (row[mid] < 0) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            ans += n - left;
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
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0;
        for (auto& row : grid) {
            ans += lower_bound(row.rbegin(), row.rend(), 0) - row.rbegin();
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countNegatives(grid [][]int) int {
	ans, n := 0, len(grid[0])
	for _, row := range grid {
		left, right := 0, n
		for left < right {
			mid := (left + right) >> 1
			if row[mid] < 0 {
				right = mid
			} else {
				left = mid + 1
			}
		}
		ans += n - left
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countNegatives(grid: number[][]): number {
    const n = grid[0].length;
    let ans = 0;
    for (let row of grid) {
        let left = 0,
            right = n;
        while (left < right) {
            const mid = (left + right) >> 1;
            if (row[mid] < 0) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        ans += n - left;
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn count_negatives(grid: Vec<Vec<i32>>) -> i32 {
        let m = grid.len();
        let n = grid[0].len();
        let mut i = m;
        let mut j = 0;
        let mut res = 0;
        while i > 0 && j < n {
            if grid[i - 1][j] >= 0 {
                j += 1;
            } else {
                res += n - j;
                i -= 1;
            }
        }
        res as i32
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[][]} grid
 * @return {number}
 */
var countNegatives = function (grid) {
    const n = grid[0].length;
    let ans = 0;
    for (let row of grid) {
        let left = 0,
            right = n;
        while (left < right) {
            const mid = (left + right) >> 1;
            if (row[mid] < 0) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        ans += n - left;
    }
    return ans;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个&nbsp;<code>m&nbsp;* n</code>&nbsp;的矩阵&nbsp;<code>grid</code>，矩阵中的元素无论是按行还是按列，都以非严格递减顺序排列。&nbsp;请你统计并返回&nbsp;<code>grid</code>&nbsp;中 <strong>负数</strong> 的数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
<strong>输出：</strong>8
<strong>解释：</strong>矩阵中共有 8 个负数。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>grid = [[3,2],[1,0]]
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 100</code></li>
	<li><code>-100 &lt;= grid[i][j] &lt;= 100</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>你可以设计一个时间复杂度为 <code>O(n + m)</code> 的解决方案吗？</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：从左下角或右上角开始遍历

根据**其行列都以非递增顺序排列**的特点，可以从**左下角**开始**往右上方向遍历**。

当遇到负数时，说明这一行从当前位置开始往右的所有元素均为负数，我们将答案加上这一行剩余的元素个数，即 $n - j$，并且向上移动一行，即 $i \leftarrow i - 1$。否则，向右移动一列，即 $j \leftarrow j + 1$。

遍历结束，返回答案。

时间复杂度 $O(m + n)$，其中 $m$ 和 $n$ 分别为矩阵的行数和列数。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        i, j = m - 1, 0
        ans = 0
        while i >= 0 and j < n:
            if grid[i][j] < 0:
                ans += n - j
                i -= 1
            else:
                j += 1
        return ans
```

#### Java

```java
class Solution {
    public int countNegatives(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int ans = 0;
        for (int i = m - 1, j = 0; i >= 0 && j < n;) {
            if (grid[i][j] < 0) {
                ans += n - j;
                --i;
            } else {
                ++j;
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
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        for (int i = m - 1, j = 0; i >= 0 && j < n;) {
            if (grid[i][j] < 0) {
                ans += n - j;
                --i;
            } else
                ++j;
        }
        return ans;
    }
};
```

#### Go

```go
func countNegatives(grid [][]int) int {
	m, n := len(grid), len(grid[0])
	ans := 0
	for i, j := m-1, 0; i >= 0 && j < n; {
		if grid[i][j] < 0 {
			ans += n - j
			i--
		} else {
			j++
		}
	}
	return ans
}
```

#### TypeScript

```ts
function countNegatives(grid: number[][]): number {
    const m = grid.length,
        n = grid[0].length;
    let ans = 0;
    for (let i = m - 1, j = 0; i >= 0 && j < n; ) {
        if (grid[i][j] < 0) {
            ans += n - j;
            --i;
        } else {
            ++j;
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn count_negatives(grid: Vec<Vec<i32>>) -> i32 {
        let n = grid[0].len();
        grid.into_iter()
            .map(|nums| {
                let mut left = 0;
                let mut right = n;
                while left < right {
                    let mid = left + (right - left) / 2;
                    if nums[mid] >= 0 {
                        left = mid + 1;
                    } else {
                        right = mid;
                    }
                }
                (n - left) as i32
            })
            .sum()
    }
}
```

#### JavaScript

```js
/**
 * @param {number[][]} grid
 * @return {number}
 */
var countNegatives = function (grid) {
    const m = grid.length,
        n = grid[0].length;
    let ans = 0;
    for (let i = m - 1, j = 0; i >= 0 && j < n; ) {
        if (grid[i][j] < 0) {
            ans += n - j;
            --i;
        } else {
            ++j;
        }
    }
    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：二分查找

遍历每一行，二分查找每一行第一个小于 $0$ 的位置，从该位置开始往右的所有元素均为负数，累加负数个数到答案中。

遍历结束，返回答案。

时间复杂度 $O(m \times \log n)$，其中 $m$ 和 $n$ 分别为矩阵的行数和列数。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        return sum(bisect_left(row[::-1], 0) for row in grid)
```

#### Java

```java
class Solution {
    public int countNegatives(int[][] grid) {
        int ans = 0;
        int n = grid[0].length;
        for (int[] row : grid) {
            int left = 0, right = n;
            while (left < right) {
                int mid = (left + right) >> 1;
                if (row[mid] < 0) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            ans += n - left;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0;
        for (auto& row : grid) {
            ans += lower_bound(row.rbegin(), row.rend(), 0) - row.rbegin();
        }
        return ans;
    }
};
```

#### Go

```go
func countNegatives(grid [][]int) int {
	ans, n := 0, len(grid[0])
	for _, row := range grid {
		left, right := 0, n
		for left < right {
			mid := (left + right) >> 1
			if row[mid] < 0 {
				right = mid
			} else {
				left = mid + 1
			}
		}
		ans += n - left
	}
	return ans
}
```

#### TypeScript

```ts
function countNegatives(grid: number[][]): number {
    const n = grid[0].length;
    let ans = 0;
    for (let row of grid) {
        let left = 0,
            right = n;
        while (left < right) {
            const mid = (left + right) >> 1;
            if (row[mid] < 0) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        ans += n - left;
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn count_negatives(grid: Vec<Vec<i32>>) -> i32 {
        let m = grid.len();
        let n = grid[0].len();
        let mut i = m;
        let mut j = 0;
        let mut res = 0;
        while i > 0 && j < n {
            if grid[i - 1][j] >= 0 {
                j += 1;
            } else {
                res += n - j;
                i -= 1;
            }
        }
        res as i32
    }
}
```

#### JavaScript

```js
/**
 * @param {number[][]} grid
 * @return {number}
 */
var countNegatives = function (grid) {
    const n = grid[0].length;
    let ans = 0;
    for (let row of grid) {
        let left = 0,
            right = n;
        while (left < right) {
            const mid = (left + right) >> 1;
            if (row[mid] < 0) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        ans += n - left;
    }
    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1352. 最后 K 个数的乘积](https://leetcode.cn/problems/product-of-the-last-k-numbers){#1352}

{{< tabs "1352" >}}

{{% tab "python" %}}
```python
class ProductOfNumbers:
    def __init__(self):
        self.s = [1]

    def add(self, num: int) -> None:
        if num == 0:
            self.s = [1]
            return
        self.s.append(self.s[-1] * num)

    def getProduct(self, k: int) -> int:
        return 0 if len(self.s) <= k else self.s[-1] // self.s[-k - 1]


# Your ProductOfNumbers object will be instantiated and called as such:
# obj = ProductOfNumbers()
# obj.add(num)
# param_2 = obj.getProduct(k)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class ProductOfNumbers {
    private List<Integer> s = new ArrayList<>();

    public ProductOfNumbers() {
        s.add(1);
    }

    public void add(int num) {
        if (num == 0) {
            s.clear();
            s.add(1);
            return;
        }
        s.add(s.get(s.size() - 1) * num);
    }

    public int getProduct(int k) {
        int n = s.size();
        return n <= k ? 0 : s.get(n - 1) / s.get(n - k - 1);
    }
}

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers obj = new ProductOfNumbers();
 * obj.add(num);
 * int param_2 = obj.getProduct(k);
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class ProductOfNumbers {
public:
    ProductOfNumbers() {
        s.push_back(1);
    }

    void add(int num) {
        if (num == 0) {
            s.clear();
            s.push_back(1);
            return;
        }
        s.push_back(s.back() * num);
    }

    int getProduct(int k) {
        int n = s.size();
        return n <= k ? 0 : s.back() / s[n - k - 1];
    }

private:
    vector<int> s;
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type ProductOfNumbers struct {
	s []int
}

func Constructor() ProductOfNumbers {
	return ProductOfNumbers{[]int{1}}
}

func (this *ProductOfNumbers) Add(num int) {
	if num == 0 {
		this.s = []int{1}
		return
	}
	this.s = append(this.s, this.s[len(this.s)-1]*num)
}

func (this *ProductOfNumbers) GetProduct(k int) int {
	n := len(this.s)
	if n <= k {
		return 0
	}
	return this.s[len(this.s)-1] / this.s[len(this.s)-k-1]
}

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Add(num);
 * param_2 := obj.GetProduct(k);
 */
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class ProductOfNumbers {
    s = [1];

    add(num: number): void {
        if (num === 0) {
            this.s = [1];
        } else {
            const i = this.s.length;
            this.s[i] = this.s[i - 1] * num;
        }
    }

    getProduct(k: number): number {
        const i = this.s.length;
        if (k > i - 1) return 0;
        return this.s[i - 1] / this.s[i - k - 1];
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
class ProductOfNumbers {
    s = [1];

    add(num) {
        if (num === 0) {
            this.s = [1];
        } else {
            const i = this.s.length;
            this.s[i] = this.s[i - 1] * num;
        }
    }

    getProduct(k) {
        const i = this.s.length;
        if (k > i - 1) return 0;
        return this.s[i - 1] / this.s[i - k - 1];
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>设计一个算法，该算法接受一个整数流并检索该流中最后 <code>k</code> 个整数的乘积。</p>

<p>实现&nbsp;<code>ProductOfNumbers</code>&nbsp;类：</p>

<ul>
	<li><code>ProductOfNumbers()</code>&nbsp;用一个空的流初始化对象。</li>
	<li><code>void add(int num)</code>&nbsp;将数字&nbsp;<code>num</code>&nbsp;添加到当前数字列表的最后面。</li>
	<li><code>int getProduct(int k)</code>&nbsp;返回当前数字列表中，最后&nbsp;<code>k</code>&nbsp;个数字的乘积。你可以假设当前列表中始终 <strong>至少</strong> 包含 <code>k</code> 个数字。</li>
</ul>

<p>题目数据保证：任何时候，任一连续数字序列的乘积都在 32 位整数范围内，不会溢出。</p>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre>
<strong>输入：</strong>
["ProductOfNumbers","add","add","add","add","add","getProduct","getProduct","getProduct","add","getProduct"]
[[],[3],[0],[2],[5],[4],[2],[3],[4],[8],[2]]

<strong>输出：</strong>
[null,null,null,null,null,null,20,40,0,null,32]

<strong>解释：</strong>
ProductOfNumbers productOfNumbers = new ProductOfNumbers();
productOfNumbers.add(3);        // [3]
productOfNumbers.add(0);        // [3,0]
productOfNumbers.add(2);        // [3,0,2]
productOfNumbers.add(5);        // [3,0,2,5]
productOfNumbers.add(4);        // [3,0,2,5,4]
productOfNumbers.getProduct(2); // 返回 20 。最后 2 个数字的乘积是 5 * 4 = 20
productOfNumbers.getProduct(3); // 返回 40 。最后 3 个数字的乘积是 2 * 5 * 4 = 40
productOfNumbers.getProduct(4); // 返回  0 。最后 4 个数字的乘积是 0 * 2 * 5 * 4 = 0
productOfNumbers.add(8);        // [3,0,2,5,4,8]
productOfNumbers.getProduct(2); // 返回 32 。最后 2 个数字的乘积是 4 * 8 = 32 
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= num&nbsp;&lt;=&nbsp;100</code></li>
	<li><code>1 &lt;= k &lt;= 4 * 10<sup>4</sup></code></li>
	<li><code>add</code> 和 <code>getProduct</code>&nbsp;最多被调用&nbsp;<code>4 * 10<sup>4</sup></code> 次。</li>
	<li>在任何时间点流的乘积都在 32 位整数范围内。</li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>您能否 <strong>同时</strong> 将 <code>GetProduct</code> 和 <code>Add</code> 的实现改为 <code>O(1)</code> 时间复杂度，而不是 <code>O(k)</code> 时间复杂度？</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前缀积

我们初始化一个数组 $s$，其中 $s[i]$ 表示前 $i$ 个数字的乘积。

当调用 `add(num)` 时，我们判断 `num` 是否为 $0$，若是，则将 $s$ 置为 `[1]`，否则将 $s$ 的最后一个元素乘以 `num`，并将结果添加到 $s$ 的末尾。

当调用 `getProduct(k)` 时，此时判断 $s$ 的长度是否小于等于 $k$，若是，则返回 $0$，否则返回 $s$ 的最后一个元素除以 $s$ 的倒数第 $k + 1$ 个元素。即 $s[-1] / s[-k - 1]$。

时间复杂度 $O(1)$，空间复杂度 $O(n)$。其中 $n$ 为调用 `add` 的次数。

<!-- tabs:start -->

#### Python3

```python
class ProductOfNumbers:
    def __init__(self):
        self.s = [1]

    def add(self, num: int) -> None:
        if num == 0:
            self.s = [1]
            return
        self.s.append(self.s[-1] * num)

    def getProduct(self, k: int) -> int:
        return 0 if len(self.s) <= k else self.s[-1] // self.s[-k - 1]


# Your ProductOfNumbers object will be instantiated and called as such:
# obj = ProductOfNumbers()
# obj.add(num)
# param_2 = obj.getProduct(k)
```

#### Java

```java
class ProductOfNumbers {
    private List<Integer> s = new ArrayList<>();

    public ProductOfNumbers() {
        s.add(1);
    }

    public void add(int num) {
        if (num == 0) {
            s.clear();
            s.add(1);
            return;
        }
        s.add(s.get(s.size() - 1) * num);
    }

    public int getProduct(int k) {
        int n = s.size();
        return n <= k ? 0 : s.get(n - 1) / s.get(n - k - 1);
    }
}

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers obj = new ProductOfNumbers();
 * obj.add(num);
 * int param_2 = obj.getProduct(k);
 */
```

#### C++

```cpp
class ProductOfNumbers {
public:
    ProductOfNumbers() {
        s.push_back(1);
    }

    void add(int num) {
        if (num == 0) {
            s.clear();
            s.push_back(1);
            return;
        }
        s.push_back(s.back() * num);
    }

    int getProduct(int k) {
        int n = s.size();
        return n <= k ? 0 : s.back() / s[n - k - 1];
    }

private:
    vector<int> s;
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
```

#### Go

```go
type ProductOfNumbers struct {
	s []int
}

func Constructor() ProductOfNumbers {
	return ProductOfNumbers{[]int{1}}
}

func (this *ProductOfNumbers) Add(num int) {
	if num == 0 {
		this.s = []int{1}
		return
	}
	this.s = append(this.s, this.s[len(this.s)-1]*num)
}

func (this *ProductOfNumbers) GetProduct(k int) int {
	n := len(this.s)
	if n <= k {
		return 0
	}
	return this.s[len(this.s)-1] / this.s[len(this.s)-k-1]
}

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Add(num);
 * param_2 := obj.GetProduct(k);
 */
```

#### TypeScript

```ts
class ProductOfNumbers {
    s = [1];

    add(num: number): void {
        if (num === 0) {
            this.s = [1];
        } else {
            const i = this.s.length;
            this.s[i] = this.s[i - 1] * num;
        }
    }

    getProduct(k: number): number {
        const i = this.s.length;
        if (k > i - 1) return 0;
        return this.s[i - 1] / this.s[i - k - 1];
    }
}
```

#### JavaScript

```js
class ProductOfNumbers {
    s = [1];

    add(num) {
        if (num === 0) {
            this.s = [1];
        } else {
            const i = this.s.length;
            this.s[i] = this.s[i - 1] * num;
        }
    }

    getProduct(k) {
        const i = this.s.length;
        if (k > i - 1) return 0;
        return this.s[i - 1] / this.s[i - k - 1];
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1353. 最多可以参加的会议数目](https://leetcode.cn/problems/maximum-number-of-events-that-can-be-attended){#1353}

{{< tabs "1353" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxEvents(self, events: List[List[int]]) -> int:
        g = defaultdict(list)
        l, r = inf, 0
        for s, e in events:
            g[s].append(e)
            l = min(l, s)
            r = max(r, e)
        pq = []
        ans = 0
        for s in range(l, r + 1):
            while pq and pq[0] < s:
                heappop(pq)
            for e in g[s]:
                heappush(pq, e)
            if pq:
                heappop(pq)
                ans += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxEvents(int[][] events) {
        Map<Integer, List<Integer>> g = new HashMap<>();
        int l = Integer.MAX_VALUE, r = 0;
        for (int[] event : events) {
            int s = event[0], e = event[1];
            g.computeIfAbsent(s, k -> new ArrayList<>()).add(e);
            l = Math.min(l, s);
            r = Math.max(r, e);
        }
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        int ans = 0;
        for (int s = l; s <= r; s++) {
            while (!pq.isEmpty() && pq.peek() < s) {
                pq.poll();
            }
            for (int e : g.getOrDefault(s, List.of())) {
                pq.offer(e);
            }
            if (!pq.isEmpty()) {
                pq.poll();
                ans++;
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
    int maxEvents(vector<vector<int>>& events) {
        unordered_map<int, vector<int>> g;
        int l = INT_MAX, r = 0;
        for (auto& event : events) {
            int s = event[0], e = event[1];
            g[s].push_back(e);
            l = min(l, s);
            r = max(r, e);
        }
        priority_queue<int, vector<int>, greater<int>> pq;
        int ans = 0;
        for (int s = l; s <= r; ++s) {
            while (!pq.empty() && pq.top() < s) {
                pq.pop();
            }
            for (int e : g[s]) {
                pq.push(e);
            }
            if (!pq.empty()) {
                pq.pop();
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
func maxEvents(events [][]int) (ans int) {
	g := map[int][]int{}
	l, r := math.MaxInt32, 0
	for _, event := range events {
		s, e := event[0], event[1]
		g[s] = append(g[s], e)
		l = min(l, s)
		r = max(r, e)
	}

	pq := &hp{}
	heap.Init(pq)
	for s := l; s <= r; s++ {
		for pq.Len() > 0 && pq.IntSlice[0] < s {
			heap.Pop(pq)
		}
		for _, e := range g[s] {
			heap.Push(pq, e)
		}
		if pq.Len() > 0 {
			heap.Pop(pq)
			ans++
		}
	}
	return
}

type hp struct{ sort.IntSlice }

func (h *hp) Push(v any) { h.IntSlice = append(h.IntSlice, v.(int)) }
func (h *hp) Pop() any {
	n := len(h.IntSlice)
	v := h.IntSlice[n-1]
	h.IntSlice = h.IntSlice[:n-1]
	return v
}
func (h *hp) Less(i, j int) bool { return h.IntSlice[i] < h.IntSlice[j] }
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxEvents(events: number[][]): number {
    const g: Map<number, number[]> = new Map();
    let l = Infinity,
        r = 0;
    for (const [s, e] of events) {
        if (!g.has(s)) g.set(s, []);
        g.get(s)!.push(e);
        l = Math.min(l, s);
        r = Math.max(r, e);
    }

    const pq = new MinPriorityQueue<number>();
    let ans = 0;
    for (let s = l; s <= r; s++) {
        while (!pq.isEmpty() && pq.front() < s) {
            pq.dequeue();
        }
        for (const e of g.get(s) || []) {
            pq.enqueue(e);
        }
        if (!pq.isEmpty()) {
            pq.dequeue();
            ans++;
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::{BinaryHeap, HashMap};
use std::cmp::Reverse;

impl Solution {
    pub fn max_events(events: Vec<Vec<i32>>) -> i32 {
        let mut g: HashMap<i32, Vec<i32>> = HashMap::new();
        let mut l = i32::MAX;
        let mut r = 0;

        for event in events {
            let s = event[0];
            let e = event[1];
            g.entry(s).or_default().push(e);
            l = l.min(s);
            r = r.max(e);
        }

        let mut pq = BinaryHeap::new();
        let mut ans = 0;

        for s in l..=r {
            while let Some(&Reverse(top)) = pq.peek() {
                if top < s {
                    pq.pop();
                } else {
                    break;
                }
            }
            if let Some(ends) = g.get(&s) {
                for &e in ends {
                    pq.push(Reverse(e));
                }
            }
            if pq.pop().is_some() {
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

<p>给你一个数组&nbsp;<code>events</code>，其中&nbsp;<code>events[i] = [startDay<sub>i</sub>, endDay<sub>i</sub>]</code>&nbsp;，表示会议&nbsp;<code>i</code>&nbsp;开始于&nbsp;<code>startDay<sub>i</sub></code>&nbsp;，结束于&nbsp;<code>endDay<sub>i</sub></code>&nbsp;。</p>

<p>你可以在满足&nbsp;<code>startDay<sub>i</sub>&nbsp;&lt;= d &lt;= endDay<sub>i</sub></code><sub>&nbsp;</sub>中的任意一天&nbsp;<code>d</code>&nbsp;参加会议&nbsp;<code>i</code>&nbsp;。在任意一天&nbsp;<code>d</code>&nbsp;中只能参加一场会议。</p>

<p>请你返回你可以参加的&nbsp;<strong>最大&nbsp;</strong>会议数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1300-1399/1353.Maximum%20Number%20of%20Events%20That%20Can%20Be%20Attended/images/e1.png" style="height: 267px; width: 400px;" /></p>

<pre>
<strong>输入：</strong>events = [[1,2],[2,3],[3,4]]
<strong>输出：</strong>3
<strong>解释：</strong>你可以参加所有的三个会议。
安排会议的一种方案如上图。
第 1 天参加第一个会议。
第 2 天参加第二个会议。
第 3 天参加第三个会议。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>events= [[1,2],[2,3],[3,4],[1,2]]
<strong>输出：</strong>4
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong>​​​​​​</p>

<ul>
	<li><code>1 &lt;= events.length &lt;= 10<sup>5</sup></code></li>
	<li><code>events[i].length == 2</code></li>
	<li><code>1 &lt;= startDay<sub>i</sub>&nbsp;&lt;= endDay<sub>i</sub>&nbsp;&lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 贪心 + 优先队列

我们用一个哈希表 $\textit{g}$ 记录每个会议的开始和结束时间。键为会议的开始时间，值为一个列表，包含所有在该开始时间开始的会议的结束时间。用两个变量 $\textit{l}$ 和 $\textit{r}$ 分别记录会议的最小开始时间和最大结束时间。

对于从小到大每个在 $\textit{l}$ 到 $\textit{r}$ 的时间点 $s$，我们需要做以下操作：

1. 从优先队列中移除所有结束时间小于当前时间 $s$ 的会议。
2. 将所有开始时间等于当前时间 $s$ 的会议的结束时间加入优先队列中。
3. 如果优先队列不为空，则取出结束时间最小的会议，累加答案数，并从优先队列中移除该会议。

这样，我们可以确保在每个时间点 $s$，我们都能参加结束时间最早的会议，从而最大化参加的会议数。

时间复杂度 $O(M \times \log n)$，空间复杂度 $O(n)$，其中 $M$ 和 $n$ 分别为会议的最大结束时间和会议的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxEvents(self, events: List[List[int]]) -> int:
        g = defaultdict(list)
        l, r = inf, 0
        for s, e in events:
            g[s].append(e)
            l = min(l, s)
            r = max(r, e)
        pq = []
        ans = 0
        for s in range(l, r + 1):
            while pq and pq[0] < s:
                heappop(pq)
            for e in g[s]:
                heappush(pq, e)
            if pq:
                heappop(pq)
                ans += 1
        return ans
```

#### Java

```java
class Solution {
    public int maxEvents(int[][] events) {
        Map<Integer, List<Integer>> g = new HashMap<>();
        int l = Integer.MAX_VALUE, r = 0;
        for (int[] event : events) {
            int s = event[0], e = event[1];
            g.computeIfAbsent(s, k -> new ArrayList<>()).add(e);
            l = Math.min(l, s);
            r = Math.max(r, e);
        }
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        int ans = 0;
        for (int s = l; s <= r; s++) {
            while (!pq.isEmpty() && pq.peek() < s) {
                pq.poll();
            }
            for (int e : g.getOrDefault(s, List.of())) {
                pq.offer(e);
            }
            if (!pq.isEmpty()) {
                pq.poll();
                ans++;
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
    int maxEvents(vector<vector<int>>& events) {
        unordered_map<int, vector<int>> g;
        int l = INT_MAX, r = 0;
        for (auto& event : events) {
            int s = event[0], e = event[1];
            g[s].push_back(e);
            l = min(l, s);
            r = max(r, e);
        }
        priority_queue<int, vector<int>, greater<int>> pq;
        int ans = 0;
        for (int s = l; s <= r; ++s) {
            while (!pq.empty() && pq.top() < s) {
                pq.pop();
            }
            for (int e : g[s]) {
                pq.push(e);
            }
            if (!pq.empty()) {
                pq.pop();
                ++ans;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func maxEvents(events [][]int) (ans int) {
	g := map[int][]int{}
	l, r := math.MaxInt32, 0
	for _, event := range events {
		s, e := event[0], event[1]
		g[s] = append(g[s], e)
		l = min(l, s)
		r = max(r, e)
	}

	pq := &hp{}
	heap.Init(pq)
	for s := l; s <= r; s++ {
		for pq.Len() > 0 && pq.IntSlice[0] < s {
			heap.Pop(pq)
		}
		for _, e := range g[s] {
			heap.Push(pq, e)
		}
		if pq.Len() > 0 {
			heap.Pop(pq)
			ans++
		}
	}
	return
}

type hp struct{ sort.IntSlice }

func (h *hp) Push(v any) { h.IntSlice = append(h.IntSlice, v.(int)) }
func (h *hp) Pop() any {
	n := len(h.IntSlice)
	v := h.IntSlice[n-1]
	h.IntSlice = h.IntSlice[:n-1]
	return v
}
func (h *hp) Less(i, j int) bool { return h.IntSlice[i] < h.IntSlice[j] }
```

#### TypeScript

```ts
function maxEvents(events: number[][]): number {
    const g: Map<number, number[]> = new Map();
    let l = Infinity,
        r = 0;
    for (const [s, e] of events) {
        if (!g.has(s)) g.set(s, []);
        g.get(s)!.push(e);
        l = Math.min(l, s);
        r = Math.max(r, e);
    }

    const pq = new MinPriorityQueue<number>();
    let ans = 0;
    for (let s = l; s <= r; s++) {
        while (!pq.isEmpty() && pq.front() < s) {
            pq.dequeue();
        }
        for (const e of g.get(s) || []) {
            pq.enqueue(e);
        }
        if (!pq.isEmpty()) {
            pq.dequeue();
            ans++;
        }
    }
    return ans;
}
```

#### Rust

```rust
use std::collections::{BinaryHeap, HashMap};
use std::cmp::Reverse;

impl Solution {
    pub fn max_events(events: Vec<Vec<i32>>) -> i32 {
        let mut g: HashMap<i32, Vec<i32>> = HashMap::new();
        let mut l = i32::MAX;
        let mut r = 0;

        for event in events {
            let s = event[0];
            let e = event[1];
            g.entry(s).or_default().push(e);
            l = l.min(s);
            r = r.max(e);
        }

        let mut pq = BinaryHeap::new();
        let mut ans = 0;

        for s in l..=r {
            while let Some(&Reverse(top)) = pq.peek() {
                if top < s {
                    pq.pop();
                } else {
                    break;
                }
            }
            if let Some(ends) = g.get(&s) {
                for &e in ends {
                    pq.push(Reverse(e));
                }
            }
            if pq.pop().is_some() {
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

# [1354. 多次求和构造目标数组](https://leetcode.cn/problems/construct-target-array-with-multiple-sums){#1354}

{{< tabs "1354" >}}

{{% tab "python" %}}
```python
class Solution:
    def isPossible(self, target: List[int]) -> bool:
        s = sum(target)
        pq = [-x for x in target]
        heapify(pq)
        while -pq[0] > 1:
            mx = -heappop(pq)
            t = s - mx
            if t == 0 or mx - t < 1:
                return False
            x = (mx % t) or t
            heappush(pq, -x)
            s = s - mx + x
        return True
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean isPossible(int[] target) {
        PriorityQueue<Long> pq = new PriorityQueue<>(Collections.reverseOrder());
        long s = 0;
        for (int x : target) {
            s += x;
            pq.offer((long) x);
        }
        while (pq.peek() > 1) {
            long mx = pq.poll();
            long t = s - mx;
            if (t == 0 || mx - t < 1) {
                return false;
            }
            long x = mx % t;
            if (x == 0) {
                x = t;
            }
            pq.offer(x);
            s = s - mx + x;
        }
        return true;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> pq;
        long long s = 0;
        for (int i = 0; i < target.size(); i++) {
            s += target[i];
            pq.push(target[i]);
        }
        while (pq.top() != 1) {
            int mx = pq.top();
            pq.pop();
            long long t = s - mx;
            if (t < 1 || mx - t < 1) {
                return false;
            }
            int x = mx % t;
            if (x == 0) {
                x = t;
            }
            pq.push(x);
            s = s - mx + x;
        }
        return true;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func isPossible(target []int) bool {
	pq := &hp{target}
	s := 0
	for _, x := range target {
		s += x
	}
	heap.Init(pq)
	for target[0] > 1 {
		mx := target[0]
		t := s - mx
		if t < 1 || mx-t < 1 {
			return false
		}
		x := mx % t
		if x == 0 {
			x = t
		}
		target[0] = x
		heap.Fix(pq, 0)
		s = s - mx + x
	}
	return true
}

type hp struct{ sort.IntSlice }

func (h hp) Less(i, j int) bool { return h.IntSlice[i] > h.IntSlice[j] }
func (hp) Pop() (_ any)         { return }
func (hp) Push(any)             {}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function isPossible(target: number[]): boolean {
    const pq = new MaxPriorityQueue<number>();
    let s = 0;
    for (const x of target) {
        s += x;
        pq.enqueue(x);
    }
    while (pq.front() > 1) {
        const mx = pq.dequeue();
        const t = s - mx;
        if (t < 1 || mx - t < 1) {
            return false;
        }
        const x = mx % t || t;
        pq.enqueue(x);
        s = s - mx + x;
    }
    return true;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组&nbsp;<code>target</code> 。一开始，你有一个数组&nbsp;<code>A</code> ，它的所有元素均为 1 ，你可以执行以下操作：</p>

<ul>
	<li>令&nbsp;<code>x</code>&nbsp;为你数组里所有元素的和</li>
	<li>选择满足&nbsp;<code>0 &lt;= i &lt; target.size</code>&nbsp;的任意下标&nbsp;<code>i</code>&nbsp;，并让&nbsp;<code>A</code>&nbsp;数组里下标为&nbsp;<code>i</code>&nbsp;处的值为&nbsp;<code>x</code>&nbsp;。</li>
	<li>你可以重复该过程任意次</li>
</ul>

<p>如果能从&nbsp;<code>A</code>&nbsp;开始构造出目标数组&nbsp;<code>target</code>&nbsp;，请你返回 True ，否则返回 False 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>target = [9,3,5]
<strong>输出：</strong>true
<strong>解释：</strong>从 [1, 1, 1] 开始
[1, 1, 1], 和为 3 ，选择下标 1
[1, 3, 1], 和为 5， 选择下标 2
[1, 3, 5], 和为 9， 选择下标 0
[9, 3, 5] 完成
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>target = [1,1,1,2]
<strong>输出：</strong>false
<strong>解释：</strong>不可能从 [1,1,1,1] 出发构造目标数组。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>target = [8,5]
<strong>输出：</strong>true
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>N == target.length</code></li>
	<li><code>1 &lt;= target.length&nbsp;&lt;= 5 * 10^4</code></li>
	<li><code>1 &lt;= target[i] &lt;= 10^9</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：逆向构造 + 优先队列（大根堆）

我们发现，如果从数组 $arr$ 开始正向构造目标数组 $target$，每次都不好确定选择哪个下标 $i$，问题比较复杂。而如果我们从数组 $target$ 开始逆向构造，每次构造都一定是选择当前数组中最大的元素，这样就可以保证每次构造都是唯一的，问题比较简单。

因此，我们可以使用优先队列（大根堆）来存储数组 $target$ 中的元素，用一个变量 $s$ 记录数组 $target$ 中所有元素的和。每次从优先队列中取出最大的元素 $mx$，计算当前数组中除 $mx$ 以外的所有元素之和 $t$，如果 $t \lt 1$ 或者 $mx - t \lt 1$，则说明无法构造目标数组 $target$，返回 `false`。否则，我们计算 $mx \bmod t$，如果 $mx \bmod t = 0$，则令 $x = t$，否则令 $x = mx \bmod t$，将 $x$ 加入优先队列中，并更新 $s$ 的值，重复上述操作，直到优先队列中的所有元素都变为 $1$，此时返回 `true`。

时间复杂度 $O(n \log n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $target$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def isPossible(self, target: List[int]) -> bool:
        s = sum(target)
        pq = [-x for x in target]
        heapify(pq)
        while -pq[0] > 1:
            mx = -heappop(pq)
            t = s - mx
            if t == 0 or mx - t < 1:
                return False
            x = (mx % t) or t
            heappush(pq, -x)
            s = s - mx + x
        return True
```

#### Java

```java
class Solution {
    public boolean isPossible(int[] target) {
        PriorityQueue<Long> pq = new PriorityQueue<>(Collections.reverseOrder());
        long s = 0;
        for (int x : target) {
            s += x;
            pq.offer((long) x);
        }
        while (pq.peek() > 1) {
            long mx = pq.poll();
            long t = s - mx;
            if (t == 0 || mx - t < 1) {
                return false;
            }
            long x = mx % t;
            if (x == 0) {
                x = t;
            }
            pq.offer(x);
            s = s - mx + x;
        }
        return true;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> pq;
        long long s = 0;
        for (int i = 0; i < target.size(); i++) {
            s += target[i];
            pq.push(target[i]);
        }
        while (pq.top() != 1) {
            int mx = pq.top();
            pq.pop();
            long long t = s - mx;
            if (t < 1 || mx - t < 1) {
                return false;
            }
            int x = mx % t;
            if (x == 0) {
                x = t;
            }
            pq.push(x);
            s = s - mx + x;
        }
        return true;
    }
};
```

#### Go

```go
func isPossible(target []int) bool {
	pq := &hp{target}
	s := 0
	for _, x := range target {
		s += x
	}
	heap.Init(pq)
	for target[0] > 1 {
		mx := target[0]
		t := s - mx
		if t < 1 || mx-t < 1 {
			return false
		}
		x := mx % t
		if x == 0 {
			x = t
		}
		target[0] = x
		heap.Fix(pq, 0)
		s = s - mx + x
	}
	return true
}

type hp struct{ sort.IntSlice }

func (h hp) Less(i, j int) bool { return h.IntSlice[i] > h.IntSlice[j] }
func (hp) Pop() (_ any)         { return }
func (hp) Push(any)             {}
```

#### TypeScript

```ts
function isPossible(target: number[]): boolean {
    const pq = new MaxPriorityQueue<number>();
    let s = 0;
    for (const x of target) {
        s += x;
        pq.enqueue(x);
    }
    while (pq.front() > 1) {
        const mx = pq.dequeue();
        const t = s - mx;
        if (t < 1 || mx - t < 1) {
            return false;
        }
        const x = mx % t || t;
        pq.enqueue(x);
        s = s - mx + x;
    }
    return true;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1355. 活动参与者 🔒](https://leetcode.cn/problems/activity-participants){#1355}

{{< tabs "1355" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    t AS (
        SELECT activity, COUNT(1) AS cnt
        FROM Friends
        GROUP BY activity
    )
SELECT activity
FROM t
WHERE cnt > (SELECT MIN(cnt) FROM t) AND cnt < (SELECT MAX(cnt) FROM t);
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表: <code>Friends</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| id            | int     |
| name          | varchar |
| activity      | varchar |
+---------------+---------+
id 是朋友的 id，并且在 SQL 中，是该表的主键
name 是朋友的名字
activity 是朋友参加的活动的名字
</pre>

<p>&nbsp;</p>

<p>表: <code>Activities</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| id            | int     |
| name          | varchar |
+---------------+---------+
在 SQL 中，id 是该表的主键
name 是活动的名字
</pre>

<p>&nbsp;</p>

<p>找出那些既没有最多，也没有最少参与者的活动的名字。</p>

<p><code>Activities</code> 表中的任意活动都有在&nbsp;<code>Friends</code> 中参与过。</p>

<p>可以以 <strong>任何顺序</strong> 返回结果。</p>

<p>下面是返回结果格式的例子。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入：</strong>
Friends 表:
+------+--------------+---------------+
| id   | name         | activity      |
+------+--------------+---------------+
| 1    | Jonathan D.  | Eating        |
| 2    | Jade W.      | Singing       |
| 3    | Victor J.    | Singing       |
| 4    | Elvis Q.     | Eating        |
| 5    | Daniel A.    | Eating        |
| 6    | Bob B.       | Horse Riding  |
+------+--------------+---------------+
Activities 表:
+------+--------------+
| id   | name         |
+------+--------------+
| 1    | Eating       |
| 2    | Singing      |
| 3    | Horse Riding |
+------+--------------+
<strong>输出：</strong>
+--------------+
| activity     |
+--------------+
| Singing      |
+--------------+
<strong>解释：</strong>
Eating 活动有三个人参加, 是最多人参加的活动 (Jonathan D. , Elvis Q. and Daniel A.)
Horse Riding 活动有一个人参加, 是最少人参加的活动 (Bob B.)
Singing 活动有两个人参加 (Victor J. and Jade W.)</pre>

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
    t AS (
        SELECT activity, COUNT(1) AS cnt
        FROM Friends
        GROUP BY activity
    )
SELECT activity
FROM t
WHERE cnt > (SELECT MIN(cnt) FROM t) AND cnt < (SELECT MAX(cnt) FROM t);
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1356. 根据数字二进制下 1 的数目排序](https://leetcode.cn/problems/sort-integers-by-the-number-of-1-bits){#1356}

{{< tabs "1356" >}}

{{% tab "python" %}}
```python
class Solution:
    def sortByBits(self, arr: List[int]) -> List[int]:
        return sorted(arr, key=lambda x: (x.bit_count(), x))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] sortByBits(int[] arr) {
        int n = arr.length;
        Integer[] t = new Integer[n];
        for (int i = 0; i < n; ++i) {
            t[i] = arr[i];
        }
        Arrays.sort(t, (a, b) -> {
            int x = Integer.bitCount(a), y = Integer.bitCount(b);
            return x == y ? a - b : x - y;
        });
        for (int i = 0; i < n; ++i) {
            arr[i] = t[i];
        }
        return arr;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [&](auto& a, auto& b) -> bool {
            int x = __builtin_popcount(a), y = __builtin_popcount(b);
            return x < y || (x == y && a < b);
        });
        return arr;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func sortByBits(arr []int) []int {
	sort.Slice(arr, func(i, j int) bool {
		a, b := bits.OnesCount(uint(arr[i])), bits.OnesCount(uint(arr[j]))
		return a < b || (a == b && arr[i] < arr[j])
	})
	return arr
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function sortByBits(arr: number[]): number[] {
    const countOnes = (n: number) => {
        let res = 0;
        while (n) {
            n &= n - 1;
            res++;
        }
        return res;
    };
    return arr.sort((a, b) => countOnes(a) - countOnes(b) || a - b);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn sort_by_bits(mut arr: Vec<i32>) -> Vec<i32> {
        arr.sort_by(|a, b| {
            let res = a.count_ones().cmp(&b.count_ones());
            if res == std::cmp::Ordering::Equal {
                return a.cmp(&b);
            }
            res
        });
        arr
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int countOnes(int n) {
    int res = 0;
    while (n) {
        n &= n - 1;
        res++;
    }
    return res;
}

int cmp(const void* _a, const void* _b) {
    int a = *(int*) _a;
    int b = *(int*) _b;
    int res = countOnes(a) - countOnes(b);
    if (res == 0) {
        return a - b;
    }
    return res;
}

int* sortByBits(int* arr, int arrSize, int* returnSize) {
    qsort(arr, arrSize, sizeof(int), cmp);
    *returnSize = arrSize;
    return arr;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组&nbsp;<code>arr</code>&nbsp;。请你将数组中的元素按照其二进制表示中数字 <strong>1</strong> 的数目升序排序。</p>

<p>如果存在多个数字二进制中&nbsp;<strong>1</strong>&nbsp;的数目相同，则必须将它们按照数值大小升序排列。</p>

<p>请你返回排序后的数组。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>arr = [0,1,2,3,4,5,6,7,8]
<strong>输出：</strong>[0,1,2,4,8,3,5,6,7]
<strong>解释：</strong>[0] 是唯一一个有 0 个 1 的数。
[1,2,4,8] 都有 1 个 1 。
[3,5,6] 有 2 个 1 。
[7] 有 3 个 1 。
按照 1 的个数排序得到的结果数组为 [0,1,2,4,8,3,5,6,7]
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>arr = [1024,512,256,128,64,32,16,8,4,2,1]
<strong>输出：</strong>[1,2,4,8,16,32,64,128,256,512,1024]
<strong>解释：</strong>数组中所有整数二进制下都只有 1 个 1 ，所以你需要按照数值大小将它们排序。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>arr = [10000,10000]
<strong>输出：</strong>[10000,10000]
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>arr = [2,3,5,7,11,13,17,19]
<strong>输出：</strong>[2,3,5,17,7,11,13,19]
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>arr = [10,100,1000,10000]
<strong>输出：</strong>[10,100,10000,1000]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 500</code></li>
	<li><code>0 &lt;= arr[i] &lt;= 10^4</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：自定义排序

我们将数组 $arr$ 按照题目要求排序，即按照二进制表示中数字 $1$ 的数目升序排序，如果存在多个数字二进制中 $1$ 的数目相同，则必须将它们按照数值大小升序排列。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $arr$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def sortByBits(self, arr: List[int]) -> List[int]:
        return sorted(arr, key=lambda x: (x.bit_count(), x))
```

#### Java

```java
class Solution {
    public int[] sortByBits(int[] arr) {
        int n = arr.length;
        for (int i = 0; i < n; ++i) {
            arr[i] += Integer.bitCount(arr[i]) * 100000;
        }
        Arrays.sort(arr);
        for (int i = 0; i < n; ++i) {
            arr[i] %= 100000;
        }
        return arr;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        for (int& v : arr) {
            v += __builtin_popcount(v) * 100000;
        }
        sort(arr.begin(), arr.end());
        for (int& v : arr) {
            v %= 100000;
        }
        return arr;
    }
};
```

#### Go

```go
func sortByBits(arr []int) []int {
	for i, v := range arr {
		arr[i] += bits.OnesCount(uint(v)) * 100000
	}
	sort.Ints(arr)
	for i := range arr {
		arr[i] %= 100000
	}
	return arr
}
```

#### TypeScript

```ts
function sortByBits(arr: number[]): number[] {
    const countOnes = (n: number) => {
        let res = 0;
        while (n) {
            n &= n - 1;
            res++;
        }
        return res;
    };
    return arr.sort((a, b) => countOnes(a) - countOnes(b) || a - b);
}
```

#### Rust

```rust
impl Solution {
    pub fn sort_by_bits(mut arr: Vec<i32>) -> Vec<i32> {
        arr.sort_by(|a, b| {
            let res = a.count_ones().cmp(&b.count_ones());
            if res == std::cmp::Ordering::Equal {
                return a.cmp(&b);
            }
            res
        });
        arr
    }
}
```

#### C

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int countOnes(int n) {
    int res = 0;
    while (n) {
        n &= n - 1;
        res++;
    }
    return res;
}

int cmp(const void* _a, const void* _b) {
    int a = *(int*) _a;
    int b = *(int*) _b;
    int res = countOnes(a) - countOnes(b);
    if (res == 0) {
        return a - b;
    }
    return res;
}

int* sortByBits(int* arr, int arrSize, int* returnSize) {
    qsort(arr, arrSize, sizeof(int), cmp);
    *returnSize = arrSize;
    return arr;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### Java

```java
class Solution {
    public int[] sortByBits(int[] arr) {
        int n = arr.length;
        Integer[] t = new Integer[n];
        for (int i = 0; i < n; ++i) {
            t[i] = arr[i];
        }
        Arrays.sort(t, (a, b) -> {
            int x = Integer.bitCount(a), y = Integer.bitCount(b);
            return x == y ? a - b : x - y;
        });
        for (int i = 0; i < n; ++i) {
            arr[i] = t[i];
        }
        return arr;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [&](auto& a, auto& b) -> bool {
            int x = __builtin_popcount(a), y = __builtin_popcount(b);
            return x < y || (x == y && a < b);
        });
        return arr;
    }
};
```

#### Go

```go
func sortByBits(arr []int) []int {
	sort.Slice(arr, func(i, j int) bool {
		a, b := bits.OnesCount(uint(arr[i])), bits.OnesCount(uint(arr[j]))
		return a < b || (a == b && arr[i] < arr[j])
	})
	return arr
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1357. 每隔 n 个顾客打折](https://leetcode.cn/problems/apply-discount-every-n-orders){#1357}

{{< tabs "1357" >}}

{{% tab "python" %}}
```python
class Cashier:
    def __init__(self, n: int, discount: int, products: List[int], prices: List[int]):
        self.i = 0
        self.n = n
        self.discount = discount
        self.d = {product: price for product, price in zip(products, prices)}

    def getBill(self, product: List[int], amount: List[int]) -> float:
        self.i += 1
        discount = self.discount if self.i % self.n == 0 else 0
        ans = 0
        for p, a in zip(product, amount):
            x = self.d[p] * a
            ans += x - (discount * x) / 100
        return ans


# Your Cashier object will be instantiated and called as such:
# obj = Cashier(n, discount, products, prices)
# param_1 = obj.getBill(product,amount)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Cashier {
    private int i;
    private int n;
    private int discount;
    private Map<Integer, Integer> d = new HashMap<>();

    public Cashier(int n, int discount, int[] products, int[] prices) {
        this.n = n;
        this.discount = discount;
        for (int j = 0; j < products.length; ++j) {
            d.put(products[j], prices[j]);
        }
    }

    public double getBill(int[] product, int[] amount) {
        int dis = (++i) % n == 0 ? discount : 0;
        double ans = 0;
        for (int j = 0; j < product.length; ++j) {
            int p = product[j], a = amount[j];
            int x = d.get(p) * a;
            ans += x - (dis * x) / 100.0;
        }
        return ans;
    }
}

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj.getBill(product,amount);
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Cashier {
public:
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        this->n = n;
        this->discount = discount;
        for (int j = 0; j < products.size(); ++j) {
            d[products[j]] = prices[j];
        }
    }

    double getBill(vector<int> product, vector<int> amount) {
        int dis = (++i) % n == 0 ? discount : 0;
        double ans = 0;
        for (int j = 0; j < product.size(); ++j) {
            int x = d[product[j]] * amount[j];
            ans += x - (dis * x) / 100.0;
        }
        return ans;
    }

private:
    int i = 0;
    int n;
    int discount;
    unordered_map<int, int> d;
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type Cashier struct {
	i        int
	n        int
	discount int
	d        map[int]int
}

func Constructor(n int, discount int, products []int, prices []int) Cashier {
	d := map[int]int{}
	for i, product := range products {
		d[product] = prices[i]
	}
	return Cashier{0, n, discount, d}
}

func (this *Cashier) GetBill(product []int, amount []int) (ans float64) {
	this.i++
	dis := 0
	if this.i%this.n == 0 {
		dis = this.discount
	}
	for j, p := range product {
		x := float64(this.d[p] * amount[j])
		ans += x - (float64(dis)*x)/100.0
	}
	return
}

/**
 * Your Cashier object will be instantiated and called as such:
 * obj := Constructor(n, discount, products, prices);
 * param_1 := obj.GetBill(product,amount);
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>超市里正在举行打折活动，每隔&nbsp;<code>n</code>&nbsp;个顾客会得到 <code>discount</code>&nbsp;的折扣。</p>

<p>超市里有一些商品，第&nbsp;<code>i</code>&nbsp;种商品为&nbsp;<code>products[i]</code>&nbsp;且每件单品的价格为&nbsp;<code>prices[i]</code>&nbsp;。</p>

<p>结账系统会统计顾客的数目，每隔&nbsp;<code>n</code>&nbsp;个顾客结账时，该顾客的账单都会打折，折扣为&nbsp;<code>discount</code>&nbsp;（也就是如果原本账单为&nbsp;<code>x</code>&nbsp;，那么实际金额会变成&nbsp;<code>x - (discount * x) / 100</code>&nbsp;），然后系统会重新开始计数。</p>

<p>顾客会购买一些商品，&nbsp;<code>product[i]</code>&nbsp;是顾客购买的第&nbsp;<code>i</code>&nbsp;种商品，&nbsp;<code>amount[i]</code>&nbsp;是对应的购买该种商品的数目。</p>

<p>请你实现&nbsp;<code>Cashier</code>&nbsp;类：</p>

<ul>
	<li><code>Cashier(int n, int discount, int[] products, int[] prices)</code>&nbsp;初始化实例对象，参数分别为打折频率&nbsp;<code>n</code>&nbsp;，折扣大小 <code>discount</code>&nbsp;，超市里的商品列表 <code>products</code>&nbsp;和它们的价格 <code>prices</code>&nbsp;。</li>
	<li><code>double&nbsp;getBill(int[] product, int[] amount)</code>&nbsp;返回账单的实际金额（如果有打折，请返回打折后的结果）。返回结果与标准答案误差在&nbsp;<code>10^-5</code>&nbsp;以内都视为正确结果。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入</strong>
[&quot;Cashier&quot;,&quot;getBill&quot;,&quot;getBill&quot;,&quot;getBill&quot;,&quot;getBill&quot;,&quot;getBill&quot;,&quot;getBill&quot;,&quot;getBill&quot;]
[[3,50,[1,2,3,4,5,6,7],[100,200,300,400,300,200,100]],[[1,2],[1,2]],[[3,7],[10,10]],[[1,2,3,4,5,6,7],[1,1,1,1,1,1,1]],[[4],[10]],[[7,3],[10,10]],[[7,5,3,1,6,4,2],[10,10,10,9,9,9,7]],[[2,3,5],[5,3,2]]]
<strong>输出</strong>
[null,500.0,4000.0,800.0,4000.0,4000.0,7350.0,2500.0]
<strong>解释</strong>
Cashier cashier = new Cashier(3,50,[1,2,3,4,5,6,7],[100,200,300,400,300,200,100]);
cashier.getBill([1,2],[1,2]);                        // 返回 500.0, 账单金额为 = 1 * 100 + 2 * 200 = 500.
cashier.getBill([3,7],[10,10]);                      // 返回 4000.0
cashier.getBill([1,2,3,4,5,6,7],[1,1,1,1,1,1,1]);    // 返回 800.0 ，账单原本为 1600.0 ，但由于该顾客是第三位顾客，他将得到 50% 的折扣，所以实际金额为 1600 - 1600 * (50 / 100) = 800 。
cashier.getBill([4],[10]);                           // 返回 4000.0
cashier.getBill([7,3],[10,10]);                      // 返回 4000.0
cashier.getBill([7,5,3,1,6,4,2],[10,10,10,9,9,9,7]); // 返回 7350.0 ，账单原本为 14700.0 ，但由于系统计数再次达到三，该顾客将得到 50% 的折扣，实际金额为 7350.0 。
cashier.getBill([2,3,5],[5,3,2]);                    // 返回 2500.0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10^4</code></li>
	<li><code>0 &lt;= discount &lt;= 100</code></li>
	<li><code>1 &lt;= products.length &lt;= 200</code></li>
	<li><code>1 &lt;= products[i] &lt;= 200</code></li>
	<li><code>products</code>&nbsp;列表中&nbsp;<strong>不会</strong>&nbsp;有重复的元素。</li>
	<li><code>prices.length == products.length</code></li>
	<li><code>1 &lt;= prices[i] &lt;= 1000</code></li>
	<li><code>1 &lt;= product.length &lt;= products.length</code></li>
	<li><code>product[i]</code>&nbsp;在&nbsp;<code>products</code>&nbsp;出现过。</li>
	<li><code>amount.length == product.length</code></li>
	<li><code>1 &lt;= amount[i] &lt;= 1000</code></li>
	<li>最多有&nbsp;<code>1000</code> 次对&nbsp;<code>getBill</code>&nbsp;函数的调用。</li>
	<li>返回结果与标准答案误差在&nbsp;<code>10^-5</code>&nbsp;以内都视为正确结果。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 模拟

用哈希表 $d$ 存储商品编号和价格，然后遍历商品编号和数量，计算总价，再根据折扣计算折扣后的价格。

初始化的时间复杂度为 $O(n)$，其中 $n$ 为商品的数量。`getBill` 函数的时间复杂度为 $O(m)$，其中 $m$ 为购买商品的数量。空间复杂度为 $O(n)$。

<!-- tabs:start -->

#### Python3

```python
class Cashier:
    def __init__(self, n: int, discount: int, products: List[int], prices: List[int]):
        self.i = 0
        self.n = n
        self.discount = discount
        self.d = {product: price for product, price in zip(products, prices)}

    def getBill(self, product: List[int], amount: List[int]) -> float:
        self.i += 1
        discount = self.discount if self.i % self.n == 0 else 0
        ans = 0
        for p, a in zip(product, amount):
            x = self.d[p] * a
            ans += x - (discount * x) / 100
        return ans


# Your Cashier object will be instantiated and called as such:
# obj = Cashier(n, discount, products, prices)
# param_1 = obj.getBill(product,amount)
```

#### Java

```java
class Cashier {
    private int i;
    private int n;
    private int discount;
    private Map<Integer, Integer> d = new HashMap<>();

    public Cashier(int n, int discount, int[] products, int[] prices) {
        this.n = n;
        this.discount = discount;
        for (int j = 0; j < products.length; ++j) {
            d.put(products[j], prices[j]);
        }
    }

    public double getBill(int[] product, int[] amount) {
        int dis = (++i) % n == 0 ? discount : 0;
        double ans = 0;
        for (int j = 0; j < product.length; ++j) {
            int p = product[j], a = amount[j];
            int x = d.get(p) * a;
            ans += x - (dis * x) / 100.0;
        }
        return ans;
    }
}

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj.getBill(product,amount);
 */
```

#### C++

```cpp
class Cashier {
public:
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        this->n = n;
        this->discount = discount;
        for (int j = 0; j < products.size(); ++j) {
            d[products[j]] = prices[j];
        }
    }

    double getBill(vector<int> product, vector<int> amount) {
        int dis = (++i) % n == 0 ? discount : 0;
        double ans = 0;
        for (int j = 0; j < product.size(); ++j) {
            int x = d[product[j]] * amount[j];
            ans += x - (dis * x) / 100.0;
        }
        return ans;
    }

private:
    int i = 0;
    int n;
    int discount;
    unordered_map<int, int> d;
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */
```

#### Go

```go
type Cashier struct {
	i        int
	n        int
	discount int
	d        map[int]int
}

func Constructor(n int, discount int, products []int, prices []int) Cashier {
	d := map[int]int{}
	for i, product := range products {
		d[product] = prices[i]
	}
	return Cashier{0, n, discount, d}
}

func (this *Cashier) GetBill(product []int, amount []int) (ans float64) {
	this.i++
	dis := 0
	if this.i%this.n == 0 {
		dis = this.discount
	}
	for j, p := range product {
		x := float64(this.d[p] * amount[j])
		ans += x - (float64(dis)*x)/100.0
	}
	return
}

/**
 * Your Cashier object will be instantiated and called as such:
 * obj := Constructor(n, discount, products, prices);
 * param_1 := obj.GetBill(product,amount);
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1358. 包含所有三种字符的子字符串数目](https://leetcode.cn/problems/number-of-substrings-containing-all-three-characters){#1358}

{{< tabs "1358" >}}

{{% tab "python" %}}
```python
class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        d = {"a": -1, "b": -1, "c": -1}
        ans = 0
        for i, c in enumerate(s):
            d[c] = i
            ans += min(d["a"], d["b"], d["c"]) + 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numberOfSubstrings(String s) {
        int[] d = new int[] {-1, -1, -1};
        int ans = 0;
        for (int i = 0; i < s.length(); ++i) {
            char c = s.charAt(i);
            d[c - 'a'] = i;
            ans += Math.min(d[0], Math.min(d[1], d[2])) + 1;
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
    int numberOfSubstrings(string s) {
        int d[3] = {-1, -1, -1};
        int ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            d[s[i] - 'a'] = i;
            ans += min(d[0], min(d[1], d[2])) + 1;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numberOfSubstrings(s string) (ans int) {
	d := [3]int{-1, -1, -1}
	for i, c := range s {
		d[c-'a'] = i
		ans += min(d[0], min(d[1], d[2])) + 1
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

<p>给你一个字符串 <code>s</code>&nbsp;，它只包含三种字符 a, b 和 c 。</p>

<p>请你返回 a，b 和 c 都&nbsp;<strong>至少&nbsp;</strong>出现过一次的子字符串数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = &quot;abcabc&quot;
<strong>输出：</strong>10
<strong>解释：</strong>包含 a，b 和 c 各至少一次的子字符串为<em> &quot;</em>abc<em>&quot;, &quot;</em>abca<em>&quot;, &quot;</em>abcab<em>&quot;, &quot;</em>abcabc<em>&quot;, &quot;</em>bca<em>&quot;, &quot;</em>bcab<em>&quot;, &quot;</em>bcabc<em>&quot;, &quot;</em>cab<em>&quot;, &quot;</em>cabc<em>&quot; </em>和<em> &quot;</em>abc<em>&quot; </em>(<strong>相同</strong><strong>字符串算多次</strong>)<em>。</em>
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = &quot;aaacb&quot;
<strong>输出：</strong>3
<strong>解释：</strong>包含 a，b 和 c 各至少一次的子字符串为<em> &quot;</em>aaacb<em>&quot;, &quot;</em>aacb<em>&quot; </em>和<em> &quot;</em>acb<em>&quot; 。</em>
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>s = &quot;abc&quot;
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= s.length &lt;= 5 x 10^4</code></li>
	<li><code>s</code>&nbsp;只包含字符 a，b 和 c 。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：一次遍历

我们用一个长度为 $3$ 的数组 $d$ 记录三种字符最近一次出现的位置，初始时均为 $-1$。

遍历字符串 $s$，对于当前位置 $i$，我们先更新 $d[s[i]]=i$，然后合法的字符串个数为 $\min(d[0], d[1], d[2]) + 1$，累加到答案中。

时间复杂度 $O(n)$，其中 $n$ 为字符串 $s$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        d = {"a": -1, "b": -1, "c": -1}
        ans = 0
        for i, c in enumerate(s):
            d[c] = i
            ans += min(d["a"], d["b"], d["c"]) + 1
        return ans
```

#### Java

```java
class Solution {
    public int numberOfSubstrings(String s) {
        int[] d = new int[] {-1, -1, -1};
        int ans = 0;
        for (int i = 0; i < s.length(); ++i) {
            char c = s.charAt(i);
            d[c - 'a'] = i;
            ans += Math.min(d[0], Math.min(d[1], d[2])) + 1;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numberOfSubstrings(string s) {
        int d[3] = {-1, -1, -1};
        int ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            d[s[i] - 'a'] = i;
            ans += min(d[0], min(d[1], d[2])) + 1;
        }
        return ans;
    }
};
```

#### Go

```go
func numberOfSubstrings(s string) (ans int) {
	d := [3]int{-1, -1, -1}
	for i, c := range s {
		d[c-'a'] = i
		ans += min(d[0], min(d[1], d[2])) + 1
	}
	return
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1359. 有效的快递序列数目](https://leetcode.cn/problems/count-all-valid-pickup-and-delivery-options){#1359}

{{< tabs "1359" >}}

{{% tab "python" %}}
```python
class Solution:
    def countOrders(self, n: int) -> int:
        mod = 10**9 + 7
        f = 1
        for i in range(2, n + 1):
            f = (f * i * (2 * i - 1)) % mod
        return f
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countOrders(int n) {
        final int mod = (int) 1e9 + 7;
        long f = 1;
        for (int i = 2; i <= n; ++i) {
            f = f * i * (2 * i - 1) % mod;
        }
        return (int) f;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int countOrders(int n) {
        const int mod = 1e9 + 7;
        long long f = 1;
        for (int i = 2; i <= n; ++i) {
            f = f * i * (2 * i - 1) % mod;
        }
        return f;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countOrders(n int) int {
	const mod = 1e9 + 7
	f := 1
	for i := 2; i <= n; i++ {
		f = f * i * (2*i - 1) % mod
	}
	return f
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
const MOD: i64 = (1e9 as i64) + 7;

impl Solution {
    #[allow(dead_code)]
    pub fn count_orders(n: i32) -> i32 {
        let mut f = 1;
        for i in 2..=n as i64 {
            f = (i * (2 * i - 1) * f) % MOD;
        }
        f as i32
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你&nbsp;<code>n</code>&nbsp;笔订单，每笔订单都需要快递服务。</p>

<p>计算所有有效的 取货 / 交付 可能的顺序，使 delivery(i) 总是在 pickup(i) 之后。</p>

<p>由于答案可能很大，请返回答案对 10^9 + 7 取余的结果。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 1
<strong>输出：</strong>1
<strong>解释：</strong>只有一种序列 (P1, D1)，物品 1 的配送服务（D1）在物品 1 的收件服务（P1）后。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 2
<strong>输出：</strong>6
<strong>解释：</strong>所有可能的序列包括：
(P1,P2,D1,D2)，(P1,P2,D2,D1)，(P1,D1,P2,D2)，(P2,P1,D1,D2)，(P2,P1,D2,D1) 和 (P2,D2,P1,D1)。
(P1,D2,P2,D1) 是一个无效的序列，因为物品 2 的收件服务（P2）不应在物品 2 的配送服务（D2）之后。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 3
<strong>输出：</strong>90
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 500</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i]$ 表示 $i$ 个订单的所有有效的收件/配送序列的数目。初始时 $f[1] = 1$。

我们可以选择这 $i$ 个订单中的任意一个作为最后一个配送的订单 $D_i$，那么它的收件订单 $P_i$ 可以在之前 $2 \times i - 1$ 的任意一个位置，剩下的 $i - 1$ 个订单的配送/收件序列数目为 $f[i - 1]$，所以 $f[i]$ 可以表示为：

$$
f[i] = i \times (2 \times i - 1) \times f[i - 1]
$$

最终的答案即为 $f[n]$。

我们注意到 $f[i]$ 的值只与 $f[i - 1]$ 有关，所以可以用一个变量代替数组，降低空间复杂度。

时间复杂度 $O(n)$，其中 $n$ 为订单数目。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countOrders(self, n: int) -> int:
        mod = 10**9 + 7
        f = 1
        for i in range(2, n + 1):
            f = (f * i * (2 * i - 1)) % mod
        return f
```

#### Java

```java
class Solution {
    public int countOrders(int n) {
        final int mod = (int) 1e9 + 7;
        long f = 1;
        for (int i = 2; i <= n; ++i) {
            f = f * i * (2 * i - 1) % mod;
        }
        return (int) f;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int countOrders(int n) {
        const int mod = 1e9 + 7;
        long long f = 1;
        for (int i = 2; i <= n; ++i) {
            f = f * i * (2 * i - 1) % mod;
        }
        return f;
    }
};
```

#### Go

```go
func countOrders(n int) int {
	const mod = 1e9 + 7
	f := 1
	for i := 2; i <= n; i++ {
		f = f * i * (2*i - 1) % mod
	}
	return f
}
```

#### Rust

```rust
const MOD: i64 = (1e9 as i64) + 7;

impl Solution {
    #[allow(dead_code)]
    pub fn count_orders(n: i32) -> i32 {
        let mut f = 1;
        for i in 2..=n as i64 {
            f = (i * (2 * i - 1) * f) % MOD;
        }
        f as i32
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
