---
title: "2364_CountNumberofBadPairs"
date: 2025-10-06T00:42:37+08:00
weight: 2364
tags: [数组, 哈希表, 数学, 计数]
---


{{< katex />}}

{{< badge title="Difficulty" value="中等" >}}

<!-- problem:start -->

# [2364. 统计坏数对的数目](https://leetcode.cn/problems/count-number-of-bad-pairs)

[English Version](../en/2364-64/2364_CountNumberofBadPairs)

## 题目描述

<!-- description:start -->

<p>给你一个下标从<strong>&nbsp;0</strong>&nbsp;开始的整数数组&nbsp;<code>nums</code>&nbsp;。如果 <code>i &lt; j</code>&nbsp;且&nbsp;<code>j - i != nums[j] - nums[i]</code>&nbsp;，那么我们称&nbsp;<code>(i, j)</code>&nbsp;是一个 <strong>坏</strong><strong>数对</strong>&nbsp;。</p>

<p>请你返回 <code>nums</code>&nbsp;中 <strong>坏数对</strong>&nbsp;的总数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [4,1,3,3]
<b>输出：</b>5
<b>解释：</b>数对 (0, 1) 是坏数对，因为 1 - 0 != 1 - 4 。
数对 (0, 2) 是坏数对，因为 2 - 0 != 3 - 4, 2 != -1 。
数对 (0, 3) 是坏数对，因为 3 - 0 != 3 - 4, 3 != -1 。
数对 (1, 2) 是坏数对，因为 2 - 1 != 3 - 1, 1 != 2 。
数对 (2, 3) 是坏数对，因为 3 - 2 != 3 - 3, 1 != 0 。
总共有 5 个坏数对，所以我们返回 5 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [1,2,3,4,5]
<b>输出：</b>0
<strong>解释：</strong>没有坏数对。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：式子转换 + 哈希表

根据题目描述，我们可以得知，对于任意的 $i \lt j$，如果 $j - i \neq \textit{nums}[j] - \textit{nums}[i]$，则 $(i, j)$ 是一个坏数对。

我们可以将式子转换为 $i - \textit{nums}[i] \neq j - \textit{nums}[j]$。这启发我们用哈希表 $cnt$ 来统计 $i - \textit{nums}[i]$ 的出现次数。

遍历数组，对于当前元素 $\textit{nums}[i]$，我们将 $i - cnt[i - \textit{nums}[i]]$ 加到答案中，然后将 $i - \textit{nums}[i]$ 的出现次数加 $1$。

最后，我们返回答案即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $\textit{nums}$ 的长度。

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
    def countBadPairs(self, nums: List[int]) -> int:
        cnt = Counter()
        ans = 0
        for i, x in enumerate(nums):
            ans += i - cnt[i - x]
            cnt[i - x] += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long countBadPairs(int[] nums) {
        Map<Integer, Integer> cnt = new HashMap<>();
        long ans = 0;
        for (int i = 0; i < nums.length; ++i) {
            int x = i - nums[i];
            ans += i - cnt.merge(x, 1, Integer::sum) + 1;
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
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, int> cnt;
        long long ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int x = i - nums[i];
            ans += i - cnt[x]++;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countBadPairs(nums []int) (ans int64) {
	cnt := map[int]int{}
	for i, x := range nums {
		x = i - x
		ans += int64(i - cnt[x])
		cnt[x]++
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countBadPairs(nums: number[]): number {
    const cnt = new Map<number, number>();
    let ans = 0;
    for (let i = 0; i < nums.length; ++i) {
        const x = i - nums[i];
        ans += i - (cnt.get(x) ?? 0);
        cnt.set(x, (cnt.get(x) ?? 0) + 1);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashMap;

impl Solution {
    pub fn count_bad_pairs(nums: Vec<i32>) -> i64 {
        let mut cnt: HashMap<i32, i64> = HashMap::new();
        let mut ans: i64 = 0;
        for (i, &num) in nums.iter().enumerate() {
            let x = i as i32 - num;
            let count = *cnt.get(&x).unwrap_or(&0);
            ans += i as i64 - count;
            *cnt.entry(x).or_insert(0) += 1;
        }
        ans
    }
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def countBadPairs(self, nums: List[int]) -> int:
        cnt = Counter()
        ans = 0
        for i, x in enumerate(nums):
            ans += i - cnt[i - x]
            cnt[i - x] += 1
        return ans
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public long countBadPairs(int[] nums) {
        Map<Integer, Integer> cnt = new HashMap<>();
        long ans = 0;
        for (int i = 0; i < nums.length; ++i) {
            int x = i - nums[i];
            ans += i - cnt.merge(x, 1, Integer::sum) + 1;
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
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, int> cnt;
        long long ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int x = i - nums[i];
            ans += i - cnt[x]++;
        }
        return ans;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}