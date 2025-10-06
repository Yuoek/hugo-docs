---
title: "2244_MinimumRoundstoCompleteAllTasks"
date: 2025-10-06T00:42:37+08:00
weight: 2244
tags: [贪心, 数组, 哈希表, 计数]
---


{{< katex />}}

{{< badge title="Difficulty" value="中等" >}}

<!-- problem:start -->

# [2244. 完成所有任务需要的最少轮数](https://leetcode.cn/problems/minimum-rounds-to-complete-all-tasks)

[English Version](../en/2244-44/2244_MinimumRoundstoCompleteAllTasks)

## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong> 开始的整数数组 <code>tasks</code> ，其中 <code>tasks[i]</code> 表示任务的难度级别。在每一轮中，你可以完成 2 个或者 3 个 <strong>相同难度级别</strong> 的任务。</p>

<p>返回完成所有任务需要的 <strong>最少</strong> 轮数，如果无法完成所有任务，返回<em> </em><code>-1</code><em> </em>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>tasks = [2,2,3,3,2,4,4,4,4,4]
<strong>输出：</strong>4
<strong>解释：</strong>要想完成所有任务，一个可能的计划是：
- 第一轮，完成难度级别为 2 的 3 个任务。 
- 第二轮，完成难度级别为 3 的 2 个任务。 
- 第三轮，完成难度级别为 4 的 3 个任务。 
- 第四轮，完成难度级别为 4 的 2 个任务。 
可以证明，无法在少于 4 轮的情况下完成所有任务，所以答案为 4 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>tasks = [2,3,3]
<strong>输出：</strong>-1
<strong>解释：</strong>难度级别为 2 的任务只有 1 个，但每一轮执行中，只能选择完成 2 个或者 3 个相同难度级别的任务。因此，无法完成所有任务，答案为 -1 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= tasks.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= tasks[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：哈希表

我们用哈希表统计每个难度级别的任务数量，然后遍历哈希表，对于每个难度级别的任务数量，如果数量为 $1$，则无法完成所有任务，返回 $-1$；否则，计算完成该难度级别的任务需要的轮数，累加到答案中。

最后返回答案即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 `tasks` 的长度。

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
    def minimumRounds(self, tasks: List[int]) -> int:
        cnt = Counter(tasks)
        ans = 0
        for v in cnt.values():
            if v == 1:
                return -1
            ans += v // 3 + (v % 3 != 0)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumRounds(int[] tasks) {
        Map<Integer, Integer> cnt = new HashMap<>();
        for (int t : tasks) {
            cnt.merge(t, 1, Integer::sum);
        }
        int ans = 0;
        for (int v : cnt.values()) {
            if (v == 1) {
                return -1;
            }
            ans += v / 3 + (v % 3 == 0 ? 0 : 1);
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
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> cnt;
        for (auto& t : tasks) {
            ++cnt[t];
        }
        int ans = 0;
        for (auto& [_, v] : cnt) {
            if (v == 1) {
                return -1;
            }
            ans += v / 3 + (v % 3 != 0);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumRounds(tasks []int) int {
	cnt := map[int]int{}
	for _, t := range tasks {
		cnt[t]++
	}
	ans := 0
	for _, v := range cnt {
		if v == 1 {
			return -1
		}
		ans += v / 3
		if v%3 != 0 {
			ans++
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumRounds(tasks: number[]): number {
    const cnt = new Map();
    for (const t of tasks) {
        cnt.set(t, (cnt.get(t) || 0) + 1);
    }
    let ans = 0;
    for (const v of cnt.values()) {
        if (v == 1) {
            return -1;
        }
        ans += Math.floor(v / 3) + (v % 3 === 0 ? 0 : 1);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashMap;

impl Solution {
    pub fn minimum_rounds(tasks: Vec<i32>) -> i32 {
        let mut cnt = HashMap::new();
        for &t in tasks.iter() {
            let count = cnt.entry(t).or_insert(0);
            *count += 1;
        }
        let mut ans = 0;
        for &v in cnt.values() {
            if v == 1 {
                return -1;
            }
            ans += v / 3 + (if v % 3 == 0 { 0 } else { 1 });
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
    def minimumRounds(self, tasks: List[int]) -> int:
        cnt = Counter(tasks)
        ans = 0
        for v in cnt.values():
            if v == 1:
                return -1
            ans += v // 3 + (v % 3 != 0)
        return ans
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public int minimumRounds(int[] tasks) {
        Map<Integer, Integer> cnt = new HashMap<>();
        for (int t : tasks) {
            cnt.merge(t, 1, Integer::sum);
        }
        int ans = 0;
        for (int v : cnt.values()) {
            if (v == 1) {
                return -1;
            }
            ans += v / 3 + (v % 3 == 0 ? 0 : 1);
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
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> cnt;
        for (auto& t : tasks) {
            ++cnt[t];
        }
        int ans = 0;
        for (auto& [_, v] : cnt) {
            if (v == 1) {
                return -1;
            }
            ans += v / 3 + (v % 3 != 0);
        }
        return ans;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}