---
title: "1620_网络信号最好的坐标"
date: 2025-10-08T18:38:12+08:00
weight: 3
tags: [二叉树, 动态规划, 哈希表, 字符串, 并查集, 广度优先搜索, 排序, 数学, 数据库, 数组, 数论, 枚举, 栈, 树, 深度优先搜索, 线段树, 组合数学, 设计]
---

{{< markmap >}}
### [1620_网络信号最好的坐标](#1620)
#### [数组](#1620)
#### [枚举](#1620)
### [1621_大小为 K 的不重叠线段的数目](#1621)
#### [数学](#1621)
#### [动态规划](#1621)
#### [组合数学](#1621)
### [1622_奇妙序列](#1622)
#### [设计](#1622)
#### [线段树](#1622)
#### [数学](#1622)
### [1623_三人国家代表队 🔒](#1623)
#### [数据库](#1623)
### [1624_两个相同字符之间的最长子字符串](#1624)
#### [哈希表](#1624)
#### [字符串](#1624)
### [1625_执行操作后字典序最小的字符串](#1625)
#### [深度优先搜索](#1625)
#### [广度优先搜索](#1625)
#### [字符串](#1625)
#### [枚举](#1625)
### [1626_无矛盾的最佳球队](#1626)
#### [数组](#1626)
#### [动态规划](#1626)
#### [排序](#1626)
### [1627_带阈值的图连通性](#1627)
#### [并查集](#1627)
#### [数组](#1627)
#### [数学](#1627)
#### [数论](#1627)
### [1628_设计带解析函数的表达式树 🔒](#1628)
#### [栈](#1628)
#### [树](#1628)
#### [设计](#1628)
#### [数组](#1628)
#### [数学](#1628)
#### [二叉树](#1628)
### [1629_按键持续时间最长的键](#1629)
#### [数组](#1629)
#### [字符串](#1629)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1620_网络信号最好的坐标
___
#### 数组
___
#### 枚举
---
### 1621_大小为 K 的不重叠线段的数目
___
#### 数学
___
#### 动态规划
___
#### 组合数学
---
### 1622_奇妙序列
___
#### 设计
___
#### 线段树
___
#### 数学
---
### 1623_三人国家代表队 🔒
___
#### 数据库
---
### 1624_两个相同字符之间的最长子字符串
___
#### 哈希表
___
#### 字符串
---
### 1625_执行操作后字典序最小的字符串
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 字符串
___
#### 枚举
---
### 1626_无矛盾的最佳球队
___
#### 数组
___
#### 动态规划
___
#### 排序
---
### 1627_带阈值的图连通性
___
#### 并查集
___
#### 数组
___
#### 数学
___
#### 数论
---
### 1628_设计带解析函数的表达式树 🔒
___
#### 栈
___
#### 树
___
#### 设计
___
#### 数组
___
#### 数学
___
#### 二叉树
---
### 1629_按键持续时间最长的键
___
#### 数组
___
#### 字符串
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二叉树 | 动态规划 | 哈希表 |
| 字符串 | 并查集 | 广度优先搜索 |
| 排序 | 数学 | 数据库 |
| 数组 | 数论 | 枚举 |
| 栈 | 树 | 深度优先搜索 |
| 线段树 | 组合数学 | 设计 |

# [1620. 网络信号最好的坐标](https://leetcode.cn/problems/coordinate-with-maximum-network-quality){#1620}

{{< tabs "1620" >}}

{{% tab "python" %}}
```python
class Solution:
    def bestCoordinate(self, towers: List[List[int]], radius: int) -> List[int]:
        mx = 0
        ans = [0, 0]
        for i in range(51):
            for j in range(51):
                t = 0
                for x, y, q in towers:
                    d = ((x - i) ** 2 + (y - j) ** 2) ** 0.5
                    if d <= radius:
                        t += floor(q / (1 + d))
                if t > mx:
                    mx = t
                    ans = [i, j]
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] bestCoordinate(int[][] towers, int radius) {
        int mx = 0;
        int[] ans = new int[] {0, 0};
        for (int i = 0; i < 51; ++i) {
            for (int j = 0; j < 51; ++j) {
                int t = 0;
                for (var e : towers) {
                    double d = Math.sqrt((i - e[0]) * (i - e[0]) + (j - e[1]) * (j - e[1]));
                    if (d <= radius) {
                        t += Math.floor(e[2] / (1 + d));
                    }
                }
                if (mx < t) {
                    mx = t;
                    ans = new int[] {i, j};
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
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        int mx = 0;
        vector<int> ans = {0, 0};
        for (int i = 0; i < 51; ++i) {
            for (int j = 0; j < 51; ++j) {
                int t = 0;
                for (auto& e : towers) {
                    double d = sqrt((i - e[0]) * (i - e[0]) + (j - e[1]) * (j - e[1]));
                    if (d <= radius) {
                        t += floor(e[2] / (1 + d));
                    }
                }
                if (mx < t) {
                    mx = t;
                    ans = {i, j};
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
func bestCoordinate(towers [][]int, radius int) []int {
	ans := []int{0, 0}
	mx := 0
	for i := 0; i < 51; i++ {
		for j := 0; j < 51; j++ {
			t := 0
			for _, e := range towers {
				d := math.Sqrt(float64((i-e[0])*(i-e[0]) + (j-e[1])*(j-e[1])))
				if d <= float64(radius) {
					t += int(float64(e[2]) / (1 + d))
				}
			}
			if mx < t {
				mx = t
				ans = []int{i, j}
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

<p>给你一个数组 <code>towers</code>&nbsp;和一个整数 <code>radius</code> 。</p>

<p>数组&nbsp; <code>towers</code>&nbsp; 中包含一些网络信号塔，其中&nbsp;<code>towers[i] = [x<sub>i</sub>, y<sub>i</sub>, q<sub>i</sub>]</code>&nbsp;表示第&nbsp;<code>i</code>&nbsp;个网络信号塔的坐标是&nbsp;<code>(x<sub>i</sub>, y<sub>i</sub>)</code>&nbsp;且信号强度参数为&nbsp;<code>q<sub>i</sub></code><sub>&nbsp;</sub>。所有坐标都是在&nbsp; X-Y 坐标系内的&nbsp;<strong>整数</strong>&nbsp;坐标。两个坐标之间的距离用 <strong>欧几里得距离</strong>&nbsp;计算。</p>

<p>整数&nbsp;<code>radius</code>&nbsp;表示一个塔 <strong>能到达&nbsp;</strong>的 <strong>最远距离</strong>&nbsp;。如果一个坐标跟塔的距离在 <code>radius</code>&nbsp;以内，那么该塔的信号可以到达该坐标。在这个范围以外信号会很微弱，所以 <code>radius</code>&nbsp;以外的距离该塔是 <strong>不能到达的</strong>&nbsp;。</p>

<p>如果第 <code>i</code>&nbsp;个塔能到达 <code>(x, y)</code>&nbsp;，那么该塔在此处的信号为&nbsp;<code>⌊q<sub>i</sub> / (1 + d)⌋</code>&nbsp;，其中&nbsp;<code>d</code>&nbsp;是塔跟此坐标的距离。一个坐标的 <b>信号强度</b> 是所有 <strong>能到达&nbsp;</strong>该坐标的塔的信号强度之和。</p>

<p>请你返回数组 <code>[c<sub>x</sub>, c<sub>y</sub>]</code> ，表示 <strong>信号强度</strong> 最大的 <strong>整数</strong> 坐标点&nbsp;<code>(c<sub>x</sub>, c<sub>y</sub>)</code> 。如果有多个坐标网络信号一样大，请你返回字典序最小的 <strong>非负</strong> 坐标。</p>

<p><strong>注意：</strong></p>

<ul>
	<li>坐标&nbsp;<code>(x1, y1)</code>&nbsp;字典序比另一个坐标&nbsp;<code>(x2, y2)</code> 小，需满足以下条件之一：

    <ul>
    	<li>要么&nbsp;<code>x1 &lt; x2</code>&nbsp;，</li>
    	<li>要么&nbsp;<code>x1 == x2</code> 且&nbsp;<code>y1 &lt; y2</code>&nbsp;。</li>
    </ul>
    </li>
    <li><code>⌊val⌋</code>&nbsp;表示小于等于&nbsp;<code>val</code>&nbsp;的最大整数（向下取整函数）。</li>

</ul>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1600-1699/1620.Coordinate%20With%20Maximum%20Network%20Quality/images/untitled-diagram.png" style="width: 176px; height: 176px;" />
<pre>
<b>输入：</b>towers = [[1,2,5],[2,1,7],[3,1,9]], radius = 2
<b>输出：</b>[2,1]
<strong>解释：</strong>
坐标 (2, 1) 信号强度之和为 13
- 塔 (2, 1) 强度参数为 7 ，在该点强度为 ⌊7 / (1 + sqrt(0)⌋ = ⌊7⌋ = 7
- 塔 (1, 2) 强度参数为 5 ，在该点强度为 ⌊5 / (1 + sqrt(2)⌋ = ⌊2.07⌋ = 2
- 塔 (3, 1) 强度参数为 9 ，在该点强度为 ⌊9 / (1 + sqrt(1)⌋ = ⌊4.5⌋ = 4
没有别的坐标有更大的信号强度。</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>towers = [[23,11,21]], radius = 9
<b>输出：</b>[23,11]
<strong>解释：</strong>由于仅存在一座信号塔，所以塔的位置信号强度最大。</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>towers = [[1,2,13],[2,1,7],[0,1,9]], radius = 2
<b>输出：</b>[1,2]
<strong>解释：</strong>坐标 (1, 2) 的信号强度最大。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= towers.length &lt;= 50</code></li>
	<li><code>towers[i].length == 3</code></li>
	<li><code>0 &lt;= x<sub>i</sub>, y<sub>i</sub>, q<sub>i</sub> &lt;= 50</code></li>
	<li><code>1 &lt;= radius &lt;= 50</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：暴力枚举

由于坐标点的范围是 $[0,.. 50]$，因此我们可以直接暴力枚举所有的坐标点 $(i, j)$，计算每个坐标点的信号强度，然后找出信号强度最大的坐标点。

时间复杂度 $O(n \times C^2)$，其中 $n$ 是信号塔的数量，而 $C$ 是坐标点的范围大小。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def bestCoordinate(self, towers: List[List[int]], radius: int) -> List[int]:
        mx = 0
        ans = [0, 0]
        for i in range(51):
            for j in range(51):
                t = 0
                for x, y, q in towers:
                    d = ((x - i) ** 2 + (y - j) ** 2) ** 0.5
                    if d <= radius:
                        t += floor(q / (1 + d))
                if t > mx:
                    mx = t
                    ans = [i, j]
        return ans
```

#### Java

