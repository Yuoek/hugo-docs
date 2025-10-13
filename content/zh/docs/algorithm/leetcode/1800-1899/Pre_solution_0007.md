---
title: "1860_增长的内存泄露"
date: 2025-10-08T18:38:27+08:00
weight: 7
tags: [二分查找, 位运算, 前缀和, 动态规划, 双指针, 哈希表, 回溯, 字符串, 数学, 数据库, 数组, 枚举, 模拟, 矩阵, 组合数学, 设计, 贪心]
---

{{< markmap >}}
### [1860_增长的内存泄露](#1860)
#### [数学](#1860)
#### [模拟](#1860)
### [1861_旋转盒子](#1861)
#### [数组](#1861)
#### [双指针](#1861)
#### [矩阵](#1861)
### [1862_向下取整数对和](#1862)
#### [数组](#1862)
#### [数学](#1862)
#### [二分查找](#1862)
#### [前缀和](#1862)
### [1863_找出所有子集的异或总和再求和](#1863)
#### [位运算](#1863)
#### [数组](#1863)
#### [数学](#1863)
#### [回溯](#1863)
#### [组合数学](#1863)
#### [枚举](#1863)
### [1864_构成交替字符串需要的最小交换次数](#1864)
#### [贪心](#1864)
#### [字符串](#1864)
### [1865_找出和为指定值的下标对](#1865)
#### [设计](#1865)
#### [数组](#1865)
#### [哈希表](#1865)
### [1866_恰有 K 根木棍可以看到的排列数目](#1866)
#### [数学](#1866)
#### [动态规划](#1866)
#### [组合数学](#1866)
### [1867_最大数量高于平均水平的订单 🔒](#1867)
#### [数据库](#1867)
### [1868_两个行程编码数组的积 🔒](#1868)
#### [数组](#1868)
#### [双指针](#1868)
### [1869_哪种连续子字符串更长](#1869)
#### [字符串](#1869)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1860_增长的内存泄露
___
#### 数学
___
#### 模拟
---
### 1861_旋转盒子
___
#### 数组
___
#### 双指针
___
#### 矩阵
---
### 1862_向下取整数对和
___
#### 数组
___
#### 数学
___
#### 二分查找
___
#### 前缀和
---
### 1863_找出所有子集的异或总和再求和
___
#### 位运算
___
#### 数组
___
#### 数学
___
#### 回溯
___
#### 组合数学
___
#### 枚举
---
### 1864_构成交替字符串需要的最小交换次数
___
#### 贪心
___
#### 字符串
---
### 1865_找出和为指定值的下标对
___
#### 设计
___
#### 数组
___
#### 哈希表
---
### 1866_恰有 K 根木棍可以看到的排列数目
___
#### 数学
___
#### 动态规划
___
#### 组合数学
---
### 1867_最大数量高于平均水平的订单 🔒
___
#### 数据库
---
### 1868_两个行程编码数组的积 🔒
___
#### 数组
___
#### 双指针
---
### 1869_哪种连续子字符串更长
___
#### 字符串
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 位运算 | 前缀和 |
| 动态规划 | 双指针 | 哈希表 |
| 回溯 | 字符串 | 数学 |
| 数据库 | 数组 | 枚举 |
| 模拟 | 矩阵 | 组合数学 |
| 设计 | 贪心 |  |

# [1860. 增长的内存泄露](https://leetcode.cn/problems/incremental-memory-leak){#1860}

{{< tabs "1860" >}}

{{% tab "python" %}}
```python
class Solution:
    def memLeak(self, memory1: int, memory2: int) -> List[int]:
        i = 1
        while i <= max(memory1, memory2):
            if memory1 >= memory2:
                memory1 -= i
            else:
                memory2 -= i
            i += 1
        return [i, memory1, memory2]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] memLeak(int memory1, int memory2) {
        int i = 1;
        for (; i <= Math.max(memory1, memory2); ++i) {
            if (memory1 >= memory2) {
                memory1 -= i;
            } else {
                memory2 -= i;
            }
        }
        return new int[] {i, memory1, memory2};
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        int i = 1;
        for (; i <= max(memory1, memory2); ++i) {
            if (memory1 >= memory2) {
                memory1 -= i;
            } else {
                memory2 -= i;
            }
        }
        return {i, memory1, memory2};
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func memLeak(memory1 int, memory2 int) []int {
	i := 1
	for ; i <= memory1 || i <= memory2; i++ {
		if memory1 >= memory2 {
			memory1 -= i
		} else {
			memory2 -= i
		}
	}
	return []int{i, memory1, memory2}
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function memLeak(memory1: number, memory2: number): number[] {
    let i = 1;
    for (; i <= Math.max(memory1, memory2); ++i) {
        if (memory1 >= memory2) {
            memory1 -= i;
        } else {
            memory2 -= i;
        }
    }
    return [i, memory1, memory2];
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number} memory1
 * @param {number} memory2
 * @return {number[]}
 */
var memLeak = function (memory1, memory2) {
    let i = 1;
    for (; i <= Math.max(memory1, memory2); ++i) {
        if (memory1 >= memory2) {
            memory1 -= i;
        } else {
            memory2 -= i;
        }
    }
    return [i, memory1, memory2];
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个整数 <code>memory1</code> 和 <code>memory2</code> 分别表示两个内存条剩余可用内存的位数。现在有一个程序每秒递增的速度消耗着内存。</p>

<p>在第 <code>i</code> 秒（秒数从 1 开始），有 <code>i</code> 位内存被分配到 <strong>剩余内存较多</strong> 的内存条（如果两者一样多，则分配到第一个内存条）。如果两者剩余内存都不足 <code>i</code> 位，那么程序将 <b>意外退出</b> 。</p>

<p>请你返回一个数组，包含<em> </em><code>[crashTime, memory1<sub>crash</sub>, memory2<sub>crash</sub>]</code> ，其中 <code>crashTime</code>是程序意外退出的时间（单位为秒），<em> </em><code>memory1<sub>crash</sub></code><em> </em>和<em> </em><code>memory2<sub>crash</sub></code><em> </em>分别是两个内存条最后剩余内存的位数。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>memory1 = 2, memory2 = 2
<b>输出：</b>[3,1,0]
<b>解释：</b>内存分配如下：
- 第 1 秒，内存条 1 被占用 1 位内存。内存条 1 现在有 1 位剩余可用内存。
- 第 2 秒，内存条 2 被占用 2 位内存。内存条 2 现在有 0 位剩余可用内存。
- 第 3 秒，程序意外退出，两个内存条分别有 1 位和 0 位剩余可用内存。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>memory1 = 8, memory2 = 11
<b>输出：</b>[6,0,4]
<b>解释：</b>内存分配如下：
- 第 1 秒，内存条 2 被占用 1 位内存，内存条 2 现在有 10 位剩余可用内存。
- 第 2 秒，内存条 2 被占用 2 位内存，内存条 2 现在有 8 位剩余可用内存。
- 第 3 秒，内存条 1 被占用 3 位内存，内存条 1 现在有 5 位剩余可用内存。
- 第 4 秒，内存条 2 被占用 4 位内存，内存条 2 现在有 4 位剩余可用内存。
- 第 5 秒，内存条 1 被占用 5 位内存，内存条 1 现在有 0 位剩余可用内存。
- 第 6 秒，程序意外退出，两个内存条分别有 0 位和 4 位剩余可用内存。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= memory1, memory2 &lt;= 2<sup>31</sup> - 1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们直接模拟内存的分配。

假设 $t$ 为意外退出的时刻，那么两个内存条一定可以容纳 $t-1$ 时刻及以前消耗的内存，因此有：

$$
\sum_{i=1}^{t-1} i = \frac{t\times (t-1)}{2}  \leq (m_1+m_2)
$$

时间复杂度 $O(\sqrt{m_1+m_2})$，其中 $m_1$, $m_2$ 分别为两个内存条的内存大小。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def memLeak(self, memory1: int, memory2: int) -> List[int]:
        i = 1
        while i <= max(memory1, memory2):
            if memory1 >= memory2:
                memory1 -= i
            else:
                memory2 -= i
            i += 1
        return [i, memory1, memory2]
```

#### Java

```java
class Solution {
    public int[] memLeak(int memory1, int memory2) {
        int i = 1;
        for (; i <= Math.max(memory1, memory2); ++i) {
            if (memory1 >= memory2) {
                memory1 -= i;
            } else {
                memory2 -= i;
            }
        }
        return new int[] {i, memory1, memory2};
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        int i = 1;
        for (; i <= max(memory1, memory2); ++i) {
            if (memory1 >= memory2) {
                memory1 -= i;
            } else {
                memory2 -= i;
            }
        }
        return {i, memory1, memory2};
    }
};
```

#### Go

```go
func memLeak(memory1 int, memory2 int) []int {
	i := 1
	for ; i <= memory1 || i <= memory2; i++ {
		if memory1 >= memory2 {
			memory1 -= i
		} else {
			memory2 -= i
		}
	}
	return []int{i, memory1, memory2}
}
```

#### TypeScript

```ts
function memLeak(memory1: number, memory2: number): number[] {
    let i = 1;
    for (; i <= Math.max(memory1, memory2); ++i) {
        if (memory1 >= memory2) {
            memory1 -= i;
        } else {
            memory2 -= i;
        }
    }
    return [i, memory1, memory2];
}
```

#### JavaScript

