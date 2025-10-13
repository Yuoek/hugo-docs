---
title: "0740_删除并获得点数"
date: 2025-10-08T18:36:29+08:00
weight: 5
tags: [二分查找, 二叉树, 动态规划, 哈希表, 图, 堆（优先队列）, 字典树, 字符串, 广度优先搜索, 排序, 数组, 最短路, 树, 模拟, 深度优先搜索, 矩阵, 设计]
---

{{< markmap >}}
### [0740_删除并获得点数](#740)
#### [数组](#740)
#### [哈希表](#740)
#### [动态规划](#740)
### [0741_摘樱桃](#741)
#### [数组](#741)
#### [动态规划](#741)
#### [矩阵](#741)
### [0742_二叉树最近的叶节点 🔒](#742)
#### [树](#742)
#### [深度优先搜索](#742)
#### [广度优先搜索](#742)
#### [二叉树](#742)
### [0743_网络延迟时间](#743)
#### [深度优先搜索](#743)
#### [广度优先搜索](#743)
#### [图](#743)
#### [最短路](#743)
#### [堆（优先队列）](#743)
### [0744_寻找比目标字母大的最小字母](#744)
#### [数组](#744)
#### [二分查找](#744)
### [0745_前缀和后缀搜索](#745)
#### [设计](#745)
#### [字典树](#745)
#### [数组](#745)
#### [哈希表](#745)
#### [字符串](#745)
### [0746_使用最小花费爬楼梯](#746)
#### [数组](#746)
#### [动态规划](#746)
### [0747_至少是其他数字两倍的最大数](#747)
#### [数组](#747)
#### [排序](#747)
### [0748_最短补全词](#748)
#### [数组](#748)
#### [哈希表](#748)
#### [字符串](#748)
### [0749_隔离病毒](#749)
#### [深度优先搜索](#749)
#### [广度优先搜索](#749)
#### [数组](#749)
#### [矩阵](#749)
#### [模拟](#749)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0740_删除并获得点数
___
#### 数组
___
#### 哈希表
___
#### 动态规划
---
### 0741_摘樱桃
___
#### 数组
___
#### 动态规划
___
#### 矩阵
---
### 0742_二叉树最近的叶节点 🔒
___
#### 树
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 二叉树
---
### 0743_网络延迟时间
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 图
___
#### 最短路
___
#### 堆（优先队列）
---
### 0744_寻找比目标字母大的最小字母
___
#### 数组
___
#### 二分查找
---
### 0745_前缀和后缀搜索
___
#### 设计
___
#### 字典树
___
#### 数组
___
#### 哈希表
___
#### 字符串
---
### 0746_使用最小花费爬楼梯
___
#### 数组
___
#### 动态规划
---
### 0747_至少是其他数字两倍的最大数
___
#### 数组
___
#### 排序
---
### 0748_最短补全词
___
#### 数组
___
#### 哈希表
___
#### 字符串
---
### 0749_隔离病毒
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 数组
___
#### 矩阵
___
#### 模拟
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 二叉树 | 动态规划 |
| 哈希表 | 图 | 堆（优先队列） |
| 字典树 | 字符串 | 广度优先搜索 |
| 排序 | 数组 | 最短路 |
| 树 | 模拟 | 深度优先搜索 |
| 矩阵 | 设计 |  |

# [740. 删除并获得点数](https://leetcode.cn/problems/delete-and-earn){#740}

{{< tabs "740" >}}

{{% tab "python" %}}
```python
class Solution:
    def deleteAndEarn(self, nums: List[int]) -> int:
        mx = -inf
        for num in nums:
            mx = max(mx, num)
        total = [0] * (mx + 1)
        for num in nums:
            total[num] += num
        first = total[0]
        second = max(total[0], total[1])
        for i in range(2, mx + 1):
            cur = max(first + total[i], second)
            first = second
            second = cur
        return second
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int deleteAndEarn(int[] nums) {
        if (nums.length == 0) {
            return 0;
        }

        int[] sums = new int[10010];
        int[] select = new int[10010];
        int[] nonSelect = new int[10010];

        int maxV = 0;
        for (int x : nums) {
            sums[x] += x;
            maxV = Math.max(maxV, x);
        }

        for (int i = 1; i <= maxV; i++) {
            select[i] = nonSelect[i - 1] + sums[i];
            nonSelect[i] = Math.max(select[i - 1], nonSelect[i - 1]);
        }
        return Math.max(select[maxV], nonSelect[maxV]);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> vals(10010);
        for (int& num : nums) {
            vals[num] += num;
        }
        return rob(vals);
    }

    int rob(vector<int>& nums) {
        int a = 0, b = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int c = max(nums[i] + a, b);
            a = b;
            b = c;
        }
        return b;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func deleteAndEarn(nums []int) int {

	max := func(x, y int) int {
		if x > y {
			return x
		}
		return y
	}

	mx := math.MinInt32
	for _, num := range nums {
		mx = max(mx, num)
	}
	total := make([]int, mx+1)
	for _, num := range nums {
		total[num] += num
	}
	first := total[0]
	second := max(total[0], total[1])
	for i := 2; i <= mx; i++ {
		cur := max(first+total[i], second)
		first = second
		second = cur
	}
	return second
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>nums</code> ，你可以对它进行一些操作。</p>

<p>每次操作中，选择任意一个 <code>nums[i]</code> ，删除它并获得 <code>nums[i]</code> 的点数。之后，你必须删除 <strong>所有 </strong>等于 <code>nums[i] - 1</code> 和 <code>nums[i] + 1</code> 的元素。</p>

<p>开始你拥有 <code>0</code> 个点数。返回你能通过这些操作获得的最大点数。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [3,4,2]
<strong>输出：</strong>6
<strong>解释：</strong>
删除 4 获得 4 个点数，因此 3 也被删除。
之后，删除 2 获得 2 个点数。总共获得 6 个点数。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,2,3,3,3,4]
<strong>输出：</strong>9
<strong>解释：</strong>
删除 3 获得 3 个点数，接着要删除两个 2 和 4 。
之后，再次删除 3 获得 3 个点数，再次删除 3 获得 3 个点数。
总共获得 9 个点数。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= nums.length <= 2 * 10<sup>4</sup></code></li>
	<li><code>1 <= nums[i] <= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def deleteAndEarn(self, nums: List[int]) -> int:
        mx = -inf
        for num in nums:
            mx = max(mx, num)
        total = [0] * (mx + 1)
        for num in nums:
            total[num] += num
        first = total[0]
        second = max(total[0], total[1])
        for i in range(2, mx + 1):
            cur = max(first + total[i], second)
            first = second
            second = cur
        return second
```

#### Java

```java
class Solution {
    public int deleteAndEarn(int[] nums) {
        if (nums.length == 0) {
            return 0;
        }

        int[] sums = new int[10010];
        int[] select = new int[10010];
        int[] nonSelect = new int[10010];

        int maxV = 0;
        for (int x : nums) {
            sums[x] += x;
            maxV = Math.max(maxV, x);
        }

        for (int i = 1; i <= maxV; i++) {
            select[i] = nonSelect[i - 1] + sums[i];
            nonSelect[i] = Math.max(select[i - 1], nonSelect[i - 1]);
        }
        return Math.max(select[maxV], nonSelect[maxV]);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> vals(10010);
        for (int& num : nums) {
            vals[num] += num;
        }
        return rob(vals);
    }

    int rob(vector<int>& nums) {
        int a = 0, b = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int c = max(nums[i] + a, b);
            a = b;
            b = c;
        }
        return b;
    }
};
```

#### Go

