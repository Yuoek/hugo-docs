---
title: "1970_你能穿过矩阵的最后一天"
date: 2025-10-08T18:38:49+08:00
weight: 8
tags: [二分查找, 二叉树, 动态规划, 后缀数组, 图, 字符串, 并查集, 广度优先搜索, 拓扑排序, 数学, 数据库, 数组, 数论, 最短路, 树, 深度优先搜索, 矩阵, 贪心]
---

{{< markmap >}}
### [1970_你能穿过矩阵的最后一天](#1970)
#### [深度优先搜索](#1970)
#### [广度优先搜索](#1970)
#### [并查集](#1970)
#### [数组](#1970)
#### [二分查找](#1970)
#### [矩阵](#1970)
### [1971_寻找图中是否存在路径](#1971)
#### [深度优先搜索](#1971)
#### [广度优先搜索](#1971)
#### [并查集](#1971)
#### [图](#1971)
### [1972_同一天的第一个电话和最后一个电话 🔒](#1972)
#### [数据库](#1972)
### [1973_值等于子节点值之和的节点数量 🔒](#1973)
#### [树](#1973)
#### [深度优先搜索](#1973)
#### [二叉树](#1973)
### [1974_使用特殊打字机键入单词的最少时间](#1974)
#### [贪心](#1974)
#### [字符串](#1974)
### [1975_最大方阵和](#1975)
#### [贪心](#1975)
#### [数组](#1975)
#### [矩阵](#1975)
### [1976_到达目的地的方案数](#1976)
#### [图](#1976)
#### [拓扑排序](#1976)
#### [动态规划](#1976)
#### [最短路](#1976)
### [1977_划分数字的方案数](#1977)
#### [字符串](#1977)
#### [动态规划](#1977)
#### [后缀数组](#1977)
### [1978_上级经理已离职的公司员工](#1978)
#### [数据库](#1978)
### [1979_找出数组的最大公约数](#1979)
#### [数组](#1979)
#### [数学](#1979)
#### [数论](#1979)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1970_你能穿过矩阵的最后一天
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 并查集
___
#### 数组
___
#### 二分查找
___
#### 矩阵
---
### 1971_寻找图中是否存在路径
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 并查集
___
#### 图
---
### 1972_同一天的第一个电话和最后一个电话 🔒
___
#### 数据库
---
### 1973_值等于子节点值之和的节点数量 🔒
___
#### 树
___
#### 深度优先搜索
___
#### 二叉树
---
### 1974_使用特殊打字机键入单词的最少时间
___
#### 贪心
___
#### 字符串
---
### 1975_最大方阵和
___
#### 贪心
___
#### 数组
___
#### 矩阵
---
### 1976_到达目的地的方案数
___
#### 图
___
#### 拓扑排序
___
#### 动态规划
___
#### 最短路
---
### 1977_划分数字的方案数
___
#### 字符串
___
#### 动态规划
___
#### 后缀数组
---
### 1978_上级经理已离职的公司员工
___
#### 数据库
---
### 1979_找出数组的最大公约数
___
#### 数组
___
#### 数学
___
#### 数论
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 二叉树 | 动态规划 |
| 后缀数组 | 图 | 字符串 |
| 并查集 | 广度优先搜索 | 拓扑排序 |
| 数学 | 数据库 | 数组 |
| 数论 | 最短路 | 树 |
| 深度优先搜索 | 矩阵 | 贪心 |

# [1970. 你能穿过矩阵的最后一天](https://leetcode.cn/problems/last-day-where-you-can-still-cross){#1970}

{{< tabs "1970" >}}

{{% tab "python" %}}
```python
class UnionFind:
    def __init__(self, n):
        self.p = list(range(n))
        self.size = [1] * n

    def find(self, x):
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]

    def union(self, a, b):
        pa, pb = self.find(a), self.find(b)
        if pa == pb:
            return False
        if self.size[pa] > self.size[pb]:
            self.p[pb] = pa
            self.size[pa] += self.size[pb]
        else:
            self.p[pa] = pb
            self.size[pb] += self.size[pa]
        return True


class Solution:
    def latestDayToCross(self, row: int, col: int, cells: List[List[int]]) -> int:
        mn = len(cells)
        uf = UnionFind(mn + 2)
        s, t = mn, mn + 1
        dirs = (-1, 0, 1, 0, -1)
        g = [[1] * col for _ in range(row)]
        for i in range(mn - 1, -1, -1):
            x, y = cells[i][0] - 1, cells[i][1] - 1
            g[x][y] = 0
            for a, b in pairwise(dirs):
                nx, ny = x + a, y + b
                if 0 <= nx < row and 0 <= ny < col and g[nx][ny] == 0:
                    uf.union(x * col + y, nx * col + ny)
            if x == 0:
                uf.union(y, s)
            if x == row - 1:
                uf.union(x * col + y, t)
            if uf.find(s) == uf.find(t):
                return i
```
{{% /tab %}}
{{% tab "java" %}}
```java
class UnionFind {
    private final int[] p;
    private final int[] size;

    public UnionFind(int n) {
        p = new int[n];
        size = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
            size[i] = 1;
        }
    }

    public int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    public boolean union(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) {
            return false;
        }
        if (size[pa] > size[pb]) {
            p[pb] = pa;
            size[pa] += size[pb];
        } else {
            p[pa] = pb;
            size[pb] += size[pa];
        }
        return true;
    }
}

class Solution {
    public int latestDayToCross(int row, int col, int[][] cells) {
        int mn = cells.length;
        UnionFind uf = new UnionFind(mn + 2);
        int s = mn, t = mn + 1;
        int[][] g = new int[row][col];
        for (var e : g) {
            Arrays.fill(e, 1);
        }
        final int[] dirs = {-1, 0, 1, 0, -1};
        for (int i = mn - 1;; --i) {
            int x = cells[i][0] - 1, y = cells[i][1] - 1;
            g[x][y] = 0;
            for (int j = 0; j < 4; ++j) {
                int nx = x + dirs[j], ny = y + dirs[j + 1];
                if (nx >= 0 && nx < row && ny >= 0 && ny < col && g[nx][ny] == 0) {
                    uf.union(x * col + y, nx * col + ny);
                }
            }
            if (x == 0) {
                uf.union(s, x * col + y);
            }
            if (x == row - 1) {
                uf.union(t, x * col + y);
            }
            if (uf.find(s) == uf.find(t)) {
                return i;
            }
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class UnionFind {
public:
    UnionFind(int n) {
        p = vector<int>(n);
        size = vector<int>(n, 1);
        iota(p.begin(), p.end(), 0);
    }

    bool unite(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) {
            return false;
        }
        if (size[pa] > size[pb]) {
            p[pb] = pa;
            size[pa] += size[pb];
        } else {
            p[pa] = pb;
            size[pb] += size[pa];
        }
        return true;
    }

    int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

private:
    vector<int> p, size;
};

class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int mn = cells.size();
        UnionFind uf(mn + 2);
        int s = mn, t = mn + 1;
        vector<vector<int>> g(row, vector<int>(col, 1));
        const int dirs[5] = {0, 1, 0, -1, 0};
        for (int i = mn - 1;; --i) {
            int x = cells[i][0] - 1, y = cells[i][1] - 1;
            g[x][y] = 0;
            for (int j = 0; j < 4; ++j) {
                int nx = x + dirs[j], ny = y + dirs[j + 1];
                if (nx >= 0 && nx < row && ny >= 0 && ny < col && g[nx][ny] == 0) {
                    uf.unite(x * col + y, nx * col + ny);
                }
            }
            if (x == 0) {
                uf.unite(s, x * col + y);
            }
            if (x == row - 1) {
                uf.unite(t, x * col + y);
            }
            if (uf.find(s) == uf.find(t)) {
                return i;
            }
        }
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
type unionFind struct {
	p, size []int
}

func newUnionFind(n int) *unionFind {
	p := make([]int, n)
	size := make([]int, n)
	for i := range p {
		p[i] = i
		size[i] = 1
	}
	return &unionFind{p, size}
}

func (uf *unionFind) find(x int) int {
	if uf.p[x] != x {
		uf.p[x] = uf.find(uf.p[x])
	}
	return uf.p[x]
}

func (uf *unionFind) union(a, b int) bool {
	pa, pb := uf.find(a), uf.find(b)
	if pa == pb {
		return false
	}
	if uf.size[pa] > uf.size[pb] {
		uf.p[pb] = pa
		uf.size[pa] += uf.size[pb]
	} else {
		uf.p[pa] = pb
		uf.size[pb] += uf.size[pa]
	}
	return true
}

func latestDayToCross(row int, col int, cells [][]int) int {
	mn := len(cells)
	uf := newUnionFind(mn + 2)
	s, t := mn, mn+1
	g := make([][]int, row)
	for i := range g {
		g[i] = make([]int, col)
		for j := range g[i] {
			g[i][j] = 1
		}
	}
	dirs := [5]int{-1, 0, 1, 0, -1}
	for i := mn - 1; ; i-- {
		x, y := cells[i][0]-1, cells[i][1]-1
		g[x][y] = 0
		for j := 0; j < 4; j++ {
			nx, ny := x+dirs[j], y+dirs[j+1]
			if nx >= 0 && nx < row && ny >= 0 && ny < col && g[nx][ny] == 0 {
				uf.union(x*col+y, nx*col+ny)
			}
		}
		if x == 0 {
			uf.union(s, x*col+y)
		}
		if x == row-1 {
			uf.union(t, x*col+y)
		}
		if uf.find(s) == uf.find(t) {
			return i
		}
	}
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class UnionFind {
    p: number[];
    size: number[];
    constructor(n: number) {
        this.p = Array(n)
            .fill(0)
            .map((_, i) => i);
        this.size = Array(n).fill(1);
    }

    find(x: number): number {
        if (this.p[x] !== x) {
            this.p[x] = this.find(this.p[x]);
        }
        return this.p[x];
    }

    union(a: number, b: number): boolean {
        const [pa, pb] = [this.find(a), this.find(b)];
        if (pa === pb) {
            return false;
        }
        if (this.size[pa] > this.size[pb]) {
            this.p[pb] = pa;
            this.size[pa] += this.size[pb];
        } else {
            this.p[pa] = pb;
            this.size[pb] += this.size[pa];
        }
        return true;
    }
}

function latestDayToCross(row: number, col: number, cells: number[][]): number {
    const mn = cells.length;
    const uf = new UnionFind(row * col + 2);
    const [s, t] = [mn, mn + 1];
    const g: number[][] = Array.from({ length: row }, () => Array(col).fill(1));
    const dirs: number[] = [-1, 0, 1, 0, -1];
    for (let i = mn - 1; ; --i) {
        const [x, y] = [cells[i][0] - 1, cells[i][1] - 1];
        g[x][y] = 0;
        for (let j = 0; j < 4; ++j) {
            const [nx, ny] = [x + dirs[j], y + dirs[j + 1]];
            if (nx >= 0 && nx < row && ny >= 0 && ny < col && g[nx][ny] === 0) {
                uf.union(x * col + y, nx * col + ny);
            }
        }
        if (x === 0) {
            uf.union(s, y);
        }
        if (x === row - 1) {
            uf.union(t, x * col + y);
        }
        if (uf.find(s) === uf.find(t)) {
            return i;
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

<p>给你一个下标从 <strong>1</strong>&nbsp;开始的二进制矩阵，其中&nbsp;<code>0</code>&nbsp;表示陆地，<code>1</code>&nbsp;表示水域。同时给你&nbsp;<code>row</code> 和&nbsp;<code>col</code>&nbsp;分别表示矩阵中行和列的数目。</p>

<p>一开始在第&nbsp;<code>0</code>&nbsp;天，<strong>整个</strong>&nbsp;矩阵都是&nbsp;<strong>陆地</strong>&nbsp;。但每一天都会有一块新陆地被&nbsp;<strong>水</strong>&nbsp;淹没变成水域。给你一个下标从&nbsp;<strong>1</strong>&nbsp;开始的二维数组&nbsp;<code>cells</code>&nbsp;，其中&nbsp;<code>cells[i] = [r<sub>i</sub>, c<sub>i</sub>]</code>&nbsp;表示在第&nbsp;<code>i</code>&nbsp;天，第&nbsp;<code>r<sub>i</sub></code>&nbsp;行&nbsp;<code>c<sub>i</sub></code>&nbsp;列（下标都是从 <strong>1</strong>&nbsp;开始）的陆地会变成 <strong>水域</strong>&nbsp;（也就是 <code>0</code>&nbsp;变成 <code>1</code>&nbsp;）。</p>

<p>你想知道从矩阵最 <strong>上面</strong>&nbsp;一行走到最 <strong>下面</strong>&nbsp;一行，且只经过陆地格子的 <strong>最后一天</strong>&nbsp;是哪一天。你可以从最上面一行的&nbsp;<strong>任意</strong>&nbsp;格子出发，到达最下面一行的&nbsp;<strong>任意</strong>&nbsp;格子。你只能沿着&nbsp;<strong>四个</strong>&nbsp;基本方向移动（也就是上下左右）。</p>

<p>请返回只经过陆地格子能从最 <strong>上面</strong>&nbsp;一行走到最 <strong>下面</strong>&nbsp;一行的 <strong>最后一天</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1900-1999/1970.Last%20Day%20Where%20You%20Can%20Still%20Cross/images/1.png" style="width: 624px; height: 162px;">
<pre><b>输入：</b>row = 2, col = 2, cells = [[1,1],[2,1],[1,2],[2,2]]
<b>输出：</b>2
<b>解释：</b>上图描述了矩阵从第 0 天开始是如何变化的。
可以从最上面一行到最下面一行的最后一天是第 2 天。
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1900-1999/1970.Last%20Day%20Where%20You%20Can%20Still%20Cross/images/2.png" style="width: 504px; height: 178px;">
<pre><b>输入：</b>row = 2, col = 2, cells = [[1,1],[1,2],[2,1],[2,2]]
<b>输出：</b>1
<b>解释：</b>上图描述了矩阵从第 0 天开始是如何变化的。
可以从最上面一行到最下面一行的最后一天是第 1 天。
</pre>

<p><strong>示例 3：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1900-1999/1970.Last%20Day%20Where%20You%20Can%20Still%20Cross/images/3.png" style="width: 666px; height: 167px;">
<pre><b>输入：</b>row = 3, col = 3, cells = [[1,2],[2,1],[3,3],[2,2],[1,1],[1,3],[2,3],[3,2],[3,1]]
<b>输出：</b>3
<b>解释：</b>上图描述了矩阵从第 0 天开始是如何变化的。
可以从最上面一行到最下面一行的最后一天是第 3 天。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= row, col &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>4 &lt;= row * col &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>cells.length == row * col</code></li>
	<li><code>1 &lt;= r<sub>i</sub> &lt;= row</code></li>
	<li><code>1 &lt;= c<sub>i</sub> &lt;= col</code></li>
	<li><code>cells</code>&nbsp;中的所有格子坐标都是 <strong>唯一</strong>&nbsp;的。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二分查找 + BFS

我们注意到，如果我们能在第 $k$ 天从最上面一行走到最下面一行，那么对于任意 $0 \lt k' \lt k$，我们也能在第 $k'$ 天从最上面一行走到最下面一行。这存在着单调性，因此，我们可以使用二分查找，找到最大的 $k$，使得我们能在第 $k$ 天从最上面一行走到最下面一行。

我们定义二分查找的左边界 $l = 1$，右边界 $r = |cells|$，其中 $|cells|$ 表示数组 $cells$ 的长度。然后，我们二分枚举 $k$，对于每一个 $k$，我们取 $\textit{cells}$ 的前 $k$ 个元素，将这些元素对应的格子变成水域，然后使用广度优先搜索，从最上面一行开始，尝试走到最下面一行。如果我们能走到最下面一行，那么说明我们可以在第 $k$ 天从最上面一行走到最下面一行，我们就将左边界 $l$ 更新为 $k$，否则，我们将右边界 $r$ 更新为 $k - 1$。

时间复杂度 $O(m \times n \times \log (m \times n))$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别表示矩阵的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def latestDayToCross(self, row: int, col: int, cells: List[List[int]]) -> int:
        def check(k: int) -> bool:
            g = [[0] * col for _ in range(row)]
            for i, j in cells[:k]:
                g[i - 1][j - 1] = 1
            q = [(0, j) for j in range(col) if g[0][j] == 0]
            for x, y in q:
                if x == row - 1:
                    return True
                for a, b in pairwise(dirs):
                    nx, ny = x + a, y + b
                    if 0 <= nx < row and 0 <= ny < col and g[nx][ny] == 0:
                        q.append((nx, ny))
                        g[nx][ny] = 1
            return False

        n = row * col
        l, r = 1, n
        dirs = (-1, 0, 1, 0, -1)
        while l < r:
            mid = (l + r + 1) >> 1
            if check(mid):
                l = mid
            else:
                r = mid - 1
        return l
```