```js
/**
 * @param {number} memory1
 * @param {number} memory2
 * @return {number[]}
 */
var memLeak = function (memory1, memory2) {
    let i = 1;
    for (; i <= Math.max(memory1, memory2); ++i) {
        if (memory1 >= memory2) {
            memory1 -= i;
        } else {
            memory2 -= i;
        }
    }
    return [i, memory1, memory2];
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1861. 旋转盒子](https://leetcode.cn/problems/rotating-the-box){#1861}

{{< tabs "1861" >}}

{{% tab "python" %}}
```python
class Solution:
    def rotateTheBox(self, box: List[List[str]]) -> List[List[str]]:
        m, n = len(box), len(box[0])
        ans = [[None] * m for _ in range(n)]
        for i in range(m):
            for j in range(n):
                ans[j][m - i - 1] = box[i][j]
        for j in range(m):
            q = deque()
            for i in range(n - 1, -1, -1):
                if ans[i][j] == '*':
                    q.clear()
                elif ans[i][j] == '.':
                    q.append(i)
                elif q:
                    ans[q.popleft()][j] = '#'
                    ans[i][j] = '.'
                    q.append(i)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public char[][] rotateTheBox(char[][] box) {
        int m = box.length, n = box[0].length;
        char[][] ans = new char[n][m];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans[j][m - i - 1] = box[i][j];
            }
        }
        for (int j = 0; j < m; ++j) {
            Deque<Integer> q = new ArrayDeque<>();
            for (int i = n - 1; i >= 0; --i) {
                if (ans[i][j] == '*') {
                    q.clear();
                } else if (ans[i][j] == '.') {
                    q.offer(i);
                } else if (!q.isEmpty()) {
                    ans[q.pollFirst()][j] = '#';
                    ans[i][j] = '.';
                    q.offer(i);
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
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size(), n = box[0].size();
        vector<vector<char>> ans(n, vector<char>(m));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans[j][m - i - 1] = box[i][j];
            }
        }
        for (int j = 0; j < m; ++j) {
            queue<int> q;
            for (int i = n - 1; ~i; --i) {
                if (ans[i][j] == '*') {
                    queue<int> t;
                    swap(t, q);
                } else if (ans[i][j] == '.') {
                    q.push(i);
                } else if (!q.empty()) {
                    ans[q.front()][j] = '#';
                    q.pop();
                    ans[i][j] = '.';
                    q.push(i);
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
func rotateTheBox(box [][]byte) [][]byte {
	m, n := len(box), len(box[0])
	ans := make([][]byte, n)
	for i := range ans {
		ans[i] = make([]byte, m)
	}
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			ans[j][m-i-1] = box[i][j]
		}
	}
	for j := 0; j < m; j++ {
		q := []int{}
		for i := n - 1; i >= 0; i-- {
			if ans[i][j] == '*' {
				q = []int{}
			} else if ans[i][j] == '.' {
				q = append(q, i)
			} else if len(q) > 0 {
				ans[q[0]][j] = '#'
				q = q[1:]
				ans[i][j] = '.'
				q = append(q, i)
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

<p>给你一个&nbsp;<code>m x n</code>&nbsp;的字符矩阵&nbsp;<code>boxGrid</code>&nbsp;，它表示一个箱子的侧视图。箱子的每一个格子可能为：</p>

<ul>
	<li><code>'#'</code>&nbsp;表示石头</li>
	<li><code>'*'</code>&nbsp;表示固定的障碍物</li>
	<li><code>'.'</code>&nbsp;表示空位置</li>
</ul>

<p>这个箱子被 <strong>顺时针旋转 90 度</strong>&nbsp;，由于重力原因，部分石头的位置会发生改变。每个石头会垂直掉落，直到它遇到障碍物，另一个石头或者箱子的底部。重力 <strong>不会</strong>&nbsp;影响障碍物的位置，同时箱子旋转不会产生<strong>惯性</strong>&nbsp;，也就是说石头的水平位置不会发生改变。</p>

<p>题目保证初始时&nbsp;<code>boxGrid</code>&nbsp;中的石头要么在一个障碍物上，要么在另一个石头上，要么在箱子的底部。</p>

<p>请你返回一个<em>&nbsp;</em><code>n x m</code>&nbsp;的矩阵，表示按照上述旋转后，箱子内的结果。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1800-1899/1861.Rotating%20the%20Box/images/rotatingtheboxleetcodewithstones.png" style="width: 300px; height: 150px;" /></p>

<pre>
<b>输入：</b>box = [["#",".","#"]]
<b>输出：</b>[["."],
&nbsp;     ["#"],
&nbsp;     ["#"]]
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1800-1899/1861.Rotating%20the%20Box/images/rotatingtheboxleetcode2withstones.png" style="width: 375px; height: 195px;" /></p>

<pre>
<b>输入：</b>box = [["#",".","*","."],
&nbsp;           ["#","#","*","."]]
<b>输出：</b>[["#","."],
&nbsp;     ["#","#"],
&nbsp;     ["*","*"],
&nbsp;     [".","."]]
</pre>

<p><strong>示例 3：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1800-1899/1861.Rotating%20the%20Box/images/rotatingtheboxleetcode3withstone.png" style="width: 400px; height: 218px;" /></p>

<pre>
<b>输入：</b>box = [["#","#","*",".","*","."],
&nbsp;           ["#","#","#","*",".","."],
&nbsp;           ["#","#","#",".","#","."]]
<b>输出：</b>[[".","#","#"],
&nbsp;     [".","#","#"],
&nbsp;     ["#","#","*"],
&nbsp;     ["#","*","."],
&nbsp;     ["#",".","*"],
&nbsp;     ["#",".","."]]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == boxGrid.length</code></li>
	<li><code>n == boxGrid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 500</code></li>
	<li><code>boxGrid[i][j]</code>&nbsp;只可能是&nbsp;<code>'#'</code>&nbsp;，<code>'*'</code>&nbsp;或者&nbsp;<code>'.'</code>&nbsp;。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：队列模拟

我们先将矩阵顺时针旋转 90 度，然后模拟每一列石头的下落过程。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别是矩阵的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def rotateTheBox(self, box: List[List[str]]) -> List[List[str]]:
        m, n = len(box), len(box[0])
        ans = [[None] * m for _ in range(n)]
        for i in range(m):
            for j in range(n):
                ans[j][m - i - 1] = box[i][j]
        for j in range(m):
            q = deque()
            for i in range(n - 1, -1, -1):
                if ans[i][j] == '*':
                    q.clear()
                elif ans[i][j] == '.':
                    q.append(i)
                elif q:
                    ans[q.popleft()][j] = '#'
                    ans[i][j] = '.'
                    q.append(i)
        return ans
```

#### Java

```java
class Solution {
    public char[][] rotateTheBox(char[][] box) {
        int m = box.length, n = box[0].length;
        char[][] ans = new char[n][m];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans[j][m - i - 1] = box[i][j];
            }
        }
        for (int j = 0; j < m; ++j) {
            Deque<Integer> q = new ArrayDeque<>();
            for (int i = n - 1; i >= 0; --i) {
                if (ans[i][j] == '*') {
                    q.clear();
                } else if (ans[i][j] == '.') {
                    q.offer(i);
                } else if (!q.isEmpty()) {
                    ans[q.pollFirst()][j] = '#';
                    ans[i][j] = '.';
                    q.offer(i);
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
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size(), n = box[0].size();
        vector<vector<char>> ans(n, vector<char>(m));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans[j][m - i - 1] = box[i][j];
            }
        }
        for (int j = 0; j < m; ++j) {
            queue<int> q;
            for (int i = n - 1; ~i; --i) {
                if (ans[i][j] == '*') {
                    queue<int> t;
                    swap(t, q);
                } else if (ans[i][j] == '.') {
                    q.push(i);
                } else if (!q.empty()) {
                    ans[q.front()][j] = '#';
                    q.pop();
                    ans[i][j] = '.';
                    q.push(i);
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func rotateTheBox(box [][]byte) [][]byte {
	m, n := len(box), len(box[0])
	ans := make([][]byte, n)
	for i := range ans {
		ans[i] = make([]byte, m)
	}
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			ans[j][m-i-1] = box[i][j]
		}
	}
	for j := 0; j < m; j++ {
		q := []int{}
		for i := n - 1; i >= 0; i-- {
			if ans[i][j] == '*' {
				q = []int{}
			} else if ans[i][j] == '.' {
				q = append(q, i)
			} else if len(q) > 0 {
				ans[q[0]][j] = '#'
				q = q[1:]
				ans[i][j] = '.'
				q = append(q, i)
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

# [1862. 向下取整数对和](https://leetcode.cn/problems/sum-of-floored-pairs){#1862}

{{< tabs "1862" >}}

{{% tab "python" %}}
```python
class Solution:
    def sumOfFlooredPairs(self, nums: List[int]) -> int:
        mod = 10**9 + 7
        cnt = Counter(nums)
        mx = max(nums)
        s = [0] * (mx + 1)
        for i in range(1, mx + 1):
            s[i] = s[i - 1] + cnt[i]
        ans = 0
        for y in range(1, mx + 1):
            if cnt[y]:
                d = 1
                while d * y <= mx:
                    ans += cnt[y] * d * (s[min(mx, d * y + y - 1)] - s[d * y - 1])
                    ans %= mod
                    d += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int sumOfFlooredPairs(int[] nums) {
        final int mod = (int) 1e9 + 7;
        int mx = 0;
        for (int x : nums) {
            mx = Math.max(mx, x);
        }
        int[] cnt = new int[mx + 1];
        int[] s = new int[mx + 1];
        for (int x : nums) {
            ++cnt[x];
        }
        for (int i = 1; i <= mx; ++i) {
            s[i] = s[i - 1] + cnt[i];
        }
        long ans = 0;
        for (int y = 1; y <= mx; ++y) {
            if (cnt[y] > 0) {
                for (int d = 1; d * y <= mx; ++d) {
                    ans += 1L * cnt[y] * d * (s[Math.min(mx, d * y + y - 1)] - s[d * y - 1]);
                    ans %= mod;
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
    int sumOfFlooredPairs(vector<int>& nums) {
        const int mod = 1e9 + 7;
        int mx = *max_element(nums.begin(), nums.end());
        vector<int> cnt(mx + 1);
        vector<int> s(mx + 1);
        for (int x : nums) {
            ++cnt[x];
        }
        for (int i = 1; i <= mx; ++i) {
            s[i] = s[i - 1] + cnt[i];
        }
        long long ans = 0;
        for (int y = 1; y <= mx; ++y) {
            if (cnt[y]) {
                for (int d = 1; d * y <= mx; ++d) {
                    ans += 1LL * cnt[y] * d * (s[min(mx, d * y + y - 1)] - s[d * y - 1]);
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
func sumOfFlooredPairs(nums []int) (ans int) {
	mx := slices.Max(nums)
	cnt := make([]int, mx+1)
	s := make([]int, mx+1)
	for _, x := range nums {
		cnt[x]++
	}
	for i := 1; i <= mx; i++ {
		s[i] = s[i-1] + cnt[i]
	}
	const mod int = 1e9 + 7
	for y := 1; y <= mx; y++ {
		if cnt[y] > 0 {
			for d := 1; d*y <= mx; d++ {
				ans += d * cnt[y] * (s[min((d+1)*y-1, mx)] - s[d*y-1])
				ans %= mod
			}
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function sumOfFlooredPairs(nums: number[]): number {
    const mx = Math.max(...nums);
    const cnt: number[] = Array(mx + 1).fill(0);
    const s: number[] = Array(mx + 1).fill(0);
    for (const x of nums) {
        ++cnt[x];
    }
    for (let i = 1; i <= mx; ++i) {
        s[i] = s[i - 1] + cnt[i];
    }
    let ans = 0;
    const mod = 1e9 + 7;
    for (let y = 1; y <= mx; ++y) {
        if (cnt[y]) {
            for (let d = 1; d * y <= mx; ++d) {
                ans += cnt[y] * d * (s[Math.min((d + 1) * y - 1, mx)] - s[d * y - 1]);
                ans %= mod;
            }
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn sum_of_floored_pairs(nums: Vec<i32>) -> i32 {
        const MOD: i32 = 1_000_000_007;
        let mut mx = 0;
        for &x in nums.iter() {
            mx = mx.max(x);
        }

        let mut cnt = vec![0; (mx + 1) as usize];
        let mut s = vec![0; (mx + 1) as usize];

        for &x in nums.iter() {
            cnt[x as usize] += 1;
        }

        for i in 1..=mx as usize {
            s[i] = s[i - 1] + cnt[i];
        }

        let mut ans = 0;
        for y in 1..=mx as usize {
            if cnt[y] > 0 {
                let mut d = 1;
                while d * y <= (mx as usize) {
                    ans += ((cnt[y] as i64)
                        * (d as i64)
                        * (s[std::cmp::min(mx as usize, d * y + y - 1)] - s[d * y - 1]))
                        % (MOD as i64);
                    ans %= MOD as i64;
                    d += 1;
                }
            }
        }

        ans as i32
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>nums</code> ，请你返回所有下标对 <code>0 &lt;= i, j &lt; nums.length</code> 的 <code>floor(nums[i] / nums[j])</code> 结果之和。由于答案可能会很大，请你返回答案对<code>10<sup>9</sup> + 7</code> <strong>取余</strong> 的结果。</p>

<p>函数 <code>floor()</code> 返回输入数字的整数部分。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [2,5,9]
<b>输出：</b>10
<strong>解释：</strong>
floor(2 / 5) = floor(2 / 9) = floor(5 / 9) = 0
floor(2 / 2) = floor(5 / 5) = floor(9 / 9) = 1
floor(5 / 2) = 2
floor(9 / 2) = 4
floor(9 / 5) = 1
我们计算每一个数对商向下取整的结果并求和得到 10 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [7,7,7,7,7,7,7]
<b>输出：</b>49
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：值域前缀和 + 优化枚举

我们先统计数组 $nums$ 中每个元素出现的次数，记录在数组 $cnt$ 中，然后计算数组 $cnt$ 的前缀和，记录在数组 $s$ 中，即 $s[i]$ 表示小于等于 $i$ 的元素的个数。

接下来，我们枚举分母 $y$ 以及商 $d$，利用前缀和数组计算得到分子的个数 $s[\min(mx, d \times y + y - 1)] - s[d \times y - 1]$，其中 $mx$ 表示数组 $nums$ 中的最大值。那么，我们将分子的个数，乘以分母的个数 $cnt[y]$，再乘以商 $d$，就可以得到所有满足条件的分式的值，将这些值累加起来，就可以得到答案。

时间复杂度 $O(M \times \log M)$，空间复杂度 $O(M)$，其中 $M$ 表示数组 $nums$ 中的最大值。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def sumOfFlooredPairs(self, nums: List[int]) -> int:
        mod = 10**9 + 7
        cnt = Counter(nums)
        mx = max(nums)
        s = [0] * (mx + 1)
        for i in range(1, mx + 1):
            s[i] = s[i - 1] + cnt[i]
        ans = 0
        for y in range(1, mx + 1):
            if cnt[y]:
                d = 1
                while d * y <= mx:
                    ans += cnt[y] * d * (s[min(mx, d * y + y - 1)] - s[d * y - 1])
                    ans %= mod
                    d += 1
        return ans
```

#### Java

```java
class Solution {
    public int sumOfFlooredPairs(int[] nums) {
        final int mod = (int) 1e9 + 7;
        int mx = 0;
        for (int x : nums) {
            mx = Math.max(mx, x);
        }
        int[] cnt = new int[mx + 1];
        int[] s = new int[mx + 1];
        for (int x : nums) {
            ++cnt[x];
        }
        for (int i = 1; i <= mx; ++i) {
            s[i] = s[i - 1] + cnt[i];
        }
        long ans = 0;
        for (int y = 1; y <= mx; ++y) {
            if (cnt[y] > 0) {
                for (int d = 1; d * y <= mx; ++d) {
                    ans += 1L * cnt[y] * d * (s[Math.min(mx, d * y + y - 1)] - s[d * y - 1]);
                    ans %= mod;
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
    int sumOfFlooredPairs(vector<int>& nums) {
        const int mod = 1e9 + 7;
        int mx = *max_element(nums.begin(), nums.end());
        vector<int> cnt(mx + 1);
        vector<int> s(mx + 1);
        for (int x : nums) {
            ++cnt[x];
        }
        for (int i = 1; i <= mx; ++i) {
            s[i] = s[i - 1] + cnt[i];
        }
        long long ans = 0;
        for (int y = 1; y <= mx; ++y) {
            if (cnt[y]) {
                for (int d = 1; d * y <= mx; ++d) {
                    ans += 1LL * cnt[y] * d * (s[min(mx, d * y + y - 1)] - s[d * y - 1]);
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
func sumOfFlooredPairs(nums []int) (ans int) {
	mx := slices.Max(nums)
	cnt := make([]int, mx+1)
	s := make([]int, mx+1)
	for _, x := range nums {
		cnt[x]++
	}
	for i := 1; i <= mx; i++ {
		s[i] = s[i-1] + cnt[i]
	}
	const mod int = 1e9 + 7
	for y := 1; y <= mx; y++ {
		if cnt[y] > 0 {
			for d := 1; d*y <= mx; d++ {
				ans += d * cnt[y] * (s[min((d+1)*y-1, mx)] - s[d*y-1])
				ans %= mod
			}
		}
	}
	return
}
```

#### TypeScript

```ts
function sumOfFlooredPairs(nums: number[]): number {
    const mx = Math.max(...nums);
    const cnt: number[] = Array(mx + 1).fill(0);
    const s: number[] = Array(mx + 1).fill(0);
    for (const x of nums) {
        ++cnt[x];
    }
    for (let i = 1; i <= mx; ++i) {
        s[i] = s[i - 1] + cnt[i];
    }
    let ans = 0;
    const mod = 1e9 + 7;
    for (let y = 1; y <= mx; ++y) {
        if (cnt[y]) {
            for (let d = 1; d * y <= mx; ++d) {
                ans += cnt[y] * d * (s[Math.min((d + 1) * y - 1, mx)] - s[d * y - 1]);
                ans %= mod;
            }
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn sum_of_floored_pairs(nums: Vec<i32>) -> i32 {
        const MOD: i32 = 1_000_000_007;
        let mut mx = 0;
        for &x in nums.iter() {
            mx = mx.max(x);
        }

        let mut cnt = vec![0; (mx + 1) as usize];
        let mut s = vec![0; (mx + 1) as usize];

        for &x in nums.iter() {
            cnt[x as usize] += 1;
        }

        for i in 1..=mx as usize {
            s[i] = s[i - 1] + cnt[i];
        }

        let mut ans = 0;
        for y in 1..=mx as usize {
            if cnt[y] > 0 {
                let mut d = 1;
                while d * y <= (mx as usize) {
                    ans += ((cnt[y] as i64)
                        * (d as i64)
                        * (s[std::cmp::min(mx as usize, d * y + y - 1)] - s[d * y - 1]))
                        % (MOD as i64);
                    ans %= MOD as i64;
                    d += 1;
                }
            }
        }

        ans as i32
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1863. 找出所有子集的异或总和再求和](https://leetcode.cn/problems/sum-of-all-subset-xor-totals){#1863}

{{< tabs "1863" >}}

{{% tab "python" %}}
```python
class Solution:
    def subsetXORSum(self, nums: List[int]) -> int:
        def dfs(i: int, s: int):
            nonlocal ans
            if i >= len(nums):
                ans += s
                return
            dfs(i + 1, s)
            dfs(i + 1, s ^ nums[i])

        ans = 0
        dfs(0, 0)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int ans;
    private int[] nums;

    public int subsetXORSum(int[] nums) {
        this.nums = nums;
        dfs(0, 0);
        return ans;
    }

    private void dfs(int i, int s) {
        if (i >= nums.length) {
            ans += s;
            return;
        }
        dfs(i + 1, s);
        dfs(i + 1, s ^ nums[i]);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        auto dfs = [&](this auto&& dfs, int i, int s) {
            if (i >= n) {
                ans += s;
                return;
            }
            dfs(i + 1, s);
            dfs(i + 1, s ^ nums[i]);
        };
        dfs(0, 0);
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func subsetXORSum(nums []int) (ans int) {
	n := len(nums)
	var dfs func(int, int)
	dfs = func(i, s int) {
		if i >= n {
			ans += s
			return
		}
		dfs(i+1, s)
		dfs(i+1, s^nums[i])
	}
	dfs(0, 0)
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function subsetXORSum(nums: number[]): number {
    let ans = 0;
    const n = nums.length;
    const dfs = (i: number, s: number) => {
        if (i >= n) {
            ans += s;
            return;
        }
        dfs(i + 1, s);
        dfs(i + 1, s ^ nums[i]);
    };
    dfs(0, 0);
    return ans;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var subsetXORSum = function (nums) {
    let ans = 0;
    const n = nums.length;
    const dfs = (i, s) => {
        if (i >= n) {
            ans += s;
            return;
        }
        dfs(i + 1, s);
        dfs(i + 1, s ^ nums[i]);
    };
    dfs(0, 0);
    return ans;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>一个数组的<strong> 异或总和</strong> 定义为数组中所有元素按位 <code>XOR</code> 的结果；如果数组为 <strong>空</strong> ，则异或总和为 <code>0</code> 。</p>

<ul>
	<li>例如，数组 <code>[2,5,6]</code> 的 <strong>异或总和</strong> 为 <code>2 XOR 5 XOR 6 = 1</code> 。</li>
</ul>

<p>给你一个数组 <code>nums</code> ，请你求出 <code>nums</code> 中每个 <strong>子集</strong> 的 <strong>异或总和</strong> ，计算并返回这些值相加之 <strong>和</strong> 。</p>

<p><strong>注意：</strong>在本题中，元素 <strong>相同</strong> 的不同子集应 <strong>多次</strong> 计数。</p>

<p>数组 <code>a</code> 是数组 <code>b</code> 的一个 <strong>子集</strong> 的前提条件是：从 <code>b</code> 删除几个（也可能不删除）元素能够得到 <code>a</code> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [1,3]
<strong>输出：</strong>6
<strong>解释：</strong>[1,3] 共有 4 个子集：
- 空子集的异或总和是 0 。
- [1] 的异或总和为 1 。
- [3] 的异或总和为 3 。
- [1,3] 的异或总和为 1 XOR 3 = 2 。
0 + 1 + 3 + 2 = 6
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [5,1,6]
<strong>输出：</strong>28
<strong>解释：</strong>[5,1,6] 共有 8 个子集：
- 空子集的异或总和是 0 。
- [5] 的异或总和为 5 。
- [1] 的异或总和为 1 。
- [6] 的异或总和为 6 。
- [5,1] 的异或总和为 5 XOR 1 = 4 。
- [5,6] 的异或总和为 5 XOR 6 = 3 。
- [1,6] 的异或总和为 1 XOR 6 = 7 。
- [5,1,6] 的异或总和为 5 XOR 1 XOR 6 = 2 。
0 + 5 + 1 + 6 + 4 + 3 + 7 + 2 = 28
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>nums = [3,4,5,6,7,8]
<strong>输出：</strong>480
<strong>解释：</strong>每个子集的全部异或总和值之和为 480 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 12</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 20</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二进制枚举

我们可以用二进制枚举的方法，枚举出所有的子集，然后计算每个子集的异或总和。

具体地，我们在 $[0, 2^n)$ 的范围内枚举 $i$，其中 $n$ 是数组 $nums$ 的长度。如果 $i$ 的二进制表示的第 $j$ 位为 $1$，那么代表着 $nums$ 的第 $j$ 个元素在当前枚举的子集中；如果第 $j$ 位为 $0$，那么代表着 $nums$ 的第 $j$ 个元素不在当前枚举的子集中。我们可以根据 $i$ 的二进制表示，得到当前子集对应的异或总和，将其加到答案中即可。

时间复杂度 $O(n \times 2^n)$，其中 $n$ 是数组 $nums$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def subsetXORSum(self, nums: List[int]) -> int:
        ans, n = 0, len(nums)
        for i in range(1 << n):
            s = 0
            for j in range(n):
                if i >> j & 1:
                    s ^= nums[j]
            ans += s
        return ans
```

#### Java

```java
class Solution {
    public int subsetXORSum(int[] nums) {
        int n = nums.length;
        int ans = 0;
        for (int i = 0; i < 1 << n; ++i) {
            int s = 0;
            for (int j = 0; j < n; ++j) {
                if ((i >> j & 1) == 1) {
                    s ^= nums[j];
                }
            }
            ans += s;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < 1 << n; ++i) {
            int s = 0;
            for (int j = 0; j < n; ++j) {
                if (i >> j & 1) {
                    s ^= nums[j];
                }
            }
            ans += s;
        }
        return ans;
    }
};
```

#### Go

```go
func subsetXORSum(nums []int) (ans int) {
	n := len(nums)
	for i := 0; i < 1<<n; i++ {
		s := 0
		for j, x := range nums {
			if i>>j&1 == 1 {
				s ^= x
			}
		}
		ans += s
	}
	return
}
```

#### TypeScript

```ts
function subsetXORSum(nums: number[]): number {
    let ans = 0;
    const n = nums.length;
    for (let i = 0; i < 1 << n; ++i) {
        let s = 0;
        for (let j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                s ^= nums[j];
            }
        }
        ans += s;
    }
    return ans;
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var subsetXORSum = function (nums) {
    let ans = 0;
    const n = nums.length;
    for (let i = 0; i < 1 << n; ++i) {
        let s = 0;
        for (let j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                s ^= nums[j];
            }
        }
        ans += s;
    }
    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：DFS

我们也可以使用深度优先搜索的方法，枚举出所有的子集，然后计算每个子集的异或总和。

我们设计一个函数 $dfs(i, s)$，其中 $i$ 表示当前搜索到数组 $nums$ 的第 $i$ 个元素，$s$ 表示当前子集的异或总和。初始时，$i=0$, $s=0$。在搜索的过程中，每次我们都有两种选择：

-   将 $nums$ 的第 $i$ 个元素加入当前子集，即 $dfs(i+1, s \oplus nums[i])$；
-   将 $nums$ 的第 $i$ 个元素不加入当前子集，即 $dfs(i+1, s)$。

当我们搜索完数组 $nums$ 的所有元素时，即 $i=n$ 时，当前子集的异或总和为 $s$，将其加到答案中即可。

时间复杂度 $O(2^n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def subsetXORSum(self, nums: List[int]) -> int:
        def dfs(i: int, s: int):
            nonlocal ans
            if i >= len(nums):
                ans += s
                return
            dfs(i + 1, s)
            dfs(i + 1, s ^ nums[i])

        ans = 0
        dfs(0, 0)
        return ans
```

#### Java

```java
class Solution {
    private int ans;
    private int[] nums;

    public int subsetXORSum(int[] nums) {
        this.nums = nums;
        dfs(0, 0);
        return ans;
    }

    private void dfs(int i, int s) {
        if (i >= nums.length) {
            ans += s;
            return;
        }
        dfs(i + 1, s);
        dfs(i + 1, s ^ nums[i]);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        auto dfs = [&](this auto&& dfs, int i, int s) {
            if (i >= n) {
                ans += s;
                return;
            }
            dfs(i + 1, s);
            dfs(i + 1, s ^ nums[i]);
        };
        dfs(0, 0);
        return ans;
    }
};
```

#### Go

```go
func subsetXORSum(nums []int) (ans int) {
	n := len(nums)
	var dfs func(int, int)
	dfs = func(i, s int) {
		if i >= n {
			ans += s
			return
		}
		dfs(i+1, s)
		dfs(i+1, s^nums[i])
	}
	dfs(0, 0)
	return
}
```

#### TypeScript

```ts
function subsetXORSum(nums: number[]): number {
    let ans = 0;
    const n = nums.length;
    const dfs = (i: number, s: number) => {
        if (i >= n) {
            ans += s;
            return;
        }
        dfs(i + 1, s);
        dfs(i + 1, s ^ nums[i]);
    };
    dfs(0, 0);
    return ans;
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var subsetXORSum = function (nums) {
    let ans = 0;
    const n = nums.length;
    const dfs = (i, s) => {
        if (i >= n) {
            ans += s;
            return;
        }
        dfs(i + 1, s);
        dfs(i + 1, s ^ nums[i]);
    };
    dfs(0, 0);
    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1864. 构成交替字符串需要的最小交换次数](https://leetcode.cn/problems/minimum-number-of-swaps-to-make-the-binary-string-alternating){#1864}

{{< tabs "1864" >}}

{{% tab "python" %}}
```python
class Solution:
    def minSwaps(self, s: str) -> int:
        def calc(c: int) -> int:
            return sum((c ^ i & 1) != x for i, x in enumerate(map(int, s))) // 2

        n0 = s.count("0")
        n1 = len(s) - n0
        if abs(n0 - n1) > 1:
            return -1
        if n0 == n1:
            return min(calc(0), calc(1))
        return calc(0 if n0 > n1 else 1)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private char[] s;

    public int minSwaps(String s) {
        this.s = s.toCharArray();
        int n1 = 0;
        for (char c : this.s) {
            n1 += (c - '0');
        }
        int n0 = this.s.length - n1;
        if (Math.abs(n0 - n1) > 1) {
            return -1;
        }
        if (n0 == n1) {
            return Math.min(calc(0), calc(1));
        }
        return calc(n0 > n1 ? 0 : 1);
    }

    private int calc(int c) {
        int cnt = 0;
        for (int i = 0; i < s.length; ++i) {
            int x = s[i] - '0';
            if ((i & 1 ^ c) != x) {
                ++cnt;
            }
        }
        return cnt / 2;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minSwaps(string s) {
        int n0 = ranges::count(s, '0');
        int n1 = s.size() - n0;
        if (abs(n0 - n1) > 1) {
            return -1;
        }
        auto calc = [&](int c) -> int {
            int cnt = 0;
            for (int i = 0; i < s.size(); ++i) {
                int x = s[i] - '0';
                if ((i & 1 ^ c) != x) {
                    ++cnt;
                }
            }
            return cnt / 2;
        };
        if (n0 == n1) {
            return min(calc(0), calc(1));
        }
        return calc(n0 > n1 ? 0 : 1);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minSwaps(s string) int {
	n0 := strings.Count(s, "0")
	n1 := len(s) - n0
	if abs(n0-n1) > 1 {
		return -1
	}
	calc := func(c int) int {
		cnt := 0
		for i, ch := range s {
			x := int(ch - '0')
			if i&1^c != x {
				cnt++
			}
		}
		return cnt / 2
	}
	if n0 == n1 {
		return min(calc(0), calc(1))
	}
	if n0 > n1 {
		return calc(0)
	}
	return calc(1)
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
function minSwaps(s: string): number {
    const n0 = (s.match(/0/g) || []).length;
    const n1 = s.length - n0;
    if (Math.abs(n0 - n1) > 1) {
        return -1;
    }
    const calc = (c: number): number => {
        let cnt = 0;
        for (let i = 0; i < s.length; i++) {
            const x = +s[i];
            if (((i & 1) ^ c) !== x) {
                cnt++;
            }
        }
        return Math.floor(cnt / 2);
    };
    if (n0 === n1) {
        return Math.min(calc(0), calc(1));
    }
    return calc(n0 > n1 ? 0 : 1);
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {string} s
 * @return {number}
 */
var minSwaps = function (s) {
    const n0 = (s.match(/0/g) || []).length;
    const n1 = s.length - n0;
    if (Math.abs(n0 - n1) > 1) {
        return -1;
    }
    const calc = c => {
        let cnt = 0;
        for (let i = 0; i < s.length; i++) {
            const x = +s[i];
            if (((i & 1) ^ c) !== x) {
                cnt++;
            }
        }
        return Math.floor(cnt / 2);
    };
    if (n0 === n1) {
        return Math.min(calc(0), calc(1));
    }
    return calc(n0 > n1 ? 0 : 1);
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个二进制字符串 <code>s</code> ，现需要将其转化为一个 <strong>交替字符串</strong> 。请你计算并返回转化所需的 <strong>最小</strong> 字符交换次数，如果无法完成转化，返回<em> </em><code>-1</code><em> </em>。</p>

<p><strong>交替字符串</strong> 是指：相邻字符之间不存在相等情况的字符串。例如，字符串 <code>"010"</code> 和 <code>"1010"</code> 属于交替字符串，但 <code>"0100"</code> 不是。</p>

<p>任意两个字符都可以进行交换，<strong>不必相邻</strong> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "111000"
<strong>输出：</strong>1
<strong>解释：</strong>交换位置 1 和 4："1<em><strong>1</strong></em>10<em><strong>0</strong></em>0" -> "1<em><strong>0</strong></em>10<em><strong>1</strong></em>0" ，字符串变为交替字符串。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "010"
<strong>输出：</strong>0
<strong>解释：</strong>字符串已经是交替字符串了，不需要交换。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "1110"
<strong>输出：</strong>-1
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= s.length <= 1000</code></li>
	<li><code>s[i]</code> 的值为 <code>'0'</code> 或 <code>'1'</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数

我们先统计字符串 $\textit{s}$ 中字符 $0$ 和字符 $1$ 的个数，分别记为 $n_0$ 和 $n_1$。

如果 $n_0$ 和 $n_1$ 的绝对值大于 $1$，那么无法构成交替字符串，返回 $-1$。

如果 $n_0$ 和 $n_1$ 相等，那么我们可以分别计算将字符串转化为以 $0$ 开头和以 $1$ 开头的交替字符串所需要的交换次数，取最小值。

如果 $n_0$ 和 $n_1$ 不相等，那么我们只需要计算将字符串转化为以字符个数较多的字符开头的交替字符串所需要的交换次数。

问题转换为：计算字符串 $\textit{s}$ 转化为以字符 $c$ 开头的交替字符串所需要的交换次数。

我们定义一个函数 $\text{calc}(c)$，表示将字符串 $\textit{s}$ 转化为以字符 $c$ 开头的交替字符串所需要的交换次数。我们遍历字符串 $\textit{s}$，对于每个位置 $i$，如果 $i$ 与 $c$ 的奇偶性不同，那么我们需要交换这个位置的字符，计数器 $+1$。由于每次交换都会使两个位置的字符变得相同，因此最终的交换次数为计数器的一半。

时间复杂度 $O(n)$，其中 $n$ 是字符串 $\textit{s}$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minSwaps(self, s: str) -> int:
        def calc(c: int) -> int:
            return sum((c ^ i & 1) != x for i, x in enumerate(map(int, s))) // 2

        n0 = s.count("0")
        n1 = len(s) - n0
        if abs(n0 - n1) > 1:
            return -1
        if n0 == n1:
            return min(calc(0), calc(1))
        return calc(0 if n0 > n1 else 1)
```

#### Java

```java
class Solution {
    private char[] s;

    public int minSwaps(String s) {
        this.s = s.toCharArray();
        int n1 = 0;
        for (char c : this.s) {
            n1 += (c - '0');
        }
        int n0 = this.s.length - n1;
        if (Math.abs(n0 - n1) > 1) {
            return -1;
        }
        if (n0 == n1) {
            return Math.min(calc(0), calc(1));
        }
        return calc(n0 > n1 ? 0 : 1);
    }

    private int calc(int c) {
        int cnt = 0;
        for (int i = 0; i < s.length; ++i) {
            int x = s[i] - '0';
            if ((i & 1 ^ c) != x) {
                ++cnt;
            }
        }
        return cnt / 2;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minSwaps(string s) {
        int n0 = ranges::count(s, '0');
        int n1 = s.size() - n0;
        if (abs(n0 - n1) > 1) {
            return -1;
        }
        auto calc = [&](int c) -> int {
            int cnt = 0;
            for (int i = 0; i < s.size(); ++i) {
                int x = s[i] - '0';
                if ((i & 1 ^ c) != x) {
                    ++cnt;
                }
            }
            return cnt / 2;
        };
        if (n0 == n1) {
            return min(calc(0), calc(1));
        }
        return calc(n0 > n1 ? 0 : 1);
    }
};
```

#### Go

```go
func minSwaps(s string) int {
	n0 := strings.Count(s, "0")
	n1 := len(s) - n0
	if abs(n0-n1) > 1 {
		return -1
	}
	calc := func(c int) int {
		cnt := 0
		for i, ch := range s {
			x := int(ch - '0')
			if i&1^c != x {
				cnt++
			}
		}
		return cnt / 2
	}
	if n0 == n1 {
		return min(calc(0), calc(1))
	}
	if n0 > n1 {
		return calc(0)
	}
	return calc(1)
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
function minSwaps(s: string): number {
    const n0 = (s.match(/0/g) || []).length;
    const n1 = s.length - n0;
    if (Math.abs(n0 - n1) > 1) {
        return -1;
    }
    const calc = (c: number): number => {
        let cnt = 0;
        for (let i = 0; i < s.length; i++) {
            const x = +s[i];
            if (((i & 1) ^ c) !== x) {
                cnt++;
            }
        }
        return Math.floor(cnt / 2);
    };
    if (n0 === n1) {
        return Math.min(calc(0), calc(1));
    }
    return calc(n0 > n1 ? 0 : 1);
}
```

#### JavaScript

```js
/**
 * @param {string} s
 * @return {number}
 */
var minSwaps = function (s) {
    const n0 = (s.match(/0/g) || []).length;
    const n1 = s.length - n0;
    if (Math.abs(n0 - n1) > 1) {
        return -1;
    }
    const calc = c => {
        let cnt = 0;
        for (let i = 0; i < s.length; i++) {
            const x = +s[i];
            if (((i & 1) ^ c) !== x) {
                cnt++;
            }
        }
        return Math.floor(cnt / 2);
    };
    if (n0 === n1) {
        return Math.min(calc(0), calc(1));
    }
    return calc(n0 > n1 ? 0 : 1);
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1865. 找出和为指定值的下标对](https://leetcode.cn/problems/finding-pairs-with-a-certain-sum){#1865}

{{< tabs "1865" >}}

{{% tab "python" %}}
```python
class FindSumPairs:

    def __init__(self, nums1: List[int], nums2: List[int]):
        self.cnt = Counter(nums2)
        self.nums1 = nums1
        self.nums2 = nums2

    def add(self, index: int, val: int) -> None:
        self.cnt[self.nums2[index]] -= 1
        self.nums2[index] += val
        self.cnt[self.nums2[index]] += 1

    def count(self, tot: int) -> int:
        return sum(self.cnt[tot - x] for x in self.nums1)


# Your FindSumPairs object will be instantiated and called as such:
# obj = FindSumPairs(nums1, nums2)
# obj.add(index,val)
# param_2 = obj.count(tot)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class FindSumPairs {
    private int[] nums1;
    private int[] nums2;
    private Map<Integer, Integer> cnt = new HashMap<>();

    public FindSumPairs(int[] nums1, int[] nums2) {
        this.nums1 = nums1;
        this.nums2 = nums2;
        for (int x : nums2) {
            cnt.merge(x, 1, Integer::sum);
        }
    }

    public void add(int index, int val) {
        cnt.merge(nums2[index], -1, Integer::sum);
        nums2[index] += val;
        cnt.merge(nums2[index], 1, Integer::sum);
    }

    public int count(int tot) {
        int ans = 0;
        for (int x : nums1) {
            ans += cnt.getOrDefault(tot - x, 0);
        }
        return ans;
    }
}

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs obj = new FindSumPairs(nums1, nums2);
 * obj.add(index,val);
 * int param_2 = obj.count(tot);
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class FindSumPairs {
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        for (int x : nums2) {
            ++cnt[x];
        }
    }

    void add(int index, int val) {
        --cnt[nums2[index]];
        nums2[index] += val;
        ++cnt[nums2[index]];
    }

    int count(int tot) {
        int ans = 0;
        for (int x : nums1) {
            ans += cnt[tot - x];
        }
        return ans;
    }

private:
    vector<int> nums1;
    vector<int> nums2;
    unordered_map<int, int> cnt;
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type FindSumPairs struct {
	nums1 []int
	nums2 []int
	cnt   map[int]int
}

func Constructor(nums1 []int, nums2 []int) FindSumPairs {
	cnt := map[int]int{}
	for _, x := range nums2 {
		cnt[x]++
	}
	return FindSumPairs{nums1, nums2, cnt}
}

func (this *FindSumPairs) Add(index int, val int) {
	this.cnt[this.nums2[index]]--
	this.nums2[index] += val
	this.cnt[this.nums2[index]]++
}

func (this *FindSumPairs) Count(tot int) (ans int) {
	for _, x := range this.nums1 {
		ans += this.cnt[tot-x]
	}
	return
}

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * obj := Constructor(nums1, nums2);
 * obj.Add(index,val);
 * param_2 := obj.Count(tot);
 */
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class FindSumPairs {
    private nums1: number[];
    private nums2: number[];
    private cnt: Map<number, number>;

    constructor(nums1: number[], nums2: number[]) {
        this.nums1 = nums1;
        this.nums2 = nums2;
        this.cnt = new Map();
        for (const x of nums2) {
            this.cnt.set(x, (this.cnt.get(x) || 0) + 1);
        }
    }

    add(index: number, val: number): void {
        const old = this.nums2[index];
        this.cnt.set(old, this.cnt.get(old)! - 1);
        this.nums2[index] += val;
        const now = this.nums2[index];
        this.cnt.set(now, (this.cnt.get(now) || 0) + 1);
    }

    count(tot: number): number {
        return this.nums1.reduce((acc, x) => acc + (this.cnt.get(tot - x) || 0), 0);
    }
}

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * var obj = new FindSumPairs(nums1, nums2)
 * obj.add(index,val)
 * var param_2 = obj.count(tot)
 */
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashMap;

struct FindSumPairs {
    nums1: Vec<i32>,
    nums2: Vec<i32>,
    cnt: HashMap<i32, i32>,
}

impl FindSumPairs {
    fn new(nums1: Vec<i32>, nums2: Vec<i32>) -> Self {
        let mut cnt = HashMap::new();
        for &x in &nums2 {
            *cnt.entry(x).or_insert(0) += 1;
        }
        Self { nums1, nums2, cnt }
    }

    fn add(&mut self, index: i32, val: i32) {
        let i = index as usize;
        let old_val = self.nums2[i];
        *self.cnt.entry(old_val).or_insert(0) -= 1;
        if self.cnt[&old_val] == 0 {
            self.cnt.remove(&old_val);
        }

        self.nums2[i] += val;
        let new_val = self.nums2[i];
        *self.cnt.entry(new_val).or_insert(0) += 1;
    }

    fn count(&self, tot: i32) -> i32 {
        let mut ans = 0;
        for &x in &self.nums1 {
            let target = tot - x;
            if let Some(&c) = self.cnt.get(&target) {
                ans += c;
            }
        }
        ans
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 */
var FindSumPairs = function (nums1, nums2) {
    this.nums1 = nums1;
    this.nums2 = nums2;
    this.cnt = new Map();
    for (const x of nums2) {
        this.cnt.set(x, (this.cnt.get(x) || 0) + 1);
    }
};

/**
 * @param {number} index
 * @param {number} val
 * @return {void}
 */
FindSumPairs.prototype.add = function (index, val) {
    const old = this.nums2[index];
    this.cnt.set(old, this.cnt.get(old) - 1);
    this.nums2[index] += val;
    const now = this.nums2[index];
    this.cnt.set(now, (this.cnt.get(now) || 0) + 1);
};

/**
 * @param {number} tot
 * @return {number}
 */
FindSumPairs.prototype.count = function (tot) {
    return this.nums1.reduce((acc, x) => acc + (this.cnt.get(tot - x) || 0), 0);
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * var obj = new FindSumPairs(nums1, nums2)
 * obj.add(index,val)
 * var param_2 = obj.count(tot)
 */
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class FindSumPairs {
    private int[] nums1;
    private int[] nums2;
    private Dictionary<int, int> cnt = new Dictionary<int, int>();

    public FindSumPairs(int[] nums1, int[] nums2) {
        this.nums1 = nums1;
        this.nums2 = nums2;
        foreach (int x in nums2) {
            if (cnt.ContainsKey(x)) {
                cnt[x]++;
            } else {
                cnt[x] = 1;
            }
        }
    }

    public void Add(int index, int val) {
        int oldVal = nums2[index];
        if (cnt.TryGetValue(oldVal, out int oldCount)) {
            if (oldCount == 1) {
                cnt.Remove(oldVal);
            } else {
                cnt[oldVal] = oldCount - 1;
            }
        }
        nums2[index] += val;
        int newVal = nums2[index];
        if (cnt.TryGetValue(newVal, out int newCount)) {
            cnt[newVal] = newCount + 1;
        } else {
            cnt[newVal] = 1;
        }
    }

    public int Count(int tot) {
        int ans = 0;
        foreach (int x in nums1) {
            int target = tot - x;
            if (cnt.TryGetValue(target, out int count)) {
                ans += count;
            }
        }
        return ans;
    }
}

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs obj = new FindSumPairs(nums1, nums2);
 * obj.Add(index,val);
 * int param_2 = obj.Count(tot);
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个整数数组 <code>nums1</code> 和 <code>nums2</code> ，请你实现一个支持下述两类查询的数据结构：</p>

<ol>
	<li><strong>累加</strong> ，将一个正整数加到 <code>nums2</code> 中指定下标对应元素上。</li>
	<li><strong>计数 </strong>，统计满足 <code>nums1[i] + nums2[j]</code> 等于指定值的下标对 <code>(i, j)</code> 数目（<code>0 <= i < nums1.length</code> 且 <code>0 <= j < nums2.length</code>）。</li>
</ol>

<p>实现 <code>FindSumPairs</code> 类：</p>

<ul>
	<li><code>FindSumPairs(int[] nums1, int[] nums2)</code> 使用整数数组 <code>nums1</code> 和 <code>nums2</code> 初始化 <code>FindSumPairs</code> 对象。</li>
	<li><code>void add(int index, int val)</code> 将 <code>val</code> 加到 <code>nums2[index]</code> 上，即，执行 <code>nums2[index] += val</code> 。</li>
	<li><code>int count(int tot)</code> 返回满足 <code>nums1[i] + nums2[j] == tot</code> 的下标对 <code>(i, j)</code> 数目。</li>
</ul>

<p> </p>

<p><strong>示例：</strong></p>

<pre>
<strong>输入：</strong>
["FindSumPairs", "count", "add", "count", "count", "add", "add", "count"]
[[[1, 1, 2, 2, 2, 3], [1, 4, 5, 2, 5, 4]], [7], [3, 2], [8], [4], [0, 1], [1, 1], [7]]
<strong>输出：</strong>
[null, 8, null, 2, 1, null, null, 11]

<strong>解释：</strong>
FindSumPairs findSumPairs = new FindSumPairs([1, 1, 2, 2, 2, 3], [1, 4, 5, 2, 5, 4]);
findSumPairs.count(7);  // 返回 8 ; 下标对 (2,2), (3,2), (4,2), (2,4), (3,4), (4,4) 满足 2 + 5 = 7 ，下标对 (5,1), (5,5) 满足 3 + 4 = 7
findSumPairs.add(3, 2); // 此时 nums2 = [1,4,5,<em><strong>4</strong></em><code>,5,4</code>]
findSumPairs.count(8);  // 返回 2 ；下标对 (5,2), (5,4) 满足 3 + 5 = 8
findSumPairs.count(4);  // 返回 1 ；下标对 (5,0) 满足 3 + 1 = 4
findSumPairs.add(0, 1); // 此时 nums2 = [<em><strong><code>2</code></strong></em>,4,5,4<code>,5,4</code>]
findSumPairs.add(1, 1); // 此时 nums2 = [<code>2</code>,<em><strong>5</strong></em>,5,4<code>,5,4</code>]
findSumPairs.count(7);  // 返回 11 ；下标对 (2,1), (2,2), (2,4), (3,1), (3,2), (3,4), (4,1), (4,2), (4,4) 满足 2 + 5 = 7 ，下标对 (5,3), (5,5) 满足 3 + 4 = 7
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= nums1.length <= 1000</code></li>
	<li><code>1 <= nums2.length <= 10<sup>5</sup></code></li>
	<li><code>1 <= nums1[i] <= 10<sup>9</sup></code></li>
	<li><code>1 <= nums2[i] <= 10<sup>5</sup></code></li>
	<li><code>0 <= index < nums2.length</code></li>
	<li><code>1 <= val <= 10<sup>5</sup></code></li>
	<li><code>1 <= tot <= 10<sup>9</sup></code></li>
	<li>最多调用 <code>add</code> 和 <code>count</code> 函数各 <code>1000</code> 次</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

我们注意到，数组 $\textit{nums1}$ 的长度不超过 ${10}^3$，数组 $\textit{nums2}$ 的长度达到 ${10}^5$，因此，如果直接暴力枚举所有下标对 $(i, j)$，计算 $\textit{nums1}[i] + \textit{nums2}[j]$ 是否等于指定值 $\textit{tot}$，那么会超出时间限制。

能否只枚举长度较短的数组 $\textit{nums1}$ 呢？答案是可以的。我们用一个哈希表 $\textit{cnt}$ 统计数组 $\textit{nums2}$ 中每个元素出现的次数，然后枚举数组 $\textit{nums1}$ 中的每个元素 $x$，计算 $\textit{cnt}[\textit{tot} - x]$ 的值之和即可。

在调用 $\text{add}$ 方法时，我们需要先将 $\textit{nums2}[index]$ 对应的值从 $\textit{cnt}$ 中减去 $1$，然后将 $\textit{nums2}[index]$ 的值加上 $\textit{val}$，最后将 $\textit{nums2}[index]$ 对应的值加上 $1$。

在调用 $\text{count}$ 方法时，我们只需要遍历数组 $\textit{nums1}$，对于每个元素 $x$，计算 $\textit{cnt}[\textit{tot} - x]$ 的值之和即可。

时间复杂度 $O(n \times q)$，空间复杂度 $O(m)$。其中 $n$ 和 $m$ 分别是数组 $\textit{nums1}$ 和 $\textit{nums2}$ 的长度，而 $q$ 是调用 $\text{count}$ 方法的次数。

<!-- tabs:start -->

#### Python3

```python
class FindSumPairs:

    def __init__(self, nums1: List[int], nums2: List[int]):
        self.cnt = Counter(nums2)
        self.nums1 = nums1
        self.nums2 = nums2

    def add(self, index: int, val: int) -> None:
        self.cnt[self.nums2[index]] -= 1
        self.nums2[index] += val
        self.cnt[self.nums2[index]] += 1

    def count(self, tot: int) -> int:
        return sum(self.cnt[tot - x] for x in self.nums1)


# Your FindSumPairs object will be instantiated and called as such:
# obj = FindSumPairs(nums1, nums2)
# obj.add(index,val)
# param_2 = obj.count(tot)
```

#### Java

```java
class FindSumPairs {
    private int[] nums1;
    private int[] nums2;
    private Map<Integer, Integer> cnt = new HashMap<>();

    public FindSumPairs(int[] nums1, int[] nums2) {
        this.nums1 = nums1;
        this.nums2 = nums2;
        for (int x : nums2) {
            cnt.merge(x, 1, Integer::sum);
        }
    }

    public void add(int index, int val) {
        cnt.merge(nums2[index], -1, Integer::sum);
        nums2[index] += val;
        cnt.merge(nums2[index], 1, Integer::sum);
    }

    public int count(int tot) {
        int ans = 0;
        for (int x : nums1) {
            ans += cnt.getOrDefault(tot - x, 0);
        }
        return ans;
    }
}

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs obj = new FindSumPairs(nums1, nums2);
 * obj.add(index,val);
 * int param_2 = obj.count(tot);
 */
```

#### C++

```cpp
class FindSumPairs {
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        for (int x : nums2) {
            ++cnt[x];
        }
    }

    void add(int index, int val) {
        --cnt[nums2[index]];
        nums2[index] += val;
        ++cnt[nums2[index]];
    }

    int count(int tot) {
        int ans = 0;
        for (int x : nums1) {
            ans += cnt[tot - x];
        }
        return ans;
    }

private:
    vector<int> nums1;
    vector<int> nums2;
    unordered_map<int, int> cnt;
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
```

#### Go

```go
type FindSumPairs struct {
	nums1 []int
	nums2 []int
	cnt   map[int]int
}

func Constructor(nums1 []int, nums2 []int) FindSumPairs {
	cnt := map[int]int{}
	for _, x := range nums2 {
		cnt[x]++
	}
	return FindSumPairs{nums1, nums2, cnt}
}

func (this *FindSumPairs) Add(index int, val int) {
	this.cnt[this.nums2[index]]--
	this.nums2[index] += val
	this.cnt[this.nums2[index]]++
}

func (this *FindSumPairs) Count(tot int) (ans int) {
	for _, x := range this.nums1 {
		ans += this.cnt[tot-x]
	}
	return
}

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * obj := Constructor(nums1, nums2);
 * obj.Add(index,val);
 * param_2 := obj.Count(tot);
 */
```

#### TypeScript

```ts
class FindSumPairs {
    private nums1: number[];
    private nums2: number[];
    private cnt: Map<number, number>;

    constructor(nums1: number[], nums2: number[]) {
        this.nums1 = nums1;
        this.nums2 = nums2;
        this.cnt = new Map();
        for (const x of nums2) {
            this.cnt.set(x, (this.cnt.get(x) || 0) + 1);
        }
    }

    add(index: number, val: number): void {
        const old = this.nums2[index];
        this.cnt.set(old, this.cnt.get(old)! - 1);
        this.nums2[index] += val;
        const now = this.nums2[index];
        this.cnt.set(now, (this.cnt.get(now) || 0) + 1);
    }

    count(tot: number): number {
        return this.nums1.reduce((acc, x) => acc + (this.cnt.get(tot - x) || 0), 0);
    }
}

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * var obj = new FindSumPairs(nums1, nums2)
 * obj.add(index,val)
 * var param_2 = obj.count(tot)
 */
```

#### Rust

```rust
use std::collections::HashMap;

struct FindSumPairs {
    nums1: Vec<i32>,
    nums2: Vec<i32>,
    cnt: HashMap<i32, i32>,
}

impl FindSumPairs {
    fn new(nums1: Vec<i32>, nums2: Vec<i32>) -> Self {
        let mut cnt = HashMap::new();
        for &x in &nums2 {
            *cnt.entry(x).or_insert(0) += 1;
        }
        Self { nums1, nums2, cnt }
    }

    fn add(&mut self, index: i32, val: i32) {
        let i = index as usize;
        let old_val = self.nums2[i];
        *self.cnt.entry(old_val).or_insert(0) -= 1;
        if self.cnt[&old_val] == 0 {
            self.cnt.remove(&old_val);
        }

        self.nums2[i] += val;
        let new_val = self.nums2[i];
        *self.cnt.entry(new_val).or_insert(0) += 1;
    }

    fn count(&self, tot: i32) -> i32 {
        let mut ans = 0;
        for &x in &self.nums1 {
            let target = tot - x;
            if let Some(&c) = self.cnt.get(&target) {
                ans += c;
            }
        }
        ans
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 */
var FindSumPairs = function (nums1, nums2) {
    this.nums1 = nums1;
    this.nums2 = nums2;
    this.cnt = new Map();
    for (const x of nums2) {
        this.cnt.set(x, (this.cnt.get(x) || 0) + 1);
    }
};

/**
 * @param {number} index
 * @param {number} val
 * @return {void}
 */
FindSumPairs.prototype.add = function (index, val) {
    const old = this.nums2[index];
    this.cnt.set(old, this.cnt.get(old) - 1);
    this.nums2[index] += val;
    const now = this.nums2[index];
    this.cnt.set(now, (this.cnt.get(now) || 0) + 1);
};

/**
 * @param {number} tot
 * @return {number}
 */
FindSumPairs.prototype.count = function (tot) {
    return this.nums1.reduce((acc, x) => acc + (this.cnt.get(tot - x) || 0), 0);
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * var obj = new FindSumPairs(nums1, nums2)
 * obj.add(index,val)
 * var param_2 = obj.count(tot)
 */
```

#### C#

```cs
public class FindSumPairs {
    private int[] nums1;
    private int[] nums2;
    private Dictionary<int, int> cnt = new Dictionary<int, int>();

    public FindSumPairs(int[] nums1, int[] nums2) {
        this.nums1 = nums1;
        this.nums2 = nums2;
        foreach (int x in nums2) {
            if (cnt.ContainsKey(x)) {
                cnt[x]++;
            } else {
                cnt[x] = 1;
            }
        }
    }

    public void Add(int index, int val) {
        int oldVal = nums2[index];
        if (cnt.TryGetValue(oldVal, out int oldCount)) {
            if (oldCount == 1) {
                cnt.Remove(oldVal);
            } else {
                cnt[oldVal] = oldCount - 1;
            }
        }
        nums2[index] += val;
        int newVal = nums2[index];
        if (cnt.TryGetValue(newVal, out int newCount)) {
            cnt[newVal] = newCount + 1;
        } else {
            cnt[newVal] = 1;
        }
    }

    public int Count(int tot) {
        int ans = 0;
        foreach (int x in nums1) {
            int target = tot - x;
            if (cnt.TryGetValue(target, out int count)) {
                ans += count;
            }
        }
        return ans;
    }
}

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs obj = new FindSumPairs(nums1, nums2);
 * obj.Add(index,val);
 * int param_2 = obj.Count(tot);
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1866. 恰有 K 根木棍可以看到的排列数目](https://leetcode.cn/problems/number-of-ways-to-rearrange-sticks-with-k-sticks-visible){#1866}

{{< tabs "1866" >}}

{{% tab "python" %}}
```python
class Solution:
    def rearrangeSticks(self, n: int, k: int) -> int:
        mod = 10**9 + 7
        f = [1] + [0] * k
        for i in range(1, n + 1):
            for j in range(k, 0, -1):
                f[j] = (f[j] * (i - 1) + f[j - 1]) % mod
            f[0] = 0
        return f[k]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int rearrangeSticks(int n, int k) {
        final int mod = (int) 1e9 + 7;
        int[] f = new int[k + 1];
        f[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = k; j > 0; --j) {
                f[j] = (int) ((f[j] * (i - 1L) + f[j - 1]) % mod);
            }
            f[0] = 0;
        }
        return f[k];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int rearrangeSticks(int n, int k) {
        const int mod = 1e9 + 7;
        int f[k + 1];
        memset(f, 0, sizeof(f));
        f[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = k; j; --j) {
                f[j] = (f[j - 1] + f[j] * (i - 1LL)) % mod;
            }
            f[0] = 0;
        }
        return f[k];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func rearrangeSticks(n int, k int) int {
	const mod = 1e9 + 7
	f := make([]int, k+1)
	f[0] = 1
	for i := 1; i <= n; i++ {
		for j := k; j > 0; j-- {
			f[j] = (f[j-1] + f[j]*(i-1)) % mod
		}
		f[0] = 0
	}
	return f[k]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function rearrangeSticks(n: number, k: number): number {
    const mod = 10 ** 9 + 7;
    const f: number[] = Array(n + 1).fill(0);
    f[0] = 1;
    for (let i = 1; i <= n; ++i) {
        for (let j = k; j; --j) {
            f[j] = (f[j] * (i - 1) + f[j - 1]) % mod;
        }
        f[0] = 0;
    }
    return f[k];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>有 <code>n</code> 根长度互不相同的木棍，长度为从 <code>1</code> 到 <code>n</code> 的整数。请你将这些木棍排成一排，并满足从左侧 <strong>可以看到</strong> <strong>恰好</strong> <code>k</code> 根木棍。从左侧 <strong>可以看到</strong> 木棍的前提是这个木棍的 <strong>左侧</strong> 不存在比它 <strong>更长的</strong> 木棍。</p>

<ul>
	<li>例如，如果木棍排列为 <code>[<em><strong>1</strong></em>,<em><strong>3</strong></em>,2,<em><strong>5</strong></em>,4]</code> ，那么从左侧可以看到的就是长度分别为 <code>1</code>、<code>3</code> 、<code>5</code> 的木棍。</li>
</ul>

<p>给你 <code>n</code> 和 <code>k</code> ，返回符合题目要求的排列 <strong>数目</strong> 。由于答案可能很大，请返回对 <code>10<sup>9</sup> + 7</code> <strong>取余 </strong>的结果。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>n = 3, k = 2
<strong>输出：</strong>3
<strong>解释：</strong>[<strong><em>1</em></strong>,<strong><em>3</em></strong>,2], [<em><strong>2</strong></em>,<em><strong>3</strong></em>,1] 和 [<em><strong>2</strong></em>,1,<em><strong>3</strong></em>] 是仅有的能满足恰好 2 根木棍可以看到的排列。
可以看到的木棍已经用粗体+斜体标识。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>n = 5, k = 5
<strong>输出：</strong>1
<strong>解释：</strong>[<em><strong>1</strong></em>,<em><strong>2</strong></em>,<em><strong>3</strong></em>,<em><strong>4</strong></em>,<em><strong>5</strong></em>] 是唯一一种能满足全部 5 根木棍可以看到的排列。
可以看到的木棍已经用粗体+斜体标识。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>n = 20, k = 11
<strong>输出：</strong>647427950
<strong>解释：</strong>总共有 647427950 (mod 10<sup>9 </sup>+ 7) 种能满足恰好有 11 根木棍可以看到的排列。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
	<li><code>1 &lt;= k &lt;= n</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i][j]$ 表示长度为 $i$ 的排列中，恰有 $j$ 根木棍可以看到的排列数目。初始时 $f[0][0]=1$，其余 $f[i][j]=0$。答案为 $f[n][k]$。

考虑最后一根木棍是否可以看到，如果可以看到，那么它一定是最长的，那么它的前面有 $i - 1$ 根木棍，恰有 $j - 1$ 根木棍可以看到，即 $f[i - 1][j - 1]$；如果最后一根木棍不可以看到，那么它可以是除了最长的木棍之外的任意一根，那么它的前面有 $i - 1$ 根木棍，恰有 $j$ 根木棍可以看到，即 $f[i - 1][j] \times (i - 1)$。

因此，状态转移方程为：

$$
f[i][j] = f[i - 1][j - 1] + f[i - 1][j] \times (i - 1)
$$

最终答案为 $f[n][k]$。

时间复杂度 $O(n \times k)$，空间复杂度 $O(n \times k)$。其中 $n$ 和 $k$ 分别是题目中给定的两个整数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def rearrangeSticks(self, n: int, k: int) -> int:
        mod = 10**9 + 7
        f = [[0] * (k + 1) for _ in range(n + 1)]
        f[0][0] = 1
        for i in range(1, n + 1):
            for j in range(1, k + 1):
                f[i][j] = (f[i - 1][j - 1] + f[i - 1][j] * (i - 1)) % mod
        return f[n][k]
```

#### Java

```java
class Solution {
    public int rearrangeSticks(int n, int k) {
        final int mod = (int) 1e9 + 7;
        int[][] f = new int[n + 1][k + 1];
        f[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                f[i][j] = (int) ((f[i - 1][j - 1] + f[i - 1][j] * (long) (i - 1)) % mod);
            }
        }
        return f[n][k];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int rearrangeSticks(int n, int k) {
        const int mod = 1e9 + 7;
        int f[n + 1][k + 1];
        memset(f, 0, sizeof(f));
        f[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                f[i][j] = (f[i - 1][j - 1] + (i - 1LL) * f[i - 1][j]) % mod;
            }
        }
        return f[n][k];
    }
};
```

#### Go

```go
func rearrangeSticks(n int, k int) int {
	const mod = 1e9 + 7
	f := make([][]int, n+1)
	for i := range f {
		f[i] = make([]int, k+1)
	}
	f[0][0] = 1
	for i := 1; i <= n; i++ {
		for j := 1; j <= k; j++ {
			f[i][j] = (f[i-1][j-1] + (i-1)*f[i-1][j]) % mod
		}
	}
	return f[n][k]
}
```

#### TypeScript

```ts
function rearrangeSticks(n: number, k: number): number {
    const mod = 10 ** 9 + 7;
    const f: number[][] = Array.from({ length: n + 1 }, () =>
        Array.from({ length: k + 1 }, () => 0),
    );
    f[0][0] = 1;
    for (let i = 1; i <= n; ++i) {
        for (let j = 1; j <= k; ++j) {
            f[i][j] = (f[i - 1][j - 1] + (i - 1) * f[i - 1][j]) % mod;
        }
    }
    return f[n][k];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：动态规划（空间优化）

我们注意到 $f[i][j]$ 只跟 $f[i - 1][j - 1]$ 和 $f[i - 1][j]$ 有关，因此可以使用一维数组优化空间复杂度。

时间复杂度 $O(n \times k)$，空间复杂度 $O(k)$。其中 $n$ 和 $k$ 分别是题目中给定的两个整数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def rearrangeSticks(self, n: int, k: int) -> int:
        mod = 10**9 + 7
        f = [1] + [0] * k
        for i in range(1, n + 1):
            for j in range(k, 0, -1):
                f[j] = (f[j] * (i - 1) + f[j - 1]) % mod
            f[0] = 0
        return f[k]
```

#### Java

```java
class Solution {
    public int rearrangeSticks(int n, int k) {
        final int mod = (int) 1e9 + 7;
        int[] f = new int[k + 1];
        f[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = k; j > 0; --j) {
                f[j] = (int) ((f[j] * (i - 1L) + f[j - 1]) % mod);
            }
            f[0] = 0;
        }
        return f[k];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int rearrangeSticks(int n, int k) {
        const int mod = 1e9 + 7;
        int f[k + 1];
        memset(f, 0, sizeof(f));
        f[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = k; j; --j) {
                f[j] = (f[j - 1] + f[j] * (i - 1LL)) % mod;
            }
            f[0] = 0;
        }
        return f[k];
    }
};
```

#### Go

```go
func rearrangeSticks(n int, k int) int {
	const mod = 1e9 + 7
	f := make([]int, k+1)
	f[0] = 1
	for i := 1; i <= n; i++ {
		for j := k; j > 0; j-- {
			f[j] = (f[j-1] + f[j]*(i-1)) % mod
		}
		f[0] = 0
	}
	return f[k]
}
```

#### TypeScript

```ts
function rearrangeSticks(n: number, k: number): number {
    const mod = 10 ** 9 + 7;
    const f: number[] = Array(n + 1).fill(0);
    f[0] = 1;
    for (let i = 1; i <= n; ++i) {
        for (let j = k; j; --j) {
            f[j] = (f[j] * (i - 1) + f[j - 1]) % mod;
        }
        f[0] = 0;
    }
    return f[k];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1867. 最大数量高于平均水平的订单 🔒](https://leetcode.cn/problems/orders-with-maximum-quantity-above-average){#1867}

{{< tabs "1867" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    t AS (
        SELECT
            order_id,
            MAX(quantity) AS max_quantity,
            SUM(quantity) / COUNT(1) AS avg_quantity
        FROM OrdersDetails
        GROUP BY order_id
    )
SELECT order_id
FROM t
WHERE max_quantity > (SELECT MAX(avg_quantity) FROM t);
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>&nbsp;<code>OrdersDetails</code> 表</p>

<pre>
+-------------+------+
| Column Name | Type |
+-------------+------+
| order_id    | int  |
| product_id  | int  |
| quantity    | int  |
+-------------+------+
(order_id, product_id) 是此表的主键。
单个订单表示为多行，订单中的每个产品对应一行。
此表的每一行都包含订单id中产品id的订购数量。
</pre>

<p>&nbsp;</p>

<p>您正在运行一个电子商务网站，该网站正在寻找不平衡的订单。不平衡订单的订单最大数量严格大于每个订单（包括订单本身）的平均数量。</p>

<p>订单的平均数量计算为（订单中所有产品的总数量）/（订单中不同产品的数量）。订单的最大数量是订单中任何单个产品的最高数量。</p>

<p>编写SQL查询以查找所有不平衡订单的订单id。</p>

<p>按任意顺序返回结果表。</p>

<p>查询结果格式如下例所示。</p>

<p>&nbsp;</p>

<p><strong>示例:</strong></p>

<pre>
<strong>输入:</strong> 
OrdersDetails 表:
+----------+------------+----------+
| order_id | product_id | quantity |
+----------+------------+----------+
| 1        | 1          | 12       |
| 1        | 2          | 10       |
| 1        | 3          | 15       |
| 2        | 1          | 8        |
| 2        | 4          | 4        |
| 2        | 5          | 6        |
| 3        | 3          | 5        |
| 3        | 4          | 18       |
| 4        | 5          | 2        |
| 4        | 6          | 8        |
| 5        | 7          | 9        |
| 5        | 8          | 9        |
| 3        | 9          | 20       |
| 2        | 9          | 4        |
+----------+------------+----------+
<strong>输出:</strong> 
+----------+
| order_id |
+----------+
| 1        |
| 3        |
+----------+
<strong>解释:</strong> 
每份订单的平均数量为:
- order_id=1: (12+10+15)/3 = 12.3333333
- order_id=2: (8+4+6+4)/4 = 5.5
- order_id=3: (5+18+20)/3 = 14.333333
- order_id=4: (2+8)/2 = 5
- order_id=5: (9+9)/2 = 9

每个订单的最大数量为:
- order_id=1: max(12, 10, 15) = 15
- order_id=2: max(8, 4, 6, 4) = 8
- order_id=3: max(5, 18, 20) = 20
- order_id=4: max(2, 8) = 8
- order_id=5: max(9, 9) = 9

订单1和订单3是不平衡的，因为它们的最大数量超过了它们订单的平均数量。
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
WITH
    t AS (
        SELECT
            order_id,
            MAX(quantity) AS max_quantity,
            SUM(quantity) / COUNT(1) AS avg_quantity
        FROM OrdersDetails
        GROUP BY order_id
    )
SELECT order_id
FROM t
WHERE max_quantity > (SELECT MAX(avg_quantity) FROM t);
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1868. 两个行程编码数组的积 🔒](https://leetcode.cn/problems/product-of-two-run-length-encoded-arrays){#1868}

{{< tabs "1868" >}}

{{% tab "python" %}}
```python
class Solution:
    def findRLEArray(
        self, encoded1: List[List[int]], encoded2: List[List[int]]
    ) -> List[List[int]]:
        ans = []
        j = 0
        for vi, fi in encoded1:
            while fi:
                f = min(fi, encoded2[j][1])
                v = vi * encoded2[j][0]
                if ans and ans[-1][0] == v:
                    ans[-1][1] += f
                else:
                    ans.append([v, f])
                fi -= f
                encoded2[j][1] -= f
                if encoded2[j][1] == 0:
                    j += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<List<Integer>> findRLEArray(int[][] encoded1, int[][] encoded2) {
        List<List<Integer>> ans = new ArrayList<>();
        int j = 0;
        for (var e : encoded1) {
            int vi = e[0], fi = e[1];
            while (fi > 0) {
                int f = Math.min(fi, encoded2[j][1]);
                int v = vi * encoded2[j][0];
                int m = ans.size();
                if (m > 0 && ans.get(m - 1).get(0) == v) {
                    ans.get(m - 1).set(1, ans.get(m - 1).get(1) + f);
                } else {
                    ans.add(new ArrayList<>(List.of(v, f)));
                }
                fi -= f;
                encoded2[j][1] -= f;
                if (encoded2[j][1] == 0) {
                    ++j;
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
    vector<vector<int>> findRLEArray(vector<vector<int>>& encoded1, vector<vector<int>>& encoded2) {
        vector<vector<int>> ans;
        int j = 0;
        for (auto& e : encoded1) {
            int vi = e[0], fi = e[1];
            while (fi) {
                int f = min(fi, encoded2[j][1]);
                int v = vi * encoded2[j][0];
                if (!ans.empty() && ans.back()[0] == v) {
                    ans.back()[1] += f;
                } else {
                    ans.push_back({v, f});
                }
                fi -= f;
                encoded2[j][1] -= f;
                if (encoded2[j][1] == 0) {
                    ++j;
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
func findRLEArray(encoded1 [][]int, encoded2 [][]int) (ans [][]int) {
	j := 0
	for _, e := range encoded1 {
		vi, fi := e[0], e[1]
		for fi > 0 {
			f := min(fi, encoded2[j][1])
			v := vi * encoded2[j][0]
			if len(ans) > 0 && ans[len(ans)-1][0] == v {
				ans[len(ans)-1][1] += f
			} else {
				ans = append(ans, []int{v, f})
			}
			fi -= f
			encoded2[j][1] -= f
			if encoded2[j][1] == 0 {
				j++
			}
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

<p><b>行程编码（</b><strong>Run-length encoding）</strong>是一种压缩算法，能让一个含有许多段<strong>连续重复</strong>数字的整数类型数组 <code>nums</code> 以一个（通常更小的）二维数组 <code>encoded</code> 表示。每个 <code>encoded[i] = [val<sub>i</sub>, freq<sub>i</sub>]</code> 表示 <code>nums</code> 中第 <code>i</code> 段重复数字，其中 <code>val<sub>i</sub></code> 是该段重复数字，重复了 <code>freq<sub>i</sub></code> 次。</p>

<ul>
	<li>例如， <code>nums = [1,1,1,2,2,2,2,2]</code> 可表示称行程编码数组 <code>encoded = [[1,3],[2,5]]</code> 。对此数组的另一种读法是“三个 <code>1</code> ，后面有五个 <code>2</code> ”。</li>
</ul>

<p>两个行程编码数组 <code>encoded1</code> 和 <code>encoded2</code> 的积可以按下列步骤计算：</p>

<ol>
	<li>将 <code>encoded1</code> 和 <code>encoded2</code> 分别<strong>扩展</strong>成完整数组 <code>nums1</code> 和 <code>nums2</code> 。</li>
	<li>创建一个新的数组 <code>prodNums</code> ，长度为 <code>nums1.length</code> 并设 <code>prodNums[i] = nums1[i] * nums2[i]</code> 。</li>
	<li>将 <code>prodNums</code> <strong>压缩</strong>成一个行程编码数组并返回之。</li>
</ol>

<p>给定两个<strong>行程编码</strong>数组 <code>encoded1</code> 和 <code>encoded2</code> ，分别表示完整数组 <code>nums1</code> 和 <code>nums2</code> 。<code>nums1</code> 和 <code>nums2</code> 的<strong>长度相同</strong>。 每一个 <code>encoded1[i] = [val<sub>i</sub>, freq<sub>i</sub>]</code> 表示 <code>nums1</code> 中的第 <code>i</code> 段，每一个 <code>encoded2[j] = [val<sub>j</sub>, freq<sub>j</sub>]</code> 表示 <code>nums2</code> 中的第 <code>j</code> 段。</p>

<p>返回<i> </i><code>encoded1</code> 和 <code>encoded2</code> 的<strong>乘积</strong>。</p>

<p><b>注：</b>行程编码数组需压缩成可能的<strong>最小</strong>长度。</p>

<p> </p>

<p><b>示例 1:</b></p>

<pre><strong>输入:</strong> encoded1 = [[1,3],[2,3]], encoded2 = [[6,3],[3,3]]
<strong>输出:</strong> [[6,6]]
<strong>解释n:</strong> encoded1 扩展为 [1,1,1,2,2,2] ，encoded2 扩展为 [6,6,6,3,3,3]。
prodNums = [6,6,6,6,6,6]，压缩成行程编码数组 [[6,6]]。
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> encoded1 = [[1,3],[2,1],[3,2]], encoded2 = [[2,3],[3,3]]
<strong>输出:</strong> [[2,3],[6,1],[9,2]]
<strong>解释:</strong> encoded1 扩展为 [1,1,1,2,3,3] ，encoded2 扩展为 [2,2,2,3,3,3]。
prodNums = [2,2,2,6,9,9]，压缩成行程编码数组 [[2,3],[6,1],[9,2]]。
</pre>

<p> </p>

<p><b>提示：</b></p>

<ul>
	<li><code>1 &lt;= encoded1.length, encoded2.length &lt;= 10<sup>5</sup></code></li>
	<li><code>encoded1[i].length == 2</code></li>
	<li><code>encoded2[j].length == 2</code></li>
	<li>对于每一个 <code>encoded1[i]</code>， <code>1 &lt;= val<sub>i</sub>, freq<sub>i</sub> &lt;= 10<sup>4</sup></code>  </li>
	<li>对于每一个 <code>encoded2[j]</code>， <code>1 &lt;= val<sub>j</sub>, freq<sub>j</sub> &lt;= 10<sup>4</sup></code></li>
	<li><code>encoded1</code> 和 <code>encoded2</code> 表示的完整数组长度相同。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双指针

我们用两个指针 $i$ 和 $j$ 分别指向两个数组的当前位置，然后开始模拟乘法的过程。

对于当前位置 $i$ 和 $j$，我们取 $f=min(encoded1[i][1],encoded2[j][1])$，表示当前位置的乘积的频次，然后将 $v=encoded1[i][0] \times encoded2[j][0]$，表示当前位置的乘积的值。如果当前位置的乘积的值 $v$ 和上一个位置的乘积的值相同，则将当前位置的乘积的频次加到上一个位置的乘积的频次上，否则将当前位置的乘积的值和频次加到答案数组中。然后我们将 $encoded1[i][1]$ 和 $encoded2[j][1]$ 分别减去 $f$，如果 $encoded1[i][1]$ 或 $encoded2[j][1]$ 减为 $0$，则将对应的指针向后移动一位。

最后返回答案数组即可。

时间复杂度 $O(m + n)$，其中 $m$ 和 $n$ 分别是两个数组的长度。忽略答案数组的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findRLEArray(
        self, encoded1: List[List[int]], encoded2: List[List[int]]
    ) -> List[List[int]]:
        ans = []
        j = 0
        for vi, fi in encoded1:
            while fi:
                f = min(fi, encoded2[j][1])
                v = vi * encoded2[j][0]
                if ans and ans[-1][0] == v:
                    ans[-1][1] += f
                else:
                    ans.append([v, f])
                fi -= f
                encoded2[j][1] -= f
                if encoded2[j][1] == 0:
                    j += 1
        return ans
```

#### Java

```java
class Solution {
    public List<List<Integer>> findRLEArray(int[][] encoded1, int[][] encoded2) {
        List<List<Integer>> ans = new ArrayList<>();
        int j = 0;
        for (var e : encoded1) {
            int vi = e[0], fi = e[1];
            while (fi > 0) {
                int f = Math.min(fi, encoded2[j][1]);
                int v = vi * encoded2[j][0];
                int m = ans.size();
                if (m > 0 && ans.get(m - 1).get(0) == v) {
                    ans.get(m - 1).set(1, ans.get(m - 1).get(1) + f);
                } else {
                    ans.add(new ArrayList<>(List.of(v, f)));
                }
                fi -= f;
                encoded2[j][1] -= f;
                if (encoded2[j][1] == 0) {
                    ++j;
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
    vector<vector<int>> findRLEArray(vector<vector<int>>& encoded1, vector<vector<int>>& encoded2) {
        vector<vector<int>> ans;
        int j = 0;
        for (auto& e : encoded1) {
            int vi = e[0], fi = e[1];
            while (fi) {
                int f = min(fi, encoded2[j][1]);
                int v = vi * encoded2[j][0];
                if (!ans.empty() && ans.back()[0] == v) {
                    ans.back()[1] += f;
                } else {
                    ans.push_back({v, f});
                }
                fi -= f;
                encoded2[j][1] -= f;
                if (encoded2[j][1] == 0) {
                    ++j;
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func findRLEArray(encoded1 [][]int, encoded2 [][]int) (ans [][]int) {
	j := 0
	for _, e := range encoded1 {
		vi, fi := e[0], e[1]
		for fi > 0 {
			f := min(fi, encoded2[j][1])
			v := vi * encoded2[j][0]
			if len(ans) > 0 && ans[len(ans)-1][0] == v {
				ans[len(ans)-1][1] += f
			} else {
				ans = append(ans, []int{v, f})
			}
			fi -= f
			encoded2[j][1] -= f
			if encoded2[j][1] == 0 {
				j++
			}
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

# [1869. 哪种连续子字符串更长](https://leetcode.cn/problems/longer-contiguous-segments-of-ones-than-zeros){#1869}

{{< tabs "1869" >}}

{{% tab "python" %}}
```python
class Solution:
    def checkZeroOnes(self, s: str) -> bool:
        def f(x: str) -> int:
            cnt = mx = 0
            for c in s:
                if c == x:
                    cnt += 1
                    mx = max(mx, cnt)
                else:
                    cnt = 0
            return mx

        return f("1") > f("0")
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean checkZeroOnes(String s) {
        return f(s, '1') > f(s, '0');
    }

    private int f(String s, char x) {
        int cnt = 0, mx = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s.charAt(i) == x) {
                mx = Math.max(mx, ++cnt);
            } else {
                cnt = 0;
            }
        }
        return mx;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool checkZeroOnes(string s) {
        auto f = [&](char x) {
            int cnt = 0, mx = 0;
            for (char& c : s) {
                if (c == x) {
                    mx = max(mx, ++cnt);
                } else {
                    cnt = 0;
                }
            }
            return mx;
        };
        return f('1') > f('0');
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func checkZeroOnes(s string) bool {
	f := func(x rune) int {
		cnt, mx := 0, 0
		for _, c := range s {
			if c == x {
				cnt++
				mx = max(mx, cnt)
			} else {
				cnt = 0
			}
		}
		return mx
	}
	return f('1') > f('0')
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function checkZeroOnes(s: string): boolean {
    const f = (x: string): number => {
        let [mx, cnt] = [0, 0];
        for (const c of s) {
            if (c === x) {
                mx = Math.max(mx, ++cnt);
            } else {
                cnt = 0;
            }
        }
        return mx;
    };
    return f('1') > f('0');
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {string} s
 * @return {boolean}
 */
var checkZeroOnes = function (s) {
    const f = x => {
        let [mx, cnt] = [0, 0];
        for (const c of s) {
            if (c === x) {
                mx = Math.max(mx, ++cnt);
            } else {
                cnt = 0;
            }
        }
        return mx;
    };
    return f('1') > f('0');
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个二进制字符串 <code>s</code> 。如果字符串中由 <code>1</code> 组成的 <strong>最长</strong> 连续子字符串 <strong>严格长于</strong> 由 <code>0</code> 组成的 <strong>最长</strong> 连续子字符串，返回 <code>true</code> ；否则，返回 <code>false</code><em> </em>。</p>

<ul>
	<li>例如，<code>s = "<strong>11</strong>01<strong>000</strong>10"</code> 中，由 <code>1</code> 组成的最长连续子字符串的长度是 <code>2</code> ，由 <code>0</code> 组成的最长连续子字符串的长度是 <code>3</code> 。</li>
</ul>

<p>注意，如果字符串中不存在 <code>0</code> ，此时认为由 <code>0</code> 组成的最长连续子字符串的长度是 <code>0</code> 。字符串中不存在 <code>1</code> 的情况也适用此规则。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "1101"
<strong>输出：</strong>true
<strong>解释：</strong>
由 <code>1</code> 组成的最长连续子字符串的长度是 2："<strong>11</strong>01"
由 <code>0</code> 组成的最长连续子字符串的长度是 1："11<strong>0</strong>1"
由 1 组成的子字符串更长，故返回 true 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "111000"
<strong>输出：</strong>false
<strong>解释：</strong>
由 <code>1</code> 组成的最长连续子字符串的长度是 3："<strong>111</strong>000"
由<code> 0</code> 组成的最长连续子字符串的长度是 3："111<strong>000</strong>"
由 1 组成的子字符串不比由 0 组成的子字符串长，故返回 false 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "110100010"
<strong>输出：</strong>false
<strong>解释：</strong>
由 <code>1</code> 组成的最长连续子字符串的长度是 2："<strong>11</strong>0100010"
由 <code>0</code> 组成的最长连续子字符串的长度是 3："1101<strong>000</strong>10"
由 1 组成的子字符串不比由 0 组成的子字符串长，故返回 false 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= s.length <= 100</code></li>
	<li><code>s[i]</code> 不是 <code>'0'</code> 就是 <code>'1'</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：两次遍历

我们设计一个函数 $f(x)$，表示字符串 $s$ 中由 $x$ 组成的最长连续子字符串的长度。如果 $f(1) \gt f(0)$，那么返回 `true`，否则返回 `false`。

时间复杂度 $O(n)$，其中 $n$ 是字符串 $s$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def checkZeroOnes(self, s: str) -> bool:
        def f(x: str) -> int:
            cnt = mx = 0
            for c in s:
                if c == x:
                    cnt += 1
                    mx = max(mx, cnt)
                else:
                    cnt = 0
            return mx

        return f("1") > f("0")
```

#### Java

```java
class Solution {
    public boolean checkZeroOnes(String s) {
        return f(s, '1') > f(s, '0');
    }

    private int f(String s, char x) {
        int cnt = 0, mx = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s.charAt(i) == x) {
                mx = Math.max(mx, ++cnt);
            } else {
                cnt = 0;
            }
        }
        return mx;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool checkZeroOnes(string s) {
        auto f = [&](char x) {
            int cnt = 0, mx = 0;
            for (char& c : s) {
                if (c == x) {
                    mx = max(mx, ++cnt);
                } else {
                    cnt = 0;
                }
            }
            return mx;
        };
        return f('1') > f('0');
    }
};
```

#### Go

```go
func checkZeroOnes(s string) bool {
	f := func(x rune) int {
		cnt, mx := 0, 0
		for _, c := range s {
			if c == x {
				cnt++
				mx = max(mx, cnt)
			} else {
				cnt = 0
			}
		}
		return mx
	}
	return f('1') > f('0')
}
```

#### TypeScript

```ts
function checkZeroOnes(s: string): boolean {
    const f = (x: string): number => {
        let [mx, cnt] = [0, 0];
        for (const c of s) {
            if (c === x) {
                mx = Math.max(mx, ++cnt);
            } else {
                cnt = 0;
            }
        }
        return mx;
    };
    return f('1') > f('0');
}
```

#### JavaScript

```js
/**
 * @param {string} s
 * @return {boolean}
 */
var checkZeroOnes = function (s) {
    const f = x => {
        let [mx, cnt] = [0, 0];
        for (const c of s) {
            if (c === x) {
                mx = Math.max(mx, ++cnt);
            } else {
                cnt = 0;
            }
        }
        return mx;
    };
    return f('1') > f('0');
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
