---
title: "1230_抛掷硬币 🔒"
date: 2025-10-08T18:37:06+08:00
weight: 4
tags: [二分查找, 交互, 位运算, 几何, 动态规划, 双指针, 回溯, 字典树, 字符串, 广度优先搜索, 排序, 数学, 数组, 概率与统计, 深度优先搜索, 滑动窗口]
---

{{< markmap >}}
### [1230_抛掷硬币 🔒](#1230)
#### [数组](#1230)
#### [数学](#1230)
#### [动态规划](#1230)
#### [概率与统计](#1230)
### [1231_分享巧克力 🔒](#1231)
#### [数组](#1231)
#### [二分查找](#1231)
### [1232_缀点成线](#1232)
#### [几何](#1232)
#### [数组](#1232)
#### [数学](#1232)
### [1233_删除子文件夹](#1233)
#### [深度优先搜索](#1233)
#### [字典树](#1233)
#### [数组](#1233)
#### [字符串](#1233)
### [1234_替换子串得到平衡字符串](#1234)
#### [字符串](#1234)
#### [滑动窗口](#1234)
### [1235_规划兼职工作](#1235)
#### [数组](#1235)
#### [二分查找](#1235)
#### [动态规划](#1235)
#### [排序](#1235)
### [1236_网络爬虫 🔒](#1236)
#### [深度优先搜索](#1236)
#### [广度优先搜索](#1236)
#### [字符串](#1236)
#### [交互](#1236)
### [1237_找出给定方程的正整数解](#1237)
#### [数学](#1237)
#### [双指针](#1237)
#### [二分查找](#1237)
#### [交互](#1237)
### [1238_循环码排列](#1238)
#### [位运算](#1238)
#### [数学](#1238)
#### [回溯](#1238)
### [1239_串联字符串的最大长度](#1239)
#### [位运算](#1239)
#### [数组](#1239)
#### [字符串](#1239)
#### [回溯](#1239)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1230_抛掷硬币 🔒
___
#### 数组
___
#### 数学
___
#### 动态规划
___
#### 概率与统计
---
### 1231_分享巧克力 🔒
___
#### 数组
___
#### 二分查找
---
### 1232_缀点成线
___
#### 几何
___
#### 数组
___
#### 数学
---
### 1233_删除子文件夹
___
#### 深度优先搜索
___
#### 字典树
___
#### 数组
___
#### 字符串
---
### 1234_替换子串得到平衡字符串
___
#### 字符串
___
#### 滑动窗口
---
### 1235_规划兼职工作
___
#### 数组
___
#### 二分查找
___
#### 动态规划
___
#### 排序
---
### 1236_网络爬虫 🔒
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 字符串
___
#### 交互
---
### 1237_找出给定方程的正整数解
___
#### 数学
___
#### 双指针
___
#### 二分查找
___
#### 交互
---
### 1238_循环码排列
___
#### 位运算
___
#### 数学
___
#### 回溯
---
### 1239_串联字符串的最大长度
___
#### 位运算
___
#### 数组
___
#### 字符串
___
#### 回溯
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 交互 | 位运算 |
| 几何 | 动态规划 | 双指针 |
| 回溯 | 字典树 | 字符串 |
| 广度优先搜索 | 排序 | 数学 |
| 数组 | 概率与统计 | 深度优先搜索 |
| 滑动窗口 |  |  |

# [1230. 抛掷硬币 🔒](https://leetcode.cn/problems/toss-strange-coins){#1230}

{{< tabs "1230" >}}

{{% tab "python" %}}
```python
class Solution:
    def probabilityOfHeads(self, prob: List[float], target: int) -> float:
        f = [0] * (target + 1)
        f[0] = 1
        for p in prob:
            for j in range(target, -1, -1):
                f[j] *= 1 - p
                if j:
                    f[j] += p * f[j - 1]
        return f[target]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public double probabilityOfHeads(double[] prob, int target) {
        double[] f = new double[target + 1];
        f[0] = 1;
        for (double p : prob) {
            for (int j = target; j >= 0; --j) {
                f[j] *= (1 - p);
                if (j > 0) {
                    f[j] += p * f[j - 1];
                }
            }
        }
        return f[target];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        double f[target + 1];
        memset(f, 0, sizeof(f));
        f[0] = 1;
        for (double p : prob) {
            for (int j = target; j >= 0; --j) {
                f[j] *= (1 - p);
                if (j > 0) {
                    f[j] += p * f[j - 1];
                }
            }
        }
        return f[target];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func probabilityOfHeads(prob []float64, target int) float64 {
	f := make([]float64, target+1)
	f[0] = 1
	for _, p := range prob {
		for j := target; j >= 0; j-- {
			f[j] *= (1 - p)
			if j > 0 {
				f[j] += p * f[j-1]
			}
		}
	}
	return f[target]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function probabilityOfHeads(prob: number[], target: number): number {
    const f = new Array(target + 1).fill(0);
    f[0] = 1;
    for (const p of prob) {
        for (let j = target; j >= 0; --j) {
            f[j] *= 1 - p;
            if (j > 0) {
                f[j] += f[j - 1] * p;
            }
        }
    }
    return f[target];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>有一些不规则的硬币。在这些硬币中，<code>prob[i]</code>&nbsp;表示第&nbsp;<code>i</code>&nbsp;枚硬币正面朝上的概率。</p>

<p>请对每一枚硬币抛掷&nbsp;<strong>一次</strong>，然后返回正面朝上的硬币数等于&nbsp;<code>target</code>&nbsp;的概率。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>prob = [0.4], target = 1
<strong>输出：</strong>0.40000
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>prob = [0.5,0.5,0.5,0.5,0.5], target = 0
<strong>输出：</strong>0.03125
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= prob.length &lt;= 1000</code></li>
	<li><code>0 &lt;= prob[i] &lt;= 1</code></li>
	<li><code>0 &lt;= target&nbsp;</code><code>&lt;= prob.length</code></li>
	<li>如果答案与标准答案的误差在&nbsp;<code>10^-5</code>&nbsp;内，则被视为正确答案。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i][j]$ 表示前 $i$ 枚硬币中有 $j$ 枚正面朝上的概率，初始时 $f[0][0]=1$，答案即为 $f[n][target]$。

考虑 $f[i][j]$，其中 $i \geq 1$，如果当前硬币反面朝上，那么 $f[i][j] = (1 - p) \times f[i - 1][j]$；如果当前硬币正面朝上，并且 $j \gt 0$，那么 $f[i][j] = p \times f[i - 1][j - 1]$。因此状态转移方程为：

$$
f[i][j] = \begin{cases}
(1 - p) \times f[i - 1][j], & j = 0 \\
(1 - p) \times f[i - 1][j] + p \times f[i - 1][j - 1], & j \gt 0
\end{cases}
$$

其中 $p$ 表示第 $i$ 枚硬币正面朝上的概率。

我们注意到，状态 $f[i][j]$ 只与状态 $f[i - 1][j]$ 和 $f[i - 1][j - 1]$ 有关，因此，我们可以将二维空间优化为一维空间。

时间复杂度 $O(n \times target)$，空间复杂度 $O(target)$。其中 $n$ 为硬币的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def probabilityOfHeads(self, prob: List[float], target: int) -> float:
        n = len(prob)
        f = [[0] * (target + 1) for _ in range(n + 1)]
        f[0][0] = 1
        for i, p in enumerate(prob, 1):
            for j in range(min(i, target) + 1):
                f[i][j] = (1 - p) * f[i - 1][j]
                if j:
                    f[i][j] += p * f[i - 1][j - 1]
        return f[n][target]
```

#### Java

```java
class Solution {
    public double probabilityOfHeads(double[] prob, int target) {
        int n = prob.length;
        double[][] f = new double[n + 1][target + 1];
        f[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= Math.min(i, target); ++j) {
                f[i][j] = (1 - prob[i - 1]) * f[i - 1][j];
                if (j > 0) {
                    f[i][j] += prob[i - 1] * f[i - 1][j - 1];
                }
            }
        }
        return f[n][target];
    }
}
```

#### C++

```cpp
class Solution {
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        int n = prob.size();
        double f[n + 1][target + 1];
        memset(f, 0, sizeof(f));
        f[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= min(i, target); ++j) {
                f[i][j] = (1 - prob[i - 1]) * f[i - 1][j];
                if (j > 0) {
                    f[i][j] += prob[i - 1] * f[i - 1][j - 1];
                }
            }
        }
        return f[n][target];
    }
};
```

#### Go

```go
func probabilityOfHeads(prob []float64, target int) float64 {
	n := len(prob)
	f := make([][]float64, n+1)
	for i := range f {
		f[i] = make([]float64, target+1)
	}
	f[0][0] = 1
	for i := 1; i <= n; i++ {
		for j := 0; j <= i && j <= target; j++ {
			f[i][j] = (1 - prob[i-1]) * f[i-1][j]
			if j > 0 {
				f[i][j] += prob[i-1] * f[i-1][j-1]
			}
		}
	}
	return f[n][target]
}
```

#### TypeScript

```ts
function probabilityOfHeads(prob: number[], target: number): number {
    const n = prob.length;
    const f = new Array(n + 1).fill(0).map(() => new Array(target + 1).fill(0));
    f[0][0] = 1;
    for (let i = 1; i <= n; ++i) {
        for (let j = 0; j <= target; ++j) {
            f[i][j] = f[i - 1][j] * (1 - prob[i - 1]);
            if (j) {
                f[i][j] += f[i - 1][j - 1] * prob[i - 1];
            }
        }
    }
    return f[n][target];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def probabilityOfHeads(self, prob: List[float], target: int) -> float:
        f = [0] * (target + 1)
        f[0] = 1
        for p in prob:
            for j in range(target, -1, -1):
                f[j] *= 1 - p
                if j:
                    f[j] += p * f[j - 1]
        return f[target]
```

#### Java

```java
class Solution {
    public double probabilityOfHeads(double[] prob, int target) {
        double[] f = new double[target + 1];
        f[0] = 1;
        for (double p : prob) {
            for (int j = target; j >= 0; --j) {
                f[j] *= (1 - p);
                if (j > 0) {
                    f[j] += p * f[j - 1];
                }
            }
        }
        return f[target];
    }
}
```

#### C++

```cpp
class Solution {
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        double f[target + 1];
        memset(f, 0, sizeof(f));
        f[0] = 1;
        for (double p : prob) {
            for (int j = target; j >= 0; --j) {
                f[j] *= (1 - p);
                if (j > 0) {
                    f[j] += p * f[j - 1];
                }
            }
        }
        return f[target];
    }
};
```

#### Go

```go
func probabilityOfHeads(prob []float64, target int) float64 {
	f := make([]float64, target+1)
	f[0] = 1
	for _, p := range prob {
		for j := target; j >= 0; j-- {
			f[j] *= (1 - p)
			if j > 0 {
				f[j] += p * f[j-1]
			}
		}
	}
	return f[target]
}
```

#### TypeScript

