---
title: "1837_SumofDigitsinBaseK"
date: 2025-10-06T00:42:37+08:00
weight: 1837
tags: [数学]
---


{{< katex />}}

{{< badge title="Difficulty" value="简单" >}}

<!-- problem:start -->

# [1837. K 进制表示下的各位数字总和](https://leetcode.cn/problems/sum-of-digits-in-base-k)

[English Version](../en/1837-37/1837_SumofDigitsinBaseK)

## 题目描述

<!-- description:start -->

<p>给你一个整数 <code>n</code>（<code>10</code> 进制）和一个基数 <code>k</code> ，请你将 <code>n</code> 从 <code>10</code> 进制表示转换为 <code>k</code> 进制表示，计算并返回转换后各位数字的 <strong>总和</strong> 。</p>

<p>转换后，各位数字应当视作是 <code>10</code> 进制数字，且它们的总和也应当按 <code>10</code> 进制表示返回。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 34, k = 6
<strong>输出：</strong>9
<strong>解释：</strong>34 (10 进制) 在 6 进制下表示为 54 。5 + 4 = 9 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 10, k = 10
<strong>输出：</strong>1
<strong>解释：</strong>n 本身就是 10 进制。 1 + 0 = 1 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= n <= 100</code></li>
	<li><code>2 <= k <= 10</code></li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：数学

我们将 $n$ 除 $k$ 取余，直至为 $0$，余数相加即可得到结果。

时间复杂度 $O(\log_{k}n)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



#### Rust



#### JavaScript



#### C



<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->

{{< tabs id >}}
{{% tab "python" %}}
```python
class Solution:
    def sumBase(self, n: int, k: int) -> int:
        ans = 0
        while n:
            ans += n % k
            n //= k
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int sumBase(int n, int k) {
        int ans = 0;
        while (n != 0) {
            ans += n % k;
            n /= k;
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
    int sumBase(int n, int k) {
        int ans = 0;
        while (n) {
            ans += n % k;
            n /= k;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func sumBase(n int, k int) (ans int) {
	for n > 0 {
		ans += n % k
		n /= k
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function sumBase(n: number, k: number): number {
    let ans = 0;
    while (n) {
        ans += n % k;
        n = Math.floor(n / k);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn sum_base(mut n: i32, k: i32) -> i32 {
        let mut ans = 0;
        while n != 0 {
            ans += n % k;
            n /= k;
        }
        ans
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number} n
 * @param {number} k
 * @return {number}
 */
var sumBase = function (n, k) {
    let ans = 0;
    while (n) {
        ans += n % k;
        n = Math.floor(n / k);
    }
    return ans;
};
```
{{% /tab %}}
{{% tab "c" %}}
```c
int sumBase(int n, int k) {
    int ans = 0;
    while (n) {
        ans += n % k;
        n /= k;
    }
    return ans;
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def sumBase(self, n: int, k: int) -> int:
        ans = 0
        while n:
            ans += n % k
            n //= k
        return ans
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public int sumBase(int n, int k) {
        int ans = 0;
        while (n != 0) {
            ans += n % k;
            n /= k;
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
int sumBase(int n, int k) {
    int ans = 0;
    while (n) {
        ans += n % k;
        n /= k;
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
    int sumBase(int n, int k) {
        int ans = 0;
        while (n) {
            ans += n % k;
            n /= k;
        }
        return ans;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}