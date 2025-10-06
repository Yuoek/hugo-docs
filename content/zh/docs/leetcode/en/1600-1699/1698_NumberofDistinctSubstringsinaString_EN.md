---
title: "1698_NumberofDistinctSubstringsinaString"
date: 2025-10-06T00:42:37+08:00
weight: 1698
tags: [Trie, String, Suffix Array, Hash Function, Rolling Hash]
---


{{< katex />}}

{{< badge title="Difficulty" value="Medium" >}}

<!-- problem:start -->

# [1698. Number of Distinct Substrings in a String 🔒](https://leetcode.com/problems/number-of-distinct-substrings-in-a-string)

[中文文档](/solution/1600-1699/1698.Number%20of%20Distinct%20Substrings%20in%20a%20String/README.md)

## Description

<!-- description:start -->

<p>Given a string <code>s</code>, return <em>the number of <strong>distinct</strong> substrings of</em>&nbsp;<code>s</code>.</p>

<p>A <strong>substring</strong> of a string is obtained by deleting any number of characters (possibly zero) from the front of the string and any number (possibly zero) from the back of the string.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;aabbaba&quot;
<strong>Output:</strong> 21
<strong>Explanation:</strong> The set of distinct strings is [&quot;a&quot;,&quot;b&quot;,&quot;aa&quot;,&quot;bb&quot;,&quot;ab&quot;,&quot;ba&quot;,&quot;aab&quot;,&quot;abb&quot;,&quot;bab&quot;,&quot;bba&quot;,&quot;aba&quot;,&quot;aabb&quot;,&quot;abba&quot;,&quot;bbab&quot;,&quot;baba&quot;,&quot;aabba&quot;,&quot;abbab&quot;,&quot;bbaba&quot;,&quot;aabbab&quot;,&quot;abbaba&quot;,&quot;aabbaba&quot;]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;abcdefg&quot;
<strong>Output:</strong> 28
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 500</code></li>
	<li><code>s</code> consists of lowercase English letters.</li>
</ul>

<p>&nbsp;</p>
<strong>Follow up:</strong> Can you solve this problem in <code>O(n)</code> time complexity?

<!-- description:end -->

## Solutions

<!-- solution:start -->

### Solution 1: Brute Force Enumeration

Enumerate all substrings and use a hash table to record the count of different substrings.

The time complexity is $O(n^3)$, and the space complexity is $O(n^2)$. Here, $n$ is the length of the string.

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### Solution 2: String Hashing

**String hashing** is a method to map a string of any length to a non-negative integer, and the probability of collision is almost zero. String hashing is used to calculate the hash value of a string, which can quickly determine whether two strings are equal.

We take a fixed value BASE, treat the string as a number in BASE radix, and assign a value greater than 0 to represent each character. Generally, the values we assign are much smaller than BASE. For example, for a string composed of lowercase letters, we can set a=1, b=2, ..., z=26. We take a fixed value MOD, calculate the remainder of the BASE radix number to MOD, and use it as the hash value of the string.

Generally, we take BASE=131 or BASE=13331, at which point the probability of collision of the hash value is extremely low. As long as the hash values of two strings are the same, we consider the two strings to be equal. Usually, MOD is taken as 2^64. In C++, we can directly use the unsigned long long type to store this hash value. When calculating, we do not handle arithmetic overflow. When overflow occurs, it is equivalent to automatically taking the modulus of 2^64, which can avoid inefficient modulus operations.

Except for extremely specially constructed data, the above hash algorithm is unlikely to cause collisions. In general, the above hash algorithm can appear in the standard answer of the problem. We can also take some appropriate BASE and MOD values (such as large prime numbers), perform several groups of hash operations, and only consider the original strings equal when the results are all the same, making it even more difficult to construct data that causes this hash to produce errors.

The time complexity is $O(n^2)$, and the space complexity is $O(n^2)$. Here, $n$ is the length of the string.

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->

