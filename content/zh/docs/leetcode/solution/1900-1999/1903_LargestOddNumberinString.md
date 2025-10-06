---
title: "1903_LargestOddNumberinString"
date: 2025-10-06T00:42:37+08:00
weight: 1903
tags: [贪心, 数学, 字符串]
---


{{< katex />}}

{{< badge title="Difficulty" value="简单" >}}

<!-- problem:start -->

# [1903. 字符串中的最大奇数](https://leetcode.cn/problems/largest-odd-number-in-string)

[English Version](../en/1903-03/1903_LargestOddNumberinString)

## 题目描述

<!-- description:start -->

<p>给你一个字符串 <code>num</code> ，表示一个大整数。请你在字符串 <code>num</code> 的所有 <strong>非空子字符串</strong> 中找出 <strong>值最大的奇数</strong> ，并以字符串形式返回。如果不存在奇数，则返回一个空字符串<em> </em><code>""</code><em> </em>。</p>

<p><strong>子字符串</strong> 是字符串中的一个连续的字符序列。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>num = "52"
<strong>输出：</strong>"5"
<strong>解释：</strong>非空子字符串仅有 "5"、"2" 和 "52" 。"5" 是其中唯一的奇数。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>num = "4206"
<strong>输出：</strong>""
<strong>解释：</strong>在 "4206" 中不存在奇数。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>num = "35427"
<strong>输出：</strong>"35427"
<strong>解释：</strong>"35427" 本身就是一个奇数。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= num.length <= 10<sup>5</sup></code></li>
	<li><code>num</code> 仅由数字组成且不含前导零</li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：逆序遍历

我们可以从后往前遍历字符串，找到第一个奇数，然后返回从开头到该奇数的子字符串即可。如果不存在奇数，则返回空字符串。

时间复杂度 $O(n)$，其中 $n$ 是字符串 $num$ 的长度。忽略答案字符串的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



#### JavaScript



<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->

{{< tabs id >}}
{{% tab "python" %}}
```python
class Solution:
    def largestOddNumber(self, num: str) -> str:
        for i in range(len(num) - 1, -1, -1):
            if (int(num[i]) & 1) == 1:
                return num[: i + 1]
        return ''
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String largestOddNumber(String num) {
        for (int i = num.length() - 1; i >= 0; --i) {
            int c = num.charAt(i) - '0';
            if ((c & 1) == 1) {
                return num.substring(0, i + 1);
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
    string largestOddNumber(string num) {
        for (int i = num.size() - 1; i >= 0; --i) {
            int c = num[i] - '0';
            if ((c & 1) == 1) {
                return num.substr(0, i + 1);
            }
        }
        return "";
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func largestOddNumber(num string) string {
	for i := len(num) - 1; i >= 0; i-- {
		c := num[i] - '0'
		if (c & 1) == 1 {
			return num[:i+1]
		}
	}
	return ""
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function largestOddNumber(num: string): string {
    for (let i = num.length - 1; ~i; --i) {
        if (Number(num[i]) & 1) {
            return num.slice(0, i + 1);
        }
    }
    return '';
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {string} num
 * @return {string}
 */
var largestOddNumber = function (num) {
    for (let i = num.length - 1; ~i; --i) {
        if (Number(num[i]) & 1) {
            return num.slice(0, i + 1);
        }
    }
    return '';
};
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def largestOddNumber(self, num: str) -> str:
        for i in range(len(num) - 1, -1, -1):
            if (int(num[i]) & 1) == 1:
                return num[: i + 1]
        return ''
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public String largestOddNumber(String num) {
        for (int i = num.length() - 1; i >= 0; --i) {
            int c = num.charAt(i) - '0';
            if ((c & 1) == 1) {
                return num.substring(0, i + 1);
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
    string largestOddNumber(string num) {
        for (int i = num.size() - 1; i >= 0; --i) {
            int c = num[i] - '0';
            if ((c & 1) == 1) {
                return num.substr(0, i + 1);
            }
        }
        return "";
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}