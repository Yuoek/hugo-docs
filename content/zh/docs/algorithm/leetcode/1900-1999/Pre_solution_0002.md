---
title: "1910_删除一个字符串中所有出现的给定子字符串"
date: 2025-10-08T18:38:49+08:00
weight: 2
tags: [二分查找, 位运算, 前缀和, 动态规划, 哈希表, 图, 堆（优先队列）, 字符串, 拓扑排序, 排序, 数学, 数据库, 数组, 有序集合, 栈, 树, 模拟, 滑动窗口, 矩阵, 组合数学, 设计]
---

{{< markmap >}}
### [1910_删除一个字符串中所有出现的给定子字符串](#1910)
#### [栈](#1910)
#### [字符串](#1910)
#### [模拟](#1910)
### [1911_最大交替子序列和](#1911)
#### [数组](#1911)
#### [动态规划](#1911)
### [1912_设计电影租借系统](#1912)
#### [设计](#1912)
#### [数组](#1912)
#### [哈希表](#1912)
#### [有序集合](#1912)
#### [堆（优先队列）](#1912)
### [1913_两个数对之间的最大乘积差](#1913)
#### [数组](#1913)
#### [排序](#1913)
### [1914_循环轮转矩阵](#1914)
#### [数组](#1914)
#### [矩阵](#1914)
#### [模拟](#1914)
### [1915_最美子字符串的数目](#1915)
#### [位运算](#1915)
#### [哈希表](#1915)
#### [字符串](#1915)
#### [前缀和](#1915)
### [1916_统计为蚁群构筑房间的不同顺序](#1916)
#### [树](#1916)
#### [图](#1916)
#### [拓扑排序](#1916)
#### [数学](#1916)
#### [动态规划](#1916)
#### [组合数学](#1916)
### [1917_Leetcodify 好友推荐 🔒](#1917)
#### [数据库](#1917)
### [1918_第 K 小的子数组和 🔒](#1918)
#### [数组](#1918)
#### [二分查找](#1918)
#### [滑动窗口](#1918)
### [1919_兴趣相同的朋友 🔒](#1919)
#### [数据库](#1919)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1910_删除一个字符串中所有出现的给定子字符串
___
#### 栈
___
#### 字符串
___
#### 模拟
---
### 1911_最大交替子序列和
___
#### 数组
___
#### 动态规划
---
### 1912_设计电影租借系统
___
#### 设计
___
#### 数组
___
#### 哈希表
___
#### 有序集合
___
#### 堆（优先队列）
---
### 1913_两个数对之间的最大乘积差
___
#### 数组
___
#### 排序
---
### 1914_循环轮转矩阵
___
#### 数组
___
#### 矩阵
___
#### 模拟
---
### 1915_最美子字符串的数目
___
#### 位运算
___
#### 哈希表
___
#### 字符串
___
#### 前缀和
---
### 1916_统计为蚁群构筑房间的不同顺序
___
#### 树
___
#### 图
___
#### 拓扑排序
___
#### 数学
___
#### 动态规划
___
#### 组合数学
---
### 1917_Leetcodify 好友推荐 🔒
___
#### 数据库
---
### 1918_第 K 小的子数组和 🔒
___
#### 数组
___
#### 二分查找
___
#### 滑动窗口
---
### 1919_兴趣相同的朋友 🔒
___
#### 数据库
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 位运算 | 前缀和 |
| 动态规划 | 哈希表 | 图 |
| 堆（优先队列） | 字符串 | 拓扑排序 |
| 排序 | 数学 | 数据库 |
| 数组 | 有序集合 | 栈 |
| 树 | 模拟 | 滑动窗口 |
| 矩阵 | 组合数学 | 设计 |

# [1910. 删除一个字符串中所有出现的给定子字符串](https://leetcode.cn/problems/remove-all-occurrences-of-a-substring){#1910}

{{< tabs "1910" >}}

{{% tab "python" %}}
```python
class Solution:
    def removeOccurrences(self, s: str, part: str) -> str:
        while part in s:
            s = s.replace(part, '', 1)
        return s
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String removeOccurrences(String s, String part) {
        while (s.contains(part)) {
            s = s.replaceFirst(part, "");
        }
        return s;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string removeOccurrences(string s, string part) {
        int m = part.size();
        while (s.find(part) != -1) {
            s = s.erase(s.find(part), m);
        }
        return s;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func removeOccurrences(s string, part string) string {
	for strings.Contains(s, part) {
		s = strings.Replace(s, part, "", 1)
	}
	return s
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function removeOccurrences(s: string, part: string): string {
    while (s.includes(part)) {
        s = s.replace(part, '');
    }
    return s;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个字符串 <code>s</code> 和 <code>part</code> ，请你对 <code>s</code> 反复执行以下操作直到 <b>所有</b> 子字符串 <code>part</code> 都被删除：</p>

<ul>
	<li>找到 <code>s</code> 中 <strong>最左边</strong> 的子字符串 <code>part</code> ，并将它从 <code>s</code> 中删除。</li>
</ul>

<p>请你返回从 <code>s</code> 中删除所有 <code>part</code> 子字符串以后得到的剩余字符串。</p>

<p>一个 <strong>子字符串</strong> 是一个字符串中连续的字符序列。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>s = "daabcbaabcbc", part = "abc"
<b>输出：</b>"dab"
<b>解释：</b>以下操作按顺序执行：
- s = "da<strong>abc</strong>baabcbc" ，删除下标从 2 开始的 "abc" ，得到 s = "dabaabcbc" 。
- s = "daba<strong>abc</strong>bc" ，删除下标从 4 开始的 "abc" ，得到 s = "dababc" 。
- s = "dab<strong>abc</strong>" ，删除下标从 3 开始的 "abc" ，得到 s = "dab" 。
此时 s 中不再含有子字符串 "abc" 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>s = "axxxxyyyyb", part = "xy"
<b>输出：</b>"ab"
<b>解释：</b>以下操作按顺序执行：
- s = "axxx<strong>xy</strong>yyyb" ，删除下标从 4 开始的 "xy" ，得到 s = "axxxyyyb" 。
- s = "axx<strong>xy</strong>yyb" ，删除下标从 3 开始的 "xy" ，得到 s = "axxyyb" 。
- s = "ax<strong>xy</strong>yb" ，删除下标从 2 开始的 "xy" ，得到 s = "axyb" 。
- s = "a<strong>xy</strong>b" ，删除下标从 1 开始的 "xy" ，得到 s = "ab" 。
此时 s 中不再含有子字符串 "xy" 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>1 &lt;= part.length &lt;= 1000</code></li>
	<li><code>s</code>​​​​​​ 和 <code>part</code> 只包小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：暴力替换

我们循环判断 $s$ 中是否存在字符串 $part$，是则进行一次替换，继续循环此操作，直至 $s$ 中不存在字符串 $part$，返回此时的 $s$ 作为答案字符串。

时间复杂度 $O(n^2 + n \times m)$，空间复杂度 $O(n + m)$。其中 $n$ 和 $m$ 分别是字符串 $s$ 和字符串 $part$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def removeOccurrences(self, s: str, part: str) -> str:
        while part in s:
            s = s.replace(part, '', 1)
        return s
```

#### Java

```java
class Solution {
    public String removeOccurrences(String s, String part) {
        while (s.contains(part)) {
            s = s.replaceFirst(part, "");
        }
        return s;
    }
}
```

#### C++

```cpp
class Solution {
public:
    string removeOccurrences(string s, string part) {
        int m = part.size();
        while (s.find(part) != -1) {
            s = s.erase(s.find(part), m);
        }
        return s;
    }
};
```

#### Go

```go
func removeOccurrences(s string, part string) string {
	for strings.Contains(s, part) {
		s = strings.Replace(s, part, "", 1)
	}
	return s
}
```

#### TypeScript

