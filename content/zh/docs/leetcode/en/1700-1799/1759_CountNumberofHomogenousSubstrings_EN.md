---
title: "1759_CountNumberofHomogenousSubstrings"
date: 2025-10-06T00:42:37+08:00
weight: 1759
tags: [Math, String]
---


{{< katex />}}

{{< badge title="Difficulty" value="Medium" >}}

<!-- problem:start -->

# [1759. Count Number of Homogenous Substrings](https://leetcode.com/problems/count-number-of-homogenous-substrings)

[中文文档](/solution/1700-1799/1759.Count%20Number%20of%20Homogenous%20Substrings/README.md)

## Description

<!-- description:start -->

<p>Given a string <code>s</code>, return <em>the number of <strong>homogenous</strong> substrings of </em><code>s</code><em>.</em> Since the answer may be too large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>A string is <strong>homogenous</strong> if all the characters of the string are the same.</p>

<p>A <strong>substring</strong> is a contiguous sequence of characters within a string.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;abbcccaa&quot;
<strong>Output:</strong> 13
<strong>Explanation:</strong> The homogenous substrings are listed as below:
&quot;a&quot;   appears 3 times.
&quot;aa&quot;  appears 1 time.
&quot;b&quot;   appears 2 times.
&quot;bb&quot;  appears 1 time.
&quot;c&quot;   appears 3 times.
&quot;cc&quot;  appears 2 times.
&quot;ccc&quot; appears 1 time.
3 + 1 + 2 + 1 + 3 + 2 + 1 = 13.</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;xy&quot;
<strong>Output:</strong> 2
<strong>Explanation:</strong> The homogenous substrings are &quot;x&quot; and &quot;y&quot;.</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;zzzzz&quot;
<strong>Output:</strong> 15
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> consists of lowercase letters.</li>
</ul>

<!-- description:end -->

## Solutions

<!-- solution:start -->

### Solution 1

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



#### Rust



#### C#



#### C



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### Solution 2

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
    def countHomogenous(self, s: str) -> int:
        mod = 10**9 + 7
        ans = cnt = 1
        for a, b in pairwise(s):
            cnt = cnt + 1 if a == b else 1
            ans = (ans + cnt) % mod
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private static final int MOD = (int) 1e9 + 7;

    public int countHomogenous(String s) {
        int n = s.length();
        int ans = 1, cnt = 1;
        for (int i = 1; i < n; ++i) {
            cnt = s.charAt(i) == s.charAt(i - 1) ? cnt + 1 : 1;
            ans = (ans + cnt) % MOD;
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

    int countHomogenous(string s) {
        int n = s.size();
        int ans = 1, cnt = 1;
        for (int i = 1; i < n; ++i) {
            cnt = s[i] == s[i - 1] ? cnt + 1 : 1;
            ans = (ans + cnt) % mod;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countHomogenous(s string) int {
	n := len(s)
	const mod int = 1e9 + 7
	ans, cnt := 1, 1
	for i := 1; i < n; i++ {
		if s[i] == s[i-1] {
			cnt++
		} else {
			cnt = 1
		}
		ans = (ans + cnt) % mod
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countHomogenous(s: string): number {
    const mod = 1e9 + 7;
    const n = s.length;
    let ans = 0;
    for (let i = 0, j = 0; j < n; j++) {
        if (s[i] !== s[j]) {
            i = j;
        }
        ans = (ans + j - i + 1) % mod;
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn count_homogenous(s: String) -> i32 {
        const MOD: usize = (1e9 as usize) + 7;
        let s = s.as_bytes();
        let n = s.len();
        let mut ans = 0;
        let mut i = 0;
        for j in 0..n {
            if s[i] != s[j] {
                i = j;
            }
            ans = (ans + j - i + 1) % MOD;
        }
        ans as i32
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int CountHomogenous(string s) {
        long MOD = 1000000007;
        long ans = 0;
        for (int i = 0, j = 0; i < s.Length; i = j) {
            j = i;
            while (j < s.Length && s[j] == s[i]) {
                ++j;
            }
            int cnt = j - i;
            ans += (long) (1 + cnt) * cnt / 2;
            ans %= MOD;
        }
        return (int) ans;
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
int countHomogenous(char* s) {
    int MOD = 1e9 + 7;
    int ans = 0;
    for (int i = 0, j = 0; s[j]; j++) {
        if (s[i] != s[j]) {
            i = j;
        }
        ans = (ans + j - i + 1) % MOD;
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
    def countHomogenous(self, s: str) -> int:
        mod = 10**9 + 7
        ans = cnt = 1
        for a, b in pairwise(s):
            cnt = cnt + 1 if a == b else 1
            ans = (ans + cnt) % mod
        return ans
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    private static final int MOD = (int) 1e9 + 7;

    public int countHomogenous(String s) {
        int n = s.length();
        int ans = 1, cnt = 1;
        for (int i = 1; i < n; ++i) {
            cnt = s.charAt(i) == s.charAt(i - 1) ? cnt + 1 : 1;
            ans = (ans + cnt) % MOD;
        }
        return ans;
    }
}
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "c 可视化" %}}
{{< pythontutor width="100%" height="800" language="c" >}}
int countHomogenous(char* s) {
    int MOD = 1e9 + 7;
    int ans = 0;
    for (int i = 0, j = 0; s[j]; j++) {
        if (s[i] != s[j]) {
            i = j;
        }
        ans = (ans + j - i + 1) % MOD;
    }
    return ans;
}
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "cpp 可视化" %}}
{{< pythontutor width="100%" height="800" language="cpp" >}}
class Solution {
public:
    const int mod = 1e9 + 7;

    int countHomogenous(string s) {
        int n = s.size();
        int ans = 1, cnt = 1;
        for (int i = 1; i < n; ++i) {
            cnt = s[i] == s[i - 1] ? cnt + 1 : 1;
            ans = (ans + cnt) % mod;
        }
        return ans;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}