#### Java

```java
class Solution {
    private int[][] cells;
    private int m;
    private int n;

    public int latestDayToCross(int row, int col, int[][] cells) {
        int l = 1, r = cells.length;
        this.cells = cells;
        this.m = row;
        this.n = col;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (check(mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }

    private boolean check(int k) {
        int[][] g = new int[m][n];
        for (int i = 0; i < k; i++) {
            g[cells[i][0] - 1][cells[i][1] - 1] = 1;
        }
        final int[] dirs = {-1, 0, 1, 0, -1};
        Deque<int[]> q = new ArrayDeque<>();
        for (int j = 0; j < n; j++) {
            if (g[0][j] == 0) {
                q.offer(new int[] {0, j});
                g[0][j] = 1;
            }
        }
        while (!q.isEmpty()) {
            int[] p = q.poll();
            int x = p[0], y = p[1];
            if (x == m - 1) {
                return true;
            }
            for (int i = 0; i < 4; i++) {
                int nx = x + dirs[i], ny = y + dirs[i + 1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && g[nx][ny] == 0) {
                    q.offer(new int[] {nx, ny});
                    g[nx][ny] = 1;
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
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int l = 1, r = cells.size();
        int g[row][col];
        int dirs[5] = {0, 1, 0, -1, 0};
        auto check = [&](int k) -> bool {
            memset(g, 0, sizeof(g));
            for (int i = 0; i < k; ++i) {
                g[cells[i][0] - 1][cells[i][1] - 1] = 1;
            }
            queue<pair<int, int>> q;
            for (int j = 0; j < col; ++j) {
                if (g[0][j] == 0) {
                    q.emplace(0, j);
                    g[0][j] = 1;
                }
            }
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                if (x == row - 1) {
                    return true;
                }
                for (int i = 0; i < 4; ++i) {
                    int nx = x + dirs[i];
                    int ny = y + dirs[i + 1];
                    if (nx >= 0 && nx < row && ny >= 0 && ny < col && g[nx][ny] == 0) {
                        q.emplace(nx, ny);
                        g[nx][ny] = 1;
                    }
                }
            }
            return false;
        };
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (check(mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};
```

#### Go

```go
func latestDayToCross(row int, col int, cells [][]int) int {
	l, r := 1, len(cells)
	dirs := [5]int{-1, 0, 1, 0, -1}
	check := func(k int) bool {
		g := make([][]int, row)
		for i := range g {
			g[i] = make([]int, col)
		}
		for i := 0; i < k; i++ {
			g[cells[i][0]-1][cells[i][1]-1] = 1
		}
		q := [][2]int{}
		for j := 0; j < col; j++ {
			if g[0][j] == 0 {
				g[0][j] = 1
				q = append(q, [2]int{0, j})
			}
		}
		for len(q) > 0 {
			x, y := q[0][0], q[0][1]
			q = q[1:]
			if x == row-1 {
				return true
			}
			for i := 0; i < 4; i++ {
				nx, ny := x+dirs[i], y+dirs[i+1]
				if nx >= 0 && nx < row && ny >= 0 && ny < col && g[nx][ny] == 0 {
					g[nx][ny] = 1
					q = append(q, [2]int{nx, ny})
				}
			}
		}
		return false
	}
	for l < r {
		mid := (l + r + 1) >> 1
		if check(mid) {
			l = mid
		} else {
			r = mid - 1
		}
	}
	return l
}
```

#### TypeScript

```ts
function latestDayToCross(row: number, col: number, cells: number[][]): number {
    let [l, r] = [1, cells.length];
    const check = (k: number): boolean => {
        const g: number[][] = Array.from({ length: row }, () => Array(col).fill(0));
        for (let i = 0; i < k; ++i) {
            const [x, y] = cells[i];
            g[x - 1][y - 1] = 1;
        }
        const q: number[][] = [];
        for (let j = 0; j < col; ++j) {
            if (g[0][j] === 0) {
                q.push([0, j]);
                g[0][j] = 1;
            }
        }
        const dirs: number[] = [-1, 0, 1, 0, -1];
        for (const [x, y] of q) {
            if (x === row - 1) {
                return true;
            }
            for (let i = 0; i < 4; ++i) {
                const nx = x + dirs[i];
                const ny = y + dirs[i + 1];
                if (nx >= 0 && nx < row && ny >= 0 && ny < col && g[nx][ny] === 0) {
                    q.push([nx, ny]);
                    g[nx][ny] = 1;
                }
            }
        }
        return false;
    };
    while (l < r) {
        const mid = (l + r + 1) >> 1;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return l;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：并查集

我们可以先将所有的陆地格子初始化为 $1$，然后倒序遍历数组 $\textit{cells}$，将每个格子对应的陆地格子变成 $0$，并将其与上下左右的陆地格子合并。我们还需要维护两个虚拟节点 $s$ 和 $t$，分别表示最上面一行和最下面一行的虚拟节点。如果 $s$ 和 $t$ 在并查集中连通，那么说明我们可以在第 $i$ 天从最上面一行走到最下面一行。

时间复杂度 $O(m \times n \times \alpha(m \times n))$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别表示矩阵的行数和列数，而 $\alpha$ 表示 Ackermann 函数的反函数。

<!-- tabs:start -->

#### Python3

```python
class UnionFind:
    def __init__(self, n):
        self.p = list(range(n))
        self.size = [1] * n

    def find(self, x):
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]

    def union(self, a, b):
        pa, pb = self.find(a), self.find(b)
        if pa == pb:
            return False
        if self.size[pa] > self.size[pb]:
            self.p[pb] = pa
            self.size[pa] += self.size[pb]
        else:
            self.p[pa] = pb
            self.size[pb] += self.size[pa]
        return True


class Solution:
    def latestDayToCross(self, row: int, col: int, cells: List[List[int]]) -> int:
        mn = len(cells)
        uf = UnionFind(mn + 2)
        s, t = mn, mn + 1
        dirs = (-1, 0, 1, 0, -1)
        g = [[1] * col for _ in range(row)]
        for i in range(mn - 1, -1, -1):
            x, y = cells[i][0] - 1, cells[i][1] - 1
            g[x][y] = 0
            for a, b in pairwise(dirs):
                nx, ny = x + a, y + b
                if 0 <= nx < row and 0 <= ny < col and g[nx][ny] == 0:
                    uf.union(x * col + y, nx * col + ny)
            if x == 0:
                uf.union(y, s)
            if x == row - 1:
                uf.union(x * col + y, t)
            if uf.find(s) == uf.find(t):
                return i
```

#### Java

```java
class UnionFind {
    private final int[] p;
    private final int[] size;

    public UnionFind(int n) {
        p = new int[n];
        size = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
            size[i] = 1;
        }
    }

    public int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    public boolean union(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) {
            return false;
        }
        if (size[pa] > size[pb]) {
            p[pb] = pa;
            size[pa] += size[pb];
        } else {
            p[pa] = pb;
            size[pb] += size[pa];
        }
        return true;
    }
}

class Solution {
    public int latestDayToCross(int row, int col, int[][] cells) {
        int mn = cells.length;
        UnionFind uf = new UnionFind(mn + 2);
        int s = mn, t = mn + 1;
        int[][] g = new int[row][col];
        for (var e : g) {
            Arrays.fill(e, 1);
        }
        final int[] dirs = {-1, 0, 1, 0, -1};
        for (int i = mn - 1;; --i) {
            int x = cells[i][0] - 1, y = cells[i][1] - 1;
            g[x][y] = 0;
            for (int j = 0; j < 4; ++j) {
                int nx = x + dirs[j], ny = y + dirs[j + 1];
                if (nx >= 0 && nx < row && ny >= 0 && ny < col && g[nx][ny] == 0) {
                    uf.union(x * col + y, nx * col + ny);
                }
            }
            if (x == 0) {
                uf.union(s, x * col + y);
            }
            if (x == row - 1) {
                uf.union(t, x * col + y);
            }
            if (uf.find(s) == uf.find(t)) {
                return i;
            }
        }
    }
}
```

#### C++

```cpp
class UnionFind {
public:
    UnionFind(int n) {
        p = vector<int>(n);
        size = vector<int>(n, 1);
        iota(p.begin(), p.end(), 0);
    }

    bool unite(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) {
            return false;
        }
        if (size[pa] > size[pb]) {
            p[pb] = pa;
            size[pa] += size[pb];
        } else {
            p[pa] = pb;
            size[pb] += size[pa];
        }
        return true;
    }

    int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

private:
    vector<int> p, size;
};

class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int mn = cells.size();
        UnionFind uf(mn + 2);
        int s = mn, t = mn + 1;
        vector<vector<int>> g(row, vector<int>(col, 1));
        const int dirs[5] = {0, 1, 0, -1, 0};
        for (int i = mn - 1;; --i) {
            int x = cells[i][0] - 1, y = cells[i][1] - 1;
            g[x][y] = 0;
            for (int j = 0; j < 4; ++j) {
                int nx = x + dirs[j], ny = y + dirs[j + 1];
                if (nx >= 0 && nx < row && ny >= 0 && ny < col && g[nx][ny] == 0) {
                    uf.unite(x * col + y, nx * col + ny);
                }
            }
            if (x == 0) {
                uf.unite(s, x * col + y);
            }
            if (x == row - 1) {
                uf.unite(t, x * col + y);
            }
            if (uf.find(s) == uf.find(t)) {
                return i;
            }
        }
    }
};
```

#### Go

```go
type unionFind struct {
	p, size []int
}

func newUnionFind(n int) *unionFind {
	p := make([]int, n)
	size := make([]int, n)
	for i := range p {
		p[i] = i
		size[i] = 1
	}
	return &unionFind{p, size}
}

