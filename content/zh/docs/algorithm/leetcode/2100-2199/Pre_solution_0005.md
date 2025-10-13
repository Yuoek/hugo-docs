---
title: "2140_解决智力问题"
date: 2025-10-08T18:39:03+08:00
weight: 5
tags: [二分查找, 前缀和, 动态规划, 双指针, 堆（优先队列）, 字符串, 广度优先搜索, 排序, 数学, 数据库, 数组, 模拟, 矩阵, 计数, 贪心]
---

{{< markmap >}}
### [2140_解决智力问题](#2140)
#### [数组](#2140)
#### [动态规划](#2140)
### [2141_同时运行 N 台电脑的最长时间](#2141)
#### [贪心](#2141)
#### [数组](#2141)
#### [二分查找](#2141)
#### [排序](#2141)
### [2142_每辆车的乘客人数 I 🔒](#2142)
#### [数据库](#2142)
### [2143_在两个数组的区间中选取数字 🔒](#2143)
#### [数组](#2143)
#### [动态规划](#2143)
### [2144_打折购买糖果的最小开销](#2144)
#### [贪心](#2144)
#### [数组](#2144)
#### [排序](#2144)
### [2145_统计隐藏数组数目](#2145)
#### [数组](#2145)
#### [前缀和](#2145)
### [2146_价格范围内最高排名的 K 样物品](#2146)
#### [广度优先搜索](#2146)
#### [数组](#2146)
#### [矩阵](#2146)
#### [排序](#2146)
#### [堆（优先队列）](#2146)
### [2147_分隔长廊的方案数](#2147)
#### [数学](#2147)
#### [字符串](#2147)
#### [动态规划](#2147)
### [2148_元素计数](#2148)
#### [数组](#2148)
#### [计数](#2148)
#### [排序](#2148)
### [2149_按符号重排数组](#2149)
#### [数组](#2149)
#### [双指针](#2149)
#### [模拟](#2149)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2140_解决智力问题
___
#### 数组
___
#### 动态规划
---
### 2141_同时运行 N 台电脑的最长时间
___
#### 贪心
___
#### 数组
___
#### 二分查找
___
#### 排序
---
### 2142_每辆车的乘客人数 I 🔒
___
#### 数据库
---
### 2143_在两个数组的区间中选取数字 🔒
___
#### 数组
___
#### 动态规划
---
### 2144_打折购买糖果的最小开销
___
#### 贪心
___
#### 数组
___
#### 排序
---
### 2145_统计隐藏数组数目
___
#### 数组
___
#### 前缀和
---
### 2146_价格范围内最高排名的 K 样物品
___
#### 广度优先搜索
___
#### 数组
___
#### 矩阵
___
#### 排序
___
#### 堆（优先队列）
---
### 2147_分隔长廊的方案数
___
#### 数学
___
#### 字符串
___
#### 动态规划
---
### 2148_元素计数
___
#### 数组
___
#### 计数
___
#### 排序
---
### 2149_按符号重排数组
___
#### 数组
___
#### 双指针
___
#### 模拟
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 前缀和 | 动态规划 |
| 双指针 | 堆（优先队列） | 字符串 |
| 广度优先搜索 | 排序 | 数学 |
| 数据库 | 数组 | 模拟 |
| 矩阵 | 计数 | 贪心 |

# [2140. 解决智力问题](https://leetcode.cn/problems/solving-questions-with-brainpower){#2140}

{{< tabs "2140" >}}

{{% tab "python" %}}
```python
class Solution:
    def mostPoints(self, questions: List[List[int]]) -> int:
        n = len(questions)
        f = [0] * (n + 1)
        for i in range(n - 1, -1, -1):
            p, b = questions[i]
            j = i + b + 1
            f[i] = max(f[i + 1], p + (0 if j > n else f[j]))
        return f[0]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long mostPoints(int[][] questions) {
        int n = questions.length;
        long[] f = new long[n + 1];
        for (int i = n - 1; i >= 0; --i) {
            int p = questions[i][0], b = questions[i][1];
            int j = i + b + 1;
            f[i] = Math.max(f[i + 1], p + (j > n ? 0 : f[j]));
        }
        return f[0];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        long long f[n + 1];
        memset(f, 0, sizeof(f));
        for (int i = n - 1; ~i; --i) {
            int p = questions[i][0], b = questions[i][1];
            int j = i + b + 1;
            f[i] = max(f[i + 1], p + (j > n ? 0 : f[j]));
        }
        return f[0];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func mostPoints(questions [][]int) int64 {
	n := len(questions)
	f := make([]int64, n+1)
	for i := n - 1; i >= 0; i-- {
		p := int64(questions[i][0])
		if j := i + questions[i][1] + 1; j <= n {
			p += f[j]
		}
		f[i] = max(f[i+1], p)
	}
	return f[0]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function mostPoints(questions: number[][]): number {
    const n = questions.length;
    const f = Array(n + 1).fill(0);
    for (let i = n - 1; i >= 0; --i) {
        const [p, b] = questions[i];
        const j = i + b + 1;
        f[i] = Math.max(f[i + 1], p + (j > n ? 0 : f[j]));
    }
    return f[0];
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn most_points(questions: Vec<Vec<i32>>) -> i64 {
        let n = questions.len();
        let mut f = vec![0; n + 1];
        for i in (0..n).rev() {
            let p = questions[i][0] as i64;
            let b = questions[i][1] as usize;
            let j = i + b + 1;
            f[i] = f[i + 1].max(p + if j > n { 0 } else { f[j] });
        }
        f[0]
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的二维整数数组&nbsp;<code>questions</code>&nbsp;，其中&nbsp;<code>questions[i] = [points<sub>i</sub>, brainpower<sub>i</sub>]</code>&nbsp;。</p>

<p>这个数组表示一场考试里的一系列题目，你需要 <strong>按顺序</strong>&nbsp;（也就是从问题 <code>0</code><strong>&nbsp;</strong>开始依次解决），针对每个问题选择 <strong>解决</strong>&nbsp;或者 <strong>跳过</strong>&nbsp;操作。解决问题 <code>i</code>&nbsp;将让你 <b>获得</b>&nbsp;&nbsp;<code>points<sub>i</sub></code>&nbsp;的分数，但是你将 <strong>无法</strong>&nbsp;解决接下来的&nbsp;<code>brainpower<sub>i</sub></code>&nbsp;个问题（即只能跳过接下来的 <code>brainpower<sub>i</sub></code><sub>&nbsp;</sub>个问题）。如果你跳过问题&nbsp;<code>i</code>&nbsp;，你可以对下一个问题决定使用哪种操作。</p>

<ul>
	<li>比方说，给你&nbsp;<code>questions = [[3, 2], [4, 3], [4, 4], [2, 5]]</code>&nbsp;：

    <ul>
    	<li>如果问题&nbsp;<code>0</code>&nbsp;被解决了， 那么你可以获得&nbsp;<code>3</code>&nbsp;分，但你不能解决问题&nbsp;<code>1</code> 和&nbsp;<code>2</code>&nbsp;。</li>
    	<li>如果你跳过问题&nbsp;<code>0</code>&nbsp;，且解决问题&nbsp;<code>1</code>&nbsp;，你将获得 <code>4</code> 分但是不能解决问题&nbsp;<code>2</code> 和&nbsp;<code>3</code>&nbsp;。</li>
    </ul>
    </li>

</ul>

<p>请你返回这场考试里你能获得的 <strong>最高</strong>&nbsp;分数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>questions = [[3,2],[4,3],[4,4],[2,5]]
<b>输出：</b>5
<b>解释：</b>解决问题 0 和 3 得到最高分。
- 解决问题 0 ：获得 3 分，但接下来 2 个问题都不能解决。
- 不能解决问题 1 和 2
- 解决问题 3 ：获得 2 分
总得分为：3 + 2 = 5 。没有别的办法获得 5 分或者多于 5 分。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>questions = [[1,1],[2,2],[3,3],[4,4],[5,5]]
<b>输出：</b>7
<b>解释：</b>解决问题 1 和 4 得到最高分。
- 跳过问题 0
- 解决问题 1 ：获得 2 分，但接下来 2 个问题都不能解决。
- 不能解决问题 2 和 3
- 解决问题 4 ：获得 5 分
总得分为：2 + 5 = 7 。没有别的办法获得 7 分或者多于 7 分。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= questions.length &lt;= 10<sup>5</sup></code></li>
	<li><code>questions[i].length == 2</code></li>
	<li><code>1 &lt;= points<sub>i</sub>, brainpower<sub>i</sub> &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

我们设计一个函数 $\textit{dfs}(i)$，表示从第 $i$ 个问题开始解决，能够获得的最高分数。那么答案就是 $\textit{dfs}(0)$。

函数 $\textit{dfs}(i)$ 的计算方式如下：

-   如果 $i \geq n$，表示已经解决完所有问题，返回 $0$；
-   否则，设第 $i$ 个问题的分数为 $p$，需要跳过的问题数为 $b$，那么 $\textit{dfs}(i) = \max(p + \textit{dfs}(i + b + 1), \textit{dfs}(i + 1))$。

为了避免重复计算，我们可以使用记忆化搜索的方法，用一个数组 $f$ 记录所有已经计算过的 $\textit{dfs}(i)$ 的值。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是问题的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def mostPoints(self, questions: List[List[int]]) -> int:
        @cache
        def dfs(i: int) -> int:
            if i >= len(questions):
                return 0
            p, b = questions[i]
            return max(p + dfs(i + b + 1), dfs(i + 1))

        return dfs(0)
```

#### Java

```java
class Solution {
    private int n;
    private Long[] f;
    private int[][] questions;

    public long mostPoints(int[][] questions) {
        n = questions.length;
        f = new Long[n];
        this.questions = questions;
        return dfs(0);
    }

    private long dfs(int i) {
        if (i >= n) {
            return 0;
        }
        if (f[i] != null) {
            return f[i];
        }
        int p = questions[i][0], b = questions[i][1];
        return f[i] = Math.max(p + dfs(i + b + 1), dfs(i + 1));
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        long long f[n];
        memset(f, 0, sizeof(f));
        auto dfs = [&](this auto&& dfs, int i) -> long long {
            if (i >= n) {
                return 0;
            }
            if (f[i]) {
                return f[i];
            }
            int p = questions[i][0], b = questions[i][1];
            return f[i] = max(p + dfs(i + b + 1), dfs(i + 1));
        };
        return dfs(0);
    }
};
```

#### Go

```go
func mostPoints(questions [][]int) int64 {
	n := len(questions)
	f := make([]int64, n)
	var dfs func(int) int64
	dfs = func(i int) int64 {
		if i >= n {
			return 0
		}
		if f[i] > 0 {
			return f[i]
		}
		p, b := questions[i][0], questions[i][1]
		f[i] = max(int64(p)+dfs(i+b+1), dfs(i+1))
		return f[i]
	}
	return dfs(0)
}
```

#### TypeScript

```ts
function mostPoints(questions: number[][]): number {
    const n = questions.length;
    const f = Array(n).fill(0);
    const dfs = (i: number): number => {
        if (i >= n) {
            return 0;
        }
        if (f[i] > 0) {
            return f[i];
        }
        const [p, b] = questions[i];
        return (f[i] = Math.max(p + dfs(i + b + 1), dfs(i + 1)));
    };
    return dfs(0);
}
```

#### Rust

