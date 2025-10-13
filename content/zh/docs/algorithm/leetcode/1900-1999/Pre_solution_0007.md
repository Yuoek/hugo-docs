---
title: "1960_两个回文子字符串长度的最大乘积"
date: 2025-10-08T18:38:49+08:00
weight: 7
tags: [二分查找, 双指针, 哈希函数, 堆（优先队列）, 字符串, 排序, 数学, 数据库, 数组, 栈, 树状数组, 滚动哈希, 贪心, 递归]
---

{{< markmap >}}
### [1960_两个回文子字符串长度的最大乘积](#1960)
#### [字符串](#1960)
#### [哈希函数](#1960)
#### [滚动哈希](#1960)
### [1961_检查字符串是否为数组前缀](#1961)
#### [数组](#1961)
#### [双指针](#1961)
#### [字符串](#1961)
### [1962_移除石子使总数最小](#1962)
#### [贪心](#1962)
#### [数组](#1962)
#### [堆（优先队列）](#1962)
### [1963_使字符串平衡的最小交换次数](#1963)
#### [栈](#1963)
#### [贪心](#1963)
#### [双指针](#1963)
#### [字符串](#1963)
### [1964_找出到每个位置为止最长的有效障碍赛跑路线](#1964)
#### [树状数组](#1964)
#### [数组](#1964)
#### [二分查找](#1964)
### [1965_丢失信息的雇员](#1965)
#### [数据库](#1965)
### [1966_未排序数组中的可被二分搜索的数 🔒](#1966)
#### [数组](#1966)
#### [二分查找](#1966)
### [1967_作为子字符串出现在单词中的字符串数目](#1967)
#### [数组](#1967)
#### [字符串](#1967)
### [1968_构造元素不等于两相邻元素平均值的数组](#1968)
#### [贪心](#1968)
#### [数组](#1968)
#### [排序](#1968)
### [1969_数组元素的最小非零乘积](#1969)
#### [贪心](#1969)
#### [递归](#1969)
#### [数学](#1969)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1960_两个回文子字符串长度的最大乘积
___
#### 字符串
___
#### 哈希函数
___
#### 滚动哈希
---
### 1961_检查字符串是否为数组前缀
___
#### 数组
___
#### 双指针
___
#### 字符串
---
### 1962_移除石子使总数最小
___
#### 贪心
___
#### 数组
___
#### 堆（优先队列）
---
### 1963_使字符串平衡的最小交换次数
___
#### 栈
___
#### 贪心
___
#### 双指针
___
#### 字符串
---
### 1964_找出到每个位置为止最长的有效障碍赛跑路线
___
#### 树状数组
___
#### 数组
___
#### 二分查找
---
### 1965_丢失信息的雇员
___
#### 数据库
---
### 1966_未排序数组中的可被二分搜索的数 🔒
___
#### 数组
___
#### 二分查找
---
### 1967_作为子字符串出现在单词中的字符串数目
___
#### 数组
___
#### 字符串
---
### 1968_构造元素不等于两相邻元素平均值的数组
___
#### 贪心
___
#### 数组
___
#### 排序
---
### 1969_数组元素的最小非零乘积
___
#### 贪心
___
#### 递归
___
#### 数学
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 双指针 | 哈希函数 |
| 堆（优先队列） | 字符串 | 排序 |
| 数学 | 数据库 | 数组 |
| 栈 | 树状数组 | 滚动哈希 |
| 贪心 | 递归 |  |

# [1960. 两个回文子字符串长度的最大乘积](https://leetcode.cn/problems/maximum-product-of-the-length-of-two-palindromic-substrings){#1960}

