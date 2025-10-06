---
title: "3438_FindValidPairofAdjacentDigitsinString"
date: 2025-10-06T00:42:37+08:00
weight: 3438
tags: [哈希表, 字符串, 计数]
---


{{< katex />}}

{{< badge title="Difficulty" value="简单" >}}

<!-- problem:start -->

# [3438. 找到字符串中合法的相邻数字](https://leetcode.cn/problems/find-valid-pair-of-adjacent-digits-in-string)

[English Version](../en/3438-38/3438_FindValidPairofAdjacentDigitsinString)

## 题目描述

<!-- description:start -->

<p>给你一个只包含数字的字符串&nbsp;<code>s</code>&nbsp;。如果 <code>s</code>&nbsp;中两个 <strong>相邻</strong>&nbsp;的数字满足以下条件，我们称它们是 <strong>合法的</strong>&nbsp;：</p>

<ul>
	<li>前面的数字 <strong>不等于</strong> 第二个数字。</li>
	<li>两个数字在 <code>s</code>&nbsp;中出现的次数 <strong>恰好</strong>&nbsp;分别等于这个数字本身。</li>
</ul>

<p>请你从左到右遍历字符串 <code>s</code>&nbsp;，并返回最先找到的 <strong>合法</strong>&nbsp;相邻数字。如果这样的相邻数字不存在，请你返回一个空字符串。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>s = "2523533"</span></p>

<p><span class="example-io"><b>输出：</b>"23"</span></p>

<p><strong>解释：</strong></p>

<p>数字&nbsp;<code>'2'</code>&nbsp;出现 2 次，数字&nbsp;<code>'3'</code>&nbsp;出现 3 次。<code>"23"</code>&nbsp;中每个数字在 <code>s</code>&nbsp;中出现的次数都恰好分别等于数字本身。所以输出&nbsp;<code>"23"</code>&nbsp;。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>s = "221"</span></p>

<p><span class="example-io"><b>输出：</b>"21"</span></p>

<p><strong>解释：</strong></p>

<p>数字&nbsp;<code>'2'</code>&nbsp;出现 2 次，数字&nbsp;<code>'1'</code>&nbsp;出现 1 次。所以输出&nbsp;<code>"21"</code>&nbsp;。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>s = "22"</span></p>

<p><span class="example-io"><b>输出：</b>""</span></p>

<p><strong>解释：</strong></p>

<p>没有合法的相邻数字。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= s.length &lt;= 100</code></li>
	<li><code>s</code>&nbsp;只包含&nbsp;<code>'1'</code> 到&nbsp;<code>'9'</code> 的数字。</li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：计数

我们可以用一个长度为 $10$ 的数组 $\textit{cnt}$ 记录字符串 $\textit{s}$ 中每个数字出现的次数。

然后我们遍历字符串 $\textit{s}$ 中的相邻数字对，如果这两个数字不相等且满足这两个数字出现的次数分别等于这两个数字本身，我们就找到了一个合法的相邻数字对，返回即可。

遍历结束后，如果没有找到合法的相邻数字对，我们返回一个空字符串。

时间复杂度 $O(n)$，其中 $n$ 为字符串 $\textit{s}$ 的长度。空间复杂度 $O(|\Sigma|)$，其中 $\Sigma$ 为字符串 $\textit{s}$ 中出现的字符集，本题中 $\Sigma = \{1, 2, \ldots, 9\}$。

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
    def findValidPair(self, s: str) -> str:
        cnt = [0] * 10
        for x in map(int, s):
            cnt[x] += 1
        for x, y in pairwise(map(int, s)):
            if x != y and cnt[x] == x and cnt[y] == y:
                return f"{x}{y}"
        return ""
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String findValidPair(String s) {
        int[] cnt = new int[10];
        for (char c : s.toCharArray()) {
            ++cnt[c - '0'];
        }
        for (int i = 1; i < s.length(); ++i) {
            int x = s.charAt(i - 1) - '0';
            int y = s.charAt(i) - '0';
            if (x != y && cnt[x] == x && cnt[y] == y) {
                return s.substring(i - 1, i + 1);
            }
        }
        return "";
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string findValidPair(string s) {
        int cnt[10]{};
        for (char c : s) {
            ++cnt[c - '0'];
        }
        for (int i = 1; i < s.size(); ++i) {
            int x = s[i - 1] - '0';
            int y = s[i] - '0';
            if (x != y && cnt[x] == x && cnt[y] == y) {
                return s.substr(i - 1, 2);
            }
        }
        return "";
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findValidPair(s string) string {
	cnt := [10]int{}
	for _, c := range s {
		cnt[c-'0']++
	}
	for i := 1; i < len(s); i++ {
		x, y := int(s[i-1]-'0'), int(s[i]-'0')
		if x != y && cnt[x] == x && cnt[y] == y {
			return s[i-1 : i+1]
		}
	}
	return ""
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findValidPair(s: string): string {
    const cnt: number[] = Array(10).fill(0);
    for (const c of s) {
        ++cnt[+c];
    }
    for (let i = 1; i < s.length; ++i) {
        const x = +s[i - 1];
        const y = +s[i];
        if (x !== y && cnt[x] === x && cnt[y] === y) {
            return `${x}${y}`;
        }
    }
    return '';
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def findValidPair(self, s: str) -> str:
        cnt = [0] * 10
        for x in map(int, s):
            cnt[x] += 1
        for x, y in pairwise(map(int, s)):
            if x != y and cnt[x] == x and cnt[y] == y:
                return f"{x}{y}"
        return ""
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public String findValidPair(String s) {
        int[] cnt = new int[10];
        for (char c : s.toCharArray()) {
            ++cnt[c - '0'];
        }
        for (int i = 1; i < s.length(); ++i) {
            int x = s.charAt(i - 1) - '0';
            int y = s.charAt(i) - '0';
            if (x != y && cnt[x] == x && cnt[y] == y) {
                return s.substring(i - 1, i + 1);
            }
        }
        return "";
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
    string findValidPair(string s) {
        int cnt[10]{};
        for (char c : s) {
            ++cnt[c - '0'];
        }
        for (int i = 1; i < s.size(); ++i) {
            int x = s[i - 1] - '0';
            int y = s[i] - '0';
            if (x != y && cnt[x] == x && cnt[y] == y) {
                return s.substr(i - 1, 2);
            }
        }
        return "";
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}