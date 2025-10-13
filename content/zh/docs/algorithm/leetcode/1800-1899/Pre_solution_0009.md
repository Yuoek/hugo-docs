---
title: "1880_检查某单词是否等于两单词之和"
date: 2025-10-08T18:38:27+08:00
weight: 9
tags: [二分查找, 前缀和, 动态规划, 双指针, 堆（优先队列）, 字符串, 排序, 数学, 数组, 滑动窗口, 矩阵, 贪心]
---

{{< markmap >}}
### [1880_检查某单词是否等于两单词之和](#1880)
#### [字符串](#1880)
### [1881_插入后的最大值](#1881)
#### [贪心](#1881)
#### [字符串](#1881)
### [1882_使用服务器处理任务](#1882)
#### [数组](#1882)
#### [堆（优先队列）](#1882)
### [1883_准时抵达会议现场的最小跳过休息次数](#1883)
#### [数组](#1883)
#### [动态规划](#1883)
### [1884_鸡蛋掉落-两枚鸡蛋](#1884)
#### [数学](#1884)
#### [动态规划](#1884)
### [1885_统计数对 🔒](#1885)
#### [数组](#1885)
#### [双指针](#1885)
#### [二分查找](#1885)
#### [排序](#1885)
### [1886_判断矩阵经轮转后是否一致](#1886)
#### [数组](#1886)
#### [矩阵](#1886)
### [1887_使数组元素相等的减少操作次数](#1887)
#### [数组](#1887)
#### [排序](#1887)
### [1888_使二进制字符串字符交替的最少反转次数](#1888)
#### [字符串](#1888)
#### [动态规划](#1888)
#### [滑动窗口](#1888)
### [1889_装包裹的最小浪费空间](#1889)
#### [数组](#1889)
#### [二分查找](#1889)
#### [前缀和](#1889)
#### [排序](#1889)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1880_检查某单词是否等于两单词之和
___
#### 字符串
---
### 1881_插入后的最大值
___
#### 贪心
___
#### 字符串
---
### 1882_使用服务器处理任务
___
#### 数组
___
#### 堆（优先队列）
---
### 1883_准时抵达会议现场的最小跳过休息次数
___
#### 数组
___
#### 动态规划
---
### 1884_鸡蛋掉落-两枚鸡蛋
___
#### 数学
___
#### 动态规划
---
### 1885_统计数对 🔒
___
#### 数组
___
#### 双指针
___
#### 二分查找
___
#### 排序
---
### 1886_判断矩阵经轮转后是否一致
___
#### 数组
___
#### 矩阵
---
### 1887_使数组元素相等的减少操作次数
___
#### 数组
___
#### 排序
---
### 1888_使二进制字符串字符交替的最少反转次数
___
#### 字符串
___
#### 动态规划
___
#### 滑动窗口
---
### 1889_装包裹的最小浪费空间
___
#### 数组
___
#### 二分查找
___
#### 前缀和
___
#### 排序
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 前缀和 | 动态规划 |
| 双指针 | 堆（优先队列） | 字符串 |
| 排序 | 数学 | 数组 |
| 滑动窗口 | 矩阵 | 贪心 |

# [1880. 检查某单词是否等于两单词之和](https://leetcode.cn/problems/check-if-word-equals-summation-of-two-words){#1880}

{{< tabs "1880" >}}

{{% tab "python" %}}
```python
class Solution:
    def isSumEqual(self, firstWord: str, secondWord: str, targetWord: str) -> bool:
        def f(s: str) -> int:
            ans, a = 0, ord("a")
            for c in map(ord, s):
                x = c - a
                ans = ans * 10 + x
            return ans

        return f(firstWord) + f(secondWord) == f(targetWord)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean isSumEqual(String firstWord, String secondWord, String targetWord) {
        return f(firstWord) + f(secondWord) == f(targetWord);
    }

    private int f(String s) {
        int ans = 0;
        for (char c : s.toCharArray()) {
            ans = ans * 10 + (c - 'a');
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
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        auto f = [](string& s) -> int {
            int ans = 0;
            for (char c : s) {
                ans = ans * 10 + (c - 'a');
            }
            return ans;
        };
        return f(firstWord) + f(secondWord) == f(targetWord);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func isSumEqual(firstWord string, secondWord string, targetWord string) bool {
	f := func(s string) (ans int) {
		for _, c := range s {
			ans = ans*10 + int(c-'a')
		}
		return
	}
	return f(firstWord)+f(secondWord) == f(targetWord)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function isSumEqual(firstWord: string, secondWord: string, targetWord: string): boolean {
    const f = (s: string): number => {
        let ans = 0;
        for (const c of s) {
            ans = ans * 10 + c.charCodeAt(0) - 97;
        }
        return ans;
    };
    return f(firstWord) + f(secondWord) == f(targetWord);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn is_sum_equal(first_word: String, second_word: String, target_word: String) -> bool {
        fn f(s: &str) -> i64 {
            let mut ans = 0;
            let a = 'a' as i64;
            for c in s.chars() {
                let x = c as i64 - a;
                ans = ans * 10 + x;
            }
            ans
        }
        f(&first_word) + f(&second_word) == f(&target_word)
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {string} firstWord
 * @param {string} secondWord
 * @param {string} targetWord
 * @return {boolean}
 */
var isSumEqual = function (firstWord, secondWord, targetWord) {
    const f = s => {
        let ans = 0;
        for (const c of s) {
            ans = ans * 10 + c.charCodeAt(0) - 97;
        }
        return ans;
    };
    return f(firstWord) + f(secondWord) == f(targetWord);
};
```
{{% /tab %}}
{{% tab "c" %}}
```c
int f(const char* s) {
    int ans = 0;
    while (*s) {
        ans = ans * 10 + (*s - 'a');
        s++;
    }
    return ans;
}

bool isSumEqual(char* firstWord, char* secondWord, char* targetWord) {
    return f(firstWord) + f(secondWord) == f(targetWord);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>字母的 <strong>字母值</strong> 取决于字母在字母表中的位置，<strong>从 0 开始</strong> 计数。即，<code>'a' -&gt; 0</code>、<code>'b' -&gt; 1</code>、<code>'c' -&gt; 2</code>，以此类推。</p>

<p>对某个由小写字母组成的字符串 <code>s</code> 而言，其 <strong>数值</strong> 就等于将 <code>s</code> 中每个字母的 <strong>字母值</strong> 按顺序 <strong>连接</strong> 并 <strong>转换</strong> 成对应整数。</p>

<ul>
	<li>例如，<code>s = "acb"</code> ，依次连接每个字母的字母值可以得到 <code>"021"</code> ，转换为整数得到 <code>21</code> 。</li>
</ul>

<p>给你三个字符串 <code>firstWord</code>、<code>secondWord</code> 和 <code>targetWord</code> ，每个字符串都由从 <code>'a'</code> 到 <code>'j'</code> （<strong>含 </strong><code>'a'</code> 和 <code>'j'</code><strong> </strong>）的小写英文字母组成。</p>

<p>如果 <code>firstWord</code><em> </em>和<em> </em><code>secondWord</code> 的 <strong>数值之和</strong> 等于<em> </em><code>targetWord</code><em> </em>的数值，返回 <code>true</code> ；否则，返回<em> </em><code>false</code><em> </em>。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>firstWord = "acb", secondWord = "cba", targetWord = "cdb"
<strong>输出：</strong>true
<strong>解释：</strong>
firstWord 的数值为 "acb" -&gt; "021" -&gt; 21
secondWord 的数值为 "cba" -&gt; "210" -&gt; 210
targetWord 的数值为 "cdb" -&gt; "231" -&gt; 231
由于 21 + 210 == 231 ，返回 true
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>firstWord = "aaa", secondWord = "a", targetWord = "aab"
<strong>输出：</strong>false
<strong>解释：</strong>
firstWord 的数值为 "aaa" -&gt; "000" -&gt; 0
secondWord 的数值为 "a" -&gt; "0" -&gt; 0
targetWord 的数值为 "aab" -&gt; "001" -&gt; 1
由于 0 + 0 != 1 ，返回 false</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>firstWord = "aaa", secondWord = "a", targetWord = "aaaa"
<strong>输出：</strong>true
<strong>解释：</strong>
firstWord 的数值为 "aaa" -&gt; "000" -&gt; 0
secondWord 的数值为 "a" -&gt; "0" -&gt; 0
targetWord 的数值为 "aaaa" -&gt; "0000" -&gt; 0
由于 0 + 0 == 0 ，返回 true
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= firstWord.length, </code><code>secondWord.length, </code><code>targetWord.length &lt;= 8</code></li>
	<li><code>firstWord</code>、<code>secondWord</code> 和 <code>targetWord</code> 仅由从 <code>'a'</code> 到 <code>'j'</code> （<strong>含 </strong><code>'a'</code> 和 <code>'j'</code><strong> </strong>）的小写英文字母组成<strong>。</strong></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：字符串转数字

我们定义一个函数 $\textit{f}(s)$，用来计算字符串 $s$ 的数值。对于字符串 $s$ 中的每个字符 $c$，我们将其转换为对应的数字 $x$，然后将 $x$ 依次连接起来，最后转换为整数。

最后，我们只需要判断 $\textit{f}(\textit{firstWord}) + \textit{f}(\textit{secondWord})$ 是否等于 $\textit{f}(\textit{targetWord})$ 即可。

时间复杂度 $O(L)$，其中 $L$ 为题目中所有字符串的长度之和。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def isSumEqual(self, firstWord: str, secondWord: str, targetWord: str) -> bool:
        def f(s: str) -> int:
            ans, a = 0, ord("a")
            for c in map(ord, s):
                x = c - a
                ans = ans * 10 + x
            return ans

        return f(firstWord) + f(secondWord) == f(targetWord)
```

#### Java

```java
class Solution {
    public boolean isSumEqual(String firstWord, String secondWord, String targetWord) {
        return f(firstWord) + f(secondWord) == f(targetWord);
    }

    private int f(String s) {
        int ans = 0;
        for (char c : s.toCharArray()) {
            ans = ans * 10 + (c - 'a');
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        auto f = [](string& s) -> int {
            int ans = 0;
            for (char c : s) {
                ans = ans * 10 + (c - 'a');
            }
            return ans;
        };
        return f(firstWord) + f(secondWord) == f(targetWord);
    }
};
```

#### Go

```go
func isSumEqual(firstWord string, secondWord string, targetWord string) bool {
	f := func(s string) (ans int) {
		for _, c := range s {
			ans = ans*10 + int(c-'a')
		}
		return
	}
	return f(firstWord)+f(secondWord) == f(targetWord)
}
```

#### TypeScript

```ts
function isSumEqual(firstWord: string, secondWord: string, targetWord: string): boolean {
    const f = (s: string): number => {
        let ans = 0;
        for (const c of s) {
            ans = ans * 10 + c.charCodeAt(0) - 97;
        }
        return ans;
    };
    return f(firstWord) + f(secondWord) == f(targetWord);
}
```

#### Rust

```rust
impl Solution {
    pub fn is_sum_equal(first_word: String, second_word: String, target_word: String) -> bool {
        fn f(s: &str) -> i64 {
            let mut ans = 0;
            let a = 'a' as i64;
            for c in s.chars() {
                let x = c as i64 - a;
                ans = ans * 10 + x;
            }
            ans
        }
        f(&first_word) + f(&second_word) == f(&target_word)
    }
}
```

#### JavaScript

```js
/**
 * @param {string} firstWord
 * @param {string} secondWord
 * @param {string} targetWord
 * @return {boolean}
 */
var isSumEqual = function (firstWord, secondWord, targetWord) {
    const f = s => {
        let ans = 0;
        for (const c of s) {
            ans = ans * 10 + c.charCodeAt(0) - 97;
        }
        return ans;
    };
    return f(firstWord) + f(secondWord) == f(targetWord);
};
```

#### C