func (uf *unionFind) find(x int) int {
	if uf.p[x] != x {
		uf.p[x] = uf.find(uf.p[x])
	}
	return uf.p[x]
}

func (uf *unionFind) union(a, b int) bool {
	pa, pb := uf.find(a), uf.find(b)
	if pa == pb {
		return false
	}
	if uf.size[pa] > uf.size[pb] {
		uf.p[pb] = pa
		uf.size[pa] += uf.size[pb]
	} else {
		uf.p[pa] = pb
		uf.size[pb] += uf.size[pa]
	}
	return true
}

func latestDayToCross(row int, col int, cells [][]int) int {
	mn := len(cells)
	uf := newUnionFind(mn + 2)
	s, t := mn, mn+1
	g := make([][]int, row)
	for i := range g {
		g[i] = make([]int, col)
		for j := range g[i] {
			g[i][j] = 1
		}
	}
	dirs := [5]int{-1, 0, 1, 0, -1}
	for i := mn - 1; ; i-- {
		x, y := cells[i][0]-1, cells[i][1]-1
		g[x][y] = 0
		for j := 0; j < 4; j++ {
			nx, ny := x+dirs[j], y+dirs[j+1]
			if nx >= 0 && nx < row && ny >= 0 && ny < col && g[nx][ny] == 0 {
				uf.union(x*col+y, nx*col+ny)
			}
		}
		if x == 0 {
			uf.union(s, x*col+y)
		}
		if x == row-1 {
			uf.union(t, x*col+y)
		}
		if uf.find(s) == uf.find(t) {
			return i
		}
	}
}
```

#### TypeScript

```ts
class UnionFind {
    p: number[];
    size: number[];
    constructor(n: number) {
        this.p = Array(n)
            .fill(0)
            .map((_, i) => i);
        this.size = Array(n).fill(1);
    }

    find(x: number): number {
        if (this.p[x] !== x) {
            this.p[x] = this.find(this.p[x]);
        }
        return this.p[x];
    }

    union(a: number, b: number): boolean {
        const [pa, pb] = [this.find(a), this.find(b)];
        if (pa === pb) {
            return false;
        }
        if (this.size[pa] > this.size[pb]) {
            this.p[pb] = pa;
            this.size[pa] += this.size[pb];
        } else {
            this.p[pa] = pb;
            this.size[pb] += this.size[pa];
        }
        return true;
    }
}

function latestDayToCross(row: number, col: number, cells: number[][]): number {
    const mn = cells.length;
    const uf = new UnionFind(row * col + 2);
    const [s, t] = [mn, mn + 1];
    const g: number[][] = Array.from({ length: row }, () => Array(col).fill(1));
    const dirs: number[] = [-1, 0, 1, 0, -1];
    for (let i = mn - 1; ; --i) {
        const [x, y] = [cells[i][0] - 1, cells[i][1] - 1];
        g[x][y] = 0;
        for (let j = 0; j < 4; ++j) {
            const [nx, ny] = [x + dirs[j], y + dirs[j + 1]];
            if (nx >= 0 && nx < row && ny >= 0 && ny < col && g[nx][ny] === 0) {
                uf.union(x * col + y, nx * col + ny);
            }
        }
        if (x === 0) {
            uf.union(s, y);
        }
        if (x === row - 1) {
            uf.union(t, x * col + y);
        }
        if (uf.find(s) === uf.find(t)) {
            return i;
        }
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1971. 寻找图中是否存在路径](https://leetcode.cn/problems/find-if-path-exists-in-graph){#1971}

{{< tabs "1971" >}}

{{% tab "python" %}}
```python
class UnionFind:
    def __init__(self, n):
        self.p = list(range(n))
        self.size = [1] * n

    def find(self, x):
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]

    def union(self, a, b):
        pa, pb = self.find(a), self.find(b)
        if pa == pb:
            return False
        if self.size[pa] > self.size[pb]:
            self.p[pb] = pa
            self.size[pa] += self.size[pb]
        else:
            self.p[pa] = pb
            self.size[pb] += self.size[pa]
        return True


class Solution:
    def validPath(
        self, n: int, edges: List[List[int]], source: int, destination: int
    ) -> bool:
        uf = UnionFind(n)
        for u, v in edges:
            uf.union(u, v)
        return uf.find(source) == uf.find(destination)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class UnionFind {
    private int[] p;
    private int[] size;

    public UnionFind(int n) {
        p = new int[n];
        size = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
            size[i] = 1;
        }
    }

    public int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    public void union(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa != pb) {
            if (size[pa] > size[pb]) {
                p[pb] = pa;
                size[pa] += size[pb];
            } else {
                p[pa] = pb;
                size[pb] += size[pa];
            }
        }
    }
}

class Solution {
    public boolean validPath(int n, int[][] edges, int source, int destination) {
        UnionFind uf = new UnionFind(n);
        for (var e : edges) {
            uf.union(e[0], e[1]);
        }
        return uf.find(source) == uf.find(destination);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class UnionFind {
public:
    UnionFind(int n) {
        p = vector<int>(n);
        size = vector<int>(n, 1);
        iota(p.begin(), p.end(), 0);
    }

    void unite(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa != pb) {
            if (size[pa] > size[pb]) {
                p[pb] = pa;
                size[pa] += size[pb];
            } else {
                p[pa] = pb;
                size[pb] += size[pa];
            }
        }
    }

    int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

private:
    vector<int> p, size;
};

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        UnionFind uf(n);
        for (const auto& e : edges) {
            uf.unite(e[0], e[1]);
        }
        return uf.find(source) == uf.find(destination);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
type unionFind struct {
	p, size []int
}

func newUnionFind(n int) *unionFind {
	p := make([]int, n)
	size := make([]int, n)
	for i := range p {
		p[i] = i
		size[i] = 1
	}
	return &unionFind{p, size}
}

func (uf *unionFind) find(x int) int {
	if uf.p[x] != x {
		uf.p[x] = uf.find(uf.p[x])
	}
	return uf.p[x]
}

func (uf *unionFind) union(a, b int) bool {
	pa, pb := uf.find(a), uf.find(b)
	if pa == pb {
		return false
	}
	if uf.size[pa] > uf.size[pb] {
		uf.p[pb] = pa
		uf.size[pa] += uf.size[pb]
	} else {
		uf.p[pa] = pb
		uf.size[pb] += uf.size[pa]
	}
	return true
}

func validPath(n int, edges [][]int, source int, destination int) bool {
	uf := newUnionFind(n)
	for _, e := range edges {
		uf.union(e[0], e[1])
	}
	return uf.find(source) == uf.find(destination)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class UnionFind {
    p: number[];
    size: number[];
    constructor(n: number) {
        this.p = Array(n)
            .fill(0)
            .map((_, i) => i);
        this.size = Array(n).fill(1);
    }

    find(x: number): number {
        if (this.p[x] !== x) {
            this.p[x] = this.find(this.p[x]);
        }
        return this.p[x];
    }

    union(a: number, b: number): boolean {
        const [pa, pb] = [this.find(a), this.find(b)];
        if (pa === pb) {
            return false;
        }
        if (this.size[pa] > this.size[pb]) {
            this.p[pb] = pa;
            this.size[pa] += this.size[pb];
        } else {
            this.p[pa] = pb;
            this.size[pb] += this.size[pa];
        }
        return true;
    }
}

function validPath(n: number, edges: number[][], source: number, destination: number): boolean {
    const uf = new UnionFind(n);
    edges.forEach(([u, v]) => uf.union(u, v));
    return uf.find(source) === uf.find(destination);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
struct UnionFind {
    p: Vec<usize>,
    size: Vec<usize>,
}

impl UnionFind {
    fn new(n: usize) -> Self {
        let p = (0..n).collect();
        let size = vec![1; n];
        UnionFind { p, size }
    }

    fn find(&mut self, x: usize) -> usize {
        if self.p[x] != x {
            self.p[x] = self.find(self.p[x]);
        }
        self.p[x]
    }

    fn union(&mut self, a: usize, b: usize) {
        let pa = self.find(a);
        let pb = self.find(b);
        if pa != pb {
            if self.size[pa] > self.size[pb] {
                self.p[pb] = pa;
                self.size[pa] += self.size[pb];
            } else {
                self.p[pa] = pb;
                self.size[pb] += self.size[pa];
            }
        }
    }
}

impl Solution {
    pub fn valid_path(n: i32, edges: Vec<Vec<i32>>, source: i32, destination: i32) -> bool {
        let n = n as usize;
        let mut uf = UnionFind::new(n);

        for e in edges {
            let u = e[0] as usize;
            let v = e[1] as usize;
            uf.union(u, v);
        }

        uf.find(source as usize) == uf.find(destination as usize)
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>有一个具有 <code>n</code> 个顶点的 <strong>双向</strong> 图，其中每个顶点标记从 <code>0</code> 到 <code>n - 1</code>（包含 <code>0</code> 和 <code>n - 1</code>）。图中的边用一个二维整数数组 <code>edges</code> 表示，其中 <code>edges[i] = [u<sub>i</sub>, v<sub>i</sub>]</code> 表示顶点 <code>ui</code> 和顶点 <code>vi</code> 之间的双向边。 每个顶点对由 <strong>最多一条</strong> 边连接，并且没有顶点存在与自身相连的边。</p>

<p>请你确定是否存在从顶点 <code>source</code> 开始，到顶点 <code>destination</code> 结束的 <strong>有效路径</strong> 。</p>

<p>给你数组 <code>edges</code> 和整数 <code>n</code>、<code>source</code> 和 <code>destination</code>，如果从 <code>source</code> 到 <code>destination</code> 存在 <strong>有效路径</strong> ，则返回 <code>true</code>，否则返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1900-1999/1971.Find%20if%20Path%20Exists%20in%20Graph/images/validpath-ex1.png" style="width: 141px; height: 121px;" />
<pre>
<strong>输入：</strong>n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2
<strong>输出：</strong>true
<strong>解释：</strong>存在由顶点 0 到顶点 2 的路径:
- 0 → 1 → 2 
- 0 → 2
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1900-1999/1971.Find%20if%20Path%20Exists%20in%20Graph/images/validpath-ex2.png" style="width: 281px; height: 141px;" />
<pre>
<strong>输入：</strong>n = 6, edges = [[0,1],[0,2],[3,5],[5,4],[4,3]], source = 0, destination = 5
<strong>输出：</strong>false
<strong>解释：</strong>不存在由顶点 0 到顶点 5 的路径.
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 2 * 10<sup>5</sup></code></li>
	<li><code>0 &lt;= edges.length &lt;= 2 * 10<sup>5</sup></code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>0 &lt;= u<sub>i</sub>, v<sub>i</sub> &lt;= n - 1</code></li>
	<li><code>u<sub>i</sub> != v<sub>i</sub></code></li>
	<li><code>0 &lt;= source, destination &lt;= n - 1</code></li>
	<li>不存在重复边</li>
	<li>不存在指向顶点自身的边</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS

我们首先将 $\textit{edges}$ 转换成邻接表 $g$，然后使用 DFS，判断是否存在从 $\textit{source}$ 到 $\textit{destination}$ 的路径。

过程中，我们用数组 $\textit{vis}$ 记录已经访问过的顶点，避免重复访问。

时间复杂度 $O(n + m)$，空间复杂度 $O(n + m)$。其中 $n$ 和 $m$ 分别是节点数和边数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def validPath(
        self, n: int, edges: List[List[int]], source: int, destination: int
    ) -> bool:
        def dfs(i: int) -> bool:
            if i == destination:
                return True
            vis.add(i)
            for j in g[i]:
                if j not in vis and dfs(j):
                    return True
            return False

        g = [[] for _ in range(n)]
        for u, v in edges:
            g[u].append(v)
            g[v].append(u)
        vis = set()
        return dfs(source)
```

#### Java

```java
class Solution {
    private int destination;
    private boolean[] vis;
    private List<Integer>[] g;

    public boolean validPath(int n, int[][] edges, int source, int destination) {
        this.destination = destination;
        vis = new boolean[n];
        g = new List[n];
        Arrays.setAll(g, i -> new ArrayList<>());
        for (var e : edges) {
            int u = e[0], v = e[1];
            g[u].add(v);
            g[v].add(u);
        }
        return dfs(source);
    }

    private boolean dfs(int i) {
        if (i == destination) {
            return true;
        }
        vis[i] = true;
        for (var j : g[i]) {
            if (!vis[j] && dfs(j)) {
                return true;
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
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> g[n];
        vector<bool> vis(n);
        for (const auto& e : edges) {
            int u = e[0], v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        function<bool(int)> dfs = [&](int i) -> bool {
            if (i == destination) {
                return true;
            }
            vis[i] = true;
            for (int j : g[i]) {
                if (!vis[j] && dfs(j)) {
                    return true;
                }
            }
            return false;
        };
        return dfs(source);
    }
};
```

#### Go

```go
func validPath(n int, edges [][]int, source int, destination int) bool {
	vis := make([]bool, n)
	g := make([][]int, n)
	for _, e := range edges {
		u, v := e[0], e[1]
		g[u] = append(g[u], v)
		g[v] = append(g[v], u)
	}
	var dfs func(int) bool
	dfs = func(i int) bool {
		if i == destination {
			return true
		}
		vis[i] = true
		for _, j := range g[i] {
			if !vis[j] && dfs(j) {
				return true
			}
		}
		return false
	}
	return dfs(source)
}
```

#### TypeScript

```ts
function validPath(n: number, edges: number[][], source: number, destination: number): boolean {
    const g: number[][] = Array.from({ length: n }, () => []);
    for (const [u, v] of edges) {
        g[u].push(v);
        g[v].push(u);
    }
    const vis = new Set<number>();
    const dfs = (i: number) => {
        if (i === destination) {
            return true;
        }
        if (vis.has(i)) {
            return false;
        }
        vis.add(i);
        return g[i].some(dfs);
    };
    return dfs(source);
}
```

#### Rust

```rust
impl Solution {
    pub fn valid_path(n: i32, edges: Vec<Vec<i32>>, source: i32, destination: i32) -> bool {
        let n = n as usize;
        let source = source as usize;
        let destination = destination as usize;

        let mut g = vec![Vec::new(); n];
        let mut vis = vec![false; n];

        for e in edges {
            let u = e[0] as usize;
            let v = e[1] as usize;
            g[u].push(v);
            g[v].push(u);
        }

        fn dfs(g: &Vec<Vec<usize>>, vis: &mut Vec<bool>, i: usize, destination: usize) -> bool {
            if i == destination {
                return true;
            }
            vis[i] = true;
            for &j in &g[i] {
                if !vis[j] && dfs(g, vis, j, destination) {
                    return true;
                }
            }
            false
        }

        dfs(&g, &mut vis, source, destination)
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：BFS

我们也可以使用 BFS，判断是否存在从 $\textit{source}$ 到 $\textit{destination}$ 的路径。

具体地，我们定义一个队列 $q$，初始时将 $\textit{source}$ 加入队列。另外，我们用一个集合 $\textit{vis}$ 记录已经访问过的顶点，避免重复访问。

接下来，我们不断从队列中取出顶点 $i$，如果 $i = \textit{destination}$，则说明存在从 $\textit{source}$ 到 $\textit{destination}$ 的路径，返回 $\textit{true}$。否则，我们遍历 $i$ 的所有邻接顶点 $j$，如果 $j$ 没有被访问过，我们将 $j$ 加入队列 $q$，并且标记 $j$ 为已访问。

最后，如果队列为空，说明不存在从 $\textit{source}$ 到 $\textit{destination}$ 的路径，返回 $\textit{false}$。

时间复杂度 $O(n + m)$，空间复杂度 $O(n + m)$。其中 $n$ 和 $m$ 分别是节点数和边数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def validPath(
        self, n: int, edges: List[List[int]], source: int, destination: int
    ) -> bool:
        g = [[] for _ in range(n)]
        for u, v in edges:
            g[u].append(v)
            g[v].append(u)
        q = deque([source])
        vis = {source}
        while q:
            i = q.popleft()
            if i == destination:
                return True
            for j in g[i]:
                if j not in vis:
                    vis.add(j)
                    q.append(j)
        return False
```

#### Java

```java
class Solution {
    public boolean validPath(int n, int[][] edges, int source, int destination) {
        List<Integer>[] g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (var e : edges) {
            int u = e[0], v = e[1];
            g[u].add(v);
            g[v].add(u);
        }
        Deque<Integer> q = new ArrayDeque<>();
        q.offer(source);
        boolean[] vis = new boolean[n];
        vis[source] = true;
        while (!q.isEmpty()) {
            int i = q.poll();
            if (i == destination) {
                return true;
            }
            for (int j : g[i]) {
                if (!vis[j]) {
                    vis[j] = true;
                    q.offer(j);
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
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> g(n);
        for (const auto& e : edges) {
            int u = e[0], v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        queue<int> q{{source}};
        vector<bool> vis(n);
        vis[source] = true;
        while (q.size()) {
            int i = q.front();
            q.pop();
            if (i == destination) {
                return true;
            }
            for (int j : g[i]) {
                if (!vis[j]) {
                    vis[j] = true;
                    q.push(j);
                }
            }
        }
        return false;
    }
};
```

#### Go

```go
func validPath(n int, edges [][]int, source int, destination int) bool {
	g := make([][]int, n)
	for _, e := range edges {
		u, v := e[0], e[1]
		g[u] = append(g[u], v)
		g[v] = append(g[v], u)
	}
	q := []int{source}
	vis := make([]bool, n)
	vis[source] = true
	for len(q) > 0 {
		i := q[0]
		q = q[1:]
		if i == destination {
			return true
		}
		for _, j := range g[i] {
			if !vis[j] {
				vis[j] = true
				q = append(q, j)
			}
		}
	}
	return false
}
```

#### TypeScript

```ts
function validPath(n: number, edges: number[][], source: number, destination: number): boolean {
    const g: number[][] = Array.from({ length: n }, () => []);
    for (const [u, v] of edges) {
        g[u].push(v);
        g[v].push(u);
    }
    const vis = new Set<number>([source]);
    const q = [source];
    while (q.length) {
        const i = q.pop()!;
        if (i === destination) {
            return true;
        }
        for (const j of g[i]) {
            if (!vis.has(j)) {
                vis.add(j);
                q.push(j);
            }
        }
    }
    return false;
}
```

#### Rust

```rust
use std::collections::{HashSet, VecDeque};

impl Solution {
    pub fn valid_path(n: i32, edges: Vec<Vec<i32>>, source: i32, destination: i32) -> bool {
        let n = n as usize;
        let source = source as usize;
        let destination = destination as usize;

        let mut g = vec![Vec::new(); n];
        for edge in edges {
            let u = edge[0] as usize;
            let v = edge[1] as usize;
            g[u].push(v);
            g[v].push(u);
        }

        let mut q = VecDeque::new();
        let mut vis = HashSet::new();
        q.push_back(source);
        vis.insert(source);

        while let Some(i) = q.pop_front() {
            if i == destination {
                return true;
            }
            for &j in &g[i] {
                if !vis.contains(&j) {
                    vis.insert(j);
                    q.push_back(j);
                }
            }
        }

        false
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法三：并查集

并查集是一种树形的数据结构，顾名思义，它用于处理一些不交集的**合并**及**查询**问题。 它支持两种操作：

1. 查找（Find）：确定某个元素处于哪个子集，单次操作时间复杂度 $O(\alpha(n))$
1. 合并（Union）：将两个子集合并成一个集合，单次操作时间复杂度 $O(\alpha(n))$

对于本题，我们可以利用并查集，将 `edges` 中的边进行合并，然后判断 `source` 和 `destination` 是否在同一个集合中。

时间复杂度 $O(n \log n + m)$ 或 $O(n \alpha(n) + m)$，空间复杂度 $O(n)$。其中 $n$ 和 $m$ 分别是节点数和边数。

<!-- tabs:start -->

#### Python3

```python
class UnionFind:
    def __init__(self, n):
        self.p = list(range(n))
        self.size = [1] * n

    def find(self, x):
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]

    def union(self, a, b):
        pa, pb = self.find(a), self.find(b)
        if pa == pb:
            return False
        if self.size[pa] > self.size[pb]:
            self.p[pb] = pa
            self.size[pa] += self.size[pb]
        else:
            self.p[pa] = pb
            self.size[pb] += self.size[pa]
        return True


class Solution:
    def validPath(
        self, n: int, edges: List[List[int]], source: int, destination: int
    ) -> bool:
        uf = UnionFind(n)
        for u, v in edges:
            uf.union(u, v)
        return uf.find(source) == uf.find(destination)
```

#### Java

```java
class UnionFind {
    private int[] p;
    private int[] size;

    public UnionFind(int n) {
        p = new int[n];
        size = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
            size[i] = 1;
        }
    }

    public int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    public void union(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa != pb) {
            if (size[pa] > size[pb]) {
                p[pb] = pa;
                size[pa] += size[pb];
            } else {
                p[pa] = pb;
                size[pb] += size[pa];
            }
        }
    }
}

