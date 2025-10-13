---
title: "3140_连续空余座位 II 🔒"
date: 2025-10-08T18:40:09+08:00
weight: 5
tags: [二分查找, 位运算, 前缀和, 动态规划, 哈希表, 字符串, 广度优先搜索, 排序, 数据库, 数组, 状态压缩, 矩阵, 计数]
---

{{< markmap >}}
### [3140_连续空余座位 II 🔒](#3140)
#### [数据库](#3140)
### [3141_最大汉明距离 🔒](#3141)
#### [位运算](#3141)
#### [广度优先搜索](#3141)
#### [数组](#3141)
### [3142_判断矩阵是否满足条件](#3142)
#### [数组](#3142)
#### [矩阵](#3142)
### [3143_正方形中的最多点数](#3143)
#### [数组](#3143)
#### [哈希表](#3143)
#### [字符串](#3143)
#### [二分查找](#3143)
#### [排序](#3143)
### [3144_分割字符频率相等的最少子字符串](#3144)
#### [哈希表](#3144)
#### [字符串](#3144)
#### [动态规划](#3144)
#### [计数](#3144)
### [3145_大数组元素的乘积](#3145)
#### [位运算](#3145)
#### [数组](#3145)
#### [二分查找](#3145)
### [3146_两个字符串的排列差](#3146)
#### [哈希表](#3146)
#### [字符串](#3146)
### [3147_从魔法师身上吸取的最大能量](#3147)
#### [数组](#3147)
#### [前缀和](#3147)
### [3148_矩阵中的最大得分](#3148)
#### [数组](#3148)
#### [动态规划](#3148)
#### [矩阵](#3148)
### [3149_找出分数最低的排列](#3149)
#### [位运算](#3149)
#### [数组](#3149)
#### [动态规划](#3149)
#### [状态压缩](#3149)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 3140_连续空余座位 II 🔒
___
#### 数据库
---
### 3141_最大汉明距离 🔒
___
#### 位运算
___
#### 广度优先搜索
___
#### 数组
---
### 3142_判断矩阵是否满足条件
___
#### 数组
___
#### 矩阵
---
### 3143_正方形中的最多点数
___
#### 数组
___
#### 哈希表
___
#### 字符串
___
#### 二分查找
___
#### 排序
---
### 3144_分割字符频率相等的最少子字符串
___
#### 哈希表
___
#### 字符串
___
#### 动态规划
___
#### 计数
---
### 3145_大数组元素的乘积
___
#### 位运算
___
#### 数组
___
#### 二分查找
---
### 3146_两个字符串的排列差
___
#### 哈希表
___
#### 字符串
---
### 3147_从魔法师身上吸取的最大能量
___
#### 数组
___
#### 前缀和
---
### 3148_矩阵中的最大得分
___
#### 数组
___
#### 动态规划
___
#### 矩阵
---
### 3149_找出分数最低的排列
___
#### 位运算
___
#### 数组
___
#### 动态规划
___
#### 状态压缩
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 位运算 | 前缀和 |
| 动态规划 | 哈希表 | 字符串 |
| 广度优先搜索 | 排序 | 数据库 |
| 数组 | 状态压缩 | 矩阵 |
| 计数 |  |  |

# [3140. 连续空余座位 II 🔒](https://leetcode.cn/problems/consecutive-available-seats-ii){#3140}

{{< tabs "3140" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            *,
            seat_id - (RANK() OVER (ORDER BY seat_id)) AS gid
        FROM Cinema
        WHERE free = 1
    ),
    P AS (
        SELECT
            MIN(seat_id) AS first_seat_id,
            MAX(seat_id) AS last_seat_id,
            COUNT(1) AS consecutive_seats_len,
            RANK() OVER (ORDER BY COUNT(1) DESC) AS rk
        FROM T
        GROUP BY gid
    )
SELECT first_seat_id, last_seat_id, consecutive_seats_len
FROM P
WHERE rk = 1
ORDER BY 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code>Cinema</code></p>

<pre>
+-------------+------+
| Column Name | Type |
+-------------+------+
| seat_id     | int  |
| free        | bool |
+-------------+------+
seat_id 是这张表中的自增列。
这张表的每一行表示第 i 个作为是否空余。1 表示空余，而 0 表示被占用。
</pre>

<p>编写一个解决方案来找到电影院中 <strong>最长的空余座位</strong> 的 <strong>长度</strong>。</p>

<p>注意：</p>

<ul>
	<li>保证 <strong>最多有一个</strong> 最长连续序列。</li>
	<li>如果有 <strong>多个</strong> <strong>相同长度</strong> 的连续序列，将它们全部输出。</li>
</ul>

<p>返回结果表以&nbsp;<code>first_seat_id</code>&nbsp;<strong>升序排序</strong>。</p>

<p>结果表的格式如下所示。</p>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<div class="example-block">
<p><strong>输入：</strong></p>

<p>Cinema 表：</p>

<pre class="example-io">
+---------+------+
| seat_id | free |
+---------+------+
| 1       | 1    |
| 2       | 0    |
| 3       | 1    |
| 4       | 1    |
| 5       | 1    |
+---------+------+
</pre>

<p><strong>输出：</strong></p>

<pre class="example-io">
+-----------------+----------------+-----------------------+
| first_seat_id   | last_seat_id   | consecutive_seats_len |
+-----------------+----------------+-----------------------+
| 3               | 5              | 3                     |
+-----------------+----------------+-----------------------+
</pre>

<p><strong>解释：</strong></p>

<ul>
	<li>可用座位的最长连续序列从座位 3 开始，到座位 5 结束，长度为 3。</li>
</ul>
输出表以 first_seat_id 升序排序。</div>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：使用窗口函数

我们首先找到所有空闲座位，然后将座位进行分组，分组的依据是座位的编号减去它的排名。这样一来，连续的空闲座位将会被分到同一组。接着我们找到每组中的最小座位编号、最大座位编号和连续座位的长度。最后我们找到连续座位长度最大的组，输出这个组的最小座位编号、最大座位编号和连续座位的长度。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            *,
            seat_id - (RANK() OVER (ORDER BY seat_id)) AS gid
        FROM Cinema
        WHERE free = 1
    ),
    P AS (
        SELECT
            MIN(seat_id) AS first_seat_id,
            MAX(seat_id) AS last_seat_id,
            COUNT(1) AS consecutive_seats_len,
            RANK() OVER (ORDER BY COUNT(1) DESC) AS rk
        FROM T
        GROUP BY gid
    )
