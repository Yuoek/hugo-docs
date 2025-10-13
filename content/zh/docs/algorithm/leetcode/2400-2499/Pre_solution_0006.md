---
title: "2450_应用操作后不同二进制字符串的数量 🔒"
date: 2025-10-08T18:39:18+08:00
weight: 6
tags: [二分查找, 二叉树, 单调栈, 哈希表, 堆（优先队列）, 字典树, 字符串, 广度优先搜索, 排序, 数学, 数组, 栈, 树, 深度优先搜索, 计数, 贪心]
---

{{< markmap >}}
### [2450_应用操作后不同二进制字符串的数量 🔒](#2450)
#### [数学](#2450)
#### [字符串](#2450)
### [2451_差值数组不同的字符串](#2451)
#### [数组](#2451)
#### [哈希表](#2451)
#### [字符串](#2451)
### [2452_距离字典两次编辑以内的单词](#2452)
#### [字典树](#2452)
#### [数组](#2452)
#### [字符串](#2452)
### [2453_摧毁一系列目标](#2453)
#### [数组](#2453)
#### [哈希表](#2453)
#### [计数](#2453)
### [2454_下一个更大元素 IV](#2454)
#### [栈](#2454)
#### [数组](#2454)
#### [二分查找](#2454)
#### [排序](#2454)
#### [单调栈](#2454)
#### [堆（优先队列）](#2454)
### [2455_可被三整除的偶数的平均值](#2455)
#### [数组](#2455)
#### [数学](#2455)
### [2456_最流行的视频创作者](#2456)
#### [数组](#2456)
#### [哈希表](#2456)
#### [字符串](#2456)
#### [排序](#2456)
#### [堆（优先队列）](#2456)
### [2457_美丽整数的最小增量](#2457)
#### [贪心](#2457)
#### [数学](#2457)
### [2458_移除子树后的二叉树高度](#2458)
#### [树](#2458)
#### [深度优先搜索](#2458)
#### [广度优先搜索](#2458)
#### [数组](#2458)
#### [二叉树](#2458)
### [2459_通过移动项目到空白区域来排序数组 🔒](#2459)
#### [贪心](#2459)
#### [数组](#2459)
#### [排序](#2459)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2450_应用操作后不同二进制字符串的数量 🔒
___
#### 数学
___
#### 字符串
---
### 2451_差值数组不同的字符串
___
#### 数组
___
#### 哈希表
___
#### 字符串
---
### 2452_距离字典两次编辑以内的单词
___
#### 字典树
___
#### 数组
___
#### 字符串
---
### 2453_摧毁一系列目标
___
#### 数组
___
#### 哈希表
___
#### 计数
---
### 2454_下一个更大元素 IV
___
#### 栈
___
#### 数组
___
#### 二分查找
___
#### 排序
___
#### 单调栈
___
#### 堆（优先队列）
---
### 2455_可被三整除的偶数的平均值
___
#### 数组
___
#### 数学
---
### 2456_最流行的视频创作者
___
#### 数组
___
#### 哈希表
___
#### 字符串
___
#### 排序
___
#### 堆（优先队列）
---
### 2457_美丽整数的最小增量
___
#### 贪心
___
#### 数学
---
### 2458_移除子树后的二叉树高度
___
#### 树
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 数组
___
#### 二叉树
---
### 2459_通过移动项目到空白区域来排序数组 🔒
___
#### 贪心
___
#### 数组
___
#### 排序
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 二叉树 | 单调栈 |
| 哈希表 | 堆（优先队列） | 字典树 |
| 字符串 | 广度优先搜索 | 排序 |
| 数学 | 数组 | 栈 |
| 树 | 深度优先搜索 | 计数 |
| 贪心 |  |  |

# [2450. 应用操作后不同二进制字符串的数量 🔒](https://leetcode.cn/problems/number-of-distinct-binary-strings-after-applying-operations){#2450}

{{< tabs "2450" >}}

{{% tab "python" %}}
```python
class Solution:
    def countDistinctStrings(self, s: str, k: int) -> int:
        return pow(2, len(s) - k + 1) % (10**9 + 7)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public static final int MOD = (int) 1e9 + 7;

    public int countDistinctStrings(String s, int k) {
        int ans = 1;
        for (int i = 0; i < s.length() - k + 1; ++i) {
            ans = (ans * 2) % MOD;
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
    const int mod = 1e9 + 7;

    int countDistinctStrings(string s, int k) {
        int ans = 1;
        for (int i = 0; i < s.size() - k + 1; ++i) {
            ans = (ans * 2) % mod;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countDistinctStrings(s string, k int) int {
	const mod int = 1e9 + 7
	ans := 1
	for i := 0; i < len(s)-k+1; i++ {
		ans = (ans * 2) % mod
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

<p>给定一个&nbsp;<strong>二进制&nbsp;</strong>字符串 <code>s</code> 和一个正整数 <code>k</code>。</p>

<p>你可以对字符串应用以下操作&nbsp;<strong>任意&nbsp;</strong>次数:</p>

<ul>
	<li>从 <code>s</code> 中选择任何大小为 <code>k</code> 的子字符串，将其所有字符&nbsp;<strong>翻转</strong>，即将所有 <code>1</code>&nbsp;都变成 <code>0</code>，所有 <code>0</code>&nbsp;都变成 <code>1</code>。</li>
</ul>

<p>返回<em>您可以获得的&nbsp;<strong>不同&nbsp;</strong>字符串的数量。</em>因为答案可能太大，所以对 <code>10<sup>9</sup> + 7</code>&nbsp;<strong>取模&nbsp;</strong>后返回。</p>

<p><b>注意</b>:</p>

<ul>
	<li>二进制字符串是&nbsp;<strong>仅由&nbsp;</strong>字符 <code>0</code> 和 <code>1</code> 组成的字符串。</li>
	<li>
	<p data-group="1-1">子字符串是字符串的连续部分。</p>
	</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> s = "1001", k = 3
<strong>输出:</strong> 4
<strong>解释:</strong> 我们可以获得以下字符串:
- 对字符串不应用任何操作将得到 s = "1001"。
- 对从下标 0 开始的子字符串应用一个操作，得到 s = "<u><strong>011</strong></u>1"。
- 对从下标 1 开始的子字符串应用一个操作，得到 s = "1<u><strong>110</strong></u>"。
- 对从下标 0 和 1 开始的两个子字符串都应用一个操作，得到 s = "<u><strong>0000</strong></u>"。
可以证明，我们不能获得任何其他字符串，所以答案是 4。</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> s = "10110", k = 5
<strong>输出:</strong> 2
<strong>解释:</strong> 我们可以获得以下字符串:
- 对字符串不执行任何操作，将得到 s = "10110"。
- 对整个字符串应用一个操作将得到 s = "01001"。
可以证明，我们不能获得任何其他字符串，所以答案是 2。
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s[i]</code>&nbsp;是&nbsp;<code>0</code> 或&nbsp;<code>1</code>。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数学

假设字符串 $s$ 长度为 $n$，那么长度为 $k$ 的子串共有 $n - k + 1$ 个，每个子串都可以翻转，因此共有 $2^{n - k + 1}$ 种翻转方式。

时间复杂度 $O(n)$，空间复杂度 $O(1)$。其中 $n$ 为字符串 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countDistinctStrings(self, s: str, k: int) -> int:
        return pow(2, len(s) - k + 1) % (10**9 + 7)
```

#### Java

```java
class Solution {
    public static final int MOD = (int) 1e9 + 7;

    public int countDistinctStrings(String s, int k) {
        int ans = 1;
        for (int i = 0; i < s.length() - k + 1; ++i) {
            ans = (ans * 2) % MOD;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    const int mod = 1e9 + 7;

    int countDistinctStrings(string s, int k) {
        int ans = 1;
        for (int i = 0; i < s.size() - k + 1; ++i) {
            ans = (ans * 2) % mod;
        }
        return ans;
    }
};
```

#### Go

