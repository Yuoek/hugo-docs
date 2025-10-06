---
title: "1317_ConvertIntegertotheSumofTwoNo-ZeroIntegers"
date: 2025-10-06T00:42:37+08:00
weight: 1317
tags: [数学]
---


{{< katex />}}

{{< badge title="Difficulty" value="简单" >}}

<!-- problem:start -->

# [1317. 将整数转换为两个无零整数的和](https://leetcode.cn/problems/convert-integer-to-the-sum-of-two-no-zero-integers)

[English Version](../en/1317-17/1317_ConvertIntegertotheSumofTwoNo-ZeroIntegers)

## 题目描述

<!-- description:start -->

<p>「无零整数」是十进制表示中 <strong>不含任何 0</strong>&nbsp;的正整数。</p>

<p>给你一个整数&nbsp;<code>n</code>，请你返回一个 <strong>由两个整数组成的列表</strong> <code>[a, b]</code>，满足：</p>

<ul>
	<li><code>a</code> 和 <code>b</code>&nbsp;都是无零整数</li>
	<li><code>a + b = n</code></li>
</ul>

<p>题目数据保证至少有一个有效的解决方案。</p>

<p>如果存在多个有效解决方案，你可以返回其中任意一个。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 2
<strong>输出：</strong>[1,1]
<strong>解释：</strong>a = 1, b = 1。a + b = n 并且 a 和 b 的十进制表示形式都不包含任何 0。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 11
<strong>输出：</strong>[2,9]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 10000
<strong>输出：</strong>[1,9999]
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>n = 69
<strong>输出：</strong>[1,68]
</pre>

<p><strong>示例 5：</strong></p>

<pre>
<strong>输入：</strong>n = 1010
<strong>输出：</strong>[11,999]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：直接枚举

从 $1$ 开始枚举 $a$，那么 $b = n - a$。对于每个 $a$ 和 $b$，我们将它们转换为字符串并且连接起来，然后判断是否包含字符 `'0'`，如果不包含，那么就找到了答案，返回 $[a, b]$。

时间复杂度 $O(n \times \log n)$，其中 $n$ 为题目给定的整数。空间复杂度 $O(\log n)$。

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

### 方法二：直接枚举（另一种写法）

在方法一中，我们将 $a$ 和 $b$ 转换为字符串并且连接起来，然后判断是否包含字符 `'0'`。这里我们可以通过一个函数 $f(x)$ 来判断 $x$ 是否包含字符 `'0'`，然后直接枚举 $a$，判断 $a$ 和 $b = n - a$ 是否都不包含字符 `'0'`，如果是，则找到了答案，返回 $[a, b]$。

时间复杂度 $O(n \times \log n)$，其中 $n$ 为题目给定的整数。空间复杂度 $O(1)$。

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
    def getNoZeroIntegers(self, n: int) -> List[int]:
        def f(x: int) -> bool:
            while x:
                if x % 10 == 0:
                    return False
                x //= 10
            return True

        for a in count(1):
            b = n - a
            if f(a) and f(b):
                return [a, b]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] getNoZeroIntegers(int n) {
        for (int a = 1;; ++a) {
            int b = n - a;
            if (f(a) && f(b)) {
                return new int[] {a, b};
            }
        }
    }

    private boolean f(int x) {
        for (; x > 0; x /= 10) {
            if (x % 10 == 0) {
                return false;
            }
        }
        return true;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        auto f = [](int x) {
            for (; x; x /= 10) {
                if (x % 10 == 0) {
                    return false;
                }
            }
            return true;
        };
        for (int a = 1;; ++a) {
            int b = n - a;
            if (f(a) && f(b)) {
                return {a, b};
            }
        }
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func getNoZeroIntegers(n int) []int {
	f := func(x int) bool {
		for ; x > 0; x /= 10 {
			if x%10 == 0 {
				return false
			}
		}
		return true
	}
	for a := 1; ; a++ {
		b := n - a
		if f(a) && f(b) {
			return []int{a, b}
		}
	}
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function getNoZeroIntegers(n: number): number[] {
    const f = (x: number): boolean => {
        for (; x; x = (x / 10) | 0) {
            if (x % 10 === 0) {
                return false;
            }
        }
        return true;
    };
    for (let a = 1; ; ++a) {
        const b = n - a;
        if (f(a) && f(b)) {
            return [a, b];
        }
    }
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn get_no_zero_integers(n: i32) -> Vec<i32> {
        fn f(mut x: i32) -> bool {
            while x > 0 {
                if x % 10 == 0 {
                    return false;
                }
                x /= 10;
            }
            true
        }

        for a in 1..n {
            let b = n - a;
            if f(a) && f(b) {
                return vec![a, b];
            }
        }
        vec![]
    }
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def getNoZeroIntegers(self, n: int) -> List[int]:
        def f(x: int) -> bool:
            while x:
                if x % 10 == 0:
                    return False
                x //= 10
            return True

        for a in count(1):
            b = n - a
            if f(a) and f(b):
                return [a, b]
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public int[] getNoZeroIntegers(int n) {
        for (int a = 1;; ++a) {
            int b = n - a;
            if (f(a) && f(b)) {
                return new int[] {a, b};
            }
        }
    }

    private boolean f(int x) {
        for (; x > 0; x /= 10) {
            if (x % 10 == 0) {
                return false;
            }
        }
        return true;
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
    vector<int> getNoZeroIntegers(int n) {
        auto f = [](int x) {
            for (; x; x /= 10) {
                if (x % 10 == 0) {
                    return false;
                }
            }
            return true;
        };
        for (int a = 1;; ++a) {
            int b = n - a;
            if (f(a) && f(b)) {
                return {a, b};
            }
        }
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}