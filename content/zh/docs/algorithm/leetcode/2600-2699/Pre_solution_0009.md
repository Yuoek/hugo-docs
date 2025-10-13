---
title: "2680_最大或值"
date: 2025-10-08T18:39:28+08:00
weight: 9
tags: [二叉树, 位运算, 前缀和, 动态规划, 哈希表, 图, 并查集, 广度优先搜索, 排序, 数学, 数据库, 数组, 树, 模拟, 深度优先搜索, 矩阵, 贪心]
---

{{< markmap >}}
### [2680_最大或值](#2680)
#### [贪心](#2680)
#### [位运算](#2680)
#### [数组](#2680)
#### [前缀和](#2680)
### [2681_英雄的力量](#2681)
#### [数组](#2681)
#### [数学](#2681)
#### [动态规划](#2681)
#### [前缀和](#2681)
#### [排序](#2681)
### [2682_找出转圈游戏输家](#2682)
#### [数组](#2682)
#### [哈希表](#2682)
#### [模拟](#2682)
### [2683_相邻值的按位异或](#2683)
#### [位运算](#2683)
#### [数组](#2683)
### [2684_矩阵中移动的最大次数](#2684)
#### [数组](#2684)
#### [动态规划](#2684)
#### [矩阵](#2684)
### [2685_统计完全连通分量的数量](#2685)
#### [深度优先搜索](#2685)
#### [广度优先搜索](#2685)
#### [并查集](#2685)
#### [图](#2685)
### [2686_即时食物配送 III 🔒](#2686)
#### [数据库](#2686)
### [2687_自行车的最后使用时间 🔒](#2687)
#### [数据库](#2687)
### [2688_查找活跃用户 🔒](#2688)
#### [数据库](#2688)
### [2689_从 Rope 树中提取第 K 个字符 🔒](#2689)
#### [树](#2689)
#### [深度优先搜索](#2689)
#### [二叉树](#2689)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2680_最大或值
___
#### 贪心
___
#### 位运算
___
#### 数组
___
#### 前缀和
---
### 2681_英雄的力量
___
#### 数组
___
#### 数学
___
#### 动态规划
___
#### 前缀和
___
#### 排序
---
### 2682_找出转圈游戏输家
___
#### 数组
___
#### 哈希表
___
#### 模拟
---
### 2683_相邻值的按位异或
___
#### 位运算
___
#### 数组
---
### 2684_矩阵中移动的最大次数
___
#### 数组
___
#### 动态规划
___
#### 矩阵
---
### 2685_统计完全连通分量的数量
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 并查集
___
#### 图
---
### 2686_即时食物配送 III 🔒
___
#### 数据库
---
### 2687_自行车的最后使用时间 🔒
___
#### 数据库
---
### 2688_查找活跃用户 🔒
___
#### 数据库
---
### 2689_从 Rope 树中提取第 K 个字符 🔒
___
#### 树
___
#### 深度优先搜索
___
#### 二叉树
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二叉树 | 位运算 | 前缀和 |
| 动态规划 | 哈希表 | 图 |
| 并查集 | 广度优先搜索 | 排序 |
| 数学 | 数据库 | 数组 |
| 树 | 模拟 | 深度优先搜索 |
| 矩阵 | 贪心 |  |

# [2680. 最大或值](https://leetcode.cn/problems/maximum-or){#2680}

