---
title: "2800_包含三个字符串的最短字符串"
date: 2025-10-08T18:39:37+08:00
weight: 1
tags: [JavaScript, 位运算, 动态规划, 哈希表, 字符串, 排序, 数学, 数组, 数论, 枚举, 贪心, 链表]
---

{{< markmap >}}
### [2800_包含三个字符串的最短字符串](#2800)
#### [贪心](#2800)
#### [字符串](#2800)
#### [枚举](#2800)
### [2801_统计范围内的步进数字数目](#2801)
#### [字符串](#2801)
#### [动态规划](#2801)
### [2802_找出第 K 个幸运数字 🔒](#2802)
#### [位运算](#2802)
#### [数学](#2802)
#### [字符串](#2802)
### [2803_阶乘生成器 🔒](#2803)
#### [JavaScript](#2803)
### [2804_数组原型的 forEach 方法 🔒](#2804)
#### [JavaScript](#2804)
### [2805_自定义间隔 🔒](#2805)
#### [JavaScript](#2805)
### [2806_取整购买后的账户余额](#2806)
#### [数学](#2806)
### [2807_在链表中插入最大公约数](#2807)
#### [链表](#2807)
#### [数学](#2807)
#### [数论](#2807)
### [2808_使循环数组所有元素相等的最少秒数](#2808)
#### [数组](#2808)
#### [哈希表](#2808)
### [2809_使数组和小于等于 x 的最少时间](#2809)
#### [数组](#2809)
#### [动态规划](#2809)
#### [排序](#2809)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2800_包含三个字符串的最短字符串
___
#### 贪心
___
#### 字符串
___
#### 枚举
---
### 2801_统计范围内的步进数字数目
___
#### 字符串
___
#### 动态规划
---
### 2802_找出第 K 个幸运数字 🔒
___
#### 位运算
___
#### 数学
___
#### 字符串
---
### 2803_阶乘生成器 🔒
___
#### JavaScript
---
### 2804_数组原型的 forEach 方法 🔒
___
#### JavaScript
---
### 2805_自定义间隔 🔒
___
#### JavaScript
---
### 2806_取整购买后的账户余额
___
#### 数学
---
### 2807_在链表中插入最大公约数
___
#### 链表
___
#### 数学
___
#### 数论
---
### 2808_使循环数组所有元素相等的最少秒数
___
#### 数组
___
#### 哈希表
---
### 2809_使数组和小于等于 x 的最少时间
___
#### 数组
___
#### 动态规划
___
#### 排序
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| JavaScript | 位运算 | 动态规划 |
| 哈希表 | 字符串 | 排序 |
| 数学 | 数组 | 数论 |
| 枚举 | 贪心 | 链表 |

# [2800. 包含三个字符串的最短字符串](https://leetcode.cn/problems/shortest-string-that-contains-three-strings){#2800}

