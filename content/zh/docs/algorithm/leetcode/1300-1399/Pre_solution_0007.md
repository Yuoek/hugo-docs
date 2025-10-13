---
title: "1360_日期之间隔几天"
date: 2025-10-08T18:37:12+08:00
weight: 7
tags: [二叉树, 动态规划, 哈希表, 图, 堆（优先队列）, 字符串, 并查集, 广度优先搜索, 排序, 数学, 数据库, 数组, 最短路, 树, 深度优先搜索, 矩阵, 计数, 计数排序, 贪心, 链表]
---

{{< markmap >}}
### [1360_日期之间隔几天](#1360)
#### [数学](#1360)
#### [字符串](#1360)
### [1361_验证二叉树](#1361)
#### [树](#1361)
#### [深度优先搜索](#1361)
#### [广度优先搜索](#1361)
#### [并查集](#1361)
#### [图](#1361)
#### [二叉树](#1361)
### [1362_最接近的因数](#1362)
#### [数学](#1362)
### [1363_形成三的最大倍数](#1363)
#### [贪心](#1363)
#### [数组](#1363)
#### [数学](#1363)
#### [动态规划](#1363)
#### [排序](#1363)
### [1364_顾客的可信联系人数量 🔒](#1364)
#### [数据库](#1364)
### [1365_有多少小于当前数字的数字](#1365)
#### [数组](#1365)
#### [哈希表](#1365)
#### [计数排序](#1365)
#### [排序](#1365)
### [1366_通过投票对团队排名](#1366)
#### [数组](#1366)
#### [哈希表](#1366)
#### [字符串](#1366)
#### [计数](#1366)
#### [排序](#1366)
### [1367_二叉树中的链表](#1367)
#### [树](#1367)
#### [深度优先搜索](#1367)
#### [链表](#1367)
#### [二叉树](#1367)
### [1368_使网格图至少有一条有效路径的最小代价](#1368)
#### [广度优先搜索](#1368)
#### [图](#1368)
#### [数组](#1368)
#### [矩阵](#1368)
#### [最短路](#1368)
#### [堆（优先队列）](#1368)
### [1369_获取最近第二次的活动 🔒](#1369)
#### [数据库](#1369)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1360_日期之间隔几天
___
#### 数学
___
#### 字符串
---
### 1361_验证二叉树
___
#### 树
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 并查集
___
#### 图
___
#### 二叉树
---
### 1362_最接近的因数
___
#### 数学
---
### 1363_形成三的最大倍数
___
#### 贪心
___
#### 数组
___
#### 数学
___
#### 动态规划
___
#### 排序
---
### 1364_顾客的可信联系人数量 🔒
___
#### 数据库
---
### 1365_有多少小于当前数字的数字
___
#### 数组
___
#### 哈希表
___
#### 计数排序
___
#### 排序
---
### 1366_通过投票对团队排名
___
#### 数组
___
#### 哈希表
___
#### 字符串
___
#### 计数
___
#### 排序
---
### 1367_二叉树中的链表
___
#### 树
___
#### 深度优先搜索
___
#### 链表
___
#### 二叉树
---
### 1368_使网格图至少有一条有效路径的最小代价
___
#### 广度优先搜索
___
#### 图
___
#### 数组
___
#### 矩阵
___
#### 最短路
___
#### 堆（优先队列）
---
### 1369_获取最近第二次的活动 🔒
___
#### 数据库
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二叉树 | 动态规划 | 哈希表 |
| 图 | 堆（优先队列） | 字符串 |
| 并查集 | 广度优先搜索 | 排序 |
| 数学 | 数据库 | 数组 |
| 最短路 | 树 | 深度优先搜索 |
| 矩阵 | 计数 | 计数排序 |
| 贪心 | 链表 |  |

# [1360. 日期之间隔几天](https://leetcode.cn/problems/number-of-days-between-two-dates){#1360}

{{< tabs "1360" >}}

{{% tab "python" %}}
```python
class Solution:
    def daysBetweenDates(self, date1: str, date2: str) -> int:
        def isLeapYear(year: int) -> bool:
            return year % 4 == 0 and (year % 100 != 0 or year % 400 == 0)

        def daysInMonth(year: int, month: int) -> int:
            days = [
                31,
                28 + int(isLeapYear(year)),
                31,
                30,
                31,
                30,
                31,
                31,
                30,
                31,
                30,
                31,
            ]
            return days[month - 1]

        def calcDays(date: str) -> int:
            year, month, day = map(int, date.split("-"))
            days = 0
            for y in range(1971, year):
                days += 365 + int(isLeapYear(y))
            for m in range(1, month):
                days += daysInMonth(year, m)
            days += day
            return days

        return abs(calcDays(date1) - calcDays(date2))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int daysBetweenDates(String date1, String date2) {
        return Math.abs(calcDays(date1) - calcDays(date2));
    }

    private boolean isLeapYear(int year) {
        return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
    }

    private int daysInMonth(int year, int month) {
        int[] days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        days[1] += isLeapYear(year) ? 1 : 0;
        return days[month - 1];
    }

    private int calcDays(String date) {
        int year = Integer.parseInt(date.substring(0, 4));
        int month = Integer.parseInt(date.substring(5, 7));
        int day = Integer.parseInt(date.substring(8));
        int days = 0;
        for (int y = 1971; y < year; ++y) {
            days += isLeapYear(y) ? 366 : 365;
        }
        for (int m = 1; m < month; ++m) {
            days += daysInMonth(year, m);
        }
        days += day;
        return days;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int daysBetweenDates(string date1, string date2) {
        return abs(calcDays(date1) - calcDays(date2));
    }

    bool isLeapYear(int year) {
        return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
    }

    int daysInMonth(int year, int month) {
        int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        days[1] += isLeapYear(year);
        return days[month - 1];
    }

    int calcDays(string date) {
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));
        int days = 0;
        for (int y = 1971; y < year; ++y) {
            days += 365 + isLeapYear(y);
        }
        for (int m = 1; m < month; ++m) {
            days += daysInMonth(year, m);
        }
        days += day;
        return days;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func daysBetweenDates(date1 string, date2 string) int {
	return abs(calcDays(date1) - calcDays(date2))
}

func isLeapYear(year int) bool {
	return year%4 == 0 && (year%100 != 0 || year%400 == 0)
}

func daysInMonth(year, month int) int {
	days := [12]int{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
	if isLeapYear(year) {
		days[1] = 29
	}
	return days[month-1]
}

func calcDays(date string) int {
	year, _ := strconv.Atoi(date[:4])
	month, _ := strconv.Atoi(date[5:7])
	day, _ := strconv.Atoi(date[8:])
	days := 0
	for y := 1971; y < year; y++ {
		days += 365
		if isLeapYear(y) {
			days++
		}
	}
	for m := 1; m < month; m++ {
		days += daysInMonth(year, m)
	}
	days += day
	return days
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
function daysBetweenDates(date1: string, date2: string): number {
    return Math.abs(calcDays(date1) - calcDays(date2));
}

function isLeapYear(year: number): boolean {
    return year % 4 === 0 && (year % 100 !== 0 || year % 400 === 0);
}

function daysOfMonth(year: number, month: number): number {
    const days = [31, isLeapYear(year) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
    return days[month - 1];
}

function calcDays(date: string): number {
    let days = 0;
    const [year, month, day] = date.split('-').map(Number);
    for (let y = 1971; y < year; ++y) {
        days += isLeapYear(y) ? 366 : 365;
    }
    for (let m = 1; m < month; ++m) {
        days += daysOfMonth(year, m);
    }
    days += day - 1;
    return days;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>请你编写一个程序来计算两个日期之间隔了多少天。</p>

<p>日期以字符串形式给出，格式为&nbsp;<code>YYYY-MM-DD</code>，如示例所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>date1 = &quot;2019-06-29&quot;, date2 = &quot;2019-06-30&quot;
<strong>输出：</strong>1
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>date1 = &quot;2020-01-15&quot;, date2 = &quot;2019-12-31&quot;
<strong>输出：</strong>15
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>给定的日期是&nbsp;<code>1971</code>&nbsp;年到 <code>2100</code>&nbsp;年之间的有效日期。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数学

我们先定义一个函数 `isLeapYear(year)` 来判断给定的年份 `year` 是否是闰年，如果是闰年则返回 `true`，否则返回 `false`。

接下来，我们再定义一个函数 `daysInMonth(year, month)` 来计算给定的年份 `year` 和月份 `month` 一共有多少天，我们可以使用一个数组 `days` 来存储每个月份的天数，其中 `days[1]` 表示二月份的天数，如果是闰年则为 $29$ 天，否则为 $28$ 天。

然后，我们再定义一个函数 `calcDays(date)` 来计算给定的日期 `date` 距离 `1971-01-01` 有多少天，我们可以使用 `date.split("-")` 来将日期 `date` 按照 `-` 分割成年份 `year`、月份 `month` 和日期 `day`，然后我们可以使用一个循环来计算从 `1971` 年到 `year` 年一共有多少天，然后再计算从 `1` 月到 `month` 月一共有多少天，最后再加上 `day` 天即可。

最后，我们只需要返回 `calcDays(date1) - calcDays(date2)` 的绝对值即可。

时间复杂度 $O(y + m)$，其中 $y$ 表示给定的日期距离 `1971-01-01` 的年数，而 $m$ 表示给定的日期的月数。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def daysBetweenDates(self, date1: str, date2: str) -> int:
        def isLeapYear(year: int) -> bool:
            return year % 4 == 0 and (year % 100 != 0 or year % 400 == 0)

        def daysInMonth(year: int, month: int) -> int:
            days = [
                31,
                28 + int(isLeapYear(year)),
                31,
                30,
                31,
                30,
                31,
                31,
                30,
                31,
                30,
                31,
            ]
            return days[month - 1]

        def calcDays(date: str) -> int:
            year, month, day = map(int, date.split("-"))
            days = 0
            for y in range(1971, year):
                days += 365 + int(isLeapYear(y))
            for m in range(1, month):
                days += daysInMonth(year, m)
            days += day
            return days

        return abs(calcDays(date1) - calcDays(date2))
```

#### Java