{{< tabs "1960" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxProduct(self, s: str) -> int:
        n = len(s)
        hlen = [0] * n
        center = right = 0

        for i in range(n):
            if i < right:
                hlen[i] = min(right - i, hlen[2 * center - i])
            while (
                0 <= i - 1 - hlen[i]
                and i + 1 + hlen[i] < len(s)
                and s[i - 1 - hlen[i]] == s[i + 1 + hlen[i]]
            ):
                hlen[i] += 1
            if right < i + hlen[i]:
                center, right = i, i + hlen[i]

        prefix = [0] * n
        suffix = [0] * n

        for i in range(n):
            prefix[i + hlen[i]] = max(prefix[i + hlen[i]], 2 * hlen[i] + 1)
            suffix[i - hlen[i]] = max(suffix[i - hlen[i]], 2 * hlen[i] + 1)

        for i in range(1, n):
            prefix[~i] = max(prefix[~i], prefix[~i + 1] - 2)
            suffix[i] = max(suffix[i], suffix[i - 1] - 2)

        for i in range(1, n):
            prefix[i] = max(prefix[i - 1], prefix[i])
            suffix[~i] = max(suffix[~i], suffix[~i + 1])

        return max(prefix[i - 1] * suffix[i] for i in range(1, n))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long maxProduct(String s) {
        int n = s.length();
        if (n == 2) return 1;
        int[] len = manachers(s);
        long[] left = new long[n];
        int max = 1;
        left[0] = max;
        for (int i = 1; i <= n - 1; i++) {
            if (len[(i - max - 1 + i) / 2] > max) max += 2;
            left[i] = max;
        }
        max = 1;
        long[] right = new long[n];
        right[n - 1] = max;
        for (int i = n - 2; i >= 0; i--) {
            if (len[(i + max + 1 + i) / 2] > max) max += 2;
            right[i] = max;
        }
        long res = 1;
        for (int i = 1; i < n; i++) {
            res = Math.max(res, left[i - 1] * right[i]);
        }
        return res;
    }
    private int[] manachers(String s) {
        int len = s.length();
        int[] P = new int[len];
        int c = 0;
        int r = 0;
        for (int i = 0; i < len; i++) {
            int mirror = (2 * c) - i;
            if (i < r) {
                P[i] = Math.min(r - i, P[mirror]);
            }
            int a = i + (1 + P[i]);
            int b = i - (1 + P[i]);
            while (a < len && b >= 0 && s.charAt(a) == s.charAt(b)) {
                P[i]++;
                a++;
                b--;
            }
            if (i + P[i] > r) {
                c = i;
                r = i + P[i];
            }
        }
        for (int i = 0; i < len; i++) {
            P[i] = 1 + 2 * P[i];
        }
        return P;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    long long maxProduct(string s) {
        long long res = 0, l = 0, n = s.size();
        vector<int> m(n), r(n);

        for (int i = 0, l = 0, r = -1; i < n; ++i) {
            int k = (i > r) ? 1 : min(m[l + r - i], r - i + 1);
            while (0 <= i - k && i + k < n && s[i - k] == s[i + k])
                k++;
            m[i] = k--;
            if (i + k > r) {
                l = i - k;
                r = i + k;
            }
        }

        queue<array<int, 2>> q, q1;

        for (int i = n - 1; i >= 0; --i) {
            while (!q.empty() && q.front()[0] - q.front()[1] > i - 1)
                q.pop();
            r[i] = 1 + (q.empty() ? 0 : (q.front()[0] - i) * 2);
            q.push({i, m[i]});
        }

        for (int i = 0; i < n - 1; i++) {
            while (!q1.empty() && q1.front()[0] + q1.front()[1] < i + 1)
                q1.pop();
            l = max(l, 1ll + (q1.empty() ? 0 : (i - q1.front()[0]) * 2));
            res = max(res, l * r[i + 1]);
            q1.push({i, m[i]});
        }

        return res;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxProduct(s string) int64 {
	n := len(s)
	hlen := make([]int, n)
	center, right := 0, 0

	for i := 0; i < n; i++ {
		if i < right {
			mirror := 2*center - i
			if mirror >= 0 && mirror < n {
				hlen[i] = min(right-i, hlen[mirror])
			}
		}
		for i-1-hlen[i] >= 0 && i+1+hlen[i] < n && s[i-1-hlen[i]] == s[i+1+hlen[i]] {
			hlen[i]++
		}
		if i+hlen[i] > right {
			center = i
			right = i + hlen[i]
		}
	}

	prefix := make([]int, n)
	suffix := make([]int, n)

	for i := 0; i < n; i++ {
		r := i + hlen[i]
		if r < n {
			prefix[r] = max(prefix[r], 2*hlen[i]+1)
		}
		l := i - hlen[i]
		if l >= 0 {
			suffix[l] = max(suffix[l], 2*hlen[i]+1)
		}
	}

	for i := 1; i < n; i++ {
		if n-i-1 >= 0 {
			prefix[n-i-1] = max(prefix[n-i-1], prefix[n-i]-2)
		}
		suffix[i] = max(suffix[i], suffix[i-1]-2)
	}

	for i := 1; i < n; i++ {
		prefix[i] = max(prefix[i-1], prefix[i])
		suffix[n-i-1] = max(suffix[n-i], suffix[n-i-1])
	}

	var res int64
	for i := 1; i < n; i++ {
		prod := int64(prefix[i-1]) * int64(suffix[i])
		if prod > res {
			res = prod
		}
	}

	return res
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的字符串&nbsp;<code>s</code>&nbsp;，你需要找到两个 <strong>不重叠</strong><strong>的回文&nbsp;</strong>子字符串，它们的长度都必须为 <strong>奇数</strong>&nbsp;，使得它们长度的乘积最大。</p>

<p>更正式地，你想要选择四个整数&nbsp;<code>i</code>&nbsp;，<code>j</code>&nbsp;，<code>k</code>&nbsp;，<code>l</code>&nbsp;，使得&nbsp;<code>0 &lt;= i &lt;= j &lt; k &lt;= l &lt; s.length</code>&nbsp;，且子字符串&nbsp;<code>s[i...j]</code> 和&nbsp;<code>s[k...l]</code>&nbsp;都是回文串且长度为奇数。<code>s[i...j]</code>&nbsp;表示下标从 <code>i</code>&nbsp;到 <code>j</code>&nbsp;且 <strong>包含</strong>&nbsp;两端下标的子字符串。</p>

<p>请你返回两个不重叠回文子字符串长度的 <strong>最大</strong>&nbsp;乘积。</p>

<p><strong>回文字符串</strong>&nbsp;指的是一个从前往后读和从后往前读一模一样的字符串。<strong>子字符串</strong>&nbsp;指的是一个字符串中一段连续字符。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>s = "ababbb"
<b>输出：</b>9
<b>解释：</b>子字符串 "aba" 和 "bbb" 为奇数长度的回文串。乘积为 3 * 3 = 9 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>s = "zaaaxbbby"
<b>输出：</b>9
<b>解释：</b>子字符串 "aaa" 和 "bbb" 为奇数长度的回文串。乘积为 3 * 3 = 9 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code>&nbsp;只包含小写英文字母。</li>
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
    def maxProduct(self, s: str) -> int:
        n = len(s)
        hlen = [0] * n
        center = right = 0

        for i in range(n):
            if i < right:
                hlen[i] = min(right - i, hlen[2 * center - i])
            while (
                0 <= i - 1 - hlen[i]
                and i + 1 + hlen[i] < len(s)
                and s[i - 1 - hlen[i]] == s[i + 1 + hlen[i]]
            ):
                hlen[i] += 1
            if right < i + hlen[i]:
                center, right = i, i + hlen[i]

        prefix = [0] * n
        suffix = [0] * n

        for i in range(n):
            prefix[i + hlen[i]] = max(prefix[i + hlen[i]], 2 * hlen[i] + 1)
            suffix[i - hlen[i]] = max(suffix[i - hlen[i]], 2 * hlen[i] + 1)

        for i in range(1, n):
            prefix[~i] = max(prefix[~i], prefix[~i + 1] - 2)
            suffix[i] = max(suffix[i], suffix[i - 1] - 2)

        for i in range(1, n):
            prefix[i] = max(prefix[i - 1], prefix[i])
            suffix[~i] = max(suffix[~i], suffix[~i + 1])

        return max(prefix[i - 1] * suffix[i] for i in range(1, n))
```

#### Java

```java
class Solution {
    public long maxProduct(String s) {
        int n = s.length();
        if (n == 2) return 1;
        int[] len = manachers(s);
        long[] left = new long[n];
        int max = 1;
        left[0] = max;
        for (int i = 1; i <= n - 1; i++) {
            if (len[(i - max - 1 + i) / 2] > max) max += 2;
            left[i] = max;
        }
        max = 1;
        long[] right = new long[n];
        right[n - 1] = max;
        for (int i = n - 2; i >= 0; i--) {
            if (len[(i + max + 1 + i) / 2] > max) max += 2;
            right[i] = max;
        }
        long res = 1;
        for (int i = 1; i < n; i++) {
            res = Math.max(res, left[i - 1] * right[i]);
        }
        return res;
    }
    private int[] manachers(String s) {
        int len = s.length();
        int[] P = new int[len];
        int c = 0;
        int r = 0;
        for (int i = 0; i < len; i++) {
            int mirror = (2 * c) - i;
            if (i < r) {
                P[i] = Math.min(r - i, P[mirror]);
            }
            int a = i + (1 + P[i]);
            int b = i - (1 + P[i]);
            while (a < len && b >= 0 && s.charAt(a) == s.charAt(b)) {
                P[i]++;
                a++;
                b--;
            }
            if (i + P[i] > r) {
                c = i;
                r = i + P[i];
            }
        }
        for (int i = 0; i < len; i++) {
            P[i] = 1 + 2 * P[i];
        }
        return P;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long maxProduct(string s) {
        long long res = 0, l = 0, n = s.size();
        vector<int> m(n), r(n);

        for (int i = 0, l = 0, r = -1; i < n; ++i) {
            int k = (i > r) ? 1 : min(m[l + r - i], r - i + 1);
            while (0 <= i - k && i + k < n && s[i - k] == s[i + k])
                k++;
            m[i] = k--;
            if (i + k > r) {
                l = i - k;
                r = i + k;
            }
        }

        queue<array<int, 2>> q, q1;

        for (int i = n - 1; i >= 0; --i) {
            while (!q.empty() && q.front()[0] - q.front()[1] > i - 1)
                q.pop();
            r[i] = 1 + (q.empty() ? 0 : (q.front()[0] - i) * 2);
            q.push({i, m[i]});
        }

        for (int i = 0; i < n - 1; i++) {
            while (!q1.empty() && q1.front()[0] + q1.front()[1] < i + 1)
                q1.pop();
            l = max(l, 1ll + (q1.empty() ? 0 : (i - q1.front()[0]) * 2));
            res = max(res, l * r[i + 1]);
            q1.push({i, m[i]});
        }

        return res;
    }
};
```

#### Go

```go
func maxProduct(s string) int64 {
	n := len(s)
	hlen := make([]int, n)
	center, right := 0, 0

	for i := 0; i < n; i++ {
		if i < right {
			mirror := 2*center - i
			if mirror >= 0 && mirror < n {
				hlen[i] = min(right-i, hlen[mirror])
			}
		}
		for i-1-hlen[i] >= 0 && i+1+hlen[i] < n && s[i-1-hlen[i]] == s[i+1+hlen[i]] {
			hlen[i]++
		}
		if i+hlen[i] > right {
			center = i
			right = i + hlen[i]
		}
	}

	prefix := make([]int, n)
	suffix := make([]int, n)

	for i := 0; i < n; i++ {
		r := i + hlen[i]
		if r < n {
			prefix[r] = max(prefix[r], 2*hlen[i]+1)
		}
		l := i - hlen[i]
		if l >= 0 {
			suffix[l] = max(suffix[l], 2*hlen[i]+1)
		}
	}

	for i := 1; i < n; i++ {
		if n-i-1 >= 0 {
			prefix[n-i-1] = max(prefix[n-i-1], prefix[n-i]-2)
		}
		suffix[i] = max(suffix[i], suffix[i-1]-2)
	}

	for i := 1; i < n; i++ {
		prefix[i] = max(prefix[i-1], prefix[i])
		suffix[n-i-1] = max(suffix[n-i], suffix[n-i-1])
	}

	var res int64
	for i := 1; i < n; i++ {
		prod := int64(prefix[i-1]) * int64(suffix[i])
		if prod > res {
			res = prod
		}
	}

	return res
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1961. 检查字符串是否为数组前缀](https://leetcode.cn/problems/check-if-string-is-a-prefix-of-array){#1961}

{{< tabs "1961" >}}

{{% tab "python" %}}
```python
class Solution:
    def isPrefixString(self, s: str, words: List[str]) -> bool:
        n, m = len(s), 0
        for i, w in enumerate(words):
            m += len(w)
            if m == n:
                return "".join(words[: i + 1]) == s
        return False
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean isPrefixString(String s, String[] words) {
        StringBuilder t = new StringBuilder();
        for (var w : words) {
            t.append(w);
            if (t.length() > s.length()) {
                return false;
            }
            if (t.length() == s.length()) {
                return s.equals(t.toString());
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
    bool isPrefixString(string s, vector<string>& words) {
        string t;
        for (auto& w : words) {
            t += w;
            if (t.size() > s.size()) {
                return false;
            }
            if (t.size() == s.size()) {
                return t == s;
            }
        }
        return false;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func isPrefixString(s string, words []string) bool {
	t := strings.Builder{}
	for _, w := range words {
		t.WriteString(w)
		if t.Len() > len(s) {
			return false
		}
		if t.Len() == len(s) {
			return t.String() == s
		}
	}
	return false
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function isPrefixString(s: string, words: string[]): boolean {
    const t: string[] = [];
    const n = s.length;
    let m = 0;
    for (const w of words) {
        m += w.length;
        if (m > n) {
            return false;
        }
        t.push(w);
        if (m === n) {
            return s === t.join('');
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

<p>给你一个字符串 <code>s</code> 和一个字符串数组 <code>words</code> ，请你判断 <code>s</code> 是否为 <code>words</code> 的 <strong>前缀字符串</strong> 。</p>

<p>字符串 <code>s</code> 要成为 <code>words</code> 的 <strong>前缀字符串</strong> ，需要满足：<code>s</code> 可以由 <code>words</code> 中的前 <code>k</code>（<code>k</code> 为 <strong>正数</strong> ）个字符串按顺序相连得到，且 <code>k</code> 不超过 <code>words.length</code> 。</p>

<p>如果 <code>s</code> 是 <code>words</code> 的 <strong>前缀字符串</strong> ，返回 <code>true</code> ；否则，返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "iloveleetcode", words = ["i","love","leetcode","apples"]
<strong>输出：</strong>true
<strong>解释：</strong>
s 可以由 "i"、"love" 和 "leetcode" 相连得到。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "iloveleetcode", words = ["apples","i","love","leetcode"]
<strong>输出：</strong>false
<strong>解释：</strong>
数组的前缀相连无法得到 s 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 100</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 20</code></li>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>words[i]</code> 和 <code>s</code> 仅由小写英文字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：遍历

我们遍历数组 $words$，用一个变量 $t$ 记录当前已经拼接的字符串，如果 $t$ 的长度大于 $s$ 的长度，说明 $s$ 不是 $words$ 的前缀字符串，返回 $false$；如果 $t$ 的长度等于 $s$ 的长度，返回 $t$ 是否等于 $s$。

遍历结束后，如果 $t$ 的长度小于 $s$ 的长度，说明 $s$ 不是 $words$ 的前缀字符串，返回 $false$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是字符串 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def isPrefixString(self, s: str, words: List[str]) -> bool:
        n, m = len(s), 0
        for i, w in enumerate(words):
            m += len(w)
            if m == n:
                return "".join(words[: i + 1]) == s
        return False
```

#### Java

```java
class Solution {
    public boolean isPrefixString(String s, String[] words) {
        StringBuilder t = new StringBuilder();
        for (var w : words) {
            t.append(w);
            if (t.length() > s.length()) {
                return false;
            }
            if (t.length() == s.length()) {
                return s.equals(t.toString());
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
    bool isPrefixString(string s, vector<string>& words) {
        string t;
        for (auto& w : words) {
            t += w;
            if (t.size() > s.size()) {
                return false;
            }
            if (t.size() == s.size()) {
                return t == s;
            }
        }
        return false;
    }
};
```

#### Go

```go
func isPrefixString(s string, words []string) bool {
	t := strings.Builder{}
	for _, w := range words {
		t.WriteString(w)
		if t.Len() > len(s) {
			return false
		}
		if t.Len() == len(s) {
			return t.String() == s
		}
	}
	return false
}
```

#### TypeScript

```ts
function isPrefixString(s: string, words: string[]): boolean {
    const t: string[] = [];
    const n = s.length;
    let m = 0;
    for (const w of words) {
        m += w.length;
        if (m > n) {
            return false;
        }
        t.push(w);
        if (m === n) {
            return s === t.join('');
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

# [1962. 移除石子使总数最小](https://leetcode.cn/problems/remove-stones-to-minimize-the-total){#1962}

{{< tabs "1962" >}}

{{% tab "python" %}}
```python
class Solution:
    def minStoneSum(self, piles: List[int], k: int) -> int:
        pq = [-x for x in piles]
        heapify(pq)
        for _ in range(k):
            heapreplace(pq, pq[0] // 2)
        return -sum(pq)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minStoneSum(int[] piles, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> b - a);
        for (int x : piles) {
            pq.offer(x);
        }
        while (k-- > 0) {
            int x = pq.poll();
            pq.offer(x - x / 2);
        }
        int ans = 0;
        while (!pq.isEmpty()) {
            ans += pq.poll();
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
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        for (int x : piles) {
            pq.push(x);
        }
        while (k--) {
            int x = pq.top();
            pq.pop();
            pq.push(x - x / 2);
        }
        int ans = 0;
        while (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minStoneSum(piles []int, k int) (ans int) {
	pq := &hp{piles}
	heap.Init(pq)
	for ; k > 0; k-- {
		x := pq.pop()
		pq.push(x - x/2)
	}
	for pq.Len() > 0 {
		ans += pq.pop()
	}
	return
}

type hp struct{ sort.IntSlice }

func (h hp) Less(i, j int) bool { return h.IntSlice[i] > h.IntSlice[j] }
func (h *hp) Push(v any)        { h.IntSlice = append(h.IntSlice, v.(int)) }
func (h *hp) Pop() any {
	a := h.IntSlice
	v := a[len(a)-1]
	h.IntSlice = a[:len(a)-1]
	return v
}
func (h *hp) push(v int) { heap.Push(h, v) }
func (h *hp) pop() int   { return heap.Pop(h).(int) }
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minStoneSum(piles: number[], k: number): number {
    const pq = new MaxPriorityQueue<number>();
    for (const x of piles) {
        pq.enqueue(x);
    }
    while (k--) {
        pq.enqueue((pq.dequeue() + 1) >> 1);
    }
    return pq.toArray().reduce((a, b) => a + b, 0);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>piles</code> ，数组 <strong>下标从 0 开始</strong> ，其中 <code>piles[i]</code> 表示第 <code>i</code> 堆石子中的石子数量。另给你一个整数 <code>k</code> ，请你执行下述操作 <strong>恰好</strong> <code>k</code> 次：</p>

<ul>
	<li>选出任一石子堆 <code>piles[i]</code> ，并从中 <strong>移除</strong> <code>floor(piles[i] / 2)</code> 颗石子。</li>
</ul>

<p><strong>注意：</strong>你可以对 <strong>同一堆</strong> 石子多次执行此操作。</p>

<p>返回执行 <code>k</code> 次操作后，剩下石子的 <strong>最小</strong> 总数。</p>

<p><code>floor(x)</code> 为 <strong>小于</strong> 或 <strong>等于</strong> <code>x</code> 的 <strong>最大</strong>&nbsp;整数。（即，对 <code>x</code> 向下取整）。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>piles = [5,4,9], k = 2
<strong>输出：</strong>12
<strong>解释：</strong>可能的执行情景如下：
- 对第 2 堆石子执行移除操作，石子分布情况变成 [5,4,<strong><em>5</em></strong>] 。
- 对第 0 堆石子执行移除操作，石子分布情况变成 [<strong><em>3</em></strong>,4,5] 。
剩下石子的总数为 12 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>piles = [4,3,6,7], k = 3
<strong>输出：</strong>12
<strong>解释：</strong>可能的执行情景如下：
- 对第 2 堆石子执行移除操作，石子分布情况变成 [4,3,<strong><em>3</em></strong>,7] 。
- 对第 3 堆石子执行移除操作，石子分布情况变成 [4,3,3,<strong><em>4</em></strong>] 。
- 对第 0 堆石子执行移除操作，石子分布情况变成 [<strong><em>2</em></strong>,3,3,4] 。
剩下石子的总数为 12 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= piles.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= piles[i] &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 优先队列（大根堆）

根据题目描述，为了使得剩下的石子总数最小，我们需要尽可能多地移除石子堆中的石子。因此，每次应该选择数量最多的石子堆进行移除。

我们创建一个优先队列（大根堆） $pq$，用于存储石子堆的数量。初始时，将所有石子堆的数量加入优先队列。

接下来，我们进行 $k$ 次操作。在每一次操作中，我们取出优先队列的堆顶元素 $x$，将 $x$ 减半后重新加入优先队列。

在进行了 $k$ 次操作后，优先队列中所有元素的和即为答案。

时间复杂度 $O(n + k \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 `piles` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minStoneSum(self, piles: List[int], k: int) -> int:
        pq = [-x for x in piles]
        heapify(pq)
        for _ in range(k):
            heapreplace(pq, pq[0] // 2)
        return -sum(pq)
```

#### Java

```java
class Solution {
    public int minStoneSum(int[] piles, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> b - a);
        for (int x : piles) {
            pq.offer(x);
        }
        while (k-- > 0) {
            int x = pq.poll();
            pq.offer(x - x / 2);
        }
        int ans = 0;
        while (!pq.isEmpty()) {
            ans += pq.poll();
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        for (int x : piles) {
            pq.push(x);
        }
        while (k--) {
            int x = pq.top();
            pq.pop();
            pq.push(x - x / 2);
        }
        int ans = 0;
        while (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};
```

#### Go

```go
func minStoneSum(piles []int, k int) (ans int) {
	pq := &hp{piles}
	heap.Init(pq)
	for ; k > 0; k-- {
		x := pq.pop()
		pq.push(x - x/2)
	}
	for pq.Len() > 0 {
		ans += pq.pop()
	}
	return
}

type hp struct{ sort.IntSlice }

func (h hp) Less(i, j int) bool { return h.IntSlice[i] > h.IntSlice[j] }
func (h *hp) Push(v any)        { h.IntSlice = append(h.IntSlice, v.(int)) }
func (h *hp) Pop() any {
	a := h.IntSlice
	v := a[len(a)-1]
	h.IntSlice = a[:len(a)-1]
	return v
}
func (h *hp) push(v int) { heap.Push(h, v) }
func (h *hp) pop() int   { return heap.Pop(h).(int) }
```

#### TypeScript

```ts
function minStoneSum(piles: number[], k: number): number {
    const pq = new MaxPriorityQueue<number>();
    for (const x of piles) {
        pq.enqueue(x);
    }
    while (k--) {
        pq.enqueue((pq.dequeue() + 1) >> 1);
    }
    return pq.toArray().reduce((a, b) => a + b, 0);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1963. 使字符串平衡的最小交换次数](https://leetcode.cn/problems/minimum-number-of-swaps-to-make-the-string-balanced){#1963}

{{< tabs "1963" >}}

{{% tab "python" %}}
```python
class Solution:
    def minSwaps(self, s: str) -> int:
        x = 0
        for c in s:
            if c == "[":
                x += 1
            elif x:
                x -= 1
        return (x + 1) >> 1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minSwaps(String s) {
        int x = 0;
        for (int i = 0; i < s.length(); ++i) {
            char c = s.charAt(i);
            if (c == '[') {
                ++x;
            } else if (x > 0) {
                --x;
            }
        }
        return (x + 1) / 2;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minSwaps(string s) {
        int x = 0;
        for (char& c : s) {
            if (c == '[') {
                ++x;
            } else if (x) {
                --x;
            }
        }
        return (x + 1) / 2;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minSwaps(s string) int {
	x := 0
	for _, c := range s {
		if c == '[' {
			x++
		} else if x > 0 {
			x--
		}
	}
	return (x + 1) / 2
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minSwaps(s: string): number {
    let x = 0;
    for (const c of s) {
        if (c === '[') {
            ++x;
        } else if (x) {
            --x;
        }
    }
    return (x + 1) >> 1;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串 <code>s</code> ，<strong>下标从 0 开始</strong> ，且长度为偶数 <code>n</code> 。字符串 <strong>恰好</strong> 由 <code>n / 2</code> 个开括号 <code>'['</code> 和 <code>n / 2</code> 个闭括号 <code>']'</code> 组成。</p>

<p>只有能满足下述所有条件的字符串才能称为 <strong>平衡字符串</strong> ：</p>

<ul>
	<li>字符串是一个空字符串，或者</li>
	<li>字符串可以记作 <code>AB</code> ，其中 <code>A</code> 和 <code>B</code> 都是 <strong>平衡字符串</strong> ，或者</li>
	<li>字符串可以写成 <code>[C]</code> ，其中 <code>C</code> 是一个 <strong>平衡字符串</strong> 。</li>
</ul>

<p>你可以交换 <strong>任意</strong> 两个下标所对应的括号 <strong>任意</strong> 次数。</p>

<p>返回使<em> </em><code>s</code> 变成 <strong>平衡字符串</strong> 所需要的 <strong>最小</strong> 交换次数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "][]["
<strong>输出：</strong>1
<strong>解释：</strong>交换下标 0 和下标 3 对应的括号，可以使字符串变成平衡字符串。
最终字符串变成 "[[]]" 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "]]][[["
<strong>输出：</strong>2
<strong>解释：</strong>执行下述操作可以使字符串变成平衡字符串：
- 交换下标 0 和下标 4 对应的括号，s = "[]][][" 。
- 交换下标 1 和下标 5 对应的括号，s = "[[][]]" 。
最终字符串变成 "[[][]]" 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "[]"
<strong>输出：</strong>0
<strong>解释：</strong>这个字符串已经是平衡字符串。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == s.length</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>6</sup></code></li>
	<li><code>n</code> 为偶数</li>
	<li><code>s[i]</code> 为<code>'['</code> 或 <code>']'</code></li>
	<li>开括号 <code>'['</code> 的数目为 <code>n / 2</code> ，闭括号 <code>']'</code> 的数目也是 <code>n / 2</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心

我们用一个变量 $x$ 记录当前未匹配的左括号的数量，遍历字符串 $s$，对于每个字符 $c$：

-   如果 $c$ 是左括号，那么 $x$ 加一；
-   如果 $c$ 是右括号，那么我们需要判断 $x$ 是否大于零，如果大于零，那么将当前右括号与左侧最近的一个未匹配的左括号匹配，即 $x$ 减一。

遍历结束后，得到的一定是形如 `"]]]...[[[..."`的字符串，我们再贪心地每次将两端的括号交换，这样一次可以消去 $2$ 个不匹配的左括号。因此，一共需要交换的次数为 $\left\lfloor \frac{x + 1}{2} \right\rfloor$。

时间复杂度 $O(n)$，其中 $n$ 为字符串 $s$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minSwaps(self, s: str) -> int:
        x = 0
        for c in s:
            if c == "[":
                x += 1
            elif x:
                x -= 1
        return (x + 1) >> 1
```

#### Java

```java
class Solution {
    public int minSwaps(String s) {
        int x = 0;
        for (int i = 0; i < s.length(); ++i) {
            char c = s.charAt(i);
            if (c == '[') {
                ++x;
            } else if (x > 0) {
                --x;
            }
        }
        return (x + 1) / 2;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minSwaps(string s) {
        int x = 0;
        for (char& c : s) {
            if (c == '[') {
                ++x;
            } else if (x) {
                --x;
            }
        }
        return (x + 1) / 2;
    }
};
```

#### Go

```go
func minSwaps(s string) int {
	x := 0
	for _, c := range s {
		if c == '[' {
			x++
		} else if x > 0 {
			x--
		}
	}
	return (x + 1) / 2
}
```

#### TypeScript

```ts
function minSwaps(s: string): number {
    let x = 0;
    for (const c of s) {
        if (c === '[') {
            ++x;
        } else if (x) {
            --x;
        }
    }
    return (x + 1) >> 1;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1964. 找出到每个位置为止最长的有效障碍赛跑路线](https://leetcode.cn/problems/find-the-longest-valid-obstacle-course-at-each-position){#1964}

{{< tabs "1964" >}}

{{% tab "python" %}}
```python
class BinaryIndexedTree:
    __slots__ = ["n", "c"]

    def __init__(self, n: int):
        self.n = n
        self.c = [0] * (n + 1)

    def update(self, x: int, v: int):
        while x <= self.n:
            self.c[x] = max(self.c[x], v)
            x += x & -x

    def query(self, x: int) -> int:
        s = 0
        while x:
            s = max(s, self.c[x])
            x -= x & -x
        return s


class Solution:
    def longestObstacleCourseAtEachPosition(self, obstacles: List[int]) -> List[int]:
        nums = sorted(set(obstacles))
        n = len(nums)
        tree = BinaryIndexedTree(n)
        ans = []
        for x in obstacles:
            i = bisect_left(nums, x) + 1
            ans.append(tree.query(i) + 1)
            tree.update(i, ans[-1])
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class BinaryIndexedTree {
    private int n;
    private int[] c;

    public BinaryIndexedTree(int n) {
        this.n = n;
        c = new int[n + 1];
    }

    public void update(int x, int v) {
        while (x <= n) {
            c[x] = Math.max(c[x], v);
            x += x & -x;
        }
    }

    public int query(int x) {
        int s = 0;
        while (x > 0) {
            s = Math.max(s, c[x]);
            x -= x & -x;
        }
        return s;
    }
}

class Solution {
    public int[] longestObstacleCourseAtEachPosition(int[] obstacles) {
        int[] nums = obstacles.clone();
        Arrays.sort(nums);
        int n = nums.length;
        int[] ans = new int[n];
        BinaryIndexedTree tree = new BinaryIndexedTree(n);
        for (int k = 0; k < n; ++k) {
            int x = obstacles[k];
            int i = Arrays.binarySearch(nums, x) + 1;
            ans[k] = tree.query(i) + 1;
            tree.update(i, ans[k]);
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class BinaryIndexedTree {
private:
    int n;
    vector<int> c;

public:
    BinaryIndexedTree(int n) {
        this->n = n;
        c = vector<int>(n + 1);
    }

    void update(int x, int v) {
        while (x <= n) {
            c[x] = max(c[x], v);
            x += x & -x;
        }
    }

    int query(int x) {
        int s = 0;
        while (x > 0) {
            s = max(s, c[x]);
            x -= x & -x;
        }
        return s;
    }
};

class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> nums = obstacles;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> ans(n);
        BinaryIndexedTree tree(n);
        for (int k = 0; k < n; ++k) {
            int x = obstacles[k];
            auto it = lower_bound(nums.begin(), nums.end(), x);
            int i = distance(nums.begin(), it) + 1;
            ans[k] = tree.query(i) + 1;
            tree.update(i, ans[k]);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
type BinaryIndexedTree struct {
	n int
	c []int
}

func NewBinaryIndexedTree(n int) *BinaryIndexedTree {
	return &BinaryIndexedTree{n, make([]int, n+1)}
}

func (bit *BinaryIndexedTree) update(x, v int) {
	for x <= bit.n {
		bit.c[x] = max(bit.c[x], v)
		x += x & -x
	}
}

func (bit *BinaryIndexedTree) query(x int) (s int) {
	for x > 0 {
		s = max(s, bit.c[x])
		x -= x & -x
	}
	return
}

func longestObstacleCourseAtEachPosition(obstacles []int) (ans []int) {
	nums := slices.Clone(obstacles)
	sort.Ints(nums)
	n := len(nums)
	tree := NewBinaryIndexedTree(n)
	for k, x := range obstacles {
		i := sort.SearchInts(nums, x) + 1
		ans = append(ans, tree.query(i)+1)
		tree.update(i, ans[k])
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class BinaryIndexedTree {
    private n: number;
    private c: number[];

    constructor(n: number) {
        this.n = n;
        this.c = Array(n + 1).fill(0);
    }

    update(x: number, v: number): void {
        while (x <= this.n) {
            this.c[x] = Math.max(this.c[x], v);
            x += x & -x;
        }
    }

    query(x: number): number {
        let s = 0;
        while (x > 0) {
            s = Math.max(s, this.c[x]);
            x -= x & -x;
        }
        return s;
    }
}

function longestObstacleCourseAtEachPosition(obstacles: number[]): number[] {
    const nums: number[] = [...obstacles];
    nums.sort((a, b) => a - b);
    const n: number = nums.length;
    const ans: number[] = [];
    const tree: BinaryIndexedTree = new BinaryIndexedTree(n);
    const search = (x: number): number => {
        let [l, r] = [0, n];
        while (l < r) {
            const mid = (l + r) >> 1;
            if (nums[mid] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    };
    for (let k = 0; k < n; ++k) {
        const i: number = search(obstacles[k]) + 1;
        ans[k] = tree.query(i) + 1;
        tree.update(i, ans[k]);
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

<p>你打算构建一些障碍赛跑路线。给你一个 <strong>下标从 0 开始</strong> 的整数数组 <code>obstacles</code> ，数组长度为 <code>n</code> ，其中 <code>obstacles[i]</code> 表示第 <code>i</code> 个障碍的高度。</p>

<p>对于每个介于 <code>0</code> 和 <code>n - 1</code> 之间（包含 <code>0</code> 和 <code>n - 1</code>）的下标&nbsp; <code>i</code> ，在满足下述条件的前提下，请你找出&nbsp;<code>obstacles</code> 能构成的最长障碍路线的长度：</p>

<ul>
	<li>你可以选择下标介于 <code>0</code> 到 <code>i</code> 之间（包含 <code>0</code> 和 <code>i</code>）的任意个障碍。</li>
	<li>在这条路线中，必须包含第 <code>i</code> 个障碍。</li>
	<li>你必须按障碍在&nbsp;<code>obstacles</code>&nbsp;中的<strong> </strong><strong>出现顺序</strong> 布置这些障碍。</li>
	<li>除第一个障碍外，路线中每个障碍的高度都必须和前一个障碍 <strong>相同</strong> 或者 <strong>更高</strong> 。</li>
</ul>

<p>返回长度为 <code>n</code> 的答案数组 <code>ans</code> ，其中 <code>ans[i]</code> 是上面所述的下标 <code>i</code> 对应的最长障碍赛跑路线的长度。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>obstacles = [1,2,3,2]
<strong>输出：</strong>[1,2,3,3]
<strong>解释：</strong>每个位置的最长有效障碍路线是：
- i = 0: [<em><strong>1</strong></em>], [1] 长度为 1
- i = 1: [<em><strong>1</strong></em>,<em><strong>2</strong></em>], [1,2] 长度为 2
- i = 2: [<em><strong>1</strong></em>,<em><strong>2</strong></em>,<em><strong>3</strong></em>], [1,2,3] 长度为 3
- i = 3: [<em><strong>1</strong></em>,<em><strong>2</strong></em>,3,<em><strong>2</strong></em>], [1,2,2] 长度为 3
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>obstacles = [2,2,1]
<strong>输出：</strong>[1,2,1]
<strong>解释：</strong>每个位置的最长有效障碍路线是：
- i = 0: [<em><strong>2</strong></em>], [2] 长度为 1
- i = 1: [<em><strong>2</strong></em>,<em><strong>2</strong></em>], [2,2] 长度为 2
- i = 2: [2,2,<em><strong>1</strong></em>], [1] 长度为 1
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>obstacles = [3,1,5,6,4,2]
<strong>输出：</strong>[1,1,2,3,2,2]
<strong>解释：</strong>每个位置的最长有效障碍路线是：
- i = 0: [<em><strong>3</strong></em>], [3] 长度为 1
- i = 1: [3,<em><strong>1</strong></em>], [1] 长度为 1
- i = 2: [<em><strong>3</strong></em>,1,<em><strong>5</strong></em>], [3,5] 长度为 2, [1,5] 也是有效的障碍赛跑路线
- i = 3: [<em><strong>3</strong></em>,1,<em><strong>5</strong></em>,<em><strong>6</strong></em>], [3,5,6] 长度为 3, [1,5,6] 也是有效的障碍赛跑路线
- i = 4: [<em><strong>3</strong></em>,1,5,6,<em><strong>4</strong></em>], [3,4] 长度为 2, [1,4] 也是有效的障碍赛跑路线
- i = 5: [3,<em><strong>1</strong></em>,5,6,4,<em><strong>2</strong></em>], [1,2] 长度为 2
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == obstacles.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= obstacles[i] &lt;= 10<sup>7</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：树状数组

我们可以用树状数组维护一个最长递增子序列的长度数组。

然后对于每个障碍，我们在树状数组中查询小于等于当前障碍的最长递增子序列的长度，假设为 $l$，那么当前障碍的最长递增子序列的长度为 $l+1$，我们将 $l+1$ 添加到答案数组中，并将 $l+1$ 更新到树状数组。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为障碍的数量。

<!-- tabs:start -->

#### Python3

```python
class BinaryIndexedTree:
    __slots__ = ["n", "c"]

    def __init__(self, n: int):
        self.n = n
        self.c = [0] * (n + 1)

    def update(self, x: int, v: int):
        while x <= self.n:
            self.c[x] = max(self.c[x], v)
            x += x & -x

    def query(self, x: int) -> int:
        s = 0
        while x:
            s = max(s, self.c[x])
            x -= x & -x
        return s


class Solution:
    def longestObstacleCourseAtEachPosition(self, obstacles: List[int]) -> List[int]:
        nums = sorted(set(obstacles))
        n = len(nums)
        tree = BinaryIndexedTree(n)
        ans = []
        for x in obstacles:
            i = bisect_left(nums, x) + 1
            ans.append(tree.query(i) + 1)
            tree.update(i, ans[-1])
        return ans
```

#### Java

```java
class BinaryIndexedTree {
    private int n;
    private int[] c;

    public BinaryIndexedTree(int n) {
        this.n = n;
        c = new int[n + 1];
    }

    public void update(int x, int v) {
        while (x <= n) {
            c[x] = Math.max(c[x], v);
            x += x & -x;
        }
    }

    public int query(int x) {
        int s = 0;
        while (x > 0) {
            s = Math.max(s, c[x]);
            x -= x & -x;
        }
        return s;
    }
}

class Solution {
    public int[] longestObstacleCourseAtEachPosition(int[] obstacles) {
        int[] nums = obstacles.clone();
        Arrays.sort(nums);
        int n = nums.length;
        int[] ans = new int[n];
        BinaryIndexedTree tree = new BinaryIndexedTree(n);
        for (int k = 0; k < n; ++k) {
            int x = obstacles[k];
            int i = Arrays.binarySearch(nums, x) + 1;
            ans[k] = tree.query(i) + 1;
            tree.update(i, ans[k]);
        }
        return ans;
    }
}
```

#### C++

```cpp
class BinaryIndexedTree {
private:
    int n;
    vector<int> c;

public:
    BinaryIndexedTree(int n) {
        this->n = n;
        c = vector<int>(n + 1);
    }

    void update(int x, int v) {
        while (x <= n) {
            c[x] = max(c[x], v);
            x += x & -x;
        }
    }

    int query(int x) {
        int s = 0;
        while (x > 0) {
            s = max(s, c[x]);
            x -= x & -x;
        }
        return s;
    }
};

class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> nums = obstacles;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> ans(n);
        BinaryIndexedTree tree(n);
        for (int k = 0; k < n; ++k) {
            int x = obstacles[k];
            auto it = lower_bound(nums.begin(), nums.end(), x);
            int i = distance(nums.begin(), it) + 1;
            ans[k] = tree.query(i) + 1;
            tree.update(i, ans[k]);
        }
        return ans;
    }
};
```

#### Go

```go
type BinaryIndexedTree struct {
	n int
	c []int
}

func NewBinaryIndexedTree(n int) *BinaryIndexedTree {
	return &BinaryIndexedTree{n, make([]int, n+1)}
}

func (bit *BinaryIndexedTree) update(x, v int) {
	for x <= bit.n {
		bit.c[x] = max(bit.c[x], v)
		x += x & -x
	}
}

func (bit *BinaryIndexedTree) query(x int) (s int) {
	for x > 0 {
		s = max(s, bit.c[x])
		x -= x & -x
	}
	return
}

func longestObstacleCourseAtEachPosition(obstacles []int) (ans []int) {
	nums := slices.Clone(obstacles)
	sort.Ints(nums)
	n := len(nums)
	tree := NewBinaryIndexedTree(n)
	for k, x := range obstacles {
		i := sort.SearchInts(nums, x) + 1
		ans = append(ans, tree.query(i)+1)
		tree.update(i, ans[k])
	}
	return
}
```

#### TypeScript

```ts
class BinaryIndexedTree {
    private n: number;
    private c: number[];

    constructor(n: number) {
        this.n = n;
        this.c = Array(n + 1).fill(0);
    }

    update(x: number, v: number): void {
        while (x <= this.n) {
            this.c[x] = Math.max(this.c[x], v);
            x += x & -x;
        }
    }

    query(x: number): number {
        let s = 0;
        while (x > 0) {
            s = Math.max(s, this.c[x]);
            x -= x & -x;
        }
        return s;
    }
}

function longestObstacleCourseAtEachPosition(obstacles: number[]): number[] {
    const nums: number[] = [...obstacles];
    nums.sort((a, b) => a - b);
    const n: number = nums.length;
    const ans: number[] = [];
    const tree: BinaryIndexedTree = new BinaryIndexedTree(n);
    const search = (x: number): number => {
        let [l, r] = [0, n];
        while (l < r) {
            const mid = (l + r) >> 1;
            if (nums[mid] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    };
    for (let k = 0; k < n; ++k) {
        const i: number = search(obstacles[k]) + 1;
        ans[k] = tree.query(i) + 1;
        tree.update(i, ans[k]);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1965. 丢失信息的雇员](https://leetcode.cn/problems/employees-with-missing-information){#1965}

{{< tabs "1965" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT employee_id
FROM Employees
WHERE employee_id NOT IN (SELECT employee_id FROM Salaries)
UNION
SELECT employee_id
FROM Salaries
WHERE employee_id NOT IN (SELECT employee_id FROM Employees)
ORDER BY 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表: <code>Employees</code></p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| employee_id | int     |
| name        | varchar |
+-------------+---------+
employee_id 是该表中具有唯一值的列。
每一行表示雇员的 id 和他的姓名。
</pre>

<p>表: <code>Salaries</code></p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| employee_id | int     |
| salary      | int     |
+-------------+---------+
employee_id 是该表中具有唯一值的列。
每一行表示雇员的 id 和他的薪水。
</pre>

<p>&nbsp;</p>

<p>编写解决方案，找到所有 <strong>丢失信息</strong> 的雇员 id。当满足下面一个条件时，就被认为是雇员的信息丢失：</p>

<ul>
	<li>雇员的 <strong>姓名</strong> 丢失了，或者</li>
	<li>雇员的 <strong>薪水信息</strong> 丢失了</li>
</ul>

<p>返回这些雇员的 id &nbsp;<code>employee_id</code>&nbsp;，&nbsp;<strong>从小到大排序&nbsp;</strong>。</p>

<p>查询结果格式如下面的例子所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
Employees table:
+-------------+----------+
| employee_id | name     |
+-------------+----------+
| 2           | Crew     |
| 4           | Haven    |
| 5           | Kristian |
+-------------+----------+
Salaries table:
+-------------+--------+
| employee_id | salary |
+-------------+--------+
| 5           | 76071  |
| 1           | 22517  |
| 4           | 63539  |
+-------------+--------+
<strong>输出：</strong>
+-------------+
| employee_id |
+-------------+
| 1           |
| 2           |
+-------------+
<strong>解释：</strong>
雇员 1，2，4，5 都在这个公司工作。
1 号雇员的姓名丢失了。
2 号雇员的薪水信息丢失了。</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：子查询 + 合并

我们可以先从 `Employees` 表中找出所有不在 `Salaries` 表中的 `employee_id`，再从 `Salaries` 表中找出所有不在 `Employees` 表中的 `employee_id`，最后将两个结果合并，然后按照 `employee_id` 排序即可。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT employee_id
FROM Employees
WHERE employee_id NOT IN (SELECT employee_id FROM Salaries)
UNION
SELECT employee_id
FROM Salaries
WHERE employee_id NOT IN (SELECT employee_id FROM Employees)
ORDER BY 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1966. 未排序数组中的可被二分搜索的数 🔒](https://leetcode.cn/problems/binary-searchable-numbers-in-an-unsorted-array){#1966}

{{< tabs "1966" >}}

{{% tab "python" %}}
```python
class Solution:
    def binarySearchableNumbers(self, nums: List[int]) -> int:
        n = len(nums)
        ok = [1] * n
        mx, mi = -1000000, 1000000
        for i, x in enumerate(nums):
            if x < mx:
                ok[i] = 0
            else:
                mx = x
        for i in range(n - 1, -1, -1):
            if nums[i] > mi:
                ok[i] = 0
            else:
                mi = nums[i]
        return sum(ok)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int binarySearchableNumbers(int[] nums) {
        int n = nums.length;
        int[] ok = new int[n];
        Arrays.fill(ok, 1);
        int mx = -1000000, mi = 1000000;
        for (int i = 0; i < n; ++i) {
            if (nums[i] < mx) {
                ok[i] = 0;
            }
            mx = Math.max(mx, nums[i]);
        }
        int ans = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (nums[i] > mi) {
                ok[i] = 0;
            }
            mi = Math.min(mi, nums[i]);
            ans += ok[i];
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
    int binarySearchableNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> ok(n, 1);
        int mx = -1000000, mi = 1000000;
        for (int i = 0; i < n; ++i) {
            if (nums[i] < mx) {
                ok[i] = 0;
            }
            mx = max(mx, nums[i]);
        }
        int ans = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (nums[i] > mi) {
                ok[i] = 0;
            }
            mi = min(mi, nums[i]);
            ans += ok[i];
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func binarySearchableNumbers(nums []int) (ans int) {
	n := len(nums)
	ok := make([]int, n)
	for i := range ok {
		ok[i] = 1
	}
	mx, mi := -1000000, 1000000
	for i, x := range nums {
		if x < mx {
			ok[i] = 0
		} else {
			mx = x
		}
	}
	for i := n - 1; i >= 0; i-- {
		if nums[i] > mi {
			ok[i] = 0
		} else {
			mi = nums[i]
		}
		ans += ok[i]
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

<p>有一个 <strong>类似</strong> <a href="https://leetcode.com/explore/learn/card/binary-search/" target="_blank">二分搜索</a>的方法。 这个方法有两个入参: <code>sequence</code> 是一个整数数组， <code>target</code> 是一个整数。 这个方法可以判断 <code>target</code> 是否存在 <code>sequence</code>中。</p>

<p>该方法的伪代码如下：</p>

<pre>
func(sequence, target)
  while sequence is not empty
    <strong>randomly</strong> choose an element from sequence as the pivot
    if pivot = target, return <strong>true</strong>
    else if pivot &lt; target, remove pivot and all elements to its left from the sequence
    else, remove pivot and all elements to its right from the sequence
  end while
  return <strong>false</strong></pre>

<p>当 <code>sequence</code> 是排好序时, 这个方法对 <strong>所有</strong> 值都可正常判断。如果&nbsp;<code>sequence</code>&nbsp;不是排好序的, 该方法并不是对所有值都可正常判断, 但对<strong>一些</strong> 值仍可正常判断。</p>

<p>给定一个仅包含<strong>不同</strong>数字的数组 <code>nums</code>表示 <code>sequence</code>， nums<strong>是否排序未知</strong>，对于 <strong>所有可能</strong>的选择, 返回通过这个方法<b>保证</b>能找到的值的数量。</p>

<p>&nbsp;</p>

<p><strong>示例&nbsp;1:</strong></p>

<pre>
<strong>输入:</strong> nums = [7]
<strong>输出:</strong> 1
<strong>解释</strong>: 
7 保证能被找到.
因为数组中只有一个数字, 7 一定会被选中. 因为选中的值等于target, 这个方法会返回 true.
</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre>
<strong>输入:</strong> nums = [-1,5,2]
<strong>输出:</strong> 1
<strong>解释</strong>: 
只有 -1 保证能被找到.
如果 -1 被选中, 这个方法就会返回 true.
如果 5 被选中, 5 和 2 会被移除。 在下一次循环时, 这个序列只有一个元素： -1 ，这个方法就会返回 true.
如果 2 被选中, 2 将会被移除。 在下次循环时, 这个序列里将会有 -1 和 5. 无论哪个数字被选中, 这个方法都会找到 -1 且返回 true.

5 不能保证被找到。
如果 2 被选中, -1, 5 和 2 将会被移除。 这个序列将会被清空且这个方法会返回 false。

2 不能保证被找到.
如果 5 被选中, 5 和 2 将会被移除。在下次循环时, 这个序列只会有一个元素： -1 且这个方法会返回 false。

因为只有-1 是保证能被找到的, 你应该返回 1.
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>5</sup> &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>nums</code>&nbsp;中所有值都&nbsp;<b>不同</b>.</li>
</ul>

<p>&nbsp;</p>

<p><strong>提升:</strong>&nbsp;如果&nbsp;<code>nums</code> 存在&nbsp;<strong>重复的值</strong>, 你会如何修改你的算法吗?&nbsp;</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：维护前缀最大值和后缀最小值

我们注意到，对于数组中的每个元素，如果它是可被二分搜索的，那么需要满足两个条件：

1. 这个元素大于它的左边所有元素，否则，如果左边存在比当前元素大的元素，那么就会被移除，导致无法找到当前元素；
2. 这个元素小于它的右边所有元素，否则，如果右边存在比当前元素小的元素，那么就会被移除，导致无法找到当前元素。

我们创建一个数组 $ok$，其中 $ok[i]$ 表示 $nums[i]$ 是否是可被二分搜索的。初始时 $ok[i]$ 都为 $1$。

我们先从左到右遍历数组，维护前缀最大值 $mx$，如果当前元素 $x$ 比 $mx$ 小，那么 $x$ 就不是可被二分搜索的，我们将 $ok[i]$ 置为 $0$，否则，我们将 $mx$ 更新为 $x$。

然后我们从右到左遍历数组，维护后缀最小值 $mi$，如果当前元素 $x$ 比 $mi$ 大，那么 $x$ 就不是可被二分搜索的，我们将 $ok[i]$ 置为 $0$，否则，我们将 $mi$ 更新为 $x$。

最后我们统计 $ok$ 中的 $1$ 的个数，即为可被二分搜索的元素的个数。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def binarySearchableNumbers(self, nums: List[int]) -> int:
        n = len(nums)
        ok = [1] * n
        mx, mi = -1000000, 1000000
        for i, x in enumerate(nums):
            if x < mx:
                ok[i] = 0
            else:
                mx = x
        for i in range(n - 1, -1, -1):
            if nums[i] > mi:
                ok[i] = 0
            else:
                mi = nums[i]
        return sum(ok)
```

#### Java

```java
class Solution {
    public int binarySearchableNumbers(int[] nums) {
        int n = nums.length;
        int[] ok = new int[n];
        Arrays.fill(ok, 1);
        int mx = -1000000, mi = 1000000;
        for (int i = 0; i < n; ++i) {
            if (nums[i] < mx) {
                ok[i] = 0;
            }
            mx = Math.max(mx, nums[i]);
        }
        int ans = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (nums[i] > mi) {
                ok[i] = 0;
            }
            mi = Math.min(mi, nums[i]);
            ans += ok[i];
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int binarySearchableNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> ok(n, 1);
        int mx = -1000000, mi = 1000000;
        for (int i = 0; i < n; ++i) {
            if (nums[i] < mx) {
                ok[i] = 0;
            }
            mx = max(mx, nums[i]);
        }
        int ans = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (nums[i] > mi) {
                ok[i] = 0;
            }
            mi = min(mi, nums[i]);
            ans += ok[i];
        }
        return ans;
    }
};
```

#### Go

```go
func binarySearchableNumbers(nums []int) (ans int) {
	n := len(nums)
	ok := make([]int, n)
	for i := range ok {
		ok[i] = 1
	}
	mx, mi := -1000000, 1000000
	for i, x := range nums {
		if x < mx {
			ok[i] = 0
		} else {
			mx = x
		}
	}
	for i := n - 1; i >= 0; i-- {
		if nums[i] > mi {
			ok[i] = 0
		} else {
			mi = nums[i]
		}
		ans += ok[i]
	}
	return
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1967. 作为子字符串出现在单词中的字符串数目](https://leetcode.cn/problems/number-of-strings-that-appear-as-substrings-in-word){#1967}

{{< tabs "1967" >}}

{{% tab "python" %}}
```python
class Solution:
    def numOfStrings(self, patterns: List[str], word: str) -> int:
        return sum(p in word for p in patterns)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numOfStrings(String[] patterns, String word) {
        int ans = 0;
        for (String p : patterns) {
            if (word.contains(p)) {
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
    int numOfStrings(vector<string>& patterns, string word) {
        int ans = 0;
        for (auto& p : patterns) {
            ans += word.find(p) != string::npos;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numOfStrings(patterns []string, word string) (ans int) {
	for _, p := range patterns {
		if strings.Contains(word, p) {
			ans++
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numOfStrings(patterns: string[], word: string): number {
    return patterns.filter(p => word.includes(p)).length;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn num_of_strings(patterns: Vec<String>, word: String) -> i32 {
        patterns.iter().filter(|p| word.contains(&**p)).count() as i32
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串数组 <code>patterns</code> 和一个字符串 <code>word</code> ，统计 <code>patterns</code> 中有多少个字符串是 <code>word</code> 的子字符串。返回字符串数目。</p>

<p><strong>子字符串</strong> 是字符串中的一个连续字符序列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>patterns = ["a","abc","bc","d"], word = "abc"
<strong>输出：</strong>3
<strong>解释：</strong>
- "a" 是 "<em><strong>a</strong></em>bc" 的子字符串。
- "abc" 是 "<em><strong>abc</strong></em>" 的子字符串。
- "bc" 是 "a<em><strong>bc</strong></em>" 的子字符串。
- "d" 不是 "abc" 的子字符串。
patterns 中有 3 个字符串作为子字符串出现在 word 中。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>patterns = ["a","b","c"], word = "aaaaabbbbb"
<strong>输出：</strong>2
<strong>解释：</strong>
- "a" 是 "a<em><strong>a</strong></em>aaabbbbb" 的子字符串。
- "b" 是 "aaaaabbbb<em><strong>b</strong></em>" 的子字符串。
- "c" 不是 "aaaaabbbbb" 的字符串。
patterns 中有 2 个字符串作为子字符串出现在 word 中。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>patterns = ["a","a","a"], word = "ab"
<strong>输出：</strong>3
<strong>解释：</strong>patterns 中的每个字符串都作为子字符串出现在 word "<em><strong>a</strong></em>b" 中。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= patterns.length &lt;= 100</code></li>
	<li><code>1 &lt;= patterns[i].length &lt;= 100</code></li>
	<li><code>1 &lt;= word.length &lt;= 100</code></li>
	<li><code>patterns[i]</code> 和 <code>word</code> 由小写英文字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

遍历字符串数组 $\textit{patterns}$ 中的每个字符串 $p$，判断其是否为 $\textit{word}$ 的子字符串，如果是，答案加一。

遍历结束后，返回答案。

时间复杂度 $O(n \times m)$，空间复杂度 $O(1)$。其中 $n$ 和 $m$ 分别为 $\textit{patterns}$ 和 $\textit{word}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numOfStrings(self, patterns: List[str], word: str) -> int:
        return sum(p in word for p in patterns)
```

#### Java

```java
class Solution {
    public int numOfStrings(String[] patterns, String word) {
        int ans = 0;
        for (String p : patterns) {
            if (word.contains(p)) {
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
    int numOfStrings(vector<string>& patterns, string word) {
        int ans = 0;
        for (auto& p : patterns) {
            ans += word.find(p) != string::npos;
        }
        return ans;
    }
};
```

#### Go

```go
func numOfStrings(patterns []string, word string) (ans int) {
	for _, p := range patterns {
		if strings.Contains(word, p) {
			ans++
		}
	}
	return
}
```

#### TypeScript

```ts
function numOfStrings(patterns: string[], word: string): number {
    return patterns.filter(p => word.includes(p)).length;
}
```

#### Rust

```rust
impl Solution {
    pub fn num_of_strings(patterns: Vec<String>, word: String) -> i32 {
        patterns.iter().filter(|p| word.contains(&**p)).count() as i32
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1968. 构造元素不等于两相邻元素平均值的数组](https://leetcode.cn/problems/array-with-elements-not-equal-to-average-of-neighbors){#1968}

{{< tabs "1968" >}}

{{% tab "python" %}}
```python
class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        nums.sort()
        n = len(nums)
        m = (n + 1) // 2
        ans = []
        for i in range(m):
            ans.append(nums[i])
            if i + m < n:
                ans.append(nums[i + m])
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] rearrangeArray(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        int m = (n + 1) >> 1;
        int[] ans = new int[n];
        for (int i = 0, j = 0; i < n; i += 2, j++) {
            ans[i] = nums[j];
            if (j + m < n) {
                ans[i + 1] = nums[j + m];
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
    vector<int> rearrangeArray(vector<int>& nums) {
        ranges::sort(nums);
        vector<int> ans;
        int n = nums.size();
        int m = (n + 1) >> 1;
        for (int i = 0; i < m; ++i) {
            ans.push_back(nums[i]);
            if (i + m < n) {
                ans.push_back(nums[i + m]);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func rearrangeArray(nums []int) (ans []int) {
	sort.Ints(nums)
	n := len(nums)
	m := (n + 1) >> 1
	for i := 0; i < m; i++ {
		ans = append(ans, nums[i])
		if i+m < n {
			ans = append(ans, nums[i+m])
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function rearrangeArray(nums: number[]): number[] {
    nums.sort((a, b) => a - b);
    const n = nums.length;
    const m = (n + 1) >> 1;
    const ans: number[] = [];
    for (let i = 0; i < m; i++) {
        ans.push(nums[i]);
        if (i + m < n) {
            ans.push(nums[i + m]);
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

<p>给你一个 <strong>下标从 0 开始</strong> 的数组 <code>nums</code> ，数组由若干 <strong>互不相同的</strong> 整数组成。你打算重新排列数组中的元素以满足：重排后，数组中的每个元素都 <strong>不等于</strong> 其两侧相邻元素的 <strong>平均值</strong> 。</p>

<p>更公式化的说法是，重新排列的数组应当满足这一属性：对于范围&nbsp;<code>1 &lt;= i &lt; nums.length - 1</code> 中的每个 <code>i</code> ，<code>(nums[i-1] + nums[i+1]) / 2</code> <strong>不等于</strong> <code>nums[i]</code> 均成立 。</p>

<p>返回满足题意的任一重排结果。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [1,2,3,4,5]
<strong>输出：</strong>[1,2,4,5,3]
<strong>解释：</strong>
i=1, nums[i] = 2, 两相邻元素平均值为 (1+4) / 2 = 2.5
i=2, nums[i] = 4, 两相邻元素平均值为 (2+5) / 2 = 3.5
i=3, nums[i] = 5, 两相邻元素平均值为 (4+3) / 2 = 3.5
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [6,2,0,9,7]
<strong>输出：</strong>[9,7,6,2,0]
<strong>解释：</strong>
i=1, nums[i] = 7, 两相邻元素平均值为 (9+6) / 2 = 7.5
i=2, nums[i] = 6, 两相邻元素平均值为 (7+2) / 2 = 4.5
i=3, nums[i] = 2, 两相邻元素平均值为 (6+0) / 2 = 3
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序

由于数组中的元素是互不相同的，我们可以先对数组进行排序，然后将数组分成两部分，将前一半的元素放到答案数组中的偶数位置，将后一半的元素放到答案数组中的奇数位置。这样，对于每个元素，它的两个相邻元素都不会等于它的平均值。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 $\textit{nums}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        nums.sort()
        n = len(nums)
        m = (n + 1) // 2
        ans = []
        for i in range(m):
            ans.append(nums[i])
            if i + m < n:
                ans.append(nums[i + m])
        return ans
```

#### Java

```java
class Solution {
    public int[] rearrangeArray(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        int m = (n + 1) >> 1;
        int[] ans = new int[n];
        for (int i = 0, j = 0; i < n; i += 2, j++) {
            ans[i] = nums[j];
            if (j + m < n) {
                ans[i + 1] = nums[j + m];
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
    vector<int> rearrangeArray(vector<int>& nums) {
        ranges::sort(nums);
        vector<int> ans;
        int n = nums.size();
        int m = (n + 1) >> 1;
        for (int i = 0; i < m; ++i) {
            ans.push_back(nums[i]);
            if (i + m < n) {
                ans.push_back(nums[i + m]);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func rearrangeArray(nums []int) (ans []int) {
	sort.Ints(nums)
	n := len(nums)
	m := (n + 1) >> 1
	for i := 0; i < m; i++ {
		ans = append(ans, nums[i])
		if i+m < n {
			ans = append(ans, nums[i+m])
		}
	}
	return
}
```

#### TypeScript

```ts
function rearrangeArray(nums: number[]): number[] {
    nums.sort((a, b) => a - b);
    const n = nums.length;
    const m = (n + 1) >> 1;
    const ans: number[] = [];
    for (let i = 0; i < m; i++) {
        ans.push(nums[i]);
        if (i + m < n) {
            ans.push(nums[i + m]);
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

# [1969. 数组元素的最小非零乘积](https://leetcode.cn/problems/minimum-non-zero-product-of-the-array-elements){#1969}

{{< tabs "1969" >}}

{{% tab "python" %}}
```python
class Solution:
    def minNonZeroProduct(self, p: int) -> int:
        mod = 10**9 + 7
        return (2**p - 1) * pow(2**p - 2, 2 ** (p - 1) - 1, mod) % mod
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minNonZeroProduct(int p) {
        final int mod = (int) 1e9 + 7;
        long a = ((1L << p) - 1) % mod;
        long b = qpow(((1L << p) - 2) % mod, (1L << (p - 1)) - 1, mod);
        return (int) (a * b % mod);
    }

    private long qpow(long a, long n, int mod) {
        long ans = 1;
        for (; n > 0; n >>= 1) {
            if ((n & 1) == 1) {
                ans = ans * a % mod;
            }
            a = a * a % mod;
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
    int minNonZeroProduct(int p) {
        using ll = long long;
        const int mod = 1e9 + 7;
        auto qpow = [](ll a, ll n) {
            ll ans = 1;
            for (; n; n >>= 1) {
                if (n & 1) {
                    ans = ans * a % mod;
                }
                a = a * a % mod;
            }
            return ans;
        };
        ll a = ((1LL << p) - 1) % mod;
        ll b = qpow(((1LL << p) - 2) % mod, (1L << (p - 1)) - 1);
        return a * b % mod;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minNonZeroProduct(p int) int {
	const mod int = 1e9 + 7
	qpow := func(a, n int) int {
		ans := 1
		for ; n > 0; n >>= 1 {
			if n&1 == 1 {
				ans = ans * a % mod
			}
			a = a * a % mod
		}
		return ans
	}
	a := ((1 << p) - 1) % mod
	b := qpow(((1<<p)-2)%mod, (1<<(p-1))-1)
	return a * b % mod
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minNonZeroProduct(p: number): number {
    const mod = BigInt(1e9 + 7);

    const qpow = (a: bigint, n: bigint): bigint => {
        let ans = BigInt(1);
        for (; n; n >>= BigInt(1)) {
            if (n & BigInt(1)) {
                ans = (ans * a) % mod;
            }
            a = (a * a) % mod;
        }
        return ans;
    };
    const a = (2n ** BigInt(p) - 1n) % mod;
    const b = qpow((2n ** BigInt(p) - 2n) % mod, 2n ** (BigInt(p) - 1n) - 1n);
    return Number((a * b) % mod);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个正整数&nbsp;<code>p</code>&nbsp;。你有一个下标从 <strong>1</strong>&nbsp;开始的数组&nbsp;<code>nums</code>&nbsp;，这个数组包含范围&nbsp;<code>[1, 2<sup>p</sup> - 1]</code>&nbsp;内所有整数的二进制形式（两端都 <strong>包含</strong>）。你可以进行以下操作 <strong>任意</strong>&nbsp;次：</p>

<ul>
	<li>从 <code>nums</code>&nbsp;中选择两个元素&nbsp;<code>x</code>&nbsp;和&nbsp;<code>y</code>&nbsp; 。</li>
	<li>选择 <code>x</code>&nbsp;中的一位与 <code>y</code>&nbsp;对应位置的位交换。对应位置指的是两个整数 <strong>相同位置</strong>&nbsp;的二进制位。</li>
</ul>

<p>比方说，如果&nbsp;<code>x = 11<em><strong>0</strong></em>1</code>&nbsp;且&nbsp;<code>y = 00<em><strong>1</strong></em>1</code>&nbsp;，交换右边数起第 <code>2</code>&nbsp;位后，我们得到&nbsp;<code>x = 11<em><strong>1</strong></em>1</code> 和&nbsp;<code>y = 00<em><strong>0</strong></em>1</code>&nbsp;。</p>

<p>请你算出进行以上操作 <strong>任意次</strong>&nbsp;以后，<code>nums</code>&nbsp;能得到的 <strong>最小非零</strong>&nbsp;乘积。将乘积对<em>&nbsp;</em><code>10<sup>9</sup> + 7</code>&nbsp;<strong>取余</strong> 后返回。</p>

<p><strong>注意：</strong>答案应为取余 <strong>之前</strong>&nbsp;的最小值。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>p = 1
<b>输出：</b>1
<b>解释：</b>nums = [1] 。
只有一个元素，所以乘积为该元素。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>p = 2
<b>输出：</b>6
<b>解释：</b>nums = [01, 10, 11] 。
所有交换要么使乘积变为 0 ，要么乘积与初始乘积相同。
所以，数组乘积 1 * 2 * 3 = 6 已经是最小值。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>p = 3
<b>输出：</b>1512
<b>解释：</b>nums = [001, 010, 011, 100, 101, 110, 111]
- 第一次操作中，我们交换第二个和第五个元素最左边的数位。
    - 结果数组为 [001, <em><strong>1</strong></em>10, 011, 100, <em><strong>0</strong></em>01, 110, 111] 。
- 第二次操作中，我们交换第三个和第四个元素中间的数位。
    - 结果数组为 [001, 110, 0<em><strong>0</strong></em>1, 1<em><strong>1</strong></em>0, 001, 110, 111] 。
数组乘积 1 * 6 * 1 * 6 * 1 * 6 * 7 = 1512 是最小乘积。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= p &lt;= 60</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 快速幂

我们注意到，每一次操作，并不会改变元素的和，而在元素和不变的情况下，要想使得乘积最小，应该尽可能最大化元素的差值。

由于最大的元素为 $2^p - 1$，无论与哪个元素交换，都不会使得差值变大，因此我们不需要考虑与最大元素交换的情况。

对于其它的 $[1,..2^p-2]$ 的元素，我们依次将首尾元素两两配对，即 $x$ 与 $2^p-1-x$ 进行配置，那么经过若干次操作过后，每一对元素都变成了 $(1, 2^p-2)$，那么最终的乘积为 $(2^p-1) \times (2^p-2)^{2^{p-1}-1}$。

时间复杂度 $O(p)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minNonZeroProduct(self, p: int) -> int:
        mod = 10**9 + 7
        return (2**p - 1) * pow(2**p - 2, 2 ** (p - 1) - 1, mod) % mod
```

#### Java

```java
class Solution {
    public int minNonZeroProduct(int p) {
        final int mod = (int) 1e9 + 7;
        long a = ((1L << p) - 1) % mod;
        long b = qpow(((1L << p) - 2) % mod, (1L << (p - 1)) - 1, mod);
        return (int) (a * b % mod);
    }

    private long qpow(long a, long n, int mod) {
        long ans = 1;
        for (; n > 0; n >>= 1) {
            if ((n & 1) == 1) {
                ans = ans * a % mod;
            }
            a = a * a % mod;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minNonZeroProduct(int p) {
        using ll = long long;
        const int mod = 1e9 + 7;
        auto qpow = [](ll a, ll n) {
            ll ans = 1;
            for (; n; n >>= 1) {
                if (n & 1) {
                    ans = ans * a % mod;
                }
                a = a * a % mod;
            }
            return ans;
        };
        ll a = ((1LL << p) - 1) % mod;
        ll b = qpow(((1LL << p) - 2) % mod, (1L << (p - 1)) - 1);
        return a * b % mod;
    }
};
```

#### Go

```go
func minNonZeroProduct(p int) int {
	const mod int = 1e9 + 7
	qpow := func(a, n int) int {
		ans := 1
		for ; n > 0; n >>= 1 {
			if n&1 == 1 {
				ans = ans * a % mod
			}
			a = a * a % mod
		}
		return ans
	}
	a := ((1 << p) - 1) % mod
	b := qpow(((1<<p)-2)%mod, (1<<(p-1))-1)
	return a * b % mod
}
```

#### TypeScript

```ts
function minNonZeroProduct(p: number): number {
    const mod = BigInt(1e9 + 7);

    const qpow = (a: bigint, n: bigint): bigint => {
        let ans = BigInt(1);
        for (; n; n >>= BigInt(1)) {
            if (n & BigInt(1)) {
                ans = (ans * a) % mod;
            }
            a = (a * a) % mod;
        }
        return ans;
    };
    const a = (2n ** BigInt(p) - 1n) % mod;
    const b = qpow((2n ** BigInt(p) - 2n) % mod, 2n ** (BigInt(p) - 1n) - 1n);
    return Number((a * b) % mod);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