```ts
function removeOccurrences(s: string, part: string): string {
    while (s.includes(part)) {
        s = s.replace(part, '');
    }
    return s;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1911. 最大交替子序列和](https://leetcode.cn/problems/maximum-alternating-subsequence-sum){#1911}

{{< tabs "1911" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxAlternatingSum(self, nums: List[int]) -> int:
        f = g = 0
        for x in nums:
            f, g = max(g - x, f), max(f + x, g)
        return max(f, g)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long maxAlternatingSum(int[] nums) {
        long f = 0, g = 0;
        for (int x : nums) {
            long ff = Math.max(g - x, f);
            long gg = Math.max(f + x, g);
            f = ff;
            g = gg;
        }
        return Math.max(f, g);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long f = 0, g = 0;
        for (int& x : nums) {
            long ff = max(g - x, f), gg = max(f + x, g);
            f = ff, g = gg;
        }
        return max(f, g);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxAlternatingSum(nums []int) int64 {
	var f, g int
	for _, x := range nums {
		f, g = max(g-x, f), max(f+x, g)
	}
	return int64(max(f, g))
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxAlternatingSum(nums: number[]): number {
    let [f, g] = [0, 0];
    for (const x of nums) {
        [f, g] = [Math.max(g - x, f), Math.max(f + x, g)];
    }
    return g;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>一个下标从 <strong>0</strong> 开始的数组的 <strong>交替和</strong> 定义为 <strong>偶数</strong> 下标处元素之 <strong>和</strong> 减去 <strong>奇数</strong> 下标处元素之 <strong>和</strong> 。</p>

<ul>
	<li>比方说，数组 <code>[4,2,5,3]</code> 的交替和为 <code>(4 + 5) - (2 + 3) = 4</code> 。</li>
</ul>

<p>给你一个数组 <code>nums</code> ，请你返回 <code>nums</code> 中任意子序列的 <strong>最大交替和</strong> （子序列的下标 <strong>重新</strong> 从 0 开始编号）。</p>

<ul>
</ul>

<p>一个数组的 <strong>子序列</strong> 是从原数组中删除一些元素后（也可能一个也不删除）剩余元素不改变顺序组成的数组。比方说，<code>[2,7,4]</code> 是 <code>[4,<strong>2</strong>,3,<strong>7</strong>,2,1,<strong>4</strong>]</code> 的一个子序列（加粗元素），但是 <code>[2,4,2]</code> 不是。</p>

<p> </p>

<p><b>示例 1：</b></p>

<pre><b>输入：</b>nums = [<strong>4</strong>,<strong>2</strong>,<strong>5</strong>,3]
<b>输出：</b>7
<b>解释：</b>最优子序列为 [4,2,5] ，交替和为 (4 + 5) - 2 = 7 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [5,6,7,<strong>8</strong>]
<b>输出：</b>8
<b>解释：</b>最优子序列为 [8] ，交替和为 8 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>nums = [<strong>6</strong>,2,<strong>1</strong>,2,4,<strong>5</strong>]
<b>输出：</b>10
<b>解释：</b>最优子序列为 [6,1,5] ，交替和为 (6 + 5) - 1 = 10 。
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

### 方法一：动态规划

我们定义 $f[i]$ 表示从前 $i$ 个元素中选出的子序列，且最后一个元素为奇数下标时的最大交替和，定义 $g[i]$ 表示从前 $i$ 个元素中选出的子序列，且最后一个元素为偶数下标时的最大交替和。初始时 $f[0] = g[0] = 0$。答案为 $max(f[n], g[n])$。

我们考虑第 $i$ 个元素 $nums[i - 1]$：

如果选取该元素且该元素为奇数下标，那么上一个元素必须为偶数下标，且只能从前 $i-1$ 个元素中选取，因此 $f[i] = g[i - 1] - nums[i - 1]$；如果不选取该元素，那么 $f[i] = f[i - 1]$。

同理，如果选取该元素且该元素为偶数下标，那么上一个元素必须为奇数下标，且只能从前 $i-1$ 个元素中选取，因此 $g[i] = f[i - 1] + nums[i - 1]$；如果不选取该元素，那么 $g[i] = g[i - 1]$。

综上，我们可以得到状态转移方程：

$$
\begin{aligned}
f[i] &= max(g[i - 1] - nums[i - 1], f[i - 1]) \\
g[i] &= max(f[i - 1] + nums[i - 1], g[i - 1])
\end{aligned}
$$

最终答案为 $max(f[n], g[n])$。

我们注意到 $f[i]$ 和 $g[i]$ 只与 $f[i - 1]$ 和 $g[i - 1]$ 有关，因此我们可以使用两个变量代替数组，将空间复杂度降低到 $O(1)$。

时间复杂度 $O(n)$，其中 $n$ 为数组长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxAlternatingSum(self, nums: List[int]) -> int:
        n = len(nums)
        f = [0] * (n + 1)
        g = [0] * (n + 1)
        for i, x in enumerate(nums, 1):
            f[i] = max(g[i - 1] - x, f[i - 1])
            g[i] = max(f[i - 1] + x, g[i - 1])
        return max(f[n], g[n])
```

#### Java

```java
class Solution {
    public long maxAlternatingSum(int[] nums) {
        int n = nums.length;
        long[] f = new long[n + 1];
        long[] g = new long[n + 1];
        for (int i = 1; i <= n; ++i) {
            f[i] = Math.max(g[i - 1] - nums[i - 1], f[i - 1]);
            g[i] = Math.max(f[i - 1] + nums[i - 1], g[i - 1]);
        }
        return Math.max(f[n], g[n]);
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> f(n + 1), g(n + 1);
        for (int i = 1; i <= n; ++i) {
            f[i] = max(g[i - 1] - nums[i - 1], f[i - 1]);
            g[i] = max(f[i - 1] + nums[i - 1], g[i - 1]);
        }
        return max(f[n], g[n]);
    }
};
```

#### Go

```go
func maxAlternatingSum(nums []int) int64 {
	n := len(nums)
	f := make([]int, n+1)
	g := make([]int, n+1)
	for i, x := range nums {
		i++
		f[i] = max(g[i-1]-x, f[i-1])
		g[i] = max(f[i-1]+x, g[i-1])
	}
	return int64(max(f[n], g[n]))
}
```

#### TypeScript

```ts
function maxAlternatingSum(nums: number[]): number {
    const n = nums.length;
    const f: number[] = new Array(n + 1).fill(0);
    const g = f.slice();
    for (let i = 1; i <= n; ++i) {
        f[i] = Math.max(g[i - 1] + nums[i - 1], f[i - 1]);
        g[i] = Math.max(f[i - 1] - nums[i - 1], g[i - 1]);
    }
    return Math.max(f[n], g[n]);
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
    def maxAlternatingSum(self, nums: List[int]) -> int:
        f = g = 0
        for x in nums:
            f, g = max(g - x, f), max(f + x, g)
        return max(f, g)
```

#### Java

```java
class Solution {
    public long maxAlternatingSum(int[] nums) {
        long f = 0, g = 0;
        for (int x : nums) {
            long ff = Math.max(g - x, f);
            long gg = Math.max(f + x, g);
            f = ff;
            g = gg;
        }
        return Math.max(f, g);
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long f = 0, g = 0;
        for (int& x : nums) {
            long ff = max(g - x, f), gg = max(f + x, g);
            f = ff, g = gg;
        }
        return max(f, g);
    }
};
```

#### Go

```go
func maxAlternatingSum(nums []int) int64 {
	var f, g int
	for _, x := range nums {
		f, g = max(g-x, f), max(f+x, g)
	}
	return int64(max(f, g))
}
```

#### TypeScript

```ts
function maxAlternatingSum(nums: number[]): number {
    let [f, g] = [0, 0];
    for (const x of nums) {
        [f, g] = [Math.max(g - x, f), Math.max(f + x, g)];
    }
    return g;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1912. 设计电影租借系统](https://leetcode.cn/problems/design-movie-rental-system){#1912}

{{< tabs "1912" >}}

{{% tab "python" %}}
```python
class MovieRentingSystem:
    def __init__(self, n: int, entries: List[List[int]]):
        self.unrented = collections.defaultdict(SortedList)  # {movie: (price, shop)}
        self.shopAndMovieToPrice = {}  # {(shop, movie): price}
        self.rented = SortedList()  # (price, shop, movie)
        for shop, movie, price in entries:
            self.unrented[movie].add((price, shop))
            self.shopAndMovieToPrice[(shop, movie)] = price

    def search(self, movie: int) -> List[int]:
        return [shop for _, shop in self.unrented[movie][:5]]

    def rent(self, shop: int, movie: int) -> None:
        price = self.shopAndMovieToPrice[(shop, movie)]
        self.unrented[movie].remove((price, shop))
        self.rented.add((price, shop, movie))

    def drop(self, shop: int, movie: int) -> None:
        price = self.shopAndMovieToPrice[(shop, movie)]
        self.unrented[movie].add((price, shop))
        self.rented.remove((price, shop, movie))

    def report(self) -> List[List[int]]:
        return [[shop, movie] for _, shop, movie in self.rented[:5]]


# Your MovieRentingSystem object will be instantiated and called as such:
# obj = MovieRentingSystem(n, entries)
# param_1 = obj.search(movie)
# obj.rent(shop,movie)
# obj.drop(shop,movie)
# param_4 = obj.report()
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你有一个电影租借公司和 <code>n</code> 个电影商店。你想要实现一个电影租借系统，它支持查询、预订和返还电影的操作。同时系统还能生成一份当前被借出电影的报告。</p>

<p>所有电影用二维整数数组 <code>entries</code> 表示，其中 <code>entries[i] = [shop<sub>i</sub>, movie<sub>i</sub>, price<sub>i</sub>]</code> 表示商店 <code>shop<sub>i</sub></code> 有一份电影 <code>movie<sub>i</sub></code> 的拷贝，租借价格为 <code>price<sub>i</sub></code> 。每个商店有 <strong>至多一份</strong> 编号为 <code>movie<sub>i</sub></code> 的电影拷贝。</p>

<p>系统需要支持以下操作：</p>

<ul>
	<li><strong>Search：</strong>找到拥有指定电影且 <strong>未借出</strong> 的商店中 <strong>最便宜的 5 个</strong> 。商店需要按照 <strong>价格</strong> 升序排序，如果价格相同，则 <code>shop<sub>i</sub></code> <strong>较小</strong> 的商店排在前面。如果查询结果少于 5 个商店，则将它们全部返回。如果查询结果没有任何商店，则返回空列表。</li>
	<li><strong>Rent：</strong>从指定商店借出指定电影，题目保证指定电影在指定商店 <strong>未借出</strong> 。</li>
	<li><strong>Drop：</strong>在指定商店返还 <strong>之前已借出</strong> 的指定电影。</li>
	<li><strong>Report：</strong>返回 <strong>最便宜的 5 部已借出电影</strong> （可能有重复的电影 ID），将结果用二维列表 <code>res</code> 返回，其中 <code>res[j] = [shop<sub>j</sub>, movie<sub>j</sub>]</code> 表示第 <code>j</code> 便宜的已借出电影是从商店 <code>shop<sub>j</sub></code> 借出的电影 <code>movie<sub>j</sub></code> 。<code>res</code> 中的电影需要按 <strong>价格</strong> 升序排序；如果价格相同，则<strong> </strong><code>shop<sub>j</sub></code> <strong>较小</strong> 的排在前面；如果仍然相同，则 <code>movie<sub>j</sub></code> <strong>较小 </strong>的排在前面。如果当前借出的电影小于 5 部，则将它们全部返回。如果当前没有借出电影，则返回一个空的列表。</li>