SELECT first_seat_id, last_seat_id, consecutive_seats_len
FROM P
WHERE rk = 1
ORDER BY 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3141. 最大汉明距离 🔒](https://leetcode.cn/problems/maximum-hamming-distances){#3141}

{{< tabs "3141" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxHammingDistances(self, nums: List[int], m: int) -> List[int]:
        dist = [-1] * (1 << m)
        for x in nums:
            dist[x] = 0
        q = nums
        k = 1
        while q:
            t = []
            for x in q:
                for i in range(m):
                    y = x ^ (1 << i)
                    if dist[y] == -1:
                        t.append(y)
                        dist[y] = k
            q = t
            k += 1
        return [m - dist[x ^ ((1 << m) - 1)] for x in nums]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] maxHammingDistances(int[] nums, int m) {
        int[] dist = new int[1 << m];
        Arrays.fill(dist, -1);
        Deque<Integer> q = new ArrayDeque<>();
        for (int x : nums) {
            dist[x] = 0;
            q.offer(x);
        }
        for (int k = 1; !q.isEmpty(); ++k) {
            for (int t = q.size(); t > 0; --t) {
                int x = q.poll();
                for (int i = 0; i < m; ++i) {
                    int y = x ^ (1 << i);
                    if (dist[y] == -1) {
                        q.offer(y);
                        dist[y] = k;
                    }
                }
            }
        }
        for (int i = 0; i < nums.length; ++i) {
            nums[i] = m - dist[nums[i] ^ ((1 << m) - 1)];
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
    vector<int> maxHammingDistances(vector<int>& nums, int m) {
        int dist[1 << m];
        memset(dist, -1, sizeof(dist));
        queue<int> q;
        for (int x : nums) {
            dist[x] = 0;
            q.push(x);
        }
        for (int k = 1; q.size(); ++k) {
            for (int t = q.size(); t; --t) {
                int x = q.front();
                q.pop();
                for (int i = 0; i < m; ++i) {
                    int y = x ^ (1 << i);
                    if (dist[y] == -1) {
                        dist[y] = k;
                        q.push(y);
                    }
                }
            }
        }
        for (int& x : nums) {
            x = m - dist[x ^ ((1 << m) - 1)];
        }
        return nums;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxHammingDistances(nums []int, m int) []int {
	dist := make([]int, 1<<m)
	for i := range dist {
		dist[i] = -1
	}
	q := []int{}
	for _, x := range nums {
		dist[x] = 0
		q = append(q, x)
	}
	for k := 1; len(q) > 0; k++ {
		t := []int{}
		for _, x := range q {
			for i := 0; i < m; i++ {
				y := x ^ (1 << i)
				if dist[y] == -1 {
					dist[y] = k
					t = append(t, y)
				}
			}
		}
		q = t
	}
	for i, x := range nums {
		nums[i] = m - dist[x^(1<<m-1)]
	}
	return nums
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxHammingDistances(nums: number[], m: number): number[] {
    const dist: number[] = Array.from({ length: 1 << m }, () => -1);
    const q: number[] = [];
    for (const x of nums) {
        dist[x] = 0;
        q.push(x);
    }
    for (let k = 1; q.length; ++k) {
        const t: number[] = [];
        for (const x of q) {
            for (let i = 0; i < m; ++i) {
                const y = x ^ (1 << i);
                if (dist[y] === -1) {
                    dist[y] = k;
                    t.push(y);
                }
            }
        }
        q.splice(0, q.length, ...t);
    }
    for (let i = 0; i < nums.length; ++i) {
        nums[i] = m - dist[nums[i] ^ ((1 << m) - 1)];
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

<p>给定一个数组&nbsp;<code>nums</code>&nbsp;和一个整数&nbsp;<code>m</code>，每个元素&nbsp;<code>nums[i]</code>&nbsp;满足&nbsp;<code>0 &lt;= nums[i] &lt; 2<sup>m</sup></code>，返回数组&nbsp;<code>answer</code>。<code>answer</code>&nbsp;数组应该与&nbsp;<code>nums</code>&nbsp; 有相同的长度，每个元素&nbsp;<code>answer[i]</code>&nbsp;表示&nbsp;<code>nums[i]</code>&nbsp;和数组中其它任何元素&nbsp;<code>nums[j]</code>&nbsp;的最大 <strong>汉明距离</strong>。</p>

<p>两个二进制整数之间的&nbsp;<strong>汉明距离</strong> 定义为对应位上二进制位不同的数量（如果需要，添加前置零）。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">nums = [9,12,9,11], m = 4</span></p>

<p><strong>输出：</strong><span class="example-io">[2,3,2,3]</span></p>

<p><strong>解释：</strong></p>

<p>二进制表示为&nbsp;<code>nums = [1001,1100,1001,1011]</code>。</p>

<p>每个下标的最大汉明距离为：</p>

<ul>
	<li><code>nums[0]</code>：1001 与 1100 距离为 2。</li>
	<li><code>nums[1]</code>：1100 与 1011 距离为&nbsp;3。</li>
	<li><code>nums[2]</code>：1001 与 1100 距离为&nbsp;2。</li>
	<li><code>nums[3]</code>：1011 与 1100 距离为&nbsp;3。</li>
</ul>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">nums = [3,4,6,10], m = 4</span></p>

<p><strong>输出：</strong><span class="example-io">[3,3,2,3]</span></p>

<p><strong>解释：</strong></p>

<p>二进制表示为 <code>nums = [0011,0100,0110,1010]</code>。</p>

<p>每个下标的最大汉明距离为：</p>

<ul>
	<li><code>nums[0]</code>：0011 与 0100 距离为 3。</li>
	<li><code>nums[1]</code>：0100 与 0011 距离为 3。</li>
	<li><code>nums[2]</code>：0110 与 1010 距离为 2。</li>
	<li><code>nums[3]</code>：1010 与 0100 距离为 3。</li>
</ul>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= m &lt;= 17</code></li>
	<li><code>2 &lt;= nums.length &lt;= 2<sup>m</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt; 2<sup>m</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：逆向思维 + BFS

题目需要我们求出数组每个元素和其他元素的最大海明距离，我们不妨换个角度思考，我们对每个元素取反，然后求出其到数组中其他元素的最小海明距离，那么 $m$ 减去这个最小海明距离就是我们要求的最大海明距离。

我们可以使用广度优先搜索来求出每个取反的元素到其他元素的最小海明距离。

具体步骤如下：

1. 初始化一个数组 $\textit{dist}$，数组长度为 $2^m$，用来记录每个取反后的元素到其他元素的最小海明距离，初始时全部置为 $-1$。
2. 遍历数组 $\textit{nums}$，将每个元素的取反值置为 $0$，并将其加入队列 $\textit{q}$。
3. 从 $k = 1$ 开始，不断遍历队列 $\textit{q}$，每次遍历时，将队列中的元素取出，然后对其进行 $m$ 次取反操作，将取反后的元素加入队列 $\textit{t}$，并将其到原元素的最小海明距离置为 $k$。
4. 重复步骤 3，直到队列为空。

最后，我们遍历数组 $\textit{nums}$，将每个元素取反后的值作为下标，从 $\textit{dist}$ 数组中取出对应的最小海明距离，然后用 $m$ 减去这个值，就是我们要求的最大海明距离。

时间复杂度 $O(2^m)$，空间复杂度 $O(2^m)$。其中 $m$ 为题目给定的整数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxHammingDistances(self, nums: List[int], m: int) -> List[int]:
        dist = [-1] * (1 << m)
        for x in nums:
            dist[x] = 0
        q = nums
        k = 1
        while q:
            t = []
            for x in q:
                for i in range(m):
                    y = x ^ (1 << i)
                    if dist[y] == -1:
                        t.append(y)
                        dist[y] = k
            q = t
            k += 1
        return [m - dist[x ^ ((1 << m) - 1)] for x in nums]
```

#### Java

```java
class Solution {
    public int[] maxHammingDistances(int[] nums, int m) {
        int[] dist = new int[1 << m];
        Arrays.fill(dist, -1);
        Deque<Integer> q = new ArrayDeque<>();
        for (int x : nums) {
            dist[x] = 0;
            q.offer(x);
        }
        for (int k = 1; !q.isEmpty(); ++k) {
            for (int t = q.size(); t > 0; --t) {
                int x = q.poll();
                for (int i = 0; i < m; ++i) {
                    int y = x ^ (1 << i);
                    if (dist[y] == -1) {
                        q.offer(y);
                        dist[y] = k;
                    }
                }
            }
        }
        for (int i = 0; i < nums.length; ++i) {
            nums[i] = m - dist[nums[i] ^ ((1 << m) - 1)];
        }
        return nums;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> maxHammingDistances(vector<int>& nums, int m) {
        int dist[1 << m];
        memset(dist, -1, sizeof(dist));
        queue<int> q;
        for (int x : nums) {
            dist[x] = 0;
            q.push(x);
        }
        for (int k = 1; q.size(); ++k) {
            for (int t = q.size(); t; --t) {
                int x = q.front();
                q.pop();
                for (int i = 0; i < m; ++i) {
                    int y = x ^ (1 << i);
                    if (dist[y] == -1) {
                        dist[y] = k;
                        q.push(y);
                    }
                }
            }
        }
        for (int& x : nums) {
            x = m - dist[x ^ ((1 << m) - 1)];
        }
        return nums;
    }
};
```

#### Go

```go
func maxHammingDistances(nums []int, m int) []int {
	dist := make([]int, 1<<m)
	for i := range dist {
		dist[i] = -1
	}
	q := []int{}
	for _, x := range nums {
		dist[x] = 0
		q = append(q, x)
	}
	for k := 1; len(q) > 0; k++ {
		t := []int{}
		for _, x := range q {
			for i := 0; i < m; i++ {
				y := x ^ (1 << i)
				if dist[y] == -1 {
					dist[y] = k
					t = append(t, y)
				}
			}
		}
		q = t
	}
	for i, x := range nums {
		nums[i] = m - dist[x^(1<<m-1)]
	}
	return nums
}
```

#### TypeScript

```ts
function maxHammingDistances(nums: number[], m: number): number[] {
    const dist: number[] = Array.from({ length: 1 << m }, () => -1);
    const q: number[] = [];
    for (const x of nums) {
        dist[x] = 0;
        q.push(x);
    }
    for (let k = 1; q.length; ++k) {
        const t: number[] = [];
        for (const x of q) {
            for (let i = 0; i < m; ++i) {
                const y = x ^ (1 << i);
                if (dist[y] === -1) {
                    dist[y] = k;
                    t.push(y);
                }
            }
        }
        q.splice(0, q.length, ...t);
    }
    for (let i = 0; i < nums.length; ++i) {
        nums[i] = m - dist[nums[i] ^ ((1 << m) - 1)];
    }
    return nums;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3142. 判断矩阵是否满足条件](https://leetcode.cn/problems/check-if-grid-satisfies-conditions){#3142}

{{< tabs "3142" >}}

{{% tab "python" %}}
```python
class Solution:
    def satisfiesConditions(self, grid: List[List[int]]) -> bool:
        m, n = len(grid), len(grid[0])
        for i, row in enumerate(grid):
            for j, x in enumerate(row):
                if i + 1 < m and x != grid[i + 1][j]:
                    return False
                if j + 1 < n and x == grid[i][j + 1]:
                    return False
        return True
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean satisfiesConditions(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i + 1 < m && grid[i][j] != grid[i + 1][j]) {
                    return false;
                }
                if (j + 1 < n && grid[i][j] == grid[i][j + 1]) {
                    return false;
                }
            }
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
    bool satisfiesConditions(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i + 1 < m && grid[i][j] != grid[i + 1][j]) {
                    return false;
                }
                if (j + 1 < n && grid[i][j] == grid[i][j + 1]) {
                    return false;
                }
            }
        }
        return true;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func satisfiesConditions(grid [][]int) bool {
	m, n := len(grid), len(grid[0])
	for i, row := range grid {
		for j, x := range row {
			if i+1 < m && x != grid[i+1][j] {
				return false
			}
			if j+1 < n && x == grid[i][j+1] {
				return false
			}
		}
	}
	return true
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function satisfiesConditions(grid: number[][]): boolean {
    const [m, n] = [grid.length, grid[0].length];
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            if (i + 1 < m && grid[i][j] !== grid[i + 1][j]) {
                return false;
            }
            if (j + 1 < n && grid[i][j] === grid[i][j + 1]) {
                return false;
            }
        }
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

<p>给你一个大小为 <code>m x n</code>&nbsp;的二维矩阵&nbsp;<code>grid</code>&nbsp;。你需要判断每一个格子&nbsp;<code>grid[i][j]</code>&nbsp;是否满足：</p>

<ul>
	<li>如果它下面的格子存在，那么它需要等于它下面的格子，也就是&nbsp;<code>grid[i][j] == grid[i + 1][j]</code>&nbsp;。</li>
	<li>如果它右边的格子存在，那么它需要不等于它右边的格子，也就是&nbsp;<code>grid[i][j] != grid[i][j + 1]</code>&nbsp;。</li>
</ul>

<p>如果 <strong>所有</strong>&nbsp;格子都满足以上条件，那么返回 <code>true</code>&nbsp;，否则返回 <code>false</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>grid = [[1,0,2],[1,0,2]]</span></p>

<p><span class="example-io"><b>输出：</b>true</span></p>

<p><strong>解释：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3100-3199/3142.Check%20if%20Grid%20Satisfies%20Conditions/images/examplechanged.png" style="width: 254px; height: 186px;padding: 10px; background: #fff; border-radius: .5rem;" /></strong></p>

<p>网格图中所有格子都符合条件。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>grid = [[1,1,1],[0,0,0]]</span></p>

<p><span class="example-io"><b>输出：</b>false</span></p>

<p><b>解释：</b></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3100-3199/3142.Check%20if%20Grid%20Satisfies%20Conditions/images/example21.png" style="width: 254px; height: 186px;padding: 10px; background: #fff; border-radius: .5rem;" /></strong></p>

<p>同一行中的格子值都相等。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>grid = [[1],[2],[3]]</span></p>

<p><span class="example-io"><b>输出：</b>false</span></p>

<p><strong>解释：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3100-3199/3142.Check%20if%20Grid%20Satisfies%20Conditions/images/changed.png" style="width: 86px; height: 277px;padding: 10px; background: #fff; border-radius: .5rem;" /></p>

<p>同一列中的格子值不相等。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n, m &lt;= 10</code></li>
	<li><code>0 &lt;= grid[i][j] &lt;= 9</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们可以遍历每一个格子，判断其是否满足题目条件，如果有一个格子不满足条件，我们就返回 `false`，否则返回 `true`。

时间复杂度 $O(m \times n)$，其中 $m$ 和 $n$ 分别是矩阵 `grid` 的行数和列数。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def satisfiesConditions(self, grid: List[List[int]]) -> bool:
        m, n = len(grid), len(grid[0])
        for i, row in enumerate(grid):
            for j, x in enumerate(row):
                if i + 1 < m and x != grid[i + 1][j]:
                    return False
                if j + 1 < n and x == grid[i][j + 1]:
                    return False
        return True
```

#### Java

```java
class Solution {
    public boolean satisfiesConditions(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i + 1 < m && grid[i][j] != grid[i + 1][j]) {
                    return false;
                }
                if (j + 1 < n && grid[i][j] == grid[i][j + 1]) {
                    return false;
                }
            }
        }
        return true;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i + 1 < m && grid[i][j] != grid[i + 1][j]) {
                    return false;
                }
                if (j + 1 < n && grid[i][j] == grid[i][j + 1]) {
                    return false;
                }
            }
        }
        return true;
    }
};
```

#### Go

```go
func satisfiesConditions(grid [][]int) bool {
	m, n := len(grid), len(grid[0])
	for i, row := range grid {
		for j, x := range row {
			if i+1 < m && x != grid[i+1][j] {
				return false
			}
			if j+1 < n && x == grid[i][j+1] {
				return false
			}
		}
	}
	return true
}
```

#### TypeScript

```ts
function satisfiesConditions(grid: number[][]): boolean {
    const [m, n] = [grid.length, grid[0].length];
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            if (i + 1 < m && grid[i][j] !== grid[i + 1][j]) {
                return false;
            }
            if (j + 1 < n && grid[i][j] === grid[i][j + 1]) {
                return false;
            }
        }
    }
    return true;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3143. 正方形中的最多点数](https://leetcode.cn/problems/maximum-points-inside-the-square){#3143}

{{< tabs "3143" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxPointsInsideSquare(self, points: List[List[int]], s: str) -> int:
        g = defaultdict(list)
        for i, (x, y) in enumerate(points):
            g[max(abs(x), abs(y))].append(i)
        vis = set()
        ans = 0
        for d in sorted(g):
            idx = g[d]
            for i in idx:
                if s[i] in vis:
                    return ans
                vis.add(s[i])
            ans += len(idx)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxPointsInsideSquare(int[][] points, String s) {
        TreeMap<Integer, List<Integer>> g = new TreeMap<>();
        for (int i = 0; i < points.length; ++i) {
            int x = points[i][0], y = points[i][1];
            int key = Math.max(Math.abs(x), Math.abs(y));
            g.computeIfAbsent(key, k -> new ArrayList<>()).add(i);
        }
        boolean[] vis = new boolean[26];
        int ans = 0;
        for (var idx : g.values()) {
            for (int i : idx) {
                int j = s.charAt(i) - 'a';
                if (vis[j]) {
                    return ans;
                }
                vis[j] = true;
            }
            ans += idx.size();
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
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        map<int, vector<int>> g;
        for (int i = 0; i < points.size(); ++i) {
            auto& p = points[i];
            int key = max(abs(p[0]), abs(p[1]));
            g[key].push_back(i);
        }
        bool vis[26]{};
        int ans = 0;
        for (auto& [_, idx] : g) {
            for (int i : idx) {
                int j = s[i] - 'a';
                if (vis[j]) {
                    return ans;
                }
                vis[j] = true;
            }
            ans += idx.size();
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxPointsInsideSquare(points [][]int, s string) (ans int) {
	g := map[int][]int{}
	for i, p := range points {
		key := max(p[0], -p[0], p[1], -p[1])
		g[key] = append(g[key], i)
	}
	vis := [26]bool{}
	keys := []int{}
	for k := range g {
		keys = append(keys, k)
	}
	sort.Ints(keys)
	for _, k := range keys {
		idx := g[k]
		for _, i := range idx {
			j := s[i] - 'a'
			if vis[j] {
				return
			}
			vis[j] = true
		}
		ans += len(idx)
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxPointsInsideSquare(points: number[][], s: string): number {
    const n = points.length;
    const g: Map<number, number[]> = new Map();
    for (let i = 0; i < n; ++i) {
        const [x, y] = points[i];
        const key = Math.max(Math.abs(x), Math.abs(y));
        if (!g.has(key)) {
            g.set(key, []);
        }
        g.get(key)!.push(i);
    }
    const keys = Array.from(g.keys()).sort((a, b) => a - b);
    const vis: boolean[] = Array(26).fill(false);
    let ans = 0;
    for (const key of keys) {
        const idx = g.get(key)!;
        for (const i of idx) {
            const j = s.charCodeAt(i) - 'a'.charCodeAt(0);
            if (vis[j]) {
                return ans;
            }
            vis[j] = true;
        }
        ans += idx.length;
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

<p>给你一个二维数组&nbsp;<code>points</code>&nbsp;和一个字符串&nbsp;<code>s</code>&nbsp;，其中&nbsp;<code>points[i]</code>&nbsp;表示第 <code>i</code>&nbsp;个点的坐标，<code>s[i]</code>&nbsp;表示第 <code>i</code>&nbsp;个点的 <strong>标签</strong>&nbsp;。</p>

<p>如果一个正方形的中心在&nbsp;<code>(0, 0)</code>&nbsp;，所有边都平行于坐标轴，且正方形内&nbsp;<strong>不</strong>&nbsp;存在标签相同的两个点，那么我们称这个正方形是&nbsp;<strong>合法</strong>&nbsp;的。</p>

<p>请你返回 <strong>合法</strong>&nbsp;正方形中可以包含的 <strong>最多</strong>&nbsp;点数。</p>

<p><strong>注意：</strong></p>

<ul>
	<li>如果一个点位于正方形的边上或者在边以内，则认为该点位于正方形内。</li>
	<li>正方形的边长可以为零。</li>
</ul>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3100-3199/3143.Maximum%20Points%20Inside%20the%20Square/images/3708-tc1.png" style="width: 303px; height: 303px;" /></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>points = [[2,2],[-1,-2],[-4,4],[-3,1],[3,-3]], s = "abdca"</span></p>

<p><span class="example-io"><b>输出：</b>2</span></p>

<p><strong>解释：</strong></p>

<p>边长为 4 的正方形包含两个点&nbsp;<code>points[0]</code> 和&nbsp;<code>points[1]</code>&nbsp;。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3100-3199/3143.Maximum%20Points%20Inside%20the%20Square/images/3708-tc2.png" style="width: 302px; height: 302px;" /></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>points = [[1,1],[-2,-2],[-2,2]], s = "abb"</span></p>

<p><span class="example-io"><b>输出：</b>1</span></p>

<p><strong>解释：</strong></p>

<p>边长为 2 的正方形包含 1 个点&nbsp;<code>points[0]</code>&nbsp;。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>points = [[1,1],[-1,-1],[2,-2]], s = "ccd"</span></p>

<p><span class="example-io"><b>输出：</b>0</span></p>

<p><strong>解释：</strong></p>

<p>任何正方形都无法只包含&nbsp;<code>points[0]</code> 和&nbsp;<code>points[1]</code>&nbsp;中的一个点，所以合法正方形中都不包含任何点。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length, points.length &lt;= 10<sup>5</sup></code></li>
	<li><code>points[i].length == 2</code></li>
	<li><code>-10<sup>9</sup> &lt;= points[i][0], points[i][1] &lt;= 10<sup>9</sup></code></li>
	<li><code>s.length == points.length</code></li>
	<li><code>points</code>&nbsp;中的点坐标互不相同。</li>
	<li><code>s</code>&nbsp;只包含小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 排序

对于一个点 $(x, y)$，我们可以将其映射到以原点为中心的第一象限，即 $(\max(|x|, |y|), \max(|x|, |y|))$。这样，我们就可以将所有的点映射到第一象限，然后按照点到原点的距离进行排序。

我们可以使用哈希表 $g$ 来存储所有点到原点的距离，然后按照距离进行排序。对于每个距离 $d$，我们将所有距离为 $d$ 的点放在一起，然后遍历这些点，如果有两个点的标签相同，那么这个正方形是不合法的，直接返回答案。否则，我们将这些点加入到答案中。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 是点的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxPointsInsideSquare(self, points: List[List[int]], s: str) -> int:
        g = defaultdict(list)
        for i, (x, y) in enumerate(points):
            g[max(abs(x), abs(y))].append(i)
        vis = set()
        ans = 0
        for d in sorted(g):
            idx = g[d]
            for i in idx:
                if s[i] in vis:
                    return ans
                vis.add(s[i])
            ans += len(idx)
        return ans
```

#### Java

```java
class Solution {
    public int maxPointsInsideSquare(int[][] points, String s) {
        TreeMap<Integer, List<Integer>> g = new TreeMap<>();
        for (int i = 0; i < points.length; ++i) {
            int x = points[i][0], y = points[i][1];
            int key = Math.max(Math.abs(x), Math.abs(y));
            g.computeIfAbsent(key, k -> new ArrayList<>()).add(i);
        }
        boolean[] vis = new boolean[26];
        int ans = 0;
        for (var idx : g.values()) {
            for (int i : idx) {
                int j = s.charAt(i) - 'a';
                if (vis[j]) {
                    return ans;
                }
                vis[j] = true;
            }
            ans += idx.size();
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        map<int, vector<int>> g;
        for (int i = 0; i < points.size(); ++i) {
            auto& p = points[i];
            int key = max(abs(p[0]), abs(p[1]));
            g[key].push_back(i);
        }
        bool vis[26]{};
        int ans = 0;
        for (auto& [_, idx] : g) {
            for (int i : idx) {
                int j = s[i] - 'a';
                if (vis[j]) {
                    return ans;
                }
                vis[j] = true;
            }
            ans += idx.size();
        }
        return ans;
    }
};
```

#### Go

```go
func maxPointsInsideSquare(points [][]int, s string) (ans int) {
	g := map[int][]int{}
	for i, p := range points {
		key := max(p[0], -p[0], p[1], -p[1])
		g[key] = append(g[key], i)
	}
	vis := [26]bool{}
	keys := []int{}
	for k := range g {
		keys = append(keys, k)
	}
	sort.Ints(keys)
	for _, k := range keys {
		idx := g[k]
		for _, i := range idx {
			j := s[i] - 'a'
			if vis[j] {
				return
			}
			vis[j] = true
		}
		ans += len(idx)
	}
	return
}
```

#### TypeScript

```ts
function maxPointsInsideSquare(points: number[][], s: string): number {
    const n = points.length;
    const g: Map<number, number[]> = new Map();
    for (let i = 0; i < n; ++i) {
        const [x, y] = points[i];
        const key = Math.max(Math.abs(x), Math.abs(y));
        if (!g.has(key)) {
            g.set(key, []);
        }
        g.get(key)!.push(i);
    }
    const keys = Array.from(g.keys()).sort((a, b) => a - b);
    const vis: boolean[] = Array(26).fill(false);
    let ans = 0;
    for (const key of keys) {
        const idx = g.get(key)!;
        for (const i of idx) {
            const j = s.charCodeAt(i) - 'a'.charCodeAt(0);
            if (vis[j]) {
                return ans;
            }
            vis[j] = true;
        }
        ans += idx.length;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3144. 分割字符频率相等的最少子字符串](https://leetcode.cn/problems/minimum-substring-partition-of-equal-character-frequency){#3144}

{{< tabs "3144" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumSubstringsInPartition(self, s: str) -> int:
        n = len(s)
        f = [inf] * (n + 1)
        f[0] = 0
        for i in range(n):
            cnt = defaultdict(int)
            m = 0
            for j in range(i, -1, -1):
                cnt[s[j]] += 1
                m = max(m, cnt[s[j]])
                if i - j + 1 == len(cnt) * m:
                    f[i + 1] = min(f[i + 1], f[j] + 1)
        return f[n]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumSubstringsInPartition(String s) {
        int n = s.length();
        char[] cs = s.toCharArray();
        int[] f = new int[n + 1];
        Arrays.fill(f, n);
        f[0] = 0;
        for (int i = 0; i < n; ++i) {
            int[] cnt = new int[26];
            int k = 0, m = 0;
            for (int j = i; j >= 0; --j) {
                k += ++cnt[cs[j] - 'a'] == 1 ? 1 : 0;
                m = Math.max(m, cnt[cs[j] - 'a']);
                if (i - j + 1 == k * m) {
                    f[i + 1] = Math.min(f[i + 1], 1 + f[j]);
                }
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
    int minimumSubstringsInPartition(string s) {
        int n = s.size();
        vector<int> f(n + 1, n);
        f[0] = 0;
        for (int i = 0; i < n; ++i) {
            int cnt[26]{};
            int k = 0, m = 0;
            for (int j = i; ~j; --j) {
                k += ++cnt[s[j] - 'a'] == 1;
                m = max(m, cnt[s[j] - 'a']);
                if (i - j + 1 == k * m) {
                    f[i + 1] = min(f[i + 1], f[j] + 1);
                }
            }
        }
        return f[n];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumSubstringsInPartition(s string) int {
	n := len(s)
	f := make([]int, n+1)
	for i := range f {
		f[i] = n
	}
	f[0] = 0
	for i := 0; i < n; i++ {
		cnt := [26]int{}
		k, m := 0, 0
		for j := i; j >= 0; j-- {
			x := int(s[j] - 'a')
			cnt[x]++
			if cnt[x] == 1 {
				k++
			}
			m = max(m, cnt[x])
			if i-j+1 == k*m {
				f[i+1] = min(f[i+1], 1+f[j])
			}
		}
	}
	return f[n]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumSubstringsInPartition(s: string): number {
    const n = s.length;
    const f: number[] = Array(n + 1).fill(n);
    f[0] = 0;
    for (let i = 0; i < n; ++i) {
        const cnt: number[] = Array(26).fill(0);
        let [k, m] = [0, 0];
        for (let j = i; ~j; --j) {
            const x = s.charCodeAt(j) - 97;
            k += ++cnt[x] === 1 ? 1 : 0;
            m = Math.max(m, cnt[x]);
            if (i - j + 1 === k * m) {
                f[i + 1] = Math.min(f[i + 1], 1 + f[j]);
            }
        }
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

<p>给你一个字符串&nbsp;<code>s</code>&nbsp;，你需要将它分割成一个或者更多的&nbsp;<strong>平衡</strong>&nbsp;子字符串。比方说，<code>s == "ababcc"</code>&nbsp;那么&nbsp;<code>("abab", "c", "c")</code>&nbsp;，<code>("ab", "abc", "c")</code>&nbsp;和&nbsp;<code>("ababcc")</code>&nbsp;都是合法分割，但是&nbsp;<code>("a", <strong>"bab"</strong>, "cc")</code>&nbsp;，<code>(<strong>"aba"</strong>, "bc", "c")</code>&nbsp;和&nbsp;<code>("ab", <strong>"abcc"</strong>)</code>&nbsp;不是，不平衡的子字符串用粗体表示。</p>

<p>请你返回 <code>s</code>&nbsp;<strong>最少</strong> 能分割成多少个平衡子字符串。</p>

<p><b>注意：</b>一个 <strong>平衡</strong>&nbsp;字符串指的是字符串中所有字符出现的次数都相同。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>s = "fabccddg"</span></p>

<p><span class="example-io"><b>输出：</b>3</span></p>

<p><strong>解释：</strong></p>

<p>我们可以将 <code>s</code>&nbsp;分割成 3 个子字符串：<code>("fab, "ccdd", "g")</code>&nbsp;或者&nbsp;<code>("fabc", "cd", "dg")</code>&nbsp;。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>s = "abababaccddb"</span></p>

<p><span class="example-io"><b>输出：</b>2</span></p>

<p><strong>解释：</strong></p>

<p>我们可以将&nbsp;<code>s</code>&nbsp;分割成 2 个子字符串：<code>("abab", "abaccddb")</code>&nbsp;。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s</code>&nbsp;只包含小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索 + 哈希表

我们设计一个函数 $\textit{dfs}(i)$，表示从字符串 $s[i]$ 开始分割的最少子字符串数量。那么答案就是 $\textit{dfs}(0)$。

函数 $\textit{dfs}(i)$ 的计算过程如下：

如果 $i \geq n$，表示已经处理完了所有字符，返回 $0$。

否则，我们维护一个哈希表 $\textit{cnt}$，表示当前子字符串中每个字符出现的次数。另外，我们还维护一个哈希表 $\textit{freq}$，表示每个字符出现的次数的频率。

然后我们枚举 $j$ 从 $i$ 到 $n-1$，表示当前子字符串的结束位置。对于每个 $j$，我们更新 $\textit{cnt}$ 和 $\textit{freq}$，然后判断 $\textit{freq}$ 的大小是否为 $1$，如果是的话，我们可以从 $j+1$ 开始分割，此时答案为 $1 + \textit{dfs}(j+1)$，我们取所有 $j$ 中答案的最小值作为函数的返回值。

为了避免重复计算，我们使用记忆化搜索。

时间复杂度 $O(n^2)$，空间复杂度 $O(n \times |\Sigma|)$。其中 $n$ 为字符串 $s$ 的长度，而 $|\Sigma|$ 表示字符集的大小，本题中 $|\Sigma| = 26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumSubstringsInPartition(self, s: str) -> int:
        @cache
        def dfs(i: int) -> int:
            if i >= n:
                return 0
            cnt = defaultdict(int)
            freq = defaultdict(int)
            ans = n - i
            for j in range(i, n):
                if cnt[s[j]]:
                    freq[cnt[s[j]]] -= 1
                    if not freq[cnt[s[j]]]:
                        freq.pop(cnt[s[j]])
                cnt[s[j]] += 1
                freq[cnt[s[j]]] += 1
                if len(freq) == 1 and (t := 1 + dfs(j + 1)) < ans:
                    ans = t
            return ans

        n = len(s)
        return dfs(0)
```

#### Java

```java
class Solution {
    private int n;
    private char[] s;
    private Integer[] f;

    public int minimumSubstringsInPartition(String s) {
        n = s.length();
        f = new Integer[n];
        this.s = s.toCharArray();
        return dfs(0);
    }

    private int dfs(int i) {
        if (i >= n) {
            return 0;
        }
        if (f[i] != null) {
            return f[i];
        }
        int[] cnt = new int[26];
        Map<Integer, Integer> freq = new HashMap<>(26);
        int ans = n - i;
        for (int j = i; j < n; ++j) {
            int k = s[j] - 'a';
            if (cnt[k] > 0) {
                if (freq.merge(cnt[k], -1, Integer::sum) == 0) {
                    freq.remove(cnt[k]);
                }
            }
            ++cnt[k];
            freq.merge(cnt[k], 1, Integer::sum);
            if (freq.size() == 1) {
                ans = Math.min(ans, 1 + dfs(j + 1));
            }
        }
        return f[i] = ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumSubstringsInPartition(string s) {
        int n = s.size();
        int f[n];
        memset(f, -1, sizeof(f));
        auto dfs = [&](this auto&& dfs, int i) -> int {
            if (i >= n) {
                return 0;
            }
            if (f[i] != -1) {
                return f[i];
            }
            f[i] = n - i;
            int cnt[26]{};
            unordered_map<int, int> freq;
            for (int j = i; j < n; ++j) {
                int k = s[j] - 'a';
                if (cnt[k]) {
                    freq[cnt[k]]--;
                    if (freq[cnt[k]] == 0) {
                        freq.erase(cnt[k]);
                    }
                }
                ++cnt[k];
                ++freq[cnt[k]];
                if (freq.size() == 1) {
                    f[i] = min(f[i], 1 + dfs(j + 1));
                }
            }
            return f[i];
        };
        return dfs(0);
    }
};
```

#### Go

```go
func minimumSubstringsInPartition(s string) int {
	n := len(s)
	f := make([]int, n)
	for i := range f {
		f[i] = -1
	}
	var dfs func(int) int
	dfs = func(i int) int {
		if i >= n {
			return 0
		}
		if f[i] != -1 {
			return f[i]
		}
		cnt := [26]int{}
		freq := map[int]int{}
		f[i] = n - i
		for j := i; j < n; j++ {
			k := int(s[j] - 'a')
			if cnt[k] > 0 {
				freq[cnt[k]]--
				if freq[cnt[k]] == 0 {
					delete(freq, cnt[k])
				}
			}
			cnt[k]++
			freq[cnt[k]]++
			if len(freq) == 1 {
				f[i] = min(f[i], 1+dfs(j+1))
			}
		}
		return f[i]
	}
	return dfs(0)
}
```

#### TypeScript

```ts
function minimumSubstringsInPartition(s: string): number {
    const n = s.length;
    const f: number[] = Array(n).fill(-1);
    const dfs = (i: number): number => {
        if (i >= n) {
            return 0;
        }
        if (f[i] !== -1) {
            return f[i];
        }
        const cnt: Map<number, number> = new Map();
        const freq: Map<number, number> = new Map();
        f[i] = n - i;
        for (let j = i; j < n; ++j) {
            const k = s.charCodeAt(j) - 97;
            if (freq.has(cnt.get(k)!)) {
                freq.set(cnt.get(k)!, freq.get(cnt.get(k)!)! - 1);
                if (freq.get(cnt.get(k)!) === 0) {
                    freq.delete(cnt.get(k)!);
                }
            }
            cnt.set(k, (cnt.get(k) || 0) + 1);
            freq.set(cnt.get(k)!, (freq.get(cnt.get(k)!) || 0) + 1);
            if (freq.size === 1) {
                f[i] = Math.min(f[i], 1 + dfs(j + 1));
            }
        }
        return f[i];
    };
    return dfs(0);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：记忆化搜索（优化）

我们可以对方法一进行优化，不需要维护 $\textit{freq}$ 哈希表，只需要维护一个哈希表 $\textit{cnt}$，表示当前子字符串中每个字符出现的次数。另外，维护两个变量 $k$ 和 $m$ 分别表示当前子字符串中的字符种类数和出现次数最多的字符的出现次数。对于一个子串 $s[i..j]$，如果 $j-i+1 = m \times k$，那么这个子串就是一个平衡子串。

时间复杂度 $O(n^2)$，空间复杂度 $O(n \times |\Sigma|)$。其中 $n$ 为字符串 $s$ 的长度，而 $|\Sigma|$ 表示字符集的大小，本题中 $|\Sigma| = 26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumSubstringsInPartition(self, s: str) -> int:
        @cache
        def dfs(i: int) -> int:
            if i >= n:
                return 0
            cnt = defaultdict(int)
            m = 0
            ans = n - i
            for j in range(i, n):
                cnt[s[j]] += 1
                m = max(m, cnt[s[j]])
                if j - i + 1 == m * len(cnt):
                    ans = min(ans, 1 + dfs(j + 1))
            return ans

        n = len(s)
        ans = dfs(0)
        dfs.cache_clear()
        return ans
```

#### Java

```java
class Solution {
    private int n;
    private char[] s;
    private Integer[] f;

    public int minimumSubstringsInPartition(String s) {
        n = s.length();
        f = new Integer[n];
        this.s = s.toCharArray();
        return dfs(0);
    }

    private int dfs(int i) {
        if (i >= n) {
            return 0;
        }
        if (f[i] != null) {
            return f[i];
        }
        int[] cnt = new int[26];
        int ans = n - i;
        int k = 0, m = 0;
        for (int j = i; j < n; ++j) {
            k += ++cnt[s[j] - 'a'] == 1 ? 1 : 0;
            m = Math.max(m, cnt[s[j] - 'a']);
            if (j - i + 1 == k * m) {
                ans = Math.min(ans, 1 + dfs(j + 1));
            }
        }
        return f[i] = ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumSubstringsInPartition(string s) {
        int n = s.size();
        int f[n];
        memset(f, -1, sizeof(f));
        auto dfs = [&](this auto&& dfs, int i) -> int {
            if (i >= n) {
                return 0;
            }
            if (f[i] != -1) {
                return f[i];
            }
            f[i] = n - i;
            int cnt[26]{};
            int k = 0, m = 0;
            for (int j = i; j < n; ++j) {
                k += ++cnt[s[j] - 'a'] == 1 ? 1 : 0;
                m = max(m, cnt[s[j] - 'a']);
                if (j - i + 1 == k * m) {
                    f[i] = min(f[i], 1 + dfs(j + 1));
                }
            }
            return f[i];
        };
        return dfs(0);
    }
};
```

#### Go

```go
func minimumSubstringsInPartition(s string) int {
	n := len(s)
	f := make([]int, n)
	for i := range f {
		f[i] = -1
	}
	var dfs func(int) int
	dfs = func(i int) int {
		if i >= n {
			return 0
		}
		if f[i] != -1 {
			return f[i]
		}
		cnt := [26]int{}
		f[i] = n - i
		k, m := 0, 0
		for j := i; j < n; j++ {
			x := int(s[j] - 'a')
			cnt[x]++
			if cnt[x] == 1 {
				k++
			}
			m = max(m, cnt[x])
			if j-i+1 == k*m {
				f[i] = min(f[i], 1+dfs(j+1))
			}
		}
		return f[i]
	}
	return dfs(0)
}
```

#### TypeScript

```ts
function minimumSubstringsInPartition(s: string): number {
    const n = s.length;
    const f: number[] = Array(n).fill(-1);
    const dfs = (i: number): number => {
        if (i >= n) {
            return 0;
        }
        if (f[i] !== -1) {
            return f[i];
        }
        const cnt: number[] = Array(26).fill(0);
        f[i] = n - i;
        let [k, m] = [0, 0];
        for (let j = i; j < n; ++j) {
            const x = s.charCodeAt(j) - 97;
            k += ++cnt[x] === 1 ? 1 : 0;
            m = Math.max(m, cnt[x]);
            if (j - i + 1 === k * m) {
                f[i] = Math.min(f[i], 1 + dfs(j + 1));
            }
        }
        return f[i];
    };
    return dfs(0);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法三：动态规划

我们可以将记忆化搜索转换为动态规划，定义状态 $f[i]$ 对前 $i$ 个字符进行分割的最少子字符串数量。初始时 $f[0] = 0$，其余 $f[i] = +\infty$ 或者 $f[i] = n$。

接下来我们枚举 $i$ 从 $0$ 到 $n-1$，对于每个 $i$，我们维护一个哈希表 $\textit{cnt}$，表示当前子字符串中每个字符出现的次数。另外，我们维护两个变量 $k$ 和 $m$ 分别表示当前子字符串中的字符种类数和出现次数最多的字符的出现次数。对于一个子串 $s[j..i]$，如果 $i-j+1 = m \times k$，那么这个子串就是一个平衡子串。此时我们可以从 $j$ 开始分割，那么 $f[i+1] = \min(f[i+1], f[j] + 1)$。

最终答案为 $f[n]$。

时间复杂度 $O(n^2)$，空间复杂度 $O(n + |\Sigma|)$。其中 $n$ 为字符串 $s$ 的长度，而 $|\Sigma|$ 表示字符集的大小，本题中 $|\Sigma| = 26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumSubstringsInPartition(self, s: str) -> int:
        n = len(s)
        f = [inf] * (n + 1)
        f[0] = 0
        for i in range(n):
            cnt = defaultdict(int)
            m = 0
            for j in range(i, -1, -1):
                cnt[s[j]] += 1
                m = max(m, cnt[s[j]])
                if i - j + 1 == len(cnt) * m:
                    f[i + 1] = min(f[i + 1], f[j] + 1)
        return f[n]
```

#### Java

```java
class Solution {
    public int minimumSubstringsInPartition(String s) {
        int n = s.length();
        char[] cs = s.toCharArray();
        int[] f = new int[n + 1];
        Arrays.fill(f, n);
        f[0] = 0;
        for (int i = 0; i < n; ++i) {
            int[] cnt = new int[26];
            int k = 0, m = 0;
            for (int j = i; j >= 0; --j) {
                k += ++cnt[cs[j] - 'a'] == 1 ? 1 : 0;
                m = Math.max(m, cnt[cs[j] - 'a']);
                if (i - j + 1 == k * m) {
                    f[i + 1] = Math.min(f[i + 1], 1 + f[j]);
                }
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
    int minimumSubstringsInPartition(string s) {
        int n = s.size();
        vector<int> f(n + 1, n);
        f[0] = 0;
        for (int i = 0; i < n; ++i) {
            int cnt[26]{};
            int k = 0, m = 0;
            for (int j = i; ~j; --j) {
                k += ++cnt[s[j] - 'a'] == 1;
                m = max(m, cnt[s[j] - 'a']);
                if (i - j + 1 == k * m) {
                    f[i + 1] = min(f[i + 1], f[j] + 1);
                }
            }
        }
        return f[n];
    }
};
```

#### Go

```go
func minimumSubstringsInPartition(s string) int {
	n := len(s)
	f := make([]int, n+1)
	for i := range f {
		f[i] = n
	}
	f[0] = 0
	for i := 0; i < n; i++ {
		cnt := [26]int{}
		k, m := 0, 0
		for j := i; j >= 0; j-- {
			x := int(s[j] - 'a')
			cnt[x]++
			if cnt[x] == 1 {
				k++
			}
			m = max(m, cnt[x])
			if i-j+1 == k*m {
				f[i+1] = min(f[i+1], 1+f[j])
			}
		}
	}
	return f[n]
}
```

#### TypeScript

```ts
function minimumSubstringsInPartition(s: string): number {
    const n = s.length;
    const f: number[] = Array(n + 1).fill(n);
    f[0] = 0;
    for (let i = 0; i < n; ++i) {
        const cnt: number[] = Array(26).fill(0);
        let [k, m] = [0, 0];
        for (let j = i; ~j; --j) {
            const x = s.charCodeAt(j) - 97;
            k += ++cnt[x] === 1 ? 1 : 0;
            m = Math.max(m, cnt[x]);
            if (i - j + 1 === k * m) {
                f[i + 1] = Math.min(f[i + 1], 1 + f[j]);
            }
        }
    }
    return f[n];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3145. 大数组元素的乘积](https://leetcode.cn/problems/find-products-of-elements-of-big-array){#3145}

{{< tabs "3145" >}}

{{% tab "python" %}}
```python
m = 50
cnt = [0] * (m + 1)
s = [0] * (m + 1)
p = 1
for i in range(1, m + 1):
    cnt[i] = cnt[i - 1] * 2 + p
    s[i] = s[i - 1] * 2 + p * (i - 1)
    p *= 2


def num_idx_and_sum(x: int) -> tuple:
    idx = 0
    total_sum = 0
    while x:
        i = x.bit_length() - 1
        idx += cnt[i]
        total_sum += s[i]
        x -= 1 << i
        total_sum += (x + 1) * i
        idx += x + 1
    return (idx, total_sum)


def f(i: int) -> int:
    l, r = 0, 1 << m
    while l < r:
        mid = (l + r + 1) >> 1
        idx, _ = num_idx_and_sum(mid)
        if idx < i:
            l = mid
        else:
            r = mid - 1

    total_sum = 0
    idx, total_sum = num_idx_and_sum(l)
    i -= idx
    x = l + 1
    for _ in range(i):
        y = x & -x
        total_sum += y.bit_length() - 1
        x -= y
    return total_sum


class Solution:
    def findProductsOfElements(self, queries: List[List[int]]) -> List[int]:
        return [pow(2, f(right + 1) - f(left), mod) for left, right, mod in queries]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private static final int M = 50;
    private static final long[] cnt = new long[M + 1];
    private static final long[] s = new long[M + 1];

    static {
        long p = 1;
        for (int i = 1; i <= M; i++) {
            cnt[i] = cnt[i - 1] * 2 + p;
            s[i] = s[i - 1] * 2 + p * (i - 1);
            p *= 2;
        }
    }

    private static long[] numIdxAndSum(long x) {
        long idx = 0;
        long totalSum = 0;
        while (x > 0) {
            int i = Long.SIZE - Long.numberOfLeadingZeros(x) - 1;
            idx += cnt[i];
            totalSum += s[i];
            x -= 1L << i;
            totalSum += (x + 1) * i;
            idx += x + 1;
        }
        return new long[] {idx, totalSum};
    }

    private static long f(long i) {
        long l = 0;
        long r = 1L << M;
        while (l < r) {
            long mid = (l + r + 1) >> 1;
            long[] idxAndSum = numIdxAndSum(mid);
            long idx = idxAndSum[0];
            if (idx < i) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }

        long[] idxAndSum = numIdxAndSum(l);
        long totalSum = idxAndSum[1];
        long idx = idxAndSum[0];
        i -= idx;
        long x = l + 1;
        for (int j = 0; j < i; j++) {
            long y = x & -x;
            totalSum += Long.numberOfTrailingZeros(y);
            x -= y;
        }
        return totalSum;
    }

    public int[] findProductsOfElements(long[][] queries) {
        int n = queries.length;
        int[] ans = new int[n];
        for (int i = 0; i < n; i++) {
            long left = queries[i][0];
            long right = queries[i][1];
            long mod = queries[i][2];
            long power = f(right + 1) - f(left);
            ans[i] = qpow(2, power, mod);
        }
        return ans;
    }

    private int qpow(long a, long n, long mod) {
        long ans = 1 % mod;
        for (; n > 0; n >>= 1) {
            if ((n & 1) == 1) {
                ans = ans * a % mod;
            }
            a = a * a % mod;
        }
        return (int) ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
using ll = long long;
const int m = 50;
ll cnt[m + 1];
ll s[m + 1];
ll p = 1;

auto init = [] {
    cnt[0] = 0;
    s[0] = 0;
    for (int i = 1; i <= m; ++i) {
        cnt[i] = cnt[i - 1] * 2 + p;
        s[i] = s[i - 1] * 2 + p * (i - 1);
        p *= 2;
    }
    return 0;
}();

pair<ll, ll> numIdxAndSum(ll x) {
    ll idx = 0;
    ll totalSum = 0;
    while (x > 0) {
        int i = 63 - __builtin_clzll(x);
        idx += cnt[i];
        totalSum += s[i];
        x -= 1LL << i;
        totalSum += (x + 1) * i;
        idx += x + 1;
    }
    return make_pair(idx, totalSum);
}

ll f(ll i) {
    ll l = 0;
    ll r = 1LL << m;
    while (l < r) {
        ll mid = (l + r + 1) >> 1;
        auto idxAndSum = numIdxAndSum(mid);
        ll idx = idxAndSum.first;
        if (idx < i) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }

    auto idxAndSum = numIdxAndSum(l);
    ll totalSum = idxAndSum.second;
    ll idx = idxAndSum.first;
    i -= idx;
    ll x = l + 1;
    for (int j = 0; j < i; ++j) {
        ll y = x & -x;
        totalSum += __builtin_ctzll(y);
        x -= y;
    }
    return totalSum;
}

ll qpow(ll a, ll n, ll mod) {
    ll ans = 1 % mod;
    a = a % mod;
    while (n > 0) {
        if (n & 1) {
            ans = ans * a % mod;
        }
        a = a * a % mod;
        n >>= 1;
    }
    return ans;
}

class Solution {
public:
    vector<int> findProductsOfElements(vector<vector<ll>>& queries) {
        int n = queries.size();
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            ll left = queries[i][0];
            ll right = queries[i][1];
            ll mod = queries[i][2];
            ll power = f(right + 1) - f(left);
            if (power < 0) {
                power += mod;
            }
            ans[i] = static_cast<int>(qpow(2, power, mod));
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
const m = 50

var cnt [m + 1]int64
var s [m + 1]int64
var p int64 = 1

func init() {
	cnt[0] = 0
	s[0] = 0
	for i := 1; i <= m; i++ {
		cnt[i] = cnt[i-1]*2 + p
		s[i] = s[i-1]*2 + p*(int64(i)-1)
		p *= 2
	}
}

func numIdxAndSum(x int64) (int64, int64) {
	var idx, totalSum int64
	for x > 0 {
		i := 63 - bits.LeadingZeros64(uint64(x))
		idx += cnt[i]
		totalSum += s[i]
		x -= 1 << i
		totalSum += (x + 1) * int64(i)
		idx += x + 1
	}
	return idx, totalSum
}

func f(i int64) int64 {
	l, r := int64(0), int64(1)<<m
	for l < r {
		mid := (l + r + 1) >> 1
		idx, _ := numIdxAndSum(mid)
		if idx < i {
			l = mid
		} else {
			r = mid - 1
		}
	}

	_, totalSum := numIdxAndSum(l)
	idx, _ := numIdxAndSum(l)
	i -= idx
	x := l + 1
	for j := int64(0); j < i; j++ {
		y := x & -x
		totalSum += int64(bits.TrailingZeros64(uint64(y)))
		x -= y
	}
	return totalSum
}

func qpow(a, n, mod int64) int64 {
	ans := int64(1) % mod
	a = a % mod
	for n > 0 {
		if n&1 == 1 {
			ans = (ans * a) % mod
		}
		a = (a * a) % mod
		n >>= 1
	}
	return ans
}

func findProductsOfElements(queries [][]int64) []int {
	ans := make([]int, len(queries))
	for i, q := range queries {
		left, right, mod := q[0], q[1], q[2]
		power := f(right+1) - f(left)
		ans[i] = int(qpow(2, power, mod))
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

<p>一个非负整数 <code>x</code>&nbsp;的 <strong>强数组</strong>&nbsp;指的是满足元素为 2 的幂且元素总和为 <code>x</code> 的最短有序数组。下表说明了如何确定 <strong>强数组</strong> 的示例。可以证明，<code>x</code>&nbsp;对应的强数组是独一无二的。</p>

<table border="1">
	<tbody>
		<tr>
			<th>数字</th>
			<th>二进制表示</th>
			<th>强数组</th>
		</tr>
		<tr>
			<td>1</td>
			<td>0000<u>1</u></td>
			<td>[1]</td>
		</tr>
		<tr>
			<td>8</td>
			<td>0<u>1</u>000</td>
			<td>[8]</td>
		</tr>
		<tr>
			<td>10</td>
			<td>0<u>1</u>0<u>1</u>0</td>
			<td>[2, 8]</td>
		</tr>
		<tr>
			<td>13</td>
			<td>0<u>11</u>0<u>1</u></td>
			<td>[1, 4, 8]</td>
		</tr>
		<tr>
			<td>23</td>
			<td><u>1</u>0<u>111</u></td>
			<td>[1, 2, 4, 16]</td>
		</tr>
	</tbody>
</table>

<p>&nbsp;</p>

<p>我们将每一个升序的正整数 <code>i</code>&nbsp;（即1，2，3等等）的 <strong>强数组</strong>&nbsp;连接得到数组&nbsp;<code>big_nums</code>&nbsp;，<code>big_nums</code>&nbsp;开始部分为&nbsp;<code>[<u>1</u>, <u>2</u>, <u>1, 2</u>, <u>4</u>, <u>1, 4</u>, <u>2, 4</u>, <u>1, 2, 4</u>, <u>8</u>, ...]</code>&nbsp;。</p>

<p>给你一个二维整数数组&nbsp;<code>queries</code>&nbsp;，其中&nbsp;<code>queries[i] = [from<sub>i</sub>, to<sub>i</sub>, mod<sub>i</sub>]</code>&nbsp;，你需要计算&nbsp;<code>(big_nums[from<sub>i</sub>] * big_nums[from<sub>i</sub> + 1] * ... * big_nums[to<sub>i</sub>]) % mod<sub>i</sub></code>&nbsp;。</p>

<p>请你返回一个整数数组&nbsp;<code>answer</code>&nbsp;，其中&nbsp;<code>answer[i]</code>&nbsp;是第 <code>i</code>&nbsp;个查询的答案。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><b>输入：</b>queries = [[1,3,7]]</p>

<p><b>输出：</b>[4]</p>

<p><strong>解释：</strong></p>

<p>只有一个查询。</p>

<p><code>big_nums[1..3] = [2,1,2]</code>&nbsp;。它们的乘积为 4。结果为&nbsp;<code>4 % 7 = 4</code>。</p>

<p><strong>示例 2：</strong></p>

<p><b>输入：</b>queries = [[2,5,3],[7,7,4]]</p>

<p><b>输出：</b>[2,2]</p>

<p><strong>解释：</strong></p>

<p>有两个查询。</p>

<p>第一个查询：<code>big_nums[2..5] = [1,2,4,1]</code>&nbsp;。它们的乘积为 8 。结果为&nbsp; <code>8 % 3 = 2</code>。</p>

<p>第二个查询：<code>big_nums[7] = 2</code>&nbsp;。结果为 <code>2 % 4 = 2</code>。</p>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= queries.length &lt;= 500</code></li>
	<li><code>queries[i].length == 3</code></li>
	<li><code>0 &lt;= queries[i][0] &lt;= queries[i][1] &lt;= 10<sup>15</sup></code></li>
	<li><code>1 &lt;= queries[i][2] &lt;= 10<sup>5</sup></code></li>
</ul>

<p>&nbsp;</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二分查找 + 位运算

连续的正整数数字对应的强整数数组连接得到数组 $\textit{bignums}$，题目需要我们求出对于每个查询 $[\textit{left}, \textit{right}, \textit{mod}]$，子数组 $\textit{bignums}[\textit{left}..\textit{right}]$ 的乘积对 $\textit{mod}$ 取模的结果。由于子数组每个元素都是 $2$ 的幂，这等价于求子数组的幂次之和 $\textit{power}$，然后计算 $2^{\textit{power}} \bmod \textit{mod}$。例如，对于子数组 $[1, 4, 8]$，即 $[2^0, 2^2, 2^3]$，其幂次之和为 $0 + 2 + 3 = 5$，所以 $2^5 \bmod \textit{mod}$ 就是我们要求的结果。

因此，我们不妨将 $\textit{bignums}$ 转换为幂次数组，即对于子数组 $[1, 4, 8]$，我们将其转换为 $[0, 2, 3]$。这样，问题转换为求幂次数组的子数组之和，即 $\textit{power} = \textit{f}(\textit{right} + 1) - \textit{f}(\textit{left})$，其中 $\textit{f}(i)$ 表示 $\textit{bignums}[0..i)$ 的幂次之和，也即是前缀和。

接下来，就是根据下标 $i$ 计算 $\textit{f}(i)$ 的值。我们可以使用二分查找的方法，先找到强数组长度和小于 $i$ 的最大数字，然后再计算剩下的数字的幂次之和。

我们根据题目描述，列出数字 $0..14$ 的强整数：

| $\textit{nums}$ | 8($2^3$)                              | 4($2^2$)                              | 2($2^1$)                              | ($2^0$)                               |
| --------------- | ------------------------------------- | ------------------------------------- | ------------------------------------- | ------------------------------------- |
| 0               | 0                                     | 0                                     | 0                                     | 0                                     |
| 1               | <span style="color: red;">0</span>    | <span style="color: red;">0</span>    | <span style="color: red;">0</span>    | <span style="color: red;">1</span>    |
| 2               | <span style="color: blue;">0</span>   | <span style="color: blue;">0</span>   | <span style="color: blue;">1</span>   | <span style="color: blue;">0</span>   |
| 3               | <span style="color: blue;">0</span>   | <span style="color: blue;">0</span>   | <span style="color: blue;">1</span>   | <span style="color: blue;">1</span>   |
| 4               | <span style="color: green;">0</span>  | <span style="color: green;">1</span>  | <span style="color: green;">0</span>  | <span style="color: green;">0</span>  |
| 5               | <span style="color: green;">0</span>  | <span style="color: green;">1</span>  | <span style="color: green;">0</span>  | <span style="color: green;">1</span>  |
| 6               | <span style="color: green;">0</span>  | <span style="color: green;">1</span>  | <span style="color: green;">1</span>  | <span style="color: green;">0</span>  |
| 7               | <span style="color: green;">0</span>  | <span style="color: green;">1</span>  | <span style="color: green;">1</span>  | <span style="color: green;">1</span>  |
| 8               | <span style="color: yellow;">1</span> | <span style="color: yellow;">0</span> | <span style="color: yellow;">0</span> | <span style="color: yellow;">0</span> |
| 9               | <span style="color: yellow;">1</span> | <span style="color: yellow;">0</span> | <span style="color: yellow;">0</span> | <span style="color: yellow;">1</span> |
| 10              | <span style="color: yellow;">1</span> | <span style="color: yellow;">0</span> | <span style="color: yellow;">1</span> | <span style="color: yellow;">0</span> |
| 11              | <span style="color: yellow;">1</span> | <span style="color: yellow;">0</span> | <span style="color: yellow;">1</span> | <span style="color: yellow;">1</span> |
| 12              | <span style="color: yellow;">1</span> | <span style="color: yellow;">1</span> | <span style="color: yellow;">0</span> | <span style="color: yellow;">0</span> |
| 13              | <span style="color: yellow;">1</span> | <span style="color: yellow;">1</span> | <span style="color: yellow;">0</span> | <span style="color: yellow;">1</span> |
| 14              | <span style="color: yellow;">1</span> | <span style="color: yellow;">1</span> | <span style="color: yellow;">1</span> | <span style="color: yellow;">0</span> |

将数字按照 $[2^i, 2^{i+1}-1]$ 的区间划分为不同的颜色，可以发现，区间 $[2^i, 2^{i+1}-1]$ 的数字，相当于在区间 $[0, 2^i-1]$ 的数字基础上，每个数字加上 $2^i$。我们可以根据这个规律，计算出 $\textit{bignums}$ 的前 $i$ 组的所有数字的强数组个数之和 $\textit{cnt}[i]$ 和幂次之和 $\textit{s}[i]$。

接下来，对于任何数字，我们考虑如何计算其强数组的个数和幂次之和。我们可以通过二进制的方式，从最高位开始，诸位计算。例如，对于数字 $13 = 2^3 + 2^2 + 2^0$，前 $2^3$ 个数字的结果可以由 $textit{cnt}[3]$ 和 $\textit{s}[3]$ 计算得到，而剩下的 $[2^3, 13]$ 的结果，相当于给 $[0, 13-2^3]$ 的所有数字，即 $[0, 5]$ 的所有数字的强数组增加 $3$，问题转换为计算 $[0, 5]$ 的所有数字的强数组的个数和幂次之和。这样，我们可以计算出任意数字的强数组的个数和幂次之和。

最后，我们可以根据 $\textit{power}$ 的值，利用快速幂的方法，计算出 $2^{\textit{power}} \bmod \textit{mod}$ 的结果。

时间复杂度 $O(q \times \log M)$，空间复杂度 $(\log M)$。其中 $q$ 为查询的个数，而 $M$ 为数字的上界，本题中 $M \le 10^{15}$。

<!-- tabs:start -->

#### Python3

```python
m = 50
cnt = [0] * (m + 1)
s = [0] * (m + 1)
p = 1
for i in range(1, m + 1):
    cnt[i] = cnt[i - 1] * 2 + p
    s[i] = s[i - 1] * 2 + p * (i - 1)
    p *= 2


def num_idx_and_sum(x: int) -> tuple:
    idx = 0
    total_sum = 0
    while x:
        i = x.bit_length() - 1
        idx += cnt[i]
        total_sum += s[i]
        x -= 1 << i
        total_sum += (x + 1) * i
        idx += x + 1
    return (idx, total_sum)


def f(i: int) -> int:
    l, r = 0, 1 << m
    while l < r:
        mid = (l + r + 1) >> 1
        idx, _ = num_idx_and_sum(mid)
        if idx < i:
            l = mid
        else:
            r = mid - 1

    total_sum = 0
    idx, total_sum = num_idx_and_sum(l)
    i -= idx
    x = l + 1
    for _ in range(i):
        y = x & -x
        total_sum += y.bit_length() - 1
        x -= y
    return total_sum


class Solution:
    def findProductsOfElements(self, queries: List[List[int]]) -> List[int]:
        return [pow(2, f(right + 1) - f(left), mod) for left, right, mod in queries]
```

#### Java

```java
class Solution {
    private static final int M = 50;
    private static final long[] cnt = new long[M + 1];
    private static final long[] s = new long[M + 1];

    static {
        long p = 1;
        for (int i = 1; i <= M; i++) {
            cnt[i] = cnt[i - 1] * 2 + p;
            s[i] = s[i - 1] * 2 + p * (i - 1);
            p *= 2;
        }
    }

    private static long[] numIdxAndSum(long x) {
        long idx = 0;
        long totalSum = 0;
        while (x > 0) {
            int i = Long.SIZE - Long.numberOfLeadingZeros(x) - 1;
            idx += cnt[i];
            totalSum += s[i];
            x -= 1L << i;
            totalSum += (x + 1) * i;
            idx += x + 1;
        }
        return new long[] {idx, totalSum};
    }

    private static long f(long i) {
        long l = 0;
        long r = 1L << M;
        while (l < r) {
            long mid = (l + r + 1) >> 1;
            long[] idxAndSum = numIdxAndSum(mid);
            long idx = idxAndSum[0];
            if (idx < i) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }

        long[] idxAndSum = numIdxAndSum(l);
        long totalSum = idxAndSum[1];
        long idx = idxAndSum[0];
        i -= idx;
        long x = l + 1;
        for (int j = 0; j < i; j++) {
            long y = x & -x;
            totalSum += Long.numberOfTrailingZeros(y);
            x -= y;
        }
        return totalSum;
    }

    public int[] findProductsOfElements(long[][] queries) {
        int n = queries.length;
        int[] ans = new int[n];
        for (int i = 0; i < n; i++) {
            long left = queries[i][0];
            long right = queries[i][1];
            long mod = queries[i][2];
            long power = f(right + 1) - f(left);
            ans[i] = qpow(2, power, mod);
        }
        return ans;
    }

    private int qpow(long a, long n, long mod) {
        long ans = 1 % mod;
        for (; n > 0; n >>= 1) {
            if ((n & 1) == 1) {
                ans = ans * a % mod;
            }
            a = a * a % mod;
        }
        return (int) ans;
    }
}
```

#### C++

```cpp
using ll = long long;
const int m = 50;
ll cnt[m + 1];
ll s[m + 1];
ll p = 1;

auto init = [] {
    cnt[0] = 0;
    s[0] = 0;
    for (int i = 1; i <= m; ++i) {
        cnt[i] = cnt[i - 1] * 2 + p;
        s[i] = s[i - 1] * 2 + p * (i - 1);
        p *= 2;
    }
    return 0;
}();

pair<ll, ll> numIdxAndSum(ll x) {
    ll idx = 0;
    ll totalSum = 0;
    while (x > 0) {
        int i = 63 - __builtin_clzll(x);
        idx += cnt[i];
        totalSum += s[i];
        x -= 1LL << i;
        totalSum += (x + 1) * i;
        idx += x + 1;
    }
    return make_pair(idx, totalSum);
}

ll f(ll i) {
    ll l = 0;
    ll r = 1LL << m;
    while (l < r) {
        ll mid = (l + r + 1) >> 1;
        auto idxAndSum = numIdxAndSum(mid);
        ll idx = idxAndSum.first;
        if (idx < i) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }

    auto idxAndSum = numIdxAndSum(l);
    ll totalSum = idxAndSum.second;
    ll idx = idxAndSum.first;
    i -= idx;
    ll x = l + 1;
    for (int j = 0; j < i; ++j) {
        ll y = x & -x;
        totalSum += __builtin_ctzll(y);
        x -= y;
    }
    return totalSum;
}

ll qpow(ll a, ll n, ll mod) {
    ll ans = 1 % mod;
    a = a % mod;
    while (n > 0) {
        if (n & 1) {
            ans = ans * a % mod;
        }
        a = a * a % mod;
        n >>= 1;
    }
    return ans;
}

class Solution {
public:
    vector<int> findProductsOfElements(vector<vector<ll>>& queries) {
        int n = queries.size();
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            ll left = queries[i][0];
            ll right = queries[i][1];
            ll mod = queries[i][2];
            ll power = f(right + 1) - f(left);
            if (power < 0) {
                power += mod;
            }
            ans[i] = static_cast<int>(qpow(2, power, mod));
        }
        return ans;
    }
};
```

#### Go

```go
const m = 50

var cnt [m + 1]int64
var s [m + 1]int64
var p int64 = 1

func init() {
	cnt[0] = 0
	s[0] = 0
	for i := 1; i <= m; i++ {
		cnt[i] = cnt[i-1]*2 + p
		s[i] = s[i-1]*2 + p*(int64(i)-1)
		p *= 2
	}
}

func numIdxAndSum(x int64) (int64, int64) {
	var idx, totalSum int64
	for x > 0 {
		i := 63 - bits.LeadingZeros64(uint64(x))
		idx += cnt[i]
		totalSum += s[i]
		x -= 1 << i
		totalSum += (x + 1) * int64(i)
		idx += x + 1
	}
	return idx, totalSum
}

func f(i int64) int64 {
	l, r := int64(0), int64(1)<<m
	for l < r {
		mid := (l + r + 1) >> 1
		idx, _ := numIdxAndSum(mid)
		if idx < i {
			l = mid
		} else {
			r = mid - 1
		}
	}

	_, totalSum := numIdxAndSum(l)
	idx, _ := numIdxAndSum(l)
	i -= idx
	x := l + 1
	for j := int64(0); j < i; j++ {
		y := x & -x
		totalSum += int64(bits.TrailingZeros64(uint64(y)))
		x -= y
	}
	return totalSum
}

func qpow(a, n, mod int64) int64 {
	ans := int64(1) % mod
	a = a % mod
	for n > 0 {
		if n&1 == 1 {
			ans = (ans * a) % mod
		}
		a = (a * a) % mod
		n >>= 1
	}
	return ans
}

func findProductsOfElements(queries [][]int64) []int {
	ans := make([]int, len(queries))
	for i, q := range queries {
		left, right, mod := q[0], q[1], q[2]
		power := f(right+1) - f(left)
		ans[i] = int(qpow(2, power, mod))
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3146. 两个字符串的排列差](https://leetcode.cn/problems/permutation-difference-between-two-strings){#3146}

{{< tabs "3146" >}}

{{% tab "python" %}}
```python
class Solution:
    def findPermutationDifference(self, s: str, t: str) -> int:
        d = {c: i for i, c in enumerate(s)}
        return sum(abs(d[c] - i) for i, c in enumerate(t))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int findPermutationDifference(String s, String t) {
        int[] d = new int[26];
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            d[s.charAt(i) - 'a'] = i;
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += Math.abs(d[t.charAt(i) - 'a'] - i);
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
    int findPermutationDifference(string s, string t) {
        int d[26]{};
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            d[s[i] - 'a'] = i;
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += abs(d[t[i] - 'a'] - i);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findPermutationDifference(s string, t string) (ans int) {
	d := [26]int{}
	for i, c := range s {
		d[c-'a'] = i
	}
	for i, c := range t {
		ans += max(d[c-'a']-i, i-d[c-'a'])
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findPermutationDifference(s: string, t: string): number {
    const d: number[] = Array(26).fill(0);
    const n = s.length;
    for (let i = 0; i < n; ++i) {
        d[s.charCodeAt(i) - 97] = i;
    }
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        ans += Math.abs(d[t.charCodeAt(i) - 97] - i);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int FindPermutationDifference(string s, string t) {
        int[] d = new int[26];
        int n = s.Length;
        for (int i = 0; i < n; ++i) {
            d[s[i] - 'a'] = i;
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += Math.Abs(d[t[i] - 'a'] - i);
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

<p>给你两个字符串 <code>s</code> 和 <code>t</code>，每个字符串中的字符都不重复，且 <code>t</code> 是 <code>s</code> 的一个排列。</p>

<p><strong>排列差</strong> 定义为 <code>s</code> 和 <code>t</code> 中每个字符在两个字符串中位置的绝对差值之和。</p>

<p>返回 <code>s</code> 和 <code>t</code> 之间的<strong> 排列差 </strong>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">s = "abc", t = "bac"</span></p>

<p><strong>输出：</strong><span class="example-io">2</span></p>

<p><strong>解释：</strong></p>

<p>对于 <code>s = "abc"</code> 和 <code>t = "bac"</code>，排列差是：</p>

<ul>
	<li><code>"a"</code> 在 <code>s</code> 中的位置与在 <code>t</code> 中的位置之差的绝对值。</li>
	<li><code>"b"</code> 在 <code>s</code> 中的位置与在 <code>t</code> 中的位置之差的绝对值。</li>
	<li><code>"c"</code> 在 <code>s</code> 中的位置与在 <code>t</code> 中的位置之差的绝对值。</li>
</ul>

<p>即，<code>s</code> 和 <code>t</code> 的排列差等于 <code>|0 - 1| + |1 - 0| + |2&nbsp;- 2| = 2</code>。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">s = "abcde", t = "edbac"</span></p>

<p><strong>输出：</strong><span class="example-io">12</span></p>

<p><strong>解释：</strong> <code>s</code> 和 <code>t</code> 的排列差等于 <code>|0 - 3| + |1 - 2| + |2 - 4| + |3 - 1| + |4 - 0| = 12</code>。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 26</code></li>
	<li>每个字符在 <code>s</code> 中最多出现一次。</li>
	<li><code>t</code> 是 <code>s</code> 的一个排列。</li>
	<li><code>s</code> 仅由小写英文字母组成。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表或数组

我们可以使用哈希表或者一个长度为 $26$ 的数组 $\textit{d}$ 来存储字符串 $\textit{s}$ 中每个字符的位置。

然后遍历字符串 $\textit{t}$，计算每个字符在字符串 $\textit{t}$ 中的位置与在字符串 $\textit{s}$ 中的位置之差的绝对值之和即可。

时间复杂度 $O(n)$，其中 $n$ 为字符串 $\textit{s}$ 的长度。空间复杂度 $O(|\Sigma|)$，其中 $\Sigma$ 为字符集，这里是小写英文字母，所以 $|\Sigma| \leq 26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findPermutationDifference(self, s: str, t: str) -> int:
        d = {c: i for i, c in enumerate(s)}
        return sum(abs(d[c] - i) for i, c in enumerate(t))
```

#### Java

```java
class Solution {
    public int findPermutationDifference(String s, String t) {
        int[] d = new int[26];
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            d[s.charAt(i) - 'a'] = i;
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += Math.abs(d[t.charAt(i) - 'a'] - i);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int findPermutationDifference(string s, string t) {
        int d[26]{};
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            d[s[i] - 'a'] = i;
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += abs(d[t[i] - 'a'] - i);
        }
        return ans;
    }
};
```

#### Go

```go
func findPermutationDifference(s string, t string) (ans int) {
	d := [26]int{}
	for i, c := range s {
		d[c-'a'] = i
	}
	for i, c := range t {
		ans += max(d[c-'a']-i, i-d[c-'a'])
	}
	return
}
```

#### TypeScript

```ts
function findPermutationDifference(s: string, t: string): number {
    const d: number[] = Array(26).fill(0);
    const n = s.length;
    for (let i = 0; i < n; ++i) {
        d[s.charCodeAt(i) - 97] = i;
    }
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        ans += Math.abs(d[t.charCodeAt(i) - 97] - i);
    }
    return ans;
}
```

#### C#

```cs
public class Solution {
    public int FindPermutationDifference(string s, string t) {
        int[] d = new int[26];
        int n = s.Length;
        for (int i = 0; i < n; ++i) {
            d[s[i] - 'a'] = i;
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += Math.Abs(d[t[i] - 'a'] - i);
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

# [3147. 从魔法师身上吸取的最大能量](https://leetcode.cn/problems/taking-maximum-energy-from-the-mystic-dungeon){#3147}

{{< tabs "3147" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumEnergy(self, energy: List[int], k: int) -> int:
        ans = -inf
        n = len(energy)
        for i in range(n - k, n):
            j, s = i, 0
            while j >= 0:
                s += energy[j]
                ans = max(ans, s)
                j -= k
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maximumEnergy(int[] energy, int k) {
        int ans = -(1 << 30);
        int n = energy.length;
        for (int i = n - k; i < n; ++i) {
            for (int j = i, s = 0; j >= 0; j -= k) {
                s += energy[j];
                ans = Math.max(ans, s);
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
    int maximumEnergy(vector<int>& energy, int k) {
        int ans = -(1 << 30);
        int n = energy.size();
        for (int i = n - k; i < n; ++i) {
            for (int j = i, s = 0; j >= 0; j -= k) {
                s += energy[j];
                ans = max(ans, s);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumEnergy(energy []int, k int) int {
	ans := -(1 << 30)
	n := len(energy)
	for i := n - k; i < n; i++ {
		for j, s := i, 0; j >= 0; j -= k {
			s += energy[j]
			ans = max(ans, s)
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumEnergy(energy: number[], k: number): number {
    const n = energy.length;
    let ans = -Infinity;
    for (let i = n - k; i < n; ++i) {
        for (let j = i, s = 0; j >= 0; j -= k) {
            s += energy[j];
            ans = Math.max(ans, s);
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

<p>在神秘的地牢中，<code>n</code> 个魔法师站成一排。每个魔法师都拥有一个属性，这个属性可以给你提供能量。有些魔法师可能会给你负能量，即从你身上吸取能量。</p>

<p>你被施加了一种诅咒，当你从魔法师 <code>i</code> 处吸收能量后，你将被立即传送到魔法师 <code>(i + k)</code> 处。这一过程将重复进行，直到你到达一个不存在 <code>(i + k)</code> 的魔法师为止。</p>

<p>换句话说，你将选择一个起点，然后以 <code>k</code> 为间隔跳跃，直到到达魔法师序列的末端，<strong>在过程中吸收所有的能量</strong>。</p>

<p>给定一个数组 <code>energy</code> 和一个整数<code>k</code>，返回你能获得的<strong> 最大 </strong>能量。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block" style="
    border-color: var(--border-tertiary);
    border-left-width: 2px;
    color: var(--text-secondary);
    font-size: .875rem;
    margin-bottom: 1rem;
    margin-top: 1rem;
    overflow: visible;
    padding-left: 1rem;
">
<p><strong>输入：</strong><span class="example-io" style="
    font-family: Menlo,sans-serif;
    font-size: 0.85rem;
"> energy = [5,2,-10,-5,1], k = 3</span></p>

<p><strong>输出：</strong><span class="example-io" style="
    font-family: Menlo,sans-serif;
    font-size: 0.85rem;
"> 3</span></p>

<p><strong>解释：</strong>可以从魔法师 1 开始，吸收能量 2 + 1 = 3。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block" style="
    border-color: var(--border-tertiary);
    border-left-width: 2px;
    color: var(--text-secondary);
    font-size: .875rem;
    margin-bottom: 1rem;
    margin-top: 1rem;
    overflow: visible;
    padding-left: 1rem;
">
<p><strong>输入：</strong><span class="example-io" style="
    font-family: Menlo,sans-serif;
    font-size: 0.85rem;
"> energy = [-2,-3,-1], k = 2</span></p>

<p><strong>输出：</strong><span class="example-io" style="
    font-family: Menlo,sans-serif;
    font-size: 0.85rem;
"> -1</span></p>

<p><strong>解释：</strong>可以从魔法师 2 开始，吸收能量 -1。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= energy.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-1000 &lt;= energy[i] &lt;= 1000</code></li>
	<li><code>1 &lt;= k &lt;= energy.length - 1</code></li>
</ul>

<p>&nbsp;</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举 + 后缀和

我们可以在 $[n - k, n)$ 的范围内枚举终点，然后从终点开始向前遍历，每次累加间隔为 $k$ 的魔法师的能量值，更新答案。

时间复杂度 $O(n)$，其中 $n$ 是数组 `energy` 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumEnergy(self, energy: List[int], k: int) -> int:
        ans = -inf
        n = len(energy)
        for i in range(n - k, n):
            j, s = i, 0
            while j >= 0:
                s += energy[j]
                ans = max(ans, s)
                j -= k
        return ans
```

#### Java

```java
class Solution {
    public int maximumEnergy(int[] energy, int k) {
        int ans = -(1 << 30);
        int n = energy.length;
        for (int i = n - k; i < n; ++i) {
            for (int j = i, s = 0; j >= 0; j -= k) {
                s += energy[j];
                ans = Math.max(ans, s);
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
    int maximumEnergy(vector<int>& energy, int k) {
        int ans = -(1 << 30);
        int n = energy.size();
        for (int i = n - k; i < n; ++i) {
            for (int j = i, s = 0; j >= 0; j -= k) {
                s += energy[j];
                ans = max(ans, s);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func maximumEnergy(energy []int, k int) int {
	ans := -(1 << 30)
	n := len(energy)
	for i := n - k; i < n; i++ {
		for j, s := i, 0; j >= 0; j -= k {
			s += energy[j]
			ans = max(ans, s)
		}
	}
	return ans
}
```

#### TypeScript

```ts
function maximumEnergy(energy: number[], k: number): number {
    const n = energy.length;
    let ans = -Infinity;
    for (let i = n - k; i < n; ++i) {
        for (let j = i, s = 0; j >= 0; j -= k) {
            s += energy[j];
            ans = Math.max(ans, s);
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

# [3148. 矩阵中的最大得分](https://leetcode.cn/problems/maximum-difference-score-in-a-grid){#3148}

{{< tabs "3148" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxScore(self, grid: List[List[int]]) -> int:
        f = [[0] * len(grid[0]) for _ in range(len(grid))]
        ans = -inf
        for i, row in enumerate(grid):
            for j, x in enumerate(row):
                mi = inf
                if i:
                    mi = min(mi, f[i - 1][j])
                if j:
                    mi = min(mi, f[i][j - 1])
                ans = max(ans, x - mi)
                f[i][j] = min(x, mi)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxScore(List<List<Integer>> grid) {
        int m = grid.size(), n = grid.get(0).size();
        final int inf = 1 << 30;
        int ans = -inf;
        int[][] f = new int[m][n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int mi = inf;
                if (i > 0) {
                    mi = Math.min(mi, f[i - 1][j]);
                }
                if (j > 0) {
                    mi = Math.min(mi, f[i][j - 1]);
                }
                ans = Math.max(ans, grid.get(i).get(j) - mi);
                f[i][j] = Math.min(grid.get(i).get(j), mi);
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
    int maxScore(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        const int inf = 1 << 30;
        int ans = -inf;
        int f[m][n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int mi = inf;
                if (i) {
                    mi = min(mi, f[i - 1][j]);
                }
                if (j) {
                    mi = min(mi, f[i][j - 1]);
                }
                ans = max(ans, grid[i][j] - mi);
                f[i][j] = min(grid[i][j], mi);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxScore(grid [][]int) int {
	m, n := len(grid), len(grid[0])
	f := make([][]int, m)
	for i := range f {
		f[i] = make([]int, n)
	}
	const inf int = 1 << 30
	ans := -inf
	for i, row := range grid {
		for j, x := range row {
			mi := inf
			if i > 0 {
				mi = min(mi, f[i-1][j])
			}
			if j > 0 {
				mi = min(mi, f[i][j-1])
			}
			ans = max(ans, x-mi)
			f[i][j] = min(x, mi)
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxScore(grid: number[][]): number {
    const [m, n] = [grid.length, grid[0].length];
    const f: number[][] = Array.from({ length: m }, () => Array.from({ length: n }, () => 0));
    let ans = -Infinity;
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            let mi = Infinity;
            if (i) {
                mi = Math.min(mi, f[i - 1][j]);
            }
            if (j) {
                mi = Math.min(mi, f[i][j - 1]);
            }
            ans = Math.max(ans, grid[i][j] - mi);
            f[i][j] = Math.min(mi, grid[i][j]);
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

<p>给你一个由 <strong>正整数</strong> 组成、大小为 <code>m x n</code> 的矩阵 <code>grid</code>。你可以从矩阵中的任一单元格移动到另一个位于正下方或正右侧的任意单元格（不必相邻）。从值为 <code>c1</code> 的单元格移动到值为 <code>c2</code> 的单元格的得分为 <code>c2 - c1</code> 。</p>

<p>你可以从<strong> 任一</strong> 单元格开始，并且必须至少移动一次。</p>

<p>返回你能得到的 <strong>最大 </strong>总得分。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3100-3199/3148.Maximum%20Difference%20Score%20in%20a%20Grid/images/grid1.png" style="width: 240px; height: 240px;" />
<div class="example-block">
<p><strong>输入：</strong><span class="example-io">grid = [[9,5,7,3],[8,9,6,1],[6,7,14,3],[2,5,3,1]]</span></p>

<p><strong>输出：</strong><span class="example-io">9</span></p>

<p><strong>解释：</strong>从单元格 <code>(0, 1)</code> 开始，并执行以下移动：<br />
- 从单元格 <code>(0, 1)</code> 移动到 <code>(2, 1)</code>，得分为 <code>7 - 5 = 2</code> 。<br />
- 从单元格 <code>(2, 1)</code> 移动到 <code>(2, 2)</code>，得分为 <code>14 - 7 = 7</code> 。<br />
总得分为 <code>2 + 7 = 9</code> 。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3100-3199/3148.Maximum%20Difference%20Score%20in%20a%20Grid/images/moregridsdrawio-1.png" style="width: 180px; height: 116px;" /></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">grid = [[4,3,2],[3,2,1]]</span></p>

<p><strong>输出：</strong><span class="example-io">-1</span></p>

<p><strong>解释：</strong>从单元格 <code>(0, 0)</code> 开始，执行一次移动：从 <code>(0, 0)</code> 到 <code>(0, 1)</code> 。得分为 <code>3 - 4 = -1</code> 。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>2 &lt;= m, n &lt;= 1000</code></li>
	<li><code>4 &lt;= m * n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= grid[i][j] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

根据题目描述，如果我们经过的单元格的值依次是 $c_1, c_2, \cdots, c_k$，那么我们的得分就是 $c_2 - c_1 + c_3 - c_2 + \cdots + c_k - c_{k-1} = c_k - c_1$。因此，问题转化为：对于矩阵的每个单元格 $(i, j)$，如果我们将其作为终点，那么起点的最小值是多少。

我们可以使用动态规划来解决这个问题。我们定义 $f[i][j]$ 表示以 $(i, j)$ 为终点的路径的最小值。那么我们可以得到状态转移方程：

$$
f[i][j] = \min(f[i-1][j], f[i][j-1], grid[i][j])
$$

那么答案为 $\textit{grid}[i][j] - \min(f[i-1][j], f[i][j-1])$ 的最大值。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别是矩阵的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxScore(self, grid: List[List[int]]) -> int:
        f = [[0] * len(grid[0]) for _ in range(len(grid))]
        ans = -inf
        for i, row in enumerate(grid):
            for j, x in enumerate(row):
                mi = inf
                if i:
                    mi = min(mi, f[i - 1][j])
                if j:
                    mi = min(mi, f[i][j - 1])
                ans = max(ans, x - mi)
                f[i][j] = min(x, mi)
        return ans
```

#### Java

```java
class Solution {
    public int maxScore(List<List<Integer>> grid) {
        int m = grid.size(), n = grid.get(0).size();
        final int inf = 1 << 30;
        int ans = -inf;
        int[][] f = new int[m][n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int mi = inf;
                if (i > 0) {
                    mi = Math.min(mi, f[i - 1][j]);
                }
                if (j > 0) {
                    mi = Math.min(mi, f[i][j - 1]);
                }
                ans = Math.max(ans, grid.get(i).get(j) - mi);
                f[i][j] = Math.min(grid.get(i).get(j), mi);
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
    int maxScore(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        const int inf = 1 << 30;
        int ans = -inf;
        int f[m][n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int mi = inf;
                if (i) {
                    mi = min(mi, f[i - 1][j]);
                }
                if (j) {
                    mi = min(mi, f[i][j - 1]);
                }
                ans = max(ans, grid[i][j] - mi);
                f[i][j] = min(grid[i][j], mi);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func maxScore(grid [][]int) int {
	m, n := len(grid), len(grid[0])
	f := make([][]int, m)
	for i := range f {
		f[i] = make([]int, n)
	}
	const inf int = 1 << 30
	ans := -inf
	for i, row := range grid {
		for j, x := range row {
			mi := inf
			if i > 0 {
				mi = min(mi, f[i-1][j])
			}
			if j > 0 {
				mi = min(mi, f[i][j-1])
			}
			ans = max(ans, x-mi)
			f[i][j] = min(x, mi)
		}
	}
	return ans
}
```

#### TypeScript

```ts
function maxScore(grid: number[][]): number {
    const [m, n] = [grid.length, grid[0].length];
    const f: number[][] = Array.from({ length: m }, () => Array.from({ length: n }, () => 0));
    let ans = -Infinity;
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            let mi = Infinity;
            if (i) {
                mi = Math.min(mi, f[i - 1][j]);
            }
            if (j) {
                mi = Math.min(mi, f[i][j - 1]);
            }
            ans = Math.max(ans, grid[i][j] - mi);
            f[i][j] = Math.min(mi, grid[i][j]);
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

# [3149. 找出分数最低的排列](https://leetcode.cn/problems/find-the-minimum-cost-array-permutation){#3149}

{{< tabs "3149" >}}

{{% tab "python" %}}
```python
class Solution:
    def findPermutation(self, nums: List[int]) -> List[int]:
        @cache
        def dfs(mask: int, pre: int) -> int:
            if mask == (1 << n) - 1:
                return abs(pre - nums[0])
            res = inf
            for cur in range(1, n):
                if mask >> cur & 1 ^ 1:
                    res = min(res, abs(pre - nums[cur]) + dfs(mask | 1 << cur, cur))
            return res

        def g(mask: int, pre: int):
            ans.append(pre)
            if mask == (1 << n) - 1:
                return
            res = dfs(mask, pre)
            for cur in range(1, n):
                if mask >> cur & 1 ^ 1:
                    if abs(pre - nums[cur]) + dfs(mask | 1 << cur, cur) == res:
                        g(mask | 1 << cur, cur)
                        break

        n = len(nums)
        ans = []
        g(1, 0)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private Integer[][] f;
    private int[] nums;
    private int[] ans;
    private int n;

    public int[] findPermutation(int[] nums) {
        n = nums.length;
        ans = new int[n];
        this.nums = nums;
        f = new Integer[1 << n][n];
        g(1, 0, 0);
        return ans;
    }

    private int dfs(int mask, int pre) {
        if (mask == (1 << n) - 1) {
            return Math.abs(pre - nums[0]);
        }
        if (f[mask][pre] != null) {
            return f[mask][pre];
        }
        int res = Integer.MAX_VALUE;
        for (int cur = 1; cur < n; ++cur) {
            if ((mask >> cur & 1) == 0) {
                res = Math.min(res, Math.abs(pre - nums[cur]) + dfs(mask | 1 << cur, cur));
            }
        }
        return f[mask][pre] = res;
    }

    private void g(int mask, int pre, int k) {
        ans[k] = pre;
        if (mask == (1 << n) - 1) {
            return;
        }
        int res = dfs(mask, pre);
        for (int cur = 1; cur < n; ++cur) {
            if ((mask >> cur & 1) == 0) {
                if (Math.abs(pre - nums[cur]) + dfs(mask | 1 << cur, cur) == res) {
                    g(mask | 1 << cur, cur, k + 1);
                    break;
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
    vector<int> findPermutation(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        int f[1 << n][n];
        memset(f, -1, sizeof(f));
        function<int(int, int)> dfs = [&](int mask, int pre) {
            if (mask == (1 << n) - 1) {
                return abs(pre - nums[0]);
            }
            int* res = &f[mask][pre];
            if (*res != -1) {
                return *res;
            }
            *res = INT_MAX;
            for (int cur = 1; cur < n; ++cur) {
                if (mask >> cur & 1 ^ 1) {
                    *res = min(*res, abs(pre - nums[cur]) + dfs(mask | 1 << cur, cur));
                }
            }
            return *res;
        };
        function<void(int, int)> g = [&](int mask, int pre) {
            ans.push_back(pre);
            if (mask == (1 << n) - 1) {
                return;
            }
            int res = dfs(mask, pre);
            for (int cur = 1; cur < n; ++cur) {
                if (mask >> cur & 1 ^ 1) {
                    if (abs(pre - nums[cur]) + dfs(mask | 1 << cur, cur) == res) {
                        g(mask | 1 << cur, cur);
                        break;
                    }
                }
            }
        };
        g(1, 0);
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findPermutation(nums []int) (ans []int) {
	n := len(nums)
	f := make([][]int, 1<<n)
	for i := range f {
		f[i] = make([]int, n)
		for j := range f[i] {
			f[i][j] = -1
		}
	}
	var dfs func(int, int) int
	dfs = func(mask, pre int) int {
		if mask == 1<<n-1 {
			return abs(pre - nums[0])
		}
		if f[mask][pre] != -1 {
			return f[mask][pre]
		}
		res := &f[mask][pre]
		*res = math.MaxInt32
		for cur := 1; cur < n; cur++ {
			if mask>>cur&1 == 0 {
				*res = min(*res, abs(pre-nums[cur])+dfs(mask|1<<cur, cur))
			}
		}
		return *res
	}
	var g func(int, int)
	g = func(mask, pre int) {
		ans = append(ans, pre)
		if mask == 1<<n-1 {
			return
		}
		res := dfs(mask, pre)
		for cur := 1; cur < n; cur++ {
			if mask>>cur&1 == 0 {
				if abs(pre-nums[cur])+dfs(mask|1<<cur, cur) == res {
					g(mask|1<<cur, cur)
					break
				}
			}
		}
	}
	g(1, 0)
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
function findPermutation(nums: number[]): number[] {
    const n = nums.length;
    const ans: number[] = [];
    const f: number[][] = Array.from({ length: 1 << n }, () => Array(n).fill(-1));
    const dfs = (mask: number, pre: number): number => {
        if (mask === (1 << n) - 1) {
            return Math.abs(pre - nums[0]);
        }
        if (f[mask][pre] !== -1) {
            return f[mask][pre];
        }
        let res = Infinity;
        for (let cur = 1; cur < n; ++cur) {
            if (((mask >> cur) & 1) ^ 1) {
                res = Math.min(res, Math.abs(pre - nums[cur]) + dfs(mask | (1 << cur), cur));
            }
        }
        return (f[mask][pre] = res);
    };
    const g = (mask: number, pre: number) => {
        ans.push(pre);
        if (mask === (1 << n) - 1) {
            return;
        }
        const res = dfs(mask, pre);
        for (let cur = 1; cur < n; ++cur) {
            if (((mask >> cur) & 1) ^ 1) {
                if (Math.abs(pre - nums[cur]) + dfs(mask | (1 << cur), cur) === res) {
                    g(mask | (1 << cur), cur);
                    break;
                }
            }
        }
    };
    g(1, 0);
    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个数组 <code>nums</code> ，它是 <code>[0, 1, 2, ..., n - 1]</code> 的一个<span data-keyword="permutation">排列</span> 。对于任意一个 <code>[0, 1, 2, ..., n - 1]</code> 的排列 <code>perm</code> ，其 <strong>分数 </strong>定义为：</p>

<p><code>score(perm) = |perm[0] - nums[perm[1]]| + |perm[1] - nums[perm[2]]| + ... + |perm[n - 1] - nums[perm[0]]|</code></p>

<p>返回具有<strong> 最低</strong> 分数的排列 <code>perm</code> 。如果存在多个满足题意且分数相等的排列，则返回其中<span data-keyword="lexicographically-smaller-array">字典序最小</span>的一个。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">nums = [1,0,2]</span></p>

<p><strong>输出：</strong><span class="example-io">[0,1,2]</span></p>

<p><strong>解释：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3100-3199/3149.Find%20the%20Minimum%20Cost%20Array%20Permutation/images/example0gif.gif" style="width: 235px; height: 235px;" /></strong></p>

<p>字典序最小且分数最低的排列是 <code>[0,1,2]</code>。这个排列的分数是 <code>|0 - 0| + |1 - 2| + |2 - 1| = 2</code> 。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">nums = [0,2,1]</span></p>

<p><strong>输出：</strong><span class="example-io">[0,2,1]</span></p>

<p><strong>解释：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3100-3199/3149.Find%20the%20Minimum%20Cost%20Array%20Permutation/images/example1gif.gif" style="width: 235px; height: 235px;" /></strong></p>

<p>字典序最小且分数最低的排列是 <code>[0,2,1]</code>。这个排列的分数是 <code>|0 - 1| + |2 - 2| + |1 - 0| = 2</code> 。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n == nums.length &lt;= 14</code></li>
	<li><code>nums</code> 是 <code>[0, 1, 2, ..., n - 1]</code> 的一个排列。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

我们注意到，对于任意一个排列 $\textit{perm}$，把它循环向左移动任意次，得到的排列分数依然是相同的。由于题目要求返回字典序最小的排列，因此我们可以确定排列的第一个元素一定是 $0$。

另外，由于题目的数据范围不超过 $14$，我们可以考虑使用状态压缩的方法，来表示当前排列选取的数字集合。我们用一个长度为 $n$ 的二进制数 $\textit{mask}$ 来表示当前排列选取的数字集合，其中 $\textit{mask}$ 的第 $i$ 位为 $1$ 表示数字 $i$ 已经被选取，为 $0$ 表示数字 $i$ 还未被选取。

我们设计一个函数 $\textit{dfs}(\textit{mask}, \textit{pre})$，表示当前排列选取的数字集合为 $\textit{mask}$，且最后一个选取的数字为 $\textit{pre}$ 时，得到的排列的最小分数。初始时我们将数字 $0$ 加入到排列中。

函数 $\textit{dfs}(\textit{mask}, \textit{pre})$ 的计算过程如下：

-   如果 $\textit{mask}$ 的二进制表示中 $1$ 的个数为 $n$，即 $\textit{mask} = 2^n - 1$，表示所有数字都已经被选取，此时返回 $|\textit{pre} - \textit{nums}[0]|$；
-   否则，我们枚举下一个选取的数字 $\textit{cur}$，如果数字 $\textit{cur}$ 还未被选取，那么我们可以将数字 $\textit{cur}$ 加入到排列中，此时排列的分数为 $|\textit{pre} - \textit{nums}[\textit{cur}]| + \textit{dfs}(\textit{mask} \, | \, 1 << \textit{cur}, \textit{cur})$，我们需要取所有 $\textit{cur}$ 中分数的最小值。

最后，我们利用一个函数 $\textit{g}(\textit{mask}, \textit{pre})$ 来构造得到最小分数的排列。我们首先将数字 $\textit{pre}$ 加入到排列中，然后枚举下一个选取的数字 $\textit{cur}$，如果数字 $\textit{cur}$ 还未被选取，且满足 $|\textit{pre} - \textit{nums}[\textit{cur}]| + \textit{dfs}(\textit{mask} \, | \, 1 << \textit{cur}, \textit{cur})$ 的值等于 $\textit{dfs}(\textit{mask}, \textit{pre})$，那么我们就可以将数字 $\textit{cur}$ 加入到排列中。

时间复杂度 $(n^2 \times 2^n)$，空间复杂度 $O(n \times 2^n)$。其中 $n$ 为数组 $\textit{nums}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findPermutation(self, nums: List[int]) -> List[int]:
        @cache
        def dfs(mask: int, pre: int) -> int:
            if mask == (1 << n) - 1:
                return abs(pre - nums[0])
            res = inf
            for cur in range(1, n):
                if mask >> cur & 1 ^ 1:
                    res = min(res, abs(pre - nums[cur]) + dfs(mask | 1 << cur, cur))
            return res

        def g(mask: int, pre: int):
            ans.append(pre)
            if mask == (1 << n) - 1:
                return
            res = dfs(mask, pre)
            for cur in range(1, n):
                if mask >> cur & 1 ^ 1:
                    if abs(pre - nums[cur]) + dfs(mask | 1 << cur, cur) == res:
                        g(mask | 1 << cur, cur)
                        break

        n = len(nums)
        ans = []
        g(1, 0)
        return ans
```

#### Java

```java
class Solution {
    private Integer[][] f;
    private int[] nums;
    private int[] ans;
    private int n;

    public int[] findPermutation(int[] nums) {
        n = nums.length;
        ans = new int[n];
        this.nums = nums;
        f = new Integer[1 << n][n];
        g(1, 0, 0);
        return ans;
    }

    private int dfs(int mask, int pre) {
        if (mask == (1 << n) - 1) {
            return Math.abs(pre - nums[0]);
        }
        if (f[mask][pre] != null) {
            return f[mask][pre];
        }
        int res = Integer.MAX_VALUE;
        for (int cur = 1; cur < n; ++cur) {
            if ((mask >> cur & 1) == 0) {
                res = Math.min(res, Math.abs(pre - nums[cur]) + dfs(mask | 1 << cur, cur));
            }
        }
        return f[mask][pre] = res;
    }

    private void g(int mask, int pre, int k) {
        ans[k] = pre;
        if (mask == (1 << n) - 1) {
            return;
        }
        int res = dfs(mask, pre);
        for (int cur = 1; cur < n; ++cur) {
            if ((mask >> cur & 1) == 0) {
                if (Math.abs(pre - nums[cur]) + dfs(mask | 1 << cur, cur) == res) {
                    g(mask | 1 << cur, cur, k + 1);
                    break;
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
    vector<int> findPermutation(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        int f[1 << n][n];
        memset(f, -1, sizeof(f));
        function<int(int, int)> dfs = [&](int mask, int pre) {
            if (mask == (1 << n) - 1) {
                return abs(pre - nums[0]);
            }
            int* res = &f[mask][pre];
            if (*res != -1) {
                return *res;
            }
            *res = INT_MAX;
            for (int cur = 1; cur < n; ++cur) {
                if (mask >> cur & 1 ^ 1) {
                    *res = min(*res, abs(pre - nums[cur]) + dfs(mask | 1 << cur, cur));
                }
            }
            return *res;
        };
        function<void(int, int)> g = [&](int mask, int pre) {
            ans.push_back(pre);
            if (mask == (1 << n) - 1) {
                return;
            }
            int res = dfs(mask, pre);
            for (int cur = 1; cur < n; ++cur) {
                if (mask >> cur & 1 ^ 1) {
                    if (abs(pre - nums[cur]) + dfs(mask | 1 << cur, cur) == res) {
                        g(mask | 1 << cur, cur);
                        break;
                    }
                }
            }
        };
        g(1, 0);
        return ans;
    }
};
```

#### Go

```go
func findPermutation(nums []int) (ans []int) {
	n := len(nums)
	f := make([][]int, 1<<n)
	for i := range f {
		f[i] = make([]int, n)
		for j := range f[i] {
			f[i][j] = -1
		}
	}
	var dfs func(int, int) int
	dfs = func(mask, pre int) int {
		if mask == 1<<n-1 {
			return abs(pre - nums[0])
		}
		if f[mask][pre] != -1 {
			return f[mask][pre]
		}
		res := &f[mask][pre]
		*res = math.MaxInt32
		for cur := 1; cur < n; cur++ {
			if mask>>cur&1 == 0 {
				*res = min(*res, abs(pre-nums[cur])+dfs(mask|1<<cur, cur))
			}
		}
		return *res
	}
	var g func(int, int)
	g = func(mask, pre int) {
		ans = append(ans, pre)
		if mask == 1<<n-1 {
			return
		}
		res := dfs(mask, pre)
		for cur := 1; cur < n; cur++ {
			if mask>>cur&1 == 0 {
				if abs(pre-nums[cur])+dfs(mask|1<<cur, cur) == res {
					g(mask|1<<cur, cur)
					break
				}
			}
		}
	}
	g(1, 0)
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
function findPermutation(nums: number[]): number[] {
    const n = nums.length;
    const ans: number[] = [];
    const f: number[][] = Array.from({ length: 1 << n }, () => Array(n).fill(-1));
    const dfs = (mask: number, pre: number): number => {
        if (mask === (1 << n) - 1) {
            return Math.abs(pre - nums[0]);
        }
        if (f[mask][pre] !== -1) {
            return f[mask][pre];
        }
        let res = Infinity;
        for (let cur = 1; cur < n; ++cur) {
            if (((mask >> cur) & 1) ^ 1) {
                res = Math.min(res, Math.abs(pre - nums[cur]) + dfs(mask | (1 << cur), cur));
            }
        }
        return (f[mask][pre] = res);
    };
    const g = (mask: number, pre: number) => {
        ans.push(pre);
        if (mask === (1 << n) - 1) {
            return;
        }
        const res = dfs(mask, pre);
        for (let cur = 1; cur < n; ++cur) {
            if (((mask >> cur) & 1) ^ 1) {
                if (Math.abs(pre - nums[cur]) + dfs(mask | (1 << cur), cur) === res) {
                    g(mask | (1 << cur), cur);
                    break;
                }
            }
        }
    };
    g(1, 0);
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
