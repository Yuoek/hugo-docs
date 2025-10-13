---
title: "1920_基于排列构建数组"
date: 2025-10-08T18:38:49+08:00
weight: 3
tags: [二分查找, 几何, 动态规划, 博弈, 后缀数组, 哈希函数, 图, 字符串, 广度优先搜索, 排序, 数学, 数组, 枚举, 模拟, 滚动哈希, 矩阵, 贪心, 递归]
---

{{< markmap >}}
### [1920_基于排列构建数组](#1920)
#### [数组](#1920)
#### [模拟](#1920)
### [1921_消灭怪物的最大数量](#1921)
#### [贪心](#1921)
#### [数组](#1921)
#### [排序](#1921)
### [1922_统计好数字的数目](#1922)
#### [递归](#1922)
#### [数学](#1922)
### [1923_最长公共子路径](#1923)
#### [数组](#1923)
#### [二分查找](#1923)
#### [后缀数组](#1923)
#### [哈希函数](#1923)
#### [滚动哈希](#1923)
### [1924_安装栅栏 II 🔒](#1924)
#### [几何](#1924)
#### [数组](#1924)
#### [数学](#1924)
### [1925_统计平方和三元组的数目](#1925)
#### [数学](#1925)
#### [枚举](#1925)
### [1926_迷宫中离入口最近的出口](#1926)
#### [广度优先搜索](#1926)
#### [数组](#1926)
#### [矩阵](#1926)
### [1927_求和游戏](#1927)
#### [贪心](#1927)
#### [数学](#1927)
#### [字符串](#1927)
#### [博弈](#1927)
### [1928_规定时间内到达终点的最小花费](#1928)
#### [图](#1928)
#### [数组](#1928)
#### [动态规划](#1928)
### [1929_数组串联](#1929)
#### [数组](#1929)
#### [模拟](#1929)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1920_基于排列构建数组
___
#### 数组
___
#### 模拟
---
### 1921_消灭怪物的最大数量
___
#### 贪心
___
#### 数组
___
#### 排序
---
### 1922_统计好数字的数目
___
#### 递归
___
#### 数学
---
### 1923_最长公共子路径
___
#### 数组
___
#### 二分查找
___
#### 后缀数组
___
#### 哈希函数
___
#### 滚动哈希
---
### 1924_安装栅栏 II 🔒
___
#### 几何
___
#### 数组
___
#### 数学
---
### 1925_统计平方和三元组的数目
___
#### 数学
___
#### 枚举
---
### 1926_迷宫中离入口最近的出口
___
#### 广度优先搜索
___
#### 数组
___
#### 矩阵
---
### 1927_求和游戏
___
#### 贪心
___
#### 数学
___
#### 字符串
___
#### 博弈
---
### 1928_规定时间内到达终点的最小花费
___
#### 图
___
#### 数组
___
#### 动态规划
---
### 1929_数组串联
___
#### 数组
___
#### 模拟
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 几何 | 动态规划 |
| 博弈 | 后缀数组 | 哈希函数 |
| 图 | 字符串 | 广度优先搜索 |
| 排序 | 数学 | 数组 |
| 枚举 | 模拟 | 滚动哈希 |
| 矩阵 | 贪心 | 递归 |

# [1920. 基于排列构建数组](https://leetcode.cn/problems/build-array-from-permutation){#1920}

{{< tabs "1920" >}}

{{% tab "python" %}}
```python
class Solution:
    def buildArray(self, nums: List[int]) -> List[int]:
        return [nums[num] for num in nums]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] buildArray(int[] nums) {
        int[] ans = new int[nums.length];
        for (int i = 0; i < nums.length; ++i) {
            ans[i] = nums[nums[i]];
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
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ans;
        for (int& num : nums) {
            ans.push_back(nums[num]);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func buildArray(nums []int) []int {
	ans := make([]int, len(nums))
	for i, num := range nums {
		ans[i] = nums[num]
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function buildArray(nums: number[]): number[] {
    return nums.map(x => nums[x]);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn build_array(nums: Vec<i32>) -> Vec<i32> {
        nums.iter().map(|&v| nums[v as usize]).collect()
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var buildArray = function (nums) {
    return nums.map(x => nums[x]);
};
```
{{% /tab %}}
{{% tab "c" %}}
```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* buildArray(int* nums, int numsSize, int* returnSize) {
    int* ans = malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        ans[i] = nums[nums[i]];
    }
    *returnSize = numsSize;
    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个 <strong>从 0 开始的排列</strong> <code>nums</code>（<strong>下标也从 0 开始</strong>）。请你构建一个 <strong>同样长度</strong> 的数组 <code>ans</code> ，其中，对于每个 <code>i</code>（<code>0 &lt;= i &lt; nums.length</code>），都满足 <code>ans[i] = nums[nums[i]]</code> 。返回构建好的数组 <code>ans</code> 。</p>

<p><strong>从 0 开始的排列</strong> <code>nums</code> 是一个由 <code>0</code> 到&nbsp;<code>nums.length - 1</code>（<code>0</code> 和 <code>nums.length - 1</code> 也包含在内）的不同整数组成的数组。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [0,2,1,5,3,4]
<strong>输出：</strong>[0,1,2,4,5,3]<strong>
解释：</strong>数组 ans 构建如下：
ans = [nums[nums[0]], nums[nums[1]], nums[nums[2]], nums[nums[3]], nums[nums[4]], nums[nums[5]]]
    = [nums[0], nums[2], nums[1], nums[5], nums[3], nums[4]]
    = [0,1,2,4,5,3]</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [5,0,1,2,3,4]
<strong>输出：</strong>[4,5,0,1,2,3]
<strong>解释：</strong>数组 ans 构建如下：
ans = [nums[nums[0]], nums[nums[1]], nums[nums[2]], nums[nums[3]], nums[nums[4]], nums[nums[5]]]
    = [nums[5], nums[0], nums[1], nums[2], nums[3], nums[4]]
    = [4,5,0,1,2,3]</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>0 &lt;= nums[i] &lt; nums.length</code></li>
	<li><code>nums</code> 中的元素 <strong>互不相同</strong></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>你能在不使用额外空间的情况下解决此问题吗（即 <code>O(1)</code> 内存）？</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们可以直接模拟题目描述的过程，构建一个新的数组 $\textit{ans}$，对于每个 $i$，令 $\textit{ans}[i] = \textit{nums}[\textit{nums}[i]]$。

时间复杂度 $O(n)$，其中 $n$ 是数组 $\textit{nums}$ 的长度。忽略答案数组的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def buildArray(self, nums: List[int]) -> List[int]:
        return [nums[num] for num in nums]
```

#### Java

```java
class Solution {
    public int[] buildArray(int[] nums) {
        int[] ans = new int[nums.length];
        for (int i = 0; i < nums.length; ++i) {
            ans[i] = nums[nums[i]];
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ans;
        for (int& num : nums) {
            ans.push_back(nums[num]);
        }
        return ans;
    }
};
```

#### Go

```go
func buildArray(nums []int) []int {
	ans := make([]int, len(nums))
	for i, num := range nums {
		ans[i] = nums[num]
	}
	return ans
}
```

#### TypeScript

```ts
function buildArray(nums: number[]): number[] {
    return nums.map(x => nums[x]);
}
```

#### Rust

```rust
impl Solution {
    pub fn build_array(nums: Vec<i32>) -> Vec<i32> {
        nums.iter().map(|&v| nums[v as usize]).collect()
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var buildArray = function (nums) {
    return nums.map(x => nums[x]);
};
```

