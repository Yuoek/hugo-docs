---
title: "0470_用 Rand7() 实现 Rand10()"
date: 2025-10-08T18:36:10+08:00
weight: 8
tags: [二分查找, 位运算, 几何, 动态规划, 双指针, 回溯, 字典树, 字符串, 拒绝采样, 排序, 数学, 数组, 枚举, 概率与统计, 深度优先搜索, 状态压缩, 随机化]
---

{{< markmap >}}
### [0470_用 Rand7() 实现 Rand10()](#470)
#### [数学](#470)
#### [拒绝采样](#470)
#### [概率与统计](#470)
#### [随机化](#470)
### [0471_编码最短长度的字符串 🔒](#471)
#### [字符串](#471)
#### [动态规划](#471)
### [0472_连接词](#472)
#### [深度优先搜索](#472)
#### [字典树](#472)
#### [数组](#472)
#### [字符串](#472)
#### [动态规划](#472)
#### [排序](#472)
### [0473_火柴拼正方形](#473)
#### [位运算](#473)
#### [数组](#473)
#### [动态规划](#473)
#### [回溯](#473)
#### [状态压缩](#473)
### [0474_一和零](#474)
#### [数组](#474)
#### [字符串](#474)
#### [动态规划](#474)
### [0475_供暖器](#475)
#### [数组](#475)
#### [双指针](#475)
#### [二分查找](#475)
#### [排序](#475)
### [0476_数字的补数](#476)
#### [位运算](#476)
### [0477_汉明距离总和](#477)
#### [位运算](#477)
#### [数组](#477)
#### [数学](#477)
### [0478_在圆内随机生成点](#478)
#### [几何](#478)
#### [数学](#478)
#### [拒绝采样](#478)
#### [随机化](#478)
### [0479_最大回文数乘积](#479)
#### [数学](#479)
#### [枚举](#479)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0470_用 Rand7() 实现 Rand10()
___
#### 数学
___
#### 拒绝采样
___
#### 概率与统计
___
#### 随机化
---
### 0471_编码最短长度的字符串 🔒
___
#### 字符串
___
#### 动态规划
---
### 0472_连接词
___
#### 深度优先搜索
___
#### 字典树
___
#### 数组
___
#### 字符串
___
#### 动态规划
___
#### 排序
---
### 0473_火柴拼正方形
___
#### 位运算
___
#### 数组
___
#### 动态规划
___
#### 回溯
___
#### 状态压缩
---
### 0474_一和零
___
#### 数组
___
#### 字符串
___
#### 动态规划
---
### 0475_供暖器
___
#### 数组
___
#### 双指针
___
#### 二分查找
___
#### 排序
---
### 0476_数字的补数
___
#### 位运算
---
### 0477_汉明距离总和
___
#### 位运算
___
#### 数组
___
#### 数学
---
### 0478_在圆内随机生成点
___
#### 几何
___
#### 数学
___
#### 拒绝采样
___
#### 随机化
---
### 0479_最大回文数乘积
___
#### 数学
___
#### 枚举
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 位运算 | 几何 |
| 动态规划 | 双指针 | 回溯 |
| 字典树 | 字符串 | 拒绝采样 |
| 排序 | 数学 | 数组 |
| 枚举 | 概率与统计 | 深度优先搜索 |
| 状态压缩 | 随机化 |  |

# [470. 用 Rand7() 实现 Rand10()](https://leetcode.cn/problems/implement-rand10-using-rand7){#470}

{{< tabs "470" >}}

{{% tab "python" %}}
```python
# The rand7() API is already defined for you.
# def rand7():
# @return a random integer in the range 1 to 7


class Solution:
    def rand10(self):
        """
        :rtype: int
        """
        while 1:
            i = rand7() - 1
            j = rand7()
            x = i * 7 + j
            if x <= 40:
                return x % 10 + 1
```
{{% /tab %}}
{{% tab "java" %}}
```java
/**
 * The rand7() API is already defined in the parent class SolBase.
 * public int rand7();
 * @return a random integer in the range 1 to 7
 */
class Solution extends SolBase {
    public int rand10() {
        while (true) {
            int i = rand7() - 1;
            int j = rand7();
            int x = i * 7 + j;
            if (x <= 40) {
                return x % 10 + 1;
            }
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        while (1) {
            int i = rand7() - 1;
            int j = rand7();
            int x = i * 7 + j;
            if (x <= 40) {
                return x % 10 + 1;
            }
        }
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func rand10() int {
	for {
		i := rand7() - 1
		j := rand7()
		x := i*7 + j
		if x <= 40 {
			return x%10 + 1
		}
	}
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
/**
 * The rand7() API is already defined for you.
 * function rand7(): number {}
 * @return a random integer in the range 1 to 7
 */

function rand10(): number {
    while (true) {
        const i = rand7() - 1;
        const j = rand7();
        const x = i * 7 + j;
        if (x <= 40) {
            return (x % 10) + 1;
        }
    }
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
/**
 * The rand7() API is already defined for you.
 * @return a random integer in the range 1 to 7
 * fn rand7() -> i32;
 */

impl Solution {
    pub fn rand10() -> i32 {
        loop {
            let i = rand7() - 1;
            let j = rand7();
            let x = i * 7 + j;
            if x <= 40 {
                return (x % 10) + 1;
            }
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

<p>给定方法&nbsp;<code>rand7</code>&nbsp;可生成 <code>[1,7]</code> 范围内的均匀随机整数，试写一个方法&nbsp;<code>rand10</code>&nbsp;生成 <code>[1,10]</code> 范围内的均匀随机整数。</p>

<p>你只能调用&nbsp;<code>rand7()</code>&nbsp;且不能调用其他方法。请不要使用系统的&nbsp;<code>Math.random()</code>&nbsp;方法。</p>

<ol>
</ol>

<p>每个测试用例将有一个内部参数 <code>n</code>，即你实现的函数 <code>rand10()</code> 在测试时将被调用的次数。请注意，这不是传递给 <code>rand10()</code> 的参数。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入: </strong>1
<strong>输出: </strong>[2]
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入: </strong>2
<strong>输出: </strong>[2,8]
</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入: </strong>3
<strong>输出: </strong>[3,8,10]
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶:</strong></p>

<ul>
	<li><code>rand7()</code>调用次数的&nbsp;<a href="https://en.wikipedia.org/wiki/Expected_value" target="_blank">期望值</a>&nbsp;是多少&nbsp;?</li>
	<li>你能否尽量少调用 <code>rand7()</code> ?</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：拒绝采样

我们可以使用拒绝采样的方法实现等概率生成任意区间的随机数。拒绝采样的思路是如果生成的随机数落在我们希望的区间内，那么就返回该随机数，否则会不断生成直到生成一个落在区间内的随机数为止。

对于本题，我们可以通过调用 $rand7()$ 两次来实现生成 $[1,10]$ 以内的随机数，具体如下：

我们生成一个大于等于 $1$ 且小于等于 $40$ 的整数 $x$，其中等概率生成的方式为 $x = (rand7() - 1) \times 7 + rand7()$，然后，我们返回 $x \bmod 10 + 1$ 即可。

期望时间复杂度为 $O(1)$，但是最坏情况下会达到无穷大的时间复杂度。空间复杂度为 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
# The rand7() API is already defined for you.
# def rand7():
# @return a random integer in the range 1 to 7


class Solution:
    def rand10(self):
        """
        :rtype: int
        """
        while 1:
            i = rand7() - 1
            j = rand7()
            x = i * 7 + j
            if x <= 40:
                return x % 10 + 1
```

#### Java

```java
/**
 * The rand7() API is already defined in the parent class SolBase.
 * public int rand7();
 * @return a random integer in the range 1 to 7
 */
class Solution extends SolBase {
    public int rand10() {
        while (true) {
            int i = rand7() - 1;
            int j = rand7();
            int x = i * 7 + j;
            if (x <= 40) {
                return x % 10 + 1;
            }
        }
    }
}
```

#### C++

```cpp
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        while (1) {
            int i = rand7() - 1;
            int j = rand7();
            int x = i * 7 + j;
            if (x <= 40) {
                return x % 10 + 1;
            }
        }
    }
};
```

#### Go

```go
func rand10() int {
	for {
		i := rand7() - 1
		j := rand7()
		x := i*7 + j
		if x <= 40 {
			return x%10 + 1
		}
	}
}
```

#### TypeScript

```ts
/**
 * The rand7() API is already defined for you.
 * function rand7(): number {}
 * @return a random integer in the range 1 to 7
 */

function rand10(): number {
    while (true) {
        const i = rand7() - 1;
        const j = rand7();
        const x = i * 7 + j;
        if (x <= 40) {
            return (x % 10) + 1;
        }
    }
}
```

#### Rust

