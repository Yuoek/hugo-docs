---
title: "1210_穿过迷宫的最少移动次数"
date: 2025-10-08T18:37:06+08:00
weight: 2
tags: [二分查找, 二叉搜索树, 二叉树, 动态规划, 双指针, 哈希表, 回溯, 字符串, 广度优先搜索, 数学, 数据库, 数组, 栈, 树, 深度优先搜索, 矩阵, 计数, 贪心]
---

{{< markmap >}}
### [1210_穿过迷宫的最少移动次数](#1210)
#### [广度优先搜索](#1210)
#### [数组](#1210)
#### [矩阵](#1210)
### [1211_查询结果的质量和占比](#1211)
#### [数据库](#1211)
### [1212_查询球队积分 🔒](#1212)
#### [数据库](#1212)
### [1213_三个有序数组的交集 🔒](#1213)
#### [数组](#1213)
#### [哈希表](#1213)
#### [二分查找](#1213)
#### [计数](#1213)
### [1214_查找两棵二叉搜索树之和 🔒](#1214)
#### [栈](#1214)
#### [树](#1214)
#### [深度优先搜索](#1214)
#### [二叉搜索树](#1214)
#### [双指针](#1214)
#### [二分查找](#1214)
#### [二叉树](#1214)
### [1215_步进数 🔒](#1215)
#### [广度优先搜索](#1215)
#### [数学](#1215)
#### [回溯](#1215)
### [1216_验证回文串 III 🔒](#1216)
#### [字符串](#1216)
#### [动态规划](#1216)
### [1217_玩筹码](#1217)
#### [贪心](#1217)
#### [数组](#1217)
#### [数学](#1217)
### [1218_最长定差子序列](#1218)
#### [数组](#1218)
#### [哈希表](#1218)
#### [动态规划](#1218)
### [1219_黄金矿工](#1219)
#### [数组](#1219)
#### [回溯](#1219)
#### [矩阵](#1219)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1210_穿过迷宫的最少移动次数
___
#### 广度优先搜索
___
#### 数组
___
#### 矩阵
---
### 1211_查询结果的质量和占比
___
#### 数据库
---
### 1212_查询球队积分 🔒
___
#### 数据库
---
### 1213_三个有序数组的交集 🔒
___
#### 数组
___
#### 哈希表
___
#### 二分查找
___
#### 计数
---
### 1214_查找两棵二叉搜索树之和 🔒
___
#### 栈
___
#### 树
___
#### 深度优先搜索
___
#### 二叉搜索树
___
#### 双指针
___
#### 二分查找
___
#### 二叉树
---
### 1215_步进数 🔒
___
#### 广度优先搜索
___
#### 数学
___
#### 回溯
---
### 1216_验证回文串 III 🔒
___
#### 字符串
___
#### 动态规划
---
### 1217_玩筹码
___
#### 贪心
___
#### 数组
___
#### 数学
---
### 1218_最长定差子序列
___
#### 数组
___
#### 哈希表
___
#### 动态规划
---
### 1219_黄金矿工
___
#### 数组
___
#### 回溯
___
#### 矩阵
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 二叉搜索树 | 二叉树 |
| 动态规划 | 双指针 | 哈希表 |
| 回溯 | 字符串 | 广度优先搜索 |
| 数学 | 数据库 | 数组 |
| 栈 | 树 | 深度优先搜索 |
| 矩阵 | 计数 | 贪心 |

# [1210. 穿过迷宫的最少移动次数](https://leetcode.cn/problems/minimum-moves-to-reach-target-with-rotations){#1210}