```c
int f(const char* s) {
    int ans = 0;
    while (*s) {
        ans = ans * 10 + (*s - 'a');
        s++;
    }
    return ans;
}

bool isSumEqual(char* firstWord, char* secondWord, char* targetWord) {
    return f(firstWord) + f(secondWord) == f(targetWord);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1881. 插入后的最大值](https://leetcode.cn/problems/maximum-value-after-insertion){#1881}

{{< tabs "1881" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxValue(self, n: str, x: int) -> str:
        i = 0
        if n[0] == "-":
            i += 1
            while i < len(n) and int(n[i]) <= x:
                i += 1
        else:
            while i < len(n) and int(n[i]) >= x:
                i += 1
        return n[:i] + str(x) + n[i:]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String maxValue(String n, int x) {
        int i = 0;
        if (n.charAt(0) == '-') {
            ++i;
            while (i < n.length() && n.charAt(i) - '0' <= x) {
                ++i;
            }
        } else {
            while (i < n.length() && n.charAt(i) - '0' >= x) {
                ++i;
            }
        }
        return n.substring(0, i) + x + n.substring(i);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string maxValue(string n, int x) {
        int i = 0;
        if (n[0] == '-') {
            ++i;
            while (i < n.size() && n[i] - '0' <= x) {
                ++i;
            }
        } else {
            while (i < n.size() && n[i] - '0' >= x) {
                ++i;
            }
        }
        n.insert(i, 1, x + '0');
        return n;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxValue(n string, x int) string {
	i := 0
	y := byte('0' + x)
	if n[0] == '-' {
		i++
		for i < len(n) && n[i] <= y {
			i++
		}
	} else {
		for i < len(n) && n[i] >= y {
			i++
		}
	}
	return n[:i] + string(y) + n[i:]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxValue(n: string, x: number): string {
    let i = 0;
    if (n[0] === '-') {
        i++;
        while (i < n.length && +n[i] <= x) {
            i++;
        }
    } else {
        while (i < n.length && +n[i] >= x) {
            i++;
        }
    }
    return n.slice(0, i) + x + n.slice(i);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn max_value(n: String, x: i32) -> String {
        let s = n.as_bytes();
        let mut i = 0;
        if n.starts_with('-') {
            i += 1;
            while i < s.len() && (s[i] - b'0') as i32 <= x {
                i += 1;
            }
        } else {
            while i < s.len() && (s[i] - b'0') as i32 >= x {
                i += 1;
            }
        }
        let mut ans = String::new();
        ans.push_str(&n[0..i]);
        ans.push_str(&x.to_string());
        ans.push_str(&n[i..]);
        ans
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {string} n
 * @param {number} x
 * @return {string}
 */
var maxValue = function (n, x) {
    let i = 0;
    if (n[0] === '-') {
        i++;
        while (i < n.length && +n[i] <= x) {
            i++;
        }
    } else {
        while (i < n.length && +n[i] >= x) {
            i++;
        }
    }
    return n.slice(0, i) + x + n.slice(i);
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个非常大的整数 <code>n</code> 和一个整数数字 <code>x</code> ，大整数 <code>n</code> 用一个字符串表示。<code>n</code> 中每一位数字和数字 <code>x</code> 都处于闭区间 <code>[1, 9]</code> 中，且 <code>n</code> 可能表示一个 <strong>负数</strong> 。</p>

<p>你打算通过在 <code>n</code> 的十进制表示的任意位置插入 <code>x</code> 来 <strong>最大化</strong> <code>n</code> 的 <strong>数值</strong> ​​​​​​。但 <strong>不能</strong> 在负号的左边插入 <code>x</code> 。</p>

<ul>
	<li>例如，如果 <code>n = 73</code> 且 <code>x = 6</code> ，那么最佳方案是将 <code>6</code> 插入 <code>7</code> 和 <code>3</code> 之间，使 <code>n = 763</code> 。</li>
	<li>如果 <code>n = -55</code> 且 <code>x = 2</code> ，那么最佳方案是将 <code>2</code> 插在第一个 <code>5</code> 之前，使 <code>n = -255</code> 。</li>
</ul>

<p>返回插入操作后，用字符串表示的 <code>n</code> 的最大值。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = "99", x = 9
<strong>输出：</strong>"999"
<strong>解释：</strong>不管在哪里插入 9 ，结果都是相同的。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = "-13", x = 2
<strong>输出：</strong>"-123"
<strong>解释：</strong>向 n 中插入 x 可以得到 -213、-123 或者 -132 ，三者中最大的是 -123 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= n.length <= 10<sup>5</sup></code></li>
	<li><code>1 <= x <= 9</code></li>
	<li><code>n</code>​​​ 中每一位的数字都在闭区间 <code>[1, 9]</code> 中。</li>
	<li><code>n</code> 代表一个有效的整数。</li>
	<li>当 <code>n</code> 表示负数时，将会以字符 <code>'-'</code> 开始。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心

如果 $n$ 是负数，那么我们要找到第一个大于 $x$ 的位置，然后在这个位置插入 $x$；如果 $n$ 是正数，那么我们要找到第一个小于 $x$ 的位置，然后在这个位置插入 $x$。

时间复杂度 $O(m)$，其中 $m$ 为 $n$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxValue(self, n: str, x: int) -> str:
        i = 0
        if n[0] == "-":
            i += 1
            while i < len(n) and int(n[i]) <= x:
                i += 1
        else:
            while i < len(n) and int(n[i]) >= x:
                i += 1
        return n[:i] + str(x) + n[i:]
```

#### Java

```java
class Solution {
    public String maxValue(String n, int x) {
        int i = 0;
        if (n.charAt(0) == '-') {
            ++i;
            while (i < n.length() && n.charAt(i) - '0' <= x) {
                ++i;
            }
        } else {
            while (i < n.length() && n.charAt(i) - '0' >= x) {
                ++i;
            }
        }
        return n.substring(0, i) + x + n.substring(i);
    }
}
```

#### C++

```cpp
class Solution {
public:
    string maxValue(string n, int x) {
        int i = 0;
        if (n[0] == '-') {
            ++i;
            while (i < n.size() && n[i] - '0' <= x) {
                ++i;
            }
        } else {
            while (i < n.size() && n[i] - '0' >= x) {
                ++i;
            }
        }
        n.insert(i, 1, x + '0');
        return n;
    }
};
```

#### Go

```go
func maxValue(n string, x int) string {
	i := 0
	y := byte('0' + x)
	if n[0] == '-' {
		i++
		for i < len(n) && n[i] <= y {
			i++
		}
	} else {
		for i < len(n) && n[i] >= y {
			i++
		}
	}
	return n[:i] + string(y) + n[i:]
}
```

#### TypeScript

```ts
function maxValue(n: string, x: number): string {
    let i = 0;
    if (n[0] === '-') {
        i++;
        while (i < n.length && +n[i] <= x) {
            i++;
        }
    } else {
        while (i < n.length && +n[i] >= x) {
            i++;
        }
    }
    return n.slice(0, i) + x + n.slice(i);
}
```

#### Rust

```rust
impl Solution {
    pub fn max_value(n: String, x: i32) -> String {
        let s = n.as_bytes();
        let mut i = 0;
        if n.starts_with('-') {
            i += 1;
            while i < s.len() && (s[i] - b'0') as i32 <= x {
                i += 1;
            }
        } else {
            while i < s.len() && (s[i] - b'0') as i32 >= x {
                i += 1;
            }
        }
        let mut ans = String::new();
        ans.push_str(&n[0..i]);
        ans.push_str(&x.to_string());
        ans.push_str(&n[i..]);
        ans
    }
}
```

#### JavaScript

