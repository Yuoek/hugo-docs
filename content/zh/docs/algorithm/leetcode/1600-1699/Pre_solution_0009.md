---
title: "1680_连接连续二进制数字"
date: 2025-10-08T18:38:12+08:00
weight: 9
tags: [位运算, 前缀和, 动态规划, 单调队列, 博弈, 哈希表, 堆（优先队列）, 字符串, 排序, 数学, 数据库, 数组, 模拟, 状态压缩, 线段树, 计数, 贪心, 队列]
---

{{< markmap >}}
### [1680_连接连续二进制数字](#1680)
#### [位运算](#1680)
#### [数学](#1680)
#### [模拟](#1680)
### [1681_最小不兼容性](#1681)
#### [位运算](#1681)
#### [数组](#1681)
#### [动态规划](#1681)
#### [状态压缩](#1681)
### [1682_最长回文子序列 II 🔒](#1682)
#### [字符串](#1682)
#### [动态规划](#1682)
### [1683_无效的推文](#1683)
#### [数据库](#1683)
### [1684_统计一致字符串的数目](#1684)
#### [位运算](#1684)
#### [数组](#1684)
#### [哈希表](#1684)
#### [字符串](#1684)
#### [计数](#1684)
### [1685_有序数组中差绝对值之和](#1685)
#### [数组](#1685)
#### [数学](#1685)
#### [前缀和](#1685)
### [1686_石子游戏 VI](#1686)
#### [贪心](#1686)
#### [数组](#1686)
#### [数学](#1686)
#### [博弈](#1686)
#### [排序](#1686)
#### [堆（优先队列）](#1686)
### [1687_从仓库到码头运输箱子](#1687)
#### [线段树](#1687)
#### [队列](#1687)
#### [数组](#1687)
#### [动态规划](#1687)
#### [前缀和](#1687)
#### [单调队列](#1687)
#### [堆（优先队列）](#1687)
### [1688_比赛中的配对次数](#1688)
#### [数学](#1688)
#### [模拟](#1688)
### [1689_十-二进制数的最少数目](#1689)
#### [贪心](#1689)
#### [字符串](#1689)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1680_连接连续二进制数字
___
#### 位运算
___
#### 数学
___
#### 模拟
---
### 1681_最小不兼容性
___
#### 位运算
___
#### 数组
___
#### 动态规划
___
#### 状态压缩
---
### 1682_最长回文子序列 II 🔒
___
#### 字符串
___
#### 动态规划
---
### 1683_无效的推文
___
#### 数据库
---
### 1684_统计一致字符串的数目
___
#### 位运算
___
#### 数组
___
#### 哈希表
___
#### 字符串
___
#### 计数
---
### 1685_有序数组中差绝对值之和
___
#### 数组
___
#### 数学
___
#### 前缀和
---
### 1686_石子游戏 VI
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
___
#### 堆（优先队列）
---
### 1687_从仓库到码头运输箱子
___
#### 线段树
___
#### 队列
___
#### 数组
___
#### 动态规划
___
#### 前缀和
___
#### 单调队列
___
#### 堆（优先队列）
---
### 1688_比赛中的配对次数
___
#### 数学
___
#### 模拟
---
### 1689_十-二进制数的最少数目
___
#### 贪心
___
#### 字符串
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 位运算 | 前缀和 | 动态规划 |
| 单调队列 | 博弈 | 哈希表 |
| 堆（优先队列） | 字符串 | 排序 |
| 数学 | 数据库 | 数组 |
| 模拟 | 状态压缩 | 线段树 |
| 计数 | 贪心 | 队列 |

# [1680. 连接连续二进制数字](https://leetcode.cn/problems/concatenation-of-consecutive-binary-numbers){#1680}

{{< tabs "1680" >}}

{{% tab "python" %}}
```python
class Solution:
    def concatenatedBinary(self, n: int) -> int:
        mod = 10**9 + 7
        ans = shift = 0
        for i in range(1, n + 1):
            if (i & (i - 1)) == 0:
                shift += 1
            ans = (ans << shift | i) % mod
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int concatenatedBinary(int n) {
        final int mod = (int) 1e9 + 7;
        long ans = 0;
        int shift = 0;
        for (int i = 1; i <= n; ++i) {
            if ((i & (i - 1)) == 0) {
                ++shift;
            }
            ans = (ans << shift | i) % mod;
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
    int concatenatedBinary(int n) {
        const int mod = 1e9 + 7;
        long ans = 0;
        int shift = 0;
        for (int i = 1; i <= n; ++i) {
            if ((i & (i - 1)) == 0) {
                ++shift;
            }
            ans = (ans << shift | i) % mod;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func concatenatedBinary(n int) (ans int) {
	const mod = 1e9 + 7
	shift := 0
	for i := 1; i <= n; i++ {
		if i&(i-1) == 0 {
			shift++
		}
		ans = (ans<<shift | i) % mod
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function concatenatedBinary(n: number): number {
    const mod = BigInt(10 ** 9 + 7);
    let ans = 0n;
    let shift = 0n;
    for (let i = 1n; i <= n; ++i) {
        if ((i & (i - 1n)) == 0n) {
            ++shift;
        }
        ans = ((ans << shift) | i) % mod;
    }
    return Number(ans);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数 <code>n</code> ，请你将 <code>1</code> 到 <code>n</code> 的二进制表示连接起来，并返回连接结果对应的 <strong>十进制</strong> 数字对 <code>10<sup>9</sup> + 7</code> 取余的结果。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>n = 1
<b>输出：</b>1
<strong>解释：</strong>二进制的 "1" 对应着十进制的 1 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>n = 3
<b>输出：</b>27
<strong>解释：</strong>二进制下，1，2 和 3 分别对应 "1" ，"10" 和 "11" 。
将它们依次连接，我们得到 "11011" ，对应着十进制的 27 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>n = 12
<b>输出：</b>505379714
<b>解释：</b>连接结果为 "1101110010111011110001001101010111100" 。
对应的十进制数字为 118505380540 。
对 10<sup>9</sup> + 7 取余后，结果为 505379714 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：位运算

观察数字的连接规律，我们可以发现，当连接到第 $i$ 个数时，实际上是将前 $i-1$ 个数连接而成的结果 $ans$ 往左移动一定的位数，然后再加上 $i$ 这个数，移动的位数 $shift$ 是 $i$ 中二进制的位数。由于 $i$ 在不断加 $1$，移动的位数要么与上一次移动的位数保持不变，要么加一。当 $i$ 为 $2$ 的幂次方的时候，也即是说 $i$ 的二进制数中只有一位是 $1$ 时，移动的位数相比于上次加 $1$。

时间复杂度 $O(n)$，其中 $n$ 为给定的整数。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def concatenatedBinary(self, n: int) -> int:
        mod = 10**9 + 7
        ans = 0
        for i in range(1, n + 1):
            ans = (ans << i.bit_length() | i) % mod
        return ans
```

#### Java

```java
class Solution {
    public int concatenatedBinary(int n) {
        final int mod = (int) 1e9 + 7;
        long ans = 0;
        for (int i = 1; i <= n; ++i) {
            ans = (ans << (32 - Integer.numberOfLeadingZeros(i)) | i) % mod;
        }
        return (int) ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int concatenatedBinary(int n) {
        const int mod = 1e9 + 7;
        long ans = 0;
        for (int i = 1; i <= n; ++i) {
            ans = (ans << (32 - __builtin_clz(i)) | i) % mod;
        }
        return ans;
    }
};
```

#### Go

```go
func concatenatedBinary(n int) (ans int) {
	const mod = 1e9 + 7
	for i := 1; i <= n; i++ {
		ans = (ans<<bits.Len(uint(i)) | i) % mod
	}
	return
}
```

#### TypeScript

```ts
function concatenatedBinary(n: number): number {
    const mod = BigInt(10 ** 9 + 7);
    let ans = 0n;
    let shift = 0n;
    for (let i = 1n; i <= n; ++i) {
        if ((i & (i - 1n)) == 0n) {
            ++shift;
        }
        ans = ((ans << shift) | i) % mod;
    }
    return Number(ans);
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
    def concatenatedBinary(self, n: int) -> int:
        mod = 10**9 + 7
        ans = shift = 0
        for i in range(1, n + 1):
            if (i & (i - 1)) == 0:
                shift += 1
            ans = (ans << shift | i) % mod
        return ans
```

#### Java

```java
class Solution {
    public int concatenatedBinary(int n) {
        final int mod = (int) 1e9 + 7;
        long ans = 0;
        int shift = 0;
        for (int i = 1; i <= n; ++i) {
            if ((i & (i - 1)) == 0) {
                ++shift;
            }
            ans = (ans << shift | i) % mod;
        }
        return (int) ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int concatenatedBinary(int n) {
        const int mod = 1e9 + 7;
        long ans = 0;
        int shift = 0;
        for (int i = 1; i <= n; ++i) {
            if ((i & (i - 1)) == 0) {
                ++shift;
            }
            ans = (ans << shift | i) % mod;
        }
        return ans;
    }
};
```

#### Go

