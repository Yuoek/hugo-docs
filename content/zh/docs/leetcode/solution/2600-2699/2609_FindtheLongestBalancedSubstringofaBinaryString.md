---
title: "2609_FindtheLongestBalancedSubstringofaBinaryString"
date: 2025-10-06T00:42:37+08:00
weight: 2609
tags: [字符串]
---


{{< katex />}}

{{< badge title="Difficulty" value="简单" >}}

<!-- problem:start -->

# [2609. 最长平衡子字符串](https://leetcode.cn/problems/find-the-longest-balanced-substring-of-a-binary-string)

[English Version](../en/2609-09/2609_FindtheLongestBalancedSubstringofaBinaryString)

## 题目描述

<!-- description:start -->

<p>给你一个仅由 <code>0</code> 和 <code>1</code> 组成的二进制字符串 <code>s</code> 。<span style="">&nbsp;</span><span style="">&nbsp;</span></p>

<p>如果子字符串中 <strong>所有的<span style=""> </span></strong><code><span style="">0</span></code><strong><span style=""> </span>都在 </strong><code>1</code><strong> 之前</strong> 且其中 <code>0</code> 的数量等于 <code>1</code> 的数量，则认为 <code>s</code> 的这个子字符串是平衡子字符串。请注意，空子字符串也视作平衡子字符串。<span style="">&nbsp;</span></p>

<p>返回&nbsp;<span style=""> </span><code>s</code> 中最长的平衡子字符串长度。</p>

<p>子字符串是字符串中的一个连续字符序列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "01000111"
<strong>输出：</strong>6
<strong>解释：</strong>最长的平衡子字符串是 "000111" ，长度为 6 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "00111"
<strong>输出：</strong>4
<strong>解释：</strong>最长的平衡子字符串是 "0011" ，长度为 <span style="">&nbsp;</span>4 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "111"
<strong>输出：</strong>0
<strong>解释：</strong>除了空子字符串之外不存在其他平衡子字符串，所以答案为 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 50</code></li>
	<li><code>'0' &lt;= s[i] &lt;= '1'</code></li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：暴力枚举

注意到数据范围很小，因此，我们可以枚举所有的子串 $s[i..j]$，检查其是否为平衡子串，如果是，则更新答案。

时间复杂度 $O(n^3)$，空间复杂度 $O(1)$。其中 $n$ 为字符串 $s$ 的长度。

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

### 方法二：枚举优化

我们用变量 $zero$ 和 $one$ 分别记录当前连续的 $0$ 和 $1$ 的个数。

遍历字符串 $s$，对于当前字符 $c$：

-   如果当前字符为 `'0'`，我们判断此时 $one$ 是否大于 $0$，是则将 $zero$ 和 $one$ 重置为 $0$，接下来将 $zero$ 加 $1$。
-   如果当前字符为 `'1'`，则将 $one$ 加 $1$，并更新答案为 $ans = \max(ans, 2 \times \min(one, zero))$。

遍历结束后，即可得到最长的平衡子串的长度。

时间复杂度 $O(n)$，空间复杂度 $O(1)$。其中 $n$ 为字符串 $s$ 的长度。

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
    def findTheLongestBalancedSubstring(self, s: str) -> int:
        ans = zero = one = 0
        for c in s:
            if c == '0':
                if one:
                    zero = one = 0
                zero += 1
            else:
                one += 1
                ans = max(ans, 2 * min(one, zero))
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int findTheLongestBalancedSubstring(String s) {
        int zero = 0, one = 0;
        int ans = 0, n = s.length();
        for (int i = 0; i < n; ++i) {
            if (s.charAt(i) == '0') {
                if (one > 0) {
                    zero = 0;
                    one = 0;
                }
                ++zero;
            } else {
                ans = Math.max(ans, 2 * Math.min(zero, ++one));
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
    int findTheLongestBalancedSubstring(string s) {
        int zero = 0, one = 0;
        int ans = 0;
        for (char& c : s) {
            if (c == '0') {
                if (one > 0) {
                    zero = 0;
                    one = 0;
                }
                ++zero;
            } else {
                ans = max(ans, 2 * min(zero, ++one));
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findTheLongestBalancedSubstring(s string) (ans int) {
	zero, one := 0, 0
	for _, c := range s {
		if c == '0' {
			if one > 0 {
				zero, one = 0, 0
			}
			zero++
		} else {
			one++
			ans = max(ans, 2*min(zero, one))
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findTheLongestBalancedSubstring(s: string): number {
    let zero = 0;
    let one = 0;
    let ans = 0;
    for (const c of s) {
        if (c === '0') {
            if (one > 0) {
                zero = 0;
                one = 0;
            }
            ++zero;
        } else {
            ans = Math.max(ans, 2 * Math.min(zero, ++one));
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn find_the_longest_balanced_substring(s: String) -> i32 {
        let mut zero = 0;
        let mut one = 0;
        let mut ans = 0;

        for &c in s.as_bytes().iter() {
            if c == b'0' {
                if one > 0 {
                    zero = 0;
                    one = 0;
                }
                zero += 1;
            } else {
                one += 1;
                ans = std::cmp::max(ans, std::cmp::min(zero, one) * 2);
            }
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
    def findTheLongestBalancedSubstring(self, s: str) -> int:
        ans = zero = one = 0
        for c in s:
            if c == '0':
                if one:
                    zero = one = 0
                zero += 1
            else:
                one += 1
                ans = max(ans, 2 * min(one, zero))
        return ans
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public int findTheLongestBalancedSubstring(String s) {
        int zero = 0, one = 0;
        int ans = 0, n = s.length();
        for (int i = 0; i < n; ++i) {
            if (s.charAt(i) == '0') {
                if (one > 0) {
                    zero = 0;
                    one = 0;
                }
                ++zero;
            } else {
                ans = Math.max(ans, 2 * Math.min(zero, ++one));
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
    int findTheLongestBalancedSubstring(string s) {
        int zero = 0, one = 0;
        int ans = 0;
        for (char& c : s) {
            if (c == '0') {
                if (one > 0) {
                    zero = 0;
                    one = 0;
                }
                ++zero;
            } else {
                ans = max(ans, 2 * min(zero, ++one));
            }
        }
        return ans;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}