---
title: "1030_距离顺序排列矩阵单元格"
date: 2025-10-08T18:36:50+08:00
weight: 4
tags: [二叉搜索树, 二叉树, 几何, 动态规划, 哈希表, 字典树, 字符串, 广度优先搜索, 排序, 数学, 数据流, 数组, 树, 深度优先搜索, 滑动窗口, 矩阵, 脑筋急转弯, 设计]
---

{{< markmap >}}
### [1030_距离顺序排列矩阵单元格](#1030)
#### [几何](#1030)
#### [数组](#1030)
#### [数学](#1030)
#### [矩阵](#1030)
#### [排序](#1030)
### [1031_两个非重叠子数组的最大和](#1031)
#### [数组](#1031)
#### [动态规划](#1031)
#### [滑动窗口](#1031)
### [1032_字符流](#1032)
#### [设计](#1032)
#### [字典树](#1032)
#### [数组](#1032)
#### [字符串](#1032)
#### [数据流](#1032)
### [1033_移动石子直到连续](#1033)
#### [脑筋急转弯](#1033)
#### [数学](#1033)
### [1034_边界着色](#1034)
#### [深度优先搜索](#1034)
#### [广度优先搜索](#1034)
#### [数组](#1034)
#### [矩阵](#1034)
### [1035_不相交的线](#1035)
#### [数组](#1035)
#### [动态规划](#1035)
### [1036_逃离大迷宫](#1036)
#### [深度优先搜索](#1036)
#### [广度优先搜索](#1036)
#### [数组](#1036)
#### [哈希表](#1036)
### [1037_有效的回旋镖](#1037)
#### [几何](#1037)
#### [数组](#1037)
#### [数学](#1037)
### [1038_从二叉搜索树到更大和树](#1038)
#### [树](#1038)
#### [深度优先搜索](#1038)
#### [二叉搜索树](#1038)
#### [二叉树](#1038)
### [1039_多边形三角剖分的最低得分](#1039)
#### [数组](#1039)
#### [动态规划](#1039)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1030_距离顺序排列矩阵单元格
___
#### 几何
___
#### 数组
___
#### 数学
___
#### 矩阵
___
#### 排序
---
### 1031_两个非重叠子数组的最大和
___
#### 数组
___
#### 动态规划
___
#### 滑动窗口
---
### 1032_字符流
___
#### 设计
___
#### 字典树
___
#### 数组
___
#### 字符串
___
#### 数据流
---
### 1033_移动石子直到连续
___
#### 脑筋急转弯
___
#### 数学
---
### 1034_边界着色
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 数组
___
#### 矩阵
---
### 1035_不相交的线
___
#### 数组
___
#### 动态规划
---
### 1036_逃离大迷宫
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 数组
___
#### 哈希表
---
### 1037_有效的回旋镖
___
#### 几何
___
#### 数组
___
#### 数学
---
### 1038_从二叉搜索树到更大和树
___
#### 树
___
#### 深度优先搜索
___
#### 二叉搜索树
___
#### 二叉树
---
### 1039_多边形三角剖分的最低得分
___
#### 数组
___
#### 动态规划
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二叉搜索树 | 二叉树 | 几何 |
| 动态规划 | 哈希表 | 字典树 |
| 字符串 | 广度优先搜索 | 排序 |
| 数学 | 数据流 | 数组 |
| 树 | 深度优先搜索 | 滑动窗口 |
| 矩阵 | 脑筋急转弯 | 设计 |

# [1030. 距离顺序排列矩阵单元格](https://leetcode.cn/problems/matrix-cells-in-distance-order){#1030}

{{< tabs "1030" >}}

{{% tab "python" %}}
```python
class Solution:
    def allCellsDistOrder(
        self, rows: int, cols: int, rCenter: int, cCenter: int
    ) -> List[List[int]]:
        q = deque([[rCenter, cCenter]])
        vis = [[False] * cols for _ in range(rows)]
        vis[rCenter][cCenter] = True
        ans = []
        while q:
            for _ in range(len(q)):
                p = q.popleft()
                ans.append(p)
                for a, b in pairwise((-1, 0, 1, 0, -1)):
                    x, y = p[0] + a, p[1] + b
                    if 0 <= x < rows and 0 <= y < cols and not vis[x][y]:
                        vis[x][y] = True
                        q.append([x, y])
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[][] allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        Deque<int[]> q = new ArrayDeque<>();
        q.offer(new int[] {rCenter, cCenter});
        boolean[][] vis = new boolean[rows][cols];
        vis[rCenter][cCenter] = true;
        int[][] ans = new int[rows * cols][2];
        int[] dirs = {-1, 0, 1, 0, -1};
        int idx = 0;
        while (!q.isEmpty()) {
            for (int n = q.size(); n > 0; --n) {
                var p = q.poll();
                ans[idx++] = p;
                for (int k = 0; k < 4; ++k) {
                    int x = p[0] + dirs[k], y = p[1] + dirs[k + 1];
                    if (x >= 0 && x < rows && y >= 0 && y < cols && !vis[x][y]) {
                        vis[x][y] = true;
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
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        queue<pair<int, int>> q;
        q.emplace(rCenter, cCenter);
        vector<vector<int>> ans;
        bool vis[rows][cols];
        memset(vis, false, sizeof(vis));
        vis[rCenter][cCenter] = true;
        int dirs[5] = {-1, 0, 1, 0, -1};
        while (!q.empty()) {
            for (int n = q.size(); n; --n) {
                auto [i, j] = q.front();
                q.pop();
                ans.push_back({i, j});
                for (int k = 0; k < 4; ++k) {
                    int x = i + dirs[k];
                    int y = j + dirs[k + 1];
                    if (x >= 0 && x < rows && y >= 0 && y < cols && !vis[x][y]) {
                        vis[x][y] = true;
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
func allCellsDistOrder(rows int, cols int, rCenter int, cCenter int) (ans [][]int) {
	q := [][]int{{rCenter, cCenter}}
	vis := make([][]bool, rows)
	for i := range vis {
		vis[i] = make([]bool, cols)
	}
	vis[rCenter][cCenter] = true
	dirs := [5]int{-1, 0, 1, 0, -1}
	for len(q) > 0 {
		for n := len(q); n > 0; n-- {
			p := q[0]
			q = q[1:]
			ans = append(ans, p)
			for k := 0; k < 4; k++ {
				x, y := p[0]+dirs[k], p[1]+dirs[k+1]
				if x >= 0 && x < rows && y >= 0 && y < cols && !vis[x][y] {
					vis[x][y] = true
					q = append(q, []int{x, y})
				}
			}
		}
	}
	return
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定四个整数 <code>rows</code>&nbsp;,&nbsp; &nbsp;<code>cols</code> ,&nbsp; <code>rCenter</code> 和 <code>cCenter</code> 。有一个&nbsp;<code>rows x cols</code>&nbsp;的矩阵，你在单元格上的坐标是&nbsp;<code>(rCenter, cCenter)</code> 。</p>

<p>返回矩阵中的所有单元格的坐标，并按与<em>&nbsp;</em><code>(rCenter, cCenter)</code><em>&nbsp;</em>的 <strong>距离</strong> 从最小到最大的顺序排。你可以按 <strong>任何</strong> 满足此条件的顺序返回答案。</p>

<p>单元格<code>(r1, c1)</code> 和 <code>(r2, c2)</code> 之间的距离为<code>|r1 - r2| + |c1 - c2|</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>rows = 1, cols = 2, rCenter = 0, cCenter = 0
<strong>输出：</strong>[[0,0],[0,1]]
<strong>解释</strong>：从 (r0, c0) 到其他单元格的距离为：[0,1]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>rows = 2, cols = 2, rCenter = 0, cCenter = 1
<strong>输出：</strong>[[0,1],[0,0],[1,1],[1,0]]
<strong>解释</strong>：从 (r0, c0) 到其他单元格的距离为：[0,1,1,2]
[[0,1],[1,1],[0,0],[1,0]] 也会被视作正确答案。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>rows = 2, cols = 3, rCenter = 1, cCenter = 2
<strong>输出：</strong>[[1,2],[0,2],[1,1],[0,1],[1,0],[0,0]]
<strong>解释</strong>：从 (r0, c0) 到其他单元格的距离为：[0,1,1,2,2,3]
其他满足题目要求的答案也会被视为正确，例如 [[1,2],[1,1],[0,2],[1,0],[0,1],[0,0]]。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= rows, cols &lt;= 100</code></li>
	<li><code>0 &lt;= rCenter &lt; rows</code></li>
	<li><code>0 &lt;= cCenter &lt; cols</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：BFS

我们定义一个队列 $q$，初始时将坐标点 $(rCenter, cCenter)$ 入队，用一个二维布尔数组 $vis$ 记录已经访问过的点，初始时 $vis[rCenter][cCenter]$ 为 $true$。

接下来，我们不断地从队列中取出一个点，将其加入答案数组，然后将其上下左右四个相邻点加入队列，注意要判断这些点是否已经访问过，如果没有访问过，就将其标记为已访问，并将其加入队列。一直重复这个过程，直到队列为空，此时答案数组中的点就是按照距离从小到大的顺序排列的。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别是矩阵的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def allCellsDistOrder(
        self, rows: int, cols: int, rCenter: int, cCenter: int
    ) -> List[List[int]]:
        q = deque([[rCenter, cCenter]])
        vis = [[False] * cols for _ in range(rows)]
        vis[rCenter][cCenter] = True
        ans = []
        while q:
            for _ in range(len(q)):
                p = q.popleft()
                ans.append(p)
                for a, b in pairwise((-1, 0, 1, 0, -1)):
                    x, y = p[0] + a, p[1] + b
                    if 0 <= x < rows and 0 <= y < cols and not vis[x][y]:
                        vis[x][y] = True
                        q.append([x, y])
        return ans
```

#### Java

```java
class Solution {
    public int[][] allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        Deque<int[]> q = new ArrayDeque<>();
        q.offer(new int[] {rCenter, cCenter});
        boolean[][] vis = new boolean[rows][cols];
        vis[rCenter][cCenter] = true;
        int[][] ans = new int[rows * cols][2];
        int[] dirs = {-1, 0, 1, 0, -1};
        int idx = 0;
        while (!q.isEmpty()) {
            for (int n = q.size(); n > 0; --n) {
                var p = q.poll();
                ans[idx++] = p;
                for (int k = 0; k < 4; ++k) {
                    int x = p[0] + dirs[k], y = p[1] + dirs[k + 1];
                    if (x >= 0 && x < rows && y >= 0 && y < cols && !vis[x][y]) {
                        vis[x][y] = true;
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
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        queue<pair<int, int>> q;
        q.emplace(rCenter, cCenter);
        vector<vector<int>> ans;
        bool vis[rows][cols];
        memset(vis, false, sizeof(vis));
        vis[rCenter][cCenter] = true;
        int dirs[5] = {-1, 0, 1, 0, -1};
        while (!q.empty()) {
            for (int n = q.size(); n; --n) {
                auto [i, j] = q.front();
                q.pop();
                ans.push_back({i, j});
                for (int k = 0; k < 4; ++k) {
                    int x = i + dirs[k];
                    int y = j + dirs[k + 1];
                    if (x >= 0 && x < rows && y >= 0 && y < cols && !vis[x][y]) {
                        vis[x][y] = true;
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
func allCellsDistOrder(rows int, cols int, rCenter int, cCenter int) (ans [][]int) {
	q := [][]int{{rCenter, cCenter}}
	vis := make([][]bool, rows)
	for i := range vis {
		vis[i] = make([]bool, cols)
	}
	vis[rCenter][cCenter] = true
	dirs := [5]int{-1, 0, 1, 0, -1}
	for len(q) > 0 {
		for n := len(q); n > 0; n-- {
			p := q[0]
			q = q[1:]
			ans = append(ans, p)
			for k := 0; k < 4; k++ {
				x, y := p[0]+dirs[k], p[1]+dirs[k+1]
				if x >= 0 && x < rows && y >= 0 && y < cols && !vis[x][y] {
					vis[x][y] = true
					q = append(q, []int{x, y})
				}
			}
		}
	}
	return
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1031. 两个非重叠子数组的最大和](https://leetcode.cn/problems/maximum-sum-of-two-non-overlapping-subarrays){#1031}

{{< tabs "1031" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxSumTwoNoOverlap(self, nums: List[int], firstLen: int, secondLen: int) -> int:
        n = len(nums)
        s = list(accumulate(nums, initial=0))
        ans = t = 0
        i = firstLen
        while i + secondLen - 1 < n:
            t = max(t, s[i] - s[i - firstLen])
            ans = max(ans, t + s[i + secondLen] - s[i])
            i += 1
        t = 0
        i = secondLen
        while i + firstLen - 1 < n:
            t = max(t, s[i] - s[i - secondLen])
            ans = max(ans, t + s[i + firstLen] - s[i])
            i += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxSumTwoNoOverlap(int[] nums, int firstLen, int secondLen) {
        int n = nums.length;
        int[] s = new int[n + 1];
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + nums[i];
        }
        int ans = 0;
        for (int i = firstLen, t = 0; i + secondLen - 1 < n; ++i) {
            t = Math.max(t, s[i] - s[i - firstLen]);
            ans = Math.max(ans, t + s[i + secondLen] - s[i]);
        }
        for (int i = secondLen, t = 0; i + firstLen - 1 < n; ++i) {
            t = Math.max(t, s[i] - s[i - secondLen]);
            ans = Math.max(ans, t + s[i + firstLen] - s[i]);
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
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();
        vector<int> s(n + 1);
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + nums[i];
        }
        int ans = 0;
        for (int i = firstLen, t = 0; i + secondLen - 1 < n; ++i) {
            t = max(t, s[i] - s[i - firstLen]);
            ans = max(ans, t + s[i + secondLen] - s[i]);
        }
        for (int i = secondLen, t = 0; i + firstLen - 1 < n; ++i) {
            t = max(t, s[i] - s[i - secondLen]);
            ans = max(ans, t + s[i + firstLen] - s[i]);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxSumTwoNoOverlap(nums []int, firstLen int, secondLen int) (ans int) {
	n := len(nums)
	s := make([]int, n+1)
	for i, x := range nums {
		s[i+1] = s[i] + x
	}
	for i, t := firstLen, 0; i+secondLen-1 < n; i++ {
		t = max(t, s[i]-s[i-firstLen])
		ans = max(ans, t+s[i+secondLen]-s[i])
	}
	for i, t := secondLen, 0; i+firstLen-1 < n; i++ {
		t = max(t, s[i]-s[i-secondLen])
		ans = max(ans, t+s[i+firstLen]-s[i])
	}
	return
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>nums</code> 和两个整数 <code>firstLen</code> 和 <code>secondLen</code>，请你找出并返回两个非重叠<strong> 子数组 </strong>中元素的最大和<em>，</em>长度分别为 <code>firstLen</code> 和 <code>secondLen</code> 。</p>

<p>长度为 <code>firstLen</code> 的子数组可以出现在长为 <code>secondLen</code> 的子数组之前或之后，但二者必须是不重叠的。</p>

<p>子数组是数组的一个 <strong>连续</strong> 部分。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [0,6,5,2,2,5,1,9,4], firstLen = 1, secondLen = 2
<strong>输出：</strong>20
<strong>解释：</strong>子数组的一种选择中，[9] 长度为 1，[6,5] 长度为 2。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [3,8,1,3,2,1,8,9,0], firstLen = 3, secondLen = 2
<strong>输出：</strong>29
<strong>解释：</strong>子数组的一种选择中，[3,8,1] 长度为 3，[8,9] 长度为 2。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,1,5,6,0,9,5,0,3,8], firstLen = 4, secondLen = 3
<strong>输出：</strong>31
<strong>解释：</strong>子数组的一种选择中，[5,6,0,9] 长度为 4，[0,3,8] 长度为 3。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= firstLen, secondLen &lt;= 1000</code></li>
	<li><code>2 &lt;= firstLen + secondLen &lt;= 1000</code></li>
	<li><code>firstLen + secondLen &lt;= nums.length &lt;= 1000</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前缀和 + 枚举

我们先预处理得到数组 `nums` 的前缀和数组 $s$，其中 $s[i]$ 表示 $nums$ 中前 $i$ 个元素的和。

接下来，我们分两种情况枚举：

假设 $firstLen$ 个元素的子数组在 $secondLen$ 个元素的子数组的左边，那么我们可以枚举 $secondLen$ 个元素的子数组的左端点 $i$，用变量 $t$ 维护左边 $firstLen$ 个元素的子数组的最大和，那么答案就是 $t + s[i + secondLen] - s[i]$。枚举完所有的 $i$，就可以得到候选答案。

假设 $secondLen$ 个元素的子数组在 $firstLen$ 个元素的子数组的左边，那么我们可以枚举 $firstLen$ 个元素的子数组的左端点 $i$，用变量 $t$ 维护左边 $secondLen$ 个元素的子数组的最大和，那么答案就是 $t + s[i + firstLen] - s[i]$。枚举完所有的 $i$，就可以得到候选答案。

最后，我们取两种情况下的候选答案的最大值即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 `nums` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxSumTwoNoOverlap(self, nums: List[int], firstLen: int, secondLen: int) -> int:
        n = len(nums)
        s = list(accumulate(nums, initial=0))
        ans = t = 0
        i = firstLen
        while i + secondLen - 1 < n:
            t = max(t, s[i] - s[i - firstLen])
            ans = max(ans, t + s[i + secondLen] - s[i])
            i += 1
        t = 0
        i = secondLen
        while i + firstLen - 1 < n:
            t = max(t, s[i] - s[i - secondLen])
            ans = max(ans, t + s[i + firstLen] - s[i])
            i += 1
        return ans
```

