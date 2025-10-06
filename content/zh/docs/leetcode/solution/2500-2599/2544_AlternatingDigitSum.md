---
title: "2544_AlternatingDigitSum"
date: 2025-10-06T00:42:37+08:00
weight: 2544
tags: [数学]
---


{{< katex />}}

{{< badge title="Difficulty" value="简单" >}}

<!-- problem:start -->

# [2544. 交替数字和](https://leetcode.cn/problems/alternating-digit-sum)

[English Version](../en/2544-44/2544_AlternatingDigitSum)

## 题目描述

<!-- description:start -->

<p>给你一个正整数 <code>n</code> 。<code>n</code> 中的每一位数字都会按下述规则分配一个符号：</p>

<ul>
	<li><strong>最高有效位</strong> 上的数字分配到 <strong>正</strong> 号。</li>
	<li>剩余每位上数字的符号都与其相邻数字相反。</li>
</ul>

<p>返回所有数字及其对应符号的和。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 521
<strong>输出：</strong>4
<strong>解释：</strong>(+5) + (-2) + (+1) = 4</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 111
<strong>输出：</strong>1
<strong>解释：</strong>(+1) + (-1) + (+1) = 1
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 886996
<strong>输出：</strong>0
<strong>解释：</strong>(+8) + (-8) + (+6) + (-9) + (+9) + (-6) = 0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>9</sup></code></li>
</ul>

<p>&nbsp;</p>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：模拟

直接根据题目描述模拟即可。

我们定义一个初始符号 $sign=1$，然后从最高有效位开始，每次取出一位数字 $x$，与 $sign$ 相乘，将结果加到答案中，然后将 $sign$ 取反，继续处理下一位数字，直到处理完所有数字。

时间复杂度 $O(\log n)$，空间复杂度 $O(\log n)$。其中 $n$ 为给定数字。

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



#### Rust



#### C



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### Python3



#### Rust



<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->

{{< tabs id >}}
{{% tab "python" %}}
```python
class Solution:
    def alternateDigitSum(self, n: int) -> int:
        ans, sign = 0, 1
        for c in str(n):
            x = int(c)
            ans += sign * x
            sign *= -1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int alternateDigitSum(int n) {
        int ans = 0, sign = 1;
        for (char c : String.valueOf(n).toCharArray()) {
            int x = c - '0';
            ans += sign * x;
            sign *= -1;
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
    int alternateDigitSum(int n) {
        int ans = 0, sign = 1;
        for (char c : to_string(n)) {
            int x = c - '0';
            ans += sign * x;
            sign *= -1;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func alternateDigitSum(n int) (ans int) {
	sign := 1
	for _, c := range strconv.Itoa(n) {
		x := int(c - '0')
		ans += sign * x
		sign *= -1
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function alternateDigitSum(n: number): number {
    let ans = 0;
    let sign = 1;
    while (n) {
        ans += (n % 10) * sign;
        sign = -sign;
        n = Math.floor(n / 10);
    }
    return ans * -sign;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn alternate_digit_sum(n: i32) -> i32 {
        let mut ans = 0;
        let mut sign = 1;

        for c in format!("{}", n).chars() {
            let x = c.to_digit(10).unwrap() as i32;
            ans += x * sign;
            sign *= -1;
        }

        ans
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
int alternateDigitSum(int n) {
    int ans = 0;
    int sign = 1;
    while (n) {
        ans += (n % 10) * sign;
        sign = -sign;
        n /= 10;
    }
    return ans * -sign;
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def alternateDigitSum(self, n: int) -> int:
        ans, sign = 0, 1
        for c in str(n):
            x = int(c)
            ans += sign * x
            sign *= -1
        return ans
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public int alternateDigitSum(int n) {
        int ans = 0, sign = 1;
        for (char c : String.valueOf(n).toCharArray()) {
            int x = c - '0';
            ans += sign * x;
            sign *= -1;
        }
        return ans;
    }
}
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "c 可视化" %}}
{{< pythontutor width="100%" height="800" language="c" >}}
int alternateDigitSum(int n) {
    int ans = 0;
    int sign = 1;
    while (n) {
        ans += (n % 10) * sign;
        sign = -sign;
        n /= 10;
    }
    return ans * -sign;
}
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "cpp 可视化" %}}
{{< pythontutor width="100%" height="800" language="cpp" >}}
class Solution {
public:
    int alternateDigitSum(int n) {
        int ans = 0, sign = 1;
        for (char c : to_string(n)) {
            int x = c - '0';
            ans += sign * x;
            sign *= -1;
        }
        return ans;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}