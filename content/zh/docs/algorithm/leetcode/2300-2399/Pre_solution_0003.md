---
title: "2320_统计放置房子的方式数"
date: 2025-10-08T18:39:12+08:00
weight: 3
tags: [位运算, 动态规划, 哈希表, 图, 字符串, 广度优先搜索, 拓扑排序, 排序, 数据库, 数组, 树, 模拟, 深度优先搜索, 矩阵, 记忆化搜索, 贪心, 链表, 队列]
---

{{< markmap >}}
### [2320_统计放置房子的方式数](#2320)
#### [动态规划](#2320)
### [2321_拼接数组的最大分数](#2321)
#### [数组](#2321)
#### [动态规划](#2321)
### [2322_从树中删除边的最小分数](#2322)
#### [位运算](#2322)
#### [树](#2322)
#### [深度优先搜索](#2322)
#### [数组](#2322)
### [2323_完成所有工作的最短时间 II 🔒](#2323)
#### [贪心](#2323)
#### [数组](#2323)
#### [排序](#2323)
### [2324_产品销售分析 IV 🔒](#2324)
#### [数据库](#2324)
### [2325_解密消息](#2325)
#### [哈希表](#2325)
#### [字符串](#2325)
### [2326_螺旋矩阵 IV](#2326)
#### [数组](#2326)
#### [链表](#2326)
#### [矩阵](#2326)
#### [模拟](#2326)
### [2327_知道秘密的人数](#2327)
#### [队列](#2327)
#### [动态规划](#2327)
#### [模拟](#2327)
### [2328_网格图中递增路径的数目](#2328)
#### [深度优先搜索](#2328)
#### [广度优先搜索](#2328)
#### [图](#2328)
#### [拓扑排序](#2328)
#### [记忆化搜索](#2328)
#### [数组](#2328)
#### [动态规划](#2328)
#### [矩阵](#2328)
### [2329_产品销售分析Ⅴ 🔒](#2329)
#### [数据库](#2329)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2320_统计放置房子的方式数
___
#### 动态规划
---
### 2321_拼接数组的最大分数
___
#### 数组
___
#### 动态规划
---
### 2322_从树中删除边的最小分数
___
#### 位运算
___
#### 树
___
#### 深度优先搜索
___
#### 数组
---
### 2323_完成所有工作的最短时间 II 🔒
___
#### 贪心
___
#### 数组
___
#### 排序
---
### 2324_产品销售分析 IV 🔒
___
#### 数据库
---
### 2325_解密消息
___
#### 哈希表
___
#### 字符串
---
### 2326_螺旋矩阵 IV
___
#### 数组
___
#### 链表
___
#### 矩阵
___
#### 模拟
---
### 2327_知道秘密的人数
___
#### 队列
___
#### 动态规划
___
#### 模拟
---
### 2328_网格图中递增路径的数目
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 图
___
#### 拓扑排序
___
#### 记忆化搜索
___
#### 数组
___
#### 动态规划
___
#### 矩阵
---
### 2329_产品销售分析Ⅴ 🔒
___
#### 数据库
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 位运算 | 动态规划 | 哈希表 |
| 图 | 字符串 | 广度优先搜索 |
| 拓扑排序 | 排序 | 数据库 |
| 数组 | 树 | 模拟 |
| 深度优先搜索 | 矩阵 | 记忆化搜索 |
| 贪心 | 链表 | 队列 |

# [2320. 统计放置房子的方式数](https://leetcode.cn/problems/count-number-of-ways-to-place-houses){#2320}

{{< tabs "2320" >}}

{{% tab "python" %}}
```python
class Solution:
    def countHousePlacements(self, n: int) -> int:
        mod = 10**9 + 7
        f = [1] * n
        g = [1] * n
        for i in range(1, n):
            f[i] = g[i - 1]
            g[i] = (f[i - 1] + g[i - 1]) % mod
        v = f[-1] + g[-1]
        return v * v % mod
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countHousePlacements(int n) {
        final int mod = (int) 1e9 + 7;
        int[] f = new int[n];
        int[] g = new int[n];
        f[0] = 1;
        g[0] = 1;
        for (int i = 1; i < n; ++i) {
            f[i] = g[i - 1];
            g[i] = (f[i - 1] + g[i - 1]) % mod;
        }
        long v = (f[n - 1] + g[n - 1]) % mod;
        return (int) (v * v % mod);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int countHousePlacements(int n) {
        const int mod = 1e9 + 7;
        int f[n], g[n];
        f[0] = g[0] = 1;
        for (int i = 1; i < n; ++i) {
            f[i] = g[i - 1];
            g[i] = (f[i - 1] + g[i - 1]) % mod;
        }
        long v = f[n - 1] + g[n - 1];
        return v * v % mod;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countHousePlacements(n int) int {
	const mod = 1e9 + 7
	f := make([]int, n)
	g := make([]int, n)
	f[0], g[0] = 1, 1
	for i := 1; i < n; i++ {
		f[i] = g[i-1]
		g[i] = (f[i-1] + g[i-1]) % mod
	}
	v := f[n-1] + g[n-1]
	return v * v % mod
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countHousePlacements(n: number): number {
    const f = new Array(n);
    const g = new Array(n);
    f[0] = g[0] = 1n;
    const mod = BigInt(10 ** 9 + 7);
    for (let i = 1; i < n; ++i) {
        f[i] = g[i - 1];
        g[i] = (f[i - 1] + g[i - 1]) % mod;
    }
    const v = f[n - 1] + g[n - 1];
    return Number(v ** 2n % mod);
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int CountHousePlacements(int n) {
        const int mod = (int) 1e9 + 7;
        int[] f = new int[n];
        int[] g = new int[n];
        f[0] = g[0] = 1;
        for (int i = 1; i < n; ++i) {
            f[i] = g[i - 1];
            g[i] = (f[i - 1] + g[i - 1]) % mod;
        }
        long v = (f[n - 1] + g[n - 1]) % mod;
        return (int) (v * v % mod);
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>一条街道上共有 <code>n * 2</code> 个 <strong>地块</strong> ，街道的两侧各有 <code>n</code> 个地块。每一边的地块都按从 <code>1</code> 到 <code>n</code> 编号。每个地块上都可以放置一所房子。</p>

<p>现要求街道同一侧不能存在两所房子相邻的情况，请你计算并返回放置房屋的方式数目。由于答案可能很大，需要对 <code>10<sup>9</sup> + 7</code> 取余后再返回。</p>

<p>注意，如果一所房子放置在这条街某一侧上的第 <code>i</code> 个地块，不影响在另一侧的第 <code>i</code> 个地块放置房子。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>n = 1
<strong>输出：</strong>4
<strong>解释：</strong>
可能的放置方式：
1. 所有地块都不放置房子。
2. 一所房子放在街道的某一侧。
3. 一所房子放在街道的另一侧。
4. 放置两所房子，街道两侧各放置一所。
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2300-2399/2320.Count%20Number%20of%20Ways%20to%20Place%20Houses/images/arrangements.png" style="width: 500px; height: 500px;">
<pre><strong>输入：</strong>n = 2
<strong>输出：</strong>9
<strong>解释：</strong>如上图所示，共有 9 种可能的放置方式。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

由于街道两侧房子的摆放互不影响，因此，我们可以只考虑一侧的摆放情况，最后将一侧的方案数平方取模得到最终结果。

我们定义 $f[i]$ 表示放置前 $i+1$ 个地块，且最后一个地块放置房子的方案数，定义 $g[i]$ 表示放置前 $i+1$ 个地块，且最后一个地块不放置房子的方案数。初始时 $f[0] = g[0] = 1$。

当我们放置第 $i+1$ 个地块时，有两种情况：

-   如果第 $i+1$ 个地块放置房子，那么第 $i$ 个地块必须不放置房子，因此方案数 $f[i]=g[i-1]$；
-   如果第 $i+1$ 个地块不放置房子，那么第 $i$ 个地块可以放置房子，也可以不放置房子，因此方案数 $g[i]=f[i-1]+g[i-1]$。

最终，我们将 $f[n-1]+g[n-1]$ 的平方取模即为答案。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为街道的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countHousePlacements(self, n: int) -> int:
        mod = 10**9 + 7
        f = [1] * n
        g = [1] * n
        for i in range(1, n):
            f[i] = g[i - 1]
            g[i] = (f[i - 1] + g[i - 1]) % mod
        v = f[-1] + g[-1]
        return v * v % mod
```

#### Java

```java
class Solution {
    public int countHousePlacements(int n) {
        final int mod = (int) 1e9 + 7;
        int[] f = new int[n];
        int[] g = new int[n];
        f[0] = 1;
        g[0] = 1;
        for (int i = 1; i < n; ++i) {
            f[i] = g[i - 1];
            g[i] = (f[i - 1] + g[i - 1]) % mod;
        }
        long v = (f[n - 1] + g[n - 1]) % mod;
        return (int) (v * v % mod);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int countHousePlacements(int n) {
        const int mod = 1e9 + 7;
        int f[n], g[n];
        f[0] = g[0] = 1;
        for (int i = 1; i < n; ++i) {
            f[i] = g[i - 1];
            g[i] = (f[i - 1] + g[i - 1]) % mod;
        }
        long v = f[n - 1] + g[n - 1];
        return v * v % mod;
    }
};
```

#### Go

```go
func countHousePlacements(n int) int {
	const mod = 1e9 + 7
	f := make([]int, n)
	g := make([]int, n)
	f[0], g[0] = 1, 1
	for i := 1; i < n; i++ {
		f[i] = g[i-1]
		g[i] = (f[i-1] + g[i-1]) % mod
	}
	v := f[n-1] + g[n-1]
	return v * v % mod
}
```

#### TypeScript

```ts
function countHousePlacements(n: number): number {
    const f = new Array(n);
    const g = new Array(n);
    f[0] = g[0] = 1n;
    const mod = BigInt(10 ** 9 + 7);
    for (let i = 1; i < n; ++i) {
        f[i] = g[i - 1];
        g[i] = (f[i - 1] + g[i - 1]) % mod;
    }
    const v = f[n - 1] + g[n - 1];
    return Number(v ** 2n % mod);
}
```

#### C#

