---
title: "1933_CheckifStringIsDecomposableIntoValue-EqualSubstrings"
date: 2025-10-06T00:42:37+08:00
weight: 1933
tags: [String]
---


{{< katex />}}

{{< badge title="Difficulty" value="Easy" >}}

<!-- problem:start -->

# [1933. Check if String Is Decomposable Into Value-Equal Substrings 🔒](https://leetcode.com/problems/check-if-string-is-decomposable-into-value-equal-substrings)

[中文文档](/solution/1900-1999/1933.Check%20if%20String%20Is%20Decomposable%20Into%20Value-Equal%20Substrings/README.md)

## Description

<!-- description:start -->

<p>A <strong>value-equal</strong> string is a string where <strong>all</strong> characters are the same.</p>

<ul>
	<li>For example, <code>&quot;1111&quot;</code> and <code>&quot;33&quot;</code> are value-equal strings.</li>
	<li>In contrast, <code>&quot;123&quot;</code> is not a value-equal string.</li>
</ul>

<p>Given a digit string <code>s</code>, decompose the string into some number of <strong>consecutive value-equal</strong> substrings where <strong>exactly one</strong> substring has a <strong>length of </strong><code>2</code> and the remaining substrings have a <strong>length of </strong><code>3</code>.</p>

<p>Return <code>true</code><em> if you can decompose </em><code>s</code><em> according to the above rules. Otherwise, return </em><code>false</code>.</p>

<p>A <strong>substring</strong> is a contiguous sequence of characters in a string.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;000111000&quot;
<strong>Output:</strong> false
<strong>Explanation: </strong>s cannot be decomposed according to the rules because [&quot;000&quot;, &quot;111&quot;, &quot;000&quot;] does not have a substring of length 2.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;00011111222&quot;
<strong>Output:</strong> true
<strong>Explanation: </strong>s can be decomposed into [&quot;000&quot;, &quot;111&quot;, &quot;11&quot;, &quot;222&quot;].
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;011100022233&quot;
<strong>Output:</strong> false
<strong>Explanation: </strong>s cannot be decomposed according to the rules because of the first &#39;0&#39;.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s</code> consists of only digits <code>&#39;0&#39;</code> through <code>&#39;9&#39;</code>.</li>
</ul>

<!-- description:end -->

## Solutions

<!-- solution:start -->

### Solution 1: Two Pointers

We traverse the string $s$, using two pointers $i$ and $j$ to count the length of each equal substring. If the length modulo $3$ is $1$, it means that the length of this substring does not meet the requirements, so we return `false`. If the length modulo $3$ is $2$, it means that a substring of length $2$ has appeared. If a substring of length $2$ has appeared before, return `false`, otherwise assign the value of $j$ to $i$ and continue to traverse.

After the traversal, check whether a substring of length $2$ has appeared. If not, return `false`, otherwise return `true`.

The time complexity is $O(n)$, where $n$ is the length of the string $s$. The space complexity is $O(1)$.

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
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
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
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
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
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "cpp 可视化" %}}
{{< pythontutor width="100%" height="800" language="cpp" >}}
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
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}