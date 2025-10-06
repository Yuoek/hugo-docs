---
title: "2475_NumberofUnequalTripletsinArray"
date: 2025-10-06T00:42:37+08:00
weight: 2475
tags: [数组, 哈希表, 排序]
---


{{< katex />}}

{{< badge title="Difficulty" value="简单" >}}

<!-- problem:start -->

# [2475. 数组中不等三元组的数目](https://leetcode.cn/problems/number-of-unequal-triplets-in-array)

[English Version](../en/2475-75/2475_NumberofUnequalTripletsinArray)

## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong> 开始的正整数数组 <code>nums</code> 。请你找出并统计满足下述条件的三元组 <code>(i, j, k)</code> 的数目：</p>

<ul>
	<li><code>0 &lt;= i &lt; j &lt; k &lt; nums.length</code></li>
	<li><code>nums[i]</code>、<code>nums[j]</code> 和 <code>nums[k]</code> <strong>两两不同</strong> 。
	<ul>
		<li>换句话说：<code>nums[i] != nums[j]</code>、<code>nums[i] != nums[k]</code> 且 <code>nums[j] != nums[k]</code> 。</li>
	</ul>
	</li>
</ul>

<p>返回满足上述条件三元组的数目<em>。</em></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [4,4,2,4,3]
<strong>输出：</strong>3
<strong>解释：</strong>下面列出的三元组均满足题目条件：
- (0, 2, 4) 因为 4 != 2 != 3
- (1, 2, 4) 因为 4 != 2 != 3
- (2, 3, 4) 因为 2 != 4 != 3
共计 3 个三元组，返回 3 。
注意 (2, 0, 4) 不是有效的三元组，因为 2 &gt; 0 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,1,1,1,1]
<strong>输出：</strong>0
<strong>解释：</strong>不存在满足条件的三元组，所以返回 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 1000</code></li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：暴力枚举

我们可以直接枚举所有的三元组 $(i, j, k)$，统计所有符合条件的数量。

时间复杂度 $O(n^3)$，其中 $n$ 为数组 $nums$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



#### Rust



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：排序 + 枚举中间元素 + 二分查找

我们也可以先对数组 $nums$ 进行排序。

然后遍历 $nums$，枚举中间元素 $nums[j]$，利用二分查找，在 $nums[j]$ 左侧找到最近的下标 $i$，使得 $nums[i] \lt nums[j]$ 成立；在 $nums[j]$ 右侧找到最近的下标 $k$，使得 $nums[k] \gt nums[j]$ 成立。那么以 $nums[j]$ 作为中间元素，且符合条件的三元组数量为 $(i + 1) \times (n - k)$，累加到答案中。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 为数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



#### Rust



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法三：哈希表

我们还可以使用哈希表 $cnt$ 来统计数组 $nums$ 中每个元素的数量。

然后遍历哈希表 $cnt$，枚举中间元素的个数 $b$，左侧元素个数记为 $a$，那么右侧元素个数有 $c = n - a - b$，此时符合条件的三元组数量为 $a \times b \times c$，累加到答案中。接着更新 $a = a + b$，继续枚举中间元素的个数 $b$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### Rust



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法四

<!-- tabs:start -->

#### Rust



<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->

{{< tabs id >}}
{{% tab "python" %}}
```python
class Solution:
    def unequalTriplets(self, nums: List[int]) -> int:
        cnt = Counter(nums)
        n = len(nums)
        ans = a = 0
        for b in cnt.values():
            c = n - a - b
            ans += a * b * c
            a += b
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int unequalTriplets(int[] nums) {
        Map<Integer, Integer> cnt = new HashMap<>();
        for (int v : nums) {
            cnt.merge(v, 1, Integer::sum);
        }
        int ans = 0, a = 0;
        int n = nums.length;
        for (int b : cnt.values()) {
            int c = n - a - b;
            ans += a * b * c;
            a += b;
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
    int unequalTriplets(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (int& v : nums) {
            ++cnt[v];
        }
        int ans = 0, a = 0;
        int n = nums.size();
        for (auto& [_, b] : cnt) {
            int c = n - a - b;
            ans += a * b * c;
            a += b;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func unequalTriplets(nums []int) (ans int) {
	cnt := map[int]int{}
	for _, v := range nums {
		cnt[v]++
	}
	a, n := 0, len(nums)
	for _, b := range cnt {
		c := n - a - b
		ans += a * b * c
		a += b
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function unequalTriplets(nums: number[]): number {
    const n = nums.length;
    const cnt = new Map<number, number>();
    for (const num of nums) {
        cnt.set(num, (cnt.get(num) ?? 0) + 1);
    }
    let ans = 0;
    let a = 0;
    for (const b of cnt.values()) {
        const c = n - a - b;
        ans += a * b * c;
        a += b;
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn unequal_triplets(nums: Vec<i32>) -> i32 {
        let mut ans = 0;
        let mut nums = nums;
        nums.sort();
        let n = nums.len();

        for i in 1..n - 1 {
            let mut l = 0;
            let mut r = i;
            while l < r {
                let mid = (l + r) >> 1;
                if nums[mid] >= nums[i] {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            let j = r;

            let mut l = i + 1;
            let mut r = n;
            while l < r {
                let mid = (l + r) >> 1;
                if nums[mid] > nums[i] {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            let k = r;

            ans += j * (n - k);
        }

        ans as i32
    }
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def unequalTriplets(self, nums: List[int]) -> int:
        cnt = Counter(nums)
        n = len(nums)
        ans = a = 0
        for b in cnt.values():
            c = n - a - b
            ans += a * b * c
            a += b
        return ans
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public int unequalTriplets(int[] nums) {
        Map<Integer, Integer> cnt = new HashMap<>();
        for (int v : nums) {
            cnt.merge(v, 1, Integer::sum);
        }
        int ans = 0, a = 0;
        int n = nums.length;
        for (int b : cnt.values()) {
            int c = n - a - b;
            ans += a * b * c;
            a += b;
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
    int unequalTriplets(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (int& v : nums) {
            ++cnt[v];
        }
        int ans = 0, a = 0;
        int n = nums.size();
        for (auto& [_, b] : cnt) {
            int c = n - a - b;
            ans += a * b * c;
            a += b;
        }
        return ans;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}