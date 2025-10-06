---
title: "1262_GreatestSumDivisiblebyThree"
date: 2025-10-06T00:42:37+08:00
weight: 1262
tags: [贪心, 数组, 动态规划, 排序]
---


{{< katex />}}

{{< badge title="Difficulty" value="中等" >}}

<!-- problem:start -->

# [1262. 可被三整除的最大和](https://leetcode.cn/problems/greatest-sum-divisible-by-three)

[English Version](../en/1262-62/1262_GreatestSumDivisiblebyThree)

## 题目描述

<!-- description:start -->

<p>给你一个整数数组&nbsp;<code>nums</code>，请你找出并返回能被三整除的元素 <strong>最大和</strong>。</p>

<ol>
</ol>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [3,6,5,1,8]
<strong>输出：</strong>18
<strong>解释：</strong>选出数字 3, 6, 1 和 8，它们的和是 18（可被 3 整除的最大和）。</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [4]
<strong>输出：</strong>0
<strong>解释：</strong>4 不能被 3 整除，所以无法选出数字，返回 0。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3,4,4]
<strong>输出：</strong>12
<strong>解释：</strong>选出数字 1, 3, 4 以及 4，它们的和是 12（可被 3 整除的最大和）。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 4 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i][j]$ 表示前 $i$ 个数中选取若干个数，使得这若干个数的和模 $3$ 余 $j$ 的最大值。初始时 $f[0][0]=0$，其余为 $-\infty$。

对于 $f[i][j]$，我们可以考虑第 $i$ 个数 $x$ 的状态：

-   如果我们不选 $x$，那么 $f[i][j]=f[i-1][j]$；
-   如果我们选 $x$，那么 $f[i][j]=f[i-1][(j-x \bmod 3 + 3)\bmod 3]+x$。

因此我们可以得到状态转移方程：

$$
f[i][j]=\max\{f[i-1][j],f[i-1][(j-x \bmod 3 + 3)\bmod 3]+x\}
$$

最终答案为 $f[n][0]$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $nums$ 的长度。

注意到 $f[i][j]$ 的值只与 $f[i-1][j]$ 和 $f[i-1][(j-x \bmod 3 + 3)\bmod 3]$ 有关，因此我们可以使用滚动数组优化空间复杂度，使空间复杂度降低为 $O(1)$。

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

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
    def maxSumDivThree(self, nums: List[int]) -> int:
        f = [0, -inf, -inf]
        for x in nums:
            g = f[:]
            for j in range(3):
                g[j] = max(f[j], f[(j - x) % 3] + x)
            f = g
        return f[0]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxSumDivThree(int[] nums) {
        final int inf = 1 << 30;
        int[] f = new int[] {0, -inf, -inf};
        for (int x : nums) {
            int[] g = f.clone();
            for (int j = 0; j < 3; ++j) {
                g[j] = Math.max(f[j], f[(j - x % 3 + 3) % 3] + x);
            }
            f = g;
        }
        return f[0];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        const int inf = 1 << 30;
        vector<int> f = {0, -inf, -inf};
        for (int& x : nums) {
            vector<int> g = f;
            for (int j = 0; j < 3; ++j) {
                g[j] = max(f[j], f[(j - x % 3 + 3) % 3] + x);
            }
            f = move(g);
        }
        return f[0];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxSumDivThree(nums []int) int {
	const inf = 1 << 30
	f := [3]int{0, -inf, -inf}
	for _, x := range nums {
		g := [3]int{}
		for j := range f {
			g[j] = max(f[j], f[(j-x%3+3)%3]+x)
		}
		f = g
	}
	return f[0]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxSumDivThree(nums: number[]): number {
    const inf = 1 << 30;
    const f: number[] = [0, -inf, -inf];
    for (const x of nums) {
        const g = [...f];
        for (let j = 0; j < 3; ++j) {
            f[j] = Math.max(g[j], g[(j - (x % 3) + 3) % 3] + x);
        }
    }
    return f[0];
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def maxSumDivThree(self, nums: List[int]) -> int:
        f = [0, -inf, -inf]
        for x in nums:
            g = f[:]
            for j in range(3):
                g[j] = max(f[j], f[(j - x) % 3] + x)
            f = g
        return f[0]
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public int maxSumDivThree(int[] nums) {
        final int inf = 1 << 30;
        int[] f = new int[] {0, -inf, -inf};
        for (int x : nums) {
            int[] g = f.clone();
            for (int j = 0; j < 3; ++j) {
                g[j] = Math.max(f[j], f[(j - x % 3 + 3) % 3] + x);
            }
            f = g;
        }
        return f[0];
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
    int maxSumDivThree(vector<int>& nums) {
        const int inf = 1 << 30;
        vector<int> f = {0, -inf, -inf};
        for (int& x : nums) {
            vector<int> g = f;
            for (int j = 0; j < 3; ++j) {
                g[j] = max(f[j], f[(j - x % 3 + 3) % 3] + x);
            }
            f = move(g);
        }
        return f[0];
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}