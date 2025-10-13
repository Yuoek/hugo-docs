---
title: "2520_统计能整除数字的位数"
date: 2025-10-08T18:39:23+08:00
weight: 3
tags: [二分查找, 位运算, 前缀和, 动态规划, 哈希表, 字符串, 数学, 数据流, 数组, 数论, 栈, 滑动窗口, 计数, 设计, 贪心, 队列]
---

{{< markmap >}}
### [2520_统计能整除数字的位数](#2520)
#### [数学](#2520)
### [2521_数组乘积中的不同质因数数目](#2521)
#### [数组](#2521)
#### [哈希表](#2521)
#### [数学](#2521)
#### [数论](#2521)
### [2522_将字符串分割成值不超过 K 的子字符串](#2522)
#### [贪心](#2522)
#### [字符串](#2522)
#### [动态规划](#2522)
### [2523_范围内最接近的两个质数](#2523)
#### [数学](#2523)
#### [数论](#2523)
### [2524_子数组的最大频率分数 🔒](#2524)
#### [栈](#2524)
#### [数组](#2524)
#### [哈希表](#2524)
#### [数学](#2524)
#### [滑动窗口](#2524)
### [2525_根据规则将箱子分类](#2525)
#### [数学](#2525)
### [2526_找到数据流中的连续整数](#2526)
#### [设计](#2526)
#### [队列](#2526)
#### [哈希表](#2526)
#### [计数](#2526)
#### [数据流](#2526)
### [2527_查询数组异或美丽值](#2527)
#### [位运算](#2527)
#### [数组](#2527)
#### [数学](#2527)
### [2528_最大化城市的最小电量](#2528)
#### [贪心](#2528)
#### [队列](#2528)
#### [数组](#2528)
#### [二分查找](#2528)
#### [前缀和](#2528)
#### [滑动窗口](#2528)
### [2529_正整数和负整数的最大计数](#2529)
#### [数组](#2529)
#### [二分查找](#2529)
#### [计数](#2529)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2520_统计能整除数字的位数
___
#### 数学
---
### 2521_数组乘积中的不同质因数数目
___
#### 数组
___
#### 哈希表
___
#### 数学
___
#### 数论
---
### 2522_将字符串分割成值不超过 K 的子字符串
___
#### 贪心
___
#### 字符串
___
#### 动态规划
---
### 2523_范围内最接近的两个质数
___
#### 数学
___
#### 数论
---
### 2524_子数组的最大频率分数 🔒
___
#### 栈
___
#### 数组
___
#### 哈希表
___
#### 数学
___
#### 滑动窗口
---
### 2525_根据规则将箱子分类
___
#### 数学
---
### 2526_找到数据流中的连续整数
___
#### 设计
___
#### 队列
___
#### 哈希表
___
#### 计数
___
#### 数据流
---
### 2527_查询数组异或美丽值
___
#### 位运算
___
#### 数组
___
#### 数学
---
### 2528_最大化城市的最小电量
___
#### 贪心
___
#### 队列
___
#### 数组
___
#### 二分查找
___
#### 前缀和
___
#### 滑动窗口
---
### 2529_正整数和负整数的最大计数
___
#### 数组
___
#### 二分查找
___
#### 计数
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 位运算 | 前缀和 |
| 动态规划 | 哈希表 | 字符串 |
| 数学 | 数据流 | 数组 |
| 数论 | 栈 | 滑动窗口 |
| 计数 | 设计 | 贪心 |
| 队列 |  |  |

# [2520. 统计能整除数字的位数](https://leetcode.cn/problems/count-the-digits-that-divide-a-number){#2520}

{{< tabs "2520" >}}

{{% tab "python" %}}
```python
class Solution:
    def countDigits(self, num: int) -> int:
        ans, x = 0, num
        while x:
            x, val = divmod(x, 10)
            ans += num % val == 0
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countDigits(int num) {
        int ans = 0;
        for (int x = num; x > 0; x /= 10) {
            if (num % (x % 10) == 0) {
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
    int countDigits(int num) {
        int ans = 0;
        for (int x = num; x > 0; x /= 10) {
            if (num % (x % 10) == 0) {
                ++ans;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countDigits(num int) (ans int) {
	for x := num; x > 0; x /= 10 {
		if num%(x%10) == 0 {
			ans++
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countDigits(num: number): number {
    let ans = 0;
    for (const s of num.toString()) {
        if (num % Number(s) === 0) {
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
    pub fn count_digits(num: i32) -> i32 {
        num.to_string()
            .chars()
            .filter(|&c| c != '0')
            .filter(|&c| num % (c.to_digit(10).unwrap() as i32) == 0)
            .count() as i32
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
int countDigits(int num) {
    int ans = 0;
    int cur = num;
    while (cur) {
        if (num % (cur % 10) == 0) {
            ans++;
        }
        cur /= 10;
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

<p>给你一个整数 <code>num</code> ，返回 <code>num</code> 中能整除 <code>num</code> 的数位的数目。</p>

<p>如果满足&nbsp;<code>nums % val == 0</code> ，则认为整数 <code>val</code> 可以整除 <code>nums</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>num = 7
<strong>输出：</strong>1
<strong>解释：</strong>7 被自己整除，因此答案是 1 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>num = 121
<strong>输出：</strong>2
<strong>解释：</strong>121 可以被 1 整除，但无法被 2 整除。由于 1 出现两次，所以返回 2 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>num = 1248
<strong>输出：</strong>4
<strong>解释：</strong>1248 可以被它每一位上的数字整除，因此答案是 4 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= num &lt;= 10<sup>9</sup></code></li>
	<li><code>num</code> 的数位中不含 <code>0</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举

我们直接枚举整数 $num$ 的每一位上的数 $val$，若 $val$ 能够整除 $num$，那么答案加一。

枚举结束后，返回答案即可。

时间复杂度 $O(\log num)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countDigits(self, num: int) -> int:
        ans, x = 0, num
        while x:
            x, val = divmod(x, 10)
            ans += num % val == 0
        return ans
```

#### Java

```java
class Solution {
    public int countDigits(int num) {
        int ans = 0;
        for (int x = num; x > 0; x /= 10) {
            if (num % (x % 10) == 0) {
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
    int countDigits(int num) {
        int ans = 0;
        for (int x = num; x > 0; x /= 10) {
            if (num % (x % 10) == 0) {
                ++ans;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func countDigits(num int) (ans int) {
	for x := num; x > 0; x /= 10 {
		if num%(x%10) == 0 {
			ans++
		}
	}
	return
}
```

#### TypeScript

```ts
function countDigits(num: number): number {
    let ans = 0;
    for (let x = num; x; x = (x / 10) | 0) {
        if (num % (x % 10) === 0) {
            ++ans;
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn count_digits(num: i32) -> i32 {
        let mut ans = 0;
        let mut cur = num;
        while cur != 0 {
            if num % (cur % 10) == 0 {
                ans += 1;
            }
            cur /= 10;
        }
        ans
    }
}
```

#### C

