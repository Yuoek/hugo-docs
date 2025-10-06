---
title: "0318_MaximumProductofWordLengths"
date: 2025-10-06T00:42:37+08:00
weight: 0318
tags: [位运算, 数组, 字符串]
---


{{< katex />}}

{{< badge title="Difficulty" value="中等" >}}

<!-- problem:start -->

# [318. 最大单词长度乘积](https://leetcode.cn/problems/maximum-product-of-word-lengths)

[English Version](../en/0318-18/0318_MaximumProductofWordLengths)

## 题目描述

<!-- description:start -->

<p>给你一个字符串数组&nbsp;<code>words</code> ，找出并返回 <code>length(words[i]) * length(words[j])</code>&nbsp;的最大值，并且这两个单词不含有公共字母。如果不存在这样的两个单词，返回 <code>0</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例&nbsp;1：</strong></p>

<pre>
<strong>输入：</strong>words = <code>["abcw","baz","foo","bar","xtfn","abcdef"]</code>
<strong>输出：</strong><code>16 
<strong>解释</strong></code><strong>：</strong><code>这两个单词为<strong> </strong>"abcw", "xtfn"</code>。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>words = <code>["a","ab","abc","d","cd","bcd","abcd"]</code>
<strong>输出：</strong><code>4 
<strong>解释</strong></code><strong>：</strong>这两个单词为 <code>"ab", "cd"</code>。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>words = <code>["a","aa","aaa","aaaa"]</code>
<strong>输出：</strong><code>0 
<strong>解释</strong></code><strong>：</strong><code>不存在这样的两个单词。</code>
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= words.length &lt;= 1000</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 1000</code></li>
	<li><code>words[i]</code>&nbsp;仅包含小写字母</li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：位运算

题目需要我们找到两个没有公共字母的字符串，使得它们的长度乘积最大。我们可以将每个字符串用一个二进制数 $mask[i]$ 表示，这个二进制数的每一位表示字符串中是否含有某个字母。如果两个字符串没有公共字母，那么这两个字符串对应的二进制数的按位与的结果为 $0$，即 $mask[i] \& mask[j] = 0$。

我们遍历每个字符串，对于当前遍历到的字符串 $words[i]$，我们先算出对应的二进制数 $mask[i]$，然后再遍历 $j \in [0, i)$ 的所有字符串 $words[j]$，检查 $mask[i] \& mask[j] = 0$ 是否成立，如果成立就更新答案为 $\max(ans, |words[i]| \times |words[j]|)$。

遍历结束后，返回答案即可。

时间复杂度 $O(n^2 + L)$，空间复杂度 $O(n)$。其中 $n$ 是字符串数组 $words$ 的长度，而 $L$ 是字符串数组所有字符串的长度之和。

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->

{{< tabs id >}}
{{% tab "python" %}}
```python
class Solution:
    def maxProduct(self, words: List[str]) -> int:
        mask = defaultdict(int)
        ans = 0
        for s in words:
            a = len(s)
            x = 0
            for c in s:
                x |= 1 << (ord(c) - ord("a"))
            for y, b in mask.items():
                if (x & y) == 0:
                    ans = max(ans, a * b)
            mask[x] = max(mask[x], a)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxProduct(String[] words) {
        Map<Integer, Integer> mask = new HashMap<>();
        int ans = 0;
        for (var s : words) {
            int a = s.length();
            int x = 0;
            for (char c : s.toCharArray()) {
                x |= 1 << (c - 'a');
            }
            for (var e : mask.entrySet()) {
                int y = e.getKey(), b = e.getValue();
                if ((x & y) == 0) {
                    ans = Math.max(ans, a * b);
                }
            }
            mask.merge(x, a, Math::max);
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
    int maxProduct(vector<string>& words) {
        unordered_map<int, int> mask;
        int ans = 0;
        for (auto& s : words) {
            int a = s.size();
            int x = 0;
            for (char& c : s) {
                x |= 1 << (c - 'a');
            }
            for (auto& [y, b] : mask) {
                if ((x & y) == 0) {
                    ans = max(ans, a * b);
                }
            }
            mask[x] = max(mask[x], a);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxProduct(words []string) (ans int) {
	mask := map[int]int{}
	for _, s := range words {
		a := len(s)
		x := 0
		for _, c := range s {
			x |= 1 << (c - 'a')
		}
		for y, b := range mask {
			if x&y == 0 {
				ans = max(ans, a*b)
			}
		}
		mask[x] = max(mask[x], a)
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxProduct(words: string[]): number {
    const mask: Map<number, number> = new Map();
    let ans = 0;
    for (const s of words) {
        const a = s.length;
        let x = 0;
        for (const c of s) {
            x |= 1 << (c.charCodeAt(0) - 'a'.charCodeAt(0));
        }
        for (const [y, b] of mask.entries()) {
            if ((x & y) === 0) {
                ans = Math.max(ans, a * b);
            }
        }
        mask.set(x, Math.max(mask.get(x) || 0, a));
    }
    return ans;
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def maxProduct(self, words: List[str]) -> int:
        mask = defaultdict(int)
        ans = 0
        for s in words:
            a = len(s)
            x = 0
            for c in s:
                x |= 1 << (ord(c) - ord("a"))
            for y, b in mask.items():
                if (x & y) == 0:
                    ans = max(ans, a * b)
            mask[x] = max(mask[x], a)
        return ans
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public int maxProduct(String[] words) {
        Map<Integer, Integer> mask = new HashMap<>();
        int ans = 0;
        for (var s : words) {
            int a = s.length();
            int x = 0;
            for (char c : s.toCharArray()) {
                x |= 1 << (c - 'a');
            }
            for (var e : mask.entrySet()) {
                int y = e.getKey(), b = e.getValue();
                if ((x & y) == 0) {
                    ans = Math.max(ans, a * b);
                }
            }
            mask.merge(x, a, Math::max);
        }
        return ans;
    }
}
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "cpp 可视化" %}}
{{< pythontutor width="100%" height="800" language="cpp" >}}
class Solution {
public:
    int maxProduct(vector<string>& words) {
        unordered_map<int, int> mask;
        int ans = 0;
        for (auto& s : words) {
            int a = s.size();
            int x = 0;
            for (char& c : s) {
                x |= 1 << (c - 'a');
            }
            for (auto& [y, b] : mask) {
                if ((x & y) == 0) {
                    ans = max(ans, a * b);
                }
            }
            mask[x] = max(mask[x], a);
        }
        return ans;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}