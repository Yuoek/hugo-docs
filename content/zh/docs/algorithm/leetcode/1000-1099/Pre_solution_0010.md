---
title: "1090_受标签影响的最大值"
date: 2025-10-08T18:36:50+08:00
weight: 10
tags: [二分查找, 交互, 前缀和, 动态规划, 双指针, 哈希表, 回溯, 堆（优先队列）, 字符串, 广度优先搜索, 排序, 数学, 数据库, 数组, 栈, 概率与统计, 模拟, 矩阵, 计数, 贪心]
---

{{< markmap >}}
### [1090_受标签影响的最大值](#1090)
#### [贪心](#1090)
#### [数组](#1090)
#### [哈希表](#1090)
#### [计数](#1090)
#### [排序](#1090)
### [1091_二进制矩阵中的最短路径](#1091)
#### [广度优先搜索](#1091)
#### [数组](#1091)
#### [矩阵](#1091)
### [1092_最短公共超序列](#1092)
#### [字符串](#1092)
#### [动态规划](#1092)
### [1093_大样本统计](#1093)
#### [数组](#1093)
#### [数学](#1093)
#### [概率与统计](#1093)
### [1094_拼车](#1094)
#### [数组](#1094)
#### [前缀和](#1094)
#### [排序](#1094)
#### [模拟](#1094)
#### [堆（优先队列）](#1094)
### [1095_山脉数组中查找目标值](#1095)
#### [数组](#1095)
#### [二分查找](#1095)
#### [交互](#1095)
### [1096_花括号展开 II](#1096)
#### [栈](#1096)
#### [广度优先搜索](#1096)
#### [字符串](#1096)
#### [回溯](#1096)
### [1097_游戏玩法分析 V 🔒](#1097)
#### [数据库](#1097)
### [1098_小众书籍 🔒](#1098)
#### [数据库](#1098)
### [1099_小于 K 的两数之和 🔒](#1099)
#### [数组](#1099)
#### [双指针](#1099)
#### [二分查找](#1099)
#### [排序](#1099)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1090_受标签影响的最大值
___
#### 贪心
___
#### 数组
___
#### 哈希表
___
#### 计数
___
#### 排序
---
### 1091_二进制矩阵中的最短路径
___
#### 广度优先搜索
___
#### 数组
___
#### 矩阵
---
### 1092_最短公共超序列
___
#### 字符串
___
#### 动态规划
---
### 1093_大样本统计
___
#### 数组
___
#### 数学
___
#### 概率与统计
---
### 1094_拼车
___
#### 数组
___
#### 前缀和
___
#### 排序
___
#### 模拟
___
#### 堆（优先队列）
---
### 1095_山脉数组中查找目标值
___
#### 数组
___
#### 二分查找
___
#### 交互
---
### 1096_花括号展开 II
___
#### 栈
___
#### 广度优先搜索
___
#### 字符串
___
#### 回溯
---
### 1097_游戏玩法分析 V 🔒
___
#### 数据库
---
### 1098_小众书籍 🔒
___
#### 数据库
---
### 1099_小于 K 的两数之和 🔒
___
#### 数组
___
#### 双指针
___
#### 二分查找
___
#### 排序
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 交互 | 前缀和 |
| 动态规划 | 双指针 | 哈希表 |
| 回溯 | 堆（优先队列） | 字符串 |
| 广度优先搜索 | 排序 | 数学 |
| 数据库 | 数组 | 栈 |
| 概率与统计 | 模拟 | 矩阵 |
| 计数 | 贪心 |  |

# [1090. 受标签影响的最大值](https://leetcode.cn/problems/largest-values-from-labels){#1090}

{{< tabs "1090" >}}

{{% tab "python" %}}
```python
class Solution:
    def largestValsFromLabels(
        self, values: List[int], labels: List[int], numWanted: int, useLimit: int
    ) -> int:
        ans = num = 0
        cnt = Counter()
        for v, l in sorted(zip(values, labels), reverse=True):
            if cnt[l] < useLimit:
                cnt[l] += 1
                num += 1
                ans += v
                if num == numWanted:
                    break
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int largestValsFromLabels(int[] values, int[] labels, int numWanted, int useLimit) {
        int n = values.length;
        int[][] pairs = new int[n][2];
        for (int i = 0; i < n; ++i) {
            pairs[i] = new int[] {values[i], labels[i]};
        }
        Arrays.sort(pairs, (a, b) -> b[0] - a[0]);
        Map<Integer, Integer> cnt = new HashMap<>();
        int ans = 0, num = 0;
        for (int i = 0; i < n && num < numWanted; ++i) {
            int v = pairs[i][0], l = pairs[i][1];
            if (cnt.getOrDefault(l, 0) < useLimit) {
                cnt.merge(l, 1, Integer::sum);
                num += 1;
                ans += v;
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
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        int n = values.size();
        vector<pair<int, int>> pairs(n);
        for (int i = 0; i < n; ++i) {
            pairs[i] = {-values[i], labels[i]};
        }
        sort(pairs.begin(), pairs.end());
        unordered_map<int, int> cnt;
        int ans = 0, num = 0;
        for (int i = 0; i < n && num < numWanted; ++i) {
            int v = -pairs[i].first, l = pairs[i].second;
            if (cnt[l] < useLimit) {
                ++cnt[l];
                ++num;
                ans += v;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func largestValsFromLabels(values []int, labels []int, numWanted int, useLimit int) (ans int) {
	n := len(values)
	pairs := make([][2]int, n)
	for i := 0; i < n; i++ {
		pairs[i] = [2]int{values[i], labels[i]}
	}
	sort.Slice(pairs, func(i, j int) bool { return pairs[i][0] > pairs[j][0] })
	cnt := map[int]int{}
	for i, num := 0, 0; i < n && num < numWanted; i++ {
		v, l := pairs[i][0], pairs[i][1]
		if cnt[l] < useLimit {
			cnt[l]++
			num++
			ans += v
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function largestValsFromLabels(
    values: number[],
    labels: number[],
    numWanted: number,
    useLimit: number,
): number {
    const n = values.length;
    const pairs = new Array(n);
    for (let i = 0; i < n; ++i) {
        pairs[i] = [values[i], labels[i]];
    }
    pairs.sort((a, b) => b[0] - a[0]);
    const cnt: Map<number, number> = new Map();
    let ans = 0;
    for (let i = 0, num = 0; i < n && num < numWanted; ++i) {
        const [v, l] = pairs[i];
        if ((cnt.get(l) || 0) < useLimit) {
            cnt.set(l, (cnt.get(l) || 0) + 1);
            ++num;
            ans += v;
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

<p>以两个整数数组 &nbsp;<code>values</code>&nbsp;和 <code>labels</code>&nbsp;给定&nbsp;<code>n</code>&nbsp;个项的值和标签，并且给出两个整数&nbsp;<code>numWanted</code>&nbsp;和 <code>useLimit</code> 。</p>

<p>你的任务是从这些项中找到一个值的和 <strong>最大</strong> 的子集使得：</p>

<ul>
	<li>项的数量 <strong>最多</strong> 为&nbsp;<code>numWanted</code>。</li>
	<li>相同标签的项的数量&nbsp;<strong>最多 </strong>为&nbsp;<code>useLimit</code>。</li>
</ul>

<p>返回最大的和。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">values = [5,4,3,2,1], labels = [1,1,2,2,3], numWanted = 3, useLimit = 1</span></p>

<p><strong>输出：</strong><span class="example-io">9</span></p>

<p><strong>解释：</strong></p>

<p>选择的子集是第一个、第三个和第五个项，其值之和为 5 + 3 + 1。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">values = [5,4,3,2,1], labels = [1,3,3,3,2], numWanted = 3, useLimit = 2</span></p>

<p><strong>输出：</strong><span class="example-io">12</span></p>

<p><strong>解释：</strong></p>

<p>选择的子集是第一个、第二个和第三个项，其值之和为 5 + 4 + 3。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">values = [9,8,8,7,6], labels = [0,0,0,1,1], numWanted = 3, useLimit = 1</span></p>

<p><strong>输出：</strong><span class="example-io">16</span></p>

<p><strong>解释：</strong></p>

<p>选择的子集是第一个和第四个项，其值之和为 9 + 7。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == values.length == labels.length</code></li>
	<li><code>1 &lt;= n &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>0 &lt;= values[i], labels[i] &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= numWanted, useLimit &lt;= n</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 排序 + 哈希表

根据题目描述，我们需要从 $n$ 个元素的集合中选出一个子集，子集元素个数不超过 $numWanted$，且子集中最多有相同标签的 $useLimit$ 项，使得子集的值之和最大。因此，我们应该贪心地选择集合中值较大的元素，同时记录每个标签出现的次数，当某个标签出现的次数达到 $useLimit$ 时，我们就不能再选择该标签对应的元素了。

具体地，我们先将集合中的元素按照值从大到小进行排序，然后从前向后遍历排序后的元素。在遍历的过程中，我们使用一个哈希表 $cnt$ 记录每个标签出现的次数，如果某个标签出现的次数达到了 $useLimit$，那么我们就跳过该元素，否则我们就将该元素的值加到最终的答案中，并将该标签出现的次数加 $1$。同时，我们用一个变量 $num$ 记录当前子集中的元素个数，当 $num$ 达到 $numWanted$ 时，我们就可以结束遍历了。

遍历结束后，我们就得到了最大的分数。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 是集合中的元素个数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def largestValsFromLabels(
        self, values: List[int], labels: List[int], numWanted: int, useLimit: int
    ) -> int:
        ans = num = 0
        cnt = Counter()
        for v, l in sorted(zip(values, labels), reverse=True):
            if cnt[l] < useLimit:
                cnt[l] += 1
                num += 1
                ans += v
                if num == numWanted:
                    break
        return ans
```

#### Java

```java
class Solution {
    public int largestValsFromLabels(int[] values, int[] labels, int numWanted, int useLimit) {
        int n = values.length;
        int[][] pairs = new int[n][2];
        for (int i = 0; i < n; ++i) {
            pairs[i] = new int[] {values[i], labels[i]};
        }
        Arrays.sort(pairs, (a, b) -> b[0] - a[0]);
        Map<Integer, Integer> cnt = new HashMap<>();
        int ans = 0, num = 0;
        for (int i = 0; i < n && num < numWanted; ++i) {
            int v = pairs[i][0], l = pairs[i][1];
            if (cnt.getOrDefault(l, 0) < useLimit) {
                cnt.merge(l, 1, Integer::sum);
                num += 1;
                ans += v;
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
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        int n = values.size();
        vector<pair<int, int>> pairs(n);
        for (int i = 0; i < n; ++i) {
            pairs[i] = {-values[i], labels[i]};
        }
        sort(pairs.begin(), pairs.end());
        unordered_map<int, int> cnt;
        int ans = 0, num = 0;
        for (int i = 0; i < n && num < numWanted; ++i) {
            int v = -pairs[i].first, l = pairs[i].second;
            if (cnt[l] < useLimit) {
                ++cnt[l];
                ++num;
                ans += v;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func largestValsFromLabels(values []int, labels []int, numWanted int, useLimit int) (ans int) {
	n := len(values)
	pairs := make([][2]int, n)
	for i := 0; i < n; i++ {
		pairs[i] = [2]int{values[i], labels[i]}
	}
	sort.Slice(pairs, func(i, j int) bool { return pairs[i][0] > pairs[j][0] })
	cnt := map[int]int{}
	for i, num := 0, 0; i < n && num < numWanted; i++ {
		v, l := pairs[i][0], pairs[i][1]
		if cnt[l] < useLimit {
			cnt[l]++
			num++
			ans += v
		}
	}
	return
}
```

#### TypeScript