```rust
/**
 * The rand7() API is already defined for you.
 * @return a random integer in the range 1 to 7
 * fn rand7() -> i32;
 */

impl Solution {
    pub fn rand10() -> i32 {
        loop {
            let i = rand7() - 1;
            let j = rand7();
            let x = i * 7 + j;
            if x <= 40 {
                return (x % 10) + 1;
            }
        }
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [471. 编码最短长度的字符串 🔒](https://leetcode.cn/problems/encode-string-with-shortest-length){#471}

{{< tabs "471" >}}

{{% tab "python" %}}
```python
class Solution:
    def encode(self, s: str) -> str:
        def g(i: int, j: int) -> str:
            t = s[i : j + 1]
            if len(t) < 5:
                return t
            k = (t + t).index(t, 1)
            if k < len(t):
                cnt = len(t) // k
                return f"{cnt}[{f[i][i + k - 1]}]"
            return t

        n = len(s)
        f = [[None] * n for _ in range(n)]
        for i in range(n - 1, -1, -1):
            for j in range(i, n):
                f[i][j] = g(i, j)
                if j - i + 1 > 4:
                    for k in range(i, j):
                        t = f[i][k] + f[k + 1][j]
                        if len(f[i][j]) > len(t):
                            f[i][j] = t
        return f[0][-1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private String s;
    private String[][] f;

    public String encode(String s) {
        this.s = s;
        int n = s.length();
        f = new String[n][n];
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                f[i][j] = g(i, j);
                if (j - i + 1 > 4) {
                    for (int k = i; k < j; ++k) {
                        String t = f[i][k] + f[k + 1][j];
                        if (f[i][j].length() > t.length()) {
                            f[i][j] = t;
                        }
                    }
                }
            }
        }
        return f[0][n - 1];
    }

    private String g(int i, int j) {
        String t = s.substring(i, j + 1);
        if (t.length() < 5) {
            return t;
        }
        int k = (t + t).indexOf(t, 1);
        if (k < t.length()) {
            int cnt = t.length() / k;
            return String.format("%d[%s]", cnt, f[i][i + k - 1]);
        }
        return t;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string encode(string s) {
        int n = s.size();
        vector<vector<string>> f(n, vector<string>(n));

        auto g = [&](int i, int j) {
            string t = s.substr(i, j - i + 1);
            if (t.size() < 5) {
                return t;
            }
            int k = (t + t).find(t, 1);
            if (k < t.size()) {
                int cnt = t.size() / k;
                return to_string(cnt) + "[" + f[i][i + k - 1] + "]";
            }
            return t;
        };

        for (int i = n - 1; ~i; --i) {
            for (int j = i; j < n; ++j) {
                f[i][j] = g(i, j);
                if (j - i + 1 > 4) {
                    for (int k = i; k < j; ++k) {
                        string t = f[i][k] + f[k + 1][j];
                        if (t.size() < f[i][j].size()) {
                            f[i][j] = t;
                        }
                    }
                }
            }
        }
        return f[0][n - 1];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func encode(s string) string {
	n := len(s)
	f := make([][]string, n)
	for i := range f {
		f[i] = make([]string, n)
	}
	g := func(i, j int) string {
		t := s[i : j+1]
		if len(t) < 5 {
			return t
		}
		k := strings.Index((t + t)[1:], t) + 1
		if k < len(t) {
			cnt := len(t) / k
			return strconv.Itoa(cnt) + "[" + f[i][i+k-1] + "]"
		}
		return t
	}
	for i := n - 1; i >= 0; i-- {
		for j := i; j < n; j++ {
			f[i][j] = g(i, j)
			if j-i+1 > 4 {
				for k := i; k < j; k++ {
					t := f[i][k] + f[k+1][j]
					if len(t) < len(f[i][j]) {
						f[i][j] = t
					}
				}
			}
		}
	}
	return f[0][n-1]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function encode(s: string): string {
    const n = s.length;
    const f: string[][] = new Array(n).fill(0).map(() => new Array(n).fill(''));
    const g = (i: number, j: number): string => {
        const t = s.slice(i, j + 1);
        if (t.length < 5) {
            return t;
        }
        const k = t.repeat(2).indexOf(t, 1);
        if (k < t.length) {
            const cnt = Math.floor(t.length / k);
            return cnt + '[' + f[i][i + k - 1] + ']';
        }
        return t;
    };
    for (let i = n - 1; i >= 0; --i) {
        for (let j = i; j < n; ++j) {
            f[i][j] = g(i, j);
            if (j - i + 1 > 4) {
                for (let k = i; k < j; ++k) {
                    const t = f[i][k] + f[k + 1][j];
                    if (t.length < f[i][j].length) {
                        f[i][j] = t;
                    }
                }
            }
        }
    }
    return f[0][n - 1];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个 <strong>非空</strong> 字符串，将其编码为具有最短长度的字符串。</p>

<p>编码规则是：<code>k[encoded_string]</code>，其中在方括号 <code>encoded_string</code><em> </em>中的内容重复 <code>k</code> 次。</p>

<p><strong>注：</strong></p>

<ul>
	<li><em>k</em> 为正整数</li>
	<li>如果编码的过程不能使字符串缩短，则不要对其进行编码。如果有多种编码方式，返回 <strong>任意一种</strong> 即可</li>
</ul>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "aaa"
<strong>输出：</strong>"aaa"
<strong>解释：</strong>无法将其编码为更短的字符串，因此不进行编码。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "aaaaa"
<strong>输出：</strong>"5[a]"
<strong>解释：</strong>"5[a]" 比 "aaaaa" 短 1 个字符。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "aaaaaaaaaa"
<strong>输出：</strong>"10[a]"
<strong>解释：</strong>"a9[a]" 或 "9[a]a" 都是合法的编码，和 "10[a]" 一样长度都为 5。
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>s = "aabcaabcd"
<strong>输出：</strong>"2[aabc]d"
<strong>解释：</strong>"aabc" 出现两次，因此一种答案可以是 "2[aabc]d"。
</pre>

<p><strong>示例 5：</strong></p>

<pre>
<strong>输入：</strong>s = "abbbabbbcabbbabbbc"
<strong>输出：</strong>"2[2[abbb]c]"
<strong>解释：</strong>"abbbabbbc" 出现两次，但是 "abbbabbbc" 可以编码为 "2[abbb]c"，因此一种答案可以是 "2[2[abbb]c]"。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= s.length <= 150</code></li>
	<li><code>s</code> 由小写英文字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划（区间 DP）

在这道题中，我们需要判断一个字符串是否能够进行压缩，也即是说，一个字符串是否能通过其子串重复多次构成。我们可以利用第 $459$ 题的方法来判断，定义一个方法 $g(i, j)$，表示将字符串 $s[i...j]$ 进行压缩后得到的字符串。

接下来，我们用动态规划的方法，将字符串 $s$ 编码成一个最短长度的字符串。

我们定义 $f[i][j]$ 表示将字符串 $s[i..j]$ 编码后的最短字符串。如果直接将 $s[i..j]$ 进行压缩编码，那么 $f[i][j] = g(i, j)$，如果我们将其分成两个子串进行编码，那么 $f[i][j]$ 的值为 $f[i][k] + f[k + 1][j]$ 的最小值，其中 $i \le k < j$。取两种情况下长度较小的字符串即可。

在枚举 $i$ 和 $j$ 时，我们可以从大到小枚举 $i$，然后从小到大枚举 $j$，这样我们在计算 $f[i][j]$ 时，$f[i][k]$ 和 $f[k + 1][j]$ 的值都已经被计算过了。

时间复杂度 $O(n^3)$，空间复杂度 $O(n^2)$。其中 $n$ 是字符串 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def encode(self, s: str) -> str:
        def g(i: int, j: int) -> str:
            t = s[i : j + 1]
            if len(t) < 5:
                return t
            k = (t + t).index(t, 1)
            if k < len(t):
                cnt = len(t) // k
                return f"{cnt}[{f[i][i + k - 1]}]"
            return t

        n = len(s)
        f = [[None] * n for _ in range(n)]
        for i in range(n - 1, -1, -1):
            for j in range(i, n):
                f[i][j] = g(i, j)
                if j - i + 1 > 4:
                    for k in range(i, j):
                        t = f[i][k] + f[k + 1][j]
                        if len(f[i][j]) > len(t):
                            f[i][j] = t
        return f[0][-1]
```

#### Java

```java
class Solution {
    private String s;
    private String[][] f;

    public String encode(String s) {
        this.s = s;
        int n = s.length();
        f = new String[n][n];
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                f[i][j] = g(i, j);
                if (j - i + 1 > 4) {
                    for (int k = i; k < j; ++k) {
                        String t = f[i][k] + f[k + 1][j];
                        if (f[i][j].length() > t.length()) {
                            f[i][j] = t;
                        }
                    }
                }
            }
        }
        return f[0][n - 1];
    }

    private String g(int i, int j) {
        String t = s.substring(i, j + 1);
        if (t.length() < 5) {
            return t;
        }
        int k = (t + t).indexOf(t, 1);
        if (k < t.length()) {
            int cnt = t.length() / k;
            return String.format("%d[%s]", cnt, f[i][i + k - 1]);
        }
        return t;
    }
}
```

#### C++

```cpp
class Solution {
public:
    string encode(string s) {
        int n = s.size();
        vector<vector<string>> f(n, vector<string>(n));

        auto g = [&](int i, int j) {
            string t = s.substr(i, j - i + 1);
            if (t.size() < 5) {
                return t;
            }
            int k = (t + t).find(t, 1);
            if (k < t.size()) {
                int cnt = t.size() / k;
                return to_string(cnt) + "[" + f[i][i + k - 1] + "]";
            }
            return t;
        };

        for (int i = n - 1; ~i; --i) {
            for (int j = i; j < n; ++j) {
                f[i][j] = g(i, j);
                if (j - i + 1 > 4) {
                    for (int k = i; k < j; ++k) {
                        string t = f[i][k] + f[k + 1][j];
                        if (t.size() < f[i][j].size()) {
                            f[i][j] = t;
                        }
                    }
                }
            }
        }
        return f[0][n - 1];
    }
};
```

#### Go

```go
func encode(s string) string {
	n := len(s)
	f := make([][]string, n)
	for i := range f {
		f[i] = make([]string, n)
	}
	g := func(i, j int) string {
		t := s[i : j+1]
		if len(t) < 5 {
			return t
		}
		k := strings.Index((t + t)[1:], t) + 1
		if k < len(t) {
			cnt := len(t) / k
			return strconv.Itoa(cnt) + "[" + f[i][i+k-1] + "]"
		}
		return t
	}
	for i := n - 1; i >= 0; i-- {
		for j := i; j < n; j++ {
			f[i][j] = g(i, j)
			if j-i+1 > 4 {
				for k := i; k < j; k++ {
					t := f[i][k] + f[k+1][j]
					if len(t) < len(f[i][j]) {
						f[i][j] = t
					}
				}
			}
		}
	}
	return f[0][n-1]
}
```

#### TypeScript

```ts
function encode(s: string): string {
    const n = s.length;
    const f: string[][] = new Array(n).fill(0).map(() => new Array(n).fill(''));
    const g = (i: number, j: number): string => {
        const t = s.slice(i, j + 1);
        if (t.length < 5) {
            return t;
        }
        const k = t.repeat(2).indexOf(t, 1);
        if (k < t.length) {
            const cnt = Math.floor(t.length / k);
            return cnt + '[' + f[i][i + k - 1] + ']';
        }
        return t;
    };
    for (let i = n - 1; i >= 0; --i) {
        for (let j = i; j < n; ++j) {
            f[i][j] = g(i, j);
            if (j - i + 1 > 4) {
                for (let k = i; k < j; ++k) {
                    const t = f[i][k] + f[k + 1][j];
                    if (t.length < f[i][j].length) {
                        f[i][j] = t;
                    }
                }
            }
        }
    }
    return f[0][n - 1];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [472. 连接词](https://leetcode.cn/problems/concatenated-words){#472}

{{< tabs "472" >}}

{{% tab "python" %}}
```python
class Trie:
    def __init__(self):
        self.children = [None] * 26
        self.is_end = False

    def insert(self, w):
        node = self
        for c in w:
            idx = ord(c) - ord('a')
            if node.children[idx] is None:
                node.children[idx] = Trie()
            node = node.children[idx]
        node.is_end = True


class Solution:
    def findAllConcatenatedWordsInADict(self, words: List[str]) -> List[str]:
        def dfs(w):
            if not w:
                return True
            node = trie
            for i, c in enumerate(w):
                idx = ord(c) - ord('a')
                if node.children[idx] is None:
                    return False
                node = node.children[idx]
                if node.is_end and dfs(w[i + 1 :]):
                    return True
            return False

        trie = Trie()
        ans = []
        words.sort(key=lambda x: len(x))
        for w in words:
            if dfs(w):
                ans.append(w)
            else:
                trie.insert(w)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Trie {
    Trie[] children = new Trie[26];
    boolean isEnd;

    void insert(String w) {
        Trie node = this;
        for (char c : w.toCharArray()) {
            c -= 'a';
            if (node.children[c] == null) {
                node.children[c] = new Trie();
            }
            node = node.children[c];
        }
        node.isEnd = true;
    }
}

class Solution {
    private Trie trie = new Trie();

    public List<String> findAllConcatenatedWordsInADict(String[] words) {
        Arrays.sort(words, (a, b) -> a.length() - b.length());
        List<String> ans = new ArrayList<>();
        for (String w : words) {
            if (dfs(w)) {
                ans.add(w);
            } else {
                trie.insert(w);
            }
        }
        return ans;
    }

    private boolean dfs(String w) {
        if ("".equals(w)) {
            return true;
        }
        Trie node = trie;
        for (int i = 0; i < w.length(); ++i) {
            int idx = w.charAt(i) - 'a';
            if (node.children[idx] == null) {
                return false;
            }
            node = node.children[idx];
            if (node.isEnd && dfs(w.substring(i + 1))) {
                return true;
            }
        }
        return false;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Trie {
public:
    vector<Trie*> children;
    bool isEnd;
    Trie()
        : children(26)
        , isEnd(false) {}

    void insert(string w) {
        Trie* node = this;
        for (char c : w) {
            c -= 'a';
            if (!node->children[c]) node->children[c] = new Trie();
            node = node->children[c];
        }
        node->isEnd = true;
    }
};

class Solution {
public:
    Trie* trie = new Trie();

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin(), words.end(), [&](const string& a, const string& b) {
            return a.size() < b.size();
        });
        vector<string> ans;
        for (auto& w : words) {
            if (dfs(w))
                ans.push_back(w);
            else
                trie->insert(w);
        }
        return ans;
    }

    bool dfs(string w) {
        if (w == "") return true;
        Trie* node = trie;
        for (int i = 0; i < w.size(); ++i) {
            int idx = w[i] - 'a';
            if (!node->children[idx]) return false;
            node = node->children[idx];
            if (node->isEnd && dfs(w.substr(i + 1))) return true;
        }
        return false;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
type Trie struct {
	children [26]*Trie
	isEnd    bool
}

func newTrie() *Trie {
	return &Trie{}
}
func (this *Trie) insert(word string) {
	node := this
	for _, c := range word {
		c -= 'a'
		if node.children[c] == nil {
			node.children[c] = newTrie()
		}
		node = node.children[c]
	}
	node.isEnd = true
}

func findAllConcatenatedWordsInADict(words []string) (ans []string) {
	sort.Slice(words, func(i, j int) bool { return len(words[i]) < len(words[j]) })
	trie := newTrie()
	var dfs func(string) bool
	dfs = func(w string) bool {
		if w == "" {
			return true
		}
		node := trie
		for i, c := range w {
			c -= 'a'
			if node.children[c] == nil {
				return false
			}
			node = node.children[c]
			if node.isEnd && dfs(w[i+1:]) {
				return true
			}
		}
		return false
	}
	for _, w := range words {
		if dfs(w) {
			ans = append(ans, w)
		} else {
			trie.insert(w)
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

<p>给你一个 <strong>不含重复 </strong>单词的字符串数组 <code>words</code> ，请你找出并返回 <code>words</code> 中的所有 <strong>连接词</strong> 。</p>

<p><strong>连接词</strong> 定义为：一个完全由给定数组中的至少两个较短单词（不一定是不同的两个单词）组成的字符串。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>words = ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]
<strong>输出：</strong>["catsdogcats","dogcatsdog","ratcatdogcat"]
<strong>解释：</strong>"catsdogcats" 由 "cats", "dog" 和 "cats" 组成; 
     "dogcatsdog" 由 "dog", "cats" 和 "dog" 组成; 
     "ratcatdogcat" 由 "rat", "cat", "dog" 和 "cat" 组成。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>words = ["cat","dog","catdog"]
<strong>输出：</strong>["catdog"]</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= words[i].length &lt;= 30</code></li>
	<li><code>words[i]</code>&nbsp;仅由小写英文字母组成。&nbsp;</li>
	<li><code>words</code>&nbsp;中的所有字符串都是 <strong>唯一</strong> 的。</li>
	<li><code>1 &lt;= sum(words[i].length) &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前缀树 + DFS

判断一个单词是不是连接词，需要判断这个单词是否完全由至少两个给定数组中的更短的非空单词（可以重复）组成。判断更短的单词是否在给定数组中，可以使用字典树实现。

首先将 $words$ 按照字符串的长度递增的顺序排序，排序后可以确保当遍历到任意单词时，比该单词短的单词一定都已经遍历过，因此可以根据已经遍历过的全部单词判断当前单词是不是连接词。

在将 $words$ 排序之后，遍历 $words$，跳过空字符串，对于每个非空单词，判断该单词是不是连接词，如果是连接词则将该单词加入结果数组，如果不是连接词则将该单词加入字典树。

判断一个单词是不是连接词的做法是在字典树中深度优先搜索。从该单词的第一个字符（即下标 $0$ 处的字符）开始，在字典树中依次搜索每个字符对应的结点，可能有以下几种情况：

-   如果一个字符对应的结点是单词的结尾，则找到了一个更短的单词，从该字符的后一个字符开始搜索下一个更短的单词；
-   如果一个字符对应的结点在字典树中不存在，则当前的搜索结果失败，回到上一个单词的结尾继续搜索。

如果找到一个更短的单词且这个更短的单词的最后一个字符是当前单词的最后一个字符，则当前单词是连接词。由于数组 $words$ 中没有重复的单词，因此在判断一个单词是不是连接词时，该单词一定没有加入字典树，由此可以确保判断连接词的条件成立。

说明：由于一个连接词由多个更短的非空单词组成，如果存在一个较长的连接词的组成部分之一是一个较短的连接词，则一定可以将这个较短的连接词换成多个更短的非空单词，因此**不需要将连接词加入字典树**。

<!-- tabs:start -->

#### Python3

```python
class Trie:
    def __init__(self):
        self.children = [None] * 26
        self.is_end = False

    def insert(self, w):
        node = self
        for c in w:
            idx = ord(c) - ord('a')
            if node.children[idx] is None:
                node.children[idx] = Trie()
            node = node.children[idx]
        node.is_end = True


class Solution:
    def findAllConcatenatedWordsInADict(self, words: List[str]) -> List[str]:
        def dfs(w):
            if not w:
                return True
            node = trie
            for i, c in enumerate(w):
                idx = ord(c) - ord('a')
                if node.children[idx] is None:
                    return False
                node = node.children[idx]
                if node.is_end and dfs(w[i + 1 :]):
                    return True
            return False

        trie = Trie()
        ans = []
        words.sort(key=lambda x: len(x))
        for w in words:
            if dfs(w):
                ans.append(w)
            else:
                trie.insert(w)
        return ans
```

#### Java

```java
class Trie {
    Trie[] children = new Trie[26];
    boolean isEnd;

    void insert(String w) {
        Trie node = this;
        for (char c : w.toCharArray()) {
            c -= 'a';
            if (node.children[c] == null) {
                node.children[c] = new Trie();
            }
            node = node.children[c];
        }
        node.isEnd = true;
    }
}

class Solution {
    private Trie trie = new Trie();

    public List<String> findAllConcatenatedWordsInADict(String[] words) {
        Arrays.sort(words, (a, b) -> a.length() - b.length());
        List<String> ans = new ArrayList<>();
        for (String w : words) {
            if (dfs(w)) {
                ans.add(w);
            } else {
                trie.insert(w);
            }
        }
        return ans;
    }

    private boolean dfs(String w) {
        if ("".equals(w)) {
            return true;
        }
        Trie node = trie;
        for (int i = 0; i < w.length(); ++i) {
            int idx = w.charAt(i) - 'a';
            if (node.children[idx] == null) {
                return false;
            }
            node = node.children[idx];
            if (node.isEnd && dfs(w.substring(i + 1))) {
                return true;
            }
        }
        return false;
    }
}
```

#### C++

```cpp
class Trie {
public:
    vector<Trie*> children;
    bool isEnd;
    Trie()
        : children(26)
        , isEnd(false) {}

    void insert(string w) {
        Trie* node = this;
        for (char c : w) {
            c -= 'a';
            if (!node->children[c]) node->children[c] = new Trie();
            node = node->children[c];
        }
        node->isEnd = true;
    }
};

class Solution {
public:
    Trie* trie = new Trie();

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin(), words.end(), [&](const string& a, const string& b) {
            return a.size() < b.size();
        });
        vector<string> ans;
        for (auto& w : words) {
            if (dfs(w))
                ans.push_back(w);
            else
                trie->insert(w);
        }
        return ans;
    }

    bool dfs(string w) {
        if (w == "") return true;
        Trie* node = trie;
        for (int i = 0; i < w.size(); ++i) {
            int idx = w[i] - 'a';
            if (!node->children[idx]) return false;
            node = node->children[idx];
            if (node->isEnd && dfs(w.substr(i + 1))) return true;
        }
        return false;
    }
};
```

#### Go

```go
type Trie struct {
	children [26]*Trie
	isEnd    bool
}

func newTrie() *Trie {
	return &Trie{}
}
func (this *Trie) insert(word string) {
	node := this
	for _, c := range word {
		c -= 'a'
		if node.children[c] == nil {
			node.children[c] = newTrie()
		}
		node = node.children[c]
	}
	node.isEnd = true
}

func findAllConcatenatedWordsInADict(words []string) (ans []string) {
	sort.Slice(words, func(i, j int) bool { return len(words[i]) < len(words[j]) })
	trie := newTrie()
	var dfs func(string) bool
	dfs = func(w string) bool {
		if w == "" {
			return true
		}
		node := trie
		for i, c := range w {
			c -= 'a'
			if node.children[c] == nil {
				return false
			}
			node = node.children[c]
			if node.isEnd && dfs(w[i+1:]) {
				return true
			}
		}
		return false
	}
	for _, w := range words {
		if dfs(w) {
			ans = append(ans, w)
		} else {
			trie.insert(w)
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

# [473. 火柴拼正方形](https://leetcode.cn/problems/matchsticks-to-square){#473}

{{< tabs "473" >}}

{{% tab "python" %}}
```python
class Solution:
    def makesquare(self, matchsticks: List[int]) -> bool:
        @cache
        def dfs(state, t):
            if state == (1 << len(matchsticks)) - 1:
                return True
            for i, v in enumerate(matchsticks):
                if state & (1 << i):
                    continue
                if t + v > s:
                    break
                if dfs(state | (1 << i), (t + v) % s):
                    return True
            return False

        s, mod = divmod(sum(matchsticks), 4)
        matchsticks.sort()
        if mod:
            return False
        return dfs(0, 0)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean makesquare(int[] matchsticks) {
        int s = 0, mx = 0;
        for (int v : matchsticks) {
            s += v;
            mx = Math.max(mx, v);
        }
        int x = s / 4, mod = s % 4;
        if (mod != 0 || x < mx) {
            return false;
        }
        Arrays.sort(matchsticks);
        int[] edges = new int[4];
        return dfs(matchsticks.length - 1, x, matchsticks, edges);
    }

    private boolean dfs(int u, int x, int[] matchsticks, int[] edges) {
        if (u < 0) {
            return true;
        }
        for (int i = 0; i < 4; ++i) {
            if (i > 0 && edges[i - 1] == edges[i]) {
                continue;
            }
            edges[i] += matchsticks[u];
            if (edges[i] <= x && dfs(u - 1, x, matchsticks, edges)) {
                return true;
            }
            edges[i] -= matchsticks[u];
        }
        return false;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int s = 0, mx = 0;
        for (int& v : matchsticks) {
            s += v;
            mx = max(mx, v);
        }
        int x = s / 4, mod = s % 4;
        if (mod != 0 || x < mx) return false;
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        vector<int> edges(4);
        return dfs(0, x, matchsticks, edges);
    }

    bool dfs(int u, int x, vector<int>& matchsticks, vector<int>& edges) {
        if (u == matchsticks.size()) return true;
        for (int i = 0; i < 4; ++i) {
            if (i > 0 && edges[i - 1] == edges[i]) continue;
            edges[i] += matchsticks[u];
            if (edges[i] <= x && dfs(u + 1, x, matchsticks, edges)) return true;
            edges[i] -= matchsticks[u];
        }
        return false;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func makesquare(matchsticks []int) bool {
	s := 0
	for _, v := range matchsticks {
		s += v
	}
	if s%4 != 0 {
		return false
	}
	sort.Sort(sort.Reverse(sort.IntSlice(matchsticks)))
	edges := make([]int, 4)
	var dfs func(u, x int) bool
	dfs = func(u, x int) bool {
		if u == len(matchsticks) {
			return true
		}
		for i := 0; i < 4; i++ {
			if i > 0 && edges[i-1] == edges[i] {
				continue
			}
			edges[i] += matchsticks[u]
			if edges[i] <= x && dfs(u+1, x) {
				return true
			}
			edges[i] -= matchsticks[u]
		}
		return false
	}
	return dfs(0, s/4)
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn makesquare(matchsticks: Vec<i32>) -> bool {
        let mut matchsticks = matchsticks;

        fn dfs(matchsticks: &Vec<i32>, edges: &mut [i32; 4], u: usize, x: i32) -> bool {
            if u == matchsticks.len() {
                return true;
            }
            for i in 0..4 {
                if i > 0 && edges[i - 1] == edges[i] {
                    continue;
                }
                edges[i] += matchsticks[u];
                if edges[i] <= x && dfs(matchsticks, edges, u + 1, x) {
                    return true;
                }
                edges[i] -= matchsticks[u];
            }
            false
        }

        let sum: i32 = matchsticks.iter().sum();
        if sum % 4 != 0 {
            return false;
        }
        matchsticks.sort_by(|x, y| y.cmp(x));
        let mut edges = [0; 4];

        dfs(&matchsticks, &mut edges, 0, sum / 4)
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你将得到一个整数数组 <code>matchsticks</code> ，其中 <code>matchsticks[i]</code> 是第 <code>i</code>&nbsp;个火柴棒的长度。你要用 <strong>所有的火柴棍</strong>&nbsp;拼成一个正方形。你 <strong>不能折断</strong> 任何一根火柴棒，但你可以把它们连在一起，而且每根火柴棒必须 <strong>使用一次</strong> 。</p>

<p>如果你能使这个正方形，则返回 <code>true</code> ，否则返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例&nbsp;1:</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0400-0499/0473.Matchsticks%20to%20Square/images/matchsticks1-grid.jpg" /></p>

<pre>
<strong>输入:</strong> matchsticks = [1,1,2,2,2]
<strong>输出:</strong> true
<strong>解释:</strong> 能拼成一个边长为2的正方形，每边两根火柴。
</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre>
<strong>输入:</strong> matchsticks = [3,3,3,3,4]
<strong>输出:</strong> false
<strong>解释:</strong> 不能用所有火柴拼成一个正方形。
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= matchsticks.length &lt;= 15</code></li>
	<li><code>1 &lt;= matchsticks[i] &lt;= 10<sup>8</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 回溯

用 $edges[i]$ 记录正方形每条边当前的长度，对于第 $u$ 根火柴，尝试把它加到 $edges[i]$ 每条边，若加入后 $edges[i]$ 不超过正方形期望长度 $x$，则继续往下递归 $u+1$ 根火柴。若所有火柴都能被加入，说明满足拼成正方形的要求。

这里对 $matchsticks$ 从大到小排序，可以减少搜索次数。

时间复杂度 $O(4^n)$，其中 $n$ 表示 $matchsticks$ 的长度。每根火柴可以被放入正方形的 $4$ 条边，共有 $n$ 根火柴。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def makesquare(self, matchsticks: List[int]) -> bool:
        def dfs(u):
            if u == len(matchsticks):
                return True
            for i in range(4):
                if i > 0 and edges[i - 1] == edges[i]:
                    continue
                edges[i] += matchsticks[u]
                if edges[i] <= x and dfs(u + 1):
                    return True
                edges[i] -= matchsticks[u]
            return False

        x, mod = divmod(sum(matchsticks), 4)
        if mod or x < max(matchsticks):
            return False
        edges = [0] * 4
        matchsticks.sort(reverse=True)
        return dfs(0)
```

#### Java

```java
class Solution {
    public boolean makesquare(int[] matchsticks) {
        int s = 0, mx = 0;
        for (int v : matchsticks) {
            s += v;
            mx = Math.max(mx, v);
        }
        int x = s / 4, mod = s % 4;
        if (mod != 0 || x < mx) {
            return false;
        }
        Arrays.sort(matchsticks);
        int[] edges = new int[4];
        return dfs(matchsticks.length - 1, x, matchsticks, edges);
    }

    private boolean dfs(int u, int x, int[] matchsticks, int[] edges) {
        if (u < 0) {
            return true;
        }
        for (int i = 0; i < 4; ++i) {
            if (i > 0 && edges[i - 1] == edges[i]) {
                continue;
            }
            edges[i] += matchsticks[u];
            if (edges[i] <= x && dfs(u - 1, x, matchsticks, edges)) {
                return true;
            }
            edges[i] -= matchsticks[u];
        }
        return false;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int s = 0, mx = 0;
        for (int& v : matchsticks) {
            s += v;
            mx = max(mx, v);
        }
        int x = s / 4, mod = s % 4;
        if (mod != 0 || x < mx) return false;
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        vector<int> edges(4);
        return dfs(0, x, matchsticks, edges);
    }

    bool dfs(int u, int x, vector<int>& matchsticks, vector<int>& edges) {
        if (u == matchsticks.size()) return true;
        for (int i = 0; i < 4; ++i) {
            if (i > 0 && edges[i - 1] == edges[i]) continue;
            edges[i] += matchsticks[u];
            if (edges[i] <= x && dfs(u + 1, x, matchsticks, edges)) return true;
            edges[i] -= matchsticks[u];
        }
        return false;
    }
};
```

#### Go

```go
func makesquare(matchsticks []int) bool {
	s := 0
	for _, v := range matchsticks {
		s += v
	}
	if s%4 != 0 {
		return false
	}
	sort.Sort(sort.Reverse(sort.IntSlice(matchsticks)))
	edges := make([]int, 4)
	var dfs func(u, x int) bool
	dfs = func(u, x int) bool {
		if u == len(matchsticks) {
			return true
		}
		for i := 0; i < 4; i++ {
			if i > 0 && edges[i-1] == edges[i] {
				continue
			}
			edges[i] += matchsticks[u]
			if edges[i] <= x && dfs(u+1, x) {
				return true
			}
			edges[i] -= matchsticks[u]
		}
		return false
	}
	return dfs(0, s/4)
}
```

#### Rust

```rust
impl Solution {
    pub fn makesquare(matchsticks: Vec<i32>) -> bool {
        let mut matchsticks = matchsticks;

        fn dfs(matchsticks: &Vec<i32>, edges: &mut [i32; 4], u: usize, x: i32) -> bool {
            if u == matchsticks.len() {
                return true;
            }
            for i in 0..4 {
                if i > 0 && edges[i - 1] == edges[i] {
                    continue;
                }
                edges[i] += matchsticks[u];
                if edges[i] <= x && dfs(matchsticks, edges, u + 1, x) {
                    return true;
                }
                edges[i] -= matchsticks[u];
            }
            false
        }

        let sum: i32 = matchsticks.iter().sum();
        if sum % 4 != 0 {
            return false;
        }
        matchsticks.sort_by(|x, y| y.cmp(x));
        let mut edges = [0; 4];

        dfs(&matchsticks, &mut edges, 0, sum / 4)
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：状态压缩 + 记忆化搜索

记当前火柴被划分的情况为 $state$。对于第 $i$ 个数，若 $state \ \& \ (1<<i)=0$，说明第 $i$ 个火柴棒未被划分。我们的目标是从全部数字中凑出 $k$ 个和为 $s$ 的子集。

记当前子集的和为 $t$。在未划分第 $i$ 个火柴棒时：

-   若 $t+matchsticks[i]>s$，说明第 $i$ 个火柴棒不能被添加到当前子集中，由于我们对 $matchsticks$ 数组进行升序排列，因此从 $matchsticks$ 从第 $i$ 个火柴棒开始的所有数字都不能被添加到当前子集，直接返回 $false$。
-   否则，将第 $i$ 个火柴棒添加到当前子集中，状态变为 $state \ |\ (1<<i)$，继续对未划分的数字进行搜索。

注：若 $t+matchsticks[i]==s$，说明恰好可以得到一个和为 $s$ 的子集，下一步将 $t$ 归零（可以通过 $(t+matchsticks[i]) \%s$ 实现），并继续划分下一个子集。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def makesquare(self, matchsticks: List[int]) -> bool:
        @cache
        def dfs(state, t):
            if state == (1 << len(matchsticks)) - 1:
                return True
            for i, v in enumerate(matchsticks):
                if state & (1 << i):
                    continue
                if t + v > s:
                    break
                if dfs(state | (1 << i), (t + v) % s):
                    return True
            return False

        s, mod = divmod(sum(matchsticks), 4)
        matchsticks.sort()
        if mod:
            return False
        return dfs(0, 0)
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [474. 一和零](https://leetcode.cn/problems/ones-and-zeroes){#474}

{{< tabs "474" >}}

{{% tab "python" %}}
```python
class Solution:
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        f = [[0] * (n + 1) for _ in range(m + 1)]
        for s in strs:
            a, b = s.count("0"), s.count("1")
            for i in range(m, a - 1, -1):
                for j in range(n, b - 1, -1):
                    f[i][j] = max(f[i][j], f[i - a][j - b] + 1)
        return f[m][n]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int findMaxForm(String[] strs, int m, int n) {
        int[][] f = new int[m + 1][n + 1];
        for (String s : strs) {
            int[] cnt = count(s);
            for (int i = m; i >= cnt[0]; --i) {
                for (int j = n; j >= cnt[1]; --j) {
                    f[i][j] = Math.max(f[i][j], f[i - cnt[0]][j - cnt[1]] + 1);
                }
            }
        }
        return f[m][n];
    }

    private int[] count(String s) {
        int[] cnt = new int[2];
        for (int i = 0; i < s.length(); ++i) {
            ++cnt[s.charAt(i) - '0'];
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
    int findMaxForm(vector<string>& strs, int m, int n) {
        int f[m + 1][n + 1];
        memset(f, 0, sizeof(f));
        for (auto& s : strs) {
            auto [a, b] = count(s);
            for (int i = m; i >= a; --i) {
                for (int j = n; j >= b; --j) {
                    f[i][j] = max(f[i][j], f[i - a][j - b] + 1);
                }
            }
        }
        return f[m][n];
    }

    pair<int, int> count(string& s) {
        int a = count_if(s.begin(), s.end(), [](char c) { return c == '0'; });
        return {a, s.size() - a};
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findMaxForm(strs []string, m int, n int) int {
	f := make([][]int, m+1)
	for i := range f {
		f[i] = make([]int, n+1)
	}
	for _, s := range strs {
		a, b := count(s)
		for j := m; j >= a; j-- {
			for k := n; k >= b; k-- {
				f[j][k] = max(f[j][k], f[j-a][k-b]+1)
			}
		}
	}
	return f[m][n]
}

func count(s string) (int, int) {
	a := strings.Count(s, "0")
	return a, len(s) - a
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findMaxForm(strs: string[], m: number, n: number): number {
    const f = Array.from({ length: m + 1 }, () => Array.from({ length: n + 1 }, () => 0));
    const count = (s: string): [number, number] => {
        let a = 0;
        for (const c of s) {
            a += c === '0' ? 1 : 0;
        }
        return [a, s.length - a];
    };
    for (const s of strs) {
        const [a, b] = count(s);
        for (let i = m; i >= a; --i) {
            for (let j = n; j >= b; --j) {
                f[i][j] = Math.max(f[i][j], f[i - a][j - b] + 1);
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

<p>给你一个二进制字符串数组 <code>strs</code> 和两个整数 <code>m</code> 和 <code>n</code> 。</p>

<div class="MachineTrans-Lines">
<p class="MachineTrans-lang-zh-CN">请你找出并返回 <code>strs</code> 的最大子集的长度，该子集中 <strong>最多</strong> 有 <code>m</code> 个 <code>0</code> 和 <code>n</code> 个 <code>1</code> 。</p>

<p class="MachineTrans-lang-zh-CN">如果 <code>x</code> 的所有元素也是 <code>y</code> 的元素，集合 <code>x</code> 是集合 <code>y</code> 的 <strong>子集</strong> 。</p>
</div>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>strs = ["10", "0001", "111001", "1", "0"], m = 5, n = 3
<strong>输出：</strong>4
<strong>解释：</strong>最多有 5 个 0 和 3 个 1 的最大子集是 {"10","0001","1","0"} ，因此答案是 4 。
其他满足题意但较小的子集包括 {"0001","1"} 和 {"10","1","0"} 。{"111001"} 不满足题意，因为它含 4 个 1 ，大于 n 的值 3 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>strs = ["10", "0", "1"], m = 1, n = 1
<strong>输出：</strong>2
<strong>解释：</strong>最大的子集是 {"0", "1"} ，所以答案是 2 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= strs.length &lt;= 600</code></li>
	<li><code>1 &lt;= strs[i].length &lt;= 100</code></li>
	<li><code>strs[i]</code>&nbsp;仅由&nbsp;<code>'0'</code> 和&nbsp;<code>'1'</code> 组成</li>
	<li><code>1 &lt;= m, n &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i][j][k]$ 表示在前 $i$ 个字符串中，使用 $j$ 个 0 和 $k$ 个 1 的情况下最多可以得到的字符串数量。初始时 $f[i][j][k]=0$，答案为 $f[sz][m][n]$，其中 $sz$ 是数组 $strs$ 的长度。

对于 $f[i][j][k]$，我们有两种决策：

-   不选第 $i$ 个字符串，此时 $f[i][j][k]=f[i-1][j][k]$；
-   选第 $i$ 个字符串，此时 $f[i][j][k]=f[i-1][j-a][k-b]+1$，其中 $a$ 和 $b$ 分别是第 $i$ 个字符串中 $0$ 和 $1$ 的数量。

我们取两种决策中的最大值，即可得到 $f[i][j][k]$ 的值。

最终的答案即为 $f[sz][m][n]$。

时间复杂度 $O(sz \times m \times n)$，空间复杂度 $O(sz \times m \times n)$。其中 $sz$ 是数组 $strs$ 的长度；而 $m$ 和 $n$ 分别是字符串中 $0$ 和 $1$ 的数量上限。

我们注意到 $f[i][j][k]$ 的计算只和 $f[i-1][j][k]$ 以及 $f[i-1][j-a][k-b]$ 有关，因此我们可以去掉第一维，将空间复杂度优化到 $O(m \times n)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        sz = len(strs)
        f = [[[0] * (n + 1) for _ in range(m + 1)] for _ in range(sz + 1)]
        for i, s in enumerate(strs, 1):
            a, b = s.count("0"), s.count("1")
            for j in range(m + 1):
                for k in range(n + 1):
                    f[i][j][k] = f[i - 1][j][k]
                    if j >= a and k >= b:
                        f[i][j][k] = max(f[i][j][k], f[i - 1][j - a][k - b] + 1)
        return f[sz][m][n]
```

#### Java

```java
class Solution {
    public int findMaxForm(String[] strs, int m, int n) {
        int sz = strs.length;
        int[][][] f = new int[sz + 1][m + 1][n + 1];
        for (int i = 1; i <= sz; ++i) {
            int[] cnt = count(strs[i - 1]);
            for (int j = 0; j <= m; ++j) {
                for (int k = 0; k <= n; ++k) {
                    f[i][j][k] = f[i - 1][j][k];
                    if (j >= cnt[0] && k >= cnt[1]) {
                        f[i][j][k] = Math.max(f[i][j][k], f[i - 1][j - cnt[0]][k - cnt[1]] + 1);
                    }
                }
            }
        }
        return f[sz][m][n];
    }

    private int[] count(String s) {
        int[] cnt = new int[2];
        for (int i = 0; i < s.length(); ++i) {
            ++cnt[s.charAt(i) - '0'];
        }
        return cnt;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz = strs.size();
        int f[sz + 1][m + 1][n + 1];
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= sz; ++i) {
            auto [a, b] = count(strs[i - 1]);
            for (int j = 0; j <= m; ++j) {
                for (int k = 0; k <= n; ++k) {
                    f[i][j][k] = f[i - 1][j][k];
                    if (j >= a && k >= b) {
                        f[i][j][k] = max(f[i][j][k], f[i - 1][j - a][k - b] + 1);
                    }
                }
            }
        }
        return f[sz][m][n];
    }

    pair<int, int> count(string& s) {
        int a = count_if(s.begin(), s.end(), [](char c) { return c == '0'; });
        return {a, s.size() - a};
    }
};
```

#### Go

```go
func findMaxForm(strs []string, m int, n int) int {
	sz := len(strs)
	f := make([][][]int, sz+1)
	for i := range f {
		f[i] = make([][]int, m+1)
		for j := range f[i] {
			f[i][j] = make([]int, n+1)
		}
	}
	for i := 1; i <= sz; i++ {
		a, b := count(strs[i-1])
		for j := 0; j <= m; j++ {
			for k := 0; k <= n; k++ {
				f[i][j][k] = f[i-1][j][k]
				if j >= a && k >= b {
					f[i][j][k] = max(f[i][j][k], f[i-1][j-a][k-b]+1)
				}
			}
		}
	}
	return f[sz][m][n]
}

func count(s string) (int, int) {
	a := strings.Count(s, "0")
	return a, len(s) - a
}
```

#### TypeScript

```ts
function findMaxForm(strs: string[], m: number, n: number): number {
    const sz = strs.length;
    const f = Array.from({ length: sz + 1 }, () =>
        Array.from({ length: m + 1 }, () => Array.from({ length: n + 1 }, () => 0)),
    );
    const count = (s: string): [number, number] => {
        let a = 0;
        for (const c of s) {
            a += c === '0' ? 1 : 0;
        }
        return [a, s.length - a];
    };
    for (let i = 1; i <= sz; ++i) {
        const [a, b] = count(strs[i - 1]);
        for (let j = 0; j <= m; ++j) {
            for (let k = 0; k <= n; ++k) {
                f[i][j][k] = f[i - 1][j][k];
                if (j >= a && k >= b) {
                    f[i][j][k] = Math.max(f[i][j][k], f[i - 1][j - a][k - b] + 1);
                }
            }
        }
    }
    return f[sz][m][n];
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
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        f = [[0] * (n + 1) for _ in range(m + 1)]
        for s in strs:
            a, b = s.count("0"), s.count("1")
            for i in range(m, a - 1, -1):
                for j in range(n, b - 1, -1):
                    f[i][j] = max(f[i][j], f[i - a][j - b] + 1)
        return f[m][n]
```

#### Java

```java
class Solution {
    public int findMaxForm(String[] strs, int m, int n) {
        int[][] f = new int[m + 1][n + 1];
        for (String s : strs) {
            int[] cnt = count(s);
            for (int i = m; i >= cnt[0]; --i) {
                for (int j = n; j >= cnt[1]; --j) {
                    f[i][j] = Math.max(f[i][j], f[i - cnt[0]][j - cnt[1]] + 1);
                }
            }
        }
        return f[m][n];
    }

    private int[] count(String s) {
        int[] cnt = new int[2];
        for (int i = 0; i < s.length(); ++i) {
            ++cnt[s.charAt(i) - '0'];
        }
        return cnt;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int f[m + 1][n + 1];
        memset(f, 0, sizeof(f));
        for (auto& s : strs) {
            auto [a, b] = count(s);
            for (int i = m; i >= a; --i) {
                for (int j = n; j >= b; --j) {
                    f[i][j] = max(f[i][j], f[i - a][j - b] + 1);
                }
            }
        }
        return f[m][n];
    }

    pair<int, int> count(string& s) {
        int a = count_if(s.begin(), s.end(), [](char c) { return c == '0'; });
        return {a, s.size() - a};
    }
};
```

#### Go

```go
func findMaxForm(strs []string, m int, n int) int {
	f := make([][]int, m+1)
	for i := range f {
		f[i] = make([]int, n+1)
	}
	for _, s := range strs {
		a, b := count(s)
		for j := m; j >= a; j-- {
			for k := n; k >= b; k-- {
				f[j][k] = max(f[j][k], f[j-a][k-b]+1)
			}
		}
	}
	return f[m][n]
}

func count(s string) (int, int) {
	a := strings.Count(s, "0")
	return a, len(s) - a
}
```

#### TypeScript

```ts
function findMaxForm(strs: string[], m: number, n: number): number {
    const f = Array.from({ length: m + 1 }, () => Array.from({ length: n + 1 }, () => 0));
    const count = (s: string): [number, number] => {
        let a = 0;
        for (const c of s) {
            a += c === '0' ? 1 : 0;
        }
        return [a, s.length - a];
    };
    for (const s of strs) {
        const [a, b] = count(s);
        for (let i = m; i >= a; --i) {
            for (let j = n; j >= b; --j) {
                f[i][j] = Math.max(f[i][j], f[i - a][j - b] + 1);
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

# [475. 供暖器](https://leetcode.cn/problems/heaters){#475}

{{< tabs "475" >}}

{{% tab "python" %}}
```python
class Solution:
    def findRadius(self, houses: List[int], heaters: List[int]) -> int:
        houses.sort()
        heaters.sort()

        def check(r):
            m, n = len(houses), len(heaters)
            i = j = 0
            while i < m:
                if j >= n:
                    return False
                mi = heaters[j] - r
                mx = heaters[j] + r
                if houses[i] < mi:
                    return False
                if houses[i] > mx:
                    j += 1
                else:
                    i += 1
            return True

        left, right = 0, int(1e9)
        while left < right:
            mid = (left + right) >> 1
            if check(mid):
                right = mid
            else:
                left = mid + 1
        return left
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int findRadius(int[] houses, int[] heaters) {
        Arrays.sort(heaters);
        int res = 0;
        for (int x : houses) {
            int i = Arrays.binarySearch(heaters, x);
            if (i < 0) {
                i = ~i;
            }
            int dis1 = i > 0 ? x - heaters[i - 1] : Integer.MAX_VALUE;
            int dis2 = i < heaters.length ? heaters[i] - x : Integer.MAX_VALUE;
            res = Math.max(res, Math.min(dis1, dis2));
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
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int left = 0, right = 1e9;
        while (left < right) {
            int mid = left + right >> 1;
            if (check(houses, heaters, mid))
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }

    bool check(vector<int>& houses, vector<int>& heaters, int r) {
        int m = houses.size(), n = heaters.size();
        int i = 0, j = 0;
        while (i < m) {
            if (j >= n) return false;
            int mi = heaters[j] - r;
            int mx = heaters[j] + r;
            if (houses[i] < mi) return false;
            if (houses[i] > mx)
                ++j;
            else
                ++i;
        }
        return true;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findRadius(houses []int, heaters []int) int {
	sort.Ints(houses)
	sort.Ints(heaters)
	m, n := len(houses), len(heaters)

	check := func(r int) bool {
		var i, j int
		for i < m {
			if j >= n {
				return false
			}
			mi, mx := heaters[j]-r, heaters[j]+r
			if houses[i] < mi {
				return false
			}
			if houses[i] > mx {
				j++
			} else {
				i++
			}
		}
		return true
	}
	left, right := 0, int(1e9)
	for left < right {
		mid := (left + right) >> 1
		if check(mid) {
			right = mid
		} else {
			left = mid + 1
		}
	}
	return left
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findRadius(houses: number[], heaters: number[]): number {
    houses.sort((a, b) => a - b);
    heaters.sort((a, b) => a - b);
    const m = houses.length,
        n = heaters.length;
    let ans = 0;
    for (let i = 0, j = 0; i < m; i++) {
        let cur = Math.abs(houses[i] - heaters[j]);
        while (
            j + 1 < n &&
            Math.abs(houses[i] - heaters[j]) >= Math.abs(houses[i] - heaters[j + 1])
        ) {
            cur = Math.min(Math.abs(houses[i] - heaters[++j]), cur);
        }
        ans = Math.max(cur, ans);
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

<p>冬季已经来临。&nbsp;你的任务是设计一个有固定加热半径的供暖器向所有房屋供暖。</p>

<p>在加热器的加热半径范围内的每个房屋都可以获得供暖。</p>

<p>现在，给出位于一条水平线上的房屋&nbsp;<code>houses</code> 和供暖器&nbsp;<code>heaters</code> 的位置，请你找出并返回可以覆盖所有房屋的最小加热半径。</p>

<p><b>注意</b>：所有供暖器 <code>heaters</code> 都遵循你的半径标准，加热的半径也一样。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> houses = [1,2,3], heaters = [2]
<strong>输出:</strong> 1
<strong>解释:</strong> 仅在位置 2 上有一个供暖器。如果我们将加热半径设为 1，那么所有房屋就都能得到供暖。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> houses = [1,2,3,4], heaters = [1,4]
<strong>输出:</strong> 1
<strong>解释:</strong> 在位置 1, 4 上有两个供暖器。我们需要将加热半径设为 1，这样所有房屋就都能得到供暖。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>houses = [1,5], heaters = [2]
<strong>输出：</strong>3
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= houses.length, heaters.length &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= houses[i], heaters[i] &lt;= 10<sup>9</sup></code></li>
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
    def findRadius(self, houses: List[int], heaters: List[int]) -> int:
        houses.sort()
        heaters.sort()

        def check(r):
            m, n = len(houses), len(heaters)
            i = j = 0
            while i < m:
                if j >= n:
                    return False
                mi = heaters[j] - r
                mx = heaters[j] + r
                if houses[i] < mi:
                    return False
                if houses[i] > mx:
                    j += 1
                else:
                    i += 1
            return True

        left, right = 0, int(1e9)
        while left < right:
            mid = (left + right) >> 1
            if check(mid):
                right = mid
            else:
                left = mid + 1
        return left
```

#### Java

```java
class Solution {
    public int findRadius(int[] houses, int[] heaters) {
        Arrays.sort(heaters);
        int res = 0;
        for (int x : houses) {
            int i = Arrays.binarySearch(heaters, x);
            if (i < 0) {
                i = ~i;
            }
            int dis1 = i > 0 ? x - heaters[i - 1] : Integer.MAX_VALUE;
            int dis2 = i < heaters.length ? heaters[i] - x : Integer.MAX_VALUE;
            res = Math.max(res, Math.min(dis1, dis2));
        }
        return res;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int left = 0, right = 1e9;
        while (left < right) {
            int mid = left + right >> 1;
            if (check(houses, heaters, mid))
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }

    bool check(vector<int>& houses, vector<int>& heaters, int r) {
        int m = houses.size(), n = heaters.size();
        int i = 0, j = 0;
        while (i < m) {
            if (j >= n) return false;
            int mi = heaters[j] - r;
            int mx = heaters[j] + r;
            if (houses[i] < mi) return false;
            if (houses[i] > mx)
                ++j;
            else
                ++i;
        }
        return true;
    }
};
```

#### Go

```go
func findRadius(houses []int, heaters []int) int {
	sort.Ints(houses)
	sort.Ints(heaters)
	m, n := len(houses), len(heaters)

	check := func(r int) bool {
		var i, j int
		for i < m {
			if j >= n {
				return false
			}
			mi, mx := heaters[j]-r, heaters[j]+r
			if houses[i] < mi {
				return false
			}
			if houses[i] > mx {
				j++
			} else {
				i++
			}
		}
		return true
	}
	left, right := 0, int(1e9)
	for left < right {
		mid := (left + right) >> 1
		if check(mid) {
			right = mid
		} else {
			left = mid + 1
		}
	}
	return left
}
```

#### TypeScript

```ts
function findRadius(houses: number[], heaters: number[]): number {
    houses.sort((a, b) => a - b);
    heaters.sort((a, b) => a - b);
    const m = houses.length,
        n = heaters.length;
    let ans = 0;
    for (let i = 0, j = 0; i < m; i++) {
        let cur = Math.abs(houses[i] - heaters[j]);
        while (
            j + 1 < n &&
            Math.abs(houses[i] - heaters[j]) >= Math.abs(houses[i] - heaters[j + 1])
        ) {
            cur = Math.min(Math.abs(houses[i] - heaters[++j]), cur);
        }
        ans = Math.max(cur, ans);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [476. 数字的补数](https://leetcode.cn/problems/number-complement){#476}

{{< tabs "476" >}}

{{% tab "python" %}}
```python
class Solution:
    def findComplement(self, num: int) -> int:
        return num ^ ((1 << num.bit_length()) - 1)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int findComplement(int num) {
        return num ^ ((1 << (32 - Integer.numberOfLeadingZeros(num))) - 1);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int findComplement(int num) {
        return num ^ ((1LL << (64 - __builtin_clzll(num))) - 1);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findComplement(num int) int {
	return num ^ ((1 << bits.Len(uint(num))) - 1)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findComplement(num: number): number {
    return ~num & (2 ** num.toString(2).length - 1);
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number} num
 * @return {number}
 */
function findComplement(num) {
    return ~num & (2 ** num.toString(2).length - 1);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>对整数的二进制表示取反（<code>0</code> 变 <code>1</code> ，<code>1</code> 变 <code>0</code>）后，再转换为十进制表示，可以得到这个整数的补数。</p>

<ul>
	<li>例如，整数 <code>5</code> 的二进制表示是 <code>"101"</code> ，取反后得到 <code>"010"</code> ，再转回十进制表示得到补数 <code>2</code> 。</li>
</ul>

<p>给你一个整数 <code>num</code> ，输出它的补数。</p>

<p>&nbsp;</p>

<ol>
</ol>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>num = 5
<strong>输出：</strong>2
<strong>解释：</strong>5 的二进制表示为 101（没有前导零位），其补数为 010。所以你需要输出 2 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>num = 1
<strong>输出：</strong>0
<strong>解释：</strong>1 的二进制表示为 1（没有前导零位），其补数为 0。所以你需要输出 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= num &lt; 2<sup>31</sup></code></li>
</ul>

<p>&nbsp;</p>

<p><strong>注意：</strong>本题与 1009 <a href="https://leetcode.cn/problems/complement-of-base-10-integer/">https://leetcode.cn/problems/complement-of-base-10-integer/</a> 相同</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：位运算

根据题目描述，我们可以通过异或运算来实现取反的操作，步骤如下：

我们首先找到 $\textit{num}$ 的二进制表示中最高位的 $1$，位置记为 $k$。

然后，构造一个二进制数，第 $k$ 位为 $0$，其余低位为 $1$，即 $2^k - 1$；

最后，将 $\textit{num}$ 与上述构造的二进制数进行异或运算，即可得到答案。

时间复杂度 $O(\log \textit{num})$，其中 $\textit{num}$ 为输入的整数。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findComplement(self, num: int) -> int:
        return num ^ ((1 << num.bit_length()) - 1)
```

#### Java

```java
class Solution {
    public int findComplement(int num) {
        return num ^ ((1 << (32 - Integer.numberOfLeadingZeros(num))) - 1);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int findComplement(int num) {
        return num ^ ((1LL << (64 - __builtin_clzll(num))) - 1);
    }
};
```

#### Go

```go
func findComplement(num int) int {
	return num ^ ((1 << bits.Len(uint(num))) - 1)
}
```

#### TypeScript

```ts
function findComplement(num: number): number {
    return num ^ (2 ** num.toString(2).length - 1);
}
```

#### JavaScript

```js
/**
 * @param {number} num
 * @return {number}
 */
var findComplement = function (num) {
    return num ^ (2 ** num.toString(2).length - 1);
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：位运算（取反+按位与）

<!-- tabs:start -->

#### TypeScript

```ts
function findComplement(num: number): number {
    return ~num & (2 ** num.toString(2).length - 1);
}
```

#### JavaScript

```js
/**
 * @param {number} num
 * @return {number}
 */
function findComplement(num) {
    return ~num & (2 ** num.toString(2).length - 1);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [477. 汉明距离总和](https://leetcode.cn/problems/total-hamming-distance){#477}

{{< tabs "477" >}}

{{% tab "python" %}}
```python
class Solution:
    def totalHammingDistance(self, nums: List[int]) -> int:
        ans, n = 0, len(nums)
        for i in range(32):
            a = sum(x >> i & 1 for x in nums)
            b = n - a
            ans += a * b
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int totalHammingDistance(int[] nums) {
        int ans = 0, n = nums.length;
        for (int i = 0; i < 32; ++i) {
            int a = 0;
            for (int x : nums) {
                a += (x >> i & 1);
            }
            int b = n - a;
            ans += a * b;
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
    int totalHammingDistance(vector<int>& nums) {
        int ans = 0, n = nums.size();
        for (int i = 0; i < 32; ++i) {
            int a = 0;
            for (int x : nums) {
                a += x >> i & 1;
            }
            int b = n - a;
            ans += a * b;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func totalHammingDistance(nums []int) (ans int) {
	for i := 0; i < 32; i++ {
		a := 0
		for _, x := range nums {
			a += x >> i & 1
		}
		b := len(nums) - a
		ans += a * b
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function totalHammingDistance(nums: number[]): number {
    let ans = 0;
    for (let i = 0; i < 32; ++i) {
        const a = nums.filter(x => (x >> i) & 1).length;
        const b = nums.length - a;
        ans += a * b;
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn total_hamming_distance(nums: Vec<i32>) -> i32 {
        let mut ans = 0;
        for i in 0..32 {
            let mut a = 0;
            for &x in nums.iter() {
                a += (x >> i) & 1;
            }
            let b = (nums.len() as i32) - a;
            ans += a * b;
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

<p>两个整数的&nbsp;<a href="https://baike.baidu.com/item/%E6%B1%89%E6%98%8E%E8%B7%9D%E7%A6%BB/475174?fr=aladdin">汉明距离</a> 指的是这两个数字的二进制数对应位不同的数量。</p>

<p>给你一个整数数组 <code>nums</code>，请你计算并返回 <code>nums</code> 中任意两个数之间 <strong>汉明距离的总和</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [4,14,2]
<strong>输出：</strong>6
<strong>解释：</strong>在二进制表示中，4 表示为 0100 ，14 表示为 1110 ，2表示为 0010 。（这样表示是为了体现后四位之间关系）
所以答案为：
HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [4,14,4]
<strong>输出：</strong>4
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li>给定输入的对应答案符合 <strong>32-bit</strong> 整数范围</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：位运算

我们在 $[0, 31]$ 的范围内枚举每一位，对于当前枚举的位 $i$，我们统计所有数字中的第 $i$ 位为 $1$ 的个数 $a$，那么这些数字中的第 $i$ 位为 $0$ 的个数就是 $b = n - a$，其中 $n$ 是数组的长度。这样的话，在第 $i$ 位上的汉明距离之和就是 $a \times b$，我们把所有的位的汉明距离相加即为答案。

时间复杂度 $O(n \times \log M)$，其中 $n$ 和 $M$ 分别是数组的长度和数组中的元素的最大值。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def totalHammingDistance(self, nums: List[int]) -> int:
        ans, n = 0, len(nums)
        for i in range(32):
            a = sum(x >> i & 1 for x in nums)
            b = n - a
            ans += a * b
        return ans
```

#### Java

```java
class Solution {
    public int totalHammingDistance(int[] nums) {
        int ans = 0, n = nums.length;
        for (int i = 0; i < 32; ++i) {
            int a = 0;
            for (int x : nums) {
                a += (x >> i & 1);
            }
            int b = n - a;
            ans += a * b;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ans = 0, n = nums.size();
        for (int i = 0; i < 32; ++i) {
            int a = 0;
            for (int x : nums) {
                a += x >> i & 1;
            }
            int b = n - a;
            ans += a * b;
        }
        return ans;
    }
};
```

#### Go

```go
func totalHammingDistance(nums []int) (ans int) {
	for i := 0; i < 32; i++ {
		a := 0
		for _, x := range nums {
			a += x >> i & 1
		}
		b := len(nums) - a
		ans += a * b
	}
	return
}
```

#### TypeScript

```ts
function totalHammingDistance(nums: number[]): number {
    let ans = 0;
    for (let i = 0; i < 32; ++i) {
        const a = nums.filter(x => (x >> i) & 1).length;
        const b = nums.length - a;
        ans += a * b;
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn total_hamming_distance(nums: Vec<i32>) -> i32 {
        let mut ans = 0;
        for i in 0..32 {
            let mut a = 0;
            for &x in nums.iter() {
                a += (x >> i) & 1;
            }
            let b = (nums.len() as i32) - a;
            ans += a * b;
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

# [478. 在圆内随机生成点](https://leetcode.cn/problems/generate-random-point-in-a-circle){#478}

{{< tabs "478" >}}

{{% tab "python" %}}
```python
class Solution:
    def __init__(self, radius: float, x_center: float, y_center: float):
        self.radius = radius
        self.x_center = x_center
        self.y_center = y_center

    def randPoint(self) -> List[float]:
        length = math.sqrt(random.uniform(0, self.radius**2))
        degree = random.uniform(0, 1) * 2 * math.pi
        x = self.x_center + length * math.cos(degree)
        y = self.y_center + length * math.sin(degree)
        return [x, y]
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定圆的半径和圆心的位置，实现函数 <code>randPoint</code> ，在圆中产生均匀随机点。</p>

<p>实现&nbsp;<code>Solution</code>&nbsp;类:</p>

<ul>
	<li><code>Solution(double radius, double x_center, double y_center)</code>&nbsp;用圆的半径&nbsp;<code>radius</code>&nbsp;和圆心的位置<code> (x_center, y_center)</code> 初始化对象</li>
	<li><code>randPoint()</code>&nbsp;返回圆内的一个随机点。圆周上的一点被认为在圆内。答案作为数组返回 <code>[x, y]</code> 。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入: 
</strong>["Solution","randPoint","randPoint","randPoint"]
[[1.0, 0.0, 0.0], [], [], []]
<strong>输出: </strong>[null, [-0.02493, -0.38077], [0.82314, 0.38945], [0.36572, 0.17248]]
<strong>解释:</strong>
Solution solution = new Solution(1.0, 0.0, 0.0);
solution.randPoint ();//返回[-0.02493，-0.38077]
solution.randPoint ();//返回[0.82314,0.38945]
solution.randPoint ();//返回[0.36572,0.17248]</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;&nbsp;radius &lt;= 10<sup>8</sup></code></li>
	<li><code>-10<sup>7</sup>&nbsp;&lt;= x_center, y_center &lt;= 10<sup>7</sup></code></li>
	<li><code>randPoint</code> 最多被调用&nbsp;<code>3 * 10<sup>4</sup></code>&nbsp;次</li>
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
    def __init__(self, radius: float, x_center: float, y_center: float):
        self.radius = radius
        self.x_center = x_center
        self.y_center = y_center

    def randPoint(self) -> List[float]:
        length = math.sqrt(random.uniform(0, self.radius**2))
        degree = random.uniform(0, 1) * 2 * math.pi
        x = self.x_center + length * math.cos(degree)
        y = self.y_center + length * math.sin(degree)
        return [x, y]
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [479. 最大回文数乘积](https://leetcode.cn/problems/largest-palindrome-product){#479}

{{< tabs "479" >}}

{{% tab "python" %}}
```python
class Solution:
    def largestPalindrome(self, n: int) -> int:
        mx = 10**n - 1
        for a in range(mx, mx // 10, -1):
            b = x = a
            while b:
                x = x * 10 + b % 10
                b //= 10
            t = mx
            while t * t >= x:
                if x % t == 0:
                    return x % 1337
                t -= 1
        return 9
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int largestPalindrome(int n) {
        int mx = (int) Math.pow(10, n) - 1;
        for (int a = mx; a > mx / 10; --a) {
            int b = a;
            long x = a;
            while (b != 0) {
                x = x * 10 + b % 10;
                b /= 10;
            }
            for (long t = mx; t * t >= x; --t) {
                if (x % t == 0) {
                    return (int) (x % 1337);
                }
            }
        }
        return 9;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int largestPalindrome(int n) {
        int mx = pow(10, n) - 1;
        for (int a = mx; a > mx / 10; --a) {
            int b = a;
            long x = a;
            while (b) {
                x = x * 10 + b % 10;
                b /= 10;
            }
            for (long t = mx; t * t >= x; --t)
                if (x % t == 0)
                    return x % 1337;
        }
        return 9;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func largestPalindrome(n int) int {
	mx := int(math.Pow10(n)) - 1
	for a := mx; a > mx/10; a-- {
		x := a
		for b := a; b != 0; b /= 10 {
			x = x*10 + b%10
		}
		for t := mx; t*t >= x; t-- {
			if x%t == 0 {
				return x % 1337
			}
		}
	}
	return 9
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个整数 n ，返回 <em>可表示为两个 <code>n</code>&nbsp;位整数乘积的 <strong>最大回文整数</strong></em> 。因为答案可能非常大，所以返回它对 <code>1337</code> <strong>取余</strong> 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 2
<strong>输出：</strong>987
<strong>解释：</strong>99 x 91 = 9009, 9009 % 1337 = 987
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 1
<strong>输出：</strong>9
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 8</code></li>
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
    def largestPalindrome(self, n: int) -> int:
        mx = 10**n - 1
        for a in range(mx, mx // 10, -1):
            b = x = a
            while b:
                x = x * 10 + b % 10
                b //= 10
            t = mx
            while t * t >= x:
                if x % t == 0:
                    return x % 1337
                t -= 1
        return 9
```

#### Java

```java
class Solution {
    public int largestPalindrome(int n) {
        int mx = (int) Math.pow(10, n) - 1;
        for (int a = mx; a > mx / 10; --a) {
            int b = a;
            long x = a;
            while (b != 0) {
                x = x * 10 + b % 10;
                b /= 10;
            }
            for (long t = mx; t * t >= x; --t) {
                if (x % t == 0) {
                    return (int) (x % 1337);
                }
            }
        }
        return 9;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int largestPalindrome(int n) {
        int mx = pow(10, n) - 1;
        for (int a = mx; a > mx / 10; --a) {
            int b = a;
            long x = a;
            while (b) {
                x = x * 10 + b % 10;
                b /= 10;
            }
            for (long t = mx; t * t >= x; --t)
                if (x % t == 0)
                    return x % 1337;
        }
        return 9;
    }
};
```

#### Go

```go
func largestPalindrome(n int) int {
	mx := int(math.Pow10(n)) - 1
	for a := mx; a > mx/10; a-- {
		x := a
		for b := a; b != 0; b /= 10 {
			x = x*10 + b%10
		}
		for t := mx; t*t >= x; t-- {
			if x%t == 0 {
				return x % 1337
			}
		}
	}
	return 9
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
