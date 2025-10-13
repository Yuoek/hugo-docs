---
title: "1930_长度为 3 的不同回文子序列"
date: 2025-10-08T18:38:49+08:00
weight: 4
tags: [二分查找, 二叉树, 位运算, 前缀和, 动态规划, 哈希表, 字典树, 字符串, 数据库, 数组, 树, 深度优先搜索, 矩阵, 贪心]
---

{{< markmap >}}
### [1930_长度为 3 的不同回文子序列](#1930)
#### [位运算](#1930)
#### [哈希表](#1930)
#### [字符串](#1930)
#### [前缀和](#1930)
### [1931_用三种不同颜色为网格涂色](#1931)
#### [动态规划](#1931)
### [1932_合并多棵二叉搜索树](#1932)
#### [树](#1932)
#### [深度优先搜索](#1932)
#### [哈希表](#1932)
#### [二分查找](#1932)
#### [二叉树](#1932)
### [1933_判断字符串是否可分解为值均等的子串 🔒](#1933)
#### [字符串](#1933)
### [1934_确认率](#1934)
#### [数据库](#1934)
### [1935_可以输入的最大单词数](#1935)
#### [哈希表](#1935)
#### [字符串](#1935)
### [1936_新增的最少台阶数](#1936)
#### [贪心](#1936)
#### [数组](#1936)
### [1937_扣分后的最大得分](#1937)
#### [数组](#1937)
#### [动态规划](#1937)
#### [矩阵](#1937)
### [1938_查询最大基因差](#1938)
#### [位运算](#1938)
#### [深度优先搜索](#1938)
#### [字典树](#1938)
#### [数组](#1938)
#### [哈希表](#1938)
### [1939_主动请求确认消息的用户 🔒](#1939)
#### [数据库](#1939)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1930_长度为 3 的不同回文子序列
___
#### 位运算
___
#### 哈希表
___
#### 字符串
___
#### 前缀和
---
### 1931_用三种不同颜色为网格涂色
___
#### 动态规划
---
### 1932_合并多棵二叉搜索树
___
#### 树
___
#### 深度优先搜索
___
#### 哈希表
___
#### 二分查找
___
#### 二叉树
---
### 1933_判断字符串是否可分解为值均等的子串 🔒
___
#### 字符串
---
### 1934_确认率
___
#### 数据库
---
### 1935_可以输入的最大单词数
___
#### 哈希表
___
#### 字符串
---
### 1936_新增的最少台阶数
___
#### 贪心
___
#### 数组
---
### 1937_扣分后的最大得分
___
#### 数组
___
#### 动态规划
___
#### 矩阵
---
### 1938_查询最大基因差
___
#### 位运算
___
#### 深度优先搜索
___
#### 字典树
___
#### 数组
___
#### 哈希表
---
### 1939_主动请求确认消息的用户 🔒
___
#### 数据库
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 二叉树 | 位运算 |
| 前缀和 | 动态规划 | 哈希表 |
| 字典树 | 字符串 | 数据库 |
| 数组 | 树 | 深度优先搜索 |
| 矩阵 | 贪心 |  |

# [1930. 长度为 3 的不同回文子序列](https://leetcode.cn/problems/unique-length-3-palindromic-subsequences){#1930}

{{< tabs "1930" >}}

{{% tab "python" %}}
```python
class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        ans = 0
        for c in ascii_lowercase:
            l, r = s.find(c), s.rfind(c)
            if r - l > 1:
                ans += len(set(s[l + 1 : r]))
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countPalindromicSubsequence(String s) {
        int ans = 0;
        for (char c = 'a'; c <= 'z'; ++c) {
            int l = s.indexOf(c), r = s.lastIndexOf(c);
            int mask = 0;
            for (int i = l + 1; i < r; ++i) {
                int j = s.charAt(i) - 'a';
                if ((mask >> j & 1) == 0) {
                    mask |= 1 << j;
                    ++ans;
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
    int countPalindromicSubsequence(string s) {
        int ans = 0;
        for (char c = 'a'; c <= 'z'; ++c) {
            int l = s.find_first_of(c), r = s.find_last_of(c);
            int mask = 0;
            for (int i = l + 1; i < r; ++i) {
                int j = s[i] - 'a';
                if (mask >> j & 1 ^ 1) {
                    mask |= 1 << j;
                    ++ans;
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
func countPalindromicSubsequence(s string) (ans int) {
	for c := 'a'; c <= 'z'; c++ {
		l, r := strings.Index(s, string(c)), strings.LastIndex(s, string(c))
		mask := 0
		for i := l + 1; i < r; i++ {
			j := int(s[i] - 'a')
			if mask>>j&1 == 0 {
				mask |= 1 << j
				ans++
			}
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countPalindromicSubsequence(s: string): number {
    let ans = 0;
    const a = 'a'.charCodeAt(0);
    for (let ch = 0; ch < 26; ++ch) {
        const c = String.fromCharCode(ch + a);
        const l = s.indexOf(c);
        const r = s.lastIndexOf(c);
        let mask = 0;
        for (let i = l + 1; i < r; ++i) {
            const j = s.charCodeAt(i) - a;
            if (((mask >> j) & 1) ^ 1) {
                mask |= 1 << j;
                ++ans;
            }
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
 * @return {number}
 */
var countPalindromicSubsequence = function (s) {
    let ans = 0;
    const a = 'a'.charCodeAt(0);
    for (let ch = 0; ch < 26; ++ch) {
        const c = String.fromCharCode(ch + a);
        const l = s.indexOf(c);
        const r = s.lastIndexOf(c);
        let mask = 0;
        for (let i = l + 1; i < r; ++i) {
            const j = s.charCodeAt(i) - a;
            if (((mask >> j) & 1) ^ 1) {
                mask |= 1 << j;
                ++ans;
            }
        }
    }
    return ans;
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int CountPalindromicSubsequence(string s) {
        int ans = 0;
        for (char c = 'a'; c <= 'z'; ++c) {
            int l = s.IndexOf(c), r = s.LastIndexOf(c);
            int mask = 0;
            for (int i = l + 1; i < r; ++i) {
                int j = s[i] - 'a';
                if ((mask >> j & 1) == 0) {
                    mask |= 1 << j;
                    ++ans;
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

<p>给你一个字符串 <code>s</code> ，返回 <code>s</code> 中 <strong>长度为 3 </strong>的<strong>不同回文子序列</strong> 的个数。</p>

<p>即便存在多种方法来构建相同的子序列，但相同的子序列只计数一次。</p>

<p><strong>回文</strong> 是正着读和反着读一样的字符串。</p>

<p><strong>子序列</strong> 是由原字符串删除其中部分字符（也可以不删除）且不改变剩余字符之间相对顺序形成的一个新字符串。</p>

<ul>
	<li>例如，<code>"ace"</code> 是 <code>"<strong><em>a</em></strong>b<strong><em>c</em></strong>d<strong><em>e</em></strong>"</code> 的一个子序列。</li>
</ul>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "aabca"
<strong>输出：</strong>3
<strong>解释：</strong>长度为 3 的 3 个回文子序列分别是：
- "aba" ("<strong><em>a</em></strong>a<strong><em>b</em></strong>c<strong><em>a</em></strong>" 的子序列)
- "aaa" ("<strong><em>aa</em></strong>bc<strong><em>a</em></strong>" 的子序列)
- "aca" ("<strong><em>a</em></strong>ab<strong><em>ca</em></strong>" 的子序列)
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "adc"
<strong>输出：</strong>0
<strong>解释：</strong>"adc" 不存在长度为 3 的回文子序列。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "bbcbaba"
<strong>输出：</strong>4
<strong>解释：</strong>长度为 3 的 4 个回文子序列分别是：
- "bbb" ("<strong><em>bb</em></strong>c<strong><em>b</em></strong>aba" 的子序列)
- "bcb" ("<strong><em>b</em></strong>b<strong><em>cb</em></strong>aba" 的子序列)
- "bab" ("<strong><em>b</em></strong>bcb<strong><em>ab</em></strong>a" 的子序列)
- "aba" ("bbcb<strong><em>aba</em></strong>" 的子序列)
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 <= s.length <= 10<sup>5</sup></code></li>
	<li><code>s</code> 仅由小写英文字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举两端字符 + 哈希表

由于字符串中只包含小写字母，因此我们可以直接枚举所有的两端字符。对于每一对两端字符 $c$，我们找出它们在字符串中第一次和最后一次出现的位置 $l$ 和 $r$，如果 $r - l > 1$，说明找到了满足条件的回文序列，我们将 $[l+1,..r-1]$ 之间的字符去重后统计个数，即为以 $c$ 为两端字符的回文序列个数，加入答案中。

枚举结束后，即可得到答案。

时间复杂度 $O(n \times |\Sigma|)$，其中 $n$ 为字符串长度，而 $\Sigma$ 为字符集大小，本题中 $|\Sigma| = 26$。空间复杂度 $O(|\Sigma|)$ 或 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        ans = 0
        for c in ascii_lowercase:
            l, r = s.find(c), s.rfind(c)
            if r - l > 1:
                ans += len(set(s[l + 1 : r]))
        return ans
```