```rust
impl Solution {
    pub fn most_points(questions: Vec<Vec<i32>>) -> i64 {
        let n = questions.len();
        let mut f = vec![-1; n];

        fn dfs(i: usize, questions: &Vec<Vec<i32>>, f: &mut Vec<i64>) -> i64 {
            if i >= questions.len() {
                return 0;
            }
            if f[i] != -1 {
                return f[i];
            }
            let p = questions[i][0] as i64;
            let b = questions[i][1] as usize;
            f[i] = (p + dfs(i + b + 1, questions, f)).max(dfs(i + 1, questions, f));
            f[i]
        }

        dfs(0, &questions, &mut f)
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：动态规划

我们定义 $f[i]$ 表示从第 $i$ 个问题开始解决，能够获得的最高分数。那么答案就是 $f[0]$。

考虑 $f[i]$，第 $i$ 个问题的分数为 $p$，需要跳过的问题数为 $b$。如果我们解决了第 $i$ 个问题，那么接下来我们需要解决 $b$ 个问题，因此 $f[i] = p + f[i + b + 1]$。如果我们跳过了第 $i$ 个问题，那么接下来我们从第 $i + 1$ 个问题开始解决，因此 $f[i] = f[i + 1]$。两者取最大值即可。状态转移方程如下：

$$
f[i] = \max(p + f[i + b + 1], f[i + 1])
$$

我们从后往前计算 $f$ 的值，最后返回 $f[0]$ 即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是问题的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def mostPoints(self, questions: List[List[int]]) -> int:
        n = len(questions)
        f = [0] * (n + 1)
        for i in range(n - 1, -1, -1):
            p, b = questions[i]
            j = i + b + 1
            f[i] = max(f[i + 1], p + (0 if j > n else f[j]))
        return f[0]
```

#### Java

```java
class Solution {
    public long mostPoints(int[][] questions) {
        int n = questions.length;
        long[] f = new long[n + 1];
        for (int i = n - 1; i >= 0; --i) {
            int p = questions[i][0], b = questions[i][1];
            int j = i + b + 1;
            f[i] = Math.max(f[i + 1], p + (j > n ? 0 : f[j]));
        }
        return f[0];
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        long long f[n + 1];
        memset(f, 0, sizeof(f));
        for (int i = n - 1; ~i; --i) {
            int p = questions[i][0], b = questions[i][1];
            int j = i + b + 1;
            f[i] = max(f[i + 1], p + (j > n ? 0 : f[j]));
        }
        return f[0];
    }
};
```

#### Go

```go
func mostPoints(questions [][]int) int64 {
	n := len(questions)
	f := make([]int64, n+1)
	for i := n - 1; i >= 0; i-- {
		p := int64(questions[i][0])
		if j := i + questions[i][1] + 1; j <= n {
			p += f[j]
		}
		f[i] = max(f[i+1], p)
	}
	return f[0]
}
```

#### TypeScript

```ts
function mostPoints(questions: number[][]): number {
    const n = questions.length;
    const f = Array(n + 1).fill(0);
    for (let i = n - 1; i >= 0; --i) {
        const [p, b] = questions[i];
        const j = i + b + 1;
        f[i] = Math.max(f[i + 1], p + (j > n ? 0 : f[j]));
    }
    return f[0];
}
```

#### Rust

```rust
impl Solution {
    pub fn most_points(questions: Vec<Vec<i32>>) -> i64 {
        let n = questions.len();
        let mut f = vec![0; n + 1];
        for i in (0..n).rev() {
            let p = questions[i][0] as i64;
            let b = questions[i][1] as usize;
            let j = i + b + 1;
            f[i] = f[i + 1].max(p + if j > n { 0 } else { f[j] });
        }
        f[0]
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2141. 同时运行 N 台电脑的最长时间](https://leetcode.cn/problems/maximum-running-time-of-n-computers){#2141}

{{< tabs "2141" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxRunTime(self, n: int, batteries: List[int]) -> int:
        l, r = 0, sum(batteries)
        while l < r:
            mid = (l + r + 1) >> 1
            if sum(min(x, mid) for x in batteries) >= n * mid:
                l = mid
            else:
                r = mid - 1
        return l
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long maxRunTime(int n, int[] batteries) {
        long l = 0, r = 0;
        for (int x : batteries) {
            r += x;
        }
        while (l < r) {
            long mid = (l + r + 1) >> 1;
            long s = 0;
            for (int x : batteries) {
                s += Math.min(mid, x);
            }
            if (s >= n * mid) {
                l = mid;
            } else {
                r = mid - 1;
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
    long long maxRunTime(int n, vector<int>& batteries) {
        long long l = 0, r = 0;
        for (int x : batteries) {
            r += x;
        }
        while (l < r) {
            long long mid = (l + r + 1) >> 1;
            long long s = 0;
            for (int x : batteries) {
                s += min(1LL * x, mid);
            }
            if (s >= n * mid) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxRunTime(n int, batteries []int) int64 {
	l, r := 0, 0
	for _, x := range batteries {
		r += x
	}
	for l < r {
		mid := (l + r + 1) >> 1
		s := 0
		for _, x := range batteries {
			s += min(x, mid)
		}
		if s >= n*mid {
			l = mid
		} else {
			r = mid - 1
		}
	}
	return int64(l)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxRunTime(n: number, batteries: number[]): number {
    let l = 0n;
    let r = 0n;
    for (const x of batteries) {
        r += BigInt(x);
    }
    while (l < r) {
        const mid = (l + r + 1n) >> 1n;
        let s = 0n;
        for (const x of batteries) {
            s += BigInt(Math.min(x, Number(mid)));
        }
        if (s >= mid * BigInt(n)) {
            l = mid;
        } else {
            r = mid - 1n;
        }
    }
    return Number(l);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    #[allow(dead_code)]
    pub fn max_run_time(n: i32, batteries: Vec<i32>) -> i64 {
        // First sort the batteries
        let mut batteries = batteries;
        let m = batteries.len() as i32;
        batteries.sort();

        let mut extra_sum: i64 = 0;
        for i in 0..(m - n) as usize {
            extra_sum += batteries[i] as i64;
        }

        let mut i = (m - n) as usize;
        let mut cur_height = batteries[i];
        let mut ret = cur_height as i64;
        while extra_sum != 0 {
            if i + 1 == (m as usize) {
                assert!(cur_height == *batteries.last().unwrap());
                ret += extra_sum / (n as i64);
                break;
            }

            if batteries[i] == batteries[i + 1] {
                i += 1;
                continue;
            }

            let diff = extra_sum / ((i - ((m - n) as usize) + 1) as i64);

            if (cur_height as i64) + diff <= (batteries[i + 1] as i64) {
                ret = (cur_height as i64) + diff;
                break;
            } else {
                extra_sum -= ((batteries[i + 1] - batteries[i]) as i64)
                    * ((i - ((m - n) as usize) + 1) as i64);
                ret = batteries[i + 1] as i64;
            }

            i += 1;
            if i != (m as usize) {
                cur_height = batteries[i];
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

<p>你有&nbsp;<code>n</code>&nbsp;台电脑。给你整数&nbsp;<code>n</code>&nbsp;和一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>batteries</code>&nbsp;，其中第&nbsp;<code>i</code>&nbsp;个电池可以让一台电脑 <strong>运行&nbsp;</strong><code>batteries[i]</code>&nbsp;分钟。你想使用这些电池让&nbsp;<strong>全部</strong>&nbsp;<code>n</code>&nbsp;台电脑 <b>同时</b>&nbsp;运行。</p>

<p>一开始，你可以给每台电脑连接 <strong>至多一个电池</strong>&nbsp;。然后在任意整数时刻，你都可以将一台电脑与它的电池断开连接，并连接另一个电池，你可以进行这个操作 <strong>任意次</strong>&nbsp;。新连接的电池可以是一个全新的电池，也可以是别的电脑用过的电池。断开连接和连接新的电池不会花费任何时间。</p>

<p>注意，你不能给电池充电。</p>

<p>请你返回你可以让 <code>n</code>&nbsp;台电脑同时运行的 <strong>最长</strong>&nbsp;分钟数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2100-2199/2141.Maximum%20Running%20Time%20of%20N%20Computers/images/example1-fit.png" style="width: 762px; height: 150px;"></p>

<pre><b>输入：</b>n = 2, batteries = [3,3,3]
<b>输出：</b>4
<b>解释：</b>
一开始，将第一台电脑与电池 0 连接，第二台电脑与电池 1 连接。
2 分钟后，将第二台电脑与电池 1 断开连接，并连接电池 2 。注意，电池 0 还可以供电 1 分钟。
在第 3 分钟结尾，你需要将第一台电脑与电池 0 断开连接，然后连接电池 1 。
在第 4 分钟结尾，电池 1 也被耗尽，第一台电脑无法继续运行。
我们最多能同时让两台电脑同时运行 4 分钟，所以我们返回 4 。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2100-2199/2141.Maximum%20Running%20Time%20of%20N%20Computers/images/example2.png" style="width: 629px; height: 150px;"></p>

<pre><b>输入：</b>n = 2, batteries = [1,1,1,1]
<b>输出：</b>2
<b>解释：</b>
一开始，将第一台电脑与电池 0 连接，第二台电脑与电池 2 连接。
一分钟后，电池 0 和电池 2 同时耗尽，所以你需要将它们断开连接，并将电池 1 和第一台电脑连接，电池 3 和第二台电脑连接。
1 分钟后，电池 1 和电池 3 也耗尽了，所以两台电脑都无法继续运行。
我们最多能让两台电脑同时运行 2 分钟，所以我们返回 2 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= batteries.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= batteries[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二分查找

我们注意到，如果我们可以让 $n$ 台电脑同时运行 $t$ 分钟，那么我们也可以让 $n$ 台电脑同时运行 $t' \le t$ 分钟，这存在着单调性。因此，我们可以使用二分查找的方法找到最大的 $t$。

我们定义二分查找的左边界 $l=0$，右边界 $r=\sum_{i=0}^{n-1} batteries[i]$。每次二分查找的过程中，我们使用一个变量 $mid$ 表示当前的中间值，即 $mid = (l + r + 1) >> 1$。我们判断是否存在一种方案，使得 $n$ 台电脑同时运行 $mid$ 分钟。如果存在，那么我们就将 $l$ 更新为 $mid$，否则我们将 $r$ 更新为 $mid - 1$。最后，我们返回 $l$ 即为答案。

问题转化为如何判断是否存在一种方案，使得 $n$ 台电脑同时运行 $mid$ 分钟。如果一个电池可以运行的分钟数大于 $mid$，由于电脑同时运行 $mid$ 分钟，而一个电池同一时间只能供电一台电脑，因此我们只能使用这个电池 $mid$ 分钟。如果一个电池可以运行的分钟数小于等于 $mid$，我们可以使用这个电池的全部电量。因此，我们统计所有电池可以供电的分钟数之和 $s$，如果 $s \ge n \times mid$，那么我们就可以使得 $n$ 台电脑同时运行 $mid$ 分钟。

时间复杂度 $O(n \times \log M)$，其中 $M$ 为所有电池的电量之和，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxRunTime(self, n: int, batteries: List[int]) -> int:
        l, r = 0, sum(batteries)
        while l < r:
            mid = (l + r + 1) >> 1
            if sum(min(x, mid) for x in batteries) >= n * mid:
                l = mid
            else:
                r = mid - 1
        return l
```

#### Java

```java
class Solution {
    public long maxRunTime(int n, int[] batteries) {
        long l = 0, r = 0;
        for (int x : batteries) {
            r += x;
        }
        while (l < r) {
            long mid = (l + r + 1) >> 1;
            long s = 0;
            for (int x : batteries) {
                s += Math.min(mid, x);
            }
            if (s >= n * mid) {
                l = mid;
            } else {
                r = mid - 1;
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
    long long maxRunTime(int n, vector<int>& batteries) {
        long long l = 0, r = 0;
        for (int x : batteries) {
            r += x;
        }
        while (l < r) {
            long long mid = (l + r + 1) >> 1;
            long long s = 0;
            for (int x : batteries) {
                s += min(1LL * x, mid);
            }
            if (s >= n * mid) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};
```

#### Go

```go
func maxRunTime(n int, batteries []int) int64 {
	l, r := 0, 0
	for _, x := range batteries {
		r += x
	}
	for l < r {
		mid := (l + r + 1) >> 1
		s := 0
		for _, x := range batteries {
			s += min(x, mid)
		}
		if s >= n*mid {
			l = mid
		} else {
			r = mid - 1
		}
	}
	return int64(l)
}
```

#### TypeScript

```ts
function maxRunTime(n: number, batteries: number[]): number {
    let l = 0n;
    let r = 0n;
    for (const x of batteries) {
        r += BigInt(x);
    }
    while (l < r) {
        const mid = (l + r + 1n) >> 1n;
        let s = 0n;
        for (const x of batteries) {
            s += BigInt(Math.min(x, Number(mid)));
        }
        if (s >= mid * BigInt(n)) {
            l = mid;
        } else {
            r = mid - 1n;
        }
    }
    return Number(l);
}
```