```java
class Solution {
    public int daysBetweenDates(String date1, String date2) {
        return Math.abs(calcDays(date1) - calcDays(date2));
    }

    private boolean isLeapYear(int year) {
        return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
    }

    private int daysInMonth(int year, int month) {
        int[] days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        days[1] += isLeapYear(year) ? 1 : 0;
        return days[month - 1];
    }

    private int calcDays(String date) {
        int year = Integer.parseInt(date.substring(0, 4));
        int month = Integer.parseInt(date.substring(5, 7));
        int day = Integer.parseInt(date.substring(8));
        int days = 0;
        for (int y = 1971; y < year; ++y) {
            days += isLeapYear(y) ? 366 : 365;
        }
        for (int m = 1; m < month; ++m) {
            days += daysInMonth(year, m);
        }
        days += day;
        return days;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int daysBetweenDates(string date1, string date2) {
        return abs(calcDays(date1) - calcDays(date2));
    }

    bool isLeapYear(int year) {
        return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
    }

    int daysInMonth(int year, int month) {
        int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        days[1] += isLeapYear(year);
        return days[month - 1];
    }

    int calcDays(string date) {
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));
        int days = 0;
        for (int y = 1971; y < year; ++y) {
            days += 365 + isLeapYear(y);
        }
        for (int m = 1; m < month; ++m) {
            days += daysInMonth(year, m);
        }
        days += day;
        return days;
    }
};
```

#### Go

