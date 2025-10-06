---
title: "3163_StringCompressionIII"
date: 2025-10-06T00:42:37+08:00
weight: 3163
tags: [String]
---


{{< katex />}}

{{< badge title="Difficulty" value="Medium" >}}

<!-- problem:start -->

# [3163. String Compression III](https://leetcode.com/problems/string-compression-iii)

[中文文档](/solution/3100-3199/3163.String%20Compression%20III/README.md)

## Description

<!-- description:start -->

<p>Given a string <code>word</code>, compress it using the following algorithm:</p>

<ul>
	<li>Begin with an empty string <code>comp</code>. While <code>word</code> is <strong>not</strong> empty, use the following operation:

    <ul>
    	<li>Remove a maximum length prefix of <code>word</code> made of a <em>single character</em> <code>c</code> repeating <strong>at most</strong> 9 times.</li>
    	<li>Append the length of the prefix followed by <code>c</code> to <code>comp</code>.</li>
    </ul>
    </li>

</ul>

<p>Return the string <code>comp</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">word = &quot;abcde&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">&quot;1a1b1c1d1e&quot;</span></p>

<p><strong>Explanation:</strong></p>

<p>Initially, <code>comp = &quot;&quot;</code>. Apply the operation 5 times, choosing <code>&quot;a&quot;</code>, <code>&quot;b&quot;</code>, <code>&quot;c&quot;</code>, <code>&quot;d&quot;</code>, and <code>&quot;e&quot;</code> as the prefix in each operation.</p>

<p>For each prefix, append <code>&quot;1&quot;</code> followed by the character to <code>comp</code>.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">word = &quot;aaaaaaaaaaaaaabb&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">&quot;9a5a2b&quot;</span></p>

<p><strong>Explanation:</strong></p>

<p>Initially, <code>comp = &quot;&quot;</code>. Apply the operation 3 times, choosing <code>&quot;aaaaaaaaa&quot;</code>, <code>&quot;aaaaa&quot;</code>, and <code>&quot;bb&quot;</code> as the prefix in each operation.</p>

<ul>
	<li>For prefix <code>&quot;aaaaaaaaa&quot;</code>, append <code>&quot;9&quot;</code> followed by <code>&quot;a&quot;</code> to <code>comp</code>.</li>
	<li>For prefix <code>&quot;aaaaa&quot;</code>, append <code>&quot;5&quot;</code> followed by <code>&quot;a&quot;</code> to <code>comp</code>.</li>
	<li>For prefix <code>&quot;bb&quot;</code>, append <code>&quot;2&quot;</code> followed by <code>&quot;b&quot;</code> to <code>comp</code>.</li>
</ul>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= word.length &lt;= 2 * 10<sup>5</sup></code></li>
	<li><code>word</code> consists only of lowercase English letters.</li>
</ul>

<!-- description:end -->

## Solutions

<!-- solution:start -->

### Solution 1: Two Pointers

We can use two pointers to count the consecutive occurrences of each character. Suppose the current character $c$ appears consecutively $k$ times, then we divide $k$ into several $x$, each $x$ is at most $9$, then we concatenate $x$ and $c$, and append each $x$ and $c$ to the result.

Finally, return the result.

The time complexity is $O(n)$, and the space complexity is $O(n)$. Where $n$ is the length of the

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



#### JavaScript



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### Solution 2: Two Pointers

<!-- tabs:start -->

#### TypeScript



#### JavaScript



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### Solution 3: RegExp

<!-- tabs:start -->

#### TypeScript



#### JavaScript



<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->

{{< tabs id >}}
{{% tab "python" %}}
```python
class Solution:
    def compressedString(self, word: str) -> str:
        g = groupby(word)
        ans = []
        for c, v in g:
            k = len(list(v))
            while k:
                x = min(9, k)
                ans.append(str(x) + c)
                k -= x
        return "".join(ans)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String compressedString(String word) {
        StringBuilder ans = new StringBuilder();
        int n = word.length();
        for (int i = 0; i < n;) {
            int j = i + 1;
            while (j < n && word.charAt(j) == word.charAt(i)) {
                ++j;
            }
            int k = j - i;
            while (k > 0) {
                int x = Math.min(9, k);
                ans.append(x).append(word.charAt(i));
                k -= x;
            }
            i = j;
        }
        return ans.toString();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string compressedString(string word) {
        string ans;
        int n = word.length();
        for (int i = 0; i < n;) {
            int j = i + 1;
            while (j < n && word[j] == word[i]) {
                ++j;
            }
            int k = j - i;
            while (k > 0) {
                int x = min(9, k);
                ans.push_back('0' + x);
                ans.push_back(word[i]);
                k -= x;
            }
            i = j;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func compressedString(word string) string {
	ans := []byte{}
	n := len(word)
	for i := 0; i < n; {
		j := i + 1
		for j < n && word[j] == word[i] {
			j++
		}
		k := j - i
		for k > 0 {
			x := min(9, k)
			ans = append(ans, byte('0'+x))
			ans = append(ans, word[i])
			k -= x
		}
		i = j
	}
	return string(ans)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function compressedString(word: string): string {
    const regex = /(.)\1{0,8}/g;
    let m: RegExpMatchArray | null = null;
    let res = '';

    while ((m = regex.exec(word))) {
        res += m[0].length + m[1];
    }

    return res;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
function compressedString(word) {
    const regex = /(.)\1{0,8}/g;
    let m = null;
    let res = '';

    while ((m = regex.exec(word))) {
        res += m[0].length + m[1];
    }

    return res;
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def compressedString(self, word: str) -> str:
        g = groupby(word)
        ans = []
        for c, v in g:
            k = len(list(v))
            while k:
                x = min(9, k)
                ans.append(str(x) + c)
                k -= x
        return "".join(ans)
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public String compressedString(String word) {
        StringBuilder ans = new StringBuilder();
        int n = word.length();
        for (int i = 0; i < n;) {
            int j = i + 1;
            while (j < n && word.charAt(j) == word.charAt(i)) {
                ++j;
            }
            int k = j - i;
            while (k > 0) {
                int x = Math.min(9, k);
                ans.append(x).append(word.charAt(i));
                k -= x;
            }
            i = j;
        }
        return ans.toString();
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
    string compressedString(string word) {
        string ans;
        int n = word.length();
        for (int i = 0; i < n;) {
            int j = i + 1;
            while (j < n && word[j] == word[i]) {
                ++j;
            }
            int k = j - i;
            while (k > 0) {
                int x = min(9, k);
                ans.push_back('0' + x);
                ans.push_back(word[i]);
                k -= x;
            }
            i = j;
        }
        return ans;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}