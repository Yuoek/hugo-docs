---
title: "2310_个位数字为 K 的整数之和"
date: 2025-10-08T18:39:12+08:00
weight: 2
tags: [二叉树, 位运算, 动态规划, 图, 字符串, 并查集, 广度优先搜索, 数学, 数据库, 数组, 枚举, 树, 深度优先搜索, 矩阵, 记忆化搜索, 贪心]
---

{{< markmap >}}
### [2310_个位数字为 K 的整数之和](#2310)
#### [贪心](#2310)
#### [数学](#2310)
#### [动态规划](#2310)
#### [枚举](#2310)
### [2311_小于等于 K 的最长二进制子序列](#2311)
#### [贪心](#2311)
#### [记忆化搜索](#2311)
#### [字符串](#2311)
#### [动态规划](#2311)
### [2312_卖木头块](#2312)
#### [记忆化搜索](#2312)
#### [数组](#2312)
#### [动态规划](#2312)
### [2313_二叉树中得到结果所需的最少翻转次数 🔒](#2313)
#### [树](#2313)
#### [深度优先搜索](#2313)
#### [动态规划](#2313)
#### [二叉树](#2313)
### [2314_每个城市最高气温的第一天 🔒](#2314)
#### [数据库](#2314)
### [2315_统计星号](#2315)
#### [字符串](#2315)
### [2316_统计无向图中无法互相到达点对数](#2316)
#### [深度优先搜索](#2316)
#### [广度优先搜索](#2316)
#### [并查集](#2316)
#### [图](#2316)
### [2317_操作后的最大异或和](#2317)
#### [位运算](#2317)
#### [数组](#2317)
#### [数学](#2317)
### [2318_不同骰子序列的数目](#2318)
#### [记忆化搜索](#2318)
#### [动态规划](#2318)
### [2319_判断矩阵是否是一个 X 矩阵](#2319)
#### [数组](#2319)
#### [矩阵](#2319)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2310_个位数字为 K 的整数之和
___
#### 贪心
___
#### 数学
___
#### 动态规划
___
#### 枚举
---
### 2311_小于等于 K 的最长二进制子序列
___
#### 贪心
___
#### 记忆化搜索
___
#### 字符串
___
#### 动态规划
---
### 2312_卖木头块
___
#### 记忆化搜索
___
#### 数组
___
#### 动态规划
---
### 2313_二叉树中得到结果所需的最少翻转次数 🔒
___
#### 树
___
#### 深度优先搜索
___
#### 动态规划
___
#### 二叉树
---
### 2314_每个城市最高气温的第一天 🔒
___
#### 数据库
---
### 2315_统计星号
___
#### 字符串
---
### 2316_统计无向图中无法互相到达点对数
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 并查集
___
#### 图
---
### 2317_操作后的最大异或和
___
#### 位运算
___
#### 数组
___
#### 数学
---
### 2318_不同骰子序列的数目
___
#### 记忆化搜索
___
#### 动态规划
---
### 2319_判断矩阵是否是一个 X 矩阵
___
#### 数组
___
#### 矩阵
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二叉树 | 位运算 | 动态规划 |
| 图 | 字符串 | 并查集 |
| 广度优先搜索 | 数学 | 数据库 |
| 数组 | 枚举 | 树 |
| 深度优先搜索 | 矩阵 | 记忆化搜索 |
| 贪心 |  |  |

# [2310. 个位数字为 K 的整数之和](https://leetcode.cn/problems/sum-of-numbers-with-units-digit-k){#2310}

