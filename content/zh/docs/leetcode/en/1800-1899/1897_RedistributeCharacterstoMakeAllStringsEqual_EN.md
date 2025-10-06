---
title: "1897_RedistributeCharacterstoMakeAllStringsEqual"
date: 2025-10-06T00:42:37+08:00
weight: 1897
tags: [Hash Table, String, Counting]
---


{{< katex />}}

{{< badge title="Difficulty" value="Easy" >}}

<!-- problem:start -->

# [1897. Redistribute Characters to Make All Strings Equal](https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal)

[中文文档](/solution/1800-1899/1897.Redistribute%20Characters%20to%20Make%20All%20Strings%20Equal/README.md)

## Description

<!-- description:start -->

<p>You are given an array of strings <code>words</code> (<strong>0-indexed</strong>).</p>

<p>In one operation, pick two <strong>distinct</strong> indices <code>i</code> and <code>j</code>, where <code>words[i]</code> is a non-empty string, and move <strong>any</strong> character from <code>words[i]</code> to <strong>any</strong> position in <code>words[j]</code>.</p>

<p>Return <code>true</code> <em>if you can make<strong> every</strong> string in </em><code>words</code><em> <strong>equal </strong>using <strong>any</strong> number of operations</em>,<em> and </em><code>false</code> <em>otherwise</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> words = [&quot;abc&quot;,&quot;aabc&quot;,&quot;bc&quot;]
<strong>Output:</strong> true
<strong>Explanation:</strong> Move the first &#39;a&#39; in <code>words[1] to the front of words[2],
to make </code><code>words[1]</code> = &quot;abc&quot; and words[2] = &quot;abc&quot;.
All the strings are now equal to &quot;abc&quot;, so return <code>true</code>.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> words = [&quot;ab&quot;,&quot;a&quot;]
<strong>Output:</strong> false
<strong>Explanation:</strong> It is impossible to make all the strings equal using the operation.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 100</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 100</code></li>
	<li><code>words[i]</code> consists of lowercase English letters.</li>
</ul>

<!-- description:end -->

## Solutions

<!-- solution:start -->

### Solution 1: Counting

According to the problem description, as long as the occurrence count of each character can be divided by the length of the string array, it is possible to redistribute the characters to make all strings equal.

Therefore, we use a hash table or an integer array of length $26$ $\textit{cnt}$ to count the occurrences of each character. Finally, we check if the occurrence count of each character can be divided by the length of the string array.

The time complexity is $O(L)$, and the space complexity is $O(|\Sigma|)$. Here, $L$ is the total length of all strings in the array $\textit{words}$, and $\Sigma$ is the character set, which is the set of lowercase letters, so $|\Sigma|=26$.

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



#### Rust



<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->

{{< tabs id >}}
{{% tab "python" %}}
```python
class Solution:
    def makeEqual(self, words: List[str]) -> bool:
        cnt = Counter()
        for w in words:
            for c in w:
                cnt[c] += 1
        n = len(words)
        return all(v % n == 0 for v in cnt.values())
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean makeEqual(String[] words) {
        int[] cnt = new int[26];
        for (var w : words) {
            for (char c : w.toCharArray()) {
                ++cnt[c - 'a'];
            }
        }
        int n = words.length;
        for (int v : cnt) {
            if (v % n != 0) {
                return false;
            }
        }
        return true;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int cnt[26]{};
        for (const auto& w : words) {
            for (const auto& c : w) {
                ++cnt[c - 'a'];
            }
        }
        int n = words.size();
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] % n != 0) {
                return false;
            }
        }
        return true;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func makeEqual(words []string) bool {
	cnt := [26]int{}
	for _, w := range words {
		for _, c := range w {
			cnt[c-'a']++
		}
	}
	n := len(words)
	for _, v := range cnt {
		if v%n != 0 {
			return false
		}
	}
	return true
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function makeEqual(words: string[]): boolean {
    const cnt: Record<string, number> = {};
    for (const w of words) {
        for (const c of w) {
            cnt[c] = (cnt[c] || 0) + 1;
        }
    }
    const n = words.length;
    return Object.values(cnt).every(v => v % n === 0);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn make_equal(words: Vec<String>) -> bool {
        let mut cnt = std::collections::HashMap::new();

        for word in words.iter() {
            for c in word.chars() {
                *cnt.entry(c).or_insert(0) += 1;
            }
        }

        let n = words.len();
        cnt.values().all(|&v| v % n == 0)
    }
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def makeEqual(self, words: List[str]) -> bool:
        cnt = Counter()
        for w in words:
            for c in w:
                cnt[c] += 1
        n = len(words)
        return all(v % n == 0 for v in cnt.values())
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public boolean makeEqual(String[] words) {
        int[] cnt = new int[26];
        for (var w : words) {
            for (char c : w.toCharArray()) {
                ++cnt[c - 'a'];
            }
        }
        int n = words.length;
        for (int v : cnt) {
            if (v % n != 0) {
                return false;
            }
        }
        return true;
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
    bool makeEqual(vector<string>& words) {
        int cnt[26]{};
        for (const auto& w : words) {
            for (const auto& c : w) {
                ++cnt[c - 'a'];
            }
        }
        int n = words.size();
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] % n != 0) {
                return false;
            }
        }
        return true;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}