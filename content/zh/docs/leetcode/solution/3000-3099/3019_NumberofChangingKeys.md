---
title: "3019_NumberofChangingKeys"
date: 2025-10-06T00:42:37+08:00
weight: 3019
tags: [字符串]
---


{{< katex />}}

{{< badge title="Difficulty" value="简单" >}}

<!-- problem:start -->

# [3019. 按键变更的次数](https://leetcode.cn/problems/number-of-changing-keys)

[English Version](../en/3019-19/3019_NumberofChangingKeys)

## 题目描述

<!-- description:start -->

<p>给你一个下标从<strong> 0</strong> 开始的字符串 <code>s</code> ，该字符串由用户输入。按键变更的定义是：使用与上次使用的按键不同的键。例如 <code>s = "ab"</code> 表示按键变更一次，而 <code>s = "bBBb"</code> 不存在按键变更。</p>

<p>返回用户输入过程中按键变更的次数。</p>

<p><strong>注意：</strong><code>shift</code> 或 <code>caps lock</code> 等修饰键不计入按键变更，也就是说，如果用户先输入字母 <code>'a'</code> 然后输入字母 <code>'A'</code> ，不算作按键变更。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "aAbBcC"
<strong>输出：</strong>2
<strong>解释：</strong> 
从 s[0] = 'a' 到 s[1] = 'A'，不存在按键变更，因为不计入 caps lock 或 shift 。
从 s[1] = 'A' 到 s[2] = 'b'，按键变更。
从 s[2] = 'b' 到 s[3] = 'B'，不存在按键变更，因为不计入 caps lock 或 shift 。
从 s[3] = 'B' 到 s[4] = 'c'，按键变更。
从 s[4] = 'c' 到 s[5] = 'C'，不存在按键变更，因为不计入 caps lock 或 shift 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "AaAaAaaA"
<strong>输出：</strong>0
<strong>解释：</strong> 不存在按键变更，因为这个过程中只按下字母 'a' 和 'A' ，不需要进行按键变更。<!-- notionvc: 8849fe75-f31e-41dc-a2e0-b7d33d8427d2 -->
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>s</code> 仅由英文大写字母和小写字母组成。</li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：一次遍历

我们可以遍历字符串，每次判断当前字符的小写形式是否与前一个字符的小写形式相同，如果不同则说明发生了按键变更，将答案加一即可。

时间复杂度 $O(n)$，其中 $n$ 是字符串 $s$ 的长度。空间复杂度 $O(1)$。

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
    def countKeyChanges(self, s: str) -> int:
        return sum(a != b for a, b in pairwise(s.lower()))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countKeyChanges(String s) {
        int ans = 0;
        for (int i = 1; i < s.length(); ++i) {
            if (Character.toLowerCase(s.charAt(i)) != Character.toLowerCase(s.charAt(i - 1))) {
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
    int countKeyChanges(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        int ans = 0;
        for (int i = 1; i < s.size(); ++i) {
            ans += s[i] != s[i - 1];
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countKeyChanges(s string) (ans int) {
	s = strings.ToLower(s)
	for i, c := range s[1:] {
		if byte(c) != s[i] {
			ans++
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countKeyChanges(s: string): number {
    s = s.toLowerCase();
    let ans = 0;
    for (let i = 1; i < s.length; ++i) {
        if (s[i] !== s[i - 1]) {
            ++ans;
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn count_key_changes(s: String) -> i32 {
        let s = s.to_lowercase();
        let bytes = s.as_bytes();
        let mut ans = 0;
        for i in 1..bytes.len() {
            if bytes[i] != bytes[i - 1] {
                ans += 1;
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
    def countKeyChanges(self, s: str) -> int:
        return sum(a != b for a, b in pairwise(s.lower()))
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public int countKeyChanges(String s) {
        int ans = 0;
        for (int i = 1; i < s.length(); ++i) {
            if (Character.toLowerCase(s.charAt(i)) != Character.toLowerCase(s.charAt(i - 1))) {
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
    int countKeyChanges(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        int ans = 0;
        for (int i = 1; i < s.size(); ++i) {
            ans += s[i] != s[i - 1];
        }
        return ans;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}