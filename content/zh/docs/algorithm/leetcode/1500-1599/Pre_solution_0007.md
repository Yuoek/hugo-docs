---
title: "1560_圆形赛道上经过次数最多的扇区"
date: 2025-10-08T18:37:33+08:00
weight: 7
tags: [二分查找, 二叉搜索树, 二叉树, 分治, 动态规划, 博弈, 哈希表, 并查集, 广度优先搜索, 强连通分量, 排序, 数学, 数据库, 数组, 枚举, 树, 模拟, 深度优先搜索, 矩阵, 组合数学, 记忆化搜索, 贪心]
---

{{< markmap >}}
### [1560_圆形赛道上经过次数最多的扇区](#1560)
#### [数组](#1560)
#### [模拟](#1560)
### [1561_你可以获得的最大硬币数目](#1561)
#### [贪心](#1561)
#### [数组](#1561)
#### [数学](#1561)
#### [博弈](#1561)
#### [排序](#1561)
### [1562_查找大小为 M 的最新分组](#1562)
#### [数组](#1562)
#### [哈希表](#1562)
#### [二分查找](#1562)
#### [模拟](#1562)
### [1563_石子游戏 V](#1563)
#### [数组](#1563)
#### [数学](#1563)
#### [动态规划](#1563)
#### [博弈](#1563)
### [1564_把箱子放进仓库里 I 🔒](#1564)
#### [贪心](#1564)
#### [数组](#1564)
#### [排序](#1564)
### [1565_按月统计订单数与顾客数 🔒](#1565)
#### [数据库](#1565)
### [1566_重复至少 K 次且长度为 M 的模式](#1566)
#### [数组](#1566)
#### [枚举](#1566)
### [1567_乘积为正数的最长子数组长度](#1567)
#### [贪心](#1567)
#### [数组](#1567)
#### [动态规划](#1567)
### [1568_使陆地分离的最少天数](#1568)
#### [深度优先搜索](#1568)
#### [广度优先搜索](#1568)
#### [数组](#1568)
#### [矩阵](#1568)
#### [强连通分量](#1568)
### [1569_将子数组重新排序得到同一个二叉搜索树的方案数](#1569)
#### [树](#1569)
#### [并查集](#1569)
#### [二叉搜索树](#1569)
#### [记忆化搜索](#1569)
#### [数组](#1569)
#### [数学](#1569)
#### [分治](#1569)
#### [动态规划](#1569)
#### [二叉树](#1569)
#### [组合数学](#1569)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1560_圆形赛道上经过次数最多的扇区
___
#### 数组
___
#### 模拟
---
### 1561_你可以获得的最大硬币数目
___
#### 贪心
___
#### 数组
___
#### 数学
___
#### 博弈
___
#### 排序
---
### 1562_查找大小为 M 的最新分组
___
#### 数组
___
#### 哈希表
___
#### 二分查找
___
#### 模拟
---
### 1563_石子游戏 V
___
#### 数组
___
#### 数学
___
#### 动态规划
___
#### 博弈
---
### 1564_把箱子放进仓库里 I 🔒
___
#### 贪心
___
#### 数组
___
#### 排序
---
### 1565_按月统计订单数与顾客数 🔒
___
#### 数据库
---
### 1566_重复至少 K 次且长度为 M 的模式
___
#### 数组
___
#### 枚举
---
### 1567_乘积为正数的最长子数组长度
___
#### 贪心
___
#### 数组
___
#### 动态规划
---
### 1568_使陆地分离的最少天数
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 数组
___
#### 矩阵
___
#### 强连通分量
---
### 1569_将子数组重新排序得到同一个二叉搜索树的方案数
___
#### 树
___
#### 并查集
___
#### 二叉搜索树
___
#### 记忆化搜索
___
#### 数组
___
#### 数学
___
#### 分治
___
#### 动态规划
___
#### 二叉树
___
#### 组合数学
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 二叉搜索树 | 二叉树 |
| 分治 | 动态规划 | 博弈 |
| 哈希表 | 并查集 | 广度优先搜索 |
| 强连通分量 | 排序 | 数学 |
| 数据库 | 数组 | 枚举 |
| 树 | 模拟 | 深度优先搜索 |
| 矩阵 | 组合数学 | 记忆化搜索 |
| 贪心 |  |  |

# [1560. 圆形赛道上经过次数最多的扇区](https://leetcode.cn/problems/most-visited-sector-in-a-circular-track){#1560}

{{< tabs "1560" >}}

{{% tab "python" %}}
```python
class Solution:
    def mostVisited(self, n: int, rounds: List[int]) -> List[int]:
        if rounds[0] <= rounds[-1]:
            return list(range(rounds[0], rounds[-1] + 1))
        return list(range(1, rounds[-1] + 1)) + list(range(rounds[0], n + 1))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<Integer> mostVisited(int n, int[] rounds) {
        int m = rounds.length - 1;
        List<Integer> ans = new ArrayList<>();
        if (rounds[0] <= rounds[m]) {
            for (int i = rounds[0]; i <= rounds[m]; ++i) {
                ans.add(i);
            }
        } else {
            for (int i = 1; i <= rounds[m]; ++i) {
                ans.add(i);
            }
            for (int i = rounds[0]; i <= n; ++i) {
                ans.add(i);
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
    vector<int> mostVisited(int n, vector<int>& rounds) {
        int m = rounds.size() - 1;
        vector<int> ans;
        if (rounds[0] <= rounds[m]) {
            for (int i = rounds[0]; i <= rounds[m]; ++i) {
                ans.push_back(i);
            }
        } else {
            for (int i = 1; i <= rounds[m]; ++i) {
                ans.push_back(i);
            }
            for (int i = rounds[0]; i <= n; ++i) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func mostVisited(n int, rounds []int) []int {
	m := len(rounds) - 1
	var ans []int
	if rounds[0] <= rounds[m] {
		for i := rounds[0]; i <= rounds[m]; i++ {
			ans = append(ans, i)
		}
	} else {
		for i := 1; i <= rounds[m]; i++ {
			ans = append(ans, i)
		}
		for i := rounds[0]; i <= n; i++ {
			ans = append(ans, i)
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function mostVisited(n: number, rounds: number[]): number[] {
    const ans: number[] = [];
    const m = rounds.length - 1;
    if (rounds[0] <= rounds[m]) {
        for (let i = rounds[0]; i <= rounds[m]; ++i) {
            ans.push(i);
        }
    } else {
        for (let i = 1; i <= rounds[m]; ++i) {
            ans.push(i);
        }
        for (let i = rounds[0]; i <= n; ++i) {
            ans.push(i);
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

<p>给你一个整数 <code>n</code> 和一个整数数组 <code>rounds</code> 。有一条圆形赛道由 <code>n</code> 个扇区组成，扇区编号从 <code>1</code> 到 <code>n</code> 。现将在这条赛道上举办一场马拉松比赛，该马拉松全程由 <code>m</code> 个阶段组成。其中，第 <code>i</code> 个阶段将会从扇区 <code>rounds[i - 1]</code> 开始，到扇区 <code>rounds[i]</code> 结束。举例来说，第 <code>1</code> 阶段从&nbsp;<code>rounds[0]</code>&nbsp;开始，到&nbsp;<code>rounds[1]</code>&nbsp;结束。</p>

<p>请你以数组形式返回经过次数最多的那几个扇区，按扇区编号 <strong>升序</strong> 排列。</p>

<p>注意，赛道按扇区编号升序逆时针形成一个圆（请参见第一个示例）。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1560.Most%20Visited%20Sector%20in%20%20a%20Circular%20Track/images/3rd45e.jpg" style="height: 341px; width: 433px;"></p>

<pre><strong>输入：</strong>n = 4, rounds = [1,3,1,2]
<strong>输出：</strong>[1,2]
<strong>解释：</strong>本场马拉松比赛从扇区 1 开始。经过各个扇区的次序如下所示：
1 --&gt; 2 --&gt; 3（阶段 1 结束）--&gt; 4 --&gt; 1（阶段 2 结束）--&gt; 2（阶段 3 结束，即本场马拉松结束）
其中，扇区 1 和 2 都经过了两次，它们是经过次数最多的两个扇区。扇区 3 和 4 都只经过了一次。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>n = 2, rounds = [2,1,2,1,2,1,2,1,2]
<strong>输出：</strong>[2]
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>n = 7, rounds = [1,3,5,7]
<strong>输出：</strong>[1,2,3,4,5,6,7]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 100</code></li>
	<li><code>1 &lt;= m &lt;= 100</code></li>
	<li><code>rounds.length == m + 1</code></li>
	<li><code>1 &lt;= rounds[i] &lt;= n</code></li>
	<li><code>rounds[i] != rounds[i + 1]</code> ，其中 <code>0 &lt;= i &lt; m</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：考虑开始、结束的位置关系

由于每个阶段的结束位置是下一个阶段的开始位置，并且每个阶段都是逆时针方向的，所以我们可以根据开始和结束的位置关系来确定每个扇区的经过次数。

如果 $\textit{rounds}[0] \leq \textit{rounds}[m]$，那么从 $\textit{rounds}[0]$ 开始，到 $\textit{rounds}[m]$ 结束的所有扇区经过的次数是最多的，我们可以直接返回这个区间内的所有扇区。

否则，从 $1$ 开始，到 $\textit{rounds}[m]$ 结束的所有扇区和从 $\textit{rounds}[0]$ 开始，到 $n$ 结束的所有扇区的并集是经过次数最多的，我们可以返回这两个区间的并集。

时间复杂度 $O(n)$，其中 $n$ 是扇区的个数。忽略答案数组的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def mostVisited(self, n: int, rounds: List[int]) -> List[int]:
        if rounds[0] <= rounds[-1]:
            return list(range(rounds[0], rounds[-1] + 1))
        return list(range(1, rounds[-1] + 1)) + list(range(rounds[0], n + 1))
```

#### Java

```java
class Solution {
    public List<Integer> mostVisited(int n, int[] rounds) {
        int m = rounds.length - 1;
        List<Integer> ans = new ArrayList<>();
        if (rounds[0] <= rounds[m]) {
            for (int i = rounds[0]; i <= rounds[m]; ++i) {
                ans.add(i);
            }
        } else {
            for (int i = 1; i <= rounds[m]; ++i) {
                ans.add(i);
            }
            for (int i = rounds[0]; i <= n; ++i) {
                ans.add(i);
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
    vector<int> mostVisited(int n, vector<int>& rounds) {
        int m = rounds.size() - 1;
        vector<int> ans;
        if (rounds[0] <= rounds[m]) {
            for (int i = rounds[0]; i <= rounds[m]; ++i) {
                ans.push_back(i);
            }
        } else {
            for (int i = 1; i <= rounds[m]; ++i) {
                ans.push_back(i);
            }
            for (int i = rounds[0]; i <= n; ++i) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func mostVisited(n int, rounds []int) []int {
	m := len(rounds) - 1
	var ans []int
	if rounds[0] <= rounds[m] {
		for i := rounds[0]; i <= rounds[m]; i++ {
			ans = append(ans, i)
		}
	} else {
		for i := 1; i <= rounds[m]; i++ {
			ans = append(ans, i)
		}
		for i := rounds[0]; i <= n; i++ {
			ans = append(ans, i)
		}
	}
	return ans
}
```

#### TypeScript

