---
title: "2279_MaximumBagsWithFullCapacityofRocks"
date: 2025-10-06T00:42:37+08:00
weight: 2279
tags: [贪心, 数组, 排序]
---


{{< katex />}}

{{< badge title="Difficulty" value="中等" >}}

<!-- problem:start -->

# [2279. 装满石头的背包的最大数量](https://leetcode.cn/problems/maximum-bags-with-full-capacity-of-rocks)

[English Version](../en/2279-79/2279_MaximumBagsWithFullCapacityofRocks)

## 题目描述

<!-- description:start -->

<p>现有编号从&nbsp;<code>0</code> 到 <code>n - 1</code> 的 <code>n</code> 个背包。给你两个下标从 <strong>0</strong> 开始的整数数组 <code>capacity</code> 和 <code>rocks</code> 。第 <code>i</code> 个背包最大可以装 <code>capacity[i]</code> 块石头，当前已经装了 <code>rocks[i]</code> 块石头。另给你一个整数 <code>additionalRocks</code> ，表示<span class="text-only" data-eleid="10" style="white-space: pre;">你可以放置的额外石头数量，石头可以往 </span><strong><span class="text-only" data-eleid="11" style="white-space: pre;">任意</span></strong><span class="text-only" data-eleid="12" style="white-space: pre;"> 背包中放置。</span></p>

<p>请你将额外的石头放入一些背包中，并返回放置后装满石头的背包的 <strong>最大 </strong>数量<em>。</em></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>capacity = [2,3,4,5], rocks = [1,2,4,4], additionalRocks = 2
<strong>输出：</strong>3
<strong>解释：</strong>
1 块石头放入背包 0 ，1 块石头放入背包 1 。
每个背包中的石头总数是 [2,3,4,4] 。
背包 0 、背包 1 和 背包 2 都装满石头。
总计 3 个背包装满石头，所以返回 3 。
可以证明不存在超过 3 个背包装满石头的情况。
注意，可能存在其他放置石头的方案同样能够得到 3 这个结果。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>capacity = [10,2,2], rocks = [2,2,0], additionalRocks = 100
<strong>输出：</strong>3
<strong>解释：</strong>
8 块石头放入背包 0 ，2 块石头放入背包 2 。
每个背包中的石头总数是 [10,2,2] 。
背包 0 、背包 1 和背包 2 都装满石头。
总计 3 个背包装满石头，所以返回 3 。
可以证明不存在超过 3 个背包装满石头的情况。
注意，不必用完所有的额外石头。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == capacity.length == rocks.length</code></li>
	<li><code>1 &lt;= n &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= capacity[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= rocks[i] &lt;= capacity[i]</code></li>
	<li><code>1 &lt;= additionalRocks &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：排序 + 贪心

我们首先将每个背包的剩余容量计算出来，然后对剩余容量进行排序，接着我们从小到大遍历剩余容量，将额外的石头放入背包中，直到额外的石头用完或者背包的剩余容量用完为止，返回此时的背包数量即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 为背包的数量。

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
    def maximumBags(
        self, capacity: List[int], rocks: List[int], additionalRocks: int
    ) -> int:
        for i, x in enumerate(rocks):
            capacity[i] -= x
        capacity.sort()
        for i, x in enumerate(capacity):
            additionalRocks -= x
            if additionalRocks < 0:
                return i
        return len(capacity)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maximumBags(int[] capacity, int[] rocks, int additionalRocks) {
        int n = rocks.length;
        for (int i = 0; i < n; ++i) {
            capacity[i] -= rocks[i];
        }
        Arrays.sort(capacity);
        for (int i = 0; i < n; ++i) {
            additionalRocks -= capacity[i];
            if (additionalRocks < 0) {
                return i;
            }
        }
        return n;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = rocks.size();
        for (int i = 0; i < n; ++i) {
            capacity[i] -= rocks[i];
        }
        ranges::sort(capacity);
        for (int i = 0; i < n; ++i) {
            additionalRocks -= capacity[i];
            if (additionalRocks < 0) {
                return i;
            }
        }
        return n;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumBags(capacity []int, rocks []int, additionalRocks int) int {
	for i, x := range rocks {
		capacity[i] -= x
	}
	sort.Ints(capacity)
	for i, x := range capacity {
		additionalRocks -= x
		if additionalRocks < 0 {
			return i
		}
	}
	return len(capacity)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumBags(capacity: number[], rocks: number[], additionalRocks: number): number {
    const n = rocks.length;
    for (let i = 0; i < n; ++i) {
        capacity[i] -= rocks[i];
    }
    capacity.sort((a, b) => a - b);
    for (let i = 0; i < n; ++i) {
        additionalRocks -= capacity[i];
        if (additionalRocks < 0) {
            return i;
        }
    }
    return n;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn maximum_bags(mut capacity: Vec<i32>, rocks: Vec<i32>, mut additional_rocks: i32) -> i32 {
        for i in 0..rocks.len() {
            capacity[i] -= rocks[i];
        }
        capacity.sort();
        for i in 0..capacity.len() {
            additional_rocks -= capacity[i];
            if additional_rocks < 0 {
                return i as i32;
            }
        }
        capacity.len() as i32
    }
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def maximumBags(
        self, capacity: List[int], rocks: List[int], additionalRocks: int
    ) -> int:
        for i, x in enumerate(rocks):
            capacity[i] -= x
        capacity.sort()
        for i, x in enumerate(capacity):
            additionalRocks -= x
            if additionalRocks < 0:
                return i
        return len(capacity)
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public int maximumBags(int[] capacity, int[] rocks, int additionalRocks) {
        int n = rocks.length;
        for (int i = 0; i < n; ++i) {
            capacity[i] -= rocks[i];
        }
        Arrays.sort(capacity);
        for (int i = 0; i < n; ++i) {
            additionalRocks -= capacity[i];
            if (additionalRocks < 0) {
                return i;
            }
        }
        return n;
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
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = rocks.size();
        for (int i = 0; i < n; ++i) {
            capacity[i] -= rocks[i];
        }
        ranges::sort(capacity);
        for (int i = 0; i < n; ++i) {
            additionalRocks -= capacity[i];
            if (additionalRocks < 0) {
                return i;
            }
        }
        return n;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}