```cs
public class Solution {
    public int CountHousePlacements(int n) {
        const int mod = (int) 1e9 + 7;
        int[] f = new int[n];
        int[] g = new int[n];
        f[0] = g[0] = 1;
        for (int i = 1; i < n; ++i) {
            f[i] = g[i - 1];
            g[i] = (f[i - 1] + g[i - 1]) % mod;
        }
        long v = (f[n - 1] + g[n - 1]) % mod;
        return (int) (v * v % mod);
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2321. 拼接数组的最大分数](https://leetcode.cn/problems/maximum-score-of-spliced-array){#2321}

{{< tabs "2321" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumsSplicedArray(self, nums1: List[int], nums2: List[int]) -> int:
        def f(nums1, nums2):
            d = [a - b for a, b in zip(nums1, nums2)]
            t = mx = d[0]
            for v in d[1:]:
                if t > 0:
                    t += v
                else:
                    t = v
                mx = max(mx, t)
            return mx

        s1, s2 = sum(nums1), sum(nums2)
        return max(s2 + f(nums1, nums2), s1 + f(nums2, nums1))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maximumsSplicedArray(int[] nums1, int[] nums2) {
        int s1 = 0, s2 = 0, n = nums1.length;
        for (int i = 0; i < n; ++i) {
            s1 += nums1[i];
            s2 += nums2[i];
        }
        return Math.max(s2 + f(nums1, nums2), s1 + f(nums2, nums1));
    }

    private int f(int[] nums1, int[] nums2) {
        int t = nums1[0] - nums2[0];
        int mx = t;
        for (int i = 1; i < nums1.length; ++i) {
            int v = nums1[i] - nums2[i];
            if (t > 0) {
                t += v;
            } else {
                t = v;
            }
            mx = Math.max(mx, t);
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
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int s1 = 0, s2 = 0, n = nums1.size();
        for (int i = 0; i < n; ++i) {
            s1 += nums1[i];
            s2 += nums2[i];
        }
        return max(s2 + f(nums1, nums2), s1 + f(nums2, nums1));
    }

    int f(vector<int>& nums1, vector<int>& nums2) {
        int t = nums1[0] - nums2[0];
        int mx = t;
        for (int i = 1; i < nums1.size(); ++i) {
            int v = nums1[i] - nums2[i];
            if (t > 0)
                t += v;
            else
                t = v;
            mx = max(mx, t);
        }
        return mx;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumsSplicedArray(nums1 []int, nums2 []int) int {
	s1, s2 := 0, 0
	n := len(nums1)
	for i, v := range nums1 {
		s1 += v
		s2 += nums2[i]
	}
	f := func(nums1, nums2 []int) int {
		t := nums1[0] - nums2[0]
		mx := t
		for i := 1; i < n; i++ {
			v := nums1[i] - nums2[i]
			if t > 0 {
				t += v
			} else {
				t = v
			}
			mx = max(mx, t)
		}
		return mx
	}
	return max(s2+f(nums1, nums2), s1+f(nums2, nums1))
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个下标从 <strong>0</strong> 开始的整数数组 <code>nums1</code> 和 <code>nums2</code> ，长度都是 <code>n</code> 。</p>

<p>你可以选择两个整数 <code>left</code> 和 <code>right</code> ，其中 <code>0 &lt;= left &lt;= right &lt; n</code> ，接着 <strong>交换</strong> 两个子数组 <code>nums1[left...right]</code> 和 <code>nums2[left...right]</code> 。</p>

<ul>
	<li>例如，设 <code>nums1 = [1,2,3,4,5]</code> 和 <code>nums2 = [11,12,13,14,15]</code> ，整数选择 <code>left = 1</code> 和 <code>right = 2</code>，那么 <code>nums1</code> 会变为 <code>[1,<strong><em>12</em>,<em>13</em></strong>,4,5]</code> 而 <code>nums2</code> 会变为 <code>[11,<em><strong>2,3</strong></em>,14,15]</code> 。</li>
</ul>

<p>你可以选择执行上述操作 <strong>一次</strong> 或不执行任何操作。</p>

<p>数组的 <strong>分数</strong> 取 <code>sum(nums1)</code> 和 <code>sum(nums2)</code> 中的最大值，其中 <code>sum(arr)</code> 是数组 <code>arr</code> 中所有元素之和。</p>

<p>返回 <strong>可能的最大分数</strong> 。</p>

<p><strong>子数组 </strong>是数组中连续的一个元素序列。<code>arr[left...right]</code> 表示子数组包含 <code>nums</code> 中下标 <code>left</code> 和 <code>right</code> 之间的元素<strong>（含</strong> 下标 <code>left</code> 和 <code>right</code> 对应元素<strong>）</strong>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums1 = [60,60,60], nums2 = [10,90,10]
<strong>输出：</strong>210
<strong>解释：</strong>选择 left = 1 和 right = 1 ，得到 nums1 = [60,<em><strong>90</strong></em>,60] 和 nums2 = [10,<em><strong>60</strong></em>,10] 。
分数为 max(sum(nums1), sum(nums2)) = max(210, 80) = 210 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums1 = [20,40,20,70,30], nums2 = [50,20,50,40,20]
<strong>输出：</strong>220
<strong>解释：</strong>选择 left = 3 和 right = 4 ，得到 nums1 = [20,40,20,<em><strong>40,20</strong></em>] 和 nums2 = [50,20,50,<em><strong>70,30</strong></em>] 。
分数为 max(sum(nums1), sum(nums2)) = max(140, 220) = 220 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums1 = [7,11,13], nums2 = [1,1,1]
<strong>输出：</strong>31
<strong>解释：</strong>选择不交换任何子数组。
分数为 max(sum(nums1), sum(nums2)) = max(31, 3) = 31 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nums1.length == nums2.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums1[i], nums2[i] &lt;= 10<sup>4</sup></code></li>
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
    def maximumsSplicedArray(self, nums1: List[int], nums2: List[int]) -> int:
        def f(nums1, nums2):
            d = [a - b for a, b in zip(nums1, nums2)]
            t = mx = d[0]
            for v in d[1:]:
                if t > 0:
                    t += v
                else:
                    t = v
                mx = max(mx, t)
            return mx

        s1, s2 = sum(nums1), sum(nums2)
        return max(s2 + f(nums1, nums2), s1 + f(nums2, nums1))
```

#### Java

```java
class Solution {
    public int maximumsSplicedArray(int[] nums1, int[] nums2) {
        int s1 = 0, s2 = 0, n = nums1.length;
        for (int i = 0; i < n; ++i) {
            s1 += nums1[i];
            s2 += nums2[i];
        }
        return Math.max(s2 + f(nums1, nums2), s1 + f(nums2, nums1));
    }

    private int f(int[] nums1, int[] nums2) {
        int t = nums1[0] - nums2[0];
        int mx = t;
        for (int i = 1; i < nums1.length; ++i) {
            int v = nums1[i] - nums2[i];
            if (t > 0) {
                t += v;
            } else {
                t = v;
            }
            mx = Math.max(mx, t);
        }
        return mx;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int s1 = 0, s2 = 0, n = nums1.size();
        for (int i = 0; i < n; ++i) {
            s1 += nums1[i];
            s2 += nums2[i];
        }
        return max(s2 + f(nums1, nums2), s1 + f(nums2, nums1));
    }

    int f(vector<int>& nums1, vector<int>& nums2) {
        int t = nums1[0] - nums2[0];
        int mx = t;
        for (int i = 1; i < nums1.size(); ++i) {
            int v = nums1[i] - nums2[i];
            if (t > 0)
                t += v;
            else
                t = v;
            mx = max(mx, t);
        }
        return mx;
    }
};
```

#### Go