```ts
function mostVisited(n: number, rounds: number[]): number[] {
    const ans: number[] = [];
    const m = rounds.length - 1;
    if (rounds[0] <= rounds[m]) {
        for (let i = rounds[0]; i <= rounds[m]; ++i) {
            ans.push(i);
        }
    } else {
        for (let i = 1; i <= rounds[m]; ++i) {
            ans.push(i);
        }
        for (let i = rounds[0]; i <= n; ++i) {
            ans.push(i);
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

# [1561. 你可以获得的最大硬币数目](https://leetcode.cn/problems/maximum-number-of-coins-you-can-get){#1561}

{{< tabs "1561" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxCoins(self, piles: List[int]) -> int:
        piles.sort()
        return sum(piles[len(piles) // 3 :][::2])
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxCoins(int[] piles) {
        Arrays.sort(piles);
        int ans = 0;
        for (int i = piles.length / 3; i < piles.length; i += 2) {
            ans += piles[i];
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
    int maxCoins(vector<int>& piles) {
        ranges::sort(piles);
        int ans = 0;
        for (int i = piles.size() / 3; i < piles.size(); i += 2) {
            ans += piles[i];
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxCoins(piles []int) (ans int) {
	sort.Ints(piles)
	for i := len(piles) / 3; i < len(piles); i += 2 {
		ans += piles[i]
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxCoins(piles: number[]): number {
    piles.sort((a, b) => a - b);
    let ans = 0;
    for (let i = piles.length / 3; i < piles.length; i += 2) {
        ans += piles[i];
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn max_coins(mut piles: Vec<i32>) -> i32 {
        piles.sort();
        let mut ans = 0;
        for i in (piles.len() / 3..piles.len()).step_by(2) {
            ans += piles[i];
        }
        ans
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
int compare(const void* a, const void* b) {
    return (*(int*) a - *(int*) b);
}

int maxCoins(int* piles, int pilesSize) {
    qsort(piles, pilesSize, sizeof(int), compare);
    int ans = 0;
    for (int i = pilesSize / 3; i < pilesSize; i += 2) {
        ans += piles[i];
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

<p>有 3n 堆数目不一的硬币，你和你的朋友们打算按以下方式分硬币：</p>

<ul>
	<li>每一轮中，你将会选出 <strong>任意</strong> 3 堆硬币（不一定连续）。</li>
	<li>Alice 将会取走硬币数量最多的那一堆。</li>
	<li>你将会取走硬币数量第二多的那一堆。</li>
	<li>Bob 将会取走最后一堆。</li>
	<li>重复这个过程，直到没有更多硬币。</li>
</ul>

<p>给你一个整数数组 <code>piles</code> ，其中 <code>piles[i]</code> 是第 <code>i</code> 堆中硬币的数目。</p>

<p>返回你可以获得的最大硬币数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>piles = [2,4,1,2,7,8]
<strong>输出：</strong>9
<strong>解释：</strong>选出 (2, 7, 8) ，Alice 取走 8 枚硬币的那堆，你取走 <strong>7</strong> 枚硬币的那堆，Bob 取走最后一堆。
选出 (1, 2, 4) , Alice 取走 4 枚硬币的那堆，你取走 <strong>2</strong> 枚硬币的那堆，Bob 取走最后一堆。
你可以获得的最大硬币数目：7 + 2 = 9.
考虑另外一种情况，如果选出的是 (1, <strong>2</strong>, 8) 和 (2, <strong>4</strong>, 7) ，你就只能得到 2 + 4 = 6 枚硬币，这不是最优解。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>piles = [2,4,5]
<strong>输出：</strong>4
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>piles = [9,8,7,6,5,1,2,3,4]
<strong>输出：</strong>18
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= piles.length &lt;= 10^5</code></li>
	<li><code>piles.length % 3 == 0</code></li>
	<li><code>1 &lt;= piles[i] &lt;= 10^4</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 排序

为了让我们获得的硬币数量最多，我们可以贪心地让 Bob 拿走最少的 $n$ 堆硬币。我们每次先让 Alice 拿走最多的一堆硬币，然后让我们拿走第二多的一堆硬币，依次循环，直到没有硬币可拿。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 是硬币堆数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxCoins(self, piles: List[int]) -> int:
        piles.sort()
        return sum(piles[len(piles) // 3 :][::2])
```

#### Java

```java
class Solution {
    public int maxCoins(int[] piles) {
        Arrays.sort(piles);
        int ans = 0;
        for (int i = piles.length / 3; i < piles.length; i += 2) {
            ans += piles[i];
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxCoins(vector<int>& piles) {
        ranges::sort(piles);
        int ans = 0;
        for (int i = piles.size() / 3; i < piles.size(); i += 2) {
            ans += piles[i];
        }
        return ans;
    }
};
```

#### Go

```go
func maxCoins(piles []int) (ans int) {
	sort.Ints(piles)
	for i := len(piles) / 3; i < len(piles); i += 2 {
		ans += piles[i]
	}
	return
}
```

#### TypeScript

```ts
function maxCoins(piles: number[]): number {
    piles.sort((a, b) => a - b);
    let ans = 0;
    for (let i = piles.length / 3; i < piles.length; i += 2) {
        ans += piles[i];
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn max_coins(mut piles: Vec<i32>) -> i32 {
        piles.sort();
        let mut ans = 0;
        for i in (piles.len() / 3..piles.len()).step_by(2) {
            ans += piles[i];
        }
        ans
    }
}
```

#### C

