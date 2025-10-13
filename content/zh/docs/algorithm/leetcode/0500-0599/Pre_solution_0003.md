---
title: "0520_检测大写字母"
date: 2025-10-08T18:36:17+08:00
weight: 3
tags: [二分查找, 位运算, 前缀和, 动态规划, 双指针, 哈希表, 回溯, 字典树, 字符串, 广度优先搜索, 排序, 数学, 数组, 深度优先搜索, 状态压缩, 矩阵, 贪心, 随机化]
---

{{< markmap >}}
### [0520_检测大写字母](#520)
#### [字符串](#520)
### [0521_最长特殊序列 Ⅰ](#521)
#### [字符串](#521)
### [0522_最长特殊序列 II](#522)
#### [数组](#522)
#### [哈希表](#522)
#### [双指针](#522)
#### [字符串](#522)
#### [排序](#522)
### [0523_连续的子数组和](#523)
#### [数组](#523)
#### [哈希表](#523)
#### [数学](#523)
#### [前缀和](#523)
### [0524_通过删除字母匹配到字典里最长单词](#524)
#### [数组](#524)
#### [双指针](#524)
#### [字符串](#524)
#### [排序](#524)
### [0525_连续数组](#525)
#### [数组](#525)
#### [哈希表](#525)
#### [前缀和](#525)
### [0526_优美的排列](#526)
#### [位运算](#526)
#### [数组](#526)
#### [动态规划](#526)
#### [回溯](#526)
#### [状态压缩](#526)
### [0527_单词缩写 🔒](#527)
#### [贪心](#527)
#### [字典树](#527)
#### [数组](#527)
#### [字符串](#527)
#### [排序](#527)
### [0528_按权重随机选择](#528)
#### [数组](#528)
#### [数学](#528)
#### [二分查找](#528)
#### [前缀和](#528)
#### [随机化](#528)
### [0529_扫雷游戏](#529)
#### [深度优先搜索](#529)
#### [广度优先搜索](#529)
#### [数组](#529)
#### [矩阵](#529)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0520_检测大写字母
___
#### 字符串
---
### 0521_最长特殊序列 Ⅰ
___
#### 字符串
---
### 0522_最长特殊序列 II
___
#### 数组
___
#### 哈希表
___
#### 双指针
___
#### 字符串
___
#### 排序
---
### 0523_连续的子数组和
___
#### 数组
___
#### 哈希表
___
#### 数学
___
#### 前缀和
---
### 0524_通过删除字母匹配到字典里最长单词
___
#### 数组
___
#### 双指针
___
#### 字符串
___
#### 排序
---
### 0525_连续数组
___
#### 数组
___
#### 哈希表
___
#### 前缀和
---
### 0526_优美的排列
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
### 0527_单词缩写 🔒
___
#### 贪心
___
#### 字典树
___
#### 数组
___
#### 字符串
___
#### 排序
---
### 0528_按权重随机选择
___
#### 数组
___
#### 数学
___
#### 二分查找
___
#### 前缀和
___
#### 随机化
---
### 0529_扫雷游戏
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 数组
___
#### 矩阵
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 位运算 | 前缀和 |
| 动态规划 | 双指针 | 哈希表 |
| 回溯 | 字典树 | 字符串 |
| 广度优先搜索 | 排序 | 数学 |
| 数组 | 深度优先搜索 | 状态压缩 |
| 矩阵 | 贪心 | 随机化 |

# [520. 检测大写字母](https://leetcode.cn/problems/detect-capital){#520}

{{< tabs "520" >}}

{{% tab "python" %}}
```python
class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        cnt = sum(c.isupper() for c in word)
        return cnt == 0 or cnt == len(word) or (cnt == 1 and word[0].isupper())
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean detectCapitalUse(String word) {
        int cnt = 0;
        for (char c : word.toCharArray()) {
            if (Character.isUpperCase(c)) {
                ++cnt;
            }
        }
        return cnt == 0 || cnt == word.length()
            || (cnt == 1 && Character.isUpperCase(word.charAt(0)));
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool detectCapitalUse(string word) {
        int cnt = count_if(word.begin(), word.end(), [](char c) { return isupper(c); });
        return cnt == 0 || cnt == word.length() || (cnt == 1 && isupper(word[0]));
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func detectCapitalUse(word string) bool {
	cnt := 0
	for _, c := range word {
		if unicode.IsUpper(c) {
			cnt++
		}
	}
	return cnt == 0 || cnt == len(word) || (cnt == 1 && unicode.IsUpper(rune(word[0])))
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function detectCapitalUse(word: string): boolean {
    const cnt = word.split('').reduce((acc, c) => acc + (c === c.toUpperCase() ? 1 : 0), 0);
    return cnt === 0 || cnt === word.length || (cnt === 1 && word[0] === word[0].toUpperCase());
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>我们定义，在以下情况时，单词的大写用法是正确的：</p>

<ul>
	<li>全部字母都是大写，比如 <code>"USA"</code> 。</li>
	<li>所有字母都不是大写，比如 <code>"leetcode"</code> 。</li>
	<li>只有首字母大写，&nbsp;比如&nbsp;<code>"Google"</code> 。</li>
</ul>

<p>给你一个字符串 <code>word</code> 。如果大写用法正确，返回 <code>true</code> ；否则，返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>word = "USA"
<strong>输出：</strong>true
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>word = "FlaG"
<strong>输出：</strong>false
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= word.length &lt;= 100</code></li>
	<li><code>word</code> 由小写和大写英文字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：统计大写字母的个数

我们可以统计字符串中大写字母的个数，然后根据大写字母的个数判断是否符合题目要求。

-   如果大写字母的个数为 0 或者等于字符串的长度，那么返回 `true`。
-   如果大写字母的个数为 1 并且第一个字母是大写字母，那么返回 `true`。
-   否则返回 `false`。

时间复杂度 $O(n)$，其中 $n$ 为字符串 `word` 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        cnt = sum(c.isupper() for c in word)
        return cnt == 0 or cnt == len(word) or (cnt == 1 and word[0].isupper())
```

#### Java

```java
class Solution {
    public boolean detectCapitalUse(String word) {
        int cnt = 0;
        for (char c : word.toCharArray()) {
            if (Character.isUpperCase(c)) {
                ++cnt;
            }
        }
        return cnt == 0 || cnt == word.length()
            || (cnt == 1 && Character.isUpperCase(word.charAt(0)));
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool detectCapitalUse(string word) {
        int cnt = count_if(word.begin(), word.end(), [](char c) { return isupper(c); });
        return cnt == 0 || cnt == word.length() || (cnt == 1 && isupper(word[0]));
    }
};
```

#### Go

```go
func detectCapitalUse(word string) bool {
	cnt := 0
	for _, c := range word {
		if unicode.IsUpper(c) {
			cnt++
		}
	}
	return cnt == 0 || cnt == len(word) || (cnt == 1 && unicode.IsUpper(rune(word[0])))
}
```

#### TypeScript

