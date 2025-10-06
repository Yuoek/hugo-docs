---
title: "2544_AlternatingDigitSum"
date: 2025-10-06T00:42:37+08:00
weight: 2544
tags: [Math]
---


{{< katex />}}

{{< badge title="Difficulty" value="Easy" >}}

<!-- problem:start -->

# [2544. Alternating Digit Sum](https://leetcode.com/problems/alternating-digit-sum)

[中文文档](/solution/2500-2599/2544.Alternating%20Digit%20Sum/README.md)

## Description

<!-- description:start -->

<p>You are given a positive integer <code>n</code>. Each digit of <code>n</code> has a sign according to the following rules:</p>

<ul>
	<li>The <strong>most significant digit</strong> is assigned a <strong>positive</strong> sign.</li>
	<li>Each other digit has an opposite sign to its adjacent digits.</li>
</ul>

<p>Return <em>the sum of all digits with their corresponding sign</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 521
<strong>Output:</strong> 4
<strong>Explanation:</strong> (+5) + (-2) + (+1) = 4.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 111
<strong>Output:</strong> 1
<strong>Explanation:</strong> (+1) + (-1) + (+1) = 1.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> n = 886996
<strong>Output:</strong> 0
<strong>Explanation:</strong> (+8) + (-8) + (+6) + (-9) + (+9) + (-6) = 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>9</sup></code></li>
</ul>

<p>&nbsp;</p>
<style type="text/css">.spoilerbutton {display:block; border:dashed; padding: 0px 0px; margin:10px 0px; font-size:150%; font-weight: bold; color:#000000; background-color:cyan; outline:0; 
}
.spoiler {overflow:hidden;}
.spoiler > div {-webkit-transition: all 0s ease;-moz-transition: margin 0s ease;-o-transition: all 0s ease;transition: margin 0s ease;}
.spoilerbutton[value="Show Message"] + .spoiler > div {margin-top:-500%;}
.spoilerbutton[value="Hide Message"] + .spoiler {padding:5px;}
</style>

<!-- description:end -->

## Solutions

<!-- solution:start -->

### Solution 1: Simulation

We can directly simulate the process as described in the problem.

We define an initial symbol $sign=1$. Starting from the most significant digit, we take out one digit $x$ each time, multiply it by $sign$, add the result to the answer, then negate $sign$, and continue to process the next digit until all digits are processed.

The time complexity is $O(\log n)$, and the space complexity is $O(\log n)$. Here, $n$ is the given number.

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

### Solution 2

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