```c
int compare(const void* a, const void* b) {
    return (*(int*) a - *(int*) b);
}

int maxCoins(int* piles, int pilesSize) {
    qsort(piles, pilesSize, sizeof(int), compare);
    int ans = 0;
    for (int i = pilesSize / 3; i < pilesSize; i += 2) {
        ans += piles[i];
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1562. 查找大小为 M 的最新分组](https://leetcode.cn/problems/find-latest-group-of-size-m){#1562}

{{< tabs "1562" >}}

{{% tab "python" %}}
```python
class Solution:
    def findLatestStep(self, arr: List[int], m: int) -> int:
        n = len(arr)
        if m == n:
            return n
        cnt = [0] * (n + 2)
        ans = -1
        for i, v in enumerate(arr):
            v -= 1
            l, r = cnt[v - 1], cnt[v + 1]
            if l == m or r == m:
                ans = i
            cnt[v - l] = cnt[v + r] = l + r + 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int findLatestStep(int[] arr, int m) {
        int n = arr.length;
        if (m == n) {
            return n;
        }
        int[] cnt = new int[n + 2];
        int ans = -1;
        for (int i = 0; i < n; ++i) {
            int v = arr[i];
            int l = cnt[v - 1], r = cnt[v + 1];
            if (l == m || r == m) {
                ans = i;
            }
            cnt[v - l] = l + r + 1;
            cnt[v + r] = l + r + 1;
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
    int findLatestStep(vector<int>& arr, int m) {
        int n = arr.size();
        if (m == n) return n;
        vector<int> cnt(n + 2);
        int ans = -1;
        for (int i = 0; i < n; ++i) {
            int v = arr[i];
            int l = cnt[v - 1], r = cnt[v + 1];
            if (l == m || r == m) ans = i;
            cnt[v - l] = cnt[v + r] = l + r + 1;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findLatestStep(arr []int, m int) int {
	n := len(arr)
	if m == n {
		return n
	}
	cnt := make([]int, n+2)
	ans := -1
	for i, v := range arr {
		l, r := cnt[v-1], cnt[v+1]
		if l == m || r == m {
			ans = i
		}
		cnt[v-l], cnt[v+r] = l+r+1, l+r+1
	}
	return ans
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
const findLatestStep = function (arr, m) {
    function find(x) {
        if (p[x] !== x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    function union(a, b) {
        const pa = find(a);
        const pb = find(b);
        if (pa === pb) {
            return;
        }
        p[pa] = pb;
        size[pb] += size[pa];
    }

    const n = arr.length;
    if (m === n) {
        return n;
    }
    const vis = Array(n).fill(false);
    const p = Array.from({ length: n }, (_, i) => i);
    const size = Array(n).fill(1);
    let ans = -1;
    for (let i = 0; i < n; ++i) {
        const v = arr[i] - 1;
        if (v > 0 && vis[v - 1]) {
            if (size[find(v - 1)] === m) {
                ans = i;
            }
            union(v, v - 1);
        }
        if (v < n - 1 && vis[v + 1]) {
            if (size[find(v + 1)] === m) {
                ans = i;
            }
            union(v, v + 1);
        }
        vis[v] = true;
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

<p>给你一个数组 <code>arr</code> ，该数组表示一个从 <code>1</code> 到 <code>n</code> 的数字排列。有一个长度为 <code>n</code> 的二进制字符串，该字符串上的所有位最初都设置为 <code>0</code> 。</p>

<p>在从 <code>1</code> 到 <code>n</code> 的每个步骤 <code>i</code> 中（假设二进制字符串和 <code>arr</code> 都是从 <code>1</code> 开始索引的情况下），二进制字符串上位于位置 <code>arr[i]</code> 的位将会设为 <code>1</code> 。</p>

<p>给你一个整数 <code>m</code> ，请你找出二进制字符串上存在长度为 <code>m</code> 的一组 <code>1</code> 的最后步骤。一组 <code>1</code> 是一个连续的、由 <code>1</code> 组成的子串，且左右两边不再有可以延伸的 <code>1</code> 。</p>

<p>返回存在长度 <strong>恰好</strong> 为 <code>m</code> 的 <strong>一组 <code>1</code>&nbsp;</strong> 的最后步骤。如果不存在这样的步骤，请返回 <code>-1</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>arr = [3,5,1,2,4], m = 1
<strong>输出：</strong>4
<strong>解释：
</strong>步骤 1：&quot;00<strong>1</strong>00&quot;，由 1 构成的组：[&quot;1&quot;]
步骤 2：&quot;0010<strong>1</strong>&quot;，由 1 构成的组：[&quot;1&quot;, &quot;1&quot;]
步骤 3：&quot;<strong>1</strong>0101&quot;，由 1 构成的组：[&quot;1&quot;, &quot;1&quot;, &quot;1&quot;]
步骤 4：&quot;1<strong>1</strong>101&quot;，由 1 构成的组：[&quot;111&quot;, &quot;1&quot;]
步骤 5：&quot;111<strong>1</strong>1&quot;，由 1 构成的组：[&quot;11111&quot;]
存在长度为 1 的一组 1 的最后步骤是步骤 4 。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>arr = [3,1,5,4,2], m = 2
<strong>输出：</strong>-1
<strong>解释：
</strong>步骤 1：&quot;00<strong>1</strong>00&quot;，由 1 构成的组：[&quot;1&quot;]
步骤 2：&quot;<strong>1</strong>0100&quot;，由 1 构成的组：[&quot;1&quot;, &quot;1&quot;]
步骤 3：&quot;1010<strong>1</strong>&quot;，由 1 构成的组：[&quot;1&quot;, &quot;1&quot;, &quot;1&quot;]
步骤 4：&quot;101<strong>1</strong>1&quot;，由 1 构成的组：[&quot;1&quot;, &quot;111&quot;]
步骤 5：&quot;1<strong>1</strong>111&quot;，由 1 构成的组：[&quot;11111&quot;]
不管是哪一步骤都无法形成长度为 2 的一组 1 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>arr = [1], m = 1
<strong>输出：</strong>1
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>arr = [2,1], m = 2
<strong>输出：</strong>2
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == arr.length</code></li>
	<li><code>1 &lt;= n &lt;= 10^5</code></li>
	<li><code>1 &lt;= arr[i] &lt;= n</code></li>
	<li><code>arr</code> 中的所有整数 <strong>互不相同</strong></li>
	<li><code>1 &lt;= m&nbsp;&lt;= arr.length</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：并查集

正向遍历 $arr$，利用并查集动态维护每组 $1$ 的长度。

时间复杂度 $O(n \times \log n)$。

相似题目：

-   [2334. 元素值大于变化阈值的子数组](https://github.com/doocs/leetcode/blob/main/solution/2300-2399/2334.Subarray%20With%20Elements%20Greater%20Than%20Varying%20Threshold/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findLatestStep(self, arr: List[int], m: int) -> int:
        def find(x):
            if p[x] != x:
                p[x] = find(p[x])
            return p[x]

        def union(a, b):
            pa, pb = find(a), find(b)
            if pa == pb:
                return
            p[pa] = pb
            size[pb] += size[pa]

        n = len(arr)
        if m == n:
            return n
        vis = [False] * n
        p = list(range(n))
        size = [1] * n
        ans = -1
        for i, v in enumerate(arr):
            v -= 1
            if v and vis[v - 1]:
                if size[find(v - 1)] == m:
                    ans = i
                union(v, v - 1)
            if v < n - 1 and vis[v + 1]:
                if size[find(v + 1)] == m:
                    ans = i
                union(v, v + 1)
            vis[v] = True
        return ans
```

#### Java

```java
class Solution {
    private int[] p;
    private int[] size;

    public int findLatestStep(int[] arr, int m) {
        int n = arr.length;
        if (m == n) {
            return n;
        }
        boolean[] vis = new boolean[n];
        p = new int[n];
        size = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
            size[i] = 1;
        }
        int ans = -1;
        for (int i = 0; i < n; ++i) {
            int v = arr[i] - 1;
            if (v > 0 && vis[v - 1]) {
                if (size[find(v - 1)] == m) {
                    ans = i;
                }
                union(v, v - 1);
            }
            if (v < n - 1 && vis[v + 1]) {
                if (size[find(v + 1)] == m) {
                    ans = i;
                }
                union(v, v + 1);
            }
            vis[v] = true;
        }
        return ans;
    }

    private int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    private void union(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) {
            return;
        }
        p[pa] = pb;
        size[pb] += size[pa];
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> p;
    vector<int> size;

    int findLatestStep(vector<int>& arr, int m) {
        int n = arr.size();
        if (m == n) return n;
        p.resize(n);
        size.assign(n, 1);
        for (int i = 0; i < n; ++i) p[i] = i;
        int ans = -1;
        vector<int> vis(n);
        for (int i = 0; i < n; ++i) {
            int v = arr[i] - 1;
            if (v && vis[v - 1]) {
                if (size[find(v - 1)] == m) ans = i;
                unite(v, v - 1);
            }
            if (v < n - 1 && vis[v + 1]) {
                if (size[find(v + 1)] == m) ans = i;
                unite(v, v + 1);
            }
            vis[v] = true;
        }
        return ans;
    }

    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    void unite(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) return;
        p[pa] = pb;
        size[pb] += size[pa];
    }
};
```

#### Go

```go
func findLatestStep(arr []int, m int) int {
	n := len(arr)
	if m == n {
		return n
	}
	p := make([]int, n)
	size := make([]int, n)
	vis := make([]bool, n)
	for i := range p {
		p[i] = i
		size[i] = 1
	}
	var find func(int) int
	find = func(x int) int {
		if p[x] != x {
			p[x] = find(p[x])
		}
		return p[x]
	}
	union := func(a, b int) {
		pa, pb := find(a), find(b)
		if pa == pb {
			return
		}
		p[pa] = pb
		size[pb] += size[pa]
	}

	ans := -1
	for i, v := range arr {
		v--
		if v > 0 && vis[v-1] {
			if size[find(v-1)] == m {
				ans = i
			}
			union(v, v-1)
		}
		if v < n-1 && vis[v+1] {
			if size[find(v+1)] == m {
				ans = i
			}
			union(v, v+1)
		}
		vis[v] = true
	}
	return ans
}
```

#### JavaScript

```js
const findLatestStep = function (arr, m) {
    function find(x) {
        if (p[x] !== x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    function union(a, b) {
        const pa = find(a);
        const pb = find(b);
        if (pa === pb) {
            return;
        }
        p[pa] = pb;
        size[pb] += size[pa];
    }

    const n = arr.length;
    if (m === n) {
        return n;
    }
    const vis = Array(n).fill(false);
    const p = Array.from({ length: n }, (_, i) => i);
    const size = Array(n).fill(1);
    let ans = -1;
    for (let i = 0; i < n; ++i) {
        const v = arr[i] - 1;
        if (v > 0 && vis[v - 1]) {
            if (size[find(v - 1)] === m) {
                ans = i;
            }
            union(v, v - 1);
        }
        if (v < n - 1 && vis[v + 1]) {
            if (size[find(v + 1)] === m) {
                ans = i;
            }
            union(v, v + 1);
        }
        vis[v] = true;
    }
    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：动态维护区间端点的长度

我们其实并不需要去通过查找并查集来获取每个区间长度，我们只需要在每个区间端点处记录每个区间长度，由于合并的时候**只会访问区间端点**，所以合并区间的时候修改端点区间长度即可。

时间复杂度 $O(n)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findLatestStep(self, arr: List[int], m: int) -> int:
        n = len(arr)
        if m == n:
            return n
        cnt = [0] * (n + 2)
        ans = -1
        for i, v in enumerate(arr):
            v -= 1
            l, r = cnt[v - 1], cnt[v + 1]
            if l == m or r == m:
                ans = i
            cnt[v - l] = cnt[v + r] = l + r + 1
        return ans
```

#### Java

```java
class Solution {
    public int findLatestStep(int[] arr, int m) {
        int n = arr.length;
        if (m == n) {
            return n;
        }
        int[] cnt = new int[n + 2];
        int ans = -1;
        for (int i = 0; i < n; ++i) {
            int v = arr[i];
            int l = cnt[v - 1], r = cnt[v + 1];
            if (l == m || r == m) {
                ans = i;
            }
            cnt[v - l] = l + r + 1;
            cnt[v + r] = l + r + 1;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        int n = arr.size();
        if (m == n) return n;
        vector<int> cnt(n + 2);
        int ans = -1;
        for (int i = 0; i < n; ++i) {
            int v = arr[i];
            int l = cnt[v - 1], r = cnt[v + 1];
            if (l == m || r == m) ans = i;
            cnt[v - l] = cnt[v + r] = l + r + 1;
        }
        return ans;
    }
};
```

#### Go

```go
func findLatestStep(arr []int, m int) int {
	n := len(arr)
	if m == n {
		return n
	}
	cnt := make([]int, n+2)
	ans := -1
	for i, v := range arr {
		l, r := cnt[v-1], cnt[v+1]
		if l == m || r == m {
			ans = i
		}
		cnt[v-l], cnt[v+r] = l+r+1, l+r+1
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1563. 石子游戏 V](https://leetcode.cn/problems/stone-game-v){#1563}

{{< tabs "1563" >}}

{{% tab "python" %}}
```python
def max(a: int, b: int) -> int:
    return a if a > b else b


class Solution:
    def stoneGameV(self, stoneValue: List[int]) -> int:
        @cache
        def dfs(i: int, j: int) -> int:
            if i >= j:
                return 0
            ans = l = 0
            r = s[j + 1] - s[i]
            for k in range(i, j):
                l += stoneValue[k]
                r -= stoneValue[k]
                if l < r:
                    if ans >= l * 2:
                        continue
                    ans = max(ans, l + dfs(i, k))
                elif l > r:
                    if ans >= r * 2:
                        break
                    ans = max(ans, r + dfs(k + 1, j))
                else:
                    ans = max(ans, max(l + dfs(i, k), r + dfs(k + 1, j)))
            return ans

        s = list(accumulate(stoneValue, initial=0))
        return dfs(0, len(stoneValue) - 1)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int n;
    private int[] s;
    private int[] nums;
    private Integer[][] f;

    public int stoneGameV(int[] stoneValue) {
        n = stoneValue.length;
        s = new int[n + 1];
        nums = stoneValue;
        f = new Integer[n][n];
        for (int i = 1; i <= n; ++i) {
            s[i] = s[i - 1] + nums[i - 1];
        }
        return dfs(0, n - 1);
    }

    private int dfs(int i, int j) {
        if (i >= j) {
            return 0;
        }
        if (f[i][j] != null) {
            return f[i][j];
        }
        int ans = 0, l = 0, r = s[j + 1] - s[i];
        for (int k = i; k < j; ++k) {
            l += nums[k];
            r -= nums[k];
            if (l < r) {
                if (ans > l * 2) {
                    continue;
                }
                ans = Math.max(ans, l + dfs(i, k));
            } else if (l > r) {
                if (ans > r * 2) {
                    break;
                }
                ans = Math.max(ans, r + dfs(k + 1, j));
            } else {
                ans = Math.max(ans, Math.max(l + dfs(i, k), r + dfs(k + 1, j)));
            }
        }
        return f[i][j] = ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        int s[n + 1];
        s[0] = 0;
        for (int i = 0; i < n; i++) {
            s[i + 1] = s[i] + stoneValue[i];
        }
        int f[n][n];
        memset(f, -1, sizeof(f));
        auto dfs = [&](this auto&& dfs, int i, int j) -> int {
            if (i >= j) {
                return 0;
            }
            if (f[i][j] != -1) {
                return f[i][j];
            }
            int ans = 0, l = 0, r = s[j + 1] - s[i];
            for (int k = i; k < j; ++k) {
                l += stoneValue[k];
                r -= stoneValue[k];
                if (l < r) {
                    if (ans > l * 2) {
                        continue;
                    }
                    ans = max(ans, l + dfs(i, k));
                } else if (l > r) {
                    if (ans > r * 2) {
                        break;
                    }
                    ans = max(ans, r + dfs(k + 1, j));
                } else {
                    ans = max({ans, l + dfs(i, k), r + dfs(k + 1, j)});
                }
            }
            return f[i][j] = ans;
        };
        return dfs(0, n - 1);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func stoneGameV(stoneValue []int) int {
	n := len(stoneValue)
	s := make([]int, n+1)
	for i, x := range stoneValue {
		s[i+1] = s[i] + x
	}
	f := make([][]int, n)
	for i := range f {
		f[i] = make([]int, n)
		for j := range f[i] {
			f[i][j] = -1
		}
	}
	var dfs func(int, int) int
	dfs = func(i, j int) int {
		if i >= j {
			return 0
		}
		if f[i][j] != -1 {
			return f[i][j]
		}
		ans, l, r := 0, 0, s[j+1]-s[i]
		for k := i; k < j; k++ {
			l += stoneValue[k]
			r -= stoneValue[k]
			if l < r {
				if ans > l*2 {
					continue
				}
				ans = max(ans, dfs(i, k)+l)
			} else if l > r {
				if ans > r*2 {
					break
				}
				ans = max(ans, dfs(k+1, j)+r)
			} else {
				ans = max(ans, max(dfs(i, k), dfs(k+1, j))+l)
			}
		}
		f[i][j] = ans
		return ans
	}
	return dfs(0, n-1)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function stoneGameV(stoneValue: number[]): number {
    const n = stoneValue.length;
    const s: number[] = Array(n + 1).fill(0);
    for (let i = 0; i < n; i++) {
        s[i + 1] = s[i] + stoneValue[i];
    }
    const f: number[][] = Array.from({ length: n }, () => Array(n).fill(-1));

    const dfs = (i: number, j: number): number => {
        if (i >= j) {
            return 0;
        }
        if (f[i][j] !== -1) {
            return f[i][j];
        }
        let [ans, l, r] = [0, 0, s[j + 1] - s[i]];
        for (let k = i; k < j; ++k) {
            l += stoneValue[k];
            r -= stoneValue[k];
            if (l < r) {
                if (ans > l * 2) {
                    continue;
                }
                ans = Math.max(ans, l + dfs(i, k));
            } else if (l > r) {
                if (ans > r * 2) {
                    break;
                }
                ans = Math.max(ans, r + dfs(k + 1, j));
            } else {
                ans = Math.max(ans, l + dfs(i, k), r + dfs(k + 1, j));
            }
        }
        return (f[i][j] = ans);
    };

    return dfs(0, n - 1);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>几块石子 <strong>排成一行</strong> ，每块石子都有一个关联值，关联值为整数，由数组 <code>stoneValue</code> 给出。</p>

<p>游戏中的每一轮：Alice 会将这行石子分成两个 <strong>非空行</strong>（即，左侧行和右侧行）；Bob 负责计算每一行的值，即此行中所有石子的值的总和。Bob 会丢弃值最大的行，Alice 的得分为剩下那行的值（每轮累加）。如果两行的值相等，Bob 让 Alice 决定丢弃哪一行。下一轮从剩下的那一行开始。</p>

<p>只 <strong>剩下一块石子</strong> 时，游戏结束。Alice 的分数最初为 <strong><code>0</code></strong> 。</p>

<p>返回 <strong>Alice 能够获得的最大分数</strong><em> 。</em></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>stoneValue = [6,2,3,4,5,5]
<strong>输出：</strong>18
<strong>解释：</strong>在第一轮中，Alice 将行划分为 [6，2，3]，[4，5，5] 。左行的值是 11 ，右行的值是 14 。Bob 丢弃了右行，Alice 的分数现在是 11 。
在第二轮中，Alice 将行分成 [6]，[2，3] 。这一次 Bob 扔掉了左行，Alice 的分数变成了 16（11 + 5）。
最后一轮 Alice 只能将行分成 [2]，[3] 。Bob 扔掉右行，Alice 的分数现在是 18（16 + 2）。游戏结束，因为这行只剩下一块石头了。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>stoneValue = [7,7,7,7,7,7,7]
<strong>输出：</strong>28
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>stoneValue = [4]
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= stoneValue.length &lt;= 500</code></li>
	<li><code>1 &lt;=&nbsp;stoneValue[i] &lt;= 10<sup>6</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索 + 剪枝

我们先预处理出前缀和数组 $\textit{s}$，其中 $\textit{s}[i]$ 表示数组 $\textit{stoneValue}$ 前 $i$ 个元素的和。

接下来，我们设计一个函数 $\textit{dfs}(i, j)$，表示数组 $\textit{stoneValue}$ 中下标范围 $[i, j]$ 内的石子，Alice 能够获得的最大分数。那么答案就是 $\textit{dfs}(0, n - 1)$。

函数 $\textit{dfs}(i, j)$ 的计算过程如下：

-   如果 $i \geq j$，说明只剩下一块石子，Alice 无法进行分割，因此返回 $0$。
-   否则，我们枚举分割点 $k$，即 $i \leq k < j$，将数组 $\textit{stoneValue}$ 中下标范围 $[i, j]$ 内的石子分割为 $[i, k]$ 和 $[k + 1, j]$ 两部分，计算出 $a$ 和 $b$，分别表示两部分的石子总和。然后我们分别计算 $\textit{dfs}(i, k)$ 和 $\textit{dfs}(k + 1, j)$，并更新答案。

注意，如果满足 $a < b$ 并且 $\textit{ans} \geq a \times 2$，那么这一次枚举可以跳过；如果满足 $a > b$ 并且 $\textit{ans} \geq b \times 2$，那么后续的枚举都可以跳过，直接退出循环。

最后，我们返回答案即可。

为了避免重复计算，我们可以使用记忆化搜索，同时使用剪枝优化枚举的效率。

时间复杂度 $O(n^3)$，空间复杂度 $O(n^2)$。其中 $n$ 为数组 $\textit{stoneValue}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
def max(a: int, b: int) -> int:
    return a if a > b else b


class Solution:
    def stoneGameV(self, stoneValue: List[int]) -> int:
        @cache
        def dfs(i: int, j: int) -> int:
            if i >= j:
                return 0
            ans = l = 0
            r = s[j + 1] - s[i]
            for k in range(i, j):
                l += stoneValue[k]
                r -= stoneValue[k]
                if l < r:
                    if ans >= l * 2:
                        continue
                    ans = max(ans, l + dfs(i, k))
                elif l > r:
                    if ans >= r * 2:
                        break
                    ans = max(ans, r + dfs(k + 1, j))
                else:
                    ans = max(ans, max(l + dfs(i, k), r + dfs(k + 1, j)))
            return ans

        s = list(accumulate(stoneValue, initial=0))
        return dfs(0, len(stoneValue) - 1)
```

#### Java

```java
class Solution {
    private int n;
    private int[] s;
    private int[] nums;
    private Integer[][] f;

    public int stoneGameV(int[] stoneValue) {
        n = stoneValue.length;
        s = new int[n + 1];
        nums = stoneValue;
        f = new Integer[n][n];
        for (int i = 1; i <= n; ++i) {
            s[i] = s[i - 1] + nums[i - 1];
        }
        return dfs(0, n - 1);
    }

    private int dfs(int i, int j) {
        if (i >= j) {
            return 0;
        }
        if (f[i][j] != null) {
            return f[i][j];
        }
        int ans = 0, l = 0, r = s[j + 1] - s[i];
        for (int k = i; k < j; ++k) {
            l += nums[k];
            r -= nums[k];
            if (l < r) {
                if (ans > l * 2) {
                    continue;
                }
                ans = Math.max(ans, l + dfs(i, k));
            } else if (l > r) {
                if (ans > r * 2) {
                    break;
                }
                ans = Math.max(ans, r + dfs(k + 1, j));
            } else {
                ans = Math.max(ans, Math.max(l + dfs(i, k), r + dfs(k + 1, j)));
            }
        }
        return f[i][j] = ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        int s[n + 1];
        s[0] = 0;
        for (int i = 0; i < n; i++) {
            s[i + 1] = s[i] + stoneValue[i];
        }
        int f[n][n];
        memset(f, -1, sizeof(f));
        auto dfs = [&](this auto&& dfs, int i, int j) -> int {
            if (i >= j) {
                return 0;
            }
            if (f[i][j] != -1) {
                return f[i][j];
            }
            int ans = 0, l = 0, r = s[j + 1] - s[i];
            for (int k = i; k < j; ++k) {
                l += stoneValue[k];
                r -= stoneValue[k];
                if (l < r) {
                    if (ans > l * 2) {
                        continue;
                    }
                    ans = max(ans, l + dfs(i, k));
                } else if (l > r) {
                    if (ans > r * 2) {
                        break;
                    }
                    ans = max(ans, r + dfs(k + 1, j));
                } else {
                    ans = max({ans, l + dfs(i, k), r + dfs(k + 1, j)});
                }
            }
            return f[i][j] = ans;
        };
        return dfs(0, n - 1);
    }
};
```

#### Go

```go
func stoneGameV(stoneValue []int) int {
	n := len(stoneValue)
	s := make([]int, n+1)
	for i, x := range stoneValue {
		s[i+1] = s[i] + x
	}
	f := make([][]int, n)
	for i := range f {
		f[i] = make([]int, n)
		for j := range f[i] {
			f[i][j] = -1
		}
	}
	var dfs func(int, int) int
	dfs = func(i, j int) int {
		if i >= j {
			return 0
		}
		if f[i][j] != -1 {
			return f[i][j]
		}
		ans, l, r := 0, 0, s[j+1]-s[i]
		for k := i; k < j; k++ {
			l += stoneValue[k]
			r -= stoneValue[k]
			if l < r {
				if ans > l*2 {
					continue
				}
				ans = max(ans, dfs(i, k)+l)
			} else if l > r {
				if ans > r*2 {
					break
				}
				ans = max(ans, dfs(k+1, j)+r)
			} else {
				ans = max(ans, max(dfs(i, k), dfs(k+1, j))+l)
			}
		}
		f[i][j] = ans
		return ans
	}
	return dfs(0, n-1)
}
```

#### TypeScript

```ts
function stoneGameV(stoneValue: number[]): number {
    const n = stoneValue.length;
    const s: number[] = Array(n + 1).fill(0);
    for (let i = 0; i < n; i++) {
        s[i + 1] = s[i] + stoneValue[i];
    }
    const f: number[][] = Array.from({ length: n }, () => Array(n).fill(-1));

    const dfs = (i: number, j: number): number => {
        if (i >= j) {
            return 0;
        }
        if (f[i][j] !== -1) {
            return f[i][j];
        }
        let [ans, l, r] = [0, 0, s[j + 1] - s[i]];
        for (let k = i; k < j; ++k) {
            l += stoneValue[k];
            r -= stoneValue[k];
            if (l < r) {
                if (ans > l * 2) {
                    continue;
                }
                ans = Math.max(ans, l + dfs(i, k));
            } else if (l > r) {
                if (ans > r * 2) {
                    break;
                }
                ans = Math.max(ans, r + dfs(k + 1, j));
            } else {
                ans = Math.max(ans, l + dfs(i, k), r + dfs(k + 1, j));
            }
        }
        return (f[i][j] = ans);
    };

    return dfs(0, n - 1);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1564. 把箱子放进仓库里 I 🔒](https://leetcode.cn/problems/put-boxes-into-the-warehouse-i){#1564}

{{< tabs "1564" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxBoxesInWarehouse(self, boxes: List[int], warehouse: List[int]) -> int:
        n = len(warehouse)
        left = [warehouse[0]] * n
        for i in range(1, n):
            left[i] = min(left[i - 1], warehouse[i])
        boxes.sort()
        i, j = 0, n - 1
        while i < len(boxes):
            while j >= 0 and left[j] < boxes[i]:
                j -= 1
            if j < 0:
                break
            i, j = i + 1, j - 1
        return i
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxBoxesInWarehouse(int[] boxes, int[] warehouse) {
        int n = warehouse.length;
        int[] left = new int[n];
        left[0] = warehouse[0];
        for (int i = 1; i < n; ++i) {
            left[i] = Math.min(left[i - 1], warehouse[i]);
        }
        Arrays.sort(boxes);
        int i = 0, j = n - 1;
        while (i < boxes.length) {
            while (j >= 0 && left[j] < boxes[i]) {
                --j;
            }
            if (j < 0) {
                break;
            }
            ++i;
            --j;
        }
        return i;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        int n = warehouse.size();
        int left[n];
        left[0] = warehouse[0];
        for (int i = 1; i < n; ++i) {
            left[i] = min(left[i - 1], warehouse[i]);
        }
        sort(boxes.begin(), boxes.end());
        int i = 0, j = n - 1;
        while (i < boxes.size()) {
            while (j >= 0 && left[j] < boxes[i]) {
                --j;
            }
            if (j < 0) {
                break;
            }
            ++i;
            --j;
        }
        return i;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxBoxesInWarehouse(boxes []int, warehouse []int) int {
	n := len(warehouse)
	left := make([]int, n)
	left[0] = warehouse[0]
	for i := 1; i < n; i++ {
		left[i] = min(left[i-1], warehouse[i])
	}
	sort.Ints(boxes)
	i, j := 0, n-1
	for i < len(boxes) {
		for j >= 0 && left[j] < boxes[i] {
			j--
		}
		if j < 0 {
			break
		}
		i, j = i+1, j-1
	}
	return i
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxBoxesInWarehouse(boxes: number[], warehouse: number[]): number {
    const n = warehouse.length;
    const left: number[] = new Array(n);
    left[0] = warehouse[0];
    for (let i = 1; i < n; ++i) {
        left[i] = Math.min(left[i - 1], warehouse[i]);
    }
    boxes.sort((a, b) => a - b);
    let i = 0;
    let j = n - 1;
    while (i < boxes.length) {
        while (j >= 0 && left[j] < boxes[i]) {
            --j;
        }
        if (j < 0) {
            break;
        }
        ++i;
        --j;
    }
    return i;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定两个正整数数组&nbsp;<code>boxes</code>&nbsp;和&nbsp;<code>warehouse</code>&nbsp;，分别包含单位宽度的箱子的高度，以及仓库中 <code>n</code> 个房间各自的高度。仓库的房间分别从&nbsp;<code>0</code>&nbsp;到&nbsp;<code>n - 1</code>&nbsp;自左向右编号，&nbsp;<code>warehouse[i]</code>&nbsp;（索引从 0 开始）是第&nbsp;<code>i</code>&nbsp;个房间的高度。</p>

<p>箱子放进仓库时遵循下列规则：</p>

<ul>
	<li>箱子不可叠放。</li>
	<li>你可以重新调整箱子的顺序。</li>
	<li>箱子只能从左向右推进仓库中。</li>
	<li>如果仓库中某房间的高度小于某箱子的高度，则这个箱子和之后的箱子都会停在这个房间的前面。</li>
</ul>

<p>你最多可以在仓库中放进多少个箱子？</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1564.Put%20Boxes%20Into%20the%20Warehouse%20I/images/11.png" style="height: 242px; width: 400px;" /></strong></p>

<pre>
<strong>输入：</strong>boxes = [4,3,4,1], warehouse = [5,3,3,4,1]
<strong>输出：</strong>3
<strong>解释：
</strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1564.Put%20Boxes%20Into%20the%20Warehouse%20I/images/12.png" style="height: 242px; width: 280px;" />
我们可以先把高度为 1 的箱子放入 4 号房间，然后再把高度为 3 的箱子放入 1 号、 2 号或 3 号房间，最后再把高度为 4 的箱子放入 0 号房间。
我们不可能把所有 4 个箱子全部放进仓库里。</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1564.Put%20Boxes%20Into%20the%20Warehouse%20I/images/21.png" style="height: 202px; width: 400px;" /></strong></p>

<pre>
<strong>输入：</strong>boxes = [1,2,2,3,4], warehouse = [3,4,1,2]
<strong>输出：</strong>3
<strong>解释：
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1564.Put%20Boxes%20Into%20the%20Warehouse%20I/images/22.png" style="height: 202px; width: 280px;" />
</strong>我们注意到，不可能把高度为 4 的箱子放入仓库中，因为它不能通过高度为 3 的房间。
而且，对于最后两个房间 2 号和 3 号来说，只有高度为 1 的箱子可以放进去。
我们最多可以放进 3 个箱子，如上图所示。黄色的箱子也可以放入 2 号房间。
交换橙色和绿色箱子的位置，或是将这两个箱子与红色箱子交换位置，也是可以的。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>boxes = [1,2,3], warehouse = [1,2,3,4]
<strong>输出：</strong>1
<strong>解释：</strong>由于第一个房间的高度为 1，我们只能放进高度为 1 的箱子。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == warehouse.length</code></li>
	<li><code>1 &lt;= boxes.length, warehouse.length &lt;= 10^5</code></li>
	<li><code>1 &lt;= boxes[i], warehouse[i] &lt;= 10^9</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：预处理 + 排序 + 双指针

我们可以先对仓库的房间进行预处理，得到一个数组 $left$，其中 $left[i]$ 表示下标 $i$ 可以放入的最大箱子高度。

然后对箱子的高度进行排序，从小到大依次放入仓库中。我们使用两个指针 $i$ 和 $j$ 分别指向箱子的第一个位置以及仓库的最后一个位置，如果 $left[j] \lt boxes[i]$，说明当前仓库无法放入箱子 $i$，我们将指针 $j$ 循环向左移动，直到 $left[j] \ge boxes[i]$ 或者 $j \lt 0$。如果此时 $j \lt 0$，说明仓库已经没有空间可以放入箱子 $i$，我们可以直接退出循环。否则说明仓库可以放入箱子 $i$，我们将指针 $i$ 循环向右移动，指针 $j$ 循环向左移动。继续进行上述操作，直到指针 $i$ 超出箱子的范围。

最后我们返回指针 $i$ 的值即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为仓库的房间数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxBoxesInWarehouse(self, boxes: List[int], warehouse: List[int]) -> int:
        n = len(warehouse)
        left = [warehouse[0]] * n
        for i in range(1, n):
            left[i] = min(left[i - 1], warehouse[i])
        boxes.sort()
        i, j = 0, n - 1
        while i < len(boxes):
            while j >= 0 and left[j] < boxes[i]:
                j -= 1
            if j < 0:
                break
            i, j = i + 1, j - 1
        return i
```

#### Java

```java
class Solution {
    public int maxBoxesInWarehouse(int[] boxes, int[] warehouse) {
        int n = warehouse.length;
        int[] left = new int[n];
        left[0] = warehouse[0];
        for (int i = 1; i < n; ++i) {
            left[i] = Math.min(left[i - 1], warehouse[i]);
        }
        Arrays.sort(boxes);
        int i = 0, j = n - 1;
        while (i < boxes.length) {
            while (j >= 0 && left[j] < boxes[i]) {
                --j;
            }
            if (j < 0) {
                break;
            }
            ++i;
            --j;
        }
        return i;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        int n = warehouse.size();
        int left[n];
        left[0] = warehouse[0];
        for (int i = 1; i < n; ++i) {
            left[i] = min(left[i - 1], warehouse[i]);
        }
        sort(boxes.begin(), boxes.end());
        int i = 0, j = n - 1;
        while (i < boxes.size()) {
            while (j >= 0 && left[j] < boxes[i]) {
                --j;
            }
            if (j < 0) {
                break;
            }
            ++i;
            --j;
        }
        return i;
    }
};
```

#### Go

```go
func maxBoxesInWarehouse(boxes []int, warehouse []int) int {
	n := len(warehouse)
	left := make([]int, n)
	left[0] = warehouse[0]
	for i := 1; i < n; i++ {
		left[i] = min(left[i-1], warehouse[i])
	}
	sort.Ints(boxes)
	i, j := 0, n-1
	for i < len(boxes) {
		for j >= 0 && left[j] < boxes[i] {
			j--
		}
		if j < 0 {
			break
		}
		i, j = i+1, j-1
	}
	return i
}
```

#### TypeScript

```ts
function maxBoxesInWarehouse(boxes: number[], warehouse: number[]): number {
    const n = warehouse.length;
    const left: number[] = new Array(n);
    left[0] = warehouse[0];
    for (let i = 1; i < n; ++i) {
        left[i] = Math.min(left[i - 1], warehouse[i]);
    }
    boxes.sort((a, b) => a - b);
    let i = 0;
    let j = n - 1;
    while (i < boxes.length) {
        while (j >= 0 && left[j] < boxes[i]) {
            --j;
        }
        if (j < 0) {
            break;
        }
        ++i;
        --j;
    }
    return i;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1565. 按月统计订单数与顾客数 🔒](https://leetcode.cn/problems/unique-orders-and-customers-per-month){#1565}

{{< tabs "1565" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT
    DATE_FORMAT(order_date, '%Y-%m') AS month,
    COUNT(order_id) AS order_count,
    COUNT(DISTINCT customer_id) AS customer_count
FROM Orders
WHERE invoice > 20
GROUP BY 1;
```
{{% /tab %}}
{{% tab "python" %}}
```python
import pandas as pd


def unique_orders_and_customers(orders: pd.DataFrame) -> pd.DataFrame:
    filtered_orders = orders[orders["invoice"] > 20]
    filtered_orders["month"] = (
        filtered_orders["order_date"].dt.to_period("M").astype(str)
    )
    result = (
        filtered_orders.groupby("month")
        .agg(
            order_count=("order_id", "count"), customer_count=("customer_id", "nunique")
        )
        .reset_index()
    )
    return result
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code>Orders</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| order_id      | int     |
| order_date    | date    |
| customer_id   | int     |
| invoice       | int     |
+---------------+---------+
order_id 是该表具有唯一值的列<sub>。</sub>
这张表包含顾客(customer_id)所下订单的信息<sub>。</sub>
</pre>

<p>&nbsp;</p>

<p>写一个查询语句来 <strong>按月 </strong>统计金额（invoice）<strong>大于 $20 </strong>的唯一 <strong>订单数</strong> 和唯一 <strong>顾客数 。</strong></p>

<p>查询结果无排序要求。</p>

<p>查询结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<code><strong>输入：</strong>
Orders</code>
+----------+------------+-------------+------------+
| order_id | order_date | customer_id | invoice    |
+----------+------------+-------------+------------+
| 1        | 2020-09-15 | 1           | 30         |
| 2        | 2020-09-17 | 2           | 90         |
| 3        | 2020-10-06 | 3           | 20         |
| 4        | 2020-10-20 | 3           | 21         |
| 5        | 2020-11-10 | 1           | 10         |
| 6        | 2020-11-21 | 2           | 15         |
| 7        | 2020-12-01 | 4           | 55         |
| 8        | 2020-12-03 | 4           | 77         |
| 9        | 2021-01-07 | 3           | 31         |
| 10       | 2021-01-15 | 2           | 20         |
+----------+------------+-------------+------------+
<strong>输出：</strong>
+---------+-------------+----------------+
| month   | order_count | customer_count |
+---------+-------------+----------------+
| 2020-09 | 2           | 2              |
| 2020-10 | 1           | 1              |
| 2020-12 | 2           | 1              |
| 2021-01 | 1           | 1              |
+---------+-------------+----------------+
<strong>解释：</strong>
在 2020 年 09 月<sub>，</sub>有 2 份来自 2 位不同顾客的金额大于 $20 的订单<sub>。</sub>
在 2020 年 10 月<sub>，</sub>有 2 份来自 1 位顾客的订单<sub>，</sub>并且只有其中的 1 份订单金额大于 $20 <sub>。</sub>
在 2020 年 11 月<sub>，</sub>有 2 份来自 2 位不同顾客的订单<sub>，</sub>但由于金额都小于 $20 <sub>，</sub>所以我们的查询结果中不包含这个月的数据<sub>。</sub>
在 2020 年 12 月<sub>，</sub>有 2 份来自 1 位顾客的订单<sub>，</sub>且 2 份订单金额都大于 $20<sub> 。</sub>
在 2021 年 01 月<sub>，</sub>有 2 份来自 2 位不同顾客的订单<sub>，</sub>但只有其中一份订单金额大于 $20 <sub>。</sub></pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：条件筛选 + 分组统计

我们可以先筛选出金额大于 $20$ 的订单，然后按月份进行分组统计订单数和顾客数。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT
    DATE_FORMAT(order_date, '%Y-%m') AS month,
    COUNT(order_id) AS order_count,
    COUNT(DISTINCT customer_id) AS customer_count
FROM Orders
WHERE invoice > 20
GROUP BY 1;
```

#### Pandas

```python
import pandas as pd


def unique_orders_and_customers(orders: pd.DataFrame) -> pd.DataFrame:
    filtered_orders = orders[orders["invoice"] > 20]
    filtered_orders["month"] = (
        filtered_orders["order_date"].dt.to_period("M").astype(str)
    )
    result = (
        filtered_orders.groupby("month")
        .agg(
            order_count=("order_id", "count"), customer_count=("customer_id", "nunique")
        )
        .reset_index()
    )
    return result
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1566. 重复至少 K 次且长度为 M 的模式](https://leetcode.cn/problems/detect-pattern-of-length-m-repeated-k-or-more-times){#1566}

{{< tabs "1566" >}}

{{% tab "python" %}}
```python
class Solution:
    def containsPattern(self, arr: List[int], m: int, k: int) -> bool:
        if len(arr) < m * k:
            return False
        cnt, target = 0, (k - 1) * m
        for i in range(m, len(arr)):
            if arr[i] == arr[i - m]:
                cnt += 1
                if cnt == target:
                    return True
            else:
                cnt = 0
        return False
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean containsPattern(int[] arr, int m, int k) {
        if (arr.length < m * k) {
            return false;
        }
        int cnt = 0, target = (k - 1) * m;
        for (int i = m; i < arr.length; ++i) {
            if (arr[i] == arr[i - m]) {
                if (++cnt == target) {
                    return true;
                }
            } else {
                cnt = 0;
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
    bool containsPattern(vector<int>& arr, int m, int k) {
        if (arr.size() < m * k) {
            return false;
        }
        int cnt = 0, target = (k - 1) * m;
        for (int i = m; i < arr.size(); ++i) {
            if (arr[i] == arr[i - m]) {
                if (++cnt == target) {
                    return true;
                }
            } else {
                cnt = 0;
            }
        }
        return false;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func containsPattern(arr []int, m int, k int) bool {
	cnt, target := 0, (k-1)*m
	for i := m; i < len(arr); i++ {
		if arr[i] == arr[i-m] {
			cnt++
			if cnt == target {
				return true
			}
		} else {
			cnt = 0
		}
	}
	return false
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function containsPattern(arr: number[], m: number, k: number): boolean {
    if (arr.length < m * k) {
        return false;
    }
    const target = (k - 1) * m;
    let cnt = 0;
    for (let i = m; i < arr.length; ++i) {
        if (arr[i] === arr[i - m]) {
            if (++cnt === target) {
                return true;
            }
        } else {
            cnt = 0;
        }
    }
    return false;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个正整数数组 <code>arr</code>，请你找出一个长度为 <code>m</code> 且在数组中至少重复 <code>k</code> 次的模式。</p>

<p><strong>模式</strong> 是由一个或多个值组成的子数组（连续的子序列），<strong>连续</strong> 重复多次但 <strong>不重叠</strong> 。 模式由其长度和重复次数定义。</p>

<p>如果数组中存在至少重复 <code>k</code> 次且长度为 <code>m</code> 的模式，则返回 <code>true</code> ，否则返回&nbsp; <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>arr = [1,2,4,4,4,4], m = 1, k = 3
<strong>输出：</strong>true
<strong>解释：</strong>模式 <strong>(4)</strong> 的长度为 1 ，且连续重复 4 次。注意，模式可以重复 k 次或更多次，但不能少于 k 次。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>arr = [1,2,1,2,1,1,1,3], m = 2, k = 2
<strong>输出：</strong>true
<strong>解释：</strong>模式 <strong>(1,2)</strong> 长度为 2 ，且连续重复 2 次。另一个符合题意的模式是 <strong>(2,1) </strong>，同样重复 2 次。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>arr = [1,2,1,2,1,3], m = 2, k = 3
<strong>输出：</strong>false
<strong>解释：</strong>模式 <strong>(1,2)</strong> 长度为 2 ，但是只连续重复 2 次。不存在长度为 2 且至少重复 3 次的模式。
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>arr = [1,2,3,1,2], m = 2, k = 2
<strong>输出：</strong>false
<strong>解释：</strong>模式 <strong>(1,2)</strong> 出现 2 次但并不连续，所以不能算作连续重复 2 次。
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>arr = [2,2,2,2], m = 2, k = 3
<strong>输出：</strong>false
<strong>解释：</strong>长度为 2 的模式只有 <strong>(2,2)</strong> ，但是只连续重复 2 次。注意，不能计算重叠的重复次数。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= arr.length &lt;= 100</code></li>
	<li><code>1 &lt;= arr[i] &lt;= 100</code></li>
	<li><code>1 &lt;= m&nbsp;&lt;= 100</code></li>
	<li><code>2 &lt;= k&nbsp;&lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：一次遍历

首先，如果数组的长度小于 $m \times k$，那么肯定不存在长度为 $m$ 且至少重复 $k$ 次的模式，直接返回 $\textit{false}$。

接下来，我们定义一个变量 $\textit{cnt}$ 来记录当前连续重复的次数，如果数组存在连续的 $(k - 1) \times m$ 个元素 $a_i$，使得 $a_i = a_{i - m}$，那么我们就找到了一个长度为 $m$ 且至少重复 $k$ 次的模式，返回 $\textit{true}$。否则，我们将 $\textit{cnt}$ 置为 $0$，继续遍历数组。

最后，如果遍历完数组都没有找到符合条件的模式，返回 $\textit{false}$。

时间复杂度 $O(n)$，其中 $n$ 是数组的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def containsPattern(self, arr: List[int], m: int, k: int) -> bool:
        if len(arr) < m * k:
            return False
        cnt, target = 0, (k - 1) * m
        for i in range(m, len(arr)):
            if arr[i] == arr[i - m]:
                cnt += 1
                if cnt == target:
                    return True
            else:
                cnt = 0
        return False
```

#### Java

```java
class Solution {
    public boolean containsPattern(int[] arr, int m, int k) {
        if (arr.length < m * k) {
            return false;
        }
        int cnt = 0, target = (k - 1) * m;
        for (int i = m; i < arr.length; ++i) {
            if (arr[i] == arr[i - m]) {
                if (++cnt == target) {
                    return true;
                }
            } else {
                cnt = 0;
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
    bool containsPattern(vector<int>& arr, int m, int k) {
        if (arr.size() < m * k) {
            return false;
        }
        int cnt = 0, target = (k - 1) * m;
        for (int i = m; i < arr.size(); ++i) {
            if (arr[i] == arr[i - m]) {
                if (++cnt == target) {
                    return true;
                }
            } else {
                cnt = 0;
            }
        }
        return false;
    }
};
```

#### Go

```go
func containsPattern(arr []int, m int, k int) bool {
	cnt, target := 0, (k-1)*m
	for i := m; i < len(arr); i++ {
		if arr[i] == arr[i-m] {
			cnt++
			if cnt == target {
				return true
			}
		} else {
			cnt = 0
		}
	}
	return false
}
```

#### TypeScript

```ts
function containsPattern(arr: number[], m: number, k: number): boolean {
    if (arr.length < m * k) {
        return false;
    }
    const target = (k - 1) * m;
    let cnt = 0;
    for (let i = m; i < arr.length; ++i) {
        if (arr[i] === arr[i - m]) {
            if (++cnt === target) {
                return true;
            }
        } else {
            cnt = 0;
        }
    }
    return false;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1567. 乘积为正数的最长子数组长度](https://leetcode.cn/problems/maximum-length-of-subarray-with-positive-product){#1567}

{{< tabs "1567" >}}

{{% tab "python" %}}
```python
class Solution:
    def getMaxLen(self, nums: List[int]) -> int:
        n = len(nums)
        f = int(nums[0] > 0)
        g = int(nums[0] < 0)
        ans = f
        for i in range(1, n):
            ff = gg = 0
            if nums[i] > 0:
                ff = f + 1
                gg = 0 if g == 0 else g + 1
            elif nums[i] < 0:
                ff = 0 if g == 0 else g + 1
                gg = f + 1
            f, g = ff, gg
            ans = max(ans, f)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int getMaxLen(int[] nums) {
        int n = nums.length;
        int f = nums[0] > 0 ? 1 : 0;
        int g = nums[0] < 0 ? 1 : 0;
        int ans = f;

        for (int i = 1; i < n; i++) {
            int ff = 0, gg = 0;
            if (nums[i] > 0) {
                ff = f + 1;
                gg = g == 0 ? 0 : g + 1;
            } else if (nums[i] < 0) {
                ff = g == 0 ? 0 : g + 1;
                gg = f + 1;
            }
            f = ff;
            g = gg;
            ans = Math.max(ans, f);
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
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        int f = nums[0] > 0 ? 1 : 0;
        int g = nums[0] < 0 ? 1 : 0;
        int ans = f;

        for (int i = 1; i < n; i++) {
            int ff = 0, gg = 0;
            if (nums[i] > 0) {
                ff = f + 1;
                gg = g == 0 ? 0 : g + 1;
            } else if (nums[i] < 0) {
                ff = g == 0 ? 0 : g + 1;
                gg = f + 1;
            }
            f = ff;
            g = gg;
            ans = max(ans, f);
        }

        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func getMaxLen(nums []int) int {
	n := len(nums)
	var f, g int
	if nums[0] > 0 {
		f = 1
	} else if nums[0] < 0 {
		g = 1
	}
	ans := f
	for i := 1; i < n; i++ {
		ff, gg := 0, 0
		if nums[i] > 0 {
			ff = f + 1
			gg = 0
			if g > 0 {
				gg = g + 1
			}
		} else if nums[i] < 0 {
			ff = 0
			if g > 0 {
				ff = g + 1
			}
			gg = f + 1
		}
		f, g = ff, gg
		ans = max(ans, f)
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function getMaxLen(nums: number[]): number {
    const n = nums.length;
    let [f, g] = [0, 0];
    if (nums[0] > 0) {
        f = 1;
    } else if (nums[0] < 0) {
        g = 1;
    }
    let ans = f;
    for (let i = 1; i < n; i++) {
        let [ff, gg] = [0, 0];
        if (nums[i] > 0) {
            ff = f + 1;
            gg = g > 0 ? g + 1 : 0;
        } else if (nums[i] < 0) {
            ff = g > 0 ? g + 1 : 0;
            gg = f + 1;
        }
        [f, g] = [ff, gg];
        ans = Math.max(ans, f);
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

<p>给你一个整数数组 <code>nums</code>&nbsp;，请你求出乘积为正数的最长子数组的长度。</p>

<p>一个数组的子数组是由原数组中零个或者更多个连续数字组成的数组。</p>

<p>请你返回乘积为正数的最长子数组长度。</p>

<p>&nbsp;</p>

<p><strong>示例&nbsp; 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,-2,-3,4]
<strong>输出：</strong>4
<strong>解释：</strong>数组本身乘积就是正数，值为 24 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [0,1,-2,-3,-4]
<strong>输出：</strong>3
<strong>解释：</strong>最长乘积为正数的子数组为 [1,-2,-3] ，乘积为 6 。
注意，我们不能把 0 也包括到子数组中，因为这样乘积为 0 ，不是正数。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [-1,-2,-3,0,1]
<strong>输出：</strong>2
<strong>解释：</strong>乘积为正数的最长子数组是 [-1,-2] 或者 [-2,-3] 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10^5</code></li>
	<li><code>-10^9 &lt;= nums[i]&nbsp;&lt;= 10^9</code></li>
</ul>

<p>&nbsp;</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义两个长度为 $n$ 的数组 $f$ 和 $g$，其中 $f[i]$ 表示以 $\textit{nums}[i]$ 结尾的乘积为正数的最长子数组的长度，而 $g[i]$ 表示以 $\textit{nums}[i]$ 结尾的乘积为负数的最长子数组的长度。

初始时，如果 $\textit{nums}[0] > 0$，则 $f[0] = 1$，否则 $f[0] = 0$；如果 $\textit{nums}[0] < 0$，则 $g[0] = 1$，否则 $g[0] = 0$。我们初始化答案 $ans = f[0]$。

接下来，我们从 $i = 1$ 开始遍历数组 $\textit{nums}$，对于每个 $i$，我们有以下几种情况：

-   如果 $\textit{nums}[i] > 0$，那么 $f[i]$ 可以由 $f[i - 1]$ 转移而来，即 $f[i] = f[i - 1] + 1$，而 $g[i]$ 的值取决于 $g[i - 1]$ 是否为 $0$，如果 $g[i - 1] = 0$，则 $g[i] = 0$，否则 $g[i] = g[i - 1] + 1$；
-   如果 $\textit{nums}[i] < 0$，那么 $f[i]$ 的值取决于 $g[i - 1]$ 是否为 $0$，如果 $g[i - 1] = 0$，则 $f[i] = 0$，否则 $f[i] = g[i - 1] + 1$，而 $g[i]$ 可以由 $f[i - 1]$ 转移而来，即 $g[i] = f[i - 1] + 1$。
-   然后，我们更新答案 $ans = \max(ans, f[i])$。

遍历结束后，返回答案 $ans$ 即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $\textit{nums}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def getMaxLen(self, nums: List[int]) -> int:
        n = len(nums)
        f = [0] * n
        g = [0] * n
        f[0] = int(nums[0] > 0)
        g[0] = int(nums[0] < 0)
        ans = f[0]
        for i in range(1, n):
            if nums[i] > 0:
                f[i] = f[i - 1] + 1
                g[i] = 0 if g[i - 1] == 0 else g[i - 1] + 1
            elif nums[i] < 0:
                f[i] = 0 if g[i - 1] == 0 else g[i - 1] + 1
                g[i] = f[i - 1] + 1
            ans = max(ans, f[i])
        return ans
```

#### Java

```java
class Solution {
    public int getMaxLen(int[] nums) {
        int n = nums.length;
        int[] f = new int[n];
        int[] g = new int[n];
        f[0] = nums[0] > 0 ? 1 : 0;
        g[0] = nums[0] < 0 ? 1 : 0;
        int ans = f[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] > 0) {
                f[i] = f[i - 1] + 1;
                g[i] = g[i - 1] > 0 ? g[i - 1] + 1 : 0;
            } else if (nums[i] < 0) {
                f[i] = g[i - 1] > 0 ? g[i - 1] + 1 : 0;
                g[i] = f[i - 1] + 1;
            }
            ans = Math.max(ans, f[i]);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n, 0), g(n, 0);
        f[0] = nums[0] > 0 ? 1 : 0;
        g[0] = nums[0] < 0 ? 1 : 0;
        int ans = f[0];

        for (int i = 1; i < n; ++i) {
            if (nums[i] > 0) {
                f[i] = f[i - 1] + 1;
                g[i] = g[i - 1] > 0 ? g[i - 1] + 1 : 0;
            } else if (nums[i] < 0) {
                f[i] = g[i - 1] > 0 ? g[i - 1] + 1 : 0;
                g[i] = f[i - 1] + 1;
            }
            ans = max(ans, f[i]);
        }
        return ans;
    }
};
```

#### Go

```go
func getMaxLen(nums []int) int {
	n := len(nums)
	f := make([]int, n)
	g := make([]int, n)
	if nums[0] > 0 {
		f[0] = 1
	}
	if nums[0] < 0 {
		g[0] = 1
	}
	ans := f[0]

	for i := 1; i < n; i++ {
		if nums[i] > 0 {
			f[i] = f[i-1] + 1
			if g[i-1] > 0 {
				g[i] = g[i-1] + 1
			} else {
				g[i] = 0
			}
		} else if nums[i] < 0 {
			if g[i-1] > 0 {
				f[i] = g[i-1] + 1
			} else {
				f[i] = 0
			}
			g[i] = f[i-1] + 1
		}
		ans = max(ans, f[i])
	}
	return ans
}
```

#### TypeScript

```ts
function getMaxLen(nums: number[]): number {
    const n = nums.length;
    const f: number[] = Array(n).fill(0);
    const g: number[] = Array(n).fill(0);

    if (nums[0] > 0) {
        f[0] = 1;
    }
    if (nums[0] < 0) {
        g[0] = 1;
    }

    let ans = f[0];
    for (let i = 1; i < n; i++) {
        if (nums[i] > 0) {
            f[i] = f[i - 1] + 1;
            g[i] = g[i - 1] > 0 ? g[i - 1] + 1 : 0;
        } else if (nums[i] < 0) {
            f[i] = g[i - 1] > 0 ? g[i - 1] + 1 : 0;
            g[i] = f[i - 1] + 1;
        }

        ans = Math.max(ans, f[i]);
    }

    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：动态规划（空间优化）

我们发现，对于每个 $i$，$f[i]$ 和 $g[i]$ 的值只与 $f[i - 1]$ 和 $g[i - 1]$ 有关，因此我们可以使用两个变量 $f$ 和 $g$ 分别记录 $f[i - 1]$ 和 $g[i - 1]$ 的值，从而将空间复杂度优化至 $O(1)$。

时间复杂度 $O(n)$，其中 $n$ 为数组 $\textit{nums}$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def getMaxLen(self, nums: List[int]) -> int:
        n = len(nums)
        f = int(nums[0] > 0)
        g = int(nums[0] < 0)
        ans = f
        for i in range(1, n):
            ff = gg = 0
            if nums[i] > 0:
                ff = f + 1
                gg = 0 if g == 0 else g + 1
            elif nums[i] < 0:
                ff = 0 if g == 0 else g + 1
                gg = f + 1
            f, g = ff, gg
            ans = max(ans, f)
        return ans
```

#### Java

```java
class Solution {
    public int getMaxLen(int[] nums) {
        int n = nums.length;
        int f = nums[0] > 0 ? 1 : 0;
        int g = nums[0] < 0 ? 1 : 0;
        int ans = f;

        for (int i = 1; i < n; i++) {
            int ff = 0, gg = 0;
            if (nums[i] > 0) {
                ff = f + 1;
                gg = g == 0 ? 0 : g + 1;
            } else if (nums[i] < 0) {
                ff = g == 0 ? 0 : g + 1;
                gg = f + 1;
            }
            f = ff;
            g = gg;
            ans = Math.max(ans, f);
        }

        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        int f = nums[0] > 0 ? 1 : 0;
        int g = nums[0] < 0 ? 1 : 0;
        int ans = f;

        for (int i = 1; i < n; i++) {
            int ff = 0, gg = 0;
            if (nums[i] > 0) {
                ff = f + 1;
                gg = g == 0 ? 0 : g + 1;
            } else if (nums[i] < 0) {
                ff = g == 0 ? 0 : g + 1;
                gg = f + 1;
            }
            f = ff;
            g = gg;
            ans = max(ans, f);
        }

        return ans;
    }
};
```

#### Go

```go
func getMaxLen(nums []int) int {
	n := len(nums)
	var f, g int
	if nums[0] > 0 {
		f = 1
	} else if nums[0] < 0 {
		g = 1
	}
	ans := f
	for i := 1; i < n; i++ {
		ff, gg := 0, 0
		if nums[i] > 0 {
			ff = f + 1
			gg = 0
			if g > 0 {
				gg = g + 1
			}
		} else if nums[i] < 0 {
			ff = 0
			if g > 0 {
				ff = g + 1
			}
			gg = f + 1
		}
		f, g = ff, gg
		ans = max(ans, f)
	}
	return ans
}
```

#### TypeScript

```ts
function getMaxLen(nums: number[]): number {
    const n = nums.length;
    let [f, g] = [0, 0];
    if (nums[0] > 0) {
        f = 1;
    } else if (nums[0] < 0) {
        g = 1;
    }
    let ans = f;
    for (let i = 1; i < n; i++) {
        let [ff, gg] = [0, 0];
        if (nums[i] > 0) {
            ff = f + 1;
            gg = g > 0 ? g + 1 : 0;
        } else if (nums[i] < 0) {
            ff = g > 0 ? g + 1 : 0;
            gg = f + 1;
        }
        [f, g] = [ff, gg];
        ans = Math.max(ans, f);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1568. 使陆地分离的最少天数](https://leetcode.cn/problems/minimum-number-of-days-to-disconnect-island){#1568}

{{< tabs "1568" >}}

{{% tab "python" %}}
```python
class Solution:
    def minDays(self, grid: List[List[int]]) -> int:
        if self.count(grid) != 1:
            return 0
        m, n = len(grid), len(grid[0])
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    grid[i][j] = 0
                    if self.count(grid) != 1:
                        return 1
                    grid[i][j] = 1
        return 2

    def count(self, grid):
        def dfs(i, j):
            grid[i][j] = 2
            for a, b in [[0, -1], [0, 1], [1, 0], [-1, 0]]:
                x, y = i + a, j + b
                if 0 <= x < m and 0 <= y < n and grid[x][y] == 1:
                    dfs(x, y)

        m, n = len(grid), len(grid[0])
        cnt = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    dfs(i, j)
                    cnt += 1
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 2:
                    grid[i][j] = 1
        return cnt
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private static final int[] DIRS = new int[] {-1, 0, 1, 0, -1};
    private int[][] grid;
    private int m;
    private int n;

    public int minDays(int[][] grid) {
        this.grid = grid;
        m = grid.length;
        n = grid[0].length;
        if (count() != 1) {
            return 0;
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    if (count() != 1) {
                        return 1;
                    }
                    grid[i][j] = 1;
                }
            }
        }
        return 2;
    }

    private int count() {
        int cnt = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    dfs(i, j);
                    ++cnt;
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) {
                    grid[i][j] = 1;
                }
            }
        }
        return cnt;
    }

    private void dfs(int i, int j) {
        grid[i][j] = 2;
        for (int k = 0; k < 4; ++k) {
            int x = i + DIRS[k], y = j + DIRS[k + 1];
            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) {
                dfs(x, y);
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
    const vector<int> dirs = {-1, 0, 1, 0, -1};
    int m, n;

    int minDays(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        if (count(grid) != 1) {
            return 0;
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    if (count(grid) != 1) {
                        return 1;
                    }
                    grid[i][j] = 1;
                }
            }
        }
        return 2;
    }

    int count(vector<vector<int>>& grid) {
        int cnt = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    dfs(i, j, grid);
                    ++cnt;
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) {
                    grid[i][j] = 1;
                }
            }
        }
        return cnt;
    }

    void dfs(int i, int j, vector<vector<int>>& grid) {
        grid[i][j] = 2;
        for (int k = 0; k < 4; ++k) {
            int x = i + dirs[k], y = j + dirs[k + 1];
            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) {
                dfs(x, y, grid);
            }
        }
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minDays(grid [][]int) int {
	m, n := len(grid), len(grid[0])
	dirs := []int{-1, 0, 1, 0, -1}

	var dfs func(i, j int)
	dfs = func(i, j int) {
		grid[i][j] = 2
		for k := 0; k < 4; k++ {
			x, y := i+dirs[k], j+dirs[k+1]
			if x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1 {
				dfs(x, y)
			}
		}
	}

	count := func() int {
		cnt := 0
		for i := 0; i < m; i++ {
			for j := 0; j < n; j++ {
				if grid[i][j] == 1 {
					dfs(i, j)
					cnt++
				}
			}
		}
		for i := 0; i < m; i++ {
			for j := 0; j < n; j++ {
				if grid[i][j] == 2 {
					grid[i][j] = 1
				}
			}
		}
		return cnt
	}

	if count() != 1 {
		return 0
	}
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if grid[i][j] == 1 {
				grid[i][j] = 0
				if count() != 1 {
					return 1
				}
				grid[i][j] = 1
			}
		}
	}
	return 2
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minDays(grid: number[][]): number {
    const [m, n] = [grid.length, grid[0].length];

    const dfs = (i: number, j: number) => {
        if (i < 0 || m <= i || j < 0 || n <= j || [0, 2].includes(grid[i][j])) return;

        grid[i][j] = 2;
        const dir = [-1, 0, 1, 0, -1];
        for (let k = 0; k < 4; k++) {
            const [y, x] = [i + dir[k], j + dir[k + 1]];
            dfs(y, x);
        }
    };

    const count = () => {
        let c = 0;

        for (let i = 0; i < m; i++) {
            for (let j = 0; j < n; j++) {
                if (grid[i][j] === 1) {
                    dfs(i, j);
                    c++;
                }
            }
        }

        for (let i = 0; i < m; i++) {
            for (let j = 0; j < n; j++) {
                if (grid[i][j] === 2) {
                    grid[i][j] = 1;
                }
            }
        }

        return c;
    };

    if (count() !== 1) return 0;

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j] === 1) {
                grid[i][j] = 0;

                if (count() !== 1) return 1;

                grid[i][j] = 1;
            }
        }
    }

    return 2;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[][]} grid
 * @return {number}
 */
var minDays = function (grid) {
    const dirs = [-1, 0, 1, 0, -1];
    const [m, n] = [grid.length, grid[0].length];

    const dfs = (i, j, visited) => {
        if (i < 0 || m <= i || j < 0 || n <= j || grid[i][j] === 0 || visited[i][j]) {
            return;
        }

        visited[i][j] = true;
        for (let d = 0; d < 4; d++) {
            const [y, x] = [i + dirs[d], j + dirs[d + 1]];
            dfs(y, x, visited);
        }
    };

    const count = () => {
        const vis = Array.from({ length: m }, () => Array(n).fill(false));
        let c = 0;
        for (let i = 0; i < m; i++) {
            for (let j = 0; j < n; j++) {
                if (grid[i][j] === 1 && !vis[i][j]) {
                    c++;
                    dfs(i, j, vis);
                }
            }
        }
        return c;
    };

    if (count() !== 1) return 0;

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j] === 1) {
                grid[i][j] = 0;
                if (count() !== 1) return 1;
                grid[i][j] = 1;
            }
        }
    }

    return 2;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个大小为 <code>m x n</code> ，由若干 <code>0</code> 和 <code>1</code> 组成的二维网格 <code>grid</code> ，其中 <code>1</code> 表示陆地， <code>0</code> 表示水。<strong>岛屿</strong> 由水平方向或竖直方向上相邻的 <code>1</code> （陆地）连接形成。</p>

<p>如果 <strong>恰好只有一座岛屿 </strong>，则认为陆地是 <strong>连通的</strong> ；否则，陆地就是 <strong>分离的</strong> 。</p>

<p>一天内，可以将 <strong>任何单个</strong> 陆地单元（<code>1</code>）更改为水单元（<code>0</code>）。</p>

<p>返回使陆地分离的最少天数。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1568.Minimum%20Number%20of%20Days%20to%20Disconnect%20Island/images/land1.jpg" style="width: 500px; height: 169px;" />
<pre>
<strong>输入：</strong>grid = [[0,1,1,0],[0,1,1,0],[0,0,0,0]]
<strong>输出：</strong>2
<strong>解释：</strong>至少需要 2 天才能得到分离的陆地。
将陆地 grid[1][1] 和 grid[0][2] 更改为水，得到两个分离的岛屿。</pre>

<p><strong class="example">示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1568.Minimum%20Number%20of%20Days%20to%20Disconnect%20Island/images/land2.jpg" style="width: 404px; height: 85px;" />
<pre>
<strong>输入：</strong>grid = [[1,1]]
<strong>输出：</strong>2
<strong>解释：</strong>如果网格中都是水，也认为是分离的 ([[1,1]] -&gt; [[0,0]])，0 岛屿。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 30</code></li>
	<li><code>grid[i][j]</code> 为 <code>0</code> 或 <code>1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：脑筋急转弯

观察发现，我们总是可以通过把角落相邻的两个陆地变成水，使得岛屿分离。因此，答案只可能是 0，1 或 2。

我们跑一遍 DFS，统计当前岛屿的数量，如果数量不等于 $1$，也就是说不满足恰好只有一座岛屿，那么答案就是 0。

否则，我们遍历每一块陆地，把它变成水，然后再跑一遍 DFS，看看岛屿的数量是否不等于 1，如果不等于 1，说明这块陆地变成水后，岛屿分离了，答案就是 1。

遍历结束，说明必须要把两块陆地变成水，才能使得岛屿分离，因此答案就是 2。

时间复杂度 $O(m^2\times n^2)$，其中 $m$ 和 $n$ 分别是 `grid` 的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minDays(self, grid: List[List[int]]) -> int:
        if self.count(grid) != 1:
            return 0
        m, n = len(grid), len(grid[0])
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    grid[i][j] = 0
                    if self.count(grid) != 1:
                        return 1
                    grid[i][j] = 1
        return 2

    def count(self, grid):
        def dfs(i, j):
            grid[i][j] = 2
            for a, b in [[0, -1], [0, 1], [1, 0], [-1, 0]]:
                x, y = i + a, j + b
                if 0 <= x < m and 0 <= y < n and grid[x][y] == 1:
                    dfs(x, y)

        m, n = len(grid), len(grid[0])
        cnt = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    dfs(i, j)
                    cnt += 1
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 2:
                    grid[i][j] = 1
        return cnt
```

#### Java

```java
class Solution {
    private static final int[] DIRS = new int[] {-1, 0, 1, 0, -1};
    private int[][] grid;
    private int m;
    private int n;

    public int minDays(int[][] grid) {
        this.grid = grid;
        m = grid.length;
        n = grid[0].length;
        if (count() != 1) {
            return 0;
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    if (count() != 1) {
                        return 1;
                    }
                    grid[i][j] = 1;
                }
            }
        }
        return 2;
    }

    private int count() {
        int cnt = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    dfs(i, j);
                    ++cnt;
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) {
                    grid[i][j] = 1;
                }
            }
        }
        return cnt;
    }

    private void dfs(int i, int j) {
        grid[i][j] = 2;
        for (int k = 0; k < 4; ++k) {
            int x = i + DIRS[k], y = j + DIRS[k + 1];
            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) {
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
    const vector<int> dirs = {-1, 0, 1, 0, -1};
    int m, n;

    int minDays(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        if (count(grid) != 1) {
            return 0;
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    if (count(grid) != 1) {
                        return 1;
                    }
                    grid[i][j] = 1;
                }
            }
        }
        return 2;
    }

    int count(vector<vector<int>>& grid) {
        int cnt = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    dfs(i, j, grid);
                    ++cnt;
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) {
                    grid[i][j] = 1;
                }
            }
        }
        return cnt;
    }

    void dfs(int i, int j, vector<vector<int>>& grid) {
        grid[i][j] = 2;
        for (int k = 0; k < 4; ++k) {
            int x = i + dirs[k], y = j + dirs[k + 1];
            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) {
                dfs(x, y, grid);
            }
        }
    }
};
```

#### Go

```go
func minDays(grid [][]int) int {
	m, n := len(grid), len(grid[0])
	dirs := []int{-1, 0, 1, 0, -1}

	var dfs func(i, j int)
	dfs = func(i, j int) {
		grid[i][j] = 2
		for k := 0; k < 4; k++ {
			x, y := i+dirs[k], j+dirs[k+1]
			if x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1 {
				dfs(x, y)
			}
		}
	}

	count := func() int {
		cnt := 0
		for i := 0; i < m; i++ {
			for j := 0; j < n; j++ {
				if grid[i][j] == 1 {
					dfs(i, j)
					cnt++
				}
			}
		}
		for i := 0; i < m; i++ {
			for j := 0; j < n; j++ {
				if grid[i][j] == 2 {
					grid[i][j] = 1
				}
			}
		}
		return cnt
	}

	if count() != 1 {
		return 0
	}
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if grid[i][j] == 1 {
				grid[i][j] = 0
				if count() != 1 {
					return 1
				}
				grid[i][j] = 1
			}
		}
	}
	return 2
}
```

#### TypeScript

```ts
function minDays(grid: number[][]): number {
    const [m, n] = [grid.length, grid[0].length];

    const dfs = (i: number, j: number) => {
        if (i < 0 || m <= i || j < 0 || n <= j || [0, 2].includes(grid[i][j])) return;

        grid[i][j] = 2;
        const dir = [-1, 0, 1, 0, -1];
        for (let k = 0; k < 4; k++) {
            const [y, x] = [i + dir[k], j + dir[k + 1]];
            dfs(y, x);
        }
    };

    const count = () => {
        let c = 0;

        for (let i = 0; i < m; i++) {
            for (let j = 0; j < n; j++) {
                if (grid[i][j] === 1) {
                    dfs(i, j);
                    c++;
                }
            }
        }

        for (let i = 0; i < m; i++) {
            for (let j = 0; j < n; j++) {
                if (grid[i][j] === 2) {
                    grid[i][j] = 1;
                }
            }
        }

        return c;
    };

    if (count() !== 1) return 0;

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j] === 1) {
                grid[i][j] = 0;

                if (count() !== 1) return 1;

                grid[i][j] = 1;
            }
        }
    }

    return 2;
}
```

#### JavaScript

```js
/**
 * @param {number[][]} grid
 * @return {number}
 */
