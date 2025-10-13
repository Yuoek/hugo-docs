---
title: "2220_转换数字的最少位翻转次数"
date: 2025-10-08T18:39:07+08:00
weight: 3
tags: [二分查找, 位运算, 前缀和, 动态规划, 后缀数组, 哈希函数, 哈希表, 字典树, 字符串, 字符串匹配, 排序, 数学, 数据库, 数组, 模拟, 滚动哈希, 组合数学, 计数, 设计, 贪心]
---

{{< markmap >}}
### [2220_转换数字的最少位翻转次数](#2220)
#### [位运算](#2220)
### [2221_数组的三角和](#2221)
#### [数组](#2221)
#### [数学](#2221)
#### [组合数学](#2221)
#### [模拟](#2221)
### [2222_选择建筑的方案数](#2222)
#### [字符串](#2222)
#### [动态规划](#2222)
#### [前缀和](#2222)
### [2223_构造字符串的总得分和](#2223)
#### [字符串](#2223)
#### [二分查找](#2223)
#### [字符串匹配](#2223)
#### [后缀数组](#2223)
#### [哈希函数](#2223)
#### [滚动哈希](#2223)
### [2224_转化时间需要的最少操作数](#2224)
#### [贪心](#2224)
#### [字符串](#2224)
### [2225_找出输掉零场或一场比赛的玩家](#2225)
#### [数组](#2225)
#### [哈希表](#2225)
#### [计数](#2225)
#### [排序](#2225)
### [2226_每个小孩最多能分到多少糖果](#2226)
#### [数组](#2226)
#### [二分查找](#2226)
### [2227_加密解密字符串](#2227)
#### [设计](#2227)
#### [字典树](#2227)
#### [数组](#2227)
#### [哈希表](#2227)
#### [字符串](#2227)
### [2228_7 天内两次购买的用户 🔒](#2228)
#### [数据库](#2228)
### [2229_检查数组是否连贯 🔒](#2229)
#### [数组](#2229)
#### [哈希表](#2229)
#### [排序](#2229)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2220_转换数字的最少位翻转次数
___
#### 位运算
---
### 2221_数组的三角和
___
#### 数组
___
#### 数学
___
#### 组合数学
___
#### 模拟
---
### 2222_选择建筑的方案数
___
#### 字符串
___
#### 动态规划
___
#### 前缀和
---
### 2223_构造字符串的总得分和
___
#### 字符串
___
#### 二分查找
___
#### 字符串匹配
___
#### 后缀数组
___
#### 哈希函数
___
#### 滚动哈希
---
### 2224_转化时间需要的最少操作数
___
#### 贪心
___
#### 字符串
---
### 2225_找出输掉零场或一场比赛的玩家
___
#### 数组
___
#### 哈希表
___
#### 计数
___
#### 排序
---
### 2226_每个小孩最多能分到多少糖果
___
#### 数组
___
#### 二分查找
---
### 2227_加密解密字符串
___
#### 设计
___
#### 字典树
___
#### 数组
___
#### 哈希表
___
#### 字符串
---
### 2228_7 天内两次购买的用户 🔒
___
#### 数据库
---
### 2229_检查数组是否连贯 🔒
___
#### 数组
___
#### 哈希表
___
#### 排序
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 位运算 | 前缀和 |
| 动态规划 | 后缀数组 | 哈希函数 |
| 哈希表 | 字典树 | 字符串 |
| 字符串匹配 | 排序 | 数学 |
| 数据库 | 数组 | 模拟 |
| 滚动哈希 | 组合数学 | 计数 |
| 设计 | 贪心 |  |

# [2220. 转换数字的最少位翻转次数](https://leetcode.cn/problems/minimum-bit-flips-to-convert-number){#2220}

{{< tabs "2220" >}}

{{% tab "python" %}}
```python
class Solution:
    def minBitFlips(self, start: int, goal: int) -> int:
        return (start ^ goal).bit_count()
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minBitFlips(int start, int goal) {
        return Integer.bitCount(start ^ goal);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minBitFlips(int start, int goal) {
        return __builtin_popcount(start ^ goal);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minBitFlips(start int, goal int) int {
	return bits.OnesCount(uint(start ^ goal))
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minBitFlips(start: number, goal: number): number {
    return bitCount(start ^ goal);
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
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn min_bit_flips(start: i32, goal: i32) -> i32 {
        (start ^ goal).count_ones() as i32
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number} start
 * @param {number} goal
 * @return {number}
 */
var minBitFlips = function (start, goal) {
    return bitCount(start ^ goal);
};

function bitCount(i) {
    i = i - ((i >>> 1) & 0x55555555);
    i = (i & 0x33333333) + ((i >>> 2) & 0x33333333);
    i = (i + (i >>> 4)) & 0x0f0f0f0f;
    i = i + (i >>> 8);
    i = i + (i >>> 16);
    return i & 0x3f;
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
int minBitFlips(int start, int goal) {
    int x = start ^ goal;
    int ans = 0;
    while (x) {
        ans += (x & 1);
        x >>= 1;
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

<p>一次 <strong>位翻转</strong>&nbsp;定义为将数字&nbsp;<code>x</code>&nbsp;二进制中的一个位进行 <strong>翻转</strong>&nbsp;操作，即将&nbsp;<code>0</code>&nbsp;变成&nbsp;<code>1</code>&nbsp;，或者将&nbsp;<code>1</code>&nbsp;变成&nbsp;<code>0</code>&nbsp;。</p>

<ul>
	<li>比方说，<code>x = 7</code>&nbsp;，二进制表示为&nbsp;<code>111</code>&nbsp;，我们可以选择任意一个位（包含没有显示的前导 0 ）并进行翻转。比方说我们可以翻转最右边一位得到&nbsp;<code>110</code>&nbsp;，或者翻转右边起第二位得到&nbsp;<code>101</code>&nbsp;，或者翻转右边起第五位（这一位是前导 0 ）得到&nbsp;<code>10111</code>&nbsp;等等。</li>
</ul>

<p>给你两个整数&nbsp;<code>start</code> 和&nbsp;<code>goal</code>&nbsp;，请你返回将&nbsp;<code>start</code>&nbsp;转变成&nbsp;<code>goal</code>&nbsp;的&nbsp;<strong>最少位翻转</strong>&nbsp;次数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>start = 10, goal = 7
<b>输出：</b>3
<b>解释：</b>10 和 7 的二进制表示分别为 1010 和 0111 。我们可以通过 3 步将 10 转变成 7 ：
- 翻转右边起第一位得到：101<strong><em>0</em></strong> -&gt; 101<strong><em>1 。</em></strong>
- 翻转右边起第三位：1<strong><em>0</em></strong>11 -&gt; 1<strong><em>1</em></strong>11 。
- 翻转右边起第四位：<strong><em>1</em></strong>111 -&gt; <strong><em>0</em></strong>111 。
我们无法在 3 步内将 10 转变成 7 。所以我们返回 3 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>start = 3, goal = 4
<b>输出：</b>3
<b>解释：</b>3 和 4 的二进制表示分别为 011 和 100 。我们可以通过 3 步将 3 转变成 4 ：
- 翻转右边起第一位：01<strong><em>1</em></strong> -&gt; 01<em><strong>0 </strong></em>。
- 翻转右边起第二位：0<strong><em>1</em></strong>0 -&gt; 0<strong><em>0</em></strong>0 。
- 翻转右边起第三位：<strong><em>0</em></strong>00 -&gt; <strong><em>1</em></strong>00 。
我们无法在 3 步内将 3 变成 4 。所以我们返回 3 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= start, goal &lt;= 10<sup>9</sup></code></li>
</ul>

<p>&nbsp;</p>

<p><strong>注意：</strong>本题与&nbsp;<a href="https://leetcode.cn/problems/hamming-distance/">461. 汉明距离</a>&nbsp;相同。</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：位运算

根据题目描述，我们只需要计算 $\textit{start} \oplus \textit{goal}$ 的二进制表示中有多少个 1 即可。

时间复杂度 $O(\log n)$，其中 $n$ 是题目中整数的大小。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minBitFlips(self, start: int, goal: int) -> int:
        return (start ^ goal).bit_count()
```

#### Java