#### Java

```java
class Solution {
    public int countPalindromicSubsequence(String s) {
        int ans = 0;
        for (char c = 'a'; c <= 'z'; ++c) {
            int l = s.indexOf(c), r = s.lastIndexOf(c);
            int mask = 0;
            for (int i = l + 1; i < r; ++i) {
                int j = s.charAt(i) - 'a';
                if ((mask >> j & 1) == 0) {
                    mask |= 1 << j;
                    ++ans;
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
    int countPalindromicSubsequence(string s) {
        int ans = 0;
        for (char c = 'a'; c <= 'z'; ++c) {
            int l = s.find_first_of(c), r = s.find_last_of(c);
            int mask = 0;
            for (int i = l + 1; i < r; ++i) {
                int j = s[i] - 'a';
                if (mask >> j & 1 ^ 1) {
                    mask |= 1 << j;
                    ++ans;
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func countPalindromicSubsequence(s string) (ans int) {
	for c := 'a'; c <= 'z'; c++ {
		l, r := strings.Index(s, string(c)), strings.LastIndex(s, string(c))
		mask := 0
		for i := l + 1; i < r; i++ {
			j := int(s[i] - 'a')
			if mask>>j&1 == 0 {
				mask |= 1 << j
				ans++
			}
		}
	}
	return
}
```

#### TypeScript

```ts
function countPalindromicSubsequence(s: string): number {
    let ans = 0;
    const a = 'a'.charCodeAt(0);
    for (let ch = 0; ch < 26; ++ch) {
        const c = String.fromCharCode(ch + a);
        const l = s.indexOf(c);
        const r = s.lastIndexOf(c);
        let mask = 0;
        for (let i = l + 1; i < r; ++i) {
            const j = s.charCodeAt(i) - a;
            if (((mask >> j) & 1) ^ 1) {
                mask |= 1 << j;
                ++ans;
            }
        }
    }
    return ans;
}
```

#### JavaScript

```js
/**
 * @param {string} s
 * @return {number}
 */
var countPalindromicSubsequence = function (s) {
    let ans = 0;
    const a = 'a'.charCodeAt(0);
    for (let ch = 0; ch < 26; ++ch) {
        const c = String.fromCharCode(ch + a);
        const l = s.indexOf(c);
        const r = s.lastIndexOf(c);
        let mask = 0;
        for (let i = l + 1; i < r; ++i) {
            const j = s.charCodeAt(i) - a;
            if (((mask >> j) & 1) ^ 1) {
                mask |= 1 << j;
                ++ans;
            }
        }
    }
    return ans;
};
```

#### C#