```ts
function probabilityOfHeads(prob: number[], target: number): number {
    const f = new Array(target + 1).fill(0);
    f[0] = 1;
    for (const p of prob) {
        for (let j = target; j >= 0; --j) {
            f[j] *= 1 - p;
            if (j > 0) {
                f[j] += f[j - 1] * p;
            }
        }
    }
    return f[target];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1231. 分享巧克力 🔒](https://leetcode.cn/problems/divide-chocolate){#1231}

{{< tabs "1231" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximizeSweetness(self, sweetness: List[int], k: int) -> int:
        def check(x: int) -> bool:
            s = cnt = 0
            for v in sweetness:
                s += v
                if s >= x:
                    s = 0
                    cnt += 1
            return cnt > k

        l, r = 0, sum(sweetness)
        while l < r:
            mid = (l + r + 1) >> 1
            if check(mid):
                l = mid
            else:
                r = mid - 1
        return l
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maximizeSweetness(int[] sweetness, int k) {
        int l = 0, r = 0;
        for (int v : sweetness) {
            r += v;
        }
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (check(sweetness, mid, k)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }

    private boolean check(int[] nums, int x, int k) {
        int s = 0, cnt = 0;
        for (int v : nums) {
            s += v;
            if (s >= x) {
                s = 0;
                ++cnt;
            }
        }
        return cnt > k;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maximizeSweetness(vector<int>& sweetness, int k) {
        int l = 0, r = accumulate(sweetness.begin(), sweetness.end(), 0);
        auto check = [&](int x) {
            int s = 0, cnt = 0;
            for (int v : sweetness) {
                s += v;
                if (s >= x) {
                    s = 0;
                    ++cnt;
                }
            }
            return cnt > k;
        };
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (check(mid)) {
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
func maximizeSweetness(sweetness []int, k int) int {
	l, r := 0, 0
	for _, v := range sweetness {
		r += v
	}
	check := func(x int) bool {
		s, cnt := 0, 0
		for _, v := range sweetness {
			s += v
			if s >= x {
				s = 0
				cnt++
			}
		}
		return cnt > k
	}
	for l < r {
		mid := (l + r + 1) >> 1
		if check(mid) {
			l = mid
		} else {
			r = mid - 1
		}
	}
	return l
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximizeSweetness(sweetness: number[], k: number): number {
    let l = 0;
    let r = sweetness.reduce((a, b) => a + b);
    const check = (x: number): boolean => {
        let s = 0;
        let cnt = 0;
        for (const v of sweetness) {
            s += v;
            if (s >= x) {
                s = 0;
                ++cnt;
            }
        }
        return cnt > k;
    };
    while (l < r) {
        const mid = (l + r + 1) >> 1;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return l;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你有一大块巧克力，它由一些甜度不完全相同的小块组成。我们用数组&nbsp;<code>sweetness</code>&nbsp;来表示每一小块的甜度。</p>

<p>你打算和&nbsp;<code>K</code>&nbsp;名朋友一起分享这块巧克力，所以你需要将切割&nbsp;<code>K</code>&nbsp;次才能得到 <code>K+1</code>&nbsp;块，每一块都由一些 <strong>连续&nbsp;</strong>的小块组成。</p>

<p>为了表现出你的慷慨，你将会吃掉&nbsp;<strong>总甜度最小</strong> 的一块，并将其余几块分给你的朋友们。</p>

<p>请找出一个最佳的切割策略，使得你所分得的巧克力&nbsp;<strong>总甜度最大</strong>，并返回这个 <strong>最大总甜度</strong>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>sweetness = [1,2,3,4,5,6,7,8,9], K = 5
<strong>输出：</strong>6
<strong>解释：</strong>你可以把巧克力分成 [1,2,3], [4,5], [6], [7], [8], [9]。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>sweetness = [5,6,7,8,9,1,2,3,4], K = 8
<strong>输出：</strong>1
<strong>解释：</strong>只有一种办法可以把巧克力分成 9 块。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>sweetness = [1,2,2,1,2,2,1,2,2], K = 2
<strong>输出：</strong>5
<strong>解释：</strong>你可以把巧克力分成 [1,2,2], [1,2,2], [1,2,2]。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= K &lt;&nbsp;sweetness.length &lt;= 10^4</code></li>
	<li><code>1 &lt;= sweetness[i] &lt;= 10^5</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二分查找 + 贪心

我们注意到，如果我们能吃到一块甜度为 $x$ 的巧克力，那么甜度小于等于 $x$ 的巧克力也都能吃到。这存在着单调性，因此，我们可以使用二分查找，找到最大的满足条件的 $x$。

我们定义二分查找的左边界 $l=0$，右边界 $r=\sum_{i=0}^{n-1} sweetness[i]$。每一次，我们取 $l$ 和 $r$ 的中间值 $mid$，然后判断能否吃到一块甜度为 $mid$ 的巧克力。如果能吃到，那么我们就尝试吃掉甜度更大的巧克力，即令 $l=mid$；否则，我们就尝试吃掉甜度更小的巧克力，即令 $r=mid-1$。在二分查找结束后，我们返回 $l$ 即可。

问题的关键在于，我们如何判断能否吃到一块甜度为 $x$ 的巧克力。我们可以使用贪心的思想，从左到右遍历数组，每次累加当前的甜度，当累加的甜度大于等于 $x$ 时，那么巧克力数 $cnt$ 加 $1$，并将累加的甜度清零。最后判断 $cnt$ 是否大于 $k$ 即可。

时间复杂度 $O(n \times \log \sum_{i=0}^{n-1} sweetness[i])$，空间复杂度 $O(1)$。其中 $n$ 是数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximizeSweetness(self, sweetness: List[int], k: int) -> int:
        def check(x: int) -> bool:
            s = cnt = 0
            for v in sweetness:
                s += v
                if s >= x:
                    s = 0
                    cnt += 1
            return cnt > k

        l, r = 0, sum(sweetness)
        while l < r:
            mid = (l + r + 1) >> 1
            if check(mid):
                l = mid
            else:
                r = mid - 1
        return l
```

#### Java

```java
class Solution {
    public int maximizeSweetness(int[] sweetness, int k) {
        int l = 0, r = 0;
        for (int v : sweetness) {
            r += v;
        }
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (check(sweetness, mid, k)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }

    private boolean check(int[] nums, int x, int k) {
        int s = 0, cnt = 0;
        for (int v : nums) {
            s += v;
            if (s >= x) {
                s = 0;
                ++cnt;
            }
        }
        return cnt > k;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maximizeSweetness(vector<int>& sweetness, int k) {
        int l = 0, r = accumulate(sweetness.begin(), sweetness.end(), 0);
        auto check = [&](int x) {
            int s = 0, cnt = 0;
            for (int v : sweetness) {
                s += v;
                if (s >= x) {
                    s = 0;
                    ++cnt;
                }
            }
            return cnt > k;
        };
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (check(mid)) {
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
func maximizeSweetness(sweetness []int, k int) int {
	l, r := 0, 0
	for _, v := range sweetness {
		r += v
	}
	check := func(x int) bool {
		s, cnt := 0, 0
		for _, v := range sweetness {
			s += v
			if s >= x {
				s = 0
				cnt++
			}
		}
		return cnt > k
	}
	for l < r {
		mid := (l + r + 1) >> 1
		if check(mid) {
			l = mid
		} else {
			r = mid - 1
		}
	}
	return l
}
```

#### TypeScript