```ts
function detectCapitalUse(word: string): boolean {
    const cnt = word.split('').reduce((acc, c) => acc + (c === c.toUpperCase() ? 1 : 0), 0);
    return cnt === 0 || cnt === word.length || (cnt === 1 && word[0] === word[0].toUpperCase());
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [521. 最长特殊序列 Ⅰ](https://leetcode.cn/problems/longest-uncommon-subsequence-i){#521}

{{< tabs "521" >}}

{{% tab "python" %}}
```python
class Solution:
    def findLUSlength(self, a: str, b: str) -> int:
        return -1 if a == b else max(len(a), len(b))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int findLUSlength(String a, String b) {
        return a.equals(b) ? -1 : Math.max(a.length(), b.length());
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int findLUSlength(string a, string b) {
        return a == b ? -1 : max(a.size(), b.size());
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findLUSlength(a string, b string) int {
	if a == b {
		return -1
	}
	if len(a) > len(b) {
		return len(a)
	}
	return len(b)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findLUSlength(a: string, b: string): number {
    return a === b ? -1 : Math.max(a.length, b.length);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn find_lu_slength(a: String, b: String) -> i32 {
        if a == b {
            return -1;
        }
        a.len().max(b.len()) as i32
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个字符串&nbsp;<code>a</code>&nbsp;和&nbsp;<code>b</code>，请返回 <em>这两个字符串中 <strong>最长的特殊序列</strong>&nbsp;</em> 的长度。如果不存在，则返回 <code>-1</code>&nbsp;。</p>

<p><strong>「最长特殊序列」</strong>&nbsp;定义如下：该序列为&nbsp;<strong>某字符串独有的最长<span data-keyword="subsequence-array">子序列</span>（即不能是其他字符串的子序列）</strong>&nbsp;。</p>

<p>字符串&nbsp;<code>s</code>&nbsp;的子序列是在从&nbsp;<code>s</code>&nbsp;中删除任意数量的字符后可以获得的字符串。</p>

<ul>
	<li>例如，<code>"abc"</code> 是 <code>"aebdc"</code> 的子序列，因为删除 <code>"a<em><strong>e</strong></em>b<strong><em>d</em></strong>c"</code> 中斜体加粗的字符可以得到 <code>"abc"</code> 。 <code>"aebdc"</code> 的子序列还包括 <code>"aebdc"</code> 、 <code>"aeb"</code> 和 <code>""</code> (空字符串)。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入:</strong> a = "aba", b = "cdc"
<strong>输出:</strong> 3
<strong>解释:</strong> 最长特殊序列可为 "aba" (或 "cdc")，两者均为自身的子序列且不是对方的子序列。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>a = "aaa", b = "bbb"
<strong>输出：</strong>3
<strong>解释:</strong> 最长特殊序列是 "aaa" 和 "bbb" 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>a = "aaa", b = "aaa"
<strong>输出：</strong>-1
<strong>解释:</strong> 字符串 a 的每个子序列也是字符串 b 的每个子序列。同样，字符串 b 的每个子序列也是字符串 a 的子序列。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= a.length, b.length &lt;= 100</code></li>
	<li><code>a</code>&nbsp;和&nbsp;<code>b</code>&nbsp;由小写英文字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：脑筋急转弯

如果字符串 `a` 和 `b` 相等，那么它们没有特殊序列，返回 `-1`；否则，返回长度较长的字符串的长度。

时间复杂度 $O(n)$，其中 $n$ 为字符串 `a` 和 `b` 中较长的字符串的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findLUSlength(self, a: str, b: str) -> int:
        return -1 if a == b else max(len(a), len(b))
```

#### Java

```java
class Solution {
    public int findLUSlength(String a, String b) {
        return a.equals(b) ? -1 : Math.max(a.length(), b.length());
    }
}
```

#### C++

```cpp
class Solution {
public:
    int findLUSlength(string a, string b) {
        return a == b ? -1 : max(a.size(), b.size());
    }
};
```

#### Go

```go
func findLUSlength(a string, b string) int {
	if a == b {
		return -1
	}
	if len(a) > len(b) {
		return len(a)
	}
	return len(b)
}
```

#### TypeScript

```ts
function findLUSlength(a: string, b: string): number {
    return a === b ? -1 : Math.max(a.length, b.length);
}
```

#### Rust

```rust
impl Solution {
    pub fn find_lu_slength(a: String, b: String) -> i32 {
        if a == b {
            return -1;
        }
        a.len().max(b.len()) as i32
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [522. 最长特殊序列 II](https://leetcode.cn/problems/longest-uncommon-subsequence-ii){#522}

{{< tabs "522" >}}

{{% tab "python" %}}
```python
class Solution:
    def findLUSlength(self, strs: List[str]) -> int:
        def check(s: str, t: str):
            i = j = 0
            while i < len(s) and j < len(t):
                if s[i] == t[j]:
                    i += 1
                j += 1
            return i == len(s)

        ans = -1
        for i, s in enumerate(strs):
            for j, t in enumerate(strs):
                if i != j and check(s, t):
                    break
            else:
                ans = max(ans, len(s))
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int findLUSlength(String[] strs) {
        int ans = -1;
        int n = strs.length;
        for (int i = 0, j; i < n; ++i) {
            int x = strs[i].length();
            for (j = 0; j < n; ++j) {
                if (i != j && check(strs[i], strs[j])) {
                    x = -1;
                    break;
                }
            }
            ans = Math.max(ans, x);
        }
        return ans;
    }

    private boolean check(String s, String t) {
        int m = s.length(), n = t.length();
        int i = 0;
        for (int j = 0; i < m && j < n; ++j) {
            if (s.charAt(i) == t.charAt(j)) {
                ++i;
            }
        }
        return i == m;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        int ans = -1;
        int n = strs.size();
        auto check = [&](const string& s, const string& t) {
            int m = s.size(), n = t.size();
            int i = 0;
            for (int j = 0; i < m && j < n; ++j) {
                if (s[i] == t[j]) {
                    ++i;
                }
            }
            return i == m;
        };
        for (int i = 0, j; i < n; ++i) {
            int x = strs[i].size();
            for (j = 0; j < n; ++j) {
                if (i != j && check(strs[i], strs[j])) {
                    x = -1;
                    break;
                }
            }
            ans = max(ans, x);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findLUSlength(strs []string) int {
	ans := -1
	check := func(s, t string) bool {
		m, n := len(s), len(t)
		i := 0
		for j := 0; i < m && j < n; j++ {
			if s[i] == t[j] {
				i++
			}
		}
		return i == m
	}
	for i, s := range strs {
		x := len(s)
		for j, t := range strs {
			if i != j && check(s, t) {
				x = -1
				break
			}
		}
		ans = max(ans, x)
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findLUSlength(strs: string[]): number {
    const n = strs.length;
    let ans = -1;
    const check = (s: string, t: string): boolean => {
        const [m, n] = [s.length, t.length];
        let i = 0;
        for (let j = 0; i < m && j < n; ++j) {
            if (s[i] === t[j]) {
                ++i;
            }
        }
        return i === m;
    };
    for (let i = 0; i < n; ++i) {
        let x = strs[i].length;
        for (let j = 0; j < n; ++j) {
            if (i !== j && check(strs[i], strs[j])) {
                x = -1;
                break;
            }
        }
        ans = Math.max(ans, x);
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

<p>给定字符串列表&nbsp;<code>strs</code> ，返回其中 <strong>最长的特殊序列</strong>&nbsp;的长度。如果最长特殊序列不存在，返回 <code>-1</code> 。</p>

<p><strong>特殊序列</strong> 定义如下：该序列为某字符串 <strong>独有的子序列（即不能是其他字符串的子序列）</strong>。</p>

<p>&nbsp;<code>s</code>&nbsp;的&nbsp;<strong>子序列</strong>可以通过删去字符串&nbsp;<code>s</code>&nbsp;中的某些字符实现。</p>

<ul>
	<li>例如，<code>"abc"</code>&nbsp;是 <code>"aebdc"</code>&nbsp;的子序列，因为您可以删除<code>"a<u>e</u>b<u>d</u>c"</code>中的下划线字符来得到 <code>"abc"</code>&nbsp;。<code>"aebdc"</code>的子序列还包括<code>"aebdc"</code>、 <code>"aeb"</code>&nbsp;和 <font color="#c7254e" face="Menlo, Monaco, Consolas, Courier New, monospace"><span style="font-size: 12.6px; background-color: rgb(249, 242, 244);">""</span></font>&nbsp;(空字符串)。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入:</strong> strs = ["aba","cdc","eae"]
<strong>输出:</strong> 3
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> strs = ["aaa","aaa","aa"]
<strong>输出:</strong> -1
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>2 &lt;= strs.length &lt;= 50</code></li>
	<li><code>1 &lt;= strs[i].length &lt;= 10</code></li>
	<li><code>strs[i]</code>&nbsp;只包含小写英文字母</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：判断子序列

我们定义一个函数 $check(s, t)$，用于判断字符串 $s$ 是否是字符串 $t$ 的子序列。我们可以使用双指针的方法，初始化两个指针 $i$ 和 $j$ 分别指向字符串 $s$ 和字符串 $t$ 的开头，然后不断移动指针 $j$，如果 $s[i]$ 和 $t[j]$ 相等，则移动指针 $i$，最后判断 $i$ 是否等于 $s$ 的长度即可。若 $i$ 等于 $s$ 的长度，则说明 $s$ 是 $t$ 的子序列。

判断字符串 $s$ 是否独有，只需要取字符串 $s$ 本身，与字符串列表的其他字符串比较即可。如果存在 $s$ 是其他字符串的子序列，则 $s$ 不是独有的。否则，字符串 $s$ 是独有的。我们取所有独有字符串中长度最长的字符串即可。

时间复杂度 $O(n^2 \times m)$，其中 $n$ 是字符串列表的长度，而 $m$ 是字符串的平均长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findLUSlength(self, strs: List[str]) -> int:
        def check(s: str, t: str):
            i = j = 0
            while i < len(s) and j < len(t):
                if s[i] == t[j]:
                    i += 1
                j += 1
            return i == len(s)

        ans = -1
        for i, s in enumerate(strs):
            for j, t in enumerate(strs):
                if i != j and check(s, t):
                    break
            else:
                ans = max(ans, len(s))
        return ans
```

#### Java

```java
class Solution {
    public int findLUSlength(String[] strs) {
        int ans = -1;
        int n = strs.length;
        for (int i = 0, j; i < n; ++i) {
            int x = strs[i].length();
            for (j = 0; j < n; ++j) {
                if (i != j && check(strs[i], strs[j])) {
                    x = -1;
                    break;
                }
            }
            ans = Math.max(ans, x);
        }
        return ans;
    }

    private boolean check(String s, String t) {
        int m = s.length(), n = t.length();
        int i = 0;
        for (int j = 0; i < m && j < n; ++j) {
            if (s.charAt(i) == t.charAt(j)) {
                ++i;
            }
        }
        return i == m;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        int ans = -1;
        int n = strs.size();
        auto check = [&](const string& s, const string& t) {
            int m = s.size(), n = t.size();
            int i = 0;
            for (int j = 0; i < m && j < n; ++j) {
                if (s[i] == t[j]) {
                    ++i;
                }
            }
            return i == m;
        };
        for (int i = 0, j; i < n; ++i) {
            int x = strs[i].size();
            for (j = 0; j < n; ++j) {
                if (i != j && check(strs[i], strs[j])) {
                    x = -1;
                    break;
                }
            }
            ans = max(ans, x);
        }
        return ans;
    }
};
```

#### Go

```go
func findLUSlength(strs []string) int {
	ans := -1
	check := func(s, t string) bool {
		m, n := len(s), len(t)
		i := 0
		for j := 0; i < m && j < n; j++ {
			if s[i] == t[j] {
				i++
			}
		}
		return i == m
	}
	for i, s := range strs {
		x := len(s)
		for j, t := range strs {
			if i != j && check(s, t) {
				x = -1
				break
			}
		}
		ans = max(ans, x)
	}
	return ans
}
```

#### TypeScript

```ts
function findLUSlength(strs: string[]): number {
    const n = strs.length;
    let ans = -1;
    const check = (s: string, t: string): boolean => {
        const [m, n] = [s.length, t.length];
        let i = 0;
        for (let j = 0; i < m && j < n; ++j) {
            if (s[i] === t[j]) {
                ++i;
            }
        }
        return i === m;
    };
    for (let i = 0; i < n; ++i) {
        let x = strs[i].length;
        for (let j = 0; j < n; ++j) {
            if (i !== j && check(strs[i], strs[j])) {
                x = -1;
                break;
            }
        }
        ans = Math.max(ans, x);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [523. 连续的子数组和](https://leetcode.cn/problems/continuous-subarray-sum){#523}

{{< tabs "523" >}}

{{% tab "python" %}}
```python
class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        d = {0: -1}
        s = 0
        for i, x in enumerate(nums):
            s = (s + x) % k
            if s not in d:
                d[s] = i
            elif i - d[s] > 1:
                return True
        return False
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
        Map<Integer, Integer> d = new HashMap<>();
        d.put(0, -1);
        int s = 0;
        for (int i = 0; i < nums.length; ++i) {
            s = (s + nums[i]) % k;
            if (!d.containsKey(s)) {
                d.put(s, i);
            } else if (i - d.get(s) > 1) {
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
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> d{{0, -1}};
        int s = 0;
        for (int i = 0; i < nums.size(); ++i) {
            s = (s + nums[i]) % k;
            if (!d.contains(s)) {
                d[s] = i;
            } else if (i - d[s] > 1) {
                return true;
            }
        }
        return false;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func checkSubarraySum(nums []int, k int) bool {
	d := map[int]int{0: -1}
	s := 0
	for i, x := range nums {
		s = (s + x) % k
		if _, ok := d[s]; !ok {
			d[s] = i
		} else if i-d[s] > 1 {
			return true
		}
	}
	return false
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function checkSubarraySum(nums: number[], k: number): boolean {
    const d: Record<number, number> = { 0: -1 };
    let s = 0;
    for (let i = 0; i < nums.length; ++i) {
        s = (s + nums[i]) % k;
        if (!d.hasOwnProperty(s)) {
            d[s] = i;
        } else if (i - d[s] > 1) {
            return true;
        }
    }
    return false;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>nums</code> 和一个整数&nbsp;<code>k</code> ，如果&nbsp;<code>nums</code>&nbsp;有一个 <strong>好的子数组</strong>&nbsp;返回&nbsp;<code>true</code>&nbsp;，否则返回 <code>false</code>：</p>

<p>一个&nbsp;<strong>好的子数组</strong>&nbsp;是：</p>

<ul>
	<li>长度&nbsp;<strong>至少为 2</strong> ，且</li>
	<li>子数组元素总和为 <code>k</code> 的倍数。</li>
</ul>

<p><strong>注意</strong>：</p>

<ul>
	<li><strong>子数组</strong> 是数组中 <strong>连续</strong> 的部分。</li>
	<li>如果存在一个整数 <code>n</code> ，令整数 <code>x</code> 符合 <code>x = n * k</code> ，则称 <code>x</code> 是 <code>k</code> 的一个倍数。<code>0</code> <strong>始终</strong> 视为 <code>k</code> 的一个倍数。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [23<u>,2,4</u>,6,7], k = 6
<strong>输出：</strong>true
<strong>解释：</strong>[2,4] 是一个大小为 2 的子数组，并且和为 6 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [<u>23,2,6,4,7</u>], k = 6
<strong>输出：</strong>true
<strong>解释：</strong>[23, 2, 6, 4, 7] 是大小为 5 的子数组，并且和为 42 。 
42 是 6 的倍数，因为 42 = 7 * 6 且 7 是一个整数。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [23,2,6,4,7], k = 13
<strong>输出：</strong>false
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= sum(nums[i]) &lt;= 2<sup>31</sup> - 1</code></li>
	<li><code>1 &lt;= k &lt;= 2<sup>31</sup> - 1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前缀和 + 哈希表

根据题目描述，如果存在两个前缀和模 $k$ 的余数相同的位置 $i$ 和 $j$（不妨设 $j < i$），那么 $\textit{nums}[j+1..i]$ 这个子数组的和是 $k$ 的倍数。

因此，我们可以使用哈希表存储每个前缀和模 $k$ 的余数第一次出现的位置。初始时，我们在哈希表中存入一对键值对 $(0, -1)$，表示前缀和为 $0$ 的余数 $0$ 出现在位置 $-1$。

遍历数组时，我们计算当前前缀和的模 $k$ 的余数，如果当前前缀和的模 $k$ 的余数没有在哈希表中出现过，我们就将当前前缀和的模 $k$ 的余数和对应的位置存入哈希表中。否则，如果当前前缀和的模 $k$ 的余数在哈希表中已经出现过，位置为 $j$，那么我们就找到了一个满足条件的子数组 $\textit{nums}[j+1..i]$，因此返回 $\textit{True}$。

遍历结束后，如果没有找到满足条件的子数组，我们返回 $\textit{False}$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 $\textit{nums}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        d = {0: -1}
        s = 0
        for i, x in enumerate(nums):
            s = (s + x) % k
            if s not in d:
                d[s] = i
            elif i - d[s] > 1:
                return True
        return False
```

#### Java

```java
class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
        Map<Integer, Integer> d = new HashMap<>();
        d.put(0, -1);
        int s = 0;
        for (int i = 0; i < nums.length; ++i) {
            s = (s + nums[i]) % k;
            if (!d.containsKey(s)) {
                d.put(s, i);
            } else if (i - d.get(s) > 1) {
                return true;
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
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> d{{0, -1}};
        int s = 0;
        for (int i = 0; i < nums.size(); ++i) {
            s = (s + nums[i]) % k;
            if (!d.contains(s)) {
                d[s] = i;
            } else if (i - d[s] > 1) {
                return true;
            }
        }
        return false;
    }
};
```

#### Go

```go
func checkSubarraySum(nums []int, k int) bool {
	d := map[int]int{0: -1}
	s := 0
	for i, x := range nums {
		s = (s + x) % k
		if _, ok := d[s]; !ok {
			d[s] = i
		} else if i-d[s] > 1 {
			return true
		}
	}
	return false
}
```

#### TypeScript

```ts
function checkSubarraySum(nums: number[], k: number): boolean {
    const d: Record<number, number> = { 0: -1 };
    let s = 0;
    for (let i = 0; i < nums.length; ++i) {
        s = (s + nums[i]) % k;
        if (!d.hasOwnProperty(s)) {
            d[s] = i;
        } else if (i - d[s] > 1) {
            return true;
        }
    }
    return false;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [524. 通过删除字母匹配到字典里最长单词](https://leetcode.cn/problems/longest-word-in-dictionary-through-deleting){#524}

{{< tabs "524" >}}

{{% tab "python" %}}
```python
class Solution:
    def findLongestWord(self, s: str, dictionary: List[str]) -> str:
        def check(s: str, t: str) -> bool:
            m, n = len(s), len(t)
            i = j = 0
            while i < m and j < n:
                if s[i] == t[j]:
                    i += 1
                j += 1
            return i == m

        ans = ""
        for t in dictionary:
            if check(t, s) and (len(ans) < len(t) or (len(ans) == len(t) and ans > t)):
                ans = t
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String findLongestWord(String s, List<String> dictionary) {
        String ans = "";
        for (String t : dictionary) {
            int a = ans.length(), b = t.length();
            if (check(t, s) && (a < b || (a == b && t.compareTo(ans) < 0))) {
                ans = t;
            }
        }
        return ans;
    }

    private boolean check(String s, String t) {
        int m = s.length(), n = t.length();
        int i = 0;
        for (int j = 0; i < m && j < n; ++j) {
            if (s.charAt(i) == t.charAt(j)) {
                ++i;
            }
        }
        return i == m;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string ans = "";
        auto check = [&](const string& s, const string& t) {
            int m = s.size(), n = t.size();
            int i = 0;
            for (int j = 0; i < m && j < n; ++j) {
                if (s[i] == t[j]) {
                    ++i;
                }
            }
            return i == m;
        };
        for (auto& t : dictionary) {
            int a = ans.size(), b = t.size();
            if (check(t, s) && (a < b || (a == b && ans > t))) {
                ans = t;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findLongestWord(s string, dictionary []string) string {
	ans := ''
	check := func(s, t string) bool {
		m, n := len(s), len(t)
		i := 0
		for j := 0; i < m && j < n; j++ {
			if s[i] == t[j] {
				i++
			}
		}
		return i == m
	}
	for _, t := range dictionary {
		a, b := len(ans), len(t)
		if check(t, s) && (a < b || (a == b && ans > t)) {
			ans = t
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findLongestWord(s: string, dictionary: string[]): string {
    const check = (s: string, t: string): boolean => {
        const [m, n] = [s.length, t.length];
        let i = 0;
        for (let j = 0; i < m && j < n; ++j) {
            if (s[i] === t[j]) {
                ++i;
            }
        }
        return i === m;
    };
    let ans: string = '';
    for (const t of dictionary) {
        const [a, b] = [ans.length, t.length];
        if (check(t, s) && (a < b || (a === b && ans > t))) {
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
    pub fn find_longest_word(s: String, dictionary: Vec<String>) -> String {
        let mut ans = String::new();
        for t in dictionary {
            let a = ans.len();
            let b = t.len();
            if Self::check(&t, &s) && (a < b || (a == b && t < ans)) {
                ans = t;
            }
        }
        ans
    }

    fn check(s: &str, t: &str) -> bool {
        let (m, n) = (s.len(), t.len());
        let mut i = 0;
        let mut j = 0;
        let s: Vec<char> = s.chars().collect();
        let t: Vec<char> = t.chars().collect();

        while i < m && j < n {
            if s[i] == t[j] {
                i += 1;
            }
            j += 1;
        }
        i == m
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串 <code>s</code> 和一个字符串数组 <code>dictionary</code> ，找出并返回&nbsp;<code>dictionary</code> 中最长的字符串，该字符串可以通过删除 <code>s</code> 中的某些字符得到。</p>

<p>如果答案不止一个，返回长度最长且字母序最小的字符串。如果答案不存在，则返回空字符串。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
<strong>输出：</strong>"apple"
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "abpcplea", dictionary = ["a","b","c"]
<strong>输出：</strong>"a"
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>1 &lt;= dictionary.length &lt;= 1000</code></li>
	<li><code>1 &lt;= dictionary[i].length &lt;= 1000</code></li>
	<li><code>s</code> 和 <code>dictionary[i]</code> 仅由小写英文字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：判断子序列

我们定义一个函数 $check(s, t)$，用于判断字符串 $s$ 是否是字符串 $t$ 的子序列。我们可以使用双指针的方法，初始化两个指针 $i$ 和 $j$ 分别指向字符串 $s$ 和字符串 $t$ 的开头，然后不断移动指针 $j$，如果 $s[i]$ 和 $t[j]$ 相等，则移动指针 $i$，最后判断 $i$ 是否等于 $s$ 的长度即可。若 $i$ 等于 $s$ 的长度，则说明 $s$ 是 $t$ 的子序列。

我们初始化答案字符串 $ans$ 为空字符串，然后遍历数组 $dictionary$ 中的每个字符串 $t$，如果 $t$ 是 $s$ 的子序列，并且 $t$ 的长度大于 $ans$ 的长度，或者 $t$ 的长度等于 $ans$ 的长度且 $t$ 字典序小于 $ans$，则更新 $ans$ 为 $t$。

时间复杂度 $O(d \times (m + n))$，其中 $d$ 是字符串列表的长度，而 $m$ 和 $n$ 分别是字符串 $s$ 的长度和字符串列表中字符串的平均长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findLongestWord(self, s: str, dictionary: List[str]) -> str:
        def check(s: str, t: str) -> bool:
            m, n = len(s), len(t)
            i = j = 0
            while i < m and j < n:
                if s[i] == t[j]:
                    i += 1
                j += 1
            return i == m

        ans = ""
        for t in dictionary:
            if check(t, s) and (len(ans) < len(t) or (len(ans) == len(t) and ans > t)):
                ans = t
        return ans
```

#### Java

```java
class Solution {
    public String findLongestWord(String s, List<String> dictionary) {
        String ans = "";
        for (String t : dictionary) {
            int a = ans.length(), b = t.length();
            if (check(t, s) && (a < b || (a == b && t.compareTo(ans) < 0))) {
                ans = t;
            }
        }
        return ans;
    }

    private boolean check(String s, String t) {
        int m = s.length(), n = t.length();
        int i = 0;
        for (int j = 0; i < m && j < n; ++j) {
            if (s.charAt(i) == t.charAt(j)) {
                ++i;
            }
        }
        return i == m;
    }
}
```

#### C++

```cpp
class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string ans = "";
        auto check = [&](const string& s, const string& t) {
            int m = s.size(), n = t.size();
            int i = 0;
            for (int j = 0; i < m && j < n; ++j) {
                if (s[i] == t[j]) {
                    ++i;
                }
            }
            return i == m;
        };
        for (auto& t : dictionary) {
            int a = ans.size(), b = t.size();
            if (check(t, s) && (a < b || (a == b && ans > t))) {
                ans = t;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func findLongestWord(s string, dictionary []string) string {
	ans := ''
	check := func(s, t string) bool {
		m, n := len(s), len(t)
		i := 0
		for j := 0; i < m && j < n; j++ {
			if s[i] == t[j] {
				i++
			}
		}
		return i == m
	}
	for _, t := range dictionary {
		a, b := len(ans), len(t)
		if check(t, s) && (a < b || (a == b && ans > t)) {
			ans = t
		}
	}
	return ans
}
```

#### TypeScript

```ts
function findLongestWord(s: string, dictionary: string[]): string {
    const check = (s: string, t: string): boolean => {
        const [m, n] = [s.length, t.length];
        let i = 0;
        for (let j = 0; i < m && j < n; ++j) {
            if (s[i] === t[j]) {
                ++i;
            }
        }
        return i === m;
    };
    let ans: string = '';
    for (const t of dictionary) {
        const [a, b] = [ans.length, t.length];
        if (check(t, s) && (a < b || (a === b && ans > t))) {
            ans = t;
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn find_longest_word(s: String, dictionary: Vec<String>) -> String {
        let mut ans = String::new();
        for t in dictionary {
            let a = ans.len();
            let b = t.len();
            if Self::check(&t, &s) && (a < b || (a == b && t < ans)) {
                ans = t;
            }
        }
        ans
    }

    fn check(s: &str, t: &str) -> bool {
        let (m, n) = (s.len(), t.len());
        let mut i = 0;
        let mut j = 0;
        let s: Vec<char> = s.chars().collect();
        let t: Vec<char> = t.chars().collect();

        while i < m && j < n {
            if s[i] == t[j] {
                i += 1;
            }
            j += 1;
        }
        i == m
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [525. 连续数组](https://leetcode.cn/problems/contiguous-array){#525}

{{< tabs "525" >}}

{{% tab "python" %}}
```python
class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        d = {0: -1}
        ans = s = 0
        for i, x in enumerate(nums):
            s += 1 if x else -1
            if s in d:
                ans = max(ans, i - d[s])
            else:
                d[s] = i
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int findMaxLength(int[] nums) {
        Map<Integer, Integer> d = new HashMap<>();
        d.put(0, -1);
        int ans = 0, s = 0;
        for (int i = 0; i < nums.length; ++i) {
            s += nums[i] == 1 ? 1 : -1;
            if (d.containsKey(s)) {
                ans = Math.max(ans, i - d.get(s));
            } else {
                d.put(s, i);
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
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> d{{0, -1}};
        int ans = 0, s = 0;
        for (int i = 0; i < nums.size(); ++i) {
            s += nums[i] ? 1 : -1;
            if (d.contains(s)) {
                ans = max(ans, i - d[s]);
            } else {
                d[s] = i;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findMaxLength(nums []int) int {
	d := map[int]int{0: -1}
	ans, s := 0, 0
	for i, x := range nums {
		if x == 0 {
			x = -1
		}
		s += x
		if j, ok := d[s]; ok {
			ans = max(ans, i-j)
		} else {
			d[s] = i
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findMaxLength(nums: number[]): number {
    const d: Record<number, number> = { 0: -1 };
    let ans = 0;
    let s = 0;
    for (let i = 0; i < nums.length; ++i) {
        s += nums[i] ? 1 : -1;
        if (d.hasOwnProperty(s)) {
            ans = Math.max(ans, i - d[s]);
        } else {
            d[s] = i;
        }
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
var findMaxLength = function (nums) {
    const d = { 0: -1 };
    let ans = 0;
    let s = 0;
    for (let i = 0; i < nums.length; ++i) {
        s += nums[i] ? 1 : -1;
        if (d.hasOwnProperty(s)) {
            ans = Math.max(ans, i - d[s]);
        } else {
            d[s] = i;
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

<p>给定一个二进制数组 <code>nums</code> , 找到含有相同数量的 <code>0</code> 和 <code>1</code> 的最长连续子数组，并返回该子数组的长度。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [0,1]
<strong>输出：</strong>2
<strong>说明：</strong>[0, 1] 是具有相同数量 0 和 1 的最长连续子数组。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [0,1,0]
<strong>输出：</strong>2
<strong>说明：</strong>[0, 1] (或 [1, 0]) 是具有相同数量 0 和 1 的最长连续子数组。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>nums = [0,1,1,1,1,1,0,0,0]
<b>输出：</b>6
<b>解释：</b>[1,1,1,0,0,0] 是具有相同数量 0 和 1 的最长连续子数组。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>nums[i]</code> 不是 <code>0</code> 就是 <code>1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前缀和 + 哈希表

根据题目描述，我们可以将数组中的 $0$ 视作 $-1$，这样当遇到 $0$ 时，前缀和 $s$ 就会减一，当遇到 $1$ 时，前缀和 $s$ 就会加一。因此，假设前缀和 $s$ 在下标 $j$ 和 $i$ 处的值相等，其中 $j < i$，那么从下标 $j + 1$ 到 $i$ 的子数组中 $0$ 和 $1$ 的数量就是相等的。

我们使用哈希表存储所有的前缀和以及它们第一次出现的下标，初始时，我们将 $0$ 的前缀和映射到 $-1$。

遍历数组，计算前缀和 $s$，如果 $s$ 已经在哈希表中，那么我们就找到了一个和为 $0$ 的子数组，其长度为 $i - d[s]$，其中 $d[s]$ 是哈希表中保存的 $s$ 第一次出现的下标。如果 $s$ 不在哈希表中，我们将 $s$ 与它的下标 $i$ 存入哈希表。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        d = {0: -1}
        ans = s = 0
        for i, x in enumerate(nums):
            s += 1 if x else -1
            if s in d:
                ans = max(ans, i - d[s])
            else:
                d[s] = i
        return ans
```

#### Java

```java
class Solution {
    public int findMaxLength(int[] nums) {
        Map<Integer, Integer> d = new HashMap<>();
        d.put(0, -1);
        int ans = 0, s = 0;
        for (int i = 0; i < nums.length; ++i) {
            s += nums[i] == 1 ? 1 : -1;
            if (d.containsKey(s)) {
                ans = Math.max(ans, i - d.get(s));
            } else {
                d.put(s, i);
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
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> d{{0, -1}};
        int ans = 0, s = 0;
        for (int i = 0; i < nums.size(); ++i) {
            s += nums[i] ? 1 : -1;
            if (d.contains(s)) {
                ans = max(ans, i - d[s]);
            } else {
                d[s] = i;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func findMaxLength(nums []int) int {
	d := map[int]int{0: -1}
	ans, s := 0, 0
	for i, x := range nums {
		if x == 0 {
			x = -1
		}
		s += x
		if j, ok := d[s]; ok {
			ans = max(ans, i-j)
		} else {
			d[s] = i
		}
	}
	return ans
}
```

#### TypeScript

```ts
function findMaxLength(nums: number[]): number {
    const d: Record<number, number> = { 0: -1 };
    let ans = 0;
    let s = 0;
    for (let i = 0; i < nums.length; ++i) {
        s += nums[i] ? 1 : -1;
        if (d.hasOwnProperty(s)) {
            ans = Math.max(ans, i - d[s]);
        } else {
            d[s] = i;
        }
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
var findMaxLength = function (nums) {
    const d = { 0: -1 };
    let ans = 0;
    let s = 0;
    for (let i = 0; i < nums.length; ++i) {
        s += nums[i] ? 1 : -1;
        if (d.hasOwnProperty(s)) {
            ans = Math.max(ans, i - d[s]);
        } else {
            d[s] = i;
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

# [526. 优美的排列](https://leetcode.cn/problems/beautiful-arrangement){#526}

{{< tabs "526" >}}

{{% tab "python" %}}
```python
class Solution:
    def countArrangement(self, n: int) -> int:
        def dfs(i):
            nonlocal ans, n
            if i == n + 1:
                ans += 1
                return
            for j in match[i]:
                if not vis[j]:
                    vis[j] = True
                    dfs(i + 1)
                    vis[j] = False

        ans = 0
        vis = [False] * (n + 1)
        match = defaultdict(list)
        for i in range(1, n + 1):
            for j in range(1, n + 1):
                if j % i == 0 or i % j == 0:
                    match[i].append(j)

        dfs(1)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countArrangement(int N) {
        int maxn = 1 << N;
        int[] f = new int[maxn];
        f[0] = 1;
        for (int i = 0; i < maxn; ++i) {
            int s = 1;
            for (int j = 0; j < N; ++j) {
                s += (i >> j) & 1;
            }
            for (int j = 1; j <= N; ++j) {
                if (((i >> (j - 1) & 1) == 0) && (s % j == 0 || j % s == 0)) {
                    f[i | (1 << (j - 1))] += f[i];
                }
            }
        }
        return f[maxn - 1];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int n;
    int ans;
    vector<bool> vis;
    unordered_map<int, vector<int>> match;

    int countArrangement(int n) {
        this->n = n;
        this->ans = 0;
        vis.resize(n + 1);
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (i % j == 0 || j % i == 0)
                    match[i].push_back(j);
        dfs(1);
        return ans;
    }

    void dfs(int i) {
        if (i == n + 1) {
            ++ans;
            return;
        }
        for (int j : match[i]) {
            if (!vis[j]) {
                vis[j] = true;
                dfs(i + 1);
                vis[j] = false;
            }
        }
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countArrangement(n int) int {
	ans := 0
	match := make(map[int][]int)
	for i := 1; i <= n; i++ {
		for j := 1; j <= n; j++ {
			if i%j == 0 || j%i == 0 {
				match[i] = append(match[i], j)
			}
		}
	}
	vis := make([]bool, n+1)

	var dfs func(i int)
	dfs = func(i int) {
		if i == n+1 {
			ans++
			return
		}
		for _, j := range match[i] {
			if !vis[j] {
				vis[j] = true
				dfs(i + 1)
				vis[j] = false
			}
		}
	}

	dfs(1)
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countArrangement(n: number): number {
    const vis = new Array(n + 1).fill(0);
    const match = Array.from({ length: n + 1 }, () => []);
    for (let i = 1; i <= n; i++) {
        for (let j = 1; j <= n; j++) {
            if (i % j === 0 || j % i === 0) {
                match[i].push(j);
            }
        }
    }

    let res = 0;
    const dfs = (i: number, n: number) => {
        if (i === n + 1) {
            res++;
            return;
        }
        for (const j of match[i]) {
            if (!vis[j]) {
                vis[j] = true;
                dfs(i + 1, n);
                vis[j] = false;
            }
        }
    };
    dfs(1, n);
    return res;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    fn dfs(i: usize, n: usize, mat: &Vec<Vec<usize>>, vis: &mut Vec<bool>, res: &mut i32) {
        if i == n + 1 {
            *res += 1;
            return;
        }
        for &j in mat[i].iter() {
            if !vis[j] {
                vis[j] = true;
                Self::dfs(i + 1, n, mat, vis, res);
                vis[j] = false;
            }
        }
    }

    pub fn count_arrangement(n: i32) -> i32 {
        let n = n as usize;
        let mut vis = vec![false; n + 1];
        let mut mat = vec![Vec::new(); n + 1];
        for i in 1..=n {
            for j in 1..=n {
                if i % j == 0 || j % i == 0 {
                    mat[i].push(j);
                }
            }
        }

        let mut res = 0;
        Self::dfs(1, n, &mat, &mut vis, &mut res);
        res
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>假设有从 1 到 n 的 n 个整数。用这些整数构造一个数组 <code>perm</code>（<strong>下标从 1 开始</strong>），只要满足下述条件 <strong>之一</strong> ，该数组就是一个 <strong>优美的排列</strong> ：</p>

<ul>
	<li><code>perm[i]</code> 能够被 <code>i</code> 整除</li>
	<li><code>i</code> 能够被 <code>perm[i]</code> 整除</li>
</ul>

<p>给你一个整数 <code>n</code> ，返回可以构造的 <strong>优美排列 </strong>的 <strong>数量</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 2
<strong>输出：</strong>2
<b>解释：</b>
第 1 个优美的排列是 [1,2]：
    - perm[1] = 1 能被 i = 1 整除
    - perm[2] = 2 能被 i = 2 整除
第 2 个优美的排列是 [2,1]:
    - perm[1] = 2 能被 i = 1 整除
    - i = 2 能被 perm[2] = 1 整除
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 1
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 15</code></li>
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
    def countArrangement(self, n: int) -> int:
        def dfs(i):
            nonlocal ans, n
            if i == n + 1:
                ans += 1
                return
            for j in match[i]:
                if not vis[j]:
                    vis[j] = True
                    dfs(i + 1)
                    vis[j] = False

        ans = 0
        vis = [False] * (n + 1)
        match = defaultdict(list)
        for i in range(1, n + 1):
            for j in range(1, n + 1):
                if j % i == 0 or i % j == 0:
                    match[i].append(j)

        dfs(1)
        return ans
```

#### Java

```java
class Solution {
    private int n;
    private int ans;
    private boolean[] vis;
    private Map<Integer, List<Integer>> match;

    public int countArrangement(int n) {
        this.n = n;
        ans = 0;
        vis = new boolean[n + 1];
        match = new HashMap<>();
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i % j == 0 || j % i == 0) {
                    match.computeIfAbsent(i, k -> new ArrayList<>()).add(j);
                }
            }
        }
        dfs(1);
        return ans;
    }

    private void dfs(int i) {
        if (i == n + 1) {
            ++ans;
            return;
        }
        if (!match.containsKey(i)) {
            return;
        }
        for (int j : match.get(i)) {
            if (!vis[j]) {
                vis[j] = true;
                dfs(i + 1);
                vis[j] = false;
            }
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    int n;
    int ans;
    vector<bool> vis;
    unordered_map<int, vector<int>> match;

    int countArrangement(int n) {
        this->n = n;
        this->ans = 0;
        vis.resize(n + 1);
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (i % j == 0 || j % i == 0)
                    match[i].push_back(j);
        dfs(1);
        return ans;
    }

    void dfs(int i) {
        if (i == n + 1) {
            ++ans;
            return;
        }
        for (int j : match[i]) {
            if (!vis[j]) {
                vis[j] = true;
                dfs(i + 1);
                vis[j] = false;
            }
        }
    }
};
```

#### Go

```go
func countArrangement(n int) int {
	ans := 0
	match := make(map[int][]int)
	for i := 1; i <= n; i++ {
		for j := 1; j <= n; j++ {
			if i%j == 0 || j%i == 0 {
				match[i] = append(match[i], j)
			}
		}
	}
	vis := make([]bool, n+1)

	var dfs func(i int)
	dfs = func(i int) {
		if i == n+1 {
			ans++
			return
		}
		for _, j := range match[i] {
			if !vis[j] {
				vis[j] = true
				dfs(i + 1)
				vis[j] = false
			}
		}
	}

	dfs(1)
	return ans
}
```

#### TypeScript

```ts
function countArrangement(n: number): number {
    const vis = new Array(n + 1).fill(0);
    const match = Array.from({ length: n + 1 }, () => []);
    for (let i = 1; i <= n; i++) {
        for (let j = 1; j <= n; j++) {
            if (i % j === 0 || j % i === 0) {
                match[i].push(j);
            }
        }
    }

    let res = 0;
    const dfs = (i: number, n: number) => {
        if (i === n + 1) {
            res++;
            return;
        }
        for (const j of match[i]) {
            if (!vis[j]) {
                vis[j] = true;
                dfs(i + 1, n);
                vis[j] = false;
            }
        }
    };
    dfs(1, n);
    return res;
}
```

#### Rust

```rust
impl Solution {
    fn dfs(i: usize, n: usize, mat: &Vec<Vec<usize>>, vis: &mut Vec<bool>, res: &mut i32) {
        if i == n + 1 {
            *res += 1;
            return;
        }
        for &j in mat[i].iter() {
            if !vis[j] {
                vis[j] = true;
                Self::dfs(i + 1, n, mat, vis, res);
                vis[j] = false;
            }
        }
    }

    pub fn count_arrangement(n: i32) -> i32 {
        let n = n as usize;
        let mut vis = vec![false; n + 1];
        let mut mat = vec![Vec::new(); n + 1];
        for i in 1..=n {
            for j in 1..=n {
                if i % j == 0 || j % i == 0 {
                    mat[i].push(j);
                }
            }
        }

        let mut res = 0;
        Self::dfs(1, n, &mat, &mut vis, &mut res);
        res
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### Java

```java
class Solution {
    public int countArrangement(int N) {
        int maxn = 1 << N;
        int[] f = new int[maxn];
        f[0] = 1;
        for (int i = 0; i < maxn; ++i) {
            int s = 1;
            for (int j = 0; j < N; ++j) {
                s += (i >> j) & 1;
            }
            for (int j = 1; j <= N; ++j) {
                if (((i >> (j - 1) & 1) == 0) && (s % j == 0 || j % s == 0)) {
                    f[i | (1 << (j - 1))] += f[i];
                }
            }
        }
        return f[maxn - 1];
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [527. 单词缩写 🔒](https://leetcode.cn/problems/word-abbreviation){#527}

{{< tabs "527" >}}

{{% tab "python" %}}
```python
class Trie:
    __slots__ = ["children", "cnt"]

    def __init__(self):
        self.children = [None] * 26
        self.cnt = 0

    def insert(self, w: str):
        node = self
        for c in w:
            idx = ord(c) - ord("a")
            if not node.children[idx]:
                node.children[idx] = Trie()
            node = node.children[idx]
            node.cnt += 1

    def search(self, w: str) -> int:
        node = self
        cnt = 0
        for c in w:
            cnt += 1
            idx = ord(c) - ord("a")
            node = node.children[idx]
            if node.cnt == 1:
                return cnt
        return len(w)


class Solution:
    def wordsAbbreviation(self, words: List[str]) -> List[str]:
        tries = {}
        for w in words:
            m = len(w)
            if (m, w[-1]) not in tries:
                tries[(m, w[-1])] = Trie()
            tries[(m, w[-1])].insert(w)
        ans = []
        for w in words:
            cnt = tries[(len(w), w[-1])].search(w)
            ans.append(
                w if cnt + 2 >= len(w) else w[:cnt] + str(len(w) - cnt - 1) + w[-1]
            )
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Trie {
    private final Trie[] children = new Trie[26];
    private int cnt;

    public void insert(String w) {
        Trie node = this;
        for (char c : w.toCharArray()) {
            int idx = c - 'a';
            if (node.children[idx] == null) {
                node.children[idx] = new Trie();
            }
            node = node.children[idx];
            ++node.cnt;
        }
    }

    public int search(String w) {
        Trie node = this;
        int ans = 0;
        for (char c : w.toCharArray()) {
            ++ans;
            int idx = c - 'a';
            node = node.children[idx];
            if (node.cnt == 1) {
                return ans;
            }
        }
        return w.length();
    }
}

class Solution {
    public List<String> wordsAbbreviation(List<String> words) {
        Map<List<Integer>, Trie> tries = new HashMap<>();
        for (var w : words) {
            var key = List.of(w.length(), w.charAt(w.length() - 1) - 'a');
            tries.putIfAbsent(key, new Trie());
            tries.get(key).insert(w);
        }
        List<String> ans = new ArrayList<>();
        for (var w : words) {
            int m = w.length();
            var key = List.of(m, w.charAt(m - 1) - 'a');
            int cnt = tries.get(key).search(w);
            ans.add(cnt + 2 >= m ? w : w.substring(0, cnt) + (m - cnt - 1) + w.substring(m - 1));
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Trie {
public:
    Trie()
        : cnt(0) {
        fill(children.begin(), children.end(), nullptr);
    }

    void insert(const string& w) {
        Trie* node = this;
        for (char c : w) {
            int idx = c - 'a';
            if (node->children[idx] == nullptr) {
                node->children[idx] = new Trie();
            }
            node = node->children[idx];
            ++node->cnt;
        }
    }

    int search(const string& w) {
        Trie* node = this;
        int ans = 0;
        for (char c : w) {
            ++ans;
            int idx = c - 'a';
            node = node->children[idx];
            if (node->cnt == 1) {
                return ans;
            }
        }
        return w.size();
    }

private:
    array<Trie*, 26> children;
    int cnt;
};

class Solution {
public:
    vector<string> wordsAbbreviation(vector<string>& words) {
        map<pair<int, int>, Trie*> tries;
        for (const auto& w : words) {
            pair<int, int> key = {static_cast<int>(w.size()), w.back() - 'a'};
            if (tries.find(key) == tries.end()) {
                tries[key] = new Trie();
            }
            tries[key]->insert(w);
        }

        vector<string> ans;
        for (const auto& w : words) {
            int m = w.size();
            pair<int, int> key = {m, w.back() - 'a'};
            int cnt = tries[key]->search(w);
            ans.push_back((cnt + 2 >= m) ? w : w.substr(0, cnt) + to_string(m - cnt - 1) + w.back());
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

func (t *Trie) insert(w string) {
	node := t
	for _, c := range w {
		idx := c - 'a'
		if node.children[idx] == nil {
			node.children[idx] = &Trie{}
		}
		node = node.children[idx]
		node.cnt++
	}
}

func (t *Trie) search(w string) int {
	node := t
	ans := 0
	for _, c := range w {
		ans++
		idx := c - 'a'
		node = node.children[idx]
		if node.cnt == 1 {
			return ans
		}
	}
	return len(w)
}

func wordsAbbreviation(words []string) (ans []string) {
	tries := make(map[[2]int]*Trie)
	for _, w := range words {
		key := [2]int{len(w), int(w[len(w)-1] - 'a')}
		_, exists := tries[key]
		if !exists {
			tries[key] = &Trie{}
		}
		tries[key].insert(w)
	}

	for _, w := range words {
		m := len(w)
		key := [2]int{m, int(w[m-1] - 'a')}
		cnt := tries[key].search(w)
		if cnt+2 >= m {
			ans = append(ans, w)
		} else {
			abbr := w[:cnt] + fmt.Sprintf("%d", m-cnt-1) + w[m-1:]
			ans = append(ans, abbr)
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class Trie {
    private children: Trie[] = Array(26);
    private cnt: number = 0;

    insert(w: string): void {
        let node: Trie = this;
        for (const c of w) {
            const idx: number = c.charCodeAt(0) - 'a'.charCodeAt(0);
            if (!node.children[idx]) {
                node.children[idx] = new Trie();
            }
            node = node.children[idx];
            node.cnt++;
        }
    }

    search(w: string): number {
        let node: Trie = this;
        let ans: number = 0;
        for (const c of w) {
            ans++;
            const idx: number = c.charCodeAt(0) - 'a'.charCodeAt(0);
            node = node.children[idx];
            if (node.cnt === 1) {
                return ans;
            }
        }
        return w.length;
    }
}

function wordsAbbreviation(words: string[]): string[] {
    const tries: Map<string, Trie> = new Map();
    for (const w of words) {
        const key: string = `${w.length}-${w.charCodeAt(w.length - 1) - 'a'.charCodeAt(0)}`;
        if (!tries.get(key)) {
            tries.set(key, new Trie());
        }
        tries.get(key)!.insert(w);
    }

    const ans: string[] = [];
    for (const w of words) {
        const m: number = w.length;
        const key: string = `${m}-${w.charCodeAt(m - 1) - 'a'.charCodeAt(0)}`;
        const cnt: number = tries.get(key)!.search(w);
        ans.push(cnt + 2 >= m ? w : w.substring(0, cnt) + (m - cnt - 1) + w.substring(m - 1));
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

<p>给你一个字符串数组 <code>words</code> ，该数组由 <strong>互不相同</strong> 的若干字符串组成，请你找出并返回每个单词的 <strong>最小缩写</strong> 。</p>

<p>生成缩写的规则如下<strong>：</strong></p>

<ol>
	<li>初始缩写由起始字母+省略字母的数量+结尾字母组成。</li>
	<li>若存在冲突，亦即多于一个单词有同样的缩写，则使用更长的前缀代替首字母，直到从单词到缩写的映射唯一。换而言之，最终的缩写必须只能映射到一个单词。</li>
	<li>若缩写并不比原单词更短，则保留原样。</li>
</ol>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入:</strong> words = ["like", "god", "internal", "me", "internet", "interval", "intension", "face", "intrusion"]
<strong>输出:</strong> ["l2e","god","internal","me","i6t","interval","inte4n","f2e","intr4n"]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>words = ["aa","aaa"]
<strong>输出：</strong>["aa","aaa"]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 400</code></li>
	<li><code>2 &lt;= words[i].length &lt;= 400</code></li>
	<li><code>words[i]</code> 由小写英文字母组成</li>
	<li><code>words</code> 中的所有字符串 <strong>互不相同</strong></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：分组字典树

我们注意到，如果两个单词的缩写相同，那么它们的首尾字母一定相同，并且它们的长度一定相同。因此，我们可以将所有的单词按照长度以及末尾字母进行分组，对于每组单词，我们使用字典树存储这组单词的信息。

字典树的每个节点结构如下：

-   `children`：长度为 $26$ 的数组，表示该节点的所有子节点。
-   `cnt`：表示经过该节点的单词数量。

对于每个单词，我们将其插入到字典树中，同时记录每个节点的 `cnt` 值。

在查询时，我们从根节点开始，对于当前的字母，如果其对应的子节点的 `cnt` 值为 $1$，那么我们就找到了唯一的缩写，我们返回当前前缀的长度即可。否则，我们继续向下遍历。遍历结束后，如果我们没有找到唯一的缩写，那么我们返回原单词的长度。在得到所有单词的前缀长度后，我们判断单词的缩写是否比原单词更短，如果是，那么我们将其加入答案中，否则我们将原单词加入答案中。

时间复杂度 $O(L)$，空间复杂度 $O(L)$，其中 $L$ 为所有单词的长度和。

<!-- tabs:start -->

#### Python3

```python
class Trie:
    __slots__ = ["children", "cnt"]

    def __init__(self):
        self.children = [None] * 26
        self.cnt = 0

    def insert(self, w: str):
        node = self
        for c in w:
            idx = ord(c) - ord("a")
            if not node.children[idx]:
                node.children[idx] = Trie()
            node = node.children[idx]
            node.cnt += 1

    def search(self, w: str) -> int:
        node = self
        cnt = 0
        for c in w:
            cnt += 1
            idx = ord(c) - ord("a")
            node = node.children[idx]
            if node.cnt == 1:
                return cnt
        return len(w)


class Solution:
    def wordsAbbreviation(self, words: List[str]) -> List[str]:
        tries = {}
        for w in words:
            m = len(w)
            if (m, w[-1]) not in tries:
                tries[(m, w[-1])] = Trie()
            tries[(m, w[-1])].insert(w)
        ans = []
        for w in words:
            cnt = tries[(len(w), w[-1])].search(w)
            ans.append(
                w if cnt + 2 >= len(w) else w[:cnt] + str(len(w) - cnt - 1) + w[-1]
            )
        return ans
```

#### Java

```java
class Trie {
    private final Trie[] children = new Trie[26];
    private int cnt;

    public void insert(String w) {
        Trie node = this;
        for (char c : w.toCharArray()) {
            int idx = c - 'a';
            if (node.children[idx] == null) {
                node.children[idx] = new Trie();
            }
            node = node.children[idx];
            ++node.cnt;
        }
    }

    public int search(String w) {
        Trie node = this;
        int ans = 0;
        for (char c : w.toCharArray()) {
            ++ans;
            int idx = c - 'a';
            node = node.children[idx];
            if (node.cnt == 1) {
                return ans;
            }
        }
        return w.length();
    }
}

class Solution {
    public List<String> wordsAbbreviation(List<String> words) {
        Map<List<Integer>, Trie> tries = new HashMap<>();
        for (var w : words) {
            var key = List.of(w.length(), w.charAt(w.length() - 1) - 'a');
            tries.putIfAbsent(key, new Trie());
            tries.get(key).insert(w);
        }
        List<String> ans = new ArrayList<>();
        for (var w : words) {
            int m = w.length();
            var key = List.of(m, w.charAt(m - 1) - 'a');
            int cnt = tries.get(key).search(w);
            ans.add(cnt + 2 >= m ? w : w.substring(0, cnt) + (m - cnt - 1) + w.substring(m - 1));
        }
        return ans;
    }
}
```

#### C++

```cpp
class Trie {
public:
    Trie()
        : cnt(0) {
        fill(children.begin(), children.end(), nullptr);
    }

    void insert(const string& w) {
        Trie* node = this;
        for (char c : w) {
            int idx = c - 'a';
            if (node->children[idx] == nullptr) {
                node->children[idx] = new Trie();
            }
            node = node->children[idx];
            ++node->cnt;
        }
    }

    int search(const string& w) {
        Trie* node = this;
        int ans = 0;
        for (char c : w) {
            ++ans;
            int idx = c - 'a';
            node = node->children[idx];
            if (node->cnt == 1) {
                return ans;
            }
        }
        return w.size();
    }

private:
    array<Trie*, 26> children;
    int cnt;
};

class Solution {
public:
    vector<string> wordsAbbreviation(vector<string>& words) {
        map<pair<int, int>, Trie*> tries;
        for (const auto& w : words) {
            pair<int, int> key = {static_cast<int>(w.size()), w.back() - 'a'};
            if (tries.find(key) == tries.end()) {
                tries[key] = new Trie();
            }
            tries[key]->insert(w);
        }

        vector<string> ans;
        for (const auto& w : words) {
            int m = w.size();
            pair<int, int> key = {m, w.back() - 'a'};
            int cnt = tries[key]->search(w);
            ans.push_back((cnt + 2 >= m) ? w : w.substr(0, cnt) + to_string(m - cnt - 1) + w.back());
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

func (t *Trie) insert(w string) {
	node := t
	for _, c := range w {
		idx := c - 'a'
		if node.children[idx] == nil {
			node.children[idx] = &Trie{}
		}
		node = node.children[idx]
		node.cnt++
	}
}

func (t *Trie) search(w string) int {
	node := t
	ans := 0
	for _, c := range w {
		ans++
		idx := c - 'a'
		node = node.children[idx]
		if node.cnt == 1 {
			return ans
		}
	}
	return len(w)
}

func wordsAbbreviation(words []string) (ans []string) {
	tries := make(map[[2]int]*Trie)
	for _, w := range words {
		key := [2]int{len(w), int(w[len(w)-1] - 'a')}
		_, exists := tries[key]
		if !exists {
			tries[key] = &Trie{}
		}
		tries[key].insert(w)
	}

	for _, w := range words {
		m := len(w)
		key := [2]int{m, int(w[m-1] - 'a')}
		cnt := tries[key].search(w)
		if cnt+2 >= m {
			ans = append(ans, w)
		} else {
			abbr := w[:cnt] + fmt.Sprintf("%d", m-cnt-1) + w[m-1:]
			ans = append(ans, abbr)
		}
	}
	return
}
```

#### TypeScript

```ts
class Trie {
    private children: Trie[] = Array(26);
    private cnt: number = 0;

    insert(w: string): void {
        let node: Trie = this;
        for (const c of w) {
            const idx: number = c.charCodeAt(0) - 'a'.charCodeAt(0);
            if (!node.children[idx]) {
                node.children[idx] = new Trie();
            }
            node = node.children[idx];
            node.cnt++;
        }
    }

    search(w: string): number {
        let node: Trie = this;
        let ans: number = 0;
        for (const c of w) {
            ans++;
            const idx: number = c.charCodeAt(0) - 'a'.charCodeAt(0);
            node = node.children[idx];
            if (node.cnt === 1) {
                return ans;
            }
        }
        return w.length;
    }
}

function wordsAbbreviation(words: string[]): string[] {
    const tries: Map<string, Trie> = new Map();
    for (const w of words) {
        const key: string = `${w.length}-${w.charCodeAt(w.length - 1) - 'a'.charCodeAt(0)}`;
        if (!tries.get(key)) {
            tries.set(key, new Trie());
        }
        tries.get(key)!.insert(w);
    }

    const ans: string[] = [];
    for (const w of words) {
        const m: number = w.length;
        const key: string = `${m}-${w.charCodeAt(m - 1) - 'a'.charCodeAt(0)}`;
        const cnt: number = tries.get(key)!.search(w);
        ans.push(cnt + 2 >= m ? w : w.substring(0, cnt) + (m - cnt - 1) + w.substring(m - 1));
    }

    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [528. 按权重随机选择](https://leetcode.cn/problems/random-pick-with-weight){#528}

{{< tabs "528" >}}

{{% tab "python" %}}
```python
class Solution:
    def __init__(self, w: List[int]):
        self.s = [0]
        for c in w:
            self.s.append(self.s[-1] + c)

    def pickIndex(self) -> int:
        x = random.randint(1, self.s[-1])
        left, right = 1, len(self.s) - 1
        while left < right:
            mid = (left + right) >> 1
            if self.s[mid] >= x:
                right = mid
            else:
                left = mid + 1
        return left - 1


# Your Solution object will be instantiated and called as such:
# obj = Solution(w)
# param_1 = obj.pickIndex()
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[] s;
    private Random random = new Random();

    public Solution(int[] w) {
        int n = w.length;
        s = new int[n + 1];
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + w[i];
        }
    }

    public int pickIndex() {
        int x = 1 + random.nextInt(s[s.length - 1]);
        int left = 1, right = s.length - 1;
        while (left < right) {
            int mid = (left + right) >> 1;
            if (s[mid] >= x) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left - 1;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> s;

    Solution(vector<int>& w) {
        int n = w.size();
        s.resize(n + 1);
        for (int i = 0; i < n; ++i) s[i + 1] = s[i] + w[i];
    }

    int pickIndex() {
        int n = s.size();
        int x = 1 + rand() % s[n - 1];
        int left = 1, right = n - 1;
        while (left < right) {
            int mid = left + right >> 1;
            if (s[mid] >= x)
                right = mid;
            else
                left = mid + 1;
        }
        return left - 1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type Solution struct {
	s []int
}

func Constructor(w []int) Solution {
	n := len(w)
	s := make([]int, n+1)
	for i := 0; i < n; i++ {
		s[i+1] = s[i] + w[i]
	}
	return Solution{s}
}

func (this *Solution) PickIndex() int {
	n := len(this.s)
	x := 1 + rand.Intn(this.s[n-1])
	left, right := 1, n-1
	for left < right {
		mid := (left + right) >> 1
		if this.s[mid] >= x {
			right = mid
		} else {
			left = mid + 1
		}
	}
	return left - 1
}

/**
 * Your Solution object will be instantiated and called as such:
 * obj := Constructor(w);
 * param_1 := obj.PickIndex();
 */
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use rand::{thread_rng, Rng};

struct Solution {
    sum: Vec<i32>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl Solution {
    fn new(w: Vec<i32>) -> Self {
        let n = w.len();
        let mut sum = vec![0; n + 1];
        for i in 1..=n {
            sum[i] = sum[i - 1] + w[i - 1];
        }
        Self { sum }
    }

    fn pick_index(&self) -> i32 {
        let x = thread_rng().gen_range(1, self.sum.last().unwrap() + 1);
        let (mut left, mut right) = (1, self.sum.len() - 1);
        while left < right {
            let mid = (left + right) >> 1;
            if self.sum[mid] < x {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        (left - 1) as i32
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} w
 */
var Solution = function (w) {
    const n = w.length;
    this.s = new Array(n + 1).fill(0);
    for (let i = 0; i < n; ++i) {
        this.s[i + 1] = this.s[i] + w[i];
    }
};

/**
 * @return {number}
 */
Solution.prototype.pickIndex = function () {
    const n = this.s.length;
    const x = 1 + Math.floor(Math.random() * this.s[n - 1]);
    let left = 1,
        right = n - 1;
    while (left < right) {
        const mid = (left + right) >> 1;
        if (this.s[mid] >= x) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left - 1;
};

/**
 * Your Solution object will be instantiated and called as such:
 * var obj = new Solution(w)
 * var param_1 = obj.pickIndex()
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个 <strong>下标从 0 开始</strong> 的正整数数组&nbsp;<code>w</code> ，其中&nbsp;<code>w[i]</code> 代表第 <code>i</code> 个下标的权重。</p>

<p>请你实现一个函数&nbsp;<code>pickIndex</code>&nbsp;，它可以 <strong>随机地</strong> 从范围 <code>[0, w.length - 1]</code> 内（含 <code>0</code> 和 <code>w.length - 1</code>）选出并返回一个下标。选取下标 <code>i</code>&nbsp;的 <strong>概率</strong> 为 <code>w[i] / sum(w)</code> 。</p>

<ol>
</ol>

<ul>
	<li>例如，对于 <code>w = [1, 3]</code>，挑选下标 <code>0</code> 的概率为 <code>1 / (1 + 3)&nbsp;= 0.25</code> （即，25%），而选取下标 <code>1</code> 的概率为 <code>3 / (1 + 3)&nbsp;= 0.75</code>（即，<code>75%</code>）。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
["Solution","pickIndex"]
[[[1]],[]]
<strong>输出：</strong>
[null,0]
<strong>解释：</strong>
Solution solution = new Solution([1]);
solution.pickIndex(); // 返回 0，因为数组中只有一个元素，所以唯一的选择是返回下标 0。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>
["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]
[[[1,3]],[],[],[],[],[]]
<strong>输出：</strong>
[null,1,1,1,1,0]
<strong>解释：</strong>
Solution solution = new Solution([1, 3]);
solution.pickIndex(); // 返回 1，返回下标 1，返回该下标概率为 3/4 。
solution.pickIndex(); // 返回 1
solution.pickIndex(); // 返回 1
solution.pickIndex(); // 返回 1
solution.pickIndex(); // 返回 0，返回下标 0，返回该下标概率为 1/4 。

由于这是一个随机问题，允许多个答案，因此下列输出都可以被认为是正确的:
[null,1,1,1,1,0]
[null,1,1,1,1,1]
[null,1,1,1,0,0]
[null,1,1,1,0,1]
[null,1,0,1,0,0]
......
诸若此类。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= w.length &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= w[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>pickIndex</code>&nbsp;将被调用不超过 <code>10<sup>4</sup></code>&nbsp;次</li>
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
    def __init__(self, w: List[int]):
        self.s = [0]
        for c in w:
            self.s.append(self.s[-1] + c)

    def pickIndex(self) -> int:
        x = random.randint(1, self.s[-1])
        left, right = 1, len(self.s) - 1
        while left < right:
            mid = (left + right) >> 1
            if self.s[mid] >= x:
                right = mid
            else:
                left = mid + 1
        return left - 1


# Your Solution object will be instantiated and called as such:
# obj = Solution(w)
# param_1 = obj.pickIndex()
```

#### Java

```java
class Solution {
    private int[] s;
    private Random random = new Random();

    public Solution(int[] w) {
        int n = w.length;
        s = new int[n + 1];
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + w[i];
        }
    }

    public int pickIndex() {
        int x = 1 + random.nextInt(s[s.length - 1]);
        int left = 1, right = s.length - 1;
        while (left < right) {
            int mid = (left + right) >> 1;
            if (s[mid] >= x) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left - 1;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 */
```

#### C++

```cpp
class Solution {
public:
    vector<int> s;

    Solution(vector<int>& w) {
        int n = w.size();
        s.resize(n + 1);
        for (int i = 0; i < n; ++i) s[i + 1] = s[i] + w[i];
    }

    int pickIndex() {
        int n = s.size();
        int x = 1 + rand() % s[n - 1];
        int left = 1, right = n - 1;
        while (left < right) {
            int mid = left + right >> 1;
            if (s[mid] >= x)
                right = mid;
            else
                left = mid + 1;
        }
        return left - 1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
```

#### Go

```go
type Solution struct {
	s []int
}

func Constructor(w []int) Solution {
	n := len(w)
	s := make([]int, n+1)
	for i := 0; i < n; i++ {
		s[i+1] = s[i] + w[i]
	}
	return Solution{s}
}

func (this *Solution) PickIndex() int {
	n := len(this.s)
	x := 1 + rand.Intn(this.s[n-1])
	left, right := 1, n-1
	for left < right {
		mid := (left + right) >> 1
		if this.s[mid] >= x {
			right = mid
		} else {
			left = mid + 1
		}
	}
	return left - 1
}

/**
 * Your Solution object will be instantiated and called as such:
 * obj := Constructor(w);
 * param_1 := obj.PickIndex();
 */
```

#### Rust

```rust
use rand::{thread_rng, Rng};

struct Solution {
    sum: Vec<i32>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl Solution {
    fn new(w: Vec<i32>) -> Self {
        let n = w.len();
        let mut sum = vec![0; n + 1];
        for i in 1..=n {
            sum[i] = sum[i - 1] + w[i - 1];
        }
        Self { sum }
    }

    fn pick_index(&self) -> i32 {
        let x = thread_rng().gen_range(1, self.sum.last().unwrap() + 1);
        let (mut left, mut right) = (1, self.sum.len() - 1);
        while left < right {
            let mid = (left + right) >> 1;
            if self.sum[mid] < x {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        (left - 1) as i32
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} w
 */
var Solution = function (w) {
    const n = w.length;
    this.s = new Array(n + 1).fill(0);
    for (let i = 0; i < n; ++i) {
        this.s[i + 1] = this.s[i] + w[i];
    }
};

/**
 * @return {number}
 */
Solution.prototype.pickIndex = function () {
    const n = this.s.length;
    const x = 1 + Math.floor(Math.random() * this.s[n - 1]);
    let left = 1,
        right = n - 1;
    while (left < right) {
        const mid = (left + right) >> 1;
        if (this.s[mid] >= x) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left - 1;
};

/**
 * Your Solution object will be instantiated and called as such:
 * var obj = new Solution(w)
 * var param_1 = obj.pickIndex()
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [529. 扫雷游戏](https://leetcode.cn/problems/minesweeper){#529}

{{< tabs "529" >}}

{{% tab "python" %}}
```python
class Solution:
    def updateBoard(self, board: List[List[str]], click: List[int]) -> List[List[str]]:
        def dfs(i: int, j: int):
            cnt = 0
            for x in range(i - 1, i + 2):
                for y in range(j - 1, j + 2):
                    if 0 <= x < m and 0 <= y < n and board[x][y] == "M":
                        cnt += 1
            if cnt:
                board[i][j] = str(cnt)
            else:
                board[i][j] = "B"
                for x in range(i - 1, i + 2):
                    for y in range(j - 1, j + 2):
                        if 0 <= x < m and 0 <= y < n and board[x][y] == "E":
                            dfs(x, y)

        m, n = len(board), len(board[0])
        i, j = click
        if board[i][j] == "M":
            board[i][j] = "X"
        else:
            dfs(i, j)
        return board
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private char[][] board;
    private int m;
    private int n;

    public char[][] updateBoard(char[][] board, int[] click) {
        m = board.length;
        n = board[0].length;
        this.board = board;
        int i = click[0], j = click[1];
        if (board[i][j] == 'M') {
            board[i][j] = 'X';
        } else {
            dfs(i, j);
        }
        return board;
    }

    private void dfs(int i, int j) {
        int cnt = 0;
        for (int x = i - 1; x <= i + 1; ++x) {
            for (int y = j - 1; y <= j + 1; ++y) {
                if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 'M') {
                    ++cnt;
                }
            }
        }
        if (cnt > 0) {
            board[i][j] = (char) (cnt + '0');
        } else {
            board[i][j] = 'B';
            for (int x = i - 1; x <= i + 1; ++x) {
                for (int y = j - 1; y <= j + 1; ++y) {
                    if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 'E') {
                        dfs(x, y);
                    }
                }
            }
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int m = board.size(), n = board[0].size();
        int i = click[0], j = click[1];

        function<void(int, int)> dfs = [&](int i, int j) {
            int cnt = 0;
            for (int x = i - 1; x <= i + 1; ++x) {
                for (int y = j - 1; y <= j + 1; ++y) {
                    if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 'M') {
                        ++cnt;
                    }
                }
            }
            if (cnt) {
                board[i][j] = cnt + '0';
            } else {
                board[i][j] = 'B';
                for (int x = i - 1; x <= i + 1; ++x) {
                    for (int y = j - 1; y <= j + 1; ++y) {
                        if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 'E') {
                            dfs(x, y);
                        }
                    }
                }
            }
        };

        if (board[i][j] == 'M') {
            board[i][j] = 'X';
        } else {
            dfs(i, j);
        }
        return board;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func updateBoard(board [][]byte, click []int) [][]byte {
	m, n := len(board), len(board[0])
	i, j := click[0], click[1]

	var dfs func(i, j int)
	dfs = func(i, j int) {
		cnt := 0
		for x := i - 1; x <= i+1; x++ {
			for y := j - 1; y <= j+1; y++ {
				if x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 'M' {
					cnt++
				}
			}
		}
		if cnt > 0 {
			board[i][j] = byte(cnt + '0')
			return
		}
		board[i][j] = 'B'
		for x := i - 1; x <= i+1; x++ {
			for y := j - 1; y <= j+1; y++ {
				if x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 'E' {
					dfs(x, y)
				}
			}
		}
	}

	if board[i][j] == 'M' {
		board[i][j] = 'X'
	} else {
		dfs(i, j)
	}
	return board
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function updateBoard(board: string[][], click: number[]): string[][] {
    const m = board.length;
    const n = board[0].length;
    const [i, j] = click;

    const dfs = (i: number, j: number) => {
        let cnt = 0;
        for (let x = i - 1; x <= i + 1; ++x) {
            for (let y = j - 1; y <= j + 1; ++y) {
                if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] === 'M') {
                    ++cnt;
                }
            }
        }
        if (cnt > 0) {
            board[i][j] = cnt.toString();
            return;
        }
        board[i][j] = 'B';
        for (let x = i - 1; x <= i + 1; ++x) {
            for (let y = j - 1; y <= j + 1; ++y) {
                if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] === 'E') {
                    dfs(x, y);
                }
            }
        }
    };

    if (board[i][j] === 'M') {
        board[i][j] = 'X';
    } else {
        dfs(i, j);
    }
    return board;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>让我们一起来玩扫雷游戏！</p>

<p>给你一个大小为 <code>m x n</code> 二维字符矩阵&nbsp;<code>board</code> ，表示扫雷游戏的盘面，其中：</p>

<ul>
	<li><code>'M'</code>&nbsp;代表一个 <strong>未挖出的</strong> 地雷，</li>
	<li><code>'E'</code>&nbsp;代表一个<strong> 未挖出的 </strong>空方块，</li>
	<li><code>'B'</code><strong>&nbsp;</strong>代表没有相邻（上，下，左，右，和所有4个对角线）地雷的<strong> 已挖出的 </strong>空白方块，</li>
	<li><strong>数字</strong>（<code>'1'</code> 到 <code>'8'</code>）表示有多少地雷与这块<strong> 已挖出的</strong> 方块相邻，</li>
	<li><code>'X'</code>&nbsp;则表示一个<strong> 已挖出的</strong> 地雷。</li>
</ul>

<p>给你一个整数数组 <code>click</code> ，其中 <code>click = [click<sub>r</sub>, click<sub>c</sub>]</code> 表示在所有<strong> 未挖出的 </strong>方块（<code>'M'</code> 或者 <code>'E'</code>）中的下一个点击位置（<code>click<sub>r</sub></code> 是行下标，<code>click<sub>c</sub></code> 是列下标）。</p>

<p>根据以下规则，返回相应位置被点击后对应的盘面：</p>

<ol>
	<li>如果一个地雷（<code>'M'</code>）被挖出，游戏就结束了- 把它改为&nbsp;<code>'X'</code> 。</li>
	<li>如果一个<strong> 没有相邻地雷 </strong>的空方块（<code>'E'</code>）被挖出，修改它为（<code>'B'</code>），并且所有和其相邻的<strong> 未挖出 </strong>方块都应该被递归地揭露。</li>
	<li>如果一个<strong> 至少与一个地雷相邻</strong> 的空方块（<code>'E'</code>）被挖出，修改它为数字（<code>'1'</code> 到 <code>'8'</code> ），表示相邻地雷的数量。</li>
	<li>如果在此次点击中，若无更多方块可被揭露，则返回盘面。</li>
</ol>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0500-0599/0529.Minesweeper/images/untitled.jpeg" style="width: 500px; max-width: 400px; height: 269px;" />
<pre>
<strong>输入：</strong>board = [["E","E","E","E","E"],["E","E","M","E","E"],["E","E","E","E","E"],["E","E","E","E","E"]], click = [3,0]
<strong>输出：</strong>[["B","1","E","1","B"],["B","1","M","1","B"],["B","1","1","1","B"],["B","B","B","B","B"]]
</pre>

<p><strong>示例 2：</strong></p>
<img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0500-0599/0529.Minesweeper/images/untitled-2.jpeg" style="width: 500px; max-width: 400px; height: 275px;" />
<pre>
<strong>输入：</strong>board = [["B","1","E","1","B"],["B","1","M","1","B"],["B","1","1","1","B"],["B","B","B","B","B"]], click = [1,2]
<strong>输出：</strong>[["B","1","E","1","B"],["B","1","X","1","B"],["B","1","1","1","B"],["B","B","B","B","B"]]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == board.length</code></li>
	<li><code>n == board[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 50</code></li>
	<li><code>board[i][j]</code> 为 <code>'M'</code>、<code>'E'</code>、<code>'B'</code> 或数字 <code>'1'</code> 到 <code>'8'</code> 中的一个</li>
	<li><code>click.length == 2</code></li>
	<li><code>0 &lt;= click<sub>r</sub> &lt; m</code></li>
	<li><code>0 &lt;= click<sub>c</sub> &lt; n</code></li>
	<li><code>board[click<sub>r</sub>][click<sub>c</sub>]</code> 为 <code>'M'</code> 或 <code>'E'</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS

我们记 $click = (i, j)$，如果 $board[i][j]$ 等于 `'M'`，那么直接将 $board[i][j]$ 的值改为 `'X'` 即可。否则，我们需要统计 $board[i][j]$ 周围的地雷数量 $cnt$，如果 $cnt$ 不为 $0$，那么将 $board[i][j]$ 的值改为 $cnt$ 的字符串形式。否则，将 $board[i][j]$ 的值改为 `'B'`，并且递归地搜索处理 $board[i][j]$ 周围的未挖出的方块。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别是二维数组 $board$ 的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def updateBoard(self, board: List[List[str]], click: List[int]) -> List[List[str]]:
        def dfs(i: int, j: int):
            cnt = 0
            for x in range(i - 1, i + 2):
                for y in range(j - 1, j + 2):
                    if 0 <= x < m and 0 <= y < n and board[x][y] == "M":
                        cnt += 1
            if cnt:
                board[i][j] = str(cnt)
            else:
                board[i][j] = "B"
                for x in range(i - 1, i + 2):
                    for y in range(j - 1, j + 2):
                        if 0 <= x < m and 0 <= y < n and board[x][y] == "E":
                            dfs(x, y)

        m, n = len(board), len(board[0])
        i, j = click
        if board[i][j] == "M":
            board[i][j] = "X"
        else:
            dfs(i, j)
        return board
```

#### Java

```java
class Solution {
    private char[][] board;
    private int m;
    private int n;

    public char[][] updateBoard(char[][] board, int[] click) {
        m = board.length;
        n = board[0].length;
        this.board = board;
        int i = click[0], j = click[1];
        if (board[i][j] == 'M') {
            board[i][j] = 'X';
        } else {
            dfs(i, j);
        }
        return board;
    }

    private void dfs(int i, int j) {
        int cnt = 0;
        for (int x = i - 1; x <= i + 1; ++x) {
            for (int y = j - 1; y <= j + 1; ++y) {
                if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 'M') {
                    ++cnt;
                }
            }
        }
        if (cnt > 0) {
            board[i][j] = (char) (cnt + '0');
        } else {
            board[i][j] = 'B';
            for (int x = i - 1; x <= i + 1; ++x) {
                for (int y = j - 1; y <= j + 1; ++y) {
                    if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 'E') {
                        dfs(x, y);
                    }
                }
            }
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int m = board.size(), n = board[0].size();
        int i = click[0], j = click[1];

        function<void(int, int)> dfs = [&](int i, int j) {
            int cnt = 0;
            for (int x = i - 1; x <= i + 1; ++x) {
                for (int y = j - 1; y <= j + 1; ++y) {
                    if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 'M') {
                        ++cnt;
                    }
                }
            }
            if (cnt) {
                board[i][j] = cnt + '0';
            } else {
                board[i][j] = 'B';
                for (int x = i - 1; x <= i + 1; ++x) {
                    for (int y = j - 1; y <= j + 1; ++y) {
                        if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 'E') {
                            dfs(x, y);
                        }
                    }
                }
            }
        };

        if (board[i][j] == 'M') {
            board[i][j] = 'X';
        } else {
            dfs(i, j);
        }
        return board;
    }
};
```

#### Go

```go
func updateBoard(board [][]byte, click []int) [][]byte {
	m, n := len(board), len(board[0])
	i, j := click[0], click[1]

	var dfs func(i, j int)
	dfs = func(i, j int) {
		cnt := 0
		for x := i - 1; x <= i+1; x++ {
			for y := j - 1; y <= j+1; y++ {
				if x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 'M' {
					cnt++
				}
			}
		}
		if cnt > 0 {
			board[i][j] = byte(cnt + '0')
			return
		}
		board[i][j] = 'B'
		for x := i - 1; x <= i+1; x++ {
			for y := j - 1; y <= j+1; y++ {
				if x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 'E' {
					dfs(x, y)
				}
			}
		}
	}

	if board[i][j] == 'M' {
		board[i][j] = 'X'
	} else {
		dfs(i, j)
	}
	return board
}
```

#### TypeScript

```ts
function updateBoard(board: string[][], click: number[]): string[][] {
    const m = board.length;
    const n = board[0].length;
    const [i, j] = click;

    const dfs = (i: number, j: number) => {
        let cnt = 0;
        for (let x = i - 1; x <= i + 1; ++x) {
            for (let y = j - 1; y <= j + 1; ++y) {
                if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] === 'M') {
                    ++cnt;
                }
            }
        }
        if (cnt > 0) {
            board[i][j] = cnt.toString();
            return;
        }
        board[i][j] = 'B';
        for (let x = i - 1; x <= i + 1; ++x) {
            for (let y = j - 1; y <= j + 1; ++y) {
                if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] === 'E') {
                    dfs(x, y);
                }
            }
        }
    };

    if (board[i][j] === 'M') {
        board[i][j] = 'X';
    } else {
        dfs(i, j);
    }
    return board;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