```go
func daysBetweenDates(date1 string, date2 string) int {
	return abs(calcDays(date1) - calcDays(date2))
}

func isLeapYear(year int) bool {
	return year%4 == 0 && (year%100 != 0 || year%400 == 0)
}

func daysInMonth(year, month int) int {
	days := [12]int{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
	if isLeapYear(year) {
		days[1] = 29
	}
	return days[month-1]
}

func calcDays(date string) int {
	year, _ := strconv.Atoi(date[:4])
	month, _ := strconv.Atoi(date[5:7])
	day, _ := strconv.Atoi(date[8:])
	days := 0
	for y := 1971; y < year; y++ {
		days += 365
		if isLeapYear(y) {
			days++
		}
	}
	for m := 1; m < month; m++ {
		days += daysInMonth(year, m)
	}
	days += day
	return days
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
function daysBetweenDates(date1: string, date2: string): number {
    return Math.abs(calcDays(date1) - calcDays(date2));
}

function isLeapYear(year: number): boolean {
    return year % 4 === 0 && (year % 100 !== 0 || year % 400 === 0);
}

function daysOfMonth(year: number, month: number): number {
    const days = [31, isLeapYear(year) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
    return days[month - 1];
}

function calcDays(date: string): number {
    let days = 0;
    const [year, month, day] = date.split('-').map(Number);
    for (let y = 1971; y < year; ++y) {
        days += isLeapYear(y) ? 366 : 365;
    }
    for (let m = 1; m < month; ++m) {
        days += daysOfMonth(year, m);
    }
    days += day - 1;
    return days;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1361. 验证二叉树](https://leetcode.cn/problems/validate-binary-tree-nodes){#1361}

{{< tabs "1361" >}}

{{% tab "python" %}}
```python
class Solution:
    def validateBinaryTreeNodes(
        self, n: int, leftChild: List[int], rightChild: List[int]
    ) -> bool:
        def find(x: int) -> int:
            if p[x] != x:
                p[x] = find(p[x])
            return p[x]

        p = list(range(n))
        vis = [False] * n
        for i, (a, b) in enumerate(zip(leftChild, rightChild)):
            for j in (a, b):
                if j != -1:
                    if vis[j] or find(i) == find(j):
                        return False
                    p[find(i)] = find(j)
                    vis[j] = True
                    n -= 1
        return n == 1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[] p;

    public boolean validateBinaryTreeNodes(int n, int[] leftChild, int[] rightChild) {
        p = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
        }
        boolean[] vis = new boolean[n];
        for (int i = 0, m = n; i < m; ++i) {
            for (int j : new int[] {leftChild[i], rightChild[i]}) {
                if (j != -1) {
                    if (vis[j] || find(i) == find(j)) {
                        return false;
                    }
                    p[find(i)] = find(j);
                    vis[j] = true;
                    --n;
                }
            }
        }
        return n == 1;
    }

    private int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        int p[n];
        iota(p, p + n, 0);
        bool vis[n];
        memset(vis, 0, sizeof(vis));
        function<int(int)> find = [&](int x) {
            return p[x] == x ? x : p[x] = find(p[x]);
        };
        for (int i = 0, m = n; i < m; ++i) {
            for (int j : {leftChild[i], rightChild[i]}) {
                if (j != -1) {
                    if (vis[j] || find(i) == find(j)) {
                        return false;
                    }
                    p[find(i)] = find(j);
                    vis[j] = true;
                    --n;
                }
            }
        }
        return n == 1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func validateBinaryTreeNodes(n int, leftChild []int, rightChild []int) bool {
	p := make([]int, n)
	for i := range p {
		p[i] = i
	}
	var find func(int) int
	find = func(x int) int {
		if p[x] != x {
			p[x] = find(p[x])
		}
		return p[x]
	}
	vis := make([]bool, n)
	for i, a := range leftChild {
		for _, j := range []int{a, rightChild[i]} {
			if j != -1 {
				if vis[j] || find(i) == find(j) {
					return false
				}
				p[find(i)] = find(j)
				vis[j] = true
				n--
			}
		}
	}
	return n == 1
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>二叉树上有 <code>n</code>&nbsp;个节点，按从&nbsp;<code>0</code>&nbsp;到 <code>n - 1</code>&nbsp;编号，其中节点&nbsp;<code>i</code>&nbsp;的两个子节点分别是&nbsp;<code>leftChild[i]</code>&nbsp;和&nbsp;<code>rightChild[i]</code>。</p>

<p>只有 <strong>所有</strong> 节点能够形成且 <strong>只</strong> 形成 <strong>一颗</strong>&nbsp;有效的二叉树时，返回&nbsp;<code>true</code>；否则返回 <code>false</code>。</p>

<p>如果节点&nbsp;<code>i</code>&nbsp;没有左子节点，那么&nbsp;<code>leftChild[i]</code>&nbsp;就等于&nbsp;<code>-1</code>。右子节点也符合该规则。</p>

<p>注意：节点没有值，本问题中仅仅使用节点编号。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1300-1399/1361.Validate%20Binary%20Tree%20Nodes/images/1503_ex1.png" style="height: 287px; width: 195px;" /></strong></p>

<pre>
<strong>输入：</strong>n = 4, leftChild = [1,-1,3,-1], rightChild = [2,-1,-1,-1]
<strong>输出：</strong>true
</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1300-1399/1361.Validate%20Binary%20Tree%20Nodes/images/1503_ex2.png" style="height: 272px; width: 183px;" /></strong></p>

<pre>
<strong>输入：</strong>n = 4, leftChild = [1,-1,3,-1], rightChild = [2,3,-1,-1]
<strong>输出：</strong>false
</pre>

<p><strong>示例 3：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1300-1399/1361.Validate%20Binary%20Tree%20Nodes/images/1503_ex3.png" style="height: 174px; width: 82px;" /></strong></p>

<pre>
<strong>输入：</strong>n = 2, leftChild = [1,0], rightChild = [-1,-1]
<strong>输出：</strong>false
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == leftChild.length == rightChild.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>-1 &lt;= leftChild[i], rightChild[i] &lt;= n - 1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：并查集

我们可以遍历每个节点 $i$ 以及对应的左右孩子 $l$, $r$，用 $vis$ 数组记录节点是否有父节点：

-   若孩子节点已存在父节点，说明有多个父亲，不满足条件，直接返回 `false`。
-   若孩子节点与父节点已经处于同一个连通分量，说明会形成环，不满足条件，直接返回 `false`。
-   否则，进行合并，并且将 $vis$ 数组对应位置置为 `true`，同时将连通分量个数减去 $1$。

遍历结束，判断并查集中连通分量个数是否为 $1$，若是返回 `true`，否则返回 `false`。

时间复杂度 $O(n \times \alpha(n))$，空间复杂度 $O(n)$。其中 $n$ 为节点个数，而 $\alpha(n)$ 为阿克曼函数的反函数，即反阿克曼函数，其值小于 $5$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def validateBinaryTreeNodes(
        self, n: int, leftChild: List[int], rightChild: List[int]
    ) -> bool:
        def find(x: int) -> int:
            if p[x] != x:
                p[x] = find(p[x])
            return p[x]

        p = list(range(n))
        vis = [False] * n
        for i, (a, b) in enumerate(zip(leftChild, rightChild)):
            for j in (a, b):
                if j != -1:
                    if vis[j] or find(i) == find(j):
                        return False
                    p[find(i)] = find(j)
                    vis[j] = True
                    n -= 1
        return n == 1
```

#### Java

```java
class Solution {
    private int[] p;

    public boolean validateBinaryTreeNodes(int n, int[] leftChild, int[] rightChild) {
        p = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
        }
        boolean[] vis = new boolean[n];
        for (int i = 0, m = n; i < m; ++i) {
            for (int j : new int[] {leftChild[i], rightChild[i]}) {
                if (j != -1) {
                    if (vis[j] || find(i) == find(j)) {
                        return false;
                    }
                    p[find(i)] = find(j);
                    vis[j] = true;
                    --n;
                }
            }
        }
        return n == 1;
    }

    private int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        int p[n];
        iota(p, p + n, 0);
        bool vis[n];
        memset(vis, 0, sizeof(vis));
        function<int(int)> find = [&](int x) {
            return p[x] == x ? x : p[x] = find(p[x]);
        };
        for (int i = 0, m = n; i < m; ++i) {
            for (int j : {leftChild[i], rightChild[i]}) {
                if (j != -1) {
                    if (vis[j] || find(i) == find(j)) {
                        return false;
                    }
                    p[find(i)] = find(j);
                    vis[j] = true;
                    --n;
                }
            }
        }
        return n == 1;
    }
};
```

#### Go

```go
func validateBinaryTreeNodes(n int, leftChild []int, rightChild []int) bool {
	p := make([]int, n)
	for i := range p {
		p[i] = i
	}
	var find func(int) int
	find = func(x int) int {
		if p[x] != x {
			p[x] = find(p[x])
		}
		return p[x]
	}
	vis := make([]bool, n)
	for i, a := range leftChild {
		for _, j := range []int{a, rightChild[i]} {
			if j != -1 {
				if vis[j] || find(i) == find(j) {
					return false
				}
				p[find(i)] = find(j)
				vis[j] = true
				n--
			}
		}
	}
	return n == 1
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1362. 最接近的因数](https://leetcode.cn/problems/closest-divisors){#1362}

{{< tabs "1362" >}}

{{% tab "python" %}}
```python
class Solution:
    def closestDivisors(self, num: int) -> List[int]:
        def f(x):
            for i in range(int(sqrt(x)), 0, -1):
                if x % i == 0:
                    return [i, x // i]

        a = f(num + 1)
        b = f(num + 2)
        return a if abs(a[0] - a[1]) < abs(b[0] - b[1]) else b
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] closestDivisors(int num) {
        int[] a = f(num + 1);
        int[] b = f(num + 2);
        return Math.abs(a[0] - a[1]) < Math.abs(b[0] - b[1]) ? a : b;
    }

    private int[] f(int x) {
        for (int i = (int) Math.sqrt(x);; --i) {
            if (x % i == 0) {
                return new int[] {i, x / i};
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
    vector<int> closestDivisors(int num) {
        auto f = [](int x) {
            for (int i = sqrt(x);; --i) {
                if (x % i == 0) {
                    return vector<int>{i, x / i};
                }
            }
        };
        vector<int> a = f(num + 1);
        vector<int> b = f(num + 2);
        return abs(a[0] - a[1]) < abs(b[0] - b[1]) ? a : b;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func closestDivisors(num int) []int {
	f := func(x int) []int {
		for i := int(math.Sqrt(float64(x))); ; i-- {
			if x%i == 0 {
				return []int{i, x / i}
			}
		}
	}
	a, b := f(num+1), f(num+2)
	if abs(a[0]-a[1]) < abs(b[0]-b[1]) {
		return a
	}
	return b
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数&nbsp;<code>num</code>，请你找出同时满足下面全部要求的两个整数：</p>

<ul>
	<li>两数乘积等于 &nbsp;<code>num + 1</code>&nbsp;或&nbsp;<code>num + 2</code></li>
	<li>以绝对差进行度量，两数大小最接近</li>
</ul>

<p>你可以按任意顺序返回这两个整数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>num = 8
<strong>输出：</strong>[3,3]
<strong>解释：</strong>对于 num + 1 = 9，最接近的两个因数是 3 &amp; 3；对于 num + 2 = 10, 最接近的两个因数是 2 &amp; 5，因此返回 3 &amp; 3 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>num = 123
<strong>输出：</strong>[5,25]
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>num = 999
<strong>输出：</strong>[40,25]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= num &lt;= 10^9</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举

我们设计一个函数 $f(x)$，该函数返回乘积等于 $x$ 的两个数，且这两个数的差的绝对值最小。我们可以从 $\sqrt{x}$ 开始枚举 $i$，如果 $x$ 能被 $i$ 整除，那么 $\frac{x}{i}$ 就是另一个因数，此时我们就找到了一个乘积等于 $x$ 的两个因数，我们将其返回即可。否则我们减小 $i$ 的值，继续枚举。

接下来，我们只需要分别计算 $f(num + 1)$ 和 $f(num + 2)$，然后比较两个函数的返回值，返回差的绝对值更小的那个即可。

时间复杂度 $O(\sqrt{num})$，空间复杂度 $O(1)$。其中 $num$ 是给定的整数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def closestDivisors(self, num: int) -> List[int]:
        def f(x):
            for i in range(int(sqrt(x)), 0, -1):
                if x % i == 0:
                    return [i, x // i]

        a = f(num + 1)
        b = f(num + 2)
        return a if abs(a[0] - a[1]) < abs(b[0] - b[1]) else b
```

#### Java

```java
class Solution {
    public int[] closestDivisors(int num) {
        int[] a = f(num + 1);
        int[] b = f(num + 2);
        return Math.abs(a[0] - a[1]) < Math.abs(b[0] - b[1]) ? a : b;
    }

    private int[] f(int x) {
        for (int i = (int) Math.sqrt(x);; --i) {
            if (x % i == 0) {
                return new int[] {i, x / i};
            }
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> closestDivisors(int num) {
        auto f = [](int x) {
            for (int i = sqrt(x);; --i) {
                if (x % i == 0) {
                    return vector<int>{i, x / i};
                }
            }
        };
        vector<int> a = f(num + 1);
        vector<int> b = f(num + 2);
        return abs(a[0] - a[1]) < abs(b[0] - b[1]) ? a : b;
    }
};
```

#### Go

```go
func closestDivisors(num int) []int {
	f := func(x int) []int {
		for i := int(math.Sqrt(float64(x))); ; i-- {
			if x%i == 0 {
				return []int{i, x / i}
			}
		}
	}
	a, b := f(num+1), f(num+2)
	if abs(a[0]-a[1]) < abs(b[0]-b[1]) {
		return a
	}
	return b
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1363. 形成三的最大倍数](https://leetcode.cn/problems/largest-multiple-of-three){#1363}

{{< tabs "1363" >}}

{{% tab "python" %}}
```python
class Solution:
    def largestMultipleOfThree(self, digits: List[int]) -> str:
        digits.sort()
        n = len(digits)
        f = [[-inf] * 3 for _ in range(n + 1)]
        f[0][0] = 0
        for i, x in enumerate(digits, 1):
            for j in range(3):
                f[i][j] = max(f[i - 1][j], f[i - 1][(j - x % 3 + 3) % 3] + 1)
        if f[n][0] <= 0:
            return ""
        arr = []
        j = 0
        for i in range(n, 0, -1):
            k = (j - digits[i - 1] % 3 + 3) % 3
            if f[i - 1][k] + 1 == f[i][j]:
                arr.append(digits[i - 1])
                j = k
        i = 0
        while i < len(arr) - 1 and arr[i] == 0:
            i += 1
        return "".join(map(str, arr[i:]))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String largestMultipleOfThree(int[] digits) {
        Arrays.sort(digits);
        int n = digits.length;
        int[][] f = new int[n + 1][3];
        final int inf = 1 << 30;
        for (var g : f) {
            Arrays.fill(g, -inf);
        }
        f[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 3; ++j) {
                f[i][j] = Math.max(f[i - 1][j], f[i - 1][(j - digits[i - 1] % 3 + 3) % 3] + 1);
            }
        }
        if (f[n][0] <= 0) {
            return "";
        }
        StringBuilder sb = new StringBuilder();
        for (int i = n, j = 0; i > 0; --i) {
            int k = (j - digits[i - 1] % 3 + 3) % 3;
            if (f[i - 1][k] + 1 == f[i][j]) {
                sb.append(digits[i - 1]);
                j = k;
            }
        }
        int i = 0;
        while (i < sb.length() - 1 && sb.charAt(i) == '0') {
            ++i;
        }
        return sb.substring(i);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        sort(digits.begin(), digits.end());
        int n = digits.size();
        int f[n + 1][3];
        memset(f, -0x3f, sizeof(f));
        f[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 3; ++j) {
                f[i][j] = max(f[i - 1][j], f[i - 1][(j - digits[i - 1] % 3 + 3) % 3] + 1);
            }
        }
        if (f[n][0] <= 0) {
            return "";
        }
        string ans;
        for (int i = n, j = 0; i; --i) {
            int k = (j - digits[i - 1] % 3 + 3) % 3;
            if (f[i - 1][k] + 1 == f[i][j]) {
                ans += digits[i - 1] + '0';
                j = k;
            }
        }
        int i = 0;
        while (i < ans.size() - 1 && ans[i] == '0') {
            ++i;
        }
        return ans.substr(i);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func largestMultipleOfThree(digits []int) string {
	sort.Ints(digits)
	n := len(digits)
	const inf = 1 << 30
	f := make([][]int, n+1)
	for i := range f {
		f[i] = make([]int, 3)
		for j := range f[i] {
			f[i][j] = -inf
		}
	}
	f[0][0] = 0
	for i := 1; i <= n; i++ {
		for j := 0; j < 3; j++ {
			f[i][j] = max(f[i-1][j], f[i-1][(j-digits[i-1]%3+3)%3]+1)
		}
	}
	if f[n][0] <= 0 {
		return ""
	}
	ans := []byte{}
	for i, j := n, 0; i > 0; i-- {
		k := (j - digits[i-1]%3 + 3) % 3
		if f[i][j] == f[i-1][k]+1 {
			ans = append(ans, byte('0'+digits[i-1]))
			j = k
		}
	}
	i := 0
	for i < len(ans)-1 && ans[i] == '0' {
		i++
	}
	return string(ans[i:])
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function largestMultipleOfThree(digits: number[]): string {
    digits.sort((a, b) => a - b);
    const n = digits.length;
    const f: number[][] = new Array(n + 1).fill(0).map(() => new Array(3).fill(-Infinity));
    f[0][0] = 0;
    for (let i = 1; i <= n; ++i) {
        for (let j = 0; j < 3; ++j) {
            f[i][j] = Math.max(f[i - 1][j], f[i - 1][(j - (digits[i - 1] % 3) + 3) % 3] + 1);
        }
    }
    if (f[n][0] <= 0) {
        return '';
    }
    const arr: number[] = [];
    for (let i = n, j = 0; i; --i) {
        const k = (j - (digits[i - 1] % 3) + 3) % 3;
        if (f[i - 1][k] + 1 === f[i][j]) {
            arr.push(digits[i - 1]);
            j = k;
        }
    }
    let i = 0;
    while (i < arr.length - 1 && arr[i] === 0) {
        ++i;
    }
    return arr.slice(i).join('');
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组&nbsp;<code>digits</code>，你可以通过按 <strong>任意顺序</strong> 连接其中某些数字来形成 <strong>3</strong> 的倍数，请你返回所能得到的最大的 3 的倍数。</p>

<p>由于答案可能不在整数数据类型范围内，请以字符串形式返回答案。如果无法得到答案，请返回一个空字符串。返回的结果不应包含不必要的前导零。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>digits = [8,1,9]
<strong>输出：</strong>"981"
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>digits = [8,6,7,1,0]
<strong>输出：</strong>"8760"
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>digits = [1]
<strong>输出：</strong>""
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>digits = [0,0,0,0,0,0]
<strong>输出：</strong>"0"
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= digits.length &lt;= 10^4</code></li>
	<li><code>0 &lt;= digits[i] &lt;= 9</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 动态规划 + 逆推

我们定义 $f[i][j]$ 表示在前 $i$ 个数中选取若干个数，使得选取的数的和模 $3$ 为 $j$ 的最大长度。为了使得选取的数最大，我们需要尽可能选取更多的数，因此我们需要使得 $f[i][j]$ 尽可能大。我们初始化 $f[0][0] = 0$，其余的 $f[0][j] = -\infty$。

考虑 $f[i][j]$ 如何进行状态转移。我们可以不选取第 $i$ 个数，此时 $f[i][j] = f[i - 1][j]$；我们也可以选取第 $i$ 个数，此时 $f[i][j] = f[i - 1][(j - x_i \bmod 3 + 3) \bmod 3] + 1$，其中 $x_i$ 表示第 $i$ 个数的值。因此我们有如下的状态转移方程：

$$
f[i][j] = \max \{ f[i - 1][j], f[i - 1][(j - x_i \bmod 3 + 3) \bmod 3] + 1 \}
$$

如果 $f[n][0] \le 0$，那么我们无法选取任何数，因此答案字符串为空。否则我们可以通过 $f$ 数组进行逆推，找出选取的数。

定义 $i = n$, $j = 0$，从 $f[i][j]$ 开始逆推，记 $k = (j - x_i \bmod 3 + 3) \bmod 3$，如果 $f[i - 1][k] + 1 = f[i][j]$，那么我们选取了第 $i$ 个数，否则我们没有选取第 $i$ 个数。如果我们选取了第 $i$ 个数，那么我们将 $j$ 更新为 $k$，否则我们保持 $j$ 不变。为了使得同等长度的数最大，我们应该优先选取较大的数，因此，我们在前面首先对数组进行排序。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def largestMultipleOfThree(self, digits: List[int]) -> str:
        digits.sort()
        n = len(digits)
        f = [[-inf] * 3 for _ in range(n + 1)]
        f[0][0] = 0
        for i, x in enumerate(digits, 1):
            for j in range(3):
                f[i][j] = max(f[i - 1][j], f[i - 1][(j - x % 3 + 3) % 3] + 1)
        if f[n][0] <= 0:
            return ""
        arr = []
        j = 0
        for i in range(n, 0, -1):
            k = (j - digits[i - 1] % 3 + 3) % 3
            if f[i - 1][k] + 1 == f[i][j]:
                arr.append(digits[i - 1])
                j = k
        i = 0
        while i < len(arr) - 1 and arr[i] == 0:
            i += 1
        return "".join(map(str, arr[i:]))
```

#### Java

```java
class Solution {
    public String largestMultipleOfThree(int[] digits) {
        Arrays.sort(digits);
        int n = digits.length;
        int[][] f = new int[n + 1][3];
        final int inf = 1 << 30;
        for (var g : f) {
            Arrays.fill(g, -inf);
        }
        f[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 3; ++j) {
                f[i][j] = Math.max(f[i - 1][j], f[i - 1][(j - digits[i - 1] % 3 + 3) % 3] + 1);
            }
        }
        if (f[n][0] <= 0) {
            return "";
        }
        StringBuilder sb = new StringBuilder();
        for (int i = n, j = 0; i > 0; --i) {
            int k = (j - digits[i - 1] % 3 + 3) % 3;
            if (f[i - 1][k] + 1 == f[i][j]) {
                sb.append(digits[i - 1]);
                j = k;
            }
        }
        int i = 0;
        while (i < sb.length() - 1 && sb.charAt(i) == '0') {
            ++i;
        }
        return sb.substring(i);
    }
}
```

#### C++

```cpp
class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        sort(digits.begin(), digits.end());
        int n = digits.size();
        int f[n + 1][3];
        memset(f, -0x3f, sizeof(f));
        f[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 3; ++j) {
                f[i][j] = max(f[i - 1][j], f[i - 1][(j - digits[i - 1] % 3 + 3) % 3] + 1);
            }
        }
        if (f[n][0] <= 0) {
            return "";
        }
        string ans;
        for (int i = n, j = 0; i; --i) {
            int k = (j - digits[i - 1] % 3 + 3) % 3;
            if (f[i - 1][k] + 1 == f[i][j]) {
                ans += digits[i - 1] + '0';
                j = k;
            }
        }
        int i = 0;
        while (i < ans.size() - 1 && ans[i] == '0') {
            ++i;
        }
        return ans.substr(i);
    }
};
```

#### Go

```go
func largestMultipleOfThree(digits []int) string {
	sort.Ints(digits)
	n := len(digits)
	const inf = 1 << 30
	f := make([][]int, n+1)
	for i := range f {
		f[i] = make([]int, 3)
		for j := range f[i] {
			f[i][j] = -inf
		}
	}
	f[0][0] = 0
	for i := 1; i <= n; i++ {
		for j := 0; j < 3; j++ {
			f[i][j] = max(f[i-1][j], f[i-1][(j-digits[i-1]%3+3)%3]+1)
		}
	}
	if f[n][0] <= 0 {
		return ""
	}
	ans := []byte{}
	for i, j := n, 0; i > 0; i-- {
		k := (j - digits[i-1]%3 + 3) % 3
		if f[i][j] == f[i-1][k]+1 {
			ans = append(ans, byte('0'+digits[i-1]))
			j = k
		}
	}
	i := 0
	for i < len(ans)-1 && ans[i] == '0' {
		i++
	}
	return string(ans[i:])
}
```

#### TypeScript

```ts
function largestMultipleOfThree(digits: number[]): string {
    digits.sort((a, b) => a - b);
    const n = digits.length;
    const f: number[][] = new Array(n + 1).fill(0).map(() => new Array(3).fill(-Infinity));
    f[0][0] = 0;
    for (let i = 1; i <= n; ++i) {
        for (let j = 0; j < 3; ++j) {
            f[i][j] = Math.max(f[i - 1][j], f[i - 1][(j - (digits[i - 1] % 3) + 3) % 3] + 1);
        }
    }
    if (f[n][0] <= 0) {
        return '';
    }
    const arr: number[] = [];
    for (let i = n, j = 0; i; --i) {
        const k = (j - (digits[i - 1] % 3) + 3) % 3;
        if (f[i - 1][k] + 1 === f[i][j]) {
            arr.push(digits[i - 1]);
            j = k;
        }
    }
    let i = 0;
    while (i < arr.length - 1 && arr[i] === 0) {
        ++i;
    }
    return arr.slice(i).join('');
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1364. 顾客的可信联系人数量 🔒](https://leetcode.cn/problems/number-of-trusted-contacts-of-a-customer){#1364}

{{< tabs "1364" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT
    invoice_id,
    t2.customer_name,
    price,
    COUNT(t3.user_id) AS contacts_cnt,
    COUNT(t4.email) AS trusted_contacts_cnt
FROM
    Invoices AS t1
    LEFT JOIN Customers AS t2 ON t1.user_id = t2.customer_id
    LEFT JOIN Contacts AS t3 ON t1.user_id = t3.user_id
    LEFT JOIN Customers AS t4 ON t3.contact_email = t4.email
GROUP BY invoice_id
ORDER BY invoice_id;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>顾客表：<code>Customers</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| customer_id   | int     |
| customer_name | varchar |
| email         | varchar |
+---------------+---------+
customer_id 是这张表具有唯一值的列。
此表的每一行包含了某在线商店顾客的姓名和电子邮件。
</pre>

<p>&nbsp;</p>

<p>联系方式表：<code>Contacts</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| user_id       | id      |
| contact_name  | varchar |
| contact_email | varchar |
+---------------+---------+
(user_id, contact_email) 是这张表的主键（具有唯一值的列的组合）。
此表的每一行表示编号为 user_id 的顾客的某位联系人的姓名和电子邮件。
此表包含每位顾客的联系人信息，但顾客的联系人不一定存在于顾客表中。
</pre>

<p>&nbsp;</p>

<p>发票表：<code>Invoices</code></p>

<pre>
+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| invoice_id   | int     |
| price        | int     |
| user_id      | int     |
+--------------+---------+
invoice_id 是这张表具有唯一值的列。
此表的每一行分别表示编号为 user_id 的顾客拥有有一张编号为 invoice_id、价格为 price 的发票。
</pre>

<p>&nbsp;</p>

<p>为每张发票 <code>invoice_id</code> 编写一个查询方案以查找以下内容：</p>

<ul>
	<li><code>customer_name</code>：与发票相关的顾客名称。</li>
	<li><code>price</code>：发票的价格。</li>
	<li><code>contacts_cnt</code>：该顾客的联系人数量</li>
	<li><code>trusted_contacts_cnt</code>：可信联系人的数量：既是该顾客的联系人又是商店顾客的联系人数量（即：可信联系人的电子邮件存在于 <meta charset="UTF-8" />&nbsp;<code>Customers</code>&nbsp;表中）。</li>
</ul>

<p>返回结果按照&nbsp;<code>invoice_id</code>&nbsp;<strong>排序</strong>。</p>

<p>结果的格式如下例所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
<code>Customers</code> table:
+-------------+---------------+--------------------+
| customer_id | customer_name | email              |
+-------------+---------------+--------------------+
| 1           | Alice         | alice@leetcode.com |
| 2           | Bob           | bob@leetcode.com   |
| 13          | John          | john@leetcode.com  |
| 6           | Alex          | alex@leetcode.com  |
+-------------+---------------+--------------------+
Contacts table:
+-------------+--------------+--------------------+
| user_id     | contact_name | contact_email      |
+-------------+--------------+--------------------+
| 1           | Bob          | bob@leetcode.com   |
| 1           | John         | john@leetcode.com  |
| 1           | Jal          | jal@leetcode.com   |
| 2           | Omar         | omar@leetcode.com  |
| 2           | Meir         | meir@leetcode.com  |
| 6           | Alice        | alice@leetcode.com |
+-------------+--------------+--------------------+
Invoices table:
+------------+-------+---------+
| invoice_id | price | user_id |
+------------+-------+---------+
| 77         | 100   | 1       |
| 88         | 200   | 1       |
| 99         | 300   | 2       |
| 66         | 400   | 2       |
| 55         | 500   | 13      |
| 44         | 60    | 6       |
+------------+-------+---------+
<strong>输出：</strong>
+------------+---------------+-------+--------------+----------------------+
| invoice_id | customer_name | price | contacts_cnt | trusted_contacts_cnt |
+------------+---------------+-------+--------------+----------------------+
| 44         | Alex          | 60    | 1            | 1                    |
| 55         | John          | 500   | 0            | 0                    |
| 66         | Bob           | 400   | 2            | 0                    |
| 77         | Alice         | 100   | 3            | 2                    |
| 88         | Alice         | 200   | 3            | 2                    |
| 99         | Bob           | 300   | 2            | 0                    |
+------------+---------------+-------+--------------+----------------------+
<strong>解释：</strong>
Alice 有三位联系人，其中两位(Bob 和 John)是可信联系人。
Bob 有两位联系人, 他们中的任何一位都不是可信联系人。
Alex 只有一位联系人(Alice)，并是一位可信联系人。
John 没有任何联系人。
</pre>

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
SELECT
    invoice_id,
    t2.customer_name,
    price,
    COUNT(t3.user_id) AS contacts_cnt,
    COUNT(t4.email) AS trusted_contacts_cnt
FROM
    Invoices AS t1
    LEFT JOIN Customers AS t2 ON t1.user_id = t2.customer_id
    LEFT JOIN Contacts AS t3 ON t1.user_id = t3.user_id
    LEFT JOIN Customers AS t4 ON t3.contact_email = t4.email
GROUP BY invoice_id
ORDER BY invoice_id;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1365. 有多少小于当前数字的数字](https://leetcode.cn/problems/how-many-numbers-are-smaller-than-the-current-number){#1365}

{{< tabs "1365" >}}

{{% tab "python" %}}
```python
class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        cnt = [0] * 102
        for x in nums:
            cnt[x + 1] += 1
        s = list(accumulate(cnt))
        return [s[x] for x in nums]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] smallerNumbersThanCurrent(int[] nums) {
        int[] cnt = new int[102];
        for (int x : nums) {
            ++cnt[x + 1];
        }
        for (int i = 1; i < cnt.length; ++i) {
            cnt[i] += cnt[i - 1];
        }
        int n = nums.length;
        int[] ans = new int[n];
        for (int i = 0; i < n; ++i) {
            ans[i] = cnt[nums[i]];
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
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int cnt[102]{};
        for (int& x : nums) {
            ++cnt[x + 1];
        }
        for (int i = 1; i < 102; ++i) {
            cnt[i] += cnt[i - 1];
        }
        vector<int> ans;
        for (int& x : nums) {
            ans.push_back(cnt[x]);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func smallerNumbersThanCurrent(nums []int) (ans []int) {
	cnt := [102]int{}
	for _, x := range nums {
		cnt[x+1]++
	}
	for i := 1; i < len(cnt); i++ {
		cnt[i] += cnt[i-1]
	}
	for _, x := range nums {
		ans = append(ans, cnt[x])
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function smallerNumbersThanCurrent(nums: number[]): number[] {
    const cnt: number[] = new Array(102).fill(0);
    for (const x of nums) {
        ++cnt[x + 1];
    }
    for (let i = 1; i < cnt.length; ++i) {
        cnt[i] += cnt[i - 1];
    }
    const n = nums.length;
    const ans: number[] = new Array(n);
    for (let i = 0; i < n; ++i) {
        ans[i] = cnt[nums[i]];
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

<p>给你一个数组&nbsp;<code>nums</code>，对于其中每个元素&nbsp;<code>nums[i]</code>，请你统计数组中比它小的所有数字的数目。</p>

<p>换而言之，对于每个&nbsp;<code>nums[i]</code>&nbsp;你必须计算出有效的&nbsp;<code>j</code>&nbsp;的数量，其中 <code>j</code> 满足&nbsp;<code>j != i</code> <strong>且</strong> <code>nums[j] &lt; nums[i]</code>&nbsp;。</p>

<p>以数组形式返回答案。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [8,1,2,2,3]
<strong>输出：</strong>[4,0,1,1,3]
<strong>解释：</strong> 
对于 nums[0]=8 存在四个比它小的数字：（1，2，2 和 3）。 
对于 nums[1]=1 不存在比它小的数字。
对于 nums[2]=2 存在一个比它小的数字：（1）。 
对于 nums[3]=2 存在一个比它小的数字：（1）。 
对于 nums[4]=3 存在三个比它小的数字：（1，2 和 2）。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [6,5,4,8]
<strong>输出：</strong>[2,1,0,3]
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>nums = [7,7,7,7]
<strong>输出：</strong>[0,0,0,0]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 500</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 二分查找

我们可以将数组 $nums$ 复制一份，记为 $arr$，然后对 $arr$ 进行升序排序。

接下来，对于 $nums$ 中的每个元素 $x$，我们可以通过二分查找的方法找到第一个大于等于 $x$ 的元素的下标 $j$，那么 $j$ 就是比 $x$ 小的元素的个数，我们将 $j$ 存入答案数组中即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        arr = sorted(nums)
        return [bisect_left(arr, x) for x in nums]
```

#### Java

```java
class Solution {
    public int[] smallerNumbersThanCurrent(int[] nums) {
        int[] arr = nums.clone();
        Arrays.sort(arr);
        for (int i = 0; i < nums.length; ++i) {
            nums[i] = search(arr, nums[i]);
        }
        return nums;
    }

    private int search(int[] nums, int x) {
        int l = 0, r = nums.length;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] >= x) {
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
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> arr = nums;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < nums.size(); ++i) {
            nums[i] = lower_bound(arr.begin(), arr.end(), nums[i]) - arr.begin();
        }
        return nums;
    }
};
```

#### Go

```go
func smallerNumbersThanCurrent(nums []int) (ans []int) {
	arr := make([]int, len(nums))
	copy(arr, nums)
	sort.Ints(arr)
	for i, x := range nums {
		nums[i] = sort.SearchInts(arr, x)
	}
	return nums
}
```

#### TypeScript

```ts
function smallerNumbersThanCurrent(nums: number[]): number[] {
    const search = (nums: number[], x: number) => {
        let l = 0,
            r = nums.length;
        while (l < r) {
            const mid = (l + r) >> 1;
            if (nums[mid] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    };
    const arr = nums.slice().sort((a, b) => a - b);
    for (let i = 0; i < nums.length; ++i) {
        nums[i] = search(arr, nums[i]);
    }
    return nums;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：计数排序 + 前缀和

我们注意到数组 $nums$ 中的元素的范围是 $[0, 100]$，因此我们可以使用计数排序的方法，先统计数组 $nums$ 中每个元素的个数。然后对计数数组进行前缀和计算，最后遍历数组 $nums$，对于每个元素 $x$，我们直接将计数数组中下标为 $x$ 的元素的值加入答案数组即可。

时间复杂度 $O(n + M)$，空间复杂度 $O(M)$，其中 $n$ 和 $M$ 分别是数组 $nums$ 的长度和最大值。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        cnt = [0] * 102
        for x in nums:
            cnt[x + 1] += 1
        s = list(accumulate(cnt))
        return [s[x] for x in nums]
```

#### Java

```java
class Solution {
    public int[] smallerNumbersThanCurrent(int[] nums) {
        int[] cnt = new int[102];
        for (int x : nums) {
            ++cnt[x + 1];
        }
        for (int i = 1; i < cnt.length; ++i) {
            cnt[i] += cnt[i - 1];
        }
        int n = nums.length;
        int[] ans = new int[n];
        for (int i = 0; i < n; ++i) {
            ans[i] = cnt[nums[i]];
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int cnt[102]{};
        for (int& x : nums) {
            ++cnt[x + 1];
        }
        for (int i = 1; i < 102; ++i) {
            cnt[i] += cnt[i - 1];
        }
        vector<int> ans;
        for (int& x : nums) {
            ans.push_back(cnt[x]);
        }
        return ans;
    }
};
```

#### Go

```go
func smallerNumbersThanCurrent(nums []int) (ans []int) {
	cnt := [102]int{}
	for _, x := range nums {
		cnt[x+1]++
	}
	for i := 1; i < len(cnt); i++ {
		cnt[i] += cnt[i-1]
	}
	for _, x := range nums {
		ans = append(ans, cnt[x])
	}
	return
}
```

#### TypeScript

```ts
function smallerNumbersThanCurrent(nums: number[]): number[] {
    const cnt: number[] = new Array(102).fill(0);
    for (const x of nums) {
        ++cnt[x + 1];
    }
    for (let i = 1; i < cnt.length; ++i) {
        cnt[i] += cnt[i - 1];
    }
    const n = nums.length;
    const ans: number[] = new Array(n);
    for (let i = 0; i < n; ++i) {
        ans[i] = cnt[nums[i]];
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1366. 通过投票对团队排名](https://leetcode.cn/problems/rank-teams-by-votes){#1366}

{{< tabs "1366" >}}

{{% tab "python" %}}
```python
class Solution:
    def rankTeams(self, votes: List[str]) -> str:
        m = len(votes[0])
        cnt = defaultdict(lambda: [0] * m)
        for vote in votes:
            for i, c in enumerate(vote):
                cnt[c][i] += 1
        return "".join(sorted(cnt, key=lambda c: (cnt[c], -ord(c)), reverse=True))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String rankTeams(String[] votes) {
        int m = votes[0].length();
        int[][] cnt = new int[26][m + 1];
        for (var vote : votes) {
            for (int i = 0; i < m; ++i) {
                ++cnt[vote.charAt(i) - 'A'][i];
            }
        }
        Character[] s = new Character[m];
        for (int i = 0; i < m; ++i) {
            s[i] = votes[0].charAt(i);
        }
        Arrays.sort(s, (a, b) -> {
            int i = a - 'A', j = b - 'A';
            for (int k = 0; k < m; ++k) {
                if (cnt[i][k] != cnt[j][k]) {
                    return cnt[j][k] - cnt[i][k];
                }
            }
            return a - b;
        });
        StringBuilder ans = new StringBuilder();
        for (var c : s) {
            ans.append(c);
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
    string rankTeams(vector<string>& votes) {
        int m = votes[0].size();
        array<array<int, 27>, 26> cnt{};

        for (const auto& vote : votes) {
            for (int i = 0; i < m; ++i) {
                ++cnt[vote[i] - 'A'][i];
            }
        }
        string s = votes[0];
        ranges::sort(s, [&](char a, char b) {
            int i = a - 'A', j = b - 'A';
            for (int k = 0; k < m; ++k) {
                if (cnt[i][k] != cnt[j][k]) {
                    return cnt[i][k] > cnt[j][k];
                }
            }
            return a < b;
        });
        return string(s.begin(), s.end());
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func rankTeams(votes []string) string {
	m := len(votes[0])
	cnt := [26][27]int{}
	for _, vote := range votes {
		for i, ch := range vote {
			cnt[ch-'A'][i]++
		}
	}
	s := []rune(votes[0])
	sort.Slice(s, func(i, j int) bool {
		a, b := s[i]-'A', s[j]-'A'
		for k := 0; k < m; k++ {
			if cnt[a][k] != cnt[b][k] {
				return cnt[a][k] > cnt[b][k]
			}
		}
		return s[i] < s[j]
	})
	return string(s)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function rankTeams(votes: string[]): string {
    const m = votes[0].length;
    const cnt: number[][] = Array.from({ length: 26 }, () => Array(m + 1).fill(0));
    for (const vote of votes) {
        for (let i = 0; i < m; i++) {
            cnt[vote.charCodeAt(i) - 65][i]++;
        }
    }
    const s: string[] = votes[0].split('');
    s.sort((a, b) => {
        const i = a.charCodeAt(0) - 65;
        const j = b.charCodeAt(0) - 65;
        for (let k = 0; k < m; k++) {
            if (cnt[i][k] !== cnt[j][k]) {
                return cnt[j][k] - cnt[i][k];
            }
        }
        return a.localeCompare(b);
    });
    return s.join('');
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn rank_teams(votes: Vec<String>) -> String {
        let m = votes[0].len();
        let mut cnt = vec![vec![0; m + 1]; 26];

        for vote in &votes {
            for (i, ch) in vote.chars().enumerate() {
                cnt[(ch as u8 - b'A') as usize][i] += 1;
            }
        }

        let mut s: Vec<char> = votes[0].chars().collect();

        s.sort_by(|&a, &b| {
            let i = (a as u8 - b'A') as usize;
            let j = (b as u8 - b'A') as usize;

            for k in 0..m {
                if cnt[i][k] != cnt[j][k] {
                    return cnt[j][k].cmp(&cnt[i][k]);
                }
            }
            a.cmp(&b)
        });

        s.into_iter().collect()
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>现在有一个特殊的排名系统，依据参赛团队在投票人心中的次序进行排名，每个投票者都需要按从高到低的顺序对参与排名的所有团队进行排位。</p>

<p>排名规则如下：</p>

<ul>
	<li>参赛团队的排名次序依照其所获「排位第一」的票的多少决定。如果存在多个团队并列的情况，将继续考虑其「排位第二」的票的数量。以此类推，直到不再存在并列的情况。</li>
	<li>如果在考虑完所有投票情况后仍然出现并列现象，则根据团队字母的字母顺序进行排名。</li>
</ul>

<p>给你一个字符串数组&nbsp;<code>votes</code> 代表全体投票者给出的排位情况，请你根据上述排名规则对所有参赛团队进行排名。</p>

<p>请你返回能表示按排名系统 <strong>排序后</strong> 的所有团队排名的字符串。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>votes = ["ABC","ACB","ABC","ACB","ACB"]
<strong>输出：</strong>"ACB"
<strong>解释：</strong>
A 队获得五票「排位第一」，没有其他队获得「排位第一」，所以 A 队排名第一。
B 队获得两票「排位第二」，三票「排位第三」。
C 队获得三票「排位第二」，两票「排位第三」。
由于 C 队「排位第二」的票数较多，所以 C 队排第二，B 队排第三。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>votes = ["WXYZ","XYZW"]
<strong>输出：</strong>"XWYZ"
<strong>解释：</strong>
X 队在并列僵局打破后成为排名第一的团队。X 队和 W 队的「排位第一」票数一样，但是 X 队有一票「排位第二」，而 W 没有获得「排位第二」。 
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>votes = ["ZMNAGUEDSJYLBOPHRQICWFXTVK"]
<strong>输出：</strong>"ZMNAGUEDSJYLBOPHRQICWFXTVK"
<strong>解释：</strong>只有一个投票者，所以排名完全按照他的意愿。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= votes.length &lt;= 1000</code></li>
	<li><code>1 &lt;= votes[i].length &lt;= 26</code></li>
	<li><code>votes[i].length ==&nbsp;votes[j].length</code> for&nbsp;<code>0 &lt;= i, j &lt; votes.length</code></li>
	<li><code>votes[i][j]</code>&nbsp;是英文 <strong>大写</strong> 字母</li>
	<li><code>votes[i]</code>&nbsp;中的所有字母都是唯一的</li>
	<li><code>votes[0]</code>&nbsp;中出现的所有字母 <strong>同样也</strong> 出现在&nbsp;<code>votes[j]</code>&nbsp;中，其中&nbsp;<code>1 &lt;= j &lt; votes.length</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数 + 自定义排序

对于每个候选人，我们可以统计他在每个排位上的票数，然后根据不同的排位依次比较票数，票数相同则比较字母。

时间复杂度 $O(n \times m + m^2 \times \log m)$，空间复杂度 $O(m^2)$。其中 $n$ 是 $\textit{votes}$ 的长度，而 $m$ 是候选人的数量，即 $\textit{votes}[0]$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def rankTeams(self, votes: List[str]) -> str:
        m = len(votes[0])
        cnt = defaultdict(lambda: [0] * m)
        for vote in votes:
            for i, c in enumerate(vote):
                cnt[c][i] += 1
        return "".join(sorted(cnt, key=lambda c: (cnt[c], -ord(c)), reverse=True))
```

#### Java

```java
class Solution {
    public String rankTeams(String[] votes) {
        int m = votes[0].length();
        int[][] cnt = new int[26][m + 1];
        for (var vote : votes) {
            for (int i = 0; i < m; ++i) {
                ++cnt[vote.charAt(i) - 'A'][i];
            }
        }
        Character[] s = new Character[m];
        for (int i = 0; i < m; ++i) {
            s[i] = votes[0].charAt(i);
        }
        Arrays.sort(s, (a, b) -> {
            int i = a - 'A', j = b - 'A';
            for (int k = 0; k < m; ++k) {
                if (cnt[i][k] != cnt[j][k]) {
                    return cnt[j][k] - cnt[i][k];
                }
            }
            return a - b;
        });
        StringBuilder ans = new StringBuilder();
        for (var c : s) {
            ans.append(c);
        }
        return ans.toString();
    }
}
```

#### C++

```cpp
class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int m = votes[0].size();
        array<array<int, 27>, 26> cnt{};

        for (const auto& vote : votes) {
            for (int i = 0; i < m; ++i) {
                ++cnt[vote[i] - 'A'][i];
            }
        }
        string s = votes[0];
        ranges::sort(s, [&](char a, char b) {
            int i = a - 'A', j = b - 'A';
            for (int k = 0; k < m; ++k) {
                if (cnt[i][k] != cnt[j][k]) {
                    return cnt[i][k] > cnt[j][k];
                }
            }
            return a < b;
        });
        return string(s.begin(), s.end());
    }
};
```

#### Go

```go
func rankTeams(votes []string) string {
	m := len(votes[0])
	cnt := [26][27]int{}
	for _, vote := range votes {
		for i, ch := range vote {
			cnt[ch-'A'][i]++
		}
	}
	s := []rune(votes[0])
	sort.Slice(s, func(i, j int) bool {
		a, b := s[i]-'A', s[j]-'A'
		for k := 0; k < m; k++ {
			if cnt[a][k] != cnt[b][k] {
				return cnt[a][k] > cnt[b][k]
			}
		}
		return s[i] < s[j]
	})
	return string(s)
}
```

#### TypeScript

```ts
function rankTeams(votes: string[]): string {
    const m = votes[0].length;
    const cnt: number[][] = Array.from({ length: 26 }, () => Array(m + 1).fill(0));
    for (const vote of votes) {
        for (let i = 0; i < m; i++) {
            cnt[vote.charCodeAt(i) - 65][i]++;
        }
    }
    const s: string[] = votes[0].split('');
    s.sort((a, b) => {
        const i = a.charCodeAt(0) - 65;
        const j = b.charCodeAt(0) - 65;
        for (let k = 0; k < m; k++) {
            if (cnt[i][k] !== cnt[j][k]) {
                return cnt[j][k] - cnt[i][k];
            }
        }
        return a.localeCompare(b);
    });
    return s.join('');
}
```

#### Rust

```rust
impl Solution {
    pub fn rank_teams(votes: Vec<String>) -> String {
        let m = votes[0].len();
        let mut cnt = vec![vec![0; m + 1]; 26];

        for vote in &votes {
            for (i, ch) in vote.chars().enumerate() {
                cnt[(ch as u8 - b'A') as usize][i] += 1;
            }
        }

        let mut s: Vec<char> = votes[0].chars().collect();

        s.sort_by(|&a, &b| {
            let i = (a as u8 - b'A') as usize;
            let j = (b as u8 - b'A') as usize;

            for k in 0..m {
                if cnt[i][k] != cnt[j][k] {
                    return cnt[j][k].cmp(&cnt[i][k]);
                }
            }
            a.cmp(&b)
        });

        s.into_iter().collect()
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1367. 二叉树中的链表](https://leetcode.cn/problems/linked-list-in-binary-tree){#1367}

{{< tabs "1367" >}}

{{% tab "python" %}}
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSubPath(self, head: Optional[ListNode], root: Optional[TreeNode]) -> bool:
        def dfs(head, root):
            if head is None:
                return True
            if root is None or root.val != head.val:
                return False
            return dfs(head.next, root.left) or dfs(head.next, root.right)

        if root is None:
            return False
        return (
            dfs(head, root)
            or self.isSubPath(head, root.left)
            or self.isSubPath(head, root.right)
        )
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
    public boolean isSubPath(ListNode head, TreeNode root) {
        if (root == null) {
            return false;
        }
        return dfs(head, root) || isSubPath(head, root.left) || isSubPath(head, root.right);
    }

    private boolean dfs(ListNode head, TreeNode root) {
        if (head == null) {
            return true;
        }
        if (root == null || head.val != root.val) {
            return false;
        }
        return dfs(head.next, root.left) || dfs(head.next, root.right);
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
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!root) {
            return false;
        }
        return dfs(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }

    bool dfs(ListNode* head, TreeNode* root) {
        if (!head) {
            return true;
        }
        if (!root || head->val != root->val) {
            return false;
        }
        return dfs(head->next, root->left) || dfs(head->next, root->right);
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
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isSubPath(head *ListNode, root *TreeNode) bool {
	if root == nil {
		return false
	}
	return dfs(head, root) || isSubPath(head, root.Left) || isSubPath(head, root.Right)
}

func dfs(head *ListNode, root *TreeNode) bool {
	if head == nil {
		return true
	}
	if root == nil || head.Val != root.Val {
		return false
	}
	return dfs(head.Next, root.Left) || dfs(head.Next, root.Right)
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

const dfs = (head: ListNode | null, root: TreeNode | null) => {
    if (head == null) {
        return true;
    }
    if (root == null || head.val !== root.val) {
        return false;
    }
    return dfs(head.next, root.left) || dfs(head.next, root.right);
};

function isSubPath(head: ListNode | null, root: TreeNode | null): boolean {
    if (root == null) {
        return false;
    }
    return dfs(head, root) || isSubPath(head, root.left) || isSubPath(head, root.right);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
//
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
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
    fn dfs(head: &Option<Box<ListNode>>, root: &Option<Rc<RefCell<TreeNode>>>) -> bool {
        if head.is_none() {
            return true;
        }
        if root.is_none() {
            return false;
        }
        let node = head.as_ref().unwrap();
        let root = root.as_ref().unwrap().borrow();
        if node.val != root.val {
            return false;
        }
        Self::dfs(&node.next, &root.left) || Self::dfs(&node.next, &root.right)
    }

    fn my_is_sub_path(head: &Option<Box<ListNode>>, root: &Option<Rc<RefCell<TreeNode>>>) -> bool {
        if root.is_none() {
            return false;
        }
        let node = root.as_ref().unwrap().borrow();
        Self::dfs(head, root)
            || Self::my_is_sub_path(head, &node.left)
            || Self::my_is_sub_path(head, &node.right)
    }

    pub fn is_sub_path(head: Option<Box<ListNode>>, root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        Self::my_is_sub_path(&head, &root)
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一棵以&nbsp;<code>root</code>&nbsp;为根的二叉树和一个&nbsp;<code>head</code>&nbsp;为第一个节点的链表。</p>

<p>如果在二叉树中，存在一条一直向下的路径，且每个点的数值恰好一一对应以&nbsp;<code>head</code>&nbsp;为首的链表中每个节点的值，那么请你返回 <code>True</code> ，否则返回 <code>False</code> 。</p>

<p>一直向下的路径的意思是：从树中某个节点开始，一直连续向下的路径。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1300-1399/1367.Linked%20List%20in%20Binary%20Tree/images/sample_1_1720.png" style="height: 280px; width: 220px;"></strong></p>

<pre><strong>输入：</strong>head = [4,2,8], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
<strong>输出：</strong>true
<strong>解释：</strong>树中蓝色的节点构成了与链表对应的子路径。
</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1300-1399/1367.Linked%20List%20in%20Binary%20Tree/images/sample_2_1720.png" style="height: 280px; width: 220px;"></strong></p>

<pre><strong>输入：</strong>head = [1,4,2,6], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
<strong>输出：</strong>true
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>head = [1,4,2,6,8], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
<strong>输出：</strong>false
<strong>解释：</strong>二叉树中不存在一一对应链表的路径。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>二叉树和链表中的每个节点的值都满足&nbsp;<code>1 &lt;= node.val&nbsp;&lt;= 100</code>&nbsp;。</li>
	<li>链表包含的节点数目在&nbsp;<code>1</code>&nbsp;到&nbsp;<code>100</code>&nbsp;之间。</li>
	<li>二叉树包含的节点数目在&nbsp;<code>1</code>&nbsp;到&nbsp;<code>2500</code>&nbsp;之间。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：递归

我们设计一个递归函数 $dfs(head, root)$，表示链表 $head$ 是否是以 $root$ 为起点的路径上的节点值一一对应的子路径。函数 $dfs(head, root)$ 的逻辑如下：

-   如果链表 $head$ 为空，说明链表已经遍历完了，返回 `true`；
-   如果二叉树 $root$ 为空，说明二叉树已经遍历完了，但链表还没遍历完，返回 `false`；
-   如果二叉树 $root$ 的值与链表 $head$ 的值不相等，返回 `false`；
-   否则，返回 $dfs(head.next, root.left)$ 或 $dfs(head.next, root.right)$。

我们在主函数中，对二叉树的每个节点调用 $dfs(head, root)$，只要有一个返回 `true`，就说明链表是二叉树的子路径，返回 `true`；如果所有节点都返回 `false`，说明链表不是二叉树的子路径，返回 `false`。

时间复杂度 $O(n^2)，空间复杂度 O(n)$。其中 $n$ 是二叉树的节点数。

<!-- tabs:start -->

#### Python3

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSubPath(self, head: Optional[ListNode], root: Optional[TreeNode]) -> bool:
        def dfs(head, root):
            if head is None:
                return True
            if root is None or root.val != head.val:
                return False
            return dfs(head.next, root.left) or dfs(head.next, root.right)

        if root is None:
            return False
        return (
            dfs(head, root)
            or self.isSubPath(head, root.left)
            or self.isSubPath(head, root.right)
        )
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
    public boolean isSubPath(ListNode head, TreeNode root) {
        if (root == null) {
            return false;
        }
        return dfs(head, root) || isSubPath(head, root.left) || isSubPath(head, root.right);
    }

    private boolean dfs(ListNode head, TreeNode root) {
        if (head == null) {
            return true;
        }
        if (root == null || head.val != root.val) {
            return false;
        }
        return dfs(head.next, root.left) || dfs(head.next, root.right);
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
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!root) {
            return false;
        }
        return dfs(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }

    bool dfs(ListNode* head, TreeNode* root) {
        if (!head) {
            return true;
        }
        if (!root || head->val != root->val) {
            return false;
        }
        return dfs(head->next, root->left) || dfs(head->next, root->right);
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
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isSubPath(head *ListNode, root *TreeNode) bool {
	if root == nil {
		return false
	}
	return dfs(head, root) || isSubPath(head, root.Left) || isSubPath(head, root.Right)
}

func dfs(head *ListNode, root *TreeNode) bool {
	if head == nil {
		return true
	}
	if root == nil || head.Val != root.Val {
		return false
	}
	return dfs(head.Next, root.Left) || dfs(head.Next, root.Right)
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

const dfs = (head: ListNode | null, root: TreeNode | null) => {
    if (head == null) {
        return true;
    }
    if (root == null || head.val !== root.val) {
        return false;
    }
    return dfs(head.next, root.left) || dfs(head.next, root.right);
};

function isSubPath(head: ListNode | null, root: TreeNode | null): boolean {
    if (root == null) {
        return false;
    }
    return dfs(head, root) || isSubPath(head, root.left) || isSubPath(head, root.right);
}
```

#### Rust

```rust
// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
//
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
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
    fn dfs(head: &Option<Box<ListNode>>, root: &Option<Rc<RefCell<TreeNode>>>) -> bool {
        if head.is_none() {
            return true;
        }
        if root.is_none() {
            return false;
        }
        let node = head.as_ref().unwrap();
        let root = root.as_ref().unwrap().borrow();
        if node.val != root.val {
            return false;
        }
        Self::dfs(&node.next, &root.left) || Self::dfs(&node.next, &root.right)
    }

    fn my_is_sub_path(head: &Option<Box<ListNode>>, root: &Option<Rc<RefCell<TreeNode>>>) -> bool {
        if root.is_none() {
            return false;
        }
        let node = root.as_ref().unwrap().borrow();
        Self::dfs(head, root)
            || Self::my_is_sub_path(head, &node.left)
            || Self::my_is_sub_path(head, &node.right)
    }

    pub fn is_sub_path(head: Option<Box<ListNode>>, root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        Self::my_is_sub_path(&head, &root)
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1368. 使网格图至少有一条有效路径的最小代价](https://leetcode.cn/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid){#1368}

{{< tabs "1368" >}}

{{% tab "python" %}}
```python
class Solution:
    def minCost(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        dirs = [[0, 0], [0, 1], [0, -1], [1, 0], [-1, 0]]
        q = deque([(0, 0, 0)])
        vis = set()
        while q:
            i, j, d = q.popleft()
            if (i, j) in vis:
                continue
            vis.add((i, j))
            if i == m - 1 and j == n - 1:
                return d
            for k in range(1, 5):
                x, y = i + dirs[k][0], j + dirs[k][1]
                if 0 <= x < m and 0 <= y < n:
                    if grid[i][j] == k:
                        q.appendleft((x, y, d))
                    else:
                        q.append((x, y, d + 1))
        return -1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minCost(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        boolean[][] vis = new boolean[m][n];
        Deque<int[]> q = new ArrayDeque<>();
        q.offer(new int[] {0, 0, 0});
        int[][] dirs = {{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!q.isEmpty()) {
            int[] p = q.poll();
            int i = p[0], j = p[1], d = p[2];
            if (i == m - 1 && j == n - 1) {
                return d;
            }
            if (vis[i][j]) {
                continue;
            }
            vis[i][j] = true;
            for (int k = 1; k <= 4; ++k) {
                int x = i + dirs[k][0], y = j + dirs[k][1];
                if (x >= 0 && x < m && y >= 0 && y < n) {
                    if (grid[i][j] == k) {
                        q.offerFirst(new int[] {x, y, d});
                    } else {
                        q.offer(new int[] {x, y, d + 1});
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
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n));
        vector<vector<int>> dirs = {{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        deque<pair<int, int>> q;
        q.push_back({0, 0});
        while (!q.empty()) {
            auto p = q.front();
            q.pop_front();
            int i = p.first / n, j = p.first % n, d = p.second;
            if (i == m - 1 && j == n - 1) return d;
            if (vis[i][j]) continue;
            vis[i][j] = true;
            for (int k = 1; k <= 4; ++k) {
                int x = i + dirs[k][0], y = j + dirs[k][1];
                if (x >= 0 && x < m && y >= 0 && y < n) {
                    if (grid[i][j] == k)
                        q.push_front({x * n + y, d});
                    else
                        q.push_back({x * n + y, d + 1});
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
func minCost(grid [][]int) int {
	m, n := len(grid), len(grid[0])
	q := doublylinkedlist.New()
	q.Add([]int{0, 0, 0})
	dirs := [][]int{{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}}
	vis := make([][]bool, m)
	for i := range vis {
		vis[i] = make([]bool, n)
	}
	for !q.Empty() {
		v, _ := q.Get(0)
		p := v.([]int)
		q.Remove(0)
		i, j, d := p[0], p[1], p[2]
		if i == m-1 && j == n-1 {
			return d
		}
		if vis[i][j] {
			continue
		}
		vis[i][j] = true
		for k := 1; k <= 4; k++ {
			x, y := i+dirs[k][0], j+dirs[k][1]
			if x >= 0 && x < m && y >= 0 && y < n {
				if grid[i][j] == k {
					q.Insert(0, []int{x, y, d})
				} else {
					q.Add([]int{x, y, d + 1})
				}
			}
		}
	}
	return -1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minCost(grid: number[][]): number {
    const m = grid.length,
        n = grid[0].length;
    let ans = Array.from({ length: m }, v => new Array(n).fill(Infinity));
    ans[0][0] = 0;
    let queue = [[0, 0]];
    const dirs = [
        [0, 1],
        [0, -1],
        [1, 0],
        [-1, 0],
    ];
    while (queue.length) {
        let [x, y] = queue.shift();
        for (let step = 1; step < 5; step++) {
            let [dx, dy] = dirs[step - 1];
            let [i, j] = [x + dx, y + dy];
            if (i < 0 || i >= m || j < 0 || j >= n) continue;
            let cost = ~~(grid[x][y] != step) + ans[x][y];
            if (cost >= ans[i][j]) continue;
            ans[i][j] = cost;
            if (grid[x][y] == step) {
                queue.unshift([i, j]);
            } else {
                queue.push([i, j]);
            }
        }
    }
    return ans[m - 1][n - 1];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个 m x n 的网格图&nbsp;<code>grid</code>&nbsp;。&nbsp;<code>grid</code>&nbsp;中每个格子都有一个数字，对应着从该格子出发下一步走的方向。&nbsp;<code>grid[i][j]</code>&nbsp;中的数字可能为以下几种情况：</p>

<ul>
	<li><strong>1</strong>&nbsp;，下一步往右走，也就是你会从 <code>grid[i][j]</code>&nbsp;走到 <code>grid[i][j + 1]</code></li>
	<li><strong>2</strong>&nbsp;，下一步往左走，也就是你会从 <code>grid[i][j]</code>&nbsp;走到 <code>grid[i][j - 1]</code></li>
	<li><strong>3</strong>&nbsp;，下一步往下走，也就是你会从 <code>grid[i][j]</code>&nbsp;走到 <code>grid[i + 1][j]</code></li>
	<li><strong>4</strong>&nbsp;，下一步往上走，也就是你会从 <code>grid[i][j]</code>&nbsp;走到 <code>grid[i - 1][j]</code></li>
</ul>

<p>注意网格图中可能会有&nbsp;<strong>无效数字</strong>&nbsp;，因为它们可能指向&nbsp;<code>grid</code>&nbsp;以外的区域。</p>

<p>一开始，你会从最左上角的格子&nbsp;<code>(0,0)</code>&nbsp;出发。我们定义一条&nbsp;<strong>有效路径</strong>&nbsp;为从格子&nbsp;<code>(0,0)</code>&nbsp;出发，每一步都顺着数字对应方向走，最终在最右下角的格子&nbsp;<code>(m - 1, n - 1)</code>&nbsp;结束的路径。有效路径&nbsp;<strong>不需要是最短路径</strong>&nbsp;。</p>

<p>你可以花费&nbsp;<code>cost = 1</code>&nbsp;的代价修改一个格子中的数字，但每个格子中的数字&nbsp;<strong>只能修改一次</strong>&nbsp;。</p>

<p>请你返回让网格图至少有一条有效路径的最小代价。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1300-1399/1368.Minimum%20Cost%20to%20Make%20at%20Least%20One%20Valid%20Path%20in%20a%20Grid/images/grid1.png" style="height: 528px; width: 542px;"></p>

<pre><strong>输入：</strong>grid = [[1,1,1,1],[2,2,2,2],[1,1,1,1],[2,2,2,2]]
<strong>输出：</strong>3
<strong>解释：</strong>你将从点 (0, 0) 出发。
到达 (3, 3) 的路径为： (0, 0) --&gt; (0, 1) --&gt; (0, 2) --&gt; (0, 3) 花费代价 cost = 1 使方向向下 --&gt; (1, 3) --&gt; (1, 2) --&gt; (1, 1) --&gt; (1, 0) 花费代价 cost = 1 使方向向下 --&gt; (2, 0) --&gt; (2, 1) --&gt; (2, 2) --&gt; (2, 3) 花费代价 cost = 1 使方向向下 --&gt; (3, 3)
总花费为 cost = 3.
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1300-1399/1368.Minimum%20Cost%20to%20Make%20at%20Least%20One%20Valid%20Path%20in%20a%20Grid/images/grid2.png" style="height: 408px; width: 419px;"></p>

<pre><strong>输入：</strong>grid = [[1,1,3],[3,2,2],[1,1,4]]
<strong>输出：</strong>0
<strong>解释：</strong>不修改任何数字你就可以从 (0, 0) 到达 (2, 2) 。
</pre>

<p><strong>示例 3：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1300-1399/1368.Minimum%20Cost%20to%20Make%20at%20Least%20One%20Valid%20Path%20in%20a%20Grid/images/grid3.png" style="height: 302px; width: 314px;"></p>

<pre><strong>输入：</strong>grid = [[1,2],[4,3]]
<strong>输出：</strong>1
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>grid = [[2,2,2],[2,2,2]]
<strong>输出：</strong>3
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>grid = [[4]]
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双端队列 BFS

本题实际上也是最短路模型，只不过求解的是改变方向的最小次数。

在一个边权只有 0、1 的无向图中搜索最短路径可以使用双端队列进行 BFS。其原理是当前可以扩展到的点的权重为 0 时，将其加入队首；权重为 1 时，将其加入队尾。

> 如果某条边权值为 0，那么新拓展出的节点权值就和当前队首节点权值相同，显然可以作为下一次拓展的起点。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minCost(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        dirs = [[0, 0], [0, 1], [0, -1], [1, 0], [-1, 0]]
        q = deque([(0, 0, 0)])
        vis = set()
        while q:
            i, j, d = q.popleft()
            if (i, j) in vis:
                continue
            vis.add((i, j))
            if i == m - 1 and j == n - 1:
                return d
            for k in range(1, 5):
                x, y = i + dirs[k][0], j + dirs[k][1]
                if 0 <= x < m and 0 <= y < n:
                    if grid[i][j] == k:
                        q.appendleft((x, y, d))
                    else:
                        q.append((x, y, d + 1))
        return -1
```

#### Java

```java
class Solution {
    public int minCost(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        boolean[][] vis = new boolean[m][n];
        Deque<int[]> q = new ArrayDeque<>();
        q.offer(new int[] {0, 0, 0});
        int[][] dirs = {{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!q.isEmpty()) {
            int[] p = q.poll();
            int i = p[0], j = p[1], d = p[2];
            if (i == m - 1 && j == n - 1) {
                return d;
            }
            if (vis[i][j]) {
                continue;
            }
            vis[i][j] = true;
            for (int k = 1; k <= 4; ++k) {
                int x = i + dirs[k][0], y = j + dirs[k][1];
                if (x >= 0 && x < m && y >= 0 && y < n) {
                    if (grid[i][j] == k) {
                        q.offerFirst(new int[] {x, y, d});
                    } else {
                        q.offer(new int[] {x, y, d + 1});
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
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n));
        vector<vector<int>> dirs = {{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        deque<pair<int, int>> q;
        q.push_back({0, 0});
        while (!q.empty()) {
            auto p = q.front();
            q.pop_front();
            int i = p.first / n, j = p.first % n, d = p.second;
            if (i == m - 1 && j == n - 1) return d;
            if (vis[i][j]) continue;
            vis[i][j] = true;
            for (int k = 1; k <= 4; ++k) {
                int x = i + dirs[k][0], y = j + dirs[k][1];
                if (x >= 0 && x < m && y >= 0 && y < n) {
                    if (grid[i][j] == k)
                        q.push_front({x * n + y, d});
                    else
                        q.push_back({x * n + y, d + 1});
                }
            }
        }
        return -1;
    }
};
```

#### Go

```go
func minCost(grid [][]int) int {
	m, n := len(grid), len(grid[0])
	q := doublylinkedlist.New()
	q.Add([]int{0, 0, 0})
	dirs := [][]int{{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}}
	vis := make([][]bool, m)
	for i := range vis {
		vis[i] = make([]bool, n)
	}
	for !q.Empty() {
		v, _ := q.Get(0)
		p := v.([]int)
		q.Remove(0)
		i, j, d := p[0], p[1], p[2]
		if i == m-1 && j == n-1 {
			return d
		}
		if vis[i][j] {
			continue
		}
		vis[i][j] = true
		for k := 1; k <= 4; k++ {
			x, y := i+dirs[k][0], j+dirs[k][1]
			if x >= 0 && x < m && y >= 0 && y < n {
				if grid[i][j] == k {
					q.Insert(0, []int{x, y, d})
				} else {
					q.Add([]int{x, y, d + 1})
				}
			}
		}
	}
	return -1
}
```

#### TypeScript

```ts
function minCost(grid: number[][]): number {
    const m = grid.length,
        n = grid[0].length;
    let ans = Array.from({ length: m }, v => new Array(n).fill(Infinity));
    ans[0][0] = 0;
    let queue = [[0, 0]];
    const dirs = [
        [0, 1],
        [0, -1],
        [1, 0],
        [-1, 0],
    ];
    while (queue.length) {
        let [x, y] = queue.shift();
        for (let step = 1; step < 5; step++) {
            let [dx, dy] = dirs[step - 1];
            let [i, j] = [x + dx, y + dy];
            if (i < 0 || i >= m || j < 0 || j >= n) continue;
            let cost = ~~(grid[x][y] != step) + ans[x][y];
            if (cost >= ans[i][j]) continue;
            ans[i][j] = cost;
            if (grid[x][y] == step) {
                queue.unshift([i, j]);
            } else {
                queue.push([i, j]);
            }
        }
    }
    return ans[m - 1][n - 1];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1369. 获取最近第二次的活动 🔒](https://leetcode.cn/problems/get-the-second-most-recent-activity){#1369}

{{< tabs "1369" >}}

{{% tab "sql" %}}
```sql
SELECT
    username,
    activity,
    startdate,
    enddate
FROM
    (
        SELECT
            *,
            RANK() OVER (
                PARTITION BY username
                ORDER BY startdate DESC
            ) AS rk,
            COUNT(username) OVER (PARTITION BY username) AS cnt
        FROM UserActivity
    ) AS a
WHERE a.rk = 2 OR a.cnt = 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表: <code>UserActivity</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| username      | varchar |
| activity      | varchar |
| startDate     | Date    |
| endDate       | Date    |
+---------------+---------+
该表可能有重复的行
该表包含每个用户在一段时间内进行的活动的信息
名为 username 的用户在 startDate 到 endDate 日内有一次活动
</pre>

<p>&nbsp;</p>

<p>编写解决方案展示每一位用户 <strong>最近第二次</strong> 的活动</p>

<p>如果用户仅有一次活动，返回该活动</p>

<p>一个用户不能同时进行超过一项活动，以<strong> 任意 </strong>顺序返回结果</p>

<p>下面是返回结果格式的例子。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<code><strong>输入：</strong>
UserActivity</code> 表:
+------------+--------------+-------------+-------------+
| username   | activity     | startDate   | endDate     |
+------------+--------------+-------------+-------------+
| Alice      | Travel       | 2020-02-12  | 2020-02-20  |
| Alice      | Dancing      | 2020-02-21  | 2020-02-23  |
| Alice      | Travel       | 2020-02-24  | 2020-02-28  |
| Bob        | Travel       | 2020-02-11  | 2020-02-18  |
+------------+--------------+-------------+-------------+
<strong>输出：</strong>
+------------+--------------+-------------+-------------+
| username   | activity     | startDate   | endDate     |
+------------+--------------+-------------+-------------+
| Alice      | Dancing      | 2020-02-21  | 2020-02-23  |
| Bob        | Travel       | 2020-02-11  | 2020-02-18  |
+------------+--------------+-------------+-------------+
<strong>解释：</strong>
Alice 最近一次的活动是从 2020-02-24 到 2020-02-28 的旅行, 在此之前的 2020-02-21 到 2020-02-23 她进行了舞蹈
Bob 只有一条记录，我们就取这条记录</pre>

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
SELECT
    username,
    activity,
    startdate,
    enddate
FROM
    (
        SELECT
            *,
            RANK() OVER (
                PARTITION BY username
                ORDER BY startdate DESC
            ) AS rk,
            COUNT(username) OVER (PARTITION BY username) AS cnt
        FROM UserActivity
    ) AS a
WHERE a.rk = 2 OR a.cnt = 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
