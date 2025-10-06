---
title: "0650_2KeysKeyboard"
date: 2025-10-06T00:42:37+08:00
weight: 0650
tags: [数学, 动态规划]
---


{{< katex />}}

{{< badge title="Difficulty" value="中等" >}}

<!-- problem:start -->

# [650. 两个键的键盘](https://leetcode.cn/problems/2-keys-keyboard)

[English Version](../en/0650-50/0650_2KeysKeyboard)

## 题目描述

<!-- description:start -->

<p>最初记事本上只有一个字符 <code>'A'</code> 。你每次可以对这个记事本进行两种操作：</p>

<ul>
	<li><code>Copy All</code>（复制全部）：复制这个记事本中的所有字符（不允许仅复制部分字符）。</li>
	<li><code>Paste</code>（粘贴）：粘贴<strong> 上一次 </strong>复制的字符。</li>
</ul>

<p>给你一个数字&nbsp;<code>n</code> ，你需要使用最少的操作次数，在记事本上输出 <strong>恰好</strong>&nbsp;<code>n</code>&nbsp;个 <code>'A'</code> 。返回能够打印出&nbsp;<code>n</code>&nbsp;个 <code>'A'</code> 的最少操作次数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>3
<strong>输出：</strong>3
<strong>解释：</strong>
最初, 只有一个字符 'A'。
第 1 步, 使用 <strong>Copy All</strong> 操作。
第 2 步, 使用 <strong>Paste </strong>操作来获得 'AA'。
第 3 步, 使用 <strong>Paste</strong> 操作来获得 'AAA'。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 1
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

定义 $dfs(i)$ 为输出 $i$ 个字符的最少操作次数。初始化 `dfs(1)=0`。

当 $i\gt 1$ 时，有：

$$
dfs(i)=\min _{j \mid i} (dfs(\frac{i}{j})+j, i), 2\leq j\lt i
$$

时间复杂度 $O(n\sqrt{n})$。

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：动态规划

记忆化搜索也可以改成动态规划。

$$
dp[i]=\min _{j \mid i} (dp[\frac{i}{j}]+j, i), 2\leq j\lt i
$$

时间复杂度 $O(n\sqrt{n})$。

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



#### JavaScript



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法三

<!-- tabs:start -->

#### Java



<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->

{{< tabs id >}}
{{% tab "python" %}}
```python
class Solution:
    def minSteps(self, n: int) -> int:
        dp = list(range(n + 1))
        dp[1] = 0
        for i in range(2, n + 1):
            j = 2
            while j * j <= i:
                if i % j == 0:
                    dp[i] = min(dp[i], dp[i // j] + j)
                j += 1
        return dp[-1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minSteps(int n) {
        int res = 0;
        for (int i = 2; n > 1; ++i) {
            while (n % i == 0) {
                res += i;
                n /= i;
            }
        }
        return res;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n + 1);
        iota(dp.begin(), dp.end(), 0);
        dp[1] = 0;
        for (int i = 2; i < n + 1; ++i) {
            for (int j = 2; j * j <= i; ++j) {
                if (i % j == 0) {
                    dp[i] = min(dp[i], dp[i / j] + j);
                }
            }
        }
        return dp[n];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minSteps(n int) int {
	dp := make([]int, n+1)
	for i := range dp {
		dp[i] = i
	}
	dp[1] = 0
	for i := 2; i < n+1; i++ {
		for j := 2; j*j <= i; j++ {
			if i%j == 0 {
				dp[i] = min(dp[i], dp[i/j]+j)
			}
		}
	}
	return dp[n]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minSteps(n: number): number {
    const dp = Array(n + 1).fill(1000);
    dp[1] = 0;

    for (let i = 2; i <= n; i++) {
        for (let j = 1, half = i / 2; j <= half; j++) {
            if (i % j === 0) {
                dp[i] = Math.min(dp[i], dp[j] + i / j);
            }
        }
    }

    return dp[n];
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number} n
 * @return {number}
 */
var minSteps = function (n) {
    const dp = Array(n + 1).fill(1000);
    dp[1] = 0;

    for (let i = 2; i <= n; i++) {
        for (let j = 1, half = i / 2; j <= half; j++) {
            if (i % j === 0) {
                dp[i] = Math.min(dp[i], dp[j] + i / j);
            }
        }
    }

    return dp[n];
};
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def minSteps(self, n: int) -> int:
        dp = list(range(n + 1))
        dp[1] = 0
        for i in range(2, n + 1):
            j = 2
            while j * j <= i:
                if i % j == 0:
                    dp[i] = min(dp[i], dp[i // j] + j)
                j += 1
        return dp[-1]
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public int minSteps(int n) {
        int res = 0;
        for (int i = 2; n > 1; ++i) {
            while (n % i == 0) {
                res += i;
                n /= i;
            }
        }
        return res;
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
    int minSteps(int n) {
        vector<int> dp(n + 1);
        iota(dp.begin(), dp.end(), 0);
        dp[1] = 0;
        for (int i = 2; i < n + 1; ++i) {
            for (int j = 2; j * j <= i; ++j) {
                if (i % j == 0) {
                    dp[i] = min(dp[i], dp[i / j] + j);
                }
            }
        }
        return dp[n];
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}