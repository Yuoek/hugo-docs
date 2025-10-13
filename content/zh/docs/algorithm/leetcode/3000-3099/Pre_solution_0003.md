---
title: "3020_子集中元素的最大数量"
date: 2025-10-08T18:39:55+08:00
weight: 3
tags: [位运算, 几何, 前缀和, 哈希函数, 哈希表, 字符串, 字符串匹配, 排序, 数学, 数组, 枚举, 模拟, 滑动窗口, 滚动哈希, 贪心]
---

{{< markmap >}}
### [3020_子集中元素的最大数量](#3020)
#### [数组](#3020)
#### [哈希表](#3020)
#### [枚举](#3020)
### [3021_Alice 和 Bob 玩鲜花游戏](#3021)
#### [数学](#3021)
### [3022_给定操作次数内使剩余元素的或值最小](#3022)
#### [贪心](#3022)
#### [位运算](#3022)
#### [数组](#3022)
### [3023_在无限流中寻找模式 I 🔒](#3023)
#### [数组](#3023)
#### [字符串匹配](#3023)
#### [滑动窗口](#3023)
#### [哈希函数](#3023)
#### [滚动哈希](#3023)
### [3024_三角形类型](#3024)
#### [数组](#3024)
#### [数学](#3024)
#### [排序](#3024)
### [3025_人员站位的方案数 I](#3025)
#### [几何](#3025)
#### [数组](#3025)
#### [数学](#3025)
#### [枚举](#3025)
#### [排序](#3025)
### [3026_最大好子数组和](#3026)
#### [数组](#3026)
#### [哈希表](#3026)
#### [前缀和](#3026)
### [3027_人员站位的方案数 II](#3027)
#### [几何](#3027)
#### [数组](#3027)
#### [数学](#3027)
#### [枚举](#3027)
#### [排序](#3027)
### [3028_边界上的蚂蚁](#3028)
#### [数组](#3028)
#### [前缀和](#3028)
#### [模拟](#3028)
### [3029_将单词恢复初始状态所需的最短时间 I](#3029)
#### [字符串](#3029)
#### [字符串匹配](#3029)
#### [哈希函数](#3029)
#### [滚动哈希](#3029)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 3020_子集中元素的最大数量
___
#### 数组
___
#### 哈希表
___
#### 枚举
---
### 3021_Alice 和 Bob 玩鲜花游戏
___
#### 数学
---
### 3022_给定操作次数内使剩余元素的或值最小
___
#### 贪心
___
#### 位运算
___
#### 数组
---
### 3023_在无限流中寻找模式 I 🔒
___
#### 数组
___
#### 字符串匹配
___
#### 滑动窗口
___
#### 哈希函数
___
#### 滚动哈希
---
### 3024_三角形类型
___
#### 数组
___
#### 数学
___
#### 排序
---
### 3025_人员站位的方案数 I
___
#### 几何
___
#### 数组
___
#### 数学
___
#### 枚举
___
#### 排序
---
### 3026_最大好子数组和
___
#### 数组
___
#### 哈希表
___
#### 前缀和
---
### 3027_人员站位的方案数 II
___
#### 几何
___
#### 数组
___
#### 数学
___
#### 枚举
___
#### 排序
---
### 3028_边界上的蚂蚁
___
#### 数组
___
#### 前缀和
___
#### 模拟
---
### 3029_将单词恢复初始状态所需的最短时间 I
___
#### 字符串
___
#### 字符串匹配
___
#### 哈希函数
___
#### 滚动哈希
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 位运算 | 几何 | 前缀和 |
| 哈希函数 | 哈希表 | 字符串 |
| 字符串匹配 | 排序 | 数学 |
| 数组 | 枚举 | 模拟 |
| 滑动窗口 | 滚动哈希 | 贪心 |

# [3020. 子集中元素的最大数量](https://leetcode.cn/problems/find-the-maximum-number-of-elements-in-subset){#3020}