var minDays = function (grid) {
    const dirs = [-1, 0, 1, 0, -1];
    const [m, n] = [grid.length, grid[0].length];

    const dfs = (i, j, visited) => {
        if (i < 0 || m <= i || j < 0 || n <= j || grid[i][j] === 0 || visited[i][j]) {
            return;
        }

        visited[i][j] = true;
        for (let d = 0; d < 4; d++) {
            const [y, x] = [i + dirs[d], j + dirs[d + 1]];
            dfs(y, x, visited);
        }
    };

    const count = () => {
        const vis = Array.from({ length: m }, () => Array(n).fill(false));
        let c = 0;
        for (let i = 0; i < m; i++) {
            for (let j = 0; j < n; j++) {
                if (grid[i][j] === 1 && !vis[i][j]) {
                    c++;
                    dfs(i, j, vis);
                }
            }
        }
        return c;
    };

    if (count() !== 1) return 0;

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j] === 1) {
                grid[i][j] = 0;
                if (count() !== 1) return 1;
                grid[i][j] = 1;
            }
        }
    }

    return 2;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1569. 将子数组重新排序得到同一个二叉搜索树的方案数](https://leetcode.cn/problems/number-of-ways-to-reorder-array-to-get-same-bst){#1569}

{{< tabs "1569" >}}

{{% tab "python" %}}
```python
class Solution:
    def numOfWays(self, nums: List[int]) -> int:
        def dfs(nums):
            if len(nums) < 2:
                return 1
            left = [x for x in nums if x < nums[0]]
            right = [x for x in nums if x > nums[0]]
            m, n = len(left), len(right)
            a, b = dfs(left), dfs(right)
            return (((c[m + n][m] * a) % mod) * b) % mod

        n = len(nums)
        mod = 10**9 + 7
        c = [[0] * n for _ in range(n)]
        c[0][0] = 1
        for i in range(1, n):
            c[i][0] = 1
            for j in range(1, i + 1):
                c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod
        return (dfs(nums) - 1 + mod) % mod
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[][] c;
    private final int mod = (int) 1e9 + 7;

    public int numOfWays(int[] nums) {
        int n = nums.length;
        c = new int[n][n];
        c[0][0] = 1;
        for (int i = 1; i < n; ++i) {
            c[i][0] = 1;
            for (int j = 1; j <= i; ++j) {
                c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
            }
        }
        List<Integer> list = new ArrayList<>();
        for (int x : nums) {
            list.add(x);
        }
        return (dfs(list) - 1 + mod) % mod;
    }

    private int dfs(List<Integer> nums) {
        if (nums.size() < 2) {
            return 1;
        }
        List<Integer> left = new ArrayList<>();
        List<Integer> right = new ArrayList<>();
        for (int x : nums) {
            if (x < nums.get(0)) {
                left.add(x);
            } else if (x > nums.get(0)) {
                right.add(x);
            }
        }
        int m = left.size(), n = right.size();
        int a = dfs(left), b = dfs(right);
        return (int) ((long) a * b % mod * c[m + n][n] % mod);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        const int mod = 1e9 + 7;
        int c[n][n];
        memset(c, 0, sizeof(c));
        c[0][0] = 1;
        for (int i = 1; i < n; ++i) {
            c[i][0] = 1;
            for (int j = 1; j <= i; ++j) {
                c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
            }
        }
        function<int(vector<int>)> dfs = [&](vector<int> nums) -> int {
            if (nums.size() < 2) {
                return 1;
            }
            vector<int> left, right;
            for (int& x : nums) {
                if (x < nums[0]) {
                    left.push_back(x);
                } else if (x > nums[0]) {
                    right.push_back(x);
                }
            }
            int m = left.size(), n = right.size();
            int a = dfs(left), b = dfs(right);
            return c[m + n][m] * 1ll * a % mod * b % mod;
        };
        return (dfs(nums) - 1 + mod) % mod;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numOfWays(nums []int) int {
	n := len(nums)
	const mod = 1e9 + 7
	c := make([][]int, n)
	for i := range c {
		c[i] = make([]int, n)
	}
	c[0][0] = 1
	for i := 1; i < n; i++ {
		c[i][0] = 1
		for j := 1; j <= i; j++ {
			c[i][j] = (c[i-1][j] + c[i-1][j-1]) % mod
		}
	}
	var dfs func(nums []int) int
	dfs = func(nums []int) int {
		if len(nums) < 2 {
			return 1
		}
		var left, right []int
		for _, x := range nums[1:] {
			if x < nums[0] {
				left = append(left, x)
			} else {
				right = append(right, x)
			}
		}
		m, n := len(left), len(right)
		a, b := dfs(left), dfs(right)
		return c[m+n][m] * a % mod * b % mod
	}
	return (dfs(nums) - 1 + mod) % mod
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numOfWays(nums: number[]): number {
    const n = nums.length;
    const mod = 1e9 + 7;
    const c = new Array(n).fill(0).map(() => new Array(n).fill(0));
    c[0][0] = 1;
    for (let i = 1; i < n; ++i) {
        c[i][0] = 1;
        for (let j = 1; j <= i; ++j) {
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
        }
    }
    const dfs = (nums: number[]): number => {
        if (nums.length < 2) {
            return 1;
        }
        const left: number[] = [];
        const right: number[] = [];
        for (let i = 1; i < nums.length; ++i) {
            if (nums[i] < nums[0]) {
                left.push(nums[i]);
            } else {
                right.push(nums[i]);
            }
        }
        const m = left.length;
        const n = right.length;
        const a = dfs(left);
        const b = dfs(right);
        return Number((BigInt(c[m + n][m]) * BigInt(a) * BigInt(b)) % BigInt(mod));
    };
    return (dfs(nums) - 1 + mod) % mod;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个数组 <code>nums</code>&nbsp;表示 <code>1</code>&nbsp;到 <code>n</code>&nbsp;的一个排列。我们按照元素在 <code>nums</code>&nbsp;中的顺序依次插入一个初始为空的二叉搜索树（BST）。请你统计将 <code>nums</code>&nbsp;重新排序后，统计满足如下条件的方案数：重排后得到的二叉搜索树与 <code>nums</code>&nbsp;原本数字顺序得到的二叉搜索树相同。</p>

<p>比方说，给你&nbsp;<code>nums = [2,1,3]</code>，我们得到一棵 2 为根，1 为左孩子，3 为右孩子的树。数组&nbsp;<code>[2,3,1]</code>&nbsp;也能得到相同的 BST，但&nbsp;<code>[3,2,1]</code>&nbsp;会得到一棵不同的&nbsp;BST 。</p>

<p>请你返回重排 <code>nums</code>&nbsp;后，与原数组 <code>nums</code> 得到相同二叉搜索树的方案数。</p>

<p>由于答案可能会很大，请将结果对<strong>&nbsp;</strong><code>10^9 + 7</code>&nbsp;取余数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1569.Number%20of%20Ways%20to%20Reorder%20Array%20to%20Get%20Same%20BST/images/bb.png" style="height: 101px; width: 121px;" /></p>

<pre>
<strong>输入：</strong>nums = [2,1,3]
<strong>输出：</strong>1
<strong>解释：</strong>我们将 nums 重排， [2,3,1] 能得到相同的 BST 。没有其他得到相同 BST 的方案了。
</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1569.Number%20of%20Ways%20to%20Reorder%20Array%20to%20Get%20Same%20BST/images/ex1.png" style="height: 161px; width: 241px;" /></strong></p>

<pre>
<strong>输入：</strong>nums = [3,4,5,1,2]
<strong>输出：</strong>5
<strong>解释：</strong>下面 5 个数组会得到相同的 BST：
[3,1,2,4,5]
[3,1,4,2,5]
[3,1,4,5,2]
[3,4,1,2,5]
[3,4,1,5,2]
</pre>

<p><strong>示例 3：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1569.Number%20of%20Ways%20to%20Reorder%20Array%20to%20Get%20Same%20BST/images/ex4.png" style="height: 161px; width: 121px;" /></strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3]
<strong>输出：</strong>0
<strong>解释：</strong>没有别的排列顺序能得到相同的 BST 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= nums.length</code></li>
	<li><code>nums</code>&nbsp;中所有数 <strong>互不相同</strong>&nbsp;。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：组合计数 + 递归

我们设计一个函数 $dfs(nums)$，它的功能是计算以 $nums$ 为节点构成的二叉搜索树的方案数。那么答案就是 $dfs(nums)-1$，因为 $dfs(nums)$ 计算的是以 $nums$ 为节点构成的二叉搜索树的方案数，而题目要求的是重排后与原数组 $nums$ 得到相同二叉搜索树的方案数，因此答案需要减去一。

接下来，我们来看一下 $dfs(nums)$ 的计算方法。

对于一个数组 $nums$，它的第一个元素是根节点，那么它的左子树的元素都小于它，右子树的元素都大于它。因此，我们可以将数组分为三部分，第一部分是根节点，第二部分是左子树的元素，记为 $left$，第三部分是右子树的元素，记为 $right$。那么，左子树的元素个数为 $m$，右子树的元素个数为 $n$，那么 $left$ 和 $right$ 的方案数分别为 $dfs(left)$ 和 $dfs(right)$。我们可以在数组 $nums$ 的 $m + n$ 个位置中选择 $m$ 个位置放置左子树的元素，剩下的 $n$ 个位置放置右子树的元素，这样就能保证重排后与原数组 $nums$ 得到相同二叉搜索树。因此，$dfs(nums)$ 的计算方法为：

$$
dfs(nums) = C_{m+n}^m \times dfs(left) \times dfs(right)
$$

其中 $C_{m+n}^m$ 表示从 $m + n$ 个位置中选择 $m$ 个位置的方案数，我们可以通过预处理得到。

注意答案的取模运算，因为 $dfs(nums)$ 的值可能会很大，所以我们需要在计算过程中对每一步的结果取模，最后再对整个结果取模。

时间复杂度 $O(n^2)$，空间复杂度 $O(n^2)$。其中 $n$ 是数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numOfWays(self, nums: List[int]) -> int:
        def dfs(nums):
            if len(nums) < 2:
                return 1
            left = [x for x in nums if x < nums[0]]
            right = [x for x in nums if x > nums[0]]
            m, n = len(left), len(right)
            a, b = dfs(left), dfs(right)
            return (((c[m + n][m] * a) % mod) * b) % mod

        n = len(nums)
        mod = 10**9 + 7
        c = [[0] * n for _ in range(n)]
        c[0][0] = 1
        for i in range(1, n):
            c[i][0] = 1
            for j in range(1, i + 1):
                c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod
        return (dfs(nums) - 1 + mod) % mod
```

#### Java

```java
class Solution {
    private int[][] c;
    private final int mod = (int) 1e9 + 7;

    public int numOfWays(int[] nums) {
        int n = nums.length;
        c = new int[n][n];
        c[0][0] = 1;
        for (int i = 1; i < n; ++i) {
            c[i][0] = 1;
            for (int j = 1; j <= i; ++j) {
                c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
            }
        }
        List<Integer> list = new ArrayList<>();
        for (int x : nums) {
            list.add(x);
        }
        return (dfs(list) - 1 + mod) % mod;
    }

    private int dfs(List<Integer> nums) {
        if (nums.size() < 2) {
            return 1;
        }
        List<Integer> left = new ArrayList<>();
        List<Integer> right = new ArrayList<>();
        for (int x : nums) {
            if (x < nums.get(0)) {
                left.add(x);
            } else if (x > nums.get(0)) {
                right.add(x);
            }
        }
        int m = left.size(), n = right.size();
        int a = dfs(left), b = dfs(right);
        return (int) ((long) a * b % mod * c[m + n][n] % mod);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        const int mod = 1e9 + 7;
        int c[n][n];
        memset(c, 0, sizeof(c));
        c[0][0] = 1;
        for (int i = 1; i < n; ++i) {
            c[i][0] = 1;
            for (int j = 1; j <= i; ++j) {
                c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
            }
        }
        function<int(vector<int>)> dfs = [&](vector<int> nums) -> int {
            if (nums.size() < 2) {
                return 1;
            }
            vector<int> left, right;
            for (int& x : nums) {
                if (x < nums[0]) {
                    left.push_back(x);
                } else if (x > nums[0]) {
                    right.push_back(x);
                }
            }
            int m = left.size(), n = right.size();
            int a = dfs(left), b = dfs(right);
            return c[m + n][m] * 1ll * a % mod * b % mod;
        };
        return (dfs(nums) - 1 + mod) % mod;
    }
};
```

#### Go

```go
func numOfWays(nums []int) int {
	n := len(nums)
	const mod = 1e9 + 7
	c := make([][]int, n)
	for i := range c {
		c[i] = make([]int, n)
	}
	c[0][0] = 1
	for i := 1; i < n; i++ {
		c[i][0] = 1
		for j := 1; j <= i; j++ {
			c[i][j] = (c[i-1][j] + c[i-1][j-1]) % mod
		}
	}
	var dfs func(nums []int) int
	dfs = func(nums []int) int {
		if len(nums) < 2 {
			return 1
		}
		var left, right []int
		for _, x := range nums[1:] {
			if x < nums[0] {
				left = append(left, x)
			} else {
				right = append(right, x)
			}
		}
		m, n := len(left), len(right)
		a, b := dfs(left), dfs(right)
		return c[m+n][m] * a % mod * b % mod
	}
	return (dfs(nums) - 1 + mod) % mod
}
```

#### TypeScript

```ts
function numOfWays(nums: number[]): number {
    const n = nums.length;
    const mod = 1e9 + 7;
    const c = new Array(n).fill(0).map(() => new Array(n).fill(0));
    c[0][0] = 1;
    for (let i = 1; i < n; ++i) {
        c[i][0] = 1;
        for (let j = 1; j <= i; ++j) {
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
        }
    }
    const dfs = (nums: number[]): number => {
        if (nums.length < 2) {
            return 1;
        }
        const left: number[] = [];
        const right: number[] = [];
        for (let i = 1; i < nums.length; ++i) {
            if (nums[i] < nums[0]) {
                left.push(nums[i]);
            } else {
                right.push(nums[i]);
            }
        }
        const m = left.length;
        const n = right.length;
        const a = dfs(left);
        const b = dfs(right);
        return Number((BigInt(c[m + n][m]) * BigInt(a) * BigInt(b)) % BigInt(mod));
    };
    return (dfs(nums) - 1 + mod) % mod;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