{{< tabs id >}}
{{% tab "python" %}}
```python
class Solution:
    def countDistinct(self, s: str) -> int:
        base = 131
        n = len(s)
        p = [0] * (n + 10)
        h = [0] * (n + 10)
        p[0] = 1
        for i, c in enumerate(s):
            p[i + 1] = p[i] * base
            h[i + 1] = h[i] * base + ord(c)
        ss = set()
        for i in range(1, n + 1):
            for j in range(i, n + 1):
                t = h[j] - h[i - 1] * p[j - i + 1]
                ss.add(t)
        return len(ss)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countDistinct(String s) {
        int base = 131;
        int n = s.length();
        long[] p = new long[n + 10];
        long[] h = new long[n + 10];
        p[0] = 1;
        for (int i = 0; i < n; ++i) {
            p[i + 1] = p[i] * base;
            h[i + 1] = h[i] * base + s.charAt(i);
        }
        Set<Long> ss = new HashSet<>();
        for (int i = 1; i <= n; ++i) {
            for (int j = i; j <= n; ++j) {
                long t = h[j] - h[i - 1] * p[j - i + 1];
                ss.add(t);
            }
        }
        return ss.size();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int countDistinct(string s) {
        using ull = unsigned long long;
        int n = s.size();
        ull p[n + 10];
        ull h[n + 10];
        int base = 131;
        p[0] = 1;
        for (int i = 0; i < n; ++i) {
            p[i + 1] = p[i] * base;
            h[i + 1] = h[i] * base + s[i];
        }
        unordered_set<ull> ss;
        for (int i = 1; i <= n; ++i) {
            for (int j = i; j <= n; ++j) {
                ss.insert(h[j] - h[i - 1] * p[j - i + 1]);
            }
        }
        return ss.size();
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countDistinct(s string) int {
	n := len(s)
	p := make([]int, n+10)
	h := make([]int, n+10)
	p[0] = 1
	base := 131
	for i, c := range s {
		p[i+1] = p[i] * base
		h[i+1] = h[i]*base + int(c)
	}
	ss := map[int]struct{}{}
	for i := 1; i <= n; i++ {
		for j := i; j <= n; j++ {
			ss[h[j]-h[i-1]*p[j-i+1]] = struct{}{}
		}
	}
	return len(ss)
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def countDistinct(self, s: str) -> int:
        base = 131
        n = len(s)
        p = [0] * (n + 10)
        h = [0] * (n + 10)
        p[0] = 1
        for i, c in enumerate(s):
            p[i + 1] = p[i] * base
            h[i + 1] = h[i] * base + ord(c)
        ss = set()
        for i in range(1, n + 1):
            for j in range(i, n + 1):
                t = h[j] - h[i - 1] * p[j - i + 1]
                ss.add(t)
        return len(ss)
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public int countDistinct(String s) {
        int base = 131;
        int n = s.length();
        long[] p = new long[n + 10];
        long[] h = new long[n + 10];
        p[0] = 1;
        for (int i = 0; i < n; ++i) {
            p[i + 1] = p[i] * base;
            h[i + 1] = h[i] * base + s.charAt(i);
        }
        Set<Long> ss = new HashSet<>();
        for (int i = 1; i <= n; ++i) {
            for (int j = i; j <= n; ++j) {
                long t = h[j] - h[i - 1] * p[j - i + 1];
                ss.add(t);
            }
        }
        return ss.size();
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
    int countDistinct(string s) {
        using ull = unsigned long long;
        int n = s.size();
        ull p[n + 10];
        ull h[n + 10];
        int base = 131;
        p[0] = 1;
        for (int i = 0; i < n; ++i) {
            p[i + 1] = p[i] * base;
            h[i + 1] = h[i] * base + s[i];
        }
        unordered_set<ull> ss;
        for (int i = 1; i <= n; ++i) {
            for (int j = i; j <= n; ++j) {
                ss.insert(h[j] - h[i - 1] * p[j - i + 1]);
            }
        }
        return ss.size();
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}