```go
func maximumsSplicedArray(nums1 []int, nums2 []int) int {
	s1, s2 := 0, 0
	n := len(nums1)
	for i, v := range nums1 {
		s1 += v
		s2 += nums2[i]
	}
	f := func(nums1, nums2 []int) int {
		t := nums1[0] - nums2[0]
		mx := t
		for i := 1; i < n; i++ {
			v := nums1[i] - nums2[i]
			if t > 0 {
				t += v
			} else {
				t = v
			}
			mx = max(mx, t)
		}
		return mx
	}
	return max(s2+f(nums1, nums2), s1+f(nums2, nums1))
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2322. 从树中删除边的最小分数](https://leetcode.cn/problems/minimum-score-after-removals-on-a-tree){#2322}

{{< tabs "2322" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumScore(self, nums: List[int], edges: List[List[int]]) -> int:
        def dfs(i: int, fa: int) -> int:
            res = nums[i]
            for j in g[i]:
                if j != fa:
                    res ^= dfs(j, i)
            return res

        def dfs2(i: int, fa: int) -> int:
            nonlocal s, s1, ans
            res = nums[i]
            for j in g[i]:
                if j != fa:
                    s2 = dfs2(j, i)
                    res ^= s2
                    mx = max(s ^ s1, s2, s1 ^ s2)
                    mn = min(s ^ s1, s2, s1 ^ s2)
                    ans = min(ans, mx - mn)
            return res

        g = defaultdict(list)
        for a, b in edges:
            g[a].append(b)
            g[b].append(a)
        s = reduce(lambda x, y: x ^ y, nums)
        n = len(nums)
        ans = inf
        for i in range(n):
            for j in g[i]:
                s1 = dfs(i, j)
                dfs2(i, j)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[] nums;
    private List<Integer>[] g;
    private int ans = Integer.MAX_VALUE;
    private int s;
    private int s1;

    public int minimumScore(int[] nums, int[][] edges) {
        int n = nums.length;
        this.nums = nums;
        g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (int[] e : edges) {
            int a = e[0], b = e[1];
            g[a].add(b);
            g[b].add(a);
        }
        for (int x : nums) {
            s ^= x;
        }
        for (int i = 0; i < n; ++i) {
            for (int j : g[i]) {
                s1 = dfs(i, j);
                dfs2(i, j);
            }
        }
        return ans;
    }

    private int dfs(int i, int fa) {
        int res = nums[i];
        for (int j : g[i]) {
            if (j != fa) {
                res ^= dfs(j, i);
            }
        }
        return res;
    }

    private int dfs2(int i, int fa) {
        int res = nums[i];
        for (int j : g[i]) {
            if (j != fa) {
                int s2 = dfs2(j, i);
                res ^= s2;
                int mx = Math.max(Math.max(s ^ s1, s2), s1 ^ s2);
                int mn = Math.min(Math.min(s ^ s1, s2), s1 ^ s2);
                ans = Math.min(ans, mx - mn);
            }
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
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<int> g[n];
        for (const auto& e : edges) {
            int a = e[0], b = e[1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        int s = 0, s1 = 0;
        int ans = INT_MAX;
        for (int x : nums) {
            s ^= x;
        }
        auto dfs = [&](this auto&& dfs, int i, int fa) -> int {
            int res = nums[i];
            for (int j : g[i]) {
                if (j != fa) {
                    res ^= dfs(j, i);
                }
            }
            return res;
        };
        auto dfs2 = [&](this auto&& dfs2, int i, int fa) -> int {
            int res = nums[i];
            for (int j : g[i]) {
                if (j != fa) {
                    int s2 = dfs2(j, i);
                    res ^= s2;
                    int mx = max({s ^ s1, s2, s1 ^ s2});
                    int mn = min({s ^ s1, s2, s1 ^ s2});
                    ans = min(ans, mx - mn);
                }
            }
            return res;
        };
        for (int i = 0; i < n; ++i) {
            for (int j : g[i]) {
                s1 = dfs(i, j);
                dfs2(i, j);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumScore(nums []int, edges [][]int) int {
	n := len(nums)
	g := make([][]int, n)
	for _, e := range edges {
		a, b := e[0], e[1]
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}
	s, s1 := 0, 0
	ans := math.MaxInt32
	for _, x := range nums {
		s ^= x
	}
	var dfs func(i, fa int) int
	dfs = func(i, fa int) int {
		res := nums[i]
		for _, j := range g[i] {
			if j != fa {
				res ^= dfs(j, i)
			}
		}
		return res
	}
	var dfs2 func(i, fa int) int
	dfs2 = func(i, fa int) int {
		res := nums[i]
		for _, j := range g[i] {
			if j != fa {
				s2 := dfs2(j, i)
				res ^= s2
				mx := max(s^s1, s2, s1^s2)
				mn := min(s^s1, s2, s1^s2)
				ans = min(ans, mx-mn)
			}
		}
		return res
	}
	for i := 0; i < n; i++ {
		for _, j := range g[i] {
			s1 = dfs(i, j)
			dfs2(i, j)
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumScore(nums: number[], edges: number[][]): number {
    const n = nums.length;
    const g: number[][] = Array.from({ length: n }, () => []);
    for (const [a, b] of edges) {
        g[a].push(b);
        g[b].push(a);
    }
    const s = nums.reduce((a, b) => a ^ b, 0);
    let s1 = 0;
    let ans = Number.MAX_SAFE_INTEGER;
    function dfs(i: number, fa: number): number {
        let res = nums[i];
        for (const j of g[i]) {
            if (j !== fa) {
                res ^= dfs(j, i);
            }
        }
        return res;
    }
    function dfs2(i: number, fa: number): number {
        let res = nums[i];
        for (const j of g[i]) {
            if (j !== fa) {
                const s2 = dfs2(j, i);
                res ^= s2;
                const mx = Math.max(s ^ s1, s2, s1 ^ s2);
                const mn = Math.min(s ^ s1, s2, s1 ^ s2);
                ans = Math.min(ans, mx - mn);
            }
        }
        return res;
    }
    for (let i = 0; i < n; ++i) {
        for (const j of g[i]) {
            s1 = dfs(i, j);
            dfs2(i, j);
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn minimum_score(nums: Vec<i32>, edges: Vec<Vec<i32>>) -> i32 {
        let n = nums.len();
        let mut g = vec![vec![]; n];
        for e in edges.iter() {
            let a = e[0] as usize;
            let b = e[1] as usize;
            g[a].push(b);
            g[b].push(a);
        }
        let mut s1 = 0;
        let mut ans = i32::MAX;
        let s = nums.iter().fold(0, |acc, &x| acc ^ x);

        fn dfs(i: usize, fa: usize, g: &Vec<Vec<usize>>, nums: &Vec<i32>) -> i32 {
            let mut res = nums[i];
            for &j in &g[i] {
                if j != fa {
                    res ^= dfs(j, i, g, nums);
                }
            }
            res
        }

        fn dfs2(
            i: usize,
            fa: usize,
            g: &Vec<Vec<usize>>,
            nums: &Vec<i32>,
            s: i32,
            s1: i32,
            ans: &mut i32
        ) -> i32 {
            let mut res = nums[i];
            for &j in &g[i] {
                if j != fa {
                    let s2 = dfs2(j, i, g, nums, s, s1, ans);
                    res ^= s2;
                    let mx = (s ^ s1).max(s2).max(s1 ^ s2);
                    let mn = (s ^ s1).min(s2).min(s1 ^ s2);
                    *ans = (*ans).min(mx - mn);
                }
            }
            res
        }

        for i in 0..n {
            for &j in &g[i] {
                s1 = dfs(i, j, &g, &nums);
                dfs2(i, j, &g, &nums, s, s1, &mut ans);
            }
        }
        ans
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int MinimumScore(int[] nums, int[][] edges) {
        int n = nums.Length;
        List<int>[] g = new List<int>[n];
        for (int i = 0; i < n; i++) {
            g[i] = new List<int>();
        }
        foreach (var e in edges) {
            int a = e[0], b = e[1];
            g[a].Add(b);
            g[b].Add(a);
        }

        int s = 0;
        foreach (int x in nums) {
            s ^= x;
        }

        int ans = int.MaxValue;
        int s1 = 0;

        int Dfs(int i, int fa) {
            int res = nums[i];
            foreach (int j in g[i]) {
                if (j != fa) {
                    res ^= Dfs(j, i);
                }
            }
            return res;
        }

        int Dfs2(int i, int fa) {
            int res = nums[i];
            foreach (int j in g[i]) {
                if (j != fa) {
                    int s2 = Dfs2(j, i);
                    res ^= s2;
                    int mx = Math.Max(Math.Max(s ^ s1, s2), s1 ^ s2);
                    int mn = Math.Min(Math.Min(s ^ s1, s2), s1 ^ s2);
                    ans = Math.Min(ans, mx - mn);
                }
            }
            return res;
        }

        for (int i = 0; i < n; ++i) {
            foreach (int j in g[i]) {
                s1 = Dfs(i, j);
                Dfs2(i, j);
            }
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

<p>存在一棵无向连通树，树中有编号从 <code>0</code> 到 <code>n - 1</code> 的 <code>n</code> 个节点， 以及 <code>n - 1</code> 条边。</p>

<p>给你一个下标从 <strong>0</strong> 开始的整数数组 <code>nums</code> ，长度为 <code>n</code> ，其中 <code>nums[i]</code> 表示第 <code>i</code> 个节点的值。另给你一个二维整数数组 <code>edges</code> ，长度为 <code>n - 1</code> ，其中 <code>edges[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> 表示树中存在一条位于节点 <code>a<sub>i</sub></code> 和 <code>b<sub>i</sub></code> 之间的边。</p>

<p>删除树中两条 <strong>不同</strong> 的边以形成三个连通组件。对于一种删除边方案，定义如下步骤以计算其分数：</p>

<ol>
	<li>分别获取三个组件 <strong>每个</strong> 组件中所有节点值的异或值。</li>
	<li><strong>最大</strong> 异或值和 <strong>最小</strong> 异或值的 <strong>差值</strong> 就是这一种删除边方案的分数。</li>
</ol>

<ul>
	<li>例如，三个组件的节点值分别是：<code>[4,5,7]</code>、<code>[1,9]</code> 和 <code>[3,3,3]</code> 。三个异或值分别是 <code>4 ^ 5 ^ 7 = <em><strong>6</strong></em></code>、<code>1 ^ 9 = <em><strong>8</strong></em></code> 和 <code>3 ^ 3 ^ 3 = <em><strong>3</strong></em></code> 。最大异或值是 <code>8</code> ，最小异或值是 <code>3</code> ，分数是 <code>8 - 3 = 5</code> 。</li>
</ul>

<p>返回在给定树上执行任意删除边方案可能的 <strong>最小</strong> 分数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2300-2399/2322.Minimum%20Score%20After%20Removals%20on%20a%20Tree/images/ex1drawio.png" style="width: 193px; height: 190px;">
<pre><strong>输入：</strong>nums = [1,5,5,4,11], edges = [[0,1],[1,2],[1,3],[3,4]]
<strong>输出：</strong>9
<strong>解释：</strong>上图展示了一种删除边方案。
- 第 1 个组件的节点是 [1,3,4] ，值是 [5,4,11] 。异或值是 5 ^ 4 ^ 11 = 10 。
- 第 2 个组件的节点是 [0] ，值是 [1] 。异或值是 1 = 1 。
- 第 3 个组件的节点是 [2] ，值是 [5] 。异或值是 5 = 5 。
分数是最大异或值和最小异或值的差值，10 - 1 = 9 。
可以证明不存在分数比 9 小的删除边方案。
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2300-2399/2322.Minimum%20Score%20After%20Removals%20on%20a%20Tree/images/ex2drawio.png" style="width: 287px; height: 150px;">
<pre><strong>输入：</strong>nums = [5,5,2,4,4,2], edges = [[0,1],[1,2],[5,2],[4,3],[1,3]]
<strong>输出：</strong>0
<strong>解释：</strong>上图展示了一种删除边方案。
- 第 1 个组件的节点是 [3,4] ，值是 [4,4] 。异或值是 4 ^ 4 = 0 。
- 第 2 个组件的节点是 [1,0] ，值是 [5,5] 。异或值是 5 ^ 5 = 0 。
- 第 3 个组件的节点是 [2,5] ，值是 [2,2] 。异或值是 2 ^ 2 = 0 。
分数是最大异或值和最小异或值的差值，0 - 0 = 0 。
无法获得比 0 更小的分数 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>3 &lt;= n &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>8</sup></code></li>
	<li><code>edges.length == n - 1</code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt; n</code></li>
	<li><code>a<sub>i</sub> != b<sub>i</sub></code></li>
	<li><code>edges</code> 表示一棵有效的树</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS + 子树异或和

我们记树的异或和为 $s$，即 $s = \text{nums}[0] \oplus \text{nums}[1] \oplus \ldots \oplus \text{nums}[n-1]$。

接下来，枚举 $[0..n)$ 的每个点 $i$ 作为树的根节点，将根节点与某个子节点 $j$ 相连的边作为第一条被删除的边。这样我们就获得了两个连通块，我们记包含根节点 $i$ 的连通块的异或和为 $s_1$，然后我们对包含根节点 $i$ 的连通块进行 DFS，计算出每个子树的异或和，记每次 DFS 计算出的子树异或和为 $s_2$。那么三个连通块的异或和分别为 $s \oplus s_1$, $s_2$ 和 $s_1 \oplus s_2$。我们需要计算这三个异或和的最大值和最小值，记为 $\textit{mx}$ 和 $\textit{mn}$，那么对于枚举的每一种情况，得到的分数为 $\textit{mx} - \textit{mn}$。求所有情况的最小值作为答案。

计算每个子树的异或和可以通过 DFS 实现。定义一个函数 $\text{dfs}(i, fa)$，表示从节点 $i$ 开始 DFS，而 $fa$ 是节点 $i$ 的父节点。函数返回值为以节点 $i$ 为根的子树的异或和。

时间复杂度 $O(n^2)$，空间复杂度 $O(n)$。其中 $n$ 是树的节点数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumScore(self, nums: List[int], edges: List[List[int]]) -> int:
        def dfs(i: int, fa: int) -> int:
            res = nums[i]
            for j in g[i]:
                if j != fa:
                    res ^= dfs(j, i)
            return res

        def dfs2(i: int, fa: int) -> int:
            nonlocal s, s1, ans
            res = nums[i]
            for j in g[i]:
                if j != fa:
                    s2 = dfs2(j, i)
                    res ^= s2
                    mx = max(s ^ s1, s2, s1 ^ s2)
                    mn = min(s ^ s1, s2, s1 ^ s2)
                    ans = min(ans, mx - mn)
            return res

        g = defaultdict(list)
        for a, b in edges:
            g[a].append(b)
            g[b].append(a)
        s = reduce(lambda x, y: x ^ y, nums)
        n = len(nums)
        ans = inf
        for i in range(n):
            for j in g[i]:
                s1 = dfs(i, j)
                dfs2(i, j)
        return ans
```

#### Java

```java
class Solution {
    private int[] nums;
    private List<Integer>[] g;
    private int ans = Integer.MAX_VALUE;
    private int s;
    private int s1;

    public int minimumScore(int[] nums, int[][] edges) {
        int n = nums.length;
        this.nums = nums;
        g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (int[] e : edges) {
            int a = e[0], b = e[1];
            g[a].add(b);
            g[b].add(a);
        }
        for (int x : nums) {
            s ^= x;
        }
        for (int i = 0; i < n; ++i) {
            for (int j : g[i]) {
                s1 = dfs(i, j);
                dfs2(i, j);
            }
        }
        return ans;
    }

    private int dfs(int i, int fa) {
        int res = nums[i];
        for (int j : g[i]) {
            if (j != fa) {
                res ^= dfs(j, i);
            }
        }
        return res;
    }

    private int dfs2(int i, int fa) {
        int res = nums[i];
        for (int j : g[i]) {
            if (j != fa) {
                int s2 = dfs2(j, i);
                res ^= s2;
                int mx = Math.max(Math.max(s ^ s1, s2), s1 ^ s2);
                int mn = Math.min(Math.min(s ^ s1, s2), s1 ^ s2);
                ans = Math.min(ans, mx - mn);
            }
        }
        return res;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<int> g[n];
        for (const auto& e : edges) {
            int a = e[0], b = e[1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        int s = 0, s1 = 0;
        int ans = INT_MAX;
        for (int x : nums) {
            s ^= x;
        }
        auto dfs = [&](this auto&& dfs, int i, int fa) -> int {
            int res = nums[i];
            for (int j : g[i]) {
                if (j != fa) {
                    res ^= dfs(j, i);
                }
            }
            return res;
        };
        auto dfs2 = [&](this auto&& dfs2, int i, int fa) -> int {
            int res = nums[i];
            for (int j : g[i]) {
                if (j != fa) {
                    int s2 = dfs2(j, i);
                    res ^= s2;
                    int mx = max({s ^ s1, s2, s1 ^ s2});
                    int mn = min({s ^ s1, s2, s1 ^ s2});
                    ans = min(ans, mx - mn);
                }
            }
            return res;
        };
        for (int i = 0; i < n; ++i) {
            for (int j : g[i]) {
                s1 = dfs(i, j);
                dfs2(i, j);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func minimumScore(nums []int, edges [][]int) int {
	n := len(nums)
	g := make([][]int, n)
	for _, e := range edges {
		a, b := e[0], e[1]
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}
	s, s1 := 0, 0
	ans := math.MaxInt32
	for _, x := range nums {
		s ^= x
	}
	var dfs func(i, fa int) int
	dfs = func(i, fa int) int {
		res := nums[i]
		for _, j := range g[i] {
			if j != fa {
				res ^= dfs(j, i)
			}
		}
		return res
	}
	var dfs2 func(i, fa int) int
	dfs2 = func(i, fa int) int {
		res := nums[i]
		for _, j := range g[i] {
			if j != fa {
				s2 := dfs2(j, i)
				res ^= s2
				mx := max(s^s1, s2, s1^s2)
				mn := min(s^s1, s2, s1^s2)
				ans = min(ans, mx-mn)
			}
		}
		return res
	}
	for i := 0; i < n; i++ {
		for _, j := range g[i] {
			s1 = dfs(i, j)
			dfs2(i, j)
		}
	}
	return ans
}
```

