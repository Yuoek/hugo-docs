---
title: "2369_CheckifThereisaValidPartitionForTheArray"
date: 2025-10-06T00:42:37+08:00
weight: 2369
tags: [数组, 动态规划]
---


{{< katex />}}

{{< badge title="Difficulty" value="中等" >}}

<!-- problem:start -->

# [2369. 检查数组是否存在有效划分](https://leetcode.cn/problems/check-if-there-is-a-valid-partition-for-the-array)

[English Version](../en/2369-69/2369_CheckifThereisaValidPartitionForTheArray)

## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong> 开始的整数数组 <code>nums</code> ，你必须将数组划分为一个或多个 <strong>连续</strong> 子数组。</p>

<p>如果获得的这些子数组中每个都能满足下述条件<strong> 之一</strong> ，则可以称其为数组的一种 <strong>有效</strong> 划分：</p>

<ol>
	<li>子数组 <strong>恰</strong> 由 <code>2</code> 个相等元素组成，例如，子数组 <code>[2,2]</code> 。</li>
	<li>子数组 <strong>恰</strong> 由 <code>3</code> 个相等元素组成，例如，子数组 <code>[4,4,4]</code> 。</li>
	<li>子数组 <strong>恰</strong> 由 <code>3</code> 个连续递增元素组成，并且相邻元素之间的差值为 <code>1</code> 。例如，子数组 <code>[3,4,5]</code> ，但是子数组 <code>[1,3,5]</code> 不符合要求。</li>
</ol>

<p>如果数组 <strong>至少</strong> 存在一种有效划分，返回 <code>true</code><em> </em>，否则，返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [4,4,4,5,6]
<strong>输出：</strong>true
<strong>解释：</strong>数组可以划分成子数组 [4,4] 和 [4,5,6] 。
这是一种有效划分，所以返回 true 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,1,1,2]
<strong>输出：</strong>false
<strong>解释：</strong>该数组不存在有效划分。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

我们设计一个函数 $dfs(i)$，表示从下标 $i$ 开始是否存在一种有效划分。那么答案就是 $dfs(0)$。

函数 $dfs(i)$ 的执行过程如下：

-   如果 $i \ge n$，返回 $true$。
-   如果 $i$ 和 $i+1$ 下标的元素相等，那么可以选择将 $i$ 和 $i+1$ 作为一个子数组，递归调用 $dfs(i+2)$。
-   如果 $i$, $i+1$ 和 $i+2$ 下标的元素相等，那么可以选择将 $i$, $i+1$ 和 $i+2$ 作为一个子数组，递归调用 $dfs(i+3)$。
-   如果 $i$, $i+1$ 和 $i+2$ 下标的元素依次递增 $1$，那么可以选择将 $i$, $i+1$ 和 $i+2$ 作为一个子数组，递归调用 $dfs(i+3)$。
-   如果上述情况都不满足，返回 $false$，否则返回 $true$。

即：

$$
dfs(i) = \textit{OR}
\begin{cases}
true,&i \ge n\\
dfs(i+2),&i+1 < n\ \textit{and}\ \textit{nums}[i] = \textit{nums}[i+1]\\
dfs(i+3),&i+2 < n\ \textit{and}\ \textit{nums}[i] = \textit{nums}[i+1] = \textit{nums}[i+2]\\
dfs(i+3),&i+2 < n\ \textit{and}\ \textit{nums}[i+1] - \textit{nums}[i] = 1\ \textit{and}\ \textit{nums}[i+2] - \textit{nums}[i+1] = 1
\end{cases}
$$

为了避免重复计算，我们使用记忆化搜索的方法。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组的长度。

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：动态规划

我们可以将方法一中的记忆化搜索转换为动态规划。

设 $f[i]$ 表示数组的前 $i$ 个元素是否存在一种有效划分，初始时 $f[0] = true$，答案就是 $f[n]$。

状态转移方程如下：