```cs
public class Solution {
    public int CountPalindromicSubsequence(string s) {
        int ans = 0;
        for (char c = 'a'; c <= 'z'; ++c) {
            int l = s.IndexOf(c), r = s.LastIndexOf(c);
            int mask = 0;
            for (int i = l + 1; i < r; ++i) {
                int j = s[i] - 'a';
                if ((mask >> j & 1) == 0) {
                    mask |= 1 << j;
                    ++ans;
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

# [1931. 用三种不同颜色为网格涂色](https://leetcode.cn/problems/painting-a-grid-with-three-different-colors){#1931}

{{< tabs "1931" >}}

{{% tab "python" %}}
```python
class Solution:
    def colorTheGrid(self, m: int, n: int) -> int:
        def f1(x: int) -> bool:
            last = -1
            for _ in range(m):
                if x % 3 == last:
                    return False
                last = x % 3
                x //= 3
            return True

        def f2(x: int, y: int) -> bool:
            for _ in range(m):
                if x % 3 == y % 3:
                    return False
                x, y = x // 3, y // 3
            return True

        mod = 10**9 + 7
        mx = 3**m
        valid = {i for i in range(mx) if f1(i)}
        d = defaultdict(list)
        for x in valid:
            for y in valid:
                if f2(x, y):
                    d[x].append(y)
        f = [int(i in valid) for i in range(mx)]
        for _ in range(n - 1):
            g = [0] * mx
            for i in valid:
                for j in d[i]:
                    g[i] = (g[i] + f[j]) % mod
            f = g
        return sum(f) % mod
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int m;

    public int colorTheGrid(int m, int n) {
        this.m = m;
        final int mod = (int) 1e9 + 7;
        int mx = (int) Math.pow(3, m);
        Set<Integer> valid = new HashSet<>();
        int[] f = new int[mx];
        for (int i = 0; i < mx; ++i) {
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
            int[] g = new int[mx];
            for (int i : valid) {
                for (int j : d.getOrDefault(i, List.of())) {
                    g[i] = (g[i] + f[j]) % mod;
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
        for (int i = 0; i < m; ++i) {
            if (x % 3 == last) {
                return false;
            }
            last = x % 3;
            x /= 3;
        }
        return true;
    }

    private boolean f2(int x, int y) {
        for (int i = 0; i < m; ++i) {
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
    int colorTheGrid(int m, int n) {
        auto f1 = [&](int x) {
            int last = -1;
            for (int i = 0; i < m; ++i) {
                if (x % 3 == last) {
                    return false;
                }
                last = x % 3;
                x /= 3;
            }
            return true;
        };
        auto f2 = [&](int x, int y) {
            for (int i = 0; i < m; ++i) {
                if (x % 3 == y % 3) {
                    return false;
                }
                x /= 3;
                y /= 3;
            }
            return true;
        };

        const int mod = 1e9 + 7;
        int mx = pow(3, m);
        unordered_set<int> valid;
        vector<int> f(mx);
        for (int i = 0; i < mx; ++i) {
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
            vector<int> g(mx);
            for (int i : valid) {
                for (int j : d[i]) {
                    g[i] = (g[i] + f[j]) % mod;
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
func colorTheGrid(m int, n int) (ans int) {
	f1 := func(x int) bool {
		last := -1
		for i := 0; i < m; i++ {
			if x%3 == last {
				return false
			}
			last = x % 3
			x /= 3
		}
		return true
	}
	f2 := func(x, y int) bool {
		for i := 0; i < m; i++ {
			if x%3 == y%3 {
				return false
			}
			x /= 3
			y /= 3
		}
		return true
	}
	mx := int(math.Pow(3, float64(m)))
	valid := map[int]bool{}
	f := make([]int, mx)
	for i := 0; i < mx; i++ {
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
		g := make([]int, mx)
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
function colorTheGrid(m: number, n: number): number {
    const f1 = (x: number): boolean => {
        let last = -1;
        for (let i = 0; i < m; ++i) {
            if (x % 3 === last) {
                return false;
            }
            last = x % 3;
            x = Math.floor(x / 3);
        }
        return true;
    };
    const f2 = (x: number, y: number): boolean => {
        for (let i = 0; i < m; ++i) {
            if (x % 3 === y % 3) {
                return false;
            }
            x = Math.floor(x / 3);
            y = Math.floor(y / 3);
        }
        return true;
    };
    const mx = 3 ** m;
    const valid = new Set<number>();
    const f: number[] = Array(mx).fill(0);
    for (let i = 0; i < mx; ++i) {
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
        const g: number[] = Array(mx).fill(0);
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

<p>给你两个整数 <code>m</code> 和 <code>n</code> 。构造一个 <code>m x n</code> 的网格，其中每个单元格最开始是白色。请你用 <strong>红、绿、蓝</strong> 三种颜色为每个单元格涂色。所有单元格都需要被涂色。</p>

<p>涂色方案需要满足：<strong>不存在相邻两个单元格颜色相同的情况</strong> 。返回网格涂色的方法数。因为答案可能非常大， 返回 <strong>对 </strong><code>10<sup>9</sup> + 7</code><strong> 取余</strong> 的结果。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1900-1999/1931.Painting%20a%20Grid%20With%20Three%20Different%20Colors/images/colorthegrid.png" style="width: 200px; height: 50px;" />
<pre>
<strong>输入：</strong>m = 1, n = 1
<strong>输出：</strong>3
<strong>解释：</strong>如上图所示，存在三种可能的涂色方案。
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1900-1999/1931.Painting%20a%20Grid%20With%20Three%20Different%20Colors/images/copy-of-colorthegrid.png" style="width: 321px; height: 121px;" />
<pre>
<strong>输入：</strong>m = 1, n = 2
<strong>输出：</strong>6
<strong>解释：</strong>如上图所示，存在六种可能的涂色方案。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>m = 5, n = 5
<strong>输出：</strong>580986
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= m <= 5</code></li>
	<li><code>1 <= n <= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：状态压缩 + 动态规划

我们注意到，网格的行数不超过 $5$，那么一列中最多有 $3^5=243$ 种不同的颜色方案。

因此，我们定义 $f[i][j]$ 表示前 $i$ 列中，第 $i$ 列的涂色状态为 $j$ 的方案数。状态 $f[i][j]$ 由 $f[i - 1][k]$ 转移而来，其中 $k$ 是第 $i - 1$ 列的涂色状态，且 $k$ 和 $j$ 满足不同颜色相邻的要求。即：

$$
f[i][j] = \sum_{k \in \textit{valid}(j)} f[i - 1][k]
$$

其中 $\textit{valid}(j)$ 表示状态 $j$ 的所有合法前驱状态。

最终的答案即为 $f[n][j]$ 的总和，其中 $j$ 是任意合法的状态。

我们注意到，$f[i][j]$ 只和 $f[i - 1][k]$ 有关，因此我们可以使用滚动数组优化空间复杂度。

时间复杂度 $O((m + n) \times 3^{2m})$，空间复杂度 $O(3^m)$。其中 $m$ 和 $n$ 分别是网格的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def colorTheGrid(self, m: int, n: int) -> int:
        def f1(x: int) -> bool:
            last = -1
            for _ in range(m):
                if x % 3 == last:
                    return False
                last = x % 3
                x //= 3
            return True

        def f2(x: int, y: int) -> bool:
            for _ in range(m):
                if x % 3 == y % 3:
                    return False
                x, y = x // 3, y // 3
            return True

        mod = 10**9 + 7
        mx = 3**m
        valid = {i for i in range(mx) if f1(i)}
        d = defaultdict(list)
        for x in valid:
            for y in valid:
                if f2(x, y):
                    d[x].append(y)
        f = [int(i in valid) for i in range(mx)]
        for _ in range(n - 1):
            g = [0] * mx
            for i in valid:
                for j in d[i]:
                    g[i] = (g[i] + f[j]) % mod
            f = g
        return sum(f) % mod
```

#### Java

```java
class Solution {
    private int m;

    public int colorTheGrid(int m, int n) {
        this.m = m;
        final int mod = (int) 1e9 + 7;
        int mx = (int) Math.pow(3, m);
        Set<Integer> valid = new HashSet<>();
        int[] f = new int[mx];
        for (int i = 0; i < mx; ++i) {
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
            int[] g = new int[mx];
            for (int i : valid) {
                for (int j : d.getOrDefault(i, List.of())) {
                    g[i] = (g[i] + f[j]) % mod;
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
        for (int i = 0; i < m; ++i) {
            if (x % 3 == last) {
                return false;
            }
            last = x % 3;
            x /= 3;
        }
        return true;
    }

    private boolean f2(int x, int y) {
        for (int i = 0; i < m; ++i) {
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
    int colorTheGrid(int m, int n) {
        auto f1 = [&](int x) {
            int last = -1;
            for (int i = 0; i < m; ++i) {
                if (x % 3 == last) {
                    return false;
                }
                last = x % 3;
                x /= 3;
            }
            return true;
        };
        auto f2 = [&](int x, int y) {
            for (int i = 0; i < m; ++i) {
                if (x % 3 == y % 3) {
                    return false;
                }
                x /= 3;
                y /= 3;
            }
            return true;
        };

        const int mod = 1e9 + 7;
        int mx = pow(3, m);
        unordered_set<int> valid;
        vector<int> f(mx);
        for (int i = 0; i < mx; ++i) {
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
            vector<int> g(mx);
            for (int i : valid) {
                for (int j : d[i]) {
                    g[i] = (g[i] + f[j]) % mod;
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
func colorTheGrid(m int, n int) (ans int) {
	f1 := func(x int) bool {
		last := -1
		for i := 0; i < m; i++ {
			if x%3 == last {
				return false
			}
			last = x % 3
			x /= 3
		}
		return true
	}
	f2 := func(x, y int) bool {
		for i := 0; i < m; i++ {
			if x%3 == y%3 {
				return false
			}
			x /= 3
			y /= 3
		}
		return true
	}
	mx := int(math.Pow(3, float64(m)))
	valid := map[int]bool{}
	f := make([]int, mx)
	for i := 0; i < mx; i++ {
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
		g := make([]int, mx)
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
function colorTheGrid(m: number, n: number): number {
    const f1 = (x: number): boolean => {
        let last = -1;
        for (let i = 0; i < m; ++i) {
            if (x % 3 === last) {
                return false;
            }
            last = x % 3;
            x = Math.floor(x / 3);
        }
        return true;
    };
    const f2 = (x: number, y: number): boolean => {
        for (let i = 0; i < m; ++i) {
            if (x % 3 === y % 3) {
                return false;
            }
            x = Math.floor(x / 3);
            y = Math.floor(y / 3);
        }
        return true;
    };
    const mx = 3 ** m;
    const valid = new Set<number>();
    const f: number[] = Array(mx).fill(0);
    for (let i = 0; i < mx; ++i) {
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
        const g: number[] = Array(mx).fill(0);
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

# [1932. 合并多棵二叉搜索树](https://leetcode.cn/problems/merge-bsts-to-create-single-bst){#1932}

{{< tabs "1932" >}}

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

<p>给你 <code>n</code> 个 <strong>二叉搜索树的根节点</strong> ，存储在数组 <code>trees</code> 中（<strong>下标从 0 开始</strong>），对应 <code>n</code> 棵不同的二叉搜索树。<code>trees</code> 中的每棵二叉搜索树 <strong>最多有 3 个节点</strong> ，且不存在值相同的两个根节点。在一步操作中，将会完成下述步骤：</p>

<ul>
	<li>选择两个 <strong>不同的</strong> 下标 <code>i</code> 和 <code>j</code> ，要求满足在&nbsp;<code>trees[i]</code> 中的某个 <strong>叶节点</strong> 的值等于&nbsp;<code>trees[j]</code> 的 <strong>根节点的值</strong> 。</li>
	<li>用&nbsp;<code>trees[j]</code> 替换 <code>trees[i]</code> 中的那个叶节点。</li>
	<li>从 <code>trees</code> 中移除 <code>trees[j]</code> 。</li>
</ul>

<p>如果在执行 <code>n - 1</code> 次操作后，能形成一棵有效的二叉搜索树，则返回结果二叉树的 <strong>根节点</strong> ；如果无法构造一棵有效的二叉搜索树<em>，</em>返回<em> </em><code>null</code> 。</p>

<p>二叉搜索树是一种二叉树，且树中每个节点均满足下述属性：</p>

<ul>
	<li>任意节点的左子树中的值都 <strong>严格小于</strong>&nbsp;此节点的值。</li>
	<li>任意节点的右子树中的值都 <strong>严格大于</strong>&nbsp;此节点的值。</li>
</ul>

<p>叶节点是不含子节点的节点。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1900-1999/1932.Merge%20BSTs%20to%20Create%20Single%20BST/images/d1.png" />
<pre>
<strong>输入：</strong>trees = [[2,1],[3,2,5],[5,4]]
<strong>输出：</strong>[3,2,5,1,null,4]
<strong>解释：</strong>
第一步操作中，选出 i=1 和 j=0 ，并将 trees[0] 合并到 trees[1] 中。
删除 trees[0] ，trees = [[3,2,5,1],[5,4]] 。
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1900-1999/1932.Merge%20BSTs%20to%20Create%20Single%20BST/images/diagram.png" />
在第二步操作中，选出 i=0 和 j=1 ，将 trees[1] 合并到 trees[0] 中。
删除 trees[1] ，trees = [[3,2,5,1,null,4]] 。
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1900-1999/1932.Merge%20BSTs%20to%20Create%20Single%20BST/images/diagram-2.png" />
结果树如上图所示，为一棵有效的二叉搜索树，所以返回该树的根节点。</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1900-1999/1932.Merge%20BSTs%20to%20Create%20Single%20BST/images/d2.png" />
<pre>
<strong>输入：</strong>trees = [[5,3,8],[3,2,6]]
<strong>输出：</strong>[]
<strong>解释：</strong>
选出 i=0 和 j=1 ，然后将 trees[1] 合并到 trees[0] 中。
删除 trees[1] ，trees = [[5,3,8,2,6]] 。
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1900-1999/1932.Merge%20BSTs%20to%20Create%20Single%20BST/images/diagram-3.png" />
结果树如上图所示。仅能执行一次有效的操作，但结果树不是一棵有效的二叉搜索树，所以返回 null 。
</pre>

<p><strong>示例 3：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1900-1999/1932.Merge%20BSTs%20to%20Create%20Single%20BST/images/d3.png" />
<pre>
<strong>输入：</strong>trees = [[5,4],[3]]
<strong>输出：</strong>[]
<strong>解释：</strong>无法执行任何操作。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == trees.length</code></li>
	<li><code>1 &lt;= n &lt;= 5 * 10<sup>4</sup></code></li>
	<li>每棵树中节点数目在范围 <code>[1, 3]</code> 内。</li>
	<li>输入数据的每个节点可能有子节点但不存在子节点的子节点</li>
	<li><code>trees</code> 中不存在两棵树根节点值相同的情况。</li>
	<li>输入中的所有树都是 <strong>有效的二叉树搜索树</strong> 。</li>
	<li><code>1 &lt;= TreeNode.val &lt;= 5 * 10<sup>4</sup></code>.</li>
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

# [1933. 判断字符串是否可分解为值均等的子串 🔒](https://leetcode.cn/problems/check-if-string-is-decomposable-into-value-equal-substrings){#1933}

{{< tabs "1933" >}}

{{% tab "python" %}}
```python
class Solution:
    def isDecomposable(self, s: str) -> bool:
        cnt2 = 0
        for _, g in groupby(s):
            m = len(list(g))
            if m % 3 == 1:
                return False
            cnt2 += m % 3 == 2
            if cnt2 > 1:
                return False
        return cnt2 == 1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean isDecomposable(String s) {
        int i = 0, n = s.length();
        int cnt2 = 0;
        while (i < n) {
            int j = i;
            while (j < n && s.charAt(j) == s.charAt(i)) {
                ++j;
            }
            if ((j - i) % 3 == 1) {
                return false;
            }
            if ((j - i) % 3 == 2 && ++cnt2 > 1) {
                return false;
            }
            i = j;
        }
        return cnt2 == 1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool isDecomposable(string s) {
        int cnt2 = 0;
        for (int i = 0, n = s.size(); i < n;) {
            int j = i;
            while (j < n && s[j] == s[i]) {
                ++j;
            }
            if ((j - i) % 3 == 1) {
                return false;
            }
            cnt2 += (j - i) % 3 == 2;
            if (cnt2 > 1) {
                return false;
            }
            i = j;
        }
        return cnt2 == 1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func isDecomposable(s string) bool {
	i, n := 0, len(s)
	cnt2 := 0
	for i < n {
		j := i
		for j < n && s[j] == s[i] {
			j++
		}
		if (j-i)%3 == 1 {
			return false
		}
		if (j-i)%3 == 2 {
			cnt2++
			if cnt2 > 1 {
				return false
			}
		}
		i = j
	}
	return cnt2 == 1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function isDecomposable(s: string): boolean {
    const n = s.length;
    let cnt2 = 0;
    for (let i = 0; i < n; ) {
        let j = i;
        while (j < n && s[j] === s[i]) {
            ++j;
        }
        if ((j - i) % 3 === 1) {
            return false;
        }
        if ((j - i) % 3 === 2 && ++cnt2 > 1) {
            return false;
        }
        i = j;
    }
    return cnt2 === 1;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>一个字符串的所有字符都是一样的，被称作等值字符串。</p>

<ul>
	<li>举例，<code>"1111"</code> 和 <code>"33" </code>就是等值字符串。</li>
	<li>相比之下，<code>"123"</code>就不是等值字符串。</li>
</ul>

<p>规则：给出一个数字字符串s，将字符串分解成一些等值字符串，如果有且仅有一个等值子字符串长度为2，其他的等值子字符串的长度都是3.</p>

<p>如果能够按照上面的规则分解字符串s，就返回真，否则返回假。</p>

<p>子串就是原字符串中连续的字符序列。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入:</strong> s = "000111000"
<strong>输出:</strong> false
<strong>解释: </strong> s只能被分解长度为3的等值子字符串。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入:</strong> s = "00011111222"
<strong>输出:</strong> true
<strong>解释: </strong>s 能被分解为 ["000","111","11","222"].
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入:</strong> s = "01110002223300"
<strong>输出:</strong> false
<strong>解释: </strong>一个不能被分解的原因是在开头有一个0.
</pre>

<p> </p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;</code><code>= 1000</code></li>
	<li><code>s</code> 仅包含数字。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双指针

遍历字符串 $s$，用双指针 $i$ 和 $j$ 统计每个等值子字符串的长度。若长度模 $3$ 余 $1$，说明该子字符串长度不符合要求，返回 `false`；若长度模 $3$ 余 $2$，说明出现了长度为 $2$ 的子字符串，若此前已经出现过长度为 $2$ 的子字符串，返回 `false`，否则将 $j$ 的值赋给 $i$，继续遍历。

遍历结束后，判断是否出现过长度为 $2$ 的子字符串，若没有，返回 `false`，否则返回 `true`。

时间复杂度 $O(n)$，其中 $n$ 为字符串 $s$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def isDecomposable(self, s: str) -> bool:
        cnt2 = 0
        for _, g in groupby(s):
            m = len(list(g))
            if m % 3 == 1:
                return False
            cnt2 += m % 3 == 2
            if cnt2 > 1:
                return False
        return cnt2 == 1
```

#### Java

```java
class Solution {
    public boolean isDecomposable(String s) {
        int i = 0, n = s.length();
        int cnt2 = 0;
        while (i < n) {
            int j = i;
            while (j < n && s.charAt(j) == s.charAt(i)) {
                ++j;
            }
            if ((j - i) % 3 == 1) {
                return false;
            }
            if ((j - i) % 3 == 2 && ++cnt2 > 1) {
                return false;
            }
            i = j;
        }
        return cnt2 == 1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool isDecomposable(string s) {
        int cnt2 = 0;
        for (int i = 0, n = s.size(); i < n;) {
            int j = i;
            while (j < n && s[j] == s[i]) {
                ++j;
            }
            if ((j - i) % 3 == 1) {
                return false;
            }
            cnt2 += (j - i) % 3 == 2;
            if (cnt2 > 1) {
                return false;
            }
            i = j;
        }
        return cnt2 == 1;
    }
};
```

#### Go

```go
func isDecomposable(s string) bool {
	i, n := 0, len(s)
	cnt2 := 0
	for i < n {
		j := i
		for j < n && s[j] == s[i] {
			j++
		}
		if (j-i)%3 == 1 {
			return false
		}
		if (j-i)%3 == 2 {
			cnt2++
			if cnt2 > 1 {
				return false
			}
		}
		i = j
	}
	return cnt2 == 1
}
```

#### TypeScript

```ts
function isDecomposable(s: string): boolean {
    const n = s.length;
    let cnt2 = 0;
    for (let i = 0; i < n; ) {
        let j = i;
        while (j < n && s[j] === s[i]) {
            ++j;
        }
        if ((j - i) % 3 === 1) {
            return false;
        }
        if ((j - i) % 3 === 2 && ++cnt2 > 1) {
            return false;
        }
        i = j;
    }
    return cnt2 === 1;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1934. 确认率](https://leetcode.cn/problems/confirmation-rate){#1934}

{{< tabs "1934" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT
    user_id,
    ROUND(IFNULL(SUM(action = 'confirmed') / COUNT(1), 0), 2) AS confirmation_rate
FROM
    SignUps
    LEFT JOIN Confirmations USING (user_id)
GROUP BY 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表: <code>Signups</code></p>

<pre>
+----------------+----------+
| Column Name    | Type     |
+----------------+----------+
| user_id        | int      |
| time_stamp     | datetime |
+----------------+----------+
User_id是该表的主键。
每一行都包含ID为user_id的用户的注册时间信息。
</pre>

<p>&nbsp;</p>

<p>表: <code>Confirmations</code></p>

<pre>
+----------------+----------+
| Column Name    | Type     |
+----------------+----------+
| user_id        | int      |
| time_stamp     | datetime |
| action         | ENUM     |
+----------------+----------+
(user_id, time_stamp)是该表的主键。
user_id是一个引用到注册表的外键。
action是类型为('confirmed'， 'timeout')的ENUM
该表的每一行都表示ID为user_id的用户在time_stamp请求了一条确认消息，该确认消息要么被确认('confirmed')，要么被过期('timeout')。
</pre>

<p>&nbsp;</p>

<p>用户的 <strong>确认率</strong>&nbsp;是 <code>'confirmed'</code>&nbsp;消息的数量除以请求的确认消息的总数。没有请求任何确认消息的用户的确认率为&nbsp;<code>0</code> 。确认率四舍五入到 <strong>小数点后两位</strong> 。</p>

<p>编写一个SQL查询来查找每个用户的 确认率 。<br />
<br />
以 任意顺序&nbsp;返回结果表。<br />
<br />
查询结果格式如下所示。<br />
<br />
<strong>示例1:</strong></p>

<pre>
<b>输入：</b>
Signups 表:
+---------+---------------------+
| user_id | time_stamp          |
+---------+---------------------+
| 3       | 2020-03-21 10:16:13 |
| 7       | 2020-01-04 13:57:59 |
| 2       | 2020-07-29 23:09:44 |
| 6       | 2020-12-09 10:39:37 |
+---------+---------------------+
Confirmations 表:
+---------+---------------------+-----------+
| user_id | time_stamp          | action    |
+---------+---------------------+-----------+
| 3       | 2021-01-06 03:30:46 | timeout   |
| 3       | 2021-07-14 14:00:00 | timeout   |
| 7       | 2021-06-12 11:57:29 | confirmed |
| 7       | 2021-06-13 12:58:28 | confirmed |
| 7       | 2021-06-14 13:59:27 | confirmed |
| 2       | 2021-01-22 00:00:00 | confirmed |
| 2       | 2021-02-28 23:59:59 | timeout   |
+---------+---------------------+-----------+
<strong>输出:</strong> 
+---------+-------------------+
| user_id | confirmation_rate |
+---------+-------------------+
| 6       | 0.00              |
| 3       | 0.00              |
| 7       | 1.00              |
| 2       | 0.50              |
+---------+-------------------+
<strong>解释:
</strong>用户 6 没有请求任何确认消息。确认率为 0。
用户 3 进行了 2 次请求，都超时了。确认率为 0。
用户 7 提出了 3 个请求，所有请求都得到了确认。确认率为 1。
用户 2 做了 2 个请求，其中一个被确认，另一个超时。确认率为 1 / 2 = 0.5。</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：左连接 + 分组统计

我们可以使用左连接，将 `Signups` 表和 `Confirmations` 表按照 `user_id` 进行连接，然后使用 `GROUP BY` 对 `user_id` 进行分组统计。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT
    user_id,
    ROUND(IFNULL(SUM(action = 'confirmed') / COUNT(1), 0), 2) AS confirmation_rate
FROM
    SignUps
    LEFT JOIN Confirmations USING (user_id)
GROUP BY 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1935. 可以输入的最大单词数](https://leetcode.cn/problems/maximum-number-of-words-you-can-type){#1935}

{{< tabs "1935" >}}

{{% tab "python" %}}
```python
class Solution:
    def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
        s = set(brokenLetters)
        return sum(all(c not in s for c in w) for w in text.split())
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int canBeTypedWords(String text, String brokenLetters) {
        boolean[] s = new boolean[26];
        for (char c : brokenLetters.toCharArray()) {
            s[c - 'a'] = true;
        }
        int ans = 0;
        for (String w : text.split(" ")) {
            for (char c : w.toCharArray()) {
                if (s[c - 'a']) {
                    --ans;
                    break;
                }
            }
            ++ans;
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
    int canBeTypedWords(string text, string brokenLetters) {
        bool s[26]{};
        for (char& c : brokenLetters) {
            s[c - 'a'] = true;
        }
        int ans = 0;
        for (auto& w : split(text, ' ')) {
            for (char& c : w) {
                if (s[c - 'a']) {
                    --ans;
                    break;
                }
            }
            ++ans;
        }
        return ans;
    }

    vector<string> split(const string& s, char c) {
        vector<string> ans;
        string t;
        for (char d : s) {
            if (d == c) {
                ans.push_back(t);
                t.clear();
            } else {
                t.push_back(d);
            }
        }
        ans.push_back(t);
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func canBeTypedWords(text string, brokenLetters string) (ans int) {
	s := [26]bool{}
	for _, c := range brokenLetters {
		s[c-'a'] = true
	}
	for _, w := range strings.Split(text, " ") {
		for _, c := range w {
			if s[c-'a'] {
				ans--
				break
			}
		}
		ans++
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function canBeTypedWords(text: string, brokenLetters: string): number {
    const s: boolean[] = Array(26).fill(false);
    for (const c of brokenLetters) {
        s[c.charCodeAt(0) - 'a'.charCodeAt(0)] = true;
    }
    let ans = 0;
    for (const w of text.split(' ')) {
        for (const c of w) {
            if (s[c.charCodeAt(0) - 'a'.charCodeAt(0)]) {
                --ans;
                break;
            }
        }
        ++ans;
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn can_be_typed_words(text: String, broken_letters: String) -> i32 {
        let mut s = vec![false; 26];
        for c in broken_letters.chars() {
            s[(c as usize) - ('a' as usize)] = true;
        }
        let mut ans = 0;
        let words = text.split_whitespace();
        for w in words {
            for c in w.chars() {
                if s[(c as usize) - ('a' as usize)] {
                    ans -= 1;
                    break;
                }
            }
            ans += 1;
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

<p>键盘出现了一些故障，有些字母键无法正常工作。而键盘上所有其他键都能够正常工作。</p>

<p>给你一个由若干单词组成的字符串 <code>text</code> ，单词间由单个空格组成（不含前导和尾随空格）；另有一个字符串 <code>brokenLetters</code> ，由所有已损坏的不同字母键组成，返回你可以使用此键盘完全输入的 <code>text</code> 中单词的数目。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>text = "hello world", brokenLetters = "ad"
<strong>输出：</strong>1
<strong>解释：</strong>无法输入 "world" ，因为字母键 'd' 已损坏。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>text = "leet code", brokenLetters = "lt"
<strong>输出：</strong>1
<strong>解释：</strong>无法输入 "leet" ，因为字母键 'l' 和 't' 已损坏。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>text = "leet code", brokenLetters = "e"
<strong>输出：</strong>0
<strong>解释：</strong>无法输入任何单词，因为字母键 'e' 已损坏。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= text.length &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= brokenLetters.length &lt;= 26</code></li>
	<li><code>text</code> 由若干用单个空格分隔的单词组成，且不含任何前导和尾随空格</li>
	<li>每个单词仅由小写英文字母组成</li>
	<li><code>brokenLetters</code> 由 <strong>互不相同</strong> 的小写英文字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数组或哈希表

我们可以用哈希表或者一个长度为 $26$ 的数组 $s$ 来记录所有损坏的字母键。

然后，我们遍历字符串 $text$ 中的每个单词 $w$，如果 $w$ 中的某个字母 $c$ 在 $s$ 中出现过，那么说明这个单词无法输入，答案不需要加一，否则答案需要加一。

遍历结束后，返回答案即可。

时间复杂度 $O(n)$，空间复杂度 $O(|\Sigma|)$，其中 $n$ 是字符串 $text$ 的长度，而 $|\Sigma|$ 是字母表的大小，本题中 $|\Sigma|=26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
        s = set(brokenLetters)
        return sum(all(c not in s for c in w) for w in text.split())
```

#### Java

```java
class Solution {
    public int canBeTypedWords(String text, String brokenLetters) {
        boolean[] s = new boolean[26];
        for (char c : brokenLetters.toCharArray()) {
            s[c - 'a'] = true;
        }
        int ans = 0;
        for (String w : text.split(" ")) {
            for (char c : w.toCharArray()) {
                if (s[c - 'a']) {
                    --ans;
                    break;
                }
            }
            ++ans;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        bool s[26]{};
        for (char& c : brokenLetters) {
            s[c - 'a'] = true;
        }
        int ans = 0;
        for (auto& w : split(text, ' ')) {
            for (char& c : w) {
                if (s[c - 'a']) {
                    --ans;
                    break;
                }
            }
            ++ans;
        }
        return ans;
    }

    vector<string> split(const string& s, char c) {
        vector<string> ans;
        string t;
        for (char d : s) {
            if (d == c) {
                ans.push_back(t);
                t.clear();
            } else {
                t.push_back(d);
            }
        }
        ans.push_back(t);
        return ans;
    }
};
```

#### Go

```go
func canBeTypedWords(text string, brokenLetters string) (ans int) {
	s := [26]bool{}
	for _, c := range brokenLetters {
		s[c-'a'] = true
	}
	for _, w := range strings.Split(text, " ") {
		for _, c := range w {
			if s[c-'a'] {
				ans--
				break
			}
		}
		ans++
	}
	return
}
```

#### TypeScript

```ts
function canBeTypedWords(text: string, brokenLetters: string): number {
    const s: boolean[] = Array(26).fill(false);
    for (const c of brokenLetters) {
        s[c.charCodeAt(0) - 'a'.charCodeAt(0)] = true;
    }
    let ans = 0;
    for (const w of text.split(' ')) {
        for (const c of w) {
            if (s[c.charCodeAt(0) - 'a'.charCodeAt(0)]) {
                --ans;
                break;
            }
        }
        ++ans;
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn can_be_typed_words(text: String, broken_letters: String) -> i32 {
        let mut s = vec![false; 26];
        for c in broken_letters.chars() {
            s[(c as usize) - ('a' as usize)] = true;
        }
        let mut ans = 0;
        let words = text.split_whitespace();
        for w in words {
            for c in w.chars() {
                if s[(c as usize) - ('a' as usize)] {
                    ans -= 1;
                    break;
                }
            }
            ans += 1;
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

# [1936. 新增的最少台阶数](https://leetcode.cn/problems/add-minimum-number-of-rungs){#1936}

{{< tabs "1936" >}}

{{% tab "python" %}}
```python
class Solution:
    def addRungs(self, rungs: List[int], dist: int) -> int:
        rungs = [0] + rungs
        return sum((b - a - 1) // dist for a, b in pairwise(rungs))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int addRungs(int[] rungs, int dist) {
        int ans = 0, prev = 0;
        for (int x : rungs) {
            ans += (x - prev - 1) / dist;
            prev = x;
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
    int addRungs(vector<int>& rungs, int dist) {
        int ans = 0, prev = 0;
        for (int& x : rungs) {
            ans += (x - prev - 1) / dist;
            prev = x;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func addRungs(rungs []int, dist int) (ans int) {
	prev := 0
	for _, x := range rungs {
		ans += (x - prev - 1) / dist
		prev = x
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function addRungs(rungs: number[], dist: number): number {
    let ans = 0;
    let prev = 0;
    for (const x of rungs) {
        ans += ((x - prev - 1) / dist) | 0;
        prev = x;
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn add_rungs(rungs: Vec<i32>, dist: i32) -> i32 {
        let mut ans = 0;
        let mut prev = 0;

        for &x in rungs.iter() {
            ans += (x - prev - 1) / dist;
            prev = x;
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

<p>给你一个 <strong>严格递增</strong> 的整数数组 <code>rungs</code> ，用于表示梯子上每一台阶的 <strong>高度</strong> 。当前你正站在高度为 <code>0</code> 的地板上，并打算爬到最后一个台阶。</p>

<p>另给你一个整数 <code>dist</code> 。每次移动中，你可以到达下一个距离你当前位置（地板或台阶）<strong>不超过</strong> <code>dist</code> 高度的台阶。当然，你也可以在任何正 <strong>整数</strong> 高度处插入尚不存在的新台阶。</p>

<p>返回爬到最后一阶时必须添加到梯子上的 <strong>最少</strong> 台阶数。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>rungs = [1,3,5,10], dist = 2
<strong>输出：</strong>2
<strong>解释：
</strong>现在无法到达最后一阶。
在高度为 7 和 8 的位置增设新的台阶，以爬上梯子。 
梯子在高度为 [1,3,5,<strong><em>7</em></strong>,<strong><em>8</em></strong>,10] 的位置上有台阶。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>rungs = [3,6,8,10], dist = 3
<strong>输出：</strong>0
<strong>解释：</strong>
这个梯子无需增设新台阶也可以爬上去。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>rungs = [3,4,6,7], dist = 2
<strong>输出：</strong>1
<strong>解释：</strong>
现在无法从地板到达梯子的第一阶。 
在高度为 1 的位置增设新的台阶，以爬上梯子。 
梯子在高度为 [<strong><em>1</em></strong>,3,4,6,7] 的位置上有台阶。
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>rungs = [5], dist = 10
<strong>输出：</strong>0
<strong>解释：</strong>这个梯子无需增设新台阶也可以爬上去。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= rungs.length <= 10<sup>5</sup></code></li>
	<li><code>1 <= rungs[i] <= 10<sup>9</sup></code></li>
	<li><code>1 <= dist <= 10<sup>9</sup></code></li>
	<li><code>rungs</code> <strong>严格递增</strong></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 模拟

根据题目描述，我们知道，每一次计划爬上一个新的台阶，都需要满足新的台阶的高度与当前所在位置的高度之差不超过 `dist`，否则，我们需要贪心地在距离当前位置 $dist$ 的地方插入一个新的台阶，爬上一个新的台阶，一共需要插入的台阶数为 $\lfloor \frac{b - a - 1}{dist} \rfloor$，其中 $a$ 和 $b$ 分别为当前位置和新台阶的高度。那么答案即为所有插入的台阶数之和。

时间复杂度 $O(n)$，其中 $n$ 为 `rungs` 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def addRungs(self, rungs: List[int], dist: int) -> int:
        rungs = [0] + rungs
        return sum((b - a - 1) // dist for a, b in pairwise(rungs))
```

#### Java

```java
class Solution {
    public int addRungs(int[] rungs, int dist) {
        int ans = 0, prev = 0;
        for (int x : rungs) {
            ans += (x - prev - 1) / dist;
            prev = x;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int ans = 0, prev = 0;
        for (int& x : rungs) {
            ans += (x - prev - 1) / dist;
            prev = x;
        }
        return ans;
    }
};
```

#### Go

```go
func addRungs(rungs []int, dist int) (ans int) {
	prev := 0
	for _, x := range rungs {
		ans += (x - prev - 1) / dist
		prev = x
	}
	return
}
```

#### TypeScript

```ts
function addRungs(rungs: number[], dist: number): number {
    let ans = 0;
    let prev = 0;
    for (const x of rungs) {
        ans += ((x - prev - 1) / dist) | 0;
        prev = x;
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn add_rungs(rungs: Vec<i32>, dist: i32) -> i32 {
        let mut ans = 0;
        let mut prev = 0;

        for &x in rungs.iter() {
            ans += (x - prev - 1) / dist;
            prev = x;
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

# [1937. 扣分后的最大得分](https://leetcode.cn/problems/maximum-number-of-points-with-cost){#1937}

{{< tabs "1937" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        n = len(points[0])
        f = points[0][:]
        for p in points[1:]:
            g = [0] * n
            lmx = -inf
            for j in range(n):
                lmx = max(lmx, f[j] + j)
                g[j] = max(g[j], p[j] + lmx - j)
            rmx = -inf
            for j in range(n - 1, -1, -1):
                rmx = max(rmx, f[j] - j)
                g[j] = max(g[j], p[j] + rmx + j)
            f = g
        return max(f)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long maxPoints(int[][] points) {
        int n = points[0].length;
        long[] f = new long[n];
        final long inf = 1L << 60;
        for (int[] p : points) {
            long[] g = new long[n];
            long lmx = -inf, rmx = -inf;
            for (int j = 0; j < n; ++j) {
                lmx = Math.max(lmx, f[j] + j);
                g[j] = Math.max(g[j], p[j] + lmx - j);
            }
            for (int j = n - 1; j >= 0; --j) {
                rmx = Math.max(rmx, f[j] - j);
                g[j] = Math.max(g[j], p[j] + rmx + j);
            }
            f = g;
        }
        long ans = 0;
        for (long x : f) {
            ans = Math.max(ans, x);
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
    long long maxPoints(vector<vector<int>>& points) {
        using ll = long long;
        int n = points[0].size();
        vector<ll> f(n);
        const ll inf = 1e18;
        for (auto& p : points) {
            vector<ll> g(n);
            ll lmx = -inf, rmx = -inf;
            for (int j = 0; j < n; ++j) {
                lmx = max(lmx, f[j] + j);
                g[j] = max(g[j], p[j] + lmx - j);
            }
            for (int j = n - 1; ~j; --j) {
                rmx = max(rmx, f[j] - j);
                g[j] = max(g[j], p[j] + rmx + j);
            }
            f = move(g);
        }
        return *max_element(f.begin(), f.end());
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxPoints(points [][]int) int64 {
	n := len(points[0])
	const inf int64 = 1e18
	f := make([]int64, n)
	for _, p := range points {
		g := make([]int64, n)
		lmx, rmx := -inf, -inf
		for j := range p {
			lmx = max(lmx, f[j]+int64(j))
			g[j] = max(g[j], int64(p[j])+lmx-int64(j))
		}
		for j := n - 1; j >= 0; j-- {
			rmx = max(rmx, f[j]-int64(j))
			g[j] = max(g[j], int64(p[j])+rmx+int64(j))
		}
		f = g
	}
	return slices.Max(f)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxPoints(points: number[][]): number {
    const n = points[0].length;
    const f: number[] = new Array(n).fill(0);
    for (const p of points) {
        const g: number[] = new Array(n).fill(0);
        let lmx = -Infinity;
        let rmx = -Infinity;
        for (let j = 0; j < n; ++j) {
            lmx = Math.max(lmx, f[j] + j);
            g[j] = Math.max(g[j], p[j] + lmx - j);
        }
        for (let j = n - 1; ~j; --j) {
            rmx = Math.max(rmx, f[j] - j);
            g[j] = Math.max(g[j], p[j] + rmx + j);
        }
        f.splice(0, n, ...g);
    }
    return Math.max(...f);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个 <code>m x n</code> 的整数矩阵 <code>points</code> （下标从 <strong>0</strong> 开始）。一开始你的得分为 <code>0</code> ，你想最大化从矩阵中得到的分数。</p>

<p>你的得分方式为：<strong>每一行</strong> 中选取一个格子，选中坐标为 <code>(r, c)</code> 的格子会给你的总得分 <strong>增加</strong> <code>points[r][c]</code> 。</p>

<p>然而，相邻行之间被选中的格子如果隔得太远，你会失去一些得分。对于相邻行 <code>r</code> 和 <code>r + 1</code> （其中 <code>0 <= r < m - 1</code>），选中坐标为 <code>(r, c<sub>1</sub>)</code> 和 <code>(r + 1, c<sub>2</sub>)</code> 的格子，你的总得分 <b>减少</b> <code>abs(c<sub>1</sub> - c<sub>2</sub>)</code> 。</p>

<p>请你返回你能得到的 <strong>最大</strong> 得分。</p>

<p><code>abs(x)</code> 定义为：</p>

<ul>
	<li>如果 <code>x >= 0</code> ，那么值为 <code>x</code> 。</li>
	<li>如果 <code>x < 0</code> ，那么值为 <code>-x</code> 。</li>
</ul>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1900-1999/1937.Maximum%20Number%20of%20Points%20with%20Cost/images/screenshot-2021-07-12-at-13-40-26-diagram-drawio-diagrams-net.png" style="width: 300px; height: 300px;" />
<pre>
<b>输入：</b>points = [[1,2,3],[1,5,1],[3,1,1]]
<b>输出：</b>9
<strong>解释：</strong>
蓝色格子是最优方案选中的格子，坐标分别为 (0, 2)，(1, 1) 和 (2, 0) 。
你的总得分增加 3 + 5 + 3 = 11 。
但是你的总得分需要扣除 abs(2 - 1) + abs(1 - 0) = 2 。
你的最终得分为 11 - 2 = 9 。
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1900-1999/1937.Maximum%20Number%20of%20Points%20with%20Cost/images/screenshot-2021-07-12-at-13-42-14-diagram-drawio-diagrams-net.png" style="width: 200px; height: 299px;" />
<pre>
<b>输入：</b>points = [[1,5],[2,3],[4,2]]
<b>输出：</b>11
<strong>解释：</strong>
蓝色格子是最优方案选中的格子，坐标分别为 (0, 1)，(1, 1) 和 (2, 0) 。
你的总得分增加 5 + 3 + 4 = 12 。
但是你的总得分需要扣除 abs(1 - 1) + abs(1 - 0) = 1 。
你的最终得分为 12 - 1 = 11 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == points.length</code></li>
	<li><code>n == points[r].length</code></li>
	<li><code>1 <= m, n <= 10<sup>5</sup></code></li>
	<li><code>1 <= m * n <= 10<sup>5</sup></code></li>
	<li><code>0 <= points[r][c] <= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i][j]$ 表示选取前 $i-1$ 行，并且第 $i-1$ 行选择第 $j$ 列的格子时的最大得分。初始时 $f[0][j] = points[0][j]$。

对于 $i > 0$ 的情况，对于 $f[i][j]$，我们考虑是从上一行的哪一列转移过来的，记上一行选择的列为 $k$，那么有：

$$
f[i][j]=
\begin{cases}
\max(f[i - 1][k] + k - j + points[i][j]), & 0 \le k < j \\
\max(f[i - 1][k] - k + j + points[i][j]), & j < k < n
\end{cases}
$$

其中 $n$ 表示列数。答案为 $\max\limits_{0 \le j < n} f[m - 1][j]$。

我们注意到 $f[i]$ 的值只跟 $f[i-1]$ 的值有关，因此我们可以使用滚动数组优化空间复杂度。

时间复杂度 $O(m \times n)$，空间复杂度 $O(n)$。其中 $m$ 和 $n$ 分别是矩阵的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        n = len(points[0])
        f = points[0][:]
        for p in points[1:]:
            g = [0] * n
            lmx = -inf
            for j in range(n):
                lmx = max(lmx, f[j] + j)
                g[j] = max(g[j], p[j] + lmx - j)
            rmx = -inf
            for j in range(n - 1, -1, -1):
                rmx = max(rmx, f[j] - j)
                g[j] = max(g[j], p[j] + rmx + j)
            f = g
        return max(f)
```

#### Java

```java
class Solution {
    public long maxPoints(int[][] points) {
        int n = points[0].length;
        long[] f = new long[n];
        final long inf = 1L << 60;
        for (int[] p : points) {
            long[] g = new long[n];
            long lmx = -inf, rmx = -inf;
            for (int j = 0; j < n; ++j) {
                lmx = Math.max(lmx, f[j] + j);
                g[j] = Math.max(g[j], p[j] + lmx - j);
            }
            for (int j = n - 1; j >= 0; --j) {
                rmx = Math.max(rmx, f[j] - j);
                g[j] = Math.max(g[j], p[j] + rmx + j);
            }
            f = g;
        }
        long ans = 0;
        for (long x : f) {
            ans = Math.max(ans, x);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        using ll = long long;
        int n = points[0].size();
        vector<ll> f(n);
        const ll inf = 1e18;
        for (auto& p : points) {
            vector<ll> g(n);
            ll lmx = -inf, rmx = -inf;
            for (int j = 0; j < n; ++j) {
                lmx = max(lmx, f[j] + j);
                g[j] = max(g[j], p[j] + lmx - j);
            }
            for (int j = n - 1; ~j; --j) {
                rmx = max(rmx, f[j] - j);
                g[j] = max(g[j], p[j] + rmx + j);
            }
            f = move(g);
        }
        return *max_element(f.begin(), f.end());
    }
};
```

#### Go

```go
func maxPoints(points [][]int) int64 {
	n := len(points[0])
	const inf int64 = 1e18
	f := make([]int64, n)
	for _, p := range points {
		g := make([]int64, n)
		lmx, rmx := -inf, -inf
		for j := range p {
			lmx = max(lmx, f[j]+int64(j))
			g[j] = max(g[j], int64(p[j])+lmx-int64(j))
		}
		for j := n - 1; j >= 0; j-- {
			rmx = max(rmx, f[j]-int64(j))
			g[j] = max(g[j], int64(p[j])+rmx+int64(j))
		}
		f = g
	}
	return slices.Max(f)
}
```

#### TypeScript

```ts
function maxPoints(points: number[][]): number {
    const n = points[0].length;
    const f: number[] = new Array(n).fill(0);
    for (const p of points) {
        const g: number[] = new Array(n).fill(0);
        let lmx = -Infinity;
        let rmx = -Infinity;
        for (let j = 0; j < n; ++j) {
            lmx = Math.max(lmx, f[j] + j);
            g[j] = Math.max(g[j], p[j] + lmx - j);
        }
        for (let j = n - 1; ~j; --j) {
            rmx = Math.max(rmx, f[j] - j);
            g[j] = Math.max(g[j], p[j] + rmx + j);
        }
        f.splice(0, n, ...g);
    }
    return Math.max(...f);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1938. 查询最大基因差](https://leetcode.cn/problems/maximum-genetic-difference-query){#1938}

{{< tabs "1938" >}}

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

<p>给你一棵 <code>n</code> 个节点的有根树，节点编号从 <code>0</code> 到 <code>n - 1</code> 。每个节点的编号表示这个节点的 <strong>独一无二的基因值</strong> （也就是说节点 <code>x</code> 的基因值为 <code>x</code>）。两个基因值的 <strong>基因差</strong> 是两者的 <strong>异或和</strong> 。给你整数数组 <code>parents</code> ，其中 <code>parents[i]</code> 是节点 <code>i</code> 的父节点。如果节点 <code>x</code> 是树的 <strong>根</strong> ，那么 <code>parents[x] == -1</code> 。</p>

<p>给你查询数组 <code>queries</code> ，其中 <code>queries[i] = [node<sub>i</sub>, val<sub>i</sub>]</code> 。对于查询 <code>i</code> ，请你找到 <code>val<sub>i</sub></code> 和 <code>p<sub>i</sub></code> 的 <strong>最大基因差</strong> ，其中 <code>p<sub>i</sub></code> 是节点 <code>node<sub>i</sub></code> 到根之间的任意节点（包含 <code>node<sub>i</sub></code> 和根节点）。更正式的，你想要最大化 <code>val<sub>i</sub> XOR p<sub>i</sub></code><sub> </sub>。</p>

<p>请你返回数组<em> </em><code>ans</code> ，其中 <code>ans[i]</code> 是第 <code>i</code> 个查询的答案。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1900-1999/1938.Maximum%20Genetic%20Difference%20Query/images/c1.png" style="width: 118px; height: 163px;">
<pre><b>输入：</b>parents = [-1,0,1,1], queries = [[0,2],[3,2],[2,5]]
<b>输出：</b>[2,3,7]
<strong>解释：</strong>查询数组处理如下：
- [0,2]：最大基因差的对应节点为 0 ，基因差为 2 XOR 0 = 2 。
- [3,2]：最大基因差的对应节点为 1 ，基因差为 2 XOR 1 = 3 。
- [2,5]：最大基因差的对应节点为 2 ，基因差为 5 XOR 2 = 7 。
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1900-1999/1938.Maximum%20Genetic%20Difference%20Query/images/c2.png" style="width: 256px; height: 221px;">
<pre><b>输入：</b>parents = [3,7,-1,2,0,7,0,2], queries = [[4,6],[1,15],[0,5]]
<b>输出：</b>[6,14,7]
<strong>解释：</strong>查询数组处理如下：
- [4,6]：最大基因差的对应节点为 0 ，基因差为 6 XOR 0 = 6 。
- [1,15]：最大基因差的对应节点为 1 ，基因差为 15 XOR 1 = 14 。
- [0,5]：最大基因差的对应节点为 2 ，基因差为 5 XOR 2 = 7 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= parents.length &lt;= 10<sup>5</sup></code></li>
	<li>对于每个 <strong>不是</strong> 根节点的 <code>i</code> ，有 <code>0 &lt;= parents[i] &lt;= parents.length - 1</code> 。</li>
	<li><code>parents[root] == -1</code></li>
	<li><code>1 &lt;= queries.length &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>0 &lt;= node<sub>i</sub> &lt;= parents.length - 1</code></li>
	<li><code>0 &lt;= val<sub>i</sub> &lt;= 2 * 10<sup>5</sup></code></li>
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

# [1939. 主动请求确认消息的用户 🔒](https://leetcode.cn/problems/users-that-actively-request-confirmation-messages){#1939}

{{< tabs "1939" >}}

{{% tab "sql" %}}
```sql
SELECT DISTINCT user_id
FROM
    Confirmations AS c1
    JOIN Confirmations AS c2 USING (user_id)
WHERE
    c1.time_stamp < c2.time_stamp
    AND TIMESTAMPDIFF(SECOND, c1.time_stamp, c2.time_stamp) <= 24 * 60 * 60;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>Table: <code>Signups</code></p>

<pre>+----------------+----------+
| Column Name    | Type     |
+----------------+----------+
| user_id        | int      |
| time_stamp     | datetime |
+----------------+----------+
user_id is the primary key for this table.
每行包含有关 ID 为 user_id 的用户的注册时间的信息。</pre>

<p>&nbsp;</p>

<p>Table: <code>Confirmations</code></p>

<pre>+----------------+----------+
| Column Name    | Type     |
+----------------+----------+
| user_id        | int      |
| time_stamp     | datetime |
| action         | ENUM     |
+----------------+----------+
(user_id, time_stamp) is the primary key for this table.
user_id is a foreign key with a reference to the Signups table.
action is an ENUM of the type ('confirmed', 'timeout')
此表的每一行都表示 ID 为 user_id 的用户在 time_stamp 请求了确认消息，并且该确认消息已被确认（'confirmed'）或已过期（'timeout'）。</pre>

<p>编写 SQL 查询以查找在 24 小时窗口内两次请求确认消息的用户的 ID。 两个正好相隔 24 小时的消息被认为是在窗口内。 该操作不会影响答案，只会影响请求时间。</p>

<p>以任意顺序返回结果表。</p>

<p>查询结果格式如下例：</p>

<pre>Signups table:
+---------+---------------------+
| user_id | time_stamp          |
+---------+---------------------+
| 3       | 2020-03-21 10:16:13 |
| 7       | 2020-01-04 13:57:59 |
| 2       | 2020-07-29 23:09:44 |
| 6       | 2020-12-09 10:39:37 |
+---------+---------------------+

Confirmations table:
+---------+---------------------+-----------+
| user_id | time_stamp          | action    |
+---------+---------------------+-----------+
| 3       | 2021-01-06 03:30:46 | timeout   |
| 3       | 2021-01-06 03:37:45 | timeout   |
| 7       | 2021-06-12 11:57:29 | confirmed |
| 7       | 2021-06-13 11:57:30 | confirmed |
| 2       | 2021-01-22 00:00:00 | confirmed |
| 2       | 2021-01-23 00:00:00 | timeout   |
| 6       | 2021-10-23 14:14:14 | confirmed |
| 6       | 2021-10-24 14:14:13 | timeout   |
+---------+---------------------+-----------+

Result table
+---------+
| user_id |
+---------+
| 2       |
| 3       |
| 6       |
+---------+
</pre>

<p>&nbsp;</p>

<p>用户 2 在彼此恰好 24 小时内请求了两条消息，因此我们将它们包括在内。 用户 3 在 6 分 59 秒内请求了两条消息，因此我们将它们包括在内。 用户 6 在 23 小时 59 分 59 秒内请求了两条消息，因此我们将它们包括在内。 用户 7 在 24 小时 1 秒内请求了两条消息，因此我们将它们从答案中排除。</p>

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
SELECT DISTINCT user_id
FROM
    Confirmations AS c1
    JOIN Confirmations AS c2 USING (user_id)
WHERE
    c1.time_stamp < c2.time_stamp
    AND TIMESTAMPDIFF(SECOND, c1.time_stamp, c2.time_stamp) <= 24 * 60 * 60;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
