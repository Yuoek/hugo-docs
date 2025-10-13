---
title: "3290_最高乘法得分"
date: 2025-10-08T18:40:15+08:00
weight: 10
tags: [二分查找, 动态规划, 双向链表, 哈希函数, 哈希表, 堆（优先队列）, 字典树, 字符串, 字符串匹配, 数学, 数据库, 数组, 滑动窗口, 滚动哈希, 线段树, 贪心, 链表]
---

{{< markmap >}}
### [3290_最高乘法得分](#3290)
#### [数组](#3290)
#### [动态规划](#3290)
### [3291_形成目标字符串需要的最少字符串数 I](#3291)
#### [字典树](#3291)
#### [线段树](#3291)
#### [数组](#3291)
#### [字符串](#3291)
#### [二分查找](#3291)
#### [动态规划](#3291)
#### [字符串匹配](#3291)
#### [哈希函数](#3291)
#### [滚动哈希](#3291)
### [3292_形成目标字符串需要的最少字符串数 II](#3292)
#### [线段树](#3292)
#### [数组](#3292)
#### [字符串](#3292)
#### [二分查找](#3292)
#### [动态规划](#3292)
#### [字符串匹配](#3292)
#### [哈希函数](#3292)
#### [滚动哈希](#3292)
### [3293_计算产品最终价格 🔒](#3293)
#### [数据库](#3293)
### [3294_将双链表转换为数组 II 🔒](#3294)
#### [数组](#3294)
#### [链表](#3294)
#### [双向链表](#3294)
### [3295_举报垃圾信息](#3295)
#### [数组](#3295)
#### [哈希表](#3295)
#### [字符串](#3295)
### [3296_移山所需的最少秒数](#3296)
#### [贪心](#3296)
#### [数组](#3296)
#### [数学](#3296)
#### [二分查找](#3296)
#### [堆（优先队列）](#3296)
### [3297_统计重新排列后包含另一个字符串的子字符串数目 I](#3297)
#### [哈希表](#3297)
#### [字符串](#3297)
#### [滑动窗口](#3297)
### [3298_统计重新排列后包含另一个字符串的子字符串数目 II](#3298)
#### [哈希表](#3298)
#### [字符串](#3298)
#### [滑动窗口](#3298)
### [3299_连续子序列的和 🔒](#3299)
#### [数组](#3299)
#### [哈希表](#3299)
#### [动态规划](#3299)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 3290_最高乘法得分
___
#### 数组
___
#### 动态规划
---
### 3291_形成目标字符串需要的最少字符串数 I
___
#### 字典树
___
#### 线段树
___
#### 数组
___
#### 字符串
___
#### 二分查找
___
#### 动态规划
___
#### 字符串匹配
___
#### 哈希函数
___
#### 滚动哈希
---
### 3292_形成目标字符串需要的最少字符串数 II
___
#### 线段树
___
#### 数组
___
#### 字符串
___
#### 二分查找
___
#### 动态规划
___
#### 字符串匹配
___
#### 哈希函数
___
#### 滚动哈希
---
### 3293_计算产品最终价格 🔒
___
#### 数据库
---
### 3294_将双链表转换为数组 II 🔒
___
#### 数组
___
#### 链表
___
#### 双向链表
---
### 3295_举报垃圾信息
___
#### 数组
___
#### 哈希表
___
#### 字符串
---
### 3296_移山所需的最少秒数
___
#### 贪心
___
#### 数组
___
#### 数学
___
#### 二分查找
___
#### 堆（优先队列）
---
### 3297_统计重新排列后包含另一个字符串的子字符串数目 I
___
#### 哈希表
___
#### 字符串
___
#### 滑动窗口
---
### 3298_统计重新排列后包含另一个字符串的子字符串数目 II
___
#### 哈希表
___
#### 字符串
___
#### 滑动窗口
---
### 3299_连续子序列的和 🔒
___
#### 数组
___
#### 哈希表
___
#### 动态规划
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 动态规划 | 双向链表 |
| 哈希函数 | 哈希表 | 堆（优先队列） |
| 字典树 | 字符串 | 字符串匹配 |
| 数学 | 数据库 | 数组 |
| 滑动窗口 | 滚动哈希 | 线段树 |
| 贪心 | 链表 |  |

# [3290. 最高乘法得分](https://leetcode.cn/problems/maximum-multiplication-score){#3290}