{{< tabs "2800" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumString(self, a: str, b: str, c: str) -> str:
        def f(s: str, t: str) -> str:
            if s in t:
                return t
            if t in s:
                return s
            p = t + "#" + s + "$"
            n = len(p)
            next = [0] * n
            next[0] = -1
            i, j = 2, 0
            while i < n:
                if p[i - 1] == p[j]:
                    j += 1
                    next[i] = j
                    i += 1
                elif j:
                    j = next[j]
                else:
                    next[i] = 0
                    i += 1
            return s + t[next[-1] :]

        ans = ""
        for a, b, c in permutations((a, b, c)):
            s = f(f(a, b), c)
            if ans == "" or len(s) < len(ans) or (len(s) == len(ans) and s < ans):
                ans = s
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String minimumString(String a, String b, String c) {
        String[] s = {a, b, c};
        int[][] perm = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 1, 0}, {2, 0, 1}};
        String ans = "";
        for (var p : perm) {
            int i = p[0], j = p[1], k = p[2];
            String t = f(f(s[i], s[j]), s[k]);
            if ("".equals(ans) || t.length() < ans.length()
                || (t.length() == ans.length() && t.compareTo(ans) < 0)) {
                ans = t;
            }
        }
        return ans;
    }

    private String f(String s, String t) {
        if (s.contains(t)) {
            return s;
        }
        if (t.contains(s)) {
            return t;
        }
        char[] p = (t + "#" + s + "$").toCharArray();
        int n = p.length;
        int[] next = new int[n];
        next[0] = -1;
        for (int i = 2, j = 0; i < n;) {
            if (p[i - 1] == p[j]) {
                next[i++] = ++j;
            } else if (j > 0) {
                j = next[j];
            } else {
                next[i++] = 0;
            }
        }
        return s + t.substring(next[n - 1]);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string minimumString(string a, string b, string c) {
        vector<string> s = {a, b, c};
        vector<vector<int>> perm = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 1, 0}, {2, 0, 1}};
        string ans = "";
        for (auto& p : perm) {
            int i = p[0], j = p[1], k = p[2];
            string t = f(f(s[i], s[j]), s[k]);
            if (ans == "" || t.size() < ans.size() || (t.size() == ans.size() && t < ans)) {
                ans = t;
            }
        }
        return ans;
    }

    string f(string s, string t) {
        if (s.find(t) != string::npos) {
            return s;
        }
        if (t.find(s) != string::npos) {
            return t;
        }
        string p = t + "#" + s + "$";
        int n = p.size();
        int next[n];
        next[0] = -1;
        next[1] = 0;
        for (int i = 2, j = 0; i < n;) {
            if (p[i - 1] == p[j]) {
                next[i++] = ++j;
            } else if (j > 0) {
                j = next[j];
            } else {
                next[i++] = 0;
            }
        }
        return s + t.substr(next[n - 1]);
    };
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumString(a string, b string, c string) string {
	f := func(s, t string) string {
		if strings.Contains(s, t) {
			return s
		}
		if strings.Contains(t, s) {
			return t
		}
		p := t + "#" + s + "$"
		n := len(p)
		next := make([]int, n)
		next[0] = -1
		for i, j := 2, 0; i < n; {
			if p[i-1] == p[j] {
				j++
				next[i] = j
				i++
			} else if j > 0 {
				j = next[j]
			} else {
				next[i] = 0
				i++
			}
		}
		return s + t[next[n-1]:]
	}
	s := [3]string{a, b, c}
	ans := ""
	for _, p := range [][]int{{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0}} {
		i, j, k := p[0], p[1], p[2]
		t := f(f(s[i], s[j]), s[k])
		if ans == "" || len(t) < len(ans) || (len(t) == len(ans) && t < ans) {
			ans = t
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumString(a: string, b: string, c: string): string {
    const f = (s: string, t: string): string => {
        if (s.includes(t)) {
            return s;
        }
        if (t.includes(s)) {
            return t;
        }
        const p = t + '#' + s + '$';
        const n = p.length;
        const next: number[] = Array(n).fill(0);
        next[0] = -1;
        for (let i = 2, j = 0; i < n; ) {
            if (p[i - 1] === p[j]) {
                next[i++] = ++j;
            } else if (j) {
                j = next[j];
            } else {
                next[i++] = 0;
            }
        }
        return s + t.slice(next[n - 1]);
    };
    const s: string[] = [a, b, c];
    const perm: number[][] = [
        [0, 1, 2],
        [0, 2, 1],
        [1, 0, 2],
        [1, 2, 0],
        [2, 0, 1],
        [2, 1, 0],
    ];
    let ans = '';
    for (const [i, j, k] of perm) {
        const t = f(f(s[i], s[j]), s[k]);
        if (ans === '' || t.length < ans.length || (t.length === ans.length && t < ans)) {
            ans = t;
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    fn f(s1: String, s2: String) -> String {
        if s1.contains(&s2) {
            return s1;
        }
        if s2.contains(&s1) {
            return s2;
        }
        for i in 0..s1.len() {
            let s = &s1[i..];
            if s2.starts_with(s) {
                let n = s.len();
                return s1 + &s2[n..];
            }
        }
        s1 + s2.as_str()
    }

    pub fn minimum_string(a: String, b: String, c: String) -> String {
        let s = [&a, &b, &c];
        let perm = [
            [0, 1, 2],
            [0, 2, 1],
            [1, 0, 2],
            [1, 2, 0],
            [2, 0, 1],
            [2, 1, 0],
        ];
        let mut ans = String::new();
        for [i, j, k] in perm.iter() {
            let r = Self::f(Self::f(s[*i].clone(), s[*j].clone()), s[*k].clone());
            if ans == "" || r.len() < ans.len() || (r.len() == ans.len() && r < ans) {
                ans = r;
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

给你三个字符串&nbsp;<code>a</code>&nbsp;，<code>b</code>&nbsp;和&nbsp;<code>c</code>&nbsp;， 你的任务是找到长度&nbsp;<strong>最短</strong>&nbsp;的字符串，且这三个字符串都是它的 <strong>子字符串</strong>&nbsp;。

<p>如果有多个这样的字符串，请你返回 <strong>字典序最小</strong>&nbsp;的一个。</p>

<p>请你返回满足题目要求的字符串。</p>

<p><strong>注意：</strong></p>

<ul>
	<li>两个长度相同的字符串 <code>a</code>&nbsp;和 <code>b</code>&nbsp;，如果在第一个不相同的字符处，<code>a</code>&nbsp;的字母在字母表中比 <code>b</code>&nbsp;的字母 <strong>靠前</strong>&nbsp;，那么字符串&nbsp;<code>a</code>&nbsp;比字符串&nbsp;<code>b</code> <strong>字典序小</strong>&nbsp;。</li>
	<li><strong>子字符串</strong>&nbsp;是一个字符串中一段连续的字符序列。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><code><span style=""><b>输入：</b></span>a</code> = "abc", <code>b</code> = "bca", <code>c</code> = "aaa"
<b>输出：</b>"aaabca"
<b>解释：</b>字符串 "aaabca" 包含所有三个字符串：a = ans[2...4] ，b = ans[3..5] ，c = ans[0..2] 。结果字符串的长度至少为 6 ，且"aaabca" 是字典序最小的一个。</pre>

<p><strong>示例 2：</strong></p>

<pre><code><span style=""><b>输入：</b></span>a</code> = "ab", <code>b</code> = "ba", <code>c</code> = "aba"
<b>输出：</b>"aba"
<strong>解释：</strong>字符串 "aba" 包含所有三个字符串：a = ans[0..1] ，b = ans[1..2] ，c = ans[0..2] 。由于 c 的长度为 3 ，结果字符串的长度至少为 3 。"aba" 是字典序最小的一个。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= a.length, b.length, c.length &lt;= 100</code></li>
	<li><code>a</code>&nbsp;，<code>b</code>&nbsp;，<code>c</code>&nbsp;只包含小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举

我们枚举三个字符串的所有排列，然后对于每个排列，对三个字符串进行合并，找到最短的且字典序最小的字符串。

时间复杂度 $O(n^2)$，空间复杂度 $O(n)$。其中 $n$ 是三个字符串的长度的最大值。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumString(self, a: str, b: str, c: str) -> str:
        def f(s: str, t: str) -> str:
            if s in t:
                return t
            if t in s:
                return s
            m, n = len(s), len(t)
            for i in range(min(m, n), 0, -1):
                if s[-i:] == t[:i]:
                    return s + t[i:]
            return s + t

        ans = ""
        for a, b, c in permutations((a, b, c)):
            s = f(f(a, b), c)
            if ans == "" or len(s) < len(ans) or (len(s) == len(ans) and s < ans):
                ans = s
        return ans
```

#### Java

```java
class Solution {
    public String minimumString(String a, String b, String c) {
        String[] s = {a, b, c};
        int[][] perm = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 1, 0}, {2, 0, 1}};
        String ans = "";
        for (var p : perm) {
            int i = p[0], j = p[1], k = p[2];
            String t = f(f(s[i], s[j]), s[k]);
            if ("".equals(ans) || t.length() < ans.length()
                || (t.length() == ans.length() && t.compareTo(ans) < 0)) {
                ans = t;
            }
        }
        return ans;
    }

    private String f(String s, String t) {
        if (s.contains(t)) {
            return s;
        }
        if (t.contains(s)) {
            return t;
        }
        int m = s.length(), n = t.length();
        for (int i = Math.min(m, n); i > 0; --i) {
            if (s.substring(m - i).equals(t.substring(0, i))) {
                return s + t.substring(i);
            }
        }
        return s + t;
    }
}
```

#### C++

```cpp
class Solution {
public:
    string minimumString(string a, string b, string c) {
        vector<string> s = {a, b, c};
        vector<vector<int>> perm = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 1, 0}, {2, 0, 1}};
        string ans = "";
        for (auto& p : perm) {
            int i = p[0], j = p[1], k = p[2];
            string t = f(f(s[i], s[j]), s[k]);
            if (ans == "" || t.size() < ans.size() || (t.size() == ans.size() && t < ans)) {
                ans = t;
            }
        }
        return ans;
    }

    string f(string s, string t) {
        if (s.find(t) != string::npos) {
            return s;
        }
        if (t.find(s) != string::npos) {
            return t;
        }
        int m = s.size(), n = t.size();
        for (int i = min(m, n); i; --i) {
            if (s.substr(m - i) == t.substr(0, i)) {
                return s + t.substr(i);
            }
        }
        return s + t;
    };
};
```

#### Go

```go
func minimumString(a string, b string, c string) string {
	f := func(s, t string) string {
		if strings.Contains(s, t) {
			return s
		}
		if strings.Contains(t, s) {
			return t
		}
		m, n := len(s), len(t)
		for i := min(m, n); i > 0; i-- {
			if s[m-i:] == t[:i] {
				return s + t[i:]
			}
		}
		return s + t
	}
	s := [3]string{a, b, c}
	ans := ""
	for _, p := range [][]int{{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0}} {
		i, j, k := p[0], p[1], p[2]
		t := f(f(s[i], s[j]), s[k])
		if ans == "" || len(t) < len(ans) || (len(t) == len(ans) && t < ans) {
			ans = t
		}
	}
	return ans
}
```

#### TypeScript

```ts
function minimumString(a: string, b: string, c: string): string {
    const f = (s: string, t: string): string => {
        if (s.includes(t)) {
            return s;
        }
        if (t.includes(s)) {
            return t;
        }
        const m = s.length;
        const n = t.length;
        for (let i = Math.min(m, n); i > 0; --i) {
            if (s.slice(-i) === t.slice(0, i)) {
                return s + t.slice(i);
            }
        }
        return s + t;
    };
    const s: string[] = [a, b, c];
    const perm: number[][] = [
        [0, 1, 2],
        [0, 2, 1],
        [1, 0, 2],
        [1, 2, 0],
        [2, 0, 1],
        [2, 1, 0],
    ];
    let ans = '';
    for (const [i, j, k] of perm) {
        const t = f(f(s[i], s[j]), s[k]);
        if (ans === '' || t.length < ans.length || (t.length === ans.length && t < ans)) {
            ans = t;
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    fn f(s1: String, s2: String) -> String {
        if s1.contains(&s2) {
            return s1;
        }
        if s2.contains(&s1) {
            return s2;
        }
        for i in 0..s1.len() {
            let s = &s1[i..];
            if s2.starts_with(s) {
                let n = s.len();
                return s1 + &s2[n..];
            }
        }
        s1 + s2.as_str()
    }

    pub fn minimum_string(a: String, b: String, c: String) -> String {
        let s = [&a, &b, &c];
        let perm = [
            [0, 1, 2],
            [0, 2, 1],
            [1, 0, 2],
            [1, 2, 0],
            [2, 0, 1],
            [2, 1, 0],
        ];
        let mut ans = String::new();
        for [i, j, k] in perm.iter() {
            let r = Self::f(Self::f(s[*i].clone(), s[*j].clone()), s[*k].clone());
            if ans == "" || r.len() < ans.len() || (r.len() == ans.len() && r < ans) {
                ans = r;
            }
        }
        ans
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：枚举 + KMP

我们可以使用 KMP 算法来优化字符串的合并过程。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是三个字符串的长度之和。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumString(self, a: str, b: str, c: str) -> str:
        def f(s: str, t: str) -> str:
            if s in t:
                return t
            if t in s:
                return s
            p = t + "#" + s + "$"
            n = len(p)
            next = [0] * n
            next[0] = -1
            i, j = 2, 0
            while i < n:
                if p[i - 1] == p[j]:
                    j += 1
                    next[i] = j
                    i += 1
                elif j:
                    j = next[j]
                else:
                    next[i] = 0
                    i += 1
            return s + t[next[-1] :]

        ans = ""
        for a, b, c in permutations((a, b, c)):
            s = f(f(a, b), c)
            if ans == "" or len(s) < len(ans) or (len(s) == len(ans) and s < ans):
                ans = s
        return ans
```

#### Java

```java
class Solution {
    public String minimumString(String a, String b, String c) {
        String[] s = {a, b, c};
        int[][] perm = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 1, 0}, {2, 0, 1}};
        String ans = "";
        for (var p : perm) {
            int i = p[0], j = p[1], k = p[2];
            String t = f(f(s[i], s[j]), s[k]);
            if ("".equals(ans) || t.length() < ans.length()
                || (t.length() == ans.length() && t.compareTo(ans) < 0)) {
                ans = t;
            }
        }
        return ans;
    }

    private String f(String s, String t) {
        if (s.contains(t)) {
            return s;
        }
        if (t.contains(s)) {
            return t;
        }
        char[] p = (t + "#" + s + "$").toCharArray();
        int n = p.length;
        int[] next = new int[n];
        next[0] = -1;
        for (int i = 2, j = 0; i < n;) {
            if (p[i - 1] == p[j]) {
                next[i++] = ++j;
            } else if (j > 0) {
                j = next[j];
            } else {
                next[i++] = 0;
            }
        }
        return s + t.substring(next[n - 1]);
    }
}
```

#### C++

```cpp
class Solution {
public:
    string minimumString(string a, string b, string c) {
        vector<string> s = {a, b, c};
        vector<vector<int>> perm = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 1, 0}, {2, 0, 1}};
        string ans = "";
        for (auto& p : perm) {
            int i = p[0], j = p[1], k = p[2];
            string t = f(f(s[i], s[j]), s[k]);
            if (ans == "" || t.size() < ans.size() || (t.size() == ans.size() && t < ans)) {
                ans = t;
            }
        }
        return ans;
    }

    string f(string s, string t) {
        if (s.find(t) != string::npos) {
            return s;
        }
        if (t.find(s) != string::npos) {
            return t;
        }
        string p = t + "#" + s + "$";
        int n = p.size();
        int next[n];
        next[0] = -1;
        next[1] = 0;
        for (int i = 2, j = 0; i < n;) {
            if (p[i - 1] == p[j]) {
                next[i++] = ++j;
            } else if (j > 0) {
                j = next[j];
            } else {
                next[i++] = 0;
            }
        }
        return s + t.substr(next[n - 1]);
    };
};
```

#### Go

```go
func minimumString(a string, b string, c string) string {
	f := func(s, t string) string {
		if strings.Contains(s, t) {
			return s
		}
		if strings.Contains(t, s) {
			return t
		}
		p := t + "#" + s + "$"
		n := len(p)
		next := make([]int, n)
		next[0] = -1
		for i, j := 2, 0; i < n; {
			if p[i-1] == p[j] {
				j++
				next[i] = j
				i++
			} else if j > 0 {
				j = next[j]
			} else {
				next[i] = 0
				i++
			}
		}
		return s + t[next[n-1]:]
	}
	s := [3]string{a, b, c}
	ans := ""
	for _, p := range [][]int{{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0}} {
		i, j, k := p[0], p[1], p[2]
		t := f(f(s[i], s[j]), s[k])
		if ans == "" || len(t) < len(ans) || (len(t) == len(ans) && t < ans) {
			ans = t
		}
	}
	return ans
}
```

#### TypeScript

```ts
function minimumString(a: string, b: string, c: string): string {
    const f = (s: string, t: string): string => {
        if (s.includes(t)) {
            return s;
        }
        if (t.includes(s)) {
            return t;
        }
        const p = t + '#' + s + '$';
        const n = p.length;
        const next: number[] = Array(n).fill(0);
        next[0] = -1;
        for (let i = 2, j = 0; i < n; ) {
            if (p[i - 1] === p[j]) {
                next[i++] = ++j;
            } else if (j) {
                j = next[j];
            } else {
                next[i++] = 0;
            }
        }
        return s + t.slice(next[n - 1]);
    };
    const s: string[] = [a, b, c];
    const perm: number[][] = [
        [0, 1, 2],
        [0, 2, 1],
        [1, 0, 2],
        [1, 2, 0],
        [2, 0, 1],
        [2, 1, 0],
    ];
    let ans = '';
    for (const [i, j, k] of perm) {
        const t = f(f(s[i], s[j]), s[k]);
        if (ans === '' || t.length < ans.length || (t.length === ans.length && t < ans)) {
            ans = t;
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

# [2801. 统计范围内的步进数字数目](https://leetcode.cn/problems/count-stepping-numbers-in-range){#2801}

{{< tabs "2801" >}}

{{% tab "python" %}}
```python
class Solution:
    def countSteppingNumbers(self, low: str, high: str) -> int:
        @cache
        def dfs(pos: int, pre: int, lead: bool, limit: bool) -> int:
            if pos >= len(num):
                return int(not lead)
            up = int(num[pos]) if limit else 9
            ans = 0
            for i in range(up + 1):
                if i == 0 and lead:
                    ans += dfs(pos + 1, pre, True, limit and i == up)
                elif pre == -1 or abs(i - pre) == 1:
                    ans += dfs(pos + 1, i, False, limit and i == up)
            return ans % mod

        mod = 10**9 + 7
        num = high
        a = dfs(0, -1, True, True)
        dfs.cache_clear()
        num = str(int(low) - 1)
        b = dfs(0, -1, True, True)
        return (a - b) % mod
```
{{% /tab %}}
{{% tab "java" %}}
```java
import java.math.BigInteger;

class Solution {
    private final int mod = (int) 1e9 + 7;
    private String num;
    private Integer[][] f;

    public int countSteppingNumbers(String low, String high) {
        f = new Integer[high.length() + 1][10];
        num = high;
        int a = dfs(0, -1, true, true);
        f = new Integer[high.length() + 1][10];
        num = new BigInteger(low).subtract(BigInteger.ONE).toString();
        int b = dfs(0, -1, true, true);
        return (a - b + mod) % mod;
    }

    private int dfs(int pos, int pre, boolean lead, boolean limit) {
        if (pos >= num.length()) {
            return lead ? 0 : 1;
        }
        if (!lead && !limit && f[pos][pre] != null) {
            return f[pos][pre];
        }
        int ans = 0;
        int up = limit ? num.charAt(pos) - '0' : 9;
        for (int i = 0; i <= up; ++i) {
            if (i == 0 && lead) {
                ans += dfs(pos + 1, pre, true, limit && i == up);
            } else if (pre == -1 || Math.abs(pre - i) == 1) {
                ans += dfs(pos + 1, i, false, limit && i == up);
            }
            ans %= mod;
        }
        if (!lead && !limit) {
            f[pos][pre] = ans;
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
    int countSteppingNumbers(string low, string high) {
        const int mod = 1e9 + 7;
        int m = high.size();
        int f[m + 1][10];
        memset(f, -1, sizeof(f));
        string num = high;

        function<int(int, int, bool, bool)> dfs = [&](int pos, int pre, bool lead, bool limit) {
            if (pos >= num.size()) {
                return lead ? 0 : 1;
            }
            if (!lead && !limit && f[pos][pre] != -1) {
                return f[pos][pre];
            }
            int up = limit ? num[pos] - '0' : 9;
            int ans = 0;
            for (int i = 0; i <= up; ++i) {
                if (i == 0 && lead) {
                    ans += dfs(pos + 1, pre, true, limit && i == up);
                } else if (pre == -1 || abs(pre - i) == 1) {
                    ans += dfs(pos + 1, i, false, limit && i == up);
                }
                ans %= mod;
            }
            if (!lead && !limit) {
                f[pos][pre] = ans;
            }
            return ans;
        };

        int a = dfs(0, -1, true, true);
        memset(f, -1, sizeof(f));
        for (int i = low.size() - 1; i >= 0; --i) {
            if (low[i] == '0') {
                low[i] = '9';
            } else {
                low[i] -= 1;
                break;
            }
        }
        num = low;
        int b = dfs(0, -1, true, true);
        return (a - b + mod) % mod;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countSteppingNumbers(low string, high string) int {
	const mod = 1e9 + 7
	f := [110][10]int{}
	for i := range f {
		for j := range f[i] {
			f[i][j] = -1
		}
	}
	num := high
	var dfs func(int, int, bool, bool) int
	dfs = func(pos, pre int, lead bool, limit bool) int {
		if pos >= len(num) {
			if lead {
				return 0
			}
			return 1
		}
		if !lead && !limit && f[pos][pre] != -1 {
			return f[pos][pre]
		}
		var ans int
		up := 9
		if limit {
			up = int(num[pos] - '0')
		}
		for i := 0; i <= up; i++ {
			if i == 0 && lead {
				ans += dfs(pos+1, pre, true, limit && i == up)
			} else if pre == -1 || abs(pre-i) == 1 {
				ans += dfs(pos+1, i, false, limit && i == up)
			}
			ans %= mod
		}
		if !lead && !limit {
			f[pos][pre] = ans
		}
		return ans
	}
	a := dfs(0, -1, true, true)
	t := []byte(low)
	for i := len(t) - 1; i >= 0; i-- {
		if t[i] != '0' {
			t[i]--
			break
		}
		t[i] = '9'
	}
	num = string(t)
	f = [110][10]int{}
	for i := range f {
		for j := range f[i] {
			f[i][j] = -1
		}
	}
	b := dfs(0, -1, true, true)
	return (a - b + mod) % mod
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countSteppingNumbers(low: string, high: string): number {
    const mod = 1e9 + 7;
    const m = high.length;
    let f: number[][] = Array(m + 1)
        .fill(0)
        .map(() => Array(10).fill(-1));
    let num = high;
    const dfs = (pos: number, pre: number, lead: boolean, limit: boolean): number => {
        if (pos >= num.length) {
            return lead ? 0 : 1;
        }
        if (!lead && !limit && f[pos][pre] !== -1) {
            return f[pos][pre];
        }
        let ans = 0;
        const up = limit ? +num[pos] : 9;
        for (let i = 0; i <= up; i++) {
            if (i == 0 && lead) {
                ans += dfs(pos + 1, pre, true, limit && i == up);
            } else if (pre == -1 || Math.abs(pre - i) == 1) {
                ans += dfs(pos + 1, i, false, limit && i == up);
            }
            ans %= mod;
        }
        if (!lead && !limit) {
            f[pos][pre] = ans;
        }
        return ans;
    };
    const a = dfs(0, -1, true, true);
    num = (BigInt(low) - 1n).toString();
    f = Array(m + 1)
        .fill(0)
        .map(() => Array(10).fill(-1));
    const b = dfs(0, -1, true, true);
    return (a - b + mod) % mod;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个正整数&nbsp;<code>low</code> 和&nbsp;<code>high</code>&nbsp;，都用字符串表示，请你统计闭区间 <code>[low, high]</code>&nbsp;内的 <strong>步进数字</strong>&nbsp;数目。</p>

<p>如果一个整数相邻数位之间差的绝对值都 <strong>恰好</strong>&nbsp;是 <code>1</code>&nbsp;，那么这个数字被称为 <strong>步进数字</strong>&nbsp;。</p>

<p>请你返回一个整数，表示闭区间&nbsp;<code>[low, high]</code>&nbsp;之间步进数字的数目。</p>

<p>由于答案可能很大，请你将它对&nbsp;<code>10<sup>9</sup> + 7</code>&nbsp;<strong>取余</strong>&nbsp;后返回。</p>

<p><b>注意：</b>步进数字不能有前导 0 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>low = "1", high = "11"
<b>输出：</b>10
<strong>解释：</strong>区间 [1,11] 内的步进数字为 1 ，2 ，3 ，4 ，5 ，6 ，7 ，8 ，9 和 10 。总共有 10 个步进数字。所以输出为 10 。</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>low = "90", high = "101"
<b>输出：</b>2
<strong>解释：</strong>区间 [90,101] 内的步进数字为 98 和 101 。总共有 2 个步进数字。所以输出为 2 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= int(low) &lt;= int(high) &lt; 10<sup>100</sup></code></li>
	<li><code>1 &lt;= low.length, high.length &lt;= 100</code></li>
	<li><code>low</code> 和&nbsp;<code>high</code>&nbsp;只包含数字。</li>
	<li><code>low</code> 和&nbsp;<code>high</code>&nbsp;都不含前导 0 。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数位 DP

我们注意到，题目求的是区间 $[low, high]$ 内的步进数的个数，对于这种区间 $[l,..r]$ 的问题，我们通常可以考虑转化为求 $[1, r]$ 和 $[1, l-1]$ 的答案，然后相减即可。另外，题目中只涉及到不同数位之间的关系，而不涉及具体的数值，因此我们可以考虑使用数位 DP 来解决。

我们设计一个函数 $dfs(pos, pre, lead, limit)$，表示当前处理到第 $pos$ 位，前一位数字是 $pre$，当前数字是否只包含前导零 $lead$，当前数字是否达到上界 $limit$ 的方案数。其中，而 $pos$ 的范围是 $[0, len(num))$。

函数 $dfs(pos, pre, lead, limit)$ 的执行逻辑如下：

如果 $pos$ 超出了 $num$ 的长度，说明我们已经处理完了所有数位，如果此时 $lead$ 为真，说明当前数字只包含前导零，不是一个合法的数字，我们可以返回 $0$ 表示方案数为 $0$；否则我们返回 $1$ 表示方案数为 $1$。

否则，我们计算得到当前数位的上界 $up$，然后在 $[0,..up]$ 范围内枚举当前数位的数字 $i$：

-   如果 $i=0$ 且 $lead$ 为真，说明当前数字只包含前导零，我们递归计算 $dfs(pos+1,pre, true, limit\ and\ i=up)$ 的值并累加到答案中；
-   否则，如果 $pre$ 为 $-1$，或者 $i$ 和 $pre$ 之间的差的绝对值为 $1$，说明当前数字是一个合法的步进数，我们递归计算 $dfs(pos+1,i, false, limit\ and\ i=up)$ 的值并累加到答案中。

最终我们返回答案。

在主函数中，我们分别计算 $[1, high]$ 和 $[1, low-1]$ 的答案 $a$ 和 $b$，最终答案为 $a-b$。注意答案的取模运算。

时间复杂度 $O(\log M \times |\Sigma|^2)$，空间复杂度 $O(\log M \times |\Sigma|)$，其中 $M$ 表示 $high$ 数字的大小，而 $|\Sigma|$ 表示数字集合。

相似题目：

-   [2719. 统计整数数目](https://github.com/doocs/leetcode/blob/main/solution/2700-2799/2719.Count%20of%20Integers/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countSteppingNumbers(self, low: str, high: str) -> int:
        @cache
        def dfs(pos: int, pre: int, lead: bool, limit: bool) -> int:
            if pos >= len(num):
                return int(not lead)
            up = int(num[pos]) if limit else 9
            ans = 0
            for i in range(up + 1):
                if i == 0 and lead:
                    ans += dfs(pos + 1, pre, True, limit and i == up)
                elif pre == -1 or abs(i - pre) == 1:
                    ans += dfs(pos + 1, i, False, limit and i == up)
            return ans % mod

        mod = 10**9 + 7
        num = high
        a = dfs(0, -1, True, True)
        dfs.cache_clear()
        num = str(int(low) - 1)
        b = dfs(0, -1, True, True)
        return (a - b) % mod
```

#### Java

```java
import java.math.BigInteger;

class Solution {
    private final int mod = (int) 1e9 + 7;
    private String num;
    private Integer[][] f;

    public int countSteppingNumbers(String low, String high) {
        f = new Integer[high.length() + 1][10];
        num = high;
        int a = dfs(0, -1, true, true);
        f = new Integer[high.length() + 1][10];
        num = new BigInteger(low).subtract(BigInteger.ONE).toString();
        int b = dfs(0, -1, true, true);
        return (a - b + mod) % mod;
    }

    private int dfs(int pos, int pre, boolean lead, boolean limit) {
        if (pos >= num.length()) {
            return lead ? 0 : 1;
        }
        if (!lead && !limit && f[pos][pre] != null) {
            return f[pos][pre];
        }
        int ans = 0;
        int up = limit ? num.charAt(pos) - '0' : 9;
        for (int i = 0; i <= up; ++i) {
            if (i == 0 && lead) {
                ans += dfs(pos + 1, pre, true, limit && i == up);
            } else if (pre == -1 || Math.abs(pre - i) == 1) {
                ans += dfs(pos + 1, i, false, limit && i == up);
            }
            ans %= mod;
        }
        if (!lead && !limit) {
            f[pos][pre] = ans;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int countSteppingNumbers(string low, string high) {
        const int mod = 1e9 + 7;
        int m = high.size();
        int f[m + 1][10];
        memset(f, -1, sizeof(f));
        string num = high;

        function<int(int, int, bool, bool)> dfs = [&](int pos, int pre, bool lead, bool limit) {
            if (pos >= num.size()) {
                return lead ? 0 : 1;
            }
            if (!lead && !limit && f[pos][pre] != -1) {
                return f[pos][pre];
            }
            int up = limit ? num[pos] - '0' : 9;
            int ans = 0;
            for (int i = 0; i <= up; ++i) {
                if (i == 0 && lead) {
                    ans += dfs(pos + 1, pre, true, limit && i == up);
                } else if (pre == -1 || abs(pre - i) == 1) {
                    ans += dfs(pos + 1, i, false, limit && i == up);
                }
                ans %= mod;
            }
            if (!lead && !limit) {
                f[pos][pre] = ans;
            }
            return ans;
        };

        int a = dfs(0, -1, true, true);
        memset(f, -1, sizeof(f));
        for (int i = low.size() - 1; i >= 0; --i) {
            if (low[i] == '0') {
                low[i] = '9';
            } else {
                low[i] -= 1;
                break;
            }
        }
        num = low;
        int b = dfs(0, -1, true, true);
        return (a - b + mod) % mod;
    }
};
```

#### Go

```go
func countSteppingNumbers(low string, high string) int {
	const mod = 1e9 + 7
	f := [110][10]int{}
	for i := range f {
		for j := range f[i] {
			f[i][j] = -1
		}
	}
	num := high
	var dfs func(int, int, bool, bool) int
	dfs = func(pos, pre int, lead bool, limit bool) int {
		if pos >= len(num) {
			if lead {
				return 0
			}
			return 1
		}
		if !lead && !limit && f[pos][pre] != -1 {
			return f[pos][pre]
		}
		var ans int
		up := 9
		if limit {
			up = int(num[pos] - '0')
		}
		for i := 0; i <= up; i++ {
			if i == 0 && lead {
				ans += dfs(pos+1, pre, true, limit && i == up)
			} else if pre == -1 || abs(pre-i) == 1 {
				ans += dfs(pos+1, i, false, limit && i == up)
			}
			ans %= mod
		}
		if !lead && !limit {
			f[pos][pre] = ans
		}
		return ans
	}
	a := dfs(0, -1, true, true)
	t := []byte(low)
	for i := len(t) - 1; i >= 0; i-- {
		if t[i] != '0' {
			t[i]--
			break
		}
		t[i] = '9'
	}
	num = string(t)
	f = [110][10]int{}
	for i := range f {
		for j := range f[i] {
			f[i][j] = -1
		}
	}
	b := dfs(0, -1, true, true)
	return (a - b + mod) % mod
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
```

#### TypeScript

```ts
function countSteppingNumbers(low: string, high: string): number {
    const mod = 1e9 + 7;
    const m = high.length;
    let f: number[][] = Array(m + 1)
        .fill(0)
        .map(() => Array(10).fill(-1));
    let num = high;
    const dfs = (pos: number, pre: number, lead: boolean, limit: boolean): number => {
        if (pos >= num.length) {
            return lead ? 0 : 1;
        }
        if (!lead && !limit && f[pos][pre] !== -1) {
            return f[pos][pre];
        }
        let ans = 0;
        const up = limit ? +num[pos] : 9;
        for (let i = 0; i <= up; i++) {
            if (i == 0 && lead) {
                ans += dfs(pos + 1, pre, true, limit && i == up);
            } else if (pre == -1 || Math.abs(pre - i) == 1) {
                ans += dfs(pos + 1, i, false, limit && i == up);
            }
            ans %= mod;
        }
        if (!lead && !limit) {
            f[pos][pre] = ans;
        }
        return ans;
    };
    const a = dfs(0, -1, true, true);
    num = (BigInt(low) - 1n).toString();
    f = Array(m + 1)
        .fill(0)
        .map(() => Array(10).fill(-1));
    const b = dfs(0, -1, true, true);
    return (a - b + mod) % mod;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2802. 找出第 K 个幸运数字 🔒](https://leetcode.cn/problems/find-the-k-th-lucky-number){#2802}

{{< tabs "2802" >}}

{{% tab "python" %}}
```python
class Solution:
    def kthLuckyNumber(self, k: int) -> str:
        n = 1
        while k > 1 << n:
            k -= 1 << n
            n += 1
        ans = []
        while n:
            n -= 1
            if k <= 1 << n:
                ans.append("4")
            else:
                ans.append("7")
                k -= 1 << n
        return "".join(ans)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String kthLuckyNumber(int k) {
        int n = 1;
        while (k > 1 << n) {
            k -= 1 << n;
            ++n;
        }
        StringBuilder ans = new StringBuilder();
        while (n-- > 0) {
            if (k <= 1 << n) {
                ans.append('4');
            } else {
                ans.append('7');
                k -= 1 << n;
            }
        }
        return ans.toString();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string kthLuckyNumber(int k) {
        int n = 1;
        while (k > 1 << n) {
            k -= 1 << n;
            ++n;
        }
        string ans;
        while (n--) {
            if (k <= 1 << n) {
                ans.push_back('4');
            } else {
                ans.push_back('7');
                k -= 1 << n;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func kthLuckyNumber(k int) string {
	n := 1
	for k > 1<<n {
		k -= 1 << n
		n++
	}
	ans := []byte{}
	for n > 0 {
		n--
		if k <= 1<<n {
			ans = append(ans, '4')
		} else {
			ans = append(ans, '7')
			k -= 1 << n
		}
	}
	return string(ans)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function kthLuckyNumber(k: number): string {
    let n = 1;
    while (k > 1 << n) {
        k -= 1 << n;
        ++n;
    }
    const ans: string[] = [];
    while (n-- > 0) {
        if (k <= 1 << n) {
            ans.push('4');
        } else {
            ans.push('7');
            k -= 1 << n;
        }
    }
    return ans.join('');
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>我们知道 <code>4</code> 和 <code>7</code> 是 <strong>幸运</strong> 数字。同时，如果一个数字只包含幸运数字，那么它被称为幸运数字。</p>

<p>给定一个整数 <code>k</code>，返回第 <code>k</code> 个幸运数字，并将其表示为一个 <strong>字符串</strong> 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>k = 4
<b>输出：</b>"47"
<b>解释：</b>第一个幸运数字是 4，第二个是 7，第三个是 44，第四个是 47。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>k = 10
<b>输出：</b>"477"
<b>解释：</b>按递增顺序列出的幸运数字为：
4, 7, 44, 47, 74, 77, 444, 447, 474, 477。 因此第10个幸运数字是477。</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>k = 1000
<b>输出：</b>"777747447"
<b>解释：</b>第 1000 个幸运数字是 777747447。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数学

根据题目描述，一个幸运数只包含数字 $4$ 和 $7$，因此 $n$ 位幸运数的个数为 $2^n$。

我们初始化 $n=1$，接下来循环判断 $k$ 是否大于 $2^n$，如果大于则将 $k$ 减去 $2^n$，同时 $n$ 加一，直到 $k$ 小于等于 $2^n$。此时，我们只需要找出 $n$ 位幸运数中的第 $k$ 个即可。

如果 $k$ 小于等于 $2^{n-1}$，则第 $k$ 个幸运数的第一位为 $4$，否则第一位为 $7$，然后我们将 $k$ 减去 $2^{n-1}$，继续判断第二位，直到 $n$ 位幸运数的所有位都判断完毕。

时间复杂度 $O(\log k)$，空间复杂度 $O(\log k)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def kthLuckyNumber(self, k: int) -> str:
        n = 1
        while k > 1 << n:
            k -= 1 << n
            n += 1
        ans = []
        while n:
            n -= 1
            if k <= 1 << n:
                ans.append("4")
            else:
                ans.append("7")
                k -= 1 << n
        return "".join(ans)
```

#### Java

```java
class Solution {
    public String kthLuckyNumber(int k) {
        int n = 1;
        while (k > 1 << n) {
            k -= 1 << n;
            ++n;
        }
        StringBuilder ans = new StringBuilder();
        while (n-- > 0) {
            if (k <= 1 << n) {
                ans.append('4');
            } else {
                ans.append('7');
                k -= 1 << n;
            }
        }
        return ans.toString();
    }
}
```

#### C++

```cpp
class Solution {
public:
    string kthLuckyNumber(int k) {
        int n = 1;
        while (k > 1 << n) {
            k -= 1 << n;
            ++n;
        }
        string ans;
        while (n--) {
            if (k <= 1 << n) {
                ans.push_back('4');
            } else {
                ans.push_back('7');
                k -= 1 << n;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func kthLuckyNumber(k int) string {
	n := 1
	for k > 1<<n {
		k -= 1 << n
		n++
	}
	ans := []byte{}
	for n > 0 {
		n--
		if k <= 1<<n {
			ans = append(ans, '4')
		} else {
			ans = append(ans, '7')
			k -= 1 << n
		}
	}
	return string(ans)
}
```

#### TypeScript

```ts
function kthLuckyNumber(k: number): string {
    let n = 1;
    while (k > 1 << n) {
        k -= 1 << n;
        ++n;
    }
    const ans: string[] = [];
    while (n-- > 0) {
        if (k <= 1 << n) {
            ans.push('4');
        } else {
            ans.push('7');
            k -= 1 << n;
        }
    }
    return ans.join('');
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2803. 阶乘生成器 🔒](https://leetcode.cn/problems/factorial-generator){#2803}

{{< tabs "2803" >}}

{{% tab "ts" %}}
```ts
function* factorial(n: number): Generator<number> {
    if (n === 0) {
        yield 1;
    }
    let ans = 1;
    for (let i = 1; i <= n; ++i) {
        ans *= i;
        yield ans;
    }
}

/**
 * const gen = factorial(2);
 * gen.next().value; // 1
 * gen.next().value; // 2
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>编写一个生成器函数，该函数以一个整数 <code>n</code> 作为参数，并返回一个生成器对象，该生成器对象可以生成 <strong>阶乘序列</strong> 。</p>

<p><strong>阶乘序列</strong> 的定义如下：<code>n! = n * (n-1) * (n-2) * ... * 2 * 1</code>&nbsp;。</p>

<p>0 的阶乘被定义为 1。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>n = 5
<b>输出：</b>[1,2,6,24,120]
<b>解释：</b>
const gen = factorial(5)
gen.next().value // 1
gen.next().value // 2
gen.next().value // 6
gen.next().value // 24
gen.next().value // 120
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>n = 2
<b>输出：</b>[1,2]
<b>解释：</b>
const gen = factorial(2) 
gen.next().value // 1 
gen.next().value // 2 
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>n = 0
<b>输出：</b>[1]
<b>解释：</b>
const gen = factorial(0) 
gen.next().value // 1 
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= n &lt;= 18</code></li>
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

#### TypeScript

```ts
function* factorial(n: number): Generator<number> {
    if (n === 0) {
        yield 1;
    }
    let ans = 1;
    for (let i = 1; i <= n; ++i) {
        ans *= i;
        yield ans;
    }
}

/**
 * const gen = factorial(2);
 * gen.next().value; // 1
 * gen.next().value; // 2
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2804. 数组原型的 forEach 方法 🔒](https://leetcode.cn/problems/array-prototype-foreach){#2804}

{{< tabs "2804" >}}

{{% tab "ts" %}}
```ts
Array.prototype.forEach = function (callback: Function, context: any): void {
    for (let i = 0; i < this.length; ++i) {
        callback.call(context, this[i], i, this);
    }
};

/**
 *  const arr = [1,2,3];
 *  const callback = (val, i, arr) => arr[i] = val * 2;
 *  const context = {"context":true};
 *
 *  arr.forEach(callback, context)
 *
 *  console.log(arr) // [2,4,6]
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>编写一个数组方法 <code>forEach</code>，使其可以在任何数组上调用 <code>array.forEach(callback, context)</code> 方法，它将在数组的每个元素上执行回调函数。<code>forEach</code> 方法不应该返回任何内容。</p>

<p>回调函数 <code>callback</code> 接受以下参数：</p>

<ul>
	<li><code>value</code> - 表示数组中当前正在处理的元素的值。</li>
	<li><code>index</code> - 表示数组中当前正在处理的元素的索引。</li>
	<li><code>array</code> - 表示数组本身，在回调函数内部可以访问整个数组。</li>
</ul>

<p>上下文 <code>context</code> 应该是作为函数上下文参数传递给回调函数 <code>callback</code> 的对象，确保回调函数 <code>callback</code> 内部的 <code>this</code> 关键字引用此上下文对象。</p>

<p>尝试在不使用内置数组方法的情况下实现这个方法。</p>

<p>&nbsp;</p>

<p><b>示例 1：</b></p>

<pre>
<strong>输入：</strong>
arr = [1,2,3], 
callback = (val, i, arr) =&gt; arr[i] = val * 2, 
context = {"context":true}
<strong>输出：</strong>[2,4,6]
<strong>解释：</strong>
arr.forEach(callback, context)&nbsp; 
console.log(arr) // [2,4,6]

回调函数在数组的每个元素上执行。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>
arr = [true, true, false, false], 
callback = (val, i, arr) =&gt; arr[i] = this, 
context = {"context": false}
<strong>输出：</strong>[{"context":false},{"context":false},{"context":false},{"context":false}]
<strong>解释：</strong>
arr.forEach(callback, context)&nbsp;
console.log(arr) // [{"context":false},{"context":false},{"context":false},{"context":false}]

回调函数在数组的每个元素上以正确的上下文执行。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>
arr = [true, true, false, false], 
callback = (val, i, arr) =&gt; arr[i] = !val, 
context = {"context": 5}
<strong>输出：</strong>[false,false,true,true]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>arr</code> 是一个有效的 JSON 数组</li>
	<li><code>context</code> 是一个有效的 JSON 对象</li>
	<li><code>fn</code>&nbsp;是一个函数</li>
	<li><code>0 &lt;= arr.length &lt;= 10<sup>5</sup></code></li>
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

#### TypeScript

```ts
Array.prototype.forEach = function (callback: Function, context: any): void {
    for (let i = 0; i < this.length; ++i) {
        callback.call(context, this[i], i, this);
    }
};

/**
 *  const arr = [1,2,3];
 *  const callback = (val, i, arr) => arr[i] = val * 2;
 *  const context = {"context":true};
 *
 *  arr.forEach(callback, context)
 *
 *  console.log(arr) // [2,4,6]
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2805. 自定义间隔 🔒](https://leetcode.cn/problems/custom-interval){#2805}

{{< tabs "2805" >}}

{{% tab "ts" %}}
```ts
const intervalMap = new Map<number, NodeJS.Timeout>();

function customInterval(fn: Function, delay: number, period: number): number {
    let count = 0;
    function recursiveTimeout() {
        intervalMap.set(
            id,
            setTimeout(
                () => {
                    fn();
                    count++;
                    recursiveTimeout();
                },
                delay + period * count,
            ),
        );
    }

    const id = Date.now();
    recursiveTimeout();
    return id;
}

function customClearInterval(id: number) {
    if (intervalMap.has(id)) {
        clearTimeout(intervalMap.get(id)!);
        intervalMap.delete(id);
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p><strong>函数</strong>&nbsp;<code>customInterval</code></p>

<p>给定一个函数 <code>fn</code>、一个数字 <code>delay</code> 和一个数字 <code>period</code>，返回一个数字 <code>id</code>。<code>customInterval</code> 是一个函数，它应该根据公式 <code>delay + period * count</code> 在间隔中执行提供的函数 <code>fn</code>，公式中的 <code>count</code> 表示从初始值 <code>0</code> 开始执行间隔的次数。</p>

<p><strong>函数</strong> <code>customClearInterval</code></p>

<p>给定 <code>id</code>。<code>id</code> 是从函数 <code>customInterval</code> 返回的值。<code>customClearInterval</code> 应该停止在间隔中执行提供的函数 <code>fn</code>。</p>

<p><strong>注意：</strong>在 Node.js 中，<code>setTimeout</code> 和 <code>setInterval</code> 函数返回一个对象，而不是一个数字。</p>

<p>&nbsp;</p>

<p><b>示例 1：</b></p>

<pre>
<strong>输入：</strong>delay = 50, period = 20, stopTime = 225
<strong>输出：</strong>[50,120,210]
<strong>解释：</strong>
const t = performance.now()&nbsp;&nbsp;
const result = []
&nbsp; &nbsp; &nbsp; &nbsp;&nbsp;
const fn = () =&gt; {
    result.push(Math.floor(performance.now() - t))
}
const id = customInterval(fn, delay, period)
        
setTimeout(() =&gt; {
    customClearInterval(id)
}, 225)

50 + 20 * 0 = 50 // 50ms - 第一个函数调用
50 + 20&nbsp;* 1 = 70 // 50ms + 70ms = 120ms - 第二个函数调用
50 + 20 * 2 = 90 // 50ms + 70ms + 90ms = 210ms - 第三个函数调用
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>delay = 20, period = 20, stopTime = 150
<strong>输出：</strong>[20,60,120]
<strong>解释：</strong>
20 + 20 * 0 = 20 // 20ms - 第一个函数调用
20 + 20&nbsp;* 1 = 40 // 20ms + 40ms = 60ms - 第二个函数调用
20 + 20 * 2 = 60 // 20ms + 40ms + 60ms = 120ms - 第三个函数调用
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>delay = 100, period = 200, stopTime = 500
<strong>输出：</strong>[100,400]
<strong>解释：</strong>
100 + 200 * 0 = 100 // 100ms - 第一个函数调用
100 + 200&nbsp;* 1 = 300 // 100ms + 300ms = 400ms - 第二个函数调用
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>20 &lt;= delay, period &lt;= 250</code></li>
	<li><code>20 &lt;= stopTime &lt;= 1000</code></li>
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

#### TypeScript

```ts
const intervalMap = new Map<number, NodeJS.Timeout>();

function customInterval(fn: Function, delay: number, period: number): number {
    let count = 0;
    function recursiveTimeout() {
        intervalMap.set(
            id,
            setTimeout(
                () => {
                    fn();
                    count++;
                    recursiveTimeout();
                },
                delay + period * count,
            ),
        );
    }

    const id = Date.now();
    recursiveTimeout();
    return id;
}

function customClearInterval(id: number) {
    if (intervalMap.has(id)) {
        clearTimeout(intervalMap.get(id)!);
        intervalMap.delete(id);
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2806. 取整购买后的账户余额](https://leetcode.cn/problems/account-balance-after-rounded-purchase){#2806}

{{< tabs "2806" >}}

{{% tab "python" %}}
```python
class Solution:
    def accountBalanceAfterPurchase(self, purchaseAmount: int) -> int:
        diff, x = 100, 0
        for y in range(100, -1, -10):
            if (t := abs(y - purchaseAmount)) < diff:
                diff = t
                x = y
        return 100 - x
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int accountBalanceAfterPurchase(int purchaseAmount) {
        int diff = 100, x = 0;
        for (int y = 100; y >= 0; y -= 10) {
            int t = Math.abs(y - purchaseAmount);
            if (t < diff) {
                diff = t;
                x = y;
            }
        }
        return 100 - x;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        int diff = 100, x = 0;
        for (int y = 100; y >= 0; y -= 10) {
            int t = abs(y - purchaseAmount);
            if (t < diff) {
                diff = t;
                x = y;
            }
        }
        return 100 - x;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func accountBalanceAfterPurchase(purchaseAmount int) int {
	diff, x := 100, 0
	for y := 100; y >= 0; y -= 10 {
		t := abs(y - purchaseAmount)
		if t < diff {
			diff = t
			x = y
		}
	}
	return 100 - x
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function accountBalanceAfterPurchase(purchaseAmount: number): number {
    let [diff, x] = [100, 0];
    for (let y = 100; y >= 0; y -= 10) {
        const t = Math.abs(y - purchaseAmount);
        if (t < diff) {
            diff = t;
            x = y;
        }
    }
    return 100 - x;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>一开始，你的银行账户里有&nbsp;<code>100</code>&nbsp;块钱。</p>

<p>给你一个整数<code>purchaseAmount</code>&nbsp;，它表示你在一次购买中愿意支出的金额。</p>

<p>在一个商店里，你进行一次购买，实际支出的金额会向 <strong>最近</strong>&nbsp;的&nbsp;<code>10</code>&nbsp;的 <strong>倍数</strong>&nbsp;取整。换句话说，你实际会支付一个&nbsp;<strong>非负</strong>&nbsp;金额&nbsp;<code>roundedAmount</code>&nbsp;，满足&nbsp;<code>roundedAmount</code>&nbsp;是&nbsp;<code>10</code>&nbsp;的倍数且&nbsp;<code>abs(roundedAmount - purchaseAmount)</code>&nbsp;的值 <strong>最小</strong>&nbsp;。</p>

<p>如果存在多于一个最接近的 <code>10</code>&nbsp;的倍数，<strong>较大的倍数</strong>&nbsp;是你的实际支出金额。</p>

<p>请你返回一个整数，表示你在愿意支出金额为<em>&nbsp;</em><code>purchaseAmount</code><em>&nbsp;</em>块钱的前提下，购买之后剩下的余额。</p>

<p><strong>注意：</strong> <code>0</code>&nbsp;也是&nbsp;<code>10</code>&nbsp;的倍数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>purchaseAmount = 9
<b>输出：</b>90
<b>解释：</b>这个例子中，最接近 9 的 10 的倍数是 10 。所以你的账户余额为 100 - 10 = 90 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>purchaseAmount = 15
<b>输出：</b>80
<b>解释：</b>这个例子中，有 2 个最接近 15 的 10 的倍数：10 和 20，较大的数 20 是你的实际开销。
所以你的账户余额为 100 - 20 = 80 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= purchaseAmount &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举 + 模拟

我们在 $[0, 100]$ 的范围内枚举所有的 $10$ 的倍数，然后找到与 `purchaseAmount` 最接近的那个数，记为 $x$，那么答案就是 $100 - x$。

时间复杂度 $O(1)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def accountBalanceAfterPurchase(self, purchaseAmount: int) -> int:
        diff, x = 100, 0
        for y in range(100, -1, -10):
            if (t := abs(y - purchaseAmount)) < diff:
                diff = t
                x = y
        return 100 - x
```

#### Java

```java
class Solution {
    public int accountBalanceAfterPurchase(int purchaseAmount) {
        int diff = 100, x = 0;
        for (int y = 100; y >= 0; y -= 10) {
            int t = Math.abs(y - purchaseAmount);
            if (t < diff) {
                diff = t;
                x = y;
            }
        }
        return 100 - x;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        int diff = 100, x = 0;
        for (int y = 100; y >= 0; y -= 10) {
            int t = abs(y - purchaseAmount);
            if (t < diff) {
                diff = t;
                x = y;
            }
        }
        return 100 - x;
    }
};
```

#### Go

```go
func accountBalanceAfterPurchase(purchaseAmount int) int {
	diff, x := 100, 0
	for y := 100; y >= 0; y -= 10 {
		t := abs(y - purchaseAmount)
		if t < diff {
			diff = t
			x = y
		}
	}
	return 100 - x
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
```

#### TypeScript

```ts
function accountBalanceAfterPurchase(purchaseAmount: number): number {
    let [diff, x] = [100, 0];
    for (let y = 100; y >= 0; y -= 10) {
        const t = Math.abs(y - purchaseAmount);
        if (t < diff) {
            diff = t;
            x = y;
        }
    }
    return 100 - x;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2807. 在链表中插入最大公约数](https://leetcode.cn/problems/insert-greatest-common-divisors-in-linked-list){#2807}

{{< tabs "2807" >}}

{{% tab "python" %}}
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def insertGreatestCommonDivisors(
        self, head: Optional[ListNode]
    ) -> Optional[ListNode]:
        pre, cur = head, head.next
        while cur:
            x = gcd(pre.val, cur.val)
            pre.next = ListNode(x, cur)
            pre, cur = cur, cur.next
        return head
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
    public ListNode insertGreatestCommonDivisors(ListNode head) {
        for (ListNode pre = head, cur = head.next; cur != null; cur = cur.next) {
            int x = gcd(pre.val, cur.val);
            pre.next = new ListNode(x, cur);
            pre = cur;
        }
        return head;
    }

    private int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* pre = head;
        for (ListNode* cur = head->next; cur; cur = cur->next) {
            int x = gcd(pre->val, cur->val);
            pre->next = new ListNode(x, cur);
            pre = cur;
        }
        return head;
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
func insertGreatestCommonDivisors(head *ListNode) *ListNode {
	for pre, cur := head, head.Next; cur != nil; cur = cur.Next {
		x := gcd(pre.Val, cur.Val)
		pre.Next = &ListNode{x, cur}
		pre = cur
	}
	return head
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
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

function insertGreatestCommonDivisors(head: ListNode | null): ListNode | null {
    for (let pre = head, cur = head.next; cur; cur = cur.next) {
        const x = gcd(pre.val, cur.val);
        pre.next = new ListNode(x, cur);
        pre = cur;
    }
    return head;
}

function gcd(a: number, b: number): number {
    if (b === 0) {
        return a;
    }
    return gcd(b, a % b);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个链表的头&nbsp;<code>head</code>&nbsp;，每个结点包含一个整数值。</p>

<p>在相邻结点之间，请你插入一个新的结点，结点值为这两个相邻结点值的 <strong>最大公约数</strong>&nbsp;。</p>

<p>请你返回插入之后的链表。</p>

<p>两个数的 <strong>最大公约数</strong>&nbsp;是可以被两个数字整除的最大正整数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2800-2899/2807.Insert%20Greatest%20Common%20Divisors%20in%20Linked%20List/images/ex1_copy.png" style="width: 641px; height: 181px;"></p>

<pre><b>输入：</b>head = [18,6,10,3]
<b>输出：</b>[18,6,6,2,10,1,3]
<b>解释：</b>第一幅图是一开始的链表，第二幅图是插入新结点后的图（蓝色结点为新插入结点）。
- 18 和 6 的最大公约数为 6 ，插入第一和第二个结点之间。
- 6 和 10 的最大公约数为 2 ，插入第二和第三个结点之间。
- 10 和 3 的最大公约数为 1 ，插入第三和第四个结点之间。
所有相邻结点之间都插入完毕，返回链表。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2800-2899/2807.Insert%20Greatest%20Common%20Divisors%20in%20Linked%20List/images/ex2_copy1.png" style="width: 51px; height: 191px;"></p>

<pre><b>输入：</b>head = [7]
<strong>输出：</strong>[7]
<b>解释：</b>第一幅图是一开始的链表，第二幅图是插入新结点后的图（蓝色结点为新插入结点）。
没有相邻结点，所以返回初始链表。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>链表中结点数目在&nbsp;<code>[1, 5000]</code> 之间。</li>
	<li><code>1 &lt;= Node.val &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们用两个指针 $pre$ 和 $cur$ 分别指向当前遍历到的结点和下一个结点，那么我们只需要在 $pre$ 和 $cur$ 之间插入一个新的结点即可。因此，每次计算出 $pre$ 和 $cur$ 的最大公约数 $x$，然后在 $pre$ 和 $cur$ 之间插入一个值为 $x$ 的新结点，然后更新 $pre = cur$，并且 $cur = cur.next$，继续遍历链表，直到 $cur$ 为空。

时间复杂度 $O(n \times \log M)$，其中 $n$ 是链表的长度，而 $M$ 是链表中结点的最大值。忽略结果链表的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def insertGreatestCommonDivisors(
        self, head: Optional[ListNode]
    ) -> Optional[ListNode]:
        pre, cur = head, head.next
        while cur:
            x = gcd(pre.val, cur.val)
            pre.next = ListNode(x, cur)
            pre, cur = cur, cur.next
        return head
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
    public ListNode insertGreatestCommonDivisors(ListNode head) {
        for (ListNode pre = head, cur = head.next; cur != null; cur = cur.next) {
            int x = gcd(pre.val, cur.val);
            pre.next = new ListNode(x, cur);
            pre = cur;
        }
        return head;
    }

    private int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* pre = head;
        for (ListNode* cur = head->next; cur; cur = cur->next) {
            int x = gcd(pre->val, cur->val);
            pre->next = new ListNode(x, cur);
            pre = cur;
        }
        return head;
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
func insertGreatestCommonDivisors(head *ListNode) *ListNode {
	for pre, cur := head, head.Next; cur != nil; cur = cur.Next {
		x := gcd(pre.Val, cur.Val)
		pre.Next = &ListNode{x, cur}
		pre = cur
	}
	return head
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
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

function insertGreatestCommonDivisors(head: ListNode | null): ListNode | null {
    for (let pre = head, cur = head.next; cur; cur = cur.next) {
        const x = gcd(pre.val, cur.val);
        pre.next = new ListNode(x, cur);
        pre = cur;
    }
    return head;
}

function gcd(a: number, b: number): number {
    if (b === 0) {
        return a;
    }
    return gcd(b, a % b);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2808. 使循环数组所有元素相等的最少秒数](https://leetcode.cn/problems/minimum-seconds-to-equalize-a-circular-array){#2808}

{{< tabs "2808" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumSeconds(self, nums: List[int]) -> int:
        d = defaultdict(list)
        for i, x in enumerate(nums):
            d[x].append(i)
        ans = inf
        n = len(nums)
        for idx in d.values():
            t = idx[0] + n - idx[-1]
            for i, j in pairwise(idx):
                t = max(t, j - i)
            ans = min(ans, t // 2)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumSeconds(List<Integer> nums) {
        Map<Integer, List<Integer>> d = new HashMap<>();
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            d.computeIfAbsent(nums.get(i), k -> new ArrayList<>()).add(i);
        }
        int ans = 1 << 30;
        for (List<Integer> idx : d.values()) {
            int m = idx.size();
            int t = idx.get(0) + n - idx.get(m - 1);
            for (int i = 1; i < m; ++i) {
                t = Math.max(t, idx.get(i) - idx.get(i - 1));
            }
            ans = Math.min(ans, t / 2);
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
    int minimumSeconds(vector<int>& nums) {
        unordered_map<int, vector<int>> d;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            d[nums[i]].push_back(i);
        }
        int ans = 1 << 30;
        for (auto& [_, idx] : d) {
            int m = idx.size();
            int t = idx[0] + n - idx[m - 1];
            for (int i = 1; i < m; ++i) {
                t = max(t, idx[i] - idx[i - 1]);
            }
            ans = min(ans, t / 2);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumSeconds(nums []int) int {
	d := map[int][]int{}
	for i, x := range nums {
		d[x] = append(d[x], i)
	}
	ans := 1 << 30
	n := len(nums)
	for _, idx := range d {
		m := len(idx)
		t := idx[0] + n - idx[m-1]
		for i := 1; i < m; i++ {
			t = max(t, idx[i]-idx[i-1])
		}
		ans = min(ans, t/2)
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumSeconds(nums: number[]): number {
    const d: Map<number, number[]> = new Map();
    const n = nums.length;
    for (let i = 0; i < n; ++i) {
        if (!d.has(nums[i])) {
            d.set(nums[i], []);
        }
        d.get(nums[i])!.push(i);
    }
    let ans = 1 << 30;
    for (const [_, idx] of d) {
        const m = idx.length;
        let t = idx[0] + n - idx[m - 1];
        for (let i = 1; i < m; ++i) {
            t = Math.max(t, idx[i] - idx[i - 1]);
        }
        ans = Math.min(ans, t >> 1);
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

<p>给你一个下标从 <strong>0</strong>&nbsp;开始长度为 <code>n</code>&nbsp;的数组&nbsp;<code>nums</code>&nbsp;。</p>

<p>每一秒，你可以对数组执行以下操作：</p>

<ul>
	<li>对于范围在&nbsp;<code>[0, n - 1]</code>&nbsp;内的每一个下标&nbsp;<code>i</code>&nbsp;，将&nbsp;<code>nums[i]</code> 替换成&nbsp;<code>nums[i]</code>&nbsp;，<code>nums[(i - 1 + n) % n]</code>&nbsp;或者&nbsp;<code>nums[(i + 1) % n]</code>&nbsp;三者之一。</li>
</ul>

<p><strong>注意</strong>，所有元素会被同时替换。</p>

<p>请你返回将数组 <code>nums</code>&nbsp;中所有元素变成相等元素所需要的 <strong>最少</strong>&nbsp;秒数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [1,2,1,2]
<b>输出：</b>1
<b>解释：</b>我们可以在 1 秒内将数组变成相等元素：
- 第 1 秒，将每个位置的元素分别变为 [nums[3],nums[1],nums[3],nums[3]] 。变化后，nums = [2,2,2,2] 。
1 秒是将数组变成相等元素所需要的最少秒数。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [2,1,3,3,2]
<b>输出：</b>2
<b>解释：</b>我们可以在 2 秒内将数组变成相等元素：
- 第 1 秒，将每个位置的元素分别变为 [nums[0],nums[2],nums[2],nums[2],nums[3]] 。变化后，nums = [2,3,3,3,3] 。
- 第 2 秒，将每个位置的元素分别变为 [nums[1],nums[1],nums[2],nums[3],nums[4]] 。变化后，nums = [3,3,3,3,3] 。
2 秒是将数组变成相等元素所需要的最少秒数。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>nums = [5,5,5,5]
<b>输出：</b>0
<b>解释：</b>不需要执行任何操作，因为一开始数组中的元素已经全部相等。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n == nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举

我们假设最终所有元素都变成了 $x$，那么 $x$ 一定是数组中的某个元素。

数字 $x$ 每一秒都可以向左右两边扩展一位，如果有多个相同的 $x$，那么扩展完整个数组所需要的时间，就取决于相邻两个 $x$ 之间的最大间距。

因此，我们枚举每个元素作为最终的 $x$，计算出每个 $x$ 中相邻两个元素之间的最大间距，记为 $t$，那么最终答案就是 $\min\limits_{x \in nums} \left\lfloor \frac{t}{2} \right\rfloor$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumSeconds(self, nums: List[int]) -> int:
        d = defaultdict(list)
        for i, x in enumerate(nums):
            d[x].append(i)
        ans = inf
        n = len(nums)
        for idx in d.values():
            t = idx[0] + n - idx[-1]
            for i, j in pairwise(idx):
                t = max(t, j - i)
            ans = min(ans, t // 2)
        return ans
```

#### Java

```java
class Solution {
    public int minimumSeconds(List<Integer> nums) {
        Map<Integer, List<Integer>> d = new HashMap<>();
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            d.computeIfAbsent(nums.get(i), k -> new ArrayList<>()).add(i);
        }
        int ans = 1 << 30;
        for (List<Integer> idx : d.values()) {
            int m = idx.size();
            int t = idx.get(0) + n - idx.get(m - 1);
            for (int i = 1; i < m; ++i) {
                t = Math.max(t, idx.get(i) - idx.get(i - 1));
            }
            ans = Math.min(ans, t / 2);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        unordered_map<int, vector<int>> d;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            d[nums[i]].push_back(i);
        }
        int ans = 1 << 30;
        for (auto& [_, idx] : d) {
            int m = idx.size();
            int t = idx[0] + n - idx[m - 1];
            for (int i = 1; i < m; ++i) {
                t = max(t, idx[i] - idx[i - 1]);
            }
            ans = min(ans, t / 2);
        }
        return ans;
    }
};
```

#### Go

```go
func minimumSeconds(nums []int) int {
	d := map[int][]int{}
	for i, x := range nums {
		d[x] = append(d[x], i)
	}
	ans := 1 << 30
	n := len(nums)
	for _, idx := range d {
		m := len(idx)
		t := idx[0] + n - idx[m-1]
		for i := 1; i < m; i++ {
			t = max(t, idx[i]-idx[i-1])
		}
		ans = min(ans, t/2)
	}
	return ans
}
```

#### TypeScript

```ts
function minimumSeconds(nums: number[]): number {
    const d: Map<number, number[]> = new Map();
    const n = nums.length;
    for (let i = 0; i < n; ++i) {
        if (!d.has(nums[i])) {
            d.set(nums[i], []);
        }
        d.get(nums[i])!.push(i);
    }
    let ans = 1 << 30;
    for (const [_, idx] of d) {
        const m = idx.length;
        let t = idx[0] + n - idx[m - 1];
        for (let i = 1; i < m; ++i) {
            t = Math.max(t, idx[i] - idx[i - 1]);
        }
        ans = Math.min(ans, t >> 1);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2809. 使数组和小于等于 x 的最少时间](https://leetcode.cn/problems/minimum-time-to-make-array-sum-at-most-x){#2809}

{{< tabs "2809" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumTime(self, nums1: List[int], nums2: List[int], x: int) -> int:
        n = len(nums1)
        f = [0] * (n + 1)
        for a, b in sorted(zip(nums1, nums2), key=lambda z: z[1]):
            for j in range(n, 0, -1):
                f[j] = max(f[j], f[j - 1] + a + b * j)
        s1 = sum(nums1)
        s2 = sum(nums2)
        for j in range(n + 1):
            if s1 + s2 * j - f[j] <= x:
                return j
        return -1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumTime(List<Integer> nums1, List<Integer> nums2, int x) {
        int n = nums1.size();
        int[] f = new int[n + 1];
        int[][] nums = new int[n][0];
        for (int i = 0; i < n; ++i) {
            nums[i] = new int[] {nums1.get(i), nums2.get(i)};
        }
        Arrays.sort(nums, Comparator.comparingInt(a -> a[1]));
        for (int[] e : nums) {
            int a = e[0], b = e[1];
            for (int j = n; j > 0; --j) {
                f[j] = Math.max(f[j], f[j - 1] + a + b * j);
            }
        }
        int s1 = 0, s2 = 0;
        for (int v : nums1) {
            s1 += v;
        }
        for (int v : nums2) {
            s2 += v;
        }

        for (int j = 0; j <= n; ++j) {
            if (s1 + s2 * j - f[j] <= x) {
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
    int minimumTime(vector<int>& nums1, vector<int>& nums2, int x) {
        int n = nums1.size();
        vector<pair<int, int>> nums;
        for (int i = 0; i < n; ++i) {
            nums.emplace_back(nums2[i], nums1[i]);
        }
        sort(nums.begin(), nums.end());
        int f[n + 1];
        memset(f, 0, sizeof(f));
        for (auto [b, a] : nums) {
            for (int j = n; j; --j) {
                f[j] = max(f[j], f[j - 1] + a + b * j);
            }
        }
        int s1 = accumulate(nums1.begin(), nums1.end(), 0);
        int s2 = accumulate(nums2.begin(), nums2.end(), 0);
        for (int j = 0; j <= n; ++j) {
            if (s1 + s2 * j - f[j] <= x) {
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
func minimumTime(nums1 []int, nums2 []int, x int) int {
	n := len(nums1)
	f := make([]int, n+1)
	type pair struct{ a, b int }
	nums := make([]pair, n)
	var s1, s2 int
	for i := range nums {
		s1 += nums1[i]
		s2 += nums2[i]
		nums[i] = pair{nums1[i], nums2[i]}
	}
	sort.Slice(nums, func(i, j int) bool { return nums[i].b < nums[j].b })
	for _, e := range nums {
		a, b := e.a, e.b
		for j := n; j > 0; j-- {
			f[j] = max(f[j], f[j-1]+a+b*j)
		}
	}
	for j := 0; j <= n; j++ {
		if s1+s2*j-f[j] <= x {
			return j
		}
	}
	return -1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumTime(nums1: number[], nums2: number[], x: number): number {
    const n = nums1.length;
    const f: number[] = new Array(n + 1).fill(0);
    const nums: number[][] = [];
    for (let i = 0; i < n; ++i) {
        nums.push([nums1[i], nums2[i]]);
    }
    nums.sort((a, b) => a[1] - b[1]);
    for (const [a, b] of nums) {
        for (let j = n; j > 0; --j) {
            f[j] = Math.max(f[j], f[j - 1] + a + b * j);
        }
    }
    const s1 = nums1.reduce((a, b) => a + b, 0);
    const s2 = nums2.reduce((a, b) => a + b, 0);
    for (let j = 0; j <= n; ++j) {
        if (s1 + s2 * j - f[j] <= x) {
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

<p>给你两个长度相等下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>nums1</code> 和&nbsp;<code>nums2</code>&nbsp;。每一秒，对于所有下标&nbsp;<code>0 &lt;= i &lt; nums1.length</code>&nbsp;，<code>nums1[i]</code>&nbsp;的值都增加&nbsp;<code>nums2[i]</code>&nbsp;。操作&nbsp;<strong>完成后</strong>&nbsp;，你可以进行如下操作：</p>

<ul>
	<li>选择任一满足&nbsp;<code>0 &lt;= i &lt; nums1.length</code>&nbsp;的下标 <code>i</code>&nbsp;，并使&nbsp;<code>nums1[i] = 0</code>&nbsp;。</li>
</ul>

<p>同时给你一个整数&nbsp;<code>x</code>&nbsp;。</p>

<p>请你返回使&nbsp;<code>nums1</code>&nbsp;中所有元素之和 <strong>小于等于</strong>&nbsp;<code>x</code>&nbsp;所需要的 <strong>最少</strong>&nbsp;时间，如果无法实现，那么返回 <code>-1</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>nums1 = [1,2,3], nums2 = [1,2,3], x = 4
<b>输出：</b>3
<b>解释：</b>
第 1 秒，我们对 i = 0 进行操作，得到 nums1 = [0,2+2,3+3] = [0,4,6] 。
第 2 秒，我们对 i = 1 进行操作，得到 nums1 = [0+1,0,6+3] = [1,0,9] 。
第 3 秒，我们对 i = 2 进行操作，得到 nums1 = [1+1,0+2,0] = [2,2,0] 。
现在 nums1 的和为 4 。不存在更少次数的操作，所以我们返回 3 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>nums1 = [1,2,3], nums2 = [3,3,3], x = 4
<b>输出：</b>-1
<b>解释：</b>不管如何操作，nums1 的和总是会超过 x 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums1.length &lt;= 10<sup>3</sup></code></li>
	<li><code>1 &lt;= nums1[i] &lt;= 10<sup>3</sup></code></li>
	<li><code>0 &lt;= nums2[i] &lt;= 10<sup>3</sup></code></li>
	<li><code>nums1.length == nums2.length</code></li>
	<li><code>0 &lt;= x &lt;= 10<sup>6</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 动态规划

我们注意到，如果我们多次操作同一个数，那么只有最后一次操作是有意义的，其余的对该数的操作，只会使得其它数字增大。因此，我们最多对每个数操作一次，也即是说，操作次数在 $[0,..n]$ 之间。

我们不妨假设进行了 $j$ 次操作，操作的数字下标分别为 $i_1, i_2, \cdots, i_j$，那么对于这 $j$ 次操作，每一次可以使得数组元素和减少的值为：

$$
\begin{aligned}
& d_1 = nums_1[i_1] + nums_2[i_1] \times 1 \\
& d_2 = nums_1[i_2] + nums_2[i_2] \times 2 \\
& \cdots \\
& d_j = nums_1[i_j] + nums_2[i_j] \times j
\end{aligned}
$$

从贪心的角度考虑，为了使得数组元素和的减少量最大，我们应当让 $nums_2$ 中的较大元素尽可能放在后面操作。因此，我们可以对 $nums_1$ 和 $nums_2$ 按照 $nums_2$ 的元素值从小到大进行排序。

接下来，我们考虑动态规划的实现。我们用 $f[i][j]$ 表示对于数组 $nums_1$ 的前 $i$ 个元素，进行 $j$ 次操作，所能减少的数组元素和的最大值。我们可以得到如下的状态转移方程：

$$
f[i][j] = \max \{f[i-1][j], f[i-1][j-1] + nums_1[i] + nums_2[i] \times j\}
$$

最后，我们枚举 $j$，找到最小的满足 $s_1 + s_2 \times j - f[n][j] \le x$ 的 $j$ 即可。

时间复杂度 $O(n^2)$，空间复杂度 $O(n^2)$。其中 $n$ 是数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumTime(self, nums1: List[int], nums2: List[int], x: int) -> int:
        n = len(nums1)
        f = [[0] * (n + 1) for _ in range(n + 1)]
        for i, (a, b) in enumerate(sorted(zip(nums1, nums2), key=lambda z: z[1]), 1):
            for j in range(n + 1):
                f[i][j] = f[i - 1][j]
                if j > 0:
                    f[i][j] = max(f[i][j], f[i - 1][j - 1] + a + b * j)
        s1 = sum(nums1)
        s2 = sum(nums2)
        for j in range(n + 1):
            if s1 + s2 * j - f[n][j] <= x:
                return j
        return -1
```

#### Java

```java
class Solution {
    public int minimumTime(List<Integer> nums1, List<Integer> nums2, int x) {
        int n = nums1.size();
        int[][] f = new int[n + 1][n + 1];
        int[][] nums = new int[n][0];
        for (int i = 0; i < n; ++i) {
            nums[i] = new int[] {nums1.get(i), nums2.get(i)};
        }
        Arrays.sort(nums, Comparator.comparingInt(a -> a[1]));
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= n; ++j) {
                f[i][j] = f[i - 1][j];
                if (j > 0) {
                    int a = nums[i - 1][0], b = nums[i - 1][1];
                    f[i][j] = Math.max(f[i][j], f[i - 1][j - 1] + a + b * j);
                }
            }
        }
        int s1 = 0, s2 = 0;
        for (int v : nums1) {
            s1 += v;
        }
        for (int v : nums2) {
            s2 += v;
        }

        for (int j = 0; j <= n; ++j) {
            if (s1 + s2 * j - f[n][j] <= x) {
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
    int minimumTime(vector<int>& nums1, vector<int>& nums2, int x) {
        int n = nums1.size();
        vector<pair<int, int>> nums;
        for (int i = 0; i < n; ++i) {
            nums.emplace_back(nums2[i], nums1[i]);
        }
        sort(nums.begin(), nums.end());
        int f[n + 1][n + 1];
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= n; ++j) {
                f[i][j] = f[i - 1][j];
                if (j) {
                    auto [b, a] = nums[i - 1];
                    f[i][j] = max(f[i][j], f[i - 1][j - 1] + a + b * j);
                }
            }
        }
        int s1 = accumulate(nums1.begin(), nums1.end(), 0);
        int s2 = accumulate(nums2.begin(), nums2.end(), 0);
        for (int j = 0; j <= n; ++j) {
            if (s1 + s2 * j - f[n][j] <= x) {
                return j;
            }
        }
        return -1;
    }
};
```

#### Go

```go
func minimumTime(nums1 []int, nums2 []int, x int) int {
	n := len(nums1)
	f := make([][]int, n+1)
	for i := range f {
		f[i] = make([]int, n+1)
	}
	type pair struct{ a, b int }
	nums := make([]pair, n)
	var s1, s2 int
	for i := range nums {
		s1 += nums1[i]
		s2 += nums2[i]
		nums[i] = pair{nums1[i], nums2[i]}
	}
	sort.Slice(nums, func(i, j int) bool { return nums[i].b < nums[j].b })
	for i := 1; i <= n; i++ {
		for j := 0; j <= n; j++ {
			f[i][j] = f[i-1][j]
			if j > 0 {
				a, b := nums[i-1].a, nums[i-1].b
				f[i][j] = max(f[i][j], f[i-1][j-1]+a+b*j)
			}
		}
	}
	for j := 0; j <= n; j++ {
		if s1+s2*j-f[n][j] <= x {
			return j
		}
	}
	return -1
}
```

#### TypeScript

```ts
function minimumTime(nums1: number[], nums2: number[], x: number): number {
    const n = nums1.length;
    const f: number[][] = Array(n + 1)
        .fill(0)
        .map(() => Array(n + 1).fill(0));
    const nums: number[][] = [];
    for (let i = 0; i < n; ++i) {
        nums.push([nums1[i], nums2[i]]);
    }
    nums.sort((a, b) => a[1] - b[1]);
    for (let i = 1; i <= n; ++i) {
        for (let j = 0; j <= n; ++j) {
            f[i][j] = f[i - 1][j];
            if (j > 0) {
                const [a, b] = nums[i - 1];
                f[i][j] = Math.max(f[i][j], f[i - 1][j - 1] + a + b * j);
            }
        }
    }
    const s1 = nums1.reduce((a, b) => a + b, 0);
    const s2 = nums2.reduce((a, b) => a + b, 0);
    for (let j = 0; j <= n; ++j) {
        if (s1 + s2 * j - f[n][j] <= x) {
            return j;
        }
    }
    return -1;
}
```

<!-- tabs:end -->

我们注意到，状态 $f[i][j]$ 只与 $f[i-1][j]$ 和 $f[i-1][j-1]$ 有关，因此我们可以优化掉第一维，将空间复杂度降低到 $O(n)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumTime(self, nums1: List[int], nums2: List[int], x: int) -> int:
        n = len(nums1)
        f = [0] * (n + 1)
        for a, b in sorted(zip(nums1, nums2), key=lambda z: z[1]):
            for j in range(n, 0, -1):
                f[j] = max(f[j], f[j - 1] + a + b * j)
        s1 = sum(nums1)
        s2 = sum(nums2)
        for j in range(n + 1):
            if s1 + s2 * j - f[j] <= x:
                return j
        return -1
```

#### Java

```java
class Solution {
    public int minimumTime(List<Integer> nums1, List<Integer> nums2, int x) {
        int n = nums1.size();
        int[] f = new int[n + 1];
        int[][] nums = new int[n][0];
        for (int i = 0; i < n; ++i) {
            nums[i] = new int[] {nums1.get(i), nums2.get(i)};
        }
        Arrays.sort(nums, Comparator.comparingInt(a -> a[1]));
        for (int[] e : nums) {
            int a = e[0], b = e[1];
            for (int j = n; j > 0; --j) {
                f[j] = Math.max(f[j], f[j - 1] + a + b * j);
            }
        }
        int s1 = 0, s2 = 0;
        for (int v : nums1) {
            s1 += v;
        }
        for (int v : nums2) {
            s2 += v;
        }

        for (int j = 0; j <= n; ++j) {
            if (s1 + s2 * j - f[j] <= x) {
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
    int minimumTime(vector<int>& nums1, vector<int>& nums2, int x) {
        int n = nums1.size();
        vector<pair<int, int>> nums;
        for (int i = 0; i < n; ++i) {
            nums.emplace_back(nums2[i], nums1[i]);
        }
        sort(nums.begin(), nums.end());
        int f[n + 1];
        memset(f, 0, sizeof(f));
        for (auto [b, a] : nums) {
            for (int j = n; j; --j) {
                f[j] = max(f[j], f[j - 1] + a + b * j);
            }
        }
        int s1 = accumulate(nums1.begin(), nums1.end(), 0);
        int s2 = accumulate(nums2.begin(), nums2.end(), 0);
        for (int j = 0; j <= n; ++j) {
            if (s1 + s2 * j - f[j] <= x) {
                return j;
            }
        }
        return -1;
    }
};
```

#### Go

```go
func minimumTime(nums1 []int, nums2 []int, x int) int {
	n := len(nums1)
	f := make([]int, n+1)
	type pair struct{ a, b int }
	nums := make([]pair, n)
	var s1, s2 int
	for i := range nums {
		s1 += nums1[i]
		s2 += nums2[i]
		nums[i] = pair{nums1[i], nums2[i]}
	}
	sort.Slice(nums, func(i, j int) bool { return nums[i].b < nums[j].b })
	for _, e := range nums {
		a, b := e.a, e.b
		for j := n; j > 0; j-- {
			f[j] = max(f[j], f[j-1]+a+b*j)
		}
	}
	for j := 0; j <= n; j++ {
		if s1+s2*j-f[j] <= x {
			return j
		}
	}
	return -1
}
```

#### TypeScript

```ts
function minimumTime(nums1: number[], nums2: number[], x: number): number {
    const n = nums1.length;
    const f: number[] = new Array(n + 1).fill(0);
    const nums: number[][] = [];
    for (let i = 0; i < n; ++i) {
        nums.push([nums1[i], nums2[i]]);
    }
    nums.sort((a, b) => a[1] - b[1]);
    for (const [a, b] of nums) {
        for (let j = n; j > 0; --j) {
            f[j] = Math.max(f[j], f[j - 1] + a + b * j);
        }
    }
    const s1 = nums1.reduce((a, b) => a + b, 0);
    const s2 = nums2.reduce((a, b) => a + b, 0);
    for (let j = 0; j <= n; ++j) {
        if (s1 + s2 * j - f[j] <= x) {
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
