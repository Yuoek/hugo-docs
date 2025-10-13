---
title: "2550_猴子碰撞的方法数"
date: 2025-10-08T18:39:23+08:00
weight: 6
tags: [二分查找, 前缀和, 动态规划, 哈希表, 堆（优先队列）, 字符串, 广度优先搜索, 排序, 数学, 数组, 枚举, 树状数组, 模拟, 深度优先搜索, 滑动窗口, 矩阵, 贪心, 递归]
---

{{< markmap >}}
### [2550_猴子碰撞的方法数](#2550)
#### [递归](#2550)
#### [数学](#2550)
### [2551_将珠子放入背包中](#2551)
#### [贪心](#2551)
#### [数组](#2551)
#### [排序](#2551)
#### [堆（优先队列）](#2551)
### [2552_统计上升四元组](#2552)
#### [树状数组](#2552)
#### [数组](#2552)
#### [动态规划](#2552)
#### [枚举](#2552)
#### [前缀和](#2552)
### [2553_分割数组中数字的数位](#2553)
#### [数组](#2553)
#### [模拟](#2553)
### [2554_从一个范围内选择最多整数 I](#2554)
#### [贪心](#2554)
#### [数组](#2554)
#### [哈希表](#2554)
#### [二分查找](#2554)
#### [排序](#2554)
### [2555_两个线段获得的最多奖品](#2555)
#### [数组](#2555)
#### [二分查找](#2555)
#### [滑动窗口](#2555)
### [2556_二进制矩阵中翻转最多一次使路径不连通](#2556)
#### [深度优先搜索](#2556)
#### [广度优先搜索](#2556)
#### [数组](#2556)
#### [动态规划](#2556)
#### [矩阵](#2556)
### [2557_从一个范围内选择最多整数 II 🔒](#2557)
#### [贪心](#2557)
#### [数组](#2557)
#### [二分查找](#2557)
#### [排序](#2557)
### [2558_从数量最多的堆取走礼物](#2558)
#### [数组](#2558)
#### [模拟](#2558)
#### [堆（优先队列）](#2558)
### [2559_统计范围内的元音字符串数](#2559)
#### [数组](#2559)
#### [字符串](#2559)
#### [前缀和](#2559)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2550_猴子碰撞的方法数
___
#### 递归
___
#### 数学
---
### 2551_将珠子放入背包中
___
#### 贪心
___
#### 数组
___
#### 排序
___
#### 堆（优先队列）
---
### 2552_统计上升四元组
___
#### 树状数组
___
#### 数组
___
#### 动态规划
___
#### 枚举
___
#### 前缀和
---
### 2553_分割数组中数字的数位
___
#### 数组
___
#### 模拟
---
### 2554_从一个范围内选择最多整数 I
___
#### 贪心
___
#### 数组
___
#### 哈希表
___
#### 二分查找
___
#### 排序
---
### 2555_两个线段获得的最多奖品
___
#### 数组
___
#### 二分查找
___
#### 滑动窗口
---
### 2556_二进制矩阵中翻转最多一次使路径不连通
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 数组
___
#### 动态规划
___
#### 矩阵
---
### 2557_从一个范围内选择最多整数 II 🔒
___
#### 贪心
___
#### 数组
___
#### 二分查找
___
#### 排序
---
### 2558_从数量最多的堆取走礼物
___
#### 数组
___
#### 模拟
___
#### 堆（优先队列）
---
### 2559_统计范围内的元音字符串数
___
#### 数组
___
#### 字符串
___
#### 前缀和
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 前缀和 | 动态规划 |
| 哈希表 | 堆（优先队列） | 字符串 |
| 广度优先搜索 | 排序 | 数学 |
| 数组 | 枚举 | 树状数组 |
| 模拟 | 深度优先搜索 | 滑动窗口 |
| 矩阵 | 贪心 | 递归 |

# [2550. 猴子碰撞的方法数](https://leetcode.cn/problems/count-collisions-of-monkeys-on-a-polygon){#2550}

{{< tabs "2550" >}}

{{% tab "python" %}}
```python
class Solution:
    def monkeyMove(self, n: int) -> int:
        mod = 10**9 + 7
        return (pow(2, n, mod) - 2) % mod
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int monkeyMove(int n) {
        final int mod = (int) 1e9 + 7;
        return (qpow(2, n, mod) - 2 + mod) % mod;
    }

    private int qpow(long a, int n, int mod) {
        long ans = 1;
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
class Solution {
public:
    int monkeyMove(int n) {
        const int mod = 1e9 + 7;
        using ll = long long;
        auto qpow = [&](ll a, int n) {
            ll ans = 1;
            for (; n; n >>= 1) {
                if (n & 1) {
                    ans = ans * a % mod;
                }
                a = a * a % mod;
            }
            return ans;
        };
        return (qpow(2, n) - 2 + mod) % mod;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func monkeyMove(n int) int {
	const mod = 1e9 + 7
	qpow := func(a, n int) int {
		ans := 1
		for ; n > 0; n >>= 1 {
			if n&1 == 1 {
				ans = ans * a % mod
			}
			a = a * a % mod
		}
		return ans
	}
	return (qpow(2, n) - 2 + mod) % mod
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function monkeyMove(n: number): number {
    const mod = 10 ** 9 + 7;
    const qpow = (a: number, n: number): number => {
        let ans = 1n;
        for (; n; n >>>= 1) {
            if (n & 1) {
                ans = (ans * BigInt(a)) % BigInt(mod);
            }
            a = Number((BigInt(a) * BigInt(a)) % BigInt(mod));
        }
        return Number(ans);
    };
    return (qpow(2, n) - 2 + mod) % mod;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>现在有一个正凸多边形，其上共有 <code>n</code> 个顶点。顶点按顺时针方向从 <code>0</code> 到 <code>n - 1</code> 依次编号。每个顶点上 <strong>正好有一只猴子</strong> 。下图中是一个 6 个顶点的凸多边形。</p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2500-2599/2550.Count%20Collisions%20of%20Monkeys%20on%20a%20Polygon/images/hexagon.jpg" style="width: 300px; height: 293px;" /></p>

<p>每个猴子同时移动到相邻的顶点。顶点 <code>i</code> 的相邻顶点可以是：</p>

<ul>
	<li>顺时针方向的顶点 <code>(i + 1) % n</code> ，或</li>
	<li>逆时针方向的顶点 <code>(i - 1 + n) % n</code> 。</li>
</ul>

<p>如果移动后至少有两只猴子停留在同一个顶点上或者相交在一条边上，则会发生 <strong>碰撞</strong> 。</p>

<p>返回猴子至少发生 <strong>一次碰撞 </strong>的移动方法数。由于答案可能非常大，请返回对 <code>10<sup>9</sup>+7</code> 取余后的结果。</p>

<p><strong>注意</strong>，每只猴子只能移动一次。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 3
<strong>输出：</strong>6
<strong>解释：</strong>共计 8 种移动方式。
下面列出两种会发生碰撞的方式：
- 猴子 1 顺时针移动；猴子 2 逆时针移动；猴子 3 顺时针移动。猴子 1 和猴子 2 碰撞。
- 猴子 1 逆时针移动；猴子 2 逆时针移动；猴子 3 顺时针移动。猴子 1 和猴子 3 碰撞。
可以证明，有 6 种让猴子碰撞的方法。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 4
<strong>输出：</strong>14
<strong>解释：</strong>可以证明，有 14 种让猴子碰撞的方法。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= n &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数学（快速幂）

根据题目描述，每一只猴子都有两种移动方式，即顺时针或逆时针。因此，一共有 $2^n$ 种移动方式。不碰撞的移动方式只有两种，即所有猴子都顺时针移动或所有猴子都逆时针移动。因此，碰撞的移动方式有 $2^n - 2$ 种。

我们可以用快速幂求出 $2^n$ 的值，然后用 $2^n - 2$ 求出碰撞的移动方式数，最后对 $10^9 + 7$ 取余即可。

时间复杂度 $O(\log n)$，其中 $n$ 为猴子的数量。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def monkeyMove(self, n: int) -> int:
        mod = 10**9 + 7
        return (pow(2, n, mod) - 2) % mod
```

#### Java

```java
class Solution {
    public int monkeyMove(int n) {
        final int mod = (int) 1e9 + 7;
        return (qpow(2, n, mod) - 2 + mod) % mod;
    }

    private int qpow(long a, int n, int mod) {
        long ans = 1;
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
class Solution {
public:
    int monkeyMove(int n) {
        const int mod = 1e9 + 7;
        using ll = long long;
        auto qpow = [&](ll a, int n) {
            ll ans = 1;
            for (; n; n >>= 1) {
                if (n & 1) {
                    ans = ans * a % mod;
                }
                a = a * a % mod;
            }
            return ans;
        };
        return (qpow(2, n) - 2 + mod) % mod;
    }
};
```

#### Go

```go
func monkeyMove(n int) int {
	const mod = 1e9 + 7
	qpow := func(a, n int) int {
		ans := 1
		for ; n > 0; n >>= 1 {
			if n&1 == 1 {
				ans = ans * a % mod
			}
			a = a * a % mod
		}
		return ans
	}
	return (qpow(2, n) - 2 + mod) % mod
}
```

#### TypeScript

