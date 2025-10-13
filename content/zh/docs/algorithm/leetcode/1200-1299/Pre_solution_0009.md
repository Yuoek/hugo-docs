---
title: "1280_学生们参加各科测试的次数"
date: 2025-10-08T18:37:06+08:00
weight: 9
tags: [二分查找, 位运算, 动态规划, 哈希表, 回溯, 字符串, 广度优先搜索, 排序, 数学, 数据库, 数组, 矩阵, 设计, 贪心, 迭代器]
---

{{< markmap >}}
### [1280_学生们参加各科测试的次数](#1280)
#### [数据库](#1280)
### [1281_整数的各位积和之差](#1281)
#### [数学](#1281)
### [1282_用户分组](#1282)
#### [贪心](#1282)
#### [数组](#1282)
#### [哈希表](#1282)
### [1283_使结果不超过阈值的最小除数](#1283)
#### [数组](#1283)
#### [二分查找](#1283)
### [1284_转化为全零矩阵的最少反转次数](#1284)
#### [位运算](#1284)
#### [广度优先搜索](#1284)
#### [数组](#1284)
#### [哈希表](#1284)
#### [矩阵](#1284)
### [1285_找到连续区间的开始和结束数字 🔒](#1285)
#### [数据库](#1285)
### [1286_字母组合迭代器](#1286)
#### [设计](#1286)
#### [字符串](#1286)
#### [回溯](#1286)
#### [迭代器](#1286)
### [1287_有序数组中出现次数超过25%的元素](#1287)
#### [数组](#1287)
### [1288_删除被覆盖区间](#1288)
#### [数组](#1288)
#### [排序](#1288)
### [1289_下降路径最小和 II](#1289)
#### [数组](#1289)
#### [动态规划](#1289)
#### [矩阵](#1289)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1280_学生们参加各科测试的次数
___
#### 数据库
---
### 1281_整数的各位积和之差
___
#### 数学
---
### 1282_用户分组
___
#### 贪心
___
#### 数组
___
#### 哈希表
---
### 1283_使结果不超过阈值的最小除数
___
#### 数组
___
#### 二分查找
---
### 1284_转化为全零矩阵的最少反转次数
___
#### 位运算
___
#### 广度优先搜索
___
#### 数组
___
#### 哈希表
___
#### 矩阵
---
### 1285_找到连续区间的开始和结束数字 🔒
___
#### 数据库
---
### 1286_字母组合迭代器
___
#### 设计
___
#### 字符串
___
#### 回溯
___
#### 迭代器
---
### 1287_有序数组中出现次数超过25%的元素
___
#### 数组
---
### 1288_删除被覆盖区间
___
#### 数组
___
#### 排序
---
### 1289_下降路径最小和 II
___
#### 数组
___
#### 动态规划
___
#### 矩阵
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 位运算 | 动态规划 |
| 哈希表 | 回溯 | 字符串 |
| 广度优先搜索 | 排序 | 数学 |
| 数据库 | 数组 | 矩阵 |
| 设计 | 贪心 | 迭代器 |

# [1280. 学生们参加各科测试的次数](https://leetcode.cn/problems/students-and-examinations){#1280}

