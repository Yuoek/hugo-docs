---
title: "2169_CountOperationstoObtainZero"
date: 2025-10-06T00:42:37+08:00
weight: 2169
tags: [数学, 模拟]
---


{{< katex />}}

{{< badge title="Difficulty" value="简单" >}}

<!-- problem:start -->

# [2169. 得到 0 的操作数](https://leetcode.cn/problems/count-operations-to-obtain-zero)

[English Version](../en/2169-69/2169_CountOperationstoObtainZero)

## 题目描述

<!-- description:start -->

<p>给你两个 <strong>非负</strong> 整数 <code>num1</code> 和 <code>num2</code> 。</p>

<p>每一步 <strong>操作</strong>&nbsp;中，如果 <code>num1 &gt;= num2</code> ，你必须用 <code>num1</code> 减 <code>num2</code> ；否则，你必须用 <code>num2</code> 减 <code>num1</code> 。</p>

<ul>
	<li>例如，<code>num1 = 5</code> 且 <code>num2 = 4</code> ，应该用&nbsp;<code>num1</code> 减 <code>num2</code> ，因此，得到 <code>num1 = 1</code> 和 <code>num2 = 4</code> 。然而，如果 <code>num1 = 4</code>且 <code>num2 = 5</code> ，一步操作后，得到 <code>num1 = 4</code> 和 <code>num2 = 1</code> 。</li>
</ul>

<p>返回使 <code>num1 = 0</code> 或 <code>num2 = 0</code> 的 <strong>操作数</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>num1 = 2, num2 = 3
<strong>输出：</strong>3
<strong>解释：</strong>
- 操作 1 ：num1 = 2 ，num2 = 3 。由于 num1 &lt; num2 ，num2 减 num1 得到 num1 = 2 ，num2 = 3 - 2 = 1 。
- 操作 2 ：num1 = 2 ，num2 = 1 。由于 num1 &gt; num2 ，num1 减 num2 。
- 操作 3 ：num1 = 1 ，num2 = 1 。由于 num1 == num2 ，num1 减 num2 。
此时 num1 = 0 ，num2 = 1 。由于 num1 == 0 ，不需要再执行任何操作。
所以总操作数是 3 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>num1 = 10, num2 = 10
<strong>输出：</strong>1
<strong>解释：</strong>
- 操作 1 ：num1 = 10 ，num2 = 10 。由于 num1 == num2 ，num1 减 num2 得到 num1 = 10 - 10 = 0 。
此时 num1 = 0 ，num2 = 10 。由于 num1 == 0 ，不需要再执行任何操作。
所以总操作数是 1 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= num1, num2 &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：模拟

我们可以直接模拟这个过程，循环执行以下操作：

-   如果 $\textit{num1} \ge \textit{num2}$，则 $\textit{num1} = \textit{num1} - \textit{num2}$；
-   否则，$\textit{num2} = \textit{num2} - \textit{num1}$。
-   每执行一次操作，操作数加一。

当 $\textit{num1}$ 或 $\textit{num2}$ 有一个为 $0$ 时，停止循环，返回操作数。

时间复杂度 $O(m)$，其中 $m$ 为 $\textit{num1}$ 和 $\textit{num2}$ 的最大值。空间复杂度 $O(1)$。

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

### 方法二：数学

如果按照方法一的模拟过程，我们会发现，如果 $\textit{num1}$ 远大于 $\textit{num2}$，那么每次操作我们都会减少 $\textit{num1}$ 的值，这样会导致操作数过多。我们可以优化这个过程，每次操作时，我们可以直接将 $\textit{num1}$ 除以 $\textit{num2}$ 的商加到答案中，然后将 $\textit{num1}$ 对 $\textit{num2}$ 取余，这样可以减少操作数。

时间复杂度 $O(\log m)$，其中 $m$ 为 $\textit{num1}$ 和 $\textit{num2}$ 的最大值。空间复杂度 $O(1)$。

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
    def countOperations(self, num1: int, num2: int) -> int:
        ans = 0
        while num1 and num2:
            if num1 >= num2:
                ans += num1 // num2
                num1 %= num2
            else:
                ans += num2 // num1
                num2 %= num1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countOperations(int num1, int num2) {
        int ans = 0;
        while (num1 != 0 && num2 != 0) {
            if (num1 >= num2) {
                ans += num1 / num2;
                num1 %= num2;
            } else {
                ans += num2 / num1;
                num2 %= num1;
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
    int countOperations(int num1, int num2) {
        int ans = 0;
        while (num1 && num2) {
            if (num1 >= num2) {
                ans += num1 / num2;
                num1 %= num2;
            } else {
                ans += num2 / num1;
                num2 %= num1;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countOperations(num1 int, num2 int) (ans int) {
	for num1 != 0 && num2 != 0 {
		if num1 >= num2 {
			ans += num1 / num2
			num1 %= num2
		} else {
			ans += num2 / num1
			num2 %= num1
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countOperations(num1: number, num2: number): number {
    let ans = 0;
    while (num1 && num2) {
        if (num1 >= num2) {
            ans += (num1 / num2) | 0;
            num1 %= num2;
        } else {
            ans += (num2 / num1) | 0;
            num2 %= num1;
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn count_operations(mut num1: i32, mut num2: i32) -> i32 {
        let mut ans = 0;
        while num1 != 0 && num2 != 0 {
            if num1 >= num2 {
                ans += num1 / num2;
                num1 %= num2;
            } else {
                ans += num2 / num1;
                num2 %= num1;
            }
        }
        ans
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number} num1
 * @param {number} num2
 * @return {number}
 */
var countOperations = function (num1, num2) {
    let ans = 0;
    while (num1 && num2) {
        if (num1 >= num2) {
            ans += (num1 / num2) | 0;
            num1 %= num2;
        } else {
            ans += (num2 / num1) | 0;
            num2 %= num1;
        }
    }
    return ans;
};
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def countOperations(self, num1: int, num2: int) -> int:
        ans = 0
        while num1 and num2:
            if num1 >= num2:
                ans += num1 // num2
                num1 %= num2
            else:
                ans += num2 // num1
                num2 %= num1
        return ans
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public int countOperations(int num1, int num2) {
        int ans = 0;
        while (num1 != 0 && num2 != 0) {
            if (num1 >= num2) {
                ans += num1 / num2;
                num1 %= num2;
            } else {
                ans += num2 / num1;
                num2 %= num1;
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
    int countOperations(int num1, int num2) {
        int ans = 0;
        while (num1 && num2) {
            if (num1 >= num2) {
                ans += num1 / num2;
                num1 %= num2;
            } else {
                ans += num2 / num1;
                num2 %= num1;
            }
        }
        return ans;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}