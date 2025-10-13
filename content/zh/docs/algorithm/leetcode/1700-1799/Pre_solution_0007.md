---
title: "1760_袋子里最少数目的球"
date: 2025-10-08T18:38:17+08:00
weight: 7
tags: [二分查找, 位运算, 分治, 前缀和, 单调栈, 双指针, 哈希表, 图, 字符串, 字符串匹配, 广度优先搜索, 数学, 数据库, 数组, 数论, 枚举, 栈, 树, 深度优先搜索, 滑动窗口, 矩阵, 贪心]
---

{{< markmap >}}
### [1760_袋子里最少数目的球](#1760)
#### [数组](#1760)
#### [二分查找](#1760)
### [1761_一个图中连通三元组的最小度数](#1761)
#### [图](#1761)
#### [枚举](#1761)
### [1762_能看到海景的建筑物 🔒](#1762)
#### [栈](#1762)
#### [数组](#1762)
#### [单调栈](#1762)
### [1763_最长的美好子字符串](#1763)
#### [位运算](#1763)
#### [哈希表](#1763)
#### [字符串](#1763)
#### [分治](#1763)
#### [滑动窗口](#1763)
### [1764_通过连接另一个数组的子数组得到一个数组](#1764)
#### [贪心](#1764)
#### [数组](#1764)
#### [双指针](#1764)
#### [字符串匹配](#1764)
### [1765_地图中的最高点](#1765)
#### [广度优先搜索](#1765)
#### [数组](#1765)
#### [矩阵](#1765)
### [1766_互质树](#1766)
#### [树](#1766)
#### [深度优先搜索](#1766)
#### [数组](#1766)
#### [数学](#1766)
#### [数论](#1766)
### [1767_寻找没有被执行的任务对 🔒](#1767)
#### [数据库](#1767)
### [1768_交替合并字符串](#1768)
#### [双指针](#1768)
#### [字符串](#1768)
### [1769_移动所有球到每个盒子所需的最小操作数](#1769)
#### [数组](#1769)
#### [字符串](#1769)
#### [前缀和](#1769)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1760_袋子里最少数目的球
___
#### 数组
___
#### 二分查找
---
### 1761_一个图中连通三元组的最小度数
___
#### 图
___
#### 枚举
---
### 1762_能看到海景的建筑物 🔒
___
#### 栈
___
#### 数组
___
#### 单调栈
---
### 1763_最长的美好子字符串
___
#### 位运算
___
#### 哈希表
___
#### 字符串
___
#### 分治
___
#### 滑动窗口
---
### 1764_通过连接另一个数组的子数组得到一个数组
___
#### 贪心
___
#### 数组
___
#### 双指针
___
#### 字符串匹配
---
### 1765_地图中的最高点
___
#### 广度优先搜索
___
#### 数组
___
#### 矩阵
---
### 1766_互质树
___
#### 树
___
#### 深度优先搜索
___
#### 数组
___
#### 数学
___
#### 数论
---
### 1767_寻找没有被执行的任务对 🔒
___
#### 数据库
---
### 1768_交替合并字符串
___
#### 双指针
___
#### 字符串
---
### 1769_移动所有球到每个盒子所需的最小操作数
___
#### 数组
___
#### 字符串
___
#### 前缀和
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 位运算 | 分治 |
| 前缀和 | 单调栈 | 双指针 |
| 哈希表 | 图 | 字符串 |
| 字符串匹配 | 广度优先搜索 | 数学 |
| 数据库 | 数组 | 数论 |
| 枚举 | 栈 | 树 |
| 深度优先搜索 | 滑动窗口 | 矩阵 |
| 贪心 |  |  |

# [1760. 袋子里最少数目的球](https://leetcode.cn/problems/minimum-limit-of-balls-in-a-bag){#1760}

