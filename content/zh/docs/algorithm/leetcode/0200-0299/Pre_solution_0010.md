---
title: "0290_单词规律"
date: 2025-10-08T18:35:28+08:00
weight: 10
tags: [二叉树, 动态规划, 博弈, 双指针, 哈希表, 回溯, 堆（优先队列）, 字符串, 广度优先搜索, 排序, 数学, 数据流, 数组, 树, 深度优先搜索, 矩阵, 脑筋急转弯, 计数, 记忆化搜索, 设计]
---

{{< markmap >}}
### [0290_单词规律](#290)
#### [哈希表](#290)
#### [字符串](#290)
### [0291_单词规律 II 🔒](#291)
#### [哈希表](#291)
#### [字符串](#291)
#### [回溯](#291)
### [0292_Nim 游戏](#292)
#### [脑筋急转弯](#292)
#### [数学](#292)
#### [博弈](#292)
### [0293_翻转游戏 🔒](#293)
#### [字符串](#293)
### [0294_翻转游戏 II 🔒](#294)
#### [记忆化搜索](#294)
#### [数学](#294)
#### [动态规划](#294)
#### [回溯](#294)
#### [博弈](#294)
### [0295_数据流的中位数](#295)
#### [设计](#295)
#### [双指针](#295)
#### [数据流](#295)
#### [排序](#295)
#### [堆（优先队列）](#295)
### [0296_最佳的碰头地点 🔒](#296)
#### [数组](#296)
#### [数学](#296)
#### [矩阵](#296)
#### [排序](#296)
### [0297_二叉树的序列化与反序列化](#297)
#### [树](#297)
#### [深度优先搜索](#297)
#### [广度优先搜索](#297)
#### [设计](#297)
#### [字符串](#297)
#### [二叉树](#297)
### [0298_二叉树最长连续序列 🔒](#298)
#### [树](#298)
#### [深度优先搜索](#298)
#### [二叉树](#298)
### [0299_猜数字游戏](#299)
#### [哈希表](#299)
#### [字符串](#299)
#### [计数](#299)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0290_单词规律
___
#### 哈希表
___
#### 字符串
---
### 0291_单词规律 II 🔒
___
#### 哈希表
___
#### 字符串
___
#### 回溯
---
### 0292_Nim 游戏
___
#### 脑筋急转弯
___
#### 数学
___
#### 博弈
---
### 0293_翻转游戏 🔒
___
#### 字符串
---
### 0294_翻转游戏 II 🔒
___
#### 记忆化搜索
___
#### 数学
___
#### 动态规划
___
#### 回溯
___
#### 博弈
---
### 0295_数据流的中位数
___
#### 设计
___
#### 双指针
___
#### 数据流
___
#### 排序
___
#### 堆（优先队列）
---
### 0296_最佳的碰头地点 🔒
___
#### 数组
___
#### 数学
___
#### 矩阵
___
#### 排序
---
### 0297_二叉树的序列化与反序列化
___
#### 树
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 设计
___
#### 字符串
___
#### 二叉树
---
### 0298_二叉树最长连续序列 🔒
___
#### 树
___
#### 深度优先搜索
___
#### 二叉树
---
### 0299_猜数字游戏
___
#### 哈希表
___
#### 字符串
___
#### 计数
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二叉树 | 动态规划 | 博弈 |
| 双指针 | 哈希表 | 回溯 |
| 堆（优先队列） | 字符串 | 广度优先搜索 |
| 排序 | 数学 | 数据流 |
| 数组 | 树 | 深度优先搜索 |
| 矩阵 | 脑筋急转弯 | 计数 |
| 记忆化搜索 | 设计 |  |

# [290. 单词规律](https://leetcode.cn/problems/word-pattern){#290}

{{< tabs "290" >}}

{{% tab "python" %}}
```python
class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        ws = s.split()
        if len(pattern) != len(ws):
            return False
        d1 = {}
        d2 = {}
        for a, b in zip(pattern, ws):
            if (a in d1 and d1[a] != b) or (b in d2 and d2[b] != a):
                return False
            d1[a] = b
            d2[b] = a
        return True
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean wordPattern(String pattern, String s) {
        String[] ws = s.split(" ");
        if (pattern.length() != ws.length) {
            return false;
        }
        Map<Character, String> d1 = new HashMap<>();
        Map<String, Character> d2 = new HashMap<>();
        for (int i = 0; i < ws.length; ++i) {
            char a = pattern.charAt(i);
            String b = ws[i];
            if (!d1.getOrDefault(a, b).equals(b) || d2.getOrDefault(b, a) != a) {
                return false;
            }
            d1.put(a, b);
            d2.put(b, a);
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
    bool wordPattern(string pattern, string s) {
        istringstream is(s);
        vector<string> ws;
        while (is >> s) {
            ws.push_back(s);
        }
        if (pattern.size() != ws.size()) {
            return false;
        }
        unordered_map<char, string> d1;
        unordered_map<string, char> d2;
        for (int i = 0; i < ws.size(); ++i) {
            char a = pattern[i];
            string b = ws[i];
            if ((d1.count(a) && d1[a] != b) || (d2.count(b) && d2[b] != a)) {
                return false;
            }
            d1[a] = b;
            d2[b] = a;
        }
        return true;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func wordPattern(pattern string, s string) bool {
	ws := strings.Split(s, " ")
	if len(ws) != len(pattern) {
		return false
	}
	d1 := map[rune]string{}
	d2 := map[string]rune{}
	for i, a := range pattern {
		b := ws[i]
		if v, ok := d1[a]; ok && v != b {
			return false
		}
		if v, ok := d2[b]; ok && v != a {
			return false
		}
		d1[a] = b
		d2[b] = a
	}
	return true
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function wordPattern(pattern: string, s: string): boolean {
    const hash: Record<string, string> = Object.create(null);
    const arr = s.split(/\s+/);

    if (pattern.length !== arr.length || new Set(pattern).size !== new Set(arr).size) {
        return false;
    }

    for (let i = 0; i < pattern.length; i++) {
        hash[pattern[i]] ??= arr[i];
        if (hash[pattern[i]] !== arr[i]) {
            return false;
        }
    }

    return true;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashMap;

impl Solution {
    pub fn word_pattern(pattern: String, s: String) -> bool {
        let cs1: Vec<char> = pattern.chars().collect();
        let cs2: Vec<&str> = s.split_whitespace().collect();
        let n = cs1.len();
        if n != cs2.len() {
            return false;
        }
        let mut map1 = HashMap::new();
        let mut map2 = HashMap::new();
        for i in 0..n {
            let c = cs1[i];
            let s = cs2[i];
            if !map1.contains_key(&c) {
                map1.insert(c, i);
            }
            if !map2.contains_key(&s) {
                map2.insert(s, i);
            }
            if map1.get(&c) != map2.get(&s) {
                return false;
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
    public bool WordPattern(string pattern, string s) {
        var ws = s.Split(' ');
        if (pattern.Length != ws.Length) {
            return false;
        }
        var d1 = new Dictionary<char, string>();
        var d2 = new Dictionary<string, char>();
        for (int i = 0; i < ws.Length; ++i) {
            var a = pattern[i];
            var b = ws[i];
            if (d1.ContainsKey(a) && d1[a] != b) {
                return false;
            }
            if (d2.ContainsKey(b) && d2[b] != a) {
                return false;
            }
            d1[a] = b;
            d2[b] = a;
        }
        return true;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一种规律 <code>pattern</code>&nbsp;和一个字符串&nbsp;<code>s</code>&nbsp;，判断 <code>s</code>&nbsp;是否遵循相同的规律。</p>

<p>这里的&nbsp;<strong>遵循&nbsp;</strong>指完全匹配，例如，&nbsp;<code>pattern</code>&nbsp;里的每个字母和字符串&nbsp;<code>s</code><strong>&nbsp;</strong>中的每个非空单词之间存在着双向连接的对应规律。</p>

<p>&nbsp;</p>

<p><strong class="example">示例1:</strong></p>

<pre>
<strong>输入:</strong> pattern = <code>"abba"</code>, s = <code>"dog cat cat dog"</code>
<strong>输出:</strong> true</pre>

<p><strong class="example">示例 2:</strong></p>

<pre>
<strong>输入:</strong>pattern = <code>"abba"</code>, s = <code>"dog cat cat fish"</code>
<strong>输出:</strong> false</pre>

<p><strong class="example">示例 3:</strong></p>

<pre>
<strong>输入:</strong> pattern = <code>"aaaa"</code>, s = <code>"dog cat cat dog"</code>
<strong>输出:</strong> false</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= pattern.length &lt;= 300</code></li>
	<li><code>pattern</code>&nbsp;只包含小写英文字母</li>
	<li><code>1 &lt;= s.length &lt;= 3000</code></li>
	<li><code>s</code>&nbsp;只包含小写英文字母和&nbsp;<code>' '</code></li>
	<li><code>s</code>&nbsp;<strong>不包含</strong> 任何前导或尾随对空格</li>
	<li><code>s</code>&nbsp;中每个单词都被 <strong>单个空格 </strong>分隔</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

我们先将字符串 $s$ 按照空格分割成单词数组 $ws$，如果 $pattern$ 和 $ws$ 的长度不相等，直接返回 `false`。否则，我们使用两个哈希表 $d_1$ 和 $d_2$，分别记录 $pattern$ 和 $ws$ 中每个字符和单词的对应关系。

接下来，我们遍历 $pattern$ 和 $ws$，对于每个字符 $a$ 和单词 $b$，如果 $d_1$ 中存在 $a$ 的映射，且映射的单词不是 $b$，或者 $d_2$ 中存在 $b$ 的映射，且映射的字符不是 $a$，则返回 `false`。否则，我们将 $a$ 和 $b$ 的映射分别加入 $d_1$ 和 $d_2$ 中。

遍历结束后，返回 `true`。

时间复杂度 $O(m + n)$，空间复杂度 $O(m + n)$。其中 $m$ 和 $n$ 分别是 $pattern$ 和字符串 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        ws = s.split()
        if len(pattern) != len(ws):
            return False
        d1 = {}
        d2 = {}
        for a, b in zip(pattern, ws):
            if (a in d1 and d1[a] != b) or (b in d2 and d2[b] != a):
                return False
            d1[a] = b
            d2[b] = a
        return True
```

#### Java

```java
class Solution {
    public boolean wordPattern(String pattern, String s) {
        String[] ws = s.split(" ");
        if (pattern.length() != ws.length) {
            return false;
        }
        Map<Character, String> d1 = new HashMap<>();
        Map<String, Character> d2 = new HashMap<>();
        for (int i = 0; i < ws.length; ++i) {
            char a = pattern.charAt(i);
            String b = ws[i];
            if (!d1.getOrDefault(a, b).equals(b) || d2.getOrDefault(b, a) != a) {
                return false;
            }
            d1.put(a, b);
            d2.put(b, a);
        }
        return true;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        istringstream is(s);
        vector<string> ws;
        while (is >> s) {
            ws.push_back(s);
        }
        if (pattern.size() != ws.size()) {
            return false;
        }
        unordered_map<char, string> d1;
        unordered_map<string, char> d2;
        for (int i = 0; i < ws.size(); ++i) {
            char a = pattern[i];
            string b = ws[i];
            if ((d1.count(a) && d1[a] != b) || (d2.count(b) && d2[b] != a)) {
                return false;
            }
            d1[a] = b;
            d2[b] = a;
        }
        return true;
    }
};
```

#### Go

```go
func wordPattern(pattern string, s string) bool {
	ws := strings.Split(s, " ")
	if len(ws) != len(pattern) {
		return false
	}
	d1 := map[rune]string{}
	d2 := map[string]rune{}
	for i, a := range pattern {
		b := ws[i]
		if v, ok := d1[a]; ok && v != b {
			return false
		}
		if v, ok := d2[b]; ok && v != a {
			return false
		}
		d1[a] = b
		d2[b] = a
	}
	return true
}
```

#### TypeScript

```ts
function wordPattern(pattern: string, s: string): boolean {
    const ws = s.split(' ');
    if (pattern.length !== ws.length) {
        return false;
    }
    const d1 = new Map<string, string>();
    const d2 = new Map<string, string>();
    for (let i = 0; i < pattern.length; ++i) {
        const a = pattern[i];
        const b = ws[i];
        if (d1.has(a) && d1.get(a) !== b) {
            return false;
        }
        if (d2.has(b) && d2.get(b) !== a) {
            return false;
        }
        d1.set(a, b);
        d2.set(b, a);
    }
    return true;
}
```

#### Rust

```rust
use std::collections::HashMap;

impl Solution {
    pub fn word_pattern(pattern: String, s: String) -> bool {
        let cs1: Vec<char> = pattern.chars().collect();
        let cs2: Vec<&str> = s.split_whitespace().collect();
        let n = cs1.len();
        if n != cs2.len() {
            return false;
        }
        let mut map1 = HashMap::new();
        let mut map2 = HashMap::new();
        for i in 0..n {
            let c = cs1[i];
            let s = cs2[i];
            if !map1.contains_key(&c) {
                map1.insert(c, i);
            }
            if !map2.contains_key(&s) {
                map2.insert(s, i);
            }
            if map1.get(&c) != map2.get(&s) {
                return false;
            }
        }
        true
    }
}
```

#### C#