{{< tabs "1210" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumMoves(self, grid: List[List[int]]) -> int:
        def move(i1, j1, i2, j2):
            if 0 <= i1 < n and 0 <= j1 < n and 0 <= i2 < n and 0 <= j2 < n:
                a, b = i1 * n + j1, i2 * n + j2
                status = 0 if i1 == i2 else 1
                if (a, status) not in vis and grid[i1][j1] == 0 and grid[i2][j2] == 0:
                    q.append((a, b))
                    vis.add((a, status))

        n = len(grid)
        target = (n * n - 2, n * n - 1)
        q = deque([(0, 1)])
        vis = {(0, 0)}
        ans = 0
        while q:
            for _ in range(len(q)):
                a, b = q.popleft()
                if (a, b) == target:
                    return ans
                i1, j1 = a // n, a % n
                i2, j2 = b // n, b % n
                # 尝试向右平移（保持身体水平/垂直状态）
                move(i1, j1 + 1, i2, j2 + 1)
                # 尝试向下平移（保持身体水平/垂直状态）
                move(i1 + 1, j1, i2 + 1, j2)
                # 当前处于水平状态，且 grid[i1 + 1][j2] 无障碍，尝试顺时针旋转90°
                if i1 == i2 and i1 + 1 < n and grid[i1 + 1][j2] == 0:
                    move(i1, j1, i1 + 1, j1)
                # 当前处于垂直状态，且 grid[i2][j1 + 1] 无障碍，尝试逆时针旋转90°
                if j1 == j2 and j1 + 1 < n and grid[i2][j1 + 1] == 0:
                    move(i1, j1, i1, j1 + 1)
            ans += 1
        return -1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int n;
    private int[][] grid;
    private boolean[][] vis;
    private Deque<int[]> q = new ArrayDeque<>();

    public int minimumMoves(int[][] grid) {
        this.grid = grid;
        n = grid.length;
        vis = new boolean[n * n][2];
        int[] target = {n * n - 2, n * n - 1};
        q.offer(new int[] {0, 1});
        vis[0][0] = true;
        int ans = 0;
        while (!q.isEmpty()) {
            for (int k = q.size(); k > 0; --k) {
                var p = q.poll();
                if (p[0] == target[0] && p[1] == target[1]) {
                    return ans;
                }
                int i1 = p[0] / n, j1 = p[0] % n;
                int i2 = p[1] / n, j2 = p[1] % n;
                // 尝试向右平移（保持身体水平/垂直状态）
                move(i1, j1 + 1, i2, j2 + 1);
                // 尝试向下平移（保持身体水平/垂直状态）
                move(i1 + 1, j1, i2 + 1, j2);
                // 当前处于水平状态，且 grid[i1 + 1][j2] 无障碍，尝试顺时针旋转90°
                if (i1 == i2 && i1 + 1 < n && grid[i1 + 1][j2] == 0) {
                    move(i1, j1, i1 + 1, j1);
                }
                // 当前处于垂直状态，且 grid[i2][j1 + 1] 无障碍，尝试逆时针旋转90°
                if (j1 == j2 && j1 + 1 < n && grid[i2][j1 + 1] == 0) {
                    move(i1, j1, i1, j1 + 1);
                }
            }
            ++ans;
        }
        return -1;
    }

    private void move(int i1, int j1, int i2, int j2) {
        if (i1 >= 0 && i1 < n && j1 >= 0 && j1 < n && i2 >= 0 && i2 < n && j2 >= 0 && j2 < n) {
            int a = i1 * n + j1, b = i2 * n + j2;
            int status = i1 == i2 ? 0 : 1;
            if (!vis[a][status] && grid[i1][j1] == 0 && grid[i2][j2] == 0) {
                q.offer(new int[] {a, b});
                vis[a][status] = true;
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
    int minimumMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        auto target = make_pair(n * n - 2, n * n - 1);
        queue<pair<int, int>> q;
        q.emplace(0, 1);
        bool vis[n * n][2];
        memset(vis, 0, sizeof vis);
        vis[0][0] = true;

        auto move = [&](int i1, int j1, int i2, int j2) {
            if (i1 >= 0 && i1 < n && j1 >= 0 && j1 < n && i2 >= 0 && i2 < n && j2 >= 0 && j2 < n) {
                int a = i1 * n + j1, b = i2 * n + j2;
                int status = i1 == i2 ? 0 : 1;
                if (!vis[a][status] && grid[i1][j1] == 0 && grid[i2][j2] == 0) {
                    q.emplace(a, b);
                    vis[a][status] = true;
                }
            }
        };

        int ans = 0;
        while (!q.empty()) {
            for (int k = q.size(); k; --k) {
                auto p = q.front();
                q.pop();
                if (p == target) {
                    return ans;
                }
                auto [a, b] = p;
                int i1 = a / n, j1 = a % n;
                int i2 = b / n, j2 = b % n;
                // 尝试向右平移（保持身体水平/垂直状态）
                move(i1, j1 + 1, i2, j2 + 1);
                // 尝试向下平移（保持身体水平/垂直状态）
                move(i1 + 1, j1, i2 + 1, j2);
                // 当前处于水平状态，且 grid[i1 + 1][j2] 无障碍，尝试顺时针旋转90°
                if (i1 == i2 && i1 + 1 < n && grid[i1 + 1][j2] == 0) {
                    move(i1, j1, i1 + 1, j1);
                }
                // 当前处于垂直状态，且 grid[i2][j1 + 1] 无障碍，尝试逆时针旋转90°
                if (j1 == j2 && j1 + 1 < n && grid[i2][j1 + 1] == 0) {
                    move(i1, j1, i1, j1 + 1);
                }
            }
            ++ans;
        }
        return -1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumMoves(grid [][]int) int {
	n := len(grid)
	type pair struct{ a, b int }
	target := pair{n*n - 2, n*n - 1}
	q := []pair{pair{0, 1}}
	vis := make([][2]bool, n*n)
	vis[0][0] = true

	move := func(i1, j1, i2, j2 int) {
		if i1 >= 0 && i1 < n && j1 >= 0 && j1 < n && i2 >= 0 && i2 < n && j2 >= 0 && j2 < n {
			a, b := i1*n+j1, i2*n+j2
			status := 1
			if i1 == i2 {
				status = 0
			}
			if !vis[a][status] && grid[i1][j1] == 0 && grid[i2][j2] == 0 {
				q = append(q, pair{a, b})
				vis[a][status] = true
			}
		}
	}

	ans := 0
	for len(q) > 0 {
		for k := len(q); k > 0; k-- {
			p := q[0]
			q = q[1:]
			if p == target {
				return ans
			}
			a, b := p.a, p.b
			i1, j1 := a/n, a%n
			i2, j2 := b/n, b%n
			// 尝试向右平移（保持身体水平/垂直状态）
			move(i1, j1+1, i2, j2+1)
			// 尝试向下平移（保持身体水平/垂直状态）
			move(i1+1, j1, i2+1, j2)
			// 当前处于水平状态，且 grid[i1 + 1][j2] 无障碍，尝试顺时针旋转90°
			if i1 == i2 && i1+1 < n && grid[i1+1][j2] == 0 {
				move(i1, j1, i1+1, j1)
			}
			// 当前处于垂直状态，且 grid[i2][j1 + 1] 无障碍，尝试逆时针旋转90°
			if j1 == j2 && j1+1 < n && grid[i2][j1+1] == 0 {
				move(i1, j1, i1, j1+1)
			}
		}
		ans++
	}
	return -1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumMoves(grid: number[][]): number {
    const n = grid.length;
    const target: number[] = [n * n - 2, n * n - 1];
    const q: number[][] = [[0, 1]];
    const vis = Array.from({ length: n * n }, () => Array(2).fill(false));
    vis[0][0] = true;

    const move = (i1: number, j1: number, i2: number, j2: number) => {
        if (i1 >= 0 && i1 < n && j1 >= 0 && j1 < n && i2 >= 0 && i2 < n && j2 >= 0 && j2 < n) {
            const a = i1 * n + j1;
            const b = i2 * n + j2;
            const status = i1 === i2 ? 0 : 1;
            if (!vis[a][status] && grid[i1][j1] == 0 && grid[i2][j2] == 0) {
                q.push([a, b]);
                vis[a][status] = true;
            }
        }
    };

    let ans = 0;
    while (q.length) {
        for (let k = q.length; k; --k) {
            const p: number[] = q.shift();
            if (p[0] === target[0] && p[1] === target[1]) {
                return ans;
            }
            const [i1, j1] = [~~(p[0] / n), p[0] % n];
            const [i2, j2] = [~~(p[1] / n), p[1] % n];
            // 尝试向右平移（保持身体水平/垂直状态）
            move(i1, j1 + 1, i2, j2 + 1);
            // 尝试向下平移（保持身体水平/垂直状态）
            move(i1 + 1, j1, i2 + 1, j2);
            // 当前处于水平状态，且 grid[i1 + 1][j2] 无障碍，尝试顺时针旋转90°
            if (i1 == i2 && i1 + 1 < n && grid[i1 + 1][j2] == 0) {
                move(i1, j1, i1 + 1, j1);
            }
            // 当前处于垂直状态，且 grid[i2][j1 + 1] 无障碍，尝试逆时针旋转90°
            if (j1 == j2 && j1 + 1 < n && grid[i2][j1 + 1] == 0) {
                move(i1, j1, i1, j1 + 1);
            }
        }
        ++ans;
    }
    return -1;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[][]} grid
 * @return {number}
 */
var minimumMoves = function (grid) {
    const n = grid.length;
    const target = [n * n - 2, n * n - 1];
    const q = [[0, 1]];
    const vis = Array.from({ length: n * n }, () => Array(2).fill(false));
    vis[0][0] = true;

    const move = (i1, j1, i2, j2) => {
        if (i1 >= 0 && i1 < n && j1 >= 0 && j1 < n && i2 >= 0 && i2 < n && j2 >= 0 && j2 < n) {
            const a = i1 * n + j1;
            const b = i2 * n + j2;
            const status = i1 === i2 ? 0 : 1;
            if (!vis[a][status] && grid[i1][j1] == 0 && grid[i2][j2] == 0) {
                q.push([a, b]);
                vis[a][status] = true;
            }
        }
    };

    let ans = 0;
    while (q.length) {
        for (let k = q.length; k; --k) {
            const p = q.shift();
            if (p[0] === target[0] && p[1] === target[1]) {
                return ans;
            }
            const [i1, j1] = [~~(p[0] / n), p[0] % n];
            const [i2, j2] = [~~(p[1] / n), p[1] % n];
            // 尝试向右平移（保持身体水平/垂直状态）
            move(i1, j1 + 1, i2, j2 + 1);
            // 尝试向下平移（保持身体水平/垂直状态）
            move(i1 + 1, j1, i2 + 1, j2);
            // 当前处于水平状态，且 grid[i1 + 1][j2] 无障碍，尝试顺时针旋转90°
            if (i1 == i2 && i1 + 1 < n && grid[i1 + 1][j2] == 0) {
                move(i1, j1, i1 + 1, j1);
            }
            // 当前处于垂直状态，且 grid[i2][j1 + 1] 无障碍，尝试逆时针旋转90°
            if (j1 == j2 && j1 + 1 < n && grid[i2][j1 + 1] == 0) {
                move(i1, j1, i1, j1 + 1);
            }
        }
        ++ans;
    }
    return -1;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你还记得那条风靡全球的贪吃蛇吗？</p>

<p>我们在一个&nbsp;<code>n*n</code>&nbsp;的网格上构建了新的迷宫地图，蛇的长度为 2，也就是说它会占去两个单元格。蛇会从左上角（<code>(0, 0)</code>&nbsp;和&nbsp;<code>(0, 1)</code>）开始移动。我们用 <code>0</code> 表示空单元格，用 1 表示障碍物。蛇需要移动到迷宫的右下角（<code>(n-1, n-2)</code>&nbsp;和&nbsp;<code>(n-1, n-1)</code>）。</p>

<p>每次移动，蛇可以这样走：</p>

<ul>
	<li>如果没有障碍，则向右移动一个单元格。并仍然保持身体的水平／竖直状态。</li>
	<li>如果没有障碍，则向下移动一个单元格。并仍然保持身体的水平／竖直状态。</li>
	<li>如果它处于水平状态并且其下面的两个单元都是空的，就顺时针旋转 90 度。蛇从（<code>(r, c)</code>、<code>(r, c+1)</code>）移动到 （<code>(r, c)</code>、<code>(r+1, c)</code>）。<br>
	<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1200-1299/1210.Minimum%20Moves%20to%20Reach%20Target%20with%20Rotations/images/image-2.png" style="height: 134px; width: 300px;"></li>
	<li>如果它处于竖直状态并且其右面的两个单元都是空的，就逆时针旋转 90 度。蛇从（<code>(r, c)</code>、<code>(r+1, c)</code>）移动到（<code>(r, c)</code>、<code>(r, c+1)</code>）。<br>
	<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1200-1299/1210.Minimum%20Moves%20to%20Reach%20Target%20with%20Rotations/images/image-1.png" style="height: 121px; width: 300px;"></li>
</ul>

<p>返回蛇抵达目的地所需的最少移动次数。</p>

<p>如果无法到达目的地，请返回&nbsp;<code>-1</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1200-1299/1210.Minimum%20Moves%20to%20Reach%20Target%20with%20Rotations/images/image.png" style="height: 439px; width: 400px;"></strong></p>

<pre><strong>输入：</strong>grid = [[0,0,0,0,0,1],
               [1,1,0,0,1,0],
&nbsp;              [0,0,0,0,1,1],
&nbsp;              [0,0,1,0,1,0],
&nbsp;              [0,1,1,0,0,0],
&nbsp;              [0,1,1,0,0,0]]
<strong>输出：</strong>11
<strong>解释：
</strong>一种可能的解决方案是 [右, 右, 顺时针旋转, 右, 下, 下, 下, 下, 逆时针旋转, 右, 下]。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>grid = [[0,0,1,1,1,1],
&nbsp;              [0,0,0,0,1,1],
&nbsp;              [1,1,0,0,0,1],
&nbsp;              [1,1,1,0,0,1],
&nbsp;              [1,1,1,0,0,1],
&nbsp;              [1,1,1,0,0,0]]
<strong>输出：</strong>9
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 100</code></li>
	<li><code>0 &lt;= grid[i][j] &lt;= 1</code></li>
	<li>蛇保证从空单元格开始出发。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：BFS

题目求的是蛇从起始位置到达目标位置的最少移动次数，我们考虑使用广度优先搜索 $BFS$ 来求解。

我们定义以下数据结构或变量：

-   队列 $q$：存储蛇的当前位置，每个位置是一个二元组 $(a, b)$，其中 $a$ 表示蛇的尾部位置，而 $b$ 表示蛇的头部位置。初始时，我们将位置 $(0, 1)$ 加入队列 $q$ 中。如果我们将二维迷宫扁平化成一个一维数组，那么位置 $(0, 1)$ 就表示一维数组下标为 $0$ 和 $1$ 的两个单元格。
-   目标位置 $target$：值固定为 $(n^2 - 2, n^2 - 1)$，即二维迷宫的最后一行的最后两个单元格。
-   数组或集合 $vis$：存储蛇的当前位置状态是否已经被访问过，每个状态是一个二元组 $(a, status)$，其中 $a$ 表示蛇的尾部位置；而 $status$ 表示蛇当前所处的状态，取值为 $0$ 或 $1$，分别表示蛇的水平状态和垂直状态。初始时将起始位置 $(0, 1)$ 的状态加入集合 $vis$ 中。
-   答案变量 $ans$：存储蛇从起始位置到达目标位置的移动次数，初始时为 $0$。

我们使用广度优先搜索来求解，每次从队列 $q$ 中取出一个位置，判断该位置是否为目标位置 $target$，如果是，则直接返回答案变量 $ans$。如果不是，则将该位置的下一个可能的位置加入队列 $q$ 中，并将该位置加入 $vis$ 中。注意，这里的下一个位置可能是蛇的水平状态或垂直状态，我们需要分别判断（具体见以下代码注释）。在每一轮搜索结束后，答案变量 $ans$ 自增 $1$。

最后，如果队列 $q$ 为空，说明无法从起始位置到达目标位置，返回 $-1$。

时间复杂度 $O(n^2)$，空间复杂度 $O(n^2)$。其中 $n$ 是二维迷宫的行数或列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumMoves(self, grid: List[List[int]]) -> int:
        def move(i1, j1, i2, j2):
            if 0 <= i1 < n and 0 <= j1 < n and 0 <= i2 < n and 0 <= j2 < n:
                a, b = i1 * n + j1, i2 * n + j2
                status = 0 if i1 == i2 else 1
                if (a, status) not in vis and grid[i1][j1] == 0 and grid[i2][j2] == 0:
                    q.append((a, b))
                    vis.add((a, status))

        n = len(grid)
        target = (n * n - 2, n * n - 1)
        q = deque([(0, 1)])
        vis = {(0, 0)}
        ans = 0
        while q:
            for _ in range(len(q)):
                a, b = q.popleft()
                if (a, b) == target:
                    return ans
                i1, j1 = a // n, a % n
                i2, j2 = b // n, b % n
                # 尝试向右平移（保持身体水平/垂直状态）
                move(i1, j1 + 1, i2, j2 + 1)
                # 尝试向下平移（保持身体水平/垂直状态）
                move(i1 + 1, j1, i2 + 1, j2)
                # 当前处于水平状态，且 grid[i1 + 1][j2] 无障碍，尝试顺时针旋转90°
                if i1 == i2 and i1 + 1 < n and grid[i1 + 1][j2] == 0:
                    move(i1, j1, i1 + 1, j1)
                # 当前处于垂直状态，且 grid[i2][j1 + 1] 无障碍，尝试逆时针旋转90°
                if j1 == j2 and j1 + 1 < n and grid[i2][j1 + 1] == 0:
                    move(i1, j1, i1, j1 + 1)
            ans += 1
        return -1
```

#### Java

```java
class Solution {
    private int n;
    private int[][] grid;
    private boolean[][] vis;
    private Deque<int[]> q = new ArrayDeque<>();

    public int minimumMoves(int[][] grid) {
        this.grid = grid;
        n = grid.length;
        vis = new boolean[n * n][2];
        int[] target = {n * n - 2, n * n - 1};
        q.offer(new int[] {0, 1});
        vis[0][0] = true;
        int ans = 0;
        while (!q.isEmpty()) {
            for (int k = q.size(); k > 0; --k) {
                var p = q.poll();
                if (p[0] == target[0] && p[1] == target[1]) {
                    return ans;
                }
                int i1 = p[0] / n, j1 = p[0] % n;
                int i2 = p[1] / n, j2 = p[1] % n;
                // 尝试向右平移（保持身体水平/垂直状态）
                move(i1, j1 + 1, i2, j2 + 1);
                // 尝试向下平移（保持身体水平/垂直状态）
                move(i1 + 1, j1, i2 + 1, j2);
                // 当前处于水平状态，且 grid[i1 + 1][j2] 无障碍，尝试顺时针旋转90°
                if (i1 == i2 && i1 + 1 < n && grid[i1 + 1][j2] == 0) {
                    move(i1, j1, i1 + 1, j1);
                }
                // 当前处于垂直状态，且 grid[i2][j1 + 1] 无障碍，尝试逆时针旋转90°
                if (j1 == j2 && j1 + 1 < n && grid[i2][j1 + 1] == 0) {
                    move(i1, j1, i1, j1 + 1);
                }
            }
            ++ans;
        }
        return -1;
    }

    private void move(int i1, int j1, int i2, int j2) {
        if (i1 >= 0 && i1 < n && j1 >= 0 && j1 < n && i2 >= 0 && i2 < n && j2 >= 0 && j2 < n) {
            int a = i1 * n + j1, b = i2 * n + j2;
            int status = i1 == i2 ? 0 : 1;
            if (!vis[a][status] && grid[i1][j1] == 0 && grid[i2][j2] == 0) {
                q.offer(new int[] {a, b});
                vis[a][status] = true;
            }
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        auto target = make_pair(n * n - 2, n * n - 1);
        queue<pair<int, int>> q;
        q.emplace(0, 1);
        bool vis[n * n][2];
        memset(vis, 0, sizeof vis);
        vis[0][0] = true;

        auto move = [&](int i1, int j1, int i2, int j2) {
            if (i1 >= 0 && i1 < n && j1 >= 0 && j1 < n && i2 >= 0 && i2 < n && j2 >= 0 && j2 < n) {
                int a = i1 * n + j1, b = i2 * n + j2;
                int status = i1 == i2 ? 0 : 1;
                if (!vis[a][status] && grid[i1][j1] == 0 && grid[i2][j2] == 0) {
                    q.emplace(a, b);
                    vis[a][status] = true;
                }
            }
        };

        int ans = 0;
        while (!q.empty()) {
            for (int k = q.size(); k; --k) {
                auto p = q.front();
                q.pop();
                if (p == target) {
                    return ans;
                }
                auto [a, b] = p;
                int i1 = a / n, j1 = a % n;
                int i2 = b / n, j2 = b % n;
                // 尝试向右平移（保持身体水平/垂直状态）
                move(i1, j1 + 1, i2, j2 + 1);
                // 尝试向下平移（保持身体水平/垂直状态）
                move(i1 + 1, j1, i2 + 1, j2);
                // 当前处于水平状态，且 grid[i1 + 1][j2] 无障碍，尝试顺时针旋转90°
                if (i1 == i2 && i1 + 1 < n && grid[i1 + 1][j2] == 0) {
                    move(i1, j1, i1 + 1, j1);
                }
                // 当前处于垂直状态，且 grid[i2][j1 + 1] 无障碍，尝试逆时针旋转90°
                if (j1 == j2 && j1 + 1 < n && grid[i2][j1 + 1] == 0) {
                    move(i1, j1, i1, j1 + 1);
                }
            }
            ++ans;
        }
        return -1;
    }
};
```

#### Go

```go
func minimumMoves(grid [][]int) int {
	n := len(grid)
	type pair struct{ a, b int }
	target := pair{n*n - 2, n*n - 1}
	q := []pair{pair{0, 1}}
	vis := make([][2]bool, n*n)
	vis[0][0] = true

	move := func(i1, j1, i2, j2 int) {
		if i1 >= 0 && i1 < n && j1 >= 0 && j1 < n && i2 >= 0 && i2 < n && j2 >= 0 && j2 < n {
			a, b := i1*n+j1, i2*n+j2
			status := 1
			if i1 == i2 {
				status = 0
			}
			if !vis[a][status] && grid[i1][j1] == 0 && grid[i2][j2] == 0 {
				q = append(q, pair{a, b})
				vis[a][status] = true
			}
		}
	}

	ans := 0
	for len(q) > 0 {
		for k := len(q); k > 0; k-- {
			p := q[0]
			q = q[1:]
			if p == target {
				return ans
			}
			a, b := p.a, p.b
			i1, j1 := a/n, a%n
			i2, j2 := b/n, b%n
			// 尝试向右平移（保持身体水平/垂直状态）
			move(i1, j1+1, i2, j2+1)
			// 尝试向下平移（保持身体水平/垂直状态）
			move(i1+1, j1, i2+1, j2)
			// 当前处于水平状态，且 grid[i1 + 1][j2] 无障碍，尝试顺时针旋转90°
			if i1 == i2 && i1+1 < n && grid[i1+1][j2] == 0 {
				move(i1, j1, i1+1, j1)
			}
			// 当前处于垂直状态，且 grid[i2][j1 + 1] 无障碍，尝试逆时针旋转90°
			if j1 == j2 && j1+1 < n && grid[i2][j1+1] == 0 {
				move(i1, j1, i1, j1+1)
			}
		}
		ans++
	}
	return -1
}
```

#### TypeScript

```ts
function minimumMoves(grid: number[][]): number {
    const n = grid.length;
    const target: number[] = [n * n - 2, n * n - 1];
    const q: number[][] = [[0, 1]];
    const vis = Array.from({ length: n * n }, () => Array(2).fill(false));
    vis[0][0] = true;

    const move = (i1: number, j1: number, i2: number, j2: number) => {
        if (i1 >= 0 && i1 < n && j1 >= 0 && j1 < n && i2 >= 0 && i2 < n && j2 >= 0 && j2 < n) {
            const a = i1 * n + j1;
            const b = i2 * n + j2;
            const status = i1 === i2 ? 0 : 1;
            if (!vis[a][status] && grid[i1][j1] == 0 && grid[i2][j2] == 0) {
                q.push([a, b]);
                vis[a][status] = true;
            }
        }
    };

    let ans = 0;
    while (q.length) {
        for (let k = q.length; k; --k) {
            const p: number[] = q.shift();
            if (p[0] === target[0] && p[1] === target[1]) {
                return ans;
            }
            const [i1, j1] = [~~(p[0] / n), p[0] % n];
            const [i2, j2] = [~~(p[1] / n), p[1] % n];
            // 尝试向右平移（保持身体水平/垂直状态）
            move(i1, j1 + 1, i2, j2 + 1);
            // 尝试向下平移（保持身体水平/垂直状态）
            move(i1 + 1, j1, i2 + 1, j2);
            // 当前处于水平状态，且 grid[i1 + 1][j2] 无障碍，尝试顺时针旋转90°
            if (i1 == i2 && i1 + 1 < n && grid[i1 + 1][j2] == 0) {
                move(i1, j1, i1 + 1, j1);
            }
            // 当前处于垂直状态，且 grid[i2][j1 + 1] 无障碍，尝试逆时针旋转90°
            if (j1 == j2 && j1 + 1 < n && grid[i2][j1 + 1] == 0) {
                move(i1, j1, i1, j1 + 1);
            }
        }
        ++ans;
    }
    return -1;
}
```

#### JavaScript

```js
/**
 * @param {number[][]} grid
 * @return {number}
 */
var minimumMoves = function (grid) {
    const n = grid.length;
    const target = [n * n - 2, n * n - 1];
    const q = [[0, 1]];
    const vis = Array.from({ length: n * n }, () => Array(2).fill(false));
    vis[0][0] = true;

    const move = (i1, j1, i2, j2) => {
        if (i1 >= 0 && i1 < n && j1 >= 0 && j1 < n && i2 >= 0 && i2 < n && j2 >= 0 && j2 < n) {
            const a = i1 * n + j1;
            const b = i2 * n + j2;
            const status = i1 === i2 ? 0 : 1;
            if (!vis[a][status] && grid[i1][j1] == 0 && grid[i2][j2] == 0) {
                q.push([a, b]);
                vis[a][status] = true;
            }
        }
    };

    let ans = 0;
    while (q.length) {
        for (let k = q.length; k; --k) {
            const p = q.shift();
            if (p[0] === target[0] && p[1] === target[1]) {
                return ans;
            }
            const [i1, j1] = [~~(p[0] / n), p[0] % n];
            const [i2, j2] = [~~(p[1] / n), p[1] % n];
            // 尝试向右平移（保持身体水平/垂直状态）
            move(i1, j1 + 1, i2, j2 + 1);
            // 尝试向下平移（保持身体水平/垂直状态）
            move(i1 + 1, j1, i2 + 1, j2);
            // 当前处于水平状态，且 grid[i1 + 1][j2] 无障碍，尝试顺时针旋转90°
            if (i1 == i2 && i1 + 1 < n && grid[i1 + 1][j2] == 0) {
                move(i1, j1, i1 + 1, j1);
            }
            // 当前处于垂直状态，且 grid[i2][j1 + 1] 无障碍，尝试逆时针旋转90°
            if (j1 == j2 && j1 + 1 < n && grid[i2][j1 + 1] == 0) {
                move(i1, j1, i1, j1 + 1);
            }
        }
        ++ans;
    }
    return -1;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1211. 查询结果的质量和占比](https://leetcode.cn/problems/queries-quality-and-percentage){#1211}

{{< tabs "1211" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT
    IFNULL(query_name, 'null') AS query_name,
    ROUND(AVG(CAST(rating AS DECIMAL) / position), 2) AS quality,
    ROUND(
        (
            SUM(
                CASE
                    WHEN rating < 3 THEN 1
                    ELSE 0
                END
            ) / NULLIF(COUNT(*), 0)
        ) * 100,
        2
    ) AS poor_query_percentage
FROM Queries
GROUP BY query_name WITH ROLLUP
HAVING query_name IS NOT NULL;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p><code>Queries</code>&nbsp;表：&nbsp;</p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| query_name  | varchar |
| result      | varchar |
| position    | int     |
| rating      | int     |
+-------------+---------+
此表可能有重复的行。
此表包含了一些从数据库中收集的查询信息。
“位置”（<code>position</code>）列的值为 <strong>1</strong> 到 <strong>500</strong> 。
“评分”（<code>rating</code>）列的值为 <strong>1</strong> 到 <strong>5</strong> 。评分小于 3 的查询被定义为质量很差的查询。
</pre>

<p>&nbsp;</p>

<p>将查询结果的质量 <code>quality</code> 定义为：</p>

<blockquote>
<p>各查询结果的评分与其位置之间比率的平均值。</p>
</blockquote>

<p>将劣质查询百分比&nbsp;<code>poor_query_percentage</code>&nbsp;定义为：</p>

<blockquote>
<p>评分小于 3 的查询结果占全部查询结果的百分比。</p>
</blockquote>

<p>编写解决方案，找出每次的&nbsp;<code>query_name</code>&nbsp;、&nbsp;<code>quality</code>&nbsp;和&nbsp;<code>poor_query_percentage</code>。</p>

<p><code>quality</code>&nbsp;和&nbsp;<code>poor_query_percentage</code>&nbsp;都应 <strong>四舍五入到小数点后两位</strong> 。</p>

<p>以 <strong>任意顺序</strong> 返回结果表。</p>

<p>结果格式如下所示：</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
Queries table:
+------------+-------------------+----------+--------+
| query_name | result            | position | rating |
+------------+-------------------+----------+--------+
| Dog        | Golden Retriever  | 1        | 5      |
| Dog        | German Shepherd   | 2        | 5      |
| Dog        | Mule              | 200      | 1      |
| Cat        | Shirazi           | 5        | 2      |
| Cat        | Siamese           | 3        | 3      |
| Cat        | Sphynx            | 7        | 4      |
+------------+-------------------+----------+--------+
<strong>输出：</strong>
+------------+---------+-----------------------+
| query_name | quality | poor_query_percentage |
+------------+---------+-----------------------+
| Dog        | 2.50    | 33.33                 |
| Cat        | 0.66    | 33.33                 |
+------------+---------+-----------------------+
<strong>解释：</strong>
Dog 查询结果的质量为 ((5 / 1) + (5 / 2) + (1 / 200)) / 3 = 2.50
Dog 查询结果的劣质查询百分比为 (1 / 3) * 100 = 33.33

Cat 查询结果的质量为 ((2 / 5) + (3 / 3) + (4 / 7)) / 3 = 0.66
Cat 查询结果的劣质查询百分比为 (1 / 3) * 100 = 33.33
</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：分组统计

我们将查询结果按照 `query_name` 进行分组，然后利用 `AVG` 和 `ROUND` 函数计算 `quality` 和 `poor_query_percentage`。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT
    query_name,
    ROUND(AVG(rating / position), 2) AS quality,
    ROUND(AVG(rating < 3) * 100, 2) AS poor_query_percentage
FROM Queries
WHERE query_name IS NOT NULL
GROUP BY 1;
```

#### MySQL

```sql
# Write your MySQL query statement below
SELECT
    IFNULL(query_name, 'null') AS query_name,
    ROUND(AVG(CAST(rating AS DECIMAL) / position), 2) AS quality,
    ROUND(
        (
            SUM(
                CASE
                    WHEN rating < 3 THEN 1
                    ELSE 0
                END
            ) / NULLIF(COUNT(*), 0)
        ) * 100,
        2
    ) AS poor_query_percentage
FROM Queries
GROUP BY query_name WITH ROLLUP
HAVING query_name IS NOT NULL;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1212. 查询球队积分 🔒](https://leetcode.cn/problems/team-scores-in-football-tournament){#1212}

{{< tabs "1212" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT
    team_id,
    team_name,
    SUM(
        CASE
            WHEN team_id = host_team
            AND host_goals > guest_goals THEN 3
            WHEN team_id = guest_team
            AND guest_goals > host_goals THEN 3
            WHEN host_goals = guest_goals THEN 1
            ELSE 0
        END
    ) AS num_points
FROM
    Teams
    LEFT JOIN Matches ON team_id = host_team OR team_id = guest_team
GROUP BY 1
ORDER BY 3 DESC, 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表: <code>Teams</code></p>

<pre>
+---------------+----------+
| Column Name   | Type     |
+---------------+----------+
| team_id       | int      |
| team_name     | varchar  |
+---------------+----------+
team_id 是该表具有唯一值的列。
表中的每一行都代表一支独立足球队。
</pre>

<p>&nbsp;</p>

<p>表:&nbsp;<code>Matches</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| match_id      | int     |
| host_team     | int     |
| guest_team    | int     | 
| host_goals    | int     |
| guest_goals   | int     |
+---------------+---------+
match_id 是该表具有唯一值的列。
表中的每一行都代表一场已结束的比赛。
比赛的主客队分别由它们自己的 id 表示，他们的进球由 host_goals 和 guest_goals 分别表示。
</pre>

<p>&nbsp;</p>

<p>你希望在所有比赛之后计算所有球队的比分。积分奖励方式如下:</p>

<ul>
	<li>如果球队赢了比赛(即比对手进更多的球)，就得 <strong>3</strong> 分。</li>
	<li>如果双方打成平手(即，与对方得分相同)，则得 <strong>1</strong> 分。</li>
	<li>如果球队输掉了比赛(例如，比对手少进球)，就 <strong>不得分</strong> 。</li>
</ul>

<p>编写解决方案，以找出每个队的&nbsp;<code>team_id</code>，<code>team_name</code> 和 <code>num_points</code>。</p>

<p>返回的结果根据&nbsp;<code>num_points</code><strong> 降序排序</strong>，如果有两队积分相同，那么这两队按&nbsp;<code>team_id</code>&nbsp; <strong>升序排序</strong>。</p>

<p>返回结果格式如下。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<code><strong>输入：</strong>
Teams </code>table:
+-----------+--------------+
| team_id   | team_name    |
+-----------+--------------+
| 10        | Leetcode FC  |
| 20        | NewYork FC   |
| 30        | Atlanta FC   |
| 40        | Chicago FC   |
| 50        | Toronto FC   |
+-----------+--------------+
<code>Matches </code>table:
+------------+--------------+---------------+-------------+--------------+
| match_id   | host_team    | guest_team    | host_goals  | guest_goals  |
+------------+--------------+---------------+-------------+--------------+
| 1          | 10           | 20            | 3           | 0            |
| 2          | 30           | 10            | 2           | 2            |
| 3          | 10           | 50            | 5           | 1            |
| 4          | 20           | 30            | 1           | 0            |
| 5          | 50           | 30            | 1           | 0            |
+------------+--------------+---------------+-------------+--------------+
<strong>输出：</strong>
+------------+--------------+---------------+
| team_id    | team_name    | num_points    |
+------------+--------------+---------------+
| 10         | Leetcode FC  | 7             |
| 20         | NewYork FC   | 3             |
| 50         | Toronto FC   | 3             |
| 30         | Atlanta FC   | 1             |
| 40         | Chicago FC   | 0             |
+------------+--------------+---------------+</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：左连接 + 分组 + CASE 表达式

我们可以通过左连接，将 `Teams` 表和 `Matches` 表连接起来，连接的条件为 `team_id = host_team OR team_id = guest_team`，这样就可以得到每个球队的所有比赛信息。

接下来，我们按照 `team_id` 分组，然后使用 `CASE` 表达式计算每个球队的积分，计算规则如下：

-   如果球队是主队，且主队进球数大于客队进球数，则积分加 $3$ 分；
-   如果球队是客队，且客队进球数大于主队进球数，则积分加 $3$ 分；
-   如果主队和客队进球数相同，则积分加 $1$ 分；

最后，我们按照积分降序排序，如果积分相同，则按照 `team_id` 升序排序。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT
    team_id,
    team_name,
    SUM(
        CASE
            WHEN team_id = host_team
            AND host_goals > guest_goals THEN 3
            WHEN team_id = guest_team
            AND guest_goals > host_goals THEN 3
            WHEN host_goals = guest_goals THEN 1
            ELSE 0
        END
    ) AS num_points
FROM
    Teams
    LEFT JOIN Matches ON team_id = host_team OR team_id = guest_team
GROUP BY 1
ORDER BY 3 DESC, 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1213. 三个有序数组的交集 🔒](https://leetcode.cn/problems/intersection-of-three-sorted-arrays){#1213}

{{< tabs "1213" >}}

{{% tab "python" %}}
```python
class Solution:
    def arraysIntersection(
        self, arr1: List[int], arr2: List[int], arr3: List[int]
    ) -> List[int]:
        ans = []
        for x in arr1:
            i = bisect_left(arr2, x)
            j = bisect_left(arr3, x)
            if i < len(arr2) and j < len(arr3) and arr2[i] == x and arr3[j] == x:
                ans.append(x)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<Integer> arraysIntersection(int[] arr1, int[] arr2, int[] arr3) {
        List<Integer> ans = new ArrayList<>();
        for (int x : arr1) {
            int i = Arrays.binarySearch(arr2, x);
            int j = Arrays.binarySearch(arr3, x);
            if (i >= 0 && j >= 0) {
                ans.add(x);
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
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        vector<int> ans;
        for (int x : arr1) {
            auto i = lower_bound(arr2.begin(), arr2.end(), x);
            auto j = lower_bound(arr3.begin(), arr3.end(), x);
            if (*i == x && *j == x) {
                ans.push_back(x);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func arraysIntersection(arr1 []int, arr2 []int, arr3 []int) (ans []int) {
	for _, x := range arr1 {
		i := sort.SearchInts(arr2, x)
		j := sort.SearchInts(arr3, x)
		if i < len(arr2) && j < len(arr3) && arr2[i] == x && arr3[j] == x {
			ans = append(ans, x)
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param Integer[] $arr1
     * @param Integer[] $arr2
     * @param Integer[] $arr3
     * @return Integer[]
     */
    function arraysIntersection($arr1, $arr2, $arr3) {
        $rs = [];
        $arr = array_merge($arr1, $arr2, $arr3);
        for ($i = 0; $i < count($arr); $i++) {
            $hashtable[$arr[$i]] += 1;
            if ($hashtable[$arr[$i]] === 3) {
                array_push($rs, $arr[$i]);
            }
        }
        return $rs;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给出三个均为 <strong>严格递增排列 </strong>的整数数组&nbsp;<code>arr1</code>，<code>arr2</code> 和&nbsp;<code>arr3</code>。返回一个由&nbsp;<strong>仅 </strong>在这三个数组中&nbsp;<strong>同时出现&nbsp;</strong>的整数所构成的有序数组。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入: </strong>arr1 = [1,2,3,4,5], arr2 = [1,2,5,7,9], arr3 = [1,3,4,5,8]
<strong>输出: </strong>[1,5]
<strong>解释: </strong>只有 1 和 5 同时在这三个数组中出现.
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入: </strong>arr1 = [197,418,523,876,1356], arr2 = [501,880,1593,1710,1870], arr3 = [521,682,1337,1395,1764]
<strong>输出: </strong>[]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= arr1.length, arr2.length, arr3.length &lt;= 1000</code></li>
	<li><code>1 &lt;= arr1[i], arr2[i], arr3[i] &lt;= 2000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数

遍历三个数组，统计每个数字出现的次数，然后遍历任意一个数组，若某个数字出现的次数为 $3$，则将其加入结果数组。

时间复杂度 $O(n)$，空间复杂度 $O(m)$。其中 $n$ 和 $m$ 分别为数组的长度和数组中数字的范围。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def arraysIntersection(
        self, arr1: List[int], arr2: List[int], arr3: List[int]
    ) -> List[int]:
        cnt = Counter(arr1 + arr2 + arr3)
        return [x for x in arr1 if cnt[x] == 3]
```

#### Java

```java
class Solution {
    public List<Integer> arraysIntersection(int[] arr1, int[] arr2, int[] arr3) {
        List<Integer> ans = new ArrayList<>();
        int[] cnt = new int[2001];
        for (int x : arr1) {
            ++cnt[x];
        }
        for (int x : arr2) {
            ++cnt[x];
        }
        for (int x : arr3) {
            if (++cnt[x] == 3) {
                ans.add(x);
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
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        vector<int> ans;
        int cnt[2001]{};
        for (int x : arr1) {
            ++cnt[x];
        }
        for (int x : arr2) {
            ++cnt[x];
        }
        for (int x : arr3) {
            if (++cnt[x] == 3) {
                ans.push_back(x);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func arraysIntersection(arr1 []int, arr2 []int, arr3 []int) (ans []int) {
	cnt := [2001]int{}
	for _, x := range arr1 {
		cnt[x]++
	}
	for _, x := range arr2 {
		cnt[x]++
	}
	for _, x := range arr3 {
		cnt[x]++
		if cnt[x] == 3 {
			ans = append(ans, x)
		}
	}
	return
}
```

#### PHP

```php
class Solution {
    /**
     * @param Integer[] $arr1
     * @param Integer[] $arr2
     * @param Integer[] $arr3
     * @return Integer[]
     */
    function arraysIntersection($arr1, $arr2, $arr3) {
        $rs = [];
        $arr = array_merge($arr1, $arr2, $arr3);
        for ($i = 0; $i < count($arr); $i++) {
            $hashtable[$arr[$i]] += 1;
            if ($hashtable[$arr[$i]] === 3) {
                array_push($rs, $arr[$i]);
            }
        }
        return $rs;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：二分查找

遍历第一个数组，对于其中的每个数字，使用二分查找在第二个数组和第三个数组中查找该数字，若都找到，则将该数字加入结果数组。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(1)$。其中 $n$ 为数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def arraysIntersection(
        self, arr1: List[int], arr2: List[int], arr3: List[int]
    ) -> List[int]:
        ans = []
        for x in arr1:
            i = bisect_left(arr2, x)
            j = bisect_left(arr3, x)
            if i < len(arr2) and j < len(arr3) and arr2[i] == x and arr3[j] == x:
                ans.append(x)
        return ans
```

#### Java

```java
class Solution {
    public List<Integer> arraysIntersection(int[] arr1, int[] arr2, int[] arr3) {
        List<Integer> ans = new ArrayList<>();
        for (int x : arr1) {
            int i = Arrays.binarySearch(arr2, x);
            int j = Arrays.binarySearch(arr3, x);
            if (i >= 0 && j >= 0) {
                ans.add(x);
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
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        vector<int> ans;
        for (int x : arr1) {
            auto i = lower_bound(arr2.begin(), arr2.end(), x);
            auto j = lower_bound(arr3.begin(), arr3.end(), x);
            if (*i == x && *j == x) {
                ans.push_back(x);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func arraysIntersection(arr1 []int, arr2 []int, arr3 []int) (ans []int) {
	for _, x := range arr1 {
		i := sort.SearchInts(arr2, x)
		j := sort.SearchInts(arr3, x)
		if i < len(arr2) && j < len(arr3) && arr2[i] == x && arr3[j] == x {
			ans = append(ans, x)
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

# [1214. 查找两棵二叉搜索树之和 🔒](https://leetcode.cn/problems/two-sum-bsts){#1214}

{{< tabs "1214" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def twoSumBSTs(
        self, root1: Optional[TreeNode], root2: Optional[TreeNode], target: int
    ) -> bool:
        def dfs(root: Optional[TreeNode], i: int):
            if root is None:
                return
            dfs(root.left, i)
            nums[i].append(root.val)
            dfs(root.right, i)

        nums = [[], []]
        dfs(root1, 0)
        dfs(root2, 1)
        i, j = 0, len(nums[1]) - 1
        while i < len(nums[0]) and ~j:
            x = nums[0][i] + nums[1][j]
            if x == target:
                return True
            if x < target:
                i += 1
            else:
                j -= 1
        return False
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
    private List<Integer>[] nums = new List[2];

    public boolean twoSumBSTs(TreeNode root1, TreeNode root2, int target) {
        Arrays.setAll(nums, k -> new ArrayList<>());
        dfs(root1, 0);
        dfs(root2, 1);
        int i = 0, j = nums[1].size() - 1;
        while (i < nums[0].size() && j >= 0) {
            int x = nums[0].get(i) + nums[1].get(j);
            if (x == target) {
                return true;
            }
            if (x < target) {
                ++i;
            } else {
                --j;
            }
        }
        return false;
    }

    private void dfs(TreeNode root, int i) {
        if (root == null) {
            return;
        }
        dfs(root.left, i);
        nums[i].add(root.val);
        dfs(root.right, i);
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
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        vector<int> nums[2];
        function<void(TreeNode*, int)> dfs = [&](TreeNode* root, int i) {
            if (!root) {
                return;
            }
            dfs(root->left, i);
            nums[i].push_back(root->val);
            dfs(root->right, i);
        };
        dfs(root1, 0);
        dfs(root2, 1);
        int i = 0, j = nums[1].size() - 1;
        while (i < nums[0].size() && j >= 0) {
            int x = nums[0][i] + nums[1][j];
            if (x == target) {
                return true;
            }
            if (x < target) {
                ++i;
            } else {
                --j;
            }
        }
        return false;
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
func twoSumBSTs(root1 *TreeNode, root2 *TreeNode, target int) bool {
	nums := [2][]int{}
	var dfs func(*TreeNode, int)
	dfs = func(root *TreeNode, i int) {
		if root == nil {
			return
		}
		dfs(root.Left, i)
		nums[i] = append(nums[i], root.Val)
		dfs(root.Right, i)
	}
	dfs(root1, 0)
	dfs(root2, 1)
	i, j := 0, len(nums[1])-1
	for i < len(nums[0]) && j >= 0 {
		x := nums[0][i] + nums[1][j]
		if x == target {
			return true
		}
		if x < target {
			i++
		} else {
			j--
		}
	}
	return false
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

function twoSumBSTs(root1: TreeNode | null, root2: TreeNode | null, target: number): boolean {
    const nums: number[][] = Array(2)
        .fill(0)
        .map(() => []);
    const dfs = (root: TreeNode | null, i: number) => {
        if (!root) {
            return;
        }
        dfs(root.left, i);
        nums[i].push(root.val);
        dfs(root.right, i);
    };
    dfs(root1, 0);
    dfs(root2, 1);
    let i = 0;
    let j = nums[1].length - 1;
    while (i < nums[0].length && j >= 0) {
        const x = nums[0][i] + nums[1][j];
        if (x === target) {
            return true;
        }
        if (x < target) {
            ++i;
        } else {
            --j;
        }
    }
    return false;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给出两棵二叉搜索树的根节点&nbsp;<meta charset="UTF-8" /><code>root1</code>&nbsp;和<meta charset="UTF-8" />&nbsp;<code>root2</code>&nbsp;，请你从两棵树中各找出一个节点，使得这两个节点的值之和等于目标值&nbsp;<code>Target</code>。</p>

<p>如果可以找到返回&nbsp;<code>True</code>，否则返回&nbsp;<code>False</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1200-1299/1214.Two%20Sum%20BSTs/images/ex1.png" style="height: 169px; width: 369px;" /></p>

<pre>
<strong>输入：</strong>root1 = [2,1,4], root2 = [1,0,3], target = 5
<strong>输出：</strong>true
<strong>解释：</strong>2 加 3 和为 5 。
</pre>

<p><strong>示例 2：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1200-1299/1214.Two%20Sum%20BSTs/images/ex2.png" style="height: 290px; width: 453px;" /></p>

<pre>
<strong>输入：</strong>root1 = [0,-10,10], root2 = [5,1,7,0,2], target = 18
<strong>输出：</strong>false</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>每棵树上节点数在<meta charset="UTF-8" />&nbsp;<code>[1, 5000]</code>&nbsp;范围内。<meta charset="UTF-8" /></li>
	<li><code>-10<sup>9</sup>&nbsp;&lt;= Node.val, target &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：中序遍历 + 双指针

我们分别对两棵树进行中序遍历，得到两个有序数组 $nums[0]$ 和 $nums[1]$，然后使用双指针的方法判断是否存在两个数的和为目标值。双指针判断方法如下：

初始化两个指针 $i$ 和 $j$，分别指向数组 $nums[0]$ 的左边界和数组 $nums[1]$ 的右边界；

每次比较 $x = nums[0][i] + nums[1][j]$ 与目标值的大小。如果 $x = target$，则返回 `true`；否则，如果 $x \lt target$，则 $i$ 右移一位；否则，如果 $x \gt target$，则 $j$ 左移一位。

时间复杂度 $O(m + n)$，空间复杂度 $O(m + n)$。其中 $m$ 和 $n$ 分别为两棵树的节点数。

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
    def twoSumBSTs(
        self, root1: Optional[TreeNode], root2: Optional[TreeNode], target: int
    ) -> bool:
        def dfs(root: Optional[TreeNode], i: int):
            if root is None:
                return
            dfs(root.left, i)
            nums[i].append(root.val)
            dfs(root.right, i)

        nums = [[], []]
        dfs(root1, 0)
        dfs(root2, 1)
        i, j = 0, len(nums[1]) - 1
        while i < len(nums[0]) and ~j:
            x = nums[0][i] + nums[1][j]
            if x == target:
                return True
            if x < target:
                i += 1
            else:
                j -= 1
        return False
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
    private List<Integer>[] nums = new List[2];

    public boolean twoSumBSTs(TreeNode root1, TreeNode root2, int target) {
        Arrays.setAll(nums, k -> new ArrayList<>());
        dfs(root1, 0);
        dfs(root2, 1);
        int i = 0, j = nums[1].size() - 1;
        while (i < nums[0].size() && j >= 0) {
            int x = nums[0].get(i) + nums[1].get(j);
            if (x == target) {
                return true;
            }
            if (x < target) {
                ++i;
            } else {
                --j;
            }
        }
        return false;
    }

    private void dfs(TreeNode root, int i) {
        if (root == null) {
            return;
        }
        dfs(root.left, i);
        nums[i].add(root.val);
        dfs(root.right, i);
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
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        vector<int> nums[2];
        function<void(TreeNode*, int)> dfs = [&](TreeNode* root, int i) {
            if (!root) {
                return;
            }
            dfs(root->left, i);
            nums[i].push_back(root->val);
            dfs(root->right, i);
        };
        dfs(root1, 0);
        dfs(root2, 1);
        int i = 0, j = nums[1].size() - 1;
        while (i < nums[0].size() && j >= 0) {
            int x = nums[0][i] + nums[1][j];
            if (x == target) {
                return true;
            }
            if (x < target) {
                ++i;
            } else {
                --j;
            }
        }
        return false;
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
func twoSumBSTs(root1 *TreeNode, root2 *TreeNode, target int) bool {
	nums := [2][]int{}
	var dfs func(*TreeNode, int)
	dfs = func(root *TreeNode, i int) {
		if root == nil {
			return
		}
		dfs(root.Left, i)
		nums[i] = append(nums[i], root.Val)
		dfs(root.Right, i)
	}
	dfs(root1, 0)
	dfs(root2, 1)
	i, j := 0, len(nums[1])-1
	for i < len(nums[0]) && j >= 0 {
		x := nums[0][i] + nums[1][j]
		if x == target {
			return true
		}
		if x < target {
			i++
		} else {
			j--
		}
	}
	return false
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

function twoSumBSTs(root1: TreeNode | null, root2: TreeNode | null, target: number): boolean {
    const nums: number[][] = Array(2)
        .fill(0)
        .map(() => []);
    const dfs = (root: TreeNode | null, i: number) => {
        if (!root) {
            return;
        }
        dfs(root.left, i);
        nums[i].push(root.val);
        dfs(root.right, i);
    };
    dfs(root1, 0);
    dfs(root2, 1);
    let i = 0;
    let j = nums[1].length - 1;
    while (i < nums[0].length && j >= 0) {
        const x = nums[0][i] + nums[1][j];
        if (x === target) {
            return true;
        }
        if (x < target) {
            ++i;
        } else {
            --j;
        }
    }
    return false;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1215. 步进数 🔒](https://leetcode.cn/problems/stepping-numbers){#1215}

{{< tabs "1215" >}}

{{% tab "python" %}}
```python
class Solution:
    def countSteppingNumbers(self, low: int, high: int) -> List[int]:
        ans = []
        if low == 0:
            ans.append(0)
        q = deque(range(1, 10))
        while q:
            v = q.popleft()
            if v > high:
                break
            if v >= low:
                ans.append(v)
            x = v % 10
            if x:
                q.append(v * 10 + x - 1)
            if x < 9:
                q.append(v * 10 + x + 1)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<Integer> countSteppingNumbers(int low, int high) {
        List<Integer> ans = new ArrayList<>();
        if (low == 0) {
            ans.add(0);
        }
        Deque<Long> q = new ArrayDeque<>();
        for (long i = 1; i < 10; ++i) {
            q.offer(i);
        }
        while (!q.isEmpty()) {
            long v = q.pollFirst();
            if (v > high) {
                break;
            }
            if (v >= low) {
                ans.add((int) v);
            }
            int x = (int) v % 10;
            if (x > 0) {
                q.offer(v * 10 + x - 1);
            }
            if (x < 9) {
                q.offer(v * 10 + x + 1);
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
    vector<int> countSteppingNumbers(int low, int high) {
        vector<int> ans;
        if (low == 0) {
            ans.push_back(0);
        }
        queue<long long> q;
        for (int i = 1; i < 10; ++i) {
            q.push(i);
        }
        while (!q.empty()) {
            long long v = q.front();
            q.pop();
            if (v > high) {
                break;
            }
            if (v >= low) {
                ans.push_back(v);
            }
            int x = v % 10;
            if (x > 0) {
                q.push(v * 10 + x - 1);
            }
            if (x < 9) {
                q.push(v * 10 + x + 1);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countSteppingNumbers(low int, high int) []int {
	ans := []int{}
	if low == 0 {
		ans = append(ans, 0)
	}
	q := []int{1, 2, 3, 4, 5, 6, 7, 8, 9}
	for len(q) > 0 {
		v := q[0]
		q = q[1:]
		if v > high {
			break
		}
		if v >= low {
			ans = append(ans, v)
		}
		x := v % 10
		if x > 0 {
			q = append(q, v*10+x-1)
		}
		if x < 9 {
			q = append(q, v*10+x+1)
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countSteppingNumbers(low: number, high: number): number[] {
    const ans: number[] = [];
    if (low === 0) {
        ans.push(0);
    }
    const q: number[] = [];
    for (let i = 1; i < 10; ++i) {
        q.push(i);
    }
    while (q.length) {
        const v = q.shift()!;
        if (v > high) {
            break;
        }
        if (v >= low) {
            ans.push(v);
        }
        const x = v % 10;
        if (x > 0) {
            q.push(v * 10 + x - 1);
        }
        if (x < 9) {
            q.push(v * 10 + x + 1);
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

<p>如果一个整数上的每一位数字与其相邻位上的数字的绝对差都是 <code>1</code>，那么这个数就是一个「<strong>步进数</strong>」。</p>

<p>例如，<code>321</code>&nbsp;是一个 <strong>步进数</strong>，而&nbsp;<code>421</code>&nbsp;不是。</p>

<p>给你两个整数，<code>low</code>&nbsp;和&nbsp;<code>high</code>，请你找出在&nbsp;<code>[low, high]</code>&nbsp;范围内的所有 <strong>步进数</strong>，并返回&nbsp;<strong>排序后</strong> 的结果。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>low = 0, high = 21
<strong>输出：</strong>[0,1,2,3,4,5,6,7,8,9,10,12,21]
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>low = 10, high = 15
<b>输出：</b>[10,12]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= low &lt;= high &lt;= 2 * 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：BFS

首先，如果 $low$ 为 $0$，那么我们需要将 $0$ 加入答案中。

接下来，我们创建一个队列 $q$，并将 $1 \sim 9$ 加入队列中。然后我们不断从队列中取出元素，记当前元素为 $v$，如果 $v$ 大于 $high$，那么我们就停止搜索；如果 $v$ 在 $[low, high]$ 的范围内，那么我们将 $v$ 加入答案中。然后，我们需要将 $v$ 的最后一位数字记为 $x$，如果 $x \gt 0$，那么我们将 $v \times 10 + x - 1$ 加入队列中；如果 $x \lt 9$，那么我们将 $v \times 10 + x + 1$ 加入队列中。重复上述操作，直到队列为空。

时间复杂度 $O(10 \times 2^{\log M})$，空间复杂度 $O(2^{\log M})$，其中 $M$ 为 $high$ 的位数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countSteppingNumbers(self, low: int, high: int) -> List[int]:
        ans = []
        if low == 0:
            ans.append(0)
        q = deque(range(1, 10))
        while q:
            v = q.popleft()
            if v > high:
                break
            if v >= low:
                ans.append(v)
            x = v % 10
            if x:
                q.append(v * 10 + x - 1)
            if x < 9:
                q.append(v * 10 + x + 1)
        return ans
```

#### Java

```java
class Solution {
    public List<Integer> countSteppingNumbers(int low, int high) {
        List<Integer> ans = new ArrayList<>();
        if (low == 0) {
            ans.add(0);
        }
        Deque<Long> q = new ArrayDeque<>();
        for (long i = 1; i < 10; ++i) {
            q.offer(i);
        }
        while (!q.isEmpty()) {
            long v = q.pollFirst();
            if (v > high) {
                break;
            }
            if (v >= low) {
                ans.add((int) v);
            }
            int x = (int) v % 10;
            if (x > 0) {
                q.offer(v * 10 + x - 1);
            }
            if (x < 9) {
                q.offer(v * 10 + x + 1);
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
    vector<int> countSteppingNumbers(int low, int high) {
        vector<int> ans;
        if (low == 0) {
            ans.push_back(0);
        }
        queue<long long> q;
        for (int i = 1; i < 10; ++i) {
            q.push(i);
        }
        while (!q.empty()) {
            long long v = q.front();
            q.pop();
            if (v > high) {
                break;
            }
            if (v >= low) {
                ans.push_back(v);
            }
            int x = v % 10;
            if (x > 0) {
                q.push(v * 10 + x - 1);
            }
            if (x < 9) {
                q.push(v * 10 + x + 1);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func countSteppingNumbers(low int, high int) []int {
	ans := []int{}
	if low == 0 {
		ans = append(ans, 0)
	}
	q := []int{1, 2, 3, 4, 5, 6, 7, 8, 9}
	for len(q) > 0 {
		v := q[0]
		q = q[1:]
		if v > high {
			break
		}
		if v >= low {
			ans = append(ans, v)
		}
		x := v % 10
		if x > 0 {
			q = append(q, v*10+x-1)
		}
		if x < 9 {
			q = append(q, v*10+x+1)
		}
	}
	return ans
}
```

#### TypeScript

```ts
function countSteppingNumbers(low: number, high: number): number[] {
    const ans: number[] = [];
    if (low === 0) {
        ans.push(0);
    }
    const q: number[] = [];
    for (let i = 1; i < 10; ++i) {
        q.push(i);
    }
    while (q.length) {
        const v = q.shift()!;
        if (v > high) {
            break;
        }
        if (v >= low) {
            ans.push(v);
        }
        const x = v % 10;
        if (x > 0) {
            q.push(v * 10 + x - 1);
        }
        if (x < 9) {
            q.push(v * 10 + x + 1);
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

# [1216. 验证回文串 III 🔒](https://leetcode.cn/problems/valid-palindrome-iii){#1216}

{{< tabs "1216" >}}

{{% tab "python" %}}
```python
class Solution:
    def isValidPalindrome(self, s: str, k: int) -> bool:
        n = len(s)
        f = [[0] * n for _ in range(n)]
        for i in range(n):
            f[i][i] = 1
        for i in range(n - 2, -1, -1):
            for j in range(i + 1, n):
                if s[i] == s[j]:
                    f[i][j] = f[i + 1][j - 1] + 2
                else:
                    f[i][j] = max(f[i + 1][j], f[i][j - 1])
                if f[i][j] + k >= n:
                    return True
        return False
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean isValidPalindrome(String s, int k) {
        int n = s.length();
        int[][] f = new int[n][n];
        for (int i = 0; i < n; ++i) {
            f[i][i] = 1;
        }
        for (int i = n - 2; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (s.charAt(i) == s.charAt(j)) {
                    f[i][j] = f[i + 1][j - 1] + 2;
                } else {
                    f[i][j] = Math.max(f[i + 1][j], f[i][j - 1]);
                }
                if (f[i][j] + k >= n) {
                    return true;
                }
            }
        }
        return false;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool isValidPalindrome(string s, int k) {
        int n = s.length();
        int f[n][n];
        memset(f, 0, sizeof f);
        for (int i = 0; i < n; ++i) {
            f[i][i] = 1;
        }
        for (int i = n - 2; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (s[i] == s[j]) {
                    f[i][j] = f[i + 1][j - 1] + 2;
                } else {
                    f[i][j] = max(f[i + 1][j], f[i][j - 1]);
                }
                if (f[i][j] + k >= n) {
                    return true;
                }
            }
        }
        return false;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func isValidPalindrome(s string, k int) bool {
	n := len(s)
	f := make([][]int, n)
	for i := range f {
		f[i] = make([]int, n)
		f[i][i] = 1
	}
	for i := n - 2; i >= 0; i-- {
		for j := i + 1; j < n; j++ {
			if s[i] == s[j] {
				f[i][j] = f[i+1][j-1] + 2
			} else {
				f[i][j] = max(f[i+1][j], f[i][j-1])
			}
			if f[i][j]+k >= n {
				return true
			}
		}
	}
	return false
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function isValidPalindrome(s: string, k: number): boolean {
    const n = s.length;
    const f: number[][] = Array.from({ length: n }, () => Array.from({ length: n }, () => 0));
    for (let i = 0; i < n; ++i) {
        f[i][i] = 1;
    }
    for (let i = n - 2; ~i; --i) {
        for (let j = i + 1; j < n; ++j) {
            if (s[i] === s[j]) {
                f[i][j] = f[i + 1][j - 1] + 2;
            } else {
                f[i][j] = Math.max(f[i + 1][j], f[i][j - 1]);
            }
            if (f[i][j] + k >= n) {
                return true;
            }
        }
    }
    return false;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn is_valid_palindrome(s: String, k: i32) -> bool {
        let s = s.as_bytes();
        let n = s.len();
        let mut f = vec![vec![0; n]; n];

        for i in 0..n {
            f[i][i] = 1;
        }

        for i in (0..n - 2).rev() {
            for j in i + 1..n {
                if s[i] == s[j] {
                    f[i][j] = f[i + 1][j - 1] + 2;
                } else {
                    f[i][j] = std::cmp::max(f[i + 1][j], f[i][j - 1]);
                }

                if f[i][j] + k >= (n as i32) {
                    return true;
                }
            }
        }

        false
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给出一个字符串&nbsp;<code>s</code>&nbsp;和一个整数&nbsp;<code>k</code>，若这个字符串是一个「k&nbsp;<strong>回文</strong>&nbsp;」，则返回 <code>true</code> 。</p>

<p>如果可以通过从字符串中删去最多 <code>k</code> 个字符将其转换为回文，那么这个字符串就是一个「<strong>k</strong>&nbsp;<strong>回文</strong>&nbsp;」。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "abcdeca", k = 2
<strong>输</strong><strong>出：</strong>true
<strong>解释：</strong>删去字符 “b” 和 “e”。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入：</strong>s = "abbababa", k = 1
<strong>输</strong><strong>出：</strong>true
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s</code>&nbsp;中只含有小写英文字母</li>
	<li><code>1 &lt;= k&nbsp;&lt;= s.length</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

题目要求删去最多 $k$ 个字符，使得剩余的字符串是回文串。可以转换为求最长回文子序列的问题。

我们定义 $f[i][j]$ 表示字符串 $s$ 中下标范围 $[i, j]$ 内的最长回文子序列的长度。初始时 $f[i][i] = 1$，即每个单独的字符都是一个回文子序列。

当 $s[i] = s[j]$ 时，有 $f[i][j] = f[i + 1][j - 1] + 2$，即去掉 $s[i]$ 和 $s[j]$ 后，剩余的字符串的最长回文子序列长度加 $2$。

当 $s[i] \neq s[j]$ 时，有 $f[i][j] = \max(f[i + 1][j], f[i][j - 1])$，即去掉 $s[i]$ 或 $s[j]$ 后，剩余的字符串的最长回文子序列长度。

然后是否存在 $f[i][j] + k \geq n$，如果存在，说明可以通过删去 $k$ 个字符，使得剩余的字符串是回文串。

时间复杂度 $O(n^2)$，空间复杂度 $O(n^2)$。其中 $n$ 为字符串 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def isValidPalindrome(self, s: str, k: int) -> bool:
        n = len(s)
        f = [[0] * n for _ in range(n)]
        for i in range(n):
            f[i][i] = 1
        for i in range(n - 2, -1, -1):
            for j in range(i + 1, n):
                if s[i] == s[j]:
                    f[i][j] = f[i + 1][j - 1] + 2
                else:
                    f[i][j] = max(f[i + 1][j], f[i][j - 1])
                if f[i][j] + k >= n:
                    return True
        return False
```

#### Java

```java
class Solution {
    public boolean isValidPalindrome(String s, int k) {
        int n = s.length();
        int[][] f = new int[n][n];
        for (int i = 0; i < n; ++i) {
            f[i][i] = 1;
        }
        for (int i = n - 2; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (s.charAt(i) == s.charAt(j)) {
                    f[i][j] = f[i + 1][j - 1] + 2;
                } else {
                    f[i][j] = Math.max(f[i + 1][j], f[i][j - 1]);
                }
                if (f[i][j] + k >= n) {
                    return true;
                }
            }
        }
        return false;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool isValidPalindrome(string s, int k) {
        int n = s.length();
        int f[n][n];
        memset(f, 0, sizeof f);
        for (int i = 0; i < n; ++i) {
            f[i][i] = 1;
        }
        for (int i = n - 2; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (s[i] == s[j]) {
                    f[i][j] = f[i + 1][j - 1] + 2;
                } else {
                    f[i][j] = max(f[i + 1][j], f[i][j - 1]);
                }
                if (f[i][j] + k >= n) {
                    return true;
                }
            }
        }
        return false;
    }
};
```

#### Go

```go
func isValidPalindrome(s string, k int) bool {
	n := len(s)
	f := make([][]int, n)
	for i := range f {
		f[i] = make([]int, n)
		f[i][i] = 1
	}
	for i := n - 2; i >= 0; i-- {
		for j := i + 1; j < n; j++ {
			if s[i] == s[j] {
				f[i][j] = f[i+1][j-1] + 2
			} else {
				f[i][j] = max(f[i+1][j], f[i][j-1])
			}
			if f[i][j]+k >= n {
				return true
			}
		}
	}
	return false
}
```

#### TypeScript

```ts
function isValidPalindrome(s: string, k: number): boolean {
    const n = s.length;
    const f: number[][] = Array.from({ length: n }, () => Array.from({ length: n }, () => 0));
    for (let i = 0; i < n; ++i) {
        f[i][i] = 1;
    }
    for (let i = n - 2; ~i; --i) {
        for (let j = i + 1; j < n; ++j) {
            if (s[i] === s[j]) {
                f[i][j] = f[i + 1][j - 1] + 2;
            } else {
                f[i][j] = Math.max(f[i + 1][j], f[i][j - 1]);
            }
            if (f[i][j] + k >= n) {
                return true;
            }
        }
    }
    return false;
}
```

#### Rust

```rust
impl Solution {
    pub fn is_valid_palindrome(s: String, k: i32) -> bool {
        let s = s.as_bytes();
        let n = s.len();
        let mut f = vec![vec![0; n]; n];

        for i in 0..n {
            f[i][i] = 1;
        }

        for i in (0..n - 2).rev() {
            for j in i + 1..n {
                if s[i] == s[j] {
                    f[i][j] = f[i + 1][j - 1] + 2;
                } else {
                    f[i][j] = std::cmp::max(f[i + 1][j], f[i][j - 1]);
                }

                if f[i][j] + k >= (n as i32) {
                    return true;
                }
            }
        }

        false
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1217. 玩筹码](https://leetcode.cn/problems/minimum-cost-to-move-chips-to-the-same-position){#1217}

{{< tabs "1217" >}}

{{% tab "python" %}}
```python
class Solution:
    def minCostToMoveChips(self, position: List[int]) -> int:
        a = sum(p % 2 for p in position)
        b = len(position) - a
        return min(a, b)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minCostToMoveChips(int[] position) {
        int a = 0;
        for (int p : position) {
            a += p % 2;
        }
        int b = position.length - a;
        return Math.min(a, b);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int a = 0;
        for (auto& p : position) a += p & 1;
        int b = position.size() - a;
        return min(a, b);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minCostToMoveChips(position []int) int {
	a := 0
	for _, p := range position {
		a += p & 1
	}
	b := len(position) - a
	if a < b {
		return a
	}
	return b
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} position
 * @return {number}
 */
var minCostToMoveChips = function (position) {
    let a = 0;
    for (let v of position) {
        a += v % 2;
    }
    let b = position.length - a;
    return Math.min(a, b);
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>有&nbsp;<code>n</code>&nbsp;个筹码。第 <code>i</code> 个筹码的位置是<meta charset="UTF-8" />&nbsp;<code>position[i]</code>&nbsp;。</p>

<p>我们需要把所有筹码移到同一个位置。在一步中，我们可以将第 <code>i</code> 个筹码的位置从&nbsp;<code>position[i]</code>&nbsp;改变为:</p>

<p><meta charset="UTF-8" /></p>

<ul>
	<li><code>position[i] + 2</code>&nbsp;或&nbsp;<code>position[i] - 2</code>&nbsp;，此时&nbsp;<code>cost = 0</code></li>
	<li><code>position[i] + 1</code>&nbsp;或&nbsp;<code>position[i] - 1</code>&nbsp;，此时&nbsp;<code>cost = 1</code></li>
</ul>

<p>返回将所有筹码移动到同一位置上所需要的 <em>最小代价</em> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1200-1299/1217.Minimum%20Cost%20to%20Move%20Chips%20to%20The%20Same%20Position/images/chips_e1.jpg" style="height: 217px; width: 750px;" /></p>

<pre>
<strong>输入：</strong>position = [1,2,3]
<strong>输出：</strong>1
<strong>解释：</strong>第一步:将位置3的筹码移动到位置1，成本为0。
第二步:将位置2的筹码移动到位置1，成本= 1。
总成本是1。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1200-1299/1217.Minimum%20Cost%20to%20Move%20Chips%20to%20The%20Same%20Position/images/chip_e2.jpg" style="height: 306px; width: 750px;" /></p>

<pre>
<strong>输入：</strong>position = [2,2,2,3,3]
<strong>输出：</strong>2
<strong>解释：</strong>我们可以把位置3的两个筹码移到位置2。每一步的成本为1。总成本= 2。
</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入：</strong>position = [1,1000000000]
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= position.length &lt;= 100</code></li>
	<li><code>1 &lt;= position[i] &lt;= 10^9</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：脑筋急转弯

将所有偶数下标的芯片移动到 0 号位置，所有奇数下标的芯片移动到 1 号位置，所有的代价为 0，接下来只需要在 0/1 号位置中选择其中一个较小数量的芯片，移动到另一个位置。所需的最小代价就是那个较小的数量。

时间复杂度 $O(n)$，其中 $n$ 为芯片的数量。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minCostToMoveChips(self, position: List[int]) -> int:
        a = sum(p % 2 for p in position)
        b = len(position) - a
        return min(a, b)
```

#### Java

```java
class Solution {
    public int minCostToMoveChips(int[] position) {
        int a = 0;
        for (int p : position) {
            a += p % 2;
        }
        int b = position.length - a;
        return Math.min(a, b);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int a = 0;
        for (auto& p : position) a += p & 1;
        int b = position.size() - a;
        return min(a, b);
    }
};
```

#### Go

```go
func minCostToMoveChips(position []int) int {
	a := 0
	for _, p := range position {
		a += p & 1
	}
	b := len(position) - a
	if a < b {
		return a
	}
	return b
}
```

#### JavaScript

```js
/**
 * @param {number[]} position
 * @return {number}
 */
var minCostToMoveChips = function (position) {
    let a = 0;
    for (let v of position) {
        a += v % 2;
    }
    let b = position.length - a;
    return Math.min(a, b);
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1218. 最长定差子序列](https://leetcode.cn/problems/longest-arithmetic-subsequence-of-given-difference){#1218}

{{< tabs "1218" >}}

{{% tab "python" %}}
```python
class Solution:
    def longestSubsequence(self, arr: List[int], difference: int) -> int:
        f = defaultdict(int)
        for x in arr:
            f[x] = f[x - difference] + 1
        return max(f.values())
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int longestSubsequence(int[] arr, int difference) {
        Map<Integer, Integer> f = new HashMap<>();
        int ans = 0;
        for (int x : arr) {
            f.put(x, f.getOrDefault(x - difference, 0) + 1);
            ans = Math.max(ans, f.get(x));
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
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> f;
        int ans = 0;
        for (int x : arr) {
            f[x] = f[x - difference] + 1;
            ans = max(ans, f[x]);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func longestSubsequence(arr []int, difference int) (ans int) {
	f := map[int]int{}
	for _, x := range arr {
		f[x] = f[x-difference] + 1
		ans = max(ans, f[x])
	}
	return
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashMap;

impl Solution {
    pub fn longest_subsequence(arr: Vec<i32>, difference: i32) -> i32 {
        let mut f = HashMap::new();
        let mut ans = 0;
        for &x in &arr {
            let count = f.get(&(x - difference)).unwrap_or(&0) + 1;
            f.insert(x, count);
            ans = ans.max(count);
        }
        ans
    }
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function longestSubsequence(arr: number[], difference: number): number {
    const f: Map<number, number> = new Map();
    for (const x of arr) {
        f.set(x, (f.get(x - difference) ?? 0) + 1);
    }
    return Math.max(...f.values());
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} arr
 * @param {number} difference
 * @return {number}
 */
var longestSubsequence = function (arr, difference) {
    const f = new Map();
    for (const x of arr) {
        f.set(x, (f.get(x - difference) || 0) + 1);
    }
    return Math.max(...f.values());
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>arr</code> 和一个整数 <code>difference</code>，请你找出并返回 <code>arr</code> 中最长等差子序列的长度，该子序列中相邻元素之间的差等于 <code>difference</code> 。</p>

<p><strong>子序列</strong> 是指在不改变其余元素顺序的情况下，通过删除一些元素或不删除任何元素而从 <code>arr</code> 派生出来的序列。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>arr = [1,2,3,4], difference = 1
<strong>输出：</strong>4
<strong>解释：</strong>最长的等差子序列是 [1,2,3,4]。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>arr = [1,3,5,7], difference = 1
<strong>输出：</strong>1
<strong>解释：</strong>最长的等差子序列是任意单个元素。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>arr = [1,5,7,8,5,3,4,2,1], difference = -2
<strong>输出：</strong>4
<strong>解释：</strong>最长的等差子序列是 [7,5,3,1]。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= arr.length <= 10<sup>5</sup></code></li>
	<li><code>-10<sup>4</sup> <= arr[i], difference <= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们可以使用哈希表 $f$ 来存储以 $x$ 结尾的最长等差子序列的长度。

遍历数组 $\textit{arr}$，对于每个元素 $x$，我们更新 $f[x]$ 为 $f[x - \textit{difference}] + 1$。

遍历结束后，我们返回 $f$ 中的最大值作为答案返回即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $\textit{arr}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def longestSubsequence(self, arr: List[int], difference: int) -> int:
        f = defaultdict(int)
        for x in arr:
            f[x] = f[x - difference] + 1
        return max(f.values())
```

#### Java

```java
class Solution {
    public int longestSubsequence(int[] arr, int difference) {
        Map<Integer, Integer> f = new HashMap<>();
        int ans = 0;
        for (int x : arr) {
            f.put(x, f.getOrDefault(x - difference, 0) + 1);
            ans = Math.max(ans, f.get(x));
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> f;
        int ans = 0;
        for (int x : arr) {
            f[x] = f[x - difference] + 1;
            ans = max(ans, f[x]);
        }
        return ans;
    }
};
```

#### Go

```go
func longestSubsequence(arr []int, difference int) (ans int) {
	f := map[int]int{}
	for _, x := range arr {
		f[x] = f[x-difference] + 1
		ans = max(ans, f[x])
	}
	return
}
```

#### Rust

```rust
use std::collections::HashMap;

impl Solution {
    pub fn longest_subsequence(arr: Vec<i32>, difference: i32) -> i32 {
        let mut f = HashMap::new();
        let mut ans = 0;
        for &x in &arr {
            let count = f.get(&(x - difference)).unwrap_or(&0) + 1;
            f.insert(x, count);
            ans = ans.max(count);
        }
        ans
    }
}
```

#### TypeScript

```ts
function longestSubsequence(arr: number[], difference: number): number {
    const f: Map<number, number> = new Map();
    for (const x of arr) {
        f.set(x, (f.get(x - difference) ?? 0) + 1);
    }
    return Math.max(...f.values());
}
```

#### JavaScript

```js
/**
 * @param {number[]} arr
 * @param {number} difference
 * @return {number}
 */
var longestSubsequence = function (arr, difference) {
    const f = new Map();
    for (const x of arr) {
        f.set(x, (f.get(x - difference) || 0) + 1);
    }
    return Math.max(...f.values());
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1219. 黄金矿工](https://leetcode.cn/problems/path-with-maximum-gold){#1219}

{{< tabs "1219" >}}

{{% tab "python" %}}
```python
class Solution:
    def getMaximumGold(self, grid: List[List[int]]) -> int:
        def dfs(i: int, j: int) -> int:
            if not (0 <= i < m and 0 <= j < n and grid[i][j]):
                return 0
            v = grid[i][j]
            grid[i][j] = 0
            ans = max(dfs(i + a, j + b) for a, b in pairwise(dirs)) + v
            grid[i][j] = v
            return ans

        m, n = len(grid), len(grid[0])
        dirs = (-1, 0, 1, 0, -1)
        return max(dfs(i, j) for i in range(m) for j in range(n))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private final int[] dirs = {-1, 0, 1, 0, -1};
    private int[][] grid;
    private int m;
    private int n;

    public int getMaximumGold(int[][] grid) {
        m = grid.length;
        n = grid[0].length;
        this.grid = grid;
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans = Math.max(ans, dfs(i, j));
            }
        }
        return ans;
    }

    private int dfs(int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
            return 0;
        }
        int v = grid[i][j];
        grid[i][j] = 0;
        int ans = 0;
        for (int k = 0; k < 4; ++k) {
            ans = Math.max(ans, v + dfs(i + dirs[k], j + dirs[k + 1]));
        }
        grid[i][j] = v;
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        function<int(int, int)> dfs = [&](int i, int j) {
            if (i < 0 || i >= m || j < 0 || j >= n || !grid[i][j]) {
                return 0;
            }
            int v = grid[i][j];
            grid[i][j] = 0;
            int ans = v + max({dfs(i - 1, j), dfs(i + 1, j), dfs(i, j - 1), dfs(i, j + 1)});
            grid[i][j] = v;
            return ans;
        };
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans = max(ans, dfs(i, j));
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func getMaximumGold(grid [][]int) (ans int) {
	m, n := len(grid), len(grid[0])
	var dfs func(i, j int) int
	dfs = func(i, j int) int {
		if i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0 {
			return 0
		}
		v := grid[i][j]
		grid[i][j] = 0
		ans := 0
		dirs := []int{-1, 0, 1, 0, -1}
		for k := 0; k < 4; k++ {
			ans = max(ans, v+dfs(i+dirs[k], j+dirs[k+1]))
		}
		grid[i][j] = v
		return ans
	}
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			ans = max(ans, dfs(i, j))
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function getMaximumGold(grid: number[][]): number {
    const m = grid.length;
    const n = grid[0].length;
    const dfs = (i: number, j: number): number => {
        if (i < 0 || i >= m || j < 0 || j >= n || !grid[i][j]) {
            return 0;
        }
        const v = grid[i][j];
        grid[i][j] = 0;
        let ans = v + Math.max(dfs(i - 1, j), dfs(i + 1, j), dfs(i, j - 1), dfs(i, j + 1));
        grid[i][j] = v;
        return ans;
    };
    let ans = 0;
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            ans = Math.max(ans, dfs(i, j));
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[][]} grid
 * @return {number}
 */
var getMaximumGold = function (grid) {
    const m = grid.length;
    const n = grid[0].length;
    const dfs = (i, j) => {
        if (i < 0 || i >= m || j < 0 || j >= n || !grid[i][j]) {
            return 0;
        }
        const v = grid[i][j];
        grid[i][j] = 0;
        let ans = v + Math.max(dfs(i - 1, j), dfs(i + 1, j), dfs(i, j - 1), dfs(i, j + 1));
        grid[i][j] = v;
        return ans;
    };
    let ans = 0;
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            ans = Math.max(ans, dfs(i, j));
        }
    }
    return ans;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你要开发一座金矿，地质勘测学家已经探明了这座金矿中的资源分布，并用大小为&nbsp;<code>m * n</code> 的网格 <code>grid</code> 进行了标注。每个单元格中的整数就表示这一单元格中的黄金数量；如果该单元格是空的，那么就是 <code>0</code>。</p>

<p>为了使收益最大化，矿工需要按以下规则来开采黄金：</p>

<ul>
	<li>每当矿工进入一个单元，就会收集该单元格中的所有黄金。</li>
	<li>矿工每次可以从当前位置向上下左右四个方向走。</li>
	<li>每个单元格只能被开采（进入）一次。</li>
	<li><strong>不得开采</strong>（进入）黄金数目为 <code>0</code> 的单元格。</li>
	<li>矿工可以从网格中 <strong>任意一个</strong> 有黄金的单元格出发或者是停止。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>grid = [[0,6,0],[5,8,7],[0,9,0]]
<strong>输出：</strong>24
<strong>解释：</strong>
[[0,6,0],
 [5,8,7],
 [0,9,0]]
一种收集最多黄金的路线是：9 -&gt; 8 -&gt; 7。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>grid = [[1,0,7],[2,0,6],[3,4,5],[0,3,0],[9,0,20]]
<strong>输出：</strong>28
<strong>解释：</strong>
[[1,0,7],
 [2,0,6],
 [3,4,5],
 [0,3,0],
 [9,0,20]]
一种收集最多黄金的路线是：1 -&gt; 2 -&gt; 3 -&gt; 4 -&gt; 5 -&gt; 6 -&gt; 7。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= grid.length,&nbsp;grid[i].length &lt;= 15</code></li>
	<li><code>0 &lt;= grid[i][j] &lt;= 100</code></li>
	<li>最多 <strong>25 </strong>个单元格中有黄金。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS

我们可以枚举每个格子作为起点，然后从起点开始进行深度优先搜索。在搜索的过程中，每遇到一个非零的格子，就将其变成零，并继续搜索。当无法继续搜索时，计算当前的路径的黄金总数，然后将当前的格子变回非零的格子，从而进行回溯。

时间复杂度 $O(m \times n \times 3^k)$，其中 $k$ 是每条路径的最大长度。由于每个格子最多只能被访问一次，因此时间复杂度不会超过 $O(m \times n \times 3^k)$。空间复杂度 $O(m \times n)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def getMaximumGold(self, grid: List[List[int]]) -> int:
        def dfs(i: int, j: int) -> int:
            if not (0 <= i < m and 0 <= j < n and grid[i][j]):
                return 0
            v = grid[i][j]
            grid[i][j] = 0
            ans = max(dfs(i + a, j + b) for a, b in pairwise(dirs)) + v
            grid[i][j] = v
            return ans

        m, n = len(grid), len(grid[0])
        dirs = (-1, 0, 1, 0, -1)
        return max(dfs(i, j) for i in range(m) for j in range(n))
```

#### Java

```java
class Solution {
    private final int[] dirs = {-1, 0, 1, 0, -1};
    private int[][] grid;
    private int m;
    private int n;

    public int getMaximumGold(int[][] grid) {
        m = grid.length;
        n = grid[0].length;
        this.grid = grid;
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans = Math.max(ans, dfs(i, j));
            }
        }
        return ans;
    }

    private int dfs(int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
            return 0;
        }
        int v = grid[i][j];
        grid[i][j] = 0;
        int ans = 0;
        for (int k = 0; k < 4; ++k) {
            ans = Math.max(ans, v + dfs(i + dirs[k], j + dirs[k + 1]));
        }
        grid[i][j] = v;
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        function<int(int, int)> dfs = [&](int i, int j) {
            if (i < 0 || i >= m || j < 0 || j >= n || !grid[i][j]) {
                return 0;
            }
            int v = grid[i][j];
            grid[i][j] = 0;
            int ans = v + max({dfs(i - 1, j), dfs(i + 1, j), dfs(i, j - 1), dfs(i, j + 1)});
            grid[i][j] = v;
            return ans;
        };
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans = max(ans, dfs(i, j));
            }
        }
        return ans;
    }
};
```

#### Go

```go
func getMaximumGold(grid [][]int) (ans int) {
	m, n := len(grid), len(grid[0])
	var dfs func(i, j int) int
	dfs = func(i, j int) int {
		if i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0 {
			return 0
		}
		v := grid[i][j]
		grid[i][j] = 0
		ans := 0
		dirs := []int{-1, 0, 1, 0, -1}
		for k := 0; k < 4; k++ {
			ans = max(ans, v+dfs(i+dirs[k], j+dirs[k+1]))
		}
		grid[i][j] = v
		return ans
	}
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			ans = max(ans, dfs(i, j))
		}
	}
	return
}
```

#### TypeScript

```ts
function getMaximumGold(grid: number[][]): number {
    const m = grid.length;
    const n = grid[0].length;
    const dfs = (i: number, j: number): number => {
        if (i < 0 || i >= m || j < 0 || j >= n || !grid[i][j]) {
            return 0;
        }
        const v = grid[i][j];
        grid[i][j] = 0;
        let ans = v + Math.max(dfs(i - 1, j), dfs(i + 1, j), dfs(i, j - 1), dfs(i, j + 1));
        grid[i][j] = v;
        return ans;
    };
    let ans = 0;
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            ans = Math.max(ans, dfs(i, j));
        }
    }
    return ans;
}
```

#### JavaScript

```js
/**
 * @param {number[][]} grid
 * @return {number}
 */
var getMaximumGold = function (grid) {
    const m = grid.length;
    const n = grid[0].length;
    const dfs = (i, j) => {
        if (i < 0 || i >= m || j < 0 || j >= n || !grid[i][j]) {
            return 0;
        }
        const v = grid[i][j];
        grid[i][j] = 0;
        let ans = v + Math.max(dfs(i - 1, j), dfs(i + 1, j), dfs(i, j - 1), dfs(i, j + 1));
        grid[i][j] = v;
        return ans;
    };
    let ans = 0;
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            ans = Math.max(ans, dfs(i, j));
        }
    }
    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