```java
class Solution {
    public int minBitFlips(int start, int goal) {
        return Integer.bitCount(start ^ goal);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minBitFlips(int start, int goal) {
        return __builtin_popcount(start ^ goal);
    }
};
```

#### Go

```go
func minBitFlips(start int, goal int) int {
	return bits.OnesCount(uint(start ^ goal))
}
```

#### TypeScript

```ts
function minBitFlips(start: number, goal: number): number {
    return bitCount(start ^ goal);
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

#### Rust

```rust
impl Solution {
    pub fn min_bit_flips(start: i32, goal: i32) -> i32 {
        (start ^ goal).count_ones() as i32
    }
}
```

#### JavaScript

```js
/**
 * @param {number} start
 * @param {number} goal
 * @return {number}
 */
var minBitFlips = function (start, goal) {
    return bitCount(start ^ goal);
};

function bitCount(i) {
    i = i - ((i >>> 1) & 0x55555555);
    i = (i & 0x33333333) + ((i >>> 2) & 0x33333333);
    i = (i + (i >>> 4)) & 0x0f0f0f0f;
    i = i + (i >>> 8);
    i = i + (i >>> 16);
    return i & 0x3f;
}
```

#### C

```c
int minBitFlips(int start, int goal) {
    int x = start ^ goal;
    int ans = 0;
    while (x) {
        ans += (x & 1);
        x >>= 1;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2221. 数组的三角和](https://leetcode.cn/problems/find-triangular-sum-of-an-array){#2221}

{{< tabs "2221" >}}

{{% tab "python" %}}
```python
class Solution:
    def triangularSum(self, nums: List[int]) -> int:
        for k in range(len(nums) - 1, 0, -1):
            for i in range(k):
                nums[i] = (nums[i] + nums[i + 1]) % 10
        return nums[0]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int triangularSum(int[] nums) {
        for (int k = nums.length - 1; k > 0; --k) {
            for (int i = 0; i < k; ++i) {
                nums[i] = (nums[i] + nums[i + 1]) % 10;
            }
        }
        return nums[0];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        for (int k = nums.size() - 1; k; --k) {
            for (int i = 0; i < k; ++i) {
                nums[i] = (nums[i] + nums[i + 1]) % 10;
            }
        }
        return nums[0];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func triangularSum(nums []int) int {
	for k := len(nums) - 1; k > 0; k-- {
		for i := 0; i < k; i++ {
			nums[i] = (nums[i] + nums[i+1]) % 10
		}
	}
	return nums[0]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function triangularSum(nums: number[]): number {
    for (let k = nums.length - 1; k; --k) {
        for (let i = 0; i < k; ++i) {
            nums[i] = (nums[i] + nums[i + 1]) % 10;
        }
    }
    return nums[0];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>nums</code>&nbsp;，其中&nbsp;<code>nums[i]</code>&nbsp;是 <code>0</code>&nbsp;到 <code>9</code>&nbsp;之间（两者都包含）的一个数字。</p>

<p><code>nums</code>&nbsp;的 <strong>三角和</strong>&nbsp;是执行以下操作以后最后剩下元素的值：</p>

<ol>
	<li><code>nums</code>&nbsp;初始包含&nbsp;<code>n</code>&nbsp;个元素。如果&nbsp;<code>n == 1</code>&nbsp;，<strong>终止</strong>&nbsp;操作。否则，<strong>创建</strong>&nbsp;一个新的下标从&nbsp;<strong>0</strong>&nbsp;开始的长度为 <code>n - 1</code>&nbsp;的整数数组&nbsp;<code>newNums</code>&nbsp;。</li>
	<li>对于满足&nbsp;<code>0 &lt;= i &lt;&nbsp;n - 1</code>&nbsp;的下标&nbsp;<code>i</code>&nbsp;，<code>newNums[i]</code> <strong>赋值</strong>&nbsp;为&nbsp;<code>(nums[i] + nums[i+1]) % 10</code>&nbsp;，<code>%</code>&nbsp;表示取余运算。</li>
	<li>将&nbsp;<code>newNums</code>&nbsp;<strong>替换</strong> 数组&nbsp;<code>nums</code>&nbsp;。</li>
	<li>从步骤 1 开始&nbsp;<strong>重复</strong>&nbsp;整个过程。</li>
</ol>

<p>请你返回&nbsp;<code>nums</code>&nbsp;的三角和。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2200-2299/2221.Find%20Triangular%20Sum%20of%20an%20Array/images/ex1drawio.png" style="width: 250px; height: 250px;" /></p>

<pre>
<b>输入：</b>nums = [1,2,3,4,5]
<b>输出：</b>8
<strong>解释：</strong>
上图展示了得到数组三角和的过程。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [5]
<b>输出：</b>5
<b>解释：</b>
由于 nums 中只有一个元素，数组的三角和为这个元素自己。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 9</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们可以直接模拟题目描述的操作，对数组 $\textit{nums}$ 进行 $n - 1$ 轮操作，每轮操作都按照题目描述的规则更新数组 $\textit{nums}$。最后返回数组 $\textit{nums}$ 中剩下的唯一元素即可。

时间复杂度 $O(n^2)$，其中 $n$ 是数组 $\textit{nums}$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def triangularSum(self, nums: List[int]) -> int:
        for k in range(len(nums) - 1, 0, -1):
            for i in range(k):
                nums[i] = (nums[i] + nums[i + 1]) % 10
        return nums[0]
```

#### Java

```java
class Solution {
    public int triangularSum(int[] nums) {
        for (int k = nums.length - 1; k > 0; --k) {
            for (int i = 0; i < k; ++i) {
                nums[i] = (nums[i] + nums[i + 1]) % 10;
            }
        }
        return nums[0];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        for (int k = nums.size() - 1; k; --k) {
            for (int i = 0; i < k; ++i) {
                nums[i] = (nums[i] + nums[i + 1]) % 10;
            }
        }
        return nums[0];
    }
};
```

#### Go

```go
func triangularSum(nums []int) int {
	for k := len(nums) - 1; k > 0; k-- {
		for i := 0; i < k; i++ {
			nums[i] = (nums[i] + nums[i+1]) % 10
		}
	}
	return nums[0]
}
```

#### TypeScript

```ts
function triangularSum(nums: number[]): number {
    for (let k = nums.length - 1; k; --k) {
        for (let i = 0; i < k; ++i) {
            nums[i] = (nums[i] + nums[i + 1]) % 10;
        }
    }
    return nums[0];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2222. 选择建筑的方案数](https://leetcode.cn/problems/number-of-ways-to-select-buildings){#2222}

{{< tabs "2222" >}}

{{% tab "python" %}}
```python
class Solution:
    def numberOfWays(self, s: str) -> int:
        l = [0, 0]
        r = [s.count("0"), s.count("1")]
        ans = 0
        for x in map(int, s):
            r[x] -= 1
            ans += l[x ^ 1] * r[x ^ 1]
            l[x] += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long numberOfWays(String s) {
        int n = s.length();
        int[] l = new int[2];
        int[] r = new int[2];
        for (int i = 0; i < n; ++i) {
            r[s.charAt(i) - '0']++;
        }
        long ans = 0;
        for (int i = 0; i < n; ++i) {
            int x = s.charAt(i) - '0';
            r[x]--;
            ans += 1L * l[x ^ 1] * r[x ^ 1];
            l[x]++;
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
    long long numberOfWays(string s) {
        int n = s.size();
        int l[2]{};
        int r[2]{};
        r[0] = ranges::count(s, '0');
        r[1] = n - r[0];
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            int x = s[i] - '0';
            r[x]--;
            ans += 1LL * l[x ^ 1] * r[x ^ 1];
            l[x]++;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numberOfWays(s string) (ans int64) {
	n := len(s)
	l := [2]int{}
	r := [2]int{}
	r[0] = strings.Count(s, "0")
	r[1] = n - r[0]
	for _, c := range s {
		x := int(c - '0')
		r[x]--
		ans += int64(l[x^1] * r[x^1])
		l[x]++
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numberOfWays(s: string): number {
    const n = s.length;
    const l: number[] = [0, 0];
    const r: number[] = [s.split('').filter(c => c === '0').length, 0];
    r[1] = n - r[0];
    let ans: number = 0;
    for (const c of s) {
        const x = c === '0' ? 0 : 1;
        r[x]--;
        ans += l[x ^ 1] * r[x ^ 1];
        l[x]++;
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

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的二进制字符串&nbsp;<code>s</code>&nbsp;，它表示一条街沿途的建筑类型，其中：</p>

<ul>
	<li><code>s[i] = '0'</code>&nbsp;表示第&nbsp;<code>i</code>&nbsp;栋建筑是一栋办公楼，</li>
	<li><code>s[i] = '1'</code>&nbsp;表示第&nbsp;<code>i</code>&nbsp;栋建筑是一间餐厅。</li>
</ul>

<p>作为市政厅的官员，你需要随机<strong>&nbsp;选择</strong>&nbsp;3 栋建筑。然而，为了确保多样性，选出来的 3 栋建筑 <strong>相邻</strong>&nbsp;的两栋不能是同一类型。</p>

<ul>
	<li>比方说，给你&nbsp;<code>s = "0<em><strong>0</strong></em>1<em><strong>1</strong></em>0<em><strong>1</strong></em>"</code>&nbsp;，我们不能选择第&nbsp;<code>1</code>&nbsp;，<code>3</code>&nbsp;和&nbsp;<code>5</code>&nbsp;栋建筑，因为得到的子序列是&nbsp;<code>"0<em><strong>11</strong></em>"</code>&nbsp;，有相邻两栋建筑是同一类型，所以 <strong>不合</strong>&nbsp;题意。</li>
</ul>

<p>请你返回可以选择 3 栋建筑的 <strong>有效方案数</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>s = "001101"
<b>输出：</b>6
<b>解释：</b>
以下下标集合是合法的：
- [0,2,4] ，从 "<em><strong>0</strong></em>0<em><strong>1</strong></em>1<em><strong>0</strong></em>1" 得到 "010"
- [0,3,4] ，从 "<em><strong>0</strong></em>01<em><strong>10</strong></em>1" 得到 "010"
- [1,2,4] ，从 "0<em><strong>01</strong></em>1<em><strong>0</strong></em>1" 得到 "010"
- [1,3,4] ，从 "0<em><strong>0</strong></em>1<em><strong>10</strong></em>1" 得到 "010"
- [2,4,5] ，从 "00<em><strong>1</strong></em>1<em><strong>01</strong></em>" 得到 "101"
- [3,4,5] ，从 "001<em><strong>101</strong></em>" 得到 "101"
没有别的合法选择，所以总共有 6 种方法。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>s = "11100"
<b>输出：</b>0
<b>解释：</b>没有任何符合题意的选择。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s[i]</code>&nbsp;要么是&nbsp;<code>'0'</code>&nbsp;，要么是&nbsp;<code>'1'</code>&nbsp;。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数 + 枚举

根据题目描述，我们需要选择 $3$ 栋建筑，且相邻的两栋不能是同一类型。

我们可以枚举中间的建筑，假设为 $x$，那么左右两边的建筑类型只能是 $x \oplus 1$，其中 $\oplus$ 表示异或运算。因此，我们可以使用两个数组 $l$ 和 $r$ 分别记录左右两边的建筑类型的数量，然后枚举中间的建筑，计算答案即可。

时间复杂度 $O(n)$，其中 $n$ 是字符串 $s$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numberOfWays(self, s: str) -> int:
        l = [0, 0]
        r = [s.count("0"), s.count("1")]
        ans = 0
        for x in map(int, s):
            r[x] -= 1
            ans += l[x ^ 1] * r[x ^ 1]
            l[x] += 1
        return ans
```

#### Java

```java
class Solution {
    public long numberOfWays(String s) {
        int n = s.length();
        int[] l = new int[2];
        int[] r = new int[2];
        for (int i = 0; i < n; ++i) {
            r[s.charAt(i) - '0']++;
        }
        long ans = 0;
        for (int i = 0; i < n; ++i) {
            int x = s.charAt(i) - '0';
            r[x]--;
            ans += 1L * l[x ^ 1] * r[x ^ 1];
            l[x]++;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long numberOfWays(string s) {
        int n = s.size();
        int l[2]{};
        int r[2]{};
        r[0] = ranges::count(s, '0');
        r[1] = n - r[0];
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            int x = s[i] - '0';
            r[x]--;
            ans += 1LL * l[x ^ 1] * r[x ^ 1];
            l[x]++;
        }
        return ans;
    }
};
```

#### Go

```go
func numberOfWays(s string) (ans int64) {
	n := len(s)
	l := [2]int{}
	r := [2]int{}
	r[0] = strings.Count(s, "0")
	r[1] = n - r[0]
	for _, c := range s {
		x := int(c - '0')
		r[x]--
		ans += int64(l[x^1] * r[x^1])
		l[x]++
	}
	return
}
```

#### TypeScript

```ts
function numberOfWays(s: string): number {
    const n = s.length;
    const l: number[] = [0, 0];
    const r: number[] = [s.split('').filter(c => c === '0').length, 0];
    r[1] = n - r[0];
    let ans: number = 0;
    for (const c of s) {
        const x = c === '0' ? 0 : 1;
        r[x]--;
        ans += l[x ^ 1] * r[x ^ 1];
        l[x]++;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2223. 构造字符串的总得分和](https://leetcode.cn/problems/sum-of-scores-of-built-strings){#2223}

{{< tabs "2223" >}}

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

<p>你需要从空字符串开始&nbsp;<strong>构造</strong> 一个长度为 <code>n</code>&nbsp;的字符串 <code>s</code>&nbsp;，构造的过程为每次给当前字符串 <strong>前面</strong>&nbsp;添加 <strong>一个</strong> 字符。构造过程中得到的所有字符串编号为 <code>1</code>&nbsp;到 <code>n</code>&nbsp;，其中长度为 <code>i</code>&nbsp;的字符串编号为 <code>s<sub>i</sub></code>&nbsp;。</p>

<ul>
	<li>比方说，<code>s = "abaca"</code>&nbsp;，<code>s<sub>1</sub> == "a"</code>&nbsp;，<code>s<sub>2</sub> == "ca"</code>&nbsp;，<code>s<sub>3</sub> == "aca"</code>&nbsp;依次类推。</li>
</ul>

<p><code>s<sub>i</sub></code>&nbsp;的 <strong>得分</strong>&nbsp;为&nbsp;<code>s<sub>i</sub></code> 和&nbsp;<code>s<sub>n</sub></code>&nbsp;的 <strong>最长公共前缀</strong> 的长度（注意&nbsp;<code>s == s<sub>n</sub></code>&nbsp;）。</p>

<p>给你最终的字符串&nbsp;<code>s</code>&nbsp;，请你返回每一个<em>&nbsp;</em><code>s<sub>i</sub></code>&nbsp;的&nbsp;<strong>得分之和</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>s = "babab"
<b>输出：</b>9
<b>解释：</b>
s<sub>1</sub> == "b" ，最长公共前缀是 "b" ，得分为 1 。
s<sub>2</sub> == "ab" ，没有公共前缀，得分为 0 。
s<sub>3</sub> == "bab" ，最长公共前缀为 "bab" ，得分为 3 。
s<sub>4</sub> == "abab" ，没有公共前缀，得分为 0 。
s<sub>5</sub> == "babab" ，最长公共前缀为 "babab" ，得分为 5 。
得分和为 1 + 0 + 3 + 0 + 5 = 9 ，所以我们返回 9 。</pre>

<p><strong>示例 2 ：</strong></p>

<pre>
<b>输入：</b>s = "azbazbzaz"
<b>输出：</b>14
<b>解释：</b>
s<sub>2</sub> == "az" ，最长公共前缀为 "az" ，得分为 2 。
s<sub>6</sub> == "azbzaz" ，最长公共前缀为 "azb" ，得分为 3 。
s<sub>9</sub> == "azbazbzaz" ，最长公共前缀为 "azbazbzaz" ，得分为 9 。
其他 s<sub>i</sub> 得分均为 0 。
得分和为 2 + 3 + 9 = 14 ，所以我们返回 14 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code>&nbsp;只包含小写英文字母。</li>
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

# [2224. 转化时间需要的最少操作数](https://leetcode.cn/problems/minimum-number-of-operations-to-convert-time){#2224}

{{< tabs "2224" >}}

{{% tab "python" %}}
```python
class Solution:
    def convertTime(self, current: str, correct: str) -> int:
        a = int(current[:2]) * 60 + int(current[3:])
        b = int(correct[:2]) * 60 + int(correct[3:])
        ans, d = 0, b - a
        for i in [60, 15, 5, 1]:
            ans += d // i
            d %= i
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int convertTime(String current, String correct) {
        int a = Integer.parseInt(current.substring(0, 2)) * 60
            + Integer.parseInt(current.substring(3));
        int b = Integer.parseInt(correct.substring(0, 2)) * 60
            + Integer.parseInt(correct.substring(3));
        int ans = 0, d = b - a;
        for (int i : Arrays.asList(60, 15, 5, 1)) {
            ans += d / i;
            d %= i;
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
    int convertTime(string current, string correct) {
        int a = stoi(current.substr(0, 2)) * 60 + stoi(current.substr(3, 2));
        int b = stoi(correct.substr(0, 2)) * 60 + stoi(correct.substr(3, 2));
        int ans = 0, d = b - a;
        vector<int> inc = {60, 15, 5, 1};
        for (int i : inc) {
            ans += d / i;
            d %= i;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func convertTime(current string, correct string) int {
	parse := func(s string) int {
		h := int(s[0]-'0')*10 + int(s[1]-'0')
		m := int(s[3]-'0')*10 + int(s[4]-'0')
		return h*60 + m
	}
	a, b := parse(current), parse(correct)
	ans, d := 0, b-a
	for _, i := range []int{60, 15, 5, 1} {
		ans += d / i
		d %= i
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

<p>给你两个字符串 <code>current</code> 和 <code>correct</code> ，表示两个 <strong>24 小时制时间</strong> 。</p>

<p><strong>24 小时制时间</strong> 按 <code>"HH:MM"</code> 进行格式化，其中 <code>HH</code> 在 <code>00</code> 和 <code>23</code> 之间，而 <code>MM</code> 在 <code>00</code> 和 <code>59</code> 之间。最早的 24 小时制时间为 <code>00:00</code> ，最晚的是 <code>23:59</code> 。</p>

<p>在一步操作中，你可以将 <code>current</code> 这个时间增加 <code>1</code>、<code>5</code>、<code>15</code> 或 <code>60</code> 分钟。你可以执行这一操作 <strong>任意</strong> 次数。</p>

<p>返回将&nbsp;<code>current</code><em> </em>转化为<em> </em><code>correct</code> 需要的 <strong>最少操作数</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>current = "02:30", correct = "04:35"
<strong>输出：</strong>3
<strong>解释：
</strong>可以按下述 3 步操作将 current 转换为 correct ：
- 为 current 加 60 分钟，current 变为 "03:30" 。
- 为 current 加 60 分钟，current 变为 "04:30" 。 
- 为 current 加 5 分钟，current 变为 "04:35" 。
可以证明，无法用少于 3 步操作将 current 转化为 correct 。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>current = "11:00", correct = "11:01"
<strong>输出：</strong>1
<strong>解释：</strong>只需要为 current 加一分钟，所以最小操作数是 1 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>current</code> 和 <code>correct</code> 都符合 <code>"HH:MM"</code> 格式</li>
	<li><code>current &lt;= correct</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def convertTime(self, current: str, correct: str) -> int:
        a = int(current[:2]) * 60 + int(current[3:])
        b = int(correct[:2]) * 60 + int(correct[3:])
        ans, d = 0, b - a
        for i in [60, 15, 5, 1]:
            ans += d // i
            d %= i
        return ans
```

#### Java

```java
class Solution {
    public int convertTime(String current, String correct) {
        int a = Integer.parseInt(current.substring(0, 2)) * 60
            + Integer.parseInt(current.substring(3));
        int b = Integer.parseInt(correct.substring(0, 2)) * 60
            + Integer.parseInt(correct.substring(3));
        int ans = 0, d = b - a;
        for (int i : Arrays.asList(60, 15, 5, 1)) {
            ans += d / i;
            d %= i;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int convertTime(string current, string correct) {
        int a = stoi(current.substr(0, 2)) * 60 + stoi(current.substr(3, 2));
        int b = stoi(correct.substr(0, 2)) * 60 + stoi(correct.substr(3, 2));
        int ans = 0, d = b - a;
        vector<int> inc = {60, 15, 5, 1};
        for (int i : inc) {
            ans += d / i;
            d %= i;
        }
        return ans;
    }
};
```

#### Go

```go
func convertTime(current string, correct string) int {
	parse := func(s string) int {
		h := int(s[0]-'0')*10 + int(s[1]-'0')
		m := int(s[3]-'0')*10 + int(s[4]-'0')
		return h*60 + m
	}
	a, b := parse(current), parse(correct)
	ans, d := 0, b-a
	for _, i := range []int{60, 15, 5, 1} {
		ans += d / i
		d %= i
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2225. 找出输掉零场或一场比赛的玩家](https://leetcode.cn/problems/find-players-with-zero-or-one-losses){#2225}

{{< tabs "2225" >}}

{{% tab "python" %}}
```python
class Solution:
    def findWinners(self, matches: List[List[int]]) -> List[List[int]]:
        cnt = Counter()
        for winner, loser in matches:
            if winner not in cnt:
                cnt[winner] = 0
            cnt[loser] += 1
        ans = [[], []]
        for x, v in sorted(cnt.items()):
            if v < 2:
                ans[v].append(x)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<List<Integer>> findWinners(int[][] matches) {
        Map<Integer, Integer> cnt = new HashMap<>();
        for (var e : matches) {
            cnt.putIfAbsent(e[0], 0);
            cnt.merge(e[1], 1, Integer::sum);
        }
        List<List<Integer>> ans = List.of(new ArrayList<>(), new ArrayList<>());
        for (var e : cnt.entrySet()) {
            if (e.getValue() < 2) {
                ans.get(e.getValue()).add(e.getKey());
            }
        }
        Collections.sort(ans.get(0));
        Collections.sort(ans.get(1));
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> cnt;
        for (auto& e : matches) {
            if (!cnt.contains(e[0])) {
                cnt[e[0]] = 0;
            }
            ++cnt[e[1]];
        }
        vector<vector<int>> ans(2);
        for (auto& [x, v] : cnt) {
            if (v < 2) {
                ans[v].push_back(x);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findWinners(matches [][]int) [][]int {
	cnt := map[int]int{}
	for _, e := range matches {
		if _, ok := cnt[e[0]]; !ok {
			cnt[e[0]] = 0
		}
		cnt[e[1]]++
	}
	ans := make([][]int, 2)
	for x, v := range cnt {
		if v < 2 {
			ans[v] = append(ans[v], x)
		}
	}
	sort.Ints(ans[0])
	sort.Ints(ans[1])
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findWinners(matches: number[][]): number[][] {
    const cnt: Map<number, number> = new Map();
    for (const [winner, loser] of matches) {
        if (!cnt.has(winner)) {
            cnt.set(winner, 0);
        }
        cnt.set(loser, (cnt.get(loser) || 0) + 1);
    }
    const ans: number[][] = [[], []];
    for (const [x, v] of cnt) {
        if (v < 2) {
            ans[v].push(x);
        }
    }
    ans[0].sort((a, b) => a - b);
    ans[1].sort((a, b) => a - b);
    return ans;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[][]} matches
 * @return {number[][]}
 */
var findWinners = function (matches) {
    const cnt = new Map();
    for (const [winner, loser] of matches) {
        if (!cnt.has(winner)) {
            cnt.set(winner, 0);
        }
        cnt.set(loser, (cnt.get(loser) || 0) + 1);
    }
    const ans = [[], []];
    for (const [x, v] of cnt) {
        if (v < 2) {
            ans[v].push(x);
        }
    }
    ans[0].sort((a, b) => a - b);
    ans[1].sort((a, b) => a - b);
    return ans;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>matches</code> 其中 <code>matches[i] = [winner<sub>i</sub>, loser<sub>i</sub>]</code> 表示在一场比赛中 <code>winner<sub>i</sub></code> 击败了 <code>loser<sub>i</sub></code> 。</p>

<p>返回一个长度为 2 的列表<em> </em><code>answer</code> ：</p>

<ul>
	<li><code>answer[0]</code> 是所有 <strong>没有</strong> 输掉任何比赛的玩家列表。</li>
	<li><code>answer[1]</code> 是所有恰好输掉 <strong>一场</strong> 比赛的玩家列表。</li>
</ul>

<p>两个列表中的值都应该按 <strong>递增</strong> 顺序返回。</p>

<p><strong>注意：</strong></p>

<ul>
	<li>只考虑那些参与 <strong>至少一场</strong> 比赛的玩家。</li>
	<li>生成的测试用例保证 <strong>不存在</strong> 两场比赛结果 <strong>相同</strong> 。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>matches = [[1,3],[2,3],[3,6],[5,6],[5,7],[4,5],[4,8],[4,9],[10,4],[10,9]]
<strong>输出：</strong>[[1,2,10],[4,5,7,8]]
<strong>解释：</strong>
玩家 1、2 和 10 都没有输掉任何比赛。
玩家 4、5、7 和 8 每个都输掉一场比赛。
玩家 3、6 和 9 每个都输掉两场比赛。
因此，answer[0] = [1,2,10] 和 answer[1] = [4,5,7,8] 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>matches = [[2,3],[1,3],[5,4],[6,4]]
<strong>输出：</strong>[[1,2,5,6],[]]
<strong>解释：</strong>
玩家 1、2、5 和 6 都没有输掉任何比赛。
玩家 3 和 4 每个都输掉两场比赛。
因此，answer[0] = [1,2,5,6] 和 answer[1] = [] 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= matches.length &lt;= 10<sup>5</sup></code></li>
	<li><code>matches[i].length == 2</code></li>
	<li><code>1 &lt;= winner<sub>i</sub>, loser<sub>i</sub> &lt;= 10<sup>5</sup></code></li>
	<li><code>winner<sub>i</sub> != loser<sub>i</sub></code></li>
	<li>所有 <code>matches[i]</code> <strong>互不相同</strong></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 排序

我们用一个哈希表 $\textit{cnt}$ 记录每个玩家输掉的比赛场次。

然后遍历哈希表，将输掉 $0$ 场比赛的玩家放入 $\textit{ans}[0]$，将输掉 $1$ 场比赛的玩家放入 $\textit{ans}[1]$。

最后将 $\textit{ans}[0]$ 和 $\textit{ans}[1]$ 按照升序排序，返回结果。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为比赛场次数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findWinners(self, matches: List[List[int]]) -> List[List[int]]:
        cnt = Counter()
        for winner, loser in matches:
            if winner not in cnt:
                cnt[winner] = 0
            cnt[loser] += 1
        ans = [[], []]
        for x, v in sorted(cnt.items()):
            if v < 2:
                ans[v].append(x)
        return ans
```

#### Java

```java
class Solution {
    public List<List<Integer>> findWinners(int[][] matches) {
        Map<Integer, Integer> cnt = new HashMap<>();
        for (var e : matches) {
            cnt.putIfAbsent(e[0], 0);
            cnt.merge(e[1], 1, Integer::sum);
        }
        List<List<Integer>> ans = List.of(new ArrayList<>(), new ArrayList<>());
        for (var e : cnt.entrySet()) {
            if (e.getValue() < 2) {
                ans.get(e.getValue()).add(e.getKey());
            }
        }
        Collections.sort(ans.get(0));
        Collections.sort(ans.get(1));
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> cnt;
        for (auto& e : matches) {
            if (!cnt.contains(e[0])) {
                cnt[e[0]] = 0;
            }
            ++cnt[e[1]];
        }
        vector<vector<int>> ans(2);
        for (auto& [x, v] : cnt) {
            if (v < 2) {
                ans[v].push_back(x);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func findWinners(matches [][]int) [][]int {
	cnt := map[int]int{}
	for _, e := range matches {
		if _, ok := cnt[e[0]]; !ok {
			cnt[e[0]] = 0
		}
		cnt[e[1]]++
	}
	ans := make([][]int, 2)
	for x, v := range cnt {
		if v < 2 {
			ans[v] = append(ans[v], x)
		}
	}
	sort.Ints(ans[0])
	sort.Ints(ans[1])
	return ans
}
```

#### TypeScript

```ts
function findWinners(matches: number[][]): number[][] {
    const cnt: Map<number, number> = new Map();
    for (const [winner, loser] of matches) {
        if (!cnt.has(winner)) {
            cnt.set(winner, 0);
        }
        cnt.set(loser, (cnt.get(loser) || 0) + 1);
    }
    const ans: number[][] = [[], []];
    for (const [x, v] of cnt) {
        if (v < 2) {
            ans[v].push(x);
        }
    }
    ans[0].sort((a, b) => a - b);
    ans[1].sort((a, b) => a - b);
    return ans;
}
```

#### JavaScript

```js
/**
 * @param {number[][]} matches
 * @return {number[][]}
 */
var findWinners = function (matches) {
    const cnt = new Map();
    for (const [winner, loser] of matches) {
        if (!cnt.has(winner)) {
            cnt.set(winner, 0);
        }
        cnt.set(loser, (cnt.get(loser) || 0) + 1);
    }
    const ans = [[], []];
    for (const [x, v] of cnt) {
        if (v < 2) {
            ans[v].push(x);
        }
    }
    ans[0].sort((a, b) => a - b);
    ans[1].sort((a, b) => a - b);
    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2226. 每个小孩最多能分到多少糖果](https://leetcode.cn/problems/maximum-candies-allocated-to-k-children){#2226}

{{< tabs "2226" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumCandies(self, candies: List[int], k: int) -> int:
        l, r = 0, max(candies)
        while l < r:
            mid = (l + r + 1) >> 1
            if sum(x // mid for x in candies) >= k:
                l = mid
            else:
                r = mid - 1
        return l
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maximumCandies(int[] candies, long k) {
        int l = 0, r = Arrays.stream(candies).max().getAsInt();
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            long cnt = 0;
            for (int x : candies) {
                cnt += x / mid;
            }
            if (cnt >= k) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int l = 0, r = ranges::max(candies);
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            long long cnt = 0;
            for (int x : candies) {
                cnt += x / mid;
            }
            if (cnt >= k) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumCandies(candies []int, k int64) int {
	return sort.Search(1e7, func(v int) bool {
		v++
		var cnt int64
		for _, x := range candies {
			cnt += int64(x / v)
		}
		return cnt < k
	})
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumCandies(candies: number[], k: number): number {
    let [l, r] = [0, Math.max(...candies)];
    while (l < r) {
        const mid = (l + r + 1) >> 1;
        const cnt = candies.reduce((acc, cur) => acc + Math.floor(cur / mid), 0);
        if (cnt >= k) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return l;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个 <strong>下标从 0 开始</strong> 的整数数组 <code>candies</code> 。数组中的每个元素表示大小为 <code>candies[i]</code> 的一堆糖果。你可以将每堆糖果分成任意数量的 <strong>子堆</strong> ，但 <strong>无法</strong> 再将两堆合并到一起。</p>

<p>另给你一个整数 <code>k</code> 。你需要将这些糖果分配给 <code>k</code> 个小孩，使每个小孩分到 <strong>相同</strong> 数量的糖果。每个小孩可以拿走 <strong>至多一堆</strong> 糖果，有些糖果可能会不被分配。</p>

<p>返回每个小孩可以拿走的 <strong>最大糖果数目</strong><em> </em>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>candies = [5,8,6], k = 3
<strong>输出：</strong>5
<strong>解释：</strong>可以将 candies[1] 分成大小分别为 5 和 3 的两堆，然后把 candies[2] 分成大小分别为 5 和 1 的两堆。现在就有五堆大小分别为 5、5、3、5 和 1 的糖果。可以把 3 堆大小为 5 的糖果分给 3 个小孩。可以证明无法让每个小孩得到超过 5 颗糖果。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>candies = [2,5], k = 11
<strong>输出：</strong>0
<strong>解释：</strong>总共有 11 个小孩，但只有 7 颗糖果，但如果要分配糖果的话，必须保证每个小孩至少能得到 1 颗糖果。因此，最后每个小孩都没有得到糖果，答案是 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= candies.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= candies[i] &lt;= 10<sup>7</sup></code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>12</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二分查找

我们注意到，如果每个小孩能分到糖果数 $v$，那么对于任意 $v' \lt v$，每个小孩也能分到 $v'$ 颗糖果。因此，我们可以使用二分查找的方法找到最大的 $v$，使得每个小孩能分到 $v$ 颗糖果。

我们定义二分查找的左边界 $l = 0$，右边界 $r = \max(\text{candies})$，其中 $\max(\text{candies})$ 表示数组 $\text{candies}$ 中的最大值。在二分查找的过程中，我们每次取 $v$ 的中间值 $v = \left\lfloor \frac{l + r + 1}{2} \right\rfloor$，然后计算每个小孩能分到的糖果数 $v$ 的总和，如果总和大于等于 $k$，则说明每个小孩能分到 $v$ 颗糖果，此时我们更新左边界 $l = v$，否则我们更新右边界 $r = v - 1$。最终，当 $l = r$ 时，我们找到了最大的 $v$。

时间复杂度 $O(n \times \log M)$，其中 $n$ 表示数组 $\text{candies}$ 的长度，而 $M$ 表示数组 $\text{candies}$ 中的最大值。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumCandies(self, candies: List[int], k: int) -> int:
        l, r = 0, max(candies)
        while l < r:
            mid = (l + r + 1) >> 1
            if sum(x // mid for x in candies) >= k:
                l = mid
            else:
                r = mid - 1
        return l
```

#### Java

```java
class Solution {
    public int maximumCandies(int[] candies, long k) {
        int l = 0, r = Arrays.stream(candies).max().getAsInt();
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            long cnt = 0;
            for (int x : candies) {
                cnt += x / mid;
            }
            if (cnt >= k) {
                l = mid;
            } else {
                r = mid - 1;
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
    int maximumCandies(vector<int>& candies, long long k) {
        int l = 0, r = ranges::max(candies);
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            long long cnt = 0;
            for (int x : candies) {
                cnt += x / mid;
            }
            if (cnt >= k) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};
```

#### Go

```go
func maximumCandies(candies []int, k int64) int {
	return sort.Search(1e7, func(v int) bool {
		v++
		var cnt int64
		for _, x := range candies {
			cnt += int64(x / v)
		}
		return cnt < k
	})
}
```

#### TypeScript

```ts
function maximumCandies(candies: number[], k: number): number {
    let [l, r] = [0, Math.max(...candies)];
    while (l < r) {
        const mid = (l + r + 1) >> 1;
        const cnt = candies.reduce((acc, cur) => acc + Math.floor(cur / mid), 0);
        if (cnt >= k) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return l;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2227. 加密解密字符串](https://leetcode.cn/problems/encrypt-and-decrypt-strings){#2227}

{{< tabs "2227" >}}

{{% tab "python" %}}
```python
class Encrypter:
    def __init__(self, keys: List[str], values: List[str], dictionary: List[str]):
        self.mp = dict(zip(keys, values))
        self.cnt = Counter(self.encrypt(v) for v in dictionary)

    def encrypt(self, word1: str) -> str:
        res = []
        for c in word1:
            if c not in self.mp:
                return ''
            res.append(self.mp[c])
        return ''.join(res)

    def decrypt(self, word2: str) -> int:
        return self.cnt[word2]


# Your Encrypter object will be instantiated and called as such:
# obj = Encrypter(keys, values, dictionary)
# param_1 = obj.encrypt(word1)
# param_2 = obj.decrypt(word2)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Encrypter {
    private Map<Character, String> mp = new HashMap<>();
    private Map<String, Integer> cnt = new HashMap<>();

    public Encrypter(char[] keys, String[] values, String[] dictionary) {
        for (int i = 0; i < keys.length; ++i) {
            mp.put(keys[i], values[i]);
        }
        for (String w : dictionary) {
            cnt.merge(encrypt(w), 1, Integer::sum);
        }
    }

    public String encrypt(String word1) {
        StringBuilder sb = new StringBuilder();
        for (char c : word1.toCharArray()) {
            if (!mp.containsKey(c)) {
                return "";
            }
            sb.append(mp.get(c));
        }
        return sb.toString();
    }

    public int decrypt(String word2) {
        return cnt.getOrDefault(word2, 0);
    }
}

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter obj = new Encrypter(keys, values, dictionary);
 * String param_1 = obj.encrypt(word1);
 * int param_2 = obj.decrypt(word2);
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Encrypter {
public:
    unordered_map<string, int> cnt;
    unordered_map<char, string> mp;

    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        for (int i = 0; i < keys.size(); ++i) {
            mp[keys[i]] = values[i];
        }
        for (auto v : dictionary) {
            cnt[encrypt(v)]++;
        }
    }

    string encrypt(string word1) {
        string res = "";
        for (char c : word1) {
            if (!mp.count(c)) {
                return "";
            }
            res += mp[c];
        }
        return res;
    }

    int decrypt(string word2) {
        return cnt[word2];
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type Encrypter struct {
	mp  map[byte]string
	cnt map[string]int
}

func Constructor(keys []byte, values []string, dictionary []string) Encrypter {
	mp := map[byte]string{}
	cnt := map[string]int{}
	for i, k := range keys {
		mp[k] = values[i]
	}
	e := Encrypter{mp, cnt}
	for _, v := range dictionary {
		e.cnt[e.Encrypt(v)]++
	}
	return e
}

func (this *Encrypter) Encrypt(word1 string) string {
	var ans strings.Builder
	for _, c := range word1 {
		if v, ok := this.mp[byte(c)]; ok {
			ans.WriteString(v)
		} else {
			return ""
		}
	}
	return ans.String()
}

func (this *Encrypter) Decrypt(word2 string) int {
	return this.cnt[word2]
}

/**
 * Your Encrypter object will be instantiated and called as such:
 * obj := Constructor(keys, values, dictionary);
 * param_1 := obj.Encrypt(word1);
 * param_2 := obj.Decrypt(word2);
 */
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class Encrypter {
    private mp: Map<string, string> = new Map();
    private cnt: Map<string, number> = new Map();

    constructor(keys: string[], values: string[], dictionary: string[]) {
        for (let i = 0; i < keys.length; i++) {
            this.mp.set(keys[i], values[i]);
        }
        for (const w of dictionary) {
            const encrypted = this.encrypt(w);
            if (encrypted !== '') {
                this.cnt.set(encrypted, (this.cnt.get(encrypted) || 0) + 1);
            }
        }
    }

    encrypt(word: string): string {
        let res = '';
        for (const c of word) {
            if (!this.mp.has(c)) {
                return '';
            }
            res += this.mp.get(c);
        }
        return res;
    }

    decrypt(word: string): number {
        return this.cnt.get(word) || 0;
    }
}

/**
 * Your Encrypter object will be instantiated and called as such:
 * const obj = new Encrypter(keys, values, dictionary);
 * const param_1 = obj.encrypt(word1);
 * const param_2 = obj.decrypt(word2);
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符数组 <code>keys</code> ，由若干 <strong>互不相同</strong> 的字符组成。还有一个字符串数组 <code>values</code> ，内含若干长度为 2 的字符串。另给你一个字符串数组 <code>dictionary</code> ，包含解密后所有允许的原字符串。请你设计并实现一个支持加密及解密下标从 <strong>0</strong> 开始字符串的数据结构。</p>

<p>字符串 <strong>加密</strong> 按下述步骤进行：</p>

<ol>
	<li>对字符串中的每个字符 <code>c</code> ，先从 <code>keys</code> 中找出满足 <code>keys[i] == c</code> 的下标 <code>i</code> 。</li>
	<li>在字符串中，用&nbsp;<code>values[i]</code> 替换字符 <code>c</code> 。</li>
</ol>

<p>请注意，如果&nbsp;<code>keys</code> 中不存在字符串中的字符，则无法执行加密过程，返回空字符串 <code>""</code>。</p>

<p>字符串 <strong>解密</strong> 按下述步骤进行：</p>

<ol>
	<li>将字符串每相邻 2 个字符划分为一个子字符串，对于每个子字符串 <code>s</code> ，找出满足 <code>values[i] == s</code> 的一个下标 <code>i</code> 。如果存在多个有效的 <code>i</code> ，从中选择 <strong>任意</strong> 一个。这意味着一个字符串解密可能得到多个解密字符串。</li>
	<li>在字符串中，用 <code>keys[i]</code> 替换 <code>s</code> 。</li>
</ol>

<p>实现 <code>Encrypter</code> 类：</p>

<ul>
	<li><code>Encrypter(char[] keys, String[] values, String[] dictionary)</code> 用 <code>keys</code>、<code>values</code> 和 <code>dictionary</code> 初始化 <code>Encrypter</code> 类。</li>
	<li><code>String encrypt(String word1)</code> 按上述加密过程完成对 <code>word1</code> 的加密，并返回加密后的字符串。</li>
	<li><code>int decrypt(String word2)</code> 统计并返回可以由 <code>word2</code> 解密得到且出现在 <code>dictionary</code> 中的字符串数目。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre>
<strong>输入：</strong>
["Encrypter", "encrypt", "decrypt"]
[[['a', 'b', 'c', 'd'], ["ei", "zf", "ei", "am"], ["abcd", "acbd", "adbc", "badc", "dacb", "cadb", "cbda", "abad"]], ["abcd"], ["eizfeiam"]]
<strong>输出：</strong>
[null, "eizfeiam", 2]

<strong>解释：</strong>
Encrypter encrypter = new Encrypter([['a', 'b', 'c', 'd'], ["ei", "zf", "ei", "am"], ["abcd", "acbd", "adbc", "badc", "dacb", "cadb", "cbda", "abad"]);
encrypter.encrypt("abcd"); // 返回 "eizfeiam"。 
&nbsp;                          // 'a' 映射为 "ei"，'b' 映射为 "zf"，'c' 映射为 "ei"，'d' 映射为 "am"。
encrypter.decrypt("eizfeiam"); // return 2. 
                              // "ei" 可以映射为 'a' 或 'c'，"zf" 映射为 'b'，"am" 映射为 'd'。 
                              // 因此，解密后可以得到的字符串是 "abad"，"cbad"，"abcd" 和 "cbcd"。 
                              // 其中 2 个字符串，"abad" 和 "abcd"，在 dictionary 中出现，所以答案是 2 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= keys.length == values.length &lt;= 26</code></li>
	<li><code>values[i].length == 2</code></li>
	<li><code>1 &lt;= dictionary.length &lt;= 100</code></li>
	<li><code>1 &lt;= dictionary[i].length &lt;= 100</code></li>
	<li>所有 <code>keys[i]</code> 和 <code>dictionary[i]</code> <strong>互不相同</strong></li>
	<li><code>1 &lt;= word1.length &lt;= 2000</code></li>
	<li><code>1 &lt;= word2.length &lt;= 200</code></li>
	<li>所有 <code>word1[i]</code> 都出现在 <code>keys</code> 中</li>
	<li><code>word2.length</code> 是偶数</li>
	<li><code>keys</code>、<code>values[i]</code>、<code>dictionary[i]</code>、<code>word1</code> 和 <code>word2</code> 只含小写英文字母</li>
	<li>至多调用 <code>encrypt</code> 和 <code>decrypt</code> <strong>总计</strong> <code>200</code> 次</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

我们用一个哈希表 $\textit{mp}$ 记录每个字符的加密结果，用另一个哈希表 $\textit{cnt}$ 记录每个加密结果出现的次数。

在构造函数中，我们遍历 $\textit{keys}$ 和 $\textit{values}$，将每个字符和其对应的加密结果存入 $\textit{mp}$ 中。然后遍历 $\textit{dictionary}$，统计每个加密结果出现的次数。时间复杂度 $(n + m)$，其中 $n$ 和 $m$ 分别是 $\textit{keys}$ 和 $\textit{dictionary}$ 的长度。

在加密函数中，我们遍历输入字符串 $\textit{word1}$ 的每个字符，查找其加密结果并拼接起来。如果某个字符没有对应的加密结果，说明无法加密，返回空字符串。时间复杂度 $O(k)$，其中 $k$ 是 $\textit{word1}$ 的长度。

在解密函数中，我们直接返回 $\textit{cnt}$ 中 $\textit{word2}$ 对应的次数。时间复杂度 $O(1)$。

空间复杂度 $O(n + m)$。

<!-- tabs:start -->

#### Python3

```python
class Encrypter:
    def __init__(self, keys: List[str], values: List[str], dictionary: List[str]):
        self.mp = dict(zip(keys, values))
        self.cnt = Counter(self.encrypt(v) for v in dictionary)

    def encrypt(self, word1: str) -> str:
        res = []
        for c in word1:
            if c not in self.mp:
                return ''
            res.append(self.mp[c])
        return ''.join(res)

    def decrypt(self, word2: str) -> int:
        return self.cnt[word2]


# Your Encrypter object will be instantiated and called as such:
# obj = Encrypter(keys, values, dictionary)
# param_1 = obj.encrypt(word1)
# param_2 = obj.decrypt(word2)
```

#### Java

```java
class Encrypter {
    private Map<Character, String> mp = new HashMap<>();
    private Map<String, Integer> cnt = new HashMap<>();

    public Encrypter(char[] keys, String[] values, String[] dictionary) {
        for (int i = 0; i < keys.length; ++i) {
            mp.put(keys[i], values[i]);
        }
        for (String w : dictionary) {
            cnt.merge(encrypt(w), 1, Integer::sum);
        }
    }

    public String encrypt(String word1) {
        StringBuilder sb = new StringBuilder();
        for (char c : word1.toCharArray()) {
            if (!mp.containsKey(c)) {
                return "";
            }
            sb.append(mp.get(c));
        }
        return sb.toString();
    }

    public int decrypt(String word2) {
        return cnt.getOrDefault(word2, 0);
    }
}

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter obj = new Encrypter(keys, values, dictionary);
 * String param_1 = obj.encrypt(word1);
 * int param_2 = obj.decrypt(word2);
 */
```

#### C++

```cpp
class Encrypter {
public:
    unordered_map<string, int> cnt;
    unordered_map<char, string> mp;

    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        for (int i = 0; i < keys.size(); ++i) {
            mp[keys[i]] = values[i];
        }
        for (auto v : dictionary) {
            cnt[encrypt(v)]++;
        }
    }

    string encrypt(string word1) {
        string res = "";
        for (char c : word1) {
            if (!mp.count(c)) {
                return "";
            }
            res += mp[c];
        }
        return res;
    }

    int decrypt(string word2) {
        return cnt[word2];
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */
```

#### Go

```go
type Encrypter struct {
	mp  map[byte]string
	cnt map[string]int
}

func Constructor(keys []byte, values []string, dictionary []string) Encrypter {
	mp := map[byte]string{}
	cnt := map[string]int{}
	for i, k := range keys {
		mp[k] = values[i]
	}
	e := Encrypter{mp, cnt}
	for _, v := range dictionary {
		e.cnt[e.Encrypt(v)]++
	}
	return e
}

func (this *Encrypter) Encrypt(word1 string) string {
	var ans strings.Builder
	for _, c := range word1 {
		if v, ok := this.mp[byte(c)]; ok {
			ans.WriteString(v)
		} else {
			return ""
		}
	}
	return ans.String()
}

func (this *Encrypter) Decrypt(word2 string) int {
	return this.cnt[word2]
}

/**
 * Your Encrypter object will be instantiated and called as such:
 * obj := Constructor(keys, values, dictionary);
 * param_1 := obj.Encrypt(word1);
 * param_2 := obj.Decrypt(word2);
 */
```

#### TypeScript

```ts
class Encrypter {
    private mp: Map<string, string> = new Map();
    private cnt: Map<string, number> = new Map();

    constructor(keys: string[], values: string[], dictionary: string[]) {
        for (let i = 0; i < keys.length; i++) {
            this.mp.set(keys[i], values[i]);
        }
        for (const w of dictionary) {
            const encrypted = this.encrypt(w);
            if (encrypted !== '') {
                this.cnt.set(encrypted, (this.cnt.get(encrypted) || 0) + 1);
            }
        }
    }

    encrypt(word: string): string {
        let res = '';
        for (const c of word) {
            if (!this.mp.has(c)) {
                return '';
            }
            res += this.mp.get(c);
        }
        return res;
    }

    decrypt(word: string): number {
        return this.cnt.get(word) || 0;
    }
}

/**
 * Your Encrypter object will be instantiated and called as such:
 * const obj = new Encrypter(keys, values, dictionary);
 * const param_1 = obj.encrypt(word1);
 * const param_2 = obj.decrypt(word2);
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2228. 7 天内两次购买的用户 🔒](https://leetcode.cn/problems/users-with-two-purchases-within-seven-days){#2228}

{{< tabs "2228" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    t AS (
        SELECT
            user_id,
            DATEDIFF(
                purchase_date,
                LAG(purchase_date, 1) OVER (
                    PARTITION BY user_id
                    ORDER BY purchase_date
                )
            ) AS d
        FROM Purchases
    )
SELECT DISTINCT user_id
FROM t
WHERE d <= 7
ORDER BY user_id;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表: <code>Purchases</code></p>

<pre>
+---------------+------+
| Column Name   | Type |
+---------------+------+
| purchase_id   | int  |
| user_id       | int  |
| purchase_date | date |
+---------------+------+
purchase_id 包含唯一值。
该表包含用户从某个零售商购买的日期的日志。
</pre>

<p>&nbsp;</p>

<p>编写解决方案，获取&nbsp;<strong>最多&nbsp;</strong>间隔 <code>7</code> 天进行两次购买的用户的 id。</p>

<p data-group="1-1">返回<em>按 <code>user_id</code>&nbsp;排序的结果表。</em></p>

<p>结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> 
Purchases 表:
+-------------+---------+---------------+
| purchase_id | user_id | purchase_date |
+-------------+---------+---------------+
| 4           | 2       | 2022-03-13    |
| 1           | 5       | 2022-02-11    |
| 3           | 7       | 2022-06-19    |
| 6           | 2       | 2022-03-20    |
| 5           | 7       | 2022-06-19    |
| 2           | 2       | 2022-06-08    |
+-------------+---------+---------------+
<strong>输出:</strong> 
+---------+
| user_id |
+---------+
| 2       |
| 7       |
+---------+
<strong>解释:</strong> 
用户 2 在 2022-03-13 和 2022-03-20 有两次购买。由于第二次购买是在第一次购买后的 7 天内，我们添加了他们的 ID。
用户 5 只购买了 1 次。
用户 7 在同一天有两次购买，所以我们添加了他们的 ID。</pre>

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
    t AS (
        SELECT
            user_id,
            DATEDIFF(
                purchase_date,
                LAG(purchase_date, 1) OVER (
                    PARTITION BY user_id
                    ORDER BY purchase_date
                )
            ) AS d
        FROM Purchases
    )
SELECT DISTINCT user_id
FROM t
WHERE d <= 7
ORDER BY user_id;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2229. 检查数组是否连贯 🔒](https://leetcode.cn/problems/check-if-an-array-is-consecutive){#2229}

{{< tabs "2229" >}}

{{% tab "python" %}}
```python
class Solution:
    def isConsecutive(self, nums: List[int]) -> bool:
        mi, mx = min(nums), max(nums)
        return len(set(nums)) == mx - mi + 1 == len(nums)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean isConsecutive(int[] nums) {
        int mi = nums[0], mx = 0;
        Set<Integer> s = new HashSet<>();
        for (int x : nums) {
            if (!s.add(x)) {
                return false;
            }
            mi = Math.min(mi, x);
            mx = Math.max(mx, x);
        }
        return mx - mi + 1 == nums.length;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool isConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int mi = nums[0], mx = 0;
        for (int x : nums) {
            if (s.contains(x)) {
                return false;
            }
            s.insert(x);
            mi = min(mi, x);
            mx = max(mx, x);
        }
        return mx - mi + 1 == nums.size();
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func isConsecutive(nums []int) bool {
	s := map[int]bool{}
	mi, mx := nums[0], 0
	for _, x := range nums {
		if s[x] {
			return false
		}
		s[x] = true
		mi = min(mi, x)
		mx = max(mx, x)
	}
	return mx-mi+1 == len(nums)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function isConsecutive(nums: number[]): boolean {
    let [mi, mx] = [nums[0], 0];
    const s = new Set<number>();
    for (const x of nums) {
        if (s.has(x)) {
            return false;
        }
        s.add(x);
        mi = Math.min(mi, x);
        mx = Math.max(mx, x);
    }
    return mx - mi + 1 === nums.length;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} nums
 * @return {boolean}
 */
var isConsecutive = function (nums) {
    let [mi, mx] = [nums[0], 0];
    const s = new Set();
    for (const x of nums) {
        if (s.has(x)) {
            return false;
        }
        s.add(x);
        mi = Math.min(mi, x);
        mx = Math.max(mx, x);
    }
    return mx - mi + 1 === nums.length;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>nums</code> ，如果 <code>nums</code> 是一个 <strong>连贯数组</strong> ，则返回 <code>true</code> ，否则返回 <code>false</code> 。</p>

<p><span style="">如果数组包含 </span><code>[x, x + n - 1]</code><span style=""> 范围内的所有数字（包括 <code>x</code> 和 <code>x + n - 1</code> ），则该数组为连贯数组；其中</span> <code>x</code><span style=""> 是数组中最小的数，</span><code>n</code> <span style="">是数组的长度。</span></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,3,4,2]
<strong>输出：</strong>true
<strong>解释：</strong>
最小值是 1 ，数组长度为 4 。
范围 [x, x + n - 1] 中的所有值都出现在 nums 中：[1, 1 + 4 - 1] = [1, 4] = (1, 2, 3, 4) 。
因此，nums 是一个连贯数组。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,3]
<strong>输出：</strong>false
<strong>解释：
</strong>最小值是 1 ，数组长度为 2 。 
范围 [x, x + n - 1] 中的所有值没有都出现在 nums 中：[1, 1 + 2 - 1] = [1, 2] = (1, 2) 。 
因此，nums 不是一个连贯数组。 
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [3,5,4]
<strong>输出：</strong>true
<strong>解释：</strong>
最小值是 3 ，数组长度为 3 。
范围 [x, x + n - 1] 中的所有值都出现在 nums 中：[3, 3 + 3 - 1] = [3, 5] = (3，4，5) 。
因此，nums 是一个连贯数组。
</pre>

<p>&nbsp;</p>
<strong>提示：</strong>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

我们可以用一个哈希表 $\textit{s}$ 来存储数组 $\textit{nums}$ 中的所有元素，用两个变量 $\textit{mi}$ 和 $\textit{mx}$ 分别表示数组中的最小值和最大值。

如果数组中的所有元素都不相同，且数组的长度等于最大值和最小值之间的差值加 $1$，那么数组就是连贯数组，返回 $\textit{true}$；否则返回 $\textit{false}$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 $\textit{nums}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def isConsecutive(self, nums: List[int]) -> bool:
        mi, mx = min(nums), max(nums)
        return len(set(nums)) == mx - mi + 1 == len(nums)
```

#### Java

```java
class Solution {
    public boolean isConsecutive(int[] nums) {
        int mi = nums[0], mx = 0;
        Set<Integer> s = new HashSet<>();
        for (int x : nums) {
            if (!s.add(x)) {
                return false;
            }
            mi = Math.min(mi, x);
            mx = Math.max(mx, x);
        }
        return mx - mi + 1 == nums.length;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool isConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int mi = nums[0], mx = 0;
        for (int x : nums) {
            if (s.contains(x)) {
                return false;
            }
            s.insert(x);
            mi = min(mi, x);
            mx = max(mx, x);
        }
        return mx - mi + 1 == nums.size();
    }
};
```

#### Go

```go
func isConsecutive(nums []int) bool {
	s := map[int]bool{}
	mi, mx := nums[0], 0
	for _, x := range nums {
		if s[x] {
			return false
		}
		s[x] = true
		mi = min(mi, x)
		mx = max(mx, x)
	}
	return mx-mi+1 == len(nums)
}
```

#### TypeScript

```ts
function isConsecutive(nums: number[]): boolean {
    let [mi, mx] = [nums[0], 0];
    const s = new Set<number>();
    for (const x of nums) {
        if (s.has(x)) {
            return false;
        }
        s.add(x);
        mi = Math.min(mi, x);
        mx = Math.max(mx, x);
    }
    return mx - mi + 1 === nums.length;
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @return {boolean}
 */
var isConsecutive = function (nums) {
    let [mi, mx] = [nums[0], 0];
    const s = new Set();
    for (const x of nums) {
        if (s.has(x)) {
            return false;
        }
        s.add(x);
        mi = Math.min(mi, x);
        mx = Math.max(mx, x);
    }
    return mx - mi + 1 === nums.length;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