```cs
public class Solution {
    public bool WordPattern(string pattern, string s) {
        var ws = s.Split(' ');
        if (pattern.Length != ws.Length) {
            return false;
        }
        var d1 = new Dictionary<char, string>();
        var d2 = new Dictionary<string, char>();
        for (int i = 0; i < ws.Length; ++i) {
            var a = pattern[i];
            var b = ws[i];
            if (d1.ContainsKey(a) && d1[a] != b) {
                return false;
            }
            if (d2.ContainsKey(b) && d2[b] != a) {
                return false;
            }
            d1[a] = b;
            d2[b] = a;
        }
        return true;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：哈希表的另一种写法

<!-- tabs:start -->

#### TypeScript

```ts
function wordPattern(pattern: string, s: string): boolean {
    const hash: Record<string, string> = Object.create(null);
    const arr = s.split(/\s+/);

    if (pattern.length !== arr.length || new Set(pattern).size !== new Set(arr).size) {
        return false;
    }

    for (let i = 0; i < pattern.length; i++) {
        hash[pattern[i]] ??= arr[i];
        if (hash[pattern[i]] !== arr[i]) {
            return false;
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

# [291. 单词规律 II 🔒](https://leetcode.cn/problems/word-pattern-ii){#291}

{{< tabs "291" >}}

{{% tab "python" %}}
```python
class Solution:
    def wordPatternMatch(self, pattern: str, s: str) -> bool:
        def dfs(i, j):
            if i == m and j == n:
                return True
            if i == m or j == n or n - j < m - i:
                return False
            for k in range(j, n):
                t = s[j : k + 1]
                if d.get(pattern[i]) == t:
                    if dfs(i + 1, k + 1):
                        return True
                if pattern[i] not in d and t not in vis:
                    d[pattern[i]] = t
                    vis.add(t)
                    if dfs(i + 1, k + 1):
                        return True
                    d.pop(pattern[i])
                    vis.remove(t)
            return False

        m, n = len(pattern), len(s)
        d = {}
        vis = set()
        return dfs(0, 0)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private Set<String> vis;
    private Map<Character, String> d;
    private String p;
    private String s;
    private int m;
    private int n;

    public boolean wordPatternMatch(String pattern, String s) {
        vis = new HashSet<>();
        d = new HashMap<>();
        this.p = pattern;
        this.s = s;
        m = p.length();
        n = s.length();
        return dfs(0, 0);
    }

    private boolean dfs(int i, int j) {
        if (i == m && j == n) {
            return true;
        }
        if (i == m || j == n || m - i > n - j) {
            return false;
        }
        char c = p.charAt(i);
        for (int k = j + 1; k <= n; ++k) {
            String t = s.substring(j, k);
            if (d.getOrDefault(c, "").equals(t)) {
                if (dfs(i + 1, k)) {
                    return true;
                }
            }
            if (!d.containsKey(c) && !vis.contains(t)) {
                d.put(c, t);
                vis.add(t);
                if (dfs(i + 1, k)) {
                    return true;
                }
                vis.remove(t);
                d.remove(c);
            }
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
    bool wordPatternMatch(string pattern, string s) {
        unordered_set<string> vis;
        unordered_map<char, string> d;
        return dfs(0, 0, pattern, s, vis, d);
    }

    bool dfs(int i, int j, string& p, string& s, unordered_set<string>& vis, unordered_map<char, string>& d) {
        int m = p.size(), n = s.size();
        if (i == m && j == n) return true;
        if (i == m || j == n || m - i > n - j) return false;
        char c = p[i];
        for (int k = j + 1; k <= n; ++k) {
            string t = s.substr(j, k - j);
            if (d.count(c) && d[c] == t) {
                if (dfs(i + 1, k, p, s, vis, d)) return true;
            }
            if (!d.count(c) && !vis.count(t)) {
                d[c] = t;
                vis.insert(t);
                if (dfs(i + 1, k, p, s, vis, d)) return true;
                vis.erase(t);
                d.erase(c);
            }
        }
        return false;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func wordPatternMatch(pattern string, s string) bool {
	m, n := len(pattern), len(s)
	vis := map[string]bool{}
	d := map[byte]string{}
	var dfs func(i, j int) bool
	dfs = func(i, j int) bool {
		if i == m && j == n {
			return true
		}
		if i == m || j == n || m-i > n-j {
			return false
		}
		c := pattern[i]
		for k := j + 1; k <= n; k++ {
			t := s[j:k]
			if v, ok := d[c]; ok && v == t {
				if dfs(i+1, k) {
					return true
				}
			}
			if _, ok := d[c]; !ok && !vis[t] {
				d[c] = t
				vis[t] = true
				if dfs(i+1, k) {
					return true
				}
				delete(d, c)
				vis[t] = false
			}
		}
		return false
	}
	return dfs(0, 0)
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一种规律&nbsp;<code>pattern</code>&nbsp;和一个字符串&nbsp;<code>s</code>，请你判断&nbsp;<code>s</code>&nbsp;是否和<em>&nbsp;</em><code>pattern</code>&nbsp;的规律<strong>相匹配</strong>。</p>

<p>如果存在单个字符到 <strong>非空</strong> 字符串的 <strong>双射映射</strong> ，那么字符串<meta charset="UTF-8" />&nbsp;<code>s</code>&nbsp;匹配<meta charset="UTF-8" />&nbsp;<code>pattern</code>&nbsp;，即：如果&nbsp;<meta charset="UTF-8" /><code>pattern</code>&nbsp;中的每个字符都被它映射到的字符串替换，那么最终的字符串则为 <code>s</code> 。<strong>双射</strong> 意味着映射双方一一对应，不会存在两个字符映射到同一个字符串，也不会存在一个字符分别映射到两个不同的字符串。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>pattern = "abab", s = "redblueredblue"
<strong>输出：</strong>true
<strong>解释：</strong>一种可能的映射如下：
'a' -&gt; "red"
'b' -&gt; "blue"</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>pattern = "aaaa", s = "asdasdasdasd"
<strong>输出：</strong>true
<strong>解释：</strong>一种可能的映射如下：
'a' -&gt; "asd"
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>pattern = "aabb", s = "xyzabcxzyabc"
<strong>输出：</strong>false
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= pattern.length, s.length &lt;= 20</code></li>
	<li><code>pattern</code> 和 <code>s</code> 由小写英文字母组成</li>
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
    def wordPatternMatch(self, pattern: str, s: str) -> bool:
        def dfs(i, j):
            if i == m and j == n:
                return True
            if i == m or j == n or n - j < m - i:
                return False
            for k in range(j, n):
                t = s[j : k + 1]
                if d.get(pattern[i]) == t:
                    if dfs(i + 1, k + 1):
                        return True
                if pattern[i] not in d and t not in vis:
                    d[pattern[i]] = t
                    vis.add(t)
                    if dfs(i + 1, k + 1):
                        return True
                    d.pop(pattern[i])
                    vis.remove(t)
            return False

        m, n = len(pattern), len(s)
        d = {}
        vis = set()
        return dfs(0, 0)
```

#### Java

```java
class Solution {
    private Set<String> vis;
    private Map<Character, String> d;
    private String p;
    private String s;
    private int m;
    private int n;

    public boolean wordPatternMatch(String pattern, String s) {
        vis = new HashSet<>();
        d = new HashMap<>();
        this.p = pattern;
        this.s = s;
        m = p.length();
        n = s.length();
        return dfs(0, 0);
    }

    private boolean dfs(int i, int j) {
        if (i == m && j == n) {
            return true;
        }
        if (i == m || j == n || m - i > n - j) {
            return false;
        }
        char c = p.charAt(i);
        for (int k = j + 1; k <= n; ++k) {
            String t = s.substring(j, k);
            if (d.getOrDefault(c, "").equals(t)) {
                if (dfs(i + 1, k)) {
                    return true;
                }
            }
            if (!d.containsKey(c) && !vis.contains(t)) {
                d.put(c, t);
                vis.add(t);
                if (dfs(i + 1, k)) {
                    return true;
                }
                vis.remove(t);
                d.remove(c);
            }
        }
        return false;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool wordPatternMatch(string pattern, string s) {
        unordered_set<string> vis;
        unordered_map<char, string> d;
        return dfs(0, 0, pattern, s, vis, d);
    }

    bool dfs(int i, int j, string& p, string& s, unordered_set<string>& vis, unordered_map<char, string>& d) {
        int m = p.size(), n = s.size();
        if (i == m && j == n) return true;
        if (i == m || j == n || m - i > n - j) return false;
        char c = p[i];
        for (int k = j + 1; k <= n; ++k) {
            string t = s.substr(j, k - j);
            if (d.count(c) && d[c] == t) {
                if (dfs(i + 1, k, p, s, vis, d)) return true;
            }
            if (!d.count(c) && !vis.count(t)) {
                d[c] = t;
                vis.insert(t);
                if (dfs(i + 1, k, p, s, vis, d)) return true;
                vis.erase(t);
                d.erase(c);
            }
        }
        return false;
    }
};
```

#### Go

```go
func wordPatternMatch(pattern string, s string) bool {
	m, n := len(pattern), len(s)
	vis := map[string]bool{}
	d := map[byte]string{}
	var dfs func(i, j int) bool
	dfs = func(i, j int) bool {
		if i == m && j == n {
			return true
		}
		if i == m || j == n || m-i > n-j {
			return false
		}
		c := pattern[i]
		for k := j + 1; k <= n; k++ {
			t := s[j:k]
			if v, ok := d[c]; ok && v == t {
				if dfs(i+1, k) {
					return true
				}
			}
			if _, ok := d[c]; !ok && !vis[t] {
				d[c] = t
				vis[t] = true
				if dfs(i+1, k) {
					return true
				}
				delete(d, c)
				vis[t] = false
			}
		}
		return false
	}
	return dfs(0, 0)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [292. Nim 游戏](https://leetcode.cn/problems/nim-game){#292}

{{< tabs "292" >}}

{{% tab "python" %}}
```python
class Solution:
    def canWinNim(self, n: int) -> bool:
        return n % 4 != 0
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean canWinNim(int n) {
        return n % 4 != 0;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool canWinNim(int n) {
        return n % 4 != 0;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func canWinNim(n int) bool {
	return n%4 != 0
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function canWinNim(n: number): boolean {
    return n % 4 != 0;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn can_win_nim(n: i32) -> bool {
        n % 4 != 0
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你和你的朋友，两个人一起玩&nbsp;<a href="https://baike.baidu.com/item/Nim游戏/6737105" target="_blank">Nim 游戏</a>：</p>

<ul>
	<li>桌子上有一堆石头。</li>
	<li>你们轮流进行自己的回合，&nbsp;<strong>你作为先手&nbsp;</strong>。</li>
	<li>每一回合，轮到的人拿掉&nbsp;1 - 3 块石头。</li>
	<li>拿掉最后一块石头的人就是获胜者。</li>
</ul>

<p>假设你们每一步都是最优解。请编写一个函数，来判断你是否可以在给定石头数量为 <code>n</code> 的情况下赢得游戏。如果可以赢，返回 <code>true</code>；否则，返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong><code>n = 4</code>
<strong>输出：</strong>false 
<strong>解释：</strong>以下是可能的结果:
1. 移除1颗石头。你的朋友移走了3块石头，包括最后一块。你的朋友赢了。
2. 移除2个石子。你的朋友移走2块石头，包括最后一块。你的朋友赢了。
3.你移走3颗石子。你的朋友移走了最后一块石头。你的朋友赢了。
在所有结果中，你的朋友是赢家。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 1
<strong>输出：</strong>true
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 2
<strong>输出：</strong>true
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 2<sup>31</sup> - 1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：找规律

第一个得到 $4$ 的倍数（即 $n$ 能被 $4$ 整除）的将会输掉比赛。

证明：

1. 当 $n \lt 4$ 时，第一个玩家可以直接拿走所有的石头，所以第一个玩家将会赢得比赛。
1. 当 $n = 4$，无论第一个玩家选择 $1, 2, 3$ 哪个数字，第二个玩家总能选择剩下的数字，所以第一个玩家将会输掉比赛。
1. 当 $4 \lt n \lt 8$ 时，即 $n = 5, 6, 7$，第一个玩家可以相应地将数字减少为 $4$，那么 $4$ 这个死亡数字给到了第二个玩家，第二个玩家将会输掉比赛。
1. 当 $n = 8$，无论第一个玩家选择 $1, 2, 3$ 哪个数字，都会把 $4 \lt n \lt 8$ 的数字留给第二个，所以第一个玩家将会输掉比赛。
1. ...
1. 依次类推，当玩家拿到 $n$ 这个数字，且 $n$ 能被 $4$ 整除，他将会输掉比赛，否则他将赢得比赛。

时间复杂度 $O(1)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def canWinNim(self, n: int) -> bool:
        return n % 4 != 0
```

#### Java

```java
class Solution {
    public boolean canWinNim(int n) {
        return n % 4 != 0;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool canWinNim(int n) {
        return n % 4 != 0;
    }
};
```

#### Go

```go
func canWinNim(n int) bool {
	return n%4 != 0
}
```

#### TypeScript

```ts
function canWinNim(n: number): boolean {
    return n % 4 != 0;
}
```

#### Rust

```rust
impl Solution {
    pub fn can_win_nim(n: i32) -> bool {
        n % 4 != 0
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [293. 翻转游戏 🔒](https://leetcode.cn/problems/flip-game){#293}

{{< tabs "293" >}}

{{% tab "python" %}}
```python
class Solution:
    def generatePossibleNextMoves(self, currentState: str) -> List[str]:
        s = list(currentState)
        ans = []
        for i, (a, b) in enumerate(pairwise(s)):
            if a == b == "+":
                s[i] = s[i + 1] = "-"
                ans.append("".join(s))
                s[i] = s[i + 1] = "+"
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<String> generatePossibleNextMoves(String currentState) {
        List<String> ans = new ArrayList<>();
        char[] s = currentState.toCharArray();
        for (int i = 0; i < s.length - 1; ++i) {
            if (s[i] == '+' && s[i + 1] == '+') {
                s[i] = '-';
                s[i + 1] = '-';
                ans.add(new String(s));
                s[i] = '+';
                s[i + 1] = '+';
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
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> ans;
        for (int i = 0; i < s.size() - 1; ++i) {
            if (s[i] == '+' && s[i + 1] == '+') {
                s[i] = s[i + 1] = '-';
                ans.emplace_back(s);
                s[i] = s[i + 1] = '+';
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func generatePossibleNextMoves(currentState string) (ans []string) {
	s := []byte(currentState)
	for i := 0; i < len(s)-1; i++ {
		if s[i] == '+' && s[i+1] == '+' {
			s[i], s[i+1] = '-', '-'
			ans = append(ans, string(s))
			s[i], s[i+1] = '+', '+'
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function generatePossibleNextMoves(currentState: string): string[] {
    const s = currentState.split('');
    const ans: string[] = [];
    for (let i = 0; i < s.length - 1; ++i) {
        if (s[i] === '+' && s[i + 1] === '+') {
            s[i] = s[i + 1] = '-';
            ans.push(s.join(''));
            s[i] = s[i + 1] = '+';
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

<p>你和朋友玩一个叫做「翻转游戏」的游戏。游戏规则如下：</p>

<p>给你一个字符串 <code>currentState</code> ，其中只含 <code>'+'</code> 和 <code>'-'</code> 。你和朋友轮流将 <strong>连续 </strong>的两个 <code>"++"</code> 反转成 <code>"--"</code> 。当一方无法进行有效的翻转时便意味着游戏结束，则另一方获胜。</p>

<p>计算并返回 <strong>一次有效操作</strong> 后，字符串 <code>currentState</code> 所有的可能状态，返回结果可以按 <strong>任意顺序</strong> 排列。如果不存在可能的有效操作，请返回一个空列表 <code>[]</code> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>currentState = "++++"
<strong>输出：</strong>["--++","+--+","++--"]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>currentState = "+"
<strong>输出：</strong>[]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= currentState.length <= 500</code></li>
	<li><code>currentState[i]</code> 不是 <code>'+'</code> 就是 <code>'-'</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：遍历 + 模拟

我们遍历字符串，如果当前字符和下一个字符都是 `+`，那么我们就将这两个字符变成 `-`，然后将结果加入到结果数组中，再将这两个字符变回 `+`。

遍历结束后，返回结果数组即可。

时间复杂度 $O(n^2)$，其中 $n$ 是字符串长度。忽略答案数组的空间复杂度，空间复杂度 $O(n)$ 或 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def generatePossibleNextMoves(self, currentState: str) -> List[str]:
        s = list(currentState)
        ans = []
        for i, (a, b) in enumerate(pairwise(s)):
            if a == b == "+":
                s[i] = s[i + 1] = "-"
                ans.append("".join(s))
                s[i] = s[i + 1] = "+"
        return ans
```

#### Java

```java
class Solution {
    public List<String> generatePossibleNextMoves(String currentState) {
        List<String> ans = new ArrayList<>();
        char[] s = currentState.toCharArray();
        for (int i = 0; i < s.length - 1; ++i) {
            if (s[i] == '+' && s[i + 1] == '+') {
                s[i] = '-';
                s[i + 1] = '-';
                ans.add(new String(s));
                s[i] = '+';
                s[i + 1] = '+';
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
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> ans;
        for (int i = 0; i < s.size() - 1; ++i) {
            if (s[i] == '+' && s[i + 1] == '+') {
                s[i] = s[i + 1] = '-';
                ans.emplace_back(s);
                s[i] = s[i + 1] = '+';
            }
        }
        return ans;
    }
};
```

#### Go

```go
func generatePossibleNextMoves(currentState string) (ans []string) {
	s := []byte(currentState)
	for i := 0; i < len(s)-1; i++ {
		if s[i] == '+' && s[i+1] == '+' {
			s[i], s[i+1] = '-', '-'
			ans = append(ans, string(s))
			s[i], s[i+1] = '+', '+'
		}
	}
	return
}
```

#### TypeScript

```ts
function generatePossibleNextMoves(currentState: string): string[] {
    const s = currentState.split('');
    const ans: string[] = [];
    for (let i = 0; i < s.length - 1; ++i) {
        if (s[i] === '+' && s[i + 1] === '+') {
            s[i] = s[i + 1] = '-';
            ans.push(s.join(''));
            s[i] = s[i + 1] = '+';
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

# [294. 翻转游戏 II 🔒](https://leetcode.cn/problems/flip-game-ii){#294}

{{< tabs "294" >}}

{{% tab "python" %}}
```python
class Solution:
    def canWin(self, currentState: str) -> bool:
        def win(i):
            if sg[i] != -1:
                return sg[i]
            vis = [False] * n
            for j in range(i - 1):
                vis[win(j) ^ win(i - j - 2)] = True
            for j in range(n):
                if not vis[j]:
                    sg[i] = j
                    return j
            return 0

        n = len(currentState)
        sg = [-1] * (n + 1)
        sg[0] = sg[1] = 0
        ans = i = 0
        while i < n:
            j = i
            while j < n and currentState[j] == '+':
                j += 1
            ans ^= win(j - i)
            i = j + 1
        return ans > 0
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int n;
    private int[] sg;

    public boolean canWin(String currentState) {
        n = currentState.length();
        sg = new int[n + 1];
        Arrays.fill(sg, -1);
        int i = 0;
        int ans = 0;
        while (i < n) {
            int j = i;
            while (j < n && currentState.charAt(j) == '+') {
                ++j;
            }
            ans ^= win(j - i);
            i = j + 1;
        }
        return ans > 0;
    }

    private int win(int i) {
        if (sg[i] != -1) {
            return sg[i];
        }
        boolean[] vis = new boolean[n];
        for (int j = 0; j < i - 1; ++j) {
            vis[win(j) ^ win(i - j - 2)] = true;
        }
        for (int j = 0; j < n; ++j) {
            if (!vis[j]) {
                sg[i] = j;
                return j;
            }
        }
        return 0;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool canWin(string currentState) {
        int n = currentState.size();
        vector<int> sg(n + 1, -1);
        sg[0] = 0, sg[1] = 0;

        function<int(int)> win = [&](int i) {
            if (sg[i] != -1) return sg[i];
            vector<bool> vis(n);
            for (int j = 0; j < i - 1; ++j) vis[win(j) ^ win(i - j - 2)] = true;
            for (int j = 0; j < n; ++j)
                if (!vis[j]) return sg[i] = j;
            return 0;
        };

        int ans = 0, i = 0;
        while (i < n) {
            int j = i;
            while (j < n && currentState[j] == '+') ++j;
            ans ^= win(j - i);
            i = j + 1;
        }
        return ans > 0;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func canWin(currentState string) bool {
	n := len(currentState)
	sg := make([]int, n+1)
	for i := range sg {
		sg[i] = -1
	}
	var win func(i int) int
	win = func(i int) int {
		if sg[i] != -1 {
			return sg[i]
		}
		vis := make([]bool, n)
		for j := 0; j < i-1; j++ {
			vis[win(j)^win(i-j-2)] = true
		}
		for j := 0; j < n; j++ {
			if !vis[j] {
				sg[i] = j
				return j
			}
		}
		return 0
	}
	ans, i := 0, 0
	for i < n {
		j := i
		for j < n && currentState[j] == '+' {
			j++
		}
		ans ^= win(j - i)
		i = j + 1
	}
	return ans > 0
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你和朋友玩一个叫做「翻转游戏」的游戏。游戏规则如下：</p>

<p>给你一个字符串 <code>currentState</code> ，其中只含 <code>'+'</code> 和 <code>'-'</code> 。你和朋友轮流将&nbsp;<strong>连续 </strong>的两个&nbsp;<code>"++"</code>&nbsp;反转成&nbsp;<code>"--"</code> 。当一方无法进行有效的翻转时便意味着游戏结束，则另一方获胜。默认每个人都会采取最优策略。</p>

<p>请你写出一个函数来判定起始玩家 <strong>是否存在必胜的方案</strong> ：如果存在，返回 <code>true</code> ；否则，返回 <code>false</code> 。</p>
&nbsp;

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>currentState = "++++"
<strong>输出：</strong>true
<strong>解释：</strong>起始玩家可将中间的 <code>"++"</code> 翻转变为 <code>"+--+" 从而得胜。</code></pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>currentState = "+"
<strong>输出：</strong>false
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= currentState.length &lt;= 60</code></li>
	<li><code>currentState[i]</code> 不是 <code>'+'</code> 就是 <code>'-'</code></li>
	<li>不能有超过 20 个连续的&nbsp;<code>'+'</code>。</li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>请推导你算法的时间复杂度。</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：状态压缩 + 记忆化搜索

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def canWin(self, currentState: str) -> bool:
        @cache
        def dfs(mask):
            for i in range(n - 1):
                if (mask & (1 << i)) == 0 or (mask & (1 << (i + 1)) == 0):
                    continue
                if dfs(mask ^ (1 << i) ^ (1 << (i + 1))):
                    continue
                return True
            return False

        mask, n = 0, len(currentState)
        for i, c in enumerate(currentState):
            if c == '+':
                mask |= 1 << i
        return dfs(mask)
```

#### Java

```java
class Solution {
    private int n;
    private Map<Long, Boolean> memo = new HashMap<>();

    public boolean canWin(String currentState) {
        long mask = 0;
        n = currentState.length();
        for (int i = 0; i < n; ++i) {
            if (currentState.charAt(i) == '+') {
                mask |= 1 << i;
            }
        }
        return dfs(mask);
    }

    private boolean dfs(long mask) {
        if (memo.containsKey(mask)) {
            return memo.get(mask);
        }
        for (int i = 0; i < n - 1; ++i) {
            if ((mask & (1 << i)) == 0 || (mask & (1 << (i + 1))) == 0) {
                continue;
            }
            if (dfs(mask ^ (1 << i) ^ (1 << (i + 1)))) {
                continue;
            }
            memo.put(mask, true);
            return true;
        }
        memo.put(mask, false);
        return false;
    }
}
```

#### C++

```cpp
using ll = long long;

class Solution {
public:
    int n;
    unordered_map<ll, bool> memo;

    bool canWin(string currentState) {
        n = currentState.size();
        ll mask = 0;
        for (int i = 0; i < n; ++i)
            if (currentState[i] == '+') mask |= 1ll << i;
        return dfs(mask);
    }

    bool dfs(ll mask) {
        if (memo.count(mask)) return memo[mask];
        for (int i = 0; i < n - 1; ++i) {
            if ((mask & (1ll << i)) == 0 || (mask & (1ll << (i + 1))) == 0) continue;
            if (dfs(mask ^ (1ll << i) ^ (1ll << (i + 1)))) continue;
            memo[mask] = true;
            return true;
        }
        memo[mask] = false;
        return false;
    }
};
```

#### Go

```go
func canWin(currentState string) bool {
	n := len(currentState)
	memo := map[int]bool{}
	mask := 0
	for i, c := range currentState {
		if c == '+' {
			mask |= 1 << i
		}
	}
	var dfs func(int) bool
	dfs = func(mask int) bool {
		if v, ok := memo[mask]; ok {
			return v
		}
		for i := 0; i < n-1; i++ {
			if (mask&(1<<i)) == 0 || (mask&(1<<(i+1))) == 0 {
				continue
			}
			if dfs(mask ^ (1 << i) ^ (1 << (i + 1))) {
				continue
			}
			memo[mask] = true
			return true
		}
		memo[mask] = false
		return false
	}
	return dfs(mask)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：Sprague-Grundy 定理

Sprague-Grundy 定理为游戏的每一个状态定义了一个 Sprague-Grundy 数（简称 SG 数），游戏状态的组合相当于 SG 数的异或运算。

Sprague-Grundy 定理的完整表述如下：

若一个游戏满足以下条件：

1. 双人、回合制
1. 信息完全公开
1. 无随机因素
1. 必然在有限步内结束，且每步的走法数有限
1. 没有平局
1. 双方可采取的行动及胜利目标都相同
1. 这个胜利目标是自己亲手达成终局状态，或者说走最后一步者为胜（normal play）

则游戏中的每个状态可以按如下规则赋予一个非负整数，称为 Sprague-Grundy 数，即 $SG(A)=mex\{SG(B)|A->B\}$。（式中 $A$, $B$ 代表状态，代表 $A$ 状态经一步行动可以到达 $B$ 状态，而 $mex$ 表示一个集合所不包含的最小非负整数）

SG 数有如下性质：

1. SG 数为 0 的状态，后手必胜；SG 数为正的状态，先手必胜；
1. 若一个母状态可以拆分成多个相互独立的子状态，则母状态的 SG 数等于各个子状态的 SG 数的异或。

参考资料：[Sprague-Grundy 定理是怎么想出来的](https://zhuanlan.zhihu.com/p/20611132)

时间复杂度 $O(n^2)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def canWin(self, currentState: str) -> bool:
        def win(i):
            if sg[i] != -1:
                return sg[i]
            vis = [False] * n
            for j in range(i - 1):
                vis[win(j) ^ win(i - j - 2)] = True
            for j in range(n):
                if not vis[j]:
                    sg[i] = j
                    return j
            return 0

        n = len(currentState)
        sg = [-1] * (n + 1)
        sg[0] = sg[1] = 0
        ans = i = 0
        while i < n:
            j = i
            while j < n and currentState[j] == '+':
                j += 1
            ans ^= win(j - i)
            i = j + 1
        return ans > 0
```

#### Java

```java
class Solution {
    private int n;
    private int[] sg;

    public boolean canWin(String currentState) {
        n = currentState.length();
        sg = new int[n + 1];
        Arrays.fill(sg, -1);
        int i = 0;
        int ans = 0;
        while (i < n) {
            int j = i;
            while (j < n && currentState.charAt(j) == '+') {
                ++j;
            }
            ans ^= win(j - i);
            i = j + 1;
        }
        return ans > 0;
    }

    private int win(int i) {
        if (sg[i] != -1) {
            return sg[i];
        }
        boolean[] vis = new boolean[n];
        for (int j = 0; j < i - 1; ++j) {
            vis[win(j) ^ win(i - j - 2)] = true;
        }
        for (int j = 0; j < n; ++j) {
            if (!vis[j]) {
                sg[i] = j;
                return j;
            }
        }
        return 0;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool canWin(string currentState) {
        int n = currentState.size();
        vector<int> sg(n + 1, -1);
        sg[0] = 0, sg[1] = 0;

        function<int(int)> win = [&](int i) {
            if (sg[i] != -1) return sg[i];
            vector<bool> vis(n);
            for (int j = 0; j < i - 1; ++j) vis[win(j) ^ win(i - j - 2)] = true;
            for (int j = 0; j < n; ++j)
                if (!vis[j]) return sg[i] = j;
            return 0;
        };

        int ans = 0, i = 0;
        while (i < n) {
            int j = i;
            while (j < n && currentState[j] == '+') ++j;
            ans ^= win(j - i);
            i = j + 1;
        }
        return ans > 0;
    }
};
```

#### Go

```go
func canWin(currentState string) bool {
	n := len(currentState)
	sg := make([]int, n+1)
	for i := range sg {
		sg[i] = -1
	}
	var win func(i int) int
	win = func(i int) int {
		if sg[i] != -1 {
			return sg[i]
		}
		vis := make([]bool, n)
		for j := 0; j < i-1; j++ {
			vis[win(j)^win(i-j-2)] = true
		}
		for j := 0; j < n; j++ {
			if !vis[j] {
				sg[i] = j
				return j
			}
		}
		return 0
	}
	ans, i := 0, 0
	for i < n {
		j := i
		for j < n && currentState[j] == '+' {
			j++
		}
		ans ^= win(j - i)
		i = j + 1
	}
	return ans > 0
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [295. 数据流的中位数](https://leetcode.cn/problems/find-median-from-data-stream){#295}

{{< tabs "295" >}}

{{% tab "python" %}}
```python
class MedianFinder:

    def __init__(self):
        self.minq = []
        self.maxq = []

    def addNum(self, num: int) -> None:
        heappush(self.minq, -heappushpop(self.maxq, -num))
        if len(self.minq) - len(self.maxq) > 1:
            heappush(self.maxq, -heappop(self.minq))

    def findMedian(self) -> float:
        if len(self.minq) == len(self.maxq):
            return (self.minq[0] - self.maxq[0]) / 2
        return self.minq[0]


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()
```
{{% /tab %}}
{{% tab "java" %}}
```java
class MedianFinder {
    private PriorityQueue<Integer> minQ = new PriorityQueue<>();
    private PriorityQueue<Integer> maxQ = new PriorityQueue<>(Collections.reverseOrder());

    public MedianFinder() {
    }

    public void addNum(int num) {
        maxQ.offer(num);
        minQ.offer(maxQ.poll());
        if (minQ.size() - maxQ.size() > 1) {
            maxQ.offer(minQ.poll());
        }
    }

    public double findMedian() {
        return minQ.size() == maxQ.size() ? (minQ.peek() + maxQ.peek()) / 2.0 : minQ.peek();
    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class MedianFinder {
public:
    MedianFinder() {
    }

    void addNum(int num) {
        maxQ.push(num);
        minQ.push(maxQ.top());
        maxQ.pop();

        if (minQ.size() > maxQ.size() + 1) {
            maxQ.push(minQ.top());
            minQ.pop();
        }
    }

    double findMedian() {
        return minQ.size() == maxQ.size() ? (minQ.top() + maxQ.top()) / 2.0 : minQ.top();
    }

private:
    priority_queue<int> maxQ;
    priority_queue<int, vector<int>, greater<int>> minQ;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type MedianFinder struct {
	minq hp
	maxq hp
}

func Constructor() MedianFinder {
	return MedianFinder{hp{}, hp{}}
}

func (this *MedianFinder) AddNum(num int) {
	minq, maxq := &this.minq, &this.maxq
	heap.Push(maxq, -num)
	heap.Push(minq, -heap.Pop(maxq).(int))
	if minq.Len()-maxq.Len() > 1 {
		heap.Push(maxq, -heap.Pop(minq).(int))
	}
}

func (this *MedianFinder) FindMedian() float64 {
	minq, maxq := this.minq, this.maxq
	if minq.Len() == maxq.Len() {
		return float64(minq.IntSlice[0]-maxq.IntSlice[0]) / 2
	}
	return float64(minq.IntSlice[0])
}

type hp struct{ sort.IntSlice }

func (h hp) Less(i, j int) bool { return h.IntSlice[i] < h.IntSlice[j] }
func (h *hp) Push(v any)        { h.IntSlice = append(h.IntSlice, v.(int)) }
func (h *hp) Pop() any {
	a := h.IntSlice
	v := a[len(a)-1]
	h.IntSlice = a[:len(a)-1]
	return v
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * obj := Constructor();
 * obj.AddNum(num);
 * param_2 := obj.FindMedian();
 */
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class MedianFinder {
    #minQ = new MinPriorityQueue();
    #maxQ = new MaxPriorityQueue();

    addNum(num: number): void {
        const [minQ, maxQ] = [this.#minQ, this.#maxQ];
        maxQ.enqueue(num);
        minQ.enqueue(maxQ.dequeue().element);
        if (minQ.size() - maxQ.size() > 1) {
            maxQ.enqueue(minQ.dequeue().element);
        }
    }

    findMedian(): number {
        const [minQ, maxQ] = [this.#minQ, this.#maxQ];
        if (minQ.size() === maxQ.size()) {
            return (minQ.front().element + maxQ.front().element) / 2;
        }
        return minQ.front().element;
    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * var obj = new MedianFinder()
 * obj.addNum(num)
 * var param_2 = obj.findMedian()
 */
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::cmp::Reverse;
use std::collections::BinaryHeap;

struct MedianFinder {
    minQ: BinaryHeap<Reverse<i32>>,
    maxQ: BinaryHeap<i32>,
}

impl MedianFinder {
    fn new() -> Self {
        MedianFinder {
            minQ: BinaryHeap::new(),
            maxQ: BinaryHeap::new(),
        }
    }

    fn add_num(&mut self, num: i32) {
        self.maxQ.push(num);
        self.minQ.push(Reverse(self.maxQ.pop().unwrap()));

        if self.minQ.len() > self.maxQ.len() + 1 {
            self.maxQ.push(self.minQ.pop().unwrap().0);
        }
    }

    fn find_median(&self) -> f64 {
        if self.minQ.len() == self.maxQ.len() {
            let min_top = self.minQ.peek().unwrap().0;
            let max_top = *self.maxQ.peek().unwrap();
            (min_top + max_top) as f64 / 2.0
        } else {
            self.minQ.peek().unwrap().0 as f64
        }
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
var MedianFinder = function () {
    this.minQ = new MinPriorityQueue();
    this.maxQ = new MaxPriorityQueue();
};

/**
 * @param {number} num
 * @return {void}
 */
MedianFinder.prototype.addNum = function (num) {
    this.maxQ.enqueue(num);
    this.minQ.enqueue(this.maxQ.dequeue().element);
    if (this.minQ.size() - this.maxQ.size() > 1) {
        this.maxQ.enqueue(this.minQ.dequeue().element);
    }
};

/**
 * @return {number}
 */
MedianFinder.prototype.findMedian = function () {
    if (this.minQ.size() === this.maxQ.size()) {
        return (this.minQ.front().element + this.maxQ.front().element) / 2;
    }
    return this.minQ.front().element;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * var obj = new MedianFinder()
 * obj.addNum(num)
 * var param_2 = obj.findMedian()
 */
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class MedianFinder {
    private PriorityQueue<int, int> minQ = new PriorityQueue<int, int>();
    private PriorityQueue<int, int> maxQ = new PriorityQueue<int, int>(Comparer<int>.Create((a, b) => b.CompareTo(a)));

    public MedianFinder() {

    }

    public void AddNum(int num) {
        maxQ.Enqueue(num, num);
        minQ.Enqueue(maxQ.Peek(), maxQ.Dequeue());
        if (minQ.Count > maxQ.Count + 1) {
            maxQ.Enqueue(minQ.Peek(), minQ.Dequeue());
        }
    }

    public double FindMedian() {
        return minQ.Count == maxQ.Count ? (minQ.Peek() + maxQ.Peek()) / 2.0 : minQ.Peek();
    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.AddNum(num);
 * double param_2 = obj.FindMedian();
 */
```
{{% /tab %}}
{{% tab "swift" %}}
```swift
class MedianFinder {
    private var minQ = Heap<Int>(sort: <)
    private var maxQ = Heap<Int>(sort: >)

    init() {
    }

    func addNum(_ num: Int) {
        maxQ.insert(num)
        minQ.insert(maxQ.remove()!)
        if maxQ.count < minQ.count {
            maxQ.insert(minQ.remove()!)
        }
    }

    func findMedian() -> Double {
        if maxQ.count > minQ.count {
            return Double(maxQ.peek()!)
        }
        return (Double(maxQ.peek()!) + Double(minQ.peek()!)) / 2.0
    }
}

struct Heap<T> {
    var elements: [T]
    let sort: (T, T) -> Bool

    init(sort: @escaping (T, T) -> Bool, elements: [T] = []) {
        self.sort = sort
        self.elements = elements
        if !elements.isEmpty {
            for i in stride(from: elements.count / 2 - 1, through: 0, by: -1) {
                siftDown(from: i)
            }
        }
    }

    var isEmpty: Bool {
        return elements.isEmpty
    }

    var count: Int {
        return elements.count
    }

    func peek() -> T? {
        return elements.first
    }

    mutating func insert(_ value: T) {
        elements.append(value)
        siftUp(from: elements.count - 1)
    }

    mutating func remove() -> T? {
        guard !elements.isEmpty else { return nil }
        elements.swapAt(0, elements.count - 1)
        let removedValue = elements.removeLast()
        siftDown(from: 0)
        return removedValue
    }

    private mutating func siftUp(from index: Int) {
        var child = index
        var parent = parentIndex(ofChildAt: child)
        while child > 0 && sort(elements[child], elements[parent]) {
            elements.swapAt(child, parent)
            child = parent
            parent = parentIndex(ofChildAt: child)
        }
    }

    private mutating func siftDown(from index: Int) {
        var parent = index
        while true {
            let left = leftChildIndex(ofParentAt: parent)
            let right = rightChildIndex(ofParentAt: parent)
            var candidate = parent
            if left < count && sort(elements[left], elements[candidate]) {
                candidate = left
            }
            if right < count && sort(elements[right], elements[candidate]) {
                candidate = right
            }
            if candidate == parent {
                return
            }
            elements.swapAt(parent, candidate)
            parent = candidate
        }
    }

    private func parentIndex(ofChildAt index: Int) -> Int {
        return (index - 1) / 2
    }

    private func leftChildIndex(ofParentAt index: Int) -> Int {
        return 2 * index + 1
    }

    private func rightChildIndex(ofParentAt index: Int) -> Int {
        return 2 * index + 2
    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * let obj = MedianFinder()
 * obj.addNum(num)
 * let ret_2: Double = obj.findMedian()
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p><strong>中位数</strong>是有序整数列表中的中间值。如果列表的大小是偶数，则没有中间值，中位数是两个中间值的平均值。</p>

<ul>
	<li>例如 <code>arr = [2,3,4]</code>&nbsp;的中位数是 <code>3</code>&nbsp;。</li>
	<li>例如&nbsp;<code>arr = [2,3]</code> 的中位数是 <code>(2 + 3) / 2 = 2.5</code> 。</li>
</ul>

<p>实现 MedianFinder 类:</p>

<ul>
	<li>
	<p><code>MedianFinder()</code> 初始化 <code>MedianFinder</code>&nbsp;对象。</p>
	</li>
	<li>
	<p><code>void addNum(int num)</code> 将数据流中的整数 <code>num</code> 添加到数据结构中。</p>
	</li>
	<li>
	<p><code>double findMedian()</code> 返回到目前为止所有元素的中位数。与实际答案相差&nbsp;<code>10<sup>-5</sup></code>&nbsp;以内的答案将被接受。</p>
	</li>
</ul>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入</strong>
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
<strong>输出</strong>
[null, null, null, 1.5, null, 2.0]

<strong>解释</strong>
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.addNum(2);    // arr = [1, 2]
medianFinder.findMedian(); // 返回 1.5 ((1 + 2) / 2)
medianFinder.addNum(3);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0</pre>

<p><strong>提示:</strong></p>

<ul>
	<li><code>-10<sup>5</sup>&nbsp;&lt;= num &lt;= 10<sup>5</sup></code></li>
	<li>在调用 <code>findMedian</code>&nbsp;之前，数据结构中至少有一个元素</li>
	<li>最多&nbsp;<code>5 * 10<sup>4</sup></code>&nbsp;次调用&nbsp;<code>addNum</code>&nbsp;和&nbsp;<code>findMedian</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：大小根堆（优先队列）

我们可以使用两个堆来维护所有的元素，一个小根堆 $\textit{minQ}$ 和一个大根堆 $\textit{maxQ}$，其中小根堆 $\textit{minQ}$ 存储较大的一半，大根堆 $\textit{maxQ}$ 存储较小的一半。

调用 `addNum` 方法时，我们首先将元素加入到大根堆 $\textit{maxQ}$，然后将 $\textit{maxQ}$ 的堆顶元素弹出并加入到小根堆 $\textit{minQ}$。如果此时 $\textit{minQ}$ 的大小与 $\textit{maxQ}$ 的大小差值大于 $1$，我们就将 $\textit{minQ}$ 的堆顶元素弹出并加入到 $\textit{maxQ}$。时间复杂度为 $O(\log n)$。

调用 `findMedian` 方法时，如果 $\textit{minQ}$ 的大小等于 $\textit{maxQ}$ 的大小，说明元素的总数为偶数，我们就可以返回 $\textit{minQ}$ 的堆顶元素与 $\textit{maxQ}$ 的堆顶元素的平均值；否则，我们返回 $\textit{minQ}$ 的堆顶元素。时间复杂度为 $O(1)$。

空间复杂度为 $O(n)$。其中 $n$ 为元素的个数。

<!-- tabs:start -->

#### Python3

```python
class MedianFinder:

    def __init__(self):
        self.minq = []
        self.maxq = []

    def addNum(self, num: int) -> None:
        heappush(self.minq, -heappushpop(self.maxq, -num))
        if len(self.minq) - len(self.maxq) > 1:
            heappush(self.maxq, -heappop(self.minq))

    def findMedian(self) -> float:
        if len(self.minq) == len(self.maxq):
            return (self.minq[0] - self.maxq[0]) / 2
        return self.minq[0]


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()
```

#### Java

```java
class MedianFinder {
    private PriorityQueue<Integer> minQ = new PriorityQueue<>();
    private PriorityQueue<Integer> maxQ = new PriorityQueue<>(Collections.reverseOrder());

    public MedianFinder() {
    }

    public void addNum(int num) {
        maxQ.offer(num);
        minQ.offer(maxQ.poll());
        if (minQ.size() - maxQ.size() > 1) {
            maxQ.offer(minQ.poll());
        }
    }

    public double findMedian() {
        return minQ.size() == maxQ.size() ? (minQ.peek() + maxQ.peek()) / 2.0 : minQ.peek();
    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
```

#### C++

```cpp
class MedianFinder {
public:
    MedianFinder() {
    }

    void addNum(int num) {
        maxQ.push(num);
        minQ.push(maxQ.top());
        maxQ.pop();

        if (minQ.size() > maxQ.size() + 1) {
            maxQ.push(minQ.top());
            minQ.pop();
        }
    }

    double findMedian() {
        return minQ.size() == maxQ.size() ? (minQ.top() + maxQ.top()) / 2.0 : minQ.top();
    }

private:
    priority_queue<int> maxQ;
    priority_queue<int, vector<int>, greater<int>> minQ;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
```

#### Go

```go
type MedianFinder struct {
	minq hp
	maxq hp
}

func Constructor() MedianFinder {
	return MedianFinder{hp{}, hp{}}
}

func (this *MedianFinder) AddNum(num int) {
	minq, maxq := &this.minq, &this.maxq
	heap.Push(maxq, -num)
	heap.Push(minq, -heap.Pop(maxq).(int))
	if minq.Len()-maxq.Len() > 1 {
		heap.Push(maxq, -heap.Pop(minq).(int))
	}
}

func (this *MedianFinder) FindMedian() float64 {
	minq, maxq := this.minq, this.maxq
	if minq.Len() == maxq.Len() {
		return float64(minq.IntSlice[0]-maxq.IntSlice[0]) / 2
	}
	return float64(minq.IntSlice[0])
}

type hp struct{ sort.IntSlice }

func (h hp) Less(i, j int) bool { return h.IntSlice[i] < h.IntSlice[j] }
func (h *hp) Push(v any)        { h.IntSlice = append(h.IntSlice, v.(int)) }
func (h *hp) Pop() any {
	a := h.IntSlice
	v := a[len(a)-1]
	h.IntSlice = a[:len(a)-1]
	return v
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * obj := Constructor();
 * obj.AddNum(num);
 * param_2 := obj.FindMedian();
 */
```

#### TypeScript

```ts
class MedianFinder {
    #minQ = new MinPriorityQueue();
    #maxQ = new MaxPriorityQueue();

    addNum(num: number): void {
        const [minQ, maxQ] = [this.#minQ, this.#maxQ];
        maxQ.enqueue(num);
        minQ.enqueue(maxQ.dequeue().element);
        if (minQ.size() - maxQ.size() > 1) {
            maxQ.enqueue(minQ.dequeue().element);
        }
    }

    findMedian(): number {
        const [minQ, maxQ] = [this.#minQ, this.#maxQ];
        if (minQ.size() === maxQ.size()) {
            return (minQ.front().element + maxQ.front().element) / 2;
        }
        return minQ.front().element;
    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * var obj = new MedianFinder()
 * obj.addNum(num)
 * var param_2 = obj.findMedian()
 */
```

#### Rust

```rust
use std::cmp::Reverse;
use std::collections::BinaryHeap;

struct MedianFinder {
    minQ: BinaryHeap<Reverse<i32>>,
    maxQ: BinaryHeap<i32>,
}

impl MedianFinder {
    fn new() -> Self {
        MedianFinder {
            minQ: BinaryHeap::new(),
            maxQ: BinaryHeap::new(),
        }
    }

    fn add_num(&mut self, num: i32) {
        self.maxQ.push(num);
        self.minQ.push(Reverse(self.maxQ.pop().unwrap()));

        if self.minQ.len() > self.maxQ.len() + 1 {
            self.maxQ.push(self.minQ.pop().unwrap().0);
        }
    }

    fn find_median(&self) -> f64 {
        if self.minQ.len() == self.maxQ.len() {
            let min_top = self.minQ.peek().unwrap().0;
            let max_top = *self.maxQ.peek().unwrap();
            (min_top + max_top) as f64 / 2.0
        } else {
            self.minQ.peek().unwrap().0 as f64
        }
    }
}
```

#### JavaScript

```js
var MedianFinder = function () {
    this.minQ = new MinPriorityQueue();
    this.maxQ = new MaxPriorityQueue();
};

/**
 * @param {number} num
 * @return {void}
 */
MedianFinder.prototype.addNum = function (num) {
    this.maxQ.enqueue(num);
    this.minQ.enqueue(this.maxQ.dequeue().element);
    if (this.minQ.size() - this.maxQ.size() > 1) {
        this.maxQ.enqueue(this.minQ.dequeue().element);
    }
};

/**
 * @return {number}
 */
MedianFinder.prototype.findMedian = function () {
    if (this.minQ.size() === this.maxQ.size()) {
        return (this.minQ.front().element + this.maxQ.front().element) / 2;
    }
    return this.minQ.front().element;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * var obj = new MedianFinder()
 * obj.addNum(num)
 * var param_2 = obj.findMedian()
 */
```

#### C#

```cs
public class MedianFinder {
    private PriorityQueue<int, int> minQ = new PriorityQueue<int, int>();
    private PriorityQueue<int, int> maxQ = new PriorityQueue<int, int>(Comparer<int>.Create((a, b) => b.CompareTo(a)));

    public MedianFinder() {

    }

    public void AddNum(int num) {
        maxQ.Enqueue(num, num);
        minQ.Enqueue(maxQ.Peek(), maxQ.Dequeue());
        if (minQ.Count > maxQ.Count + 1) {
            maxQ.Enqueue(minQ.Peek(), minQ.Dequeue());
        }
    }

    public double FindMedian() {
        return minQ.Count == maxQ.Count ? (minQ.Peek() + maxQ.Peek()) / 2.0 : minQ.Peek();
    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.AddNum(num);
 * double param_2 = obj.FindMedian();
 */
```

#### Swift

```swift
class MedianFinder {
    private var minQ = Heap<Int>(sort: <)
    private var maxQ = Heap<Int>(sort: >)

    init() {
    }

    func addNum(_ num: Int) {
        maxQ.insert(num)
        minQ.insert(maxQ.remove()!)
        if maxQ.count < minQ.count {
            maxQ.insert(minQ.remove()!)
        }
    }

    func findMedian() -> Double {
        if maxQ.count > minQ.count {
            return Double(maxQ.peek()!)
        }
        return (Double(maxQ.peek()!) + Double(minQ.peek()!)) / 2.0
    }
}

struct Heap<T> {
    var elements: [T]
    let sort: (T, T) -> Bool

    init(sort: @escaping (T, T) -> Bool, elements: [T] = []) {
        self.sort = sort
        self.elements = elements
        if !elements.isEmpty {
            for i in stride(from: elements.count / 2 - 1, through: 0, by: -1) {
                siftDown(from: i)
            }
        }
    }

    var isEmpty: Bool {
        return elements.isEmpty
    }

    var count: Int {
        return elements.count
    }

    func peek() -> T? {
        return elements.first
    }

    mutating func insert(_ value: T) {
        elements.append(value)
        siftUp(from: elements.count - 1)
    }

    mutating func remove() -> T? {
        guard !elements.isEmpty else { return nil }
        elements.swapAt(0, elements.count - 1)
        let removedValue = elements.removeLast()
        siftDown(from: 0)
        return removedValue
    }

    private mutating func siftUp(from index: Int) {
        var child = index
        var parent = parentIndex(ofChildAt: child)
        while child > 0 && sort(elements[child], elements[parent]) {
            elements.swapAt(child, parent)
            child = parent
            parent = parentIndex(ofChildAt: child)
        }
    }

    private mutating func siftDown(from index: Int) {
        var parent = index
        while true {
            let left = leftChildIndex(ofParentAt: parent)
            let right = rightChildIndex(ofParentAt: parent)
            var candidate = parent
            if left < count && sort(elements[left], elements[candidate]) {
                candidate = left
            }
            if right < count && sort(elements[right], elements[candidate]) {
                candidate = right
            }
            if candidate == parent {
                return
            }
            elements.swapAt(parent, candidate)
            parent = candidate
        }
    }

    private func parentIndex(ofChildAt index: Int) -> Int {
        return (index - 1) / 2
    }

    private func leftChildIndex(ofParentAt index: Int) -> Int {
        return 2 * index + 1
    }

    private func rightChildIndex(ofParentAt index: Int) -> Int {
        return 2 * index + 2
    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * let obj = MedianFinder()
 * obj.addNum(num)
 * let ret_2: Double = obj.findMedian()
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [296. 最佳的碰头地点 🔒](https://leetcode.cn/problems/best-meeting-point){#296}

{{< tabs "296" >}}

{{% tab "python" %}}
```python
class Solution:
    def minTotalDistance(self, grid: List[List[int]]) -> int:
        def f(arr, x):
            return sum(abs(v - x) for v in arr)

        rows, cols = [], []
        for i, row in enumerate(grid):
            for j, v in enumerate(row):
                if v:
                    rows.append(i)
                    cols.append(j)
        cols.sort()
        i = rows[len(rows) >> 1]
        j = cols[len(cols) >> 1]
        return f(rows, i) + f(cols, j)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minTotalDistance(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        List<Integer> rows = new ArrayList<>();
        List<Integer> cols = new ArrayList<>();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    rows.add(i);
                    cols.add(j);
                }
            }
        }
        Collections.sort(cols);
        int i = rows.get(rows.size() >> 1);
        int j = cols.get(cols.size() >> 1);
        return f(rows, i) + f(cols, j);
    }

    private int f(List<Integer> arr, int x) {
        int s = 0;
        for (int v : arr) {
            s += Math.abs(v - x);
        }
        return s;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> rows;
        vector<int> cols;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    rows.emplace_back(i);
                    cols.emplace_back(j);
                }
            }
        }
        sort(cols.begin(), cols.end());
        int i = rows[rows.size() / 2];
        int j = cols[cols.size() / 2];
        auto f = [](vector<int>& arr, int x) {
            int s = 0;
            for (int v : arr) {
                s += abs(v - x);
            }
            return s;
        };
        return f(rows, i) + f(cols, j);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minTotalDistance(grid [][]int) int {
	rows, cols := []int{}, []int{}
	for i, row := range grid {
		for j, v := range row {
			if v == 1 {
				rows = append(rows, i)
				cols = append(cols, j)
			}
		}
	}
	sort.Ints(cols)
	i := rows[len(rows)>>1]
	j := cols[len(cols)>>1]
	f := func(arr []int, x int) int {
		s := 0
		for _, v := range arr {
			s += abs(v - x)
		}
		return s
	}
	return f(rows, i) + f(cols, j)
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    #[allow(dead_code)]
    pub fn min_total_distance(grid: Vec<Vec<i32>>) -> i32 {
        let n = grid.len();
        let m = grid[0].len();

        let mut row_vec = Vec::new();
        let mut col_vec = Vec::new();

        // Initialize the two vector
        for i in 0..n {
            for j in 0..m {
                if grid[i][j] == 1 {
                    row_vec.push(i as i32);
                    col_vec.push(j as i32);
                }
            }
        }

        // Since the row vector is originally sorted, we only need to sort the col vector here
        col_vec.sort();

        Self::compute_manhattan_dis(&row_vec, row_vec[row_vec.len() / 2])
            + Self::compute_manhattan_dis(&col_vec, col_vec[col_vec.len() / 2])
    }

    #[allow(dead_code)]
    fn compute_manhattan_dis(v: &Vec<i32>, e: i32) -> i32 {
        let mut ret = 0;

        for num in v {
            ret += (num - e).abs();
        }

        ret
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个&nbsp;<code>m x n</code>&nbsp;&nbsp;的二进制网格&nbsp;<code>grid</code>&nbsp;，其中 <code>1</code> 表示某个朋友的家所处的位置。返回 <em>最小的 <strong>总行走距离</strong></em> 。</p>

<p><strong>总行走距离</strong> 是朋友们家到碰头地点的距离之和。</p>

<p>我们将使用&nbsp;<a href="https://baike.baidu.com/item/%E6%9B%BC%E5%93%88%E9%A1%BF%E8%B7%9D%E7%A6%BB" target="_blank">曼哈顿距离</a>&nbsp;来计算，其中&nbsp;<code>distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0200-0299/0296.Best%20Meeting%20Point/images/meetingpoint-grid.jpg" /></p>

<pre>
<strong>输入:</strong> grid = [[1,0,0,0,1],[0,0,0,0,0],[0,0,1,0,0]]
<strong>输出: </strong>6 <strong>
解释: </strong>给定的三个人分别住在<code>(0,0)，</code><code>(0,4) </code>和 <code>(2,2)</code>:
&nbsp;    <code>(0,2)</code> 是一个最佳的碰面点，其总行走距离为 2 + 2 + 2 = 6，最小，因此返回 6。</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> grid = [[1,1]]
<strong>输出:</strong> 1</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 200</code></li>
	<li><code>grid[i][j] ==</code>&nbsp;<code>0</code>&nbsp;or&nbsp;<code>1</code>.</li>
	<li><code>grid</code>&nbsp;中 <strong>至少</strong> 有两个朋友</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 中位数

对于每一行，我们可以将所有的 $1$ 的下标排序，然后取中位数 $i$ 作为碰头地点的横坐标。

对于每一列，我们可以将所有的 $1$ 的下标排序，然后取中位数 $i$ 作为碰头地点的纵坐标。

最后，我们计算所有 $1$ 到碰头地点 $(i, j)$ 的曼哈顿距离之和即可。

时间复杂度 $O(m\times n\times \log(m\times n))$。最多有 $m\times n$ 个 $1$，排序的时间复杂度为 $\log(m\times n)$。

相似题目：

-   [462. 最少移动次数使数组元素相等 II](https://github.com/doocs/leetcode/blob/main/solution/0400-0499/0462.Minimum%20Moves%20to%20Equal%20Array%20Elements%20II/README.md)
-   [2448. 使数组相等的最小开销](https://github.com/doocs/leetcode/blob/main/solution/2400-2499/2448.Minimum%20Cost%20to%20Make%20Array%20Equal/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minTotalDistance(self, grid: List[List[int]]) -> int:
        def f(arr, x):
            return sum(abs(v - x) for v in arr)

        rows, cols = [], []
        for i, row in enumerate(grid):
            for j, v in enumerate(row):
                if v:
                    rows.append(i)
                    cols.append(j)
        cols.sort()
        i = rows[len(rows) >> 1]
        j = cols[len(cols) >> 1]
        return f(rows, i) + f(cols, j)
```

#### Java

```java
class Solution {
    public int minTotalDistance(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        List<Integer> rows = new ArrayList<>();
        List<Integer> cols = new ArrayList<>();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    rows.add(i);
                    cols.add(j);
                }
            }
        }
        Collections.sort(cols);
        int i = rows.get(rows.size() >> 1);
        int j = cols.get(cols.size() >> 1);
        return f(rows, i) + f(cols, j);
    }

    private int f(List<Integer> arr, int x) {
        int s = 0;
        for (int v : arr) {
            s += Math.abs(v - x);
        }
        return s;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> rows;
        vector<int> cols;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    rows.emplace_back(i);
                    cols.emplace_back(j);
                }
            }
        }
        sort(cols.begin(), cols.end());
        int i = rows[rows.size() / 2];
        int j = cols[cols.size() / 2];
        auto f = [](vector<int>& arr, int x) {
            int s = 0;
            for (int v : arr) {
                s += abs(v - x);
            }
            return s;
        };
        return f(rows, i) + f(cols, j);
    }
};
```

#### Go

```go
func minTotalDistance(grid [][]int) int {
	rows, cols := []int{}, []int{}
	for i, row := range grid {
		for j, v := range row {
			if v == 1 {
				rows = append(rows, i)
				cols = append(cols, j)
			}
		}
	}
	sort.Ints(cols)
	i := rows[len(rows)>>1]
	j := cols[len(cols)>>1]
	f := func(arr []int, x int) int {
		s := 0
		for _, v := range arr {
			s += abs(v - x)
		}
		return s
	}
	return f(rows, i) + f(cols, j)
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
```

#### Rust

```rust
impl Solution {
    #[allow(dead_code)]
    pub fn min_total_distance(grid: Vec<Vec<i32>>) -> i32 {
        let n = grid.len();
        let m = grid[0].len();

        let mut row_vec = Vec::new();
        let mut col_vec = Vec::new();

        // Initialize the two vector
        for i in 0..n {
            for j in 0..m {
                if grid[i][j] == 1 {
                    row_vec.push(i as i32);
                    col_vec.push(j as i32);
                }
            }
        }

        // Since the row vector is originally sorted, we only need to sort the col vector here
        col_vec.sort();

        Self::compute_manhattan_dis(&row_vec, row_vec[row_vec.len() / 2])
            + Self::compute_manhattan_dis(&col_vec, col_vec[col_vec.len() / 2])
    }

    #[allow(dead_code)]
    fn compute_manhattan_dis(v: &Vec<i32>, e: i32) -> i32 {
        let mut ret = 0;

        for num in v {
            ret += (num - e).abs();
        }

        ret
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [297. 二叉树的序列化与反序列化](https://leetcode.cn/problems/serialize-and-deserialize-binary-tree){#297}

{{< tabs "297" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Codec:
    def serialize(self, root):
        """Encodes a tree to a single string.

        :type root: TreeNode
        :rtype: str
        """
        if root is None:
            return ""
        q = deque([root])
        ans = []
        while q:
            node = q.popleft()
            if node:
                ans.append(str(node.val))
                q.append(node.left)
                q.append(node.right)
            else:
                ans.append("#")
        return ",".join(ans)

    def deserialize(self, data):
        """Decodes your encoded data to tree.

        :type data: str
        :rtype: TreeNode
        """
        if not data:
            return None
        vals = data.split(",")
        root = TreeNode(int(vals[0]))
        q = deque([root])
        i = 1
        while q:
            node = q.popleft()
            if vals[i] != "#":
                node.left = TreeNode(int(vals[i]))
                q.append(node.left)
            i += 1
            if vals[i] != "#":
                node.right = TreeNode(int(vals[i]))
                q.append(node.right)
            i += 1
        return root


# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))
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
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Codec {

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        if (root == null) {
            return null;
        }
        List<String> ans = new ArrayList<>();
        Deque<TreeNode> q = new LinkedList<>();
        q.offer(root);
        while (!q.isEmpty()) {
            TreeNode node = q.poll();
            if (node != null) {
                ans.add(node.val + "");
                q.offer(node.left);
                q.offer(node.right);
            } else {
                ans.add("#");
            }
        }
        return String.join(",", ans);
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        if (data == null) {
            return null;
        }
        String[] vals = data.split(",");
        int i = 0;
        TreeNode root = new TreeNode(Integer.valueOf(vals[i++]));
        Deque<TreeNode> q = new ArrayDeque<>();
        q.offer(root);
        while (!q.isEmpty()) {
            TreeNode node = q.poll();
            if (!"#".equals(vals[i])) {
                node.left = new TreeNode(Integer.valueOf(vals[i]));
                q.offer(node.left);
            }
            ++i;
            if (!"#".equals(vals[i])) {
                node.right = new TreeNode(Integer.valueOf(vals[i]));
                q.offer(node.right);
            }
            ++i;
        }
        return root;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.deserialize(codec.serialize(root));
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) {
            return "";
        }
        queue<TreeNode*> q{{root}};
        string ans;
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            if (node) {
                ans += to_string(node->val) + " ";
                q.push(node->left);
                q.push(node->right);
            } else {
                ans += "# ";
            }
        }
        ans.pop_back();
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "") {
            return nullptr;
        }
        stringstream ss(data);
        string t;
        ss >> t;
        TreeNode* root = new TreeNode(stoi(t));
        queue<TreeNode*> q{{root}};
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            ss >> t;
            if (t != "#") {
                node->left = new TreeNode(stoi(t));
                q.push(node->left);
            }
            ss >> t;
            if (t != "#") {
                node->right = new TreeNode(stoi(t));
                q.push(node->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
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

type Codec struct {
}

func Constructor() Codec {
	return Codec{}
}

// Serializes a tree to a single string.
func (this *Codec) serialize(root *TreeNode) string {
	if root == nil {
		return ""
	}
	q := []*TreeNode{root}
	ans := []string{}
	for len(q) > 0 {
		node := q[0]
		q = q[1:]
		if node != nil {
			ans = append(ans, strconv.Itoa(node.Val))
			q = append(q, node.Left)
			q = append(q, node.Right)
		} else {
			ans = append(ans, "#")
		}
	}
	return strings.Join(ans, ",")
}

// Deserializes your encoded data to tree.
func (this *Codec) deserialize(data string) *TreeNode {
	if data == "" {
		return nil
	}
	vals := strings.Split(data, ",")
	v, _ := strconv.Atoi(vals[0])
	i := 1
	root := &TreeNode{Val: v}
	q := []*TreeNode{root}
	for len(q) > 0 {
		node := q[0]
		q = q[1:]
		if x, err := strconv.Atoi(vals[i]); err == nil {
			node.Left = &TreeNode{Val: x}
			q = append(q, node.Left)
		}
		i++
		if x, err := strconv.Atoi(vals[i]); err == nil {
			node.Right = &TreeNode{Val: x}
			q = append(q, node.Right)
		}
		i++
	}
	return root
}

/**
 * Your Codec object will be instantiated and called as such:
 * ser := Constructor();
 * deser := Constructor();
 * data := ser.serialize(root);
 * ans := deser.deserialize(data);
 */
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */

/**
 * Encodes a tree to a single string.
 *
 * @param {TreeNode} root
 * @return {string}
 */
var serialize = function (root) {
    if (root === null) {
        return null;
    }
    const ans = [];
    const q = [root];
    let index = 0;
    while (index < q.length) {
        const node = q[index++];
        if (node !== null) {
            ans.push(node.val.toString());
            q.push(node.left);
            q.push(node.right);
        } else {
            ans.push('#');
        }
    }
    return ans.join(',');
};

/**
 * Decodes your encoded data to tree.
 *
 * @param {string} data
 * @return {TreeNode}
 */
var deserialize = function (data) {
    if (data === null) {
        return null;
    }
    const vals = data.split(',');
    let i = 0;
    const root = new TreeNode(parseInt(vals[i++]));
    const q = [root];
    let index = 0;
    while (index < q.length) {
        const node = q[index++];
        if (vals[i] !== '#') {
            node.left = new TreeNode(+vals[i]);
            q.push(node.left);
        }
        i++;
        if (vals[i] !== '#') {
            node.right = new TreeNode(+vals[i]);
            q.push(node.right);
        }
        i++;
    }
    return root;
};

/**
 * Your functions will be called as such:
 * deserialize(serialize(root));
 */
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int x) { val = x; }
 * }
 */
public class Codec {

    // Encodes a tree to a single string.
    public string serialize(TreeNode root) {
        if (root == null) {
            return null;
        }
        List<string> ans = new List<string>();
        Queue<TreeNode> q = new Queue<TreeNode>();
        q.Enqueue(root);
        while (q.Count > 0) {
            TreeNode node = q.Dequeue();
            if (node != null) {
                ans.Add(node.val.ToString());
                q.Enqueue(node.left);
                q.Enqueue(node.right);
            } else {
                ans.Add("#");
            }
        }
        return string.Join(",", ans);
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(string data) {
        if (data == null) {
            return null;
        }
        string[] vals = data.Split(',');
        int i = 0;
        TreeNode root = new TreeNode(int.Parse(vals[i++]));
        Queue<TreeNode> q = new Queue<TreeNode>();
        q.Enqueue(root);
        while (q.Count > 0) {
            TreeNode node = q.Dequeue();
            if (vals[i] != "#") {
                node.left = new TreeNode(int.Parse(vals[i]));
                q.Enqueue(node.left);
            }
            i++;
            if (vals[i] != "#") {
                node.right = new TreeNode(int.Parse(vals[i]));
                q.Enqueue(node.right);
            }
            i++;
        }
        return root;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.deserialize(codec.serialize(root));
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。</p>

<p>请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。</p>

<p><strong>提示: </strong>输入输出格式与 LeetCode 目前使用的方式一致，详情请参阅&nbsp;<a href="https://support.leetcode.cn/hc/kb/article/1567641/">LeetCode 序列化二叉树的格式</a>。你并非必须采取这种方式，你也可以采用其他的方法解决这个问题。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0200-0299/0297.Serialize%20and%20Deserialize%20Binary%20Tree/images/serdeser.jpg" style="width: 442px; height: 324px;" />
<pre>
<strong>输入：</strong>root = [1,2,3,null,null,4,5]
<strong>输出：</strong>[1,2,3,null,null,4,5]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>root = []
<strong>输出：</strong>[]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>root = [1]
<strong>输出：</strong>[1]
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>root = [1,2]
<strong>输出：</strong>[1,2]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中结点数在范围 <code>[0, 10<sup>4</sup>]</code> 内</li>
	<li><code>-1000 &lt;= Node.val &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：层序遍历

我们可以采用层序遍历的方式对二叉树进行序列化，即从根节点开始，依次将二叉树的节点按照从上到下、从左到右的顺序加入队列中，然后将队列中的节点依次出队。如果节点不为空，则将其值加入序列化字符串中，否则加入特殊字符 `#`。最后将序列化字符串返回即可。

反序列化时，我们将序列化字符串按照分隔符进行切分，得到一个字符串数组，然后依次将字符串数组中的元素加入队列中。队列中的元素即为二叉树的节点，我们从队列中依次取出元素，如果元素不为 `#`，则将其转换为整数后作为节点的值，然后将该节点加入队列中，否则将其置为 `null`。最后返回根节点即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为二叉树的节点个数。

<!-- tabs:start -->

#### Python3

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Codec:
    def serialize(self, root):
        """Encodes a tree to a single string.

        :type root: TreeNode
        :rtype: str
        """
        if root is None:
            return ""
        q = deque([root])
        ans = []
        while q:
            node = q.popleft()
            if node:
                ans.append(str(node.val))
                q.append(node.left)
                q.append(node.right)
            else:
                ans.append("#")
        return ",".join(ans)

    def deserialize(self, data):
        """Decodes your encoded data to tree.

        :type data: str
        :rtype: TreeNode
        """
        if not data:
            return None
        vals = data.split(",")
        root = TreeNode(int(vals[0]))
        q = deque([root])
        i = 1
        while q:
            node = q.popleft()
            if vals[i] != "#":
                node.left = TreeNode(int(vals[i]))
                q.append(node.left)
            i += 1
            if vals[i] != "#":
                node.right = TreeNode(int(vals[i]))
                q.append(node.right)
            i += 1
        return root


# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))
```

#### Java

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Codec {

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        if (root == null) {
            return null;
        }
        List<String> ans = new ArrayList<>();
        Deque<TreeNode> q = new LinkedList<>();
        q.offer(root);
        while (!q.isEmpty()) {
            TreeNode node = q.poll();
            if (node != null) {
                ans.add(node.val + "");
                q.offer(node.left);
                q.offer(node.right);
            } else {
                ans.add("#");
            }
        }
        return String.join(",", ans);
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        if (data == null) {
            return null;
        }
        String[] vals = data.split(",");
        int i = 0;
        TreeNode root = new TreeNode(Integer.valueOf(vals[i++]));
        Deque<TreeNode> q = new ArrayDeque<>();
        q.offer(root);
        while (!q.isEmpty()) {
            TreeNode node = q.poll();
            if (!"#".equals(vals[i])) {
                node.left = new TreeNode(Integer.valueOf(vals[i]));
                q.offer(node.left);
            }
            ++i;
            if (!"#".equals(vals[i])) {
                node.right = new TreeNode(Integer.valueOf(vals[i]));
                q.offer(node.right);
            }
            ++i;
        }
        return root;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.deserialize(codec.serialize(root));
```

#### C++

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) {
            return "";
        }
        queue<TreeNode*> q{{root}};
        string ans;
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            if (node) {
                ans += to_string(node->val) + " ";
                q.push(node->left);
                q.push(node->right);
            } else {
                ans += "# ";
            }
        }
        ans.pop_back();
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "") {
            return nullptr;
        }
        stringstream ss(data);
        string t;
        ss >> t;
        TreeNode* root = new TreeNode(stoi(t));
        queue<TreeNode*> q{{root}};
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            ss >> t;
            if (t != "#") {
                node->left = new TreeNode(stoi(t));
                q.push(node->left);
            }
            ss >> t;
            if (t != "#") {
                node->right = new TreeNode(stoi(t));
                q.push(node->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
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

type Codec struct {
}

func Constructor() Codec {
	return Codec{}
}

// Serializes a tree to a single string.
func (this *Codec) serialize(root *TreeNode) string {
	if root == nil {
		return ""
	}
	q := []*TreeNode{root}
	ans := []string{}
	for len(q) > 0 {
		node := q[0]
		q = q[1:]
		if node != nil {
			ans = append(ans, strconv.Itoa(node.Val))
			q = append(q, node.Left)
			q = append(q, node.Right)
		} else {
			ans = append(ans, "#")
		}
	}
	return strings.Join(ans, ",")
}

// Deserializes your encoded data to tree.
func (this *Codec) deserialize(data string) *TreeNode {
	if data == "" {
		return nil
	}
	vals := strings.Split(data, ",")
	v, _ := strconv.Atoi(vals[0])
	i := 1
	root := &TreeNode{Val: v}
	q := []*TreeNode{root}
	for len(q) > 0 {
		node := q[0]
		q = q[1:]
		if x, err := strconv.Atoi(vals[i]); err == nil {
			node.Left = &TreeNode{Val: x}
			q = append(q, node.Left)
		}
		i++
		if x, err := strconv.Atoi(vals[i]); err == nil {
			node.Right = &TreeNode{Val: x}
			q = append(q, node.Right)
		}
		i++
	}
	return root
}

/**
 * Your Codec object will be instantiated and called as such:
 * ser := Constructor();
 * deser := Constructor();
 * data := ser.serialize(root);
 * ans := deser.deserialize(data);
 */
```

#### JavaScript

```js
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */

/**
 * Encodes a tree to a single string.
 *
 * @param {TreeNode} root
 * @return {string}
 */
var serialize = function (root) {
    if (root === null) {
        return null;
    }
    const ans = [];
    const q = [root];
    let index = 0;
    while (index < q.length) {
        const node = q[index++];
        if (node !== null) {
            ans.push(node.val.toString());
            q.push(node.left);
            q.push(node.right);
        } else {
            ans.push('#');
        }
    }
    return ans.join(',');
};

/**
 * Decodes your encoded data to tree.
 *
 * @param {string} data
 * @return {TreeNode}
 */
var deserialize = function (data) {
    if (data === null) {
        return null;
    }
    const vals = data.split(',');
    let i = 0;
    const root = new TreeNode(parseInt(vals[i++]));
    const q = [root];
    let index = 0;
    while (index < q.length) {
        const node = q[index++];
        if (vals[i] !== '#') {
            node.left = new TreeNode(+vals[i]);
            q.push(node.left);
        }
        i++;
        if (vals[i] !== '#') {
            node.right = new TreeNode(+vals[i]);
            q.push(node.right);
        }
        i++;
    }
    return root;
};

/**
 * Your functions will be called as such:
 * deserialize(serialize(root));
 */
```

#### C#

```cs
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int x) { val = x; }
 * }
 */
public class Codec {

    // Encodes a tree to a single string.
    public string serialize(TreeNode root) {
        if (root == null) {
            return null;
        }
        List<string> ans = new List<string>();
        Queue<TreeNode> q = new Queue<TreeNode>();
        q.Enqueue(root);
        while (q.Count > 0) {
            TreeNode node = q.Dequeue();
            if (node != null) {
                ans.Add(node.val.ToString());
                q.Enqueue(node.left);
                q.Enqueue(node.right);
            } else {
                ans.Add("#");
            }
        }
        return string.Join(",", ans);
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(string data) {
        if (data == null) {
            return null;
        }
        string[] vals = data.Split(',');
        int i = 0;
        TreeNode root = new TreeNode(int.Parse(vals[i++]));
        Queue<TreeNode> q = new Queue<TreeNode>();
        q.Enqueue(root);
        while (q.Count > 0) {
            TreeNode node = q.Dequeue();
            if (vals[i] != "#") {
                node.left = new TreeNode(int.Parse(vals[i]));
                q.Enqueue(node.left);
            }
            i++;
            if (vals[i] != "#") {
                node.right = new TreeNode(int.Parse(vals[i]));
                q.Enqueue(node.right);
            }
            i++;
        }
        return root;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.deserialize(codec.serialize(root));
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [298. 二叉树最长连续序列 🔒](https://leetcode.cn/problems/binary-tree-longest-consecutive-sequence){#298}

{{< tabs "298" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def longestConsecutive(self, root: Optional[TreeNode]) -> int:
        def dfs(root: Optional[TreeNode]) -> int:
            if root is None:
                return 0
            l = dfs(root.left) + 1
            r = dfs(root.right) + 1
            if root.left and root.left.val - root.val != 1:
                l = 1
            if root.right and root.right.val - root.val != 1:
                r = 1
            t = max(l, r)
            nonlocal ans
            ans = max(ans, t)
            return t

        ans = 0
        dfs(root)
        return ans
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
    private int ans;

    public int longestConsecutive(TreeNode root) {
        dfs(root);
        return ans;
    }

    private int dfs(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int l = dfs(root.left) + 1;
        int r = dfs(root.right) + 1;
        if (root.left != null && root.left.val - root.val != 1) {
            l = 1;
        }
        if (root.right != null && root.right.val - root.val != 1) {
            r = 1;
        }
        int t = Math.max(l, r);
        ans = Math.max(ans, t);
        return t;
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
    int longestConsecutive(TreeNode* root) {
        int ans = 0;
        function<int(TreeNode*)> dfs = [&](TreeNode* root) {
            if (!root) {
                return 0;
            }
            int l = dfs(root->left) + 1;
            int r = dfs(root->right) + 1;
            if (root->left && root->left->val - root->val != 1) {
                l = 1;
            }
            if (root->right && root->right->val - root->val != 1) {
                r = 1;
            }
            int t = max(l, r);
            ans = max(ans, t);
            return t;
        };
        dfs(root);
        return ans;
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
func longestConsecutive(root *TreeNode) (ans int) {
	var dfs func(*TreeNode) int
	dfs = func(root *TreeNode) int {
		if root == nil {
			return 0
		}
		l := dfs(root.Left) + 1
		r := dfs(root.Right) + 1
		if root.Left != nil && root.Left.Val-root.Val != 1 {
			l = 1
		}
		if root.Right != nil && root.Right.Val-root.Val != 1 {
			r = 1
		}
		t := max(l, r)
		ans = max(ans, t)
		return t
	}
	dfs(root)
	return
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

function longestConsecutive(root: TreeNode | null): number {
    let ans = 0;
    const dfs = (root: TreeNode | null): number => {
        if (root === null) {
            return 0;
        }
        let l = dfs(root.left) + 1;
        let r = dfs(root.right) + 1;
        if (root.left && root.left.val - root.val !== 1) {
            l = 1;
        }
        if (root.right && root.right.val - root.val !== 1) {
            r = 1;
        }
        const t = Math.max(l, r);
        ans = Math.max(ans, t);
        return t;
    };
    dfs(root);
    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一棵指定的二叉树的根节点 <code>root</code> ，请你计算其中 <strong>最长连续序列路径</strong> 的长度。</p>

<p><strong>最长连续序列路径</strong> 是依次递增 1 的路径。该路径，可以是从某个初始节点到树中任意节点，通过「父 - 子」关系连接而产生的任意路径。且必须从父节点到子节点，反过来是不可以的。</p>
&nbsp;

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0200-0299/0298.Binary%20Tree%20Longest%20Consecutive%20Sequence/images/consec1-1-tree.jpg" style="width: 306px; height: 400px;" />
<pre>
<strong>输入：</strong>root = [1,null,3,2,4,null,null,null,5]
<strong>输出：</strong>3
<strong>解释：</strong>当中，最长连续序列是 <code>3-4-5 ，所以</code>返回结果为 <code>3 。</code>
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0200-0299/0298.Binary%20Tree%20Longest%20Consecutive%20Sequence/images/consec1-2-tree.jpg" style="width: 249px; height: 400px;" />
<pre>
<strong>输入：</strong>root = [2,null,3,2,null,1]
<strong>输出：</strong>2
<strong>解释：</strong>当中，最长连续序列是 <code>2-3 。注意，不是</code> <code>3-2-1，所以</code>返回 <code>2 。</code>
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点的数目在范围 <code>[1, 3 * 10<sup>4</sup>]</code> 内</li>
	<li><code>-3 * 10<sup>4</sup> &lt;= Node.val &lt;= 3 * 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS

我们设计一个函数 $dfs(root)$，表示以 $root$ 为连续序列的第一个节点的最长连续序列路径长度。

函数 $dfs(root)$ 的执行过程如下：

如果 $root$ 为空，那么返回 $0$。

否则，我们递归计算 $root$ 的左右子节点，分别得到 $l$ 和 $r$，如果 $root$ 的左子节点和 $root$ 连续，那么 $l$ 的值加 $1$，否则置 $l$ 为 $1$；如果 $root$ 的右子节点和 $root$ 连续，那么 $r$ 的值加 $1$，否则置 $r$ 为 $1$。

然后我们更新答案为 $ans = \max(ans, l, r)$，并返回 $\max(l, r)$。

最后，我们调用 $dfs(root)$，返回答案 $ans$。

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
    def longestConsecutive(self, root: Optional[TreeNode]) -> int:
        def dfs(root: Optional[TreeNode]) -> int:
            if root is None:
                return 0
            l = dfs(root.left) + 1
            r = dfs(root.right) + 1
            if root.left and root.left.val - root.val != 1:
                l = 1
            if root.right and root.right.val - root.val != 1:
                r = 1
            t = max(l, r)
            nonlocal ans
            ans = max(ans, t)
            return t

        ans = 0
        dfs(root)
        return ans
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
    private int ans;

    public int longestConsecutive(TreeNode root) {
        dfs(root);
        return ans;
    }

    private int dfs(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int l = dfs(root.left) + 1;
        int r = dfs(root.right) + 1;
        if (root.left != null && root.left.val - root.val != 1) {
            l = 1;
        }
        if (root.right != null && root.right.val - root.val != 1) {
            r = 1;
        }
        int t = Math.max(l, r);
        ans = Math.max(ans, t);
        return t;
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
    int longestConsecutive(TreeNode* root) {
        int ans = 0;
        function<int(TreeNode*)> dfs = [&](TreeNode* root) {
            if (!root) {
                return 0;
            }
            int l = dfs(root->left) + 1;
            int r = dfs(root->right) + 1;
            if (root->left && root->left->val - root->val != 1) {
                l = 1;
            }
            if (root->right && root->right->val - root->val != 1) {
                r = 1;
            }
            int t = max(l, r);
            ans = max(ans, t);
            return t;
        };
        dfs(root);
        return ans;
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
func longestConsecutive(root *TreeNode) (ans int) {
	var dfs func(*TreeNode) int
	dfs = func(root *TreeNode) int {
		if root == nil {
			return 0
		}
		l := dfs(root.Left) + 1
		r := dfs(root.Right) + 1
		if root.Left != nil && root.Left.Val-root.Val != 1 {
			l = 1
		}
		if root.Right != nil && root.Right.Val-root.Val != 1 {
			r = 1
		}
		t := max(l, r)
		ans = max(ans, t)
		return t
	}
	dfs(root)
	return
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

function longestConsecutive(root: TreeNode | null): number {
    let ans = 0;
    const dfs = (root: TreeNode | null): number => {
        if (root === null) {
            return 0;
        }
        let l = dfs(root.left) + 1;
        let r = dfs(root.right) + 1;
        if (root.left && root.left.val - root.val !== 1) {
            l = 1;
        }
        if (root.right && root.right.val - root.val !== 1) {
            r = 1;
        }
        const t = Math.max(l, r);
        ans = Math.max(ans, t);
        return t;
    };
    dfs(root);
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [299. 猜数字游戏](https://leetcode.cn/problems/bulls-and-cows){#299}

{{< tabs "299" >}}

{{% tab "python" %}}
```python
class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        cnt1, cnt2 = Counter(), Counter()
        x = 0
        for a, b in zip(secret, guess):
            if a == b:
                x += 1
            else:
                cnt1[a] += 1
                cnt2[b] += 1
        y = sum(min(cnt1[c], cnt2[c]) for c in cnt1)
        return f"{x}A{y}B"
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String getHint(String secret, String guess) {
        int x = 0, y = 0;
        int[] cnt1 = new int[10];
        int[] cnt2 = new int[10];
        for (int i = 0; i < secret.length(); ++i) {
            int a = secret.charAt(i) - '0', b = guess.charAt(i) - '0';
            if (a == b) {
                ++x;
            } else {
                ++cnt1[a];
                ++cnt2[b];
            }
        }
        for (int i = 0; i < 10; ++i) {
            y += Math.min(cnt1[i], cnt2[i]);
        }
        return String.format("%dA%dB", x, y);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string getHint(string secret, string guess) {
        int x = 0, y = 0;
        int cnt1[10]{};
        int cnt2[10]{};
        for (int i = 0; i < secret.size(); ++i) {
            int a = secret[i] - '0', b = guess[i] - '0';
            if (a == b) {
                ++x;
            } else {
                ++cnt1[a];
                ++cnt2[b];
            }
        }
        for (int i = 0; i < 10; ++i) {
            y += min(cnt1[i], cnt2[i]);
        }
        return to_string(x) + "A" + to_string(y) + "B";
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func getHint(secret string, guess string) string {
	x, y := 0, 0
	cnt1 := [10]int{}
	cnt2 := [10]int{}
	for i, c := range secret {
		a, b := int(c-'0'), int(guess[i]-'0')
		if a == b {
			x++
		} else {
			cnt1[a]++
			cnt2[b]++
		}
	}
	for i, c := range cnt1 {
		y += min(c, cnt2[i])

	}
	return fmt.Sprintf("%dA%dB", x, y)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function getHint(secret: string, guess: string): string {
    const cnt1: number[] = Array(10).fill(0);
    const cnt2: number[] = Array(10).fill(0);
    let x: number = 0;
    for (let i = 0; i < secret.length; ++i) {
        if (secret[i] === guess[i]) {
            ++x;
        } else {
            ++cnt1[+secret[i]];
            ++cnt2[+guess[i]];
        }
    }
    let y: number = 0;
    for (let i = 0; i < 10; ++i) {
        y += Math.min(cnt1[i], cnt2[i]);
    }
    return `${x}A${y}B`;
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param String $secret
     * @param String $guess
     * @return String
     */
    function getHint($secret, $guess) {
        $cnt1 = array_fill(0, 10, 0);
        $cnt2 = array_fill(0, 10, 0);
        $x = 0;
        for ($i = 0; $i < strlen($secret); ++$i) {
            if ($secret[$i] === $guess[$i]) {
                ++$x;
            } else {
                ++$cnt1[(int) $secret[$i]];
                ++$cnt2[(int) $guess[$i]];
            }
        }
        $y = 0;
        for ($i = 0; $i < 10; ++$i) {
            $y += min($cnt1[$i], $cnt2[$i]);
        }
        return "{$x}A{$y}B";
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你在和朋友一起玩 <a href="https://baike.baidu.com/item/%E7%8C%9C%E6%95%B0%E5%AD%97/83200?fromtitle=Bulls+and+Cows&amp;fromid=12003488&amp;fr=aladdin" target="_blank">猜数字（Bulls and Cows）</a>游戏，该游戏规则如下：</p>

<p>写出一个秘密数字，并请朋友猜这个数字是多少。朋友每猜测一次，你就会给他一个包含下述信息的提示：</p>

<ul>
	<li>猜测数字中有多少位属于数字和确切位置都猜对了（称为 "Bulls"，公牛），</li>
	<li>有多少位属于数字猜对了但是位置不对（称为 "Cows"，奶牛）。也就是说，这次猜测中有多少位非公牛数字可以通过重新排列转换成公牛数字。</li>
</ul>

<p>给你一个秘密数字&nbsp;<code>secret</code> 和朋友猜测的数字&nbsp;<code>guess</code> ，请你返回对朋友这次猜测的提示。</p>

<p>提示的格式为 <code>"xAyB"</code> ，<code>x</code> 是公牛个数， <code>y</code> 是奶牛个数，<code>A</code> 表示公牛，<code>B</code>&nbsp;表示奶牛。</p>

<p>请注意秘密数字和朋友猜测的数字都可能含有重复数字。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>secret = "1807", guess = "7810"
<strong>输出：</strong>"1A3B"
<strong>解释：</strong>数字和位置都对（公牛）用 '|' 连接，数字猜对位置不对（奶牛）的采用斜体加粗标识。
"1807"
  |
"<em><strong>7</strong></em>8<em><strong>10</strong></em>"</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>secret = "1123", guess = "0111"
<strong>输出：</strong>"1A1B"
<strong>解释：</strong>数字和位置都对（公牛）用 '|' 连接，数字猜对位置不对（奶牛）的采用斜体加粗标识。
"1123"        "1123"
  |      or     |
"01<em><strong>1</strong></em>1"        "011<em><strong>1</strong></em>"
注意，两个不匹配的 1 中，只有一个会算作奶牛（数字猜对位置不对）。通过重新排列非公牛数字，其中仅有一个 1 可以成为公牛数字。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= secret.length, guess.length &lt;= 1000</code></li>
	<li><code>secret.length == guess.length</code></li>
	<li><code>secret</code> 和 <code>guess</code> 仅由数字组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数

我们创建两个计数器 $cnt1$ 和 $cnt2$，分别用来统计秘密数字和朋友猜测的数字中每个数字出现的次数。同时，我们创建一个变量 $x$ 来统计公牛的数量。

然后我们遍历秘密数字和朋友猜测的数字，如果当前数字相同，我们就将 $x$ 加一。否则，我们分别将秘密数字和朋友猜测的数字中的当前数字的计数加一。

最后，我们遍历 $cnt1$ 中的每个数字，取 $cnt1$ 和 $cnt2$ 中当前数字的计数的最小值，然后将这个最小值加到变量 $y$ 中。

最后，我们返回 $x$ 和 $y$ 的值。

时间复杂度 $O(n)$，其中 $n$ 是秘密数字和朋友猜测的数字的长度。空间复杂度 $O(|\Sigma|)$，其中 $|\Sigma|$ 是字符集的大小，本题中字符集为数字，所以 $|\Sigma| = 10$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        cnt1, cnt2 = Counter(), Counter()
        x = 0
        for a, b in zip(secret, guess):
            if a == b:
                x += 1
            else:
                cnt1[a] += 1
                cnt2[b] += 1
        y = sum(min(cnt1[c], cnt2[c]) for c in cnt1)
        return f"{x}A{y}B"
```

#### Java

```java
class Solution {
    public String getHint(String secret, String guess) {
        int x = 0, y = 0;
        int[] cnt1 = new int[10];
        int[] cnt2 = new int[10];
        for (int i = 0; i < secret.length(); ++i) {
            int a = secret.charAt(i) - '0', b = guess.charAt(i) - '0';
            if (a == b) {
                ++x;
            } else {
                ++cnt1[a];
                ++cnt2[b];
            }
        }
        for (int i = 0; i < 10; ++i) {
            y += Math.min(cnt1[i], cnt2[i]);
        }
        return String.format("%dA%dB", x, y);
    }
}
```

#### C++

```cpp
class Solution {
public:
    string getHint(string secret, string guess) {
        int x = 0, y = 0;
        int cnt1[10]{};
        int cnt2[10]{};
        for (int i = 0; i < secret.size(); ++i) {
            int a = secret[i] - '0', b = guess[i] - '0';
            if (a == b) {
                ++x;
            } else {
                ++cnt1[a];
                ++cnt2[b];
            }
        }
        for (int i = 0; i < 10; ++i) {
            y += min(cnt1[i], cnt2[i]);
        }
        return to_string(x) + "A" + to_string(y) + "B";
    }
};
```

#### Go

```go
func getHint(secret string, guess string) string {
	x, y := 0, 0
	cnt1 := [10]int{}
	cnt2 := [10]int{}
	for i, c := range secret {
		a, b := int(c-'0'), int(guess[i]-'0')
		if a == b {
			x++
		} else {
			cnt1[a]++
			cnt2[b]++
		}
	}
	for i, c := range cnt1 {
		y += min(c, cnt2[i])

	}
	return fmt.Sprintf("%dA%dB", x, y)
}
```

#### TypeScript

```ts
function getHint(secret: string, guess: string): string {
    const cnt1: number[] = Array(10).fill(0);
    const cnt2: number[] = Array(10).fill(0);
    let x: number = 0;
    for (let i = 0; i < secret.length; ++i) {
        if (secret[i] === guess[i]) {
            ++x;
        } else {
            ++cnt1[+secret[i]];
            ++cnt2[+guess[i]];
        }
    }
    let y: number = 0;
    for (let i = 0; i < 10; ++i) {
        y += Math.min(cnt1[i], cnt2[i]);
    }
    return `${x}A${y}B`;
}
```

#### PHP

```php
class Solution {
    /**
     * @param String $secret
     * @param String $guess
     * @return String
     */
    function getHint($secret, $guess) {
        $cnt1 = array_fill(0, 10, 0);
        $cnt2 = array_fill(0, 10, 0);
        $x = 0;
        for ($i = 0; $i < strlen($secret); ++$i) {
            if ($secret[$i] === $guess[$i]) {
                ++$x;
            } else {
                ++$cnt1[(int) $secret[$i]];
                ++$cnt2[(int) $guess[$i]];
            }
        }
        $y = 0;
        for ($i = 0; $i < 10; ++$i) {
            $y += min($cnt1[$i], $cnt2[$i]);
        }
        return "{$x}A{$y}B";
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