```c
int countDigits(int num) {
    int ans = 0;
    int cur = num;
    while (cur) {
        if (num % (cur % 10) == 0) {
            ans++;
        }
        cur /= 10;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### TypeScript

```ts
function countDigits(num: number): number {
    let ans = 0;
    for (const s of num.toString()) {
        if (num % Number(s) === 0) {
            ans++;
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn count_digits(num: i32) -> i32 {
        num.to_string()
            .chars()
            .filter(|&c| c != '0')
            .filter(|&c| num % (c.to_digit(10).unwrap() as i32) == 0)
            .count() as i32
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2521. 数组乘积中的不同质因数数目](https://leetcode.cn/problems/distinct-prime-factors-of-product-of-array){#2521}

{{< tabs "2521" >}}

{{% tab "python" %}}
```python
class Solution:
    def distinctPrimeFactors(self, nums: List[int]) -> int:
        s = set()
        for n in nums:
            i = 2
            while i <= n // i:
                if n % i == 0:
                    s.add(i)
                    while n % i == 0:
                        n //= i
                i += 1
            if n > 1:
                s.add(n)
        return len(s)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int distinctPrimeFactors(int[] nums) {
        Set<Integer> s = new HashSet<>();
        for (int n : nums) {
            for (int i = 2; i <= n / i; ++i) {
                if (n % i == 0) {
                    s.add(i);
                    while (n % i == 0) {
                        n /= i;
                    }
                }
            }
            if (n > 1) {
                s.add(n);
            }
        }
        return s.size();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        unordered_set<int> s;
        for (int& n : nums) {
            for (int i = 2; i <= n / i; ++i) {
                if (n % i == 0) {
                    s.insert(i);
                    while (n % i == 0) {
                        n /= i;
                    }
                }
            }
            if (n > 1) {
                s.insert(n);
            }
        }
        return s.size();
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func distinctPrimeFactors(nums []int) int {
	s := map[int]bool{}
	for _, n := range nums {
		for i := 2; i <= n/i; i++ {
			if n%i == 0 {
				s[i] = true
				for n%i == 0 {
					n /= i
				}
			}
		}
		if n > 1 {
			s[n] = true
		}
	}
	return len(s)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function distinctPrimeFactors(nums: number[]): number {
    const s: Set<number> = new Set();
    for (let n of nums) {
        let i = 2;
        while (i <= n / i) {
            if (n % i === 0) {
                s.add(i);
                while (n % i === 0) {
                    n = Math.floor(n / i);
                }
            }
            ++i;
        }
        if (n > 1) {
            s.add(n);
        }
    }
    return s.size;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个正整数数组 <code>nums</code> ，对 <code>nums</code> 所有元素求积之后，找出并返回乘积中 <strong>不同质因数</strong> 的数目。</p>

<p><strong>注意：</strong></p>

<ul>
	<li><strong>质数</strong> 是指大于 <code>1</code> 且仅能被 <code>1</code> 及自身整除的数字。</li>
	<li>如果 <code>val2 / val1</code> 是一个整数，则整数 <code>val1</code> 是另一个整数 <code>val2</code> 的一个因数。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [2,4,3,7,10,6]
<strong>输出：</strong>4
<strong>解释：</strong>
nums 中所有元素的乘积是：2 * 4 * 3 * 7 * 10 * 6 = 10080 = 2<sup>5</sup> * 3<sup>2</sup> * 5 * 7 。
共有 4 个不同的质因数，所以返回 4 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [2,4,8,16]
<strong>输出：</strong>1
<strong>解释：</strong>
nums 中所有元素的乘积是：2 * 4 * 8 * 16 = 1024 = 2<sup>10</sup> 。
共有 1 个不同的质因数，所以返回 1 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
	<li><code>2 &lt;= nums[i] &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 质因数分解

对于数组中的每个元素，先对其进行质因数分解，然后将分解出的质因数加入哈希表中。最后返回哈希表的大小即可。

时间复杂度 $O(n \times \sqrt{m})$，空间复杂度 $O(\frac{m}{\log m})$，其中 $n$ 和 $m$ 分别为数组的长度和数组中元素的最大值。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def distinctPrimeFactors(self, nums: List[int]) -> int:
        s = set()
        for n in nums:
            i = 2
            while i <= n // i:
                if n % i == 0:
                    s.add(i)
                    while n % i == 0:
                        n //= i
                i += 1
            if n > 1:
                s.add(n)
        return len(s)
```

#### Java

```java
class Solution {
    public int distinctPrimeFactors(int[] nums) {
        Set<Integer> s = new HashSet<>();
        for (int n : nums) {
            for (int i = 2; i <= n / i; ++i) {
                if (n % i == 0) {
                    s.add(i);
                    while (n % i == 0) {
                        n /= i;
                    }
                }
            }
            if (n > 1) {
                s.add(n);
            }
        }
        return s.size();
    }
}
```

#### C++

```cpp
class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        unordered_set<int> s;
        for (int& n : nums) {
            for (int i = 2; i <= n / i; ++i) {
                if (n % i == 0) {
                    s.insert(i);
                    while (n % i == 0) {
                        n /= i;
                    }
                }
            }
            if (n > 1) {
                s.insert(n);
            }
        }
        return s.size();
    }
};
```

#### Go

```go
func distinctPrimeFactors(nums []int) int {
	s := map[int]bool{}
	for _, n := range nums {
		for i := 2; i <= n/i; i++ {
			if n%i == 0 {
				s[i] = true
				for n%i == 0 {
					n /= i
				}
			}
		}
		if n > 1 {
			s[n] = true
		}
	}
	return len(s)
}
```

#### TypeScript

```ts
function distinctPrimeFactors(nums: number[]): number {
    const s: Set<number> = new Set();
    for (let n of nums) {
        let i = 2;
        while (i <= n / i) {
            if (n % i === 0) {
                s.add(i);
                while (n % i === 0) {
                    n = Math.floor(n / i);
                }
            }
            ++i;
        }
        if (n > 1) {
            s.add(n);
        }
    }
    return s.size;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2522. 将字符串分割成值不超过 K 的子字符串](https://leetcode.cn/problems/partition-string-into-substrings-with-values-at-most-k){#2522}

{{< tabs "2522" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumPartition(self, s: str, k: int) -> int:
        @cache
        def dfs(i):
            if i >= n:
                return 0
            res, v = inf, 0
            for j in range(i, n):
                v = v * 10 + int(s[j])
                if v > k:
                    break
                res = min(res, dfs(j + 1))
            return res + 1

        n = len(s)
        ans = dfs(0)
        return ans if ans < inf else -1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private Integer[] f;
    private int n;
    private String s;
    private int k;
    private int inf = 1 << 30;

    public int minimumPartition(String s, int k) {
        n = s.length();
        f = new Integer[n];
        this.s = s;
        this.k = k;
        int ans = dfs(0);
        return ans < inf ? ans : -1;
    }

    private int dfs(int i) {
        if (i >= n) {
            return 0;
        }
        if (f[i] != null) {
            return f[i];
        }
        int res = inf;
        long v = 0;
        for (int j = i; j < n; ++j) {
            v = v * 10 + (s.charAt(j) - '0');
            if (v > k) {
                break;
            }
            res = Math.min(res, dfs(j + 1));
        }
        return f[i] = res + 1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minimumPartition(string s, int k) {
        int n = s.size();
        int f[n];
        memset(f, 0, sizeof f);
        const int inf = 1 << 30;
        function<int(int)> dfs = [&](int i) -> int {
            if (i >= n) return 0;
            if (f[i]) return f[i];
            int res = inf;
            long v = 0;
            for (int j = i; j < n; ++j) {
                v = v * 10 + (s[j] - '0');
                if (v > k) break;
                res = min(res, dfs(j + 1));
            }
            return f[i] = res + 1;
        };
        int ans = dfs(0);
        return ans < inf ? ans : -1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumPartition(s string, k int) int {
	n := len(s)
	f := make([]int, n)
	const inf int = 1 << 30
	var dfs func(int) int
	dfs = func(i int) int {
		if i >= n {
			return 0
		}
		if f[i] > 0 {
			return f[i]
		}
		res, v := inf, 0
		for j := i; j < n; j++ {
			v = v*10 + int(s[j]-'0')
			if v > k {
				break
			}
			res = min(res, dfs(j+1))
		}
		f[i] = res + 1
		return f[i]
	}
	ans := dfs(0)
	if ans < inf {
		return ans
	}
	return -1
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串&nbsp;<code>s</code>&nbsp;，它每一位都是&nbsp;<code>1</code>&nbsp;到&nbsp;<code>9</code>&nbsp;之间的数字组成，同时给你一个整数&nbsp;<code>k</code>&nbsp;。</p>

<p>如果一个字符串 <code>s</code>&nbsp;的分割满足以下条件，我们称它是一个 <strong>好</strong>&nbsp;分割：</p>

<ul>
	<li><code>s</code>&nbsp;中每个数位 <strong>恰好</strong>&nbsp;属于一个子字符串。</li>
	<li>每个子字符串的值都小于等于&nbsp;<code>k</code>&nbsp;。</li>
</ul>

<p>请你返回 <code>s</code>&nbsp;所有的 <strong>好</strong>&nbsp;分割中，子字符串的&nbsp;<strong>最少</strong>&nbsp;数目。如果不存在 <code>s</code>&nbsp;的<strong>&nbsp;好</strong>&nbsp;分割，返回&nbsp;<code>-1</code>&nbsp;。</p>

<p><b>注意：</b></p>

<ul>
	<li>一个字符串的 <strong>值</strong>&nbsp;是这个字符串对应的整数。比方说，<code>"123"</code>&nbsp;的值为&nbsp;<code>123</code>&nbsp;，<code>"1"</code>&nbsp;的值是&nbsp;<code>1</code>&nbsp;。</li>
	<li><strong>子字符串</strong>&nbsp;是字符串中一段连续的字符序列。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>s = "165462", k = 60
<b>输出：</b>4
<b>解释：</b>我们将字符串分割成子字符串 "16" ，"54" ，"6" 和 "2" 。每个子字符串的值都小于等于 k = 60 。
不存在小于 4 个子字符串的好分割。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>s = "238182", k = 5
<b>输出：</b>-1
<strong>解释：</strong>这个字符串不存在好分割。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s[i]</code>&nbsp;是&nbsp;<code>'1'</code>&nbsp;到&nbsp;<code>'9'</code>&nbsp;之间的数字。</li>
	<li><code>1 &lt;= k &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

我们设计一个函数 $dfs(i)$ 表示从字符串 $s$ 的下标 $i$ 开始的最少分割数，那么答案就是 $dfs(0)$。

函数 $dfs(i)$ 的计算过程如下：

-   如果 $i \geq n$，说明已经到达字符串末尾，返回 $0$。
-   否则，我们枚举 $i$ 开始的所有子字符串，如果子字符串的值小于等于 $k$，那么我们可以将子字符串作为一个分割，那么我们可以得到 $dfs(j + 1)$，其中 $j$ 是子字符串的末尾下标，然后我们取所有可能的分割中的最小值，再加上 $1$，即为 $dfs(i)$ 的值。

最后，如果 $dfs(0) = \infty$，说明不存在好分割，返回 $-1$，否则返回 $dfs(0)$。

为了避免重复计算，我们可以使用记忆化搜索。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是字符串 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumPartition(self, s: str, k: int) -> int:
        @cache
        def dfs(i):
            if i >= n:
                return 0
            res, v = inf, 0
            for j in range(i, n):
                v = v * 10 + int(s[j])
                if v > k:
                    break
                res = min(res, dfs(j + 1))
            return res + 1

        n = len(s)
        ans = dfs(0)
        return ans if ans < inf else -1
```

#### Java

```java
class Solution {
    private Integer[] f;
    private int n;
    private String s;
    private int k;
    private int inf = 1 << 30;

    public int minimumPartition(String s, int k) {
        n = s.length();
        f = new Integer[n];
        this.s = s;
        this.k = k;
        int ans = dfs(0);
        return ans < inf ? ans : -1;
    }

    private int dfs(int i) {
        if (i >= n) {
            return 0;
        }
        if (f[i] != null) {
            return f[i];
        }
        int res = inf;
        long v = 0;
        for (int j = i; j < n; ++j) {
            v = v * 10 + (s.charAt(j) - '0');
            if (v > k) {
                break;
            }
            res = Math.min(res, dfs(j + 1));
        }
        return f[i] = res + 1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumPartition(string s, int k) {
        int n = s.size();
        int f[n];
        memset(f, 0, sizeof f);
        const int inf = 1 << 30;
        function<int(int)> dfs = [&](int i) -> int {
            if (i >= n) return 0;
            if (f[i]) return f[i];
            int res = inf;
            long v = 0;
            for (int j = i; j < n; ++j) {
                v = v * 10 + (s[j] - '0');
                if (v > k) break;
                res = min(res, dfs(j + 1));
            }
            return f[i] = res + 1;
        };
        int ans = dfs(0);
        return ans < inf ? ans : -1;
    }
};
```

#### Go

```go
func minimumPartition(s string, k int) int {
	n := len(s)
	f := make([]int, n)
	const inf int = 1 << 30
	var dfs func(int) int
	dfs = func(i int) int {
		if i >= n {
			return 0
		}
		if f[i] > 0 {
			return f[i]
		}
		res, v := inf, 0
		for j := i; j < n; j++ {
			v = v*10 + int(s[j]-'0')
			if v > k {
				break
			}
			res = min(res, dfs(j+1))
		}
		f[i] = res + 1
		return f[i]
	}
	ans := dfs(0)
	if ans < inf {
		return ans
	}
	return -1
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2523. 范围内最接近的两个质数](https://leetcode.cn/problems/closest-prime-numbers-in-range){#2523}

{{< tabs "2523" >}}

{{% tab "python" %}}
```python
class Solution:
    def closestPrimes(self, left: int, right: int) -> List[int]:
        cnt = 0
        st = [False] * (right + 1)
        prime = [0] * (right + 1)
        for i in range(2, right + 1):
            if not st[i]:
                prime[cnt] = i
                cnt += 1
            j = 0
            while prime[j] <= right // i:
                st[prime[j] * i] = 1
                if i % prime[j] == 0:
                    break
                j += 1
        p = [v for v in prime[:cnt] if left <= v <= right]
        mi = inf
        ans = [-1, -1]
        for a, b in pairwise(p):
            if (d := b - a) < mi:
                mi = d
                ans = [a, b]
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] closestPrimes(int left, int right) {
        int cnt = 0;
        boolean[] st = new boolean[right + 1];
        int[] prime = new int[right + 1];
        for (int i = 2; i <= right; ++i) {
            if (!st[i]) {
                prime[cnt++] = i;
            }
            for (int j = 0; prime[j] <= right / i; ++j) {
                st[prime[j] * i] = true;
                if (i % prime[j] == 0) {
                    break;
                }
            }
        }
        int i = -1, j = -1;
        for (int k = 0; k < cnt; ++k) {
            if (prime[k] >= left && prime[k] <= right) {
                if (i == -1) {
                    i = k;
                }
                j = k;
            }
        }
        int[] ans = new int[] {-1, -1};
        if (i == j || i == -1) {
            return ans;
        }
        int mi = 1 << 30;
        for (int k = i; k < j; ++k) {
            int d = prime[k + 1] - prime[k];
            if (d < mi) {
                mi = d;
                ans[0] = prime[k];
                ans[1] = prime[k + 1];
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
    vector<int> closestPrimes(int left, int right) {
        int cnt = 0;
        bool st[right + 1];
        memset(st, 0, sizeof st);
        int prime[right + 1];
        for (int i = 2; i <= right; ++i) {
            if (!st[i]) {
                prime[cnt++] = i;
            }
            for (int j = 0; prime[j] <= right / i; ++j) {
                st[prime[j] * i] = true;
                if (i % prime[j] == 0) {
                    break;
                }
            }
        }
        int i = -1, j = -1;
        for (int k = 0; k < cnt; ++k) {
            if (prime[k] >= left && prime[k] <= right) {
                if (i == -1) {
                    i = k;
                }
                j = k;
            }
        }
        vector<int> ans = {-1, -1};
        if (i == j || i == -1) return ans;
        int mi = 1 << 30;
        for (int k = i; k < j; ++k) {
            int d = prime[k + 1] - prime[k];
            if (d < mi) {
                mi = d;
                ans[0] = prime[k];
                ans[1] = prime[k + 1];
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func closestPrimes(left int, right int) []int {
	cnt := 0
	st := make([]bool, right+1)
	prime := make([]int, right+1)
	for i := 2; i <= right; i++ {
		if !st[i] {
			prime[cnt] = i
			cnt++
		}
		for j := 0; prime[j] <= right/i; j++ {
			st[prime[j]*i] = true
			if i%prime[j] == 0 {
				break
			}
		}
	}
	i, j := -1, -1
	for k := 0; k < cnt; k++ {
		if prime[k] >= left && prime[k] <= right {
			if i == -1 {
				i = k
			}
			j = k
		}
	}
	ans := []int{-1, -1}
	if i == j || i == -1 {
		return ans
	}
	mi := 1 << 30
	for k := i; k < j; k++ {
		d := prime[k+1] - prime[k]
		if d < mi {
			mi = d
			ans[0], ans[1] = prime[k], prime[k+1]
		}
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

<p>给你两个正整数&nbsp;<code>left</code> 和&nbsp;<code>right</code>&nbsp;，请你找到两个整数&nbsp;<code>num1</code> 和&nbsp;<code>num2</code>&nbsp;，它们满足：</p>

<ul>
	<li><code>left &lt;= nums1 &lt; nums2 &lt;= right&nbsp;</code>&nbsp;。</li>
	<li><code>nums1</code> 和&nbsp;<code>nums2</code>&nbsp;都是 <strong><span data-keyword="prime-number">质数</span></strong>&nbsp;。</li>
	<li><code>nums2 - nums1</code>&nbsp;是满足上述条件的质数对中的 <strong>最小值</strong>&nbsp;。</li>
</ul>

<p>请你返回正整数数组&nbsp;<code>ans = [nums1, nums2]</code>&nbsp;。如果有多个整数对满足上述条件，请你返回&nbsp;<code>nums1</code>&nbsp;最小的质数对。如果不存在符合题意的质数对，请你返回&nbsp;<code>[-1, -1]</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>left = 10, right = 19
<b>输出：</b>[11,13]
<b>解释：</b>10 到 19 之间的质数为 11 ，13 ，17 和 19 。
质数对的最小差值是 2 ，[11,13] 和 [17,19] 都可以得到最小差值。
由于 11 比 17 小，我们返回第一个质数对。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>left = 4, right = 6
<b>输出：</b>[-1,-1]
<b>解释：</b>给定范围内只有一个质数，所以题目条件无法被满足。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= left &lt;= right &lt;= 10<sup>6</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：线性筛

对于给定的范围 $[\textit{left}, \textit{right}]$，我们可以使用线性筛求出所有质数，然后从小到大遍历质数，找到相邻的两个质数，其差值最小的质数对即为答案。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n = \textit{right}$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def closestPrimes(self, left: int, right: int) -> List[int]:
        cnt = 0
        st = [False] * (right + 1)
        prime = [0] * (right + 1)
        for i in range(2, right + 1):
            if not st[i]:
                prime[cnt] = i
                cnt += 1
            j = 0
            while prime[j] <= right // i:
                st[prime[j] * i] = 1
                if i % prime[j] == 0:
                    break
                j += 1
        p = [v for v in prime[:cnt] if left <= v <= right]
        mi = inf
        ans = [-1, -1]
        for a, b in pairwise(p):
            if (d := b - a) < mi:
                mi = d
                ans = [a, b]
        return ans
```

#### Java

```java
class Solution {
    public int[] closestPrimes(int left, int right) {
        int cnt = 0;
        boolean[] st = new boolean[right + 1];
        int[] prime = new int[right + 1];
        for (int i = 2; i <= right; ++i) {
            if (!st[i]) {
                prime[cnt++] = i;
            }
            for (int j = 0; prime[j] <= right / i; ++j) {
                st[prime[j] * i] = true;
                if (i % prime[j] == 0) {
                    break;
                }
            }
        }
        int i = -1, j = -1;
        for (int k = 0; k < cnt; ++k) {
            if (prime[k] >= left && prime[k] <= right) {
                if (i == -1) {
                    i = k;
                }
                j = k;
            }
        }
        int[] ans = new int[] {-1, -1};
        if (i == j || i == -1) {
            return ans;
        }
        int mi = 1 << 30;
        for (int k = i; k < j; ++k) {
            int d = prime[k + 1] - prime[k];
            if (d < mi) {
                mi = d;
                ans[0] = prime[k];
                ans[1] = prime[k + 1];
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
    vector<int> closestPrimes(int left, int right) {
        int cnt = 0;
        bool st[right + 1];
        memset(st, 0, sizeof st);
        int prime[right + 1];
        for (int i = 2; i <= right; ++i) {
            if (!st[i]) {
                prime[cnt++] = i;
            }
            for (int j = 0; prime[j] <= right / i; ++j) {
                st[prime[j] * i] = true;
                if (i % prime[j] == 0) {
                    break;
                }
            }
        }
        int i = -1, j = -1;
        for (int k = 0; k < cnt; ++k) {
            if (prime[k] >= left && prime[k] <= right) {
                if (i == -1) {
                    i = k;
                }
                j = k;
            }
        }
        vector<int> ans = {-1, -1};
        if (i == j || i == -1) return ans;
        int mi = 1 << 30;
        for (int k = i; k < j; ++k) {
            int d = prime[k + 1] - prime[k];
            if (d < mi) {
                mi = d;
                ans[0] = prime[k];
                ans[1] = prime[k + 1];
            }
        }
        return ans;
    }
};
```

#### Go

```go
func closestPrimes(left int, right int) []int {
	cnt := 0
	st := make([]bool, right+1)
	prime := make([]int, right+1)
	for i := 2; i <= right; i++ {
		if !st[i] {
			prime[cnt] = i
			cnt++
		}
		for j := 0; prime[j] <= right/i; j++ {
			st[prime[j]*i] = true
			if i%prime[j] == 0 {
				break
			}
		}
	}
	i, j := -1, -1
	for k := 0; k < cnt; k++ {
		if prime[k] >= left && prime[k] <= right {
			if i == -1 {
				i = k
			}
			j = k
		}
	}
	ans := []int{-1, -1}
	if i == j || i == -1 {
		return ans
	}
	mi := 1 << 30
	for k := i; k < j; k++ {
		d := prime[k+1] - prime[k]
		if d < mi {
			mi = d
			ans[0], ans[1] = prime[k], prime[k+1]
		}
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2524. 子数组的最大频率分数 🔒](https://leetcode.cn/problems/maximum-frequency-score-of-a-subarray){#2524}

{{< tabs "2524" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxFrequencyScore(self, nums: List[int], k: int) -> int:
        mod = 10**9 + 7
        cnt = Counter(nums[:k])
        ans = cur = sum(pow(k, v, mod) for k, v in cnt.items()) % mod
        i = k
        while i < len(nums):
            a, b = nums[i - k], nums[i]
            if a != b:
                cur += (b - 1) * pow(b, cnt[b], mod) if cnt[b] else b
                cur -= (a - 1) * pow(a, cnt[a] - 1, mod) if cnt[a] > 1 else a
                cur %= mod
                cnt[b] += 1
                cnt[a] -= 1
                ans = max(ans, cur)
            i += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private final int mod = (int) 1e9 + 7;

    public int maxFrequencyScore(int[] nums, int k) {
        Map<Integer, Integer> cnt = new HashMap<>();
        for (int i = 0; i < k; ++i) {
            cnt.merge(nums[i], 1, Integer::sum);
        }
        long cur = 0;
        for (var e : cnt.entrySet()) {
            cur = (cur + qpow(e.getKey(), e.getValue())) % mod;
        }
        long ans = cur;
        for (int i = k; i < nums.length; ++i) {
            int a = nums[i - k];
            int b = nums[i];
            if (a != b) {
                if (cnt.getOrDefault(b, 0) > 0) {
                    cur += (b - 1) * qpow(b, cnt.get(b)) % mod;
                } else {
                    cur += b;
                }
                if (cnt.getOrDefault(a, 0) > 1) {
                    cur -= (a - 1) * qpow(a, cnt.get(a) - 1) % mod;
                } else {
                    cur -= a;
                }
                cur = (cur + mod) % mod;
                cnt.put(b, cnt.getOrDefault(b, 0) + 1);
                cnt.put(a, cnt.getOrDefault(a, 0) - 1);
                ans = Math.max(ans, cur);
            }
        }
        return (int) ans;
    }

    private long qpow(long a, long n) {
        long ans = 1;
        for (; n > 0; n >>= 1) {
            if ((n & 1) == 1) {
                ans = ans * a % mod;
            }
            a = a * a % mod;
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
    int maxFrequencyScore(vector<int>& nums, int k) {
        using ll = long long;
        const int mod = 1e9 + 7;
        auto qpow = [&](ll a, ll n) {
            ll ans = 1;
            for (; n; n >>= 1) {
                if (n & 1) {
                    ans = ans * a % mod;
                }
                a = a * a % mod;
            }
            return ans;
        };
        unordered_map<int, int> cnt;
        for (int i = 0; i < k; ++i) {
            cnt[nums[i]]++;
        }
        ll cur = 0;
        for (auto& [k, v] : cnt) {
            cur = (cur + qpow(k, v)) % mod;
        }
        ll ans = cur;
        for (int i = k; i < nums.size(); ++i) {
            int a = nums[i - k], b = nums[i];
            if (a != b) {
                cur += cnt[b] ? (b - 1) * qpow(b, cnt[b]) % mod : b;
                cur -= cnt[a] > 1 ? (a - 1) * qpow(a, cnt[a] - 1) % mod : a;
                cur = (cur + mod) % mod;
                ans = max(ans, cur);
                cnt[b]++;
                cnt[a]--;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxFrequencyScore(nums []int, k int) int {
	cnt := map[int]int{}
	for _, v := range nums[:k] {
		cnt[v]++
	}
	cur := 0
	const mod int = 1e9 + 7
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
	for k, v := range cnt {
		cur = (cur + qpow(k, v)) % mod
	}
	ans := cur
	for i := k; i < len(nums); i++ {
		a, b := nums[i-k], nums[i]
		if a != b {
			if cnt[b] > 0 {
				cur += (b - 1) * qpow(b, cnt[b]) % mod
			} else {
				cur += b
			}
			if cnt[a] > 1 {
				cur -= (a - 1) * qpow(a, cnt[a]-1) % mod
			} else {
				cur -= a
			}
			cur = (cur + mod) % mod
			ans = max(ans, cur)
			cnt[b]++
			cnt[a]--
		}
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

<p>给定一个整数数组 <code>nums</code> 和一个 <strong>正</strong> 整数 <code>k</code> 。</p>

<p>数组的 <strong>频率得分</strong> 是数组中 <strong>不同</strong> 值的 <strong>幂次</strong> 之和，并将和对&nbsp;<code>10<sup>9</sup>&nbsp;+ 7</code> <strong>取模</strong>。</p>

<p>例如，数组 <code>[5,4,5,7,4,4]</code> 的频率得分为 <code>(4<sup>3</sup>&nbsp;+ 5<sup>2</sup>&nbsp;+ 7<sup>1</sup>) modulo (10<sup>9</sup>&nbsp;+ 7) = 96</code> 。</p>

<p>返回 <code>nums</code> 中长度为 <code>k</code> 的 <strong>子数组</strong> 的 <strong>最大&nbsp;</strong>频率得分。你需要返回取模后的最大值，而不是实际值。</p>

<p><strong>子数组</strong>&nbsp;是一个数组的连续部分。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1 ：</strong></p>

<pre>
<b>输入：</b>nums = [1,1,1,2,1,2], k = 3
<b>输出：</b>5
<b>解释：</b>子数组 [2,1,2] 的频率分数等于 5。可以证明这是我们可以获得的最大频率分数。
</pre>

<p><strong class="example">示例 2 ：</strong></p>

<pre>
<b>输入：</b>nums = [1,1,1,1,1,1], k = 4
<b>输出：</b>1
<b>解释：</b>所有长度为 4 的子数组的频率得分都等于 1。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 滑动窗口 + 快速幂

我们用哈希表 $\textit{cnt}$ 维护窗口大小为 $k$ 的元素及其出现的次数。

先算出初始窗口为 $k$ 的所有元素的分数。然后利用滑动窗口，每次加入一个元素，并移除最左边的元素，同时利用快速幂更新分数。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 $\textit{nums}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxFrequencyScore(self, nums: List[int], k: int) -> int:
        mod = 10**9 + 7
        cnt = Counter(nums[:k])
        ans = cur = sum(pow(k, v, mod) for k, v in cnt.items()) % mod
        i = k
        while i < len(nums):
            a, b = nums[i - k], nums[i]
            if a != b:
                cur += (b - 1) * pow(b, cnt[b], mod) if cnt[b] else b
                cur -= (a - 1) * pow(a, cnt[a] - 1, mod) if cnt[a] > 1 else a
                cur %= mod
                cnt[b] += 1
                cnt[a] -= 1
                ans = max(ans, cur)
            i += 1
        return ans
```

#### Java

```java
class Solution {
    private final int mod = (int) 1e9 + 7;

    public int maxFrequencyScore(int[] nums, int k) {
        Map<Integer, Integer> cnt = new HashMap<>();
        for (int i = 0; i < k; ++i) {
            cnt.merge(nums[i], 1, Integer::sum);
        }
        long cur = 0;
        for (var e : cnt.entrySet()) {
            cur = (cur + qpow(e.getKey(), e.getValue())) % mod;
        }
        long ans = cur;
        for (int i = k; i < nums.length; ++i) {
            int a = nums[i - k];
            int b = nums[i];
            if (a != b) {
                if (cnt.getOrDefault(b, 0) > 0) {
                    cur += (b - 1) * qpow(b, cnt.get(b)) % mod;
                } else {
                    cur += b;
                }
                if (cnt.getOrDefault(a, 0) > 1) {
                    cur -= (a - 1) * qpow(a, cnt.get(a) - 1) % mod;
                } else {
                    cur -= a;
                }
                cur = (cur + mod) % mod;
                cnt.put(b, cnt.getOrDefault(b, 0) + 1);
                cnt.put(a, cnt.getOrDefault(a, 0) - 1);
                ans = Math.max(ans, cur);
            }
        }
        return (int) ans;
    }

    private long qpow(long a, long n) {
        long ans = 1;
        for (; n > 0; n >>= 1) {
            if ((n & 1) == 1) {
                ans = ans * a % mod;
            }
            a = a * a % mod;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxFrequencyScore(vector<int>& nums, int k) {
        using ll = long long;
        const int mod = 1e9 + 7;
        auto qpow = [&](ll a, ll n) {
            ll ans = 1;
            for (; n; n >>= 1) {
                if (n & 1) {
                    ans = ans * a % mod;
                }
                a = a * a % mod;
            }
            return ans;
        };
        unordered_map<int, int> cnt;
        for (int i = 0; i < k; ++i) {
            cnt[nums[i]]++;
        }
        ll cur = 0;
        for (auto& [k, v] : cnt) {
            cur = (cur + qpow(k, v)) % mod;
        }
        ll ans = cur;
        for (int i = k; i < nums.size(); ++i) {
            int a = nums[i - k], b = nums[i];
            if (a != b) {
                cur += cnt[b] ? (b - 1) * qpow(b, cnt[b]) % mod : b;
                cur -= cnt[a] > 1 ? (a - 1) * qpow(a, cnt[a] - 1) % mod : a;
                cur = (cur + mod) % mod;
                ans = max(ans, cur);
                cnt[b]++;
                cnt[a]--;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func maxFrequencyScore(nums []int, k int) int {
	cnt := map[int]int{}
	for _, v := range nums[:k] {
		cnt[v]++
	}
	cur := 0
	const mod int = 1e9 + 7
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
	for k, v := range cnt {
		cur = (cur + qpow(k, v)) % mod
	}
	ans := cur
	for i := k; i < len(nums); i++ {
		a, b := nums[i-k], nums[i]
		if a != b {
			if cnt[b] > 0 {
				cur += (b - 1) * qpow(b, cnt[b]) % mod
			} else {
				cur += b
			}
			if cnt[a] > 1 {
				cur -= (a - 1) * qpow(a, cnt[a]-1) % mod
			} else {
				cur -= a
			}
			cur = (cur + mod) % mod
			ans = max(ans, cur)
			cnt[b]++
			cnt[a]--
		}
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2525. 根据规则将箱子分类](https://leetcode.cn/problems/categorize-box-according-to-criteria){#2525}

{{< tabs "2525" >}}

{{% tab "python" %}}
```python
class Solution:
    def categorizeBox(self, length: int, width: int, height: int, mass: int) -> str:
        v = length * width * height
        bulky = any(x >= 10000 for x in (length, width, height)) or v >= 10**9
        heavy = mass >= 100

        if bulky and heavy:
            return "Both"
        if bulky:
            return "Bulky"
        if heavy:
            return "Heavy"

        return "Neither"
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String categorizeBox(int length, int width, int height, int mass) {
        long v = (long) length * width * height;
        boolean bulky = length >= 1e4 || width >= 1e4 || height >= 1e4 || v >= 1e9;
        boolean heavy = mass >= 100;

        if (bulky && heavy) {
            return "Both";
        }
        if (bulky) {
            return "Bulky";
        }
        if (heavy) {
            return "Heavy";
        }

        return "Neither";
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        long v = (long) length * width * height;
        bool bulky = length >= 1e4 || width >= 1e4 || height >= 1e4 || v >= 1e9;
        bool heavy = mass >= 100;

        if (bulky && heavy) {
            return "Both";
        }
        if (bulky) {
            return "Bulky";
        }
        if (heavy) {
            return "Heavy";
        }

        return "Neither";
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func categorizeBox(length int, width int, height int, mass int) string {
	v := length * width * height
	bulky := length >= 1e4 || width >= 1e4 || height >= 1e4 || v >= 1e9
	heavy := mass >= 100
	if bulky && heavy {
		return "Both"
	}
	if bulky {
		return "Bulky"
	}
	if heavy {
		return "Heavy"
	}
	return "Neither"
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function categorizeBox(length: number, width: number, height: number, mass: number): string {
    const v = length * width * height;
    const bulky = length >= 1e4 || width >= 1e4 || height >= 1e4 || v >= 1e9;
    const heavy = mass >= 100;
    if (bulky && heavy) {
        return 'Both';
    }
    if (bulky) {
        return 'Bulky';
    }
    if (heavy) {
        return 'Heavy';
    }
    return 'Neither';
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn categorize_box(length: i32, width: i32, height: i32, mass: i32) -> String {
        let v = length * width * height;
        let bulky = length >= 10000
            || width >= 10000
            || height >= 10000
            || (length as i64) * (width as i64) * (height as i64) >= 1000000000;

        let heavy = mass >= 100;

        if bulky && heavy {
            return "Both".to_string();
        }
        if bulky {
            return "Bulky".to_string();
        }
        if heavy {
            return "Heavy".to_string();
        }

        "Neither".to_string()
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你四个整数&nbsp;<code>length</code>&nbsp;，<code>width</code>&nbsp;，<code>height</code>&nbsp;和&nbsp;<code>mass</code>&nbsp;，分别表示一个箱子的三个维度和质量，请你返回一个表示箱子 <strong>类别</strong> 的字符串。</p>

<ul>
	<li>如果满足以下条件，那么箱子是&nbsp;<code>"Bulky"</code>&nbsp;的：

    <ul>
    	<li>箱子 <strong>至少有一个</strong> 维度大于等于 <code>10<sup>4</sup></code>&nbsp;。</li>
    	<li>或者箱子的 <strong>体积</strong> 大于等于&nbsp;<code>10<sup>9</sup></code>&nbsp;。</li>
    </ul>
    </li>
    <li>如果箱子的质量大于等于&nbsp;<code>100</code>&nbsp;，那么箱子是&nbsp;<code>"Heavy"</code>&nbsp;的。</li>
    <li>如果箱子同时是&nbsp;<code>"Bulky"</code> 和&nbsp;<code>"Heavy"</code>&nbsp;，那么返回类别为&nbsp;<code>"Both"</code>&nbsp;。</li>
    <li>如果箱子既不是&nbsp;<code>"Bulky"</code>&nbsp;，也不是&nbsp;<code>"Heavy"</code>&nbsp;，那么返回类别为&nbsp;<code>"Neither"</code>&nbsp;。</li>
    <li>如果箱子是&nbsp;<code>"Bulky"</code>&nbsp;但不是&nbsp;<code>"Heavy"</code>&nbsp;，那么返回类别为&nbsp;<code>"Bulky"</code>&nbsp;。</li>
    <li>如果箱子是&nbsp;<code>"Heavy"</code>&nbsp;但不是&nbsp;<code>"Bulky"</code>&nbsp;，那么返回类别为&nbsp;<code>"Heavy"</code>&nbsp;。</li>

</ul>

<p><strong>注意</strong>，箱子的体积等于箱子的长度、宽度和高度的乘积。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>length = 1000, width = 35, height = 700, mass = 300
<b>输出：</b>"Heavy"
<b>解释：</b>
箱子没有任何维度大于等于 10<sup>4 </sup>。
体积为 24500000 &lt;= 10<sup>9 </sup>。所以不能归类为 "Bulky" 。
但是质量 &gt;= 100 ，所以箱子是 "Heavy" 的。
由于箱子不是 "Bulky" 但是是 "Heavy" ，所以我们返回 "Heavy" 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>length = 200, width = 50, height = 800, mass = 50
<b>输出：</b>"Neither"
<b>解释：</b>
箱子没有任何维度大于等于 10<sup>4</sup>&nbsp;。
体积为 8 * 10<sup>6</sup> &lt;= 10<sup>9</sup>&nbsp;。所以不能归类为 "Bulky" 。
质量小于 100 ，所以不能归类为 "Heavy" 。
由于不属于上述两者任何一类，所以我们返回 "Neither" 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= length, width, height &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= mass &lt;= 10<sup>3</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

根据题意模拟即可。

时间复杂度 $O(1)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def categorizeBox(self, length: int, width: int, height: int, mass: int) -> str:
        v = length * width * height
        bulky = int(any(x >= 10000 for x in (length, width, height)) or v >= 10**9)
        heavy = int(mass >= 100)
        i = heavy << 1 | bulky
        d = ['Neither', 'Bulky', 'Heavy', 'Both']
        return d[i]
```

#### Java

```java
class Solution {
    public String categorizeBox(int length, int width, int height, int mass) {
        long v = (long) length * width * height;
        int bulky = length >= 10000 || width >= 10000 || height >= 10000 || v >= 1000000000 ? 1 : 0;
        int heavy = mass >= 100 ? 1 : 0;
        String[] d = {"Neither", "Bulky", "Heavy", "Both"};
        int i = heavy << 1 | bulky;
        return d[i];
    }
}
```

#### C++

```cpp
class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        long v = (long) length * width * height;
        int bulky = length >= 10000 || width >= 10000 || height >= 10000 || v >= 1000000000 ? 1 : 0;
        int heavy = mass >= 100 ? 1 : 0;
        string d[4] = {"Neither", "Bulky", "Heavy", "Both"};
        int i = heavy << 1 | bulky;
        return d[i];
    }
};
```

#### Go

```go
func categorizeBox(length int, width int, height int, mass int) string {
	v := length * width * height
	i := 0
	if length >= 10000 || width >= 10000 || height >= 10000 || v >= 1000000000 {
		i |= 1
	}
	if mass >= 100 {
		i |= 2
	}
	d := [4]string{"Neither", "Bulky", "Heavy", "Both"}
	return d[i]
}
```

#### TypeScript

```ts
function categorizeBox(length: number, width: number, height: number, mass: number): string {
    const v = length * width * height;
    let i = 0;
    if (length >= 10000 || width >= 10000 || height >= 10000 || v >= 1000000000) {
        i |= 1;
    }
    if (mass >= 100) {
        i |= 2;
    }
    return ['Neither', 'Bulky', 'Heavy', 'Both'][i];
}
```

#### Rust

```rust
impl Solution {
    pub fn categorize_box(length: i32, width: i32, height: i32, mass: i32) -> String {
        let v = (length as i64) * (width as i64) * (height as i64);
        let mut i = 0;

        if length >= 10000 || width >= 10000 || height >= 10000 || v >= 1000000000 {
            i |= 1;
        }

        if mass >= 100 {
            i |= 2;
        }

        let d = vec!["Neither", "Bulky", "Heavy", "Both"];
        d[i].to_string()
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
    def categorizeBox(self, length: int, width: int, height: int, mass: int) -> str:
        v = length * width * height
        bulky = any(x >= 10000 for x in (length, width, height)) or v >= 10**9
        heavy = mass >= 100

        if bulky and heavy:
            return "Both"
        if bulky:
            return "Bulky"
        if heavy:
            return "Heavy"

        return "Neither"
```

#### Java

```java
class Solution {
    public String categorizeBox(int length, int width, int height, int mass) {
        long v = (long) length * width * height;
        boolean bulky = length >= 1e4 || width >= 1e4 || height >= 1e4 || v >= 1e9;
        boolean heavy = mass >= 100;

        if (bulky && heavy) {
            return "Both";
        }
        if (bulky) {
            return "Bulky";
        }
        if (heavy) {
            return "Heavy";
        }

        return "Neither";
    }
}
```

#### C++

```cpp
class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        long v = (long) length * width * height;
        bool bulky = length >= 1e4 || width >= 1e4 || height >= 1e4 || v >= 1e9;
        bool heavy = mass >= 100;

        if (bulky && heavy) {
            return "Both";
        }
        if (bulky) {
            return "Bulky";
        }
        if (heavy) {
            return "Heavy";
        }

        return "Neither";
    }
};
```

#### Go

```go
func categorizeBox(length int, width int, height int, mass int) string {
	v := length * width * height
	bulky := length >= 1e4 || width >= 1e4 || height >= 1e4 || v >= 1e9
	heavy := mass >= 100
	if bulky && heavy {
		return "Both"
	}
	if bulky {
		return "Bulky"
	}
	if heavy {
		return "Heavy"
	}
	return "Neither"
}
```

#### TypeScript

```ts
function categorizeBox(length: number, width: number, height: number, mass: number): string {
    const v = length * width * height;
    const bulky = length >= 1e4 || width >= 1e4 || height >= 1e4 || v >= 1e9;
    const heavy = mass >= 100;
    if (bulky && heavy) {
        return 'Both';
    }
    if (bulky) {
        return 'Bulky';
    }
    if (heavy) {
        return 'Heavy';
    }
    return 'Neither';
}
```

#### Rust

```rust
impl Solution {
    pub fn categorize_box(length: i32, width: i32, height: i32, mass: i32) -> String {
        let v = length * width * height;
        let bulky = length >= 10000
            || width >= 10000
            || height >= 10000
            || (length as i64) * (width as i64) * (height as i64) >= 1000000000;

        let heavy = mass >= 100;

        if bulky && heavy {
            return "Both".to_string();
        }
        if bulky {
            return "Bulky".to_string();
        }
        if heavy {
            return "Heavy".to_string();
        }

        "Neither".to_string()
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2526. 找到数据流中的连续整数](https://leetcode.cn/problems/find-consecutive-integers-from-a-data-stream){#2526}

{{< tabs "2526" >}}

{{% tab "python" %}}
```python
class DataStream:
    def __init__(self, value: int, k: int):
        self.val, self.k = value, k
        self.cnt = 0

    def consec(self, num: int) -> bool:
        self.cnt = 0 if num != self.val else self.cnt + 1
        return self.cnt >= self.k


# Your DataStream object will be instantiated and called as such:
# obj = DataStream(value, k)
# param_1 = obj.consec(num)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class DataStream {
    private int cnt;
    private int val;
    private int k;

    public DataStream(int value, int k) {
        val = value;
        this.k = k;
    }

    public boolean consec(int num) {
        cnt = num == val ? cnt + 1 : 0;
        return cnt >= k;
    }
}

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream obj = new DataStream(value, k);
 * boolean param_1 = obj.consec(num);
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class DataStream {
public:
    DataStream(int value, int k) {
        val = value;
        this->k = k;
    }

    bool consec(int num) {
        cnt = num == val ? cnt + 1 : 0;
        return cnt >= k;
    }

private:
    int cnt = 0;
    int val, k;
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type DataStream struct {
	val, k, cnt int
}

func Constructor(value int, k int) DataStream {
	return DataStream{value, k, 0}
}

func (this *DataStream) Consec(num int) bool {
	if num == this.val {
		this.cnt++
	} else {
		this.cnt = 0
	}
	return this.cnt >= this.k
}

/**
 * Your DataStream object will be instantiated and called as such:
 * obj := Constructor(value, k);
 * param_1 := obj.Consec(num);
 */
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class DataStream {
    private val: number;
    private k: number;
    private cnt: number;

    constructor(value: number, k: number) {
        this.val = value;
        this.k = k;
        this.cnt = 0;
    }

    consec(num: number): boolean {
        this.cnt = this.val === num ? this.cnt + 1 : 0;
        return this.cnt >= this.k;
    }
}

/**
 * Your DataStream object will be instantiated and called as such:
 * var obj = new DataStream(value, k)
 * var param_1 = obj.consec(num)
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数据流，请你实现一个数据结构，检查数据流中最后&nbsp;<code>k</code>&nbsp;个整数是否 <strong>等于</strong> 给定值&nbsp;<code>value</code>&nbsp;。</p>

<p>请你实现&nbsp;<strong>DataStream</strong>&nbsp;类：</p>

<ul>
	<li><code>DataStream(int value, int k)</code>&nbsp;用两个整数 <code>value</code>&nbsp;和 <code>k</code>&nbsp;初始化一个空的整数数据流。</li>
	<li><code>boolean consec(int num)</code>&nbsp;将&nbsp;<code>num</code>&nbsp;添加到整数数据流。如果后 <code>k</code>&nbsp;个整数都等于&nbsp;<code>value</code>&nbsp;，返回&nbsp;<code>true</code>&nbsp;，否则返回&nbsp;<code>false</code>&nbsp;。如果少于&nbsp;<code>k</code>&nbsp;个整数，条件不满足，所以也返回&nbsp;<code>false</code>&nbsp;。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
["DataStream", "consec", "consec", "consec", "consec"]
[[4, 3], [4], [4], [4], [3]]
<strong>输出：</strong>
[null, false, false, true, false]

<strong>解释：</strong>
DataStream dataStream = new DataStream(4, 3); // value = 4, k = 3 
dataStream.consec(4); // 数据流中只有 1 个整数，所以返回 False 。
dataStream.consec(4); // 数据流中只有 2 个整数
                      // 由于 2 小于 k ，返回 False 。
dataStream.consec(4); // 数据流最后 3 个整数都等于 value， 所以返回 True 。
dataStream.consec(3); // 最后 k 个整数分别是 [4,4,3] 。
                      // 由于 3 不等于 value ，返回 False 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= value, num &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>5</sup></code></li>
	<li>至多调用 <code>consec</code>&nbsp;次数为&nbsp;<code>10<sup>5</sup></code>&nbsp;次。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数

我们可以维护一个计数器 $\textit{cnt}$，记录当前连续整数为 $\textit{value}$ 的个数。

调用 `consec` 方法时，如果 $\textit{num}$ 与 $\textit{value}$ 相等，我们将 $\textit{cnt}$ 自增 1，否则将 $\textit{cnt}$ 重置为 0。然后判断 $\textit{cnt}$ 是否大于等于 $\textit{k}$ 即可。

时间复杂度 $O(1)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class DataStream:
    def __init__(self, value: int, k: int):
        self.val, self.k = value, k
        self.cnt = 0

    def consec(self, num: int) -> bool:
        self.cnt = 0 if num != self.val else self.cnt + 1
        return self.cnt >= self.k


# Your DataStream object will be instantiated and called as such:
# obj = DataStream(value, k)
# param_1 = obj.consec(num)
```

#### Java

```java
class DataStream {
    private int cnt;
    private int val;
    private int k;

    public DataStream(int value, int k) {
        val = value;
        this.k = k;
    }

    public boolean consec(int num) {
        cnt = num == val ? cnt + 1 : 0;
        return cnt >= k;
    }
}

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream obj = new DataStream(value, k);
 * boolean param_1 = obj.consec(num);
 */
```

#### C++

```cpp
class DataStream {
public:
    DataStream(int value, int k) {
        val = value;
        this->k = k;
    }

    bool consec(int num) {
        cnt = num == val ? cnt + 1 : 0;
        return cnt >= k;
    }

private:
    int cnt = 0;
    int val, k;
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */
```

#### Go

```go
type DataStream struct {
	val, k, cnt int
}

func Constructor(value int, k int) DataStream {
	return DataStream{value, k, 0}
}

func (this *DataStream) Consec(num int) bool {
	if num == this.val {
		this.cnt++
	} else {
		this.cnt = 0
	}
	return this.cnt >= this.k
}

/**
 * Your DataStream object will be instantiated and called as such:
 * obj := Constructor(value, k);
 * param_1 := obj.Consec(num);
 */
```

#### TypeScript

```ts
class DataStream {
    private val: number;
    private k: number;
    private cnt: number;

    constructor(value: number, k: number) {
        this.val = value;
        this.k = k;
        this.cnt = 0;
    }

    consec(num: number): boolean {
        this.cnt = this.val === num ? this.cnt + 1 : 0;
        return this.cnt >= this.k;
    }
}

/**
 * Your DataStream object will be instantiated and called as such:
 * var obj = new DataStream(value, k)
 * var param_1 = obj.consec(num)
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2527. 查询数组异或美丽值](https://leetcode.cn/problems/find-xor-beauty-of-array){#2527}

{{< tabs "2527" >}}

{{% tab "python" %}}
```python
class Solution:
    def xorBeauty(self, nums: List[int]) -> int:
        return reduce(xor, nums)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int xorBeauty(int[] nums) {
        int ans = 0;
        for (int x : nums) {
            ans ^= x;
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
    int xorBeauty(vector<int>& nums) {
        int ans = 0;
        for (auto& x : nums) {
            ans ^= x;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func xorBeauty(nums []int) (ans int) {
	for _, x := range nums {
		ans ^= x
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function xorBeauty(nums: number[]): number {
    return nums.reduce((acc, cur) => acc ^ cur, 0);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>nums</code>&nbsp;。</p>

<p>三个下标&nbsp;<code>i</code>&nbsp;，<code>j</code>&nbsp;和&nbsp;<code>k</code>&nbsp;的 <strong>有效值</strong>&nbsp;定义为&nbsp;<code>((nums[i] | nums[j]) &amp; nums[k])</code>&nbsp;。</p>

<p>一个数组的 <strong>异或美丽值</strong>&nbsp;是数组中所有满足&nbsp;<code>0 &lt;= i, j, k &lt; n</code>&nbsp;&nbsp;<strong>的三元组</strong>&nbsp;<code>(i, j, k)</code>&nbsp;的 <strong>有效值</strong>&nbsp;的异或结果。</p>

<p>请你返回&nbsp;<code>nums</code>&nbsp;的异或美丽值。</p>

<p><b>注意：</b></p>

<ul>
	<li><code>val1 | val2</code>&nbsp;是&nbsp;<code>val1</code> 和&nbsp;<code>val2</code>&nbsp;的按位或。</li>
	<li><code>val1 &amp; val2</code>&nbsp;是&nbsp;<code>val1</code> 和&nbsp;<code>val2</code>&nbsp;的按位与。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [1,4]
<b>输出：</b>5
<b>解释：</b>
三元组和它们对应的有效值如下：
- (0,0,0) 有效值为 ((1 | 1) &amp; 1) = 1
- (0,0,1) 有效值为 ((1 | 1) &amp; 4) = 0
- (0,1,0) 有效值为 ((1 | 4) &amp; 1) = 1
- (0,1,1) 有效值为 ((1 | 4) &amp; 4) = 4
- (1,0,0) 有效值为 ((4 | 1) &amp; 1) = 1
- (1,0,1) 有效值为 ((4 | 1) &amp; 4) = 4
- (1,1,0) 有效值为 ((4 | 4) &amp; 1) = 0
- (1,1,1) 有效值为 ((4 | 4) &amp; 4) = 4 
数组的异或美丽值为所有有效值的按位异或 1 ^ 0 ^ 1 ^ 4 ^ 1 ^ 4 ^ 0 ^ 4 = 5 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [15,45,20,2,34,35,5,44,32,30]
<b>输出：</b>34
<code><span style=""><b>解释：</b>数组的异或美丽值为</span> 34 。</code>
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length&nbsp;&lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：位运算

我们首先考虑 $i$ 与 $j$ 不相等的情况，此时 $(nums[i] | nums[j]) \& nums[k]$ 与 $(nums[j] | nums[i]) \& nums[k]$ 的结果是相同的，两者的异或结果为 $0$。

因此，我们只需要考虑 $i$ 与 $j$ 相等的情况。此时 $(nums[i] | nums[j]) \& nums[k] = nums[i] \& nums[k]$，如果 $i \neq k$，那么与 $nums[k] \& nums[i]$ 的结果是相同的，这些值的异或结果为 $0$。

因此，我们最终只需要考虑 $i = j = k$ 的情况，那么答案就是所有 $nums[i]$ 的异或结果。

时间复杂度 $O(n)$，空间复杂度 $O(1)$。其中 $n$ 为数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def xorBeauty(self, nums: List[int]) -> int:
        return reduce(xor, nums)
```

#### Java

```java
class Solution {
    public int xorBeauty(int[] nums) {
        int ans = 0;
        for (int x : nums) {
            ans ^= x;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int xorBeauty(vector<int>& nums) {
        int ans = 0;
        for (auto& x : nums) {
            ans ^= x;
        }
        return ans;
    }
};
```

#### Go

```go
func xorBeauty(nums []int) (ans int) {
	for _, x := range nums {
		ans ^= x
	}
	return
}
```

#### TypeScript

```ts
function xorBeauty(nums: number[]): number {
    return nums.reduce((acc, cur) => acc ^ cur, 0);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2528. 最大化城市的最小电量](https://leetcode.cn/problems/maximize-the-minimum-powered-city){#2528}

{{< tabs "2528" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxPower(self, stations: List[int], r: int, k: int) -> int:
        def check(x, k):
            d = [0] * (n + 1)
            t = 0
            for i in range(n):
                t += d[i]
                dist = x - (s[i] + t)
                if dist > 0:
                    if k < dist:
                        return False
                    k -= dist
                    j = min(i + r, n - 1)
                    left, right = max(0, j - r), min(j + r, n - 1)
                    d[left] += dist
                    d[right + 1] -= dist
                    t += dist
            return True

        n = len(stations)
        d = [0] * (n + 1)
        for i, v in enumerate(stations):
            left, right = max(0, i - r), min(i + r, n - 1)
            d[left] += v
            d[right + 1] -= v
        s = list(accumulate(d))
        left, right = 0, 1 << 40
        while left < right:
            mid = (left + right + 1) >> 1
            if check(mid, k):
                left = mid
            else:
                right = mid - 1
        return left
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private long[] s;
    private long[] d;
    private int n;

    public long maxPower(int[] stations, int r, int k) {
        n = stations.length;
        d = new long[n + 1];
        s = new long[n + 1];
        for (int i = 0; i < n; ++i) {
            int left = Math.max(0, i - r), right = Math.min(i + r, n - 1);
            d[left] += stations[i];
            d[right + 1] -= stations[i];
        }
        s[0] = d[0];
        for (int i = 1; i < n + 1; ++i) {
            s[i] = s[i - 1] + d[i];
        }
        long left = 0, right = 1l << 40;
        while (left < right) {
            long mid = (left + right + 1) >>> 1;
            if (check(mid, r, k)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }

    private boolean check(long x, int r, int k) {
        Arrays.fill(d, 0);
        long t = 0;
        for (int i = 0; i < n; ++i) {
            t += d[i];
            long dist = x - (s[i] + t);
            if (dist > 0) {
                if (k < dist) {
                    return false;
                }
                k -= dist;
                int j = Math.min(i + r, n - 1);
                int left = Math.max(0, j - r), right = Math.min(j + r, n - 1);
                d[left] += dist;
                d[right + 1] -= dist;
                t += dist;
            }
        }
        return true;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        long d[n + 1];
        memset(d, 0, sizeof d);
        for (int i = 0; i < n; ++i) {
            int left = max(0, i - r), right = min(i + r, n - 1);
            d[left] += stations[i];
            d[right + 1] -= stations[i];
        }
        long s[n + 1];
        s[0] = d[0];
        for (int i = 1; i < n + 1; ++i) {
            s[i] = s[i - 1] + d[i];
        }
        auto check = [&](long x, int k) {
            memset(d, 0, sizeof d);
            long t = 0;
            for (int i = 0; i < n; ++i) {
                t += d[i];
                long dist = x - (s[i] + t);
                if (dist > 0) {
                    if (k < dist) {
                        return false;
                    }
                    k -= dist;
                    int j = min(i + r, n - 1);
                    int left = max(0, j - r), right = min(j + r, n - 1);
                    d[left] += dist;
                    d[right + 1] -= dist;
                    t += dist;
                }
            }
            return true;
        };
        long left = 0, right = 1e12;
        while (left < right) {
            long mid = (left + right + 1) >> 1;
            if (check(mid, k)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxPower(stations []int, r int, k int) int64 {
	n := len(stations)
	d := make([]int, n+1)
	s := make([]int, n+1)
	for i, v := range stations {
		left, right := max(0, i-r), min(i+r, n-1)
		d[left] += v
		d[right+1] -= v
	}
	s[0] = d[0]
	for i := 1; i < n+1; i++ {
		s[i] = s[i-1] + d[i]
	}
	check := func(x, k int) bool {
		d := make([]int, n+1)
		t := 0
		for i := range stations {
			t += d[i]
			dist := x - (s[i] + t)
			if dist > 0 {
				if k < dist {
					return false
				}
				k -= dist
				j := min(i+r, n-1)
				left, right := max(0, j-r), min(j+r, n-1)
				d[left] += dist
				d[right+1] -= dist
				t += dist
			}
		}
		return true
	}
	left, right := 0, 1<<40
	for left < right {
		mid := (left + right + 1) >> 1
		if check(mid, k) {
			left = mid
		} else {
			right = mid - 1
		}
	}
	return int64(left)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxPower(stations: number[], r: number, k: number): number {
    function check(x: bigint, k: bigint): boolean {
        d.fill(0n);
        let t = 0n;
        for (let i = 0; i < n; ++i) {
            t += d[i];
            const dist = x - (s[i] + t);
            if (dist > 0) {
                if (k < dist) {
                    return false;
                }
                k -= dist;
                const j = Math.min(i + r, n - 1);
                const left = Math.max(0, j - r);
                const right = Math.min(j + r, n - 1);
                d[left] += dist;
                d[right + 1] -= dist;
                t += dist;
            }
        }
        return true;
    }
    const n = stations.length;
    const d: bigint[] = new Array(n + 1).fill(0n);
    const s: bigint[] = new Array(n + 1).fill(0n);

    for (let i = 0; i < n; ++i) {
        const left = Math.max(0, i - r);
        const right = Math.min(i + r, n - 1);
        d[left] += BigInt(stations[i]);
        d[right + 1] -= BigInt(stations[i]);
    }

    s[0] = d[0];
    for (let i = 1; i < n + 1; ++i) {
        s[i] = s[i - 1] + d[i];
    }

    let left = 0n,
        right = 1n << 40n;
    while (left < right) {
        const mid = (left + right + 1n) >> 1n;
        if (check(mid, BigInt(k))) {
            left = mid;
        } else {
            right = mid - 1n;
        }
    }
    return Number(left);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong>&nbsp;开始长度为 <code>n</code>&nbsp;的整数数组&nbsp;<code>stations</code>&nbsp;，其中&nbsp;<code>stations[i]</code>&nbsp;表示第 <code>i</code>&nbsp;座城市的供电站数目。</p>

<p>每个供电站可以在一定 <strong>范围</strong>&nbsp;内给所有城市提供电力。换句话说，如果给定的范围是&nbsp;<code>r</code>&nbsp;，在城市&nbsp;<code>i</code>&nbsp;处的供电站可以给所有满足&nbsp;<code>|i - j| &lt;= r</code> 且&nbsp;<code>0 &lt;= i, j &lt;= n - 1</code>&nbsp;的城市&nbsp;<code>j</code>&nbsp;供电。</p>

<ul>
	<li><code>|x|</code>&nbsp;表示 <code>x</code>&nbsp;的 <strong>绝对值</strong>&nbsp;。比方说，<code>|7 - 5| = 2</code>&nbsp;，<code>|3 - 10| = 7</code>&nbsp;。</li>
</ul>

<p>一座城市的 <strong>电量</strong>&nbsp;是所有能给它供电的供电站数目。</p>

<p>政府批准了可以额外建造 <code>k</code>&nbsp;座供电站，你需要决定这些供电站分别应该建在哪里，这些供电站与已经存在的供电站有相同的供电范围。</p>

<p>给你两个整数&nbsp;<code>r</code> 和&nbsp;<code>k</code>&nbsp;，如果以最优策略建造额外的发电站，返回所有城市中，最小电量的最大值是多少。</p>

<p>这 <code>k</code>&nbsp;座供电站可以建在多个城市。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>stations = [1,2,4,5,0], r = 1, k = 2
<b>输出：</b>5
<b>解释：</b>
最优方案之一是把 2 座供电站都建在城市 1 。
每座城市的供电站数目分别为 [1,4,4,5,0] 。
- 城市 0 的供电站数目为 1 + 4 = 5 。
- 城市 1 的供电站数目为 1 + 4 + 4 = 9 。
- 城市 2 的供电站数目为 4 + 4 + 5 = 13 。
- 城市 3 的供电站数目为 5 + 4 = 9 。
- 城市 4 的供电站数目为 5 + 0 = 5 。
供电站数目最少是 5 。
无法得到更优解，所以我们返回 5 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>stations = [4,4,4,4], r = 0, k = 3
<b>输出：</b>4
<b>解释：</b>
无论如何安排，总有一座城市的供电站数目是 4 ，所以最优解是 4 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == stations.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= stations[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= r&nbsp;&lt;= n - 1</code></li>
	<li><code>0 &lt;= k&nbsp;&lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二分查找 + 差分数组 + 贪心

根据题目描述，最小供电站数目随着 $k$ 值的增大而增大，因此，我们可以用二分查找，找到一个最大的最小供电站数目，并且需要额外建造的供电站不超过 $k$ 座。

我们先利用差分数组以及前缀和算出初始时每座城市的供电站数目，记录在数组 $s$ 中，其中 $s[i]$ 表示第 $i$ 座城市的供电站数目。

接下来，我们定义二分查找的左边界为 $0$，右边界为 $2^{40}$。然后实现一个 $check(x, k)$ 函数，用于判断是否城市供电站数目的最小值是否可以为 $x$，使得额外建造的供电站不超过 $k$ 座。

函数 $check(x, k)$ 的实现逻辑是：

遍历每座城市，如果当前城市 $i$ 的供电站数目小于 $x$，此时我们可以贪心地在尽可能右边的位置上建造供电站，位置 $j = \min(i + r, n - 1)$，这样可以使得供电站覆盖尽可能多的城市。过程中我们可以借助差分数组，给一段连续的位置加上某个值。如果需要额外建造的供电站数量超过 $k$，那么 $x$ 不满足条件，返回 `false`。否则遍历结束后，返回 `true`。

时间复杂度 $O(n \times \log M)$，空间复杂度 $O(n)$。其中 $n$ 为城市数量，而 $M$ 我们固定取 $2^{40}$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxPower(self, stations: List[int], r: int, k: int) -> int:
        def check(x, k):
            d = [0] * (n + 1)
            t = 0
            for i in range(n):
                t += d[i]
                dist = x - (s[i] + t)
                if dist > 0:
                    if k < dist:
                        return False
                    k -= dist
                    j = min(i + r, n - 1)
                    left, right = max(0, j - r), min(j + r, n - 1)
                    d[left] += dist
                    d[right + 1] -= dist
                    t += dist
            return True

        n = len(stations)
        d = [0] * (n + 1)
        for i, v in enumerate(stations):
            left, right = max(0, i - r), min(i + r, n - 1)
            d[left] += v
            d[right + 1] -= v
        s = list(accumulate(d))
        left, right = 0, 1 << 40
        while left < right:
            mid = (left + right + 1) >> 1
            if check(mid, k):
                left = mid
            else:
                right = mid - 1
        return left
```

#### Java

```java
class Solution {
    private long[] s;
    private long[] d;
    private int n;

    public long maxPower(int[] stations, int r, int k) {
        n = stations.length;
        d = new long[n + 1];
        s = new long[n + 1];
        for (int i = 0; i < n; ++i) {
            int left = Math.max(0, i - r), right = Math.min(i + r, n - 1);
            d[left] += stations[i];
            d[right + 1] -= stations[i];
        }
        s[0] = d[0];
        for (int i = 1; i < n + 1; ++i) {
            s[i] = s[i - 1] + d[i];
        }
        long left = 0, right = 1l << 40;
        while (left < right) {
            long mid = (left + right + 1) >>> 1;
            if (check(mid, r, k)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }

    private boolean check(long x, int r, int k) {
        Arrays.fill(d, 0);
        long t = 0;
        for (int i = 0; i < n; ++i) {
            t += d[i];
            long dist = x - (s[i] + t);
            if (dist > 0) {
                if (k < dist) {
                    return false;
                }
                k -= dist;
                int j = Math.min(i + r, n - 1);
                int left = Math.max(0, j - r), right = Math.min(j + r, n - 1);
                d[left] += dist;
                d[right + 1] -= dist;
                t += dist;
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
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        long d[n + 1];
        memset(d, 0, sizeof d);
        for (int i = 0; i < n; ++i) {
            int left = max(0, i - r), right = min(i + r, n - 1);
            d[left] += stations[i];
            d[right + 1] -= stations[i];
        }
        long s[n + 1];
        s[0] = d[0];
        for (int i = 1; i < n + 1; ++i) {
            s[i] = s[i - 1] + d[i];
        }
        auto check = [&](long x, int k) {
            memset(d, 0, sizeof d);
            long t = 0;
            for (int i = 0; i < n; ++i) {
                t += d[i];
                long dist = x - (s[i] + t);
                if (dist > 0) {
                    if (k < dist) {
                        return false;
                    }
                    k -= dist;
                    int j = min(i + r, n - 1);
                    int left = max(0, j - r), right = min(j + r, n - 1);
                    d[left] += dist;
                    d[right + 1] -= dist;
                    t += dist;
                }
            }
            return true;
        };
        long left = 0, right = 1e12;
        while (left < right) {
            long mid = (left + right + 1) >> 1;
            if (check(mid, k)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};
```

#### Go

```go
func maxPower(stations []int, r int, k int) int64 {
	n := len(stations)
	d := make([]int, n+1)
	s := make([]int, n+1)
	for i, v := range stations {
		left, right := max(0, i-r), min(i+r, n-1)
		d[left] += v
		d[right+1] -= v
	}
	s[0] = d[0]
	for i := 1; i < n+1; i++ {
		s[i] = s[i-1] + d[i]
	}
	check := func(x, k int) bool {
		d := make([]int, n+1)
		t := 0
		for i := range stations {
			t += d[i]
			dist := x - (s[i] + t)
			if dist > 0 {
				if k < dist {
					return false
				}
				k -= dist
				j := min(i+r, n-1)
				left, right := max(0, j-r), min(j+r, n-1)
				d[left] += dist
				d[right+1] -= dist
				t += dist
			}
		}
		return true
	}
	left, right := 0, 1<<40
	for left < right {
		mid := (left + right + 1) >> 1
		if check(mid, k) {
			left = mid
		} else {
			right = mid - 1
		}
	}
	return int64(left)
}
```

#### TypeScript

```ts
function maxPower(stations: number[], r: number, k: number): number {
    function check(x: bigint, k: bigint): boolean {
        d.fill(0n);
        let t = 0n;
        for (let i = 0; i < n; ++i) {
            t += d[i];
            const dist = x - (s[i] + t);
            if (dist > 0) {
                if (k < dist) {
                    return false;
                }
                k -= dist;
                const j = Math.min(i + r, n - 1);
                const left = Math.max(0, j - r);
                const right = Math.min(j + r, n - 1);
                d[left] += dist;
                d[right + 1] -= dist;
                t += dist;
            }
        }
        return true;
    }
    const n = stations.length;
    const d: bigint[] = new Array(n + 1).fill(0n);
    const s: bigint[] = new Array(n + 1).fill(0n);

    for (let i = 0; i < n; ++i) {
        const left = Math.max(0, i - r);
        const right = Math.min(i + r, n - 1);
        d[left] += BigInt(stations[i]);
        d[right + 1] -= BigInt(stations[i]);
    }

    s[0] = d[0];
    for (let i = 1; i < n + 1; ++i) {
        s[i] = s[i - 1] + d[i];
    }

    let left = 0n,
        right = 1n << 40n;
    while (left < right) {
        const mid = (left + right + 1n) >> 1n;
        if (check(mid, BigInt(k))) {
            left = mid;
        } else {
            right = mid - 1n;
        }
    }
    return Number(left);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2529. 正整数和负整数的最大计数](https://leetcode.cn/problems/maximum-count-of-positive-integer-and-negative-integer){#2529}

{{< tabs "2529" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumCount(self, nums: List[int]) -> int:
        a = len(nums) - bisect_left(nums, 1)
        b = bisect_left(nums, 0)
        return max(a, b)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maximumCount(int[] nums) {
        int a = nums.length - search(nums, 1);
        int b = search(nums, 0);
        return Math.max(a, b);
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
    int maximumCount(vector<int>& nums) {
        int a = nums.end() - lower_bound(nums.begin(), nums.end(), 1);
        int b = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        return max(a, b);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumCount(nums []int) int {
	a := len(nums) - sort.SearchInts(nums, 1)
	b := sort.SearchInts(nums, 0)
	return max(a, b)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumCount(nums: number[]): number {
    const search = (x: number): number => {
        let [left, right] = [0, nums.length];
        while (left < right) {
            const mid = (left + right) >> 1;
            if (nums[mid] >= x) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    };
    const i = search(1);
    const j = search(0);
    const [a, b] = [nums.length - i, j];
    return Math.max(a, b);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    fn search(nums: &Vec<i32>, x: i32) -> usize {
        let mut left = 0;
        let mut right = nums.len();
        while left < right {
            let mid = (left + right) >> 1;
            if nums[mid] >= x {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        left
    }

    pub fn maximum_count(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let i = Self::search(&nums, 1);
        let j = Self::search(&nums, 0);
        (n - i).max(j) as i32
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
#define max(a, b) (a > b ? a : b)

int search(int* nums, int numsSize, int x) {
    int left = 0;
    int right = numsSize;
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

int maximumCount(int* nums, int numsSize) {
    int i = search(nums, numsSize, 1);
    int j = search(nums, numsSize, 0);
    return max(numsSize - i, j);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个按 <strong>非递减顺序</strong> 排列的数组 <code>nums</code> ，返回正整数数目和负整数数目中的最大值。</p>

<ul>
	<li>换句话讲，如果 <code>nums</code> 中正整数的数目是 <code>pos</code> ，而负整数的数目是 <code>neg</code> ，返回 <code>pos</code> 和 <code>neg</code>二者中的最大值。</li>
</ul>

<p><strong>注意：</strong><code>0</code> 既不是正整数也不是负整数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [-2,-1,-1,1,2,3]
<strong>输出：</strong>3
<strong>解释：</strong>共有 3 个正整数和 3 个负整数。计数得到的最大值是 3 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [-3,-2,-1,0,0,1,2]
<strong>输出：</strong>3
<strong>解释：</strong>共有 2 个正整数和 3 个负整数。计数得到的最大值是 3 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [5,20,66,1314]
<strong>输出：</strong>4
<strong>解释：</strong>共有 4 个正整数和 0 个负整数。计数得到的最大值是 4 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 2000</code></li>
	<li><code>-2000 &lt;= nums[i] &lt;= 2000</code></li>
	<li><code>nums</code> 按 <strong>非递减顺序</strong> 排列。</li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>你可以设计并实现时间复杂度为 <code>O(log(n))</code> 的算法解决此问题吗？</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：遍历

我们可以直接遍历数组，统计正整数和负整数的个数 $a$ 和 $b$，返回 $a$ 和 $b$ 中的较大值即可。

时间复杂度 $O(n)$，其中 $n$ 为数组长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumCount(self, nums: List[int]) -> int:
        a = sum(x > 0 for x in nums)
        b = sum(x < 0 for x in nums)
        return max(a, b)
```

#### Java

```java
class Solution {
    public int maximumCount(int[] nums) {
        int a = 0, b = 0;
        for (int x : nums) {
            if (x > 0) {
                ++a;
            } else if (x < 0) {
                ++b;
            }
        }
        return Math.max(a, b);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int a = 0, b = 0;
        for (int x : nums) {
            if (x > 0) {
                ++a;
            } else if (x < 0) {
                ++b;
            }
        }
        return max(a, b);
    }
};
```

#### Go

```go
func maximumCount(nums []int) int {
	var a, b int
	for _, x := range nums {
		if x > 0 {
			a++
		} else if x < 0 {
			b++
		}
	}
	return max(a, b)
}
```

#### TypeScript

```ts
function maximumCount(nums: number[]): number {
    let [a, b] = [0, 0];
    for (const x of nums) {
        if (x > 0) {
            ++a;
        } else if (x < 0) {
            ++b;
        }
    }
    return Math.max(a, b);
}
```

#### Rust

```rust
impl Solution {
    pub fn maximum_count(nums: Vec<i32>) -> i32 {
        let mut a = 0;
        let mut b = 0;

        for x in nums {
            if x > 0 {
                a += 1;
            } else if x < 0 {
                b += 1;
            }
        }

        std::cmp::max(a, b)
    }
}
```

#### C

```c
#define max(a, b) (a > b ? a : b)

int maximumCount(int* nums, int numsSize) {
    int a = 0, b = 0;
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] > 0) {
            ++a;
        } else if (nums[i] < 0) {
            ++b;
        }
    }
    return max(a, b);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：二分查找

由于数组是按非递减顺序排列的，因此可以使用二分查找找到第一个大于等于 $1$ 的元素的下标 $i$ 以及第一个大于等于 $0$ 的元素的下标 $j$，那么正整数的个数 $a = n - i$，负整数的个数 $b = j$，返回 $a$ 和 $b$ 中的较大值即可。

时间复杂度 $O(\log n)$，其中 $n$ 为数组长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumCount(self, nums: List[int]) -> int:
        a = len(nums) - bisect_left(nums, 1)
        b = bisect_left(nums, 0)
        return max(a, b)
```

#### Java

```java
class Solution {
    public int maximumCount(int[] nums) {
        int a = nums.length - search(nums, 1);
        int b = search(nums, 0);
        return Math.max(a, b);
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
    int maximumCount(vector<int>& nums) {
        int a = nums.end() - lower_bound(nums.begin(), nums.end(), 1);
        int b = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        return max(a, b);
    }
};
```

#### Go

```go
func maximumCount(nums []int) int {
	a := len(nums) - sort.SearchInts(nums, 1)
	b := sort.SearchInts(nums, 0)
	return max(a, b)
}
```

#### TypeScript

```ts
function maximumCount(nums: number[]): number {
    const search = (x: number): number => {
        let [left, right] = [0, nums.length];
        while (left < right) {
            const mid = (left + right) >> 1;
            if (nums[mid] >= x) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    };
    const i = search(1);
    const j = search(0);
    const [a, b] = [nums.length - i, j];
    return Math.max(a, b);
}
```

#### Rust

```rust
impl Solution {
    fn search(nums: &Vec<i32>, x: i32) -> usize {
        let mut left = 0;
        let mut right = nums.len();
        while left < right {
            let mid = (left + right) >> 1;
            if nums[mid] >= x {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        left
    }

    pub fn maximum_count(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let i = Self::search(&nums, 1);
        let j = Self::search(&nums, 0);
        (n - i).max(j) as i32
    }
}
```

#### C

```c
#define max(a, b) (a > b ? a : b)

int search(int* nums, int numsSize, int x) {
    int left = 0;
    int right = numsSize;
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

int maximumCount(int* nums, int numsSize) {
    int i = search(nums, numsSize, 1);
    int j = search(nums, numsSize, 0);
    return max(numsSize - i, j);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