$$
f[i] = \textit{OR}
\begin{cases}
true,&i = 0\\
f[i-2],&i-2 \ge 0\ \textit{and}\ \textit{nums}[i-1] = \textit{nums}[i-2]\\
f[i-3],&i-3 \ge 0\ \textit{and}\ \textit{nums}[i-1] = \textit{nums}[i-2] = \textit{nums}[i-3]\\
f[i-3],&i-3 \ge 0\ \textit{and}\ \textit{nums}[i-1] - \textit{nums}[i-2] = 1\ \textit{and}\ \textit{nums}[i-2] - \textit{nums}[i-3] = 1
\end{cases}
$$

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组的长度。

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
    def validPartition(self, nums: List[int]) -> bool:
        n = len(nums)
        f = [True] + [False] * n
        for i, x in enumerate(nums, 1):
            a = i - 2 >= 0 and nums[i - 2] == x
            b = i - 3 >= 0 and nums[i - 3] == nums[i - 2] == x
            c = i - 3 >= 0 and x - nums[i - 2] == 1 and nums[i - 2] - nums[i - 3] == 1
            f[i] = (a and f[i - 2]) or ((b or c) and f[i - 3])
        return f[n]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean validPartition(int[] nums) {
        int n = nums.length;
        boolean[] f = new boolean[n + 1];
        f[0] = true;
        for (int i = 1; i <= n; ++i) {
            boolean a = i - 2 >= 0 && nums[i - 1] == nums[i - 2];
            boolean b = i - 3 >= 0 && nums[i - 1] == nums[i - 2] && nums[i - 2] == nums[i - 3];
            boolean c
                = i - 3 >= 0 && nums[i - 1] - nums[i - 2] == 1 && nums[i - 2] - nums[i - 3] == 1;
            f[i] = (a && f[i - 2]) || ((b || c) && f[i - 3]);
        }
        return f[n];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<bool> f(n + 1);
        f[0] = true;
        for (int i = 1; i <= n; ++i) {
            bool a = i - 2 >= 0 && nums[i - 1] == nums[i - 2];
            bool b = i - 3 >= 0 && nums[i - 1] == nums[i - 2] && nums[i - 2] == nums[i - 3];
            bool c = i - 3 >= 0 && nums[i - 1] - nums[i - 2] == 1 && nums[i - 2] - nums[i - 3] == 1;
            f[i] = (a && f[i - 2]) || ((b || c) && f[i - 3]);
        }
        return f[n];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func validPartition(nums []int) bool {
	n := len(nums)
	f := make([]bool, n+1)
	f[0] = true
	for i := 1; i <= n; i++ {
		x := nums[i-1]
		a := i-2 >= 0 && nums[i-2] == x
		b := i-3 >= 0 && nums[i-3] == nums[i-2] && nums[i-2] == x
		c := i-3 >= 0 && x-nums[i-2] == 1 && nums[i-2]-nums[i-3] == 1
		f[i] = (a && f[i-2]) || ((b || c) && f[i-3])
	}
	return f[n]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function validPartition(nums: number[]): boolean {
    const n = nums.length;
    const f: boolean[] = Array(n + 1).fill(false);
    f[0] = true;
    for (let i = 1; i <= n; ++i) {
        const a = i - 2 >= 0 && nums[i - 1] === nums[i - 2];
        const b = i - 3 >= 0 && nums[i - 1] === nums[i - 2] && nums[i - 2] === nums[i - 3];
        const c = i - 3 >= 0 && nums[i - 1] - nums[i - 2] === 1 && nums[i - 2] - nums[i - 3] === 1;
        f[i] = (a && f[i - 2]) || ((b || c) && f[i - 3]);
    }
    return f[n];
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def validPartition(self, nums: List[int]) -> bool:
        n = len(nums)
        f = [True] + [False] * n
        for i, x in enumerate(nums, 1):
            a = i - 2 >= 0 and nums[i - 2] == x
            b = i - 3 >= 0 and nums[i - 3] == nums[i - 2] == x
            c = i - 3 >= 0 and x - nums[i - 2] == 1 and nums[i - 2] - nums[i - 3] == 1
            f[i] = (a and f[i - 2]) or ((b or c) and f[i - 3])
        return f[n]
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public boolean validPartition(int[] nums) {
        int n = nums.length;
        boolean[] f = new boolean[n + 1];
        f[0] = true;
        for (int i = 1; i <= n; ++i) {
            boolean a = i - 2 >= 0 && nums[i - 1] == nums[i - 2];
            boolean b = i - 3 >= 0 && nums[i - 1] == nums[i - 2] && nums[i - 2] == nums[i - 3];
            boolean c
                = i - 3 >= 0 && nums[i - 1] - nums[i - 2] == 1 && nums[i - 2] - nums[i - 3] == 1;
            f[i] = (a && f[i - 2]) || ((b || c) && f[i - 3]);
        }
        return f[n];
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
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<bool> f(n + 1);
        f[0] = true;
        for (int i = 1; i <= n; ++i) {
            bool a = i - 2 >= 0 && nums[i - 1] == nums[i - 2];
            bool b = i - 3 >= 0 && nums[i - 1] == nums[i - 2] && nums[i - 2] == nums[i - 3];
            bool c = i - 3 >= 0 && nums[i - 1] - nums[i - 2] == 1 && nums[i - 2] - nums[i - 3] == 1;
            f[i] = (a && f[i - 2]) || ((b || c) && f[i - 3]);
        }
        return f[n];
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}