---
title: "1392_LongestHappyPrefix"
date: 2025-10-06T00:42:37+08:00
weight: 1392
tags: [String, String Matching, Hash Function, Rolling Hash]
---


{{< katex />}}

{{< badge title="Difficulty" value="Hard" >}}

<!-- problem:start -->

# [1392. Longest Happy Prefix](https://leetcode.com/problems/longest-happy-prefix)

[中文文档](/solution/1300-1399/1392.Longest%20Happy%20Prefix/README.md)

## Description

<!-- description:start -->

<p>A string is called a <strong>happy prefix</strong> if is a <strong>non-empty</strong> prefix which is also a suffix (excluding itself).</p>

<p>Given a string <code>s</code>, return <em>the <strong>longest happy prefix</strong> of</em> <code>s</code>. Return an empty string <code>&quot;&quot;</code> if no such prefix exists.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;level&quot;
<strong>Output:</strong> &quot;l&quot;
<strong>Explanation:</strong> s contains 4 prefix excluding itself (&quot;l&quot;, &quot;le&quot;, &quot;lev&quot;, &quot;leve&quot;), and suffix (&quot;l&quot;, &quot;el&quot;, &quot;vel&quot;, &quot;evel&quot;). The largest prefix which is also suffix is given by &quot;l&quot;.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;ababab&quot;
<strong>Output:</strong> &quot;abab&quot;
<strong>Explanation:</strong> &quot;abab&quot; is the largest prefix which is also suffix. They can overlap in the original string.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> contains only lowercase English letters.</li>
</ul>

<!-- description:end -->

## Solutions

<!-- solution:start -->

### Solution 1: String Hashing

**String Hashing** is a method to map a string of any length to a non-negative integer, with the probability of collision being almost zero. String hashing is used to calculate the hash value of a string, which allows for quick determination of whether two strings are equal.

We choose a fixed value BASE, and consider the string as a number in BASE radix, assigning a value greater than 0 to represent each character. Generally, the values we assign are much smaller than BASE. For example, for strings composed of lowercase letters, we can assign a=1, b=2, ..., z=26. We choose a fixed value MOD, and calculate the remainder of the BASE radix number divided by MOD, which is used as the hash value of the string.

Generally, we choose BASE=131 or BASE=13331, at which point the probability of hash value collision is extremely low. As long as the hash values of two strings are the same, we consider the two strings to be equal. Usually, MOD is chosen as $2^{64}$. In C++, we can directly use the unsigned long long type to store this hash value. When calculating, we do not handle arithmetic overflow. When overflow occurs, it is equivalent to automatically taking the modulus of $2^{64}$, which can avoid inefficient modulus operations.

Except for extremely specially constructed data, the above hash algorithm is unlikely to produce collisions. In general, the above hash algorithm can appear in the standard answers of the problem. We can also choose some appropriate values of BASE and MOD (such as large prime numbers), and perform several groups of hash operations. Only when the results are all the same do we consider the original strings to be equal, making it even more difficult to construct data that causes this hash to produce errors.

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



#### Rust



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### Solution 2: KMP Algorithm

According to the problem description, we need to find the longest happy prefix of a string, which is the longest prefix of the string that is also a suffix of the string. We can use the KMP algorithm to solve this problem.

The time complexity is $O(n)$, and the space complexity is $O(n)$. Here, $n$ is the length of the string.

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
    def longestPrefix(self, s: str) -> str:
        s += "#"
        n = len(s)
        next = [0] * n
        next[0] = -1
        i, j = 2, 0
        while i < n:
            if s[i - 1] == s[j]:
                j += 1
                next[i] = j
                i += 1
            elif j:
                j = next[j]
            else:
                next[i] = 0
                i += 1
        return s[: next[-1]]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String longestPrefix(String s) {
        s += "#";
        int n = s.length();
        int[] next = new int[n];
        next[0] = -1;
        for (int i = 2, j = 0; i < n;) {
            if (s.charAt(i - 1) == s.charAt(j)) {
                next[i++] = ++j;
            } else if (j > 0) {
                j = next[j];
            } else {
                next[i++] = 0;
            }
        }
        return s.substring(0, next[n - 1]);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string longestPrefix(string s) {
        s.push_back('#');
        int n = s.size();
        int next[n];
        next[0] = -1;
        next[1] = 0;
        for (int i = 2, j = 0; i < n;) {
            if (s[i - 1] == s[j]) {
                next[i++] = ++j;
            } else if (j > 0) {
                j = next[j];
            } else {
                next[i++] = 0;
            }
        }
        return s.substr(0, next[n - 1]);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func longestPrefix(s string) string {
	s += "#"
	n := len(s)
	next := make([]int, n)
	next[0], next[1] = -1, 0
	for i, j := 2, 0; i < n; {
		if s[i-1] == s[j] {
			j++
			next[i] = j
			i++
		} else if j > 0 {
			j = next[j]
		} else {
			next[i] = 0
			i++
		}
	}
	return s[:next[n-1]]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function longestPrefix(s: string): string {
    s += '#';
    const n = s.length;
    const next: number[] = Array(n).fill(0);
    next[0] = -1;
    for (let i = 2, j = 0; i < n; ) {
        if (s[i - 1] === s[j]) {
            next[i++] = ++j;
        } else if (j > 0) {
            j = next[j];
        } else {
            next[i++] = 0;
        }
    }
    return s.slice(0, next[n - 1]);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn longest_prefix(s: String) -> String {
        let n = s.len();
        for i in (0..n).rev() {
            if s[0..i] == s[n - i..n] {
                return s[0..i].to_string();
            }
        }
        String::new()
    }
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def longestPrefix(self, s: str) -> str:
        s += "#"
        n = len(s)
        next = [0] * n
        next[0] = -1
        i, j = 2, 0
        while i < n:
            if s[i - 1] == s[j]:
                j += 1
                next[i] = j
                i += 1
            elif j:
                j = next[j]
            else:
                next[i] = 0
                i += 1
        return s[: next[-1]]
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public String longestPrefix(String s) {
        s += "#";
        int n = s.length();
        int[] next = new int[n];
        next[0] = -1;
        for (int i = 2, j = 0; i < n;) {
            if (s.charAt(i - 1) == s.charAt(j)) {
                next[i++] = ++j;
            } else if (j > 0) {
                j = next[j];
            } else {
                next[i++] = 0;
            }
        }
        return s.substring(0, next[n - 1]);
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
    string longestPrefix(string s) {
        s.push_back('#');
        int n = s.size();
        int next[n];
        next[0] = -1;
        next[1] = 0;
        for (int i = 2, j = 0; i < n;) {
            if (s[i - 1] == s[j]) {
                next[i++] = ++j;
            } else if (j > 0) {
                j = next[j];
            } else {
                next[i++] = 0;
            }
        }
        return s.substr(0, next[n - 1]);
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}