class Solution {
    public boolean validPath(int n, int[][] edges, int source, int destination) {
        UnionFind uf = new UnionFind(n);
        for (var e : edges) {
            uf.union(e[0], e[1]);
        }
        return uf.find(source) == uf.find(destination);
    }
}
```

#### C++

```cpp
class UnionFind {
public:
    UnionFind(int n) {
        p = vector<int>(n);
        size = vector<int>(n, 1);
        iota(p.begin(), p.end(), 0);
    }

    void unite(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa != pb) {
            if (size[pa] > size[pb]) {
                p[pb] = pa;
                size[pa] += size[pb];
            } else {
                p[pa] = pb;
                size[pb] += size[pa];
            }
        }
    }

    int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

private:
    vector<int> p, size;
};

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        UnionFind uf(n);
        for (const auto& e : edges) {
            uf.unite(e[0], e[1]);
        }
        return uf.find(source) == uf.find(destination);
    }
};
```

#### Go

```go
type unionFind struct {
	p, size []int
}

func newUnionFind(n int) *unionFind {
	p := make([]int, n)
	size := make([]int, n)
	for i := range p {
		p[i] = i
		size[i] = 1
	}
	return &unionFind{p, size}
}

func (uf *unionFind) find(x int) int {
	if uf.p[x] != x {
		uf.p[x] = uf.find(uf.p[x])
	}
	return uf.p[x]
}

func (uf *unionFind) union(a, b int) bool {
	pa, pb := uf.find(a), uf.find(b)
	if pa == pb {
		return false
	}
	if uf.size[pa] > uf.size[pb] {
		uf.p[pb] = pa
		uf.size[pa] += uf.size[pb]
	} else {
		uf.p[pa] = pb
		uf.size[pb] += uf.size[pa]
	}
	return true
}

func validPath(n int, edges [][]int, source int, destination int) bool {
	uf := newUnionFind(n)
	for _, e := range edges {
		uf.union(e[0], e[1])
	}
	return uf.find(source) == uf.find(destination)
}
```

#### TypeScript

```ts
class UnionFind {
    p: number[];
    size: number[];
    constructor(n: number) {
        this.p = Array(n)
            .fill(0)
            .map((_, i) => i);
        this.size = Array(n).fill(1);
    }

    find(x: number): number {
        if (this.p[x] !== x) {
            this.p[x] = this.find(this.p[x]);
        }
        return this.p[x];
    }

    union(a: number, b: number): boolean {
        const [pa, pb] = [this.find(a), this.find(b)];
        if (pa === pb) {
            return false;
        }
        if (this.size[pa] > this.size[pb]) {
            this.p[pb] = pa;
            this.size[pa] += this.size[pb];
        } else {
            this.p[pa] = pb;
            this.size[pb] += this.size[pa];
        }
        return true;
    }
}

function validPath(n: number, edges: number[][], source: number, destination: number): boolean {
    const uf = new UnionFind(n);
    edges.forEach(([u, v]) => uf.union(u, v));
    return uf.find(source) === uf.find(destination);
}
```

#### Rust

```rust
struct UnionFind {
    p: Vec<usize>,
    size: Vec<usize>,
}

impl UnionFind {
    fn new(n: usize) -> Self {
        let p = (0..n).collect();
        let size = vec![1; n];
        UnionFind { p, size }
    }

    fn find(&mut self, x: usize) -> usize {
        if self.p[x] != x {
            self.p[x] = self.find(self.p[x]);
        }
        self.p[x]
    }

    fn union(&mut self, a: usize, b: usize) {
        let pa = self.find(a);
        let pb = self.find(b);
        if pa != pb {
            if self.size[pa] > self.size[pb] {
                self.p[pb] = pa;
                self.size[pa] += self.size[pb];
            } else {
                self.p[pa] = pb;
                self.size[pb] += self.size[pa];
            }
        }
    }
}