#### Java

```java
class Solution {
    public int maxSumTwoNoOverlap(int[] nums, int firstLen, int secondLen) {
        int n = nums.length;
        int[] s = new int[n + 1];
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + nums[i];
        }
        int ans = 0;
        for (int i = firstLen, t = 0; i + secondLen - 1 < n; ++i) {
            t = Math.max(t, s[i] - s[i - firstLen]);
            ans = Math.max(ans, t + s[i + secondLen] - s[i]);
        }
        for (int i = secondLen, t = 0; i + firstLen - 1 < n; ++i) {
            t = Math.max(t, s[i] - s[i - secondLen]);
            ans = Math.max(ans, t + s[i + firstLen] - s[i]);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();
        vector<int> s(n + 1);
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + nums[i];
        }
        int ans = 0;
        for (int i = firstLen, t = 0; i + secondLen - 1 < n; ++i) {
            t = max(t, s[i] - s[i - firstLen]);
            ans = max(ans, t + s[i + secondLen] - s[i]);
        }
        for (int i = secondLen, t = 0; i + firstLen - 1 < n; ++i) {
            t = max(t, s[i] - s[i - secondLen]);
            ans = max(ans, t + s[i + firstLen] - s[i]);
        }
        return ans;
    }
};
```

#### Go

```go
func maxSumTwoNoOverlap(nums []int, firstLen int, secondLen int) (ans int) {
	n := len(nums)
	s := make([]int, n+1)
	for i, x := range nums {
		s[i+1] = s[i] + x
	}
	for i, t := firstLen, 0; i+secondLen-1 < n; i++ {
		t = max(t, s[i]-s[i-firstLen])
		ans = max(ans, t+s[i+secondLen]-s[i])
	}
	for i, t := secondLen, 0; i+firstLen-1 < n; i++ {
		t = max(t, s[i]-s[i-secondLen])
		ans = max(ans, t+s[i+firstLen]-s[i])
	}
	return
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1032. 字符流](https://leetcode.cn/problems/stream-of-characters){#1032}

{{< tabs "1032" >}}

{{% tab "python" %}}
```python
class Trie:
    def __init__(self):
        self.children = [None] * 26
        self.is_end = False

    def insert(self, w: str):
        node = self
        for c in w[::-1]:
            idx = ord(c) - ord('a')
            if node.children[idx] is None:
                node.children[idx] = Trie()
            node = node.children[idx]
        node.is_end = True

    def search(self, w: List[str]) -> bool:
        node = self
        for c in w[::-1]:
            idx = ord(c) - ord('a')
            if node.children[idx] is None:
                return False
            node = node.children[idx]
            if node.is_end:
                return True
        return False


class StreamChecker:
    def __init__(self, words: List[str]):
        self.trie = Trie()
        self.cs = []
        self.limit = 201
        for w in words:
            self.trie.insert(w)

    def query(self, letter: str) -> bool:
        self.cs.append(letter)
        return self.trie.search(self.cs[-self.limit :])


# Your StreamChecker object will be instantiated and called as such:
# obj = StreamChecker(words)
# param_1 = obj.query(letter)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Trie {
    Trie[] children = new Trie[26];
    boolean isEnd = false;

    public void insert(String w) {
        Trie node = this;
        for (int i = w.length() - 1; i >= 0; --i) {
            int idx = w.charAt(i) - 'a';
            if (node.children[idx] == null) {
                node.children[idx] = new Trie();
            }
            node = node.children[idx];
        }
        node.isEnd = true;
    }

    public boolean query(StringBuilder s) {
        Trie node = this;
        for (int i = s.length() - 1; i >= 0; --i) {
            int idx = s.charAt(i) - 'a';
            if (node.children[idx] == null) {
                return false;
            }
            node = node.children[idx];
            if (node.isEnd) {
                return true;
            }
        }
        return false;
    }
}

class StreamChecker {
    private StringBuilder sb = new StringBuilder();
    private Trie trie = new Trie();

    public StreamChecker(String[] words) {
        for (String w : words) {
            trie.insert(w);
        }
    }

    public boolean query(char letter) {
        sb.append(letter);
        return trie.query(sb);
    }
}

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker obj = new StreamChecker(words);
 * boolean param_1 = obj.query(letter);
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Trie {
private:
    Trie* children[26]{};
    bool isEnd = false;

public:
    void insert(string& w) {
        Trie* node = this;
        reverse(w.begin(), w.end());
        for (char& c : w) {
            int idx = c - 'a';
            if (!node->children[idx]) {
                node->children[idx] = new Trie();
            }
            node = node->children[idx];
        }
        node->isEnd = true;
    }

    bool search(string& w) {
        Trie* node = this;
        for (int i = w.size() - 1, j = 0; ~i && j < 201; --i, ++j) {
            int idx = w[i] - 'a';
            if (!node->children[idx]) {
                return false;
            }
            node = node->children[idx];
            if (node->isEnd) {
                return true;
            }
        }
        return false;
    }
};

class StreamChecker {
public:
    Trie* trie = new Trie();
    string s;

    StreamChecker(vector<string>& words) {
        for (auto& w : words) {
            trie->insert(w);
        }
    }

