---
title: "2309_GreatestEnglishLetterinUpperandLowerCase"
date: 2025-10-06T00:42:37+08:00
weight: 2309
tags: [哈希表, 字符串, 枚举]
---


{{< katex />}}

{{< badge title="Difficulty" value="简单" >}}

<!-- problem:start -->

# [2309. 兼具大小写的最好英文字母](https://leetcode.cn/problems/greatest-english-letter-in-upper-and-lower-case)

[English Version](../en/2309-09/2309_GreatestEnglishLetterinUpperandLowerCase)

## 题目描述

<!-- description:start -->

<p>给你一个由英文字母组成的字符串 <code>s</code> ，请你找出并返回 <code>s</code> 中的 <strong>最好</strong> 英文字母。返回的字母必须为大写形式。如果不存在满足条件的字母，则返回一个空字符串。</p>

<p><strong>最好</strong> 英文字母的大写和小写形式必须 <strong>都</strong> 在 <code>s</code> 中出现。</p>

<p>英文字母 <code>b</code> 比另一个英文字母&nbsp;<code>a</code>&nbsp;<strong>更好</strong> 的前提是：英文字母表中，<code>b</code> 在 <code>a</code> 之 <strong>后</strong> 出现。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "l<em><strong>Ee</strong></em>TcOd<em><strong>E</strong></em>"
<strong>输出：</strong>"E"
<strong>解释：</strong>
字母 'E' 是唯一一个大写和小写形式都出现的字母。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "a<em><strong>rR</strong></em>AzFif"
<strong>输出：</strong>"R"
<strong>解释：</strong>
字母 'R' 是大写和小写形式都出现的最好英文字母。
注意 'A' 和 'F' 的大写和小写形式也都出现了，但是 'R' 比 'F' 和 'A' 更好。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "AbCdEfGhIjK"
<strong>输出：</strong>""
<strong>解释：</strong>
不存在大写和小写形式都出现的字母。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s</code> 由小写和大写英文字母组成</li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：哈希表 + 枚举

我们先用哈希表 $ss$ 记录字符串 $s$ 中出现的所有字母，然后从大写字母表的最后一个字母开始枚举，如果当前字母的大写和小写形式都在 $ss$ 中，则返回该字母。

枚举结束后，如果没有找到符合条件的字母，则返回空字符串。

时间复杂度 $O(n)$，空间复杂度 $O(C)$。其中 $n$ 和 $C$ 分别是字符串 $s$ 的长度和字符集的大小。

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



#### Rust



#### JavaScript



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：位运算（空间优化）

我们可以用两个整数 $mask1$ 和 $mask2$ 分别记录字符串 $s$ 中出现的小写字母和大写字母，其中 $mask1$ 的第 $i$ 位表示第 $i$ 个小写字母是否出现，而 $mask2$ 的第 $i$ 位表示第 $i$ 个大写字母是否出现。

然后我们将 $mask1$ 和 $mask2$ 进行与运算，得到的结果 $mask$ 的第 $i$ 位表示第 $i$ 个字母的大小写是否同时出现。

接下来我们只要获取 $mask$ 的二进制表示中最高位的 $1$ 的位置，将其转换为对应的大写字母即可。如果所有二进制位都不为 $1$，说明不存在大小写同时出现的字母，返回空字符串。

时间复杂度 $O(n)$，其中 $n$ 是字符串 $s$ 的长度。空间复杂度 $O(1)$。

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
    def greatestLetter(self, s: str) -> str:
        mask1 = mask2 = 0
        for c in s:
            if c.islower():
                mask1 |= 1 << (ord(c) - ord("a"))
            else:
                mask2 |= 1 << (ord(c) - ord("A"))
        mask = mask1 & mask2
        return chr(mask.bit_length() - 1 + ord("A")) if mask else ""
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String greatestLetter(String s) {
        int mask1 = 0, mask2 = 0;
        for (int i = 0; i < s.length(); ++i) {
            char c = s.charAt(i);
            if (Character.isLowerCase(c)) {
                mask1 |= 1 << (c - 'a');
            } else {
                mask2 |= 1 << (c - 'A');
            }
        }
        int mask = mask1 & mask2;
        return mask > 0 ? String.valueOf((char) (31 - Integer.numberOfLeadingZeros(mask) + 'A'))
                        : "";
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string greatestLetter(string s) {
        int mask1 = 0, mask2 = 0;
        for (char& c : s) {
            if (islower(c)) {
                mask1 |= 1 << (c - 'a');
            } else {
                mask2 |= 1 << (c - 'A');
            }
        }
        int mask = mask1 & mask2;
        return mask ? string(1, 31 - __builtin_clz(mask) + 'A') : "";
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func greatestLetter(s string) string {
	mask1, mask2 := 0, 0
	for _, c := range s {
		if unicode.IsLower(c) {
			mask1 |= 1 << (c - 'a')
		} else {
			mask2 |= 1 << (c - 'A')
		}
	}
	mask := mask1 & mask2
	if mask == 0 {
		return ""
	}
	return string(byte(bits.Len(uint(mask))-1) + 'A')
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function greatestLetter(s: string): string {
    const ss = new Array(128).fill(false);
    for (const c of s) {
        ss[c.charCodeAt(0)] = true;
    }
    for (let i = 90; i >= 65; --i) {
        if (ss[i] && ss[i + 32]) {
            return String.fromCharCode(i);
        }
    }
    return '';
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn greatest_letter(s: String) -> String {
        let mut arr = [0; 26];
        for &c in s.as_bytes().iter() {
            if c >= b'a' {
                arr[(c - b'a') as usize] |= 1;
            } else {
                arr[(c - b'A') as usize] |= 2;
            }
        }
        for i in (0..26).rev() {
            if arr[i] == 3 {
                return char::from(b'A' + (i as u8)).to_string();
            }
        }
        "".to_string()
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {string} s
 * @return {string}
 */
var greatestLetter = function (s) {
    const ss = new Array(128).fill(false);
    for (const c of s) {
        ss[c.charCodeAt(0)] = true;
    }
    for (let i = 90; i >= 65; --i) {
        if (ss[i] && ss[i + 32]) {
            return String.fromCharCode(i);
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
    def greatestLetter(self, s: str) -> str:
        mask1 = mask2 = 0
        for c in s:
            if c.islower():
                mask1 |= 1 << (ord(c) - ord("a"))
            else:
                mask2 |= 1 << (ord(c) - ord("A"))
        mask = mask1 & mask2
        return chr(mask.bit_length() - 1 + ord("A")) if mask else ""
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public String greatestLetter(String s) {
        int mask1 = 0, mask2 = 0;
        for (int i = 0; i < s.length(); ++i) {
            char c = s.charAt(i);
            if (Character.isLowerCase(c)) {
                mask1 |= 1 << (c - 'a');
            } else {
                mask2 |= 1 << (c - 'A');
            }
        }
        int mask = mask1 & mask2;
        return mask > 0 ? String.valueOf((char) (31 - Integer.numberOfLeadingZeros(mask) + 'A'))
                        : "";
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
    string greatestLetter(string s) {
        int mask1 = 0, mask2 = 0;
        for (char& c : s) {
            if (islower(c)) {
                mask1 |= 1 << (c - 'a');
            } else {
                mask2 |= 1 << (c - 'A');
            }
        }
        int mask = mask1 & mask2;
        return mask ? string(1, 31 - __builtin_clz(mask) + 'A') : "";
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}