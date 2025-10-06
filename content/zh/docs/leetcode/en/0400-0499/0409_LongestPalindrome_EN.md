---
title: "0409_LongestPalindrome"
date: 2025-10-06T00:42:37+08:00
weight: 0409
tags: [Greedy, Hash Table, String]
---


{{< katex />}}

{{< badge title="Difficulty" value="Easy" >}}

<!-- problem:start -->

# [409. Longest Palindrome](https://leetcode.com/problems/longest-palindrome)

[中文文档](/solution/0400-0499/0409.Longest%20Palindrome/README.md)

## Description

<!-- description:start -->

<p>Given a string <code>s</code> which consists of lowercase or uppercase letters, return the length of the <strong>longest <span data-keyword="palindrome-string">palindrome</span></strong>&nbsp;that can be built with those letters.</p>

<p>Letters are <strong>case sensitive</strong>, for example, <code>&quot;Aa&quot;</code> is not considered a palindrome.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;abccccdd&quot;
<strong>Output:</strong> 7
<strong>Explanation:</strong> One longest palindrome that can be built is &quot;dccaccd&quot;, whose length is 7.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;a&quot;
<strong>Output:</strong> 1
<strong>Explanation:</strong> The longest palindrome that can be built is &quot;a&quot;, whose length is 1.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 2000</code></li>
	<li><code>s</code> consists of lowercase <strong>and/or</strong> uppercase English&nbsp;letters only.</li>
</ul>

<!-- description:end -->

## Solutions

<!-- solution:start -->

### Solution 1: Counting

A valid palindrome string can have at most one character that appears an odd number of times, and the rest of the characters appear an even number of times.

Therefore, we can first traverse the string $s$, count the number of occurrences of each character, and record it in an array or hash table $cnt$.

Then, we traverse $cnt$, for each count $v$, we divide $v$ by 2, take the integer part, multiply by 2, and add it to the answer $ans$.

Finally, if the answer is less than the length of the string $s$, we increment the answer by one and return $ans$.

The time complexity is $O(n + |\Sigma|)$, and the space complexity is $O(|\Sigma|)$. Where $n$ is the length of the string $s$, and $|\Sigma|$ is the size of the character set. In this problem, $|\Sigma| = 128$.

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

### Solution 2: Bit Manipulation + Counting

We can use an array or hash table $odd$ to record whether each character in string $s$ appears an odd number of times, and an integer variable $cnt$ to record the number of characters that appear an odd number of times.

We iterate through the string $s$. For each character $c$, we flip $odd[c]$, i.e., $0 \rightarrow 1$, $1 \rightarrow 0$. If $odd[c]$ changes from $0$ to $1$, then we increment $cnt$ by one; if $odd[c]$ changes from $1$ to $0$, then we decrement $cnt$ by one.

Finally, if $cnt$ is greater than $0$, the answer is $n - cnt + 1$, otherwise, the answer is $n$.

The time complexity is $O(n)$, and the space complexity is $O(|\Sigma|)$. Where $n$ is the length of the string $s$, and $|\Sigma|$ is the size of the character set. In this problem, $|\Sigma| = 128$.

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
    def longestPalindrome(self, s: str) -> int:
        odd = defaultdict(int)
        cnt = 0
        for c in s:
            odd[c] ^= 1
            cnt += 1 if odd[c] else -1
        return len(s) - cnt + 1 if cnt else len(s)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int longestPalindrome(String s) {
        int[] odd = new int[128];
        int n = s.length();
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            odd[s.charAt(i)] ^= 1;
            cnt += odd[s.charAt(i)] == 1 ? 1 : -1;
        }
        return cnt > 0 ? n - cnt + 1 : n;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        int odd[128]{};
        int n = s.length();
        int cnt = 0;
        for (char& c : s) {
            odd[c] ^= 1;
            cnt += odd[c] ? 1 : -1;
        }
        return cnt ? n - cnt + 1 : n;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func longestPalindrome(s string) (ans int) {
	odd := [128]int{}
	cnt := 0
	for _, c := range s {
		odd[c] ^= 1
		cnt += odd[c]
		if odd[c] == 0 {
			cnt--
		}
	}
	if cnt > 0 {
		return len(s) - cnt + 1
	}
	return len(s)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function longestPalindrome(s: string): number {
    const odd: Record<string, number> = {};
    let cnt = 0;
    for (const c of s) {
        odd[c] ^= 1;
        cnt += odd[c] ? 1 : -1;
    }
    return cnt ? s.length - cnt + 1 : s.length;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashMap;

impl Solution {
    pub fn longest_palindrome(s: String) -> i32 {
        let mut cnt = HashMap::new();
        for ch in s.chars() {
            *cnt.entry(ch).or_insert(0) += 1;
        }

        let mut ans = 0;
        for &v in cnt.values() {
            ans += (v / 2) * 2;
        }

        if ans < (s.len() as i32) {
            ans += 1;
        }

        ans
    }
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def longestPalindrome(self, s: str) -> int:
        odd = defaultdict(int)
        cnt = 0
        for c in s:
            odd[c] ^= 1
            cnt += 1 if odd[c] else -1
        return len(s) - cnt + 1 if cnt else len(s)
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public int longestPalindrome(String s) {
        int[] odd = new int[128];
        int n = s.length();
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            odd[s.charAt(i)] ^= 1;
            cnt += odd[s.charAt(i)] == 1 ? 1 : -1;
        }
        return cnt > 0 ? n - cnt + 1 : n;
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
    int longestPalindrome(string s) {
        int odd[128]{};
        int n = s.length();
        int cnt = 0;
        for (char& c : s) {
            odd[c] ^= 1;
            cnt += odd[c] ? 1 : -1;
        }
        return cnt ? n - cnt + 1 : n;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}