{{< tabs "3020" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumLength(self, nums: List[int]) -> int:
        cnt = Counter(nums)
        ans = cnt[1] - (cnt[1] % 2 ^ 1)
        del cnt[1]
        for x in cnt:
            t = 0
            while cnt[x] > 1:
                x = x * x
                t += 2
            t += 1 if cnt[x] else -1
            ans = max(ans, t)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maximumLength(int[] nums) {
        Map<Long, Integer> cnt = new HashMap<>();
        for (int x : nums) {
            cnt.merge((long) x, 1, Integer::sum);
        }
        Integer t = cnt.remove(1L);
        int ans = t == null ? 0 : t - (t % 2 ^ 1);
        for (long x : cnt.keySet()) {
            t = 0;
            while (cnt.getOrDefault(x, 0) > 1) {
                x = x * x;
                t += 2;
            }
            t += cnt.getOrDefault(x, -1);
            ans = Math.max(ans, t);
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
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> cnt;
        for (int x : nums) {
            ++cnt[x];
        }
        int ans = cnt[1] - (cnt[1] % 2 ^ 1);
        cnt.erase(1);
        for (auto [v, _] : cnt) {
            int t = 0;
            long long x = v;
            while (cnt.count(x) && cnt[x] > 1) {
                x = x * x;
                t += 2;
            }
            t += cnt.count(x) ? 1 : -1;
            ans = max(ans, t);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumLength(nums []int) (ans int) {
	cnt := map[int]int{}
	for _, x := range nums {
		cnt[x]++
	}
	ans = cnt[1] - (cnt[1]%2 ^ 1)
	delete(cnt, 1)
	for x := range cnt {
		t := 0
		for cnt[x] > 1 {
			x = x * x
			t += 2
		}
		if cnt[x] > 0 {
			t += 1
		} else {
			t -= 1
		}
		ans = max(ans, t)
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumLength(nums: number[]): number {
    const cnt: Map<number, number> = new Map();
    for (const x of nums) {
        cnt.set(x, (cnt.get(x) ?? 0) + 1);
    }
    let ans = cnt.has(1) ? cnt.get(1)! - (cnt.get(1)! % 2 ^ 1) : 0;
    cnt.delete(1);
    for (let [x, _] of cnt) {
        let t = 0;
        while (cnt.has(x) && cnt.get(x)! > 1) {
            x = x * x;
            t += 2;
        }
        t += cnt.has(x) ? 1 : -1;
        ans = Math.max(ans, t);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashMap;

impl Solution {
    pub fn maximum_length(nums: Vec<i32>) -> i32 {
        let mut cnt: HashMap<i64, i32> = HashMap::new();
        for &x in &nums {
            *cnt.entry(x as i64).or_insert(0) += 1;
        }

        let mut ans = 0;
        if let Some(t) = cnt.remove(&1) {
            ans = t - ((t % 2) ^ 1);
        }

        for &key in cnt.keys() {
            let mut x = key;
            let mut t = 0;
            while *cnt.get(&x).unwrap_or(&0) > 1 {
                x = x * x;
                t += 2;
            }
            t += cnt.get(&x).unwrap_or(&-1);
            ans = ans.max(t);
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

<p>给你一个<strong> 正整数 </strong>数组 <code>nums</code> 。</p>

<p>你需要从数组中选出一个满足下述条件的<span data-keyword="subset">子集</span>：</p>

<ul>
	<li>你可以将选中的元素放置在一个下标从 <strong>0</strong> 开始的数组中，并使其遵循以下模式：<code>[x, x<sup>2</sup>, x<sup>4</sup>, ..., x<sup>k/2</sup>, x<sup>k</sup>, x<sup>k/2</sup>, ..., x<sup>4</sup>, x<sup>2</sup>, x]</code>（<strong>注意</strong>，<code>k</code> 可以是任何 <strong>非负</strong> 的 2 的幂）。例如，<code>[2, 4, 16, 4, 2]</code> 和 <code>[3, 9, 3]</code> 都符合这一模式，而 <code>[2, 4, 8, 4, 2]</code> 则不符合。</li>
</ul>

<p>返回满足这些条件的子集中，元素数量的 <strong>最大值 </strong><em>。</em></p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [5,4,1,2,2]
<strong>输出：</strong>3
<strong>解释：</strong>选择子集 {4,2,2} ，将其放在数组 [2,4,2] 中，它遵循该模式，且 2<sup>2</sup> == 4 。因此答案是 3 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,3,2,4]
<strong>输出：</strong>1
<strong>解释：</strong>选择子集 {1}，将其放在数组 [1] 中，它遵循该模式。因此答案是 1 。注意我们也可以选择子集 {2} 、{4} 或 {3} ，可能存在多个子集都能得到相同的答案。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 枚举

我们用一个哈希表 $cnt$ 记录数组 $nums$ 中每个元素出现的次数。对于每个元素 $x$，我们可以将其不断平方，直到其值在哈希表 $cnt$ 中的出现次数小于 $2$ 为止。此时，我们判断 $x$ 在哈希表 $cnt$ 中的出现次数是否为 $1$，如果是则说明 $x$ 仍然可以被选入子集中，否则我们需要从子集中删除一个元素，确保子集个数为奇数。然后我们更新答案。继续枚举下一个元素。

注意我们需要特殊处理 $x = 1$ 的情况。

时间复杂度 $O(n \times \log \log M)$，空间复杂度 $O(n)$。其中 $n$ 和 $M$ 分别是数组 $nums$ 的长度和数组 $nums$ 中的最大值。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumLength(self, nums: List[int]) -> int:
        cnt = Counter(nums)
        ans = cnt[1] - (cnt[1] % 2 ^ 1)
        del cnt[1]
        for x in cnt:
            t = 0
            while cnt[x] > 1:
                x = x * x
                t += 2
            t += 1 if cnt[x] else -1
            ans = max(ans, t)
        return ans
```

#### Java

```java
class Solution {
    public int maximumLength(int[] nums) {
        Map<Long, Integer> cnt = new HashMap<>();
        for (int x : nums) {
            cnt.merge((long) x, 1, Integer::sum);
        }
        Integer t = cnt.remove(1L);
        int ans = t == null ? 0 : t - (t % 2 ^ 1);
        for (long x : cnt.keySet()) {
            t = 0;
            while (cnt.getOrDefault(x, 0) > 1) {
                x = x * x;
                t += 2;
            }
            t += cnt.getOrDefault(x, -1);
            ans = Math.max(ans, t);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> cnt;
        for (int x : nums) {
            ++cnt[x];
        }
        int ans = cnt[1] - (cnt[1] % 2 ^ 1);
        cnt.erase(1);
        for (auto [v, _] : cnt) {
            int t = 0;
            long long x = v;
            while (cnt.count(x) && cnt[x] > 1) {
                x = x * x;
                t += 2;
            }
            t += cnt.count(x) ? 1 : -1;
            ans = max(ans, t);
        }
        return ans;
    }
};
```

#### Go

```go
func maximumLength(nums []int) (ans int) {
	cnt := map[int]int{}
	for _, x := range nums {
		cnt[x]++
	}
	ans = cnt[1] - (cnt[1]%2 ^ 1)
	delete(cnt, 1)
	for x := range cnt {
		t := 0
		for cnt[x] > 1 {
			x = x * x
			t += 2
		}
		if cnt[x] > 0 {
			t += 1
		} else {
			t -= 1
		}
		ans = max(ans, t)
	}
	return
}
```

#### TypeScript

```ts
function maximumLength(nums: number[]): number {
    const cnt: Map<number, number> = new Map();
    for (const x of nums) {
        cnt.set(x, (cnt.get(x) ?? 0) + 1);
    }
    let ans = cnt.has(1) ? cnt.get(1)! - (cnt.get(1)! % 2 ^ 1) : 0;
    cnt.delete(1);
    for (let [x, _] of cnt) {
        let t = 0;
        while (cnt.has(x) && cnt.get(x)! > 1) {
            x = x * x;
            t += 2;
        }
        t += cnt.has(x) ? 1 : -1;
        ans = Math.max(ans, t);
    }
    return ans;
}
```

#### Rust

```rust
use std::collections::HashMap;

impl Solution {
    pub fn maximum_length(nums: Vec<i32>) -> i32 {
        let mut cnt: HashMap<i64, i32> = HashMap::new();
        for &x in &nums {
            *cnt.entry(x as i64).or_insert(0) += 1;
        }

        let mut ans = 0;
        if let Some(t) = cnt.remove(&1) {
            ans = t - ((t % 2) ^ 1);
        }

        for &key in cnt.keys() {
            let mut x = key;
            let mut t = 0;
            while *cnt.get(&x).unwrap_or(&0) > 1 {
                x = x * x;
                t += 2;
            }
            t += cnt.get(&x).unwrap_or(&-1);
            ans = ans.max(t);
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

# [3021. Alice 和 Bob 玩鲜花游戏](https://leetcode.cn/problems/alice-and-bob-playing-flower-game){#3021}

{{< tabs "3021" >}}

{{% tab "python" %}}
```python
class Solution:
    def flowerGame(self, n: int, m: int) -> int:
        return (n * m) // 2
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long flowerGame(int n, int m) {
        return ((long) n * m) / 2;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    long long flowerGame(int n, int m) {
        return ((long long) n * m) / 2;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func flowerGame(n int, m int) int64 {
	return int64((n * m) / 2)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function flowerGame(n: number, m: number): number {
    return Number(((BigInt(n) * BigInt(m)) / 2n) | 0n);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn flower_game(n: i32, m: i32) -> i64 {
        (n as i64 * m as i64) / 2
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number} n
 * @param {number} m
 * @return {number}
 */
var flowerGame = function (n, m) {
    return Number(((BigInt(n) * BigInt(m)) / 2n) | 0n);
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>Alice 和 Bob 在一片田野上玩一个回合制游戏，他们之间有两排花。Alice 和 Bob 之间第一排有 <code>x</code> 朵花，第二排有 <code>y</code> 朵花。</p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3000-3099/3021.Alice%20and%20Bob%20Playing%20Flower%20Game/images/3021.png" style="width: 300px; height: 150px;" /></p>

<p>游戏过程如下：</p>

<ol>
	<li>Alice 先行动。</li>
	<li>每一次行动中，当前玩家必须选择其中一排，然后在这边摘一朵鲜花。</li>
	<li>一次行动结束后，如果两排上都没有剩下鲜花，那么 <strong>当前</strong>&nbsp;玩家抓住对手并赢得游戏的胜利。</li>
</ol>

<p>给你两个整数&nbsp;<code>n</code>&nbsp;和&nbsp;<code>m</code>&nbsp;，你的任务是求出满足以下条件的所有&nbsp;<code>(x, y)</code>&nbsp;对：</p>

<ul>
	<li>按照上述规则，Alice 必须赢得游戏。</li>
	<li>第一排的鲜花数目&nbsp;<code>x</code>&nbsp;必须在区间&nbsp;<code>[1,n]</code>&nbsp;之间。</li>
	<li>第二排的鲜花数目 <code>y</code>&nbsp;必须在区间&nbsp;<code>[1,m]</code>&nbsp;之间。</li>
</ul>

<p>请你返回满足题目描述的数对&nbsp;<code>(x, y)</code>&nbsp;的数目。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>n = 3, m = 2
<b>输出：</b>3
<b>解释：</b>以下数对满足题目要求：(1,2) ，(3,2) ，(2,1) 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>n = 1, m = 1
<b>输出：</b>0
<b>解释：</b>没有数对满足题目要求。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n, m &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数学

根据题目描述，每一次行动，玩家都会选择顺时针或者逆时针方向，然后摘一朵鲜花。由于 Alice 先行动，因此当 $x + y$ 为奇数时，Alice 一定会赢得游戏。

因此，鲜花数目 $x$ 和 $y$ 满足以下条件：

1. $x + y$ 为奇数；
2. $1 \le x \le n$；
3. $1 \le y \le m$。

若 $x$ 为奇数，$y$ 一定为偶数。此时 $x$ 的取值个数为 $\lceil \frac{n}{2} \rceil$，$y$ 的取值个数为 $\lfloor \frac{m}{2} \rfloor$，因此满足条件的数对个数为 $\lceil \frac{n}{2} \rceil \times \lfloor \frac{m}{2} \rfloor$。

若 $x$ 为偶数，$y$ 一定为奇数。此时 $x$ 的取值个数为 $\lfloor \frac{n}{2} \rfloor$，$y$ 的取值个数为 $\lceil \frac{m}{2} \rceil$，因此满足条件的数对个数为 $\lfloor \frac{n}{2} \rfloor \times \lceil \frac{m}{2} \rceil$。

因此，满足条件的数对个数为 $\lceil \frac{n}{2} \rceil \times \lfloor \frac{m}{2} \rfloor + \lfloor \frac{n}{2} \rfloor \times \lceil \frac{m}{2} \rceil$，即 $\lfloor \frac{n + 1}{2} \rfloor \times \lfloor \frac{m}{2} \rfloor + \lfloor \frac{n}{2} \rfloor \times \lfloor \frac{m + 1}{2} \rfloor$。

时间复杂度 $O(1)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def flowerGame(self, n: int, m: int) -> int:
        a1 = (n + 1) // 2
        b1 = (m + 1) // 2
        a2 = n // 2
        b2 = m // 2
        return a1 * b2 + a2 * b1
```

#### Java

```java
class Solution {
    public long flowerGame(int n, int m) {
        long a1 = (n + 1) / 2;
        long b1 = (m + 1) / 2;
        long a2 = n / 2;
        long b2 = m / 2;
        return a1 * b2 + a2 * b1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long flowerGame(int n, int m) {
        long long a1 = (n + 1) / 2;
        long long b1 = (m + 1) / 2;
        long long a2 = n / 2;
        long long b2 = m / 2;
        return a1 * b2 + a2 * b1;
    }
};
```

#### Go

```go
func flowerGame(n int, m int) int64 {
	a1, b1 := (n+1)/2, (m+1)/2
	a2, b2 := n/2, m/2
	return int64(a1*b2 + a2*b1)
}
```

#### TypeScript

```ts
function flowerGame(n: number, m: number): number {
    const [a1, b1] = [(n + 1) >> 1, (m + 1) >> 1];
    const [a2, b2] = [n >> 1, m >> 1];
    return a1 * b2 + a2 * b1;
}
```

#### Rust

```rust
impl Solution {
    pub fn flower_game(n: i32, m: i32) -> i64 {
        let a1 = ((n + 1) / 2) as i64;
        let b1 = ((m + 1) / 2) as i64;
        let a2 = (n / 2) as i64;
        let b2 = (m / 2) as i64;
        a1 * b2 + a2 * b1
    }
}
```

#### JavaScript

```js
/**
 * @param {number} n
 * @param {number} m
 * @return {number}
 */
var flowerGame = function (n, m) {
    const [a1, b1] = [(n + 1) >> 1, (m + 1) >> 1];
    const [a2, b2] = [n >> 1, m >> 1];
    return a1 * b2 + a2 * b1;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：数学（优化）

方法一得出的结果为 $\lfloor \frac{n + 1}{2} \rfloor \times \lfloor \frac{m}{2} \rfloor + \lfloor \frac{n}{2} \rfloor \times \lfloor \frac{m + 1}{2} \rfloor$。

如果 $n$ 和 $m$ 都是奇数，那么结果为 $\frac{n + 1}{2} \times \frac{m - 1}{2} + \frac{n - 1}{2} \times \frac{m + 1}{2}$，即 $\frac{n \times m - 1}{2}$。

如果 $n$ 和 $m$ 都是偶数，那么结果为 $\frac{n}{2} \times \frac{m}{2} + \frac{n}{2} \times \frac{m}{2}$，即 $\frac{n \times m}{2}$。

如果 $n$ 是奇数，且 $m$ 是偶数，那么结果为 $\frac{n + 1}{2} \times \frac{m}{2} + \frac{n - 1}{2} \times \frac{m}{2}$，即 $\frac{n \times m}{2}$。

如果 $n$ 是偶数，且 $m$ 是奇数，那么结果为 $\frac{n}{2} \times \frac{m - 1}{2} + \frac{n}{2} \times \frac{m + 1}{2}$，即 $\frac{n \times m}{2}$。

上面四种情况可以合并为 $\lfloor \frac{n \times m}{2} \rfloor$。

时间复杂度 $O(1)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def flowerGame(self, n: int, m: int) -> int:
        return (n * m) // 2
```

#### Java

```java
class Solution {
    public long flowerGame(int n, int m) {
        return ((long) n * m) / 2;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long flowerGame(int n, int m) {
        return ((long long) n * m) / 2;
    }
};
```

#### Go

```go
func flowerGame(n int, m int) int64 {
	return int64((n * m) / 2)
}
```

#### TypeScript

```ts
function flowerGame(n: number, m: number): number {
    return Number(((BigInt(n) * BigInt(m)) / 2n) | 0n);
}
```

#### Rust

```rust
impl Solution {
    pub fn flower_game(n: i32, m: i32) -> i64 {
        (n as i64 * m as i64) / 2
    }
}
```

#### JavaScript

```js
/**
 * @param {number} n
 * @param {number} m
 * @return {number}
 */
var flowerGame = function (n, m) {
    return Number(((BigInt(n) * BigInt(m)) / 2n) | 0n);
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3022. 给定操作次数内使剩余元素的或值最小](https://leetcode.cn/problems/minimize-or-of-remaining-elements-using-operations){#3022}

{{< tabs "3022" >}}

{{% tab "python" %}}
```python
class Solution:
    def minOrAfterOperations(self, nums: List[int], k: int) -> int:
        ans = 0
        rans = 0
        for i in range(29, -1, -1):
            test = ans + (1 << i)
            cnt = 0
            val = 0
            for num in nums:
                if val == 0:
                    val = test & num
                else:
                    val &= test & num
                if val:
                    cnt += 1
            if cnt > k:
                rans += 1 << i
            else:
                ans += 1 << i
        return rans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minOrAfterOperations(int[] nums, int k) {
        int ans = 0, rans = 0;
        for (int i = 29; i >= 0; i--) {
            int test = ans + (1 << i);
            int cnt = 0;
            int val = 0;
            for (int num : nums) {
                if (val == 0) {
                    val = test & num;
                } else {
                    val &= test & num;
                }
                if (val != 0) {
                    cnt++;
                }
            }
            if (cnt > k) {
                rans += (1 << i);
            } else {
                ans += (1 << i);
            }
        }
        return rans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minOrAfterOperations(vector<int>& nums, int k) {
        int ans = 0, rans = 0;
        for (int i = 29; i >= 0; i--) {
            int test = ans + (1 << i);
            int cnt = 0;
            int val = 0;
            for (auto it : nums) {
                if (val == 0) {
                    val = test & it;
                } else {
                    val &= test & it;
                }
                if (val) {
                    cnt++;
                }
            }
            if (cnt > k) {
                rans += (1 << i);
            } else {
                ans += (1 << i);
            }
        }
        return rans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minOrAfterOperations(nums []int, k int) int {
    ans := 0
    rans := 0
    for i := 29; i >= 0; i-- {
        test := ans + (1 << i)
        cnt := 0
        val := 0
        for _, num := range nums {
            if val == 0 {
                val = test & num
            } else {
                val &= test & num
            }
            if val != 0 {
                cnt++
            }
        }
        if cnt > k {
            rans += (1 << i)
        } else {
            ans += (1 << i)
        }
    }
    return rans
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>nums</code>&nbsp;和一个整数&nbsp;<code>k</code>&nbsp;。</p>

<p>一次操作中，你可以选择 <code>nums</code>&nbsp;中满足&nbsp;<code>0 &lt;= i &lt; nums.length - 1</code>&nbsp;的一个下标 <code>i</code>&nbsp;，并将&nbsp;<code>nums[i]</code> 和&nbsp;<code>nums[i + 1]</code>&nbsp;替换为数字&nbsp;<code>nums[i] &amp; nums[i + 1]</code>&nbsp;，其中&nbsp;<code>&amp;</code>&nbsp;表示按位&nbsp;<code>AND</code>&nbsp;操作。</p>

<p>请你返回 <strong>至多</strong>&nbsp;<code>k</code>&nbsp;次操作以内，使 <code>nums</code>&nbsp;中所有剩余元素按位 <code>OR</code>&nbsp;结果的 <strong>最小值</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [3,5,3,2,7], k = 2
<b>输出：</b>3
<b>解释：</b>执行以下操作：
1. 将 nums[0] 和 nums[1] 替换为 (nums[0] &amp; nums[1]) ，得到 nums 为 [1,3,2,7] 。
2. 将 nums[2] 和 nums[3] 替换为 (nums[2] &amp; nums[3]) ，得到 nums 为 [1,3,2] 。
最终数组的按位或值为 3 。
3 是 k 次操作以内，可以得到的剩余元素的最小按位或值。</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [7,3,15,14,2,8], k = 4
<b>输出：</b>2
<b>解释：</b>执行以下操作：
1. 将 nums[0] 和 nums[1] 替换为 (nums[0] &amp; nums[1]) ，得到 nums 为 [3,15,14,2,8] 。
2. 将 nums[0] 和 nums[1] 替换为 (nums[0] &amp; nums[1]) ，得到 nums 为 [3,14,2,8] 。
3. 将 nums[0] 和 nums[1] 替换为 (nums[0] &amp; nums[1]) ，得到 nums 为 [2,2,8] 。
4. 将 nums[1] 和 nums[2] 替换为 (nums[1] &amp; nums[2]) ，得到 nums 为 [2,0] 。
最终数组的按位或值为 2 。
2 是 k 次操作以内，可以得到的剩余元素的最小按位或值。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>nums = [10,7,10,3,9,14,9,4], k = 1
<b>输出：</b>15
<b>解释：</b>不执行任何操作，nums 的按位或值为 15 。
15 是 k 次操作以内，可以得到的剩余元素的最小按位或值。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt; 2<sup>30</sup></code></li>
	<li><code>0 &lt;= k &lt; nums.length</code></li>
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
    def minOrAfterOperations(self, nums: List[int], k: int) -> int:
        ans = 0
        rans = 0
        for i in range(29, -1, -1):
            test = ans + (1 << i)
            cnt = 0
            val = 0
            for num in nums:
                if val == 0:
                    val = test & num
                else:
                    val &= test & num
                if val:
                    cnt += 1
            if cnt > k:
                rans += 1 << i
            else:
                ans += 1 << i
        return rans
```

#### Java

```java
class Solution {
    public int minOrAfterOperations(int[] nums, int k) {
        int ans = 0, rans = 0;
        for (int i = 29; i >= 0; i--) {
            int test = ans + (1 << i);
            int cnt = 0;
            int val = 0;
            for (int num : nums) {
                if (val == 0) {
                    val = test & num;
                } else {
                    val &= test & num;
                }
                if (val != 0) {
                    cnt++;
                }
            }
            if (cnt > k) {
                rans += (1 << i);
            } else {
                ans += (1 << i);
            }
        }
        return rans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minOrAfterOperations(vector<int>& nums, int k) {
        int ans = 0, rans = 0;
        for (int i = 29; i >= 0; i--) {
            int test = ans + (1 << i);
            int cnt = 0;
            int val = 0;
            for (auto it : nums) {
                if (val == 0) {
                    val = test & it;
                } else {
                    val &= test & it;
                }
                if (val) {
                    cnt++;
                }
            }
            if (cnt > k) {
                rans += (1 << i);
            } else {
                ans += (1 << i);
            }
        }
        return rans;
    }
};
```

#### Go

```go
func minOrAfterOperations(nums []int, k int) int {
    ans := 0
    rans := 0
    for i := 29; i >= 0; i-- {
        test := ans + (1 << i)
        cnt := 0
        val := 0
        for _, num := range nums {
            if val == 0 {
                val = test & num
            } else {
                val &= test & num
            }
            if val != 0 {
                cnt++
            }
        }
        if cnt > k {
            rans += (1 << i)
        } else {
            ans += (1 << i)
        }
    }
    return rans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3023. 在无限流中寻找模式 I 🔒](https://leetcode.cn/problems/find-pattern-in-infinite-stream-i){#3023}

{{< tabs "3023" >}}

{{% tab "python" %}}
```python
# Definition for an infinite stream.
# class InfiniteStream:
#     def next(self) -> int:
#         pass
class Solution:
    def findPattern(
        self, stream: Optional["InfiniteStream"], pattern: List[int]
    ) -> int:
        a = b = 0
        m = len(pattern)
        half = m >> 1
        mask1 = (1 << half) - 1
        mask2 = (1 << (m - half)) - 1
        for i in range(half):
            a |= pattern[i] << (half - 1 - i)
        for i in range(half, m):
            b |= pattern[i] << (m - 1 - i)
        x = y = 0
        for i in count(1):
            v = stream.next()
            y = y << 1 | v
            v = y >> (m - half) & 1
            y &= mask2
            x = x << 1 | v
            x &= mask1
            if i >= m and a == x and b == y:
                return i - m
```
{{% /tab %}}
{{% tab "java" %}}
```java
/**
 * Definition for an infinite stream.
 * class InfiniteStream {
 *     public InfiniteStream(int[] bits);
 *     public int next();
 * }
 */
class Solution {
    public int findPattern(InfiniteStream infiniteStream, int[] pattern) {
        long a = 0, b = 0;
        int m = pattern.length;
        int half = m >> 1;
        long mask1 = (1L << half) - 1;
        long mask2 = (1L << (m - half)) - 1;
        for (int i = 0; i < half; ++i) {
            a |= (long) pattern[i] << (half - 1 - i);
        }
        for (int i = half; i < m; ++i) {
            b |= (long) pattern[i] << (m - 1 - i);
        }
        long x = 0, y = 0;
        for (int i = 1;; ++i) {
            int v = infiniteStream.next();
            y = y << 1 | v;
            v = (int) ((y >> (m - half)) & 1);
            y &= mask2;
            x = x << 1 | v;
            x &= mask1;
            if (i >= m && a == x && b == y) {
                return i - m;
            }
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
/**
 * Definition for an infinite stream.
 * class InfiniteStream {
 * public:
 *     InfiniteStream(vector<int> bits);
 *     int next();
 * };
 */
class Solution {
public:
    int findPattern(InfiniteStream* stream, vector<int>& pattern) {
        long long a = 0, b = 0;
        int m = pattern.size();
        int half = m >> 1;
        long long mask1 = (1LL << half) - 1;
        long long mask2 = (1LL << (m - half)) - 1;
        for (int i = 0; i < half; ++i) {
            a |= (long long) pattern[i] << (half - 1 - i);
        }
        for (int i = half; i < m; ++i) {
            b |= (long long) pattern[i] << (m - 1 - i);
        }
        long x = 0, y = 0;
        for (int i = 1;; ++i) {
            int v = stream->next();
            y = y << 1 | v;
            v = (int) ((y >> (m - half)) & 1);
            y &= mask2;
            x = x << 1 | v;
            x &= mask1;
            if (i >= m && a == x && b == y) {
                return i - m;
            }
        }
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
/**
 * Definition for an infinite stream.
 * type InfiniteStream interface {
 *     Next() int
 * }
 */
 func findPattern(stream InfiniteStream, pattern []int) int {
	a, b := 0, 0
	m := len(pattern)
	half := m >> 1
	mask1 := (1 << half) - 1
	mask2 := (1 << (m - half)) - 1
	for i := 0; i < half; i++ {
		a |= pattern[i] << (half - 1 - i)
	}
	for i := half; i < m; i++ {
		b |= pattern[i] << (m - 1 - i)
	}
	x, y := 0, 0
	for i := 1; ; i++ {
		v := stream.Next()
		y = y<<1 | v
		v = (y >> (m - half)) & 1
		y &= mask2
		x = x<<1 | v
		x &= mask1
		if i >= m && a == x && b == y {
			return i - m
		}
	}
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个二进制数组&nbsp;<code>pattern</code>&nbsp;和一个类 <code>InfiniteStream</code>&nbsp;的对象&nbsp;<code>stream</code>&nbsp;表示一个下标从 <strong>0</strong>&nbsp;开始的二进制位无限流。</p>

<p>类&nbsp;<code>InfiniteStream</code>&nbsp;包含下列函数：</p>

<ul>
	<li><code>int next()</code>：从流中读取 <strong>一个</strong>&nbsp;二进制位&nbsp;（是&nbsp;<code>0</code>&nbsp;或&nbsp;<code>1</code>）并返回。</li>
</ul>

<p>返回<em>&nbsp;<strong>第一个使得模式匹配流中读取的二进制位的 </strong>开始下标</em>。例如，如果模式是&nbsp;<code>[1, 0]</code>，第一个匹配是流中的高亮部分&nbsp;<code>[0, <strong><u>1, 0</u></strong>, 1, ...]</code>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入:</strong> stream = [1,1,1,0,1,1,1,...], pattern = [0,1]
<strong>输出:</strong> 3
<strong>解释:</strong> 模式 [0,1] 的第一次出现在流中高亮 [1,1,1,<strong><u>0,1</u></strong>,...]，从下标 3 开始。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入:</strong> stream = [0,0,0,0,...], pattern = [0]
<strong>输出:</strong> 0
<strong>解释:</strong> 模式 [0] 的第一次出现在流中高亮 [<strong><u>0</u></strong>,...]，从下标 0 开始。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入:</strong> stream = [1,0,1,1,0,1,1,0,1,...], pattern = [1,1,0,1]
<strong>输出:</strong> 2
<strong>解释:</strong> 模式 [1,1,0,1] 的第一次出现在流中高亮 [1,0,<strong><u>1,1,0,1</u></strong>,...]，从下标 2 开始。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= pattern.length &lt;= 100</code></li>
	<li><code>pattern</code>&nbsp;只包含&nbsp;<code>0</code>&nbsp;或&nbsp;<code>1</code>。</li>
	<li><code>stream</code> 只包含&nbsp;<code>0</code>&nbsp;或&nbsp;<code>1</code>。</li>
	<li>生成的输入使模式的开始下标在流的前&nbsp;<code>10<sup>5</sup></code>&nbsp;个二进制位中。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：位运算 + 滑动窗口

我们注意到，数组 $pattern$ 的长度不超过 $100$，因此，我们可以用两个 $64$ 位的整数 $a$ 和 $b$ 来表示 $pattern$ 左右两半的二进制数。

接下来，我们遍历数据流，同样维护两个 $64$ 位的整数 $x$ 和 $y$ 表示当前 $pattern$ 长度的窗口的二进制数。如果当前达到了窗口的长度，我们比较 $a$ 和 $x$ 是否相等，以及 $b$ 和 $y$ 是否相等，如果是，我们返回当前数据流的索引即可。

时间复杂度 $O(n + m)$，其中 $n$ 和 $m$ 分别是数据流和 $pattern$ 的元素个数。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
# Definition for an infinite stream.
# class InfiniteStream:
#     def next(self) -> int:
#         pass
class Solution:
    def findPattern(
        self, stream: Optional["InfiniteStream"], pattern: List[int]
    ) -> int:
        a = b = 0
        m = len(pattern)
        half = m >> 1
        mask1 = (1 << half) - 1
        mask2 = (1 << (m - half)) - 1
        for i in range(half):
            a |= pattern[i] << (half - 1 - i)
        for i in range(half, m):
            b |= pattern[i] << (m - 1 - i)
        x = y = 0
        for i in count(1):
            v = stream.next()
            y = y << 1 | v
            v = y >> (m - half) & 1
            y &= mask2
            x = x << 1 | v
            x &= mask1
            if i >= m and a == x and b == y:
                return i - m
```

#### Java

```java
/**
 * Definition for an infinite stream.
 * class InfiniteStream {
 *     public InfiniteStream(int[] bits);
 *     public int next();
 * }
 */
class Solution {
    public int findPattern(InfiniteStream infiniteStream, int[] pattern) {
        long a = 0, b = 0;
        int m = pattern.length;
        int half = m >> 1;
        long mask1 = (1L << half) - 1;
        long mask2 = (1L << (m - half)) - 1;
        for (int i = 0; i < half; ++i) {
            a |= (long) pattern[i] << (half - 1 - i);
        }
        for (int i = half; i < m; ++i) {
            b |= (long) pattern[i] << (m - 1 - i);
        }
        long x = 0, y = 0;
        for (int i = 1;; ++i) {
            int v = infiniteStream.next();
            y = y << 1 | v;
            v = (int) ((y >> (m - half)) & 1);
            y &= mask2;
            x = x << 1 | v;
            x &= mask1;
            if (i >= m && a == x && b == y) {
                return i - m;
            }
        }
    }
}
```

#### C++

```cpp
/**
 * Definition for an infinite stream.
 * class InfiniteStream {
 * public:
 *     InfiniteStream(vector<int> bits);
 *     int next();
 * };
 */
class Solution {
public:
    int findPattern(InfiniteStream* stream, vector<int>& pattern) {
        long long a = 0, b = 0;
        int m = pattern.size();
        int half = m >> 1;
        long long mask1 = (1LL << half) - 1;
        long long mask2 = (1LL << (m - half)) - 1;
        for (int i = 0; i < half; ++i) {
            a |= (long long) pattern[i] << (half - 1 - i);
        }
        for (int i = half; i < m; ++i) {
            b |= (long long) pattern[i] << (m - 1 - i);
        }
        long x = 0, y = 0;
        for (int i = 1;; ++i) {
            int v = stream->next();
            y = y << 1 | v;
            v = (int) ((y >> (m - half)) & 1);
            y &= mask2;
            x = x << 1 | v;
            x &= mask1;
            if (i >= m && a == x && b == y) {
                return i - m;
            }
        }
    }
};
```

#### Go

```go
/**
 * Definition for an infinite stream.
 * type InfiniteStream interface {
 *     Next() int
 * }
 */
 func findPattern(stream InfiniteStream, pattern []int) int {
	a, b := 0, 0
	m := len(pattern)
	half := m >> 1
	mask1 := (1 << half) - 1
	mask2 := (1 << (m - half)) - 1
	for i := 0; i < half; i++ {
		a |= pattern[i] << (half - 1 - i)
	}
	for i := half; i < m; i++ {
		b |= pattern[i] << (m - 1 - i)
	}
	x, y := 0, 0
	for i := 1; ; i++ {
		v := stream.Next()
		y = y<<1 | v
		v = (y >> (m - half)) & 1
		y &= mask2
		x = x<<1 | v
		x &= mask1
		if i >= m && a == x && b == y {
			return i - m
		}
	}
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3024. 三角形类型](https://leetcode.cn/problems/type-of-triangle){#3024}

{{< tabs "3024" >}}

{{% tab "python" %}}
```python
class Solution:
    def triangleType(self, nums: List[int]) -> str:
        nums.sort()
        if nums[0] + nums[1] <= nums[2]:
            return "none"
        if nums[0] == nums[2]:
            return "equilateral"
        if nums[0] == nums[1] or nums[1] == nums[2]:
            return "isosceles"
        return "scalene"
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String triangleType(int[] nums) {
        Arrays.sort(nums);
        if (nums[0] + nums[1] <= nums[2]) {
            return "none";
        }
        if (nums[0] == nums[2]) {
            return "equilateral";
        }
        if (nums[0] == nums[1] || nums[1] == nums[2]) {
            return "isosceles";
        }
        return "scalene";
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string triangleType(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums[0] + nums[1] <= nums[2]) {
            return "none";
        }
        if (nums[0] == nums[2]) {
            return "equilateral";
        }
        if (nums[0] == nums[1] || nums[1] == nums[2]) {
            return "isosceles";
        }
        return "scalene";
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func triangleType(nums []int) string {
	sort.Ints(nums)
	if nums[0]+nums[1] <= nums[2] {
		return "none"
	}
	if nums[0] == nums[2] {
		return "equilateral"
	}
	if nums[0] == nums[1] || nums[1] == nums[2] {
		return "isosceles"
	}
	return "scalene"
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function triangleType(nums: number[]): string {
    nums.sort((a, b) => a - b);
    if (nums[0] + nums[1] <= nums[2]) {
        return 'none';
    }
    if (nums[0] === nums[2]) {
        return 'equilateral';
    }
    if (nums[0] === nums[1] || nums[1] === nums[2]) {
        return 'isosceles';
    }
    return 'scalene';
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public string TriangleType(int[] nums) {
        Array.Sort(nums);
        if (nums[0] + nums[1] <= nums[2]) {
            return "none";
        }
        if (nums[0] == nums[2]) {
            return "equilateral";
        }
        if (nums[0] == nums[1] || nums[1] == nums[2]) {
            return "isosceles";
        }
        return "scalene";
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong>&nbsp;开始长度为 <code>3</code>&nbsp;的整数数组&nbsp;<code>nums</code>&nbsp;，需要用它们来构造三角形。</p>

<ul>
	<li>如果一个三角形的所有边长度相等，那么这个三角形称为&nbsp;<strong>equilateral</strong>&nbsp;。</li>
	<li>如果一个三角形恰好有两条边长度相等，那么这个三角形称为&nbsp;<strong>isosceles</strong>&nbsp;。</li>
	<li>如果一个三角形三条边的长度互不相同，那么这个三角形称为&nbsp;<strong>scalene</strong>&nbsp;。</li>
</ul>

<p>如果这个数组无法构成一个三角形，请你返回字符串&nbsp;<code>"none"</code>&nbsp;，否则返回一个字符串表示这个三角形的类型。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [3,3,3]
<b>输出：</b>"equilateral"
<b>解释：</b>由于三条边长度相等，所以可以构成一个等边三角形，返回 "equilateral" 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [3,4,5]
<b>输出：</b>"scalene"
<b>解释：</b>
nums[0] + nums[1] = 3 + 4 = 7 ，大于 nums[2] = 5 <span style="text-wrap: wrap;">。</span>
nums[0] + nums[2] = 3 + 5 = 8 ，大于 nums[1] = 4 。
nums[1] + nums[2] = 4 + 5 = 9 ，大于 nums[0] = 3 。
由于任意两边之和都大于第三边，所以可以构成一个三角形，因为三条边的长度互不相等，所以返回 "scalene"。
</pre>

<p><strong>提示：</strong></p>

<ul>
	<li><code>nums.length == 3</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 分类讨论

我们先对数组进行排序，然后根据三角形的定义进行分类讨论即可。

-   如果最小的两个数之和小于等于最大的数，那么无法构成三角形，返回 "none"。
-   如果最小的数等于最大的数，那么是等边三角形，返回 "equilateral"。
-   如果最小的数等于中间的数或者中间的数等于最大的数，那么是等腰三角形，返回 "isosceles"。
-   否则，返回 "scalene"。

时间复杂度 $O(1)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def triangleType(self, nums: List[int]) -> str:
        nums.sort()
        if nums[0] + nums[1] <= nums[2]:
            return "none"
        if nums[0] == nums[2]:
            return "equilateral"
        if nums[0] == nums[1] or nums[1] == nums[2]:
            return "isosceles"
        return "scalene"
```

#### Java

```java
class Solution {
    public String triangleType(int[] nums) {
        Arrays.sort(nums);
        if (nums[0] + nums[1] <= nums[2]) {
            return "none";
        }
        if (nums[0] == nums[2]) {
            return "equilateral";
        }
        if (nums[0] == nums[1] || nums[1] == nums[2]) {
            return "isosceles";
        }
        return "scalene";
    }
}
```

#### C++

```cpp
class Solution {
public:
    string triangleType(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums[0] + nums[1] <= nums[2]) {
            return "none";
        }
        if (nums[0] == nums[2]) {
            return "equilateral";
        }
        if (nums[0] == nums[1] || nums[1] == nums[2]) {
            return "isosceles";
        }
        return "scalene";
    }
};
```

#### Go

```go
func triangleType(nums []int) string {
	sort.Ints(nums)
	if nums[0]+nums[1] <= nums[2] {
		return "none"
	}
	if nums[0] == nums[2] {
		return "equilateral"
	}
	if nums[0] == nums[1] || nums[1] == nums[2] {
		return "isosceles"
	}
	return "scalene"
}
```

#### TypeScript

```ts
function triangleType(nums: number[]): string {
    nums.sort((a, b) => a - b);
    if (nums[0] + nums[1] <= nums[2]) {
        return 'none';
    }
    if (nums[0] === nums[2]) {
        return 'equilateral';
    }
    if (nums[0] === nums[1] || nums[1] === nums[2]) {
        return 'isosceles';
    }
    return 'scalene';
}
```

#### C#

```cs
public class Solution {
    public string TriangleType(int[] nums) {
        Array.Sort(nums);
        if (nums[0] + nums[1] <= nums[2]) {
            return "none";
        }
        if (nums[0] == nums[2]) {
            return "equilateral";
        }
        if (nums[0] == nums[1] || nums[1] == nums[2]) {
            return "isosceles";
        }
        return "scalene";
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3025. 人员站位的方案数 I](https://leetcode.cn/problems/find-the-number-of-ways-to-place-people-i){#3025}

{{< tabs "3025" >}}

{{% tab "python" %}}
```python
class Solution:
    def numberOfPairs(self, points: List[List[int]]) -> int:
        points.sort(key=lambda x: (x[0], -x[1]))
        ans = 0
        for i, (_, y1) in enumerate(points):
            max_y = -inf
            for _, y2 in points[i + 1 :]:
                if max_y < y2 <= y1:
                    max_y = y2
                    ans += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numberOfPairs(int[][] points) {
        Arrays.sort(points, (a, b) -> a[0] == b[0] ? b[1] - a[1] : a[0] - b[0]);
        int ans = 0;
        int n = points.length;
        final int inf = 1 << 30;
        for (int i = 0; i < n; ++i) {
            int y1 = points[i][1];
            int maxY = -inf;
            for (int j = i + 1; j < n; ++j) {
                int y2 = points[j][1];
                if (maxY < y2 && y2 <= y1) {
                    maxY = y2;
                    ++ans;
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
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0] || (a[0] == b[0] && b[1] < a[1]);
        });
        int n = points.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int y1 = points[i][1];
            int maxY = INT_MIN;
            for (int j = i + 1; j < n; ++j) {
                int y2 = points[j][1];
                if (maxY < y2 && y2 <= y1) {
                    maxY = y2;
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
func numberOfPairs(points [][]int) (ans int) {
	sort.Slice(points, func(i, j int) bool {
		return points[i][0] < points[j][0] || points[i][0] == points[j][0] && points[j][1] < points[i][1]
	})
	for i, p1 := range points {
		y1 := p1[1]
		maxY := math.MinInt32
		for _, p2 := range points[i+1:] {
			y2 := p2[1]
			if maxY < y2 && y2 <= y1 {
				maxY = y2
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
function numberOfPairs(points: number[][]): number {
    points.sort((a, b) => (a[0] === b[0] ? b[1] - a[1] : a[0] - b[0]));
    const n = points.length;
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        const [_, y1] = points[i];
        let maxY = -Infinity;
        for (let j = i + 1; j < n; ++j) {
            const [_, y2] = points[j];
            if (maxY < y2 && y2 <= y1) {
                maxY = y2;
                ++ans;
            }
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn number_of_pairs(mut points: Vec<Vec<i32>>) -> i32 {
        points.sort_by(|a, b| {
            if a[0] == b[0] {
                b[1].cmp(&a[1])
            } else {
                a[0].cmp(&b[0])
            }
        });

        let n = points.len();
        let mut ans = 0;
        for i in 0..n {
            let y1 = points[i][1];
            let mut max_y = i32::MIN;
            for j in (i + 1)..n {
                let y2 = points[j][1];
                if max_y < y2 && y2 <= y1 {
                    max_y = y2;
                    ans += 1;
                }
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
    public int NumberOfPairs(int[][] points) {
        Array.Sort(points, (a, b) => a[0] == b[0] ? b[1] - a[1] : a[0] - b[0]);
        int ans = 0;
        int n = points.Length;
        int inf = 1 << 30;
        for (int i = 0; i < n; ++i) {
            int y1 = points[i][1];
            int maxY = -inf;
            for (int j = i + 1; j < n; ++j) {
                int y2 = points[j][1];
                if (maxY < y2 && y2 <= y1) {
                    maxY = y2;
                    ++ans;
                }
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

<p>给你一个&nbsp;&nbsp;<code>n x 2</code>&nbsp;的二维数组 <code>points</code>&nbsp;，它表示二维平面上的一些点坐标，其中&nbsp;<code>points[i] = [x<sub>i</sub>, y<sub>i</sub>]</code>&nbsp;。</p>

<p>&nbsp;</p>

<p>计算点对&nbsp;<code>(A, B)</code>&nbsp;的数量，其中</p>

<ul>
	<li><code>A</code> 在 <code>B</code> 的左上角，并且</li>
	<li>它们形成的长方形中（或直线上）没有其它点（<strong>包括边界</strong>）。</li>
</ul>

<p>返回数量。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>points = [[1,1],[2,2],[3,3]]</span></p>

<p><span class="example-io"><b>输出：</b>0</span></p>

<p><strong>解释：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3000-3099/3025.Find%20the%20Number%20of%20Ways%20to%20Place%20People%20I/images/example1alicebob.png" style="width: 427px; height: 350px;" /></p>

<p>没有办法选择&nbsp;<code>A</code> 和&nbsp;<code>B</code>，使得&nbsp;<code>A</code>&nbsp;在&nbsp;<code>B</code>&nbsp;的左上角。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b></span><span class="example-io">points = [[6,2],[4,4],[2,6]]</span></p>

<p><span class="example-io"><b>输出：</b></span><span class="example-io">2</span></p>

<p><strong>解释：</strong></p>

<p><img height="365" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3000-3099/3025.Find%20the%20Number%20of%20Ways%20to%20Place%20People%20I/images/t2.jpg" width="1321" /></p>

<ul>
	<li>左边的是点对&nbsp;<code>(points[1], points[0])</code>，其中&nbsp;<code>points[1]</code>&nbsp;在&nbsp;<code>points[0]</code>&nbsp;的左上角，并且形成的长方形内部是空的。</li>
	<li>中间的是点对&nbsp;<code>(points[2], points[1])</code>，和左边的一样是合法的点对。</li>
	<li>右边的是点对 <code>(points[2], points[0])</code>，其中 <code>points[2]</code> 在 <code>points[0]</code>&nbsp;的左上角，但&nbsp;<code>points[1]</code>&nbsp;在长方形内部，所以不是一个合法的点对。</li>
</ul>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b></span><span class="example-io">points = [[3,1],[1,3],[1,1]]</span></p>

<p><span class="example-io"><b>输出：</b></span><span class="example-io">2</span></p>

<p><strong>解释：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3000-3099/3025.Find%20the%20Number%20of%20Ways%20to%20Place%20People%20I/images/t3.jpg" style="width: 1269px; height: 350px;" /></p>

<ul>
	<li>左边的是点对 <code>(points[2], points[0])</code>，其中&nbsp;<code>points[2]</code>&nbsp;在&nbsp;<code>points[0]</code>&nbsp;的左上角并且在它们形成的直线上没有其它点。注意两个点形成一条线的情况是合法的。</li>
	<li>中间的是点对 <code>(points[1], points[2])</code>，和左边一样也是合法的点对。</li>
	<li>右边的是点对 <code>(points[1], points[0])</code>，它不是合法的点对，因为&nbsp;<code>points[2]</code>&nbsp;在长方形的边上。</li>
</ul>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 50</code></li>
	<li><code>points[i].length == 2</code></li>
	<li><code>0 &lt;= points[i][0], points[i][1] &lt;= 50</code></li>
	<li><code>points[i]</code>&nbsp;点对两两不同。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 枚举

我们不妨考虑枚举矩形左上角的点 $(x_1, y_1)$，那么根据题目，右下角的点 $(x_2, y_2)$ 随着 $x$ 的增大，纵坐标 $y$ 也会要严格增大，才符合题意。

因此，我们对所有点按照 $x$ 坐标升序排序，如果 $x$ 坐标相同，按照 $y$ 坐标降序排序。

然后我们枚举左上角的点 $(x_1, y_1)$，并且维护一个最大的 $y_2$，记为 $maxY$，表示所有右下角的点的纵坐标的最大值。然后我们枚举右下角的点 $(x_2, y_2)$，如果 $y_2$ 大于 $maxY$ 并且小于等于 $y_1$，那么我们就找到了一个合法的方案，将答案加一，然后更新 $maxY$ 为 $y_2$。

枚举完所有的点对后，我们就得到了答案。

时间复杂度 $O(n^2)$，空间复杂度 $O(\log n)$。其中 $n$ 是点的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numberOfPairs(self, points: List[List[int]]) -> int:
        points.sort(key=lambda x: (x[0], -x[1]))
        ans = 0
        for i, (_, y1) in enumerate(points):
            max_y = -inf
            for _, y2 in points[i + 1 :]:
                if max_y < y2 <= y1:
                    max_y = y2
                    ans += 1
        return ans
```

#### Java

```java
class Solution {
    public int numberOfPairs(int[][] points) {
        Arrays.sort(points, (a, b) -> a[0] == b[0] ? b[1] - a[1] : a[0] - b[0]);
        int ans = 0;
        int n = points.length;
        final int inf = 1 << 30;
        for (int i = 0; i < n; ++i) {
            int y1 = points[i][1];
            int maxY = -inf;
            for (int j = i + 1; j < n; ++j) {
                int y2 = points[j][1];
                if (maxY < y2 && y2 <= y1) {
                    maxY = y2;
                    ++ans;
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
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0] || (a[0] == b[0] && b[1] < a[1]);
        });
        int n = points.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int y1 = points[i][1];
            int maxY = INT_MIN;
            for (int j = i + 1; j < n; ++j) {
                int y2 = points[j][1];
                if (maxY < y2 && y2 <= y1) {
                    maxY = y2;
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
func numberOfPairs(points [][]int) (ans int) {
	sort.Slice(points, func(i, j int) bool {
		return points[i][0] < points[j][0] || points[i][0] == points[j][0] && points[j][1] < points[i][1]
	})
	for i, p1 := range points {
		y1 := p1[1]
		maxY := math.MinInt32
		for _, p2 := range points[i+1:] {
			y2 := p2[1]
			if maxY < y2 && y2 <= y1 {
				maxY = y2
				ans++
			}
		}
	}
	return
}
```

#### TypeScript

```ts
function numberOfPairs(points: number[][]): number {
    points.sort((a, b) => (a[0] === b[0] ? b[1] - a[1] : a[0] - b[0]));
    const n = points.length;
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        const [_, y1] = points[i];
        let maxY = -Infinity;
        for (let j = i + 1; j < n; ++j) {
            const [_, y2] = points[j];
            if (maxY < y2 && y2 <= y1) {
                maxY = y2;
                ++ans;
            }
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn number_of_pairs(mut points: Vec<Vec<i32>>) -> i32 {
        points.sort_by(|a, b| {
            if a[0] == b[0] {
                b[1].cmp(&a[1])
            } else {
                a[0].cmp(&b[0])
            }
        });

        let n = points.len();
        let mut ans = 0;
        for i in 0..n {
            let y1 = points[i][1];
            let mut max_y = i32::MIN;
            for j in (i + 1)..n {
                let y2 = points[j][1];
                if max_y < y2 && y2 <= y1 {
                    max_y = y2;
                    ans += 1;
                }
            }
        }
        ans
    }
}
```

#### C#

```cs
public class Solution {
    public int NumberOfPairs(int[][] points) {
        Array.Sort(points, (a, b) => a[0] == b[0] ? b[1] - a[1] : a[0] - b[0]);
        int ans = 0;
        int n = points.Length;
        int inf = 1 << 30;
        for (int i = 0; i < n; ++i) {
            int y1 = points[i][1];
            int maxY = -inf;
            for (int j = i + 1; j < n; ++j) {
                int y2 = points[j][1];
                if (maxY < y2 && y2 <= y1) {
                    maxY = y2;
                    ++ans;
                }
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

# [3026. 最大好子数组和](https://leetcode.cn/problems/maximum-good-subarray-sum){#3026}

{{< tabs "3026" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumSubarraySum(self, nums: List[int], k: int) -> int:
        ans = -inf
        p = {nums[0]: 0}
        s, n = 0, len(nums)
        for i, x in enumerate(nums):
            s += x
            if x - k in p:
                ans = max(ans, s - p[x - k])
            if x + k in p:
                ans = max(ans, s - p[x + k])
            if i + 1 < n and (nums[i + 1] not in p or p[nums[i + 1]] > s):
                p[nums[i + 1]] = s
        return 0 if ans == -inf else ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long maximumSubarraySum(int[] nums, int k) {
        Map<Integer, Long> p = new HashMap<>();
        p.put(nums[0], 0L);
        long s = 0;
        int n = nums.length;
        long ans = Long.MIN_VALUE;
        for (int i = 0; i < n; ++i) {
            s += nums[i];
            if (p.containsKey(nums[i] - k)) {
                ans = Math.max(ans, s - p.get(nums[i] - k));
            }
            if (p.containsKey(nums[i] + k)) {
                ans = Math.max(ans, s - p.get(nums[i] + k));
            }
            if (i + 1 < n && (!p.containsKey(nums[i + 1]) || p.get(nums[i + 1]) > s)) {
                p.put(nums[i + 1], s);
            }
        }
        return ans == Long.MIN_VALUE ? 0 : ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, long long> p;
        p[nums[0]] = 0;
        long long s = 0;
        const int n = nums.size();
        long long ans = LONG_LONG_MIN;
        for (int i = 0;; ++i) {
            s += nums[i];
            auto it = p.find(nums[i] - k);
            if (it != p.end()) {
                ans = max(ans, s - it->second);
            }
            it = p.find(nums[i] + k);
            if (it != p.end()) {
                ans = max(ans, s - it->second);
            }
            if (i + 1 == n) {
                break;
            }
            it = p.find(nums[i + 1]);
            if (it == p.end() || it->second > s) {
                p[nums[i + 1]] = s;
            }
        }
        return ans == LONG_LONG_MIN ? 0 : ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumSubarraySum(nums []int, k int) int64 {
	p := map[int]int64{nums[0]: 0}
	var s int64 = 0
	n := len(nums)
	var ans int64 = math.MinInt64
	for i, x := range nums {
		s += int64(x)
		if t, ok := p[nums[i]-k]; ok {
			ans = max(ans, s-t)
		}
		if t, ok := p[nums[i]+k]; ok {
			ans = max(ans, s-t)
		}
		if i+1 == n {
			break
		}
		if t, ok := p[nums[i+1]]; !ok || s < t {
			p[nums[i+1]] = s
		}
	}
	if ans == math.MinInt64 {
		return 0
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumSubarraySum(nums: number[], k: number): number {
    const p: Map<number, number> = new Map();
    p.set(nums[0], 0);
    let ans: number = -Infinity;
    let s: number = 0;
    const n: number = nums.length;
    for (let i = 0; i < n; ++i) {
        s += nums[i];
        if (p.has(nums[i] - k)) {
            ans = Math.max(ans, s - p.get(nums[i] - k)!);
        }
        if (p.has(nums[i] + k)) {
            ans = Math.max(ans, s - p.get(nums[i] + k)!);
        }
        if (i + 1 < n && (!p.has(nums[i + 1]) || p.get(nums[i + 1])! > s)) {
            p.set(nums[i + 1], s);
        }
    }
    return ans === -Infinity ? 0 : ans;
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public long MaximumSubarraySum(int[] nums, int k) {
        Dictionary<int, long> p = new Dictionary<int, long>();
        p[nums[0]] = 0L;
        long s = 0;
        int n = nums.Length;
        long ans = long.MinValue;
        for (int i = 0; i < n; ++i) {
            s += nums[i];
            if (p.ContainsKey(nums[i] - k)) {
                ans = Math.Max(ans, s - p[nums[i] - k]);
            }
            if (p.ContainsKey(nums[i] + k)) {
                ans = Math.Max(ans, s - p[nums[i] + k]);
            }
            if (i + 1 < n && (!p.ContainsKey(nums[i + 1]) || p[nums[i + 1]] > s)) {
                p[nums[i + 1]] = s;
            }
        }
        return ans == long.MinValue ? 0 : ans;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个长度为 <code>n</code>&nbsp;的数组&nbsp;<code>nums</code>&nbsp;和一个 <strong>正</strong>&nbsp;整数&nbsp;<code>k</code>&nbsp;。</p>

<p>如果&nbsp;<code>nums</code>&nbsp;的一个<span data-keyword="subarray">子数组</span>中，第一个元素和最后一个元素 <strong>差的绝对值恰好</strong>&nbsp;为&nbsp;<code>k</code>&nbsp;，我们称这个子数组为&nbsp;<strong>好</strong>&nbsp;的。换句话说，如果子数组&nbsp;<code>nums[i..j]</code>&nbsp;满足&nbsp;<code>|nums[i] - nums[j]| == k</code>&nbsp;，那么它是一个好子数组。</p>

<p>请你返回&nbsp;<code>nums</code>&nbsp;中&nbsp;<strong>好</strong>&nbsp;子数组的&nbsp;<strong>最大</strong>&nbsp;和，如果没有好子数组，返回<em>&nbsp;</em><code>0</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [1,2,3,4,5,6], k = 1
<b>输出：</b>11
<b>解释：</b>好子数组中第一个元素和最后一个元素的差的绝对值必须为 1 。好子数组有 [1,2] ，[2,3] ，[3,4] ，[4,5] 和 [5,6] 。最大子数组和为 11 ，对应的子数组为 [5,6] 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [-1,3,2,4,5], k = 3
<b>输出：</b>11
<b>解释：</b>好子数组中第一个元素和最后一个元素的差的绝对值必须为 3 。好子数组有 [-1,3,2] 和 [2,4,5] 。最大子数组和为 11 ，对应的子数组为 [2,4,5] 。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>nums = [-1,-2,-3,-4], k = 2
<b>输出：</b>-6
<b>解释：</b>好子数组中第一个元素和最后一个元素的差的绝对值必须为 2 。好子数组有 [-1,-2,-3] 和 [-2,-3,-4] 。最大子数组和为 -6 ，对应的子数组为 [-1,-2,-3] 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前缀和 + 哈希表

我们用一个哈希表 $p$ 记录 $nums[i]$ 的前缀数组 $nums[0..i-1]$ 的和 $s$，如果有多个相同的 $nums[i]$，我们只保留最小的 $s$。初始时，我们将 $p[nums[0]]$ 设为 $0$。另外，我们用一个变量 $s$ 记录当前的前缀和，初始时 $s = 0$。初始化答案 $ans$ 为 $-\infty$。

接下来，我们枚举 $nums[i]$，并且维护一个变量 $s$ 表示 $nums[0..i]$ 的和。如果 $nums[i] - k$ 在 $p$ 中，那么我们就找到了一个好子数组，将答案更新为 $ans = \max(ans, s - p[nums[i] - k])$。同理，如果 $nums[i] + k$ 在 $p$ 中，那么我们也找到了一个好子数组，将答案更新为 $ans = \max(ans, s - p[nums[i] + k])$。然后，如果 $i + 1 \lt n$ 并且 $nums[i + 1]$ 不在 $p$ 中，或者 $p[nums[i + 1]] \gt s$，我们就将 $p[nums[i + 1]]$ 设为 $s$。

最后，如果 $ans = -\infty$，那么我们返回 $0$，否则返回 $ans$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumSubarraySum(self, nums: List[int], k: int) -> int:
        ans = -inf
        p = {nums[0]: 0}
        s, n = 0, len(nums)
        for i, x in enumerate(nums):
            s += x
            if x - k in p:
                ans = max(ans, s - p[x - k])
            if x + k in p:
                ans = max(ans, s - p[x + k])
            if i + 1 < n and (nums[i + 1] not in p or p[nums[i + 1]] > s):
                p[nums[i + 1]] = s
        return 0 if ans == -inf else ans
```

#### Java

```java
class Solution {
    public long maximumSubarraySum(int[] nums, int k) {
        Map<Integer, Long> p = new HashMap<>();
        p.put(nums[0], 0L);
        long s = 0;
        int n = nums.length;
        long ans = Long.MIN_VALUE;
        for (int i = 0; i < n; ++i) {
            s += nums[i];
            if (p.containsKey(nums[i] - k)) {
                ans = Math.max(ans, s - p.get(nums[i] - k));
            }
            if (p.containsKey(nums[i] + k)) {
                ans = Math.max(ans, s - p.get(nums[i] + k));
            }
            if (i + 1 < n && (!p.containsKey(nums[i + 1]) || p.get(nums[i + 1]) > s)) {
                p.put(nums[i + 1], s);
            }
        }
        return ans == Long.MIN_VALUE ? 0 : ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, long long> p;
        p[nums[0]] = 0;
        long long s = 0;
        const int n = nums.size();
        long long ans = LONG_LONG_MIN;
        for (int i = 0;; ++i) {
            s += nums[i];
            auto it = p.find(nums[i] - k);
            if (it != p.end()) {
                ans = max(ans, s - it->second);
            }
            it = p.find(nums[i] + k);
            if (it != p.end()) {
                ans = max(ans, s - it->second);
            }
            if (i + 1 == n) {
                break;
            }
            it = p.find(nums[i + 1]);
            if (it == p.end() || it->second > s) {
                p[nums[i + 1]] = s;
            }
        }
        return ans == LONG_LONG_MIN ? 0 : ans;
    }
};
```

#### Go

```go
func maximumSubarraySum(nums []int, k int) int64 {
	p := map[int]int64{nums[0]: 0}
	var s int64 = 0
	n := len(nums)
	var ans int64 = math.MinInt64
	for i, x := range nums {
		s += int64(x)
		if t, ok := p[nums[i]-k]; ok {
			ans = max(ans, s-t)
		}
		if t, ok := p[nums[i]+k]; ok {
			ans = max(ans, s-t)
		}
		if i+1 == n {
			break
		}
		if t, ok := p[nums[i+1]]; !ok || s < t {
			p[nums[i+1]] = s
		}
	}
	if ans == math.MinInt64 {
		return 0
	}
	return ans
}
```

#### TypeScript

```ts
function maximumSubarraySum(nums: number[], k: number): number {
    const p: Map<number, number> = new Map();
    p.set(nums[0], 0);
    let ans: number = -Infinity;
    let s: number = 0;
    const n: number = nums.length;
    for (let i = 0; i < n; ++i) {
        s += nums[i];
        if (p.has(nums[i] - k)) {
            ans = Math.max(ans, s - p.get(nums[i] - k)!);
        }
        if (p.has(nums[i] + k)) {
            ans = Math.max(ans, s - p.get(nums[i] + k)!);
        }
        if (i + 1 < n && (!p.has(nums[i + 1]) || p.get(nums[i + 1])! > s)) {
            p.set(nums[i + 1], s);
        }
    }
    return ans === -Infinity ? 0 : ans;
}
```

#### C#

```cs
public class Solution {
    public long MaximumSubarraySum(int[] nums, int k) {
        Dictionary<int, long> p = new Dictionary<int, long>();
        p[nums[0]] = 0L;
        long s = 0;
        int n = nums.Length;
        long ans = long.MinValue;
        for (int i = 0; i < n; ++i) {
            s += nums[i];
            if (p.ContainsKey(nums[i] - k)) {
                ans = Math.Max(ans, s - p[nums[i] - k]);
            }
            if (p.ContainsKey(nums[i] + k)) {
                ans = Math.Max(ans, s - p[nums[i] + k]);
            }
            if (i + 1 < n && (!p.ContainsKey(nums[i + 1]) || p[nums[i + 1]] > s)) {
                p[nums[i + 1]] = s;
            }
        }
        return ans == long.MinValue ? 0 : ans;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3027. 人员站位的方案数 II](https://leetcode.cn/problems/find-the-number-of-ways-to-place-people-ii){#3027}

{{< tabs "3027" >}}

{{% tab "python" %}}
```python
class Solution:
    def numberOfPairs(self, points: List[List[int]]) -> int:
        points.sort(key=lambda x: (x[0], -x[1]))
        ans = 0
        for i, (_, y1) in enumerate(points):
            max_y = -inf
            for _, y2 in points[i + 1 :]:
                if max_y < y2 <= y1:
                    max_y = y2
                    ans += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numberOfPairs(int[][] points) {
        Arrays.sort(points, (a, b) -> a[0] == b[0] ? b[1] - a[1] : a[0] - b[0]);
        int ans = 0;
        int n = points.length;
        final int inf = 1 << 30;
        for (int i = 0; i < n; ++i) {
            int y1 = points[i][1];
            int maxY = -inf;
            for (int j = i + 1; j < n; ++j) {
                int y2 = points[j][1];
                if (maxY < y2 && y2 <= y1) {
                    maxY = y2;
                    ++ans;
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
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0] || (a[0] == b[0] && b[1] < a[1]);
        });
        int n = points.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int y1 = points[i][1];
            int maxY = INT_MIN;
            for (int j = i + 1; j < n; ++j) {
                int y2 = points[j][1];
                if (maxY < y2 && y2 <= y1) {
                    maxY = y2;
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
func numberOfPairs(points [][]int) (ans int) {
	sort.Slice(points, func(i, j int) bool {
		return points[i][0] < points[j][0] || points[i][0] == points[j][0] && points[j][1] < points[i][1]
	})
	for i, p1 := range points {
		y1 := p1[1]
		maxY := math.MinInt32
		for _, p2 := range points[i+1:] {
			y2 := p2[1]
			if maxY < y2 && y2 <= y1 {
				maxY = y2
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
function numberOfPairs(points: number[][]): number {
    points.sort((a, b) => (a[0] === b[0] ? b[1] - a[1] : a[0] - b[0]));
    const n = points.length;
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        const [_, y1] = points[i];
        let maxY = -Infinity;
        for (let j = i + 1; j < n; ++j) {
            const [_, y2] = points[j];
            if (maxY < y2 && y2 <= y1) {
                maxY = y2;
                ++ans;
            }
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn number_of_pairs(mut points: Vec<Vec<i32>>) -> i32 {
        points.sort_by(|a, b| {
            if a[0] == b[0] {
                b[1].cmp(&a[1])
            } else {
                a[0].cmp(&b[0])
            }
        });

        let n = points.len();
        let mut ans = 0;
        for i in 0..n {
            let y1 = points[i][1];
            let mut max_y = i32::MIN;
            for j in (i + 1)..n {
                let y2 = points[j][1];
                if max_y < y2 && y2 <= y1 {
                    max_y = y2;
                    ans += 1;
                }
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
    public int NumberOfPairs(int[][] points) {
        Array.Sort(points, (a, b) => a[0] == b[0] ? b[1] - a[1] : a[0] - b[0]);
        int ans = 0;
        int n = points.Length;
        int inf = 1 << 30;
        for (int i = 0; i < n; ++i) {
            int y1 = points[i][1];
            int maxY = -inf;
            for (int j = i + 1; j < n; ++j) {
                int y2 = points[j][1];
                if (maxY < y2 && y2 <= y1) {
                    maxY = y2;
                    ++ans;
                }
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

<p>给你一个&nbsp;&nbsp;<code>n x 2</code>&nbsp;的二维数组 <code>points</code>&nbsp;，它表示二维平面上的一些点坐标，其中&nbsp;<code>points[i] = [x<sub>i</sub>, y<sub>i</sub>]</code>&nbsp;。</p>

<p>我们定义 x 轴的正方向为 <strong>右</strong>&nbsp;（<strong>x 轴递增的方向</strong>），x 轴的负方向为 <strong>左</strong>&nbsp;（<strong>x 轴递减的方向</strong>）。类似的，我们定义 y 轴的正方向为 <strong>上</strong>&nbsp;（<strong>y 轴递增的方向</strong>），y 轴的负方向为 <strong>下</strong>&nbsp;（<strong>y 轴递减的方向</strong>）。</p>

<p>你需要安排这 <code>n</code>&nbsp;个人的站位，这 <code>n</code>&nbsp;个人中包括 Alice 和 Bob 。你需要确保每个点处&nbsp;<strong>恰好</strong>&nbsp;有&nbsp;<strong>一个</strong>&nbsp;人。同时，Alice 想跟 Bob 单独玩耍，所以&nbsp;Alice 会以 Alice<b>&nbsp;</b>的坐标为 <strong>左上角</strong>&nbsp;，Bob 的坐标为 <strong>右下角</strong>&nbsp;建立一个矩形的围栏（<strong>注意</strong>，围栏可能&nbsp;<strong>不</strong> 包含任何区域，也就是说围栏可能是一条线段）。如果围栏的 <strong>内部</strong>&nbsp;或者 <strong>边缘</strong>&nbsp;上有任何其他人，Alice 都会难过。</p>

<p>请你在确保 Alice&nbsp;<strong>不会</strong> 难过的前提下，返回 Alice 和 Bob 可以选择的 <strong>点对</strong>&nbsp;数目。</p>

<p><b>注意</b>，Alice 建立的围栏必须确保 Alice 的位置是矩形的左上角，Bob 的位置是矩形的右下角。比方说，以&nbsp;<code>(1, 1)</code>&nbsp;，<code>(1, 3)</code>&nbsp;，<code>(3, 1)</code>&nbsp;和&nbsp;<code>(3, 3)</code>&nbsp;为矩形的四个角，给定下图的两个输入，Alice 都不能建立围栏，原因如下：</p>

<ul>
	<li>图一中，Alice 在&nbsp;<code>(3, 3)</code>&nbsp;且 Bob 在&nbsp;<code>(1, 1)</code>&nbsp;，Alice 的位置不是左上角且 Bob 的位置不是右下角。</li>
	<li>图二中，Alice 在&nbsp;<code>(1, 3)</code>&nbsp;且 Bob 在&nbsp;<code>(1, 1)</code>&nbsp;，Bob 的位置不是在围栏的右下角。</li>
</ul>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3000-3099/3027.Find%20the%20Number%20of%20Ways%20to%20Place%20People%20II/images/example0alicebob-1.png" style="width: 750px; height: 308px;padding: 10px; background: #fff; border-radius: .5rem;" />
<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3000-3099/3027.Find%20the%20Number%20of%20Ways%20to%20Place%20People%20II/images/example1alicebob.png" style="width: 376px; height: 308px; padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem;" /></p>

<pre>
<b>输入：</b>points = [[1,1],[2,2],[3,3]]
<b>输出：</b>0
<strong>解释：</strong>没有办法可以让 Alice 的围栏以 Alice 的位置为左上角且 Bob 的位置为右下角。所以我们返回 0 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<p><strong class="example"><a href="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3000-3099/3027.Find%20the%20Number%20of%20Ways%20to%20Place%20People%20II/images/1708226715-CxjXKb-20240218-112338.jpeg"><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3000-3099/3027.Find%20the%20Number%20of%20Ways%20to%20Place%20People%20II/images/1708226715-CxjXKb-20240218-112338.jpeg" style="width: 900px; height: 248px;" /></a></strong></p>

<pre>
<b>输入：</b>points = [[6,2],[4,4],[2,6]]
<b>输出：</b>2
<b>解释：</b>总共有 2 种方案安排 Alice 和 Bob 的位置，使得 Alice 不会难过：
- Alice 站在 (4, 4) ，Bob 站在 (6, 2) 。
- Alice 站在 (2, 6) ，Bob 站在 (4, 4) 。
不能安排 Alice 站在 (2, 6) 且 Bob 站在 (6, 2) ，因为站在 (4, 4) 的人处于围栏内。
</pre>

<p><strong class="example">示例 3：</strong></p>

<p><strong class="example"><a href="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3000-3099/3027.Find%20the%20Number%20of%20Ways%20to%20Place%20People%20II/images/1708226721-wTbEuK-20240218-112351.jpeg"><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3000-3099/3027.Find%20the%20Number%20of%20Ways%20to%20Place%20People%20II/images/1708226721-wTbEuK-20240218-112351.jpeg" style="width: 911px; height: 250px;" /></a></strong></p>

<pre>
<b>输入：</b>points = [[3,1],[1,3],[1,1]]
<b>输出：</b>2
<b>解释：</b>总共有 2 种方案安排 Alice 和 Bob 的位置，使得 Alice 不会难过：
- Alice 站在 (1, 1) ，Bob 站在 (3, 1) 。
- Alice 站在 (1, 3) ，Bob 站在 (1, 1) 。
不能安排 Alice 站在 (1, 3) 且 Bob 站在 (3, 1) ，因为站在 (1, 1) 的人处于围栏内。
注意围栏是可以不包含任何面积的，上图中第一和第二个围栏都是合法的。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 1000</code></li>
	<li><code>points[i].length == 2</code></li>
	<li><code>-10<sup>9</sup> &lt;= points[i][0], points[i][1] &lt;= 10<sup>9</sup></code></li>
	<li><code>points[i]</code>&nbsp;点对两两不同。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 枚举

我们不妨考虑枚举矩形左上角的点 $(x_1, y_1)$，那么根据题目，右下角的点 $(x_2, y_2)$ 随着 $x$ 的增大，纵坐标 $y$ 也会要严格增大，才符合题意。

因此，我们对所有点按照 $x$ 坐标升序排序，如果 $x$ 坐标相同，按照 $y$ 坐标降序排序。

然后我们枚举左上角的点 $(x_1, y_1)$，并且维护一个最大的 $y_2$，记为 $maxY$，表示所有右下角的点的纵坐标的最大值。然后我们枚举右下角的点 $(x_2, y_2)$，如果 $y_2$ 大于 $maxY$ 并且小于等于 $y_1$，那么我们就找到了一个合法的方案，将答案加一，然后更新 $maxY$ 为 $y_2$。

枚举完所有的点对后，我们就得到了答案。

时间复杂度 $O(n^2)$，空间复杂度 $O(\log n)$。其中 $n$ 是点的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numberOfPairs(self, points: List[List[int]]) -> int:
        points.sort(key=lambda x: (x[0], -x[1]))
        ans = 0
        for i, (_, y1) in enumerate(points):
            max_y = -inf
            for _, y2 in points[i + 1 :]:
                if max_y < y2 <= y1:
                    max_y = y2
                    ans += 1
        return ans
```

#### Java

```java
class Solution {
    public int numberOfPairs(int[][] points) {
        Arrays.sort(points, (a, b) -> a[0] == b[0] ? b[1] - a[1] : a[0] - b[0]);
        int ans = 0;
        int n = points.length;
        final int inf = 1 << 30;
        for (int i = 0; i < n; ++i) {
            int y1 = points[i][1];
            int maxY = -inf;
            for (int j = i + 1; j < n; ++j) {
                int y2 = points[j][1];
                if (maxY < y2 && y2 <= y1) {
                    maxY = y2;
                    ++ans;
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
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0] || (a[0] == b[0] && b[1] < a[1]);
        });
        int n = points.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int y1 = points[i][1];
            int maxY = INT_MIN;
            for (int j = i + 1; j < n; ++j) {
                int y2 = points[j][1];
                if (maxY < y2 && y2 <= y1) {
                    maxY = y2;
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
func numberOfPairs(points [][]int) (ans int) {
	sort.Slice(points, func(i, j int) bool {
		return points[i][0] < points[j][0] || points[i][0] == points[j][0] && points[j][1] < points[i][1]
	})
	for i, p1 := range points {
		y1 := p1[1]
		maxY := math.MinInt32
		for _, p2 := range points[i+1:] {
			y2 := p2[1]
			if maxY < y2 && y2 <= y1 {
				maxY = y2
				ans++
			}
		}
	}
	return
}
```

#### TypeScript

```ts
function numberOfPairs(points: number[][]): number {
    points.sort((a, b) => (a[0] === b[0] ? b[1] - a[1] : a[0] - b[0]));
    const n = points.length;
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        const [_, y1] = points[i];
        let maxY = -Infinity;
        for (let j = i + 1; j < n; ++j) {
            const [_, y2] = points[j];
            if (maxY < y2 && y2 <= y1) {
                maxY = y2;
                ++ans;
            }
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn number_of_pairs(mut points: Vec<Vec<i32>>) -> i32 {
        points.sort_by(|a, b| {
            if a[0] == b[0] {
                b[1].cmp(&a[1])
            } else {
                a[0].cmp(&b[0])
            }
        });

        let n = points.len();
        let mut ans = 0;
        for i in 0..n {
            let y1 = points[i][1];
            let mut max_y = i32::MIN;
            for j in (i + 1)..n {
                let y2 = points[j][1];
                if max_y < y2 && y2 <= y1 {
                    max_y = y2;
                    ans += 1;
                }
            }
        }
        ans
    }
}
```

#### C#

```cs
public class Solution {
    public int NumberOfPairs(int[][] points) {
        Array.Sort(points, (a, b) => a[0] == b[0] ? b[1] - a[1] : a[0] - b[0]);
        int ans = 0;
        int n = points.Length;
        int inf = 1 << 30;
        for (int i = 0; i < n; ++i) {
            int y1 = points[i][1];
            int maxY = -inf;
            for (int j = i + 1; j < n; ++j) {
                int y2 = points[j][1];
                if (maxY < y2 && y2 <= y1) {
                    maxY = y2;
                    ++ans;
                }
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

# [3028. 边界上的蚂蚁](https://leetcode.cn/problems/ant-on-the-boundary){#3028}

{{< tabs "3028" >}}

{{% tab "python" %}}
```python
class Solution:
    def returnToBoundaryCount(self, nums: List[int]) -> int:
        return sum(s == 0 for s in accumulate(nums))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int returnToBoundaryCount(int[] nums) {
        int ans = 0, s = 0;
        for (int x : nums) {
            s += x;
            if (s == 0) {
                ++ans;
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
    int returnToBoundaryCount(vector<int>& nums) {
        int ans = 0, s = 0;
        for (int x : nums) {
            s += x;
            ans += s == 0;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func returnToBoundaryCount(nums []int) (ans int) {
	s := 0
	for _, x := range nums {
		s += x
		if s == 0 {
			ans++
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function returnToBoundaryCount(nums: number[]): number {
    let [ans, s] = [0, 0];
    for (const x of nums) {
        s += x;
        ans += s === 0 ? 1 : 0;
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

<p>边界上有一只蚂蚁，它有时向 <strong>左 </strong>走，有时向 <strong>右 </strong>走。</p>

<p>给你一个 <strong>非零</strong> 整数数组 <code>nums</code> 。蚂蚁会按顺序读取 <code>nums</code> 中的元素，从第一个元素开始直到结束。每一步，蚂蚁会根据当前元素的值移动：</p>

<ul>
	<li>如果 <code>nums[i] &lt; 0</code> ，向 <strong>左</strong> 移动<!-- notionvc: 55fee232-4fc9-445f-952a-f1b979415864 --> <code>-nums[i]</code>单位。</li>
	<li>如果 <code>nums[i] &gt; 0</code> ，向 <strong>右</strong> 移动 <code>nums[i]</code>单位。</li>
</ul>

<p>返回蚂蚁 <strong>返回 </strong>到边界上的次数。</p>

<p><strong>注意：</strong></p>

<ul>
	<li>边界两侧有无限的空间。</li>
	<li>只有在蚂蚁移动了 <code>|nums[i]|</code> 单位后才检查它是否位于边界上。换句话说，如果蚂蚁只是在移动过程中穿过了边界，则不会计算在内。<!-- notionvc: 5ff95338-8634-4d02-a085-1e83c0be6fcd --></li>
</ul>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,3,-5]
<strong>输出：</strong>1
<strong>解释：</strong>第 1 步后，蚂蚁距边界右侧 2 单位远<!-- notionvc: 61ace51c-559f-4bc6-800f-0a0db2540433 -->。
第 2 步后，蚂蚁距边界右侧 5 单位远<!-- notionvc: 61ace51c-559f-4bc6-800f-0a0db2540433 -->。
第 3 步后，蚂蚁位于边界上。
所以答案是 1 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [3,2,-3,-4]
<strong>输出：</strong>0
<strong>解释：</strong>第 1 步后，蚂蚁距边界右侧 3 单位远<!-- notionvc: 61ace51c-559f-4bc6-800f-0a0db2540433 -->。
第 2 步后，蚂蚁距边界右侧 5 单位远<!-- notionvc: 61ace51c-559f-4bc6-800f-0a0db2540433 -->。
第 3 步后，蚂蚁距边界右侧 2 单位远<!-- notionvc: 61ace51c-559f-4bc6-800f-0a0db2540433 -->。
第 4 步后，蚂蚁距边界左侧 2 单位远<!-- notionvc: 61ace51c-559f-4bc6-800f-0a0db2540433 -->。
蚂蚁从未返回到边界上，所以答案是 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>-10 &lt;= nums[i] &lt;= 10</code></li>
	<li><code>nums[i] != 0</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前缀和

根据题目描述，我们只需要计算 $nums$ 的所有前缀和中有多少个 $0$ 即可。

时间复杂度 $O(n)$，其中 $n$ 为 $nums$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def returnToBoundaryCount(self, nums: List[int]) -> int:
        return sum(s == 0 for s in accumulate(nums))
```

#### Java

```java
class Solution {
    public int returnToBoundaryCount(int[] nums) {
        int ans = 0, s = 0;
        for (int x : nums) {
            s += x;
            if (s == 0) {
                ++ans;
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
    int returnToBoundaryCount(vector<int>& nums) {
        int ans = 0, s = 0;
        for (int x : nums) {
            s += x;
            ans += s == 0;
        }
        return ans;
    }
};
```

#### Go

```go
func returnToBoundaryCount(nums []int) (ans int) {
	s := 0
	for _, x := range nums {
		s += x
		if s == 0 {
			ans++
		}
	}
	return
}
```

#### TypeScript

```ts
function returnToBoundaryCount(nums: number[]): number {
    let [ans, s] = [0, 0];
    for (const x of nums) {
        s += x;
        ans += s === 0 ? 1 : 0;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3029. 将单词恢复初始状态所需的最短时间 I](https://leetcode.cn/problems/minimum-time-to-revert-word-to-initial-state-i){#3029}

{{< tabs "3029" >}}

{{% tab "python" %}}
```python
class Hashing:
    __slots__ = ["mod", "h", "p"]

    def __init__(self, s: str, base: int, mod: int):
        self.mod = mod
        self.h = [0] * (len(s) + 1)
        self.p = [1] * (len(s) + 1)
        for i in range(1, len(s) + 1):
            self.h[i] = (self.h[i - 1] * base + ord(s[i - 1])) % mod
            self.p[i] = (self.p[i - 1] * base) % mod

    def query(self, l: int, r: int) -> int:
        return (self.h[r] - self.h[l - 1] * self.p[r - l + 1]) % self.mod


class Solution:
    def minimumTimeToInitialState(self, word: str, k: int) -> int:
        hashing = Hashing(word, 13331, 998244353)
        n = len(word)
        for i in range(k, n, k):
            if hashing.query(1, n - i) == hashing.query(i + 1, n):
                return i // k
        return (n + k - 1) // k
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Hashing {
    private final long[] p;
    private final long[] h;
    private final long mod;

    public Hashing(String word, long base, int mod) {
        int n = word.length();
        p = new long[n + 1];
        h = new long[n + 1];
        p[0] = 1;
        this.mod = mod;
        for (int i = 1; i <= n; i++) {
            p[i] = p[i - 1] * base % mod;
            h[i] = (h[i - 1] * base + word.charAt(i - 1) - 'a') % mod;
        }
    }

    public long query(int l, int r) {
        return (h[r] - h[l - 1] * p[r - l + 1] % mod + mod) % mod;
    }
}

class Solution {
    public int minimumTimeToInitialState(String word, int k) {
        Hashing hashing = new Hashing(word, 13331, 998244353);
        int n = word.length();
        for (int i = k; i < n; i += k) {
            if (hashing.query(1, n - i) == hashing.query(i + 1, n)) {
                return i / k;
            }
        }
        return (n + k - 1) / k;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Hashing {
private:
    vector<long long> p;
    vector<long long> h;
    long long mod;

public:
    Hashing(string word, long long base, int mod) {
        int n = word.size();
        p.resize(n + 1);
        h.resize(n + 1);
        p[0] = 1;
        this->mod = mod;
        for (int i = 1; i <= n; i++) {
            p[i] = (p[i - 1] * base) % mod;
            h[i] = (h[i - 1] * base + word[i - 1] - 'a') % mod;
        }
    }

    long long query(int l, int r) {
        return (h[r] - h[l - 1] * p[r - l + 1] % mod + mod) % mod;
    }
};

class Solution {
public:
    int minimumTimeToInitialState(string word, int k) {
        Hashing hashing(word, 13331, 998244353);
        int n = word.size();
        for (int i = k; i < n; i += k) {
            if (hashing.query(1, n - i) == hashing.query(i + 1, n)) {
                return i / k;
            }
        }
        return (n + k - 1) / k;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
type Hashing struct {
	p   []int64
	h   []int64
	mod int64
}

func NewHashing(word string, base int64, mod int64) *Hashing {
	n := len(word)
	p := make([]int64, n+1)
	h := make([]int64, n+1)
	p[0] = 1
	for i := 1; i <= n; i++ {
		p[i] = (p[i-1] * base) % mod
		h[i] = (h[i-1]*base + int64(word[i-1]-'a')) % mod
	}
	return &Hashing{p, h, mod}
}

func (hashing *Hashing) Query(l, r int) int64 {
	return (hashing.h[r] - hashing.h[l-1]*hashing.p[r-l+1]%hashing.mod + hashing.mod) % hashing.mod
}

func minimumTimeToInitialState(word string, k int) int {
	hashing := NewHashing(word, 13331, 998244353)
	n := len(word)
	for i := k; i < n; i += k {
		if hashing.Query(1, n-i) == hashing.Query(i+1, n) {
			return i / k
		}
	}
	return (n + k - 1) / k
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumTimeToInitialState(word: string, k: number): number {
    const n = word.length;
    for (let i = k; i < n; i += k) {
        if (word.slice(i) === word.slice(0, -i)) {
            return Math.floor(i / k);
        }
    }
    return Math.floor((n + k - 1) / k);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong> 开始的字符串 <code>word</code> 和一个整数 <code>k</code> 。</p>

<p>在每一秒，你必须执行以下操作：</p>

<ul>
	<li>移除 <code>word</code> 的前 <code>k</code> 个字符。</li>
	<li>在 <code>word</code> 的末尾添加 <code>k</code> 个任意字符。</li>
</ul>

<p><strong>注意 </strong>添加的字符不必和移除的字符相同。但是，必须在每一秒钟都执行 <strong>两种 </strong>操作。</p>

<p>返回将 <code>word</code> 恢复到其 <strong>初始 </strong>状态所需的 <strong>最短 </strong>时间（该时间必须大于零）。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>word = "abacaba", k = 3
<strong>输出：</strong>2
<strong>解释：</strong>
第 1 秒，移除 word 的前缀 "aba"，并在末尾添加 "bac" 。因此，word 变为 "cababac"。
第 2 秒，移除 word 的前缀 "cab"，并在末尾添加 "aba" 。因此，word 变为 "abacaba" 并恢复到始状态。
可以证明，2 秒是 word 恢复到其初始状态所需的最短时间。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>word = "abacaba", k = 4
<strong>输出：</strong>1
<strong>解释：
</strong>第 1 秒，移除 word 的前缀 "abac"，并在末尾添加 "caba" 。因此，word 变为 "abacaba" 并恢复到初始状态。
可以证明，1 秒是 word 恢复到其初始状态所需的最短时间。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>word = "abcbabcd", k = 2
<strong>输出：</strong>4
<strong>解释：</strong>
每一秒，我们都移除 word 的前 2 个字符，并在 word 末尾添加相同的字符。
4 秒后，word 变为 "abcbabcd" 并恢复到初始状态。
可以证明，4 秒是 word 恢复到其初始状态所需的最短时间。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= word.length &lt;= 50</code></li>
	<li><code>1 &lt;= k &lt;= word.length</code></li>
	<li><code>word</code>仅由小写英文字母组成。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举

我们不妨假设，如果只操作一次，就能使得 `word` 恢复到初始状态，那么意味着 `word[k:]` 是 `word` 的前缀，即 `word[k:] == word[:n-k]`。

如果有多次操作，不妨设 $i$ 为操作次数，那么意味着 `word[k*i:]` 是 `word` 的前缀，即 `word[k*i:] == word[:n-k*i]`。

因此，我们可以枚举操作次数，判断 `word[k*i:]` 是否是 `word` 的前缀，如果是，则返回 $i$。

时间复杂度 $O(n^2)$，空间复杂度 $O(n)$。其中 $n$ 为 `word` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumTimeToInitialState(self, word: str, k: int) -> int:
        n = len(word)
        for i in range(k, n, k):
            if word[i:] == word[:-i]:
                return i // k
        return (n + k - 1) // k
```

#### Java

```java
class Solution {
    public int minimumTimeToInitialState(String word, int k) {
        int n = word.length();
        for (int i = k; i < n; i += k) {
            if (word.substring(i).equals(word.substring(0, n - i))) {
                return i / k;
            }
        }
        return (n + k - 1) / k;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumTimeToInitialState(string word, int k) {
        int n = word.size();
        for (int i = k; i < n; i += k) {
            if (word.substr(i) == word.substr(0, n - i)) {
                return i / k;
            }
        }
        return (n + k - 1) / k;
    }
};
```

#### Go

```go
func minimumTimeToInitialState(word string, k int) int {
	n := len(word)
	for i := k; i < n; i += k {
		if word[i:] == word[:n-i] {
			return i / k
		}
	}
	return (n + k - 1) / k
}
```

#### TypeScript

```ts
function minimumTimeToInitialState(word: string, k: number): number {
    const n = word.length;
    for (let i = k; i < n; i += k) {
        if (word.slice(i) === word.slice(0, -i)) {
            return Math.floor(i / k);
        }
    }
    return Math.floor((n + k - 1) / k);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：枚举 + 字符串哈希

我们也可以在方法一的基础上，利用字符串哈希来判断两个字符串是否相等。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为 `word` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Hashing:
    __slots__ = ["mod", "h", "p"]

    def __init__(self, s: str, base: int, mod: int):
        self.mod = mod
        self.h = [0] * (len(s) + 1)
        self.p = [1] * (len(s) + 1)
        for i in range(1, len(s) + 1):
            self.h[i] = (self.h[i - 1] * base + ord(s[i - 1])) % mod
            self.p[i] = (self.p[i - 1] * base) % mod

    def query(self, l: int, r: int) -> int:
        return (self.h[r] - self.h[l - 1] * self.p[r - l + 1]) % self.mod


class Solution:
    def minimumTimeToInitialState(self, word: str, k: int) -> int:
        hashing = Hashing(word, 13331, 998244353)
        n = len(word)
        for i in range(k, n, k):
            if hashing.query(1, n - i) == hashing.query(i + 1, n):
                return i // k
        return (n + k - 1) // k
```

#### Java

```java
class Hashing {
    private final long[] p;
    private final long[] h;
    private final long mod;

    public Hashing(String word, long base, int mod) {
        int n = word.length();
        p = new long[n + 1];
        h = new long[n + 1];
        p[0] = 1;
        this.mod = mod;
        for (int i = 1; i <= n; i++) {
            p[i] = p[i - 1] * base % mod;
            h[i] = (h[i - 1] * base + word.charAt(i - 1) - 'a') % mod;
        }
    }

    public long query(int l, int r) {
        return (h[r] - h[l - 1] * p[r - l + 1] % mod + mod) % mod;
    }
}

class Solution {
    public int minimumTimeToInitialState(String word, int k) {
        Hashing hashing = new Hashing(word, 13331, 998244353);
        int n = word.length();
        for (int i = k; i < n; i += k) {
            if (hashing.query(1, n - i) == hashing.query(i + 1, n)) {
                return i / k;
            }
        }
        return (n + k - 1) / k;
    }
}
```

#### C++

```cpp
class Hashing {
private:
    vector<long long> p;
    vector<long long> h;
    long long mod;

public:
    Hashing(string word, long long base, int mod) {
        int n = word.size();
        p.resize(n + 1);
        h.resize(n + 1);
        p[0] = 1;
        this->mod = mod;
        for (int i = 1; i <= n; i++) {
            p[i] = (p[i - 1] * base) % mod;
            h[i] = (h[i - 1] * base + word[i - 1] - 'a') % mod;
        }
    }

    long long query(int l, int r) {
        return (h[r] - h[l - 1] * p[r - l + 1] % mod + mod) % mod;
    }
};

class Solution {
public:
    int minimumTimeToInitialState(string word, int k) {
        Hashing hashing(word, 13331, 998244353);
        int n = word.size();
        for (int i = k; i < n; i += k) {
            if (hashing.query(1, n - i) == hashing.query(i + 1, n)) {
                return i / k;
            }
        }
        return (n + k - 1) / k;
    }
};
```

#### Go

```go
type Hashing struct {
	p   []int64
	h   []int64
	mod int64
}

func NewHashing(word string, base int64, mod int64) *Hashing {
	n := len(word)
	p := make([]int64, n+1)
	h := make([]int64, n+1)
	p[0] = 1
	for i := 1; i <= n; i++ {
		p[i] = (p[i-1] * base) % mod
		h[i] = (h[i-1]*base + int64(word[i-1]-'a')) % mod
	}
	return &Hashing{p, h, mod}
}

func (hashing *Hashing) Query(l, r int) int64 {
	return (hashing.h[r] - hashing.h[l-1]*hashing.p[r-l+1]%hashing.mod + hashing.mod) % hashing.mod
}

func minimumTimeToInitialState(word string, k int) int {
	hashing := NewHashing(word, 13331, 998244353)
	n := len(word)
	for i := k; i < n; i += k {
		if hashing.Query(1, n-i) == hashing.Query(i+1, n) {
			return i / k
		}
	}
	return (n + k - 1) / k
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