</ul>

<p>请你实现 <code>MovieRentingSystem</code> 类：</p>

<ul>
	<li><code>MovieRentingSystem(int n, int[][] entries)</code> 将 <code>MovieRentingSystem</code> 对象用 <code>n</code> 个商店和 <code>entries</code> 表示的电影列表初始化。</li>
	<li><code>List&lt;Integer&gt; search(int movie)</code> 如上所述，返回 <strong>未借出</strong> 指定 <code>movie</code> 的商店列表。</li>
	<li><code>void rent(int shop, int movie)</code> 从指定商店 <code>shop</code> 借出指定电影 <code>movie</code> 。</li>
	<li><code>void drop(int shop, int movie)</code> 在指定商店 <code>shop</code> 返还之前借出的电影 <code>movie</code> 。</li>
	<li><code>List&lt;List&lt;Integer&gt;&gt; report()</code> 如上所述，返回最便宜的 <strong>已借出</strong> 电影列表。</li>
</ul>

<p><strong>注意：</strong>测试数据保证 <code>rent</code> 操作中指定商店拥有 <strong>未借出 </strong>的指定电影，且 <code>drop</code> 操作指定的商店 <strong>之前已借出</strong> 指定电影。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
["MovieRentingSystem", "search", "rent", "rent", "report", "drop", "search"]
[[3, [[0, 1, 5], [0, 2, 6], [0, 3, 7], [1, 1, 4], [1, 2, 7], [2, 1, 5]]], [1], [0, 1], [1, 2], [], [1, 2], [2]]
<strong>输出：</strong>
[null, [1, 0, 2], null, null, [[0, 1], [1, 2]], null, [0, 1]]

<strong>解释：</strong>
MovieRentingSystem movieRentingSystem = new MovieRentingSystem(3, [[0, 1, 5], [0, 2, 6], [0, 3, 7], [1, 1, 4], [1, 2, 7], [2, 1, 5]]);
movieRentingSystem.search(1);  // 返回 [1, 0, 2] ，商店 1，0 和 2 有未借出的 ID 为 1 的电影。商店 1 最便宜，商店 0 和 2 价格相同，所以按商店编号排序。
movieRentingSystem.rent(0, 1); // 从商店 0 借出电影 1 。现在商店 0 未借出电影编号为 [2,3] 。
movieRentingSystem.rent(1, 2); // 从商店 1 借出电影 2 。现在商店 1 未借出的电影编号为 [1] 。
movieRentingSystem.report();   // 返回 [[0, 1], [1, 2]] 。商店 0 借出的电影 1 最便宜，然后是商店 1 借出的电影 2 。
movieRentingSystem.drop(1, 2); // 在商店 1 返还电影 2 。现在商店 1 未借出的电影编号为 [1,2] 。
movieRentingSystem.search(2);  // 返回 [0, 1] 。商店 0 和 1 有未借出的 ID 为 2 的电影。商店 0 最便宜，然后是商店 1 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= n <= 3 * 10<sup>5</sup></code></li>
	<li><code>1 <= entries.length <= 10<sup>5</sup></code></li>
	<li><code>0 <= shop<sub>i</sub> < n</code></li>
	<li><code>1 <= movie<sub>i</sub>, price<sub>i</sub> <= 10<sup>4</sup></code></li>
	<li>每个商店 <strong>至多</strong> 有一份电影 <code>movie<sub>i</sub></code> 的拷贝。</li>
	<li><code>search</code>，<code>rent</code>，<code>drop</code> 和 <code>report</code> 的调用 <strong>总共</strong> 不超过 <code>10<sup>5</sup></code> 次。</li>
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
class MovieRentingSystem:
    def __init__(self, n: int, entries: List[List[int]]):
        self.unrented = collections.defaultdict(SortedList)  # {movie: (price, shop)}
        self.shopAndMovieToPrice = {}  # {(shop, movie): price}
        self.rented = SortedList()  # (price, shop, movie)
        for shop, movie, price in entries:
            self.unrented[movie].add((price, shop))
            self.shopAndMovieToPrice[(shop, movie)] = price

    def search(self, movie: int) -> List[int]:
        return [shop for _, shop in self.unrented[movie][:5]]

    def rent(self, shop: int, movie: int) -> None:
        price = self.shopAndMovieToPrice[(shop, movie)]
        self.unrented[movie].remove((price, shop))
        self.rented.add((price, shop, movie))

    def drop(self, shop: int, movie: int) -> None:
        price = self.shopAndMovieToPrice[(shop, movie)]
        self.unrented[movie].add((price, shop))
        self.rented.remove((price, shop, movie))

    def report(self) -> List[List[int]]:
        return [[shop, movie] for _, shop, movie in self.rented[:5]]