```go
func concatenatedBinary(n int) (ans int) {
	const mod = 1e9 + 7
	shift := 0
	for i := 1; i <= n; i++ {
		if i&(i-1) == 0 {
			shift++
		}
		ans = (ans<<shift | i) % mod
	}
	return
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1681. 最小不兼容性](https://leetcode.cn/problems/minimum-incompatibility){#1681}

{{< tabs "1681" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumIncompatibility(self, nums: List[int], k: int) -> int:
        n = len(nums)
        m = n // k
        g = [-1] * (1 << n)
        for i in range(1, 1 << n):
            if i.bit_count() != m:
                continue
            s = set()
            mi, mx = 20, 0
            for j, x in enumerate(nums):
                if i >> j & 1:
                    if x in s:
                        break
                    s.add(x)
                    mi = min(mi, x)
                    mx = max(mx, x)
            if len(s) == m:
                g[i] = mx - mi
        f = [inf] * (1 << n)
        f[0] = 0
        for i in range(1 << n):
            if f[i] == inf:
                continue
            s = set()
            mask = 0
            for j, x in enumerate(nums):
                if (i >> j & 1) == 0 and x not in s:
                    s.add(x)
                    mask |= 1 << j
            if len(s) < m:
                continue
            j = mask
            while j:
                if g[j] != -1:
                    f[i | j] = min(f[i | j], f[i] + g[j])
                j = (j - 1) & mask
        return f[-1] if f[-1] != inf else -1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumIncompatibility(int[] nums, int k) {
        int n = nums.length;
        int m = n / k;
        int[] g = new int[1 << n];
        Arrays.fill(g, -1);
        for (int i = 1; i < 1 << n; ++i) {
            if (Integer.bitCount(i) != m) {
                continue;
            }
            Set<Integer> s = new HashSet<>();
            int mi = 20, mx = 0;
            for (int j = 0; j < n; ++j) {
                if ((i >> j & 1) == 1) {
                    if (!s.add(nums[j])) {
                        break;
                    }
                    mi = Math.min(mi, nums[j]);
                    mx = Math.max(mx, nums[j]);
                }
            }
            if (s.size() == m) {
                g[i] = mx - mi;
            }
        }
        int[] f = new int[1 << n];
        final int inf = 1 << 30;
        Arrays.fill(f, inf);
        f[0] = 0;
        for (int i = 0; i < 1 << n; ++i) {
            if (f[i] == inf) {
                continue;
            }
            Set<Integer> s = new HashSet<>();
            int mask = 0;
            for (int j = 0; j < n; ++j) {
                if ((i >> j & 1) == 0 && !s.contains(nums[j])) {
                    s.add(nums[j]);
                    mask |= 1 << j;
                }
            }
            if (s.size() < m) {
                continue;
            }
            for (int j = mask; j > 0; j = (j - 1) & mask) {
                if (g[j] != -1) {
                    f[i | j] = Math.min(f[i | j], f[i] + g[j]);
                }
            }
        }
        return f[(1 << n) - 1] == inf ? -1 : f[(1 << n) - 1];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minimumIncompatibility(vector<int>& nums, int k) {
        int n = nums.size();
        int m = n / k;
        int g[1 << n];
        memset(g, -1, sizeof(g));
        for (int i = 1; i < 1 << n; ++i) {
            if (__builtin_popcount(i) != m) {
                continue;
            }
            unordered_set<int> s;
            int mi = 20, mx = 0;
            for (int j = 0; j < n; ++j) {
                if (i >> j & 1) {
                    if (s.count(nums[j])) {
                        break;
                    }
                    s.insert(nums[j]);
                    mi = min(mi, nums[j]);
                    mx = max(mx, nums[j]);
                }
            }
            if (s.size() == m) {
                g[i] = mx - mi;
            }
        }
        int f[1 << n];
        memset(f, 0x3f, sizeof(f));
        f[0] = 0;
        for (int i = 0; i < 1 << n; ++i) {
            if (f[i] == 0x3f3f3f3f) {
                continue;
            }
            unordered_set<int> s;
            int mask = 0;
            for (int j = 0; j < n; ++j) {
                if ((i >> j & 1) == 0 && !s.count(nums[j])) {
                    s.insert(nums[j]);
                    mask |= 1 << j;
                }
            }
            if (s.size() < m) {
                continue;
            }
            for (int j = mask; j; j = (j - 1) & mask) {
                if (g[j] != -1) {
                    f[i | j] = min(f[i | j], f[i] + g[j]);
                }
            }
        }
        return f[(1 << n) - 1] == 0x3f3f3f3f ? -1 : f[(1 << n) - 1];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumIncompatibility(nums []int, k int) int {
	n := len(nums)
	m := n / k
	const inf = 1 << 30
	f := make([]int, 1<<n)
	g := make([]int, 1<<n)
	for i := range g {
		f[i] = inf
		g[i] = -1
	}
	for i := 1; i < 1<<n; i++ {
		if bits.OnesCount(uint(i)) != m {
			continue
		}
		s := map[int]struct{}{}
		mi, mx := 20, 0
		for j, x := range nums {
			if i>>j&1 == 1 {
				if _, ok := s[x]; ok {
					break
				}
				s[x] = struct{}{}
				mi = min(mi, x)
				mx = max(mx, x)
			}
		}
		if len(s) == m {
			g[i] = mx - mi
		}
	}
	f[0] = 0
	for i := 0; i < 1<<n; i++ {
		if f[i] == inf {
			continue
		}
		s := map[int]struct{}{}
		mask := 0
		for j, x := range nums {
			if _, ok := s[x]; !ok && i>>j&1 == 0 {
				s[x] = struct{}{}
				mask |= 1 << j
			}
		}
		if len(s) < m {
			continue
		}
		for j := mask; j > 0; j = (j - 1) & mask {
			if g[j] != -1 {
				f[i|j] = min(f[i|j], f[i]+g[j])
			}
		}
	}
	if f[1<<n-1] == inf {
		return -1
	}
	return f[1<<n-1]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumIncompatibility(nums: number[], k: number): number {
    const n = nums.length;
    const m = Math.floor(n / k);
    const g: number[] = Array(1 << n).fill(-1);
    for (let i = 1; i < 1 << n; ++i) {
        if (bitCount(i) !== m) {
            continue;
        }
        const s: Set<number> = new Set();
        let [mi, mx] = [20, 0];
        for (let j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                if (s.has(nums[j])) {
                    break;
                }
                s.add(nums[j]);
                mi = Math.min(mi, nums[j]);
                mx = Math.max(mx, nums[j]);
            }
        }
        if (s.size === m) {
            g[i] = mx - mi;
        }
    }
    const inf = 1e9;
    const f: number[] = Array(1 << n).fill(inf);
    f[0] = 0;
    for (let i = 0; i < 1 << n; ++i) {
        if (f[i] === inf) {
            continue;
        }
        const s: Set<number> = new Set();
        let mask = 0;
        for (let j = 0; j < n; ++j) {
            if (((i >> j) & 1) === 0 && !s.has(nums[j])) {
                s.add(nums[j]);
                mask |= 1 << j;
            }
        }
        if (s.size < m) {
            continue;
        }
        for (let j = mask; j; j = (j - 1) & mask) {
            if (g[j] !== -1) {
                f[i | j] = Math.min(f[i | j], f[i] + g[j]);
            }
        }
    }
    return f[(1 << n) - 1] === inf ? -1 : f[(1 << n) - 1];
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
{{% tab "cs" %}}
```cs
public class Solution {
    public int MinimumIncompatibility(int[] nums, int k) {
        int n = nums.Length;
        int m = n / k;
        int[] g = new int[1 << n];
        Array.Fill(g, -1);
        for (int i = 1; i < 1 << n; ++i) {
            if (bitCount(i) != m) {
                continue;
            }
            HashSet<int> s = new();
            int mi = 20, mx = 0;
            for (int j = 0; j < n; ++j) {
                if ((i >> j & 1) == 1) {
                    if (s.Contains(nums[j])) {
                        break;
                    }
                    s.Add(nums[j]);
                    mi = Math.Min(mi, nums[j]);
                    mx = Math.Max(mx, nums[j]);
                }
            }
            if (s.Count == m) {
                g[i] = mx - mi;
            }
        }
        int[] f = new int[1 << n];
        int inf = 1 << 30;
        Array.Fill(f, inf);
        f[0] = 0;
        for (int i = 0; i < 1 << n; ++i) {
            if (f[i] == inf) {
                continue;
            }
            HashSet<int> s = new();
            int mask = 0;
            for (int j = 0; j < n; ++j) {
                if ((i >> j & 1) == 0 && !s.Contains(nums[j])) {
                    s.Add(nums[j]);
                    mask |= 1 << j;
                }
            }
            if (s.Count < m) {
                continue;
            }
            for (int j = mask; j > 0; j = (j - 1) & mask) {
                if (g[j] != -1) {
                    f[i | j] = Math.Min(f[i | j], f[i] + g[j]);
                }
            }
        }
        return f[(1 << n) - 1] == inf ? -1 : f[(1 << n) - 1];
    }

