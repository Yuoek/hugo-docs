---
title: "3180_执行操作可获得的最大总奖励 I"
date: 2025-10-08T18:40:09+08:00
weight: 9
tags: [二分查找, 位运算, 动态规划, 双指针, 哈希表, 排序, 数据库, 数组, 树状数组, 线段树, 计数, 计数排序, 贪心]
---

{{< markmap >}}
### [3180_执行操作可获得的最大总奖励 I](#3180)
#### [数组](#3180)
#### [动态规划](#3180)
### [3181_执行操作可获得的最大总奖励 II](#3181)
#### [位运算](#3181)
#### [数组](#3181)
#### [动态规划](#3181)
### [3182_查找得分最高的学生 🔒](#3182)
#### [数据库](#3182)
### [3183_达到总和的方法数量 🔒](#3183)
#### [数组](#3183)
#### [动态规划](#3183)
### [3184_构成整天的下标对数目 I](#3184)
#### [数组](#3184)
#### [哈希表](#3184)
#### [计数](#3184)
### [3185_构成整天的下标对数目 II](#3185)
#### [数组](#3185)
#### [哈希表](#3185)
#### [计数](#3185)
### [3186_施咒的最大总伤害](#3186)
#### [数组](#3186)
#### [哈希表](#3186)
#### [双指针](#3186)
#### [二分查找](#3186)
#### [动态规划](#3186)
#### [计数](#3186)
#### [排序](#3186)
### [3187_数组中的峰值](#3187)
#### [树状数组](#3187)
#### [线段树](#3187)
#### [数组](#3187)
### [3188_查找得分最高的学生 II 🔒](#3188)
#### [数据库](#3188)
### [3189_得到一个和平棋盘的最少步骤 🔒](#3189)
#### [贪心](#3189)
#### [数组](#3189)
#### [计数排序](#3189)
#### [排序](#3189)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 3180_执行操作可获得的最大总奖励 I
___
#### 数组
___
#### 动态规划
---
### 3181_执行操作可获得的最大总奖励 II
___
#### 位运算
___
#### 数组
___
#### 动态规划
---
### 3182_查找得分最高的学生 🔒
___
#### 数据库
---
### 3183_达到总和的方法数量 🔒
___
#### 数组
___
#### 动态规划
---
### 3184_构成整天的下标对数目 I
___
#### 数组
___
#### 哈希表
___
#### 计数
---
### 3185_构成整天的下标对数目 II
___
#### 数组
___
#### 哈希表
___
#### 计数
---
### 3186_施咒的最大总伤害
___
#### 数组
___
#### 哈希表
___
#### 双指针
___
#### 二分查找
___
#### 动态规划
___
#### 计数
___
#### 排序
---
### 3187_数组中的峰值
___
#### 树状数组
___
#### 线段树
___
#### 数组
---
### 3188_查找得分最高的学生 II 🔒
___
#### 数据库
---
### 3189_得到一个和平棋盘的最少步骤 🔒
___
#### 贪心
___
#### 数组
___
#### 计数排序
___
#### 排序
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 位运算 | 动态规划 |
| 双指针 | 哈希表 | 排序 |
| 数据库 | 数组 | 树状数组 |
| 线段树 | 计数 | 计数排序 |
| 贪心 |  |  |

# [3180. 执行操作可获得的最大总奖励 I](https://leetcode.cn/problems/maximum-total-reward-using-operations-i){#3180}