```ts
function monkeyMove(n: number): number {
    const mod = 10 ** 9 + 7;
    const qpow = (a: number, n: number): number => {
        let ans = 1n;
        for (; n; n >>>= 1) {
            if (n & 1) {
                ans = (ans * BigInt(a)) % BigInt(mod);
            }
            a = Number((BigInt(a) * BigInt(a)) % BigInt(mod));
        }
        return Number(ans);
    };
    return (qpow(2, n) - 2 + mod) % mod;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2551. 将珠子放入背包中](https://leetcode.cn/problems/put-marbles-in-bags){#2551}

{{< tabs "2551" >}}

{{% tab "python" %}}
```python
class Solution:
    def putMarbles(self, weights: List[int], k: int) -> int:
        arr = sorted(a + b for a, b in pairwise(weights))
        return sum(arr[len(arr) - k + 1 :]) - sum(arr[: k - 1])
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long putMarbles(int[] weights, int k) {
        int n = weights.length;
        int[] arr = new int[n - 1];
        for (int i = 0; i < n - 1; ++i) {
            arr[i] = weights[i] + weights[i + 1];
        }
        Arrays.sort(arr);
        long ans = 0;
        for (int i = 0; i < k - 1; ++i) {
            ans -= arr[i];
            ans += arr[n - 2 - i];
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
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        vector<int> arr(n - 1);
        for (int i = 0; i < n - 1; ++i) {
            arr[i] = weights[i] + weights[i + 1];
        }
        sort(arr.begin(), arr.end());
        long long ans = 0;
        for (int i = 0; i < k - 1; ++i) {
            ans -= arr[i];
            ans += arr[n - 2 - i];
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func putMarbles(weights []int, k int) (ans int64) {
	n := len(weights)
	arr := make([]int, n-1)
	for i, w := range weights[:n-1] {
		arr[i] = w + weights[i+1]
	}
	sort.Ints(arr)
	for i := 0; i < k-1; i++ {
		ans += int64(arr[n-2-i] - arr[i])
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function putMarbles(weights: number[], k: number): number {
    const n = weights.length;
    const arr: number[] = [];
    for (let i = 0; i < n - 1; ++i) {
        arr.push(weights[i] + weights[i + 1]);
    }
    arr.sort((a, b) => a - b);
    let ans = 0;
    for (let i = 0; i < k - 1; ++i) {
        ans += arr[n - i - 2] - arr[i];
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

<p>你有&nbsp;<code>k</code>&nbsp;个背包。给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>weights</code>&nbsp;，其中&nbsp;<code>weights[i]</code>&nbsp;是第&nbsp;<code>i</code>&nbsp;个珠子的重量。同时给你整数 <code>k</code>&nbsp;。</p>

<p>请你按照如下规则将所有的珠子放进&nbsp;<code>k</code>&nbsp;个背包。</p>

<ul>
	<li>没有背包是空的。</li>
	<li>如果第&nbsp;<code>i</code>&nbsp;个珠子和第&nbsp;<code>j</code>&nbsp;个珠子在同一个背包里，那么下标在&nbsp;<code>i</code>&nbsp;到&nbsp;<code>j</code>&nbsp;之间的所有珠子都必须在这同一个背包中。</li>
	<li>如果一个背包有下标从&nbsp;<code>i</code>&nbsp;到&nbsp;<code>j</code>&nbsp;的所有珠子，那么这个背包的价格是&nbsp;<code>weights[i] + weights[j]</code>&nbsp;。</li>
</ul>

<p>一个珠子分配方案的 <strong>分数</strong>&nbsp;是所有 <code>k</code>&nbsp;个背包的价格之和。</p>

<p>请你返回所有分配方案中，<strong>最大分数</strong>&nbsp;与 <strong>最小分数</strong>&nbsp;的 <strong>差值</strong>&nbsp;为多少。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>weights = [1,3,5,1], k = 2
<b>输出：</b>4
<b>解释：</b>
分配方案 [1],[3,5,1] 得到最小得分 (1+1) + (3+1) = 6 。
分配方案 [1,3],[5,1] 得到最大得分 (1+3) + (5+1) = 10 。
所以差值为 10 - 6 = 4 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>weights = [1, 3], k = 2
<b>输出：</b>0
<b>解释：</b>唯一的分配方案为 [1],[3] 。
最大最小得分相等，所以返回 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= weights.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= weights[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：问题转化 + 排序

我们可以将问题转化为：将数组 `weights` 分成 $k$ 个连续的子数组，也就是说，我们要找到 $k-1$ 个分割点，每个分割点的价格是分割点左右两个元素的和，求最大的 $k-1$ 个分割点的价格之和与最小的 $k-1$ 个分割点的价格之和的差值，即为答案。

因此，我们可以处理数组 `weights`，将其转化为一个长度为 $n-1$ 的数组 `arr`，其中 `arr[i] = weights[i] + weights[i+1]`，然后对数组 `arr` 进行排序，最后求出最大的 $k-1$ 个分割点的价格之和与最小的 $k-1$ 个分割点的价格之和的差值即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 `weights` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def putMarbles(self, weights: List[int], k: int) -> int:
        arr = sorted(a + b for a, b in pairwise(weights))
        return sum(arr[len(arr) - k + 1 :]) - sum(arr[: k - 1])
```

#### Java

```java
class Solution {
    public long putMarbles(int[] weights, int k) {
        int n = weights.length;
        int[] arr = new int[n - 1];
        for (int i = 0; i < n - 1; ++i) {
            arr[i] = weights[i] + weights[i + 1];
        }
        Arrays.sort(arr);
        long ans = 0;
        for (int i = 0; i < k - 1; ++i) {
            ans -= arr[i];
            ans += arr[n - 2 - i];
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        vector<int> arr(n - 1);
        for (int i = 0; i < n - 1; ++i) {
            arr[i] = weights[i] + weights[i + 1];
        }
        sort(arr.begin(), arr.end());
        long long ans = 0;
        for (int i = 0; i < k - 1; ++i) {
            ans -= arr[i];
            ans += arr[n - 2 - i];
        }
        return ans;
    }
};
```

#### Go

```go
func putMarbles(weights []int, k int) (ans int64) {
	n := len(weights)
	arr := make([]int, n-1)
	for i, w := range weights[:n-1] {
		arr[i] = w + weights[i+1]
	}
	sort.Ints(arr)
	for i := 0; i < k-1; i++ {
		ans += int64(arr[n-2-i] - arr[i])
	}
	return
}
```

#### TypeScript

```ts
function putMarbles(weights: number[], k: number): number {
    const n = weights.length;
    const arr: number[] = [];
    for (let i = 0; i < n - 1; ++i) {
        arr.push(weights[i] + weights[i + 1]);
    }
    arr.sort((a, b) => a - b);
    let ans = 0;
    for (let i = 0; i < k - 1; ++i) {
        ans += arr[n - i - 2] - arr[i];
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2552. 统计上升四元组](https://leetcode.cn/problems/count-increasing-quadruplets){#2552}

{{< tabs "2552" >}}

{{% tab "python" %}}
```python
class Solution:
    def countQuadruplets(self, nums: List[int]) -> int:
        n = len(nums)
        f = [[0] * n for _ in range(n)]
        g = [[0] * n for _ in range(n)]
        for j in range(1, n - 2):
            cnt = sum(nums[l] > nums[j] for l in range(j + 1, n))
            for k in range(j + 1, n - 1):
                if nums[j] > nums[k]:
                    f[j][k] = cnt
                else:
                    cnt -= 1
        for k in range(2, n - 1):
            cnt = sum(nums[i] < nums[k] for i in range(k))
            for j in range(k - 1, 0, -1):
                if nums[j] > nums[k]:
                    g[j][k] = cnt
                else:
                    cnt -= 1
        return sum(
            f[j][k] * g[j][k] for j in range(1, n - 2) for k in range(j + 1, n - 1)
        )
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long countQuadruplets(int[] nums) {
        int n = nums.length;
        int[][] f = new int[n][n];
        int[][] g = new int[n][n];
        for (int j = 1; j < n - 2; ++j) {
            int cnt = 0;
            for (int l = j + 1; l < n; ++l) {
                if (nums[l] > nums[j]) {
                    ++cnt;
                }
            }
            for (int k = j + 1; k < n - 1; ++k) {
                if (nums[j] > nums[k]) {
                    f[j][k] = cnt;
                } else {
                    --cnt;
                }
            }
        }
        long ans = 0;
        for (int k = 2; k < n - 1; ++k) {
            int cnt = 0;
            for (int i = 0; i < k; ++i) {
                if (nums[i] < nums[k]) {
                    ++cnt;
                }
            }
            for (int j = k - 1; j > 0; --j) {
                if (nums[j] > nums[k]) {
                    g[j][k] = cnt;
                    ans += (long) f[j][k] * g[j][k];
                } else {
                    --cnt;
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
const int N = 4001;
int f[N][N];
int g[N][N];

class Solution {
public:
    long long countQuadruplets(vector<int>& nums) {
        int n = nums.size();
        memset(f, 0, sizeof f);
        memset(g, 0, sizeof g);
        for (int j = 1; j < n - 2; ++j) {
            int cnt = 0;
            for (int l = j + 1; l < n; ++l) {
                if (nums[l] > nums[j]) {
                    ++cnt;
                }
            }
            for (int k = j + 1; k < n - 1; ++k) {
                if (nums[j] > nums[k]) {
                    f[j][k] = cnt;
                } else {
                    --cnt;
                }
            }
        }
        long long ans = 0;
        for (int k = 2; k < n - 1; ++k) {
            int cnt = 0;
            for (int i = 0; i < k; ++i) {
                if (nums[i] < nums[k]) {
                    ++cnt;
                }
            }
            for (int j = k - 1; j > 0; --j) {
                if (nums[j] > nums[k]) {
                    g[j][k] = cnt;
                    ans += 1ll * f[j][k] * g[j][k];
                } else {
                    --cnt;
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
func countQuadruplets(nums []int) int64 {
	n := len(nums)
	f := make([][]int, n)
	g := make([][]int, n)
	for i := range f {
		f[i] = make([]int, n)
		g[i] = make([]int, n)
	}
	for j := 1; j < n-2; j++ {
		cnt := 0
		for l := j + 1; l < n; l++ {
			if nums[l] > nums[j] {
				cnt++
			}
		}
		for k := j + 1; k < n-1; k++ {
			if nums[j] > nums[k] {
				f[j][k] = cnt
			} else {
				cnt--
			}
		}
	}
	ans := 0
	for k := 2; k < n-1; k++ {
		cnt := 0
		for i := 0; i < k; i++ {
			if nums[i] < nums[k] {
				cnt++
			}
		}
		for j := k - 1; j > 0; j-- {
			if nums[j] > nums[k] {
				g[j][k] = cnt
				ans += f[j][k] * g[j][k]
			} else {
				cnt--
			}
		}
	}
	return int64(ans)
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个长度为 <code>n</code>&nbsp;下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>nums</code>&nbsp;，它包含&nbsp;<code>1</code>&nbsp;到&nbsp;<code>n</code>&nbsp;的所有数字，请你返回上升四元组的数目。</p>

<p>如果一个四元组&nbsp;<code>(i, j, k, l)</code>&nbsp;满足以下条件，我们称它是上升的：</p>

<ul>
	<li><code>0 &lt;= i &lt; j &lt; k &lt; l &lt; n</code>&nbsp;且</li>
	<li><code>nums[i] &lt; nums[k] &lt; nums[j] &lt; nums[l]</code>&nbsp;。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [1,3,2,4,5]
<b>输出：</b>2
<b>解释：</b>
- 当 i = 0 ，j = 1 ，k = 2 且 l = 3 时，有 nums[i] &lt; nums[k] &lt; nums[j] &lt; nums[l] 。
- 当 i = 0 ，j = 1 ，k = 2 且 l = 4 时，有 nums[i] &lt; nums[k] &lt; nums[j] &lt; nums[l] 。
没有其他的四元组，所以我们返回 2 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [1,2,3,4]
<b>输出：</b>0
<b>解释：</b>只存在一个四元组 i = 0 ，j = 1 ，k = 2 ，l = 3 ，但是 nums[j] &lt; nums[k] ，所以我们返回 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>4 &lt;= nums.length &lt;= 4000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= nums.length</code></li>
	<li><code>nums</code>&nbsp;中所有数字 <strong>互不相同</strong>&nbsp;，<code>nums</code>&nbsp;是一个排列。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举 + 预处理

我们可以枚举四元组中的 $j$ 和 $k$，那么问题转化为，对于当前的 $j$ 和 $k$：

-   统计有多少个 $l$ 满足 $l \gt k$ 且 $nums[l] \gt nums[j]$；
-   统计有多少个 $i$ 满足 $i \lt j$ 且 $nums[i] \lt nums[k]$。

我们可以使用两个二维数组 $f$ 和 $g$ 分别记录这两个信息。其中 $f[j][k]$ 表示有多少个 $l$ 满足 $l \gt k$ 且 $nums[l] \gt nums[j]$，而 $g[j][k]$ 表示有多少个 $i$ 满足 $i \lt j$ 且 $nums[i] \lt nums[k]$。

那么答案就是所有的 $f[j][k] \times g[j][k]$ 的和。

时间复杂度为 $O(n^2)$，空间复杂度为 $O(n^2)$。其中 $n$ 是数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countQuadruplets(self, nums: List[int]) -> int:
        n = len(nums)
        f = [[0] * n for _ in range(n)]
        g = [[0] * n for _ in range(n)]
        for j in range(1, n - 2):
            cnt = sum(nums[l] > nums[j] for l in range(j + 1, n))
            for k in range(j + 1, n - 1):
                if nums[j] > nums[k]:
                    f[j][k] = cnt
                else:
                    cnt -= 1
        for k in range(2, n - 1):
            cnt = sum(nums[i] < nums[k] for i in range(k))
            for j in range(k - 1, 0, -1):
                if nums[j] > nums[k]:
                    g[j][k] = cnt
                else:
                    cnt -= 1
        return sum(
            f[j][k] * g[j][k] for j in range(1, n - 2) for k in range(j + 1, n - 1)
        )
```

#### Java

```java
class Solution {
    public long countQuadruplets(int[] nums) {
        int n = nums.length;
        int[][] f = new int[n][n];
        int[][] g = new int[n][n];
        for (int j = 1; j < n - 2; ++j) {
            int cnt = 0;
            for (int l = j + 1; l < n; ++l) {
                if (nums[l] > nums[j]) {
                    ++cnt;
                }
            }
            for (int k = j + 1; k < n - 1; ++k) {
                if (nums[j] > nums[k]) {
                    f[j][k] = cnt;
                } else {
                    --cnt;
                }
            }
        }
        long ans = 0;
        for (int k = 2; k < n - 1; ++k) {
            int cnt = 0;
            for (int i = 0; i < k; ++i) {
                if (nums[i] < nums[k]) {
                    ++cnt;
                }
            }
            for (int j = k - 1; j > 0; --j) {
                if (nums[j] > nums[k]) {
                    g[j][k] = cnt;
                    ans += (long) f[j][k] * g[j][k];
                } else {
                    --cnt;
                }
            }
        }
        return ans;
    }
}
```

#### C++

```cpp
const int N = 4001;
int f[N][N];
int g[N][N];

class Solution {
public:
    long long countQuadruplets(vector<int>& nums) {
        int n = nums.size();
        memset(f, 0, sizeof f);
        memset(g, 0, sizeof g);
        for (int j = 1; j < n - 2; ++j) {
            int cnt = 0;
            for (int l = j + 1; l < n; ++l) {
                if (nums[l] > nums[j]) {
                    ++cnt;
                }
            }
            for (int k = j + 1; k < n - 1; ++k) {
                if (nums[j] > nums[k]) {
                    f[j][k] = cnt;
                } else {
                    --cnt;
                }
            }
        }
        long long ans = 0;
        for (int k = 2; k < n - 1; ++k) {
            int cnt = 0;
            for (int i = 0; i < k; ++i) {
                if (nums[i] < nums[k]) {
                    ++cnt;
                }
            }
            for (int j = k - 1; j > 0; --j) {
                if (nums[j] > nums[k]) {
                    g[j][k] = cnt;
                    ans += 1ll * f[j][k] * g[j][k];
                } else {
                    --cnt;
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func countQuadruplets(nums []int) int64 {
	n := len(nums)
	f := make([][]int, n)
	g := make([][]int, n)
	for i := range f {
		f[i] = make([]int, n)
		g[i] = make([]int, n)
	}
	for j := 1; j < n-2; j++ {
		cnt := 0
		for l := j + 1; l < n; l++ {
			if nums[l] > nums[j] {
				cnt++
			}
		}
		for k := j + 1; k < n-1; k++ {
			if nums[j] > nums[k] {
				f[j][k] = cnt
			} else {
				cnt--
			}
		}
	}
	ans := 0
	for k := 2; k < n-1; k++ {
		cnt := 0
		for i := 0; i < k; i++ {
			if nums[i] < nums[k] {
				cnt++
			}
		}
		for j := k - 1; j > 0; j-- {
			if nums[j] > nums[k] {
				g[j][k] = cnt
				ans += f[j][k] * g[j][k]
			} else {
				cnt--
			}
		}
	}
	return int64(ans)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2553. 分割数组中数字的数位](https://leetcode.cn/problems/separate-the-digits-in-an-array){#2553}

{{< tabs "2553" >}}

{{% tab "python" %}}
```python
class Solution:
    def separateDigits(self, nums: List[int]) -> List[int]:
        ans = []
        for x in nums:
            t = []
            while x:
                t.append(x % 10)
                x //= 10
            ans.extend(t[::-1])
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] separateDigits(int[] nums) {
        List<Integer> res = new ArrayList<>();
        for (int x : nums) {
            List<Integer> t = new ArrayList<>();
            for (; x > 0; x /= 10) {
                t.add(x % 10);
            }
            Collections.reverse(t);
            res.addAll(t);
        }
        int[] ans = new int[res.size()];
        for (int i = 0; i < ans.length; ++i) {
            ans[i] = res.get(i);
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
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for (int x : nums) {
            vector<int> t;
            for (; x; x /= 10) {
                t.push_back(x % 10);
            }
            while (t.size()) {
                ans.push_back(t.back());
                t.pop_back();
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func separateDigits(nums []int) (ans []int) {
	for _, x := range nums {
		t := []int{}
		for ; x > 0; x /= 10 {
			t = append(t, x%10)
		}
		for i, j := 0, len(t)-1; i < j; i, j = i+1, j-1 {
			t[i], t[j] = t[j], t[i]
		}
		ans = append(ans, t...)
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function separateDigits(nums: number[]): number[] {
    const ans: number[] = [];
    for (let num of nums) {
        const t: number[] = [];
        while (num) {
            t.push(num % 10);
            num = Math.floor(num / 10);
        }
        ans.push(...t.reverse());
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn separate_digits(nums: Vec<i32>) -> Vec<i32> {
        let mut ans = vec![];

        for n in nums {
            let mut t = vec![];
            let mut x = n;

            while x != 0 {
                t.push(x % 10);
                x /= 10;
            }

            for i in (0..t.len()).rev() {
                ans.push(t[i]);
            }
        }

        ans
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* separateDigits(int* nums, int numsSize, int* returnSize) {
    int n = 0;
    for (int i = 0; i < numsSize; i++) {
        int t = nums[i];
        while (t != 0) {
            t /= 10;
            n++;
        }
    }
    int* ans = malloc(sizeof(int) * n);
    for (int i = numsSize - 1, j = n - 1; i >= 0; i--) {
        int t = nums[i];
        while (t != 0) {
            ans[j--] = t % 10;
            t /= 10;
        }
    }
    *returnSize = n;
    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个正整数数组&nbsp;<code>nums</code>&nbsp;，请你返回一个数组<em>&nbsp;</em><code>answer</code> ，你需要将&nbsp;<code>nums</code>&nbsp;中每个整数进行数位分割后，按照&nbsp;<code>nums</code>&nbsp;中出现的&nbsp;<strong>相同顺序</strong>&nbsp;放入答案数组中。</p>

<p>对一个整数进行数位分割，指的是将整数各个数位按原本出现的顺序排列成数组。</p>

<ul>
	<li>比方说，整数&nbsp;<code>10921</code>&nbsp;，分割它的各个数位得到&nbsp;<code>[1,0,9,2,1]</code>&nbsp;。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [13,25,83,77]
<b>输出：</b>[1,3,2,5,8,3,7,7]
<b>解释：</b>
- 分割 13 得到 [1,3] 。
- 分割 25 得到 [2,5] 。
- 分割 83 得到 [8,3] 。
- 分割 77 得到 [7,7] 。
answer = [1,3,2,5,8,3,7,7] 。answer 中的数字分割结果按照原数字在数组中的相同顺序排列。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [7,1,3,9]
<b>输出：</b>[7,1,3,9]
<b>解释：</b>nums 中每个整数的分割是它自己。
answer = [7,1,3,9] 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

将数组中的每个数字进行数位分割，然后将分割后的数字依次放入答案数组中。

时间复杂度 $O(n \times \log_{10} M)$，空间复杂度 $O(n \times \log_{10} M)$，其中 $n$ 为数组 $nums$ 的长度，而 $M$ 为数组 $nums$ 中的最大值。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def separateDigits(self, nums: List[int]) -> List[int]:
        ans = []
        for x in nums:
            t = []
            while x:
                t.append(x % 10)
                x //= 10
            ans.extend(t[::-1])
        return ans
```

#### Java

```java
class Solution {
    public int[] separateDigits(int[] nums) {
        List<Integer> res = new ArrayList<>();
        for (int x : nums) {
            List<Integer> t = new ArrayList<>();
            for (; x > 0; x /= 10) {
                t.add(x % 10);
            }
            Collections.reverse(t);
            res.addAll(t);
        }
        int[] ans = new int[res.size()];
        for (int i = 0; i < ans.length; ++i) {
            ans[i] = res.get(i);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for (int x : nums) {
            vector<int> t;
            for (; x; x /= 10) {
                t.push_back(x % 10);
            }
            while (t.size()) {
                ans.push_back(t.back());
                t.pop_back();
            }
        }
        return ans;
    }
};
```

#### Go

```go
func separateDigits(nums []int) (ans []int) {
	for _, x := range nums {
		t := []int{}
		for ; x > 0; x /= 10 {
			t = append(t, x%10)
		}
		for i, j := 0, len(t)-1; i < j; i, j = i+1, j-1 {
			t[i], t[j] = t[j], t[i]
		}
		ans = append(ans, t...)
	}
	return
}
```

#### TypeScript

```ts
function separateDigits(nums: number[]): number[] {
    const ans: number[] = [];
    for (let num of nums) {
        const t: number[] = [];
        while (num) {
            t.push(num % 10);
            num = Math.floor(num / 10);
        }
        ans.push(...t.reverse());
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn separate_digits(nums: Vec<i32>) -> Vec<i32> {
        let mut ans = Vec::new();
        for &num in nums.iter() {
            let mut num = num;
            let mut t = Vec::new();
            while num != 0 {
                t.push(num % 10);
                num /= 10;
            }
            t.into_iter().rev().for_each(|v| ans.push(v));
        }
        ans
    }
}
```

#### C

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* separateDigits(int* nums, int numsSize, int* returnSize) {
    int n = 0;
    for (int i = 0; i < numsSize; i++) {
        int t = nums[i];
        while (t != 0) {
            t /= 10;
            n++;
        }
    }
    int* ans = malloc(sizeof(int) * n);
    for (int i = numsSize - 1, j = n - 1; i >= 0; i--) {
        int t = nums[i];
        while (t != 0) {
            ans[j--] = t % 10;
            t /= 10;
        }
    }
    *returnSize = n;
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### Rust

```rust
impl Solution {
    pub fn separate_digits(nums: Vec<i32>) -> Vec<i32> {
        let mut ans = vec![];

        for n in nums {
            let mut t = vec![];
            let mut x = n;

            while x != 0 {
                t.push(x % 10);
                x /= 10;
            }

            for i in (0..t.len()).rev() {
                ans.push(t[i]);
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

# [2554. 从一个范围内选择最多整数 I](https://leetcode.cn/problems/maximum-number-of-integers-to-choose-from-a-range-i){#2554}

{{< tabs "2554" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxCount(self, banned: List[int], n: int, maxSum: int) -> int:
        banned.extend([0, n + 1])
        ban = sorted(x for x in set(banned) if x < n + 2)
        ans = 0
        for i, j in pairwise(ban):
            left, right = 0, j - i - 1
            while left < right:
                mid = (left + right + 1) >> 1
                if (i + 1 + i + mid) * mid // 2 <= maxSum:
                    left = mid
                else:
                    right = mid - 1
            ans += left
            maxSum -= (i + 1 + i + left) * left // 2
            if maxSum <= 0:
                break
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxCount(int[] banned, int n, int maxSum) {
        Set<Integer> black = new HashSet<>();
        black.add(0);
        black.add(n + 1);
        for (int x : banned) {
            if (x < n + 2) {
                black.add(x);
            }
        }
        List<Integer> ban = new ArrayList<>(black);
        Collections.sort(ban);
        int ans = 0;
        for (int k = 1; k < ban.size(); ++k) {
            int i = ban.get(k - 1), j = ban.get(k);
            int left = 0, right = j - i - 1;
            while (left < right) {
                int mid = (left + right + 1) >>> 1;
                if ((i + 1 + i + mid) * 1L * mid / 2 <= maxSum) {
                    left = mid;
                } else {
                    right = mid - 1;
                }
            }
            ans += left;
            maxSum -= (i + 1 + i + left) * 1L * left / 2;
            if (maxSum <= 0) {
                break;
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
    int maxCount(vector<int>& banned, int n, int maxSum) {
        banned.push_back(0);
        banned.push_back(n + 1);
        sort(banned.begin(), banned.end());
        banned.erase(unique(banned.begin(), banned.end()), banned.end());
        banned.erase(remove_if(banned.begin(), banned.end(), [&](int x) { return x > n + 1; }), banned.end());
        int ans = 0;
        for (int k = 1; k < banned.size(); ++k) {
            int i = banned[k - 1], j = banned[k];
            int left = 0, right = j - i - 1;
            while (left < right) {
                int mid = left + ((right - left + 1) / 2);
                if ((i + 1 + i + mid) * 1LL * mid / 2 <= maxSum) {
                    left = mid;
                } else {
                    right = mid - 1;
                }
            }
            ans += left;
            maxSum -= (i + 1 + i + left) * 1LL * left / 2;
            if (maxSum <= 0) {
                break;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxCount(banned []int, n int, maxSum int) (ans int) {
	banned = append(banned, []int{0, n + 1}...)
	sort.Ints(banned)
	ban := []int{}
	for i, x := range banned {
		if (i > 0 && x == banned[i-1]) || x > n+1 {
			continue
		}
		ban = append(ban, x)
	}
	for k := 1; k < len(ban); k++ {
		i, j := ban[k-1], ban[k]
		left, right := 0, j-i-1
		for left < right {
			mid := (left + right + 1) >> 1
			if (i+1+i+mid)*mid/2 <= maxSum {
				left = mid
			} else {
				right = mid - 1
			}
		}
		ans += left
		maxSum -= (i + 1 + i + left) * left / 2
		if maxSum <= 0 {
			break
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxCount(banned: number[], n: number, maxSum: number): number {
    const set = new Set(banned);
    let sum = 0;
    let ans = 0;
    for (let i = 1; i <= n; i++) {
        if (i + sum > maxSum) {
            break;
        }
        if (set.has(i)) {
            continue;
        }
        sum += i;
        ans++;
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashSet;
impl Solution {
    pub fn max_count(banned: Vec<i32>, n: i32, max_sum: i32) -> i32 {
        let mut set = banned.into_iter().collect::<HashSet<i32>>();
        let mut sum = 0;
        let mut ans = 0;
        for i in 1..=n {
            if sum + i > max_sum {
                break;
            }
            if set.contains(&i) {
                continue;
            }
            sum += i;
            ans += 1;
        }
        ans
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
int cmp(const void* a, const void* b) {
    return *(int*) a - *(int*) b;
}

int maxCount(int* banned, int bannedSize, int n, int maxSum) {
    qsort(banned, bannedSize, sizeof(int), cmp);
    int sum = 0;
    int ans = 0;
    for (int i = 1, j = 0; i <= n; i++) {
        if (sum + i > maxSum) {
            break;
        }
        if (j < bannedSize && i == banned[j]) {
            while (j < bannedSize && i == banned[j]) {
                j++;
            }
        } else {
            sum += i;
            ans++;
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

<p>给你一个整数数组&nbsp;<code>banned</code>&nbsp;和两个整数&nbsp;<code>n</code> 和&nbsp;<code>maxSum</code>&nbsp;。你需要按照以下规则选择一些整数：</p>

<ul>
	<li>被选择整数的范围是&nbsp;<code>[1, n]</code>&nbsp;。</li>
	<li>每个整数 <strong>至多</strong>&nbsp;选择 <strong>一次</strong>&nbsp;。</li>
	<li>被选择整数不能在数组&nbsp;<code>banned</code>&nbsp;中。</li>
	<li>被选择整数的和不超过&nbsp;<code>maxSum</code>&nbsp;。</li>
</ul>

<p>请你返回按照上述规则 <strong>最多</strong>&nbsp;可以选择的整数数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>banned = [1,6,5], n = 5, maxSum = 6
<b>输出：</b>2
<b>解释：</b>你可以选择整数 2 和 4 。
2 和 4 在范围 [1, 5] 内，且它们都不在 banned 中，它们的和是 6 ，没有超过 maxSum 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>banned = [1,2,3,4,5,6,7], n = 8, maxSum = 1
<b>输出：</b>0
<b>解释：</b>按照上述规则无法选择任何整数。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>banned = [11], n = 7, maxSum = 50
<b>输出：</b>7
<b>解释：</b>你可以选择整数 1, 2, 3, 4, 5, 6 和 7 。
它们都在范围 [1, 7] 中，且都没出现在 banned 中，它们的和是 28 ，没有超过 maxSum 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= banned.length &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= banned[i], n &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= maxSum &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 枚举

我们用变量 $s$ 表示当前已经选择的整数的和，用变量 $ans$ 表示当前已经选择的整数的个数。将数组 `banned` 转换为哈希表，方便判断某个整数是否不可选。

接下来，我们从 $1$ 开始枚举整数 $i$，如果 $s + i \leq maxSum$ 且 $i$ 不在 `banned` 中，那么我们就可以选择整数 $i$，并将 $s$ 和 $ans$ 分别加上 $i$ 和 $1$。

最终，我们返回 $ans$ 即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为给定的整数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxCount(self, banned: List[int], n: int, maxSum: int) -> int:
        ans = s = 0
        ban = set(banned)
        for i in range(1, n + 1):
            if s + i > maxSum:
                break
            if i not in ban:
                ans += 1
                s += i
        return ans
```

#### Java

```java
class Solution {
    public int maxCount(int[] banned, int n, int maxSum) {
        Set<Integer> ban = new HashSet<>(banned.length);
        for (int x : banned) {
            ban.add(x);
        }
        int ans = 0, s = 0;
        for (int i = 1; i <= n && s + i <= maxSum; ++i) {
            if (!ban.contains(i)) {
                ++ans;
                s += i;
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
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> ban(banned.begin(), banned.end());
        int ans = 0, s = 0;
        for (int i = 1; i <= n && s + i <= maxSum; ++i) {
            if (!ban.count(i)) {
                ++ans;
                s += i;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func maxCount(banned []int, n int, maxSum int) (ans int) {
	ban := map[int]bool{}
	for _, x := range banned {
		ban[x] = true
	}
	s := 0
	for i := 1; i <= n && s+i <= maxSum; i++ {
		if !ban[i] {
			ans++
			s += i
		}
	}
	return
}
```

#### TypeScript

```ts
function maxCount(banned: number[], n: number, maxSum: number): number {
    const set = new Set(banned);
    let sum = 0;
    let ans = 0;
    for (let i = 1; i <= n; i++) {
        if (i + sum > maxSum) {
            break;
        }
        if (set.has(i)) {
            continue;
        }
        sum += i;
        ans++;
    }
    return ans;
}
```

#### Rust

```rust
use std::collections::HashSet;
impl Solution {
    pub fn max_count(banned: Vec<i32>, n: i32, max_sum: i32) -> i32 {
        let mut set = banned.into_iter().collect::<HashSet<i32>>();
        let mut sum = 0;
        let mut ans = 0;
        for i in 1..=n {
            if sum + i > max_sum {
                break;
            }
            if set.contains(&i) {
                continue;
            }
            sum += i;
            ans += 1;
        }
        ans
    }
}
```

#### C

```c
int cmp(const void* a, const void* b) {
    return *(int*) a - *(int*) b;
}

int maxCount(int* banned, int bannedSize, int n, int maxSum) {
    qsort(banned, bannedSize, sizeof(int), cmp);
    int sum = 0;
    int ans = 0;
    for (int i = 1, j = 0; i <= n; i++) {
        if (sum + i > maxSum) {
            break;
        }
        if (j < bannedSize && i == banned[j]) {
            while (j < bannedSize && i == banned[j]) {
                j++;
            }
        } else {
            sum += i;
            ans++;
        }
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：贪心 + 二分查找

如果 $n$ 很大，那么方法一中的枚举会超时。

我们可以在数组 `banned` 中加入 $0$ 和 $n + 1$，并将数组 `banned` 去重且移除大于 $n+1$ 的元素，然后进行排序。

接下来，我们枚举数组 `banned` 中的每两个相邻元素 $i$ 和 $j$，那么可选的整数范围就是 $[i + 1, j - 1]$。二分枚举我们在此区间内能够选择的元素个数，找到最大的可选元素个数，然后将其加到 $ans$ 中。同时在 `maxSum` 中减去这些元素的和。如果 `maxSum` 小于 $0$，那么我们跳出循环。返回答案即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 `banned` 的长度。

相似题目：

-   [2557. 从一个范围内选择最多整数 II](https://github.com/doocs/leetcode/blob/main/solution/2500-2599/2557.Maximum%20Number%20of%20Integers%20to%20Choose%20From%20a%20Range%20II/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxCount(self, banned: List[int], n: int, maxSum: int) -> int:
        banned.extend([0, n + 1])
        ban = sorted(x for x in set(banned) if x < n + 2)
        ans = 0
        for i, j in pairwise(ban):
            left, right = 0, j - i - 1
            while left < right:
                mid = (left + right + 1) >> 1
                if (i + 1 + i + mid) * mid // 2 <= maxSum:
                    left = mid
                else:
                    right = mid - 1
            ans += left
            maxSum -= (i + 1 + i + left) * left // 2
            if maxSum <= 0:
                break
        return ans
```

#### Java

```java
class Solution {
    public int maxCount(int[] banned, int n, int maxSum) {
        Set<Integer> black = new HashSet<>();
        black.add(0);
        black.add(n + 1);
        for (int x : banned) {
            if (x < n + 2) {
                black.add(x);
            }
        }
        List<Integer> ban = new ArrayList<>(black);
        Collections.sort(ban);
        int ans = 0;
        for (int k = 1; k < ban.size(); ++k) {
            int i = ban.get(k - 1), j = ban.get(k);
            int left = 0, right = j - i - 1;
            while (left < right) {
                int mid = (left + right + 1) >>> 1;
                if ((i + 1 + i + mid) * 1L * mid / 2 <= maxSum) {
                    left = mid;
                } else {
                    right = mid - 1;
                }
            }
            ans += left;
            maxSum -= (i + 1 + i + left) * 1L * left / 2;
            if (maxSum <= 0) {
                break;
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
    int maxCount(vector<int>& banned, int n, int maxSum) {
        banned.push_back(0);
        banned.push_back(n + 1);
        sort(banned.begin(), banned.end());
        banned.erase(unique(banned.begin(), banned.end()), banned.end());
        banned.erase(remove_if(banned.begin(), banned.end(), [&](int x) { return x > n + 1; }), banned.end());
        int ans = 0;
        for (int k = 1; k < banned.size(); ++k) {
            int i = banned[k - 1], j = banned[k];
            int left = 0, right = j - i - 1;
            while (left < right) {
                int mid = left + ((right - left + 1) / 2);
                if ((i + 1 + i + mid) * 1LL * mid / 2 <= maxSum) {
                    left = mid;
                } else {
                    right = mid - 1;
                }
            }
            ans += left;
            maxSum -= (i + 1 + i + left) * 1LL * left / 2;
            if (maxSum <= 0) {
                break;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func maxCount(banned []int, n int, maxSum int) (ans int) {
	banned = append(banned, []int{0, n + 1}...)
	sort.Ints(banned)
	ban := []int{}
	for i, x := range banned {
		if (i > 0 && x == banned[i-1]) || x > n+1 {
			continue
		}
		ban = append(ban, x)
	}
	for k := 1; k < len(ban); k++ {
		i, j := ban[k-1], ban[k]
		left, right := 0, j-i-1
		for left < right {
			mid := (left + right + 1) >> 1
			if (i+1+i+mid)*mid/2 <= maxSum {
				left = mid
			} else {
				right = mid - 1
			}
		}
		ans += left
		maxSum -= (i + 1 + i + left) * left / 2
		if maxSum <= 0 {
			break
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

# [2555. 两个线段获得的最多奖品](https://leetcode.cn/problems/maximize-win-from-two-segments){#2555}

{{< tabs "2555" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximizeWin(self, prizePositions: List[int], k: int) -> int:
        n = len(prizePositions)
        f = [0] * (n + 1)
        ans = 0
        for i, x in enumerate(prizePositions, 1):
            j = bisect_left(prizePositions, x - k)
            ans = max(ans, f[j] + i - j)
            f[i] = max(f[i - 1], i - j)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maximizeWin(int[] prizePositions, int k) {
        int n = prizePositions.length;
        int[] f = new int[n + 1];
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            int x = prizePositions[i - 1];
            int j = search(prizePositions, x - k);
            ans = Math.max(ans, f[j] + i - j);
            f[i] = Math.max(f[i - 1], i - j);
        }
        return ans;
    }

    private int search(int[] nums, int x) {
        int left = 0, right = nums.length;
        while (left < right) {
            int mid = (left + right) >> 1;
            if (nums[mid] >= x) {
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
    int maximizeWin(vector<int>& prizePositions, int k) {
        int n = prizePositions.size();
        vector<int> f(n + 1);
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            int x = prizePositions[i - 1];
            int j = lower_bound(prizePositions.begin(), prizePositions.end(), x - k) - prizePositions.begin();
            ans = max(ans, f[j] + i - j);
            f[i] = max(f[i - 1], i - j);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximizeWin(prizePositions []int, k int) (ans int) {
	n := len(prizePositions)
	f := make([]int, n+1)
	for i, x := range prizePositions {
		j := sort.Search(n, func(h int) bool { return prizePositions[h] >= x-k })
		ans = max(ans, f[j]+i-j+1)
		f[i+1] = max(f[i], i-j+1)
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximizeWin(prizePositions: number[], k: number): number {
    const n = prizePositions.length;
    const f: number[] = Array(n + 1).fill(0);
    let ans = 0;
    const search = (x: number): number => {
        let left = 0;
        let right = n;
        while (left < right) {
            const mid = (left + right) >> 1;
            if (prizePositions[mid] >= x) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    };
    for (let i = 1; i <= n; ++i) {
        const x = prizePositions[i - 1];
        const j = search(x - k);
        ans = Math.max(ans, f[j] + i - j);
        f[i] = Math.max(f[i - 1], i - j);
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

<p>在 <strong>X轴</strong>&nbsp;上有一些奖品。给你一个整数数组&nbsp;<code>prizePositions</code>&nbsp;，它按照 <strong>非递减</strong>&nbsp;顺序排列，其中&nbsp;<code>prizePositions[i]</code>&nbsp;是第&nbsp;<code>i</code>&nbsp;件奖品的位置。数轴上一个位置可能会有多件奖品。再给你一个整数&nbsp;<code>k</code>&nbsp;。</p>

<p>你可以同时选择两个端点为整数的线段。每个线段的长度都必须是 <code>k</code>&nbsp;。你可以获得位置在任一线段上的所有奖品（包括线段的两个端点）。注意，两个线段可能会有相交。</p>

<ul>
	<li>比方说&nbsp;<code>k = 2</code>&nbsp;，你可以选择线段&nbsp;<code>[1, 3]</code> 和&nbsp;<code>[2, 4]</code>&nbsp;，你可以获得满足&nbsp;<code>1 &lt;= prizePositions[i] &lt;= 3</code> 或者&nbsp;<code>2 &lt;= prizePositions[i] &lt;= 4</code>&nbsp;的所有奖品 i 。</li>
</ul>

<p>请你返回在选择两个最优线段的前提下，可以获得的 <strong>最多</strong>&nbsp;奖品数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>prizePositions = [1,1,2,2,3,3,5], k = 2
<b>输出：</b>7
<b>解释：</b>这个例子中，你可以选择线段 [1, 3] 和 [3, 5] ，获得 7 个奖品。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>prizePositions = [1,2,3,4], k = 0
<b>输出：</b>2
<b>解释：</b>这个例子中，一个选择是选择线段 <code>[3, 3]</code> 和 <code>[4, 4]</code> ，获得 2 个奖品。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= prizePositions.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= prizePositions[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= k &lt;= 10<sup>9</sup> </code></li>
	<li><code>prizePositions</code>&nbsp;有序非递减。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划 + 二分查找

我们定义 $f[i]$ 表示在前 $i$ 个奖品中，选择一个长度为 $k$ 的线段，可以获得的最多奖品数目。初始时 $f[0] = 0$。定义答案变量 $ans = 0$。

接下来，我们枚举每个奖品的位置 $x$，通过二分查找，找到最左边的奖品下标 $j$，使得 $prizePositions[j] \geq x - k$。此时，我们更新答案 $ans = \max(ans, f[j] + i - j)$，并更新 $f[i] = \max(f[i - 1], i - j)$。

最后，返回 $ans$ 即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为奖品数目。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximizeWin(self, prizePositions: List[int], k: int) -> int:
        n = len(prizePositions)
        f = [0] * (n + 1)
        ans = 0
        for i, x in enumerate(prizePositions, 1):
            j = bisect_left(prizePositions, x - k)
            ans = max(ans, f[j] + i - j)
            f[i] = max(f[i - 1], i - j)
        return ans
```

#### Java

```java
class Solution {
    public int maximizeWin(int[] prizePositions, int k) {
        int n = prizePositions.length;
        int[] f = new int[n + 1];
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            int x = prizePositions[i - 1];
            int j = search(prizePositions, x - k);
            ans = Math.max(ans, f[j] + i - j);
            f[i] = Math.max(f[i - 1], i - j);
        }
        return ans;
    }

    private int search(int[] nums, int x) {
        int left = 0, right = nums.length;
        while (left < right) {
            int mid = (left + right) >> 1;
            if (nums[mid] >= x) {
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
    int maximizeWin(vector<int>& prizePositions, int k) {
        int n = prizePositions.size();
        vector<int> f(n + 1);
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            int x = prizePositions[i - 1];
            int j = lower_bound(prizePositions.begin(), prizePositions.end(), x - k) - prizePositions.begin();
            ans = max(ans, f[j] + i - j);
            f[i] = max(f[i - 1], i - j);
        }
        return ans;
    }
};
```

#### Go

```go
func maximizeWin(prizePositions []int, k int) (ans int) {
	n := len(prizePositions)
	f := make([]int, n+1)
	for i, x := range prizePositions {
		j := sort.Search(n, func(h int) bool { return prizePositions[h] >= x-k })
		ans = max(ans, f[j]+i-j+1)
		f[i+1] = max(f[i], i-j+1)
	}
	return
}
```

#### TypeScript

```ts
function maximizeWin(prizePositions: number[], k: number): number {
    const n = prizePositions.length;
    const f: number[] = Array(n + 1).fill(0);
    let ans = 0;
    const search = (x: number): number => {
        let left = 0;
        let right = n;
        while (left < right) {
            const mid = (left + right) >> 1;
            if (prizePositions[mid] >= x) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    };
    for (let i = 1; i <= n; ++i) {
        const x = prizePositions[i - 1];
        const j = search(x - k);
        ans = Math.max(ans, f[j] + i - j);
        f[i] = Math.max(f[i - 1], i - j);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2556. 二进制矩阵中翻转最多一次使路径不连通](https://leetcode.cn/problems/disconnect-path-in-a-binary-matrix-by-at-most-one-flip){#2556}

{{< tabs "2556" >}}

{{% tab "python" %}}
```python
class Solution:
    def isPossibleToCutPath(self, grid: List[List[int]]) -> bool:
        def dfs(i, j):
            if i >= m or j >= n or grid[i][j] == 0:
                return False
            grid[i][j] = 0
            if i == m - 1 and j == n - 1:
                return True
            return dfs(i + 1, j) or dfs(i, j + 1)

        m, n = len(grid), len(grid[0])
        a = dfs(0, 0)
        grid[0][0] = grid[-1][-1] = 1
        b = dfs(0, 0)
        return not (a and b)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[][] grid;
    private int m;
    private int n;

    public boolean isPossibleToCutPath(int[][] grid) {
        this.grid = grid;
        m = grid.length;
        n = grid[0].length;
        boolean a = dfs(0, 0);
        grid[0][0] = 1;
        grid[m - 1][n - 1] = 1;
        boolean b = dfs(0, 0);
        return !(a && b);
    }

    private boolean dfs(int i, int j) {
        if (i >= m || j >= n || grid[i][j] == 0) {
            return false;
        }
        if (i == m - 1 && j == n - 1) {
            return true;
        }
        grid[i][j] = 0;
        return dfs(i + 1, j) || dfs(i, j + 1);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        function<bool(int, int)> dfs = [&](int i, int j) -> bool {
            if (i >= m || j >= n || grid[i][j] == 0) {
                return false;
            }
            if (i == m - 1 && j == n - 1) {
                return true;
            }
            grid[i][j] = 0;
            return dfs(i + 1, j) || dfs(i, j + 1);
        };
        bool a = dfs(0, 0);
        grid[0][0] = grid[m - 1][n - 1] = 1;
        bool b = dfs(0, 0);
        return !(a && b);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func isPossibleToCutPath(grid [][]int) bool {
	m, n := len(grid), len(grid[0])
	var dfs func(i, j int) bool
	dfs = func(i, j int) bool {
		if i >= m || j >= n || grid[i][j] == 0 {
			return false
		}
		if i == m-1 && j == n-1 {
			return true
		}
		grid[i][j] = 0
		return dfs(i+1, j) || dfs(i, j+1)
	}
	a := dfs(0, 0)
	grid[0][0], grid[m-1][n-1] = 1, 1
	b := dfs(0, 0)
	return !(a && b)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function isPossibleToCutPath(grid: number[][]): boolean {
    const m = grid.length;
    const n = grid[0].length;

    const dfs = (i: number, j: number): boolean => {
        if (i >= m || j >= n || grid[i][j] !== 1) {
            return false;
        }
        grid[i][j] = 0;
        if (i === m - 1 && j === n - 1) {
            return true;
        }
        return dfs(i + 1, j) || dfs(i, j + 1);
    };
    const a = dfs(0, 0);
    grid[0][0] = 1;
    grid[m - 1][n - 1] = 1;
    const b = dfs(0, 0);
    return !(a && b);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的&nbsp;<code>m x n</code>&nbsp;<strong>二进制</strong> 矩阵&nbsp;<code>grid</code>&nbsp;。你可以从一个格子&nbsp;<code>(row, col)</code>&nbsp;移动到格子&nbsp;<code>(row + 1, col)</code>&nbsp;或者&nbsp;<code>(row, col + 1)</code>&nbsp;，前提是前往的格子值为 <code>1</code>&nbsp;。如果从&nbsp;<code>(0, 0)</code>&nbsp;到&nbsp;<code>(m - 1, n - 1)</code>&nbsp;没有任何路径，我们称该矩阵是&nbsp;<strong>不连通</strong>&nbsp;的。</p>

<p>你可以翻转 <strong>最多一个</strong>&nbsp;格子的值（也可以不翻转）。你 <strong>不能翻转</strong>&nbsp;格子&nbsp;<code>(0, 0)</code> 和&nbsp;<code>(m - 1, n - 1)</code>&nbsp;。</p>

<p>如果可以使矩阵不连通，请你返回&nbsp;<code>true</code>&nbsp;，否则返回<em>&nbsp;</em><code>false</code><em>&nbsp;</em>。</p>

<p><strong>注意</strong>&nbsp;，翻转一个格子的值，可以使它的值从&nbsp;<code>0</code>&nbsp;变&nbsp;<code>1</code>&nbsp;，或从&nbsp;<code>1</code>&nbsp;变&nbsp;<code>0</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2500-2599/2556.Disconnect%20Path%20in%20a%20Binary%20Matrix%20by%20at%20Most%20One%20Flip/images/yetgrid2drawio.png" style="width: 441px; height: 151px;" /></p>

<pre>
<b>输入：</b>grid = [[1,1,1],[1,0,0],[1,1,1]]
<strong>输出：</strong>true
<b>解释：</b>按照上图所示我们翻转蓝色格子里的值，翻转后从 (0, 0) 到 (2, 2) 没有路径。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2500-2599/2556.Disconnect%20Path%20in%20a%20Binary%20Matrix%20by%20at%20Most%20One%20Flip/images/yetgrid3drawio.png" /></p>

<pre>
<b>输入：</b>grid = [[1,1,1],[1,0,1],[1,1,1]]
<b>输出：</b>false
<b>解释：</b>无法翻转至多一个格子，使 (0, 0) 到 (2, 2) 没有路径。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 1000</code></li>
	<li><code>1 &lt;= m * n &lt;= 10<sup>5</sup></code></li>
	<li><code>grid[0][0] == grid[m - 1][n - 1] == 1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：两次 DFS

我们先进行一次 DFS，判断从 $(0, 0)$ 到 $(m - 1, n - 1)$ 是否存在路径，记结果为 $a$。在 DFS 的过程中，我们将访问过的格子的值置为 $0$，以防止重复访问。

接下来，我们将 $(0, 0)$ 和 $(m - 1, n - 1)$ 的值置为 $1$，再进行一次 DFS，判断从 $(0, 0)$ 到 $(m - 1, n - 1)$ 是否存在路径，记结果为 $b$。在 DFS 的过程中，我们将访问过的格子的值置为 $0$，避免重复访问。

最后，如果 $a$ 和 $b$ 都为 `true`，则返回 `false`，否则返回 `true`。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别是矩阵的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def isPossibleToCutPath(self, grid: List[List[int]]) -> bool:
        def dfs(i, j):
            if i >= m or j >= n or grid[i][j] == 0:
                return False
            grid[i][j] = 0
            if i == m - 1 and j == n - 1:
                return True
            return dfs(i + 1, j) or dfs(i, j + 1)

        m, n = len(grid), len(grid[0])
        a = dfs(0, 0)
        grid[0][0] = grid[-1][-1] = 1
        b = dfs(0, 0)
        return not (a and b)
```

#### Java

```java
class Solution {
    private int[][] grid;
    private int m;
    private int n;

    public boolean isPossibleToCutPath(int[][] grid) {
        this.grid = grid;
        m = grid.length;
        n = grid[0].length;
        boolean a = dfs(0, 0);
        grid[0][0] = 1;
        grid[m - 1][n - 1] = 1;
        boolean b = dfs(0, 0);
        return !(a && b);
    }

    private boolean dfs(int i, int j) {
        if (i >= m || j >= n || grid[i][j] == 0) {
            return false;
        }
        if (i == m - 1 && j == n - 1) {
            return true;
        }
        grid[i][j] = 0;
        return dfs(i + 1, j) || dfs(i, j + 1);
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        function<bool(int, int)> dfs = [&](int i, int j) -> bool {
            if (i >= m || j >= n || grid[i][j] == 0) {
                return false;
            }
            if (i == m - 1 && j == n - 1) {
                return true;
            }
            grid[i][j] = 0;
            return dfs(i + 1, j) || dfs(i, j + 1);
        };
        bool a = dfs(0, 0);
        grid[0][0] = grid[m - 1][n - 1] = 1;
        bool b = dfs(0, 0);
        return !(a && b);
    }
};
```

#### Go

```go
func isPossibleToCutPath(grid [][]int) bool {
	m, n := len(grid), len(grid[0])
	var dfs func(i, j int) bool
	dfs = func(i, j int) bool {
		if i >= m || j >= n || grid[i][j] == 0 {
			return false
		}
		if i == m-1 && j == n-1 {
			return true
		}
		grid[i][j] = 0
		return dfs(i+1, j) || dfs(i, j+1)
	}
	a := dfs(0, 0)
	grid[0][0], grid[m-1][n-1] = 1, 1
	b := dfs(0, 0)
	return !(a && b)
}
```

#### TypeScript

```ts
function isPossibleToCutPath(grid: number[][]): boolean {
    const m = grid.length;
    const n = grid[0].length;

    const dfs = (i: number, j: number): boolean => {
        if (i >= m || j >= n || grid[i][j] !== 1) {
            return false;
        }
        grid[i][j] = 0;
        if (i === m - 1 && j === n - 1) {
            return true;
        }
        return dfs(i + 1, j) || dfs(i, j + 1);
    };
    const a = dfs(0, 0);
    grid[0][0] = 1;
    grid[m - 1][n - 1] = 1;
    const b = dfs(0, 0);
    return !(a && b);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2557. 从一个范围内选择最多整数 II 🔒](https://leetcode.cn/problems/maximum-number-of-integers-to-choose-from-a-range-ii){#2557}

{{< tabs "2557" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxCount(self, banned: List[int], n: int, maxSum: int) -> int:
        banned.extend([0, n + 1])
        ban = sorted(set(banned))
        ans = 0
        for i, j in pairwise(ban):
            left, right = 0, j - i - 1
            while left < right:
                mid = (left + right + 1) >> 1
                if (i + 1 + i + mid) * mid // 2 <= maxSum:
                    left = mid
                else:
                    right = mid - 1
            ans += left
            maxSum -= (i + 1 + i + left) * left // 2
            if maxSum <= 0:
                break
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxCount(int[] banned, int n, long maxSum) {
        Set<Integer> black = new HashSet<>();
        black.add(0);
        black.add(n + 1);
        for (int x : banned) {
            black.add(x);
        }
        List<Integer> ban = new ArrayList<>(black);
        Collections.sort(ban);
        int ans = 0;
        for (int k = 1; k < ban.size(); ++k) {
            int i = ban.get(k - 1), j = ban.get(k);
            int left = 0, right = j - i - 1;
            while (left < right) {
                int mid = (left + right + 1) >>> 1;
                if ((i + 1 + i + mid) * 1L * mid / 2 <= maxSum) {
                    left = mid;
                } else {
                    right = mid - 1;
                }
            }
            ans += left;
            maxSum -= (i + 1 + i + left) * 1L * left / 2;
            if (maxSum <= 0) {
                break;
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
    int maxCount(vector<int>& banned, int n, long long maxSum) {
        banned.push_back(0);
        banned.push_back(n + 1);
        sort(banned.begin(), banned.end());
        banned.erase(unique(banned.begin(), banned.end()), banned.end());
        int ans = 0;
        for (int k = 1; k < banned.size(); ++k) {
            int i = banned[k - 1], j = banned[k];
            int left = 0, right = j - i - 1;
            while (left < right) {
                int mid = left + ((right - left + 1) / 2);
                if ((i + 1 + i + mid) * 1LL * mid / 2 <= maxSum) {
                    left = mid;
                } else {
                    right = mid - 1;
                }
            }
            ans += left;
            maxSum -= (i + 1 + i + left) * 1LL * left / 2;
            if (maxSum <= 0) {
                break;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxCount(banned []int, n int, maxSum int64) (ans int) {
	banned = append(banned, []int{0, n + 1}...)
	sort.Ints(banned)
	ban := []int{}
	for i, x := range banned {
		if i > 0 && x == banned[i-1] {
			continue
		}
		ban = append(ban, x)
	}
	for k := 1; k < len(ban); k++ {
		i, j := ban[k-1], ban[k]
		left, right := 0, j-i-1
		for left < right {
			mid := (left + right + 1) >> 1
			if int64((i+1+i+mid)*mid/2) <= maxSum {
				left = mid
			} else {
				right = mid - 1
			}
		}
		ans += left
		maxSum -= int64((i + 1 + i + left) * left / 2)
		if maxSum <= 0 {
			break
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

<p>给你一个整数数组 <code>banned</code> 和两个整数 <code>n</code> 和 <code>maxSum</code>&nbsp;。你需要按照以下规则选择一些整数：</p>

<ul>
	<li>被选择整数的范围是 <code>[1, n]</code> 。</li>
	<li>每个整数 <strong>至多</strong> 选择 <strong>一次</strong> 。</li>
	<li>被选择整数不能在数组 <code>banned</code> 中。</li>
	<li>被选择整数的和不超过 <code>maxSum</code> 。</li>
</ul>

<p>请你返回按照上述规则 <strong>最多</strong> 可以选择的整数数目。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>banned = [1,4,6], n = 6, maxSum = 4
<strong>输出：</strong>1
<strong>解释：</strong>你可以选择整数 3 。
3 在范围 [1, 6] 内，且不在 banned 中，所选整数的和为 3 ，也没有超过 maxSum 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>banned = [4,3,5,6], n = 7, maxSum = 18
<strong>输出：</strong>3
<strong>解释：</strong>你可以选择整数 1, 2&nbsp;和 7 。
它们都在范围 [1, 7] 中，且都没出现在 banned 中，所选整数的和为 10 ，没有超过 maxSum 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= banned.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= banned[i] &lt;= n &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= maxSum &lt;= 10<sup>15</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：去重 + 排序 + 二分查找

我们可以在数组 `banned` 中加入 $0$ 和 $n + 1$，将数组 `banned` 去重并排序。

接下来，我们枚举数组 `banned` 中的每两个相邻元素 $i$ 和 $j$，那么可选的整数范围就是 $[i + 1, j - 1]$。二分枚举我们在此区间内能够选择的元素个数，找到最大的可选元素个数，然后将其加到 $ans$ 中。同时在 `maxSum` 中减去这些元素的和。如果 `maxSum` 小于 $0$，那么我们跳出循环。返回答案即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 `banned` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxCount(self, banned: List[int], n: int, maxSum: int) -> int:
        banned.extend([0, n + 1])
        ban = sorted(set(banned))
        ans = 0
        for i, j in pairwise(ban):
            left, right = 0, j - i - 1
            while left < right:
                mid = (left + right + 1) >> 1
                if (i + 1 + i + mid) * mid // 2 <= maxSum:
                    left = mid
                else:
                    right = mid - 1
            ans += left
            maxSum -= (i + 1 + i + left) * left // 2
            if maxSum <= 0:
                break
        return ans
```

#### Java

```java
class Solution {
    public int maxCount(int[] banned, int n, long maxSum) {
        Set<Integer> black = new HashSet<>();
        black.add(0);
        black.add(n + 1);
        for (int x : banned) {
            black.add(x);
        }
        List<Integer> ban = new ArrayList<>(black);
        Collections.sort(ban);
        int ans = 0;
        for (int k = 1; k < ban.size(); ++k) {
            int i = ban.get(k - 1), j = ban.get(k);
            int left = 0, right = j - i - 1;
            while (left < right) {
                int mid = (left + right + 1) >>> 1;
                if ((i + 1 + i + mid) * 1L * mid / 2 <= maxSum) {
                    left = mid;
                } else {
                    right = mid - 1;
                }
            }
            ans += left;
            maxSum -= (i + 1 + i + left) * 1L * left / 2;
            if (maxSum <= 0) {
                break;
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
    int maxCount(vector<int>& banned, int n, long long maxSum) {
        banned.push_back(0);
        banned.push_back(n + 1);
        sort(banned.begin(), banned.end());
        banned.erase(unique(banned.begin(), banned.end()), banned.end());
        int ans = 0;
        for (int k = 1; k < banned.size(); ++k) {
            int i = banned[k - 1], j = banned[k];
            int left = 0, right = j - i - 1;
            while (left < right) {
                int mid = left + ((right - left + 1) / 2);
                if ((i + 1 + i + mid) * 1LL * mid / 2 <= maxSum) {
                    left = mid;
                } else {
                    right = mid - 1;
                }
            }
            ans += left;
            maxSum -= (i + 1 + i + left) * 1LL * left / 2;
            if (maxSum <= 0) {
                break;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func maxCount(banned []int, n int, maxSum int64) (ans int) {
	banned = append(banned, []int{0, n + 1}...)
	sort.Ints(banned)
	ban := []int{}
	for i, x := range banned {
		if i > 0 && x == banned[i-1] {
			continue
		}
		ban = append(ban, x)
	}
	for k := 1; k < len(ban); k++ {
		i, j := ban[k-1], ban[k]
		left, right := 0, j-i-1
		for left < right {
			mid := (left + right + 1) >> 1
			if int64((i+1+i+mid)*mid/2) <= maxSum {
				left = mid
			} else {
				right = mid - 1
			}
		}
		ans += left
		maxSum -= int64((i + 1 + i + left) * left / 2)
		if maxSum <= 0 {
			break
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

# [2558. 从数量最多的堆取走礼物](https://leetcode.cn/problems/take-gifts-from-the-richest-pile){#2558}

{{< tabs "2558" >}}

{{% tab "python" %}}
```python
class Solution:
    def pickGifts(self, gifts: List[int], k: int) -> int:
        h = [-v for v in gifts]
        heapify(h)
        for _ in range(k):
            heapreplace(h, -int(sqrt(-h[0])))
        return -sum(h)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long pickGifts(int[] gifts, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> b - a);
        for (int v : gifts) {
            pq.offer(v);
        }
        while (k-- > 0) {
            pq.offer((int) Math.sqrt(pq.poll()));
        }
        long ans = 0;
        for (int v : pq) {
            ans += v;
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
    long long pickGifts(vector<int>& gifts, int k) {
        make_heap(gifts.begin(), gifts.end());
        while (k--) {
            pop_heap(gifts.begin(), gifts.end());
            gifts.back() = sqrt(gifts.back());
            push_heap(gifts.begin(), gifts.end());
        }
        return accumulate(gifts.begin(), gifts.end(), 0LL);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func pickGifts(gifts []int, k int) (ans int64) {
	h := &hp{gifts}
	heap.Init(h)
	for ; k > 0; k-- {
		gifts[0] = int(math.Sqrt(float64(gifts[0])))
		heap.Fix(h, 0)
	}
	for _, x := range gifts {
		ans += int64(x)
	}
	return
}

type hp struct{ sort.IntSlice }

func (h hp) Less(i, j int) bool { return h.IntSlice[i] > h.IntSlice[j] }
func (hp) Pop() (_ any)         { return }
func (hp) Push(any)             {}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function pickGifts(gifts: number[], k: number): number {
    const pq = new MaxPriorityQueue();
    gifts.forEach(v => pq.enqueue(v));
    while (k--) {
        let v = pq.dequeue().element;
        v = Math.floor(Math.sqrt(v));
        pq.enqueue(v);
    }
    let ans = 0;
    while (!pq.isEmpty()) {
        ans += pq.dequeue().element;
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn pick_gifts(gifts: Vec<i32>, k: i32) -> i64 {
        let mut h = std::collections::BinaryHeap::from(gifts);
        let mut ans = 0;

        for _ in 0..k {
            if let Some(mut max_gift) = h.pop() {
                max_gift = (max_gift as f64).sqrt().floor() as i32;
                h.push(max_gift);
            }
        }

        for x in h {
            ans += x as i64;
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

<p>给你一个整数数组 <code>gifts</code> ，表示各堆礼物的数量。每一秒，你需要执行以下操作：</p>

<ul>
	<li>选择礼物数量最多的那一堆。</li>
	<li>如果不止一堆都符合礼物数量最多，从中选择任一堆即可。</li>
	<li>将堆中的礼物数量减少到堆中原来礼物数量的平方根，向下取整。</li>
</ul>

<p>返回在 <code>k</code> 秒后剩下的礼物数量<em>。</em></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>gifts = [25,64,9,4,100], k = 4
<strong>输出：</strong>29
<strong>解释：</strong> 
按下述方式取走礼物：
- 在第一秒，选中最后一堆，剩下 10 个礼物。
- 接着第二秒选中第二堆礼物，剩下 8 个礼物。
- 然后选中第一堆礼物，剩下 5 个礼物。
- 最后，再次选中最后一堆礼物，剩下 3 个礼物。
最后剩下的礼物数量分别是 [5,8,9,4,3] ，所以，剩下礼物的总数量是 29 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>gifts = [1,1,1,1], k = 4
<strong>输出：</strong>4
<strong>解释：</strong>
在本例中，不管选中哪一堆礼物，都必须剩下 1 个礼物。 
也就是说，你无法获取任一堆中的礼物。 
所以，剩下礼物的总数量是 4 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= gifts.length &lt;= 10<sup>3</sup></code></li>
	<li><code>1 &lt;= gifts[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>3</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：优先队列（大根堆）

我们将数组 $gifts$ 转存到大根堆中，然后循环 $k$ 次，每次取出堆顶元素，将堆顶元素开根号的结果再放入堆中。

最后累加堆中所有元素之和作为答案。

时间复杂度 $O(n + k \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 $gifts$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def pickGifts(self, gifts: List[int], k: int) -> int:
        h = [-v for v in gifts]
        heapify(h)
        for _ in range(k):
            heapreplace(h, -int(sqrt(-h[0])))
        return -sum(h)
```

#### Java

```java
class Solution {
    public long pickGifts(int[] gifts, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> b - a);
        for (int v : gifts) {
            pq.offer(v);
        }
        while (k-- > 0) {
            pq.offer((int) Math.sqrt(pq.poll()));
        }
        long ans = 0;
        for (int v : pq) {
            ans += v;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        make_heap(gifts.begin(), gifts.end());
        while (k--) {
            pop_heap(gifts.begin(), gifts.end());
            gifts.back() = sqrt(gifts.back());
            push_heap(gifts.begin(), gifts.end());
        }
        return accumulate(gifts.begin(), gifts.end(), 0LL);
    }
};
```

#### Go

```go
func pickGifts(gifts []int, k int) (ans int64) {
	h := &hp{gifts}
	heap.Init(h)
	for ; k > 0; k-- {
		gifts[0] = int(math.Sqrt(float64(gifts[0])))
		heap.Fix(h, 0)
	}
	for _, x := range gifts {
		ans += int64(x)
	}
	return
}

type hp struct{ sort.IntSlice }

func (h hp) Less(i, j int) bool { return h.IntSlice[i] > h.IntSlice[j] }
func (hp) Pop() (_ any)         { return }
func (hp) Push(any)             {}
```

#### TypeScript

```ts
function pickGifts(gifts: number[], k: number): number {
    const pq = new MaxPriorityQueue();
    gifts.forEach(v => pq.enqueue(v));
    while (k--) {
        let v = pq.dequeue().element;
        v = Math.floor(Math.sqrt(v));
        pq.enqueue(v);
    }
    let ans = 0;
    while (!pq.isEmpty()) {
        ans += pq.dequeue().element;
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn pick_gifts(gifts: Vec<i32>, k: i32) -> i64 {
        let mut h = std::collections::BinaryHeap::from(gifts);
        let mut ans = 0;

        for _ in 0..k {
            if let Some(mut max_gift) = h.pop() {
                max_gift = (max_gift as f64).sqrt().floor() as i32;
                h.push(max_gift);
            }
        }

        for x in h {
            ans += x as i64;
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

# [2559. 统计范围内的元音字符串数](https://leetcode.cn/problems/count-vowel-strings-in-ranges){#2559}

{{< tabs "2559" >}}

{{% tab "python" %}}
```python
class Solution:
    def vowelStrings(self, words: List[str], queries: List[List[int]]) -> List[int]:
        vowels = set("aeiou")
        s = list(
            accumulate(
                (int(w[0] in vowels and w[-1] in vowels) for w in words), initial=0
            )
        )
        return [s[r + 1] - s[l] for l, r in queries]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] vowelStrings(String[] words, int[][] queries) {
        Set<Character> vowels = Set.of('a', 'e', 'i', 'o', 'u');
        int n = words.length;
        int[] s = new int[n + 1];
        for (int i = 0; i < n; ++i) {
            char a = words[i].charAt(0), b = words[i].charAt(words[i].length() - 1);
            s[i + 1] = s[i] + (vowels.contains(a) && vowels.contains(b) ? 1 : 0);
        }
        int m = queries.length;
        int[] ans = new int[m];
        for (int i = 0; i < m; ++i) {
            int l = queries[i][0], r = queries[i][1];
            ans[i] = s[r + 1] - s[l];
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
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int n = words.size();
        int s[n + 1];
        s[0] = 0;
        for (int i = 0; i < n; ++i) {
            char a = words[i][0], b = words[i].back();
            s[i + 1] = s[i] + (vowels.count(a) && vowels.count(b));
        }
        vector<int> ans;
        for (auto& q : queries) {
            int l = q[0], r = q[1];
            ans.push_back(s[r + 1] - s[l]);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func vowelStrings(words []string, queries [][]int) []int {
	vowels := map[byte]bool{'a': true, 'e': true, 'i': true, 'o': true, 'u': true}
	n := len(words)
	s := make([]int, n+1)
	for i, w := range words {
		x := 0
		if vowels[w[0]] && vowels[w[len(w)-1]] {
			x = 1
		}
		s[i+1] = s[i] + x
	}
	ans := make([]int, len(queries))
	for i, q := range queries {
		l, r := q[0], q[1]
		ans[i] = s[r+1] - s[l]
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function vowelStrings(words: string[], queries: number[][]): number[] {
    const vowels = new Set(['a', 'e', 'i', 'o', 'u']);
    const s = new Array(words.length + 1).fill(0);

    words.forEach((w, i) => {
        const x = +(vowels.has(w[0]) && vowels.has(w.at(-1)!));
        s[i + 1] = s[i] + x;
    });

    return queries.map(([l, r]) => s[r + 1] - s[l]);
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
function vowelStrings(words, queries) {
    const vowels = new Set(['a', 'e', 'i', 'o', 'u']);
    const s = new Array(words.length + 1).fill(0);

    words.forEach((w, i) => {
        const x = +(vowels.has(w[0]) && vowels.has(w.at(-1)));
        s[i + 1] = s[i] + x;
    });

    return queries.map(([l, r]) => s[r + 1] - s[l]);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong> 开始的字符串数组 <code>words</code> 以及一个二维整数数组 <code>queries</code> 。</p>

<p>每个查询 <code>queries[i] = [l<sub>i</sub>, r<sub>i</sub>]</code> 会要求我们统计在 <code>words</code> 中下标在 <code>l<sub>i</sub></code> 到 <code>r<sub>i</sub></code> 范围内（<strong>包含</strong> 这两个值）并且以元音开头和结尾的字符串的数目。</p>

<p>返回一个整数数组，其中数组的第 <code>i</code> 个元素对应第 <code>i</code> 个查询的答案。</p>

<p><strong>注意：</strong>元音字母是 <code>'a'</code>、<code>'e'</code>、<code>'i'</code>、<code>'o'</code> 和 <code>'u'</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>words = ["aba","bcb","ece","aa","e"], queries = [[0,2],[1,4],[1,1]]
<strong>输出：</strong>[2,3,0]
<strong>解释：</strong>以元音开头和结尾的字符串是 "aba"、"ece"、"aa" 和 "e" 。
查询 [0,2] 结果为 2（字符串 "aba" 和 "ece"）。
查询 [1,4] 结果为 3（字符串 "ece"、"aa"、"e"）。
查询 [1,1] 结果为 0 。
返回结果 [2,3,0] 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>words = ["a","e","i"], queries = [[0,2],[0,1],[2,2]]
<strong>输出：</strong>[3,2,1]
<strong>解释：</strong>每个字符串都满足这一条件，所以返回 [3,2,1] 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= words[i].length &lt;= 40</code></li>
	<li><code>words[i]</code> 仅由小写英文字母组成</li>
	<li><code>sum(words[i].length) &lt;= 3 * 10<sup>5</sup></code></li>
	<li><code>1 &lt;= queries.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= queries[j][0] &lt;= queries[j][1] &lt;&nbsp;words.length</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：预处理 + 二分查找

我们可以预处理出所有以元音开头和结尾的字符串的下标，按顺序记录在数组 $nums$ 中。

接下来，我们遍历每个查询 $(l, r)$，通过二分查找在 $nums$ 中找到第一个大于等于 $l$ 的下标 $i$，以及第一个大于 $r$ 的下标 $j$，那么当前查询的答案就是 $j - i$。

时间复杂度 $O(n + m \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 和 $m$ 分别是数组 $words$ 和 $queries$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def vowelStrings(self, words: List[str], queries: List[List[int]]) -> List[int]:
        vowels = set("aeiou")
        nums = [i for i, w in enumerate(words) if w[0] in vowels and w[-1] in vowels]
        return [bisect_right(nums, r) - bisect_left(nums, l) for l, r in queries]
```

#### Java

```java
class Solution {
    private List<Integer> nums = new ArrayList<>();

    public int[] vowelStrings(String[] words, int[][] queries) {
        Set<Character> vowels = Set.of('a', 'e', 'i', 'o', 'u');
        for (int i = 0; i < words.length; ++i) {
            char a = words[i].charAt(0), b = words[i].charAt(words[i].length() - 1);
            if (vowels.contains(a) && vowels.contains(b)) {
                nums.add(i);
            }
        }
        int m = queries.length;
        int[] ans = new int[m];
        for (int i = 0; i < m; ++i) {
            int l = queries[i][0], r = queries[i][1];
            ans[i] = search(r + 1) - search(l);
        }
        return ans;
    }

    private int search(int x) {
        int l = 0, r = nums.size();
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums.get(mid) >= x) {
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
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        vector<int> nums;
        for (int i = 0; i < words.size(); ++i) {
            char a = words[i][0], b = words[i].back();
            if (vowels.count(a) && vowels.count(b)) {
                nums.push_back(i);
            }
        }
        vector<int> ans;
        for (auto& q : queries) {
            int l = q[0], r = q[1];
            int cnt = upper_bound(nums.begin(), nums.end(), r) - lower_bound(nums.begin(), nums.end(), l);
            ans.push_back(cnt);
        }
        return ans;
    }
};
```

#### Go

```go
func vowelStrings(words []string, queries [][]int) []int {
	vowels := map[byte]bool{'a': true, 'e': true, 'i': true, 'o': true, 'u': true}
	nums := []int{}
	for i, w := range words {
		if vowels[w[0]] && vowels[w[len(w)-1]] {
			nums = append(nums, i)
		}
	}
	ans := make([]int, len(queries))
	for i, q := range queries {
		l, r := q[0], q[1]
		ans[i] = sort.SearchInts(nums, r+1) - sort.SearchInts(nums, l)
	}
	return ans
}
```

#### TypeScript

```ts
function vowelStrings(words: string[], queries: number[][]): number[] {
    const vowels = new Set(['a', 'e', 'i', 'o', 'u']);
    const nums: number[] = [];
    for (let i = 0; i < words.length; ++i) {
        if (vowels.has(words[i][0]) && vowels.has(words[i][words[i].length - 1])) {
            nums.push(i);
        }
    }
    const search = (x: number): number => {
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
    return queries.map(([l, r]) => search(r + 1) - search(l));
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：前缀和

我们可以创建一个长度为 $n+1$ 的前缀和数组 $s$，其中 $s[i]$ 表示数组 $words$ 的前 $i$ 个字符串中以元音开头和结尾的字符串的数目。初始时 $s[0] = 0$。

接下来，我们遍历数组 $words$，如果当前字符串以元音开头和结尾，那么 $s[i+1] = s[i] + 1$，否则 $s[i+1] = s[i]$。

最后，我们遍历每个查询 $(l, r)$，那么当前查询的答案就是 $s[r+1] - s[l]$。

时间复杂度 $O(n + m)$，空间复杂度 $O(n)$。其中 $n$ 和 $m$ 分别是数组 $words$ 和 $queries$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def vowelStrings(self, words: List[str], queries: List[List[int]]) -> List[int]:
        vowels = set("aeiou")
        s = list(
            accumulate(
                (int(w[0] in vowels and w[-1] in vowels) for w in words), initial=0
            )
        )
        return [s[r + 1] - s[l] for l, r in queries]
```

#### Java

```java
class Solution {
    public int[] vowelStrings(String[] words, int[][] queries) {
        Set<Character> vowels = Set.of('a', 'e', 'i', 'o', 'u');
        int n = words.length;
        int[] s = new int[n + 1];
        for (int i = 0; i < n; ++i) {
            char a = words[i].charAt(0), b = words[i].charAt(words[i].length() - 1);
            s[i + 1] = s[i] + (vowels.contains(a) && vowels.contains(b) ? 1 : 0);
        }
        int m = queries.length;
        int[] ans = new int[m];
        for (int i = 0; i < m; ++i) {
            int l = queries[i][0], r = queries[i][1];
            ans[i] = s[r + 1] - s[l];
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int n = words.size();
        int s[n + 1];
        s[0] = 0;
        for (int i = 0; i < n; ++i) {
            char a = words[i][0], b = words[i].back();
            s[i + 1] = s[i] + (vowels.count(a) && vowels.count(b));
        }
        vector<int> ans;
        for (auto& q : queries) {
            int l = q[0], r = q[1];
            ans.push_back(s[r + 1] - s[l]);
        }
        return ans;
    }
};
```

#### Go

```go
func vowelStrings(words []string, queries [][]int) []int {
	vowels := map[byte]bool{'a': true, 'e': true, 'i': true, 'o': true, 'u': true}
	n := len(words)
	s := make([]int, n+1)
	for i, w := range words {
		x := 0
		if vowels[w[0]] && vowels[w[len(w)-1]] {
			x = 1
		}
		s[i+1] = s[i] + x
	}
	ans := make([]int, len(queries))
	for i, q := range queries {
		l, r := q[0], q[1]
		ans[i] = s[r+1] - s[l]
	}
	return ans
}
```

#### TypeScript

```ts
function vowelStrings(words: string[], queries: number[][]): number[] {
    const vowels = new Set(['a', 'e', 'i', 'o', 'u']);
    const s = new Array(words.length + 1).fill(0);

    words.forEach((w, i) => {
        const x = +(vowels.has(w[0]) && vowels.has(w.at(-1)!));
        s[i + 1] = s[i] + x;
    });

    return queries.map(([l, r]) => s[r + 1] - s[l]);
}
```

#### JavaScript

```js
function vowelStrings(words, queries) {
    const vowels = new Set(['a', 'e', 'i', 'o', 'u']);
    const s = new Array(words.length + 1).fill(0);

    words.forEach((w, i) => {
        const x = +(vowels.has(w[0]) && vowels.has(w.at(-1)));
        s[i + 1] = s[i] + x;
    });

    return queries.map(([l, r]) => s[r + 1] - s[l]);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