```ts
function largestValsFromLabels(
    values: number[],
    labels: number[],
    numWanted: number,
    useLimit: number,
): number {
    const n = values.length;
    const pairs = new Array(n);
    for (let i = 0; i < n; ++i) {
        pairs[i] = [values[i], labels[i]];
    }
    pairs.sort((a, b) => b[0] - a[0]);
    const cnt: Map<number, number> = new Map();
    let ans = 0;
    for (let i = 0, num = 0; i < n && num < numWanted; ++i) {
        const [v, l] = pairs[i];
        if ((cnt.get(l) || 0) < useLimit) {
            cnt.set(l, (cnt.get(l) || 0) + 1);
            ++num;
            ans += v;
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

# [1091. 二进制矩阵中的最短路径](https://leetcode.cn/problems/shortest-path-in-binary-matrix){#1091}

{{< tabs "1091" >}}

{{% tab "python" %}}
```python
class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        if grid[0][0]:
            return -1
        n = len(grid)
        grid[0][0] = 1
        q = deque([(0, 0)])
        ans = 1
        while q:
            for _ in range(len(q)):
                i, j = q.popleft()
                if i == j == n - 1:
                    return ans
                for x in range(i - 1, i + 2):
                    for y in range(j - 1, j + 2):
                        if 0 <= x < n and 0 <= y < n and grid[x][y] == 0:
                            grid[x][y] = 1
                            q.append((x, y))
            ans += 1
        return -1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int shortestPathBinaryMatrix(int[][] grid) {
        if (grid[0][0] == 1) {
            return -1;
        }
        int n = grid.length;
        grid[0][0] = 1;
        Deque<int[]> q = new ArrayDeque<>();
        q.offer(new int[] {0, 0});
        for (int ans = 1; !q.isEmpty(); ++ans) {
            for (int k = q.size(); k > 0; --k) {
                var p = q.poll();
                int i = p[0], j = p[1];
                if (i == n - 1 && j == n - 1) {
                    return ans;
                }
                for (int x = i - 1; x <= i + 1; ++x) {
                    for (int y = j - 1; y <= j + 1; ++y) {
                        if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 0) {
                            grid[x][y] = 1;
                            q.offer(new int[] {x, y});
                        }
                    }
                }
            }
        }
        return -1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0]) {
            return -1;
        }
        int n = grid.size();
        grid[0][0] = 1;
        queue<pair<int, int>> q;
        q.emplace(0, 0);
        for (int ans = 1; !q.empty(); ++ans) {
            for (int k = q.size(); k; --k) {
                auto [i, j] = q.front();
                q.pop();
                if (i == n - 1 && j == n - 1) {
                    return ans;
                }
                for (int x = i - 1; x <= i + 1; ++x) {
                    for (int y = j - 1; y <= j + 1; ++y) {
                        if (x >= 0 && x < n && y >= 0 && y < n && !grid[x][y]) {
                            grid[x][y] = 1;
                            q.emplace(x, y);
                        }
                    }
                }
            }
        }
        return -1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func shortestPathBinaryMatrix(grid [][]int) int {
	if grid[0][0] == 1 {
		return -1
	}
	n := len(grid)
	grid[0][0] = 1
	q := [][2]int{{0, 0}}
	for ans := 1; len(q) > 0; ans++ {
		for k := len(q); k > 0; k-- {
			p := q[0]
			i, j := p[0], p[1]
			q = q[1:]
			if i == n-1 && j == n-1 {
				return ans
			}
			for x := i - 1; x <= i+1; x++ {
				for y := j - 1; y <= j+1; y++ {
					if x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 0 {
						grid[x][y] = 1
						q = append(q, [2]int{x, y})
					}
				}
			}
		}
	}
	return -1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function shortestPathBinaryMatrix(grid: number[][]): number {
    if (grid[0][0]) {
        return -1;
    }
    const max = grid.length - 1;
    grid[0][0] = 1;
    let q: number[][] = [[0, 0]];
    for (let ans = 1; q.length > 0; ++ans) {
        const nq: number[][] = [];
        for (const [i, j] of q) {
            if (i === max && j === max) {
                return ans;
            }
            for (let x = i - 1; x <= i + 1; ++x) {
                for (let y = j - 1; y <= j + 1; ++y) {
                    if (grid[x]?.[y] === 0) {
                        grid[x][y] = 1;
                        nq.push([x, y]);
                    }
                }
            }
        }
        q = nq;
    }
    return -1;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::VecDeque;
impl Solution {
    pub fn shortest_path_binary_matrix(mut grid: Vec<Vec<i32>>) -> i32 {
        let n = grid.len();
        let mut queue = VecDeque::new();
        queue.push_back([0, 0]);
        let mut res = 0;
        while !queue.is_empty() {
            res += 1;
            for _ in 0..queue.len() {
                let [i, j] = queue.pop_front().unwrap();
                if grid[i][j] == 1 {
                    continue;
                }
                if i == n - 1 && j == n - 1 {
                    return res;
                }
                grid[i][j] = 1;
                for x in -1..=1 {
                    for y in -1..=1 {
                        let x = x + (i as i32);
                        let y = y + (j as i32);
                        if x < 0 || x == (n as i32) || y < 0 || y == (n as i32) {
                            continue;
                        }
                        queue.push_back([x as usize, y as usize]);
                    }
                }
            }
        }
        -1
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个 <code>n x n</code> 的二进制矩阵 <code>grid</code> 中，返回矩阵中最短 <strong>畅通路径</strong> 的长度。如果不存在这样的路径，返回 <code>-1</code> 。</p>

<p>二进制矩阵中的 畅通路径 是一条从 <strong>左上角</strong> 单元格（即，<code>(0, 0)</code>）到 右下角 单元格（即，<code>(n - 1, n - 1)</code>）的路径，该路径同时满足下述要求：</p>

<ul>
	<li>路径途经的所有单元格的值都是 <code>0</code> 。</li>
	<li>路径中所有相邻的单元格应当在 <strong>8 个方向之一</strong> 上连通（即，相邻两单元之间彼此不同且共享一条边或者一个角）。</li>
</ul>

<p><strong>畅通路径的长度</strong> 是该路径途经的单元格总数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1000-1099/1091.Shortest%20Path%20in%20Binary%20Matrix/images/example1_1.png" style="width: 500px; height: 234px;" />
<pre>
<strong>输入：</strong>grid = [[0,1],[1,0]]
<strong>输出：</strong>2
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1000-1099/1091.Shortest%20Path%20in%20Binary%20Matrix/images/example2_1.png" style="height: 216px; width: 500px;" />
<pre>
<strong>输入：</strong>grid = [[0,0,0],[1,1,0],[1,1,0]]
<strong>输出：</strong>4
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>grid = [[1,0,0],[1,1,0],[1,1,0]]
<strong>输出：</strong>-1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>grid[i][j]</code> 为 <code>0</code> 或 <code>1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：BFS

根据题目描述，一条畅通路径是从左上角单元格 $(0, 0)$ 到右下角单元格 $(n - 1, n - 1)$ 的路径，且路径上所有单元格的值都是 $0$。

因此，如果左上角单元格 $(0, 0)$ 的值为 $1$，则不存在满足要求的路径，直接返回 $-1$。

否则，我们创建一个队列 $q$，将左上角单元格 $(0, 0)$ 加入队列，并且将其标记为已访问，即把 $grid[0][0]$ 的值置为 $1$，然后开始广度优先搜索。

在每一轮搜索中，我们每次取出队首节点 $(i, j)$，如果 $(i, j)$ 为右下角单元格 $(n - 1, n - 1)$，则路径长度为当前的搜索轮数，直接返回。否则，我们将当前节点的所有未被访问过的相邻节点加入队列，并且将它们标记为已访问。每一轮搜索结束后，我们将搜索轮数增加 $1$。然后继续执行上述过程，直到队列为空或者找到目标节点。

如果在搜索结束后，我们仍然没有到达右下角的节点，那么说明右下角的节点不可达，返回 $-1$。

时间复杂度 $O(n^2)$，空间复杂度 $O(n^2)$。其中 $n$ 是给定的二进制矩阵的边长。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        if grid[0][0]:
            return -1
        n = len(grid)
        grid[0][0] = 1
        q = deque([(0, 0)])
        ans = 1
        while q:
            for _ in range(len(q)):
                i, j = q.popleft()
                if i == j == n - 1:
                    return ans
                for x in range(i - 1, i + 2):
                    for y in range(j - 1, j + 2):
                        if 0 <= x < n and 0 <= y < n and grid[x][y] == 0:
                            grid[x][y] = 1
                            q.append((x, y))
            ans += 1
        return -1
```

#### Java

```java
class Solution {
    public int shortestPathBinaryMatrix(int[][] grid) {
        if (grid[0][0] == 1) {
            return -1;
        }
        int n = grid.length;
        grid[0][0] = 1;
        Deque<int[]> q = new ArrayDeque<>();
        q.offer(new int[] {0, 0});
        for (int ans = 1; !q.isEmpty(); ++ans) {
            for (int k = q.size(); k > 0; --k) {
                var p = q.poll();
                int i = p[0], j = p[1];
                if (i == n - 1 && j == n - 1) {
                    return ans;
                }
                for (int x = i - 1; x <= i + 1; ++x) {
                    for (int y = j - 1; y <= j + 1; ++y) {
                        if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 0) {
                            grid[x][y] = 1;
                            q.offer(new int[] {x, y});
                        }
                    }
                }
            }
        }
        return -1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0]) {
            return -1;
        }
        int n = grid.size();
        grid[0][0] = 1;
        queue<pair<int, int>> q;
        q.emplace(0, 0);
        for (int ans = 1; !q.empty(); ++ans) {
            for (int k = q.size(); k; --k) {
                auto [i, j] = q.front();
                q.pop();
                if (i == n - 1 && j == n - 1) {
                    return ans;
                }
                for (int x = i - 1; x <= i + 1; ++x) {
                    for (int y = j - 1; y <= j + 1; ++y) {
                        if (x >= 0 && x < n && y >= 0 && y < n && !grid[x][y]) {
                            grid[x][y] = 1;
                            q.emplace(x, y);
                        }
                    }
                }
            }
        }
        return -1;
    }
};
```

#### Go

```go
func shortestPathBinaryMatrix(grid [][]int) int {
	if grid[0][0] == 1 {
		return -1
	}
	n := len(grid)
	grid[0][0] = 1
	q := [][2]int{{0, 0}}
	for ans := 1; len(q) > 0; ans++ {
		for k := len(q); k > 0; k-- {
			p := q[0]
			i, j := p[0], p[1]
			q = q[1:]
			if i == n-1 && j == n-1 {
				return ans
			}
			for x := i - 1; x <= i+1; x++ {
				for y := j - 1; y <= j+1; y++ {
					if x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 0 {
						grid[x][y] = 1
						q = append(q, [2]int{x, y})
					}
				}
			}
		}
	}
	return -1
}
```

#### TypeScript

```ts
function shortestPathBinaryMatrix(grid: number[][]): number {
    if (grid[0][0]) {
        return -1;
    }
    const max = grid.length - 1;
    grid[0][0] = 1;
    let q: number[][] = [[0, 0]];
    for (let ans = 1; q.length > 0; ++ans) {
        const nq: number[][] = [];
        for (const [i, j] of q) {
            if (i === max && j === max) {
                return ans;
            }
            for (let x = i - 1; x <= i + 1; ++x) {
                for (let y = j - 1; y <= j + 1; ++y) {
                    if (grid[x]?.[y] === 0) {
                        grid[x][y] = 1;
                        nq.push([x, y]);
                    }
                }
            }
        }
        q = nq;
    }
    return -1;
}
```

#### Rust

```rust
use std::collections::VecDeque;
impl Solution {
    pub fn shortest_path_binary_matrix(mut grid: Vec<Vec<i32>>) -> i32 {
        let n = grid.len();
        let mut queue = VecDeque::new();
        queue.push_back([0, 0]);
        let mut res = 0;
        while !queue.is_empty() {
            res += 1;
            for _ in 0..queue.len() {
                let [i, j] = queue.pop_front().unwrap();
                if grid[i][j] == 1 {
                    continue;
                }
                if i == n - 1 && j == n - 1 {
                    return res;
                }
                grid[i][j] = 1;
                for x in -1..=1 {
                    for y in -1..=1 {
                        let x = x + (i as i32);
                        let y = y + (j as i32);
                        if x < 0 || x == (n as i32) || y < 0 || y == (n as i32) {
                            continue;
                        }
                        queue.push_back([x as usize, y as usize]);
                    }
                }
            }
        }
        -1
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1092. 最短公共超序列](https://leetcode.cn/problems/shortest-common-supersequence){#1092}

{{< tabs "1092" >}}

{{% tab "bash" %}}
```bash
str1:       a   b   a   c

str2:   c   a   b

ans:    c   a   b   a   c
```
{{% /tab %}}
{{% tab "python" %}}
```python
class Solution:
    def shortestCommonSupersequence(self, str1: str, str2: str) -> str:
        m, n = len(str1), len(str2)
        f = [[0] * (n + 1) for _ in range(m + 1)]
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if str1[i - 1] == str2[j - 1]:
                    f[i][j] = f[i - 1][j - 1] + 1
                else:
                    f[i][j] = max(f[i - 1][j], f[i][j - 1])
        ans = []
        i, j = m, n
        while i or j:
            if i == 0:
                j -= 1
                ans.append(str2[j])
            elif j == 0:
                i -= 1
                ans.append(str1[i])
            else:
                if f[i][j] == f[i - 1][j]:
                    i -= 1
                    ans.append(str1[i])
                elif f[i][j] == f[i][j - 1]:
                    j -= 1
                    ans.append(str2[j])
                else:
                    i, j = i - 1, j - 1
                    ans.append(str1[i])
        return ''.join(ans[::-1])
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String shortestCommonSupersequence(String str1, String str2) {
        int m = str1.length(), n = str2.length();
        int[][] f = new int[m + 1][n + 1];
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (str1.charAt(i - 1) == str2.charAt(j - 1)) {
                    f[i][j] = f[i - 1][j - 1] + 1;
                } else {
                    f[i][j] = Math.max(f[i - 1][j], f[i][j - 1]);
                }
            }
        }
        int i = m, j = n;
        StringBuilder ans = new StringBuilder();
        while (i > 0 || j > 0) {
            if (i == 0) {
                ans.append(str2.charAt(--j));
            } else if (j == 0) {
                ans.append(str1.charAt(--i));
            } else {
                if (f[i][j] == f[i - 1][j]) {
                    ans.append(str1.charAt(--i));
                } else if (f[i][j] == f[i][j - 1]) {
                    ans.append(str2.charAt(--j));
                } else {
                    ans.append(str1.charAt(--i));
                    --j;
                }
            }
        }
        return ans.reverse().toString();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size(), n = str2.size();
        vector<vector<int>> f(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (str1[i - 1] == str2[j - 1])
                    f[i][j] = f[i - 1][j - 1] + 1;
                else
                    f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            }
        }
        int i = m, j = n;
        string ans;
        while (i || j) {
            if (i == 0)
                ans += str2[--j];
            else if (j == 0)
                ans += str1[--i];
            else {
                if (f[i][j] == f[i - 1][j])
                    ans += str1[--i];
                else if (f[i][j] == f[i][j - 1])
                    ans += str2[--j];
                else
                    ans += str1[--i], --j;
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
func shortestCommonSupersequence(str1 string, str2 string) string {
	m, n := len(str1), len(str2)
	f := make([][]int, m+1)
	for i := range f {
		f[i] = make([]int, n+1)
	}
	for i := 1; i <= m; i++ {
		for j := 1; j <= n; j++ {
			if str1[i-1] == str2[j-1] {
				f[i][j] = f[i-1][j-1] + 1
			} else {
				f[i][j] = max(f[i-1][j], f[i][j-1])
			}
		}
	}
	ans := []byte{}
	i, j := m, n
	for i > 0 || j > 0 {
		if i == 0 {
			j--
			ans = append(ans, str2[j])
		} else if j == 0 {
			i--
			ans = append(ans, str1[i])
		} else {
			if f[i][j] == f[i-1][j] {
				i--
				ans = append(ans, str1[i])
			} else if f[i][j] == f[i][j-1] {
				j--
				ans = append(ans, str2[j])
			} else {
				i, j = i-1, j-1
				ans = append(ans, str1[i])
			}
		}
	}
	for i, j = 0, len(ans)-1; i < j; i, j = i+1, j-1 {
		ans[i], ans[j] = ans[j], ans[i]
	}
	return string(ans)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function shortestCommonSupersequence(str1: string, str2: string): string {
    const m = str1.length;
    const n = str2.length;
    const f = new Array(m + 1).fill(0).map(() => new Array(n + 1).fill(0));
    for (let i = 1; i <= m; ++i) {
        for (let j = 1; j <= n; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                f[i][j] = f[i - 1][j - 1] + 1;
            } else {
                f[i][j] = Math.max(f[i - 1][j], f[i][j - 1]);
            }
        }
    }
    let ans: string[] = [];
    let i = m;
    let j = n;
    while (i > 0 || j > 0) {
        if (i === 0) {
            ans.push(str2[--j]);
        } else if (j === 0) {
            ans.push(str1[--i]);
        } else {
            if (f[i][j] === f[i - 1][j]) {
                ans.push(str1[--i]);
            } else if (f[i][j] === f[i][j - 1]) {
                ans.push(str2[--j]);
            } else {
                ans.push(str1[--i]);
                --j;
            }
        }
    }
    return ans.reverse().join('');
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个字符串&nbsp;<code>str1</code> 和&nbsp;<code>str2</code>，返回同时以&nbsp;<code>str1</code>&nbsp;和&nbsp;<code>str2</code>&nbsp;作为 <strong>子序列</strong> 的最短字符串。如果答案不止一个，则可以返回满足条件的 <strong>任意一个</strong> 答案。</p>

<p>如果从字符串 <code>t</code> 中删除一些字符（也可能不删除），可以得到字符串 <code>s</code> ，那么 <code>s</code> 就是 t 的一个子序列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>str1 = "abac", str2 = "cab"
<strong>输出：</strong>"cabac"
<strong>解释：</strong>
str1 = "abac" 是 "cabac" 的一个子串，因为我们可以删去 "cabac" 的第一个 "c"得到 "abac"。 
str2 = "cab" 是 "cabac" 的一个子串，因为我们可以删去 "cabac" 末尾的 "ac" 得到 "cab"。
最终我们给出的答案是满足上述属性的最短字符串。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>str1 = "aaaaaaaa", str2 = "aaaaaaaa"
<strong>输出：</strong>"aaaaaaaa"
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= str1.length, str2.length &lt;= 1000</code></li>
	<li><code>str1</code> 和&nbsp;<code>str2</code>&nbsp;都由小写英文字母组成。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划 + 构造

我们先用动态规划求出两个字符串的最长公共子序列，然后根据最长公共子序列构造出最短公共超序列。

定义 $f[i][j]$ 表示字符串 $str1$ 的前 $i$ 个字符和字符串 $str2$ 的前 $j$ 个字符的最长公共子序列的长度。状态转移方程如下：

$$
f[i][j] =
\begin{cases}
0 & i = 0 \textit{ or } j = 0 \\
f[i - 1][j - 1] + 1 & str1[i - 1] = str2[j - 1] \\
\max(f[i - 1][j], f[i][j - 1]) & str1[i - 1] \neq str2[j - 1]
\end{cases}
$$

接下来我们基于 $f[i][j]$ 构造出最短公共超序列。

```bash
str1:       a   b   a   c

str2:   c   a   b

ans:    c   a   b   a   c
```

不妨对照着上面的示例字符串，来看看如何构造出最短公共超序列。

我们用双指针 $i$ 和 $j$ 分别指向字符串 $str1$ 和 $str2$ 的末尾，然后从后往前遍历，每次比较 $str1[i]$ 和 $str2[j]$ 的值：

-   如果 $str1[i] = str2[j]$，则将 $str1[i]$ 或 $str2[j]$ 中的任意一个字符加入到最答案序列的末尾，然后 $i$ 和 $j$ 同时减 $1$；
-   如果 $str1[i] \neq str2[j]$，则将 $f[i][j]$ 与 $f[i - 1][j]$ 和 $f[i][j - 1]$ 中的最大值进行比较：
    -   如果 $f[i][j] = f[i - 1][j]$，则将 $str1[i]$ 加入到答案序列的末尾，然后 $i$ 减 $1$；
    -   如果 $f[i][j] = f[i][j - 1]$，则将 $str2[j]$ 加入到答案序列的末尾，然后 $j$ 减 $1$。

重复上述操作，直到 $i = 0$ 或 $j = 0$，然后将剩余的字符串加入到答案序列的末尾即可。

最后我们将答案序列反转，即可得到最终的答案。

时间复杂度 $O(m\times n)$，空间复杂度 $O(m\times n)$。其中 $m$ 和 $n$ 分别是字符串 $str1$ 和 $str2$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def shortestCommonSupersequence(self, str1: str, str2: str) -> str:
        m, n = len(str1), len(str2)
        f = [[0] * (n + 1) for _ in range(m + 1)]
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if str1[i - 1] == str2[j - 1]:
                    f[i][j] = f[i - 1][j - 1] + 1
                else:
                    f[i][j] = max(f[i - 1][j], f[i][j - 1])
        ans = []
        i, j = m, n
        while i or j:
            if i == 0:
                j -= 1
                ans.append(str2[j])
            elif j == 0:
                i -= 1
                ans.append(str1[i])
            else:
                if f[i][j] == f[i - 1][j]:
                    i -= 1
                    ans.append(str1[i])
                elif f[i][j] == f[i][j - 1]:
                    j -= 1
                    ans.append(str2[j])
                else:
                    i, j = i - 1, j - 1
                    ans.append(str1[i])
        return ''.join(ans[::-1])
```

#### Java

```java
class Solution {
    public String shortestCommonSupersequence(String str1, String str2) {
        int m = str1.length(), n = str2.length();
        int[][] f = new int[m + 1][n + 1];
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (str1.charAt(i - 1) == str2.charAt(j - 1)) {
                    f[i][j] = f[i - 1][j - 1] + 1;
                } else {
                    f[i][j] = Math.max(f[i - 1][j], f[i][j - 1]);
                }
            }
        }
        int i = m, j = n;
        StringBuilder ans = new StringBuilder();
        while (i > 0 || j > 0) {
            if (i == 0) {
                ans.append(str2.charAt(--j));
            } else if (j == 0) {
                ans.append(str1.charAt(--i));
            } else {
                if (f[i][j] == f[i - 1][j]) {
                    ans.append(str1.charAt(--i));
                } else if (f[i][j] == f[i][j - 1]) {
                    ans.append(str2.charAt(--j));
                } else {
                    ans.append(str1.charAt(--i));
                    --j;
                }
            }
        }
        return ans.reverse().toString();
    }
}
```

#### C++

```cpp
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size(), n = str2.size();
        vector<vector<int>> f(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (str1[i - 1] == str2[j - 1])
                    f[i][j] = f[i - 1][j - 1] + 1;
                else
                    f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            }
        }
        int i = m, j = n;
        string ans;
        while (i || j) {
            if (i == 0)
                ans += str2[--j];
            else if (j == 0)
                ans += str1[--i];
            else {
                if (f[i][j] == f[i - 1][j])
                    ans += str1[--i];
                else if (f[i][j] == f[i][j - 1])
                    ans += str2[--j];
                else
                    ans += str1[--i], --j;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```

#### Go

```go
func shortestCommonSupersequence(str1 string, str2 string) string {
	m, n := len(str1), len(str2)
	f := make([][]int, m+1)
	for i := range f {
		f[i] = make([]int, n+1)
	}
	for i := 1; i <= m; i++ {
		for j := 1; j <= n; j++ {
			if str1[i-1] == str2[j-1] {
				f[i][j] = f[i-1][j-1] + 1
			} else {
				f[i][j] = max(f[i-1][j], f[i][j-1])
			}
		}
	}
	ans := []byte{}
	i, j := m, n
	for i > 0 || j > 0 {
		if i == 0 {
			j--
			ans = append(ans, str2[j])
		} else if j == 0 {
			i--
			ans = append(ans, str1[i])
		} else {
			if f[i][j] == f[i-1][j] {
				i--
				ans = append(ans, str1[i])
			} else if f[i][j] == f[i][j-1] {
				j--
				ans = append(ans, str2[j])
			} else {
				i, j = i-1, j-1
				ans = append(ans, str1[i])
			}
		}
	}
	for i, j = 0, len(ans)-1; i < j; i, j = i+1, j-1 {
		ans[i], ans[j] = ans[j], ans[i]
	}
	return string(ans)
}
```

#### TypeScript

```ts
function shortestCommonSupersequence(str1: string, str2: string): string {
    const m = str1.length;
    const n = str2.length;
    const f = new Array(m + 1).fill(0).map(() => new Array(n + 1).fill(0));
    for (let i = 1; i <= m; ++i) {
        for (let j = 1; j <= n; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                f[i][j] = f[i - 1][j - 1] + 1;
            } else {
                f[i][j] = Math.max(f[i - 1][j], f[i][j - 1]);
            }
        }
    }
    let ans: string[] = [];
    let i = m;
    let j = n;
    while (i > 0 || j > 0) {
        if (i === 0) {
            ans.push(str2[--j]);
        } else if (j === 0) {
            ans.push(str1[--i]);
        } else {
            if (f[i][j] === f[i - 1][j]) {
                ans.push(str1[--i]);
            } else if (f[i][j] === f[i][j - 1]) {
                ans.push(str2[--j]);
            } else {
                ans.push(str1[--i]);
                --j;
            }
        }
    }
    return ans.reverse().join('');
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1093. 大样本统计](https://leetcode.cn/problems/statistics-from-a-large-sample){#1093}

{{< tabs "1093" >}}

{{% tab "python" %}}
```python
class Solution:
    def sampleStats(self, count: List[int]) -> List[float]:
        def find(i: int) -> int:
            t = 0
            for k, x in enumerate(count):
                t += x
                if t >= i:
                    return k

        mi, mx = inf, -1
        s = cnt = 0
        mode = 0
        for k, x in enumerate(count):
            if x:
                mi = min(mi, k)
                mx = max(mx, k)
                s += k * x
                cnt += x
                if x > count[mode]:
                    mode = k

        median = (
            find(cnt // 2 + 1) if cnt & 1 else (find(cnt // 2) + find(cnt // 2 + 1)) / 2
        )
        return [mi, mx, s / cnt, median, mode]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[] count;

    public double[] sampleStats(int[] count) {
        this.count = count;
        int mi = 1 << 30, mx = -1;
        long s = 0;
        int cnt = 0;
        int mode = 0;
        for (int k = 0; k < count.length; ++k) {
            if (count[k] > 0) {
                mi = Math.min(mi, k);
                mx = Math.max(mx, k);
                s += 1L * k * count[k];
                cnt += count[k];
                if (count[k] > count[mode]) {
                    mode = k;
                }
            }
        }
        double median
            = cnt % 2 == 1 ? find(cnt / 2 + 1) : (find(cnt / 2) + find(cnt / 2 + 1)) / 2.0;
        return new double[] {mi, mx, s * 1.0 / cnt, median, mode};
    }

    private int find(int i) {
        for (int k = 0, t = 0;; ++k) {
            t += count[k];
            if (t >= i) {
                return k;
            }
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        auto find = [&](int i) -> int {
            for (int k = 0, t = 0;; ++k) {
                t += count[k];
                if (t >= i) {
                    return k;
                }
            }
        };
        int mi = 1 << 30, mx = -1;
        long long s = 0;
        int cnt = 0, mode = 0;
        for (int k = 0; k < count.size(); ++k) {
            if (count[k]) {
                mi = min(mi, k);
                mx = max(mx, k);
                s += 1LL * k * count[k];
                cnt += count[k];
                if (count[k] > count[mode]) {
                    mode = k;
                }
            }
        }
        double median = cnt % 2 == 1 ? find(cnt / 2 + 1) : (find(cnt / 2) + find(cnt / 2 + 1)) / 2.0;
        return vector<double>{(double) mi, (double) mx, s * 1.0 / cnt, median, (double) mode};
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func sampleStats(count []int) []float64 {
	find := func(i int) int {
		for k, t := 0, 0; ; k++ {
			t += count[k]
			if t >= i {
				return k
			}
		}
	}
	mi, mx := 1<<30, -1
	s, cnt, mode := 0, 0, 0
	for k, x := range count {
		if x > 0 {
			mi = min(mi, k)
			mx = max(mx, k)
			s += k * x
			cnt += x
			if x > count[mode] {
				mode = k
			}
		}
	}
	var median float64
	if cnt&1 == 1 {
		median = float64(find(cnt/2 + 1))
	} else {
		median = float64(find(cnt/2)+find(cnt/2+1)) / 2
	}
	return []float64{float64(mi), float64(mx), float64(s) / float64(cnt), median, float64(mode)}
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function sampleStats(count: number[]): number[] {
    const find = (i: number): number => {
        for (let k = 0, t = 0; ; ++k) {
            t += count[k];
            if (t >= i) {
                return k;
            }
        }
    };
    let mi = 1 << 30;
    let mx = -1;
    let [s, cnt, mode] = [0, 0, 0];
    for (let k = 0; k < count.length; ++k) {
        if (count[k] > 0) {
            mi = Math.min(mi, k);
            mx = Math.max(mx, k);
            s += k * count[k];
            cnt += count[k];
            if (count[k] > count[mode]) {
                mode = k;
            }
        }
    }
    const median =
        cnt % 2 === 1 ? find((cnt >> 1) + 1) : (find(cnt >> 1) + find((cnt >> 1) + 1)) / 2;
    return [mi, mx, s / cnt, median, mode];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>我们对&nbsp;<code>0</code>&nbsp;到&nbsp;<code>255</code>&nbsp;之间的整数进行采样，并将结果存储在数组&nbsp;<code>count</code>&nbsp;中：<code>count[k]</code>&nbsp;就是整数&nbsp;<code>k</code> 在样本中出现的次数。</p>

<p>计算以下统计数据:</p>

<ul>
	<li><code>minimum</code>&nbsp;：样本中的最小元素。</li>
	<li><code>maximum</code>&nbsp;：样品中的最大元素。</li>
	<li><code>mean</code>&nbsp;：样本的平均值，计算为所有元素的总和除以元素总数。</li>
	<li><code>median</code>&nbsp;：
	<ul>
		<li>如果样本的元素个数是奇数，那么一旦样本排序后，中位数 <code>median</code> 就是中间的元素。</li>
		<li>如果样本中有偶数个元素，那么中位数<code>median</code> 就是样本排序后中间两个元素的平均值。</li>
	</ul>
	</li>
	<li><code>mode</code>&nbsp;：样本中出现次数最多的数字。保众数是 <strong>唯一</strong> 的。</li>
</ul>

<p>以浮点数数组的形式返回样本的统计信息<em>&nbsp;</em><code>[minimum, maximum, mean, median, mode]</code>&nbsp;。与真实答案误差在<em>&nbsp;</em><code>10<sup>-5</sup></code><em>&nbsp;</em>内的答案都可以通过。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>count = [0,1,3,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
<strong>输出：</strong>[1.00000,3.00000,2.37500,2.50000,3.00000]
<strong>解释：</strong>用count表示的样本为[1,2,2,2,3,3,3,3]。
最小值和最大值分别为1和3。
均值是(1+2+2+2+3+3+3+3) / 8 = 19 / 8 = 2.375。
因为样本的大小是偶数，所以中位数是中间两个元素2和3的平均值，也就是2.5。
众数为3，因为它在样本中出现的次数最多。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>count = [0,4,3,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
<strong>输出：</strong>[1.00000,4.00000,2.18182,2.00000,1.00000]
<strong>解释：</strong>用count表示的样本为[1,1,1,1,2,2,3,3,3,4,4]。
最小值为1，最大值为4。
平均数是(1+1+1+1+2+2+2+3+3+4+4)/ 11 = 24 / 11 = 2.18181818…(为了显示，输出显示了整数2.18182)。
因为样本的大小是奇数，所以中值是中间元素2。
众数为1，因为它在样本中出现的次数最多。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>count.length == 256</code></li>
	<li><code>0 &lt;= count[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= sum(count) &lt;= 10<sup>9</sup></code></li>
	<li>&nbsp;<code>count</code>&nbsp;的众数是 <strong>唯一</strong> 的</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们直接根据题目描述模拟即可，定义以下变量：

-   变量 $mi$ 表示最小值；
-   变量 $mx$ 表示最大值；
-   变量 $s$ 表示总和；
-   变量 $cnt$ 表示总个数；
-   变量 $mode$ 表示众数。

我们遍历数组 $count$，对于当前遍历到的数字 $count[k]$，如果 $count[k] \gt 0$，那么我们做以下更新操作：

-   更新 $mi = \min(mi, k)$；
-   更新 $mx = \max(mx, k)$；
-   更新 $s = s + k \times count[k]$；
-   更新 $cnt = cnt + count[k]$；
-   如果 $count[k] \gt count[mode]$，那么更新 $mode = k$。

遍历结束后，我们再根据 $cnt$ 的奇偶性来计算中位数 $median$，如果 $cnt$ 是奇数，那么中位数就是第 $\lfloor \frac{cnt}{2} \rfloor + 1$ 个数字，如果 $cnt$ 是偶数，那么中位数就是第 $\lfloor \frac{cnt}{2} \rfloor$ 和第 $\lfloor \frac{cnt}{2} \rfloor + 1$ 个数字的平均值。

> 这里我们通过一个简单的辅助函数 $find(i)$ 来找到第 $i$ 个数字，具体实现可以参考下面的代码。

最后，我们将 $mi, mx, \frac{s}{cnt}, median, mode$ 放入答案数组中返回即可。

时间复杂度 $O(n)$，其中 $n$ 是数组 $count$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def sampleStats(self, count: List[int]) -> List[float]:
        def find(i: int) -> int:
            t = 0
            for k, x in enumerate(count):
                t += x
                if t >= i:
                    return k

        mi, mx = inf, -1
        s = cnt = 0
        mode = 0
        for k, x in enumerate(count):
            if x:
                mi = min(mi, k)
                mx = max(mx, k)
                s += k * x
                cnt += x
                if x > count[mode]:
                    mode = k

        median = (
            find(cnt // 2 + 1) if cnt & 1 else (find(cnt // 2) + find(cnt // 2 + 1)) / 2
        )
        return [mi, mx, s / cnt, median, mode]
```

#### Java

```java
class Solution {
    private int[] count;

    public double[] sampleStats(int[] count) {
        this.count = count;
        int mi = 1 << 30, mx = -1;
        long s = 0;
        int cnt = 0;
        int mode = 0;
        for (int k = 0; k < count.length; ++k) {
            if (count[k] > 0) {
                mi = Math.min(mi, k);
                mx = Math.max(mx, k);
                s += 1L * k * count[k];
                cnt += count[k];
                if (count[k] > count[mode]) {
                    mode = k;
                }
            }
        }
        double median
            = cnt % 2 == 1 ? find(cnt / 2 + 1) : (find(cnt / 2) + find(cnt / 2 + 1)) / 2.0;
        return new double[] {mi, mx, s * 1.0 / cnt, median, mode};
    }

    private int find(int i) {
        for (int k = 0, t = 0;; ++k) {
            t += count[k];
            if (t >= i) {
                return k;
            }
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        auto find = [&](int i) -> int {
            for (int k = 0, t = 0;; ++k) {
                t += count[k];
                if (t >= i) {
                    return k;
                }
            }
        };
        int mi = 1 << 30, mx = -1;
        long long s = 0;
        int cnt = 0, mode = 0;
        for (int k = 0; k < count.size(); ++k) {
            if (count[k]) {
                mi = min(mi, k);
                mx = max(mx, k);
                s += 1LL * k * count[k];
                cnt += count[k];
                if (count[k] > count[mode]) {
                    mode = k;
                }
            }
        }
        double median = cnt % 2 == 1 ? find(cnt / 2 + 1) : (find(cnt / 2) + find(cnt / 2 + 1)) / 2.0;
        return vector<double>{(double) mi, (double) mx, s * 1.0 / cnt, median, (double) mode};
    }
};
```

#### Go

```go
func sampleStats(count []int) []float64 {
	find := func(i int) int {
		for k, t := 0, 0; ; k++ {
			t += count[k]
			if t >= i {
				return k
			}
		}
	}
	mi, mx := 1<<30, -1
	s, cnt, mode := 0, 0, 0
	for k, x := range count {
		if x > 0 {
			mi = min(mi, k)
			mx = max(mx, k)
			s += k * x
			cnt += x
			if x > count[mode] {
				mode = k
			}
		}
	}
	var median float64
	if cnt&1 == 1 {
		median = float64(find(cnt/2 + 1))
	} else {
		median = float64(find(cnt/2)+find(cnt/2+1)) / 2
	}
	return []float64{float64(mi), float64(mx), float64(s) / float64(cnt), median, float64(mode)}
}
```

#### TypeScript

```ts
function sampleStats(count: number[]): number[] {
    const find = (i: number): number => {
        for (let k = 0, t = 0; ; ++k) {
            t += count[k];
            if (t >= i) {
                return k;
            }
        }
    };
    let mi = 1 << 30;
    let mx = -1;
    let [s, cnt, mode] = [0, 0, 0];
    for (let k = 0; k < count.length; ++k) {
        if (count[k] > 0) {
            mi = Math.min(mi, k);
            mx = Math.max(mx, k);
            s += k * count[k];
            cnt += count[k];
            if (count[k] > count[mode]) {
                mode = k;
            }
        }
    }
    const median =
        cnt % 2 === 1 ? find((cnt >> 1) + 1) : (find(cnt >> 1) + find((cnt >> 1) + 1)) / 2;
    return [mi, mx, s / cnt, median, mode];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1094. 拼车](https://leetcode.cn/problems/car-pooling){#1094}

{{< tabs "1094" >}}

{{% tab "python" %}}
```python
class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        mx = max(e[2] for e in trips)
        d = [0] * (mx + 1)
        for x, f, t in trips:
            d[f] += x
            d[t] -= x
        return all(s <= capacity for s in accumulate(d))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean carPooling(int[][] trips, int capacity) {
        int[] d = new int[1001];
        for (var trip : trips) {
            int x = trip[0], f = trip[1], t = trip[2];
            d[f] += x;
            d[t] -= x;
        }
        int s = 0;
        for (int x : d) {
            s += x;
            if (s > capacity) {
                return false;
            }
        }
        return true;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int d[1001]{};
        for (auto& trip : trips) {
            int x = trip[0], f = trip[1], t = trip[2];
            d[f] += x;
            d[t] -= x;
        }
        int s = 0;
        for (int x : d) {
            s += x;
            if (s > capacity) {
                return false;
            }
        }
        return true;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func carPooling(trips [][]int, capacity int) bool {
	d := [1001]int{}
	for _, trip := range trips {
		x, f, t := trip[0], trip[1], trip[2]
		d[f] += x
		d[t] -= x
	}
	s := 0
	for _, x := range d {
		s += x
		if s > capacity {
			return false
		}
	}
	return true
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function carPooling(trips: number[][], capacity: number): boolean {
    const mx = Math.max(...trips.map(([, , t]) => t));
    const d = Array(mx + 1).fill(0);
    for (const [x, f, t] of trips) {
        d[f] += x;
        d[t] -= x;
    }
    let s = 0;
    for (const x of d) {
        s += x;
        if (s > capacity) {
            return false;
        }
    }
    return true;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn car_pooling(trips: Vec<Vec<i32>>, capacity: i32) -> bool {
        let mx = trips.iter().map(|e| e[2]).max().unwrap_or(0) as usize;
        let mut d = vec![0; mx + 1];
        for trip in &trips {
            let (x, f, t) = (trip[0], trip[1] as usize, trip[2] as usize);
            d[f] += x;
            d[t] -= x;
        }
        d.iter()
            .scan(0, |acc, &x| {
                *acc += x;
                Some(*acc)
            })
            .all(|s| s <= capacity)
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[][]} trips
 * @param {number} capacity
 * @return {boolean}
 */
var carPooling = function (trips, capacity) {
    const mx = Math.max(...trips.map(([, , t]) => t));
    const d = Array(mx + 1).fill(0);
    for (const [x, f, t] of trips) {
        d[f] += x;
        d[t] -= x;
    }
    let s = 0;
    for (const x of d) {
        s += x;
        if (s > capacity) {
            return false;
        }
    }
    return true;
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public bool CarPooling(int[][] trips, int capacity) {
        int mx = trips.Max(x => x[2]);
        int[] d = new int[mx + 1];
        foreach (var trip in trips) {
            int x = trip[0], f = trip[1], t = trip[2];
            d[f] += x;
            d[t] -= x;
        }
        int s = 0;
        foreach (var x in d) {
            s += x;
            if (s > capacity) {
                return false;
            }
        }
        return true;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>车上最初有&nbsp;<code>capacity</code>&nbsp;个空座位。车&nbsp;<strong>只能&nbsp;</strong>向一个方向行驶（也就是说，<strong>不允许掉头或改变方向</strong>）</p>

<p>给定整数&nbsp;<code>capacity</code>&nbsp;和一个数组 <code>trips</code> , &nbsp;<code>trips[i] = [numPassengers<sub>i</sub>, from<sub>i</sub>, to<sub>i</sub>]</code>&nbsp;表示第 <code>i</code> 次旅行有&nbsp;<code>numPassengers<sub>i</sub></code>&nbsp;乘客，接他们和放他们的位置分别是&nbsp;<code>from<sub>i</sub></code>&nbsp;和&nbsp;<code>to<sub>i</sub></code>&nbsp;。这些位置是从汽车的初始位置向东的公里数。</p>

<p>当且仅当你可以在所有给定的行程中接送所有乘客时，返回&nbsp;<code>true</code>，否则请返回 <code>false</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>trips = [[2,1,5],[3,3,7]], capacity = 4
<strong>输出：</strong>false
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>trips = [[2,1,5],[3,3,7]], capacity = 5
<strong>输出：</strong>true
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= trips.length &lt;= 1000</code></li>
	<li><code>trips[i].length == 3</code></li>
	<li><code>1 &lt;= numPassengers<sub>i</sub>&nbsp;&lt;= 100</code></li>
	<li><code>0 &lt;= from<sub>i</sub>&nbsp;&lt; to<sub>i</sub>&nbsp;&lt;= 1000</code></li>
	<li><code>1 &lt;= capacity &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：差分数组

我们可以利用差分数组的思想，将每个行程的乘客数加到起点，减去终点，最后我们只需要判断差分数组的前缀和是否都不大于车的最大载客量即可。

时间复杂度 $O(n)$，空间复杂度 $O(M)$。其中 $n$ 是行程数，而 $M$ 是行程中最大的终点，本题中 $M \le 1000$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        mx = max(e[2] for e in trips)
        d = [0] * (mx + 1)
        for x, f, t in trips:
            d[f] += x
            d[t] -= x
        return all(s <= capacity for s in accumulate(d))
```

#### Java

```java
class Solution {
    public boolean carPooling(int[][] trips, int capacity) {
        int[] d = new int[1001];
        for (var trip : trips) {
            int x = trip[0], f = trip[1], t = trip[2];
            d[f] += x;
            d[t] -= x;
        }
        int s = 0;
        for (int x : d) {
            s += x;
            if (s > capacity) {
                return false;
            }
        }
        return true;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int d[1001]{};
        for (auto& trip : trips) {
            int x = trip[0], f = trip[1], t = trip[2];
            d[f] += x;
            d[t] -= x;
        }
        int s = 0;
        for (int x : d) {
            s += x;
            if (s > capacity) {
                return false;
            }
        }
        return true;
    }
};
```

#### Go

```go
func carPooling(trips [][]int, capacity int) bool {
	d := [1001]int{}
	for _, trip := range trips {
		x, f, t := trip[0], trip[1], trip[2]
		d[f] += x
		d[t] -= x
	}
	s := 0
	for _, x := range d {
		s += x
		if s > capacity {
			return false
		}
	}
	return true
}
```

#### TypeScript

```ts
function carPooling(trips: number[][], capacity: number): boolean {
    const mx = Math.max(...trips.map(([, , t]) => t));
    const d = Array(mx + 1).fill(0);
    for (const [x, f, t] of trips) {
        d[f] += x;
        d[t] -= x;
    }
    let s = 0;
    for (const x of d) {
        s += x;
        if (s > capacity) {
            return false;
        }
    }
    return true;
}
```

#### Rust

```rust
impl Solution {
    pub fn car_pooling(trips: Vec<Vec<i32>>, capacity: i32) -> bool {
        let mx = trips.iter().map(|e| e[2]).max().unwrap_or(0) as usize;
        let mut d = vec![0; mx + 1];
        for trip in &trips {
            let (x, f, t) = (trip[0], trip[1] as usize, trip[2] as usize);
            d[f] += x;
            d[t] -= x;
        }
        d.iter()
            .scan(0, |acc, &x| {
                *acc += x;
                Some(*acc)
            })
            .all(|s| s <= capacity)
    }
}
```

#### JavaScript

```js
/**
 * @param {number[][]} trips
 * @param {number} capacity
 * @return {boolean}
 */
var carPooling = function (trips, capacity) {
    const mx = Math.max(...trips.map(([, , t]) => t));
    const d = Array(mx + 1).fill(0);
    for (const [x, f, t] of trips) {
        d[f] += x;
        d[t] -= x;
    }
    let s = 0;
    for (const x of d) {
        s += x;
        if (s > capacity) {
            return false;
        }
    }
    return true;
};
```

#### C#

```cs
public class Solution {
    public bool CarPooling(int[][] trips, int capacity) {
        int mx = trips.Max(x => x[2]);
        int[] d = new int[mx + 1];
        foreach (var trip in trips) {
            int x = trip[0], f = trip[1], t = trip[2];
            d[f] += x;
            d[t] -= x;
        }
        int s = 0;
        foreach (var x in d) {
            s += x;
            if (s > capacity) {
                return false;
            }
        }
        return true;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1095. 山脉数组中查找目标值](https://leetcode.cn/problems/find-in-mountain-array){#1095}

{{< tabs "1095" >}}

{{% tab "python" %}}
```python
# """
# This is MountainArray's API interface.
# You should not implement it, or speculate about its implementation
# """
# class MountainArray:
#    def get(self, index: int) -> int:
#    def length(self) -> int:


class Solution:
    def findInMountainArray(self, target: int, mountain_arr: 'MountainArray') -> int:
        def search(l: int, r: int, k: int) -> int:
            while l < r:
                mid = (l + r) >> 1
                if k * mountain_arr.get(mid) >= k * target:
                    r = mid
                else:
                    l = mid + 1
            return -1 if mountain_arr.get(l) != target else l

        n = mountain_arr.length()
        l, r = 0, n - 1
        while l < r:
            mid = (l + r) >> 1
            if mountain_arr.get(mid) > mountain_arr.get(mid + 1):
                r = mid
            else:
                l = mid + 1
        ans = search(0, l, 1)
        return search(l + 1, n - 1, -1) if ans == -1 else ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
/**
 * // This is MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface MountainArray {
 *     public int get(int index) {}
 *     public int length() {}
 * }
 */

class Solution {
    private MountainArray mountainArr;
    private int target;

    public int findInMountainArray(int target, MountainArray mountainArr) {
        int n = mountainArr.length();
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) >>> 1;
            if (mountainArr.get(mid) > mountainArr.get(mid + 1)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        this.mountainArr = mountainArr;
        this.target = target;
        int ans = search(0, l, 1);
        return ans == -1 ? search(l + 1, n - 1, -1) : ans;
    }

    private int search(int l, int r, int k) {
        while (l < r) {
            int mid = (l + r) >>> 1;
            if (k * mountainArr.get(mid) >= k * target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return mountainArr.get(l) == target ? l : -1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray& mountainArr) {
        int n = mountainArr.length();
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (mountainArr.get(mid) > mountainArr.get(mid + 1)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        auto search = [&](int l, int r, int k) -> int {
            while (l < r) {
                int mid = (l + r) >> 1;
                if (k * mountainArr.get(mid) >= k * target) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            return mountainArr.get(l) == target ? l : -1;
        };
        int ans = search(0, l, 1);
        return ans == -1 ? search(l + 1, n - 1, -1) : ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * type MountainArray struct {
 * }
 *
 * func (this *MountainArray) get(index int) int {}
 * func (this *MountainArray) length() int {}
 */

func findInMountainArray(target int, mountainArr *MountainArray) int {
	n := mountainArr.length()
	l, r := 0, n-1
	for l < r {
		mid := (l + r) >> 1
		if mountainArr.get(mid) > mountainArr.get(mid+1) {
			r = mid
		} else {
			l = mid + 1
		}
	}
	search := func(l, r, k int) int {
		for l < r {
			mid := (l + r) >> 1
			if k*mountainArr.get(mid) >= k*target {
				r = mid
			} else {
				l = mid + 1
			}
		}
		if mountainArr.get(l) == target {
			return l
		}
		return -1
	}
	ans := search(0, l, 1)
	if ans == -1 {
		return search(l+1, n-1, -1)
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *      get(index: number): number {}
 *
 *      length(): number {}
 * }
 */

function findInMountainArray(target: number, mountainArr: MountainArray) {
    const n = mountainArr.length();
    let l = 0;
    let r = n - 1;
    while (l < r) {
        const mid = (l + r) >> 1;
        if (mountainArr.get(mid) > mountainArr.get(mid + 1)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    const search = (l: number, r: number, k: number): number => {
        while (l < r) {
            const mid = (l + r) >> 1;
            if (k * mountainArr.get(mid) >= k * target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return mountainArr.get(l) === target ? l : -1;
    };
    const ans = search(0, l, 1);
    return ans === -1 ? search(l + 1, n - 1, -1) : ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    #[allow(dead_code)]
    pub fn find_in_mountain_array(target: i32, mountain_arr: &MountainArray) -> i32 {
        let n = mountain_arr.length();

        // First find the maximum element in the array
        let mut l = 0;
        let mut r = n - 1;

        while l < r {
            let mid = (l + r) >> 1;
            if mountain_arr.get(mid) > mountain_arr.get(mid + 1) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        let left = Self::binary_search(mountain_arr, 0, l, 1, target);

        if left == -1 {
            Self::binary_search(mountain_arr, l, n - 1, -1, target)
        } else {
            left
        }
    }

    #[allow(dead_code)]
    fn binary_search(m: &MountainArray, mut l: i32, mut r: i32, k: i32, target: i32) -> i32 {
        let n = m.length();

        while l < r {
            let mid = (l + r) >> 1;
            if k * m.get(mid) >= k * target {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        if m.get(l) == target {
            l
        } else {
            -1
        }
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>（这是一个 <strong>交互式问题&nbsp;</strong>）</p>

<p>你可以将一个数组&nbsp;<code>arr</code>&nbsp;称为&nbsp;<strong>山脉数组&nbsp;</strong>当且仅当：</p>

<ul>
	<li><code>arr.length &gt;= 3</code></li>
	<li>存在一些&nbsp;<code>0 &lt; i &lt; arr.length - 1</code>&nbsp;的&nbsp;<code>i</code>&nbsp;使得：
	<ul>
		<li><code>arr[0] &lt; arr[1] &lt; ... &lt; arr[i - 1] &lt; arr[i]</code></li>
		<li><code>arr[i] &gt; arr[i + 1] &gt; ... &gt; arr[arr.length - 1]</code></li>
	</ul>
	</li>
</ul>

<p>给定一个山脉数组&nbsp;<code>mountainArr</code>&nbsp;，返回&nbsp;<strong>最小</strong> 的&nbsp;<code>index</code>&nbsp;使得&nbsp;<code>mountainArr.get(index) == target</code>。如果不存在这样的&nbsp;<code>index</code>，返回&nbsp;<code>-1</code>&nbsp;。</p>

<p><strong>你无法直接访问山脉数组</strong>。你只能使用&nbsp;<code>MountainArray</code>&nbsp;接口来访问数组：</p>

<ul>
	<li><code>MountainArray.get(k)</code>&nbsp;返回数组中下标为&nbsp;<code>k</code>&nbsp;的元素（从 0 开始）。</li>
	<li><code>MountainArray.length()</code>&nbsp;返回数组的长度。</li>
</ul>

<p>调用&nbsp;<code>MountainArray.get</code>&nbsp;超过&nbsp;<code>100</code>&nbsp;次的提交会被判定为错误答案。此外，任何试图绕过在线评测的解决方案都将导致取消资格。</p>

<ol>
</ol>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>mountainArr = [1,2,3,4,5,3,1], target = 3
<strong>输出：</strong>2
<strong>解释：</strong>3 在数组中出现了两次，下标分别为 2 和 5，我们返回最小的下标 2。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>mountainArr = [0,1,2,4,2,1], target = 3
<strong>输出：</strong>-1
<strong>解释：</strong>3 在数组中没有出现，返回 -1。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= mountainArr.length() &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= target &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= mountainArr.get(index) &lt;=&nbsp;10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二分查找

我们先通过二分查找，找到数组中的最大值所在的下标 $l$，那么数组就可以被分成两段，前半段是递增的，后半段是递减的。

然后我们在前半段中使用二分查找，查找目标值所在的下标，如果找不到，再在后半段中使用二分查找，查找目标值所在的下标。

时间复杂度 $O(\log n)$，其中 $n$ 是数组的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
# """
# This is MountainArray's API interface.
# You should not implement it, or speculate about its implementation
# """
# class MountainArray:
#    def get(self, index: int) -> int:
#    def length(self) -> int:


class Solution:
    def findInMountainArray(self, target: int, mountain_arr: 'MountainArray') -> int:
        def search(l: int, r: int, k: int) -> int:
            while l < r:
                mid = (l + r) >> 1
                if k * mountain_arr.get(mid) >= k * target:
                    r = mid
                else:
                    l = mid + 1
            return -1 if mountain_arr.get(l) != target else l

        n = mountain_arr.length()
        l, r = 0, n - 1
        while l < r:
            mid = (l + r) >> 1
            if mountain_arr.get(mid) > mountain_arr.get(mid + 1):
                r = mid
            else:
                l = mid + 1
        ans = search(0, l, 1)
        return search(l + 1, n - 1, -1) if ans == -1 else ans
```

#### Java

```java
/**
 * // This is MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface MountainArray {
 *     public int get(int index) {}
 *     public int length() {}
 * }
 */

class Solution {
    private MountainArray mountainArr;
    private int target;

    public int findInMountainArray(int target, MountainArray mountainArr) {
        int n = mountainArr.length();
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) >>> 1;
            if (mountainArr.get(mid) > mountainArr.get(mid + 1)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        this.mountainArr = mountainArr;
        this.target = target;
        int ans = search(0, l, 1);
        return ans == -1 ? search(l + 1, n - 1, -1) : ans;
    }

    private int search(int l, int r, int k) {
        while (l < r) {
            int mid = (l + r) >>> 1;
            if (k * mountainArr.get(mid) >= k * target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return mountainArr.get(l) == target ? l : -1;
    }
}
```

#### C++

```cpp
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray& mountainArr) {
        int n = mountainArr.length();
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (mountainArr.get(mid) > mountainArr.get(mid + 1)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        auto search = [&](int l, int r, int k) -> int {
            while (l < r) {
                int mid = (l + r) >> 1;
                if (k * mountainArr.get(mid) >= k * target) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            return mountainArr.get(l) == target ? l : -1;
        };
        int ans = search(0, l, 1);
        return ans == -1 ? search(l + 1, n - 1, -1) : ans;
    }
};
```

#### Go

```go
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * type MountainArray struct {
 * }
 *
 * func (this *MountainArray) get(index int) int {}
 * func (this *MountainArray) length() int {}
 */

func findInMountainArray(target int, mountainArr *MountainArray) int {
	n := mountainArr.length()
	l, r := 0, n-1
	for l < r {
		mid := (l + r) >> 1
		if mountainArr.get(mid) > mountainArr.get(mid+1) {
			r = mid
		} else {
			l = mid + 1
		}
	}
	search := func(l, r, k int) int {
		for l < r {
			mid := (l + r) >> 1
			if k*mountainArr.get(mid) >= k*target {
				r = mid
			} else {
				l = mid + 1
			}
		}
		if mountainArr.get(l) == target {
			return l
		}
		return -1
	}
	ans := search(0, l, 1)
	if ans == -1 {
		return search(l+1, n-1, -1)
	}
	return ans
}
```

#### TypeScript

```ts
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *      get(index: number): number {}
 *
 *      length(): number {}
 * }
 */

function findInMountainArray(target: number, mountainArr: MountainArray) {
    const n = mountainArr.length();
    let l = 0;
    let r = n - 1;
    while (l < r) {
        const mid = (l + r) >> 1;
        if (mountainArr.get(mid) > mountainArr.get(mid + 1)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    const search = (l: number, r: number, k: number): number => {
        while (l < r) {
            const mid = (l + r) >> 1;
            if (k * mountainArr.get(mid) >= k * target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return mountainArr.get(l) === target ? l : -1;
    };
    const ans = search(0, l, 1);
    return ans === -1 ? search(l + 1, n - 1, -1) : ans;
}
```

#### Rust

```rust
impl Solution {
    #[allow(dead_code)]
    pub fn find_in_mountain_array(target: i32, mountain_arr: &MountainArray) -> i32 {
        let n = mountain_arr.length();

        // First find the maximum element in the array
        let mut l = 0;
        let mut r = n - 1;

        while l < r {
            let mid = (l + r) >> 1;
            if mountain_arr.get(mid) > mountain_arr.get(mid + 1) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        let left = Self::binary_search(mountain_arr, 0, l, 1, target);

        if left == -1 {
            Self::binary_search(mountain_arr, l, n - 1, -1, target)
        } else {
            left
        }
    }

    #[allow(dead_code)]
    fn binary_search(m: &MountainArray, mut l: i32, mut r: i32, k: i32, target: i32) -> i32 {
        let n = m.length();

        while l < r {
            let mid = (l + r) >> 1;
            if k * m.get(mid) >= k * target {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        if m.get(l) == target {
            l
        } else {
            -1
        }
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1096. 花括号展开 II](https://leetcode.cn/problems/brace-expansion-ii){#1096}

{{< tabs "1096" >}}

{{% tab "python" %}}
```python
class Solution:
    def braceExpansionII(self, expression: str) -> List[str]:
        def dfs(exp):
            j = exp.find('}')
            if j == -1:
                s.add(exp)
                return
            i = exp.rfind('{', 0, j - 1)
            a, c = exp[:i], exp[j + 1 :]
            for b in exp[i + 1 : j].split(','):
                dfs(a + b + c)

        s = set()
        dfs(expression)
        return sorted(s)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private TreeSet<String> s = new TreeSet<>();

    public List<String> braceExpansionII(String expression) {
        dfs(expression);
        return new ArrayList<>(s);
    }

    private void dfs(String exp) {
        int j = exp.indexOf('}');
        if (j == -1) {
            s.add(exp);
            return;
        }
        int i = exp.lastIndexOf('{', j);
        String a = exp.substring(0, i);
        String c = exp.substring(j + 1);
        for (String b : exp.substring(i + 1, j).split(",")) {
            dfs(a + b + c);
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        dfs(expression);
        return vector<string>(s.begin(), s.end());
    }

private:
    set<string> s;

    void dfs(string exp) {
        int j = exp.find_first_of('}');
        if (j == string::npos) {
            s.insert(exp);
            return;
        }
        int i = exp.rfind('{', j);
        string a = exp.substr(0, i);
        string c = exp.substr(j + 1);
        stringstream ss(exp.substr(i + 1, j - i - 1));
        string b;
        while (getline(ss, b, ',')) {
            dfs(a + b + c);
        }
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func braceExpansionII(expression string) []string {
	s := map[string]struct{}{}
	var dfs func(string)
	dfs = func(exp string) {
		j := strings.Index(exp, "}")
		if j == -1 {
			s[exp] = struct{}{}
			return
		}
		i := strings.LastIndex(exp[:j], "{")
		a, c := exp[:i], exp[j+1:]
		for _, b := range strings.Split(exp[i+1:j], ",") {
			dfs(a + b + c)
		}
	}
	dfs(expression)
	ans := make([]string, 0, len(s))
	for k := range s {
		ans = append(ans, k)
	}
	sort.Strings(ans)
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function braceExpansionII(expression: string): string[] {
    const dfs = (exp: string) => {
        const j = exp.indexOf('}');
        if (j === -1) {
            s.add(exp);
            return;
        }
        const i = exp.lastIndexOf('{', j);
        const a = exp.substring(0, i);
        const c = exp.substring(j + 1);
        for (const b of exp.substring(i + 1, j).split(',')) {
            dfs(a + b + c);
        }
    };
    const s: Set<string> = new Set();
    dfs(expression);
    return Array.from(s).sort();
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>如果你熟悉 Shell 编程，那么一定了解过花括号展开，它可以用来生成任意字符串。</p>

<p>花括号展开的表达式可以看作一个由 <strong>花括号</strong>、<strong>逗号</strong> 和 <strong>小写英文字母</strong> 组成的字符串，定义下面几条语法规则：</p>

<ul>
	<li>如果只给出单一的元素&nbsp;<code>x</code>，那么表达式表示的字符串就只有&nbsp;<code>"x"</code>。<code>R(x) = {x}</code>

    <ul>
    	<li>例如，表达式 <code>"a"</code> 表示字符串 <code>"a"</code>。</li>
    	<li>而表达式 <code>"w"</code> 就表示字符串 <code>"w"</code>。</li>
    </ul>
    </li>
    <li>当两个或多个表达式并列，以逗号分隔，我们取这些表达式中元素的并集。<code>R({e_1,e_2,...}) = R(e_1)&nbsp;∪ R(e_2)&nbsp;∪ ...</code>
    <ul>
    	<li>例如，表达式 <code>"{a,b,c}"</code> 表示字符串&nbsp;<code>"a","b","c"</code>。</li>
    	<li>而表达式 <code>"{{a,b},{b,c}}"</code> 也可以表示字符串&nbsp;<code>"a","b","c"</code>。</li>
    </ul>
    </li>
    <li>要是两个或多个表达式相接，中间没有隔开时，我们从这些表达式中各取一个元素依次连接形成字符串。<code>R(e_1 + e_2) = {a + b for (a, b) in&nbsp;R(e_1)&nbsp;× R(e_2)}</code>
    <ul>
    	<li>例如，表达式 <code>"{a,b}{c,d}"</code> 表示字符串&nbsp;<code>"ac","ad","bc","bd"</code>。</li>
    </ul>
    </li>
    <li>表达式之间允许嵌套，单一元素与表达式的连接也是允许的。
    <ul>
    	<li>例如，表达式 <code>"a{b,c,d}"</code> 表示字符串&nbsp;<code>"ab","ac","ad"​​​​​​</code>。</li>
    	<li>例如，表达式 <code>"a{b,c}{d,e}f{g,h}"</code> 可以表示字符串&nbsp;<code>"abdfg", "abdfh", "abefg", "abefh", "acdfg", "acdfh", "acefg", "acefh"</code>。</li>
    </ul>
    </li>

</ul>

<p>给出表示基于给定语法规则的表达式&nbsp;<code>expression</code>，返回它所表示的所有字符串组成的有序列表。</p>

<p>假如你希望以「集合」的概念了解此题，也可以通过点击 “<strong>显示英文描述</strong>” 获取详情。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>expression = "{a,b}{c,{d,e}}"
<strong>输出：</strong>["ac","ad","ae","bc","bd","be"]</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>expression = "{{a,z},a{b,c},{ab,z}}"
<strong>输出：</strong>["a","ab","ac","z"]
<strong>解释：</strong>输出中 <strong>不应 </strong>出现重复的组合结果。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= expression.length &lt;= 60</code></li>
	<li><code>expression[i]</code> 由 <code>'{'</code>，<code>'}'</code>，<code>','</code>&nbsp;或小写英文字母组成</li>
	<li>给出的表达式&nbsp;<code>expression</code>&nbsp;用以表示一组基于题目描述中语法构造的字符串</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：递归

我们设计一个递归函数 $dfs(exp)$，用于处理表达式 $exp$，并将结果存入集合 $s$ 中。

对于表达式 $exp$，我们首先找到第一个右花括号的位置 $j$，如果找不到，说明 $exp$ 中没有右花括号，即 $exp$ 为单一元素，直接将 $exp$ 加入集合 $s$ 中即可。

否则，我们从位置 $j$ 开始往左找到第一个左花括号的位置 $i$，此时 $exp[:i]$ 和 $exp[j + 1:]$ 分别为 $exp$ 的前缀和后缀，记为 $a$ 和 $c$。而 $exp[i + 1: j]$ 为 $exp$ 中花括号内的部分，即 $exp$ 中的子表达式，我们将其按照逗号分割成多个字符串 $b_1, b_2, \cdots, b_k$，然后对每个 $b_i$，我们将 $a + b_i + c$ 拼接成新的表达式，递归调用 $dfs$ 函数处理新的表达式，即 $dfs(a + b_i + c)$。

最后，我们将集合 $s$ 中的元素按照字典序排序，即可得到答案。

时间复杂度约为 $O(n \times 2^{n / 4})$，其中 $n$ 为表达式 $expression$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def braceExpansionII(self, expression: str) -> List[str]:
        def dfs(exp):
            j = exp.find('}')
            if j == -1:
                s.add(exp)
                return
            i = exp.rfind('{', 0, j - 1)
            a, c = exp[:i], exp[j + 1 :]
            for b in exp[i + 1 : j].split(','):
                dfs(a + b + c)

        s = set()
        dfs(expression)
        return sorted(s)
```

#### Java

```java
class Solution {
    private TreeSet<String> s = new TreeSet<>();

    public List<String> braceExpansionII(String expression) {
        dfs(expression);
        return new ArrayList<>(s);
    }

    private void dfs(String exp) {
        int j = exp.indexOf('}');
        if (j == -1) {
            s.add(exp);
            return;
        }
        int i = exp.lastIndexOf('{', j);
        String a = exp.substring(0, i);
        String c = exp.substring(j + 1);
        for (String b : exp.substring(i + 1, j).split(",")) {
            dfs(a + b + c);
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        dfs(expression);
        return vector<string>(s.begin(), s.end());
    }

private:
    set<string> s;

    void dfs(string exp) {
        int j = exp.find_first_of('}');
        if (j == string::npos) {
            s.insert(exp);
            return;
        }
        int i = exp.rfind('{', j);
        string a = exp.substr(0, i);
        string c = exp.substr(j + 1);
        stringstream ss(exp.substr(i + 1, j - i - 1));
        string b;
        while (getline(ss, b, ',')) {
            dfs(a + b + c);
        }
    }
};
```

#### Go

```go
func braceExpansionII(expression string) []string {
	s := map[string]struct{}{}
	var dfs func(string)
	dfs = func(exp string) {
		j := strings.Index(exp, "}")
		if j == -1 {
			s[exp] = struct{}{}
			return
		}
		i := strings.LastIndex(exp[:j], "{")
		a, c := exp[:i], exp[j+1:]
		for _, b := range strings.Split(exp[i+1:j], ",") {
			dfs(a + b + c)
		}
	}
	dfs(expression)
	ans := make([]string, 0, len(s))
	for k := range s {
		ans = append(ans, k)
	}
	sort.Strings(ans)
	return ans
}
```

#### TypeScript

```ts
function braceExpansionII(expression: string): string[] {
    const dfs = (exp: string) => {
        const j = exp.indexOf('}');
        if (j === -1) {
            s.add(exp);
            return;
        }
        const i = exp.lastIndexOf('{', j);
        const a = exp.substring(0, i);
        const c = exp.substring(j + 1);
        for (const b of exp.substring(i + 1, j).split(',')) {
            dfs(a + b + c);
        }
    };
    const s: Set<string> = new Set();
    dfs(expression);
    return Array.from(s).sort();
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1097. 游戏玩法分析 V 🔒](https://leetcode.cn/problems/game-play-analysis-v){#1097}

{{< tabs "1097" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            player_id,
            event_date,
            MIN(event_date) OVER (PARTITION BY player_id) AS install_dt
        FROM Activity
    )
SELECT
    install_dt,
    COUNT(DISTINCT player_id) AS installs,
    ROUND(
        SUM(DATEDIFF(event_date, install_dt) = 1) / COUNT(DISTINCT player_id),
        2
    ) AS day1_retention
FROM T
GROUP BY 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code>Activity</code>&nbsp;</p>

<pre>
+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| player_id    | int     |
| device_id    | int     |
| event_date   | date    |
| games_played | int     |
+--------------+---------+
（player_id，event_date）是此表的主键(具有唯一值的列的组合)
这张表显示了某些游戏的玩家的活动情况
每一行表示一个玩家的记录，在某一天使用某个设备注销之前，登录并玩了很多游戏（可能是 0）
</pre>

<p>&nbsp;</p>

<p>玩家的 <strong>安装日期</strong> 定义为该玩家的第一个登录日。</p>

<p>我们将日期 x&nbsp;的 <strong>第一天留存率</strong> 定义为：假定安装日期为 <code>X</code>&nbsp;的玩家的数量为 <code>N</code> ，其中在 <code>X</code>&nbsp;之后的一天重新登录的玩家数量为 <code>M</code>，<code>M/N</code> 就是第一天留存率，<strong>四舍五入到小数点后两位</strong>。</p>

<p>编写解决方案，报告所有安装日期、当天安装游戏的玩家数量和玩家的&nbsp;<strong>第一天留存率</strong>。</p>

<p>以 <strong>任意顺序</strong> 返回结果表。</p>

<p>结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
Activity 表：
+-----------+-----------+------------+--------------+
| player_id | device_id | event_date | games_played |
+-----------+-----------+------------+--------------+
| 1         | 2         | 2016-03-01 | 5            |
| 1         | 2         | 2016-03-02 | 6            |
| 2         | 3         | 2017-06-25 | 1            |
| 3         | 1         | 2016-03-01 | 0            |
| 3         | 4         | 2016-07-03 | 5            |
+-----------+-----------+------------+--------------+
<strong>输出：</strong>
+------------+----------+----------------+
| install_dt | installs | Day1_retention |
+------------+----------+----------------+
| 2016-03-01 | 2        | 0.50           |
| 2017-06-25 | 1        | 0.00           |
+------------+----------+----------------+
<strong>解释：</strong>
玩家 1 和 3 在 2016-03-01 安装了游戏，但只有玩家 1 在 2016-03-02 重新登录，所以 2016-03-01 的第一天留存率是 1/2=0.50
玩家 2 在 2017-06-25 安装了游戏，但在 2017-06-26 没有重新登录，因此 2017-06-25 的第一天留存率为 0/1=0.00
</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            player_id,
            event_date,
            MIN(event_date) OVER (PARTITION BY player_id) AS install_dt
        FROM Activity
    )
SELECT
    install_dt,
    COUNT(DISTINCT player_id) AS installs,
    ROUND(
        SUM(DATEDIFF(event_date, install_dt) = 1) / COUNT(DISTINCT player_id),
        2
    ) AS day1_retention
FROM T
GROUP BY 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1098. 小众书籍 🔒](https://leetcode.cn/problems/unpopular-books){#1098}

{{< tabs "1098" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT book_id, name
FROM
    Books
    LEFT JOIN Orders USING (book_id)
WHERE available_from < '2019-05-23'
GROUP BY 1
HAVING SUM(IF(dispatch_date >= '2018-06-23', quantity, 0)) < 10;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>书籍表&nbsp;<code>Books</code>：</p>

<pre>
+----------------+---------+
| Column Name    | Type    |
+----------------+---------+
| book_id        | int     |
| name           | varchar |
| available_from | date    |
+----------------+---------+
book_id 是这个表的主键（具有唯一值的列）。
</pre>

<p>订单表&nbsp;<code>Orders</code>：</p>

<pre>
+----------------+---------+
| Column Name    | Type    |
+----------------+---------+
| order_id       | int     |
| book_id        | int     |
| quantity       | int     |
| dispatch_date  | date    |
+----------------+---------+
order_id 是这个表的主键（具有唯一值的列）。
book_id  是 Books 表的外键（reference 列）。
</pre>

<p>&nbsp;</p>

<p>编写解决方案，筛选出过去一年中订单总量&nbsp;<strong>少于 </strong><code>10</code><strong> 本&nbsp;</strong>的&nbsp;<strong>书籍</strong>，并且&nbsp;<strong>不考虑&nbsp;</strong>上架距今销售&nbsp;<strong>不满一个月</strong> 的书籍<strong>&nbsp;</strong>。<strong>假设今天是</strong>&nbsp;<code>2019-06-23</code>&nbsp;<strong>。</strong></p>

<p>返回结果表 <strong>无顺序要求</strong> 。</p>

<p>结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
Books 表：
+---------+--------------------+----------------+
| book_id | name               | available_from |
+---------+--------------------+----------------+
| 1       | "Kalila And Demna" | 2010-01-01     |
| 2       | "28 Letters"       | 2012-05-12     |
| 3       | "The Hobbit"       | 2019-06-10     |
| 4       | "13 Reasons Why"   | 2019-06-01     |
| 5       | "The Hunger Games" | 2008-09-21     |
+---------+--------------------+----------------+
Orders 表：
+----------+---------+----------+---------------+
| order_id | book_id | quantity | dispatch_date |
+----------+---------+----------+---------------+
| 1        | 1       | 2        | 2018-07-26    |
| 2        | 1       | 1        | 2018-11-05    |
| 3        | 3       | 8        | 2019-06-11    |
| 4        | 4       | 6        | 2019-06-05    |
| 5        | 4       | 5        | 2019-06-20    |
| 6        | 5       | 9        | 2009-02-02    |
| 7        | 5       | 8        | 2010-04-13    |
+----------+---------+----------+---------------+
<strong>输出：</strong>
+-----------+--------------------+
| book_id   | name               |
+-----------+--------------------+
| 1         | "Kalila And Demna" |
| 2         | "28 Letters"       |
| 5         | "The Hunger Games" |
+-----------+--------------------+
</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT book_id, name
FROM
    Books
    LEFT JOIN Orders USING (book_id)
WHERE available_from < '2019-05-23'
GROUP BY 1
HAVING SUM(IF(dispatch_date >= '2018-06-23', quantity, 0)) < 10;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1099. 小于 K 的两数之和 🔒](https://leetcode.cn/problems/two-sum-less-than-k){#1099}

{{< tabs "1099" >}}

{{% tab "python" %}}
```python
class Solution:
    def twoSumLessThanK(self, nums: List[int], k: int) -> int:
        nums.sort()
        i, j = 0, len(nums) - 1
        ans = -1
        while i < j:
            if (s := nums[i] + nums[j]) < k:
                ans = max(ans, s)
                i += 1
            else:
                j -= 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int twoSumLessThanK(int[] nums, int k) {
        Arrays.sort(nums);
        int ans = -1;
        for (int i = 0, j = nums.length - 1; i < j;) {
            int s = nums[i] + nums[j];
            if (s < k) {
                ans = Math.max(ans, s);
                ++i;
            } else {
                --j;
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
    int twoSumLessThanK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = -1;
        for (int i = 0, j = nums.size() - 1; i < j;) {
            int s = nums[i] + nums[j];
            if (s < k) {
                ans = max(ans, s);
                ++i;
            } else {
                --j;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func twoSumLessThanK(nums []int, k int) int {
	sort.Ints(nums)
	ans := -1
	for i, j := 0, len(nums)-1; i < j; {
		if s := nums[i] + nums[j]; s < k {
			ans = max(ans, s)
			i++
		} else {
			j--
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function twoSumLessThanK(nums: number[], k: number): number {
    nums.sort((a, b) => a - b);
    let ans = -1;
    for (let i = 0, j = nums.length - 1; i < j; ) {
        const s = nums[i] + nums[j];
        if (s < k) {
            ans = Math.max(ans, s);
            ++i;
        } else {
            --j;
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

<p>给你一个整数数组 <code>nums</code> 和整数 <code>k</code> ，返回最大和 <code>sum</code> ，满足存在 <code>i < j</code> 使得 <code>nums[i] + nums[j] = sum</code> 且 <code>sum < k</code> 。如果没有满足此等式的 <code>i,j</code> 存在，则返回 <code>-1</code> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [34,23,1,24,75,33,54,8], k = 60
<strong>输出：</strong>58
<strong>解释：</strong>
34 和 24 相加得到 58，58 小于 60，满足题意。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [10,20,30], k = 15
<strong>输出：</strong>-1
<strong>解释：</strong>
我们无法找到和小于 15 的两个元素。</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= nums.length <= 100</code></li>
	<li><code>1 <= nums[i] <= 1000</code></li>
	<li><code>1 <= k <= 2000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 二分查找

我们可以先对数组 $nums$ 进行排序，初始化答案为 $-1$。

接下来，我们枚举数组中的每个元素 $nums[i]$，并在数组中寻找满足 $nums[j] + nums[i] \lt k$ 的最大的 $nums[j]$。这里我们可以使用二分查找来加速寻找过程。如果找到了这样的 $nums[j]$，那么我们就可以更新答案，即 $ans = \max(ans, nums[i] + nums[j])$。

枚举结束后，返回答案即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 是数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def twoSumLessThanK(self, nums: List[int], k: int) -> int:
        nums.sort()
        ans = -1
        for i, x in enumerate(nums):
            j = bisect_left(nums, k - x, lo=i + 1) - 1
            if i < j:
                ans = max(ans, x + nums[j])
        return ans
```

#### Java

```java
class Solution {
    public int twoSumLessThanK(int[] nums, int k) {
        Arrays.sort(nums);
        int ans = -1;
        int n = nums.length;
        for (int i = 0; i < n; ++i) {
            int j = search(nums, k - nums[i], i + 1, n) - 1;
            if (i < j) {
                ans = Math.max(ans, nums[i] + nums[j]);
            }
        }
        return ans;
    }

    private int search(int[] nums, int x, int l, int r) {
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] >= x) {
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
    int twoSumLessThanK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = -1, n = nums.size();
        for (int i = 0; i < n; ++i) {
            int j = lower_bound(nums.begin() + i + 1, nums.end(), k - nums[i]) - nums.begin() - 1;
            if (i < j) {
                ans = max(ans, nums[i] + nums[j]);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func twoSumLessThanK(nums []int, k int) int {
	sort.Ints(nums)
	ans := -1
	for i, x := range nums {
		j := sort.SearchInts(nums[i+1:], k-x) + i
		if v := nums[i] + nums[j]; i < j && ans < v {
			ans = v
		}
	}
	return ans
}
```

#### TypeScript

```ts
function twoSumLessThanK(nums: number[], k: number): number {
    nums.sort((a, b) => a - b);
    let ans = -1;
    for (let i = 0, j = nums.length - 1; i < j; ) {
        const s = nums[i] + nums[j];
        if (s < k) {
            ans = Math.max(ans, s);
            ++i;
        } else {
            --j;
        }
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：排序 + 双指针

与方法一类似，我们可以先对数组 $nums$ 进行排序，初始化答案为 $-1$。

接下来，我们使用双指针 $i$ 和 $j$ 分别指向数组的左右两端，每次判断 $s = nums[i] + nums[j]$ 是否小于 $k$，如果小于 $k$，那么我们就可以更新答案，即 $ans = \max(ans, s)$，并将 $i$ 右移一位，否则将 $j$ 左移一位。

枚举结束后，返回答案即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 是数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def twoSumLessThanK(self, nums: List[int], k: int) -> int:
        nums.sort()
        i, j = 0, len(nums) - 1
        ans = -1
        while i < j:
            if (s := nums[i] + nums[j]) < k:
                ans = max(ans, s)
                i += 1
            else:
                j -= 1
        return ans
```

#### Java

```java
class Solution {
    public int twoSumLessThanK(int[] nums, int k) {
        Arrays.sort(nums);
        int ans = -1;
        for (int i = 0, j = nums.length - 1; i < j;) {
            int s = nums[i] + nums[j];
            if (s < k) {
                ans = Math.max(ans, s);
                ++i;
            } else {
                --j;
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
    int twoSumLessThanK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = -1;
        for (int i = 0, j = nums.size() - 1; i < j;) {
            int s = nums[i] + nums[j];
            if (s < k) {
                ans = max(ans, s);
                ++i;
            } else {
                --j;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func twoSumLessThanK(nums []int, k int) int {
	sort.Ints(nums)
	ans := -1
	for i, j := 0, len(nums)-1; i < j; {
		if s := nums[i] + nums[j]; s < k {
			ans = max(ans, s)
			i++
		} else {
			j--
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