{{< tabs "2680" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumOr(self, nums: List[int], k: int) -> int:
        n = len(nums)
        suf = [0] * (n + 1)
        for i in range(n - 1, -1, -1):
            suf[i] = suf[i + 1] | nums[i]
        ans = pre = 0
        for i, x in enumerate(nums):
            ans = max(ans, pre | (x << k) | suf[i + 1])
            pre |= x
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long maximumOr(int[] nums, int k) {
        int n = nums.length;
        long[] suf = new long[n + 1];
        for (int i = n - 1; i >= 0; --i) {
            suf[i] = suf[i + 1] | nums[i];
        }
        long ans = 0, pre = 0;
        for (int i = 0; i < n; ++i) {
            ans = Math.max(ans, pre | (1L * nums[i] << k) | suf[i + 1]);
            pre |= nums[i];
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
    long long maximumOr(vector<int>& nums, int k) {
        int n = nums.size();
        long long suf[n + 1];
        memset(suf, 0, sizeof(suf));
        for (int i = n - 1; i >= 0; --i) {
            suf[i] = suf[i + 1] | nums[i];
        }
        long long ans = 0, pre = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, pre | (1LL * nums[i] << k) | suf[i + 1]);
            pre |= nums[i];
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumOr(nums []int, k int) int64 {
	n := len(nums)
	suf := make([]int, n+1)
	for i := n - 1; i >= 0; i-- {
		suf[i] = suf[i+1] | nums[i]
	}
	ans, pre := 0, 0
	for i, x := range nums {
		ans = max(ans, pre|(nums[i]<<k)|suf[i+1])
		pre |= x
	}
	return int64(ans)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumOr(nums: number[], k: number): number {
    const n = nums.length;
    const suf: bigint[] = Array(n + 1).fill(0n);
    for (let i = n - 1; i >= 0; i--) {
        suf[i] = suf[i + 1] | BigInt(nums[i]);
    }
    let [ans, pre] = [0, 0n];
    for (let i = 0; i < n; i++) {
        ans = Math.max(Number(ans), Number(pre | (BigInt(nums[i]) << BigInt(k)) | suf[i + 1]));
        pre |= BigInt(nums[i]);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn maximum_or(nums: Vec<i32>, k: i32) -> i64 {
        let n = nums.len();
        let mut suf = vec![0; n + 1];

        for i in (0..n).rev() {
            suf[i] = suf[i + 1] | (nums[i] as i64);
        }

        let mut ans = 0i64;
        let mut pre = 0i64;
        let k64 = k as i64;
        for i in 0..n {
            ans = ans.max(pre | ((nums[i] as i64) << k64) | suf[i + 1]);
            pre |= nums[i] as i64;
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

<p>给你一个下标从 <strong>0</strong>&nbsp;开始长度为 <code>n</code>&nbsp;的整数数组&nbsp;<code>nums</code>&nbsp;和一个整数&nbsp;<code>k</code> 。每一次操作中，你可以选择一个数并将它乘&nbsp;<code>2</code>&nbsp;。</p>

<p>你最多可以进行 <code>k</code>&nbsp;次操作，请你返回<em>&nbsp;</em><code>nums[0] | nums[1] | ... | nums[n - 1]</code>&nbsp;的最大值。</p>

<p><code>a | b</code>&nbsp;表示两个整数 <code>a</code>&nbsp;和 <code>b</code>&nbsp;的 <strong>按位或</strong>&nbsp;运算。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [12,9], k = 1
<b>输出：</b>30
<b>解释：</b>如果我们对下标为 1 的元素进行操作，新的数组为 [12,18] 。此时得到最优答案为 12 和 18 的按位或运算的结果，也就是 30 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [8,1,2], k = 2
<b>输出：</b>35
<b>解释：</b>如果我们对下标 0 处的元素进行操作，得到新数组 [32,1,2] 。此时得到最优答案为 32|1|2 = 35 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= k &lt;= 15</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 预处理

我们注意到，为了使得答案最大，我们应该将 $k$ 次乘 $2$ 作用于同一个数。

我们先预处理出数组 $nums$ 的后缀或值数组 $suf$，其中 $suf[i]$ 表示 $nums[i], nums[i + 1], \cdots, nums[n - 1]$ 的按位或值。

接下来，我们从左到右遍历数组 $nums$，同时维护当前的前缀或值 $pre$。对于当前遍历到的位置 $i$，我们将 $nums[i]$ 乘 $2$ 的 $k$ 次方，即 $nums[i] \times 2^k$，与 $pre$ 进行按位或运算，得到的结果再与 $suf[i + 1]$ 进行按位或运算，即可得到以 $nums[i]$ 为最后一个数的最大或值。枚举所有的 $i$，即可得到答案。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumOr(self, nums: List[int], k: int) -> int:
        n = len(nums)
        suf = [0] * (n + 1)
        for i in range(n - 1, -1, -1):
            suf[i] = suf[i + 1] | nums[i]
        ans = pre = 0
        for i, x in enumerate(nums):
            ans = max(ans, pre | (x << k) | suf[i + 1])
            pre |= x
        return ans
```

#### Java

```java
class Solution {
    public long maximumOr(int[] nums, int k) {
        int n = nums.length;
        long[] suf = new long[n + 1];
        for (int i = n - 1; i >= 0; --i) {
            suf[i] = suf[i + 1] | nums[i];
        }
        long ans = 0, pre = 0;
        for (int i = 0; i < n; ++i) {
            ans = Math.max(ans, pre | (1L * nums[i] << k) | suf[i + 1]);
            pre |= nums[i];
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        int n = nums.size();
        long long suf[n + 1];
        memset(suf, 0, sizeof(suf));
        for (int i = n - 1; i >= 0; --i) {
            suf[i] = suf[i + 1] | nums[i];
        }
        long long ans = 0, pre = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, pre | (1LL * nums[i] << k) | suf[i + 1]);
            pre |= nums[i];
        }
        return ans;
    }
};
```

#### Go

```go
func maximumOr(nums []int, k int) int64 {
	n := len(nums)
	suf := make([]int, n+1)
	for i := n - 1; i >= 0; i-- {
		suf[i] = suf[i+1] | nums[i]
	}
	ans, pre := 0, 0
	for i, x := range nums {
		ans = max(ans, pre|(nums[i]<<k)|suf[i+1])
		pre |= x
	}
	return int64(ans)
}
```

#### TypeScript

```ts
function maximumOr(nums: number[], k: number): number {
    const n = nums.length;
    const suf: bigint[] = Array(n + 1).fill(0n);
    for (let i = n - 1; i >= 0; i--) {
        suf[i] = suf[i + 1] | BigInt(nums[i]);
    }
    let [ans, pre] = [0, 0n];
    for (let i = 0; i < n; i++) {
        ans = Math.max(Number(ans), Number(pre | (BigInt(nums[i]) << BigInt(k)) | suf[i + 1]));
        pre |= BigInt(nums[i]);
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn maximum_or(nums: Vec<i32>, k: i32) -> i64 {
        let n = nums.len();
        let mut suf = vec![0; n + 1];

        for i in (0..n).rev() {
            suf[i] = suf[i + 1] | (nums[i] as i64);
        }

        let mut ans = 0i64;
        let mut pre = 0i64;
        let k64 = k as i64;
        for i in 0..n {
            ans = ans.max(pre | ((nums[i] as i64) << k64) | suf[i + 1]);
            pre |= nums[i] as i64;
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

# [2681. 英雄的力量](https://leetcode.cn/problems/power-of-heroes){#2681}

{{< tabs "2681" >}}

{{% tab "python" %}}
```python
class Solution:
    def sumOfPower(self, nums: List[int]) -> int:
        mod = 10**9 + 7
        nums.sort()
        ans = 0
        p = 0
        for x in nums[::-1]:
            ans = (ans + (x * x % mod) * x) % mod
            ans = (ans + x * p) % mod
            p = (p * 2 + x * x) % mod
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int sumOfPower(int[] nums) {
        final int mod = (int) 1e9 + 7;
        Arrays.sort(nums);
        long ans = 0, p = 0;
        for (int i = nums.length - 1; i >= 0; --i) {
            long x = nums[i];
            ans = (ans + (x * x % mod) * x) % mod;
            ans = (ans + x * p % mod) % mod;
            p = (p * 2 + x * x % mod) % mod;
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
    int sumOfPower(vector<int>& nums) {
        const int mod = 1e9 + 7;
        sort(nums.rbegin(), nums.rend());
        long long ans = 0, p = 0;
        for (long long x : nums) {
            ans = (ans + (x * x % mod) * x) % mod;
            ans = (ans + x * p % mod) % mod;
            p = (p * 2 + x * x % mod) % mod;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func sumOfPower(nums []int) (ans int) {
	const mod = 1e9 + 7
	sort.Ints(nums)
	p := 0
	for i := len(nums) - 1; i >= 0; i-- {
		x := nums[i]
		ans = (ans + (x*x%mod)*x) % mod
		ans = (ans + x*p%mod) % mod
		p = (p*2 + x*x%mod) % mod
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function sumOfPower(nums: number[]): number {
    const mod = 10 ** 9 + 7;
    nums.sort((a, b) => a - b);
    let ans = 0;
    let p = 0;
    for (let i = nums.length - 1; i >= 0; --i) {
        const x = BigInt(nums[i]);
        ans = (ans + Number((x * x * x) % BigInt(mod))) % mod;
        ans = (ans + Number((x * BigInt(p)) % BigInt(mod))) % mod;
        p = Number((BigInt(p) * 2n + x * x) % BigInt(mod));
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

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>nums</code>&nbsp;，它表示英雄的能力值。如果我们选出一部分英雄，这组英雄的 <strong>力量</strong>&nbsp;定义为：</p>

<ul>
	<li><code>i<sub>0</sub></code>&nbsp;，<code>i<sub>1</sub></code>&nbsp;，<span style="">... </span><code><span style="">i<sub>k</sub></span></code><span style="">&nbsp;</span>表示这组英雄在数组中的下标。那么这组英雄的力量为&nbsp;<code><font face="monospace">max(nums[</font>i<sub>0</sub><font face="monospace">],nums[</font>i<sub>1</sub><font face="monospace">] ... nums[</font><span style="font-size:10.8333px">i<sub>k</sub></span><font face="monospace">])<sup>2</sup> * min(nums[</font>i<sub>0</sub><font face="monospace">],nums[</font>i<sub>1</sub><font face="monospace">] ... nums[</font><span style="font-size:10.8333px">i<sub>k</sub></span><font face="monospace">])</font></code> 。</li>
</ul>

<p>请你返回所有可能的 <strong>非空</strong> 英雄组的 <strong>力量</strong> 之和。由于答案可能非常大，请你将结果对&nbsp;<code>10<sup>9 </sup>+ 7</code>&nbsp;<strong>取余。</strong></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [2,1,4]
<b>输出：</b>141
<b>解释：</b>
第 1&nbsp;组：[2] 的力量为 2<sup>2</sup>&nbsp;* 2 = 8 。
第 2&nbsp;组：[1] 的力量为 1<sup>2</sup> * 1 = 1 。
第 3&nbsp;组：[4] 的力量为 4<sup>2</sup> * 4 = 64 。
第 4&nbsp;组：[2,1] 的力量为 2<sup>2</sup> * 1 = 4 。
第 5 组：[2,4] 的力量为 4<sup>2</sup> * 2 = 32 。
第 6&nbsp;组：[1,4] 的力量为 4<sup>2</sup> * 1 = 16 。
第​ ​​​​​​7&nbsp;组：[2,1,4] 的力量为 4<sup>2</sup>​​​​​​​ * 1 = 16 。
所有英雄组的力量之和为 8 + 1 + 64 + 4 + 32 + 16 + 16 = 141 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [1,1,1]
<b>输出：</b>7
<b>解释：</b>总共有 7 个英雄组，每一组的力量都是 1 。所以所有英雄组的力量之和为 7 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 数学

我们注意到，题目中涉及到子序列的最大值和最小值，数组中元素的顺序不影响最终的结果，因此我们可以先对数组进行排序。

接下来，我们枚举每个元素作为子序列的最小值，不妨记数组的每个元素为 $a_1, a_2, \cdots, a_n$。以 $a_i$ 作为最小值的子序列的贡献为：

$$
a_i \times (a_{i}^{2} + a_{i+1}^2 + 2 \times a_{i+2}^2 + 4 \times a_{i+3}^2 + \cdots + 2^{n-i-1} \times a_n^2)
$$

我们注意到，每一个 $a_i$ 都会乘上 $a_i^2$，这一部分我们可以直接累加到答案中。剩下的部分，我们可以用一个变量 $p$ 来维护，初始时 $p = 0$。

接下来从右往左枚举 $a_i$，每次我们将 $a_i \times p$ 累加到答案中，然后令 $p = p \times 2 + a_i^2$。

枚举完所有的 $a_i$ 之后，返回答案即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 为数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def sumOfPower(self, nums: List[int]) -> int:
        mod = 10**9 + 7
        nums.sort()
        ans = 0
        p = 0
        for x in nums[::-1]:
            ans = (ans + (x * x % mod) * x) % mod
            ans = (ans + x * p) % mod
            p = (p * 2 + x * x) % mod
        return ans
```

#### Java

```java
class Solution {
    public int sumOfPower(int[] nums) {
        final int mod = (int) 1e9 + 7;
        Arrays.sort(nums);
        long ans = 0, p = 0;
        for (int i = nums.length - 1; i >= 0; --i) {
            long x = nums[i];
            ans = (ans + (x * x % mod) * x) % mod;
            ans = (ans + x * p % mod) % mod;
            p = (p * 2 + x * x % mod) % mod;
        }
        return (int) ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int sumOfPower(vector<int>& nums) {
        const int mod = 1e9 + 7;
        sort(nums.rbegin(), nums.rend());
        long long ans = 0, p = 0;
        for (long long x : nums) {
            ans = (ans + (x * x % mod) * x) % mod;
            ans = (ans + x * p % mod) % mod;
            p = (p * 2 + x * x % mod) % mod;
        }
        return ans;
    }
};
```

#### Go

```go
func sumOfPower(nums []int) (ans int) {
	const mod = 1e9 + 7
	sort.Ints(nums)
	p := 0
	for i := len(nums) - 1; i >= 0; i-- {
		x := nums[i]
		ans = (ans + (x*x%mod)*x) % mod
		ans = (ans + x*p%mod) % mod
		p = (p*2 + x*x%mod) % mod
	}
	return
}
```

#### TypeScript

```ts
function sumOfPower(nums: number[]): number {
    const mod = 10 ** 9 + 7;
    nums.sort((a, b) => a - b);
    let ans = 0;
    let p = 0;
    for (let i = nums.length - 1; i >= 0; --i) {
        const x = BigInt(nums[i]);
        ans = (ans + Number((x * x * x) % BigInt(mod))) % mod;
        ans = (ans + Number((x * BigInt(p)) % BigInt(mod))) % mod;
        p = Number((BigInt(p) * 2n + x * x) % BigInt(mod));
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2682. 找出转圈游戏输家](https://leetcode.cn/problems/find-the-losers-of-the-circular-game){#2682}

{{< tabs "2682" >}}

{{% tab "python" %}}
```python
class Solution:
    def circularGameLosers(self, n: int, k: int) -> List[int]:
        vis = [False] * n
        i, p = 0, 1
        while not vis[i]:
            vis[i] = True
            i = (i + p * k) % n
            p += 1
        return [i + 1 for i in range(n) if not vis[i]]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] circularGameLosers(int n, int k) {
        boolean[] vis = new boolean[n];
        int cnt = 0;
        for (int i = 0, p = 1; !vis[i]; ++p) {
            vis[i] = true;
            ++cnt;
            i = (i + p * k) % n;
        }
        int[] ans = new int[n - cnt];
        for (int i = 0, j = 0; i < n; ++i) {
            if (!vis[i]) {
                ans[j++] = i + 1;
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
    vector<int> circularGameLosers(int n, int k) {
        bool vis[n];
        memset(vis, false, sizeof(vis));
        for (int i = 0, p = 1; !vis[i]; ++p) {
            vis[i] = true;
            i = (i + p * k) % n;
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func circularGameLosers(n int, k int) (ans []int) {
	vis := make([]bool, n)
	for i, p := 0, 1; !vis[i]; p++ {
		vis[i] = true
		i = (i + p*k) % n
	}
	for i, x := range vis {
		if !x {
			ans = append(ans, i+1)
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function circularGameLosers(n: number, k: number): number[] {
    const vis = new Array(n).fill(false);
    const ans: number[] = [];
    for (let i = 0, p = 1; !vis[i]; p++) {
        vis[i] = true;
        i = (i + p * k) % n;
    }
    for (let i = 0; i < vis.length; i++) {
        if (!vis[i]) {
            ans.push(i + 1);
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn circular_game_losers(n: i32, k: i32) -> Vec<i32> {
        let mut vis: Vec<bool> = vec![false; n as usize];

        let mut i = 0;
        let mut p = 1;
        while !vis[i] {
            vis[i] = true;
            i = (i + p * (k as usize)) % (n as usize);
            p += 1;
        }

        let mut ans = Vec::new();
        for i in 0..vis.len() {
            if !vis[i] {
                ans.push((i + 1) as i32);
            }
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

<p><code>n</code> 个朋友在玩游戏。这些朋友坐成一个圈，按 <strong>顺时针方向</strong> 从 <code>1</code> 到 <code>n</code> 编号。准确的说，从第 <code>i</code> 个朋友的位置开始顺时针移动 <code>1</code> 步会到达第 <code>(i + 1)</code> 个朋友的位置（<code>1 &lt;= i &lt; n</code>），而从第 <code>n</code> 个朋友的位置开始顺时针移动 <code>1</code> 步会回到第 <code>1</code> 个朋友的位置。</p>

<p>游戏规则如下：</p>

<p>第 <code>1</code> 个朋友接球。</p>

<ul>
	<li>接着，第 <code>1</code> 个朋友将球传给距离他顺时针方向 <code>k</code> 步的朋友。</li>
	<li>然后，接球的朋友应该把球传给距离他顺时针方向 <code>2 * k</code> 步的朋友。</li>
	<li>接着，接球的朋友应该把球传给距离他顺时针方向 <code>3 * k</code> 步的朋友，以此类推。</li>
</ul>

<p>换句话说，在第 <code>i</code> 轮中持有球的那位朋友需要将球传递给距离他顺时针方向 <code>i * k</code> 步的朋友。</p>

<p>当某个朋友第 2 次接到球时，游戏结束。</p>

<p>在整场游戏中没有接到过球的朋友是 <strong>输家</strong> 。</p>

<p>给你参与游戏的朋友数量 <code>n</code> 和一个整数 <code>k</code> ，请按升序排列返回包含所有输家编号的数组 <code>answer</code> 作为答案。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 5, k = 2
<strong>输出：</strong>[4,5]
<strong>解释：</strong>以下为游戏进行情况：
1）第 1 个朋友接球，第 1 个朋友将球传给距离他顺时针方向 2 步的玩家 —— 第 3 个朋友。
2）第 3 个朋友将球传给距离他顺时针方向 4 步的玩家 —— 第 2 个朋友。
3）第 2 个朋友将球传给距离他顺时针方向 6 步的玩家 —— 第 3 个朋友。
4）第 3 个朋友接到两次球，游戏结束。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 4, k = 4
<strong>输出：</strong>[2,3,4]
<strong>解释：</strong>以下为游戏进行情况：
1）第 1 个朋友接球，第 1 个朋友将球传给距离他顺时针方向 4 步的玩家 —— 第 1 个朋友。
2）第 1 个朋友接到两次球，游戏结束。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= n &lt;= 50</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们用一个数组 `vis` 记录每个朋友是否接到过球，初始时所有朋友都没有接到过球。然后我们按照题目描述的规则模拟游戏的过程，直到某个朋友第二次接到球为止。

在模拟过程中，我们用两个变量 $i$ 和 $p$ 分别表示当前持球的朋友编号和当前传球的步长。初始时 $i=0,p=1$，表示第一个朋友接到球。每次传球时，我们将 $i$ 更新为 $(i+p \times k) \bmod n$，表示下一个接球的朋友编号，然后将 $p$ 更新为 $p+1$，表示下一次传球的步长。当某个朋友第二次接到球时，游戏结束。

最后我们遍历数组 `vis`，将没有接到过球的朋友编号加入答案数组中即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是朋友的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def circularGameLosers(self, n: int, k: int) -> List[int]:
        vis = [False] * n
        i, p = 0, 1
        while not vis[i]:
            vis[i] = True
            i = (i + p * k) % n
            p += 1
        return [i + 1 for i in range(n) if not vis[i]]
```

#### Java

```java
class Solution {
    public int[] circularGameLosers(int n, int k) {
        boolean[] vis = new boolean[n];
        int cnt = 0;
        for (int i = 0, p = 1; !vis[i]; ++p) {
            vis[i] = true;
            ++cnt;
            i = (i + p * k) % n;
        }
        int[] ans = new int[n - cnt];
        for (int i = 0, j = 0; i < n; ++i) {
            if (!vis[i]) {
                ans[j++] = i + 1;
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
    vector<int> circularGameLosers(int n, int k) {
        bool vis[n];
        memset(vis, false, sizeof(vis));
        for (int i = 0, p = 1; !vis[i]; ++p) {
            vis[i] = true;
            i = (i + p * k) % n;
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func circularGameLosers(n int, k int) (ans []int) {
	vis := make([]bool, n)
	for i, p := 0, 1; !vis[i]; p++ {
		vis[i] = true
		i = (i + p*k) % n
	}
	for i, x := range vis {
		if !x {
			ans = append(ans, i+1)
		}
	}
	return
}
```

#### TypeScript

```ts
function circularGameLosers(n: number, k: number): number[] {
    const vis = new Array(n).fill(false);
    const ans: number[] = [];
    for (let i = 0, p = 1; !vis[i]; p++) {
        vis[i] = true;
        i = (i + p * k) % n;
    }
    for (let i = 0; i < vis.length; i++) {
        if (!vis[i]) {
            ans.push(i + 1);
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn circular_game_losers(n: i32, k: i32) -> Vec<i32> {
        let mut vis: Vec<bool> = vec![false; n as usize];

        let mut i = 0;
        let mut p = 1;
        while !vis[i] {
            vis[i] = true;
            i = (i + p * (k as usize)) % (n as usize);
            p += 1;
        }

        let mut ans = Vec::new();
        for i in 0..vis.len() {
            if !vis[i] {
                ans.push((i + 1) as i32);
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

# [2683. 相邻值的按位异或](https://leetcode.cn/problems/neighboring-bitwise-xor){#2683}

{{< tabs "2683" >}}

{{% tab "python" %}}
```python
class Solution:
    def doesValidArrayExist(self, derived: List[int]) -> bool:
        return reduce(xor, derived) == 0
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean doesValidArrayExist(int[] derived) {
        int s = 0;
        for (int x : derived) {
            s ^= x;
        }
        return s == 0;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int s = 0;
        for (int x : derived) {
            s ^= x;
        }
        return s == 0;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func doesValidArrayExist(derived []int) bool {
	s := 0
	for _, x := range derived {
		s ^= x
	}
	return s == 0
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function doesValidArrayExist(derived: number[]): boolean {
    return derived.reduce((acc, x) => acc ^ x) === 0;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn does_valid_array_exist(derived: Vec<i32>) -> bool {
        derived.iter().fold(0, |acc, &x| acc ^ x) == 0
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} derived
 * @return {boolean}
 */
var doesValidArrayExist = function (derived) {
    return derived.reduce((acc, x) => acc ^ x) === 0;
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public bool DoesValidArrayExist(int[] derived) {
        return derived.Aggregate(0, (acc, x) => acc ^ x) == 0;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>下标从 <strong>0</strong> 开始、长度为 <code>n</code> 的数组 <code>derived</code> 是由同样长度为 <code>n</code> 的原始 <strong>二进制数组</strong> <code>original</code> 通过计算相邻值的 <strong>按位异或（⊕）</strong>派生而来。</p>

<p>特别地，对于范围&nbsp;<code>[0, n - 1]</code> 内的每个下标 <code>i</code> ：</p>

<ul>
	<li>如果 <code>i = n - 1</code> ，那么 <code>derived[i] = original[i] ⊕ original[0]</code></li>
	<li>否则 <code>derived[i] = original[i] ⊕ original[i + 1]</code></li>
</ul>

<p>给你一个数组 <code>derived</code> ，请判断是否存在一个能够派生得到 <code>derived</code> 的 <strong>有效原始二进制数组</strong> <code>original</code> 。</p>

<p>如果存在满足要求的原始二进制数组，返回 <em><strong>true</strong> </em>；否则，返回<em> <strong>false</strong> </em>。</p>

<ul>
	<li>二进制数组是仅由 <strong>0</strong> 和 <strong>1</strong> 组成的数组。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>derived = [1,1,0]
<strong>输出：</strong>true
<strong>解释：</strong>能够派生得到 [1,1,0] 的有效原始二进制数组是 [0,1,0] ：
derived[0] = original[0] ⊕ original[1] = 0 ⊕ 1 = 1 
derived[1] = original[1] ⊕ original[2] = 1 ⊕ 0 = 1
derived[2] = original[2] ⊕ original[0] = 0 ⊕ 0 = 0
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>derived = [1,1]
<strong>输出：</strong>true
<strong>解释：</strong>能够派生得到 [1,1] 的有效原始二进制数组是 [0,1] ：
derived[0] = original[0] ⊕ original[1] = 1
derived[1] = original[1] ⊕ original[0] = 1
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>derived = [1,0]
<strong>输出：</strong>false
<strong>解释：</strong>不存在能够派生得到 [1,0] 的有效原始二进制数组。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == derived.length</code></li>
	<li><code>1 &lt;= n&nbsp;&lt;= 10<sup>5</sup></code></li>
	<li><code>derived</code> 中的值不是 <strong>0</strong> 就是 <strong>1</strong> 。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：位运算

我们不妨假设原始二进制数组为 $a$，派生数组为 $b$，那么有：

$$
b_0 = a_0 \oplus a_1 \\
b_1 = a_1 \oplus a_2 \\
\cdots \\
b_{n-1} = a_{n-1} \oplus a_0
$$

由于异或运算满足交换律和结合律，因此有：

$$
b_0 \oplus b_1 \oplus \cdots \oplus b_{n-1} = (a_0 \oplus a_1) \oplus (a_1 \oplus a_2) \oplus \cdots \oplus (a_{n-1} \oplus a_0) = 0
$$

因此，只要派生数组的所有元素的异或和为 $0$，就一定存在一个满足要求的原始二进制数组。

时间复杂度 $O(n)$，其中 $n$ 为数组长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def doesValidArrayExist(self, derived: List[int]) -> bool:
        return reduce(xor, derived) == 0
```

#### Java

```java
class Solution {
    public boolean doesValidArrayExist(int[] derived) {
        int s = 0;
        for (int x : derived) {
            s ^= x;
        }
        return s == 0;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int s = 0;
        for (int x : derived) {
            s ^= x;
        }
        return s == 0;
    }
};
```

#### Go

```go
func doesValidArrayExist(derived []int) bool {
	s := 0
	for _, x := range derived {
		s ^= x
	}
	return s == 0
}
```

#### TypeScript

```ts
function doesValidArrayExist(derived: number[]): boolean {
    return derived.reduce((acc, x) => acc ^ x) === 0;
}
```

#### Rust

```rust
impl Solution {
    pub fn does_valid_array_exist(derived: Vec<i32>) -> bool {
        derived.iter().fold(0, |acc, &x| acc ^ x) == 0
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} derived
 * @return {boolean}
 */
var doesValidArrayExist = function (derived) {
    return derived.reduce((acc, x) => acc ^ x) === 0;
};
```

#### C#

```cs
public class Solution {
    public bool DoesValidArrayExist(int[] derived) {
        return derived.Aggregate(0, (acc, x) => acc ^ x) == 0;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2684. 矩阵中移动的最大次数](https://leetcode.cn/problems/maximum-number-of-moves-in-a-grid){#2684}

{{< tabs "2684" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxMoves(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        q = set(range(m))
        for j in range(n - 1):
            t = set()
            for i in q:
                for k in range(i - 1, i + 2):
                    if 0 <= k < m and grid[i][j] < grid[k][j + 1]:
                        t.add(k)
            if not t:
                return j
            q = t
        return n - 1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxMoves(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        Set<Integer> q = IntStream.range(0, m).boxed().collect(Collectors.toSet());
        for (int j = 0; j < n - 1; ++j) {
            Set<Integer> t = new HashSet<>();
            for (int i : q) {
                for (int k = i - 1; k <= i + 1; ++k) {
                    if (k >= 0 && k < m && grid[i][j] < grid[k][j + 1]) {
                        t.add(k);
                    }
                }
            }
            if (t.isEmpty()) {
                return j;
            }
            q = t;
        }
        return n - 1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        unordered_set<int> q, t;
        for (int i = 0; i < m; ++i) {
            q.insert(i);
        }
        for (int j = 0; j < n - 1; ++j) {
            t.clear();
            for (int i : q) {
                for (int k = i - 1; k <= i + 1; ++k) {
                    if (k >= 0 && k < m && grid[i][j] < grid[k][j + 1]) {
                        t.insert(k);
                    }
                }
            }
            if (t.empty()) {
                return j;
            }
            q.swap(t);
        }
        return n - 1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxMoves(grid [][]int) (ans int) {
	m, n := len(grid), len(grid[0])
	q := map[int]bool{}
	for i := range grid {
		q[i] = true
	}
	for j := 0; j < n-1; j++ {
		t := map[int]bool{}
		for i := range q {
			for k := i - 1; k <= i+1; k++ {
				if k >= 0 && k < m && grid[i][j] < grid[k][j+1] {
					t[k] = true
				}
			}
		}
		if len(t) == 0 {
			return j
		}
		q = t
	}
	return n - 1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxMoves(grid: number[][]): number {
    const m = grid.length;
    const n = grid[0].length;
    let q = new Set<number>(Array.from({ length: m }, (_, i) => i));
    for (let j = 0; j < n - 1; ++j) {
        const t = new Set<number>();
        for (const i of q) {
            for (let k = i - 1; k <= i + 1; ++k) {
                if (k >= 0 && k < m && grid[i][j] < grid[k][j + 1]) {
                    t.add(k);
                }
            }
        }
        if (t.size === 0) {
            return j;
        }
        q = t;
    }
    return n - 1;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong> 开始、大小为 <code>m x n</code> 的矩阵 <code>grid</code> ，矩阵由若干 <strong>正</strong> 整数组成。</p>

<p>你可以从矩阵第一列中的 <strong>任一</strong> 单元格出发，按以下方式遍历&nbsp;<code>grid</code> ：</p>

<ul>
	<li>从单元格 <code>(row, col)</code> 可以移动到&nbsp;<code>(row - 1, col + 1)</code>、<code>(row, col + 1)</code> 和 <code>(row + 1, col + 1)</code> 三个单元格中任一满足值 <strong>严格</strong> 大于当前单元格的单元格。</li>
</ul>

<p>返回你在矩阵中能够 <strong>移动</strong> 的 <strong>最大</strong> 次数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2600-2699/2684.Maximum%20Number%20of%20Moves%20in%20a%20Grid/images/yetgriddrawio-10.png" style="width: 201px; height: 201px;">
<pre><strong>输入：</strong>grid = [[2,4,3,5],[5,4,9,3],[3,4,2,11],[10,9,13,15]]
<strong>输出：</strong>3
<strong>解释：</strong>可以从单元格 (0, 0) 开始并且按下面的路径移动：
- (0, 0) -&gt; (0, 1).
- (0, 1) -&gt; (1, 2).
- (1, 2) -&gt; (2, 3).
可以证明这是能够移动的最大次数。</pre>

<p><strong>示例 2：</strong></p>

<pre><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2600-2699/2684.Maximum%20Number%20of%20Moves%20in%20a%20Grid/images/yetgrid4drawio.png">
<strong>输入：</strong>grid = [[3,2,4],[2,1,9],[1,1,7]]
<strong>输出：</strong>0
<strong>解释：</strong>从第一列的任一单元格开始都无法移动。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>2 &lt;= m, n &lt;= 1000</code></li>
	<li><code>4 &lt;= m * n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= grid[i][j] &lt;= 10<sup>6</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：BFS

我们定义一个队列 $q$，初始时将第一列的所有行坐标加入队列中。

接下来，我们从第一列开始，逐列进行遍历。对于每一列，我们将队列中的所有行坐标依次取出，然后对于每一个行坐标 $i$，我们得到其下一列的所有可能行坐标 $k$，并且满足 $grid[i][j] < grid[k][j + 1]$，将这些行坐标加入到一个新的集合 $t$ 中。如果 $t$ 为空，说明我们无法继续移动，返回当前列数。否则，我们将 $t$ 赋值给 $q$，继续下一列的遍历。

最后，如果我们遍历完了所有列，说明我们可以移动到最后一列，返回 $n - 1$。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m)$。其中 $m$ 和 $n$ 分别是矩阵的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxMoves(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        q = set(range(m))
        for j in range(n - 1):
            t = set()
            for i in q:
                for k in range(i - 1, i + 2):
                    if 0 <= k < m and grid[i][j] < grid[k][j + 1]:
                        t.add(k)
            if not t:
                return j
            q = t
        return n - 1
```

#### Java

```java
class Solution {
    public int maxMoves(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        Set<Integer> q = IntStream.range(0, m).boxed().collect(Collectors.toSet());
        for (int j = 0; j < n - 1; ++j) {
            Set<Integer> t = new HashSet<>();
            for (int i : q) {
                for (int k = i - 1; k <= i + 1; ++k) {
                    if (k >= 0 && k < m && grid[i][j] < grid[k][j + 1]) {
                        t.add(k);
                    }
                }
            }
            if (t.isEmpty()) {
                return j;
            }
            q = t;
        }
        return n - 1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        unordered_set<int> q, t;
        for (int i = 0; i < m; ++i) {
            q.insert(i);
        }
        for (int j = 0; j < n - 1; ++j) {
            t.clear();
            for (int i : q) {
                for (int k = i - 1; k <= i + 1; ++k) {
                    if (k >= 0 && k < m && grid[i][j] < grid[k][j + 1]) {
                        t.insert(k);
                    }
                }
            }
            if (t.empty()) {
                return j;
            }
            q.swap(t);
        }
        return n - 1;
    }
};
```

#### Go

```go
func maxMoves(grid [][]int) (ans int) {
	m, n := len(grid), len(grid[0])
	q := map[int]bool{}
	for i := range grid {
		q[i] = true
	}
	for j := 0; j < n-1; j++ {
		t := map[int]bool{}
		for i := range q {
			for k := i - 1; k <= i+1; k++ {
				if k >= 0 && k < m && grid[i][j] < grid[k][j+1] {
					t[k] = true
				}
			}
		}
		if len(t) == 0 {
			return j
		}
		q = t
	}
	return n - 1
}
```

#### TypeScript

```ts
function maxMoves(grid: number[][]): number {
    const m = grid.length;
    const n = grid[0].length;
    let q = new Set<number>(Array.from({ length: m }, (_, i) => i));
    for (let j = 0; j < n - 1; ++j) {
        const t = new Set<number>();
        for (const i of q) {
            for (let k = i - 1; k <= i + 1; ++k) {
                if (k >= 0 && k < m && grid[i][j] < grid[k][j + 1]) {
                    t.add(k);
                }
            }
        }
        if (t.size === 0) {
            return j;
        }
        q = t;
    }
    return n - 1;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2685. 统计完全连通分量的数量](https://leetcode.cn/problems/count-the-number-of-complete-components){#2685}

{{< tabs "2685" >}}

{{% tab "python" %}}
```python
class Solution:
    def countCompleteComponents(self, n: int, edges: List[List[int]]) -> int:
        def dfs(i: int) -> (int, int):
            vis[i] = True
            x, y = 1, len(g[i])
            for j in g[i]:
                if not vis[j]:
                    a, b = dfs(j)
                    x += a
                    y += b
            return x, y

        g = defaultdict(list)
        for a, b in edges:
            g[a].append(b)
            g[b].append(a)
        vis = [False] * n
        ans = 0
        for i in range(n):
            if not vis[i]:
                a, b = dfs(i)
                ans += a * (a - 1) == b
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private List<Integer>[] g;
    private boolean[] vis;

    public int countCompleteComponents(int n, int[][] edges) {
        g = new List[n];
        vis = new boolean[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (int[] e : edges) {
            int a = e[0], b = e[1];
            g[a].add(b);
            g[b].add(a);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                int[] t = dfs(i);
                if (t[0] * (t[0] - 1) == t[1]) {
                    ++ans;
                }
            }
        }
        return ans;
    }

    private int[] dfs(int i) {
        vis[i] = true;
        int x = 1, y = g[i].size();
        for (int j : g[i]) {
            if (!vis[j]) {
                int[] t = dfs(j);
                x += t[0];
                y += t[1];
            }
        }
        return new int[] {x, y};
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int ans = 0;
        vector<set<int>> m(n + 1, set<int>());
        for (int i = 0; i < n; i++) {
            m[i].insert(i);
        }
        for (auto x : edges) {
            m[x[0]].insert(x[1]);
            m[x[1]].insert(x[0]);
        }
        map<set<int>, int> s;
        for (int i = 0; i < n; i++) {
            s[m[i]]++;
        }
        for (auto& [x, y] : s) {
            if (y == x.size()) {
                ans++;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countCompleteComponents(n int, edges [][]int) (ans int) {
	g := make([][]int, n)
	vis := make([]bool, n)
	for _, e := range edges {
		a, b := e[0], e[1]
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}
	var dfs func(int) (int, int)
	dfs = func(i int) (int, int) {
		vis[i] = true
		x, y := 1, len(g[i])
		for _, j := range g[i] {
			if !vis[j] {
				a, b := dfs(j)
				x += a
				y += b
			}
		}
		return x, y
	}
	for i := range vis {
		if !vis[i] {
			a, b := dfs(i)
			if a*(a-1) == b {
				ans++
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

<p>给你一个整数 <code>n</code> 。现有一个包含 <code>n</code> 个顶点的 <strong>无向</strong> 图，顶点按从 <code>0</code> 到 <code>n - 1</code> 编号。给你一个二维整数数组 <code>edges</code> 其中 <code>edges[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> 表示顶点 <code>a<sub>i</sub></code> 和 <code>b<sub>i</sub></code> 之间存在一条 <strong>无向</strong> 边。</p>

<p>返回图中 <strong>完全连通分量</strong> 的数量。</p>

<p>如果在子图中任意两个顶点之间都存在路径，并且子图中没有任何一个顶点与子图外部的顶点共享边，则称其为 <strong>连通分量</strong> 。</p>

<p>如果连通分量中每对节点之间都存在一条边，则称其为 <strong>完全连通分量</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2600-2699/2685.Count%20the%20Number%20of%20Complete%20Components/images/screenshot-from-2023-04-11-23-31-23.png" style="width: 671px; height: 270px;" /></strong></p>

<pre>
<strong>输入：</strong>n = 6, edges = [[0,1],[0,2],[1,2],[3,4]]
<strong>输出：</strong>3
<strong>解释：</strong>如上图所示，可以看到此图所有分量都是完全连通分量。
</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2600-2699/2685.Count%20the%20Number%20of%20Complete%20Components/images/screenshot-from-2023-04-11-23-32-00.png" style="width: 671px; height: 270px;" /></strong></p>

<pre>
<strong>输入：</strong>n = 6, edges = [[0,1],[0,2],[1,2],[3,4],[3,5]]
<strong>输出：</strong>1
<strong>解释：</strong>包含节点 0、1 和 2 的分量是完全连通分量，因为每对节点之间都存在一条边。
包含节点 3 、4 和 5 的分量不是完全连通分量，因为节点 4 和 5 之间不存在边。
因此，在图中完全连接分量的数量是 1 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 50</code></li>
	<li><code>0 &lt;= edges.length &lt;= n * (n - 1) / 2</code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt;= n - 1</code></li>
	<li><code>a<sub>i</sub> != b<sub>i</sub></code></li>
	<li>不存在重复的边</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS

我们先根据题目给定的边建立一个邻接表 $g$，其中 $g[i]$ 表示顶点 $i$ 的邻接点集合。

然后我们从 $0$ 开始遍历所有顶点，如果当前顶点没有被访问过，我们就从当前顶点开始进行深度优先搜索，统计当前连通分量的顶点数 $x$ 和边数 $y$。如果 $\frac{x(x-1)}{2} = y$，那么当前连通分量就是完全连通分量，我们将答案加一。

最后我们返回答案即可。

时间复杂度 $O(n + m)$，空间复杂度 $O(n + m)$。其中 $n$ 和 $m$ 分别是顶点数和边数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countCompleteComponents(self, n: int, edges: List[List[int]]) -> int:
        def dfs(i: int) -> (int, int):
            vis[i] = True
            x, y = 1, len(g[i])
            for j in g[i]:
                if not vis[j]:
                    a, b = dfs(j)
                    x += a
                    y += b
            return x, y

        g = defaultdict(list)
        for a, b in edges:
            g[a].append(b)
            g[b].append(a)
        vis = [False] * n
        ans = 0
        for i in range(n):
            if not vis[i]:
                a, b = dfs(i)
                ans += a * (a - 1) == b
        return ans
```

#### Java

```java
class Solution {
    private List<Integer>[] g;
    private boolean[] vis;

    public int countCompleteComponents(int n, int[][] edges) {
        g = new List[n];
        vis = new boolean[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (int[] e : edges) {
            int a = e[0], b = e[1];
            g[a].add(b);
            g[b].add(a);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                int[] t = dfs(i);
                if (t[0] * (t[0] - 1) == t[1]) {
                    ++ans;
                }
            }
        }
        return ans;
    }

    private int[] dfs(int i) {
        vis[i] = true;
        int x = 1, y = g[i].size();
        for (int j : g[i]) {
            if (!vis[j]) {
                int[] t = dfs(j);
                x += t[0];
                y += t[1];
            }
        }
        return new int[] {x, y};
    }
}
```

#### C++

```cpp
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        bool vis[n];
        memset(vis, false, sizeof(vis));
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        function<pair<int, int>(int)> dfs = [&](int i) -> pair<int, int> {
            vis[i] = true;
            int x = 1, y = g[i].size();
            for (int j : g[i]) {
                if (!vis[j]) {
                    auto [a, b] = dfs(j);
                    x += a;
                    y += b;
                }
            }
            return make_pair(x, y);
        };
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                auto [a, b] = dfs(i);
                if (a * (a - 1) == b) {
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
func countCompleteComponents(n int, edges [][]int) (ans int) {
	g := make([][]int, n)
	vis := make([]bool, n)
	for _, e := range edges {
		a, b := e[0], e[1]
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}
	var dfs func(int) (int, int)
	dfs = func(i int) (int, int) {
		vis[i] = true
		x, y := 1, len(g[i])
		for _, j := range g[i] {
			if !vis[j] {
				a, b := dfs(j)
				x += a
				y += b
			}
		}
		return x, y
	}
	for i := range vis {
		if !vis[i] {
			a, b := dfs(i)
			if a*(a-1) == b {
				ans++
			}
		}
	}
	return
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：取巧做法

要解决的问题：

1. 如何保存每一个节点与其它点联通状态
2. 如何判断多个点是否是一个联通图

对于第一点：实际上就是保存了当前到每个点的联通点集合（包括自己），方便后续判等。
第二点：有了第一点之后，如果是连通图中的点就有：

1. 此点包含此联通图中所有的点（包括自己）
2. 并且只包含此联通图中的点

拿示例一举例：

-   5 包含的联通点有且只有自己，所以是连通图
-   0 包含 0、1、2，同理 1、2 点也是
-   3 和 4 也是包含自己和彼此
-   基于以上就有以下代码实现：

<!-- tabs:start -->

#### C++

```cpp
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int ans = 0;
        vector<set<int>> m(n + 1, set<int>());
        for (int i = 0; i < n; i++) {
            m[i].insert(i);
        }
        for (auto x : edges) {
            m[x[0]].insert(x[1]);
            m[x[1]].insert(x[0]);
        }
        map<set<int>, int> s;
        for (int i = 0; i < n; i++) {
            s[m[i]]++;
        }
        for (auto& [x, y] : s) {
            if (y == x.size()) {
                ans++;
            }
        }
        return ans;
    }
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2686. 即时食物配送 III 🔒](https://leetcode.cn/problems/immediate-food-delivery-iii){#2686}

{{< tabs "2686" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT  order_date
       ,ROUND(100*SUM(IF(customer_pref_delivery_date = order_date,1,0))/COUNT(*),2) AS immediate_percentage
FROM Delivery
GROUP BY  order_date
ORDER BY order_date
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p><code>Delivery</code>&nbsp;表：</p>

<pre>
+-----------------------------+---------+
| 字段名                       | 类型   |
+-----------------------------+---------+
| delivery_id                 | int     |
| customer_id                 | int     |
| order_date                  | date    |
| customer_pref_delivery_date | date    |
+-----------------------------+---------+
delivery_id 是该表的具有唯一值的列。
每一行包含有关向顾客交付食物的信息，顾客在某个日期下订单，并指定了一个首选交付日期（在订单日期当天或之后）。
</pre>

<p>&nbsp;</p>

<p>如果顾客的首选交付日期与订单日期相同，则该订单称为 <strong>立即交付</strong>&nbsp;，否则称为 <strong>计划交付</strong>&nbsp;。</p>

<p>编写解决方案，找出每个唯一的 <code>order_date</code> 中立即交付订单的百分比。<strong>结果保留两位小数</strong>。</p>

<p>返回查询结果并按 <code>order_date</code> <strong>升序</strong> 排序。</p>

<p>查询结果的格式如下所示。</p>

<p>&nbsp;</p>

<p><b>示例 1：</b></p>

<pre>
<b>输入：</b>
Delivery 表:
+-------------+-------------+------------+-----------------------------+
| delivery_id | customer_id | order_date | customer_pref_delivery_date |
+-------------+-------------+------------+-----------------------------+
| 1           | 1           | 2019-08-01 | 2019-08-02                  |
| 2           | 2           | 2019-08-01 | 2019-08-01                  |
| 3           | 1           | 2019-08-01 | 2019-08-01                  |
| 4           | 3           | 2019-08-02 | 2019-08-13                  |
| 5           | 3           | 2019-08-02 | 2019-08-02                  |
| 6           | 2           | 2019-08-02 | 2019-08-02                  |
| 7           | 4           | 2019-08-03 | 2019-08-03                  |
| 8           | 1           | 2019-08-03 | 2019-08-03                  |
| 9           | 5           | 2019-08-04 | 2019-08-08                  |
| 10          | 2           | 2019-08-04 | 2019-08-18                  |
+-------------+-------------+------------+-----------------------------+
<b>输出：</b>
+------------+----------------------+
| order_date | immediate_percentage |
+------------+----------------------+
| 2019-08-01 | 66.67                |
| 2019-08-02 | 66.67                |
| 2019-08-03 | 100.00               |
| 2019-08-04 | 0.00                 |
+------------+----------------------+
<b>解释：</b>
– 2019年8月1日共有3个订单，其中2个是即时订单，1个是预定订单。因此，该日期的即时订单百分比为66.67。
– 2019年8月2日共有3个订单，其中2个是即时订单，1个是预定订单。因此，该日期的即时订单百分比为66.67。
– 2019年8月3日共有2个订单，均为即时订单。因此，该日期的即时订单百分比为100.00。
– 2019年8月4日共有2个订单，均为预定订单。因此，该日期的即时订单百分比为0.00。
order_dste 按升序排序。</pre>

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
SELECT  order_date
       ,ROUND(100*SUM(IF(customer_pref_delivery_date = order_date,1,0))/COUNT(*),2) AS immediate_percentage
FROM Delivery
GROUP BY  order_date
ORDER BY order_date
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2687. 自行车的最后使用时间 🔒](https://leetcode.cn/problems/bikes-last-time-used){#2687}

{{< tabs "2687" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT
    bike_number,
    MAX(end_time) AS end_time
FROM Bikes
GROUP BY bike_number
ORDER BY end_time DESC;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code>Bikes</code>&nbsp;</p>

<pre>
+-------------+----------+ 
| 列名        | 类型     | 
+-------------+----------+ 
| ride_id     | int      | 
| bike_number | int      | 
| start_time  | datetime |
| end_time    | datetime |
+-------------+----------+
ride_id 是该表的主键。
每行包含一个骑行信息，包括 ride_id、自行车编号、骑行的起始和结束时间。
输入保证 start_time 和 end_time 是有效的日期值。
</pre>

<p>编写一个解决方案，找出每辆自行车 <strong>最近一次被使用</strong> 的时间。</p>

<p>返回结果表按 <strong>最近被使用</strong>&nbsp;的自行车进行排序。</p>

<p>返回结果的格式如下所示：</p>

<p>&nbsp;</p>

<p><b>示例 1：</b></p>

<pre>
<strong>输入：
</strong><code>Bikes</code> 表:
+---------+-------------+---------------------+---------------------+ 
| ride_id | bike_number | start_time          | end_time            |  
+---------+-------------+---------------------+---------------------+
| 1       | W00576      | 2012-03-25 11:30:00 | 2012-03-25 12:40:00 |
| 2       | W00300      | 2012-03-25 10:30:00 | 2012-03-25 10:50:00 |
| 3       | W00455      | 2012-03-26 14:30:00 | 2012-03-26 17:40:00 |
| 4       | W00455      | 2012-03-25 12:30:00 | 2012-03-25 13:40:00 |
| 5       | W00576      | 2012-03-25 08:10:00 | 2012-03-25 09:10:00 |
| 6       | W00576      | 2012-03-28 02:30:00 | 2012-03-28 02:50:00 |
+---------+-------------+---------------------+---------------------+ 
<b>输出：</b>
+-------------+---------------------+ 
| bike_number | end_time            |  
+-------------+---------------------+
| W00576      | 2012-03-28 02:50:00 |
| W00455      | 2012-03-26 17:40:00 |
| W00300      | 2012-03-25 10:50:00 |
+-------------+---------------------+ 
<b>解释：</b>
编号为 W00576 的自行车有三次骑行记录，其中最近的骑行记录是 ride_id 为 6，于 2012-03-28 02:50:00结束。
编号为 W00300 的自行车只有一次骑行记录，所以我们直接在输出中包含结束时间。
编号为 W00455 的自行车有两次骑行记录，其中最近的骑行记录是 ride_id 为 3，于 2012-03-26 17:40:00结束。
按照最近使用的自行车顺序返回输出。</pre>

<p>&nbsp;</p>

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
    bike_number,
    MAX(end_time) AS end_time
FROM Bikes
GROUP BY bike_number
ORDER BY end_time DESC;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2688. 查找活跃用户 🔒](https://leetcode.cn/problems/find-active-users){#2688}

{{< tabs "2688" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement
SELECT DISTINCT
    user_id
FROM Users
WHERE
    user_id IN (
        SELECT
            user_id
        FROM
            (
                SELECT
                    user_id,
                    created_at,
                    LAG(created_at, 1) OVER (
                        PARTITION BY user_id
                        ORDER BY created_at
                    ) AS prev_created_at
                FROM Users
            ) AS t
        WHERE DATEDIFF(created_at, prev_created_at) <= 7
    );
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p><font face="monospace"><code>Users</code> 表：</font></p>

<pre>
+-------------+----------+ 
| 字段名       | 类型      | 
+-------------+----------+ 
| user_id     | int      | 
| item        | varchar  |
| created_at  | datetime |
| amount      | int      |
+-------------+----------+
在这个表可能包含重复的记录。
每一行包括 user_id、购买的商品、购买日期和购买金额。</pre>

<p>编写一个解决方案，找出活跃用户。活跃用户是指在其任何一次购买之后的 <strong>七天内</strong>&nbsp;进行了第二次购买的用户。</p>

<p>例如，如果结束日期是 2023年5月31日，那么在 2023年5月31日 和 2023年6月7日之间（包括这两天）的任何日期都被视为"在7天内"。</p>

<p>返回 <strong>任意顺序</strong> 的 <code>user_id</code> 列表，表示活跃用户列表。</p>

<p>结果的格式如下示例：</p>

<p>&nbsp;</p>

<p><b>示例 1：</b></p>

<pre>
<strong>输入：
</strong>Users 表:
+---------+-------------------+------------+--------+ 
| user_id | item              | created_at | amount |  
+---------+-------------------+------------+--------+
| 5       | Smart Crock Pot   | 2021-09-18 | 698882 |
| 6       | Smart Lock        | 2021-09-14 | 11487  |
| 6       | Smart Thermostat  | 2021-09-10 | 674762 |
| 8       | Smart Light Strip | 2021-09-29 | 630773 |
| 4       | Smart Cat Feeder  | 2021-09-02 | 693545 |
| 4       | Smart Bed         | 2021-09-13 | 170249 |
+---------+-------------------+------------+--------+ 
<b>输出：</b>
+---------+
| user_id | 
+---------+
| 6       | 
+---------+
<b>解释：</b>
– user_id 为 5 的用户只有一笔交易，因此他不是活跃用户。
– user_id 为 6 的用户有两笔交易，第一笔交易是在2021年9月10日，第二笔交易是在2021年9月14日。第一笔和第二笔交易之间的时间间隔小于等于7天。因此，他是一个活跃用户。
– user_id 为 8 的用户只有一笔交易，因此他不是活跃用户。
– user_id 为 4 的用户有两笔交易，第一笔交易是在2021年9月2日，第二笔交易是在2021年9月13日。第一笔和第二笔交易之间的时间间隔大于7天。因此，他不是活跃用户。</pre>

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
# Write your MySQL query statement
SELECT DISTINCT
    user_id
FROM Users
WHERE
    user_id IN (
        SELECT
            user_id
        FROM
            (
                SELECT
                    user_id,
                    created_at,
                    LAG(created_at, 1) OVER (
                        PARTITION BY user_id
                        ORDER BY created_at
                    ) AS prev_created_at
                FROM Users
            ) AS t
        WHERE DATEDIFF(created_at, prev_created_at) <= 7
    );
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2689. 从 Rope 树中提取第 K 个字符 🔒](https://leetcode.cn/problems/extract-kth-character-from-the-rope-tree){#2689}

{{< tabs "2689" >}}

{{% tab "python" %}}
```python
# Definition for a rope tree node.
# class RopeTreeNode(object):
#     def __init__(self, len=0, val="", left=None, right=None):
#         self.len = len
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getKthCharacter(self, root: Optional[object], k: int) -> str:
        def dfs(root):
            if root is None:
                return ""
            if root.len == 0:
                return root.val
            return dfs(root.left) + dfs(root.right)

        return dfs(root)[k - 1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
/**
 * Definition for a rope tree node.
 * class RopeTreeNode {
 *     int len;
 *     String val;
 *     RopeTreeNode left;
 *     RopeTreeNode right;
 *     RopeTreeNode() {}
 *     RopeTreeNode(String val) {
 *         this.len = 0;
 *         this.val = val;
 *     }
 *     RopeTreeNode(int len) {
 *         this.len = len;
 *         this.val = "";
 *     }
 *     RopeTreeNode(int len, TreeNode left, TreeNode right) {
 *         this.len = len;
 *         this.val = "";
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public char getKthCharacter(RopeTreeNode root, int k) {
        return dfs(root).charAt(k - 1);
    }

    private String dfs(RopeTreeNode root) {
        if (root == null) {
            return "";
        }
        if (root.val.length() > 0) {
            return root.val;
        }
        String left = dfs(root.left);
        String right = dfs(root.right);
        return left + right;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
/**
 * Definition for a rope tree node.
 * struct RopeTreeNode {
 *     int len;
 *     string val;
 *     RopeTreeNode *left;
 *     RopeTreeNode *right;
 *     RopeTreeNode() : len(0), val(""), left(nullptr), right(nullptr) {}
 *     RopeTreeNode(string s) : len(0), val(std::move(s)), left(nullptr), right(nullptr) {}
 *     RopeTreeNode(int x) : len(x), val(""), left(nullptr), right(nullptr) {}
 *     RopeTreeNode(int x, RopeTreeNode *left, RopeTreeNode *right) : len(x), val(""), left(left), right(right) {}
 * };
 */
class Solution {
public:
    char getKthCharacter(RopeTreeNode* root, int k) {
        function<string(RopeTreeNode * root)> dfs = [&](RopeTreeNode* root) -> string {
            if (root == nullptr) {
                return "";
            }
            if (root->len == 0) {
                return root->val;
            }
            string left = dfs(root->left);
            string right = dfs(root->right);
            return left + right;
        };
        return dfs(root)[k - 1];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
/**
 * Definition for a rope tree node.
 * type RopeTreeNode struct {
 * 	   len   int
 * 	   val   string
 * 	   left  *RopeTreeNode
 * 	   right *RopeTreeNode
 * }
 */
func getKthCharacter(root *RopeTreeNode, k int) byte {
	var dfs func(root *RopeTreeNode) string
	dfs = func(root *RopeTreeNode) string {
		if root == nil {
			return ""
		}
		if root.len == 0 {
			return root.val
		}
		left, right := dfs(root.left), dfs(root.right)
		return left + right
	}
	return dfs(root)[k-1]
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个二叉树的根节点 <code>root</code> 和整数 <code>k</code>。除了左右孩子之外，该树的每个节点还有另外两个属性：一个仅包含小写英文字母（可能为空）的 <strong>字符串</strong> <code>node.val</code> 和一个非负整数 <code>node.len</code>。这棵树中有两种类型的节点：</p>

<ul>
	<li><strong>叶子节点</strong>：这些节点没有子节点，<code>node.len = 0</code>，<code>node.val</code> 是一个 <strong>非空</strong> 字符串。</li>
	<li><strong>内部节点</strong>：这些节点至少有一个子节点（最多两个子节点），<code>node.len &gt; 0</code>，<code>node.val</code> 是一个 <strong>空</strong> 字符串。</li>
</ul>

<p>上述描述的树被称为 Rope 二叉树。现在我们用以下递归方式定义 <code>S[node]</code>：</p>

<ul>
	<li>如果 <code>node</code> 是一个叶子节点，则 <code>S[node] = node.val</code>，</li>
	<li>否则，如果 <code>node</code> 是一个内部节点，则 <code>S[node] = concat(S[node.left], S[node.right])</code>，且 <code>S[node].length = node.len</code>。</li>
</ul>

<p>返回字符串 <code>S[root]</code> 的第 <code>k</code> 个字符。</p>

<p><strong>注意</strong>：如果 <code>s</code> 和 <code>p</code> 是两个字符串，则 <code>concat(s, p)</code> 是将字符串 <code>p</code> 连接到 <code>s</code> 后面的字符串。例如，<code>concat("ab", "zz") = "abzz"</code>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>root = [10,4,"abcpoe","g","rta"], k = 6
<b>输出：</b>"b"
<b>解释：</b>在下面的图片中，我们在内部节点上放置一个表示 <code>node.len</code> 的整数，在叶子节点上放置一个表示 <code>node.val</code> 的字符串。 你可以看到，<code>S[root] = concat(concat("g", "rta"), "abcpoe") = "grtaabcpoe"</code>。因此，<code>S[root][5]</code>，表示它的第6个字符，等于 "b"。
</pre>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2600-2699/2689.Extract%20Kth%20Character%20From%20The%20Rope%20Tree/images/example1.png" style="width: 300px; height: 213px; margin-left: 280px; margin-right: 280px;" /></p>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>root = [12,6,6,"abc","efg","hij","klm"], k = 3
<b>输出：</b>"c"
<b>解释：</b>在下面的图片中，我们在内部节点上放置一个表示 <code>node.len</code> 的整数，在叶子节点上放置一个表示 <code>node.val</code> 的字符串。 你可以看到，<code>S[root] = concat(concat("abc", "efg"), concat("hij", "klm")) = "abcefghijklm"</code>。因此，<code>S[root][2]</code>，表示它的第3个字符，等于 "c"。
</pre>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2600-2699/2689.Extract%20Kth%20Character%20From%20The%20Rope%20Tree/images/example2.png" style="width: 400px; height: 232px; margin-left: 255px; margin-right: 255px;" /></p>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>root = ["ropetree"], k = 8
<b>输出：</b>"e"
<b>解释：</b>在下面的图片中，我们在内部节点上放置一个表示 <code>node.len</code> 的整数，在叶子节点上放置一个表示 <code>node.val</code> 的字符串。 你可以看到，<code>S[root] = "ropetree"</code>。因此，<code>S[root][7]</code>，表示它的第8个字符，等于 "e"。
</pre>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2600-2699/2689.Extract%20Kth%20Character%20From%20The%20Rope%20Tree/images/example3.png" style="width: 80px; height: 78px; margin-left: 400px; margin-right: 400px;" /></p>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>这棵树的节点数量在区间&nbsp;<code>[1, 10<sup>3</sup>]</code></li>
	<li><code>node.val</code> 仅包含小写英文字母</li>
	<li><code>0 &lt;= node.val.length &lt;= 50</code></li>
	<li><code>0 &lt;= node.len &lt;= 10<sup>4</sup></code></li>
	<li>对于叶子节点， <code>node.len = 0</code> 且&nbsp;<code>node.val</code> 是非空的</li>
	<li>对于内部节点， <code>node.len &gt; 0 </code>&nbsp;且&nbsp;<code>node.val</code> 为空</li>
	<li><code>1 &lt;= k &lt;= S[root].length</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS

我们可以使用深度优先搜索的方法，定义一个函数 $dfs(root)$，表示从根节点开始搜索，返回以 $root$ 为根节点的子树的字符串。那么答案就是 $dfs(root)[k-1]$。

函数 $dfs(root)$ 的执行逻辑如下：

-   如果 $root$ 为空，返回空字符串；
-   如果 $root$ 是叶子节点，返回 $root.val$；
-   否则，返回 $dfs(root.left) + dfs(root.right)$。

时间复杂度 $O(n^2)$，空间复杂度 $O(n)$。其中 $n$ 是树中节点的个数。

<!-- tabs:start -->

#### Python3

```python
# Definition for a rope tree node.
# class RopeTreeNode(object):
#     def __init__(self, len=0, val="", left=None, right=None):
#         self.len = len
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getKthCharacter(self, root: Optional[object], k: int) -> str:
        def dfs(root):
            if root is None:
                return ""
            if root.len == 0:
                return root.val
            return dfs(root.left) + dfs(root.right)

        return dfs(root)[k - 1]
```

#### Java

```java
/**
 * Definition for a rope tree node.
 * class RopeTreeNode {
 *     int len;
 *     String val;
 *     RopeTreeNode left;
 *     RopeTreeNode right;
 *     RopeTreeNode() {}
 *     RopeTreeNode(String val) {
 *         this.len = 0;
 *         this.val = val;
 *     }
 *     RopeTreeNode(int len) {
 *         this.len = len;
 *         this.val = "";
 *     }
 *     RopeTreeNode(int len, TreeNode left, TreeNode right) {
 *         this.len = len;
 *         this.val = "";
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public char getKthCharacter(RopeTreeNode root, int k) {
        return dfs(root).charAt(k - 1);
    }

    private String dfs(RopeTreeNode root) {
        if (root == null) {
            return "";
        }
        if (root.val.length() > 0) {
            return root.val;
        }
        String left = dfs(root.left);
        String right = dfs(root.right);
        return left + right;
    }
}
```

#### C++

```cpp
/**
 * Definition for a rope tree node.
 * struct RopeTreeNode {
 *     int len;
 *     string val;
 *     RopeTreeNode *left;
 *     RopeTreeNode *right;
 *     RopeTreeNode() : len(0), val(""), left(nullptr), right(nullptr) {}
 *     RopeTreeNode(string s) : len(0), val(std::move(s)), left(nullptr), right(nullptr) {}
 *     RopeTreeNode(int x) : len(x), val(""), left(nullptr), right(nullptr) {}
 *     RopeTreeNode(int x, RopeTreeNode *left, RopeTreeNode *right) : len(x), val(""), left(left), right(right) {}
 * };
 */
class Solution {
public:
    char getKthCharacter(RopeTreeNode* root, int k) {
        function<string(RopeTreeNode * root)> dfs = [&](RopeTreeNode* root) -> string {
            if (root == nullptr) {
                return "";
            }
            if (root->len == 0) {
                return root->val;
            }
            string left = dfs(root->left);
            string right = dfs(root->right);
            return left + right;
        };
        return dfs(root)[k - 1];
    }
};
```

#### Go

```go
/**
 * Definition for a rope tree node.
 * type RopeTreeNode struct {
 * 	   len   int
 * 	   val   string
 * 	   left  *RopeTreeNode
 * 	   right *RopeTreeNode
 * }
 */
func getKthCharacter(root *RopeTreeNode, k int) byte {
	var dfs func(root *RopeTreeNode) string
	dfs = func(root *RopeTreeNode) string {
		if root == nil {
			return ""
		}
		if root.len == 0 {
			return root.val
		}
		left, right := dfs(root.left), dfs(root.right)
		return left + right
	}
	return dfs(root)[k-1]
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
