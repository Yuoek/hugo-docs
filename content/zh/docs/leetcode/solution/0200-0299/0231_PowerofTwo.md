---
title: "0231_PowerofTwo"
date: 2025-10-06T00:42:37+08:00
weight: 0231
tags: [位运算, 递归, 数学]
---


{{< katex />}}

{{< badge title="Difficulty" value="简单" >}}

<!-- problem:start -->

# [231. 2 的幂](https://leetcode.cn/problems/power-of-two)

[English Version](../en/0231-31/0231_PowerofTwo)

## 题目描述

<!-- description:start -->

<p>给你一个整数 <code>n</code>，请你判断该整数是否是 2 的幂次方。如果是，返回 <code>true</code> ；否则，返回 <code>false</code> 。</p>

<p>如果存在一个整数 <code>x</code> 使得&nbsp;<code>n == 2<sup>x</sup></code> ，则认为 <code>n</code> 是 2 的幂次方。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 1
<strong>输出：</strong>true
<strong>解释：</strong>2<sup>0</sup> = 1
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 16
<strong>输出：</strong>true
<strong>解释：</strong>2<sup>4</sup> = 16
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 3
<strong>输出：</strong>false
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>-2<sup>31</sup> &lt;= n &lt;= 2<sup>31</sup> - 1</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>你能够不使用循环/递归解决此问题吗？</p>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：位运算

根据位运算的性质，执行 $\texttt{n\&(n-1)}$ 可以消去二进制形式的 $n$ 的最后一位 $1$。因此，如果 $n \gt 0$，并且满足 $\texttt{n\&(n-1)}$ 结果为 $0$，则说明 $n$ 是 $2$ 的幂。

时间复杂度 $O(1)$，空间复杂度 $O(1)$。

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

### 方法二：Lowbit

根据 $\text{lowbit}$ 的定义，我们知道 $\text{lowbit}(x) = x \& (-x)$，可以得到 $n$ 的最后一位 $1$ 表示的十进制数。因此，如果 $n > 0$，并且满足 $\text{lowbit}(n)$ 等于 $n$，则说明 $n$ 是 $2$ 的幂。

时间复杂度 $O(1)$，空间复杂度 $O(1)$。

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

<!-- problem:end -->

{{< tabs id >}}
{{% tab "python" %}}
```python
class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        return n > 0 and n == n & (-n)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean isPowerOfTwo(int n) {
        return n > 0 && n == (n & (-n));
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && n == (n & (-n));
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func isPowerOfTwo(n int) bool {
	return n > 0 && n == (n&(-n))
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function isPowerOfTwo(n: number): boolean {
    return n > 0 && n === (n & -n);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn is_power_of_two(n: i32) -> bool {
        n > 0 && n == (n & (-n))
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number} n
 * @return {boolean}
 */
var isPowerOfTwo = function (n) {
    return n > 0 && n === (n & -n);
};
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        return n > 0 and n == n & (-n)
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public boolean isPowerOfTwo(int n) {
        return n > 0 && n == (n & (-n));
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
    bool isPowerOfTwo(int n) {
        return n > 0 && n == (n & (-n));
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}