{{< tabs "1760" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumSize(self, nums: List[int], maxOperations: int) -> int:
        def check(mx: int) -> bool:
            return sum((x - 1) // mx for x in nums) <= maxOperations

        return bisect_left(range(1, max(nums) + 1), True, key=check) + 1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumSize(int[] nums, int maxOperations) {
        int l = 1, r = Arrays.stream(nums).max().getAsInt();
        while (l < r) {
            int mid = (l + r) >> 1;
            long s = 0;
            for (int x : nums) {
                s += (x - 1) / mid;
            }
            if (s <= maxOperations) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1, r = ranges::max(nums);
        while (l < r) {
            int mid = (l + r) >> 1;
            long long s = 0;
            for (int x : nums) {
                s += (x - 1) / mid;
            }
            if (s <= maxOperations) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumSize(nums []int, maxOperations int) int {
	r := slices.Max(nums)
	return 1 + sort.Search(r, func(mx int) bool {
		mx++
		s := 0
		for _, x := range nums {
			s += (x - 1) / mx
		}
		return s <= maxOperations
	})
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumSize(nums: number[], maxOperations: number): number {
    let [l, r] = [1, Math.max(...nums)];
    while (l < r) {
        const mid = (l + r) >> 1;
        const s = nums.map(x => ((x - 1) / mid) | 0).reduce((a, b) => a + b);
        if (s <= maxOperations) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn minimum_size(nums: Vec<i32>, max_operations: i32) -> i32 {
        let mut l = 1;
        let mut r = *nums.iter().max().unwrap();

        while l < r {
            let mid = (l + r) / 2;
            let mut s: i64 = 0;

            for &x in &nums {
                s += ((x - 1) / mid) as i64;
            }

            if s <= max_operations as i64 {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        l
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} nums
 * @param {number} maxOperations
 * @return {number}
 */
var minimumSize = function (nums, maxOperations) {
    let [l, r] = [1, Math.max(...nums)];
    while (l < r) {
        const mid = (l + r) >> 1;
        const s = nums.map(x => ((x - 1) / mid) | 0).reduce((a, b) => a + b);
        if (s <= maxOperations) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int MinimumSize(int[] nums, int maxOperations) {
        int l = 1, r = nums.Max();
        while (l < r) {
            int mid = (l + r) >> 1;
            long s = 0;
            foreach (int x in nums) {
                s += (x - 1) / mid;
            }
            if (s <= maxOperations) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>nums</code> ，其中 <code>nums[i]</code> 表示第 <code>i</code> 个袋子里球的数目。同时给你一个整数 <code>maxOperations</code> 。</p>

<p>你可以进行如下操作至多 <code>maxOperations</code> 次：</p>

<ul>
	<li>选择任意一个袋子，并将袋子里的球分到 2 个新的袋子中，每个袋子里都有 <strong>正整数</strong> 个球。

    <ul>
    	<li>比方说，一个袋子里有 <code>5</code> 个球，你可以把它们分到两个新袋子里，分别有 <code>1</code> 个和 <code>4</code> 个球，或者分别有 <code>2</code> 个和 <code>3</code> 个球。</li>
    </ul>
    </li>

</ul>

<p>你的开销是单个袋子里球数目的 <strong>最大值</strong> ，你想要 <strong>最小化</strong> 开销。</p>

<p>请你返回进行上述操作后的最小开销。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [9], maxOperations = 2
<b>输出：</b>3
<b>解释：</b>
- 将装有 9 个球的袋子分成装有 6 个和 3 个球的袋子。[<strong>9</strong>] -> [6,3] 。
- 将装有 6 个球的袋子分成装有 3 个和 3 个球的袋子。[<strong>6</strong>,3] -> [3,3,3] 。
装有最多球的袋子里装有 3 个球，所以开销为 3 并返回 3 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [2,4,8,2], maxOperations = 4
<b>输出：</b>2
<strong>解释：</strong>
- 将装有 8 个球的袋子分成装有 4 个和 4 个球的袋子。[2,4,<strong>8</strong>,2] -> [2,4,4,4,2] 。
- 将装有 4 个球的袋子分成装有 2 个和 2 个球的袋子。[2,<strong>4</strong>,4,4,2] -> [2,2,2,4,4,2] 。
- 将装有 4 个球的袋子分成装有 2 个和 2 个球的袋子。[2,2,2,<strong>4</strong>,4,2] -> [2,2,2,2,2,4,2] 。
- 将装有 4 个球的袋子分成装有 2 个和 2 个球的袋子。[2,2,2,2,2,<strong>4</strong>,2] -> [2,2,2,2,2,2,2,2] 。
装有最多球的袋子里装有 2 个球，所以开销为 2 并返回 2 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>nums = [7,17], maxOperations = 2
<b>输出：</b>7
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= nums.length <= 10<sup>5</sup></code></li>
	<li><code>1 <= maxOperations, nums[i] <= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二分查找

本题需要我们最小化开销，即最小化单个袋子里球数目的最大值。随着最大值的增大，操作次数会减少，越容易满足条件。

因此，我们可以二分枚举单个袋子里球数目的最大值，判断是否能在 $\textit{maxOperations}$ 次操作内得到。

具体地，我们定义二分查找的左边界 $l = 1$，右边界 $r = \max(\textit{nums})$。然后我们不断二分枚举中间值 $\textit{mid} = \frac{l + r}{2}$，对于每个 $\textit{mid}$，我们计算在这个 $\textit{mid}$ 下，需要的操作次数。如果操作次数小于等于 $\textit{maxOperations}$，说明 $\textit{mid}$ 满足条件，我们将右边界 $r$ 更新为 $\textit{mid}$，否则将左边界 $l$ 更新为 $\textit{mid} + 1$。

最后，我们返回左边界 $l$ 即可。

时间复杂度 $O(n \times \log M)$，其中 $n$ 和 $M$ 分别是数组 $\textit{nums}$ 的长度和最大值。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumSize(self, nums: List[int], maxOperations: int) -> int:
        def check(mx: int) -> bool:
            return sum((x - 1) // mx for x in nums) <= maxOperations

        return bisect_left(range(1, max(nums) + 1), True, key=check) + 1
```

#### Java

```java
class Solution {
    public int minimumSize(int[] nums, int maxOperations) {
        int l = 1, r = Arrays.stream(nums).max().getAsInt();
        while (l < r) {
            int mid = (l + r) >> 1;
            long s = 0;
            for (int x : nums) {
                s += (x - 1) / mid;
            }
            if (s <= maxOperations) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1, r = ranges::max(nums);
        while (l < r) {
            int mid = (l + r) >> 1;
            long long s = 0;
            for (int x : nums) {
                s += (x - 1) / mid;
            }
            if (s <= maxOperations) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
```

#### Go

```go
func minimumSize(nums []int, maxOperations int) int {
	r := slices.Max(nums)
	return 1 + sort.Search(r, func(mx int) bool {
		mx++
		s := 0
		for _, x := range nums {
			s += (x - 1) / mx
		}
		return s <= maxOperations
	})
}
```

#### TypeScript

```ts
function minimumSize(nums: number[], maxOperations: number): number {
    let [l, r] = [1, Math.max(...nums)];
    while (l < r) {
        const mid = (l + r) >> 1;
        const s = nums.map(x => ((x - 1) / mid) | 0).reduce((a, b) => a + b);
        if (s <= maxOperations) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}
```

#### Rust

```rust
impl Solution {
    pub fn minimum_size(nums: Vec<i32>, max_operations: i32) -> i32 {
        let mut l = 1;
        let mut r = *nums.iter().max().unwrap();

        while l < r {
            let mid = (l + r) / 2;
            let mut s: i64 = 0;

            for &x in &nums {
                s += ((x - 1) / mid) as i64;
            }

            if s <= max_operations as i64 {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        l
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @param {number} maxOperations
 * @return {number}
 */
var minimumSize = function (nums, maxOperations) {
    let [l, r] = [1, Math.max(...nums)];
    while (l < r) {
        const mid = (l + r) >> 1;
        const s = nums.map(x => ((x - 1) / mid) | 0).reduce((a, b) => a + b);
        if (s <= maxOperations) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
};
```

#### C#

```cs
public class Solution {
    public int MinimumSize(int[] nums, int maxOperations) {
        int l = 1, r = nums.Max();
        while (l < r) {
            int mid = (l + r) >> 1;
            long s = 0;
            foreach (int x in nums) {
                s += (x - 1) / mid;
            }
            if (s <= maxOperations) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1761. 一个图中连通三元组的最小度数](https://leetcode.cn/problems/minimum-degree-of-a-connected-trio-in-a-graph){#1761}

{{< tabs "1761" >}}

{{% tab "python" %}}
```python
def min(a: int, b: int) -> int:
    return a if a < b else b


class Solution:
    def minTrioDegree(self, n: int, edges: List[List[int]]) -> int:
        g = [[False] * n for _ in range(n)]
        deg = [0] * n
        for u, v in edges:
            u, v = u - 1, v - 1
            g[u][v] = g[v][u] = True
            deg[u] += 1
            deg[v] += 1
        ans = inf
        for i in range(n):
            for j in range(i + 1, n):
                if g[i][j]:
                    for k in range(j + 1, n):
                        if g[i][k] and g[j][k]:
                            ans = min(ans, deg[i] + deg[j] + deg[k] - 6)
        return -1 if ans == inf else ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minTrioDegree(int n, int[][] edges) {
        boolean[][] g = new boolean[n][n];
        int[] deg = new int[n];
        for (var e : edges) {
            int u = e[0] - 1, v = e[1] - 1;
            g[u][v] = true;
            g[v][u] = true;
            ++deg[u];
            ++deg[v];
        }
        int ans = 1 << 30;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (g[i][j]) {
                    for (int k = j + 1; k < n; ++k) {
                        if (g[i][k] && g[j][k]) {
                            ans = Math.min(ans, deg[i] + deg[j] + deg[k] - 6);
                        }
                    }
                }
            }
        }
        return ans == 1 << 30 ? -1 : ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        bool g[n][n];
        memset(g, 0, sizeof g);
        int deg[n];
        memset(deg, 0, sizeof deg);
        for (auto& e : edges) {
            int u = e[0] - 1, v = e[1] - 1;
            g[u][v] = g[v][u] = true;
            deg[u]++, deg[v]++;
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (g[i][j]) {
                    for (int k = j + 1; k < n; ++k) {
                        if (g[j][k] && g[i][k]) {
                            ans = min(ans, deg[i] + deg[j] + deg[k] - 6);
                        }
                    }
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minTrioDegree(n int, edges [][]int) int {
	g := make([][]bool, n)
	deg := make([]int, n)
	for i := range g {
		g[i] = make([]bool, n)
	}
	for _, e := range edges {
		u, v := e[0]-1, e[1]-1
		g[u][v], g[v][u] = true, true
		deg[u]++
		deg[v]++
	}
	ans := 1 << 30
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			if g[i][j] {
				for k := j + 1; k < n; k++ {
					if g[i][k] && g[j][k] {
						ans = min(ans, deg[i]+deg[j]+deg[k]-6)
					}
				}
			}
		}
	}
	if ans == 1<<30 {
		return -1
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minTrioDegree(n: number, edges: number[][]): number {
    const g = Array.from({ length: n }, () => Array(n).fill(false));
    const deg: number[] = Array(n).fill(0);
    for (let [u, v] of edges) {
        u--;
        v--;
        g[u][v] = g[v][u] = true;
        ++deg[u];
        ++deg[v];
    }
    let ans = Infinity;
    for (let i = 0; i < n; ++i) {
        for (let j = i + 1; j < n; ++j) {
            if (g[i][j]) {
                for (let k = j + 1; k < n; ++k) {
                    if (g[i][k] && g[j][k]) {
                        ans = Math.min(ans, deg[i] + deg[j] + deg[k] - 6);
                    }
                }
            }
        }
    }
    return ans === Infinity ? -1 : ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个无向图，整数 <code>n</code> 表示图中节点的数目，<code>edges</code> 数组表示图中的边，其中 <code>edges[i] = [u<sub>i</sub>, v<sub>i</sub>]</code> ，表示 <code>u<sub>i</sub></code> 和 <code>v<sub>i</sub></code><sub> </sub>之间有一条无向边。</p>

<p>一个 <strong>连通三元组</strong> 指的是 <strong>三个</strong> 节点组成的集合且这三个点之间 <strong>两两</strong> 有边。</p>

<p><strong>连通三元组的度数</strong> 是所有满足此条件的边的数目：一个顶点在这个三元组内，而另一个顶点不在这个三元组内。</p>

<p>请你返回所有连通三元组中度数的 <strong>最小值</strong> ，如果图中没有连通三元组，那么返回 <code>-1</code> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1700-1799/1761.Minimum%20Degree%20of%20a%20Connected%20Trio%20in%20a%20Graph/images/trios1.png" style="width: 388px; height: 164px;" />
<pre>
<b>输入：</b>n = 6, edges = [[1,2],[1,3],[3,2],[4,1],[5,2],[3,6]]
<b>输出：</b>3
<b>解释：</b>只有一个三元组 [1,2,3] 。构成度数的边在上图中已被加粗。
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1700-1799/1761.Minimum%20Degree%20of%20a%20Connected%20Trio%20in%20a%20Graph/images/trios2.png" style="width: 388px; height: 164px;" />
<pre>
<b>输入：</b>n = 7, edges = [[1,3],[4,1],[4,3],[2,5],[5,6],[6,7],[7,5],[2,6]]
<b>输出：</b>0
<b>解释：</b>有 3 个三元组：
1) [1,4,3]，度数为 0 。
2) [2,5,6]，度数为 2 。
3) [5,6,7]，度数为 2 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 <= n <= 400</code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>1 <= edges.length <= n * (n-1) / 2</code></li>
	<li><code>1 <= u<sub>i</sub>, v<sub>i</sub> <= n</code></li>
	<li><code>u<sub>i </sub>!= v<sub>i</sub></code></li>
	<li>图中没有重复的边。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：暴力枚举

我们先将所有边存入邻接矩阵 $\textit{g}$ 中，再将每个节点的度数存入数组 $\textit{deg}$ 中。初始化答案 $\textit{ans}=+\infty$。

然后枚举所有的三元组 $(i, j, k)$，其中 $i \lt j \lt k$，如果 $\textit{g}[i][j] = \textit{g}[j][k] = \textit{g}[i][k] = 1$，则说明这三个节点构成了一个连通三元组，此时更新答案为 $\textit{ans} = \min(\textit{ans}, \textit{deg}[i] + \textit{deg}[j] + \textit{deg}[k] - 6)$。

枚举完所有的三元组后，如果答案仍然为 $+\infty$，说明图中不存在连通三元组，返回 $-1$，否则返回答案。

时间复杂度 $O(n^3)$，空间复杂度 $O(n^2)$。其中 $n$ 为节点数。

<!-- tabs:start -->

#### Python3

```python
def min(a: int, b: int) -> int:
    return a if a < b else b


class Solution:
    def minTrioDegree(self, n: int, edges: List[List[int]]) -> int:
        g = [[False] * n for _ in range(n)]
        deg = [0] * n
        for u, v in edges:
            u, v = u - 1, v - 1
            g[u][v] = g[v][u] = True
            deg[u] += 1
            deg[v] += 1
        ans = inf
        for i in range(n):
            for j in range(i + 1, n):
                if g[i][j]:
                    for k in range(j + 1, n):
                        if g[i][k] and g[j][k]:
                            ans = min(ans, deg[i] + deg[j] + deg[k] - 6)
        return -1 if ans == inf else ans
```

#### Java

```java
class Solution {
    public int minTrioDegree(int n, int[][] edges) {
        boolean[][] g = new boolean[n][n];
        int[] deg = new int[n];
        for (var e : edges) {
            int u = e[0] - 1, v = e[1] - 1;
            g[u][v] = true;
            g[v][u] = true;
            ++deg[u];
            ++deg[v];
        }
        int ans = 1 << 30;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (g[i][j]) {
                    for (int k = j + 1; k < n; ++k) {
                        if (g[i][k] && g[j][k]) {
                            ans = Math.min(ans, deg[i] + deg[j] + deg[k] - 6);
                        }
                    }
                }
            }
        }
        return ans == 1 << 30 ? -1 : ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        bool g[n][n];
        memset(g, 0, sizeof g);
        int deg[n];
        memset(deg, 0, sizeof deg);
        for (auto& e : edges) {
            int u = e[0] - 1, v = e[1] - 1;
            g[u][v] = g[v][u] = true;
            deg[u]++, deg[v]++;
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (g[i][j]) {
                    for (int k = j + 1; k < n; ++k) {
                        if (g[j][k] && g[i][k]) {
                            ans = min(ans, deg[i] + deg[j] + deg[k] - 6);
                        }
                    }
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
```

#### Go

```go
func minTrioDegree(n int, edges [][]int) int {
	g := make([][]bool, n)
	deg := make([]int, n)
	for i := range g {
		g[i] = make([]bool, n)
	}
	for _, e := range edges {
		u, v := e[0]-1, e[1]-1
		g[u][v], g[v][u] = true, true
		deg[u]++
		deg[v]++
	}
	ans := 1 << 30
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			if g[i][j] {
				for k := j + 1; k < n; k++ {
					if g[i][k] && g[j][k] {
						ans = min(ans, deg[i]+deg[j]+deg[k]-6)
					}
				}
			}
		}
	}
	if ans == 1<<30 {
		return -1
	}
	return ans
}
```

#### TypeScript

```ts
function minTrioDegree(n: number, edges: number[][]): number {
    const g = Array.from({ length: n }, () => Array(n).fill(false));
    const deg: number[] = Array(n).fill(0);
    for (let [u, v] of edges) {
        u--;
        v--;
        g[u][v] = g[v][u] = true;
        ++deg[u];
        ++deg[v];
    }
    let ans = Infinity;
    for (let i = 0; i < n; ++i) {
        for (let j = i + 1; j < n; ++j) {
            if (g[i][j]) {
                for (let k = j + 1; k < n; ++k) {
                    if (g[i][k] && g[j][k]) {
                        ans = Math.min(ans, deg[i] + deg[j] + deg[k] - 6);
                    }
                }
            }
        }
    }
    return ans === Infinity ? -1 : ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1762. 能看到海景的建筑物 🔒](https://leetcode.cn/problems/buildings-with-an-ocean-view){#1762}

{{< tabs "1762" >}}

{{% tab "python" %}}
```python
class Solution:
    def findBuildings(self, heights: List[int]) -> List[int]:
        ans = []
        mx = 0
        for i in range(len(heights) - 1, -1, -1):
            if heights[i] > mx:
                ans.append(i)
                mx = heights[i]
        return ans[::-1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] findBuildings(int[] heights) {
        int n = heights.length;
        List<Integer> ans = new ArrayList<>();
        int mx = 0;
        for (int i = heights.length - 1; i >= 0; --i) {
            if (heights[i] > mx) {
                ans.add(i);
                mx = heights[i];
            }
        }
        Collections.reverse(ans);
        return ans.stream().mapToInt(Integer::intValue).toArray();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int> ans;
        int mx = 0;
        for (int i = heights.size() - 1; ~i; --i) {
            if (heights[i] > mx) {
                ans.push_back(i);
                mx = heights[i];
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findBuildings(heights []int) (ans []int) {
	mx := 0
	for i := len(heights) - 1; i >= 0; i-- {
		if v := heights[i]; v > mx {
			ans = append(ans, i)
			mx = v
		}
	}
	for i, j := 0, len(ans)-1; i < j; i, j = i+1, j-1 {
		ans[i], ans[j] = ans[j], ans[i]
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findBuildings(heights: number[]): number[] {
    const ans: number[] = [];
    let mx = 0;
    for (let i = heights.length - 1; ~i; --i) {
        if (heights[i] > mx) {
            ans.push(i);
            mx = heights[i];
        }
    }
    return ans.reverse();
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} heights
 * @return {number[]}
 */
var findBuildings = function (heights) {
    const ans = [];
    let mx = 0;
    for (let i = heights.length - 1; ~i; --i) {
        if (heights[i] > mx) {
            ans.push(i);
            mx = heights[i];
        }
    }
    return ans.reverse();
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>有 <code>n</code> 座建筑物。给你一个大小为 <code>n</code> 的整数数组 <code>heights</code> 表示每一个建筑物的高度。</p>

<p>建筑物的右边是海洋。如果建筑物可以无障碍地看到海洋，则建筑物能看到海景。确切地说，如果一座建筑物右边的所有建筑都比它 <strong>矮</strong> 时，就认为它能看到海景。</p>

<p>返回能看到海景建筑物的下标列表（下标 <strong>从 <code>0</code> 开始</strong> ），并按升序排列。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>heights = [4,2,3,1]
<strong>输出：</strong>[0,2,3]
<strong>解释：</strong>1 号建筑物看不到海景，因为 2 号建筑物比它高
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>heights = [4,3,2,1]
<strong>输出：</strong>[0,1,2,3]
<strong>解释：</strong>所有的建筑物都能看到海景。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>heights = [1,3,2,4]
<strong>输出：</strong>[3]
<strong>解释：</strong>只有 3 号建筑物能看到海景。</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>heights = [2,2,2,2]
<strong>输出：</strong>[3]
<strong>解释：</strong>如果建筑物右边有相同高度的建筑物则无法看到海景。</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= heights.length <= 10<sup>5</sup></code></li>
	<li><code>1 <= heights[i] <= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：逆序遍历求右侧最大值

我们逆序遍历数组 $\textit{height}$ 每个元素 $v$，判断 $v$ 与右侧最大元素 $mx$ 的大小关系，若 $mx \lt v$，说明右侧所有元素都比当前元素小，当前位置能看到海景，加入结果数组 $\textit{ans}$。然后我们更新 $mx$ 为 $v$。

遍历结束后，逆序返回 $\textit{ans}$ 即可。

时间复杂度 $O(n)$，其中 $n$ 为数组长度。忽略答案数组的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findBuildings(self, heights: List[int]) -> List[int]:
        ans = []
        mx = 0
        for i in range(len(heights) - 1, -1, -1):
            if heights[i] > mx:
                ans.append(i)
                mx = heights[i]
        return ans[::-1]
```

#### Java

```java
class Solution {
    public int[] findBuildings(int[] heights) {
        int n = heights.length;
        List<Integer> ans = new ArrayList<>();
        int mx = 0;
        for (int i = heights.length - 1; i >= 0; --i) {
            if (heights[i] > mx) {
                ans.add(i);
                mx = heights[i];
            }
        }
        Collections.reverse(ans);
        return ans.stream().mapToInt(Integer::intValue).toArray();
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int> ans;
        int mx = 0;
        for (int i = heights.size() - 1; ~i; --i) {
            if (heights[i] > mx) {
                ans.push_back(i);
                mx = heights[i];
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```

#### Go

```go
func findBuildings(heights []int) (ans []int) {
	mx := 0
	for i := len(heights) - 1; i >= 0; i-- {
		if v := heights[i]; v > mx {
			ans = append(ans, i)
			mx = v
		}
	}
	for i, j := 0, len(ans)-1; i < j; i, j = i+1, j-1 {
		ans[i], ans[j] = ans[j], ans[i]
	}
	return
}
```

#### TypeScript

```ts
function findBuildings(heights: number[]): number[] {
    const ans: number[] = [];
    let mx = 0;
    for (let i = heights.length - 1; ~i; --i) {
        if (heights[i] > mx) {
            ans.push(i);
            mx = heights[i];
        }
    }
    return ans.reverse();
}
```

#### JavaScript

```js
/**
 * @param {number[]} heights
 * @return {number[]}
 */
var findBuildings = function (heights) {
    const ans = [];
    let mx = 0;
    for (let i = heights.length - 1; ~i; --i) {
        if (heights[i] > mx) {
            ans.push(i);
            mx = heights[i];
        }
    }
    return ans.reverse();
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1763. 最长的美好子字符串](https://leetcode.cn/problems/longest-nice-substring){#1763}

{{< tabs "1763" >}}

{{% tab "python" %}}
```python
class Solution:
    def longestNiceSubstring(self, s: str) -> str:
        n = len(s)
        ans = ''
        for i in range(n):
            lower = upper = 0
            for j in range(i, n):
                if s[j].islower():
                    lower |= 1 << (ord(s[j]) - ord('a'))
                else:
                    upper |= 1 << (ord(s[j]) - ord('A'))
                if lower == upper and len(ans) < j - i + 1:
                    ans = s[i : j + 1]
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String longestNiceSubstring(String s) {
        int n = s.length();
        int k = -1;
        int mx = 0;
        for (int i = 0; i < n; ++i) {
            int lower = 0, upper = 0;
            for (int j = i; j < n; ++j) {
                char c = s.charAt(j);
                if (Character.isLowerCase(c)) {
                    lower |= 1 << (c - 'a');
                } else {
                    upper |= 1 << (c - 'A');
                }
                if (lower == upper && mx < j - i + 1) {
                    mx = j - i + 1;
                    k = i;
                }
            }
        }
        return k == -1 ? "" : s.substring(k, k + mx);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string longestNiceSubstring(string s) {
        int n = s.size();
        int k = -1, mx = 0;
        for (int i = 0; i < n; ++i) {
            int lower = 0, upper = 0;
            for (int j = i; j < n; ++j) {
                char c = s[j];
                if (islower(c))
                    lower |= 1 << (c - 'a');
                else
                    upper |= 1 << (c - 'A');
                if (lower == upper && mx < j - i + 1) {
                    mx = j - i + 1;
                    k = i;
                }
            }
        }
        return k == -1 ? "" : s.substr(k, mx);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func longestNiceSubstring(s string) string {
	n := len(s)
	k, mx := -1, 0
	for i := 0; i < n; i++ {
		var lower, upper int
		for j := i; j < n; j++ {
			if unicode.IsLower(rune(s[j])) {
				lower |= 1 << (s[j] - 'a')
			} else {
				upper |= 1 << (s[j] - 'A')
			}
			if lower == upper && mx < j-i+1 {
				mx = j - i + 1
				k = i
			}
		}
	}
	if k < 0 {
		return ""
	}
	return s[k : k+mx]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function longestNiceSubstring(s: string): string {
    const n = s.length;
    let ans = '';
    for (let i = 0; i < n; i++) {
        let lower = 0,
            upper = 0;
        for (let j = i; j < n; j++) {
            const c = s.charCodeAt(j);
            if (c > 96) {
                lower |= 1 << (c - 97);
            } else {
                upper |= 1 << (c - 65);
            }
            if (lower == upper && j - i + 1 > ans.length) {
                ans = s.substring(i, j + 1);
            }
        }
    }
    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>当一个字符串 <code>s</code> 包含的每一种字母的大写和小写形式 <strong>同时</strong> 出现在 <code>s</code> 中，就称这个字符串 <code>s</code> 是 <strong>美好</strong> 字符串。比方说，<code>"abABB"</code> 是美好字符串，因为 <code>'A'</code> 和 <code>'a'</code> 同时出现了，且 <code>'B'</code> 和 <code>'b'</code> 也同时出现了。然而，<code>"abA"</code> 不是美好字符串因为 <code>'b'</code> 出现了，而 <code>'B'</code> 没有出现。</p>

<p>给你一个字符串 <code>s</code> ，请你返回 <code>s</code> 最长的 <strong>美好子字符串</strong> 。如果有多个答案，请你返回 <strong>最早</strong> 出现的一个。如果不存在美好子字符串，请你返回一个空字符串。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>s = "YazaAay"
<b>输出：</b>"aAa"
<strong>解释：</strong>"aAa" 是一个美好字符串，因为这个子串中仅含一种字母，其小写形式 'a' 和大写形式 'A' 也同时出现了。
"aAa" 是最长的美好子字符串。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>s = "Bb"
<b>输出：</b>"Bb"
<b>解释：</b>"Bb" 是美好字符串，因为 'B' 和 'b' 都出现了。整个字符串也是原字符串的子字符串。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>s = "c"
<b>输出：</b>""
<b>解释：</b>没有美好子字符串。</pre>

<p><strong>示例 4：</strong></p>

<pre>
<b>输入：</b>s = "dDzeE"
<b>输出：</b>"dD"
<strong>解释：</strong>"dD" 和 "eE" 都是最长美好子字符串。
由于有多个美好子字符串，返回 "dD" ，因为它出现得最早。</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= s.length <= 100</code></li>
	<li><code>s</code> 只包含大写和小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举 + 哈希表

我们可以直接枚举所有子串的起点位置 $i$，找到以该位置所在的字符为首字符的所有子串，用哈希表 $s$ 记录子串的所有字符。

如果子串中存在一个字母找不到对应的大写字母或者小写字母，那么不满足条件，否则取最长的且最早出现的子串。

时间复杂度 $O(n^2 \times C)$，空间复杂度 $O(C)$。其中 $n$ 为字符串 $s$ 的长度，而 $C$ 为字符集的大小。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def longestNiceSubstring(self, s: str) -> str:
        n = len(s)
        ans = ''
        for i in range(n):
            ss = set()
            for j in range(i, n):
                ss.add(s[j])
                if (
                    all(c.lower() in ss and c.upper() in ss for c in ss)
                    and len(ans) < j - i + 1
                ):
                    ans = s[i : j + 1]
        return ans
```

#### Java

```java
class Solution {
    public String longestNiceSubstring(String s) {
        int n = s.length();
        int k = -1;
        int mx = 0;
        for (int i = 0; i < n; ++i) {
            Set<Character> ss = new HashSet<>();
            for (int j = i; j < n; ++j) {
                ss.add(s.charAt(j));
                boolean ok = true;
                for (char a : ss) {
                    char b = (char) (a ^ 32);
                    if (!(ss.contains(a) && ss.contains(b))) {
                        ok = false;
                        break;
                    }
                }
                if (ok && mx < j - i + 1) {
                    mx = j - i + 1;
                    k = i;
                }
            }
        }
        return k == -1 ? "" : s.substring(k, k + mx);
    }
}
```

#### C++

```cpp
class Solution {
public:
    string longestNiceSubstring(string s) {
        int n = s.size();
        int k = -1, mx = 0;
        for (int i = 0; i < n; ++i) {
            unordered_set<char> ss;
            for (int j = i; j < n; ++j) {
                ss.insert(s[j]);
                bool ok = true;
                for (auto& a : ss) {
                    char b = a ^ 32;
                    if (!(ss.count(a) && ss.count(b))) {
                        ok = false;
                        break;
                    }
                }
                if (ok && mx < j - i + 1) {
                    mx = j - i + 1;
                    k = i;
                }
            }
        }
        return k == -1 ? "" : s.substr(k, mx);
    }
};
```

#### Go

```go
func longestNiceSubstring(s string) string {
	n := len(s)
	k, mx := -1, 0
	for i := 0; i < n; i++ {
		ss := map[byte]bool{}
		for j := i; j < n; j++ {
			ss[s[j]] = true
			ok := true
			for a := range ss {
				b := a ^ 32
				if !(ss[a] && ss[b]) {
					ok = false
					break
				}
			}
			if ok && mx < j-i+1 {
				mx = j - i + 1
				k = i
			}
		}
	}
	if k < 0 {
		return ""
	}
	return s[k : k+mx]
}
```

#### TypeScript

```ts
function longestNiceSubstring(s: string): string {
    const n = s.length;
    let ans = '';
    for (let i = 0; i < n; i++) {
        let lower = 0,
            upper = 0;
        for (let j = i; j < n; j++) {
            const c = s.charCodeAt(j);
            if (c > 96) {
                lower |= 1 << (c - 97);
            } else {
                upper |= 1 << (c - 65);
            }
            if (lower == upper && j - i + 1 > ans.length) {
                ans = s.substring(i, j + 1);
            }
        }
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：枚举 + 位运算

与方法一类似，我们可以直接枚举所有子串的起点位置 $i$，找到以该位置所在的字符为首字符的所有子串，用两个整数 $lower$ 和 $upper$ 分别记录子串中小写字母和大写字母的出现情况。

判断子串是否满足条件，只需要判断 $lower$ 和 $upper$ 中对应的位是否都为 $1$ 即可。

时间复杂度 $O(n^2)$，空间复杂度 $O(1)$。其中 $n$ 为字符串 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def longestNiceSubstring(self, s: str) -> str:
        n = len(s)
        ans = ''
        for i in range(n):
            lower = upper = 0
            for j in range(i, n):
                if s[j].islower():
                    lower |= 1 << (ord(s[j]) - ord('a'))
                else:
                    upper |= 1 << (ord(s[j]) - ord('A'))
                if lower == upper and len(ans) < j - i + 1:
                    ans = s[i : j + 1]
        return ans
```

#### Java

```java
class Solution {
    public String longestNiceSubstring(String s) {
        int n = s.length();
        int k = -1;
        int mx = 0;
        for (int i = 0; i < n; ++i) {
            int lower = 0, upper = 0;
            for (int j = i; j < n; ++j) {
                char c = s.charAt(j);
                if (Character.isLowerCase(c)) {
                    lower |= 1 << (c - 'a');
                } else {
                    upper |= 1 << (c - 'A');
                }
                if (lower == upper && mx < j - i + 1) {
                    mx = j - i + 1;
                    k = i;
                }
            }
        }
        return k == -1 ? "" : s.substring(k, k + mx);
    }
}
```

#### C++

```cpp
class Solution {
public:
    string longestNiceSubstring(string s) {
        int n = s.size();
        int k = -1, mx = 0;
        for (int i = 0; i < n; ++i) {
            int lower = 0, upper = 0;
            for (int j = i; j < n; ++j) {
                char c = s[j];
                if (islower(c))
                    lower |= 1 << (c - 'a');
                else
                    upper |= 1 << (c - 'A');
                if (lower == upper && mx < j - i + 1) {
                    mx = j - i + 1;
                    k = i;
                }
            }
        }
        return k == -1 ? "" : s.substr(k, mx);
    }
};
```

#### Go

```go
func longestNiceSubstring(s string) string {
	n := len(s)
	k, mx := -1, 0
	for i := 0; i < n; i++ {
		var lower, upper int
		for j := i; j < n; j++ {
			if unicode.IsLower(rune(s[j])) {
				lower |= 1 << (s[j] - 'a')
			} else {
				upper |= 1 << (s[j] - 'A')
			}
			if lower == upper && mx < j-i+1 {
				mx = j - i + 1
				k = i
			}
		}
	}
	if k < 0 {
		return ""
	}
	return s[k : k+mx]
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1764. 通过连接另一个数组的子数组得到一个数组](https://leetcode.cn/problems/form-array-by-concatenating-subarrays-of-another-array){#1764}

{{< tabs "1764" >}}

{{% tab "python" %}}
```python
class Solution:
    def canChoose(self, groups: List[List[int]], nums: List[int]) -> bool:
        n, m = len(groups), len(nums)
        i = j = 0
        while i < n and j < m:
            g = groups[i]
            if g == nums[j : j + len(g)]:
                j += len(g)
                i += 1
            else:
                j += 1
        return i == n
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean canChoose(int[][] groups, int[] nums) {
        int n = groups.length, m = nums.length;
        int i = 0;
        for (int j = 0; i < n && j < m;) {
            if (check(groups[i], nums, j)) {
                j += groups[i].length;
                ++i;
            } else {
                ++j;
            }
        }
        return i == n;
    }

    private boolean check(int[] a, int[] b, int j) {
        int m = a.length, n = b.length;
        int i = 0;
        for (; i < m && j < n; ++i, ++j) {
            if (a[i] != b[j]) {
                return false;
            }
        }
        return i == m;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        auto check = [&](vector<int>& a, vector<int>& b, int j) {
            int m = a.size(), n = b.size();
            int i = 0;
            for (; i < m && j < n; ++i, ++j) {
                if (a[i] != b[j]) {
                    return false;
                }
            }
            return i == m;
        };
        int n = groups.size(), m = nums.size();
        int i = 0;
        for (int j = 0; i < n && j < m;) {
            if (check(groups[i], nums, j)) {
                j += groups[i].size();
                ++i;
            } else {
                ++j;
            }
        }
        return i == n;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func canChoose(groups [][]int, nums []int) bool {
	check := func(a, b []int, j int) bool {
		m, n := len(a), len(b)
		i := 0
		for ; i < m && j < n; i, j = i+1, j+1 {
			if a[i] != b[j] {
				return false
			}
		}
		return i == m
	}
	n, m := len(groups), len(nums)
	i := 0
	for j := 0; i < n && j < m; {
		if check(groups[i], nums, j) {
			j += len(groups[i])
			i++
		} else {
			j++
		}
	}
	return i == n
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个长度为 <code>n</code> 的二维整数数组 <code>groups</code> ，同时给你一个整数数组 <code>nums</code> 。</p>

<p>你是否可以从 <code>nums</code> 中选出 <code>n</code> 个 <strong>不相交</strong> 的子数组，使得第 <code>i</code> 个子数组与 <code>groups[i]</code> （下标从 <strong>0</strong> 开始）完全相同，且如果 <code>i > 0</code> ，那么第 <code>(i-1)</code> 个子数组在 <code>nums</code> 中出现的位置在第 <code>i</code> 个子数组前面。（也就是说，这些子数组在 <code>nums</code> 中出现的顺序需要与 <code>groups</code> 顺序相同）</p>

<p>如果你可以找出这样的 <code>n</code> 个子数组，请你返回 <code>true</code> ，否则返回 <code>false</code> 。</p>

<p>如果不存在下标为 <code>k</code> 的元素 <code>nums[k]</code> 属于不止一个子数组，就称这些子数组是 <strong>不相交</strong> 的。子数组指的是原数组中连续元素组成的一个序列。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>groups = [[1,-1,-1],[3,-2,0]], nums = [1,-1,0,1,-1,-1,3,-2,0]
<b>输出：</b>true
<b>解释：</b>你可以分别在 nums 中选出第 0 个子数组 [1,-1,0,<strong>1,</strong><strong>-1,</strong><strong>-1</strong>,3,-2,0] 和第 1 个子数组 [1,-1,0,1,-1,-1,<strong>3,</strong><strong>-2,0</strong>] 。
这两个子数组是不相交的，因为它们没有任何共同的元素。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>groups = [[10,-2],[1,2,3,4]], nums = [1,2,3,4,10,-2]
<b>输出：</b>false
<strong>解释：</strong>选择子数组 [<strong>1,2,3,4</strong>,10,-2] 和 [1,2,3,4,<strong>10,-2</strong>] 是不正确的，因为它们出现的顺序与 groups 中顺序不同。
[10,-2] 必须出现在 [1,2,3,4] 之前。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>groups = [[1,2,3],[3,4]], nums = [7,7,1,2,3,4,7,7]
<b>输出：</b>false
<strong>解释：</strong>选择子数组 [7,7,<strong>1,2,3</strong>,4,7,7] 和 [7,7,1,2,<strong>3,4</strong>,7,7] 是不正确的，因为它们不是不相交子数组。
它们有一个共同的元素 nums[4] （下标从 0 开始）。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>groups.length == n</code></li>
	<li><code>1 <= n <= 10<sup>3</sup></code></li>
	<li><code>1 <= groups[i].length, sum(groups[i].length) <= 10<sup><span style="">3</span></sup></code></li>
	<li><code>1 <= nums.length <= 10<sup>3</sup></code></li>
	<li><code>-10<sup>7</sup> <= groups[i][j], nums[k] <= 10<sup>7</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心枚举

我们贪心地枚举 `nums` 中每一个数 $nums[j]$ 作为子数组的开始，判断其是否与当前 $groups[i]$ 匹配，是则将指针 $i$ 往后移一位，将指针 $j$ 往后移动 $groups[i].length$ 位，否则将指针 $j$ 往后移动一位。

如果 $i$ 走到了 $groups.length$，说明所有的子数组都匹配上了，返回 `true`，否则返回 `false`。

时间复杂度 $O(n \times m)$，空间复杂度 $O(1)$。其中 $n$ 和 $m$ 分别为 `groups` 和 `nums` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def canChoose(self, groups: List[List[int]], nums: List[int]) -> bool:
        n, m = len(groups), len(nums)
        i = j = 0
        while i < n and j < m:
            g = groups[i]
            if g == nums[j : j + len(g)]:
                j += len(g)
                i += 1
            else:
                j += 1
        return i == n
```

#### Java

```java
class Solution {
    public boolean canChoose(int[][] groups, int[] nums) {
        int n = groups.length, m = nums.length;
        int i = 0;
        for (int j = 0; i < n && j < m;) {
            if (check(groups[i], nums, j)) {
                j += groups[i].length;
                ++i;
            } else {
                ++j;
            }
        }
        return i == n;
    }

    private boolean check(int[] a, int[] b, int j) {
        int m = a.length, n = b.length;
        int i = 0;
        for (; i < m && j < n; ++i, ++j) {
            if (a[i] != b[j]) {
                return false;
            }
        }
        return i == m;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        auto check = [&](vector<int>& a, vector<int>& b, int j) {
            int m = a.size(), n = b.size();
            int i = 0;
            for (; i < m && j < n; ++i, ++j) {
                if (a[i] != b[j]) {
                    return false;
                }
            }
            return i == m;
        };
        int n = groups.size(), m = nums.size();
        int i = 0;
        for (int j = 0; i < n && j < m;) {
            if (check(groups[i], nums, j)) {
                j += groups[i].size();
                ++i;
            } else {
                ++j;
            }
        }
        return i == n;
    }
};
```

#### Go

```go
func canChoose(groups [][]int, nums []int) bool {
	check := func(a, b []int, j int) bool {
		m, n := len(a), len(b)
		i := 0
		for ; i < m && j < n; i, j = i+1, j+1 {
			if a[i] != b[j] {
				return false
			}
		}
		return i == m
	}
	n, m := len(groups), len(nums)
	i := 0
	for j := 0; i < n && j < m; {
		if check(groups[i], nums, j) {
			j += len(groups[i])
			i++
		} else {
			j++
		}
	}
	return i == n
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1765. 地图中的最高点](https://leetcode.cn/problems/map-of-highest-peak){#1765}

{{< tabs "1765" >}}

{{% tab "python" %}}
```python
class Solution:
    def highestPeak(self, isWater: List[List[int]]) -> List[List[int]]:
        m, n = len(isWater), len(isWater[0])
        ans = [[-1] * n for _ in range(m)]
        q = deque()
        for i, row in enumerate(isWater):
            for j, v in enumerate(row):
                if v:
                    q.append((i, j))
                    ans[i][j] = 0
        while q:
            for _ in range(len(q)):
                i, j = q.popleft()
                for a, b in pairwise((-1, 0, 1, 0, -1)):
                    x, y = i + a, j + b
                    if 0 <= x < m and 0 <= y < n and ans[x][y] == -1:
                        ans[x][y] = ans[i][j] + 1
                        q.append((x, y))
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[][] highestPeak(int[][] isWater) {
        int m = isWater.length, n = isWater[0].length;
        int[][] ans = new int[m][n];
        Deque<int[]> q = new ArrayDeque<>();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans[i][j] = isWater[i][j] - 1;
                if (ans[i][j] == 0) {
                    q.offer(new int[] {i, j});
                }
            }
        }
        int[] dirs = {-1, 0, 1, 0, -1};
        while (!q.isEmpty()) {
            for (int t = q.size(); t > 0; --t) {
                var p = q.poll();
                int i = p[0], j = p[1];
                for (int k = 0; k < 4; ++k) {
                    int x = i + dirs[k], y = j + dirs[k + 1];
                    if (x >= 0 && x < m && y >= 0 && y < n && ans[x][y] == -1) {
                        ans[x][y] = ans[i][j] + 1;
                        q.offer(new int[] {x, y});
                    }
                }
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
    const int dirs[5] = {-1, 0, 1, 0, -1};

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(), n = isWater[0].size();
        vector<vector<int>> ans(m, vector<int>(n));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans[i][j] = isWater[i][j] - 1;
                if (ans[i][j] == 0) {
                    q.emplace(i, j);
                }
            }
        }
        while (!q.empty()) {
            for (int t = q.size(); t; --t) {
                auto [i, j] = q.front();
                q.pop();
                for (int k = 0; k < 4; ++k) {
                    int x = i + dirs[k], y = j + dirs[k + 1];
                    if (x >= 0 && x < m && y >= 0 && y < n && ans[x][y] == -1) {
                        ans[x][y] = ans[i][j] + 1;
                        q.emplace(x, y);
                    }
                }
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func highestPeak(isWater [][]int) [][]int {
	m, n := len(isWater), len(isWater[0])
	ans := make([][]int, m)
	type pair struct{ i, j int }
	q := []pair{}
	for i, row := range isWater {
		ans[i] = make([]int, n)
		for j, v := range row {
			ans[i][j] = v - 1
			if v == 1 {
				q = append(q, pair{i, j})
			}
		}
	}
	dirs := []int{-1, 0, 1, 0, -1}
	for len(q) > 0 {
		for t := len(q); t > 0; t-- {
			p := q[0]
			q = q[1:]
			i, j := p.i, p.j
			for k := 0; k < 4; k++ {
				x, y := i+dirs[k], j+dirs[k+1]
				if x >= 0 && x < m && y >= 0 && y < n && ans[x][y] == -1 {
					ans[x][y] = ans[i][j] + 1
					q = append(q, pair{x, y})
				}
			}
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function highestPeak(isWater: number[][]): number[][] {
    const m = isWater.length;
    const n = isWater[0].length;
    let ans: number[][] = [];
    let q: number[][] = [];
    for (let i = 0; i < m; ++i) {
        ans.push(new Array(n).fill(-1));
        for (let j = 0; j < n; ++j) {
            if (isWater[i][j]) {
                q.push([i, j]);
                ans[i][j] = 0;
            }
        }
    }
    const dirs = [-1, 0, 1, 0, -1];
    while (q.length) {
        let tq: number[][] = [];
        for (const [i, j] of q) {
            for (let k = 0; k < 4; k++) {
                const [x, y] = [i + dirs[k], j + dirs[k + 1]];
                if (x >= 0 && x < m && y >= 0 && y < n && ans[x][y] == -1) {
                    tq.push([x, y]);
                    ans[x][y] = ans[i][j] + 1;
                }
            }
        }
        q = tq;
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::VecDeque;

impl Solution {
    #[allow(dead_code)]
    pub fn highest_peak(is_water: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let n = is_water.len();
        let m = is_water[0].len();
        let mut ret_vec = vec![vec![-1; m]; n];
        let mut q: VecDeque<(usize, usize)> = VecDeque::new();
        let vis_pair: Vec<(i32, i32)> = vec![(-1, 0), (1, 0), (0, -1), (0, 1)];

        // Initialize the return vector
        for i in 0..n {
            for j in 0..m {
                if is_water[i][j] == 1 {
                    // This cell is water, the height of which must be 0
                    ret_vec[i][j] = 0;
                    q.push_back((i, j));
                }
            }
        }

        while !q.is_empty() {
            // Get the front X-Y Coordinates
            let (x, y) = q.front().unwrap().clone();
            q.pop_front();
            // Traverse through the vis pair
            for d in &vis_pair {
                let (dx, dy) = *d;
                if Self::check_bounds((x as i32) + dx, (y as i32) + dy, n as i32, m as i32) {
                    if ret_vec[((x as i32) + dx) as usize][((y as i32) + dy) as usize] == -1 {
                        // This cell hasn't been visited, update its height
                        ret_vec[((x as i32) + dx) as usize][((y as i32) + dy) as usize] =
                            ret_vec[x][y] + 1;
                        // Enqueue the current cell
                        q.push_back((((x as i32) + dx) as usize, ((y as i32) + dy) as usize));
                    }
                }
            }
        }

        ret_vec
    }

    #[allow(dead_code)]
    fn check_bounds(i: i32, j: i32, n: i32, m: i32) -> bool {
        i >= 0 && i < n && j >= 0 && j < m
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个大小为&nbsp;<code>m x n</code>&nbsp;的整数矩阵&nbsp;<code>isWater</code>&nbsp;，它代表了一个由 <strong>陆地</strong>&nbsp;和 <strong>水域</strong>&nbsp;单元格组成的地图。</p>

<ul>
	<li>如果&nbsp;<code>isWater[i][j] == 0</code>&nbsp;，格子&nbsp;<code>(i, j)</code>&nbsp;是一个 <strong>陆地</strong>&nbsp;格子。</li>
	<li>如果&nbsp;<code>isWater[i][j] == 1</code>&nbsp;，格子&nbsp;<code>(i, j)</code>&nbsp;是一个 <strong>水域</strong>&nbsp;格子。</li>
</ul>

<p>你需要按照如下规则给每个单元格安排高度：</p>

<ul>
	<li>每个格子的高度都必须是非负的。</li>
	<li>如果一个格子是 <strong>水域</strong>&nbsp;，那么它的高度必须为 <code>0</code>&nbsp;。</li>
	<li>任意相邻的格子高度差 <strong>至多</strong>&nbsp;为 <code>1</code>&nbsp;。当两个格子在正东、南、西、北方向上相互紧挨着，就称它们为相邻的格子。（也就是说它们有一条公共边）</li>
</ul>

<p>找到一种安排高度的方案，使得矩阵中的最高高度值&nbsp;<strong>最大</strong>&nbsp;。</p>

<p>请你返回一个大小为&nbsp;<code>m x n</code>&nbsp;的整数矩阵 <code>height</code>&nbsp;，其中 <code>height[i][j]</code>&nbsp;是格子 <code>(i, j)</code>&nbsp;的高度。如果有多种解法，请返回&nbsp;<strong>任意一个</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1700-1799/1765.Map%20of%20Highest%20Peak/images/screenshot-2021-01-11-at-82045-am.png" style="width: 220px; height: 219px;" /></strong></p>

<pre>
<b>输入：</b>isWater = [[0,1],[0,0]]
<b>输出：</b>[[1,0],[2,1]]
<b>解释：</b>上图展示了给各个格子安排的高度。
蓝色格子是水域格，绿色格子是陆地格。
</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1700-1799/1765.Map%20of%20Highest%20Peak/images/screenshot-2021-01-11-at-82050-am.png" style="width: 300px; height: 296px;" /></strong></p>

<pre>
<b>输入：</b>isWater = [[0,0,1],[1,0,0],[0,0,0]]
<b>输出：</b>[[1,1,0],[0,1,1],[1,2,2]]
<b>解释：</b>所有安排方案中，最高可行高度为 2 。
任意安排方案中，只要最高高度为 2 且符合上述规则的，都为可行方案。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == isWater.length</code></li>
	<li><code>n == isWater[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 1000</code></li>
	<li><code>isWater[i][j]</code>&nbsp;要么是&nbsp;<code>0</code>&nbsp;，要么是&nbsp;<code>1</code>&nbsp;。</li>
	<li>至少有 <strong>1</strong>&nbsp;个水域格子。</li>
</ul>
<strong>注意：</strong>本题与 <a href="https://leetcode.cn/problems/01-matrix/">542</a> 题相同。

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：BFS

根据题目描述，水域的高度必须是 $0$，而任意相邻格子的高度差至多为 $1$。因此，我们可以从所有水域格子出发，用 BFS 搜索相邻且未访问过的格子，将其高度置为当前格子的高度再加一。

最后返回结果矩阵即可。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别是整数矩阵 `isWater` 的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def highestPeak(self, isWater: List[List[int]]) -> List[List[int]]:
        m, n = len(isWater), len(isWater[0])
        ans = [[-1] * n for _ in range(m)]
        q = deque()
        for i, row in enumerate(isWater):
            for j, v in enumerate(row):
                if v:
                    q.append((i, j))
                    ans[i][j] = 0
        while q:
            i, j = q.popleft()
            for a, b in pairwise((-1, 0, 1, 0, -1)):
                x, y = i + a, j + b
                if 0 <= x < m and 0 <= y < n and ans[x][y] == -1:
                    ans[x][y] = ans[i][j] + 1
                    q.append((x, y))
        return ans
```

#### Java

```java
class Solution {
    public int[][] highestPeak(int[][] isWater) {
        int m = isWater.length, n = isWater[0].length;
        int[][] ans = new int[m][n];
        Deque<int[]> q = new ArrayDeque<>();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans[i][j] = isWater[i][j] - 1;
                if (ans[i][j] == 0) {
                    q.offer(new int[] {i, j});
                }
            }
        }
        int[] dirs = {-1, 0, 1, 0, -1};
        while (!q.isEmpty()) {
            var p = q.poll();
            int i = p[0], j = p[1];
            for (int k = 0; k < 4; ++k) {
                int x = i + dirs[k], y = j + dirs[k + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && ans[x][y] == -1) {
                    ans[x][y] = ans[i][j] + 1;
                    q.offer(new int[] {x, y});
                }
            }
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    const int dirs[5] = {-1, 0, 1, 0, -1};

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(), n = isWater[0].size();
        vector<vector<int>> ans(m, vector<int>(n));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans[i][j] = isWater[i][j] - 1;
                if (ans[i][j] == 0) {
                    q.emplace(i, j);
                }
            }
        }
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            for (int k = 0; k < 4; ++k) {
                int x = i + dirs[k], y = j + dirs[k + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && ans[x][y] == -1) {
                    ans[x][y] = ans[i][j] + 1;
                    q.emplace(x, y);
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func highestPeak(isWater [][]int) [][]int {
	m, n := len(isWater), len(isWater[0])
	ans := make([][]int, m)
	type pair struct{ i, j int }
	q := []pair{}
	for i, row := range isWater {
		ans[i] = make([]int, n)
		for j, v := range row {
			ans[i][j] = v - 1
			if v == 1 {
				q = append(q, pair{i, j})
			}
		}
	}
	dirs := []int{-1, 0, 1, 0, -1}
	for len(q) > 0 {
		p := q[0]
		q = q[1:]
		i, j := p.i, p.j
		for k := 0; k < 4; k++ {
			x, y := i+dirs[k], j+dirs[k+1]
			if x >= 0 && x < m && y >= 0 && y < n && ans[x][y] == -1 {
				ans[x][y] = ans[i][j] + 1
				q = append(q, pair{x, y})
			}
		}
	}
	return ans
}
```

#### TypeScript

```ts
function highestPeak(isWater: number[][]): number[][] {
    const m = isWater.length;
    const n = isWater[0].length;
    let ans: number[][] = [];
    let q: number[][] = [];
    for (let i = 0; i < m; ++i) {
        ans.push(new Array(n).fill(-1));
        for (let j = 0; j < n; ++j) {
            if (isWater[i][j]) {
                q.push([i, j]);
                ans[i][j] = 0;
            }
        }
    }
    const dirs = [-1, 0, 1, 0, -1];
    while (q.length) {
        let tq: number[][] = [];
        for (const [i, j] of q) {
            for (let k = 0; k < 4; k++) {
                const [x, y] = [i + dirs[k], j + dirs[k + 1]];
                if (x >= 0 && x < m && y >= 0 && y < n && ans[x][y] == -1) {
                    tq.push([x, y]);
                    ans[x][y] = ans[i][j] + 1;
                }
            }
        }
        q = tq;
    }
    return ans;
}
```

#### Rust

```rust
use std::collections::VecDeque;

impl Solution {
    #[allow(dead_code)]
    pub fn highest_peak(is_water: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let n = is_water.len();
        let m = is_water[0].len();
        let mut ret_vec = vec![vec![-1; m]; n];
        let mut q: VecDeque<(usize, usize)> = VecDeque::new();
        let vis_pair: Vec<(i32, i32)> = vec![(-1, 0), (1, 0), (0, -1), (0, 1)];

        // Initialize the return vector
        for i in 0..n {
            for j in 0..m {
                if is_water[i][j] == 1 {
                    // This cell is water, the height of which must be 0
                    ret_vec[i][j] = 0;
                    q.push_back((i, j));
                }
            }
        }

        while !q.is_empty() {
            // Get the front X-Y Coordinates
            let (x, y) = q.front().unwrap().clone();
            q.pop_front();
            // Traverse through the vis pair
            for d in &vis_pair {
                let (dx, dy) = *d;
                if Self::check_bounds((x as i32) + dx, (y as i32) + dy, n as i32, m as i32) {
                    if ret_vec[((x as i32) + dx) as usize][((y as i32) + dy) as usize] == -1 {
                        // This cell hasn't been visited, update its height
                        ret_vec[((x as i32) + dx) as usize][((y as i32) + dy) as usize] =
                            ret_vec[x][y] + 1;
                        // Enqueue the current cell
                        q.push_back((((x as i32) + dx) as usize, ((y as i32) + dy) as usize));
                    }
                }
            }
        }

        ret_vec
    }

    #[allow(dead_code)]
    fn check_bounds(i: i32, j: i32, n: i32, m: i32) -> bool {
        i >= 0 && i < n && j >= 0 && j < m
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def highestPeak(self, isWater: List[List[int]]) -> List[List[int]]:
        m, n = len(isWater), len(isWater[0])
        ans = [[-1] * n for _ in range(m)]
        q = deque()
        for i, row in enumerate(isWater):
            for j, v in enumerate(row):
                if v:
                    q.append((i, j))
                    ans[i][j] = 0
        while q:
            for _ in range(len(q)):
                i, j = q.popleft()
                for a, b in pairwise((-1, 0, 1, 0, -1)):
                    x, y = i + a, j + b
                    if 0 <= x < m and 0 <= y < n and ans[x][y] == -1:
                        ans[x][y] = ans[i][j] + 1
                        q.append((x, y))
        return ans
```

#### Java

```java
class Solution {
    public int[][] highestPeak(int[][] isWater) {
        int m = isWater.length, n = isWater[0].length;
        int[][] ans = new int[m][n];
        Deque<int[]> q = new ArrayDeque<>();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans[i][j] = isWater[i][j] - 1;
                if (ans[i][j] == 0) {
                    q.offer(new int[] {i, j});
                }
            }
        }
        int[] dirs = {-1, 0, 1, 0, -1};
        while (!q.isEmpty()) {
            for (int t = q.size(); t > 0; --t) {
                var p = q.poll();
                int i = p[0], j = p[1];
                for (int k = 0; k < 4; ++k) {
                    int x = i + dirs[k], y = j + dirs[k + 1];
                    if (x >= 0 && x < m && y >= 0 && y < n && ans[x][y] == -1) {
                        ans[x][y] = ans[i][j] + 1;
                        q.offer(new int[] {x, y});
                    }
                }
            }
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    const int dirs[5] = {-1, 0, 1, 0, -1};

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(), n = isWater[0].size();
        vector<vector<int>> ans(m, vector<int>(n));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans[i][j] = isWater[i][j] - 1;
                if (ans[i][j] == 0) {
                    q.emplace(i, j);
                }
            }
        }
        while (!q.empty()) {
            for (int t = q.size(); t; --t) {
                auto [i, j] = q.front();
                q.pop();
                for (int k = 0; k < 4; ++k) {
                    int x = i + dirs[k], y = j + dirs[k + 1];
                    if (x >= 0 && x < m && y >= 0 && y < n && ans[x][y] == -1) {
                        ans[x][y] = ans[i][j] + 1;
                        q.emplace(x, y);
                    }
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func highestPeak(isWater [][]int) [][]int {
	m, n := len(isWater), len(isWater[0])
	ans := make([][]int, m)
	type pair struct{ i, j int }
	q := []pair{}
	for i, row := range isWater {
		ans[i] = make([]int, n)
		for j, v := range row {
			ans[i][j] = v - 1
			if v == 1 {
				q = append(q, pair{i, j})
			}
		}
	}
	dirs := []int{-1, 0, 1, 0, -1}
	for len(q) > 0 {
		for t := len(q); t > 0; t-- {
			p := q[0]
			q = q[1:]
			i, j := p.i, p.j
			for k := 0; k < 4; k++ {
				x, y := i+dirs[k], j+dirs[k+1]
				if x >= 0 && x < m && y >= 0 && y < n && ans[x][y] == -1 {
					ans[x][y] = ans[i][j] + 1
					q = append(q, pair{x, y})
				}
			}
		}
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1766. 互质树](https://leetcode.cn/problems/tree-of-coprimes){#1766}

{{< tabs "1766" >}}

{{% tab "python" %}}
```python
class Solution:
    def getCoprimes(self, nums: List[int], edges: List[List[int]]) -> List[int]:
        def dfs(i, fa, depth):
            t = k = -1
            for v in f[nums[i]]:
                stk = stks[v]
                if stk and stk[-1][1] > k:
                    t, k = stk[-1]
            ans[i] = t
            for j in g[i]:
                if j != fa:
                    stks[nums[i]].append((i, depth))
                    dfs(j, i, depth + 1)
                    stks[nums[i]].pop()

        g = defaultdict(list)
        for u, v in edges:
            g[u].append(v)
            g[v].append(u)
        f = defaultdict(list)
        for i in range(1, 51):
            for j in range(1, 51):
                if gcd(i, j) == 1:
                    f[i].append(j)
        stks = defaultdict(list)
        ans = [-1] * len(nums)
        dfs(0, -1, 0)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private List<Integer>[] g;
    private List<Integer>[] f;
    private Deque<int[]>[] stks;
    private int[] nums;
    private int[] ans;

    public int[] getCoprimes(int[] nums, int[][] edges) {
        int n = nums.length;
        g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (var e : edges) {
            int u = e[0], v = e[1];
            g[u].add(v);
            g[v].add(u);
        }
        f = new List[51];
        stks = new Deque[51];
        Arrays.setAll(f, k -> new ArrayList<>());
        Arrays.setAll(stks, k -> new ArrayDeque<>());
        for (int i = 1; i < 51; ++i) {
            for (int j = 1; j < 51; ++j) {
                if (gcd(i, j) == 1) {
                    f[i].add(j);
                }
            }
        }
        this.nums = nums;
        ans = new int[n];
        dfs(0, -1, 0);
        return ans;
    }

    private void dfs(int i, int fa, int depth) {
        int t = -1, k = -1;
        for (int v : f[nums[i]]) {
            var stk = stks[v];
            if (!stk.isEmpty() && stk.peek()[1] > k) {
                t = stk.peek()[0];
                k = stk.peek()[1];
            }
        }
        ans[i] = t;
        for (int j : g[i]) {
            if (j != fa) {
                stks[nums[i]].push(new int[] {i, depth});
                dfs(j, i, depth + 1);
                stks[nums[i]].pop();
            }
        }
    }

    private int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> g(n);
        vector<vector<int>> f(51);
        vector<stack<pair<int, int>>> stks(51);
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
        for (int i = 1; i < 51; ++i) {
            for (int j = 1; j < 51; ++j) {
                if (__gcd(i, j) == 1) {
                    f[i].emplace_back(j);
                }
            }
        }
        vector<int> ans(n);
        function<void(int, int, int)> dfs = [&](int i, int fa, int depth) {
            int t = -1, k = -1;
            for (int v : f[nums[i]]) {
                auto& stk = stks[v];
                if (!stk.empty() && stk.top().second > k) {
                    t = stk.top().first;
                    k = stk.top().second;
                }
            }
            ans[i] = t;
            for (int j : g[i]) {
                if (j != fa) {
                    stks[nums[i]].push({i, depth});
                    dfs(j, i, depth + 1);
                    stks[nums[i]].pop();
                }
            }
        };
        dfs(0, -1, 0);
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func getCoprimes(nums []int, edges [][]int) []int {
	n := len(nums)
	g := make([][]int, n)
	f := [51][]int{}
	type pair struct{ first, second int }
	stks := [51][]pair{}
	for _, e := range edges {
		u, v := e[0], e[1]
		g[u] = append(g[u], v)
		g[v] = append(g[v], u)
	}
	for i := 1; i < 51; i++ {
		for j := 1; j < 51; j++ {
			if gcd(i, j) == 1 {
				f[i] = append(f[i], j)
			}
		}
	}
	ans := make([]int, n)
	var dfs func(i, fa, depth int)
	dfs = func(i, fa, depth int) {
		t, k := -1, -1
		for _, v := range f[nums[i]] {
			stk := stks[v]
			if len(stk) > 0 && stk[len(stk)-1].second > k {
				t, k = stk[len(stk)-1].first, stk[len(stk)-1].second
			}
		}
		ans[i] = t
		for _, j := range g[i] {
			if j != fa {
				stks[nums[i]] = append(stks[nums[i]], pair{i, depth})
				dfs(j, i, depth+1)
				stks[nums[i]] = stks[nums[i]][:len(stks[nums[i]])-1]
			}
		}
	}
	dfs(0, -1, 0)
	return ans
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个 <code>n</code> 个节点的树（也就是一个无环连通无向图），节点编号从 <code>0</code> 到 <code>n - 1</code> ，且恰好有 <code>n - 1</code> 条边，每个节点有一个值。树的 <strong>根节点</strong> 为 0 号点。</p>

<p>给你一个整数数组 <code>nums</code> 和一个二维数组 <code>edges</code> 来表示这棵树。<code>nums[i]</code> 表示第 <code>i</code> 个点的值，<code>edges[j] = [u<sub>j</sub>, v<sub>j</sub>]</code> 表示节点 <code>u<sub>j</sub></code> 和节点 <code>v<sub>j</sub></code> 在树中有一条边。</p>

<p>当 <code>gcd(x, y) == 1</code> ，我们称两个数 <code>x</code> 和 <code>y</code> 是 <strong>互质的</strong> ，其中 <code>gcd(x, y)</code> 是 <code>x</code> 和 <code>y</code> 的 <strong>最大公约数</strong> 。</p>

<p>从节点 <code>i</code> 到 <strong>根</strong> 最短路径上的点都是节点 <code>i</code> 的祖先节点。一个节点 <strong>不是</strong> 它自己的祖先节点。</p>

<p>请你返回一个大小为 <code>n</code> 的数组 <code>ans</code> ，其中<em> </em><code>ans[i]</code>是离节点 <code>i</code> 最近的祖先节点且满足<em> </em><code>nums[i]</code> 和<em> </em><code>nums[ans[i]]</code> 是 <strong>互质的</strong> ，如果不存在这样的祖先节点，<code>ans[i]</code> 为 <code>-1</code> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1700-1799/1766.Tree%20of%20Coprimes/images/untitled-diagram.png" style="width: 191px; height: 281px;" /></strong></p>

<pre>
<b>输入：</b>nums = [2,3,3,2], edges = [[0,1],[1,2],[1,3]]
<b>输出：</b>[-1,0,0,1]
<b>解释：</b>上图中，每个节点的值在括号中表示。
- 节点 0 没有互质祖先。
- 节点 1 只有一个祖先节点 0 。它们的值是互质的（gcd(2,3) == 1）。
- 节点 2 有两个祖先节点，分别是节点 1 和节点 0 。节点 1 的值与它的值不是互质的（gcd(3,3) == 3）但节点 0 的值是互质的(gcd(2,3) == 1)，所以节点 0 是最近的符合要求的祖先节点。
- 节点 3 有两个祖先节点，分别是节点 1 和节点 0 。它与节点 1 互质（gcd(3,2) == 1），所以节点 1 是离它最近的符合要求的祖先节点。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1700-1799/1766.Tree%20of%20Coprimes/images/untitled-diagram1.png" style="width: 441px; height: 291px;" /></p>

<pre>
<strong>输入：</strong>nums = [5,6,10,2,3,6,15], edges = [[0,1],[0,2],[1,3],[1,4],[2,5],[2,6]]
<b>输出：</b>[-1,0,-1,0,0,0,-1]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>nums.length == n</code></li>
	<li><code>1 <= nums[i] <= 50</code></li>
	<li><code>1 <= n <= 10<sup>5</sup></code></li>
	<li><code>edges.length == n - 1</code></li>
	<li><code>edges[j].length == 2</code></li>
	<li><code>0 <= u<sub>j</sub>, v<sub>j</sub> < n</code></li>
	<li><code>u<sub>j</sub> != v<sub>j</sub></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：预处理 + 枚举 + 栈 + 回溯

由于题目中 $nums[i]$ 的取值范围为 $[1, 50]$，因此我们可以预处理出每个数的所有互质数，记录在数组 $f$ 中，其中 $f[i]$ 表示 $i$ 的所有互质数。

接下来我们可以使用回溯的方法，从根节点开始遍历整棵树，对于每个节点 $i$，我们可以通过 $f$ 数组得到 $nums[i]$ 的所有互质数。然后我们枚举 $nums[i]$ 的所有互质数，找到已经出现过的且深度最大的祖先节点 $t$，即为 $i$ 的最近的互质祖先节点。这里我们可以用一个长度为 $51$ 的栈数组 $stks$ 来获取每个出现过的值 $v$ 的节点以及其深度。每个栈 $stks[v]$ 的栈顶元素就是最近的深度最大的祖先节点。

时间复杂度 $O(n \times M)$，空间复杂度 $O(M^2 + n)$。其中 $n$ 为节点个数，而 $M$ 为 $nums[i]$ 的最大值，本题中 $M = 50$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def getCoprimes(self, nums: List[int], edges: List[List[int]]) -> List[int]:
        def dfs(i, fa, depth):
            t = k = -1
            for v in f[nums[i]]:
                stk = stks[v]
                if stk and stk[-1][1] > k:
                    t, k = stk[-1]
            ans[i] = t
            for j in g[i]:
                if j != fa:
                    stks[nums[i]].append((i, depth))
                    dfs(j, i, depth + 1)
                    stks[nums[i]].pop()

        g = defaultdict(list)
        for u, v in edges:
            g[u].append(v)
            g[v].append(u)
        f = defaultdict(list)
        for i in range(1, 51):
            for j in range(1, 51):
                if gcd(i, j) == 1:
                    f[i].append(j)
        stks = defaultdict(list)
        ans = [-1] * len(nums)
        dfs(0, -1, 0)
        return ans
```

#### Java

```java
class Solution {
    private List<Integer>[] g;
    private List<Integer>[] f;
    private Deque<int[]>[] stks;
    private int[] nums;
    private int[] ans;

    public int[] getCoprimes(int[] nums, int[][] edges) {
        int n = nums.length;
        g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (var e : edges) {
            int u = e[0], v = e[1];
            g[u].add(v);
            g[v].add(u);
        }
        f = new List[51];
        stks = new Deque[51];
        Arrays.setAll(f, k -> new ArrayList<>());
        Arrays.setAll(stks, k -> new ArrayDeque<>());
        for (int i = 1; i < 51; ++i) {
            for (int j = 1; j < 51; ++j) {
                if (gcd(i, j) == 1) {
                    f[i].add(j);
                }
            }
        }
        this.nums = nums;
        ans = new int[n];
        dfs(0, -1, 0);
        return ans;
    }

    private void dfs(int i, int fa, int depth) {
        int t = -1, k = -1;
        for (int v : f[nums[i]]) {
            var stk = stks[v];
            if (!stk.isEmpty() && stk.peek()[1] > k) {
                t = stk.peek()[0];
                k = stk.peek()[1];
            }
        }
        ans[i] = t;
        for (int j : g[i]) {
            if (j != fa) {
                stks[nums[i]].push(new int[] {i, depth});
                dfs(j, i, depth + 1);
                stks[nums[i]].pop();
            }
        }
    }

    private int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> g(n);
        vector<vector<int>> f(51);
        vector<stack<pair<int, int>>> stks(51);
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
        for (int i = 1; i < 51; ++i) {
            for (int j = 1; j < 51; ++j) {
                if (__gcd(i, j) == 1) {
                    f[i].emplace_back(j);
                }
            }
        }
        vector<int> ans(n);
        function<void(int, int, int)> dfs = [&](int i, int fa, int depth) {
            int t = -1, k = -1;
            for (int v : f[nums[i]]) {
                auto& stk = stks[v];
                if (!stk.empty() && stk.top().second > k) {
                    t = stk.top().first;
                    k = stk.top().second;
                }
            }
            ans[i] = t;
            for (int j : g[i]) {
                if (j != fa) {
                    stks[nums[i]].push({i, depth});
                    dfs(j, i, depth + 1);
                    stks[nums[i]].pop();
                }
            }
        };
        dfs(0, -1, 0);
        return ans;
    }
};
```

#### Go

```go
func getCoprimes(nums []int, edges [][]int) []int {
	n := len(nums)
	g := make([][]int, n)
	f := [51][]int{}
	type pair struct{ first, second int }
	stks := [51][]pair{}
	for _, e := range edges {
		u, v := e[0], e[1]
		g[u] = append(g[u], v)
		g[v] = append(g[v], u)
	}
	for i := 1; i < 51; i++ {
		for j := 1; j < 51; j++ {
			if gcd(i, j) == 1 {
				f[i] = append(f[i], j)
			}
		}
	}
	ans := make([]int, n)
	var dfs func(i, fa, depth int)
	dfs = func(i, fa, depth int) {
		t, k := -1, -1
		for _, v := range f[nums[i]] {
			stk := stks[v]
			if len(stk) > 0 && stk[len(stk)-1].second > k {
				t, k = stk[len(stk)-1].first, stk[len(stk)-1].second
			}
		}
		ans[i] = t
		for _, j := range g[i] {
			if j != fa {
				stks[nums[i]] = append(stks[nums[i]], pair{i, depth})
				dfs(j, i, depth+1)
				stks[nums[i]] = stks[nums[i]][:len(stks[nums[i]])-1]
			}
		}
	}
	dfs(0, -1, 0)
	return ans
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1767. 寻找没有被执行的任务对 🔒](https://leetcode.cn/problems/find-the-subtasks-that-did-not-execute){#1767}

{{< tabs "1767" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH RECURSIVE
    T(task_id, subtask_id) AS (
        SELECT
            task_id,
            subtasks_count
        FROM Tasks
        UNION ALL
        SELECT
            task_id,
            subtask_id - 1
        FROM t
        WHERE subtask_id > 1
    )
SELECT
    T.*
FROM
    T
    LEFT JOIN Executed USING (task_id, subtask_id)
WHERE Executed.subtask_id IS NULL;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code>Tasks</code></p>

<pre>
+----------------+---------+
| Column Name    | Type    |
+----------------+---------+
| task_id        | int     |
| subtasks_count | int     |
+----------------+---------+
task_id 具有唯一值的列。
task_id 表示的为主任务的id,每一个task_id被分为了多个子任务(subtasks)，subtasks_count表示为子任务的个数（n），它的值表示了子任务的索引从1到n。
本表保证2 &lt;=subtasks_count&lt;= 20。
</pre>

<p>&nbsp;</p>

<p>表： <code>Executed</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| task_id       | int     |
| subtask_id    | int     |
+---------------+---------+
(task_id, subtask_id) 是该表中具有唯一值的列的组合。
每一行表示标记为task_id的主任务与标记为subtask_id的子任务被成功执行。
本表 <strong>保证 </strong>，对于每一个task_id，subtask_id &lt;= subtasks_count。
</pre>

<p>&nbsp;</p>

<p>编写解决方案报告没有被执行的（主任务，子任务）对，即没有被执行的（task_id, subtask_id）。</p>

<p>以 <strong>任何顺序</strong> 返回即可。</p>

<p>查询结果格式如下。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：
</strong>Tasks 表:
+---------+----------------+
| task_id | subtasks_count |
+---------+----------------+
| 1       | 3              |
| 2       | 2              |
| 3       | 4              |
+---------+----------------+
Executed 表:
+---------+------------+
| task_id | subtask_id |
+---------+------------+
| 1       | 2          |
| 3       | 1          |
| 3       | 2          |
| 3       | 3          |
| 3       | 4          |
+---------+------------+
<strong>输出：</strong>
+---------+------------+
| task_id | subtask_id |
+---------+------------+
| 1       | 1          |
| 1       | 3          |
| 2       | 1          |
| 2       | 2          |
+---------+------------+
<strong>解释：</strong>
Task 1 被分成了 3 subtasks (1, 2, 3)。只有 subtask 2 被成功执行, 所以我们返回 (1, 1) 和 (1, 3) 这两个主任务子任务对。
Task 2 被分成了 2 subtasks (1, 2)。没有一个subtask被成功执行, 因此我们返回(2, 1)和(2, 2)。
Task 3 被分成了 4 subtasks (1, 2, 3, 4)。所有的subtask都被成功执行，因此对于Task 3,我们不返回任何值。</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：递归生成数据表 + 左连接

我们可以通过递归生成一个数据表，该数据表包含了所有的（主任务，子任务）对，然后我们通过左连接找到没有被执行的（主任务，子任务）对。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
WITH RECURSIVE
    T(task_id, subtask_id) AS (
        SELECT
            task_id,
            subtasks_count
        FROM Tasks
        UNION ALL
        SELECT
            task_id,
            subtask_id - 1
        FROM t
        WHERE subtask_id > 1
    )
SELECT
    T.*
FROM
    T
    LEFT JOIN Executed USING (task_id, subtask_id)
WHERE Executed.subtask_id IS NULL;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1768. 交替合并字符串](https://leetcode.cn/problems/merge-strings-alternately){#1768}

{{< tabs "1768" >}}

{{% tab "python" %}}
```python
class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        return ''.join(a + b for a, b in zip_longest(word1, word2, fillvalue=''))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String mergeAlternately(String word1, String word2) {
        int m = word1.length(), n = word2.length();
        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < m || i < n; ++i) {
            if (i < m) {
                ans.append(word1.charAt(i));
            }
            if (i < n) {
                ans.append(word2.charAt(i));
            }
        }
        return ans.toString();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        string ans;
        for (int i = 0; i < m || i < n; ++i) {
            if (i < m) ans += word1[i];
            if (i < n) ans += word2[i];
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func mergeAlternately(word1 string, word2 string) string {
	m, n := len(word1), len(word2)
	ans := make([]byte, 0, m+n)
	for i := 0; i < m || i < n; i++ {
		if i < m {
			ans = append(ans, word1[i])
		}
		if i < n {
			ans = append(ans, word2[i])
		}
	}
	return string(ans)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function mergeAlternately(word1: string, word2: string): string {
    const ans: string[] = [];
    const [m, n] = [word1.length, word2.length];
    for (let i = 0; i < m || i < n; ++i) {
        if (i < m) {
            ans.push(word1[i]);
        }
        if (i < n) {
            ans.push(word2[i]);
        }
    }
    return ans.join('');
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn merge_alternately(word1: String, word2: String) -> String {
        let s1 = word1.as_bytes();
        let s2 = word2.as_bytes();
        let n = s1.len().max(s2.len());
        let mut res = vec![];
        for i in 0..n {
            if s1.get(i).is_some() {
                res.push(s1[i]);
            }
            if s2.get(i).is_some() {
                res.push(s2[i]);
            }
        }
        String::from_utf8(res).unwrap()
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
char* mergeAlternately(char* word1, char* word2) {
    int m = strlen(word1);
    int n = strlen(word2);
    char* ans = malloc(sizeof(char) * (n + m + 1));
    int i = 0;
    int j = 0;
    while (i + j != m + n) {
        if (i < m) {
            ans[i + j] = word1[i];
            i++;
        }
        if (j < n) {
            ans[i + j] = word2[j];
            j++;
        }
    }
    ans[n + m] = '\0';
    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个字符串 <code>word1</code> 和 <code>word2</code> 。请你从 <code>word1</code> 开始，通过交替添加字母来合并字符串。如果一个字符串比另一个字符串长，就将多出来的字母追加到合并后字符串的末尾。</p>

<p>返回 <strong>合并后的字符串</strong> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>word1 = "abc", word2 = "pqr"
<strong>输出：</strong>"apbqcr"
<strong>解释：</strong>字符串合并情况如下所示：
word1：  a   b   c
word2：    p   q   r
合并后：  a p b q c r
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>word1 = "ab", word2 = "pqrs"
<strong>输出：</strong>"apbqrs"
<strong>解释：</strong>注意，word2 比 word1 长，"rs" 需要追加到合并后字符串的末尾。
word1：  a   b 
word2：    p   q   r   s
合并后：  a p b q   r   s
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>word1 = "abcd", word2 = "pq"
<strong>输出：</strong>"apbqcd"
<strong>解释：</strong>注意，word1 比 word2 长，"cd" 需要追加到合并后字符串的末尾。
word1：  a   b   c   d
word2：    p   q 
合并后：  a p b q c   d
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= word1.length, word2.length <= 100</code></li>
	<li><code>word1</code> 和 <code>word2</code> 由小写英文字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：直接模拟

我们遍历 `word1`, `word2` 两个字符串，依次取出字符，拼接到结果字符串中。Python 代码可以简化为一行。

时间复杂度 $O(m + n)$，其中 $m$ 和 $n$ 分别是两个字符串的长度。忽略答案的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        return ''.join(a + b for a, b in zip_longest(word1, word2, fillvalue=''))
```

#### Java

```java
class Solution {
    public String mergeAlternately(String word1, String word2) {
        int m = word1.length(), n = word2.length();
        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < m || i < n; ++i) {
            if (i < m) {
                ans.append(word1.charAt(i));
            }
            if (i < n) {
                ans.append(word2.charAt(i));
            }
        }
        return ans.toString();
    }
}
```

#### C++

```cpp
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        string ans;
        for (int i = 0; i < m || i < n; ++i) {
            if (i < m) ans += word1[i];
            if (i < n) ans += word2[i];
        }
        return ans;
    }
};
```

#### Go

```go
func mergeAlternately(word1 string, word2 string) string {
	m, n := len(word1), len(word2)
	ans := make([]byte, 0, m+n)
	for i := 0; i < m || i < n; i++ {
		if i < m {
			ans = append(ans, word1[i])
		}
		if i < n {
			ans = append(ans, word2[i])
		}
	}
	return string(ans)
}
```

#### TypeScript

```ts
function mergeAlternately(word1: string, word2: string): string {
    const ans: string[] = [];
    const [m, n] = [word1.length, word2.length];
    for (let i = 0; i < m || i < n; ++i) {
        if (i < m) {
            ans.push(word1[i]);
        }
        if (i < n) {
            ans.push(word2[i]);
        }
    }
    return ans.join('');
}
```

#### Rust

```rust
impl Solution {
    pub fn merge_alternately(word1: String, word2: String) -> String {
        let s1 = word1.as_bytes();
        let s2 = word2.as_bytes();
        let n = s1.len().max(s2.len());
        let mut res = vec![];
        for i in 0..n {
            if s1.get(i).is_some() {
                res.push(s1[i]);
            }
            if s2.get(i).is_some() {
                res.push(s2[i]);
            }
        }
        String::from_utf8(res).unwrap()
    }
}
```

#### C

```c
char* mergeAlternately(char* word1, char* word2) {
    int m = strlen(word1);
    int n = strlen(word2);
    char* ans = malloc(sizeof(char) * (n + m + 1));
    int i = 0;
    int j = 0;
    while (i + j != m + n) {
        if (i < m) {
            ans[i + j] = word1[i];
            i++;
        }
        if (j < n) {
            ans[i + j] = word2[j];
            j++;
        }
    }
    ans[n + m] = '\0';
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1769. 移动所有球到每个盒子所需的最小操作数](https://leetcode.cn/problems/minimum-number-of-operations-to-move-all-balls-to-each-box){#1769}

{{< tabs "1769" >}}

{{% tab "python" %}}
```python
class Solution:
    def minOperations(self, boxes: str) -> List[int]:
        n = len(boxes)
        ans = [0] * n
        cnt = 0
        for i in range(1, n):
            if boxes[i - 1] == '1':
                cnt += 1
            ans[i] = ans[i - 1] + cnt
        cnt = s = 0
        for i in range(n - 2, -1, -1):
            if boxes[i + 1] == '1':
                cnt += 1
            s += cnt
            ans[i] += s
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] minOperations(String boxes) {
        int n = boxes.length();
        int[] ans = new int[n];
        for (int i = 1, cnt = 0; i < n; ++i) {
            if (boxes.charAt(i - 1) == '1') {
                ++cnt;
            }
            ans[i] = ans[i - 1] + cnt;
        }
        for (int i = n - 2, cnt = 0, s = 0; i >= 0; --i) {
            if (boxes.charAt(i + 1) == '1') {
                ++cnt;
            }
            s += cnt;
            ans[i] += s;
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
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans(n);
        for (int i = 1, cnt = 0; i < n; ++i) {
            cnt += boxes[i - 1] == '1';
            ans[i] = ans[i - 1] + cnt;
        }
        for (int i = n - 2, cnt = 0, s = 0; ~i; --i) {
            cnt += boxes[i + 1] == '1';
            s += cnt;
            ans[i] += s;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minOperations(boxes string) []int {
	n := len(boxes)
	ans := make([]int, n)
	for i, cnt := 1, 0; i < n; i++ {
		if boxes[i-1] == '1' {
			cnt++
		}
		ans[i] = ans[i-1] + cnt
	}
	for i, cnt, s := n-2, 0, 0; i >= 0; i-- {
		if boxes[i+1] == '1' {
			cnt++
		}
		s += cnt
		ans[i] += s
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minOperations(boxes: string): number[] {
    const n = boxes.length;
    const ans = Array(n).fill(0);
    const ones: number[] = [];

    for (let i = 0; i < n; i++) {
        if (+boxes[i]) {
            ones.push(i);
        }
    }

    for (let i = 0; i < n; i++) {
        for (const j of ones) {
            ans[i] += Math.abs(i - j);
        }
    }

    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn min_operations(boxes: String) -> Vec<i32> {
        let s = boxes.as_bytes();
        let n = s.len();
        let mut ans = vec![0; n];
        let mut count = 0;
        for i in 1..n {
            if s[i - 1] == b'1' {
                count += 1;
            }
            ans[i] = ans[i - 1] + count;
        }
        let mut sum = 0;
        count = 0;
        for i in (0..n - 1).rev() {
            if s[i + 1] == b'1' {
                count += 1;
            }
            sum += count;
            ans[i] += sum;
        }
        ans
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* minOperations(char* boxes, int* returnSize) {
    int n = strlen(boxes);
    int* ans = malloc(sizeof(int) * n);
    memset(ans, 0, sizeof(int) * n);
    for (int i = 1, count = 0; i < n; i++) {
        if (boxes[i - 1] == '1') {
            count++;
        }
        ans[i] = ans[i - 1] + count;
    }
    for (int i = n - 2, count = 0, sum = 0; i >= 0; i--) {
        if (boxes[i + 1] == '1') {
            count++;
        }
        sum += count;
        ans[i] += sum;
    }
    *returnSize = n;
    return ans;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
function minOperations(boxes) {
    const n = boxes.length;
    const ans = Array(n).fill(0);
    const ones = [];

    for (let i = 0; i < n; i++) {
        if (+boxes[i]) {
            ones.push(i);
        }
    }

    for (let i = 0; i < n; i++) {
        for (const j of ones) {
            ans[i] += Math.abs(i - j);
        }
    }

    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>有 <code>n</code> 个盒子。给你一个长度为 <code>n</code> 的二进制字符串 <code>boxes</code> ，其中 <code>boxes[i]</code> 的值为 <code>'0'</code> 表示第 <code>i</code> 个盒子是 <strong>空</strong> 的，而 <code>boxes[i]</code> 的值为 <code>'1'</code> 表示盒子里有 <strong>一个</strong> 小球。</p>

<p>在一步操作中，你可以将 <strong>一个</strong> 小球从某个盒子移动到一个与之相邻的盒子中。第 <code>i</code> 个盒子和第 <code>j</code> 个盒子相邻需满足 <code>abs(i - j) == 1</code> 。注意，操作执行后，某些盒子中可能会存在不止一个小球。</p>

<p>返回一个长度为 <code>n</code> 的数组 <code>answer</code> ，其中 <code>answer[i]</code> 是将所有小球移动到第 <code>i</code> 个盒子所需的 <strong>最小</strong> 操作数。</p>

<p>每个 <code>answer[i]</code> 都需要根据盒子的 <strong>初始状态</strong> 进行计算。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>boxes = "110"
<strong>输出：</strong>[1,1,3]
<strong>解释：</strong>每个盒子对应的最小操作数如下：
1) 第 1 个盒子：将一个小球从第 2 个盒子移动到第 1 个盒子，需要 1 步操作。
2) 第 2 个盒子：将一个小球从第 1 个盒子移动到第 2 个盒子，需要 1 步操作。
3) 第 3 个盒子：将一个小球从第 1 个盒子移动到第 3 个盒子，需要 2 步操作。将一个小球从第 2 个盒子移动到第 3 个盒子，需要 1 步操作。共计 3 步操作。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>boxes = "001011"
<strong>输出：</strong>[11,8,5,4,3,4]</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == boxes.length</code></li>
	<li><code>1 &lt;= n &lt;= 2000</code></li>
	<li><code>boxes[i]</code> 为 <code>'0'</code> 或 <code>'1'</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：预处理 + 枚举

我们可以预处理出每个位置 $i$ 左边的小球移动到 $i$ 的操作数，记为 $left[i]$；每个位置 $i$ 右边的小球移动到 $i$ 的操作数，记为 $right[i]$。那么答案数组的第 $i$ 个元素就是 $left[i] + right[i]$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为 `boxes` 的长度。

我们还可以进一步优化空间复杂度，只用一个答案数组 $ans$ 以及若干个变量即可。

时间复杂度 $O(n)$，忽略答案数组的空间消耗，空间复杂度 $O(1)$。其中 $n$ 为 `boxes` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minOperations(self, boxes: str) -> List[int]:
        n = len(boxes)
        left = [0] * n
        right = [0] * n
        cnt = 0
        for i in range(1, n):
            if boxes[i - 1] == '1':
                cnt += 1
            left[i] = left[i - 1] + cnt
        cnt = 0
        for i in range(n - 2, -1, -1):
            if boxes[i + 1] == '1':
                cnt += 1
            right[i] = right[i + 1] + cnt
        return [a + b for a, b in zip(left, right)]
```

#### Java

```java
class Solution {
    public int[] minOperations(String boxes) {
        int n = boxes.length();
        int[] left = new int[n];
        int[] right = new int[n];
        for (int i = 1, cnt = 0; i < n; ++i) {
            if (boxes.charAt(i - 1) == '1') {
                ++cnt;
            }
            left[i] = left[i - 1] + cnt;
        }
        for (int i = n - 2, cnt = 0; i >= 0; --i) {
            if (boxes.charAt(i + 1) == '1') {
                ++cnt;
            }
            right[i] = right[i + 1] + cnt;
        }
        int[] ans = new int[n];
        for (int i = 0; i < n; ++i) {
            ans[i] = left[i] + right[i];
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        int left[n];
        int right[n];
        memset(left, 0, sizeof left);
        memset(right, 0, sizeof right);
        for (int i = 1, cnt = 0; i < n; ++i) {
            cnt += boxes[i - 1] == '1';
            left[i] = left[i - 1] + cnt;
        }
        for (int i = n - 2, cnt = 0; ~i; --i) {
            cnt += boxes[i + 1] == '1';
            right[i] = right[i + 1] + cnt;
        }
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) ans[i] = left[i] + right[i];
        return ans;
    }
};
```

#### Go

```go
func minOperations(boxes string) []int {
	n := len(boxes)
	left := make([]int, n)
	right := make([]int, n)
	for i, cnt := 1, 0; i < n; i++ {
		if boxes[i-1] == '1' {
			cnt++
		}
		left[i] = left[i-1] + cnt
	}
	for i, cnt := n-2, 0; i >= 0; i-- {
		if boxes[i+1] == '1' {
			cnt++
		}
		right[i] = right[i+1] + cnt
	}
	ans := make([]int, n)
	for i := range ans {
		ans[i] = left[i] + right[i]
	}
	return ans
}
```

#### TypeScript

```ts
function minOperations(boxes: string): number[] {
    const n = boxes.length;
    const left = new Array(n).fill(0);
    const right = new Array(n).fill(0);
    for (let i = 1, count = 0; i < n; i++) {
        if (boxes[i - 1] == '1') {
            count++;
        }
        left[i] = left[i - 1] + count;
    }
    for (let i = n - 2, count = 0; i >= 0; i--) {
        if (boxes[i + 1] == '1') {
            count++;
        }
        right[i] = right[i + 1] + count;
    }
    return left.map((v, i) => v + right[i]);
}
```

#### Rust

```rust
impl Solution {
    pub fn min_operations(boxes: String) -> Vec<i32> {
        let s = boxes.as_bytes();
        let n = s.len();
        let mut left = vec![0; n];
        let mut right = vec![0; n];
        let mut count = 0;
        for i in 1..n {
            if s[i - 1] == b'1' {
                count += 1;
            }
            left[i] = left[i - 1] + count;
        }
        count = 0;
        for i in (0..n - 1).rev() {
            if s[i + 1] == b'1' {
                count += 1;
            }
            right[i] = right[i + 1] + count;
        }
        (0..n).into_iter().map(|i| left[i] + right[i]).collect()
    }
}
```

#### C

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* minOperations(char* boxes, int* returnSize) {
    int n = strlen(boxes);
    int* left = malloc(sizeof(int) * n);
    int* right = malloc(sizeof(int) * n);
    memset(left, 0, sizeof(int) * n);
    memset(right, 0, sizeof(int) * n);
    for (int i = 1, count = 0; i < n; i++) {
        if (boxes[i - 1] == '1') {
            count++;
        }
        left[i] = left[i - 1] + count;
    }
    for (int i = n - 2, count = 0; i >= 0; i--) {
        if (boxes[i + 1] == '1') {
            count++;
        }
        right[i] = right[i + 1] + count;
    }
    int* ans = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        ans[i] = left[i] + right[i];
    }
    free(left);
    free(right);
    *returnSize = n;
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minOperations(self, boxes: str) -> List[int]:
        n = len(boxes)
        ans = [0] * n
        cnt = 0
        for i in range(1, n):
            if boxes[i - 1] == '1':
                cnt += 1
            ans[i] = ans[i - 1] + cnt
        cnt = s = 0
        for i in range(n - 2, -1, -1):
            if boxes[i + 1] == '1':
                cnt += 1
            s += cnt
            ans[i] += s
        return ans
```

#### Java

```java
class Solution {
    public int[] minOperations(String boxes) {
        int n = boxes.length();
        int[] ans = new int[n];
        for (int i = 1, cnt = 0; i < n; ++i) {
            if (boxes.charAt(i - 1) == '1') {
                ++cnt;
            }
            ans[i] = ans[i - 1] + cnt;
        }
        for (int i = n - 2, cnt = 0, s = 0; i >= 0; --i) {
            if (boxes.charAt(i + 1) == '1') {
                ++cnt;
            }
            s += cnt;
            ans[i] += s;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans(n);
        for (int i = 1, cnt = 0; i < n; ++i) {
            cnt += boxes[i - 1] == '1';
            ans[i] = ans[i - 1] + cnt;
        }
        for (int i = n - 2, cnt = 0, s = 0; ~i; --i) {
            cnt += boxes[i + 1] == '1';
            s += cnt;
            ans[i] += s;
        }
        return ans;
    }
};
```

#### Go

```go
func minOperations(boxes string) []int {
	n := len(boxes)
	ans := make([]int, n)
	for i, cnt := 1, 0; i < n; i++ {
		if boxes[i-1] == '1' {
			cnt++
		}
		ans[i] = ans[i-1] + cnt
	}
	for i, cnt, s := n-2, 0, 0; i >= 0; i-- {
		if boxes[i+1] == '1' {
			cnt++
		}
		s += cnt
		ans[i] += s
	}
	return ans
}
```

#### TypeScript

```ts
function minOperations(boxes: string): number[] {
    const n = boxes.length;
    const ans = new Array(n).fill(0);
    for (let i = 1, count = 0; i < n; i++) {
        if (boxes[i - 1] === '1') {
            count++;
        }
        ans[i] = ans[i - 1] + count;
    }
    for (let i = n - 2, count = 0, sum = 0; i >= 0; i--) {
        if (boxes[i + 1] === '1') {
            count++;
        }
        sum += count;
        ans[i] += sum;
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn min_operations(boxes: String) -> Vec<i32> {
        let s = boxes.as_bytes();
        let n = s.len();
        let mut ans = vec![0; n];
        let mut count = 0;
        for i in 1..n {
            if s[i - 1] == b'1' {
                count += 1;
            }
            ans[i] = ans[i - 1] + count;
        }
        let mut sum = 0;
        count = 0;
        for i in (0..n - 1).rev() {
            if s[i + 1] == b'1' {
                count += 1;
            }
            sum += count;
            ans[i] += sum;
        }
        ans
    }
}
```

#### C

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* minOperations(char* boxes, int* returnSize) {
    int n = strlen(boxes);
    int* ans = malloc(sizeof(int) * n);
    memset(ans, 0, sizeof(int) * n);
    for (int i = 1, count = 0; i < n; i++) {
        if (boxes[i - 1] == '1') {
            count++;
        }
        ans[i] = ans[i - 1] + count;
    }
    for (int i = n - 2, count = 0, sum = 0; i >= 0; i--) {
        if (boxes[i + 1] == '1') {
            count++;
        }
        sum += count;
        ans[i] += sum;
    }
    *returnSize = n;
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### Solution 3

<!-- tabs:start -->

#### TypeScript

```ts
function minOperations(boxes: string): number[] {
    const n = boxes.length;
    const ans = Array(n).fill(0);
    const ones: number[] = [];

    for (let i = 0; i < n; i++) {
        if (+boxes[i]) {
            ones.push(i);
        }
    }

    for (let i = 0; i < n; i++) {
        for (const j of ones) {
            ans[i] += Math.abs(i - j);
        }
    }

    return ans;
}
```

#### JavaScript

```js
function minOperations(boxes) {
    const n = boxes.length;
    const ans = Array(n).fill(0);
    const ones = [];

    for (let i = 0; i < n; i++) {
        if (+boxes[i]) {
            ones.push(i);
        }
    }

    for (let i = 0; i < n; i++) {
        for (const j of ones) {
            ans[i] += Math.abs(i - j);
        }
    }

    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
