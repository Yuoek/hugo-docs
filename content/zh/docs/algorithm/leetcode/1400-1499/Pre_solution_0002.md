---
title: "1410_HTML 实体解析器"
date: 2025-10-08T18:37:18+08:00
weight: 2
tags: [前缀和, 动态规划, 哈希表, 回溯, 字符串, 排序, 数学, 数据库, 数组, 有序集合, 计数, 贪心]
---

{{< markmap >}}
### [1410_HTML 实体解析器](#1410)
#### [哈希表](#1410)
#### [字符串](#1410)
### [1411_给 N x 3 网格图涂色的方案数](#1411)
#### [动态规划](#1411)
### [1412_查找成绩处于中游的学生 🔒](#1412)
#### [数据库](#1412)
### [1413_逐步求和得到正数的最小值](#1413)
#### [数组](#1413)
#### [前缀和](#1413)
### [1414_和为 K 的最少斐波那契数字数目](#1414)
#### [贪心](#1414)
#### [数学](#1414)
### [1415_长度为 n 的开心字符串中字典序第 k 小的字符串](#1415)
#### [字符串](#1415)
#### [回溯](#1415)
### [1416_恢复数组](#1416)
#### [字符串](#1416)
#### [动态规划](#1416)
### [1417_重新格式化字符串](#1417)
#### [字符串](#1417)
### [1418_点菜展示表](#1418)
#### [数组](#1418)
#### [哈希表](#1418)
#### [字符串](#1418)
#### [有序集合](#1418)
#### [排序](#1418)
### [1419_数青蛙](#1419)
#### [字符串](#1419)
#### [计数](#1419)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1410_HTML 实体解析器
___
#### 哈希表
___
#### 字符串
---
### 1411_给 N x 3 网格图涂色的方案数
___
#### 动态规划
---
### 1412_查找成绩处于中游的学生 🔒
___
#### 数据库
---
### 1413_逐步求和得到正数的最小值
___
#### 数组
___
#### 前缀和
---
### 1414_和为 K 的最少斐波那契数字数目
___
#### 贪心
___
#### 数学
---
### 1415_长度为 n 的开心字符串中字典序第 k 小的字符串
___
#### 字符串
___
#### 回溯
---
### 1416_恢复数组
___
#### 字符串
___
#### 动态规划
---
### 1417_重新格式化字符串
___
#### 字符串
---
### 1418_点菜展示表
___
#### 数组
___
#### 哈希表
___
#### 字符串
___
#### 有序集合
___
#### 排序
---
### 1419_数青蛙
___
#### 字符串
___
#### 计数
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 前缀和 | 动态规划 | 哈希表 |
| 回溯 | 字符串 | 排序 |
| 数学 | 数据库 | 数组 |
| 有序集合 | 计数 | 贪心 |

# [1410. HTML 实体解析器](https://leetcode.cn/problems/html-entity-parser){#1410}

{{< tabs "1410" >}}

{{% tab "python" %}}
```python
class Solution:
    def entityParser(self, text: str) -> str:
        d = {
            '&quot;': '"',
            '&apos;': "'",
            '&amp;': "&",
            "&gt;": '>',
            "&lt;": '<',
            "&frasl;": '/',
        }
        i, n = 0, len(text)
        ans = []
        while i < n:
            for l in range(1, 8):
                j = i + l
                if text[i:j] in d:
                    ans.append(d[text[i:j]])
                    i = j
                    break
            else:
                ans.append(text[i])
                i += 1
        return ''.join(ans)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String entityParser(String text) {
        Map<String, String> d = new HashMap<>();
        d.put("&quot;", "\"");
        d.put("&apos;", "'");
        d.put("&amp;", "&");
        d.put("&gt;", ">");
        d.put("&lt;", "<");
        d.put("&frasl;", "/");
        StringBuilder ans = new StringBuilder();
        int i = 0;
        int n = text.length();
        while (i < n) {
            boolean found = false;
            for (int l = 1; l < 8; ++l) {
                int j = i + l;
                if (j <= n) {
                    String t = text.substring(i, j);
                    if (d.containsKey(t)) {
                        ans.append(d.get(t));
                        i = j;
                        found = true;
                        break;
                    }
                }
            }
            if (!found) {
                ans.append(text.charAt(i++));
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
    string entityParser(string text) {
        unordered_map<string, string> d = {
            {"&quot;", "\""},
            {"&apos;", "'"},
            {"&amp;", "&"},
            {"&gt;", ">"},
            {"&lt;", "<"},
            {"&frasl;", "/"},
        };
        string ans = "";
        int i = 0, n = text.size();
        while (i < n) {
            bool found = false;
            for (int l = 1; l < 8; ++l) {
                int j = i + l;
                if (j <= n) {
                    string t = text.substr(i, l);
                    if (d.count(t)) {
                        ans += d[t];
                        i = j;
                        found = true;
                        break;
                    }
                }
            }
            if (!found) ans += text[i++];
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func entityParser(text string) string {
	d := map[string]string{
		"&quot;":  "\"",
		"&apos;":  "'",
		"&amp;":   "&",
		"&gt;":    ">",
		"&lt;":    "<",
		"&frasl;": "/",
	}
	var ans strings.Builder
	i, n := 0, len(text)

	for i < n {
		found := false
		for l := 1; l < 8; l++ {
			j := i + l
			if j <= n {
				t := text[i:j]
				if val, ok := d[t]; ok {
					ans.WriteString(val)
					i = j
					found = true
					break
				}
			}
		}
		if !found {
			ans.WriteByte(text[i])
			i++
		}
	}

	return ans.String()
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function entityParser(text: string): string {
    const d: { [key: string]: string } = {
        '&quot;': '"',
        '&apos;': "'",
        '&amp;': '&',
        '&gt;': '>',
        '&lt;': '<',
        '&frasl;': '/',
    };

    const pattern = new RegExp(Object.keys(d).join('|'), 'g');
    return text.replace(pattern, match => d[match]);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>「HTML&nbsp;实体解析器」 是一种特殊的解析器，它将 HTML 代码作为输入，并用字符本身替换掉所有这些特殊的字符实体。</p>

<p>HTML 里这些特殊字符和它们对应的字符实体包括：</p>

<ul>
	<li><strong>双引号：</strong>字符实体为&nbsp;<code>&amp;quot;</code>&nbsp;，对应的字符是&nbsp;<code>&quot;</code>&nbsp;。</li>
	<li><strong>单引号：</strong>字符实体为&nbsp;<code>&amp;apos;</code>&nbsp;，对应的字符是&nbsp;<code>&#39;</code>&nbsp;。</li>
	<li><strong>与符号：</strong>字符实体为&nbsp;<code>&amp;amp;</code>&nbsp;，对应对的字符是&nbsp;<code>&amp;</code>&nbsp;。</li>
	<li><strong>大于号：</strong>字符实体为&nbsp;<code>&amp;gt;</code>&nbsp;，对应的字符是&nbsp;<code>&gt;</code>&nbsp;。</li>
	<li><strong>小于号：</strong>字符实体为&nbsp;<code>&amp;lt;</code>&nbsp;，对应的字符是&nbsp;<code>&lt;</code>&nbsp;。</li>
	<li><strong>斜线号：</strong>字符实体为&nbsp;<code>&amp;frasl;</code>&nbsp;，对应的字符是&nbsp;<code>/</code>&nbsp;。</li>
</ul>

<p>给你输入字符串&nbsp;<code>text</code>&nbsp;，请你实现一个 HTML&nbsp;实体解析器，返回解析器解析后的结果。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>text = &quot;&amp;amp; is an HTML entity but &amp;ambassador; is not.&quot;
<strong>输出：</strong>&quot;&amp; is an HTML entity but &amp;ambassador; is not.&quot;
<strong>解释：</strong>解析器把字符实体 &amp;amp; 用 &amp; 替换
</pre>

<p><strong>示例&nbsp;2：</strong></p>

<pre>
<strong>输入：</strong>text = &quot;and I quote: &amp;quot;...&amp;quot;&quot;
<strong>输出：</strong>&quot;and I quote: \&quot;...\&quot;&quot;
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>text = &quot;Stay home! Practice on Leetcode :)&quot;
<strong>输出：</strong>&quot;Stay home! Practice on Leetcode :)&quot;
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>text = &quot;x &amp;gt; y &amp;amp;&amp;amp; x &amp;lt; y is always false&quot;
<strong>输出：</strong>&quot;x &gt; y &amp;&amp; x &lt; y is always false&quot;
</pre>

<p><strong>示例 5：</strong></p>

<pre>
<strong>输入：</strong>text = &quot;leetcode.com&amp;frasl;problemset&amp;frasl;all&quot;
<strong>输出：</strong>&quot;leetcode.com/problemset/all&quot;
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= text.length &lt;= 10^5</code></li>
	<li>字符串可能包含 256 个ASCII 字符中的任意字符。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 模拟

我们可以使用哈希表来存储每个字符实体对应的字符，然后遍历字符串，当遇到字符实体时，我们就将其替换为对应的字符。

时间复杂度 $O(n \times l)$，空间复杂度 $O(l)$。其中 $n$ 是字符串的长度，而 $l$ 是字符实体的总长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def entityParser(self, text: str) -> str:
        d = {
            '&quot;': '"',
            '&apos;': "'",
            '&amp;': "&",
            "&gt;": '>',
            "&lt;": '<',
            "&frasl;": '/',
        }
        i, n = 0, len(text)
        ans = []
        while i < n:
            for l in range(1, 8):
                j = i + l
                if text[i:j] in d:
                    ans.append(d[text[i:j]])
                    i = j
                    break
            else:
                ans.append(text[i])
                i += 1
        return ''.join(ans)
```

#### Java

```java
class Solution {
    public String entityParser(String text) {
        Map<String, String> d = new HashMap<>();
        d.put("&quot;", "\"");
        d.put("&apos;", "'");
        d.put("&amp;", "&");
        d.put("&gt;", ">");
        d.put("&lt;", "<");
        d.put("&frasl;", "/");
        StringBuilder ans = new StringBuilder();
        int i = 0;
        int n = text.length();
        while (i < n) {
            boolean found = false;
            for (int l = 1; l < 8; ++l) {
                int j = i + l;
                if (j <= n) {
                    String t = text.substring(i, j);
                    if (d.containsKey(t)) {
                        ans.append(d.get(t));
                        i = j;
                        found = true;
                        break;
                    }
                }
            }
            if (!found) {
                ans.append(text.charAt(i++));
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
    string entityParser(string text) {
        unordered_map<string, string> d = {
            {"&quot;", "\""},
            {"&apos;", "'"},
            {"&amp;", "&"},
            {"&gt;", ">"},
            {"&lt;", "<"},
            {"&frasl;", "/"},
        };
        string ans = "";
        int i = 0, n = text.size();
        while (i < n) {
            bool found = false;
            for (int l = 1; l < 8; ++l) {
                int j = i + l;
                if (j <= n) {
                    string t = text.substr(i, l);
                    if (d.count(t)) {
                        ans += d[t];
                        i = j;
                        found = true;
                        break;
                    }
                }
            }
            if (!found) ans += text[i++];
        }
        return ans;
    }
};
```

#### Go

```go
func entityParser(text string) string {
	d := map[string]string{
		"&quot;":  "\"",
		"&apos;":  "'",
		"&amp;":   "&",
		"&gt;":    ">",
		"&lt;":    "<",
		"&frasl;": "/",
	}
	var ans strings.Builder
	i, n := 0, len(text)

	for i < n {
		found := false
		for l := 1; l < 8; l++ {
			j := i + l
			if j <= n {
				t := text[i:j]
				if val, ok := d[t]; ok {
					ans.WriteString(val)
					i = j
					found = true
					break
				}
			}
		}
		if !found {
			ans.WriteByte(text[i])
			i++
		}
	}

	return ans.String()
}
```