#### C

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* buildArray(int* nums, int numsSize, int* returnSize) {
    int* ans = malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        ans[i] = nums[nums[i]];
    }
    *returnSize = numsSize;
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1921. 消灭怪物的最大数量](https://leetcode.cn/problems/eliminate-maximum-number-of-monsters){#1921}

{{< tabs "1921" >}}

{{% tab "python" %}}
```python
class Solution:
    def eliminateMaximum(self, dist: List[int], speed: List[int]) -> int:
        times = sorted((d - 1) // s for d, s in zip(dist, speed))
        for i, t in enumerate(times):
            if t < i:
                return i
        return len(times)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int eliminateMaximum(int[] dist, int[] speed) {
        int n = dist.length;
        int[] times = new int[n];
        for (int i = 0; i < n; ++i) {
            times[i] = (dist[i] - 1) / speed[i];
        }
        Arrays.sort(times);
        for (int i = 0; i < n; ++i) {
            if (times[i] < i) {
                return i;
            }
        }
        return n;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<int> times;
        for (int i = 0; i < n; ++i) {
            times.push_back((dist[i] - 1) / speed[i]);
        }
        sort(times.begin(), times.end());
        for (int i = 0; i < n; ++i) {
            if (times[i] < i) {
                return i;
            }
        }
        return n;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func eliminateMaximum(dist []int, speed []int) int {
	n := len(dist)
	times := make([]int, n)
	for i, d := range dist {
		times[i] = (d - 1) / speed[i]
	}
	sort.Ints(times)
	for i, t := range times {
		if t < i {
			return i
		}
	}
	return n
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function eliminateMaximum(dist: number[], speed: number[]): number {
    const n = dist.length;
    const times: number[] = Array(n).fill(0);
    for (let i = 0; i < n; ++i) {
        times[i] = Math.floor((dist[i] - 1) / speed[i]);
    }
    times.sort((a, b) => a - b);
    for (let i = 0; i < n; ++i) {
        if (times[i] < i) {
            return i;
        }
    }
    return n;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} dist
 * @param {number[]} speed
 * @return {number}
 */
var eliminateMaximum = function (dist, speed) {
    const n = dist.length;
    const times = Array(n).fill(0);
    for (let i = 0; i < n; ++i) {
        times[i] = Math.floor((dist[i] - 1) / speed[i]);
    }
    times.sort((a, b) => a - b);
    for (let i = 0; i < n; ++i) {
        if (times[i] < i) {
            return i;
        }
    }
    return n;
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int EliminateMaximum(int[] dist, int[] speed) {
        int n = dist.Length;
        int[] times = new int[n];
        for (int i = 0; i < n; ++i) {
            times[i] = (dist[i] - 1) / speed[i];
        }
        Array.Sort(times);
        for (int i = 0; i < n; ++i) {
            if (times[i] < i) {
                return i;
            }
        }
        return n;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你正在玩一款电子游戏，在游戏中你需要保护城市免受怪物侵袭。给定一个 <strong>下标从 0 开始</strong> 且大小为 <code>n</code> 的整数数组 <code>dist</code> ，其中 <code>dist[i]</code> 是第 <code>i</code> 个怪物与城市的 <strong>初始距离</strong>（单位：千米）。</p>

<p>怪物以 <strong>恒定</strong> 的速度走向城市。每个怪物的速度都以一个长度为 <code>n</code> 的整数数组 <code>speed</code> 表示，其中 <code>speed[i]</code> 是第 <code>i</code> 个怪物的速度（单位：千米/分）。</p>

<p>你有一种武器，一旦充满电，就可以消灭 <strong>一个</strong> 怪物。但是，武器需要 <strong>一分钟</strong> 才能充电。武器在游戏开始时是充满电的状态，怪物从 <strong>第 0 分钟</strong> 时开始移动。</p>

<p>一旦任一怪物到达城市，你就输掉了这场游戏。如果某个怪物 <strong>恰好</strong>&nbsp;在某一分钟开始时到达城市（距离表示为0），这也会被视为<strong> 输掉</strong>&nbsp;游戏，在你可以使用武器之前，游戏就会结束。</p>

<p>返回在你输掉游戏前可以消灭的怪物的 <strong>最大</strong> 数量。如果你可以在所有怪物到达城市前将它们全部消灭，返回&nbsp; <code>n</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>dist = [1,3,4], speed = [1,1,1]
<strong>输出：</strong>3
<strong>解释：</strong>
第 0 分钟开始时，怪物的距离是 [1,3,4]，你消灭了第一个怪物。
第 1 分钟开始时，怪物的距离是 [X,2,3]，你消灭了第二个怪物。
第 3 分钟开始时，怪物的距离是 [X,X,2]，你消灭了第三个怪物。
所有 3 个怪物都可以被消灭。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>dist = [1,1,2,3], speed = [1,1,1,1]
<strong>输出：</strong>1
<strong>解释：</strong>
第 0 分钟开始时，怪物的距离是 [1,1,2,3]，你消灭了第一个怪物。
第 1 分钟开始时，怪物的距离是 [X,0,1,2]，所以你输掉了游戏。
你只能消灭 1 个怪物。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>dist = [3,2,4], speed = [5,3,2]
<strong>输出：</strong>1
<strong>解释：</strong>
第 0 分钟开始时，怪物的距离是 [3,2,4]，你消灭了第一个怪物。
第 1 分钟开始时，怪物的距离是 [X,0,2]，你输掉了游戏。 
你只能消灭 1 个怪物。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == dist.length == speed.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= dist[i], speed[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 贪心

我们用 $\textit{times}$ 数组记录每个怪物最晚可被消灭的时间。对于第 $i$ 个怪物，最晚可被消灭的时间满足：

$$\textit{times}[i] = \left\lfloor \frac{\textit{dist}[i]-1}{\textit{speed}[i]} \right\rfloor$$

接下来，我们对 $\textit{times}$ 数组升序排列。

然后遍历 $\textit{times}$ 数组，对于第 $i$ 个怪物，如果 $\textit{times}[i] \geq i$，说明第 $i$ 个怪物可以被消灭，否则说明第 $i$ 个怪物无法被消灭，直接返回 $i$ 即可。

若所有怪物都可以被消灭，则返回 $n$。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 是数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def eliminateMaximum(self, dist: List[int], speed: List[int]) -> int:
        times = sorted((d - 1) // s for d, s in zip(dist, speed))
        for i, t in enumerate(times):
            if t < i:
                return i
        return len(times)
```

#### Java

```java
class Solution {
    public int eliminateMaximum(int[] dist, int[] speed) {
        int n = dist.length;
        int[] times = new int[n];
        for (int i = 0; i < n; ++i) {
            times[i] = (dist[i] - 1) / speed[i];
        }
        Arrays.sort(times);
        for (int i = 0; i < n; ++i) {
            if (times[i] < i) {
                return i;
            }
        }
        return n;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<int> times;
        for (int i = 0; i < n; ++i) {
            times.push_back((dist[i] - 1) / speed[i]);
        }
        sort(times.begin(), times.end());
        for (int i = 0; i < n; ++i) {
            if (times[i] < i) {
                return i;
            }
        }
        return n;
    }
};
```

#### Go

```go
func eliminateMaximum(dist []int, speed []int) int {
	n := len(dist)
	times := make([]int, n)
	for i, d := range dist {
		times[i] = (d - 1) / speed[i]
	}
	sort.Ints(times)
	for i, t := range times {
		if t < i {
			return i
		}
	}
	return n
}
```

#### TypeScript

```ts
function eliminateMaximum(dist: number[], speed: number[]): number {
    const n = dist.length;
    const times: number[] = Array(n).fill(0);
    for (let i = 0; i < n; ++i) {
        times[i] = Math.floor((dist[i] - 1) / speed[i]);
    }
    times.sort((a, b) => a - b);
    for (let i = 0; i < n; ++i) {
        if (times[i] < i) {
            return i;
        }
    }
    return n;
}
```

#### JavaScript

```js
/**
 * @param {number[]} dist
 * @param {number[]} speed
 * @return {number}
 */
var eliminateMaximum = function (dist, speed) {
    const n = dist.length;
    const times = Array(n).fill(0);
    for (let i = 0; i < n; ++i) {
        times[i] = Math.floor((dist[i] - 1) / speed[i]);
    }
    times.sort((a, b) => a - b);
    for (let i = 0; i < n; ++i) {
        if (times[i] < i) {
            return i;
        }
    }
    return n;
};
```

#### C#

```cs
public class Solution {
    public int EliminateMaximum(int[] dist, int[] speed) {
        int n = dist.Length;
        int[] times = new int[n];
        for (int i = 0; i < n; ++i) {
            times[i] = (dist[i] - 1) / speed[i];
        }
        Array.Sort(times);
        for (int i = 0; i < n; ++i) {
            if (times[i] < i) {
                return i;
            }
        }
        return n;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1922. 统计好数字的数目](https://leetcode.cn/problems/count-good-numbers){#1922}

{{< tabs "1922" >}}

{{% tab "python" %}}
```python
class Solution:
    def countGoodNumbers(self, n: int) -> int:
        mod = 10**9 + 7
        return pow(5, (n + 1) >> 1, mod) * pow(4, n >> 1, mod) % mod
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private final int mod = (int) 1e9 + 7;

    public int countGoodNumbers(long n) {
        return (int) (qpow(5, (n + 1) >> 1) * qpow(4, n >> 1) % mod);
    }

    private long qpow(long x, long n) {
        long res = 1;
        while (n != 0) {
            if ((n & 1) == 1) {
                res = res * x % mod;
            }
            x = x * x % mod;
            n >>= 1;
        }
        return res;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int countGoodNumbers(long long n) {
        const int mod = 1e9 + 7;
        auto qpow = [](long long x, long long n) -> long long {
            long long res = 1;
            while (n) {
                if ((n & 1) == 1) {
                    res = res * x % mod;
                }
                x = x * x % mod;
                n >>= 1;
            }
            return res;
        };
        return qpow(5, (n + 1) >> 1) * qpow(4, n >> 1) % mod;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
const mod int64 = 1e9 + 7

func countGoodNumbers(n int64) int {
	return int(myPow(5, (n+1)>>1) * myPow(4, n>>1) % mod)
}

func myPow(x, n int64) int64 {
	var res int64 = 1
	for n != 0 {
		if (n & 1) == 1 {
			res = res * x % mod
		}
		x = x * x % mod
		n >>= 1
	}
	return res
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countGoodNumbers(n: number): number {
    const mod = 1000000007n;
    const qpow = (x: bigint, n: bigint): bigint => {
        let res = 1n;
        while (n > 0n) {
            if (n & 1n) {
                res = (res * x) % mod;
            }
            x = (x * x) % mod;
            n >>= 1n;
        }
        return res;
    };
    const a = qpow(5n, BigInt(n + 1) / 2n);
    const b = qpow(4n, BigInt(n) / 2n);
    return Number((a * b) % mod);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>我们称一个数字字符串是 <strong>好数字</strong> 当它满足（下标从 <strong>0</strong> 开始）<strong>偶数</strong> 下标处的数字为 <strong>偶数</strong> 且 <strong>奇数</strong> 下标处的数字为 <strong>质数</strong> （<code>2</code>，<code>3</code>，<code>5</code> 或 <code>7</code>）。</p>

<ul>
	<li>比方说，<code>"2582"</code> 是好数字，因为偶数下标处的数字（<code>2</code> 和 <code>8</code>）是偶数且奇数下标处的数字（<code>5</code> 和 <code>2</code>）为质数。但 <code>"3245"</code> <strong>不是</strong> 好数字，因为 <code>3</code> 在偶数下标处但不是偶数。</li>
</ul>

<p>给你一个整数 <code>n</code> ，请你返回长度为 <code>n</code> 且为好数字的数字字符串 <strong>总数</strong> 。由于答案可能会很大，请你将它对<strong> </strong><code>10<sup>9</sup> + 7</code> <strong>取余后返回</strong> 。</p>

<p>一个 <strong>数字字符串</strong> 是每一位都由 <code>0</code> 到 <code>9</code> 组成的字符串，且可能包含前导 0 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>n = 1
<b>输出：</b>5
<b>解释：</b>长度为 1 的好数字包括 "0"，"2"，"4"，"6"，"8" 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>n = 4
<b>输出：</b>400
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>n = 50
<b>输出：</b>564908303
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= n <= 10<sup>15</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：快速幂

长度为 $n$ 的好数字，偶数下标一共有 $\lceil \frac{n}{2} \rceil = \lfloor \frac{n + 1}{2} \rfloor$ 位，偶数下标可以填入 $5$ 种数字（$0, 2, 4, 6, 8$）；奇数下标一共有 $\lfloor \frac{n}{2} \rfloor$ 位，奇数下标可以填入 $4$ 种数字（$2, 3, 5, 7$）。因此长度为 $n$ 的好数字的个数为：

$$
ans = 5^{\lceil \frac{n}{2} \rceil} \times 4^{\lfloor \frac{n}{2} \rfloor}
$$

我们可以使用快速幂来计算 $5^{\lceil \frac{n}{2} \rceil}$ 和 $4^{\lfloor \frac{n}{2} \rfloor}$，时间复杂度为 $O(\log n)$，空间复杂度为 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countGoodNumbers(self, n: int) -> int:
        mod = 10**9 + 7
        return pow(5, (n + 1) >> 1, mod) * pow(4, n >> 1, mod) % mod
```

#### Java

```java
class Solution {
    private final int mod = (int) 1e9 + 7;

    public int countGoodNumbers(long n) {
        return (int) (qpow(5, (n + 1) >> 1) * qpow(4, n >> 1) % mod);
    }

    private long qpow(long x, long n) {
        long res = 1;
        while (n != 0) {
            if ((n & 1) == 1) {
                res = res * x % mod;
            }
            x = x * x % mod;
            n >>= 1;
        }
        return res;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int countGoodNumbers(long long n) {
        const int mod = 1e9 + 7;
        auto qpow = [](long long x, long long n) -> long long {
            long long res = 1;
            while (n) {
                if ((n & 1) == 1) {
                    res = res * x % mod;
                }
                x = x * x % mod;
                n >>= 1;
            }
            return res;
        };
        return qpow(5, (n + 1) >> 1) * qpow(4, n >> 1) % mod;
    }
};
```

#### Go

```go
const mod int64 = 1e9 + 7

func countGoodNumbers(n int64) int {
	return int(myPow(5, (n+1)>>1) * myPow(4, n>>1) % mod)
}

func myPow(x, n int64) int64 {
	var res int64 = 1
	for n != 0 {
		if (n & 1) == 1 {
			res = res * x % mod
		}
		x = x * x % mod
		n >>= 1
	}
	return res
}
```

#### TypeScript

```ts
function countGoodNumbers(n: number): number {
    const mod = 1000000007n;
    const qpow = (x: bigint, n: bigint): bigint => {
        let res = 1n;
        while (n > 0n) {
            if (n & 1n) {
                res = (res * x) % mod;
            }
            x = (x * x) % mod;
            n >>= 1n;
        }
        return res;
    };
    const a = qpow(5n, BigInt(n + 1) / 2n);
    const b = qpow(4n, BigInt(n) / 2n);
    return Number((a * b) % mod);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1923. 最长公共子路径](https://leetcode.cn/problems/longest-common-subpath){#1923}

{{< tabs "1923" >}}

{{% tab "python" %}}
```python
class Solution:
    def longestCommonSubpath(self, n: int, paths: List[List[int]]) -> int:
        def check(k: int) -> bool:
            cnt = Counter()
            for h in hh:
                vis = set()
                for i in range(1, len(h) - k + 1):
                    j = i + k - 1
                    x = (h[j] - h[i - 1] * p[j - i + 1]) % mod
                    if x not in vis:
                        vis.add(x)
                        cnt[x] += 1
            return max(cnt.values()) == m

        m = len(paths)
        mx = max(len(path) for path in paths)
        base = 133331
        mod = 2**64 + 1
        p = [0] * (mx + 1)
        p[0] = 1
        for i in range(1, len(p)):
            p[i] = p[i - 1] * base % mod
        hh = []
        for path in paths:
            k = len(path)
            h = [0] * (k + 1)
            for i, x in enumerate(path, 1):
                h[i] = h[i - 1] * base % mod + x
            hh.append(h)
        l, r = 0, min(len(path) for path in paths)
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
    int N = 100010;
    long[] h = new long[N];
    long[] p = new long[N];
    private int[][] paths;
    Map<Long, Integer> cnt = new HashMap<>();
    Map<Long, Integer> inner = new HashMap<>();

    public int longestCommonSubpath(int n, int[][] paths) {
        int left = 0, right = N;
        for (int[] path : paths) {
            right = Math.min(right, path.length);
        }
        this.paths = paths;
        while (left < right) {
            int mid = (left + right + 1) >> 1;
            if (check(mid)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }

    private boolean check(int mid) {
        cnt.clear();
        inner.clear();
        p[0] = 1;
        for (int j = 0; j < paths.length; ++j) {
            int n = paths[j].length;
            for (int i = 1; i <= n; ++i) {
                p[i] = p[i - 1] * 133331;
                h[i] = h[i - 1] * 133331 + paths[j][i - 1];
            }
            for (int i = mid; i <= n; ++i) {
                long val = get(i - mid + 1, i);
                if (!inner.containsKey(val) || inner.get(val) != j) {
                    inner.put(val, j);
                    cnt.put(val, cnt.getOrDefault(val, 0) + 1);
                }
            }
        }
        int max = 0;
        for (int val : cnt.values()) {
            max = Math.max(max, val);
        }
        return max == paths.length;
    }

    private long get(int l, int r) {
        return h[r] - h[l - 1] * p[r - l + 1];
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>一个国家由 <code>n</code> 个编号为 <code>0</code> 到 <code>n - 1</code> 的城市组成。在这个国家里，<strong>每两个</strong> 城市之间都有一条道路连接。</p>

<p>总共有 <code>m</code> 个编号为 <code>0</code> 到 <code>m - 1</code> 的朋友想在这个国家旅游。他们每一个人的路径都会包含一些城市。每条路径都由一个整数数组表示，每个整数数组表示一个朋友按顺序访问过的城市序列。同一个城市在一条路径中可能 <strong>重复</strong> 出现，但同一个城市在一条路径中不会连续出现。</p>

<p>给你一个整数 <code>n</code> 和二维数组 <code>paths</code> ，其中 <code>paths[i]</code> 是一个整数数组，表示第 <code>i</code> 个朋友走过的路径，请你返回 <strong>每一个</strong> 朋友都走过的 <strong>最长公共子路径</strong> 的长度，如果不存在公共子路径，请你返回 <code>0</code> 。</p>

<p>一个 <strong>子路径</strong> 指的是一条路径中连续的城市序列。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>n = 5, paths = [[0,1,<strong>2,3</strong>,4],
                     [<strong>2,3</strong>,4],
                     [4,0,1,<strong>2,3</strong>]]
<b>输出：</b>2
<b>解释：</b>最长公共子路径为 [2,3] 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>n = 3, paths = [[0],[1],[2]]
<b>输出：</b>0
<b>解释：</b>三条路径没有公共子路径。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>n = 5, paths = [[<strong>0</strong>,1,2,3,4],
                     [4,3,2,1,<strong>0</strong>]]
<b>输出：</b>1
<b>解释：</b>最长公共子路径为 [0]，[1]，[2]，[3] 和 [4] 。它们长度都为 1 。</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= n <= 10<sup>5</sup></code></li>
	<li><code>m == paths.length</code></li>
	<li><code>2 <= m <= 10<sup>5</sup></code></li>
	<li><code>sum(paths[i].length) <= 10<sup>5</sup></code></li>
	<li><code>0 <= paths[i][j] < n</code></li>
	<li><code>paths[i]</code> 中同一个城市不会连续重复出现。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：字符串哈希

**字符串哈希**是把一个任意长度的字符串映射成一个非负整数，并且其冲突的概率几乎为 0。字符串哈希用于计算字符串哈希值，快速判断两个字符串是否相等。

取一固定值 BASE，把字符串看作是 BASE 进制数，并分配一个大于 0 的数值，代表每种字符。一般来说，我们分配的数值都远小于 BASE。例如，对于小写字母构成的字符串，可以令 a=1, b=2, ..., z=26。取一固定值 MOD，求出该 BASE 进制对 M 的余数，作为该字符串的 hash 值。

一般来说，取 BASE=131 或者 BASE=13331，此时 hash 值产生的冲突概率极低。只要两个字符串 hash 值相同，我们就认为两个字符串是相等的。通常 MOD 取 2^64，C++ 里，可以直接使用 unsigned long long 类型存储这个 hash 值，在计算时不处理算术溢出问题，产生溢出时相当于自动对 2^64 取模，这样可以避免低效取模运算。

除了在极特殊构造的数据上，上述 hash 算法很难产生冲突，一般情况下上述 hash 算法完全可以出现在题目的标准答案中。我们还可以多取一些恰当的 BASE 和 MOD 的值（例如大质数），多进行几组 hash 运算，当结果都相同时才认为原字符串相等，就更加难以构造出使这个 hash 产生错误的数据。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def longestCommonSubpath(self, n: int, paths: List[List[int]]) -> int:
        def check(k: int) -> bool:
            cnt = Counter()
            for h in hh:
                vis = set()
                for i in range(1, len(h) - k + 1):
                    j = i + k - 1
                    x = (h[j] - h[i - 1] * p[j - i + 1]) % mod
                    if x not in vis:
                        vis.add(x)
                        cnt[x] += 1
            return max(cnt.values()) == m

        m = len(paths)
        mx = max(len(path) for path in paths)
        base = 133331
        mod = 2**64 + 1
        p = [0] * (mx + 1)
        p[0] = 1
        for i in range(1, len(p)):
            p[i] = p[i - 1] * base % mod
        hh = []
        for path in paths:
            k = len(path)
            h = [0] * (k + 1)
            for i, x in enumerate(path, 1):
                h[i] = h[i - 1] * base % mod + x
            hh.append(h)
        l, r = 0, min(len(path) for path in paths)
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
    int N = 100010;
    long[] h = new long[N];
    long[] p = new long[N];
    private int[][] paths;
    Map<Long, Integer> cnt = new HashMap<>();
    Map<Long, Integer> inner = new HashMap<>();

    public int longestCommonSubpath(int n, int[][] paths) {
        int left = 0, right = N;
        for (int[] path : paths) {
            right = Math.min(right, path.length);
        }
        this.paths = paths;
        while (left < right) {
            int mid = (left + right + 1) >> 1;
            if (check(mid)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }

    private boolean check(int mid) {
        cnt.clear();
        inner.clear();
        p[0] = 1;
        for (int j = 0; j < paths.length; ++j) {
            int n = paths[j].length;
            for (int i = 1; i <= n; ++i) {
                p[i] = p[i - 1] * 133331;
                h[i] = h[i - 1] * 133331 + paths[j][i - 1];
            }
            for (int i = mid; i <= n; ++i) {
                long val = get(i - mid + 1, i);
                if (!inner.containsKey(val) || inner.get(val) != j) {
                    inner.put(val, j);
                    cnt.put(val, cnt.getOrDefault(val, 0) + 1);
                }
            }
        }
        int max = 0;
        for (int val : cnt.values()) {
            max = Math.max(max, val);
        }
        return max == paths.length;
    }

    private long get(int l, int r) {
        return h[r] - h[l - 1] * p[r - l + 1];
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1924. 安装栅栏 II 🔒](https://leetcode.cn/problems/erect-the-fence-ii){#1924}

{{< tabs "1924" >}}

{{% tab "python" %}}
```python

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

<p>给你一个二维整数数组&nbsp;<code>trees</code>，其中 <code>trees[i] = [x<sub>i</sub>, y<sub>i</sub>]</code> 表示花园中第 <code>i</code> 棵树的坐标。</p>

<p>你需要用最少的原材料给花园安装一个 <strong>圆形</strong> 的栅栏，使花园中所有的树都在被 <strong>围在栅栏内部</strong>（在栅栏边界上的树也算在内）。</p>

<p>正式地说，你需要求出栅栏的圆心坐标 <code>(x,y)</code> 和半径 <code>r</code>，使花园中所有的树都在圆的内部或边界上，并且让半径 <code>r</code> <strong>最小</strong>。</p>

<p>请用一个长度为 3 的数组 <code>[x,y,r]</code> 来返回圆心坐标和半径。如果答案与正确答案的误差不超过&nbsp;<code>10<sup>-5</sup></code>，则该答案将被视为正确答案通过。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1900-1999/1924.Erect%20the%20Fence%20II/images/trees1.png" style="width: 510px; height: 501px;"></strong></p>

<pre><strong>输入:</strong> trees = [[1,1],[2,2],[2,0],[2,4],[3,3],[4,2]]
<strong>输出:</strong> [2.00000,2.00000,2.00000]
<strong>解释:</strong> 栅栏的圆心应当在 (2, 2) 处，半径为 2。
</pre>

<p><strong>示例 2:</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1900-1999/1924.Erect%20the%20Fence%20II/images/trees2.png" style="width: 510px; height: 501px;"></strong></p>

<pre><strong>输入:</strong> trees = [[1,2],[2,2],[4,2]]
<strong>输出:</strong> [2.50000,2.00000,1.50000]
<strong>解释:</strong> 栅栏的圆心应当在 (2.5, 2) 处，半径为 1.5。
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= trees.length &lt;= 3000</code></li>
	<li><code>trees[i].length == 2</code></li>
	<li><code>0 &lt;= x<sub>i</sub>, y<sub>i</sub> &lt;= 3000</code></li>
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

# [1925. 统计平方和三元组的数目](https://leetcode.cn/problems/count-square-sum-triples){#1925}

{{< tabs "1925" >}}

{{% tab "python" %}}
```python
class Solution:
    def countTriples(self, n: int) -> int:
        ans = 0
        for a in range(1, n):
            for b in range(1, n):
                x = a * a + b * b
                c = int(sqrt(x))
                if c <= n and c * c == x:
                    ans += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countTriples(int n) {
        int ans = 0;
        for (int a = 1; a < n; a++) {
            for (int b = 1; b < n; b++) {
                int x = a * a + b * b;
                int c = (int) Math.sqrt(x);
                if (c <= n && c * c == x) {
                    ans++;
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
    int countTriples(int n) {
        int ans = 0;
        for (int a = 1; a < n; ++a) {
            for (int b = 1; b < n; ++b) {
                int x = a * a + b * b;
                int c = static_cast<int>(sqrt(x));
                if (c <= n && c * c == x) {
                    ++ans;
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
func countTriples(n int) (ans int) {
	for a := 1; a < n; a++ {
		for b := 1; b < n; b++ {
			x := a*a + b*b
			c := int(math.Sqrt(float64(x)))
			if c <= n && c*c == x {
				ans++
			}
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countTriples(n: number): number {
    let ans = 0;
    for (let a = 1; a < n; a++) {
        for (let b = 1; b < n; b++) {
            const x = a * a + b * b;
            const c = Math.floor(Math.sqrt(x));
            if (c <= n && c * c === x) {
                ans++;
            }
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

<p>一个 <strong>平方和三元组</strong> <code>(a,b,c)</code> 指的是满足 <code>a<sup>2</sup> + b<sup>2</sup> = c<sup>2</sup></code> 的 <strong>整数 </strong>三元组 <code>a</code>，<code>b</code> 和 <code>c</code> 。</p>

<p>给你一个整数 <code>n</code> ，请你返回满足<em> </em><code>1 &lt;= a, b, c &lt;= n</code> 的 <strong>平方和三元组</strong> 的数目。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>n = 5
<b>输出：</b>2
<b>解释：</b>平方和三元组为 (3,4,5) 和 (4,3,5) 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>n = 10
<b>输出：</b>4
<b>解释：</b>平方和三元组为 (3,4,5)，(4,3,5)，(6,8,10) 和 (8,6,10) 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 250</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举

我们在 $[1, n)$ 的范围内枚举 $a$ 和 $b$，然后计算 $c = \sqrt{a^2 + b^2}$，如果 $c$ 是整数且 $c \leq n$，那么就找到了一个平方和三元组，答案加一。

枚举结束后，返回答案即可。

时间复杂度 $O(n^2)$，其中 $n$ 是给定的整数。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countTriples(self, n: int) -> int:
        ans = 0
        for a in range(1, n):
            for b in range(1, n):
                x = a * a + b * b
                c = int(sqrt(x))
                if c <= n and c * c == x:
                    ans += 1
        return ans
```

#### Java

```java
class Solution {
    public int countTriples(int n) {
        int ans = 0;
        for (int a = 1; a < n; a++) {
            for (int b = 1; b < n; b++) {
                int x = a * a + b * b;
                int c = (int) Math.sqrt(x);
                if (c <= n && c * c == x) {
                    ans++;
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
    int countTriples(int n) {
        int ans = 0;
        for (int a = 1; a < n; ++a) {
            for (int b = 1; b < n; ++b) {
                int x = a * a + b * b;
                int c = static_cast<int>(sqrt(x));
                if (c <= n && c * c == x) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func countTriples(n int) (ans int) {
	for a := 1; a < n; a++ {
		for b := 1; b < n; b++ {
			x := a*a + b*b
			c := int(math.Sqrt(float64(x)))
			if c <= n && c*c == x {
				ans++
			}
		}
	}
	return
}
```

#### TypeScript

```ts
function countTriples(n: number): number {
    let ans = 0;
    for (let a = 1; a < n; a++) {
        for (let b = 1; b < n; b++) {
            const x = a * a + b * b;
            const c = Math.floor(Math.sqrt(x));
            if (c <= n && c * c === x) {
                ans++;
            }
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

# [1926. 迷宫中离入口最近的出口](https://leetcode.cn/problems/nearest-exit-from-entrance-in-maze){#1926}

{{< tabs "1926" >}}

{{% tab "python" %}}
```python
class Solution:
    def nearestExit(self, maze: List[List[str]], entrance: List[int]) -> int:
        m, n = len(maze), len(maze[0])
        i, j = entrance
        q = deque([(i, j)])
        maze[i][j] = "+"
        ans = 0
        while q:
            ans += 1
            for _ in range(len(q)):
                i, j = q.popleft()
                for a, b in [[0, -1], [0, 1], [-1, 0], [1, 0]]:
                    x, y = i + a, j + b
                    if 0 <= x < m and 0 <= y < n and maze[x][y] == ".":
                        if x == 0 or x == m - 1 or y == 0 or y == n - 1:
                            return ans
                        q.append((x, y))
                        maze[x][y] = "+"
        return -1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int nearestExit(char[][] maze, int[] entrance) {
        int m = maze.length, n = maze[0].length;
        final int[] dirs = {-1, 0, 1, 0, -1};
        Deque<int[]> q = new ArrayDeque<>();
        q.offer(entrance);
        maze[entrance[0]][entrance[1]] = '+';
        for (int ans = 1; !q.isEmpty(); ++ans) {
            for (int k = q.size(); k > 0; --k) {
                var p = q.poll();
                for (int d = 0; d < 4; ++d) {
                    int x = p[0] + dirs[d], y = p[1] + dirs[d + 1];
                    if (x >= 0 && x < m && y >= 0 && y < n && maze[x][y] == '.') {
                        if (x == 0 || x == m - 1 || y == 0 || y == n - 1) {
                            return ans;
                        }
                        maze[x][y] = '+';
                        q.offer(new int[] {x, y});
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
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size();
        int dirs[5] = {-1, 0, 1, 0, -1};
        queue<pair<int, int>> q;
        q.emplace(entrance[0], entrance[1]);
        maze[entrance[0]][entrance[1]] = '+';
        for (int ans = 1; !q.empty(); ++ans) {
            for (int k = q.size(); k; --k) {
                auto [i, j] = q.front();
                q.pop();
                for (int d = 0; d < 4; ++d) {
                    int x = i + dirs[d], y = j + dirs[d + 1];
                    if (x >= 0 && x < m && y >= 0 && y < n && maze[x][y] == '.') {
                        if (x == 0 || x == m - 1 || y == 0 || y == n - 1) {
                            return ans;
                        }
                        maze[x][y] = '+';
                        q.emplace(x, y);
                    }
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
func nearestExit(maze [][]byte, entrance []int) int {
	m, n := len(maze), len(maze[0])
	q := [][2]int{{entrance[0], entrance[1]}}
	maze[entrance[0]][entrance[1]] = '+'
	dirs := []int{-1, 0, 1, 0, -1}
	for ans := 1; len(q) > 0; ans++ {
		for k := len(q); k > 0; k-- {
			p := q[0]
			q = q[1:]
			for l := 0; l < 4; l++ {
				x, y := p[0]+dirs[l], p[1]+dirs[l+1]
				if x >= 0 && x < m && y >= 0 && y < n && maze[x][y] == '.' {
					if x == 0 || x == m-1 || y == 0 || y == n-1 {
						return ans
					}
					q = append(q, [2]int{x, y})
					maze[x][y] = '+'
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
function nearestExit(maze: string[][], entrance: number[]): number {
    const dir = [0, 1, 0, -1, 0];
    const q = [[...entrance, 0]];
    maze[entrance[0]][entrance[1]] = '+';
    for (const [i, j, ans] of q) {
        for (let d = 0; d < 4; d++) {
            const [x, y] = [i + dir[d], j + dir[d + 1]];
            const v = maze[x]?.[y];
            if (!v && ans) {
                return ans;
            }
            if (v === '.') {
                q.push([x, y, ans + 1]);
                maze[x][y] = '+';
            }
        }
    }
    return -1;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个 <code>m x n</code> 的迷宫矩阵 <code>maze</code> （<strong>下标从 0 开始</strong>），矩阵中有空格子（用 <code>'.'</code> 表示）和墙（用 <code>'+'</code> 表示）。同时给你迷宫的入口 <code>entrance</code> ，用 <code>entrance = [entrance<sub>row</sub>, entrance<sub>col</sub>]</code> 表示你一开始所在格子的行和列。</p>

<p>每一步操作，你可以往 <strong>上</strong>，<strong>下</strong>，<strong>左</strong> 或者 <strong>右</strong> 移动一个格子。你不能进入墙所在的格子，你也不能离开迷宫。你的目标是找到离 <code>entrance</code> <strong>最近</strong> 的出口。<strong>出口</strong> 的含义是 <code>maze</code> <strong>边界</strong> 上的 <strong>空格子</strong>。<code>entrance</code> 格子 <strong>不算</strong> 出口。</p>

<p>请你返回从 <code>entrance</code> 到最近出口的最短路径的 <strong>步数</strong> ，如果不存在这样的路径，请你返回 <code>-1</code> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1900-1999/1926.Nearest%20Exit%20from%20Entrance%20in%20Maze/images/nearest1-grid.jpg" style="width: 333px; height: 253px;">
<pre><b>输入：</b>maze = [["+","+",".","+"],[".",".",".","+"],["+","+","+","."]], entrance = [1,2]
<b>输出：</b>1
<b>解释：</b>总共有 3 个出口，分别位于 (1,0)，(0,2) 和 (2,3) 。
一开始，你在入口格子 (1,2) 处。
- 你可以往左移动 2 步到达 (1,0) 。
- 你可以往上移动 1 步到达 (0,2) 。
从入口处没法到达 (2,3) 。
所以，最近的出口是 (0,2) ，距离为 1 步。
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1900-1999/1926.Nearest%20Exit%20from%20Entrance%20in%20Maze/images/nearesr2-grid.jpg" style="width: 253px; height: 253px;">
<pre><b>输入：</b>maze = [["+","+","+"],[".",".","."],["+","+","+"]], entrance = [1,0]
<b>输出：</b>2
<b>解释：</b>迷宫中只有 1 个出口，在 (1,2) 处。
(1,0) 不算出口，因为它是入口格子。
初始时，你在入口与格子 (1,0) 处。
- 你可以往右移动 2 步到达 (1,2) 处。
所以，最近的出口为 (1,2) ，距离为 2 步。
</pre>

<p><strong>示例 3：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1900-1999/1926.Nearest%20Exit%20from%20Entrance%20in%20Maze/images/nearest3-grid.jpg" style="width: 173px; height: 93px;">
<pre><b>输入：</b>maze = [[".","+"]], entrance = [0,0]
<b>输出：</b>-1
<b>解释：</b>这个迷宫中没有出口。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>maze.length == m</code></li>
	<li><code>maze[i].length == n</code></li>
	<li><code>1 &lt;= m, n &lt;= 100</code></li>
	<li><code>maze[i][j]</code> 要么是 <code>'.'</code> ，要么是 <code>'+'</code> 。</li>
	<li><code>entrance.length == 2</code></li>
	<li><code>0 &lt;= entrance<sub>row</sub> &lt; m</code></li>
	<li><code>0 &lt;= entrance<sub>col</sub> &lt; n</code></li>
	<li><code>entrance</code> 一定是空格子。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：BFS

我们可以从入口开始，进行广度优先搜索，每次搜索到一个新的空格子，就将其标记为已访问，并将其加入队列，直到找到一个边界上的空格子，返回步数。

具体地，我们定义一个队列 $q$，初始时我们将 $\textit{entrance}$ 加入队列。定义一个变量 $\textit{ans}$ 记录步数，初始为 $1$。然后我们开始进行广度优先搜索，每一轮我们取出队列中的所有元素，遍历这些元素，对于每个元素，我们尝试向四个方向移动，如果移动后的位置是一个空格子，我们将其加入队列，并将其标记为已访问。如果移动后的位置是边界上的空格子，我们返回 $\textit{ans}$。如果队列为空，我们返回 $-1$。这一轮搜索结束后，我们将 $\textit{ans}$ 加一，继续进行下一轮搜索。

遍历结束后，如果我们没有找到边界上的空格子，我们返回 $-1$。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别是迷宫的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def nearestExit(self, maze: List[List[str]], entrance: List[int]) -> int:
        m, n = len(maze), len(maze[0])
        i, j = entrance
        q = deque([(i, j)])
        maze[i][j] = "+"
        ans = 0
        while q:
            ans += 1
            for _ in range(len(q)):
                i, j = q.popleft()
                for a, b in [[0, -1], [0, 1], [-1, 0], [1, 0]]:
                    x, y = i + a, j + b
                    if 0 <= x < m and 0 <= y < n and maze[x][y] == ".":
                        if x == 0 or x == m - 1 or y == 0 or y == n - 1:
                            return ans
                        q.append((x, y))
                        maze[x][y] = "+"
        return -1
```

#### Java

```java
class Solution {
    public int nearestExit(char[][] maze, int[] entrance) {
        int m = maze.length, n = maze[0].length;
        final int[] dirs = {-1, 0, 1, 0, -1};
        Deque<int[]> q = new ArrayDeque<>();
        q.offer(entrance);
        maze[entrance[0]][entrance[1]] = '+';
        for (int ans = 1; !q.isEmpty(); ++ans) {
            for (int k = q.size(); k > 0; --k) {
                var p = q.poll();
                for (int d = 0; d < 4; ++d) {
                    int x = p[0] + dirs[d], y = p[1] + dirs[d + 1];
                    if (x >= 0 && x < m && y >= 0 && y < n && maze[x][y] == '.') {
                        if (x == 0 || x == m - 1 || y == 0 || y == n - 1) {
                            return ans;
                        }
                        maze[x][y] = '+';
                        q.offer(new int[] {x, y});
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
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size();
        int dirs[5] = {-1, 0, 1, 0, -1};
        queue<pair<int, int>> q;
        q.emplace(entrance[0], entrance[1]);
        maze[entrance[0]][entrance[1]] = '+';
        for (int ans = 1; !q.empty(); ++ans) {
            for (int k = q.size(); k; --k) {
                auto [i, j] = q.front();
                q.pop();
                for (int d = 0; d < 4; ++d) {
                    int x = i + dirs[d], y = j + dirs[d + 1];
                    if (x >= 0 && x < m && y >= 0 && y < n && maze[x][y] == '.') {
                        if (x == 0 || x == m - 1 || y == 0 || y == n - 1) {
                            return ans;
                        }
                        maze[x][y] = '+';
                        q.emplace(x, y);
                    }
                }
            }
        }
        return -1;
    }
};
```

#### Go

```go
func nearestExit(maze [][]byte, entrance []int) int {
	m, n := len(maze), len(maze[0])
	q := [][2]int{{entrance[0], entrance[1]}}
	maze[entrance[0]][entrance[1]] = '+'
	dirs := []int{-1, 0, 1, 0, -1}
	for ans := 1; len(q) > 0; ans++ {
		for k := len(q); k > 0; k-- {
			p := q[0]
			q = q[1:]
			for l := 0; l < 4; l++ {
				x, y := p[0]+dirs[l], p[1]+dirs[l+1]
				if x >= 0 && x < m && y >= 0 && y < n && maze[x][y] == '.' {
					if x == 0 || x == m-1 || y == 0 || y == n-1 {
						return ans
					}
					q = append(q, [2]int{x, y})
					maze[x][y] = '+'
				}
			}
		}
	}
	return -1
}
```

#### TypeScript

```ts
function nearestExit(maze: string[][], entrance: number[]): number {
    const dir = [0, 1, 0, -1, 0];
    const q = [[...entrance, 0]];
    maze[entrance[0]][entrance[1]] = '+';
    for (const [i, j, ans] of q) {
        for (let d = 0; d < 4; d++) {
            const [x, y] = [i + dir[d], j + dir[d + 1]];
            const v = maze[x]?.[y];
            if (!v && ans) {
                return ans;
            }
            if (v === '.') {
                q.push([x, y, ans + 1]);
                maze[x][y] = '+';
            }
        }
    }
    return -1;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1927. 求和游戏](https://leetcode.cn/problems/sum-game){#1927}

{{< tabs "1927" >}}

{{% tab "python" %}}
```python
class Solution:
    def sumGame(self, num: str) -> bool:
        n = len(num)
        cnt1 = num[: n // 2].count("?")
        cnt2 = num[n // 2 :].count("?")
        s1 = sum(int(x) for x in num[: n // 2] if x != "?")
        s2 = sum(int(x) for x in num[n // 2 :] if x != "?")
        return (cnt1 + cnt2) % 2 == 1 or s1 - s2 != 9 * (cnt2 - cnt1) // 2
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean sumGame(String num) {
        int n = num.length();
        int cnt1 = 0, cnt2 = 0;
        int s1 = 0, s2 = 0;
        for (int i = 0; i < n / 2; ++i) {
            if (num.charAt(i) == '?') {
                cnt1++;
            } else {
                s1 += num.charAt(i) - '0';
            }
        }
        for (int i = n / 2; i < n; ++i) {
            if (num.charAt(i) == '?') {
                cnt2++;
            } else {
                s2 += num.charAt(i) - '0';
            }
        }
        return (cnt1 + cnt2) % 2 == 1 || s1 - s2 != 9 * (cnt2 - cnt1) / 2;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int cnt1 = 0, cnt2 = 0;
        int s1 = 0, s2 = 0;
        for (int i = 0; i < n / 2; ++i) {
            if (num[i] == '?') {
                cnt1++;
            } else {
                s1 += num[i] - '0';
            }
        }
        for (int i = n / 2; i < n; ++i) {
            if (num[i] == '?') {
                cnt2++;
            } else {
                s2 += num[i] - '0';
            }
        }
        return (cnt1 + cnt2) % 2 == 1 || (s1 - s2) != 9 * (cnt2 - cnt1) / 2;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func sumGame(num string) bool {
	n := len(num)
	var cnt1, cnt2, s1, s2 int
	for i := 0; i < n/2; i++ {
		if num[i] == '?' {
			cnt1++
		} else {
			s1 += int(num[i] - '0')
		}
	}
	for i := n / 2; i < n; i++ {
		if num[i] == '?' {
			cnt2++
		} else {
			s2 += int(num[i] - '0')
		}
	}
	return (cnt1+cnt2)%2 == 1 || s1-s2 != (cnt2-cnt1)*9/2
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function sumGame(num: string): boolean {
    const n = num.length;
    let [cnt1, cnt2, s1, s2] = [0, 0, 0, 0];
    for (let i = 0; i < n >> 1; ++i) {
        if (num[i] === '?') {
            ++cnt1;
        } else {
            s1 += num[i].charCodeAt(0) - '0'.charCodeAt(0);
        }
    }
    for (let i = n >> 1; i < n; ++i) {
        if (num[i] === '?') {
            ++cnt2;
        } else {
            s2 += num[i].charCodeAt(0) - '0'.charCodeAt(0);
        }
    }
    return (cnt1 + cnt2) % 2 === 1 || 2 * (s1 - s2) !== 9 * (cnt2 - cnt1);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>Alice 和 Bob 玩一个游戏，两人轮流行动，<strong>Alice 先手</strong> 。</p>

<p>给你一个 <strong>偶数长度</strong> 的字符串 <code>num</code> ，每一个字符为数字字符或者 <code>'?'</code> 。每一次操作中，如果 <code>num</code> 中至少有一个 <code>'?'</code> ，那么玩家可以执行以下操作：</p>

<ol>
	<li>选择一个下标 <code>i</code> 满足 <code>num[i] == '?'</code> 。</li>
	<li>将 <code>num[i]</code> 用 <code>'0'</code> 到 <code>'9'</code> 之间的一个数字字符替代。</li>
</ol>

<p>当 <code>num</code> 中没有<span style=""> </span><code>'?'</code> 时，游戏结束。</p>

<p>Bob 获胜的条件是 <code>num</code> 中前一半数字的和 <strong>等于</strong> 后一半数字的和。Alice 获胜的条件是前一半的和与后一半的和 <strong>不相等</strong> 。</p>

<ul>
	<li>比方说，游戏结束时 <code>num = "243801"</code> ，那么 Bob 获胜，因为 <code>2+4+3 = 8+0+1</code> 。如果游戏结束时 <code>num = "243803"</code> ，那么 Alice 获胜，因为 <code>2+4+3 != 8+0+3</code> 。</li>
</ul>

<p>在 Alice 和 Bob 都采取 <strong>最优</strong> 策略的前提下，如果 Alice 获胜，请返回 <code>true</code> ，如果 Bob 获胜，请返回 <code>false</code> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>num = "5023"
<b>输出：</b>false
<b>解释：</b>num 中没有 '?' ，没法进行任何操作。
前一半的和等于后一半的和：5 + 0 = 2 + 3 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>num = "25??"
<b>输出：</b>true
<strong>解释：</strong>Alice 可以将两个 '?' 中的一个替换为 '9' ，Bob 无论如何都无法使前一半的和等于后一半的和。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>num = "?3295???"
<b>输出：</b>false
<b>解释：</b>Bob 总是能赢。一种可能的结果是：
- Alice 将第一个 '?' 用 '9' 替换。num = "93295???" 。
- Bob 将后面一半中的一个 '?' 替换为 '9' 。num = "932959??" 。
- Alice 将后面一半中的一个 '?' 替换为 '2' 。num = "9329592?" 。
- Bob 将后面一半中最后一个 '?' 替换为 '7' 。num = "93295927" 。
Bob 获胜，因为 9 + 3 + 2 + 9 = 5 + 9 + 2 + 7 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 <= num.length <= 10<sup>5</sup></code></li>
	<li><code>num.length</code> 是 <strong>偶数</strong> 。</li>
	<li><code>num</code> 只包含数字字符和 <code>'?'</code> 。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：分类讨论

如果 `'?'` 的个数为奇数，那么 Alice 一定会获胜，因为她可以选择将最后一个 `'?'` 替换为任何一个数字，使得前一半的和与后一半的和不相等。

如果 `'?'` 的个数为偶数，Alice 为了使得前一半的和与后一半的和不相等，那么会选择在当前和较大的一半数字中放置 $9$，在当前和较小的一半数字中放置 $0$，而 Bob 为了使得前后两半的和相等，那么会选择在 Alice 替换数字的另一半放置一个与 Alice 替换数字相同的数字。

因此，最终会使得剩下的所有偶数个 `'?'` 集中在其中一半。假设当前两半的数字差值为 $d$。

我们先考虑，如果剩下两个 `'?'`，差值为 $x$，此时：

-   如果 $x \lt 9$，那么 Alice 必胜，因为 Alice 可以将其中一个 `'?'` 替换为 $9$，使得前一半的和与后一半的和不相等；
-   如果 $x \gt 9$，那么 Alice 必胜，因为 Alice 可以将其中一个 `'?'` 替换为 $0$，使得前一半的和与后一半的和不相等；
-   如果 $x = 9$，那么 Bob 必胜，假设 Alice 替换的数字为 $a$，那么 Bob 可以将另一个 `'?'` 替换为 $9 - a$，使得前后两半的和相等。

因此，如果两半数字差值为 $d= \frac{9 \times cnt}{2}$，其中 $cnt$ 为剩下的 `'?'` 的个数，那么 Bob 必胜，否则 Alice 必胜。

时间复杂度 $O(n)$，其中 $n$ 为字符串的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def sumGame(self, num: str) -> bool:
        n = len(num)
        cnt1 = num[: n // 2].count("?")
        cnt2 = num[n // 2 :].count("?")
        s1 = sum(int(x) for x in num[: n // 2] if x != "?")
        s2 = sum(int(x) for x in num[n // 2 :] if x != "?")
        return (cnt1 + cnt2) % 2 == 1 or s1 - s2 != 9 * (cnt2 - cnt1) // 2
```

#### Java

```java
class Solution {
    public boolean sumGame(String num) {
        int n = num.length();
        int cnt1 = 0, cnt2 = 0;
        int s1 = 0, s2 = 0;
        for (int i = 0; i < n / 2; ++i) {
            if (num.charAt(i) == '?') {
                cnt1++;
            } else {
                s1 += num.charAt(i) - '0';
            }
        }
        for (int i = n / 2; i < n; ++i) {
            if (num.charAt(i) == '?') {
                cnt2++;
            } else {
                s2 += num.charAt(i) - '0';
            }
        }
        return (cnt1 + cnt2) % 2 == 1 || s1 - s2 != 9 * (cnt2 - cnt1) / 2;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int cnt1 = 0, cnt2 = 0;
        int s1 = 0, s2 = 0;
        for (int i = 0; i < n / 2; ++i) {
            if (num[i] == '?') {
                cnt1++;
            } else {
                s1 += num[i] - '0';
            }
        }
        for (int i = n / 2; i < n; ++i) {
            if (num[i] == '?') {
                cnt2++;
            } else {
                s2 += num[i] - '0';
            }
        }
        return (cnt1 + cnt2) % 2 == 1 || (s1 - s2) != 9 * (cnt2 - cnt1) / 2;
    }
};
```

#### Go

```go
func sumGame(num string) bool {
	n := len(num)
	var cnt1, cnt2, s1, s2 int
	for i := 0; i < n/2; i++ {
		if num[i] == '?' {
			cnt1++
		} else {
			s1 += int(num[i] - '0')
		}
	}
	for i := n / 2; i < n; i++ {
		if num[i] == '?' {
			cnt2++
		} else {
			s2 += int(num[i] - '0')
		}
	}
	return (cnt1+cnt2)%2 == 1 || s1-s2 != (cnt2-cnt1)*9/2
}
```

#### TypeScript

```ts
function sumGame(num: string): boolean {
    const n = num.length;
    let [cnt1, cnt2, s1, s2] = [0, 0, 0, 0];
    for (let i = 0; i < n >> 1; ++i) {
        if (num[i] === '?') {
            ++cnt1;
        } else {
            s1 += num[i].charCodeAt(0) - '0'.charCodeAt(0);
        }
    }
    for (let i = n >> 1; i < n; ++i) {
        if (num[i] === '?') {
            ++cnt2;
        } else {
            s2 += num[i].charCodeAt(0) - '0'.charCodeAt(0);
        }
    }
    return (cnt1 + cnt2) % 2 === 1 || 2 * (s1 - s2) !== 9 * (cnt2 - cnt1);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1928. 规定时间内到达终点的最小花费](https://leetcode.cn/problems/minimum-cost-to-reach-destination-in-time){#1928}

{{< tabs "1928" >}}

{{% tab "python" %}}
```python
class Solution:
    def minCost(
        self, maxTime: int, edges: List[List[int]], passingFees: List[int]
    ) -> int:
        m, n = maxTime, len(passingFees)
        f = [[inf] * n for _ in range(m + 1)]
        f[0][0] = passingFees[0]
        for i in range(1, m + 1):
            for x, y, t in edges:
                if t <= i:
                    f[i][x] = min(f[i][x], f[i - t][y] + passingFees[x])
                    f[i][y] = min(f[i][y], f[i - t][x] + passingFees[y])
        ans = min(f[i][n - 1] for i in range(m + 1))
        return ans if ans < inf else -1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minCost(int maxTime, int[][] edges, int[] passingFees) {
        int m = maxTime, n = passingFees.length;
        int[][] f = new int[m + 1][n];
        final int inf = 1 << 30;
        for (var g : f) {
            Arrays.fill(g, inf);
        }
        f[0][0] = passingFees[0];
        for (int i = 1; i <= m; ++i) {
            for (var e : edges) {
                int x = e[0], y = e[1], t = e[2];
                if (t <= i) {
                    f[i][x] = Math.min(f[i][x], f[i - t][y] + passingFees[x]);
                    f[i][y] = Math.min(f[i][y], f[i - t][x] + passingFees[y]);
                }
            }
        }
        int ans = inf;
        for (int i = 0; i <= m; ++i) {
            ans = Math.min(ans, f[i][n - 1]);
        }
        return ans == inf ? -1 : ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int m = maxTime, n = passingFees.size();
        const int inf = 1 << 30;
        vector<vector<int>> f(m + 1, vector<int>(n, inf));
        f[0][0] = passingFees[0];
        for (int i = 1; i <= m; ++i) {
            for (const auto& e : edges) {
                int x = e[0], y = e[1], t = e[2];
                if (t <= i) {
                    f[i][x] = min(f[i][x], f[i - t][y] + passingFees[x]);
                    f[i][y] = min(f[i][y], f[i - t][x] + passingFees[y]);
                }
            }
        }
        int ans = inf;
        for (int i = 1; i <= m; ++i) {
            ans = min(ans, f[i][n - 1]);
        }
        return ans == inf ? -1 : ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minCost(maxTime int, edges [][]int, passingFees []int) int {
	m, n := maxTime, len(passingFees)
	f := make([][]int, m+1)
	const inf int = 1 << 30
	for i := range f {
		f[i] = make([]int, n)
		for j := range f[i] {
			f[i][j] = inf
		}
	}
	f[0][0] = passingFees[0]
	for i := 1; i <= m; i++ {
		for _, e := range edges {
			x, y, t := e[0], e[1], e[2]
			if t <= i {
				f[i][x] = min(f[i][x], f[i-t][y]+passingFees[x])
				f[i][y] = min(f[i][y], f[i-t][x]+passingFees[y])
			}
		}
	}
	ans := inf
	for i := 1; i <= m; i++ {
		ans = min(ans, f[i][n-1])
	}
	if ans == inf {
		return -1
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minCost(maxTime: number, edges: number[][], passingFees: number[]): number {
    const [m, n] = [maxTime, passingFees.length];
    const f: number[][] = Array.from({ length: m + 1 }, () => Array(n).fill(Infinity));
    f[0][0] = passingFees[0];
    for (let i = 1; i <= m; ++i) {
        for (const [x, y, t] of edges) {
            if (t <= i) {
                f[i][x] = Math.min(f[i][x], f[i - t][y] + passingFees[x]);
                f[i][y] = Math.min(f[i][y], f[i - t][x] + passingFees[y]);
            }
        }
    }
    let ans = Infinity;
    for (let i = 1; i <= m; ++i) {
        ans = Math.min(ans, f[i][n - 1]);
    }
    return ans === Infinity ? -1 : ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>一个国家有 <code>n</code> 个城市，城市编号为 <code>0</code> 到 <code>n - 1</code> ，题目保证 <strong>所有城市</strong> 都由双向道路 <b>连接在一起</b> 。道路由二维整数数组 <code>edges</code> 表示，其中 <code>edges[i] = [x<sub>i</sub>, y<sub>i</sub>, time<sub>i</sub>]</code> 表示城市 <code>x<sub>i</sub></code> 和 <code>y<sub>i</sub></code> 之间有一条双向道路，耗费时间为 <code>time<sub>i</sub></code> 分钟。两个城市之间可能会有多条耗费时间不同的道路，但是不会有道路两头连接着同一座城市。</p>

<p>每次经过一个城市时，你需要付通行费。通行费用一个长度为 <code>n</code> 且下标从 <strong>0</strong> 开始的整数数组 <code>passingFees</code> 表示，其中 <code>passingFees[j]</code> 是你经过城市 <code>j</code> 需要支付的费用。</p>

<p>一开始，你在城市 <code>0</code> ，你想要在 <code>maxTime</code> <strong>分钟以内</strong> （包含 <code>maxTime</code> 分钟）到达城市 <code>n - 1</code> 。旅行的 <strong>费用</strong> 为你经过的所有城市 <strong>通行费之和</strong> （<strong>包括</strong> 起点和终点城市的通行费）。</p>

<p>给你 <code>maxTime</code>，<code>edges</code> 和 <code>passingFees</code> ，请你返回完成旅行的 <strong>最小费用</strong> ，如果无法在 <code>maxTime</code> 分钟以内完成旅行，请你返回 <code>-1</code> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1900-1999/1928.Minimum%20Cost%20to%20Reach%20Destination%20in%20Time/images/leetgraph1-1.png" style="width: 371px; height: 171px;" /></p>

<pre>
<b>输入：</b>maxTime = 30, edges = [[0,1,10],[1,2,10],[2,5,10],[0,3,1],[3,4,10],[4,5,15]], passingFees = [5,1,2,20,20,3]
<b>输出：</b>11
<b>解释：</b>最优路径为 0 -> 1 -> 2 -> 5 ，总共需要耗费 30 分钟，需要支付 11 的通行费。
</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1900-1999/1928.Minimum%20Cost%20to%20Reach%20Destination%20in%20Time/images/copy-of-leetgraph1-1.png" style="width: 371px; height: 171px;" /></strong></p>

<pre>
<b>输入：</b>maxTime = 29, edges = [[0,1,10],[1,2,10],[2,5,10],[0,3,1],[3,4,10],[4,5,15]], passingFees = [5,1,2,20,20,3]
<b>输出：</b>48
<b>解释：</b>最优路径为 0 -> 3 -> 4 -> 5 ，总共需要耗费 26 分钟，需要支付 48 的通行费。
你不能选择路径 0 -> 1 -> 2 -> 5 ，因为这条路径耗费的时间太长。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>maxTime = 25, edges = [[0,1,10],[1,2,10],[2,5,10],[0,3,1],[3,4,10],[4,5,15]], passingFees = [5,1,2,20,20,3]
<b>输出：</b>-1
<b>解释：</b>无法在 25 分钟以内从城市 0 到达城市 5 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= maxTime <= 1000</code></li>
	<li><code>n == passingFees.length</code></li>
	<li><code>2 <= n <= 1000</code></li>
	<li><code>n - 1 <= edges.length <= 1000</code></li>
	<li><code>0 <= x<sub>i</sub>, y<sub>i</sub> <= n - 1</code></li>
	<li><code>1 <= time<sub>i</sub> <= 1000</code></li>
	<li><code>1 <= passingFees[j] <= 1000</code> </li>
	<li>图中两个节点之间可能有多条路径。</li>
	<li>图中不含有自环。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i][j]$ 表示经过 $i$ 分钟，从城市 $0$ 到达城市 $j$ 的最小花费。初始时 $f[0][0] = \textit{passingFees}[0]$，其余的 $f[0][j] = +\infty$。

接下来，我们在 $[1, \textit{maxTime}]$ 的时间范围内，遍历所有的边，对于每一条边 $(x, y, t)$，如果 $t \leq i$，那么我们：

-   可以先经过 $i - t$ 分钟，从城市 $0$ 到达城市 $y$，然后再经过 $t$ 分钟，从城市 $y$ 到达城市 $x$，再加上到达城市 $x$ 的通行费，即 $f[i][x] = \min(f[i][x], f[i - t][y] + \textit{passingFees}[x])$；
-   也可以先经过 $i - t$ 分钟，从城市 $0$ 到达城市 $x$，然后再经过 $t$ 分钟，从城市 $x$ 到达城市 $y$，再加上到达城市 $y$ 的通行费，即 $f[i][y] = \min(f[i][y], f[i - t][x] + \textit{passingFees}[y])$。

最终答案即为 $\min\{f[i][n - 1]\}$，其中 $i \in [0, \textit{maxTime}]$。如果答案为 $+\infty$，则返回 $-1$。

时间复杂度 $O(\textit{maxTime} \times (m + n))$，其中 $m$ 和 $n$ 分别是边的数量和城市的数量。空间复杂度 $O(\textit{maxTime} \times n)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minCost(
        self, maxTime: int, edges: List[List[int]], passingFees: List[int]
    ) -> int:
        m, n = maxTime, len(passingFees)
        f = [[inf] * n for _ in range(m + 1)]
        f[0][0] = passingFees[0]
        for i in range(1, m + 1):
            for x, y, t in edges:
                if t <= i:
                    f[i][x] = min(f[i][x], f[i - t][y] + passingFees[x])
                    f[i][y] = min(f[i][y], f[i - t][x] + passingFees[y])
        ans = min(f[i][n - 1] for i in range(m + 1))
        return ans if ans < inf else -1
```

#### Java

```java
class Solution {
    public int minCost(int maxTime, int[][] edges, int[] passingFees) {
        int m = maxTime, n = passingFees.length;
        int[][] f = new int[m + 1][n];
        final int inf = 1 << 30;
        for (var g : f) {
            Arrays.fill(g, inf);
        }
        f[0][0] = passingFees[0];
        for (int i = 1; i <= m; ++i) {
            for (var e : edges) {
                int x = e[0], y = e[1], t = e[2];
                if (t <= i) {
                    f[i][x] = Math.min(f[i][x], f[i - t][y] + passingFees[x]);
                    f[i][y] = Math.min(f[i][y], f[i - t][x] + passingFees[y]);
                }
            }
        }
        int ans = inf;
        for (int i = 0; i <= m; ++i) {
            ans = Math.min(ans, f[i][n - 1]);
        }
        return ans == inf ? -1 : ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int m = maxTime, n = passingFees.size();
        const int inf = 1 << 30;
        vector<vector<int>> f(m + 1, vector<int>(n, inf));
        f[0][0] = passingFees[0];
        for (int i = 1; i <= m; ++i) {
            for (const auto& e : edges) {
                int x = e[0], y = e[1], t = e[2];
                if (t <= i) {
                    f[i][x] = min(f[i][x], f[i - t][y] + passingFees[x]);
                    f[i][y] = min(f[i][y], f[i - t][x] + passingFees[y]);
                }
            }
        }
        int ans = inf;
        for (int i = 1; i <= m; ++i) {
            ans = min(ans, f[i][n - 1]);
        }
        return ans == inf ? -1 : ans;
    }
};
```

#### Go

```go
func minCost(maxTime int, edges [][]int, passingFees []int) int {
	m, n := maxTime, len(passingFees)
	f := make([][]int, m+1)
	const inf int = 1 << 30
	for i := range f {
		f[i] = make([]int, n)
		for j := range f[i] {
			f[i][j] = inf
		}
	}
	f[0][0] = passingFees[0]
	for i := 1; i <= m; i++ {
		for _, e := range edges {
			x, y, t := e[0], e[1], e[2]
			if t <= i {
				f[i][x] = min(f[i][x], f[i-t][y]+passingFees[x])
				f[i][y] = min(f[i][y], f[i-t][x]+passingFees[y])
			}
		}
	}
	ans := inf
	for i := 1; i <= m; i++ {
		ans = min(ans, f[i][n-1])
	}
	if ans == inf {
		return -1
	}
	return ans
}
```

#### TypeScript

```ts
function minCost(maxTime: number, edges: number[][], passingFees: number[]): number {
    const [m, n] = [maxTime, passingFees.length];
    const f: number[][] = Array.from({ length: m + 1 }, () => Array(n).fill(Infinity));
    f[0][0] = passingFees[0];
    for (let i = 1; i <= m; ++i) {
        for (const [x, y, t] of edges) {
            if (t <= i) {
                f[i][x] = Math.min(f[i][x], f[i - t][y] + passingFees[x]);
                f[i][y] = Math.min(f[i][y], f[i - t][x] + passingFees[y]);
            }
        }
    }
    let ans = Infinity;
    for (let i = 1; i <= m; ++i) {
        ans = Math.min(ans, f[i][n - 1]);
    }
    return ans === Infinity ? -1 : ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1929. 数组串联](https://leetcode.cn/problems/concatenation-of-array){#1929}

{{< tabs "1929" >}}

{{% tab "python" %}}
```python
class Solution:
    def getConcatenation(self, nums: List[int]) -> List[int]:
        return nums + nums
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] getConcatenation(int[] nums) {
        int n = nums.length;
        int[] ans = new int[n << 1];
        for (int i = 0; i < n << 1; ++i) {
            ans[i] = nums[i % n];
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
    vector<int> getConcatenation(vector<int>& nums) {
        for (int i = 0, n = nums.size(); i < n; ++i) {
            nums.push_back(nums[i]);
        }
        return nums;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func getConcatenation(nums []int) []int {
	return append(nums, nums...)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function getConcatenation(nums: number[]): number[] {
    return [...nums, ...nums];
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn get_concatenation(nums: Vec<i32>) -> Vec<i32> {
        nums.repeat(2)
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var getConcatenation = function (nums) {
    return [...nums, ...nums];
};
```
{{% /tab %}}
{{% tab "c" %}}
```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getConcatenation(int* nums, int numsSize, int* returnSize) {
    int* ans = malloc(sizeof(int) * numsSize * 2);
    for (int i = 0; i < numsSize; i++) {
        ans[i] = ans[i + numsSize] = nums[i];
    }
    *returnSize = numsSize * 2;
    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个长度为 <code>n</code> 的整数数组 <code>nums</code> 。请你构建一个长度为 <code>2n</code> 的答案数组 <code>ans</code> ，数组下标<strong> 从 0 开始计数 </strong>，对于所有 <code>0 <= i < n</code> 的 <code>i</code> ，满足下述所有要求：</p>

<ul>
	<li><code>ans[i] == nums[i]</code></li>
	<li><code>ans[i + n] == nums[i]</code></li>
</ul>

<p>具体而言，<code>ans</code> 由两个 <code>nums</code> 数组 <strong>串联</strong> 形成。</p>

<p>返回数组<em> </em><code>ans</code> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,1]
<strong>输出：</strong>[1,2,1,1,2,1]
<strong>解释：</strong>数组 ans 按下述方式形成：
- ans = [nums[0],nums[1],nums[2],nums[0],nums[1],nums[2]]
- ans = [1,2,1,1,2,1]</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,3,2,1]
<strong>输出：</strong>[1,3,2,1,1,3,2,1]
<strong>解释：</strong>数组 ans 按下述方式形成：
- ans = [nums[0],nums[1],nums[2],nums[3],nums[0],nums[1],nums[2],nums[3]]
- ans = [1,3,2,1,1,3,2,1]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 <= n <= 1000</code></li>
	<li><code>1 <= nums[i] <= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们直接根据题目描述模拟，将 $\textit{nums}$ 中的元素依次添加到答案数组中，然后再将 $\textit{nums}$ 中的元素再次添加到答案数组中。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $\textit{nums}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def getConcatenation(self, nums: List[int]) -> List[int]:
        return nums + nums
```

#### Java

```java
class Solution {
    public int[] getConcatenation(int[] nums) {
        int n = nums.length;
        int[] ans = new int[n << 1];
        for (int i = 0; i < n << 1; ++i) {
            ans[i] = nums[i % n];
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        for (int i = 0, n = nums.size(); i < n; ++i) {
            nums.push_back(nums[i]);
        }
        return nums;
    }
};
```

#### Go

```go
func getConcatenation(nums []int) []int {
	return append(nums, nums...)
}
```

#### TypeScript

```ts
function getConcatenation(nums: number[]): number[] {
    return [...nums, ...nums];
}
```

#### Rust

```rust
impl Solution {
    pub fn get_concatenation(nums: Vec<i32>) -> Vec<i32> {
        nums.repeat(2)
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var getConcatenation = function (nums) {
    return [...nums, ...nums];
};
```

#### C

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getConcatenation(int* nums, int numsSize, int* returnSize) {
    int* ans = malloc(sizeof(int) * numsSize * 2);
    for (int i = 0; i < numsSize; i++) {
        ans[i] = ans[i + numsSize] = nums[i];
    }
    *returnSize = numsSize * 2;
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
