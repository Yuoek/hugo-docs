---
title: "0826_MostProfitAssigningWork"
date: 2025-10-06T00:42:37+08:00
weight: 0826
tags: [贪心, 数组, 双指针, 二分查找, 排序]
---


{{< katex />}}

{{< badge title="Difficulty" value="中等" >}}

<!-- problem:start -->

# [826. 安排工作以达到最大收益](https://leetcode.cn/problems/most-profit-assigning-work)

[English Version](../en/0826-26/0826_MostProfitAssigningWork)

## 题目描述

<!-- description:start -->

<p>你有 <code>n</code>&nbsp;个工作和 <code>m</code> 个工人。给定三个数组：&nbsp;<code>difficulty</code>,&nbsp;<code>profit</code>&nbsp;和&nbsp;<code>worker</code>&nbsp;，其中:</p>

<ul>
	<li><code>difficulty[i]</code>&nbsp;表示第 <code>i</code> 个工作的难度，<code>profit[i]</code> 表示第 <code>i</code> 个工作的收益。</li>
	<li><code>worker[i]</code> 是第 <code>i</code> 个工人的能力，即该工人只能完成难度小于等于 <code>worker[i]</code> 的工作。</li>
</ul>

<p>每个工人&nbsp;<strong>最多</strong> 只能安排 <strong>一个</strong> 工作，但是一个工作可以 <strong>完成多次</strong> 。</p>

<ul>
	<li>举个例子，如果 3 个工人都尝试完成一份报酬为 <code>$1</code> 的同样工作，那么总收益为 <code>$3</code>&nbsp;。如果一个工人不能完成任何工作，他的收益为 <code>$0</code> 。</li>
</ul>

<p>返回 <em>在把工人分配到工作岗位后，我们所能获得的最大利润&nbsp;</em>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入: </strong>difficulty = [2,4,6,8,10], profit = [10,20,30,40,50], worker = [4,5,6,7]
<strong>输出: </strong>100 
<strong>解释: </strong>工人被分配的工作难度是 [4,4,6,6] ，分别获得 [20,20,30,30] 的收益。</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> difficulty = [85,47,57], profit = [24,66,99], worker = [40,25,25]
<strong>输出:</strong> 0</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>n == difficulty.length</code></li>
	<li><code>n == profit.length</code></li>
	<li><code>m == worker.length</code></li>
	<li><code>1 &lt;= n, m &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= difficulty[i], profit[i], worker[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：排序 + 双指针

我们可以将工作按照能力升序排列，然后将工作按照难度升序排列。

然后我们遍历工人，对于每个工人，我们找出他能完成的工作中收益最大的那个，然后将这个收益加到答案中。

时间复杂度 $O(n \times \log n + m \times \log m)$，空间复杂度 $O(n)$。其中 $n$ 和 $m$ 分别是数组 `profit` 和 `worker` 的长度。

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

我们不妨记 $m = \max(\textit{difficulty})$，定义一个长度为 $m + 1$ 的数组 $f$，其中 $f[i]$ 表示难度小于等于 $i$ 的工作中收益的最大值，初始时 $f[i] = 0$。

然后我们遍历工作，对于每个工作 $(d, p)$，我们更新 $f[d] = \max(f[d], p)$。

接下来，我们从 $1$ 到 $m$ 遍历，对于每个 $i$，我们更新 $f[i] = \max(f[i], f[i - 1])$。

最后，我们遍历工人，对于每个工人 $w$，我们将 $f[\min(w, m)]$ 加到答案中。

时间复杂度 $O(n + M)$，空间复杂度 $O(M)$。其中 $n$ 是数组 `profit` 的长度，而 $M$ 是数组 `difficulty` 中的最大值。

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
    def maxProfitAssignment(
        self, difficulty: List[int], profit: List[int], worker: List[int]
    ) -> int:
        m = max(difficulty)
        f = [0] * (m + 1)
        for d, p in zip(difficulty, profit):
            f[d] = max(f[d], p)
        for i in range(1, m + 1):
            f[i] = max(f[i], f[i - 1])
        return sum(f[min(w, m)] for w in worker)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxProfitAssignment(int[] difficulty, int[] profit, int[] worker) {
        int m = Arrays.stream(difficulty).max().getAsInt();
        int[] f = new int[m + 1];
        int n = profit.length;
        for (int i = 0; i < n; ++i) {
            int d = difficulty[i];
            f[d] = Math.max(f[d], profit[i]);
        }
        for (int i = 1; i <= m; ++i) {
            f[i] = Math.max(f[i], f[i - 1]);
        }
        int ans = 0;
        for (int w : worker) {
            ans += f[Math.min(w, m)];
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
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int m = *max_element(begin(difficulty), end(difficulty));
        int f[m + 1];
        memset(f, 0, sizeof(f));
        int n = profit.size();
        for (int i = 0; i < n; ++i) {
            int d = difficulty[i];
            f[d] = max(f[d], profit[i]);
        }
        for (int i = 1; i <= m; ++i) {
            f[i] = max(f[i], f[i - 1]);
        }
        int ans = 0;
        for (int w : worker) {
            ans += f[min(w, m)];
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxProfitAssignment(difficulty []int, profit []int, worker []int) (ans int) {
	m := slices.Max(difficulty)
	f := make([]int, m+1)
	for i, d := range difficulty {
		f[d] = max(f[d], profit[i])
	}
	for i := 1; i <= m; i++ {
		f[i] = max(f[i], f[i-1])
	}
	for _, w := range worker {
		ans += f[min(w, m)]
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxProfitAssignment(difficulty: number[], profit: number[], worker: number[]): number {
    const m = Math.max(...difficulty);
    const f = Array(m + 1).fill(0);
    const n = profit.length;
    for (let i = 0; i < n; ++i) {
        const d = difficulty[i];
        f[d] = Math.max(f[d], profit[i]);
    }
    for (let i = 1; i <= m; ++i) {
        f[i] = Math.max(f[i], f[i - 1]);
    }
    return worker.reduce((acc, w) => acc + f[Math.min(w, m)], 0);
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def maxProfitAssignment(
        self, difficulty: List[int], profit: List[int], worker: List[int]
    ) -> int:
        m = max(difficulty)
        f = [0] * (m + 1)
        for d, p in zip(difficulty, profit):
            f[d] = max(f[d], p)
        for i in range(1, m + 1):
            f[i] = max(f[i], f[i - 1])
        return sum(f[min(w, m)] for w in worker)
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public int maxProfitAssignment(int[] difficulty, int[] profit, int[] worker) {
        int m = Arrays.stream(difficulty).max().getAsInt();
        int[] f = new int[m + 1];
        int n = profit.length;
        for (int i = 0; i < n; ++i) {
            int d = difficulty[i];
            f[d] = Math.max(f[d], profit[i]);
        }
        for (int i = 1; i <= m; ++i) {
            f[i] = Math.max(f[i], f[i - 1]);
        }
        int ans = 0;
        for (int w : worker) {
            ans += f[Math.min(w, m)];
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
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int m = *max_element(begin(difficulty), end(difficulty));
        int f[m + 1];
        memset(f, 0, sizeof(f));
        int n = profit.size();
        for (int i = 0; i < n; ++i) {
            int d = difficulty[i];
            f[d] = max(f[d], profit[i]);
        }
        for (int i = 1; i <= m; ++i) {
            f[i] = max(f[i], f[i - 1]);
        }
        int ans = 0;
        for (int w : worker) {
            ans += f[min(w, m)];
        }
        return ans;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}