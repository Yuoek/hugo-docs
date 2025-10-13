---
title: "2410_运动员和训练师的最大匹配数"
date: 2025-10-08T18:39:18+08:00
weight: 2
tags: [二分查找, 二叉树, 位运算, 双指针, 哈希表, 字典树, 字符串, 广度优先搜索, 排序, 数学, 数组, 数论, 枚举, 树, 深度优先搜索, 滑动窗口, 脑筋急转弯, 计数, 贪心]
---

{{< markmap >}}
### [2410_运动员和训练师的最大匹配数](#2410)
#### [贪心](#2410)
#### [数组](#2410)
#### [双指针](#2410)
#### [排序](#2410)
### [2411_按位或最大的最小子数组长度](#2411)
#### [位运算](#2411)
#### [数组](#2411)
#### [二分查找](#2411)
#### [滑动窗口](#2411)
### [2412_完成所有交易的初始最少钱数](#2412)
#### [贪心](#2412)
#### [数组](#2412)
#### [排序](#2412)
### [2413_最小偶倍数](#2413)
#### [数学](#2413)
#### [数论](#2413)
### [2414_最长的字母序连续子字符串的长度](#2414)
#### [字符串](#2414)
### [2415_反转二叉树的奇数层](#2415)
#### [树](#2415)
#### [深度优先搜索](#2415)
#### [广度优先搜索](#2415)
#### [二叉树](#2415)
### [2416_字符串的前缀分数和](#2416)
#### [字典树](#2416)
#### [数组](#2416)
#### [字符串](#2416)
#### [计数](#2416)
### [2417_最近的公平整数 🔒](#2417)
#### [数学](#2417)
#### [枚举](#2417)
### [2418_按身高排序](#2418)
#### [数组](#2418)
#### [哈希表](#2418)
#### [字符串](#2418)
#### [排序](#2418)
### [2419_按位与最大的最长子数组](#2419)
#### [位运算](#2419)
#### [脑筋急转弯](#2419)
#### [数组](#2419)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2410_运动员和训练师的最大匹配数
___
#### 贪心
___
#### 数组
___
#### 双指针
___
#### 排序
---
### 2411_按位或最大的最小子数组长度
___
#### 位运算
___
#### 数组
___
#### 二分查找
___
#### 滑动窗口
---
### 2412_完成所有交易的初始最少钱数
___
#### 贪心
___
#### 数组
___
#### 排序
---
### 2413_最小偶倍数
___
#### 数学
___
#### 数论
---
### 2414_最长的字母序连续子字符串的长度
___
#### 字符串
---
### 2415_反转二叉树的奇数层
___
#### 树
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 二叉树
---
### 2416_字符串的前缀分数和
___
#### 字典树
___
#### 数组
___
#### 字符串
___
#### 计数
---
### 2417_最近的公平整数 🔒
___
#### 数学
___
#### 枚举
---
### 2418_按身高排序
___
#### 数组
___
#### 哈希表
___
#### 字符串
___
#### 排序
---
### 2419_按位与最大的最长子数组
___
#### 位运算
___
#### 脑筋急转弯
___
#### 数组
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 二叉树 | 位运算 |
| 双指针 | 哈希表 | 字典树 |
| 字符串 | 广度优先搜索 | 排序 |
| 数学 | 数组 | 数论 |
| 枚举 | 树 | 深度优先搜索 |
| 滑动窗口 | 脑筋急转弯 | 计数 |
| 贪心 |  |  |

# [2410. 运动员和训练师的最大匹配数](https://leetcode.cn/problems/maximum-matching-of-players-with-trainers){#2410}

{{< tabs "2410" >}}

{{% tab "python" %}}
```python
class Solution:
    def matchPlayersAndTrainers(self, players: List[int], trainers: List[int]) -> int:
        players.sort()
        trainers.sort()
        j, n = 0, len(trainers)
        for i, p in enumerate(players):
            while j < n and trainers[j] < p:
                j += 1
            if j == n:
                return i
            j += 1
        return len(players)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int matchPlayersAndTrainers(int[] players, int[] trainers) {
        Arrays.sort(players);
        Arrays.sort(trainers);
        int m = players.length, n = trainers.length;
        for (int i = 0, j = 0; i < m; ++i, ++j) {
            while (j < n && trainers[j] < players[i]) {
                ++j;
            }
            if (j == n) {
                return i;
            }
        }
        return m;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        ranges::sort(players);
        ranges::sort(trainers);
        int m = players.size(), n = trainers.size();
        for (int i = 0, j = 0; i < m; ++i, ++j) {
            while (j < n && trainers[j] < players[i]) {
                ++j;
            }
            if (j == n) {
                return i;
            }
        }
        return m;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func matchPlayersAndTrainers(players []int, trainers []int) int {
	sort.Ints(players)
	sort.Ints(trainers)
	m, n := len(players), len(trainers)
	for i, j := 0, 0; i < m; i, j = i+1, j+1 {
		for j < n && trainers[j] < players[i] {
			j++
		}
		if j == n {
			return i
		}
	}
	return m
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function matchPlayersAndTrainers(players: number[], trainers: number[]): number {
    players.sort((a, b) => a - b);
    trainers.sort((a, b) => a - b);
    const [m, n] = [players.length, trainers.length];
    for (let i = 0, j = 0; i < m; ++i, ++j) {
        while (j < n && trainers[j] < players[i]) {
            ++j;
        }
        if (j === n) {
            return i;
        }
    }
    return m;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn match_players_and_trainers(mut players: Vec<i32>, mut trainers: Vec<i32>) -> i32 {
        players.sort();
        trainers.sort();
        let mut j = 0;
        let n = trainers.len();
        for (i, &p) in players.iter().enumerate() {
            while j < n && trainers[j] < p {
                j += 1;
            }
            if j == n {
                return i as i32;
            }
            j += 1;
        }
        players.len() as i32
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>players</code>&nbsp;，其中&nbsp;<code>players[i]</code>&nbsp;表示第 <code>i</code>&nbsp;名运动员的 <strong>能力</strong>&nbsp;值，同时给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>trainers</code>&nbsp;，其中&nbsp;<code>trainers[j]</code>&nbsp;表示第 <code>j</code>&nbsp;名训练师的 <strong>训练能力值</strong>&nbsp;。</p>

<p>如果第 <code>i</code>&nbsp;名运动员的能力值 <strong>小于等于</strong>&nbsp;第 <code>j</code>&nbsp;名训练师的能力值，那么第&nbsp;<code>i</code>&nbsp;名运动员可以 <strong>匹配</strong>&nbsp;第&nbsp;<code>j</code>&nbsp;名训练师。除此以外，每名运动员至多可以匹配一位训练师，每位训练师最多可以匹配一位运动员。</p>

<p>请你返回满足上述要求&nbsp;<code>players</code>&nbsp;和 <code>trainers</code>&nbsp;的 <strong>最大</strong> 匹配数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>players = [4,7,9], trainers = [8,2,5,8]
<b>输出：</b>2
<b>解释：</b>
得到两个匹配的一种方案是：
- players[0] 与 trainers[0] 匹配，因为 4 &lt;= 8 。
- players[1] 与 trainers[3] 匹配，因为 7 &lt;= 8 。
可以证明 2 是可以形成的最大匹配数。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>players = [1,1,1], trainers = [10]
<b>输出：</b>1
<b>解释：</b>
训练师可以匹配所有 3 个运动员
每个运动员至多只能匹配一个训练师，所以最大答案是 1 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= players.length, trainers.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= players[i], trainers[j] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 双指针

根据题目描述，每位运动员应该尽可能匹配能力值最接近的训练师，因此我们可以对运动员和训练师的能力值进行排序，然后使用双指针的方法进行匹配。

我们用两个指针 $i$ 和 $j$ 分别指向运动员和训练师的数组，初始时都指向数组的起始位置。然后我们逐个遍历运动员的能力值，如果当前训练师的能力值小于当前运动员的能力值，我们就将训练师的指针向右移动一位，直到找到一个能力值大于等于当前运动员的训练师。如果找不到这样的训练师，说明当前运动员无法匹配任何训练师，此时我们返回当前运动员的下标即可。否则，，我们可以将当前运动员和训练师匹配，然后将两个指针都向右移动一位。继续这个过程直到遍历完所有的运动员。

如果我们遍历完所有的运动员，说明所有的运动员都能匹配到训练师，此时我们返回运动员的数量即可。

时间复杂度 $O(m \times \log m + n \times \log n)$，空间复杂度 $O(\max(\log m, \log n))$。其中 $m$ 和 $n$ 分别为运动员和训练师的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def matchPlayersAndTrainers(self, players: List[int], trainers: List[int]) -> int:
        players.sort()
        trainers.sort()
        j, n = 0, len(trainers)
        for i, p in enumerate(players):
            while j < n and trainers[j] < p:
                j += 1
            if j == n:
                return i
            j += 1
        return len(players)
```

#### Java

```java
class Solution {
    public int matchPlayersAndTrainers(int[] players, int[] trainers) {
        Arrays.sort(players);
        Arrays.sort(trainers);
        int m = players.length, n = trainers.length;
        for (int i = 0, j = 0; i < m; ++i, ++j) {
            while (j < n && trainers[j] < players[i]) {
                ++j;
            }
            if (j == n) {
                return i;
            }
        }
        return m;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        ranges::sort(players);
        ranges::sort(trainers);
        int m = players.size(), n = trainers.size();
        for (int i = 0, j = 0; i < m; ++i, ++j) {
            while (j < n && trainers[j] < players[i]) {
                ++j;
            }
            if (j == n) {
                return i;
            }
        }
        return m;
    }
};
```

#### Go

```go
func matchPlayersAndTrainers(players []int, trainers []int) int {
	sort.Ints(players)
	sort.Ints(trainers)
	m, n := len(players), len(trainers)
	for i, j := 0, 0; i < m; i, j = i+1, j+1 {
		for j < n && trainers[j] < players[i] {
			j++
		}
		if j == n {
			return i
		}
	}
	return m
}
```

#### TypeScript

