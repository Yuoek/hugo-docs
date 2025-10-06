---
title: "0318_MaximumProductofWordLengths"
date: 2025-10-06T00:42:37+08:00
weight: 0318
tags: [Bit Manipulation, Array, String]
---


{{< katex />}}

{{< badge title="Difficulty" value="Medium" >}}

<!-- problem:start -->

# [318. Maximum Product of Word Lengths](https://leetcode.com/problems/maximum-product-of-word-lengths)

[中文文档](/solution/0300-0399/0318.Maximum%20Product%20of%20Word%20Lengths/README.md)

## Description

<!-- description:start -->

<p>Given a string array <code>words</code>, return <em>the maximum value of</em> <code>length(word[i]) * length(word[j])</code> <em>where the two words do not share common letters</em>. If no such two words exist, return <code>0</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> words = [&quot;abcw&quot;,&quot;baz&quot;,&quot;foo&quot;,&quot;bar&quot;,&quot;xtfn&quot;,&quot;abcdef&quot;]
<strong>Output:</strong> 16
<strong>Explanation:</strong> The two words can be &quot;abcw&quot;, &quot;xtfn&quot;.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> words = [&quot;a&quot;,&quot;ab&quot;,&quot;abc&quot;,&quot;d&quot;,&quot;cd&quot;,&quot;bcd&quot;,&quot;abcd&quot;]
<strong>Output:</strong> 4
<strong>Explanation:</strong> The two words can be &quot;ab&quot;, &quot;cd&quot;.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> words = [&quot;a&quot;,&quot;aa&quot;,&quot;aaa&quot;,&quot;aaaa&quot;]
<strong>Output:</strong> 0
<strong>Explanation:</strong> No such pair of words.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= words.length &lt;= 1000</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 1000</code></li>
	<li><code>words[i]</code> consists only of lowercase English letters.</li>
</ul>

<!-- description:end -->

## Solutions

<!-- solution:start -->

### Solution 1: Bit Manipulation

The problem requires us to find two strings without common letters, so that their length product is maximized. We can represent each string with a binary number $mask[i]$, where each bit of this binary number indicates whether the string contains a certain letter. If two strings do not have common letters, then the bitwise AND result of the two binary numbers corresponding to these strings is $0$, that is, $mask[i] \& mask[j] = 0$.

We traverse each string. For the current string $words[i]$ we are traversing, we first calculate the corresponding binary number $mask[i]$, and then traverse all strings $words[j]$ where $j \in [0, i)$. We check whether $mask[i] \& mask[j] = 0$ holds. If it holds, we update the answer to $\max(ans, |words[i]| \times |words[j]|)$.

After the traversal, we return the answer.

The time complexity is $O(n^2 + L)$, and the space complexity is $O(n)$. Here, $n$ is the length of the string array $words$, and $L$ is the sum of the lengths of all strings in the string array.

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### Solution 2

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