# Your MovieRentingSystem object will be instantiated and called as such:
# obj = MovieRentingSystem(n, entries)
# param_1 = obj.search(movie)
# obj.rent(shop,movie)
# obj.drop(shop,movie)
# param_4 = obj.report()
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1913. 两个数对之间的最大乘积差](https://leetcode.cn/problems/maximum-product-difference-between-two-pairs){#1913}

{{< tabs "1913" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxProductDifference(self, nums: List[int]) -> int:
        nums.sort()
        return nums[-1] * nums[-2] - nums[0] * nums[1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxProductDifference(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        return nums[n - 1] * nums[n - 2] - nums[0] * nums[1];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return nums[n - 1] * nums[n - 2] - nums[0] * nums[1];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxProductDifference(nums []int) int {
	sort.Ints(nums)
	n := len(nums)
	return nums[n-1]*nums[n-2] - nums[0]*nums[1]
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var maxProductDifference = function (nums) {
    nums.sort((a, b) => a - b);
    let n = nums.length;
    let ans = nums[n - 1] * nums[n - 2] - nums[0] * nums[1];
    return ans;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>两个数对 <code>(a, b)</code> 和 <code>(c, d)</code> 之间的 <strong>乘积差</strong> 定义为 <code>(a * b) - (c * d)</code> 。</p>

<ul>
	<li>例如，<code>(5, 6)</code> 和 <code>(2, 7)</code> 之间的乘积差是 <code>(5 * 6) - (2 * 7) = 16</code> 。</li>
</ul>

<p>给你一个整数数组 <code>nums</code> ，选出四个 <strong>不同的</strong> 下标 <code>w</code>、<code>x</code>、<code>y</code> 和 <code>z</code> ，使数对 <code>(nums[w], nums[x])</code> 和 <code>(nums[y], nums[z])</code> 之间的 <strong>乘积差</strong> 取到 <strong>最大值</strong> 。</p>

<p>返回以这种方式取得的乘积差中的 <strong>最大值</strong> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [5,6,2,7,4]
<strong>输出：</strong>34
<strong>解释：</strong>可以选出下标为 1 和 3 的元素构成第一个数对 (6, 7) 以及下标 2 和 4 构成第二个数对 (2, 4)
乘积差是 (6 * 7) - (2 * 4) = 34
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [4,2,5,9,7,4,8]
<strong>输出：</strong>64
<strong>解释：</strong>可以选出下标为 3 和 6 的元素构成第一个数对 (9, 8) 以及下标 1 和 5 构成第二个数对 (2, 4)
乘积差是 (9 * 8) - (2 * 4) = 64
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>4 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
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
    def maxProductDifference(self, nums: List[int]) -> int:
        nums.sort()
        return nums[-1] * nums[-2] - nums[0] * nums[1]
```

#### Java

```java
class Solution {
    public int maxProductDifference(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        return nums[n - 1] * nums[n - 2] - nums[0] * nums[1];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return nums[n - 1] * nums[n - 2] - nums[0] * nums[1];
    }
};
```

#### Go

```go
func maxProductDifference(nums []int) int {
	sort.Ints(nums)
	n := len(nums)
	return nums[n-1]*nums[n-2] - nums[0]*nums[1]
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var maxProductDifference = function (nums) {
    nums.sort((a, b) => a - b);
    let n = nums.length;
    let ans = nums[n - 1] * nums[n - 2] - nums[0] * nums[1];
    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1914. 循环轮转矩阵](https://leetcode.cn/problems/cyclically-rotating-a-grid){#1914}

{{< tabs "1914" >}}

{{% tab "python" %}}
```python
class Solution:
    def rotateGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        def rotate(p: int, k: int):
            nums = []
            for j in range(p, n - p - 1):
                nums.append(grid[p][j])
            for i in range(p, m - p - 1):
                nums.append(grid[i][n - p - 1])
            for j in range(n - p - 1, p, -1):
                nums.append(grid[m - p - 1][j])
            for i in range(m - p - 1, p, -1):
                nums.append(grid[i][p])
            k %= len(nums)
            if k == 0:
                return
            nums = nums[k:] + nums[:k]
            k = 0
            for j in range(p, n - p - 1):
                grid[p][j] = nums[k]
                k += 1
            for i in range(p, m - p - 1):
                grid[i][n - p - 1] = nums[k]
                k += 1
            for j in range(n - p - 1, p, -1):
                grid[m - p - 1][j] = nums[k]
                k += 1
            for i in range(m - p - 1, p, -1):
                grid[i][p] = nums[k]
                k += 1

        m, n = len(grid), len(grid[0])
        for p in range(min(m, n) >> 1):
            rotate(p, k)
        return grid
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int m;
    private int n;
    private int[][] grid;

    public int[][] rotateGrid(int[][] grid, int k) {
        m = grid.length;
        n = grid[0].length;
        this.grid = grid;
        for (int p = 0; p < Math.min(m, n) / 2; ++p) {
            rotate(p, k);
        }
        return grid;
    }

    private void rotate(int p, int k) {
        List<Integer> nums = new ArrayList<>();
        for (int j = p; j < n - p - 1; ++j) {
            nums.add(grid[p][j]);
        }
        for (int i = p; i < m - p - 1; ++i) {
            nums.add(grid[i][n - p - 1]);
        }
        for (int j = n - p - 1; j > p; --j) {
            nums.add(grid[m - p - 1][j]);
        }
        for (int i = m - p - 1; i > p; --i) {
            nums.add(grid[i][p]);
        }
        int l = nums.size();
        k %= l;
        if (k == 0) {
            return;
        }
        for (int j = p; j < n - p - 1; ++j) {
            grid[p][j] = nums.get(k++ % l);
        }
        for (int i = p; i < m - p - 1; ++i) {
            grid[i][n - p - 1] = nums.get(k++ % l);
        }
        for (int j = n - p - 1; j > p; --j) {
            grid[m - p - 1][j] = nums.get(k++ % l);
        }
        for (int i = m - p - 1; i > p; --i) {
            grid[i][p] = nums.get(k++ % l);
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        auto rotate = [&](int p, int k) {
            vector<int> nums;
            for (int j = p; j < n - p - 1; ++j) {
                nums.push_back(grid[p][j]);
            }
            for (int i = p; i < m - p - 1; ++i) {
                nums.push_back(grid[i][n - p - 1]);
            }
            for (int j = n - p - 1; j > p; --j) {
                nums.push_back(grid[m - p - 1][j]);
            }
            for (int i = m - p - 1; i > p; --i) {
                nums.push_back(grid[i][p]);
            }
            int l = nums.size();
            k %= l;
            if (k == 0) {
                return;
            }
            for (int j = p; j < n - p - 1; ++j) {
                grid[p][j] = nums[k++ % l];
            }
            for (int i = p; i < m - p - 1; ++i) {
                grid[i][n - p - 1] = nums[k++ % l];
            }
            for (int j = n - p - 1; j > p; --j) {
                grid[m - p - 1][j] = nums[k++ % l];
            }
            for (int i = m - p - 1; i > p; --i) {
                grid[i][p] = nums[k++ % l];
            }
        };
        for (int p = 0; p < min(m, n) / 2; ++p) {
            rotate(p, k);
        }
        return grid;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func rotateGrid(grid [][]int, k int) [][]int {
	m, n := len(grid), len(grid[0])

	rotate := func(p, k int) {
		nums := []int{}
		for j := p; j < n-p-1; j++ {
			nums = append(nums, grid[p][j])
		}
		for i := p; i < m-p-1; i++ {
			nums = append(nums, grid[i][n-p-1])
		}
		for j := n - p - 1; j > p; j-- {
			nums = append(nums, grid[m-p-1][j])
		}
		for i := m - p - 1; i > p; i-- {
			nums = append(nums, grid[i][p])
		}
		l := len(nums)
		k %= l
		if k == 0 {
			return
		}
		for j := p; j < n-p-1; j++ {
			grid[p][j] = nums[k]
			k = (k + 1) % l
		}
		for i := p; i < m-p-1; i++ {
			grid[i][n-p-1] = nums[k]
			k = (k + 1) % l
		}
		for j := n - p - 1; j > p; j-- {
			grid[m-p-1][j] = nums[k]
			k = (k + 1) % l
		}
		for i := m - p - 1; i > p; i-- {
			grid[i][p] = nums[k]
			k = (k + 1) % l
		}
	}

	for i := 0; i < m/2 && i < n/2; i++ {
		rotate(i, k)
	}
	return grid
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function rotateGrid(grid: number[][], k: number): number[][] {
    const m = grid.length;
    const n = grid[0].length;
    const rotate = (p: number, k: number) => {
        const nums: number[] = [];
        for (let j = p; j < n - p - 1; ++j) {
            nums.push(grid[p][j]);
        }
        for (let i = p; i < m - p - 1; ++i) {
            nums.push(grid[i][n - p - 1]);
        }
        for (let j = n - p - 1; j > p; --j) {
            nums.push(grid[m - p - 1][j]);
        }
        for (let i = m - p - 1; i > p; --i) {
            nums.push(grid[i][p]);
        }
        const l = nums.length;
        k %= l;
        if (k === 0) {
            return;
        }
        for (let j = p; j < n - p - 1; ++j) {
            grid[p][j] = nums[k++ % l];
        }
        for (let i = p; i < m - p - 1; ++i) {
            grid[i][n - p - 1] = nums[k++ % l];
        }
        for (let j = n - p - 1; j > p; --j) {
            grid[m - p - 1][j] = nums[k++ % l];
        }
        for (let i = m - p - 1; i > p; --i) {
            grid[i][p] = nums[k++ % l];
        }
    };
    for (let p = 0; p < Math.min(m, n) >> 1; ++p) {
        rotate(p, k);
    }
    return grid;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个大小为 <code>m x n</code> 的整数矩阵 <code>grid</code>​​​ ，其中 <code>m</code> 和 <code>n</code> 都是 <strong>偶数</strong> ；另给你一个整数 <code>k</code> 。</p>

<p>矩阵由若干层组成，如下图所示，每种颜色代表一层：</p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1900-1999/1914.Cyclically%20Rotating%20a%20Grid/images/ringofgrid.png" style="width: 231px; height: 258px;"></p>

<p>矩阵的循环轮转是通过分别循环轮转矩阵中的每一层完成的。在对某一层进行一次循环旋转操作时，层中的每一个元素将会取代其 <strong>逆时针 </strong>方向的相邻元素。轮转示例如下：</p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1900-1999/1914.Cyclically%20Rotating%20a%20Grid/images/explanation_grid.jpg" style="width: 500px; height: 268px;">
<p>返回执行 <code>k</code> 次循环轮转操作后的矩阵。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1900-1999/1914.Cyclically%20Rotating%20a%20Grid/images/rod2.png" style="width: 421px; height: 191px;">
<pre><strong>输入：</strong>grid = [[40,10],[30,20]], k = 1
<strong>输出：</strong>[[10,20],[40,30]]
<strong>解释：</strong>上图展示了矩阵在执行循环轮转操作时每一步的状态。</pre>

<p><strong>示例 2：</strong></p>
<strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1900-1999/1914.Cyclically%20Rotating%20a%20Grid/images/ringofgrid5.png" style="width: 231px; height: 262px;"></strong> <strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1900-1999/1914.Cyclically%20Rotating%20a%20Grid/images/ringofgrid6.png" style="width: 231px; height: 262px;"></strong> <strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1900-1999/1914.Cyclically%20Rotating%20a%20Grid/images/ringofgrid7.png" style="width: 231px; height: 262px;"></strong>

<pre><strong>输入：</strong>grid = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]], k = 2
<strong>输出：</strong>[[3,4,8,12],[2,11,10,16],[1,7,6,15],[5,9,13,14]]
<strong>解释：</strong>上图展示了矩阵在执行循环轮转操作时每一步的状态。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>2 &lt;= m, n &lt;= 50</code></li>
	<li><code>m</code> 和 <code>n</code> 都是 <strong>偶数</strong></li>
	<li><code>1 &lt;= grid[i][j] &lt;=<sup> </sup>5000</code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：逐层模拟

我们先计算得到矩阵的层数 $p$，然后从外到内逐层模拟循环轮转的过程。

对于每一层，我们按照顺时针方向，将上、右、下、左四条边的元素依次放入数组 $nums$ 中。记数组 $nums$ 的长度为 $l$。接下来，我们将 $k$ 模 $l$。然后从数组的第 $k$ 个位置开始，将数组中的元素依次放回矩阵的上、右、下、左四条边。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m + n)$。其中 $m$ 和 $n$ 分别是矩阵的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def rotateGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        def rotate(p: int, k: int):
            nums = []
            for j in range(p, n - p - 1):
                nums.append(grid[p][j])
            for i in range(p, m - p - 1):
                nums.append(grid[i][n - p - 1])
            for j in range(n - p - 1, p, -1):
                nums.append(grid[m - p - 1][j])
            for i in range(m - p - 1, p, -1):
                nums.append(grid[i][p])
            k %= len(nums)
            if k == 0:
                return
            nums = nums[k:] + nums[:k]
            k = 0
            for j in range(p, n - p - 1):
                grid[p][j] = nums[k]
                k += 1
            for i in range(p, m - p - 1):
                grid[i][n - p - 1] = nums[k]
                k += 1
            for j in range(n - p - 1, p, -1):
                grid[m - p - 1][j] = nums[k]
                k += 1
            for i in range(m - p - 1, p, -1):
                grid[i][p] = nums[k]
                k += 1

        m, n = len(grid), len(grid[0])
        for p in range(min(m, n) >> 1):
            rotate(p, k)
        return grid
```

#### Java

```java
class Solution {
    private int m;
    private int n;
    private int[][] grid;

    public int[][] rotateGrid(int[][] grid, int k) {
        m = grid.length;
        n = grid[0].length;
        this.grid = grid;
        for (int p = 0; p < Math.min(m, n) / 2; ++p) {
            rotate(p, k);
        }
        return grid;
    }

    private void rotate(int p, int k) {
        List<Integer> nums = new ArrayList<>();
        for (int j = p; j < n - p - 1; ++j) {
            nums.add(grid[p][j]);
        }
        for (int i = p; i < m - p - 1; ++i) {
            nums.add(grid[i][n - p - 1]);
        }
        for (int j = n - p - 1; j > p; --j) {
            nums.add(grid[m - p - 1][j]);
        }
        for (int i = m - p - 1; i > p; --i) {
            nums.add(grid[i][p]);
        }
        int l = nums.size();
        k %= l;
        if (k == 0) {
            return;
        }
        for (int j = p; j < n - p - 1; ++j) {
            grid[p][j] = nums.get(k++ % l);
        }
        for (int i = p; i < m - p - 1; ++i) {
            grid[i][n - p - 1] = nums.get(k++ % l);
        }
        for (int j = n - p - 1; j > p; --j) {
            grid[m - p - 1][j] = nums.get(k++ % l);
        }
        for (int i = m - p - 1; i > p; --i) {
            grid[i][p] = nums.get(k++ % l);
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        auto rotate = [&](int p, int k) {
            vector<int> nums;
            for (int j = p; j < n - p - 1; ++j) {
                nums.push_back(grid[p][j]);
            }
            for (int i = p; i < m - p - 1; ++i) {
                nums.push_back(grid[i][n - p - 1]);
            }
            for (int j = n - p - 1; j > p; --j) {
                nums.push_back(grid[m - p - 1][j]);
            }
            for (int i = m - p - 1; i > p; --i) {
                nums.push_back(grid[i][p]);
            }
            int l = nums.size();
            k %= l;
            if (k == 0) {
                return;
            }
            for (int j = p; j < n - p - 1; ++j) {
                grid[p][j] = nums[k++ % l];
            }
            for (int i = p; i < m - p - 1; ++i) {
                grid[i][n - p - 1] = nums[k++ % l];
            }
            for (int j = n - p - 1; j > p; --j) {
                grid[m - p - 1][j] = nums[k++ % l];
            }
            for (int i = m - p - 1; i > p; --i) {
                grid[i][p] = nums[k++ % l];
            }
        };
        for (int p = 0; p < min(m, n) / 2; ++p) {
            rotate(p, k);
        }
        return grid;
    }
};
```

#### Go

```go
func rotateGrid(grid [][]int, k int) [][]int {
	m, n := len(grid), len(grid[0])

	rotate := func(p, k int) {
		nums := []int{}
		for j := p; j < n-p-1; j++ {
			nums = append(nums, grid[p][j])
		}
		for i := p; i < m-p-1; i++ {
			nums = append(nums, grid[i][n-p-1])
		}
		for j := n - p - 1; j > p; j-- {
			nums = append(nums, grid[m-p-1][j])
		}
		for i := m - p - 1; i > p; i-- {
			nums = append(nums, grid[i][p])
		}
		l := len(nums)
		k %= l
		if k == 0 {
			return
		}
		for j := p; j < n-p-1; j++ {
			grid[p][j] = nums[k]
			k = (k + 1) % l
		}
		for i := p; i < m-p-1; i++ {
			grid[i][n-p-1] = nums[k]
			k = (k + 1) % l
		}
		for j := n - p - 1; j > p; j-- {
			grid[m-p-1][j] = nums[k]
			k = (k + 1) % l
		}
		for i := m - p - 1; i > p; i-- {
			grid[i][p] = nums[k]
			k = (k + 1) % l
		}
	}

	for i := 0; i < m/2 && i < n/2; i++ {
		rotate(i, k)
	}
	return grid
}
```

#### TypeScript

```ts
function rotateGrid(grid: number[][], k: number): number[][] {
    const m = grid.length;
    const n = grid[0].length;
    const rotate = (p: number, k: number) => {
        const nums: number[] = [];
        for (let j = p; j < n - p - 1; ++j) {
            nums.push(grid[p][j]);
        }
        for (let i = p; i < m - p - 1; ++i) {
            nums.push(grid[i][n - p - 1]);
        }
        for (let j = n - p - 1; j > p; --j) {
            nums.push(grid[m - p - 1][j]);
        }
        for (let i = m - p - 1; i > p; --i) {
            nums.push(grid[i][p]);
        }
        const l = nums.length;
        k %= l;
        if (k === 0) {
            return;
        }
        for (let j = p; j < n - p - 1; ++j) {
            grid[p][j] = nums[k++ % l];
        }
        for (let i = p; i < m - p - 1; ++i) {
            grid[i][n - p - 1] = nums[k++ % l];
        }
        for (let j = n - p - 1; j > p; --j) {
            grid[m - p - 1][j] = nums[k++ % l];
        }
        for (let i = m - p - 1; i > p; --i) {
            grid[i][p] = nums[k++ % l];
        }
    };
    for (let p = 0; p < Math.min(m, n) >> 1; ++p) {
        rotate(p, k);
    }
    return grid;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1915. 最美子字符串的数目](https://leetcode.cn/problems/number-of-wonderful-substrings){#1915}

{{< tabs "1915" >}}

{{% tab "python" %}}
```python
class Solution:
    def wonderfulSubstrings(self, word: str) -> int:
        cnt = Counter({0: 1})
        ans = st = 0
        for c in word:
            st ^= 1 << (ord(c) - ord("a"))
            ans += cnt[st]
            for i in range(10):
                ans += cnt[st ^ (1 << i)]
            cnt[st] += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long wonderfulSubstrings(String word) {
        int[] cnt = new int[1 << 10];
        cnt[0] = 1;
        long ans = 0;
        int st = 0;
        for (char c : word.toCharArray()) {
            st ^= 1 << (c - 'a');
            ans += cnt[st];
            for (int i = 0; i < 10; ++i) {
                ans += cnt[st ^ (1 << i)];
            }
            ++cnt[st];
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
    long long wonderfulSubstrings(string word) {
        int cnt[1024] = {1};
        long long ans = 0;
        int st = 0;
        for (char c : word) {
            st ^= 1 << (c - 'a');
            ans += cnt[st];
            for (int i = 0; i < 10; ++i) {
                ans += cnt[st ^ (1 << i)];
            }
            ++cnt[st];
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func wonderfulSubstrings(word string) (ans int64) {
	cnt := [1024]int{1}
	st := 0
	for _, c := range word {
		st ^= 1 << (c - 'a')
		ans += int64(cnt[st])
		for i := 0; i < 10; i++ {
			ans += int64(cnt[st^(1<<i)])
		}
		cnt[st]++
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function wonderfulSubstrings(word: string): number {
    const cnt: number[] = new Array(1 << 10).fill(0);
    cnt[0] = 1;
    let ans = 0;
    let st = 0;
    for (const c of word) {
        st ^= 1 << (c.charCodeAt(0) - 'a'.charCodeAt(0));
        ans += cnt[st];
        for (let i = 0; i < 10; ++i) {
            ans += cnt[st ^ (1 << i)];
        }
        cnt[st]++;
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {string} word
 * @return {number}
 */
var wonderfulSubstrings = function (word) {
    const cnt = new Array(1024).fill(0);
    cnt[0] = 1;
    let ans = 0;
    let st = 0;
    for (const c of word) {
        st ^= 1 << (c.charCodeAt() - 'a'.charCodeAt());
        ans += cnt[st];
        for (let i = 0; i < 10; ++i) {
            ans += cnt[st ^ (1 << i)];
        }
        cnt[st]++;
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

<p>如果某个字符串中 <strong>至多一个</strong> 字母出现 <strong>奇数</strong> 次，则称其为 <strong>最美</strong> 字符串。</p>

<ul>
	<li>例如，<code>"ccjjc"</code> 和 <code>"abab"</code> 都是最美字符串，但 <code>"ab"</code> 不是。</li>
</ul>

<p>给你一个字符串 <code>word</code> ，该字符串由前十个小写英文字母组成（<code>'a'</code> 到 <code>'j'</code>）。请你返回 <code>word</code> 中 <strong>最美非空子字符串</strong> 的数目<em>。</em>如果同样的子字符串在<em> </em><code>word</code> 中出现多次，那么应当对 <strong>每次出现</strong> 分别计数<em>。</em></p>

<p><strong>子字符串</strong> 是字符串中的一个连续字符序列。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>word = "aba"
<strong>输出：</strong>4
<strong>解释：</strong>4 个最美子字符串如下所示：
- "<strong>a</strong>ba" -> "a"
- "a<strong>b</strong>a" -> "b"
- "ab<strong>a</strong>" -> "a"
- "<strong>aba</strong>" -> "aba"
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>word = "aabb"
<strong>输出：</strong>9
<strong>解释：</strong>9 个最美子字符串如下所示：
- "<strong>a</strong>abb" -> "a"
- "<strong>aa</strong>bb" -> "aa"
- "<strong>aab</strong>b" -> "aab"
- "<strong>aabb</strong>" -> "aabb"
- "a<strong>a</strong>bb" -> "a"
- "a<strong>abb</strong>" -> "abb"
- "aa<strong>b</strong>b" -> "b"
- "aa<strong>bb</strong>" -> "bb"
- "aab<strong>b</strong>" -> "b"
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>word = "he"
<strong>输出：</strong>2
<strong>解释：</strong>2 个最美子字符串如下所示：
- "<b>h</b>e" -> "h"
- "h<strong>e</strong>" -> "e"
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= word.length <= 10<sup>5</sup></code></li>
	<li><code>word</code> 由从 <code>'a'</code> 到 <code>'j'</code> 的小写英文字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前缀异或 + 计数

由于字符串中只包含 $10$ 个小写字母，因此可以用一个长度为 $10$ 的二进制数表示字符串中每个字母的奇偶性，其中第 $i$ 位为 $1$ 表示第 $i$ 个字母出现了奇数次，为 $0$ 表示第 $i$ 个字母出现了偶数次。

我们遍历字符串的每个字符，用一个变量 $st$ 维护当前字符串的前缀异或值，用一个数组 $cnt$ 维护每个前缀异或值出现的次数，初始时 $st = 0$, $cnt[0] = 1$。

对于当前遍历到的字符，我们更新其前缀异或值。如果当前的前缀异或值出现了 $cnt[st]$ 次，也就意味着有 $cnt[st]$ 个子字符串满足所有字母的出现次数均为偶数，因此我们将答案增加 $cnt[st]$。此外，对于 $0 \le i < 10$，如果当前的前缀异或值 $st$ 的第 $i$ 位为 $1$，那么我们还可以找到一个字母出现了奇数次，我们将答案增加 $cnt[st \oplus (1 << i)]$。最后，我们将 $st$ 出现的次数增加 $1$。继续遍历下一个字符，直到遍历完整个字符串。

时间复杂度 $O(n \times \Sigma)$，空间复杂度 $O(2^{\Sigma})$，其中 $\Sigma = 10$，而 $n$ 为字符串的长度。

相似题目：

-   [1371. 每个元音包含偶数次的最长子字符串](https://github.com/doocs/leetcode/blob/main/solution/1300-1399/1371.Find%20the%20Longest%20Substring%20Containing%20Vowels%20in%20Even%20Counts/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def wonderfulSubstrings(self, word: str) -> int:
        cnt = Counter({0: 1})
        ans = st = 0
        for c in word:
            st ^= 1 << (ord(c) - ord("a"))
            ans += cnt[st]
            for i in range(10):
                ans += cnt[st ^ (1 << i)]
            cnt[st] += 1
        return ans
```

#### Java

```java
class Solution {
    public long wonderfulSubstrings(String word) {
        int[] cnt = new int[1 << 10];
        cnt[0] = 1;
        long ans = 0;
        int st = 0;
        for (char c : word.toCharArray()) {
            st ^= 1 << (c - 'a');
            ans += cnt[st];
            for (int i = 0; i < 10; ++i) {
                ans += cnt[st ^ (1 << i)];
            }
            ++cnt[st];
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long wonderfulSubstrings(string word) {
        int cnt[1024] = {1};
        long long ans = 0;
        int st = 0;
        for (char c : word) {
            st ^= 1 << (c - 'a');
            ans += cnt[st];
            for (int i = 0; i < 10; ++i) {
                ans += cnt[st ^ (1 << i)];
            }
            ++cnt[st];
        }
        return ans;
    }
};
```

#### Go

```go
func wonderfulSubstrings(word string) (ans int64) {
	cnt := [1024]int{1}
	st := 0
	for _, c := range word {
		st ^= 1 << (c - 'a')
		ans += int64(cnt[st])
		for i := 0; i < 10; i++ {
			ans += int64(cnt[st^(1<<i)])
		}
		cnt[st]++
	}
	return
}
```

#### TypeScript

```ts
function wonderfulSubstrings(word: string): number {
    const cnt: number[] = new Array(1 << 10).fill(0);
    cnt[0] = 1;
    let ans = 0;
    let st = 0;
    for (const c of word) {
        st ^= 1 << (c.charCodeAt(0) - 'a'.charCodeAt(0));
        ans += cnt[st];
        for (let i = 0; i < 10; ++i) {
            ans += cnt[st ^ (1 << i)];
        }
        cnt[st]++;
    }
    return ans;
}
```

#### JavaScript

```js
/**
 * @param {string} word
 * @return {number}
 */
var wonderfulSubstrings = function (word) {
    const cnt = new Array(1024).fill(0);
    cnt[0] = 1;
    let ans = 0;
    let st = 0;
    for (const c of word) {
        st ^= 1 << (c.charCodeAt() - 'a'.charCodeAt());
        ans += cnt[st];
        for (let i = 0; i < 10; ++i) {
            ans += cnt[st ^ (1 << i)];
        }
        cnt[st]++;
    }
    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1916. 统计为蚁群构筑房间的不同顺序](https://leetcode.cn/problems/count-ways-to-build-rooms-in-an-ant-colony){#1916}

{{< tabs "1916" >}}

{{% tab "python" %}}
```python
class Solution:
    def waysToBuildRooms(self, prevRoom: List[int]) -> int:
        modulo = 10**9 + 7
        ingoing = defaultdict(set)
        outgoing = defaultdict(set)

        for i in range(1, len(prevRoom)):
            ingoing[i].add(prevRoom[i])
            outgoing[prevRoom[i]].add(i)
        ans = [1]

        def recurse(i):
            if len(outgoing[i]) == 0:
                return 1

            nodes_in_tree = 0
            for v in outgoing[i]:
                cn = recurse(v)
                if nodes_in_tree != 0:
                    ans[0] *= comb(nodes_in_tree + cn, cn)
                    ans[0] %= modulo
                nodes_in_tree += cn
            return nodes_in_tree + 1

        recurse(0)
        return ans[0] % modulo
```
{{% /tab %}}
{{% tab "java" %}}
```java

```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp

```
{{% /tab %}}
{{% tab "go" %}}
```go

```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你是一只蚂蚁，负责为蚁群构筑 <code>n</code> 间编号从 <code>0</code> 到 <code>n-1</code> 的新房间。给你一个 <strong>下标从 0 开始</strong> 且长度为 <code>n</code> 的整数数组&nbsp;<code>prevRoom</code> 作为扩建计划。其中，<code>prevRoom[i]</code> 表示在构筑房间 <code>i</code> 之前，你必须先构筑房间 <code>prevRoom[i]</code> ，并且这两个房间必须 <strong>直接</strong> 相连。房间 <code>0</code> 已经构筑完成，所以 <code>prevRoom[0] = -1</code> 。扩建计划中还有一条硬性要求，在完成所有房间的构筑之后，从房间 <code>0</code> 可以访问到每个房间。</p>

<p>你一次只能构筑 <strong>一个</strong> 房间。你可以在 <strong>已经构筑好的</strong> 房间之间自由穿行，只要这些房间是 <strong>相连的</strong> 。如果房间&nbsp;<code>prevRoom[i]</code> 已经构筑完成，那么你就可以构筑房间 <code>i</code>。</p>

<p>返回你构筑所有房间的 <strong>不同顺序的数目</strong> 。由于答案可能很大，请返回对 <code>10<sup>9</sup> + 7</code> <strong>取余</strong> 的结果。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1900-1999/1916.Count%20Ways%20to%20Build%20Rooms%20in%20an%20Ant%20Colony/images/d1.jpg" style="width: 200px; height: 212px;" />
<pre>
<strong>输入：</strong><code>prevRoom</code> = [-1,0,1]
<strong>输出：</strong>1
<strong>解释：</strong>仅有一种方案可以完成所有房间的构筑：0 → 1 → 2
</pre>

<p><strong>示例 2：</strong></p>
<strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1900-1999/1916.Count%20Ways%20to%20Build%20Rooms%20in%20an%20Ant%20Colony/images/d2.jpg" style="width: 200px; height: 239px;" /></strong>

<pre>
<strong>输入：</strong><code>prevRoom</code> = [-1,0,0,1,2]
<strong>输出：</strong>6
<strong>解释：
</strong>有 6 种不同顺序：
0 → 1 → 3 → 2 → 4
0 → 2 → 4 → 1 → 3
0 → 1 → 2 → 3 → 4
0 → 1 → 2 → 4 → 3
0 → 2 → 1 → 3 → 4
0 → 2 → 1 → 4 → 3
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == prevRoom.length</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>prevRoom[0] == -1</code></li>
	<li>对于所有的&nbsp;<code>1 &lt;= i &lt; n</code>&nbsp;，都有&nbsp;<code>0 &lt;= prevRoom[i] &lt; n</code></li>
	<li>题目保证所有房间都构筑完成后，从房间 <code>0</code> 可以访问到每个房间</li>
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
    def waysToBuildRooms(self, prevRoom: List[int]) -> int:
        modulo = 10**9 + 7
        ingoing = defaultdict(set)
        outgoing = defaultdict(set)

        for i in range(1, len(prevRoom)):
            ingoing[i].add(prevRoom[i])
            outgoing[prevRoom[i]].add(i)
        ans = [1]

        def recurse(i):
            if len(outgoing[i]) == 0:
                return 1

            nodes_in_tree = 0
            for v in outgoing[i]:
                cn = recurse(v)
                if nodes_in_tree != 0:
                    ans[0] *= comb(nodes_in_tree + cn, cn)
                    ans[0] %= modulo
                nodes_in_tree += cn
            return nodes_in_tree + 1

        recurse(0)
        return ans[0] % modulo
```

#### Java

```java

```

#### C++

```cpp

```

#### Go

```go

```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1917. Leetcodify 好友推荐 🔒](https://leetcode.cn/problems/leetcodify-friends-recommendations){#1917}

{{< tabs "1917" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT user1_id, user2_id FROM Friendship
        UNION
        SELECT user2_id AS user1_id, user1_id AS user2_id FROM Friendship
    )
SELECT DISTINCT l1.user_id, l2.user_id AS recommended_id
FROM
    Listens AS l1,
    Listens AS l2
WHERE
    l1.day = l2.day
    AND l1.song_id = l2.song_id
    AND l1.user_id != l2.user_id
    AND NOT EXISTS (
        SELECT 1
        FROM T AS t
        WHERE l1.user_id = t.user1_id AND l2.user_id = t.user2_id
    )
GROUP BY l1.day, l1.user_id, l2.user_id
HAVING COUNT(DISTINCT l1.song_id) >= 3;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表： <code>Listens</code></p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| user_id     | int     |
| song_id     | int     |
| day         | date    |
+-------------+---------+
这个表没有主键，可能存在重复项。
表中的每一行表示用户 user_id 在 day 这一天收听的歌曲 song_id。
</pre>

<p>&nbsp;</p>

<p>表： <code>Friendship</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| user1_id      | int     |
| user2_id      | int     |
+---------------+---------+
(user1_id, user2_id) 是这个表的主键。
表中的每一行表示 user1_id 和 user2_id 是好友。
注意，user1_id &lt; user2_id。
</pre>

<p>&nbsp;</p>

<p>写出 SQL 语句，为 Leetcodify 用户推荐好友。我们将符合下列条件的用户 <code>x</code> 推荐给用户 <code>y</code> ：</p>

<ul>
	<li>用户 <code>x</code> 和 <code>y</code> 不是好友，且</li>
	<li>用户 <code>x</code> 和 <code>y</code> 在<strong>同一天</strong>收听了相同的三首或更多不同歌曲。</li>
</ul>

<p>注意，好友推荐是<strong>单向</strong>的，这意味着如果用户 <code>x</code> 和用户 <code>y</code> 需要互相推荐给对方，结果表需要将用户 <code>x</code> 推荐给用户 <code>y</code> 并将用户 <code>y</code> 推荐给用户 <code>x</code>。另外，结果表不得出现重复项（即，用户 <code>y</code> 不可多次推荐给用户 <code>x</code> ）。</p>

<p>按<strong>任意顺序</strong>返回结果表。</p>

<p>查询格式如下示例所示：</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入：</strong>
Listens 表：
+---------+---------+------------+
| user_id | song_id | day        |
+---------+---------+------------+
| 1       | 10      | 2021-03-15 |
| 1       | 11      | 2021-03-15 |
| 1       | 12      | 2021-03-15 |
| 2       | 10      | 2021-03-15 |
| 2       | 11      | 2021-03-15 |
| 2       | 12      | 2021-03-15 |
| 3       | 10      | 2021-03-15 |
| 3       | 11      | 2021-03-15 |
| 3       | 12      | 2021-03-15 |
| 4       | 10      | 2021-03-15 |
| 4       | 11      | 2021-03-15 |
| 4       | 13      | 2021-03-15 |
| 5       | 10      | 2021-03-16 |
| 5       | 11      | 2021-03-16 |
| 5       | 12      | 2021-03-16 |
+---------+---------+------------+
Friendship 表：
+----------+----------+
| user1_id | user2_id |
+----------+----------+
| 1        | 2        |
+----------+----------+
<strong>输出：</strong>
+---------+----------------+
| user_id | recommended_id |
+---------+----------------+
| 1       | 3              |
| 2       | 3              |
| 3       | 1              |
| 3       | 2              |
+---------+----------------+
<strong>解释</strong>
用户 1 和 2 在同一天收听了歌曲 10、11 和 12，但他们已经是好友了。
用户 1 和 3 在同一天收听了歌曲 10、11 和 12。由于他们不是好友，所以我们给他们互相推荐为好友。
用户 1 和 4 没有收听三首相同的歌曲。
用户 1 和 5 收听了歌曲 10、11 和 12，但不是在同一天收听的。

类似地，我们可以发现用户 2 和 3 在同一天收听了歌曲 10、11 和 12，且他们不是好友，所以我们给他们互相推荐为好友。
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
    T AS (
        SELECT user1_id, user2_id FROM Friendship
        UNION
        SELECT user2_id AS user1_id, user1_id AS user2_id FROM Friendship
    )
SELECT DISTINCT l1.user_id, l2.user_id AS recommended_id
FROM
    Listens AS l1,
    Listens AS l2
WHERE
    l1.day = l2.day
    AND l1.song_id = l2.song_id
    AND l1.user_id != l2.user_id
    AND NOT EXISTS (
        SELECT 1
        FROM T AS t
        WHERE l1.user_id = t.user1_id AND l2.user_id = t.user2_id
    )
GROUP BY l1.day, l1.user_id, l2.user_id
HAVING COUNT(DISTINCT l1.song_id) >= 3;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1918. 第 K 小的子数组和 🔒](https://leetcode.cn/problems/kth-smallest-subarray-sum){#1918}

{{< tabs "1918" >}}

{{% tab "python" %}}
```python
class Solution:
    def kthSmallestSubarraySum(self, nums: List[int], k: int) -> int:
        def f(s):
            t = j = 0
            cnt = 0
            for i, x in enumerate(nums):
                t += x
                while t > s:
                    t -= nums[j]
                    j += 1
                cnt += i - j + 1
            return cnt >= k

        l, r = min(nums), sum(nums)
        return l + bisect_left(range(l, r + 1), True, key=f)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int kthSmallestSubarraySum(int[] nums, int k) {
        int l = 1 << 30, r = 0;
        for (int x : nums) {
            l = Math.min(l, x);
            r += x;
        }
        while (l < r) {
            int mid = (l + r) >> 1;
            if (f(nums, mid) >= k) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }

    private int f(int[] nums, int s) {
        int t = 0, j = 0;
        int cnt = 0;
        for (int i = 0; i < nums.length; ++i) {
            t += nums[i];
            while (t > s) {
                t -= nums[j++];
            }
            cnt += i - j + 1;
        }
        return cnt;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int kthSmallestSubarraySum(vector<int>& nums, int k) {
        int l = 1 << 30, r = 0;
        for (int& x : nums) {
            l = min(l, x);
            r += x;
        }
        auto f = [&](int s) {
            int cnt = 0, t = 0;
            for (int i = 0, j = 0; i < nums.size(); ++i) {
                t += nums[i];
                while (t > s) {
                    t -= nums[j++];
                }
                cnt += i - j + 1;
            }
            return cnt;
        };
        while (l < r) {
            int mid = (l + r) >> 1;
            if (f(mid) >= k) {
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
func kthSmallestSubarraySum(nums []int, k int) int {
	l, r := 1<<30, 0
	for _, x := range nums {
		l = min(l, x)
		r += x
	}
	f := func(s int) (cnt int) {
		t := 0
		for i, j := 0, 0; i < len(nums); i++ {
			t += nums[i]
			for t > s {
				t -= nums[j]
				j++
			}
			cnt += i - j + 1
		}
		return
	}
	for l < r {
		mid := (l + r) >> 1
		if f(mid) >= k {
			r = mid
		} else {
			l = mid + 1
		}
	}
	return l
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function kthSmallestSubarraySum(nums: number[], k: number): number {
    let l = Math.min(...nums);
    let r = nums.reduce((sum, x) => sum + x, 0);

    const f = (s: number): number => {
        let cnt = 0;
        let t = 0;
        let j = 0;

        for (let i = 0; i < nums.length; i++) {
            t += nums[i];
            while (t > s) {
                t -= nums[j];
                j++;
            }
            cnt += i - j + 1;
        }
        return cnt;
    };

    while (l < r) {
        const mid = (l + r) >> 1;
        if (f(mid) >= k) {
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
    pub fn kth_smallest_subarray_sum(nums: Vec<i32>, k: i32) -> i32 {
        let mut l = *nums.iter().min().unwrap();
        let mut r: i32 = nums.iter().sum();

        let f = |s: i32| -> i32 {
            let (mut cnt, mut t, mut j) = (0, 0, 0);

            for i in 0..nums.len() {
                t += nums[i];
                while t > s {
                    t -= nums[j];
                    j += 1;
                }
                cnt += (i - j + 1) as i32;
            }
            cnt
        };

        while l < r {
            let mid = (l + r) / 2;
            if f(mid) >= k {
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
{{% tab "scala" %}}
```scala
object Solution {
    def kthSmallestSubarraySum(nums: Array[Int], k: Int): Int = {
        var l = Int.MaxValue
        var r = 0

        for (x <- nums) {
            l = l.min(x)
            r += x
        }

        def f(s: Int): Int = {
            var cnt = 0
            var t = 0
            var j = 0

            for (i <- nums.indices) {
                t += nums(i)
                while (t > s) {
                    t -= nums(j)
                    j += 1
                }
                cnt += i - j + 1
            }
            cnt
        }

        while (l < r) {
            val mid = (l + r) / 2
            if (f(mid) >= k) r = mid
            else l = mid + 1
        }
        l
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个 长度为&nbsp;<code>n</code>&nbsp;的整型数组&nbsp;<code>nums</code>&nbsp;和一个数值&nbsp;<code>k</code>&nbsp;，返回<strong> 第<em>&nbsp;</em><code>k</code>&nbsp;小的子数组和<i>。</i></strong></p>

<p><b>子数组</b> 是指数组中一个 <b>非空</b>&nbsp;且不间断的子序列。&nbsp; <b>子数组和</b> 则指子数组中所有元素的和。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> nums = [2,1,3], k = 4
<strong>输出:</strong> 3
<strong>解释: </strong>[2,1,3] 的子数组为：
- [2] 和为 2
- [1] 和为 1
- [3] 和为 3
- [2,1] 和为 3
- [1,3] 和为 4
- [2,1,3] 和为 6 
最小子数组和的升序排序为 1, 2, 3, <strong><em>3</em></strong>, 4, 6。 第 4 小的子数组和为 3 。
</pre>

<strong>示例 2：</strong>

<pre>
<strong>输入：</strong>nums = [3,3,5,5], k = 7
<strong>输出：</strong>10
<strong>解释：</strong>[3,3,5,5] 的子数组为：
- [3] 和为 3
- [3] 和为 3
- [5] 和为 5
- [5] 和为 5
- [3,3] 和为 6
- [3,5] 和为 8
- [5,5] 和为 10
- [3,3,5], 和为 11
- [3,5,5] 和为 13
- [3,3,5,5] 和为 16
最小子数组和的升序排序为 3, 3, 5, 5, 6, 8, <strong><em>10</em></strong>, 11, 13, 16。第 7 小的子数组和为 10 。
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 &lt;= n&nbsp;&lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= k &lt;= n * (n + 1) / 2</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二分查找 + 双指针

我们注意到，题目中数组元素均为正整数，子数组的和 $s$ 越大，那么数组中子数组和小于等于 $s$ 的个数就越多。这存在一个单调性，因此我们可以考虑使用使用二分查找的方法来求解。

我们二分枚举子数组的和，初始化左右边界分别为数组 $\textit{nums}$ 中的最小值以及所有元素之和。每次我们计算数组中子数组和小于等于当前枚举值的个数，如果个数大于等于 $k$，则说明当前枚举值 $s$ 可能是第 $k$ 小的子数组和，我们缩小右边界，否则我们增大左边界。枚举结束后，左边界即为第 $k$ 小的子数组和。

问题转换为计算一个数组中，有多少个子数组的和小于等于 $s$，我们可以通过函数 $f(s)$ 来计算。

函数 $f(s)$ 的计算方法如下：

-   初始化双指针 $j$ 和 $i$，分别指向当前窗口的左右边界，初始时 $j = i = 0$。初始化窗口内元素的和 $t = 0$。
-   用变量 $\textit{cnt}$ 记录子数组和小于等于 $s$ 的个数，初始时 $\textit{cnt} = 0$。
-   遍历数组 $\textit{nums}$，每次遍历到一个元素 $\textit{nums}[i]$，我们将其加入窗口，即 $t = t + \textit{nums}[i]$。如果此时 $t \gt s$，我们需要不断地将窗口的左边界右移，直到 $t \le s$ 为止，即不断地执行 $t -= \textit{nums}[j]$，并且 $j = j + 1$。接下来我们更新 $\textit{cnt}$，即 $\textit{cnt} = \textit{cnt} + i - j + 1$。继续遍历下一个元素，直到遍历完整个数组。

最后将 $cnt$ 作为函数 $f(s)$ 的返回值。

时间复杂度 $O(n \times \log S)$，其中 $n$ 为数组 $\textit{nums}$ 的长度，而 $S$ 为数组 $\textit{nums}$ 中所有元素之和。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def kthSmallestSubarraySum(self, nums: List[int], k: int) -> int:
        def f(s):
            t = j = 0
            cnt = 0
            for i, x in enumerate(nums):
                t += x
                while t > s:
                    t -= nums[j]
                    j += 1
                cnt += i - j + 1
            return cnt >= k

        l, r = min(nums), sum(nums)
        return l + bisect_left(range(l, r + 1), True, key=f)
```

#### Java

```java
class Solution {
    public int kthSmallestSubarraySum(int[] nums, int k) {
        int l = 1 << 30, r = 0;
        for (int x : nums) {
            l = Math.min(l, x);
            r += x;
        }
        while (l < r) {
            int mid = (l + r) >> 1;
            if (f(nums, mid) >= k) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }

    private int f(int[] nums, int s) {
        int t = 0, j = 0;
        int cnt = 0;
        for (int i = 0; i < nums.length; ++i) {
            t += nums[i];
            while (t > s) {
                t -= nums[j++];
            }
            cnt += i - j + 1;
        }
        return cnt;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int kthSmallestSubarraySum(vector<int>& nums, int k) {
        int l = 1 << 30, r = 0;
        for (int& x : nums) {
            l = min(l, x);
            r += x;
        }
        auto f = [&](int s) {
            int cnt = 0, t = 0;
            for (int i = 0, j = 0; i < nums.size(); ++i) {
                t += nums[i];
                while (t > s) {
                    t -= nums[j++];
                }
                cnt += i - j + 1;
            }
            return cnt;
        };
        while (l < r) {
            int mid = (l + r) >> 1;
            if (f(mid) >= k) {
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
func kthSmallestSubarraySum(nums []int, k int) int {
	l, r := 1<<30, 0
	for _, x := range nums {
		l = min(l, x)
		r += x
	}
	f := func(s int) (cnt int) {
		t := 0
		for i, j := 0, 0; i < len(nums); i++ {
			t += nums[i]
			for t > s {
				t -= nums[j]
				j++
			}
			cnt += i - j + 1
		}
		return
	}
	for l < r {
		mid := (l + r) >> 1
		if f(mid) >= k {
			r = mid
		} else {
			l = mid + 1
		}
	}
	return l
}
```

#### TypeScript

```ts
function kthSmallestSubarraySum(nums: number[], k: number): number {
    let l = Math.min(...nums);
    let r = nums.reduce((sum, x) => sum + x, 0);

    const f = (s: number): number => {
        let cnt = 0;
        let t = 0;
        let j = 0;

        for (let i = 0; i < nums.length; i++) {
            t += nums[i];
            while (t > s) {
                t -= nums[j];
                j++;
            }
            cnt += i - j + 1;
        }
        return cnt;
    };

    while (l < r) {
        const mid = (l + r) >> 1;
        if (f(mid) >= k) {
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
    pub fn kth_smallest_subarray_sum(nums: Vec<i32>, k: i32) -> i32 {
        let mut l = *nums.iter().min().unwrap();
        let mut r: i32 = nums.iter().sum();

        let f = |s: i32| -> i32 {
            let (mut cnt, mut t, mut j) = (0, 0, 0);

            for i in 0..nums.len() {
                t += nums[i];
                while t > s {
                    t -= nums[j];
                    j += 1;
                }
                cnt += (i - j + 1) as i32;
            }
            cnt
        };

        while l < r {
            let mid = (l + r) / 2;
            if f(mid) >= k {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        l
    }
}
```

#### Scala

```scala
object Solution {
    def kthSmallestSubarraySum(nums: Array[Int], k: Int): Int = {
        var l = Int.MaxValue
        var r = 0

        for (x <- nums) {
            l = l.min(x)
            r += x
        }

        def f(s: Int): Int = {
            var cnt = 0
            var t = 0
            var j = 0

            for (i <- nums.indices) {
                t += nums(i)
                while (t > s) {
                    t -= nums(j)
                    j += 1
                }
                cnt += i - j + 1
            }
            cnt
        }

        while (l < r) {
            val mid = (l + r) / 2
            if (f(mid) >= k) r = mid
            else l = mid + 1
        }
        l
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1919. 兴趣相同的朋友 🔒](https://leetcode.cn/problems/leetcodify-similar-friends){#1919}

{{< tabs "1919" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT DISTINCT user1_id, user2_id
FROM
    Friendship AS f
    LEFT JOIN Listens AS l1 ON user1_id = l1.user_id
    LEFT JOIN Listens AS l2 ON user2_id = l2.user_id
WHERE l1.song_id = l2.song_id AND l1.day = l2.day
GROUP BY 1, 2, l1.day
HAVING COUNT(DISTINCT l1.song_id) >= 3;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表: <code>Listens</code></p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| user_id     | int     |
| song_id     | int     |
| day         | date    |
+-------------+---------+
该表没有主键，因此会存在重复的行。
该表的每一行所代表的含义是：用户（user_id）在某天（day）听了某首歌曲（song_id）。
</pre>

<p>&nbsp;</p>

<p>表: <code>Friendship</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| user1_id      | int     |
| user2_id      | int     |
+---------------+---------+
(user1_id, user2_id) 是该表的主键。
该表的每一行所代表的含义是，用户（user1_id, user2_id）是朋友。
注意：user1_id &lt; user2_id。
</pre>

<p>&nbsp;</p>

<p>请写一段SQL查询获取到兴趣相同的朋友。用户 <code>x</code>&nbsp;和 用户 <code>y</code>&nbsp;是兴趣相同的朋友，需满足下述条件：</p>

<ul>
	<li>用户&nbsp;<code>x</code>&nbsp;和&nbsp;<code>y</code>&nbsp;是朋友，并且</li>
	<li>用户&nbsp;<code>x</code> and <code>y</code>&nbsp;在同一天内听过相同的歌曲，且数量大于等于三首.</li>
</ul>

<p>结果表&nbsp;<strong>无需排序&nbsp;</strong>。注意：返回的结果需要和源数据表的呈现方式相同&nbsp;（例如，&nbsp;需满足&nbsp;<code>user1_id &lt; user2_id</code>）。</p>

<p>结果表的格式如下例。</p>

<p>&nbsp;</p>

<p><b>示例 1：</b></p>

<pre>
<strong>输入：</strong>
Listens table:
+---------+---------+------------+
| user_id | song_id | day        |
+---------+---------+------------+
| 1       | 10      | 2021-03-15 |
| 1       | 11      | 2021-03-15 |
| 1       | 12      | 2021-03-15 |
| 2       | 10      | 2021-03-15 |
| 2       | 11      | 2021-03-15 |
| 2       | 12      | 2021-03-15 |
| 3       | 10      | 2021-03-15 |
| 3       | 11      | 2021-03-15 |
| 3       | 12      | 2021-03-15 |
| 4       | 10      | 2021-03-15 |
| 4       | 11      | 2021-03-15 |
| 4       | 13      | 2021-03-15 |
| 5       | 10      | 2021-03-16 |
| 5       | 11      | 2021-03-16 |
| 5       | 12      | 2021-03-16 |
+---------+---------+------------+
Friendship table:
+----------+----------+
| user1_id | user2_id |
+----------+----------+
| 1        | 2        |
| 2        | 4        |
| 2        | 5        |
+----------+----------+
<b>输出：</b>
+----------+----------+
| user1_id | user2_id |
+----------+----------+
| 1        | 2        |
+----------+----------+
<strong>解释：</strong>
用户 1 和 2 是朋友, 并且他们在同一天内都听了10、11、12的歌曲。所以，他们是兴趣相同的朋友。
用户 1 和 3 在同一天内都听了10、11、12的歌曲，但他们不是朋友。
用户 2 和 4 是朋友，但他们同一天内听过相同的歌曲的数量小于3。
用户 2 和 5 是朋友，并且在都听了了10、11、12的歌曲，但不在同一天内。</pre>

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
SELECT DISTINCT user1_id, user2_id
FROM
    Friendship AS f
    LEFT JOIN Listens AS l1 ON user1_id = l1.user_id
    LEFT JOIN Listens AS l2 ON user2_id = l2.user_id
WHERE l1.song_id = l2.song_id AND l1.day = l2.day
GROUP BY 1, 2, l1.day
HAVING COUNT(DISTINCT l1.song_id) >= 3;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