#### Rust

```rust
impl Solution {
    #[allow(dead_code)]
    pub fn max_run_time(n: i32, batteries: Vec<i32>) -> i64 {
        // First sort the batteries
        let mut batteries = batteries;
        let m = batteries.len() as i32;
        batteries.sort();

        let mut extra_sum: i64 = 0;
        for i in 0..(m - n) as usize {
            extra_sum += batteries[i] as i64;
        }

        let mut i = (m - n) as usize;
        let mut cur_height = batteries[i];
        let mut ret = cur_height as i64;
        while extra_sum != 0 {
            if i + 1 == (m as usize) {
                assert!(cur_height == *batteries.last().unwrap());
                ret += extra_sum / (n as i64);
                break;
            }

            if batteries[i] == batteries[i + 1] {
                i += 1;
                continue;
            }

            let diff = extra_sum / ((i - ((m - n) as usize) + 1) as i64);

            if (cur_height as i64) + diff <= (batteries[i + 1] as i64) {
                ret = (cur_height as i64) + diff;
                break;
            } else {
                extra_sum -= ((batteries[i + 1] - batteries[i]) as i64)
                    * ((i - ((m - n) as usize) + 1) as i64);
                ret = batteries[i + 1] as i64;
            }

            i += 1;
            if i != (m as usize) {
                cur_height = batteries[i];
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

# [2142. 每辆车的乘客人数 I 🔒](https://leetcode.cn/problems/the-number-of-passengers-in-each-bus-i){#2142}

{{< tabs "2142" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT
    bus_id,
    COUNT(passenger_id) - LAG(COUNT(passenger_id), 1, 0) OVER (
        ORDER BY b.arrival_time
    ) AS passengers_cnt
FROM
    Buses AS b
    LEFT JOIN Passengers AS p ON p.arrival_time <= b.arrival_time
GROUP BY 1
ORDER BY 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表: <code>Buses</code></p>

<pre>
+--------------+------+
| Column Name  | Type |
+--------------+------+
| bus_id       | int  |
| arrival_time | int  |
+--------------+------+
bus_id 是该表的主键。
该表的每一行都包含关于 LeetCode 站点的公交车到达时间的信息。
不会出现两辆公交车会同时到达。</pre>

<p>&nbsp;</p>

<p>表: <code>Passengers</code></p>

<pre>
+--------------+------+
| Column Name  | Type |
+--------------+------+
| passenger_id | int  |
| arrival_time | int  |
+--------------+------+
passenger_id 是该表的主键。
该表的每一行都包含乘客到达 LeetCode 站的时间信息。
</pre>

<p>&nbsp;</p>

<p>公交车和乘客到达 LeetCode 站。如果一辆公交车在时间 <code>t<sub>bus</sub></code> 到站，乘客在时间 <code>t<sub>passenger</sub></code> 到站，其中 <code>t<sub>passenger</sub> &lt;= t<sub>bus</sub></code>，该乘客之前没有赶上任何公交车，则该乘客将搭乘该公交车。</p>

<p>编写一个 SQL 来查询使用每辆公交车的用户数量。</p>

<p>返回按 <code>bus_id</code> <strong>升序排序&nbsp;</strong>的结果表。</p>

<p>查询结果格式如下所示。</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> 
Buses 表:
+--------+--------------+
| bus_id | arrival_time |
+--------+--------------+
| 1      | 2            |
| 2      | 4            |
| 3      | 7            |
+--------+--------------+
Passengers 表:
+--------------+--------------+
| passenger_id | arrival_time |
+--------------+--------------+
| 11           | 1            |
| 12           | 5            |
| 13           | 6            |
| 14           | 7            |
+--------------+--------------+
<strong>输出:</strong> 
+--------+----------------+
| bus_id | passengers_cnt |
+--------+----------------+
| 1      | 1              |
| 2      | 0              |
| 3      | 3              |
+--------+----------------+
<strong>解释:</strong> 
- 11 号乘客在时间 1 到达。
- 1 号公交车到达时间为 2，搭载 11 号乘客。

- 2 号公交车车在时间 4 到达，没有乘客。

- 12 号乘客在时间 5 到达。
- 13 号乘客在时间 6 到达。
- 14 号乘客在时间 7 到达。
- 3 号车在时间 7 到达，搭载 12、13、14 号乘客。</pre>

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
    bus_id,
    COUNT(passenger_id) - LAG(COUNT(passenger_id), 1, 0) OVER (
        ORDER BY b.arrival_time
    ) AS passengers_cnt
FROM
    Buses AS b
    LEFT JOIN Passengers AS p ON p.arrival_time <= b.arrival_time
GROUP BY 1
ORDER BY 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2143. 在两个数组的区间中选取数字 🔒](https://leetcode.cn/problems/choose-numbers-from-two-arrays-in-range){#2143}

{{< tabs "2143" >}}

{{% tab "python" %}}
```python
class Solution:
    def countSubranges(self, nums1: List[int], nums2: List[int]) -> int:
        n = len(nums1)
        s1, s2 = sum(nums1), sum(nums2)
        f = [[0] * (s1 + s2 + 1) for _ in range(n)]
        ans = 0
        mod = 10**9 + 7
        for i, (a, b) in enumerate(zip(nums1, nums2)):
            f[i][a + s2] += 1
            f[i][-b + s2] += 1
            if i:
                for j in range(s1 + s2 + 1):
                    if j >= a:
                        f[i][j] = (f[i][j] + f[i - 1][j - a]) % mod
                    if j + b < s1 + s2 + 1:
                        f[i][j] = (f[i][j] + f[i - 1][j + b]) % mod
            ans = (ans + f[i][s2]) % mod
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countSubranges(int[] nums1, int[] nums2) {
        int n = nums1.length;
        int s1 = Arrays.stream(nums1).sum();
        int s2 = Arrays.stream(nums2).sum();
        int[][] f = new int[n][s1 + s2 + 1];
        int ans = 0;
        final int mod = (int) 1e9 + 7;
        for (int i = 0; i < n; ++i) {
            int a = nums1[i], b = nums2[i];
            f[i][a + s2]++;
            f[i][-b + s2]++;
            if (i > 0) {
                for (int j = 0; j <= s1 + s2; ++j) {
                    if (j >= a) {
                        f[i][j] = (f[i][j] + f[i - 1][j - a]) % mod;
                    }
                    if (j + b <= s1 + s2) {
                        f[i][j] = (f[i][j] + f[i - 1][j + b]) % mod;
                    }
                }
            }
            ans = (ans + f[i][s2]) % mod;
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
    int countSubranges(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int s1 = accumulate(nums1.begin(), nums1.end(), 0);
        int s2 = accumulate(nums2.begin(), nums2.end(), 0);
        int f[n][s1 + s2 + 1];
        memset(f, 0, sizeof(f));
        int ans = 0;
        const int mod = 1e9 + 7;
        for (int i = 0; i < n; ++i) {
            int a = nums1[i], b = nums2[i];
            f[i][a + s2]++;
            f[i][-b + s2]++;
            if (i) {
                for (int j = 0; j <= s1 + s2; ++j) {
                    if (j >= a) {
                        f[i][j] = (f[i][j] + f[i - 1][j - a]) % mod;
                    }
                    if (j + b <= s1 + s2) {
                        f[i][j] = (f[i][j] + f[i - 1][j + b]) % mod;
                    }
                }
            }
            ans = (ans + f[i][s2]) % mod;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countSubranges(nums1 []int, nums2 []int) (ans int) {
	n := len(nums1)
	s1, s2 := sum(nums1), sum(nums2)
	f := make([][]int, n)
	for i := range f {
		f[i] = make([]int, s1+s2+1)
	}
	const mod int = 1e9 + 7
	for i, a := range nums1 {
		b := nums2[i]
		f[i][a+s2]++
		f[i][-b+s2]++
		if i > 0 {
			for j := 0; j <= s1+s2; j++ {
				if j >= a {
					f[i][j] = (f[i][j] + f[i-1][j-a]) % mod
				}
				if j+b <= s1+s2 {
					f[i][j] = (f[i][j] + f[i-1][j+b]) % mod
				}
			}
		}
		ans = (ans + f[i][s2]) % mod
	}
	return
}

func sum(nums []int) (ans int) {
	for _, x := range nums {
		ans += x
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countSubranges(nums1: number[], nums2: number[]): number {
    const n = nums1.length;
    const s1 = nums1.reduce((a, b) => a + b, 0);
    const s2 = nums2.reduce((a, b) => a + b, 0);
    const f: number[][] = Array(n)
        .fill(0)
        .map(() => Array(s1 + s2 + 1).fill(0));
    const mod = 1e9 + 7;
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        const [a, b] = [nums1[i], nums2[i]];
        f[i][a + s2]++;
        f[i][-b + s2]++;
        if (i) {
            for (let j = 0; j <= s1 + s2; ++j) {
                if (j >= a) {
                    f[i][j] = (f[i][j] + f[i - 1][j - a]) % mod;
                }
                if (j + b <= s1 + s2) {
                    f[i][j] = (f[i][j] + f[i - 1][j + b]) % mod;
                }
            }
        }
        ans = (ans + f[i][s2]) % mod;
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

<p>给你两个 <strong>下标从 0 开始</strong>，长度为 <code>n</code> 的整数数组 <code>nums1</code> 和 <code>nums2</code>。</p>

<p>如果一个区间 <code>[l, r]</code> （<strong>包含左右端点</strong>，<code>0 &lt;= l &lt;= r &lt; n</code>）满足下列条件，那么这个区间就是 <strong>平衡</strong> 的：</p>

<ul>
	<li>对每个在区间 <code>[l, r]</code> 范围内的 <code>i</code>，你需要选取&nbsp;<code>nums1[i]</code> 或者&nbsp;<code>nums2[i]</code>；</li>
	<li>从 <code>nums1</code> 中选取的数字和与从 <code>nums2</code> 中选取的数字和相等。（如果你没有从某个数组中选取任何数字，那么数字和被视为 <code>0</code>）。</li>
</ul>

<p>如果两个 <strong>平衡</strong> 的区间 <code>[l<sub>1</sub>, r<sub>1</sub>]</code> 和 <code>[l<sub>2</sub>, r<sub>2</sub>]</code> 满足下列条件之一，那么它们就是 <strong>不同</strong> 的：</p>

<ul>
	<li><code>l<sub>1</sub> != l<sub>2</sub></code></li>
	<li><code>r<sub>1</sub> != r<sub>2</sub></code></li>
	<li>两个区间中的数字选取情况不同（也就是说，存在至少一个 <code>i</code>，使得在第一个区间中，<code>nums1[i]</code> 被选中, 而在第二个区间中，<code>nums2[i]</code> 被选中，或者相反的情况）。</li>
</ul>

<p>请返回 <strong>不同</strong> 的平衡的区间数目。由于答案可能很大，请返回答案 <strong>模 </strong><code>10<sup>9</sup>+7</code> 的结果。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> nums1 = [1,2,5], nums2 = [2,6,3]
<strong>输出:</strong> 3
<strong>解释:</strong> 平衡的区间有:
- [0, 1], 我们选取 nums2[0] 和 nums1[1]。
  从 <code>nums1</code> 中选取的数字和与从 <code>nums2</code> 中选取的数字和相等: 2 = 2.
- [0, 2], 我们选取 nums1[0], nums2[1] 和 nums1[2]。
  从 <code>nums1</code> 中选取的数字和与从 <code>nums2</code> 中选取的数字和相等: 1 + 5 = 6。
- [0, 2], 我们选取 nums1[0], nums1[1] 和 nums2[2]。
  从 <code>nums1</code> 中选取的数字和与从 <code>nums2</code> 中选取的数字和相等: 1 + 2 = 3。
注意第二个区间和第三个区间是不同的。
因为在第二个平衡的区间中，我们选取了 nums2[1]，但是在第三个平衡的区间中，我们选取了 nums1[1]。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入:</strong> nums1 = [0,1], nums2 = [1,0]
<strong>输出:</strong> 4
<strong>解释:</strong> 平衡的区间有:
- [0, 0], 我们选取 nums1[0]。
  从 <code>nums1</code> 中选取的数字和与从 <code>nums2</code> 中选取的数字和相等: 0 = 0。
- [1, 1], 我们选取 nums2[1]。
  从 <code>nums1</code> 中选取的数字和与从 <code>nums2</code> 中选取的数字和相等: 0 = 0。
- [0, 1], 我们选取 nums1[0] 和 nums2[1]。
  从 <code>nums1</code> 中选取的数字和与从 <code>nums2</code> 中选取的数字和相等: 0 = 0。
- [0, 1], 我们选取 nums2[0] 和 nums1[1]。
  从 <code>nums1</code> 中选取的数字和与从 <code>nums2</code> 中选取的数字和相等: 1 = 1。
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>n == nums1.length == nums2.length</code></li>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>0 &lt;= nums1[i], nums2[i] &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i][j]$ 表示以第 $i$ 个元素结尾，且从 $nums1$ 中选取的数字和与从 $nums2$ 中选取的数字和之差为 $j$ 的平衡区间的个数。由于差值可能为负数，因此，我们统一将 $j$ 加上 $s_2 = \sum_{k=0}^{n-1}nums2[k]$，这样就可以保证 $j$ 为非负整数。

考虑 $f[i][j]$，我们可以单独将第 $i$ 个元素视为一个区间，那么 $f[i][nums1[i] + s_2]$ 和 $f[i][-nums2[i] + s_2]$ 都会增加 $1$。此外，如果 $i \gt 0$，我们也可以将第 $i$ 个元素添加到前面的某个区间中，我们在 $[0, s_1 + s_2]$ 范围内枚举 $j$，如果 $j \geq a$，那么 $f[i][j]$ 会增加 $f[i - 1][j - a]$，如果 $j + b \leq s_1 + s_2$，那么 $f[i][j]$ 会增加 $f[i - 1][j + b]$。

答案为 $\sum_{i=0}^{n-1}f[i][s_2]$。

时间复杂度 $O(n \times M)$，空间复杂度 $O(n \times M)$。其中 $n$ 和 $M$ 分别为数组 $nums1$ 的长度以及数字和的最大值。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countSubranges(self, nums1: List[int], nums2: List[int]) -> int:
        n = len(nums1)
        s1, s2 = sum(nums1), sum(nums2)
        f = [[0] * (s1 + s2 + 1) for _ in range(n)]
        ans = 0
        mod = 10**9 + 7
        for i, (a, b) in enumerate(zip(nums1, nums2)):
            f[i][a + s2] += 1
            f[i][-b + s2] += 1
            if i:
                for j in range(s1 + s2 + 1):
                    if j >= a:
                        f[i][j] = (f[i][j] + f[i - 1][j - a]) % mod
                    if j + b < s1 + s2 + 1:
                        f[i][j] = (f[i][j] + f[i - 1][j + b]) % mod
            ans = (ans + f[i][s2]) % mod
        return ans
```

#### Java

```java
class Solution {
    public int countSubranges(int[] nums1, int[] nums2) {
        int n = nums1.length;
        int s1 = Arrays.stream(nums1).sum();
        int s2 = Arrays.stream(nums2).sum();
        int[][] f = new int[n][s1 + s2 + 1];
        int ans = 0;
        final int mod = (int) 1e9 + 7;
        for (int i = 0; i < n; ++i) {
            int a = nums1[i], b = nums2[i];
            f[i][a + s2]++;
            f[i][-b + s2]++;
            if (i > 0) {
                for (int j = 0; j <= s1 + s2; ++j) {
                    if (j >= a) {
                        f[i][j] = (f[i][j] + f[i - 1][j - a]) % mod;
                    }
                    if (j + b <= s1 + s2) {
                        f[i][j] = (f[i][j] + f[i - 1][j + b]) % mod;
                    }
                }
            }
            ans = (ans + f[i][s2]) % mod;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int countSubranges(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int s1 = accumulate(nums1.begin(), nums1.end(), 0);
        int s2 = accumulate(nums2.begin(), nums2.end(), 0);
        int f[n][s1 + s2 + 1];
        memset(f, 0, sizeof(f));
        int ans = 0;
        const int mod = 1e9 + 7;
        for (int i = 0; i < n; ++i) {
            int a = nums1[i], b = nums2[i];
            f[i][a + s2]++;
            f[i][-b + s2]++;
            if (i) {
                for (int j = 0; j <= s1 + s2; ++j) {
                    if (j >= a) {
                        f[i][j] = (f[i][j] + f[i - 1][j - a]) % mod;
                    }
                    if (j + b <= s1 + s2) {
                        f[i][j] = (f[i][j] + f[i - 1][j + b]) % mod;
                    }
                }
            }
            ans = (ans + f[i][s2]) % mod;
        }
        return ans;
    }
};
```

#### Go

```go
func countSubranges(nums1 []int, nums2 []int) (ans int) {
	n := len(nums1)
	s1, s2 := sum(nums1), sum(nums2)
	f := make([][]int, n)
	for i := range f {
		f[i] = make([]int, s1+s2+1)
	}
	const mod int = 1e9 + 7
	for i, a := range nums1 {
		b := nums2[i]
		f[i][a+s2]++
		f[i][-b+s2]++
		if i > 0 {
			for j := 0; j <= s1+s2; j++ {
				if j >= a {
					f[i][j] = (f[i][j] + f[i-1][j-a]) % mod
				}
				if j+b <= s1+s2 {
					f[i][j] = (f[i][j] + f[i-1][j+b]) % mod
				}
			}
		}
		ans = (ans + f[i][s2]) % mod
	}
	return
}

func sum(nums []int) (ans int) {
	for _, x := range nums {
		ans += x
	}
	return
}
```

#### TypeScript

```ts
function countSubranges(nums1: number[], nums2: number[]): number {
    const n = nums1.length;
    const s1 = nums1.reduce((a, b) => a + b, 0);
    const s2 = nums2.reduce((a, b) => a + b, 0);
    const f: number[][] = Array(n)
        .fill(0)
        .map(() => Array(s1 + s2 + 1).fill(0));
    const mod = 1e9 + 7;
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        const [a, b] = [nums1[i], nums2[i]];
        f[i][a + s2]++;
        f[i][-b + s2]++;
        if (i) {
            for (let j = 0; j <= s1 + s2; ++j) {
                if (j >= a) {
                    f[i][j] = (f[i][j] + f[i - 1][j - a]) % mod;
                }
                if (j + b <= s1 + s2) {
                    f[i][j] = (f[i][j] + f[i - 1][j + b]) % mod;
                }
            }
        }
        ans = (ans + f[i][s2]) % mod;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2144. 打折购买糖果的最小开销](https://leetcode.cn/problems/minimum-cost-of-buying-candies-with-discount){#2144}

{{< tabs "2144" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumCost(self, cost: List[int]) -> int:
        cost.sort(reverse=True)
        return sum(cost) - sum(cost[2::3])
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumCost(int[] cost) {
        Arrays.sort(cost);
        int ans = 0;
        for (int i = cost.length - 1; i >= 0; i -= 3) {
            ans += cost[i];
            if (i > 0) {
                ans += cost[i - 1];
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
    int minimumCost(vector<int>& cost) {
        sort(cost.rbegin(), cost.rend());
        int ans = 0;
        for (int i = 0; i < cost.size(); i += 3) {
            ans += cost[i];
            if (i < cost.size() - 1) {
                ans += cost[i + 1];
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumCost(cost []int) (ans int) {
	sort.Ints(cost)
	for i := len(cost) - 1; i >= 0; i -= 3 {
		ans += cost[i]
		if i > 0 {
			ans += cost[i-1]
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumCost(cost: number[]): number {
    cost.sort((a, b) => a - b);
    let ans = 0;
    for (let i = cost.length - 1; i >= 0; i -= 3) {
        ans += cost[i];
        if (i) {
            ans += cost[i - 1];
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

<p>一家商店正在打折销售糖果。每购买 <strong>两个</strong>&nbsp;糖果，商店会 <strong>免费</strong>&nbsp;送一个糖果。</p>

<p>免费送的糖果唯一的限制是：它的价格需要小于等于购买的两个糖果价格的 <strong>较小值</strong>&nbsp;。</p>

<ul>
	<li>比方说，总共有 <code>4</code>&nbsp;个糖果，价格分别为&nbsp;<code>1</code>&nbsp;，<code>2</code>&nbsp;，<code>3</code>&nbsp;和&nbsp;<code>4</code>&nbsp;，一位顾客买了价格为&nbsp;<code>2</code> 和&nbsp;<code>3</code>&nbsp;的糖果，那么他可以免费获得价格为 <code>1</code>&nbsp;的糖果，但不能获得价格为&nbsp;<code>4</code>&nbsp;的糖果。</li>
</ul>

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>cost</code>&nbsp;，其中&nbsp;<code>cost[i]</code>&nbsp;表示第&nbsp;<code>i</code>&nbsp;个糖果的价格，请你返回获得 <strong>所有</strong>&nbsp;糖果的 <strong>最小</strong>&nbsp;总开销。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>cost = [1,2,3]
<b>输出：</b>5
<b>解释：</b>我们购买价格为 2 和 3 的糖果，然后免费获得价格为 1 的糖果。
总开销为 2 + 3 = 5 。这是开销最小的 <strong>唯一</strong>&nbsp;方案。
注意，我们不能购买价格为 1 和 3 的糖果，并免费获得价格为 2 的糖果。
这是因为免费糖果的价格必须小于等于购买的 2 个糖果价格的较小值。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>cost = [6,5,7,9,2,2]
<b>输出：</b>23
<b>解释：</b>最小总开销购买糖果方案为：
- 购买价格为 9 和 7 的糖果
- 免费获得价格为 6 的糖果
- 购买价格为 5 和 2 的糖果
- 免费获得价格为 2 的最后一个糖果
因此，最小总开销为 9 + 7 + 5 + 2 = 23 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>cost = [5,5]
<b>输出：</b>10
<b>解释：</b>由于只有 2 个糖果，我们需要将它们都购买，而且没有免费糖果。
所以总最小开销为 5 + 5 = 10 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= cost.length &lt;= 100</code></li>
	<li><code>1 &lt;= cost[i] &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心

我们可以先将糖果按照价格从高到低排序，然后每三个糖果中取两个糖果，这样可以保证免费获得的糖果价格最高，从而使得总开销最小。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 是糖果数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumCost(self, cost: List[int]) -> int:
        cost.sort(reverse=True)
        return sum(cost) - sum(cost[2::3])
```

#### Java

```java
class Solution {
    public int minimumCost(int[] cost) {
        Arrays.sort(cost);
        int ans = 0;
        for (int i = cost.length - 1; i >= 0; i -= 3) {
            ans += cost[i];
            if (i > 0) {
                ans += cost[i - 1];
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
    int minimumCost(vector<int>& cost) {
        sort(cost.rbegin(), cost.rend());
        int ans = 0;
        for (int i = 0; i < cost.size(); i += 3) {
            ans += cost[i];
            if (i < cost.size() - 1) {
                ans += cost[i + 1];
            }
        }
        return ans;
    }
};
```

#### Go

```go
func minimumCost(cost []int) (ans int) {
	sort.Ints(cost)
	for i := len(cost) - 1; i >= 0; i -= 3 {
		ans += cost[i]
		if i > 0 {
			ans += cost[i-1]
		}
	}
	return
}
```

#### TypeScript

```ts
function minimumCost(cost: number[]): number {
    cost.sort((a, b) => a - b);
    let ans = 0;
    for (let i = cost.length - 1; i >= 0; i -= 3) {
        ans += cost[i];
        if (i) {
            ans += cost[i - 1];
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

# [2145. 统计隐藏数组数目](https://leetcode.cn/problems/count-the-hidden-sequences){#2145}

{{< tabs "2145" >}}

{{% tab "python" %}}
```python
class Solution:
    def numberOfArrays(self, differences: List[int], lower: int, upper: int) -> int:
        x = mi = mx = 0
        for d in differences:
            x += d
            mi = min(mi, x)
            mx = max(mx, x)
        return max(upper - lower - (mx - mi) + 1, 0)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numberOfArrays(int[] differences, int lower, int upper) {
        long x = 0, mi = 0, mx = 0;
        for (int d : differences) {
            x += d;
            mi = Math.min(mi, x);
            mx = Math.max(mx, x);
        }
        return (int) Math.max(upper - lower - (mx - mi) + 1, 0);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long x = 0, mi = 0, mx = 0;
        for (int d : differences) {
            x += d;
            mi = min(mi, x);
            mx = max(mx, x);
        }
        return max(upper - lower - (mx - mi) + 1, 0LL);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numberOfArrays(differences []int, lower int, upper int) int {
	x, mi, mx := 0, 0, 0
	for _, d := range differences {
		x += d
		mi = min(mi, x)
		mx = max(mx, x)
	}
	return max(0, upper-lower-(mx-mi)+1)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numberOfArrays(differences: number[], lower: number, upper: number): number {
    let [x, mi, mx] = [0, 0, 0];
    for (const d of differences) {
        x += d;
        mi = Math.min(mi, x);
        mx = Math.max(mx, x);
    }
    return Math.max(0, upper - lower - (mx - mi) + 1);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong>&nbsp;开始且长度为 <code>n</code>&nbsp;的整数数组&nbsp;<code>differences</code>&nbsp;，它表示一个长度为&nbsp;<code>n + 1</code>&nbsp;的&nbsp;<strong>隐藏</strong>&nbsp;数组&nbsp;<strong>相邻</strong>&nbsp;元素之间的&nbsp;<strong>差值</strong>&nbsp;。更正式的表述为：我们将隐藏数组记作&nbsp;<code>hidden</code>&nbsp;，那么&nbsp;<code>differences[i] = hidden[i + 1] - hidden[i]</code>&nbsp;。</p>

<p>同时给你两个整数&nbsp;<code>lower</code> 和&nbsp;<code>upper</code>&nbsp;，它们表示隐藏数组中所有数字的值都在 <strong>闭</strong>&nbsp;区间&nbsp;<code>[lower, upper]</code>&nbsp;之间。</p>

<ul>
	<li>比方说，<code>differences = [1, -3, 4]</code>&nbsp;，<code>lower = 1</code>&nbsp;，<code>upper = 6</code>&nbsp;，那么隐藏数组是一个长度为 <code>4</code>&nbsp;且所有值都在&nbsp;<code>1</code>&nbsp;和&nbsp;<code>6</code>&nbsp;（包含两者）之间的数组。

    <ul>
    	<li><code>[3, 4, 1, 5]</code> 和&nbsp;<code>[4, 5, 2, 6]</code>&nbsp;都是符合要求的隐藏数组。</li>
    	<li><code>[5, 6, 3, 7]</code>&nbsp;不符合要求，因为它包含大于 <code>6</code>&nbsp;的元素。</li>
    	<li><code>[1, 2, 3, 4]</code>&nbsp;不符合要求，因为相邻元素的差值不符合给定数据。</li>
    </ul>
    </li>

</ul>

<p>请你返回 <strong>符合</strong>&nbsp;要求的隐藏数组的数目。如果没有符合要求的隐藏数组，请返回 <code>0</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>differences = [1,-3,4], lower = 1, upper = 6
<b>输出：</b>2
<b>解释：</b>符合要求的隐藏数组为：
- [3, 4, 1, 5]
- [4, 5, 2, 6]
所以返回 2 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>differences = [3,-4,5,1,-2], lower = -4, upper = 5
<b>输出：</b>4
<b>解释：</b>符合要求的隐藏数组为：
- [-3, 0, -4, 1, 2, 0]
- [-2, 1, -3, 2, 3, 1]
- [-1, 2, -2, 3, 4, 2]
- [0, 3, -1, 4, 5, 3]
所以返回 4 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>differences = [4,-7,2], lower = 3, upper = 6
<b>输出：</b>0
<b>解释：</b>没有符合要求的隐藏数组，所以返回 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == differences.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>5</sup> &lt;= differences[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>5</sup> &lt;= lower &lt;= upper &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前缀和

由于数组 $\textit{differences}$ 已经确定，那么数组 $\textit{hidden}$ 的元素最大值与最小值之差也是固定的，我们只要确保差值不超过 $\textit{upper} - \textit{lower}$ 即可。

我们不妨假设数组 $\textit{hidden}$ 的第一个元素为 $0$，那么 $\textit{hidden}[i] = \textit{hidden}[i - 1] + \textit{differences}[i - 1]$，其中 $1 \leq i \leq n$。记数组 $\textit{hidden}$ 的最大值为 $mx$，最小值为 $mi$，如果 $mx - mi \leq \textit{upper} - \textit{lower}$，那么我们就可以构造出一个合法的 $\textit{hidden}$ 数组，可以构造的个数为 $\textit{upper} - \textit{lower} - (mx - mi) + 1$。否则，无法构造出合法的 $\textit{hidden}$ 数组，返回 $0$。

时间复杂度 $O(n)$，其中 $n$ 是数组 $\textit{differences}$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numberOfArrays(self, differences: List[int], lower: int, upper: int) -> int:
        x = mi = mx = 0
        for d in differences:
            x += d
            mi = min(mi, x)
            mx = max(mx, x)
        return max(upper - lower - (mx - mi) + 1, 0)
```

#### Java

```java
class Solution {
    public int numberOfArrays(int[] differences, int lower, int upper) {
        long x = 0, mi = 0, mx = 0;
        for (int d : differences) {
            x += d;
            mi = Math.min(mi, x);
            mx = Math.max(mx, x);
        }
        return (int) Math.max(upper - lower - (mx - mi) + 1, 0);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long x = 0, mi = 0, mx = 0;
        for (int d : differences) {
            x += d;
            mi = min(mi, x);
            mx = max(mx, x);
        }
        return max(upper - lower - (mx - mi) + 1, 0LL);
    }
};
```

#### Go

```go
func numberOfArrays(differences []int, lower int, upper int) int {
	x, mi, mx := 0, 0, 0
	for _, d := range differences {
		x += d
		mi = min(mi, x)
		mx = max(mx, x)
	}
	return max(0, upper-lower-(mx-mi)+1)
}
```

#### TypeScript

```ts
function numberOfArrays(differences: number[], lower: number, upper: number): number {
    let [x, mi, mx] = [0, 0, 0];
    for (const d of differences) {
        x += d;
        mi = Math.min(mi, x);
        mx = Math.max(mx, x);
    }
    return Math.max(0, upper - lower - (mx - mi) + 1);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2146. 价格范围内最高排名的 K 样物品](https://leetcode.cn/problems/k-highest-ranked-items-within-a-price-range){#2146}

{{< tabs "2146" >}}

{{% tab "python" %}}
```python
class Solution:
    def highestRankedKItems(
        self, grid: List[List[int]], pricing: List[int], start: List[int], k: int
    ) -> List[List[int]]:
        m, n = len(grid), len(grid[0])
        row, col = start
        low, high = pricing
        q = deque([(row, col)])
        pq = []
        if low <= grid[row][col] <= high:
            pq.append((0, grid[row][col], row, col))
        grid[row][col] = 0
        dirs = (-1, 0, 1, 0, -1)
        step = 0
        while q:
            step += 1
            for _ in range(len(q)):
                x, y = q.popleft()
                for a, b in pairwise(dirs):
                    nx, ny = x + a, y + b
                    if 0 <= nx < m and 0 <= ny < n and grid[nx][ny] > 0:
                        if low <= grid[nx][ny] <= high:
                            pq.append((step, grid[nx][ny], nx, ny))
                        grid[nx][ny] = 0
                        q.append((nx, ny))
        pq.sort()
        return [list(x[2:]) for x in pq[:k]]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<List<Integer>> highestRankedKItems(
        int[][] grid, int[] pricing, int[] start, int k) {
        int m = grid.length;
        int n = grid[0].length;
        int row = start[0], col = start[1];
        int low = pricing[0], high = pricing[1];
        Deque<int[]> q = new ArrayDeque<>();
        q.offer(new int[] {row, col});
        List<int[]> pq = new ArrayList<>();
        if (low <= grid[row][col] && grid[row][col] <= high) {
            pq.add(new int[] {0, grid[row][col], row, col});
        }
        grid[row][col] = 0;
        final int[] dirs = {-1, 0, 1, 0, -1};
        for (int step = 1; !q.isEmpty(); ++step) {
            for (int size = q.size(); size > 0; --size) {
                int[] curr = q.poll();
                int x = curr[0], y = curr[1];
                for (int j = 0; j < 4; j++) {
                    int nx = x + dirs[j];
                    int ny = y + dirs[j + 1];
                    if (0 <= nx && nx < m && 0 <= ny && ny < n && grid[nx][ny] > 0) {
                        if (low <= grid[nx][ny] && grid[nx][ny] <= high) {
                            pq.add(new int[] {step, grid[nx][ny], nx, ny});
                        }
                        grid[nx][ny] = 0;
                        q.offer(new int[] {nx, ny});
                    }
                }
            }
        }

        pq.sort((a, b) -> {
            if (a[0] != b[0]) return Integer.compare(a[0], b[0]);
            if (a[1] != b[1]) return Integer.compare(a[1], b[1]);
            if (a[2] != b[2]) return Integer.compare(a[2], b[2]);
            return Integer.compare(a[3], b[3]);
        });

        List<List<Integer>> ans = new ArrayList<>();
        for (int i = 0; i < Math.min(k, pq.size()); i++) {
            ans.add(List.of(pq.get(i)[2], pq.get(i)[3]));
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
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        int m = grid.size(), n = grid[0].size();
        int row = start[0], col = start[1];
        int low = pricing[0], high = pricing[1];
        queue<pair<int, int>> q;
        q.push({row, col});
        vector<tuple<int, int, int, int>> pq;
        if (low <= grid[row][col] && grid[row][col] <= high) {
            pq.push_back({0, grid[row][col], row, col});
        }
        grid[row][col] = 0;
        vector<int> dirs = {-1, 0, 1, 0, -1};
        for (int step = 1; q.size(); ++step) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                auto [x, y] = q.front();
                q.pop();
                for (int j = 0; j < 4; ++j) {
                    int nx = x + dirs[j];
                    int ny = y + dirs[j + 1];
                    if (0 <= nx && nx < m && 0 <= ny && ny < n && grid[nx][ny] > 0) {
                        if (low <= grid[nx][ny] && grid[nx][ny] <= high) {
                            pq.push_back({step, grid[nx][ny], nx, ny});
                        }
                        grid[nx][ny] = 0;
                        q.push({nx, ny});
                    }
                }
            }
        }
        sort(pq.begin(), pq.end());
        vector<vector<int>> ans;
        for (int i = 0; i < min(k, (int) pq.size()); ++i) {
            ans.push_back({get<2>(pq[i]), get<3>(pq[i])});
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func highestRankedKItems(grid [][]int, pricing []int, start []int, k int) (ans [][]int) {
	m, n := len(grid), len(grid[0])
	row, col := start[0], start[1]
	low, high := pricing[0], pricing[1]
	q := [][2]int{{row, col}}
	pq := [][]int{}
	if low <= grid[row][col] && grid[row][col] <= high {
		pq = append(pq, []int{0, grid[row][col], row, col})
	}
	grid[row][col] = 0
	dirs := [5]int{-1, 0, 1, 0, -1}
	for step := 1; len(q) > 0; step++ {
		for sz := len(q); sz > 0; sz-- {
			x, y := q[0][0], q[0][1]
			q = q[1:]
			for j := 0; j < 4; j++ {
				nx, ny := x+dirs[j], y+dirs[j+1]
				if nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] > 0 {
					if low <= grid[nx][ny] && grid[nx][ny] <= high {
						pq = append(pq, []int{step, grid[nx][ny], nx, ny})
					}
					grid[nx][ny] = 0
					q = append(q, [2]int{nx, ny})
				}
			}
		}
	}
	sort.Slice(pq, func(i, j int) bool {
		a, b := pq[i], pq[j]
		if a[0] != b[0] {
			return a[0] < b[0]
		}
		if a[1] != b[1] {
			return a[1] < b[1]
		}
		if a[2] != b[2] {
			return a[2] < b[2]
		}
		return a[3] < b[3]
	})
	for i := 0; i < len(pq) && i < k; i++ {
		ans = append(ans, pq[i][2:])
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function highestRankedKItems(
    grid: number[][],
    pricing: number[],
    start: number[],
    k: number,
): number[][] {
    const [m, n] = [grid.length, grid[0].length];
    const [row, col] = start;
    const [low, high] = pricing;
    let q: [number, number][] = [[row, col]];
    const pq: [number, number, number, number][] = [];
    if (low <= grid[row][col] && grid[row][col] <= high) {
        pq.push([0, grid[row][col], row, col]);
    }
    grid[row][col] = 0;
    const dirs = [-1, 0, 1, 0, -1];
    for (let step = 1; q.length > 0; ++step) {
        const nq: [number, number][] = [];
        for (const [x, y] of q) {
            for (let j = 0; j < 4; j++) {
                const nx = x + dirs[j];
                const ny = y + dirs[j + 1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] > 0) {
                    if (low <= grid[nx][ny] && grid[nx][ny] <= high) {
                        pq.push([step, grid[nx][ny], nx, ny]);
                    }
                    grid[nx][ny] = 0;
                    nq.push([nx, ny]);
                }
            }
        }
        q = nq;
    }
    pq.sort((a, b) => {
        if (a[0] !== b[0]) return a[0] - b[0];
        if (a[1] !== b[1]) return a[1] - b[1];
        if (a[2] !== b[2]) return a[2] - b[2];
        return a[3] - b[3];
    });
    const ans: number[][] = [];
    for (let i = 0; i < Math.min(k, pq.length); i++) {
        ans.push([pq[i][2], pq[i][3]]);
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

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的二维整数数组&nbsp;<code>grid</code>&nbsp;，它的大小为&nbsp;<code>m x n</code>&nbsp;，表示一个商店中物品的分布图。数组中的整数含义为：</p>

<ul>
	<li><code>0</code>&nbsp;表示无法穿越的一堵墙。</li>
	<li><code>1</code>&nbsp;表示可以自由通过的一个空格子。</li>
	<li>所有其他正整数表示该格子内的一样物品的价格。你可以自由经过这些格子。</li>
</ul>

<p>从一个格子走到上下左右相邻格子花费&nbsp;<code>1</code>&nbsp;步。</p>

<p>同时给你一个整数数组&nbsp;<code>pricing</code> 和&nbsp;<code>start</code>&nbsp;，其中&nbsp;<code>pricing = [low, high]</code> 且&nbsp;<code>start = [row, col]</code>&nbsp;，表示你开始位置为&nbsp;<code>(row, col)</code>&nbsp;，同时你只对物品价格在<strong>&nbsp;闭区间</strong>&nbsp;<code>[low, high]</code>&nbsp;之内的物品感兴趣。同时给你一个整数&nbsp;<code>k</code>&nbsp;。</p>

<p>你想知道给定范围 <strong>内</strong>&nbsp;且 <strong>排名最高</strong>&nbsp;的 <code>k</code>&nbsp;件物品的 <strong>位置</strong>&nbsp;。排名按照优先级从高到低的以下规则制定：</p>

<ol>
	<li>距离：定义为从&nbsp;<code>start</code>&nbsp;到一件物品的最短路径需要的步数（<strong>较近</strong>&nbsp;距离的排名更高）。</li>
	<li>价格：<strong>较低</strong>&nbsp;价格的物品有更高优先级，但只考虑在给定范围之内的价格。</li>
	<li>行坐标：<strong>较小</strong>&nbsp;行坐标的有更高优先级。</li>
	<li>列坐标：<strong>较小</strong>&nbsp;列坐标的有更高优先级。</li>
</ol>

<p>请你返回给定价格内排名最高的 <code>k</code>&nbsp;件物品的坐标，将它们按照排名排序后返回。如果给定价格内少于 <code>k</code>&nbsp;件物品，那么请将它们的坐标&nbsp;<strong>全部</strong>&nbsp;返回。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2100-2199/2146.K%20Highest%20Ranked%20Items%20Within%20a%20Price%20Range/images/example1drawio.png" style="width: 200px; height: 151px;"></p>

<pre><b>输入：</b>grid = [[1,2,0,1],[1,3,0,1],[0,2,5,1]], pricing = [2,5], start = [0,0], k = 3
<b>输出：</b>[[0,1],[1,1],[2,1]]
<b>解释：</b>起点为 (0,0) 。
价格范围为 [2,5] ，我们可以选择的物品坐标为 (0,1)，(1,1)，(2,1) 和 (2,2) 。
这些物品的排名为：
- (0,1) 距离为 1
- (1,1) 距离为 2
- (2,1) 距离为 3
- (2,2) 距离为 4
所以，给定价格范围内排名最高的 3 件物品的坐标为 (0,1)，(1,1) 和 (2,1) 。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2100-2199/2146.K%20Highest%20Ranked%20Items%20Within%20a%20Price%20Range/images/example2drawio1.png" style="width: 200px; height: 151px;"></p>

<pre><b>输入：</b>grid = [[1,2,0,1],[1,3,3,1],[0,2,5,1]], pricing = [2,3], start = [2,3], k = 2
<b>输出：</b>[[2,1],[1,2]]
<b>解释：</b>起点为 (2,3) 。
价格范围为 [2,3] ，我们可以选择的物品坐标为 (0,1)，(1,1)，(1,2) 和 (2,1) 。
这些物品的排名为： 
- (2,1) 距离为 2 ，价格为 2
- (1,2) 距离为 2 ，价格为 3
- (1,1) 距离为 3
- (0,1) 距离为 4
所以，给定价格范围内排名最高的 2 件物品的坐标为 (2,1) 和 (1,2) 。
</pre>

<p><strong>示例 3：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2100-2199/2146.K%20Highest%20Ranked%20Items%20Within%20a%20Price%20Range/images/example3.png" style="width: 149px; height: 150px;"></p>

<pre><b>输入：</b>grid = [[1,1,1],[0,0,1],[2,3,4]], pricing = [2,3], start = [0,0], k = 3
<b>输出：</b>[[2,1],[2,0]]
<b>解释：</b>起点为 (0,0) 。
价格范围为 [2,3] ，我们可以选择的物品坐标为 (2,0) 和 (2,1) 。
这些物品的排名为：
- (2,1) 距离为 5
- (2,0) 距离为 6
所以，给定价格范围内排名最高的 2 件物品的坐标为 (2,1) 和 (2,0) 。
注意，k = 3 但给定价格范围内只有 2 件物品。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= m * n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= grid[i][j] &lt;= 10<sup>5</sup></code></li>
	<li><code>pricing.length == 2</code></li>
	<li><code>2 &lt;= low &lt;= high &lt;= 10<sup>5</sup></code></li>
	<li><code>start.length == 2</code></li>
	<li><code>0 &lt;= row &lt;= m - 1</code></li>
	<li><code>0 &lt;= col &lt;= n - 1</code></li>
	<li><code>grid[row][col] &gt; 0</code></li>
	<li><code>1 &lt;= k &lt;= m * n</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：BFS + 排序

我们可以从 $(\textit{row}, \textit{col})$ 出发，使用广度优先搜索找到所有价格在 $[\textit{low}, \textit{high}]$ 范围内的物品，将这些物品的距离、价格、行坐标和列坐标存入数组 $\textit{pq}$ 中。

最后对 $\textit{pq}$ 按照距离、价格、行坐标和列坐标的顺序排序，取前 $k$ 个物品的坐标返回。

时间复杂度 $O(m \times n \times \log (m \times n))$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别是二维数组 $\textit{grid}$ 的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def highestRankedKItems(
        self, grid: List[List[int]], pricing: List[int], start: List[int], k: int
    ) -> List[List[int]]:
        m, n = len(grid), len(grid[0])
        row, col = start
        low, high = pricing
        q = deque([(row, col)])
        pq = []
        if low <= grid[row][col] <= high:
            pq.append((0, grid[row][col], row, col))
        grid[row][col] = 0
        dirs = (-1, 0, 1, 0, -1)
        step = 0
        while q:
            step += 1
            for _ in range(len(q)):
                x, y = q.popleft()
                for a, b in pairwise(dirs):
                    nx, ny = x + a, y + b
                    if 0 <= nx < m and 0 <= ny < n and grid[nx][ny] > 0:
                        if low <= grid[nx][ny] <= high:
                            pq.append((step, grid[nx][ny], nx, ny))
                        grid[nx][ny] = 0
                        q.append((nx, ny))
        pq.sort()
        return [list(x[2:]) for x in pq[:k]]
```

#### Java

```java
class Solution {
    public List<List<Integer>> highestRankedKItems(
        int[][] grid, int[] pricing, int[] start, int k) {
        int m = grid.length;
        int n = grid[0].length;
        int row = start[0], col = start[1];
        int low = pricing[0], high = pricing[1];
        Deque<int[]> q = new ArrayDeque<>();
        q.offer(new int[] {row, col});
        List<int[]> pq = new ArrayList<>();
        if (low <= grid[row][col] && grid[row][col] <= high) {
            pq.add(new int[] {0, grid[row][col], row, col});
        }
        grid[row][col] = 0;
        final int[] dirs = {-1, 0, 1, 0, -1};
        for (int step = 1; !q.isEmpty(); ++step) {
            for (int size = q.size(); size > 0; --size) {
                int[] curr = q.poll();
                int x = curr[0], y = curr[1];
                for (int j = 0; j < 4; j++) {
                    int nx = x + dirs[j];
                    int ny = y + dirs[j + 1];
                    if (0 <= nx && nx < m && 0 <= ny && ny < n && grid[nx][ny] > 0) {
                        if (low <= grid[nx][ny] && grid[nx][ny] <= high) {
                            pq.add(new int[] {step, grid[nx][ny], nx, ny});
                        }
                        grid[nx][ny] = 0;
                        q.offer(new int[] {nx, ny});
                    }
                }
            }
        }

        pq.sort((a, b) -> {
            if (a[0] != b[0]) return Integer.compare(a[0], b[0]);
            if (a[1] != b[1]) return Integer.compare(a[1], b[1]);
            if (a[2] != b[2]) return Integer.compare(a[2], b[2]);
            return Integer.compare(a[3], b[3]);
        });

        List<List<Integer>> ans = new ArrayList<>();
        for (int i = 0; i < Math.min(k, pq.size()); i++) {
            ans.add(List.of(pq.get(i)[2], pq.get(i)[3]));
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        int m = grid.size(), n = grid[0].size();
        int row = start[0], col = start[1];
        int low = pricing[0], high = pricing[1];
        queue<pair<int, int>> q;
        q.push({row, col});
        vector<tuple<int, int, int, int>> pq;
        if (low <= grid[row][col] && grid[row][col] <= high) {
            pq.push_back({0, grid[row][col], row, col});
        }
        grid[row][col] = 0;
        vector<int> dirs = {-1, 0, 1, 0, -1};
        for (int step = 1; q.size(); ++step) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                auto [x, y] = q.front();
                q.pop();
                for (int j = 0; j < 4; ++j) {
                    int nx = x + dirs[j];
                    int ny = y + dirs[j + 1];
                    if (0 <= nx && nx < m && 0 <= ny && ny < n && grid[nx][ny] > 0) {
                        if (low <= grid[nx][ny] && grid[nx][ny] <= high) {
                            pq.push_back({step, grid[nx][ny], nx, ny});
                        }
                        grid[nx][ny] = 0;
                        q.push({nx, ny});
                    }
                }
            }
        }
        sort(pq.begin(), pq.end());
        vector<vector<int>> ans;
        for (int i = 0; i < min(k, (int) pq.size()); ++i) {
            ans.push_back({get<2>(pq[i]), get<3>(pq[i])});
        }
        return ans;
    }
};
```

#### Go

```go
func highestRankedKItems(grid [][]int, pricing []int, start []int, k int) (ans [][]int) {
	m, n := len(grid), len(grid[0])
	row, col := start[0], start[1]
	low, high := pricing[0], pricing[1]
	q := [][2]int{{row, col}}
	pq := [][]int{}
	if low <= grid[row][col] && grid[row][col] <= high {
		pq = append(pq, []int{0, grid[row][col], row, col})
	}
	grid[row][col] = 0
	dirs := [5]int{-1, 0, 1, 0, -1}
	for step := 1; len(q) > 0; step++ {
		for sz := len(q); sz > 0; sz-- {
			x, y := q[0][0], q[0][1]
			q = q[1:]
			for j := 0; j < 4; j++ {
				nx, ny := x+dirs[j], y+dirs[j+1]
				if nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] > 0 {
					if low <= grid[nx][ny] && grid[nx][ny] <= high {
						pq = append(pq, []int{step, grid[nx][ny], nx, ny})
					}
					grid[nx][ny] = 0
					q = append(q, [2]int{nx, ny})
				}
			}
		}
	}
	sort.Slice(pq, func(i, j int) bool {
		a, b := pq[i], pq[j]
		if a[0] != b[0] {
			return a[0] < b[0]
		}
		if a[1] != b[1] {
			return a[1] < b[1]
		}
		if a[2] != b[2] {
			return a[2] < b[2]
		}
		return a[3] < b[3]
	})
	for i := 0; i < len(pq) && i < k; i++ {
		ans = append(ans, pq[i][2:])
	}
	return
}
```

#### TypeScript

```ts
function highestRankedKItems(
    grid: number[][],
    pricing: number[],
    start: number[],
    k: number,
): number[][] {
    const [m, n] = [grid.length, grid[0].length];
    const [row, col] = start;
    const [low, high] = pricing;
    let q: [number, number][] = [[row, col]];
    const pq: [number, number, number, number][] = [];
    if (low <= grid[row][col] && grid[row][col] <= high) {
        pq.push([0, grid[row][col], row, col]);
    }
    grid[row][col] = 0;
    const dirs = [-1, 0, 1, 0, -1];
    for (let step = 1; q.length > 0; ++step) {
        const nq: [number, number][] = [];
        for (const [x, y] of q) {
            for (let j = 0; j < 4; j++) {
                const nx = x + dirs[j];
                const ny = y + dirs[j + 1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] > 0) {
                    if (low <= grid[nx][ny] && grid[nx][ny] <= high) {
                        pq.push([step, grid[nx][ny], nx, ny]);
                    }
                    grid[nx][ny] = 0;
                    nq.push([nx, ny]);
                }
            }
        }
        q = nq;
    }
    pq.sort((a, b) => {
        if (a[0] !== b[0]) return a[0] - b[0];
        if (a[1] !== b[1]) return a[1] - b[1];
        if (a[2] !== b[2]) return a[2] - b[2];
        return a[3] - b[3];
    });
    const ans: number[][] = [];
    for (let i = 0; i < Math.min(k, pq.length); i++) {
        ans.push([pq[i][2], pq[i][3]]);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2147. 分隔长廊的方案数](https://leetcode.cn/problems/number-of-ways-to-divide-a-long-corridor){#2147}

{{< tabs "2147" >}}

{{% tab "python" %}}
```python
class Solution:
    def numberOfWays(self, corridor: str) -> int:
        mod = 10**9 + 7
        ans, cnt, last = 1, 0, 0
        for i, c in enumerate(corridor):
            if c == "S":
                cnt += 1
                if cnt > 2 and cnt % 2:
                    ans = ans * (i - last) % mod
                last = i
        return ans if cnt and cnt % 2 == 0 else 0
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numberOfWays(String corridor) {
        final int mod = (int) 1e9 + 7;
        long ans = 1, cnt = 0, last = 0;
        for (int i = 0; i < corridor.length(); ++i) {
            if (corridor.charAt(i) == 'S') {
                if (++cnt > 2 && cnt % 2 == 1) {
                    ans = ans * (i - last) % mod;
                }
                last = i;
            }
        }
        return cnt > 0 && cnt % 2 == 0 ? (int) ans : 0;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int numberOfWays(string corridor) {
        const int mod = 1e9 + 7;
        long long ans = 1;
        int cnt = 0, last = 0;
        for (int i = 0; i < corridor.length(); ++i) {
            if (corridor[i] == 'S') {
                if (++cnt > 2 && cnt % 2) {
                    ans = ans * (i - last) % mod;
                }
                last = i;
            }
        }
        return cnt > 0 && cnt % 2 == 0 ? ans : 0;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numberOfWays(corridor string) int {
	const mod int = 1e9 + 7
	ans, cnt, last := 1, 0, 0
	for i, c := range corridor {
		if c == 'S' {
			cnt++
			if cnt > 2 && cnt%2 == 1 {
				ans = ans * (i - last) % mod
			}
			last = i
		}
	}
	if cnt > 0 && cnt%2 == 0 {
		return ans
	}
	return 0
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numberOfWays(corridor: string): number {
    const mod = 10 ** 9 + 7;
    const n = corridor.length;
    let [ans, cnt, last] = [1, 0, 0];
    for (let i = 0; i < n; ++i) {
        if (corridor[i] === 'S') {
            if (++cnt > 2 && cnt % 2) {
                ans = (ans * (i - last)) % mod;
            }
            last = i;
        }
    }
    return cnt > 0 && cnt % 2 === 0 ? ans : 0;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>在一个图书馆的长廊里，有一些座位和装饰植物排成一列。给你一个下标从 <strong>0</strong>&nbsp;开始，长度为 <code>n</code>&nbsp;的字符串&nbsp;<code>corridor</code>&nbsp;，它包含字母&nbsp;<code>'S'</code> 和&nbsp;<code>'P'</code>&nbsp;，其中每个&nbsp;<code>'S'</code>&nbsp;表示一个座位，每个&nbsp;<code>'P'</code>&nbsp;表示一株植物。</p>

<p>在下标 <code>0</code>&nbsp;的左边和下标 <code>n - 1</code>&nbsp;的右边 <strong>已经</strong>&nbsp;分别各放了一个屏风。你还需要额外放置一些屏风。每一个位置&nbsp;<code>i - 1</code> 和&nbsp;<code>i</code>&nbsp;之间（<code>1 &lt;= i &lt;= n - 1</code>），至多能放一个屏风。</p>

<p>请你将走廊用屏风划分为若干段，且每一段内都 <strong>恰好有两个座位</strong>&nbsp;，而每一段内植物的数目没有要求。可能有多种划分方案，如果两个方案中有任何一个屏风的位置不同，那么它们被视为 <strong>不同</strong> 方案。</p>

<p>请你返回划分走廊的方案数。由于答案可能很大，请你返回它对&nbsp;<code>10<sup>9</sup> + 7</code>&nbsp;<strong>取余</strong>&nbsp;的结果。如果没有任何方案，请返回&nbsp;<code>0</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2100-2199/2147.Number%20of%20Ways%20to%20Divide%20a%20Long%20Corridor/images/1.png" style="width: 410px; height: 199px;"></p>

<pre><b>输入：</b>corridor = "SSPPSPS"
<b>输出：</b>3
<b>解释：</b>总共有 3 种不同分隔走廊的方案。
上图中黑色的竖线表示已经放置好的屏风。
上图每种方案中，每一段都恰好有 <strong>两个</strong>&nbsp;座位。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2100-2199/2147.Number%20of%20Ways%20to%20Divide%20a%20Long%20Corridor/images/2.png" style="width: 357px; height: 68px;"></p>

<pre><b>输入：</b>corridor = "PPSPSP"
<b>输出：</b>1
<b>解释：</b>只有 1 种分隔走廊的方案，就是不放置任何屏风。
放置任何的屏风都会导致有一段无法恰好有 2 个座位。
</pre>

<p><strong>示例 3：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2100-2199/2147.Number%20of%20Ways%20to%20Divide%20a%20Long%20Corridor/images/3.png" style="width: 115px; height: 68px;"></p>

<pre><b>输入：</b>corridor = "S"
<b>输出：</b>0
<b>解释：</b>没有任何方案，因为总是有一段无法恰好有 2 个座位。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == corridor.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>corridor[i]</code>&nbsp;要么是&nbsp;<code>'S'</code>&nbsp;，要么是&nbsp;<code>'P'</code> 。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

我们设计一个函数 $\textit{dfs}(i, k)$，表示在走廊的第 $i$ 个位置，已经放置了 $k$ 个屏风的情况下，划分走廊的方案数。那么答案就是 $\textit{dfs}(0, 0)$。

函数 $\textit{dfs}(i, k)$ 的计算过程如下：

如果 $i \geq \textit{len}(\textit{corridor})$，表示已经遍历完了走廊，此时如果 $k = 2$，说明找到了一种划分走廊的方案，返回 $1$，否则返回 $0$；

否则，我们需要考虑当前位置 $i$ 的情况：

-   如果 $\textit{corridor}[i] = \text{'S'}$，表示当前位置是一个座位，我们将 $k$ 加 $1$；
-   如果 $k > 2$，表示当前位置放置的屏风数量超过了 $2$，返回 $0$；
-   否则，我们可以选择不放置屏风，即 $\textit{dfs}(i + 1, k)$；如果 $k = 2$，我们还可以选择放置屏风，即 $\textit{dfs}(i + 1, 0)$；我们将这两种情况的结果相加并取模 $10^9 + 7$，即 $\textit{ans} = (\textit{ans} + \textit{dfs}(i + 1, k)) \bmod \text{mod}$。

最后，我们返回 $\textit{dfs}(0, 0)$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是走廊的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numberOfWays(self, corridor: str) -> int:
        @cache
        def dfs(i: int, k: int) -> int:
            if i >= len(corridor):
                return int(k == 2)
            k += int(corridor[i] == "S")
            if k > 2:
                return 0
            ans = dfs(i + 1, k)
            if k == 2:
                ans = (ans + dfs(i + 1, 0)) % mod
            return ans

        mod = 10**9 + 7
        ans = dfs(0, 0)
        dfs.cache_clear()
        return ans
```

#### Java

```java
class Solution {
    private int n;
    private char[] s;
    private Integer[][] f;
    private final int mod = (int) 1e9 + 7;

    public int numberOfWays(String corridor) {
        s = corridor.toCharArray();
        n = s.length;
        f = new Integer[n][3];
        return dfs(0, 0);
    }

    private int dfs(int i, int k) {
        if (i >= n) {
            return k == 2 ? 1 : 0;
        }
        if (f[i][k] != null) {
            return f[i][k];
        }
        k += s[i] == 'S' ? 1 : 0;
        if (k > 2) {
            return 0;
        }
        int ans = dfs(i + 1, k);
        if (k == 2) {
            ans = (ans + dfs(i + 1, 0)) % mod;
        }
        return f[i][k] = ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numberOfWays(string corridor) {
        int n = corridor.size();
        int f[n][3];
        memset(f, -1, sizeof(f));
        const int mod = 1e9 + 7;
        auto dfs = [&](this auto&& dfs, int i, int k) -> int {
            if (i >= n) {
                return k == 2;
            }
            if (f[i][k] != -1) {
                return f[i][k];
            }
            k += corridor[i] == 'S';
            if (k > 2) {
                return 0;
            }
            f[i][k] = dfs(i + 1, k);
            if (k == 2) {
                f[i][k] = (f[i][k] + dfs(i + 1, 0)) % mod;
            }
            return f[i][k];
        };
        return dfs(0, 0);
    }
};
```

#### Go

```go
func numberOfWays(corridor string) int {
	n := len(corridor)
	f := make([][3]int, n)
	for i := range f {
		f[i] = [3]int{-1, -1, -1}
	}
	const mod = 1e9 + 7
	var dfs func(int, int) int
	dfs = func(i, k int) int {
		if i >= n {
			if k == 2 {
				return 1
			}
			return 0
		}
		if f[i][k] != -1 {
			return f[i][k]
		}
		if corridor[i] == 'S' {
			k++
		}
		if k > 2 {
			return 0
		}
		f[i][k] = dfs(i+1, k)
		if k == 2 {
			f[i][k] = (f[i][k] + dfs(i+1, 0)) % mod
		}
		return f[i][k]
	}
	return dfs(0, 0)
}
```

#### TypeScript

```ts
function numberOfWays(corridor: string): number {
    const n = corridor.length;
    const mod = 10 ** 9 + 7;
    const f: number[][] = Array.from({ length: n }, () => Array(3).fill(-1));
    const dfs = (i: number, k: number): number => {
        if (i >= n) {
            return k === 2 ? 1 : 0;
        }
        if (f[i][k] !== -1) {
            return f[i][k];
        }
        if (corridor[i] === 'S') {
            ++k;
        }
        if (k > 2) {
            return (f[i][k] = 0);
        }
        f[i][k] = dfs(i + 1, k);
        if (k === 2) {
            f[i][k] = (f[i][k] + dfs(i + 1, 0)) % mod;
        }
        return f[i][k];
    };
    return dfs(0, 0);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：数学

我们可以将每两个座位划分为一组。在相邻的两组座位之间，如果前一组的最后一个座位和后一组的第一个座位之间的距离为 $x$，那么就有 $x$ 种放置屏风的方案。

我们遍历走廊，用一个变量 $\textit{cnt}$ 记录当前座位数，用一个变量 $\textit{last}$ 记录上一个座位的位置。

当遍历到一个座位时，我们将 $\textit{cnt}$ 加 $1$，如果 $\textit{cnt}$ 大于 $2$ 且 $\textit{cnt}$ 为奇数，那么我们就需要在 $\textit{last}$ 和当前座位之间放置一个屏风，此时的方案数就是 $\textit{ans} \times (i - \textit{last})$，其中 $\textit{ans}$ 是之前的方案数。然后，我们更新 $\textit{last}$ 为当前座位的位置 $i$。

最后，如果 $\textit{cnt}$ 大于 $0$ 且 $\textit{cnt}$ 为偶数，那么返回 $\textit{ans}$，否则返回 $0$。

时间复杂度 $O(n)$，其中 $n$ 是走廊的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numberOfWays(self, corridor: str) -> int:
        mod = 10**9 + 7
        ans, cnt, last = 1, 0, 0
        for i, c in enumerate(corridor):
            if c == "S":
                cnt += 1
                if cnt > 2 and cnt % 2:
                    ans = ans * (i - last) % mod
                last = i
        return ans if cnt and cnt % 2 == 0 else 0
```

#### Java

```java
class Solution {
    public int numberOfWays(String corridor) {
        final int mod = (int) 1e9 + 7;
        long ans = 1, cnt = 0, last = 0;
        for (int i = 0; i < corridor.length(); ++i) {
            if (corridor.charAt(i) == 'S') {
                if (++cnt > 2 && cnt % 2 == 1) {
                    ans = ans * (i - last) % mod;
                }
                last = i;
            }
        }
        return cnt > 0 && cnt % 2 == 0 ? (int) ans : 0;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numberOfWays(string corridor) {
        const int mod = 1e9 + 7;
        long long ans = 1;
        int cnt = 0, last = 0;
        for (int i = 0; i < corridor.length(); ++i) {
            if (corridor[i] == 'S') {
                if (++cnt > 2 && cnt % 2) {
                    ans = ans * (i - last) % mod;
                }
                last = i;
            }
        }
        return cnt > 0 && cnt % 2 == 0 ? ans : 0;
    }
};
```

#### Go

```go
func numberOfWays(corridor string) int {
	const mod int = 1e9 + 7
	ans, cnt, last := 1, 0, 0
	for i, c := range corridor {
		if c == 'S' {
			cnt++
			if cnt > 2 && cnt%2 == 1 {
				ans = ans * (i - last) % mod
			}
			last = i
		}
	}
	if cnt > 0 && cnt%2 == 0 {
		return ans
	}
	return 0
}
```

#### TypeScript

```ts
function numberOfWays(corridor: string): number {
    const mod = 10 ** 9 + 7;
    const n = corridor.length;
    let [ans, cnt, last] = [1, 0, 0];
    for (let i = 0; i < n; ++i) {
        if (corridor[i] === 'S') {
            if (++cnt > 2 && cnt % 2) {
                ans = (ans * (i - last)) % mod;
            }
            last = i;
        }
    }
    return cnt > 0 && cnt % 2 === 0 ? ans : 0;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2148. 元素计数](https://leetcode.cn/problems/count-elements-with-strictly-smaller-and-greater-elements){#2148}

{{< tabs "2148" >}}

{{% tab "python" %}}
```python
class Solution:
    def countElements(self, nums: List[int]) -> int:
        mi, mx = min(nums), max(nums)
        return sum(mi < x < mx for x in nums)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countElements(int[] nums) {
        int mi = Arrays.stream(nums).min().getAsInt();
        int mx = Arrays.stream(nums).max().getAsInt();
        int ans = 0;
        for (int x : nums) {
            if (mi < x && x < mx) {
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
    int countElements(vector<int>& nums) {
        auto [mi, mx] = ranges::minmax_element(nums);
        return ranges::count_if(nums, [mi, mx](int x) { return *mi < x && x < *mx; });
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countElements(nums []int) (ans int) {
	mi := slices.Min(nums)
	mx := slices.Max(nums)
	for _, x := range nums {
		if mi < x && x < mx {
			ans++
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countElements(nums: number[]): number {
    const mi = Math.min(...nums);
    const mx = Math.max(...nums);
    return nums.filter(x => mi < x && x < mx).length;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>nums</code> ，统计并返回在 <code>nums</code> 中同时至少具有一个严格较小元素和一个严格较大元素的元素数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [11,7,2,15]
<strong>输出：</strong>2
<strong>解释：</strong>元素 7 ：严格较小元素是元素 2 ，严格较大元素是元素 11 。
元素 11 ：严格较小元素是元素 7 ，严格较大元素是元素 15 。
总计有 2 个元素都满足在 nums 中同时存在一个严格较小元素和一个严格较大元素。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [-3,3,3,90]
<strong>输出：</strong>2
<strong>解释：</strong>元素 3 ：严格较小元素是元素 -3 ，严格较大元素是元素 90 。
由于有两个元素的值为 3 ，总计有 2 个元素都满足在 nums 中同时存在一个严格较小元素和一个严格较大元素。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>-10<sup>5</sup> &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：求最小值和最大值

根据题目描述，我们可以先求出数组 $\textit{nums}$ 的最小值 $\textit{mi}$ 和最大值 $\textit{mx}$，然后遍历数组 $\textit{nums}$，统计满足 $\textit{mi} < x < \textit{mx}$ 的元素个数即可。

时间复杂度 $O(n)$，其中 $n$ 是数组 $\textit{nums}$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countElements(self, nums: List[int]) -> int:
        mi, mx = min(nums), max(nums)
        return sum(mi < x < mx for x in nums)
```

#### Java

```java
class Solution {
    public int countElements(int[] nums) {
        int mi = Arrays.stream(nums).min().getAsInt();
        int mx = Arrays.stream(nums).max().getAsInt();
        int ans = 0;
        for (int x : nums) {
            if (mi < x && x < mx) {
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
    int countElements(vector<int>& nums) {
        auto [mi, mx] = ranges::minmax_element(nums);
        return ranges::count_if(nums, [mi, mx](int x) { return *mi < x && x < *mx; });
    }
};
```

#### Go

```go
func countElements(nums []int) (ans int) {
	mi := slices.Min(nums)
	mx := slices.Max(nums)
	for _, x := range nums {
		if mi < x && x < mx {
			ans++
		}
	}
	return
}
```

#### TypeScript

```ts
function countElements(nums: number[]): number {
    const mi = Math.min(...nums);
    const mx = Math.max(...nums);
    return nums.filter(x => mi < x && x < mx).length;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2149. 按符号重排数组](https://leetcode.cn/problems/rearrange-array-elements-by-sign){#2149}

{{< tabs "2149" >}}

{{% tab "python" %}}
```python
class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        ans = [0] * len(nums)
        i, j = 0, 1
        for x in nums:
            if x > 0:
                ans[i] = x
                i += 2
            else:
                ans[j] = x
                j += 2
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] rearrangeArray(int[] nums) {
        int[] ans = new int[nums.length];
        int i = 0, j = 1;
        for (int x : nums) {
            if (x > 0) {
                ans[i] = x;
                i += 2;
            } else {
                ans[j] = x;
                j += 2;
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
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        int i = 0, j = 1;
        for (int x : nums) {
            if (x > 0) {
                ans[i] = x;
                i += 2;
            } else {
                ans[j] = x;
                j += 2;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func rearrangeArray(nums []int) []int {
	ans := make([]int, len(nums))
	i, j := 0, 1
	for _, x := range nums {
		if x > 0 {
			ans[i] = x
			i += 2
		} else {
			ans[j] = x
			j += 2
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function rearrangeArray(nums: number[]): number[] {
    const ans: number[] = Array(nums.length);
    let [i, j] = [0, 1];
    for (const x of nums) {
        if (x > 0) {
            ans[i] = x;
            i += 2;
        } else {
            ans[j] = x;
            j += 2;
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

<p>给你一个下标从 <strong>0</strong> 开始的整数数组 <code>nums</code> ，数组长度为 <strong>偶数</strong> ，由数目 <strong>相等</strong> 的正整数和负整数组成。</p>

<p>你需要返回满足下述条件的数组&nbsp;<code>nums</code>：</p>

<ol>
	<li>任意&nbsp;<strong>连续</strong> 的两个整数 <strong>符号相反</strong></li>
	<li>对于符号相同的所有整数，<strong>保留</strong> 它们在 <code>nums</code> 中的 <strong>顺序</strong> 。</li>
	<li>重排后数组以正整数开头。</li>
</ol>

<p>重排元素满足上述条件后，返回修改后的数组。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [3,1,-2,-5,2,-4]
<strong>输出：</strong>[3,-2,1,-5,2,-4]
<strong>解释：</strong>
nums 中的正整数是 [3,1,2] ，负整数是 [-2,-5,-4] 。
重排的唯一可行方案是 [3,-2,1,-5,2,-4]，能满足所有条件。
像 [1,-2,2,-5,3,-4]、[3,1,2,-2,-5,-4]、[-2,3,-5,1,-4,2] 这样的其他方案是不正确的，因为不满足一个或者多个条件。 
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [-1,1]
<strong>输出：</strong>[1,-1]
<strong>解释：</strong>
1 是 nums 中唯一一个正整数，-1 是 nums 中唯一一个负整数。
所以 nums 重排为 [1,-1] 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 2 * 10<sup>5</sup></code></li>
	<li><code>nums.length</code> 是 <strong>偶数</strong></li>
	<li><code>1 &lt;= |nums[i]| &lt;= 10<sup>5</sup></code></li>
	<li><code>nums</code> 由 <strong>相等</strong> 数量的正整数和负整数组成</li>
</ul>

<p>&nbsp;</p>

<p>不需要原地进行修改。</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双指针

我们先创建一个长度为 $n$ 的数组 $\textit{ans}$，然后使用两个指针 $i$ 和 $j$ 分别指向 $\textit{ans}$ 的偶数下标和奇数下标，初始时 $i = 0$, $j = 1$。

遍历数组 $\textit{nums}$，如果当前元素 $x$ 为正整数，则将 $x$ 放入 $\textit{ans}[i]$，并将 $i$ 增加 $2$；否则将 $x$ 放入 $\textit{ans}[j]$，并将 $j$ 增加 $2$。

最后返回 $\textit{ans}$ 即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $\textit{nums}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        ans = [0] * len(nums)
        i, j = 0, 1
        for x in nums:
            if x > 0:
                ans[i] = x
                i += 2
            else:
                ans[j] = x
                j += 2
        return ans
```

#### Java

```java
class Solution {
    public int[] rearrangeArray(int[] nums) {
        int[] ans = new int[nums.length];
        int i = 0, j = 1;
        for (int x : nums) {
            if (x > 0) {
                ans[i] = x;
                i += 2;
            } else {
                ans[j] = x;
                j += 2;
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
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        int i = 0, j = 1;
        for (int x : nums) {
            if (x > 0) {
                ans[i] = x;
                i += 2;
            } else {
                ans[j] = x;
                j += 2;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func rearrangeArray(nums []int) []int {
	ans := make([]int, len(nums))
	i, j := 0, 1
	for _, x := range nums {
		if x > 0 {
			ans[i] = x
			i += 2
		} else {
			ans[j] = x
			j += 2
		}
	}
	return ans
}
```

#### TypeScript

```ts
function rearrangeArray(nums: number[]): number[] {
    const ans: number[] = Array(nums.length);
    let [i, j] = [0, 1];
    for (const x of nums) {
        if (x > 0) {
            ans[i] = x;
            i += 2;
        } else {
            ans[j] = x;
            j += 2;
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