#### TypeScript

```ts
function entityParser(text: string): string {
    const d: Record<string, string> = {
        '&quot;': '"',
        '&apos;': "'",
        '&amp;': '&',
        '&gt;': '>',
        '&lt;': '<',
        '&frasl;': '/',
    };

    let ans: string = '';
    let i: number = 0;
    const n: number = text.length;

    while (i < n) {
        let found: boolean = false;
        for (let l: number = 1; l < 8; ++l) {
            const j: number = i + l;
            if (j <= n) {
                const t: string = text.substring(i, j);
                if (d.hasOwnProperty(t)) {
                    ans += d[t];
                    i = j;
                    found = true;
                    break;
                }
            }
        }

        if (!found) {
            ans += text[i++];
        }
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
function entityParser(text: string): string {
    const d: { [key: string]: string } = {
        '&quot;': '"',
        '&apos;': "'",
        '&amp;': '&',
        '&gt;': '>',
        '&lt;': '<',
        '&frasl;': '/',
    };

    const pattern = new RegExp(Object.keys(d).join('|'), 'g');
    return text.replace(pattern, match => d[match]);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1411. 给 N x 3 网格图涂色的方案数](https://leetcode.cn/problems/number-of-ways-to-paint-n-3-grid){#1411}

{{< tabs "1411" >}}

{{% tab "python" %}}
```python
class Solution:
    def numOfWays(self, n: int) -> int:
        def f1(x: int) -> bool:
            last = -1
            for _ in range(3):
                if x % 3 == last:
                    return False
                last = x % 3
                x //= 3
            return True

        def f2(x: int, y: int) -> bool:
            for _ in range(3):
                if x % 3 == y % 3:
                    return False
                x //= 3
                y //= 3
            return True

        mod = 10**9 + 7
        m = 27
        valid = {i for i in range(m) if f1(i)}
        d = defaultdict(list)
        for i in valid:
            for j in valid:
                if f2(i, j):
                    d[i].append(j)
        f = [int(i in valid) for i in range(m)]
        for _ in range(n - 1):
            g = [0] * m
            for i in valid:
                for j in d[i]:
                    g[j] = (g[j] + f[i]) % mod
            f = g
        return sum(f) % mod
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numOfWays(int n) {
        final int mod = (int) 1e9 + 7;
        int m = 27;
        Set<Integer> valid = new HashSet<>();
        int[] f = new int[m];
        for (int i = 0; i < m; ++i) {
            if (f1(i)) {
                valid.add(i);
                f[i] = 1;
            }
        }
        Map<Integer, List<Integer>> d = new HashMap<>();
        for (int i : valid) {
            for (int j : valid) {
                if (f2(i, j)) {
                    d.computeIfAbsent(i, k -> new ArrayList<>()).add(j);
                }
            }
        }
        for (int k = 1; k < n; ++k) {
            int[] g = new int[m];
            for (int i : valid) {
                for (int j : d.getOrDefault(i, List.of())) {
                    g[j] = (g[j] + f[i]) % mod;
                }
            }
            f = g;
        }
        int ans = 0;
        for (int x : f) {
            ans = (ans + x) % mod;
        }
        return ans;
    }

    private boolean f1(int x) {
        int last = -1;
        for (int i = 0; i < 3; ++i) {
            if (x % 3 == last) {
                return false;
            }
            last = x % 3;
            x /= 3;
        }
        return true;
    }

    private boolean f2(int x, int y) {
        for (int i = 0; i < 3; ++i) {
            if (x % 3 == y % 3) {
                return false;
            }
            x /= 3;
            y /= 3;
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
    int numOfWays(int n) {
        int m = 27;

        auto f1 = [&](int x) {
            int last = -1;
            for (int i = 0; i < 3; ++i) {
                if (x % 3 == last) {
                    return false;
                }
                last = x % 3;
                x /= 3;
            }
            return true;
        };
        auto f2 = [&](int x, int y) {
            for (int i = 0; i < 3; ++i) {
                if (x % 3 == y % 3) {
                    return false;
                }
                x /= 3;
                y /= 3;
            }
            return true;
        };

        const int mod = 1e9 + 7;
        unordered_set<int> valid;
        vector<int> f(m);
        for (int i = 0; i < m; ++i) {
            if (f1(i)) {
                valid.insert(i);
                f[i] = 1;
            }
        }
        unordered_map<int, vector<int>> d;
        for (int i : valid) {
            for (int j : valid) {
                if (f2(i, j)) {
                    d[i].push_back(j);
                }
            }
        }
        for (int k = 1; k < n; ++k) {
            vector<int> g(m);
            for (int i : valid) {
                for (int j : d[i]) {
                    g[j] = (g[j] + f[i]) % mod;
                }
            }
            f = move(g);
        }
        int ans = 0;
        for (int x : f) {
            ans = (ans + x) % mod;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numOfWays(n int) (ans int) {
	f1 := func(x int) bool {
		last := -1
		for i := 0; i < 3; i++ {
			if x%3 == last {
				return false
			}
			last = x % 3
			x /= 3
		}
		return true
	}
	f2 := func(x, y int) bool {
		for i := 0; i < 3; i++ {
			if x%3 == y%3 {
				return false
			}
			x /= 3
			y /= 3
		}
		return true
	}
	m := 27
	valid := map[int]bool{}
	f := make([]int, m)
	for i := 0; i < m; i++ {
		if f1(i) {
			valid[i] = true
			f[i] = 1
		}
	}
	d := map[int][]int{}
	for i := range valid {
		for j := range valid {
			if f2(i, j) {
				d[i] = append(d[i], j)
			}
		}
	}
	const mod int = 1e9 + 7
	for k := 1; k < n; k++ {
		g := make([]int, m)
		for i := range valid {
			for _, j := range d[i] {
				g[i] = (g[i] + f[j]) % mod
			}
		}
		f = g
	}
	for _, x := range f {
		ans = (ans + x) % mod
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numOfWays(n: number): number {
    const f1 = (x: number): boolean => {
        let last = -1;
        for (let i = 0; i < 3; ++i) {
            if (x % 3 === last) {
                return false;
            }
            last = x % 3;
            x = Math.floor(x / 3);
        }
        return true;
    };
    const f2 = (x: number, y: number): boolean => {
        for (let i = 0; i < 3; ++i) {
            if (x % 3 === y % 3) {
                return false;
            }
            x = Math.floor(x / 3);
            y = Math.floor(y / 3);
        }
        return true;
    };
    const m = 27;
    const valid = new Set<number>();
    const f: number[] = Array(m).fill(0);
    for (let i = 0; i < m; ++i) {
        if (f1(i)) {
            valid.add(i);
            f[i] = 1;
        }
    }
    const d: Map<number, number[]> = new Map();
    for (const i of valid) {
        for (const j of valid) {
            if (f2(i, j)) {
                d.set(i, (d.get(i) || []).concat(j));
            }
        }
    }
    const mod = 10 ** 9 + 7;
    for (let k = 1; k < n; ++k) {
        const g: number[] = Array(m).fill(0);
        for (const i of valid) {
            for (const j of d.get(i) || []) {
                g[i] = (g[i] + f[j]) % mod;
            }
        }
        f.splice(0, f.length, ...g);
    }
    let ans = 0;
    for (const x of f) {
        ans = (ans + x) % mod;
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

<p>你有一个 <code>n x 3</code>&nbsp;的网格图 <code>grid</code>&nbsp;，你需要用 <strong>红，黄，绿</strong>&nbsp;三种颜色之一给每一个格子上色，且确保相邻格子颜色不同（也就是有相同水平边或者垂直边的格子颜色不同）。</p>

<p>给你网格图的行数 <code>n</code>&nbsp;。</p>

<p>请你返回给&nbsp;<code>grid</code>&nbsp;涂色的方案数。由于答案可能会非常大，请你返回答案对&nbsp;<code>10^9 + 7</code>&nbsp;取余的结果。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>n = 1
<strong>输出：</strong>12
<strong>解释：</strong>总共有 12 种可行的方法：
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1400-1499/1411.Number%20of%20Ways%20to%20Paint%20N%20%C3%97%203%20Grid/images/e1.png" style="height: 289px; width: 450px;">
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>n = 2
<strong>输出：</strong>54
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>n = 3
<strong>输出：</strong>246
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>n = 7
<strong>输出：</strong>106494
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>n = 5000
<strong>输出：</strong>30228214
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == grid.length</code></li>
	<li><code>grid[i].length == 3</code></li>
	<li><code>1 &lt;= n &lt;= 5000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：递推

把每一行所有可能的状态进行分类。根据对称性原理，当一行只有 $3$ 个元素时，所有合法状态分类为 $010$ 型以及 $012$ 型。

-   当状态为 $010$ 型时：下一行可能的状态为 $101$, $102$, $121$, $201$, $202$。这 $5$ 个状态可归纳为 $3$ 个 $010$ 型，以及 $2$ 个 $012$ 型。
-   当状态为 $012$ 型时：下一行可能的状态为 $101$, $120$, $121$, $201$。这 $4$ 个状态可归纳为 $2$ 个 $010$ 型，以及 $2$ 个 $012$ 型。

综上所述，可以得到 $newf0 = 3 \times f0 + 2 \times f1$, $newf1 = 2 \times f0 + 2 \times f1$。

时间复杂度 $O(n)$，其中 $n$ 是网格的行数。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numOfWays(self, n: int) -> int:
        mod = 10**9 + 7
        f0 = f1 = 6
        for _ in range(n - 1):
            g0 = (3 * f0 + 2 * f1) % mod
            g1 = (2 * f0 + 2 * f1) % mod
            f0, f1 = g0, g1
        return (f0 + f1) % mod
```

#### Java

```java
class Solution {
    public int numOfWays(int n) {
        int mod = (int) 1e9 + 7;
        long f0 = 6, f1 = 6;
        for (int i = 0; i < n - 1; ++i) {
            long g0 = (3 * f0 + 2 * f1) % mod;
            long g1 = (2 * f0 + 2 * f1) % mod;
            f0 = g0;
            f1 = g1;
        }
        return (int) (f0 + f1) % mod;
    }
}
```

#### C++

```cpp
using ll = long long;

class Solution {
public:
    int numOfWays(int n) {
        int mod = 1e9 + 7;
        ll f0 = 6, f1 = 6;
        while (--n) {
            ll g0 = (f0 * 3 + f1 * 2) % mod;
            ll g1 = (f0 * 2 + f1 * 2) % mod;
            f0 = g0;
            f1 = g1;
        }
        return (int) (f0 + f1) % mod;
    }
};
```

#### Go

```go
func numOfWays(n int) int {
	mod := int(1e9) + 7
	f0, f1 := 6, 6
	for n > 1 {
		n--
		g0 := (f0*3 + f1*2) % mod
		g1 := (f0*2 + f1*2) % mod
		f0, f1 = g0, g1
	}
	return (f0 + f1) % mod
}
```

#### TypeScript

```ts
function numOfWays(n: number): number {
    const mod: number = 10 ** 9 + 7;
    let f0: number = 6;
    let f1: number = 6;

    for (let i = 1; i < n; i++) {
        const g0: number = (3 * f0 + 2 * f1) % mod;
        const g1: number = (2 * f0 + 2 * f1) % mod;
        f0 = g0;
        f1 = g1;
    }

    return (f0 + f1) % mod;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：状态压缩 + 动态规划

我们注意到，网格只有 $3$ 列，那么一行中最多有 $3^3=27$ 种不同的涂色方案。

因此，我们定义 $f[i][j]$ 表示前 $i$ 行中，第 $i$ 行的涂色状态为 $j$ 的方案数。状态 $f[i][j]$ 由 $f[i - 1][k]$ 转移而来，其中 $k$ 是第 $i - 1$ 行的涂色状态，且 $k$ 和 $j$ 满足不同颜色相邻的要求。即：

$$
f[i][j] = \sum_{k \in \textit{valid}(j)} f[i - 1][k]
$$

其中 $\textit{valid}(j)$ 表示状态 $j$ 的所有合法前驱状态。

最终的答案即为 $f[n][j]$ 的总和，其中 $j$ 是任意合法的状态。

我们注意到 $f[i][j]$ 只和 $f[i - 1][k]$ 有关，因此我们可以使用滚动数组优化空间复杂度。

时间复杂度 $O((m + n) \times 3^{2m})$，空间复杂度 $O(3^m)$。其中 $n$ 和 $m$ 分别是网格的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numOfWays(self, n: int) -> int:
        def f1(x: int) -> bool:
            last = -1
            for _ in range(3):
                if x % 3 == last:
                    return False
                last = x % 3
                x //= 3
            return True

        def f2(x: int, y: int) -> bool:
            for _ in range(3):
                if x % 3 == y % 3:
                    return False
                x //= 3
                y //= 3
            return True

        mod = 10**9 + 7
        m = 27
        valid = {i for i in range(m) if f1(i)}
        d = defaultdict(list)
        for i in valid:
            for j in valid:
                if f2(i, j):
                    d[i].append(j)
        f = [int(i in valid) for i in range(m)]
        for _ in range(n - 1):
            g = [0] * m
            for i in valid:
                for j in d[i]:
                    g[j] = (g[j] + f[i]) % mod
            f = g
        return sum(f) % mod
```

#### Java

```java
class Solution {
    public int numOfWays(int n) {
        final int mod = (int) 1e9 + 7;
        int m = 27;
        Set<Integer> valid = new HashSet<>();
        int[] f = new int[m];
        for (int i = 0; i < m; ++i) {
            if (f1(i)) {
                valid.add(i);
                f[i] = 1;
            }
        }
        Map<Integer, List<Integer>> d = new HashMap<>();
        for (int i : valid) {
            for (int j : valid) {
                if (f2(i, j)) {
                    d.computeIfAbsent(i, k -> new ArrayList<>()).add(j);
                }
            }
        }
        for (int k = 1; k < n; ++k) {
            int[] g = new int[m];
            for (int i : valid) {
                for (int j : d.getOrDefault(i, List.of())) {
                    g[j] = (g[j] + f[i]) % mod;
                }
            }
            f = g;
        }
        int ans = 0;
        for (int x : f) {
            ans = (ans + x) % mod;
        }
        return ans;
    }

    private boolean f1(int x) {
        int last = -1;
        for (int i = 0; i < 3; ++i) {
            if (x % 3 == last) {
                return false;
            }
            last = x % 3;
            x /= 3;
        }
        return true;
    }

    private boolean f2(int x, int y) {
        for (int i = 0; i < 3; ++i) {
            if (x % 3 == y % 3) {
                return false;
            }
            x /= 3;
            y /= 3;
        }
        return true;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numOfWays(int n) {
        int m = 27;

        auto f1 = [&](int x) {
            int last = -1;
            for (int i = 0; i < 3; ++i) {
                if (x % 3 == last) {
                    return false;
                }
                last = x % 3;
                x /= 3;
            }
            return true;
        };
        auto f2 = [&](int x, int y) {
            for (int i = 0; i < 3; ++i) {
                if (x % 3 == y % 3) {
                    return false;
                }
                x /= 3;
                y /= 3;
            }
            return true;
        };

        const int mod = 1e9 + 7;
        unordered_set<int> valid;
        vector<int> f(m);
        for (int i = 0; i < m; ++i) {
            if (f1(i)) {
                valid.insert(i);
                f[i] = 1;
            }
        }
        unordered_map<int, vector<int>> d;
        for (int i : valid) {
            for (int j : valid) {
                if (f2(i, j)) {
                    d[i].push_back(j);
                }
            }
        }
        for (int k = 1; k < n; ++k) {
            vector<int> g(m);
            for (int i : valid) {
                for (int j : d[i]) {
                    g[j] = (g[j] + f[i]) % mod;
                }
            }
            f = move(g);
        }
        int ans = 0;
        for (int x : f) {
            ans = (ans + x) % mod;
        }
        return ans;
    }
};
```

#### Go

```go
func numOfWays(n int) (ans int) {
	f1 := func(x int) bool {
		last := -1
		for i := 0; i < 3; i++ {
			if x%3 == last {
				return false
			}
			last = x % 3
			x /= 3
		}
		return true
	}
	f2 := func(x, y int) bool {
		for i := 0; i < 3; i++ {
			if x%3 == y%3 {
				return false
			}
			x /= 3
			y /= 3
		}
		return true
	}
	m := 27
	valid := map[int]bool{}
	f := make([]int, m)
	for i := 0; i < m; i++ {
		if f1(i) {
			valid[i] = true
			f[i] = 1
		}
	}
	d := map[int][]int{}
	for i := range valid {
		for j := range valid {
			if f2(i, j) {
				d[i] = append(d[i], j)
			}
		}
	}
	const mod int = 1e9 + 7
	for k := 1; k < n; k++ {
		g := make([]int, m)
		for i := range valid {
			for _, j := range d[i] {
				g[i] = (g[i] + f[j]) % mod
			}
		}
		f = g
	}
	for _, x := range f {
		ans = (ans + x) % mod
	}
	return
}
```

#### TypeScript

```ts
function numOfWays(n: number): number {
    const f1 = (x: number): boolean => {
        let last = -1;
        for (let i = 0; i < 3; ++i) {
            if (x % 3 === last) {
                return false;
            }
            last = x % 3;
            x = Math.floor(x / 3);
        }
        return true;
    };
    const f2 = (x: number, y: number): boolean => {
        for (let i = 0; i < 3; ++i) {
            if (x % 3 === y % 3) {
                return false;
            }
            x = Math.floor(x / 3);
            y = Math.floor(y / 3);
        }
        return true;
    };
    const m = 27;
    const valid = new Set<number>();
    const f: number[] = Array(m).fill(0);
    for (let i = 0; i < m; ++i) {
        if (f1(i)) {
            valid.add(i);
            f[i] = 1;
        }
    }
    const d: Map<number, number[]> = new Map();
    for (const i of valid) {
        for (const j of valid) {
            if (f2(i, j)) {
                d.set(i, (d.get(i) || []).concat(j));
            }
        }
    }
    const mod = 10 ** 9 + 7;
    for (let k = 1; k < n; ++k) {
        const g: number[] = Array(m).fill(0);
        for (const i of valid) {
            for (const j of d.get(i) || []) {
                g[i] = (g[i] + f[j]) % mod;
            }
        }
        f.splice(0, f.length, ...g);
    }
    let ans = 0;
    for (const x of f) {
        ans = (ans + x) % mod;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1412. 查找成绩处于中游的学生 🔒](https://leetcode.cn/problems/find-the-quiet-students-in-all-exams){#1412}

{{< tabs "1412" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            student_id,
            RANK() OVER (
                PARTITION BY exam_id
                ORDER BY score
            ) AS rk1,
            RANK() OVER (
                PARTITION BY exam_id
                ORDER BY score DESC
            ) AS rk2
        FROM Exam
    )
SELECT student_id, student_name
FROM
    T
    JOIN Student USING (student_id)
GROUP BY 1
HAVING SUM(rk1 = 1) = 0 AND SUM(rk2 = 1) = 0
ORDER BY 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表: <code>Student</code></p>

<pre>
+---------------------+---------+
| Column Name         | Type    |
+---------------------+---------+
| student_id          | int     |
| student_name        | varchar |
+---------------------+---------+
student_id 是该表主键(具有唯一值的列)。
student_name 学生名字。</pre>

<p>&nbsp;</p>

<p>表: <code>Exam</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| exam_id       | int     |
| student_id    | int     |
| score         | int     |
+---------------+---------+
(exam_id, student_id) 是该表主键(具有唯一值的列的组合)。
学生 student_id 在测验 exam_id 中得分为 score。
</pre>

<p>&nbsp;</p>

<p>成绩处于中游的学生是指至少参加了一次测验,&nbsp;且得分既不是最高分也不是最低分的学生。</p>

<p>编写解决方案，找出在 <strong>所有</strong> 测验中都处于中游的学生 <code>(student_id, student_name)</code>。不要返回从来没有参加过测验的学生。</p>

<p>返回结果表按照&nbsp;<code>student_id</code>&nbsp;排序。</p>

<p>返回结果格式如下。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
Student 表：
+-------------+---------------+
| student_id  | student_name  |
+-------------+---------------+
| 1           | Daniel        |
| 2           | Jade          |
| 3           | Stella        |
| 4           | Jonathan      |
| 5           | Will          |
+-------------+---------------+
Exam 表：
+------------+--------------+-----------+
| exam_id    | student_id   | score     |
+------------+--------------+-----------+
| 10         |     1        |    70     |
| 10         |     2        |    80     |
| 10         |     3        |    90     |
| 20         |     1        |    80     |
| 30         |     1        |    70     |
| 30         |     3        |    80     |
| 30         |     4        |    90     |
| 40         |     1        |    60     |
| 40         |     2        |    70     |
| 40         |     4        |    80     |
+------------+--------------+-----------+
<strong>输出：</strong>
+-------------+---------------+
| student_id  | student_name  |
+-------------+---------------+
| 2           | Jade          |
+-------------+---------------+
<strong>解释：</strong>
对于测验 1: 学生 1 和 3 分别获得了最低分和最高分。
对于测验 2: 学生 1 既获得了最高分, 也获得了最低分。
对于测验 3 和 4: 学生 1 和 4 分别获得了最低分和最高分。
学生 2 和 5 没有在任一场测验中获得了最高分或者最低分。
因为学生 5 从来没有参加过任何测验, 所以他被排除于结果表。
由此, 我们仅仅返回学生 2 的信息。</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：使用 RANK() 窗口函数 + 分组聚合

我们可以使用 `RANK()` 窗口函数来计算每个学生在每场考试中的正序排名 $rk1$ 和倒序排序 $rk2$，得到表 $T$。

接下来，我们将表 $T$ 与表 $Student$ 进行内连接，然后按照学生编号进行分组聚合，得到每个学生在所有考试中的正序排名为 $1$ 的次数 $cnt1$ 和倒序排名为 $1$ 的次数 $cnt2$。如果 $cnt1$ 和 $cnt2$ 都为 $0$，则说明该学生在所有考试中都处于中游。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            student_id,
            RANK() OVER (
                PARTITION BY exam_id
                ORDER BY score
            ) AS rk1,
            RANK() OVER (
                PARTITION BY exam_id
                ORDER BY score DESC
            ) AS rk2
        FROM Exam
    )
SELECT student_id, student_name
FROM
    T
    JOIN Student USING (student_id)
GROUP BY 1
HAVING SUM(rk1 = 1) = 0 AND SUM(rk2 = 1) = 0
ORDER BY 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1413. 逐步求和得到正数的最小值](https://leetcode.cn/problems/minimum-value-to-get-positive-step-by-step-sum){#1413}

{{< tabs "1413" >}}

{{% tab "python" %}}
```python
class Solution:
    def minStartValue(self, nums: List[int]) -> int:
        s = list(accumulate(nums))
        return 1 if min(s) >= 0 else abs(min(s)) + 1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minStartValue(int[] nums) {
        int s = 0;
        int t = Integer.MAX_VALUE;
        for (int num : nums) {
            s += num;
            t = Math.min(t, s);
        }
        return Math.max(1, 1 - t);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int s = 0, t = INT_MAX;
        for (int num : nums) {
            s += num;
            t = min(t, s);
        }
        return max(1, 1 - t);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minStartValue(nums []int) int {
	s, t := 0, 10000
	for _, num := range nums {
		s += num
		if s < t {
			t = s
		}
	}
	if t < 0 {
		return 1 - t
	}
	return 1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minStartValue(nums: number[]): number {
    let sum = 0;
    let min = Infinity;
    for (const num of nums) {
        sum += num;
        min = Math.min(min, sum);
    }
    return Math.max(1, 1 - min);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn min_start_value(nums: Vec<i32>) -> i32 {
        let mut sum = 0;
        let mut min = i32::MAX;
        for num in nums.iter() {
            sum += num;
            min = min.min(sum);
        }
        (1).max(1 - min)
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>nums</code>&nbsp;。你可以选定任意的&nbsp;<strong>正数</strong> startValue 作为初始值。</p>

<p>你需要从左到右遍历 <code>nums</code>&nbsp;数组，并将 startValue 依次累加上&nbsp;<code>nums</code>&nbsp;数组中的值。</p>

<p>请你在确保累加和始终大于等于 1 的前提下，选出一个最小的&nbsp;<strong>正数</strong>&nbsp;作为 startValue 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [-3,2,-3,4,2]
<strong>输出：</strong>5
<strong>解释：</strong>如果你选择 startValue = 4，在第三次累加时，和小于 1 。
<strong>                累加求和
&nbsp;               startValue = 4 | startValue = 5 | nums
</strong>&nbsp;                 (4 <strong>-3</strong> ) = 1  | (5 <strong>-3</strong> ) = 2    |  -3
&nbsp;                 (1 <strong>+2</strong> ) = 3  | (2 <strong>+2</strong> ) = 4    |   2
&nbsp;                 (3 <strong>-3</strong> ) = 0  | (4 <strong>-3</strong> ) = 1    |  -3
&nbsp;                 (0 <strong>+4</strong> ) = 4  | (1 <strong>+4</strong> ) = 5    |   4
&nbsp;                 (4 <strong>+2</strong> ) = 6  | (5 <strong>+2</strong> ) = 7    |   2
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2]
<strong>输出：</strong>1
<strong>解释：</strong>最小的 startValue 需要是正数。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,-2,-3]
<strong>输出：</strong>5
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>-100 &lt;= nums[i] &lt;= 100</code></li>
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
    def minStartValue(self, nums: List[int]) -> int:
        s, t = 0, inf
        for num in nums:
            s += num
            t = min(t, s)
        return max(1, 1 - t)
```

#### Java

```java
class Solution {
    public int minStartValue(int[] nums) {
        int s = 0;
        int t = Integer.MAX_VALUE;
        for (int num : nums) {
            s += num;
            t = Math.min(t, s);
        }
        return Math.max(1, 1 - t);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int s = 0, t = INT_MAX;
        for (int num : nums) {
            s += num;
            t = min(t, s);
        }
        return max(1, 1 - t);
    }
};
```

#### Go

```go
func minStartValue(nums []int) int {
	s, t := 0, 10000
	for _, num := range nums {
		s += num
		if s < t {
			t = s
		}
	}
	if t < 0 {
		return 1 - t
	}
	return 1
}
```

#### TypeScript

```ts
function minStartValue(nums: number[]): number {
    let sum = 0;
    let min = Infinity;
    for (const num of nums) {
        sum += num;
        min = Math.min(min, sum);
    }
    return Math.max(1, 1 - min);
}
```

#### Rust

```rust
impl Solution {
    pub fn min_start_value(nums: Vec<i32>) -> i32 {
        let mut sum = 0;
        let mut min = i32::MAX;
        for num in nums.iter() {
            sum += num;
            min = min.min(sum);
        }
        (1).max(1 - min)
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
    def minStartValue(self, nums: List[int]) -> int:
        s = list(accumulate(nums))
        return 1 if min(s) >= 0 else abs(min(s)) + 1
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1414. 和为 K 的最少斐波那契数字数目](https://leetcode.cn/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k){#1414}

{{< tabs "1414" >}}

{{% tab "python" %}}
```python
class Solution:
    def findMinFibonacciNumbers(self, k: int) -> int:
        a = b = 1
        while b <= k:
            a, b = b, a + b
        ans = 0
        while k:
            if k >= b:
                k -= b
                ans += 1
            a, b = b - a, a
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int findMinFibonacciNumbers(int k) {
        int a = 1, b = 1;
        while (b <= k) {
            int c = a + b;
            a = b;
            b = c;
        }
        int ans = 0;
        while (k > 0) {
            if (k >= b) {
                k -= b;
                ++ans;
            }
            int c = b - a;
            b = a;
            a = c;
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
    int findMinFibonacciNumbers(int k) {
        int a = 1, b = 1;
        while (b <= k) {
            int c = a + b;
            a = b;
            b = c;
        }
        int ans = 0;
        while (k > 0) {
            if (k >= b) {
                k -= b;
                ++ans;
            }
            int c = b - a;
            b = a;
            a = c;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findMinFibonacciNumbers(k int) (ans int) {
	a, b := 1, 1
	for b <= k {
		c := a + b
		a = b
		b = c
	}

	for k > 0 {
		if k >= b {
			k -= b
			ans++
		}
		c := b - a
		b = a
		a = c
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findMinFibonacciNumbers(k: number): number {
    let [a, b] = [1, 1];
    while (b <= k) {
        let c = a + b;
        a = b;
        b = c;
    }

    let ans = 0;
    while (k > 0) {
        if (k >= b) {
            k -= b;
            ans++;
        }
        let c = b - a;
        b = a;
        a = c;
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn find_min_fibonacci_numbers(mut k: i32) -> i32 {
        let mut a = 1;
        let mut b = 1;
        while b <= k {
            let c = a + b;
            a = b;
            b = c;
        }

        let mut ans = 0;
        while k > 0 {
            if k >= b {
                k -= b;
                ans += 1;
            }
            let c = b - a;
            b = a;
            a = c;
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

<p>给你数字 <code>k</code>&nbsp;，请你返回和为&nbsp;<code>k</code>&nbsp;的斐波那契数字的最少数目，其中，每个斐波那契数字都可以被使用多次。</p>

<p>斐波那契数字定义为：</p>

<ul>
	<li>F<sub>1</sub> = 1</li>
	<li>F<sub>2</sub> = 1</li>
	<li>F<sub>n</sub> = F<sub>n-1</sub> + F<sub>n-2</sub>&nbsp;， 其中 n &gt; 2 。</li>
</ul>

<p>数据保证对于给定的 <code>k</code>&nbsp;，一定能找到可行解。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>k = 7
<strong>输出：</strong>2 
<strong>解释：</strong>斐波那契数字为：1，1，2，3，5，8，13，&hellip;&hellip;
对于 k = 7 ，我们可以得到 2 + 5 = 7 。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>k = 10
<strong>输出：</strong>2 
<strong>解释：</strong>对于 k = 10 ，我们可以得到 2 + 8 = 10 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>k = 19
<strong>输出：</strong>3 
<strong>解释：</strong>对于 k = 19 ，我们可以得到 1 + 5 + 13 = 19 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= 10^9</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心

我们可以每次贪心地选取一个不超过 $k$ 的最大的斐波那契数，然后将 $k$ 减去该数，答案加一，一直循环，直到 $k = 0$ 为止。

由于每次贪心地选取了最大的不超过 $k$ 的斐波那契数，假设为 $b$，前一个数为 $a$，后一个数为 $c$。将 $k$ 减去 $b$，得到的结果，一定小于 $a$，也即意味着，我们选取了 $b$ 之后，一定不会选到 $a$。这是因为，如果能选上 $a$，那么我们在前面就可以贪心地选上 $b$ 的下一个斐波那契数 $c$，这不符合我们的假设。因此，我们在选取 $b$ 之后，可以贪心地减小斐波那契数。

时间复杂度 $O(\log k)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findMinFibonacciNumbers(self, k: int) -> int:
        a = b = 1
        while b <= k:
            a, b = b, a + b
        ans = 0
        while k:
            if k >= b:
                k -= b
                ans += 1
            a, b = b - a, a
        return ans
```

#### Java

```java
class Solution {
    public int findMinFibonacciNumbers(int k) {
        int a = 1, b = 1;
        while (b <= k) {
            int c = a + b;
            a = b;
            b = c;
        }
        int ans = 0;
        while (k > 0) {
            if (k >= b) {
                k -= b;
                ++ans;
            }
            int c = b - a;
            b = a;
            a = c;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        int a = 1, b = 1;
        while (b <= k) {
            int c = a + b;
            a = b;
            b = c;
        }
        int ans = 0;
        while (k > 0) {
            if (k >= b) {
                k -= b;
                ++ans;
            }
            int c = b - a;
            b = a;
            a = c;
        }
        return ans;
    }
};
```

#### Go

```go
func findMinFibonacciNumbers(k int) (ans int) {
	a, b := 1, 1
	for b <= k {
		c := a + b
		a = b
		b = c
	}

	for k > 0 {
		if k >= b {
			k -= b
			ans++
		}
		c := b - a
		b = a
		a = c
	}
	return
}
```

#### TypeScript

```ts
function findMinFibonacciNumbers(k: number): number {
    let [a, b] = [1, 1];
    while (b <= k) {
        let c = a + b;
        a = b;
        b = c;
    }

    let ans = 0;
    while (k > 0) {
        if (k >= b) {
            k -= b;
            ans++;
        }
        let c = b - a;
        b = a;
        a = c;
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn find_min_fibonacci_numbers(mut k: i32) -> i32 {
        let mut a = 1;
        let mut b = 1;
        while b <= k {
            let c = a + b;
            a = b;
            b = c;
        }

        let mut ans = 0;
        while k > 0 {
            if k >= b {
                k -= b;
                ans += 1;
            }
            let c = b - a;
            b = a;
            a = c;
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

# [1415. 长度为 n 的开心字符串中字典序第 k 小的字符串](https://leetcode.cn/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n){#1415}

{{< tabs "1415" >}}

{{% tab "python" %}}
```python
class Solution:
    def getHappyString(self, n: int, k: int) -> str:
        def dfs():
            if len(s) == n:
                ans.append("".join(s))
                return
            if len(ans) >= k:
                return
            for c in "abc":
                if not s or s[-1] != c:
                    s.append(c)
                    dfs()
                    s.pop()

        ans = []
        s = []
        dfs()
        return "" if len(ans) < k else ans[k - 1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private List<String> ans = new ArrayList<>();
    private StringBuilder s = new StringBuilder();
    private int n, k;

    public String getHappyString(int n, int k) {
        this.n = n;
        this.k = k;
        dfs();
        return ans.size() < k ? "" : ans.get(k - 1);
    }

    private void dfs() {
        if (s.length() == n) {
            ans.add(s.toString());
            return;
        }
        if (ans.size() >= k) {
            return;
        }
        for (char c : "abc".toCharArray()) {
            if (s.isEmpty() || s.charAt(s.length() - 1) != c) {
                s.append(c);
                dfs();
                s.deleteCharAt(s.length() - 1);
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
    string getHappyString(int n, int k) {
        vector<string> ans;
        string s = "";
        auto dfs = [&](this auto&& dfs) -> void {
            if (s.size() == n) {
                ans.emplace_back(s);
                return;
            }
            if (ans.size() >= k) {
                return;
            }
            for (char c = 'a'; c <= 'c'; ++c) {
                if (s.empty() || s.back() != c) {
                    s.push_back(c);
                    dfs();
                    s.pop_back();
                }
            }
        };
        dfs();
        return ans.size() < k ? "" : ans[k - 1];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func getHappyString(n int, k int) string {
    ans := []string{}
    var s []byte

    var dfs func()
    dfs = func() {
        if len(s) == n {
            ans = append(ans, string(s))
            return
        }
        if len(ans) >= k {
            return
        }
        for c := byte('a'); c <= 'c'; c++ {
            if len(s) == 0 || s[len(s)-1] != c {
                s = append(s, c)
                dfs()
                s = s[:len(s)-1]
            }
        }
    }

    dfs()
    if len(ans) < k {
        return ""
    }
    return ans[k-1]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function getHappyString(n: number, k: number): string {
    const ans: string[] = [];
    const s: string[] = [];
    const dfs = () => {
        if (s.length === n) {
            ans.push(s.join(''));
            return;
        }
        if (ans.length >= k) {
            return;
        }
        for (const c of 'abc') {
            if (!s.length || s.at(-1)! !== c) {
                s.push(c);
                dfs();
                s.pop();
            }
        }
    };
    dfs();
    return ans[k - 1] ?? '';
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn get_happy_string(n: i32, k: i32) -> String {
        let mut ans = Vec::new();
        let mut s = String::new();
        let mut k = k;

        fn dfs(n: i32, s: &mut String, ans: &mut Vec<String>, k: &mut i32) {
            if s.len() == n as usize {
                ans.push(s.clone());
                return;
            }
            if ans.len() >= *k as usize {
                return;
            }
            for c in "abc".chars() {
                if s.is_empty() || s.chars().last() != Some(c) {
                    s.push(c);
                    dfs(n, s, ans, k);
                    s.pop();
                }
            }
        }

        dfs(n, &mut s, &mut ans, &mut k);
        if ans.len() < k as usize {
            "".to_string()
        } else {
            ans[(k - 1) as usize].clone()
        }
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number} n
 * @param {number} k
 * @return {string}
 */
var getHappyString = function (n, k) {
    const ans = [];
    const s = [];
    const dfs = () => {
        if (s.length === n) {
            ans.push(s.join(''));
            return;
        }
        if (ans.length >= k) {
            return;
        }
        for (const c of 'abc') {
            if (!s.length || s.at(-1) !== c) {
                s.push(c);
                dfs();
                s.pop();
            }
        }
    };
    dfs();
    return ans[k - 1] ?? '';
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public string GetHappyString(int n, int k) {
        List<string> ans = new List<string>();
        StringBuilder s = new StringBuilder();

        void Dfs() {
            if (s.Length == n) {
                ans.Add(s.ToString());
                return;
            }
            if (ans.Count >= k) {
                return;
            }
            foreach (char c in "abc") {
                if (s.Length == 0 || s[s.Length - 1] != c) {
                    s.Append(c);
                    Dfs();
                    s.Length--;
                }
            }
        }

        Dfs();
        return ans.Count < k ? "" : ans[k - 1];
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>一个 「开心字符串」定义为：</p>

<ul>
	<li>仅包含小写字母&nbsp;<code>[&#39;a&#39;, &#39;b&#39;, &#39;c&#39;]</code>.</li>
	<li>对所有在&nbsp;<code>1</code>&nbsp;到&nbsp;<code>s.length - 1</code>&nbsp;之间的&nbsp;<code>i</code>&nbsp;，满足&nbsp;<code>s[i] != s[i + 1]</code>&nbsp;（字符串的下标从 1 开始）。</li>
</ul>

<p>比方说，字符串&nbsp;<strong>&quot;abc&quot;</strong>，<strong>&quot;ac&quot;，&quot;b&quot;</strong> 和&nbsp;<strong>&quot;abcbabcbcb&quot;</strong>&nbsp;都是开心字符串，但是&nbsp;<strong>&quot;aa&quot;</strong>，<strong>&quot;baa&quot;</strong>&nbsp;和&nbsp;<strong>&quot;ababbc&quot;</strong>&nbsp;都不是开心字符串。</p>

<p>给你两个整数 <code>n</code>&nbsp;和 <code>k</code>&nbsp;，你需要将长度为 <code>n</code>&nbsp;的所有开心字符串按字典序排序。</p>

<p>请你返回排序后的第 k 个开心字符串，如果长度为 <code>n</code>&nbsp;的开心字符串少于 <code>k</code>&nbsp;个，那么请你返回 <strong>空字符串</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>n = 1, k = 3
<strong>输出：</strong>&quot;c&quot;
<strong>解释：</strong>列表 [&quot;a&quot;, &quot;b&quot;, &quot;c&quot;] 包含了所有长度为 1 的开心字符串。按照字典序排序后第三个字符串为 &quot;c&quot; 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>n = 1, k = 4
<strong>输出：</strong>&quot;&quot;
<strong>解释：</strong>长度为 1 的开心字符串只有 3 个。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>n = 3, k = 9
<strong>输出：</strong>&quot;cab&quot;
<strong>解释：</strong>长度为 3 的开心字符串总共有 12 个 [&quot;aba&quot;, &quot;abc&quot;, &quot;aca&quot;, &quot;acb&quot;, &quot;bab&quot;, &quot;bac&quot;, &quot;bca&quot;, &quot;bcb&quot;, &quot;cab&quot;, &quot;cac&quot;, &quot;cba&quot;, &quot;cbc&quot;] 。第 9 个字符串为 &quot;cab&quot;
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>n = 2, k = 7
<strong>输出：</strong>&quot;&quot;
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>n = 10, k = 100
<strong>输出：</strong>&quot;abacbabacb&quot;
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10</code></li>
	<li><code>1 &lt;= k &lt;= 100</code></li>
</ul>

<p>&nbsp;</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS

我们用一个字符串 $\textit{s}$ 来记录当前的字符串，初始时为空字符串。然后，我们设计一个函数 $\text{dfs}$，用来生成所有长度为 $n$ 的开心字符串。

函数 $\text{dfs}$ 的具体实现如下：

1. 如果当前字符串的长度等于 $n$，则将当前字符串加入答案数组 $\textit{ans}$ 中，然后返回；
2. 如果答案数组的长度大于等于 $k$，则直接返回；
3. 否则，我们遍历字符集 $\{a, b, c\}$，对于每个字符 $c$，如果当前字符串为空，或者当前字符串的最后一个字符不等于 $c$，则将字符 $c$ 加入当前字符串，然后递归调用 $\text{dfs}$，递归结束后，将当前字符串的最后一个字符删除。

最后，我们判断答案数组的长度是否小于 $k$，如果是，则返回空字符串，否则返回答案数组的第 $k-1$ 个元素。

时间复杂度 $O(n \times 2^n)$，空间复杂度 $O(n)$。其中 $n$ 为字符串长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def getHappyString(self, n: int, k: int) -> str:
        def dfs():
            if len(s) == n:
                ans.append("".join(s))
                return
            if len(ans) >= k:
                return
            for c in "abc":
                if not s or s[-1] != c:
                    s.append(c)
                    dfs()
                    s.pop()

        ans = []
        s = []
        dfs()
        return "" if len(ans) < k else ans[k - 1]
```

#### Java

```java
class Solution {
    private List<String> ans = new ArrayList<>();
    private StringBuilder s = new StringBuilder();
    private int n, k;

    public String getHappyString(int n, int k) {
        this.n = n;
        this.k = k;
        dfs();
        return ans.size() < k ? "" : ans.get(k - 1);
    }

    private void dfs() {
        if (s.length() == n) {
            ans.add(s.toString());
            return;
        }
        if (ans.size() >= k) {
            return;
        }
        for (char c : "abc".toCharArray()) {
            if (s.isEmpty() || s.charAt(s.length() - 1) != c) {
                s.append(c);
                dfs();
                s.deleteCharAt(s.length() - 1);
            }
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    string getHappyString(int n, int k) {
        vector<string> ans;
        string s = "";
        auto dfs = [&](this auto&& dfs) -> void {
            if (s.size() == n) {
                ans.emplace_back(s);
                return;
            }
            if (ans.size() >= k) {
                return;
            }
            for (char c = 'a'; c <= 'c'; ++c) {
                if (s.empty() || s.back() != c) {
                    s.push_back(c);
                    dfs();
                    s.pop_back();
                }
            }
        };
        dfs();
        return ans.size() < k ? "" : ans[k - 1];
    }
};
```

#### Go

```go
func getHappyString(n int, k int) string {
    ans := []string{}
    var s []byte

    var dfs func()
    dfs = func() {
        if len(s) == n {
            ans = append(ans, string(s))
            return
        }
        if len(ans) >= k {
            return
        }
        for c := byte('a'); c <= 'c'; c++ {
            if len(s) == 0 || s[len(s)-1] != c {
                s = append(s, c)
                dfs()
                s = s[:len(s)-1]
            }
        }
    }

    dfs()
    if len(ans) < k {
        return ""
    }
    return ans[k-1]
}
```

#### TypeScript

```ts
function getHappyString(n: number, k: number): string {
    const ans: string[] = [];
    const s: string[] = [];
    const dfs = () => {
        if (s.length === n) {
            ans.push(s.join(''));
            return;
        }
        if (ans.length >= k) {
            return;
        }
        for (const c of 'abc') {
            if (!s.length || s.at(-1)! !== c) {
                s.push(c);
                dfs();
                s.pop();
            }
        }
    };
    dfs();
    return ans[k - 1] ?? '';
}
```

#### Rust

```rust
impl Solution {
    pub fn get_happy_string(n: i32, k: i32) -> String {
        let mut ans = Vec::new();
        let mut s = String::new();
        let mut k = k;

        fn dfs(n: i32, s: &mut String, ans: &mut Vec<String>, k: &mut i32) {
            if s.len() == n as usize {
                ans.push(s.clone());
                return;
            }
            if ans.len() >= *k as usize {
                return;
            }
            for c in "abc".chars() {
                if s.is_empty() || s.chars().last() != Some(c) {
                    s.push(c);
                    dfs(n, s, ans, k);
                    s.pop();
                }
            }
        }

        dfs(n, &mut s, &mut ans, &mut k);
        if ans.len() < k as usize {
            "".to_string()
        } else {
            ans[(k - 1) as usize].clone()
        }
    }
}
```

#### JavaScript

```js
/**
 * @param {number} n
 * @param {number} k
 * @return {string}
 */
var getHappyString = function (n, k) {
    const ans = [];
    const s = [];
    const dfs = () => {
        if (s.length === n) {
            ans.push(s.join(''));
            return;
        }
        if (ans.length >= k) {
            return;
        }
        for (const c of 'abc') {
            if (!s.length || s.at(-1) !== c) {
                s.push(c);
                dfs();
                s.pop();
            }
        }
    };
    dfs();
    return ans[k - 1] ?? '';
};
```

#### C#

```cs
public class Solution {
    public string GetHappyString(int n, int k) {
        List<string> ans = new List<string>();
        StringBuilder s = new StringBuilder();

        void Dfs() {
            if (s.Length == n) {
                ans.Add(s.ToString());
                return;
            }
            if (ans.Count >= k) {
                return;
            }
            foreach (char c in "abc") {
                if (s.Length == 0 || s[s.Length - 1] != c) {
                    s.Append(c);
                    Dfs();
                    s.Length--;
                }
            }
        }

        Dfs();
        return ans.Count < k ? "" : ans[k - 1];
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1416. 恢复数组](https://leetcode.cn/problems/restore-the-array){#1416}

{{< tabs "1416" >}}

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

<p>某个程序本来应该输出一个整数数组。但是这个程序忘记输出空格了以致输出了一个数字字符串，我们所知道的信息只有：数组中所有整数都在 <code>[1, k]</code>&nbsp;之间，且数组中的数字都没有前导 0 。</p>

<p>给你字符串&nbsp;<code>s</code>&nbsp;和整数&nbsp;<code>k</code>&nbsp;。可能会有多种不同的数组恢复结果。</p>

<p>按照上述程序，请你返回所有可能输出字符串&nbsp;<code>s</code>&nbsp;的数组方案数。</p>

<p>由于数组方案数可能会很大，请你返回它对&nbsp;<code>10^9 + 7</code>&nbsp;<strong>取余</strong>&nbsp;后的结果。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = &quot;1000&quot;, k = 10000
<strong>输出：</strong>1
<strong>解释：</strong>唯一一种可能的数组方案是 [1000]
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = &quot;1000&quot;, k = 10
<strong>输出：</strong>0
<strong>解释：</strong>不存在任何数组方案满足所有整数都 &gt;= 1 且 &lt;= 10 同时输出结果为 s 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>s = &quot;1317&quot;, k = 2000
<strong>输出：</strong>8
<strong>解释：</strong>可行的数组方案为 [1317]，[131,7]，[13,17]，[1,317]，[13,1,7]，[1,31,7]，[1,3,17]，[1,3,1,7]
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>s = &quot;2020&quot;, k = 30
<strong>输出：</strong>1
<strong>解释：</strong>唯一可能的数组方案是 [20,20] 。 [2020] 不是可行的数组方案，原因是 2020 &gt; 30 。 [2,020] 也不是可行的数组方案，因为 020 含有前导 0 。
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>s = &quot;1234567890&quot;, k = 90
<strong>输出：</strong>34
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10^5</code>.</li>
	<li><code>s</code>&nbsp;只包含数字且不包含前导 0 。</li>
	<li><code>1 &lt;= k &lt;= 10^9</code>.</li>
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

# [1417. 重新格式化字符串](https://leetcode.cn/problems/reformat-the-string){#1417}

{{< tabs "1417" >}}

{{% tab "python" %}}
```python
class Solution:
    def reformat(self, s: str) -> str:
        a = [c for c in s if c.islower()]
        b = [c for c in s if c.isdigit()]
        if abs(len(a) - len(b)) > 1:
            return ''
        if len(a) < len(b):
            a, b = b, a
        ans = []
        for x, y in zip(a, b):
            ans.append(x + y)
        if len(a) > len(b):
            ans.append(a[-1])
        return ''.join(ans)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String reformat(String s) {
        StringBuilder a = new StringBuilder();
        StringBuilder b = new StringBuilder();
        for (char c : s.toCharArray()) {
            if (Character.isDigit(c)) {
                a.append(c);
            } else {
                b.append(c);
            }
        }
        int m = a.length(), n = b.length();
        if (Math.abs(m - n) > 1) {
            return "";
        }
        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < Math.min(m, n); ++i) {
            if (m > n) {
                ans.append(a.charAt(i));
                ans.append(b.charAt(i));
            } else {
                ans.append(b.charAt(i));
                ans.append(a.charAt(i));
            }
        }
        if (m > n) {
            ans.append(a.charAt(m - 1));
        }
        if (m < n) {
            ans.append(b.charAt(n - 1));
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
    string reformat(string s) {
        string a = "", b = "";
        for (char c : s) {
            if (isdigit(c))
                a += c;
            else
                b += c;
        }
        int m = a.size(), n = b.size();
        if (abs(m - n) > 1) return "";
        string ans = "";
        for (int i = 0; i < min(m, n); ++i) {
            if (m > n) {
                ans += a[i];
                ans += b[i];
            } else {
                ans += b[i];
                ans += a[i];
            }
        }
        if (m > n) ans += a[m - 1];
        if (m < n) ans += b[n - 1];
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func reformat(s string) string {
	a := []byte{}
	b := []byte{}
	for _, c := range s {
		if unicode.IsLetter(c) {
			a = append(a, byte(c))
		} else {
			b = append(b, byte(c))
		}
	}
	if len(a) < len(b) {
		a, b = b, a
	}
	if len(a)-len(b) > 1 {
		return ""
	}
	var ans strings.Builder
	for i := range b {
		ans.WriteByte(a[i])
		ans.WriteByte(b[i])
	}
	if len(a) > len(b) {
		ans.WriteByte(a[len(a)-1])
	}
	return ans.String()
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个混合了数字和字母的字符串 <code>s</code>，其中的字母均为小写英文字母。</p>

<p>请你将该字符串重新格式化，使得任意两个相邻字符的类型都不同。也就是说，字母后面应该跟着数字，而数字后面应该跟着字母。</p>

<p>请你返回 <strong>重新格式化后</strong> 的字符串；如果无法按要求重新格式化，则返回一个 <strong>空字符串</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = &quot;a0b1c2&quot;
<strong>输出：</strong>&quot;0a1b2c&quot;
<strong>解释：</strong>&quot;0a1b2c&quot; 中任意两个相邻字符的类型都不同。 &quot;a0b1c2&quot;, &quot;0a1b2c&quot;, &quot;0c2a1b&quot; 也是满足题目要求的答案。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = &quot;leetcode&quot;
<strong>输出：</strong>&quot;&quot;
<strong>解释：</strong>&quot;leetcode&quot; 中只有字母，所以无法满足重新格式化的条件。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>s = &quot;1229857369&quot;
<strong>输出：</strong>&quot;&quot;
<strong>解释：</strong>&quot;1229857369&quot; 中只有数字，所以无法满足重新格式化的条件。
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>s = &quot;covid2019&quot;
<strong>输出：</strong>&quot;c2o0v1i9d&quot;
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>s = &quot;ab123&quot;
<strong>输出：</strong>&quot;1a2b3&quot;
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 500</code></li>
	<li><code>s</code> 仅由小写英文字母和/或数字组成。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

将字符串 $s$ 中的所有字符分成“数字”、“字母”两类，分别放入 $a$, $b$ 两个数组中。

比较 $a$, $b$ 两个数组的长度，若 $a$ 长度小于 $b$，则交换 $a$, $b$。接着判断两个数组长度差，若超过 $1$，则返回空字符串。

接着同时遍历两个数组，依次添加 $a$, $b$ 中对应字符到答案中。遍历结束，若 $a$ 长度大于 $b$，则添加 $a$ 的最后一个字符到答案中。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是字符串 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def reformat(self, s: str) -> str:
        a = [c for c in s if c.islower()]
        b = [c for c in s if c.isdigit()]
        if abs(len(a) - len(b)) > 1:
            return ''
        if len(a) < len(b):
            a, b = b, a
        ans = []
        for x, y in zip(a, b):
            ans.append(x + y)
        if len(a) > len(b):
            ans.append(a[-1])
        return ''.join(ans)
```

#### Java

```java
class Solution {
    public String reformat(String s) {
        StringBuilder a = new StringBuilder();
        StringBuilder b = new StringBuilder();
        for (char c : s.toCharArray()) {
            if (Character.isDigit(c)) {
                a.append(c);
            } else {
                b.append(c);
            }
        }
        int m = a.length(), n = b.length();
        if (Math.abs(m - n) > 1) {
            return "";
        }
        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < Math.min(m, n); ++i) {
            if (m > n) {
                ans.append(a.charAt(i));
                ans.append(b.charAt(i));
            } else {
                ans.append(b.charAt(i));
                ans.append(a.charAt(i));
            }
        }
        if (m > n) {
            ans.append(a.charAt(m - 1));
        }
        if (m < n) {
            ans.append(b.charAt(n - 1));
        }
        return ans.toString();
    }
}
```

#### C++

```cpp
class Solution {
public:
    string reformat(string s) {
        string a = "", b = "";
        for (char c : s) {
            if (isdigit(c))
                a += c;
            else
                b += c;
        }
        int m = a.size(), n = b.size();
        if (abs(m - n) > 1) return "";
        string ans = "";
        for (int i = 0; i < min(m, n); ++i) {
            if (m > n) {
                ans += a[i];
                ans += b[i];
            } else {
                ans += b[i];
                ans += a[i];
            }
        }
        if (m > n) ans += a[m - 1];
        if (m < n) ans += b[n - 1];
        return ans;
    }
};
```

#### Go

```go
func reformat(s string) string {
	a := []byte{}
	b := []byte{}
	for _, c := range s {
		if unicode.IsLetter(c) {
			a = append(a, byte(c))
		} else {
			b = append(b, byte(c))
		}
	}
	if len(a) < len(b) {
		a, b = b, a
	}
	if len(a)-len(b) > 1 {
		return ""
	}
	var ans strings.Builder
	for i := range b {
		ans.WriteByte(a[i])
		ans.WriteByte(b[i])
	}
	if len(a) > len(b) {
		ans.WriteByte(a[len(a)-1])
	}
	return ans.String()
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1418. 点菜展示表](https://leetcode.cn/problems/display-table-of-food-orders-in-a-restaurant){#1418}

{{< tabs "1418" >}}

{{% tab "python" %}}
```python
class Solution:
    def displayTable(self, orders: List[List[str]]) -> List[List[str]]:
        tables = defaultdict(list)
        items = set()
        for _, table, foodItem in orders:
            tables[int(table)].append(foodItem)
            items.add(foodItem)
        sorted_items = sorted(items)
        ans = [["Table"] + sorted_items]
        for table in sorted(tables):
            cnt = Counter(tables[table])
            row = [str(table)] + [str(cnt[item]) for item in sorted_items]
            ans.append(row)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<List<String>> displayTable(List<List<String>> orders) {
        TreeMap<Integer, List<String>> tables = new TreeMap<>();
        Set<String> items = new HashSet<>();
        for (List<String> o : orders) {
            int table = Integer.parseInt(o.get(1));
            String foodItem = o.get(2);
            tables.computeIfAbsent(table, k -> new ArrayList<>()).add(foodItem);
            items.add(foodItem);
        }
        List<String> sortedItems = new ArrayList<>(items);
        Collections.sort(sortedItems);
        List<List<String>> ans = new ArrayList<>();
        List<String> header = new ArrayList<>();
        header.add("Table");
        header.addAll(sortedItems);
        ans.add(header);
        for (Map.Entry<Integer, List<String>> entry : tables.entrySet()) {
            Map<String, Integer> cnt = new HashMap<>();
            for (String item : entry.getValue()) {
                cnt.merge(item, 1, Integer::sum);
            }
            List<String> row = new ArrayList<>();
            row.add(String.valueOf(entry.getKey()));
            for (String item : sortedItems) {
                row.add(String.valueOf(cnt.getOrDefault(item, 0)));
            }
            ans.add(row);
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
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        map<int, vector<string>> tables;
        set<string> sortedItems;
        for (auto& o : orders) {
            int table = stoi(o[1]);
            string foodItem = o[2];
            tables[table].push_back(foodItem);
            sortedItems.insert(foodItem);
        }
        vector<vector<string>> ans;
        vector<string> header = {"Table"};
        header.insert(header.end(), sortedItems.begin(), sortedItems.end());
        ans.push_back(header);
        for (auto& [table, items] : tables) {
            unordered_map<string, int> cnt;
            for (string& item : items) {
                cnt[item]++;
            }
            vector<string> row;
            row.push_back(to_string(table));
            for (const string& item : sortedItems) {
                row.push_back(to_string(cnt[item]));
            }
            ans.push_back(row);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func displayTable(orders [][]string) [][]string {
	tables := make(map[int]map[string]int)
	items := make(map[string]bool)
	for _, order := range orders {
		table, _ := strconv.Atoi(order[1])
		foodItem := order[2]
		if tables[table] == nil {
			tables[table] = make(map[string]int)
		}
		tables[table][foodItem]++
		items[foodItem] = true
	}
	sortedItems := make([]string, 0, len(items))
	for item := range items {
		sortedItems = append(sortedItems, item)
	}
	sort.Strings(sortedItems)
	ans := [][]string{}
	header := append([]string{"Table"}, sortedItems...)
	ans = append(ans, header)
	tableNums := make([]int, 0, len(tables))
	for table := range tables {
		tableNums = append(tableNums, table)
	}
	sort.Ints(tableNums)
	for _, table := range tableNums {
		row := []string{strconv.Itoa(table)}
		for _, item := range sortedItems {
			count := tables[table][item]
			row = append(row, strconv.Itoa(count))
		}
		ans = append(ans, row)
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function displayTable(orders: string[][]): string[][] {
    const tables: Record<number, Record<string, number>> = {};
    const items: Set<string> = new Set();
    for (const [_, table, foodItem] of orders) {
        const t = +table;
        if (!tables[t]) {
            tables[t] = {};
        }
        if (!tables[t][foodItem]) {
            tables[t][foodItem] = 0;
        }
        tables[t][foodItem]++;
        items.add(foodItem);
    }
    const sortedItems = Array.from(items).sort();
    const ans: string[][] = [];
    const header: string[] = ['Table', ...sortedItems];
    ans.push(header);
    const sortedTableNumbers = Object.keys(tables)
        .map(Number)
        .sort((a, b) => a - b);
    for (const table of sortedTableNumbers) {
        const row: string[] = [table.toString()];
        for (const item of sortedItems) {
            row.push((tables[table][item] || 0).toString());
        }
        ans.push(row);
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

<p>给你一个数组 <code>orders</code>，表示客户在餐厅中完成的订单，确切地说， <code>orders[i]=[customerName<sub>i</sub>,tableNumber<sub>i</sub>,foodItem<sub>i</sub>]</code> ，其中 <code>customerName<sub>i</sub></code> 是客户的姓名，<code>tableNumber<sub>i</sub></code> 是客户所在餐桌的桌号，而 <code>foodItem<sub>i</sub></code> 是客户点的餐品名称。</p>

<p>请你返回该餐厅的 <strong>点菜展示表</strong><em> 。</em>在这张表中，表中第一行为标题，其第一列为餐桌桌号 &ldquo;Table&rdquo; ，后面每一列都是按字母顺序排列的餐品名称。接下来每一行中的项则表示每张餐桌订购的相应餐品数量，第一列应当填对应的桌号，后面依次填写下单的餐品数量。</p>

<p>注意：客户姓名不是点菜展示表的一部分。此外，表中的数据行应该按餐桌桌号升序排列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>orders = [[&quot;David&quot;,&quot;3&quot;,&quot;Ceviche&quot;],[&quot;Corina&quot;,&quot;10&quot;,&quot;Beef Burrito&quot;],[&quot;David&quot;,&quot;3&quot;,&quot;Fried Chicken&quot;],[&quot;Carla&quot;,&quot;5&quot;,&quot;Water&quot;],[&quot;Carla&quot;,&quot;5&quot;,&quot;Ceviche&quot;],[&quot;Rous&quot;,&quot;3&quot;,&quot;Ceviche&quot;]]
<strong>输出：</strong>[[&quot;Table&quot;,&quot;Beef Burrito&quot;,&quot;Ceviche&quot;,&quot;Fried Chicken&quot;,&quot;Water&quot;],[&quot;3&quot;,&quot;0&quot;,&quot;2&quot;,&quot;1&quot;,&quot;0&quot;],[&quot;5&quot;,&quot;0&quot;,&quot;1&quot;,&quot;0&quot;,&quot;1&quot;],[&quot;10&quot;,&quot;1&quot;,&quot;0&quot;,&quot;0&quot;,&quot;0&quot;]] 
<strong>解释：
</strong>点菜展示表如下所示：
<strong>Table,Beef Burrito,Ceviche,Fried Chicken,Water</strong>
3    ,0           ,2      ,1            ,0
5    ,0           ,1      ,0            ,1
10   ,1           ,0      ,0            ,0
对于餐桌 3：David 点了 &quot;Ceviche&quot; 和 &quot;Fried Chicken&quot;，而 Rous 点了 &quot;Ceviche&quot;
而餐桌 5：Carla 点了 &quot;Water&quot; 和 &quot;Ceviche&quot;
餐桌 10：Corina 点了 &quot;Beef Burrito&quot; 
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>orders = [[&quot;James&quot;,&quot;12&quot;,&quot;Fried Chicken&quot;],[&quot;Ratesh&quot;,&quot;12&quot;,&quot;Fried Chicken&quot;],[&quot;Amadeus&quot;,&quot;12&quot;,&quot;Fried Chicken&quot;],[&quot;Adam&quot;,&quot;1&quot;,&quot;Canadian Waffles&quot;],[&quot;Brianna&quot;,&quot;1&quot;,&quot;Canadian Waffles&quot;]]
<strong>输出：</strong>[[&quot;Table&quot;,&quot;Canadian Waffles&quot;,&quot;Fried Chicken&quot;],[&quot;1&quot;,&quot;2&quot;,&quot;0&quot;],[&quot;12&quot;,&quot;0&quot;,&quot;3&quot;]] 
<strong>解释：</strong>
对于餐桌 1：Adam 和 Brianna 都点了 &quot;Canadian Waffles&quot;
而餐桌 12：James, Ratesh 和 Amadeus 都点了 &quot;Fried Chicken&quot;
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>orders = [[&quot;Laura&quot;,&quot;2&quot;,&quot;Bean Burrito&quot;],[&quot;Jhon&quot;,&quot;2&quot;,&quot;Beef Burrito&quot;],[&quot;Melissa&quot;,&quot;2&quot;,&quot;Soda&quot;]]
<strong>输出：</strong>[[&quot;Table&quot;,&quot;Bean Burrito&quot;,&quot;Beef Burrito&quot;,&quot;Soda&quot;],[&quot;2&quot;,&quot;1&quot;,&quot;1&quot;,&quot;1&quot;]]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;=&nbsp;orders.length &lt;= 5 * 10^4</code></li>
	<li><code>orders[i].length == 3</code></li>
	<li><code>1 &lt;= customerName<sub>i</sub>.length, foodItem<sub>i</sub>.length &lt;= 20</code></li>
	<li><code>customerName<sub>i</sub></code> 和 <code>foodItem<sub>i</sub></code> 由大小写英文字母及空格字符 <code>&#39; &#39;</code> 组成。</li>
	<li><code>tableNumber<sub>i</sub></code> 是 <code>1</code> 到 <code>500</code> 范围内的整数。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 排序

我们可以用一个哈希表 $\textit{tables}$ 来存储每张餐桌点的菜品，用一个集合 $\textit{items}$ 来存储所有的菜品。

遍历 $\textit{orders}$，将每张餐桌点的菜品存入 $\textit{tables}$ 和 $\textit{items}$ 中。

然后我们将 $\textit{items}$ 排序，得到 $\textit{sortedItems}$。

接下来，我们构建答案数组 $\textit{ans}$，首先将标题行 $\textit{header}$ 加入 $\textit{ans}$，然后遍历排序后的 $\textit{tables}$，对于每张餐桌，我们用一个计数器 $\textit{cnt}$ 来统计每种菜品的数量，然后构建一行 $\textit{row}$，将其加入 $\textit{ans}$。

最后返回 $\textit{ans}$。

时间复杂度 $O(n + m \times \log m + k \times \log k + m \times k)$，空间复杂度 $O(n + m + k)$。其中 $n$ 是数组 $\textit{orders}$ 的长度，而 $m$ 和 $k$ 分别表示菜品种类数和餐桌数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def displayTable(self, orders: List[List[str]]) -> List[List[str]]:
        tables = defaultdict(list)
        items = set()
        for _, table, foodItem in orders:
            tables[int(table)].append(foodItem)
            items.add(foodItem)
        sorted_items = sorted(items)
        ans = [["Table"] + sorted_items]
        for table in sorted(tables):
            cnt = Counter(tables[table])
            row = [str(table)] + [str(cnt[item]) for item in sorted_items]
            ans.append(row)
        return ans
```

#### Java

```java
class Solution {
    public List<List<String>> displayTable(List<List<String>> orders) {
        TreeMap<Integer, List<String>> tables = new TreeMap<>();
        Set<String> items = new HashSet<>();
        for (List<String> o : orders) {
            int table = Integer.parseInt(o.get(1));
            String foodItem = o.get(2);
            tables.computeIfAbsent(table, k -> new ArrayList<>()).add(foodItem);
            items.add(foodItem);
        }
        List<String> sortedItems = new ArrayList<>(items);
        Collections.sort(sortedItems);
        List<List<String>> ans = new ArrayList<>();
        List<String> header = new ArrayList<>();
        header.add("Table");
        header.addAll(sortedItems);
        ans.add(header);
        for (Map.Entry<Integer, List<String>> entry : tables.entrySet()) {
            Map<String, Integer> cnt = new HashMap<>();
            for (String item : entry.getValue()) {
                cnt.merge(item, 1, Integer::sum);
            }
            List<String> row = new ArrayList<>();
            row.add(String.valueOf(entry.getKey()));
            for (String item : sortedItems) {
                row.add(String.valueOf(cnt.getOrDefault(item, 0)));
            }
            ans.add(row);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        map<int, vector<string>> tables;
        set<string> sortedItems;
        for (auto& o : orders) {
            int table = stoi(o[1]);
            string foodItem = o[2];
            tables[table].push_back(foodItem);
            sortedItems.insert(foodItem);
        }
        vector<vector<string>> ans;
        vector<string> header = {"Table"};
        header.insert(header.end(), sortedItems.begin(), sortedItems.end());
        ans.push_back(header);
        for (auto& [table, items] : tables) {
            unordered_map<string, int> cnt;
            for (string& item : items) {
                cnt[item]++;
            }
            vector<string> row;
            row.push_back(to_string(table));
            for (const string& item : sortedItems) {
                row.push_back(to_string(cnt[item]));
            }
            ans.push_back(row);
        }
        return ans;
    }
};
```

#### Go

```go
func displayTable(orders [][]string) [][]string {
	tables := make(map[int]map[string]int)
	items := make(map[string]bool)
	for _, order := range orders {
		table, _ := strconv.Atoi(order[1])
		foodItem := order[2]
		if tables[table] == nil {
			tables[table] = make(map[string]int)
		}
		tables[table][foodItem]++
		items[foodItem] = true
	}
	sortedItems := make([]string, 0, len(items))
	for item := range items {
		sortedItems = append(sortedItems, item)
	}
	sort.Strings(sortedItems)
	ans := [][]string{}
	header := append([]string{"Table"}, sortedItems...)
	ans = append(ans, header)
	tableNums := make([]int, 0, len(tables))
	for table := range tables {
		tableNums = append(tableNums, table)
	}
	sort.Ints(tableNums)
	for _, table := range tableNums {
		row := []string{strconv.Itoa(table)}
		for _, item := range sortedItems {
			count := tables[table][item]
			row = append(row, strconv.Itoa(count))
		}
		ans = append(ans, row)
	}
	return ans
}
```

#### TypeScript

```ts
function displayTable(orders: string[][]): string[][] {
    const tables: Record<number, Record<string, number>> = {};
    const items: Set<string> = new Set();
    for (const [_, table, foodItem] of orders) {
        const t = +table;
        if (!tables[t]) {
            tables[t] = {};
        }
        if (!tables[t][foodItem]) {
            tables[t][foodItem] = 0;
        }
        tables[t][foodItem]++;
        items.add(foodItem);
    }
    const sortedItems = Array.from(items).sort();
    const ans: string[][] = [];
    const header: string[] = ['Table', ...sortedItems];
    ans.push(header);
    const sortedTableNumbers = Object.keys(tables)
        .map(Number)
        .sort((a, b) => a - b);
    for (const table of sortedTableNumbers) {
        const row: string[] = [table.toString()];
        for (const item of sortedItems) {
            row.push((tables[table][item] || 0).toString());
        }
        ans.push(row);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1419. 数青蛙](https://leetcode.cn/problems/minimum-number-of-frogs-croaking){#1419}

{{< tabs "1419" >}}

{{% tab "python" %}}
```python
class Solution:
    def minNumberOfFrogs(self, croakOfFrogs: str) -> int:
        if len(croakOfFrogs) % 5 != 0:
            return -1
        idx = {c: i for i, c in enumerate('croak')}
        cnt = [0] * 5
        ans = x = 0
        for i in map(idx.get, croakOfFrogs):
            cnt[i] += 1
            if i == 0:
                x += 1
                ans = max(ans, x)
            else:
                if cnt[i - 1] == 0:
                    return -1
                cnt[i - 1] -= 1
                if i == 4:
                    x -= 1
        return -1 if x else ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minNumberOfFrogs(String croakOfFrogs) {
        int n = croakOfFrogs.length();
        if (n % 5 != 0) {
            return -1;
        }
        int[] idx = new int[26];
        String s = "croak";
        for (int i = 0; i < 5; ++i) {
            idx[s.charAt(i) - 'a'] = i;
        }
        int[] cnt = new int[5];
        int ans = 0, x = 0;
        for (int k = 0; k < n; ++k) {
            int i = idx[croakOfFrogs.charAt(k) - 'a'];
            ++cnt[i];
            if (i == 0) {
                ans = Math.max(ans, ++x);
            } else {
                if (--cnt[i - 1] < 0) {
                    return -1;
                }
                if (i == 4) {
                    --x;
                }
            }
        }
        return x > 0 ? -1 : ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int n = croakOfFrogs.size();
        if (n % 5 != 0) {
            return -1;
        }
        int idx[26]{};
        string s = "croak";
        for (int i = 0; i < 5; ++i) {
            idx[s[i] - 'a'] = i;
        }
        int cnt[5]{};
        int ans = 0, x = 0;
        for (char& c : croakOfFrogs) {
            int i = idx[c - 'a'];
            ++cnt[i];
            if (i == 0) {
                ans = max(ans, ++x);
            } else {
                if (--cnt[i - 1] < 0) {
                    return -1;
                }
                if (i == 4) {
                    --x;
                }
            }
        }
        return x > 0 ? -1 : ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minNumberOfFrogs(croakOfFrogs string) int {
	n := len(croakOfFrogs)
	if n%5 != 0 {
		return -1
	}
	idx := [26]int{}
	for i, c := range "croak" {
		idx[c-'a'] = i
	}
	cnt := [5]int{}
	ans, x := 0, 0
	for _, c := range croakOfFrogs {
		i := idx[c-'a']
		cnt[i]++
		if i == 0 {
			x++
			ans = max(ans, x)
		} else {
			cnt[i-1]--
			if cnt[i-1] < 0 {
				return -1
			}
			if i == 4 {
				x--
			}
		}
	}
	if x > 0 {
		return -1
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minNumberOfFrogs(croakOfFrogs: string): number {
    const n = croakOfFrogs.length;
    if (n % 5 !== 0) {
        return -1;
    }
    const idx = (c: string): number => 'croak'.indexOf(c);
    const cnt: number[] = [0, 0, 0, 0, 0];
    let ans = 0;
    let x = 0;
    for (const c of croakOfFrogs) {
        const i = idx(c);
        ++cnt[i];
        if (i === 0) {
            ans = Math.max(ans, ++x);
        } else {
            if (--cnt[i - 1] < 0) {
                return -1;
            }
            if (i === 4) {
                --x;
            }
        }
    }
    return x > 0 ? -1 : ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串 <code>croakOfFrogs</code>，它表示不同青蛙发出的蛙鸣声（字符串 <code>"croak"</code> ）的组合。由于同一时间可以有多只青蛙呱呱作响，所以&nbsp;<code>croakOfFrogs</code> 中会混合多个 <code>“croak”</code> <em>。</em></p>

<p>请你返回模拟字符串中所有蛙鸣所需不同青蛙的最少数目。</p>

<p>要想发出蛙鸣 "croak"，青蛙必须 <strong>依序</strong> 输出 <code>‘c’, ’r’, ’o’, ’a’, ’k’</code> 这 5 个字母。如果没有输出全部五个字母，那么它就不会发出声音。如果字符串 <code>croakOfFrogs</code> 不是由若干有效的 "croak" 字符混合而成，请返回 <code>-1</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>croakOfFrogs = "croakcroak"
<strong>输出：</strong>1 
<strong>解释：</strong>一只青蛙 “呱呱” 两次
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>croakOfFrogs = "crcoakroak"
<strong>输出：</strong>2 
<strong>解释：</strong>最少需要两只青蛙，“呱呱” 声用黑体标注
第一只青蛙 "<strong>cr</strong>c<strong>oak</strong>roak"
第二只青蛙 "cr<strong>c</strong>oak<strong>roak</strong>"
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>croakOfFrogs = "croakcrook"
<strong>输出：</strong>-1
<strong>解释：</strong>给出的字符串不是 "croak<strong>"</strong> 的有效组合。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= croakOfFrogs.length &lt;= 10<sup>5</sup></code></li>
	<li>字符串中的字符只有 <code>'c'</code>, <code>'r'</code>, <code>'o'</code>, <code>'a'</code> 或者 <code>'k'</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数 + 模拟

我们注意到，如果字符串 `croakOfFrogs` 是由若干有效的 `"croak"` 字符混合而成，那么它的长度一定是 $5$ 的倍数。因此，如果字符串的长度不是 $5$ 的倍数，可以直接返回 $-1$。

接下来，我们将 `'c'`, `'r'`, `'o'`, `'a'`, `'k'` 这 $5$ 个字母分别对应下标 $0$ 到 $4$，用一个长度为 $5$ 的数组 $cnt$ 记录字符串 `croakOfFrogs` 中每个字母出现的次数，其中 $cnt[i]$ 表示当前下标为 $i$ 的字母出现的次数。另外，我们定义一个整数变量 $x$ 表示当前未完成蛙鸣的青蛙的数目，需要的青蛙的最少数目 $ans$ 即为 $x$ 的最大值。

我们遍历字符串 `croakOfFrogs` 中的每个字母 $c$，找到 $c$ 对应的下标 $i$，然后将 $cnt[i]$ 加 $1$。接下来，根据 $i$ 值的不同，我们分别进行如下操作：

-   如果 $i=0$，那么当前有一个新的青蛙开始蛙鸣，因此令 $x$ 的值加 $1$，然后我们更新 $ans = \max(ans, x)$；
-   否则，如果 $cnt[i-1]=0$，那么表示当前没有青蛙可以发出字母 $c$，无法完成蛙鸣，返回 $-1$，否则我们令 $cnt[i-1]$ 减 $1$。如果 $i=4$，那么表示青蛙已经完成了一个蛙鸣，因此令 $x$ 的值减 $1$。

遍历结束后，如果 $x=0$，那么说明青蛙已经完成了所有的蛙鸣，返回 $ans$，否则返回 $-1$。

时间复杂度 $O(n)$，空间复杂度 $O(C)$。其中 $n$ 是字符串 `croakOfFrogs` 的长度；而 $C$ 是字符集的大小，本题中 $C=26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minNumberOfFrogs(self, croakOfFrogs: str) -> int:
        if len(croakOfFrogs) % 5 != 0:
            return -1
        idx = {c: i for i, c in enumerate('croak')}
        cnt = [0] * 5
        ans = x = 0
        for i in map(idx.get, croakOfFrogs):
            cnt[i] += 1
            if i == 0:
                x += 1
                ans = max(ans, x)
            else:
                if cnt[i - 1] == 0:
                    return -1
                cnt[i - 1] -= 1
                if i == 4:
                    x -= 1
        return -1 if x else ans
```

#### Java

```java
class Solution {
    public int minNumberOfFrogs(String croakOfFrogs) {
        int n = croakOfFrogs.length();
        if (n % 5 != 0) {
            return -1;
        }
        int[] idx = new int[26];
        String s = "croak";
        for (int i = 0; i < 5; ++i) {
            idx[s.charAt(i) - 'a'] = i;
        }
        int[] cnt = new int[5];
        int ans = 0, x = 0;
        for (int k = 0; k < n; ++k) {
            int i = idx[croakOfFrogs.charAt(k) - 'a'];
            ++cnt[i];
            if (i == 0) {
                ans = Math.max(ans, ++x);
            } else {
                if (--cnt[i - 1] < 0) {
                    return -1;
                }
                if (i == 4) {
                    --x;
                }
            }
        }
        return x > 0 ? -1 : ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int n = croakOfFrogs.size();
        if (n % 5 != 0) {
            return -1;
        }
        int idx[26]{};
        string s = "croak";
        for (int i = 0; i < 5; ++i) {
            idx[s[i] - 'a'] = i;
        }
        int cnt[5]{};
        int ans = 0, x = 0;
        for (char& c : croakOfFrogs) {
            int i = idx[c - 'a'];
            ++cnt[i];
            if (i == 0) {
                ans = max(ans, ++x);
            } else {
                if (--cnt[i - 1] < 0) {
                    return -1;
                }
                if (i == 4) {
                    --x;
                }
            }
        }
        return x > 0 ? -1 : ans;
    }
};
```

#### Go

```go
func minNumberOfFrogs(croakOfFrogs string) int {
	n := len(croakOfFrogs)
	if n%5 != 0 {
		return -1
	}
	idx := [26]int{}
	for i, c := range "croak" {
		idx[c-'a'] = i
	}
	cnt := [5]int{}
	ans, x := 0, 0
	for _, c := range croakOfFrogs {
		i := idx[c-'a']
		cnt[i]++
		if i == 0 {
			x++
			ans = max(ans, x)
		} else {
			cnt[i-1]--
			if cnt[i-1] < 0 {
				return -1
			}
			if i == 4 {
				x--
			}
		}
	}
	if x > 0 {
		return -1
	}
	return ans
}
```

#### TypeScript

```ts
function minNumberOfFrogs(croakOfFrogs: string): number {
    const n = croakOfFrogs.length;
    if (n % 5 !== 0) {
        return -1;
    }
    const idx = (c: string): number => 'croak'.indexOf(c);
    const cnt: number[] = [0, 0, 0, 0, 0];
    let ans = 0;
    let x = 0;
    for (const c of croakOfFrogs) {
        const i = idx(c);
        ++cnt[i];
        if (i === 0) {
            ans = Math.max(ans, ++x);
        } else {
            if (--cnt[i - 1] < 0) {
                return -1;
            }
            if (i === 4) {
                --x;
            }
        }
    }
    return x > 0 ? -1 : ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