{{< tabs "3290" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxScore(self, a: List[int], b: List[int]) -> int:
        @cache
        def dfs(i: int, j: int) -> int:
            if j >= len(b):
                return 0 if i >= len(a) else -inf
            if i >= len(a):
                return 0
            return max(dfs(i, j + 1), a[i] * b[j] + dfs(i + 1, j + 1))

        return dfs(0, 0)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private Long[][] f;
    private int[] a;
    private int[] b;

    public long maxScore(int[] a, int[] b) {
        f = new Long[a.length][b.length];
        this.a = a;
        this.b = b;
        return dfs(0, 0);
    }

    private long dfs(int i, int j) {
        if (j >= b.length) {
            return i >= a.length ? 0 : Long.MIN_VALUE / 2;
        }
        if (i >= a.length) {
            return 0;
        }
        if (f[i][j] != null) {
            return f[i][j];
        }
        return f[i][j] = Math.max(dfs(i, j + 1), 1L * a[i] * b[j] + dfs(i + 1, j + 1));
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b) {
        int m = a.size(), n = b.size();
        long long f[m][n];
        memset(f, -1, sizeof(f));
        auto dfs = [&](this auto&& dfs, int i, int j) -> long long {
            if (j >= n) {
                return i >= m ? 0 : LLONG_MIN / 2;
            }
            if (i >= m) {
                return 0;
            }
            if (f[i][j] != -1) {
                return f[i][j];
            }
            return f[i][j] = max(dfs(i, j + 1), 1LL * a[i] * b[j] + dfs(i + 1, j + 1));
        };
        return dfs(0, 0);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxScore(a []int, b []int) int64 {
	m, n := len(a), len(b)
	f := make([][]int64, m)
	for i := range f {
		f[i] = make([]int64, n)
		for j := range f[i] {
			f[i][j] = -1
		}
	}
	var dfs func(i, j int) int64
	dfs = func(i, j int) int64 {
		if j >= n {
			if i >= m {
				return 0
			}
			return math.MinInt64 / 2
		}
		if i >= m {
			return 0
		}
		if f[i][j] != -1 {
			return f[i][j]
		}
		f[i][j] = max(dfs(i, j+1), int64(a[i])*int64(b[j])+dfs(i+1, j+1))
		return f[i][j]
	}
	return dfs(0, 0)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxScore(a: number[], b: number[]): number {
    const [m, n] = [a.length, b.length];
    const f: number[][] = Array.from({ length: m }, () => Array(n).fill(-1));
    const dfs = (i: number, j: number): number => {
        if (j >= n) {
            return i >= m ? 0 : -Infinity;
        }
        if (i >= m) {
            return 0;
        }
        if (f[i][j] !== -1) {
            return f[i][j];
        }
        return (f[i][j] = Math.max(dfs(i, j + 1), a[i] * b[j] + dfs(i + 1, j + 1)));
    };
    return dfs(0, 0);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个大小为 4 的整数数组 <code>a</code> 和一个大小 <strong>至少</strong>为 4 的整数数组 <code>b</code>。</p>

<p>你需要从数组 <code>b</code> 中选择四个下标 <code>i<sub>0</sub></code>, <code>i<sub>1</sub></code>, <code>i<sub>2</sub></code>, 和 <code>i<sub>3</sub></code>，并满足 <code>i<sub>0</sub> &lt; i<sub>1</sub> &lt; i<sub>2</sub> &lt; i<sub>3</sub></code>。你的得分将是 <code>a[0] * b[i<sub>0</sub>] + a[1] * b[i<sub>1</sub>] + a[2] * b[i<sub>2</sub>] + a[3] * b[i<sub>3</sub>]</code> 的值。</p>

<p>返回你能够获得的 <strong>最大 </strong>得分。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">a = [3,2,5,6], b = [2,-6,4,-5,-3,2,-7]</span></p>

<p><strong>输出：</strong> <span class="example-io">26</span></p>

<p><strong>解释：</strong><br />
选择下标 0, 1, 2 和 5。得分为 <code>3 * 2 + 2 * (-6) + 5 * 4 + 6 * 2 = 26</code>。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">a = [-1,4,5,-2], b = [-5,-1,-3,-2,-4]</span></p>

<p><strong>输出：</strong> <span class="example-io">-1</span></p>

<p><strong>解释：</strong><br />
选择下标 0, 1, 3 和 4。得分为 <code>(-1) * (-5) + 4 * (-1) + 5 * (-2) + (-2) * (-4) = -1</code>。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>a.length == 4</code></li>
	<li><code>4 &lt;= b.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>5</sup> &lt;= a[i], b[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

我们设计一个函数 $\textit{dfs}(i, j)$，表示从数组 $a$ 的第 $i$ 个元素开始，从数组 $b$ 的第 $j$ 个元素开始，能够获得的最大得分。那么答案就是 $\textit{dfs}(0, 0)$。

函数 $\textit{dfs}(i, j)$ 的计算方式如下：

-   如果 $j \geq \text{len}(b)$，表示数组 $b$ 已经遍历完了，此时如果数组 $a$ 也遍历完了，返回 $0$，否则返回负无穷；
-   如果 $i \geq \text{len}(a)$，表示数组 $a$ 已经遍历完了，返回 $0$；
-   否则，我们可以不选择数组 $b$ 的第 $j$ 个元素，直接跳到下一个元素，即 $\textit{dfs}(i, j + 1)$；也可以选择数组 $b$ 的第 $j$ 个元素，此时得分为 $a[i] \times b[j]$，再加上 $\textit{dfs}(i + 1, j + 1)$。我们取这两者的最大值作为 $\textit{dfs}(i, j)$ 的返回值。

我们可以使用记忆化搜索的方式，避免重复计算。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别为数组 $a$ 和 $b$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxScore(self, a: List[int], b: List[int]) -> int:
        @cache
        def dfs(i: int, j: int) -> int:
            if j >= len(b):
                return 0 if i >= len(a) else -inf
            if i >= len(a):
                return 0
            return max(dfs(i, j + 1), a[i] * b[j] + dfs(i + 1, j + 1))

        return dfs(0, 0)
```

#### Java

```java
class Solution {
    private Long[][] f;
    private int[] a;
    private int[] b;

    public long maxScore(int[] a, int[] b) {
        f = new Long[a.length][b.length];
        this.a = a;
        this.b = b;
        return dfs(0, 0);
    }

    private long dfs(int i, int j) {
        if (j >= b.length) {
            return i >= a.length ? 0 : Long.MIN_VALUE / 2;
        }
        if (i >= a.length) {
            return 0;
        }
        if (f[i][j] != null) {
            return f[i][j];
        }
        return f[i][j] = Math.max(dfs(i, j + 1), 1L * a[i] * b[j] + dfs(i + 1, j + 1));
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b) {
        int m = a.size(), n = b.size();
        long long f[m][n];
        memset(f, -1, sizeof(f));
        auto dfs = [&](this auto&& dfs, int i, int j) -> long long {
            if (j >= n) {
                return i >= m ? 0 : LLONG_MIN / 2;
            }
            if (i >= m) {
                return 0;
            }
            if (f[i][j] != -1) {
                return f[i][j];
            }
            return f[i][j] = max(dfs(i, j + 1), 1LL * a[i] * b[j] + dfs(i + 1, j + 1));
        };
        return dfs(0, 0);
    }
};
```

#### Go

```go
func maxScore(a []int, b []int) int64 {
	m, n := len(a), len(b)
	f := make([][]int64, m)
	for i := range f {
		f[i] = make([]int64, n)
		for j := range f[i] {
			f[i][j] = -1
		}
	}
	var dfs func(i, j int) int64
	dfs = func(i, j int) int64 {
		if j >= n {
			if i >= m {
				return 0
			}
			return math.MinInt64 / 2
		}
		if i >= m {
			return 0
		}
		if f[i][j] != -1 {
			return f[i][j]
		}
		f[i][j] = max(dfs(i, j+1), int64(a[i])*int64(b[j])+dfs(i+1, j+1))
		return f[i][j]
	}
	return dfs(0, 0)
}
```

#### TypeScript

```ts
function maxScore(a: number[], b: number[]): number {
    const [m, n] = [a.length, b.length];
    const f: number[][] = Array.from({ length: m }, () => Array(n).fill(-1));
    const dfs = (i: number, j: number): number => {
        if (j >= n) {
            return i >= m ? 0 : -Infinity;
        }
        if (i >= m) {
            return 0;
        }
        if (f[i][j] !== -1) {
            return f[i][j];
        }
        return (f[i][j] = Math.max(dfs(i, j + 1), a[i] * b[j] + dfs(i + 1, j + 1)));
    };
    return dfs(0, 0);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3291. 形成目标字符串需要的最少字符串数 I](https://leetcode.cn/problems/minimum-number-of-valid-strings-to-form-target-i){#3291}

{{< tabs "3291" >}}

{{% tab "python" %}}
```python
def min(a: int, b: int) -> int:
    return a if a < b else b


class Trie:
    def __init__(self):
        self.children: List[Optional[Trie]] = [None] * 26

    def insert(self, w: str):
        node = self
        for i in map(lambda c: ord(c) - 97, w):
            if node.children[i] is None:
                node.children[i] = Trie()
            node = node.children[i]


class Solution:
    def minValidStrings(self, words: List[str], target: str) -> int:
        @cache
        def dfs(i: int) -> int:
            if i >= n:
                return 0
            node = trie
            ans = inf
            for j in range(i, n):
                k = ord(target[j]) - 97
                if node.children[k] is None:
                    break
                node = node.children[k]
                ans = min(ans, 1 + dfs(j + 1))
            return ans

        trie = Trie()
        for w in words:
            trie.insert(w)
        n = len(target)
        ans = dfs(0)
        return ans if ans < inf else -1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Trie {
    Trie[] children = new Trie[26];

    void insert(String w) {
        Trie node = this;
        for (int i = 0; i < w.length(); ++i) {
            int j = w.charAt(i) - 'a';
            if (node.children[j] == null) {
                node.children[j] = new Trie();
            }
            node = node.children[j];
        }
    }
}

class Solution {
    private Integer[] f;
    private char[] s;
    private Trie trie;
    private final int inf = 1 << 30;

    public int minValidStrings(String[] words, String target) {
        trie = new Trie();
        for (String w : words) {
            trie.insert(w);
        }
        s = target.toCharArray();
        f = new Integer[s.length];
        int ans = dfs(0);
        return ans < inf ? ans : -1;
    }

    private int dfs(int i) {
        if (i >= s.length) {
            return 0;
        }
        if (f[i] != null) {
            return f[i];
        }
        Trie node = trie;
        f[i] = inf;
        for (int j = i; j < s.length; ++j) {
            int k = s[j] - 'a';
            if (node.children[k] == null) {
                break;
            }
            f[i] = Math.min(f[i], 1 + dfs(j + 1));
            node = node.children[k];
        }
        return f[i];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Trie {
public:
    Trie* children[26]{};

    void insert(string& word) {
        Trie* node = this;
        for (char& c : word) {
            int i = c - 'a';
            if (!node->children[i]) {
                node->children[i] = new Trie();
            }
            node = node->children[i];
        }
    }
};

class Solution {
public:
    int minValidStrings(vector<string>& words, string target) {
        int n = target.size();
        Trie* trie = new Trie();
        for (auto& w : words) {
            trie->insert(w);
        }
        const int inf = 1 << 30;
        int f[n];
        memset(f, -1, sizeof(f));
        auto dfs = [&](this auto&& dfs, int i) -> int {
            if (i >= n) {
                return 0;
            }
            if (f[i] != -1) {
                return f[i];
            }
            f[i] = inf;
            Trie* node = trie;
            for (int j = i; j < n; ++j) {
                int k = target[j] - 'a';
                if (!node->children[k]) {
                    break;
                }
                node = node->children[k];
                f[i] = min(f[i], 1 + dfs(j + 1));
            }
            return f[i];
        };
        int ans = dfs(0);
        return ans < inf ? ans : -1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
type Trie struct {
	children [26]*Trie
}

func (t *Trie) insert(word string) {
	node := t
	for _, c := range word {
		idx := c - 'a'
		if node.children[idx] == nil {
			node.children[idx] = &Trie{}
		}
		node = node.children[idx]
	}
}

func minValidStrings(words []string, target string) int {
	n := len(target)
	trie := &Trie{}
	for _, w := range words {
		trie.insert(w)
	}
	const inf int = 1 << 30
	f := make([]int, n)
	var dfs func(int) int
	dfs = func(i int) int {
		if i >= n {
			return 0
		}
		if f[i] != 0 {
			return f[i]
		}
		node := trie
		f[i] = inf
		for j := i; j < n; j++ {
			k := int(target[j] - 'a')
			if node.children[k] == nil {
				break
			}
			f[i] = min(f[i], 1+dfs(j+1))
			node = node.children[k]
		}
		return f[i]
	}
	if ans := dfs(0); ans < inf {
		return ans
	}
	return -1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class Trie {
    children: (Trie | null)[] = Array(26).fill(null);

    insert(word: string): void {
        let node: Trie = this;
        for (const c of word) {
            const i = c.charCodeAt(0) - 'a'.charCodeAt(0);
            if (!node.children[i]) {
                node.children[i] = new Trie();
            }
            node = node.children[i];
        }
    }
}

function minValidStrings(words: string[], target: string): number {
    const n = target.length;
    const trie = new Trie();
    for (const w of words) {
        trie.insert(w);
    }
    const inf = 1 << 30;
    const f = Array(n).fill(0);

    const dfs = (i: number): number => {
        if (i >= n) {
            return 0;
        }
        if (f[i]) {
            return f[i];
        }
        f[i] = inf;
        let node: Trie | null = trie;
        for (let j = i; j < n; ++j) {
            const k = target[j].charCodeAt(0) - 'a'.charCodeAt(0);
            if (!node?.children[k]) {
                break;
            }
            node = node.children[k];
            f[i] = Math.min(f[i], 1 + dfs(j + 1));
        }
        return f[i];
    };

    const ans = dfs(0);
    return ans < inf ? ans : -1;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串数组 <code>words</code> 和一个字符串 <code>target</code>。</p>

<p>如果字符串 <code>x</code> 是 <code>words</code> 中<strong> 任意 </strong>字符串的 <span data-keyword="string-prefix">前缀</span>，则认为 <code>x</code> 是一个 <strong>有效</strong> 字符串。</p>

<p>现计划通过 <strong>连接 </strong>有效字符串形成 <code>target</code> ，请你计算并返回需要连接的 <strong>最少 </strong>字符串数量。如果无法通过这种方式形成 <code>target</code>，则返回 <code>-1</code>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">words = ["abc","aaaaa","bcdef"], target = "aabcdabc"</span></p>

<p><strong>输出：</strong> <span class="example-io">3</span></p>

<p><strong>解释：</strong></p>

<p>target 字符串可以通过连接以下有效字符串形成：</p>

<ul>
	<li><code>words[1]</code> 的长度为 2 的前缀，即 <code>"aa"</code>。</li>
	<li><code>words[2]</code> 的长度为 3 的前缀，即 <code>"bcd"</code>。</li>
	<li><code>words[0]</code> 的长度为 3 的前缀，即 <code>"abc"</code>。</li>
</ul>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">words = ["abababab","ab"], target = "ababaababa"</span></p>

<p><strong>输出：</strong> <span class="example-io">2</span></p>

<p><strong>解释：</strong></p>

<p>target 字符串可以通过连接以下有效字符串形成：</p>

<ul>
	<li><code>words[0]</code> 的长度为 5 的前缀，即 <code>"ababa"</code>。</li>
	<li><code>words[0]</code> 的长度为 5 的前缀，即 <code>"ababa"</code>。</li>
</ul>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">words = ["abcdef"], target = "xyz"</span></p>

<p><strong>输出：</strong> <span class="example-io">-1</span></p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 100</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 5 * 10<sup>3</sup></code></li>
	<li>输入确保 <code>sum(words[i].length) &lt;= 10<sup>5</sup></code>。</li>
	<li><code>words[i]</code> 只包含小写英文字母。</li>
	<li><code>1 &lt;= target.length &lt;= 5 * 10<sup>3</sup></code></li>
	<li><code>target</code> 只包含小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：字典树 + 记忆化搜索

我们可以使用字典树存储所有有效字符串，然后使用记忆化搜索计算答案。

我们设计一个函数 $\textit{dfs}(i)$，表示从字符串 $\textit{target}$ 的第 $i$ 个字符开始，需要连接的最少字符串数量。那么答案就是 $\textit{dfs}(0)$。

函数 $\textit{dfs}(i)$ 的计算方式如下：

-   如果 $i \geq n$，表示字符串 $\textit{target}$ 已经遍历完了，返回 $0$；
-   否则，我们可以从字典树中找到以 $\textit{target}[i]$ 开头的有效字符串，然后递归计算 $\textit{dfs}(i + \text{len}(w))$，其中 $w$ 是找到的有效字符串。我们取这些值中的最小值加 $1$ 作为 $\textit{dfs}(i)$ 的返回值。

为了避免重复计算，我们使用记忆化搜索。

时间复杂度 $O(n^2 + L)$，空间复杂度 $O(n + L)$。其中 $n$ 是字符串 $\textit{target}$ 的长度，而 $L$ 是所有有效字符串的总长度。

<!-- tabs:start -->

#### Python3

```python
def min(a: int, b: int) -> int:
    return a if a < b else b


class Trie:
    def __init__(self):
        self.children: List[Optional[Trie]] = [None] * 26

    def insert(self, w: str):
        node = self
        for i in map(lambda c: ord(c) - 97, w):
            if node.children[i] is None:
                node.children[i] = Trie()
            node = node.children[i]


class Solution:
    def minValidStrings(self, words: List[str], target: str) -> int:
        @cache
        def dfs(i: int) -> int:
            if i >= n:
                return 0
            node = trie
            ans = inf
            for j in range(i, n):
                k = ord(target[j]) - 97
                if node.children[k] is None:
                    break
                node = node.children[k]
                ans = min(ans, 1 + dfs(j + 1))
            return ans

        trie = Trie()
        for w in words:
            trie.insert(w)
        n = len(target)
        ans = dfs(0)
        return ans if ans < inf else -1
```

#### Java

```java
class Trie {
    Trie[] children = new Trie[26];

    void insert(String w) {
        Trie node = this;
        for (int i = 0; i < w.length(); ++i) {
            int j = w.charAt(i) - 'a';
            if (node.children[j] == null) {
                node.children[j] = new Trie();
            }
            node = node.children[j];
        }
    }
}

class Solution {
    private Integer[] f;
    private char[] s;
    private Trie trie;
    private final int inf = 1 << 30;

    public int minValidStrings(String[] words, String target) {
        trie = new Trie();
        for (String w : words) {
            trie.insert(w);
        }
        s = target.toCharArray();
        f = new Integer[s.length];
        int ans = dfs(0);
        return ans < inf ? ans : -1;
    }

    private int dfs(int i) {
        if (i >= s.length) {
            return 0;
        }
        if (f[i] != null) {
            return f[i];
        }
        Trie node = trie;
        f[i] = inf;
        for (int j = i; j < s.length; ++j) {
            int k = s[j] - 'a';
            if (node.children[k] == null) {
                break;
            }
            f[i] = Math.min(f[i], 1 + dfs(j + 1));
            node = node.children[k];
        }
        return f[i];
    }
}
```

#### C++

```cpp
class Trie {
public:
    Trie* children[26]{};

    void insert(string& word) {
        Trie* node = this;
        for (char& c : word) {
            int i = c - 'a';
            if (!node->children[i]) {
                node->children[i] = new Trie();
            }
            node = node->children[i];
        }
    }
};

class Solution {
public:
    int minValidStrings(vector<string>& words, string target) {
        int n = target.size();
        Trie* trie = new Trie();
        for (auto& w : words) {
            trie->insert(w);
        }
        const int inf = 1 << 30;
        int f[n];
        memset(f, -1, sizeof(f));
        auto dfs = [&](this auto&& dfs, int i) -> int {
            if (i >= n) {
                return 0;
            }
            if (f[i] != -1) {
                return f[i];
            }
            f[i] = inf;
            Trie* node = trie;
            for (int j = i; j < n; ++j) {
                int k = target[j] - 'a';
                if (!node->children[k]) {
                    break;
                }
                node = node->children[k];
                f[i] = min(f[i], 1 + dfs(j + 1));
            }
            return f[i];
        };
        int ans = dfs(0);
        return ans < inf ? ans : -1;
    }
};
```

#### Go

```go
type Trie struct {
	children [26]*Trie
}

func (t *Trie) insert(word string) {
	node := t
	for _, c := range word {
		idx := c - 'a'
		if node.children[idx] == nil {
			node.children[idx] = &Trie{}
		}
		node = node.children[idx]
	}
}

func minValidStrings(words []string, target string) int {
	n := len(target)
	trie := &Trie{}
	for _, w := range words {
		trie.insert(w)
	}
	const inf int = 1 << 30
	f := make([]int, n)
	var dfs func(int) int
	dfs = func(i int) int {
		if i >= n {
			return 0
		}
		if f[i] != 0 {
			return f[i]
		}
		node := trie
		f[i] = inf
		for j := i; j < n; j++ {
			k := int(target[j] - 'a')
			if node.children[k] == nil {
				break
			}
			f[i] = min(f[i], 1+dfs(j+1))
			node = node.children[k]
		}
		return f[i]
	}
	if ans := dfs(0); ans < inf {
		return ans
	}
	return -1
}
```

#### TypeScript

```ts
class Trie {
    children: (Trie | null)[] = Array(26).fill(null);

    insert(word: string): void {
        let node: Trie = this;
        for (const c of word) {
            const i = c.charCodeAt(0) - 'a'.charCodeAt(0);
            if (!node.children[i]) {
                node.children[i] = new Trie();
            }
            node = node.children[i];
        }
    }
}

function minValidStrings(words: string[], target: string): number {
    const n = target.length;
    const trie = new Trie();
    for (const w of words) {
        trie.insert(w);
    }
    const inf = 1 << 30;
    const f = Array(n).fill(0);

    const dfs = (i: number): number => {
        if (i >= n) {
            return 0;
        }
        if (f[i]) {
            return f[i];
        }
        f[i] = inf;
        let node: Trie | null = trie;
        for (let j = i; j < n; ++j) {
            const k = target[j].charCodeAt(0) - 'a'.charCodeAt(0);
            if (!node?.children[k]) {
                break;
            }
            node = node.children[k];
            f[i] = Math.min(f[i], 1 + dfs(j + 1));
        }
        return f[i];
    };

    const ans = dfs(0);
    return ans < inf ? ans : -1;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3292. 形成目标字符串需要的最少字符串数 II](https://leetcode.cn/problems/minimum-number-of-valid-strings-to-form-target-ii){#3292}

{{< tabs "3292" >}}

{{% tab "python" %}}
```python
class Hashing:
    __slots__ = ["mod", "h", "p"]

    def __init__(self, s: List[str], base: int, mod: int):
        self.mod = mod
        self.h = [0] * (len(s) + 1)
        self.p = [1] * (len(s) + 1)
        for i in range(1, len(s) + 1):
            self.h[i] = (self.h[i - 1] * base + ord(s[i - 1])) % mod
            self.p[i] = (self.p[i - 1] * base) % mod

    def query(self, l: int, r: int) -> int:
        return (self.h[r] - self.h[l - 1] * self.p[r - l + 1]) % self.mod


class Solution:
    def minValidStrings(self, words: List[str], target: str) -> int:
        def f(i: int) -> int:
            l, r = 0, min(n - i, m)
            while l < r:
                mid = (l + r + 1) >> 1
                sub = hashing.query(i + 1, i + mid)
                if sub in s[mid]:
                    l = mid
                else:
                    r = mid - 1
            return l

        base, mod = 13331, 998244353
        hashing = Hashing(target, base, mod)
        m = max(len(w) for w in words)
        s = [set() for _ in range(m + 1)]
        for w in words:
            h = 0
            for j, c in enumerate(w, 1):
                h = (h * base + ord(c)) % mod
                s[j].add(h)
        ans = last = mx = 0
        n = len(target)
        for i in range(n):
            dist = f(i)
            mx = max(mx, i + dist)
            if i == last:
                if i == mx:
                    return -1
                last = mx
                ans += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Hashing {
    private final long[] p;
    private final long[] h;
    private final long mod;

    public Hashing(String word, long base, int mod) {
        int n = word.length();
        p = new long[n + 1];
        h = new long[n + 1];
        p[0] = 1;
        this.mod = mod;
        for (int i = 1; i <= n; i++) {
            p[i] = p[i - 1] * base % mod;
            h[i] = (h[i - 1] * base + word.charAt(i - 1)) % mod;
        }
    }

    public long query(int l, int r) {
        return (h[r] - h[l - 1] * p[r - l + 1] % mod + mod) % mod;
    }
}

class Solution {
    private Hashing hashing;
    private Set<Long>[] s;

    public int minValidStrings(String[] words, String target) {
        int base = 13331, mod = 998244353;
        hashing = new Hashing(target, base, mod);
        int m = Arrays.stream(words).mapToInt(String::length).max().orElse(0);
        s = new Set[m + 1];
        Arrays.setAll(s, k -> new HashSet<>());
        for (String w : words) {
            long h = 0;
            for (int j = 0; j < w.length(); j++) {
                h = (h * base + w.charAt(j)) % mod;
                s[j + 1].add(h);
            }
        }

        int ans = 0;
        int last = 0;
        int mx = 0;
        int n = target.length();
        for (int i = 0; i < n; i++) {
            int dist = f(i, n, m);
            mx = Math.max(mx, i + dist);
            if (i == last) {
                if (i == mx) {
                    return -1;
                }
                last = mx;
                ans++;
            }
        }
        return ans;
    }

    private int f(int i, int n, int m) {
        int l = 0, r = Math.min(n - i, m);
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            long sub = hashing.query(i + 1, i + mid);
            if (s[mid].contains(sub)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Hashing {
private:
    vector<long long> p;
    vector<long long> h;
    long long mod;

public:
    Hashing(const string& word, long long base, int mod) {
        int n = word.size();
        p.resize(n + 1);
        h.resize(n + 1);
        p[0] = 1;
        this->mod = mod;
        for (int i = 1; i <= n; i++) {
            p[i] = (p[i - 1] * base) % mod;
            h[i] = (h[i - 1] * base + word[i - 1]) % mod;
        }
    }

    long long query(int l, int r) {
        return (h[r] - h[l - 1] * p[r - l + 1] % mod + mod) % mod;
    }
};

class Solution {
public:
    int minValidStrings(vector<string>& words, string target) {
        int base = 13331, mod = 998244353;
        Hashing hashing(target, base, mod);
        int m = 0, n = target.size();
        for (const string& word : words) {
            m = max(m, (int) word.size());
        }

        vector<unordered_set<long long>> s(m + 1);
        for (const string& w : words) {
            long long h = 0;
            for (int j = 0; j < w.size(); j++) {
                h = (h * base + w[j]) % mod;
                s[j + 1].insert(h);
            }
        }

        auto f = [&](int i) -> int {
            int l = 0, r = min(n - i, m);
            while (l < r) {
                int mid = (l + r + 1) >> 1;
                long long sub = hashing.query(i + 1, i + mid);
                if (s[mid].count(sub)) {
                    l = mid;
                } else {
                    r = mid - 1;
                }
            }
            return l;
        };

        int ans = 0, last = 0, mx = 0;
        for (int i = 0; i < n; i++) {
            int dist = f(i);
            mx = max(mx, i + dist);
            if (i == last) {
                if (i == mx) {
                    return -1;
                }
                last = mx;
                ans++;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
type Hashing struct {
	p   []int64
	h   []int64
	mod int64
}

func NewHashing(word string, base int64, mod int64) *Hashing {
	n := len(word)
	p := make([]int64, n+1)
	h := make([]int64, n+1)
	p[0] = 1
	for i := 1; i <= n; i++ {
		p[i] = (p[i-1] * base) % mod
		h[i] = (h[i-1]*base + int64(word[i-1])) % mod
	}
	return &Hashing{p, h, mod}
}

func (hashing *Hashing) Query(l, r int) int64 {
	return (hashing.h[r] - hashing.h[l-1]*hashing.p[r-l+1]%hashing.mod + hashing.mod) % hashing.mod
}

func minValidStrings(words []string, target string) (ans int) {
	base, mod := int64(13331), int64(998244353)
	hashing := NewHashing(target, base, mod)

	m, n := 0, len(target)
	for _, w := range words {
		m = max(m, len(w))
	}

	s := make([]map[int64]bool, m+1)

	f := func(i int) int {
		l, r := 0, int(math.Min(float64(n-i), float64(m)))
		for l < r {
			mid := (l + r + 1) >> 1
			sub := hashing.Query(i+1, i+mid)
			if s[mid][sub] {
				l = mid
			} else {
				r = mid - 1
			}
		}
		return l
	}

	for _, w := range words {
		h := int64(0)
		for j := 0; j < len(w); j++ {
			h = (h*base + int64(w[j])) % mod
			if s[j+1] == nil {
				s[j+1] = make(map[int64]bool)
			}
			s[j+1][h] = true
		}
	}

	var last, mx int

	for i := 0; i < n; i++ {
		dist := f(i)
		mx = max(mx, i+dist)
		if i == last {
			if i == mx {
				return -1
			}
			last = mx
			ans++
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

<p>给你一个字符串数组 <code>words</code> 和一个字符串 <code>target</code>。</p>

<p>如果字符串 <code>x</code> 是 <code>words</code> 中<strong> 任意 </strong>字符串的 <span data-keyword="string-prefix">前缀</span>，则认为 <code>x</code> 是一个 <strong>有效</strong> 字符串。</p>

<p>现计划通过 <strong>连接 </strong>有效字符串形成 <code>target</code> ，请你计算并返回需要连接的 <strong>最少 </strong>字符串数量。如果无法通过这种方式形成 <code>target</code>，则返回 <code>-1</code>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">words = ["abc","aaaaa","bcdef"], target = "aabcdabc"</span></p>

<p><strong>输出：</strong> <span class="example-io">3</span></p>

<p><strong>解释：</strong></p>

<p>target 字符串可以通过连接以下有效字符串形成：</p>

<ul>
	<li><code>words[1]</code> 的长度为 2 的前缀，即 <code>"aa"</code>。</li>
	<li><code>words[2]</code> 的长度为 3 的前缀，即 <code>"bcd"</code>。</li>
	<li><code>words[0]</code> 的长度为 3 的前缀，即 <code>"abc"</code>。</li>
</ul>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">words = ["abababab","ab"], target = "ababaababa"</span></p>

<p><strong>输出：</strong> <span class="example-io">2</span></p>

<p><strong>解释：</strong></p>

<p>target 字符串可以通过连接以下有效字符串形成：</p>

<ul>
	<li><code>words[0]</code> 的长度为 5 的前缀，即 <code>"ababa"</code>。</li>
	<li><code>words[0]</code> 的长度为 5 的前缀，即 <code>"ababa"</code>。</li>
</ul>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">words = ["abcdef"], target = "xyz"</span></p>

<p><strong>输出：</strong> <span class="example-io">-1</span></p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 100</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 5 * 10<sup>4</sup></code></li>
	<li>输入确保 <code>sum(words[i].length) &lt;= 10<sup>5</sup></code>.</li>
	<li><code>words[i]</code> &nbsp;只包含小写英文字母。</li>
	<li><code>1 &lt;= target.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>target</code> &nbsp;只包含小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：字符串哈希 + 二分查找 + 贪心

由于本题数据规模较大，使用“字典树 + 记忆化搜索”的方法将会超时，我们需要寻找一种更高效的解法。

考虑从字符串 $\textit{target}$ 的第 $i$ 个字符开始，最远能够匹配的字符串长度，假设为 $\textit{dist}$，那么对于任意 $j \in [i, i + \textit{dist}-1]$，我们都能够在 $\textit{words}$ 中找到一个字符串，使得 $\textit{target}[i..j]$ 是这个字符串的前缀。这存在着单调性，我们可以使用二分查找来确定 $\textit{dist}$。

具体地，我们首先预处理出 $\textit{words}$ 中所有字符串的每个前缀的哈希值，按照前缀长度分组存储在 $\textit{s}$ 数组中。另外，将 $\textit{target}$ 的哈希值也预处理出来，存储在 $\textit{hashing}$ 中，便于我们查询任意 $\textit{target}[l..r]$ 的哈希值。

接下来，我们设计一个函数 $\textit{f}(i)$，表示从字符串 $\textit{target}$ 的第 $i$ 个字符开始，最远能够匹配的字符串长度。我们可以通过二分查找的方式确定 $\textit{f}(i)$。

定义二分查找的左边界 $l = 0$，右边界 $r = \min(n - i, m)$，其中 $n$ 是字符串 $\textit{target}$ 的长度，而 $m$ 是 $\textit{words}$ 中字符串的最大长度。在二分查找的过程中，我们需要判断 $\textit{target}[i..i+\textit{mid}-1]$ 是否是 $\textit{s}[\textit{mid}]$ 中的某个哈希值，如果是，则将左边界 $l$ 更新为 $\textit{mid}$，否则将右边界 $r$ 更新为 $\textit{mid}-1$。二分结束后，返回 $l$ 即可。

算出 $\textit{f}(i)$ 后，问题就转化为了一个经典的贪心问题，我们从 $i = 0$ 开始，对于每个位置 $i$，最远可以移动到的位置为 $i + \textit{f}(i)$，求最少需要多少次移动即可到达终点。

我们定义 $\textit{last}$ 表示上一次移动的位置，变量 $\textit{mx}$ 表示当前位置能够移动到的最远位置，初始时 $\textit{last} = \textit{mx} = 0$。我们从 $i = 0$ 开始遍历，如果 $i$ 等于 $\textit{last}$，说明我们需要再次移动，此时如果 $\textit{last} = \textit{mx}$，说明我们无法再移动，返回 $-1$；否则，我们将 $\textit{last}$ 更新为 $\textit{mx}$，并将答案加一。

遍历结束后，返回答案即可。

时间复杂度 $O(n \times \log n + L)$，空间复杂度 $O(n + L)$。其中 $n$ 是字符串 $\textit{target}$ 的长度，而 $L$ 是所有有效字符串的总长度。

<!-- tabs:start -->

#### Python3

```python
class Hashing:
    __slots__ = ["mod", "h", "p"]

    def __init__(self, s: List[str], base: int, mod: int):
        self.mod = mod
        self.h = [0] * (len(s) + 1)
        self.p = [1] * (len(s) + 1)
        for i in range(1, len(s) + 1):
            self.h[i] = (self.h[i - 1] * base + ord(s[i - 1])) % mod
            self.p[i] = (self.p[i - 1] * base) % mod

    def query(self, l: int, r: int) -> int:
        return (self.h[r] - self.h[l - 1] * self.p[r - l + 1]) % self.mod


class Solution:
    def minValidStrings(self, words: List[str], target: str) -> int:
        def f(i: int) -> int:
            l, r = 0, min(n - i, m)
            while l < r:
                mid = (l + r + 1) >> 1
                sub = hashing.query(i + 1, i + mid)
                if sub in s[mid]:
                    l = mid
                else:
                    r = mid - 1
            return l

        base, mod = 13331, 998244353
        hashing = Hashing(target, base, mod)
        m = max(len(w) for w in words)
        s = [set() for _ in range(m + 1)]
        for w in words:
            h = 0
            for j, c in enumerate(w, 1):
                h = (h * base + ord(c)) % mod
                s[j].add(h)
        ans = last = mx = 0
        n = len(target)
        for i in range(n):
            dist = f(i)
            mx = max(mx, i + dist)
            if i == last:
                if i == mx:
                    return -1
                last = mx
                ans += 1
        return ans
```

#### Java

```java
class Hashing {
    private final long[] p;
    private final long[] h;
    private final long mod;

    public Hashing(String word, long base, int mod) {
        int n = word.length();
        p = new long[n + 1];
        h = new long[n + 1];
        p[0] = 1;
        this.mod = mod;
        for (int i = 1; i <= n; i++) {
            p[i] = p[i - 1] * base % mod;
            h[i] = (h[i - 1] * base + word.charAt(i - 1)) % mod;
        }
    }

    public long query(int l, int r) {
        return (h[r] - h[l - 1] * p[r - l + 1] % mod + mod) % mod;
    }
}

class Solution {
    private Hashing hashing;
    private Set<Long>[] s;

    public int minValidStrings(String[] words, String target) {
        int base = 13331, mod = 998244353;
        hashing = new Hashing(target, base, mod);
        int m = Arrays.stream(words).mapToInt(String::length).max().orElse(0);
        s = new Set[m + 1];
        Arrays.setAll(s, k -> new HashSet<>());
        for (String w : words) {
            long h = 0;
            for (int j = 0; j < w.length(); j++) {
                h = (h * base + w.charAt(j)) % mod;
                s[j + 1].add(h);
            }
        }

        int ans = 0;
        int last = 0;
        int mx = 0;
        int n = target.length();
        for (int i = 0; i < n; i++) {
            int dist = f(i, n, m);
            mx = Math.max(mx, i + dist);
            if (i == last) {
                if (i == mx) {
                    return -1;
                }
                last = mx;
                ans++;
            }
        }
        return ans;
    }

    private int f(int i, int n, int m) {
        int l = 0, r = Math.min(n - i, m);
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            long sub = hashing.query(i + 1, i + mid);
            if (s[mid].contains(sub)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
}
```

#### C++

```cpp
class Hashing {
private:
    vector<long long> p;
    vector<long long> h;
    long long mod;

public:
    Hashing(const string& word, long long base, int mod) {
        int n = word.size();
        p.resize(n + 1);
        h.resize(n + 1);
        p[0] = 1;
        this->mod = mod;
        for (int i = 1; i <= n; i++) {
            p[i] = (p[i - 1] * base) % mod;
            h[i] = (h[i - 1] * base + word[i - 1]) % mod;
        }
    }

    long long query(int l, int r) {
        return (h[r] - h[l - 1] * p[r - l + 1] % mod + mod) % mod;
    }
};

class Solution {
public:
    int minValidStrings(vector<string>& words, string target) {
        int base = 13331, mod = 998244353;
        Hashing hashing(target, base, mod);
        int m = 0, n = target.size();
        for (const string& word : words) {
            m = max(m, (int) word.size());
        }

        vector<unordered_set<long long>> s(m + 1);
        for (const string& w : words) {
            long long h = 0;
            for (int j = 0; j < w.size(); j++) {
                h = (h * base + w[j]) % mod;
                s[j + 1].insert(h);
            }
        }

        auto f = [&](int i) -> int {
            int l = 0, r = min(n - i, m);
            while (l < r) {
                int mid = (l + r + 1) >> 1;
                long long sub = hashing.query(i + 1, i + mid);
                if (s[mid].count(sub)) {
                    l = mid;
                } else {
                    r = mid - 1;
                }
            }
            return l;
        };

        int ans = 0, last = 0, mx = 0;
        for (int i = 0; i < n; i++) {
            int dist = f(i);
            mx = max(mx, i + dist);
            if (i == last) {
                if (i == mx) {
                    return -1;
                }
                last = mx;
                ans++;
            }
        }
        return ans;
    }
};
```

#### Go

```go
type Hashing struct {
	p   []int64
	h   []int64
	mod int64
}

func NewHashing(word string, base int64, mod int64) *Hashing {
	n := len(word)
	p := make([]int64, n+1)
	h := make([]int64, n+1)
	p[0] = 1
	for i := 1; i <= n; i++ {
		p[i] = (p[i-1] * base) % mod
		h[i] = (h[i-1]*base + int64(word[i-1])) % mod
	}
	return &Hashing{p, h, mod}
}

func (hashing *Hashing) Query(l, r int) int64 {
	return (hashing.h[r] - hashing.h[l-1]*hashing.p[r-l+1]%hashing.mod + hashing.mod) % hashing.mod
}

func minValidStrings(words []string, target string) (ans int) {
	base, mod := int64(13331), int64(998244353)
	hashing := NewHashing(target, base, mod)

	m, n := 0, len(target)
	for _, w := range words {
		m = max(m, len(w))
	}

	s := make([]map[int64]bool, m+1)

	f := func(i int) int {
		l, r := 0, int(math.Min(float64(n-i), float64(m)))
		for l < r {
			mid := (l + r + 1) >> 1
			sub := hashing.Query(i+1, i+mid)
			if s[mid][sub] {
				l = mid
			} else {
				r = mid - 1
			}
		}
		return l
	}

	for _, w := range words {
		h := int64(0)
		for j := 0; j < len(w); j++ {
			h = (h*base + int64(w[j])) % mod
			if s[j+1] == nil {
				s[j+1] = make(map[int64]bool)
			}
			s[j+1][h] = true
		}
	}

	var last, mx int

	for i := 0; i < n; i++ {
		dist := f(i)
		mx = max(mx, i+dist)
		if i == last {
			if i == mx {
				return -1
			}
			last = mx
			ans++
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

# [3293. 计算产品最终价格 🔒](https://leetcode.cn/problems/calculate-product-final-price){#3293}

{{< tabs "3293" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT
    product_id,
    price * (100 - IFNULL(discount, 0)) / 100 final_price,
    category
FROM
    Products
    LEFT JOIN Discounts USING (category)
ORDER BY 1;
```
{{% /tab %}}
{{% tab "python" %}}
```python
import pandas as pd


def calculate_final_prices(
    products: pd.DataFrame, discounts: pd.DataFrame
) -> pd.DataFrame:
    # Perform a left join on the 'category' column
    merged_df = pd.merge(products, discounts, on="category", how="left")

    # Calculate the final price
    merged_df["final_price"] = (
        merged_df["price"] * (100 - merged_df["discount"].fillna(0)) / 100
    )

    # Select the necessary columns and sort by 'product_id'
    result_df = merged_df[["product_id", "final_price", "category"]].sort_values(
        "product_id"
    )

    return result_df
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<font face="monospace"><code>Products</code></font></p>

<pre>
+------------+---------+ 
| Column Name| Type    | 
+------------+---------+ 
| product_id | int     | 
| category   | varchar |
| price      | decimal |
+------------+---------+
product_id 是这张表的唯一主键。
每一行包含产品的 ID，分类以及价格。
</pre>

<p>表：<font face="monospace"><code>Discounts</code></font></p>

<pre>
+------------+---------+ 
| Column Name| Type    | 
+------------+---------+ 
| category   | varchar |
| discount   | int     |
+------------+---------+
category 是这张表的主键。
每一行包含有一个产品分类和该分类的折扣百分比（值的范围从 0 到 100）。
</pre>

<p>编写一个解决方案来找到每个产品使用 <strong>分类折扣</strong>&nbsp;后的 <strong>最终价格</strong>。如果一个产品分类 <strong>没有关联的折扣</strong>，它的价格保持 <strong>不变</strong>。</p>

<p>返回结果表以&nbsp;<code>product_id</code><em> </em><strong>升序&nbsp;</strong>排序。</p>

<p>结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong class="example">示例：</strong></p>

<div class="example-block">
<p><strong>输入：</strong></p>

<p><code>Products</code> 表：</p>

<pre class="example-io">
+------------+-------------+-------+
| product_id | category    | price |
+------------+-------------+-------+
| 1          | Electronics | 1000  |
| 2          | Clothing    | 50    |
| 3          | Electronics | 1200  | 
| 4          | Home        | 500   |
+------------+-------------+-------+
  </pre>

<p><code>Discounts</code> 表：</p>

<pre class="example-io">
+------------+----------+
| category   | discount |
+------------+----------+
| Electronics| 10       |
| Clothing   | 20       |
+------------+----------+
  </pre>

<p><strong>输出：</strong></p>

<pre class="example-io">
+------------+------------+-------------+
| product_id | final_price| category    |
+------------+------------+-------------+
| 1          | 900        | Electronics |
| 2          | 40         | Clothing    |
| 3          | 1080       | Electronics |
| 4          | 500        | Home        |
+------------+------------+-------------+
  </pre>

<p><strong>解释：</strong></p>

<ul>
	<li>对于产品 1，它属于电器分类，有 10% 的折扣，所以最终价格为 1000 - (10% of 1000) = 900。</li>
	<li>对于产品 2，它属于衣物分类，有 20% 的折扣，所以最终价格为 50 - (20% of 50) = 40。</li>
	<li>对于产品 3，它属于电器分类，有 10% 的折扣，所以最终价格为&nbsp;1200 - (10% of 1200) = 1080。</li>
	<li>对于产品 4，它属于家具分类，没有可用的折扣，所以最终价格仍是 500。</li>
</ul>
结果表以 product_id 升序排序。</div>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：左连接

我们可以将 `Products` 表和 `Discounts` 表按照 `category` 列进行左连接，然后计算最终价格。如果某个产品的类别没有关联的折扣，那么它的价格保持不变。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT
    product_id,
    price * (100 - IFNULL(discount, 0)) / 100 final_price,
    category
FROM
    Products
    LEFT JOIN Discounts USING (category)
ORDER BY 1;
```

#### Pandas

```python
import pandas as pd


def calculate_final_prices(
    products: pd.DataFrame, discounts: pd.DataFrame
) -> pd.DataFrame:
    # Perform a left join on the 'category' column
    merged_df = pd.merge(products, discounts, on="category", how="left")

    # Calculate the final price
    merged_df["final_price"] = (
        merged_df["price"] * (100 - merged_df["discount"].fillna(0)) / 100
    )

    # Select the necessary columns and sort by 'product_id'
    result_df = merged_df[["product_id", "final_price", "category"]].sort_values(
        "product_id"
    )

    return result_df
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3294. 将双链表转换为数组 II 🔒](https://leetcode.cn/problems/convert-doubly-linked-list-to-array-ii){#3294}

{{< tabs "3294" >}}

{{% tab "python" %}}
```python
"""
# Definition for a Node.
class Node:
    def __init__(self, val, prev=None, next=None):
        self.val = val
        self.prev = prev
        self.next = next
"""


class Solution:
    def toArray(self, node: "Optional[Node]") -> List[int]:
        while node.prev:
            node = node.prev
        ans = []
        while node:
            ans.append(node.val)
            node = node.next
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
/*
// Definition for a Node.
class Node {
    public int val;
    public Node prev;
    public Node next;
};
*/

class Solution {
    public int[] toArray(Node node) {
        while (node != null && node.prev != null) {
            node = node.prev;
        }
        var ans = new ArrayList<Integer>();
        for (; node != null; node = node.next) {
            ans.add(node.val);
        }
        return ans.stream().mapToInt(i -> i).toArray();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
/**
 * Definition for doubly-linked list.
 * class Node {
 *     int val;
 *     Node* prev;
 *     Node* next;
 *     Node() : val(0), next(nullptr), prev(nullptr) {}
 *     Node(int x) : val(x), next(nullptr), prev(nullptr) {}
 *     Node(int x, Node *prev, Node *next) : val(x), next(next), prev(prev) {}
 * };
 */
class Solution {
public:
    vector<int> toArray(Node* node) {
        while (node && node->prev) {
            node = node->prev;
        }
        vector<int> ans;
        for (; node; node = node->next) {
            ans.push_back(node->val);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Next *Node
 *     Prev *Node
 * }
 */

func toArray(node *Node) (ans []int) {
	for node != nil && node.Prev != nil {
		node = node.Prev
	}
	for ; node != nil; node = node.Next {
		ans = append(ans, node.Val)
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
/**
 * Definition for _Node.
 * class _Node {
 *     val: number
 *     prev: _Node | null
 *     next: _Node | null
 *
 *     constructor(val?: number, prev? : _Node, next? : _Node) {
 *         this.val = (val===undefined ? 0 : val);
 *         this.prev = (prev===undefined ? null : prev);
 *         this.next = (next===undefined ? null : next);
 *     }
 * }
 */

function toArray(node: _Node | null): number[] {
    while (node && node.prev) {
        node = node.prev;
    }
    const ans: number[] = [];
    for (; node; node = node.next) {
        ans.push(node.val);
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

<p>给定一个 <strong>双链表&nbsp;</strong>的&nbsp;<b>任意</b>&nbsp;<code>node</code>，其中的节点具有指向下一个节点的指针和上一个节点的指针。</p>

<p>返回一个 <strong>按顺序</strong> 包含链表中元素的整数数组。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">head = [1,2,3,4,5], node = 5</span></p>

<p><span class="example-io"><b>输出：</b>[1,2,3,4,5]</span></p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>head = [4,5,6,7,8], node = 8</span></p>

<p><span class="example-io"><b>输出：</b>[4,5,6,7,8]</span></p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>给定列表中的节点数在范围&nbsp;<code>[1, 500]</code>&nbsp;内。</li>
	<li><code>1 &lt;= Node.val &lt;= 1000</code></li>
	<li>所有节点的&nbsp;<code>Node.val</code>&nbsp;互不相同。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：遍历链表

我们可以从给定的节点开始，往前遍历链表，直到遍历到头节点，然后再从头节点开始往后遍历链表，将遍历到的节点的值添加到答案数组中。

遍历结束后，返回答案数组即可。

时间复杂度 $O(n)$，其中 $n$ 为链表的节点个数。忽略答案数组的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
"""
# Definition for a Node.
class Node:
    def __init__(self, val, prev=None, next=None):
        self.val = val
        self.prev = prev
        self.next = next
"""


class Solution:
    def toArray(self, node: "Optional[Node]") -> List[int]:
        while node.prev:
            node = node.prev
        ans = []
        while node:
            ans.append(node.val)
            node = node.next
        return ans
```

#### Java

```java
/*
// Definition for a Node.
class Node {
    public int val;
    public Node prev;
    public Node next;
};
*/

class Solution {
    public int[] toArray(Node node) {
        while (node != null && node.prev != null) {
            node = node.prev;
        }
        var ans = new ArrayList<Integer>();
        for (; node != null; node = node.next) {
            ans.add(node.val);
        }
        return ans.stream().mapToInt(i -> i).toArray();
    }
}
```

#### C++

```cpp
/**
 * Definition for doubly-linked list.
 * class Node {
 *     int val;
 *     Node* prev;
 *     Node* next;
 *     Node() : val(0), next(nullptr), prev(nullptr) {}
 *     Node(int x) : val(x), next(nullptr), prev(nullptr) {}
 *     Node(int x, Node *prev, Node *next) : val(x), next(next), prev(prev) {}
 * };
 */
class Solution {
public:
    vector<int> toArray(Node* node) {
        while (node && node->prev) {
            node = node->prev;
        }
        vector<int> ans;
        for (; node; node = node->next) {
            ans.push_back(node->val);
        }
        return ans;
    }
};
```

#### Go

```go
/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Next *Node
 *     Prev *Node
 * }
 */

func toArray(node *Node) (ans []int) {
	for node != nil && node.Prev != nil {
		node = node.Prev
	}
	for ; node != nil; node = node.Next {
		ans = append(ans, node.Val)
	}
	return
}
```

#### TypeScript

```ts
/**
 * Definition for _Node.
 * class _Node {
 *     val: number
 *     prev: _Node | null
 *     next: _Node | null
 *
 *     constructor(val?: number, prev? : _Node, next? : _Node) {
 *         this.val = (val===undefined ? 0 : val);
 *         this.prev = (prev===undefined ? null : prev);
 *         this.next = (next===undefined ? null : next);
 *     }
 * }
 */

function toArray(node: _Node | null): number[] {
    while (node && node.prev) {
        node = node.prev;
    }
    const ans: number[] = [];
    for (; node; node = node.next) {
        ans.push(node.val);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3295. 举报垃圾信息](https://leetcode.cn/problems/report-spam-message){#3295}

{{< tabs "3295" >}}

{{% tab "python" %}}
```python
class Solution:
    def reportSpam(self, message: List[str], bannedWords: List[str]) -> bool:
        s = set(bannedWords)
        return sum(w in s for w in message) >= 2
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean reportSpam(String[] message, String[] bannedWords) {
        Set<String> s = new HashSet<>();
        for (var w : bannedWords) {
            s.add(w);
        }
        int cnt = 0;
        for (var w : message) {
            if (s.contains(w) && ++cnt >= 2) {
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
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_set<string> s(bannedWords.begin(), bannedWords.end());
        int cnt = 0;
        for (const auto& w : message) {
            if (s.contains(w) && ++cnt >= 2) {
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
func reportSpam(message []string, bannedWords []string) bool {
	s := map[string]bool{}
	for _, w := range bannedWords {
		s[w] = true
	}
	cnt := 0
	for _, w := range message {
		if s[w] {
			cnt++
			if cnt >= 2 {
				return true
			}
		}
	}
	return false
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function reportSpam(message: string[], bannedWords: string[]): boolean {
    const s = new Set<string>(bannedWords);
    let cnt = 0;
    for (const w of message) {
        if (s.has(w) && ++cnt >= 2) {
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

<p>给你一个字符串数组 <code>message</code> 和一个字符串数组 <code>bannedWords</code>。</p>

<p>如果数组中 <strong>至少</strong> 存在两个单词与 <code>bannedWords</code> 中的任一单词 <strong>完全相同</strong>，则该数组被视为 <strong>垃圾信息</strong>。</p>

<p>如果数组 <code>message</code> 是垃圾信息，则返回 <code>true</code>；否则返回 <code>false</code>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">message = ["hello","world","leetcode"], bannedWords = ["world","hello"]</span></p>

<p><strong>输出：</strong> <span class="example-io">true</span></p>

<p><strong>解释：</strong></p>

<p>数组 <code>message</code> 中的 <code>"hello"</code> 和 <code>"world"</code> 都出现在数组 <code>bannedWords</code> 中。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">message = ["hello","programming","fun"], bannedWords = ["world","programming","leetcode"]</span></p>

<p><strong>输出：</strong> <span class="example-io">false</span></p>

<p><strong>解释：</strong></p>

<p>数组 <code>message</code> 中只有一个单词（<code>"programming"</code>）出现在数组 <code>bannedWords</code> 中。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= message.length, bannedWords.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= message[i].length, bannedWords[i].length &lt;= 15</code></li>
	<li><code>message[i]</code> 和 <code>bannedWords[i]</code> 都只由小写英文字母组成。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

我们用一个哈希表 $s$ 存储 $\textit{bannedWords}$ 中的所有单词，然后遍历 $\textit{message}$ 中的每个单词，如果单词在哈希表 $s$ 中出现，我们就将计数器 $cnt$ 加一，如果 $cnt$ 大于等于 $2$，我们就返回 $\text{true}$，否则返回 $\text{false}$。

时间复杂度 $O((n + m) \times |w|)$，空间复杂度 $O(m \times |w|)$。其中 $n$ 是数组 $\textit{message}$ 的长度，而 $m$ 和 $|w|$ 分别是数组 $\textit{bannedWords}$ 的长度和数组中单词的最大长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def reportSpam(self, message: List[str], bannedWords: List[str]) -> bool:
        s = set(bannedWords)
        return sum(w in s for w in message) >= 2
```

#### Java

```java
class Solution {
    public boolean reportSpam(String[] message, String[] bannedWords) {
        Set<String> s = new HashSet<>();
        for (var w : bannedWords) {
            s.add(w);
        }
        int cnt = 0;
        for (var w : message) {
            if (s.contains(w) && ++cnt >= 2) {
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
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_set<string> s(bannedWords.begin(), bannedWords.end());
        int cnt = 0;
        for (const auto& w : message) {
            if (s.contains(w) && ++cnt >= 2) {
                return true;
            }
        }
        return false;
    }
};
```

#### Go

```go
func reportSpam(message []string, bannedWords []string) bool {
	s := map[string]bool{}
	for _, w := range bannedWords {
		s[w] = true
	}
	cnt := 0
	for _, w := range message {
		if s[w] {
			cnt++
			if cnt >= 2 {
				return true
			}
		}
	}
	return false
}
```

#### TypeScript

```ts
function reportSpam(message: string[], bannedWords: string[]): boolean {
    const s = new Set<string>(bannedWords);
    let cnt = 0;
    for (const w of message) {
        if (s.has(w) && ++cnt >= 2) {
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

# [3296. 移山所需的最少秒数](https://leetcode.cn/problems/minimum-number-of-seconds-to-make-mountain-height-zero){#3296}

{{< tabs "3296" >}}

{{% tab "python" %}}
```python
class Solution:
    def minNumberOfSeconds(self, mountainHeight: int, workerTimes: List[int]) -> int:
        def check(t: int) -> bool:
            h = 0
            for wt in workerTimes:
                h += int(sqrt(2 * t / wt + 1 / 4) - 1 / 2)
            return h >= mountainHeight

        return bisect_left(range(10**16), True, key=check)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int mountainHeight;
    private int[] workerTimes;

    public long minNumberOfSeconds(int mountainHeight, int[] workerTimes) {
        this.mountainHeight = mountainHeight;
        this.workerTimes = workerTimes;
        long l = 1, r = (long) 1e16;
        while (l < r) {
            long mid = (l + r) >> 1;
            if (check(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }

    private boolean check(long t) {
        long h = 0;
        for (int wt : workerTimes) {
            h += (long) (Math.sqrt(t * 2.0 / wt + 0.25) - 0.5);
        }
        return h >= mountainHeight;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        using ll = long long;
        ll l = 1, r = 1e16;
        auto check = [&](ll t) -> bool {
            ll h = 0;
            for (int& wt : workerTimes) {
                h += (long long) (sqrt(t * 2.0 / wt + 0.25) - 0.5);
            }
            return h >= mountainHeight;
        };
        while (l < r) {
            ll mid = (l + r) >> 1;
            if (check(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minNumberOfSeconds(mountainHeight int, workerTimes []int) int64 {
	return int64(sort.Search(1e16, func(t int) bool {
		var h int64
		for _, wt := range workerTimes {
			h += int64(math.Sqrt(float64(t)*2.0/float64(wt)+0.25) - 0.5)
		}
		return h >= int64(mountainHeight)
	}))
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minNumberOfSeconds(mountainHeight: number, workerTimes: number[]): number {
    const check = (t: bigint): boolean => {
        let h = BigInt(0);
        for (const wt of workerTimes) {
            h += BigInt(Math.floor(Math.sqrt((Number(t) * 2.0) / wt + 0.25) - 0.5));
        }
        return h >= BigInt(mountainHeight);
    };

    let l = BigInt(1);
    let r = BigInt(1e16);

    while (l < r) {
        const mid = (l + r) >> BigInt(1);
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1n;
        }
    }

    return Number(l);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数 <code>mountainHeight</code> 表示山的高度。</p>

<p>同时给你一个整数数组 <code>workerTimes</code>，表示工人们的工作时间（单位：<strong>秒</strong>）。</p>

<p>工人们需要 <strong>同时 </strong>进行工作以 <strong>降低 </strong>山的高度。对于工人 <code>i</code> :</p>

<ul>
	<li>山的高度降低 <code>x</code>，需要花费 <code>workerTimes[i] + workerTimes[i] * 2 + ... + workerTimes[i] * x</code> 秒。例如：

    <ul>
    	<li>山的高度降低 1，需要 <code>workerTimes[i]</code> 秒。</li>
    	<li>山的高度降低 2，需要 <code>workerTimes[i] + workerTimes[i] * 2</code> 秒，依此类推。</li>
    </ul>
    </li>

</ul>

<p>返回一个整数，表示工人们使山的高度降低到 0 所需的 <strong>最少</strong> 秒数。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">mountainHeight = 4, workerTimes = [2,1,1]</span></p>

<p><strong>输出：</strong> <span class="example-io">3</span></p>

<p><strong>解释：</strong></p>

<p>将山的高度降低到 0 的一种方式是：</p>

<ul>
	<li>工人 0 将高度降低 1，花费 <code>workerTimes[0] = 2</code> 秒。</li>
	<li>工人 1 将高度降低 2，花费 <code>workerTimes[1] + workerTimes[1] * 2 = 3</code> 秒。</li>
	<li>工人 2 将高度降低 1，花费 <code>workerTimes[2] = 1</code> 秒。</li>
</ul>

<p>因为工人同时工作，所需的最少时间为 <code>max(2, 3, 1) = 3</code> 秒。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">mountainHeight = 10, workerTimes = [3,2,2,4]</span></p>

<p><strong>输出：</strong> <span class="example-io">12</span></p>

<p><strong>解释：</strong></p>

<ul>
	<li>工人 0 将高度降低 2，花费 <code>workerTimes[0] + workerTimes[0] * 2 = 9</code> 秒。</li>
	<li>工人 1 将高度降低 3，花费 <code>workerTimes[1] + workerTimes[1] * 2 + workerTimes[1] * 3 = 12</code> 秒。</li>
	<li>工人 2 将高度降低 3，花费 <code>workerTimes[2] + workerTimes[2] * 2 + workerTimes[2] * 3 = 12</code> 秒。</li>
	<li>工人 3 将高度降低 2，花费 <code>workerTimes[3] + workerTimes[3] * 2 = 12</code> 秒。</li>
</ul>

<p>所需的最少时间为 <code>max(9, 12, 12, 12) = 12</code> 秒。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">mountainHeight = 5, workerTimes = [1]</span></p>

<p><strong>输出：</strong> <span class="example-io">15</span></p>

<p><strong>解释：</strong></p>

<p>这个示例中只有一个工人，所以答案是 <code>workerTimes[0] + workerTimes[0] * 2 + workerTimes[0] * 3 + workerTimes[0] * 4 + workerTimes[0] * 5 = 15</code> 秒。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= mountainHeight &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= workerTimes.length &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= workerTimes[i] &lt;= 10<sup>6</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二分查找

我们注意到，如果所有的工人能在 $t$ 秒内将山的高度降低到 $0$，那么对于任意 $t' > t$，工人们也能在 $t'$ 秒内将山的高度降低到 $0$。因此，我们可以使用二分查找的方法找到最小的 $t$，使得工人们能在 $t$ 秒内将山的高度降低到 $0$。

我们定义一个函数 $\textit{check}(t)$，表示工人们能否在 $t$ 秒内将山的高度降低到 $0$。具体地，我们遍历每一个工人，对于当前工人 $\textit{workerTimes}[i]$，假设他在 $t$ 秒内降低了 $h'$ 的高度，那么我们可以得到一个不等式：

<!-- (1+h')h'/2 wt <= t -->

$$
\left(1 + h'\right) \cdot \frac{h'}{2} \cdot \textit{workerTimes}[i] \leq t
$$

解不等式得到：

$$
h' \leq \left\lfloor \sqrt{\frac{2t}{\textit{workerTimes}[i]} + \frac{1}{4}} - \frac{1}{2} \right\rfloor
$$

我们可以将所有工人的 $h'$ 相加，得到总共降低的高度 $h$，如果 $h \geq \textit{mountainHeight}$，那么说明工人们能在 $t$ 秒内将山的高度降低到 $0$。

接下来，我们确定二分查找的左边界 $l = 1$，由于最少有一个工作，且每个工人的工作时间不超过 $10^6$，要想使山的高度降低到 $0$，最少需要 $(1 + \textit{mountainHeight}) \cdot \textit{mountainHeight} / 2 \cdot \textit{workerTimes}[i] \leq 10^{16}$ 秒，因此我们可以确定二分查找的右边界 $r = 10^{16}$。然后我们不断地将区间 $[l, r]$ 二分，直到 $l = r$，此时 $l$ 即为答案。

时间复杂度 $O(n \times \log M)$，其中 $n$ 为工人的数量，而 $M$ 为二分查找的右边界，本题中 $M = 10^{16}$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minNumberOfSeconds(self, mountainHeight: int, workerTimes: List[int]) -> int:
        def check(t: int) -> bool:
            h = 0
            for wt in workerTimes:
                h += int(sqrt(2 * t / wt + 1 / 4) - 1 / 2)
            return h >= mountainHeight

        return bisect_left(range(10**16), True, key=check)
```

#### Java

```java
class Solution {
    private int mountainHeight;
    private int[] workerTimes;

    public long minNumberOfSeconds(int mountainHeight, int[] workerTimes) {
        this.mountainHeight = mountainHeight;
        this.workerTimes = workerTimes;
        long l = 1, r = (long) 1e16;
        while (l < r) {
            long mid = (l + r) >> 1;
            if (check(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }

    private boolean check(long t) {
        long h = 0;
        for (int wt : workerTimes) {
            h += (long) (Math.sqrt(t * 2.0 / wt + 0.25) - 0.5);
        }
        return h >= mountainHeight;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        using ll = long long;
        ll l = 1, r = 1e16;
        auto check = [&](ll t) -> bool {
            ll h = 0;
            for (int& wt : workerTimes) {
                h += (long long) (sqrt(t * 2.0 / wt + 0.25) - 0.5);
            }
            return h >= mountainHeight;
        };
        while (l < r) {
            ll mid = (l + r) >> 1;
            if (check(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
```

#### Go

```go
func minNumberOfSeconds(mountainHeight int, workerTimes []int) int64 {
	return int64(sort.Search(1e16, func(t int) bool {
		var h int64
		for _, wt := range workerTimes {
			h += int64(math.Sqrt(float64(t)*2.0/float64(wt)+0.25) - 0.5)
		}
		return h >= int64(mountainHeight)
	}))
}
```

#### TypeScript

```ts
function minNumberOfSeconds(mountainHeight: number, workerTimes: number[]): number {
    const check = (t: bigint): boolean => {
        let h = BigInt(0);
        for (const wt of workerTimes) {
            h += BigInt(Math.floor(Math.sqrt((Number(t) * 2.0) / wt + 0.25) - 0.5));
        }
        return h >= BigInt(mountainHeight);
    };

    let l = BigInt(1);
    let r = BigInt(1e16);

    while (l < r) {
        const mid = (l + r) >> BigInt(1);
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1n;
        }
    }

    return Number(l);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3297. 统计重新排列后包含另一个字符串的子字符串数目 I](https://leetcode.cn/problems/count-substrings-that-can-be-rearranged-to-contain-a-string-i){#3297}

{{< tabs "3297" >}}

{{% tab "python" %}}
```python
class Solution:
    def validSubstringCount(self, word1: str, word2: str) -> int:
        if len(word1) < len(word2):
            return 0
        cnt = Counter(word2)
        need = len(cnt)
        ans = l = 0
        win = Counter()
        for c in word1:
            win[c] += 1
            if win[c] == cnt[c]:
                need -= 1
            while need == 0:
                if win[word1[l]] == cnt[word1[l]]:
                    need += 1
                win[word1[l]] -= 1
                l += 1
            ans += l
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long validSubstringCount(String word1, String word2) {
        if (word1.length() < word2.length()) {
            return 0;
        }
        int[] cnt = new int[26];
        int need = 0;
        for (int i = 0; i < word2.length(); ++i) {
            if (++cnt[word2.charAt(i) - 'a'] == 1) {
                ++need;
            }
        }
        long ans = 0;
        int[] win = new int[26];
        for (int l = 0, r = 0; r < word1.length(); ++r) {
            int c = word1.charAt(r) - 'a';
            if (++win[c] == cnt[c]) {
                --need;
            }
            while (need == 0) {
                c = word1.charAt(l) - 'a';
                if (win[c] == cnt[c]) {
                    ++need;
                }
                --win[c];
                ++l;
            }
            ans += l;
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
    long long validSubstringCount(string word1, string word2) {
        if (word1.size() < word2.size()) {
            return 0;
        }
        int cnt[26]{};
        int need = 0;
        for (char& c : word2) {
            if (++cnt[c - 'a'] == 1) {
                ++need;
            }
        }
        long long ans = 0;
        int win[26]{};
        int l = 0;
        for (char& c : word1) {
            int i = c - 'a';
            if (++win[i] == cnt[i]) {
                --need;
            }
            while (need == 0) {
                i = word1[l] - 'a';
                if (win[i] == cnt[i]) {
                    ++need;
                }
                --win[i];
                ++l;
            }
            ans += l;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func validSubstringCount(word1 string, word2 string) (ans int64) {
	if len(word1) < len(word2) {
		return 0
	}
	cnt := [26]int{}
	need := 0
	for _, c := range word2 {
		cnt[c-'a']++
		if cnt[c-'a'] == 1 {
			need++
		}
	}
	win := [26]int{}
	l := 0
	for _, c := range word1 {
		i := int(c - 'a')
		win[i]++
		if win[i] == cnt[i] {
			need--
		}
		for need == 0 {
			i = int(word1[l] - 'a')
			if win[i] == cnt[i] {
				need++
			}
			win[i]--
			l++
		}
		ans += int64(l)
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function validSubstringCount(word1: string, word2: string): number {
    if (word1.length < word2.length) {
        return 0;
    }
    const cnt: number[] = Array(26).fill(0);
    let need: number = 0;
    for (const c of word2) {
        if (++cnt[c.charCodeAt(0) - 97] === 1) {
            ++need;
        }
    }
    const win: number[] = Array(26).fill(0);
    let [ans, l] = [0, 0];
    for (const c of word1) {
        const i = c.charCodeAt(0) - 97;
        if (++win[i] === cnt[i]) {
            --need;
        }
        while (need === 0) {
            const j = word1[l].charCodeAt(0) - 97;
            if (win[j] === cnt[j]) {
                ++need;
            }
            --win[j];
            ++l;
        }
        ans += l;
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

<p>给你两个字符串&nbsp;<code>word1</code> 和&nbsp;<code>word2</code>&nbsp;。</p>

<p>如果一个字符串 <code>x</code>&nbsp;重新排列后，<code>word2</code>&nbsp;是重排字符串的&nbsp;<span data-keyword="string-prefix">前缀</span>&nbsp;，那么我们称字符串&nbsp;<code>x</code>&nbsp;是&nbsp;<strong>合法的</strong>&nbsp;。</p>

<p>请你返回 <code>word1</code>&nbsp;中 <strong>合法</strong>&nbsp;<span data-keyword="substring-nonempty">子字符串</span>&nbsp;的数目。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>word1 = "bcca", word2 = "abc"</span></p>

<p><span class="example-io"><b>输出：</b>1</span></p>

<p><strong>解释：</strong></p>

<p>唯一合法的子字符串是&nbsp;<code>"bcca"</code>&nbsp;，可以重新排列得到&nbsp;<code>"abcc"</code>&nbsp;，<code>"abc"</code>&nbsp;是它的前缀。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>word1 = "abcabc", word2 = "abc"</span></p>

<p><span class="example-io"><b>输出：</b>10</span></p>

<p><strong>解释：</strong></p>

<p>除了长度为 1 和 2 的所有子字符串都是合法的。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>word1 = "abcabc", word2 = "aaabc"</span></p>

<p><span class="example-io"><b>输出：</b>0</span></p>
</div>

<p>&nbsp;</p>

<p><strong>解释：</strong></p>

<ul>
	<li><code>1 &lt;= word1.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= word2.length &lt;= 10<sup>4</sup></code></li>
	<li><code>word1</code> 和&nbsp;<code>word2</code>&nbsp;都只包含小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：滑动窗口

题目实际上是求在 $\textit{word1}$ 中，有多少个子串包含了 $\textit{word2}$ 中的所有字符。我们可以使用滑动窗口来处理。

首先，如果 $\textit{word1}$ 的长度小于 $\textit{word2}$ 的长度，那么 $\textit{word1}$ 中不可能包含 $\textit{word2}$ 的所有字符，直接返回 $0$。

接下来，我们用一个哈希表或长度为 $26$ 的数组 $\textit{cnt}$ 来统计 $\textit{word2}$ 中的字符出现的次数。然后，我们用 $\textit{need}$ 来记录还需要多少个字符才能满足条件，初始化为 $\textit{cnt}$ 的长度。

接着，我们用一个滑动窗口 $\textit{win}$ 来记录当前窗口中的字符出现的次数。我们用 $\textit{ans}$ 来记录满足条件的子串的个数，用 $\textit{l}$ 来记录窗口的左边界。

遍历 $\textit{word1}$ 中的每个字符，对于当前字符 $c$，我们将其加入到 $\textit{win}$ 中，如果 $\textit{win}[c]$ 的值等于 $\textit{cnt}[c]$，那么说明当前窗口中已经包含了 $\textit{word2}$ 中的所有字符之一，那么 $\textit{need}$ 减一。如果 $\textit{need}$ 等于 $0$，说明当前窗口中包含了 $\textit{word2}$ 中的所有字符，我们需要缩小窗口的左边界，直到 $\textit{need}$ 大于 $0$。具体地，如果 $\textit{win}[\textit{word1}[l]]$ 等于 $\textit{cnt}[\textit{word1}[l]]$，那么说明当前窗口中包含了 $\textit{word2}$ 中的所有字符之一，那么缩小窗口的左边界之后，就不满足条件了，所以 $\textit{need}$ 加一，同时 $\textit{win}[\textit{word1}[l]]$ 减一。然后，我们将 $\textit{l}$ 加一。此时窗口为 $[l, r]$，那么对于任意 $0 \leq l' \lt l$，$[l', r]$ 都是满足条件的子串，一共有 $l$ 个，我们累加到答案中。

遍历完 $\textit{word1}$ 中的所有字符之后，我们就得到了答案。

时间复杂度 $O(n + m)$，其中 $n$ 和 $m$ 分别是 $\textit{word1}$ 和 $\textit{word2}$ 的长度。空间复杂度 $O(|\Sigma|)$，其中 $\Sigma$ 是字符集，这里是小写字母集合，所以空间复杂度是常数级别的。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def validSubstringCount(self, word1: str, word2: str) -> int:
        if len(word1) < len(word2):
            return 0
        cnt = Counter(word2)
        need = len(cnt)
        ans = l = 0
        win = Counter()
        for c in word1:
            win[c] += 1
            if win[c] == cnt[c]:
                need -= 1
            while need == 0:
                if win[word1[l]] == cnt[word1[l]]:
                    need += 1
                win[word1[l]] -= 1
                l += 1
            ans += l
        return ans
```

#### Java

```java
class Solution {
    public long validSubstringCount(String word1, String word2) {
        if (word1.length() < word2.length()) {
            return 0;
        }
        int[] cnt = new int[26];
        int need = 0;
        for (int i = 0; i < word2.length(); ++i) {
            if (++cnt[word2.charAt(i) - 'a'] == 1) {
                ++need;
            }
        }
        long ans = 0;
        int[] win = new int[26];
        for (int l = 0, r = 0; r < word1.length(); ++r) {
            int c = word1.charAt(r) - 'a';
            if (++win[c] == cnt[c]) {
                --need;
            }
            while (need == 0) {
                c = word1.charAt(l) - 'a';
                if (win[c] == cnt[c]) {
                    ++need;
                }
                --win[c];
                ++l;
            }
            ans += l;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        if (word1.size() < word2.size()) {
            return 0;
        }
        int cnt[26]{};
        int need = 0;
        for (char& c : word2) {
            if (++cnt[c - 'a'] == 1) {
                ++need;
            }
        }
        long long ans = 0;
        int win[26]{};
        int l = 0;
        for (char& c : word1) {
            int i = c - 'a';
            if (++win[i] == cnt[i]) {
                --need;
            }
            while (need == 0) {
                i = word1[l] - 'a';
                if (win[i] == cnt[i]) {
                    ++need;
                }
                --win[i];
                ++l;
            }
            ans += l;
        }
        return ans;
    }
};
```

#### Go

```go
func validSubstringCount(word1 string, word2 string) (ans int64) {
	if len(word1) < len(word2) {
		return 0
	}
	cnt := [26]int{}
	need := 0
	for _, c := range word2 {
		cnt[c-'a']++
		if cnt[c-'a'] == 1 {
			need++
		}
	}
	win := [26]int{}
	l := 0
	for _, c := range word1 {
		i := int(c - 'a')
		win[i]++
		if win[i] == cnt[i] {
			need--
		}
		for need == 0 {
			i = int(word1[l] - 'a')
			if win[i] == cnt[i] {
				need++
			}
			win[i]--
			l++
		}
		ans += int64(l)
	}
	return
}
```

#### TypeScript

```ts
function validSubstringCount(word1: string, word2: string): number {
    if (word1.length < word2.length) {
        return 0;
    }
    const cnt: number[] = Array(26).fill(0);
    let need: number = 0;
    for (const c of word2) {
        if (++cnt[c.charCodeAt(0) - 97] === 1) {
            ++need;
        }
    }
    const win: number[] = Array(26).fill(0);
    let [ans, l] = [0, 0];
    for (const c of word1) {
        const i = c.charCodeAt(0) - 97;
        if (++win[i] === cnt[i]) {
            --need;
        }
        while (need === 0) {
            const j = word1[l].charCodeAt(0) - 97;
            if (win[j] === cnt[j]) {
                ++need;
            }
            --win[j];
            ++l;
        }
        ans += l;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3298. 统计重新排列后包含另一个字符串的子字符串数目 II](https://leetcode.cn/problems/count-substrings-that-can-be-rearranged-to-contain-a-string-ii){#3298}

{{< tabs "3298" >}}

{{% tab "python" %}}
```python
class Solution:
    def validSubstringCount(self, word1: str, word2: str) -> int:
        if len(word1) < len(word2):
            return 0
        cnt = Counter(word2)
        need = len(cnt)
        ans = l = 0
        win = Counter()
        for c in word1:
            win[c] += 1
            if win[c] == cnt[c]:
                need -= 1
            while need == 0:
                if win[word1[l]] == cnt[word1[l]]:
                    need += 1
                win[word1[l]] -= 1
                l += 1
            ans += l
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long validSubstringCount(String word1, String word2) {
        if (word1.length() < word2.length()) {
            return 0;
        }
        int[] cnt = new int[26];
        int need = 0;
        for (int i = 0; i < word2.length(); ++i) {
            if (++cnt[word2.charAt(i) - 'a'] == 1) {
                ++need;
            }
        }
        long ans = 0;
        int[] win = new int[26];
        for (int l = 0, r = 0; r < word1.length(); ++r) {
            int c = word1.charAt(r) - 'a';
            if (++win[c] == cnt[c]) {
                --need;
            }
            while (need == 0) {
                c = word1.charAt(l) - 'a';
                if (win[c] == cnt[c]) {
                    ++need;
                }
                --win[c];
                ++l;
            }
            ans += l;
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
    long long validSubstringCount(string word1, string word2) {
        if (word1.size() < word2.size()) {
            return 0;
        }
        int cnt[26]{};
        int need = 0;
        for (char& c : word2) {
            if (++cnt[c - 'a'] == 1) {
                ++need;
            }
        }
        long long ans = 0;
        int win[26]{};
        int l = 0;
        for (char& c : word1) {
            int i = c - 'a';
            if (++win[i] == cnt[i]) {
                --need;
            }
            while (need == 0) {
                i = word1[l] - 'a';
                if (win[i] == cnt[i]) {
                    ++need;
                }
                --win[i];
                ++l;
            }
            ans += l;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func validSubstringCount(word1 string, word2 string) (ans int64) {
	if len(word1) < len(word2) {
		return 0
	}
	cnt := [26]int{}
	need := 0
	for _, c := range word2 {
		cnt[c-'a']++
		if cnt[c-'a'] == 1 {
			need++
		}
	}
	win := [26]int{}
	l := 0
	for _, c := range word1 {
		i := int(c - 'a')
		win[i]++
		if win[i] == cnt[i] {
			need--
		}
		for need == 0 {
			i = int(word1[l] - 'a')
			if win[i] == cnt[i] {
				need++
			}
			win[i]--
			l++
		}
		ans += int64(l)
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function validSubstringCount(word1: string, word2: string): number {
    if (word1.length < word2.length) {
        return 0;
    }
    const cnt: number[] = Array(26).fill(0);
    let need: number = 0;
    for (const c of word2) {
        if (++cnt[c.charCodeAt(0) - 97] === 1) {
            ++need;
        }
    }
    const win: number[] = Array(26).fill(0);
    let [ans, l] = [0, 0];
    for (const c of word1) {
        const i = c.charCodeAt(0) - 97;
        if (++win[i] === cnt[i]) {
            --need;
        }
        while (need === 0) {
            const j = word1[l].charCodeAt(0) - 97;
            if (win[j] === cnt[j]) {
                ++need;
            }
            --win[j];
            ++l;
        }
        ans += l;
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

<p>给你两个字符串&nbsp;<code>word1</code> 和&nbsp;<code>word2</code>&nbsp;。</p>

<p>如果一个字符串 <code>x</code>&nbsp;重新排列后，<code>word2</code>&nbsp;是重排字符串的&nbsp;<span data-keyword="string-prefix">前缀</span>&nbsp;，那么我们称字符串&nbsp;<code>x</code>&nbsp;是&nbsp;<strong>合法的</strong>&nbsp;。</p>

<p>请你返回 <code>word1</code>&nbsp;中 <strong>合法</strong>&nbsp;<span data-keyword="substring-nonempty">子字符串</span>&nbsp;的数目。</p>

<p><strong>注意</strong>&nbsp;，这个问题中的内存限制比其他题目要&nbsp;<strong>小</strong>&nbsp;，所以你&nbsp;<strong>必须</strong>&nbsp;实现一个线性复杂度的解法。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>word1 = "bcca", word2 = "abc"</span></p>

<p><span class="example-io"><b>输出：</b>1</span></p>

<p><strong>解释：</strong></p>

<p>唯一合法的子字符串是&nbsp;<code>"bcca"</code>&nbsp;，可以重新排列得到&nbsp;<code>"abcc"</code>&nbsp;，<code>"abc"</code>&nbsp;是它的前缀。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>word1 = "abcabc", word2 = "abc"</span></p>

<p><span class="example-io"><b>输出：</b>10</span></p>

<p><strong>解释：</strong></p>

<p>除了长度为 1 和 2 的所有子字符串都是合法的。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>word1 = "abcabc", word2 = "aaabc"</span></p>

<p><span class="example-io"><b>输出：</b>0</span></p>
</div>

<p>&nbsp;</p>

<p><strong>解释：</strong></p>

<ul>
	<li><code>1 &lt;= word1.length &lt;= 10<sup>6</sup></code></li>
	<li><code>1 &lt;= word2.length &lt;= 10<sup>4</sup></code></li>
	<li><code>word1</code> 和&nbsp;<code>word2</code>&nbsp;都只包含小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：滑动窗口

题目实际上是求在 $\textit{word1}$ 中，有多少个子串包含了 $\textit{word2}$ 中的所有字符。我们可以使用滑动窗口来处理。

首先，如果 $\textit{word1}$ 的长度小于 $\textit{word2}$ 的长度，那么 $\textit{word1}$ 中不可能包含 $\textit{word2}$ 的所有字符，直接返回 $0$。

接下来，我们用一个哈希表或长度为 $26$ 的数组 $\textit{cnt}$ 来统计 $\textit{word2}$ 中的字符出现的次数。然后，我们用 $\textit{need}$ 来记录还需要多少个字符才能满足条件，初始化为 $\textit{cnt}$ 的长度。

接着，我们用一个滑动窗口 $\textit{win}$ 来记录当前窗口中的字符出现的次数。我们用 $\textit{ans}$ 来记录满足条件的子串的个数，用 $\textit{l}$ 来记录窗口的左边界。

遍历 $\textit{word1}$ 中的每个字符，对于当前字符 $c$，我们将其加入到 $\textit{win}$ 中，如果 $\textit{win}[c]$ 的值等于 $\textit{cnt}[c]$，那么说明当前窗口中已经包含了 $\textit{word2}$ 中的所有字符之一，那么 $\textit{need}$ 减一。如果 $\textit{need}$ 等于 $0$，说明当前窗口中包含了 $\textit{word2}$ 中的所有字符，我们需要缩小窗口的左边界，直到 $\textit{need}$ 大于 $0$。具体地，如果 $\textit{win}[\textit{word1}[l]]$ 等于 $\textit{cnt}[\textit{word1}[l]]$，那么说明当前窗口中包含了 $\textit{word2}$ 中的所有字符之一，那么缩小窗口的左边界之后，就不满足条件了，所以 $\textit{need}$ 加一，同时 $\textit{win}[\textit{word1}[l]]$ 减一。然后，我们将 $\textit{l}$ 加一。此时窗口为 $[l, r]$，那么对于任意 $0 \leq l' \lt l$，$[l', r]$ 都是满足条件的子串，一共有 $l$ 个，我们累加到答案中。

遍历完 $\textit{word1}$ 中的所有字符之后，我们就得到了答案。

时间复杂度 $O(n + m)$，其中 $n$ 和 $m$ 分别是 $\textit{word1}$ 和 $\textit{word2}$ 的长度。空间复杂度 $O(|\Sigma|)$，其中 $\Sigma$ 是字符集，这里是小写字母集合，所以空间复杂度是常数级别的。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def validSubstringCount(self, word1: str, word2: str) -> int:
        if len(word1) < len(word2):
            return 0
        cnt = Counter(word2)
        need = len(cnt)
        ans = l = 0
        win = Counter()
        for c in word1:
            win[c] += 1
            if win[c] == cnt[c]:
                need -= 1
            while need == 0:
                if win[word1[l]] == cnt[word1[l]]:
                    need += 1
                win[word1[l]] -= 1
                l += 1
            ans += l
        return ans
```

#### Java

```java
class Solution {
    public long validSubstringCount(String word1, String word2) {
        if (word1.length() < word2.length()) {
            return 0;
        }
        int[] cnt = new int[26];
        int need = 0;
        for (int i = 0; i < word2.length(); ++i) {
            if (++cnt[word2.charAt(i) - 'a'] == 1) {
                ++need;
            }
        }
        long ans = 0;
        int[] win = new int[26];
        for (int l = 0, r = 0; r < word1.length(); ++r) {
            int c = word1.charAt(r) - 'a';
            if (++win[c] == cnt[c]) {
                --need;
            }
            while (need == 0) {
                c = word1.charAt(l) - 'a';
                if (win[c] == cnt[c]) {
                    ++need;
                }
                --win[c];
                ++l;
            }
            ans += l;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        if (word1.size() < word2.size()) {
            return 0;
        }
        int cnt[26]{};
        int need = 0;
        for (char& c : word2) {
            if (++cnt[c - 'a'] == 1) {
                ++need;
            }
        }
        long long ans = 0;
        int win[26]{};
        int l = 0;
        for (char& c : word1) {
            int i = c - 'a';
            if (++win[i] == cnt[i]) {
                --need;
            }
            while (need == 0) {
                i = word1[l] - 'a';
                if (win[i] == cnt[i]) {
                    ++need;
                }
                --win[i];
                ++l;
            }
            ans += l;
        }
        return ans;
    }
};
```

#### Go

```go
func validSubstringCount(word1 string, word2 string) (ans int64) {
	if len(word1) < len(word2) {
		return 0
	}
	cnt := [26]int{}
	need := 0
	for _, c := range word2 {
		cnt[c-'a']++
		if cnt[c-'a'] == 1 {
			need++
		}
	}
	win := [26]int{}
	l := 0
	for _, c := range word1 {
		i := int(c - 'a')
		win[i]++
		if win[i] == cnt[i] {
			need--
		}
		for need == 0 {
			i = int(word1[l] - 'a')
			if win[i] == cnt[i] {
				need++
			}
			win[i]--
			l++
		}
		ans += int64(l)
	}
	return
}
```

#### TypeScript

```ts
function validSubstringCount(word1: string, word2: string): number {
    if (word1.length < word2.length) {
        return 0;
    }
    const cnt: number[] = Array(26).fill(0);
    let need: number = 0;
    for (const c of word2) {
        if (++cnt[c.charCodeAt(0) - 97] === 1) {
            ++need;
        }
    }
    const win: number[] = Array(26).fill(0);
    let [ans, l] = [0, 0];
    for (const c of word1) {
        const i = c.charCodeAt(0) - 97;
        if (++win[i] === cnt[i]) {
            --need;
        }
        while (need === 0) {
            const j = word1[l].charCodeAt(0) - 97;
            if (win[j] === cnt[j]) {
                ++need;
            }
            --win[j];
            ++l;
        }
        ans += l;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3299. 连续子序列的和 🔒](https://leetcode.cn/problems/sum-of-consecutive-subsequences){#3299}

{{< tabs "3299" >}}

{{% tab "python" %}}
```python
class Solution:
    def getSum(self, nums: List[int]) -> int:
        def calc(nums: List[int]) -> int:
            n = len(nums)
            left = [0] * n
            right = [0] * n
            cnt = Counter()
            for i in range(1, n):
                cnt[nums[i - 1]] += 1 + cnt[nums[i - 1] - 1]
                left[i] = cnt[nums[i] - 1]
            cnt = Counter()
            for i in range(n - 2, -1, -1):
                cnt[nums[i + 1]] += 1 + cnt[nums[i + 1] + 1]
                right[i] = cnt[nums[i] + 1]
            return sum((l + r + l * r) * x for l, r, x in zip(left, right, nums)) % mod

        mod = 10**9 + 7
        x = calc(nums)
        nums.reverse()
        y = calc(nums)
        return (x + y + sum(nums)) % mod
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private final int mod = (int) 1e9 + 7;

    public int getSum(int[] nums) {
        long x = calc(nums);
        for (int i = 0, j = nums.length - 1; i < j; ++i, --j) {
            int t = nums[i];
            nums[i] = nums[j];
            nums[j] = t;
        }
        long y = calc(nums);
        long s = Arrays.stream(nums).asLongStream().sum();
        return (int) ((x + y + s) % mod);
    }

    private long calc(int[] nums) {
        int n = nums.length;
        long[] left = new long[n];
        long[] right = new long[n];
        Map<Integer, Long> cnt = new HashMap<>();
        for (int i = 1; i < n; ++i) {
            cnt.merge(nums[i - 1], 1 + cnt.getOrDefault(nums[i - 1] - 1, 0L), Long::sum);
            left[i] = cnt.getOrDefault(nums[i] - 1, 0L);
        }
        cnt.clear();
        for (int i = n - 2; i >= 0; --i) {
            cnt.merge(nums[i + 1], 1 + cnt.getOrDefault(nums[i + 1] + 1, 0L), Long::sum);
            right[i] = cnt.getOrDefault(nums[i] + 1, 0L);
        }
        long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = (ans + (left[i] + right[i] + left[i] * right[i] % mod) * nums[i] % mod) % mod;
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
    int getSum(vector<int>& nums) {
        using ll = long long;
        const int mod = 1e9 + 7;
        auto calc = [&](const vector<int>& nums) -> ll {
            int n = nums.size();
            vector<ll> left(n), right(n);
            unordered_map<int, ll> cnt;

            for (int i = 1; i < n; ++i) {
                cnt[nums[i - 1]] += 1 + cnt[nums[i - 1] - 1];
                left[i] = cnt[nums[i] - 1];
            }

            cnt.clear();

            for (int i = n - 2; i >= 0; --i) {
                cnt[nums[i + 1]] += 1 + cnt[nums[i + 1] + 1];
                right[i] = cnt[nums[i] + 1];
            }

            ll ans = 0;
            for (int i = 0; i < n; ++i) {
                ans = (ans + (left[i] + right[i] + left[i] * right[i] % mod) * nums[i] % mod) % mod;
            }
            return ans;
        };

        ll x = calc(nums);
        reverse(nums.begin(), nums.end());
        ll y = calc(nums);
        ll s = accumulate(nums.begin(), nums.end(), 0LL);
        return static_cast<int>((x + y + s) % mod);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func getSum(nums []int) int {
	const mod = 1e9 + 7

	calc := func(nums []int) int64 {
		n := len(nums)
		left := make([]int64, n)
		right := make([]int64, n)
		cnt := make(map[int]int64)

		for i := 1; i < n; i++ {
			cnt[nums[i-1]] += 1 + cnt[nums[i-1]-1]
			left[i] = cnt[nums[i]-1]
		}

		cnt = make(map[int]int64)

		for i := n - 2; i >= 0; i-- {
			cnt[nums[i+1]] += 1 + cnt[nums[i+1]+1]
			right[i] = cnt[nums[i]+1]
		}

		var ans int64
		for i, x := range nums {
			ans = (ans + (left[i]+right[i]+(left[i]*right[i]%mod))*int64(x)%mod) % mod
		}
		return ans
	}

	x := calc(nums)
	for i, j := 0, len(nums)-1; i < j; i, j = i+1, j-1 {
		nums[i], nums[j] = nums[j], nums[i]
	}
	y := calc(nums)
	s := int64(0)
	for _, num := range nums {
		s += int64(num)
	}
	return int((x + y + s) % mod)
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>如果一个长度为&nbsp;<code>n</code>&nbsp;的数组&nbsp;<code>arr</code>&nbsp;符合下面其中一个条件，可以称它 <strong>连续</strong>：</p>

<ul>
	<li>对于所有的&nbsp;<code>1 &lt;= i &lt; n</code>，<code>arr[i] - arr[i - 1] == 1</code>。</li>
	<li>对于所有的&nbsp;<code>1 &lt;= i &lt; n</code>，<code>arr[i] - arr[i - 1] == -1</code>。</li>
</ul>

<p>数组的 <strong>值</strong> 是其元素的和。</p>

<p>例如，<code>[3, 4, 5]</code>&nbsp;是一个值为 12 的连续数组，并且&nbsp;<code>[9, 8]</code>&nbsp;是另一个值为 17 的连续数组。而&nbsp;<code>[3, 4, 3]</code> 和&nbsp;<code>[8, 6]</code>&nbsp;都不连续。</p>

<p>给定一个整数数组&nbsp;<code>nums</code>，返回所有 <strong>连续</strong>&nbsp;非空&nbsp;<span data-keyword="subsequence-array">子序列</span>&nbsp;的 <strong>值</strong>&nbsp;之和。</p>

<p>由于答案可能很大，返回它对&nbsp;<code>10<sup>9 </sup>+ 7</code>&nbsp;<strong>取模</strong>&nbsp;的值。</p>

<p><strong>注意</strong>&nbsp;长度为 1 的数组也被认为是连续的。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">nums = [1,2]</span></p>

<p><strong>输出：</strong><span class="example-io">6</span></p>

<p><strong>解释：</strong></p>

<p>连续子序列为&nbsp;<code>[1]</code>，<code>[2]</code>，<code>[1, 2]</code>。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [1,4,2,3]</span></p>

<p><span class="example-io"><b>输出：</b>31</span></p>

<p><strong>解释：</strong></p>

<p>连续子序列为：<code>[1]</code>，<code>[4]</code>，<code>[2]</code>，<code>[3]</code>，<code>[1, 2]</code>，<code>[2, 3]</code>，<code>[4, 3]</code>，<code>[1, 2, 3]</code>。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举贡献

我们不妨统计每个元素 $\textit{nums}[i]$ 在多少个长度大于 $1$ 的连续子序列中出现，那么其个数乘以 $\textit{nums}[i]$ 就是 $\textit{nums}[i]$ 在所有长度大于 $1$ 的连续子序列中的贡献。我们将其累加，再加上所有元素的和，即为答案。

我们可以先统计连续递增子序列对答案的贡献，再统计连续递减子序列对答案的贡献，最后再加上所有元素的和即可。

在实现上，我们定义一个函数 $\textit{calc}(\textit{nums})$，其中 $\textit{nums}$ 是一个数组，返回 $\textit{nums}$ 所有长度大于 $1$ 的连续子序列的和。

在函数中，我们可以使用两个数组 $\textit{left}$ 和 $\textit{right}$ 分别记录每个元素 $\textit{nums}[i]$ 的左侧以 $\textit{nums}[i] - 1$ 结尾的连续递增子序列的个数，以及右侧以 $\textit{nums}[i] + 1$ 开头的连续递增子序列的个数。这样，我们就可以在 $O(n)$ 的时间复杂度内计算出 $\textit{nums}$ 在所有长度大于 $1$ 的连续子序列中的贡献。

在主函数中，我们首先调用 $\textit{calc}(\textit{nums})$ 计算出连续递增子序列对答案的贡献，然后将 $\textit{nums}$ 反转后再次调用 $\textit{calc}(\textit{nums})$ 计算出连续递减子序列对答案的贡献，最后再加上所有元素的和即为答案。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 $\textit{nums}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def getSum(self, nums: List[int]) -> int:
        def calc(nums: List[int]) -> int:
            n = len(nums)
            left = [0] * n
            right = [0] * n
            cnt = Counter()
            for i in range(1, n):
                cnt[nums[i - 1]] += 1 + cnt[nums[i - 1] - 1]
                left[i] = cnt[nums[i] - 1]
            cnt = Counter()
            for i in range(n - 2, -1, -1):
                cnt[nums[i + 1]] += 1 + cnt[nums[i + 1] + 1]
                right[i] = cnt[nums[i] + 1]
            return sum((l + r + l * r) * x for l, r, x in zip(left, right, nums)) % mod

        mod = 10**9 + 7
        x = calc(nums)
        nums.reverse()
        y = calc(nums)
        return (x + y + sum(nums)) % mod
```

#### Java

```java
class Solution {
    private final int mod = (int) 1e9 + 7;

    public int getSum(int[] nums) {
        long x = calc(nums);
        for (int i = 0, j = nums.length - 1; i < j; ++i, --j) {
            int t = nums[i];
            nums[i] = nums[j];
            nums[j] = t;
        }
        long y = calc(nums);
        long s = Arrays.stream(nums).asLongStream().sum();
        return (int) ((x + y + s) % mod);
    }

    private long calc(int[] nums) {
        int n = nums.length;
        long[] left = new long[n];
        long[] right = new long[n];
        Map<Integer, Long> cnt = new HashMap<>();
        for (int i = 1; i < n; ++i) {
            cnt.merge(nums[i - 1], 1 + cnt.getOrDefault(nums[i - 1] - 1, 0L), Long::sum);
            left[i] = cnt.getOrDefault(nums[i] - 1, 0L);
        }
        cnt.clear();
        for (int i = n - 2; i >= 0; --i) {
            cnt.merge(nums[i + 1], 1 + cnt.getOrDefault(nums[i + 1] + 1, 0L), Long::sum);
            right[i] = cnt.getOrDefault(nums[i] + 1, 0L);
        }
        long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = (ans + (left[i] + right[i] + left[i] * right[i] % mod) * nums[i] % mod) % mod;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int getSum(vector<int>& nums) {
        using ll = long long;
        const int mod = 1e9 + 7;
        auto calc = [&](const vector<int>& nums) -> ll {
            int n = nums.size();
            vector<ll> left(n), right(n);
            unordered_map<int, ll> cnt;

            for (int i = 1; i < n; ++i) {
                cnt[nums[i - 1]] += 1 + cnt[nums[i - 1] - 1];
                left[i] = cnt[nums[i] - 1];
            }

            cnt.clear();

            for (int i = n - 2; i >= 0; --i) {
                cnt[nums[i + 1]] += 1 + cnt[nums[i + 1] + 1];
                right[i] = cnt[nums[i] + 1];
            }

            ll ans = 0;
            for (int i = 0; i < n; ++i) {
                ans = (ans + (left[i] + right[i] + left[i] * right[i] % mod) * nums[i] % mod) % mod;
            }
            return ans;
        };

        ll x = calc(nums);
        reverse(nums.begin(), nums.end());
        ll y = calc(nums);
        ll s = accumulate(nums.begin(), nums.end(), 0LL);
        return static_cast<int>((x + y + s) % mod);
    }
};
```

#### Go

```go
func getSum(nums []int) int {
	const mod = 1e9 + 7

	calc := func(nums []int) int64 {
		n := len(nums)
		left := make([]int64, n)
		right := make([]int64, n)
		cnt := make(map[int]int64)

		for i := 1; i < n; i++ {
			cnt[nums[i-1]] += 1 + cnt[nums[i-1]-1]
			left[i] = cnt[nums[i]-1]
		}

		cnt = make(map[int]int64)

		for i := n - 2; i >= 0; i-- {
			cnt[nums[i+1]] += 1 + cnt[nums[i+1]+1]
			right[i] = cnt[nums[i]+1]
		}

		var ans int64
		for i, x := range nums {
			ans = (ans + (left[i]+right[i]+(left[i]*right[i]%mod))*int64(x)%mod) % mod
		}
		return ans
	}

	x := calc(nums)
	for i, j := 0, len(nums)-1; i < j; i, j = i+1, j-1 {
		nums[i], nums[j] = nums[j], nums[i]
	}
	y := calc(nums)
	s := int64(0)
	for _, num := range nums {
		s += int64(num)
	}
	return int((x + y + s) % mod)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
