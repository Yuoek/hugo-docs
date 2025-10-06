---
title: "3309_MaximumPossibleNumberbyBinaryConcatenation"
date: 2025-10-06T00:42:37+08:00
weight: 3309
tags: [位运算, 数组, 枚举]
---


{{< katex />}}

{{< badge title="Difficulty" value="中等" >}}

<!-- problem:start -->

# [3309. 连接二进制表示可形成的最大数值](https://leetcode.cn/problems/maximum-possible-number-by-binary-concatenation)

[English Version](../en/3309-09/3309_MaximumPossibleNumberbyBinaryConcatenation)

## 题目描述

<!-- description:start -->

<p>给你一个长度为 <code>3</code> 的整数数组 <code>nums</code>。</p>

<p>现以某种顺序<strong> 连接 </strong>数组 <code>nums</code> 中所有元素的 <strong>二进制表示</strong> ，请你返回可以由这种方法形成的 <strong>最大 </strong>数值。</p>

<p><strong>注意</strong> 任何数字的二进制表示<em> </em><strong>不含</strong><em> </em>前导零。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1:</strong></p>

<div class="example-block">
<p><strong>输入:</strong> <span class="example-io">nums = [1,2,3]</span></p>

<p><strong>输出:</strong> 30</p>

<p><strong>解释:</strong></p>

<p>按照顺序 <code>[3, 1, 2]</code> 连接数字的二进制表示，得到结果 <code>"11110"</code>，这是 30 的二进制表示。</p>
</div>

<p><strong class="example">示例 2:</strong></p>

<div class="example-block">
<p><strong>输入:</strong> <span class="example-io">nums = [2,8,16]</span></p>

<p><strong>输出:</strong> 1296</p>

<p><strong>解释:</strong></p>

<p>按照顺序 <code>[2, 8, 16]</code> 连接数字的二进制表述，得到结果 <code>"10100010000"</code>，这是 1296 的二进制表示。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>nums.length == 3</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 127</code></li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：枚举

根据题目描述，数组 $\textit{nums}$ 的长度为 $3$，我们可以枚举 $\textit{nums}$ 的全排列，一共有 $3! = 6$ 种排列方式，然后将排列后的数组中的元素转换为二进制字符串，再将这些二进制字符串连接起来，最后将连接后的二进制字符串转换为十进制数，取最大值即可。

时间复杂度 $O(\log M)$，其中 $M$ 表示 $\textit{nums}$ 中的元素的最大值。空间复杂度 $O(1)$。

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
    def maxGoodNumber(self, nums: List[int]) -> int:
        ans = 0
        for arr in permutations(nums):
            num = int("".join(bin(i)[2:] for i in arr), 2)
            ans = max(ans, num)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[] nums;

    public int maxGoodNumber(int[] nums) {
        this.nums = nums;
        int ans = f(0, 1, 2);
        ans = Math.max(ans, f(0, 2, 1));
        ans = Math.max(ans, f(1, 0, 2));
        ans = Math.max(ans, f(1, 2, 0));
        ans = Math.max(ans, f(2, 0, 1));
        ans = Math.max(ans, f(2, 1, 0));
        return ans;
    }

    private int f(int i, int j, int k) {
        String a = Integer.toBinaryString(nums[i]);
        String b = Integer.toBinaryString(nums[j]);
        String c = Integer.toBinaryString(nums[k]);
        return Integer.parseInt(a + b + c, 2);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maxGoodNumber(vector<int>& nums) {
        int ans = 0;
        auto f = [&](vector<int>& nums) {
            int res = 0;
            vector<int> t;
            for (int x : nums) {
                for (; x; x >>= 1) {
                    t.push_back(x & 1);
                }
            }
            while (t.size()) {
                res = res * 2 + t.back();
                t.pop_back();
            }
            return res;
        };
        for (int i = 0; i < 6; ++i) {
            ans = max(ans, f(nums));
            next_permutation(nums.begin(), nums.end());
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxGoodNumber(nums []int) int {
	f := func(i, j, k int) int {
		a := strconv.FormatInt(int64(nums[i]), 2)
		b := strconv.FormatInt(int64(nums[j]), 2)
		c := strconv.FormatInt(int64(nums[k]), 2)
		res, _ := strconv.ParseInt(a+b+c, 2, 64)
		return int(res)
	}
	ans := f(0, 1, 2)
	ans = max(ans, f(0, 2, 1))
	ans = max(ans, f(1, 0, 2))
	ans = max(ans, f(1, 2, 0))
	ans = max(ans, f(2, 0, 1))
	ans = max(ans, f(2, 1, 0))
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxGoodNumber(nums: number[]): number {
    const f = (i: number, j: number, k: number): number => {
        const a = nums[i].toString(2);
        const b = nums[j].toString(2);
        const c = nums[k].toString(2);
        const res = parseInt(a + b + c, 2);
        return res;
    };

    let ans = f(0, 1, 2);
    ans = Math.max(ans, f(0, 2, 1));
    ans = Math.max(ans, f(1, 0, 2));
    ans = Math.max(ans, f(1, 2, 0));
    ans = Math.max(ans, f(2, 0, 1));
    ans = Math.max(ans, f(2, 1, 0));

    return ans;
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def maxGoodNumber(self, nums: List[int]) -> int:
        ans = 0
        for arr in permutations(nums):
            num = int("".join(bin(i)[2:] for i in arr), 2)
            ans = max(ans, num)
        return ans
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    private int[] nums;

    public int maxGoodNumber(int[] nums) {
        this.nums = nums;
        int ans = f(0, 1, 2);
        ans = Math.max(ans, f(0, 2, 1));
        ans = Math.max(ans, f(1, 0, 2));
        ans = Math.max(ans, f(1, 2, 0));
        ans = Math.max(ans, f(2, 0, 1));
        ans = Math.max(ans, f(2, 1, 0));
        return ans;
    }

    private int f(int i, int j, int k) {
        String a = Integer.toBinaryString(nums[i]);
        String b = Integer.toBinaryString(nums[j]);
        String c = Integer.toBinaryString(nums[k]);
        return Integer.parseInt(a + b + c, 2);
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
    int maxGoodNumber(vector<int>& nums) {
        int ans = 0;
        auto f = [&](vector<int>& nums) {
            int res = 0;
            vector<int> t;
            for (int x : nums) {
                for (; x; x >>= 1) {
                    t.push_back(x & 1);
                }
            }
            while (t.size()) {
                res = res * 2 + t.back();
                t.pop_back();
            }
            return res;
        };
        for (int i = 0; i < 6; ++i) {
            ans = max(ans, f(nums));
            next_permutation(nums.begin(), nums.end());
        }
        return ans;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}