    private int bitCount(int x) {
        int cnt = 0;
        while (x > 0) {
            x &= x - 1;
            ++cnt;
        }
        return cnt;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>nums</code>​​​ 和一个整数 <code>k</code> 。你需要将这个数组划分到 <code>k</code> 个相同大小的子集中，使得同一个子集里面没有两个相同的元素。</p>

<p>一个子集的 <strong>不兼容性</strong> 是该子集里面最大值和最小值的差。</p>

<p>请你返回将数组分成 <code>k</code> 个子集后，各子集 <strong>不兼容性 </strong>的<strong> 和</strong> 的 <strong>最小值</strong> ，如果无法分成分成 <code>k</code> 个子集，返回 <code>-1</code> 。</p>

<p>子集的定义是数组中一些数字的集合，对数字顺序没有要求。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [1,2,1,4], k = 2
<b>输出：</b>4
<b>解释：</b>最优的分配是 [1,2] 和 [1,4] 。
不兼容性和为 (2-1) + (4-1) = 4 。
注意到 [1,1] 和 [2,4] 可以得到更小的和，但是第一个集合有 2 个相同的元素，所以不可行。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [6,3,8,1,3,1,2,2], k = 4
<b>输出：</b>6
<b>解释：</b>最优的子集分配为 [1,2]，[2,3]，[6,8] 和 [1,3] 。
不兼容性和为 (2-1) + (3-2) + (8-6) + (3-1) = 6 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>nums = [5,3,3,6,3,3], k = 3
<b>输出：</b>-1
<b>解释：</b>没办法将这些数字分配到 3 个子集且满足每个子集里没有相同数字。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= k <= nums.length <= 16</code></li>
	<li><code>nums.length</code> 能被 <code>k</code> 整除。</li>
	<li><code>1 <= nums[i] <= nums.length</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：预处理 + 状态压缩 + 动态规划

不妨设划分后每个子集的大小为 $m$，那么 $m=\frac{n}{k}$，其中 $n$ 是数组的长度。

我们可以枚举所有的子集 $i$，其中 $i \in [0, 2^n)$，如果子集 $i$ 的二进制表示中有 $m$ 个 $1$，并且子集 $i$ 中的元素没有重复，那么我们就可以计算出子集 $i$ 的不兼容性，记为 $g[i]$，即 $g[i]=\max_{j \in i} \{nums[j]\} - \min_{j \in i} \{nums[j]\}$。

接下来，我们可以使用动态规划来求解。

我们定义 $f[i]$ 表示当前已经划分的子集状态为 $i$ 时，子集的不兼容性和的最小值。初始时 $f[0]=0$，表示没有任何元素被划分到子集中，其余 $f[i]=+\infty$。

对于状态 $i$，我们找出所有未被划分且不重复的元素，用一个状态 $mask$ 表示，如果状态 $mask$ 中的元素个数大于等于 $m$，那么我们就枚举 $mask$ 的所有子集 $j$，并且满足 $j \subset mask$，那么 $f[i \cup j]=\min \{f[i \cup j], f[i]+g[j]\}$。

最后，如果 $f[2^n-1]=+\infty$，那么说明无法划分成 $k$ 个子集，返回 $-1$，否则返回 $f[2^n-1]$。

时间复杂度 $O(3^n)$，空间复杂度 $O(2^n)$。其中 $n$ 是数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumIncompatibility(self, nums: List[int], k: int) -> int:
        n = len(nums)
        m = n // k
        g = [-1] * (1 << n)
        for i in range(1, 1 << n):
            if i.bit_count() != m:
                continue
            s = set()
            mi, mx = 20, 0
            for j, x in enumerate(nums):
                if i >> j & 1:
                    if x in s:
                        break
                    s.add(x)
                    mi = min(mi, x)
                    mx = max(mx, x)
            if len(s) == m:
                g[i] = mx - mi
        f = [inf] * (1 << n)
        f[0] = 0
        for i in range(1 << n):
            if f[i] == inf:
                continue
            s = set()
            mask = 0
            for j, x in enumerate(nums):
                if (i >> j & 1) == 0 and x not in s:
                    s.add(x)
                    mask |= 1 << j
            if len(s) < m:
                continue
            j = mask
            while j:
                if g[j] != -1:
                    f[i | j] = min(f[i | j], f[i] + g[j])
                j = (j - 1) & mask
        return f[-1] if f[-1] != inf else -1
```

#### Java

```java
class Solution {
    public int minimumIncompatibility(int[] nums, int k) {
        int n = nums.length;
        int m = n / k;
        int[] g = new int[1 << n];
        Arrays.fill(g, -1);
        for (int i = 1; i < 1 << n; ++i) {
            if (Integer.bitCount(i) != m) {
                continue;
            }
            Set<Integer> s = new HashSet<>();
            int mi = 20, mx = 0;
            for (int j = 0; j < n; ++j) {
                if ((i >> j & 1) == 1) {
                    if (!s.add(nums[j])) {
                        break;
                    }
                    mi = Math.min(mi, nums[j]);
                    mx = Math.max(mx, nums[j]);
                }
            }
            if (s.size() == m) {
                g[i] = mx - mi;
            }
        }
        int[] f = new int[1 << n];
        final int inf = 1 << 30;
        Arrays.fill(f, inf);
        f[0] = 0;
        for (int i = 0; i < 1 << n; ++i) {
            if (f[i] == inf) {
                continue;
            }
            Set<Integer> s = new HashSet<>();
            int mask = 0;
            for (int j = 0; j < n; ++j) {
                if ((i >> j & 1) == 0 && !s.contains(nums[j])) {
                    s.add(nums[j]);
                    mask |= 1 << j;
                }
            }
            if (s.size() < m) {
                continue;
            }
            for (int j = mask; j > 0; j = (j - 1) & mask) {
                if (g[j] != -1) {
                    f[i | j] = Math.min(f[i | j], f[i] + g[j]);
                }
            }
        }
        return f[(1 << n) - 1] == inf ? -1 : f[(1 << n) - 1];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumIncompatibility(vector<int>& nums, int k) {
        int n = nums.size();
        int m = n / k;
        int g[1 << n];
        memset(g, -1, sizeof(g));
        for (int i = 1; i < 1 << n; ++i) {
            if (__builtin_popcount(i) != m) {
                continue;
            }
            unordered_set<int> s;
            int mi = 20, mx = 0;
            for (int j = 0; j < n; ++j) {
                if (i >> j & 1) {
                    if (s.count(nums[j])) {
                        break;
                    }
                    s.insert(nums[j]);
                    mi = min(mi, nums[j]);
                    mx = max(mx, nums[j]);
                }
            }
            if (s.size() == m) {
                g[i] = mx - mi;
            }
        }
        int f[1 << n];
        memset(f, 0x3f, sizeof(f));
        f[0] = 0;
        for (int i = 0; i < 1 << n; ++i) {
            if (f[i] == 0x3f3f3f3f) {
                continue;
            }
            unordered_set<int> s;
            int mask = 0;
            for (int j = 0; j < n; ++j) {
                if ((i >> j & 1) == 0 && !s.count(nums[j])) {
                    s.insert(nums[j]);
                    mask |= 1 << j;
                }
            }
            if (s.size() < m) {
                continue;
            }
            for (int j = mask; j; j = (j - 1) & mask) {
                if (g[j] != -1) {
                    f[i | j] = min(f[i | j], f[i] + g[j]);
                }
            }
        }
        return f[(1 << n) - 1] == 0x3f3f3f3f ? -1 : f[(1 << n) - 1];
    }
};
```

#### Go

```go
func minimumIncompatibility(nums []int, k int) int {
	n := len(nums)
	m := n / k
	const inf = 1 << 30
	f := make([]int, 1<<n)
	g := make([]int, 1<<n)
	for i := range g {
		f[i] = inf
		g[i] = -1
	}
	for i := 1; i < 1<<n; i++ {
		if bits.OnesCount(uint(i)) != m {
			continue
		}
		s := map[int]struct{}{}
		mi, mx := 20, 0
		for j, x := range nums {
			if i>>j&1 == 1 {
				if _, ok := s[x]; ok {
					break
				}
				s[x] = struct{}{}
				mi = min(mi, x)
				mx = max(mx, x)
			}
		}
		if len(s) == m {
			g[i] = mx - mi
		}
	}
	f[0] = 0
	for i := 0; i < 1<<n; i++ {
		if f[i] == inf {
			continue
		}
		s := map[int]struct{}{}
		mask := 0
		for j, x := range nums {
			if _, ok := s[x]; !ok && i>>j&1 == 0 {
				s[x] = struct{}{}
				mask |= 1 << j
			}
		}
		if len(s) < m {
			continue
		}
		for j := mask; j > 0; j = (j - 1) & mask {
			if g[j] != -1 {
				f[i|j] = min(f[i|j], f[i]+g[j])
			}
		}
	}
	if f[1<<n-1] == inf {
		return -1
	}
	return f[1<<n-1]
}
```

#### TypeScript

```ts
function minimumIncompatibility(nums: number[], k: number): number {
    const n = nums.length;
    const m = Math.floor(n / k);
    const g: number[] = Array(1 << n).fill(-1);
    for (let i = 1; i < 1 << n; ++i) {
        if (bitCount(i) !== m) {
            continue;
        }
        const s: Set<number> = new Set();
        let [mi, mx] = [20, 0];
        for (let j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                if (s.has(nums[j])) {
                    break;
                }
                s.add(nums[j]);
                mi = Math.min(mi, nums[j]);
                mx = Math.max(mx, nums[j]);
            }
        }
        if (s.size === m) {
            g[i] = mx - mi;
        }
    }
    const inf = 1e9;
    const f: number[] = Array(1 << n).fill(inf);
    f[0] = 0;
    for (let i = 0; i < 1 << n; ++i) {
        if (f[i] === inf) {
            continue;
        }
        const s: Set<number> = new Set();
        let mask = 0;
        for (let j = 0; j < n; ++j) {
            if (((i >> j) & 1) === 0 && !s.has(nums[j])) {
                s.add(nums[j]);
                mask |= 1 << j;
            }
        }
        if (s.size < m) {
            continue;
        }
        for (let j = mask; j; j = (j - 1) & mask) {
            if (g[j] !== -1) {
                f[i | j] = Math.min(f[i | j], f[i] + g[j]);
            }
        }
    }
    return f[(1 << n) - 1] === inf ? -1 : f[(1 << n) - 1];
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

#### C#

```cs
public class Solution {
    public int MinimumIncompatibility(int[] nums, int k) {
        int n = nums.Length;
        int m = n / k;
        int[] g = new int[1 << n];
        Array.Fill(g, -1);
        for (int i = 1; i < 1 << n; ++i) {
            if (bitCount(i) != m) {
                continue;
            }
            HashSet<int> s = new();
            int mi = 20, mx = 0;
            for (int j = 0; j < n; ++j) {
                if ((i >> j & 1) == 1) {
                    if (s.Contains(nums[j])) {
                        break;
                    }
                    s.Add(nums[j]);
                    mi = Math.Min(mi, nums[j]);
                    mx = Math.Max(mx, nums[j]);
                }
            }
            if (s.Count == m) {
                g[i] = mx - mi;
            }
        }
        int[] f = new int[1 << n];
        int inf = 1 << 30;
        Array.Fill(f, inf);
        f[0] = 0;
        for (int i = 0; i < 1 << n; ++i) {
            if (f[i] == inf) {
                continue;
            }
            HashSet<int> s = new();
            int mask = 0;
            for (int j = 0; j < n; ++j) {
                if ((i >> j & 1) == 0 && !s.Contains(nums[j])) {
                    s.Add(nums[j]);
                    mask |= 1 << j;
                }
            }
            if (s.Count < m) {
                continue;
            }
            for (int j = mask; j > 0; j = (j - 1) & mask) {
                if (g[j] != -1) {
                    f[i | j] = Math.Min(f[i | j], f[i] + g[j]);
                }
            }
        }
        return f[(1 << n) - 1] == inf ? -1 : f[(1 << n) - 1];
    }

    private int bitCount(int x) {
        int cnt = 0;
        while (x > 0) {
            x &= x - 1;
            ++cnt;
        }
        return cnt;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1682. 最长回文子序列 II 🔒](https://leetcode.cn/problems/longest-palindromic-subsequence-ii){#1682}

{{< tabs "1682" >}}

{{% tab "python" %}}
```python
class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        @cache
        def dfs(i, j, x):
            if i >= j:
                return 0
            if s[i] == s[j] and s[i] != x:
                return dfs(i + 1, j - 1, s[i]) + 2
            return max(dfs(i + 1, j, x), dfs(i, j - 1, x))

        ans = dfs(0, len(s) - 1, '')
        dfs.cache_clear()
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[][][] f;
    private String s;

    public int longestPalindromeSubseq(String s) {
        int n = s.length();
        this.s = s;
        f = new int[n][n][27];
        for (var a : f) {
            for (var b : a) {
                Arrays.fill(b, -1);
            }
        }
        return dfs(0, n - 1, 26);
    }

    private int dfs(int i, int j, int x) {
        if (i >= j) {
            return 0;
        }
        if (f[i][j][x] != -1) {
            return f[i][j][x];
        }
        int ans = 0;
        if (s.charAt(i) == s.charAt(j) && s.charAt(i) - 'a' != x) {
            ans = dfs(i + 1, j - 1, s.charAt(i) - 'a') + 2;
        } else {
            ans = Math.max(dfs(i + 1, j, x), dfs(i, j - 1, x));
        }
        f[i][j][x] = ans;
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int f[251][251][27];

    int longestPalindromeSubseq(string s) {
        int n = s.size();
        memset(f, -1, sizeof f);
        function<int(int, int, int)> dfs = [&](int i, int j, int x) -> int {
            if (i >= j) return 0;
            if (f[i][j][x] != -1) return f[i][j][x];
            int ans = 0;
            if (s[i] == s[j] && s[i] - 'a' != x)
                ans = dfs(i + 1, j - 1, s[i] - 'a') + 2;
            else
                ans = max(dfs(i + 1, j, x), dfs(i, j - 1, x));
            f[i][j][x] = ans;
            return ans;
        };
        return dfs(0, n - 1, 26);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func longestPalindromeSubseq(s string) int {
	n := len(s)
	f := make([][][]int, n)
	for i := range f {
		f[i] = make([][]int, n)
		for j := range f[i] {
			f[i][j] = make([]int, 27)
			for k := range f[i][j] {
				f[i][j][k] = -1
			}
		}
	}
	var dfs func(i, j, x int) int
	dfs = func(i, j, x int) int {
		if i >= j {
			return 0
		}
		if f[i][j][x] != -1 {
			return f[i][j][x]
		}
		ans := 0
		if s[i] == s[j] && int(s[i]-'a') != x {
			ans = dfs(i+1, j-1, int(s[i]-'a')) + 2
		} else {
			ans = max(dfs(i+1, j, x), dfs(i, j-1, x))
		}
		f[i][j][x] = ans
		return ans
	}
	return dfs(0, n-1, 26)
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>字符串&nbsp;<code>s</code>&nbsp;的某个子序列符合下列条件时，称为“<strong>好的回文子序列</strong>”：</p>

<ul>
	<li>它是&nbsp;<code>s</code>&nbsp;的子序列。</li>
	<li>它是回文序列（反转后与原序列相等）。</li>
	<li>长度为<strong>偶数</strong>。</li>
	<li>除中间的两个字符外，其余任意两个连续字符不相等。</li>
</ul>

<p>例如，若&nbsp;<code>s = "abcabcabb"</code>，则&nbsp;<code>"abba"</code>&nbsp;可称为“好的回文子序列”，而&nbsp;<code>"bcb"</code>&nbsp;（长度不是偶数）和&nbsp;<code>"bbbb"</code>&nbsp;（含有相等的连续字符）不能称为“好的回文子序列”。</p>

<p>给定一个字符串&nbsp;<code>s</code>， 返回<em>&nbsp;</em><code>s</code>&nbsp;的<strong>最长“好的回文子序列”</strong>的<strong>长度</strong>。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> s = "bbabab"
<strong>输出:</strong> 4
<strong>解释:</strong> s 的最长“好的回文子序列”是 "baab"。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> s = "dcbccacdb"
<strong>输出:</strong> 4
<strong>解释:</strong> s 的最长“好的回文子序列”是 "dccd"。
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 250</code></li>
	<li><code>s</code>&nbsp;包含小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

我们设计一个函数 $dfs(i, j, x)$ 表示字符串 $s$ 中下标范围 $[i, j]$ 内，且以字符 $x$ 结尾的最长“好的回文子序列”的长度。答案为 $dfs(0, n - 1, 26)$。

函数 $dfs(i, j, x)$ 的计算过程如下：

-   如果 $i >= j$，则 $dfs(i, j, x) = 0$；
-   如果 $s[i] = s[j]$，且 $s[i] \neq x$，那么 $dfs(i, j, x) = dfs(i + 1, j - 1, s[i]) + 2$；
-   如果 $s[i] \neq s[j]$，那么 $dfs(i, j, x) = max(dfs(i + 1, j, x), dfs(i, j - 1, x))$。

过程中，我们可以使用记忆化搜索的方式，避免重复计算。

时间复杂度 $O(n^2 \times C)$。其中 $n$ 为字符串 $s$ 的长度，而 $C$ 为字符集大小。本题中 $C = 26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        @cache
        def dfs(i, j, x):
            if i >= j:
                return 0
            if s[i] == s[j] and s[i] != x:
                return dfs(i + 1, j - 1, s[i]) + 2
            return max(dfs(i + 1, j, x), dfs(i, j - 1, x))

        ans = dfs(0, len(s) - 1, '')
        dfs.cache_clear()
        return ans
```

#### Java

```java
class Solution {
    private int[][][] f;
    private String s;

    public int longestPalindromeSubseq(String s) {
        int n = s.length();
        this.s = s;
        f = new int[n][n][27];
        for (var a : f) {
            for (var b : a) {
                Arrays.fill(b, -1);
            }
        }
        return dfs(0, n - 1, 26);
    }

    private int dfs(int i, int j, int x) {
        if (i >= j) {
            return 0;
        }
        if (f[i][j][x] != -1) {
            return f[i][j][x];
        }
        int ans = 0;
        if (s.charAt(i) == s.charAt(j) && s.charAt(i) - 'a' != x) {
            ans = dfs(i + 1, j - 1, s.charAt(i) - 'a') + 2;
        } else {
            ans = Math.max(dfs(i + 1, j, x), dfs(i, j - 1, x));
        }
        f[i][j][x] = ans;
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int f[251][251][27];

    int longestPalindromeSubseq(string s) {
        int n = s.size();
        memset(f, -1, sizeof f);
        function<int(int, int, int)> dfs = [&](int i, int j, int x) -> int {
            if (i >= j) return 0;
            if (f[i][j][x] != -1) return f[i][j][x];
            int ans = 0;
            if (s[i] == s[j] && s[i] - 'a' != x)
                ans = dfs(i + 1, j - 1, s[i] - 'a') + 2;
            else
                ans = max(dfs(i + 1, j, x), dfs(i, j - 1, x));
            f[i][j][x] = ans;
            return ans;
        };
        return dfs(0, n - 1, 26);
    }
};
```

#### Go

```go
func longestPalindromeSubseq(s string) int {
	n := len(s)
	f := make([][][]int, n)
	for i := range f {
		f[i] = make([][]int, n)
		for j := range f[i] {
			f[i][j] = make([]int, 27)
			for k := range f[i][j] {
				f[i][j][k] = -1
			}
		}
	}
	var dfs func(i, j, x int) int
	dfs = func(i, j, x int) int {
		if i >= j {
			return 0
		}
		if f[i][j][x] != -1 {
			return f[i][j][x]
		}
		ans := 0
		if s[i] == s[j] && int(s[i]-'a') != x {
			ans = dfs(i+1, j-1, int(s[i]-'a')) + 2
		} else {
			ans = max(dfs(i+1, j, x), dfs(i, j-1, x))
		}
		f[i][j][x] = ans
		return ans
	}
	return dfs(0, n-1, 26)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1683. 无效的推文](https://leetcode.cn/problems/invalid-tweets){#1683}

{{< tabs "1683" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT
    tweet_id
FROM Tweets
WHERE CHAR_LENGTH(content) > 15;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code>Tweets</code></p>

<pre>
+----------------+---------+
| Column Name    | Type    |
+----------------+---------+
| tweet_id       | int     |
| content        | varchar |
+----------------+---------+
在 SQL 中，tweet_id 是这个表的主键。
content 只包含字母数字字符，'!'，' '，不包含其它特殊字符。
这个表包含某社交媒体 App 中所有的推文。</pre>

<p>&nbsp;</p>

<p>查询所有无效推文的编号（ID）。当推文内容中的字符数<strong>严格大于</strong> <code>15</code> 时，该推文是无效的。</p>

<p>以<strong>任意顺序</strong>返回结果表。</p>

<p>查询结果格式如下所示：</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
Tweets 表：
+----------+----------------------------------+
| tweet_id | content                          |
+----------+----------------------------------+
| 1        | Vote for Biden                   |
| 2        | Let us make America great again! |
+----------+----------------------------------+

<strong>输出：</strong>
+----------+
| tweet_id |
+----------+
| 2        |
+----------+
<strong>解释：</strong>
推文 1 的长度 length = 14。该推文是有效的。
推文 2 的长度 length = 32。该推文是无效的。
</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：使用 `CHAR_LENGTH` 函数

`CHAR_LENGTH()` 函数返回字符串的长度，其中中文、数字、字母都是 $1$ 字节。

`LENGTH()` 函数返回字符串的长度，其中 utf8 编码下，中文 $3$ 字节，数字、字母 $1$ 字节；gbk 编码下，中文 $2$ 字节，数字、字母 $1$ 字节。

对于本题，我们直接用 `CHAR_LENGTH` 函数获取字符串长度，筛选出长度大于 $15$ 的推文 ID 即可。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT
    tweet_id
FROM Tweets
WHERE CHAR_LENGTH(content) > 15;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1684. 统计一致字符串的数目](https://leetcode.cn/problems/count-the-number-of-consistent-strings){#1684}

{{< tabs "1684" >}}

{{% tab "python" %}}
```python
class Solution:
    def countConsistentStrings(self, allowed: str, words: List[str]) -> int:
        def f(w):
            return reduce(or_, (1 << (ord(c) - ord('a')) for c in w))

        mask = f(allowed)
        return sum((mask | f(w)) == mask for w in words)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countConsistentStrings(String allowed, String[] words) {
        int mask = f(allowed);
        int ans = 0;
        for (String w : words) {
            if ((mask | f(w)) == mask) {
                ++ans;
            }
        }
        return ans;
    }

    private int f(String w) {
        int mask = 0;
        for (int i = 0; i < w.length(); ++i) {
            mask |= 1 << (w.charAt(i) - 'a');
        }
        return mask;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        auto f = [](string& w) {
            int mask = 0;
            for (auto& c : w) mask |= 1 << (c - 'a');
            return mask;
        };
        int mask = f(allowed);
        int ans = 0;
        for (auto& w : words) ans += (mask | f(w)) == mask;
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countConsistentStrings(allowed string, words []string) (ans int) {
	f := func(w string) (mask int) {
		for _, c := range w {
			mask |= 1 << (c - 'a')
		}
		return
	}

	mask := f(allowed)
	for _, w := range words {
		if (mask | f(w)) == mask {
			ans++
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countConsistentStrings(allowed: string, words: string[]): number {
    const helper = (s: string) => {
        let res = 0;
        for (const c of s) {
            res |= 1 << (c.charCodeAt(0) - 'a'.charCodeAt(0));
        }
        return res;
    };
    const mask = helper(allowed);
    let ans = 0;
    for (const word of words) {
        if ((mask | helper(word)) === mask) {
            ans++;
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    fn helper(s: &String) -> i32 {
        let mut res = 0;
        for c in s.as_bytes().iter() {
            res |= 1 << ((c - b'a') as i32);
        }
        res
    }

    pub fn count_consistent_strings(allowed: String, words: Vec<String>) -> i32 {
        let mask = Self::helper(&allowed);
        let mut ans = 0;
        for word in words.iter() {
            if (mask | Self::helper(word)) == mask {
                ans += 1;
            }
        }
        ans
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
int helper(char* s) {
    int res = 0;
    int n = strlen(s);
    for (int i = 0; i < n; i++) {
        res |= 1 << (s[i] - 'a');
    }
    return res;
}

int countConsistentStrings(char* allowed, char** words, int wordsSize) {
    int mask = helper(allowed);
    int ans = 0;
    for (int i = 0; i < wordsSize; i++) {
        if ((mask | helper(words[i])) == mask) {
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

<p>给你一个由不同字符组成的字符串 <code>allowed</code> 和一个字符串数组 <code>words</code> 。如果一个字符串的每一个字符都在 <code>allowed</code> 中，就称这个字符串是 <strong>一致字符串 </strong>。</p>

<p>请你返回 <code>words</code> 数组中 <strong>一致字符串</strong> 的数目。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>allowed = "ab", words = ["ad","bd","aaab","baa","badab"]
<b>输出：</b>2
<b>解释：</b>字符串 "aaab" 和 "baa" 都是一致字符串，因为它们只包含字符 'a' 和 'b' 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>allowed = "abc", words = ["a","b","c","ab","ac","bc","abc"]
<b>输出：</b>7
<b>解释：</b>所有字符串都是一致的。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>allowed = "cad", words = ["cc","acd","b","ba","bac","bad","ac","d"]
<b>输出：</b>4
<b>解释：</b>字符串 "cc"，"acd"，"ac" 和 "d" 是一致字符串。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= words.length <= 10<sup>4</sup></code></li>
	<li><code>1 <= allowed.length <=<sup> </sup>26</code></li>
	<li><code>1 <= words[i].length <= 10</code></li>
	<li><code>allowed</code> 中的字符 <strong>互不相同</strong> 。</li>
	<li><code>words[i]</code> 和 <code>allowed</code> 只包含小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表或数组

一种比较直接的思路是，用哈希表或数组 $s$ 记录 `allowed` 中的字符。然后遍历 `words` 数组，对于每个字符串 $w$，判断其是否由 `allowed` 中的字符组成。若是，答案加一。

时间复杂度 $O(m)$，空间复杂度 $O(C)$。其中 $m$ 为所有字符串的总长度，而 $C$ 为 `allowed` 字符集的大小。本题中 $C \leq 26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countConsistentStrings(self, allowed: str, words: List[str]) -> int:
        s = set(allowed)
        return sum(all(c in s for c in w) for w in words)
```

#### Java

```java
class Solution {
    public int countConsistentStrings(String allowed, String[] words) {
        boolean[] s = new boolean[26];
        for (char c : allowed.toCharArray()) {
            s[c - 'a'] = true;
        }
        int ans = 0;
        for (String w : words) {
            if (check(w, s)) {
                ++ans;
            }
        }
        return ans;
    }

    private boolean check(String w, boolean[] s) {
        for (int i = 0; i < w.length(); ++i) {
            if (!s[w.charAt(i) - 'a']) {
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
    int countConsistentStrings(string allowed, vector<string>& words) {
        bitset<26> s;
        for (auto& c : allowed) s[c - 'a'] = 1;
        int ans = 0;
        auto check = [&](string& w) {
            for (auto& c : w)
                if (!s[c - 'a']) return false;
            return true;
        };
        for (auto& w : words) ans += check(w);
        return ans;
    }
};
```

#### Go

```go
func countConsistentStrings(allowed string, words []string) (ans int) {
	s := [26]bool{}
	for _, c := range allowed {
		s[c-'a'] = true
	}
	check := func(w string) bool {
		for _, c := range w {
			if !s[c-'a'] {
				return false
			}
		}
		return true
	}
	for _, w := range words {
		if check(w) {
			ans++
		}
	}
	return ans
}
```

#### TypeScript

```ts
function countConsistentStrings(allowed: string, words: string[]): number {
    const set = new Set([...allowed]);
    const n = words.length;
    let ans = n;
    for (const word of words) {
        for (const c of word) {
            if (!set.has(c)) {
                ans--;
                break;
            }
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn count_consistent_strings(allowed: String, words: Vec<String>) -> i32 {
        let n = words.len();
        let mut make = [false; 26];
        for c in allowed.as_bytes() {
            make[(c - b'a') as usize] = true;
        }
        let mut ans = n as i32;
        for word in words.iter() {
            for c in word.as_bytes().iter() {
                if !make[(c - b'a') as usize] {
                    ans -= 1;
                    break;
                }
            }
        }
        ans
    }
}
```

#### C

```c
int countConsistentStrings(char* allowed, char** words, int wordsSize) {
    int n = strlen(allowed);
    int make[26] = {0};
    for (int i = 0; i < n; i++) {
        make[allowed[i] - 'a'] = 1;
    }
    int ans = wordsSize;
    for (int i = 0; i < wordsSize; i++) {
        char* word = words[i];
        for (int j = 0; j < strlen(word); j++) {
            if (!make[word[j] - 'a']) {
                ans--;
                break;
            }
        }
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：位运算

我们也可以仅用一个整数来表示每个字符串中字符的出现情况。其中，整数的二进制表示中的每一位表示一个字符是否出现。

我们简单地定义一个函数 $f(w)$，这个函数可以将一个字符串 $w$ 转换为一个整数。整数的二进制表示中的每一位表示一个字符是否出现。例如，字符串 `ab` 可以转换为整数 $3$，即二进制表示为 $11$。字符串 `abd` 可以转换为整数 $11$，即二进制表示为 $1011$。

回到题目上，判断一个字符串 $w$ 是否由 `allowed` 中的字符组成，就可以转换为：判断 $f(allowed)$ 和 $f(w)$ 进行按位或运算后的结果是否等于 $f(allowed)$。若是，答案加一。

时间复杂度 $O(m)$，其中 $m$ 为所有字符串的总长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countConsistentStrings(self, allowed: str, words: List[str]) -> int:
        def f(w):
            return reduce(or_, (1 << (ord(c) - ord('a')) for c in w))

        mask = f(allowed)
        return sum((mask | f(w)) == mask for w in words)
```

#### Java

```java
class Solution {
    public int countConsistentStrings(String allowed, String[] words) {
        int mask = f(allowed);
        int ans = 0;
        for (String w : words) {
            if ((mask | f(w)) == mask) {
                ++ans;
            }
        }
        return ans;
    }

    private int f(String w) {
        int mask = 0;
        for (int i = 0; i < w.length(); ++i) {
            mask |= 1 << (w.charAt(i) - 'a');
        }
        return mask;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        auto f = [](string& w) {
            int mask = 0;
            for (auto& c : w) mask |= 1 << (c - 'a');
            return mask;
        };
        int mask = f(allowed);
        int ans = 0;
        for (auto& w : words) ans += (mask | f(w)) == mask;
        return ans;
    }
};
```

#### Go

```go
func countConsistentStrings(allowed string, words []string) (ans int) {
	f := func(w string) (mask int) {
		for _, c := range w {
			mask |= 1 << (c - 'a')
		}
		return
	}

	mask := f(allowed)
	for _, w := range words {
		if (mask | f(w)) == mask {
			ans++
		}
	}
	return
}
```

#### TypeScript

```ts
function countConsistentStrings(allowed: string, words: string[]): number {
    const helper = (s: string) => {
        let res = 0;
        for (const c of s) {
            res |= 1 << (c.charCodeAt(0) - 'a'.charCodeAt(0));
        }
        return res;
    };
    const mask = helper(allowed);
    let ans = 0;
    for (const word of words) {
        if ((mask | helper(word)) === mask) {
            ans++;
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    fn helper(s: &String) -> i32 {
        let mut res = 0;
        for c in s.as_bytes().iter() {
            res |= 1 << ((c - b'a') as i32);
        }
        res
    }

    pub fn count_consistent_strings(allowed: String, words: Vec<String>) -> i32 {
        let mask = Self::helper(&allowed);
        let mut ans = 0;
        for word in words.iter() {
            if (mask | Self::helper(word)) == mask {
                ans += 1;
            }
        }
        ans
    }
}
```

#### C

```c
int helper(char* s) {
    int res = 0;
    int n = strlen(s);
    for (int i = 0; i < n; i++) {
        res |= 1 << (s[i] - 'a');
    }
    return res;
}

int countConsistentStrings(char* allowed, char** words, int wordsSize) {
    int mask = helper(allowed);
    int ans = 0;
    for (int i = 0; i < wordsSize; i++) {
        if ((mask | helper(words[i])) == mask) {
            ans++;
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

# [1685. 有序数组中差绝对值之和](https://leetcode.cn/problems/sum-of-absolute-differences-in-a-sorted-array){#1685}

{{< tabs "1685" >}}

{{% tab "python" %}}
```python
class Solution:
    def getSumAbsoluteDifferences(self, nums: List[int]) -> List[int]:
        ans = []
        s, t = sum(nums), 0
        for i, x in enumerate(nums):
            v = x * i - t + s - t - x * (len(nums) - i)
            ans.append(v)
            t += x
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] getSumAbsoluteDifferences(int[] nums) {
        // int s = Arrays.stream(nums).sum();
        int s = 0, t = 0;
        for (int x : nums) {
            s += x;
        }
        int n = nums.length;
        int[] ans = new int[n];
        for (int i = 0; i < n; ++i) {
            int v = nums[i] * i - t + s - t - nums[i] * (n - i);
            ans[i] = v;
            t += nums[i];
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
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int s = accumulate(nums.begin(), nums.end(), 0), t = 0;
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            int v = nums[i] * i - t + s - t - nums[i] * (n - i);
            ans[i] = v;
            t += nums[i];
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func getSumAbsoluteDifferences(nums []int) (ans []int) {
	var s, t int
	for _, x := range nums {
		s += x
	}
	for i, x := range nums {
		v := x*i - t + s - t - x*(len(nums)-i)
		ans = append(ans, v)
		t += x
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function getSumAbsoluteDifferences(nums: number[]): number[] {
    const s = nums.reduce((a, b) => a + b);
    let t = 0;
    const n = nums.length;
    const ans = new Array(n);
    for (let i = 0; i < n; ++i) {
        const v = nums[i] * i - t + s - t - nums[i] * (n - i);
        ans[i] = v;
        t += nums[i];
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var getSumAbsoluteDifferences = function (nums) {
    const s = nums.reduce((a, b) => a + b);
    let t = 0;
    const n = nums.length;
    const ans = new Array(n);
    for (let i = 0; i < n; ++i) {
        const v = nums[i] * i - t + s - t - nums[i] * (n - i);
        ans[i] = v;
        t += nums[i];
    }
    return ans;
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int[] GetSumAbsoluteDifferences(int[] nums) {
        int s = 0, t = 0;
        foreach (int x in nums) {
            s += x;
        }
        int n = nums.Length;
        int[] ans = new int[n];
        for (int i = 0; i < n; ++i) {
            int v = nums[i] * i - t + s - t - nums[i] * (n - i);
            ans[i] = v;
            t += nums[i];
        }
        return ans;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个 <strong>非递减 </strong>有序整数数组 <code>nums</code> 。</p>

<p>请你建立并返回一个整数数组<em> </em><code>result</code>，它跟<em> </em><code>nums</code> 长度相同，且<code>result[i]</code> 等于<em> </em><code>nums[i]</code> 与数组中所有其他元素差的绝对值之和。</p>

<p>换句话说， <code>result[i]</code> 等于 <code>sum(|nums[i]-nums[j]|)</code> ，其中 <code>0 <= j < nums.length</code> 且 <code>j != i</code> （下标从 0 开始）。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [2,3,5]
<b>输出：</b>[4,3,5]
<b>解释：</b>假设数组下标从 0 开始，那么
result[0] = |2-2| + |2-3| + |2-5| = 0 + 1 + 3 = 4，
result[1] = |3-2| + |3-3| + |3-5| = 1 + 0 + 2 = 3，
result[2] = |5-2| + |5-3| + |5-5| = 3 + 2 + 0 = 5。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [1,4,6,8,10]
<b>输出：</b>[24,15,13,15,21]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 <= nums.length <= 10<sup>5</sup></code></li>
	<li><code>1 <= nums[i] <= nums[i + 1] <= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：求和 + 枚举

我们先求出数组 $nums$ 所有元素的和，记为 $s$，用变量 $t$ 记录当前已经枚举过的元素之和。

接下来枚举 $nums[i]$，那么 $ans[i] = nums[i] \times i - t + s - t - nums[i] \times (n - i)$，然后我们更新 $t$，即 $t = t + nums[i]$。继续枚举下一个元素，直到枚举完所有元素。

时间复杂度 $O(n)$，其中 $n$ 为数组 $nums$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def getSumAbsoluteDifferences(self, nums: List[int]) -> List[int]:
        ans = []
        s, t = sum(nums), 0
        for i, x in enumerate(nums):
            v = x * i - t + s - t - x * (len(nums) - i)
            ans.append(v)
            t += x
        return ans
```

#### Java

```java
class Solution {
    public int[] getSumAbsoluteDifferences(int[] nums) {
        // int s = Arrays.stream(nums).sum();
        int s = 0, t = 0;
        for (int x : nums) {
            s += x;
        }
        int n = nums.length;
        int[] ans = new int[n];
        for (int i = 0; i < n; ++i) {
            int v = nums[i] * i - t + s - t - nums[i] * (n - i);
            ans[i] = v;
            t += nums[i];
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int s = accumulate(nums.begin(), nums.end(), 0), t = 0;
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            int v = nums[i] * i - t + s - t - nums[i] * (n - i);
            ans[i] = v;
            t += nums[i];
        }
        return ans;
    }
};
```

#### Go

```go
func getSumAbsoluteDifferences(nums []int) (ans []int) {
	var s, t int
	for _, x := range nums {
		s += x
	}
	for i, x := range nums {
		v := x*i - t + s - t - x*(len(nums)-i)
		ans = append(ans, v)
		t += x
	}
	return
}
```

#### TypeScript

```ts
function getSumAbsoluteDifferences(nums: number[]): number[] {
    const s = nums.reduce((a, b) => a + b);
    let t = 0;
    const n = nums.length;
    const ans = new Array(n);
    for (let i = 0; i < n; ++i) {
        const v = nums[i] * i - t + s - t - nums[i] * (n - i);
        ans[i] = v;
        t += nums[i];
    }
    return ans;
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var getSumAbsoluteDifferences = function (nums) {
    const s = nums.reduce((a, b) => a + b);
    let t = 0;
    const n = nums.length;
    const ans = new Array(n);
    for (let i = 0; i < n; ++i) {
        const v = nums[i] * i - t + s - t - nums[i] * (n - i);
        ans[i] = v;
        t += nums[i];
    }
    return ans;
};
```

#### C#

```cs
public class Solution {
    public int[] GetSumAbsoluteDifferences(int[] nums) {
        int s = 0, t = 0;
        foreach (int x in nums) {
            s += x;
        }
        int n = nums.Length;
        int[] ans = new int[n];
        for (int i = 0; i < n; ++i) {
            int v = nums[i] * i - t + s - t - nums[i] * (n - i);
            ans[i] = v;
            t += nums[i];
        }
        return ans;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1686. 石子游戏 VI](https://leetcode.cn/problems/stone-game-vi){#1686}

{{< tabs "1686" >}}

{{% tab "python" %}}
```python
class Solution:
    def stoneGameVI(self, aliceValues: List[int], bobValues: List[int]) -> int:
        vals = [(a + b, i) for i, (a, b) in enumerate(zip(aliceValues, bobValues))]
        vals.sort(reverse=True)
        a = sum(aliceValues[i] for _, i in vals[::2])
        b = sum(bobValues[i] for _, i in vals[1::2])
        if a > b:
            return 1
        if a < b:
            return -1
        return 0
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int stoneGameVI(int[] aliceValues, int[] bobValues) {
        int n = aliceValues.length;
        int[][] vals = new int[n][0];
        for (int i = 0; i < n; ++i) {
            vals[i] = new int[] {aliceValues[i] + bobValues[i], i};
        }
        Arrays.sort(vals, (a, b) -> b[0] - a[0]);
        int a = 0, b = 0;
        for (int k = 0; k < n; ++k) {
            int i = vals[k][1];
            if (k % 2 == 0) {
                a += aliceValues[i];
            } else {
                b += bobValues[i];
            }
        }
        if (a == b) {
            return 0;
        }
        return a > b ? 1 : -1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        vector<pair<int, int>> vals;
        int n = aliceValues.size();
        for (int i = 0; i < n; ++i) {
            vals.emplace_back(aliceValues[i] + bobValues[i], i);
        }
        sort(vals.rbegin(), vals.rend());
        int a = 0, b = 0;
        for (int k = 0; k < n; ++k) {
            int i = vals[k].second;
            if (k % 2 == 0) {
                a += aliceValues[i];
            } else {
                b += bobValues[i];
            }
        }
        if (a == b) {
            return 0;
        }
        return a > b ? 1 : -1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func stoneGameVI(aliceValues []int, bobValues []int) int {
	vals := make([][2]int, len(aliceValues))
	for i, a := range aliceValues {
		vals[i] = [2]int{a + bobValues[i], i}
	}
	slices.SortFunc(vals, func(a, b [2]int) int { return b[0] - a[0] })
	a, b := 0, 0
	for k, v := range vals {
		i := v[1]
		if k%2 == 0 {
			a += aliceValues[i]
		} else {
			b += bobValues[i]
		}
	}
	if a > b {
		return 1
	}
	if a < b {
		return -1
	}
	return 0
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function stoneGameVI(aliceValues: number[], bobValues: number[]): number {
    const n = aliceValues.length;
    const vals: number[][] = [];
    for (let i = 0; i < n; ++i) {
        vals.push([aliceValues[i] + bobValues[i], i]);
    }
    vals.sort((a, b) => b[0] - a[0]);
    let [a, b] = [0, 0];
    for (let k = 0; k < n; ++k) {
        const i = vals[k][1];
        if (k % 2 == 0) {
            a += aliceValues[i];
        } else {
            b += bobValues[i];
        }
    }
    if (a === b) {
        return 0;
    }
    return a > b ? 1 : -1;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>Alice 和 Bob 轮流玩一个游戏，Alice 先手。</p>

<p>一堆石子里总共有 <code>n</code> 个石子，轮到某个玩家时，他可以 <strong>移出</strong> 一个石子并得到这个石子的价值。Alice 和 Bob 对石子价值有 <strong>不一样的的评判标准</strong> 。双方都知道对方的评判标准。</p>

<p>给你两个长度为 <code>n</code> 的整数数组 <code>aliceValues</code> 和 <code>bobValues</code> 。<code>aliceValues[i]</code> 和 <code>bobValues[i]</code> 分别表示 Alice 和 Bob 认为第 <code>i</code> 个石子的价值。</p>

<p>所有石子都被取完后，得分较高的人为胜者。如果两个玩家得分相同，那么为平局。两位玩家都会采用 <b>最优策略</b> 进行游戏。</p>

<p>请你推断游戏的结果，用如下的方式表示：</p>

<ul>
	<li>如果 Alice 赢，返回 <code>1</code> 。</li>
	<li>如果 Bob 赢，返回 <code>-1</code> 。</li>
	<li>如果游戏平局，返回 <code>0</code> 。</li>
</ul>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>aliceValues = [1,3], bobValues = [2,1]
<b>输出：</b>1
<strong>解释：</strong>
如果 Alice 拿石子 1 （下标从 0开始），那么 Alice 可以得到 3 分。
Bob 只能选择石子 0 ，得到 2 分。
Alice 获胜。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>aliceValues = [1,2], bobValues = [3,1]
<b>输出：</b>0
<strong>解释：</strong>
Alice 拿石子 0 ， Bob 拿石子 1 ，他们得分都为 1 分。
打平。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>aliceValues = [2,4,3], bobValues = [1,6,7]
<b>输出：</b>-1
<strong>解释：</strong>
不管 Alice 怎么操作，Bob 都可以得到比 Alice 更高的得分。
比方说，Alice 拿石子 1 ，Bob 拿石子 2 ， Alice 拿石子 0 ，Alice 会得到 6 分而 Bob 得分为 7 分。
Bob 会获胜。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == aliceValues.length == bobValues.length</code></li>
	<li><code>1 <= n <= 10<sup>5</sup></code></li>
	<li><code>1 <= aliceValues[i], bobValues[i] <= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 排序

选取石头的最优化的策略是，让自己得分最高，同时让对手失分最多。因此，我们创建一个数组 $vals$，其中 $vals[i] = (aliceValues[i] + bobValues[i], i)$，表示第 $i$ 个石头的总价值和编号。然后我们对 $vals$ 按照总价值降序排序。

然后我们按照 $vals$ 的顺序，让 Alice 和 Bob 交替选取石头。Alice 选取 $vals$ 中的偶数位置的石头，Bob 选取 $vals$ 中的奇数位置的石头。最后比较 Alice 和 Bob 的得分，返回对应的结果。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$，其中 $n$ 为数组 `aliceValues` 和 `bobValues` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def stoneGameVI(self, aliceValues: List[int], bobValues: List[int]) -> int:
        vals = [(a + b, i) for i, (a, b) in enumerate(zip(aliceValues, bobValues))]
        vals.sort(reverse=True)
        a = sum(aliceValues[i] for _, i in vals[::2])
        b = sum(bobValues[i] for _, i in vals[1::2])
        if a > b:
            return 1
        if a < b:
            return -1
        return 0
```

#### Java

```java
class Solution {
    public int stoneGameVI(int[] aliceValues, int[] bobValues) {
        int n = aliceValues.length;
        int[][] vals = new int[n][0];
        for (int i = 0; i < n; ++i) {
            vals[i] = new int[] {aliceValues[i] + bobValues[i], i};
        }
        Arrays.sort(vals, (a, b) -> b[0] - a[0]);
        int a = 0, b = 0;
        for (int k = 0; k < n; ++k) {
            int i = vals[k][1];
            if (k % 2 == 0) {
                a += aliceValues[i];
            } else {
                b += bobValues[i];
            }
        }
        if (a == b) {
            return 0;
        }
        return a > b ? 1 : -1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        vector<pair<int, int>> vals;
        int n = aliceValues.size();
        for (int i = 0; i < n; ++i) {
            vals.emplace_back(aliceValues[i] + bobValues[i], i);
        }
        sort(vals.rbegin(), vals.rend());
        int a = 0, b = 0;
        for (int k = 0; k < n; ++k) {
            int i = vals[k].second;
            if (k % 2 == 0) {
                a += aliceValues[i];
            } else {
                b += bobValues[i];
            }
        }
        if (a == b) {
            return 0;
        }
        return a > b ? 1 : -1;
    }
};
```

#### Go

```go
func stoneGameVI(aliceValues []int, bobValues []int) int {
	vals := make([][2]int, len(aliceValues))
	for i, a := range aliceValues {
		vals[i] = [2]int{a + bobValues[i], i}
	}
	slices.SortFunc(vals, func(a, b [2]int) int { return b[0] - a[0] })
	a, b := 0, 0
	for k, v := range vals {
		i := v[1]
		if k%2 == 0 {
			a += aliceValues[i]
		} else {
			b += bobValues[i]
		}
	}
	if a > b {
		return 1
	}
	if a < b {
		return -1
	}
	return 0
}
```

#### TypeScript

```ts
function stoneGameVI(aliceValues: number[], bobValues: number[]): number {
    const n = aliceValues.length;
    const vals: number[][] = [];
    for (let i = 0; i < n; ++i) {
        vals.push([aliceValues[i] + bobValues[i], i]);
    }
    vals.sort((a, b) => b[0] - a[0]);
    let [a, b] = [0, 0];
    for (let k = 0; k < n; ++k) {
        const i = vals[k][1];
        if (k % 2 == 0) {
            a += aliceValues[i];
        } else {
            b += bobValues[i];
        }
    }
    if (a === b) {
        return 0;
    }
    return a > b ? 1 : -1;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1687. 从仓库到码头运输箱子](https://leetcode.cn/problems/delivering-boxes-from-storage-to-ports){#1687}

{{< tabs "1687" >}}

{{% tab "python" %}}
```python
class Solution:
    def boxDelivering(
        self, boxes: List[List[int]], portsCount: int, maxBoxes: int, maxWeight: int
    ) -> int:
        n = len(boxes)
        ws = list(accumulate((box[1] for box in boxes), initial=0))
        c = [int(a != b) for a, b in pairwise(box[0] for box in boxes)]
        cs = list(accumulate(c, initial=0))
        f = [0] * (n + 1)
        q = deque([0])
        for i in range(1, n + 1):
            while q and (i - q[0] > maxBoxes or ws[i] - ws[q[0]] > maxWeight):
                q.popleft()
            if q:
                f[i] = cs[i - 1] + f[q[0]] - cs[q[0]] + 2
            if i < n:
                while q and f[q[-1]] - cs[q[-1]] >= f[i] - cs[i]:
                    q.pop()
                q.append(i)
        return f[n]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int boxDelivering(int[][] boxes, int portsCount, int maxBoxes, int maxWeight) {
        int n = boxes.length;
        long[] ws = new long[n + 1];
        int[] cs = new int[n];
        for (int i = 0; i < n; ++i) {
            int p = boxes[i][0], w = boxes[i][1];
            ws[i + 1] = ws[i] + w;
            if (i < n - 1) {
                cs[i + 1] = cs[i] + (p != boxes[i + 1][0] ? 1 : 0);
            }
        }
        int[] f = new int[n + 1];
        Deque<Integer> q = new ArrayDeque<>();
        q.offer(0);
        for (int i = 1; i <= n; ++i) {
            while (!q.isEmpty()
                && (i - q.peekFirst() > maxBoxes || ws[i] - ws[q.peekFirst()] > maxWeight)) {
                q.pollFirst();
            }
            if (!q.isEmpty()) {
                f[i] = cs[i - 1] + f[q.peekFirst()] - cs[q.peekFirst()] + 2;
            }
            if (i < n) {
                while (!q.isEmpty() && f[q.peekLast()] - cs[q.peekLast()] >= f[i] - cs[i]) {
                    q.pollLast();
                }
                q.offer(i);
            }
        }
        return f[n];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) {
        int n = boxes.size();
        long ws[n + 1];
        int f[n + 1];
        int cs[n];
        ws[0] = cs[0] = f[0] = 0;
        for (int i = 0; i < n; ++i) {
            int p = boxes[i][0], w = boxes[i][1];
            ws[i + 1] = ws[i] + w;
            if (i < n - 1) cs[i + 1] = cs[i] + (p != boxes[i + 1][0]);
        }
        deque<int> q{{0}};
        for (int i = 1; i <= n; ++i) {
            while (!q.empty() && (i - q.front() > maxBoxes || ws[i] - ws[q.front()] > maxWeight)) q.pop_front();
            if (!q.empty()) f[i] = cs[i - 1] + f[q.front()] - cs[q.front()] + 2;
            if (i < n) {
                while (!q.empty() && f[q.back()] - cs[q.back()] >= f[i] - cs[i]) q.pop_back();
                q.push_back(i);
            }
        }
        return f[n];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func boxDelivering(boxes [][]int, portsCount int, maxBoxes int, maxWeight int) int {
	n := len(boxes)
	ws := make([]int, n+1)
	cs := make([]int, n)
	for i, box := range boxes {
		p, w := box[0], box[1]
		ws[i+1] = ws[i] + w
		if i < n-1 {
			t := 0
			if p != boxes[i+1][0] {
				t++
			}
			cs[i+1] = cs[i] + t
		}
	}
	f := make([]int, n+1)
	q := []int{0}
	for i := 1; i <= n; i++ {
		for len(q) > 0 && (i-q[0] > maxBoxes || ws[i]-ws[q[0]] > maxWeight) {
			q = q[1:]
		}
		if len(q) > 0 {
			f[i] = cs[i-1] + f[q[0]] - cs[q[0]] + 2
		}
		if i < n {
			for len(q) > 0 && f[q[len(q)-1]]-cs[q[len(q)-1]] >= f[i]-cs[i] {
				q = q[:len(q)-1]
			}
			q = append(q, i)
		}
	}
	return f[n]
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你有一辆货运卡车，你需要用这一辆车把一些箱子从仓库运送到码头。这辆卡车每次运输有&nbsp;<strong>箱子数目的限制</strong>&nbsp;和 <strong>总重量的限制</strong>&nbsp;。</p>

<p>给你一个箱子数组&nbsp;<code>boxes</code>&nbsp;和三个整数 <code>portsCount</code>, <code>maxBoxes</code>&nbsp;和&nbsp;<code>maxWeight</code>&nbsp;，其中&nbsp;<code>boxes[i] = [ports<sub>​​i</sub>​, weight<sub>i</sub>]</code>&nbsp;。</p>

<ul>
	<li><code>ports<sub>​​i</sub></code>&nbsp;表示第&nbsp;<code>i</code>&nbsp;个箱子需要送达的码头，&nbsp;<code>weights<sub>i</sub></code>&nbsp;是第&nbsp;<code>i</code>&nbsp;个箱子的重量。</li>
	<li><code>portsCount</code>&nbsp;是码头的数目。</li>
	<li><code>maxBoxes</code> 和&nbsp;<code>maxWeight</code>&nbsp;分别是卡车每趟运输箱子数目和重量的限制。</li>
</ul>

<p>箱子需要按照 <strong>数组顺序</strong>&nbsp;运输，同时每次运输需要遵循以下步骤：</p>

<ul>
	<li>卡车从&nbsp;<code>boxes</code>&nbsp;队列中按顺序取出若干个箱子，但不能违反&nbsp;<code>maxBoxes</code> 和&nbsp;<code>maxWeight</code>&nbsp;限制。</li>
	<li>对于在卡车上的箱子，我们需要 <strong>按顺序</strong>&nbsp;处理它们，卡车会通过 <strong>一趟行程</strong>&nbsp;将最前面的箱子送到目的地码头并卸货。如果卡车已经在对应的码头，那么不需要 <strong>额外行程</strong>&nbsp;，箱子也会立马被卸货。</li>
	<li>卡车上所有箱子都被卸货后，卡车需要 <strong>一趟行程</strong>&nbsp;回到仓库，从箱子队列里再取出一些箱子。</li>
</ul>

<p>卡车在将所有箱子运输并卸货后，最后必须回到仓库。</p>

<p>请你返回将所有箱子送到相应码头的&nbsp;<b>最少行程</b>&nbsp;次数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>boxes = [[1,1],[2,1],[1,1]], portsCount = 2, maxBoxes = 3, maxWeight = 3
<b>输出：</b>4
<b>解释：</b>最优策略如下：
- 卡车将所有箱子装上车，到达码头 1 ，然后去码头 2 ，然后再回到码头 1 ，最后回到仓库，总共需要 4 趟行程。
所以总行程数为 4 。
注意到第一个和第三个箱子不能同时被卸货，因为箱子需要按顺序处理（也就是第二个箱子需要先被送到码头 2 ，然后才能处理第三个箱子）。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>boxes = [[1,2],[3,3],[3,1],[3,1],[2,4]], portsCount = 3, maxBoxes = 3, maxWeight = 6
<b>输出：</b>6
<b>解释：</b>最优策略如下：
- 卡车首先运输第一个箱子，到达码头 1 ，然后回到仓库，总共 2 趟行程。
- 卡车运输第二、第三、第四个箱子，到达码头 3 ，然后回到仓库，总共 2 趟行程。
- 卡车运输第五个箱子，到达码头 2 ，回到仓库，总共 2 趟行程。
总行程数为 2 + 2 + 2 = 6 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>boxes = [[1,4],[1,2],[2,1],[2,1],[3,2],[3,4]], portsCount = 3, maxBoxes = 6, maxWeight = 7
<b>输出：</b>6
<b>解释：</b>最优策略如下：
- 卡车运输第一和第二个箱子，到达码头 1 ，然后回到仓库，总共 2 趟行程。
- 卡车运输第三和第四个箱子，到达码头 2 ，然后回到仓库，总共 2 趟行程。
- 卡车运输第五和第六个箱子，到达码头 3 ，然后回到仓库，总共 2 趟行程。
总行程数为 2 + 2 + 2 = 6 。
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<b>输入：</b>boxes = [[2,4],[2,5],[3,1],[3,2],[3,7],[3,1],[4,4],[1,3],[5,2]], portsCount = 5, maxBoxes = 5, maxWeight = 7
<b>输出：</b>14
<b>解释：</b>最优策略如下：
- 卡车运输第一个箱子，到达码头 2 ，然后回到仓库，总共 2 趟行程。
- 卡车运输第二个箱子，到达码头 2 ，然后回到仓库，总共 2 趟行程。
- 卡车运输第三和第四个箱子，到达码头 3 ，然后回到仓库，总共 2 趟行程。
- 卡车运输第五个箱子，到达码头 3 ，然后回到仓库，总共 2 趟行程。
- 卡车运输第六和第七个箱子，到达码头 3 ，然后去码头 4 ，然后回到仓库，总共 3 趟行程。
- 卡车运输第八和第九个箱子，到达码头 1 ，然后去码头 5 ，然后回到仓库，总共 3 趟行程。
总行程数为 2 + 2 + 2 + 2 + 3 + 3 = 14 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= boxes.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= portsCount, maxBoxes, maxWeight &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= ports<sub>​​i</sub> &lt;= portsCount</code></li>
	<li><code>1 &lt;= weights<sub>i</sub> &lt;= maxWeight</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划 + 单调队列优化

我们定义 $f[i]$ 表示把前 $i$ 个箱子从仓库运送到相应码头的最少行程数，那么答案就是 $f[n]$。

箱子需要按数组顺序运输，每一次运输，卡车会按顺序取出连续的几个箱子，然后依次送往对应的码头，全部送达之后，又回到了仓库。

因此，我们可以枚举上一次运输的最后一个箱子的编号 $j$，那么 $f[i]$ 就可以从 $f[j]$ 转移而来，转移的时候，我们需要考虑以下几个问题：

-   从 $f[j]$ 转移过来的时候，卡车上的箱子数量不能超过 $maxBoxes$
-   从 $f[j]$ 转移过来的时候，卡车上的箱子总重量不能超过 $maxWeight$

状态转移方程为：

$$
f[i] = \min_{j \in [i - maxBoxes, i - 1]} \left(f[j] + \sum_{k = j + 1}^i \textit{cost}(k)\right)
$$

其中 $\sum_{k = j + 1}^i \textit{cost}(k)$ 表示通过一次运输，把 $[j+1,..i]$ 这些箱子送往对应的码头所需要的行程数。这部分行程数可以通过前缀和快速计算出来。

简单举个例子，假设我们取出了 $1, 2, 3$ 这三个箱子，需要送往 $4, 4, 5$ 这三个码头，那么我们首先要从仓库到 $4$ 号码头，然后再从 $4$ 号码头到 $5$ 号码头，最后再从 $5$ 号码头回到仓库。可以发现，从仓库到码头，以及从码头到仓库，需要花费 $2$ 趟行程，而从码头到码头的行程数，取决于相邻两个码头是否相同，如果不相同，那么行程数会增加 $1$，否则不变。因此，我们可以通过前缀和，计算出码头之间的行程数，再加上首尾两趟行程，就能把 $[j+1,..i]$ 这些箱子送往对应的码头所需要的行程数计算出来。

代码实现如下：

<!-- tabs:start -->

#### Python3

```python
# 33/39 个通过测试用例，超出时间限制
class Solution:
    def boxDelivering(
        self, boxes: List[List[int]], portsCount: int, maxBoxes: int, maxWeight: int
    ) -> int:
        n = len(boxes)
        ws = list(accumulate((box[1] for box in boxes), initial=0))
        c = [int(a != b) for a, b in pairwise(box[0] for box in boxes)]
        cs = list(accumulate(c, initial=0))
        f = [inf] * (n + 1)
        f[0] = 0
        for i in range(1, n + 1):
            for j in range(max(0, i - maxBoxes), i):
                if ws[i] - ws[j] <= maxWeight:
                    f[i] = min(f[i], f[j] + cs[i - 1] - cs[j] + 2)
        return f[n]
```

#### Java

```java
// 35/39 个通过测试用例，超出时间限制
class Solution {
    public int boxDelivering(int[][] boxes, int portsCount, int maxBoxes, int maxWeight) {
        int n = boxes.length;
        long[] ws = new long[n + 1];
        int[] cs = new int[n];
        for (int i = 0; i < n; ++i) {
            int p = boxes[i][0], w = boxes[i][1];
            ws[i + 1] = ws[i] + w;
            if (i < n - 1) {
                cs[i + 1] = cs[i] + (p != boxes[i + 1][0] ? 1 : 0);
            }
        }
        int[] f = new int[n + 1];
        Arrays.fill(f, 1 << 30);
        f[0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = Math.max(0, i - maxBoxes); j < i; ++j) {
                if (ws[i] - ws[j] <= maxWeight) {
                    f[i] = Math.min(f[i], f[j] + cs[i - 1] - cs[j] + 2);
                }
            }
        }
        return f[n];
    }
}
```

#### C++

```cpp
// 35/39 个通过测试用例，超出时间限制
class Solution {
public:
    int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) {
        int n = boxes.size();
        long ws[n + 1];
        int cs[n];
        ws[0] = cs[0] = 0;
        for (int i = 0; i < n; ++i) {
            int p = boxes[i][0], w = boxes[i][1];
            ws[i + 1] = ws[i] + w;
            if (i < n - 1) cs[i + 1] = cs[i] + (p != boxes[i + 1][0]);
        }
        int f[n + 1];
        memset(f, 0x3f, sizeof f);
        f[0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = max(0, i - maxBoxes); j < i; ++j) {
                if (ws[i] - ws[j] <= maxWeight) {
                    f[i] = min(f[i], f[j] + cs[i - 1] - cs[j] + 2);
                }
            }
        }
        return f[n];
    }
};
```

#### Go

```go
// 35/39 个通过测试用例，超出时间限制
func boxDelivering(boxes [][]int, portsCount int, maxBoxes int, maxWeight int) int {
	n := len(boxes)
	ws := make([]int, n+1)
	cs := make([]int, n)
	for i, box := range boxes {
		p, w := box[0], box[1]
		ws[i+1] = ws[i] + w
		if i < n-1 {
			t := 0
			if p != boxes[i+1][0] {
				t++
			}
			cs[i+1] = cs[i] + t
		}
	}
	f := make([]int, n+1)
	for i := 1; i <= n; i++ {
		f[i] = 1 << 30
		for j := max(0, i-maxBoxes); j < i; j++ {
			if ws[i]-ws[j] <= maxWeight {
				f[i] = min(f[i], f[j]+cs[i-1]-cs[j]+2)
			}
		}
	}
	return f[n]
}
```

<!-- tabs:end -->

本题数据规模达到 $10^5$，而以上代码的时间复杂度为 $O(n^2)$，会超出时间限制。我们仔细观察：

$$
f[i] = \min(f[i], f[j] + cs[i - 1] - cs[j] + 2)
$$

实际上我们是要在 $[i-maxBoxes,..i-1]$ 这个窗口内找到一个 $j$，使得 $f[j] - cs[j]$ 的值最小，求滑动窗口的最小值，一种常用的做法是使用单调队列，可以在 $O(1)$ 时间内获取到满足条件的最小值。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是题目中箱子的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def boxDelivering(
        self, boxes: List[List[int]], portsCount: int, maxBoxes: int, maxWeight: int
    ) -> int:
        n = len(boxes)
        ws = list(accumulate((box[1] for box in boxes), initial=0))
        c = [int(a != b) for a, b in pairwise(box[0] for box in boxes)]
        cs = list(accumulate(c, initial=0))
        f = [0] * (n + 1)
        q = deque([0])
        for i in range(1, n + 1):
            while q and (i - q[0] > maxBoxes or ws[i] - ws[q[0]] > maxWeight):
                q.popleft()
            if q:
                f[i] = cs[i - 1] + f[q[0]] - cs[q[0]] + 2
            if i < n:
                while q and f[q[-1]] - cs[q[-1]] >= f[i] - cs[i]:
                    q.pop()
                q.append(i)
        return f[n]
```

#### Java

```java
class Solution {
    public int boxDelivering(int[][] boxes, int portsCount, int maxBoxes, int maxWeight) {
        int n = boxes.length;
        long[] ws = new long[n + 1];
        int[] cs = new int[n];
        for (int i = 0; i < n; ++i) {
            int p = boxes[i][0], w = boxes[i][1];
            ws[i + 1] = ws[i] + w;
            if (i < n - 1) {
                cs[i + 1] = cs[i] + (p != boxes[i + 1][0] ? 1 : 0);
            }
        }
        int[] f = new int[n + 1];
        Deque<Integer> q = new ArrayDeque<>();
        q.offer(0);
        for (int i = 1; i <= n; ++i) {
            while (!q.isEmpty()
                && (i - q.peekFirst() > maxBoxes || ws[i] - ws[q.peekFirst()] > maxWeight)) {
                q.pollFirst();
            }
            if (!q.isEmpty()) {
                f[i] = cs[i - 1] + f[q.peekFirst()] - cs[q.peekFirst()] + 2;
            }
            if (i < n) {
                while (!q.isEmpty() && f[q.peekLast()] - cs[q.peekLast()] >= f[i] - cs[i]) {
                    q.pollLast();
                }
                q.offer(i);
            }
        }
        return f[n];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) {
        int n = boxes.size();
        long ws[n + 1];
        int f[n + 1];
        int cs[n];
        ws[0] = cs[0] = f[0] = 0;
        for (int i = 0; i < n; ++i) {
            int p = boxes[i][0], w = boxes[i][1];
            ws[i + 1] = ws[i] + w;
            if (i < n - 1) cs[i + 1] = cs[i] + (p != boxes[i + 1][0]);
        }
        deque<int> q{{0}};
        for (int i = 1; i <= n; ++i) {
            while (!q.empty() && (i - q.front() > maxBoxes || ws[i] - ws[q.front()] > maxWeight)) q.pop_front();
            if (!q.empty()) f[i] = cs[i - 1] + f[q.front()] - cs[q.front()] + 2;
            if (i < n) {
                while (!q.empty() && f[q.back()] - cs[q.back()] >= f[i] - cs[i]) q.pop_back();
                q.push_back(i);
            }
        }
        return f[n];
    }
};
```

#### Go

```go
func boxDelivering(boxes [][]int, portsCount int, maxBoxes int, maxWeight int) int {
	n := len(boxes)
	ws := make([]int, n+1)
	cs := make([]int, n)
	for i, box := range boxes {
		p, w := box[0], box[1]
		ws[i+1] = ws[i] + w
		if i < n-1 {
			t := 0
			if p != boxes[i+1][0] {
				t++
			}
			cs[i+1] = cs[i] + t
		}
	}
	f := make([]int, n+1)
	q := []int{0}
	for i := 1; i <= n; i++ {
		for len(q) > 0 && (i-q[0] > maxBoxes || ws[i]-ws[q[0]] > maxWeight) {
			q = q[1:]
		}
		if len(q) > 0 {
			f[i] = cs[i-1] + f[q[0]] - cs[q[0]] + 2
		}
		if i < n {
			for len(q) > 0 && f[q[len(q)-1]]-cs[q[len(q)-1]] >= f[i]-cs[i] {
				q = q[:len(q)-1]
			}
			q = append(q, i)
		}
	}
	return f[n]
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1688. 比赛中的配对次数](https://leetcode.cn/problems/count-of-matches-in-tournament){#1688}

{{< tabs "1688" >}}

{{% tab "python" %}}
```python
class Solution:
    def numberOfMatches(self, n: int) -> int:
        return n - 1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numberOfMatches(int n) {
        return n - 1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int numberOfMatches(int n) {
        return n - 1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numberOfMatches(n int) int {
	return n - 1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numberOfMatches(n: number): number {
    return n - 1;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number} n
 * @return {number}
 */
var numberOfMatches = function (n) {
    return n - 1;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数 <code>n</code> ，表示比赛中的队伍数。比赛遵循一种独特的赛制：</p>

<ul>
	<li>如果当前队伍数是 <strong>偶数</strong> ，那么每支队伍都会与另一支队伍配对。总共进行 <code>n / 2</code> 场比赛，且产生 <code>n / 2</code> 支队伍进入下一轮。</li>
	<li>如果当前队伍数为 <strong>奇数</strong> ，那么将会随机轮空并晋级一支队伍，其余的队伍配对。总共进行 <code>(n - 1) / 2</code> 场比赛，且产生 <code>(n - 1) / 2 + 1</code> 支队伍进入下一轮。</li>
</ul>

<p>返回在比赛中进行的配对次数，直到决出获胜队伍为止。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>n = 7
<strong>输出：</strong>6
<strong>解释：</strong>比赛详情：
- 第 1 轮：队伍数 = 7 ，配对次数 = 3 ，4 支队伍晋级。
- 第 2 轮：队伍数 = 4 ，配对次数 = 2 ，2 支队伍晋级。
- 第 3 轮：队伍数 = 2 ，配对次数 = 1 ，决出 1 支获胜队伍。
总配对次数 = 3 + 2 + 1 = 6
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>n = 14
<strong>输出：</strong>13
<strong>解释：</strong>比赛详情：
- 第 1 轮：队伍数 = 14 ，配对次数 = 7 ，7 支队伍晋级。
- 第 2 轮：队伍数 = 7 ，配对次数 = 3 ，4 支队伍晋级。 
- 第 3 轮：队伍数 = 4 ，配对次数 = 2 ，2 支队伍晋级。
- 第 4 轮：队伍数 = 2 ，配对次数 = 1 ，决出 1 支获胜队伍。
总配对次数 = 7 + 3 + 2 + 1 = 13
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 200</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：脑筋急转弯

根据题目描述我们知道，一共有 $n$ 支队伍，每一次的配对，都会淘汰一支队伍，所以配对次数就是淘汰的队伍数，即 $n - 1$。

时间复杂度 $O(1)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numberOfMatches(self, n: int) -> int:
        return n - 1
```

#### Java

```java
class Solution {
    public int numberOfMatches(int n) {
        return n - 1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numberOfMatches(int n) {
        return n - 1;
    }
};
```

#### Go

```go
func numberOfMatches(n int) int {
	return n - 1
}
```

#### TypeScript

```ts
function numberOfMatches(n: number): number {
    return n - 1;
}
```

#### JavaScript

```js
/**
 * @param {number} n
 * @return {number}
 */
var numberOfMatches = function (n) {
    return n - 1;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1689. 十-二进制数的最少数目](https://leetcode.cn/problems/partitioning-into-minimum-number-of-deci-binary-numbers){#1689}

{{< tabs "1689" >}}

{{% tab "python" %}}
```python
class Solution:
    def minPartitions(self, n: str) -> int:
        return int(max(n))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minPartitions(String n) {
        int ans = 0;
        for (int i = 0; i < n.length(); ++i) {
            ans = Math.max(ans, n.charAt(i) - '0');
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
    int minPartitions(string n) {
        int ans = 0;
        for (char& c : n) {
            ans = max(ans, c - '0');
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minPartitions(n string) (ans int) {
	for _, c := range n {
		if t := int(c - '0'); ans < t {
			ans = t
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minPartitions(n: string): number {
    return Math.max(...n.split('').map(d => parseInt(d)));
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn min_partitions(n: String) -> i32 {
        let mut ans = 0;
        for c in n.as_bytes() {
            ans = ans.max((c - b'0') as i32);
        }
        ans
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
int minPartitions(char* n) {
    int ans = 0;
    for (int i = 0; n[i]; i++) {
        int v = n[i] - '0';
        if (v > ans) {
            ans = v;
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

<p>如果一个十进制数字不含任何前导零，且每一位上的数字不是 <code>0</code> 就是 <code>1</code> ，那么该数字就是一个 <strong>十-二进制数</strong> 。例如，<code>101</code> 和 <code>1100</code> 都是 <strong>十-二进制数</strong>，而 <code>112</code> 和 <code>3001</code> 不是。</p>

<p>给你一个表示十进制整数的字符串 <code>n</code> ，返回和为 <code>n</code> 的 <strong>十-二进制数 </strong>的最少数目。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>n = "32"
<strong>输出：</strong>3
<strong>解释：</strong>10 + 11 + 11 = 32
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>n = "82734"
<strong>输出：</strong>8
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>n = "27346209830709182346"
<strong>输出：</strong>9
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n.length &lt;= 10<sup>5</sup></code></li>
	<li><code>n</code> 仅由数字组成</li>
	<li><code>n</code> 不含任何前导零并总是表示正整数</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：脑筋急转弯

题目等价于找字符串中的最大数。

时间复杂度 $O(n)$，其中 $n$ 为字符串长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minPartitions(self, n: str) -> int:
        return int(max(n))
```

#### Java

```java
class Solution {
    public int minPartitions(String n) {
        int ans = 0;
        for (int i = 0; i < n.length(); ++i) {
            ans = Math.max(ans, n.charAt(i) - '0');
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minPartitions(string n) {
        int ans = 0;
        for (char& c : n) {
            ans = max(ans, c - '0');
        }
        return ans;
    }
};
```

#### Go

```go
func minPartitions(n string) (ans int) {
	for _, c := range n {
		if t := int(c - '0'); ans < t {
			ans = t
		}
	}
	return
}
```

#### TypeScript

```ts
function minPartitions(n: string): number {
    return Math.max(...n.split('').map(d => parseInt(d)));
}
```

#### Rust

```rust
impl Solution {
    pub fn min_partitions(n: String) -> i32 {
        let mut ans = 0;
        for c in n.as_bytes() {
            ans = ans.max((c - b'0') as i32);
        }
        ans
    }
}
```

#### C

```c
int minPartitions(char* n) {
    int ans = 0;
    for (int i = 0; n[i]; i++) {
        int v = n[i] - '0';
        if (v > ans) {
            ans = v;
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