```ts
function maximizeSweetness(sweetness: number[], k: number): number {
    let l = 0;
    let r = sweetness.reduce((a, b) => a + b);
    const check = (x: number): boolean => {
        let s = 0;
        let cnt = 0;
        for (const v of sweetness) {
            s += v;
            if (s >= x) {
                s = 0;
                ++cnt;
            }
        }
        return cnt > k;
    };
    while (l < r) {
        const mid = (l + r + 1) >> 1;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return l;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1232. 缀点成线](https://leetcode.cn/problems/check-if-it-is-a-straight-line){#1232}

{{< tabs "1232" >}}

{{% tab "python" %}}
```python
class Solution:
    def checkStraightLine(self, coordinates: List[List[int]]) -> bool:
        x1, y1 = coordinates[0]
        x2, y2 = coordinates[1]
        for x, y in coordinates[2:]:
            if (x - x1) * (y2 - y1) != (y - y1) * (x2 - x1):
                return False
        return True
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean checkStraightLine(int[][] coordinates) {
        int x1 = coordinates[0][0], y1 = coordinates[0][1];
        int x2 = coordinates[1][0], y2 = coordinates[1][1];
        for (int i = 2; i < coordinates.length; ++i) {
            int x = coordinates[i][0], y = coordinates[i][1];
            if ((x - x1) * (y2 - y1) != (y - y1) * (x2 - x1)) {
                return false;
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
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int x1 = coordinates[0][0], y1 = coordinates[0][1];
        int x2 = coordinates[1][0], y2 = coordinates[1][1];
        for (int i = 2; i < coordinates.size(); ++i) {
            int x = coordinates[i][0], y = coordinates[i][1];
            if ((x - x1) * (y2 - y1) != (y - y1) * (x2 - x1)) {
                return false;
            }
        }
        return true;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func checkStraightLine(coordinates [][]int) bool {
	x1, y1 := coordinates[0][0], coordinates[0][1]
	x2, y2 := coordinates[1][0], coordinates[1][1]
	for i := 2; i < len(coordinates); i++ {
		x, y := coordinates[i][0], coordinates[i][1]
		if (x-x1)*(y2-y1) != (y-y1)*(x2-x1) {
			return false
		}
	}
	return true
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个数组&nbsp;<code>coordinates</code>&nbsp;，其中&nbsp;<code>coordinates[i] = [x, y]</code>&nbsp;，<meta charset="UTF-8" />&nbsp;<code>[x, y]</code>&nbsp;表示横坐标为 <code>x</code>、纵坐标为 <code>y</code>&nbsp;的点。请你来判断，这些点是否在该坐标系中属于同一条直线上。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1200-1299/1232.Check%20If%20It%20Is%20a%20Straight%20Line/images/untitled-diagram-2.jpg" /></p>

<pre>
<strong>输入：</strong>coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
<strong>输出：</strong>true
</pre>

<p><strong class="example">示例 2：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1200-1299/1232.Check%20If%20It%20Is%20a%20Straight%20Line/images/untitled-diagram-1.jpg" /></strong></p>

<pre>
<strong>输入：</strong>coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
<strong>输出：</strong>false
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;=&nbsp;coordinates.length &lt;= 1000</code></li>
	<li><code>coordinates[i].length == 2</code></li>
	<li><code>-10^4 &lt;=&nbsp;coordinates[i][0],&nbsp;coordinates[i][1] &lt;= 10^4</code></li>
	<li><code>coordinates</code>&nbsp;中不含重复的点</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数学

时间复杂度 $O(n)$，其中 $n$ 表示 `coordinates` 数组的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def checkStraightLine(self, coordinates: List[List[int]]) -> bool:
        x1, y1 = coordinates[0]
        x2, y2 = coordinates[1]
        for x, y in coordinates[2:]:
            if (x - x1) * (y2 - y1) != (y - y1) * (x2 - x1):
                return False
        return True
```

#### Java

```java
class Solution {
    public boolean checkStraightLine(int[][] coordinates) {
        int x1 = coordinates[0][0], y1 = coordinates[0][1];
        int x2 = coordinates[1][0], y2 = coordinates[1][1];
        for (int i = 2; i < coordinates.length; ++i) {
            int x = coordinates[i][0], y = coordinates[i][1];
            if ((x - x1) * (y2 - y1) != (y - y1) * (x2 - x1)) {
                return false;
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
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int x1 = coordinates[0][0], y1 = coordinates[0][1];
        int x2 = coordinates[1][0], y2 = coordinates[1][1];
        for (int i = 2; i < coordinates.size(); ++i) {
            int x = coordinates[i][0], y = coordinates[i][1];
            if ((x - x1) * (y2 - y1) != (y - y1) * (x2 - x1)) {
                return false;
            }
        }
        return true;
    }
};
```

#### Go

```go
func checkStraightLine(coordinates [][]int) bool {
	x1, y1 := coordinates[0][0], coordinates[0][1]
	x2, y2 := coordinates[1][0], coordinates[1][1]
	for i := 2; i < len(coordinates); i++ {
		x, y := coordinates[i][0], coordinates[i][1]
		if (x-x1)*(y2-y1) != (y-y1)*(x2-x1) {
			return false
		}
	}
	return true
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1233. 删除子文件夹](https://leetcode.cn/problems/remove-sub-folders-from-the-filesystem){#1233}

{{< tabs "1233" >}}

{{% tab "python" %}}
```python
class Trie:
    def __init__(self):
        self.children = {}
        self.fid = -1

    def insert(self, i, f):
        node = self
        ps = f.split('/')
        for p in ps[1:]:
            if p not in node.children:
                node.children[p] = Trie()
            node = node.children[p]
        node.fid = i

    def search(self):
        def dfs(root):
            if root.fid != -1:
                ans.append(root.fid)
                return
            for child in root.children.values():
                dfs(child)

        ans = []
        dfs(self)
        return ans


class Solution:
    def removeSubfolders(self, folder: List[str]) -> List[str]:
        trie = Trie()
        for i, f in enumerate(folder):
            trie.insert(i, f)
        return [folder[i] for i in trie.search()]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Trie {
    private Map<String, Trie> children = new HashMap<>();
    private int fid = -1;

    public void insert(int fid, String f) {
        Trie node = this;
        String[] ps = f.split("/");
        for (int i = 1; i < ps.length; ++i) {
            String p = ps[i];
            if (!node.children.containsKey(p)) {
                node.children.put(p, new Trie());
            }
            node = node.children.get(p);
        }
        node.fid = fid;
    }

    public List<Integer> search() {
        List<Integer> ans = new ArrayList<>();
        dfs(this, ans);
        return ans;
    }

    private void dfs(Trie root, List<Integer> ans) {
        if (root.fid != -1) {
            ans.add(root.fid);
            return;
        }
        for (var child : root.children.values()) {
            dfs(child, ans);
        }
    }
}

class Solution {
    public List<String> removeSubfolders(String[] folder) {
        Trie trie = new Trie();
        for (int i = 0; i < folder.length; ++i) {
            trie.insert(i, folder[i]);
        }
        List<String> ans = new ArrayList<>();
        for (int i : trie.search()) {
            ans.add(folder[i]);
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Trie {
public:
    void insert(int fid, string& f) {
        Trie* node = this;
        vector<string> ps = split(f, '/');
        for (int i = 1; i < ps.size(); ++i) {
            auto& p = ps[i];
            if (!node->children.count(p)) {
                node->children[p] = new Trie();
            }
            node = node->children[p];
        }
        node->fid = fid;
    }

    vector<int> search() {
        vector<int> ans;
        function<void(Trie*)> dfs = [&](Trie* root) {
            if (root->fid != -1) {
                ans.push_back(root->fid);
                return;
            }
            for (auto& [_, child] : root->children) {
                dfs(child);
            }
        };
        dfs(this);
        return ans;
    }

    vector<string> split(string& s, char delim) {
        stringstream ss(s);
        string item;
        vector<string> res;
        while (getline(ss, item, delim)) {
            res.emplace_back(item);
        }
        return res;
    }

private:
    unordered_map<string, Trie*> children;
    int fid = -1;
};

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        Trie* trie = new Trie();
        for (int i = 0; i < folder.size(); ++i) {
            trie->insert(i, folder[i]);
        }
        vector<string> ans;
        for (int i : trie->search()) {
            ans.emplace_back(folder[i]);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
type Trie struct {
	children map[string]*Trie
	fid      int
}

func newTrie() *Trie {
	return &Trie{map[string]*Trie{}, -1}
}

func (this *Trie) insert(fid int, f string) {
	node := this
	ps := strings.Split(f, "/")
	for _, p := range ps[1:] {
		if _, ok := node.children[p]; !ok {
			node.children[p] = newTrie()
		}
		node = node.children[p]
	}
	node.fid = fid
}

func (this *Trie) search() (ans []int) {
	var dfs func(*Trie)
	dfs = func(root *Trie) {
		if root.fid != -1 {
			ans = append(ans, root.fid)
			return
		}
		for _, child := range root.children {
			dfs(child)
		}
	}
	dfs(this)
	return
}

func removeSubfolders(folder []string) (ans []string) {
	trie := newTrie()
	for i, f := range folder {
		trie.insert(i, f)
	}
	for _, i := range trie.search() {
		ans = append(ans, folder[i])
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class Trie {
    children: Record<string, Trie>;
    fid: number;

    constructor() {
        this.children = {};
        this.fid = -1;
    }

    insert(i: number, f: string): void {
        let node: Trie = this;
        const ps = f.split('/');
        for (let j = 1; j < ps.length; ++j) {
            const p = ps[j];
            if (!(p in node.children)) {
                node.children[p] = new Trie();
            }
            node = node.children[p];
        }
        node.fid = i;
    }

    search(): number[] {
        const ans: number[] = [];
        const dfs = (root: Trie): void => {
            if (root.fid !== -1) {
                ans.push(root.fid);
                return;
            }
            for (const child of Object.values(root.children)) {
                dfs(child);
            }
        };
        dfs(this);
        return ans;
    }
}

function removeSubfolders(folder: string[]): string[] {
    const trie = new Trie();
    for (let i = 0; i < folder.length; ++i) {
        trie.insert(i, folder[i]);
    }
    return trie.search().map(i => folder[i]);
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
class Trie {
    constructor() {
        this.children = {};
        this.fid = -1;
    }

    insert(i, f) {
        let node = this;
        const ps = f.split('/');
        for (let j = 1; j < ps.length; ++j) {
            const p = ps[j];
            if (!(p in node.children)) {
                node.children[p] = new Trie();
            }
            node = node.children[p];
        }
        node.fid = i;
    }

    search() {
        const ans = [];
        const dfs = root => {
            if (root.fid !== -1) {
                ans.push(root.fid);
                return;
            }
            for (const child of Object.values(root.children)) {
                dfs(child);
            }
        };
        dfs(this);
        return ans;
    }
}

/**
 * @param {string[]} folder
 * @return {string[]}
 */
var removeSubfolders = function (folder) {
    const trie = new Trie();
    for (let i = 0; i < folder.length; ++i) {
        trie.insert(i, folder[i]);
    }
    return trie.search().map(i => folder[i]);
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你是一位系统管理员，手里有一份文件夹列表 <code>folder</code>，你的任务是要删除该列表中的所有 <strong>子文件夹</strong>，并以 <strong>任意顺序</strong> 返回剩下的文件夹。</p>

<p>如果文件夹&nbsp;<code>folder[i]</code>&nbsp;位于另一个文件夹&nbsp;<code>folder[j]</code>&nbsp;下，那么&nbsp;<code>folder[i]</code>&nbsp;就是&nbsp;<code>folder[j]</code>&nbsp;的 <strong>子文件夹</strong> 。<code>folder[j]</code>&nbsp;的子文件夹必须以&nbsp;<code>folder[j]</code> 开头，后跟一个 <code>"/"</code>。例如，<code>"/a/b"</code> 是&nbsp;<code>"/a"</code>&nbsp;的一个子文件夹，但&nbsp;<code>"/b"</code> 不是&nbsp;<code>"/a/b/c"</code> 的一个子文件夹。</p>

<p>文件夹的「路径」是由一个或多个按以下格式串联形成的字符串：<font color="#c7254e"><font face="Menlo, Monaco, Consolas, Courier New, monospace"><span style="font-size:12.6px"><span style="background-color:#f9f2f4">'/'</span></span></font></font>&nbsp;后跟一个或者多个小写英文字母。</p>

<ul>
	<li>例如，<code>"/leetcode"</code>&nbsp;和&nbsp;<code>"/leetcode/problems"</code>&nbsp;都是有效的路径，而空字符串和&nbsp;<code>"/"</code>&nbsp;不是。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>folder = ["/a","/a/b","/c/d","/c/d/e","/c/f"]
<strong>输出：</strong>["/a","/c/d","/c/f"]
<strong>解释：</strong>"/a/b" 是 "/a" 的子文件夹，而 "/c/d/e" 是 "/c/d" 的子文件夹。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>folder = ["/a","/a/b/c","/a/b/d"]
<strong>输出：</strong>["/a"]
<strong>解释：</strong>文件夹 "/a/b/c" 和 "/a/b/d" 都会被删除，因为它们都是 "/a" 的子文件夹。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入:</strong> folder = ["/a/b/c","/a/b/ca","/a/b/d"]
<strong>输出:</strong> ["/a/b/c","/a/b/ca","/a/b/d"]</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= folder.length &lt;= 4 * 10<sup>4</sup></code></li>
	<li><code>2 &lt;= folder[i].length &lt;= 100</code></li>
	<li><code>folder[i]</code>&nbsp;只包含小写字母和 <code>'/'</code></li>
	<li><code>folder[i]</code>&nbsp;总是以字符 <code>'/'</code>&nbsp;起始</li>
	<li><code>folder</code>&nbsp;每个元素都是 <strong>唯一</strong> 的</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序

我们先将数组 `folder` 按照字典序排序，然后遍历数组，对于当前遍历到的文件夹 $f$，如果它的长度大于等于答案数组中最后一个文件夹的长度，并且它的前缀包含答案数组的最后一个文件夹再加上一个 `/`，则说明 $f$ 是答案数组中最后一个文件夹的子文件夹，我们不需要将其加入答案数组中。否则，我们将 $f$ 加入答案数组中。

遍历结束后，答案数组中的文件夹即为题目要求的答案。

时间复杂度 $O(n \times \log n \times m)$，空间复杂度 $O(m)$。其中 $n$ 和 $m$ 分别为数组 `folder` 的长度和数组 `folder` 中字符串的最大长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def removeSubfolders(self, folder: List[str]) -> List[str]:
        folder.sort()
        ans = [folder[0]]
        for f in folder[1:]:
            m, n = len(ans[-1]), len(f)
            if m >= n or not (ans[-1] == f[:m] and f[m] == '/'):
                ans.append(f)
        return ans
```

#### Java

```java
class Solution {
    public List<String> removeSubfolders(String[] folder) {
        Arrays.sort(folder);
        List<String> ans = new ArrayList<>();
        ans.add(folder[0]);
        for (int i = 1; i < folder.length; ++i) {
            int m = ans.get(ans.size() - 1).length();
            int n = folder[i].length();
            if (m >= n
                || !(ans.get(ans.size() - 1).equals(folder[i].substring(0, m))
                    && folder[i].charAt(m) == '/')) {
                ans.add(folder[i]);
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
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> ans = {folder[0]};
        for (int i = 1; i < folder.size(); ++i) {
            int m = ans.back().size();
            int n = folder[i].size();
            if (m >= n || !(ans.back() == folder[i].substr(0, m) && folder[i][m] == '/')) {
                ans.emplace_back(folder[i]);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func removeSubfolders(folder []string) []string {
	sort.Strings(folder)
	ans := []string{folder[0]}
	for _, f := range folder[1:] {
		m, n := len(ans[len(ans)-1]), len(f)
		if m >= n || !(ans[len(ans)-1] == f[:m] && f[m] == '/') {
			ans = append(ans, f)
		}
	}
	return ans
}
```

#### TypeScript

```ts
function removeSubfolders(folder: string[]): string[] {
    let s = folder[1];
    return folder.sort().filter(x => !x.startsWith(s + '/') && (s = x));
}
```

#### JavaScript

```js
function removeSubfolders(folder) {
    let s = folder[1];
    return folder.sort().filter(x => !x.startsWith(s + '/') && (s = x));
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：字典树

我们可以使用字典树存储数组 `folder` 中的所有文件夹。字典树的每个节点包含 `children` 字段，用于存储当前节点的子节点，以及 `fid` 字段，用于存储当前节点对应的文件夹在数组 `folder` 中的下标。

对于数组 `folder` 中的每个文件夹 $f$，我们先将 $f$ 按照 `/` 分割成若干个子串，然后从根节点开始，依次将子串加入字典树中。接下来，我们从根节点开始搜索字典树，如果当前节点的 `fid` 字段不为 `-1`，则说明当前节点对应的文件夹是答案数组中的一个文件夹，我们将其加入答案数组并且返回。否则，我们递归地搜索当前节点的所有子节点，最终返回答案数组。

时间复杂度 $O(n \times m)$，空间复杂度 $O(n \times m)$。其中 $n$ 和 $m$ 分别为数组 `folder` 的长度和数组 `folder` 中字符串的最大长度。

<!-- tabs:start -->

#### Python3

```python
class Trie:
    def __init__(self):
        self.children = {}
        self.fid = -1

    def insert(self, i, f):
        node = self
        ps = f.split('/')
        for p in ps[1:]:
            if p not in node.children:
                node.children[p] = Trie()
            node = node.children[p]
        node.fid = i

    def search(self):
        def dfs(root):
            if root.fid != -1:
                ans.append(root.fid)
                return
            for child in root.children.values():
                dfs(child)

        ans = []
        dfs(self)
        return ans


class Solution:
    def removeSubfolders(self, folder: List[str]) -> List[str]:
        trie = Trie()
        for i, f in enumerate(folder):
            trie.insert(i, f)
        return [folder[i] for i in trie.search()]
```

#### Java

```java
class Trie {
    private Map<String, Trie> children = new HashMap<>();
    private int fid = -1;

    public void insert(int fid, String f) {
        Trie node = this;
        String[] ps = f.split("/");
        for (int i = 1; i < ps.length; ++i) {
            String p = ps[i];
            if (!node.children.containsKey(p)) {
                node.children.put(p, new Trie());
            }
            node = node.children.get(p);
        }
        node.fid = fid;
    }

    public List<Integer> search() {
        List<Integer> ans = new ArrayList<>();
        dfs(this, ans);
        return ans;
    }

    private void dfs(Trie root, List<Integer> ans) {
        if (root.fid != -1) {
            ans.add(root.fid);
            return;
        }
        for (var child : root.children.values()) {
            dfs(child, ans);
        }
    }
}

class Solution {
    public List<String> removeSubfolders(String[] folder) {
        Trie trie = new Trie();
        for (int i = 0; i < folder.length; ++i) {
            trie.insert(i, folder[i]);
        }
        List<String> ans = new ArrayList<>();
        for (int i : trie.search()) {
            ans.add(folder[i]);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Trie {
public:
    void insert(int fid, string& f) {
        Trie* node = this;
        vector<string> ps = split(f, '/');
        for (int i = 1; i < ps.size(); ++i) {
            auto& p = ps[i];
            if (!node->children.count(p)) {
                node->children[p] = new Trie();
            }
            node = node->children[p];
        }
        node->fid = fid;
    }

    vector<int> search() {
        vector<int> ans;
        function<void(Trie*)> dfs = [&](Trie* root) {
            if (root->fid != -1) {
                ans.push_back(root->fid);
                return;
            }
            for (auto& [_, child] : root->children) {
                dfs(child);
            }
        };
        dfs(this);
        return ans;
    }

    vector<string> split(string& s, char delim) {
        stringstream ss(s);
        string item;
        vector<string> res;
        while (getline(ss, item, delim)) {
            res.emplace_back(item);
        }
        return res;
    }

private:
    unordered_map<string, Trie*> children;
    int fid = -1;
};

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        Trie* trie = new Trie();
        for (int i = 0; i < folder.size(); ++i) {
            trie->insert(i, folder[i]);
        }
        vector<string> ans;
        for (int i : trie->search()) {
            ans.emplace_back(folder[i]);
        }
        return ans;
    }
};
```

#### Go

```go
type Trie struct {
	children map[string]*Trie
	fid      int
}

func newTrie() *Trie {
	return &Trie{map[string]*Trie{}, -1}
}

func (this *Trie) insert(fid int, f string) {
	node := this
	ps := strings.Split(f, "/")
	for _, p := range ps[1:] {
		if _, ok := node.children[p]; !ok {
			node.children[p] = newTrie()
		}
		node = node.children[p]
	}
	node.fid = fid
}

func (this *Trie) search() (ans []int) {
	var dfs func(*Trie)
	dfs = func(root *Trie) {
		if root.fid != -1 {
			ans = append(ans, root.fid)
			return
		}
		for _, child := range root.children {
			dfs(child)
		}
	}
	dfs(this)
	return
}

func removeSubfolders(folder []string) (ans []string) {
	trie := newTrie()
	for i, f := range folder {
		trie.insert(i, f)
	}
	for _, i := range trie.search() {
		ans = append(ans, folder[i])
	}
	return
}
```

#### TypeScript

```ts
class Trie {
    children: Record<string, Trie>;
    fid: number;

    constructor() {
        this.children = {};
        this.fid = -1;
    }

    insert(i: number, f: string): void {
        let node: Trie = this;
        const ps = f.split('/');
        for (let j = 1; j < ps.length; ++j) {
            const p = ps[j];
            if (!(p in node.children)) {
                node.children[p] = new Trie();
            }
            node = node.children[p];
        }
        node.fid = i;
    }

    search(): number[] {
        const ans: number[] = [];
        const dfs = (root: Trie): void => {
            if (root.fid !== -1) {
                ans.push(root.fid);
                return;
            }
            for (const child of Object.values(root.children)) {
                dfs(child);
            }
        };
        dfs(this);
        return ans;
    }
}

function removeSubfolders(folder: string[]): string[] {
    const trie = new Trie();
    for (let i = 0; i < folder.length; ++i) {
        trie.insert(i, folder[i]);
    }
    return trie.search().map(i => folder[i]);
}
```

#### JavaScript

```js
class Trie {
    constructor() {
        this.children = {};
        this.fid = -1;
    }

    insert(i, f) {
        let node = this;
        const ps = f.split('/');
        for (let j = 1; j < ps.length; ++j) {
            const p = ps[j];
            if (!(p in node.children)) {
                node.children[p] = new Trie();
            }
            node = node.children[p];
        }
        node.fid = i;
    }

    search() {
        const ans = [];
        const dfs = root => {
            if (root.fid !== -1) {
                ans.push(root.fid);
                return;
            }
            for (const child of Object.values(root.children)) {
                dfs(child);
            }
        };
        dfs(this);
        return ans;
    }
}

/**
 * @param {string[]} folder
 * @return {string[]}
 */
var removeSubfolders = function (folder) {
    const trie = new Trie();
    for (let i = 0; i < folder.length; ++i) {
        trie.insert(i, folder[i]);
    }
    return trie.search().map(i => folder[i]);
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1234. 替换子串得到平衡字符串](https://leetcode.cn/problems/replace-the-substring-for-balanced-string){#1234}

{{< tabs "1234" >}}

{{% tab "python" %}}
```python
class Solution:
    def balancedString(self, s: str) -> int:
        cnt = Counter(s)
        n = len(s)
        if all(v <= n // 4 for v in cnt.values()):
            return 0
        ans, j = n, 0
        for i, c in enumerate(s):
            cnt[c] -= 1
            while j <= i and all(v <= n // 4 for v in cnt.values()):
                ans = min(ans, i - j + 1)
                cnt[s[j]] += 1
                j += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int balancedString(String s) {
        int[] cnt = new int[4];
        String t = "QWER";
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            cnt[t.indexOf(s.charAt(i))]++;
        }
        int m = n / 4;
        if (cnt[0] == m && cnt[1] == m && cnt[2] == m && cnt[3] == m) {
            return 0;
        }
        int ans = n;
        for (int i = 0, j = 0; i < n; ++i) {
            cnt[t.indexOf(s.charAt(i))]--;
            while (j <= i && cnt[0] <= m && cnt[1] <= m && cnt[2] <= m && cnt[3] <= m) {
                ans = Math.min(ans, i - j + 1);
                cnt[t.indexOf(s.charAt(j++))]++;
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
    int balancedString(string s) {
        int cnt[4]{};
        string t = "QWER";
        int n = s.size();
        for (char& c : s) {
            cnt[t.find(c)]++;
        }
        int m = n / 4;
        if (cnt[0] == m && cnt[1] == m && cnt[2] == m && cnt[3] == m) {
            return 0;
        }
        int ans = n;
        for (int i = 0, j = 0; i < n; ++i) {
            cnt[t.find(s[i])]--;
            while (j <= i && cnt[0] <= m && cnt[1] <= m && cnt[2] <= m && cnt[3] <= m) {
                ans = min(ans, i - j + 1);
                cnt[t.find(s[j++])]++;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func balancedString(s string) int {
	cnt := [4]int{}
	t := "QWER"
	n := len(s)
	for i := range s {
		cnt[strings.IndexByte(t, s[i])]++
	}
	m := n / 4
	if cnt[0] == m && cnt[1] == m && cnt[2] == m && cnt[3] == m {
		return 0
	}
	ans := n
	for i, j := 0, 0; i < n; i++ {
		cnt[strings.IndexByte(t, s[i])]--
		for j <= i && cnt[0] <= m && cnt[1] <= m && cnt[2] <= m && cnt[3] <= m {
			ans = min(ans, i-j+1)
			cnt[strings.IndexByte(t, s[j])]++
			j++
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

<p>有一个只含有&nbsp;<code>'Q', 'W', 'E',&nbsp;'R'</code>&nbsp;四种字符，且长度为 <code>n</code>&nbsp;的字符串。</p>

<p>假如在该字符串中，这四个字符都恰好出现&nbsp;<code>n/4</code>&nbsp;次，那么它就是一个「平衡字符串」。</p>

<p>&nbsp;</p>

<p>给你一个这样的字符串 <code>s</code>，请通过「替换一个子串」的方式，使原字符串 <code>s</code> 变成一个「平衡字符串」。</p>

<p>你可以用和「待替换子串」长度相同的&nbsp;<strong>任何</strong> 其他字符串来完成替换。</p>

<p>请返回待替换子串的最小可能长度。</p>

<p>如果原字符串自身就是一个平衡字符串，则返回 <code>0</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "QWER"
<strong>输出：</strong>0
<strong>解释：</strong>s 已经是平衡的了。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "QQWE"
<strong>输出：</strong>1
<strong>解释：</strong>我们需要把一个 'Q' 替换成 'R'，这样得到的 "RQWE" (或 "QRWE") 是平衡的。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "QQQW"
<strong>输出：</strong>2
<strong>解释：</strong>我们可以把前面的 "QQ" 替换成 "ER"。 
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>s = "QQQQ"
<strong>输出：</strong>3
<strong>解释：</strong>我们可以替换后 3 个 'Q'，使 s = "QWER"。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10^5</code></li>
	<li><code>s.length</code>&nbsp;是&nbsp;<code>4</code>&nbsp;的倍数</li>
	<li><code>s</code>&nbsp;中只含有&nbsp;<code>'Q'</code>, <code>'W'</code>, <code>'E'</code>,&nbsp;<code>'R'</code>&nbsp;四种字符</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数 + 双指针

我们先用一个哈希表或数组 `cnt` 统计字符串 $s$ 中每个字符的数量，如果所有字符的数量都不超过 $n/4$，那么字符串 $s$ 就是平衡字符串，直接返回 $0$。

否则，我们使用双指针 $j$ 和 $i$ 分别维护窗口的左右边界，初始时 $j = 0$。

接下来，从左到右遍历字符串 $s$，每次遍历到一个字符，就将该字符的数量减 $1$，然后判断当前窗口是否满足条件，即窗口外的字符数量都不超过 $n/4$。如果满足条件，那么就更新答案，然后将窗口的左边界右移，直到不满足条件为止。

最后，返回答案即可。

时间复杂度 $O(n)$，空间复杂度 $O(C)$。其中 $n$ 是字符串 $s$ 的长度；而 $C$ 是字符集的大小，本题中 $C = 4$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def balancedString(self, s: str) -> int:
        cnt = Counter(s)
        n = len(s)
        if all(v <= n // 4 for v in cnt.values()):
            return 0
        ans, j = n, 0
        for i, c in enumerate(s):
            cnt[c] -= 1
            while j <= i and all(v <= n // 4 for v in cnt.values()):
                ans = min(ans, i - j + 1)
                cnt[s[j]] += 1
                j += 1
        return ans
```

#### Java

```java
class Solution {
    public int balancedString(String s) {
        int[] cnt = new int[4];
        String t = "QWER";
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            cnt[t.indexOf(s.charAt(i))]++;
        }
        int m = n / 4;
        if (cnt[0] == m && cnt[1] == m && cnt[2] == m && cnt[3] == m) {
            return 0;
        }
        int ans = n;
        for (int i = 0, j = 0; i < n; ++i) {
            cnt[t.indexOf(s.charAt(i))]--;
            while (j <= i && cnt[0] <= m && cnt[1] <= m && cnt[2] <= m && cnt[3] <= m) {
                ans = Math.min(ans, i - j + 1);
                cnt[t.indexOf(s.charAt(j++))]++;
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
    int balancedString(string s) {
        int cnt[4]{};
        string t = "QWER";
        int n = s.size();
        for (char& c : s) {
            cnt[t.find(c)]++;
        }
        int m = n / 4;
        if (cnt[0] == m && cnt[1] == m && cnt[2] == m && cnt[3] == m) {
            return 0;
        }
        int ans = n;
        for (int i = 0, j = 0; i < n; ++i) {
            cnt[t.find(s[i])]--;
            while (j <= i && cnt[0] <= m && cnt[1] <= m && cnt[2] <= m && cnt[3] <= m) {
                ans = min(ans, i - j + 1);
                cnt[t.find(s[j++])]++;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func balancedString(s string) int {
	cnt := [4]int{}
	t := "QWER"
	n := len(s)
	for i := range s {
		cnt[strings.IndexByte(t, s[i])]++
	}
	m := n / 4
	if cnt[0] == m && cnt[1] == m && cnt[2] == m && cnt[3] == m {
		return 0
	}
	ans := n
	for i, j := 0, 0; i < n; i++ {
		cnt[strings.IndexByte(t, s[i])]--
		for j <= i && cnt[0] <= m && cnt[1] <= m && cnt[2] <= m && cnt[3] <= m {
			ans = min(ans, i-j+1)
			cnt[strings.IndexByte(t, s[j])]++
			j++
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

# [1235. 规划兼职工作](https://leetcode.cn/problems/maximum-profit-in-job-scheduling){#1235}

{{< tabs "1235" >}}

{{% tab "python" %}}
```python
class Solution:
    def jobScheduling(
        self, startTime: List[int], endTime: List[int], profit: List[int]
    ) -> int:
        jobs = sorted(zip(endTime, startTime, profit))
        n = len(profit)
        dp = [0] * (n + 1)
        for i, (_, s, p) in enumerate(jobs):
            j = bisect_right(jobs, s, hi=i, key=lambda x: x[0])
            dp[i + 1] = max(dp[i], dp[j] + p)
        return dp[n]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
        int n = profit.length;
        int[][] jobs = new int[n][3];
        for (int i = 0; i < n; ++i) {
            jobs[i] = new int[] {startTime[i], endTime[i], profit[i]};
        }
        Arrays.sort(jobs, (a, b) -> a[1] - b[1]);
        int[] dp = new int[n + 1];
        for (int i = 0; i < n; ++i) {
            int j = search(jobs, jobs[i][0], i);
            dp[i + 1] = Math.max(dp[i], dp[j] + jobs[i][2]);
        }
        return dp[n];
    }

    private int search(int[][] jobs, int x, int n) {
        int left = 0, right = n;
        while (left < right) {
            int mid = (left + right) >> 1;
            if (jobs[mid][1] > x) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = profit.size();
        vector<tuple<int, int, int>> jobs(n);
        for (int i = 0; i < n; ++i) jobs[i] = {endTime[i], startTime[i], profit[i]};
        sort(jobs.begin(), jobs.end());
        vector<int> dp(n + 1);
        for (int i = 0; i < n; ++i) {
            auto [_, s, p] = jobs[i];
            int j = upper_bound(jobs.begin(), jobs.begin() + i, s, [&](int x, auto& job) -> bool { return x < get<0>(job); }) - jobs.begin();
            dp[i + 1] = max(dp[i], dp[j] + p);
        }
        return dp[n];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func jobScheduling(startTime []int, endTime []int, profit []int) int {
	n := len(profit)
	type tuple struct{ s, e, p int }
	jobs := make([]tuple, n)
	for i, p := range profit {
		jobs[i] = tuple{startTime[i], endTime[i], p}
	}
	sort.Slice(jobs, func(i, j int) bool { return jobs[i].e < jobs[j].e })
	dp := make([]int, n+1)
	for i, job := range jobs {
		j := sort.Search(i, func(k int) bool { return jobs[k].e > job.s })
		dp[i+1] = max(dp[i], dp[j]+job.p)
	}
	return dp[n]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function jobScheduling(startTime: number[], endTime: number[], profit: number[]): number {
    const n = profit.length;
    const jobs: [number, number, number][] = Array.from({ length: n }, (_, i) => [
        startTime[i],
        endTime[i],
        profit[i],
    ]);
    jobs.sort((a, b) => a[1] - b[1]);
    const dp: number[] = Array.from({ length: n + 1 }, () => 0);
    const search = (x: number, right: number): number => {
        let left = 0;
        while (left < right) {
            const mid = (left + right) >> 1;
            if (jobs[mid][1] > x) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    };
    for (let i = 0; i < n; ++i) {
        const j = search(jobs[i][0], i);
        dp[i + 1] = Math.max(dp[i], dp[j] + jobs[i][2]);
    }
    return dp[n];
}
```
{{% /tab %}}
{{% tab "swift" %}}
```swift
class Solution {

    func binarySearch<T: Comparable>(inputArr: [T], searchItem: T) -> Int? {
        var lowerIndex = 0
        var upperIndex = inputArr.count - 1

        while lowerIndex < upperIndex {
            let currentIndex = (lowerIndex + upperIndex) / 2
            if inputArr[currentIndex] <= searchItem {
                lowerIndex = currentIndex + 1
            } else {
                upperIndex = currentIndex
            }
        }

        if inputArr[upperIndex] <= searchItem {
            return upperIndex + 1
        }
        return lowerIndex
    }

    func jobScheduling(_ startTime: [Int], _ endTime: [Int], _ profit: [Int]) -> Int {
        let zipList = zip(zip(startTime, endTime), profit)
        var table: [(startTime: Int, endTime: Int, profit: Int, cumsum: Int)] = []

        for ((x, y), z) in zipList {
            table.append((x, y, z, 0))
        }
        table.sort(by: { $0.endTime < $1.endTime })
        let sortedEndTime = endTime.sorted()

        var profits: [Int] = [0]
        for iJob in table {
            let index: Int! = binarySearch(inputArr: sortedEndTime, searchItem: iJob.startTime)
            if profits.last! < profits[index] + iJob.profit {
                profits.append(profits[index] + iJob.profit)
            } else {
                profits.append(profits.last!)
            }
        }
        return profits.last!
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你打算利用空闲时间来做兼职工作赚些零花钱。</p>

<p>这里有&nbsp;<code>n</code>&nbsp;份兼职工作，每份工作预计从&nbsp;<code>startTime[i]</code>&nbsp;开始到&nbsp;<code>endTime[i]</code>&nbsp;结束，报酬为&nbsp;<code>profit[i]</code>。</p>

<p>给你一份兼职工作表，包含开始时间&nbsp;<code>startTime</code>，结束时间&nbsp;<code>endTime</code>&nbsp;和预计报酬&nbsp;<code>profit</code>&nbsp;三个数组，请你计算并返回可以获得的最大报酬。</p>

<p>注意，时间上出现重叠的 2 份工作不能同时进行。</p>

<p>如果你选择的工作在时间&nbsp;<code>X</code>&nbsp;结束，那么你可以立刻进行在时间&nbsp;<code>X</code>&nbsp;开始的下一份工作。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1200-1299/1235.Maximum%20Profit%20in%20Job%20Scheduling/images/sample1_1584.png" style="width: 300px;" /></strong></p>

<pre>
<strong>输入：</strong>startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
<strong>输出：</strong>120
<strong>解释：
</strong>我们选出第 1 份和第 4 份工作， 
时间范围是 [1-3]+[3-6]，共获得报酬 120 = 50 + 70。
</pre>

<p><strong class="example">示例 2：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1200-1299/1235.Maximum%20Profit%20in%20Job%20Scheduling/images/sample22_1584.png" style="height: 112px; width: 600px;" /> </strong></p>

<pre>
<strong>输入：</strong>startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit = [20,20,100,70,60]
<strong>输出：</strong>150
<strong>解释：
</strong>我们选择第 1，4，5 份工作。 
共获得报酬 150 = 20 + 70 + 60。
</pre>

<p><strong class="example">示例 3：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1200-1299/1235.Maximum%20Profit%20in%20Job%20Scheduling/images/sample3_1584.png" style="height: 112px; width: 400px;" /></strong></p>

<pre>
<strong>输入：</strong>startTime = [1,1,1], endTime = [2,3,4], profit = [5,6,4]
<strong>输出：</strong>6
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= startTime.length == endTime.length ==&nbsp;profit.length&nbsp;&lt;= 5 * 10^4</code></li>
	<li><code>1 &lt;=&nbsp;startTime[i] &lt;&nbsp;endTime[i] &lt;= 10^9</code></li>
	<li><code>1 &lt;=&nbsp;profit[i] &lt;= 10^4</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索 + 二分查找

我们先将工作按照开始时间从小到大排序，然后设计一个函数 $dfs(i)$ 表示从第 $i$ 份工作开始，可以获得的最大报酬。答案即为 $dfs(0)$。

函数 $dfs(i)$ 的计算过程如下：

对于第 $i$ 份工作，我们可以选择做，也可以选择不做。如果不做，最大报酬就是 $dfs(i + 1)$；如果做，我们可以通过二分查找，找到在第 $i$ 份工作结束时间之后开始的第一份工作，记为 $j$，那么最大报酬就是 $profit[i] + dfs(j)$。取两者的较大值即可。即：

$$
dfs(i)=\max(dfs(i+1),profit[i]+dfs(j))
$$

其中 $j$ 是满足 $startTime[j] \ge endTime[i]$ 的最小的下标。

此过程中，我们可以使用记忆化搜索，将每个状态的答案保存下来，避免重复计算。

时间复杂度 $O(n \times \log n)$，其中 $n$ 是工作的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def jobScheduling(
        self, startTime: List[int], endTime: List[int], profit: List[int]
    ) -> int:
        @cache
        def dfs(i):
            if i >= n:
                return 0
            _, e, p = jobs[i]
            j = bisect_left(jobs, e, lo=i + 1, key=lambda x: x[0])
            return max(dfs(i + 1), p + dfs(j))

        jobs = sorted(zip(startTime, endTime, profit))
        n = len(profit)
        return dfs(0)
```

#### Java

```java
class Solution {
    private int[][] jobs;
    private int[] f;
    private int n;

    public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
        n = profit.length;
        jobs = new int[n][3];
        for (int i = 0; i < n; ++i) {
            jobs[i] = new int[] {startTime[i], endTime[i], profit[i]};
        }
        Arrays.sort(jobs, (a, b) -> a[0] - b[0]);
        f = new int[n];
        return dfs(0);
    }

    private int dfs(int i) {
        if (i >= n) {
            return 0;
        }
        if (f[i] != 0) {
            return f[i];
        }
        int e = jobs[i][1], p = jobs[i][2];
        int j = search(jobs, e, i + 1);
        int ans = Math.max(dfs(i + 1), p + dfs(j));
        f[i] = ans;
        return ans;
    }

    private int search(int[][] jobs, int x, int i) {
        int left = i, right = n;
        while (left < right) {
            int mid = (left + right) >> 1;
            if (jobs[mid][0] >= x) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = profit.size();
        vector<tuple<int, int, int>> jobs(n);
        for (int i = 0; i < n; ++i) jobs[i] = {startTime[i], endTime[i], profit[i]};
        sort(jobs.begin(), jobs.end());
        vector<int> f(n);
        function<int(int)> dfs = [&](int i) -> int {
            if (i >= n) return 0;
            if (f[i]) return f[i];
            auto [_, e, p] = jobs[i];
            tuple<int, int, int> t{e, 0, 0};
            int j = lower_bound(jobs.begin() + i + 1, jobs.end(), t, [&](auto& l, auto& r) -> bool { return get<0>(l) < get<0>(r); }) - jobs.begin();
            int ans = max(dfs(i + 1), p + dfs(j));
            f[i] = ans;
            return ans;
        };
        return dfs(0);
    }
};
```

#### Go

```go
func jobScheduling(startTime []int, endTime []int, profit []int) int {
	n := len(profit)
	type tuple struct{ s, e, p int }
	jobs := make([]tuple, n)
	for i, p := range profit {
		jobs[i] = tuple{startTime[i], endTime[i], p}
	}
	sort.Slice(jobs, func(i, j int) bool { return jobs[i].s < jobs[j].s })
	f := make([]int, n)
	var dfs func(int) int
	dfs = func(i int) int {
		if i >= n {
			return 0
		}
		if f[i] != 0 {
			return f[i]
		}
		j := sort.Search(n, func(j int) bool { return jobs[j].s >= jobs[i].e })
		ans := max(dfs(i+1), jobs[i].p+dfs(j))
		f[i] = ans
		return ans
	}
	return dfs(0)
}
```

#### TypeScript

```ts
function jobScheduling(startTime: number[], endTime: number[], profit: number[]): number {
    const n = startTime.length;
    const f = new Array(n).fill(0);
    const idx = new Array(n).fill(0).map((_, i) => i);
    idx.sort((i, j) => startTime[i] - startTime[j]);
    const search = (x: number) => {
        let l = 0;
        let r = n;
        while (l < r) {
            const mid = (l + r) >> 1;
            if (startTime[idx[mid]] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    };
    const dfs = (i: number): number => {
        if (i >= n) {
            return 0;
        }
        if (f[i] !== 0) {
            return f[i];
        }
        const j = search(endTime[idx[i]]);
        return (f[i] = Math.max(dfs(i + 1), dfs(j) + profit[idx[i]]));
    };
    return dfs(0);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：动态规划 + 二分查找

我们还可以将方法一中的记忆化搜索改为动态规划。

先将工作排序，这次我们按照结束时间从小到大排序，然后定义 $dp[i]$，表示前 $i$ 份工作中，可以获得的最大报酬。答案即为 $dp[n]$。初始化 $dp[0]=0$。

对于第 $i$ 份工作，我们可以选择做，也可以选择不做。如果不做，最大报酬就是 $dp[i]$；如果做，我们可以通过二分查找，找到在第 $i$ 份工作开始时间之前结束的最后一份工作，记为 $j$，那么最大报酬就是 $profit[i] + dp[j]$。取两者的较大值即可。即：

$$
dp[i+1] = \max(dp[i], profit[i] + dp[j])
$$

其中 $j$ 是满足 $endTime[j] \leq startTime[i]$ 的最大的下标。

时间复杂度 $O(n \times \log n)$，其中 $n$ 是工作的数量。

相似题目：

-   [2008. 出租车的最大盈利](https://github.com/doocs/leetcode/blob/main/solution/2000-2099/2008.Maximum%20Earnings%20From%20Taxi/README.md)
-   [1751. 最多可以参加的会议数目 II](https://github.com/doocs/leetcode/blob/main/solution/1700-1799/1751.Maximum%20Number%20of%20Events%20That%20Can%20Be%20Attended%20II/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def jobScheduling(
        self, startTime: List[int], endTime: List[int], profit: List[int]
    ) -> int:
        jobs = sorted(zip(endTime, startTime, profit))
        n = len(profit)
        dp = [0] * (n + 1)
        for i, (_, s, p) in enumerate(jobs):
            j = bisect_right(jobs, s, hi=i, key=lambda x: x[0])
            dp[i + 1] = max(dp[i], dp[j] + p)
        return dp[n]
```

#### Java

```java
class Solution {
    public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
        int n = profit.length;
        int[][] jobs = new int[n][3];
        for (int i = 0; i < n; ++i) {
            jobs[i] = new int[] {startTime[i], endTime[i], profit[i]};
        }
        Arrays.sort(jobs, (a, b) -> a[1] - b[1]);
        int[] dp = new int[n + 1];
        for (int i = 0; i < n; ++i) {
            int j = search(jobs, jobs[i][0], i);
            dp[i + 1] = Math.max(dp[i], dp[j] + jobs[i][2]);
        }
        return dp[n];
    }

    private int search(int[][] jobs, int x, int n) {
        int left = 0, right = n;
        while (left < right) {
            int mid = (left + right) >> 1;
            if (jobs[mid][1] > x) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = profit.size();
        vector<tuple<int, int, int>> jobs(n);
        for (int i = 0; i < n; ++i) jobs[i] = {endTime[i], startTime[i], profit[i]};
        sort(jobs.begin(), jobs.end());
        vector<int> dp(n + 1);
        for (int i = 0; i < n; ++i) {
            auto [_, s, p] = jobs[i];
            int j = upper_bound(jobs.begin(), jobs.begin() + i, s, [&](int x, auto& job) -> bool { return x < get<0>(job); }) - jobs.begin();
            dp[i + 1] = max(dp[i], dp[j] + p);
        }
        return dp[n];
    }
};
```

#### Go

```go
func jobScheduling(startTime []int, endTime []int, profit []int) int {
	n := len(profit)
	type tuple struct{ s, e, p int }
	jobs := make([]tuple, n)
	for i, p := range profit {
		jobs[i] = tuple{startTime[i], endTime[i], p}
	}
	sort.Slice(jobs, func(i, j int) bool { return jobs[i].e < jobs[j].e })
	dp := make([]int, n+1)
	for i, job := range jobs {
		j := sort.Search(i, func(k int) bool { return jobs[k].e > job.s })
		dp[i+1] = max(dp[i], dp[j]+job.p)
	}
	return dp[n]
}
```

#### TypeScript

```ts
function jobScheduling(startTime: number[], endTime: number[], profit: number[]): number {
    const n = profit.length;
    const jobs: [number, number, number][] = Array.from({ length: n }, (_, i) => [
        startTime[i],
        endTime[i],
        profit[i],
    ]);
    jobs.sort((a, b) => a[1] - b[1]);
    const dp: number[] = Array.from({ length: n + 1 }, () => 0);
    const search = (x: number, right: number): number => {
        let left = 0;
        while (left < right) {
            const mid = (left + right) >> 1;
            if (jobs[mid][1] > x) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    };
    for (let i = 0; i < n; ++i) {
        const j = search(jobs[i][0], i);
        dp[i + 1] = Math.max(dp[i], dp[j] + jobs[i][2]);
    }
    return dp[n];
}
```

#### Swift

```swift
class Solution {

    func binarySearch<T: Comparable>(inputArr: [T], searchItem: T) -> Int? {
        var lowerIndex = 0
        var upperIndex = inputArr.count - 1

        while lowerIndex < upperIndex {
            let currentIndex = (lowerIndex + upperIndex) / 2
            if inputArr[currentIndex] <= searchItem {
                lowerIndex = currentIndex + 1
            } else {
                upperIndex = currentIndex
            }
        }

        if inputArr[upperIndex] <= searchItem {
            return upperIndex + 1
        }
        return lowerIndex
    }

    func jobScheduling(_ startTime: [Int], _ endTime: [Int], _ profit: [Int]) -> Int {
        let zipList = zip(zip(startTime, endTime), profit)
        var table: [(startTime: Int, endTime: Int, profit: Int, cumsum: Int)] = []

        for ((x, y), z) in zipList {
            table.append((x, y, z, 0))
        }
        table.sort(by: { $0.endTime < $1.endTime })
        let sortedEndTime = endTime.sorted()

        var profits: [Int] = [0]
        for iJob in table {
            let index: Int! = binarySearch(inputArr: sortedEndTime, searchItem: iJob.startTime)
            if profits.last! < profits[index] + iJob.profit {
                profits.append(profits[index] + iJob.profit)
            } else {
                profits.append(profits.last!)
            }
        }
        return profits.last!
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1236. 网络爬虫 🔒](https://leetcode.cn/problems/web-crawler){#1236}

{{< tabs "1236" >}}

{{% tab "python" %}}
```python
# """
# This is HtmlParser's API interface.
# You should not implement it, or speculate about its implementation
# """
# class HtmlParser(object):
#    def getUrls(self, url):
#        """
#        :type url: str
#        :rtype List[str]
#        """


class Solution:
    def crawl(self, startUrl: str, htmlParser: 'HtmlParser') -> List[str]:
        def host(url):
            url = url[7:]
            return url.split('/')[0]

        def dfs(url):
            if url in ans:
                return
            ans.add(url)
            for next in htmlParser.getUrls(url):
                if host(url) == host(next):
                    dfs(next)

        ans = set()
        dfs(startUrl)
        return list(ans)
```
{{% /tab %}}
{{% tab "java" %}}
```java
/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface HtmlParser {
 *     public List<String> getUrls(String url) {}
 * }
 */

class Solution {
    private Set<String> ans;

    public List<String> crawl(String startUrl, HtmlParser htmlParser) {
        ans = new HashSet<>();
        dfs(startUrl, htmlParser);
        return new ArrayList<>(ans);
    }

    private void dfs(String url, HtmlParser htmlParser) {
        if (ans.contains(url)) {
            return;
        }
        ans.add(url);
        for (String next : htmlParser.getUrls(url)) {
            if (host(next).equals(host(url))) {
                dfs(next, htmlParser);
            }
        }
    }

    private String host(String url) {
        url = url.substring(7);
        return url.split("/")[0];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */

class Solution {
public:
    vector<string> ans;
    unordered_set<string> vis;

    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        dfs(startUrl, htmlParser);
        return ans;
    }

    void dfs(string& url, HtmlParser& htmlParser) {
        if (vis.count(url)) return;
        vis.insert(url);
        ans.push_back(url);
        for (string next : htmlParser.getUrls(url))
            if (host(url) == host(next))
                dfs(next, htmlParser);
    }

    string host(string url) {
        int i = 7;
        string res;
        for (; i < url.size(); ++i) {
            if (url[i] == '/') break;
            res += url[i];
        }
        return res;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
/**
 * // This is HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * type HtmlParser struct {
 *     func GetUrls(url string) []string {}
 * }
 */

func crawl(startUrl string, htmlParser HtmlParser) []string {
	var ans []string
	vis := make(map[string]bool)
	var dfs func(url string)
	host := func(url string) string {
		return strings.Split(url[7:], "/")[0]
	}
	dfs = func(url string) {
		if vis[url] {
			return
		}
		vis[url] = true
		ans = append(ans, url)
		for _, next := range htmlParser.GetUrls(url) {
			if host(next) == host(url) {
				dfs(next)
			}
		}
	}
	dfs(startUrl)
	return ans
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个网址&nbsp;<code>startUrl</code> 和一个接口&nbsp;<code>HtmlParser</code>&nbsp;，请你实现一个网络爬虫，以实现爬取同&nbsp;<code>startUrl</code>&nbsp;拥有相同&nbsp;<strong>主机名&nbsp;</strong>的全部链接。</p>

<p>该爬虫得到的全部网址可以&nbsp;<strong>任何顺序&nbsp;</strong>返回结果。</p>

<p>你的网络爬虫应当按照如下模式工作：</p>

<ul>
	<li>自页面&nbsp;<code>startUrl</code>&nbsp;开始爬取</li>
	<li>调用&nbsp;<code>HtmlParser.getUrls(url)</code>&nbsp;来获得给定&nbsp;<code>url</code>&nbsp;网址中的全部链接</li>
	<li>同一个链接最多只爬取一次</li>
	<li>只浏览&nbsp;<strong>域名&nbsp;</strong>与<strong>&nbsp;</strong><code>startUrl</code>&nbsp;<strong>相同&nbsp;</strong>的链接集合</li>
</ul>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1200-1299/1236.Web%20Crawler/images/urlhostname.png" style="height: 164px; width: 600px;" /></p>

<p>如上所示的一个网址，其域名为&nbsp;<code>example.org</code>。简单起见，你可以假设所有的网址都采用&nbsp;<strong>http协议&nbsp;</strong>并没有指定&nbsp;<strong>端口</strong>。例如，网址&nbsp;<code>http://leetcode.com/problems</code>&nbsp;和&nbsp;<code>http://leetcode.com/contest</code>&nbsp;是同一个域名下的，而网址&nbsp;<code>http://example.org/test</code>&nbsp;和&nbsp;<code>http://example.com/abc</code> 是不在同一域名下的。</p>

<p><code>HtmlParser</code> 接口定义如下：&nbsp;</p>

<pre>
interface HtmlParser {
  // 返回给定 url 对应的页面中的全部 url 。
  public List&lt;String&gt; getUrls(String url);
}</pre>

<p>下面是两个实例，用以解释该问题的设计功能，对于自定义测试，你可以使用三个变量&nbsp;&nbsp;<code>urls</code>,&nbsp;<code>edges</code>&nbsp;和&nbsp;<code>startUrl</code>。注意在代码实现中，你只可以访问&nbsp;<code>startUrl</code>&nbsp;，而&nbsp;<code>urls</code>&nbsp;和&nbsp;<code>edges</code>&nbsp;不可以在你的代码中被直接访问。</p>

<p>注意：将尾随斜线“/”的相同网址视为不同的网址。例如，“http://news.yahoo.com” 和 “http://news.yahoo.com/” 是不同的网址。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1200-1299/1236.Web%20Crawler/images/sample_2_1497.png" style="height: 300px; width: 610px;" /></p>

<pre>
<strong>输入：
</strong>urls = [
&nbsp; "http://news.yahoo.com",
&nbsp; "http://news.yahoo.com/news",
&nbsp; "http://news.yahoo.com/news/topics/",
&nbsp; "http://news.google.com",
&nbsp; "http://news.yahoo.com/us"
]
edges = [[2,0],[2,1],[3,2],[3,1],[0,4]]
startUrl = "http://news.yahoo.com/news/topics/"
<strong>输出：</strong>[
&nbsp; "http://news.yahoo.com",
&nbsp; "http://news.yahoo.com/news",
&nbsp; "http://news.yahoo.com/news/topics/",
&nbsp; "http://news.yahoo.com/us"
]
</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1200-1299/1236.Web%20Crawler/images/sample_3_1497.png" style="height: 270px; width: 540px;" /></strong></p>

<pre>
<strong>输入：</strong>
urls = [
&nbsp; "http://news.yahoo.com",
&nbsp; "http://news.yahoo.com/news",
&nbsp; "http://news.yahoo.com/news/topics/",
&nbsp; "http://news.google.com"
]
edges = [[0,2],[2,1],[3,2],[3,1],[3,0]]
startUrl = "http://news.google.com"
<strong>输出：</strong>["http://news.google.com"]
<strong>解释：</strong>startUrl 链接到所有其他不共享相同主机名的页面。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= urls.length &lt;= 1000</code></li>
	<li><code>1 &lt;= urls[i].length &lt;= 300</code></li>
	<li><code>startUrl</code>&nbsp;为&nbsp;<code>urls</code>&nbsp;中的一个。</li>
	<li>主机名的长为1到63个字符（包括点），只能包含从‘a’到‘z’的ASCII字母、‘0’到‘9’的数字以及连字符即减号（‘-’）。</li>
	<li>主机名不会以连字符即减号（‘-’）开头或结尾。</li>
	<li>关于域名有效性的约束可参考:&nbsp;&nbsp;<a href="https://en.wikipedia.org/wiki/Hostname#Restrictions_on_valid_hostnames">https://en.wikipedia.org/wiki/Hostname#Restrictions_on_valid_hostnames</a></li>
	<li>你可以假定url库中不包含重复项。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一

<!-- tabs:start -->

#### Python3

```python
# """
# This is HtmlParser's API interface.
# You should not implement it, or speculate about its implementation
# """
# class HtmlParser(object):
#    def getUrls(self, url):
#        """
#        :type url: str
#        :rtype List[str]
#        """


class Solution:
    def crawl(self, startUrl: str, htmlParser: 'HtmlParser') -> List[str]:
        def host(url):
            url = url[7:]
            return url.split('/')[0]

        def dfs(url):
            if url in ans:
                return
            ans.add(url)
            for next in htmlParser.getUrls(url):
                if host(url) == host(next):
                    dfs(next)

        ans = set()
        dfs(startUrl)
        return list(ans)
```

#### Java

```java
/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface HtmlParser {
 *     public List<String> getUrls(String url) {}
 * }
 */

class Solution {
    private Set<String> ans;

    public List<String> crawl(String startUrl, HtmlParser htmlParser) {
        ans = new HashSet<>();
        dfs(startUrl, htmlParser);
        return new ArrayList<>(ans);
    }

    private void dfs(String url, HtmlParser htmlParser) {
        if (ans.contains(url)) {
            return;
        }
        ans.add(url);
        for (String next : htmlParser.getUrls(url)) {
            if (host(next).equals(host(url))) {
                dfs(next, htmlParser);
            }
        }
    }

    private String host(String url) {
        url = url.substring(7);
        return url.split("/")[0];
    }
}
```

#### C++

```cpp
/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */

class Solution {
public:
    vector<string> ans;
    unordered_set<string> vis;

    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        dfs(startUrl, htmlParser);
        return ans;
    }

    void dfs(string& url, HtmlParser& htmlParser) {
        if (vis.count(url)) return;
        vis.insert(url);
        ans.push_back(url);
        for (string next : htmlParser.getUrls(url))
            if (host(url) == host(next))
                dfs(next, htmlParser);
    }

    string host(string url) {
        int i = 7;
        string res;
        for (; i < url.size(); ++i) {
            if (url[i] == '/') break;
            res += url[i];
        }
        return res;
    }
};
```

#### Go

```go
/**
 * // This is HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * type HtmlParser struct {
 *     func GetUrls(url string) []string {}
 * }
 */

func crawl(startUrl string, htmlParser HtmlParser) []string {
	var ans []string
	vis := make(map[string]bool)
	var dfs func(url string)
	host := func(url string) string {
		return strings.Split(url[7:], "/")[0]
	}
	dfs = func(url string) {
		if vis[url] {
			return
		}
		vis[url] = true
		ans = append(ans, url)
		for _, next := range htmlParser.GetUrls(url) {
			if host(next) == host(url) {
				dfs(next)
			}
		}
	}
	dfs(startUrl)
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1237. 找出给定方程的正整数解](https://leetcode.cn/problems/find-positive-integer-solution-for-a-given-equation){#1237}

{{< tabs "1237" >}}

{{% tab "python" %}}
```python
"""
   This is the custom function interface.
   You should not implement it, or speculate about its implementation
   class CustomFunction:
       # Returns f(x, y) for any given positive integers x and y.
       # Note that f(x, y) is increasing with respect to both x and y.
       # i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
       def f(self, x, y):

"""


class Solution:
    def findSolution(self, customfunction: "CustomFunction", z: int) -> List[List[int]]:
        ans = []
        x, y = 1, 1000
        while x <= 1000 and y:
            t = customfunction.f(x, y)
            if t < z:
                x += 1
            elif t > z:
                y -= 1
            else:
                ans.append([x, y])
                x, y = x + 1, y - 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     public int f(int x, int y);
 * };
 */

class Solution {
    public List<List<Integer>> findSolution(CustomFunction customfunction, int z) {
        List<List<Integer>> ans = new ArrayList<>();
        int x = 1, y = 1000;
        while (x <= 1000 && y > 0) {
            int t = customfunction.f(x, y);
            if (t < z) {
                x++;
            } else if (t > z) {
                y--;
            } else {
                ans.add(Arrays.asList(x++, y--));
            }
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>> ans;
        int x = 1, y = 1000;
        while (x <= 1000 && y) {
            int t = customfunction.f(x, y);
            if (t < z) {
                x++;
            } else if (t > z) {
                y--;
            } else {
                ans.push_back({x++, y--});
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
/**
 * This is the declaration of customFunction API.
 * @param  x    int
 * @param  x    int
 * @return 	    Returns f(x, y) for any given positive integers x and y.
 *			    Note that f(x, y) is increasing with respect to both x and y.
 *              i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 */

func findSolution(customFunction func(int, int) int, z int) (ans [][]int) {
	x, y := 1, 1000
	for x <= 1000 && y > 0 {
		t := customFunction(x, y)
		if t < z {
			x++
		} else if t > z {
			y--
		} else {
			ans = append(ans, []int{x, y})
			x, y = x+1, y-1
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
/**
 * // This is the CustomFunction's API interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 *      f(x: number, y: number): number {}
 * }
 */

function findSolution(customfunction: CustomFunction, z: number): number[][] {
    let x = 1;
    let y = 1000;
    const ans: number[][] = [];
    while (x <= 1000 && y) {
        const t = customfunction.f(x, y);
        if (t < z) {
            ++x;
        } else if (t > z) {
            --y;
        } else {
            ans.push([x--, y--]);
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

<p>给你一个函数  <code>f(x, y)</code> 和一个目标结果 <code>z</code>，函数公式未知，请你计算方程 <code>f(x,y) == z</code> 所有可能的正整数 <strong>数对</strong> <code>x</code> 和 <code>y</code>。满足条件的结果数对可以按任意顺序返回。</p>

<p>尽管函数的具体式子未知，但它是单调递增函数，也就是说：</p>

<ul>
	<li><code>f(x, y) < f(x + 1, y)</code></li>
	<li><code>f(x, y) < f(x, y + 1)</code></li>
</ul>

<p>函数接口定义如下：</p>

<pre>
interface CustomFunction {
public:
  // Returns some positive integer f(x, y) for two positive integers x and y based on a formula.
  int f(int x, int y);
};</pre>

<p>你的解决方案将按如下规则进行评判：</p>

<ul>
	<li>判题程序有一个由 <code>CustomFunction</code> 的 <code>9</code> 种实现组成的列表，以及一种为特定的 <code>z</code> 生成所有有效数对的答案的方法。</li>
	<li>判题程序接受两个输入：<code>function_id</code>（决定使用哪种实现测试你的代码）以及目标结果 <code>z</code> 。</li>
	<li>判题程序将会调用你实现的 <code>findSolution</code> 并将你的结果与答案进行比较。</li>
	<li>如果你的结果与答案相符，那么解决方案将被视作正确答案，即 <code>Accepted</code> 。</li>
</ul>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>function_id = 1, z = 5
<strong>输出：</strong>[[1,4],[2,3],[3,2],[4,1]]
<strong>解释：</strong>function_id = 1 暗含的函数式子为 f(x, y) = x + y
以下 x 和 y 满足 f(x, y) 等于 5：
x=1, y=4 -> f(1, 4) = 1 + 4 = 5
x=2, y=3 -> f(2, 3) = 2 + 3 = 5
x=3, y=2 -> f(3, 2) = 3 + 2 = 5
x=4, y=1 -> f(4, 1) = 4 + 1 = 5
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>function_id = 2, z = 5
<strong>输出：</strong>[[1,5],[5,1]]
<strong>解释：</strong>function_id = 2 暗含的函数式子为 f(x, y) = x * y
以下 x 和 y 满足 f(x, y) 等于 5：
x=1, y=5 -> f(1, 5) = 1 * 5 = 5
x=5, y=1 -> f(5, 1) = 5 * 1 = 5</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= function_id <= 9</code></li>
	<li><code>1 <= z <= 100</code></li>
	<li>题目保证 <code>f(x, y) == z</code> 的解处于 <code>1 <= x, y <= 1000</code> 的范围内。</li>
	<li>在 <code>1 <= x, y <= 1000</code> 的前提下，题目保证 <code>f(x, y)</code> 是一个 32 位有符号整数。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举 + 二分查找

根据题目我们可以知道，函数 $f(x, y)$ 是单调递增函数，因此，我们可以枚举 $x$，然后在 $[1,...z]$ 中二分查找 $y$，使得 $f(x, y) = z$。如果找到了，就将 $(x, y)$ 加入答案中。

时间复杂度 $(n \log n)$，其中 $n$ 是 $z$ 的值，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
"""
   This is the custom function interface.
   You should not implement it, or speculate about its implementation
   class CustomFunction:
       # Returns f(x, y) for any given positive integers x and y.
       # Note that f(x, y) is increasing with respect to both x and y.
       # i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
       def f(self, x, y):

"""


class Solution:
    def findSolution(self, customfunction: "CustomFunction", z: int) -> List[List[int]]:
        ans = []
        for x in range(1, z + 1):
            y = 1 + bisect_left(
                range(1, z + 1), z, key=lambda y: customfunction.f(x, y)
            )
            if customfunction.f(x, y) == z:
                ans.append([x, y])
        return ans
```

#### Java

```java
/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     public int f(int x, int y);
 * };
 */

class Solution {
    public List<List<Integer>> findSolution(CustomFunction customfunction, int z) {
        List<List<Integer>> ans = new ArrayList<>();
        for (int x = 1; x <= 1000; ++x) {
            int l = 1, r = 1000;
            while (l < r) {
                int mid = (l + r) >> 1;
                if (customfunction.f(x, mid) >= z) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            if (customfunction.f(x, l) == z) {
                ans.add(Arrays.asList(x, l));
            }
        }
        return ans;
    }
}
```

#### C++

```cpp
/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>> ans;
        for (int x = 1; x <= 1000; ++x) {
            int l = 1, r = 1000;
            while (l < r) {
                int mid = (l + r) >> 1;
                if (customfunction.f(x, mid) >= z) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            if (customfunction.f(x, l) == z) {
                ans.push_back({x, l});
            }
        }
        return ans;
    }
};
```

#### Go

```go
/**
 * This is the declaration of customFunction API.
 * @param  x    int
 * @param  x    int
 * @return 	    Returns f(x, y) for any given positive integers x and y.
 *			    Note that f(x, y) is increasing with respect to both x and y.
 *              i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 */

func findSolution(customFunction func(int, int) int, z int) (ans [][]int) {
	for x := 1; x <= 1000; x++ {
		y := 1 + sort.Search(999, func(y int) bool { return customFunction(x, y+1) >= z })
		if customFunction(x, y) == z {
			ans = append(ans, []int{x, y})
		}
	}
	return
}
```

#### TypeScript

```ts
/**
 * // This is the CustomFunction's API interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 *      f(x: number, y: number): number {}
 * }
 */

function findSolution(customfunction: CustomFunction, z: number): number[][] {
    const ans: number[][] = [];
    for (let x = 1; x <= 1000; ++x) {
        let l = 1;
        let r = 1000;
        while (l < r) {
            const mid = (l + r) >> 1;
            if (customfunction.f(x, mid) >= z) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if (customfunction.f(x, l) == z) {
            ans.push([x, l]);
        }
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：双指针

我们可以定义两个指针 $x$ 和 $y$，初始时 $x = 1$, $y = z$。

-   如果 $f(x, y) = z$，我们将 $(x, y)$ 加入答案中，然后 $x \leftarrow x + 1$, $y \leftarrow y - 1$；
-   如果 $f(x, y) \lt z$，此时对任意的 $y' \lt y$，都有 $f(x, y') \lt f(x, y) \lt z$，因此我们不能将 $y$ 减小，只能将 $x$ 增大，所以 $x \leftarrow x + 1$；
-   如果 $f(x, y) \gt z$，此时对任意的 $x' \gt x$，都有 $f(x', y) \gt f(x, y) \gt z$，因此我们不能将 $x$ 增大，只能将 $y$ 减小，所以 $y \leftarrow y - 1$。

循环结束后，返回答案。

时间复杂度 $O(n)$，其中 $n$ 是 $z$ 的值，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
"""
   This is the custom function interface.
   You should not implement it, or speculate about its implementation
   class CustomFunction:
       # Returns f(x, y) for any given positive integers x and y.
       # Note that f(x, y) is increasing with respect to both x and y.
       # i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
       def f(self, x, y):

"""


class Solution:
    def findSolution(self, customfunction: "CustomFunction", z: int) -> List[List[int]]:
        ans = []
        x, y = 1, 1000
        while x <= 1000 and y:
            t = customfunction.f(x, y)
            if t < z:
                x += 1
            elif t > z:
                y -= 1
            else:
                ans.append([x, y])
                x, y = x + 1, y - 1
        return ans
```

#### Java

```java
/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     public int f(int x, int y);
 * };
 */

class Solution {
    public List<List<Integer>> findSolution(CustomFunction customfunction, int z) {
        List<List<Integer>> ans = new ArrayList<>();
        int x = 1, y = 1000;
        while (x <= 1000 && y > 0) {
            int t = customfunction.f(x, y);
            if (t < z) {
                x++;
            } else if (t > z) {
                y--;
            } else {
                ans.add(Arrays.asList(x++, y--));
            }
        }
        return ans;
    }
}
```

#### C++

```cpp
/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>> ans;
        int x = 1, y = 1000;
        while (x <= 1000 && y) {
            int t = customfunction.f(x, y);
            if (t < z) {
                x++;
            } else if (t > z) {
                y--;
            } else {
                ans.push_back({x++, y--});
            }
        }
        return ans;
    }
};
```

#### Go

```go
/**
 * This is the declaration of customFunction API.
 * @param  x    int
 * @param  x    int
 * @return 	    Returns f(x, y) for any given positive integers x and y.
 *			    Note that f(x, y) is increasing with respect to both x and y.
 *              i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 */

func findSolution(customFunction func(int, int) int, z int) (ans [][]int) {
	x, y := 1, 1000
	for x <= 1000 && y > 0 {
		t := customFunction(x, y)
		if t < z {
			x++
		} else if t > z {
			y--
		} else {
			ans = append(ans, []int{x, y})
			x, y = x+1, y-1
		}
	}
	return
}
```

#### TypeScript

```ts
/**
 * // This is the CustomFunction's API interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 *      f(x: number, y: number): number {}
 * }
 */

function findSolution(customfunction: CustomFunction, z: number): number[][] {
    let x = 1;
    let y = 1000;
    const ans: number[][] = [];
    while (x <= 1000 && y) {
        const t = customfunction.f(x, y);
        if (t < z) {
            ++x;
        } else if (t > z) {
            --y;
        } else {
            ans.push([x--, y--]);
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

# [1238. 循环码排列](https://leetcode.cn/problems/circular-permutation-in-binary-representation){#1238}

{{< tabs "1238" >}}

{{% tab "java" %}}
```java
class Solution {
    public List<Integer> circularPermutation(int n, int start) {
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < 1 << n; ++i) {
            ans.add(i ^ (i >> 1) ^ start);
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "python" %}}
```python
class Solution:
    def circularPermutation(self, n: int, start: int) -> List[int]:
        return [i ^ (i >> 1) ^ start for i in range(1 << n)]
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> ans(1 << n);
        for (int i = 0; i < 1 << n; ++i) {
            ans[i] = i ^ (i >> 1) ^ start;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func circularPermutation(n int, start int) (ans []int) {
	for i := 0; i < 1<<n; i++ {
		ans = append(ans, i^(i>>1)^start)
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function circularPermutation(n: number, start: number): number[] {
    const ans: number[] = [];
    for (let i = 0; i < 1 << n; ++i) {
        ans.push(i ^ (i >> 1) ^ start);
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

<p>给你两个整数&nbsp;<code>n</code> 和 <code>start</code>。你的任务是返回任意 <code>(0,1,2,,...,2^n-1)</code> 的排列 <code>p</code>，并且满足：</p>

<ul>
	<li><code>p[0] = start</code></li>
	<li><code>p[i]</code> 和 <code>p[i+1]</code>&nbsp;的二进制表示形式只有一位不同</li>
	<li><code>p[0]</code> 和 <code>p[2^n -1]</code>&nbsp;的二进制表示形式也只有一位不同</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 2, start = 3
<strong>输出：</strong>[3,2,0,1]
<strong>解释：</strong>这个排列的二进制表示是 (11,10,00,01)
     所有的相邻元素都有一位是不同的，另一个有效的排列是 [3,1,0,2]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 3, start = 2
<strong>输出：</strong>[2,6,7,5,4,0,1,3]
<strong>解释：</strong>这个排列的二进制表示是 (010,110,111,101,100,000,001,011)
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 16</code></li>
	<li><code>0 &lt;= start&nbsp;&lt;&nbsp;2^n</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二进制码转格雷码

我们观察题目中的排列，可以发现，它的二进制表示中，任意两个（包括首尾）相邻的数只有一位二进制数不同。这种编码方式就是格雷码，它是我们在工程中会遇到的一种编码方式。

二进制码转换成二进制格雷码，其法则是保留二进制码的最高位作为格雷码的最高位，而次高位格雷码为二进制码的高位与次高位相异或，而格雷码其余各位与次高位的求法相类似。

假设某个二进制数表示为 $B_{n-1}B_{n-2}...B_2B_1B_0$，其格雷码表示为 $G_{n-1}G_{n-2}...G_2G_1G_0$。最高位保留，所以 $G_{n-1} = B_{n-1}$；而其它各位 $G_i = B_{i+1} \oplus B_{i}$，其中 $i=0,1,2..,n-2$。

因此，对于一个整数 $x$，我们可以用函数 $gray(x)$ 得到其格雷码：

```java
int gray(x) {
    return x ^ (x >> 1);
}
```

我们可以直接将 $[0,..2^n - 1]$ 这些整数转换成对应的格雷码数组，然后找到 $start$ 在格雷码数组中的位置，将格雷码数组从该位置开始截取，再将截取的部分拼接到格雷码数组的前面，就得到了题目要求的排列。

时间复杂度 $O(2^n)$，空间复杂度 $O(2^n)$。其中 $n$ 为题目给定的整数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def circularPermutation(self, n: int, start: int) -> List[int]:
        g = [i ^ (i >> 1) for i in range(1 << n)]
        j = g.index(start)
        return g[j:] + g[:j]
```

#### Java

```java
class Solution {
    public List<Integer> circularPermutation(int n, int start) {
        int[] g = new int[1 << n];
        int j = 0;
        for (int i = 0; i < 1 << n; ++i) {
            g[i] = i ^ (i >> 1);
            if (g[i] == start) {
                j = i;
            }
        }
        List<Integer> ans = new ArrayList<>();
        for (int i = j; i < j + (1 << n); ++i) {
            ans.add(g[i % (1 << n)]);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        int g[1 << n];
        int j = 0;
        for (int i = 0; i < 1 << n; ++i) {
            g[i] = i ^ (i >> 1);
            if (g[i] == start) {
                j = i;
            }
        }
        vector<int> ans;
        for (int i = j; i < j + (1 << n); ++i) {
            ans.push_back(g[i % (1 << n)]);
        }
        return ans;
    }
};
```

#### Go

```go
func circularPermutation(n int, start int) []int {
	g := make([]int, 1<<n)
	j := 0
	for i := range g {
		g[i] = i ^ (i >> 1)
		if g[i] == start {
			j = i
		}
	}
	return append(g[j:], g[:j]...)
}
```

#### TypeScript

```ts
function circularPermutation(n: number, start: number): number[] {
    const ans: number[] = [];
    for (let i = 0; i < 1 << n; ++i) {
        ans.push(i ^ (i >> 1) ^ start);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：转换优化

由于 $gray(0) = 0$，那么 $gray(0) \oplus start = start$，而 $gray(i)$ 与 $gray(i-1)$ 只有一个二进制位不同，所以 $gray(i) \oplus start$ 与 $gray(i-1) \oplus start$ 也只有一个二进制位不同。

因此，我们也可以直接将 $[0,..2^n - 1]$ 这些整数转换成对应的 $gray(i) \oplus start$，即可得到首项为 $start$ 的格雷码排列。

时间复杂度 $O(2^n)$，其中 $n$ 为题目给定的整数。忽略答案的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def circularPermutation(self, n: int, start: int) -> List[int]:
        return [i ^ (i >> 1) ^ start for i in range(1 << n)]
```

#### Java

```java
class Solution {
    public List<Integer> circularPermutation(int n, int start) {
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < 1 << n; ++i) {
            ans.add(i ^ (i >> 1) ^ start);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> ans(1 << n);
        for (int i = 0; i < 1 << n; ++i) {
            ans[i] = i ^ (i >> 1) ^ start;
        }
        return ans;
    }
};
```

#### Go

```go
func circularPermutation(n int, start int) (ans []int) {
	for i := 0; i < 1<<n; i++ {
		ans = append(ans, i^(i>>1)^start)
	}
	return
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1239. 串联字符串的最大长度](https://leetcode.cn/problems/maximum-length-of-a-concatenated-string-with-unique-characters){#1239}

{{< tabs "1239" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxLength(self, arr: List[str]) -> int:
        s = [0]
        for t in arr:
            x = 0
            for b in map(lambda c: ord(c) - 97, t):
                if x >> b & 1:
                    x = 0
                    break
                x |= 1 << b
            if x:
                s.extend((x | y) for y in s if (x & y) == 0)
        return max(x.bit_count() for x in s)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxLength(List<String> arr) {
        List<Integer> s = new ArrayList<>();
        s.add(0);
        int ans = 0;
        for (var t : arr) {
            int x = 0;
            for (char c : t.toCharArray()) {
                int b = c - 'a';
                if ((x >> b & 1) == 1) {
                    x = 0;
                    break;
                }
                x |= 1 << b;
            }
            if (x > 0) {
                for (int i = s.size() - 1; i >= 0; --i) {
                    int y = s.get(i);
                    if ((x & y) == 0) {
                        s.add(x | y);
                        ans = Math.max(ans, Integer.bitCount(x | y));
                    }
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
    int maxLength(vector<string>& arr) {
        vector<int> s = {0};
        int ans = 0;
        for (const string& t : arr) {
            int x = 0;
            for (char c : t) {
                int b = c - 'a';
                if ((x >> b & 1) == 1) {
                    x = 0;
                    break;
                }
                x |= 1 << b;
            }
            if (x > 0) {
                for (int i = s.size() - 1; i >= 0; --i) {
                    int y = s[i];
                    if ((x & y) == 0) {
                        s.push_back(x | y);
                        ans = max(ans, __builtin_popcount(x | y));
                    }
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
func maxLength(arr []string) (ans int) {
	s := []int{0}
	for _, t := range arr {
		x := 0
		for _, c := range t {
			b := int(c - 'a')
			if (x>>b)&1 == 1 {
				x = 0
				break
			}
			x |= 1 << b
		}
		if x > 0 {
			for i := len(s) - 1; i >= 0; i-- {
				y := s[i]
				if (x & y) == 0 {
					s = append(s, x|y)
					ans = max(ans, bits.OnesCount(uint(x|y)))
				}
			}
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxLength(arr: string[]): number {
    const s: number[] = [0];
    let ans = 0;
    for (const t of arr) {
        let x = 0;
        for (const c of t) {
            const b = c.charCodeAt(0) - 97;
            if ((x >> b) & 1) {
                x = 0;
                break;
            }
            x |= 1 << b;
        }

        if (x > 0) {
            for (let i = s.length - 1; ~i; --i) {
                const y = s[i];
                if ((x & y) === 0) {
                    s.push(x | y);
                    ans = Math.max(ans, bitCount(x | y));
                }
            }
        }
    }

    return ans;
}

function bitCount(i: number): number {
    i = i - ((i >>> 1) & 0x55555555);
    i = (i & 0x33333333) + ((i >>> 2) & 0x33333333);
    i = (i + (i >>> 4)) & 0x0f0f0f0f;
    i = i + (i >>> 8);
    i = i + (i >>> 16);
    return i & 0x3f;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个字符串数组 <code>arr</code>，字符串 <code>s</code> 是将 <code>arr</code>&nbsp;的含有 <strong>不同字母</strong> 的&nbsp;<strong>子序列</strong> 字符串 <strong>连接</strong> 所得的字符串。</p>

<p>请返回所有可行解 <code>s</code> 中最长长度。</p>

<p><strong>子序列</strong> 是一种可以从另一个数组派生而来的数组，通过删除某些元素或不删除元素而不改变其余元素的顺序。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>arr = ["un","iq","ue"]
<strong>输出：</strong>4
<strong>解释：</strong>所有可能的串联组合是：
- ""
- "un"
- "iq"
- "ue"
- "uniq" ("un" + "iq")
- "ique" ("iq" + "ue")
最大长度为 4。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>arr = ["cha","r","act","ers"]
<strong>输出：</strong>6
<strong>解释：</strong>可能的解答有 "chaers" 和 "acters"。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>arr = ["abcdefghijklmnopqrstuvwxyz"]
<strong>输出：</strong>26
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 16</code></li>
	<li><code>1 &lt;= arr[i].length &lt;= 26</code></li>
	<li><code>arr[i]</code>&nbsp;中只含有小写英文字母</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：状态压缩 + 位运算

由于题目要求子序列的字符不能重复，字符都是小写字母，因此，我们可以用一个长度为 $26$ 的二进制整数来表示一个子序列，其中第 $i$ 位为 $1$ 表示子序列中含有滴 $i$ 个字符，为 $0$ 表示不含有第 $i$ 个字符。

我们可以用一个数组 $s$ 来存储所有满足条件的子序列的状态，初始时 $s$ 中只有一个元素 $0$。

然后我们遍历数组 $\textit{arr}$，对于每个字符串 $t$，我们用一个整数 $x$ 来表示 $t$ 的状态，然后我们遍历数组 $s$，对于每个状态 $y$，如果 $x$ 和 $y$ 之间没有相同的字符，那么我们将 $x$ 和 $y$ 的并集加入到 $s$ 中，并更新答案。

最后我们返回答案即可。

时间复杂度 $O(2^n + L)$，空间复杂度 $O(2^n)$，其中 $n$ 是字符串数组的长度，而 $L$ 是字符串数组中所有字符串的长度之和。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxLength(self, arr: List[str]) -> int:
        s = [0]
        for t in arr:
            x = 0
            for b in map(lambda c: ord(c) - 97, t):
                if x >> b & 1:
                    x = 0
                    break
                x |= 1 << b
            if x:
                s.extend((x | y) for y in s if (x & y) == 0)
        return max(x.bit_count() for x in s)
```

#### Java

```java
class Solution {
    public int maxLength(List<String> arr) {
        List<Integer> s = new ArrayList<>();
        s.add(0);
        int ans = 0;
        for (var t : arr) {
            int x = 0;
            for (char c : t.toCharArray()) {
                int b = c - 'a';
                if ((x >> b & 1) == 1) {
                    x = 0;
                    break;
                }
                x |= 1 << b;
            }
            if (x > 0) {
                for (int i = s.size() - 1; i >= 0; --i) {
                    int y = s.get(i);
                    if ((x & y) == 0) {
                        s.add(x | y);
                        ans = Math.max(ans, Integer.bitCount(x | y));
                    }
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
    int maxLength(vector<string>& arr) {
        vector<int> s = {0};
        int ans = 0;
        for (const string& t : arr) {
            int x = 0;
            for (char c : t) {
                int b = c - 'a';
                if ((x >> b & 1) == 1) {
                    x = 0;
                    break;
                }
                x |= 1 << b;
            }
            if (x > 0) {
                for (int i = s.size() - 1; i >= 0; --i) {
                    int y = s[i];
                    if ((x & y) == 0) {
                        s.push_back(x | y);
                        ans = max(ans, __builtin_popcount(x | y));
                    }
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func maxLength(arr []string) (ans int) {
	s := []int{0}
	for _, t := range arr {
		x := 0
		for _, c := range t {
			b := int(c - 'a')
			if (x>>b)&1 == 1 {
				x = 0
				break
			}
			x |= 1 << b
		}
		if x > 0 {
			for i := len(s) - 1; i >= 0; i-- {
				y := s[i]
				if (x & y) == 0 {
					s = append(s, x|y)
					ans = max(ans, bits.OnesCount(uint(x|y)))
				}
			}
		}
	}
	return ans
}
```

#### TypeScript

```ts
function maxLength(arr: string[]): number {
    const s: number[] = [0];
    let ans = 0;
    for (const t of arr) {
        let x = 0;
        for (const c of t) {
            const b = c.charCodeAt(0) - 97;
            if ((x >> b) & 1) {
                x = 0;
                break;
            }
            x |= 1 << b;
        }

        if (x > 0) {
            for (let i = s.length - 1; ~i; --i) {
                const y = s[i];
                if ((x & y) === 0) {
                    s.push(x | y);
                    ans = Math.max(ans, bitCount(x | y));
                }
            }
        }
    }

    return ans;
}

function bitCount(i: number): number {
    i = i - ((i >>> 1) & 0x55555555);
    i = (i & 0x33333333) + ((i >>> 2) & 0x33333333);
    i = (i + (i >>> 4)) & 0x0f0f0f0f;
    i = i + (i >>> 8);
    i = i + (i >>> 16);
    return i & 0x3f;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
