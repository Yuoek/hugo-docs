---
title: "3158_FindtheXORofNumbersWhichAppearTwice"
date: 2025-10-06T00:42:37+08:00
weight: 3158
tags: [位运算, 数组, 哈希表]
---


{{< katex />}}

{{< badge title="Difficulty" value="简单" >}}

<!-- problem:start -->

# [3158. 求出出现两次数字的 XOR 值](https://leetcode.cn/problems/find-the-xor-of-numbers-which-appear-twice)

[English Version](../en/3158-58/3158_FindtheXORofNumbersWhichAppearTwice)

## 题目描述

<!-- description:start -->

<p>给你一个数组&nbsp;<code>nums</code>&nbsp;，数组中的数字 <strong>要么</strong> 出现一次，<strong>要么</strong>&nbsp;出现两次。</p>

<p>请你返回数组中所有出现两次数字的按位<em>&nbsp;</em><code>XOR</code>&nbsp;值，如果没有数字出现过两次，返回 0 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [1,2,1,3]</span></p>

<p><span class="example-io"><b>输出：</b>1</span></p>

<p><strong>解释：</strong></p>

<p><code>nums</code>&nbsp;中唯一出现过两次的数字是 1 。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [1,2,3]</span></p>

<p><span class="example-io"><b>输出：</b>0</span></p>

<p><strong>解释：</strong></p>

<p><code>nums</code>&nbsp;中没有数字出现两次。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [1,2,2,1]</span></p>

<p><span class="example-io"><b>输出：</b>3</span></p>

<p><strong>解释：</strong></p>

<p>数字 1 和&nbsp;2 出现过两次。<code>1 XOR 2 == 3</code>&nbsp;。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 50</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 50</code></li>
	<li><code>nums</code>&nbsp;中每个数字要么出现过一次，要么出现过两次。</li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：计数

我们定义一个数组或哈希表 $\textit{cnt}$ 记录每个数字出现的次数。

接下来，遍历数组 $\textit{nums}$，当某个数字出现两次时，我们将其与答案进行异或运算。

最后返回答案即可。

时间复杂度 $O(n)$，空间复杂度 $O(M)$。其中 $n$ 是数组 $\textit{nums}$ 的长度，而 $M$ 是数组 $\textit{nums}$ 中的最大值或数组 $\textit{nums}$ 不同数字的个数。

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：位运算

由于题目中给出的数字范围是 $1 \leq \textit{nums}[i] \leq 50$，我们可以使用一个 $64$ 位的整数来存储每个数字的出现次数。

我们定义一个整数 $\textit{mask}$ 来记录每个数字是否出现过。

接下来，遍历数组 $\textit{nums}$，当某个数字出现两次时，即 $\textit{mask}$ 的二进制表示中第 $x$ 位为 $1$ 时，我们将其与答案进行异或运算。否则，我们将 $\textit{mask}$ 的第 $x$ 位设置为 $1$。

最后返回答案即可。

时间复杂度 $O(n)$，其中 $n$ 是数组 $\textit{nums}$ 的长度。空间复杂度 $O(1)$。

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
    def duplicateNumbersXOR(self, nums: List[int]) -> int:
        ans = mask = 0
        for x in nums:
            if mask >> x & 1:
                ans ^= x
            else:
                mask |= 1 << x
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int duplicateNumbersXOR(int[] nums) {
        int ans = 0;
        long mask = 0;
        for (int x : nums) {
            if ((mask >> x & 1) == 1) {
                ans ^= x;
            } else {
                mask |= 1L << x;
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
    int duplicateNumbersXOR(vector<int>& nums) {
        int ans = 0;
        long long mask = 0;
        for (int x : nums) {
            if (mask >> x & 1) {
                ans ^= x;
            } else {
                mask |= 1LL << x;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func duplicateNumbersXOR(nums []int) (ans int) {
	mask := 0
	for _, x := range nums {
		if mask>>x&1 == 1 {
			ans ^= x
		} else {
			mask |= 1 << x
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function duplicateNumbersXOR(nums: number[]): number {
    let ans = 0;
    let mask = 0n;
    for (const x of nums) {
        if ((mask >> BigInt(x)) & 1n) {
            ans ^= x;
        } else {
            mask |= 1n << BigInt(x);
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
    def duplicateNumbersXOR(self, nums: List[int]) -> int:
        ans = mask = 0
        for x in nums:
            if mask >> x & 1:
                ans ^= x
            else:
                mask |= 1 << x
        return ans
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public int duplicateNumbersXOR(int[] nums) {
        int ans = 0;
        long mask = 0;
        for (int x : nums) {
            if ((mask >> x & 1) == 1) {
                ans ^= x;
            } else {
                mask |= 1L << x;
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
    int duplicateNumbersXOR(vector<int>& nums) {
        int ans = 0;
        long long mask = 0;
        for (int x : nums) {
            if (mask >> x & 1) {
                ans ^= x;
            } else {
                mask |= 1LL << x;
            }
        }
        return ans;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}