impl Solution {
    pub fn valid_path(n: i32, edges: Vec<Vec<i32>>, source: i32, destination: i32) -> bool {
        let n = n as usize;
        let mut uf = UnionFind::new(n);

        for e in edges {
            let u = e[0] as usize;
            let v = e[1] as usize;
            uf.union(u, v);
        }

        uf.find(source as usize) == uf.find(destination as usize)
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1972. 同一天的第一个电话和最后一个电话 🔒](https://leetcode.cn/problems/first-and-last-call-on-the-same-day){#1972}

{{< tabs "1972" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
with s as (
    select
        *
    from
        Calls
    union
    all
    select
        recipient_id,
        caller_id,
        call_time
    from
        Calls
),
t as (
    select
        caller_id user_id,
        FIRST_VALUE(recipient_id) over(
            partition by DATE_FORMAT(call_time, '%Y-%m-%d'),
            caller_id
            order by
                call_time asc
        ) first,
        FIRST_VALUE(recipient_id) over(
            partition by DATE_FORMAT(call_time, '%Y-%m-%d'),
            caller_id
            order by
                call_time desc
        ) last
    from
        s
)
select
    distinct user_id
from
    t
where
    first = last
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表: <code>Calls</code></p>

<pre>
+--------------+----------+
| Column Name  | Type     |
+--------------+----------+
| caller_id    | int      |
| recipient_id | int      |
| call_time    | datetime |
+--------------+----------+
(caller_id, recipient_id, call_time) 是这个表的主键。
每一行所含的时间信息都是关于caller_id 和recipient_id的。
</pre>

<p>&nbsp;</p>

<p>编写一个 SQL 查询来找出那些ID们在<strong>任意一天</strong>的第一个电话和最后一个电话都是和同一个人的。这些电话不论是拨打者还是接收者都会被记录。</p>

<p>结果请放在一个<strong>任意次序</strong>约束的表中。</p>

<p>查询结果格式如下所示：</p>

<pre>
<strong>输入：</strong>
Calls table:
+-----------+--------------+---------------------+
| caller_id | recipient_id | call_time           |
+-----------+--------------+---------------------+
| 8         | 4            | 2021-08-24 17:46:07 |
| 4         | 8            | 2021-08-24 19:57:13 |
| 5         | 1            | 2021-08-11 05:28:44 |
| 8         | 3            | 2021-08-17 04:04:15 |
| 11        | 3            | 2021-08-17 13:07:00 |
| 8         | 11           | 2021-08-17 22:22:22 |
+-----------+--------------+---------------------+
<strong>输出：</strong>
+---------+
| user_id |
+---------+
| 1       |
| 4       |
| 5       |
| 8       |
+---------+
<strong>解释：</strong>
在 2021-08-24，这天的第一个电话和最后一个电话都是在user 8和user 4之间。user8应该被包含在答案中。
同样的，user 4在2 021-08-24 的第一个电话和最后一个电话都是和user 8的。user 4也应该被包含在答案中。
在 2021-08-11，user 1和5有一个电话。这个电话是他们彼此当天的唯一一个电话。因此这个电话是他们当天的第一个电话也是最后一个电话，他们都应该被包含在答案中。
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
with s as (
    select
        *
    from
        Calls
    union
    all
    select
        recipient_id,
        caller_id,
        call_time
    from
        Calls
),
t as (
    select
        caller_id user_id,
        FIRST_VALUE(recipient_id) over(
            partition by DATE_FORMAT(call_time, '%Y-%m-%d'),
            caller_id
            order by
                call_time asc
        ) first,
        FIRST_VALUE(recipient_id) over(
            partition by DATE_FORMAT(call_time, '%Y-%m-%d'),
            caller_id
            order by
                call_time desc
        ) last
    from
        s
)
select
    distinct user_id
from
    t
where
    first = last
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1973. 值等于子节点值之和的节点数量 🔒](https://leetcode.cn/problems/count-nodes-equal-to-sum-of-descendants){#1973}

{{< tabs "1973" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def equalToDescendants(self, root: Optional[TreeNode]) -> int:
        def dfs(root):
            if root is None:
                return 0
            l, r = dfs(root.left), dfs(root.right)
            if l + r == root.val:
                nonlocal ans
                ans += 1
            return root.val + l + r

        ans = 0
        dfs(root)
        return ans
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
    private int ans;

    public int equalToDescendants(TreeNode root) {
        dfs(root);
        return ans;
    }

    private int dfs(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int l = dfs(root.left);
        int r = dfs(root.right);
        if (l + r == root.val) {
            ++ans;
        }
        return root.val + l + r;
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
    int equalToDescendants(TreeNode* root) {
        int ans = 0;
        function<long long(TreeNode*)> dfs = [&](TreeNode* root) -> long long {
            if (!root) {
                return 0;
            }
            auto l = dfs(root->left);
            auto r = dfs(root->right);
            ans += l + r == root->val;
            return root->val + l + r;
        };
        dfs(root);
        return ans;
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
func equalToDescendants(root *TreeNode) (ans int) {
	var dfs func(*TreeNode) int
	dfs = func(root *TreeNode) int {
		if root == nil {
			return 0
		}
		l, r := dfs(root.Left), dfs(root.Right)
		if l+r == root.Val {
			ans++
		}
		return root.Val + l + r
	}
	dfs(root)
	return
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一颗二叉树的根节点&nbsp;<code>root</code>&nbsp;，返回满足条件：节点的值等于该节点所有子节点的值之和&nbsp;<em>的节点的数量。</em></p>

<p>一个节点&nbsp;<code>x</code>&nbsp;的&nbsp;<strong>子节点</strong>&nbsp;是指从节点&nbsp;<code>x</code>&nbsp;出发，到所有叶子节点路径上的节点。没有子节点的节点的子节点和视为&nbsp;<code>0</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1900-1999/1973.Count%20Nodes%20Equal%20to%20Sum%20of%20Descendants/images/screenshot-2021-08-17-at-17-16-50-diagram-drawio-diagrams-net.png" style="width: 250px; height: 207px;" />
<pre>
<strong>输入:</strong> root = [10,3,4,2,1]
<strong>输出:</strong> 2
<strong>解释:</strong>
对于值为10的节点: 其子节点之和为： 3+4+2+1 = 10。
对于值为3的节点：其子节点之和为： 2+1 = 3。
</pre>

<p><strong>示例&nbsp;2:</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1900-1999/1973.Count%20Nodes%20Equal%20to%20Sum%20of%20Descendants/images/screenshot-2021-08-17-at-17-25-21-diagram-drawio-diagrams-net.png" style="height: 196px; width: 200px;" />
<pre>
<strong>输入:</strong> root = [2,3,null,2,null]
<strong>输出:</strong> 0
<strong>解释:</strong>
没有节点满足其值等于子节点之和。
</pre>

<p><strong>示例&nbsp;3:</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1900-1999/1973.Count%20Nodes%20Equal%20to%20Sum%20of%20Descendants/images/screenshot-2021-08-17-at-17-23-53-diagram-drawio-diagrams-net.png" style="width: 50px; height: 50px;" />
<pre>
<strong>输入:</strong> root = [0]
<strong>输出:</strong> 1
<strong>解释:</strong>
对于值为0的节点：因为它没有子节点，所以自己点之和为0。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点的数量范围：&nbsp;<code>[1, 10<sup>5</sup>]</code></li>
	<li><code>0 &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：递归

我们设计一个函数 $dfs(root)$，该函数返回以 $root$ 为根节点的子树的所有节点值之和。函数 $dfs(root)$ 的执行过程如下：

-   如果 $root$ 为空，返回 $0$；
-   否则，我们递归地计算 $root$ 的左子树和右子树的节点值之和，记为 $l$ 和 $r$；如果 $l + r = root.val$，说明以 $root$ 为根节点的子树满足条件，我们将答案加 $1$；最后，返回 $root.val + l + r$。

然后我们调用函数 $dfs(root)$，返回答案即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是二叉树的节点数。

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
    def equalToDescendants(self, root: Optional[TreeNode]) -> int:
        def dfs(root):
            if root is None:
                return 0
            l, r = dfs(root.left), dfs(root.right)
            if l + r == root.val:
                nonlocal ans
                ans += 1
            return root.val + l + r

        ans = 0
        dfs(root)
        return ans
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
    private int ans;

    public int equalToDescendants(TreeNode root) {
        dfs(root);
        return ans;
    }

    private int dfs(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int l = dfs(root.left);
        int r = dfs(root.right);
        if (l + r == root.val) {
            ++ans;
        }
        return root.val + l + r;
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
    int equalToDescendants(TreeNode* root) {
        int ans = 0;
        function<long long(TreeNode*)> dfs = [&](TreeNode* root) -> long long {
            if (!root) {
                return 0;
            }
            auto l = dfs(root->left);
            auto r = dfs(root->right);
            ans += l + r == root->val;
            return root->val + l + r;
        };
        dfs(root);
        return ans;
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
func equalToDescendants(root *TreeNode) (ans int) {
	var dfs func(*TreeNode) int
	dfs = func(root *TreeNode) int {
		if root == nil {
			return 0
		}
		l, r := dfs(root.Left), dfs(root.Right)
		if l+r == root.Val {
			ans++
		}
		return root.Val + l + r
	}
	dfs(root)
	return
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1974. 使用特殊打字机键入单词的最少时间](https://leetcode.cn/problems/minimum-time-to-type-word-using-special-typewriter){#1974}

{{< tabs "1974" >}}

{{% tab "python" %}}
```python
class Solution:
    def minTimeToType(self, word: str) -> int:
        ans, a = len(word), ord("a")
        for c in map(ord, word):
            d = abs(c - a)
            ans += min(d, 26 - d)
            a = c
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minTimeToType(String word) {
        int ans = word.length();
        char a = 'a';
        for (char c : word.toCharArray()) {
            int d = Math.abs(a - c);
            ans += Math.min(d, 26 - d);
            a = c;
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
    int minTimeToType(string word) {
        int ans = word.length();
        char a = 'a';
        for (char c : word) {
            int d = abs(a - c);
            ans += min(d, 26 - d);
            a = c;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minTimeToType(word string) int {
	ans := len(word)
	a := rune('a')
	for _, c := range word {
		d := int(max(a-c, c-a))
		ans += min(d, 26-d)
		a = c
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minTimeToType(word: string): number {
    let a = 'a'.charCodeAt(0);
    let ans = word.length;
    for (const c of word) {
        const d = Math.abs(c.charCodeAt(0) - a);
        ans += Math.min(d, 26 - d);
        a = c.charCodeAt(0);
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

<p>有一个特殊打字机，它由一个 <strong>圆盘</strong> 和一个 <strong>指针</strong>&nbsp;组成， 圆盘上标有小写英文字母&nbsp;<code>'a'</code> 到&nbsp;<code>'z'</code>。<strong>只有</strong>&nbsp;当指针指向某个字母时，它才能被键入。指针 <strong>初始时</strong>&nbsp;指向字符 <code>'a'</code>&nbsp;。</p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1900-1999/1974.Minimum%20Time%20to%20Type%20Word%20Using%20Special%20Typewriter/images/chart.jpg" style="width: 530px; height: 410px;" />
<p>每一秒钟，你可以执行以下操作之一：</p>

<ul>
	<li>将指针 <strong>顺时针</strong>&nbsp;或者 <b>逆时针</b>&nbsp;移动一个字符。</li>
	<li>键入指针 <strong>当前</strong>&nbsp;指向的字符。</li>
</ul>

<p>给你一个字符串&nbsp;<code>word</code>&nbsp;，请你返回键入&nbsp;<code>word</code>&nbsp;所表示单词的 <b>最少</b>&nbsp;秒数&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>word = "abc"
<b>输出：</b>5
<strong>解释：
</strong>单词按如下操作键入：
- 花 1 秒键入字符 'a' in 1 ，因为指针初始指向 'a' ，故不需移动指针。
- 花 1 秒将指针顺时针移到 'b' 。
- 花 1 秒键入字符 'b' 。
- 花 1 秒将指针顺时针移到 'c' 。
- 花 1 秒键入字符 'c' 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>word = "bza"
<b>输出：</b>7
<strong>解释：
</strong>单词按如下操作键入：
- 花 1 秒将指针顺时针移到 'b' 。
- 花 1 秒键入字符 'b' 。
- 花 2 秒将指针逆时针移到 'z' 。
- 花 1 秒键入字符 'z' 。
- 花 1 秒将指针顺时针移到 'a' 。
- 花 1 秒键入字符 'a' 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>word = "zjpc"
<b>输出：</b>34
<strong>解释：</strong>
单词按如下操作键入：
- 花 1 秒将指针逆时针移到 'z' 。
- 花 1 秒键入字符 'z' 。
- 花 10 秒将指针顺时针移到 'j' 。
- 花 1 秒键入字符 'j' 。
- 花 6 秒将指针顺时针移到 'p' 。
- 花 1 秒键入字符 'p' 。
- 花 13 秒将指针逆时针移到 'c' 。
- 花 1 秒键入字符 'c' 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= word.length &lt;= 100</code></li>
	<li><code>word</code>&nbsp;只包含小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心

我们初始化答案变量 $\textit{ans}$ 为字符串的长度，表示我们至少需要 $\textit{ans}$ 秒来键入字符串。

接下来，我们遍历字符串，对于每个字符，我们计算当前字符和前一个字符之间的最小距离，将这个距离加到答案中。然后我们更新当前字符为前一个字符，继续遍历。

时间复杂度 $O(n)$，其中 $n$ 为字符串的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minTimeToType(self, word: str) -> int:
        ans, a = len(word), ord("a")
        for c in map(ord, word):
            d = abs(c - a)
            ans += min(d, 26 - d)
            a = c
        return ans
```

#### Java

```java
class Solution {
    public int minTimeToType(String word) {
        int ans = word.length();
        char a = 'a';
        for (char c : word.toCharArray()) {
            int d = Math.abs(a - c);
            ans += Math.min(d, 26 - d);
            a = c;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minTimeToType(string word) {
        int ans = word.length();
        char a = 'a';
        for (char c : word) {
            int d = abs(a - c);
            ans += min(d, 26 - d);
            a = c;
        }
        return ans;
    }
};
```

#### Go

```go
func minTimeToType(word string) int {
	ans := len(word)
	a := rune('a')
	for _, c := range word {
		d := int(max(a-c, c-a))
		ans += min(d, 26-d)
		a = c
	}
	return ans
}
```

#### TypeScript

```ts
function minTimeToType(word: string): number {
    let a = 'a'.charCodeAt(0);
    let ans = word.length;
    for (const c of word) {
        const d = Math.abs(c.charCodeAt(0) - a);
        ans += Math.min(d, 26 - d);
        a = c.charCodeAt(0);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1975. 最大方阵和](https://leetcode.cn/problems/maximum-matrix-sum){#1975}

{{< tabs "1975" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxMatrixSum(self, matrix: List[List[int]]) -> int:
        mi = inf
        s = cnt = 0
        for row in matrix:
            for x in row:
                cnt += x < 0
                y = abs(x)
                mi = min(mi, y)
                s += y
        return s if cnt % 2 == 0 else s - mi * 2
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long maxMatrixSum(int[][] matrix) {
        long s = 0;
        int mi = 1 << 30, cnt = 0;
        for (var row : matrix) {
            for (int x : row) {
                cnt += x < 0 ? 1 : 0;
                int y = Math.abs(x);
                mi = Math.min(mi, y);
                s += y;
            }
        }
        return cnt % 2 == 0 ? s : s - mi * 2;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long s = 0;
        int mi = 1 << 30, cnt = 0;
        for (const auto& row : matrix) {
            for (int x : row) {
                cnt += x < 0 ? 1 : 0;
                int y = abs(x);
                mi = min(mi, y);
                s += y;
            }
        }
        return cnt % 2 == 0 ? s : s - mi * 2;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxMatrixSum(matrix [][]int) int64 {
	var s int64
	mi, cnt := 1<<30, 0
	for _, row := range matrix {
		for _, x := range row {
			if x < 0 {
				cnt++
				x = -x
			}
			mi = min(mi, x)
			s += int64(x)
		}
	}
	if cnt%2 == 0 {
		return s
	}
	return s - int64(mi*2)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxMatrixSum(matrix: number[][]): number {
    let [s, cnt, mi] = [0, 0, Infinity];
    for (const row of matrix) {
        for (const x of row) {
            if (x < 0) {
                ++cnt;
            }
            const y = Math.abs(x);
            s += y;
            mi = Math.min(mi, y);
        }
    }
    return cnt % 2 === 0 ? s : s - 2 * mi;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn max_matrix_sum(matrix: Vec<Vec<i32>>) -> i64 {
        let mut s = 0;
        let mut mi = i32::MAX;
        let mut cnt = 0;
        for row in matrix {
            for &x in row.iter() {
                cnt += if x < 0 { 1 } else { 0 };
                let y = x.abs();
                mi = mi.min(y);
                s += y as i64;
            }
        }
        if cnt % 2 == 0 {
            s
        } else {
            s - (mi as i64 * 2)
        }
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[][]} matrix
 * @return {number}
 */
var maxMatrixSum = function (matrix) {
    let [s, cnt, mi] = [0, 0, Infinity];
    for (const row of matrix) {
        for (const x of row) {
            if (x < 0) {
                ++cnt;
            }
            const y = Math.abs(x);
            s += y;
            mi = Math.min(mi, y);
        }
    }
    return cnt % 2 === 0 ? s : s - 2 * mi;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个&nbsp;<code>n x n</code>&nbsp;的整数方阵&nbsp;<code>matrix</code>&nbsp;。你可以执行以下操作&nbsp;<strong>任意次</strong>&nbsp;：</p>

<ul>
	<li>选择&nbsp;<code>matrix</code>&nbsp;中&nbsp;<strong>相邻</strong>&nbsp;两个元素，并将它们都 <strong>乘以</strong>&nbsp;<code>-1</code>&nbsp;。</li>
</ul>

<p>如果两个元素有 <strong>公共边</strong>&nbsp;，那么它们就是 <strong>相邻</strong>&nbsp;的。</p>

<p>你的目的是 <strong>最大化</strong>&nbsp;方阵元素的和。请你在执行以上操作之后，返回方阵的&nbsp;<strong>最大</strong>&nbsp;和。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1900-1999/1975.Maximum%20Matrix%20Sum/images/pc79-q2ex1.png" style="width: 401px; height: 81px;">
<pre><b>输入：</b>matrix = [[1,-1],[-1,1]]
<b>输出：</b>4
<b>解释：</b>我们可以执行以下操作使和等于 4 ：
- 将第一行的 2 个元素乘以 -1 。
- 将第一列的 2 个元素乘以 -1 。
</pre>

<p><strong>示例&nbsp;2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1900-1999/1975.Maximum%20Matrix%20Sum/images/pc79-q2ex2.png" style="width: 321px; height: 121px;">
<pre><b>输入：</b>matrix = [[1,2,3],[-1,-2,-3],[1,2,3]]
<b>输出：</b>16
<b>解释：</b>我们可以执行以下操作使和等于 16 ：
- 将第二行的最后 2 个元素乘以 -1 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == matrix.length == matrix[i].length</code></li>
	<li><code>2 &lt;= n &lt;= 250</code></li>
	<li><code>-10<sup>5</sup> &lt;= matrix[i][j] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心

如果矩阵中存在零，或者矩阵中负数的个数为偶数，那么最大和就是矩阵中所有元素的绝对值之和。

否则，说明矩阵中有奇数个负数，最终一定会剩下一个负数，我们选择绝对值最小的数，将其变为负数，这样可以使得最终的和最大。

时间复杂度 $O(m \times n)$，其中 $m$ 和 $n$ 分别是矩阵的行数和列数。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxMatrixSum(self, matrix: List[List[int]]) -> int:
        mi = inf
        s = cnt = 0
        for row in matrix:
            for x in row:
                cnt += x < 0
                y = abs(x)
                mi = min(mi, y)
                s += y
        return s if cnt % 2 == 0 else s - mi * 2
```

#### Java

```java
class Solution {
    public long maxMatrixSum(int[][] matrix) {
        long s = 0;
        int mi = 1 << 30, cnt = 0;
        for (var row : matrix) {
            for (int x : row) {
                cnt += x < 0 ? 1 : 0;
                int y = Math.abs(x);
                mi = Math.min(mi, y);
                s += y;
            }
        }
        return cnt % 2 == 0 ? s : s - mi * 2;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long s = 0;
        int mi = 1 << 30, cnt = 0;
        for (const auto& row : matrix) {
            for (int x : row) {
                cnt += x < 0 ? 1 : 0;
                int y = abs(x);
                mi = min(mi, y);
                s += y;
            }
        }
        return cnt % 2 == 0 ? s : s - mi * 2;
    }
};
```

#### Go

```go
func maxMatrixSum(matrix [][]int) int64 {
	var s int64
	mi, cnt := 1<<30, 0
	for _, row := range matrix {
		for _, x := range row {
			if x < 0 {
				cnt++
				x = -x
			}
			mi = min(mi, x)
			s += int64(x)
		}
	}
	if cnt%2 == 0 {
		return s
	}
	return s - int64(mi*2)
}
```

#### TypeScript

```ts
function maxMatrixSum(matrix: number[][]): number {
    let [s, cnt, mi] = [0, 0, Infinity];
    for (const row of matrix) {
        for (const x of row) {
            if (x < 0) {
                ++cnt;
            }
            const y = Math.abs(x);
            s += y;
            mi = Math.min(mi, y);
        }
    }
    return cnt % 2 === 0 ? s : s - 2 * mi;
}
```

#### Rust

```rust
impl Solution {
    pub fn max_matrix_sum(matrix: Vec<Vec<i32>>) -> i64 {
        let mut s = 0;
        let mut mi = i32::MAX;
        let mut cnt = 0;
        for row in matrix {
            for &x in row.iter() {
                cnt += if x < 0 { 1 } else { 0 };
                let y = x.abs();
                mi = mi.min(y);
                s += y as i64;
            }
        }
        if cnt % 2 == 0 {
            s
        } else {
            s - (mi as i64 * 2)
        }
    }
}
```

#### JavaScript

```js
/**
 * @param {number[][]} matrix
 * @return {number}
 */
var maxMatrixSum = function (matrix) {
    let [s, cnt, mi] = [0, 0, Infinity];
    for (const row of matrix) {
        for (const x of row) {
            if (x < 0) {
                ++cnt;
            }
            const y = Math.abs(x);
            s += y;
            mi = Math.min(mi, y);
        }
    }
    return cnt % 2 === 0 ? s : s - 2 * mi;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1976. 到达目的地的方案数](https://leetcode.cn/problems/number-of-ways-to-arrive-at-destination){#1976}

{{< tabs "1976" >}}

{{% tab "python" %}}
```python
class Solution:
    def countPaths(self, n: int, roads: List[List[int]]) -> int:
        g = [[inf] * n for _ in range(n)]
        for u, v, t in roads:
            g[u][v] = g[v][u] = t
        g[0][0] = 0
        dist = [inf] * n
        dist[0] = 0
        f = [0] * n
        f[0] = 1
        vis = [False] * n
        for _ in range(n):
            t = -1
            for j in range(n):
                if not vis[j] and (t == -1 or dist[j] < dist[t]):
                    t = j
            vis[t] = True
            for j in range(n):
                if j == t:
                    continue
                ne = dist[t] + g[t][j]
                if dist[j] > ne:
                    dist[j] = ne
                    f[j] = f[t]
                elif dist[j] == ne:
                    f[j] += f[t]
        mod = 10**9 + 7
        return f[-1] % mod
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countPaths(int n, int[][] roads) {
        final long inf = Long.MAX_VALUE / 2;
        final int mod = (int) 1e9 + 7;
        long[][] g = new long[n][n];
        for (var e : g) {
            Arrays.fill(e, inf);
        }
        for (var r : roads) {
            int u = r[0], v = r[1], t = r[2];
            g[u][v] = t;
            g[v][u] = t;
        }
        g[0][0] = 0;
        long[] dist = new long[n];
        Arrays.fill(dist, inf);
        dist[0] = 0;
        long[] f = new long[n];
        f[0] = 1;
        boolean[] vis = new boolean[n];
        for (int i = 0; i < n; ++i) {
            int t = -1;
            for (int j = 0; j < n; ++j) {
                if (!vis[j] && (t == -1 || dist[j] < dist[t])) {
                    t = j;
                }
            }
            vis[t] = true;
            for (int j = 0; j < n; ++j) {
                if (j == t) {
                    continue;
                }
                long ne = dist[t] + g[t][j];
                if (dist[j] > ne) {
                    dist[j] = ne;
                    f[j] = f[t];
                } else if (dist[j] == ne) {
                    f[j] = (f[j] + f[t]) % mod;
                }
            }
        }
        return (int) f[n - 1];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const long long inf = LLONG_MAX / 2;
        const int mod = 1e9 + 7;

        vector<vector<long long>> g(n, vector<long long>(n, inf));
        for (auto& e : g) {
            fill(e.begin(), e.end(), inf);
        }

        for (auto& r : roads) {
            int u = r[0], v = r[1], t = r[2];
            g[u][v] = t;
            g[v][u] = t;
        }

        g[0][0] = 0;

        vector<long long> dist(n, inf);
        fill(dist.begin(), dist.end(), inf);
        dist[0] = 0;

        vector<long long> f(n);
        f[0] = 1;

        vector<bool> vis(n);
        for (int i = 0; i < n; ++i) {
            int t = -1;
            for (int j = 0; j < n; ++j) {
                if (!vis[j] && (t == -1 || dist[j] < dist[t])) {
                    t = j;
                }
            }
            vis[t] = true;
            for (int j = 0; j < n; ++j) {
                if (j == t) {
                    continue;
                }
                long long ne = dist[t] + g[t][j];
                if (dist[j] > ne) {
                    dist[j] = ne;
                    f[j] = f[t];
                } else if (dist[j] == ne) {
                    f[j] = (f[j] + f[t]) % mod;
                }
            }
        }
        return (int) f[n - 1];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countPaths(n int, roads [][]int) int {
	const inf = math.MaxInt64 / 2
	const mod = int(1e9 + 7)

	g := make([][]int, n)
	dist := make([]int, n)
	for i := range g {
		g[i] = make([]int, n)
		for j := range g[i] {
			g[i][j] = inf
			dist[i] = inf
		}
	}

	for _, r := range roads {
		u, v, t := r[0], r[1], r[2]
		g[u][v] = t
		g[v][u] = t
	}

	f := make([]int, n)
	vis := make([]bool, n)
	f[0] = 1
	g[0][0] = 0
	dist[0] = 0

	for i := 0; i < n; i++ {
		t := -1
		for j := 0; j < n; j++ {
			if !vis[j] && (t == -1 || dist[j] < dist[t]) {
				t = j
			}
		}
		vis[t] = true
		for j := 0; j < n; j++ {
			if j == t {
				continue
			}
			ne := dist[t] + g[t][j]
			if dist[j] > ne {
				dist[j] = ne
				f[j] = f[t]
			} else if dist[j] == ne {
				f[j] = (f[j] + f[t]) % mod
			}
		}
	}
	return f[n-1]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countPaths(n: number, roads: number[][]): number {
    const mod: number = 1e9 + 7;
    const g: number[][] = Array.from({ length: n }, () => Array(n).fill(Infinity));
    for (const [u, v, t] of roads) {
        g[u][v] = t;
        g[v][u] = t;
    }
    g[0][0] = 0;

    const dist: number[] = Array(n).fill(Infinity);
    dist[0] = 0;

    const f: number[] = Array(n).fill(0);
    f[0] = 1;

    const vis: boolean[] = Array(n).fill(false);
    for (let i = 0; i < n; ++i) {
        let t: number = -1;
        for (let j = 0; j < n; ++j) {
            if (!vis[j] && (t === -1 || dist[j] < dist[t])) {
                t = j;
            }
        }
        vis[t] = true;
        for (let j = 0; j < n; ++j) {
            if (j === t) {
                continue;
            }
            const ne: number = dist[t] + g[t][j];
            if (dist[j] > ne) {
                dist[j] = ne;
                f[j] = f[t];
            } else if (dist[j] === ne) {
                f[j] = (f[j] + f[t]) % mod;
            }
        }
    }
    return f[n - 1];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你在一个城市里，城市由 <code>n</code>&nbsp;个路口组成，路口编号为&nbsp;<code>0</code>&nbsp;到&nbsp;<code>n - 1</code>&nbsp;，某些路口之间有 <strong>双向</strong>&nbsp;道路。输入保证你可以从任意路口出发到达其他任意路口，且任意两个路口之间最多有一条路。</p>

<p>给你一个整数&nbsp;<code>n</code>&nbsp;和二维整数数组&nbsp;<code>roads</code>&nbsp;，其中&nbsp;<code>roads[i] = [u<sub>i</sub>, v<sub>i</sub>, time<sub>i</sub>]</code>&nbsp;表示在路口&nbsp;<code>u<sub>i</sub></code>&nbsp;和&nbsp;<code>v<sub>i</sub></code>&nbsp;之间有一条需要花费&nbsp;<code>time<sub>i</sub></code>&nbsp;时间才能通过的道路。你想知道花费 <strong>最少时间</strong>&nbsp;从路口&nbsp;<code>0</code>&nbsp;出发到达路口&nbsp;<code>n - 1</code>&nbsp;的方案数。</p>

<p>请返回花费 <strong>最少时间</strong>&nbsp;到达目的地的 <strong>路径数目</strong>&nbsp;。由于答案可能很大，将结果对&nbsp;<code>10<sup>9</sup> + 7</code>&nbsp;<strong>取余</strong>&nbsp;后返回。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1900-1999/1976.Number%20of%20Ways%20to%20Arrive%20at%20Destination/images/1976_corrected.png" style="width: 255px; height: 400px;" />
<pre>
<b>输入：</b>n = 7, roads = [[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]
<b>输出：</b>4
<b>解释：</b>从路口 0 出发到路口 6 花费的最少时间是 7 分钟。
四条花费 7 分钟的路径分别为：
- 0 ➝ 6
- 0 ➝ 4 ➝ 6
- 0 ➝ 1 ➝ 2 ➝ 5 ➝ 6
- 0 ➝ 1 ➝ 3 ➝ 5 ➝ 6
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>n = 2, roads = [[1,0,10]]
<b>输出：</b>1
<b>解释：</b>只有一条从路口 0 到路口 1 的路，花费 10 分钟。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 200</code></li>
	<li><code>n - 1 &lt;= roads.length &lt;= n * (n - 1) / 2</code></li>
	<li><code>roads[i].length == 3</code></li>
	<li><code>0 &lt;= u<sub>i</sub>, v<sub>i</sub> &lt;= n - 1</code></li>
	<li><code>1 &lt;= time<sub>i</sub> &lt;= 10<sup>9</sup></code></li>
	<li><code>u<sub>i </sub>!= v<sub>i</sub></code></li>
	<li>任意两个路口之间至多有一条路。</li>
	<li>从任意路口出发，你能够到达其他任意路口。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：朴素 Dijkstra 算法

我们定义以下几个数组，其中：

-   `g` 表示图的邻接矩阵，`g[i][j]` 表示点 `i` 到点 `j` 的最短路径长度，初始时全部为 $\infty$，而 `g[0][0]` 为 $0$；然后我们遍历 `roads`，将 `g[u][v]` 和 `g[v][u]` 更新为 `t`；
-   `dist[i]` 表示从起点到点 `i` 的最短路径长度，初始时全部为 $\infty$，而 `dist[0]` 为 $0$；
-   `f[i]` 表示从起点到点 `i` 的最短路径的条数，初始时全部为 $0$，而 `f[0]` 为 $1$；
-   `vis[i]` 表示点 `i` 是否已经被访问过，初始时全部为 `False`。

然后，我们使用朴素 Dijkstra 算法求出从起点到终点的最短路径长度，过程中同时记录下每个点的最短路径的条数。

最后，我们返回 `f[n - 1]` 即可。由于答案可能很大，我们需要对 $10^9 + 7$ 取模。

时间复杂度 $O(n^2)$，空间复杂度 $O(n^2)$。其中 $n$ 为点的个数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countPaths(self, n: int, roads: List[List[int]]) -> int:
        g = [[inf] * n for _ in range(n)]
        for u, v, t in roads:
            g[u][v] = g[v][u] = t
        g[0][0] = 0
        dist = [inf] * n
        dist[0] = 0
        f = [0] * n
        f[0] = 1
        vis = [False] * n
        for _ in range(n):
            t = -1
            for j in range(n):
                if not vis[j] and (t == -1 or dist[j] < dist[t]):
                    t = j
            vis[t] = True
            for j in range(n):
                if j == t:
                    continue
                ne = dist[t] + g[t][j]
                if dist[j] > ne:
                    dist[j] = ne
                    f[j] = f[t]
                elif dist[j] == ne:
                    f[j] += f[t]
        mod = 10**9 + 7
        return f[-1] % mod
```

#### Java

```java
class Solution {
    public int countPaths(int n, int[][] roads) {
        final long inf = Long.MAX_VALUE / 2;
        final int mod = (int) 1e9 + 7;
        long[][] g = new long[n][n];
        for (var e : g) {
            Arrays.fill(e, inf);
        }
        for (var r : roads) {
            int u = r[0], v = r[1], t = r[2];
            g[u][v] = t;
            g[v][u] = t;
        }
        g[0][0] = 0;
        long[] dist = new long[n];
        Arrays.fill(dist, inf);
        dist[0] = 0;
        long[] f = new long[n];
        f[0] = 1;
        boolean[] vis = new boolean[n];
        for (int i = 0; i < n; ++i) {
            int t = -1;
            for (int j = 0; j < n; ++j) {
                if (!vis[j] && (t == -1 || dist[j] < dist[t])) {
                    t = j;
                }
            }
            vis[t] = true;
            for (int j = 0; j < n; ++j) {
                if (j == t) {
                    continue;
                }
                long ne = dist[t] + g[t][j];
                if (dist[j] > ne) {
                    dist[j] = ne;
                    f[j] = f[t];
                } else if (dist[j] == ne) {
                    f[j] = (f[j] + f[t]) % mod;
                }
            }
        }
        return (int) f[n - 1];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const long long inf = LLONG_MAX / 2;
        const int mod = 1e9 + 7;

        vector<vector<long long>> g(n, vector<long long>(n, inf));
        for (auto& e : g) {
            fill(e.begin(), e.end(), inf);
        }

        for (auto& r : roads) {
            int u = r[0], v = r[1], t = r[2];
            g[u][v] = t;
            g[v][u] = t;
        }

        g[0][0] = 0;

        vector<long long> dist(n, inf);
        fill(dist.begin(), dist.end(), inf);
        dist[0] = 0;

        vector<long long> f(n);
        f[0] = 1;

        vector<bool> vis(n);
        for (int i = 0; i < n; ++i) {
            int t = -1;
            for (int j = 0; j < n; ++j) {
                if (!vis[j] && (t == -1 || dist[j] < dist[t])) {
                    t = j;
                }
            }
            vis[t] = true;
            for (int j = 0; j < n; ++j) {
                if (j == t) {
                    continue;
                }
                long long ne = dist[t] + g[t][j];
                if (dist[j] > ne) {
                    dist[j] = ne;
                    f[j] = f[t];
                } else if (dist[j] == ne) {
                    f[j] = (f[j] + f[t]) % mod;
                }
            }
        }
        return (int) f[n - 1];
    }
};
```

#### Go

```go
func countPaths(n int, roads [][]int) int {
	const inf = math.MaxInt64 / 2
	const mod = int(1e9 + 7)

	g := make([][]int, n)
	dist := make([]int, n)
	for i := range g {
		g[i] = make([]int, n)
		for j := range g[i] {
			g[i][j] = inf
			dist[i] = inf
		}
	}

	for _, r := range roads {
		u, v, t := r[0], r[1], r[2]
		g[u][v] = t
		g[v][u] = t
	}

	f := make([]int, n)
	vis := make([]bool, n)
	f[0] = 1
	g[0][0] = 0
	dist[0] = 0

	for i := 0; i < n; i++ {
		t := -1
		for j := 0; j < n; j++ {
			if !vis[j] && (t == -1 || dist[j] < dist[t]) {
				t = j
			}
		}
		vis[t] = true
		for j := 0; j < n; j++ {
			if j == t {
				continue
			}
			ne := dist[t] + g[t][j]
			if dist[j] > ne {
				dist[j] = ne
				f[j] = f[t]
			} else if dist[j] == ne {
				f[j] = (f[j] + f[t]) % mod
			}
		}
	}
	return f[n-1]
}
```

#### TypeScript

```ts
function countPaths(n: number, roads: number[][]): number {
    const mod: number = 1e9 + 7;
    const g: number[][] = Array.from({ length: n }, () => Array(n).fill(Infinity));
    for (const [u, v, t] of roads) {
        g[u][v] = t;
        g[v][u] = t;
    }
    g[0][0] = 0;

    const dist: number[] = Array(n).fill(Infinity);
    dist[0] = 0;

    const f: number[] = Array(n).fill(0);
    f[0] = 1;

    const vis: boolean[] = Array(n).fill(false);
    for (let i = 0; i < n; ++i) {
        let t: number = -1;
        for (let j = 0; j < n; ++j) {
            if (!vis[j] && (t === -1 || dist[j] < dist[t])) {
                t = j;
            }
        }
        vis[t] = true;
        for (let j = 0; j < n; ++j) {
            if (j === t) {
                continue;
            }
            const ne: number = dist[t] + g[t][j];
            if (dist[j] > ne) {
                dist[j] = ne;
                f[j] = f[t];
            } else if (dist[j] === ne) {
                f[j] = (f[j] + f[t]) % mod;
            }
        }
    }
    return f[n - 1];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1977. 划分数字的方案数](https://leetcode.cn/problems/number-of-ways-to-separate-numbers){#1977}

{{< tabs "1977" >}}

{{% tab "python" %}}
```python
class Solution:
    def numberOfCombinations(self, num: str) -> int:
        def cmp(i, j, k):
            x = lcp[i][j]
            return x >= k or num[i + x] >= num[j + x]

        mod = 10**9 + 7
        n = len(num)
        lcp = [[0] * (n + 1) for _ in range(n + 1)]
        for i in range(n - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                if num[i] == num[j]:
                    lcp[i][j] = 1 + lcp[i + 1][j + 1]

        dp = [[0] * (n + 1) for _ in range(n + 1)]
        dp[0][0] = 1
        for i in range(1, n + 1):
            for j in range(1, i + 1):
                v = 0
                if num[i - j] != '0':
                    if i - j - j >= 0 and cmp(i - j, i - j - j, j):
                        v = dp[i - j][j]
                    else:
                        v = dp[i - j][min(j - 1, i - j)]
                dp[i][j] = (dp[i][j - 1] + v) % mod
        return dp[n][n]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private static final int MOD = (int) 1e9 + 7;

    public int numberOfCombinations(String num) {
        int n = num.length();
        int[][] lcp = new int[n + 1][n + 1];
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (num.charAt(i) == num.charAt(j)) {
                    lcp[i][j] = 1 + lcp[i + 1][j + 1];
                }
            }
        }
        int[][] dp = new int[n + 1][n + 1];
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                int v = 0;
                if (num.charAt(i - j) != '0') {
                    if (i - j - j >= 0) {
                        int x = lcp[i - j][i - j - j];
                        if (x >= j || num.charAt(i - j + x) >= num.charAt(i - j - j + x)) {
                            v = dp[i - j][j];
                        }
                    }
                    if (v == 0) {
                        v = dp[i - j][Math.min(j - 1, i - j)];
                    }
                }
                dp[i][j] = (dp[i][j - 1] + v) % MOD;
            }
        }
        return dp[n][n];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    const int mod = 1e9 + 7;

    int numberOfCombinations(string num) {
        int n = num.size();
        vector<vector<int>> lcp(n + 1, vector<int>(n + 1));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (num[i] == num[j]) {
                    lcp[i][j] = 1 + lcp[i + 1][j + 1];
                }
            }
        }
        auto cmp = [&](int i, int j, int k) {
            int x = lcp[i][j];
            return x >= k || num[i + x] >= num[j + x];
        };
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                int v = 0;
                if (num[i - j] != '0') {
                    if (i - j - j >= 0 && cmp(i - j, i - j - j, j)) {
                        v = dp[i - j][j];
                    } else {
                        v = dp[i - j][min(j - 1, i - j)];
                    }
                }
                dp[i][j] = (dp[i][j - 1] + v) % mod;
            }
        }
        return dp[n][n];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numberOfCombinations(num string) int {
	n := len(num)
	lcp := make([][]int, n+1)
	dp := make([][]int, n+1)
	for i := range lcp {
		lcp[i] = make([]int, n+1)
		dp[i] = make([]int, n+1)
	}
	for i := n - 1; i >= 0; i-- {
		for j := n - 1; j >= 0; j-- {
			if num[i] == num[j] {
				lcp[i][j] = 1 + lcp[i+1][j+1]
			}
		}
	}
	cmp := func(i, j, k int) bool {
		x := lcp[i][j]
		return x >= k || num[i+x] >= num[j+x]
	}
	dp[0][0] = 1
	var mod int = 1e9 + 7
	for i := 1; i <= n; i++ {
		for j := 1; j <= i; j++ {
			v := 0
			if num[i-j] != '0' {
				if i-j-j >= 0 && cmp(i-j, i-j-j, j) {
					v = dp[i-j][j]
				} else {
					v = dp[i-j][min(j-1, i-j)]
				}
			}
			dp[i][j] = (dp[i][j-1] + v) % mod
		}
	}
	return dp[n][n]
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你写下了若干 <strong>正整数</strong>&nbsp;，并将它们连接成了一个字符串&nbsp;<code>num</code>&nbsp;。但是你忘记给这些数字之间加逗号了。你只记得这一列数字是 <strong>非递减</strong>&nbsp;的且&nbsp;<strong>没有</strong> 任何数字有前导 0 。</p>

<p>请你返回有多少种可能的 <strong>正整数数组</strong>&nbsp;可以得到字符串&nbsp;<code>num</code>&nbsp;。由于答案可能很大，将结果对 <code>10<sup>9</sup> + 7</code>&nbsp;<b>取余</b>&nbsp;后返回。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>num = "327"
<b>输出：</b>2
<b>解释：</b>以下为可能的方案：
3, 27
327
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>num = "094"
<b>输出：</b>0
<b>解释：</b>不能有数字有前导 0 ，且所有数字均为正数。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>num = "0"
<b>输出：</b>0
<strong>解释：</strong>不能有数字有前导 0 ，且所有数字均为正数。
</pre>

<p><strong>示例 4：</strong></p>

<pre><b>输入：</b>num = "9999999999999"
<b>输出：</b>101
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= num.length &lt;= 3500</code></li>
	<li><code>num</code>&nbsp;只含有数字&nbsp;<code>'0'</code> 到&nbsp;<code>'9'</code>&nbsp;。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划 + 前缀和

定义 $dp[i][j]$ 表示字符串 `num` 的前 $i$ 个字符，且最后一个数字的长度为 $j$ 时的方案数。显然答案为 $\sum_{j=0}^{n} dp[n][j]$。初始值 $dp[0][0] = 1$。

对于 $dp[i][j]$，对应的上一个数的结尾应该是 $i-j$，我们可以枚举 $dp[i-j][k]$，其中 $k\le j$。对于 $k \lt j$ 的部分，即长度小于 $j$ 的方案数可以直接加给 $dp[i][j]$，即 $dp[i][j] = \sum_{k=0}^{j-1} dp[i-j][k]$。因为前一个数字更短，也就意味着它比当前数更小。这里可以用前缀和优化。

但是当 $k=j$ 时，我们需要判断同样长度的两个数字的大小关系。如果前一个数字比当前数字大，那么这种情况是不合法的，我们不应该将其加给 $dp[i][j]$。否则，我们可以将其加给 $dp[i][j]$。这里我们可以先用 $O(n^2)$ 的时间预处理得到“最长公共前缀”，然后用 $O(1)$ 的时间判断两个同样长度的数字的大小关系。

时间复杂度 $O(n^2)$，空间复杂度 $O(n^2)$。其中 $n$ 为字符串 `num` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numberOfCombinations(self, num: str) -> int:
        def cmp(i, j, k):
            x = lcp[i][j]
            return x >= k or num[i + x] >= num[j + x]

        mod = 10**9 + 7
        n = len(num)
        lcp = [[0] * (n + 1) for _ in range(n + 1)]
        for i in range(n - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                if num[i] == num[j]:
                    lcp[i][j] = 1 + lcp[i + 1][j + 1]

        dp = [[0] * (n + 1) for _ in range(n + 1)]
        dp[0][0] = 1
        for i in range(1, n + 1):
            for j in range(1, i + 1):
                v = 0
                if num[i - j] != '0':
                    if i - j - j >= 0 and cmp(i - j, i - j - j, j):
                        v = dp[i - j][j]
                    else:
                        v = dp[i - j][min(j - 1, i - j)]
                dp[i][j] = (dp[i][j - 1] + v) % mod
        return dp[n][n]
```

#### Java

```java
class Solution {
    private static final int MOD = (int) 1e9 + 7;

    public int numberOfCombinations(String num) {
        int n = num.length();
        int[][] lcp = new int[n + 1][n + 1];
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (num.charAt(i) == num.charAt(j)) {
                    lcp[i][j] = 1 + lcp[i + 1][j + 1];
                }
            }
        }
        int[][] dp = new int[n + 1][n + 1];
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                int v = 0;
                if (num.charAt(i - j) != '0') {
                    if (i - j - j >= 0) {
                        int x = lcp[i - j][i - j - j];
                        if (x >= j || num.charAt(i - j + x) >= num.charAt(i - j - j + x)) {
                            v = dp[i - j][j];
                        }
                    }
                    if (v == 0) {
                        v = dp[i - j][Math.min(j - 1, i - j)];
                    }
                }
                dp[i][j] = (dp[i][j - 1] + v) % MOD;
            }
        }
        return dp[n][n];
    }
}
```

#### C++

```cpp
class Solution {
public:
    const int mod = 1e9 + 7;

    int numberOfCombinations(string num) {
        int n = num.size();
        vector<vector<int>> lcp(n + 1, vector<int>(n + 1));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (num[i] == num[j]) {
                    lcp[i][j] = 1 + lcp[i + 1][j + 1];
                }
            }
        }
        auto cmp = [&](int i, int j, int k) {
            int x = lcp[i][j];
            return x >= k || num[i + x] >= num[j + x];
        };
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                int v = 0;
                if (num[i - j] != '0') {
                    if (i - j - j >= 0 && cmp(i - j, i - j - j, j)) {
                        v = dp[i - j][j];
                    } else {
                        v = dp[i - j][min(j - 1, i - j)];
                    }
                }
                dp[i][j] = (dp[i][j - 1] + v) % mod;
            }
        }
        return dp[n][n];
    }
};
```

#### Go

```go
func numberOfCombinations(num string) int {
	n := len(num)
	lcp := make([][]int, n+1)
	dp := make([][]int, n+1)
	for i := range lcp {
		lcp[i] = make([]int, n+1)
		dp[i] = make([]int, n+1)
	}
	for i := n - 1; i >= 0; i-- {
		for j := n - 1; j >= 0; j-- {
			if num[i] == num[j] {
				lcp[i][j] = 1 + lcp[i+1][j+1]
			}
		}
	}
	cmp := func(i, j, k int) bool {
		x := lcp[i][j]
		return x >= k || num[i+x] >= num[j+x]
	}
	dp[0][0] = 1
	var mod int = 1e9 + 7
	for i := 1; i <= n; i++ {
		for j := 1; j <= i; j++ {
			v := 0
			if num[i-j] != '0' {
				if i-j-j >= 0 && cmp(i-j, i-j-j, j) {
					v = dp[i-j][j]
				} else {
					v = dp[i-j][min(j-1, i-j)]
				}
			}
			dp[i][j] = (dp[i][j-1] + v) % mod
		}
	}
	return dp[n][n]
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1978. 上级经理已离职的公司员工](https://leetcode.cn/problems/employees-whose-manager-left-the-company){#1978}

{{< tabs "1978" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT employee_id
FROM Employees
WHERE salary < 30000 AND manager_id NOT IN (SELECT employee_id FROM Employees)
ORDER BY 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表: <code>Employees</code></p>

<pre>
+-------------+----------+
| Column Name | Type     |
+-------------+----------+
| employee_id | int      |
| name        | varchar  |
| manager_id  | int      |
| salary      | int      |
+-------------+----------+
在 SQL 中，employee_id 是这个表的主键。
这个表包含了员工，他们的薪水和上级经理的id。
有一些员工没有上级经理（其 manager_id 是空值）。
</pre>

<p>&nbsp;</p>

<p>查找这些员工的id，他们的薪水严格少于<code>$30000</code>&nbsp;并且他们的上级经理已离职。当一个经理离开公司时，他们的信息需要从员工表中删除掉，但是表中的员工的<code>manager_id</code> &nbsp;这一列还是设置的离职经理的id&nbsp;。</p>

<p>返回的结果按照<code>employee_id&nbsp;</code>从小到大排序。</p>

<p>查询结果如下所示：</p>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre>
<strong>输入：</strong>
Employees table:
+-------------+-----------+------------+--------+
| employee_id | name      | manager_id | salary |
+-------------+-----------+------------+--------+
| 3           | Mila      | 9          | 60301  |
| 12          | Antonella | null       | 31000  |
| 13          | Emery     | null       | 67084  |
| 1           | Kalel     | 11         | 21241  |
| 9           | Mikaela   | null       | 50937  |
| 11          | Joziah    | 6          | 28485  |
+-------------+-----------+------------+--------+
<strong>输出：</strong>
+-------------+
| employee_id |
+-------------+
| 11          |
+-------------+

<strong>解释：</strong>
薪水少于 30000 美元的员工有 1 号(Kalel) 和 11号 (Joziah)。
Kalel 的上级经理是 11 号员工，他还在公司上班(他是 Joziah )。
Joziah 的上级经理是 6 号员工，他已经离职，因为员工表里面已经没有 6 号员工的信息了，它被删除了。
</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：左连接

我们可以使用左连接，将员工表自身连接一次，然后筛选出薪水小于 30000 的员工，且有上级经理，但是上级经理已经离职的员工。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT e1.employee_id
FROM
    Employees AS e1
    LEFT JOIN Employees AS e2 ON e1.manager_id = e2.employee_id
WHERE e1.salary < 30000 AND e1.manager_id IS NOT NULL AND e2.employee_id IS NULL
ORDER BY 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：子查询

我们也可以使用子查询，先找出所有已经离职的经理，然后再找出薪水小于 30000 的员工，且他们的上级经理不在已经离职的经理列表中。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT employee_id
FROM Employees
WHERE salary < 30000 AND manager_id NOT IN (SELECT employee_id FROM Employees)
ORDER BY 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1979. 找出数组的最大公约数](https://leetcode.cn/problems/find-greatest-common-divisor-of-array){#1979}

{{< tabs "1979" >}}

{{% tab "python" %}}
```python
class Solution:
    def findGCD(self, nums: List[int]) -> int:
        return gcd(max(nums), min(nums))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int findGCD(int[] nums) {
        int a = 1, b = 1000;
        for (int x : nums) {
            a = Math.max(a, x);
            b = Math.min(b, x);
        }
        return gcd(a, b);
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
    int findGCD(vector<int>& nums) {
        auto [min, max] = ranges::minmax_element(nums);
        return gcd(*min, *max);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findGCD(nums []int) int {
	a, b := slices.Max(nums), slices.Min(nums)
	return gcd(a, b)
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findGCD(nums: number[]): number {
    const min = Math.min(...nums);
    const max = Math.max(...nums);
    return gcd(min, max);
}

function gcd(a: number, b: number): number {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn find_gcd(nums: Vec<i32>) -> i32 {
        let min_val = *nums.iter().min().unwrap();
        let max_val = *nums.iter().max().unwrap();
        gcd(min_val, max_val)
    }
}

fn gcd(mut a: i32, mut b: i32) -> i32 {
    while b != 0 {
        let temp = b;
        b = a % b;
        a = temp;
    }
    a
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>nums</code> ，返回数组中最大数和最小数的 <strong>最大公约数</strong> 。</p>

<p>两个数的&nbsp;<strong>最大公约数</strong> 是能够被两个数整除的最大正整数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [2,5,6,9,10]
<strong>输出：</strong>2
<strong>解释：</strong>
nums 中最小的数是 2
nums 中最大的数是 10
2 和 10 的最大公约数是 2
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [7,5,6,8,3]
<strong>输出：</strong>1
<strong>解释：</strong>
nums 中最小的数是 3
nums 中最大的数是 8
3 和 8 的最大公约数是 1
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>nums = [3,3]
<strong>输出：</strong>3
<strong>解释：</strong>
nums 中最小的数是 3
nums 中最大的数是 3
3 和 3 的最大公约数是 3
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们根据题意模拟即可，即先找出数组 $\textit{nums}$ 中的最大值和最小值，然后求最大值和最小值的最大公约数。

时间复杂度 $O(n)$，其中 $n$ 为数组 $\textit{nums}$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findGCD(self, nums: List[int]) -> int:
        return gcd(max(nums), min(nums))
```

#### Java

```java
class Solution {
    public int findGCD(int[] nums) {
        int a = 1, b = 1000;
        for (int x : nums) {
            a = Math.max(a, x);
            b = Math.min(b, x);
        }
        return gcd(a, b);
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
    int findGCD(vector<int>& nums) {
        auto [min, max] = ranges::minmax_element(nums);
        return gcd(*min, *max);
    }
};
```

#### Go

```go
func findGCD(nums []int) int {
	a, b := slices.Max(nums), slices.Min(nums)
	return gcd(a, b)
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}
```

#### TypeScript

```ts
function findGCD(nums: number[]): number {
    const min = Math.min(...nums);
    const max = Math.max(...nums);
    return gcd(min, max);
}

function gcd(a: number, b: number): number {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}
```

#### Rust

```rust
impl Solution {
    pub fn find_gcd(nums: Vec<i32>) -> i32 {
        let min_val = *nums.iter().min().unwrap();
        let max_val = *nums.iter().max().unwrap();
        gcd(min_val, max_val)
    }
}

fn gcd(mut a: i32, mut b: i32) -> i32 {
    while b != 0 {
        let temp = b;
        b = a % b;
        a = temp;
    }
    a
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