```ts
function matchPlayersAndTrainers(players: number[], trainers: number[]): number {
    players.sort((a, b) => a - b);
    trainers.sort((a, b) => a - b);
    const [m, n] = [players.length, trainers.length];
    for (let i = 0, j = 0; i < m; ++i, ++j) {
        while (j < n && trainers[j] < players[i]) {
            ++j;
        }
        if (j === n) {
            return i;
        }
    }
    return m;
}
```

#### Rust

```rust
impl Solution {
    pub fn match_players_and_trainers(mut players: Vec<i32>, mut trainers: Vec<i32>) -> i32 {
        players.sort();
        trainers.sort();
        let mut j = 0;
        let n = trainers.len();
        for (i, &p) in players.iter().enumerate() {
            while j < n && trainers[j] < p {
                j += 1;
            }
            if j == n {
                return i as i32;
            }
            j += 1;
        }
        players.len() as i32
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2411. 按位或最大的最小子数组长度](https://leetcode.cn/problems/smallest-subarrays-with-maximum-bitwise-or){#2411}

{{< tabs "2411" >}}

{{% tab "python" %}}
```python
class Solution:
    def smallestSubarrays(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ans = [1] * n
        f = [-1] * 32
        for i in range(n - 1, -1, -1):
            t = 1
            for j in range(32):
                if (nums[i] >> j) & 1:
                    f[j] = i
                elif f[j] != -1:
                    t = max(t, f[j] - i + 1)
            ans[i] = t
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] smallestSubarrays(int[] nums) {
        int n = nums.length;
        int[] ans = new int[n];
        int[] f = new int[32];
        Arrays.fill(f, -1);
        for (int i = n - 1; i >= 0; --i) {
            int t = 1;
            for (int j = 0; j < 32; ++j) {
                if (((nums[i] >> j) & 1) == 1) {
                    f[j] = i;
                } else if (f[j] != -1) {
                    t = Math.max(t, f[j] - i + 1);
                }
            }
            ans[i] = t;
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
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(32, -1);
        vector<int> ans(n);
        for (int i = n - 1; ~i; --i) {
            int t = 1;
            for (int j = 0; j < 32; ++j) {
                if ((nums[i] >> j) & 1) {
                    f[j] = i;
                } else if (f[j] != -1) {
                    t = max(t, f[j] - i + 1);
                }
            }
            ans[i] = t;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func smallestSubarrays(nums []int) []int {
	n := len(nums)
	f := make([]int, 32)
	for i := range f {
		f[i] = -1
	}
	ans := make([]int, n)
	for i := n - 1; i >= 0; i-- {
		t := 1
		for j := 0; j < 32; j++ {
			if ((nums[i] >> j) & 1) == 1 {
				f[j] = i
			} else if f[j] != -1 {
				t = max(t, f[j]-i+1)
			}
		}
		ans[i] = t
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function smallestSubarrays(nums: number[]): number[] {
    const n = nums.length;
    const ans: number[] = Array(n).fill(1);
    const f: number[] = Array(32).fill(-1);

    for (let i = n - 1; i >= 0; i--) {
        let t = 1;
        for (let j = 0; j < 32; j++) {
            if ((nums[i] >> j) & 1) {
                f[j] = i;
            } else if (f[j] !== -1) {
                t = Math.max(t, f[j] - i + 1);
            }
        }
        ans[i] = t;
    }

    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn smallest_subarrays(nums: Vec<i32>) -> Vec<i32> {
        let n = nums.len();
        let mut ans = vec![1; n];
        let mut f = vec![-1; 32];

        for i in (0..n).rev() {
            let mut t = 1;
            for j in 0..32 {
                if (nums[i] >> j) & 1 != 0 {
                    f[j] = i as i32;
                } else if f[j] != -1 {
                    t = t.max(f[j] - i as i32 + 1);
                }
            }
            ans[i] = t;
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

<p>给你一个长度为 <code>n</code>&nbsp;下标从 <strong>0</strong>&nbsp;开始的数组&nbsp;<code>nums</code>&nbsp;，数组中所有数字均为非负整数。对于&nbsp;<code>0</code>&nbsp;到&nbsp;<code>n - 1</code>&nbsp;之间的每一个下标 <code>i</code>&nbsp;，你需要找出&nbsp;<code>nums</code>&nbsp;中一个 <strong>最小</strong> 非空子数组，它的起始位置为&nbsp;<code>i</code>&nbsp;（包含这个位置），同时有&nbsp;<strong>最大</strong>&nbsp;的 <strong>按位或</strong><b>运算值</b>&nbsp;。</p>

<ul>
	<li>换言之，令&nbsp;<code>B<sub>ij</sub></code>&nbsp;表示子数组&nbsp;<code>nums[i...j]</code>&nbsp;的按位或运算的结果，你需要找到一个起始位置为&nbsp;<code>i</code>&nbsp;的最小子数组，这个子数组的按位或运算的结果等于&nbsp;<code>max(B<sub>ik</sub>)</code>&nbsp;，其中&nbsp;<code>i &lt;= k &lt;= n - 1</code>&nbsp;。</li>
</ul>

<p>一个数组的按位或运算值是这个数组里所有数字按位或运算的结果。</p>

<p>请你返回一个大小为 <code>n</code>&nbsp;的整数数组<em>&nbsp;</em><code>answer</code>，其中<em>&nbsp;</em><code>answer[i]</code>是开始位置为&nbsp;<code>i</code>&nbsp;，按位或运算结果最大，且&nbsp;<strong>最短</strong>&nbsp;子数组的长度。</p>

<p><strong>子数组</strong>&nbsp;是数组里一段连续非空元素组成的序列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [1,0,2,1,3]
<b>输出：</b>[3,3,2,2,1]
<strong>解释：</strong>
任何位置开始，最大按位或运算的结果都是 3 。
- 下标 0 处，能得到结果 3 的最短子数组是 [1,0,2] 。
- 下标 1 处，能得到结果 3 的最短子数组是 [0,2,1] 。
- 下标 2 处，能得到结果 3 的最短子数组是 [2,1] 。
- 下标 3 处，能得到结果 3 的最短子数组是 [1,3] 。
- 下标 4 处，能得到结果 3 的最短子数组是 [3] 。
所以我们返回 [3,3,2,2,1] 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [1,2]
<b>输出：</b>[2,1]
<strong>解释：
</strong>下标 0 处，能得到最大按位或运算值的最短子数组长度为 2 。
下标 1 处，能得到最大按位或运算值的最短子数组长度为 1 。
所以我们返回 [2,1] 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：逆序遍历

要找到每个以 $i$ 作为起始位置的最短子数组，满足或运算结果最大，那么必须让这个结果的 $1$ 尽可能多。

我们用一个 $32$ 位大小的数组$f$ 来记录每一位 $1$ 最早出现的位置。

逆序遍历数组 $nums[i]$，对于 $nums[i]$ 数字中的第 $j$ 位，如果为 $1$，那么 $f[j]$ 就是 $i$。否则如果 $f[j]$ 不为 $-1$，说明右侧找到了满足第 $j$ 位为 $1$ 的数字，更新长度。

时间复杂度 $O(n \times \log m)$。其中 $n$ 为数组 $nums$ 的长度，而 $m$ 为数组 $nums$ 中的最大值。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def smallestSubarrays(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ans = [1] * n
        f = [-1] * 32
        for i in range(n - 1, -1, -1):
            t = 1
            for j in range(32):
                if (nums[i] >> j) & 1:
                    f[j] = i
                elif f[j] != -1:
                    t = max(t, f[j] - i + 1)
            ans[i] = t
        return ans
```

#### Java

```java
class Solution {
    public int[] smallestSubarrays(int[] nums) {
        int n = nums.length;
        int[] ans = new int[n];
        int[] f = new int[32];
        Arrays.fill(f, -1);
        for (int i = n - 1; i >= 0; --i) {
            int t = 1;
            for (int j = 0; j < 32; ++j) {
                if (((nums[i] >> j) & 1) == 1) {
                    f[j] = i;
                } else if (f[j] != -1) {
                    t = Math.max(t, f[j] - i + 1);
                }
            }
            ans[i] = t;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(32, -1);
        vector<int> ans(n);
        for (int i = n - 1; ~i; --i) {
            int t = 1;
            for (int j = 0; j < 32; ++j) {
                if ((nums[i] >> j) & 1) {
                    f[j] = i;
                } else if (f[j] != -1) {
                    t = max(t, f[j] - i + 1);
                }
            }
            ans[i] = t;
        }
        return ans;
    }
};
```

#### Go

```go
func smallestSubarrays(nums []int) []int {
	n := len(nums)
	f := make([]int, 32)
	for i := range f {
		f[i] = -1
	}
	ans := make([]int, n)
	for i := n - 1; i >= 0; i-- {
		t := 1
		for j := 0; j < 32; j++ {
			if ((nums[i] >> j) & 1) == 1 {
				f[j] = i
			} else if f[j] != -1 {
				t = max(t, f[j]-i+1)
			}
		}
		ans[i] = t
	}
	return ans
}
```

#### Typescript

```ts
function smallestSubarrays(nums: number[]): number[] {
    const n = nums.length;
    const ans: number[] = Array(n).fill(1);
    const f: number[] = Array(32).fill(-1);

    for (let i = n - 1; i >= 0; i--) {
        let t = 1;
        for (let j = 0; j < 32; j++) {
            if ((nums[i] >> j) & 1) {
                f[j] = i;
            } else if (f[j] !== -1) {
                t = Math.max(t, f[j] - i + 1);
            }
        }
        ans[i] = t;
    }

    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn smallest_subarrays(nums: Vec<i32>) -> Vec<i32> {
        let n = nums.len();
        let mut ans = vec![1; n];
        let mut f = vec![-1; 32];

        for i in (0..n).rev() {
            let mut t = 1;
            for j in 0..32 {
                if (nums[i] >> j) & 1 != 0 {
                    f[j] = i as i32;
                } else if f[j] != -1 {
                    t = t.max(f[j] - i as i32 + 1);
                }
            }
            ans[i] = t;
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

# [2412. 完成所有交易的初始最少钱数](https://leetcode.cn/problems/minimum-money-required-before-transactions){#2412}

{{< tabs "2412" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumMoney(self, transactions: List[List[int]]) -> int:
        s = sum(max(0, a - b) for a, b in transactions)
        ans = 0
        for a, b in transactions:
            if a > b:
                ans = max(ans, s + b)
            else:
                ans = max(ans, s + a)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long minimumMoney(int[][] transactions) {
        long s = 0;
        for (var e : transactions) {
            s += Math.max(0, e[0] - e[1]);
        }
        long ans = 0;
        for (var e : transactions) {
            if (e[0] > e[1]) {
                ans = Math.max(ans, s + e[1]);
            } else {
                ans = Math.max(ans, s + e[0]);
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
    long long minimumMoney(vector<vector<int>>& transactions) {
        long long s = 0, ans = 0;
        for (auto& e : transactions) {
            s += max(0, e[0] - e[1]);
        }
        for (auto& e : transactions) {
            if (e[0] > e[1]) {
                ans = max(ans, s + e[1]);
            } else {
                ans = max(ans, s + e[0]);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumMoney(transactions [][]int) int64 {
	s, ans := 0, 0
	for _, e := range transactions {
		s += max(0, e[0]-e[1])
	}
	for _, e := range transactions {
		if e[0] > e[1] {
			ans = max(ans, s+e[1])
		} else {
			ans = max(ans, s+e[0])
		}
	}
	return int64(ans)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumMoney(transactions: number[][]): number {
    const s = transactions.reduce((acc, [a, b]) => acc + Math.max(0, a - b), 0);
    let ans = 0;
    for (const [a, b] of transactions) {
        if (a > b) {
            ans = Math.max(ans, s + b);
        } else {
            ans = Math.max(ans, s + a);
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn minimum_money(transactions: Vec<Vec<i32>>) -> i64 {
        let mut s: i64 = 0;
        for transaction in &transactions {
            let (a, b) = (transaction[0], transaction[1]);
            s += (a - b).max(0) as i64;
        }
        let mut ans = 0;
        for transaction in &transactions {
            let (a, b) = (transaction[0], transaction[1]);
            if a > b {
                ans = ans.max(s + b as i64);
            } else {
                ans = ans.max(s + a as i64);
            }
        }
        ans
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[][]} transactions
 * @return {number}
 */
var minimumMoney = function (transactions) {
    const s = transactions.reduce((acc, [a, b]) => acc + Math.max(0, a - b), 0);
    let ans = 0;
    for (const [a, b] of transactions) {
        if (a > b) {
            ans = Math.max(ans, s + b);
        } else {
            ans = Math.max(ans, s + a);
        }
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

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的二维整数数组&nbsp;<code><font face="monospace">transactions</font></code>，其中<code>transactions[i] = [cost<sub>i</sub>, cashback<sub>i</sub>]</code>&nbsp;。</p>

<p>数组描述了若干笔交易。其中每笔交易必须以 <strong>某种顺序</strong> 恰好完成一次。在任意一个时刻，你有一定数目的钱&nbsp;<code>money</code>&nbsp;，为了完成交易&nbsp;<code>i</code>&nbsp;，<code>money &gt;= cost<sub>i</sub></code>&nbsp;这个条件必须为真。执行交易后，你的钱数&nbsp;<code>money</code> 变成&nbsp;<code>money - cost<sub>i</sub> + cashback<sub>i</sub></code><sub>&nbsp;</sub>。</p>

<p>请你返回 <strong>任意一种</strong> 交易顺序下，你都能完成所有交易的最少钱数<em>&nbsp;</em><code>money</code>&nbsp;是多少。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>transactions = [[2,1],[5,0],[4,2]]
<b>输出：</b>10
<strong>解释：
</strong>刚开始 money = 10 ，交易可以以任意顺序进行。
可以证明如果 money &lt; 10 ，那么某些交易无法进行。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>transactions = [[3,0],[0,3]]
<b>输出：</b>3
<strong>解释：</strong>
- 如果交易执行的顺序是 [[3,0],[0,3]] ，完成所有交易需要的最少钱数是 3 。
- 如果交易执行的顺序是 [[0,3],[3,0]] ，完成所有交易需要的最少钱数是 0 。
所以，刚开始钱数为 3 ，任意顺序下交易都可以全部完成。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= transactions.length &lt;= 10<sup>5</sup></code></li>
	<li><code>transactions[i].length == 2</code></li>
	<li><code>0 &lt;= cost<sub>i</sub>, cashback<sub>i</sub> &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心

我们先累计所有负收益，记为 $s$。然后枚举每个交易 $\text{transactions}[i] = [a, b]$ 作为最后一个交易，如果 $a > b$，说明当前的交易是亏钱的，而这个交易在此前我们累计负收益的时候，已经被计算，因此取 $s + b$ 更新答案；否则，取 $s + a$ 更新答案。

时间复杂度 $O(n)$，其中 $n$ 为交易数。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumMoney(self, transactions: List[List[int]]) -> int:
        s = sum(max(0, a - b) for a, b in transactions)
        ans = 0
        for a, b in transactions:
            if a > b:
                ans = max(ans, s + b)
            else:
                ans = max(ans, s + a)
        return ans
```

#### Java

```java
class Solution {
    public long minimumMoney(int[][] transactions) {
        long s = 0;
        for (var e : transactions) {
            s += Math.max(0, e[0] - e[1]);
        }
        long ans = 0;
        for (var e : transactions) {
            if (e[0] > e[1]) {
                ans = Math.max(ans, s + e[1]);
            } else {
                ans = Math.max(ans, s + e[0]);
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
    long long minimumMoney(vector<vector<int>>& transactions) {
        long long s = 0, ans = 0;
        for (auto& e : transactions) {
            s += max(0, e[0] - e[1]);
        }
        for (auto& e : transactions) {
            if (e[0] > e[1]) {
                ans = max(ans, s + e[1]);
            } else {
                ans = max(ans, s + e[0]);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func minimumMoney(transactions [][]int) int64 {
	s, ans := 0, 0
	for _, e := range transactions {
		s += max(0, e[0]-e[1])
	}
	for _, e := range transactions {
		if e[0] > e[1] {
			ans = max(ans, s+e[1])
		} else {
			ans = max(ans, s+e[0])
		}
	}
	return int64(ans)
}
```

#### TypeScript

```ts
function minimumMoney(transactions: number[][]): number {
    const s = transactions.reduce((acc, [a, b]) => acc + Math.max(0, a - b), 0);
    let ans = 0;
    for (const [a, b] of transactions) {
        if (a > b) {
            ans = Math.max(ans, s + b);
        } else {
            ans = Math.max(ans, s + a);
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn minimum_money(transactions: Vec<Vec<i32>>) -> i64 {
        let mut s: i64 = 0;
        for transaction in &transactions {
            let (a, b) = (transaction[0], transaction[1]);
            s += (a - b).max(0) as i64;
        }
        let mut ans = 0;
        for transaction in &transactions {
            let (a, b) = (transaction[0], transaction[1]);
            if a > b {
                ans = ans.max(s + b as i64);
            } else {
                ans = ans.max(s + a as i64);
            }
        }
        ans
    }
}
```

#### JavaScript

```js
/**
 * @param {number[][]} transactions
 * @return {number}
 */
var minimumMoney = function (transactions) {
    const s = transactions.reduce((acc, [a, b]) => acc + Math.max(0, a - b), 0);
    let ans = 0;
    for (const [a, b] of transactions) {
        if (a > b) {
            ans = Math.max(ans, s + b);
        } else {
            ans = Math.max(ans, s + a);
        }
    }
    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2413. 最小偶倍数](https://leetcode.cn/problems/smallest-even-multiple){#2413}

{{< tabs "2413" >}}

{{% tab "python" %}}
```python
class Solution:
    def smallestEvenMultiple(self, n: int) -> int:
        return n if n % 2 == 0 else n * 2
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int smallestEvenMultiple(int n) {
        return n % 2 == 0 ? n : n * 2;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int smallestEvenMultiple(int n) {
        return n % 2 == 0 ? n : n * 2;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func smallestEvenMultiple(n int) int {
	if n%2 == 0 {
		return n
	}
	return n * 2
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function smallestEvenMultiple(n: number): number {
    return n % 2 === 0 ? n : n * 2;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn smallest_even_multiple(n: i32) -> i32 {
        if n % 2 == 0 {
            return n;
        }
        n * 2
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
int smallestEvenMultiple(int n) {
    return n % 2 == 0 ? n : n * 2;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

给你一个正整数 <code>n</code> ，返回 <code>2</code><em> </em>和<em> </em><code>n</code> 的最小公倍数（正整数）。

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>n = 5
<strong>输出：</strong>10
<strong>解释：</strong>5 和 2 的最小公倍数是 10 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>n = 6
<strong>输出：</strong>6
<strong>解释：</strong>6 和 2 的最小公倍数是 6 。注意数字会是它自身的倍数。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 150</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数学

如果 $n$ 为偶数，那么 $2$ 和 $n$ 的最小公倍数就是 $n$ 本身。否则，$2$ 和 $n$ 的最小公倍数就是 $n \times 2$。

时间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def smallestEvenMultiple(self, n: int) -> int:
        return n if n % 2 == 0 else n * 2
```

#### Java

```java
class Solution {
    public int smallestEvenMultiple(int n) {
        return n % 2 == 0 ? n : n * 2;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int smallestEvenMultiple(int n) {
        return n % 2 == 0 ? n : n * 2;
    }
};
```

#### Go

```go
func smallestEvenMultiple(n int) int {
	if n%2 == 0 {
		return n
	}
	return n * 2
}
```

#### TypeScript

```ts
function smallestEvenMultiple(n: number): number {
    return n % 2 === 0 ? n : n * 2;
}
```

#### Rust

```rust
impl Solution {
    pub fn smallest_even_multiple(n: i32) -> i32 {
        if n % 2 == 0 {
            return n;
        }
        n * 2
    }
}
```

#### C

```c
int smallestEvenMultiple(int n) {
    return n % 2 == 0 ? n : n * 2;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2414. 最长的字母序连续子字符串的长度](https://leetcode.cn/problems/length-of-the-longest-alphabetical-continuous-substring){#2414}

{{< tabs "2414" >}}

{{% tab "python" %}}
```python
class Solution:
    def longestContinuousSubstring(self, s: str) -> int:
        ans = cnt = 1
        for x, y in pairwise(map(ord, s)):
            if y - x == 1:
                cnt += 1
                ans = max(ans, cnt)
            else:
                cnt = 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int longestContinuousSubstring(String s) {
        int ans = 1, cnt = 1;
        for (int i = 1; i < s.length(); ++i) {
            if (s.charAt(i) - s.charAt(i - 1) == 1) {
                ans = Math.max(ans, ++cnt);
            } else {
                cnt = 1;
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
    int longestContinuousSubstring(string s) {
        int ans = 1, cnt = 1;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] - s[i - 1] == 1) {
                ans = max(ans, ++cnt);
            } else {
                cnt = 1;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func longestContinuousSubstring(s string) int {
	ans, cnt := 1, 1
	for i := range s[1:] {
		if s[i+1]-s[i] == 1 {
			cnt++
			ans = max(ans, cnt)
		} else {
			cnt = 1
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function longestContinuousSubstring(s: string): number {
    let [ans, cnt] = [1, 1];
    for (let i = 1; i < s.length; ++i) {
        if (s.charCodeAt(i) - s.charCodeAt(i - 1) === 1) {
            ans = Math.max(ans, ++cnt);
        } else {
            cnt = 1;
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn longest_continuous_substring(s: String) -> i32 {
        let mut ans = 1;
        let mut cnt = 1;
        let s = s.as_bytes();
        for i in 1..s.len() {
            if s[i] - s[i - 1] == 1 {
                cnt += 1;
                ans = ans.max(cnt);
            } else {
                cnt = 1;
            }
        }
        ans
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
#define max(a, b) (((a) > (b)) ? (a) : (b))

int longestContinuousSubstring(char* s) {
    int n = strlen(s);
    int ans = 1, cnt = 1;
    for (int i = 1; i < n; ++i) {
        if (s[i] - s[i - 1] == 1) {
            ++cnt;
            ans = max(ans, cnt);
        } else {
            cnt = 1;
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

<p><strong>字母序连续字符串</strong> 是由字母表中连续字母组成的字符串。换句话说，字符串 <code>"abcdefghijklmnopqrstuvwxyz"</code> 的任意子字符串都是 <strong>字母序连续字符串</strong> 。</p>

<ul>
	<li>例如，<code>"abc"</code> 是一个字母序连续字符串，而 <code>"acb"</code> 和 <code>"za"</code> 不是。</li>
</ul>

<p>给你一个仅由小写英文字母组成的字符串 <code>s</code> ，返回其 <strong>最长</strong> 的 字母序连续子字符串 的长度。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = "abacaba"
<strong>输出：</strong>2
<strong>解释：</strong>共有 4 个不同的字母序连续子字符串 "a"、"b"、"c" 和 "ab" 。
"ab" 是最长的字母序连续子字符串。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = "abcde"
<strong>输出：</strong>5
<strong>解释：</strong>"abcde" 是最长的字母序连续子字符串。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> 由小写英文字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：一次遍历

我们可以遍历字符串 $s$，用一个变量 $\textit{ans}$ 记录最长的字母序连续子字符串的长度，用另一个变量 $\textit{cnt}$ 记录当前连续子字符串的长度。初始时 $\textit{ans} = \textit{cnt} = 1$。

接下来，我们从下标为 $1$ 的字符开始遍历字符串 $s$，对于每个字符 $s[i]$，如果 $s[i] - s[i - 1] = 1$，则说明当前字符和前一个字符是连续的，此时 $\textit{cnt} = \textit{cnt} + 1$，并更新 $\textit{ans} = \max(\textit{ans}, \textit{cnt})$；否则，说明当前字符和前一个字符不连续，此时 $\textit{cnt} = 1$。

最终返回 $\textit{ans}$ 即可。

时间复杂度 $O(n)$，其中 $n$ 为字符串 $s$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def longestContinuousSubstring(self, s: str) -> int:
        ans = cnt = 1
        for x, y in pairwise(map(ord, s)):
            if y - x == 1:
                cnt += 1
                ans = max(ans, cnt)
            else:
                cnt = 1
        return ans
```

#### Java

```java
class Solution {
    public int longestContinuousSubstring(String s) {
        int ans = 1, cnt = 1;
        for (int i = 1; i < s.length(); ++i) {
            if (s.charAt(i) - s.charAt(i - 1) == 1) {
                ans = Math.max(ans, ++cnt);
            } else {
                cnt = 1;
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
    int longestContinuousSubstring(string s) {
        int ans = 1, cnt = 1;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] - s[i - 1] == 1) {
                ans = max(ans, ++cnt);
            } else {
                cnt = 1;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func longestContinuousSubstring(s string) int {
	ans, cnt := 1, 1
	for i := range s[1:] {
		if s[i+1]-s[i] == 1 {
			cnt++
			ans = max(ans, cnt)
		} else {
			cnt = 1
		}
	}
	return ans
}
```

#### TypeScript

```ts
function longestContinuousSubstring(s: string): number {
    let [ans, cnt] = [1, 1];
    for (let i = 1; i < s.length; ++i) {
        if (s.charCodeAt(i) - s.charCodeAt(i - 1) === 1) {
            ans = Math.max(ans, ++cnt);
        } else {
            cnt = 1;
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn longest_continuous_substring(s: String) -> i32 {
        let mut ans = 1;
        let mut cnt = 1;
        let s = s.as_bytes();
        for i in 1..s.len() {
            if s[i] - s[i - 1] == 1 {
                cnt += 1;
                ans = ans.max(cnt);
            } else {
                cnt = 1;
            }
        }
        ans
    }
}
```

#### C

```c
#define max(a, b) (((a) > (b)) ? (a) : (b))

int longestContinuousSubstring(char* s) {
    int n = strlen(s);
    int ans = 1, cnt = 1;
    for (int i = 1; i < n; ++i) {
        if (s[i] - s[i - 1] == 1) {
            ++cnt;
            ans = max(ans, cnt);
        } else {
            cnt = 1;
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

# [2415. 反转二叉树的奇数层](https://leetcode.cn/problems/reverse-odd-levels-of-binary-tree){#2415}

{{< tabs "2415" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def reverseOddLevels(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        q = deque([root])
        i = 0
        while q:
            if i & 1:
                l, r = 0, len(q) - 1
                while l < r:
                    q[l].val, q[r].val = q[r].val, q[l].val
                    l, r = l + 1, r - 1
            for _ in range(len(q)):
                node = q.popleft()
                if node.left:
                    q.append(node.left)
                    q.append(node.right)
            i += 1
        return root
```
{{% /tab %}}
{{% tab "java" %}}
```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public TreeNode reverseOddLevels(TreeNode root) {
        Deque<TreeNode> q = new ArrayDeque<>();
        q.offer(root);
        for (int i = 0; !q.isEmpty(); ++i) {
            List<TreeNode> t = new ArrayList<>();
            for (int k = q.size(); k > 0; --k) {
                var node = q.poll();
                if (i % 2 == 1) {
                    t.add(node);
                }
                if (node.left != null) {
                    q.offer(node.left);
                    q.offer(node.right);
                }
            }
            for (int l = 0, r = t.size() - 1; l < r; ++l, --r) {
                var x = t.get(l).val;
                t.get(l).val = t.get(r).val;
                t.get(r).val = x;
            }
        }
        return root;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q{{root}};
        for (int i = 0; q.size(); ++i) {
            vector<TreeNode*> t;
            for (int k = q.size(); k; --k) {
                TreeNode* node = q.front();
                q.pop();
                if (i & 1) {
                    t.push_back(node);
                }
                if (node->left) {
                    q.push(node->left);
                    q.push(node->right);
                }
            }
            for (int l = 0, r = t.size() - 1; l < r; ++l, --r) {
                swap(t[l]->val, t[r]->val);
            }
        }
        return root;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func reverseOddLevels(root *TreeNode) *TreeNode {
	q := []*TreeNode{root}
	for i := 0; len(q) > 0; i++ {
		t := []*TreeNode{}
		for k := len(q); k > 0; k-- {
			node := q[0]
			q = q[1:]
			if i%2 == 1 {
				t = append(t, node)
			}
			if node.Left != nil {
				q = append(q, node.Left)
				q = append(q, node.Right)
			}
		}
		for l, r := 0, len(t)-1; l < r; l, r = l+1, r-1 {
			t[l].Val, t[r].Val = t[r].Val, t[l].Val
		}
	}
	return root
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function reverseOddLevels(root: TreeNode | null): TreeNode | null {
    const q: TreeNode[] = [root];
    for (let i = 0; q.length > 0; ++i) {
        if (i % 2) {
            for (let l = 0, r = q.length - 1; l < r; ++l, --r) {
                [q[l].val, q[r].val] = [q[r].val, q[l].val];
            }
        }
        const nq: TreeNode[] = [];
        for (const { left, right } of q) {
            if (left) {
                nq.push(left);
                nq.push(right);
            }
        }
        q.splice(0, q.length, ...nq);
    }
    return root;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
//
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::cell::RefCell;
use std::collections::VecDeque;
use std::rc::Rc;
impl Solution {
    fn create_tree(vals: &Vec<Vec<i32>>, i: usize, j: usize) -> Option<Rc<RefCell<TreeNode>>> {
        if i == vals.len() {
            return None;
        }
        Some(Rc::new(RefCell::new(TreeNode {
            val: vals[i][j],
            left: Self::create_tree(vals, i + 1, j * 2),
            right: Self::create_tree(vals, i + 1, j * 2 + 1),
        })))
    }

    pub fn reverse_odd_levels(
        root: Option<Rc<RefCell<TreeNode>>>,
    ) -> Option<Rc<RefCell<TreeNode>>> {
        let mut queue = VecDeque::new();
        queue.push_back(root);
        let mut d = 0;
        let mut vals = Vec::new();
        while !queue.is_empty() {
            let mut val = Vec::new();
            for _ in 0..queue.len() {
                let mut node = queue.pop_front().unwrap();
                let mut node = node.as_mut().unwrap().borrow_mut();
                val.push(node.val);
                if node.left.is_some() {
                    queue.push_back(node.left.take());
                }
                if node.right.is_some() {
                    queue.push_back(node.right.take());
                }
            }
            if d % 2 == 1 {
                val.reverse();
            }
            vals.push(val);
            d += 1;
        }
        Self::create_tree(&vals, 0, 0)
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一棵 <strong>完美</strong> 二叉树的根节点 <code>root</code> ，请你反转这棵树中每个 <strong>奇数</strong> 层的节点值。</p>

<ul>
	<li>例如，假设第 3 层的节点值是 <code>[2,1,3,4,7,11,29,18]</code> ，那么反转后它应该变成 <code>[18,29,11,7,4,3,1,2]</code> 。</li>
</ul>

<p>反转后，返回树的根节点。</p>

<p><strong>完美</strong> 二叉树需满足：二叉树的所有父节点都有两个子节点，且所有叶子节点都在同一层。</p>

<p>节点的 <strong>层数</strong> 等于该节点到根节点之间的边数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2400-2499/2415.Reverse%20Odd%20Levels%20of%20Binary%20Tree/images/first_case1.png" style="width: 626px; height: 191px;" />
<pre>
<strong>输入：</strong>root = [2,3,5,8,13,21,34]
<strong>输出：</strong>[2,5,3,8,13,21,34]
<strong>解释：</strong>
这棵树只有一个奇数层。
在第 1 层的节点分别是 3、5 ，反转后为 5、3 。
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2400-2499/2415.Reverse%20Odd%20Levels%20of%20Binary%20Tree/images/second_case3.png" style="width: 591px; height: 111px;" />
<pre>
<strong>输入：</strong>root = [7,13,11]
<strong>输出：</strong>[7,11,13]
<strong>解释：</strong> 
在第 1 层的节点分别是 13、11 ，反转后为 11、13 。 
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>root = [0,1,2,0,0,0,0,1,1,1,1,2,2,2,2]
<strong>输出：</strong>[0,2,1,0,0,0,0,2,2,2,2,1,1,1,1]
<strong>解释：</strong>奇数层由非零值组成。
在第 1 层的节点分别是 1、2 ，反转后为 2、1 。
在第 3 层的节点分别是 1、1、1、1、2、2、2、2 ，反转后为 2、2、2、2、1、1、1、1 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中的节点数目在范围 <code>[1, 2<sup>14</sup>]</code> 内</li>
	<li><code>0 &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
	<li><code>root</code> 是一棵 <strong>完美</strong> 二叉树</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：BFS

我们可以使用广度优先搜索的方法，用一个队列 $q$ 来存储每一层的节点，用一个变量 $i$ 记录当前层数。若 $i$ 为奇数，则将当前层的节点值反转。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是二叉树的节点数。

<!-- tabs:start -->

#### Python3

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def reverseOddLevels(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        q = deque([root])
        i = 0
        while q:
            if i & 1:
                l, r = 0, len(q) - 1
                while l < r:
                    q[l].val, q[r].val = q[r].val, q[l].val
                    l, r = l + 1, r - 1
            for _ in range(len(q)):
                node = q.popleft()
                if node.left:
                    q.append(node.left)
                    q.append(node.right)
            i += 1
        return root
```

#### Java

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public TreeNode reverseOddLevels(TreeNode root) {
        Deque<TreeNode> q = new ArrayDeque<>();
        q.offer(root);
        for (int i = 0; !q.isEmpty(); ++i) {
            List<TreeNode> t = new ArrayList<>();
            for (int k = q.size(); k > 0; --k) {
                var node = q.poll();
                if (i % 2 == 1) {
                    t.add(node);
                }
                if (node.left != null) {
                    q.offer(node.left);
                    q.offer(node.right);
                }
            }
            for (int l = 0, r = t.size() - 1; l < r; ++l, --r) {
                var x = t.get(l).val;
                t.get(l).val = t.get(r).val;
                t.get(r).val = x;
            }
        }
        return root;
    }
}
```

#### C++

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q{{root}};
        for (int i = 0; q.size(); ++i) {
            vector<TreeNode*> t;
            for (int k = q.size(); k; --k) {
                TreeNode* node = q.front();
                q.pop();
                if (i & 1) {
                    t.push_back(node);
                }
                if (node->left) {
                    q.push(node->left);
                    q.push(node->right);
                }
            }
            for (int l = 0, r = t.size() - 1; l < r; ++l, --r) {
                swap(t[l]->val, t[r]->val);
            }
        }
        return root;
    }
};
```

#### Go

```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func reverseOddLevels(root *TreeNode) *TreeNode {
	q := []*TreeNode{root}
	for i := 0; len(q) > 0; i++ {
		t := []*TreeNode{}
		for k := len(q); k > 0; k-- {
			node := q[0]
			q = q[1:]
			if i%2 == 1 {
				t = append(t, node)
			}
			if node.Left != nil {
				q = append(q, node.Left)
				q = append(q, node.Right)
			}
		}
		for l, r := 0, len(t)-1; l < r; l, r = l+1, r-1 {
			t[l].Val, t[r].Val = t[r].Val, t[l].Val
		}
	}
	return root
}
```

#### TypeScript

```ts
/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function reverseOddLevels(root: TreeNode | null): TreeNode | null {
    const q: TreeNode[] = [root];
    for (let i = 0; q.length > 0; ++i) {
        if (i % 2) {
            for (let l = 0, r = q.length - 1; l < r; ++l, --r) {
                [q[l].val, q[r].val] = [q[r].val, q[l].val];
            }
        }
        const nq: TreeNode[] = [];
        for (const { left, right } of q) {
            if (left) {
                nq.push(left);
                nq.push(right);
            }
        }
        q.splice(0, q.length, ...nq);
    }
    return root;
}
```

#### Rust

```rust
// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
//
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::cell::RefCell;
use std::collections::VecDeque;
use std::rc::Rc;
impl Solution {
    fn create_tree(vals: &Vec<Vec<i32>>, i: usize, j: usize) -> Option<Rc<RefCell<TreeNode>>> {
        if i == vals.len() {
            return None;
        }
        Some(Rc::new(RefCell::new(TreeNode {
            val: vals[i][j],
            left: Self::create_tree(vals, i + 1, j * 2),
            right: Self::create_tree(vals, i + 1, j * 2 + 1),
        })))
    }

    pub fn reverse_odd_levels(
        root: Option<Rc<RefCell<TreeNode>>>,
    ) -> Option<Rc<RefCell<TreeNode>>> {
        let mut queue = VecDeque::new();
        queue.push_back(root);
        let mut d = 0;
        let mut vals = Vec::new();
        while !queue.is_empty() {
            let mut val = Vec::new();
            for _ in 0..queue.len() {
                let mut node = queue.pop_front().unwrap();
                let mut node = node.as_mut().unwrap().borrow_mut();
                val.push(node.val);
                if node.left.is_some() {
                    queue.push_back(node.left.take());
                }
                if node.right.is_some() {
                    queue.push_back(node.right.take());
                }
            }
            if d % 2 == 1 {
                val.reverse();
            }
            vals.push(val);
            d += 1;
        }
        Self::create_tree(&vals, 0, 0)
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2416. 字符串的前缀分数和](https://leetcode.cn/problems/sum-of-prefix-scores-of-strings){#2416}

{{< tabs "2416" >}}

{{% tab "python" %}}
```python
class Trie:
    __slots__ = "children", "cnt"

    def __init__(self):
        self.children = [None] * 26
        self.cnt = 0

    def insert(self, w):
        node = self
        for c in w:
            idx = ord(c) - ord("a")
            if node.children[idx] is None:
                node.children[idx] = Trie()
            node = node.children[idx]
            node.cnt += 1

    def search(self, w):
        node = self
        ans = 0
        for c in w:
            idx = ord(c) - ord("a")
            if node.children[idx] is None:
                return ans
            node = node.children[idx]
            ans += node.cnt
        return ans


class Solution:
    def sumPrefixScores(self, words: List[str]) -> List[int]:
        trie = Trie()
        for w in words:
            trie.insert(w)
        return [trie.search(w) for w in words]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Trie {
    private Trie[] children = new Trie[26];
    private int cnt;

    public void insert(String w) {
        Trie node = this;
        for (char c : w.toCharArray()) {
            c -= 'a';
            if (node.children[c] == null) {
                node.children[c] = new Trie();
            }
            node = node.children[c];
            ++node.cnt;
        }
    }

    public int search(String w) {
        Trie node = this;
        int ans = 0;
        for (char c : w.toCharArray()) {
            c -= 'a';
            if (node.children[c] == null) {
                return ans;
            }
            node = node.children[c];
            ans += node.cnt;
        }
        return ans;
    }
}

class Solution {
    public int[] sumPrefixScores(String[] words) {
        Trie trie = new Trie();
        for (String w : words) {
            trie.insert(w);
        }
        int[] ans = new int[words.length];
        for (int i = 0; i < words.length; ++i) {
            ans[i] = trie.search(words[i]);
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Trie {
private:
    Trie* children[26]{};
    int cnt = 0;

public:
    void insert(string& w) {
        Trie* node = this;
        for (char c : w) {
            int idx = c - 'a';
            if (!node->children[idx]) {
                node->children[idx] = new Trie();
            }
            node = node->children[idx];
            ++node->cnt;
        }
    }

    int search(string& w) {
        Trie* node = this;
        int ans = 0;
        for (char c : w) {
            int idx = c - 'a';
            if (!node->children[idx]) {
                return ans;
            }
            node = node->children[idx];
            ans += node->cnt;
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie* trie = new Trie();
        for (auto& w : words) {
            trie->insert(w);
        }
        vector<int> ans;
        for (auto& w : words) {
            ans.push_back(trie->search(w));
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
type Trie struct {
	children [26]*Trie
	cnt      int
}

func newTrie() *Trie {
	return &Trie{}
}
func (this *Trie) insert(w string) {
	node := this
	for _, c := range w {
		c -= 'a'
		if node.children[c] == nil {
			node.children[c] = newTrie()
		}
		node = node.children[c]
		node.cnt++
	}
}

func (this *Trie) search(word string) int {
	node := this
	ans := 0
	for _, c := range word {
		c -= 'a'
		if node.children[c] == nil {
			return ans
		}
		node = node.children[c]
		ans += node.cnt
	}
	return ans
}

func sumPrefixScores(words []string) []int {
	trie := newTrie()
	for _, w := range words {
		trie.insert(w)
	}
	ans := make([]int, len(words))
	for i, w := range words {
		ans[i] = trie.search(w)
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class Trie {
    children: Array<any>;
    cnt: number;

    constructor() {
        this.children = Array(26);
        this.cnt = 0;
    }

    insert(w: string): void {
        let node = this;
        for (const c of w) {
            const idx = c.charCodeAt(0) - 'a'.charCodeAt(0);
            if (!node.children[idx]) {
                node.children[idx] = new Trie();
            }
            node = node.children[idx];
            node.cnt++;
        }
    }

    search(w: string): number {
        let node = this;
        let ans = 0;
        for (const c of w) {
            const idx = c.charCodeAt(0) - 'a'.charCodeAt(0);
            if (!node.children[idx]) {
                return ans;
            }
            node = node.children[idx];
            ans += node.cnt;
        }
        return ans;
    }
}

function sumPrefixScores(words: string[]): number[] {
    const trie = new Trie();
    for (const w of words) {
        trie.insert(w);
    }
    return words.map(w => trie.search(w));
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
class Trie {
    constructor() {
        this.children = {};
        this.cnt = 0;
    }

    insert(w) {
        let node = this;
        for (const c of w) {
            if (!node.children[c]) {
                node.children[c] = new Trie();
            }
            node = node.children[c];
            node.cnt++;
        }
    }

    search(w) {
        let node = this;
        let ans = 0;
        for (const c of w) {
            if (!node.children[c]) {
                return ans;
            }
            node = node.children[c];
            ans += node.cnt;
        }
        return ans;
    }
}

/**
 * @param {string[]} words
 * @return {number[]}
 */
var sumPrefixScores = function (words) {
    const trie = new Trie();
    for (const w of words) {
        trie.insert(w);
    }
    return words.map(w => trie.search(w));
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个长度为 <code>n</code> 的数组 <code>words</code> ，该数组由 <strong>非空</strong> 字符串组成。</p>

<p>定义字符串 <code>term</code> 的 <strong>分数</strong> 等于以 <code>term</code> 作为 <strong>前缀</strong> 的 <code>words[i]</code> 的数目。</p>

<ul>
	<li>例如，如果 <code>words = ["a", "ab", "abc", "cab"]</code> ，那么 <code>"ab"</code> 的分数是 <code>2</code> ，因为 <code>"ab"</code> 是 <code>"ab"</code> 和 <code>"abc"</code> 的一个前缀。</li>
</ul>

<p>返回一个长度为<em> </em><code>n</code> 的数组<em> </em><code>answer</code><em> </em>，其中<em> </em><code>answer[i]</code><em> </em>是<em>&nbsp;</em><code>words[i]</code> 的每个非空前缀的分数 <strong>总和</strong> <em>。</em></p>

<p><strong>注意：</strong>字符串视作它自身的一个前缀。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>words = ["abc","ab","bc","b"]
<strong>输出：</strong>[5,4,3,2]
<strong>解释：</strong>对应每个字符串的答案如下：
- "abc" 有 3 个前缀："a"、"ab" 和 "abc" 。
- 2 个字符串的前缀为 "a" ，2 个字符串的前缀为 "ab" ，1 个字符串的前缀为 "abc" 。
总计 answer[0] = 2 + 2 + 1 = 5 。
- "ab" 有 2 个前缀："a" 和 "ab" 。
- 2 个字符串的前缀为 "a" ，2 个字符串的前缀为 "ab" 。
总计 answer[1] = 2 + 2 = 4 。
- "bc" 有 2 个前缀："b" 和 "bc" 。
- 2 个字符串的前缀为 "b" ，1 个字符串的前缀为 "bc" 。 
总计 answer[2] = 2 + 1 = 3 。
- "b" 有 1 个前缀："b"。
- 2 个字符串的前缀为 "b" 。
总计 answer[3] = 2 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>words = ["abcd"]
<strong>输出：</strong>[4]
<strong>解释：</strong>
"abcd" 有 4 个前缀 "a"、"ab"、"abc" 和 "abcd"。
每个前缀的分数都是 1 ，总计 answer[0] = 1 + 1 + 1 + 1 = 4 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 1000</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 1000</code></li>
	<li><code>words[i]</code> 由小写英文字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前缀树

我们可以用前缀树来维护所有字符串的前缀以及每个前缀出现的次数。

定义前缀树节点结构体 `Trie`，包含两个属性：

-   `children`：长度为 26 的数组，用于存储当前节点的子节点。
-   `cnt`：当前节点的出现次数。

定义前缀树的两个方法：

-   `insert`：插入一个字符串，将其前缀插入前缀树。
-   `search`：搜索一个字符串，返回其前缀的出现次数。

我们遍历所有字符串，将每个字符串插入前缀树中。然后再遍历所有字符串，对每个字符串调用 `search` 方法，累加每个前缀的出现次数即可。

时间复杂度 $O(L)$，空间复杂度 $O(L)$，其中 $L$ 是所有字符串的总长度。

<!-- tabs:start -->

#### Python3

```python
class Trie:
    __slots__ = "children", "cnt"

    def __init__(self):
        self.children = [None] * 26
        self.cnt = 0

    def insert(self, w):
        node = self
        for c in w:
            idx = ord(c) - ord("a")
            if node.children[idx] is None:
                node.children[idx] = Trie()
            node = node.children[idx]
            node.cnt += 1

    def search(self, w):
        node = self
        ans = 0
        for c in w:
            idx = ord(c) - ord("a")
            if node.children[idx] is None:
                return ans
            node = node.children[idx]
            ans += node.cnt
        return ans


class Solution:
    def sumPrefixScores(self, words: List[str]) -> List[int]:
        trie = Trie()
        for w in words:
            trie.insert(w)
        return [trie.search(w) for w in words]
```

#### Java

```java
class Trie {
    private Trie[] children = new Trie[26];
    private int cnt;

    public void insert(String w) {
        Trie node = this;
        for (char c : w.toCharArray()) {
            c -= 'a';
            if (node.children[c] == null) {
                node.children[c] = new Trie();
            }
            node = node.children[c];
            ++node.cnt;
        }
    }

    public int search(String w) {
        Trie node = this;
        int ans = 0;
        for (char c : w.toCharArray()) {
            c -= 'a';
            if (node.children[c] == null) {
                return ans;
            }
            node = node.children[c];
            ans += node.cnt;
        }
        return ans;
    }
}

class Solution {
    public int[] sumPrefixScores(String[] words) {
        Trie trie = new Trie();
        for (String w : words) {
            trie.insert(w);
        }
        int[] ans = new int[words.length];
        for (int i = 0; i < words.length; ++i) {
            ans[i] = trie.search(words[i]);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Trie {
private:
    Trie* children[26]{};
    int cnt = 0;

public:
    void insert(string& w) {
        Trie* node = this;
        for (char c : w) {
            int idx = c - 'a';
            if (!node->children[idx]) {
                node->children[idx] = new Trie();
            }
            node = node->children[idx];
            ++node->cnt;
        }
    }

    int search(string& w) {
        Trie* node = this;
        int ans = 0;
        for (char c : w) {
            int idx = c - 'a';
            if (!node->children[idx]) {
                return ans;
            }
            node = node->children[idx];
            ans += node->cnt;
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie* trie = new Trie();
        for (auto& w : words) {
            trie->insert(w);
        }
        vector<int> ans;
        for (auto& w : words) {
            ans.push_back(trie->search(w));
        }
        return ans;
    }
};
```

#### Go

```go
type Trie struct {
	children [26]*Trie
	cnt      int
}

func newTrie() *Trie {
	return &Trie{}
}
func (this *Trie) insert(w string) {
	node := this
	for _, c := range w {
		c -= 'a'
		if node.children[c] == nil {
			node.children[c] = newTrie()
		}
		node = node.children[c]
		node.cnt++
	}
}

func (this *Trie) search(word string) int {
	node := this
	ans := 0
	for _, c := range word {
		c -= 'a'
		if node.children[c] == nil {
			return ans
		}
		node = node.children[c]
		ans += node.cnt
	}
	return ans
}

func sumPrefixScores(words []string) []int {
	trie := newTrie()
	for _, w := range words {
		trie.insert(w)
	}
	ans := make([]int, len(words))
	for i, w := range words {
		ans[i] = trie.search(w)
	}
	return ans
}
```

#### TypeScript

```ts
class Trie {
    children: Array<any>;
    cnt: number;

    constructor() {
        this.children = Array(26);
        this.cnt = 0;
    }

    insert(w: string): void {
        let node = this;
        for (const c of w) {
            const idx = c.charCodeAt(0) - 'a'.charCodeAt(0);
            if (!node.children[idx]) {
                node.children[idx] = new Trie();
            }
            node = node.children[idx];
            node.cnt++;
        }
    }

    search(w: string): number {
        let node = this;
        let ans = 0;
        for (const c of w) {
            const idx = c.charCodeAt(0) - 'a'.charCodeAt(0);
            if (!node.children[idx]) {
                return ans;
            }
            node = node.children[idx];
            ans += node.cnt;
        }
        return ans;
    }
}

function sumPrefixScores(words: string[]): number[] {
    const trie = new Trie();
    for (const w of words) {
        trie.insert(w);
    }
    return words.map(w => trie.search(w));
}
```

#### JavaScript

```js
class Trie {
    constructor() {
        this.children = {};
        this.cnt = 0;
    }

    insert(w) {
        let node = this;
        for (const c of w) {
            if (!node.children[c]) {
                node.children[c] = new Trie();
            }
            node = node.children[c];
            node.cnt++;
        }
    }

    search(w) {
        let node = this;
        let ans = 0;
        for (const c of w) {
            if (!node.children[c]) {
                return ans;
            }
            node = node.children[c];
            ans += node.cnt;
        }
        return ans;
    }
}

/**
 * @param {string[]} words
 * @return {number[]}
 */
var sumPrefixScores = function (words) {
    const trie = new Trie();
    for (const w of words) {
        trie.insert(w);
    }
    return words.map(w => trie.search(w));
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2417. 最近的公平整数 🔒](https://leetcode.cn/problems/closest-fair-integer){#2417}

{{< tabs "2417" >}}

{{% tab "python" %}}
```python
class Solution:
    def closestFair(self, n: int) -> int:
        a = b = k = 0
        t = n
        while t:
            if (t % 10) & 1:
                a += 1
            else:
                b += 1
            t //= 10
            k += 1
        if k & 1:
            x = 10**k
            y = int('1' * (k >> 1) or '0')
            return x + y
        if a == b:
            return n
        return self.closestFair(n + 1)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int closestFair(int n) {
        int a = 0, b = 0;
        int k = 0, t = n;
        while (t > 0) {
            if ((t % 10) % 2 == 1) {
                ++a;
            } else {
                ++b;
            }
            t /= 10;
            ++k;
        }
        if (k % 2 == 1) {
            int x = (int) Math.pow(10, k);
            int y = 0;
            for (int i = 0; i < k >> 1; ++i) {
                y = y * 10 + 1;
            }
            return x + y;
        }
        if (a == b) {
            return n;
        }
        return closestFair(n + 1);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int closestFair(int n) {
        int a = 0, b = 0;
        int t = n, k = 0;
        while (t) {
            if ((t % 10) & 1) {
                ++a;
            } else {
                ++b;
            }
            ++k;
            t /= 10;
        }
        if (a == b) {
            return n;
        }
        if (k % 2 == 1) {
            int x = pow(10, k);
            int y = 0;
            for (int i = 0; i < k >> 1; ++i) {
                y = y * 10 + 1;
            }
            return x + y;
        }
        return closestFair(n + 1);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func closestFair(n int) int {
	a, b := 0, 0
	t, k := n, 0
	for t > 0 {
		if (t%10)%2 == 1 {
			a++
		} else {
			b++
		}
		k++
		t /= 10
	}
	if a == b {
		return n
	}
	if k%2 == 1 {
		x := int(math.Pow(10, float64(k)))
		y := 0
		for i := 0; i < k>>1; i++ {
			y = y*10 + 1
		}
		return x + y
	}
	return closestFair(n + 1)
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个 <strong>正整数</strong>&nbsp;<code>n</code>。</p>

<p>如果一个整数 <code>k</code> 中的&nbsp;<strong>偶数&nbsp;</strong>位数与<strong> 奇数</strong> 位数相等，那么我们称&nbsp;<code>k</code> 为公平整数。</p>

<p>返回&nbsp;<em><strong>大于或等于&nbsp;</strong></em><code>n</code><em> 的&nbsp;<strong>最小&nbsp;</strong>的公平整数。</em></p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> n = 2
<strong>输出:</strong> 10
<strong>解释:</strong> 大于等于 2 的最小的公平整数是 10。
10是公平整数，因为它的偶数和奇数个数相等 (一个奇数和一个偶数)。</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> n = 403
<strong>输出:</strong> 1001
<strong>解释:</strong> 大于或等于 403 的最小的公平整数是 1001。
1001 是公平整数，因为它有相等数量的偶数和奇数 (两个奇数和两个偶数)。
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：分类讨论

我们记 $n$ 的位数为 $k$，奇数位数、偶数位数分别为 $a$ 和 $b$。

-   若 $a=b$，则 $n$ 本身就是 `fair` 的，直接返回 $n$ 即可；
-   否则，若 $k$ 为奇数，那么我们找到 $k+1$ 位的最小 `fair` 数即可，形如 `10000111`；若 $k$ 为偶数，我们直接暴力递归 `closestFair(n+1)` 即可。

时间复杂度 $O(\sqrt{n} \times \log_{10} n)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def closestFair(self, n: int) -> int:
        a = b = k = 0
        t = n
        while t:
            if (t % 10) & 1:
                a += 1
            else:
                b += 1
            t //= 10
            k += 1
        if k & 1:
            x = 10**k
            y = int('1' * (k >> 1) or '0')
            return x + y
        if a == b:
            return n
        return self.closestFair(n + 1)
```

#### Java

```java
class Solution {
    public int closestFair(int n) {
        int a = 0, b = 0;
        int k = 0, t = n;
        while (t > 0) {
            if ((t % 10) % 2 == 1) {
                ++a;
            } else {
                ++b;
            }
            t /= 10;
            ++k;
        }
        if (k % 2 == 1) {
            int x = (int) Math.pow(10, k);
            int y = 0;
            for (int i = 0; i < k >> 1; ++i) {
                y = y * 10 + 1;
            }
            return x + y;
        }
        if (a == b) {
            return n;
        }
        return closestFair(n + 1);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int closestFair(int n) {
        int a = 0, b = 0;
        int t = n, k = 0;
        while (t) {
            if ((t % 10) & 1) {
                ++a;
            } else {
                ++b;
            }
            ++k;
            t /= 10;
        }
        if (a == b) {
            return n;
        }
        if (k % 2 == 1) {
            int x = pow(10, k);
            int y = 0;
            for (int i = 0; i < k >> 1; ++i) {
                y = y * 10 + 1;
            }
            return x + y;
        }
        return closestFair(n + 1);
    }
};
```

#### Go

```go
func closestFair(n int) int {
	a, b := 0, 0
	t, k := n, 0
	for t > 0 {
		if (t%10)%2 == 1 {
			a++
		} else {
			b++
		}
		k++
		t /= 10
	}
	if a == b {
		return n
	}
	if k%2 == 1 {
		x := int(math.Pow(10, float64(k)))
		y := 0
		for i := 0; i < k>>1; i++ {
			y = y*10 + 1
		}
		return x + y
	}
	return closestFair(n + 1)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2418. 按身高排序](https://leetcode.cn/problems/sort-the-people){#2418}

{{< tabs "2418" >}}

{{% tab "python" %}}
```python
class Solution:
    def sortPeople(self, names: List[str], heights: List[int]) -> List[str]:
        return [name for _, name in sorted(zip(heights, names), reverse=True)]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String[] sortPeople(String[] names, int[] heights) {
        int n = names.length;
        int[][] arr = new int[n][2];
        for (int i = 0; i < n; ++i) {
            arr[i] = new int[] {heights[i], i};
        }
        Arrays.sort(arr, (a, b) -> b[0] - a[0]);
        String[] ans = new String[n];
        for (int i = 0; i < n; ++i) {
            ans[i] = names[arr[i][1]];
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
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; ++i) {
            arr.emplace_back(-heights[i], i);
        }
        sort(arr.begin(), arr.end());
        vector<string> ans;
        for (int i = 0; i < n; ++i) {
            ans.emplace_back(names[arr[i].second]);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func sortPeople(names []string, heights []int) []string {
	n := len(names)
	arr := make([][2]int, n)
	for i, h := range heights {
		arr[i] = [2]int{h, i}
	}
	sort.Slice(arr, func(i, j int) bool { return arr[i][0] > arr[j][0] })
	ans := make([]string, n)
	for i, x := range arr {
		ans[i] = names[x[1]]
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function sortPeople(names: string[], heights: number[]): string[] {
    return names
        .map<[string, number]>((s, i) => [s, heights[i]])
        .sort((a, b) => b[1] - a[1])
        .map(([v]) => v);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn sort_people(names: Vec<String>, heights: Vec<i32>) -> Vec<String> {
        let mut combine: Vec<(String, i32)> = names.into_iter().zip(heights.into_iter()).collect();
        combine.sort_by(|a, b| b.1.cmp(&a.1));
        combine.iter().map(|s| s.0.clone()).collect()
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串数组 <code>names</code> ，和一个由 <strong>互不相同</strong> 的正整数组成的数组 <code>heights</code> 。两个数组的长度均为 <code>n</code> 。</p>

<p>对于每个下标 <code>i</code>，<code>names[i]</code> 和 <code>heights[i]</code> 表示第 <code>i</code> 个人的名字和身高。</p>

<p>请按身高 <strong>降序</strong> 顺序返回对应的名字数组 <code>names</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>names = ["Mary","John","Emma"], heights = [180,165,170]
<strong>输出：</strong>["Mary","Emma","John"]
<strong>解释：</strong>Mary 最高，接着是 Emma 和 John 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>names = ["Alice","Bob","Bob"], heights = [155,185,150]
<strong>输出：</strong>["Bob","Alice","Bob"]
<strong>解释：</strong>第一个 Bob 最高，然后是 Alice 和第二个 Bob 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == names.length == heights.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>3</sup></code></li>
	<li><code>1 &lt;= names[i].length &lt;= 20</code></li>
	<li><code>1 &lt;= heights[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>names[i]</code> 由大小写英文字母组成</li>
	<li><code>heights</code> 中的所有值互不相同</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序

根据题目描述，我们可以创建一个长度为 $n$ 的下标数组 $idx$，其中 $idx[i]=i$。然后我们对 $idx$ 中的每个下标按照 $heights$ 中对应的身高降序排序，最后遍历排序后的 $idx$ 中的每个下标 $i$，将 $names[i]$ 加入答案数组即可。

我们也可以创建一个长度为 $n$ 的数组 $arr$，数组中每个元素是一个二元组 $(heights[i], i)$，然后我们对 $arr$ 按照身高降序排序。最后遍历排序后的 $arr$ 中的每个元素 $(heights[i], i)$，将 $names[i]$ 加入答案数组即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 $names$ 和 $heights$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def sortPeople(self, names: List[str], heights: List[int]) -> List[str]:
        idx = list(range(len(heights)))
        idx.sort(key=lambda i: -heights[i])
        return [names[i] for i in idx]
```

#### Java

```java
class Solution {
    public String[] sortPeople(String[] names, int[] heights) {
        int n = names.length;
        Integer[] idx = new Integer[n];
        Arrays.setAll(idx, i -> i);
        Arrays.sort(idx, (i, j) -> heights[j] - heights[i]);
        String[] ans = new String[n];
        for (int i = 0; i < n; ++i) {
            ans[i] = names[idx[i]];
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int i, int j) { return heights[j] < heights[i]; });
        vector<string> ans;
        for (int i : idx) {
            ans.push_back(names[i]);
        }
        return ans;
    }
};
```

#### Go

```go
func sortPeople(names []string, heights []int) (ans []string) {
	n := len(names)
	idx := make([]int, n)
	for i := range idx {
		idx[i] = i
	}
	sort.Slice(idx, func(i, j int) bool { return heights[idx[j]] < heights[idx[i]] })
	for _, i := range idx {
		ans = append(ans, names[i])
	}
	return
}
```

#### TypeScript

```ts
function sortPeople(names: string[], heights: number[]): string[] {
    const n = names.length;
    const idx = new Array(n);
    for (let i = 0; i < n; ++i) {
        idx[i] = i;
    }
    idx.sort((i, j) => heights[j] - heights[i]);
    const ans: string[] = [];
    for (const i of idx) {
        ans.push(names[i]);
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn sort_people(names: Vec<String>, heights: Vec<i32>) -> Vec<String> {
        let mut combine: Vec<(String, i32)> = names.into_iter().zip(heights.into_iter()).collect();
        combine.sort_by(|a, b| b.1.cmp(&a.1));
        combine.iter().map(|s| s.0.clone()).collect()
    }
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
    def sortPeople(self, names: List[str], heights: List[int]) -> List[str]:
        return [name for _, name in sorted(zip(heights, names), reverse=True)]
```

#### Java

```java
class Solution {
    public String[] sortPeople(String[] names, int[] heights) {
        int n = names.length;
        int[][] arr = new int[n][2];
        for (int i = 0; i < n; ++i) {
            arr[i] = new int[] {heights[i], i};
        }
        Arrays.sort(arr, (a, b) -> b[0] - a[0]);
        String[] ans = new String[n];
        for (int i = 0; i < n; ++i) {
            ans[i] = names[arr[i][1]];
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; ++i) {
            arr.emplace_back(-heights[i], i);
        }
        sort(arr.begin(), arr.end());
        vector<string> ans;
        for (int i = 0; i < n; ++i) {
            ans.emplace_back(names[arr[i].second]);
        }
        return ans;
    }
};
```

#### Go

```go
func sortPeople(names []string, heights []int) []string {
	n := len(names)
	arr := make([][2]int, n)
	for i, h := range heights {
		arr[i] = [2]int{h, i}
	}
	sort.Slice(arr, func(i, j int) bool { return arr[i][0] > arr[j][0] })
	ans := make([]string, n)
	for i, x := range arr {
		ans[i] = names[x[1]]
	}
	return ans
}
```

#### TypeScript

```ts
function sortPeople(names: string[], heights: number[]): string[] {
    return names
        .map<[string, number]>((s, i) => [s, heights[i]])
        .sort((a, b) => b[1] - a[1])
        .map(([v]) => v);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2419. 按位与最大的最长子数组](https://leetcode.cn/problems/longest-subarray-with-maximum-bitwise-and){#2419}

{{< tabs "2419" >}}

{{% tab "python" %}}
```python
class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        mx = max(nums)
        ans = cnt = 0
        for x in nums:
            if x == mx:
                cnt += 1
                ans = max(ans, cnt)
            else:
                cnt = 0
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int longestSubarray(int[] nums) {
        int mx = Arrays.stream(nums).max().getAsInt();
        int ans = 0, cnt = 0;
        for (int x : nums) {
            if (x == mx) {
                ans = Math.max(ans, ++cnt);
            } else {
                cnt = 0;
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
    int longestSubarray(vector<int>& nums) {
        int mx = ranges::max(nums);
        int ans = 0, cnt = 0;
        for (int x : nums) {
            if (x == mx) {
                ans = max(ans, ++cnt);
            } else {
                cnt = 0;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func longestSubarray(nums []int) (ans int) {
	mx := slices.Max(nums)
	cnt := 0
	for _, x := range nums {
		if x == mx {
			cnt++
			ans = max(ans, cnt)
		} else {
			cnt = 0
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function longestSubarray(nums: number[]): number {
    const mx = Math.max(...nums);
    let [ans, cnt] = [0, 0];
    for (const x of nums) {
        if (x === mx) {
            ans = Math.max(ans, ++cnt);
        } else {
            cnt = 0;
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn longest_subarray(nums: Vec<i32>) -> i32 {
        let mx = *nums.iter().max().unwrap();
        let mut ans = 0;
        let mut cnt = 0;

        for &x in nums.iter() {
            if x == mx {
                cnt += 1;
                ans = ans.max(cnt);
            } else {
                cnt = 0;
            }
        }

        ans
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var longestSubarray = function (nums) {
    const mx = Math.max(...nums);
    let [ans, cnt] = [0, 0];
    for (const x of nums) {
        if (x === mx) {
            ans = Math.max(ans, ++cnt);
        } else {
            cnt = 0;
        }
    }
    return ans;
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int LongestSubarray(int[] nums) {
        int mx = nums.Max();
        int ans = 0, cnt = 0;
        foreach (int x in nums) {
            if (x == mx) {
                ans = Math.Max(ans, ++cnt);
            } else {
                cnt = 0;
            }
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function longestSubarray($nums) {
        $mx = max($nums);
        $ans = 0;
        $cnt = 0;

        foreach ($nums as $x) {
            if ($x == $mx) {
                $ans = max($ans, ++$cnt);
            } else {
                $cnt = 0;
            }
        }

        return $ans;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个长度为 <code>n</code> 的整数数组 <code>nums</code> 。</p>

<p>考虑 <code>nums</code> 中进行 <strong>按位与（bitwise AND）</strong>运算得到的值 <strong>最大</strong> 的 <strong>非空</strong> 子数组。</p>

<ul>
	<li>换句话说，令 <code>k</code> 是 <code>nums</code> <strong>任意</strong> 子数组执行按位与运算所能得到的最大值。那么，只需要考虑那些执行一次按位与运算后等于 <code>k</code> 的子数组。</li>
</ul>

<p>返回满足要求的 <strong>最长</strong> 子数组的长度。</p>

<p>数组的按位与就是对数组中的所有数字进行按位与运算。</p>

<p><strong>子数组</strong> 是数组中的一个连续元素序列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3,3,2,2]
<strong>输出：</strong>2
<strong>解释：</strong>
子数组按位与运算的最大值是 3 。
能得到此结果的最长子数组是 [3,3]，所以返回 2 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3,4]
<strong>输出：</strong>1
<strong>解释：</strong>
子数组按位与运算的最大值是 4 。 
能得到此结果的最长子数组是 [4]，所以返回 1 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：脑筋急转弯

由于按位与的操作，不会使得数字变大，因此最大值就是数组中的最大值。

题目可以转换为求最大值在数组中最多连续出现的次数。

我们先遍历数组 $\textit{nums}$ 找到最大值 $\textit{mx}$，然后再遍历数组一次，找到最大值连续出现的次数，最后返回这个次数即可。

时间复杂度 $O(n)$，其中 $n$ 是数组 $\textit{nums}$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        mx = max(nums)
        ans = cnt = 0
        for x in nums:
            if x == mx:
                cnt += 1
                ans = max(ans, cnt)
            else:
                cnt = 0
        return ans
```

#### Java

```java
class Solution {
    public int longestSubarray(int[] nums) {
        int mx = Arrays.stream(nums).max().getAsInt();
        int ans = 0, cnt = 0;
        for (int x : nums) {
            if (x == mx) {
                ans = Math.max(ans, ++cnt);
            } else {
                cnt = 0;
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
    int longestSubarray(vector<int>& nums) {
        int mx = ranges::max(nums);
        int ans = 0, cnt = 0;
        for (int x : nums) {
            if (x == mx) {
                ans = max(ans, ++cnt);
            } else {
                cnt = 0;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func longestSubarray(nums []int) (ans int) {
	mx := slices.Max(nums)
	cnt := 0
	for _, x := range nums {
		if x == mx {
			cnt++
			ans = max(ans, cnt)
		} else {
			cnt = 0
		}
	}
	return
}
```

#### TypeScript

```ts
function longestSubarray(nums: number[]): number {
    const mx = Math.max(...nums);
    let [ans, cnt] = [0, 0];
    for (const x of nums) {
        if (x === mx) {
            ans = Math.max(ans, ++cnt);
        } else {
            cnt = 0;
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn longest_subarray(nums: Vec<i32>) -> i32 {
        let mx = *nums.iter().max().unwrap();
        let mut ans = 0;
        let mut cnt = 0;

        for &x in nums.iter() {
            if x == mx {
                cnt += 1;
                ans = ans.max(cnt);
            } else {
                cnt = 0;
            }
        }

        ans
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var longestSubarray = function (nums) {
    const mx = Math.max(...nums);
    let [ans, cnt] = [0, 0];
    for (const x of nums) {
        if (x === mx) {
            ans = Math.max(ans, ++cnt);
        } else {
            cnt = 0;
        }
    }
    return ans;
};
```

#### C#

```cs
public class Solution {
    public int LongestSubarray(int[] nums) {
        int mx = nums.Max();
        int ans = 0, cnt = 0;
        foreach (int x in nums) {
            if (x == mx) {
                ans = Math.Max(ans, ++cnt);
            } else {
                cnt = 0;
            }
        }
        return ans;
    }
}
```

#### PHP

```php
class Solution {
    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function longestSubarray($nums) {
        $mx = max($nums);
        $ans = 0;
        $cnt = 0;

        foreach ($nums as $x) {
            if ($x == $mx) {
                $ans = max($ans, ++$cnt);
            } else {
                $cnt = 0;
            }
        }

        return $ans;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
