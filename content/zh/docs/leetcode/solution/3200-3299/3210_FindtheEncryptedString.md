---
title: "3210_FindtheEncryptedString"
date: 2025-10-06T00:42:37+08:00
weight: 3210
tags: [字符串]
---


{{< katex />}}

{{< badge title="Difficulty" value="简单" >}}

<!-- problem:start -->

# [3210. 找出加密后的字符串](https://leetcode.cn/problems/find-the-encrypted-string)

[English Version](../en/3210-10/3210_FindtheEncryptedString)

## 题目描述

<!-- description:start -->

<p>给你一个字符串 <code>s</code> 和一个整数 <code>k</code>。请你使用以下算法加密字符串：</p>

<ul>
	<li>对于字符串 <code>s</code> 中的每个字符 <code>c</code>，用字符串中 <code>c</code> 后面的第 <code>k</code> 个字符替换 <code>c</code>（以循环方式）。</li>
</ul>

<p>返回加密后的字符串。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">s = "dart", k = 3</span></p>

<p><strong>输出：</strong> <span class="example-io">"tdar"</span></p>

<p><strong>解释：</strong></p>

<ul>
	<li>对于 <code>i = 0</code>，<code>'d'</code> 后面的第 3 个字符是 <code>'t'</code>。</li>
	<li>对于 <code>i = 1</code>，<code>'a'</code> 后面的第 3 个字符是 <code>'d'</code>。</li>
	<li>对于 <code>i = 2</code>，<code>'r'</code> 后面的第 3 个字符是 <code>'a'</code>。</li>
	<li>对于 <code>i = 3</code>，<code>'t'</code> 后面的第 3 个字符是 <code>'r'</code>。</li>
</ul>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">s = "aaa", k = 1</span></p>

<p><strong>输出：</strong> <span class="example-io">"aaa"</span></p>

<p><strong>解释：</strong></p>

<p>由于所有字符都相同，加密后的字符串也将相同。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>4</sup></code></li>
	<li><code>s</code> 仅由小写英文字母组成。</li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：模拟

我们可以使用模拟的方法，对字符串的第 $i$ 个字符，我们将其替换为字符串的第 $(i + k) \bmod n$ 个字符。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是字符串 $s$ 的长度。

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
    def getEncryptedString(self, s: str, k: int) -> str:
        cs = list(s)
        n = len(s)
        for i in range(n):
            cs[i] = s[(i + k) % n]
        return "".join(cs)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String getEncryptedString(String s, int k) {
        char[] cs = s.toCharArray();
        int n = cs.length;
        for (int i = 0; i < n; ++i) {
            cs[i] = s.charAt((i + k) % n);
        }
        return new String(cs);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string getEncryptedString(string s, int k) {
        int n = s.length();
        string cs(n, ' ');
        for (int i = 0; i < n; ++i) {
            cs[i] = s[(i + k) % n];
        }
        return cs;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func getEncryptedString(s string, k int) string {
	cs := []byte(s)
	for i := range s {
		cs[i] = s[(i+k)%len(s)]
	}
	return string(cs)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function getEncryptedString(s: string, k: number): string {
    const cs: string[] = [];
    const n = s.length;
    for (let i = 0; i < n; ++i) {
        cs[i] = s[(i + k) % n];
    }
    return cs.join('');
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def getEncryptedString(self, s: str, k: int) -> str:
        cs = list(s)
        n = len(s)
        for i in range(n):
            cs[i] = s[(i + k) % n]
        return "".join(cs)
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public String getEncryptedString(String s, int k) {
        char[] cs = s.toCharArray();
        int n = cs.length;
        for (int i = 0; i < n; ++i) {
            cs[i] = s.charAt((i + k) % n);
        }
        return new String(cs);
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
    string getEncryptedString(string s, int k) {
        int n = s.length();
        string cs(n, ' ');
        for (int i = 0; i < n; ++i) {
            cs[i] = s[(i + k) % n];
        }
        return cs;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}