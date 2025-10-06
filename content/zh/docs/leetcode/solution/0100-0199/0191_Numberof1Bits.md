---
title: "0191_Numberof1Bits"
date: 2025-10-06T00:42:37+08:00
weight: 0191
tags: [位运算, 分治]
---


{{< katex />}}

{{< badge title="Difficulty" value="简单" >}}

<!-- problem:start -->

# [191. 位1的个数](https://leetcode.cn/problems/number-of-1-bits)

[English Version](../en/0191-91/0191_Numberof1Bits)

## 题目描述

<!-- description:start -->

<p>给定一个正整数 <code>n</code>，编写一个函数，获取一个正整数的二进制形式并返回其二进制表达式中 <span data-keyword="set-bit">设置位</span> 的个数（也被称为<a href="https://baike.baidu.com/item/%E6%B1%89%E6%98%8E%E9%87%8D%E9%87%8F" target="_blank">汉明重量</a>）。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 11
<strong>输出：</strong>3
<strong>解释：</strong>输入的二进制串 <code><strong>1011</strong>&nbsp;中，共有 3 个设置位。</code>
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 128
<strong>输出：</strong>1
<strong>解释：</strong>输入的二进制串 <strong>10000000</strong>&nbsp;中，共有 1 个设置位。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 2147483645
<strong>输出：</strong>30
<strong>解释：</strong>输入的二进制串 <strong>1111111111111111111111111111101</strong> 中，共有 30 个设置位。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 2<sup>31</sup> - 1</code></li>
</ul>

<ul>
</ul>

<p>&nbsp;</p>

<p><strong>进阶</strong>：</p>

<ul>
	<li>如果多次调用这个函数，你将如何优化你的算法？</li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：位运算

利用 `n & (n - 1)` 消除 `n` 中最后一位 1 这一特点，优化过程：



以 5 为例，演示推演过程：



<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



#### Rust



#### JavaScript



#### C



#### Kotlin



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：lowbit

`x -= (x & -x)` 可以消除二进制形式的最后一位 1。

同 [剑指 Offer 15. 二进制中 1 的个数](https://github.com/doocs/leetcode/blob/main/lcof/面试题15.%20二进制中1的个数/README.md)

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



#### Rust



#### JavaScript



#### Kotlin



<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->

{{< tabs id >}}
{{% tab "txt" %}}
```txt
[0, 1, 0, 1] // 5
[0, 1, 0, 0] // 5 - 1 = 4
[0, 1, 0, 0] // 5 & 4 = 4

[0, 1, 0, 0] // 4
[0, 0, 1, 1] // 4 - 1 = 3
[0, 0, 0, 0] // 4 & 3 = 0
```
{{% /tab %}}
{{% tab "python" %}}
```python
class Solution:
    def hammingWeight(self, n: int) -> int:
        ans = 0
        while n:
            n -= n & -n
            ans += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        int ans = 0;
        while (n != 0) {
            n -= (n & -n);
            ++ans;
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
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while (n) {
            n -= (n & -n);
            ++ans;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func hammingWeight(num uint32) int {
	ans := 0
	for num != 0 {
		num -= (num & -num)
		ans++
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function hammingWeight(n: number): number {
    let count = 0;
    while (n) {
        n -= n & -n;
        count++;
    }
    return count;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn hammingWeight(mut n: u32) -> i32 {
        let mut res = 0;
        while n != 0 {
            n &= n - 1;
            res += 1;
        }
        res
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number} n
 * @return {number}
 */
var hammingWeight = function (n) {
    let count = 0;
    while (n) {
        n -= n & -n;
        count++;
    }
    return count;
};
```
{{% /tab %}}
{{% tab "c" %}}
```c
int hammingWeight(uint32_t n) {
    int ans = 0;
    while (n) {
        n &= n - 1;
        ans++;
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "kotlin" %}}
```kotlin
class Solution {
    fun hammingWeight(n: Int): Int {
        var count = 0
        var num = n
        while (num != 0) {
            num -= num and (-num)
            count++
        }
        return count
    }
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def hammingWeight(self, n: int) -> int:
        ans = 0
        while n:
            n -= n & -n
            ans += 1
        return ans
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        int ans = 0;
        while (n != 0) {
            n -= (n & -n);
            ++ans;
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
int hammingWeight(uint32_t n) {
    int ans = 0;
    while (n) {
        n &= n - 1;
        ans++;
    }
    return ans;
}
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "cpp 可视化" %}}
{{< pythontutor width="100%" height="800" language="cpp" >}}
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while (n) {
            n -= (n & -n);
            ++ans;
        }
        return ans;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}