#### TypeScript

```ts
function minimumScore(nums: number[], edges: number[][]): number {
    const n = nums.length;
    const g: number[][] = Array.from({ length: n }, () => []);
    for (const [a, b] of edges) {
        g[a].push(b);
        g[b].push(a);
    }
    const s = nums.reduce((a, b) => a ^ b, 0);
    let s1 = 0;
    let ans = Number.MAX_SAFE_INTEGER;
    function dfs(i: number, fa: number): number {
        let res = nums[i];
        for (const j of g[i]) {
            if (j !== fa) {
                res ^= dfs(j, i);
            }
        }
        return res;
    }
    function dfs2(i: number, fa: number): number {
        let res = nums[i];
        for (const j of g[i]) {
            if (j !== fa) {
                const s2 = dfs2(j, i);
                res ^= s2;
                const mx = Math.max(s ^ s1, s2, s1 ^ s2);
                const mn = Math.min(s ^ s1, s2, s1 ^ s2);
                ans = Math.min(ans, mx - mn);
            }
        }
        return res;
    }
    for (let i = 0; i < n; ++i) {
        for (const j of g[i]) {
            s1 = dfs(i, j);
            dfs2(i, j);
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn minimum_score(nums: Vec<i32>, edges: Vec<Vec<i32>>) -> i32 {
        let n = nums.len();
        let mut g = vec![vec![]; n];
        for e in edges.iter() {
            let a = e[0] as usize;
            let b = e[1] as usize;
            g[a].push(b);
            g[b].push(a);
        }
        let mut s1 = 0;
        let mut ans = i32::MAX;
        let s = nums.iter().fold(0, |acc, &x| acc ^ x);

        fn dfs(i: usize, fa: usize, g: &Vec<Vec<usize>>, nums: &Vec<i32>) -> i32 {
            let mut res = nums[i];
            for &j in &g[i] {
                if j != fa {
                    res ^= dfs(j, i, g, nums);
                }
            }
            res
        }

        fn dfs2(
            i: usize,
            fa: usize,
            g: &Vec<Vec<usize>>,
            nums: &Vec<i32>,
            s: i32,
            s1: i32,
            ans: &mut i32
        ) -> i32 {
            let mut res = nums[i];
            for &j in &g[i] {
                if j != fa {
                    let s2 = dfs2(j, i, g, nums, s, s1, ans);
                    res ^= s2;
                    let mx = (s ^ s1).max(s2).max(s1 ^ s2);
                    let mn = (s ^ s1).min(s2).min(s1 ^ s2);
                    *ans = (*ans).min(mx - mn);
                }
            }
            res
        }

        for i in 0..n {
            for &j in &g[i] {
                s1 = dfs(i, j, &g, &nums);
                dfs2(i, j, &g, &nums, s, s1, &mut ans);
            }
        }
        ans
    }
}
```

#### C#

```cs
public class Solution {
    public int MinimumScore(int[] nums, int[][] edges) {
        int n = nums.Length;
        List<int>[] g = new List<int>[n];
        for (int i = 0; i < n; i++) {
            g[i] = new List<int>();
        }
        foreach (var e in edges) {
            int a = e[0], b = e[1];
            g[a].Add(b);
            g[b].Add(a);
        }

        int s = 0;
        foreach (int x in nums) {
            s ^= x;
        }

        int ans = int.MaxValue;
        int s1 = 0;

        int Dfs(int i, int fa) {
            int res = nums[i];
            foreach (int j in g[i]) {
                if (j != fa) {
                    res ^= Dfs(j, i);
                }
            }
            return res;
        }

        int Dfs2(int i, int fa) {
            int res = nums[i];
            foreach (int j in g[i]) {
                if (j != fa) {
                    int s2 = Dfs2(j, i);
                    res ^= s2;
                    int mx = Math.Max(Math.Max(s ^ s1, s2), s1 ^ s2);
                    int mn = Math.Min(Math.Min(s ^ s1, s2), s1 ^ s2);
                    ans = Math.Min(ans, mx - mn);
                }
            }
            return res;
        }

        for (int i = 0; i < n; ++i) {
            foreach (int j in g[i]) {
                s1 = Dfs(i, j);
                Dfs2(i, j);
            }
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

# [2323. 完成所有工作的最短时间 II 🔒](https://leetcode.cn/problems/find-minimum-time-to-finish-all-jobs-ii){#2323}

{{< tabs "2323" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumTime(self, jobs: List[int], workers: List[int]) -> int:
        jobs.sort()
        workers.sort()
        return max((a + b - 1) // b for a, b in zip(jobs, workers))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumTime(int[] jobs, int[] workers) {
        Arrays.sort(jobs);
        Arrays.sort(workers);
        int ans = 0;
        for (int i = 0; i < jobs.length; ++i) {
            ans = Math.max(ans, (jobs[i] + workers[i] - 1) / workers[i]);
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
    int minimumTime(vector<int>& jobs, vector<int>& workers) {
        ranges::sort(jobs);
        ranges::sort(workers);
        int ans = 0;
        int n = jobs.size();
        for (int i = 0; i < n; ++i) {
            ans = max(ans, (jobs[i] + workers[i] - 1) / workers[i]);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumTime(jobs []int, workers []int) (ans int) {
	sort.Ints(jobs)
	sort.Ints(workers)
	for i, a := range jobs {
		b := workers[i]
		ans = max(ans, (a+b-1)/b)
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumTime(jobs: number[], workers: number[]): number {
    jobs.sort((a, b) => a - b);
    workers.sort((a, b) => a - b);
    let ans = 0;
    const n = jobs.length;
    for (let i = 0; i < n; ++i) {
        ans = Math.max(ans, Math.ceil(jobs[i] / workers[i]));
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn minimum_time(mut jobs: Vec<i32>, mut workers: Vec<i32>) -> i32 {
        jobs.sort();
        workers.sort();
        jobs.iter()
            .zip(workers.iter())
            .map(|(a, b)| (a + b - 1) / b)
            .max()
            .unwrap()
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} jobs
 * @param {number[]} workers
 * @return {number}
 */
var minimumTime = function (jobs, workers) {
    jobs.sort((a, b) => a - b);
    workers.sort((a, b) => a - b);
    let ans = 0;
    const n = jobs.length;
    for (let i = 0; i < n; ++i) {
        ans = Math.max(ans, Math.ceil(jobs[i] / workers[i]));
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

<p>给你两个 <b>下标从 0 开始&nbsp;</b>的整数数组 <code>jobs</code> 和&nbsp;<strong>相等&nbsp;</strong>长度的 <code>workers</code> ，其中&nbsp;<code>jobs[i]</code>是完成第 <code>i</code> 个工作所需的时间，<code>workers[j]</code>&nbsp;是第 <code>j</code> 个工人每天可以工作的时间。</p>

<p>每项工作都应该 <strong>正好</strong> 分配给一个工人，这样每个工人就&nbsp;<strong>只能&nbsp;</strong>完成一项工作。</p>

<p>返回<em>分配后完成所有作业所需的最少天数。</em></p>

<p>&nbsp;</p>

<p><strong class="example">示例 1:</strong></p>

<pre>
<strong>输入:</strong> jobs = [5,2,4], workers = [1,7,5]
<strong>输出:</strong> 2
<strong>解释:</strong>
- 把第 2 个工人分配到第 0 个工作。他们花了 1 天时间完成这项工作。
- 把第 0 个工人分配到第 1 个工作。他们花了 2 天时间完成这项工作。
- 把第 1 个工人分配到第 2 个工作。他们花了 1 天时间完成这项工作。
所有工作完成需要 2 天，因此返回 2。
可以证明 2 天是最少需要的天数。
</pre>

<p><strong class="example">示例 2:</strong></p>

<pre>
<strong>输入:</strong> jobs = [3,18,15,9], workers = [6,5,1,3]
<strong>输出:</strong> 3
<strong>解释:</strong>
- 把第 2 个工人分配到第 0 个工作。他花了 3 天时间完成这项工作。
- 把第 0 个工人分配到第 1 个工作。他花了 3 天时间完成这项工作。
- 把第 1 个工人分配到第 2 个工作。他花了 3 天时间完成这项工作。
- 把第 3 个工人分配到第 3 个工作。他花了 3 天时间完成这项工作。
完成所有工作需要 3 天，因此返回 3。
可以证明，3 天是最少需要的天数。
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>n == jobs.length == workers.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= jobs[i], workers[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心

为了使得完成所有工作所需的最少天数尽可能小，我们可以尽量让工作时间较长的工人去完成工作时间较长的工作。

因此，我们可以先对 $\textit{jobs}$ 和 $\textit{workers}$ 进行排序，然后依次将工作分配给对应下标的工人，求最大的工作时间和工人时间的比值即可。

时间复杂度 $O(n \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 为工作数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumTime(self, jobs: List[int], workers: List[int]) -> int:
        jobs.sort()
        workers.sort()
        return max((a + b - 1) // b for a, b in zip(jobs, workers))
```

#### Java

```java
class Solution {
    public int minimumTime(int[] jobs, int[] workers) {
        Arrays.sort(jobs);
        Arrays.sort(workers);
        int ans = 0;
        for (int i = 0; i < jobs.length; ++i) {
            ans = Math.max(ans, (jobs[i] + workers[i] - 1) / workers[i]);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumTime(vector<int>& jobs, vector<int>& workers) {
        ranges::sort(jobs);
        ranges::sort(workers);
        int ans = 0;
        int n = jobs.size();
        for (int i = 0; i < n; ++i) {
            ans = max(ans, (jobs[i] + workers[i] - 1) / workers[i]);
        }
        return ans;
    }
};
```

#### Go

```go
func minimumTime(jobs []int, workers []int) (ans int) {
	sort.Ints(jobs)
	sort.Ints(workers)
	for i, a := range jobs {
		b := workers[i]
		ans = max(ans, (a+b-1)/b)
	}
	return
}
```

#### TypeScript