```go
func deleteAndEarn(nums []int) int {

	max := func(x, y int) int {
		if x > y {
			return x
		}
		return y
	}

	mx := math.MinInt32
	for _, num := range nums {
		mx = max(mx, num)
	}
	total := make([]int, mx+1)
	for _, num := range nums {
		total[num] += num
	}
	first := total[0]
	second := max(total[0], total[1])
	for i := 2; i <= mx; i++ {
		cur := max(first+total[i], second)
		first = second
		second = cur
	}
	return second
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [741. 摘樱桃](https://leetcode.cn/problems/cherry-pickup){#741}

{{< tabs "741" >}}

{{% tab "python" %}}
```python
class Solution:
    def cherryPickup(self, grid: List[List[int]]) -> int:
        n = len(grid)
        f = [[[-inf] * n for _ in range(n)] for _ in range((n << 1) - 1)]
        f[0][0][0] = grid[0][0]
        for k in range(1, (n << 1) - 1):
            for i1 in range(n):
                for i2 in range(n):
                    j1, j2 = k - i1, k - i2
                    if (
                        not 0 <= j1 < n
                        or not 0 <= j2 < n
                        or grid[i1][j1] == -1
                        or grid[i2][j2] == -1
                    ):
                        continue
                    t = grid[i1][j1]
                    if i1 != i2:
                        t += grid[i2][j2]
                    for x1 in range(i1 - 1, i1 + 1):
                        for x2 in range(i2 - 1, i2 + 1):
                            if x1 >= 0 and x2 >= 0:
                                f[k][i1][i2] = max(f[k][i1][i2], f[k - 1][x1][x2] + t)
        return max(0, f[-1][-1][-1])
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int cherryPickup(int[][] grid) {
        int n = grid.length;
        int[][][] f = new int[n * 2][n][n];
        f[0][0][0] = grid[0][0];
        for (int k = 1; k < n * 2 - 1; ++k) {
            for (int i1 = 0; i1 < n; ++i1) {
                for (int i2 = 0; i2 < n; ++i2) {
                    int j1 = k - i1, j2 = k - i2;
                    f[k][i1][i2] = Integer.MIN_VALUE;
                    if (j1 < 0 || j1 >= n || j2 < 0 || j2 >= n || grid[i1][j1] == -1
                        || grid[i2][j2] == -1) {
                        continue;
                    }
                    int t = grid[i1][j1];
                    if (i1 != i2) {
                        t += grid[i2][j2];
                    }
                    for (int x1 = i1 - 1; x1 <= i1; ++x1) {
                        for (int x2 = i2 - 1; x2 <= i2; ++x2) {
                            if (x1 >= 0 && x2 >= 0) {
                                f[k][i1][i2] = Math.max(f[k][i1][i2], f[k - 1][x1][x2] + t);
                            }
                        }
                    }
                }
            }
        }
        return Math.max(0, f[n * 2 - 2][n - 1][n - 1]);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>> f(n << 1, vector<vector<int>>(n, vector<int>(n, -1e9)));
        f[0][0][0] = grid[0][0];
        for (int k = 1; k < n * 2 - 1; ++k) {
            for (int i1 = 0; i1 < n; ++i1) {
                for (int i2 = 0; i2 < n; ++i2) {
                    int j1 = k - i1, j2 = k - i2;
                    if (j1 < 0 || j1 >= n || j2 < 0 || j2 >= n || grid[i1][j1] == -1 || grid[i2][j2] == -1) {
                        continue;
                    }
                    int t = grid[i1][j1];
                    if (i1 != i2) {
                        t += grid[i2][j2];
                    }
                    for (int x1 = i1 - 1; x1 <= i1; ++x1) {
                        for (int x2 = i2 - 1; x2 <= i2; ++x2) {
                            if (x1 >= 0 && x2 >= 0) {
                                f[k][i1][i2] = max(f[k][i1][i2], f[k - 1][x1][x2] + t);
                            }
                        }
                    }
                }
            }
        }
        return max(0, f[n * 2 - 2][n - 1][n - 1]);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func cherryPickup(grid [][]int) int {
	n := len(grid)
	f := make([][][]int, (n<<1)-1)
	for i := range f {
		f[i] = make([][]int, n)
		for j := range f[i] {
			f[i][j] = make([]int, n)
		}
	}
	f[0][0][0] = grid[0][0]
	for k := 1; k < (n<<1)-1; k++ {
		for i1 := 0; i1 < n; i1++ {
			for i2 := 0; i2 < n; i2++ {
				f[k][i1][i2] = int(-1e9)
				j1, j2 := k-i1, k-i2
				if j1 < 0 || j1 >= n || j2 < 0 || j2 >= n || grid[i1][j1] == -1 || grid[i2][j2] == -1 {
					continue
				}
				t := grid[i1][j1]
				if i1 != i2 {
					t += grid[i2][j2]
				}
				for x1 := i1 - 1; x1 <= i1; x1++ {
					for x2 := i2 - 1; x2 <= i2; x2++ {
						if x1 >= 0 && x2 >= 0 {
							f[k][i1][i2] = max(f[k][i1][i2], f[k-1][x1][x2]+t)
						}
					}
				}
			}
		}
	}
	return max(0, f[n*2-2][n-1][n-1])
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function cherryPickup(grid: number[][]): number {
    const n: number = grid.length;
    const f: number[][][] = Array.from({ length: n * 2 - 1 }, () =>
        Array.from({ length: n }, () => Array.from({ length: n }, () => -Infinity)),
    );
    f[0][0][0] = grid[0][0];
    for (let k = 1; k < n * 2 - 1; ++k) {
        for (let i1 = 0; i1 < n; ++i1) {
            for (let i2 = 0; i2 < n; ++i2) {
                const [j1, j2]: [number, number] = [k - i1, k - i2];
                if (
                    j1 < 0 ||
                    j1 >= n ||
                    j2 < 0 ||
                    j2 >= n ||
                    grid[i1][j1] == -1 ||
                    grid[i2][j2] == -1
                ) {
                    continue;
                }
                const t: number = grid[i1][j1] + (i1 != i2 ? grid[i2][j2] : 0);
                for (let x1 = i1 - 1; x1 <= i1; ++x1) {
                    for (let x2 = i2 - 1; x2 <= i2; ++x2) {
                        if (x1 >= 0 && x2 >= 0) {
                            f[k][i1][i2] = Math.max(f[k][i1][i2], f[k - 1][x1][x2] + t);
                        }
                    }
                }
            }
        }
    }
    return Math.max(0, f[n * 2 - 2][n - 1][n - 1]);
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[][]} grid
 * @return {number}
 */
var cherryPickup = function (grid) {
    const n = grid.length;
    const f = Array.from({ length: n * 2 - 1 }, () =>
        Array.from({ length: n }, () => Array.from({ length: n }, () => -Infinity)),
    );
    f[0][0][0] = grid[0][0];
    for (let k = 1; k < n * 2 - 1; ++k) {
        for (let i1 = 0; i1 < n; ++i1) {
            for (let i2 = 0; i2 < n; ++i2) {
                const [j1, j2] = [k - i1, k - i2];
                if (
                    j1 < 0 ||
                    j1 >= n ||
                    j2 < 0 ||
                    j2 >= n ||
                    grid[i1][j1] == -1 ||
                    grid[i2][j2] == -1
                ) {
                    continue;
                }
                const t = grid[i1][j1] + (i1 != i2 ? grid[i2][j2] : 0);
                for (let x1 = i1 - 1; x1 <= i1; ++x1) {
                    for (let x2 = i2 - 1; x2 <= i2; ++x2) {
                        if (x1 >= 0 && x2 >= 0) {
                            f[k][i1][i2] = Math.max(f[k][i1][i2], f[k - 1][x1][x2] + t);
                        }
                    }
                }
            }
        }
    }
    return Math.max(0, f[n * 2 - 2][n - 1][n - 1]);
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个 <code>n x n</code> 的网格 <code>grid</code> ，代表一块樱桃地，每个格子由以下三种数字的一种来表示：</p>

<ul>
	<li><code>0</code> 表示这个格子是空的，所以你可以穿过它。</li>
	<li><code>1</code> 表示这个格子里装着一个樱桃，你可以摘到樱桃然后穿过它。</li>
	<li><code>-1</code> 表示这个格子里有荆棘，挡着你的路。</li>
</ul>

<p>请你统计并返回：在遵守下列规则的情况下，能摘到的最多樱桃数：</p>

<ul>
	<li>从位置&nbsp;<code>(0, 0)</code> 出发，最后到达 <code>(n - 1, n - 1)</code> ，只能向下或向右走，并且只能穿越有效的格子（即只可以穿过值为 <code>0</code> 或者 <code>1</code> 的格子）；</li>
	<li>当到达 <code>(n - 1, n&nbsp;- 1)</code> 后，你要继续走，直到返回到 <code>(0, 0) </code>，只能向上或向左走，并且只能穿越有效的格子；</li>
	<li>当你经过一个格子且这个格子包含一个樱桃时，你将摘到樱桃并且这个格子会变成空的（值变为 <code>0</code> ）；</li>
	<li>如果在 <code>(0, 0)</code> 和 <code>(n - 1, n - 1)</code> 之间不存在一条可经过的路径，则无法摘到任何一个樱桃。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0700-0799/0741.Cherry%20Pickup/images/grid.jpg" />
<pre>
<b>输入：</b>grid = [[0,1,-1],[1,0,-1],[1,1,1]]
<b>输出：</b>5
<b>解释：</b>玩家从 (0, 0) 出发：向下、向下、向右、向右移动至 (2, 2) 。
在这一次行程中捡到 4 个樱桃，矩阵变成 [[0,1,-1],[0,0,-1],[0,0,0]] 。
然后，玩家向左、向上、向上、向左返回起点，再捡到 1 个樱桃。
总共捡到 5 个樱桃，这是最大可能值。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>grid = [[1,1,-1],[1,-1,1],[-1,1,1]]
<b>输出：</b>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= n &lt;= 50</code></li>
	<li><code>grid[i][j]</code>&nbsp;为&nbsp;<code>-1</code>、<code>0</code>&nbsp;或&nbsp;<code>1</code></li>
	<li><code>grid[0][0] != -1</code></li>
	<li><code>grid[n - 1][n - 1] != -1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

根据题目描述，玩家从 $(0, 0)$ 出发，到达 $(n-1, n-1)$ 后，又重新返回到起始点 $(0, 0)$，我们可以视为玩家两次从 $(0, 0)$ 出发，到达 $(n-1, n-1)$。

因此，我们定义 $f[k][i_1][i_2]$ 表示两次都走了 $k$ 步，分别到达 $(i_1, k-i_1)$ 和 $(i_2, k-i_2)$ 时，能够摘到的最多樱桃数。初始时 $f[0][0][0] = grid[0][0]$。其余 $f[k][i_1][i_2]$ 的初始值为负无穷。答案为 $\max(0, f[2n-2][n-1][n-1])$。

我们可以根据题目描述，得到状态转移方程：

$$
f[k][i_1][i_2] = \max(f[k-1][x_1][x_2] + t, f[k][i_1][i_2])
$$

其中 $t$ 表示 $(i_1, k-i_1)$ 和 $(i_2, k-i_2)$ 位置上的樱桃数，而 $x_1, x_2$ 分别表示 $(i_1, k-i_1)$ 和 $(i_2, k-i_2)$ 的前一步位置。

时间复杂度 $O(n^3)$，空间复杂度 $O(n^3)$。其中 $n$ 表示网格的边长。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def cherryPickup(self, grid: List[List[int]]) -> int:
        n = len(grid)
        f = [[[-inf] * n for _ in range(n)] for _ in range((n << 1) - 1)]
        f[0][0][0] = grid[0][0]
        for k in range(1, (n << 1) - 1):
            for i1 in range(n):
                for i2 in range(n):
                    j1, j2 = k - i1, k - i2
                    if (
                        not 0 <= j1 < n
                        or not 0 <= j2 < n
                        or grid[i1][j1] == -1
                        or grid[i2][j2] == -1
                    ):
                        continue
                    t = grid[i1][j1]
                    if i1 != i2:
                        t += grid[i2][j2]
                    for x1 in range(i1 - 1, i1 + 1):
                        for x2 in range(i2 - 1, i2 + 1):
                            if x1 >= 0 and x2 >= 0:
                                f[k][i1][i2] = max(f[k][i1][i2], f[k - 1][x1][x2] + t)
        return max(0, f[-1][-1][-1])
```

#### Java

```java
class Solution {
    public int cherryPickup(int[][] grid) {
        int n = grid.length;
        int[][][] f = new int[n * 2][n][n];
        f[0][0][0] = grid[0][0];
        for (int k = 1; k < n * 2 - 1; ++k) {
            for (int i1 = 0; i1 < n; ++i1) {
                for (int i2 = 0; i2 < n; ++i2) {
                    int j1 = k - i1, j2 = k - i2;
                    f[k][i1][i2] = Integer.MIN_VALUE;
                    if (j1 < 0 || j1 >= n || j2 < 0 || j2 >= n || grid[i1][j1] == -1
                        || grid[i2][j2] == -1) {
                        continue;
                    }
                    int t = grid[i1][j1];
                    if (i1 != i2) {
                        t += grid[i2][j2];
                    }
                    for (int x1 = i1 - 1; x1 <= i1; ++x1) {
                        for (int x2 = i2 - 1; x2 <= i2; ++x2) {
                            if (x1 >= 0 && x2 >= 0) {
                                f[k][i1][i2] = Math.max(f[k][i1][i2], f[k - 1][x1][x2] + t);
                            }
                        }
                    }
                }
            }
        }
        return Math.max(0, f[n * 2 - 2][n - 1][n - 1]);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>> f(n << 1, vector<vector<int>>(n, vector<int>(n, -1e9)));
        f[0][0][0] = grid[0][0];
        for (int k = 1; k < n * 2 - 1; ++k) {
            for (int i1 = 0; i1 < n; ++i1) {
                for (int i2 = 0; i2 < n; ++i2) {
                    int j1 = k - i1, j2 = k - i2;
                    if (j1 < 0 || j1 >= n || j2 < 0 || j2 >= n || grid[i1][j1] == -1 || grid[i2][j2] == -1) {
                        continue;
                    }
                    int t = grid[i1][j1];
                    if (i1 != i2) {
                        t += grid[i2][j2];
                    }
                    for (int x1 = i1 - 1; x1 <= i1; ++x1) {
                        for (int x2 = i2 - 1; x2 <= i2; ++x2) {
                            if (x1 >= 0 && x2 >= 0) {
                                f[k][i1][i2] = max(f[k][i1][i2], f[k - 1][x1][x2] + t);
                            }
                        }
                    }
                }
            }
        }
        return max(0, f[n * 2 - 2][n - 1][n - 1]);
    }
};
```

#### Go

```go
func cherryPickup(grid [][]int) int {
	n := len(grid)
	f := make([][][]int, (n<<1)-1)
	for i := range f {
		f[i] = make([][]int, n)
		for j := range f[i] {
			f[i][j] = make([]int, n)
		}
	}
	f[0][0][0] = grid[0][0]
	for k := 1; k < (n<<1)-1; k++ {
		for i1 := 0; i1 < n; i1++ {
			for i2 := 0; i2 < n; i2++ {
				f[k][i1][i2] = int(-1e9)
				j1, j2 := k-i1, k-i2
				if j1 < 0 || j1 >= n || j2 < 0 || j2 >= n || grid[i1][j1] == -1 || grid[i2][j2] == -1 {
					continue
				}
				t := grid[i1][j1]
				if i1 != i2 {
					t += grid[i2][j2]
				}
				for x1 := i1 - 1; x1 <= i1; x1++ {
					for x2 := i2 - 1; x2 <= i2; x2++ {
						if x1 >= 0 && x2 >= 0 {
							f[k][i1][i2] = max(f[k][i1][i2], f[k-1][x1][x2]+t)
						}
					}
				}
			}
		}
	}
	return max(0, f[n*2-2][n-1][n-1])
}
```

#### TypeScript

```ts
function cherryPickup(grid: number[][]): number {
    const n: number = grid.length;
    const f: number[][][] = Array.from({ length: n * 2 - 1 }, () =>
        Array.from({ length: n }, () => Array.from({ length: n }, () => -Infinity)),
    );
    f[0][0][0] = grid[0][0];
    for (let k = 1; k < n * 2 - 1; ++k) {
        for (let i1 = 0; i1 < n; ++i1) {
            for (let i2 = 0; i2 < n; ++i2) {
                const [j1, j2]: [number, number] = [k - i1, k - i2];
                if (
                    j1 < 0 ||
                    j1 >= n ||
                    j2 < 0 ||
                    j2 >= n ||
                    grid[i1][j1] == -1 ||
                    grid[i2][j2] == -1
                ) {
                    continue;
                }
                const t: number = grid[i1][j1] + (i1 != i2 ? grid[i2][j2] : 0);
                for (let x1 = i1 - 1; x1 <= i1; ++x1) {
                    for (let x2 = i2 - 1; x2 <= i2; ++x2) {
                        if (x1 >= 0 && x2 >= 0) {
                            f[k][i1][i2] = Math.max(f[k][i1][i2], f[k - 1][x1][x2] + t);
                        }
                    }
                }
            }
        }
    }
    return Math.max(0, f[n * 2 - 2][n - 1][n - 1]);
}
```

#### JavaScript

```js
/**
 * @param {number[][]} grid
 * @return {number}
 */
var cherryPickup = function (grid) {
    const n = grid.length;
    const f = Array.from({ length: n * 2 - 1 }, () =>
        Array.from({ length: n }, () => Array.from({ length: n }, () => -Infinity)),
    );
    f[0][0][0] = grid[0][0];
    for (let k = 1; k < n * 2 - 1; ++k) {
        for (let i1 = 0; i1 < n; ++i1) {
            for (let i2 = 0; i2 < n; ++i2) {
                const [j1, j2] = [k - i1, k - i2];
                if (
                    j1 < 0 ||
                    j1 >= n ||
                    j2 < 0 ||
                    j2 >= n ||
                    grid[i1][j1] == -1 ||
                    grid[i2][j2] == -1
                ) {
                    continue;
                }
                const t = grid[i1][j1] + (i1 != i2 ? grid[i2][j2] : 0);
                for (let x1 = i1 - 1; x1 <= i1; ++x1) {
                    for (let x2 = i2 - 1; x2 <= i2; ++x2) {
                        if (x1 >= 0 && x2 >= 0) {
                            f[k][i1][i2] = Math.max(f[k][i1][i2], f[k - 1][x1][x2] + t);
                        }
                    }
                }
            }
        }
    }
    return Math.max(0, f[n * 2 - 2][n - 1][n - 1]);
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [742. 二叉树最近的叶节点 🔒](https://leetcode.cn/problems/closest-leaf-in-a-binary-tree){#742}

{{< tabs "742" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findClosestLeaf(self, root: Optional[TreeNode], k: int) -> int:
        def dfs(root: Optional[TreeNode], fa: Optional[TreeNode]):
            if root:
                g[root].append(fa)
                g[fa].append(root)
                dfs(root.left, root)
                dfs(root.right, root)

        g = defaultdict(list)
        dfs(root, None)
        q = deque(node for node in g if node and node.val == k)
        vis = set(q)
        while 1:
            node = q.popleft()
            if node:
                if node.left == node.right:
                    return node.val
                for nxt in g[node]:
                    if nxt not in vis:
                        vis.add(nxt)
                        q.append(nxt)
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
    private Map<TreeNode, List<TreeNode>> g = new HashMap<>();

    public int findClosestLeaf(TreeNode root, int k) {
        dfs(root, null);
        Deque<TreeNode> q = new LinkedList<>();
        Set<TreeNode> vis = new HashSet<>(q.size());
        for (TreeNode node : g.keySet()) {
            if (node != null && node.val == k) {
                vis.add(node);
                q.offer(node);
                break;
            }
        }
        while (true) {
            TreeNode node = q.poll();
            if (node != null) {
                if (node.left == node.right) {
                    return node.val;
                }
                for (TreeNode nxt : g.get(node)) {
                    if (vis.add(nxt)) {
                        q.offer(nxt);
                    }
                }
            }
        }
    }

    private void dfs(TreeNode root, TreeNode fa) {
        if (root != null) {
            g.computeIfAbsent(root, k -> new ArrayList<>()).add(fa);
            g.computeIfAbsent(fa, k -> new ArrayList<>()).add(root);
            dfs(root.left, root);
            dfs(root.right, root);
        }
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
    int findClosestLeaf(TreeNode* root, int k) {
        unordered_map<TreeNode*, vector<TreeNode*>> g;
        function<void(TreeNode*, TreeNode*)> dfs = [&](TreeNode* root, TreeNode* fa) {
            if (root) {
                g[root].push_back(fa);
                g[fa].push_back(root);
                dfs(root->left, root);
                dfs(root->right, root);
            }
        };
        dfs(root, nullptr);
        queue<TreeNode*> q;
        unordered_set<TreeNode*> vis;
        for (auto& [node, _] : g) {
            if (node && node->val == k) {
                q.push(node);
                vis.insert(node);
            }
        }
        while (1) {
            auto node = q.front();
            q.pop();
            if (node) {
                if (node->left == node->right) {
                    return node->val;
                }
                for (auto& nxt : g[node]) {
                    if (vis.count(nxt)) {
                        continue;
                    }
                    q.push(nxt);
                    vis.insert(nxt);
                }
            }
        }
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
func findClosestLeaf(root *TreeNode, k int) int {
	g := map[*TreeNode][]*TreeNode{}
	var dfs func(*TreeNode, *TreeNode)
	dfs = func(root, fa *TreeNode) {
		if root != nil {
			g[root] = append(g[root], fa)
			g[fa] = append(g[fa], root)
			dfs(root.Left, root)
			dfs(root.Right, root)
		}
	}
	dfs(root, nil)
	q := []*TreeNode{}
	vis := map[*TreeNode]bool{}
	for node := range g {
		if node != nil && node.Val == k {
			q = append(q, node)
			vis[node] = true
			break
		}
	}
	for {
		node := q[0]
		q = q[1:]
		if node != nil {
			if node.Left == node.Right {
				return node.Val
			}
			for _, nxt := range g[node] {
				if !vis[nxt] {
					vis[nxt] = true
					q = append(q, nxt)
				}
			}
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

<p>给定一个 <strong>每个结点的值互不相同</strong>&nbsp;的二叉树，和一个目标整数值 <code>k</code>，返回 <em>树中与目标值 <code>k</code>&nbsp; <strong>最近的叶结点</strong></em> 。&nbsp;</p>

<p><strong>与叶结点最近</strong><em> </em>表示在二叉树中到达该叶节点需要行进的边数与到达其它叶结点相比最少。而且，当一个结点没有孩子结点时称其为叶结点。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0700-0799/0742.Closest%20Leaf%20in%20a%20Binary%20Tree/images/closest1-tree.jpg" /></p>

<pre>
<strong>输入：</strong>root = [1, 3, 2], k = 1
<strong>输出：</strong> 2
<strong>解释：</strong> 2 和 3 都是距离目标 1 最近的叶节点。
</pre>

<p><strong>示例 2：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0700-0799/0742.Closest%20Leaf%20in%20a%20Binary%20Tree/images/closest2-tree.jpg" /></p>

<pre>
<strong>输入：</strong>root = [1], k = 1
<strong>输出：</strong>1
<strong>解释：</strong>最近的叶节点是根结点自身。
</pre>

<p><strong>示例 3：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0700-0799/0742.Closest%20Leaf%20in%20a%20Binary%20Tree/images/closest3-tree.jpg" /></p>

<pre>
<strong>输入：</strong>root = [1,2,3,4,null,null,null,5,null,6], k = 2
<strong>输出：</strong>3
<strong>解释：</strong>值为 3（而不是值为 6）的叶节点是距离结点 2 的最近结点。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>二叉树节点数在&nbsp;<code>[1, 1000]</code> 范围内</li>
	<li><code>1 &lt;= Node.val &lt;= 1000</code></li>
	<li>每个节点值都 <strong>不同</strong></li>
	<li>给定的二叉树中有某个结点使得&nbsp;<code>node.val == k</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS + BFS

我们首先使用深度优先搜索构建一个无向图 $g$，其中 $g[node]$ 表示与节点 $node$ 相邻的节点集合。然后我们从节点 $k$ 开始进行广度优先搜索，直到找到一个叶节点为止，即为答案。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为二叉树节点个数。

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
    def findClosestLeaf(self, root: Optional[TreeNode], k: int) -> int:
        def dfs(root: Optional[TreeNode], fa: Optional[TreeNode]):
            if root:
                g[root].append(fa)
                g[fa].append(root)
                dfs(root.left, root)
                dfs(root.right, root)

        g = defaultdict(list)
        dfs(root, None)
        q = deque(node for node in g if node and node.val == k)
        vis = set(q)
        while 1:
            node = q.popleft()
            if node:
                if node.left == node.right:
                    return node.val
                for nxt in g[node]:
                    if nxt not in vis:
                        vis.add(nxt)
                        q.append(nxt)
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
    private Map<TreeNode, List<TreeNode>> g = new HashMap<>();

    public int findClosestLeaf(TreeNode root, int k) {
        dfs(root, null);
        Deque<TreeNode> q = new LinkedList<>();
        Set<TreeNode> vis = new HashSet<>(q.size());
        for (TreeNode node : g.keySet()) {
            if (node != null && node.val == k) {
                vis.add(node);
                q.offer(node);
                break;
            }
        }
        while (true) {
            TreeNode node = q.poll();
            if (node != null) {
                if (node.left == node.right) {
                    return node.val;
                }
                for (TreeNode nxt : g.get(node)) {
                    if (vis.add(nxt)) {
                        q.offer(nxt);
                    }
                }
            }
        }
    }

    private void dfs(TreeNode root, TreeNode fa) {
        if (root != null) {
            g.computeIfAbsent(root, k -> new ArrayList<>()).add(fa);
            g.computeIfAbsent(fa, k -> new ArrayList<>()).add(root);
            dfs(root.left, root);
            dfs(root.right, root);
        }
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
    int findClosestLeaf(TreeNode* root, int k) {
        unordered_map<TreeNode*, vector<TreeNode*>> g;
        function<void(TreeNode*, TreeNode*)> dfs = [&](TreeNode* root, TreeNode* fa) {
            if (root) {
                g[root].push_back(fa);
                g[fa].push_back(root);
                dfs(root->left, root);
                dfs(root->right, root);
            }
        };
        dfs(root, nullptr);
        queue<TreeNode*> q;
        unordered_set<TreeNode*> vis;
        for (auto& [node, _] : g) {
            if (node && node->val == k) {
                q.push(node);
                vis.insert(node);
            }
        }
        while (1) {
            auto node = q.front();
            q.pop();
            if (node) {
                if (node->left == node->right) {
                    return node->val;
                }
                for (auto& nxt : g[node]) {
                    if (vis.count(nxt)) {
                        continue;
                    }
                    q.push(nxt);
                    vis.insert(nxt);
                }
            }
        }
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
func findClosestLeaf(root *TreeNode, k int) int {
	g := map[*TreeNode][]*TreeNode{}
	var dfs func(*TreeNode, *TreeNode)
	dfs = func(root, fa *TreeNode) {
		if root != nil {
			g[root] = append(g[root], fa)
			g[fa] = append(g[fa], root)
			dfs(root.Left, root)
			dfs(root.Right, root)
		}
	}
	dfs(root, nil)
	q := []*TreeNode{}
	vis := map[*TreeNode]bool{}
	for node := range g {
		if node != nil && node.Val == k {
			q = append(q, node)
			vis[node] = true
			break
		}
	}
	for {
		node := q[0]
		q = q[1:]
		if node != nil {
			if node.Left == node.Right {
				return node.Val
			}
			for _, nxt := range g[node] {
				if !vis[nxt] {
					vis[nxt] = true
					q = append(q, nxt)
				}
			}
		}
	}
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [743. 网络延迟时间](https://leetcode.cn/problems/network-delay-time){#743}

{{< tabs "743" >}}

{{% tab "python" %}}
```python
class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        g = [[] for _ in range(n)]
        for u, v, w in times:
            g[u - 1].append((v - 1, w))
        dist = [inf] * n
        dist[k - 1] = 0
        pq = [(0, k - 1)]
        while pq:
            d, u = heappop(pq)
            if d > dist[u]:
                continue
            for v, w in g[u]:
                if (nd := d + w) < dist[v]:
                    dist[v] = nd
                    heappush(pq, (nd, v))
        ans = max(dist)
        return -1 if ans == inf else ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int networkDelayTime(int[][] times, int n, int k) {
        final int inf = 1 << 29;
        List<int[]>[] g = new List[n];
        Arrays.setAll(g, i -> new ArrayList<>());
        for (var e : times) {
            g[e[0] - 1].add(new int[] {e[1] - 1, e[2]});
        }
        int[] dist = new int[n];
        Arrays.fill(dist, inf);
        dist[k - 1] = 0;
        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        pq.offer(new int[] {0, k - 1});
        while (!pq.isEmpty()) {
            var p = pq.poll();
            int d = p[0], u = p[1];
            if (d > dist[u]) {
                continue;
            }
            for (var e : g[u]) {
                int v = e[0], w = e[1];
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.offer(new int[] {dist[v], v});
                }
            }
        }
        int ans = Arrays.stream(dist).max().getAsInt();
        return ans == inf ? -1 : ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        const int inf = 1 << 29;
        using pii = pair<int, int>;
        vector<vector<pii>> g(n);
        for (auto& edge : times) {
            g[edge[0] - 1].emplace_back(edge[1] - 1, edge[2]);
        }

        vector<int> dist(n, inf);
        dist[k - 1] = 0;
        priority_queue<pii, vector<pii>, greater<>> pq;
        pq.emplace(0, k - 1);

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (d > dist[u]) {
                continue;
            }
            for (auto& [v, w] : g[u]) {
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.emplace(dist[v], v);
                }
            }
        }

        int ans = ranges::max(dist);
        return ans == inf ? -1 : ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func networkDelayTime(times [][]int, n int, k int) int {
	g := make([][][2]int, n)
	for _, e := range times {
		u, v, w := e[0]-1, e[1]-1, e[2]
		g[u] = append(g[u], [2]int{v, w})
	}
	dist := make([]int, n)
	const inf int = 1 << 29
	for i := range dist {
		dist[i] = inf
	}
	dist[k-1] = 0
	pq := hp{{0, k - 1}}
	for len(pq) > 0 {
		p := heap.Pop(&pq).(pair)
		d, u := p.x, p.i
		if d > dist[u] {
			continue
		}
		for _, e := range g[u] {
			v, w := e[0], e[1]
			if nd := d + w; nd < dist[v] {
				dist[v] = nd
				heap.Push(&pq, pair{nd, v})
			}
		}
	}
	if ans := slices.Max(dist); ans < inf {
		return ans
	}
	return -1

}

type pair struct{ x, i int }
type hp []pair

func (h hp) Len() int           { return len(h) }
func (h hp) Less(i, j int) bool { return h[i].x < h[j].x }
func (h hp) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *hp) Push(x any)        { *h = append(*h, x.(pair)) }
func (h *hp) Pop() (x any)      { a := *h; x = a[len(a)-1]; *h = a[:len(a)-1]; return }
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function networkDelayTime(times: number[][], n: number, k: number): number {
    const g: [number, number][][] = Array.from({ length: n }, () => []);
    for (const [u, v, w] of times) {
        g[u - 1].push([v - 1, w]);
    }
    const dist: number[] = Array(n).fill(Infinity);
    dist[k - 1] = 0;
    const pq = new MinPriorityQueue({ priority: v => v[0] });
    pq.enqueue([0, k - 1]);
    while (!pq.isEmpty()) {
        const [d, u] = pq.dequeue().element;
        if (d > dist[u]) {
            continue;
        }
        for (const [v, w] of g[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.enqueue([dist[v], v]);
            }
        }
    }
    const ans = Math.max(...dist);
    return ans === Infinity ? -1 : ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>有 <code>n</code> 个网络节点，标记为&nbsp;<code>1</code>&nbsp;到 <code>n</code>。</p>

<p>给你一个列表&nbsp;<code>times</code>，表示信号经过 <strong>有向</strong> 边的传递时间。&nbsp;<code>times[i] = (u<sub>i</sub>, v<sub>i</sub>, w<sub>i</sub>)</code>，其中&nbsp;<code>u<sub>i</sub></code>&nbsp;是源节点，<code>v<sub>i</sub></code>&nbsp;是目标节点， <code>w<sub>i</sub></code>&nbsp;是一个信号从源节点传递到目标节点的时间。</p>

<p>现在，从某个节点&nbsp;<code>K</code>&nbsp;发出一个信号。需要多久才能使所有节点都收到信号？如果不能使所有节点收到信号，返回&nbsp;<code>-1</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0700-0799/0743.Network%20Delay%20Time/images/931_example_1.png" style="height: 220px; width: 200px;" /></p>

<pre>
<strong>输入：</strong>times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
<strong>输出：</strong>2
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>times = [[1,2,1]], n = 2, k = 1
<strong>输出：</strong>1
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>times = [[1,2,1]], n = 2, k = 2
<strong>输出：</strong>-1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= n &lt;= 100</code></li>
	<li><code>1 &lt;= times.length &lt;= 6000</code></li>
	<li><code>times[i].length == 3</code></li>
	<li><code>1 &lt;= u<sub>i</sub>, v<sub>i</sub> &lt;= n</code></li>
	<li><code>u<sub>i</sub> != v<sub>i</sub></code></li>
	<li><code>0 &lt;= w<sub>i</sub> &lt;= 100</code></li>
	<li>所有 <code>(u<sub>i</sub>, v<sub>i</sub>)</code> 对都 <strong>互不相同</strong>（即，不含重复边）</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：朴素 Dijkstra 算法

我们定义 $\textit{g}[u][v]$ 表示节点 $u$ 到节点 $v$ 的边权，如果节点 $u$ 到节点 $v$ 之间没有边，则 $\textit{g}[u][v] = +\infty$。

我们维护一个数组 $\textit{dist}$，其中 $\textit{dist}[i]$ 表示节点 $k$ 到节点 $i$ 的最短路径长度。初始时，我们将 $\textit{dist}[i]$ 全部初始化为 $+\infty$，但 $\textit{dist}[k - 1] = 0$。定义一个数组 $\textit{vis}$，其中 $\textit{vis}[i]$ 表示节点 $i$ 是否被访问过，初始时，我们将 $\textit{vis}[i]$ 全部初始化为 $\text{false}$。

我们每次找到未被访问的距离最小的节点 $t$，然后以节点 $t$ 为中心进行松弛操作，即对于每个节点 $j$，如果 $\textit{dist}[j] > \textit{dist}[t] + \textit{g}[t][j]$，则更新 $\textit{dist}[j] = \textit{dist}[t] + \textit{g}[t][j]$。

最后，我们返回 $\textit{dist}$ 中的最大值，即为答案。如果答案为 $+\infty$，则说明存在无法到达的节点，返回 $-1$。

时间复杂度 $O(n^2 + m)$，空间复杂度 $O(n^2)$。其中 $n$ 和 $m$ 分别为节点数和边数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        g = [[inf] * n for _ in range(n)]
        for u, v, w in times:
            g[u - 1][v - 1] = w
        dist = [inf] * n
        dist[k - 1] = 0
        vis = [False] * n
        for _ in range(n):
            t = -1
            for j in range(n):
                if not vis[j] and (t == -1 or dist[t] > dist[j]):
                    t = j
            vis[t] = True
            for j in range(n):
                dist[j] = min(dist[j], dist[t] + g[t][j])
        ans = max(dist)
        return -1 if ans == inf else ans
```

#### Java

```java
class Solution {
    public int networkDelayTime(int[][] times, int n, int k) {
        int[][] g = new int[n][n];
        int[] dist = new int[n];
        final int inf = 1 << 29;
        Arrays.fill(dist, inf);
        for (var e : g) {
            Arrays.fill(e, inf);
        }
        for (var e : times) {
            g[e[0] - 1][e[1] - 1] = e[2];
        }
        dist[k - 1] = 0;
        boolean[] vis = new boolean[n];
        for (int i = 0; i < n; ++i) {
            int t = -1;
            for (int j = 0; j < n; ++j) {
                if (!vis[j] && (t == -1 || dist[t] > dist[j])) {
                    t = j;
                }
            }
            vis[t] = true;
            for (int j = 0; j < n; ++j) {
                dist[j] = Math.min(dist[j], dist[t] + g[t][j]);
            }
        }
        int ans = 0;
        for (int x : dist) {
            ans = Math.max(ans, x);
        }
        return ans == inf ? -1 : ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        const int inf = 1 << 29;
        vector<vector<int>> g(n, vector<int>(n, inf));
        for (const auto& e : times) {
            g[e[0] - 1][e[1] - 1] = e[2];
        }
        vector<int> dist(n, inf);
        dist[k - 1] = 0;
        vector<bool> vis(n);
        for (int i = 0; i < n; ++i) {
            int t = -1;
            for (int j = 0; j < n; ++j) {
                if (!vis[j] && (t == -1 || dist[t] > dist[j])) {
                    t = j;
                }
            }
            vis[t] = true;
            for (int j = 0; j < n; ++j) {
                dist[j] = min(dist[j], dist[t] + g[t][j]);
            }
        }
        int ans = ranges::max(dist);
        return ans == inf ? -1 : ans;
    }
};
```

#### Go

```go
func networkDelayTime(times [][]int, n int, k int) int {
	const inf = 1 << 29
	g := make([][]int, n)
	for i := range g {
		g[i] = make([]int, n)
		for j := range g[i] {
			g[i][j] = inf
		}
	}
	for _, e := range times {
		g[e[0]-1][e[1]-1] = e[2]
	}

	dist := make([]int, n)
	for i := range dist {
		dist[i] = inf
	}
	dist[k-1] = 0

	vis := make([]bool, n)
	for i := 0; i < n; i++ {
		t := -1
		for j := 0; j < n; j++ {
			if !vis[j] && (t == -1 || dist[t] > dist[j]) {
				t = j
			}
		}
		vis[t] = true
		for j := 0; j < n; j++ {
			dist[j] = min(dist[j], dist[t]+g[t][j])
		}
	}

	if ans := slices.Max(dist); ans != inf {
		return ans
	}
	return -1
}
```

#### TypeScript

```ts
function networkDelayTime(times: number[][], n: number, k: number): number {
    const g: number[][] = Array.from({ length: n }, () => Array(n).fill(Infinity));
    for (const [u, v, w] of times) {
        g[u - 1][v - 1] = w;
    }
    const dist: number[] = Array(n).fill(Infinity);
    dist[k - 1] = 0;
    const vis: boolean[] = Array(n).fill(false);
    for (let i = 0; i < n; ++i) {
        let t = -1;
        for (let j = 0; j < n; ++j) {
            if (!vis[j] && (t === -1 || dist[j] < dist[t])) {
                t = j;
            }
        }
        vis[t] = true;
        for (let j = 0; j < n; ++j) {
            dist[j] = Math.min(dist[j], dist[t] + g[t][j]);
        }
    }
    const ans = Math.max(...dist);
    return ans === Infinity ? -1 : ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：堆优化 Dijkstra 算法

我们可以使用优先队列（堆）来优化朴素 Dijkstra 算法。

我们定义 $\textit{g}[u]$ 表示节点 $u$ 的所有邻接边，而 $\textit{dist}[u]$ 表示节点 $k$ 到节点 $u$ 的最短路径长度。初始时，我们将 $\textit{dist}[u]$ 全部初始化为 $+\infty$，但 $\textit{dist}[k - 1] = 0$。

定义一个优先队列 $\textit{pq}$，其中每个元素为 $(\textit{d}, u)$，表示节点 $u$ 到节点 $k$ 的距离为 $\textit{d}$。我们每次从 $\textit{pq}$ 中取出距离最小的节点 $(\textit{d}, u)$。如果 $\textit{d} > \textit{dist}[u]$，则跳过该节点。否则，我们遍历节点 $u$ 的所有邻接边，对于每个邻接边 $(v, w)$，如果 $\textit{dist}[v] > \textit{dist}[u] + w$，则更新 $\textit{dist}[v] = \textit{dist}[u] + w$，并将 $(\textit{dist}[v], v)$ 加入 $\textit{pq}$。

最后，我们返回 $\textit{dist}$ 中的最大值，即为答案。如果答案为 $+\infty$，则说明存在无法到达的节点，返回 $-1$。

时间复杂度 $O(m \times \log m + n)$，空间复杂度 $O(n + m)$。其中 $n$ 和 $m$ 分别为节点数和边数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        g = [[] for _ in range(n)]
        for u, v, w in times:
            g[u - 1].append((v - 1, w))
        dist = [inf] * n
        dist[k - 1] = 0
        pq = [(0, k - 1)]
        while pq:
            d, u = heappop(pq)
            if d > dist[u]:
                continue
            for v, w in g[u]:
                if (nd := d + w) < dist[v]:
                    dist[v] = nd
                    heappush(pq, (nd, v))
        ans = max(dist)
        return -1 if ans == inf else ans
```

#### Java

```java
class Solution {
    public int networkDelayTime(int[][] times, int n, int k) {
        final int inf = 1 << 29;
        List<int[]>[] g = new List[n];
        Arrays.setAll(g, i -> new ArrayList<>());
        for (var e : times) {
            g[e[0] - 1].add(new int[] {e[1] - 1, e[2]});
        }
        int[] dist = new int[n];
        Arrays.fill(dist, inf);
        dist[k - 1] = 0;
        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        pq.offer(new int[] {0, k - 1});
        while (!pq.isEmpty()) {
            var p = pq.poll();
            int d = p[0], u = p[1];
            if (d > dist[u]) {
                continue;
            }
            for (var e : g[u]) {
                int v = e[0], w = e[1];
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.offer(new int[] {dist[v], v});
                }
            }
        }
        int ans = Arrays.stream(dist).max().getAsInt();
        return ans == inf ? -1 : ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        const int inf = 1 << 29;
        using pii = pair<int, int>;
        vector<vector<pii>> g(n);
        for (auto& edge : times) {
            g[edge[0] - 1].emplace_back(edge[1] - 1, edge[2]);
        }

        vector<int> dist(n, inf);
        dist[k - 1] = 0;
        priority_queue<pii, vector<pii>, greater<>> pq;
        pq.emplace(0, k - 1);

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (d > dist[u]) {
                continue;
            }
            for (auto& [v, w] : g[u]) {
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.emplace(dist[v], v);
                }
            }
        }

        int ans = ranges::max(dist);
        return ans == inf ? -1 : ans;
    }
};
```

#### Go

```go
func networkDelayTime(times [][]int, n int, k int) int {
	g := make([][][2]int, n)
	for _, e := range times {
		u, v, w := e[0]-1, e[1]-1, e[2]
		g[u] = append(g[u], [2]int{v, w})
	}
	dist := make([]int, n)
	const inf int = 1 << 29
	for i := range dist {
		dist[i] = inf
	}
	dist[k-1] = 0
	pq := hp{{0, k - 1}}
	for len(pq) > 0 {
		p := heap.Pop(&pq).(pair)
		d, u := p.x, p.i
		if d > dist[u] {
			continue
		}
		for _, e := range g[u] {
			v, w := e[0], e[1]
			if nd := d + w; nd < dist[v] {
				dist[v] = nd
				heap.Push(&pq, pair{nd, v})
			}
		}
	}
	if ans := slices.Max(dist); ans < inf {
		return ans
	}
	return -1

}

type pair struct{ x, i int }
type hp []pair

func (h hp) Len() int           { return len(h) }
func (h hp) Less(i, j int) bool { return h[i].x < h[j].x }
func (h hp) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *hp) Push(x any)        { *h = append(*h, x.(pair)) }
func (h *hp) Pop() (x any)      { a := *h; x = a[len(a)-1]; *h = a[:len(a)-1]; return }
```

#### TypeScript

```ts
function networkDelayTime(times: number[][], n: number, k: number): number {
    const g: [number, number][][] = Array.from({ length: n }, () => []);
    for (const [u, v, w] of times) {
        g[u - 1].push([v - 1, w]);
    }
    const dist: number[] = Array(n).fill(Infinity);
    dist[k - 1] = 0;
    const pq = new MinPriorityQueue({ priority: v => v[0] });
    pq.enqueue([0, k - 1]);
    while (!pq.isEmpty()) {
        const [d, u] = pq.dequeue().element;
        if (d > dist[u]) {
            continue;
        }
        for (const [v, w] of g[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.enqueue([dist[v], v]);
            }
        }
    }
    const ans = Math.max(...dist);
    return ans === Infinity ? -1 : ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [744. 寻找比目标字母大的最小字母](https://leetcode.cn/problems/find-smallest-letter-greater-than-target){#744}

{{< tabs "744" >}}

{{% tab "python" %}}
```python
class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        i = bisect_right(letters, ord(target), key=lambda c: ord(c))
        return letters[i % len(letters)]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public char nextGreatestLetter(char[] letters, char target) {
        int i = Arrays.binarySearch(letters, (char) (target + 1));
        i = i < 0 ? -i - 1 : i;
        return letters[i % letters.length];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int i = upper_bound(letters.begin(), letters.end(), target) - letters.begin();
        return letters[i % letters.size()];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func nextGreatestLetter(letters []byte, target byte) byte {
	i := sort.Search(len(letters), func(i int) bool { return letters[i] > target })
	return letters[i%len(letters)]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function nextGreatestLetter(letters: string[], target: string): string {
    let [l, r] = [0, letters.length];
    while (l < r) {
        const mid = (l + r) >> 1;
        if (letters[mid] > target) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return letters[l % letters.length];
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn next_greatest_letter(letters: Vec<char>, target: char) -> char {
        let mut l = 0;
        let mut r = letters.len();
        while l < r {
            let mid = l + (r - l) / 2;
            if letters[mid] > target {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        letters[l % letters.len()]
    }
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param String[] $letters
     * @param String $target
     * @return String
     */
    function nextGreatestLetter($letters, $target) {
        $l = 0;
        $r = count($letters);
        while ($l < $r) {
            $mid = $l + $r >> 1;
            if ($letters[$mid] > $target) {
                $r = $mid;
            } else {
                $l = $mid + 1;
            }
        }
        return $letters[$l % count($letters)];
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符数组 <code>letters</code>，该数组按<strong>非递减顺序</strong>排序，以及一个字符 <code>target</code>。<code>letters</code>&nbsp;里<strong>至少有两个不同</strong>的字符。</p>

<p>返回&nbsp;<code>letters</code>&nbsp;中大于 <code>target</code> 的最小的字符。如果不存在这样的字符，则返回&nbsp;<code>letters</code> 的第一个字符。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入: </strong>letters = ['c', 'f', 'j']，target = 'a'
<strong>输出:</strong> 'c'
<strong>解释：</strong>letters 中字典上比 'a' 大的最小字符是 'c'。</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> letters = ['c','f','j'], target = 'c'
<strong>输出:</strong> 'f'
<strong>解释：</strong>letters 中字典顺序上大于 'c' 的最小字符是 'f'。</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入:</strong> letters = ['x','x','y','y'], target = 'z'
<strong>输出:</strong> 'x'
<strong>解释：</strong>letters 中没有一个字符在字典上大于 'z'，所以我们返回 letters[0]。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= letters.length &lt;= 10<sup>4</sup></code></li>
	<li><code>letters[i]</code>&nbsp;是一个小写字母</li>
	<li><code>letters</code> 按<strong>非递减顺序</strong>排序</li>
	<li><code>letters</code> 最少包含两个不同的字母</li>
	<li><code>target</code> 是一个小写字母</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二分查找

由于 $\textit{letters}$ 是按照非递减顺序排序的，所以我们可以使用二分查找来找到大于 `target` 的最小字符。

我们定义二分查找的左边界 $l = 0$，右边界 $r = n$。对于每一次二分查找，我们计算中间位置 $mid = (l + r) / 2$，如果 $letters[mid] > \textit{target}$，则说明我们需要在左半部分继续查找，即 $r = mid$；否则我们需要在右半部分继续查找，即 $l = mid + 1$。

最后我们返回 $letters[l \mod n]$ 即可。

时间复杂度 $O(\log n)$，其中 $n$ 是 $\textit{letters}$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        i = bisect_right(letters, ord(target), key=lambda c: ord(c))
        return letters[i % len(letters)]
```

#### Java

```java
class Solution {
    public char nextGreatestLetter(char[] letters, char target) {
        int i = Arrays.binarySearch(letters, (char) (target + 1));
        i = i < 0 ? -i - 1 : i;
        return letters[i % letters.length];
    }
}
```

#### C++

```cpp
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int i = upper_bound(letters.begin(), letters.end(), target) - letters.begin();
        return letters[i % letters.size()];
    }
};
```

#### Go

```go
func nextGreatestLetter(letters []byte, target byte) byte {
	i := sort.Search(len(letters), func(i int) bool { return letters[i] > target })
	return letters[i%len(letters)]
}
```

#### TypeScript

```ts
function nextGreatestLetter(letters: string[], target: string): string {
    let [l, r] = [0, letters.length];
    while (l < r) {
        const mid = (l + r) >> 1;
        if (letters[mid] > target) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return letters[l % letters.length];
}
```

#### Rust

```rust
impl Solution {
    pub fn next_greatest_letter(letters: Vec<char>, target: char) -> char {
        let mut l = 0;
        let mut r = letters.len();
        while l < r {
            let mid = l + (r - l) / 2;
            if letters[mid] > target {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        letters[l % letters.len()]
    }
}
```

#### PHP

```php
class Solution {
    /**
     * @param String[] $letters
     * @param String $target
     * @return String
     */
    function nextGreatestLetter($letters, $target) {
        $l = 0;
        $r = count($letters);
        while ($l < $r) {
            $mid = $l + $r >> 1;
            if ($letters[$mid] > $target) {
                $r = $mid;
            } else {
                $l = $mid + 1;
            }
        }
        return $letters[$l % count($letters)];
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [745. 前缀和后缀搜索](https://leetcode.cn/problems/prefix-and-suffix-search){#745}

{{< tabs "745" >}}

{{% tab "python" %}}
```python
class Trie:
    def __init__(self):
        self.children = [None] * 26
        self.indexes = []

    def insert(self, word, i):
        node = self
        for c in word:
            idx = ord(c) - ord("a")
            if node.children[idx] is None:
                node.children[idx] = Trie()
            node = node.children[idx]
            node.indexes.append(i)

    def search(self, pref):
        node = self
        for c in pref:
            idx = ord(c) - ord("a")
            if node.children[idx] is None:
                return []
            node = node.children[idx]
        return node.indexes


class WordFilter:
    def __init__(self, words: List[str]):
        self.p = Trie()
        self.s = Trie()
        for i, w in enumerate(words):
            self.p.insert(w, i)
            self.s.insert(w[::-1], i)

    def f(self, pref: str, suff: str) -> int:
        a = self.p.search(pref)
        b = self.s.search(suff[::-1])
        if not a or not b:
            return -1
        i, j = len(a) - 1, len(b) - 1
        while ~i and ~j:
            if a[i] == b[j]:
                return a[i]
            if a[i] > b[j]:
                i -= 1
            else:
                j -= 1
        return -1


# Your WordFilter object will be instantiated and called as such:
# obj = WordFilter(words)
# param_1 = obj.f(pref,suff)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Trie {
    Trie[] children = new Trie[26];
    List<Integer> indexes = new ArrayList<>();

    void insert(String word, int i) {
        Trie node = this;
        for (char c : word.toCharArray()) {
            c -= 'a';
            if (node.children[c] == null) {
                node.children[c] = new Trie();
            }
            node = node.children[c];
            node.indexes.add(i);
        }
    }

    List<Integer> search(String pref) {
        Trie node = this;
        for (char c : pref.toCharArray()) {
            c -= 'a';
            if (node.children[c] == null) {
                return Collections.emptyList();
            }
            node = node.children[c];
        }
        return node.indexes;
    }
}

class WordFilter {
    private Trie p = new Trie();
    private Trie s = new Trie();

    public WordFilter(String[] words) {
        for (int i = 0; i < words.length; ++i) {
            String w = words[i];
            p.insert(w, i);
            s.insert(new StringBuilder(w).reverse().toString(), i);
        }
    }

    public int f(String pref, String suff) {
        suff = new StringBuilder(suff).reverse().toString();
        List<Integer> a = p.search(pref);
        List<Integer> b = s.search(suff);
        if (a.isEmpty() || b.isEmpty()) {
            return -1;
        }
        int i = a.size() - 1, j = b.size() - 1;
        while (i >= 0 && j >= 0) {
            int c = a.get(i), d = b.get(j);
            if (c == d) {
                return c;
            }
            if (c > d) {
                --i;
            } else {
                --j;
            }
        }
        return -1;
    }
}

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter obj = new WordFilter(words);
 * int param_1 = obj.f(pref,suff);
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class WordFilter {
public:
    unordered_map<string, int> d;

    WordFilter(vector<string>& words) {
        for (int k = 0; k < words.size(); ++k) {
            string w = words[k];
            int n = w.size();
            for (int i = 0; i <= n; ++i) {
                string a = w.substr(0, i);
                for (int j = 0; j <= n; ++j) {
                    string b = w.substr(j, n - j);
                    d[a + "." + b] = k;
                }
            }
        }
    }

    int f(string pref, string suff) {
        string key = pref + "." + suff;
        if (d.count(key)) return d[key];
        return -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type Trie struct {
	children [26]*Trie
	indexes  []int
}

func newTrie() *Trie {
	return &Trie{indexes: []int{}}
}
func (this *Trie) insert(word string, i int) {
	node := this
	for _, c := range word {
		idx := c - 'a'
		if node.children[idx] == nil {
			node.children[idx] = newTrie()
		}
		node = node.children[idx]
		node.indexes = append(node.indexes, i)
	}
}

func (this *Trie) search(pref string) []int {
	node := this
	for _, c := range pref {
		idx := c - 'a'
		if node.children[idx] == nil {
			return []int{}
		}
		node = node.children[idx]
	}
	return node.indexes
}

type WordFilter struct {
	p *Trie
	s *Trie
}

func Constructor(words []string) WordFilter {
	p := newTrie()
	s := newTrie()
	for i, w := range words {
		p.insert(w, i)
		s.insert(reverse(w), i)
	}
	return WordFilter{p, s}
}

func (this *WordFilter) F(pref string, suff string) int {
	a := this.p.search(pref)
	b := this.s.search(reverse(suff))
	if len(a) == 0 || len(b) == 0 {
		return -1
	}
	i, j := len(a)-1, len(b)-1
	for i >= 0 && j >= 0 {
		if a[i] == b[j] {
			return a[i]
		}
		if a[i] > b[j] {
			i--
		} else {
			j--
		}
	}
	return -1
}

func reverse(w string) string {
	ww := []byte(w)
	for i, j := 0, len(w)-1; i < j; i++ {
		ww[i], ww[j] = ww[j], ww[i]
		j--
	}
	return string(ww)
}

/**
 * Your WordFilter object will be instantiated and called as such:
 * obj := Constructor(words);
 * param_1 := obj.F(pref,suff);
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>设计一个包含一些单词的特殊词典，并能够通过前缀和后缀来检索单词。</p>

<p>实现 <code>WordFilter</code> 类：</p>

<ul>
	<li><code>WordFilter(string[] words)</code> 使用词典中的单词 <code>words</code> 初始化对象。</li>
	<li><code>f(string pref, string suff)</code> 返回词典中具有前缀&nbsp;<code>pref</code>&nbsp;和后缀 <code>suff</code>&nbsp;的单词的下标。如果存在不止一个满足要求的下标，返回其中 <strong>最大的下标</strong> 。如果不存在这样的单词，返回 <code>-1</code> 。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre>
<strong>输入</strong>
["WordFilter", "f"]
[[["apple"]], ["a", "e"]]
<strong>输出</strong>
[null, 0]
<strong>解释</strong>
WordFilter wordFilter = new WordFilter(["apple"]);
wordFilter.f("a", "e"); // 返回 0 ，因为下标为 0 的单词：前缀 prefix = "a" 且 后缀 suffix = "e" 。
</pre>

&nbsp;

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= words[i].length &lt;= 7</code></li>
	<li><code>1 &lt;= pref.length, suff.length &lt;= 7</code></li>
	<li><code>words[i]</code>、<code>pref</code> 和 <code>suff</code> 仅由小写英文字母组成</li>
	<li>最多对函数 <code>f</code> 执行 <code>10<sup>4</sup></code> 次调用</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：暴力哈希

遍历 $words$ 的每个单词 $w$，将 $w$ 的所有前缀、后缀对存放到哈希表中。

<!-- tabs:start -->

#### Python3

```python
class WordFilter:
    def __init__(self, words: List[str]):
        self.d = {}
        for k, w in enumerate(words):
            n = len(w)
            for i in range(n + 1):
                a = w[:i]
                for j in range(n + 1):
                    b = w[j:]
                    self.d[(a, b)] = k

    def f(self, pref: str, suff: str) -> int:
        return self.d.get((pref, suff), -1)


# Your WordFilter object will be instantiated and called as such:
# obj = WordFilter(words)
# param_1 = obj.f(pref,suff)
```

#### Java

```java
class WordFilter {
    private Map<String, Integer> d = new HashMap<>();

    public WordFilter(String[] words) {
        for (int k = 0; k < words.length; ++k) {
            String w = words[k];
            int n = w.length();
            for (int i = 0; i <= n; ++i) {
                String a = w.substring(0, i);
                for (int j = 0; j <= n; ++j) {
                    String b = w.substring(j);
                    d.put(a + "." + b, k);
                }
            }
        }
    }

    public int f(String pref, String suff) {
        return d.getOrDefault(pref + "." + suff, -1);
    }
}

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter obj = new WordFilter(words);
 * int param_1 = obj.f(pref,suff);
 */
```

#### C++

```cpp
class WordFilter {
public:
    unordered_map<string, int> d;

    WordFilter(vector<string>& words) {
        for (int k = 0; k < words.size(); ++k) {
            string w = words[k];
            int n = w.size();
            for (int i = 0; i <= n; ++i) {
                string a = w.substr(0, i);
                for (int j = 0; j <= n; ++j) {
                    string b = w.substr(j, n - j);
                    d[a + "." + b] = k;
                }
            }
        }
    }

    int f(string pref, string suff) {
        string key = pref + "." + suff;
        if (d.count(key)) return d[key];
        return -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */
```

#### Go

```go
type WordFilter struct {
	d map[string]int
}

func Constructor(words []string) WordFilter {
	d := map[string]int{}
	for k, w := range words {
		n := len(w)
		for i := 0; i <= n; i++ {
			a := w[:i]
			for j := 0; j <= n; j++ {
				b := w[j:]
				d[a+"."+b] = k
			}
		}
	}
	return WordFilter{d}
}

func (this *WordFilter) F(pref string, suff string) int {
	if v, ok := this.d[pref+"."+suff]; ok {
		return v
	}
	return -1
}

/**
 * Your WordFilter object will be instantiated and called as such:
 * obj := Constructor(words);
 * param_1 := obj.F(pref,suff);
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：双前缀树

<!-- tabs:start -->

#### Python3

```python
class Trie:
    def __init__(self):
        self.children = [None] * 26
        self.indexes = []

    def insert(self, word, i):
        node = self
        for c in word:
            idx = ord(c) - ord("a")
            if node.children[idx] is None:
                node.children[idx] = Trie()
            node = node.children[idx]
            node.indexes.append(i)

    def search(self, pref):
        node = self
        for c in pref:
            idx = ord(c) - ord("a")
            if node.children[idx] is None:
                return []
            node = node.children[idx]
        return node.indexes


class WordFilter:
    def __init__(self, words: List[str]):
        self.p = Trie()
        self.s = Trie()
        for i, w in enumerate(words):
            self.p.insert(w, i)
            self.s.insert(w[::-1], i)

    def f(self, pref: str, suff: str) -> int:
        a = self.p.search(pref)
        b = self.s.search(suff[::-1])
        if not a or not b:
            return -1
        i, j = len(a) - 1, len(b) - 1
        while ~i and ~j:
            if a[i] == b[j]:
                return a[i]
            if a[i] > b[j]:
                i -= 1
            else:
                j -= 1
        return -1


# Your WordFilter object will be instantiated and called as such:
# obj = WordFilter(words)
# param_1 = obj.f(pref,suff)
```

#### Java

```java
class Trie {
    Trie[] children = new Trie[26];
    List<Integer> indexes = new ArrayList<>();

    void insert(String word, int i) {
        Trie node = this;
        for (char c : word.toCharArray()) {
            c -= 'a';
            if (node.children[c] == null) {
                node.children[c] = new Trie();
            }
            node = node.children[c];
            node.indexes.add(i);
        }
    }

    List<Integer> search(String pref) {
        Trie node = this;
        for (char c : pref.toCharArray()) {
            c -= 'a';
            if (node.children[c] == null) {
                return Collections.emptyList();
            }
            node = node.children[c];
        }
        return node.indexes;
    }
}

class WordFilter {
    private Trie p = new Trie();
    private Trie s = new Trie();

    public WordFilter(String[] words) {
        for (int i = 0; i < words.length; ++i) {
            String w = words[i];
            p.insert(w, i);
            s.insert(new StringBuilder(w).reverse().toString(), i);
        }
    }

    public int f(String pref, String suff) {
        suff = new StringBuilder(suff).reverse().toString();
        List<Integer> a = p.search(pref);
        List<Integer> b = s.search(suff);
        if (a.isEmpty() || b.isEmpty()) {
            return -1;
        }
        int i = a.size() - 1, j = b.size() - 1;
        while (i >= 0 && j >= 0) {
            int c = a.get(i), d = b.get(j);
            if (c == d) {
                return c;
            }
            if (c > d) {
                --i;
            } else {
                --j;
            }
        }
        return -1;
    }
}

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter obj = new WordFilter(words);
 * int param_1 = obj.f(pref,suff);
 */
```

#### Go

```go
type Trie struct {
	children [26]*Trie
	indexes  []int
}

func newTrie() *Trie {
	return &Trie{indexes: []int{}}
}
func (this *Trie) insert(word string, i int) {
	node := this
	for _, c := range word {
		idx := c - 'a'
		if node.children[idx] == nil {
			node.children[idx] = newTrie()
		}
		node = node.children[idx]
		node.indexes = append(node.indexes, i)
	}
}

func (this *Trie) search(pref string) []int {
	node := this
	for _, c := range pref {
		idx := c - 'a'
		if node.children[idx] == nil {
			return []int{}
		}
		node = node.children[idx]
	}
	return node.indexes
}

type WordFilter struct {
	p *Trie
	s *Trie
}

func Constructor(words []string) WordFilter {
	p := newTrie()
	s := newTrie()
	for i, w := range words {
		p.insert(w, i)
		s.insert(reverse(w), i)
	}
	return WordFilter{p, s}
}

func (this *WordFilter) F(pref string, suff string) int {
	a := this.p.search(pref)
	b := this.s.search(reverse(suff))
	if len(a) == 0 || len(b) == 0 {
		return -1
	}
	i, j := len(a)-1, len(b)-1
	for i >= 0 && j >= 0 {
		if a[i] == b[j] {
			return a[i]
		}
		if a[i] > b[j] {
			i--
		} else {
			j--
		}
	}
	return -1
}

func reverse(w string) string {
	ww := []byte(w)
	for i, j := 0, len(w)-1; i < j; i++ {
		ww[i], ww[j] = ww[j], ww[i]
		j--
	}
	return string(ww)
}

/**
 * Your WordFilter object will be instantiated and called as such:
 * obj := Constructor(words);
 * param_1 := obj.F(pref,suff);
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [746. 使用最小花费爬楼梯](https://leetcode.cn/problems/min-cost-climbing-stairs){#746}

{{< tabs "746" >}}

{{% tab "python" %}}
```python
class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        f = g = 0
        for i in range(2, len(cost) + 1):
            f, g = g, min(f + cost[i - 2], g + cost[i - 1])
        return g
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minCostClimbingStairs(int[] cost) {
        int f = 0, g = 0;
        for (int i = 2; i <= cost.length; ++i) {
            int gg = Math.min(f + cost[i - 2], g + cost[i - 1]);
            f = g;
            g = gg;
        }
        return g;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int f = 0, g = 0;
        for (int i = 2; i <= cost.size(); ++i) {
            int gg = min(f + cost[i - 2], g + cost[i - 1]);
            f = g;
            g = gg;
        }
        return g;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minCostClimbingStairs(cost []int) int {
	var f, g int
	for i := 2; i <= n; i++ {
		f, g = g, min(f+cost[i-2], g+cost[i-1])
	}
	return g
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minCostClimbingStairs(cost: number[]): number {
    let [f, g] = [0, 0];
    for (let i = 1; i < cost.length; ++i) {
        [f, g] = [g, Math.min(f + cost[i - 1], g + cost[i])];
    }
    return g;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn min_cost_climbing_stairs(cost: Vec<i32>) -> i32 {
        let (mut f, mut g) = (0, 0);
        for i in 2..=cost.len() {
            let gg = std::cmp::min(f + cost[i - 2], g + cost[i - 1]);
            f = g;
            g = gg;
        }
        g
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
function minCostClimbingStairs(cost) {
    let [f, g] = [0, 0];
    for (let i = 1; i < cost.length; ++i) {
        [f, g] = [g, Math.min(f + cost[i - 1], g + cost[i])];
    }
    return g;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>cost</code> ，其中 <code>cost[i]</code> 是从楼梯第 <code>i</code> 个台阶向上爬需要支付的费用。一旦你支付此费用，即可选择向上爬一个或者两个台阶。</p>

<p>你可以选择从下标为 <code>0</code> 或下标为 <code>1</code> 的台阶开始爬楼梯。</p>

<p>请你计算并返回达到楼梯顶部的最低花费。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>cost = [10,<em><strong>15</strong></em>,20]
<strong>输出：</strong>15
<strong>解释：</strong>你将从下标为 1 的台阶开始。
- 支付 15 ，向上爬两个台阶，到达楼梯顶部。
总花费为 15 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>cost = [<em><strong>1</strong></em>,100,<em><strong>1</strong></em>,1,<em><strong>1</strong></em>,100,<em><strong>1</strong></em>,<em><strong>1</strong></em>,100,<em><strong>1</strong></em>]
<strong>输出：</strong>6
<strong>解释：</strong>你将从下标为 0 的台阶开始。
- 支付 1 ，向上爬两个台阶，到达下标为 2 的台阶。
- 支付 1 ，向上爬两个台阶，到达下标为 4 的台阶。
- 支付 1 ，向上爬两个台阶，到达下标为 6 的台阶。
- 支付 1 ，向上爬一个台阶，到达下标为 7 的台阶。
- 支付 1 ，向上爬两个台阶，到达下标为 9 的台阶。
- 支付 1 ，向上爬一个台阶，到达楼梯顶部。
总花费为 6 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= cost.length &lt;= 1000</code></li>
	<li><code>0 &lt;= cost[i] &lt;= 999</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

我们设计一个函数 $\textit{dfs}(i)$，表示从第 $i$ 个阶梯开始爬楼梯所需要的最小花费。那么答案为 $\min(\textit{dfs}(0), \textit{dfs}(1))$。

函数 $\textit{dfs}(i)$ 的执行过程如下：

-   如果 $i \ge \textit{len(cost)}$，表示当前位置已经超过了楼梯顶部，不需要再爬楼梯，返回 $0$；
-   否则，我们可以选择爬 $1$ 级楼梯，花费为 $\textit{cost}[i]$，然后递归调用 $\textit{dfs}(i + 1)$；也可以选择爬 $2$ 级楼梯，花费为 $\textit{cost}[i]$，然后递归调用 $\textit{dfs}(i + 2)$；
-   返回两种方案中的最小花费。

为了避免重复计算，我们使用记忆化搜索的方法，将已经计算过的结果保存在数组或哈希表中。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 $\textit{cost}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        @cache
        def dfs(i: int) -> int:
            if i >= len(cost):
                return 0
            return cost[i] + min(dfs(i + 1), dfs(i + 2))

        return min(dfs(0), dfs(1))
```

#### Java

```java
class Solution {
    private Integer[] f;
    private int[] cost;

    public int minCostClimbingStairs(int[] cost) {
        this.cost = cost;
        f = new Integer[cost.length];
        return Math.min(dfs(0), dfs(1));
    }

    private int dfs(int i) {
        if (i >= cost.length) {
            return 0;
        }
        if (f[i] == null) {
            f[i] = cost[i] + Math.min(dfs(i + 1), dfs(i + 2));
        }
        return f[i];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int f[n];
        memset(f, -1, sizeof(f));
        auto dfs = [&](this auto&& dfs, int i) -> int {
            if (i >= n) {
                return 0;
            }
            if (f[i] < 0) {
                f[i] = cost[i] + min(dfs(i + 1), dfs(i + 2));
            }
            return f[i];
        };
        return min(dfs(0), dfs(1));
    }
};
```

#### Go

```go
func minCostClimbingStairs(cost []int) int {
	n := len(cost)
	f := make([]int, n)
	for i := range f {
		f[i] = -1
	}
	var dfs func(int) int
	dfs = func(i int) int {
		if i >= n {
			return 0
		}
		if f[i] < 0 {
			f[i] = cost[i] + min(dfs(i+1), dfs(i+2))
		}
		return f[i]
	}
	return min(dfs(0), dfs(1))
}
```

#### TypeScript

```ts
function minCostClimbingStairs(cost: number[]): number {
    const n = cost.length;
    const f: number[] = Array(n).fill(-1);
    const dfs = (i: number): number => {
        if (i >= n) {
            return 0;
        }
        if (f[i] < 0) {
            f[i] = cost[i] + Math.min(dfs(i + 1), dfs(i + 2));
        }
        return f[i];
    };
    return Math.min(dfs(0), dfs(1));
}
```

#### Rust

```rust
impl Solution {
    pub fn min_cost_climbing_stairs(cost: Vec<i32>) -> i32 {
        let n = cost.len();
        let mut f = vec![-1; n];

        fn dfs(i: usize, cost: &Vec<i32>, f: &mut Vec<i32>, n: usize) -> i32 {
            if i >= n {
                return 0;
            }
            if f[i] < 0 {
                let next1 = dfs(i + 1, cost, f, n);
                let next2 = dfs(i + 2, cost, f, n);
                f[i] = cost[i] + next1.min(next2);
            }
            f[i]
        }

        dfs(0, &cost, &mut f, n).min(dfs(1, &cost, &mut f, n))
    }
}
```

#### JavaScript

```js
function minCostClimbingStairs(cost) {
    const n = cost.length;
    const f = Array(n).fill(-1);
    const dfs = i => {
        if (i >= n) {
            return 0;
        }
        if (f[i] < 0) {
            f[i] = cost[i] + Math.min(dfs(i + 1), dfs(i + 2));
        }
        return f[i];
    };
    return Math.min(dfs(0), dfs(1));
}
```

<!-- tab:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：动态规划

我们定义 $f[i]$ 表示到达第 $i$ 个阶梯所需要的最小花费，初始时 $f[0] = f[1] = 0$，答案即为 $f[n]$。

当 $i \ge 2$ 时，我们可以从第 $i - 1$ 个阶梯使用 $1$ 步直接到达第 $i$ 个阶梯，或者从第 $i - 2$ 个阶梯使用 $2$ 步到达第 $i$ 个阶梯，因此我们有状态转移方程：

$$
f[i] = \min(f[i - 1] + cost[i - 1], f[i - 2] + cost[i - 2])
$$

最终的答案即为 $f[n]$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 $\textit{cost}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n = len(cost)
        f = [0] * (n + 1)
        for i in range(2, n + 1):
            f[i] = min(f[i - 2] + cost[i - 2], f[i - 1] + cost[i - 1])
        return f[n]
```

#### Java

```java
class Solution {
    public int minCostClimbingStairs(int[] cost) {
        int n = cost.length;
        int[] f = new int[n + 1];
        for (int i = 2; i <= n; ++i) {
            f[i] = Math.min(f[i - 2] + cost[i - 2], f[i - 1] + cost[i - 1]);
        }
        return f[n];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> f(n + 1);
        for (int i = 2; i <= n; ++i) {
            f[i] = min(f[i - 2] + cost[i - 2], f[i - 1] + cost[i - 1]);
        }
        return f[n];
    }
};
```

#### Go

```go
func minCostClimbingStairs(cost []int) int {
	n := len(cost)
	f := make([]int, n+1)
	for i := 2; i <= n; i++ {
		f[i] = min(f[i-1]+cost[i-1], f[i-2]+cost[i-2])
	}
	return f[n]
}
```

#### TypeScript

```ts
function minCostClimbingStairs(cost: number[]): number {
    const n = cost.length;
    const f: number[] = Array(n + 1).fill(0);
    for (let i = 2; i <= n; ++i) {
        f[i] = Math.min(f[i - 1] + cost[i - 1], f[i - 2] + cost[i - 2]);
    }
    return f[n];
}
```

#### Rust

```rust
impl Solution {
    pub fn min_cost_climbing_stairs(cost: Vec<i32>) -> i32 {
        let n = cost.len();
        let mut f = vec![0; n + 1];
        for i in 2..=n {
            f[i] = std::cmp::min(f[i - 2] + cost[i - 2], f[i - 1] + cost[i - 1]);
        }
        f[n]
    }
}
```

#### JavaScript

```js
function minCostClimbingStairs(cost) {
    const n = cost.length;
    const f = Array(n + 1).fill(0);
    for (let i = 2; i <= n; ++i) {
        f[i] = Math.min(f[i - 1] + cost[i - 1], f[i - 2] + cost[i - 2]);
    }
    return f[n];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法三：动态规划（空间优化）

我们注意到，状态转移方程中的 $f[i]$ 只和 $f[i - 1]$ 与 $f[i - 2]$ 有关，因此我们可以使用两个变量 $f$ 和 $g$ 交替地记录 $f[i - 2]$ 和 $f[i - 1]$ 的值，这样空间复杂度可以优化到 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        f = g = 0
        for i in range(2, len(cost) + 1):
            f, g = g, min(f + cost[i - 2], g + cost[i - 1])
        return g
```

#### Java

```java
class Solution {
    public int minCostClimbingStairs(int[] cost) {
        int f = 0, g = 0;
        for (int i = 2; i <= cost.length; ++i) {
            int gg = Math.min(f + cost[i - 2], g + cost[i - 1]);
            f = g;
            g = gg;
        }
        return g;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int f = 0, g = 0;
        for (int i = 2; i <= cost.size(); ++i) {
            int gg = min(f + cost[i - 2], g + cost[i - 1]);
            f = g;
            g = gg;
        }
        return g;
    }
};
```

#### Go

```go
func minCostClimbingStairs(cost []int) int {
	var f, g int
	for i := 2; i <= n; i++ {
		f, g = g, min(f+cost[i-2], g+cost[i-1])
	}
	return g
}
```

#### TypeScript

```ts
function minCostClimbingStairs(cost: number[]): number {
    let [f, g] = [0, 0];
    for (let i = 1; i < cost.length; ++i) {
        [f, g] = [g, Math.min(f + cost[i - 1], g + cost[i])];
    }
    return g;
}
```

#### Rust

```rust
impl Solution {
    pub fn min_cost_climbing_stairs(cost: Vec<i32>) -> i32 {
        let (mut f, mut g) = (0, 0);
        for i in 2..=cost.len() {
            let gg = std::cmp::min(f + cost[i - 2], g + cost[i - 1]);
            f = g;
            g = gg;
        }
        g
    }
}
```

#### JavaScript

```js
function minCostClimbingStairs(cost) {
    let [f, g] = [0, 0];
    for (let i = 1; i < cost.length; ++i) {
        [f, g] = [g, Math.min(f + cost[i - 1], g + cost[i])];
    }
    return g;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [747. 至少是其他数字两倍的最大数](https://leetcode.cn/problems/largest-number-at-least-twice-of-others){#747}

{{< tabs "747" >}}

{{% tab "python" %}}
```python
class Solution:
    def dominantIndex(self, nums: List[int]) -> int:
        x, y = nlargest(2, nums)
        return nums.index(x) if x >= 2 * y else -1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int dominantIndex(int[] nums) {
        int n = nums.length;
        int k = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[k] < nums[i]) {
                k = i;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (k != i && nums[k] < nums[i] * 2) {
                return -1;
            }
        }
        return k;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int n = nums.size();
        int k = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[k] < nums[i]) {
                k = i;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (k != i && nums[k] < nums[i] * 2) {
                return -1;
            }
        }
        return k;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func dominantIndex(nums []int) int {
	k := 0
	for i, x := range nums {
		if nums[k] < x {
			k = i
		}
	}
	for i, x := range nums {
		if k != i && nums[k] < x*2 {
			return -1
		}
	}
	return k
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function dominantIndex(nums: number[]): number {
    let k = 0;
    for (let i = 0; i < nums.length; ++i) {
        if (nums[i] > nums[k]) {
            k = i;
        }
    }
    for (let i = 0; i < nums.length; ++i) {
        if (i !== k && nums[k] < nums[i] * 2) {
            return -1;
        }
    }
    return k;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var dominantIndex = function (nums) {
    let k = 0;
    for (let i = 0; i < nums.length; ++i) {
        if (nums[i] > nums[k]) {
            k = i;
        }
    }
    for (let i = 0; i < nums.length; ++i) {
        if (i !== k && nums[k] < nums[i] * 2) {
            return -1;
        }
    }
    return k;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>nums</code> ，其中总是存在 <strong>唯一的</strong> 一个最大整数 。</p>

<p>请你找出数组中的最大元素并检查它是否 <strong>至少是数组中每个其他数字的两倍</strong> 。如果是，则返回 <strong>最大元素的下标</strong> ，否则返回 <code>-1</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [3,6,1,0]
<strong>输出：</strong>1
<strong>解释：</strong>6 是最大的整数，对于数组中的其他整数，6 至少是数组中其他元素的两倍。6 的下标是 1 ，所以返回 1 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3,4]
<strong>输出：</strong>-1
<strong>解释：</strong>4 没有超过 3 的两倍大，所以返回 -1 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 50</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 100</code></li>
	<li><code>nums</code> 中的最大元素是唯一的</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：遍历

我们可以遍历数组 $nums$，找到数组中的最大值 $x$ 和第二大的值 $y$，如果 $x \ge 2y$，则返回 $x$ 的下标，否则返回 $-1$。

我们也可以先找到数组中的最大值 $x$，同时找到最大值 $x$ 的下标 $k$。然后再遍历一次数组，如果发现 $k$ 以外的元素 $y$ 满足 $x < 2y$，则返回 $-1$。否则遍历结束后返回 $k$。

时间复杂度 $O(n)$，其中 $n$ 是数组 $nums$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def dominantIndex(self, nums: List[int]) -> int:
        x, y = nlargest(2, nums)
        return nums.index(x) if x >= 2 * y else -1
```

#### Java

```java
class Solution {
    public int dominantIndex(int[] nums) {
        int n = nums.length;
        int k = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[k] < nums[i]) {
                k = i;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (k != i && nums[k] < nums[i] * 2) {
                return -1;
            }
        }
        return k;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int n = nums.size();
        int k = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[k] < nums[i]) {
                k = i;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (k != i && nums[k] < nums[i] * 2) {
                return -1;
            }
        }
        return k;
    }
};
```

#### Go

```go
func dominantIndex(nums []int) int {
	k := 0
	for i, x := range nums {
		if nums[k] < x {
			k = i
		}
	}
	for i, x := range nums {
		if k != i && nums[k] < x*2 {
			return -1
		}
	}
	return k
}
```

#### TypeScript

```ts
function dominantIndex(nums: number[]): number {
    let k = 0;
    for (let i = 0; i < nums.length; ++i) {
        if (nums[i] > nums[k]) {
            k = i;
        }
    }
    for (let i = 0; i < nums.length; ++i) {
        if (i !== k && nums[k] < nums[i] * 2) {
            return -1;
        }
    }
    return k;
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var dominantIndex = function (nums) {
    let k = 0;
    for (let i = 0; i < nums.length; ++i) {
        if (nums[i] > nums[k]) {
            k = i;
        }
    }
    for (let i = 0; i < nums.length; ++i) {
        if (i !== k && nums[k] < nums[i] * 2) {
            return -1;
        }
    }
    return k;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [748. 最短补全词](https://leetcode.cn/problems/shortest-completing-word){#748}

{{< tabs "748" >}}

{{% tab "python" %}}
```python
class Solution:
    def shortestCompletingWord(self, licensePlate: str, words: List[str]) -> str:
        cnt = Counter(c.lower() for c in licensePlate if c.isalpha())
        ans = None
        for w in words:
            if ans and len(w) >= len(ans):
                continue
            t = Counter(w)
            if all(v <= t[c] for c, v in cnt.items()):
                ans = w
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String shortestCompletingWord(String licensePlate, String[] words) {
        int[] cnt = new int[26];
        for (int i = 0; i < licensePlate.length(); ++i) {
            char c = licensePlate.charAt(i);
            if (Character.isLetter(c)) {
                cnt[Character.toLowerCase(c) - 'a']++;
            }
        }
        String ans = "";
        for (String w : words) {
            if (!ans.isEmpty() && w.length() >= ans.length()) {
                continue;
            }
            int[] t = new int[26];
            for (int i = 0; i < w.length(); ++i) {
                t[w.charAt(i) - 'a']++;
            }
            boolean ok = true;
            for (int i = 0; i < 26; ++i) {
                if (t[i] < cnt[i]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ans = w;
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
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        int cnt[26]{};
        for (char& c : licensePlate) {
            if (isalpha(c)) {
                ++cnt[tolower(c) - 'a'];
            }
        }
        string ans;
        for (auto& w : words) {
            if (ans.size() && ans.size() <= w.size()) {
                continue;
            }
            int t[26]{};
            for (char& c : w) {
                ++t[c - 'a'];
            }
            bool ok = true;
            for (int i = 0; i < 26; ++i) {
                if (cnt[i] > t[i]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ans = w;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func shortestCompletingWord(licensePlate string, words []string) (ans string) {
	cnt := [26]int{}
	for _, c := range licensePlate {
		if unicode.IsLetter(c) {
			cnt[unicode.ToLower(c)-'a']++
		}
	}
	for _, w := range words {
		if len(ans) > 0 && len(ans) <= len(w) {
			continue
		}
		t := [26]int{}
		for _, c := range w {
			t[c-'a']++
		}
		ok := true
		for i, v := range cnt {
			if t[i] < v {
				ok = false
				break
			}
		}
		if ok {
			ans = w
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function shortestCompletingWord(licensePlate: string, words: string[]): string {
    const cnt: number[] = Array(26).fill(0);
    for (const c of licensePlate) {
        const i = c.toLowerCase().charCodeAt(0) - 97;
        if (0 <= i && i < 26) {
            ++cnt[i];
        }
    }
    let ans = '';
    for (const w of words) {
        if (ans.length && ans.length <= w.length) {
            continue;
        }
        const t = Array(26).fill(0);
        for (const c of w) {
            ++t[c.charCodeAt(0) - 97];
        }
        let ok = true;
        for (let i = 0; i < 26; ++i) {
            if (t[i] < cnt[i]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            ans = w;
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn shortest_completing_word(license_plate: String, words: Vec<String>) -> String {
        let mut cnt = vec![0; 26];
        for c in license_plate.chars() {
            if c.is_ascii_alphabetic() {
                cnt[((c.to_ascii_lowercase() as u8) - b'a') as usize] += 1;
            }
        }
        let mut ans = String::new();
        for w in words {
            if !ans.is_empty() && w.len() >= ans.len() {
                continue;
            }
            let mut t = vec![0; 26];
            for c in w.chars() {
                t[((c as u8) - b'a') as usize] += 1;
            }
            let mut ok = true;
            for i in 0..26 {
                if t[i] < cnt[i] {
                    ok = false;
                    break;
                }
            }
            if ok {
                ans = w;
            }
        }
        ans
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串 <code>licensePlate</code> 和一个字符串数组 <code>words</code> ，请你找出&nbsp;<code>words</code> 中的 <strong>最短补全词</strong> 。</p>

<p><strong>补全词 </strong>是一个包含 <code>licensePlate</code> 中所有字母的单词。<strong>忽略</strong>&nbsp;<code>licensePlate</code> 中的 <strong>数字和空格 </strong>。<strong>不区分大小写</strong>。如果某个字母在 <code>licensePlate</code> 中出现不止一次，那么该字母在补全词中的出现次数应当一致或者更多。</p>

<p>例如：<code>licensePlate</code><code> = "aBc 12c"</code>，那么它的补全词应当包含字母 <code>'a'</code>、<code>'b'</code> （忽略大写）和两个 <code>'c'</code> 。可能的 <strong>补全词</strong> 有 <code>"abccdef"</code>、<code>"caaacab"</code> 以及 <code>"cbca"</code> 。</p>

<p>请返回 <code>words</code> 中的 <strong>最短补全词</strong> 。题目数据保证一定存在一个最短补全词。当有多个单词都符合最短补全词的匹配条件时取 <code>words</code> 中 <strong>第一个</strong> 出现的那个。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>licensePlate = "1s3 PSt", words = ["step", "steps", "stripe", "stepple"]
<strong>输出：</strong>"steps"
<strong>解释：</strong>最短补全词应该包括 "s"、"p"、"s"（忽略大小写） 以及 "t"。
"step" 包含 "t"、"p"，但只包含一个 "s"，所以它不符合条件。
"steps" 包含 "t"、"p" 和两个 "s"。
"stripe" 缺一个 "s"。
"stepple" 缺一个 "s"。
因此，"steps" 是唯一一个包含所有字母的单词，也是本例的答案。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>licensePlate = "1s3 456", words = ["looks", "pest", "stew", "show"]
<strong>输出：</strong>"pest"
<strong>解释：</strong>licensePlate 只包含字母 "s" 。所有的单词都包含字母 "s" ，其中 "pest"、"stew"、和 "show" 三者最短。答案是 "pest" ，因为它是三个单词中在 words 里最靠前的那个。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= licensePlate.length &lt;= 7</code></li>
	<li><code>licensePlate</code> 由数字、大小写字母或空格 <code>' '</code> 组成</li>
	<li><code>1 &lt;= words.length &lt;= 1000</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 15</code></li>
	<li><code>words[i]</code> 由小写英文字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数

我们先用哈希表或者一个长度为 $26$ 的数组 $cnt$ 统计字符串 `licensePlate` 中每个字母出现的次数，注意这里我们统一将字母转换为小写进行计数。

然后，我们遍历数组 `words` 中的每个单词 $w$，如果单词 $w$ 的长度比答案 $ans$ 的长度长，那么我们直接跳过该单词。否则，我们再用哈希表或者一个长度为 $26$ 的数组 $t$ 统计单词 $w$ 中每个字母出现的次数。如果对于任意一个字母，$t$ 中该字母出现的次数小于 $cnt$ 中该字母出现的次数，那么我们也可以直接跳过该单词。否则，我们就找到了一个满足条件的单词，我们更新答案 $ans$ 为当前单词 $w$。

时间复杂度 $O(n \times |\Sigma|)$，空间复杂度 $O(|\Sigma|)$，其中 $n$ 是数组 `words` 的长度，而 $\Sigma$ 是字符集，这里字符集为所有小写字母，因此 $|\Sigma| = 26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def shortestCompletingWord(self, licensePlate: str, words: List[str]) -> str:
        cnt = Counter(c.lower() for c in licensePlate if c.isalpha())
        ans = None
        for w in words:
            if ans and len(w) >= len(ans):
                continue
            t = Counter(w)
            if all(v <= t[c] for c, v in cnt.items()):
                ans = w
        return ans
```

#### Java

```java
class Solution {
    public String shortestCompletingWord(String licensePlate, String[] words) {
        int[] cnt = new int[26];
        for (int i = 0; i < licensePlate.length(); ++i) {
            char c = licensePlate.charAt(i);
            if (Character.isLetter(c)) {
                cnt[Character.toLowerCase(c) - 'a']++;
            }
        }
        String ans = "";
        for (String w : words) {
            if (!ans.isEmpty() && w.length() >= ans.length()) {
                continue;
            }
            int[] t = new int[26];
            for (int i = 0; i < w.length(); ++i) {
                t[w.charAt(i) - 'a']++;
            }
            boolean ok = true;
            for (int i = 0; i < 26; ++i) {
                if (t[i] < cnt[i]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ans = w;
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
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        int cnt[26]{};
        for (char& c : licensePlate) {
            if (isalpha(c)) {
                ++cnt[tolower(c) - 'a'];
            }
        }
        string ans;
        for (auto& w : words) {
            if (ans.size() && ans.size() <= w.size()) {
                continue;
            }
            int t[26]{};
            for (char& c : w) {
                ++t[c - 'a'];
            }
            bool ok = true;
            for (int i = 0; i < 26; ++i) {
                if (cnt[i] > t[i]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ans = w;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func shortestCompletingWord(licensePlate string, words []string) (ans string) {
	cnt := [26]int{}
	for _, c := range licensePlate {
		if unicode.IsLetter(c) {
			cnt[unicode.ToLower(c)-'a']++
		}
	}
	for _, w := range words {
		if len(ans) > 0 && len(ans) <= len(w) {
			continue
		}
		t := [26]int{}
		for _, c := range w {
			t[c-'a']++
		}
		ok := true
		for i, v := range cnt {
			if t[i] < v {
				ok = false
				break
			}
		}
		if ok {
			ans = w
		}
	}
	return
}
```

#### TypeScript

```ts
function shortestCompletingWord(licensePlate: string, words: string[]): string {
    const cnt: number[] = Array(26).fill(0);
    for (const c of licensePlate) {
        const i = c.toLowerCase().charCodeAt(0) - 97;
        if (0 <= i && i < 26) {
            ++cnt[i];
        }
    }
    let ans = '';
    for (const w of words) {
        if (ans.length && ans.length <= w.length) {
            continue;
        }
        const t = Array(26).fill(0);
        for (const c of w) {
            ++t[c.charCodeAt(0) - 97];
        }
        let ok = true;
        for (let i = 0; i < 26; ++i) {
            if (t[i] < cnt[i]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            ans = w;
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn shortest_completing_word(license_plate: String, words: Vec<String>) -> String {
        let mut cnt = vec![0; 26];
        for c in license_plate.chars() {
            if c.is_ascii_alphabetic() {
                cnt[((c.to_ascii_lowercase() as u8) - b'a') as usize] += 1;
            }
        }
        let mut ans = String::new();
        for w in words {
            if !ans.is_empty() && w.len() >= ans.len() {
                continue;
            }
            let mut t = vec![0; 26];
            for c in w.chars() {
                t[((c as u8) - b'a') as usize] += 1;
            }
            let mut ok = true;
            for i in 0..26 {
                if t[i] < cnt[i] {
                    ok = false;
                    break;
                }
            }
            if ok {
                ans = w;
            }
        }
        ans
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [749. 隔离病毒](https://leetcode.cn/problems/contain-virus){#749}

{{< tabs "749" >}}

{{% tab "python" %}}
```python
class Solution:
    def containVirus(self, isInfected: List[List[int]]) -> int:
        def dfs(i, j):
            vis[i][j] = True
            areas[-1].append((i, j))
            for a, b in [[0, -1], [0, 1], [-1, 0], [1, 0]]:
                x, y = i + a, j + b
                if 0 <= x < m and 0 <= y < n:
                    if isInfected[x][y] == 1 and not vis[x][y]:
                        dfs(x, y)
                    elif isInfected[x][y] == 0:
                        c[-1] += 1
                        boundaries[-1].add((x, y))

        m, n = len(isInfected), len(isInfected[0])
        ans = 0
        while 1:
            vis = [[False] * n for _ in range(m)]
            areas = []
            c = []
            boundaries = []
            for i, row in enumerate(isInfected):
                for j, v in enumerate(row):
                    if v == 1 and not vis[i][j]:
                        areas.append([])
                        boundaries.append(set())
                        c.append(0)
                        dfs(i, j)
            if not areas:
                break
            idx = boundaries.index(max(boundaries, key=len))
            ans += c[idx]
            for k, area in enumerate(areas):
                if k == idx:
                    for i, j in area:
                        isInfected[i][j] = -1
                else:
                    for i, j in area:
                        for a, b in [[0, -1], [0, 1], [-1, 0], [1, 0]]:
                            x, y = i + a, j + b
                            if 0 <= x < m and 0 <= y < n and isInfected[x][y] == 0:
                                isInfected[x][y] = 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private static final int[] DIRS = {-1, 0, 1, 0, -1};
    private List<Integer> c = new ArrayList<>();
    private List<List<Integer>> areas = new ArrayList<>();
    private List<Set<Integer>> boundaries = new ArrayList<>();
    private int[][] infected;
    private boolean[][] vis;
    private int m;
    private int n;

    public int containVirus(int[][] isInfected) {
        infected = isInfected;
        m = infected.length;
        n = infected[0].length;
        vis = new boolean[m][n];
        int ans = 0;
        while (true) {
            for (boolean[] row : vis) {
                Arrays.fill(row, false);
            }
            c.clear();
            areas.clear();
            boundaries.clear();
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (infected[i][j] == 1 && !vis[i][j]) {
                        c.add(0);
                        areas.add(new ArrayList<>());
                        boundaries.add(new HashSet<>());
                        dfs(i, j);
                    }
                }
            }
            if (areas.isEmpty()) {
                break;
            }
            int idx = max(boundaries);
            ans += c.get(idx);
            for (int t = 0; t < areas.size(); ++t) {
                if (t == idx) {
                    for (int v : areas.get(t)) {
                        int i = v / n, j = v % n;
                        infected[i][j] = -1;
                    }
                } else {
                    for (int v : areas.get(t)) {
                        int i = v / n, j = v % n;
                        for (int k = 0; k < 4; ++k) {
                            int x = i + DIRS[k], y = j + DIRS[k + 1];
                            if (x >= 0 && x < m && y >= 0 && y < n && infected[x][y] == 0) {
                                infected[x][y] = 1;
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }

    private int max(List<Set<Integer>> boundaries) {
        int idx = 0;
        int mx = boundaries.get(0).size();
        for (int i = 1; i < boundaries.size(); ++i) {
            int t = boundaries.get(i).size();
            if (mx < t) {
                mx = t;
                idx = i;
            }
        }
        return idx;
    }

    private void dfs(int i, int j) {
        vis[i][j] = true;
        int idx = areas.size() - 1;
        areas.get(idx).add(i * n + j);
        for (int k = 0; k < 4; ++k) {
            int x = i + DIRS[k], y = j + DIRS[k + 1];
            if (x >= 0 && x < m && y >= 0 && y < n) {
                if (infected[x][y] == 1 && !vis[x][y]) {
                    dfs(x, y);
                } else if (infected[x][y] == 0) {
                    c.set(idx, c.get(idx) + 1);
                    boundaries.get(idx).add(x * n + y);
                }
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
    const vector<int> dirs = {-1, 0, 1, 0, -1};
    vector<int> c;
    vector<vector<int>> areas;
    vector<unordered_set<int>> boundaries;
    vector<vector<int>> infected;
    vector<vector<bool>> vis;
    int m;
    int n;

    int containVirus(vector<vector<int>>& isInfected) {
        infected = isInfected;
        m = infected.size();
        n = infected[0].size();
        vis.assign(m, vector<bool>(n));
        int ans = 0;
        while (1) {
            for (int i = 0; i < m; ++i)
                for (int j = 0; j < n; ++j) vis[i][j] = false;
            c.clear();
            areas.clear();
            boundaries.clear();
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (infected[i][j] == 1 && !vis[i][j]) {
                        c.push_back(0);
                        areas.push_back({});
                        boundaries.push_back({});
                        dfs(i, j);
                    }
                }
            }
            if (areas.empty()) break;
            int idx = getMax();
            ans += c[idx];
            for (int t = 0; t < areas.size(); ++t) {
                if (t == idx) {
                    for (int v : areas[t]) {
                        int i = v / n, j = v % n;
                        infected[i][j] = -1;
                    }
                } else {
                    for (int v : areas[t]) {
                        int i = v / n, j = v % n;
                        for (int k = 0; k < 4; ++k) {
                            int x = i + dirs[k], y = j + dirs[k + 1];
                            if (x >= 0 && x < m && y >= 0 && y < n && infected[x][y] == 0) infected[x][y] = 1;
                        }
                    }
                }
            }
        }
        return ans;
    }

    int getMax() {
        int idx = 0;
        int mx = boundaries[0].size();
        for (int i = 1; i < boundaries.size(); ++i) {
            int t = boundaries[i].size();
            if (mx < t) {
                mx = t;
                idx = i;
            }
        }
        return idx;
    }

    void dfs(int i, int j) {
        vis[i][j] = true;
        areas.back().push_back(i * n + j);
        for (int k = 0; k < 4; ++k) {
            int x = i + dirs[k], y = j + dirs[k + 1];
            if (x >= 0 && x < m && y >= 0 && y < n) {
                if (infected[x][y] == 1 && !vis[x][y])
                    dfs(x, y);
                else if (infected[x][y] == 0) {
                    c.back() += 1;
                    boundaries.back().insert(x * n + y);
                }
            }
        }
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func containVirus(isInfected [][]int) int {
	m, n := len(isInfected), len(isInfected[0])
	ans := 0
	dirs := []int{-1, 0, 1, 0, -1}
	max := func(boundaries []map[int]bool) int {
		idx := 0
		mx := len(boundaries[0])
		for i, v := range boundaries {
			t := len(v)
			if mx < t {
				mx = t
				idx = i
			}
		}
		return idx
	}

	for {
		vis := make([][]bool, m)
		for i := range vis {
			vis[i] = make([]bool, n)
		}
		areas := []map[int]bool{}
		boundaries := []map[int]bool{}
		c := []int{}

		var dfs func(i, j int)
		dfs = func(i, j int) {
			vis[i][j] = true
			idx := len(areas) - 1
			areas[idx][i*n+j] = true
			for k := 0; k < 4; k++ {
				x, y := i+dirs[k], j+dirs[k+1]
				if x >= 0 && x < m && y >= 0 && y < n {
					if isInfected[x][y] == 1 && !vis[x][y] {
						dfs(x, y)
					} else if isInfected[x][y] == 0 {
						c[idx]++
						boundaries[idx][x*n+y] = true
					}
				}
			}
		}

		for i, row := range isInfected {
			for j, v := range row {
				if v == 1 && !vis[i][j] {
					areas = append(areas, map[int]bool{})
					boundaries = append(boundaries, map[int]bool{})
					c = append(c, 0)
					dfs(i, j)
				}
			}
		}
		if len(areas) == 0 {
			break
		}
		idx := max(boundaries)
		ans += c[idx]
		for t, area := range areas {
			if t == idx {
				for v := range area {
					i, j := v/n, v%n
					isInfected[i][j] = -1
				}
			} else {
				for v := range area {
					i, j := v/n, v%n
					for k := 0; k < 4; k++ {
						x, y := i+dirs[k], j+dirs[k+1]
						if x >= 0 && x < m && y >= 0 && y < n && isInfected[x][y] == 0 {
							isInfected[x][y] = 1
						}
					}
				}
			}
		}

	}
	return ans
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>病毒扩散得很快，现在你的任务是尽可能地通过安装防火墙来隔离病毒。</p>

<p>假设世界由&nbsp;<code>m x n</code>&nbsp;的二维矩阵&nbsp;<code>isInfected</code>&nbsp;组成，&nbsp;<code>isInfected[i][j] == 0</code>&nbsp;表示该区域未感染病毒，而 &nbsp;<code>isInfected[i][j] == 1</code>&nbsp;表示该区域已感染病毒。可以在任意 2 个相邻单元之间的共享边界上安装一个防火墙（并且只有一个防火墙）。</p>

<p>每天晚上，病毒会从被感染区域向相邻未感染区域扩散，除非被防火墙隔离。现由于资源有限，每天你只能安装一系列防火墙来隔离其中一个被病毒感染的区域（一个区域或连续的一片区域），且该感染区域对未感染区域的威胁最大且 <strong>保证唯一&nbsp;</strong>。</p>

<p>你需要努力使得最后有部分区域不被病毒感染，如果可以成功，那么返回需要使用的防火墙个数; 如果无法实现，则返回在世界被病毒全部感染时已安装的防火墙个数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0700-0799/0749.Contain%20Virus/images/virus11-grid.jpg" style="height: 255px; width: 500px;" /></p>

<pre>
<strong>输入:</strong> isInfected = [[0,1,0,0,0,0,0,1],[0,1,0,0,0,0,0,1],[0,0,0,0,0,0,0,1],[0,0,0,0,0,0,0,0]]
<strong>输出:</strong> 10
<strong>解释:</strong>一共有两块被病毒感染的区域。
在第一天，添加 5 墙隔离病毒区域的左侧。病毒传播后的状态是:
<img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0700-0799/0749.Contain%20Virus/images/virus12edited-grid.jpg" style="height: 261px; width: 500px;" />
第二天，在右侧添加 5 个墙来隔离病毒区域。此时病毒已经被完全控制住了。
<img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0700-0799/0749.Contain%20Virus/images/virus13edited-grid.jpg" style="height: 261px; width: 500px;" />
</pre>

<p><strong>示例 2：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0700-0799/0749.Contain%20Virus/images/virus2-grid.jpg" style="height: 253px; width: 653px;" /></p>

<pre>
<strong>输入:</strong> isInfected = [[1,1,1],[1,0,1],[1,1,1]]
<strong>输出:</strong> 4
<strong>解释:</strong> 虽然只保存了一个小区域，但却有四面墙。
注意，防火墙只建立在两个不同区域的共享边界上。
</pre>

<p><strong>示例&nbsp;3:</strong></p>

<pre>
<strong>输入:</strong> isInfected = [[1,1,1,0,0,0,0,0,0],[1,0,1,0,1,1,1,1,1],[1,1,1,0,0,0,0,0,0]]
<strong>输出:</strong> 13
<strong>解释:</strong> 在隔离右边感染区域后，隔离左边病毒区域只需要 2 个防火墙。
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>m ==&nbsp;isInfected.length</code></li>
	<li><code>n ==&nbsp;isInfected[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 50</code></li>
	<li><code>isInfected[i][j]</code>&nbsp;is either&nbsp;<code>0</code>&nbsp;or&nbsp;<code>1</code></li>
	<li>在整个描述的过程中，总有一个相邻的病毒区域，它将在下一轮 <strong>严格地感染更多未受污染的方块</strong>&nbsp;</li>
</ul>

<p>&nbsp;</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS 暴力模拟

DFS 找到每个病毒区域 `areas[i]`，同时记录每个区域边界节点 `boundaries[i]` 以及周长 `c[i]`。

接着对威胁最大的病毒区域进行隔离，累加所需的防火墙数量。

剩余的病毒区域向外感染一个区域。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def containVirus(self, isInfected: List[List[int]]) -> int:
        def dfs(i, j):
            vis[i][j] = True
            areas[-1].append((i, j))
            for a, b in [[0, -1], [0, 1], [-1, 0], [1, 0]]:
                x, y = i + a, j + b
                if 0 <= x < m and 0 <= y < n:
                    if isInfected[x][y] == 1 and not vis[x][y]:
                        dfs(x, y)
                    elif isInfected[x][y] == 0:
                        c[-1] += 1
                        boundaries[-1].add((x, y))

        m, n = len(isInfected), len(isInfected[0])
        ans = 0
        while 1:
            vis = [[False] * n for _ in range(m)]
            areas = []
            c = []
            boundaries = []
            for i, row in enumerate(isInfected):
                for j, v in enumerate(row):
                    if v == 1 and not vis[i][j]:
                        areas.append([])
                        boundaries.append(set())
                        c.append(0)
                        dfs(i, j)
            if not areas:
                break
            idx = boundaries.index(max(boundaries, key=len))
            ans += c[idx]
            for k, area in enumerate(areas):
                if k == idx:
                    for i, j in area:
                        isInfected[i][j] = -1
                else:
                    for i, j in area:
                        for a, b in [[0, -1], [0, 1], [-1, 0], [1, 0]]:
                            x, y = i + a, j + b
                            if 0 <= x < m and 0 <= y < n and isInfected[x][y] == 0:
                                isInfected[x][y] = 1
        return ans
```

#### Java

```java
class Solution {
    private static final int[] DIRS = {-1, 0, 1, 0, -1};
    private List<Integer> c = new ArrayList<>();
    private List<List<Integer>> areas = new ArrayList<>();
    private List<Set<Integer>> boundaries = new ArrayList<>();
    private int[][] infected;
    private boolean[][] vis;
    private int m;
    private int n;

    public int containVirus(int[][] isInfected) {
        infected = isInfected;
        m = infected.length;
        n = infected[0].length;
        vis = new boolean[m][n];
        int ans = 0;
        while (true) {
            for (boolean[] row : vis) {
                Arrays.fill(row, false);
            }
            c.clear();
            areas.clear();
            boundaries.clear();
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (infected[i][j] == 1 && !vis[i][j]) {
                        c.add(0);
                        areas.add(new ArrayList<>());
                        boundaries.add(new HashSet<>());
                        dfs(i, j);
                    }
                }
            }
            if (areas.isEmpty()) {
                break;
            }
            int idx = max(boundaries);
            ans += c.get(idx);
            for (int t = 0; t < areas.size(); ++t) {
                if (t == idx) {
                    for (int v : areas.get(t)) {
                        int i = v / n, j = v % n;
                        infected[i][j] = -1;
                    }
                } else {
                    for (int v : areas.get(t)) {
                        int i = v / n, j = v % n;
                        for (int k = 0; k < 4; ++k) {
                            int x = i + DIRS[k], y = j + DIRS[k + 1];
                            if (x >= 0 && x < m && y >= 0 && y < n && infected[x][y] == 0) {
                                infected[x][y] = 1;
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }

    private int max(List<Set<Integer>> boundaries) {
        int idx = 0;
        int mx = boundaries.get(0).size();
        for (int i = 1; i < boundaries.size(); ++i) {
            int t = boundaries.get(i).size();
            if (mx < t) {
                mx = t;
                idx = i;
            }
        }
        return idx;
    }

    private void dfs(int i, int j) {
        vis[i][j] = true;
        int idx = areas.size() - 1;
        areas.get(idx).add(i * n + j);
        for (int k = 0; k < 4; ++k) {
            int x = i + DIRS[k], y = j + DIRS[k + 1];
            if (x >= 0 && x < m && y >= 0 && y < n) {
                if (infected[x][y] == 1 && !vis[x][y]) {
                    dfs(x, y);
                } else if (infected[x][y] == 0) {
                    c.set(idx, c.get(idx) + 1);
                    boundaries.get(idx).add(x * n + y);
                }
            }
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    const vector<int> dirs = {-1, 0, 1, 0, -1};
    vector<int> c;
    vector<vector<int>> areas;
    vector<unordered_set<int>> boundaries;
    vector<vector<int>> infected;
    vector<vector<bool>> vis;
    int m;
    int n;

    int containVirus(vector<vector<int>>& isInfected) {
        infected = isInfected;
        m = infected.size();
        n = infected[0].size();
        vis.assign(m, vector<bool>(n));
        int ans = 0;
        while (1) {
            for (int i = 0; i < m; ++i)
                for (int j = 0; j < n; ++j) vis[i][j] = false;
            c.clear();
            areas.clear();
            boundaries.clear();
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (infected[i][j] == 1 && !vis[i][j]) {
                        c.push_back(0);
                        areas.push_back({});
                        boundaries.push_back({});
                        dfs(i, j);
                    }
                }
            }
            if (areas.empty()) break;
            int idx = getMax();
            ans += c[idx];
            for (int t = 0; t < areas.size(); ++t) {
                if (t == idx) {
                    for (int v : areas[t]) {
                        int i = v / n, j = v % n;
                        infected[i][j] = -1;
                    }
                } else {
                    for (int v : areas[t]) {
                        int i = v / n, j = v % n;
                        for (int k = 0; k < 4; ++k) {
                            int x = i + dirs[k], y = j + dirs[k + 1];
                            if (x >= 0 && x < m && y >= 0 && y < n && infected[x][y] == 0) infected[x][y] = 1;
                        }
                    }
                }
            }
        }
        return ans;
    }

    int getMax() {
        int idx = 0;
        int mx = boundaries[0].size();
        for (int i = 1; i < boundaries.size(); ++i) {
            int t = boundaries[i].size();
            if (mx < t) {
                mx = t;
                idx = i;
            }
        }
        return idx;
    }

    void dfs(int i, int j) {
        vis[i][j] = true;
        areas.back().push_back(i * n + j);
        for (int k = 0; k < 4; ++k) {
            int x = i + dirs[k], y = j + dirs[k + 1];
            if (x >= 0 && x < m && y >= 0 && y < n) {
                if (infected[x][y] == 1 && !vis[x][y])
                    dfs(x, y);
                else if (infected[x][y] == 0) {
                    c.back() += 1;
                    boundaries.back().insert(x * n + y);
                }
            }
        }
    }
};
```

#### Go

```go
func containVirus(isInfected [][]int) int {
	m, n := len(isInfected), len(isInfected[0])
	ans := 0
	dirs := []int{-1, 0, 1, 0, -1}
	max := func(boundaries []map[int]bool) int {
		idx := 0
		mx := len(boundaries[0])
		for i, v := range boundaries {
			t := len(v)
			if mx < t {
				mx = t
				idx = i
			}
		}
		return idx
	}

	for {
		vis := make([][]bool, m)
		for i := range vis {
			vis[i] = make([]bool, n)
		}
		areas := []map[int]bool{}
		boundaries := []map[int]bool{}
		c := []int{}

		var dfs func(i, j int)
		dfs = func(i, j int) {
			vis[i][j] = true
			idx := len(areas) - 1
			areas[idx][i*n+j] = true
			for k := 0; k < 4; k++ {
				x, y := i+dirs[k], j+dirs[k+1]
				if x >= 0 && x < m && y >= 0 && y < n {
					if isInfected[x][y] == 1 && !vis[x][y] {
						dfs(x, y)
					} else if isInfected[x][y] == 0 {
						c[idx]++
						boundaries[idx][x*n+y] = true
					}
				}
			}
		}

		for i, row := range isInfected {
			for j, v := range row {
				if v == 1 && !vis[i][j] {
					areas = append(areas, map[int]bool{})
					boundaries = append(boundaries, map[int]bool{})
					c = append(c, 0)
					dfs(i, j)
				}
			}
		}
		if len(areas) == 0 {
			break
		}
		idx := max(boundaries)
		ans += c[idx]
		for t, area := range areas {
			if t == idx {
				for v := range area {
					i, j := v/n, v%n
					isInfected[i][j] = -1
				}
			} else {
				for v := range area {
					i, j := v/n, v%n
					for k := 0; k < 4; k++ {
						x, y := i+dirs[k], j+dirs[k+1]
						if x >= 0 && x < m && y >= 0 && y < n && isInfected[x][y] == 0 {
							isInfected[x][y] = 1
						}
					}
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