{{< tabs "3180" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxTotalReward(self, rewardValues: List[int]) -> int:
        nums = sorted(set(rewardValues))
        f = 1
        for v in nums:
            f |= (f & ((1 << v) - 1)) << v
        return f.bit_length() - 1
```
{{% /tab %}}
{{% tab "java" %}}
```java
import java.math.BigInteger;

class Solution {
    public int maxTotalReward(int[] rewardValues) {
        int[] nums = Arrays.stream(rewardValues).distinct().sorted().toArray();
        BigInteger f = BigInteger.ONE;
        for (int v : nums) {
            BigInteger mask = BigInteger.ONE.shiftLeft(v).subtract(BigInteger.ONE);
            BigInteger shifted = f.and(mask).shiftLeft(v);
            f = f.or(shifted);
        }
        return f.bitLength() - 1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        sort(rewardValues.begin(), rewardValues.end());
        rewardValues.erase(unique(rewardValues.begin(), rewardValues.end()), rewardValues.end());
        bitset<100000> f{1};
        for (int v : rewardValues) {
            int shift = f.size() - v;
            f |= f << shift >> (shift - v);
        }
        for (int i = rewardValues.back() * 2 - 1;; i--) {
            if (f.test(i)) {
                return i;
            }
        }
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxTotalReward(rewardValues []int) int {
	slices.Sort(rewardValues)
	rewardValues = slices.Compact(rewardValues)
	one := big.NewInt(1)
	f := big.NewInt(1)
	p := new(big.Int)
	for _, v := range rewardValues {
		mask := p.Sub(p.Lsh(one, uint(v)), one)
		f.Or(f, p.Lsh(p.And(f, mask), uint(v)))
	}
	return f.BitLen() - 1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxTotalReward(rewardValues: number[]): number {
    rewardValues.sort((a, b) => a - b);
    rewardValues = [...new Set(rewardValues)];
    let f = 1n;
    for (const x of rewardValues) {
        const mask = (1n << BigInt(x)) - 1n;
        f = f | ((f & mask) << BigInt(x));
    }
    return f.toString(2).length - 1;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>rewardValues</code>，长度为 <code>n</code>，代表奖励的值。</p>

<p>最初，你的总奖励 <code>x</code> 为 0，所有下标都是<strong> 未标记 </strong>的。你可以执行以下操作 <strong>任意次 </strong>：</p>

<ul>
	<li>从区间 <code>[0, n - 1]</code> 中选择一个 <strong>未标记 </strong>的下标 <code>i</code>。</li>
	<li>如果 <code>rewardValues[i]</code> <strong>大于</strong> 你当前的总奖励 <code>x</code>，则将 <code>rewardValues[i]</code> 加到 <code>x</code> 上（即 <code>x = x + rewardValues[i]</code>），并<strong> 标记</strong> 下标 <code>i</code>。</li>
</ul>

<p>以整数形式返回执行最优操作能够获得的<strong> 最大</strong><em> </em>总奖励。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">rewardValues = [1,1,3,3]</span></p>

<p><strong>输出：</strong><span class="example-io">4</span></p>

<p><strong>解释：</strong></p>

<p>依次标记下标 0 和 2，总奖励为 4，这是可获得的最大值。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">rewardValues = [1,6,4,3,2]</span></p>

<p><strong>输出：</strong><span class="example-io">11</span></p>

<p><strong>解释：</strong></p>

<p>依次标记下标 0、2 和 1。总奖励为 11，这是可获得的最大值。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= rewardValues.length &lt;= 2000</code></li>
	<li><code>1 &lt;= rewardValues[i] &lt;= 2000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 记忆化搜索 + 二分查找

我们可以对奖励值数组 `rewardValues` 进行排序，然后使用记忆化搜索的方法求解最大总奖励。

我们定义一个函数 $\textit{dfs}(x)$，表示当前总奖励为 $x$ 时，能够获得的最大总奖励。那么答案为 $\textit{dfs}(0)$。

函数 $\textit{dfs}(x)$ 的执行过程如下：

1. 二分查找数组 `rewardValues` 中第一个大于 $x$ 的元素的下标 $i$；
2. 遍历数组 `rewardValues` 中从下标 $i$ 开始的元素，对于每个元素 $v$，计算 $v + \textit{dfs}(x + v)$ 的最大值。
3. 将结果返回。

为了避免重复计算，我们使用记忆化数组 `f` 记录已经计算过的结果。

时间复杂度 $O(n \times (\log n + M))$，空间复杂度 $O(M)$。其中 $n$ 是数组 `rewardValues` 的长度，而 $M$ 是数组 `rewardValues` 中的最大值的两倍。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxTotalReward(self, rewardValues: List[int]) -> int:
        @cache
        def dfs(x: int) -> int:
            i = bisect_right(rewardValues, x)
            ans = 0
            for v in rewardValues[i:]:
                ans = max(ans, v + dfs(x + v))
            return ans

        rewardValues.sort()
        return dfs(0)
```

#### Java

```java
class Solution {
    private int[] nums;
    private Integer[] f;

    public int maxTotalReward(int[] rewardValues) {
        nums = rewardValues;
        Arrays.sort(nums);
        int n = nums.length;
        f = new Integer[nums[n - 1] << 1];
        return dfs(0);
    }

    private int dfs(int x) {
        if (f[x] != null) {
            return f[x];
        }
        int i = Arrays.binarySearch(nums, x + 1);
        i = i < 0 ? -i - 1 : i;
        int ans = 0;
        for (; i < nums.length; ++i) {
            ans = Math.max(ans, nums[i] + dfs(x + nums[i]));
        }
        return f[x] = ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        sort(rewardValues.begin(), rewardValues.end());
        int n = rewardValues.size();
        int f[rewardValues.back() << 1];
        memset(f, -1, sizeof(f));
        function<int(int)> dfs = [&](int x) {
            if (f[x] != -1) {
                return f[x];
            }
            auto it = upper_bound(rewardValues.begin(), rewardValues.end(), x);
            int ans = 0;
            for (; it != rewardValues.end(); ++it) {
                ans = max(ans, rewardValues[it - rewardValues.begin()] + dfs(x + *it));
            }
            return f[x] = ans;
        };
        return dfs(0);
    }
};
```

#### Go

```go
func maxTotalReward(rewardValues []int) int {
	sort.Ints(rewardValues)
	n := len(rewardValues)
	f := make([]int, rewardValues[n-1]<<1)
	for i := range f {
		f[i] = -1
	}
	var dfs func(int) int
	dfs = func(x int) int {
		if f[x] != -1 {
			return f[x]
		}
		i := sort.SearchInts(rewardValues, x+1)
		f[x] = 0
		for _, v := range rewardValues[i:] {
			f[x] = max(f[x], v+dfs(x+v))
		}
		return f[x]
	}
	return dfs(0)
}
```

#### TypeScript

```ts
function maxTotalReward(rewardValues: number[]): number {
    rewardValues.sort((a, b) => a - b);
    const search = (x: number): number => {
        let [l, r] = [0, rewardValues.length];
        while (l < r) {
            const mid = (l + r) >> 1;
            if (rewardValues[mid] > x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    };
    const f: number[] = Array(rewardValues.at(-1)! << 1).fill(-1);
    const dfs = (x: number): number => {
        if (f[x] !== -1) {
            return f[x];
        }
        let ans = 0;
        for (let i = search(x); i < rewardValues.length; ++i) {
            ans = Math.max(ans, rewardValues[i] + dfs(x + rewardValues[i]));
        }
        return (f[x] = ans);
    };
    return dfs(0);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：动态规划

我们定义 $f[i][j]$ 表示用前 $i$ 个奖励值，能否得到总奖励 $j$。初始时 $f[0][0] = \textit{True}$，其余值均为 $\textit{False}$。

我们考虑第 $i$ 个奖励值 $v$，如果我们不选择它，那么 $f[i][j] = f[i - 1][j]$；如果我们选择它，那么 $f[i][j] = f[i - 1][j - v]$，其中 $0 \leq j - v \lt v$。即状态转移方程为：

$$
f[i][j] = f[i - 1][j] \vee f[i - 1][j - v]
$$

最终答案为 $\max\{j \mid f[n][j] = \textit{True}\}$。

由于 $f[i][j]$ 只与 $f[i - 1][j]$ 和 $f[i - 1][j - v]$ 有关，我们可以优化掉第一维，只使用一个一维数组进行状态转移。

时间复杂度 $O(n \times M)$，空间复杂度 $O(M)$。其中 $n$ 是数组 `rewardValues` 的长度，而 $M$ 是数组 `rewardValues` 中的最大值的两倍。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxTotalReward(self, rewardValues: List[int]) -> int:
        nums = sorted(set(rewardValues))
        m = nums[-1] << 1
        f = [False] * m
        f[0] = True
        for v in nums:
            for j in range(m):
                if 0 <= j - v < v:
                    f[j] |= f[j - v]
        ans = m - 1
        while not f[ans]:
            ans -= 1
        return ans
```

#### Java

```java
class Solution {
    public int maxTotalReward(int[] rewardValues) {
        int[] nums = Arrays.stream(rewardValues).distinct().sorted().toArray();
        int n = nums.length;
        int m = nums[n - 1] << 1;
        boolean[] f = new boolean[m];
        f[0] = true;
        for (int v : nums) {
            for (int j = 0; j < m; ++j) {
                if (0 <= j - v && j - v < v) {
                    f[j] |= f[j - v];
                }
            }
        }
        int ans = m - 1;
        while (!f[ans]) {
            --ans;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        sort(rewardValues.begin(), rewardValues.end());
        rewardValues.erase(unique(rewardValues.begin(), rewardValues.end()), rewardValues.end());
        int n = rewardValues.size();
        int m = rewardValues.back() << 1;
        bool f[m];
        memset(f, false, sizeof(f));
        f[0] = true;
        for (int v : rewardValues) {
            for (int j = 1; j < m; ++j) {
                if (0 <= j - v && j - v < v) {
                    f[j] = f[j] || f[j - v];
                }
            }
        }
        int ans = m - 1;
        while (!f[ans]) {
            --ans;
        }
        return ans;
    }
};
```

#### Go

```go
func maxTotalReward(rewardValues []int) int {
	slices.Sort(rewardValues)
	nums := slices.Compact(rewardValues)
	n := len(nums)
	m := nums[n-1] << 1
	f := make([]bool, m)
	f[0] = true
	for _, v := range nums {
		for j := 1; j < m; j++ {
			if 0 <= j-v && j-v < v {
				f[j] = f[j] || f[j-v]
			}
		}
	}
	ans := m - 1
	for !f[ans] {
		ans--
	}
	return ans
}
```

#### TypeScript

```ts
function maxTotalReward(rewardValues: number[]): number {
    const nums = Array.from(new Set(rewardValues)).sort((a, b) => a - b);
    const n = nums.length;
    const m = nums[n - 1] << 1;
    const f: boolean[] = Array(m).fill(false);
    f[0] = true;
    for (const v of nums) {
        for (let j = 1; j < m; ++j) {
            if (0 <= j - v && j - v < v) {
                f[j] = f[j] || f[j - v];
            }
        }
    }
    let ans = m - 1;
    while (!f[ans]) {
        --ans;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法三：动态规划 + 位运算

我们可以对方法二进行优化，定义一个二进制数 $f$ 保存当前的状态，其中 $f$ 的第 $i$ 位为 $1$ 表示当前总奖励为 $i$ 是可达的。

观察方法二的状态转移方程 $f[j] = f[j] \vee f[j - v]$，这相当于取 $f$ 的低 $v$ 位，再左移 $v$ 位，然后与原来的 $f$ 进行或运算。

那么答案为 $f$ 的最高位的位置。

时间复杂度 $O(n \times M / w)$，空间复杂度 $O(n + M / w)$。其中 $n$ 是数组 `rewardValues` 的长度，而 $M$ 是数组 `rewardValues` 中的最大值的两倍。整数 $w = 32$ 或 $64$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxTotalReward(self, rewardValues: List[int]) -> int:
        nums = sorted(set(rewardValues))
        f = 1
        for v in nums:
            f |= (f & ((1 << v) - 1)) << v
        return f.bit_length() - 1
```

#### Java

```java
import java.math.BigInteger;

class Solution {
    public int maxTotalReward(int[] rewardValues) {
        int[] nums = Arrays.stream(rewardValues).distinct().sorted().toArray();
        BigInteger f = BigInteger.ONE;
        for (int v : nums) {
            BigInteger mask = BigInteger.ONE.shiftLeft(v).subtract(BigInteger.ONE);
            BigInteger shifted = f.and(mask).shiftLeft(v);
            f = f.or(shifted);
        }
        return f.bitLength() - 1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        sort(rewardValues.begin(), rewardValues.end());
        rewardValues.erase(unique(rewardValues.begin(), rewardValues.end()), rewardValues.end());
        bitset<100000> f{1};
        for (int v : rewardValues) {
            int shift = f.size() - v;
            f |= f << shift >> (shift - v);
        }
        for (int i = rewardValues.back() * 2 - 1;; i--) {
            if (f.test(i)) {
                return i;
            }
        }
    }
};
```

#### Go

```go
func maxTotalReward(rewardValues []int) int {
	slices.Sort(rewardValues)
	rewardValues = slices.Compact(rewardValues)
	one := big.NewInt(1)
	f := big.NewInt(1)
	p := new(big.Int)
	for _, v := range rewardValues {
		mask := p.Sub(p.Lsh(one, uint(v)), one)
		f.Or(f, p.Lsh(p.And(f, mask), uint(v)))
	}
	return f.BitLen() - 1
}
```

#### TypeScript

```ts
function maxTotalReward(rewardValues: number[]): number {
    rewardValues.sort((a, b) => a - b);
    rewardValues = [...new Set(rewardValues)];
    let f = 1n;
    for (const x of rewardValues) {
        const mask = (1n << BigInt(x)) - 1n;
        f = f | ((f & mask) << BigInt(x));
    }
    return f.toString(2).length - 1;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3181. 执行操作可获得的最大总奖励 II](https://leetcode.cn/problems/maximum-total-reward-using-operations-ii){#3181}

{{< tabs "3181" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxTotalReward(self, rewardValues: List[int]) -> int:
        nums = sorted(set(rewardValues))
        f = 1
        for v in nums:
            f |= (f & ((1 << v) - 1)) << v
        return f.bit_length() - 1
```
{{% /tab %}}
{{% tab "java" %}}
```java
import java.math.BigInteger;

class Solution {
    public int maxTotalReward(int[] rewardValues) {
        int[] nums = Arrays.stream(rewardValues).distinct().sorted().toArray();
        BigInteger f = BigInteger.ONE;
        for (int v : nums) {
            BigInteger mask = BigInteger.ONE.shiftLeft(v).subtract(BigInteger.ONE);
            BigInteger shifted = f.and(mask).shiftLeft(v);
            f = f.or(shifted);
        }
        return f.bitLength() - 1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        sort(rewardValues.begin(), rewardValues.end());
        rewardValues.erase(unique(rewardValues.begin(), rewardValues.end()), rewardValues.end());
        bitset<100000> f{1};
        for (int v : rewardValues) {
            int shift = f.size() - v;
            f |= f << shift >> (shift - v);
        }
        for (int i = rewardValues.back() * 2 - 1;; i--) {
            if (f.test(i)) {
                return i;
            }
        }
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxTotalReward(rewardValues []int) int {
	slices.Sort(rewardValues)
	rewardValues = slices.Compact(rewardValues)
	one := big.NewInt(1)
	f := big.NewInt(1)
	p := new(big.Int)
	for _, v := range rewardValues {
		mask := p.Sub(p.Lsh(one, uint(v)), one)
		f.Or(f, p.Lsh(p.And(f, mask), uint(v)))
	}
	return f.BitLen() - 1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxTotalReward(rewardValues: number[]): number {
    rewardValues.sort((a, b) => a - b);
    rewardValues = [...new Set(rewardValues)];
    let f = 1n;
    for (const x of rewardValues) {
        const mask = (1n << BigInt(x)) - 1n;
        f = f | ((f & mask) << BigInt(x));
    }
    return f.toString(2).length - 1;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>rewardValues</code>，长度为 <code>n</code>，代表奖励的值。</p>

<p>最初，你的总奖励 <code>x</code> 为 0，所有下标都是<strong> 未标记 </strong>的。你可以执行以下操作 <strong>任意次 </strong>：</p>

<ul>
	<li>从区间 <code>[0, n - 1]</code> 中选择一个 <strong>未标记 </strong>的下标 <code>i</code>。</li>
	<li>如果 <code>rewardValues[i]</code> <strong>大于</strong> 你当前的总奖励 <code>x</code>，则将 <code>rewardValues[i]</code> 加到 <code>x</code> 上（即 <code>x = x + rewardValues[i]</code>），并<strong> 标记</strong> 下标 <code>i</code>。</li>
</ul>

<p>以整数形式返回执行最优操作能够获得的<strong> 最大</strong><em> </em>总奖励。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">rewardValues = [1,1,3,3]</span></p>

<p><strong>输出：</strong><span class="example-io">4</span></p>

<p><strong>解释：</strong></p>

<p>依次标记下标 0 和 2，总奖励为 4，这是可获得的最大值。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">rewardValues = [1,6,4,3,2]</span></p>

<p><strong>输出：</strong><span class="example-io">11</span></p>

<p><strong>解释：</strong></p>

<p>依次标记下标 0、2 和 1。总奖励为 11，这是可获得的最大值。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= rewardValues.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= rewardValues[i] &lt;= 5 * 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划 + 位运算

我们定义 $f[i][j]$ 表示用前 $i$ 个奖励值，能否得到总奖励 $j$。初始时 $f[0][0] = \textit{True}$，其余值均为 $\textit{False}$。

我们考虑第 $i$ 个奖励值 $v$，如果我们不选择它，那么 $f[i][j] = f[i - 1][j]$；如果我们选择它，那么 $f[i][j] = f[i - 1][j - v]$，其中 $0 \leq j - v \lt v$。即状态转移方程为：

$$
f[i][j] = f[i - 1][j] \vee f[i - 1][j - v]
$$

最终答案为 $\max\{j \mid f[n][j] = \textit{True}\}$。

由于 $f[i][j]$ 只与 $f[i - 1][j]$ 和 $f[i - 1][j - v]$ 有关，我们可以优化掉第一维，只使用一个一维数组进行状态转移。另外，由于本题数据范围较大，我们需要使用位运算来优化状态转移的效率。

我们定义一个二进制数 $f$ 保存当前的状态，其中 $f$ 的第 $i$ 位为 $1$ 表示当前总奖励为 $i$ 是可达的。

观察上述状态转移方程 $f[j] = f[j] \vee f[j - v]$，这相当于取 $f$ 的低 $v$ 位，再左移 $v$ 位，然后与原来的 $f$ 进行或运算。

那么答案为 $f$ 的最高位的位置。

时间复杂度 $O(n \times M / w)$，空间复杂度 $O(n + M / w)$。其中 $n$ 是数组 `rewardValues` 的长度，而 $M$ 是数组 `rewardValues` 中的最大值的两倍。整数 $w = 32$ 或 $64$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxTotalReward(self, rewardValues: List[int]) -> int:
        nums = sorted(set(rewardValues))
        f = 1
        for v in nums:
            f |= (f & ((1 << v) - 1)) << v
        return f.bit_length() - 1
```

#### Java

```java
import java.math.BigInteger;

class Solution {
    public int maxTotalReward(int[] rewardValues) {
        int[] nums = Arrays.stream(rewardValues).distinct().sorted().toArray();
        BigInteger f = BigInteger.ONE;
        for (int v : nums) {
            BigInteger mask = BigInteger.ONE.shiftLeft(v).subtract(BigInteger.ONE);
            BigInteger shifted = f.and(mask).shiftLeft(v);
            f = f.or(shifted);
        }
        return f.bitLength() - 1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        sort(rewardValues.begin(), rewardValues.end());
        rewardValues.erase(unique(rewardValues.begin(), rewardValues.end()), rewardValues.end());
        bitset<100000> f{1};
        for (int v : rewardValues) {
            int shift = f.size() - v;
            f |= f << shift >> (shift - v);
        }
        for (int i = rewardValues.back() * 2 - 1;; i--) {
            if (f.test(i)) {
                return i;
            }
        }
    }
};
```

#### Go

```go
func maxTotalReward(rewardValues []int) int {
	slices.Sort(rewardValues)
	rewardValues = slices.Compact(rewardValues)
	one := big.NewInt(1)
	f := big.NewInt(1)
	p := new(big.Int)
	for _, v := range rewardValues {
		mask := p.Sub(p.Lsh(one, uint(v)), one)
		f.Or(f, p.Lsh(p.And(f, mask), uint(v)))
	}
	return f.BitLen() - 1
}
```

#### TypeScript

```ts
function maxTotalReward(rewardValues: number[]): number {
    rewardValues.sort((a, b) => a - b);
    rewardValues = [...new Set(rewardValues)];
    let f = 1n;
    for (const x of rewardValues) {
        const mask = (1n << BigInt(x)) - 1n;
        f = f | ((f & mask) << BigInt(x));
    }
    return f.toString(2).length - 1;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3182. 查找得分最高的学生 🔒](https://leetcode.cn/problems/find-top-scoring-students){#3182}

{{< tabs "3182" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT student_id
FROM
    students
    JOIN courses USING (major)
    LEFT JOIN enrollments USING (student_id, course_id)
GROUP BY 1
HAVING SUM(grade = 'A') = COUNT(major)
ORDER BY 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code>students</code></p>

<pre>
+-------------+----------+
| Column Name | Type     | 
+-------------+----------+
| student_id  | int      |
| name        | varchar  |
| major       | varchar  |
+-------------+----------+
student_id 是这张表的主键（有不同值的列的组合）。
这张表的每一行包含学生 ID，学生姓名和他们的专业。
</pre>

<p>表格：<code>courses</code></p>

<pre>
+-------------+----------+
| Column Name | Type     | 
+-------------+----------+
| course_id   | int      |
| name        | varchar  |
| credits     | int      |
| major       | varchar  |
+-------------+----------+
course_id 是这张表的主键（有不同值的列的组合）。
这张表的每一行包含课程 ID，课程名，课程学分和所属专业。
</pre>

<p>表：<code>enrollments</code></p>

<pre>
+-------------+----------+
| Column Name | Type     | 
+-------------+----------+
| student_id  | int      |
| course_id   | int      |
| semester    | varchar  |
| grade       | varchar  |
+-------------+----------+
(student_id, course_id, semester) 是这张表的主键（有不同值的列的组合）。
这张表的每一行包含学生 ID，课程 ID，学期和获得的学分。
</pre>

<p>编写一个解决方案来找到参加过他们的&nbsp;<code>major</code>&nbsp;提供的 <strong>所有课程&nbsp;</strong>并在&nbsp;<strong>所有这些课程中取得等级 A</strong> 的人。</p>

<p>返回结果表以&nbsp;<code>student_id</code> <em><strong>升序&nbsp;</strong></em>排序。</p>

<p>结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong class="example">示例：</strong></p>

<div class="example-block">
<p><b>输入：</b></p>

<p>students 表：</p>

<pre class="example-io">
+------------+------------------+------------------+
| student_id | name             | major            |
+------------+------------------+------------------+
| 1          | Alice            | Computer Science |
| 2          | Bob              | Computer Science |
| 3          | Charlie          | Mathematics      |
| 4          | David            | Mathematics      |
+------------+------------------+------------------+
</pre>

<p>courses 表：</p>

<pre class="example-io">
+-----------+-----------------+---------+------------------+
| course_id | name            | credits | major            |
+-----------+-----------------+---------+------------------+
| 101       | Algorithms      | 3       | Computer Science |
| 102       | Data Structures | 3       | Computer Science |
| 103       | Calculus        | 4       | Mathematics      |
| 104       | Linear Algebra  | 4       | Mathematics      |
+-----------+-----------------+---------+------------------+
</pre>

<p>enrollments 表：</p>

<pre class="example-io">
+------------+-----------+----------+-------+
| student_id | course_id | semester | grade |
+------------+-----------+----------+-------+
| 1          | 101       | Fall 2023| A     |
| 1          | 102       | Fall 2023| A     |
| 2          | 101       | Fall 2023| B     |
| 2          | 102       | Fall 2023| A     |
| 3          | 103       | Fall 2023| A     |
| 3          | 104       | Fall 2023| A     |
| 4          | 103       | Fall 2023| A     |
| 4          | 104       | Fall 2023| B     |
+------------+-----------+----------+-------+
</pre>

<p><strong>输出：</strong></p>

<pre class="example-io">
+------------+
| student_id |
+------------+
| 1          |
| 3          |
+------------+
</pre>

<p><strong>解释：</strong></p>

<ul>
	<li>Alice (student_id 1) 是计算机科学专业并且修了 “Algorithms” 和 “Data Structures” 课程，都获得了 ‘A’。</li>
	<li>Bob (student_id 2) 是计算机科学专业但没有在全部必修课程中获得 ‘A’。</li>
	<li>Charlie (student_id 3) 是数学专业并且修了 “Calculus”&nbsp;和 “Linear Algebra”&nbsp;课程，都获得了 ‘A’。</li>
	<li>David (student_id 4) 是数学专业但没有在全部必修课程中获得 'A'。</li>
</ul>

<p><b>注意：</b>输出表以&nbsp;student_id 升序排序。</p>
</div>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：连接表 + 分组

我们可以将 `students` 表和 `courses` 按照 `major` 字段连接起来，然后再将 `enrollments` 表左连接到上述结果表中，最后按照 `student_id` 分组，筛选出满足条件的学生。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT student_id
FROM
    students
    JOIN courses USING (major)
    LEFT JOIN enrollments USING (student_id, course_id)
GROUP BY 1
HAVING SUM(grade = 'A') = COUNT(major)
ORDER BY 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3183. 达到总和的方法数量 🔒](https://leetcode.cn/problems/the-number-of-ways-to-make-the-sum){#3183}

{{< tabs "3183" >}}

{{% tab "python" %}}
```python
m = 10**5 + 1
mod = 10**9 + 7
coins = [1, 2, 6]
f = [0] * (m)
f[0] = 1
for x in coins:
    for j in range(x, m):
        f[j] = (f[j] + f[j - x]) % mod


class Solution:
    def numberOfWays(self, n: int) -> int:
        ans = f[n]
        if n >= 4:
            ans = (ans + f[n - 4]) % mod
        if n >= 8:
            ans = (ans + f[n - 8]) % mod
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private static final int MOD = 1000000007;
    private static final int M = 100001;
    private static final int[] COINS = {1, 2, 6};
    private static final int[] f = new int[M];

    static {
        f[0] = 1;
        for (int x : COINS) {
            for (int j = x; j < M; ++j) {
                f[j] = (f[j] + f[j - x]) % MOD;
            }
        }
    }

    public int numberOfWays(int n) {
        int ans = f[n];
        if (n >= 4) {
            ans = (ans + f[n - 4]) % MOD;
        }
        if (n >= 8) {
            ans = (ans + f[n - 8]) % MOD;
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
const int m = 1e5 + 1;
const int mod = 1e9 + 7;
int f[m + 1];

auto init = [] {
    f[0] = 1;
    int coins[3] = {1, 2, 6};
    for (int x : coins) {
        for (int j = x; j < m; ++j) {
            f[j] = (f[j] + f[j - x]) % mod;
        }
    }
    return 0;
}();


class Solution {
public:
    int numberOfWays(int n) {
        int ans = f[n];
        if (n >= 4) {
            ans = (ans + f[n - 4]) % mod;
        }
        if (n >= 8) {
            ans = (ans + f[n - 8]) % mod;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
const (
    m   = 100001
    mod = 1000000007
)

var f [m]int

func init() {
    f[0] = 1
    coins := []int{1, 2, 6}
    for _, x := range coins {
        for j := x; j < m; j++ {
            f[j] = (f[j] + f[j-x]) % mod
        }
    }
}

func numberOfWays(n int) int {
    ans := f[n]
    if n >= 4 {
        ans = (ans + f[n-4]) % mod
    }
    if n >= 8 {
        ans = (ans + f[n-8]) % mod
    }
    return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
const m: number = 10 ** 5 + 1;
const mod: number = 10 ** 9 + 7;
const f: number[] = Array(m).fill(0);

(() => {
    f[0] = 1;
    const coins: number[] = [1, 2, 6];
    for (const x of coins) {
        for (let j = x; j < m; ++j) {
            f[j] = (f[j] + f[j - x]) % mod;
        }
    }
})();

function numberOfWays(n: number): number {
    let ans = f[n];
    if (n >= 4) {
        ans = (ans + f[n - 4]) % mod;
    }
    if (n >= 8) {
        ans = (ans + f[n - 8]) % mod;
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

<p>给定 <strong>无限</strong> 数量的面值为 1，2，6 的硬币，并且&nbsp;<strong>只有</strong> 2 枚硬币面值为 4。</p>

<p>给定一个整数&nbsp;<code>n</code>&nbsp;，返回用你持有的硬币达到总和&nbsp;<code>n</code> 的方法数量。</p>

<p>因为答案可能会很大，将其 <strong>取模&nbsp;</strong><code>10<sup>9</sup>&nbsp;+ 7</code>。</p>

<p><strong>注意</strong>&nbsp;硬币的顺序并不重要，<code>[2, 2, 3]</code> 与&nbsp;<code>[2, 3, 2]</code>&nbsp;相同。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">n = 4</span></p>

<p><span class="example-io"><b>输出：</b>4</span></p>

<p><strong>解释：</strong></p>

<p>有四种组合：<code>[1, 1, 1, 1]</code>，<code>[1, 1, 2]</code>，<code>[2, 2]</code>，<code>[4]</code>。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">n = 12</span></p>

<p><span class="example-io"><b>输出：</b></span><span class="example-io">22</span></p>

<p><strong>解释：</strong></p>

<p>注意&nbsp;<code>[4, 4, 4]</code>&nbsp;<strong>不是</strong> 一个有效的组合，因为我们无法使用 4 三次。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">n = 5</span></p>

<p><span class="example-io"><b>输出：</b></span><span class="example-io">4</span></p>

<p><strong>解释：</strong></p>

<p>有四种组合：<code>[1, 1, 1, 1, 1]</code>，<code>[1, 1, 1, 2]</code>，<code>[1, 2, 2]</code>，<code>[1, 4]</code>。</p>
</div>

<p>&nbsp;</p>

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

### 方法一：动态规划（完全背包）

我们可以先忽略硬币 $4$，定义硬币数组 `coins = [1, 2, 6]`，然后使用完全背包的思想，定义 $f[j]$ 表示使用前 $i$ 种硬币凑成金额 $j$ 的方案数，初始时 $f[0] = 1$，然后我们遍历硬币数组 `coins`，对于每一种硬币 $x$，我们遍历 $x$ 到 $n$ 的金额，更新 $f[j] = f[j] + f[j - x]$。

最后 $f[n]$ 就是使用硬币 $1, 2, 6$ 凑成金额 $n$ 的方案数，然后如果 $n \geq 4$，我们考虑选择一个硬币 $4$，那么方案数就是 $f[n] + f[n - 4]$，如果 $n \geq 8$，我们再考虑选择两个硬币 $4$，那么方案数就是 $f[n] + f[n - 4] + f[n - 8]$。

注意答案的取模操作。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是金额。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numberOfWays(self, n: int) -> int:
        mod = 10**9 + 7
        coins = [1, 2, 6]
        f = [0] * (n + 1)
        f[0] = 1
        for x in coins:
            for j in range(x, n + 1):
                f[j] = (f[j] + f[j - x]) % mod
        ans = f[n]
        if n >= 4:
            ans = (ans + f[n - 4]) % mod
        if n >= 8:
            ans = (ans + f[n - 8]) % mod
        return ans
```

#### Java

```java
class Solution {
    public int numberOfWays(int n) {
        final int mod = (int) 1e9 + 7;
        int[] coins = {1, 2, 6};
        int[] f = new int[n + 1];
        f[0] = 1;
        for (int x : coins) {
            for (int j = x; j <= n; ++j) {
                f[j] = (f[j] + f[j - x]) % mod;
            }
        }
        int ans = f[n];
        if (n >= 4) {
            ans = (ans + f[n - 4]) % mod;
        }
        if (n >= 8) {
            ans = (ans + f[n - 8]) % mod;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numberOfWays(int n) {
        const int mod = 1e9 + 7;
        int coins[3] = {1, 2, 6};
        int f[n + 1];
        memset(f, 0, sizeof(f));
        f[0] = 1;
        for (int x : coins) {
            for (int j = x; j <= n; ++j) {
                f[j] = (f[j] + f[j - x]) % mod;
            }
        }
        int ans = f[n];
        if (n >= 4) {
            ans = (ans + f[n - 4]) % mod;
        }
        if (n >= 8) {
            ans = (ans + f[n - 8]) % mod;
        }
        return ans;
    }
};
```

#### Go

```go
func numberOfWays(n int) int {
	const mod int = 1e9 + 7
	coins := []int{1, 2, 6}
	f := make([]int, n+1)
	f[0] = 1
	for _, x := range coins {
		for j := x; j <= n; j++ {
			f[j] = (f[j] + f[j-x]) % mod
		}
	}
	ans := f[n]
	if n >= 4 {
		ans = (ans + f[n-4]) % mod
	}
	if n >= 8 {
		ans = (ans + f[n-8]) % mod
	}
	return ans
}
```

#### TypeScript

```ts
function numberOfWays(n: number): number {
    const mod = 10 ** 9 + 7;
    const f: number[] = Array(n + 1).fill(0);
    f[0] = 1;
    for (const x of [1, 2, 6]) {
        for (let j = x; j <= n; ++j) {
            f[j] = (f[j] + f[j - x]) % mod;
        }
    }
    let ans = f[n];
    if (n >= 4) {
        ans = (ans + f[n - 4]) % mod;
    }
    if (n >= 8) {
        ans = (ans + f[n - 8]) % mod;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：预处理 + 动态规划（完全背包）

我们可以先预处理出 $1$ 到 $10^5$ 的所有金额的方案数，然后根据 $n$ 的大小直接返回对应的方案数：

-   如果 $n < 4$，直接返回 $f[n]$；
-   如果 $4 \leq n < 8$，返回 $f[n] + f[n - 4]$；
-   如果 $n \geq 8$，返回 $f[n] + f[n - 4] + f[n - 8]$。

注意答案的取模操作。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是金额。

<!-- tabs:start -->

#### Python3

```python
m = 10**5 + 1
mod = 10**9 + 7
coins = [1, 2, 6]
f = [0] * (m)
f[0] = 1
for x in coins:
    for j in range(x, m):
        f[j] = (f[j] + f[j - x]) % mod


class Solution:
    def numberOfWays(self, n: int) -> int:
        ans = f[n]
        if n >= 4:
            ans = (ans + f[n - 4]) % mod
        if n >= 8:
            ans = (ans + f[n - 8]) % mod
        return ans
```

#### Java

```java
class Solution {
    private static final int MOD = 1000000007;
    private static final int M = 100001;
    private static final int[] COINS = {1, 2, 6};
    private static final int[] f = new int[M];

    static {
        f[0] = 1;
        for (int x : COINS) {
            for (int j = x; j < M; ++j) {
                f[j] = (f[j] + f[j - x]) % MOD;
            }
        }
    }

    public int numberOfWays(int n) {
        int ans = f[n];
        if (n >= 4) {
            ans = (ans + f[n - 4]) % MOD;
        }
        if (n >= 8) {
            ans = (ans + f[n - 8]) % MOD;
        }
        return ans;
    }
}
```

#### C++

```cpp
const int m = 1e5 + 1;
const int mod = 1e9 + 7;
int f[m + 1];

auto init = [] {
    f[0] = 1;
    int coins[3] = {1, 2, 6};
    for (int x : coins) {
        for (int j = x; j < m; ++j) {
            f[j] = (f[j] + f[j - x]) % mod;
        }
    }
    return 0;
}();


class Solution {
public:
    int numberOfWays(int n) {
        int ans = f[n];
        if (n >= 4) {
            ans = (ans + f[n - 4]) % mod;
        }
        if (n >= 8) {
            ans = (ans + f[n - 8]) % mod;
        }
        return ans;
    }
};
```

#### Go

```go
const (
    m   = 100001
    mod = 1000000007
)

var f [m]int

func init() {
    f[0] = 1
    coins := []int{1, 2, 6}
    for _, x := range coins {
        for j := x; j < m; j++ {
            f[j] = (f[j] + f[j-x]) % mod
        }
    }
}

func numberOfWays(n int) int {
    ans := f[n]
    if n >= 4 {
        ans = (ans + f[n-4]) % mod
    }
    if n >= 8 {
        ans = (ans + f[n-8]) % mod
    }
    return ans
}
```

#### TypeScript

```ts
const m: number = 10 ** 5 + 1;
const mod: number = 10 ** 9 + 7;
const f: number[] = Array(m).fill(0);

(() => {
    f[0] = 1;
    const coins: number[] = [1, 2, 6];
    for (const x of coins) {
        for (let j = x; j < m; ++j) {
            f[j] = (f[j] + f[j - x]) % mod;
        }
    }
})();

function numberOfWays(n: number): number {
    let ans = f[n];
    if (n >= 4) {
        ans = (ans + f[n - 4]) % mod;
    }
    if (n >= 8) {
        ans = (ans + f[n - 8]) % mod;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3184. 构成整天的下标对数目 I](https://leetcode.cn/problems/count-pairs-that-form-a-complete-day-i){#3184}

{{< tabs "3184" >}}

{{% tab "python" %}}
```python
class Solution:
    def countCompleteDayPairs(self, hours: List[int]) -> int:
        cnt = Counter()
        ans = 0
        for x in hours:
            ans += cnt[(24 - (x % 24)) % 24]
            cnt[x % 24] += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countCompleteDayPairs(int[] hours) {
        int[] cnt = new int[24];
        int ans = 0;
        for (int x : hours) {
            ans += cnt[(24 - x % 24) % 24];
            ++cnt[x % 24];
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
    int countCompleteDayPairs(vector<int>& hours) {
        int cnt[24]{};
        int ans = 0;
        for (int x : hours) {
            ans += cnt[(24 - x % 24) % 24];
            ++cnt[x % 24];
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countCompleteDayPairs(hours []int) (ans int) {
	cnt := [24]int{}
	for _, x := range hours {
		ans += cnt[(24-x%24)%24]
		cnt[x%24]++
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countCompleteDayPairs(hours: number[]): number {
    const cnt: number[] = Array(24).fill(0);
    let ans: number = 0;
    for (const x of hours) {
        ans += cnt[(24 - (x % 24)) % 24];
        ++cnt[x % 24];
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

<p>给你一个整数数组 <code>hours</code>，表示以 <strong>小时 </strong>为单位的时间，返回一个整数，表示满足 <code>i &lt; j</code> 且 <code>hours[i] + hours[j]</code> 构成 <strong>整天 </strong>的下标对&nbsp;<code>i</code>, <code>j</code> 的数目。</p>

<p><strong>整天 </strong>定义为时间持续时间是 24 小时的 <strong>整数倍 </strong>。</p>

<p>例如，1 天是 24 小时，2 天是 48 小时，3 天是 72 小时，以此类推。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">hours = [12,12,30,24,24]</span></p>

<p><strong>输出：</strong> <span class="example-io">2</span></p>

<p><strong>解释：</strong></p>

<p>构成整天的下标对分别是 <code>(0, 1)</code> 和 <code>(3, 4)</code>。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">hours = [72,48,24,3]</span></p>

<p><strong>输出：</strong> <span class="example-io">3</span></p>

<p><strong>解释：</strong></p>

<p>构成整天的下标对分别是 <code>(0, 1)</code>、<code>(0, 2)</code> 和 <code>(1, 2)</code>。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= hours.length &lt;= 100</code></li>
	<li><code>1 &lt;= hours[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数

我们可以用一个哈希表或者一个长度为 $24$ 的数组 $\textit{cnt}$ 来记录每个小时数模 $24$ 的出现次数。

遍历数组 $\textit{hours}$，对于每个小时数 $x$，我们可以得出与 $x$ 相加为 $24$ 的倍数，且模 $24$ 之后的数为 $(24 - x \bmod 24) \bmod 24$。累加这个数在哈希表或者数组中的出现次数即可。然后我们将 $x$ 的模 $24$ 的出现次数加一。

遍历完数组 $\textit{hours}$ 后，我们就可以得到满足题意的下标对数目。

时间复杂度 $O(n)$，其中 $n$ 为数组 $\textit{hours}$ 的长度。空间复杂度 $O(C)$，其中 $C=24$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countCompleteDayPairs(self, hours: List[int]) -> int:
        cnt = Counter()
        ans = 0
        for x in hours:
            ans += cnt[(24 - (x % 24)) % 24]
            cnt[x % 24] += 1
        return ans
```

#### Java

```java
class Solution {
    public int countCompleteDayPairs(int[] hours) {
        int[] cnt = new int[24];
        int ans = 0;
        for (int x : hours) {
            ans += cnt[(24 - x % 24) % 24];
            ++cnt[x % 24];
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        int cnt[24]{};
        int ans = 0;
        for (int x : hours) {
            ans += cnt[(24 - x % 24) % 24];
            ++cnt[x % 24];
        }
        return ans;
    }
};
```

#### Go

```go
func countCompleteDayPairs(hours []int) (ans int) {
	cnt := [24]int{}
	for _, x := range hours {
		ans += cnt[(24-x%24)%24]
		cnt[x%24]++
	}
	return
}
```

#### TypeScript

```ts
function countCompleteDayPairs(hours: number[]): number {
    const cnt: number[] = Array(24).fill(0);
    let ans: number = 0;
    for (const x of hours) {
        ans += cnt[(24 - (x % 24)) % 24];
        ++cnt[x % 24];
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3185. 构成整天的下标对数目 II](https://leetcode.cn/problems/count-pairs-that-form-a-complete-day-ii){#3185}

{{< tabs "3185" >}}

{{% tab "python" %}}
```python
class Solution:
    def countCompleteDayPairs(self, hours: List[int]) -> int:
        cnt = Counter()
        ans = 0
        for x in hours:
            ans += cnt[(24 - (x % 24)) % 24]
            cnt[x % 24] += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long countCompleteDayPairs(int[] hours) {
        int[] cnt = new int[24];
        long ans = 0;
        for (int x : hours) {
            ans += cnt[(24 - x % 24) % 24];
            ++cnt[x % 24];
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
    long long countCompleteDayPairs(vector<int>& hours) {
        int cnt[24]{};
        long long ans = 0;
        for (int x : hours) {
            ans += cnt[(24 - x % 24) % 24];
            ++cnt[x % 24];
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countCompleteDayPairs(hours []int) (ans int64) {
	cnt := [24]int{}
	for _, x := range hours {
		ans += int64(cnt[(24-x%24)%24])
		cnt[x%24]++
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countCompleteDayPairs(hours: number[]): number {
    const cnt: number[] = Array(24).fill(0);
    let ans: number = 0;
    for (const x of hours) {
        ans += cnt[(24 - (x % 24)) % 24];
        ++cnt[x % 24];
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

<p>给你一个整数数组 <code>hours</code>，表示以 <strong>小时 </strong>为单位的时间，返回一个整数，表示满足 <code>i &lt; j</code> 且 <code>hours[i] + hours[j]</code> 构成 <strong>整天 </strong>的下标对&nbsp;<code>i</code>, <code>j</code> 的数目。</p>

<p><strong>整天 </strong>定义为时间持续时间是 24 小时的 <strong>整数倍 </strong>。</p>

<p>例如，1 天是 24 小时，2 天是 48 小时，3 天是 72 小时，以此类推。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">hours = [12,12,30,24,24]</span></p>

<p><strong>输出：</strong> <span class="example-io">2</span></p>

<p><strong>解释：</strong></p>

<p>构成整天的下标对分别是 <code>(0, 1)</code> 和 <code>(3, 4)</code>。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">hours = [72,48,24,3]</span></p>

<p><strong>输出：</strong> <span class="example-io">3</span></p>

<p><strong>解释：</strong></p>

<p>构成整天的下标对分别是 <code>(0, 1)</code>、<code>(0, 2)</code> 和 <code>(1, 2)</code>。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= hours.length &lt;= 5 * 10<sup>5</sup></code></li>
	<li><code>1 &lt;= hours[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数

我们可以用一个哈希表或者一个长度为 $24$ 的数组 $\textit{cnt}$ 来记录每个小时数模 $24$ 的出现次数。

遍历数组 $\textit{hours}$，对于每个小时数 $x$，我们可以得出与 $x$ 相加为 $24$ 的倍数，且模 $24$ 之后的数为 $(24 - x \bmod 24) \bmod 24$。累加这个数在哈希表或者数组中的出现次数即可。然后我们将 $x$ 的模 $24$ 的出现次数加一。

遍历完数组 $\textit{hours}$ 后，我们就可以得到满足题意的下标对数目。

时间复杂度 $O(n)$，其中 $n$ 为数组 $\textit{hours}$ 的长度。空间复杂度 $O(C)$，其中 $C=24$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countCompleteDayPairs(self, hours: List[int]) -> int:
        cnt = Counter()
        ans = 0
        for x in hours:
            ans += cnt[(24 - (x % 24)) % 24]
            cnt[x % 24] += 1
        return ans
```

#### Java

```java
class Solution {
    public long countCompleteDayPairs(int[] hours) {
        int[] cnt = new int[24];
        long ans = 0;
        for (int x : hours) {
            ans += cnt[(24 - x % 24) % 24];
            ++cnt[x % 24];
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        int cnt[24]{};
        long long ans = 0;
        for (int x : hours) {
            ans += cnt[(24 - x % 24) % 24];
            ++cnt[x % 24];
        }
        return ans;
    }
};
```

#### Go

```go
func countCompleteDayPairs(hours []int) (ans int64) {
	cnt := [24]int{}
	for _, x := range hours {
		ans += int64(cnt[(24-x%24)%24])
		cnt[x%24]++
	}
	return
}
```

#### TypeScript

```ts
function countCompleteDayPairs(hours: number[]): number {
    const cnt: number[] = Array(24).fill(0);
    let ans: number = 0;
    for (const x of hours) {
        ans += cnt[(24 - (x % 24)) % 24];
        ++cnt[x % 24];
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3186. 施咒的最大总伤害](https://leetcode.cn/problems/maximum-total-damage-with-spell-casting){#3186}

{{< tabs "3186" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumTotalDamage(self, power: List[int]) -> int:
        @cache
        def dfs(i: int) -> int:
            if i >= n:
                return 0
            a = dfs(i + cnt[power[i]])
            b = power[i] * cnt[power[i]] + dfs(nxt[i])
            return max(a, b)

        n = len(power)
        cnt = Counter(power)
        power.sort()
        nxt = [bisect_right(power, x + 2, lo=i + 1) for i, x in enumerate(power)]
        return dfs(0)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private Long[] f;
    private int[] power;
    private Map<Integer, Integer> cnt;
    private int[] nxt;
    private int n;

    public long maximumTotalDamage(int[] power) {
        Arrays.sort(power);
        this.power = power;
        n = power.length;
        f = new Long[n];
        cnt = new HashMap<>(n);
        nxt = new int[n];
        for (int i = 0; i < n; ++i) {
            cnt.merge(power[i], 1, Integer::sum);
            int l = Arrays.binarySearch(power, power[i] + 3);
            l = l < 0 ? -l - 1 : l;
            nxt[i] = l;
        }
        return dfs(0);
    }

    private long dfs(int i) {
        if (i >= n) {
            return 0;
        }
        if (f[i] != null) {
            return f[i];
        }
        long a = dfs(i + cnt.get(power[i]));
        long b = 1L * power[i] * cnt.get(power[i]) + dfs(nxt[i]);
        return f[i] = Math.max(a, b);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        sort(power.begin(), power.end());
        this->power = power;
        n = power.size();
        f.resize(n);
        nxt.resize(n);
        for (int i = 0; i < n; ++i) {
            cnt[power[i]]++;
            nxt[i] = upper_bound(power.begin() + i + 1, power.end(), power[i] + 2) - power.begin();
        }
        return dfs(0);
    }

private:
    unordered_map<int, int> cnt;
    vector<long long> f;
    vector<int> power;
    vector<int> nxt;
    int n;

    long long dfs(int i) {
        if (i >= n) {
            return 0;
        }
        if (f[i]) {
            return f[i];
        }
        long long a = dfs(i + cnt[power[i]]);
        long long b = 1LL * power[i] * cnt[power[i]] + dfs(nxt[i]);
        return f[i] = max(a, b);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumTotalDamage(power []int) int64 {
	n := len(power)
	sort.Ints(power)
	cnt := map[int]int{}
	nxt := make([]int, n)
	f := make([]int64, n)
	for i, x := range power {
		cnt[x]++
		nxt[i] = sort.SearchInts(power, x+3)
	}
	var dfs func(int) int64
	dfs = func(i int) int64 {
		if i >= n {
			return 0
		}
		if f[i] != 0 {
			return f[i]
		}
		a := dfs(i + cnt[power[i]])
		b := int64(power[i]*cnt[power[i]]) + dfs(nxt[i])
		f[i] = max(a, b)
		return f[i]
	}
	return dfs(0)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumTotalDamage(power: number[]): number {
    const n = power.length;
    power.sort((a, b) => a - b);
    const f: number[] = Array(n).fill(0);
    const cnt: Record<number, number> = {};
    const nxt: number[] = Array(n).fill(0);
    for (let i = 0; i < n; ++i) {
        cnt[power[i]] = (cnt[power[i]] || 0) + 1;
        let [l, r] = [i + 1, n];
        while (l < r) {
            const mid = (l + r) >> 1;
            if (power[mid] > power[i] + 2) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        nxt[i] = l;
    }
    const dfs = (i: number): number => {
        if (i >= n) {
            return 0;
        }
        if (f[i]) {
            return f[i];
        }
        const a = dfs(i + cnt[power[i]]);
        const b = power[i] * cnt[power[i]] + dfs(nxt[i]);
        return (f[i] = Math.max(a, b));
    };
    return dfs(0);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>一个魔法师有许多不同的咒语。</p>

<p>给你一个数组&nbsp;<code>power</code>&nbsp;，其中每个元素表示一个咒语的伤害值，可能会有多个咒语有相同的伤害值。</p>

<p>已知魔法师使用伤害值为&nbsp;<code>power[i]</code>&nbsp;的咒语时，他们就&nbsp;<strong>不能</strong>&nbsp;使用伤害为&nbsp;<code>power[i] - 2</code>&nbsp;，<code>power[i] - 1</code>&nbsp;，<code>power[i] + 1</code>&nbsp;或者&nbsp;<code>power[i] + 2</code>&nbsp;的咒语。</p>

<p>每个咒语最多只能被使用 <strong>一次</strong>&nbsp;。</p>

<p>请你返回这个魔法师可以达到的伤害值之和的 <strong>最大值</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>power = [1,1,3,4]</span></p>

<p><span class="example-io"><b>输出：</b>6</span></p>

<p><strong>解释：</strong></p>

<p>可以使用咒语 0，1，3，伤害值分别为 1，1，4，总伤害值为 6 。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>power = [7,1,6,6]</span></p>

<p><span class="example-io"><b>输出：</b>13</span></p>

<p><strong>解释：</strong></p>

<p>可以使用咒语 1，2，3，伤害值分别为 1，6，6，总伤害值为 13 。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= power.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= power[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二分查找 + 记忆化搜索

我们可以先对数组 $\textit{power}$ 进行排序，用一个哈希表 $\textit{cnt}$ 来记录每个伤害值的出现次数，然后遍历数组 $\textit{power}$，对于每个伤害值 $x$，我们可以得出使用伤害值为 $x$ 的咒语时，可以使用的下一个伤害值的索引，即第一个大于 $x + 2$ 的伤害值的索引，我们可以使用二分查找来找到这个索引，记录在数组 $\textit{nxt}$ 中。

接下来，我们定义一个函数 $\textit{dfs}$，用来计算从第 $i$ 个伤害值开始，可以获得的最大伤害值。

在 $\textit{dfs}$ 函数中，我们可以选择跳过当前伤害值，那么我们可以跳过当前伤害值的所有相同伤害值，直接跳到 $i + \textit{cnt}[x]$，可以获得的伤害值为 $\textit{dfs}(i + \textit{cnt}[x])$；或者我们可以选择使用当前伤害值，那么我们可以使用当前伤害值的所有相同伤害值，然后跳到下一个伤害值的索引，可以获得的伤害值为 $x \times \textit{cnt}[x] + \textit{dfs}(\textit{nxt}[i])$，其中 $\textit{nxt}[i]$ 表示第一个大于 $x + 2$ 的伤害值的索引。我们取这两种情况的最大值作为函数的返回值。

为了避免重复计算，我们可以使用记忆化搜索，将已经计算过的结果保存在数组 $\textit{f}$ 中，这样在计算 $\textit{dfs}(i)$ 时，如果 $\textit{f}[i]$ 不为 $0$，则直接返回 $\textit{f}[i]$。

答案即为 $\textit{dfs}(0)$。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $\textit{power}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumTotalDamage(self, power: List[int]) -> int:
        @cache
        def dfs(i: int) -> int:
            if i >= n:
                return 0
            a = dfs(i + cnt[power[i]])
            b = power[i] * cnt[power[i]] + dfs(nxt[i])
            return max(a, b)

        n = len(power)
        cnt = Counter(power)
        power.sort()
        nxt = [bisect_right(power, x + 2, lo=i + 1) for i, x in enumerate(power)]
        return dfs(0)
```

#### Java

```java
class Solution {
    private Long[] f;
    private int[] power;
    private Map<Integer, Integer> cnt;
    private int[] nxt;
    private int n;

    public long maximumTotalDamage(int[] power) {
        Arrays.sort(power);
        this.power = power;
        n = power.length;
        f = new Long[n];
        cnt = new HashMap<>(n);
        nxt = new int[n];
        for (int i = 0; i < n; ++i) {
            cnt.merge(power[i], 1, Integer::sum);
            int l = Arrays.binarySearch(power, power[i] + 3);
            l = l < 0 ? -l - 1 : l;
            nxt[i] = l;
        }
        return dfs(0);
    }

    private long dfs(int i) {
        if (i >= n) {
            return 0;
        }
        if (f[i] != null) {
            return f[i];
        }
        long a = dfs(i + cnt.get(power[i]));
        long b = 1L * power[i] * cnt.get(power[i]) + dfs(nxt[i]);
        return f[i] = Math.max(a, b);
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        sort(power.begin(), power.end());
        this->power = power;
        n = power.size();
        f.resize(n);
        nxt.resize(n);
        for (int i = 0; i < n; ++i) {
            cnt[power[i]]++;
            nxt[i] = upper_bound(power.begin() + i + 1, power.end(), power[i] + 2) - power.begin();
        }
        return dfs(0);
    }

private:
    unordered_map<int, int> cnt;
    vector<long long> f;
    vector<int> power;
    vector<int> nxt;
    int n;

    long long dfs(int i) {
        if (i >= n) {
            return 0;
        }
        if (f[i]) {
            return f[i];
        }
        long long a = dfs(i + cnt[power[i]]);
        long long b = 1LL * power[i] * cnt[power[i]] + dfs(nxt[i]);
        return f[i] = max(a, b);
    }
};
```

#### Go

```go
func maximumTotalDamage(power []int) int64 {
	n := len(power)
	sort.Ints(power)
	cnt := map[int]int{}
	nxt := make([]int, n)
	f := make([]int64, n)
	for i, x := range power {
		cnt[x]++
		nxt[i] = sort.SearchInts(power, x+3)
	}
	var dfs func(int) int64
	dfs = func(i int) int64 {
		if i >= n {
			return 0
		}
		if f[i] != 0 {
			return f[i]
		}
		a := dfs(i + cnt[power[i]])
		b := int64(power[i]*cnt[power[i]]) + dfs(nxt[i])
		f[i] = max(a, b)
		return f[i]
	}
	return dfs(0)
}
```

#### TypeScript

```ts
function maximumTotalDamage(power: number[]): number {
    const n = power.length;
    power.sort((a, b) => a - b);
    const f: number[] = Array(n).fill(0);
    const cnt: Record<number, number> = {};
    const nxt: number[] = Array(n).fill(0);
    for (let i = 0; i < n; ++i) {
        cnt[power[i]] = (cnt[power[i]] || 0) + 1;
        let [l, r] = [i + 1, n];
        while (l < r) {
            const mid = (l + r) >> 1;
            if (power[mid] > power[i] + 2) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        nxt[i] = l;
    }
    const dfs = (i: number): number => {
        if (i >= n) {
            return 0;
        }
        if (f[i]) {
            return f[i];
        }
        const a = dfs(i + cnt[power[i]]);
        const b = power[i] * cnt[power[i]] + dfs(nxt[i]);
        return (f[i] = Math.max(a, b));
    };
    return dfs(0);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3187. 数组中的峰值](https://leetcode.cn/problems/peaks-in-array){#3187}

{{< tabs "3187" >}}

{{% tab "python" %}}
```python
class BinaryIndexedTree:
    __slots__ = "n", "c"

    def __init__(self, n: int):
        self.n = n
        self.c = [0] * (n + 1)

    def update(self, x: int, delta: int) -> None:
        while x <= self.n:
            self.c[x] += delta
            x += x & -x

    def query(self, x: int) -> int:
        s = 0
        while x:
            s += self.c[x]
            x -= x & -x
        return s


class Solution:
    def countOfPeaks(self, nums: List[int], queries: List[List[int]]) -> List[int]:
        def update(i: int, val: int):
            if i <= 0 or i >= n - 1:
                return
            if nums[i - 1] < nums[i] and nums[i] > nums[i + 1]:
                tree.update(i, val)

        n = len(nums)
        tree = BinaryIndexedTree(n - 1)
        for i in range(1, n - 1):
            update(i, 1)
        ans = []
        for q in queries:
            if q[0] == 1:
                l, r = q[1] + 1, q[2] - 1
                ans.append(0 if l > r else tree.query(r) - tree.query(l - 1))
            else:
                idx, val = q[1:]
                for i in range(idx - 1, idx + 2):
                    update(i, -1)
                nums[idx] = val
                for i in range(idx - 1, idx + 2):
                    update(i, 1)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class BinaryIndexedTree {
    private int n;
    private int[] c;

    public BinaryIndexedTree(int n) {
        this.n = n;
        this.c = new int[n + 1];
    }

    public void update(int x, int delta) {
        for (; x <= n; x += x & -x) {
            c[x] += delta;
        }
    }

    public int query(int x) {
        int s = 0;
        for (; x > 0; x -= x & -x) {
            s += c[x];
        }
        return s;
    }
}

class Solution {
    private BinaryIndexedTree tree;
    private int[] nums;

    public List<Integer> countOfPeaks(int[] nums, int[][] queries) {
        int n = nums.length;
        this.nums = nums;
        tree = new BinaryIndexedTree(n - 1);
        for (int i = 1; i < n - 1; ++i) {
            update(i, 1);
        }
        List<Integer> ans = new ArrayList<>();
        for (var q : queries) {
            if (q[0] == 1) {
                int l = q[1] + 1, r = q[2] - 1;
                ans.add(l > r ? 0 : tree.query(r) - tree.query(l - 1));
            } else {
                int idx = q[1], val = q[2];
                for (int i = idx - 1; i <= idx + 1; ++i) {
                    update(i, -1);
                }
                nums[idx] = val;
                for (int i = idx - 1; i <= idx + 1; ++i) {
                    update(i, 1);
                }
            }
        }
        return ans;
    }

    private void update(int i, int val) {
        if (i <= 0 || i >= nums.length - 1) {
            return;
        }
        if (nums[i - 1] < nums[i] && nums[i] > nums[i + 1]) {
            tree.update(i, val);
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class BinaryIndexedTree {
private:
    int n;
    vector<int> c;

public:
    BinaryIndexedTree(int n)
        : n(n)
        , c(n + 1) {}

    void update(int x, int delta) {
        for (; x <= n; x += x & -x) {
            c[x] += delta;
        }
    }

    int query(int x) {
        int s = 0;
        for (; x > 0; x -= x & -x) {
            s += c[x];
        }
        return s;
    }
};

class Solution {
public:
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        BinaryIndexedTree tree(n - 1);
        auto update = [&](int i, int val) {
            if (i <= 0 || i >= n - 1) {
                return;
            }
            if (nums[i - 1] < nums[i] && nums[i] > nums[i + 1]) {
                tree.update(i, val);
            }
        };
        for (int i = 1; i < n - 1; ++i) {
            update(i, 1);
        }
        vector<int> ans;
        for (auto& q : queries) {
            if (q[0] == 1) {
                int l = q[1] + 1, r = q[2] - 1;
                ans.push_back(l > r ? 0 : tree.query(r) - tree.query(l - 1));
            } else {
                int idx = q[1], val = q[2];
                for (int i = idx - 1; i <= idx + 1; ++i) {
                    update(i, -1);
                }
                nums[idx] = val;
                for (int i = idx - 1; i <= idx + 1; ++i) {
                    update(i, 1);
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
type BinaryIndexedTree struct {
	n int
	c []int
}

func NewBinaryIndexedTree(n int) *BinaryIndexedTree {
	return &BinaryIndexedTree{n: n, c: make([]int, n+1)}
}

func (bit *BinaryIndexedTree) update(x, delta int) {
	for ; x <= bit.n; x += x & -x {
		bit.c[x] += delta
	}
}

func (bit *BinaryIndexedTree) query(x int) int {
	s := 0
	for ; x > 0; x -= x & -x {
		s += bit.c[x]
	}
	return s
}

func countOfPeaks(nums []int, queries [][]int) (ans []int) {
	n := len(nums)
	tree := NewBinaryIndexedTree(n - 1)
	update := func(i, val int) {
		if i <= 0 || i >= n-1 {
			return
		}
		if nums[i-1] < nums[i] && nums[i] > nums[i+1] {
			tree.update(i, val)
		}
	}
	for i := 1; i < n-1; i++ {
		update(i, 1)
	}
	for _, q := range queries {
		if q[0] == 1 {
			l, r := q[1]+1, q[2]-1
			t := 0
			if l <= r {
				t = tree.query(r) - tree.query(l-1)
			}
			ans = append(ans, t)
		} else {
			idx, val := q[1], q[2]
			for i := idx - 1; i <= idx+1; i++ {
				update(i, -1)
			}
			nums[idx] = val
			for i := idx - 1; i <= idx+1; i++ {
				update(i, 1)
			}
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class BinaryIndexedTree {
    private n: number;
    private c: number[];

    constructor(n: number) {
        this.n = n;
        this.c = Array(n + 1).fill(0);
    }

    update(x: number, delta: number): void {
        for (; x <= this.n; x += x & -x) {
            this.c[x] += delta;
        }
    }

    query(x: number): number {
        let s = 0;
        for (; x > 0; x -= x & -x) {
            s += this.c[x];
        }
        return s;
    }
}

function countOfPeaks(nums: number[], queries: number[][]): number[] {
    const n = nums.length;
    const tree = new BinaryIndexedTree(n - 1);
    const update = (i: number, val: number): void => {
        if (i <= 0 || i >= n - 1) {
            return;
        }
        if (nums[i - 1] < nums[i] && nums[i] > nums[i + 1]) {
            tree.update(i, val);
        }
    };
    for (let i = 1; i < n - 1; ++i) {
        update(i, 1);
    }
    const ans: number[] = [];
    for (const q of queries) {
        if (q[0] === 1) {
            const [l, r] = [q[1] + 1, q[2] - 1];
            ans.push(l > r ? 0 : tree.query(r) - tree.query(l - 1));
        } else {
            const [idx, val] = [q[1], q[2]];
            for (let i = idx - 1; i <= idx + 1; ++i) {
                update(i, -1);
            }
            nums[idx] = val;
            for (let i = idx - 1; i <= idx + 1; ++i) {
                update(i, 1);
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

<p>数组 <code>arr</code>&nbsp;中&nbsp;<strong>大于</strong>&nbsp;前面和后面相邻元素的元素被称为 <strong>峰值</strong>&nbsp;元素。</p>

<p>给你一个整数数组&nbsp;<code>nums</code>&nbsp;和一个二维整数数组&nbsp;<code>queries</code>&nbsp;。</p>

<p>你需要处理以下两种类型的操作：</p>

<ul>
	<li><code>queries[i] = [1, l<sub>i</sub>, r<sub>i</sub>]</code>&nbsp;，求出子数组&nbsp;<code>nums[l<sub>i</sub>..r<sub>i</sub>]</code>&nbsp;中&nbsp;<strong>峰值</strong>&nbsp;元素的数目。<!-- notionvc: 73b20b7c-e1ab-4dac-86d0-13761094a9ae --></li>
	<li><code>queries[i] = [2, index<sub>i</sub>, val<sub>i</sub>]</code>&nbsp;，将&nbsp;<code>nums[index<sub>i</sub>]</code>&nbsp;变为&nbsp;<code><font face="monospace">val<sub>i</sub></font></code><font face="monospace">&nbsp;。</font></li>
</ul>

<p>请你返回一个数组&nbsp;<code>answer</code>&nbsp;，它依次包含每一个第一种操作的答案。<!-- notionvc: a9ccef22-4061-4b5a-b4cc-a2b2a0e12f30 --></p>

<p><strong>注意：</strong></p>

<ul>
	<li>子数组中 <strong>第一个</strong>&nbsp;和 <strong>最后一个</strong>&nbsp;元素都 <strong>不是</strong>&nbsp;峰值元素。</li>
</ul>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [3,1,4,2,5], queries = [[2,3,4],[1,0,4]]</span></p>

<p><span class="example-io"><b>输出：</b>[0]</span></p>

<p><strong>解释：</strong></p>

<p>第一个操作：我们将&nbsp;<code>nums[3]</code>&nbsp;变为&nbsp;4 ，<code>nums</code>&nbsp;变为&nbsp;<code>[3,1,4,4,5]</code>&nbsp;。</p>

<p>第二个操作：<code>[3,1,4,4,5]</code>&nbsp;中峰值元素的数目为 0 。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [4,1,4,2,1,5], queries = [[2,2,4],[1,0,2],[1,0,4]]</span></p>

<p><span class="example-io"><b>输出：</b>[0,1]</span></p>

<p><strong>解释：</strong></p>

<p>第一个操作：<code>nums[2]</code>&nbsp;变为 4 ，它已经是 4 了，所以保持不变。</p>

<p>第二个操作：<code>[4,1,4]</code>&nbsp;中峰值元素的数目为 0 。</p>

<p>第三个操作：第二个 4 是&nbsp;<code>[4,1,4,2,1]</code>&nbsp;中的峰值元素。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= queries.length &lt;= 10<sup>5</sup></code></li>
	<li><code>queries[i][0] == 1</code>&nbsp;或者&nbsp;<code>queries[i][0] == 2</code></li>
	<li>对于所有的 <code>i</code>&nbsp;，都有：
	<ul>
		<li><code>queries[i][0] == 1</code>&nbsp;：<code>0 &lt;= queries[i][1] &lt;= queries[i][2] &lt;= nums.length - 1</code></li>
		<li><code>queries[i][0] == 2</code> ：<code>0 &lt;= queries[i][1] &lt;= nums.length - 1</code>, <code>1 &lt;= queries[i][2] &lt;= 10<sup>5</sup></code></li>
	</ul>
	</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：树状数组

根据题目描述，对于 $0 < i < n - 1$，如果满足 $nums[i - 1] < nums[i]$ 且 $nums[i] > nums[i + 1]$，我们可以将 $nums[i]$ 视为 $1$，否则视为 $0$。这样，对于操作 $1$，即查询子数组 $nums[l..r]$ 中的峰值元素个数，相当于查询区间 $[l + 1, r - 1]$ 中 $1$ 的个数。我们可以使用树状数组来维护区间 $[1, n - 1]$ 中 $1$ 的个数。

而对于操作 $1$，即把 $nums[idx]$ 更新为 $val$，只会影响到 $idx - 1$, $idx$, $idx + 1$ 这三个位置的值，因此我们只需要更新这三个位置即可。具体地，我们可以先把这三个位置的峰值元素去掉，然后更新 $nums[idx]$ 的值，最后再把这三个位置的峰值元素加回来。

时间复杂度 $O((n + q) \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 和 $q$ 分别是数组 `nums` 的长度和查询数组 `queries` 的长度。

<!-- tabs:start -->

#### Python3

```python
class BinaryIndexedTree:
    __slots__ = "n", "c"

    def __init__(self, n: int):
        self.n = n
        self.c = [0] * (n + 1)

    def update(self, x: int, delta: int) -> None:
        while x <= self.n:
            self.c[x] += delta
            x += x & -x

    def query(self, x: int) -> int:
        s = 0
        while x:
            s += self.c[x]
            x -= x & -x
        return s


class Solution:
    def countOfPeaks(self, nums: List[int], queries: List[List[int]]) -> List[int]:
        def update(i: int, val: int):
            if i <= 0 or i >= n - 1:
                return
            if nums[i - 1] < nums[i] and nums[i] > nums[i + 1]:
                tree.update(i, val)

        n = len(nums)
        tree = BinaryIndexedTree(n - 1)
        for i in range(1, n - 1):
            update(i, 1)
        ans = []
        for q in queries:
            if q[0] == 1:
                l, r = q[1] + 1, q[2] - 1
                ans.append(0 if l > r else tree.query(r) - tree.query(l - 1))
            else:
                idx, val = q[1:]
                for i in range(idx - 1, idx + 2):
                    update(i, -1)
                nums[idx] = val
                for i in range(idx - 1, idx + 2):
                    update(i, 1)
        return ans
```

#### Java

```java
class BinaryIndexedTree {
    private int n;
    private int[] c;

    public BinaryIndexedTree(int n) {
        this.n = n;
        this.c = new int[n + 1];
    }

    public void update(int x, int delta) {
        for (; x <= n; x += x & -x) {
            c[x] += delta;
        }
    }

    public int query(int x) {
        int s = 0;
        for (; x > 0; x -= x & -x) {
            s += c[x];
        }
        return s;
    }
}

class Solution {
    private BinaryIndexedTree tree;
    private int[] nums;

    public List<Integer> countOfPeaks(int[] nums, int[][] queries) {
        int n = nums.length;
        this.nums = nums;
        tree = new BinaryIndexedTree(n - 1);
        for (int i = 1; i < n - 1; ++i) {
            update(i, 1);
        }
        List<Integer> ans = new ArrayList<>();
        for (var q : queries) {
            if (q[0] == 1) {
                int l = q[1] + 1, r = q[2] - 1;
                ans.add(l > r ? 0 : tree.query(r) - tree.query(l - 1));
            } else {
                int idx = q[1], val = q[2];
                for (int i = idx - 1; i <= idx + 1; ++i) {
                    update(i, -1);
                }
                nums[idx] = val;
                for (int i = idx - 1; i <= idx + 1; ++i) {
                    update(i, 1);
                }
            }
        }
        return ans;
    }

    private void update(int i, int val) {
        if (i <= 0 || i >= nums.length - 1) {
            return;
        }
        if (nums[i - 1] < nums[i] && nums[i] > nums[i + 1]) {
            tree.update(i, val);
        }
    }
}
```

#### C++

```cpp
class BinaryIndexedTree {
private:
    int n;
    vector<int> c;

public:
    BinaryIndexedTree(int n)
        : n(n)
        , c(n + 1) {}

    void update(int x, int delta) {
        for (; x <= n; x += x & -x) {
            c[x] += delta;
        }
    }

    int query(int x) {
        int s = 0;
        for (; x > 0; x -= x & -x) {
            s += c[x];
        }
        return s;
    }
};

class Solution {
public:
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        BinaryIndexedTree tree(n - 1);
        auto update = [&](int i, int val) {
            if (i <= 0 || i >= n - 1) {
                return;
            }
            if (nums[i - 1] < nums[i] && nums[i] > nums[i + 1]) {
                tree.update(i, val);
            }
        };
        for (int i = 1; i < n - 1; ++i) {
            update(i, 1);
        }
        vector<int> ans;
        for (auto& q : queries) {
            if (q[0] == 1) {
                int l = q[1] + 1, r = q[2] - 1;
                ans.push_back(l > r ? 0 : tree.query(r) - tree.query(l - 1));
            } else {
                int idx = q[1], val = q[2];
                for (int i = idx - 1; i <= idx + 1; ++i) {
                    update(i, -1);
                }
                nums[idx] = val;
                for (int i = idx - 1; i <= idx + 1; ++i) {
                    update(i, 1);
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
type BinaryIndexedTree struct {
	n int
	c []int
}

func NewBinaryIndexedTree(n int) *BinaryIndexedTree {
	return &BinaryIndexedTree{n: n, c: make([]int, n+1)}
}

func (bit *BinaryIndexedTree) update(x, delta int) {
	for ; x <= bit.n; x += x & -x {
		bit.c[x] += delta
	}
}

func (bit *BinaryIndexedTree) query(x int) int {
	s := 0
	for ; x > 0; x -= x & -x {
		s += bit.c[x]
	}
	return s
}

func countOfPeaks(nums []int, queries [][]int) (ans []int) {
	n := len(nums)
	tree := NewBinaryIndexedTree(n - 1)
	update := func(i, val int) {
		if i <= 0 || i >= n-1 {
			return
		}
		if nums[i-1] < nums[i] && nums[i] > nums[i+1] {
			tree.update(i, val)
		}
	}
	for i := 1; i < n-1; i++ {
		update(i, 1)
	}
	for _, q := range queries {
		if q[0] == 1 {
			l, r := q[1]+1, q[2]-1
			t := 0
			if l <= r {
				t = tree.query(r) - tree.query(l-1)
			}
			ans = append(ans, t)
		} else {
			idx, val := q[1], q[2]
			for i := idx - 1; i <= idx+1; i++ {
				update(i, -1)
			}
			nums[idx] = val
			for i := idx - 1; i <= idx+1; i++ {
				update(i, 1)
			}
		}
	}
	return
}
```

#### TypeScript

```ts
class BinaryIndexedTree {
    private n: number;
    private c: number[];

    constructor(n: number) {
        this.n = n;
        this.c = Array(n + 1).fill(0);
    }

    update(x: number, delta: number): void {
        for (; x <= this.n; x += x & -x) {
            this.c[x] += delta;
        }
    }

    query(x: number): number {
        let s = 0;
        for (; x > 0; x -= x & -x) {
            s += this.c[x];
        }
        return s;
    }
}

function countOfPeaks(nums: number[], queries: number[][]): number[] {
    const n = nums.length;
    const tree = new BinaryIndexedTree(n - 1);
    const update = (i: number, val: number): void => {
        if (i <= 0 || i >= n - 1) {
            return;
        }
        if (nums[i - 1] < nums[i] && nums[i] > nums[i + 1]) {
            tree.update(i, val);
        }
    };
    for (let i = 1; i < n - 1; ++i) {
        update(i, 1);
    }
    const ans: number[] = [];
    for (const q of queries) {
        if (q[0] === 1) {
            const [l, r] = [q[1] + 1, q[2] - 1];
            ans.push(l > r ? 0 : tree.query(r) - tree.query(l - 1));
        } else {
            const [idx, val] = [q[1], q[2]];
            for (let i = idx - 1; i <= idx + 1; ++i) {
                update(i, -1);
            }
            nums[idx] = val;
            for (let i = idx - 1; i <= idx + 1; ++i) {
                update(i, 1);
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

# [3188. 查找得分最高的学生 II 🔒](https://leetcode.cn/problems/find-top-scoring-students-ii){#3188}

{{< tabs "3188" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT student_id
        FROM enrollments
        GROUP BY 1
        HAVING AVG(GPA) >= 2.5
    )
SELECT student_id
FROM
    T
    JOIN students USING (student_id)
    JOIN courses USING (major)
    LEFT JOIN enrollments USING (student_id, course_id)
GROUP BY 1
HAVING
    SUM(mandatory = 'yes' AND grade = 'A') = SUM(mandatory = 'yes')
    AND SUM(mandatory = 'no' AND grade IS NOT NULL) = SUM(mandatory = 'no' AND grade IN ('A', 'B'))
    AND SUM(mandatory = 'no' AND grade IS NOT NULL) >= 2
ORDER BY 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code>students</code></p>

<pre>
+-------------+----------+
| Column Name | Type     | 
+-------------+----------+
| student_id  | int      |
| name        | varchar  |
| major       | varchar  |
+-------------+----------+
student_id 是这张表的主键（有不同值的列的组合）。
这张表的每一行包含学生 ID，学生姓名和他们的专业。
</pre>

<p>表：<code>courses</code></p>

<pre>
+-------------+-------------------+
| Column Name | Type              |       
+-------------+-------------------+
| course_id   | int               |    
| name        | varchar           |      
| credits     | int               |           
| major       | varchar           |       
| mandatory   | enum              |      
+-------------+-------------------+
course_id 是这张表的主键。 
mandatory 是 ('Yes', 'No') 的枚举类型。
每一行包含课程 ID，课程名，学分，所属专业，以及该课程是否必修。
</pre>

<p>表：<code>enrollments</code></p>

<pre>
+-------------+----------+
| Column Name | Type     | 
+-------------+----------+
| student_id  | int      |
| course_id   | int      |
| semester    | varchar  |
| grade       | varchar  |
| GPA         | decimal  | 
+-------------+----------+
(student_id, course_id, semester) 是这张表的主键（有不同值的列的组合）。
这张表的每一行包含学生 ID，课程 ID，学期和获得的学分。
</pre>

<p>编写一个解决方案来查找满足下述标准的学生：</p>

<ul>
	<li>已经 <strong>修完他们专业中所有的必修课程</strong> 和 <strong>至少两个&nbsp;</strong>选修课程。</li>
	<li>在 <strong>所有必修课程</strong> 中取得等级 <strong>A</strong> 并且 <strong>选修课程</strong> 至少取得 <strong>B</strong>。</li>
	<li>保持他们所有课程（包括不属于他们专业的）的平均&nbsp;<code>GPA</code>&nbsp;至少在&nbsp;<code>2.5</code>&nbsp;以上。</li>
</ul>

<p>返回结果表以&nbsp;<code>student_id</code> <strong>升序&nbsp;</strong>排序。</p>

<p>&nbsp;</p>

<p><strong class="example">示例：</strong></p>

<div class="example-block">
<p><strong>输入：</strong></p>

<p>students 表：</p>

<pre class="example-io">
 +------------+------------------+------------------+
 | student_id | name             | major            |
 +------------+------------------+------------------+
 | 1          | Alice            | Computer Science |
 | 2          | Bob              | Computer Science |
 | 3          | Charlie          | Mathematics      |
 | 4          | David            | Mathematics      |
 +------------+------------------+------------------+
 </pre>

<p>courses 表：</p>

<pre class="example-io">
 +-----------+-------------------+---------+------------------+----------+
 | course_id | name              | credits | major            | mandatory|
 +-----------+-------------------+---------+------------------+----------+
 | 101       | Algorithms        | 3       | Computer Science | yes      |
 | 102       | Data Structures   | 3       | Computer Science | yes      |
 | 103       | Calculus          | 4       | Mathematics      | yes      |
 | 104       | Linear Algebra    | 4       | Mathematics      | yes      |
 | 105       | Machine Learning  | 3       | Computer Science | no       |
 | 106       | Probability       | 3       | Mathematics      | no       |
 | 107       | Operating Systems | 3       | Computer Science | no       |
 | 108       | Statistics        | 3       | Mathematics      | no       |
 +-----------+-------------------+---------+------------------+----------+
 </pre>

<p>enrollments 表：</p>

<pre class="example-io">
 +------------+-----------+-------------+-------+-----+
 | student_id | course_id | semester    | grade | GPA |
 +------------+-----------+-------------+-------+-----+
 | 1          | 101       | Fall 2023   | A     | 4.0 |
 | 1          | 102       | Spring 2023 | A     | 4.0 |
 | 1          | 105       | Spring 2023 | A     | 4.0 |
 | 1          | 107       | Fall 2023   | B     | 3.5 |
 | 2          | 101       | Fall 2023   | A     | 4.0 |
 | 2          | 102       | Spring 2023 | B     | 3.0 |
 | 3          | 103       | Fall 2023   | A     | 4.0 |
 | 3          | 104       | Spring 2023 | A     | 4.0 |
 | 3          | 106       | Spring 2023 | A     | 4.0 |
 | 3          | 108       | Fall 2023   | B     | 3.5 |
 | 4          | 103       | Fall 2023   | B     | 3.0 |
 | 4          | 104       | Spring 2023 | B     | 3.0 |
 +------------+-----------+-------------+-------+-----+
 </pre>

<p><strong>输出：</strong></p>

<pre class="example-io">
 +------------+
 | student_id |
 +------------+
 | 1          |
 | 3          |
 +------------+
 </pre>

<p><strong>解释：</strong></p>

<ul>
	<li>Alice (student_id 1) 是计算机科学专业并且修了&nbsp;Algorithms&nbsp;和 Data Structures，都取得了 A。她同时选修了&nbsp;Machine Learning&nbsp;和 Operating Systems，分别取得了 A 和 B。</li>
	<li>Bob (student_id 2) 是计算机科学专业但没有在所有需求的课程中取得 A。</li>
	<li>Charlie (student_id 3) 是数学专业并且修了 Calculus&nbsp;和 Linear Algebra，都取得了 A。他同时选修了&nbsp;Probability&nbsp;和 Statistics，分别取得了 A 和 B。</li>
	<li>David (student_id 4) 是数学专业但没有在所有需要的课程中取得 A。</li>
</ul>

<p><strong>注意：</strong>输出表以 student_id 升序排序。</p>
</div>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：连接 + 分组 + 条件过滤

我们首先筛选出平均 GPA 大于等于 2.5 的学生，记录在 `T` 表中。

然后，我们将 `T` 表与 `students` 表按照 `student_id` 进行连接，然后与 `courses` 表按照 `major` 进行连接，再与 `enrollments` 表按照 `student_id` 和 `course_id` 进行左连接。

接下来，我们按照学生 ID 进行分组，然后使用 `HAVING` 子句过滤出符合条件的学生，最后按照学生 ID 进行排序。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT student_id
        FROM enrollments
        GROUP BY 1
        HAVING AVG(GPA) >= 2.5
    )
SELECT student_id
FROM
    T
    JOIN students USING (student_id)
    JOIN courses USING (major)
    LEFT JOIN enrollments USING (student_id, course_id)
GROUP BY 1
HAVING
    SUM(mandatory = 'yes' AND grade = 'A') = SUM(mandatory = 'yes')
    AND SUM(mandatory = 'no' AND grade IS NOT NULL) = SUM(mandatory = 'no' AND grade IN ('A', 'B'))
    AND SUM(mandatory = 'no' AND grade IS NOT NULL) >= 2
ORDER BY 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3189. 得到一个和平棋盘的最少步骤 🔒](https://leetcode.cn/problems/minimum-moves-to-get-a-peaceful-board){#3189}

{{< tabs "3189" >}}

{{% tab "python" %}}
```python
class Solution:
    def minMoves(self, rooks: List[List[int]]) -> int:
        rooks.sort()
        ans = sum(abs(x - i) for i, (x, _) in enumerate(rooks))
        rooks.sort(key=lambda x: x[1])
        ans += sum(abs(y - j) for j, (_, y) in enumerate(rooks))
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minMoves(int[][] rooks) {
        Arrays.sort(rooks, (a, b) -> a[0] - b[0]);
        int ans = 0;
        int n = rooks.length;
        for (int i = 0; i < n; ++i) {
            ans += Math.abs(rooks[i][0] - i);
        }
        Arrays.sort(rooks, (a, b) -> a[1] - b[1]);
        for (int j = 0; j < n; ++j) {
            ans += Math.abs(rooks[j][1] - j);
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
    int minMoves(vector<vector<int>>& rooks) {
        sort(rooks.begin(), rooks.end());
        int ans = 0;
        int n = rooks.size();
        for (int i = 0; i < n; ++i) {
            ans += abs(rooks[i][0] - i);
        }
        sort(rooks.begin(), rooks.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        for (int j = 0; j < n; ++j) {
            ans += abs(rooks[j][1] - j);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minMoves(rooks [][]int) (ans int) {
	sort.Slice(rooks, func(i, j int) bool { return rooks[i][0] < rooks[j][0] })
	for i, row := range rooks {
		ans += int(math.Abs(float64(row[0] - i)))
	}
	sort.Slice(rooks, func(i, j int) bool { return rooks[i][1] < rooks[j][1] })
	for j, col := range rooks {
		ans += int(math.Abs(float64(col[1] - j)))
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minMoves(rooks: number[][]): number {
    rooks.sort((a, b) => a[0] - b[0]);
    let ans = rooks.reduce((sum, rook, i) => sum + Math.abs(rook[0] - i), 0);
    rooks.sort((a, b) => a[1] - b[1]);
    ans += rooks.reduce((sum, rook, j) => sum + Math.abs(rook[1] - j), 0);
    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个长度为&nbsp;<code>n</code>&nbsp;的二维数组&nbsp;<code>rooks</code>，其中&nbsp;<code>rooks[i] = [x<sub>i</sub>, y<sub>i</sub>]</code>&nbsp;表示 <code>n x n</code>&nbsp;棋盘上一个车的位置。你的任务是每次在垂直或水平方向上移动&nbsp;<strong>1 格</strong>&nbsp;车（到一个相邻的格子）使得棋盘变得&nbsp;<strong>和平</strong>。</p>

<p>如果每行每列都 <strong>只有</strong> 一个车，那么这块棋盘就是和平的。</p>

<p>返回获得和平棋盘所需的 <strong>最少</strong> 步数。</p>

<p><strong>注意 任何时刻&nbsp;</strong>两个车都不能在同一个格子。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">rooks = [[0,0],[1,0],[1,1]]</span></p>

<p><span class="example-io"><b>输出：</b>3</span></p>

<p><strong>解释：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3100-3199/3189.Minimum%20Moves%20to%20Get%20a%20Peaceful%20Board/images/1719285456-CnJqJS-ex1-edited.gif" style="width: 200px; height: 200px;" /></div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">rooks = [[0,0],[0,1],[0,2],[0,3]]</span></p>

<p><span class="example-io"><b>输出：</b></span><span class="example-io">6</span></p>

<p><strong>解释：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3100-3199/3189.Minimum%20Moves%20to%20Get%20a%20Peaceful%20Board/images/1719285456-wtGRzv-ex2-edited.gif" style="width: 200px; height: 200px;" /></div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n == rooks.length &lt;= 500</code></li>
	<li><code>0 &lt;= x<sub>i</sub>, y<sub>i</sub> &lt;= n - 1</code></li>
	<li>输入保证没有两个车在相同的格子。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心

我们可以将所有的车按照横坐标排序，然后将车按顺序分配给每一行，计算每个车到目标位置的距离之和。然后将所有的车按照纵坐标排序，按照同样的方法计算每个车到目标位置的距离之和。最后将两个距离之和相加即为答案。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 为车的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minMoves(self, rooks: List[List[int]]) -> int:
        rooks.sort()
        ans = sum(abs(x - i) for i, (x, _) in enumerate(rooks))
        rooks.sort(key=lambda x: x[1])
        ans += sum(abs(y - j) for j, (_, y) in enumerate(rooks))
        return ans
```

#### Java

```java
class Solution {
    public int minMoves(int[][] rooks) {
        Arrays.sort(rooks, (a, b) -> a[0] - b[0]);
        int ans = 0;
        int n = rooks.length;
        for (int i = 0; i < n; ++i) {
            ans += Math.abs(rooks[i][0] - i);
        }
        Arrays.sort(rooks, (a, b) -> a[1] - b[1]);
        for (int j = 0; j < n; ++j) {
            ans += Math.abs(rooks[j][1] - j);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minMoves(vector<vector<int>>& rooks) {
        sort(rooks.begin(), rooks.end());
        int ans = 0;
        int n = rooks.size();
        for (int i = 0; i < n; ++i) {
            ans += abs(rooks[i][0] - i);
        }
        sort(rooks.begin(), rooks.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        for (int j = 0; j < n; ++j) {
            ans += abs(rooks[j][1] - j);
        }
        return ans;
    }
};
```

#### Go

```go
func minMoves(rooks [][]int) (ans int) {
	sort.Slice(rooks, func(i, j int) bool { return rooks[i][0] < rooks[j][0] })
	for i, row := range rooks {
		ans += int(math.Abs(float64(row[0] - i)))
	}
	sort.Slice(rooks, func(i, j int) bool { return rooks[i][1] < rooks[j][1] })
	for j, col := range rooks {
		ans += int(math.Abs(float64(col[1] - j)))
	}
	return
}
```

#### TypeScript

```ts
function minMoves(rooks: number[][]): number {
    rooks.sort((a, b) => a[0] - b[0]);
    let ans = rooks.reduce((sum, rook, i) => sum + Math.abs(rook[0] - i), 0);
    rooks.sort((a, b) => a[1] - b[1]);
    ans += rooks.reduce((sum, rook, j) => sum + Math.abs(rook[1] - j), 0);
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