```java
class Solution {
    public int[] bestCoordinate(int[][] towers, int radius) {
        int mx = 0;
        int[] ans = new int[] {0, 0};
        for (int i = 0; i < 51; ++i) {
            for (int j = 0; j < 51; ++j) {
                int t = 0;
                for (var e : towers) {
                    double d = Math.sqrt((i - e[0]) * (i - e[0]) + (j - e[1]) * (j - e[1]));
                    if (d <= radius) {
                        t += Math.floor(e[2] / (1 + d));
                    }
                }
                if (mx < t) {
                    mx = t;
                    ans = new int[] {i, j};
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
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        int mx = 0;
        vector<int> ans = {0, 0};
        for (int i = 0; i < 51; ++i) {
            for (int j = 0; j < 51; ++j) {
                int t = 0;
                for (auto& e : towers) {
                    double d = sqrt((i - e[0]) * (i - e[0]) + (j - e[1]) * (j - e[1]));
                    if (d <= radius) {
                        t += floor(e[2] / (1 + d));
                    }
                }
                if (mx < t) {
                    mx = t;
                    ans = {i, j};
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func bestCoordinate(towers [][]int, radius int) []int {
	ans := []int{0, 0}
	mx := 0
	for i := 0; i < 51; i++ {
		for j := 0; j < 51; j++ {
			t := 0
			for _, e := range towers {
				d := math.Sqrt(float64((i-e[0])*(i-e[0]) + (j-e[1])*(j-e[1])))
				if d <= float64(radius) {
					t += int(float64(e[2]) / (1 + d))
				}
			}
			if mx < t {
				mx = t
				ans = []int{i, j}
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

# [1621. 大小为 K 的不重叠线段的数目](https://leetcode.cn/problems/number-of-sets-of-k-non-overlapping-line-segments){#1621}

{{< tabs "1621" >}}

{{% tab "python" %}}
```python
class Solution:
    def numberOfSets(self, n: int, k: int) -> int:
        mod = 10**9 + 7
        f = [[0] * (k + 1) for _ in range(n + 1)]
        g = [[0] * (k + 1) for _ in range(n + 1)]
        f[1][0] = 1
        for i in range(2, n + 1):
            for j in range(k + 1):
                f[i][j] = (f[i - 1][j] + g[i - 1][j]) % mod
                g[i][j] = g[i - 1][j]
                if j:
                    g[i][j] += f[i - 1][j - 1]
                    g[i][j] %= mod
                    g[i][j] += g[i - 1][j - 1]
                    g[i][j] %= mod
        return (f[-1][-1] + g[-1][-1]) % mod
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private static final int MOD = (int) 1e9 + 7;

    public int numberOfSets(int n, int k) {
        int[][] f = new int[n + 1][k + 1];
        int[][] g = new int[n + 1][k + 1];
        f[1][0] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j <= k; ++j) {
                f[i][j] = (f[i - 1][j] + g[i - 1][j]) % MOD;
                g[i][j] = g[i - 1][j];
                if (j > 0) {
                    g[i][j] += f[i - 1][j - 1];
                    g[i][j] %= MOD;
                    g[i][j] += g[i - 1][j - 1];
                    g[i][j] %= MOD;
                }
            }
        }
        return (f[n][k] + g[n][k]) % MOD;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int f[1010][1010];
    int g[1010][1010];
    const int mod = 1e9 + 7;

    int numberOfSets(int n, int k) {
        memset(f, 0, sizeof(f));
        memset(g, 0, sizeof(g));
        f[1][0] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j <= k; ++j) {
                f[i][j] = (f[i - 1][j] + g[i - 1][j]) % mod;
                g[i][j] = g[i - 1][j];
                if (j > 0) {
                    g[i][j] += f[i - 1][j - 1];
                    g[i][j] %= mod;
                    g[i][j] += g[i - 1][j - 1];
                    g[i][j] %= mod;
                }
            }
        }
        return (f[n][k] + g[n][k]) % mod;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numberOfSets(n int, k int) int {
	f := make([][]int, n+1)
	g := make([][]int, n+1)
	for i := range f {
		f[i] = make([]int, k+1)
		g[i] = make([]int, k+1)
	}
	f[1][0] = 1
	var mod int = 1e9 + 7
	for i := 2; i <= n; i++ {
		for j := 0; j <= k; j++ {
			f[i][j] = (f[i-1][j] + g[i-1][j]) % mod
			g[i][j] = g[i-1][j]
			if j > 0 {
				g[i][j] += f[i-1][j-1]
				g[i][j] %= mod
				g[i][j] += g[i-1][j-1]
				g[i][j] %= mod
			}
		}
	}
	return (f[n][k] + g[n][k]) % mod
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numberOfSets(n: number, k: number): number {
    const f = Array.from({ length: n + 1 }, _ => new Array(k + 1).fill(0));
    const g = Array.from({ length: n + 1 }, _ => new Array(k + 1).fill(0));
    f[1][0] = 1;
    const mod = 10 ** 9 + 7;
    for (let i = 2; i <= n; ++i) {
        for (let j = 0; j <= k; ++j) {
            f[i][j] = (f[i - 1][j] + g[i - 1][j]) % mod;
            g[i][j] = g[i - 1][j];
            if (j) {
                g[i][j] += f[i - 1][j - 1];
                g[i][j] %= mod;
                g[i][j] += g[i - 1][j - 1];
                g[i][j] %= mod;
            }
        }
    }
    return (f[n][k] + g[n][k]) % mod;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一维空间的 <code>n</code> 个点，其中第 <code>i</code> 个点（编号从 <code>0</code> 到 <code>n-1</code>）位于 <code>x = i</code> 处，请你找到 <strong>恰好</strong> <code>k</code> <strong>个不重叠</strong> 线段且每个线段至少覆盖两个点的方案数。线段的两个端点必须都是 <strong>整数坐标</strong> 。这 <code>k</code> 个线段不需要全部覆盖全部 <code>n</code> 个点，且它们的端点 <strong>可以 </strong>重合。</p>

<p>请你返回 <code>k</code> 个不重叠线段的方案数。由于答案可能很大，请将结果对 <code>10<sup>9</sup> + 7</code> <strong>取余</strong> 后返回。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1600-1699/1621.Number%20of%20Sets%20of%20K%20Non-Overlapping%20Line%20Segments/images/ex1.png" style="width: 179px; height: 222px;" />
<pre>
<b>输入：</b>n = 4, k = 2
<b>输出：</b>5
<strong>解释：
</strong>如图所示，两个线段分别用红色和蓝色标出。
上图展示了 5 种不同的方案 {(0,2),(2,3)}，{(0,1),(1,3)}，{(0,1),(2,3)}，{(1,2),(2,3)}，{(0,1),(1,2)} 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>n = 3, k = 1
<b>输出：</b>3
<strong>解释：</strong>总共有 3 种不同的方案 {(0,1)}, {(0,2)}, {(1,2)} 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>n = 30, k = 7
<b>输出：</b>796297179
<strong>解释：</strong>画 7 条线段的总方案数为 3796297200 种。将这个数对 10<sup>9</sup> + 7 取余得到 796297179 。
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<b>输入：</b>n = 5, k = 3
<b>输出：</b>7
</pre>

<p><strong>示例 5：</strong></p>

<pre>
<b>输入：</b>n = 3, k = 2
<b>输出：</b>1</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 <= n <= 1000</code></li>
	<li><code>1 <= k <= n-1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

记 $f[i][j]$ 表示使用前 $i$ 个点构造了 $j$ 条线段，且最后一条线段的右端点不为 $i$ 的方案数；记 $g[i][j]$ 表示使用了前 $i$ 个点构造了 $j$ 条线段，且最后一条线段的右端点为 $i$ 的方案数。初始时 $f[1][0]=1$。

考虑 $f[i][j]$，由于第 $j$ 条线段的右端点不为 $i$，因此前 $i-1$ 个点构造了 $j$ 条线段，因此有：

$$
f[i][j] = f[i-1][j] + g[i - 1][j]
$$

考虑 $g[i][j]$，第 $j$ 条线段的右端点为 $i$，如果第 $j$ 条线段的长度超过 $1$，则前 $i-1$ 个点构造了 $j$ 条线段，且第 $j$ 条线段的右端点一定覆盖了 $i-1$，因此有：

$$
g[i][j] = g[i - 1][j]
$$

如果第 $j$ 条线段的长度为 $1$，则前 $i-1$ 个点构造了 $j-1$ 条线段，有：

$$
g[i][j] = f[i - 1][j - 1] + g[i - 1][j - 1]
$$

答案为 $f[n][k]+g[n][k]$。

时间复杂度 $O(n\times k)$，空间复杂度 $O(n\times k)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numberOfSets(self, n: int, k: int) -> int:
        mod = 10**9 + 7
        f = [[0] * (k + 1) for _ in range(n + 1)]
        g = [[0] * (k + 1) for _ in range(n + 1)]
        f[1][0] = 1
        for i in range(2, n + 1):
            for j in range(k + 1):
                f[i][j] = (f[i - 1][j] + g[i - 1][j]) % mod
                g[i][j] = g[i - 1][j]
                if j:
                    g[i][j] += f[i - 1][j - 1]
                    g[i][j] %= mod
                    g[i][j] += g[i - 1][j - 1]
                    g[i][j] %= mod
        return (f[-1][-1] + g[-1][-1]) % mod
```

#### Java

```java
class Solution {
    private static final int MOD = (int) 1e9 + 7;

    public int numberOfSets(int n, int k) {
        int[][] f = new int[n + 1][k + 1];
        int[][] g = new int[n + 1][k + 1];
        f[1][0] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j <= k; ++j) {
                f[i][j] = (f[i - 1][j] + g[i - 1][j]) % MOD;
                g[i][j] = g[i - 1][j];
                if (j > 0) {
                    g[i][j] += f[i - 1][j - 1];
                    g[i][j] %= MOD;
                    g[i][j] += g[i - 1][j - 1];
                    g[i][j] %= MOD;
                }
            }
        }
        return (f[n][k] + g[n][k]) % MOD;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int f[1010][1010];
    int g[1010][1010];
    const int mod = 1e9 + 7;

    int numberOfSets(int n, int k) {
        memset(f, 0, sizeof(f));
        memset(g, 0, sizeof(g));
        f[1][0] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j <= k; ++j) {
                f[i][j] = (f[i - 1][j] + g[i - 1][j]) % mod;
                g[i][j] = g[i - 1][j];
                if (j > 0) {
                    g[i][j] += f[i - 1][j - 1];
                    g[i][j] %= mod;
                    g[i][j] += g[i - 1][j - 1];
                    g[i][j] %= mod;
                }
            }
        }
        return (f[n][k] + g[n][k]) % mod;
    }
};
```

#### Go

```go
func numberOfSets(n int, k int) int {
	f := make([][]int, n+1)
	g := make([][]int, n+1)
	for i := range f {
		f[i] = make([]int, k+1)
		g[i] = make([]int, k+1)
	}
	f[1][0] = 1
	var mod int = 1e9 + 7
	for i := 2; i <= n; i++ {
		for j := 0; j <= k; j++ {
			f[i][j] = (f[i-1][j] + g[i-1][j]) % mod
			g[i][j] = g[i-1][j]
			if j > 0 {
				g[i][j] += f[i-1][j-1]
				g[i][j] %= mod
				g[i][j] += g[i-1][j-1]
				g[i][j] %= mod
			}
		}
	}
	return (f[n][k] + g[n][k]) % mod
}
```

#### TypeScript

```ts
function numberOfSets(n: number, k: number): number {
    const f = Array.from({ length: n + 1 }, _ => new Array(k + 1).fill(0));
    const g = Array.from({ length: n + 1 }, _ => new Array(k + 1).fill(0));
    f[1][0] = 1;
    const mod = 10 ** 9 + 7;
    for (let i = 2; i <= n; ++i) {
        for (let j = 0; j <= k; ++j) {
            f[i][j] = (f[i - 1][j] + g[i - 1][j]) % mod;
            g[i][j] = g[i - 1][j];
            if (j) {
                g[i][j] += f[i - 1][j - 1];
                g[i][j] %= mod;
                g[i][j] += g[i - 1][j - 1];
                g[i][j] %= mod;
            }
        }
    }
    return (f[n][k] + g[n][k]) % mod;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1622. 奇妙序列](https://leetcode.cn/problems/fancy-sequence){#1622}

{{< tabs "1622" >}}

{{% tab "python" %}}
```python
MOD = int(1e9 + 7)


class Node:
    def __init__(self, l, r):
        self.left = None
        self.right = None
        self.l = l
        self.r = r
        self.mid = (l + r) >> 1
        self.v = 0
        self.add = 0
        self.mul = 1


class SegmentTree:
    def __init__(self):
        self.root = Node(1, int(1e5 + 1))

    def modifyAdd(self, l, r, inc, node=None):
        if l > r:
            return
        if node is None:
            node = self.root
        if node.l >= l and node.r <= r:
            node.v = (node.v + (node.r - node.l + 1) * inc) % MOD
            node.add += inc
            return
        self.pushdown(node)
        if l <= node.mid:
            self.modifyAdd(l, r, inc, node.left)
        if r > node.mid:
            self.modifyAdd(l, r, inc, node.right)
        self.pushup(node)

    def modifyMul(self, l, r, m, node=None):
        if l > r:
            return
        if node is None:
            node = self.root
        if node.l >= l and node.r <= r:
            node.v = (node.v * m) % MOD
            node.add = (node.add * m) % MOD
            node.mul = (node.mul * m) % MOD
            return
        self.pushdown(node)
        if l <= node.mid:
            self.modifyMul(l, r, m, node.left)
        if r > node.mid:
            self.modifyMul(l, r, m, node.right)
        self.pushup(node)

    def query(self, l, r, node=None):
        if l > r:
            return 0
        if node is None:
            node = self.root
        if node.l >= l and node.r <= r:
            return node.v
        self.pushdown(node)
        v = 0
        if l <= node.mid:
            v = (v + self.query(l, r, node.left)) % MOD
        if r > node.mid:
            v = (v + self.query(l, r, node.right)) % MOD
        return v

    def pushup(self, node):
        node.v = (node.left.v + node.right.v) % MOD

    def pushdown(self, node):
        if node.left is None:
            node.left = Node(node.l, node.mid)
        if node.right is None:
            node.right = Node(node.mid + 1, node.r)
        left, right = node.left, node.right
        if node.add != 0 or node.mul != 1:
            left.v = (left.v * node.mul + (left.r - left.l + 1) * node.add) % MOD
            right.v = (right.v * node.mul + (right.r - right.l + 1) * node.add) % MOD
            left.add = (left.add * node.mul + node.add) % MOD
            right.add = (right.add * node.mul + node.add) % MOD
            left.mul = (left.mul * node.mul) % MOD
            right.mul = (right.mul * node.mul) % MOD
            node.add = 0
            node.mul = 1


class Fancy:
    def __init__(self):
        self.n = 0
        self.tree = SegmentTree()

    def append(self, val: int) -> None:
        self.n += 1
        self.tree.modifyAdd(self.n, self.n, val)

    def addAll(self, inc: int) -> None:
        self.tree.modifyAdd(1, self.n, inc)

    def multAll(self, m: int) -> None:
        self.tree.modifyMul(1, self.n, m)

    def getIndex(self, idx: int) -> int:
        return -1 if idx >= self.n else self.tree.query(idx + 1, idx + 1)


# Your Fancy object will be instantiated and called as such:
# obj = Fancy()
# obj.append(val)
# obj.addAll(inc)
# obj.multAll(m)
# param_4 = obj.getIndex(idx)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Node {
    Node left;
    Node right;
    int l;
    int r;
    int mid;
    long v;
    long add;
    long mul = 1;

    public Node(int l, int r) {
        this.l = l;
        this.r = r;
        this.mid = (l + r) >> 1;
    }
}

class SegmentTree {
    private Node root = new Node(1, (int) 1e5 + 1);
    private static final int MOD = (int) 1e9 + 7;

    public SegmentTree() {
    }

    public void modifyAdd(int l, int r, int inc) {
        modifyAdd(l, r, inc, root);
    }

    public void modifyAdd(int l, int r, int inc, Node node) {
        if (l > r) {
            return;
        }
        if (node.l >= l && node.r <= r) {
            node.v = (node.v + (node.r - node.l + 1) * inc) % MOD;
            node.add = (node.add + inc) % MOD;
            return;
        }
        pushdown(node);
        if (l <= node.mid) {
            modifyAdd(l, r, inc, node.left);
        }
        if (r > node.mid) {
            modifyAdd(l, r, inc, node.right);
        }
        pushup(node);
    }

    public void modifyMul(int l, int r, int m) {
        modifyMul(l, r, m, root);
    }

    public void modifyMul(int l, int r, int m, Node node) {
        if (l > r) {
            return;
        }
        if (node.l >= l && node.r <= r) {
            node.v = (node.v * m) % MOD;
            node.add = (node.add * m) % MOD;
            node.mul = (node.mul * m) % MOD;
            return;
        }
        pushdown(node);
        if (l <= node.mid) {
            modifyMul(l, r, m, node.left);
        }
        if (r > node.mid) {
            modifyMul(l, r, m, node.right);
        }
        pushup(node);
    }

    public int query(int l, int r) {
        return query(l, r, root);
    }

    public int query(int l, int r, Node node) {
        if (l > r) {
            return 0;
        }
        if (node.l >= l && node.r <= r) {
            return (int) node.v;
        }
        pushdown(node);
        int v = 0;
        if (l <= node.mid) {
            v = (v + query(l, r, node.left)) % MOD;
        }
        if (r > node.mid) {
            v = (v + query(l, r, node.right)) % MOD;
        }
        return v;
    }

    public void pushup(Node node) {
        node.v = (node.left.v + node.right.v) % MOD;
    }

    public void pushdown(Node node) {
        if (node.left == null) {
            node.left = new Node(node.l, node.mid);
        }
        if (node.right == null) {
            node.right = new Node(node.mid + 1, node.r);
        }
        if (node.add != 0 || node.mul != 1) {
            Node left = node.left, right = node.right;
            left.v = (left.v * node.mul + (left.r - left.l + 1) * node.add) % MOD;
            right.v = (right.v * node.mul + (right.r - right.l + 1) * node.add) % MOD;
            left.add = (left.add * node.mul + node.add) % MOD;
            right.add = (right.add * node.mul + node.add) % MOD;
            left.mul = (left.mul * node.mul) % MOD;
            right.mul = (right.mul * node.mul) % MOD;
            node.add = 0;
            node.mul = 1;
        }
    }
}

class Fancy {
    private int n;
    private SegmentTree tree = new SegmentTree();

    public Fancy() {
    }

    public void append(int val) {
        ++n;
        tree.modifyAdd(n, n, val);
    }

    public void addAll(int inc) {
        tree.modifyAdd(1, n, inc);
    }

    public void multAll(int m) {
        tree.modifyMul(1, n, m);
    }

    public int getIndex(int idx) {
        return idx >= n ? -1 : tree.query(idx + 1, idx + 1);
    }
}

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy obj = new Fancy();
 * obj.append(val);
 * obj.addAll(inc);
 * obj.multAll(m);
 * int param_4 = obj.getIndex(idx);
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
const int MOD = 1e9 + 7;

class Node {
public:
    Node* left;
    Node* right;
    int l;
    int r;
    int mid;
    long long v;
    long long add;
    long long mul;

    Node(int l, int r) {
        this->l = l;
        this->r = r;
        this->mid = (l + r) >> 1;
        this->left = this->right = nullptr;
        v = add = 0;
        mul = 1;
    }
};

class SegmentTree {
private:
    Node* root;

public:
    SegmentTree() {
        root = new Node(1, 1e5 + 1);
    }

    void modifyAdd(int l, int r, int inc) {
        modifyAdd(l, r, inc, root);
    }

    void modifyAdd(int l, int r, int inc, Node* node) {
        if (l > r) return;
        if (node->l >= l && node->r <= r) {
            node->v = (node->v + (node->r - node->l + 1) * inc) % MOD;
            node->add = (node->add + inc) % MOD;
            return;
        }
        pushdown(node);
        if (l <= node->mid) modifyAdd(l, r, inc, node->left);
        if (r > node->mid) modifyAdd(l, r, inc, node->right);
        pushup(node);
    }

    void modifyMul(int l, int r, int m) {
        modifyMul(l, r, m, root);
    }

    void modifyMul(int l, int r, int m, Node* node) {
        if (l > r) return;
        if (node->l >= l && node->r <= r) {
            node->v = (node->v * m) % MOD;
            node->add = (node->add * m) % MOD;
            node->mul = (node->mul * m) % MOD;
            return;
        }
        pushdown(node);
        if (l <= node->mid) modifyMul(l, r, m, node->left);
        if (r > node->mid) modifyMul(l, r, m, node->right);
        pushup(node);
    }

    int query(int l, int r) {
        return query(l, r, root);
    }

    int query(int l, int r, Node* node) {
        if (l > r) return 0;
        if (node->l >= l && node->r <= r) return node->v;
        pushdown(node);
        int v = 0;
        if (l <= node->mid) v = (v + query(l, r, node->left)) % MOD;
        if (r > node->mid) v = (v + query(l, r, node->right)) % MOD;
        return v;
    }

    void pushup(Node* node) {
        node->v = (node->left->v + node->right->v) % MOD;
    }

    void pushdown(Node* node) {
        if (!node->left) node->left = new Node(node->l, node->mid);
        if (!node->right) node->right = new Node(node->mid + 1, node->r);
        if (node->add || node->mul != 1) {
            long add = node->add, mul = node->mul;
            Node* left = node->left;
            Node* right = node->right;
            left->v = (left->v * mul + (left->r - left->l + 1) * add) % MOD;
            right->v = (right->v * mul + (right->r - right->l + 1) * add) % MOD;
            left->add = (left->add * mul + add) % MOD;
            right->add = (right->add * mul + add) % MOD;
            left->mul = (left->mul * mul) % MOD;
            right->mul = (right->mul * mul) % MOD;
            node->add = 0;
            node->mul = 1;
        }
    }
};

class Fancy {
public:
    int n;
    SegmentTree* tree;

    Fancy() {
        n = 0;
        tree = new SegmentTree();
    }

    void append(int val) {
        ++n;
        tree->modifyAdd(n, n, val);
    }

    void addAll(int inc) {
        tree->modifyAdd(1, n, inc);
    }

    void multAll(int m) {
        tree->modifyMul(1, n, m);
    }

    int getIndex(int idx) {
        return idx >= n ? -1 : tree->query(idx + 1, idx + 1);
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>请你实现三个 API <code>append</code>，<code>addAll</code> 和 <code>multAll</code> 来实现奇妙序列。</p>

<p>请实现 <code>Fancy</code> 类 ：</p>

<ul>
	<li><code>Fancy()</code> 初始化一个空序列对象。</li>
	<li><code>void append(val)</code> 将整数 <code>val</code> 添加在序列末尾。</li>
	<li><code>void addAll(inc)</code> 将所有序列中的现有数值都增加 <code>inc</code> 。</li>
	<li><code>void multAll(m)</code> 将序列中的所有现有数值都乘以整数 <code>m</code> 。</li>
	<li><code>int getIndex(idx)</code> 得到下标为 <code>idx</code> 处的数值（下标从 0 开始），并将结果对 <code>10<sup>9</sup> + 7</code> 取余。如果下标大于等于序列的长度，请返回 <code>-1</code> 。</li>
</ul>

<p> </p>

<p><strong>示例：</strong></p>

<pre>
<strong>输入：</strong>
["Fancy", "append", "addAll", "append", "multAll", "getIndex", "addAll", "append", "multAll", "getIndex", "getIndex", "getIndex"]
[[], [2], [3], [7], [2], [0], [3], [10], [2], [0], [1], [2]]
<strong>输出：</strong>
[null, null, null, null, null, 10, null, null, null, 26, 34, 20]

<strong>解释：</strong>
Fancy fancy = new Fancy();
fancy.append(2);   // 奇妙序列：[2]
fancy.addAll(3);   // 奇妙序列：[2+3] -> [5]
fancy.append(7);   // 奇妙序列：[5, 7]
fancy.multAll(2);  // 奇妙序列：[5*2, 7*2] -> [10, 14]
fancy.getIndex(0); // 返回 10
fancy.addAll(3);   // 奇妙序列：[10+3, 14+3] -> [13, 17]
fancy.append(10);  // 奇妙序列：[13, 17, 10]
fancy.multAll(2);  // 奇妙序列：[13*2, 17*2, 10*2] -> [26, 34, 20]
fancy.getIndex(0); // 返回 26
fancy.getIndex(1); // 返回 34
fancy.getIndex(2); // 返回 20
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= val, inc, m <= 100</code></li>
	<li><code>0 <= idx <= 10<sup>5</sup></code></li>
	<li>总共最多会有 <code>10<sup>5</sup></code> 次对 <code>append</code>，<code>addAll</code>，<code>multAll</code> 和 <code>getIndex</code> 的调用。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：线段树

线段树将整个区间分割为多个不连续的子区间，子区间的数量不超过 `log(width)`。更新某个元素的值，只需要更新 `log(width)` 个区间，并且这些区间都包含在一个包含该元素的大区间内。区间修改时，需要使用**懒标记**保证效率。

-   线段树的每个节点代表一个区间；
-   线段树具有唯一的根节点，代表的区间是整个统计范围，如 `[1, N]`；
-   线段树的每个叶子节点代表一个长度为 1 的元区间 `[x, x]`；
-   对于每个内部节点 `[l, r]`，它的左儿子是 `[l, mid]`，右儿子是 `[mid + 1, r]`, 其中 `mid = ⌊(l + r) / 2⌋` (即向下取整)。

<!-- tabs:start -->

#### Python3

```python
MOD = int(1e9 + 7)


class Node:
    def __init__(self, l, r):
        self.left = None
        self.right = None
        self.l = l
        self.r = r
        self.mid = (l + r) >> 1
        self.v = 0
        self.add = 0
        self.mul = 1


class SegmentTree:
    def __init__(self):
        self.root = Node(1, int(1e5 + 1))

    def modifyAdd(self, l, r, inc, node=None):
        if l > r:
            return
        if node is None:
            node = self.root
        if node.l >= l and node.r <= r:
            node.v = (node.v + (node.r - node.l + 1) * inc) % MOD
            node.add += inc
            return
        self.pushdown(node)
        if l <= node.mid:
            self.modifyAdd(l, r, inc, node.left)
        if r > node.mid:
            self.modifyAdd(l, r, inc, node.right)
        self.pushup(node)

    def modifyMul(self, l, r, m, node=None):
        if l > r:
            return
        if node is None:
            node = self.root
        if node.l >= l and node.r <= r:
            node.v = (node.v * m) % MOD
            node.add = (node.add * m) % MOD
            node.mul = (node.mul * m) % MOD
            return
        self.pushdown(node)
        if l <= node.mid:
            self.modifyMul(l, r, m, node.left)
        if r > node.mid:
            self.modifyMul(l, r, m, node.right)
        self.pushup(node)

    def query(self, l, r, node=None):
        if l > r:
            return 0
        if node is None:
            node = self.root
        if node.l >= l and node.r <= r:
            return node.v
        self.pushdown(node)
        v = 0
        if l <= node.mid:
            v = (v + self.query(l, r, node.left)) % MOD
        if r > node.mid:
            v = (v + self.query(l, r, node.right)) % MOD
        return v

    def pushup(self, node):
        node.v = (node.left.v + node.right.v) % MOD

    def pushdown(self, node):
        if node.left is None:
            node.left = Node(node.l, node.mid)
        if node.right is None:
            node.right = Node(node.mid + 1, node.r)
        left, right = node.left, node.right
        if node.add != 0 or node.mul != 1:
            left.v = (left.v * node.mul + (left.r - left.l + 1) * node.add) % MOD
            right.v = (right.v * node.mul + (right.r - right.l + 1) * node.add) % MOD
            left.add = (left.add * node.mul + node.add) % MOD
            right.add = (right.add * node.mul + node.add) % MOD
            left.mul = (left.mul * node.mul) % MOD
            right.mul = (right.mul * node.mul) % MOD
            node.add = 0
            node.mul = 1


class Fancy:
    def __init__(self):
        self.n = 0
        self.tree = SegmentTree()

    def append(self, val: int) -> None:
        self.n += 1
        self.tree.modifyAdd(self.n, self.n, val)

    def addAll(self, inc: int) -> None:
        self.tree.modifyAdd(1, self.n, inc)

    def multAll(self, m: int) -> None:
        self.tree.modifyMul(1, self.n, m)

    def getIndex(self, idx: int) -> int:
        return -1 if idx >= self.n else self.tree.query(idx + 1, idx + 1)


# Your Fancy object will be instantiated and called as such:
# obj = Fancy()
# obj.append(val)
# obj.addAll(inc)
# obj.multAll(m)
# param_4 = obj.getIndex(idx)
```

#### Java

```java
class Node {
    Node left;
    Node right;
    int l;
    int r;
    int mid;
    long v;
    long add;
    long mul = 1;

    public Node(int l, int r) {
        this.l = l;
        this.r = r;
        this.mid = (l + r) >> 1;
    }
}

class SegmentTree {
    private Node root = new Node(1, (int) 1e5 + 1);
    private static final int MOD = (int) 1e9 + 7;

    public SegmentTree() {
    }

    public void modifyAdd(int l, int r, int inc) {
        modifyAdd(l, r, inc, root);
    }

    public void modifyAdd(int l, int r, int inc, Node node) {
        if (l > r) {
            return;
        }
        if (node.l >= l && node.r <= r) {
            node.v = (node.v + (node.r - node.l + 1) * inc) % MOD;
            node.add = (node.add + inc) % MOD;
            return;
        }
        pushdown(node);
        if (l <= node.mid) {
            modifyAdd(l, r, inc, node.left);
        }
        if (r > node.mid) {
            modifyAdd(l, r, inc, node.right);
        }
        pushup(node);
    }

    public void modifyMul(int l, int r, int m) {
        modifyMul(l, r, m, root);
    }

    public void modifyMul(int l, int r, int m, Node node) {
        if (l > r) {
            return;
        }
        if (node.l >= l && node.r <= r) {
            node.v = (node.v * m) % MOD;
            node.add = (node.add * m) % MOD;
            node.mul = (node.mul * m) % MOD;
            return;
        }
        pushdown(node);
        if (l <= node.mid) {
            modifyMul(l, r, m, node.left);
        }
        if (r > node.mid) {
            modifyMul(l, r, m, node.right);
        }
        pushup(node);
    }

    public int query(int l, int r) {
        return query(l, r, root);
    }

    public int query(int l, int r, Node node) {
        if (l > r) {
            return 0;
        }
        if (node.l >= l && node.r <= r) {
            return (int) node.v;
        }
        pushdown(node);
        int v = 0;
        if (l <= node.mid) {
            v = (v + query(l, r, node.left)) % MOD;
        }
        if (r > node.mid) {
            v = (v + query(l, r, node.right)) % MOD;
        }
        return v;
    }

    public void pushup(Node node) {
        node.v = (node.left.v + node.right.v) % MOD;
    }

    public void pushdown(Node node) {
        if (node.left == null) {
            node.left = new Node(node.l, node.mid);
        }
        if (node.right == null) {
            node.right = new Node(node.mid + 1, node.r);
        }
        if (node.add != 0 || node.mul != 1) {
            Node left = node.left, right = node.right;
            left.v = (left.v * node.mul + (left.r - left.l + 1) * node.add) % MOD;
            right.v = (right.v * node.mul + (right.r - right.l + 1) * node.add) % MOD;
            left.add = (left.add * node.mul + node.add) % MOD;
            right.add = (right.add * node.mul + node.add) % MOD;
            left.mul = (left.mul * node.mul) % MOD;
            right.mul = (right.mul * node.mul) % MOD;
            node.add = 0;
            node.mul = 1;
        }
    }
}

class Fancy {
    private int n;
    private SegmentTree tree = new SegmentTree();

    public Fancy() {
    }

    public void append(int val) {
        ++n;
        tree.modifyAdd(n, n, val);
    }

    public void addAll(int inc) {
        tree.modifyAdd(1, n, inc);
    }

    public void multAll(int m) {
        tree.modifyMul(1, n, m);
    }

    public int getIndex(int idx) {
        return idx >= n ? -1 : tree.query(idx + 1, idx + 1);
    }
}

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy obj = new Fancy();
 * obj.append(val);
 * obj.addAll(inc);
 * obj.multAll(m);
 * int param_4 = obj.getIndex(idx);
 */
```

#### C++

```cpp
const int MOD = 1e9 + 7;

class Node {
public:
    Node* left;
    Node* right;
    int l;
    int r;
    int mid;
    long long v;
    long long add;
    long long mul;

    Node(int l, int r) {
        this->l = l;
        this->r = r;
        this->mid = (l + r) >> 1;
        this->left = this->right = nullptr;
        v = add = 0;
        mul = 1;
    }
};

class SegmentTree {
private:
    Node* root;

public:
    SegmentTree() {
        root = new Node(1, 1e5 + 1);
    }

    void modifyAdd(int l, int r, int inc) {
        modifyAdd(l, r, inc, root);
    }

    void modifyAdd(int l, int r, int inc, Node* node) {
        if (l > r) return;
        if (node->l >= l && node->r <= r) {
            node->v = (node->v + (node->r - node->l + 1) * inc) % MOD;
            node->add = (node->add + inc) % MOD;
            return;
        }
        pushdown(node);
        if (l <= node->mid) modifyAdd(l, r, inc, node->left);
        if (r > node->mid) modifyAdd(l, r, inc, node->right);
        pushup(node);
    }

    void modifyMul(int l, int r, int m) {
        modifyMul(l, r, m, root);
    }

    void modifyMul(int l, int r, int m, Node* node) {
        if (l > r) return;
        if (node->l >= l && node->r <= r) {
            node->v = (node->v * m) % MOD;
            node->add = (node->add * m) % MOD;
            node->mul = (node->mul * m) % MOD;
            return;
        }
        pushdown(node);
        if (l <= node->mid) modifyMul(l, r, m, node->left);
        if (r > node->mid) modifyMul(l, r, m, node->right);
        pushup(node);
    }

    int query(int l, int r) {
        return query(l, r, root);
    }

    int query(int l, int r, Node* node) {
        if (l > r) return 0;
        if (node->l >= l && node->r <= r) return node->v;
        pushdown(node);
        int v = 0;
        if (l <= node->mid) v = (v + query(l, r, node->left)) % MOD;
        if (r > node->mid) v = (v + query(l, r, node->right)) % MOD;
        return v;
    }

    void pushup(Node* node) {
        node->v = (node->left->v + node->right->v) % MOD;
    }

    void pushdown(Node* node) {
        if (!node->left) node->left = new Node(node->l, node->mid);
        if (!node->right) node->right = new Node(node->mid + 1, node->r);
        if (node->add || node->mul != 1) {
            long add = node->add, mul = node->mul;
            Node* left = node->left;
            Node* right = node->right;
            left->v = (left->v * mul + (left->r - left->l + 1) * add) % MOD;
            right->v = (right->v * mul + (right->r - right->l + 1) * add) % MOD;
            left->add = (left->add * mul + add) % MOD;
            right->add = (right->add * mul + add) % MOD;
            left->mul = (left->mul * mul) % MOD;
            right->mul = (right->mul * mul) % MOD;
            node->add = 0;
            node->mul = 1;
        }
    }
};

class Fancy {
public:
    int n;
    SegmentTree* tree;

    Fancy() {
        n = 0;
        tree = new SegmentTree();
    }

    void append(int val) {
        ++n;
        tree->modifyAdd(n, n, val);
    }

    void addAll(int inc) {
        tree->modifyAdd(1, n, inc);
    }

    void multAll(int m) {
        tree->modifyMul(1, n, m);
    }

    int getIndex(int idx) {
        return idx >= n ? -1 : tree->query(idx + 1, idx + 1);
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1623. 三人国家代表队 🔒](https://leetcode.cn/problems/all-valid-triplets-that-can-represent-a-country){#1623}

{{< tabs "1623" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT
    a.student_name AS member_A,
    b.student_name AS member_B,
    c.student_name AS member_C
FROM
    SchoolA AS a,
    SchoolB AS b,
    SchoolC AS c
WHERE
    a.student_name != b.student_name
    AND a.student_name != c.student_name
    AND b.student_name != c.student_name
    AND a.student_id != b.student_id
    AND a.student_id != c.student_id
    AND b.student_id != c.student_id;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表: <code>SchoolA</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| student_id    | int     |
| student_name  | varchar |
+---------------+---------+
student_id 是该表具有唯一值的列
表中的每一行包含了学校 A 中每一个学生的名字和 ID
所有 student_name 在表中都是独一无二的
</pre>

<p>&nbsp;</p>

<p>表: <code>SchoolB</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| student_id    | int     |
| student_name  | varchar |
+---------------+---------+
student_id 是该表具有唯一值的列
表中的每一行包含了学校 B 中每一个学生的名字和 ID
所有 student_name 在表中都是独一无二的
</pre>

<p>&nbsp;</p>

<p>表: <code>SchoolC</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| student_id    | int     |
| student_name  | varchar |
+---------------+---------+
student_id 是该表具有唯一值的列
表中的每一行包含了学校 C 中每一个学生的名字和 ID
所有 student_name 在表中都是独一无二的
</pre>

<p>&nbsp;</p>

<p>有一个国家只有三所学校，这个国家的每一个学生只会注册&nbsp;<strong>一所学校</strong>。</p>

<p>这个国家正在参加一个竞赛，他们希望从这三所学校中各选出一个学生来组建一支三人的代表队。例如：</p>

<ul>
	<li><code>member_A</code>&nbsp;是从 <code>SchoolA</code>&nbsp;中选出的</li>
	<li><code>member_B</code>&nbsp;是从 <code>SchoolB</code>&nbsp;中选出的</li>
	<li><code>member_C</code>&nbsp;是从 <code>SchoolC</code>&nbsp;中选出的</li>
	<li>被选中的学生具有不同的名字和 ID（没有任何两个学生拥有相同的名字、没有任何两个学生拥有相同的 ID）</li>
</ul>

<p>使用上述条件，编写一个解决方案来找到所有可能的三人国家代表队组合。</p>

<p>返回结果 <strong>无顺序要求</strong>。</p>

<p>结果格式如下示例所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入：</strong>
<code>SchoolA</code> table:
+------------+--------------+
| student_id | student_name |
+------------+--------------+
| 1          | Alice        |
| 2          | Bob          |
+------------+--------------+
<code>SchoolB</code> table:
+------------+--------------+
| student_id | student_name |
+------------+--------------+
| 3          | Tom          |
+------------+--------------+
<code>SchoolC</code> table:
+------------+--------------+
| student_id | student_name |
+------------+--------------+
| 3          | Tom          |
| 2          | Jerry        |
| 10         | Alice        |
+------------+--------------+
<strong>输出：</strong>
+----------+----------+----------+
| member_A | member_B | member_C |
+----------+----------+----------+
| Alice    | Tom      | Jerry    |
| Bob      | Tom      | Alice    |
+----------+----------+----------+
<strong>解释：</strong>
让我们看看有哪些可能的组合：
- (Alice, Tom, Tom) --&gt; 不适用，因为member_B（Tom）和member_C（Tom）有相同的名字和ID
- (Alice, Tom, Jerry) --&gt; 可能的组合
- (Alice, Tom, Alice) --&gt; 不适用，因为member_A和member_C有相同的名字
- (Bob, Tom, Tom) --&gt; 不适用，因为member_B和member_C有相同的名字和ID
- (Bob, Tom, Jerry) --&gt; 不适用，因为member_A和member_C有相同的ID
- (Bob, Tom, Alice) --&gt; 可能的组合.</pre>

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
    a.student_name AS member_A,
    b.student_name AS member_B,
    c.student_name AS member_C
FROM
    SchoolA AS a,
    SchoolB AS b,
    SchoolC AS c
WHERE
    a.student_name != b.student_name
    AND a.student_name != c.student_name
    AND b.student_name != c.student_name
    AND a.student_id != b.student_id
    AND a.student_id != c.student_id
    AND b.student_id != c.student_id;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1624. 两个相同字符之间的最长子字符串](https://leetcode.cn/problems/largest-substring-between-two-equal-characters){#1624}

{{< tabs "1624" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxLengthBetweenEqualCharacters(self, s: str) -> int:
        d = {}
        ans = -1
        for i, c in enumerate(s):
            if c in d:
                ans = max(ans, i - d[c] - 1)
            else:
                d[c] = i
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxLengthBetweenEqualCharacters(String s) {
        int[] d = new int[26];
        Arrays.fill(d, -1);
        int ans = -1;
        for (int i = 0; i < s.length(); ++i) {
            int j = s.charAt(i) - 'a';
            if (d[j] == -1) {
                d[j] = i;
            } else {
                ans = Math.max(ans, i - d[j] - 1);
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
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> d(26, -1);
        int ans = -1;
        for (int i = 0; i < s.size(); ++i) {
            int j = s[i] - 'a';
            if (d[j] == -1) {
                d[j] = i;
            } else {
                ans = max(ans, i - d[j] - 1);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxLengthBetweenEqualCharacters(s string) int {
	d := make([]int, 26)
	for i := range d {
		d[i] = -1
	}
	ans := -1
	for i, c := range s {
		c -= 'a'
		if d[c] == -1 {
			d[c] = i
		} else {
			ans = max(ans, i-d[c]-1)
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxLengthBetweenEqualCharacters(s: string): number {
    const n = s.length;
    const pos = new Array(26).fill(-1);
    let res = -1;
    for (let i = 0; i < n; i++) {
        const j = s[i].charCodeAt(0) - 'a'.charCodeAt(0);
        if (pos[j] === -1) {
            pos[j] = i;
        } else {
            res = Math.max(res, i - pos[j] - 1);
        }
    }
    return res;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn max_length_between_equal_characters(s: String) -> i32 {
        let s = s.as_bytes();
        let n = s.len();
        let mut pos = [-1; 26];
        let mut res = -1;
        for i in 0..n {
            let j = (s[i] - b'a') as usize;
            let i = i as i32;
            if pos[j] == -1 {
                pos[j] = i;
            } else {
                res = res.max(i - pos[j] - 1);
            }
        }
        res
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
#define max(a, b) (((a) > (b)) ? (a) : (b))

int maxLengthBetweenEqualCharacters(char* s) {
    int pos[26];
    memset(pos, -1, sizeof(pos));
    int n = strlen(s);
    int res = -1;
    for (int i = 0; i < n; i++) {
        char c = s[i];
        int j = c - 'a';
        if (pos[j] == -1) {
            pos[j] = i;
        } else {
            res = max(res, i - pos[j] - 1);
        }
    }
    return res;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串 <code>s</code>，请你返回 <strong>两个相同字符之间的最长子字符串的长度</strong> <em>，</em>计算长度时不含这两个字符。如果不存在这样的子字符串，返回 <code>-1</code> 。</p>

<p><strong>子字符串</strong> 是字符串中的一个连续字符序列。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = "aa"
<strong>输出：</strong>0
<strong>解释：</strong>最优的子字符串是两个 'a' 之间的空子字符串。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = "abca"
<strong>输出：</strong>2
<strong>解释：</strong>最优的子字符串是 "bc" 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>s = "cbzxy"
<strong>输出：</strong>-1
<strong>解释：</strong>s 中不存在出现出现两次的字符，所以返回 -1 。
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>s = "cabbac"
<strong>输出：</strong>4
<strong>解释：</strong>最优的子字符串是 "abba" ，其他的非最优解包括 "bb" 和 "" 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 300</code></li>
	<li><code>s</code> 只含小写英文字母</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数组或哈希表

用数组或哈希表记录字符串 $s$ 每个字符第一次出现的位置。由于本题中字符串 $s$ 只含小写英文字母，因此可以用一个长度为 $26$ 的数组 $d$ 来记录，初始时数组元素值均为 $-1$。

遍历字符串 $s$ 中每个字符 $c$，若 $c$ 在数组中的值为 $-1$，则更新为当前位置 $i$；否则我们将答案更新为当前位置 $i$ 与数组中的值 $d[c]$ 的差值的最大值减一，即 $ans = \max (ans, i - d[c]-1)$。

时间复杂度 $O(n)$，空间复杂度 $O(C)$。其中 $n$ 为字符串长度，而 $C$ 为字符串 $s$ 的字符集大小，本题 $C=26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxLengthBetweenEqualCharacters(self, s: str) -> int:
        d = {}
        ans = -1
        for i, c in enumerate(s):
            if c in d:
                ans = max(ans, i - d[c] - 1)
            else:
                d[c] = i
        return ans
```

#### Java

```java
class Solution {
    public int maxLengthBetweenEqualCharacters(String s) {
        int[] d = new int[26];
        Arrays.fill(d, -1);
        int ans = -1;
        for (int i = 0; i < s.length(); ++i) {
            int j = s.charAt(i) - 'a';
            if (d[j] == -1) {
                d[j] = i;
            } else {
                ans = Math.max(ans, i - d[j] - 1);
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
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> d(26, -1);
        int ans = -1;
        for (int i = 0; i < s.size(); ++i) {
            int j = s[i] - 'a';
            if (d[j] == -1) {
                d[j] = i;
            } else {
                ans = max(ans, i - d[j] - 1);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func maxLengthBetweenEqualCharacters(s string) int {
	d := make([]int, 26)
	for i := range d {
		d[i] = -1
	}
	ans := -1
	for i, c := range s {
		c -= 'a'
		if d[c] == -1 {
			d[c] = i
		} else {
			ans = max(ans, i-d[c]-1)
		}
	}
	return ans
}
```

#### TypeScript

```ts
function maxLengthBetweenEqualCharacters(s: string): number {
    const n = s.length;
    const pos = new Array(26).fill(-1);
    let res = -1;
    for (let i = 0; i < n; i++) {
        const j = s[i].charCodeAt(0) - 'a'.charCodeAt(0);
        if (pos[j] === -1) {
            pos[j] = i;
        } else {
            res = Math.max(res, i - pos[j] - 1);
        }
    }
    return res;
}
```

#### Rust

```rust
impl Solution {
    pub fn max_length_between_equal_characters(s: String) -> i32 {
        let s = s.as_bytes();
        let n = s.len();
        let mut pos = [-1; 26];
        let mut res = -1;
        for i in 0..n {
            let j = (s[i] - b'a') as usize;
            let i = i as i32;
            if pos[j] == -1 {
                pos[j] = i;
            } else {
                res = res.max(i - pos[j] - 1);
            }
        }
        res
    }
}
```

#### C

```c
#define max(a, b) (((a) > (b)) ? (a) : (b))

int maxLengthBetweenEqualCharacters(char* s) {
    int pos[26];
    memset(pos, -1, sizeof(pos));
    int n = strlen(s);
    int res = -1;
    for (int i = 0; i < n; i++) {
        char c = s[i];
        int j = c - 'a';
        if (pos[j] == -1) {
            pos[j] = i;
        } else {
            res = max(res, i - pos[j] - 1);
        }
    }
    return res;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1625. 执行操作后字典序最小的字符串](https://leetcode.cn/problems/lexicographically-smallest-string-after-applying-operations){#1625}

{{< tabs "1625" >}}

{{% tab "python" %}}
```python
class Solution:
    def findLexSmallestString(self, s: str, a: int, b: int) -> str:
        ans = s
        n = len(s)
        s = list(s)
        for _ in range(n):
            s = s[-b:] + s[:-b]
            for j in range(10):
                for k in range(1, n, 2):
                    s[k] = str((int(s[k]) + a) % 10)
                if b & 1:
                    for p in range(10):
                        for k in range(0, n, 2):
                            s[k] = str((int(s[k]) + a) % 10)
                        t = ''.join(s)
                        if ans > t:
                            ans = t
                else:
                    t = ''.join(s)
                    if ans > t:
                        ans = t
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String findLexSmallestString(String s, int a, int b) {
        int n = s.length();
        String ans = s;
        for (int i = 0; i < n; ++i) {
            s = s.substring(b) + s.substring(0, b);
            char[] cs = s.toCharArray();
            for (int j = 0; j < 10; ++j) {
                for (int k = 1; k < n; k += 2) {
                    cs[k] = (char) (((cs[k] - '0' + a) % 10) + '0');
                }
                if ((b & 1) == 1) {
                    for (int p = 0; p < 10; ++p) {
                        for (int k = 0; k < n; k += 2) {
                            cs[k] = (char) (((cs[k] - '0' + a) % 10) + '0');
                        }
                        s = String.valueOf(cs);
                        if (ans.compareTo(s) > 0) {
                            ans = s;
                        }
                    }
                } else {
                    s = String.valueOf(cs);
                    if (ans.compareTo(s) > 0) {
                        ans = s;
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
    string findLexSmallestString(string s, int a, int b) {
        int n = s.size();
        string ans = s;
        for (int i = 0; i < n; ++i) {
            s = s.substr(n - b) + s.substr(0, n - b);
            for (int j = 0; j < 10; ++j) {
                for (int k = 1; k < n; k += 2) {
                    s[k] = (s[k] - '0' + a) % 10 + '0';
                }
                if (b & 1) {
                    for (int p = 0; p < 10; ++p) {
                        for (int k = 0; k < n; k += 2) {
                            s[k] = (s[k] - '0' + a) % 10 + '0';
                        }
                        ans = min(ans, s);
                    }
                } else {
                    ans = min(ans, s);
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
func findLexSmallestString(s string, a int, b int) string {
	n := len(s)
	ans := s
	for _ = range s {
		s = s[n-b:] + s[:n-b]
		cs := []byte(s)
		for j := 0; j < 10; j++ {
			for k := 1; k < n; k += 2 {
				cs[k] = byte((int(cs[k]-'0')+a)%10 + '0')
			}
			if b&1 == 1 {
				for p := 0; p < 10; p++ {
					for k := 0; k < n; k += 2 {
						cs[k] = byte((int(cs[k]-'0')+a)%10 + '0')
					}
					s = string(cs)
					if ans > s {
						ans = s
					}
				}
			} else {
				s = string(cs)
				if ans > s {
					ans = s
				}
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

<p>给你一个字符串 <code>s</code> 以及两个整数 <code>a</code> 和 <code>b</code> 。其中，字符串 <code>s</code> 的长度为偶数，且仅由数字 <code>0</code> 到 <code>9</code> 组成。</p>

<p>你可以在 <code>s</code> 上按任意顺序多次执行下面两个操作之一：</p>

<ul>
	<li>累加：将&nbsp; <code>a</code> 加到 <code>s</code> 中所有下标为奇数的元素上（<strong>下标从 0 开始</strong>）。数字一旦超过 <code>9</code> 就会变成 <code>0</code>，如此循环往复。例如，<code>s = "3456"</code> 且 <code>a = 5</code>，则执行此操作后 <code>s</code> 变成 <code>"3951"</code>。</li>
	<li>轮转：将 <code>s</code> 向右轮转 <code>b</code> 位。例如，<code>s = "3456"</code> 且 <code>b = 1</code>，则执行此操作后 <code>s</code> 变成 <code>"6345"</code>。</li>
</ul>

<p>请你返回在 <code>s</code> 上执行上述操作任意次后可以得到的 <strong>字典序最小</strong> 的字符串。</p>

<p>如果两个字符串长度相同，那么字符串 <code>a</code> 字典序比字符串 <code>b</code> 小可以这样定义：在 <code>a</code> 和 <code>b</code> 出现不同的第一个位置上，字符串 <code>a</code> 中的字符出现在字母表中的时间早于 <code>b</code> 中的对应字符。例如，<code>"0158”</code> 字典序比 <code>"0190"</code> 小，因为不同的第一个位置是在第三个字符，显然 <code>'5'</code> 出现在 <code>'9'</code> 之前。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "5525", a = 9, b = 2
<strong>输出：</strong>"2050"
<strong>解释：</strong>执行操作如下：
初态："5525"
轮转："2555"
累加："2454"
累加："2353"
轮转："5323"
累加："5222"
累加："5121"
轮转："2151"
累加："2050"​​​​​
无法获得字典序小于 "2050" 的字符串。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "74", a = 5, b = 1
<strong>输出：</strong>"24"
<strong>解释：</strong>执行操作如下：
初态："74"
轮转："47"
累加："42"
轮转："24"​​​​​
无法获得字典序小于 "24" 的字符串。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "0011", a = 4, b = 2
<strong>输出：</strong>"0011"
<strong>解释：</strong>无法获得字典序小于 "0011" 的字符串。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= s.length &lt;= 100</code></li>
	<li><code>s.length</code> 是偶数</li>
	<li><code>s</code> 仅由数字 <code>0</code> 到 <code>9</code> 组成</li>
	<li><code>1 &lt;= a &lt;= 9</code></li>
	<li><code>1 &lt;= b &lt;= s.length - 1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：BFS

本题数据规模较小，我们可以使用 BFS 暴力搜索所有可能的状态，然后取字典序最小的状态即可。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findLexSmallestString(self, s: str, a: int, b: int) -> str:
        q = deque([s])
        vis = {s}
        ans = s
        while q:
            s = q.popleft()
            if ans > s:
                ans = s
            t1 = ''.join(
                [str((int(c) + a) % 10) if i & 1 else c for i, c in enumerate(s)]
            )
            t2 = s[-b:] + s[:-b]
            for t in (t1, t2):
                if t not in vis:
                    vis.add(t)
                    q.append(t)
        return ans
```

#### Java

```java
class Solution {
    public String findLexSmallestString(String s, int a, int b) {
        Deque<String> q = new ArrayDeque<>();
        q.offer(s);
        Set<String> vis = new HashSet<>();
        vis.add(s);
        String ans = s;
        int n = s.length();
        while (!q.isEmpty()) {
            s = q.poll();
            if (ans.compareTo(s) > 0) {
                ans = s;
            }
            char[] cs = s.toCharArray();
            for (int i = 1; i < n; i += 2) {
                cs[i] = (char) (((cs[i] - '0' + a) % 10) + '0');
            }
            String t1 = String.valueOf(cs);
            String t2 = s.substring(n - b) + s.substring(0, n - b);
            for (String t : List.of(t1, t2)) {
                if (vis.add(t)) {
                    q.offer(t);
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
    string findLexSmallestString(string s, int a, int b) {
        queue<string> q{{s}};
        unordered_set<string> vis{{s}};
        string ans = s;
        int n = s.size();
        while (!q.empty()) {
            s = q.front();
            q.pop();
            ans = min(ans, s);
            string t1 = s;
            for (int i = 1; i < n; i += 2) {
                t1[i] = (t1[i] - '0' + a) % 10 + '0';
            }
            string t2 = s.substr(n - b) + s.substr(0, n - b);
            for (auto& t : {t1, t2}) {
                if (!vis.count(t)) {
                    vis.insert(t);
                    q.emplace(t);
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func findLexSmallestString(s string, a int, b int) string {
	q := []string{s}
	vis := map[string]bool{s: true}
	ans := s
	n := len(s)
	for len(q) > 0 {
		s = q[0]
		q = q[1:]
		if ans > s {
			ans = s
		}
		t1 := []byte(s)
		for i := 1; i < n; i += 2 {
			t1[i] = byte((int(t1[i]-'0')+a)%10 + '0')
		}
		t2 := s[n-b:] + s[:n-b]
		for _, t := range []string{string(t1), t2} {
			if !vis[t] {
				vis[t] = true
				q = append(q, t)
			}
		}
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：枚举

我们观察发现，对于累加操作，数字最多累加 $10$ 次，就会回到原来的状态；对于轮转操作，字符串最多轮转 $n$ 次，也会回到原来的状态。

因此，轮转操作最多产生 $n$ 种状态，如果轮转位数 $b$ 为偶数，累加操作只会对奇数位数字产生影响，因此总共产生 $n \times 10$ 种状态；如果轮转位数 $b$ 为奇数，累加操作既会对奇数位数字产生影响，也会对偶数位数字产生影响，因此总共产生 $n \times 10 \times 10$ 种状态。

所以，我们直接枚举所有的字符串状态，取字典序最小的状态即可。

时间复杂度 $O(n^2 \times 10^2)$，空间复杂度 $O(n)$。其中 $n$ 为字符串 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findLexSmallestString(self, s: str, a: int, b: int) -> str:
        ans = s
        n = len(s)
        s = list(s)
        for _ in range(n):
            s = s[-b:] + s[:-b]
            for j in range(10):
                for k in range(1, n, 2):
                    s[k] = str((int(s[k]) + a) % 10)
                if b & 1:
                    for p in range(10):
                        for k in range(0, n, 2):
                            s[k] = str((int(s[k]) + a) % 10)
                        t = ''.join(s)
                        if ans > t:
                            ans = t
                else:
                    t = ''.join(s)
                    if ans > t:
                        ans = t
        return ans
```

#### Java

```java
class Solution {
    public String findLexSmallestString(String s, int a, int b) {
        int n = s.length();
        String ans = s;
        for (int i = 0; i < n; ++i) {
            s = s.substring(b) + s.substring(0, b);
            char[] cs = s.toCharArray();
            for (int j = 0; j < 10; ++j) {
                for (int k = 1; k < n; k += 2) {
                    cs[k] = (char) (((cs[k] - '0' + a) % 10) + '0');
                }
                if ((b & 1) == 1) {
                    for (int p = 0; p < 10; ++p) {
                        for (int k = 0; k < n; k += 2) {
                            cs[k] = (char) (((cs[k] - '0' + a) % 10) + '0');
                        }
                        s = String.valueOf(cs);
                        if (ans.compareTo(s) > 0) {
                            ans = s;
                        }
                    }
                } else {
                    s = String.valueOf(cs);
                    if (ans.compareTo(s) > 0) {
                        ans = s;
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
    string findLexSmallestString(string s, int a, int b) {
        int n = s.size();
        string ans = s;
        for (int i = 0; i < n; ++i) {
            s = s.substr(n - b) + s.substr(0, n - b);
            for (int j = 0; j < 10; ++j) {
                for (int k = 1; k < n; k += 2) {
                    s[k] = (s[k] - '0' + a) % 10 + '0';
                }
                if (b & 1) {
                    for (int p = 0; p < 10; ++p) {
                        for (int k = 0; k < n; k += 2) {
                            s[k] = (s[k] - '0' + a) % 10 + '0';
                        }
                        ans = min(ans, s);
                    }
                } else {
                    ans = min(ans, s);
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func findLexSmallestString(s string, a int, b int) string {
	n := len(s)
	ans := s
	for _ = range s {
		s = s[n-b:] + s[:n-b]
		cs := []byte(s)
		for j := 0; j < 10; j++ {
			for k := 1; k < n; k += 2 {
				cs[k] = byte((int(cs[k]-'0')+a)%10 + '0')
			}
			if b&1 == 1 {
				for p := 0; p < 10; p++ {
					for k := 0; k < n; k += 2 {
						cs[k] = byte((int(cs[k]-'0')+a)%10 + '0')
					}
					s = string(cs)
					if ans > s {
						ans = s
					}
				}
			} else {
				s = string(cs)
				if ans > s {
					ans = s
				}
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

# [1626. 无矛盾的最佳球队](https://leetcode.cn/problems/best-team-with-no-conflicts){#1626}

{{< tabs "1626" >}}

{{% tab "python" %}}
```python
class BinaryIndexedTree:
    def __init__(self, n):
        self.n = n
        self.c = [0] * (n + 1)

    def update(self, x, val):
        while x <= self.n:
            self.c[x] = max(self.c[x], val)
            x += x & -x

    def query(self, x):
        s = 0
        while x:
            s = max(s, self.c[x])
            x -= x & -x
        return s


class Solution:
    def bestTeamScore(self, scores: List[int], ages: List[int]) -> int:
        m = max(ages)
        tree = BinaryIndexedTree(m)
        for score, age in sorted(zip(scores, ages)):
            tree.update(age, score + tree.query(age))
        return tree.query(m)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class BinaryIndexedTree {
    private int n;
    private int[] c;

    public BinaryIndexedTree(int n) {
        this.n = n;
        c = new int[n + 1];
    }

    public void update(int x, int val) {
        while (x <= n) {
            c[x] = Math.max(c[x], val);
            x += x & -x;
        }
    }

    public int query(int x) {
        int s = 0;
        while (x > 0) {
            s = Math.max(s, c[x]);
            x -= x & -x;
        }
        return s;
    }
}

class Solution {
    public int bestTeamScore(int[] scores, int[] ages) {
        int n = ages.length;
        int[][] arr = new int[n][2];
        for (int i = 0; i < n; ++i) {
            arr[i] = new int[] {scores[i], ages[i]};
        }
        Arrays.sort(arr, (a, b) -> a[0] == b[0] ? a[1] - b[1] : a[0] - b[0]);
        int m = 0;
        for (int age : ages) {
            m = Math.max(m, age);
        }
        BinaryIndexedTree tree = new BinaryIndexedTree(m);
        for (int[] x : arr) {
            tree.update(x[1], x[0] + tree.query(x[1]));
        }
        return tree.query(m);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class BinaryIndexedTree {
public:
    BinaryIndexedTree(int _n)
        : n(_n)
        , c(_n + 1) {}

    void update(int x, int val) {
        while (x <= n) {
            c[x] = max(c[x], val);
            x += x & -x;
        }
    }

    int query(int x) {
        int s = 0;
        while (x) {
            s = max(s, c[x]);
            x -= x & -x;
        }
        return s;
    }

private:
    int n;
    vector<int> c;
};

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = ages.size();
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = {scores[i], ages[i]};
        }
        sort(arr.begin(), arr.end());
        int m = *max_element(ages.begin(), ages.end());
        BinaryIndexedTree tree(m);
        for (auto& [score, age] : arr) {
            tree.update(age, score + tree.query(age));
        }
        return tree.query(m);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
type BinaryIndexedTree struct {
	n int
	c []int
}

func newBinaryIndexedTree(n int) *BinaryIndexedTree {
	c := make([]int, n+1)
	return &BinaryIndexedTree{n, c}
}

func (this *BinaryIndexedTree) update(x, val int) {
	for x <= this.n {
		this.c[x] = max(this.c[x], val)
		x += x & -x
	}
}

func (this *BinaryIndexedTree) query(x int) int {
	s := 0
	for x > 0 {
		s = max(s, this.c[x])
		x -= x & -x
	}
	return s
}

func bestTeamScore(scores []int, ages []int) int {
	n := len(ages)
	arr := make([][2]int, n)
	m := 0
	for i, age := range ages {
		m = max(m, age)
		arr[i] = [2]int{scores[i], age}
	}
	sort.Slice(arr, func(i, j int) bool {
		a, b := arr[i], arr[j]
		return a[0] < b[0] || a[0] == b[0] && a[1] < b[1]
	})
	tree := newBinaryIndexedTree(m)
	for _, x := range arr {
		tree.update(x[1], x[0]+tree.query(x[1]))
	}
	return tree.query(m)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function bestTeamScore(scores: number[], ages: number[]): number {
    const arr = ages.map((age, i) => [age, scores[i]]);
    arr.sort((a, b) => (a[0] == b[0] ? a[1] - b[1] : a[0] - b[0]));
    const n = arr.length;
    const f = new Array(n).fill(0);
    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < i; ++j) {
            if (arr[i][1] >= arr[j][1]) {
                f[i] = Math.max(f[i], f[j]);
            }
        }
        f[i] += arr[i][1];
    }
    return Math.max(...f);
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} scores
 * @param {number[]} ages
 * @return {number}
 */
var bestTeamScore = function (scores, ages) {
    const arr = ages.map((age, i) => [age, scores[i]]);
    arr.sort((a, b) => (a[0] == b[0] ? a[1] - b[1] : a[0] - b[0]));
    const n = arr.length;
    const f = new Array(n).fill(0);
    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < i; ++j) {
            if (arr[i][1] >= arr[j][1]) {
                f[i] = Math.max(f[i], f[j]);
            }
        }
        f[i] += arr[i][1];
    }
    return Math.max(...f);
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>假设你是球队的经理。对于即将到来的锦标赛，你想组合一支总体得分最高的球队。球队的得分是球队中所有球员的分数 <strong>总和</strong> 。</p>

<p>然而，球队中的矛盾会限制球员的发挥，所以必须选出一支 <strong>没有矛盾</strong> 的球队。如果一名年龄较小球员的分数 <strong>严格大于</strong> 一名年龄较大的球员，则存在矛盾。同龄球员之间不会发生矛盾。</p>

<p>给你两个列表 <code>scores</code> 和 <code>ages</code>，其中每组 <code>scores[i]</code> 和 <code>ages[i]</code> 表示第 <code>i</code> 名球员的分数和年龄。请你返回 <strong>所有可能的无矛盾球队中得分最高那支的分数</strong> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>scores = [1,3,5,10,15], ages = [1,2,3,4,5]
<strong>输出：</strong>34
<strong>解释：</strong>你可以选中所有球员。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>scores = [4,5,6,5], ages = [2,1,2,1]
<strong>输出：</strong>16
<strong>解释：</strong>最佳的选择是后 3 名球员。注意，你可以选中多个同龄球员。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>scores = [1,2,3,5], ages = [8,9,10,1]
<strong>输出：</strong>6
<strong>解释：</strong>最佳的选择是前 3 名球员。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= scores.length, ages.length &lt;= 1000</code></li>
	<li><code>scores.length == ages.length</code></li>
	<li><code>1 &lt;= scores[i] &lt;= 10<sup>6</sup></code></li>
	<li><code>1 &lt;= ages[i] &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 动态规划

我们可以将球员按照分数从小到大排序，如果分数相同，则按照年龄从小到大排序。

接下来，使用动态规划求解。

我们定义 $f[i]$ 表示以排序后的第 $i$ 个球员作为最后一个球员的最大得分，那么答案就是 $\max_{0 \leq i < n} f[i]$。

对于 $f[i]$，我们可以枚举 $0 \leq j \lt i$，如果第 $i$ 个球员的年龄大于等于第 $j$ 个球员的年龄，则 $f[i]$ 可以从 $f[j]$ 转移而来，转移方程为 $f[i] = \max(f[i], f[j])$。然后我们将第 $i$ 个球员的分数加到 $f[i]$ 中，即 $f[i] += scores[i]$。

最后，我们返回 $\max_{0 \leq i < n} f[i]$ 即可。

时间复杂度 $O(n^2)$，空间复杂度 $O(n)$。其中 $n$ 为球员的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def bestTeamScore(self, scores: List[int], ages: List[int]) -> int:
        arr = sorted(zip(scores, ages))
        n = len(arr)
        f = [0] * n
        for i, (score, age) in enumerate(arr):
            for j in range(i):
                if age >= arr[j][1]:
                    f[i] = max(f[i], f[j])
            f[i] += score
        return max(f)
```

#### Java

```java
class Solution {
    public int bestTeamScore(int[] scores, int[] ages) {
        int n = ages.length;
        int[][] arr = new int[n][2];
        for (int i = 0; i < n; ++i) {
            arr[i] = new int[] {scores[i], ages[i]};
        }
        Arrays.sort(arr, (a, b) -> a[0] == b[0] ? a[1] - b[1] : a[0] - b[0]);
        int[] f = new int[n];
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (arr[i][1] >= arr[j][1]) {
                    f[i] = Math.max(f[i], f[j]);
                }
            }
            f[i] += arr[i][0];
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
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = ages.size();
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = {scores[i], ages[i]};
        }
        sort(arr.begin(), arr.end());
        vector<int> f(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (arr[i].second >= arr[j].second) {
                    f[i] = max(f[i], f[j]);
                }
            }
            f[i] += arr[i].first;
        }
        return *max_element(f.begin(), f.end());
    }
};
```

#### Go

```go
func bestTeamScore(scores []int, ages []int) int {
	n := len(ages)
	arr := make([][2]int, n)
	for i := range ages {
		arr[i] = [2]int{scores[i], ages[i]}
	}
	sort.Slice(arr, func(i, j int) bool {
		a, b := arr[i], arr[j]
		return a[0] < b[0] || a[0] == b[0] && a[1] < b[1]
	})
	f := make([]int, n)
	for i := range arr {
		for j := 0; j < i; j++ {
			if arr[i][1] >= arr[j][1] {
				f[i] = max(f[i], f[j])
			}
		}
		f[i] += arr[i][0]
	}
	return slices.Max(f)
}
```

#### TypeScript

```ts
function bestTeamScore(scores: number[], ages: number[]): number {
    const arr = ages.map((age, i) => [age, scores[i]]);
    arr.sort((a, b) => (a[0] == b[0] ? a[1] - b[1] : a[0] - b[0]));
    const n = arr.length;
    const f = new Array(n).fill(0);
    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < i; ++j) {
            if (arr[i][1] >= arr[j][1]) {
                f[i] = Math.max(f[i], f[j]);
            }
        }
        f[i] += arr[i][1];
    }
    return Math.max(...f);
}
```

#### JavaScript

```js
/**
 * @param {number[]} scores
 * @param {number[]} ages
 * @return {number}
 */
var bestTeamScore = function (scores, ages) {
    const arr = ages.map((age, i) => [age, scores[i]]);
    arr.sort((a, b) => (a[0] == b[0] ? a[1] - b[1] : a[0] - b[0]));
    const n = arr.length;
    const f = new Array(n).fill(0);
    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < i; ++j) {
            if (arr[i][1] >= arr[j][1]) {
                f[i] = Math.max(f[i], f[j]);
            }
        }
        f[i] += arr[i][1];
    }
    return Math.max(...f);
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：排序 + 树状数组

与方法一类似，我们可以将球员按照分数从小到大排序，如果分数相同，则按照年龄从小到大排序。

接下来，我们使用树状数组维护不超过当前球员年龄的球员的最大得分。每一次，我们只需要在 $O(\log m)$ 的时间内找出不超过当前球员年龄的球员的最大得分，然后将当前球员的分数加到该得分上，即可更新当前球员年龄的最大得分。

最后，我们返回得分的最大值即可。

时间复杂度 $O(n \times (\log n + \log m))$，空间复杂度 $O(n + m)$。其中 $n$ 和 $m$ 分别为球员的数量和球员的年龄的最大值。

<!-- tabs:start -->

#### Python3

```python
class BinaryIndexedTree:
    def __init__(self, n):
        self.n = n
        self.c = [0] * (n + 1)

    def update(self, x, val):
        while x <= self.n:
            self.c[x] = max(self.c[x], val)
            x += x & -x

    def query(self, x):
        s = 0
        while x:
            s = max(s, self.c[x])
            x -= x & -x
        return s


class Solution:
    def bestTeamScore(self, scores: List[int], ages: List[int]) -> int:
        m = max(ages)
        tree = BinaryIndexedTree(m)
        for score, age in sorted(zip(scores, ages)):
            tree.update(age, score + tree.query(age))
        return tree.query(m)
```

#### Java

```java
class BinaryIndexedTree {
    private int n;
    private int[] c;

    public BinaryIndexedTree(int n) {
        this.n = n;
        c = new int[n + 1];
    }

    public void update(int x, int val) {
        while (x <= n) {
            c[x] = Math.max(c[x], val);
            x += x & -x;
        }
    }

    public int query(int x) {
        int s = 0;
        while (x > 0) {
            s = Math.max(s, c[x]);
            x -= x & -x;
        }
        return s;
    }
}

class Solution {
    public int bestTeamScore(int[] scores, int[] ages) {
        int n = ages.length;
        int[][] arr = new int[n][2];
        for (int i = 0; i < n; ++i) {
            arr[i] = new int[] {scores[i], ages[i]};
        }
        Arrays.sort(arr, (a, b) -> a[0] == b[0] ? a[1] - b[1] : a[0] - b[0]);
        int m = 0;
        for (int age : ages) {
            m = Math.max(m, age);
        }
        BinaryIndexedTree tree = new BinaryIndexedTree(m);
        for (int[] x : arr) {
            tree.update(x[1], x[0] + tree.query(x[1]));
        }
        return tree.query(m);
    }
}
```

#### C++

```cpp
class BinaryIndexedTree {
public:
    BinaryIndexedTree(int _n)
        : n(_n)
        , c(_n + 1) {}

    void update(int x, int val) {
        while (x <= n) {
            c[x] = max(c[x], val);
            x += x & -x;
        }
    }

    int query(int x) {
        int s = 0;
        while (x) {
            s = max(s, c[x]);
            x -= x & -x;
        }
        return s;
    }

private:
    int n;
    vector<int> c;
};

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = ages.size();
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = {scores[i], ages[i]};
        }
        sort(arr.begin(), arr.end());
        int m = *max_element(ages.begin(), ages.end());
        BinaryIndexedTree tree(m);
        for (auto& [score, age] : arr) {
            tree.update(age, score + tree.query(age));
        }
        return tree.query(m);
    }
};
```

#### Go

```go
type BinaryIndexedTree struct {
	n int
	c []int
}

func newBinaryIndexedTree(n int) *BinaryIndexedTree {
	c := make([]int, n+1)
	return &BinaryIndexedTree{n, c}
}

func (this *BinaryIndexedTree) update(x, val int) {
	for x <= this.n {
		this.c[x] = max(this.c[x], val)
		x += x & -x
	}
}

func (this *BinaryIndexedTree) query(x int) int {
	s := 0
	for x > 0 {
		s = max(s, this.c[x])
		x -= x & -x
	}
	return s
}

func bestTeamScore(scores []int, ages []int) int {
	n := len(ages)
	arr := make([][2]int, n)
	m := 0
	for i, age := range ages {
		m = max(m, age)
		arr[i] = [2]int{scores[i], age}
	}
	sort.Slice(arr, func(i, j int) bool {
		a, b := arr[i], arr[j]
		return a[0] < b[0] || a[0] == b[0] && a[1] < b[1]
	})
	tree := newBinaryIndexedTree(m)
	for _, x := range arr {
		tree.update(x[1], x[0]+tree.query(x[1]))
	}
	return tree.query(m)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1627. 带阈值的图连通性](https://leetcode.cn/problems/graph-connectivity-with-threshold){#1627}

{{< tabs "1627" >}}

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
        if pa == pb:
            return False
        if self.size[pa] > self.size[pb]:
            self.p[pb] = pa
            self.size[pa] += self.size[pb]
        else:
            self.p[pa] = pb
            self.size[pb] += self.size[pa]
        return True


class Solution:
    def areConnected(
        self, n: int, threshold: int, queries: List[List[int]]
    ) -> List[bool]:
        uf = UnionFind(n + 1)
        for a in range(threshold + 1, n + 1):
            for b in range(a + a, n + 1, a):
                uf.union(a, b)
        return [uf.find(a) == uf.find(b) for a, b in queries]
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

    public boolean union(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) {
            return false;
        }
        if (size[pa] > size[pb]) {
            p[pb] = pa;
            size[pa] += size[pb];
        } else {
            p[pa] = pb;
            size[pb] += size[pa];
        }
        return true;
    }
}

class Solution {
    public List<Boolean> areConnected(int n, int threshold, int[][] queries) {
        UnionFind uf = new UnionFind(n + 1);
        for (int a = threshold + 1; a <= n; ++a) {
            for (int b = a + a; b <= n; b += a) {
                uf.union(a, b);
            }
        }
        List<Boolean> ans = new ArrayList<>();
        for (var q : queries) {
            ans.add(uf.find(q[0]) == uf.find(q[1]));
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

    bool unite(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) {
            return false;
        }
        if (size[pa] > size[pb]) {
            p[pb] = pa;
            size[pa] += size[pb];
        } else {
            p[pa] = pb;
            size[pb] += size[pa];
        }
        return true;
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
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        UnionFind uf(n + 1);
        for (int a = threshold + 1; a <= n; ++a) {
            for (int b = a + a; b <= n; b += a) {
                uf.unite(a, b);
            }
        }
        vector<bool> ans;
        for (auto& q : queries) {
            ans.push_back(uf.find(q[0]) == uf.find(q[1]));
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

func (uf *unionFind) union(a, b int) bool {
	pa, pb := uf.find(a), uf.find(b)
	if pa == pb {
		return false
	}
	if uf.size[pa] > uf.size[pb] {
		uf.p[pb] = pa
		uf.size[pa] += uf.size[pb]
	} else {
		uf.p[pa] = pb
		uf.size[pb] += uf.size[pa]
	}
	return true
}

func areConnected(n int, threshold int, queries [][]int) []bool {
	uf := newUnionFind(n + 1)
	for a := threshold + 1; a <= n; a++ {
		for b := a + a; b <= n; b += a {
			uf.union(a, b)
		}
	}
	ans := make([]bool, len(queries))
	for i, q := range queries {
		ans[i] = uf.find(q[0]) == uf.find(q[1])
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class UnionFind {
    p: number[];
    size: number[];
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

    union(a: number, b: number): boolean {
        const [pa, pb] = [this.find(a), this.find(b)];
        if (pa === pb) {
            return false;
        }
        if (this.size[pa] > this.size[pb]) {
            this.p[pb] = pa;
            this.size[pa] += this.size[pb];
        } else {
            this.p[pa] = pb;
            this.size[pb] += this.size[pa];
        }
        return true;
    }
}

function areConnected(n: number, threshold: number, queries: number[][]): boolean[] {
    const uf = new UnionFind(n + 1);
    for (let a = threshold + 1; a <= n; ++a) {
        for (let b = a * 2; b <= n; b += a) {
            uf.union(a, b);
        }
    }
    return queries.map(([a, b]) => uf.find(a) === uf.find(b));
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>有 <code>n</code> 座城市，编号从 <code>1</code> 到 <code>n</code> 。编号为 <code>x</code> 和 <code>y</code> 的两座城市直接连通的前提是： <code>x</code> 和 <code>y</code> 的公因数中，至少有一个 <strong>严格大于</strong> 某个阈值 <code>threshold</code> 。更正式地说，如果存在整数 <code>z</code> ，且满足以下所有条件，则编号 <code>x</code> 和 <code>y</code> 的城市之间有一条道路：</p>

<ul>
	<li><code>x % z == 0</code></li>
	<li><code>y % z == 0</code></li>
	<li><code>z > threshold</code></li>
</ul>

<p>给你两个整数 <code>n</code> 和 <code>threshold</code> ，以及一个待查询数组，请你判断每个查询<code> queries[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> 指向的城市 <code>a<sub>i</sub></code> 和 <code>b<sub>i</sub></code> 是否连通（即，它们之间是否存在一条路径）。</p>

<p>返回数组 <code>answer</code> ，其中<code>answer.length == queries.length</code> 。如果第 <code>i</code> 个查询中指向的城市 <code>a<sub>i</sub></code> 和 <code>b<sub>i</sub></code> 连通，则 <code>answer[i]</code> 为 <code>true</code> ；如果不连通，则 <code>answer[i]</code> 为 <code>false</code> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1600-1699/1627.Graph%20Connectivity%20With%20Threshold/images/ex1.jpg" style="width: 382px; height: 181px;" /></p>

<p> </p>

<pre>
<strong>输入：</strong>n = 6, threshold = 2, queries = [[1,4],[2,5],[3,6]]
<strong>输出：</strong>[false,false,true]
<strong>解释：</strong>每个数的因数如下：
1:   1
2:   1, 2
3:   1, <strong>3</strong>
4:   1, 2, <strong>4</strong>
5:   1, <strong>5</strong>
6:   1, 2, <strong>3</strong>, <strong>6</strong>
所有大于阈值的的因数已经加粗标识，只有城市 3 和 6 共享公约数 3 ，因此结果是： 
[1,4]   1 与 4 不连通
[2,5]   2 与 5 不连通
[3,6]   3 与 6 连通，存在路径 3--6
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1600-1699/1627.Graph%20Connectivity%20With%20Threshold/images/tmp.jpg" style="width: 532px; height: 302px;" /></p>

<p> </p>

<pre>
<strong>输入：</strong>n = 6, threshold = 0, queries = [[4,5],[3,4],[3,2],[2,6],[1,3]]
<strong>输出：</strong>[true,true,true,true,true]
<strong>解释：</strong>每个数的因数与上一个例子相同。但是，由于阈值为 0 ，所有的因数都大于阈值。因为所有的数字共享公因数 1 ，所以所有的城市都互相连通。
</pre>

<p><strong>示例 3：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1600-1699/1627.Graph%20Connectivity%20With%20Threshold/images/ex3.jpg" style="width: 282px; height: 282px;" /></p>

<p> </p>

<pre>
<strong>输入：</strong>n = 5, threshold = 1, queries = [[4,5],[4,5],[3,2],[2,3],[3,4]]
<strong>输出：</strong>[false,false,false,false,false]
<strong>解释：</strong>只有城市 2 和 4 共享的公约数 2 严格大于阈值 1 ，所以只有这两座城市是连通的。
注意，同一对节点 [x, y] 可以有多个查询，并且查询 [x，y] 等同于查询 [y，x] 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 <= n <= 10<sup>4</sup></code></li>
	<li><code>0 <= threshold <= n</code></li>
	<li><code>1 <= queries.length <= 10<sup>5</sup></code></li>
	<li><code>queries[i].length == 2</code></li>
	<li><code>1 <= a<sub>i</sub>, b<sub>i</sub> <= cities</code></li>
	<li><code>a<sub>i</sub> != b<sub>i</sub></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：并查集

我们可以枚举 $z$ 以及 $z$ 的倍数，用并查集将它们连通起来。这样，对于每个查询 $[a, b]$，我们只需要判断 $a$ 和 $b$ 是否在同一个连通块中即可。

时间复杂度 $O(n \times \log n \time (\alpha(n) + q))$，空间复杂度 $O(n)$。其中 $n$ 和 $q$ 分别是节点数和查询数，而 $\alpha$ 是阿克曼函数的反函数。

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
        if pa == pb:
            return False
        if self.size[pa] > self.size[pb]:
            self.p[pb] = pa
            self.size[pa] += self.size[pb]
        else:
            self.p[pa] = pb
            self.size[pb] += self.size[pa]
        return True


class Solution:
    def areConnected(
        self, n: int, threshold: int, queries: List[List[int]]
    ) -> List[bool]:
        uf = UnionFind(n + 1)
        for a in range(threshold + 1, n + 1):
            for b in range(a + a, n + 1, a):
                uf.union(a, b)
        return [uf.find(a) == uf.find(b) for a, b in queries]
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

    public boolean union(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) {
            return false;
        }
        if (size[pa] > size[pb]) {
            p[pb] = pa;
            size[pa] += size[pb];
        } else {
            p[pa] = pb;
            size[pb] += size[pa];
        }
        return true;
    }
}

class Solution {
    public List<Boolean> areConnected(int n, int threshold, int[][] queries) {
        UnionFind uf = new UnionFind(n + 1);
        for (int a = threshold + 1; a <= n; ++a) {
            for (int b = a + a; b <= n; b += a) {
                uf.union(a, b);
            }
        }
        List<Boolean> ans = new ArrayList<>();
        for (var q : queries) {
            ans.add(uf.find(q[0]) == uf.find(q[1]));
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

    bool unite(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) {
            return false;
        }
        if (size[pa] > size[pb]) {
            p[pb] = pa;
            size[pa] += size[pb];
        } else {
            p[pa] = pb;
            size[pb] += size[pa];
        }
        return true;
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
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        UnionFind uf(n + 1);
        for (int a = threshold + 1; a <= n; ++a) {
            for (int b = a + a; b <= n; b += a) {
                uf.unite(a, b);
            }
        }
        vector<bool> ans;
        for (auto& q : queries) {
            ans.push_back(uf.find(q[0]) == uf.find(q[1]));
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

func (uf *unionFind) union(a, b int) bool {
	pa, pb := uf.find(a), uf.find(b)
	if pa == pb {
		return false
	}
	if uf.size[pa] > uf.size[pb] {
		uf.p[pb] = pa
		uf.size[pa] += uf.size[pb]
	} else {
		uf.p[pa] = pb
		uf.size[pb] += uf.size[pa]
	}
	return true
}

func areConnected(n int, threshold int, queries [][]int) []bool {
	uf := newUnionFind(n + 1)
	for a := threshold + 1; a <= n; a++ {
		for b := a + a; b <= n; b += a {
			uf.union(a, b)
		}
	}
	ans := make([]bool, len(queries))
	for i, q := range queries {
		ans[i] = uf.find(q[0]) == uf.find(q[1])
	}
	return ans
}
```

#### TypeScript

```ts
class UnionFind {
    p: number[];
    size: number[];
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

    union(a: number, b: number): boolean {
        const [pa, pb] = [this.find(a), this.find(b)];
        if (pa === pb) {
            return false;
        }
        if (this.size[pa] > this.size[pb]) {
            this.p[pb] = pa;
            this.size[pa] += this.size[pb];
        } else {
            this.p[pa] = pb;
            this.size[pb] += this.size[pa];
        }
        return true;
    }
}

function areConnected(n: number, threshold: number, queries: number[][]): boolean[] {
    const uf = new UnionFind(n + 1);
    for (let a = threshold + 1; a <= n; ++a) {
        for (let b = a * 2; b <= n; b += a) {
            uf.union(a, b);
        }
    }
    return queries.map(([a, b]) => uf.find(a) === uf.find(b));
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1628. 设计带解析函数的表达式树 🔒](https://leetcode.cn/problems/design-an-expression-tree-with-evaluate-function){#1628}

{{< tabs "1628" >}}

{{% tab "python" %}}
```python
import abc
from abc import ABC, abstractmethod

"""
This is the interface for the expression tree Node.
You should not remove it, and you can define some classes to implement it.
"""


class Node(ABC):
    @abstractmethod
    # define your fields here
    def evaluate(self) -> int:
        pass


class MyNode(Node):
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

    def evaluate(self) -> int:
        x = self.val
        if x.isdigit():
            return int(x)

        left, right = self.left.evaluate(), self.right.evaluate()
        if x == '+':
            return left + right
        if x == '-':
            return left - right
        if x == '*':
            return left * right
        if x == '/':
            return left // right


"""
This is the TreeBuilder class.
You can treat it as the driver code that takes the postinfix input
and returns the expression tree represnting it as a Node.
"""


class TreeBuilder(object):
    def buildTree(self, postfix: List[str]) -> 'Node':
        stk = []
        for s in postfix:
            node = MyNode(s)
            if not s.isdigit():
                node.right = stk.pop()
                node.left = stk.pop()
            stk.append(node)
        return stk[-1]


"""
Your TreeBuilder object will be instantiated and called as such:
obj = TreeBuilder();
expTree = obj.buildTree(postfix);
ans = expTree.evaluate();
"""
```
{{% /tab %}}
{{% tab "java" %}}
```java
/**
 * This is the interface for the expression tree Node.
 * You should not remove it, and you can define some classes to implement it.
 */

abstract class Node {
    public abstract int evaluate();
    // define your fields here
    protected String val;
    protected Node left;
    protected Node right;
};

class MyNode extends Node {
    public MyNode(String val) {
        this.val = val;
    }

    public int evaluate() {
        if (isNumeric()) {
            return Integer.parseInt(val);
        }
        int leftVal = left.evaluate();
        int rightVal = right.evaluate();
        if (Objects.equals(val, "+")) {
            return leftVal + rightVal;
        }
        if (Objects.equals(val, "-")) {
            return leftVal - rightVal;
        }
        if (Objects.equals(val, "*")) {
            return leftVal * rightVal;
        }
        if (Objects.equals(val, "/")) {
            return leftVal / rightVal;
        }
        return 0;
    }

    public boolean isNumeric() {
        for (char c : val.toCharArray()) {
            if (!Character.isDigit(c)) {
                return false;
            }
        }
        return true;
    }
}

/**
 * This is the TreeBuilder class.
 * You can treat it as the driver code that takes the postinfix input
 * and returns the expression tree represnting it as a Node.
 */

class TreeBuilder {
    Node buildTree(String[] postfix) {
        Deque<MyNode> stk = new ArrayDeque<>();
        for (String s : postfix) {
            MyNode node = new MyNode(s);
            if (!node.isNumeric()) {
                node.right = stk.pop();
                node.left = stk.pop();
            }
            stk.push(node);
        }
        return stk.peek();
    }
};

/**
 * Your TreeBuilder object will be instantiated and called as such:
 * TreeBuilder obj = new TreeBuilder();
 * Node expTree = obj.buildTree(postfix);
 * int ans = expTree.evaluate();
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
/**
 * This is the interface for the expression tree Node.
 * You should not remove it, and you can define some classes to implement it.
 */

class Node {
public:
    virtual ~Node(){};
    virtual int evaluate() const = 0;

protected:
    // define your fields here
    string val;
    Node* left;
    Node* right;
};

class MyNode : public Node {
public:
    MyNode(string val) {
        this->val = val;
    }

    MyNode(string val, Node* left, Node* right) {
        this->val = val;
        this->left = left;
        this->right = right;
    }

    int evaluate() const {
        if (!(val == "+" || val == "-" || val == "*" || val == "/")) return stoi(val);
        auto leftVal = left->evaluate(), rightVal = right->evaluate();
        if (val == "+") return leftVal + rightVal;
        if (val == "-") return leftVal - rightVal;
        if (val == "*") return leftVal * rightVal;
        if (val == "/") return leftVal / rightVal;
        return 0;
    }
};

/**
 * This is the TreeBuilder class.
 * You can treat it as the driver code that takes the postinfix input
 * and returns the expression tree represnting it as a Node.
 */

class TreeBuilder {
public:
    Node* buildTree(vector<string>& postfix) {
        stack<MyNode*> stk;
        for (auto s : postfix) {
            MyNode* node;
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                auto right = stk.top();
                stk.pop();
                auto left = stk.top();
                stk.pop();
                node = new MyNode(s, left, right);
            } else {
                node = new MyNode(s);
            }
            stk.push(node);
        }
        return stk.top();
    }
};

/**
 * Your TreeBuilder object will be instantiated and called as such:
 * TreeBuilder* obj = new TreeBuilder();
 * Node* expTree = obj->buildTree(postfix);
 * int ans = expTree->evaluate();
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个算术表达式的后缀表示法的标记（token）&nbsp;<code>postfix</code>&nbsp;，构造并返回该表达式对应的二叉表达式树。</p>

<p><b>后缀</b>表示法是一种将操作数写在运算符之前的表示法。例如，表达式&nbsp;<code>4*(5-(2+7))</code>&nbsp;的后缀表示法表示为数组&nbsp;<code>postfix = ["4","5","7","2","+","-","*"]</code>&nbsp;。</p>

<p>抽象类&nbsp;<code>Node</code>&nbsp;需要用于实现二叉表达式树。我们将通过&nbsp;<code>evaluate</code>&nbsp;函数来测试返回的树是否能够解析树中的值。你不可以移除 <code>Node</code> 类，但你可以按需修改此类，也可以定义其他类来实现它。</p>

<p><a href="https://en.wikipedia.org/wiki/Binary_expression_tree"><strong>二叉表达式树</strong></a>是一种表达算术表达式的二叉树。二叉表达式树中的每一个节点都有零个或两个子节点。&nbsp;叶节点（有 0 个子节点的节点）表示操作数，非叶节点（有 2 个子节点的节点）表示运算符：&nbsp;<code>'+'</code>&nbsp;（加）、&nbsp;<code>'-'</code> （减）、&nbsp;<code>'*'</code> （乘）和&nbsp;<code>'/'</code> （除）。</p>

<p>我们保证任何子树对应值的绝对值不超过&nbsp;<code>10<sup>9</sup></code>&nbsp;，且所有操作都是有效的（即没有除以零的操作）</p>

<p><b>进阶：</b>&nbsp;你可以将表达式树设计得更模块化吗？例如，你的设计能够不修改现有的&nbsp;<code>evaluate</code>&nbsp;的实现就能支持更多的操作符吗？</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1600-1699/1628.Design%20an%20Expression%20Tree%20With%20Evaluate%20Function/images/untitled-diagram.png" style="width: 242px; height: 241px;" /></strong></p>

<pre>
<b>输入：</b> s = ["3","4","+","2","*","7","/"]
<b>输出：</b> 2
<b>解释：</b> 此表达式可解析为上述二叉树，其对应表达式为 (<code>(3+4)*2)/7) = 14/7 = 2.</code>
</pre>

<p><strong>示例 2:</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1600-1699/1628.Design%20an%20Expression%20Tree%20With%20Evaluate%20Function/images/untitled-diagram2.png" style="width: 222px; height: 232px;" /></strong></p>

<pre>
<strong>输入:</strong> s = ["4","5","7","2","+","-","*"]
<strong>输出:</strong> -16
<strong>解释:</strong> 此表达式可解析为上述二叉树，其对应表达式为 4*(5-<code>(2+7)) = 4*(-4) = -16.</code>
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt; 100</code></li>
	<li><code>s.length</code>&nbsp;是奇数。</li>
	<li><code>s</code>&nbsp;包含数字和字符&nbsp;<code>'+'</code>&nbsp;、&nbsp;<code>'-'</code>&nbsp;、&nbsp;<code>'*'</code>&nbsp;以及&nbsp;<code>'/'</code>&nbsp;。</li>
	<li>如果&nbsp;<code>s[i]</code>&nbsp;是数，则对应的整数不超过&nbsp;<code>10<sup>5</sup></code>&nbsp;。</li>
	<li><code>s</code>&nbsp;保证是一个有效的表达式。</li>
	<li>结果值和所有过程值的绝对值均不超过&nbsp;<code>10<sup>9</sup></code>&nbsp;。</li>
	<li>保证表达式不包含除以零的操作。</li>
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
import abc
from abc import ABC, abstractmethod

"""
This is the interface for the expression tree Node.
You should not remove it, and you can define some classes to implement it.
"""


class Node(ABC):
    @abstractmethod
    # define your fields here
    def evaluate(self) -> int:
        pass


class MyNode(Node):
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

    def evaluate(self) -> int:
        x = self.val
        if x.isdigit():
            return int(x)

        left, right = self.left.evaluate(), self.right.evaluate()
        if x == '+':
            return left + right
        if x == '-':
            return left - right
        if x == '*':
            return left * right
        if x == '/':
            return left // right


"""
This is the TreeBuilder class.
You can treat it as the driver code that takes the postinfix input
and returns the expression tree represnting it as a Node.
"""


class TreeBuilder(object):
    def buildTree(self, postfix: List[str]) -> 'Node':
        stk = []
        for s in postfix:
            node = MyNode(s)
            if not s.isdigit():
                node.right = stk.pop()
                node.left = stk.pop()
            stk.append(node)
        return stk[-1]


"""
Your TreeBuilder object will be instantiated and called as such:
obj = TreeBuilder();
expTree = obj.buildTree(postfix);
ans = expTree.evaluate();
"""
```

#### Java

```java
/**
 * This is the interface for the expression tree Node.
 * You should not remove it, and you can define some classes to implement it.
 */

abstract class Node {
    public abstract int evaluate();
    // define your fields here
    protected String val;
    protected Node left;
    protected Node right;
};

class MyNode extends Node {
    public MyNode(String val) {
        this.val = val;
    }

    public int evaluate() {
        if (isNumeric()) {
            return Integer.parseInt(val);
        }
        int leftVal = left.evaluate();
        int rightVal = right.evaluate();
        if (Objects.equals(val, "+")) {
            return leftVal + rightVal;
        }
        if (Objects.equals(val, "-")) {
            return leftVal - rightVal;
        }
        if (Objects.equals(val, "*")) {
            return leftVal * rightVal;
        }
        if (Objects.equals(val, "/")) {
            return leftVal / rightVal;
        }
        return 0;
    }

    public boolean isNumeric() {
        for (char c : val.toCharArray()) {
            if (!Character.isDigit(c)) {
                return false;
            }
        }
        return true;
    }
}

/**
 * This is the TreeBuilder class.
 * You can treat it as the driver code that takes the postinfix input
 * and returns the expression tree represnting it as a Node.
 */

class TreeBuilder {
    Node buildTree(String[] postfix) {
        Deque<MyNode> stk = new ArrayDeque<>();
        for (String s : postfix) {
            MyNode node = new MyNode(s);
            if (!node.isNumeric()) {
                node.right = stk.pop();
                node.left = stk.pop();
            }
            stk.push(node);
        }
        return stk.peek();
    }
};

/**
 * Your TreeBuilder object will be instantiated and called as such:
 * TreeBuilder obj = new TreeBuilder();
 * Node expTree = obj.buildTree(postfix);
 * int ans = expTree.evaluate();
 */
```

#### C++

```cpp
/**
 * This is the interface for the expression tree Node.
 * You should not remove it, and you can define some classes to implement it.
 */

class Node {
public:
    virtual ~Node(){};
    virtual int evaluate() const = 0;

protected:
    // define your fields here
    string val;
    Node* left;
    Node* right;
};

class MyNode : public Node {
public:
    MyNode(string val) {
        this->val = val;
    }

    MyNode(string val, Node* left, Node* right) {
        this->val = val;
        this->left = left;
        this->right = right;
    }

    int evaluate() const {
        if (!(val == "+" || val == "-" || val == "*" || val == "/")) return stoi(val);
        auto leftVal = left->evaluate(), rightVal = right->evaluate();
        if (val == "+") return leftVal + rightVal;
        if (val == "-") return leftVal - rightVal;
        if (val == "*") return leftVal * rightVal;
        if (val == "/") return leftVal / rightVal;
        return 0;
    }
};

/**
 * This is the TreeBuilder class.
 * You can treat it as the driver code that takes the postinfix input
 * and returns the expression tree represnting it as a Node.
 */

class TreeBuilder {
public:
    Node* buildTree(vector<string>& postfix) {
        stack<MyNode*> stk;
        for (auto s : postfix) {
            MyNode* node;
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                auto right = stk.top();
                stk.pop();
                auto left = stk.top();
                stk.pop();
                node = new MyNode(s, left, right);
            } else {
                node = new MyNode(s);
            }
            stk.push(node);
        }
        return stk.top();
    }
};

/**
 * Your TreeBuilder object will be instantiated and called as such:
 * TreeBuilder* obj = new TreeBuilder();
 * Node* expTree = obj->buildTree(postfix);
 * int ans = expTree->evaluate();
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1629. 按键持续时间最长的键](https://leetcode.cn/problems/slowest-key){#1629}

{{< tabs "1629" >}}

{{% tab "python" %}}
```python
class Solution:
    def slowestKey(self, releaseTimes: List[int], keysPressed: str) -> str:
        ans = keysPressed[0]
        mx = releaseTimes[0]
        for i in range(1, len(keysPressed)):
            d = releaseTimes[i] - releaseTimes[i - 1]
            if d > mx or (d == mx and ord(keysPressed[i]) > ord(ans)):
                mx = d
                ans = keysPressed[i]
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public char slowestKey(int[] releaseTimes, String keysPressed) {
        char ans = keysPressed.charAt(0);
        int mx = releaseTimes[0];
        for (int i = 1; i < releaseTimes.length; ++i) {
            int d = releaseTimes[i] - releaseTimes[i - 1];
            if (d > mx || (d == mx && keysPressed.charAt(i) > ans)) {
                mx = d;
                ans = keysPressed.charAt(i);
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
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        char ans = keysPressed[0];
        int mx = releaseTimes[0];
        for (int i = 1, n = releaseTimes.size(); i < n; ++i) {
            int d = releaseTimes[i] - releaseTimes[i - 1];
            if (d > mx || (d == mx && keysPressed[i] > ans)) {
                mx = d;
                ans = keysPressed[i];
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func slowestKey(releaseTimes []int, keysPressed string) byte {
	ans := keysPressed[0]
	mx := releaseTimes[0]
	for i := 1; i < len(releaseTimes); i++ {
		d := releaseTimes[i] - releaseTimes[i-1]
		if d > mx || (d == mx && keysPressed[i] > ans) {
			mx = d
			ans = keysPressed[i]
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

<p>LeetCode 设计了一款新式键盘，正在测试其可用性。测试人员将会点击一系列键（总计 <code>n</code> 个），每次一个。</p>

<p>给你一个长度为 <code>n</code> 的字符串 <code>keysPressed</code> ，其中 <code>keysPressed[i]</code> 表示测试序列中第 <code>i</code> 个被按下的键。<code>releaseTimes</code> 是一个升序排列的列表，其中 <code>releaseTimes[i]</code> 表示松开第 <code>i</code> 个键的时间。字符串和数组的 <strong>下标都从 0 开始</strong> 。第 <code>0</code> 个键在时间为 <code>0</code> 时被按下，接下来每个键都 <strong>恰好</strong> 在前一个键松开时被按下。</p>

<p>测试人员想要找出按键 <strong>持续时间最长</strong> 的键。第 <code>i</code><sup> </sup>次按键的持续时间为 <code>releaseTimes[i] - releaseTimes[i - 1]</code> ，第 <code>0</code> 次按键的持续时间为 <code>releaseTimes[0]</code> 。</p>

<p>注意，测试期间，同一个键可以在不同时刻被多次按下，而每次的持续时间都可能不同。</p>

<p>请返回单次按键 <strong>持续时间最长</strong> 的键，如果有多个这样的键，则返回 <strong>按字母顺序排列最大</strong> 的那个键。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>releaseTimes = [9,29,49,50], keysPressed = "cbcd"
<strong>输出：'</strong>c'
<strong>解释：</strong>按键顺序和持续时间如下：
按下 'c' ，持续时间 9（时间 0 按下，时间 9 松开）
按下 'b' ，持续时间 29 - 9 = 20（松开上一个键的时间 9 按下，时间 29 松开）
按下 'c' ，持续时间 49 - 29 = 20（松开上一个键的时间 29 按下，时间 49 松开）
按下 'd' ，持续时间 50 - 49 = 1（松开上一个键的时间 49 按下，时间 50 松开）
按键持续时间最长的键是 'b' 和 'c'（第二次按下时），持续时间都是 20
'c' 按字母顺序排列比 'b' 大，所以答案是 'c'
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>releaseTimes = [12,23,36,46,62], keysPressed = "spuda"
<strong>输出：'</strong>a'
<strong>解释：</strong>按键顺序和持续时间如下：
按下 's' ，持续时间 12
按下 'p' ，持续时间 23 - 12 = 11
按下 'u' ，持续时间 36 - 23 = 13
按下 'd' ，持续时间 46 - 36 = 10
按下 'a' ，持续时间 62 - 46 = 16
按键持续时间最长的键是 'a' ，持续时间 16</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>releaseTimes.length == n</code></li>
	<li><code>keysPressed.length == n</code></li>
	<li><code>2 &lt;= n &lt;= 1000</code></li>
	<li><code>1 &lt;= releaseTimes[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>releaseTimes[i] &lt; releaseTimes[i+1]</code></li>
	<li><code>keysPressed</code> 仅由小写英文字母组成</li>
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
class Solution:
    def slowestKey(self, releaseTimes: List[int], keysPressed: str) -> str:
        ans = keysPressed[0]
        mx = releaseTimes[0]
        for i in range(1, len(keysPressed)):
            d = releaseTimes[i] - releaseTimes[i - 1]
            if d > mx or (d == mx and ord(keysPressed[i]) > ord(ans)):
                mx = d
                ans = keysPressed[i]
        return ans
```

#### Java

```java
class Solution {
    public char slowestKey(int[] releaseTimes, String keysPressed) {
        char ans = keysPressed.charAt(0);
        int mx = releaseTimes[0];
        for (int i = 1; i < releaseTimes.length; ++i) {
            int d = releaseTimes[i] - releaseTimes[i - 1];
            if (d > mx || (d == mx && keysPressed.charAt(i) > ans)) {
                mx = d;
                ans = keysPressed.charAt(i);
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
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        char ans = keysPressed[0];
        int mx = releaseTimes[0];
        for (int i = 1, n = releaseTimes.size(); i < n; ++i) {
            int d = releaseTimes[i] - releaseTimes[i - 1];
            if (d > mx || (d == mx && keysPressed[i] > ans)) {
                mx = d;
                ans = keysPressed[i];
            }
        }
        return ans;
    }
};
```

#### Go

```go
func slowestKey(releaseTimes []int, keysPressed string) byte {
	ans := keysPressed[0]
	mx := releaseTimes[0]
	for i := 1; i < len(releaseTimes); i++ {
		d := releaseTimes[i] - releaseTimes[i-1]
		if d > mx || (d == mx && keysPressed[i] > ans) {
			mx = d
			ans = keysPressed[i]
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