{{< tabs "1280" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT student_id, student_name, subject_name, COUNT(e.student_id) AS attended_exams
FROM
    Students
    JOIN Subjects
    LEFT JOIN Examinations AS e USING (student_id, subject_name)
GROUP BY 1, 3
ORDER BY 1, 3;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>学生表: <code>Students</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| student_id    | int     |
| student_name  | varchar |
+---------------+---------+
在 SQL 中，主键为 student_id（学生ID）。
该表内的每一行都记录有学校一名学生的信息。
</pre>

<p>&nbsp;</p>

<p>科目表: <code>Subjects</code></p>

<pre>
+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| subject_name | varchar |
+--------------+---------+
在 SQL 中，主键为 subject_name（科目名称）。
每一行记录学校的一门科目名称。
</pre>

<p>&nbsp;</p>

<p>考试表: <code>Examinations</code></p>

<pre>
+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| student_id   | int     |
| subject_name | varchar |
+--------------+---------+
这个表可能包含重复数据（换句话说，在 SQL 中，这个表没有主键）。
学生表里的一个学生修读科目表里的每一门科目。
这张考试表的每一行记录就表示学生表里的某个学生参加了一次科目表里某门科目的测试。
</pre>

<p>&nbsp;</p>

<p>查询出每个学生参加每一门科目测试的次数，结果按 <code>student_id</code> 和 <code>subject_name</code> 排序。</p>

<p>查询结构格式如下所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
Students table:
+------------+--------------+
| student_id | student_name |
+------------+--------------+
| 1          | Alice        |
| 2          | Bob          |
| 13         | John         |
| 6          | Alex         |
+------------+--------------+
Subjects table:
+--------------+
| subject_name |
+--------------+
| Math         |
| Physics      |
| Programming  |
+--------------+
Examinations table:
+------------+--------------+
| student_id | subject_name |
+------------+--------------+
| 1          | Math         |
| 1          | Physics      |
| 1          | Programming  |
| 2          | Programming  |
| 1          | Physics      |
| 1          | Math         |
| 13         | Math         |
| 13         | Programming  |
| 13         | Physics      |
| 2          | Math         |
| 1          | Math         |
+------------+--------------+
<strong>输出：</strong>
+------------+--------------+--------------+----------------+
| student_id | student_name | subject_name | attended_exams |
+------------+--------------+--------------+----------------+
| 1          | Alice        | Math         | 3              |
| 1          | Alice        | Physics      | 2              |
| 1          | Alice        | Programming  | 1              |
| 2          | Bob          | Math         | 1              |
| 2          | Bob          | Physics      | 0              |
| 2          | Bob          | Programming  | 1              |
| 6          | Alex         | Math         | 0              |
| 6          | Alex         | Physics      | 0              |
| 6          | Alex         | Programming  | 0              |
| 13         | John         | Math         | 1              |
| 13         | John         | Physics      | 1              |
| 13         | John         | Programming  | 1              |
+------------+--------------+--------------+----------------+
<strong>解释：</strong>
结果表需包含所有学生和所有科目（即便测试次数为0）：
Alice 参加了 3 次数学测试, 2 次物理测试，以及 1 次编程测试；
Bob 参加了 1 次数学测试, 1 次编程测试，没有参加物理测试；
Alex 啥测试都没参加；
John  参加了数学、物理、编程测试各 1 次。
</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：两次连接 + 分组统计

我们可以先连接 `Students` 表和 `Subjects` 表，得到所有学生和所有科目的组合，然后再连接 `Examinations` 表，连接条件为 `student_id` 和 `subject_name`，这样就得到了每个学生参加每一门科目测试的次数，最后按 `student_id` 和 `subject_name` 分组统计即可。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT student_id, student_name, subject_name, COUNT(e.student_id) AS attended_exams
FROM
    Students
    JOIN Subjects
    LEFT JOIN Examinations AS e USING (student_id, subject_name)
GROUP BY 1, 3
ORDER BY 1, 3;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1281. 整数的各位积和之差](https://leetcode.cn/problems/subtract-the-product-and-sum-of-digits-of-an-integer){#1281}

{{< tabs "1281" >}}

{{% tab "python" %}}
```python
class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        nums = list(map(int, str(n)))
        return prod(nums) - sum(nums)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int subtractProductAndSum(int n) {
        int x = 1, y = 0;
        for (; n > 0; n /= 10) {
            int v = n % 10;
            x *= v;
            y += v;
        }
        return x - y;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int subtractProductAndSum(int n) {
        int x = 1, y = 0;
        for (; n; n /= 10) {
            int v = n % 10;
            x *= v;
            y += v;
        }
        return x - y;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func subtractProductAndSum(n int) int {
	x, y := 1, 0
	for ; n > 0; n /= 10 {
		v := n % 10
		x *= v
		y += v
	}
	return x - y
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function subtractProductAndSum(n: number): number {
    let [x, y] = [1, 0];
    for (; n > 0; n = Math.floor(n / 10)) {
        const v = n % 10;
        x *= v;
        y += v;
    }
    return x - y;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn subtract_product_and_sum(mut n: i32) -> i32 {
        let mut x = 1;
        let mut y = 0;
        while n != 0 {
            let v = n % 10;
            n /= 10;
            x *= v;
            y += v;
        }
        x - y
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int SubtractProductAndSum(int n) {
        int x = 1;
        int y = 0;
        for (; n > 0; n /= 10) {
            int v = n % 10;
            x *= v;
            y += v;
        }
        return x - y;
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
int subtractProductAndSum(int n) {
    int x = 1;
    int y = 0;
    for (; n > 0; n /= 10) {
        int v = n % 10;
        x *= v;
        y += v;
    }
    return x - y;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数&nbsp;<code>n</code>，请你帮忙计算并返回该整数「各位数字之积」与「各位数字之和」的差。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>n = 234
<strong>输出：</strong>15 
<strong>解释：</strong>
各位数之积 = 2 * 3 * 4 = 24 
各位数之和 = 2 + 3 + 4 = 9 
结果 = 24 - 9 = 15
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>n = 4421
<strong>输出：</strong>21
<strong>解释： 
</strong>各位数之积 = 4 * 4 * 2 * 1 = 32 
各位数之和 = 4 + 4 + 2 + 1 = 11 
结果 = 32 - 11 = 21
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10^5</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们用两个变量 $x$ 和 $y$ 分别记录各位数之积、各位数之和，初始时 $x=1,y=0$。

当 $n \gt 0$ 时，每次将 $n$ 对 $10$ 取模得到当前位的数字 $v$，并将 $n$ 除以 $10$ 后继续进行下一次循环。在每次循环中，我们更新 $x = x \times v$, $y = y + v$。

最终，我们返回 $x - y$ 即可。

时间复杂度 $O(\log n)$，其中 $n$ 是题目给定的整数。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        nums = list(map(int, str(n)))
        return prod(nums) - sum(nums)
```

#### Java

```java
class Solution {
    public int subtractProductAndSum(int n) {
        int x = 1, y = 0;
        for (; n > 0; n /= 10) {
            int v = n % 10;
            x *= v;
            y += v;
        }
        return x - y;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int subtractProductAndSum(int n) {
        int x = 1, y = 0;
        for (; n; n /= 10) {
            int v = n % 10;
            x *= v;
            y += v;
        }
        return x - y;
    }
};
```

#### Go

```go
func subtractProductAndSum(n int) int {
	x, y := 1, 0
	for ; n > 0; n /= 10 {
		v := n % 10
		x *= v
		y += v
	}
	return x - y
}
```

#### TypeScript

```ts
function subtractProductAndSum(n: number): number {
    let [x, y] = [1, 0];
    for (; n > 0; n = Math.floor(n / 10)) {
        const v = n % 10;
        x *= v;
        y += v;
    }
    return x - y;
}
```

#### Rust

```rust
impl Solution {
    pub fn subtract_product_and_sum(mut n: i32) -> i32 {
        let mut x = 1;
        let mut y = 0;
        while n != 0 {
            let v = n % 10;
            n /= 10;
            x *= v;
            y += v;
        }
        x - y
    }
}
```

#### C#

```cs
public class Solution {
    public int SubtractProductAndSum(int n) {
        int x = 1;
        int y = 0;
        for (; n > 0; n /= 10) {
            int v = n % 10;
            x *= v;
            y += v;
        }
        return x - y;
    }
}
```

#### C

```c
int subtractProductAndSum(int n) {
    int x = 1;
    int y = 0;
    for (; n > 0; n /= 10) {
        int v = n % 10;
        x *= v;
        y += v;
    }
    return x - y;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1282. 用户分组](https://leetcode.cn/problems/group-the-people-given-the-group-size-they-belong-to){#1282}

{{< tabs "1282" >}}

{{% tab "python" %}}
```python
class Solution:
    def groupThePeople(self, groupSizes: List[int]) -> List[List[int]]:
        g = defaultdict(list)
        for i, v in enumerate(groupSizes):
            g[v].append(i)
        return [v[j : j + i] for i, v in g.items() for j in range(0, len(v), i)]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<List<Integer>> groupThePeople(int[] groupSizes) {
        int n = groupSizes.length;
        List<Integer>[] g = new List[n + 1];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (int i = 0; i < n; ++i) {
            g[groupSizes[i]].add(i);
        }
        List<List<Integer>> ans = new ArrayList<>();
        for (int i = 0; i < g.length; ++i) {
            List<Integer> v = g[i];
            for (int j = 0; j < v.size(); j += i) {
                ans.add(v.subList(j, j + i));
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
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        vector<vector<int>> g(n + 1);
        for (int i = 0; i < n; ++i) {
            g[groupSizes[i]].push_back(i);
        }
        vector<vector<int>> ans;
        for (int i = 0; i < g.size(); ++i) {
            for (int j = 0; j < g[i].size(); j += i) {
                vector<int> t(g[i].begin() + j, g[i].begin() + j + i);
                ans.push_back(t);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func groupThePeople(groupSizes []int) [][]int {
	n := len(groupSizes)
	g := make([][]int, n+1)
	for i, v := range groupSizes {
		g[v] = append(g[v], i)
	}
	ans := [][]int{}
	for i, v := range g {
		for j := 0; j < len(v); j += i {
			ans = append(ans, v[j:j+i])
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function groupThePeople(groupSizes: number[]): number[][] {
    const n: number = groupSizes.length;
    const g: number[][] = Array.from({ length: n + 1 }, () => []);

    for (let i = 0; i < groupSizes.length; i++) {
        const size: number = groupSizes[i];
        g[size].push(i);
    }
    const ans: number[][] = [];
    for (let i = 1; i <= n; i++) {
        const group: number[] = [];
        for (let j = 0; j < g[i].length; j += i) {
            group.push(...g[i].slice(j, j + i));
            ans.push([...group]);
            group.length = 0;
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn group_the_people(group_sizes: Vec<i32>) -> Vec<Vec<i32>> {
        let n: usize = group_sizes.len();
        let mut g: Vec<Vec<usize>> = vec![Vec::new(); n + 1];

        for (i, &size) in group_sizes.iter().enumerate() {
            g[size as usize].push(i);
        }

        let mut ans: Vec<Vec<i32>> = Vec::new();
        for (i, v) in g.into_iter().enumerate() {
            for j in (0..v.len()).step_by(i.max(1)) {
                ans.push(
                    v[j..(j + i).min(v.len())]
                        .iter()
                        .map(|&x| x as i32)
                        .collect(),
                );
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

<p>有&nbsp;<code>n</code>&nbsp;个人被分成数量未知的组。每个人都被标记为一个从 <code>0</code> 到 <code>n - 1</code> 的<strong>唯一ID</strong>&nbsp;。</p>

<p>给定一个整数数组 <code>groupSizes</code> ，其中<meta charset="UTF-8" />&nbsp;<code>groupSizes[i]</code>&nbsp;是第 <code>i</code> 个人所在的组的大小。例如，如果&nbsp;<code>groupSizes[1] = 3</code>&nbsp;，则第 <code>1</code> 个人必须位于大小为 <code>3</code> 的组中。</p>

<p>返回一个组列表，使每个人 <code>i</code> 都在一个大小为<meta charset="UTF-8" /><em>&nbsp;<code>groupSizes[i]</code>&nbsp;</em>的组中。</p>

<p>每个人应该&nbsp;<strong>恰好只&nbsp;</strong>出现在&nbsp;<strong>一个组&nbsp;</strong>中，并且每个人必须在一个组中。如果有多个答案，返回其中&nbsp;<strong>任何&nbsp;</strong>一个。可以&nbsp;<strong>保证&nbsp;</strong>给定输入&nbsp;<strong>至少有一个&nbsp;</strong>有效的解。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>groupSizes = [3,3,3,3,3,1,3]
<strong>输出：</strong>[[5],[0,1,2],[3,4,6]]
<strong>解释：
</strong>第一组是 [5]，大小为 1，groupSizes[5] = 1。
第二组是 [0,1,2]，大小为 3，groupSizes[0] = groupSizes[1] = groupSizes[2] = 3。
第三组是 [3,4,6]，大小为 3，groupSizes[3] = groupSizes[4] = groupSizes[6] = 3。 
其他可能的解决方案有 [[2,1,6],[5],[0,4,3]] 和 [[5],[0,6,2],[4,3,1]]。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>groupSizes = [2,1,3,3,3,2]
<strong>输出：</strong>[[1],[0,5],[2,3,4]]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>groupSizes.length == n</code></li>
	<li><code>1 &lt;= n&nbsp;&lt;= 500</code></li>
	<li><code>1 &lt;=&nbsp;groupSizes[i] &lt;= n</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表或数组

我们用一个哈希表 $g$ 来存放每个 $groupSize$ 都有哪些人。然后对每个 $groupSize$ 中的人划分为 $k$ 等份，每一等份有 $groupSize$ 个人。

由于题目中的 $n$ 范围较小，我们也可以直接创建一个大小为 $n+1$ 的数组来存放数据，运行效率较高。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为 $groupSizes$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def groupThePeople(self, groupSizes: List[int]) -> List[List[int]]:
        g = defaultdict(list)
        for i, v in enumerate(groupSizes):
            g[v].append(i)
        return [v[j : j + i] for i, v in g.items() for j in range(0, len(v), i)]
```

#### Java

```java
class Solution {
    public List<List<Integer>> groupThePeople(int[] groupSizes) {
        int n = groupSizes.length;
        List<Integer>[] g = new List[n + 1];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (int i = 0; i < n; ++i) {
            g[groupSizes[i]].add(i);
        }
        List<List<Integer>> ans = new ArrayList<>();
        for (int i = 0; i < g.length; ++i) {
            List<Integer> v = g[i];
            for (int j = 0; j < v.size(); j += i) {
                ans.add(v.subList(j, j + i));
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
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        vector<vector<int>> g(n + 1);
        for (int i = 0; i < n; ++i) {
            g[groupSizes[i]].push_back(i);
        }
        vector<vector<int>> ans;
        for (int i = 0; i < g.size(); ++i) {
            for (int j = 0; j < g[i].size(); j += i) {
                vector<int> t(g[i].begin() + j, g[i].begin() + j + i);
                ans.push_back(t);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func groupThePeople(groupSizes []int) [][]int {
	n := len(groupSizes)
	g := make([][]int, n+1)
	for i, v := range groupSizes {
		g[v] = append(g[v], i)
	}
	ans := [][]int{}
	for i, v := range g {
		for j := 0; j < len(v); j += i {
			ans = append(ans, v[j:j+i])
		}
	}
	return ans
}
```

#### TypeScript

```ts
function groupThePeople(groupSizes: number[]): number[][] {
    const n: number = groupSizes.length;
    const g: number[][] = Array.from({ length: n + 1 }, () => []);

    for (let i = 0; i < groupSizes.length; i++) {
        const size: number = groupSizes[i];
        g[size].push(i);
    }
    const ans: number[][] = [];
    for (let i = 1; i <= n; i++) {
        const group: number[] = [];
        for (let j = 0; j < g[i].length; j += i) {
            group.push(...g[i].slice(j, j + i));
            ans.push([...group]);
            group.length = 0;
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn group_the_people(group_sizes: Vec<i32>) -> Vec<Vec<i32>> {
        let n: usize = group_sizes.len();
        let mut g: Vec<Vec<usize>> = vec![Vec::new(); n + 1];

        for (i, &size) in group_sizes.iter().enumerate() {
            g[size as usize].push(i);
        }

        let mut ans: Vec<Vec<i32>> = Vec::new();
        for (i, v) in g.into_iter().enumerate() {
            for j in (0..v.len()).step_by(i.max(1)) {
                ans.push(
                    v[j..(j + i).min(v.len())]
                        .iter()
                        .map(|&x| x as i32)
                        .collect(),
                );
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

# [1283. 使结果不超过阈值的最小除数](https://leetcode.cn/problems/find-the-smallest-divisor-given-a-threshold){#1283}

{{< tabs "1283" >}}

{{% tab "python" %}}
```python
class Solution:
    def smallestDivisor(self, nums: List[int], threshold: int) -> int:
        def f(v: int) -> bool:
            v += 1
            return sum((x + v - 1) // v for x in nums) <= threshold

        return bisect_left(range(max(nums)), True, key=f) + 1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int smallestDivisor(int[] nums, int threshold) {
        int l = 1, r = 1000000;
        while (l < r) {
            int mid = (l + r) >> 1;
            int s = 0;
            for (int x : nums) {
                s += (x + mid - 1) / mid;
            }
            if (s <= threshold) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1;
        int r = *max_element(nums.begin(), nums.end());
        while (l < r) {
            int mid = (l + r) >> 1;
            int s = 0;
            for (int x : nums) {
                s += (x + mid - 1) / mid;
            }
            if (s <= threshold) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func smallestDivisor(nums []int, threshold int) int {
	return sort.Search(slices.Max(nums), func(v int) bool {
		v++
		s := 0
		for _, x := range nums {
			s += (x + v - 1) / v
		}
		return s <= threshold
	}) + 1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function smallestDivisor(nums: number[], threshold: number): number {
    let l = 1;
    let r = Math.max(...nums);
    while (l < r) {
        const mid = (l + r) >> 1;
        const s = nums.reduce((acc, x) => acc + Math.ceil(x / mid), 0);
        if (s <= threshold) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn smallest_divisor(nums: Vec<i32>, threshold: i32) -> i32 {
        let mut l = 1;
        let mut r = *nums.iter().max().unwrap();
        while l < r {
            let mid = (l + r) / 2;
            let s: i32 = nums.iter().map(|&x| (x + mid - 1) / mid).sum();
            if s <= threshold {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        l
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} nums
 * @param {number} threshold
 * @return {number}
 */
var smallestDivisor = function (nums, threshold) {
    let l = 1;
    let r = Math.max(...nums);
    while (l < r) {
        const mid = (l + r) >> 1;
        const s = nums.reduce((acc, x) => acc + Math.ceil(x / mid), 0);
        if (s <= threshold) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int SmallestDivisor(int[] nums, int threshold) {
        int l = 1;
        int r = nums.Max();
        while (l < r) {
            int mid = (l + r) >> 1;
            int s = 0;
            foreach (int x in nums) {
                s += (x + mid - 1) / mid;
            }
            if (s <= threshold) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组&nbsp;<code>nums</code> 和一个正整数&nbsp;<code>threshold</code> &nbsp;，你需要选择一个正整数作为除数，然后将数组里每个数都除以它，并对除法结果求和。</p>

<p>请你找出能够使上述结果小于等于阈值&nbsp;<code>threshold</code>&nbsp;的除数中 <strong>最小</strong> 的那个。</p>

<p>每个数除以除数后都向上取整，比方说 7/3 = 3 ， 10/2 = 5 。</p>

<p>题目保证一定有解。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,5,9], threshold = 6
<strong>输出：</strong>5
<strong>解释：</strong>如果除数为 1 ，我们可以得到和为 17 （1+2+5+9）。
如果除数为 4 ，我们可以得到和为 7 (1+1+2+3) 。如果除数为 5 ，和为 5 (1+1+1+2)。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,3,5,7,11], threshold = 11
<strong>输出：</strong>3
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [19], threshold = 5
<strong>输出：</strong>4
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 5 * 10^4</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10^6</code></li>
	<li><code>nums.length &lt;=&nbsp;threshold &lt;= 10^6</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二分查找

我们注意到，对于一个数字 $v$，如果将 $nums$ 中的每个数字都除以 $v$ 的结果之和小于等于 $threshold$，那么所有大于 $v$ 的值都满足条件。这存在着单调性，因此我们可以使用二分查找的方法找到最小的满足条件的 $v$。

我们定义二分查找的左边界 $l=1$, $r=\max(nums)$，每次取 $mid=(l+r)/2$，计算 $nums$ 中每个数字除以 $mid$ 的结果之和 $s$，如果 $s$ 小于等于 $threshold$，那么说明 $mid$ 满足条件，我们将 $r$ 更新为 $mid$，否则将 $l$ 更新为 $mid+1$。

最后返回 $l$ 即可。

时间复杂度 $O(n \times \log M)$，其中 $n$ 是数组 $nums$ 的长度，而 $M$ 是数组 $nums$ 中的最大值。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def smallestDivisor(self, nums: List[int], threshold: int) -> int:
        def f(v: int) -> bool:
            v += 1
            return sum((x + v - 1) // v for x in nums) <= threshold

        return bisect_left(range(max(nums)), True, key=f) + 1
```

#### Java

```java
class Solution {
    public int smallestDivisor(int[] nums, int threshold) {
        int l = 1, r = 1000000;
        while (l < r) {
            int mid = (l + r) >> 1;
            int s = 0;
            for (int x : nums) {
                s += (x + mid - 1) / mid;
            }
            if (s <= threshold) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1;
        int r = *max_element(nums.begin(), nums.end());
        while (l < r) {
            int mid = (l + r) >> 1;
            int s = 0;
            for (int x : nums) {
                s += (x + mid - 1) / mid;
            }
            if (s <= threshold) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
```

#### Go

```go
func smallestDivisor(nums []int, threshold int) int {
	return sort.Search(slices.Max(nums), func(v int) bool {
		v++
		s := 0
		for _, x := range nums {
			s += (x + v - 1) / v
		}
		return s <= threshold
	}) + 1
}
```

#### TypeScript

```ts
function smallestDivisor(nums: number[], threshold: number): number {
    let l = 1;
    let r = Math.max(...nums);
    while (l < r) {
        const mid = (l + r) >> 1;
        const s = nums.reduce((acc, x) => acc + Math.ceil(x / mid), 0);
        if (s <= threshold) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}
```

#### Rust

```rust
impl Solution {
    pub fn smallest_divisor(nums: Vec<i32>, threshold: i32) -> i32 {
        let mut l = 1;
        let mut r = *nums.iter().max().unwrap();
        while l < r {
            let mid = (l + r) / 2;
            let s: i32 = nums.iter().map(|&x| (x + mid - 1) / mid).sum();
            if s <= threshold {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        l
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @param {number} threshold
 * @return {number}
 */
var smallestDivisor = function (nums, threshold) {
    let l = 1;
    let r = Math.max(...nums);
    while (l < r) {
        const mid = (l + r) >> 1;
        const s = nums.reduce((acc, x) => acc + Math.ceil(x / mid), 0);
        if (s <= threshold) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
};
```

#### C#

```cs
public class Solution {
    public int SmallestDivisor(int[] nums, int threshold) {
        int l = 1;
        int r = nums.Max();
        while (l < r) {
            int mid = (l + r) >> 1;
            int s = 0;
            foreach (int x in nums) {
                s += (x + mid - 1) / mid;
            }
            if (s <= threshold) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1284. 转化为全零矩阵的最少反转次数](https://leetcode.cn/problems/minimum-number-of-flips-to-convert-binary-matrix-to-zero-matrix){#1284}

{{< tabs "1284" >}}

{{% tab "python" %}}
```python
class Solution:
    def minFlips(self, mat: List[List[int]]) -> int:
        m, n = len(mat), len(mat[0])
        state = sum(1 << (i * n + j) for i in range(m) for j in range(n) if mat[i][j])
        q = deque([state])
        vis = {state}
        ans = 0
        dirs = [0, -1, 0, 1, 0, 0]
        while q:
            for _ in range(len(q)):
                state = q.popleft()
                if state == 0:
                    return ans
                for i in range(m):
                    for j in range(n):
                        nxt = state
                        for k in range(5):
                            x, y = i + dirs[k], j + dirs[k + 1]
                            if not 0 <= x < m or not 0 <= y < n:
                                continue
                            if nxt & (1 << (x * n + y)):
                                nxt -= 1 << (x * n + y)
                            else:
                                nxt |= 1 << (x * n + y)
                        if nxt not in vis:
                            vis.add(nxt)
                            q.append(nxt)
            ans += 1
        return -1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minFlips(int[][] mat) {
        int m = mat.length, n = mat[0].length;
        int state = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 1) {
                    state |= 1 << (i * n + j);
                }
            }
        }
        Deque<Integer> q = new ArrayDeque<>();
        q.offer(state);
        Set<Integer> vis = new HashSet<>();
        vis.add(state);
        int ans = 0;
        int[] dirs = {0, -1, 0, 1, 0, 0};
        while (!q.isEmpty()) {
            for (int t = q.size(); t > 0; --t) {
                state = q.poll();
                if (state == 0) {
                    return ans;
                }
                for (int i = 0; i < m; ++i) {
                    for (int j = 0; j < n; ++j) {
                        int nxt = state;
                        for (int k = 0; k < 5; ++k) {
                            int x = i + dirs[k], y = j + dirs[k + 1];
                            if (x < 0 || x >= m || y < 0 || y >= n) {
                                continue;
                            }
                            if ((nxt & (1 << (x * n + y))) != 0) {
                                nxt -= 1 << (x * n + y);
                            } else {
                                nxt |= 1 << (x * n + y);
                            }
                        }
                        if (!vis.contains(nxt)) {
                            vis.add(nxt);
                            q.offer(nxt);
                        }
                    }
                }
            }
            ++ans;
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
    int minFlips(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int state = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (mat[i][j])
                    state |= (1 << (i * n + j));
        queue<int> q{{state}};
        unordered_set<int> vis{{state}};
        int ans = 0;
        vector<int> dirs = {0, -1, 0, 1, 0, 0};
        while (!q.empty()) {
            for (int t = q.size(); t; --t) {
                state = q.front();
                if (state == 0) return ans;
                q.pop();
                for (int i = 0; i < m; ++i) {
                    for (int j = 0; j < n; ++j) {
                        int nxt = state;
                        for (int k = 0; k < 5; ++k) {
                            int x = i + dirs[k], y = j + dirs[k + 1];
                            if (x < 0 || x >= m || y < 0 || y >= n) continue;
                            if ((nxt & (1 << (x * n + y))) != 0)
                                nxt -= 1 << (x * n + y);
                            else
                                nxt |= 1 << (x * n + y);
                        }
                        if (!vis.count(nxt)) {
                            vis.insert(nxt);
                            q.push(nxt);
                        }
                    }
                }
            }
            ++ans;
        }
        return -1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minFlips(mat [][]int) int {
	m, n := len(mat), len(mat[0])
	state := 0
	for i, row := range mat {
		for j, v := range row {
			if v == 1 {
				state |= 1 << (i*n + j)
			}
		}
	}
	q := []int{state}
	vis := map[int]bool{state: true}
	ans := 0
	dirs := []int{0, -1, 0, 1, 0, 0}
	for len(q) > 0 {
		for t := len(q); t > 0; t-- {
			state = q[0]
			if state == 0 {
				return ans
			}
			q = q[1:]
			for i := 0; i < m; i++ {
				for j := 0; j < n; j++ {
					nxt := state
					for k := 0; k < 5; k++ {
						x, y := i+dirs[k], j+dirs[k+1]
						if x < 0 || x >= m || y < 0 || y >= n {
							continue
						}
						if (nxt & (1 << (x*n + y))) != 0 {
							nxt -= 1 << (x*n + y)
						} else {
							nxt |= 1 << (x*n + y)
						}
					}
					if !vis[nxt] {
						vis[nxt] = true
						q = append(q, nxt)
					}
				}
			}
		}
		ans++
	}
	return -1
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个&nbsp;<code>m x n</code>&nbsp;的二进制矩阵&nbsp;<code>mat</code>。每一步，你可以选择一个单元格并将它反转（反转表示 <code>0</code> 变 <code>1</code> ，<code>1</code> 变 <code>0</code> ）。如果存在和它相邻的单元格，那么这些相邻的单元格也会被反转。相邻的两个单元格共享同一条边。</p>

<p>请你返回将矩阵&nbsp;<code>mat</code> 转化为全零矩阵的<em>最少反转次数</em>，如果无法转化为全零矩阵，请返回&nbsp;<code>-1</code>&nbsp;。</p>

<p><strong>二进制矩阵</strong>&nbsp;的每一个格子要么是 <code>0</code> 要么是 <code>1</code> 。</p>

<p><strong>全零矩阵</strong>&nbsp;是所有格子都为 <code>0</code> 的矩阵。</p>

<p>&nbsp;</p>

<p><strong>示例&nbsp;1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1200-1299/1284.Minimum%20Number%20of%20Flips%20to%20Convert%20Binary%20Matrix%20to%20Zero%20Matrix/images/matrix.png" /></p>

<pre>
<strong>输入：</strong>mat = [[0,0],[0,1]]
<strong>输出：</strong>3
<strong>解释：</strong>一个可能的解是反转 (1, 0)，然后 (0, 1) ，最后是 (1, 1) 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>mat = [[0]]
<strong>输出：</strong>0
<strong>解释：</strong>给出的矩阵是全零矩阵，所以你不需要改变它。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>mat = [[1,0,0],[1,0,0]]
<strong>输出：</strong>-1
<strong>解释：</strong>该矩阵无法转变成全零矩阵
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m ==&nbsp;mat.length</code></li>
	<li><code>n ==&nbsp;mat[0].length</code></li>
	<li><code>1 &lt;= m&nbsp;&lt;= 3</code></li>
	<li><code>1 &lt;= n&nbsp;&lt;= 3</code></li>
	<li><code>mat[i][j]</code>&nbsp;是 0 或 1 。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：状态压缩 + BFS

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minFlips(self, mat: List[List[int]]) -> int:
        m, n = len(mat), len(mat[0])
        state = sum(1 << (i * n + j) for i in range(m) for j in range(n) if mat[i][j])
        q = deque([state])
        vis = {state}
        ans = 0
        dirs = [0, -1, 0, 1, 0, 0]
        while q:
            for _ in range(len(q)):
                state = q.popleft()
                if state == 0:
                    return ans
                for i in range(m):
                    for j in range(n):
                        nxt = state
                        for k in range(5):
                            x, y = i + dirs[k], j + dirs[k + 1]
                            if not 0 <= x < m or not 0 <= y < n:
                                continue
                            if nxt & (1 << (x * n + y)):
                                nxt -= 1 << (x * n + y)
                            else:
                                nxt |= 1 << (x * n + y)
                        if nxt not in vis:
                            vis.add(nxt)
                            q.append(nxt)
            ans += 1
        return -1
```

#### Java

```java
class Solution {
    public int minFlips(int[][] mat) {
        int m = mat.length, n = mat[0].length;
        int state = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 1) {
                    state |= 1 << (i * n + j);
                }
            }
        }
        Deque<Integer> q = new ArrayDeque<>();
        q.offer(state);
        Set<Integer> vis = new HashSet<>();
        vis.add(state);
        int ans = 0;
        int[] dirs = {0, -1, 0, 1, 0, 0};
        while (!q.isEmpty()) {
            for (int t = q.size(); t > 0; --t) {
                state = q.poll();
                if (state == 0) {
                    return ans;
                }
                for (int i = 0; i < m; ++i) {
                    for (int j = 0; j < n; ++j) {
                        int nxt = state;
                        for (int k = 0; k < 5; ++k) {
                            int x = i + dirs[k], y = j + dirs[k + 1];
                            if (x < 0 || x >= m || y < 0 || y >= n) {
                                continue;
                            }
                            if ((nxt & (1 << (x * n + y))) != 0) {
                                nxt -= 1 << (x * n + y);
                            } else {
                                nxt |= 1 << (x * n + y);
                            }
                        }
                        if (!vis.contains(nxt)) {
                            vis.add(nxt);
                            q.offer(nxt);
                        }
                    }
                }
            }
            ++ans;
        }
        return -1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minFlips(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int state = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (mat[i][j])
                    state |= (1 << (i * n + j));
        queue<int> q{{state}};
        unordered_set<int> vis{{state}};
        int ans = 0;
        vector<int> dirs = {0, -1, 0, 1, 0, 0};
        while (!q.empty()) {
            for (int t = q.size(); t; --t) {
                state = q.front();
                if (state == 0) return ans;
                q.pop();
                for (int i = 0; i < m; ++i) {
                    for (int j = 0; j < n; ++j) {
                        int nxt = state;
                        for (int k = 0; k < 5; ++k) {
                            int x = i + dirs[k], y = j + dirs[k + 1];
                            if (x < 0 || x >= m || y < 0 || y >= n) continue;
                            if ((nxt & (1 << (x * n + y))) != 0)
                                nxt -= 1 << (x * n + y);
                            else
                                nxt |= 1 << (x * n + y);
                        }
                        if (!vis.count(nxt)) {
                            vis.insert(nxt);
                            q.push(nxt);
                        }
                    }
                }
            }
            ++ans;
        }
        return -1;
    }
};
```

#### Go

```go
func minFlips(mat [][]int) int {
	m, n := len(mat), len(mat[0])
	state := 0
	for i, row := range mat {
		for j, v := range row {
			if v == 1 {
				state |= 1 << (i*n + j)
			}
		}
	}
	q := []int{state}
	vis := map[int]bool{state: true}
	ans := 0
	dirs := []int{0, -1, 0, 1, 0, 0}
	for len(q) > 0 {
		for t := len(q); t > 0; t-- {
			state = q[0]
			if state == 0 {
				return ans
			}
			q = q[1:]
			for i := 0; i < m; i++ {
				for j := 0; j < n; j++ {
					nxt := state
					for k := 0; k < 5; k++ {
						x, y := i+dirs[k], j+dirs[k+1]
						if x < 0 || x >= m || y < 0 || y >= n {
							continue
						}
						if (nxt & (1 << (x*n + y))) != 0 {
							nxt -= 1 << (x*n + y)
						} else {
							nxt |= 1 << (x*n + y)
						}
					}
					if !vis[nxt] {
						vis[nxt] = true
						q = append(q, nxt)
					}
				}
			}
		}
		ans++
	}
	return -1
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1285. 找到连续区间的开始和结束数字 🔒](https://leetcode.cn/problems/find-the-start-and-end-number-of-continuous-ranges){#1285}

{{< tabs "1285" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            log_id,
            log_id - ROW_NUMBER() OVER (ORDER BY log_id) AS pid
        FROM Logs
    )
SELECT MIN(log_id) AS start_id, MAX(log_id) AS end_id
FROM T
GROUP BY pid;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code>Logs</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| log_id        | int     |
+---------------+---------+
id 是上表具有唯一值的列。
上表的每一行包含日志表中的一个 ID。
</pre>

<p>&nbsp;</p>

<p>编写解决方案，得到&nbsp;<code>Logs</code>&nbsp;表中的连续区间的开始数字和结束数字。</p>

<p>返回结果表按照 <code>start_id</code>&nbsp;排序。</p>

<p>结果格式如下面的例子。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
Logs 表：
+------------+
| log_id     |
+------------+
| 1          |
| 2          |
| 3          |
| 7          |
| 8          |
| 10         |
+------------+
<strong>输出：</strong>
+------------+--------------+
| start_id   | end_id       |
+------------+--------------+
| 1          | 3            |
| 7          | 8            |
| 10         | 10           |
+------------+--------------+
<strong>解释：</strong>
结果表应包含 Logs 表中的所有区间。
从 1 到 3 在表中。
从 4 到 6 不在表中。
从 7 到 8 在表中。
9 不在表中。
10 在表中。</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：分组 + 窗口函数

我们需要想办法将一段连续的日志分到同一组，然后对每一组进行聚合操作，得到每一组的开始日志和结束日志。

分组可以用以下两种方法实现：

1. 通过计算每个日志与前一个日志的差值，如果差值为 $1$，则说明这两个日志是连续的，我们设置 $delta$ 为 $0$，否则设置为 $1$。然后我们对 $delta$ 求前缀和，得到的结果就是每一行的分组的标识符。
2. 通过计算当前行的日志减去当前行的行号，得到的结果就是每一行的分组的标识符。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            log_id,
            SUM(delta) OVER (ORDER BY log_id) AS pid
        FROM
            (
                SELECT
                    log_id,
                    IF((log_id - LAG(log_id) OVER (ORDER BY log_id)) = 1, 0, 1) AS delta
                FROM Logs
            ) AS t
    )
SELECT MIN(log_id) AS start_id, MAX(log_id) AS end_id
FROM T
GROUP BY pid;
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
    T AS (
        SELECT
            log_id,
            log_id - ROW_NUMBER() OVER (ORDER BY log_id) AS pid
        FROM Logs
    )
SELECT MIN(log_id) AS start_id, MAX(log_id) AS end_id
FROM T
GROUP BY pid;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1286. 字母组合迭代器](https://leetcode.cn/problems/iterator-for-combination){#1286}

{{< tabs "1286" >}}

{{% tab "python" %}}
```python
class CombinationIterator:
    def __init__(self, characters: str, combinationLength: int):
        self.curr = (1 << len(characters)) - 1
        self.size = combinationLength
        self.cs = characters[::-1]

    def next(self) -> str:
        while self.curr >= 0 and self.curr.bit_count() != self.size:
            self.curr -= 1
        ans = []
        for i in range(len(self.cs)):
            if (self.curr >> i) & 1:
                ans.append(self.cs[i])
        self.curr -= 1
        return ''.join(ans[::-1])

    def hasNext(self) -> bool:
        while self.curr >= 0 and self.curr.bit_count() != self.size:
            self.curr -= 1
        return self.curr >= 0


# Your CombinationIterator object will be instantiated and called as such:
# obj = CombinationIterator(characters, combinationLength)
# param_1 = obj.next()
# param_2 = obj.hasNext()
```
{{% /tab %}}
{{% tab "java" %}}
```java
class CombinationIterator {
    private int curr;
    private int size;
    private char[] cs;

    public CombinationIterator(String characters, int combinationLength) {
        int n = characters.length();
        curr = (1 << n) - 1;
        size = combinationLength;
        cs = new char[n];
        for (int i = 0; i < n; ++i) {
            cs[i] = characters.charAt(n - i - 1);
        }
    }

    public String next() {
        while (curr >= 0 && Integer.bitCount(curr) != size) {
            --curr;
        }
        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < cs.length; ++i) {
            if (((curr >> i) & 1) == 1) {
                ans.append(cs[i]);
            }
        }
        --curr;
        return ans.reverse().toString();
    }

    public boolean hasNext() {
        while (curr >= 0 && Integer.bitCount(curr) != size) {
            --curr;
        }
        return curr >= 0;
    }
}

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator obj = new CombinationIterator(characters, combinationLength);
 * String param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class CombinationIterator {
public:
    int size;
    string cs;
    int curr;

    CombinationIterator(string characters, int combinationLength) {
        int n = characters.size();
        curr = (1 << n) - 1;
        reverse(characters.begin(), characters.end());
        cs = characters;
        size = combinationLength;
    }

    string next() {
        while (curr >= 0 && __builtin_popcount(curr) != size) --curr;
        string ans;
        for (int i = 0; i < cs.size(); ++i) {
            if ((curr >> i) & 1) {
                ans += cs[i];
            }
        }
        reverse(ans.begin(), ans.end());
        --curr;
        return ans;
    }

    bool hasNext() {
        while (curr >= 0 && __builtin_popcount(curr) != size) --curr;
        return curr >= 0;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type CombinationIterator struct {
	curr int
	size int
	cs   []byte
}

func Constructor(characters string, combinationLength int) CombinationIterator {
	n := len(characters)
	curr := (1 << n) - 1
	size := combinationLength
	cs := make([]byte, n)
	for i := range characters {
		cs[n-i-1] = characters[i]
	}
	return CombinationIterator{curr, size, cs}
}

func (this *CombinationIterator) Next() string {
	for this.curr >= 0 && bits.OnesCount(uint(this.curr)) != this.size {
		this.curr--
	}
	ans := []byte{}
	for i := range this.cs {
		if (this.curr >> i & 1) == 1 {
			ans = append(ans, this.cs[i])
		}
	}
	for i, j := 0, len(ans)-1; i < j; i, j = i+1, j-1 {
		ans[i], ans[j] = ans[j], ans[i]
	}
	this.curr--
	return string(ans)
}

func (this *CombinationIterator) HasNext() bool {
	for this.curr >= 0 && bits.OnesCount(uint(this.curr)) != this.size {
		this.curr--
	}
	return this.curr >= 0
}

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * obj := Constructor(characters, combinationLength);
 * param_1 := obj.Next();
 * param_2 := obj.HasNext();
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>请你设计一个迭代器类&nbsp;<code>CombinationIterator</code>&nbsp;，包括以下内容：</p>

<ul>
	<li><code>CombinationIterator(string characters, int combinationLength)</code>&nbsp;一个构造函数，输入参数包括：用一个&nbsp;<strong>有序且字符唯一&nbsp;</strong>的字符串&nbsp;<code>characters</code>（该字符串只包含小写英文字母）和一个数字&nbsp;<code>combinationLength</code>&nbsp;。</li>
	<li>函数&nbsp;<em><code>next()</code>&nbsp;</em>，按&nbsp;<strong>字典序&nbsp;</strong>返回长度为&nbsp;<code>combinationLength</code> 的下一个字母组合。</li>
	<li>函数&nbsp;<em><code>hasNext()</code>&nbsp;</em>，只有存在长度为&nbsp;<code>combinationLength</code> 的下一个字母组合时，才返回&nbsp;<code>true</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入:</strong>
["CombinationIterator", "next", "hasNext", "next", "hasNext", "next", "hasNext"]
[["abc", 2], [], [], [], [], [], []]
<strong>输出：</strong>
[null, "ab", true, "ac", true, "bc", false]
<strong>解释：
</strong>CombinationIterator iterator = new CombinationIterator("abc", 2); // 创建迭代器 iterator
iterator.next(); // 返回 "ab"
iterator.hasNext(); // 返回 true
iterator.next(); // 返回 "ac"
iterator.hasNext(); // 返回 true
iterator.next(); // 返回 "bc"
iterator.hasNext(); // 返回 false
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= combinationLength &lt;=&nbsp;characters.length &lt;= 15</code></li>
	<li>&nbsp;<code>characters</code>&nbsp;中每个字符都 <strong>不同</strong></li>
	<li>每组测试数据最多对&nbsp;<code>next</code>&nbsp;和&nbsp;<code>hasNext</code>&nbsp;调用&nbsp;<code>10<sup>4</sup></code>次</li>
	<li>题目保证每次调用函数&nbsp;<code>next</code>&nbsp;时都存在下一个字母组合。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS 回溯

我们通过 $DFS$ 枚举，预处理生成所有长度为 $combinationLength$ 的字符串，存放到 $cs$ 数组中。

<!-- tabs:start -->

#### Python3

```python
class CombinationIterator:
    def __init__(self, characters: str, combinationLength: int):
        def dfs(i):
            if len(t) == combinationLength:
                cs.append(''.join(t))
                return
            if i == n:
                return
            t.append(characters[i])
            dfs(i + 1)
            t.pop()
            dfs(i + 1)

        cs = []
        n = len(characters)
        t = []
        dfs(0)
        self.cs = cs
        self.idx = 0

    def next(self) -> str:
        ans = self.cs[self.idx]
        self.idx += 1
        return ans

    def hasNext(self) -> bool:
        return self.idx < len(self.cs)


# Your CombinationIterator object will be instantiated and called as such:
# obj = CombinationIterator(characters, combinationLength)
# param_1 = obj.next()
# param_2 = obj.hasNext()
```

#### Java

```java
class CombinationIterator {
    private int n;
    private int combinationLength;
    private String characters;
    private StringBuilder t = new StringBuilder();
    private List<String> cs = new ArrayList<>();
    private int idx = 0;

    public CombinationIterator(String characters, int combinationLength) {
        n = characters.length();
        this.combinationLength = combinationLength;
        this.characters = characters;
        dfs(0);
    }

    public String next() {
        return cs.get(idx++);
    }

    public boolean hasNext() {
        return idx < cs.size();
    }

    private void dfs(int i) {
        if (t.length() == combinationLength) {
            cs.add(t.toString());
            return;
        }
        if (i == n) {
            return;
        }
        t.append(characters.charAt(i));
        dfs(i + 1);
        t.deleteCharAt(t.length() - 1);
        dfs(i + 1);
    }
}

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator obj = new CombinationIterator(characters, combinationLength);
 * String param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */
```

#### C++

```cpp
class CombinationIterator {
public:
    string characters;
    vector<string> cs;
    int idx;
    int n;
    int combinationLength;
    string t;

    CombinationIterator(string characters, int combinationLength) {
        idx = 0;
        n = characters.size();
        this->characters = characters;
        this->combinationLength = combinationLength;
        dfs(0);
    }

    string next() {
        return cs[idx++];
    }

    bool hasNext() {
        return idx < cs.size();
    }

    void dfs(int i) {
        if (t.size() == combinationLength) {
            cs.push_back(t);
            return;
        }
        if (i == n) return;
        t.push_back(characters[i]);
        dfs(i + 1);
        t.pop_back();
        dfs(i + 1);
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
```

#### Go

```go
type CombinationIterator struct {
	cs  []string
	idx int
}

func Constructor(characters string, combinationLength int) CombinationIterator {
	t := []byte{}
	n := len(characters)
	cs := []string{}
	var dfs func(int)
	dfs = func(i int) {
		if len(t) == combinationLength {
			cs = append(cs, string(t))
			return
		}
		if i == n {
			return
		}
		t = append(t, characters[i])
		dfs(i + 1)
		t = t[:len(t)-1]
		dfs(i + 1)
	}
	dfs(0)
	return CombinationIterator{cs, 0}
}

func (this *CombinationIterator) Next() string {
	ans := this.cs[this.idx]
	this.idx++
	return ans
}

func (this *CombinationIterator) HasNext() bool {
	return this.idx < len(this.cs)
}

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * obj := Constructor(characters, combinationLength);
 * param_1 := obj.Next();
 * param_2 := obj.HasNext();
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：二进制编码

我们看个例子，对于 $abcd$，若 $combinationLength$ 为 2，则 $cs$ 就是 $ab, ac, ad, bc, bd, cd, ...$。

对应的二进制数为：

```
1100
1010
1001
0110
0101
0011
...
```

观察到上述规律后，我们依次按照二进制编码从大到小的规律，将所有字符串依次求出。

所谓的长度 $combinationLength$，只需要满足二进制编码中 $1$ 的个数满足要求即可。

<!-- tabs:start -->

#### Python3

```python
class CombinationIterator:
    def __init__(self, characters: str, combinationLength: int):
        self.curr = (1 << len(characters)) - 1
        self.size = combinationLength
        self.cs = characters[::-1]

    def next(self) -> str:
        while self.curr >= 0 and self.curr.bit_count() != self.size:
            self.curr -= 1
        ans = []
        for i in range(len(self.cs)):
            if (self.curr >> i) & 1:
                ans.append(self.cs[i])
        self.curr -= 1
        return ''.join(ans[::-1])

    def hasNext(self) -> bool:
        while self.curr >= 0 and self.curr.bit_count() != self.size:
            self.curr -= 1
        return self.curr >= 0


# Your CombinationIterator object will be instantiated and called as such:
# obj = CombinationIterator(characters, combinationLength)
# param_1 = obj.next()
# param_2 = obj.hasNext()
```

#### Java

```java
class CombinationIterator {
    private int curr;
    private int size;
    private char[] cs;

    public CombinationIterator(String characters, int combinationLength) {
        int n = characters.length();
        curr = (1 << n) - 1;
        size = combinationLength;
        cs = new char[n];
        for (int i = 0; i < n; ++i) {
            cs[i] = characters.charAt(n - i - 1);
        }
    }

    public String next() {
        while (curr >= 0 && Integer.bitCount(curr) != size) {
            --curr;
        }
        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < cs.length; ++i) {
            if (((curr >> i) & 1) == 1) {
                ans.append(cs[i]);
            }
        }
        --curr;
        return ans.reverse().toString();
    }

    public boolean hasNext() {
        while (curr >= 0 && Integer.bitCount(curr) != size) {
            --curr;
        }
        return curr >= 0;
    }
}

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator obj = new CombinationIterator(characters, combinationLength);
 * String param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */
```

#### C++

```cpp
class CombinationIterator {
public:
    int size;
    string cs;
    int curr;

    CombinationIterator(string characters, int combinationLength) {
        int n = characters.size();
        curr = (1 << n) - 1;
        reverse(characters.begin(), characters.end());
        cs = characters;
        size = combinationLength;
    }

    string next() {
        while (curr >= 0 && __builtin_popcount(curr) != size) --curr;
        string ans;
        for (int i = 0; i < cs.size(); ++i) {
            if ((curr >> i) & 1) {
                ans += cs[i];
            }
        }
        reverse(ans.begin(), ans.end());
        --curr;
        return ans;
    }

    bool hasNext() {
        while (curr >= 0 && __builtin_popcount(curr) != size) --curr;
        return curr >= 0;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
```

#### Go

```go
type CombinationIterator struct {
	curr int
	size int
	cs   []byte
}

func Constructor(characters string, combinationLength int) CombinationIterator {
	n := len(characters)
	curr := (1 << n) - 1
	size := combinationLength
	cs := make([]byte, n)
	for i := range characters {
		cs[n-i-1] = characters[i]
	}
	return CombinationIterator{curr, size, cs}
}

func (this *CombinationIterator) Next() string {
	for this.curr >= 0 && bits.OnesCount(uint(this.curr)) != this.size {
		this.curr--
	}
	ans := []byte{}
	for i := range this.cs {
		if (this.curr >> i & 1) == 1 {
			ans = append(ans, this.cs[i])
		}
	}
	for i, j := 0, len(ans)-1; i < j; i, j = i+1, j-1 {
		ans[i], ans[j] = ans[j], ans[i]
	}
	this.curr--
	return string(ans)
}

func (this *CombinationIterator) HasNext() bool {
	for this.curr >= 0 && bits.OnesCount(uint(this.curr)) != this.size {
		this.curr--
	}
	return this.curr >= 0
}

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * obj := Constructor(characters, combinationLength);
 * param_1 := obj.Next();
 * param_2 := obj.HasNext();
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1287. 有序数组中出现次数超过25%的元素](https://leetcode.cn/problems/element-appearing-more-than-25-in-sorted-array){#1287}

{{< tabs "1287" >}}

{{% tab "python" %}}
```python
class Solution:
    def findSpecialInteger(self, arr: List[int]) -> int:
        n = len(arr)
        for i, x in enumerate(arr):
            if x == arr[(i + (n >> 2))]:
                return x
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int findSpecialInteger(int[] arr) {
        for (int i = 0;; ++i) {
            if (arr[i] == (arr[i + (arr.length >> 2)])) {
                return arr[i];
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
    int findSpecialInteger(vector<int>& arr) {
        for (int i = 0;; ++i) {
            if (arr[i] == (arr[i + (arr.size() >> 2)])) {
                return arr[i];
            }
        }
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findSpecialInteger(arr []int) int {
	for i := 0; ; i++ {
		if arr[i] == arr[i+len(arr)/4] {
			return arr[i]
		}
	}
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findSpecialInteger(arr: number[]): number {
    const n = arr.length;
    for (let i = 0; ; ++i) {
        if (arr[i] === arr[i + (n >> 2)]) {
            return arr[i];
        }
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} arr
 * @return {number}
 */
var findSpecialInteger = function (arr) {
    const n = arr.length;
    for (let i = 0; ; ++i) {
        if (arr[i] === arr[i + (n >> 2)]) {
            return arr[i];
        }
    }
};
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param Integer[] $arr
     * @return Integer
     */
    function findSpecialInteger($arr) {
        $n = count($arr);
        for ($i = 0; ; ++$i) {
            if ($arr[$i] == $arr[$i + ($n >> 2)]) {
                return $arr[$i];
            }
        }
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个非递减的&nbsp;<strong>有序&nbsp;</strong>整数数组，已知这个数组中恰好有一个整数，它的出现次数超过数组元素总数的 25%。</p>

<p>请你找到并返回这个整数</p>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre>
<strong>输入：</strong>arr = [1,2,2,6,6,6,6,7,10]
<strong>输出：</strong>6
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 10^4</code></li>
	<li><code>0 &lt;= arr[i] &lt;= 10^5</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：遍历

我们从头开始遍历数组 $\textit{arr}$，对于每个元素 $\textit{arr}[i]$，我们检查 $\textit{arr}[i]$ 是否等于 $\textit{arr}[i + \left\lfloor \frac{n}{4} \right\rfloor]$，其中 $n$ 是数组的长度。如果等于，那么 $\textit{arr}[i]$ 就是我们要找的元素，直接返回即可。

时间复杂度 $O(n)$，其中 $n$ 是数组 $\textit{arr}$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findSpecialInteger(self, arr: List[int]) -> int:
        n = len(arr)
        for i, x in enumerate(arr):
            if x == arr[(i + (n >> 2))]:
                return x
```

#### Java

```java
class Solution {
    public int findSpecialInteger(int[] arr) {
        for (int i = 0;; ++i) {
            if (arr[i] == (arr[i + (arr.length >> 2)])) {
                return arr[i];
            }
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        for (int i = 0;; ++i) {
            if (arr[i] == (arr[i + (arr.size() >> 2)])) {
                return arr[i];
            }
        }
    }
};
```

#### Go

```go
func findSpecialInteger(arr []int) int {
	for i := 0; ; i++ {
		if arr[i] == arr[i+len(arr)/4] {
			return arr[i]
		}
	}
}
```

#### TypeScript

```ts
function findSpecialInteger(arr: number[]): number {
    const n = arr.length;
    for (let i = 0; ; ++i) {
        if (arr[i] === arr[i + (n >> 2)]) {
            return arr[i];
        }
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} arr
 * @return {number}
 */
var findSpecialInteger = function (arr) {
    const n = arr.length;
    for (let i = 0; ; ++i) {
        if (arr[i] === arr[i + (n >> 2)]) {
            return arr[i];
        }
    }
};
```

#### PHP

```php
class Solution {
    /**
     * @param Integer[] $arr
     * @return Integer
     */
    function findSpecialInteger($arr) {
        $n = count($arr);
        for ($i = 0; ; ++$i) {
            if ($arr[$i] == $arr[$i + ($n >> 2)]) {
                return $arr[$i];
            }
        }
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1288. 删除被覆盖区间](https://leetcode.cn/problems/remove-covered-intervals){#1288}

{{< tabs "1288" >}}

{{% tab "python" %}}
```python
class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda x: (x[0], -x[1]))
        ans = 0
        pre = -inf
        for _, cur in intervals:
            if cur > pre:
                ans += 1
                pre = cur
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int removeCoveredIntervals(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> a[0] == b[0] ? b[1] - a[1] : a[0] - b[0]);
        int ans = 0, pre = Integer.MIN_VALUE;
        for (var e : intervals) {
            int cur = e[1];
            if (cur > pre) {
                ++ans;
                pre = cur;
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
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        ranges::sort(intervals, [](const vector<int>& a, const vector<int>& b) {
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });
        int ans = 0, pre = INT_MIN;
        for (const auto& e : intervals) {
            int cur = e[1];
            if (cur > pre) {
                ++ans;
                pre = cur;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func removeCoveredIntervals(intervals [][]int) (ans int) {
	sort.Slice(intervals, func(i, j int) bool {
		if intervals[i][0] == intervals[j][0] {
			return intervals[i][1] > intervals[j][1]
		}
		return intervals[i][0] < intervals[j][0]
	})
	pre := math.MinInt32
	for _, e := range intervals {
		cur := e[1]
		if cur > pre {
			ans++
			pre = cur
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function removeCoveredIntervals(intervals: number[][]): number {
    intervals.sort((a, b) => (a[0] === b[0] ? b[1] - a[1] : a[0] - b[0]));
    let ans = 0;
    let pre = -Infinity;
    for (const [_, cur] of intervals) {
        if (cur > pre) {
            ++ans;
            pre = cur;
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[][]} intervals
 * @return {number}
 */
var removeCoveredIntervals = function (intervals) {
    intervals.sort((a, b) => (a[0] === b[0] ? b[1] - a[1] : a[0] - b[0]));
    let ans = 0;
    let pre = -Infinity;
    for (const [_, cur] of intervals) {
        if (cur > pre) {
            ++ans;
            pre = cur;
        }
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

<p>给你一个区间列表，请你删除列表中被其他区间所覆盖的区间。</p>

<p>只有当&nbsp;<code>c &lt;= a</code>&nbsp;且&nbsp;<code>b &lt;= d</code>&nbsp;时，我们才认为区间&nbsp;<code>[a,b)</code> 被区间&nbsp;<code>[c,d)</code> 覆盖。</p>

<p>在完成所有删除操作后，请你返回列表中剩余区间的数目。</p>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre>
<strong>输入：</strong>intervals = [[1,4],[3,6],[2,8]]
<strong>输出：</strong>2
<strong>解释：</strong>区间 [3,6] 被区间 [2,8] 覆盖，所以它被删除了。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong>​​​​​​</p>

<ul>
	<li><code>1 &lt;= intervals.length &lt;= 1000</code></li>
	<li><code>0 &lt;= intervals[i][0] &lt;&nbsp;intervals[i][1] &lt;= 10^5</code></li>
	<li>对于所有的&nbsp;<code>i != j</code>：<code>intervals[i] != intervals[j]</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序

我们可以按照区间的左端点升序排序，如果左端点相同，则按照右端点降序排序。

排序后，我们可以遍历区间，如果当前区间的右端点大于之前的右端点，说明当前区间不被覆盖，答案加一。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 是区间的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda x: (x[0], -x[1]))
        ans = 0
        pre = -inf
        for _, cur in intervals:
            if cur > pre:
                ans += 1
                pre = cur
        return ans
```

#### Java

```java
class Solution {
    public int removeCoveredIntervals(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> a[0] == b[0] ? b[1] - a[1] : a[0] - b[0]);
        int ans = 0, pre = Integer.MIN_VALUE;
        for (var e : intervals) {
            int cur = e[1];
            if (cur > pre) {
                ++ans;
                pre = cur;
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
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        ranges::sort(intervals, [](const vector<int>& a, const vector<int>& b) {
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });
        int ans = 0, pre = INT_MIN;
        for (const auto& e : intervals) {
            int cur = e[1];
            if (cur > pre) {
                ++ans;
                pre = cur;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func removeCoveredIntervals(intervals [][]int) (ans int) {
	sort.Slice(intervals, func(i, j int) bool {
		if intervals[i][0] == intervals[j][0] {
			return intervals[i][1] > intervals[j][1]
		}
		return intervals[i][0] < intervals[j][0]
	})
	pre := math.MinInt32
	for _, e := range intervals {
		cur := e[1]
		if cur > pre {
			ans++
			pre = cur
		}
	}
	return
}
```

#### TypeScript

```ts
function removeCoveredIntervals(intervals: number[][]): number {
    intervals.sort((a, b) => (a[0] === b[0] ? b[1] - a[1] : a[0] - b[0]));
    let ans = 0;
    let pre = -Infinity;
    for (const [_, cur] of intervals) {
        if (cur > pre) {
            ++ans;
            pre = cur;
        }
    }
    return ans;
}
```

#### JavaScript

```js
/**
 * @param {number[][]} intervals
 * @return {number}
 */
var removeCoveredIntervals = function (intervals) {
    intervals.sort((a, b) => (a[0] === b[0] ? b[1] - a[1] : a[0] - b[0]));
    let ans = 0;
    let pre = -Infinity;
    for (const [_, cur] of intervals) {
        if (cur > pre) {
            ++ans;
            pre = cur;
        }
    }
    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1289. 下降路径最小和 II](https://leetcode.cn/problems/minimum-falling-path-sum-ii){#1289}

{{< tabs "1289" >}}

{{% tab "python" %}}
```python
class Solution:
    def minFallingPathSum(self, grid: List[List[int]]) -> int:
        n = len(grid)
        f = [0] * n
        for row in grid:
            g = row[:]
            for i in range(n):
                g[i] += min((f[j] for j in range(n) if j != i), default=0)
            f = g
        return min(f)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minFallingPathSum(int[][] grid) {
        int n = grid.length;
        int[] f = new int[n];
        final int inf = 1 << 30;
        for (int[] row : grid) {
            int[] g = row.clone();
            for (int i = 0; i < n; ++i) {
                int t = inf;
                for (int j = 0; j < n; ++j) {
                    if (j != i) {
                        t = Math.min(t, f[j]);
                    }
                }
                g[i] += (t == inf ? 0 : t);
            }
            f = g;
        }
        return Arrays.stream(f).min().getAsInt();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> f(n);
        const int inf = 1e9;
        for (const auto& row : grid) {
            vector<int> g = row;
            for (int i = 0; i < n; ++i) {
                int t = inf;
                for (int j = 0; j < n; ++j) {
                    if (j != i) {
                        t = min(t, f[j]);
                    }
                }
                g[i] += (t == inf ? 0 : t);
            }
            f = move(g);
        }
        return ranges::min(f);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minFallingPathSum(grid [][]int) int {
	f := make([]int, len(grid))
	const inf = math.MaxInt32
	for _, row := range grid {
		g := slices.Clone(row)
		for i := range f {
			t := inf
			for j := range row {
				if j != i {
					t = min(t, f[j])
				}
			}
			if t != inf {
				g[i] += t
			}
		}
		f = g
	}
	return slices.Min(f)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minFallingPathSum(grid: number[][]): number {
    const n = grid.length;
    const f: number[] = Array(n).fill(0);
    for (const row of grid) {
        const g = [...row];
        for (let i = 0; i < n; ++i) {
            let t = Infinity;
            for (let j = 0; j < n; ++j) {
                if (j !== i) {
                    t = Math.min(t, f[j]);
                }
            }
            g[i] += t === Infinity ? 0 : t;
        }
        f.splice(0, n, ...g);
    }
    return Math.min(...f);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn min_falling_path_sum(grid: Vec<Vec<i32>>) -> i32 {
        let n = grid.len();
        let mut f = vec![0; n];
        let inf = i32::MAX;

        for row in grid {
            let mut g = row.clone();
            for i in 0..n {
                let mut t = inf;
                for j in 0..n {
                    if j != i {
                        t = t.min(f[j]);
                    }
                }
                g[i] += if t == inf { 0 } else { t };
            }
            f = g;
        }

        *f.iter().min().unwrap()
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个&nbsp;<code>n x n</code> 整数矩阵&nbsp;<code>grid</code>&nbsp;，请你返回 <strong>非零偏移下降路径</strong> 数字和的最小值。</p>

<p><strong>非零偏移下降路径</strong> 定义为：从&nbsp;<code>grid</code> 数组中的每一行选择一个数字，且按顺序选出来的数字中，相邻数字不在原数组的同一列。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1200-1299/1289.Minimum%20Falling%20Path%20Sum%20II/images/falling-grid.jpg" style="width: 244px; height: 245px;" /></p>

<pre>
<strong>输入：</strong>grid = [[1,2,3],[4,5,6],[7,8,9]]
<strong>输出：</strong>13
<strong>解释：</strong>
所有非零偏移下降路径包括：
[1,5,9], [1,5,7], [1,6,7], [1,6,8],
[2,4,8], [2,4,9], [2,6,7], [2,6,8],
[3,4,8], [3,4,9], [3,5,7], [3,5,9]
下降路径中数字和最小的是&nbsp;[1,5,7] ，所以答案是&nbsp;13 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>grid = [[7]]
<strong>输出：</strong>7
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == grid.length == grid[i].length</code></li>
	<li><code>1 &lt;= n &lt;= 200</code></li>
	<li><code>-99 &lt;= grid[i][j] &lt;= 99</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i][j]$ 表示前 $i$ 行，且最后一个数字在第 $j$ 列的最小数字和。那么状态转移方程为：

$$
f[i][j] = \min_{k \neq j} f[i - 1][k] + grid[i - 1][j]
$$

其中 $k$ 表示第 $i - 1$ 行的数字在第 $k$ 列，第 $i$ 行第 $j$ 列的数字为 $grid[i - 1][j]$。

最后答案为 $f[n]$ 中的最小值。

时间复杂度 $O(n^3)$，空间复杂度 $O(n^2)$。其中 $n$ 为矩阵的行数。

我们注意到，状态 $f[i][j]$ 只与 $f[i - 1][k]$ 有关，因此我们可以使用滚动数组优化空间复杂度，将空间复杂度优化到 $O(n)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minFallingPathSum(self, grid: List[List[int]]) -> int:
        n = len(grid)
        f = [0] * n
        for row in grid:
            g = row[:]
            for i in range(n):
                g[i] += min((f[j] for j in range(n) if j != i), default=0)
            f = g
        return min(f)
```

#### Java

```java
class Solution {
    public int minFallingPathSum(int[][] grid) {
        int n = grid.length;
        int[] f = new int[n];
        final int inf = 1 << 30;
        for (int[] row : grid) {
            int[] g = row.clone();
            for (int i = 0; i < n; ++i) {
                int t = inf;
                for (int j = 0; j < n; ++j) {
                    if (j != i) {
                        t = Math.min(t, f[j]);
                    }
                }
                g[i] += (t == inf ? 0 : t);
            }
            f = g;
        }
        return Arrays.stream(f).min().getAsInt();
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> f(n);
        const int inf = 1e9;
        for (const auto& row : grid) {
            vector<int> g = row;
            for (int i = 0; i < n; ++i) {
                int t = inf;
                for (int j = 0; j < n; ++j) {
                    if (j != i) {
                        t = min(t, f[j]);
                    }
                }
                g[i] += (t == inf ? 0 : t);
            }
            f = move(g);
        }
        return ranges::min(f);
    }
};
```

#### Go

```go
func minFallingPathSum(grid [][]int) int {
	f := make([]int, len(grid))
	const inf = math.MaxInt32
	for _, row := range grid {
		g := slices.Clone(row)
		for i := range f {
			t := inf
			for j := range row {
				if j != i {
					t = min(t, f[j])
				}
			}
			if t != inf {
				g[i] += t
			}
		}
		f = g
	}
	return slices.Min(f)
}
```

#### TypeScript

```ts
function minFallingPathSum(grid: number[][]): number {
    const n = grid.length;
    const f: number[] = Array(n).fill(0);
    for (const row of grid) {
        const g = [...row];
        for (let i = 0; i < n; ++i) {
            let t = Infinity;
            for (let j = 0; j < n; ++j) {
                if (j !== i) {
                    t = Math.min(t, f[j]);
                }
            }
            g[i] += t === Infinity ? 0 : t;
        }
        f.splice(0, n, ...g);
    }
    return Math.min(...f);
}
```

#### Rust

```rust
impl Solution {
    pub fn min_falling_path_sum(grid: Vec<Vec<i32>>) -> i32 {
        let n = grid.len();
        let mut f = vec![0; n];
        let inf = i32::MAX;

        for row in grid {
            let mut g = row.clone();
            for i in 0..n {
                let mut t = inf;
                for j in 0..n {
                    if j != i {
                        t = t.min(f[j]);
                    }
                }
                g[i] += if t == inf { 0 } else { t };
            }
            f = g;
        }

        *f.iter().min().unwrap()
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
