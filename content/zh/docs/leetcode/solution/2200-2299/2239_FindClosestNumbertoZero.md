---
title: "2239_FindClosestNumbertoZero"
date: 2025-10-06T00:42:37+08:00
weight: 2239
tags: [数组]
---


{{< katex />}}

{{< badge title="Difficulty" value="简单" >}}

<!-- problem:start -->

# [2239. 找到最接近 0 的数字](https://leetcode.cn/problems/find-closest-number-to-zero)

[English Version](../en/2239-39/2239_FindClosestNumbertoZero)

## 题目描述

<!-- description:start -->

<p>给你一个长度为 <code>n</code>&nbsp;的整数数组&nbsp;<code>nums</code>&nbsp;，请你返回 <code>nums</code>&nbsp;中最 <strong>接近</strong>&nbsp;<code>0</code>&nbsp;的数字。如果有多个答案，请你返回它们中的 <strong>最大值</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [-4,-2,1,4,8]
<b>输出：</b>1
<strong>解释：</strong>
-4 到 0 的距离为 |-4| = 4 。
-2 到 0 的距离为 |-2| = 2 。
1 到 0 的距离为 |1| = 1 。
4 到 0 的距离为 |4| = 4 。
8 到 0 的距离为 |8| = 8 。
所以，数组中距离 0 最近的数字为 1 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [2,-1,1]
<b>输出：</b>1
<b>解释：</b>1 和 -1 都是距离 0 最近的数字，所以返回较大值 1 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
	<li><code>-10<sup>5</sup> &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：一次遍历

我们定义一个变量 $\textit{d}$ 来记录当前最小的距离，初始时 $\textit{d}=\infty$。然后我们遍历数组，对于每个元素 $x$，我们计算 $y=|x|$，如果 $y \lt d$ 或者 $y=d$ 且 $x \gt \textit{ans}$，我们就更新答案 $\textit{ans}=x$ 和 $\textit{d}=y$。

遍历结束后返回答案即可。

时间复杂度 $O(n)$，其中 $n$ 是数组的长度。空间复杂度 $O(1)$。

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
    def findClosestNumber(self, nums: List[int]) -> int:
        ans, d = 0, inf
        for x in nums:
            if (y := abs(x)) < d or (y == d and x > ans):
                ans, d = x, y
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int findClosestNumber(int[] nums) {
        int ans = 0, d = 1 << 30;
        for (int x : nums) {
            int y = Math.abs(x);
            if (y < d || (y == d && x > ans)) {
                ans = x;
                d = y;
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
    int findClosestNumber(vector<int>& nums) {
        int ans = 0, d = 1 << 30;
        for (int x : nums) {
            int y = abs(x);
            if (y < d || (y == d && x > ans)) {
                ans = x;
                d = y;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findClosestNumber(nums []int) int {
	ans, d := 0, 1<<30
	for _, x := range nums {
		if y := abs(x); y < d || (y == d && x > ans) {
			ans, d = x, y
		}
	}
	return ans
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findClosestNumber(nums: number[]): number {
    let [ans, d] = [0, 1 << 30];
    for (const x of nums) {
        const y = Math.abs(x);
        if (y < d || (y == d && x > ans)) {
            [ans, d] = [x, y];
        }
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
    def findClosestNumber(self, nums: List[int]) -> int:
        ans, d = 0, inf
        for x in nums:
            if (y := abs(x)) < d or (y == d and x > ans):
                ans, d = x, y
        return ans
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public int findClosestNumber(int[] nums) {
        int ans = 0, d = 1 << 30;
        for (int x : nums) {
            int y = Math.abs(x);
            if (y < d || (y == d && x > ans)) {
                ans = x;
                d = y;
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
    int findClosestNumber(vector<int>& nums) {
        int ans = 0, d = 1 << 30;
        for (int x : nums) {
            int y = abs(x);
            if (y < d || (y == d && x > ans)) {
                ans = x;
                d = y;
            }
        }
        return ans;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}