---
title: "0198_HouseRobber"
date: 2025-10-06T00:42:37+08:00
weight: 0198
tags: [数组, 动态规划]
---


{{< katex />}}

{{< badge title="Difficulty" value="中等" >}}

<!-- problem:start -->

# [198. 打家劫舍](https://leetcode.cn/problems/house-robber)

[English Version](../en/0198-98/0198_HouseRobber)

## 题目描述

<!-- description:start -->

<p>你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，<strong>如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警</strong>。</p>

<p>给定一个代表每个房屋存放金额的非负整数数组，计算你<strong> 不触动警报装置的情况下 </strong>，一夜之内能够偷窃到的最高金额。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>[1,2,3,1]
<strong>输出：</strong>4
<strong>解释：</strong>偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
     偷窃到的最高金额 = 1 + 3 = 4 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>[2,7,9,3,1]
<strong>输出：</strong>12
<strong>解释：</strong>偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
     偷窃到的最高金额 = 2 + 9 + 1 = 12 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= nums.length <= 100</code></li>
	<li><code>0 <= nums[i] <= 400</code></li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

我们设计一个函数 $\textit{dfs}(i)$，表示从第 $i$ 间房屋开始偷窃能够得到的最高金额。那么答案即为 $\textit{dfs}(0)$。

函数 $\textit{dfs}(i)$ 的执行过程如下：

-   如果 $i \ge \textit{len}(\textit{nums})$，表示所有房屋都被考虑过了，直接返回 $0$；
-   否则，考虑偷窃第 $i$ 间房屋，那么 $\textit{dfs}(i) = \textit{nums}[i] + \textit{dfs}(i+2)$；不偷窃第 $i$ 间房屋，那么 $\textit{dfs}(i) = \textit{dfs}(i+1)$。
-   返回 $\max(\textit{nums}[i] + \textit{dfs}(i+2), \textit{dfs}(i+1))$。

为了避免重复计算，我们使用记忆化搜索的方法，将 $\textit{dfs}(i)$ 的结果保存在一个数组或哈希表中，每次计算前先查询是否已经计算过，如果计算过直接返回结果。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是数组长度。

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

### 方法二：动态规划

我们定义 $f[i]$ 表示前 $i$ 间房屋能偷窃到的最高总金额，初始时 $f[0]=0$, $f[1]=nums[0]$。

考虑 $i \gt 1$ 的情况，第 $i$ 间房屋有两个选项：

-   不偷窃第 $i$ 间房屋，偷窃总金额为 $f[i-1]$；
-   偷窃第 $i$ 间房屋，偷窃总金额为 $f[i-2]+nums[i-1]$；

因此，我们可以得到状态转移方程：

$$
f[i]=
\begin{cases}
0, & i=0 \\
nums[0], & i=1 \\
\max(f[i-1],f[i-2]+nums[i-1]), & i \gt 1
\end{cases}
$$

最终的答案即为 $f[n]$，其中 $n$ 是数组的长度。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是数组长度。

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

### 方法三：动态规划（空间优化）

我们注意到，当 $i \gt 2$ 时，$f[i]$ 只和 $f[i-1]$ 与 $f[i-2]$ 有关，因此我们可以使用两个变量代替数组，将空间复杂度降到 $O(1)$。

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
    def rob(self, nums: List[int]) -> int:
        f = g = 0
        for x in nums:
            f, g = max(f, g), f + x
        return max(f, g)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int rob(int[] nums) {
        int f = 0, g = 0;
        for (int x : nums) {
            int ff = Math.max(f, g);
            g = f + x;
            f = ff;
        }
        return Math.max(f, g);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        int f = 0, g = 0;
        for (int& x : nums) {
            int ff = max(f, g);
            g = f + x;
            f = ff;
        }
        return max(f, g);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func rob(nums []int) int {
	f, g := 0, 0
	for _, x := range nums {
		f, g = max(f, g), f+x
	}
	return max(f, g)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function rob(nums: number[]): number {
    let [f, g] = [0, 0];
    for (const x of nums) {
        [f, g] = [Math.max(f, g), f + x];
    }
    return Math.max(f, g);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn rob(nums: Vec<i32>) -> i32 {
        let mut f = [0, 0];
        for x in nums {
            f = [f[0].max(f[1]), f[0] + x];
        }
        f[0].max(f[1])
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
function rob(nums) {
    let [f, g] = [0, 0];
    for (const x of nums) {
        [f, g] = [Math.max(f, g), f + x];
    }
    return Math.max(f, g);
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def rob(self, nums: List[int]) -> int:
        f = g = 0
        for x in nums:
            f, g = max(f, g), f + x
        return max(f, g)
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public int rob(int[] nums) {
        int f = 0, g = 0;
        for (int x : nums) {
            int ff = Math.max(f, g);
            g = f + x;
            f = ff;
        }
        return Math.max(f, g);
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
    int rob(vector<int>& nums) {
        int f = 0, g = 0;
        for (int& x : nums) {
            int ff = max(f, g);
            g = f + x;
            f = ff;
        }
        return max(f, g);
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}