---
title: "2255_CountPrefixesofaGivenString"
date: 2025-10-06T00:42:37+08:00
weight: 2255
tags: [数组, 字符串]
---


{{< katex />}}

{{< badge title="Difficulty" value="简单" >}}

<!-- problem:start -->

# [2255. 统计是给定字符串前缀的字符串数目](https://leetcode.cn/problems/count-prefixes-of-a-given-string)

[English Version](../en/2255-55/2255_CountPrefixesofaGivenString)

## 题目描述

<!-- description:start -->

<p>给你一个字符串数组&nbsp;<code>words</code>&nbsp;和一个字符串&nbsp;<code>s</code>&nbsp;，其中&nbsp;<code>words[i]</code> 和&nbsp;<code>s</code>&nbsp;只包含 <strong>小写英文字母</strong>&nbsp;。</p>

<p>请你返回 <code>words</code>&nbsp;中是字符串 <code>s</code>&nbsp;<strong>前缀&nbsp;</strong>的 <strong>字符串数目</strong>&nbsp;。</p>

<p>一个字符串的 <strong>前缀</strong>&nbsp;是出现在字符串开头的子字符串。<strong>子字符串</strong>&nbsp;是一个字符串中的连续一段字符序列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>words = ["a","b","c","ab","bc","abc"], s = "abc"
<b>输出：</b>3
<strong>解释：</strong>
words 中是 s = "abc" 前缀的字符串为：
"a" ，"ab" 和 "abc" 。
所以 words 中是字符串 s 前缀的字符串数目为 3 。</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>words = ["a","a"], s = "aa"
<b>输出：</b>2
<strong>解释：
</strong>两个字符串都是 s 的前缀。
注意，相同的字符串可能在 words 中出现多次，它们应该被计数多次。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 1000</code></li>
	<li><code>1 &lt;= words[i].length, s.length &lt;= 10</code></li>
	<li><code>words[i]</code> 和&nbsp;<code>s</code>&nbsp;<strong>只</strong>&nbsp;包含小写英文字母。</li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：遍历计数

我们直接遍历数组 $\textit{words}$，对于每个字符串 $w$，判断 $s$ 是否以 $w$ 为前缀，如果是则答案加一。

遍历结束后，返回答案即可。

时间复杂度 $O(m \times n)$，其中 $m$ 和 $n$ 分别是数组 $\textit{words}$ 的长度和字符串 $s$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



#### Rust



#### C#



<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->

{{< tabs id >}}
{{% tab "python" %}}
```python
class Solution:
    def countPrefixes(self, words: List[str], s: str) -> int:
        return sum(s.startswith(w) for w in words)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countPrefixes(String[] words, String s) {
        int ans = 0;
        for (String w : words) {
            if (s.startsWith(w)) {
                ++ans;
            }
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
    int countPrefixes(vector<string>& words, string s) {
        int ans = 0;
        for (auto& w : words) {
            ans += s.starts_with(w);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countPrefixes(words []string, s string) (ans int) {
	for _, w := range words {
		if strings.HasPrefix(s, w) {
			ans++
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countPrefixes(words: string[], s: string): number {
    return words.filter(w => s.startsWith(w)).length;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn count_prefixes(words: Vec<String>, s: String) -> i32 {
        words.iter().filter(|w| s.starts_with(w.as_str())).count() as i32
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int CountPrefixes(string[] words, string s) {
        return words.Count(w => s.StartsWith(w));
    }
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def countPrefixes(self, words: List[str], s: str) -> int:
        return sum(s.startswith(w) for w in words)
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public int countPrefixes(String[] words, String s) {
        int ans = 0;
        for (String w : words) {
            if (s.startsWith(w)) {
                ++ans;
            }
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
    int countPrefixes(vector<string>& words, string s) {
        int ans = 0;
        for (auto& w : words) {
            ans += s.starts_with(w);
        }
        return ans;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}