---
title: "2351_FirstLettertoAppearTwice"
date: 2025-10-06T00:42:37+08:00
weight: 2351
tags: [Bit Manipulation, Hash Table, String, Counting]
---


{{< katex />}}

{{< badge title="Difficulty" value="Easy" >}}

<!-- problem:start -->

# [2351. First Letter to Appear Twice](https://leetcode.com/problems/first-letter-to-appear-twice)

[中文文档](/solution/2300-2399/2351.First%20Letter%20to%20Appear%20Twice/README.md)

## Description

<!-- description:start -->

<p>Given a string <code>s</code> consisting of lowercase English letters, return <em>the first letter to appear <strong>twice</strong></em>.</p>

<p><strong>Note</strong>:</p>

<ul>
	<li>A letter <code>a</code> appears twice before another letter <code>b</code> if the <strong>second</strong> occurrence of <code>a</code> is before the <strong>second</strong> occurrence of <code>b</code>.</li>
	<li><code>s</code> will contain at least one letter that appears twice.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;abccbaacz&quot;
<strong>Output:</strong> &quot;c&quot;
<strong>Explanation:</strong>
The letter &#39;a&#39; appears on the indexes 0, 5 and 6.
The letter &#39;b&#39; appears on the indexes 1 and 4.
The letter &#39;c&#39; appears on the indexes 2, 3 and 7.
The letter &#39;z&#39; appears on the index 8.
The letter &#39;c&#39; is the first letter to appear twice, because out of all the letters the index of its second occurrence is the smallest.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;abcdd&quot;
<strong>Output:</strong> &quot;d&quot;
<strong>Explanation:</strong>
The only letter that appears twice is &#39;d&#39; so we return &#39;d&#39;.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= s.length &lt;= 100</code></li>
	<li><code>s</code> consists of lowercase English letters.</li>
	<li><code>s</code> has at least one repeated letter.</li>
</ul>

<!-- description:end -->

## Solutions

<!-- solution:start -->

### Solution 1: Array or Hash Table

We traverse the string $s$, using an array or hash table `cnt` to record the occurrence of each letter. When a letter appears twice, we return that letter.

The time complexity is $O(n)$ and the space complexity is $O(C)$. Here, $n$ is the length of the string $s$, and $C$ is the size of the character set. In this problem, $C = 26$.

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



#### Rust



#### PHP



#### C



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### Solution 2: Bit Manipulation

We can also use an integer `mask` to record whether each letter has appeared, where the $i$-th bit of `mask` indicates whether the $i$-th letter has appeared. When a letter appears twice, we return that letter.

The time complexity is $O(n)$ and the space complexity is $O(1)$. Here, $n$ is the length of the string $s$.

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



#### Rust



#### C



<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->

{{< tabs id >}}
{{% tab "python" %}}
```python
class Solution:
    def repeatedCharacter(self, s: str) -> str:
        mask = 0
        for c in s:
            i = ord(c) - ord('a')
            if mask >> i & 1:
                return c
            mask |= 1 << i
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public char repeatedCharacter(String s) {
        int mask = 0;
        for (int i = 0;; ++i) {
            char c = s.charAt(i);
            if ((mask >> (c - 'a') & 1) == 1) {
                return c;
            }
            mask |= 1 << (c - 'a');
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    char repeatedCharacter(string s) {
        int mask = 0;
        for (int i = 0;; ++i) {
            if (mask >> (s[i] - 'a') & 1) {
                return s[i];
            }
            mask |= 1 << (s[i] - 'a');
        }
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func repeatedCharacter(s string) byte {
	mask := 0
	for i := 0; ; i++ {
		if mask>>(s[i]-'a')&1 == 1 {
			return s[i]
		}
		mask |= 1 << (s[i] - 'a')
	}
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function repeatedCharacter(s: string): string {
    let mask = 0;
    for (const c of s) {
        const i = c.charCodeAt(0) - 'a'.charCodeAt(0);
        if (mask & (1 << i)) {
            return c;
        }
        mask |= 1 << i;
    }
    return ' ';
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn repeated_character(s: String) -> char {
        let mut mask = 0;
        for &c in s.as_bytes() {
            if (mask & (1 << ((c - b'a') as i32))) != 0 {
                return c as char;
            }
            mask |= 1 << ((c - b'a') as i32);
        }
        ' '
    }
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param String $s
     * @return String
     */
    function repeatedCharacter($s) {
        for ($i = 0; ; $i++) {
            $hashtable[$s[$i]] += 1;
            if ($hashtable[$s[$i]] == 2) {
                return $s[$i];
            }
        }
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
char repeatedCharacter(char* s) {
    int mask = 0;
    for (int i = 0; s[i]; i++) {
        if (mask & (1 << s[i] - 'a')) {
            return s[i];
        }
        mask |= 1 << s[i] - 'a';
    }
    return ' ';
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def repeatedCharacter(self, s: str) -> str:
        mask = 0
        for c in s:
            i = ord(c) - ord('a')
            if mask >> i & 1:
                return c
            mask |= 1 << i
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public char repeatedCharacter(String s) {
        int mask = 0;
        for (int i = 0;; ++i) {
            char c = s.charAt(i);
            if ((mask >> (c - 'a') & 1) == 1) {
                return c;
            }
            mask |= 1 << (c - 'a');
        }
    }
}
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "c 可视化" %}}
{{< pythontutor width="100%" height="800" language="c" >}}
char repeatedCharacter(char* s) {
    int mask = 0;
    for (int i = 0; s[i]; i++) {
        if (mask & (1 << s[i] - 'a')) {
            return s[i];
        }
        mask |= 1 << s[i] - 'a';
    }
    return ' ';
}
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "cpp 可视化" %}}
{{< pythontutor width="100%" height="800" language="cpp" >}}
class Solution {
public:
    char repeatedCharacter(string s) {
        int mask = 0;
        for (int i = 0;; ++i) {
            if (mask >> (s[i] - 'a') & 1) {
                return s[i];
            }
            mask |= 1 << (s[i] - 'a');
        }
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}