---
title: "3330_FindtheOriginalTypedStringI"
date: 2025-10-06T00:42:37+08:00
weight: 3330
tags: [字符串]
---


{{< katex />}}

{{< badge title="Difficulty" value="简单" >}}

<!-- problem:start -->

# [3330. 找到初始输入字符串 I](https://leetcode.cn/problems/find-the-original-typed-string-i)

[English Version](../en/3330-30/3330_FindtheOriginalTypedStringI)

## 题目描述

<!-- description:start -->

<p>Alice 正在她的电脑上输入一个字符串。但是她打字技术比较笨拙，她&nbsp;<strong>可能</strong>&nbsp;在一个按键上按太久，导致一个字符被输入&nbsp;<strong>多次</strong>&nbsp;。</p>

<p>尽管 Alice 尽可能集中注意力，她仍然可能会犯错 <strong>至多</strong>&nbsp;一次。</p>

<p>给你一个字符串&nbsp;<code>word</code> ，它表示 <strong>最终</strong>&nbsp;显示在 Alice 显示屏上的结果。</p>

<p>请你返回 Alice 一开始可能想要输入字符串的总方案数。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>word = "abbcccc"</span></p>

<p><span class="example-io"><b>输出：</b>5</span></p>

<p><strong>解释：</strong></p>

<p>可能的字符串包括：<code>"abbcccc"</code>&nbsp;，<code>"abbccc"</code>&nbsp;，<code>"abbcc"</code>&nbsp;，<code>"abbc"</code>&nbsp;和&nbsp;<code>"abcccc"</code>&nbsp;。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>word = "abcd"</span></p>

<p><span class="example-io"><b>输出：</b>1</span></p>

<p><strong>解释：</strong></p>

<p>唯一可能的字符串是&nbsp;<code>"abcd"</code>&nbsp;。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>word = "aaaa"</span></p>

<p><span class="example-io"><b>输出：</b>4</span></p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= word.length &lt;= 100</code></li>
	<li><code>word</code>&nbsp;只包含小写英文字母。</li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：直接遍历

根据题目描述，如果所有相邻字符都不相同，那么只有 1 种可能的输入字符串；如果有 1 对相邻字符相同，例如 "abbc"，那么可能的输入字符串有 2 种："abc" 和 "abbc"。

依此类推，如果有 $k$ 对相邻字符相同，那么可能的输入字符串有 $k + 1$ 种。

因此，我们只需要遍历字符串，统计相邻字符相同的对数再加 1 即可。

时间复杂度 $O(n)$，其中 $n$ 为字符串的长度。空间复杂度 $O(1)$。

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
    def possibleStringCount(self, word: str) -> int:
        return 1 + sum(x == y for x, y in pairwise(word))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int possibleStringCount(String word) {
        int f = 1;
        for (int i = 1; i < word.length(); ++i) {
            if (word.charAt(i) == word.charAt(i - 1)) {
                ++f;
            }
        }
        return f;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int possibleStringCount(string word) {
        int f = 1;
        for (int i = 1; i < word.size(); ++i) {
            f += word[i] == word[i - 1];
        }
        return f;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func possibleStringCount(word string) int {
	f := 1
	for i := 1; i < len(word); i++ {
		if word[i] == word[i-1] {
			f++
		}
	}
	return f
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function possibleStringCount(word: string): number {
    let f = 1;
    for (let i = 1; i < word.length; ++i) {
        f += word[i] === word[i - 1] ? 1 : 0;
    }
    return f;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn possible_string_count(word: String) -> i32 {
        1 + word.as_bytes().windows(2).filter(|w| w[0] == w[1]).count() as i32
    }
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def possibleStringCount(self, word: str) -> int:
        return 1 + sum(x == y for x, y in pairwise(word))
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public int possibleStringCount(String word) {
        int f = 1;
        for (int i = 1; i < word.length(); ++i) {
            if (word.charAt(i) == word.charAt(i - 1)) {
                ++f;
            }
        }
        return f;
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
    int possibleStringCount(string word) {
        int f = 1;
        for (int i = 1; i < word.size(); ++i) {
            f += word[i] == word[i - 1];
        }
        return f;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}