```go
func countDistinctStrings(s string, k int) int {
	const mod int = 1e9 + 7
	ans := 1
	for i := 0; i < len(s)-k+1; i++ {
		ans = (ans * 2) % mod
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2451. 差值数组不同的字符串](https://leetcode.cn/problems/odd-string-difference){#2451}

{{< tabs "2451" >}}

{{% tab "python" %}}
```python
class Solution:
    def oddString(self, words: List[str]) -> str:
        d = defaultdict(list)
        for s in words:
            t = tuple(ord(b) - ord(a) for a, b in pairwise(s))
            d[t].append(s)
        return next(ss[0] for ss in d.values() if len(ss) == 1)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String oddString(String[] words) {
        var d = new HashMap<String, List<String>>();
        for (var s : words) {
            int m = s.length();
            var cs = new char[m - 1];
            for (int i = 0; i < m - 1; ++i) {
                cs[i] = (char) (s.charAt(i + 1) - s.charAt(i));
            }
            var t = String.valueOf(cs);
            d.putIfAbsent(t, new ArrayList<>());
            d.get(t).add(s);
        }
        for (var ss : d.values()) {
            if (ss.size() == 1) {
                return ss.get(0);
            }
        }
        return "";
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string oddString(vector<string>& words) {
        unordered_map<string, vector<string>> cnt;
        for (auto& w : words) {
            string d;
            for (int i = 0; i < w.size() - 1; ++i) {
                d += (char) (w[i + 1] - w[i]);
                d += ',';
            }
            cnt[d].emplace_back(w);
        }
        for (auto& [_, v] : cnt) {
            if (v.size() == 1) {
                return v[0];
            }
        }
        return "";
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func oddString(words []string) string {
	d := map[string][]string{}
	for _, s := range words {
		m := len(s)
		cs := make([]byte, m-1)
		for i := 0; i < m-1; i++ {
			cs[i] = s[i+1] - s[i]
		}
		t := string(cs)
		d[t] = append(d[t], s)
	}
	for _, ss := range d {
		if len(ss) == 1 {
			return ss[0]
		}
	}
	return ""
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function oddString(words: string[]): string {
    const d: Map<string, string[]> = new Map();
    for (const s of words) {
        const cs: number[] = [];
        for (let i = 0; i < s.length - 1; ++i) {
            cs.push(s[i + 1].charCodeAt(0) - s[i].charCodeAt(0));
        }
        const t = cs.join(',');
        if (!d.has(t)) {
            d.set(t, []);
        }
        d.get(t)!.push(s);
    }
    for (const [_, ss] of d) {
        if (ss.length === 1) {
            return ss[0];
        }
    }
    return '';
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashMap;

impl Solution {
    pub fn odd_string(words: Vec<String>) -> String {
        let mut h = HashMap::new();

        for w in words {
            let bytes: Vec<i32> = w
                .bytes()
                .zip(w.bytes().skip(1))
                .map(|(current, next)| (next - current) as i32)
                .collect();

            let s: String = bytes.iter().map(|&b| char::from(b as u8)).collect();

            h.entry(s).or_insert(vec![]).push(w);
        }

        for strs in h.values() {
            if strs.len() == 1 {
                return strs[0].clone();
            }
        }

        String::from("")
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串数组 <code>words</code>&nbsp;，每一个字符串长度都相同，令所有字符串的长度都为 <code>n</code>&nbsp;。</p>

<p>每个字符串&nbsp;<code>words[i]</code>&nbsp;可以被转化为一个长度为&nbsp;<code>n - 1</code>&nbsp;的&nbsp;<strong>差值整数数组</strong>&nbsp;<code>difference[i]</code>&nbsp;，其中对于&nbsp;<code>0 &lt;= j &lt;= n - 2</code>&nbsp;有&nbsp;<code>difference[i][j] = words[i][j+1] - words[i][j]</code>&nbsp;。注意两个字母的差值定义为它们在字母表中&nbsp;<strong>位置</strong>&nbsp;之差，也就是说&nbsp;<code>'a'</code>&nbsp;的位置是&nbsp;<code>0</code>&nbsp;，<code>'b'</code>&nbsp;的位置是&nbsp;<code>1</code>&nbsp;，<code>'z'</code>&nbsp;的位置是&nbsp;<code>25</code>&nbsp;。</p>

<ul>
	<li>比方说，字符串&nbsp;<code>"acb"</code>&nbsp;的差值整数数组是&nbsp;<code>[2 - 0, 1 - 2] = [2, -1]</code>&nbsp;。</li>
</ul>

<p><code>words</code>&nbsp;中所有字符串 <strong>除了一个字符串以外</strong>&nbsp;，其他字符串的差值整数数组都相同。你需要找到那个不同的字符串。</p>

<p>请你返回<em>&nbsp;</em><code>words</code>中&nbsp;<strong>差值整数数组</strong>&nbsp;不同的字符串。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>words = ["adc","wzy","abc"]
<b>输出：</b>"abc"
<b>解释：</b>
- "adc" 的差值整数数组是 [3 - 0, 2 - 3] = [3, -1] 。
- "wzy" 的差值整数数组是 [25 - 22, 24 - 25]= [3, -1] 。
- "abc" 的差值整数数组是 [1 - 0, 2 - 1] = [1, 1] 。
不同的数组是 [1, 1]，所以返回对应的字符串，"abc"。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>words = ["aaa","bob","ccc","ddd"]
<b>输出：</b>"bob"
<b>解释：</b>除了 "bob" 的差值整数数组是 [13, -13] 以外，其他字符串的差值整数数组都是 [0, 0] 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= words.length &lt;= 100</code></li>
	<li><code>n == words[i].length</code></li>
	<li><code>2 &lt;= n &lt;= 20</code></li>
	<li><code>words[i]</code>&nbsp;只含有小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表模拟

我们用哈希表 $d$ 维护字符串的差值数组和字符串的映射关系，其中差值数组为字符串的相邻字符的差值构成的数组。由于题目保证了除了一个字符串以外，其他字符串的差值数组都相同，因此我们只需要找到差值数组不同的字符串即可。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m + n)$。其中 $m$ 和 $n$ 分别为字符串的长度和字符串的个数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def oddString(self, words: List[str]) -> str:
        d = defaultdict(list)
        for s in words:
            t = tuple(ord(b) - ord(a) for a, b in pairwise(s))
            d[t].append(s)
        return next(ss[0] for ss in d.values() if len(ss) == 1)
```

#### Java

```java
class Solution {
    public String oddString(String[] words) {
        var d = new HashMap<String, List<String>>();
        for (var s : words) {
            int m = s.length();
            var cs = new char[m - 1];
            for (int i = 0; i < m - 1; ++i) {
                cs[i] = (char) (s.charAt(i + 1) - s.charAt(i));
            }
            var t = String.valueOf(cs);
            d.putIfAbsent(t, new ArrayList<>());
            d.get(t).add(s);
        }
        for (var ss : d.values()) {
            if (ss.size() == 1) {
                return ss.get(0);
            }
        }
        return "";
    }
}
```

#### C++

```cpp
class Solution {
public:
    string oddString(vector<string>& words) {
        unordered_map<string, vector<string>> cnt;
        for (auto& w : words) {
            string d;
            for (int i = 0; i < w.size() - 1; ++i) {
                d += (char) (w[i + 1] - w[i]);
                d += ',';
            }
            cnt[d].emplace_back(w);
        }
        for (auto& [_, v] : cnt) {
            if (v.size() == 1) {
                return v[0];
            }
        }
        return "";
    }
};
```

#### Go

```go
func oddString(words []string) string {
	d := map[string][]string{}
	for _, s := range words {
		m := len(s)
		cs := make([]byte, m-1)
		for i := 0; i < m-1; i++ {
			cs[i] = s[i+1] - s[i]
		}
		t := string(cs)
		d[t] = append(d[t], s)
	}
	for _, ss := range d {
		if len(ss) == 1 {
			return ss[0]
		}
	}
	return ""
}
```

#### TypeScript

```ts
function oddString(words: string[]): string {
    const d: Map<string, string[]> = new Map();
    for (const s of words) {
        const cs: number[] = [];
        for (let i = 0; i < s.length - 1; ++i) {
            cs.push(s[i + 1].charCodeAt(0) - s[i].charCodeAt(0));
        }
        const t = cs.join(',');
        if (!d.has(t)) {
            d.set(t, []);
        }
        d.get(t)!.push(s);
    }
    for (const [_, ss] of d) {
        if (ss.length === 1) {
            return ss[0];
        }
    }
    return '';
}
```

#### Rust

```rust
use std::collections::HashMap;
impl Solution {
    pub fn odd_string(words: Vec<String>) -> String {
        let n = words[0].len();
        let mut map: HashMap<String, (bool, usize)> = HashMap::new();
        for (i, word) in words.iter().enumerate() {
            let mut k = String::new();
            for j in 1..n {
                k.push_str(&(word.as_bytes()[j] - word.as_bytes()[j - 1]).to_string());
                k.push(',');
            }
            let new_is_only = !map.contains_key(&k);
            map.insert(k, (new_is_only, i));
        }
        for (is_only, i) in map.values() {
            if *is_only {
                return words[*i].clone();
            }
        }
        String::new()
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### Rust

```rust
use std::collections::HashMap;

impl Solution {
    pub fn odd_string(words: Vec<String>) -> String {
        let mut h = HashMap::new();

        for w in words {
            let bytes: Vec<i32> = w
                .bytes()
                .zip(w.bytes().skip(1))
                .map(|(current, next)| (next - current) as i32)
                .collect();

            let s: String = bytes.iter().map(|&b| char::from(b as u8)).collect();

            h.entry(s).or_insert(vec![]).push(w);
        }

        for strs in h.values() {
            if strs.len() == 1 {
                return strs[0].clone();
            }
        }

        String::from("")
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2452. 距离字典两次编辑以内的单词](https://leetcode.cn/problems/words-within-two-edits-of-dictionary){#2452}

{{< tabs "2452" >}}

{{% tab "python" %}}
```python
class Solution:
    def twoEditWords(self, queries: List[str], dictionary: List[str]) -> List[str]:
        ans = []
        for s in queries:
            for t in dictionary:
                if sum(a != b for a, b in zip(s, t)) < 3:
                    ans.append(s)
                    break
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<String> twoEditWords(String[] queries, String[] dictionary) {
        List<String> ans = new ArrayList<>();
        int n = queries[0].length();
        for (var s : queries) {
            for (var t : dictionary) {
                int cnt = 0;
                for (int i = 0; i < n; ++i) {
                    if (s.charAt(i) != t.charAt(i)) {
                        ++cnt;
                    }
                }
                if (cnt < 3) {
                    ans.add(s);
                    break;
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
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        for (auto& s : queries) {
            for (auto& t : dictionary) {
                int cnt = 0;
                for (int i = 0; i < s.size(); ++i) {
                    cnt += s[i] != t[i];
                }
                if (cnt < 3) {
                    ans.emplace_back(s);
                    break;
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
func twoEditWords(queries []string, dictionary []string) (ans []string) {
	for _, s := range queries {
		for _, t := range dictionary {
			cnt := 0
			for i := range s {
				if s[i] != t[i] {
					cnt++
				}
			}
			if cnt < 3 {
				ans = append(ans, s)
				break
			}
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function twoEditWords(queries: string[], dictionary: string[]): string[] {
    const n = queries[0].length;
    return queries.filter(s => {
        for (const t of dictionary) {
            let diff = 0;
            for (let i = 0; i < n; ++i) {
                if (s[i] !== t[i]) {
                    ++diff;
                }
            }
            if (diff < 3) {
                return true;
            }
        }
        return false;
    });
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn two_edit_words(queries: Vec<String>, dictionary: Vec<String>) -> Vec<String> {
        queries
            .into_iter()
            .filter(|s| {
                dictionary
                    .iter()
                    .any(|t| s.chars().zip(t.chars()).filter(|&(a, b)| a != b).count() < 3)
            })
            .collect()
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public IList<string> TwoEditWords(string[] queries, string[] dictionary) {
        var ans = new List<string>();
        foreach (var s in queries) {
            foreach (var t in dictionary) {
                int cnt = 0;
                for (int i = 0; i < s.Length; i++) {
                    if (s[i] != t[i]) {
                        cnt++;
                    }
                }
                if (cnt < 3) {
                    ans.Add(s);
                    break;
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

<p>给你两个字符串数组&nbsp;<code>queries</code> 和&nbsp;<code>dictionary</code>&nbsp;。数组中所有单词都只包含小写英文字母，且长度都相同。</p>

<p>一次 <strong>编辑</strong>&nbsp;中，你可以从 <code>queries</code>&nbsp;中选择一个单词，将任意一个字母修改成任何其他字母。从&nbsp;<code>queries</code>&nbsp;中找到所有满足以下条件的字符串：<strong>不超过</strong>&nbsp;两次编辑内，字符串与&nbsp;<code>dictionary</code>&nbsp;中某个字符串相同。</p>

<p>请你返回<em>&nbsp;</em><code>queries</code>&nbsp;中的单词列表，这些单词距离&nbsp;<code>dictionary</code>&nbsp;中的单词&nbsp;<strong>编辑次数</strong>&nbsp;不超过&nbsp;<strong>两次</strong>&nbsp;。单词返回的顺序需要与&nbsp;<code>queries</code>&nbsp;中原本顺序相同。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>queries = ["word","note","ants","wood"], dictionary = ["wood","joke","moat"]
<b>输出：</b>["word","note","wood"]
<strong>解释：</strong>
- 将 "word" 中的 'r' 换成 'o' ，得到 dictionary 中的单词 "wood" 。
- 将 "note" 中的 'n' 换成 'j' 且将 't' 换成 'k' ，得到 "joke" 。
- "ants" 需要超过 2 次编辑才能得到 dictionary 中的单词。
- "wood" 不需要修改（0 次编辑），就得到 dictionary 中相同的单词。
所以我们返回 ["word","note","wood"] 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>queries = ["yes"], dictionary = ["not"]
<b>输出：</b>[]
<strong>解释：</strong>
"yes" 需要超过 2 次编辑才能得到 "not" 。
所以我们返回空数组。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= queries.length, dictionary.length &lt;= 100</code></li>
	<li><code>n == queries[i].length == dictionary[j].length</code></li>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li>所有&nbsp;<code>queries[i]</code> 和&nbsp;<code>dictionary[j]</code>&nbsp;都只包含小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：暴力枚举

我们直接遍历数组 $\textit{queries}$ 中的每个单词 $s$，再遍历数组 $\textit{dictionary}$ 中的每个单词 $t$，如果存在一个单词 $t$ 与 $s$ 的编辑距离小于 $3$，则将 $s$ 加入答案数组中，然后退出内层循环的遍历。如果不存在这样的单词 $t$，则继续遍历下一个单词 $s$。

时间复杂度 $O(m \times n \times l)$，其中 $m$ 和 $n$ 分别是数组 $\textit{queries}$ 和 $\textit{dictionary}$ 的长度，而 $l$ 是单词的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def twoEditWords(self, queries: List[str], dictionary: List[str]) -> List[str]:
        ans = []
        for s in queries:
            for t in dictionary:
                if sum(a != b for a, b in zip(s, t)) < 3:
                    ans.append(s)
                    break
        return ans
```

#### Java

```java
class Solution {
    public List<String> twoEditWords(String[] queries, String[] dictionary) {
        List<String> ans = new ArrayList<>();
        int n = queries[0].length();
        for (var s : queries) {
            for (var t : dictionary) {
                int cnt = 0;
                for (int i = 0; i < n; ++i) {
                    if (s.charAt(i) != t.charAt(i)) {
                        ++cnt;
                    }
                }
                if (cnt < 3) {
                    ans.add(s);
                    break;
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
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        for (auto& s : queries) {
            for (auto& t : dictionary) {
                int cnt = 0;
                for (int i = 0; i < s.size(); ++i) {
                    cnt += s[i] != t[i];
                }
                if (cnt < 3) {
                    ans.emplace_back(s);
                    break;
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func twoEditWords(queries []string, dictionary []string) (ans []string) {
	for _, s := range queries {
		for _, t := range dictionary {
			cnt := 0
			for i := range s {
				if s[i] != t[i] {
					cnt++
				}
			}
			if cnt < 3 {
				ans = append(ans, s)
				break
			}
		}
	}
	return
}
```

#### TypeScript

```ts
function twoEditWords(queries: string[], dictionary: string[]): string[] {
    const n = queries[0].length;
    return queries.filter(s => {
        for (const t of dictionary) {
            let diff = 0;
            for (let i = 0; i < n; ++i) {
                if (s[i] !== t[i]) {
                    ++diff;
                }
            }
            if (diff < 3) {
                return true;
            }
        }
        return false;
    });
}
```

#### Rust

```rust
impl Solution {
    pub fn two_edit_words(queries: Vec<String>, dictionary: Vec<String>) -> Vec<String> {
        queries
            .into_iter()
            .filter(|s| {
                dictionary
                    .iter()
                    .any(|t| s.chars().zip(t.chars()).filter(|&(a, b)| a != b).count() < 3)
            })
            .collect()
    }
}
```

#### C#

```cs
public class Solution {
    public IList<string> TwoEditWords(string[] queries, string[] dictionary) {
        var ans = new List<string>();
        foreach (var s in queries) {
            foreach (var t in dictionary) {
                int cnt = 0;
                for (int i = 0; i < s.Length; i++) {
                    if (s[i] != t[i]) {
                        cnt++;
                    }
                }
                if (cnt < 3) {
                    ans.Add(s);
                    break;
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

# [2453. 摧毁一系列目标](https://leetcode.cn/problems/destroy-sequential-targets){#2453}

{{< tabs "2453" >}}

{{% tab "python" %}}
```python
class Solution:
    def destroyTargets(self, nums: List[int], space: int) -> int:
        cnt = Counter(v % space for v in nums)
        ans = mx = 0
        for v in nums:
            t = cnt[v % space]
            if t > mx or (t == mx and v < ans):
                ans = v
                mx = t
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int destroyTargets(int[] nums, int space) {
        Map<Integer, Integer> cnt = new HashMap<>();
        for (int v : nums) {
            v %= space;
            cnt.put(v, cnt.getOrDefault(v, 0) + 1);
        }
        int ans = 0, mx = 0;
        for (int v : nums) {
            int t = cnt.get(v % space);
            if (t > mx || (t == mx && v < ans)) {
                ans = v;
                mx = t;
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
    int destroyTargets(vector<int>& nums, int space) {
        unordered_map<int, int> cnt;
        for (int v : nums) ++cnt[v % space];
        int ans = 0, mx = 0;
        for (int v : nums) {
            int t = cnt[v % space];
            if (t > mx || (t == mx && v < ans)) {
                ans = v;
                mx = t;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func destroyTargets(nums []int, space int) int {
	cnt := map[int]int{}
	for _, v := range nums {
		cnt[v%space]++
	}
	ans, mx := 0, 0
	for _, v := range nums {
		t := cnt[v%space]
		if t > mx || (t == mx && v < ans) {
			ans = v
			mx = t
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

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的数组&nbsp;<code>nums</code>&nbsp;，它包含若干正整数，表示数轴上你需要摧毁的目标所在的位置。同时给你一个整数&nbsp;<code>space</code>&nbsp;。</p>

<p>你有一台机器可以摧毁目标。给机器 <strong>输入</strong>&nbsp;<code>nums[i]</code>&nbsp;，这台机器会摧毁所有位置在&nbsp;<code>nums[i] + c * space</code>&nbsp;的目标，其中&nbsp;<code>c</code>&nbsp;是任意非负整数。你想摧毁&nbsp;<code>nums</code>&nbsp;中 <strong>尽可能多</strong>&nbsp;的目标。</p>

<p>请你返回在摧毁数目最多的前提下，<code>nums[i]</code>&nbsp;的 <strong>最小值</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [3,7,8,1,1,5], space = 2
<b>输出：</b>1
<b>解释：</b>如果我们输入 nums[3] ，我们可以摧毁位于 1,3,5,7,9,... 这些位置的目标。
这种情况下， 我们总共可以摧毁 5 个目标（除了 nums[2]）。
没有办法摧毁多于 5 个目标，所以我们返回 nums[3] 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [1,3,5,2,4,6], space = 2
<b>输出：</b>1
<b>解释：</b>输入 nums[0] 或者 nums[3] 都会摧毁 3 个目标。
没有办法摧毁多于 3 个目标。
由于 nums[0] 是最小的可以摧毁 3 个目标的整数，所以我们返回 1 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>nums = [6,2,5], space = 100
<b>输出：</b>2
<b>解释：</b>无论我们输入哪个数字，都只能摧毁 1 个目标。输入的最小整数是 nums[1] 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= space &lt;=&nbsp;10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：取模 + 枚举

我们遍历数组 $nums$，用哈希表 $cnt$ 统计每个数模 $space$ 后的余数出现的次数。次数越多，意味着可以摧毁的目标越多。我们找到最多次数的组，取组中的最小值即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def destroyTargets(self, nums: List[int], space: int) -> int:
        cnt = Counter(v % space for v in nums)
        ans = mx = 0
        for v in nums:
            t = cnt[v % space]
            if t > mx or (t == mx and v < ans):
                ans = v
                mx = t
        return ans
```

#### Java

```java
class Solution {
    public int destroyTargets(int[] nums, int space) {
        Map<Integer, Integer> cnt = new HashMap<>();
        for (int v : nums) {
            v %= space;
            cnt.put(v, cnt.getOrDefault(v, 0) + 1);
        }
        int ans = 0, mx = 0;
        for (int v : nums) {
            int t = cnt.get(v % space);
            if (t > mx || (t == mx && v < ans)) {
                ans = v;
                mx = t;
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
    int destroyTargets(vector<int>& nums, int space) {
        unordered_map<int, int> cnt;
        for (int v : nums) ++cnt[v % space];
        int ans = 0, mx = 0;
        for (int v : nums) {
            int t = cnt[v % space];
            if (t > mx || (t == mx && v < ans)) {
                ans = v;
                mx = t;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func destroyTargets(nums []int, space int) int {
	cnt := map[int]int{}
	for _, v := range nums {
		cnt[v%space]++
	}
	ans, mx := 0, 0
	for _, v := range nums {
		t := cnt[v%space]
		if t > mx || (t == mx && v < ans) {
			ans = v
			mx = t
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

# [2454. 下一个更大元素 IV](https://leetcode.cn/problems/next-greater-element-iv){#2454}

{{< tabs "2454" >}}

{{% tab "python" %}}
```python
class Solution:
    def secondGreaterElement(self, nums: List[int]) -> List[int]:
        arr = [(x, i) for i, x in enumerate(nums)]
        arr.sort(key=lambda x: -x[0])
        sl = SortedList()
        n = len(nums)
        ans = [-1] * n
        for _, i in arr:
            j = sl.bisect_right(i)
            if j + 1 < len(sl):
                ans[i] = nums[sl[j + 1]]
            sl.add(i)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] secondGreaterElement(int[] nums) {
        int n = nums.length;
        int[] ans = new int[n];
        Arrays.fill(ans, -1);
        int[][] arr = new int[n][0];
        for (int i = 0; i < n; ++i) {
            arr[i] = new int[] {nums[i], i};
        }
        Arrays.sort(arr, (a, b) -> a[0] == b[0] ? a[1] - b[1] : b[0] - a[0]);
        TreeSet<Integer> ts = new TreeSet<>();
        for (int[] pair : arr) {
            int i = pair[1];
            Integer j = ts.higher(i);
            if (j != null && ts.higher(j) != null) {
                ans[i] = nums[ts.higher(j)];
            }
            ts.add(i);
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
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = {-nums[i], i};
        }
        sort(arr.begin(), arr.end());
        set<int> ts;
        for (auto& [_, i] : arr) {
            auto it = ts.upper_bound(i);
            if (it != ts.end() && ts.upper_bound(*it) != ts.end()) {
                ans[i] = nums[*ts.upper_bound(*it)];
            }
            ts.insert(i);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function secondGreaterElement(nums: number[]): number[] {
    const n = nums.length;
    const arr: number[][] = [];
    for (let i = 0; i < n; ++i) {
        arr.push([nums[i], i]);
    }
    arr.sort((a, b) => (a[0] == b[0] ? a[1] - b[1] : b[0] - a[0]));
    const ans = Array(n).fill(-1);
    const ts = new TreeSet<number>();
    for (const [_, i] of arr) {
        let j = ts.higher(i);
        if (j !== undefined) {
            j = ts.higher(j);
            if (j !== undefined) {
                ans[i] = nums[j];
            }
        }
        ts.add(i);
    }
    return ans;
}

type Compare<T> = (lhs: T, rhs: T) => number;

class RBTreeNode<T = number> {
    data: T;
    count: number;
    left: RBTreeNode<T> | null;
    right: RBTreeNode<T> | null;
    parent: RBTreeNode<T> | null;
    color: number;
    constructor(data: T) {
        this.data = data;
        this.left = this.right = this.parent = null;
        this.color = 0;
        this.count = 1;
    }

    sibling(): RBTreeNode<T> | null {
        if (!this.parent) return null; // sibling null if no parent
        return this.isOnLeft() ? this.parent.right : this.parent.left;
    }

    isOnLeft(): boolean {
        return this === this.parent!.left;
    }

    hasRedChild(): boolean {
        return (
            Boolean(this.left && this.left.color === 0) ||
            Boolean(this.right && this.right.color === 0)
        );
    }
}

class RBTree<T> {
    root: RBTreeNode<T> | null;
    lt: (l: T, r: T) => boolean;
    constructor(compare: Compare<T> = (l: T, r: T) => (l < r ? -1 : l > r ? 1 : 0)) {
        this.root = null;
        this.lt = (l: T, r: T) => compare(l, r) < 0;
    }

    rotateLeft(pt: RBTreeNode<T>): void {
        const right = pt.right!;
        pt.right = right.left;

        if (pt.right) pt.right.parent = pt;
        right.parent = pt.parent;

        if (!pt.parent) this.root = right;
        else if (pt === pt.parent.left) pt.parent.left = right;
        else pt.parent.right = right;

        right.left = pt;
        pt.parent = right;
    }

    rotateRight(pt: RBTreeNode<T>): void {
        const left = pt.left!;
        pt.left = left.right;

        if (pt.left) pt.left.parent = pt;
        left.parent = pt.parent;

        if (!pt.parent) this.root = left;
        else if (pt === pt.parent.left) pt.parent.left = left;
        else pt.parent.right = left;

        left.right = pt;
        pt.parent = left;
    }

    swapColor(p1: RBTreeNode<T>, p2: RBTreeNode<T>): void {
        const tmp = p1.color;
        p1.color = p2.color;
        p2.color = tmp;
    }

    swapData(p1: RBTreeNode<T>, p2: RBTreeNode<T>): void {
        const tmp = p1.data;
        p1.data = p2.data;
        p2.data = tmp;
    }

    fixAfterInsert(pt: RBTreeNode<T>): void {
        let parent = null;
        let grandParent = null;

        while (pt !== this.root && pt.color !== 1 && pt.parent?.color === 0) {
            parent = pt.parent;
            grandParent = pt.parent.parent;

            /*  Case : A
                Parent of pt is left child of Grand-parent of pt */
            if (parent === grandParent?.left) {
                const uncle = grandParent.right;

                /* Case : 1
                   The uncle of pt is also red
                   Only Recoloring required */
                if (uncle && uncle.color === 0) {
                    grandParent.color = 0;
                    parent.color = 1;
                    uncle.color = 1;
                    pt = grandParent;
                } else {
                    /* Case : 2
                       pt is right child of its parent
                       Left-rotation required */
                    if (pt === parent.right) {
                        this.rotateLeft(parent);
                        pt = parent;
                        parent = pt.parent;
                    }

                    /* Case : 3
                       pt is left child of its parent
                       Right-rotation required */
                    this.rotateRight(grandParent);
                    this.swapColor(parent!, grandParent);
                    pt = parent!;
                }
            } else {
                /* Case : B
               Parent of pt is right child of Grand-parent of pt */
                const uncle = grandParent!.left;

                /*  Case : 1
                    The uncle of pt is also red
                    Only Recoloring required */
                if (uncle != null && uncle.color === 0) {
                    grandParent!.color = 0;
                    parent.color = 1;
                    uncle.color = 1;
                    pt = grandParent!;
                } else {
                    /* Case : 2
                       pt is left child of its parent
                       Right-rotation required */
                    if (pt === parent.left) {
                        this.rotateRight(parent);
                        pt = parent;
                        parent = pt.parent;
                    }

                    /* Case : 3
                       pt is right child of its parent
                       Left-rotation required */
                    this.rotateLeft(grandParent!);
                    this.swapColor(parent!, grandParent!);
                    pt = parent!;
                }
            }
        }
        this.root!.color = 1;
    }

    delete(val: T): boolean {
        const node = this.find(val);
        if (!node) return false;
        node.count--;
        if (!node.count) this.deleteNode(node);
        return true;
    }

    deleteAll(val: T): boolean {
        const node = this.find(val);
        if (!node) return false;
        this.deleteNode(node);
        return true;
    }

    deleteNode(v: RBTreeNode<T>): void {
        const u = BSTreplace(v);

        // True when u and v are both black
        const uvBlack = (u === null || u.color === 1) && v.color === 1;
        const parent = v.parent!;

        if (!u) {
            // u is null therefore v is leaf
            if (v === this.root) this.root = null;
            // v is root, making root null
            else {
                if (uvBlack) {
                    // u and v both black
                    // v is leaf, fix double black at v
                    this.fixDoubleBlack(v);
                } else {
                    // u or v is red
                    if (v.sibling()) {
                        // sibling is not null, make it red"
                        v.sibling()!.color = 0;
                    }
                }
                // delete v from the tree
                if (v.isOnLeft()) parent.left = null;
                else parent.right = null;
            }
            return;
        }

        if (!v.left || !v.right) {
            // v has 1 child
            if (v === this.root) {
                // v is root, assign the value of u to v, and delete u
                v.data = u.data;
                v.left = v.right = null;
            } else {
                // Detach v from tree and move u up
                if (v.isOnLeft()) parent.left = u;
                else parent.right = u;
                u.parent = parent;
                if (uvBlack) this.fixDoubleBlack(u);
                // u and v both black, fix double black at u
                else u.color = 1; // u or v red, color u black
            }
            return;
        }

        // v has 2 children, swap data with successor and recurse
        this.swapData(u, v);
        this.deleteNode(u);

        // find node that replaces a deleted node in BST
        function BSTreplace(x: RBTreeNode<T>): RBTreeNode<T> | null {
            // when node have 2 children
            if (x.left && x.right) return successor(x.right);
            // when leaf
            if (!x.left && !x.right) return null;
            // when single child
            return x.left ?? x.right;
        }
        // find node that do not have a left child
        // in the subtree of the given node
        function successor(x: RBTreeNode<T>): RBTreeNode<T> {
            let temp = x;
            while (temp.left) temp = temp.left;
            return temp;
        }
    }

    fixDoubleBlack(x: RBTreeNode<T>): void {
        if (x === this.root) return; // Reached root

        const sibling = x.sibling();
        const parent = x.parent!;
        if (!sibling) {
            // No sibiling, double black pushed up
            this.fixDoubleBlack(parent);
        } else {
            if (sibling.color === 0) {
                // Sibling red
                parent.color = 0;
                sibling.color = 1;
                if (sibling.isOnLeft()) this.rotateRight(parent);
                // left case
                else this.rotateLeft(parent); // right case
                this.fixDoubleBlack(x);
            } else {
                // Sibling black
                if (sibling.hasRedChild()) {
                    // at least 1 red children
                    if (sibling.left && sibling.left.color === 0) {
                        if (sibling.isOnLeft()) {
                            // left left
                            sibling.left.color = sibling.color;
                            sibling.color = parent.color;
                            this.rotateRight(parent);
                        } else {
                            // right left
                            sibling.left.color = parent.color;
                            this.rotateRight(sibling);
                            this.rotateLeft(parent);
                        }
                    } else {
                        if (sibling.isOnLeft()) {
                            // left right
                            sibling.right!.color = parent.color;
                            this.rotateLeft(sibling);
                            this.rotateRight(parent);
                        } else {
                            // right right
                            sibling.right!.color = sibling.color;
                            sibling.color = parent.color;
                            this.rotateLeft(parent);
                        }
                    }
                    parent.color = 1;
                } else {
                    // 2 black children
                    sibling.color = 0;
                    if (parent.color === 1) this.fixDoubleBlack(parent);
                    else parent.color = 1;
                }
            }
        }
    }

    insert(data: T): boolean {
        // search for a position to insert
        let parent = this.root;
        while (parent) {
            if (this.lt(data, parent.data)) {
                if (!parent.left) break;
                else parent = parent.left;
            } else if (this.lt(parent.data, data)) {
                if (!parent.right) break;
                else parent = parent.right;
            } else break;
        }

        // insert node into parent
        const node = new RBTreeNode(data);
        if (!parent) this.root = node;
        else if (this.lt(node.data, parent.data)) parent.left = node;
        else if (this.lt(parent.data, node.data)) parent.right = node;
        else {
            parent.count++;
            return false;
        }
        node.parent = parent;
        this.fixAfterInsert(node);
        return true;
    }

    find(data: T): RBTreeNode<T> | null {
        let p = this.root;
        while (p) {
            if (this.lt(data, p.data)) {
                p = p.left;
            } else if (this.lt(p.data, data)) {
                p = p.right;
            } else break;
        }
        return p ?? null;
    }

    *inOrder(root: RBTreeNode<T> = this.root!): Generator<T, undefined, void> {
        if (!root) return;
        for (const v of this.inOrder(root.left!)) yield v;
        yield root.data;
        for (const v of this.inOrder(root.right!)) yield v;
    }

    *reverseInOrder(root: RBTreeNode<T> = this.root!): Generator<T, undefined, void> {
        if (!root) return;
        for (const v of this.reverseInOrder(root.right!)) yield v;
        yield root.data;
        for (const v of this.reverseInOrder(root.left!)) yield v;
    }
}

class TreeSet<T = number> {
    _size: number;
    tree: RBTree<T>;
    compare: Compare<T>;
    constructor(
        collection: T[] | Compare<T> = [],
        compare: Compare<T> = (l: T, r: T) => (l < r ? -1 : l > r ? 1 : 0),
    ) {
        if (typeof collection === 'function') {
            compare = collection;
            collection = [];
        }
        this._size = 0;
        this.compare = compare;
        this.tree = new RBTree(compare);
        for (const val of collection) this.add(val);
    }

    size(): number {
        return this._size;
    }

    has(val: T): boolean {
        return !!this.tree.find(val);
    }

    add(val: T): boolean {
        const successful = this.tree.insert(val);
        this._size += successful ? 1 : 0;
        return successful;
    }

    delete(val: T): boolean {
        const deleted = this.tree.deleteAll(val);
        this._size -= deleted ? 1 : 0;
        return deleted;
    }

    ceil(val: T): T | undefined {
        let p = this.tree.root;
        let higher = null;
        while (p) {
            if (this.compare(p.data, val) >= 0) {
                higher = p;
                p = p.left;
            } else {
                p = p.right;
            }
        }
        return higher?.data;
    }

    floor(val: T): T | undefined {
        let p = this.tree.root;
        let lower = null;
        while (p) {
            if (this.compare(val, p.data) >= 0) {
                lower = p;
                p = p.right;
            } else {
                p = p.left;
            }
        }
        return lower?.data;
    }

    higher(val: T): T | undefined {
        let p = this.tree.root;
        let higher = null;
        while (p) {
            if (this.compare(val, p.data) < 0) {
                higher = p;
                p = p.left;
            } else {
                p = p.right;
            }
        }
        return higher?.data;
    }

    lower(val: T): T | undefined {
        let p = this.tree.root;
        let lower = null;
        while (p) {
            if (this.compare(p.data, val) < 0) {
                lower = p;
                p = p.right;
            } else {
                p = p.left;
            }
        }
        return lower?.data;
    }

    first(): T | undefined {
        return this.tree.inOrder().next().value;
    }

    last(): T | undefined {
        return this.tree.reverseInOrder().next().value;
    }

    shift(): T | undefined {
        const first = this.first();
        if (first === undefined) return undefined;
        this.delete(first);
        return first;
    }

    pop(): T | undefined {
        const last = this.last();
        if (last === undefined) return undefined;
        this.delete(last);
        return last;
    }

    *[Symbol.iterator](): Generator<T, void, void> {
        for (const val of this.values()) yield val;
    }

    *keys(): Generator<T, void, void> {
        for (const val of this.values()) yield val;
    }

    *values(): Generator<T, undefined, void> {
        for (const val of this.tree.inOrder()) yield val;
        return undefined;
    }

    /**
     * Return a generator for reverse order traversing the set
     */
    *rvalues(): Generator<T, undefined, void> {
        for (const val of this.tree.reverseInOrder()) yield val;
        return undefined;
    }
}

class TreeMultiSet<T = number> {
    _size: number;
    tree: RBTree<T>;
    compare: Compare<T>;
    constructor(
        collection: T[] | Compare<T> = [],
        compare: Compare<T> = (l: T, r: T) => (l < r ? -1 : l > r ? 1 : 0),
    ) {
        if (typeof collection === 'function') {
            compare = collection;
            collection = [];
        }
        this._size = 0;
        this.compare = compare;
        this.tree = new RBTree(compare);
        for (const val of collection) this.add(val);
    }

    size(): number {
        return this._size;
    }

    has(val: T): boolean {
        return !!this.tree.find(val);
    }

    add(val: T): boolean {
        const successful = this.tree.insert(val);
        this._size++;
        return successful;
    }

    delete(val: T): boolean {
        const successful = this.tree.delete(val);
        if (!successful) return false;
        this._size--;
        return true;
    }

    count(val: T): number {
        const node = this.tree.find(val);
        return node ? node.count : 0;
    }

    ceil(val: T): T | undefined {
        let p = this.tree.root;
        let higher = null;
        while (p) {
            if (this.compare(p.data, val) >= 0) {
                higher = p;
                p = p.left;
            } else {
                p = p.right;
            }
        }
        return higher?.data;
    }

    floor(val: T): T | undefined {
        let p = this.tree.root;
        let lower = null;
        while (p) {
            if (this.compare(val, p.data) >= 0) {
                lower = p;
                p = p.right;
            } else {
                p = p.left;
            }
        }
        return lower?.data;
    }

    higher(val: T): T | undefined {
        let p = this.tree.root;
        let higher = null;
        while (p) {
            if (this.compare(val, p.data) < 0) {
                higher = p;
                p = p.left;
            } else {
                p = p.right;
            }
        }
        return higher?.data;
    }

    lower(val: T): T | undefined {
        let p = this.tree.root;
        let lower = null;
        while (p) {
            if (this.compare(p.data, val) < 0) {
                lower = p;
                p = p.right;
            } else {
                p = p.left;
            }
        }
        return lower?.data;
    }

    first(): T | undefined {
        return this.tree.inOrder().next().value;
    }

    last(): T | undefined {
        return this.tree.reverseInOrder().next().value;
    }

    shift(): T | undefined {
        const first = this.first();
        if (first === undefined) return undefined;
        this.delete(first);
        return first;
    }

    pop(): T | undefined {
        const last = this.last();
        if (last === undefined) return undefined;
        this.delete(last);
        return last;
    }

    *[Symbol.iterator](): Generator<T, void, void> {
        yield* this.values();
    }

    *keys(): Generator<T, void, void> {
        for (const val of this.values()) yield val;
    }

    *values(): Generator<T, undefined, void> {
        for (const val of this.tree.inOrder()) {
            let count = this.count(val);
            while (count--) yield val;
        }
        return undefined;
    }

    /**
     * Return a generator for reverse order traversing the multi-set
     */
    *rvalues(): Generator<T, undefined, void> {
        for (const val of this.tree.reverseInOrder()) {
            let count = this.count(val);
            while (count--) yield val;
        }
        return undefined;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的非负整数数组&nbsp;<code>nums</code>&nbsp;。对于&nbsp;<code>nums</code>&nbsp;中每一个整数，你必须找到对应元素的&nbsp;<strong>第二大</strong>&nbsp;整数。</p>

<p>如果&nbsp;<code>nums[j]</code>&nbsp;满足以下条件，那么我们称它为&nbsp;<code>nums[i]</code>&nbsp;的&nbsp;<strong>第二大</strong>&nbsp;整数：</p>

<ul>
	<li><code>j &gt; i</code></li>
	<li><code>nums[j] &gt; nums[i]</code></li>
	<li>恰好存在 <strong>一个</strong>&nbsp;<code>k</code>&nbsp;满足 <code>i &lt; k &lt; j</code>&nbsp;且&nbsp;<code>nums[k] &gt; nums[i]</code>&nbsp;。</li>
</ul>

<p>如果不存在&nbsp;<code>nums[j]</code>&nbsp;，那么第二大整数为&nbsp;<code>-1</code>&nbsp;。</p>

<ul>
	<li>比方说，数组&nbsp;<code>[1, 2, 4, 3]</code>&nbsp;中，<code>1</code>&nbsp;的第二大整数是&nbsp;<code>4</code>&nbsp;，<code>2</code>&nbsp;的第二大整数是&nbsp;<code>3</code>&nbsp;，<code>3</code> 和&nbsp;<code>4</code>&nbsp;的第二大整数是&nbsp;<code>-1</code>&nbsp;。</li>
</ul>

<p>请你返回一个整数数组<em>&nbsp;</em><code>answer</code>&nbsp;，其中<em>&nbsp;</em><code>answer[i]</code>是<em>&nbsp;</em><code>nums[i]</code>&nbsp;的第二大整数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [2,4,0,9,6]
<b>输出：</b>[9,6,6,-1,-1]
<strong>解释：</strong>
下标为 0 处：2 的右边，4 是大于 2 的第一个整数，9 是第二个大于 2 的整数。
下标为 1 处：4 的右边，9 是大于 4 的第一个整数，6 是第二个大于 4 的整数。
下标为 2 处：0 的右边，9 是大于 0 的第一个整数，6 是第二个大于 0 的整数。
下标为 3 处：右边不存在大于 9 的整数，所以第二大整数为 -1 。
下标为 4 处：右边不存在大于 6 的整数，所以第二大整数为 -1 。
所以我们返回 [9,6,6,-1,-1] 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [3,3]
<b>输出：</b>[-1,-1]
<strong>解释：</strong>
由于每个数右边都没有更大的数，所以我们返回 [-1,-1] 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 有序集合

我们可以将数组中的元素转成二元组 $(x, i)$，其中 $x$ 为元素的值，$i$ 为元素的下标。然后按照元素的值从大到小排序。

接下来，我们遍历排序后的数组，维护一个有序集合，其中存储的是元素的下标。当我们遍历到元素 $(x, i)$ 时，所有大于 $x$ 的元素的下标都已经在有序集合中了。我们只需要在有序集合中，找到 $i$ 的下下一个元素的下标 $j$，那么 $j$ 对应的元素就是 $x$ 的第二大元素。然后，我们将 $i$ 加入到有序集合中。继续遍历下一个元素。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def secondGreaterElement(self, nums: List[int]) -> List[int]:
        arr = [(x, i) for i, x in enumerate(nums)]
        arr.sort(key=lambda x: -x[0])
        sl = SortedList()
        n = len(nums)
        ans = [-1] * n
        for _, i in arr:
            j = sl.bisect_right(i)
            if j + 1 < len(sl):
                ans[i] = nums[sl[j + 1]]
            sl.add(i)
        return ans
```

#### Java

```java
class Solution {
    public int[] secondGreaterElement(int[] nums) {
        int n = nums.length;
        int[] ans = new int[n];
        Arrays.fill(ans, -1);
        int[][] arr = new int[n][0];
        for (int i = 0; i < n; ++i) {
            arr[i] = new int[] {nums[i], i};
        }
        Arrays.sort(arr, (a, b) -> a[0] == b[0] ? a[1] - b[1] : b[0] - a[0]);
        TreeSet<Integer> ts = new TreeSet<>();
        for (int[] pair : arr) {
            int i = pair[1];
            Integer j = ts.higher(i);
            if (j != null && ts.higher(j) != null) {
                ans[i] = nums[ts.higher(j)];
            }
            ts.add(i);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = {-nums[i], i};
        }
        sort(arr.begin(), arr.end());
        set<int> ts;
        for (auto& [_, i] : arr) {
            auto it = ts.upper_bound(i);
            if (it != ts.end() && ts.upper_bound(*it) != ts.end()) {
                ans[i] = nums[*ts.upper_bound(*it)];
            }
            ts.insert(i);
        }
        return ans;
    }
};
```

#### TypeScript

```ts
function secondGreaterElement(nums: number[]): number[] {
    const n = nums.length;
    const arr: number[][] = [];
    for (let i = 0; i < n; ++i) {
        arr.push([nums[i], i]);
    }
    arr.sort((a, b) => (a[0] == b[0] ? a[1] - b[1] : b[0] - a[0]));
    const ans = Array(n).fill(-1);
    const ts = new TreeSet<number>();
    for (const [_, i] of arr) {
        let j = ts.higher(i);
        if (j !== undefined) {
            j = ts.higher(j);
            if (j !== undefined) {
                ans[i] = nums[j];
            }
        }
        ts.add(i);
    }
    return ans;
}

type Compare<T> = (lhs: T, rhs: T) => number;

class RBTreeNode<T = number> {
    data: T;
    count: number;
    left: RBTreeNode<T> | null;
    right: RBTreeNode<T> | null;
    parent: RBTreeNode<T> | null;
    color: number;
    constructor(data: T) {
        this.data = data;
        this.left = this.right = this.parent = null;
        this.color = 0;
        this.count = 1;
    }

    sibling(): RBTreeNode<T> | null {
        if (!this.parent) return null; // sibling null if no parent
        return this.isOnLeft() ? this.parent.right : this.parent.left;
    }

    isOnLeft(): boolean {
        return this === this.parent!.left;
    }

    hasRedChild(): boolean {
        return (
            Boolean(this.left && this.left.color === 0) ||
            Boolean(this.right && this.right.color === 0)
        );
    }
}

class RBTree<T> {
    root: RBTreeNode<T> | null;
    lt: (l: T, r: T) => boolean;
    constructor(compare: Compare<T> = (l: T, r: T) => (l < r ? -1 : l > r ? 1 : 0)) {
        this.root = null;
        this.lt = (l: T, r: T) => compare(l, r) < 0;
    }

    rotateLeft(pt: RBTreeNode<T>): void {
        const right = pt.right!;
        pt.right = right.left;

        if (pt.right) pt.right.parent = pt;
        right.parent = pt.parent;

        if (!pt.parent) this.root = right;
        else if (pt === pt.parent.left) pt.parent.left = right;
        else pt.parent.right = right;

        right.left = pt;
        pt.parent = right;
    }

    rotateRight(pt: RBTreeNode<T>): void {
        const left = pt.left!;
        pt.left = left.right;

        if (pt.left) pt.left.parent = pt;
        left.parent = pt.parent;

        if (!pt.parent) this.root = left;
        else if (pt === pt.parent.left) pt.parent.left = left;
        else pt.parent.right = left;

        left.right = pt;
        pt.parent = left;
    }

    swapColor(p1: RBTreeNode<T>, p2: RBTreeNode<T>): void {
        const tmp = p1.color;
        p1.color = p2.color;
        p2.color = tmp;
    }

    swapData(p1: RBTreeNode<T>, p2: RBTreeNode<T>): void {
        const tmp = p1.data;
        p1.data = p2.data;
        p2.data = tmp;
    }

    fixAfterInsert(pt: RBTreeNode<T>): void {
        let parent = null;
        let grandParent = null;

        while (pt !== this.root && pt.color !== 1 && pt.parent?.color === 0) {
            parent = pt.parent;
            grandParent = pt.parent.parent;

            /*  Case : A
                Parent of pt is left child of Grand-parent of pt */
            if (parent === grandParent?.left) {
                const uncle = grandParent.right;

                /* Case : 1
                   The uncle of pt is also red
                   Only Recoloring required */
                if (uncle && uncle.color === 0) {
                    grandParent.color = 0;
                    parent.color = 1;
                    uncle.color = 1;
                    pt = grandParent;
                } else {
                    /* Case : 2
                       pt is right child of its parent
                       Left-rotation required */
                    if (pt === parent.right) {
                        this.rotateLeft(parent);
                        pt = parent;
                        parent = pt.parent;
                    }

                    /* Case : 3
                       pt is left child of its parent
                       Right-rotation required */
                    this.rotateRight(grandParent);
                    this.swapColor(parent!, grandParent);
                    pt = parent!;
                }
            } else {
                /* Case : B
               Parent of pt is right child of Grand-parent of pt */
                const uncle = grandParent!.left;

                /*  Case : 1
                    The uncle of pt is also red
                    Only Recoloring required */
                if (uncle != null && uncle.color === 0) {
                    grandParent!.color = 0;
                    parent.color = 1;
                    uncle.color = 1;
                    pt = grandParent!;
                } else {
                    /* Case : 2
                       pt is left child of its parent
                       Right-rotation required */
                    if (pt === parent.left) {
                        this.rotateRight(parent);
                        pt = parent;
                        parent = pt.parent;
                    }

                    /* Case : 3
                       pt is right child of its parent
                       Left-rotation required */
                    this.rotateLeft(grandParent!);
                    this.swapColor(parent!, grandParent!);
                    pt = parent!;
                }
            }
        }
        this.root!.color = 1;
    }

    delete(val: T): boolean {
        const node = this.find(val);
        if (!node) return false;
        node.count--;
        if (!node.count) this.deleteNode(node);
        return true;
    }

    deleteAll(val: T): boolean {
        const node = this.find(val);
        if (!node) return false;
        this.deleteNode(node);
        return true;
    }

    deleteNode(v: RBTreeNode<T>): void {
        const u = BSTreplace(v);

        // True when u and v are both black
        const uvBlack = (u === null || u.color === 1) && v.color === 1;
        const parent = v.parent!;

        if (!u) {
            // u is null therefore v is leaf
            if (v === this.root) this.root = null;
            // v is root, making root null
            else {
                if (uvBlack) {
                    // u and v both black
                    // v is leaf, fix double black at v
                    this.fixDoubleBlack(v);
                } else {
                    // u or v is red
                    if (v.sibling()) {
                        // sibling is not null, make it red"
                        v.sibling()!.color = 0;
                    }
                }
                // delete v from the tree
                if (v.isOnLeft()) parent.left = null;
                else parent.right = null;
            }
            return;
        }

        if (!v.left || !v.right) {
            // v has 1 child
            if (v === this.root) {
                // v is root, assign the value of u to v, and delete u
                v.data = u.data;
                v.left = v.right = null;
            } else {
                // Detach v from tree and move u up
                if (v.isOnLeft()) parent.left = u;
                else parent.right = u;
                u.parent = parent;
                if (uvBlack) this.fixDoubleBlack(u);
                // u and v both black, fix double black at u
                else u.color = 1; // u or v red, color u black
            }
            return;
        }

        // v has 2 children, swap data with successor and recurse
        this.swapData(u, v);
        this.deleteNode(u);

        // find node that replaces a deleted node in BST
        function BSTreplace(x: RBTreeNode<T>): RBTreeNode<T> | null {
            // when node have 2 children
            if (x.left && x.right) return successor(x.right);
            // when leaf
            if (!x.left && !x.right) return null;
            // when single child
            return x.left ?? x.right;
        }
        // find node that do not have a left child
        // in the subtree of the given node
        function successor(x: RBTreeNode<T>): RBTreeNode<T> {
            let temp = x;
            while (temp.left) temp = temp.left;
            return temp;
        }
    }

    fixDoubleBlack(x: RBTreeNode<T>): void {
        if (x === this.root) return; // Reached root

        const sibling = x.sibling();
        const parent = x.parent!;
        if (!sibling) {
            // No sibiling, double black pushed up
            this.fixDoubleBlack(parent);
        } else {
            if (sibling.color === 0) {
                // Sibling red
                parent.color = 0;
                sibling.color = 1;
                if (sibling.isOnLeft()) this.rotateRight(parent);
                // left case
                else this.rotateLeft(parent); // right case
                this.fixDoubleBlack(x);
            } else {
                // Sibling black
                if (sibling.hasRedChild()) {
                    // at least 1 red children
                    if (sibling.left && sibling.left.color === 0) {
                        if (sibling.isOnLeft()) {
                            // left left
                            sibling.left.color = sibling.color;
                            sibling.color = parent.color;
                            this.rotateRight(parent);
                        } else {
                            // right left
                            sibling.left.color = parent.color;
                            this.rotateRight(sibling);
                            this.rotateLeft(parent);
                        }
                    } else {
                        if (sibling.isOnLeft()) {
                            // left right
                            sibling.right!.color = parent.color;
                            this.rotateLeft(sibling);
                            this.rotateRight(parent);
                        } else {
                            // right right
                            sibling.right!.color = sibling.color;
                            sibling.color = parent.color;
                            this.rotateLeft(parent);
                        }
                    }
                    parent.color = 1;
                } else {
                    // 2 black children
                    sibling.color = 0;
                    if (parent.color === 1) this.fixDoubleBlack(parent);
                    else parent.color = 1;
                }
            }
        }
    }

    insert(data: T): boolean {
        // search for a position to insert
        let parent = this.root;
        while (parent) {
            if (this.lt(data, parent.data)) {
                if (!parent.left) break;
                else parent = parent.left;
            } else if (this.lt(parent.data, data)) {
                if (!parent.right) break;
                else parent = parent.right;
            } else break;
        }

        // insert node into parent
        const node = new RBTreeNode(data);
        if (!parent) this.root = node;
        else if (this.lt(node.data, parent.data)) parent.left = node;
        else if (this.lt(parent.data, node.data)) parent.right = node;
        else {
            parent.count++;
            return false;
        }
        node.parent = parent;
        this.fixAfterInsert(node);
        return true;
    }

    find(data: T): RBTreeNode<T> | null {
        let p = this.root;
        while (p) {
            if (this.lt(data, p.data)) {
                p = p.left;
            } else if (this.lt(p.data, data)) {
                p = p.right;
            } else break;
        }
        return p ?? null;
    }

    *inOrder(root: RBTreeNode<T> = this.root!): Generator<T, undefined, void> {
        if (!root) return;
        for (const v of this.inOrder(root.left!)) yield v;
        yield root.data;
        for (const v of this.inOrder(root.right!)) yield v;
    }

    *reverseInOrder(root: RBTreeNode<T> = this.root!): Generator<T, undefined, void> {
        if (!root) return;
        for (const v of this.reverseInOrder(root.right!)) yield v;
        yield root.data;
        for (const v of this.reverseInOrder(root.left!)) yield v;
    }
}

class TreeSet<T = number> {
    _size: number;
    tree: RBTree<T>;
    compare: Compare<T>;
    constructor(
        collection: T[] | Compare<T> = [],
        compare: Compare<T> = (l: T, r: T) => (l < r ? -1 : l > r ? 1 : 0),
    ) {
        if (typeof collection === 'function') {
            compare = collection;
            collection = [];
        }
        this._size = 0;
        this.compare = compare;
        this.tree = new RBTree(compare);
        for (const val of collection) this.add(val);
    }

    size(): number {
        return this._size;
    }

    has(val: T): boolean {
        return !!this.tree.find(val);
    }

    add(val: T): boolean {
        const successful = this.tree.insert(val);
        this._size += successful ? 1 : 0;
        return successful;
    }

    delete(val: T): boolean {
        const deleted = this.tree.deleteAll(val);
        this._size -= deleted ? 1 : 0;
        return deleted;
    }

    ceil(val: T): T | undefined {
        let p = this.tree.root;
        let higher = null;
        while (p) {
            if (this.compare(p.data, val) >= 0) {
                higher = p;
                p = p.left;
            } else {
                p = p.right;
            }
        }
        return higher?.data;
    }

    floor(val: T): T | undefined {
        let p = this.tree.root;
        let lower = null;
        while (p) {
            if (this.compare(val, p.data) >= 0) {
                lower = p;
                p = p.right;
            } else {
                p = p.left;
            }
        }
        return lower?.data;
    }

    higher(val: T): T | undefined {
        let p = this.tree.root;
        let higher = null;
        while (p) {
            if (this.compare(val, p.data) < 0) {
                higher = p;
                p = p.left;
            } else {
                p = p.right;
            }
        }
        return higher?.data;
    }

    lower(val: T): T | undefined {
        let p = this.tree.root;
        let lower = null;
        while (p) {
            if (this.compare(p.data, val) < 0) {
                lower = p;
                p = p.right;
            } else {
                p = p.left;
            }
        }
        return lower?.data;
    }

    first(): T | undefined {
        return this.tree.inOrder().next().value;
    }

    last(): T | undefined {
        return this.tree.reverseInOrder().next().value;
    }

    shift(): T | undefined {
        const first = this.first();
        if (first === undefined) return undefined;
        this.delete(first);
        return first;
    }

    pop(): T | undefined {
        const last = this.last();
        if (last === undefined) return undefined;
        this.delete(last);
        return last;
    }

    *[Symbol.iterator](): Generator<T, void, void> {
        for (const val of this.values()) yield val;
    }

    *keys(): Generator<T, void, void> {
        for (const val of this.values()) yield val;
    }

    *values(): Generator<T, undefined, void> {
        for (const val of this.tree.inOrder()) yield val;
        return undefined;
    }

    /**
     * Return a generator for reverse order traversing the set
     */
    *rvalues(): Generator<T, undefined, void> {
        for (const val of this.tree.reverseInOrder()) yield val;
        return undefined;
    }
}

class TreeMultiSet<T = number> {
    _size: number;
    tree: RBTree<T>;
    compare: Compare<T>;
    constructor(
        collection: T[] | Compare<T> = [],
        compare: Compare<T> = (l: T, r: T) => (l < r ? -1 : l > r ? 1 : 0),
    ) {
        if (typeof collection === 'function') {
            compare = collection;
            collection = [];
        }
        this._size = 0;
        this.compare = compare;
        this.tree = new RBTree(compare);
        for (const val of collection) this.add(val);
    }

    size(): number {
        return this._size;
    }

    has(val: T): boolean {
        return !!this.tree.find(val);
    }

    add(val: T): boolean {
        const successful = this.tree.insert(val);
        this._size++;
        return successful;
    }

    delete(val: T): boolean {
        const successful = this.tree.delete(val);
        if (!successful) return false;
        this._size--;
        return true;
    }

    count(val: T): number {
        const node = this.tree.find(val);
        return node ? node.count : 0;
    }

    ceil(val: T): T | undefined {
        let p = this.tree.root;
        let higher = null;
        while (p) {
            if (this.compare(p.data, val) >= 0) {
                higher = p;
                p = p.left;
            } else {
                p = p.right;
            }
        }
        return higher?.data;
    }

    floor(val: T): T | undefined {
        let p = this.tree.root;
        let lower = null;
        while (p) {
            if (this.compare(val, p.data) >= 0) {
                lower = p;
                p = p.right;
            } else {
                p = p.left;
            }
        }
        return lower?.data;
    }

    higher(val: T): T | undefined {
        let p = this.tree.root;
        let higher = null;
        while (p) {
            if (this.compare(val, p.data) < 0) {
                higher = p;
                p = p.left;
            } else {
                p = p.right;
            }
        }
        return higher?.data;
    }

    lower(val: T): T | undefined {
        let p = this.tree.root;
        let lower = null;
        while (p) {
            if (this.compare(p.data, val) < 0) {
                lower = p;
                p = p.right;
            } else {
                p = p.left;
            }
        }
        return lower?.data;
    }

    first(): T | undefined {
        return this.tree.inOrder().next().value;
    }

    last(): T | undefined {
        return this.tree.reverseInOrder().next().value;
    }

    shift(): T | undefined {
        const first = this.first();
        if (first === undefined) return undefined;
        this.delete(first);
        return first;
    }

    pop(): T | undefined {
        const last = this.last();
        if (last === undefined) return undefined;
        this.delete(last);
        return last;
    }

    *[Symbol.iterator](): Generator<T, void, void> {
        yield* this.values();
    }

    *keys(): Generator<T, void, void> {
        for (const val of this.values()) yield val;
    }

    *values(): Generator<T, undefined, void> {
        for (const val of this.tree.inOrder()) {
            let count = this.count(val);
            while (count--) yield val;
        }
        return undefined;
    }

    /**
     * Return a generator for reverse order traversing the multi-set
     */
    *rvalues(): Generator<T, undefined, void> {
        for (const val of this.tree.reverseInOrder()) {
            let count = this.count(val);
            while (count--) yield val;
        }
        return undefined;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2455. 可被三整除的偶数的平均值](https://leetcode.cn/problems/average-value-of-even-numbers-that-are-divisible-by-three){#2455}

{{< tabs "2455" >}}

{{% tab "python" %}}
```python
class Solution:
    def averageValue(self, nums: List[int]) -> int:
        s = n = 0
        for x in nums:
            if x % 6 == 0:
                s += x
                n += 1
        return 0 if n == 0 else s // n
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int averageValue(int[] nums) {
        int s = 0, n = 0;
        for (int x : nums) {
            if (x % 6 == 0) {
                s += x;
                ++n;
            }
        }
        return n == 0 ? 0 : s / n;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int averageValue(vector<int>& nums) {
        int s = 0, n = 0;
        for (int x : nums) {
            if (x % 6 == 0) {
                s += x;
                ++n;
            }
        }
        return n == 0 ? 0 : s / n;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func averageValue(nums []int) int {
	var s, n int
	for _, x := range nums {
		if x%6 == 0 {
			s += x
			n++
		}
	}
	if n == 0 {
		return 0
	}
	return s / n
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function averageValue(nums: number[]): number {
    let s = 0;
    let n = 0;
    for (const x of nums) {
        if (x % 6 === 0) {
            s += x;
            ++n;
        }
    }
    return n === 0 ? 0 : ~~(s / n);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn average_value(nums: Vec<i32>) -> i32 {
        let filtered_nums: Vec<i32> = nums.iter().cloned().filter(|&n| n % 6 == 0).collect();

        if filtered_nums.is_empty() {
            return 0;
        }

        filtered_nums.iter().sum::<i32>() / (filtered_nums.len() as i32)
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
int averageValue(int* nums, int numsSize) {
    int s = 0, n = 0;
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] % 6 == 0) {
            s += nums[i];
            ++n;
        }
    }
    return n == 0 ? 0 : s / n;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个由正整数组成的整数数组 <code>nums</code> ，返回其中可被 <code>3</code> 整除的所有偶数的平均值。</p>

<p>注意：<code>n</code> 个元素的平均值等于 <code>n</code> 个元素 <strong>求和</strong> 再除以 <code>n</code> ，结果 <strong>向下取整</strong> 到最接近的整数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,3,6,10,12,15]
<strong>输出：</strong>9
<strong>解释：</strong>6 和 12 是可以被 3 整除的偶数。(6 + 12) / 2 = 9 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,4,7,10]
<strong>输出：</strong>0
<strong>解释：</strong>不存在满足题目要求的整数，所以返回 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们注意到，可被 $3$ 整除的偶数一定是 $6$ 的倍数，因此我们只需要遍历数组，统计所有 $6$ 的倍数的和与个数，然后计算平均值即可。

时间复杂度 $O(n)$，其中 $n$ 是数组的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def averageValue(self, nums: List[int]) -> int:
        s = n = 0
        for x in nums:
            if x % 6 == 0:
                s += x
                n += 1
        return 0 if n == 0 else s // n
```

#### Java

```java
class Solution {
    public int averageValue(int[] nums) {
        int s = 0, n = 0;
        for (int x : nums) {
            if (x % 6 == 0) {
                s += x;
                ++n;
            }
        }
        return n == 0 ? 0 : s / n;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int averageValue(vector<int>& nums) {
        int s = 0, n = 0;
        for (int x : nums) {
            if (x % 6 == 0) {
                s += x;
                ++n;
            }
        }
        return n == 0 ? 0 : s / n;
    }
};
```

#### Go

```go
func averageValue(nums []int) int {
	var s, n int
	for _, x := range nums {
		if x%6 == 0 {
			s += x
			n++
		}
	}
	if n == 0 {
		return 0
	}
	return s / n
}
```

#### TypeScript

```ts
function averageValue(nums: number[]): number {
    let s = 0;
    let n = 0;
    for (const x of nums) {
        if (x % 6 === 0) {
            s += x;
            ++n;
        }
    }
    return n === 0 ? 0 : ~~(s / n);
}
```

#### Rust

```rust
impl Solution {
    pub fn average_value(nums: Vec<i32>) -> i32 {
        let mut s = 0;
        let mut n = 0;
        for x in nums.iter() {
            if x % 6 == 0 {
                s += x;
                n += 1;
            }
        }
        if n == 0 {
            return 0;
        }
        s / n
    }
}
```

#### C

```c
int averageValue(int* nums, int numsSize) {
    int s = 0, n = 0;
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] % 6 == 0) {
            s += nums[i];
            ++n;
        }
    }
    return n == 0 ? 0 : s / n;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### Rust

```rust
impl Solution {
    pub fn average_value(nums: Vec<i32>) -> i32 {
        let filtered_nums: Vec<i32> = nums.iter().cloned().filter(|&n| n % 6 == 0).collect();

        if filtered_nums.is_empty() {
            return 0;
        }

        filtered_nums.iter().sum::<i32>() / (filtered_nums.len() as i32)
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2456. 最流行的视频创作者](https://leetcode.cn/problems/most-popular-video-creator){#2456}

{{< tabs "2456" >}}

{{% tab "python" %}}
```python
class Solution:
    def mostPopularCreator(
        self, creators: List[str], ids: List[str], views: List[int]
    ) -> List[List[str]]:
        cnt = defaultdict(int)
        d = defaultdict(int)
        for k, (c, i, v) in enumerate(zip(creators, ids, views)):
            cnt[c] += v
            if c not in d or views[d[c]] < v or (views[d[c]] == v and ids[d[c]] > i):
                d[c] = k
        mx = max(cnt.values())
        return [[c, ids[d[c]]] for c, x in cnt.items() if x == mx]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<List<String>> mostPopularCreator(String[] creators, String[] ids, int[] views) {
        int n = ids.length;
        Map<String, Long> cnt = new HashMap<>(n);
        Map<String, Integer> d = new HashMap<>(n);
        for (int k = 0; k < n; ++k) {
            String c = creators[k], i = ids[k];
            long v = views[k];
            cnt.merge(c, v, Long::sum);
            if (!d.containsKey(c) || views[d.get(c)] < v
                || (views[d.get(c)] == v && ids[d.get(c)].compareTo(i) > 0)) {
                d.put(c, k);
            }
        }
        long mx = 0;
        for (long x : cnt.values()) {
            mx = Math.max(mx, x);
        }
        List<List<String>> ans = new ArrayList<>();
        for (var e : cnt.entrySet()) {
            if (e.getValue() == mx) {
                String c = e.getKey();
                ans.add(List.of(c, ids[d.get(c)]));
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
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        unordered_map<string, long long> cnt;
        unordered_map<string, int> d;
        int n = ids.size();
        for (int k = 0; k < n; ++k) {
            auto c = creators[k], id = ids[k];
            int v = views[k];
            cnt[c] += v;
            if (!d.count(c) || views[d[c]] < v || (views[d[c]] == v && ids[d[c]] > id)) {
                d[c] = k;
            }
        }
        long long mx = 0;
        for (auto& [_, x] : cnt) {
            mx = max(mx, x);
        }
        vector<vector<string>> ans;
        for (auto& [c, x] : cnt) {
            if (x == mx) {
                ans.push_back({c, ids[d[c]]});
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func mostPopularCreator(creators []string, ids []string, views []int) (ans [][]string) {
	cnt := map[string]int{}
	d := map[string]int{}
	for k, c := range creators {
		i, v := ids[k], views[k]
		cnt[c] += v
		if j, ok := d[c]; !ok || views[j] < v || (views[j] == v && ids[j] > i) {
			d[c] = k
		}
	}
	mx := 0
	for _, x := range cnt {
		if mx < x {
			mx = x
		}
	}
	for c, x := range cnt {
		if x == mx {
			ans = append(ans, []string{c, ids[d[c]]})
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function mostPopularCreator(creators: string[], ids: string[], views: number[]): string[][] {
    const cnt: Map<string, number> = new Map();
    const d: Map<string, number> = new Map();
    const n = ids.length;
    for (let k = 0; k < n; ++k) {
        const [c, i, v] = [creators[k], ids[k], views[k]];
        cnt.set(c, (cnt.get(c) ?? 0) + v);
        if (!d.has(c) || views[d.get(c)!] < v || (views[d.get(c)!] === v && ids[d.get(c)!] > i)) {
            d.set(c, k);
        }
    }
    const mx = Math.max(...cnt.values());
    const ans: string[][] = [];
    for (const [c, x] of cnt) {
        if (x === mx) {
            ans.push([c, ids[d.get(c)!]]);
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

<p>给你两个字符串数组 <code>creators</code> 和 <code>ids</code> ，和一个整数数组 <code>views</code> ，所有数组的长度都是 <code>n</code> 。平台上第 <code>i</code> 个视频者是&nbsp;<code>creator[i]</code> ，视频分配的 id 是 <code>ids[i]</code> ，且播放量为 <code>views[i]</code> 。</p>

<p>视频创作者的 <strong>流行度</strong> 是该创作者的 <strong>所有</strong> 视频的播放量的 <strong>总和</strong> 。请找出流行度 <strong>最高</strong> 创作者以及该创作者播放量 <strong>最大</strong> 的视频的 id 。</p>

<ul>
	<li>如果存在多个创作者流行度都最高，则需要找出所有符合条件的创作者。</li>
	<li>如果某个创作者存在多个播放量最高的视频，则只需要找出字典序最小的 <code>id</code> 。</li>
</ul>

<p>返回一个二维字符串数组<em> </em><code>answer</code><em> </em>，其中<em> </em><code>answer[i] = [creator<sub>i</sub>, id<sub>i</sub>]</code><em> </em>表示<em> </em><code>creator<sub>i</sub></code> 的流行度 <strong>最高</strong> 且其最流行的视频 id 是<em> </em><code>id<sub>i</sub></code><em> </em>，可以按任何顺序返回该结果<em>。</em></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>creators = ["alice","bob","alice","chris"], ids = ["one","two","three","four"], views = [5,10,5,4]
<strong>输出：</strong>[["alice","one"],["bob","two"]]
<strong>解释：</strong>
alice 的流行度是 5 + 5 = 10 。
bob 的流行度是 10 。
chris 的流行度是 4 。
alice 和 bob 是流行度最高的创作者。
bob 播放量最高的视频 id 为 "two" 。
alice 播放量最高的视频 id 是 "one" 和 "three" 。由于 "one" 的字典序比 "three" 更小，所以结果中返回的 id 是 "one" 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>creators = ["alice","alice","alice"], ids = ["a","b","c"], views = [1,2,2]
<strong>输出：</strong>[["alice","b"]]
<strong>解释：</strong>
id 为 "b" 和 "c" 的视频都满足播放量最高的条件。
由于 "b" 的字典序比 "c" 更小，所以结果中返回的 id 是 "b" 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == creators.length == ids.length == views.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= creators[i].length, ids[i].length &lt;= 5</code></li>
	<li><code>creators[i]</code> 和 <code>ids[i]</code> 仅由小写英文字母组成</li>
	<li><code>0 &lt;= views[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

我们遍历三个数组，用哈希表 $cnt$ 统计每个创作者的播放量总和，用哈希表 $d$ 记录每个创作者播放量最大的视频的下标。

然后，我们遍历哈希表 $cnt$，找出最大的播放量 $mx$；接着再次遍历哈希表 $cnt$，找出播放量为 $mx$ 的创作者，将其加入答案数组中。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为视频数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def mostPopularCreator(
        self, creators: List[str], ids: List[str], views: List[int]
    ) -> List[List[str]]:
        cnt = defaultdict(int)
        d = defaultdict(int)
        for k, (c, i, v) in enumerate(zip(creators, ids, views)):
            cnt[c] += v
            if c not in d or views[d[c]] < v or (views[d[c]] == v and ids[d[c]] > i):
                d[c] = k
        mx = max(cnt.values())
        return [[c, ids[d[c]]] for c, x in cnt.items() if x == mx]
```

#### Java

```java
class Solution {
    public List<List<String>> mostPopularCreator(String[] creators, String[] ids, int[] views) {
        int n = ids.length;
        Map<String, Long> cnt = new HashMap<>(n);
        Map<String, Integer> d = new HashMap<>(n);
        for (int k = 0; k < n; ++k) {
            String c = creators[k], i = ids[k];
            long v = views[k];
            cnt.merge(c, v, Long::sum);
            if (!d.containsKey(c) || views[d.get(c)] < v
                || (views[d.get(c)] == v && ids[d.get(c)].compareTo(i) > 0)) {
                d.put(c, k);
            }
        }
        long mx = 0;
        for (long x : cnt.values()) {
            mx = Math.max(mx, x);
        }
        List<List<String>> ans = new ArrayList<>();
        for (var e : cnt.entrySet()) {
            if (e.getValue() == mx) {
                String c = e.getKey();
                ans.add(List.of(c, ids[d.get(c)]));
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
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        unordered_map<string, long long> cnt;
        unordered_map<string, int> d;
        int n = ids.size();
        for (int k = 0; k < n; ++k) {
            auto c = creators[k], id = ids[k];
            int v = views[k];
            cnt[c] += v;
            if (!d.count(c) || views[d[c]] < v || (views[d[c]] == v && ids[d[c]] > id)) {
                d[c] = k;
            }
        }
        long long mx = 0;
        for (auto& [_, x] : cnt) {
            mx = max(mx, x);
        }
        vector<vector<string>> ans;
        for (auto& [c, x] : cnt) {
            if (x == mx) {
                ans.push_back({c, ids[d[c]]});
            }
        }
        return ans;
    }
};
```

#### Go

```go
func mostPopularCreator(creators []string, ids []string, views []int) (ans [][]string) {
	cnt := map[string]int{}
	d := map[string]int{}
	for k, c := range creators {
		i, v := ids[k], views[k]
		cnt[c] += v
		if j, ok := d[c]; !ok || views[j] < v || (views[j] == v && ids[j] > i) {
			d[c] = k
		}
	}
	mx := 0
	for _, x := range cnt {
		if mx < x {
			mx = x
		}
	}
	for c, x := range cnt {
		if x == mx {
			ans = append(ans, []string{c, ids[d[c]]})
		}
	}
	return
}
```

#### TypeScript

```ts
function mostPopularCreator(creators: string[], ids: string[], views: number[]): string[][] {
    const cnt: Map<string, number> = new Map();
    const d: Map<string, number> = new Map();
    const n = ids.length;
    for (let k = 0; k < n; ++k) {
        const [c, i, v] = [creators[k], ids[k], views[k]];
        cnt.set(c, (cnt.get(c) ?? 0) + v);
        if (!d.has(c) || views[d.get(c)!] < v || (views[d.get(c)!] === v && ids[d.get(c)!] > i)) {
            d.set(c, k);
        }
    }
    const mx = Math.max(...cnt.values());
    const ans: string[][] = [];
    for (const [c, x] of cnt) {
        if (x === mx) {
            ans.push([c, ids[d.get(c)!]]);
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

# [2457. 美丽整数的最小增量](https://leetcode.cn/problems/minimum-addition-to-make-integer-beautiful){#2457}

{{< tabs "2457" >}}

{{% tab "python" %}}
```python
class Solution:
    def makeIntegerBeautiful(self, n: int, target: int) -> int:
        def f(x: int) -> int:
            y = 0
            while x:
                y += x % 10
                x //= 10
            return y

        x = 0
        while f(n + x) > target:
            y = n + x
            p = 10
            while y % 10 == 0:
                y //= 10
                p *= 10
            x = (y // 10 + 1) * p - n
        return x
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long makeIntegerBeautiful(long n, int target) {
        long x = 0;
        while (f(n + x) > target) {
            long y = n + x;
            long p = 10;
            while (y % 10 == 0) {
                y /= 10;
                p *= 10;
            }
            x = (y / 10 + 1) * p - n;
        }
        return x;
    }

    private int f(long x) {
        int y = 0;
        while (x > 0) {
            y += x % 10;
            x /= 10;
        }
        return y;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    long long makeIntegerBeautiful(long long n, int target) {
        using ll = long long;
        auto f = [](ll x) {
            int y = 0;
            while (x) {
                y += x % 10;
                x /= 10;
            }
            return y;
        };

        ll x = 0;
        while (f(n + x) > target) {
            ll y = n + x;
            ll p = 10;
            while (y % 10 == 0) {
                y /= 10;
                p *= 10;
            }
            x = (y / 10 + 1) * p - n;
        }
        return x;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func makeIntegerBeautiful(n int64, target int) (x int64) {
	f := func(x int64) (y int) {
		for ; x > 0; x /= 10 {
			y += int(x % 10)
		}
		return
	}
	for f(n+x) > target {
		y := n + x
		var p int64 = 10
		for y%10 == 0 {
			y /= 10
			p *= 10
		}
		x = (y/10+1)*p - n
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function makeIntegerBeautiful(n: number, target: number): number {
    const f = (x: number): number => {
        let y = 0;
        for (; x > 0; x = Math.floor(x / 10)) {
            y += x % 10;
        }
        return y;
    };

    let x = 0;
    while (f(n + x) > target) {
        let y = n + x;
        let p = 10;
        while (y % 10 === 0) {
            y = Math.floor(y / 10);
            p *= 10;
        }
        x = (Math.floor(y / 10) + 1) * p - n;
    }
    return x;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个正整数 <code>n</code> 和 <code>target</code> 。</p>

<p>如果某个整数每一位上的数字相加小于或等于 <code>target</code> ，则认为这个整数是一个 <strong>美丽整数</strong> 。</p>

<p>找出并返回满足 <code>n + x</code> 是 <strong>美丽整数</strong> 的最小非负整数 <code>x</code> 。生成的输入保证总可以使 <code>n</code> 变成一个美丽整数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>n = 16, target = 6
<strong>输出：</strong>4
<strong>解释：</strong>最初，n 是 16 ，且其每一位数字的和是 1 + 6 = 7 。在加 4 之后，n 变为 20 且每一位数字的和变成 2 + 0 = 2 。可以证明无法加上一个小于 4 的非负整数使 n 变成一个美丽整数。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>n = 467, target = 6
<strong>输出：</strong>33
<strong>解释：</strong>最初，n 是 467 ，且其每一位数字的和是 4 + 6 + 7 = 17 。在加 33 之后，n 变为 500 且每一位数字的和变成 5 + 0 + 0 = 5 。可以证明无法加上一个小于 33 的非负整数使 n 变成一个美丽整数。</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>n = 1, target = 1
<strong>输出：</strong>0
<strong>解释：</strong>最初，n 是 1 ，且其每一位数字的和是 1 ，已经小于等于 target 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>12</sup></code></li>
	<li><code>1 &lt;= target &lt;= 150</code></li>
	<li>生成的输入保证总可以使 <code>n</code> 变成一个美丽整数。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心

我们定义函数 $f(x)$ 表示一个整数 $x$ 的每一位数字之和，那么题目求的是 $f(n + x) \leq target$ 的最小非负整数 $x$。

如果 $y = n+x$ 的每一位数字之和大于 $target$，那么我们可以循环通过以下操作，将 $y$ 的每一位数字之和减小到小于等于 $target$：

-   找到 $y$ 的最低位的非零数字，将其减小到 $0$，并将其高一位的数字加 $1$；
-   更新 $x$，继续上述操作，直到 $n+x$ 的每一位数字之和小于等于 $target$。

循环结束，返回 $x$ 即可。

我们可以举个例子，假设 $n=467$, $target=6$，那么 $n$ 的变化过程如下：

$$
\begin{aligned}
& 467 \rightarrow 470 \rightarrow 500 \\
\end{aligned}
$$

时间复杂度 $O(\log^2 n)$，其中 $n$ 给题目给定的整数。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def makeIntegerBeautiful(self, n: int, target: int) -> int:
        def f(x: int) -> int:
            y = 0
            while x:
                y += x % 10
                x //= 10
            return y

        x = 0
        while f(n + x) > target:
            y = n + x
            p = 10
            while y % 10 == 0:
                y //= 10
                p *= 10
            x = (y // 10 + 1) * p - n
        return x
```

#### Java

```java
class Solution {
    public long makeIntegerBeautiful(long n, int target) {
        long x = 0;
        while (f(n + x) > target) {
            long y = n + x;
            long p = 10;
            while (y % 10 == 0) {
                y /= 10;
                p *= 10;
            }
            x = (y / 10 + 1) * p - n;
        }
        return x;
    }

    private int f(long x) {
        int y = 0;
        while (x > 0) {
            y += x % 10;
            x /= 10;
        }
        return y;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long makeIntegerBeautiful(long long n, int target) {
        using ll = long long;
        auto f = [](ll x) {
            int y = 0;
            while (x) {
                y += x % 10;
                x /= 10;
            }
            return y;
        };

        ll x = 0;
        while (f(n + x) > target) {
            ll y = n + x;
            ll p = 10;
            while (y % 10 == 0) {
                y /= 10;
                p *= 10;
            }
            x = (y / 10 + 1) * p - n;
        }
        return x;
    }
};
```

#### Go

```go
func makeIntegerBeautiful(n int64, target int) (x int64) {
	f := func(x int64) (y int) {
		for ; x > 0; x /= 10 {
			y += int(x % 10)
		}
		return
	}
	for f(n+x) > target {
		y := n + x
		var p int64 = 10
		for y%10 == 0 {
			y /= 10
			p *= 10
		}
		x = (y/10+1)*p - n
	}
	return
}
```

#### TypeScript

```ts
function makeIntegerBeautiful(n: number, target: number): number {
    const f = (x: number): number => {
        let y = 0;
        for (; x > 0; x = Math.floor(x / 10)) {
            y += x % 10;
        }
        return y;
    };

    let x = 0;
    while (f(n + x) > target) {
        let y = n + x;
        let p = 10;
        while (y % 10 === 0) {
            y = Math.floor(y / 10);
            p *= 10;
        }
        x = (Math.floor(y / 10) + 1) * p - n;
    }
    return x;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2458. 移除子树后的二叉树高度](https://leetcode.cn/problems/height-of-binary-tree-after-subtree-removal-queries){#2458}

{{< tabs "2458" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def treeQueries(self, root: Optional[TreeNode], queries: List[int]) -> List[int]:
        def f(root):
            if root is None:
                return 0
            l, r = f(root.left), f(root.right)
            d[root] = 1 + max(l, r)
            return d[root]

        def dfs(root, depth, rest):
            if root is None:
                return
            depth += 1
            res[root.val] = rest
            dfs(root.left, depth, max(rest, depth + d[root.right]))
            dfs(root.right, depth, max(rest, depth + d[root.left]))

        d = defaultdict(int)
        f(root)
        res = [0] * (len(d) + 1)
        dfs(root, -1, 0)
        return [res[v] for v in queries]
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
    private Map<TreeNode, Integer> d = new HashMap<>();
    private int[] res;

    public int[] treeQueries(TreeNode root, int[] queries) {
        f(root);
        res = new int[d.size() + 1];
        d.put(null, 0);
        dfs(root, -1, 0);
        int m = queries.length;
        int[] ans = new int[m];
        for (int i = 0; i < m; ++i) {
            ans[i] = res[queries[i]];
        }
        return ans;
    }

    private void dfs(TreeNode root, int depth, int rest) {
        if (root == null) {
            return;
        }
        ++depth;
        res[root.val] = rest;
        dfs(root.left, depth, Math.max(rest, depth + d.get(root.right)));
        dfs(root.right, depth, Math.max(rest, depth + d.get(root.left)));
    }

    private int f(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int l = f(root.left), r = f(root.right);
        d.put(root, 1 + Math.max(l, r));
        return d.get(root);
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
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        unordered_map<TreeNode*, int> d;
        function<int(TreeNode*)> f = [&](TreeNode* root) -> int {
            if (!root) return 0;
            int l = f(root->left), r = f(root->right);
            d[root] = 1 + max(l, r);
            return d[root];
        };
        f(root);
        vector<int> res(d.size() + 1);
        function<void(TreeNode*, int, int)> dfs = [&](TreeNode* root, int depth, int rest) {
            if (!root) return;
            ++depth;
            res[root->val] = rest;
            dfs(root->left, depth, max(rest, depth + d[root->right]));
            dfs(root->right, depth, max(rest, depth + d[root->left]));
        };
        dfs(root, -1, 0);
        vector<int> ans;
        for (int v : queries) ans.emplace_back(res[v]);
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
func treeQueries(root *TreeNode, queries []int) (ans []int) {
	d := map[*TreeNode]int{}
	var f func(*TreeNode) int
	f = func(root *TreeNode) int {
		if root == nil {
			return 0
		}
		l, r := f(root.Left), f(root.Right)
		d[root] = 1 + max(l, r)
		return d[root]
	}
	f(root)
	res := make([]int, len(d)+1)
	var dfs func(*TreeNode, int, int)
	dfs = func(root *TreeNode, depth, rest int) {
		if root == nil {
			return
		}
		depth++
		res[root.Val] = rest
		dfs(root.Left, depth, max(rest, depth+d[root.Right]))
		dfs(root.Right, depth, max(rest, depth+d[root.Left]))
	}
	dfs(root, -1, 0)
	for _, v := range queries {
		ans = append(ans, res[v])
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function treeQueries(root: TreeNode | null, queries: number[]): number[] {
    const ans: number[] = [];
    const levels: Map<number, [number, number][]> = new Map();
    const valToLevel = new Map<number, number>();

    const dfs = (node: TreeNode | null, level = 0): number => {
        if (!node) return level - 1;

        const max = Math.max(dfs(node.left, level + 1), dfs(node.right, level + 1));

        if (!levels.has(level)) {
            levels.set(level, []);
        }
        levels.get(level)?.push([max, node.val]);
        valToLevel.set(node.val, level);

        return max;
    };

    dfs(root, 0);

    for (const [_, l] of levels) {
        l.sort(([a], [b]) => b - a);
    }

    for (const q of queries) {
        const level = valToLevel.get(q)!;
        const maxes = levels.get(level)!;

        if (maxes.length === 1) {
            ans.push(level - 1);
        } else {
            const [val0, max0, max1] = [maxes[0][1], maxes[0][0], maxes[1][0]];
            const max = val0 === q ? max1 : max0;
            ans.push(max);
        }
    }

    return ans;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
function treeQueries(root, queries) {
    const ans = [];
    const levels = new Map();
    const valToLevel = new Map();

    const dfs = (node, level = 0) => {
        if (!node) return level - 1;

        const max = Math.max(dfs(node.left, level + 1), dfs(node.right, level + 1));

        if (!levels.has(level)) {
            levels.set(level, []);
        }
        levels.get(level)?.push([max, node.val]);
        valToLevel.set(node.val, level);

        return max;
    };

    dfs(root, 0);

    for (const [_, l] of levels) {
        l.sort(([a], [b]) => b - a);
    }

    for (const q of queries) {
        const level = valToLevel.get(q);
        const maxes = levels.get(level);

        if (maxes.length === 1) {
            ans.push(level - 1);
        } else {
            const [val0, max0, max1] = [maxes[0][1], maxes[0][0], maxes[1][0]];
            const max = val0 === q ? max1 : max0;
            ans.push(max);
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

<p>给你一棵 <strong>二叉树</strong> 的根节点 <code>root</code> ，树中有 <code>n</code> 个节点。每个节点都可以被分配一个从 <code>1</code> 到 <code>n</code> 且互不相同的值。另给你一个长度为 <code>m</code> 的数组 <code>queries</code> 。</p>

<p>你必须在树上执行 <code>m</code> 个 <strong>独立</strong> 的查询，其中第 <code>i</code> 个查询你需要执行以下操作：</p>

<ul>
	<li>从树中 <strong>移除</strong> 以 <code>queries[i]</code> 的值作为根节点的子树。题目所用测试用例保证 <code>queries[i]</code> <strong>不</strong> 等于根节点的值。</li>
</ul>

<p>返回一个长度为 <code>m</code> 的数组<em> </em><code>answer</code><em> </em>，其中<em> </em><code>answer[i]</code><em> </em>是执行第 <code>i</code> 个查询后树的高度。</p>

<p><strong>注意：</strong></p>

<ul>
	<li>查询之间是独立的，所以在每个查询执行后，树会回到其 <strong>初始</strong> 状态。</li>
	<li>树的高度是从根到树中某个节点的 <strong>最长简单路径中的边数</strong> 。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2400-2499/2458.Height%20of%20Binary%20Tree%20After%20Subtree%20Removal%20Queries/images/binaryytreeedrawio-1.png" style="width: 495px; height: 281px;" /></p>

<pre>
<strong>输入：</strong>root = [1,3,4,2,null,6,5,null,null,null,null,null,7], queries = [4]
<strong>输出：</strong>[2]
<strong>解释：</strong>上图展示了从树中移除以 4 为根节点的子树。
树的高度是 2（路径为 1 -&gt; 3 -&gt; 2）。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2400-2499/2458.Height%20of%20Binary%20Tree%20After%20Subtree%20Removal%20Queries/images/binaryytreeedrawio-2.png" style="width: 301px; height: 284px;" /></p>

<pre>
<strong>输入：</strong>root = [5,8,9,2,1,3,7,4,6], queries = [3,2,4,8]
<strong>输出：</strong>[3,2,3,2]
<strong>解释：</strong>执行下述查询：
- 移除以 3 为根节点的子树。树的高度变为 3（路径为 5 -&gt; 8 -&gt; 2 -&gt; 4）。
- 移除以 2 为根节点的子树。树的高度变为 2（路径为 5 -&gt; 8 -&gt; 1）。
- 移除以 4 为根节点的子树。树的高度变为 3（路径为 5 -&gt; 8 -&gt; 2 -&gt; 6）。
- 移除以 8 为根节点的子树。树的高度变为 2（路径为 5 -&gt; 9 -&gt; 3）。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点的数目是 <code>n</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= Node.val &lt;= n</code></li>
	<li>树中的所有值 <strong>互不相同</strong></li>
	<li><code>m == queries.length</code></li>
	<li><code>1 &lt;= m &lt;= min(n, 10<sup>4</sup>)</code></li>
	<li><code>1 &lt;= queries[i] &lt;= n</code></li>
	<li><code>queries[i] != root.val</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：两次 DFS

我们先通过一次 DFS 遍历的深度，存放在哈希表 $d$ 中，其中 $d[x]$ 表示节点 $x$ 的深度。

然后我们设计一个函数 $dfs(root, depth, rest)$，其中：

-   `root` 表示当前节点；
-   `depth` 表示当前节点的深度；
-   `rest` 表示删除当前节点后，树的高度。

函数的计算逻辑如下：

如果节点为空，直接返回。否则，我们将 `depth` 加 $1$，然后将 `rest` 保存在 `res` 中。

接着递归遍历左右子树。

递归左子树前，我们计算从根节点到当前节点右子树最深节点的就，即 $depth+d[root.right]$，然后将其与 `rest` 比较，取较大值作为左子树的 `rest`。

递归右子树前，我们计算从根节点到当前节点左子树最深节点的就，即 $depth+d[root.left]$，然后将其与 `rest` 比较，取较大值作为右子树的 `rest`。

最后返回每个查询节点对应的结果值即可。

时间复杂度 $O(n+m)$，空间复杂度 $O(n)$。其中 $n$ 和 $m$ 分别是树的节点数和查询数。

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
    def treeQueries(self, root: Optional[TreeNode], queries: List[int]) -> List[int]:
        def f(root):
            if root is None:
                return 0
            l, r = f(root.left), f(root.right)
            d[root] = 1 + max(l, r)
            return d[root]

        def dfs(root, depth, rest):
            if root is None:
                return
            depth += 1
            res[root.val] = rest
            dfs(root.left, depth, max(rest, depth + d[root.right]))
            dfs(root.right, depth, max(rest, depth + d[root.left]))

        d = defaultdict(int)
        f(root)
        res = [0] * (len(d) + 1)
        dfs(root, -1, 0)
        return [res[v] for v in queries]
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
    private Map<TreeNode, Integer> d = new HashMap<>();
    private int[] res;

    public int[] treeQueries(TreeNode root, int[] queries) {
        f(root);
        res = new int[d.size() + 1];
        d.put(null, 0);
        dfs(root, -1, 0);
        int m = queries.length;
        int[] ans = new int[m];
        for (int i = 0; i < m; ++i) {
            ans[i] = res[queries[i]];
        }
        return ans;
    }

    private void dfs(TreeNode root, int depth, int rest) {
        if (root == null) {
            return;
        }
        ++depth;
        res[root.val] = rest;
        dfs(root.left, depth, Math.max(rest, depth + d.get(root.right)));
        dfs(root.right, depth, Math.max(rest, depth + d.get(root.left)));
    }

    private int f(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int l = f(root.left), r = f(root.right);
        d.put(root, 1 + Math.max(l, r));
        return d.get(root);
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
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        unordered_map<TreeNode*, int> d;
        function<int(TreeNode*)> f = [&](TreeNode* root) -> int {
            if (!root) return 0;
            int l = f(root->left), r = f(root->right);
            d[root] = 1 + max(l, r);
            return d[root];
        };
        f(root);
        vector<int> res(d.size() + 1);
        function<void(TreeNode*, int, int)> dfs = [&](TreeNode* root, int depth, int rest) {
            if (!root) return;
            ++depth;
            res[root->val] = rest;
            dfs(root->left, depth, max(rest, depth + d[root->right]));
            dfs(root->right, depth, max(rest, depth + d[root->left]));
        };
        dfs(root, -1, 0);
        vector<int> ans;
        for (int v : queries) ans.emplace_back(res[v]);
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
func treeQueries(root *TreeNode, queries []int) (ans []int) {
	d := map[*TreeNode]int{}
	var f func(*TreeNode) int
	f = func(root *TreeNode) int {
		if root == nil {
			return 0
		}
		l, r := f(root.Left), f(root.Right)
		d[root] = 1 + max(l, r)
		return d[root]
	}
	f(root)
	res := make([]int, len(d)+1)
	var dfs func(*TreeNode, int, int)
	dfs = func(root *TreeNode, depth, rest int) {
		if root == nil {
			return
		}
		depth++
		res[root.Val] = rest
		dfs(root.Left, depth, max(rest, depth+d[root.Right]))
		dfs(root.Right, depth, max(rest, depth+d[root.Left]))
	}
	dfs(root, -1, 0)
	for _, v := range queries {
		ans = append(ans, res[v])
	}
	return
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：一次 DFS + 排序

<!-- tabs:start -->

#### TypeScript

```ts
function treeQueries(root: TreeNode | null, queries: number[]): number[] {
    const ans: number[] = [];
    const levels: Map<number, [number, number][]> = new Map();
    const valToLevel = new Map<number, number>();

    const dfs = (node: TreeNode | null, level = 0): number => {
        if (!node) return level - 1;

        const max = Math.max(dfs(node.left, level + 1), dfs(node.right, level + 1));

        if (!levels.has(level)) {
            levels.set(level, []);
        }
        levels.get(level)?.push([max, node.val]);
        valToLevel.set(node.val, level);

        return max;
    };

    dfs(root, 0);

    for (const [_, l] of levels) {
        l.sort(([a], [b]) => b - a);
    }

    for (const q of queries) {
        const level = valToLevel.get(q)!;
        const maxes = levels.get(level)!;

        if (maxes.length === 1) {
            ans.push(level - 1);
        } else {
            const [val0, max0, max1] = [maxes[0][1], maxes[0][0], maxes[1][0]];
            const max = val0 === q ? max1 : max0;
            ans.push(max);
        }
    }

    return ans;
}
```

#### JavaScript

```js
function treeQueries(root, queries) {
    const ans = [];
    const levels = new Map();
    const valToLevel = new Map();

    const dfs = (node, level = 0) => {
        if (!node) return level - 1;

        const max = Math.max(dfs(node.left, level + 1), dfs(node.right, level + 1));

        if (!levels.has(level)) {
            levels.set(level, []);
        }
        levels.get(level)?.push([max, node.val]);
        valToLevel.set(node.val, level);

        return max;
    };

    dfs(root, 0);

    for (const [_, l] of levels) {
        l.sort(([a], [b]) => b - a);
    }

    for (const q of queries) {
        const level = valToLevel.get(q);
        const maxes = levels.get(level);

        if (maxes.length === 1) {
            ans.push(level - 1);
        } else {
            const [val0, max0, max1] = [maxes[0][1], maxes[0][0], maxes[1][0]];
            const max = val0 === q ? max1 : max0;
            ans.push(max);
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

# [2459. 通过移动项目到空白区域来排序数组 🔒](https://leetcode.cn/problems/sort-array-by-moving-items-to-empty-space){#2459}

{{< tabs "2459" >}}

{{% tab "python" %}}
```python
class Solution:
    def sortArray(self, nums: List[int]) -> int:
        def f(nums, k):
            vis = [False] * n
            cnt = 0
            for i, v in enumerate(nums):
                if i == v or vis[i]:
                    continue
                cnt += 1
                j = i
                while not vis[j]:
                    vis[j] = True
                    cnt += 1
                    j = nums[j]
            return cnt - 2 * (nums[k] != k)

        n = len(nums)
        a = f(nums, 0)
        b = f([(v - 1 + n) % n for v in nums], n - 1)
        return min(a, b)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int sortArray(int[] nums) {
        int n = nums.length;
        int[] arr = new int[n];
        for (int i = 0; i < n; ++i) {
            arr[i] = (nums[i] - 1 + n) % n;
        }
        int a = f(nums, 0);
        int b = f(arr, n - 1);
        return Math.min(a, b);
    }

    private int f(int[] nums, int k) {
        boolean[] vis = new boolean[nums.length];
        int cnt = 0;
        for (int i = 0; i < nums.length; ++i) {
            if (i == nums[i] || vis[i]) {
                continue;
            }
            ++cnt;
            int j = nums[i];
            while (!vis[j]) {
                vis[j] = true;
                ++cnt;
                j = nums[j];
            }
        }
        if (nums[k] != k) {
            cnt -= 2;
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
    int sortArray(vector<int>& nums) {
        int n = nums.size();
        auto f = [&](vector<int>& nums, int k) {
            vector<bool> vis(n);
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                if (i == nums[i] || vis[i]) continue;
                int j = i;
                ++cnt;
                while (!vis[j]) {
                    vis[j] = true;
                    ++cnt;
                    j = nums[j];
                }
            }
            if (nums[k] != k) cnt -= 2;
            return cnt;
        };

        int a = f(nums, 0);
        vector<int> arr = nums;
        for (int& v : arr) v = (v - 1 + n) % n;
        int b = f(arr, n - 1);
        return min(a, b);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func sortArray(nums []int) int {
	n := len(nums)
	f := func(nums []int, k int) int {
		vis := make([]bool, n)
		cnt := 0
		for i, v := range nums {
			if i == v || vis[i] {
				continue
			}
			cnt++
			j := i
			for !vis[j] {
				vis[j] = true
				cnt++
				j = nums[j]
			}
		}
		if nums[k] != k {
			cnt -= 2
		}
		return cnt
	}
	a := f(nums, 0)
	arr := make([]int, n)
	for i, v := range nums {
		arr[i] = (v - 1 + n) % n
	}
	b := f(arr, n-1)
	return min(a, b)
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个大小为 <code>n</code> 的整数数组 <code>nums</code>，其中包含从 <code>0</code> 到 <code>n - 1</code>&nbsp;(<strong>包含边界</strong>) 的&nbsp;<strong>每个&nbsp;</strong>元素。从 <code>1</code> 到 <code>n - 1</code> 的每一个元素都代表一项目，元素 <code>0</code> 代表一个空白区域。</p>

<p>在一个操作中，您可以将&nbsp;<strong>任何&nbsp;</strong>项目移动到空白区域。如果所有项目的编号都是&nbsp;<strong>升序&nbsp;</strong>的，并且空格在数组的开头或结尾，则认为 <code>nums</code> 已排序。</p>

<p data-group="1-1">例如，如果 <code>n = 4</code>，则 <code>nums</code> 按以下条件排序:</p>

<ul>
	<li><code>nums = [0,1,2,3]</code>&nbsp;或</li>
	<li><code>nums = [1,2,3,0]</code></li>
</ul>

<p>...否则被认为是无序的。</p>

<p>返回<em>排序&nbsp;<code>nums</code> 所需的最小操作数。</em></p>

<p>&nbsp;</p>

<p><strong class="example">示例 1:</strong></p>

<pre>
<strong>输入:</strong> nums = [4,2,0,3,1]
<strong>输出:</strong> 3
<strong>解释:</strong>
- 将项目 2 移动到空白区域。现在，nums =[4,0,2,3,1]。
- 将项目 1 移动到空白区域。现在，nums =[4,1,2,3,0]。
- 将项目 4 移动到空白区域。现在，nums =[0,1,2,3,4]。
可以证明，3 是所需的最小操作数。
</pre>

<p><strong class="example">示例 2:</strong></p>

<pre>
<strong>输入:</strong> nums = [1,2,3,4,0]
<strong>输出:</strong> 0
<strong>解释:</strong> nums 已经排序了，所以返回 0。</pre>

<p><strong class="example">示例 3:</strong></p>

<pre>
<strong>输入:</strong> nums = [1,0,2,4,3]
<strong>输出:</strong> 2
<strong>解释:</strong>
- 将项目 2 移动到空白区域。现在，nums =[1,2,0,4,3]。
- 将项目 3 移动到空白区域。现在，nums =[1,2,3,4,0]。
可以证明，2 是所需的最小操作数。
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt; n</code></li>
	<li><code>nums</code> 的所有值都是&nbsp;<strong>唯一&nbsp;</strong>的。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：置换环

一个长度为 $m$ 的置换环，如果 $0$ 在环中，那么交换次数为 $m-1$，否则交换次数为 $m+1$。

我们找到所有置换环，先按照交换次数为 $m+1$ 计算总的次数，然后判断 $0$ 是否错位，若是，说明 $0$ 在置换环中，那么总的次数减 $2$。

这里 $0$ 可以在 $0$ 位置，也可以在 $n-1$ 位置，我们取这两种情况的最小值。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def sortArray(self, nums: List[int]) -> int:
        def f(nums, k):
            vis = [False] * n
            cnt = 0
            for i, v in enumerate(nums):
                if i == v or vis[i]:
                    continue
                cnt += 1
                j = i
                while not vis[j]:
                    vis[j] = True
                    cnt += 1
                    j = nums[j]
            return cnt - 2 * (nums[k] != k)

        n = len(nums)
        a = f(nums, 0)
        b = f([(v - 1 + n) % n for v in nums], n - 1)
        return min(a, b)
```

#### Java

```java
class Solution {
    public int sortArray(int[] nums) {
        int n = nums.length;
        int[] arr = new int[n];
        for (int i = 0; i < n; ++i) {
            arr[i] = (nums[i] - 1 + n) % n;
        }
        int a = f(nums, 0);
        int b = f(arr, n - 1);
        return Math.min(a, b);
    }

    private int f(int[] nums, int k) {
        boolean[] vis = new boolean[nums.length];
        int cnt = 0;
        for (int i = 0; i < nums.length; ++i) {
            if (i == nums[i] || vis[i]) {
                continue;
            }
            ++cnt;
            int j = nums[i];
            while (!vis[j]) {
                vis[j] = true;
                ++cnt;
                j = nums[j];
            }
        }
        if (nums[k] != k) {
            cnt -= 2;
        }
        return cnt;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int sortArray(vector<int>& nums) {
        int n = nums.size();
        auto f = [&](vector<int>& nums, int k) {
            vector<bool> vis(n);
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                if (i == nums[i] || vis[i]) continue;
                int j = i;
                ++cnt;
                while (!vis[j]) {
                    vis[j] = true;
                    ++cnt;
                    j = nums[j];
                }
            }
            if (nums[k] != k) cnt -= 2;
            return cnt;
        };

        int a = f(nums, 0);
        vector<int> arr = nums;
        for (int& v : arr) v = (v - 1 + n) % n;
        int b = f(arr, n - 1);
        return min(a, b);
    }
};
```

#### Go

```go
func sortArray(nums []int) int {
	n := len(nums)
	f := func(nums []int, k int) int {
		vis := make([]bool, n)
		cnt := 0
		for i, v := range nums {
			if i == v || vis[i] {
				continue
			}
			cnt++
			j := i
			for !vis[j] {
				vis[j] = true
				cnt++
				j = nums[j]
			}
		}
		if nums[k] != k {
			cnt -= 2
		}
		return cnt
	}
	a := f(nums, 0)
	arr := make([]int, n)
	for i, v := range nums {
		arr[i] = (v - 1 + n) % n
	}
	b := f(arr, n-1)
	return min(a, b)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
