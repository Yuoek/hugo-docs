---
title: "1784_CheckifBinaryStringHasatMostOneSegmentofOnes"
date: 2025-10-06T00:42:37+08:00
weight: 1784
tags: [字符串]
---


{{< katex />}}

{{< badge title="Difficulty" value="简单" >}}

<!-- problem:start -->

# [1784. 检查二进制字符串字段](https://leetcode.cn/problems/check-if-binary-string-has-at-most-one-segment-of-ones)

[English Version](../en/1784-84/1784_CheckifBinaryStringHasatMostOneSegmentofOnes)

## 题目描述

<!-- description:start -->

<p>给你一个二进制字符串 <code>s</code> ，该字符串 <strong>不含前导零</strong> 。</p>

<p>如果 <code>s</code> 包含 <strong>零个或一个由连续的 <code>'1'</code> 组成的字段</strong> ，返回 <code>true</code>​​​ 。否则，返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "1001"
<strong>输出：</strong>false
<strong>解释：</strong>由连续若干个&nbsp;<code>'1'</code> 组成的字段数量为 2，返回 false
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "110"
<strong>输出：</strong>true</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>s[i]</code>​​​​ 为 <code>'0'</code> 或 <code>'1'</code></li>
	<li><code>s[0]</code> 为 <code>'1'</code></li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：0 后面不能有 1

注意到字符串 $s$ 不含前导零，说明 $s$ 以 '1' 开头。

若字符串 $s$ 存在 "01" 串，那么 $s$ 就是形如 "1...01..." 的字符串，此时 $s$ 出现了至少两个连续的 '1' 片段，不满足题意，返回 `false`。

若字符串 $s$ 不存在 "01" 串，那么 $s$ 只能是形如 "1..1000..." 的字符串，此时 $s$ 只有一个连续的 '1' 片段，满足题意，返回 `true`。

因此，只需要判断字符串 $s$ 是否存在 "01" 串即可。

时间复杂度 $O(n)$。其中 $n$ 为字符串 $s$ 的长度。空间复杂度 $O(1)$。

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

### 方法二

<!-- tabs:start -->

#### TypeScript



<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->

{{< tabs id >}}
{{% tab "python" %}}
```python
class Solution:
    def checkOnesSegment(self, s: str) -> bool:
        return '01' not in s
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean checkOnesSegment(String s) {
        return !s.contains("01");
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool checkOnesSegment(string s) {
        return s.find("01") == -1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func checkOnesSegment(s string) bool {
	return !strings.Contains(s, "01")
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function checkOnesSegment(s: string): boolean {
    return !s.includes('01');
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn check_ones_segment(s: String) -> bool {
        !s.contains("01")
    }
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def checkOnesSegment(self, s: str) -> bool:
        return '01' not in s
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public boolean checkOnesSegment(String s) {
        return !s.contains("01");
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
    bool checkOnesSegment(string s) {
        return s.find("01") == -1;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}