    bool query(char letter) {
        s += letter;
        return trie->search(s);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type Trie struct {
	children [26]*Trie
	isEnd    bool
}

func newTrie() Trie {
	return Trie{}
}

func (this *Trie) Insert(word string) {
	node := this
	for i := len(word) - 1; i >= 0; i-- {
		idx := word[i] - 'a'
		if node.children[idx] == nil {
			node.children[idx] = &Trie{}
		}
		node = node.children[idx]
	}
	node.isEnd = true
}

func (this *Trie) Search(word []byte) bool {
	node := this
	for i := len(word) - 1; i >= 0; i-- {
		idx := word[i] - 'a'
		if node.children[idx] == nil {
			return false
		}
		node = node.children[idx]
		if node.isEnd {
			return true
		}
	}
	return false
}

type StreamChecker struct {
	trie Trie
	s    []byte
}

func Constructor(words []string) StreamChecker {
	trie := newTrie()
	for _, w := range words {
		trie.Insert(w)
	}
	return StreamChecker{trie, []byte{}}
}

func (this *StreamChecker) Query(letter byte) bool {
	this.s = append(this.s, letter)
	return this.trie.Search(this.s)
}

/**
 * Your StreamChecker object will be instantiated and called as such:
 * obj := Constructor(words);
 * param_1 := obj.Query(letter);
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>设计一个算法：接收一个字符流，并检查这些字符的后缀是否是字符串数组 <code>words</code> 中的一个字符串。</p>

<p>例如，<code>words = ["abc", "xyz"]</code> 且字符流中逐个依次加入 4 个字符 <code>'a'</code>、<code>'x'</code>、<code>'y'</code> 和 <code>'z'</code> ，你所设计的算法应当可以检测到&nbsp;<code>"axyz"</code> 的后缀 <code>"xyz"</code> 与&nbsp;<code>words</code> 中的字符串 <code>"xyz"</code> 匹配。</p>

<p>按下述要求实现 <code>StreamChecker</code> 类：</p>

<ul>
	<li><code>StreamChecker(String[] words)</code> ：构造函数，用字符串数组&nbsp;<code>words</code> 初始化数据结构。</li>
	<li><code>boolean query(char letter)</code>：从字符流中接收一个新字符，如果字符流中的任一非空后缀能匹配 <code>words</code> 中的某一字符串，返回 <code>true</code> ；否则，返回 <code>false</code>。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre>
<strong>输入：</strong>
["StreamChecker", "query", "query", "query", "query", "query", "query", "query", "query", "query", "query", "query", "query"]
[[["cd", "f", "kl"]], ["a"], ["b"], ["c"], ["d"], ["e"], ["f"], ["g"], ["h"], ["i"], ["j"], ["k"], ["l"]]
<strong>输出：</strong>
[null, false, false, false, true, false, true, false, false, false, false, false, true]

<strong>解释：</strong>
StreamChecker streamChecker = new StreamChecker(["cd", "f", "kl"]);
streamChecker.query("a"); // 返回 False
streamChecker.query("b"); // 返回 False
streamChecker.query("c"); // 返回n False
streamChecker.query("d"); // 返回 True ，因为 'cd' 在 words 中
streamChecker.query("e"); // 返回 False
streamChecker.query("f"); // 返回 True ，因为 'f' 在 words 中
streamChecker.query("g"); // 返回 False
streamChecker.query("h"); // 返回 False
streamChecker.query("i"); // 返回 False
streamChecker.query("j"); // 返回 False
streamChecker.query("k"); // 返回 False
streamChecker.query("l"); // 返回 True ，因为 'kl' 在 words 中
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 2000</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 200</code></li>
	<li><code>words[i]</code> 由小写英文字母组成</li>
	<li><code>letter</code> 是一个小写英文字母</li>
	<li>最多调用查询 <code>4 * 10<sup>4</sup></code> 次</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前缀树

我们可以根据初始化时的字符串数组 $words$ 构建前缀树，前缀树的每个节点包含两个属性：

-   `children`：指向 $26$ 个字母的指针数组，用于存储当前节点的子节点。
-   `is_end`：标记当前节点是否为某个字符串的结尾。

在构造函数中，我们遍历字符串数组 $words$，对于每个字符串 $w$，我们将其反转后，逐个字符插入到前缀树中，插入结束后，将当前节点的 `is_end` 标记为 `true`。

在 `query` 函数中，我们将当前字符 $c$ 加入到字符流中，然后从后往前遍历字符流，对于每个字符 $c$，我们在前缀树中查找是否存在以 $c$ 为结尾的字符串，如果存在，返回 `true`，否则返回 `false`。注意到 $words$ 中的字符串长度不超过 $200$，因此查询时最多只需要遍历 $200$ 个字符。

时间复杂度方面，构造函数的时间复杂度为 $O(L)$，而 `query` 函数的时间复杂度为 $O(M)$。其中 $L$ 为字符串数组 $words$ 中所有字符串的长度之和，而 $M$ 为字符串数组 $words$ 中字符串的最大长度。空间复杂度 $O(L)$。

<!-- tabs:start -->

#### Python3

```python
class Trie:
    def __init__(self):
        self.children = [None] * 26
        self.is_end = False

    def insert(self, w: str):
        node = self
        for c in w[::-1]:
            idx = ord(c) - ord('a')
            if node.children[idx] is None:
                node.children[idx] = Trie()
            node = node.children[idx]
        node.is_end = True

    def search(self, w: List[str]) -> bool:
        node = self
        for c in w[::-1]:
            idx = ord(c) - ord('a')
            if node.children[idx] is None:
                return False
            node = node.children[idx]
            if node.is_end:
                return True
        return False


class StreamChecker:
    def __init__(self, words: List[str]):
        self.trie = Trie()
        self.cs = []
        self.limit = 201
        for w in words:
            self.trie.insert(w)

    def query(self, letter: str) -> bool:
        self.cs.append(letter)
        return self.trie.search(self.cs[-self.limit :])


# Your StreamChecker object will be instantiated and called as such:
# obj = StreamChecker(words)
# param_1 = obj.query(letter)
```

#### Java

```java
class Trie {
    Trie[] children = new Trie[26];
    boolean isEnd = false;

    public void insert(String w) {
        Trie node = this;
        for (int i = w.length() - 1; i >= 0; --i) {
            int idx = w.charAt(i) - 'a';
            if (node.children[idx] == null) {
                node.children[idx] = new Trie();
            }
            node = node.children[idx];
        }
        node.isEnd = true;
    }

    public boolean query(StringBuilder s) {
        Trie node = this;
        for (int i = s.length() - 1; i >= 0; --i) {
            int idx = s.charAt(i) - 'a';
            if (node.children[idx] == null) {
                return false;
            }
            node = node.children[idx];
            if (node.isEnd) {
                return true;
            }
        }
        return false;
    }
}

class StreamChecker {
    private StringBuilder sb = new StringBuilder();
    private Trie trie = new Trie();

    public StreamChecker(String[] words) {
        for (String w : words) {
            trie.insert(w);
        }
    }

    public boolean query(char letter) {
        sb.append(letter);
        return trie.query(sb);
    }
}

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker obj = new StreamChecker(words);
 * boolean param_1 = obj.query(letter);
 */
```

#### C++

```cpp
class Trie {
private:
    Trie* children[26]{};
    bool isEnd = false;

public:
    void insert(string& w) {
        Trie* node = this;
        reverse(w.begin(), w.end());
        for (char& c : w) {
            int idx = c - 'a';
            if (!node->children[idx]) {
                node->children[idx] = new Trie();
            }
            node = node->children[idx];
        }
        node->isEnd = true;
    }

    bool search(string& w) {
        Trie* node = this;
        for (int i = w.size() - 1, j = 0; ~i && j < 201; --i, ++j) {
            int idx = w[i] - 'a';
            if (!node->children[idx]) {
                return false;
            }
            node = node->children[idx];
            if (node->isEnd) {
                return true;
            }
        }
        return false;
    }
};

class StreamChecker {
public:
    Trie* trie = new Trie();
    string s;

    StreamChecker(vector<string>& words) {
        for (auto& w : words) {
            trie->insert(w);
        }
    }

    bool query(char letter) {
        s += letter;
        return trie->search(s);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
```

#### Go

```go
type Trie struct {
	children [26]*Trie
	isEnd    bool
}

func newTrie() Trie {
	return Trie{}
}

func (this *Trie) Insert(word string) {
	node := this
	for i := len(word) - 1; i >= 0; i-- {
		idx := word[i] - 'a'
		if node.children[idx] == nil {
			node.children[idx] = &Trie{}
		}
		node = node.children[idx]
	}
	node.isEnd = true
}

func (this *Trie) Search(word []byte) bool {
	node := this
	for i := len(word) - 1; i >= 0; i-- {
		idx := word[i] - 'a'
		if node.children[idx] == nil {
			return false
		}
		node = node.children[idx]
		if node.isEnd {
			return true
		}
	}
	return false
}

type StreamChecker struct {
	trie Trie
	s    []byte
}

func Constructor(words []string) StreamChecker {
	trie := newTrie()
	for _, w := range words {
		trie.Insert(w)
	}
	return StreamChecker{trie, []byte{}}
}

func (this *StreamChecker) Query(letter byte) bool {
	this.s = append(this.s, letter)
	return this.trie.Search(this.s)
}

/**
 * Your StreamChecker object will be instantiated and called as such:
 * obj := Constructor(words);
 * param_1 := obj.Query(letter);
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1033. 移动石子直到连续](https://leetcode.cn/problems/moving-stones-until-consecutive){#1033}

{{< tabs "1033" >}}

{{% tab "python" %}}
```python
class Solution:
    def numMovesStones(self, a: int, b: int, c: int) -> List[int]:
        x, z = min(a, b, c), max(a, b, c)
        y = a + b + c - x - z
        mi = mx = 0
        if z - x > 2:
            mi = 1 if y - x < 3 or z - y < 3 else 2
            mx = z - x - 2
        return [mi, mx]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] numMovesStones(int a, int b, int c) {
        int x = Math.min(a, Math.min(b, c));
        int z = Math.max(a, Math.max(b, c));
        int y = a + b + c - x - z;
        int mi = 0, mx = 0;
        if (z - x > 2) {
            mi = y - x < 3 || z - y < 3 ? 1 : 2;
            mx = z - x - 2;
        }
        return new int[] {mi, mx};
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        int x = min({a, b, c});
        int z = max({a, b, c});
        int y = a + b + c - x - z;
        int mi = 0, mx = 0;
        if (z - x > 2) {
            mi = y - x < 3 || z - y < 3 ? 1 : 2;
            mx = z - x - 2;
        }
        return {mi, mx};
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numMovesStones(a int, b int, c int) []int {
	x := min(a, min(b, c))
	z := max(a, max(b, c))
	y := a + b + c - x - z
	mi, mx := 0, 0
	if z-x > 2 {
		mi = 2
		if y-x < 3 || z-y < 3 {
			mi = 1
		}
		mx = z - x - 2
	}
	return []int{mi, mx}
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numMovesStones(a: number, b: number, c: number): number[] {
    const x = Math.min(a, Math.min(b, c));
    const z = Math.max(a, Math.max(b, c));
    const y = a + b + c - x - z;
    let mi = 0,
        mx = 0;
    if (z - x > 2) {
        mi = y - x < 3 || z - y < 3 ? 1 : 2;
        mx = z - x - 2;
    }
    return [mi, mx];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>三枚石子放置在数轴上，位置分别为 <code>a</code>，<code>b</code>，<code>c</code>。</p>

<p>每一回合，你可以从两端之一拿起一枚石子（位置最大或最小），并将其放入两端之间的任一空闲位置。形式上，假设这三枚石子当前分别位于位置 <code>x, y, z</code> 且 <code>x < y < z</code>。那么就可以从位置 <code>x</code> 或者是位置 <code>z</code> 拿起一枚石子，并将该石子移动到某一整数位置 <code>k</code> 处，其中 <code>x < k < z</code> 且 <code>k != y</code>。</p>

<p>当你无法进行任何移动时，即，这些石子的位置连续时，游戏结束。</p>

<p>要使游戏结束，你可以执行的最小和最大移动次数分别是多少？ 以长度为 2 的数组形式返回答案：<code>answer = [minimum_moves, maximum_moves]</code></p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>a = 1, b = 2, c = 5
<strong>输出：</strong>[1, 2]
<strong>解释：</strong>将石子从 5 移动到 4 再移动到 3，或者我们可以直接将石子移动到 3。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>a = 4, b = 3, c = 2
<strong>输出：</strong>[0, 0]
<strong>解释：</strong>我们无法进行任何移动。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ol>
	<li><code>1 <= a <= 100</code></li>
	<li><code>1 <= b <= 100</code></li>
	<li><code>1 <= c <= 100</code></li>
	<li><code>a != b, b != c, c != a</code></li>
</ol>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：分类讨论

我们先将 $a, b, c$ 排序，记为 $x, y, z$，即 $x \lt y \lt z$。

接下来分情况讨论：

1. 如果 $z - x \leq 2$，说明 $3$ 个数已经相邻，不用移动，结果为 $[0, 0]$；
1. 否则，如果 $y - x \lt 3$，或者 $z - y \lt 3$，说明有两个数只间隔一个位置，我们只需要把另一个数移动到这两个数的中间，最小移动次数为 $1$；其他情况，最小移动次数为 $2$；
1. 最大移动次数就是两边的数字逐个往中间靠，最多移动 $z - x - 2$ 次。

时间复杂度 $O(1)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numMovesStones(self, a: int, b: int, c: int) -> List[int]:
        x, z = min(a, b, c), max(a, b, c)
        y = a + b + c - x - z
        mi = mx = 0
        if z - x > 2:
            mi = 1 if y - x < 3 or z - y < 3 else 2
            mx = z - x - 2
        return [mi, mx]
```

#### Java

```java
class Solution {
    public int[] numMovesStones(int a, int b, int c) {
        int x = Math.min(a, Math.min(b, c));
        int z = Math.max(a, Math.max(b, c));
        int y = a + b + c - x - z;
        int mi = 0, mx = 0;
        if (z - x > 2) {
            mi = y - x < 3 || z - y < 3 ? 1 : 2;
            mx = z - x - 2;
        }
        return new int[] {mi, mx};
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        int x = min({a, b, c});
        int z = max({a, b, c});
        int y = a + b + c - x - z;
        int mi = 0, mx = 0;
        if (z - x > 2) {
            mi = y - x < 3 || z - y < 3 ? 1 : 2;
            mx = z - x - 2;
        }
        return {mi, mx};
    }
};
```

#### Go

```go
func numMovesStones(a int, b int, c int) []int {
	x := min(a, min(b, c))
	z := max(a, max(b, c))
	y := a + b + c - x - z
	mi, mx := 0, 0
	if z-x > 2 {
		mi = 2
		if y-x < 3 || z-y < 3 {
			mi = 1
		}
		mx = z - x - 2
	}
	return []int{mi, mx}
}
```

#### TypeScript

```ts
function numMovesStones(a: number, b: number, c: number): number[] {
    const x = Math.min(a, Math.min(b, c));
    const z = Math.max(a, Math.max(b, c));
    const y = a + b + c - x - z;
    let mi = 0,
        mx = 0;
    if (z - x > 2) {
        mi = y - x < 3 || z - y < 3 ? 1 : 2;
        mx = z - x - 2;
    }
    return [mi, mx];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1034. 边界着色](https://leetcode.cn/problems/coloring-a-border){#1034}

{{< tabs "1034" >}}

{{% tab "python" %}}
```python
class Solution:
    def colorBorder(
        self, grid: List[List[int]], row: int, col: int, color: int
    ) -> List[List[int]]:
        def dfs(i: int, j: int, c: int) -> None:
            vis[i][j] = True
            for a, b in pairwise((-1, 0, 1, 0, -1)):
                x, y = i + a, j + b
                if 0 <= x < m and 0 <= y < n:
                    if not vis[x][y]:
                        if grid[x][y] == c:
                            dfs(x, y, c)
                        else:
                            grid[i][j] = color
                else:
                    grid[i][j] = color

        m, n = len(grid), len(grid[0])
        vis = [[False] * n for _ in range(m)]
        dfs(row, col, grid[row][col])
        return grid
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[][] grid;
    private int color;
    private int m;
    private int n;
    private boolean[][] vis;

    public int[][] colorBorder(int[][] grid, int row, int col, int color) {
        this.grid = grid;
        this.color = color;
        m = grid.length;
        n = grid[0].length;
        vis = new boolean[m][n];
        dfs(row, col, grid[row][col]);
        return grid;
    }

    private void dfs(int i, int j, int c) {
        vis[i][j] = true;
        int[] dirs = {-1, 0, 1, 0, -1};
        for (int k = 0; k < 4; ++k) {
            int x = i + dirs[k], y = j + dirs[k + 1];
            if (x >= 0 && x < m && y >= 0 && y < n) {
                if (!vis[x][y]) {
                    if (grid[x][y] == c) {
                        dfs(x, y, c);
                    } else {
                        grid[i][j] = color;
                    }
                }
            } else {
                grid[i][j] = color;
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
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int m = grid.size();
        int n = grid[0].size();
        bool vis[m][n];
        memset(vis, false, sizeof(vis));
        int dirs[5] = {-1, 0, 1, 0, -1};
        function<void(int, int, int)> dfs = [&](int i, int j, int c) {
            vis[i][j] = true;
            for (int k = 0; k < 4; ++k) {
                int x = i + dirs[k];
                int y = j + dirs[k + 1];
                if (x >= 0 && x < m && y >= 0 && y < n) {
                    if (!vis[x][y]) {
                        if (grid[x][y] == c) {
                            dfs(x, y, c);
                        } else {
                            grid[i][j] = color;
                        }
                    }
                } else {
                    grid[i][j] = color;
                }
            }
        };
        dfs(row, col, grid[row][col]);
        return grid;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func colorBorder(grid [][]int, row int, col int, color int) [][]int {
	m, n := len(grid), len(grid[0])
	vis := make([][]bool, m)
	for i := range vis {
		vis[i] = make([]bool, n)
	}
	dirs := [5]int{-1, 0, 1, 0, -1}
	var dfs func(int, int, int)
	dfs = func(i, j, c int) {
		vis[i][j] = true
		for k := 0; k < 4; k++ {
			x, y := i+dirs[k], j+dirs[k+1]
			if x >= 0 && x < m && y >= 0 && y < n {
				if !vis[x][y] {
					if grid[x][y] == c {
						dfs(x, y, c)
					} else {
						grid[i][j] = color
					}
				}
			} else {
				grid[i][j] = color
			}
		}
	}
	dfs(row, col, grid[row][col])
	return grid
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function colorBorder(grid: number[][], row: number, col: number, color: number): number[][] {
    const m = grid.length;
    const n = grid[0].length;
    const vis = new Array(m).fill(0).map(() => new Array(n).fill(false));
    const dirs = [-1, 0, 1, 0, -1];
    const dfs = (i: number, j: number, c: number) => {
        vis[i][j] = true;
        for (let k = 0; k < 4; ++k) {
            const x = i + dirs[k];
            const y = j + dirs[k + 1];
            if (x >= 0 && x < m && y >= 0 && y < n) {
                if (!vis[x][y]) {
                    if (grid[x][y] == c) {
                        dfs(x, y, c);
                    } else {
                        grid[i][j] = color;
                    }
                }
            } else {
                grid[i][j] = color;
            }
        }
    };
    dfs(row, col, grid[row][col]);
    return grid;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个大小为 <code>m x n</code> 的整数矩阵 <code>grid</code> ，表示一个网格。另给你三个整数&nbsp;<code>row</code>、<code>col</code> 和 <code>color</code> 。网格中的每个值表示该位置处的网格块的颜色。</p>

<p>如果两个方块在任意 4 个方向上相邻，则称它们&nbsp;<strong>相邻 </strong>。</p>

<p>如果两个方块具有相同的颜色且相邻，它们则属于同一个 <strong>连通分量</strong> 。</p>

<p><strong>连通分量的边界</strong><strong> </strong>是指连通分量中满足下述条件之一的所有网格块：</p>

<ul>
	<li>在上、下、左、右任意一个方向上与不属于同一连通分量的网格块相邻</li>
	<li>在网格的边界上（第一行/列或最后一行/列）</li>
</ul>

<p>请你使用指定颜色&nbsp;<code>color</code> 为所有包含网格块&nbsp;<code>grid[row][col]</code> 的 <strong>连通分量的边界</strong> 进行着色。</p>

<p>并返回最终的网格&nbsp;<code>grid</code> 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>grid = [[1,1],[1,2]], row = 0, col = 0, color = 3
<strong>输出：</strong>[[3,3],[3,2]]</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>grid = [[1,2,2],[2,3,2]], row = 0, col = 1, color = 3
<strong>输出：</strong>[[1,3,3],[2,3,3]]</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>grid = [[1,1,1],[1,1,1],[1,1,1]], row = 1, col = 1, color = 2
<strong>输出：</strong>[[2,2,2],[2,1,2],[2,2,2]]</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 50</code></li>
	<li><code>1 &lt;= grid[i][j], color &lt;= 1000</code></li>
	<li><code>0 &lt;= row &lt; m</code></li>
	<li><code>0 &lt;= col &lt; n</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS

我们从位置 $(row, col)$ 出发，利用 DFS 搜索所有颜色为 $grid[row][col]$ 的网格块，如果该网格块的某个相邻位置的颜色不为 $grid[row][col]$，或者该网格块在网格的边界上，则将该网格块的颜色改为 $color$。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别是网格的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def colorBorder(
        self, grid: List[List[int]], row: int, col: int, color: int
    ) -> List[List[int]]:
        def dfs(i: int, j: int, c: int) -> None:
            vis[i][j] = True
            for a, b in pairwise((-1, 0, 1, 0, -1)):
                x, y = i + a, j + b
                if 0 <= x < m and 0 <= y < n:
                    if not vis[x][y]:
                        if grid[x][y] == c:
                            dfs(x, y, c)
                        else:
                            grid[i][j] = color
                else:
                    grid[i][j] = color

        m, n = len(grid), len(grid[0])
        vis = [[False] * n for _ in range(m)]
        dfs(row, col, grid[row][col])
        return grid
```

#### Java

```java
class Solution {
    private int[][] grid;
    private int color;
    private int m;
    private int n;
    private boolean[][] vis;

    public int[][] colorBorder(int[][] grid, int row, int col, int color) {
        this.grid = grid;
        this.color = color;
        m = grid.length;
        n = grid[0].length;
        vis = new boolean[m][n];
        dfs(row, col, grid[row][col]);
        return grid;
    }

    private void dfs(int i, int j, int c) {
        vis[i][j] = true;
        int[] dirs = {-1, 0, 1, 0, -1};
        for (int k = 0; k < 4; ++k) {
            int x = i + dirs[k], y = j + dirs[k + 1];
            if (x >= 0 && x < m && y >= 0 && y < n) {
                if (!vis[x][y]) {
                    if (grid[x][y] == c) {
                        dfs(x, y, c);
                    } else {
                        grid[i][j] = color;
                    }
                }
            } else {
                grid[i][j] = color;
            }
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int m = grid.size();
        int n = grid[0].size();
        bool vis[m][n];
        memset(vis, false, sizeof(vis));
        int dirs[5] = {-1, 0, 1, 0, -1};
        function<void(int, int, int)> dfs = [&](int i, int j, int c) {
            vis[i][j] = true;
            for (int k = 0; k < 4; ++k) {
                int x = i + dirs[k];
                int y = j + dirs[k + 1];
                if (x >= 0 && x < m && y >= 0 && y < n) {
                    if (!vis[x][y]) {
                        if (grid[x][y] == c) {
                            dfs(x, y, c);
                        } else {
                            grid[i][j] = color;
                        }
                    }
                } else {
                    grid[i][j] = color;
                }
            }
        };
        dfs(row, col, grid[row][col]);
        return grid;
    }
};
```

#### Go

```go
func colorBorder(grid [][]int, row int, col int, color int) [][]int {
	m, n := len(grid), len(grid[0])
	vis := make([][]bool, m)
	for i := range vis {
		vis[i] = make([]bool, n)
	}
	dirs := [5]int{-1, 0, 1, 0, -1}
	var dfs func(int, int, int)
	dfs = func(i, j, c int) {
		vis[i][j] = true
		for k := 0; k < 4; k++ {
			x, y := i+dirs[k], j+dirs[k+1]
			if x >= 0 && x < m && y >= 0 && y < n {
				if !vis[x][y] {
					if grid[x][y] == c {
						dfs(x, y, c)
					} else {
						grid[i][j] = color
					}
				}
			} else {
				grid[i][j] = color
			}
		}
	}
	dfs(row, col, grid[row][col])
	return grid
}
```

#### TypeScript

```ts
function colorBorder(grid: number[][], row: number, col: number, color: number): number[][] {
    const m = grid.length;
    const n = grid[0].length;
    const vis = new Array(m).fill(0).map(() => new Array(n).fill(false));
    const dirs = [-1, 0, 1, 0, -1];
    const dfs = (i: number, j: number, c: number) => {
        vis[i][j] = true;
        for (let k = 0; k < 4; ++k) {
            const x = i + dirs[k];
            const y = j + dirs[k + 1];
            if (x >= 0 && x < m && y >= 0 && y < n) {
                if (!vis[x][y]) {
                    if (grid[x][y] == c) {
                        dfs(x, y, c);
                    } else {
                        grid[i][j] = color;
                    }
                }
            } else {
                grid[i][j] = color;
            }
        }
    };
    dfs(row, col, grid[row][col]);
    return grid;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1035. 不相交的线](https://leetcode.cn/problems/uncrossed-lines){#1035}

{{< tabs "1035" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxUncrossedLines(self, nums1: List[int], nums2: List[int]) -> int:
        m, n = len(nums1), len(nums2)
        f = [[0] * (n + 1) for _ in range(m + 1)]
        for i, x in enumerate(nums1, 1):
            for j, y in enumerate(nums2, 1):
                if x == y:
                    f[i][j] = f[i - 1][j - 1] + 1
                else:
                    f[i][j] = max(f[i - 1][j], f[i][j - 1])
        return f[m][n]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxUncrossedLines(int[] nums1, int[] nums2) {
        int m = nums1.length, n = nums2.length;
        int[][] f = new int[m + 1][n + 1];
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    f[i][j] = f[i - 1][j - 1] + 1;
                } else {
                    f[i][j] = Math.max(f[i - 1][j], f[i][j - 1]);
                }
            }
        }
        return f[m][n];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int f[m + 1][n + 1];
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    f[i][j] = f[i - 1][j - 1] + 1;
                } else {
                    f[i][j] = max(f[i - 1][j], f[i][j - 1]);
                }
            }
        }
        return f[m][n];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxUncrossedLines(nums1 []int, nums2 []int) int {
	m, n := len(nums1), len(nums2)
	f := make([][]int, m+1)
	for i := range f {
		f[i] = make([]int, n+1)
	}
	for i := 1; i <= m; i++ {
		for j := 1; j <= n; j++ {
			if nums1[i-1] == nums2[j-1] {
				f[i][j] = f[i-1][j-1] + 1
			} else {
				f[i][j] = max(f[i-1][j], f[i][j-1])
			}
		}
	}
	return f[m][n]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxUncrossedLines(nums1: number[], nums2: number[]): number {
    const m = nums1.length;
    const n = nums2.length;
    const f: number[][] = Array.from({ length: m + 1 }, () => Array(n + 1).fill(0));
    for (let i = 1; i <= m; ++i) {
        for (let j = 1; j <= n; ++j) {
            if (nums1[i - 1] === nums2[j - 1]) {
                f[i][j] = f[i - 1][j - 1] + 1;
            } else {
                f[i][j] = Math.max(f[i - 1][j], f[i][j - 1]);
            }
        }
    }
    return f[m][n];
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var maxUncrossedLines = function (nums1, nums2) {
    const m = nums1.length;
    const n = nums2.length;
    const f = Array.from({ length: m + 1 }, () => Array(n + 1).fill(0));
    for (let i = 1; i <= m; ++i) {
        for (let j = 1; j <= n; ++j) {
            if (nums1[i - 1] === nums2[j - 1]) {
                f[i][j] = f[i - 1][j - 1] + 1;
            } else {
                f[i][j] = Math.max(f[i - 1][j], f[i][j - 1]);
            }
        }
    }
    return f[m][n];
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>在两条独立的水平线上按给定的顺序写下 <code>nums1</code> 和 <code>nums2</code> 中的整数。</p>

<p>现在，可以绘制一些连接两个数字 <code>nums1[i]</code>&nbsp;和 <code>nums2[j]</code>&nbsp;的直线，这些直线需要同时满足：</p>

<ul>
	<li>&nbsp;<code>nums1[i] == nums2[j]</code></li>
	<li>且绘制的直线不与任何其他连线（非水平线）相交。</li>
</ul>

<p>请注意，连线即使在端点也不能相交：每个数字只能属于一条连线。</p>

<p>以这种方法绘制线条，并返回可以绘制的最大连线数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1000-1099/1035.Uncrossed%20Lines/images/142.png" style="width: 400px; height: 286px;" />
<pre>
<strong>输入：</strong>nums1 = <span id="example-input-1-1">[1,4,2]</span>, nums2 = <span id="example-input-1-2">[1,2,4]</span>
<strong>输出：</strong><span id="example-output-1">2</span>
<strong>解释：</strong>可以画出两条不交叉的线，如上图所示。 
但无法画出第三条不相交的直线，因为从 nums1[1]=4 到 nums2[2]=4 的直线将与从 nums1[2]=2 到 nums2[1]=2 的直线相交。
</pre>

<div>
<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums1 = <span id="example-input-2-1">[2,5,1,2,5]</span>, nums2 = <span id="example-input-2-2">[10,5,2,1,5,2]</span>
<strong>输出：</strong><span id="example-output-2">3</span>
</pre>

<div>
<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums1 = <span id="example-input-3-1">[1,3,7,1,7,5]</span>, nums2 = <span id="example-input-3-2">[1,9,2,5,1]</span>
<strong>输出：</strong><span id="example-output-3">2</span></pre>

<p>&nbsp;</p>
</div>
</div>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums1.length, nums2.length &lt;= 500</code></li>
	<li><code>1 &lt;= nums1[i], nums2[j] &lt;= 2000</code></li>
</ul>

<p>&nbsp;</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i][j]$ 表示 $\textit{nums1}$ 前 $i$ 个数和 $\textit{nums2}$ 前 $j$ 个数的最大连线数。初始时 $f[i][j] = 0$，答案即为 $f[m][n]$。

当 $\textit{nums1}[i-1] = \textit{nums2}[j-1]$ 时，我们可以在 $\textit{nums1}$ 的前 $i-1$ 个数和 $\textit{nums2}$ 的前 $j-1$ 个数的基础上增加一条连线，此时 $f[i][j] = f[i-1][j-1] + 1$。

当 $\textit{nums1}[i-1] \neq \textit{nums2}[j-1]$ 时，我们要么在 $\textit{nums1}$ 的前 $i-1$ 个数和 $\textit{nums2}$ 的前 $j$ 个数的基础上求解，要么在 $\textit{nums1}$ 的前 $i$ 个数和 $\textit{nums2}$ 的前 $j-1$ 个数的基础上求解，取两者的最大值，即 $f[i][j] = \max(f[i-1][j], f[i][j-1])$。

最后返回 $f[m][n]$ 即可。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别是 $\textit{nums1}$ 和 $\textit{nums2}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxUncrossedLines(self, nums1: List[int], nums2: List[int]) -> int:
        m, n = len(nums1), len(nums2)
        f = [[0] * (n + 1) for _ in range(m + 1)]
        for i, x in enumerate(nums1, 1):
            for j, y in enumerate(nums2, 1):
                if x == y:
                    f[i][j] = f[i - 1][j - 1] + 1
                else:
                    f[i][j] = max(f[i - 1][j], f[i][j - 1])
        return f[m][n]
```

#### Java

```java
class Solution {
    public int maxUncrossedLines(int[] nums1, int[] nums2) {
        int m = nums1.length, n = nums2.length;
        int[][] f = new int[m + 1][n + 1];
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    f[i][j] = f[i - 1][j - 1] + 1;
                } else {
                    f[i][j] = Math.max(f[i - 1][j], f[i][j - 1]);
                }
            }
        }
        return f[m][n];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int f[m + 1][n + 1];
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    f[i][j] = f[i - 1][j - 1] + 1;
                } else {
                    f[i][j] = max(f[i - 1][j], f[i][j - 1]);
                }
            }
        }
        return f[m][n];
    }
};
```

#### Go

```go
func maxUncrossedLines(nums1 []int, nums2 []int) int {
	m, n := len(nums1), len(nums2)
	f := make([][]int, m+1)
	for i := range f {
		f[i] = make([]int, n+1)
	}
	for i := 1; i <= m; i++ {
		for j := 1; j <= n; j++ {
			if nums1[i-1] == nums2[j-1] {
				f[i][j] = f[i-1][j-1] + 1
			} else {
				f[i][j] = max(f[i-1][j], f[i][j-1])
			}
		}
	}
	return f[m][n]
}
```

#### TypeScript

```ts
function maxUncrossedLines(nums1: number[], nums2: number[]): number {
    const m = nums1.length;
    const n = nums2.length;
    const f: number[][] = Array.from({ length: m + 1 }, () => Array(n + 1).fill(0));
    for (let i = 1; i <= m; ++i) {
        for (let j = 1; j <= n; ++j) {
            if (nums1[i - 1] === nums2[j - 1]) {
                f[i][j] = f[i - 1][j - 1] + 1;
            } else {
                f[i][j] = Math.max(f[i - 1][j], f[i][j - 1]);
            }
        }
    }
    return f[m][n];
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var maxUncrossedLines = function (nums1, nums2) {
    const m = nums1.length;
    const n = nums2.length;
    const f = Array.from({ length: m + 1 }, () => Array(n + 1).fill(0));
    for (let i = 1; i <= m; ++i) {
        for (let j = 1; j <= n; ++j) {
            if (nums1[i - 1] === nums2[j - 1]) {
                f[i][j] = f[i - 1][j - 1] + 1;
            } else {
                f[i][j] = Math.max(f[i - 1][j], f[i][j - 1]);
            }
        }
    }
    return f[m][n];
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1036. 逃离大迷宫](https://leetcode.cn/problems/escape-a-large-maze){#1036}

{{< tabs "1036" >}}

{{% tab "python" %}}
```python
class Solution:
    def isEscapePossible(
        self, blocked: List[List[int]], source: List[int], target: List[int]
    ) -> bool:
        def dfs(source: List[int], target: List[int], vis: set) -> bool:
            vis.add(tuple(source))
            if len(vis) > m:
                return True
            for a, b in pairwise(dirs):
                x, y = source[0] + a, source[1] + b
                if 0 <= x < n and 0 <= y < n and (x, y) not in s and (x, y) not in vis:
                    if [x, y] == target or dfs([x, y], target, vis):
                        return True
            return False

        s = {(x, y) for x, y in blocked}
        dirs = (-1, 0, 1, 0, -1)
        n = 10**6
        m = len(blocked) ** 2 // 2
        return dfs(source, target, set()) and dfs(target, source, set())
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private final int n = (int) 1e6;
    private int m;
    private Set<Long> s = new HashSet<>();
    private final int[] dirs = {-1, 0, 1, 0, -1};

    public boolean isEscapePossible(int[][] blocked, int[] source, int[] target) {
        for (var b : blocked) {
            s.add(f(b[0], b[1]));
        }
        m = blocked.length * blocked.length / 2;
        int sx = source[0], sy = source[1];
        int tx = target[0], ty = target[1];
        return dfs(sx, sy, tx, ty, new HashSet<>()) && dfs(tx, ty, sx, sy, new HashSet<>());
    }

    private boolean dfs(int sx, int sy, int tx, int ty, Set<Long> vis) {
        if (vis.size() > m) {
            return true;
        }
        for (int k = 0; k < 4; ++k) {
            int x = sx + dirs[k], y = sy + dirs[k + 1];
            if (x >= 0 && x < n && y >= 0 && y < n) {
                if (x == tx && y == ty) {
                    return true;
                }
                long key = f(x, y);
                if (!s.contains(key) && vis.add(key) && dfs(x, y, tx, ty, vis)) {
                    return true;
                }
            }
        }
        return false;
    }

    private long f(int i, int j) {
        return (long) i * n + j;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        const int n = 1e6;
        int m = blocked.size() * blocked.size() / 2;
        using ll = long long;
        unordered_set<ll> s;
        const int dirs[5] = {-1, 0, 1, 0, -1};
        auto f = [&](int i, int j) {
            return (ll) i * n + j;
        };
        for (const auto& b : blocked) {
            s.insert(f(b[0], b[1]));
        }
        int sx = source[0], sy = source[1];
        int tx = target[0], ty = target[1];
        unordered_set<ll> vis1, vis2;
        auto dfs = [&](this auto&& dfs, int sx, int sy, int tx, int ty, unordered_set<ll>& vis) -> bool {
            vis.insert(f(sx, sy));
            if (vis.size() > m) {
                return true;
            }
            for (int k = 0; k < 4; ++k) {
                int x = sx + dirs[k], y = sy + dirs[k + 1];
                if (x >= 0 && x < n && y >= 0 && y < n) {
                    if (x == tx && y == ty) {
                        return true;
                    }
                    auto key = f(x, y);
                    if (!s.contains(key) && !vis.contains(key) && dfs(x, y, tx, ty, vis)) {
                        return true;
                    }
                }
            }
            return false;
        };
        return dfs(sx, sy, tx, ty, vis1) && dfs(tx, ty, sx, sy, vis2);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func isEscapePossible(blocked [][]int, source []int, target []int) bool {
	const n = 1_000_000
	m := len(blocked) * len(blocked) / 2
	dirs := [5]int{-1, 0, 1, 0, -1}

	f := func(i, j int) int64 {
		return int64(i*n + j)
	}

	s := make(map[int64]bool)
	for _, b := range blocked {
		s[f(b[0], b[1])] = true
	}

	var dfs func(sx, sy, tx, ty int, vis map[int64]bool) bool
	dfs = func(sx, sy, tx, ty int, vis map[int64]bool) bool {
		key := f(sx, sy)
		vis[key] = true
		if len(vis) > m {
			return true
		}
		for k := 0; k < 4; k++ {
			x, y := sx+dirs[k], sy+dirs[k+1]
			if x >= 0 && x < n && y >= 0 && y < n {
				if x == tx && y == ty {
					return true
				}
				key := f(x, y)
				if !s[key] && !vis[key] && dfs(x, y, tx, ty, vis) {
					return true
				}
			}
		}
		return false
	}

	sx, sy := source[0], source[1]
	tx, ty := target[0], target[1]
	return dfs(sx, sy, tx, ty, map[int64]bool{}) && dfs(tx, ty, sx, sy, map[int64]bool{})
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function isEscapePossible(blocked: number[][], source: number[], target: number[]): boolean {
    const n = 10 ** 6;
    const m = (blocked.length ** 2) >> 1;
    const dirs = [-1, 0, 1, 0, -1];

    const s = new Set<number>();
    const f = (i: number, j: number): number => i * n + j;

    for (const [x, y] of blocked) {
        s.add(f(x, y));
    }

    const dfs = (sx: number, sy: number, tx: number, ty: number, vis: Set<number>): boolean => {
        vis.add(f(sx, sy));
        if (vis.size > m) {
            return true;
        }
        for (let k = 0; k < 4; k++) {
            const x = sx + dirs[k],
                y = sy + dirs[k + 1];
            if (x >= 0 && x < n && y >= 0 && y < n) {
                if (x === tx && y === ty) {
                    return true;
                }
                const key = f(x, y);
                if (!s.has(key) && !vis.has(key) && dfs(x, y, tx, ty, vis)) {
                    return true;
                }
            }
        }
        return false;
    };

    return (
        dfs(source[0], source[1], target[0], target[1], new Set()) &&
        dfs(target[0], target[1], source[0], source[1], new Set())
    );
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashSet;

impl Solution {
    pub fn is_escape_possible(blocked: Vec<Vec<i32>>, source: Vec<i32>, target: Vec<i32>) -> bool {
        const N: i64 = 1_000_000;
        let m = (blocked.len() * blocked.len()) as i64 / 2;

        let f = |i: i64, j: i64| -> i64 { i * N + j };

        let mut s: HashSet<i64> = HashSet::new();
        for b in &blocked {
            s.insert(f(b[0] as i64, b[1] as i64));
        }

        fn dfs(
            sx: i64,
            sy: i64,
            tx: i64,
            ty: i64,
            s: &HashSet<i64>,
            m: i64,
            vis: &mut HashSet<i64>,
        ) -> bool {
            static DIRS: [i64; 5] = [-1, 0, 1, 0, -1];
            let key = sx * 1_000_000 + sy;
            vis.insert(key);
            if vis.len() as i64 > m {
                return true;
            }
            for k in 0..4 {
                let x = sx + DIRS[k];
                let y = sy + DIRS[k + 1];
                let key = x * 1_000_000 + y;
                if x >= 0 && x < 1_000_000 && y >= 0 && y < 1_000_000 {
                    if x == tx && y == ty {
                        return true;
                    }
                    if !s.contains(&key) && vis.insert(key) && dfs(x, y, tx, ty, s, m, vis) {
                        return true;
                    }
                }
            }
            false
        }

        dfs(
            source[0] as i64,
            source[1] as i64,
            target[0] as i64,
            target[1] as i64,
            &s,
            m,
            &mut HashSet::new(),
        ) && dfs(
            target[0] as i64,
            target[1] as i64,
            source[0] as i64,
            source[1] as i64,
            &s,
            m,
            &mut HashSet::new(),
        )
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>在一个 10<sup>6</sup> x 10<sup>6</sup> 的网格中，每个网格上方格的坐标为 <code>(x, y)</code> 。</p>

<p>现在从源方格 <code>source = [s<sub>x</sub>, s<sub>y</sub>]</code> 开始出发，意图赶往目标方格 <code>target = [t<sub>x</sub>, t<sub>y</sub>]</code> 。数组 <code>blocked</code> 是封锁的方格列表，其中每个 <code>blocked[i] = [x<sub>i</sub>, y<sub>i</sub>]</code> 表示坐标为 <code>(x<sub>i</sub>, y<sub>i</sub>)</code> 的方格是禁止通行的。</p>

<p>每次移动，都可以走到网格中在四个方向上相邻的方格，只要该方格 <strong>不</strong> 在给出的封锁列表 <code>blocked</code> 上。同时，不允许走出网格。</p>

<p>只有在可以通过一系列的移动从源方格 <code>source</code> 到达目标方格 <code>target</code> 时才返回 <code>true</code>。否则，返回 <code>false</code>。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>blocked = [[0,1],[1,0]], source = [0,0], target = [0,2]
<strong>输出：</strong>false
<strong>解释：</strong>
从源方格无法到达目标方格，因为我们无法在网格中移动。
无法向北或者向东移动是因为方格禁止通行。
无法向南或者向西移动是因为不能走出网格。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>blocked = [], source = [0,0], target = [999999,999999]
<strong>输出：</strong>true
<strong>解释：</strong>
因为没有方格被封锁，所以一定可以到达目标方格。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 <= blocked.length <= 200</code></li>
	<li><code>blocked[i].length == 2</code></li>
	<li><code>0 <= x<sub>i</sub>, y<sub>i</sub> < 10<sup>6</sup></code></li>
	<li><code>source.length == target.length == 2</code></li>
	<li><code>0 <= s<sub>x</sub>, s<sub>y</sub>, t<sub>x</sub>, t<sub>y</sub> < 10<sup>6</sup></code></li>
	<li><code>source != target</code></li>
	<li>题目数据保证 <code>source</code> 和 <code>target</code> 不在封锁列表内</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS

题目相当于在一个 $10^6 \times 10^6$ 的网格中，给定源点和目标点，以及一小部分被封锁的点，问是否可以从源点到达目标点。

由于被封锁的点数量很少，最终能封锁的区域大小不超过 $|blocked|^2 / 2$，因此，我们可以从源点和目标点出发，进行深度优先搜索，直到搜索到目标点或者搜索到的点数超过 $|blocked|^2 / 2$，如果都满足，则返回 $\textit{true}$。否则返回 $\textit{false}$。

时间复杂度 $O(m)$，空间复杂度 $O(m)$，其中 $m$ 是被封锁的区域的大小，本题中 $m \leq |blocked|^2 / 2 = 200^2 / 2 = 20000$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def isEscapePossible(
        self, blocked: List[List[int]], source: List[int], target: List[int]
    ) -> bool:
        def dfs(source: List[int], target: List[int], vis: set) -> bool:
            vis.add(tuple(source))
            if len(vis) > m:
                return True
            for a, b in pairwise(dirs):
                x, y = source[0] + a, source[1] + b
                if 0 <= x < n and 0 <= y < n and (x, y) not in s and (x, y) not in vis:
                    if [x, y] == target or dfs([x, y], target, vis):
                        return True
            return False

        s = {(x, y) for x, y in blocked}
        dirs = (-1, 0, 1, 0, -1)
        n = 10**6
        m = len(blocked) ** 2 // 2
        return dfs(source, target, set()) and dfs(target, source, set())
```

#### Java

```java
class Solution {
    private final int n = (int) 1e6;
    private int m;
    private Set<Long> s = new HashSet<>();
    private final int[] dirs = {-1, 0, 1, 0, -1};

    public boolean isEscapePossible(int[][] blocked, int[] source, int[] target) {
        for (var b : blocked) {
            s.add(f(b[0], b[1]));
        }
        m = blocked.length * blocked.length / 2;
        int sx = source[0], sy = source[1];
        int tx = target[0], ty = target[1];
        return dfs(sx, sy, tx, ty, new HashSet<>()) && dfs(tx, ty, sx, sy, new HashSet<>());
    }

    private boolean dfs(int sx, int sy, int tx, int ty, Set<Long> vis) {
        if (vis.size() > m) {
            return true;
        }
        for (int k = 0; k < 4; ++k) {
            int x = sx + dirs[k], y = sy + dirs[k + 1];
            if (x >= 0 && x < n && y >= 0 && y < n) {
                if (x == tx && y == ty) {
                    return true;
                }
                long key = f(x, y);
                if (!s.contains(key) && vis.add(key) && dfs(x, y, tx, ty, vis)) {
                    return true;
                }
            }
        }
        return false;
    }

    private long f(int i, int j) {
        return (long) i * n + j;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        const int n = 1e6;
        int m = blocked.size() * blocked.size() / 2;
        using ll = long long;
        unordered_set<ll> s;
        const int dirs[5] = {-1, 0, 1, 0, -1};
        auto f = [&](int i, int j) {
            return (ll) i * n + j;
        };
        for (const auto& b : blocked) {
            s.insert(f(b[0], b[1]));
        }
        int sx = source[0], sy = source[1];
        int tx = target[0], ty = target[1];
        unordered_set<ll> vis1, vis2;
        auto dfs = [&](this auto&& dfs, int sx, int sy, int tx, int ty, unordered_set<ll>& vis) -> bool {
            vis.insert(f(sx, sy));
            if (vis.size() > m) {
                return true;
            }
            for (int k = 0; k < 4; ++k) {
                int x = sx + dirs[k], y = sy + dirs[k + 1];
                if (x >= 0 && x < n && y >= 0 && y < n) {
                    if (x == tx && y == ty) {
                        return true;
                    }
                    auto key = f(x, y);
                    if (!s.contains(key) && !vis.contains(key) && dfs(x, y, tx, ty, vis)) {
                        return true;
                    }
                }
            }
            return false;
        };
        return dfs(sx, sy, tx, ty, vis1) && dfs(tx, ty, sx, sy, vis2);
    }
};
```

#### Go

```go
func isEscapePossible(blocked [][]int, source []int, target []int) bool {
	const n = 1_000_000
	m := len(blocked) * len(blocked) / 2
	dirs := [5]int{-1, 0, 1, 0, -1}

	f := func(i, j int) int64 {
		return int64(i*n + j)
	}

	s := make(map[int64]bool)
	for _, b := range blocked {
		s[f(b[0], b[1])] = true
	}

	var dfs func(sx, sy, tx, ty int, vis map[int64]bool) bool
	dfs = func(sx, sy, tx, ty int, vis map[int64]bool) bool {
		key := f(sx, sy)
		vis[key] = true
		if len(vis) > m {
			return true
		}
		for k := 0; k < 4; k++ {
			x, y := sx+dirs[k], sy+dirs[k+1]
			if x >= 0 && x < n && y >= 0 && y < n {
				if x == tx && y == ty {
					return true
				}
				key := f(x, y)
				if !s[key] && !vis[key] && dfs(x, y, tx, ty, vis) {
					return true
				}
			}
		}
		return false
	}

	sx, sy := source[0], source[1]
	tx, ty := target[0], target[1]
	return dfs(sx, sy, tx, ty, map[int64]bool{}) && dfs(tx, ty, sx, sy, map[int64]bool{})
}
```

#### TypeScript

```ts
function isEscapePossible(blocked: number[][], source: number[], target: number[]): boolean {
    const n = 10 ** 6;
    const m = (blocked.length ** 2) >> 1;
    const dirs = [-1, 0, 1, 0, -1];

    const s = new Set<number>();
    const f = (i: number, j: number): number => i * n + j;

    for (const [x, y] of blocked) {
        s.add(f(x, y));
    }

    const dfs = (sx: number, sy: number, tx: number, ty: number, vis: Set<number>): boolean => {
        vis.add(f(sx, sy));
        if (vis.size > m) {
            return true;
        }
        for (let k = 0; k < 4; k++) {
            const x = sx + dirs[k],
                y = sy + dirs[k + 1];
            if (x >= 0 && x < n && y >= 0 && y < n) {
                if (x === tx && y === ty) {
                    return true;
                }
                const key = f(x, y);
                if (!s.has(key) && !vis.has(key) && dfs(x, y, tx, ty, vis)) {
                    return true;
                }
            }
        }
        return false;
    };

    return (
        dfs(source[0], source[1], target[0], target[1], new Set()) &&
        dfs(target[0], target[1], source[0], source[1], new Set())
    );
}
```

#### Rust

```rust
use std::collections::HashSet;

impl Solution {
    pub fn is_escape_possible(blocked: Vec<Vec<i32>>, source: Vec<i32>, target: Vec<i32>) -> bool {
        const N: i64 = 1_000_000;
        let m = (blocked.len() * blocked.len()) as i64 / 2;

        let f = |i: i64, j: i64| -> i64 { i * N + j };

        let mut s: HashSet<i64> = HashSet::new();
        for b in &blocked {
            s.insert(f(b[0] as i64, b[1] as i64));
        }

        fn dfs(
            sx: i64,
            sy: i64,
            tx: i64,
            ty: i64,
            s: &HashSet<i64>,
            m: i64,
            vis: &mut HashSet<i64>,
        ) -> bool {
            static DIRS: [i64; 5] = [-1, 0, 1, 0, -1];
            let key = sx * 1_000_000 + sy;
            vis.insert(key);
            if vis.len() as i64 > m {
                return true;
            }
            for k in 0..4 {
                let x = sx + DIRS[k];
                let y = sy + DIRS[k + 1];
                let key = x * 1_000_000 + y;
                if x >= 0 && x < 1_000_000 && y >= 0 && y < 1_000_000 {
                    if x == tx && y == ty {
                        return true;
                    }
                    if !s.contains(&key) && vis.insert(key) && dfs(x, y, tx, ty, s, m, vis) {
                        return true;
                    }
                }
            }
            false
        }

        dfs(
            source[0] as i64,
            source[1] as i64,
            target[0] as i64,
            target[1] as i64,
            &s,
            m,
            &mut HashSet::new(),
        ) && dfs(
            target[0] as i64,
            target[1] as i64,
            source[0] as i64,
            source[1] as i64,
            &s,
            m,
            &mut HashSet::new(),
        )
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1037. 有效的回旋镖](https://leetcode.cn/problems/valid-boomerang){#1037}

{{< tabs "1037" >}}

{{% tab "python" %}}
```python
class Solution:
    def isBoomerang(self, points: List[List[int]]) -> bool:
        (x1, y1), (x2, y2), (x3, y3) = points
        return (y2 - y1) * (x3 - x2) != (y3 - y2) * (x2 - x1)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean isBoomerang(int[][] points) {
        int x1 = points[0][0], y1 = points[0][1];
        int x2 = points[1][0], y2 = points[1][1];
        int x3 = points[2][0], y3 = points[2][1];
        return (y2 - y1) * (x3 - x2) != (y3 - y2) * (x2 - x1);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        int x1 = points[0][0], y1 = points[0][1];
        int x2 = points[1][0], y2 = points[1][1];
        int x3 = points[2][0], y3 = points[2][1];
        return (y2 - y1) * (x3 - x2) != (y3 - y2) * (x2 - x1);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func isBoomerang(points [][]int) bool {
	x1, y1 := points[0][0], points[0][1]
	x2, y2 := points[1][0], points[1][1]
	x3, y3 := points[2][0], points[2][1]
	return (y2-y1)*(x3-x2) != (y3-y2)*(x2-x1)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function isBoomerang(points: number[][]): boolean {
    const [x1, y1] = points[0];
    const [x2, y2] = points[1];
    const [x3, y3] = points[2];
    return (x1 - x2) * (y2 - y3) !== (x2 - x3) * (y1 - y2);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn is_boomerang(points: Vec<Vec<i32>>) -> bool {
        let (x1, y1) = (points[0][0], points[0][1]);
        let (x2, y2) = (points[1][0], points[1][1]);
        let (x3, y3) = (points[2][0], points[2][1]);
        (x1 - x2) * (y2 - y3) != (x2 - x3) * (y1 - y2)
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个数组<meta charset="UTF-8" />&nbsp;<code>points</code>&nbsp;，其中<meta charset="UTF-8" />&nbsp;<code>points[i] = [x<sub>i</sub>, y<sub>i</sub>]</code>&nbsp;表示 <strong>X-Y</strong> 平面上的一个点，<em>如果这些点构成一个&nbsp;</em><strong>回旋镖</strong>&nbsp;则返回&nbsp;<code>true</code>&nbsp;。</p>

<p><strong>回旋镖</strong>&nbsp;定义为一组三个点，这些点&nbsp;<strong>各不相同</strong>&nbsp;且&nbsp;<strong>不在一条直线上</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>points = [[1,1],[2,3],[3,2]]
<strong>输出：</strong>true
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>points = [[1,1],[2,2],[3,3]]
<strong>输出：</strong>false</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>
<meta charset="UTF-8" />

<ul>
	<li><code>points.length == 3</code></li>
	<li><code>points[i].length == 2</code></li>
	<li><code>0 &lt;= x<sub>i</sub>, y<sub>i</sub>&nbsp;&lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：斜率比较

设三点分别为 $(x_1,y_1)$, $(x_2,y_2)$, $(x_3,y_3)$。两点之间斜率计算公式为 $\frac{y_2-y_1}{x_2-x_1}$。

要使得三点不共线，需要满足 $\frac{y_2-y_1}{x_2-x_1}\neq\frac{y_3-y_2}{x_3-x_2}$，我们将式子变形得到 $(y_2-y_1)*(x_3-x_2) \neq (y_3-y_2)*(x_2-x_1)$。

注意：

1. 当两点之间斜率不存在，即 $x_1=x_2$，上述变式仍然成立；
2. 若斜率除法运算比较存在精度问题，同样可以变换为乘法。

时间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def isBoomerang(self, points: List[List[int]]) -> bool:
        (x1, y1), (x2, y2), (x3, y3) = points
        return (y2 - y1) * (x3 - x2) != (y3 - y2) * (x2 - x1)
```

#### Java

```java
class Solution {
    public boolean isBoomerang(int[][] points) {
        int x1 = points[0][0], y1 = points[0][1];
        int x2 = points[1][0], y2 = points[1][1];
        int x3 = points[2][0], y3 = points[2][1];
        return (y2 - y1) * (x3 - x2) != (y3 - y2) * (x2 - x1);
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        int x1 = points[0][0], y1 = points[0][1];
        int x2 = points[1][0], y2 = points[1][1];
        int x3 = points[2][0], y3 = points[2][1];
        return (y2 - y1) * (x3 - x2) != (y3 - y2) * (x2 - x1);
    }
};
```

#### Go

```go
func isBoomerang(points [][]int) bool {
	x1, y1 := points[0][0], points[0][1]
	x2, y2 := points[1][0], points[1][1]
	x3, y3 := points[2][0], points[2][1]
	return (y2-y1)*(x3-x2) != (y3-y2)*(x2-x1)
}
```

#### TypeScript

```ts
function isBoomerang(points: number[][]): boolean {
    const [x1, y1] = points[0];
    const [x2, y2] = points[1];
    const [x3, y3] = points[2];
    return (x1 - x2) * (y2 - y3) !== (x2 - x3) * (y1 - y2);
}
```

#### Rust

```rust
impl Solution {
    pub fn is_boomerang(points: Vec<Vec<i32>>) -> bool {
        let (x1, y1) = (points[0][0], points[0][1]);
        let (x2, y2) = (points[1][0], points[1][1]);
        let (x3, y3) = (points[2][0], points[2][1]);
        (x1 - x2) * (y2 - y3) != (x2 - x3) * (y1 - y2)
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1038. 从二叉搜索树到更大和树](https://leetcode.cn/problems/binary-search-tree-to-greater-sum-tree){#1038}

{{< tabs "1038" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def bstToGst(self, root: TreeNode) -> TreeNode:
        s = 0
        node = root
        while root:
            if root.right is None:
                s += root.val
                root.val = s
                root = root.left
            else:
                next = root.right
                while next.left and next.left != root:
                    next = next.left
                if next.left is None:
                    next.left = root
                    root = root.right
                else:
                    s += root.val
                    root.val = s
                    next.left = None
                    root = root.left
        return node
```
{{% /tab %}}
{{% tab "java" %}}
```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public TreeNode bstToGst(TreeNode root) {
        int s = 0;
        TreeNode node = root;
        while (root != null) {
            if (root.right == null) {
                s += root.val;
                root.val = s;
                root = root.left;
            } else {
                TreeNode next = root.right;
                while (next.left != null && next.left != root) {
                    next = next.left;
                }
                if (next.left == null) {
                    next.left = root;
                    root = root.right;
                } else {
                    s += root.val;
                    root.val = s;
                    next.left = null;
                    root = root.left;
                }
            }
        }
        return node;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        int s = 0;
        TreeNode* node = root;
        while (root) {
            if (root->right == nullptr) {
                s += root->val;
                root->val = s;
                root = root->left;
            } else {
                TreeNode* next = root->right;
                while (next->left && next->left != root) {
                    next = next->left;
                }
                if (next->left == nullptr) {
                    next->left = root;
                    root = root->right;
                } else {
                    s += root->val;
                    root->val = s;
                    next->left = nullptr;
                    root = root->left;
                }
            }
        }
        return node;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func bstToGst(root *TreeNode) *TreeNode {
	s := 0
	node := root
	for root != nil {
		if root.Right == nil {
			s += root.Val
			root.Val = s
			root = root.Left
		} else {
			next := root.Right
			for next.Left != nil && next.Left != root {
				next = next.Left
			}
			if next.Left == nil {
				next.Left = root
				root = root.Right
			} else {
				s += root.Val
				root.Val = s
				next.Left = nil
				root = root.Left
			}
		}
	}
	return node
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function bstToGst(root: TreeNode | null): TreeNode | null {
    let cur = root;
    let sum = 0;
    while (cur != null) {
        const { val, left, right } = cur;
        if (right == null) {
            sum += val;
            cur.val = sum;
            cur = left;
        } else {
            let next = right;
            while (next.left != null && next.left != cur) {
                next = next.left;
            }
            if (next.left == null) {
                next.left = cur;
                cur = right;
            } else {
                next.left = null;
                sum += val;
                cur.val = sum;
                cur = left;
            }
        }
    }
    return root;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
//
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::rc::Rc;
use std::cell::RefCell;

impl Solution {
    pub fn bst_to_gst(root: Option<Rc<RefCell<TreeNode>>>) -> Option<Rc<RefCell<TreeNode>>> {
        let mut s = 0;
        Self::dfs(&root, &mut s);
        root
    }

    fn dfs(root: &Option<Rc<RefCell<TreeNode>>>, s: &mut i32) {
        if let Some(node) = root {
            let mut node = node.borrow_mut();
            Self::dfs(&node.right, s);
            *s += node.val;
            node.val = *s;
            Self::dfs(&node.left, s);
        }
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {TreeNode}
 */
var bstToGst = function (root) {
    let s = 0;
    function dfs(root) {
        if (!root) {
            return;
        }
        dfs(root.right);
        s += root.val;
        root.val = s;
        dfs(root.left);
    }
    dfs(root);
    return root;
};
```
{{% /tab %}}
{{% tab "c" %}}
```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* bstToGst(struct TreeNode* root) {
    struct TreeNode* cur = root;
    int sum = 0;
    while (cur) {
        if (!cur->right) {
            sum += cur->val;
            cur->val = sum;
            cur = cur->left;
        } else {
            struct TreeNode* next = cur->right;
            while (next->left && next->left != cur) {
                next = next->left;
            }
            if (!next->left) {
                next->left = cur;
                cur = cur->right;
            } else {
                next->left = NULL;
                sum += cur->val;
                cur->val = sum;
                cur = cur->left;
            }
        }
    }
    return root;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p><span style="font-size:10.5pt"><span style="font-family:Calibri"><span style="font-size:10.5000pt"><span style="font-family:宋体"><font face="宋体">给定一个二叉搜索树</font></span></span></span></span>&nbsp;<code>root</code>&nbsp;(BST)<span style="font-size:10.5pt"><span style="font-family:Calibri"><span style="font-size:10.5000pt"><span style="font-family:宋体"><font face="宋体">，请将它的每个</font></span></span></span></span>节点<span style="font-size:10.5pt"><span style="font-family:Calibri"><span style="font-size:10.5000pt"><span style="font-family:宋体"><font face="宋体">的值替换成树中大于或者等于该</font></span></span></span></span>节点<span style="font-size:10.5pt"><span style="font-family:Calibri"><span style="font-size:10.5000pt"><span style="font-family:宋体"><font face="宋体">值的所有</font></span></span></span></span>节点<span style="font-size:10.5pt"><span style="font-family:Calibri"><span style="font-size:10.5000pt"><span style="font-family:宋体"><font face="宋体">值之和。</font></span></span></span></span></p>

<p>提醒一下， <em>二叉搜索树</em> 满足下列约束条件：</p>

<ul>
	<li>节点的左子树仅包含键<strong> 小于 </strong>节点键的节点。</li>
	<li>节点的右子树仅包含键<strong> 大于</strong> 节点键的节点。</li>
	<li>左右子树也必须是二叉搜索树。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1000-1099/1038.Binary%20Search%20Tree%20to%20Greater%20Sum%20Tree/images/tree.png" style="height:273px; width:400px" /></strong></p>

<pre>
<strong>输入：</strong>[4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
<strong>输出：</strong>[30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>root = [0,null,1]
<strong>输出：</strong>[1,null,1]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中的节点数在&nbsp;<code>[1, 100]</code>&nbsp;范围内。</li>
	<li><code>0 &lt;= Node.val &lt;= 100</code></li>
	<li>树中的所有值均 <strong>不重复</strong>&nbsp;。</li>
</ul>

<p>&nbsp;</p>

<p><strong>注意：</strong>该题目与 538:&nbsp;<a href="https://leetcode.cn/problems/convert-bst-to-greater-tree/">https://leetcode.cn/problems/convert-bst-to-greater-tree/&nbsp; </a>相同</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：递归

按照“右根左”的顺序，递归遍历二叉搜索树，累加遍历到的所有节点值到 $s$ 中，然后每次赋值给对应的 `node` 节点。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是二叉搜索树的节点数。

<!-- tabs:start -->

#### Python3

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def bstToGst(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        def dfs(root: Optional[TreeNode]):
            if root is None:
                return
            dfs(root.right)
            nonlocal s
            s += root.val
            root.val = s
            dfs(root.left)

        s = 0
        dfs(root)
        return root
```

#### Java

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private int s;

    public TreeNode bstToGst(TreeNode root) {
        dfs(root);
        return root;
    }

    private void dfs(TreeNode root) {
        if (root == null) {
            return;
        }
        dfs(root.right);
        s += root.val;
        root.val = s;
        dfs(root.left);
    }
}
```

#### C++

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        int s = 0;
        auto dfs = [&](this auto&& dfs, TreeNode* root) {
            if (!root) {
                return;
            }
            dfs(root->right);
            s += root->val;
            root->val = s;
            dfs(root->left);
        };
        dfs(root);
        return root;
    }
};
```

#### Go

```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func bstToGst(root *TreeNode) *TreeNode {
	s := 0
	var dfs func(*TreeNode)
	dfs = func(root *TreeNode) {
		if root == nil {
			return
		}
		dfs(root.Right)
		s += root.Val
		root.Val = s
		dfs(root.Left)
	}
	dfs(root)
	return root
}
```

#### TypeScript

```ts
/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function bstToGst(root: TreeNode | null): TreeNode | null {
    let s = 0;
    const dfs = (root: TreeNode | null) => {
        if (!root) {
            return;
        }
        dfs(root.right);
        s += root.val;
        root.val = s;
        dfs(root.left);
    };
    dfs(root);
    return root;
}
```

#### Rust

```rust
// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
//
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::rc::Rc;
use std::cell::RefCell;

impl Solution {
    pub fn bst_to_gst(root: Option<Rc<RefCell<TreeNode>>>) -> Option<Rc<RefCell<TreeNode>>> {
        let mut s = 0;
        Self::dfs(&root, &mut s);
        root
    }

    fn dfs(root: &Option<Rc<RefCell<TreeNode>>>, s: &mut i32) {
        if let Some(node) = root {
            let mut node = node.borrow_mut();
            Self::dfs(&node.right, s);
            *s += node.val;
            node.val = *s;
            Self::dfs(&node.left, s);
        }
    }
}
```

#### JavaScript

```js
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {TreeNode}
 */
var bstToGst = function (root) {
    let s = 0;
    function dfs(root) {
        if (!root) {
            return;
        }
        dfs(root.right);
        s += root.val;
        root.val = s;
        dfs(root.left);
    }
    dfs(root);
    return root;
};
```

#### C

```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int dfs(struct TreeNode* root, int sum) {
    if (root) {
        sum = dfs(root->right, sum) + root->val;
        root->val = sum;
        sum = dfs(root->left, sum);
    }
    return sum;
}

struct TreeNode* bstToGst(struct TreeNode* root) {
    dfs(root, 0);
    return root;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：Morris 遍历

Morris 遍历无需使用栈，时间复杂度 $O(n)$，空间复杂度为 $O(1)$。核心思想是：

定义 s 表示二叉搜索树节点值累加和。遍历二叉树节点：

1. 若当前节点 root 的右子树为空，**将当前节点值添加至 s** 中，更新当前节点值为 s，并将当前节点更新为 `root.left`。
2. 若当前节点 root 的右子树不为空，找到右子树的最左节点 next（也即是 root 节点在中序遍历下的后继节点）：
    - 若后继节点 next 的左子树为空，将后继节点的左子树指向当前节点 root，并将当前节点更新为 `root.right`。
    - 若后继节点 next 的左子树不为空，**将当前节点值添加 s** 中，更新当前节点值为 s，然后将后继节点左子树指向空（即解除 next 与 root 的指向关系），并将当前节点更新为 `root.left`。
3. 循环以上步骤，直至二叉树节点为空，遍历结束。
4. 最后返回二叉搜索树根节点即可。

> Morris 反序中序遍历跟 Morris 中序遍历思路一致，只是将中序遍历的“左根右”变为“右根左”。

<!-- tabs:start -->

#### Python3

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def bstToGst(self, root: TreeNode) -> TreeNode:
        s = 0
        node = root
        while root:
            if root.right is None:
                s += root.val
                root.val = s
                root = root.left
            else:
                next = root.right
                while next.left and next.left != root:
                    next = next.left
                if next.left is None:
                    next.left = root
                    root = root.right
                else:
                    s += root.val
                    root.val = s
                    next.left = None
                    root = root.left
        return node
```

#### Java

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public TreeNode bstToGst(TreeNode root) {
        int s = 0;
        TreeNode node = root;
        while (root != null) {
            if (root.right == null) {
                s += root.val;
                root.val = s;
                root = root.left;
            } else {
                TreeNode next = root.right;
                while (next.left != null && next.left != root) {
                    next = next.left;
                }
                if (next.left == null) {
                    next.left = root;
                    root = root.right;
                } else {
                    s += root.val;
                    root.val = s;
                    next.left = null;
                    root = root.left;
                }
            }
        }
        return node;
    }
}
```

#### C++

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        int s = 0;
        TreeNode* node = root;
        while (root) {
            if (root->right == nullptr) {
                s += root->val;
                root->val = s;
                root = root->left;
            } else {
                TreeNode* next = root->right;
                while (next->left && next->left != root) {
                    next = next->left;
                }
                if (next->left == nullptr) {
                    next->left = root;
                    root = root->right;
                } else {
                    s += root->val;
                    root->val = s;
                    next->left = nullptr;
                    root = root->left;
                }
            }
        }
        return node;
    }
};
```

#### Go

```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func bstToGst(root *TreeNode) *TreeNode {
	s := 0
	node := root
	for root != nil {
		if root.Right == nil {
			s += root.Val
			root.Val = s
			root = root.Left
		} else {
			next := root.Right
			for next.Left != nil && next.Left != root {
				next = next.Left
			}
			if next.Left == nil {
				next.Left = root
				root = root.Right
			} else {
				s += root.Val
				root.Val = s
				next.Left = nil
				root = root.Left
			}
		}
	}
	return node
}
```

#### TypeScript

```ts
/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function bstToGst(root: TreeNode | null): TreeNode | null {
    let cur = root;
    let sum = 0;
    while (cur != null) {
        const { val, left, right } = cur;
        if (right == null) {
            sum += val;
            cur.val = sum;
            cur = left;
        } else {
            let next = right;
            while (next.left != null && next.left != cur) {
                next = next.left;
            }
            if (next.left == null) {
                next.left = cur;
                cur = right;
            } else {
                next.left = null;
                sum += val;
                cur.val = sum;
                cur = left;
            }
        }
    }
    return root;
}
```

#### C

```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* bstToGst(struct TreeNode* root) {
    struct TreeNode* cur = root;
    int sum = 0;
    while (cur) {
        if (!cur->right) {
            sum += cur->val;
            cur->val = sum;
            cur = cur->left;
        } else {
            struct TreeNode* next = cur->right;
            while (next->left && next->left != cur) {
                next = next->left;
            }
            if (!next->left) {
                next->left = cur;
                cur = cur->right;
            } else {
                next->left = NULL;
                sum += cur->val;
                cur->val = sum;
                cur = cur->left;
            }
        }
    }
    return root;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1039. 多边形三角剖分的最低得分](https://leetcode.cn/problems/minimum-score-triangulation-of-polygon){#1039}

{{< tabs "1039" >}}

{{% tab "python" %}}
```python
class Solution:
    def minScoreTriangulation(self, values: List[int]) -> int:
        n = len(values)
        f = [[0] * n for _ in range(n)]
        for l in range(3, n + 1):
            for i in range(n - l + 1):
                j = i + l - 1
                f[i][j] = min(
                    f[i][k] + f[k][j] + values[i] * values[k] * values[j]
                    for k in range(i + 1, j)
                )
        return f[0][-1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minScoreTriangulation(int[] values) {
        int n = values.length;
        int[][] f = new int[n][n];
        for (int l = 3; l <= n; ++l) {
            for (int i = 0; i + l - 1 < n; ++i) {
                int j = i + l - 1;
                f[i][j] = 1 << 30;
                for (int k = i + 1; k < j; ++k) {
                    f[i][j]
                        = Math.min(f[i][j], f[i][k] + f[k][j] + values[i] * values[k] * values[j]);
                }
            }
        }
        return f[0][n - 1];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        int f[n][n];
        memset(f, 0, sizeof(f));
        for (int l = 3; l <= n; ++l) {
            for (int i = 0; i + l - 1 < n; ++i) {
                int j = i + l - 1;
                f[i][j] = 1 << 30;
                for (int k = i + 1; k < j; ++k) {
                    f[i][j] = min(f[i][j], f[i][k] + f[k][j] + values[i] * values[k] * values[j]);
                }
            }
        }
        return f[0][n - 1];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minScoreTriangulation(values []int) int {
	n := len(values)
	f := [50][50]int{}
	for l := 3; l <= n; l++ {
		for i := 0; i+l-1 < n; i++ {
			j := i + l - 1
			f[i][j] = 1 << 30
			for k := i + 1; k < j; k++ {
				f[i][j] = min(f[i][j], f[i][k]+f[k][j]+values[i]*values[k]*values[j])
			}
		}
	}
	return f[0][n-1]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minScoreTriangulation(values: number[]): number {
    const n = values.length;
    const f: number[][] = Array.from({ length: n }, () => Array.from({ length: n }, () => 0));
    for (let l = 3; l <= n; ++l) {
        for (let i = 0; i + l - 1 < n; ++i) {
            const j = i + l - 1;
            f[i][j] = 1 << 30;
            for (let k = i + 1; k < j; ++k) {
                f[i][j] = Math.min(f[i][j], f[i][k] + f[k][j] + values[i] * values[k] * values[j]);
            }
        }
    }
    return f[0][n - 1];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你有一个凸的<meta charset="UTF-8" />&nbsp;<code>n</code>&nbsp;边形，其每个顶点都有一个整数值。给定一个整数数组<meta charset="UTF-8" />&nbsp;<code>values</code>&nbsp;，其中<meta charset="UTF-8" />&nbsp;<code>values[i]</code>&nbsp;是第 <code>i</code> 个顶点的值（即 <strong>顺时针顺序</strong> ）。</p>

<p>假设将多边形 <strong>剖分</strong>&nbsp;为 <code>n - 2</code>&nbsp;个三角形。对于每个三角形，该三角形的值是顶点标记的<strong>乘积</strong>，三角剖分的分数是进行三角剖分后所有 <code>n - 2</code>&nbsp;个三角形的值之和。</p>

<p>返回 <em>多边形进行三角剖分后可以得到的最低分</em> 。<br />
&nbsp;</p>

<ol>
</ol>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1000-1099/1039.Minimum%20Score%20Triangulation%20of%20Polygon/images/shape1.jpg" /></p>

<pre>
<strong>输入：</strong>values = [1,2,3]
<strong>输出：</strong>6
<strong>解释：</strong>多边形已经三角化，唯一三角形的分数为 6。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1000-1099/1039.Minimum%20Score%20Triangulation%20of%20Polygon/images/shape2.jpg" style="height: 163px; width: 446px;" /></p>

<pre>
<strong>输入：</strong>values = [3,7,4,5]
<strong>输出：</strong>144
<strong>解释：</strong>有两种三角剖分，可能得分分别为：3*7*5 + 4*5*7 = 245，或 3*4*5 + 3*4*7 = 144。最低分数为 144。
</pre>

<p><strong>示例 3：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1000-1099/1039.Minimum%20Score%20Triangulation%20of%20Polygon/images/shape3.jpg" /></p>

<pre>
<strong>输入：</strong>values = [1,3,1,4,1,5]
<strong>输出：</strong>13
<strong>解释：</strong>最低分数三角剖分的得分情况为 1*1*3 + 1*1*4 + 1*1*5 + 1*1*1 = 13。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == values.length</code></li>
	<li><code>3 &lt;= n &lt;= 50</code></li>
	<li><code>1 &lt;= values[i] &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

我们设计一个函数 $\text{dfs}(i, j)$，表示将多边形的顶点 $i$ 到 $j$ 进行三角剖分后的最低分数。那么答案就是 $\text{dfs}(0, n - 1)$。

函数 $\text{dfs}(i, j)$ 的计算过程如下：

如果 $i + 1 = j$，说明多边形只有两个顶点，无法进行三角剖分，返回 $0$；

否则，我们枚举 $i$ 和 $j$ 之间的一个顶点 $k$，即 $i \lt k \lt j$，将多边形的顶点 $i$ 到 $j$ 进行三角剖分，可以分为两个子问题：将多边形的顶点 $i$ 到 $k$ 进行三角剖分，以及将多边形的顶点 $k$ 到 $j$ 进行三角剖分。这两个子问题的最低分数分别为 $\text{dfs}(i, k)$ 和 $\text{dfs}(k, j)$，而顶点 $i$, $j$ 和 $k$ 构成的三角形的分数为 $\text{values}[i] \times \text{values}[k] \times \text{values}[j]$。那么，此次三角剖分的最低分数为 $\text{dfs}(i, k) + \text{dfs}(k, j) + \text{values}[i] \times \text{values}[k] \times \text{values}[j]$，我们取所有可能的最小值，即为 $\text{dfs}(i, j)$ 的值。

为了避免重复计算，我们可以使用记忆化搜索，即使用哈希表或者数组来存储已经计算过的函数值。

最后，我们返回 $\text{dfs}(0, n - 1)$ 即可。

时间复杂度 $O(n^3)$，空间复杂度 $O(n^2)$。其中 $n$ 为多边形的顶点数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minScoreTriangulation(self, values: List[int]) -> int:
        @cache
        def dfs(i: int, j: int) -> int:
            if i + 1 == j:
                return 0
            return min(
                dfs(i, k) + dfs(k, j) + values[i] * values[k] * values[j]
                for k in range(i + 1, j)
            )

        return dfs(0, len(values) - 1)
```

#### Java

```java
class Solution {
    private int n;
    private int[] values;
    private Integer[][] f;

    public int minScoreTriangulation(int[] values) {
        n = values.length;
        this.values = values;
        f = new Integer[n][n];
        return dfs(0, n - 1);
    }

    private int dfs(int i, int j) {
        if (i + 1 == j) {
            return 0;
        }
        if (f[i][j] != null) {
            return f[i][j];
        }
        int ans = 1 << 30;
        for (int k = i + 1; k < j; ++k) {
            ans = Math.min(ans, dfs(i, k) + dfs(k, j) + values[i] * values[k] * values[j]);
        }
        return f[i][j] = ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        int f[n][n];
        memset(f, 0, sizeof(f));
        function<int(int, int)> dfs = [&](int i, int j) -> int {
            if (i + 1 == j) {
                return 0;
            }
            if (f[i][j]) {
                return f[i][j];
            }
            int ans = 1 << 30;
            for (int k = i + 1; k < j; ++k) {
                ans = min(ans, dfs(i, k) + dfs(k, j) + values[i] * values[k] * values[j]);
            }
            return f[i][j] = ans;
        };
        return dfs(0, n - 1);
    }
};
```

#### Go

```go
func minScoreTriangulation(values []int) int {
	n := len(values)
	f := [50][50]int{}
	var dfs func(int, int) int
	dfs = func(i, j int) int {
		if i+1 == j {
			return 0
		}
		if f[i][j] != 0 {
			return f[i][j]
		}
		f[i][j] = 1 << 30
		for k := i + 1; k < j; k++ {
			f[i][j] = min(f[i][j], dfs(i, k)+dfs(k, j)+values[i]*values[k]*values[j])
		}
		return f[i][j]
	}
	return dfs(0, n-1)
}
```

#### TypeScript

```ts
function minScoreTriangulation(values: number[]): number {
    const n = values.length;
    const f: number[][] = Array.from({ length: n }, () => Array.from({ length: n }, () => 0));
    const dfs = (i: number, j: number): number => {
        if (i + 1 === j) {
            return 0;
        }
        if (f[i][j] > 0) {
            return f[i][j];
        }
        let ans = 1 << 30;
        for (let k = i + 1; k < j; ++k) {
            ans = Math.min(ans, dfs(i, k) + dfs(k, j) + values[i] * values[k] * values[j]);
        }
        f[i][j] = ans;
        return ans;
    };
    return dfs(0, n - 1);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：动态规划

我们可以将方法一中的记忆化搜索改为动态规划。

定义 $f[i][j]$ 表示将多边形的顶点 $i$ 到 $j$ 进行三角剖分后的最低分数。初始时 $f[i][j]=0$，答案为 $f[0][n-1]$。

对于 $f[i][j]$（这里要求 $i + 1 \lt j$），我们先将 $f[i][j]$ 初始化为 $\infty$。

我们枚举 $i$ 和 $j$ 之间的一个顶点 $k$，即 $i \lt k \lt j$，将多边形的顶点 $i$ 到 $j$ 进行三角剖分，可以分为两个子问题：将多边形的顶点 $i$ 到 $k$ 进行三角剖分，以及将多边形的顶点 $k$ 到 $j$ 进行三角剖分。这两个子问题的最低分数分别为 $f[i][k]$ 和 $f[k][j]$，而顶点 $i$, $j$ 和 $k$ 构成的三角形的分数为 $\text{values}[i] \times \text{values}[k] \times \text{values}[j]$。那么，此次三角剖分的最低分数为 $f[i][k] + f[k][j] + \text{values}[i] \times \text{values}[k] \times \text{values}[j]$，我们取所有可能的最小值，即为 $f[i][j]$ 的值。

综上，我们可以得到状态转移方程：

$$
f[i][j]=
\begin{cases}
0, & i+1=j \\
\infty, & i+1<j \\
\min_{i<k<j} \{f[i][k]+f[k][j]+\text{values}[i] \times \text{values}[k] \times \text{values}[j]\}, & i+1<j
\end{cases}
$$

注意，在枚举 $i$ 和 $j$ 时，我们可以有两种枚举方式：

1. 从大到小枚举 $i$，从小到大枚举 $j$，这样可以保证在计算状态 $f[i][j]$ 时，状态 $f[i][k]$ 和 $f[k][j]$ 都已经计算过了；
1. 从小到大枚举区间长度 $l$，其中 $3 \leq l \leq n$，然后枚举区间左端点 $i$，那么可以得到右端点 $j=i + l - 1$，这样也可以保证在计算较大区间 $f[i][j]$ 时，较小区间 $f[i][k]$ 和 $f[k][j]$ 都已经计算过了。

最后，我们返回 $f[0][n-1]$ 即可。

时间复杂度 $O(n^3)$，空间复杂度 $O(n^2)$。其中 $n$ 为多边形的顶点数。

相似题目：

-   [1312. 让字符串成为回文串的最少插入次数](https://github.com/doocs/leetcode/blob/main/solution/1300-1399/1312.Minimum%20Insertion%20Steps%20to%20Make%20a%20String%20Palindrome/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minScoreTriangulation(self, values: List[int]) -> int:
        n = len(values)
        f = [[0] * n for _ in range(n)]
        for i in range(n - 3, -1, -1):
            for j in range(i + 2, n):
                f[i][j] = min(
                    f[i][k] + f[k][j] + values[i] * values[k] * values[j]
                    for k in range(i + 1, j)
                )
        return f[0][-1]
```

#### Java

```java
class Solution {
    public int minScoreTriangulation(int[] values) {
        int n = values.length;
        int[][] f = new int[n][n];
        for (int i = n - 3; i >= 0; --i) {
            for (int j = i + 2; j < n; ++j) {
                f[i][j] = 1 << 30;
                for (int k = i + 1; k < j; ++k) {
                    f[i][j]
                        = Math.min(f[i][j], f[i][k] + f[k][j] + values[i] * values[k] * values[j]);
                }
            }
        }
        return f[0][n - 1];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        int f[n][n];
        memset(f, 0, sizeof(f));
        for (int i = n - 3; i >= 0; --i) {
            for (int j = i + 2; j < n; ++j) {
                f[i][j] = 1 << 30;
                for (int k = i + 1; k < j; ++k) {
                    f[i][j] = min(f[i][j], f[i][k] + f[k][j] + values[i] * values[k] * values[j]);
                }
            }
        }
        return f[0][n - 1];
    }
};
```

#### Go

```go
func minScoreTriangulation(values []int) int {
	n := len(values)
	f := [50][50]int{}
	for i := n - 3; i >= 0; i-- {
		for j := i + 2; j < n; j++ {
			f[i][j] = 1 << 30
			for k := i + 1; k < j; k++ {
				f[i][j] = min(f[i][j], f[i][k]+f[k][j]+values[i]*values[k]*values[j])
			}
		}
	}
	return f[0][n-1]
}
```

#### TypeScript

```ts
function minScoreTriangulation(values: number[]): number {
    const n = values.length;
    const f: number[][] = Array.from({ length: n }, () => Array.from({ length: n }, () => 0));
    for (let i = n - 3; i >= 0; --i) {
        for (let j = i + 2; j < n; ++j) {
            f[i][j] = 1 << 30;
            for (let k = i + 1; k < j; ++k) {
                f[i][j] = Math.min(f[i][j], f[i][k] + f[k][j] + values[i] * values[k] * values[j]);
            }
        }
    }
    return f[0][n - 1];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法三：动态规划（另一种实现方式）

方法二中，我们提到了两种枚举方式。这里我们使用第二种方式，从小到大枚举区间长度 $l$，其中 $3 \leq l \leq n$，然后枚举区间左端点 $i$，那么可以得到右端点 $j=i + l - 1$。

时间复杂度 $O(n^3)$，空间复杂度 $O(n^2)$。其中 $n$ 为多边形的顶点数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minScoreTriangulation(self, values: List[int]) -> int:
        n = len(values)
        f = [[0] * n for _ in range(n)]
        for l in range(3, n + 1):
            for i in range(n - l + 1):
                j = i + l - 1
                f[i][j] = min(
                    f[i][k] + f[k][j] + values[i] * values[k] * values[j]
                    for k in range(i + 1, j)
                )
        return f[0][-1]
```

#### Java

```java
class Solution {
    public int minScoreTriangulation(int[] values) {
        int n = values.length;
        int[][] f = new int[n][n];
        for (int l = 3; l <= n; ++l) {
            for (int i = 0; i + l - 1 < n; ++i) {
                int j = i + l - 1;
                f[i][j] = 1 << 30;
                for (int k = i + 1; k < j; ++k) {
                    f[i][j]
                        = Math.min(f[i][j], f[i][k] + f[k][j] + values[i] * values[k] * values[j]);
                }
            }
        }
        return f[0][n - 1];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        int f[n][n];
        memset(f, 0, sizeof(f));
        for (int l = 3; l <= n; ++l) {
            for (int i = 0; i + l - 1 < n; ++i) {
                int j = i + l - 1;
                f[i][j] = 1 << 30;
                for (int k = i + 1; k < j; ++k) {
                    f[i][j] = min(f[i][j], f[i][k] + f[k][j] + values[i] * values[k] * values[j]);
                }
            }
        }
        return f[0][n - 1];
    }
};
```

#### Go

```go
func minScoreTriangulation(values []int) int {
	n := len(values)
	f := [50][50]int{}
	for l := 3; l <= n; l++ {
		for i := 0; i+l-1 < n; i++ {
			j := i + l - 1
			f[i][j] = 1 << 30
			for k := i + 1; k < j; k++ {
				f[i][j] = min(f[i][j], f[i][k]+f[k][j]+values[i]*values[k]*values[j])
			}
		}
	}
	return f[0][n-1]
}
```

#### TypeScript

```ts
function minScoreTriangulation(values: number[]): number {
    const n = values.length;
    const f: number[][] = Array.from({ length: n }, () => Array.from({ length: n }, () => 0));
    for (let l = 3; l <= n; ++l) {
        for (let i = 0; i + l - 1 < n; ++i) {
            const j = i + l - 1;
            f[i][j] = 1 << 30;
            for (let k = i + 1; k < j; ++k) {
                f[i][j] = Math.min(f[i][j], f[i][k] + f[k][j] + values[i] * values[k] * values[j]);
            }
        }
    }
    return f[0][n - 1];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