{{< tabs "2310" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumNumbers(self, num: int, k: int) -> int:
        @cache
        def dfs(v):
            if v == 0:
                return 0
            if v < 10 and v % k:
                return inf
            i = 0
            t = inf
            while (x := i * 10 + k) <= v:
                t = min(t, dfs(v - x))
                i += 1
            return t + 1

        if num == 0:
            return 0
        if k == 0:
            return -1 if num % 10 else 1
        ans = dfs(num)
        return -1 if ans >= inf else ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumNumbers(int num, int k) {
        if (num == 0) {
            return 0;
        }
        for (int i = 1; i <= 10; ++i) {
            if ((k * i) % 10 == num % 10 && k * i <= num) {
                return i;
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
    int minimumNumbers(int num, int k) {
        if (!num) return 0;
        for (int i = 1; i <= 10; ++i)
            if ((k * i) % 10 == num % 10 && k * i <= num)
                return i;
        return -1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumNumbers(num int, k int) int {
	if num == 0 {
		return 0
	}
	for i := 1; i <= 10; i++ {
		if (k*i)%10 == num%10 && k*i <= num {
			return i
		}
	}
	return -1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumNumbers(num: number, k: number): number {
    if (!num) return 0;
    let digit = num % 10;
    for (let i = 1; i < 11; i++) {
        let target = i * k;
        if (target <= num && target % 10 == digit) return i;
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

<p>给你两个整数 <code>num</code> 和 <code>k</code> ，考虑具有以下属性的正整数多重集：</p>

<ul>
	<li>每个整数个位数字都是 <code>k</code> 。</li>
	<li>所有整数之和是 <code>num</code> 。</li>
</ul>

<p>返回该多重集的最小大小，如果不存在这样的多重集，返回<em> </em><code>-1</code> 。</p>

<p>注意：</p>

<ul>
	<li>多重集与集合类似，但多重集可以包含多个同一整数，空多重集的和为 <code>0</code> 。</li>
	<li><strong>个位数字</strong> 是数字最右边的数位。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>num = 58, k = 9
<strong>输出：</strong>2
<strong>解释：</strong>
多重集 [9,49] 满足题目条件，和为 58 且每个整数的个位数字是 9 。
另一个满足条件的多重集是 [19,39] 。
可以证明 2 是满足题目条件的多重集的最小长度。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>num = 37, k = 2
<strong>输出：</strong>-1
<strong>解释：</strong>个位数字为 2 的整数无法相加得到 37 。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>num = 0, k = 7
<strong>输出：</strong>0
<strong>解释：</strong>空多重集的和为 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= num &lt;= 3000</code></li>
	<li><code>0 &lt;= k &lt;= 9</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数学 + 枚举

符合拆分条件的每个数都可以表示成 $10x_i+k$，若总共有 $n$ 个数，那么 $\textit{num}-n \times k$ 必然是 $10$ 的倍数。

我们从小到达枚举 $n$，找到第一个满足 $\textit{num}-n \times k$ 是 $10$ 的倍数的 $n$。由于 $n$ 不会超过 $\textit{num}$，因此 $n$ 最大枚举至 $\textit{num}$。

也可以只考虑个位，个位满足，高位随意。

时间复杂度 $O(n)$，其中 $n$ 为 $\textit{num}$ 的大小。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumNumbers(self, num: int, k: int) -> int:
        if num == 0:
            return 0
        for i in range(1, num + 1):
            if (t := num - k * i) >= 0 and t % 10 == 0:
                return i
        return -1
```

#### Java

```java
class Solution {
    public int minimumNumbers(int num, int k) {
        if (num == 0) {
            return 0;
        }
        for (int i = 1; i <= num; ++i) {
            int t = num - k * i;
            if (t >= 0 && t % 10 == 0) {
                return i;
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
    int minimumNumbers(int num, int k) {
        if (num == 0) return 0;
        for (int i = 1; i <= num; ++i) {
            int t = num - k * i;
            if (t >= 0 && t % 10 == 0) return i;
        }
        return -1;
    }
};
```

#### Go

```go
func minimumNumbers(num int, k int) int {
	if num == 0 {
		return 0
	}
	for i := 1; i <= num; i++ {
		t := num - k*i
		if t >= 0 && t%10 == 0 {
			return i
		}
	}
	return -1
}
```

#### TypeScript

```ts
function minimumNumbers(num: number, k: number): number {
    if (!num) return 0;
    let digit = num % 10;
    for (let i = 1; i < 11; i++) {
        let target = i * k;
        if (target <= num && target % 10 == digit) return i;
    }
    return -1;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：记忆化搜索

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumNumbers(self, num: int, k: int) -> int:
        if num == 0:
            return 0
        for i in range(1, 11):
            if (k * i) % 10 == num % 10 and k * i <= num:
                return i
        return -1
```

#### Java

```java
class Solution {
    public int minimumNumbers(int num, int k) {
        if (num == 0) {
            return 0;
        }
        for (int i = 1; i <= 10; ++i) {
            if ((k * i) % 10 == num % 10 && k * i <= num) {
                return i;
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
    int minimumNumbers(int num, int k) {
        if (!num) return 0;
        for (int i = 1; i <= 10; ++i)
            if ((k * i) % 10 == num % 10 && k * i <= num)
                return i;
        return -1;
    }
};
```

#### Go

```go
func minimumNumbers(num int, k int) int {
	if num == 0 {
		return 0
	}
	for i := 1; i <= 10; i++ {
		if (k*i)%10 == num%10 && k*i <= num {
			return i
		}
	}
	return -1
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法三

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumNumbers(self, num: int, k: int) -> int:
        @cache
        def dfs(v):
            if v == 0:
                return 0
            if v < 10 and v % k:
                return inf
            i = 0
            t = inf
            while (x := i * 10 + k) <= v:
                t = min(t, dfs(v - x))
                i += 1
            return t + 1

        if num == 0:
            return 0
        if k == 0:
            return -1 if num % 10 else 1
        ans = dfs(num)
        return -1 if ans >= inf else ans
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2311. 小于等于 K 的最长二进制子序列](https://leetcode.cn/problems/longest-binary-subsequence-less-than-or-equal-to-k){#2311}

{{< tabs "2311" >}}

{{% tab "python" %}}
```python
class Solution:
    def longestSubsequence(self, s: str, k: int) -> int:
        ans = v = 0
        for c in s[::-1]:
            if c == "0":
                ans += 1
            elif ans < 30 and (v | 1 << ans) <= k:
                v |= 1 << ans
                ans += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int longestSubsequence(String s, int k) {
        int ans = 0, v = 0;
        for (int i = s.length() - 1; i >= 0; --i) {
            if (s.charAt(i) == '0') {
                ++ans;
            } else if (ans < 30 && (v | 1 << ans) <= k) {
                v |= 1 << ans;
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
    int longestSubsequence(string s, int k) {
        int ans = 0, v = 0;
        for (int i = s.size() - 1; ~i; --i) {
            if (s[i] == '0') {
                ++ans;
            } else if (ans < 30 && (v | 1 << ans) <= k) {
                v |= 1 << ans;
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
func longestSubsequence(s string, k int) (ans int) {
	for i, v := len(s)-1, 0; i >= 0; i-- {
		if s[i] == '0' {
			ans++
		} else if ans < 30 && (v|1<<ans) <= k {
			v |= 1 << ans
			ans++
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function longestSubsequence(s: string, k: number): number {
    let ans = 0;
    for (let i = s.length - 1, v = 0; ~i; --i) {
        if (s[i] == '0') {
            ++ans;
        } else if (ans < 30 && (v | (1 << ans)) <= k) {
            v |= 1 << ans;
            ++ans;
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */
var longestSubsequence = function (s, k) {
    let ans = 0;
    for (let i = s.length - 1, v = 0; ~i; --i) {
        if (s[i] == '0') {
            ++ans;
        } else if (ans < 30 && (v | (1 << ans)) <= k) {
            v |= 1 << ans;
            ++ans;
        }
    }
    return ans;
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int LongestSubsequence(string s, int k) {
        int ans = 0, v = 0;
        for (int i = s.Length - 1; i >= 0; --i) {
            if (s[i] == '0') {
                ++ans;
            } else if (ans < 30 && (v | 1 << ans) <= k) {
                v |= 1 << ans;
                ++ans;
            }
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn longest_subsequence(s: String, k: i32) -> i32 {
        let mut ans = 0;
        let mut v = 0;
        let s = s.as_bytes();
        for i in (0..s.len()).rev() {
            if s[i] == b'0' {
                ans += 1;
            } else if ans < 30 && (v | (1 << ans)) <= k {
                v |= 1 << ans;
                ans += 1;
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

<p>给你一个二进制字符串&nbsp;<code>s</code>&nbsp;和一个正整数&nbsp;<code>k</code>&nbsp;。</p>

<p>请你返回 <code>s</code>&nbsp;的 <strong>最长</strong>&nbsp;子序列的长度，且该子序列对应的 <strong>二进制</strong>&nbsp;数字小于等于 <code>k</code>&nbsp;。</p>

<p>注意：</p>

<ul>
	<li>子序列可以有 <strong>前导 0</strong>&nbsp;。</li>
	<li>空字符串视为&nbsp;<code>0</code>&nbsp;。</li>
	<li><strong>子序列</strong>&nbsp;是指从一个字符串中删除零个或者多个字符后，不改变顺序得到的剩余字符序列。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>s = "1001010", k = 5
<b>输出：</b>5
<b>解释：</b>s 中小于等于 5 的最长子序列是 "00010" ，对应的十进制数字是 2 。
注意 "00100" 和 "00101" 也是可行的最长子序列，十进制分别对应 4 和 5 。
最长子序列的长度为 5 ，所以返回 5 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>s = "00101001", k = 1
<b>输出：</b>6
<b>解释：</b>"000001" 是 s 中小于等于 1 的最长子序列，对应的十进制数字是 1 。
最长子序列的长度为 6 ，所以返回 6 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s[i]</code> 要么是&nbsp;<code>'0'</code>&nbsp;，要么是&nbsp;<code>'1'</code> 。</li>
	<li><code>1 &lt;= k &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心

最长二进制子序列必然包含原字符串中所有的 $0$，在此基础上，我们从右到左遍历 $s$，若遇到 $1$，判断子序列能否添加 $1$，使得子序列对应的二进制数字 $v \leq k$。

时间复杂度 $O(n)$，其中 $n$ 为字符串 $s$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def longestSubsequence(self, s: str, k: int) -> int:
        ans = v = 0
        for c in s[::-1]:
            if c == "0":
                ans += 1
            elif ans < 30 and (v | 1 << ans) <= k:
                v |= 1 << ans
                ans += 1
        return ans
```

#### Java

```java
class Solution {
    public int longestSubsequence(String s, int k) {
        int ans = 0, v = 0;
        for (int i = s.length() - 1; i >= 0; --i) {
            if (s.charAt(i) == '0') {
                ++ans;
            } else if (ans < 30 && (v | 1 << ans) <= k) {
                v |= 1 << ans;
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
    int longestSubsequence(string s, int k) {
        int ans = 0, v = 0;
        for (int i = s.size() - 1; ~i; --i) {
            if (s[i] == '0') {
                ++ans;
            } else if (ans < 30 && (v | 1 << ans) <= k) {
                v |= 1 << ans;
                ++ans;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func longestSubsequence(s string, k int) (ans int) {
	for i, v := len(s)-1, 0; i >= 0; i-- {
		if s[i] == '0' {
			ans++
		} else if ans < 30 && (v|1<<ans) <= k {
			v |= 1 << ans
			ans++
		}
	}
	return
}
```

#### TypeScript

```ts
function longestSubsequence(s: string, k: number): number {
    let ans = 0;
    for (let i = s.length - 1, v = 0; ~i; --i) {
        if (s[i] == '0') {
            ++ans;
        } else if (ans < 30 && (v | (1 << ans)) <= k) {
            v |= 1 << ans;
            ++ans;
        }
    }
    return ans;
}
```

#### JavaScript

```js
/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */
var longestSubsequence = function (s, k) {
    let ans = 0;
    for (let i = s.length - 1, v = 0; ~i; --i) {
        if (s[i] == '0') {
            ++ans;
        } else if (ans < 30 && (v | (1 << ans)) <= k) {
            v |= 1 << ans;
            ++ans;
        }
    }
    return ans;
};
```

#### C#

```cs
public class Solution {
    public int LongestSubsequence(string s, int k) {
        int ans = 0, v = 0;
        for (int i = s.Length - 1; i >= 0; --i) {
            if (s[i] == '0') {
                ++ans;
            } else if (ans < 30 && (v | 1 << ans) <= k) {
                v |= 1 << ans;
                ++ans;
            }
        }
        return ans;
    }
}
```

#### Rust

```rust
impl Solution {
    pub fn longest_subsequence(s: String, k: i32) -> i32 {
        let mut ans = 0;
        let mut v = 0;
        let s = s.as_bytes();
        for i in (0..s.len()).rev() {
            if s[i] == b'0' {
                ans += 1;
            } else if ans < 30 && (v | (1 << ans)) <= k {
                v |= 1 << ans;
                ans += 1;
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

# [2312. 卖木头块](https://leetcode.cn/problems/selling-pieces-of-wood){#2312}

{{< tabs "2312" >}}

{{% tab "python" %}}
```python
class Solution:
    def sellingWood(self, m: int, n: int, prices: List[List[int]]) -> int:
        d = defaultdict(dict)
        for h, w, p in prices:
            d[h][w] = p
        f = [[0] * (n + 1) for _ in range(m + 1)]
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                f[i][j] = d[i].get(j, 0)
                for k in range(1, i):
                    f[i][j] = max(f[i][j], f[k][j] + f[i - k][j])
                for k in range(1, j):
                    f[i][j] = max(f[i][j], f[i][k] + f[i][j - k])
        return f[m][n]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long sellingWood(int m, int n, int[][] prices) {
        int[][] d = new int[m + 1][n + 1];
        long[][] f = new long[m + 1][n + 1];
        for (int[] p : prices) {
            d[p[0]][p[1]] = p[2];
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                f[i][j] = d[i][j];
                for (int k = 1; k < i; ++k) {
                    f[i][j] = Math.max(f[i][j], f[k][j] + f[i - k][j]);
                }
                for (int k = 1; k < j; ++k) {
                    f[i][j] = Math.max(f[i][j], f[i][k] + f[i][j - k]);
                }
            }
        }
        return f[m][n];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        long long f[m + 1][n + 1];
        int d[m + 1][n + 1];
        memset(f, -1, sizeof(f));
        memset(d, 0, sizeof(d));
        for (auto& p : prices) {
            d[p[0]][p[1]] = p[2];
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                f[i][j] = d[i][j];
                for (int k = 1; k < i; ++k) {
                    f[i][j] = max(f[i][j], f[k][j] + f[i - k][j]);
                }
                for (int k = 1; k < j; ++k) {
                    f[i][j] = max(f[i][j], f[i][k] + f[i][j - k]);
                }
            }
        }
        return f[m][n];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func sellingWood(m int, n int, prices [][]int) int64 {
	d := make([][]int, m+1)
	f := make([][]int64, m+1)
	for i := range d {
		d[i] = make([]int, n+1)
		f[i] = make([]int64, n+1)
	}
	for _, p := range prices {
		d[p[0]][p[1]] = p[2]
	}
	for i := 1; i <= m; i++ {
		for j := 1; j <= n; j++ {
			f[i][j] = int64(d[i][j])
			for k := 1; k < i; k++ {
				f[i][j] = max(f[i][j], f[k][j]+f[i-k][j])
			}
			for k := 1; k < j; k++ {
				f[i][j] = max(f[i][j], f[i][k]+f[i][j-k])
			}
		}
	}
	return f[m][n]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function sellingWood(m: number, n: number, prices: number[][]): number {
    const f: number[][] = Array.from({ length: m + 1 }, () => Array(n + 1).fill(0));
    const d: number[][] = Array.from({ length: m + 1 }, () => Array(n + 1).fill(0));
    for (const [h, w, p] of prices) {
        d[h][w] = p;
    }

    for (let i = 1; i <= m; i++) {
        for (let j = 1; j <= n; j++) {
            f[i][j] = d[i][j];
            for (let k = 1; k < i; k++) {
                f[i][j] = Math.max(f[i][j], f[k][j] + f[i - k][j]);
            }
            for (let k = 1; k < j; k++) {
                f[i][j] = Math.max(f[i][j], f[i][k] + f[i][j - k]);
            }
        }
    }

    return f[m][n];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个整数&nbsp;<code>m</code> 和&nbsp;<code>n</code>&nbsp;，分别表示一块矩形木块的高和宽。同时给你一个二维整数数组&nbsp;<code>prices</code>&nbsp;，其中&nbsp;<code>prices[i] = [h<sub>i</sub>, w<sub>i</sub>, price<sub>i</sub>]</code>&nbsp;表示你可以以&nbsp;<code>price<sub>i</sub></code>&nbsp;元的价格卖一块高为&nbsp;<code>h<sub>i</sub></code>&nbsp;宽为&nbsp;<code>w<sub>i</sub></code>&nbsp;的矩形木块。</p>

<p>每一次操作中，你必须按下述方式之一执行切割操作，以得到两块更小的矩形木块：</p>

<ul>
	<li>沿垂直方向按高度 <strong>完全</strong> 切割木块，或</li>
	<li>沿水平方向按宽度 <strong>完全</strong> 切割木块</li>
</ul>

<p>在将一块木块切成若干小木块后，你可以根据 <code>prices</code>&nbsp;卖木块。你可以卖多块同样尺寸的木块。你不需要将所有小木块都卖出去。你 <strong>不能</strong>&nbsp;旋转切好后木块来交换它的高度值和宽度值。</p>

<p>请你返回切割一块大小为<em>&nbsp;</em><code>m x n</code><em> </em>的木块后，能得到的&nbsp;<strong>最多</strong>&nbsp;钱数。</p>

<p>注意你可以切割木块任意次。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2300-2399/2312.Selling%20Pieces%20of%20Wood/images/ex1.png" style="width: 239px; height: 150px;" /></p>

<pre>
<b>输入：</b>m = 3, n = 5, prices = [[1,4,2],[2,2,7],[2,1,3]]
<b>输出：</b>19
<b>解释：</b>上图展示了一个可行的方案。包括：
- 2 块 2 x 2 的小木块，售出 2 * 7 = 14 元。
- 1 块 2 x 1 的小木块，售出 1 * 3 = 3 元。
- 1 块 1 x 4 的小木块，售出 1 * 2 = 2 元。
总共售出 14 + 3 + 2 = 19 元。
19 元是最多能得到的钱数。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2300-2399/2312.Selling%20Pieces%20of%20Wood/images/ex2new.png" style="width: 250px; height: 175px;" /></p>

<pre>
<b>输入：</b>m = 4, n = 6, prices = [[3,2,10],[1,4,2],[4,1,3]]
<b>输出：</b>32
<b>解释：</b>上图展示了一个可行的方案。包括：
- 3 块 3 x 2 的小木块，售出 3 * 10 = 30 元。
- 1 块 1 x 4 的小木块，售出 1 * 2 = 2 元。
总共售出 30 + 2 = 32 元。
32 元是最多能得到的钱数。
注意我们不能旋转 1 x 4 的木块来得到 4 x 1 的木块。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= m, n &lt;= 200</code></li>
	<li><code>1 &lt;= prices.length &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>prices[i].length == 3</code></li>
	<li><code>1 &lt;= h<sub>i</sub> &lt;= m</code></li>
	<li><code>1 &lt;= w<sub>i</sub> &lt;= n</code></li>
	<li><code>1 &lt;= price<sub>i</sub> &lt;= 10<sup>6</sup></code></li>
	<li>所有&nbsp;<code>(h<sub>i</sub>, w<sub>i</sub>)</code> <strong>互不相同</strong>&nbsp;。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

我们先定义一个二维数组 $d$，其中 $d[i][j]$ 表示高为 $i$，宽为 $j$ 的木块的价格。初始时，我们遍历价格数组 $prices$，将每一块木块 $(h, w, p)$ 的价格 $p$ 存入 $d[h][w]$ 中，其余价格为 $0$。

然后我们设计一个函数 $dfs(h, w)$，表示对一块高为 $h$，宽为 $w$ 的木块切割后能得到的最多钱数。答案就是 $dfs(m, n)$。

函数 $dfs(h, w)$ 的执行过程如下：

-   如果 $(h, w)$ 已经被计算过了，直接返回答案。
-   否则，我们先初始化答案为 $d[h][w]$，然后枚举切割的位置，分别计算切割后的两块木块能得到的最多钱数，取最大值即可。

时间复杂度 $(m \times n \times (m + n) + p)$，空间复杂度 $O(m \times n)$。其中 $p$ 表示价格数组的长度，而 $m$ 和 $n$ 分别表示木块的高和宽。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def sellingWood(self, m: int, n: int, prices: List[List[int]]) -> int:
        @cache
        def dfs(h: int, w: int) -> int:
            ans = d[h].get(w, 0)
            for i in range(1, h // 2 + 1):
                ans = max(ans, dfs(i, w) + dfs(h - i, w))
            for i in range(1, w // 2 + 1):
                ans = max(ans, dfs(h, i) + dfs(h, w - i))
            return ans

        d = defaultdict(dict)
        for h, w, p in prices:
            d[h][w] = p
        return dfs(m, n)
```

#### Java

```java
class Solution {
    private int[][] d;
    private Long[][] f;

    public long sellingWood(int m, int n, int[][] prices) {
        d = new int[m + 1][n + 1];
        f = new Long[m + 1][n + 1];
        for (var p : prices) {
            d[p[0]][p[1]] = p[2];
        }
        return dfs(m, n);
    }

    private long dfs(int h, int w) {
        if (f[h][w] != null) {
            return f[h][w];
        }
        long ans = d[h][w];
        for (int i = 1; i < h / 2 + 1; ++i) {
            ans = Math.max(ans, dfs(i, w) + dfs(h - i, w));
        }
        for (int i = 1; i < w / 2 + 1; ++i) {
            ans = Math.max(ans, dfs(h, i) + dfs(h, w - i));
        }
        return f[h][w] = ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        using ll = long long;
        ll f[m + 1][n + 1];
        int d[m + 1][n + 1];
        memset(f, -1, sizeof(f));
        memset(d, 0, sizeof(d));
        for (auto& p : prices) {
            d[p[0]][p[1]] = p[2];
        }
        function<ll(int, int)> dfs = [&](int h, int w) -> ll {
            if (f[h][w] != -1) {
                return f[h][w];
            }
            ll ans = d[h][w];
            for (int i = 1; i < h / 2 + 1; ++i) {
                ans = max(ans, dfs(i, w) + dfs(h - i, w));
            }
            for (int i = 1; i < w / 2 + 1; ++i) {
                ans = max(ans, dfs(h, i) + dfs(h, w - i));
            }
            return f[h][w] = ans;
        };
        return dfs(m, n);
    }
};
```

#### Go

```go
func sellingWood(m int, n int, prices [][]int) int64 {
	f := make([][]int64, m+1)
	d := make([][]int, m+1)
	for i := range f {
		f[i] = make([]int64, n+1)
		for j := range f[i] {
			f[i][j] = -1
		}
		d[i] = make([]int, n+1)
	}
	for _, p := range prices {
		d[p[0]][p[1]] = p[2]
	}
	var dfs func(int, int) int64
	dfs = func(h, w int) int64 {
		if f[h][w] != -1 {
			return f[h][w]
		}
		ans := int64(d[h][w])
		for i := 1; i < h/2+1; i++ {
			ans = max(ans, dfs(i, w)+dfs(h-i, w))
		}
		for i := 1; i < w/2+1; i++ {
			ans = max(ans, dfs(h, i)+dfs(h, w-i))
		}
		f[h][w] = ans
		return ans
	}
	return dfs(m, n)
}
```

#### TypeScript

```ts
function sellingWood(m: number, n: number, prices: number[][]): number {
    const f: number[][] = Array.from({ length: m + 1 }, () => Array(n + 1).fill(-1));
    const d: number[][] = Array.from({ length: m + 1 }, () => Array(n + 1).fill(0));
    for (const [h, w, p] of prices) {
        d[h][w] = p;
    }

    const dfs = (h: number, w: number): number => {
        if (f[h][w] !== -1) {
            return f[h][w];
        }

        let ans = d[h][w];
        for (let i = 1; i <= Math.floor(h / 2); i++) {
            ans = Math.max(ans, dfs(i, w) + dfs(h - i, w));
        }
        for (let i = 1; i <= Math.floor(w / 2); i++) {
            ans = Math.max(ans, dfs(h, i) + dfs(h, w - i));
        }
        return (f[h][w] = ans);
    };

    return dfs(m, n);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：动态规划

我们可以将方法一的记忆化搜索转换为动态规划。

与方法一类似，我们定义一个二维数组 $d$，其中 $d[i][j]$ 表示高为 $i$，宽为 $j$ 的木块的价格。初始时，我们遍历价格数组 $prices$，将每一块木块 $(h, w, p)$ 的价格 $p$ 存入 $d[h][w]$ 中，其余价格为 $0$。

然后，我们定义另一个二维数组 $f$，其中 $f[i][j]$ 表示对一块高为 $i$，宽为 $j$ 的木块切割后能得到的最多钱数。答案就是 $f[m][n]$。

考虑 $f[i][j]$ 如何转移，初始时 $f[i][j] = d[i][j]$。我们枚举切割的位置，分别计算切割后的两块木块能得到的最多钱数，取最大值即可。

时间复杂度 $O(m \times n \times (m + n) + p)$，空间复杂度 $O(m \times n)$。其中 $p$ 表示价格数组的长度，而 $m$ 和 $n$ 分别表示木块的高和宽。

相似题目：

-   [1444. 切披萨的方案数](https://github.com/doocs/leetcode/blob/main/solution/1400-1499/1444.Number%20of%20Ways%20of%20Cutting%20a%20Pizza/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def sellingWood(self, m: int, n: int, prices: List[List[int]]) -> int:
        d = defaultdict(dict)
        for h, w, p in prices:
            d[h][w] = p
        f = [[0] * (n + 1) for _ in range(m + 1)]
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                f[i][j] = d[i].get(j, 0)
                for k in range(1, i):
                    f[i][j] = max(f[i][j], f[k][j] + f[i - k][j])
                for k in range(1, j):
                    f[i][j] = max(f[i][j], f[i][k] + f[i][j - k])
        return f[m][n]
```

#### Java

```java
class Solution {
    public long sellingWood(int m, int n, int[][] prices) {
        int[][] d = new int[m + 1][n + 1];
        long[][] f = new long[m + 1][n + 1];
        for (int[] p : prices) {
            d[p[0]][p[1]] = p[2];
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                f[i][j] = d[i][j];
                for (int k = 1; k < i; ++k) {
                    f[i][j] = Math.max(f[i][j], f[k][j] + f[i - k][j]);
                }
                for (int k = 1; k < j; ++k) {
                    f[i][j] = Math.max(f[i][j], f[i][k] + f[i][j - k]);
                }
            }
        }
        return f[m][n];
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        long long f[m + 1][n + 1];
        int d[m + 1][n + 1];
        memset(f, -1, sizeof(f));
        memset(d, 0, sizeof(d));
        for (auto& p : prices) {
            d[p[0]][p[1]] = p[2];
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                f[i][j] = d[i][j];
                for (int k = 1; k < i; ++k) {
                    f[i][j] = max(f[i][j], f[k][j] + f[i - k][j]);
                }
                for (int k = 1; k < j; ++k) {
                    f[i][j] = max(f[i][j], f[i][k] + f[i][j - k]);
                }
            }
        }
        return f[m][n];
    }
};
```

#### Go

```go
func sellingWood(m int, n int, prices [][]int) int64 {
	d := make([][]int, m+1)
	f := make([][]int64, m+1)
	for i := range d {
		d[i] = make([]int, n+1)
		f[i] = make([]int64, n+1)
	}
	for _, p := range prices {
		d[p[0]][p[1]] = p[2]
	}
	for i := 1; i <= m; i++ {
		for j := 1; j <= n; j++ {
			f[i][j] = int64(d[i][j])
			for k := 1; k < i; k++ {
				f[i][j] = max(f[i][j], f[k][j]+f[i-k][j])
			}
			for k := 1; k < j; k++ {
				f[i][j] = max(f[i][j], f[i][k]+f[i][j-k])
			}
		}
	}
	return f[m][n]
}
```

#### TypeScript

```ts
function sellingWood(m: number, n: number, prices: number[][]): number {
    const f: number[][] = Array.from({ length: m + 1 }, () => Array(n + 1).fill(0));
    const d: number[][] = Array.from({ length: m + 1 }, () => Array(n + 1).fill(0));
    for (const [h, w, p] of prices) {
        d[h][w] = p;
    }

    for (let i = 1; i <= m; i++) {
        for (let j = 1; j <= n; j++) {
            f[i][j] = d[i][j];
            for (let k = 1; k < i; k++) {
                f[i][j] = Math.max(f[i][j], f[k][j] + f[i - k][j]);
            }
            for (let k = 1; k < j; k++) {
                f[i][j] = Math.max(f[i][j], f[i][k] + f[i][j - k]);
            }
        }
    }

    return f[m][n];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2313. 二叉树中得到结果所需的最少翻转次数 🔒](https://leetcode.cn/problems/minimum-flips-in-binary-tree-to-get-result){#2313}

{{< tabs "2313" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minimumFlips(self, root: Optional[TreeNode], result: bool) -> int:
        def dfs(root: Optional[TreeNode]) -> (int, int):
            if root is None:
                return inf, inf
            x = root.val
            if x in (0, 1):
                return x, x ^ 1
            l, r = dfs(root.left), dfs(root.right)
            if x == 2:
                return l[0] + r[0], min(l[0] + r[1], l[1] + r[0], l[1] + r[1])
            if x == 3:
                return min(l[0] + r[0], l[0] + r[1], l[1] + r[0]), l[1] + r[1]
            if x == 4:
                return min(l[0] + r[0], l[1] + r[1]), min(l[0] + r[1], l[1] + r[0])
            return min(l[1], r[1]), min(l[0], r[0])

        return dfs(root)[int(result)]
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
    public int minimumFlips(TreeNode root, boolean result) {
        return dfs(root)[result ? 1 : 0];
    }

    private int[] dfs(TreeNode root) {
        if (root == null) {
            return new int[] {1 << 30, 1 << 30};
        }
        int x = root.val;
        if (x < 2) {
            return new int[] {x, x ^ 1};
        }
        var l = dfs(root.left);
        var r = dfs(root.right);
        int a = 0, b = 0;
        if (x == 2) {
            a = l[0] + r[0];
            b = Math.min(l[0] + r[1], Math.min(l[1] + r[0], l[1] + r[1]));
        } else if (x == 3) {
            a = Math.min(l[0] + r[0], Math.min(l[0] + r[1], l[1] + r[0]));
            b = l[1] + r[1];
        } else if (x == 4) {
            a = Math.min(l[0] + r[0], l[1] + r[1]);
            b = Math.min(l[0] + r[1], l[1] + r[0]);
        } else {
            a = Math.min(l[1], r[1]);
            b = Math.min(l[0], r[0]);
        }
        return new int[] {a, b};
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
    int minimumFlips(TreeNode* root, bool result) {
        function<pair<int, int>(TreeNode*)> dfs = [&](TreeNode* root) -> pair<int, int> {
            if (!root) {
                return {1 << 30, 1 << 30};
            }
            int x = root->val;
            if (x < 2) {
                return {x, x ^ 1};
            }
            auto [l0, l1] = dfs(root->left);
            auto [r0, r1] = dfs(root->right);
            int a = 0, b = 0;
            if (x == 2) {
                a = l0 + r0;
                b = min({l0 + r1, l1 + r0, l1 + r1});
            } else if (x == 3) {
                a = min({l0 + r0, l0 + r1, l1 + r0});
                b = l1 + r1;
            } else if (x == 4) {
                a = min(l0 + r0, l1 + r1);
                b = min(l0 + r1, l1 + r0);
            } else {
                a = min(l1, r1);
                b = min(l0, r0);
            }
            return {a, b};
        };
        auto [a, b] = dfs(root);
        return result ? b : a;
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
func minimumFlips(root *TreeNode, result bool) int {
	var dfs func(*TreeNode) (int, int)
	dfs = func(root *TreeNode) (int, int) {
		if root == nil {
			return 1 << 30, 1 << 30
		}
		x := root.Val
		if x < 2 {
			return x, x ^ 1
		}
		l0, l1 := dfs(root.Left)
		r0, r1 := dfs(root.Right)
		var a, b int
		if x == 2 {
			a = l0 + r0
			b = min(l0+r1, min(l1+r0, l1+r1))
		} else if x == 3 {
			a = min(l0+r0, min(l0+r1, l1+r0))
			b = l1 + r1
		} else if x == 4 {
			a = min(l0+r0, l1+r1)
			b = min(l0+r1, l1+r0)
		} else {
			a = min(l1, r1)
			b = min(l0, r0)
		}
		return a, b
	}
	a, b := dfs(root)
	if result {
		return b
	}
	return a
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

function minimumFlips(root: TreeNode | null, result: boolean): number {
    const dfs = (root: TreeNode | null): [number, number] => {
        if (!root) {
            return [1 << 30, 1 << 30];
        }
        const x = root.val;
        if (x < 2) {
            return [x, x ^ 1];
        }
        const [l0, l1] = dfs(root.left);
        const [r0, r1] = dfs(root.right);
        if (x === 2) {
            return [l0 + r0, Math.min(l0 + r1, l1 + r0, l1 + r1)];
        }
        if (x === 3) {
            return [Math.min(l0 + r0, l0 + r1, l1 + r0), l1 + r1];
        }
        if (x === 4) {
            return [Math.min(l0 + r0, l1 + r1), Math.min(l0 + r1, l1 + r0)];
        }
        return [Math.min(l1, r1), Math.min(l0, r0)];
    };
    return dfs(root)[result ? 1 : 0];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定<strong>二叉树</strong>的根 <code>root</code>，具有以下属性:</p>

<ul>
	<li><strong>叶节点&nbsp;</strong>的值为 <code>0</code> 或 <code>1</code>，分别表示 <code>false</code> 和 <code>true</code>。</li>
	<li><strong>非叶节点</strong>的值为 <code>2</code>、<code>3</code>、<code>4</code>、<code>5</code>，分别表示布尔运算&nbsp;<code>OR</code>,&nbsp;<code>AND</code>,&nbsp;<code>XOR</code>,&nbsp;<code>NOT</code>。</li>
</ul>

<p>您还将得到一个布尔型&nbsp;<code>result</code>，这是 <code>root</code>&nbsp;节点的期望&nbsp;<strong>评价</strong><strong>&nbsp;</strong>结果。</p>

<p data-group="1-1">对节点的评价计算如下:</p>

<ul>
	<li>如果节点是叶节点，则评价是节点的&nbsp;<strong>值</strong>，即 <code>true</code> 或&nbsp;<code>false</code>.</li>
	<li>否则, 将其值的布尔运算应用于子节点的&nbsp;<strong>评价</strong>，该节点的&nbsp;<strong>评价&nbsp;</strong>即为布尔运算后的结果。</li>
</ul>

<p>在一个操作中，您可以&nbsp;<strong>翻转&nbsp;</strong>一个叶节点，这将导致一个 <code>false</code>&nbsp;节点变为 <code>true</code>&nbsp;节点，一个 <code>true</code>&nbsp;节点变为 <code>false</code>&nbsp;节点。</p>

<p>返回<em>需要执行的最小操作数，以使 </em><code>root</code><em>&nbsp;的</em><em>评价得到&nbsp;</em><code>result</code>。可以证明，总有办法达到 <code>result</code>。</p>

<p data-group="1-1"><strong>叶节点&nbsp;</strong>是没有子节点的节点。</p>

<p>注意: <code>NOT</code> 节点只有左孩子或只有右孩子，但其他非叶节点同时拥有左孩子和右孩子。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1:</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2300-2399/2313.Minimum%20Flips%20in%20Binary%20Tree%20to%20Get%20Result/images/operationstree.png" style="width: 500px; height: 179px;" />
<pre>
<strong>输入:</strong> root = [3,5,4,2,null,1,1,1,0], result = true
<strong>输出:</strong> 2
<strong>解释:</strong>
可以证明，至少需要翻转 2 个节点才能使树的 root 评价为 true。上面的图显示了实现这一目标的一种方法。
</pre>

<p><strong class="example">示例 2:</strong></p>

<pre>
<strong>输入:</strong> root = [0], result = false
<strong>输出:</strong> 0
<strong>解释:</strong>
树的 root 的评价已经为 false，所以 0 个节点必须翻转。
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li>树中的节点数在 <code>[1, 10<sup>5</sup>]</code>&nbsp;范围内。</li>
	<li><code>0 &lt;= Node.val &lt;= 5</code></li>
	<li><code>OR</code>, <code>AND</code>, <code>XOR</code>&nbsp;节点有&nbsp;<code>2</code> 个子节点。</li>
	<li><code>NOT</code> 只有一个&nbsp;<code>1</code> 子节点。</li>
	<li>叶节点的值为 <code>0</code> 或&nbsp;<code>1</code>.</li>
	<li>非叶节点的值为<code>2</code>, <code>3</code>, <code>4</code>,&nbsp;<code>5</code>.</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：树形 DP + 分情况讨论

我们定义一个函数 $dfs(root)$，它的返回值是一个长度为 $2$ 的数组，其中第一个表示将 $root$ 节点的值变成 `false` 所需要的最少翻转次数，第二个表示将 $root$ 节点的值变成 `true` 所需要的最少翻转次数。那么答案为 $dfs(root)[result]$。

函数 $dfs(root)$ 的实现如下：

如果 $root$ 为空，那么返回 $[+\infty, +\infty]$。

否则，我们记 $root$ 的值为 $x$，左子树的返回值为 $l$，右子树的返回值为 $r$，然后分情况讨论：

-   如果 $x \in \{0, 1\}$，那么返回 $[x, x \oplus 1]$。
-   如果 $x = 2$，即布尔运算符是 `OR`，为了使 $root$ 的值为 `false`，我们需要将左右子树的值都变成 `false`，因此返回值的第一个元素为 $l[0] + r[0]$；为了使 $root$ 的值为 `true`，我们需要将左右子树的值中至少有一个变成 `true`，因此返回值的第二个元素为 $\min(l[0] + r[1], l[1] + r[0], l[1] + r[1])$。
-   如果 $x = 3$，即布尔运算符是 `AND`，为了使 $root$ 的值为 `false`，我们需要将左右子树的值中至少有一个变成 `false`，因此返回值的第一个元素为 $\min(l[0] + r[0], l[0] + r[1], l[1] + r[0])$；为了使 $root$ 的值为 `true`，我们需要将左右子树的值都变成 `true`，因此返回值的第二个元素为 $l[1] + r[1]$。
-   如果 $x = 4$，即布尔运算符是 `XOR`，为了使 $root$ 的值为 `false`，我们需要将左右子树的值同为 `false` 或同为 `true`，因此返回值的第一个元素为 $\min(l[0] + r[0], l[1] + r[1])$；为了使 $root$ 的值为 `true`，我们需要将左右子树的值不同，因此返回值的第二个元素为 $\min(l[0] + r[1], l[1] + r[0])$。
-   如果 $x = 5$，即布尔运算符是 `NOT`，为了使 $root$ 的值为 `false`，我们需要将左右子树的值中至少有一个变成 `true`，因此返回值的第一个元素为 $\min(l[1], r[1])$；为了使 $root$ 的值为 `true`，我们需要将左右子树的值中至少有一个变成 `false`，因此返回值的第二个元素为 $\min(l[0], r[0])$。

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
    def minimumFlips(self, root: Optional[TreeNode], result: bool) -> int:
        def dfs(root: Optional[TreeNode]) -> (int, int):
            if root is None:
                return inf, inf
            x = root.val
            if x in (0, 1):
                return x, x ^ 1
            l, r = dfs(root.left), dfs(root.right)
            if x == 2:
                return l[0] + r[0], min(l[0] + r[1], l[1] + r[0], l[1] + r[1])
            if x == 3:
                return min(l[0] + r[0], l[0] + r[1], l[1] + r[0]), l[1] + r[1]
            if x == 4:
                return min(l[0] + r[0], l[1] + r[1]), min(l[0] + r[1], l[1] + r[0])
            return min(l[1], r[1]), min(l[0], r[0])

        return dfs(root)[int(result)]
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
    public int minimumFlips(TreeNode root, boolean result) {
        return dfs(root)[result ? 1 : 0];
    }

    private int[] dfs(TreeNode root) {
        if (root == null) {
            return new int[] {1 << 30, 1 << 30};
        }
        int x = root.val;
        if (x < 2) {
            return new int[] {x, x ^ 1};
        }
        var l = dfs(root.left);
        var r = dfs(root.right);
        int a = 0, b = 0;
        if (x == 2) {
            a = l[0] + r[0];
            b = Math.min(l[0] + r[1], Math.min(l[1] + r[0], l[1] + r[1]));
        } else if (x == 3) {
            a = Math.min(l[0] + r[0], Math.min(l[0] + r[1], l[1] + r[0]));
            b = l[1] + r[1];
        } else if (x == 4) {
            a = Math.min(l[0] + r[0], l[1] + r[1]);
            b = Math.min(l[0] + r[1], l[1] + r[0]);
        } else {
            a = Math.min(l[1], r[1]);
            b = Math.min(l[0], r[0]);
        }
        return new int[] {a, b};
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
    int minimumFlips(TreeNode* root, bool result) {
        function<pair<int, int>(TreeNode*)> dfs = [&](TreeNode* root) -> pair<int, int> {
            if (!root) {
                return {1 << 30, 1 << 30};
            }
            int x = root->val;
            if (x < 2) {
                return {x, x ^ 1};
            }
            auto [l0, l1] = dfs(root->left);
            auto [r0, r1] = dfs(root->right);
            int a = 0, b = 0;
            if (x == 2) {
                a = l0 + r0;
                b = min({l0 + r1, l1 + r0, l1 + r1});
            } else if (x == 3) {
                a = min({l0 + r0, l0 + r1, l1 + r0});
                b = l1 + r1;
            } else if (x == 4) {
                a = min(l0 + r0, l1 + r1);
                b = min(l0 + r1, l1 + r0);
            } else {
                a = min(l1, r1);
                b = min(l0, r0);
            }
            return {a, b};
        };
        auto [a, b] = dfs(root);
        return result ? b : a;
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
func minimumFlips(root *TreeNode, result bool) int {
	var dfs func(*TreeNode) (int, int)
	dfs = func(root *TreeNode) (int, int) {
		if root == nil {
			return 1 << 30, 1 << 30
		}
		x := root.Val
		if x < 2 {
			return x, x ^ 1
		}
		l0, l1 := dfs(root.Left)
		r0, r1 := dfs(root.Right)
		var a, b int
		if x == 2 {
			a = l0 + r0
			b = min(l0+r1, min(l1+r0, l1+r1))
		} else if x == 3 {
			a = min(l0+r0, min(l0+r1, l1+r0))
			b = l1 + r1
		} else if x == 4 {
			a = min(l0+r0, l1+r1)
			b = min(l0+r1, l1+r0)
		} else {
			a = min(l1, r1)
			b = min(l0, r0)
		}
		return a, b
	}
	a, b := dfs(root)
	if result {
		return b
	}
	return a
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

function minimumFlips(root: TreeNode | null, result: boolean): number {
    const dfs = (root: TreeNode | null): [number, number] => {
        if (!root) {
            return [1 << 30, 1 << 30];
        }
        const x = root.val;
        if (x < 2) {
            return [x, x ^ 1];
        }
        const [l0, l1] = dfs(root.left);
        const [r0, r1] = dfs(root.right);
        if (x === 2) {
            return [l0 + r0, Math.min(l0 + r1, l1 + r0, l1 + r1)];
        }
        if (x === 3) {
            return [Math.min(l0 + r0, l0 + r1, l1 + r0), l1 + r1];
        }
        if (x === 4) {
            return [Math.min(l0 + r0, l1 + r1), Math.min(l0 + r1, l1 + r0)];
        }
        return [Math.min(l1, r1), Math.min(l0, r0)];
    };
    return dfs(root)[result ? 1 : 0];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2314. 每个城市最高气温的第一天 🔒](https://leetcode.cn/problems/the-first-day-of-the-maximum-recorded-degree-in-each-city){#2314}

{{< tabs "2314" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            *,
            RANK() OVER (
                PARTITION BY city_id
                ORDER BY degree DESC, day
            ) AS rk
        FROM Weather
    )
SELECT city_id, day, degree
FROM T
WHERE rk = 1
ORDER BY 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表: <code>Weather</code></p>

<pre>
+-------------+------+
| Column Name | Type |
+-------------+------+
| city_id     | int  |
| day         | date |
| degree      | int  |
+-------------+------+
(city_id, day) 是该表的主键（具有唯一值的列的组合）。
该表中的每一行都包含某一天某个城市的天气程度。
所有的学位都是在 2022 年获得的。
</pre>

<p>&nbsp;</p>

<p>编写解决方案，找出每个城市中有最高温度记录的日子。如果同一城市多次记录最高气温，则返回其中最早的一天。</p>

<p>返回按 <code>city_id</code> <strong>升序排序&nbsp;</strong>的结果表。</p>

<p>查询结果格式示例如下。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1:</strong></p>

<pre>
<strong>输入:</strong> 
Weather 表:
+---------+------------+--------+
| city_id | day        | degree |
+---------+------------+--------+
| 1       | 2022-01-07 | -12    |
| 1       | 2022-03-07 | 5      |
| 1       | 2022-07-07 | 24     |
| 2       | 2022-08-07 | 37     |
| 2       | 2022-08-17 | 37     |
| 3       | 2022-02-07 | -7     |
| 3       | 2022-12-07 | -6     |
+---------+------------+--------+
<strong>输出:</strong> 
+---------+------------+--------+
| city_id | day        | degree |
+---------+------------+--------+
| 1       | 2022-07-07 | 24     |
| 2       | 2022-08-07 | 37     |
| 3       | 2022-12-07 | -6     |
+---------+------------+--------+
<strong>解释:</strong> 
城市 1 的最高气温出现在 2022-07-07，为24度。
城市 2 的最高气温出现在 2022-08-07 和 2022-08-17，为37度。我们选择较早的日期 (2022-08-07)。
城市 3 的最高气温记录在 2022-12-07 年，为-6 度。
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
            *,
            RANK() OVER (
                PARTITION BY city_id
                ORDER BY degree DESC, day
            ) AS rk
        FROM Weather
    )
SELECT city_id, day, degree
FROM T
WHERE rk = 1
ORDER BY 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2315. 统计星号](https://leetcode.cn/problems/count-asterisks){#2315}

{{< tabs "2315" >}}

{{% tab "python" %}}
```python
class Solution:
    def countAsterisks(self, s: str) -> int:
        ans, ok = 0, 1
        for c in s:
            if c == "*":
                ans += ok
            elif c == "|":
                ok ^= 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countAsterisks(String s) {
        int ans = 0;
        for (int i = 0, ok = 1; i < s.length(); ++i) {
            char c = s.charAt(i);
            if (c == '*') {
                ans += ok;
            } else if (c == '|') {
                ok ^= 1;
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
    int countAsterisks(string s) {
        int ans = 0, ok = 1;
        for (char& c : s) {
            if (c == '*') {
                ans += ok;
            } else if (c == '|') {
                ok ^= 1;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countAsterisks(s string) (ans int) {
	ok := 1
	for _, c := range s {
		if c == '*' {
			ans += ok
		} else if c == '|' {
			ok ^= 1
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countAsterisks(s: string): number {
    let ans = 0;
    let ok = 1;
    for (const c of s) {
        if (c === '*') {
            ans += ok;
        } else if (c === '|') {
            ok ^= 1;
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn count_asterisks(s: String) -> i32 {
        let mut ans = 0;
        let mut ok = 1;
        for &c in s.as_bytes() {
            if c == b'*' {
                ans += ok;
            } else if c == b'|' {
                ok ^= 1;
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
    public int CountAsterisks(string s) {
        int ans = 0, ok = 1;
        foreach (char c in s) {
            if (c == '*') {
                ans += ok;
            } else if (c == '|') {
                ok ^= 1;
            }
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
int countAsterisks(char* s) {
    int ans = 0;
    int ok = 1;
    for (int i = 0; s[i]; i++) {
        if (s[i] == '*') {
            ans += ok;
        } else if (s[i] == '|') {
            ok ^= 1;
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

<p>给你一个字符串&nbsp;<code>s</code>&nbsp;，每&nbsp;<strong>两个</strong>&nbsp;连续竖线&nbsp;<code>'|'</code>&nbsp;为 <strong>一对</strong>&nbsp;。换言之，第一个和第二个&nbsp;<code>'|'</code>&nbsp;为一对，第三个和第四个&nbsp;<code>'|'</code>&nbsp;为一对，以此类推。</p>

<p>请你返回 <strong>不在</strong> 竖线对之间，<code>s</code>&nbsp;中&nbsp;<code>'*'</code>&nbsp;的数目。</p>

<p><strong>注意</strong>，每个竖线&nbsp;<code>'|'</code>&nbsp;都会 <strong>恰好</strong>&nbsp;属于一个对。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>s = "l|*e*et|c**o|*de|"
<b>输出：</b>2
<b>解释：</b>不在竖线对之间的字符加粗加斜体后，得到字符串："<strong><em>l</em></strong>|*e*et|<strong><em>c**o</em></strong>|*de|" 。
第一和第二条竖线 '|' 之间的字符不计入答案。
同时，第三条和第四条竖线 '|' 之间的字符也不计入答案。
不在竖线对之间总共有 2 个星号，所以我们返回 2 。</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>s = "iamprogrammer"
<b>输出：</b>0
<b>解释：</b>在这个例子中，s 中没有星号。所以返回 0 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>s = "yo|uar|e**|b|e***au|tifu|l"
<b>输出：</b>5
<b>解释：</b>需要考虑的字符加粗加斜体后："<strong><em>yo</em></strong>|uar|<strong><em>e**</em></strong>|b|<strong><em>e***au</em></strong>|tifu|<strong><em>l</em></strong>" 。不在竖线对之间总共有 5 个星号。所以我们返回 5 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s</code>&nbsp;只包含小写英文字母，竖线&nbsp;<code>'|'</code>&nbsp;和星号&nbsp;<code>'*'</code>&nbsp;。</li>
	<li><code>s</code>&nbsp;包含 <strong>偶数</strong>&nbsp;个竖线&nbsp;<code>'|'</code> 。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们定义一个整型变量 $\textit{ok}$，表示遇到 `*` 时是否能计数，初始时 $\textit{ok}=1$，表示可以计数。

遍历字符串 $s$，如果遇到 `*`，则根据 $\textit{ok}$ 的值决定是否计数，如果遇到 `|`，则 $\textit{ok}$ 的值取反。

最后返回计数的结果。

时间复杂度 $O(n)$，其中 $n$ 为字符串 $s$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countAsterisks(self, s: str) -> int:
        ans, ok = 0, 1
        for c in s:
            if c == "*":
                ans += ok
            elif c == "|":
                ok ^= 1
        return ans
```

#### Java

```java
class Solution {
    public int countAsterisks(String s) {
        int ans = 0;
        for (int i = 0, ok = 1; i < s.length(); ++i) {
            char c = s.charAt(i);
            if (c == '*') {
                ans += ok;
            } else if (c == '|') {
                ok ^= 1;
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
    int countAsterisks(string s) {
        int ans = 0, ok = 1;
        for (char& c : s) {
            if (c == '*') {
                ans += ok;
            } else if (c == '|') {
                ok ^= 1;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func countAsterisks(s string) (ans int) {
	ok := 1
	for _, c := range s {
		if c == '*' {
			ans += ok
		} else if c == '|' {
			ok ^= 1
		}
	}
	return
}
```

#### TypeScript

```ts
function countAsterisks(s: string): number {
    let ans = 0;
    let ok = 1;
    for (const c of s) {
        if (c === '*') {
            ans += ok;
        } else if (c === '|') {
            ok ^= 1;
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn count_asterisks(s: String) -> i32 {
        let mut ans = 0;
        let mut ok = 1;
        for &c in s.as_bytes() {
            if c == b'*' {
                ans += ok;
            } else if c == b'|' {
                ok ^= 1;
            }
        }
        ans
    }
}
```

#### C#

```cs
public class Solution {
    public int CountAsterisks(string s) {
        int ans = 0, ok = 1;
        foreach (char c in s) {
            if (c == '*') {
                ans += ok;
            } else if (c == '|') {
                ok ^= 1;
            }
        }
        return ans;
    }
}
```

#### C

```c
int countAsterisks(char* s) {
    int ans = 0;
    int ok = 1;
    for (int i = 0; s[i]; i++) {
        if (s[i] == '*') {
            ans += ok;
        } else if (s[i] == '|') {
            ok ^= 1;
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

# [2316. 统计无向图中无法互相到达点对数](https://leetcode.cn/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph){#2316}

{{< tabs "2316" >}}

{{% tab "python" %}}
```python
class Solution:
    def countPairs(self, n: int, edges: List[List[int]]) -> int:
        def dfs(i: int) -> int:
            if vis[i]:
                return 0
            vis[i] = True
            return 1 + sum(dfs(j) for j in g[i])

        g = [[] for _ in range(n)]
        for a, b in edges:
            g[a].append(b)
            g[b].append(a)
        vis = [False] * n
        ans = s = 0
        for i in range(n):
            t = dfs(i)
            ans += s * t
            s += t
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private List<Integer>[] g;
    private boolean[] vis;

    public long countPairs(int n, int[][] edges) {
        g = new List[n];
        vis = new boolean[n];
        Arrays.setAll(g, i -> new ArrayList<>());
        for (var e : edges) {
            int a = e[0], b = e[1];
            g[a].add(b);
            g[b].add(a);
        }
        long ans = 0, s = 0;
        for (int i = 0; i < n; ++i) {
            int t = dfs(i);
            ans += s * t;
            s += t;
        }
        return ans;
    }

    private int dfs(int i) {
        if (vis[i]) {
            return 0;
        }
        vis[i] = true;
        int cnt = 1;
        for (int j : g[i]) {
            cnt += dfs(j);
        }
        return cnt;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> g[n];
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        bool vis[n];
        memset(vis, 0, sizeof(vis));
        function<int(int)> dfs = [&](int i) {
            if (vis[i]) {
                return 0;
            }
            vis[i] = true;
            int cnt = 1;
            for (int j : g[i]) {
                cnt += dfs(j);
            }
            return cnt;
        };
        long long ans = 0, s = 0;
        for (int i = 0; i < n; ++i) {
            int t = dfs(i);
            ans += s * t;
            s += t;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countPairs(n int, edges [][]int) (ans int64) {
	g := make([][]int, n)
	for _, e := range edges {
		a, b := e[0], e[1]
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}
	vis := make([]bool, n)
	var dfs func(int) int
	dfs = func(i int) int {
		if vis[i] {
			return 0
		}
		vis[i] = true
		cnt := 1
		for _, j := range g[i] {
			cnt += dfs(j)
		}
		return cnt
	}
	var s int64
	for i := 0; i < n; i++ {
		t := int64(dfs(i))
		ans += s * t
		s += t
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countPairs(n: number, edges: number[][]): number {
    const g: number[][] = Array.from({ length: n }, () => []);
    for (const [a, b] of edges) {
        g[a].push(b);
        g[b].push(a);
    }
    const vis: boolean[] = Array(n).fill(false);
    const dfs = (i: number): number => {
        if (vis[i]) {
            return 0;
        }
        vis[i] = true;
        let cnt = 1;
        for (const j of g[i]) {
            cnt += dfs(j);
        }
        return cnt;
    };
    let [ans, s] = [0, 0];
    for (let i = 0; i < n; ++i) {
        const t = dfs(i);
        ans += s * t;
        s += t;
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn count_pairs(n: i32, edges: Vec<Vec<i32>>) -> i64 {
        let n = n as usize;
        let mut g = vec![vec![]; n];
        let mut vis = vec![false; n];
        for e in edges {
            let u = e[0] as usize;
            let v = e[1] as usize;
            g[u].push(v);
            g[v].push(u);
        }

        fn dfs(g: &Vec<Vec<usize>>, vis: &mut Vec<bool>, u: usize) -> i64 {
            if vis[u] {
                return 0;
            }
            vis[u] = true;
            let mut cnt = 1;
            for &v in &g[u] {
                cnt += dfs(g, vis, v);
            }
            cnt
        }

        let mut ans = 0;
        let mut s = 0;
        for u in 0..n {
            let t = dfs(&g, &mut vis, u);
            ans += t * s;
            s += t;
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

<p>给你一个整数&nbsp;<code>n</code>&nbsp;，表示一张<strong>&nbsp;无向图</strong>&nbsp;中有 <code>n</code>&nbsp;个节点，编号为&nbsp;<code>0</code>&nbsp;到&nbsp;<code>n - 1</code>&nbsp;。同时给你一个二维整数数组&nbsp;<code>edges</code>&nbsp;，其中&nbsp;<code>edges[i] = [a<sub>i</sub>, b<sub>i</sub>]</code>&nbsp;表示节点&nbsp;<code>a<sub>i</sub></code> 和&nbsp;<code>b<sub>i</sub></code>&nbsp;之间有一条&nbsp;<strong>无向</strong>&nbsp;边。</p>

<p>请你返回 <strong>无法互相到达</strong>&nbsp;的不同 <strong>点对数目</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2300-2399/2316.Count%20Unreachable%20Pairs%20of%20Nodes%20in%20an%20Undirected%20Graph/images/tc-3.png" style="width: 267px; height: 169px;"></p>

<pre><b>输入：</b>n = 3, edges = [[0,1],[0,2],[1,2]]
<b>输出：</b>0
<b>解释：</b>所有点都能互相到达，意味着没有点对无法互相到达，所以我们返回 0 。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2300-2399/2316.Count%20Unreachable%20Pairs%20of%20Nodes%20in%20an%20Undirected%20Graph/images/tc-2.png" style="width: 295px; height: 269px;"></p>

<pre><b>输入：</b>n = 7, edges = [[0,2],[0,5],[2,4],[1,6],[5,4]]
<b>输出：</b>14
<b>解释：</b>总共有 14 个点对互相无法到达：
[[0,1],[0,3],[0,6],[1,2],[1,3],[1,4],[1,5],[2,3],[2,6],[3,4],[3,5],[3,6],[4,6],[5,6]]
所以我们返回 14 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= edges.length &lt;= 2 * 10<sup>5</sup></code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt; n</code></li>
	<li><code>a<sub>i</sub> != b<sub>i</sub></code></li>
	<li>不会有重复边。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS

对于无向图中的任意两个节点，如果它们之间存在一条路径，那么它们之间就是互相可达的。

因此，我们可以通过深度优先搜索的方式，找出每一个连通分量中的节点个数 $t$，然后将当前连通分量中的节点个数 $t$ 与之前所有连通分量中的节点个数 $s$ 相乘，即可得到当前连通分量中的不可达点对数目 $s \times t$，然后将 $t$ 加到 $s$ 中。继续搜索下一个连通分量，直到搜索完所有连通分量，即可得到答案。

时间复杂度 $O(n + m)$，空间复杂度 $O(n + m)$。其中 $n$ 和 $m$ 分别是节点数和边数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countPairs(self, n: int, edges: List[List[int]]) -> int:
        def dfs(i: int) -> int:
            if vis[i]:
                return 0
            vis[i] = True
            return 1 + sum(dfs(j) for j in g[i])

        g = [[] for _ in range(n)]
        for a, b in edges:
            g[a].append(b)
            g[b].append(a)
        vis = [False] * n
        ans = s = 0
        for i in range(n):
            t = dfs(i)
            ans += s * t
            s += t
        return ans
```

#### Java

```java
class Solution {
    private List<Integer>[] g;
    private boolean[] vis;

    public long countPairs(int n, int[][] edges) {
        g = new List[n];
        vis = new boolean[n];
        Arrays.setAll(g, i -> new ArrayList<>());
        for (var e : edges) {
            int a = e[0], b = e[1];
            g[a].add(b);
            g[b].add(a);
        }
        long ans = 0, s = 0;
        for (int i = 0; i < n; ++i) {
            int t = dfs(i);
            ans += s * t;
            s += t;
        }
        return ans;
    }

    private int dfs(int i) {
        if (vis[i]) {
            return 0;
        }
        vis[i] = true;
        int cnt = 1;
        for (int j : g[i]) {
            cnt += dfs(j);
        }
        return cnt;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> g[n];
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        bool vis[n];
        memset(vis, 0, sizeof(vis));
        function<int(int)> dfs = [&](int i) {
            if (vis[i]) {
                return 0;
            }
            vis[i] = true;
            int cnt = 1;
            for (int j : g[i]) {
                cnt += dfs(j);
            }
            return cnt;
        };
        long long ans = 0, s = 0;
        for (int i = 0; i < n; ++i) {
            int t = dfs(i);
            ans += s * t;
            s += t;
        }
        return ans;
    }
};
```

#### Go

```go
func countPairs(n int, edges [][]int) (ans int64) {
	g := make([][]int, n)
	for _, e := range edges {
		a, b := e[0], e[1]
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}
	vis := make([]bool, n)
	var dfs func(int) int
	dfs = func(i int) int {
		if vis[i] {
			return 0
		}
		vis[i] = true
		cnt := 1
		for _, j := range g[i] {
			cnt += dfs(j)
		}
		return cnt
	}
	var s int64
	for i := 0; i < n; i++ {
		t := int64(dfs(i))
		ans += s * t
		s += t
	}
	return
}
```

#### TypeScript

```ts
function countPairs(n: number, edges: number[][]): number {
    const g: number[][] = Array.from({ length: n }, () => []);
    for (const [a, b] of edges) {
        g[a].push(b);
        g[b].push(a);
    }
    const vis: boolean[] = Array(n).fill(false);
    const dfs = (i: number): number => {
        if (vis[i]) {
            return 0;
        }
        vis[i] = true;
        let cnt = 1;
        for (const j of g[i]) {
            cnt += dfs(j);
        }
        return cnt;
    };
    let [ans, s] = [0, 0];
    for (let i = 0; i < n; ++i) {
        const t = dfs(i);
        ans += s * t;
        s += t;
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn count_pairs(n: i32, edges: Vec<Vec<i32>>) -> i64 {
        let n = n as usize;
        let mut g = vec![vec![]; n];
        let mut vis = vec![false; n];
        for e in edges {
            let u = e[0] as usize;
            let v = e[1] as usize;
            g[u].push(v);
            g[v].push(u);
        }

        fn dfs(g: &Vec<Vec<usize>>, vis: &mut Vec<bool>, u: usize) -> i64 {
            if vis[u] {
                return 0;
            }
            vis[u] = true;
            let mut cnt = 1;
            for &v in &g[u] {
                cnt += dfs(g, vis, v);
            }
            cnt
        }

        let mut ans = 0;
        let mut s = 0;
        for u in 0..n {
            let t = dfs(&g, &mut vis, u);
            ans += t * s;
            s += t;
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

# [2317. 操作后的最大异或和](https://leetcode.cn/problems/maximum-xor-after-operations){#2317}

{{< tabs "2317" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumXOR(self, nums: List[int]) -> int:
        return reduce(or_, nums)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maximumXOR(int[] nums) {
        int ans = 0;
        for (int x : nums) {
            ans |= x;
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
    int maximumXOR(vector<int>& nums) {
        int ans = 0;
        for (int& x : nums) {
            ans |= x;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumXOR(nums []int) (ans int) {
	for _, x := range nums {
		ans |= x
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumXOR(nums: number[]): number {
    let ans = 0;
    for (const x of nums) {
        ans |= x;
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

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>nums</code>&nbsp;。一次操作中，选择 <strong>任意</strong>&nbsp;非负整数&nbsp;<code>x</code>&nbsp;和一个下标&nbsp;<code>i</code>&nbsp;，<strong>更新</strong>&nbsp;<code>nums[i]</code>&nbsp;为&nbsp;<code>nums[i] AND (nums[i] XOR x)</code>&nbsp;。</p>

<p>注意，<code>AND</code>&nbsp;是逐位与运算，<code>XOR</code>&nbsp;是逐位异或运算。</p>

<p>请你执行 <strong>任意次</strong>&nbsp;更新操作，并返回&nbsp;<code>nums</code>&nbsp;中所有元素&nbsp;<strong>最大</strong>&nbsp;逐位异或和。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [3,2,4,6]
<b>输出：</b>7
<b>解释：</b>选择 x = 4 和 i = 3 进行操作，num[3] = 6 AND (6 XOR 4) = 6 AND 2 = 2 。
现在，nums = [3, 2, 4, 2] 且所有元素逐位异或得到 3 XOR 2 XOR 4 XOR 2 = 7 。
可知 7 是能得到的最大逐位异或和。
注意，其他操作可能也能得到逐位异或和 7 。</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [1,2,3,9,2]
<b>输出：</b>11
<b>解释：</b>执行 0 次操作。
所有元素的逐位异或和为 1 XOR 2 XOR 3 XOR 9 XOR 2 = 11 。
可知 11 是能得到的最大逐位异或和。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>8</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：位运算

在一次操作中，我们可以把 $\textit{nums}[i]$ 更新为 $\textit{nums}[i] \text{ AND } (\textit{nums}[i] \text{ XOR } x)$。由于 $x$ 是任意非负整数，因此 $\textit{nums}[i] \oplus x$ 的结果是一个任意值，再与 $\textit{nums}[i]$ 逐位与运算，可以把 $\textit{nums}[i]$ 的二进制表示中的若干位 $1$ 变为 $0$。

而题目中要获取的是 $\textit{nums}$ 所有元素的最大逐位异或和，对于一个二进制位，只要在 $\textit{nums}$ 中存在一个元素对应的二进制位为 $1$，那么这个二进制位对于最大逐位异或和的贡献就是 $1$。因此答案就是 $\textit{nums}$ 中所有元素的逐位或运算的结果。

时间复杂度 $O(n)$，其中 $n$ 为 $\textit{nums}$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumXOR(self, nums: List[int]) -> int:
        return reduce(or_, nums)
```

#### Java

```java
class Solution {
    public int maximumXOR(int[] nums) {
        int ans = 0;
        for (int x : nums) {
            ans |= x;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int ans = 0;
        for (int& x : nums) {
            ans |= x;
        }
        return ans;
    }
};
```

#### Go

```go
func maximumXOR(nums []int) (ans int) {
	for _, x := range nums {
		ans |= x
	}
	return
}
```

#### TypeScript

```ts
function maximumXOR(nums: number[]): number {
    let ans = 0;
    for (const x of nums) {
        ans |= x;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2318. 不同骰子序列的数目](https://leetcode.cn/problems/number-of-distinct-roll-sequences){#2318}

{{< tabs "2318" >}}

{{% tab "python" %}}
```python
class Solution:
    def distinctSequences(self, n: int) -> int:
        if n == 1:
            return 6
        mod = 10**9 + 7
        dp = [[[0] * 6 for _ in range(6)] for _ in range(n + 1)]
        for i in range(6):
            for j in range(6):
                if gcd(i + 1, j + 1) == 1 and i != j:
                    dp[2][i][j] = 1
        for k in range(3, n + 1):
            for i in range(6):
                for j in range(6):
                    if gcd(i + 1, j + 1) == 1 and i != j:
                        for h in range(6):
                            if gcd(h + 1, i + 1) == 1 and h != i and h != j:
                                dp[k][i][j] += dp[k - 1][h][i]
        ans = 0
        for i in range(6):
            for j in range(6):
                ans += dp[-1][i][j]
        return ans % mod
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int distinctSequences(int n) {
        if (n == 1) {
            return 6;
        }
        int mod = (int) 1e9 + 7;
        int[][][] dp = new int[n + 1][6][6];
        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 6; ++j) {
                if (gcd(i + 1, j + 1) == 1 && i != j) {
                    dp[2][i][j] = 1;
                }
            }
        }
        for (int k = 3; k <= n; ++k) {
            for (int i = 0; i < 6; ++i) {
                for (int j = 0; j < 6; ++j) {
                    if (gcd(i + 1, j + 1) == 1 && i != j) {
                        for (int h = 0; h < 6; ++h) {
                            if (gcd(h + 1, i + 1) == 1 && h != i && h != j) {
                                dp[k][i][j] = (dp[k][i][j] + dp[k - 1][h][i]) % mod;
                            }
                        }
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 6; ++j) {
                ans = (ans + dp[n][i][j]) % mod;
            }
        }
        return ans;
    }

    private int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int distinctSequences(int n) {
        if (n == 1) return 6;
        int mod = 1e9 + 7;
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(6, vector<int>(6)));
        for (int i = 0; i < 6; ++i)
            for (int j = 0; j < 6; ++j)
                if (gcd(i + 1, j + 1) == 1 && i != j)
                    dp[2][i][j] = 1;
        for (int k = 3; k <= n; ++k)
            for (int i = 0; i < 6; ++i)
                for (int j = 0; j < 6; ++j)
                    if (gcd(i + 1, j + 1) == 1 && i != j)
                        for (int h = 0; h < 6; ++h)
                            if (gcd(h + 1, i + 1) == 1 && h != i && h != j)
                                dp[k][i][j] = (dp[k][i][j] + dp[k - 1][h][i]) % mod;
        int ans = 0;
        for (int i = 0; i < 6; ++i)
            for (int j = 0; j < 6; ++j)
                ans = (ans + dp[n][i][j]) % mod;
        return ans;
    }

    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func distinctSequences(n int) int {
	if n == 1 {
		return 6
	}
	dp := make([][][]int, n+1)
	for k := range dp {
		dp[k] = make([][]int, 6)
		for i := range dp[k] {
			dp[k][i] = make([]int, 6)
		}
	}
	for i := 0; i < 6; i++ {
		for j := 0; j < 6; j++ {
			if gcd(i+1, j+1) == 1 && i != j {
				dp[2][i][j] = 1
			}
		}
	}
	mod := int(1e9) + 7
	for k := 3; k <= n; k++ {
		for i := 0; i < 6; i++ {
			for j := 0; j < 6; j++ {
				if gcd(i+1, j+1) == 1 && i != j {
					for h := 0; h < 6; h++ {
						if gcd(h+1, i+1) == 1 && h != i && h != j {
							dp[k][i][j] = (dp[k][i][j] + dp[k-1][h][i]) % mod
						}
					}
				}
			}
		}
	}
	ans := 0
	for i := 0; i < 6; i++ {
		for j := 0; j < 6; j++ {
			ans = (ans + dp[n][i][j]) % mod
		}
	}
	return ans
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数&nbsp;<code>n</code>&nbsp;。你需要掷一个 6 面的骰子&nbsp;<code>n</code>&nbsp;次。请你在满足以下要求的前提下，求出 <strong>不同</strong>&nbsp;骰子序列的数目：</p>

<ol>
	<li>序列中任意 <strong>相邻</strong>&nbsp;数字的 <strong>最大公约数</strong>&nbsp;为 <code>1</code>&nbsp;。</li>
	<li>序列中 <strong>相等</strong>&nbsp;的值之间，至少有 <code>2</code>&nbsp;个其他值的数字。正式地，如果第&nbsp;<code>i</code>&nbsp;次掷骰子的值 <strong>等于</strong>&nbsp;第&nbsp;<code>j</code>&nbsp;次的值，那么&nbsp;<code>abs(i - j) &gt; 2</code>&nbsp;。</li>
</ol>

<p>请你返回不同序列的 <strong>总数目</strong>&nbsp;。由于答案可能很大，请你将答案对&nbsp;<code>10<sup>9</sup> + 7</code>&nbsp;<strong>取余</strong>&nbsp;后返回。</p>

<p>如果两个序列中至少有一个元素不同，那么它们被视为不同的序列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>n = 4
<b>输出：</b>184
<b>解释：</b>一些可行的序列为 (1, 2, 3, 4) ，(6, 1, 2, 3) ，(1, 2, 3, 1) 等等。
一些不可行的序列为 (1, 2, 1, 3) ，(1, 2, 3, 6) 。
(1, 2, 1, 3) 是不可行的，因为第一个和第三个骰子值相等且 abs(1 - 3) = 2 （下标从 1 开始表示）。
(1, 2, 3, 6) i是不可行的，因为 3 和 6 的最大公约数是 3 。
总共有 184 个不同的可行序列，所以我们返回 184 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>n = 2
<b>输出：</b>22
<b>解释：</b>一些可行的序列为 (1, 2) ，(2, 1) ，(3, 2) 。
一些不可行的序列为 (3, 6) ，(2, 4) ，因为最大公约数不为 1 。
总共有 22 个不同的可行序列，所以我们返回 22 。
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

三维 DP。

设 $dp[k][i][j]$ 表示序列长度为 $k$，且序列的最后两个数字分别为 $i$, $j$ 的所有满足要求的不同序列的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def distinctSequences(self, n: int) -> int:
        if n == 1:
            return 6
        mod = 10**9 + 7
        dp = [[[0] * 6 for _ in range(6)] for _ in range(n + 1)]
        for i in range(6):
            for j in range(6):
                if gcd(i + 1, j + 1) == 1 and i != j:
                    dp[2][i][j] = 1
        for k in range(3, n + 1):
            for i in range(6):
                for j in range(6):
                    if gcd(i + 1, j + 1) == 1 and i != j:
                        for h in range(6):
                            if gcd(h + 1, i + 1) == 1 and h != i and h != j:
                                dp[k][i][j] += dp[k - 1][h][i]
        ans = 0
        for i in range(6):
            for j in range(6):
                ans += dp[-1][i][j]
        return ans % mod
```

#### Java

```java
class Solution {
    public int distinctSequences(int n) {
        if (n == 1) {
            return 6;
        }
        int mod = (int) 1e9 + 7;
        int[][][] dp = new int[n + 1][6][6];
        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 6; ++j) {
                if (gcd(i + 1, j + 1) == 1 && i != j) {
                    dp[2][i][j] = 1;
                }
            }
        }
        for (int k = 3; k <= n; ++k) {
            for (int i = 0; i < 6; ++i) {
                for (int j = 0; j < 6; ++j) {
                    if (gcd(i + 1, j + 1) == 1 && i != j) {
                        for (int h = 0; h < 6; ++h) {
                            if (gcd(h + 1, i + 1) == 1 && h != i && h != j) {
                                dp[k][i][j] = (dp[k][i][j] + dp[k - 1][h][i]) % mod;
                            }
                        }
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 6; ++j) {
                ans = (ans + dp[n][i][j]) % mod;
            }
        }
        return ans;
    }

    private int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int distinctSequences(int n) {
        if (n == 1) return 6;
        int mod = 1e9 + 7;
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(6, vector<int>(6)));
        for (int i = 0; i < 6; ++i)
            for (int j = 0; j < 6; ++j)
                if (gcd(i + 1, j + 1) == 1 && i != j)
                    dp[2][i][j] = 1;
        for (int k = 3; k <= n; ++k)
            for (int i = 0; i < 6; ++i)
                for (int j = 0; j < 6; ++j)
                    if (gcd(i + 1, j + 1) == 1 && i != j)
                        for (int h = 0; h < 6; ++h)
                            if (gcd(h + 1, i + 1) == 1 && h != i && h != j)
                                dp[k][i][j] = (dp[k][i][j] + dp[k - 1][h][i]) % mod;
        int ans = 0;
        for (int i = 0; i < 6; ++i)
            for (int j = 0; j < 6; ++j)
                ans = (ans + dp[n][i][j]) % mod;
        return ans;
    }

    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};
```

#### Go

```go
func distinctSequences(n int) int {
	if n == 1 {
		return 6
	}
	dp := make([][][]int, n+1)
	for k := range dp {
		dp[k] = make([][]int, 6)
		for i := range dp[k] {
			dp[k][i] = make([]int, 6)
		}
	}
	for i := 0; i < 6; i++ {
		for j := 0; j < 6; j++ {
			if gcd(i+1, j+1) == 1 && i != j {
				dp[2][i][j] = 1
			}
		}
	}
	mod := int(1e9) + 7
	for k := 3; k <= n; k++ {
		for i := 0; i < 6; i++ {
			for j := 0; j < 6; j++ {
				if gcd(i+1, j+1) == 1 && i != j {
					for h := 0; h < 6; h++ {
						if gcd(h+1, i+1) == 1 && h != i && h != j {
							dp[k][i][j] = (dp[k][i][j] + dp[k-1][h][i]) % mod
						}
					}
				}
			}
		}
	}
	ans := 0
	for i := 0; i < 6; i++ {
		for j := 0; j < 6; j++ {
			ans = (ans + dp[n][i][j]) % mod
		}
	}
	return ans
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2319. 判断矩阵是否是一个 X 矩阵](https://leetcode.cn/problems/check-if-matrix-is-x-matrix){#2319}

{{< tabs "2319" >}}

{{% tab "python" %}}
```python
class Solution:
    def checkXMatrix(self, grid: List[List[int]]) -> bool:
        for i, row in enumerate(grid):
            for j, v in enumerate(row):
                if i == j or i + j == len(grid) - 1:
                    if v == 0:
                        return False
                elif v:
                    return False
        return True
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean checkXMatrix(int[][] grid) {
        int n = grid.length;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j || i + j == n - 1) {
                    if (grid[i][j] == 0) {
                        return false;
                    }
                } else if (grid[i][j] != 0) {
                    return false;
                }
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
    bool checkXMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j || i + j == n - 1) {
                    if (!grid[i][j]) {
                        return false;
                    }
                } else if (grid[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func checkXMatrix(grid [][]int) bool {
	for i, row := range grid {
		for j, v := range row {
			if i == j || i+j == len(row)-1 {
				if v == 0 {
					return false
				}
			} else if v != 0 {
				return false
			}
		}
	}
	return true
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function checkXMatrix(grid: number[][]): boolean {
    const n = grid.length;
    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < n; ++j) {
            if (i == j || i + j == n - 1) {
                if (!grid[i][j]) {
                    return false;
                }
            } else if (grid[i][j]) {
                return false;
            }
        }
    }
    return true;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn check_x_matrix(grid: Vec<Vec<i32>>) -> bool {
        let n = grid.len();
        for i in 0..n {
            for j in 0..n {
                if i == j || i + j == n - 1 {
                    if grid[i][j] == 0 {
                        return false;
                    }
                } else if grid[i][j] != 0 {
                    return false;
                }
            }
        }
        true
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public bool CheckXMatrix(int[][] grid) {
        int n = grid.Length;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j || i + j == n - 1) {
                    if (grid[i][j] == 0) {
                        return false;
                    }
                } else if (grid[i][j] != 0) {
                    return false;
                }
            }
        }
        return true;
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
bool checkXMatrix(int** grid, int gridSize, int* gridColSize) {
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            if (i == j || i + j == gridSize - 1) {
                if (grid[i][j] == 0) {
                    return false;
                }
            } else if (grid[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>如果一个正方形矩阵满足下述 <strong>全部</strong> 条件，则称之为一个 <strong>X 矩阵</strong> ：</p>

<ol>
	<li>矩阵对角线上的所有元素都 <strong>不是 0</strong></li>
	<li>矩阵中所有其他元素都是 <strong>0</strong></li>
</ol>

<p>给你一个大小为 <code>n x n</code> 的二维整数数组 <code>grid</code> ，表示一个正方形矩阵。如果<em> </em><code>grid</code><em> </em>是一个 <strong>X 矩阵 </strong>，返回 <code>true</code> ；否则，返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2300-2399/2319.Check%20if%20Matrix%20Is%20X-Matrix/images/ex1.jpg" style="width: 311px; height: 320px;">
<pre><strong>输入：</strong>grid = [[2,0,0,1],[0,3,1,0],[0,5,2,0],[4,0,0,2]]
<strong>输出：</strong>true
<strong>解释：</strong>矩阵如上图所示。
X 矩阵应该满足：绿色元素（对角线上）都不是 0 ，红色元素都是 0 。
因此，grid 是一个 X 矩阵。
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2300-2399/2319.Check%20if%20Matrix%20Is%20X-Matrix/images/ex2.jpg" style="width: 238px; height: 246px;">
<pre><strong>输入：</strong>grid = [[5,7,0],[0,3,1],[0,5,0]]
<strong>输出：</strong>false
<strong>解释：</strong>矩阵如上图所示。
X 矩阵应该满足：绿色元素（对角线上）都不是 0 ，红色元素都是 0 。
因此，grid 不是一个 X 矩阵。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == grid.length == grid[i].length</code></li>
	<li><code>3 &lt;= n &lt;= 100</code></li>
	<li><code>0 &lt;= grid[i][j] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们可以直接遍历矩阵，对于每个元素，判断其是否满足 $X$ 矩阵的条件。若不满足，直接返回 $\textit{false}$；若遍历完所有元素都满足，返回 $\textit{true}$。

时间复杂度 $O(n^2)$，其中 $n$ 为矩阵的行数或列数。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def checkXMatrix(self, grid: List[List[int]]) -> bool:
        for i, row in enumerate(grid):
            for j, v in enumerate(row):
                if i == j or i + j == len(grid) - 1:
                    if v == 0:
                        return False
                elif v:
                    return False
        return True
```

#### Java

```java
class Solution {
    public boolean checkXMatrix(int[][] grid) {
        int n = grid.length;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j || i + j == n - 1) {
                    if (grid[i][j] == 0) {
                        return false;
                    }
                } else if (grid[i][j] != 0) {
                    return false;
                }
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
    bool checkXMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j || i + j == n - 1) {
                    if (!grid[i][j]) {
                        return false;
                    }
                } else if (grid[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
};
```

#### Go

```go
func checkXMatrix(grid [][]int) bool {
	for i, row := range grid {
		for j, v := range row {
			if i == j || i+j == len(row)-1 {
				if v == 0 {
					return false
				}
			} else if v != 0 {
				return false
			}
		}
	}
	return true
}
```

#### TypeScript

```ts
function checkXMatrix(grid: number[][]): boolean {
    const n = grid.length;
    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < n; ++j) {
            if (i == j || i + j == n - 1) {
                if (!grid[i][j]) {
                    return false;
                }
            } else if (grid[i][j]) {
                return false;
            }
        }
    }
    return true;
}
```

#### Rust

```rust
impl Solution {
    pub fn check_x_matrix(grid: Vec<Vec<i32>>) -> bool {
        let n = grid.len();
        for i in 0..n {
            for j in 0..n {
                if i == j || i + j == n - 1 {
                    if grid[i][j] == 0 {
                        return false;
                    }
                } else if grid[i][j] != 0 {
                    return false;
                }
            }
        }
        true
    }
}
```

#### C#

```cs
public class Solution {
    public bool CheckXMatrix(int[][] grid) {
        int n = grid.Length;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j || i + j == n - 1) {
                    if (grid[i][j] == 0) {
                        return false;
                    }
                } else if (grid[i][j] != 0) {
                    return false;
                }
            }
        }
        return true;
    }
}
```

#### C

```c
bool checkXMatrix(int** grid, int gridSize, int* gridColSize) {
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            if (i == j || i + j == gridSize - 1) {
                if (grid[i][j] == 0) {
                    return false;
                }
            } else if (grid[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