```ts
function minimumTime(jobs: number[], workers: number[]): number {
    jobs.sort((a, b) => a - b);
    workers.sort((a, b) => a - b);
    let ans = 0;
    const n = jobs.length;
    for (let i = 0; i < n; ++i) {
        ans = Math.max(ans, Math.ceil(jobs[i] / workers[i]));
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn minimum_time(mut jobs: Vec<i32>, mut workers: Vec<i32>) -> i32 {
        jobs.sort();
        workers.sort();
        jobs.iter()
            .zip(workers.iter())
            .map(|(a, b)| (a + b - 1) / b)
            .max()
            .unwrap()
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} jobs
 * @param {number[]} workers
 * @return {number}
 */
var minimumTime = function (jobs, workers) {
    jobs.sort((a, b) => a - b);
    workers.sort((a, b) => a - b);
    let ans = 0;
    const n = jobs.length;
    for (let i = 0; i < n; ++i) {
        ans = Math.max(ans, Math.ceil(jobs[i] / workers[i]));
    }
    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2324. 产品销售分析 IV 🔒](https://leetcode.cn/problems/product-sales-analysis-iv){#2324}

{{< tabs "2324" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            user_id,
            product_id,
            RANK() OVER (
                PARTITION BY user_id
                ORDER BY SUM(quantity * price) DESC
            ) AS rk
        FROM
            Sales
            JOIN Product USING (product_id)
        GROUP BY 1, 2
    )
SELECT user_id, product_id
FROM T
WHERE rk = 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表: <code>Sales</code></p>

<pre>
+-------------+-------+
| Column Name | Type  |
+-------------+-------+
| sale_id     | int   |
| product_id  | int   |
| user_id     | int   |
| quantity    | int   |
+-------------+-------+
sale_id 包含唯一值。
product_id 是 product 表的外键。
该表的每一行都显示了产品的 ID 和用户购买的数量。
</pre>

<p>&nbsp;</p>

<p>表: <code>Product</code></p>

<pre>
+-------------+------+
| Column Name | Type |
+-------------+------+
| product_id  | int  |
| price       | int  |
+-------------+------+
product_id 包含唯一值。
该表的每一行都表示每种产品的价格。
</pre>

<p>&nbsp;</p>

<p>编写解决方案，为每个用户获取其消费最多的产品 id。如果同一用户在两个或多个产品上花费了最多的钱，请获取所有花费了最多的钱的产品。</p>

<p data-group="1-1">以 <strong>任意顺序</strong> 返回结果表。</p>

<p>查询结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1:</strong></p>

<pre>
<strong>输入:</strong> 
Sales 表:
+---------+------------+---------+----------+
| sale_id | product_id | user_id | quantity |
+---------+------------+---------+----------+
| 1       | 1          | 101     | 10       |
| 2       | 3          | 101     | 7        |
| 3       | 1          | 102     | 9        |
| 4       | 2          | 102     | 6        |
| 5       | 3          | 102     | 10       |
| 6       | 1          | 102     | 6        |
+---------+------------+---------+----------+
Product 表:
+------------+-------+
| product_id | price |
+------------+-------+
| 1          | 10    |
| 2          | 25    |
| 3          | 15    |
+------------+-------+
<strong>输出:</strong> 
+---------+------------+
| user_id | product_id |
+---------+------------+
| 101     | 3          |
| 102     | 1          |
| 102     | 2          |
| 102     | 3          |
+---------+------------+ 
<strong>解释:</strong> 
用户 101:
    - 在产品 1 上花费 10 * 10 = 100。
    - 在产品 3 上花费 7 * 15 = 105。
用户101在产品3上花的钱最多。
用户 102:
    - 在产品 1 上花费 (9 + 6)* 10 = 150
    - 在产品 2 上花费 6 * 25 = 150
    - 在产品 3 上花费 10 * 15 = 150。
用户 102 在产品 1、2、3 上花的钱最多。
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
        SELECT
            user_id,
            product_id,
            RANK() OVER (
                PARTITION BY user_id
                ORDER BY SUM(quantity * price) DESC
            ) AS rk
        FROM
            Sales
            JOIN Product USING (product_id)
        GROUP BY 1, 2
    )
SELECT user_id, product_id
FROM T
WHERE rk = 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2325. 解密消息](https://leetcode.cn/problems/decode-the-message){#2325}

{{< tabs "2325" >}}

{{% tab "python" %}}
```python
class Solution:
    def decodeMessage(self, key: str, message: str) -> str:
        d = {" ": " "}
        i = 0
        for c in key:
            if c not in d:
                d[c] = ascii_lowercase[i]
                i += 1
        return "".join(d[c] for c in message)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String decodeMessage(String key, String message) {
        char[] d = new char[128];
        d[' '] = ' ';
        for (int i = 0, j = 0; i < key.length(); ++i) {
            char c = key.charAt(i);
            if (d[c] == 0) {
                d[c] = (char) ('a' + j++);
            }
        }
        char[] ans = message.toCharArray();
        for (int i = 0; i < ans.length; ++i) {
            ans[i] = d[ans[i]];
        }
        return String.valueOf(ans);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string decodeMessage(string key, string message) {
        char d[128]{};
        d[' '] = ' ';
        char i = 'a';
        for (char& c : key) {
            if (!d[c]) {
                d[c] = i++;
            }
        }
        for (char& c : message) {
            c = d[c];
        }
        return message;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func decodeMessage(key string, message string) string {
	d := [128]byte{}
	d[' '] = ' '
	for i, j := 0, 0; i < len(key); i++ {
		if d[key[i]] == 0 {
			d[key[i]] = byte('a' + j)
			j++
		}
	}
	ans := []byte(message)
	for i, c := range ans {
		ans[i] = d[c]
	}
	return string(ans)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function decodeMessage(key: string, message: string): string {
    const d = new Map<string, string>();
    for (const c of key) {
        if (c === ' ' || d.has(c)) {
            continue;
        }
        d.set(c, String.fromCharCode('a'.charCodeAt(0) + d.size));
    }
    d.set(' ', ' ');
    return [...message].map(v => d.get(v)).join('');
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashMap;
impl Solution {
    pub fn decode_message(key: String, message: String) -> String {
        let mut d = HashMap::new();
        for c in key.as_bytes() {
            if *c == b' ' || d.contains_key(c) {
                continue;
            }
            d.insert(c, char::from((97 + d.len()) as u8));
        }
        message
            .as_bytes()
            .iter()
            .map(|c| d.get(c).unwrap_or(&' '))
            .collect()
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
char* decodeMessage(char* key, char* message) {
    int m = strlen(key);
    int n = strlen(message);
    char d[26];
    memset(d, ' ', 26);
    for (int i = 0, j = 0; i < m; i++) {
        if (key[i] == ' ' || d[key[i] - 'a'] != ' ') {
            continue;
        }
        d[key[i] - 'a'] = 'a' + j++;
    }
    char* ans = malloc(n + 1);
    for (int i = 0; i < n; i++) {
        ans[i] = message[i] == ' ' ? ' ' : d[message[i] - 'a'];
    }
    ans[n] = '\0';
    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你字符串 <code>key</code> 和 <code>message</code> ，分别表示一个加密密钥和一段加密消息。解密 <code>message</code> 的步骤如下：</p>

<ol>
	<li>使用 <code>key</code> 中 26 个英文小写字母第一次出现的顺序作为替换表中的字母 <strong>顺序</strong> 。</li>
	<li>将替换表与普通英文字母表对齐，形成对照表。</li>
	<li>按照对照表 <strong>替换</strong> <code>message</code> 中的每个字母。</li>
	<li>空格 <code>' '</code> 保持不变。</li>
</ol>

<ul>
	<li>例如，<code>key = "<em><strong>hap</strong></em>p<em><strong>y</strong></em> <em><strong>bo</strong></em>y"</code>（实际的加密密钥会包含字母表中每个字母 <strong>至少一次</strong>），据此，可以得到部分对照表（<code>'h' -&gt; 'a'</code>、<code>'a' -&gt; 'b'</code>、<code>'p' -&gt; 'c'</code>、<code>'y' -&gt; 'd'</code>、<code>'b' -&gt; 'e'</code>、<code>'o' -&gt; 'f'</code>）。</li>
</ul>

<p>返回解密后的消息。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2300-2399/2325.Decode%20the%20Message/images/ex1new4.jpg" style="width: 752px; height: 150px;" /></p>

<pre>
<strong>输入：</strong>key = "the quick brown fox jumps over the lazy dog", message = "vkbs bs t suepuv"
<strong>输出：</strong>"this is a secret"
<strong>解释：</strong>对照表如上图所示。
提取 "<em><strong>the</strong></em> <em><strong>quick</strong></em> <em><strong>brown</strong></em> <em><strong>f</strong></em>o<em><strong>x</strong></em> <em><strong>j</strong></em>u<em><strong>mps</strong></em> o<em><strong>v</strong></em>er the <em><strong>lazy</strong></em> <em><strong>d</strong></em>o<em><strong>g</strong></em>" 中每个字母的首次出现可以得到替换表。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2300-2399/2325.Decode%20the%20Message/images/ex2new.jpg" style="width: 754px; height: 150px;" /></p>

<pre>
<strong>输入：</strong>key = "eljuxhpwnyrdgtqkviszcfmabo", message = "zwx hnfx lqantp mnoeius ycgk vcnjrdb"
<strong>输出：</strong>"the five boxing wizards jump quickly"
<strong>解释：</strong>对照表如上图所示。
提取 "<em><strong>eljuxhpwnyrdgtqkviszcfmabo</strong></em>" 中每个字母的首次出现可以得到替换表。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>26 &lt;= key.length &lt;= 2000</code></li>
	<li><code>key</code> 由小写英文字母及 <code>' '</code> 组成</li>
	<li><code>key</code> 包含英文字母表中每个字符（<code>'a'</code> 到 <code>'z'</code>）<strong>至少一次</strong></li>
	<li><code>1 &lt;= message.length &lt;= 2000</code></li>
	<li><code>message</code> 由小写英文字母和 <code>' '</code> 组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数组或哈希表

我们可以使用数组或哈希表 $d$ 存储对照表，然后遍历 `message` 中的每个字符，将其替换为对应的字符即可。

时间复杂度 $O(m + n)$，空间复杂度 $O(C)$。其中 $m$ 和 $n$ 分别为 `key` 和 `message` 的长度；而 $C$ 为字符集大小。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def decodeMessage(self, key: str, message: str) -> str:
        d = {" ": " "}
        i = 0
        for c in key:
            if c not in d:
                d[c] = ascii_lowercase[i]
                i += 1
        return "".join(d[c] for c in message)
```

#### Java

```java
class Solution {
    public String decodeMessage(String key, String message) {
        char[] d = new char[128];
        d[' '] = ' ';
        for (int i = 0, j = 0; i < key.length(); ++i) {
            char c = key.charAt(i);
            if (d[c] == 0) {
                d[c] = (char) ('a' + j++);
            }
        }
        char[] ans = message.toCharArray();
        for (int i = 0; i < ans.length; ++i) {
            ans[i] = d[ans[i]];
        }
        return String.valueOf(ans);
    }
}
```

#### C++

```cpp
class Solution {
public:
    string decodeMessage(string key, string message) {
        char d[128]{};
        d[' '] = ' ';
        char i = 'a';
        for (char& c : key) {
            if (!d[c]) {
                d[c] = i++;
            }
        }
        for (char& c : message) {
            c = d[c];
        }
        return message;
    }
};
```

#### Go

```go
func decodeMessage(key string, message string) string {
	d := [128]byte{}
	d[' '] = ' '
	for i, j := 0, 0; i < len(key); i++ {
		if d[key[i]] == 0 {
			d[key[i]] = byte('a' + j)
			j++
		}
	}
	ans := []byte(message)
	for i, c := range ans {
		ans[i] = d[c]
	}
	return string(ans)
}
```

#### TypeScript

```ts
function decodeMessage(key: string, message: string): string {
    const d = new Map<string, string>();
    for (const c of key) {
        if (c === ' ' || d.has(c)) {
            continue;
        }
        d.set(c, String.fromCharCode('a'.charCodeAt(0) + d.size));
    }
    d.set(' ', ' ');
    return [...message].map(v => d.get(v)).join('');
}
```

#### Rust

```rust
use std::collections::HashMap;
impl Solution {
    pub fn decode_message(key: String, message: String) -> String {
        let mut d = HashMap::new();
        for c in key.as_bytes() {
            if *c == b' ' || d.contains_key(c) {
                continue;
            }
            d.insert(c, char::from((97 + d.len()) as u8));
        }
        message
            .as_bytes()
            .iter()
            .map(|c| d.get(c).unwrap_or(&' '))
            .collect()
    }
}
```

#### C

```c
char* decodeMessage(char* key, char* message) {
    int m = strlen(key);
    int n = strlen(message);
    char d[26];
    memset(d, ' ', 26);
    for (int i = 0, j = 0; i < m; i++) {
        if (key[i] == ' ' || d[key[i] - 'a'] != ' ') {
            continue;
        }
        d[key[i] - 'a'] = 'a' + j++;
    }
    char* ans = malloc(n + 1);
    for (int i = 0; i < n; i++) {
        ans[i] = message[i] == ' ' ? ' ' : d[message[i] - 'a'];
    }
    ans[n] = '\0';
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2326. 螺旋矩阵 IV](https://leetcode.cn/problems/spiral-matrix-iv){#2326}

{{< tabs "2326" >}}

{{% tab "python" %}}
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def spiralMatrix(self, m: int, n: int, head: Optional[ListNode]) -> List[List[int]]:
        ans = [[-1] * n for _ in range(m)]
        i = j = k = 0
        dirs = (0, 1, 0, -1, 0)
        while 1:
            ans[i][j] = head.val
            head = head.next
            if head is None:
                break
            while 1:
                x, y = i + dirs[k], j + dirs[k + 1]
                if 0 <= x < m and 0 <= y < n and ans[x][y] == -1:
                    i, j = x, y
                    break
                k = (k + 1) % 4
        return ans
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
class Solution {
    public int[][] spiralMatrix(int m, int n, ListNode head) {
        int[][] ans = new int[m][n];
        for (var row : ans) {
            Arrays.fill(row, -1);
        }
        int i = 0, j = 0, k = 0;
        final int[] dirs = {0, 1, 0, -1, 0};
        while (true) {
            ans[i][j] = head.val;
            head = head.next;
            if (head == null) {
                break;
            }
            while (true) {
                int x = i + dirs[k], y = j + dirs[k + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && ans[x][y] == -1) {
                    i = x;
                    j = y;
                    break;
                }
                k = (k + 1) % 4;
            }
        }
        return ans;
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
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1));
        int i = 0, j = 0, k = 0;
        const int dirs[5] = {0, 1, 0, -1, 0};
        while (1) {
            ans[i][j] = head->val;
            head = head->next;
            if (!head) {
                break;
            }
            while (1) {
                int x = i + dirs[k], y = j + dirs[k + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && ans[x][y] == -1) {
                    i = x;
                    j = y;
                    break;
                }
                k = (k + 1) % 4;
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
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func spiralMatrix(m int, n int, head *ListNode) [][]int {
	ans := make([][]int, m)
	for i := range ans {
		ans[i] = make([]int, n)
		for j := range ans[i] {
			ans[i][j] = -1
		}
	}
	i, j, k := 0, 0, 0
	dirs := [5]int{0, 1, 0, -1, 0}
	for {
		ans[i][j] = head.Val
		if head = head.Next; head == nil {
			break
		}
		for {
			x, y := i+dirs[k], j+dirs[k+1]
			if x >= 0 && x < m && y >= 0 && y < n && ans[x][y] == -1 {
				i, j = x, y
				break
			}
			k = (k + 1) % 4
		}
	}
	return ans
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

function spiralMatrix(m: number, n: number, head: ListNode | null): number[][] {
    const ans: number[][] = Array.from({ length: m }, () => Array(n).fill(-1));
    const dirs: number[] = [0, 1, 0, -1, 0];
    let [i, j, k] = [0, 0, 0];
    while (1) {
        ans[i][j] = head.val;
        head = head.next;
        if (!head) {
            break;
        }
        while (1) {
            const [x, y] = [i + dirs[k], j + dirs[k + 1]];
            if (x >= 0 && x < m && y >= 0 && y < n && ans[x][y] === -1) {
                i = x;
                j = y;
                break;
            }
            k = (k + 1) % 4;
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

<p>给你两个整数：<code>m</code> 和 <code>n</code> ，表示矩阵的维数。</p>

<p>另给你一个整数链表的头节点 <code>head</code> 。</p>

<p>请你生成一个大小为 <code>m x n</code> 的螺旋矩阵，矩阵包含链表中的所有整数。链表中的整数从矩阵 <strong>左上角</strong> 开始、<strong>顺时针 </strong>按 <strong>螺旋</strong> 顺序填充。如果还存在剩余的空格，则用 <code>-1</code> 填充。</p>

<p>返回生成的矩阵。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2300-2399/2326.Spiral%20Matrix%20IV/images/ex1new.jpg" style="width: 240px; height: 150px;">
<pre><strong>输入：</strong>m = 3, n = 5, head = [3,0,2,6,8,1,7,9,4,2,5,5,0]
<strong>输出：</strong>[[3,0,2,6,8],[5,0,-1,-1,1],[5,2,4,9,7]]
<strong>解释：</strong>上图展示了链表中的整数在矩阵中是如何排布的。
注意，矩阵中剩下的空格用 -1 填充。
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2300-2399/2326.Spiral%20Matrix%20IV/images/ex2.jpg" style="width: 221px; height: 60px;">
<pre><strong>输入：</strong>m = 1, n = 4, head = [0,1,2]
<strong>输出：</strong>[[0,1,2,-1]]
<strong>解释：</strong>上图展示了链表中的整数在矩阵中是如何从左到右排布的。 
注意，矩阵中剩下的空格用 -1 填充。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= m, n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= m * n &lt;= 10<sup>5</sup></code></li>
	<li>链表中节点数目在范围 <code>[1, m * n]</code> 内</li>
	<li><code>0 &lt;= Node.val &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们定义一个二维数组 $\textit{ans}$，用来存放链表中的元素，初始时全部填充为 $-1$。定义三个变量 $i, j, k$，分别表示当前的行、列和方向。定义一个数组 $\textit{dirs}$，表示四个方向的偏移量。

然后我们开始遍历链表，每次遍历一个节点，就将当前节点的值填充到 $\textit{ans}[i][j]$ 中，然后更新链表的指针，如果链表为空，说明所有的元素都已经填充完毕，退出循环。

否则，我们需要找到下一个元素的位置，我们可以通过当前位置 $(i, j)$ 和当前方向 $k$ 来计算下一个位置 $(x, y)$，如果 $(x, y)$ 在矩阵的范围内，并且 $\textit{ans}[x][y]$ 为 $-1$，说明 $(x, y)$ 还没有被填充过，我们就将 $(x, y)$ 作为下一个位置，否则我们需要更换方向。

遍历完链表之后，我们就得到了一个螺旋矩阵，返回即可。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别表示矩阵的行数和列数。

<!-- tabs:start -->

#### Python3

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def spiralMatrix(self, m: int, n: int, head: Optional[ListNode]) -> List[List[int]]:
        ans = [[-1] * n for _ in range(m)]
        i = j = k = 0
        dirs = (0, 1, 0, -1, 0)
        while 1:
            ans[i][j] = head.val
            head = head.next
            if head is None:
                break
            while 1:
                x, y = i + dirs[k], j + dirs[k + 1]
                if 0 <= x < m and 0 <= y < n and ans[x][y] == -1:
                    i, j = x, y
                    break
                k = (k + 1) % 4
        return ans
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
class Solution {
    public int[][] spiralMatrix(int m, int n, ListNode head) {
        int[][] ans = new int[m][n];
        for (var row : ans) {
            Arrays.fill(row, -1);
        }
        int i = 0, j = 0, k = 0;
        final int[] dirs = {0, 1, 0, -1, 0};
        while (true) {
            ans[i][j] = head.val;
            head = head.next;
            if (head == null) {
                break;
            }
            while (true) {
                int x = i + dirs[k], y = j + dirs[k + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && ans[x][y] == -1) {
                    i = x;
                    j = y;
                    break;
                }
                k = (k + 1) % 4;
            }
        }
        return ans;
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
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1));
        int i = 0, j = 0, k = 0;
        const int dirs[5] = {0, 1, 0, -1, 0};
        while (1) {
            ans[i][j] = head->val;
            head = head->next;
            if (!head) {
                break;
            }
            while (1) {
                int x = i + dirs[k], y = j + dirs[k + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && ans[x][y] == -1) {
                    i = x;
                    j = y;
                    break;
                }
                k = (k + 1) % 4;
            }
        }
        return ans;
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
func spiralMatrix(m int, n int, head *ListNode) [][]int {
	ans := make([][]int, m)
	for i := range ans {
		ans[i] = make([]int, n)
		for j := range ans[i] {
			ans[i][j] = -1
		}
	}
	i, j, k := 0, 0, 0
	dirs := [5]int{0, 1, 0, -1, 0}
	for {
		ans[i][j] = head.Val
		if head = head.Next; head == nil {
			break
		}
		for {
			x, y := i+dirs[k], j+dirs[k+1]
			if x >= 0 && x < m && y >= 0 && y < n && ans[x][y] == -1 {
				i, j = x, y
				break
			}
			k = (k + 1) % 4
		}
	}
	return ans
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

function spiralMatrix(m: number, n: number, head: ListNode | null): number[][] {
    const ans: number[][] = Array.from({ length: m }, () => Array(n).fill(-1));
    const dirs: number[] = [0, 1, 0, -1, 0];
    let [i, j, k] = [0, 0, 0];
    while (1) {
        ans[i][j] = head.val;
        head = head.next;
        if (!head) {
            break;
        }
        while (1) {
            const [x, y] = [i + dirs[k], j + dirs[k + 1]];
            if (x >= 0 && x < m && y >= 0 && y < n && ans[x][y] === -1) {
                i = x;
                j = y;
                break;
            }
            k = (k + 1) % 4;
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

# [2327. 知道秘密的人数](https://leetcode.cn/problems/number-of-people-aware-of-a-secret){#2327}

{{< tabs "2327" >}}

{{% tab "python" %}}
```python
class Solution:
    def peopleAwareOfSecret(self, n: int, delay: int, forget: int) -> int:
        m = (n << 1) + 10
        d = [0] * m
        cnt = [0] * m
        cnt[1] = 1
        for i in range(1, n + 1):
            if cnt[i]:
                d[i] += cnt[i]
                d[i + forget] -= cnt[i]
                nxt = i + delay
                while nxt < i + forget:
                    cnt[nxt] += cnt[i]
                    nxt += 1
        mod = 10**9 + 7
        return sum(d[: n + 1]) % mod
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int peopleAwareOfSecret(int n, int delay, int forget) {
        final int mod = (int) 1e9 + 7;
        int m = (n << 1) + 10;
        long[] d = new long[m];
        long[] cnt = new long[m];
        cnt[1] = 1;
        for (int i = 1; i <= n; ++i) {
            if (cnt[i] > 0) {
                d[i] = (d[i] + cnt[i]) % mod;
                d[i + forget] = (d[i + forget] - cnt[i] + mod) % mod;
                int nxt = i + delay;
                while (nxt < i + forget) {
                    cnt[nxt] = (cnt[nxt] + cnt[i]) % mod;
                    ++nxt;
                }
            }
        }
        long ans = 0;
        for (int i = 1; i <= n; ++i) {
            ans = (ans + d[i]) % mod;
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
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int mod = 1e9 + 7;
        int m = (n << 1) + 10;
        vector<long long> d(m), cnt(m);
        cnt[1] = 1;
        for (int i = 1; i <= n; i++) {
            if (cnt[i]) {
                d[i] = (d[i] + cnt[i]) % mod;
                d[i + forget] = (d[i + forget] - cnt[i] + mod) % mod;
                int nxt = i + delay;
                while (nxt < i + forget) {
                    cnt[nxt] = (cnt[nxt] + cnt[i]) % mod;
                    nxt++;
                }
            }
        }
        long long ans = 0;
        for (int i = 0; i <= n; i++) {
            ans += d[i];
        }
        return ans % mod;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func peopleAwareOfSecret(n int, delay int, forget int) int {
	m := (n << 1) + 10
	d := make([]int, m)
	cnt := make([]int, m)
	mod := int(1e9) + 7
	cnt[1] = 1
	for i := 1; i <= n; i++ {
		if cnt[i] == 0 {
			continue
		}
		d[i] = (d[i] + cnt[i]) % mod
		d[i+forget] = (d[i+forget] - cnt[i] + mod) % mod
		nxt := i + delay
		for nxt < i+forget {
			cnt[nxt] = (cnt[nxt] + cnt[i]) % mod
			nxt++
		}
	}
	ans := 0
	for i := 1; i <= n; i++ {
		ans = (ans + d[i]) % mod
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function peopleAwareOfSecret(n: number, delay: number, forget: number): number {
    const mod = 1e9 + 7;
    const m = (n << 1) + 10;
    const d: number[] = Array(m).fill(0);
    const cnt: number[] = Array(m).fill(0);

    cnt[1] = 1;
    for (let i = 1; i <= n; ++i) {
        if (cnt[i] > 0) {
            d[i] = (d[i] + cnt[i]) % mod;
            d[i + forget] = (d[i + forget] - cnt[i] + mod) % mod;
            let nxt = i + delay;
            while (nxt < i + forget) {
                cnt[nxt] = (cnt[nxt] + cnt[i]) % mod;
                ++nxt;
            }
        }
    }

    let ans = 0;
    for (let i = 1; i <= n; ++i) {
        ans = (ans + d[i]) % mod;
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn people_aware_of_secret(n: i32, delay: i32, forget: i32) -> i32 {
        let n = n as usize;
        let delay = delay as usize;
        let forget = forget as usize;
        let m = (n << 1) + 10;
        let modulo: i64 = 1_000_000_007;

        let mut d = vec![0i64; m];
        let mut cnt = vec![0i64; m];

        cnt[1] = 1;
        for i in 1..=n {
            if cnt[i] > 0 {
                d[i] = (d[i] + cnt[i]) % modulo;
                d[i + forget] = (d[i + forget] - cnt[i] + modulo) % modulo;
                let mut nxt = i + delay;
                while nxt < i + forget {
                    cnt[nxt] = (cnt[nxt] + cnt[i]) % modulo;
                    nxt += 1;
                }
            }
        }

        let mut ans: i64 = 0;
        for i in 1..=n {
            ans = (ans + d[i]) % modulo;
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

<p>在第 <code>1</code>&nbsp;天，有一个人发现了一个秘密。</p>

<p>给你一个整数&nbsp;<code>delay</code>&nbsp;，表示每个人会在发现秘密后的 <code>delay</code>&nbsp;天之后，<strong>每天</strong>&nbsp;给一个新的人&nbsp;<strong>分享</strong>&nbsp;秘密。同时给你一个整数&nbsp;<code>forget</code>&nbsp;，表示每个人在发现秘密&nbsp;<code>forget</code>&nbsp;天之后会&nbsp;<strong>忘记</strong>&nbsp;这个秘密。一个人&nbsp;<strong>不能</strong>&nbsp;在忘记秘密那一天及之后的日子里分享秘密。</p>

<p>给你一个整数&nbsp;<code>n</code>&nbsp;，请你返回在第 <code>n</code>&nbsp;天结束时，知道秘密的人数。由于答案可能会很大，请你将结果对&nbsp;<code>10<sup>9</sup> + 7</code>&nbsp;<strong>取余</strong>&nbsp;后返回。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>n = 6, delay = 2, forget = 4
<b>输出：</b>5
<strong>解释：</strong>
第 1 天：假设第一个人叫 A 。（一个人知道秘密）
第 2 天：A 是唯一一个知道秘密的人。（一个人知道秘密）
第 3 天：A 把秘密分享给 B 。（两个人知道秘密）
第 4 天：A 把秘密分享给一个新的人 C 。（三个人知道秘密）
第 5 天：A 忘记了秘密，B 把秘密分享给一个新的人 D 。（三个人知道秘密）
第 6 天：B 把秘密分享给 E，C 把秘密分享给 F 。（五个人知道秘密）
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>n = 4, delay = 1, forget = 3
<b>输出：</b>6
<strong>解释：</strong>
第 1 天：第一个知道秘密的人为 A 。（一个人知道秘密）
第 2 天：A 把秘密分享给 B 。（两个人知道秘密）
第 3 天：A 和 B 把秘密分享给 2 个新的人 C 和 D 。（四个人知道秘密）
第 4 天：A 忘记了秘密，B、C、D 分别分享给 3 个新的人。（六个人知道秘密）
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 1000</code></li>
	<li><code>1 &lt;= delay &lt; forget &lt;= n</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：差分数组

我们用一个差分数组 $d[i]$ 来记录第 $i$ 天知道秘密的人数变化情况，用一个数组 $cnt[i]$ 来记录第 $i$ 天新得知秘密的人数。

那么，对于第 $i$ 天新得知秘密的 $cnt[i]$ 个人来说，他们会在 $[i+\text{delay}, i+\text{forget})$ 这段时间内每天都能分享给另外 $cnt[i]$ 个人。

答案为 $\sum_{i=1}^{n} d[i]$。

时间复杂度 $O(n^2)$，空间复杂度 $O(n)$。其中 $n$ 为题目给定的整数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def peopleAwareOfSecret(self, n: int, delay: int, forget: int) -> int:
        m = (n << 1) + 10
        d = [0] * m
        cnt = [0] * m
        cnt[1] = 1
        for i in range(1, n + 1):
            if cnt[i]:
                d[i] += cnt[i]
                d[i + forget] -= cnt[i]
                nxt = i + delay
                while nxt < i + forget:
                    cnt[nxt] += cnt[i]
                    nxt += 1
        mod = 10**9 + 7
        return sum(d[: n + 1]) % mod
```

#### Java

```java
class Solution {
    public int peopleAwareOfSecret(int n, int delay, int forget) {
        final int mod = (int) 1e9 + 7;
        int m = (n << 1) + 10;
        long[] d = new long[m];
        long[] cnt = new long[m];
        cnt[1] = 1;
        for (int i = 1; i <= n; ++i) {
            if (cnt[i] > 0) {
                d[i] = (d[i] + cnt[i]) % mod;
                d[i + forget] = (d[i + forget] - cnt[i] + mod) % mod;
                int nxt = i + delay;
                while (nxt < i + forget) {
                    cnt[nxt] = (cnt[nxt] + cnt[i]) % mod;
                    ++nxt;
                }
            }
        }
        long ans = 0;
        for (int i = 1; i <= n; ++i) {
            ans = (ans + d[i]) % mod;
        }
        return (int) ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int mod = 1e9 + 7;
        int m = (n << 1) + 10;
        vector<long long> d(m), cnt(m);
        cnt[1] = 1;
        for (int i = 1; i <= n; i++) {
            if (cnt[i]) {
                d[i] = (d[i] + cnt[i]) % mod;
                d[i + forget] = (d[i + forget] - cnt[i] + mod) % mod;
                int nxt = i + delay;
                while (nxt < i + forget) {
                    cnt[nxt] = (cnt[nxt] + cnt[i]) % mod;
                    nxt++;
                }
            }
        }
        long long ans = 0;
        for (int i = 0; i <= n; i++) {
            ans += d[i];
        }
        return ans % mod;
    }
};
```

#### Go

```go
func peopleAwareOfSecret(n int, delay int, forget int) int {
	m := (n << 1) + 10
	d := make([]int, m)
	cnt := make([]int, m)
	mod := int(1e9) + 7
	cnt[1] = 1
	for i := 1; i <= n; i++ {
		if cnt[i] == 0 {
			continue
		}
		d[i] = (d[i] + cnt[i]) % mod
		d[i+forget] = (d[i+forget] - cnt[i] + mod) % mod
		nxt := i + delay
		for nxt < i+forget {
			cnt[nxt] = (cnt[nxt] + cnt[i]) % mod
			nxt++
		}
	}
	ans := 0
	for i := 1; i <= n; i++ {
		ans = (ans + d[i]) % mod
	}
	return ans
}
```

#### TypeScript

```ts
function peopleAwareOfSecret(n: number, delay: number, forget: number): number {
    const mod = 1e9 + 7;
    const m = (n << 1) + 10;
    const d: number[] = Array(m).fill(0);
    const cnt: number[] = Array(m).fill(0);

    cnt[1] = 1;
    for (let i = 1; i <= n; ++i) {
        if (cnt[i] > 0) {
            d[i] = (d[i] + cnt[i]) % mod;
            d[i + forget] = (d[i + forget] - cnt[i] + mod) % mod;
            let nxt = i + delay;
            while (nxt < i + forget) {
                cnt[nxt] = (cnt[nxt] + cnt[i]) % mod;
                ++nxt;
            }
        }
    }

    let ans = 0;
    for (let i = 1; i <= n; ++i) {
        ans = (ans + d[i]) % mod;
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn people_aware_of_secret(n: i32, delay: i32, forget: i32) -> i32 {
        let n = n as usize;
        let delay = delay as usize;
        let forget = forget as usize;
        let m = (n << 1) + 10;
        let modulo: i64 = 1_000_000_007;

        let mut d = vec![0i64; m];
        let mut cnt = vec![0i64; m];

        cnt[1] = 1;
        for i in 1..=n {
            if cnt[i] > 0 {
                d[i] = (d[i] + cnt[i]) % modulo;
                d[i + forget] = (d[i + forget] - cnt[i] + modulo) % modulo;
                let mut nxt = i + delay;
                while nxt < i + forget {
                    cnt[nxt] = (cnt[nxt] + cnt[i]) % modulo;
                    nxt += 1;
                }
            }
        }

        let mut ans: i64 = 0;
        for i in 1..=n {
            ans = (ans + d[i]) % modulo;
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

# [2328. 网格图中递增路径的数目](https://leetcode.cn/problems/number-of-increasing-paths-in-a-grid){#2328}

{{< tabs "2328" >}}

{{% tab "python" %}}
```python
class Solution:
    def countPaths(self, grid: List[List[int]]) -> int:
        @cache
        def dfs(i: int, j: int) -> int:
            ans = 1
            for a, b in pairwise((-1, 0, 1, 0, -1)):
                x, y = i + a, j + b
                if 0 <= x < m and 0 <= y < n and grid[i][j] < grid[x][y]:
                    ans = (ans + dfs(x, y)) % mod
            return ans

        mod = 10**9 + 7
        m, n = len(grid), len(grid[0])
        return sum(dfs(i, j) for i in range(m) for j in range(n)) % mod
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[][] f;
    private int[][] grid;
    private int m;
    private int n;
    private final int mod = (int) 1e9 + 7;

    public int countPaths(int[][] grid) {
        m = grid.length;
        n = grid[0].length;
        this.grid = grid;
        f = new int[m][n];
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans = (ans + dfs(i, j)) % mod;
            }
        }
        return ans;
    }

    private int dfs(int i, int j) {
        if (f[i][j] != 0) {
            return f[i][j];
        }
        int ans = 1;
        int[] dirs = {-1, 0, 1, 0, -1};
        for (int k = 0; k < 4; ++k) {
            int x = i + dirs[k], y = j + dirs[k + 1];
            if (x >= 0 && x < m && y >= 0 && y < n && grid[i][j] < grid[x][y]) {
                ans = (ans + dfs(x, y)) % mod;
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
    int countPaths(vector<vector<int>>& grid) {
        const int mod = 1e9 + 7;
        int m = grid.size(), n = grid[0].size();
        int f[m][n];
        memset(f, 0, sizeof(f));
        function<int(int, int)> dfs = [&](int i, int j) -> int {
            if (f[i][j]) {
                return f[i][j];
            }
            int ans = 1;
            int dirs[5] = {-1, 0, 1, 0, -1};
            for (int k = 0; k < 4; ++k) {
                int x = i + dirs[k], y = j + dirs[k + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && grid[i][j] < grid[x][y]) {
                    ans = (ans + dfs(x, y)) % mod;
                }
            }
            return f[i][j] = ans;
        };
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans = (ans + dfs(i, j)) % mod;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countPaths(grid [][]int) (ans int) {
	const mod = 1e9 + 7
	m, n := len(grid), len(grid[0])
	f := make([][]int, m)
	for i := range f {
		f[i] = make([]int, n)
	}
	var dfs func(int, int) int
	dfs = func(i, j int) int {
		if f[i][j] != 0 {
			return f[i][j]
		}
		f[i][j] = 1
		dirs := [5]int{-1, 0, 1, 0, -1}
		for k := 0; k < 4; k++ {
			x, y := i+dirs[k], j+dirs[k+1]
			if x >= 0 && x < m && y >= 0 && y < n && grid[i][j] < grid[x][y] {
				f[i][j] = (f[i][j] + dfs(x, y)) % mod
			}
		}
		return f[i][j]
	}
	for i, row := range grid {
		for j := range row {
			ans = (ans + dfs(i, j)) % mod
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countPaths(grid: number[][]): number {
    const mod = 1e9 + 7;
    const m = grid.length;
    const n = grid[0].length;
    const f = new Array(m).fill(0).map(() => new Array(n).fill(0));
    const dfs = (i: number, j: number): number => {
        if (f[i][j]) {
            return f[i][j];
        }
        let ans = 1;
        const dirs: number[] = [-1, 0, 1, 0, -1];
        for (let k = 0; k < 4; ++k) {
            const x = i + dirs[k];
            const y = j + dirs[k + 1];
            if (x >= 0 && x < m && y >= 0 && y < n && grid[i][j] < grid[x][y]) {
                ans = (ans + dfs(x, y)) % mod;
            }
        }
        return (f[i][j] = ans);
    };
    let ans = 0;
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            ans = (ans + dfs(i, j)) % mod;
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

<p>给你一个&nbsp;<code>m x n</code>&nbsp;的整数网格图&nbsp;<code>grid</code>&nbsp;，你可以从一个格子移动到&nbsp;<code>4</code>&nbsp;个方向相邻的任意一个格子。</p>

<p>请你返回在网格图中从 <strong>任意</strong>&nbsp;格子出发，达到 <strong>任意</strong>&nbsp;格子，且路径中的数字是 <strong>严格递增</strong>&nbsp;的路径数目。由于答案可能会很大，请将结果对&nbsp;<code>10<sup>9</sup> + 7</code>&nbsp;<strong>取余</strong>&nbsp;后返回。</p>

<p>如果两条路径中访问过的格子不是完全相同的，那么它们视为两条不同的路径。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2300-2399/2328.Number%20of%20Increasing%20Paths%20in%20a%20Grid/images/griddrawio-4.png" style="width: 181px; height: 121px;"></p>

<pre><b>输入：</b>grid = [[1,1],[3,4]]
<b>输出：</b>8
<b>解释：</b>严格递增路径包括：
- 长度为 1 的路径：[1]，[1]，[3]，[4] 。
- 长度为 2 的路径：[1 -&gt; 3]，[1 -&gt; 4]，[3 -&gt; 4] 。
- 长度为 3 的路径：[1 -&gt; 3 -&gt; 4] 。
路径数目为 4 + 3 + 1 = 8 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>grid = [[1],[2]]
<b>输出：</b>3
<b>解释：</b>严格递增路径包括：
- 长度为 1 的路径：[1]，[2] 。
- 长度为 2 的路径：[1 -&gt; 2] 。
路径数目为 2 + 1 = 3 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 1000</code></li>
	<li><code>1 &lt;= m * n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= grid[i][j] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

我们设计一个函数 $dfs(i, j)$，表示从网格图中的第 $i$ 行第 $j$ 列的格子出发，能够到达任意格子的严格递增路径数目。那么答案就是 $\sum_{i=0}^{m-1} \sum_{j=0}^{n-1} dfs(i, j)$。搜索过程中，我们可以用一个二维数组 $f$ 记录已经计算过的结果，避免重复计算。

函数 $dfs(i, j)$ 的计算过程如下：

-   如果 $f[i][j]$ 不为 $0$，说明已经计算过，直接返回 $f[i][j]$；
-   否则，我们初始化 $f[i][j] = 1$，然后枚举 $(i, j)$ 的四个方向，如果某个方向的格子 $(x, y)$ 满足 $0 \leq x \lt m$, $0 \leq y \lt n$ 且 $grid[i][j] \lt grid[x][y]$，我们就可以从格子 $(i, j)$ 出发，到达格子 $(x, y)$，且路径上的数字是严格递增的，因此有 $f[i][j] += dfs(x, y)$。

最后，我们返回 $f[i][j]$。

答案为 $\sum_{i=0}^{m-1} \sum_{j=0}^{n-1} dfs(i, j)$。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别是网格图的行数和列数。

相似题目：

-   [329. 矩阵中的最长递增路径](https://github.com/doocs/leetcode/blob/main/solution/0300-0399/0329.Longest%20Increasing%20Path%20in%20a%20Matrix/README.md)。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countPaths(self, grid: List[List[int]]) -> int:
        @cache
        def dfs(i: int, j: int) -> int:
            ans = 1
            for a, b in pairwise((-1, 0, 1, 0, -1)):
                x, y = i + a, j + b
                if 0 <= x < m and 0 <= y < n and grid[i][j] < grid[x][y]:
                    ans = (ans + dfs(x, y)) % mod
            return ans

        mod = 10**9 + 7
        m, n = len(grid), len(grid[0])
        return sum(dfs(i, j) for i in range(m) for j in range(n)) % mod
```

#### Java

```java
class Solution {
    private int[][] f;
    private int[][] grid;
    private int m;
    private int n;
    private final int mod = (int) 1e9 + 7;

    public int countPaths(int[][] grid) {
        m = grid.length;
        n = grid[0].length;
        this.grid = grid;
        f = new int[m][n];
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans = (ans + dfs(i, j)) % mod;
            }
        }
        return ans;
    }

    private int dfs(int i, int j) {
        if (f[i][j] != 0) {
            return f[i][j];
        }
        int ans = 1;
        int[] dirs = {-1, 0, 1, 0, -1};
        for (int k = 0; k < 4; ++k) {
            int x = i + dirs[k], y = j + dirs[k + 1];
            if (x >= 0 && x < m && y >= 0 && y < n && grid[i][j] < grid[x][y]) {
                ans = (ans + dfs(x, y)) % mod;
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
    int countPaths(vector<vector<int>>& grid) {
        const int mod = 1e9 + 7;
        int m = grid.size(), n = grid[0].size();
        int f[m][n];
        memset(f, 0, sizeof(f));
        function<int(int, int)> dfs = [&](int i, int j) -> int {
            if (f[i][j]) {
                return f[i][j];
            }
            int ans = 1;
            int dirs[5] = {-1, 0, 1, 0, -1};
            for (int k = 0; k < 4; ++k) {
                int x = i + dirs[k], y = j + dirs[k + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && grid[i][j] < grid[x][y]) {
                    ans = (ans + dfs(x, y)) % mod;
                }
            }
            return f[i][j] = ans;
        };
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans = (ans + dfs(i, j)) % mod;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func countPaths(grid [][]int) (ans int) {
	const mod = 1e9 + 7
	m, n := len(grid), len(grid[0])
	f := make([][]int, m)
	for i := range f {
		f[i] = make([]int, n)
	}
	var dfs func(int, int) int
	dfs = func(i, j int) int {
		if f[i][j] != 0 {
			return f[i][j]
		}
		f[i][j] = 1
		dirs := [5]int{-1, 0, 1, 0, -1}
		for k := 0; k < 4; k++ {
			x, y := i+dirs[k], j+dirs[k+1]
			if x >= 0 && x < m && y >= 0 && y < n && grid[i][j] < grid[x][y] {
				f[i][j] = (f[i][j] + dfs(x, y)) % mod
			}
		}
		return f[i][j]
	}
	for i, row := range grid {
		for j := range row {
			ans = (ans + dfs(i, j)) % mod
		}
	}
	return
}
```

#### TypeScript

```ts
function countPaths(grid: number[][]): number {
    const mod = 1e9 + 7;
    const m = grid.length;
    const n = grid[0].length;
    const f = new Array(m).fill(0).map(() => new Array(n).fill(0));
    const dfs = (i: number, j: number): number => {
        if (f[i][j]) {
            return f[i][j];
        }
        let ans = 1;
        const dirs: number[] = [-1, 0, 1, 0, -1];
        for (let k = 0; k < 4; ++k) {
            const x = i + dirs[k];
            const y = j + dirs[k + 1];
            if (x >= 0 && x < m && y >= 0 && y < n && grid[i][j] < grid[x][y]) {
                ans = (ans + dfs(x, y)) % mod;
            }
        }
        return (f[i][j] = ans);
    };
    let ans = 0;
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            ans = (ans + dfs(i, j)) % mod;
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

# [2329. 产品销售分析Ⅴ 🔒](https://leetcode.cn/problems/product-sales-analysis-v){#2329}

{{< tabs "2329" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT user_id, SUM(quantity * price) AS spending
FROM
    Sales
    JOIN Product USING (product_id)
GROUP BY 1
ORDER BY 2 DESC, 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code>Sales</code></p>

<pre>
+-------------+-------+
| Column Name | Type  |
+-------------+-------+
| sale_id     | int   |
| product_id  | int   |
| user_id     | int   |
| quantity    | int   |
+-------------+-------+
sale_id 包含唯一值。
product_id 是 Product 表的外键。
这个表中的每一行展示了产品的 ID 以及某个用户购买的数量。 
</pre>

<p>表：<code>Product</code></p>

<pre>
+-------------+------+
| Column Name | Type |
+-------------+------+
| product_id  | int  |
| price       | int  |
+-------------+------+
product_id 包含唯一值。
这张表中的每一行均表示了某个产品的价格。
</pre>

<p>&nbsp;</p>

<p>编写解决方案，获取每个用户的消费额。</p>

<p>按用户消费额 <code>spending</code> <strong>递减</strong>的顺序返回结果。在消费额相等的情况下，以 <code>user_id</code> 递增的顺序将其排序。</p>

<p>结果的格式如下面例子所示：</p>

<p>&nbsp;</p>

<p><strong>示例 1 ：</strong></p>

<pre>
<strong>输入：</strong>
Sales 表：
+---------+------------+---------+----------+
| sale_id | product_id | user_id | quantity |
+---------+------------+---------+----------+
| 1       | 1          | 101     | 10       |
| 2       | 2          | 101     | 1        |
| 3       | 3          | 102     | 3        |
| 4       | 3          | 102     | 2        |
| 5       | 2          | 103     | 3        |
+---------+------------+---------+----------+
Product 表：
+------------+-------+
| product_id | price |
+------------+-------+
| 1          | 10    |
| 2          | 25    |
| 3          | 15    |
+------------+-------+
<strong>输出：</strong>
+---------+----------+
| user_id | spending |
+---------+----------+
| 101     | 125      |
| 102     | 75       |
| 103     | 75       |
+---------+----------+
<strong>解释：</strong>
用户 101 的消费额为 10 * 10 + 1 * 25 = 125 。
用户 102 的消费额为 3 * 15 + 2 * 15 = 75 。
用户 103 的消费额为 3 * 25 = 75 。
用户 101 排在最前，用户 102 与用户 103 的消费额相同，根据 ID 我们可以进一步确认排名，所以用户 102 排在 103 前面。
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
SELECT user_id, SUM(quantity * price) AS spending
FROM
    Sales
    JOIN Product USING (product_id)
GROUP BY 1
ORDER BY 2 DESC, 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