```js
/**
 * @param {string} n
 * @param {number} x
 * @return {string}
 */
var maxValue = function (n, x) {
    let i = 0;
    if (n[0] === '-') {
        i++;
        while (i < n.length && +n[i] <= x) {
            i++;
        }
    } else {
        while (i < n.length && +n[i] >= x) {
            i++;
        }
    }
    return n.slice(0, i) + x + n.slice(i);
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1882. 使用服务器处理任务](https://leetcode.cn/problems/process-tasks-using-servers){#1882}

{{< tabs "1882" >}}

{{% tab "python" %}}
```python
class Solution:
    def assignTasks(self, servers: List[int], tasks: List[int]) -> List[int]:
        idle = [(x, i) for i, x in enumerate(servers)]
        heapify(idle)
        busy = []
        ans = []
        for j, t in enumerate(tasks):
            while busy and busy[0][0] <= j:
                _, s, i = heappop(busy)
                heappush(idle, (s, i))
            if idle:
                s, i = heappop(idle)
                heappush(busy, (j + t, s, i))
            else:
                w, s, i = heappop(busy)
                heappush(busy, (w + t, s, i))
            ans.append(i)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] assignTasks(int[] servers, int[] tasks) {
        int n = servers.length;
        PriorityQueue<int[]> idle = new PriorityQueue<>((a, b) -> {
            if (a[0] != b[0]) {
                return a[0] - b[0];
            }
            return a[1] - b[1];
        });
        PriorityQueue<int[]> busy = new PriorityQueue<>((a, b) -> {
            if (a[0] != b[0]) {
                return a[0] - b[0];
            }
            if (a[1] != b[1]) {
                return a[1] - b[1];
            }
            return a[2] - b[2];
        });
        for (int i = 0; i < n; i++) {
            idle.offer(new int[] {servers[i], i});
        }
        int m = tasks.length;
        int[] ans = new int[m];
        for (int j = 0; j < m; ++j) {
            int t = tasks[j];
            while (!busy.isEmpty() && busy.peek()[0] <= j) {
                int[] p = busy.poll();
                idle.offer(new int[] {p[1], p[2]});
            }
            if (!idle.isEmpty()) {
                int i = idle.poll()[1];
                ans[j] = i;
                busy.offer(new int[] {j + t, servers[i], i});
            } else {
                int[] p = busy.poll();
                int i = p[2];
                ans[j] = i;
                busy.offer(new int[] {p[0] + t, p[1], i});
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
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        using pii = pair<int, int>;
        using arr3 = array<int, 3>;
        priority_queue<pii, vector<pii>, greater<pii>> idle;
        priority_queue<arr3, vector<arr3>, greater<arr3>> busy;
        for (int i = 0; i < servers.size(); ++i) {
            idle.push({servers[i], i});
        }
        int m = tasks.size();
        vector<int> ans(m);
        for (int j = 0; j < m; ++j) {
            int t = tasks[j];
            while (!busy.empty() && busy.top()[0] <= j) {
                auto [_, s, i] = busy.top();
                busy.pop();
                idle.push({s, i});
            }

            if (!idle.empty()) {
                auto [s, i] = idle.top();
                idle.pop();
                ans[j] = i;
                busy.push({j + t, s, i});
            } else {
                auto [w, s, i] = busy.top();
                busy.pop();
                ans[j] = i;
                busy.push({w + t, s, i});
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func assignTasks(servers []int, tasks []int) (ans []int) {
	idle := hp{}
	busy := hp2{}
	for i, x := range servers {
		heap.Push(&idle, pair{x, i})
	}
	for j, t := range tasks {
		for len(busy) > 0 && busy[0].w <= j {
			p := heap.Pop(&busy).(tuple)
			heap.Push(&idle, pair{p.s, p.i})
		}
		if idle.Len() > 0 {
			p := heap.Pop(&idle).(pair)
			ans = append(ans, p.i)
			heap.Push(&busy, tuple{j + t, p.s, p.i})
		} else {
			p := heap.Pop(&busy).(tuple)
			ans = append(ans, p.i)
			heap.Push(&busy, tuple{p.w + t, p.s, p.i})
		}
	}
	return
}

type pair struct {
	s int
	i int
}

type hp []pair

func (h hp) Len() int { return len(h) }
func (h hp) Less(i, j int) bool {
	a, b := h[i], h[j]
	return a.s < b.s || a.s == b.s && a.i < b.i
}
func (h hp) Swap(i, j int) { h[i], h[j] = h[j], h[i] }
func (h *hp) Push(v any)   { *h = append(*h, v.(pair)) }
func (h *hp) Pop() any     { a := *h; v := a[len(a)-1]; *h = a[:len(a)-1]; return v }

type tuple struct {
	w int
	s int
	i int
}

type hp2 []tuple

func (h hp2) Len() int { return len(h) }
func (h hp2) Less(i, j int) bool {
	a, b := h[i], h[j]
	return a.w < b.w || a.w == b.w && (a.s < b.s || a.s == b.s && a.i < b.i)
}
func (h hp2) Swap(i, j int) { h[i], h[j] = h[j], h[i] }
func (h *hp2) Push(v any)   { *h = append(*h, v.(tuple)) }
func (h *hp2) Pop() any     { a := *h; v := a[len(a)-1]; *h = a[:len(a)-1]; return v }
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function assignTasks(servers: number[], tasks: number[]): number[] {
    const idle = new PriorityQueue({
        compare: (a, b) => (a[0] === b[0] ? a[1] - b[1] : a[0] - b[0]),
    });
    const busy = new PriorityQueue({
        compare: (a, b) =>
            a[0] === b[0] ? (a[1] === b[1] ? a[2] - b[2] : a[1] - b[1]) : a[0] - b[0],
    });
    for (let i = 0; i < servers.length; ++i) {
        idle.enqueue([servers[i], i]);
    }
    const ans: number[] = [];
    for (let j = 0; j < tasks.length; ++j) {
        const t = tasks[j];
        while (busy.size() > 0 && busy.front()![0] <= j) {
            const [_, s, i] = busy.dequeue()!;
            idle.enqueue([s, i]);
        }
        if (idle.size() > 0) {
            const [s, i] = idle.dequeue()!;
            busy.enqueue([j + t, s, i]);
            ans.push(i);
        } else {
            const [w, s, i] = busy.dequeue()!;
            busy.enqueue([w + t, s, i]);
            ans.push(i);
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

<p>给你两个 <strong>下标从 0 开始</strong> 的整数数组 <code>servers</code> 和 <code>tasks</code> ，长度分别为 <code>n</code>​​​​​​ 和 <code>m</code>​​​​​​ 。<code>servers[i]</code> 是第 <code>i<sup>​​​​​​</sup></code>​​​​ 台服务器的 <strong>权重</strong> ，而 <code>tasks[j]</code> 是处理第 <code>j<sup>​​​​​​</sup></code> 项任务 <strong>所需要的时间</strong>（单位：秒）。</p>

<p>你正在运行一个仿真系统，在处理完所有任务后，该系统将会关闭。每台服务器只能同时处理一项任务。第 <code>0</code> 项任务在第 <code>0</code> 秒可以开始处理，相应地，第 <code>j</code> 项任务在第 <code>j</code> 秒可以开始处理。处理第 <code>j</code> 项任务时，你需要为它分配一台 <strong>权重最小</strong> 的空闲服务器。如果存在多台相同权重的空闲服务器，请选择 <strong>下标最小</strong> 的服务器。如果一台空闲服务器在第 <code>t</code> 秒分配到第 <code>j</code> 项任务，那么在 <code>t + tasks[j]</code> 时它将恢复空闲状态。</p>

<p>如果没有空闲服务器，则必须等待，直到出现一台空闲服务器，并 <strong>尽可能早</strong> 地处理剩余任务。 如果有多项任务等待分配，则按照 <strong>下标递增</strong> 的顺序完成分配。</p>

<p>如果同一时刻存在多台空闲服务器，可以同时将多项任务分别分配给它们。</p>

<p>构建长度为 <code>m</code> 的答案数组 <code>ans</code> ，其中 <code>ans[j]</code> 是第 <code>j</code> 项任务分配的服务器的下标。</p>

<p>返回答案数组<em> </em><code>ans</code>​​​​ 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>servers = [3,3,2], tasks = [1,2,3,2,1,2]
<strong>输出：</strong>[2,2,0,2,1,2]
<strong>解释：</strong>事件按时间顺序如下：
- 0 秒时，第 0 项任务加入到任务队列，使用第 2 台服务器处理到 1 秒。
- 1 秒时，第 2 台服务器空闲，第 1 项任务加入到任务队列，使用第 2 台服务器处理到 3 秒。
- 2 秒时，第 2 项任务加入到任务队列，使用第 0 台服务器处理到 5 秒。
- 3 秒时，第 2 台服务器空闲，第 3 项任务加入到任务队列，使用第 2 台服务器处理到 5 秒。
- 4 秒时，第 4 项任务加入到任务队列，使用第 1 台服务器处理到 5 秒。
- 5 秒时，所有服务器都空闲，第 5 项任务加入到任务队列，使用第 2 台服务器处理到 7 秒。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>servers = [5,1,4,3,2], tasks = [2,1,2,4,5,2,1]
<strong>输出：</strong>[1,4,1,4,1,3,2]
<strong>解释：</strong>事件按时间顺序如下：
- 0 秒时，第 0 项任务加入到任务队列，使用第 1 台服务器处理到 2 秒。
- 1 秒时，第 1 项任务加入到任务队列，使用第 4 台服务器处理到 2 秒。
- 2 秒时，第 1 台和第 4 台服务器空闲，第 2 项任务加入到任务队列，使用第 1 台服务器处理到 4 秒。
- 3 秒时，第 3 项任务加入到任务队列，使用第 4 台服务器处理到 7 秒。
- 4 秒时，第 1 台服务器空闲，第 4 项任务加入到任务队列，使用第 1 台服务器处理到 9 秒。
- 5 秒时，第 5 项任务加入到任务队列，使用第 3 台服务器处理到 7 秒。
- 6 秒时，第 6 项任务加入到任务队列，使用第 2 台服务器处理到 7 秒。</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>servers.length == n</code></li>
	<li><code>tasks.length == m</code></li>
	<li><code>1 <= n, m <= 2 * 10<sup>5</sup></code></li>
	<li><code>1 <= servers[i], tasks[j] <= 2 * 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：优先队列（小根堆）

我们用一个小根堆 $\textit{idle}$ 来维护所有的空闲服务器，其中每个元素是一个二元组 $(x, i)$，表示第 $i$ 台服务器的权重为 $x$。用一个小根堆 $\textit{busy}$ 来维护所有的忙碌服务器，其中每个元素是一个三元组 $(w, s, i)$，表示第 $i$ 台服务器在第 $w$ 秒恢复空闲，权重为 $s$。初始时我们将所有的服务器加入到 $\textit{idle}$ 中。

接下来，我们遍历所有的任务，对于第 $j$ 项任务，我们首先将所有在第 $j$ 秒或之前恢复空闲的服务器从 $\textit{busy}$ 中移除，添加到 $\textit{idle}$ 中。然后我们从 $\textit{idle}$ 中取出一个权重最小的服务器，将其加入到 $\textit{busy}$ 中，处理第 $j$ 项任务。如果 $\textit{idle}$ 为空，我们从 $\textit{busy}$ 中取出一个恢复时间最早的服务器，将其加入到 $\textit{busy}$ 中，处理第 $j$ 项任务。

遍历结束后，我们得到了答案数组 $\textit{ans}$。

时间复杂度 $O((n + m) \log n)$，其中 $n$ 为服务器的数量，$m$ 为任务的数量。空间复杂度 $O(n)$。其中 $n$ 和 $m$ 分别为服务器和任务的数量。

相似题目：

-   [2402. 会议室 III](https://github.com/doocs/leetcode/blob/main/solution/2400-2499/2402.Meeting%20Rooms%20III/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def assignTasks(self, servers: List[int], tasks: List[int]) -> List[int]:
        idle = [(x, i) for i, x in enumerate(servers)]
        heapify(idle)
        busy = []
        ans = []
        for j, t in enumerate(tasks):
            while busy and busy[0][0] <= j:
                _, s, i = heappop(busy)
                heappush(idle, (s, i))
            if idle:
                s, i = heappop(idle)
                heappush(busy, (j + t, s, i))
            else:
                w, s, i = heappop(busy)
                heappush(busy, (w + t, s, i))
            ans.append(i)
        return ans
```

#### Java

```java
class Solution {
    public int[] assignTasks(int[] servers, int[] tasks) {
        int n = servers.length;
        PriorityQueue<int[]> idle = new PriorityQueue<>((a, b) -> {
            if (a[0] != b[0]) {
                return a[0] - b[0];
            }
            return a[1] - b[1];
        });
        PriorityQueue<int[]> busy = new PriorityQueue<>((a, b) -> {
            if (a[0] != b[0]) {
                return a[0] - b[0];
            }
            if (a[1] != b[1]) {
                return a[1] - b[1];
            }
            return a[2] - b[2];
        });
        for (int i = 0; i < n; i++) {
            idle.offer(new int[] {servers[i], i});
        }
        int m = tasks.length;
        int[] ans = new int[m];
        for (int j = 0; j < m; ++j) {
            int t = tasks[j];
            while (!busy.isEmpty() && busy.peek()[0] <= j) {
                int[] p = busy.poll();
                idle.offer(new int[] {p[1], p[2]});
            }
            if (!idle.isEmpty()) {
                int i = idle.poll()[1];
                ans[j] = i;
                busy.offer(new int[] {j + t, servers[i], i});
            } else {
                int[] p = busy.poll();
                int i = p[2];
                ans[j] = i;
                busy.offer(new int[] {p[0] + t, p[1], i});
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
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        using pii = pair<int, int>;
        using arr3 = array<int, 3>;
        priority_queue<pii, vector<pii>, greater<pii>> idle;
        priority_queue<arr3, vector<arr3>, greater<arr3>> busy;
        for (int i = 0; i < servers.size(); ++i) {
            idle.push({servers[i], i});
        }
        int m = tasks.size();
        vector<int> ans(m);
        for (int j = 0; j < m; ++j) {
            int t = tasks[j];
            while (!busy.empty() && busy.top()[0] <= j) {
                auto [_, s, i] = busy.top();
                busy.pop();
                idle.push({s, i});
            }

            if (!idle.empty()) {
                auto [s, i] = idle.top();
                idle.pop();
                ans[j] = i;
                busy.push({j + t, s, i});
            } else {
                auto [w, s, i] = busy.top();
                busy.pop();
                ans[j] = i;
                busy.push({w + t, s, i});
            }
        }
        return ans;
    }
};
```

#### Go

```go
func assignTasks(servers []int, tasks []int) (ans []int) {
	idle := hp{}
	busy := hp2{}
	for i, x := range servers {
		heap.Push(&idle, pair{x, i})
	}
	for j, t := range tasks {
		for len(busy) > 0 && busy[0].w <= j {
			p := heap.Pop(&busy).(tuple)
			heap.Push(&idle, pair{p.s, p.i})
		}
		if idle.Len() > 0 {
			p := heap.Pop(&idle).(pair)
			ans = append(ans, p.i)
			heap.Push(&busy, tuple{j + t, p.s, p.i})
		} else {
			p := heap.Pop(&busy).(tuple)
			ans = append(ans, p.i)
			heap.Push(&busy, tuple{p.w + t, p.s, p.i})
		}
	}
	return
}

type pair struct {
	s int
	i int
}

type hp []pair

func (h hp) Len() int { return len(h) }
func (h hp) Less(i, j int) bool {
	a, b := h[i], h[j]
	return a.s < b.s || a.s == b.s && a.i < b.i
}
func (h hp) Swap(i, j int) { h[i], h[j] = h[j], h[i] }
func (h *hp) Push(v any)   { *h = append(*h, v.(pair)) }
func (h *hp) Pop() any     { a := *h; v := a[len(a)-1]; *h = a[:len(a)-1]; return v }

type tuple struct {
	w int
	s int
	i int
}

type hp2 []tuple

func (h hp2) Len() int { return len(h) }
func (h hp2) Less(i, j int) bool {
	a, b := h[i], h[j]
	return a.w < b.w || a.w == b.w && (a.s < b.s || a.s == b.s && a.i < b.i)
}
func (h hp2) Swap(i, j int) { h[i], h[j] = h[j], h[i] }
func (h *hp2) Push(v any)   { *h = append(*h, v.(tuple)) }
func (h *hp2) Pop() any     { a := *h; v := a[len(a)-1]; *h = a[:len(a)-1]; return v }
```

#### TypeScript

```ts
function assignTasks(servers: number[], tasks: number[]): number[] {
    const idle = new PriorityQueue({
        compare: (a, b) => (a[0] === b[0] ? a[1] - b[1] : a[0] - b[0]),
    });
    const busy = new PriorityQueue({
        compare: (a, b) =>
            a[0] === b[0] ? (a[1] === b[1] ? a[2] - b[2] : a[1] - b[1]) : a[0] - b[0],
    });
    for (let i = 0; i < servers.length; ++i) {
        idle.enqueue([servers[i], i]);
    }
    const ans: number[] = [];
    for (let j = 0; j < tasks.length; ++j) {
        const t = tasks[j];
        while (busy.size() > 0 && busy.front()![0] <= j) {
            const [_, s, i] = busy.dequeue()!;
            idle.enqueue([s, i]);
        }
        if (idle.size() > 0) {
            const [s, i] = idle.dequeue()!;
            busy.enqueue([j + t, s, i]);
            ans.push(i);
        } else {
            const [w, s, i] = busy.dequeue()!;
            busy.enqueue([w + t, s, i]);
            ans.push(i);
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

# [1883. 准时抵达会议现场的最小跳过休息次数](https://leetcode.cn/problems/minimum-skips-to-arrive-at-meeting-on-time){#1883}

{{< tabs "1883" >}}

{{% tab "python" %}}
```python
class Solution:
    def minSkips(self, dist: List[int], speed: int, hoursBefore: int) -> int:
        n = len(dist)
        f = [[inf] * (n + 1) for _ in range(n + 1)]
        f[0][0] = 0
        eps = 1e-8
        for i, x in enumerate(dist, 1):
            for j in range(i + 1):
                if j < i:
                    f[i][j] = min(f[i][j], ceil(f[i - 1][j] + x / speed - eps))
                if j:
                    f[i][j] = min(f[i][j], f[i - 1][j - 1] + x / speed)
        for j in range(n + 1):
            if f[n][j] <= hoursBefore + eps:
                return j
        return -1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minSkips(int[] dist, int speed, int hoursBefore) {
        int n = dist.length;
        double[][] f = new double[n + 1][n + 1];
        for (int i = 0; i <= n; i++) {
            Arrays.fill(f[i], 1e20);
        }
        f[0][0] = 0;
        double eps = 1e-8;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (j < i) {
                    f[i][j] = Math.min(
                        f[i][j], Math.ceil(f[i - 1][j]) + 1.0 * dist[i - 1] / speed - eps);
                }
                if (j > 0) {
                    f[i][j] = Math.min(f[i][j], f[i - 1][j - 1] + 1.0 * dist[i - 1] / speed);
                }
            }
        }
        for (int j = 0; j <= n; ++j) {
            if (f[n][j] <= hoursBefore + eps) {
                return j;
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
    int minSkips(vector<int>& dist, int speed, int hoursBefore) {
        int n = dist.size();
        vector<vector<double>> f(n + 1, vector<double>(n + 1, 1e20));
        f[0][0] = 0;
        double eps = 1e-8;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (j < i) {
                    f[i][j] = min(f[i][j], ceil(f[i - 1][j] + dist[i - 1] * 1.0 / speed - eps));
                }
                if (j) {
                    f[i][j] = min(f[i][j], f[i - 1][j - 1] + dist[i - 1] * 1.0 / speed);
                }
            }
        }
        for (int j = 0; j <= n; ++j) {
            if (f[n][j] <= hoursBefore + eps) {
                return j;
            }
        }
        return -1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minSkips(dist []int, speed int, hoursBefore int) int {
	n := len(dist)
	f := make([][]float64, n+1)
	for i := range f {
		f[i] = make([]float64, n+1)
		for j := range f[i] {
			f[i][j] = 1e20
		}
	}
	f[0][0] = 0
	eps := 1e-8
	for i := 1; i <= n; i++ {
		for j := 0; j <= i; j++ {
			if j < i {
				f[i][j] = math.Min(f[i][j], math.Ceil(f[i-1][j]+float64(dist[i-1])/float64(speed)-eps))
			}
			if j > 0 {
				f[i][j] = math.Min(f[i][j], f[i-1][j-1]+float64(dist[i-1])/float64(speed))
			}
		}
	}
	for j := 0; j <= n; j++ {
		if f[n][j] <= float64(hoursBefore) {
			return j
		}
	}
	return -1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minSkips(dist: number[], speed: number, hoursBefore: number): number {
    const n = dist.length;
    const f = Array.from({ length: n + 1 }, () => Array.from({ length: n + 1 }, () => Infinity));
    f[0][0] = 0;
    const eps = 1e-8;
    for (let i = 1; i <= n; ++i) {
        for (let j = 0; j <= i; ++j) {
            if (j < i) {
                f[i][j] = Math.min(f[i][j], Math.ceil(f[i - 1][j] + dist[i - 1] / speed - eps));
            }
            if (j) {
                f[i][j] = Math.min(f[i][j], f[i - 1][j - 1] + dist[i - 1] / speed);
            }
        }
    }
    for (let j = 0; j <= n; ++j) {
        if (f[n][j] <= hoursBefore + eps) {
            return j;
        }
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

<p>给你一个整数 <code>hoursBefore</code> ，表示你要前往会议所剩下的可用小时数。要想成功抵达会议现场，你必须途经 <code>n</code> 条道路。道路的长度用一个长度为 <code>n</code> 的整数数组 <code>dist</code> 表示，其中 <code>dist[i]</code> 表示第 <code>i</code> 条道路的长度（单位：<strong>千米</strong>）。另给你一个整数 <code>speed</code> ，表示你在道路上前进的速度（单位：<strong>千米每小时</strong>）。</p>

<p>当你通过第 <code>i</code> 条路之后，就必须休息并等待，直到 <strong>下一个整数小时</strong> 才能开始继续通过下一条道路。注意：你不需要在通过最后一条道路后休息，因为那时你已经抵达会议现场。</p>

<ul>
	<li>例如，如果你通过一条道路用去 <code>1.4</code> 小时，那你必须停下来等待，到 <code>2</code> 小时才可以继续通过下一条道路。如果通过一条道路恰好用去 <code>2</code> 小时，就无需等待，可以直接继续。</li>
</ul>

<p>然而，为了能准时到达，你可以选择 <strong>跳过</strong> 一些路的休息时间，这意味着你不必等待下一个整数小时。注意，这意味着与不跳过任何休息时间相比，你可能在不同时刻到达接下来的道路。</p>

<ul>
	<li>例如，假设通过第 <code>1</code> 条道路用去 <code>1.4</code> 小时，且通过第 <code>2</code> 条道路用去 <code>0.6</code> 小时。跳过第 <code>1</code> 条道路的休息时间意味着你将会在恰好 <code>2</code> 小时完成通过第 <code>2</code> 条道路，且你能够立即开始通过第 <code>3</code> 条道路。</li>
</ul>

<p>返回准时抵达会议现场所需要的 <strong>最小跳过次数</strong> ，如果 <strong>无法准时参会</strong> ，返回 <code>-1</code> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>dist = [1,3,2], speed = 4, hoursBefore = 2
<strong>输出：</strong>1
<strong>解释：</strong>
不跳过任何休息时间，你将用 (1/4 + 3/4) + (3/4 + 1/4) + (2/4) = 2.5 小时才能抵达会议现场。
可以跳过第 1 次休息时间，共用 ((1/4 + <strong>0</strong>) + (3/4 + 0)) + (2/4) = 1.5 小时抵达会议现场。
注意，第 2 次休息时间缩短为 0 ，由于跳过第 1 次休息时间，你是在整数小时处完成通过第 2 条道路。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>dist = [7,3,5,5], speed = 2, hoursBefore = 10
<strong>输出：</strong>2
<strong>解释：</strong>
不跳过任何休息时间，你将用 (7/2 + 1/2) + (3/2 + 1/2) + (5/2 + 1/2) + (5/2) = 11.5 小时才能抵达会议现场。
可以跳过第 1 次和第 3 次休息时间，共用 ((7/2 + <strong>0</strong>) + (3/2 + 0)) + ((5/2 + <strong>0</strong>) + (5/2)) = 10 小时抵达会议现场。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>dist = [7,3,5,5], speed = 1, hoursBefore = 10
<strong>输出：</strong>-1
<strong>解释：</strong>即使跳过所有的休息时间，也无法准时参加会议。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == dist.length</code></li>
	<li><code>1 <= n <= 1000</code></li>
	<li><code>1 <= dist[i] <= 10<sup>5</sup></code></li>
	<li><code>1 <= speed <= 10<sup>6</sup></code></li>
	<li><code>1 <= hoursBefore <= 10<sup>7</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i][j]$ 表示考虑前 $i$ 条道路，恰好跳过 $j$ 次休息时间的最短用时。初始时 $f[0][0]=0$，其余 $f[i][j]=\infty$。

由于我们可以选择跳过或者不跳过第 $i$ 条道路的休息时间，因此我们可以列出状态转移方程：

$$
f[i][j]=\min\left\{\begin{aligned} \lceil f[i-1][j]+\frac{d_i}{s}\rceil & \textit{不跳过第 $i$ 条道路的休息时间} \\ f[i-1][j-1]+\frac{d_i}{s} & \textit{跳过第 $i$ 条道路的休息时间} \end{aligned}\right.
$$

其中 $\lceil x\rceil$ 表示将 $x$ 向上取整。需要注意的是，由于我们需要保证恰好跳过 $j$ 次休息时间，因此我们必须有 $j\le i$；另外，如果 $j=0$，不能跳过任何休息时间。

由于浮点数运算以及向上取整运算可能会带来精度误差，因此我们引入一个常量 $eps = 10^{-8}$ 表示一个极小的正实数，在浮点数取整前先减去 $eps$，最后在比较 $f[n][j]$ 和 $hoursBefore$ 时，需要加上 $eps$。

时间复杂度 $O(n^2)$，空间复杂度 $O(n^2)$。其中 $n$ 是道路的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minSkips(self, dist: List[int], speed: int, hoursBefore: int) -> int:
        n = len(dist)
        f = [[inf] * (n + 1) for _ in range(n + 1)]
        f[0][0] = 0
        eps = 1e-8
        for i, x in enumerate(dist, 1):
            for j in range(i + 1):
                if j < i:
                    f[i][j] = min(f[i][j], ceil(f[i - 1][j] + x / speed - eps))
                if j:
                    f[i][j] = min(f[i][j], f[i - 1][j - 1] + x / speed)
        for j in range(n + 1):
            if f[n][j] <= hoursBefore + eps:
                return j
        return -1
```

#### Java

```java
class Solution {
    public int minSkips(int[] dist, int speed, int hoursBefore) {
        int n = dist.length;
        double[][] f = new double[n + 1][n + 1];
        for (int i = 0; i <= n; i++) {
            Arrays.fill(f[i], 1e20);
        }
        f[0][0] = 0;
        double eps = 1e-8;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (j < i) {
                    f[i][j] = Math.min(
                        f[i][j], Math.ceil(f[i - 1][j]) + 1.0 * dist[i - 1] / speed - eps);
                }
                if (j > 0) {
                    f[i][j] = Math.min(f[i][j], f[i - 1][j - 1] + 1.0 * dist[i - 1] / speed);
                }
            }
        }
        for (int j = 0; j <= n; ++j) {
            if (f[n][j] <= hoursBefore + eps) {
                return j;
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
    int minSkips(vector<int>& dist, int speed, int hoursBefore) {
        int n = dist.size();
        vector<vector<double>> f(n + 1, vector<double>(n + 1, 1e20));
        f[0][0] = 0;
        double eps = 1e-8;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (j < i) {
                    f[i][j] = min(f[i][j], ceil(f[i - 1][j] + dist[i - 1] * 1.0 / speed - eps));
                }
                if (j) {
                    f[i][j] = min(f[i][j], f[i - 1][j - 1] + dist[i - 1] * 1.0 / speed);
                }
            }
        }
        for (int j = 0; j <= n; ++j) {
            if (f[n][j] <= hoursBefore + eps) {
                return j;
            }
        }
        return -1;
    }
};
```

#### Go

```go
func minSkips(dist []int, speed int, hoursBefore int) int {
	n := len(dist)
	f := make([][]float64, n+1)
	for i := range f {
		f[i] = make([]float64, n+1)
		for j := range f[i] {
			f[i][j] = 1e20
		}
	}
	f[0][0] = 0
	eps := 1e-8
	for i := 1; i <= n; i++ {
		for j := 0; j <= i; j++ {
			if j < i {
				f[i][j] = math.Min(f[i][j], math.Ceil(f[i-1][j]+float64(dist[i-1])/float64(speed)-eps))
			}
			if j > 0 {
				f[i][j] = math.Min(f[i][j], f[i-1][j-1]+float64(dist[i-1])/float64(speed))
			}
		}
	}
	for j := 0; j <= n; j++ {
		if f[n][j] <= float64(hoursBefore) {
			return j
		}
	}
	return -1
}
```

#### TypeScript

```ts
function minSkips(dist: number[], speed: number, hoursBefore: number): number {
    const n = dist.length;
    const f = Array.from({ length: n + 1 }, () => Array.from({ length: n + 1 }, () => Infinity));
    f[0][0] = 0;
    const eps = 1e-8;
    for (let i = 1; i <= n; ++i) {
        for (let j = 0; j <= i; ++j) {
            if (j < i) {
                f[i][j] = Math.min(f[i][j], Math.ceil(f[i - 1][j] + dist[i - 1] / speed - eps));
            }
            if (j) {
                f[i][j] = Math.min(f[i][j], f[i - 1][j - 1] + dist[i - 1] / speed);
            }
        }
    }
    for (let j = 0; j <= n; ++j) {
        if (f[n][j] <= hoursBefore + eps) {
            return j;
        }
    }
    return -1;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1884. 鸡蛋掉落-两枚鸡蛋](https://leetcode.cn/problems/egg-drop-with-2-eggs-and-n-floors){#1884}

{{< tabs "1884" >}}

{{% tab "python" %}}
```python
class Solution:
    def twoEggDrop(self, n: int) -> int:
        f = [0] + [inf] * n
        for i in range(1, n + 1):
            for j in range(1, i + 1):
                f[i] = min(f[i], 1 + max(j - 1, f[i - j]))
        return f[n]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int twoEggDrop(int n) {
        int[] f = new int[n + 1];
        Arrays.fill(f, 1 << 29);
        f[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                f[i] = Math.min(f[i], 1 + Math.max(j - 1, f[i - j]));
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
    int twoEggDrop(int n) {
        int f[n + 1];
        memset(f, 0x3f, sizeof(f));
        f[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                f[i] = min(f[i], 1 + max(j - 1, f[i - j]));
            }
        }
        return f[n];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func twoEggDrop(n int) int {
	f := make([]int, n+1)
	for i := range f {
		f[i] = 1 << 29
	}
	f[0] = 0
	for i := 1; i <= n; i++ {
		for j := 1; j <= i; j++ {
			f[i] = min(f[i], 1+max(j-1, f[i-j]))
		}
	}
	return f[n]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function twoEggDrop(n: number): number {
    const f: number[] = Array(n + 1).fill(Infinity);
    f[0] = 0;
    for (let i = 1; i <= n; ++i) {
        for (let j = 1; j <= i; ++j) {
            f[i] = Math.min(f[i], 1 + Math.max(j - 1, f[i - j]));
        }
    }
    return f[n];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你 <strong>2&nbsp;枚相同 </strong>的鸡蛋，和一栋从第 <code>1</code>&nbsp;层到第 <code>n</code> 层共有 <code>n</code> 层楼的建筑。</p>

<p>已知存在楼层 <code>f</code> ，满足&nbsp;<code>0 &lt;= f &lt;= n</code> ，任何从 <strong>高于 </strong><code>f</code> 的楼层落下的鸡蛋都<strong> 会碎 </strong>，从 <strong><code>f</code> 楼层或比它低 </strong>的楼层落下的鸡蛋都 <strong>不会碎 </strong>。</p>

<p>每次操作，你可以取一枚<strong> 没有碎</strong> 的鸡蛋并把它从任一楼层 <code>x</code> 扔下（满足&nbsp;<code>1 &lt;= x &lt;= n</code>）。如果鸡蛋碎了，你就不能再次使用它。如果某枚鸡蛋扔下后没有摔碎，则可以在之后的操作中<strong> 重复使用 </strong>这枚鸡蛋。</p>

<p>请你计算并返回要确定 <code>f</code> <strong>确切的值 </strong>的 <strong>最小操作次数</strong> 是多少？</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 2
<strong>输出：</strong>2
<strong>解释：</strong>我们可以将第一枚鸡蛋从 1 楼扔下，然后将第二枚从 2 楼扔下。
如果第一枚鸡蛋碎了，可知 f = 0；
如果第二枚鸡蛋碎了，但第一枚没碎，可知 f = 1；
否则，当两个鸡蛋都没碎时，可知 f = 2。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 100
<strong>输出：</strong>14
<strong>解释：
</strong>一种最优的策略是：
- 将第一枚鸡蛋从 9 楼扔下。如果碎了，那么 f 在 0 和 8 之间。将第二枚从 1 楼扔下，然后每扔一次上一层楼，在 8 次内找到 f 。总操作次数 = 1 + 8 = 9 。
- 如果第一枚鸡蛋没有碎，那么再把第一枚鸡蛋从 22 层扔下。如果碎了，那么 f 在 9 和 21 之间。将第二枚鸡蛋从 10 楼扔下，然后每扔一次上一层楼，在 12 次内找到 f 。总操作次数 = 2 + 12 = 14 。
- 如果第一枚鸡蛋没有再次碎掉，则按照类似的方法从 34, 45, 55, 64, 72, 79, 85, 90, 94, 97, 99 和 100 楼分别扔下第一枚鸡蛋。
不管结果如何，最多需要扔 14 次来确定 f 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i]$ 表示有两枚鸡蛋，在 $i$ 层楼中确定 $f$ 的最小操作次数。初始时 $f[0] = 0$，其余 $f[i] = +\infty$。答案为 $f[n]$。

考虑 $f[i]$，我们可以枚举第一枚鸡蛋从第 $j$ 层楼扔下，其中 $1 \leq j \leq i$，此时有两种情况：

-   鸡蛋碎了，此时我们剩余一枚鸡蛋，需要在 $j - 1$ 层楼中确定 $f$，这需要 $j - 1$ 次操作，因此总操作次数为 $1 + (j - 1)$；
-   鸡蛋没碎，此时我们剩余两枚鸡蛋，需要在 $i - j$ 层楼中确定 $f$，这需要 $f[i - j]$ 次操作，因此总操作次数为 $1 + f[i - j]$。

综上，我们可以得到状态转移方程：

$$
f[i] = \min_{1 \leq j \leq i} \{1 + \max(j - 1, f[i - j])\}
$$

最后，我们返回 $f[n]$ 即可。

时间复杂度 $O(n^2)$，空间复杂度 $O(n)$。其中 $n$ 为楼层数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def twoEggDrop(self, n: int) -> int:
        f = [0] + [inf] * n
        for i in range(1, n + 1):
            for j in range(1, i + 1):
                f[i] = min(f[i], 1 + max(j - 1, f[i - j]))
        return f[n]
```

#### Java

```java
class Solution {
    public int twoEggDrop(int n) {
        int[] f = new int[n + 1];
        Arrays.fill(f, 1 << 29);
        f[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                f[i] = Math.min(f[i], 1 + Math.max(j - 1, f[i - j]));
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
    int twoEggDrop(int n) {
        int f[n + 1];
        memset(f, 0x3f, sizeof(f));
        f[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                f[i] = min(f[i], 1 + max(j - 1, f[i - j]));
            }
        }
        return f[n];
    }
};
```

#### Go

```go
func twoEggDrop(n int) int {
	f := make([]int, n+1)
	for i := range f {
		f[i] = 1 << 29
	}
	f[0] = 0
	for i := 1; i <= n; i++ {
		for j := 1; j <= i; j++ {
			f[i] = min(f[i], 1+max(j-1, f[i-j]))
		}
	}
	return f[n]
}
```

#### TypeScript

```ts
function twoEggDrop(n: number): number {
    const f: number[] = Array(n + 1).fill(Infinity);
    f[0] = 0;
    for (let i = 1; i <= n; ++i) {
        for (let j = 1; j <= i; ++j) {
            f[i] = Math.min(f[i], 1 + Math.max(j - 1, f[i - j]));
        }
    }
    return f[n];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1885. 统计数对 🔒](https://leetcode.cn/problems/count-pairs-in-two-arrays){#1885}

{{< tabs "1885" >}}

{{% tab "python" %}}
```python
class Solution:
    def countPairs(self, nums1: List[int], nums2: List[int]) -> int:
        nums = [a - b for a, b in zip(nums1, nums2)]
        nums.sort()
        l, r = 0, len(nums) - 1
        ans = 0
        while l < r:
            while l < r and nums[l] + nums[r] <= 0:
                l += 1
            ans += r - l
            r -= 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long countPairs(int[] nums1, int[] nums2) {
        int n = nums1.length;
        int[] nums = new int[n];
        for (int i = 0; i < n; ++i) {
            nums[i] = nums1[i] - nums2[i];
        }
        Arrays.sort(nums);
        int l = 0, r = n - 1;
        long ans = 0;
        while (l < r) {
            while (l < r && nums[l] + nums[r] <= 0) {
                ++l;
            }
            ans += r - l;
            --r;
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
    long long countPairs(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            nums[i] = nums1[i] - nums2[i];
        }
        ranges::sort(nums);
        int l = 0, r = n - 1;
        long long ans = 0;
        while (l < r) {
            while (l < r && nums[l] + nums[r] <= 0) {
                ++l;
            }
            ans += r - l;
            --r;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countPairs(nums1 []int, nums2 []int) (ans int64) {
	n := len(nums1)
	nums := make([]int, n)
	for i, x := range nums1 {
		nums[i] = x - nums2[i]
	}
	sort.Ints(nums)
	l, r := 0, n-1
	for l < r {
		for l < r && nums[l]+nums[r] <= 0 {
			l++
		}
		ans += int64(r - l)
		r--
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countPairs(nums1: number[], nums2: number[]): number {
    const n = nums1.length;
    const nums: number[] = [];
    for (let i = 0; i < n; ++i) {
        nums.push(nums1[i] - nums2[i]);
    }
    nums.sort((a, b) => a - b);
    let ans = 0;
    let [l, r] = [0, n - 1];
    while (l < r) {
        while (l < r && nums[l] + nums[r] <= 0) {
            ++l;
        }
        ans += r - l;
        --r;
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn count_pairs(nums1: Vec<i32>, nums2: Vec<i32>) -> i64 {
        let mut nums: Vec<i32> = nums1.iter().zip(nums2.iter()).map(|(a, b)| a - b).collect();
        nums.sort();
        let mut l = 0;
        let mut r = nums.len() - 1;
        let mut ans = 0;
        while l < r {
            while l < r && nums[l] + nums[r] <= 0 {
                l += 1;
            }
            ans += (r - l) as i64;
            r -= 1;
        }
        ans
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var countPairs = function (nums1, nums2) {
    const n = nums1.length;
    const nums = [];
    for (let i = 0; i < n; ++i) {
        nums.push(nums1[i] - nums2[i]);
    }
    nums.sort((a, b) => a - b);
    let ans = 0;
    let [l, r] = [0, n - 1];
    while (l < r) {
        while (l < r && nums[l] + nums[r] <= 0) {
            ++l;
        }
        ans += r - l;
        --r;
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

<p>给你两个长度为 <code>n</code> 的整数数组 <code>nums1</code>&nbsp;和&nbsp;<code>nums2</code> ，找出所有满足 <code>i &lt; j</code> 且 <code>nums1[i] + nums1[j] &gt; nums2[i] + nums2[j]</code>&nbsp;的数对 <code>(i, j)</code> 。</p>

<p>返回满足条件数对的<strong> 个数</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums1 = [2,1,2,1], nums2 = [1,2,1,2]
<strong>输出：</strong>1
<strong>解释：</strong>满足条件的数对有 1 个：(0, 2) ，因为 nums1[0] + nums1[2] = 2 + 2 &gt; nums2[0] + nums2[2] = 1 + 1</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums1 = [1,10,6,2], nums2 = [1,4,1,5]
<strong>输出：</strong>5
<strong>解释：</strong>以下数对满足条件：
- (0, 1) 因为 nums1[0] + nums1[1] = 1 + 10 &gt; nums2[0] + nums2[1] = 1 + 4
- (0, 2) 因为 nums1[0] + nums1[2] = 1 + 6 &gt; nums2[0] + nums2[2] = 1 + 1
- (1, 2) 因为 nums1[1] + nums1[2] = 10 + 6 &gt; nums2[1] + nums2[2] = 4 + 1
- (1, 3) 因为 nums1[1] + nums1[3] = 10 + 2 &gt; nums2[1] + nums2[3] = 4 + 5
- (2, 3) 因为 nums1[2] + nums1[3] = 6 + 2 &gt; nums2[2] + nums2[3] = 1 + 5
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nums1.length == nums2.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums1[i], nums2[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 双指针

我们可以将题目的不等式转化为 $\textit{nums1}[i] - \textit{nums2}[i] + \textit{nums1}[j] - \textit{nums2}[j] > 0$，即 $\textit{nums}[i] + \textit{nums}[j] > 0$，其中 $\textit{nums}[i] = \textit{nums1}[i] - \textit{nums2}[i]$。

即对于数组 $\textit{nums}$，我们要找到所有满足 $\textit{nums}[i] + \textit{nums}[j] > 0$ 的数对 $(i, j)$。

我们不妨对数组 $\textit{nums}$ 进行排序，然后使用双指针的方法，初始化左指针 $l = 0$，右指针 $r = n - 1$。每一次，我们判断 $\textit{nums}[l] + \textit{nums}[r]$ 是否小于等于 $0$，如果是，我们循环将左指针右移，直到 $\textit{nums}[l] + \textit{nums}[r] > 0$，此时，以 $l$, $l + 1$, $l + 2$, $\cdots$, $r - 1$ 为左指针，且 $r$ 为右指针的所有数对都满足条件，共有 $r - l$ 个数对，我们将其加入答案中。然后将右指针左移，继续进行上述操作，直到 $l \ge r$。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countPairs(self, nums1: List[int], nums2: List[int]) -> int:
        nums = [a - b for a, b in zip(nums1, nums2)]
        nums.sort()
        l, r = 0, len(nums) - 1
        ans = 0
        while l < r:
            while l < r and nums[l] + nums[r] <= 0:
                l += 1
            ans += r - l
            r -= 1
        return ans
```

#### Java

```java
class Solution {
    public long countPairs(int[] nums1, int[] nums2) {
        int n = nums1.length;
        int[] nums = new int[n];
        for (int i = 0; i < n; ++i) {
            nums[i] = nums1[i] - nums2[i];
        }
        Arrays.sort(nums);
        int l = 0, r = n - 1;
        long ans = 0;
        while (l < r) {
            while (l < r && nums[l] + nums[r] <= 0) {
                ++l;
            }
            ans += r - l;
            --r;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long countPairs(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            nums[i] = nums1[i] - nums2[i];
        }
        ranges::sort(nums);
        int l = 0, r = n - 1;
        long long ans = 0;
        while (l < r) {
            while (l < r && nums[l] + nums[r] <= 0) {
                ++l;
            }
            ans += r - l;
            --r;
        }
        return ans;
    }
};
```

#### Go

```go
func countPairs(nums1 []int, nums2 []int) (ans int64) {
	n := len(nums1)
	nums := make([]int, n)
	for i, x := range nums1 {
		nums[i] = x - nums2[i]
	}
	sort.Ints(nums)
	l, r := 0, n-1
	for l < r {
		for l < r && nums[l]+nums[r] <= 0 {
			l++
		}
		ans += int64(r - l)
		r--
	}
	return
}
```

#### TypeScript

```ts
function countPairs(nums1: number[], nums2: number[]): number {
    const n = nums1.length;
    const nums: number[] = [];
    for (let i = 0; i < n; ++i) {
        nums.push(nums1[i] - nums2[i]);
    }
    nums.sort((a, b) => a - b);
    let ans = 0;
    let [l, r] = [0, n - 1];
    while (l < r) {
        while (l < r && nums[l] + nums[r] <= 0) {
            ++l;
        }
        ans += r - l;
        --r;
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn count_pairs(nums1: Vec<i32>, nums2: Vec<i32>) -> i64 {
        let mut nums: Vec<i32> = nums1.iter().zip(nums2.iter()).map(|(a, b)| a - b).collect();
        nums.sort();
        let mut l = 0;
        let mut r = nums.len() - 1;
        let mut ans = 0;
        while l < r {
            while l < r && nums[l] + nums[r] <= 0 {
                l += 1;
            }
            ans += (r - l) as i64;
            r -= 1;
        }
        ans
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var countPairs = function (nums1, nums2) {
    const n = nums1.length;
    const nums = [];
    for (let i = 0; i < n; ++i) {
        nums.push(nums1[i] - nums2[i]);
    }
    nums.sort((a, b) => a - b);
    let ans = 0;
    let [l, r] = [0, n - 1];
    while (l < r) {
        while (l < r && nums[l] + nums[r] <= 0) {
            ++l;
        }
        ans += r - l;
        --r;
    }
    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1886. 判断矩阵经轮转后是否一致](https://leetcode.cn/problems/determine-whether-matrix-can-be-obtained-by-rotation){#1886}

{{< tabs "1886" >}}

{{% tab "python" %}}
```python
class Solution:
    def findRotation(self, mat: List[List[int]], target: List[List[int]]) -> bool:
        for _ in range(4):
            mat = [list(col) for col in zip(*mat[::-1])]
            if mat == target:
                return True
        return False
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean findRotation(int[][] mat, int[][] target) {
        int n = mat.length;
        for (int k = 0; k < 4; ++k) {
            int[][] g = new int[n][n];
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    g[i][j] = mat[j][n - i - 1];
                }
            }
            if (equals(g, target)) {
                return true;
            }
            mat = g;
        }
        return false;
    }

    private boolean equals(int[][] a, int[][] b) {
        int n = a.length;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (a[i][j] != b[i][j]) {
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
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        for (int k = 0; k < 4; ++k) {
            vector<vector<int>> g(n, vector<int>(n));
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    g[i][j] = mat[j][n - i - 1];
            if (g == target) return true;
            mat = g;
        }
        return false;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findRotation(mat [][]int, target [][]int) bool {
	n := len(mat)
	for k := 0; k < 4; k++ {
		g := make([][]int, n)
		for i := range g {
			g[i] = make([]int, n)
		}
		for i := 0; i < n; i++ {
			for j := 0; j < n; j++ {
				g[i][j] = mat[j][n-i-1]
			}
		}
		if equals(g, target) {
			return true
		}
		mat = g
	}
	return false
}

func equals(a, b [][]int) bool {
	for i, row := range a {
		for j, v := range row {
			if v != b[i][j] {
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
function findRotation(mat: number[][], target: number[][]): boolean {
    for (let k = 0; k < 4; k++) {
        rotate(mat);
        if (isEqual(mat, target)) {
            return true;
        }
    }
    return false;
}

function isEqual(A: number[][], B: number[][]) {
    const n = A.length;
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            if (A[i][j] !== B[i][j]) {
                return false;
            }
        }
    }
    return true;
}

function rotate(matrix: number[][]): void {
    const n = matrix.length;
    for (let i = 0; i < n >> 1; i++) {
        for (let j = 0; j < (n + 1) >> 1; j++) {
            [
                matrix[i][j],
                matrix[n - 1 - j][i],
                matrix[n - 1 - i][n - 1 - j],
                matrix[j][n - 1 - i],
            ] = [
                matrix[n - 1 - j][i],
                matrix[n - 1 - i][n - 1 - j],
                matrix[j][n - 1 - i],
                matrix[i][j],
            ];
        }
    }
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn find_rotation(mat: Vec<Vec<i32>>, target: Vec<Vec<i32>>) -> bool {
        let n = mat.len();
        let mut is_equal = [true; 4];
        for i in 0..n {
            for j in 0..n {
                if is_equal[0] && mat[i][j] != target[i][j] {
                    is_equal[0] = false;
                }
                if is_equal[1] && mat[i][j] != target[j][n - 1 - i] {
                    is_equal[1] = false;
                }
                if is_equal[2] && mat[i][j] != target[n - 1 - i][n - 1 - j] {
                    is_equal[2] = false;
                }
                if is_equal[3] && mat[i][j] != target[n - 1 - j][i] {
                    is_equal[3] = false;
                }
            }
        }
        is_equal.into_iter().any(|&v| v)
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个大小为 <code>n x n</code> 的二进制矩阵 <code>mat</code> 和 <code>target</code> 。现<strong> 以 90 度顺时针轮转 </strong>矩阵 <code>mat</code> 中的元素 <strong>若干次</strong> ，如果能够使 <code>mat</code> 与 <code>target</code> 一致，返回 <code>true</code> ；否则，返回<em> </em><code>false</code><em> 。</em></p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1800-1899/1886.Determine%20Whether%20Matrix%20Can%20Be%20Obtained%20By%20Rotation/images/grid3.png" style="width: 301px; height: 121px;" />
<pre>
<strong>输入：</strong>mat = [[0,1],[1,0]], target = [[1,0],[0,1]]
<strong>输出：</strong>true
<strong>解释：</strong>顺时针轮转 90 度一次可以使 mat 和 target 一致。
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1800-1899/1886.Determine%20Whether%20Matrix%20Can%20Be%20Obtained%20By%20Rotation/images/grid4.png" style="width: 301px; height: 121px;" />
<pre>
<strong>输入：</strong>mat = [[0,1],[1,1]], target = [[1,0],[0,1]]
<strong>输出：</strong>false
<strong>解释：</strong>无法通过轮转矩阵中的元素使 equal 与 target 一致。
</pre>

<p><strong>示例 3：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1800-1899/1886.Determine%20Whether%20Matrix%20Can%20Be%20Obtained%20By%20Rotation/images/grid4.png" style="width: 661px; height: 184px;" />
<pre>
<strong>输入：</strong>mat = [[0,0,0],[0,1,0],[1,1,1]], target = [[1,1,1],[0,1,0],[0,0,0]]
<strong>输出：</strong>true
<strong>解释：</strong>顺时针轮转 90 度两次可以使 mat 和 target 一致。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == mat.length == target.length</code></li>
	<li><code>n == mat[i].length == target[i].length</code></li>
	<li><code>1 <= n <= 10</code></li>
	<li><code>mat[i][j]</code> 和 <code>target[i][j]</code> 不是 <code>0</code> 就是 <code>1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟旋转

旋转矩阵，判断矩阵是否一致，旋转方式同 [48. 旋转图像](https://leetcode.cn/problems/rotate-image/)。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findRotation(self, mat: List[List[int]], target: List[List[int]]) -> bool:
        def rotate(matrix):
            n = len(matrix)
            for i in range(n // 2):
                for j in range(i, n - 1 - i):
                    t = matrix[i][j]
                    matrix[i][j] = matrix[n - j - 1][i]
                    matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1]
                    matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1]
                    matrix[j][n - i - 1] = t

        for _ in range(4):
            if mat == target:
                return True
            rotate(mat)
        return False
```

#### Java

```java
class Solution {
    public boolean findRotation(int[][] mat, int[][] target) {
        int times = 4;
        while (times-- > 0) {
            if (equals(mat, target)) {
                return true;
            }
            rotate(mat);
        }
        return false;
    }

    private void rotate(int[][] matrix) {
        int n = matrix.length;
        for (int i = 0; i < n / 2; ++i) {
            for (int j = i; j < n - 1 - i; ++j) {
                int t = matrix[i][j];
                matrix[i][j] = matrix[n - j - 1][i];
                matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
                matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
                matrix[j][n - i - 1] = t;
            }
        }
    }

    private boolean equals(int[][] nums1, int[][] nums2) {
        int n = nums1.length;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (nums1[i][j] != nums2[i][j]) {
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
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        for (int k = 0; k < 4; ++k) {
            vector<vector<int>> g(n, vector<int>(n));
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    g[i][j] = mat[j][n - i - 1];
            if (g == target) return true;
            mat = g;
        }
        return false;
    }
};
```

#### Go

```go
func findRotation(mat [][]int, target [][]int) bool {
	n := len(mat)
	for k := 0; k < 4; k++ {
		g := make([][]int, n)
		for i := range g {
			g[i] = make([]int, n)
		}
		for i := 0; i < n; i++ {
			for j := 0; j < n; j++ {
				g[i][j] = mat[j][n-i-1]
			}
		}
		if equals(g, target) {
			return true
		}
		mat = g
	}
	return false
}

func equals(a, b [][]int) bool {
	for i, row := range a {
		for j, v := range row {
			if v != b[i][j] {
				return false
			}
		}
	}
	return true
}
```

#### TypeScript

```ts
function findRotation(mat: number[][], target: number[][]): boolean {
    for (let k = 0; k < 4; k++) {
        rotate(mat);
        if (isEqual(mat, target)) {
            return true;
        }
    }
    return false;
}

function isEqual(A: number[][], B: number[][]) {
    const n = A.length;
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            if (A[i][j] !== B[i][j]) {
                return false;
            }
        }
    }
    return true;
}

function rotate(matrix: number[][]): void {
    const n = matrix.length;
    for (let i = 0; i < n >> 1; i++) {
        for (let j = 0; j < (n + 1) >> 1; j++) {
            [
                matrix[i][j],
                matrix[n - 1 - j][i],
                matrix[n - 1 - i][n - 1 - j],
                matrix[j][n - 1 - i],
            ] = [
                matrix[n - 1 - j][i],
                matrix[n - 1 - i][n - 1 - j],
                matrix[j][n - 1 - i],
                matrix[i][j],
            ];
        }
    }
}
```

#### Rust

```rust
impl Solution {
    pub fn find_rotation(mat: Vec<Vec<i32>>, target: Vec<Vec<i32>>) -> bool {
        let n = mat.len();
        let mut is_equal = [true; 4];
        for i in 0..n {
            for j in 0..n {
                if is_equal[0] && mat[i][j] != target[i][j] {
                    is_equal[0] = false;
                }
                if is_equal[1] && mat[i][j] != target[j][n - 1 - i] {
                    is_equal[1] = false;
                }
                if is_equal[2] && mat[i][j] != target[n - 1 - i][n - 1 - j] {
                    is_equal[2] = false;
                }
                if is_equal[3] && mat[i][j] != target[n - 1 - j][i] {
                    is_equal[3] = false;
                }
            }
        }
        is_equal.into_iter().any(|&v| v)
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：原地比较

此题不同于 [48. 旋转图像](https://leetcode.cn/problems/rotate-image/)，并不要求改动原数组，因此，只要比较对应的位置即可。

| 旋转度数 | A      | B              |
| -------- | ------ | -------------- |
| 0        | `i, j` | `i, j`         |
| 90       | `i, j` | `j, n - i`     |
| 180      | `i, j` | `n - i, n - j` |
| 270      | `i, j` | `n - j, i`     |

> `n = A.length - 1 = B.length - 1`

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findRotation(self, mat: List[List[int]], target: List[List[int]]) -> bool:
        for _ in range(4):
            mat = [list(col) for col in zip(*mat[::-1])]
            if mat == target:
                return True
        return False
```

#### Java

```java
class Solution {
    public boolean findRotation(int[][] mat, int[][] target) {
        int n = mat.length;
        for (int k = 0; k < 4; ++k) {
            int[][] g = new int[n][n];
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    g[i][j] = mat[j][n - i - 1];
                }
            }
            if (equals(g, target)) {
                return true;
            }
            mat = g;
        }
        return false;
    }

    private boolean equals(int[][] a, int[][] b) {
        int n = a.length;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (a[i][j] != b[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1887. 使数组元素相等的减少操作次数](https://leetcode.cn/problems/reduction-operations-to-make-the-array-elements-equal){#1887}

{{< tabs "1887" >}}

{{% tab "python" %}}
```python
class Solution:
    def reductionOperations(self, nums: List[int]) -> int:
        nums.sort()
        ans = cnt = 0
        for a, b in pairwise(nums):
            if a != b:
                cnt += 1
            ans += cnt
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int reductionOperations(int[] nums) {
        Arrays.sort(nums);
        int ans = 0, cnt = 0;
        for (int i = 1; i < nums.length; ++i) {
            if (nums[i] != nums[i - 1]) {
                ++cnt;
            }
            ans += cnt;
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
    int reductionOperations(vector<int>& nums) {
        ranges::sort(nums);
        int ans = 0, cnt = 0;
        for (int i = 1; i < nums.size(); ++i) {
            cnt += nums[i] != nums[i - 1];
            ans += cnt;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func reductionOperations(nums []int) (ans int) {
	sort.Ints(nums)
	cnt := 0
	for i, x := range nums[1:] {
		if x != nums[i] {
			cnt++
		}
		ans += cnt
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function reductionOperations(nums: number[]): number {
    nums.sort((a, b) => a - b);
    let [ans, cnt] = [0, 0];
    for (let i = 1; i < nums.length; ++i) {
        if (nums[i] !== nums[i - 1]) {
            ++cnt;
        }
        ans += cnt;
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var reductionOperations = function (nums) {
    nums.sort((a, b) => a - b);
    let [ans, cnt] = [0, 0];
    for (let i = 1; i < nums.length; ++i) {
        if (nums[i] !== nums[i - 1]) {
            ++cnt;
        }
        ans += cnt;
    }
    return ans;
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int ReductionOperations(int[] nums) {
        Array.Sort(nums);
        int ans = 0, cnt = 0;
        for (int i = 1; i < nums.Length; i++) {
            if (nums[i] != nums[i - 1]) {
                ++cnt;
            }
            ans += cnt;
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

<p>给你一个整数数组 <code>nums</code> ，你的目标是令 <code>nums</code> 中的所有元素相等。完成一次减少操作需要遵照下面的几个步骤：</p>

<ol>
	<li>找出 <code>nums</code> 中的 <strong>最大</strong> 值。记这个值为 <code>largest</code> 并取其下标 <code>i</code> （<strong>下标从 0 开始计数</strong>）。如果有多个元素都是最大值，则取最小的 <code>i</code> 。</li>
	<li>找出 <code>nums</code> 中的 <strong>下一个最大</strong> 值，这个值 <strong>严格小于</strong> <code>largest</code> ，记为 <code>nextLargest</code> 。</li>
	<li>将 <code>nums[i]</code> 减少到 <code>nextLargest</code> 。</li>
</ol>

<p>返回使<em> </em><code>nums</code><em> </em>中的所有元素相等的操作次数。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [5,1,3]
<strong>输出：</strong>3
<strong>解释：</strong>需要 3 次操作使 nums 中的所有元素相等：
1. largest = 5 下标为 0 。nextLargest = 3 。将 nums[0] 减少到 3 。nums = [<strong>3</strong>,1,3] 。
2. largest = 3 下标为 0 。nextLargest = 1 。将 nums[0] 减少到 1 。nums = [<strong>1</strong>,1,3] 。
3. largest = 3 下标为 2 。nextLargest = 1 。将 nums[2] 减少到 1 。nums = [<strong>1</strong>,1,<strong>1</strong>] 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,1,1]
<strong>输出：</strong>0
<strong>解释：</strong>nums 中的所有元素已经是相等的。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,1,2,2,3]
<strong>输出：</strong>4
<strong>解释：</strong>需要 4 次操作使 nums 中的所有元素相等：
1. largest = 3 下标为 4 。nextLargest = 2 。将 nums[4] 减少到 2 。nums = [1,1,2,2,<strong>2</strong>] 。
2. largest = 2 下标为 2 。nextLargest = 1 。将 nums[2] 减少到 1 。nums = [1,1,<strong>1</strong>,2,2] 。 
3. largest = 2 下标为 3 。nextLargest = 1 。将 nums[3] 减少到 1 。nums = [1,1,1,<strong>1</strong>,2] 。 
4. largest = 2 下标为 4 。nextLargest = 1 。将 nums[4] 减少到 1 。nums = [1,1,1,1,<strong>1</strong>] 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= nums.length <= 5 * 10<sup>4</sup></code></li>
	<li><code>1 <= nums[i] <= 5 * 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序

我们首先对数组 $\textit{nums}$ 进行排序，然后从数组的第二个元素开始遍历，如果当前元素和前一个元素不相等，那么我们就将 $\textit{cnt}$ 加一，表示我们需要将当前元素减小到最小值的操作次数。然后我们将 $\textit{ans}$ 加上 $\textit{cnt}$，继续遍历下一个元素。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 是数组 $\textit{nums}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def reductionOperations(self, nums: List[int]) -> int:
        nums.sort()
        ans = cnt = 0
        for a, b in pairwise(nums):
            if a != b:
                cnt += 1
            ans += cnt
        return ans
```

#### Java

```java
class Solution {
    public int reductionOperations(int[] nums) {
        Arrays.sort(nums);
        int ans = 0, cnt = 0;
        for (int i = 1; i < nums.length; ++i) {
            if (nums[i] != nums[i - 1]) {
                ++cnt;
            }
            ans += cnt;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        ranges::sort(nums);
        int ans = 0, cnt = 0;
        for (int i = 1; i < nums.size(); ++i) {
            cnt += nums[i] != nums[i - 1];
            ans += cnt;
        }
        return ans;
    }
};
```

#### Go

```go
func reductionOperations(nums []int) (ans int) {
	sort.Ints(nums)
	cnt := 0
	for i, x := range nums[1:] {
		if x != nums[i] {
			cnt++
		}
		ans += cnt
	}
	return
}
```

#### TypeScript

```ts
function reductionOperations(nums: number[]): number {
    nums.sort((a, b) => a - b);
    let [ans, cnt] = [0, 0];
    for (let i = 1; i < nums.length; ++i) {
        if (nums[i] !== nums[i - 1]) {
            ++cnt;
        }
        ans += cnt;
    }
    return ans;
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var reductionOperations = function (nums) {
    nums.sort((a, b) => a - b);
    let [ans, cnt] = [0, 0];
    for (let i = 1; i < nums.length; ++i) {
        if (nums[i] !== nums[i - 1]) {
            ++cnt;
        }
        ans += cnt;
    }
    return ans;
};
```

#### C#

```cs
public class Solution {
    public int ReductionOperations(int[] nums) {
        Array.Sort(nums);
        int ans = 0, cnt = 0;
        for (int i = 1; i < nums.Length; i++) {
            if (nums[i] != nums[i - 1]) {
                ++cnt;
            }
            ans += cnt;
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

# [1888. 使二进制字符串字符交替的最少反转次数](https://leetcode.cn/problems/minimum-number-of-flips-to-make-the-binary-string-alternating){#1888}

{{< tabs "1888" >}}

{{% tab "python" %}}
```python
class Solution:
    def minFlips(self, s: str) -> int:
        n = len(s)
        target = "01"
        cnt = sum(c != target[i & 1] for i, c in enumerate(s))
        ans = min(cnt, n - cnt)
        for i in range(n):
            cnt -= s[i] != target[i & 1]
            cnt += s[i] != target[(i + n) & 1]
            ans = min(ans, cnt, n - cnt)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minFlips(String s) {
        int n = s.length();
        String target = "01";
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (s.charAt(i) != target.charAt(i & 1)) {
                ++cnt;
            }
        }
        int ans = Math.min(cnt, n - cnt);
        for (int i = 0; i < n; ++i) {
            if (s.charAt(i) != target.charAt(i & 1)) {
                --cnt;
            }
            if (s.charAt(i) != target.charAt((i + n) & 1)) {
                ++cnt;
            }
            ans = Math.min(ans, Math.min(cnt, n - cnt));
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
    int minFlips(string s) {
        int n = s.size();
        string target = "01";
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] != target[i & 1]) {
                ++cnt;
            }
        }
        int ans = min(cnt, n - cnt);
        for (int i = 0; i < n; ++i) {
            if (s[i] != target[i & 1]) {
                --cnt;
            }
            if (s[i] != target[(i + n) & 1]) {
                ++cnt;
            }
            ans = min({ans, cnt, n - cnt});
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minFlips(s string) int {
	n := len(s)
	target := "01"
	cnt := 0
	for i := range s {
		if s[i] != target[i&1] {
			cnt++
		}
	}
	ans := min(cnt, n-cnt)
	for i := range s {
		if s[i] != target[i&1] {
			cnt--
		}
		if s[i] != target[(i+n)&1] {
			cnt++
		}
		ans = min(ans, min(cnt, n-cnt))
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minFlips(s: string): number {
    const n = s.length;
    const target = '01';
    let cnt = 0;
    for (let i = 0; i < n; ++i) {
        if (s[i] !== target[i & 1]) {
            ++cnt;
        }
    }
    let ans = Math.min(cnt, n - cnt);
    for (let i = 0; i < n; ++i) {
        if (s[i] !== target[i & 1]) {
            --cnt;
        }
        if (s[i] !== target[(i + n) & 1]) {
            ++cnt;
        }
        ans = Math.min(ans, cnt, n - cnt);
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

<p>给你一个二进制字符串 <code>s</code> 。你可以按任意顺序执行以下两种操作任意次：</p>

<ul>
	<li><strong>类型 1 ：删除</strong> 字符串 <code>s</code> 的第一个字符并将它 <strong>添加</strong> 到字符串结尾。</li>
	<li><strong>类型 2 ：选择 </strong>字符串 <code>s</code> 中任意一个字符并将该字符 <strong>反转 </strong>，也就是如果值为 <code>'0'</code> ，则反转得到 <code>'1'</code> ，反之亦然。</li>
</ul>

<p>请你返回使 <code>s</code> 变成 <strong>交替</strong> 字符串的前提下， <strong>类型 2 </strong>的 <strong>最少</strong> 操作次数 。</p>

<p>我们称一个字符串是 <strong>交替</strong> 的，需要满足任意相邻字符都不同。</p>

<ul>
	<li>比方说，字符串 <code>"010"</code> 和 <code>"1010"</code> 都是交替的，但是字符串 <code>"0100"</code> 不是。</li>
</ul>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>s = "111000"
<b>输出：</b>2
<b>解释：</b>执行第一种操作两次，得到 s = "100011" 。
然后对第三个和第六个字符执行第二种操作，得到 s = "10<strong>1</strong>01<strong>0</strong>" 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>s = "010"
<b>输出：</b>0
<strong>解释：</strong>字符串已经是交替的。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>s = "1110"
<b>输出：</b>1
<b>解释：</b>对第二个字符执行第二种操作，得到 s = "1<strong>0</strong>10" 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s[i]</code> 要么是 <code>'0'</code> ，要么是 <code>'1'</code> 。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：滑动窗口

我们注意到，操作 $1$ 的作用实际上是让字符串成为一个环，而操作 $2$ 是使得环中的一段长度为 $n$ 的子串变成交替二进制串。

因此，我们只需要枚举每个长度为 $n$ 的子串，计算将其变成交替二进制串的代价，取最小值即可。

时间复杂度 $O(n)$，其中 $n$ 是字符串的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minFlips(self, s: str) -> int:
        n = len(s)
        target = "01"
        cnt = sum(c != target[i & 1] for i, c in enumerate(s))
        ans = min(cnt, n - cnt)
        for i in range(n):
            cnt -= s[i] != target[i & 1]
            cnt += s[i] != target[(i + n) & 1]
            ans = min(ans, cnt, n - cnt)
        return ans
```

#### Java

```java
class Solution {
    public int minFlips(String s) {
        int n = s.length();
        String target = "01";
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (s.charAt(i) != target.charAt(i & 1)) {
                ++cnt;
            }
        }
        int ans = Math.min(cnt, n - cnt);
        for (int i = 0; i < n; ++i) {
            if (s.charAt(i) != target.charAt(i & 1)) {
                --cnt;
            }
            if (s.charAt(i) != target.charAt((i + n) & 1)) {
                ++cnt;
            }
            ans = Math.min(ans, Math.min(cnt, n - cnt));
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        string target = "01";
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] != target[i & 1]) {
                ++cnt;
            }
        }
        int ans = min(cnt, n - cnt);
        for (int i = 0; i < n; ++i) {
            if (s[i] != target[i & 1]) {
                --cnt;
            }
            if (s[i] != target[(i + n) & 1]) {
                ++cnt;
            }
            ans = min({ans, cnt, n - cnt});
        }
        return ans;
    }
};
```

#### Go

```go
func minFlips(s string) int {
	n := len(s)
	target := "01"
	cnt := 0
	for i := range s {
		if s[i] != target[i&1] {
			cnt++
		}
	}
	ans := min(cnt, n-cnt)
	for i := range s {
		if s[i] != target[i&1] {
			cnt--
		}
		if s[i] != target[(i+n)&1] {
			cnt++
		}
		ans = min(ans, min(cnt, n-cnt))
	}
	return ans
}
```

#### TypeScript

```ts
function minFlips(s: string): number {
    const n = s.length;
    const target = '01';
    let cnt = 0;
    for (let i = 0; i < n; ++i) {
        if (s[i] !== target[i & 1]) {
            ++cnt;
        }
    }
    let ans = Math.min(cnt, n - cnt);
    for (let i = 0; i < n; ++i) {
        if (s[i] !== target[i & 1]) {
            --cnt;
        }
        if (s[i] !== target[(i + n) & 1]) {
            ++cnt;
        }
        ans = Math.min(ans, cnt, n - cnt);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1889. 装包裹的最小浪费空间](https://leetcode.cn/problems/minimum-space-wasted-from-packaging){#1889}

{{< tabs "1889" >}}

{{% tab "python" %}}
```python
class Solution:
    def minWastedSpace(self, packages: List[int], boxes: List[List[int]]) -> int:
        mod = 10**9 + 7
        ans = inf
        packages.sort()
        for box in boxes:
            box.sort()
            if packages[-1] > box[-1]:
                continue
            s = i = 0
            for b in box:
                j = bisect_right(packages, b, lo=i)
                s += (j - i) * b
                i = j
            ans = min(ans, s)
        if ans == inf:
            return -1
        return (ans - sum(packages)) % mod
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minWastedSpace(int[] packages, int[][] boxes) {
        int n = packages.length;
        final long inf = 1L << 62;
        Arrays.sort(packages);
        long ans = inf;
        for (var box : boxes) {
            Arrays.sort(box);
            if (packages[n - 1] > box[box.length - 1]) {
                continue;
            }
            long s = 0;
            int i = 0;
            for (int b : box) {
                int j = search(packages, b, i);
                s += 1L * (j - i) * b;
                i = j;
            }
            ans = Math.min(ans, s);
        }
        if (ans == inf) {
            return -1;
        }
        long s = 0;
        for (int p : packages) {
            s += p;
        }
        final int mod = (int) 1e9 + 7;
        return (int) ((ans - s) % mod);
    }

    private int search(int[] nums, int x, int l) {
        int r = nums.length;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] > x) {
                r = mid;
            } else {
                l = mid + 1;
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
    int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
        int n = packages.size(), m = boxes.size();
        sort(packages.begin(), packages.end());
        const int mod = 1e9 + 7;
        const long long inf = 1LL << 62;
        long long ans = inf;
        for (auto& box : boxes) {
            sort(box.begin(), box.end());
            if (packages.back() > box.back()) {
                continue;
            }
            int i = 0;
            long long s = 0;
            for (auto& b : box) {
                int j = upper_bound(packages.begin() + i, packages.end(), b) - packages.begin();
                s += 1LL * (j - i) * b;
                i = j;
            }
            ans = min(ans, s);
        }
        return ans == inf ? -1 : (ans - accumulate(packages.begin(), packages.end(), 0LL)) % mod;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minWastedSpace(packages []int, boxes [][]int) int {
	n := len(packages)
	inf := 1 << 62
	sort.Ints(packages)
	ans := inf
	for _, box := range boxes {
		sort.Ints(box)
		if packages[n-1] > box[len(box)-1] {
			continue
		}
		s, i := 0, 0
		for _, b := range box {
			j := sort.SearchInts(packages[i:], b+1) + i
			s += (j - i) * b
			i = j
		}
		ans = min(ans, s)
	}
	if ans == inf {
		return -1
	}
	s := 0
	for _, p := range packages {
		s += p
	}
	const mod = 1e9 + 7
	return (ans - s) % mod
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minWastedSpace(packages: number[], boxes: number[][]): number {
    const n = packages.length;
    const inf = Infinity;
    packages.sort((a, b) => a - b);
    let ans = inf;
    for (const box of boxes) {
        box.sort((a, b) => a - b);
        if (packages[n - 1] > box[box.length - 1]) {
            continue;
        }
        let s = 0;
        let i = 0;
        for (const b of box) {
            const j = search(packages, b, i);
            s += (j - i) * b;
            i = j;
        }
        ans = Math.min(ans, s);
    }
    if (ans === inf) {
        return -1;
    }
    const s = packages.reduce((a, b) => a + b, 0);
    return (ans - s) % 1000000007;
}

function search(nums: number[], x: number, l: number): number {
    let r = nums.length;
    while (l < r) {
        const mid = (l + r) >> 1;
        if (nums[mid] > x) {
            r = mid;
        } else {
            l = mid + 1;
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

<p>给你 <code>n</code> 个包裹，你需要把它们装在箱子里，<strong>每个箱子装一个包裹</strong>。总共有 <code>m</code> 个供应商提供 <strong>不同尺寸</strong> 的箱子（每个规格都有无数个箱子）。如果一个包裹的尺寸 <strong>小于等于</strong> 一个箱子的尺寸，那么这个包裹就可以放入这个箱子之中。</p>

<p>包裹的尺寸用一个整数数组 <code>packages</code> 表示，其中 <code>packages[i]</code> 是第 <code>i</code> 个包裹的尺寸。供应商用二维数组 <code>boxes</code> 表示，其中 <code>boxes[j]</code> 是第 <code>j</code> 个供应商提供的所有箱子尺寸的数组。</p>

<p>你想要选择 <strong>一个供应商</strong> 并只使用该供应商提供的箱子，使得 <strong>总浪费空间最小</strong> 。对于每个装了包裹的箱子，我们定义 <strong>浪费的</strong> 空间等于 <code>箱子的尺寸 - 包裹的尺寸</code> 。<strong>总浪费空间</strong> 为 <strong>所有</strong> 箱子中浪费空间的总和。</p>

<ul>
	<li>比方说，如果你想要用尺寸数组为 <code>[4,8]</code> 的箱子装下尺寸为 <code>[2,3,5]</code> 的包裹，你可以将尺寸为 <code>2</code> 和 <code>3</code> 的两个包裹装入两个尺寸为 <code>4</code> 的箱子中，同时把尺寸为 <code>5</code> 的包裹装入尺寸为 <code>8</code> 的箱子中。总浪费空间为 <code>(4-2) + (4-3) + (8-5) = 6</code> 。</li>
</ul>

<p>请你选择 <strong>最优</strong> 箱子供应商，使得 <strong>总浪费空间最小</strong> 。如果 <strong>无法</strong> 将所有包裹放入箱子中，请你返回 <code>-1</code> 。由于答案可能会 <strong>很大</strong> ，请返回它对<strong> </strong><code>10<sup>9</sup> + 7</code> <b>取余</b> 的结果。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>packages = [2,3,5], boxes = [[4,8],[2,8]]
<b>输出：</b>6
<b>解释：</b>选择第一个供应商最优，用两个尺寸为 4 的箱子和一个尺寸为 8 的箱子。
总浪费空间为 (4-2) + (4-3) + (8-5) = 6 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>packages = [2,3,5], boxes = [[1,4],[2,3],[3,4]]
<b>输出：</b>-1
<b>解释：</b>没有箱子能装下尺寸为 5 的包裹。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>packages = [3,5,8,10,11,12], boxes = [[12],[11,9],[10,5,14]]
<b>输出：</b>9
<b>解释：</b>选择第三个供应商最优，用两个尺寸为 5 的箱子，两个尺寸为 10 的箱子和两个尺寸为 14 的箱子。
总浪费空间为 (5-3) + (5-5) + (10-8) + (10-10) + (14-11) + (14-12) = 9 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == packages.length</code></li>
	<li><code>m == boxes.length</code></li>
	<li><code>1 <= n <= 10<sup>5</sup></code></li>
	<li><code>1 <= m <= 10<sup>5</sup></code></li>
	<li><code>1 <= packages[i] <= 10<sup>5</sup></code></li>
	<li><code>1 <= boxes[j].length <= 10<sup>5</sup></code></li>
	<li><code>1 <= boxes[j][k] <= 10<sup>5</sup></code></li>
	<li><code>sum(boxes[j].length) <= 10<sup>5</sup></code></li>
	<li><code>boxes[j]</code> 中的元素 <strong>互不相同</strong> 。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 二分查找

我们首先对包裹的尺寸数组 $packages$ 进行排序。

然后遍历每个供应商的箱子数组 $boxes$，对于每个箱子数组 $boxes$，我们也对其进行排序。

如果当前箱子数组中最大的箱子尺寸小于包裹数组中最大的包裹尺寸，那么我们就可以跳过这个供应商，因为这个供应商的箱子无法装下最大的包裹。否则，我们从小到大遍历当前供应商的每个箱子 $b$，用一个指针 $i$ 指向当前待装箱的包裹。

接下来，我们在数组 $packages$ 中二分查找，找到第一个尺寸大于 $b$ 的包裹 $packages[j]$。那么我们可以用箱子 $b$ 装下 $packages[i..j-1]$ 中的所有包裹，此时总空间为 $b \times (j - i)$。然后我们将指针 $i$ 移动到 $j$，继续寻找下一个箱子的装包情况。

遍历完该供应商的所有箱子后，我们就可以得到该供应商所需的箱子总空间。我们遍历所有供应商，找到所需箱子的最小总空间，那么浪费的空间就是总空间减去所有包裹的总尺寸。

时间复杂度 $O(n \times \log n + l \times \log l + l \times \log n)$，空间复杂度 $O(\log n + \log l)$。其中 $n$ 是包裹的数量，而 $l$ 是所有箱子的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minWastedSpace(self, packages: List[int], boxes: List[List[int]]) -> int:
        mod = 10**9 + 7
        ans = inf
        packages.sort()
        for box in boxes:
            box.sort()
            if packages[-1] > box[-1]:
                continue
            s = i = 0
            for b in box:
                j = bisect_right(packages, b, lo=i)
                s += (j - i) * b
                i = j
            ans = min(ans, s)
        if ans == inf:
            return -1
        return (ans - sum(packages)) % mod
```

#### Java

```java
class Solution {
    public int minWastedSpace(int[] packages, int[][] boxes) {
        int n = packages.length;
        final long inf = 1L << 62;
        Arrays.sort(packages);
        long ans = inf;
        for (var box : boxes) {
            Arrays.sort(box);
            if (packages[n - 1] > box[box.length - 1]) {
                continue;
            }
            long s = 0;
            int i = 0;
            for (int b : box) {
                int j = search(packages, b, i);
                s += 1L * (j - i) * b;
                i = j;
            }
            ans = Math.min(ans, s);
        }
        if (ans == inf) {
            return -1;
        }
        long s = 0;
        for (int p : packages) {
            s += p;
        }
        final int mod = (int) 1e9 + 7;
        return (int) ((ans - s) % mod);
    }

    private int search(int[] nums, int x, int l) {
        int r = nums.length;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] > x) {
                r = mid;
            } else {
                l = mid + 1;
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
    int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
        int n = packages.size(), m = boxes.size();
        sort(packages.begin(), packages.end());
        const int mod = 1e9 + 7;
        const long long inf = 1LL << 62;
        long long ans = inf;
        for (auto& box : boxes) {
            sort(box.begin(), box.end());
            if (packages.back() > box.back()) {
                continue;
            }
            int i = 0;
            long long s = 0;
            for (auto& b : box) {
                int j = upper_bound(packages.begin() + i, packages.end(), b) - packages.begin();
                s += 1LL * (j - i) * b;
                i = j;
            }
            ans = min(ans, s);
        }
        return ans == inf ? -1 : (ans - accumulate(packages.begin(), packages.end(), 0LL)) % mod;
    }
};
```

#### Go

```go
func minWastedSpace(packages []int, boxes [][]int) int {
	n := len(packages)
	inf := 1 << 62
	sort.Ints(packages)
	ans := inf
	for _, box := range boxes {
		sort.Ints(box)
		if packages[n-1] > box[len(box)-1] {
			continue
		}
		s, i := 0, 0
		for _, b := range box {
			j := sort.SearchInts(packages[i:], b+1) + i
			s += (j - i) * b
			i = j
		}
		ans = min(ans, s)
	}
	if ans == inf {
		return -1
	}
	s := 0
	for _, p := range packages {
		s += p
	}
	const mod = 1e9 + 7
	return (ans - s) % mod
}
```

#### TypeScript

```ts
function minWastedSpace(packages: number[], boxes: number[][]): number {
    const n = packages.length;
    const inf = Infinity;
    packages.sort((a, b) => a - b);
    let ans = inf;
    for (const box of boxes) {
        box.sort((a, b) => a - b);
        if (packages[n - 1] > box[box.length - 1]) {
            continue;
        }
        let s = 0;
        let i = 0;
        for (const b of box) {
            const j = search(packages, b, i);
            s += (j - i) * b;
            i = j;
        }
        ans = Math.min(ans, s);
    }
    if (ans === inf) {
        return -1;
    }
    const s = packages.reduce((a, b) => a + b, 0);
    return (ans - s) % 1000000007;
}

function search(nums: number[], x: number, l: number): number {
    let r = nums.length;
    while (l < r) {
        const mid = (l + r) >> 1;
        if (nums[mid] > x) {
            r = mid;
        } else {
            l = mid + 1;
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
