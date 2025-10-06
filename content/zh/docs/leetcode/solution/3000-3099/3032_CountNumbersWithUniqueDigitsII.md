---
title: "3032_CountNumbersWithUniqueDigitsII"
date: 2025-10-06T00:42:37+08:00
weight: 3032
tags: [哈希表, 数学, 动态规划]
---


{{< katex />}}

{{< badge title="Difficulty" value="简单" >}}

<!-- problem:start -->

# [3032. 统计各位数字都不同的数字个数 II 🔒](https://leetcode.cn/problems/count-numbers-with-unique-digits-ii)

[English Version](../en/3032-32/3032_CountNumbersWithUniqueDigitsII)

## 题目描述

<!-- description:start -->

给你两个 <strong>正整数</strong> <code>a</code> 和 <code>b</code> ，返回 <strong>闭区间</strong> <code>[a, b]</code> 内各位数字都不同的数字个数。

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>a = 1, b = 20
<strong>输出：</strong>19
<strong>解释：</strong>除 11 以外，区间 [1, 20] 内的所有数字的各位数字都不同。因此，答案为 19 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>a = 9, b = 19
<strong>输出：</strong>10
<strong>解释：</strong>除 11 以外，区间 [1, 20] 内的所有数字的各位数字都不同。因此，答案为 10 。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>a = 80, b = 120
<strong>输出：</strong>27
<strong>解释：</strong>区间 [80, 120] 内共有 41 个整数，其中 27 个数字的各位数字都不同。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= a &lt;= b &lt;= 1000</code></li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：状态压缩 + 数位 DP

题目要求统计区间 $[a, b]$ 中的数中有多少个数的数位是唯一的，我们可以使用状态压缩和数位 DP 来解决这个问题。

我们可以用一个函数 $f(n)$ 来统计 $[1, n]$ 中的数中有多少个数的数位是唯一的，那么答案就是 $f(b) - f(a - 1)$。

另外，我们可以用一个二进制数来记录数字中出现过的数字，比如数字中出现了 $1, 3, 5$，那么我们可以用 $10101$ 来表示这个状态。

接下来，我们使用记忆化搜索来实现数位 DP。从起点向下搜索，到最底层得到方案数，一层层向上返回答案并累加，最后从搜索起点得到最终的答案。

基本步骤如下：

1. 我们将数字 $n$ 转换为字符串 $num$，其中 $num[0]$ 为最高位，而 $num[len - 1]$ 为最低位。
2. 根据题目信息，设计一个函数 $dfs(pos, mask, limit)$，其中 $pos$ 表示当前处理的位置，$mask$ 表示当前数字中出现过的数字，$limit$ 表示当前位置是否有限制。如果 $limit$ 为真，那么当前位置的数字不能超过 $num[pos]$。

答案为 $dfs(0, 0, true)$。

时间复杂度 $O(m \times 2^{10} \times 10)$，空间复杂度 $O(m \times 2^{10})$。其中 $m$ 为 $b$ 的位数。

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法 2

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->

{{< tabs id >}}
{{% tab "python" %}}
```python
class Solution:
    def numberCount(self, a: int, b: int) -> int:
        return sum(len(set(str(num))) == len(str(num)) for num in range(a, b + 1))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numberCount(int a, int b) {
        int res = 0;
        for (int i = a; i <= b; ++i) {
            if (isValid(i)) {
                ++res;
            }
        }
        return res;
    }
    private boolean isValid(int n) {
        boolean[] present = new boolean[10];
        Arrays.fill(present, false);
        while (n > 0) {
            int dig = n % 10;
            if (present[dig]) {
                return false;
            }
            present[dig] = true;
            n /= 10;
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
    bool isvalid(int n) {
        vector<bool> present(10, false);
        while (n) {
            const int dig = n % 10;
            if (present[dig])
                return false;
            present[dig] = true;
            n /= 10;
        }
        return true;
    }
    int numberCount(int a, int b) {
        int res = 0;
        for (int i = a; i <= b; ++i) {
            if (isvalid(i)) {
                ++res;
            }
        }
        return res;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numberCount(a int, b int) int {
	count := 0
	for num := a; num <= b; num++ {
		if hasUniqueDigits(num) {
			count++
		}
	}
	return count
}
func hasUniqueDigits(num int) bool {
	digits := strconv.Itoa(num)
	seen := make(map[rune]bool)
	for _, digit := range digits {
		if seen[digit] {
			return false
		}
		seen[digit] = true
	}
	return true
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numberCount(a: number, b: number): number {
    let count: number = 0;
    for (let num = a; num <= b; num++) {
        if (hasUniqueDigits(num)) {
            count++;
        }
    }
    return count;
}
function hasUniqueDigits(num: number): boolean {
    const digits: Set<string> = new Set(num.toString().split(''));
    return digits.size === num.toString().length;
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def numberCount(self, a: int, b: int) -> int:
        return sum(len(set(str(num))) == len(str(num)) for num in range(a, b + 1))
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public int numberCount(int a, int b) {
        int res = 0;
        for (int i = a; i <= b; ++i) {
            if (isValid(i)) {
                ++res;
            }
        }
        return res;
    }
    private boolean isValid(int n) {
        boolean[] present = new boolean[10];
        Arrays.fill(present, false);
        while (n > 0) {
            int dig = n % 10;
            if (present[dig]) {
                return false;
            }
            present[dig] = true;
            n /= 10;
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
    bool isvalid(int n) {
        vector<bool> present(10, false);
        while (n) {
            const int dig = n % 10;
            if (present[dig])
                return false;
            present[dig] = true;
            n /= 10;
        }
        return true;
    }
    int numberCount(int a, int b) {
        int res = 0;
        for (int i = a; i <= b; ++i) {
            if (isvalid(i)) {
                ++res;
            }
        }
        return res;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}