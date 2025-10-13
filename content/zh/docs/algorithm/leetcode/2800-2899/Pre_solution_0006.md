---
title: "2850_将石头分散到网格图的最少移动次数"
date: 2025-10-08T18:39:37+08:00
weight: 6
tags: [二分查找, 位运算, 动态规划, 双指针, 哈希表, 图, 字符串, 字符串匹配, 并查集, 广度优先搜索, 数学, 数据库, 数组, 深度优先搜索, 矩阵, 计数, 贪心]
---

{{< markmap >}}
### [2850_将石头分散到网格图的最少移动次数](#2850)
#### [广度优先搜索](#2850)
#### [数组](#2850)
#### [动态规划](#2850)
#### [矩阵](#2850)
### [2851_字符串转换](#2851)
#### [数学](#2851)
#### [字符串](#2851)
#### [动态规划](#2851)
#### [字符串匹配](#2851)
### [2852_所有单元格的远离程度之和 🔒](#2852)
#### [深度优先搜索](#2852)
#### [广度优先搜索](#2852)
#### [并查集](#2852)
#### [数组](#2852)
#### [哈希表](#2852)
#### [矩阵](#2852)
### [2853_最高薪水差异 🔒](#2853)
#### [数据库](#2853)
### [2854_滚动平均步数 🔒](#2854)
#### [数据库](#2854)
### [2855_使数组成为递增数组的最少右移次数](#2855)
#### [数组](#2855)
### [2856_删除数对后的最小数组长度](#2856)
#### [贪心](#2856)
#### [数组](#2856)
#### [哈希表](#2856)
#### [双指针](#2856)
#### [二分查找](#2856)
#### [计数](#2856)
### [2857_统计距离为 k 的点对](#2857)
#### [位运算](#2857)
#### [数组](#2857)
#### [哈希表](#2857)
### [2858_可以到达每一个节点的最少边反转次数](#2858)
#### [深度优先搜索](#2858)
#### [广度优先搜索](#2858)
#### [图](#2858)
#### [动态规划](#2858)
### [2859_计算 K 置位下标对应元素的和](#2859)
#### [位运算](#2859)
#### [数组](#2859)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2850_将石头分散到网格图的最少移动次数
___
#### 广度优先搜索
___
#### 数组
___
#### 动态规划
___
#### 矩阵
---
### 2851_字符串转换
___
#### 数学
___
#### 字符串
___
#### 动态规划
___
#### 字符串匹配
---
### 2852_所有单元格的远离程度之和 🔒
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 并查集
___
#### 数组
___
#### 哈希表
___
#### 矩阵
---
### 2853_最高薪水差异 🔒
___
#### 数据库
---
### 2854_滚动平均步数 🔒
___
#### 数据库
---
### 2855_使数组成为递增数组的最少右移次数
___
#### 数组
---
### 2856_删除数对后的最小数组长度
___
#### 贪心
___
#### 数组
___
#### 哈希表
___
#### 双指针
___
#### 二分查找
___
#### 计数
---
### 2857_统计距离为 k 的点对
___
#### 位运算
___
#### 数组
___
#### 哈希表
---
### 2858_可以到达每一个节点的最少边反转次数
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 图
___
#### 动态规划
---
### 2859_计算 K 置位下标对应元素的和
___
#### 位运算
___
#### 数组
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 位运算 | 动态规划 |
| 双指针 | 哈希表 | 图 |
| 字符串 | 字符串匹配 | 并查集 |
| 广度优先搜索 | 数学 | 数据库 |
| 数组 | 深度优先搜索 | 矩阵 |
| 计数 | 贪心 |  |

# [2850. 将石头分散到网格图的最少移动次数](https://leetcode.cn/problems/minimum-moves-to-spread-stones-over-grid){#2850}

{{< tabs "2850" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumMoves(self, grid: List[List[int]]) -> int:
        def cal(a: tuple, b: tuple) -> int:
            return abs(a[0] - b[0]) + abs(a[1] - b[1])

        left, right = [], []
        for i in range(3):
            for j in range(3):
                if grid[i][j] == 0:
                    left.append((i, j))
                else:
                    for _ in range(grid[i][j] - 1):
                        right.append((i, j))

        n = len(left)
        f = [inf] * (1 << n)
        f[0] = 0
        for i in range(1, 1 << n):
            k = i.bit_count()
            for j in range(n):
                if i >> j & 1:
                    f[i] = min(f[i], f[i ^ (1 << j)] + cal(left[k - 1], right[j]))
        return f[-1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumMoves(int[][] grid) {
        List<int[]> left = new ArrayList<>();
        List<int[]> right = new ArrayList<>();
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (grid[i][j] == 0) {
                    left.add(new int[] {i, j});
                } else {
                    for (int k = 1; k < grid[i][j]; ++k) {
                        right.add(new int[] {i, j});
                    }
                }
            }
        }
        int n = left.size();
        int[] f = new int[1 << n];
        Arrays.fill(f, 1 << 30);
        f[0] = 0;
        for (int i = 1; i < 1 << n; ++i) {
            int k = Integer.bitCount(i);
            for (int j = 0; j < n; ++j) {
                if ((i >> j & 1) == 1) {
                    f[i] = Math.min(f[i], f[i ^ (1 << j)] + cal(left.get(k - 1), right.get(j)));
                }
            }
        }
        return f[(1 << n) - 1];
    }

    private int cal(int[] a, int[] b) {
        return Math.abs(a[0] - b[0]) + Math.abs(a[1] - b[1]);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        using pii = pair<int, int>;
        vector<pii> left, right;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (grid[i][j] == 0) {
                    left.emplace_back(i, j);
                } else {
                    for (int k = 1; k < grid[i][j]; ++k) {
                        right.emplace_back(i, j);
                    }
                }
            }
        }
        auto cal = [](pii a, pii b) {
            return abs(a.first - b.first) + abs(a.second - b.second);
        };
        int n = left.size();
        int f[1 << n];
        memset(f, 0x3f, sizeof(f));
        f[0] = 0;
        for (int i = 1; i < 1 << n; ++i) {
            int k = __builtin_popcount(i);
            for (int j = 0; j < n; ++j) {
                if (i >> j & 1) {
                    f[i] = min(f[i], f[i ^ (1 << j)] + cal(left[k - 1], right[j]));
                }
            }
        }
        return f[(1 << n) - 1];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumMoves(grid [][]int) int {
	left := [][2]int{}
	right := [][2]int{}
	for i := 0; i < 3; i++ {
		for j := 0; j < 3; j++ {
			if grid[i][j] == 0 {
				left = append(left, [2]int{i, j})
			} else {
				for k := 1; k < grid[i][j]; k++ {
					right = append(right, [2]int{i, j})
				}
			}
		}
	}
	cal := func(a, b [2]int) int {
		return abs(a[0]-b[0]) + abs(a[1]-b[1])
	}
	n := len(left)
	f := make([]int, 1<<n)
	f[0] = 0
	for i := 1; i < 1<<n; i++ {
		f[i] = 1 << 30
		k := bits.OnesCount(uint(i))
		for j := 0; j < n; j++ {
			if i>>j&1 == 1 {
				f[i] = min(f[i], f[i^(1<<j)]+cal(left[k-1], right[j]))
			}
		}
	}
	return f[(1<<n)-1]
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumMoves(grid: number[][]): number {
    const left: number[][] = [];
    const right: number[][] = [];
    for (let i = 0; i < 3; ++i) {
        for (let j = 0; j < 3; ++j) {
            if (grid[i][j] === 0) {
                left.push([i, j]);
            } else {
                for (let k = 1; k < grid[i][j]; ++k) {
                    right.push([i, j]);
                }
            }
        }
    }
    const cal = (a: number[], b: number[]) => {
        return Math.abs(a[0] - b[0]) + Math.abs(a[1] - b[1]);
    };
    const n = left.length;
    const f: number[] = Array(1 << n).fill(1 << 30);
    f[0] = 0;
    for (let i = 0; i < 1 << n; ++i) {
        let k = 0;
        for (let j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                ++k;
            }
        }
        for (let j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                f[i] = Math.min(f[i], f[i ^ (1 << j)] + cal(left[k - 1], right[j]));
            }
        }
    }
    return f[(1 << n) - 1];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个大小为 <code>3 * 3</code>&nbsp;，下标从 <strong>0</strong>&nbsp;开始的二维整数矩阵&nbsp;<code>grid</code>&nbsp;，分别表示每一个格子里石头的数目。网格图中总共恰好有&nbsp;<code>9</code>&nbsp;个石头，一个格子里可能会有 <strong>多个</strong>&nbsp;石头。</p>

<p>每一次操作中，你可以将一个石头从它当前所在格子移动到一个至少有一条公共边的相邻格子。</p>

<p>请你返回每个格子恰好有一个石头的 <strong>最少移动次数</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2800-2899/2850.Minimum%20Moves%20to%20Spread%20Stones%20Over%20Grid/images/example1-3.svg" style="width: 401px; height: 281px;" /></p>

<pre>
<b>输入：</b>grid = [[1,1,0],[1,1,1],[1,2,1]]
<b>输出：</b>3
<b>解释：</b>让每个格子都有一个石头的一个操作序列为：
1 - 将一个石头从格子 (2,1) 移动到 (2,2) 。
2 - 将一个石头从格子 (2,2) 移动到 (1,2) 。
3 - 将一个石头从格子 (1,2) 移动到 (0,2) 。
总共需要 3 次操作让每个格子都有一个石头。
让每个格子都有一个石头的最少操作次数为 3 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2800-2899/2850.Minimum%20Moves%20to%20Spread%20Stones%20Over%20Grid/images/example2-2.svg" style="width: 401px; height: 281px;" /></p>

<pre>
<b>输入：</b>grid = [[1,3,0],[1,0,0],[1,0,3]]
<b>输出：</b>4
<b>解释：</b>让每个格子都有一个石头的一个操作序列为：
1 - 将一个石头从格子 (0,1) 移动到 (0,2) 。
2 - 将一个石头从格子 (0,1) 移动到 (1,1) 。
3 - 将一个石头从格子 (2,2) 移动到 (1,2) 。
4 - 将一个石头从格子 (2,2) 移动到 (2,1) 。
总共需要 4 次操作让每个格子都有一个石头。
让每个格子都有一个石头的最少操作次数为 4 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>grid.length == grid[i].length == 3</code></li>
	<li><code>0 &lt;= grid[i][j] &lt;= 9</code></li>
	<li><code>grid</code>&nbsp;中元素之和为&nbsp;<code>9</code> 。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：朴素 BFS

题目实际上是求一个状态图中从初始状态到目标状态的最短路径，因此可以使用 BFS 求解。初始状态为 `grid`，目标状态为 `[[1, 1, 1], [1, 1, 1], [1, 1, 1]]`，在每次操作中，我们可以将一个单元格大于 $1$ 的石头移动到相邻的一个不超过 $1$ 的单元格。如果找到了目标状态，那么就可以返回当前的层数，即为最少移动次数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumMoves(self, grid: List[List[int]]) -> int:
        q = deque([tuple(tuple(row) for row in grid)])
        vis = set(q)
        ans = 0
        dirs = (-1, 0, 1, 0, -1)
        while 1:
            for _ in range(len(q)):
                cur = q.popleft()
                if all(x for row in cur for x in row):
                    return ans
                for i in range(3):
                    for j in range(3):
                        if cur[i][j] > 1:
                            for a, b in pairwise(dirs):
                                x, y = i + a, j + b
                                if 0 <= x < 3 and 0 <= y < 3 and cur[x][y] < 2:
                                    nxt = [list(row) for row in cur]
                                    nxt[i][j] -= 1
                                    nxt[x][y] += 1
                                    nxt = tuple(tuple(row) for row in nxt)
                                    if nxt not in vis:
                                        vis.add(nxt)
                                        q.append(nxt)
            ans += 1
```

#### Java

```java
class Solution {
    public int minimumMoves(int[][] grid) {
        Deque<String> q = new ArrayDeque<>();
        q.add(f(grid));
        Set<String> vis = new HashSet<>();
        vis.add(f(grid));
        int[] dirs = {-1, 0, 1, 0, -1};
        for (int ans = 0;; ++ans) {
            for (int k = q.size(); k > 0; --k) {
                String p = q.poll();
                if ("111111111".equals(p)) {
                    return ans;
                }
                int[][] cur = g(p);
                for (int i = 0; i < 3; ++i) {
                    for (int j = 0; j < 3; ++j) {
                        if (cur[i][j] > 1) {
                            for (int d = 0; d < 4; ++d) {
                                int x = i + dirs[d];
                                int y = j + dirs[d + 1];
                                if (x >= 0 && x < 3 && y >= 0 && y < 3 && cur[x][y] < 2) {
                                    int[][] nxt = new int[3][3];
                                    for (int r = 0; r < 3; ++r) {
                                        for (int c = 0; c < 3; ++c) {
                                            nxt[r][c] = cur[r][c];
                                        }
                                    }
                                    nxt[i][j]--;
                                    nxt[x][y]++;
                                    String s = f(nxt);
                                    if (!vis.contains(s)) {
                                        vis.add(s);
                                        q.add(s);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    private String f(int[][] grid) {
        StringBuilder sb = new StringBuilder();
        for (int[] row : grid) {
            for (int x : row) {
                sb.append(x);
            }
        }
        return sb.toString();
    }

    private int[][] g(String s) {
        int[][] grid = new int[3][3];
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                grid[i][j] = s.charAt(i * 3 + j) - '0';
            }
        }
        return grid;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        queue<string> q;
        q.push(f(grid));
        unordered_set<string> vis;
        vis.insert(f(grid));
        vector<int> dirs = {-1, 0, 1, 0, -1};

        for (int ans = 0;; ++ans) {
            int sz = q.size();
            while (sz--) {
                string p = q.front();
                q.pop();
                if (p == "111111111") {
                    return ans;
                }
                vector<vector<int>> cur = g(p);

                for (int i = 0; i < 3; ++i) {
                    for (int j = 0; j < 3; ++j) {
                        if (cur[i][j] > 1) {
                            for (int d = 0; d < 4; ++d) {
                                int x = i + dirs[d];
                                int y = j + dirs[d + 1];
                                if (x >= 0 && x < 3 && y >= 0 && y < 3 && cur[x][y] < 2) {
                                    vector<vector<int>> nxt = cur;
                                    nxt[i][j]--;
                                    nxt[x][y]++;
                                    string s = f(nxt);
                                    if (!vis.count(s)) {
                                        vis.insert(s);
                                        q.push(s);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

private:
    string f(const vector<vector<int>>& grid) {
        string s;
        for (const auto& row : grid) {
            for (int x : row) {
                s += to_string(x);
            }
        }
        return s;
    }

    vector<vector<int>> g(const string& s) {
        vector<vector<int>> grid(3, vector<int>(3));
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                grid[i][j] = s[i * 3 + j] - '0';
            }
        }
        return grid;
    }
};
```

#### Go

```go
type Queue []string

func (q *Queue) Push(s string) {
	*q = append(*q, s)
}

func (q *Queue) Pop() string {
	s := (*q)[0]
	*q = (*q)[1:]
	return s
}

func (q *Queue) Empty() bool {
	return len(*q) == 0
}

func minimumMoves(grid [][]int) int {
	q := Queue{f(grid)}
	vis := map[string]bool{f(grid): true}
	dirs := []int{-1, 0, 1, 0, -1}

	for ans := 0; ; ans++ {
		sz := len(q)
		for ; sz > 0; sz-- {
			p := q.Pop()
			if p == "111111111" {
				return ans
			}
			cur := g(p)

			for i := 0; i < 3; i++ {
				for j := 0; j < 3; j++ {
					if cur[i][j] > 1 {
						for d := 0; d < 4; d++ {
							x, y := i+dirs[d], j+dirs[d+1]
							if x >= 0 && x < 3 && y >= 0 && y < 3 && cur[x][y] < 2 {
								nxt := make([][]int, 3)
								for r := range nxt {
									nxt[r] = append([]int(nil), cur[r]...)
								}
								nxt[i][j]--
								nxt[x][y]++
								s := f(nxt)
								if !vis[s] {
									vis[s] = true
									q.Push(s)
								}
							}
						}
					}
				}
			}
		}
	}
}

func f(grid [][]int) string {
	var sb strings.Builder
	for _, row := range grid {
		for _, x := range row {
			sb.WriteByte(byte(x) + '0')
		}
	}
	return sb.String()
}

func g(s string) [][]int {
	grid := make([][]int, 3)
	for i := range grid {
		grid[i] = make([]int, 3)
		for j := 0; j < 3; j++ {
			grid[i][j] = int(s[i*3+j] - '0')
		}
	}
	return grid
}
```

#### TypeScript

```ts
function minimumMoves(grid: number[][]): number {
    const q: string[] = [f(grid)];
    const vis: Set<string> = new Set([f(grid)]);
    const dirs: number[] = [-1, 0, 1, 0, -1];

    for (let ans = 0; ; ans++) {
        let sz = q.length;
        while (sz-- > 0) {
            const p = q.shift()!;
            if (p === '111111111') {
                return ans;
            }
            const cur = g(p);

            for (let i = 0; i < 3; i++) {
                for (let j = 0; j < 3; j++) {
                    if (cur[i][j] > 1) {
                        for (let d = 0; d < 4; d++) {
                            const x = i + dirs[d],
                                y = j + dirs[d + 1];
                            if (x >= 0 && x < 3 && y >= 0 && y < 3 && cur[x][y] < 2) {
                                const nxt = cur.map(row => [...row]);
                                nxt[i][j]--;
                                nxt[x][y]++;
                                const s = f(nxt);
                                if (!vis.has(s)) {
                                    vis.add(s);
                                    q.push(s);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

function f(grid: number[][]): string {
    return grid.flat().join('');
}

function g(s: string): number[][] {
    return Array.from({ length: 3 }, (_, i) =>
        Array.from({ length: 3 }, (_, j) => Number(s[i * 3 + j])),
    );
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：状态压缩动态规划

我们可以把所有值为 $0$ 的单元格坐标 $(i, j)$ 放入数组 $left$ 中，如果单元格的值 $v$ 大于 $1$，那么我们把 $v-1$ 个坐标 $(i, j)$ 放入数组 $right$ 中。那么问题就转化为，每个 $right$ 中的坐标 $(i, j)$ 都要移动到 $left$ 中的一个坐标 $(x, y)$，求最少的移动次数。

我们记 $left$ 的长度为 $n$，那么我们可以使用 $n$ 位二进制数来表示 $left$ 中的每个坐标是否被 $right$ 中的坐标填充，其中 $1$ 表示被填充，而 $0$ 表示未被填充。初始时 $f[i] = \infty$，其余 $f[0]=0$。

考虑 $f[i]$，记当前 $i$ 的二进制表示中 $1$ 的个数为 $k$，我们在 $[0..n)$ 的范围内枚举 $j$，如果 $i$ 的第 $j$ 位为 $1$，那么 $f[i]$ 可以由 $f[i \oplus (1 << j)]$ 转移而来，转移的代价为 $cal(left[k-1], right[j])$，其中 $cal$ 表示两个坐标之间的曼哈顿距离。最终答案为 $f[(1 << n) - 1]$。

时间复杂度 $O(n \times 2^n)$，空间复杂度 $O(2^n)$。其中 $n$ 表示 $left$ 的长度，本题中 $n \le 9$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumMoves(self, grid: List[List[int]]) -> int:
        def cal(a: tuple, b: tuple) -> int:
            return abs(a[0] - b[0]) + abs(a[1] - b[1])

        left, right = [], []
        for i in range(3):
            for j in range(3):
                if grid[i][j] == 0:
                    left.append((i, j))
                else:
                    for _ in range(grid[i][j] - 1):
                        right.append((i, j))

        n = len(left)
        f = [inf] * (1 << n)
        f[0] = 0
        for i in range(1, 1 << n):
            k = i.bit_count()
            for j in range(n):
                if i >> j & 1:
                    f[i] = min(f[i], f[i ^ (1 << j)] + cal(left[k - 1], right[j]))
        return f[-1]
```

#### Java

```java
class Solution {
    public int minimumMoves(int[][] grid) {
        List<int[]> left = new ArrayList<>();
        List<int[]> right = new ArrayList<>();
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (grid[i][j] == 0) {
                    left.add(new int[] {i, j});
                } else {
                    for (int k = 1; k < grid[i][j]; ++k) {
                        right.add(new int[] {i, j});
                    }
                }
            }
        }
        int n = left.size();
        int[] f = new int[1 << n];
        Arrays.fill(f, 1 << 30);
        f[0] = 0;
        for (int i = 1; i < 1 << n; ++i) {
            int k = Integer.bitCount(i);
            for (int j = 0; j < n; ++j) {
                if ((i >> j & 1) == 1) {
                    f[i] = Math.min(f[i], f[i ^ (1 << j)] + cal(left.get(k - 1), right.get(j)));
                }
            }
        }
        return f[(1 << n) - 1];
    }

    private int cal(int[] a, int[] b) {
        return Math.abs(a[0] - b[0]) + Math.abs(a[1] - b[1]);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        using pii = pair<int, int>;
        vector<pii> left, right;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (grid[i][j] == 0) {
                    left.emplace_back(i, j);
                } else {
                    for (int k = 1; k < grid[i][j]; ++k) {
                        right.emplace_back(i, j);
                    }
                }
            }
        }
        auto cal = [](pii a, pii b) {
            return abs(a.first - b.first) + abs(a.second - b.second);
        };
        int n = left.size();
        int f[1 << n];
        memset(f, 0x3f, sizeof(f));
        f[0] = 0;
        for (int i = 1; i < 1 << n; ++i) {
            int k = __builtin_popcount(i);
            for (int j = 0; j < n; ++j) {
                if (i >> j & 1) {
                    f[i] = min(f[i], f[i ^ (1 << j)] + cal(left[k - 1], right[j]));
                }
            }
        }
        return f[(1 << n) - 1];
    }
};
```

#### Go

```go
func minimumMoves(grid [][]int) int {
	left := [][2]int{}
	right := [][2]int{}
	for i := 0; i < 3; i++ {
		for j := 0; j < 3; j++ {
			if grid[i][j] == 0 {
				left = append(left, [2]int{i, j})
			} else {
				for k := 1; k < grid[i][j]; k++ {
					right = append(right, [2]int{i, j})
				}
			}
		}
	}
	cal := func(a, b [2]int) int {
		return abs(a[0]-b[0]) + abs(a[1]-b[1])
	}
	n := len(left)
	f := make([]int, 1<<n)
	f[0] = 0
	for i := 1; i < 1<<n; i++ {
		f[i] = 1 << 30
		k := bits.OnesCount(uint(i))
		for j := 0; j < n; j++ {
			if i>>j&1 == 1 {
				f[i] = min(f[i], f[i^(1<<j)]+cal(left[k-1], right[j]))
			}
		}
	}
	return f[(1<<n)-1]
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
```

#### TypeScript

```ts
function minimumMoves(grid: number[][]): number {
    const left: number[][] = [];
    const right: number[][] = [];
    for (let i = 0; i < 3; ++i) {
        for (let j = 0; j < 3; ++j) {
            if (grid[i][j] === 0) {
                left.push([i, j]);
            } else {
                for (let k = 1; k < grid[i][j]; ++k) {
                    right.push([i, j]);
                }
            }
        }
    }
    const cal = (a: number[], b: number[]) => {
        return Math.abs(a[0] - b[0]) + Math.abs(a[1] - b[1]);
    };
    const n = left.length;
    const f: number[] = Array(1 << n).fill(1 << 30);
    f[0] = 0;
    for (let i = 0; i < 1 << n; ++i) {
        let k = 0;
        for (let j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                ++k;
            }
        }
        for (let j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                f[i] = Math.min(f[i], f[i ^ (1 << j)] + cal(left[k - 1], right[j]));
            }
        }
    }
    return f[(1 << n) - 1];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2851. 字符串转换](https://leetcode.cn/problems/string-transformation){#2851}

{{< tabs "2851" >}}

{{% tab "python" %}}
```python
"""
DP, Z-algorithm, Fast mod.
Approach
How to represent a string?
Each operation is just a rotation. Each result string can be represented by an integer from 0 to n - 1. Namely, it's just the new index of s[0].
How to find the integer(s) that can represent string t?
Create a new string s + t + t (length = 3 * n).
Use Z-algorithm (or KMP), for each n <= index < 2 * n, calculate the maximum prefix length that each substring starts from index can match, if the length >= n, then (index - n) is a valid integer representation.
How to get the result?
It's a very obvious DP.
If we use an integer to represent a string, we only need to consider the transition from zero to non-zero and from non-zero to zero. In other words, all the non-zero strings should have the same result.
So let dp[t][i = 0/1] be the number of ways to get the zero/nonzero string
after excatly t steps.
Then
dp[t][0] = dp[t - 1][1] * (n - 1).
All the non zero strings can make it.
dp[t][1] = dp[t - 1][0] + dp[t - 1] * (n - 2).
For a particular non zero string, all the other non zero strings and zero string can make it.
We have dp[0][0] = 1 and dp[0][1] = 0
Use matrix multiplication.
How to calculate dp[k][x = 0, 1] faster?
Use matrix multiplication
vector (dp[t - 1][0], dp[t - 1][1])
multiplies matrix
[0 1]
[n - 1 n - 2]
== vector (dp[t][0], dp[t - 1][1]).
So we just need to calculate the kth power of the matrix which can be done by fast power algorith.
Complexity
Time complexity:
O(n + logk)
Space complexity:
O(n)
"""


class Solution:
    M: int = 1000000007

    def add(self, x: int, y: int) -> int:
        x += y
        if x >= self.M:
            x -= self.M
        return x

    def mul(self, x: int, y: int) -> int:
        return int(x * y % self.M)

    def getZ(self, s: str) -> List[int]:
        n = len(s)
        z = [0] * n
        left = right = 0
        for i in range(1, n):
            if i <= right and z[i - left] <= right - i:
                z[i] = z[i - left]
            else:
                z_i = max(0, right - i + 1)
                while i + z_i < n and s[i + z_i] == s[z_i]:
                    z_i += 1
                z[i] = z_i
            if i + z[i] - 1 > right:
                left = i
                right = i + z[i] - 1
        return z

    def matrixMultiply(self, a: List[List[int]], b: List[List[int]]) -> List[List[int]]:
        m = len(a)
        n = len(a[0])
        p = len(b[0])
        r = [[0] * p for _ in range(m)]
        for i in range(m):
            for j in range(p):
                for k in range(n):
                    r[i][j] = self.add(r[i][j], self.mul(a[i][k], b[k][j]))
        return r

    def matrixPower(self, a: List[List[int]], y: int) -> List[List[int]]:
        n = len(a)
        r = [[0] * n for _ in range(n)]
        for i in range(n):
            r[i][i] = 1
        x = [a[i][:] for i in range(n)]
        while y > 0:
            if y & 1:
                r = self.matrixMultiply(r, x)
            x = self.matrixMultiply(x, x)
            y >>= 1
        return r

    def numberOfWays(self, s: str, t: str, k: int) -> int:
        n = len(s)
        dp = self.matrixPower([[0, 1], [n - 1, n - 2]], k)[0]
        s += t + t
        z = self.getZ(s)
        m = n + n
        result = 0
        for i in range(n, m):
            if z[i] >= n:
                result = self.add(result, dp[0] if i - n == 0 else dp[1])
        return result
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private static final int M = 1000000007;

    private int add(int x, int y) {
        if ((x += y) >= M) {
            x -= M;
        }
        return x;
    }

    private int mul(long x, long y) {
        return (int) (x * y % M);
    }

    private int[] getZ(String s) {
        int n = s.length();
        int[] z = new int[n];
        for (int i = 1, left = 0, right = 0; i < n; ++i) {
            if (i <= right && z[i - left] <= right - i) {
                z[i] = z[i - left];
            } else {
                int z_i = Math.max(0, right - i + 1);
                while (i + z_i < n && s.charAt(i + z_i) == s.charAt(z_i)) {
                    z_i++;
                }
                z[i] = z_i;
            }
            if (i + z[i] - 1 > right) {
                left = i;
                right = i + z[i] - 1;
            }
        }
        return z;
    }

    private int[][] matrixMultiply(int[][] a, int[][] b) {
        int m = a.length, n = a[0].length, p = b[0].length;
        int[][] r = new int[m][p];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < p; ++j) {
                for (int k = 0; k < n; ++k) {
                    r[i][j] = add(r[i][j], mul(a[i][k], b[k][j]));
                }
            }
        }
        return r;
    }

    private int[][] matrixPower(int[][] a, long y) {
        int n = a.length;
        int[][] r = new int[n][n];
        for (int i = 0; i < n; ++i) {
            r[i][i] = 1;
        }
        int[][] x = new int[n][n];
        for (int i = 0; i < n; ++i) {
            System.arraycopy(a[i], 0, x[i], 0, n);
        }
        while (y > 0) {
            if ((y & 1) == 1) {
                r = matrixMultiply(r, x);
            }
            x = matrixMultiply(x, x);
            y >>= 1;
        }
        return r;
    }

    public int numberOfWays(String s, String t, long k) {
        int n = s.length();
        int[] dp = matrixPower(new int[][] {{0, 1}, {n - 1, n - 2}}, k)[0];
        s += t + t;
        int[] z = getZ(s);
        int m = n + n;
        int result = 0;
        for (int i = n; i < m; ++i) {
            if (z[i] >= n) {
                result = add(result, dp[i - n == 0 ? 0 : 1]);
            }
        }
        return result;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
    const int M = 1000000007;

    int add(int x, int y) {
        if ((x += y) >= M) {
            x -= M;
        }
        return x;
    }

    int mul(long long x, long long y) {
        return x * y % M;
    }

    vector<int> getz(const string& s) {
        const int n = s.length();
        vector<int> z(n);
        for (int i = 1, left = 0, right = 0; i < n; ++i) {
            if (i <= right && z[i - left] <= right - i) {
                z[i] = z[i - left];
            } else {
                for (z[i] = max(0, right - i + 1); i + z[i] < n && s[i + z[i]] == s[z[i]]; ++z[i])
                    ;
            }
            if (i + z[i] - 1 > right) {
                left = i;
                right = i + z[i] - 1;
            }
        }
        return z;
    }

    vector<vector<int>> mul(const vector<vector<int>>& a, const vector<vector<int>>& b) {
        const int m = a.size(), n = a[0].size(), p = b[0].size();
        vector<vector<int>> r(m, vector<int>(p));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < p; ++k) {
                    r[i][k] = add(r[i][k], mul(a[i][j], b[j][k]));
                }
            }
        }
        return r;
    }

    vector<vector<int>> pow(const vector<vector<int>>& a, long long y) {
        const int n = a.size();
        vector<vector<int>> r(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            r[i][i] = 1;
        }
        auto x = a;
        for (; y; y >>= 1) {
            if (y & 1) {
                r = mul(r, x);
            }
            x = mul(x, x);
        }
        return r;
    }

public:
    int numberOfWays(string s, string t, long long k) {
        const int n = s.length();
        const auto dp = pow({{0, 1}, {n - 1, n - 2}}, k)[0];
        s.append(t);
        s.append(t);
        const auto z = getz(s);
        const int m = n + n;
        int r = 0;
        for (int i = n; i < m; ++i) {
            if (z[i] >= n) {
                r = add(r, dp[!!(i - n)]);
            }
        }
        return r;
    }
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个长度都为 <code>n</code>&nbsp;的字符串&nbsp;<code>s</code> 和&nbsp;<code>t</code>&nbsp;。你可以对字符串 <code>s</code>&nbsp;执行以下操作：</p>

<ul>
	<li>将 <code>s</code>&nbsp;长度为 <code>l</code>&nbsp;（<code>0 &lt; l &lt; n</code>）的 <strong>后缀字符串</strong>&nbsp;删除，并将它添加在 <code>s</code>&nbsp;的开头。<br />
	比方说，<code>s = 'abcd'</code>&nbsp;，那么一次操作中，你可以删除后缀&nbsp;<code>'cd'</code>&nbsp;，并将它添加到&nbsp;<code>s</code>&nbsp;的开头，得到&nbsp;<code>s = 'cdab'</code>&nbsp;。</li>
</ul>

<p>给你一个整数&nbsp;<code>k</code>&nbsp;，请你返回&nbsp;<strong>恰好</strong> <code>k</code>&nbsp;次操作将<em>&nbsp;</em><code>s</code> 变为<em>&nbsp;</em><code>t</code>&nbsp;的方案数。</p>

<p>由于答案可能很大，返回答案对&nbsp;<code>10<sup>9</sup> + 7</code>&nbsp;<strong>取余</strong>&nbsp;后的结果。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>s = "abcd", t = "cdab", k = 2
<b>输出：</b>2
<b>解释：</b>
第一种方案：
第一次操作，选择 index = 3 开始的后缀，得到 s = "dabc" 。
第二次操作，选择 index = 3 开始的后缀，得到 s = "cdab" 。

第二种方案：
第一次操作，选择 index = 1 开始的后缀，得到 s = "bcda" 。
第二次操作，选择 index = 1 开始的后缀，得到 s = "cdab" 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>s = "ababab", t = "ababab", k = 1
<b>输出：</b>2
<b>解释：</b>
第一种方案：
选择 index = 2 开始的后缀，得到 s = "ababab" 。

第二种方案：
选择 index = 4 开始的后缀，得到 s = "ababab" 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= s.length &lt;= 5 * 10<sup>5</sup></code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>15</sup></code></li>
	<li><code>s.length == t.length</code></li>
	<li><code>s</code> 和&nbsp;<code>t</code>&nbsp;都只包含小写英文字母。</li>
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
"""
DP, Z-algorithm, Fast mod.
Approach
How to represent a string?
Each operation is just a rotation. Each result string can be represented by an integer from 0 to n - 1. Namely, it's just the new index of s[0].
How to find the integer(s) that can represent string t?
Create a new string s + t + t (length = 3 * n).
Use Z-algorithm (or KMP), for each n <= index < 2 * n, calculate the maximum prefix length that each substring starts from index can match, if the length >= n, then (index - n) is a valid integer representation.
How to get the result?
It's a very obvious DP.
If we use an integer to represent a string, we only need to consider the transition from zero to non-zero and from non-zero to zero. In other words, all the non-zero strings should have the same result.
So let dp[t][i = 0/1] be the number of ways to get the zero/nonzero string
after excatly t steps.
Then
dp[t][0] = dp[t - 1][1] * (n - 1).
All the non zero strings can make it.
dp[t][1] = dp[t - 1][0] + dp[t - 1] * (n - 2).
For a particular non zero string, all the other non zero strings and zero string can make it.
We have dp[0][0] = 1 and dp[0][1] = 0
Use matrix multiplication.
How to calculate dp[k][x = 0, 1] faster?
Use matrix multiplication
vector (dp[t - 1][0], dp[t - 1][1])
multiplies matrix
[0 1]
[n - 1 n - 2]
== vector (dp[t][0], dp[t - 1][1]).
So we just need to calculate the kth power of the matrix which can be done by fast power algorith.
Complexity
Time complexity:
O(n + logk)
Space complexity:
O(n)
"""


class Solution:
    M: int = 1000000007

    def add(self, x: int, y: int) -> int:
        x += y
        if x >= self.M:
            x -= self.M
        return x

    def mul(self, x: int, y: int) -> int:
        return int(x * y % self.M)

    def getZ(self, s: str) -> List[int]:
        n = len(s)
        z = [0] * n
        left = right = 0
        for i in range(1, n):
            if i <= right and z[i - left] <= right - i:
                z[i] = z[i - left]
            else:
                z_i = max(0, right - i + 1)
                while i + z_i < n and s[i + z_i] == s[z_i]:
                    z_i += 1
                z[i] = z_i
            if i + z[i] - 1 > right:
                left = i
                right = i + z[i] - 1
        return z

    def matrixMultiply(self, a: List[List[int]], b: List[List[int]]) -> List[List[int]]:
        m = len(a)
        n = len(a[0])
        p = len(b[0])
        r = [[0] * p for _ in range(m)]
        for i in range(m):
            for j in range(p):
                for k in range(n):
                    r[i][j] = self.add(r[i][j], self.mul(a[i][k], b[k][j]))
        return r

    def matrixPower(self, a: List[List[int]], y: int) -> List[List[int]]:
        n = len(a)
        r = [[0] * n for _ in range(n)]
        for i in range(n):
            r[i][i] = 1
        x = [a[i][:] for i in range(n)]
        while y > 0:
            if y & 1:
                r = self.matrixMultiply(r, x)
            x = self.matrixMultiply(x, x)
            y >>= 1
        return r

    def numberOfWays(self, s: str, t: str, k: int) -> int:
        n = len(s)
        dp = self.matrixPower([[0, 1], [n - 1, n - 2]], k)[0]
        s += t + t
        z = self.getZ(s)
        m = n + n
        result = 0
        for i in range(n, m):
            if z[i] >= n:
                result = self.add(result, dp[0] if i - n == 0 else dp[1])
        return result
```

#### Java

```java
class Solution {
    private static final int M = 1000000007;

    private int add(int x, int y) {
        if ((x += y) >= M) {
            x -= M;
        }
        return x;
    }

    private int mul(long x, long y) {
        return (int) (x * y % M);
    }

    private int[] getZ(String s) {
        int n = s.length();
        int[] z = new int[n];
        for (int i = 1, left = 0, right = 0; i < n; ++i) {
            if (i <= right && z[i - left] <= right - i) {
                z[i] = z[i - left];
            } else {
                int z_i = Math.max(0, right - i + 1);
                while (i + z_i < n && s.charAt(i + z_i) == s.charAt(z_i)) {
                    z_i++;
                }
                z[i] = z_i;
            }
            if (i + z[i] - 1 > right) {
                left = i;
                right = i + z[i] - 1;
            }
        }
        return z;
    }

    private int[][] matrixMultiply(int[][] a, int[][] b) {
        int m = a.length, n = a[0].length, p = b[0].length;
        int[][] r = new int[m][p];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < p; ++j) {
                for (int k = 0; k < n; ++k) {
                    r[i][j] = add(r[i][j], mul(a[i][k], b[k][j]));
                }
            }
        }
        return r;
    }

    private int[][] matrixPower(int[][] a, long y) {
        int n = a.length;
        int[][] r = new int[n][n];
        for (int i = 0; i < n; ++i) {
            r[i][i] = 1;
        }
        int[][] x = new int[n][n];
        for (int i = 0; i < n; ++i) {
            System.arraycopy(a[i], 0, x[i], 0, n);
        }
        while (y > 0) {
            if ((y & 1) == 1) {
                r = matrixMultiply(r, x);
            }
            x = matrixMultiply(x, x);
            y >>= 1;
        }
        return r;
    }

    public int numberOfWays(String s, String t, long k) {
        int n = s.length();
        int[] dp = matrixPower(new int[][] {{0, 1}, {n - 1, n - 2}}, k)[0];
        s += t + t;
        int[] z = getZ(s);
        int m = n + n;
        int result = 0;
        for (int i = n; i < m; ++i) {
            if (z[i] >= n) {
                result = add(result, dp[i - n == 0 ? 0 : 1]);
            }
        }
        return result;
    }
}
```

#### C++

```cpp
class Solution {
    const int M = 1000000007;

    int add(int x, int y) {
        if ((x += y) >= M) {
            x -= M;
        }
        return x;
    }

    int mul(long long x, long long y) {
        return x * y % M;
    }

    vector<int> getz(const string& s) {
        const int n = s.length();
        vector<int> z(n);
        for (int i = 1, left = 0, right = 0; i < n; ++i) {
            if (i <= right && z[i - left] <= right - i) {
                z[i] = z[i - left];
            } else {
                for (z[i] = max(0, right - i + 1); i + z[i] < n && s[i + z[i]] == s[z[i]]; ++z[i])
                    ;
            }
            if (i + z[i] - 1 > right) {
                left = i;
                right = i + z[i] - 1;
            }
        }
        return z;
    }

    vector<vector<int>> mul(const vector<vector<int>>& a, const vector<vector<int>>& b) {
        const int m = a.size(), n = a[0].size(), p = b[0].size();
        vector<vector<int>> r(m, vector<int>(p));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < p; ++k) {
                    r[i][k] = add(r[i][k], mul(a[i][j], b[j][k]));
                }
            }
        }
        return r;
    }

    vector<vector<int>> pow(const vector<vector<int>>& a, long long y) {
        const int n = a.size();
        vector<vector<int>> r(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            r[i][i] = 1;
        }
        auto x = a;
        for (; y; y >>= 1) {
            if (y & 1) {
                r = mul(r, x);
            }
            x = mul(x, x);
        }
        return r;
    }

public:
    int numberOfWays(string s, string t, long long k) {
        const int n = s.length();
        const auto dp = pow({{0, 1}, {n - 1, n - 2}}, k)[0];
        s.append(t);
        s.append(t);
        const auto z = getz(s);
        const int m = n + n;
        int r = 0;
        for (int i = n; i < m; ++i) {
            if (z[i] >= n) {
                r = add(r, dp[!!(i - n)]);
            }
        }
        return r;
    }
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2852. 所有单元格的远离程度之和 🔒](https://leetcode.cn/problems/sum-of-remoteness-of-all-cells){#2852}

{{< tabs "2852" >}}

{{% tab "python" %}}
```python
class Solution:
    def sumRemoteness(self, grid: List[List[int]]) -> int:
        def dfs(i: int, j: int) -> (int, int):
            s, t = grid[i][j], 1
            grid[i][j] = 0
            for a, b in pairwise(dirs):
                x, y = i + a, j + b
                if 0 <= x < n and 0 <= y < n and grid[x][y] > 0:
                    s1, t1 = dfs(x, y)
                    s, t = s + s1, t + t1
            return s, t

        n = len(grid)
        dirs = (-1, 0, 1, 0, -1)
        cnt = sum(x > 0 for row in grid for x in row)
        ans = 0
        for i, row in enumerate(grid):
            for j, x in enumerate(row):
                if x > 0:
                    s, t = dfs(i, j)
                    ans += (cnt - t) * s
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int n;
    private int[][] grid;
    private final int[] dirs = {-1, 0, 1, 0, -1};

    public long sumRemoteness(int[][] grid) {
        n = grid.length;
        this.grid = grid;
        int cnt = 0;
        for (int[] row : grid) {
            for (int x : row) {
                if (x > 0) {
                    ++cnt;
                }
            }
        }
        long ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) {
                    long[] res = dfs(i, j);
                    ans += (cnt - res[1]) * res[0];
                }
            }
        }
        return ans;
    }

    private long[] dfs(int i, int j) {
        long[] res = new long[2];
        res[0] = grid[i][j];
        res[1] = 1;
        grid[i][j] = 0;
        for (int k = 0; k < 4; ++k) {
            int x = i + dirs[k], y = j + dirs[k + 1];
            if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] > 0) {
                long[] tmp = dfs(x, y);
                res[0] += tmp[0];
                res[1] += tmp[1];
            }
        }
        return res;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    long long sumRemoteness(vector<vector<int>>& grid) {
        using pli = pair<long long, int>;
        int n = grid.size();
        int cnt = 0;
        for (auto& row : grid) {
            for (int x : row) {
                cnt += x > 0;
            }
        }
        int dirs[5] = {-1, 0, 1, 0, -1};
        function<pli(int, int)> dfs = [&](int i, int j) {
            long long s = grid[i][j];
            int t = 1;
            grid[i][j] = 0;
            for (int k = 0; k < 4; ++k) {
                int x = i + dirs[k], y = j + dirs[k + 1];
                if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] > 0) {
                    auto [ss, tt] = dfs(x, y);
                    s += ss;
                    t += tt;
                }
            }
            return pli(s, t);
        };
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) {
                    auto [s, t] = dfs(i, j);
                    ans += (cnt - t) * s;
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
func sumRemoteness(grid [][]int) (ans int64) {
	n := len(grid)
	cnt := 0
	for _, row := range grid {
		for _, x := range row {
			if x > 0 {
				cnt++
			}
		}
	}
	var dfs func(i, j int) (int, int)
	dfs = func(i, j int) (int, int) {
		s, t := grid[i][j], 1
		grid[i][j] = 0
		dirs := [5]int{-1, 0, 1, 0, -1}
		for k := 0; k < 4; k++ {
			x, y := i+dirs[k], j+dirs[k+1]
			if x >= 0 && x < n && y >= 0 && y < n && grid[x][y] > 0 {
				ss, tt := dfs(x, y)
				s += ss
				t += tt
			}
		}
		return s, t
	}
	for i := range grid {
		for j := range grid[i] {
			if grid[i][j] > 0 {
				s, t := dfs(i, j)
				ans += int64(cnt-t) * int64(s)
			}
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function sumRemoteness(grid: number[][]): number {
    const n = grid.length;
    let cnt = 0;
    for (const row of grid) {
        for (const x of row) {
            if (x > 0) {
                cnt++;
            }
        }
    }
    const dirs = [-1, 0, 1, 0, -1];
    const dfs = (i: number, j: number): [number, number] => {
        let s = grid[i][j];
        let t = 1;
        grid[i][j] = 0;
        for (let k = 0; k < 4; ++k) {
            const [x, y] = [i + dirs[k], j + dirs[k + 1]];
            if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] > 0) {
                const [ss, tt] = dfs(x, y);
                s += ss;
                t += tt;
            }
        }
        return [s, t];
    };
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < n; ++j) {
            if (grid[i][j] > 0) {
                const [s, t] = dfs(i, j);
                ans += (cnt - t) * s;
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

<p>给定一个下标从 <strong>0</strong> 开始的大小为 <code>n * n</code> 的矩阵 <code>grid</code>，其中每个单元格的值 <code>grid[i][j]</code> 要么是 <strong>正整数</strong>，要么是表示阻塞单元格的值 <code>-1</code> 。</p>

<p>你可以从一个非阻塞单元格移动到与其共享边的任何非阻塞单元格。</p>

<p>对于任何单元格 <code>(i, j)</code>，我们定义其 <strong>远离程度</strong> <code>R[i][j]</code> 如下：</p>

<ul>
	<li>如果单元格 <code>(i, j)</code> 是 <strong>非阻塞</strong> 单元格，则 <code>R[i][j]</code> 是值 <code>grid[x][y]</code> 的总和，其中 <strong>没有</strong> 从 <strong>非阻塞</strong> 单元格 <code>(x, y)</code> 到单元格 <code>(i, j)</code> 的路径。</li>
	<li>对于阻塞单元格，<code>R[i][j] == 0</code>。</li>
</ul>

<p>返回所有单元格的 <code>R[i][j]</code> 之和。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2800-2899/2852.Sum%20of%20Remoteness%20of%20All%20Cells/images/1-new.png" style="padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem; width: 400px; height: 304px;" /></p>

<pre>
<b>输入：</b>grid = [[-1,1,-1],[5,-1,4],[-1,3,-1]]
<b>输出：</b>39
<b>解释：</b>在上面的图片中，有四个矩阵。左上角的矩阵是题目给定矩阵的初始值。被阻塞的单元格是黑色的，其他单元格的值与输入相同。在右上方的网格中，可以看到所有单元格的值也就是 R[i][j] 的值。答案是它们的和。即:0 + 12 + 0 + 8 + 0 + 9 + 0 + 10 + 0 = 39。
在上图左下角的矩阵，计算 R[0][1] (目标单元格为绿色)。我们应该将单元格 (0,1) 无法到达的单元格的值相加。这些单元格在这个矩阵中是黄色的。所以 R[0][1] = 5 + 4 + 3 = 12。
在上图右下角的矩阵，计算 R[1][2] (目标单元格为绿色)。我们应该把单元格 (1,2) 无法到达的单元格的值相加。这些单元格在这个矩阵中是黄色的。所以 R[1][2] = 1 + 5 + 3 = 9。
</pre>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2800-2899/2852.Sum%20of%20Remoteness%20of%20All%20Cells/images/2.png" style="width: 400px; height: 302px; background: #fff; border-radius: .5rem;" /></p>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>grid = [[-1,3,4],[-1,-1,-1],[3,-1,-1]]
<b>输出：</b>13
<b>解释：</b>在上面的图片中，有四个矩阵。左上角的矩阵是给定矩阵的初始值。被阻塞的单元格是黑色的，其他单元格的值与输入相同。在右上方的网格中，可以看到所有单元格的值也就是 R[i][j] 的值。答案是它们的和。即:3 + 3 + 0 + 0 + 0 + 0 + 7 + 0 + 0 = 13。
在上图左下角的矩阵上，计算 R[0][2] (目标单元格为绿色)。将单元格 (0,2) 无法到达的单元格的值相加。这个单元格在这个矩阵中是黄色的。所以 R[0][2] = 3。
在上图右下角的矩阵上，计算 R[2][0] (目标单元格为绿色)。将单元格 (2,0) 无法到达的单元格的值相加，这些单元格在这个矩阵中是黄色的。所以 R[2][0] = 3 + 4 = 7。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>grid = [[1]]
<b>输出：</b>0
<b>解释：</b>因为除了 (0,0) 没有其他单元格，所以 R[0][0] 等于 0。所以所有单元格的和是 0。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 300</code></li>
	<li><code>1 &lt;= grid[i][j] &lt;= 10<sup>6</sup></code> 或&nbsp;<code>grid[i][j] == -1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS

我们先统计矩阵中非阻塞的格子的个数，记为 $cnt$，然后从每个非阻塞的格子出发，使用 DFS 计算出每个连通块中格子之和 $s$ 以及格子个数 $t$，那么其它连通块的所有 $(cnt - t)$ 个格子都可以累加上 $s$。我们累加所有连通块的结果即可。

时间复杂度 $O(n^2)$，空间复杂度 $O(n^2)$。其中 $n$ 是矩阵的边长。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def sumRemoteness(self, grid: List[List[int]]) -> int:
        def dfs(i: int, j: int) -> (int, int):
            s, t = grid[i][j], 1
            grid[i][j] = 0
            for a, b in pairwise(dirs):
                x, y = i + a, j + b
                if 0 <= x < n and 0 <= y < n and grid[x][y] > 0:
                    s1, t1 = dfs(x, y)
                    s, t = s + s1, t + t1
            return s, t

        n = len(grid)
        dirs = (-1, 0, 1, 0, -1)
        cnt = sum(x > 0 for row in grid for x in row)
        ans = 0
        for i, row in enumerate(grid):
            for j, x in enumerate(row):
                if x > 0:
                    s, t = dfs(i, j)
                    ans += (cnt - t) * s
        return ans
```

#### Java

```java
class Solution {
    private int n;
    private int[][] grid;
    private final int[] dirs = {-1, 0, 1, 0, -1};

    public long sumRemoteness(int[][] grid) {
        n = grid.length;
        this.grid = grid;
        int cnt = 0;
        for (int[] row : grid) {
            for (int x : row) {
                if (x > 0) {
                    ++cnt;
                }
            }
        }
        long ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) {
                    long[] res = dfs(i, j);
                    ans += (cnt - res[1]) * res[0];
                }
            }
        }
        return ans;
    }

    private long[] dfs(int i, int j) {
        long[] res = new long[2];
        res[0] = grid[i][j];
        res[1] = 1;
        grid[i][j] = 0;
        for (int k = 0; k < 4; ++k) {
            int x = i + dirs[k], y = j + dirs[k + 1];
            if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] > 0) {
                long[] tmp = dfs(x, y);
                res[0] += tmp[0];
                res[1] += tmp[1];
            }
        }
        return res;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long sumRemoteness(vector<vector<int>>& grid) {
        using pli = pair<long long, int>;
        int n = grid.size();
        int cnt = 0;
        for (auto& row : grid) {
            for (int x : row) {
                cnt += x > 0;
            }
        }
        int dirs[5] = {-1, 0, 1, 0, -1};
        function<pli(int, int)> dfs = [&](int i, int j) {
            long long s = grid[i][j];
            int t = 1;
            grid[i][j] = 0;
            for (int k = 0; k < 4; ++k) {
                int x = i + dirs[k], y = j + dirs[k + 1];
                if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] > 0) {
                    auto [ss, tt] = dfs(x, y);
                    s += ss;
                    t += tt;
                }
            }
            return pli(s, t);
        };
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) {
                    auto [s, t] = dfs(i, j);
                    ans += (cnt - t) * s;
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func sumRemoteness(grid [][]int) (ans int64) {
	n := len(grid)
	cnt := 0
	for _, row := range grid {
		for _, x := range row {
			if x > 0 {
				cnt++
			}
		}
	}
	var dfs func(i, j int) (int, int)
	dfs = func(i, j int) (int, int) {
		s, t := grid[i][j], 1
		grid[i][j] = 0
		dirs := [5]int{-1, 0, 1, 0, -1}
		for k := 0; k < 4; k++ {
			x, y := i+dirs[k], j+dirs[k+1]
			if x >= 0 && x < n && y >= 0 && y < n && grid[x][y] > 0 {
				ss, tt := dfs(x, y)
				s += ss
				t += tt
			}
		}
		return s, t
	}
	for i := range grid {
		for j := range grid[i] {
			if grid[i][j] > 0 {
				s, t := dfs(i, j)
				ans += int64(cnt-t) * int64(s)
			}
		}
	}
	return
}
```

#### TypeScript

```ts
function sumRemoteness(grid: number[][]): number {
    const n = grid.length;
    let cnt = 0;
    for (const row of grid) {
        for (const x of row) {
            if (x > 0) {
                cnt++;
            }
        }
    }
    const dirs = [-1, 0, 1, 0, -1];
    const dfs = (i: number, j: number): [number, number] => {
        let s = grid[i][j];
        let t = 1;
        grid[i][j] = 0;
        for (let k = 0; k < 4; ++k) {
            const [x, y] = [i + dirs[k], j + dirs[k + 1]];
            if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] > 0) {
                const [ss, tt] = dfs(x, y);
                s += ss;
                t += tt;
            }
        }
        return [s, t];
    };
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < n; ++j) {
            if (grid[i][j] > 0) {
                const [s, t] = dfs(i, j);
                ans += (cnt - t) * s;
            }
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

# [2853. 最高薪水差异 🔒](https://leetcode.cn/problems/highest-salaries-difference){#2853}

{{< tabs "2853" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT MAX(s) - MIN(s) AS salary_difference
FROM
    (
        SELECT MAX(salary) AS s
        FROM Salaries
        GROUP BY department
    ) AS t;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code><font face="monospace">Salaries</font></code></p>

<pre>
+-------------+---------+ 
| Column Name | Type    | 
+-------------+---------+ 
| emp_name    | varchar | 
| department  | varchar | 
| salary      | int     |
+-------------+---------+
该表的主键（具有唯一值的列的组合）是 (emp_name, department)。 
该表的每一行包含 emp_name、department 和 salary。工程部门和市场部门至少会有一条记录。
</pre>

<p>编写一个解决方案，计算&nbsp;<strong>市场部门&nbsp;</strong>和&nbsp;<strong>工程部门&nbsp;</strong>中&nbsp;<strong>最高&nbsp;</strong>工资之间的差异。输出工资的绝对差异。</p>

<p>返回结果表。</p>

<p>返回结果格式如下示例所示。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1:</strong></p>

<pre>
<b>输入：</b>
Salaries table:
+----------+-------------+--------+
| emp_name | department  | salary |
+----------+-------------+--------+
| Kathy    | Engineering | 50000  |
| Roy      | Marketing   | 30000  |
| Charles  | Engineering | 45000  |
| Jack     | Engineering | 85000  | 
| Benjamin | Marketing   | 34000  |
| Anthony  | Marketing   | 42000  |
| Edward   | Engineering | 102000 |
| Terry    | Engineering | 44000  |
| Evelyn   | Marketing   | 53000  |
| Arthur   | Engineering | 32000  |
+----------+-------------+--------+
<b>输出：</b>
+-------------------+
| salary_difference | 
+-------------------+
| 49000             | 
+-------------------+
<b>解释：</b>
- 工程部门和市场部门的最高工资分别为 102,000 和 53,000，因此绝对差异为 49,000。
</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：GROUP BY 分组

我们可以先分别计算出每个部门的最高工资，然后再计算两个最高工资的差值。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT MAX(s) - MIN(s) AS salary_difference
FROM
    (
        SELECT MAX(salary) AS s
        FROM Salaries
        GROUP BY department
    ) AS t;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2854. 滚动平均步数 🔒](https://leetcode.cn/problems/rolling-average-steps){#2854}

{{< tabs "2854" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            user_id,
            steps_date,
            ROUND(
                AVG(steps_count) OVER (
                    PARTITION BY user_id
                    ORDER BY steps_date
                    ROWS 2 PRECEDING
                ),
                2
            ) AS rolling_average,
            DATEDIFF(
                steps_date,
                LAG(steps_date, 2) OVER (
                    PARTITION BY user_id
                    ORDER BY steps_date
                )
            ) = 2 AS st
        FROM Steps
    )
SELECT
    user_id,
    steps_date,
    rolling_average
FROM T
WHERE st = 1
ORDER BY 1, 2;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：&nbsp;<code><font face="monospace">Steps</font></code></p>

<pre>
+-------------+------+ 
| Column Name | Type | 
+-------------+------+ 
| user_id     | int  | 
| steps_count | int  |
| steps_date  | date |
+-------------+------+
(user_id, steps_date) 是此表的主键。
该表的每一行包含 user_id、steps_count 和 steps_date。
</pre>

<p>编写一个解决方案，计算出每个用户的&nbsp;<code>3-day</code> <strong>滚动平均步数&nbsp;</strong>。</p>

<p>计算 <code>n-day</code> <strong>滚动平均值 </strong>的计算方式如下：</p>

<ul>
	<li>对于每一天，如果有可用数据的情况下，我们会计算以该天为结束的 <code>n</code> 天连续步数的平均值，否则，对于该天来说，<code>n</code> 天滚动平均步数是未定义的。</li>
</ul>

<p>输出 <code>user_id</code>&nbsp;、 <code>steps_date</code><em> </em>和滚动平均值。并将滚动平均值四舍五入到&nbsp;<strong>两位小数</strong>。</p>

<p>返回结果表以<code>user_id</code><em>&nbsp;</em>和 <code>steps_date</code><em>&nbsp;</em><strong>升序</strong><em>&nbsp;</em>排序。</p>

<p>结果的格式如下示例。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1:</strong></p>

<pre>
<b>输入：</b>
Steps table:
+---------+-------------+------------+
| user_id | steps_count | steps_date |
+---------+-------------+------------+
| 1       | 687         | 2021-09-02 |
| 1       | 395         | 2021-09-04 |
| 1       | 499         | 2021-09-05 |
| 1       | 712         | 2021-09-06 |
| 1       | 576         | 2021-09-07 |
| 2       | 153         | 2021-09-06 |
| 2       | 171         | 2021-09-07 |
| 2       | 530         | 2021-09-08 |
| 3       | 945         | 2021-09-04 |
| 3       | 120         | 2021-09-07 |
| 3       | 557         | 2021-09-08 |
| 3       | 840         | 2021-09-09 |
| 3       | 627         | 2021-09-10 |
| 5       | 382         | 2021-09-05 |
| 6       | 480         | 2021-09-01 |
| 6       | 191         | 2021-09-02 |
| 6       | 303         | 2021-09-05 |
+---------+-------------+------------+
<b>输出：</b>
+---------+------------+-----------------+
| user_id | steps_date | rolling_average | 
+---------+------------+-----------------+
| 1       | 2021-09-06 | 535.33          | 
| 1       | 2021-09-07 | 595.67          | 
| 2       | 2021-09-08 | 284.67          |
| 3       | 2021-09-09 | 505.67          |
| 3       | 2021-09-10 | 674.67          |    
+---------+------------+-----------------+
<b>解释：</b>
- 对于 ID 为 1 的用户，截止到 2021-09-06 的三天连续的步数可用。因此，该日期的滚动平均值计算为 (395 + 499 + 712) / 3 = 535.33。
- 对于 ID 为 1 的用户，截止到 2021-09-07 的三天连续的步数可用。因此，该日期的滚动平均值计算为 (499 + 712 + 576) / 3 = 595.67。
- 对于 ID 为 2 的用户，截止到 2021-09-08 的三天连续的步数可用。因此，该日期的滚动平均值计算为 (153 + 171 + 530) / 3 = 284.67。
- 对于 ID 为 3 的用户，截止到 2021-09-09 的三天连续的步数可用。因此，该日期的滚动平均值计算为 (120 + 557 + 840) / 3 = 505.67。
- 对于 ID 为 3 的用户，截止到 2021-09-10 的三天连续的步数可用。因此，该日期的滚动平均值计算为 (557 + 840 + 627) / 3 = 674.67。
- 对于 ID 为 4 和 5 的用户，由于连续三天的数据不足，无法计算滚动平均值。结果表按 user_id 和 steps_date 升序排序。</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：窗口函数

我们用窗口函数 `LAG() OVER()` 来计算每个用户当前日期与上上个日期之间的天数差，如果为 $2$，说明这两个日期之间有连续 $3$ 天的数据，我们可以利用窗口函数 `AVG() OVER()` 来计算这 $3$ 个数据的平均值。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            user_id,
            steps_date,
            ROUND(
                AVG(steps_count) OVER (
                    PARTITION BY user_id
                    ORDER BY steps_date
                    ROWS 2 PRECEDING
                ),
                2
            ) AS rolling_average,
            DATEDIFF(
                steps_date,
                LAG(steps_date, 2) OVER (
                    PARTITION BY user_id
                    ORDER BY steps_date
                )
            ) = 2 AS st
        FROM Steps
    )
SELECT
    user_id,
    steps_date,
    rolling_average
FROM T
WHERE st = 1
ORDER BY 1, 2;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2855. 使数组成为递增数组的最少右移次数](https://leetcode.cn/problems/minimum-right-shifts-to-sort-the-array){#2855}

{{< tabs "2855" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumRightShifts(self, nums: List[int]) -> int:
        n = len(nums)
        i = 1
        while i < n and nums[i - 1] < nums[i]:
            i += 1
        k = i + 1
        while k < n and nums[k - 1] < nums[k] < nums[0]:
            k += 1
        return -1 if k < n else n - i
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumRightShifts(List<Integer> nums) {
        int n = nums.size();
        int i = 1;
        while (i < n && nums.get(i - 1) < nums.get(i)) {
            ++i;
        }
        int k = i + 1;
        while (k < n && nums.get(k - 1) < nums.get(k) && nums.get(k) < nums.get(0)) {
            ++k;
        }
        return k < n ? -1 : n - i;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int n = nums.size();
        int i = 1;
        while (i < n && nums[i - 1] < nums[i]) {
            ++i;
        }
        int k = i + 1;
        while (k < n && nums[k - 1] < nums[k] && nums[k] < nums[0]) {
            ++k;
        }
        return k < n ? -1 : n - i;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumRightShifts(nums []int) int {
	n := len(nums)
	i := 1
	for i < n && nums[i-1] < nums[i] {
		i++
	}
	k := i + 1
	for k < n && nums[k-1] < nums[k] && nums[k] < nums[0] {
		k++
	}
	if k < n {
		return -1
	}
	return n - i
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumRightShifts(nums: number[]): number {
    const n = nums.length;
    let i = 1;
    while (i < n && nums[i - 1] < nums[i]) {
        ++i;
    }
    let k = i + 1;
    while (k < n && nums[k - 1] < nums[k] && nums[k] < nums[0]) {
        ++k;
    }
    return k < n ? -1 : n - i;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个长度为 <code>n</code>&nbsp;下标从 <strong>0</strong>&nbsp;开始的数组&nbsp;<code>nums</code>&nbsp;，数组中的元素为&nbsp;<strong>互不相同</strong>&nbsp;的正整数。请你返回让 <code>nums</code>&nbsp;成为递增数组的 <strong>最少右移</strong>&nbsp;次数，如果无法得到递增数组，返回 <code>-1</code>&nbsp;。</p>

<p>一次 <strong>右移</strong>&nbsp;指的是同时对所有下标进行操作，将下标为 <code>i</code>&nbsp;的元素移动到下标&nbsp;<code>(i + 1) % n</code>&nbsp;处。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [3,4,5,1,2]
<b>输出：</b>2
<b>解释：</b>
第一次右移后，nums = [2,3,4,5,1] 。
第二次右移后，nums = [1,2,3,4,5] 。
现在 nums 是递增数组了，所以答案为 2 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [1,3,5]
<b>输出：</b>0
<b>解释：</b>nums 已经是递增数组了，所以答案为 0 。</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>nums = [2,1,4]
<b>输出：</b>-1
<b>解释：</b>无法将数组变为递增数组。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 100</code></li>
	<li><code>nums</code>&nbsp;中的整数互不相同。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：直接遍历

我们先用一个指针 $i$ 从左到右遍历数组 $nums$，找出一段连续的递增序列，直到 $i$ 到达数组末尾或者 $nums[i - 1] \gt nums[i]$。接下来我们用另一个指针 $k$ 从 $i + 1$ 开始遍历数组 $nums$，找出一段连续的递增序列，直到 $k$ 到达数组末尾或者 $nums[k - 1] \gt nums[k]$ 且 $nums[k] \gt nums[0]$。如果 $k$ 到达数组末尾，说明数组已经是递增的，返回 $n - i$；否则返回 $-1$。

时间复杂度 $O(n)$，空间复杂度 $O(1)$。其中 $n$ 是数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumRightShifts(self, nums: List[int]) -> int:
        n = len(nums)
        i = 1
        while i < n and nums[i - 1] < nums[i]:
            i += 1
        k = i + 1
        while k < n and nums[k - 1] < nums[k] < nums[0]:
            k += 1
        return -1 if k < n else n - i
```

#### Java

```java
class Solution {
    public int minimumRightShifts(List<Integer> nums) {
        int n = nums.size();
        int i = 1;
        while (i < n && nums.get(i - 1) < nums.get(i)) {
            ++i;
        }
        int k = i + 1;
        while (k < n && nums.get(k - 1) < nums.get(k) && nums.get(k) < nums.get(0)) {
            ++k;
        }
        return k < n ? -1 : n - i;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int n = nums.size();
        int i = 1;
        while (i < n && nums[i - 1] < nums[i]) {
            ++i;
        }
        int k = i + 1;
        while (k < n && nums[k - 1] < nums[k] && nums[k] < nums[0]) {
            ++k;
        }
        return k < n ? -1 : n - i;
    }
};
```

#### Go

```go
func minimumRightShifts(nums []int) int {
	n := len(nums)
	i := 1
	for i < n && nums[i-1] < nums[i] {
		i++
	}
	k := i + 1
	for k < n && nums[k-1] < nums[k] && nums[k] < nums[0] {
		k++
	}
	if k < n {
		return -1
	}
	return n - i
}
```

#### TypeScript

```ts
function minimumRightShifts(nums: number[]): number {
    const n = nums.length;
    let i = 1;
    while (i < n && nums[i - 1] < nums[i]) {
        ++i;
    }
    let k = i + 1;
    while (k < n && nums[k - 1] < nums[k] && nums[k] < nums[0]) {
        ++k;
    }
    return k < n ? -1 : n - i;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2856. 删除数对后的最小数组长度](https://leetcode.cn/problems/minimum-array-length-after-pair-removals){#2856}

{{< tabs "2856" >}}

{{% tab "python" %}}
```python
class Solution:
    def minLengthAfterRemovals(self, nums: List[int]) -> int:
        cnt = Counter(nums)
        pq = [-x for x in cnt.values()]
        heapify(pq)
        ans = len(nums)
        while len(pq) > 1:
            x, y = -heappop(pq), -heappop(pq)
            x -= 1
            y -= 1
            if x > 0:
                heappush(pq, -x)
            if y > 0:
                heappush(pq, -y)
            ans -= 2
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minLengthAfterRemovals(List<Integer> nums) {
        Map<Integer, Integer> cnt = new HashMap<>();
        for (int x : nums) {
            cnt.merge(x, 1, Integer::sum);
        }
        PriorityQueue<Integer> pq = new PriorityQueue<>(Comparator.reverseOrder());
        for (int x : cnt.values()) {
            pq.offer(x);
        }
        int ans = nums.size();
        while (pq.size() > 1) {
            int x = pq.poll();
            int y = pq.poll();
            x--;
            y--;
            if (x > 0) {
                pq.offer(x);
            }
            if (y > 0) {
                pq.offer(y);
            }
            ans -= 2;
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
    int minLengthAfterRemovals(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (int x : nums) {
            ++cnt[x];
        }
        priority_queue<int> pq;
        for (auto& [_, v] : cnt) {
            pq.push(v);
        }
        int ans = nums.size();
        while (pq.size() > 1) {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            x--;
            y--;
            if (x > 0) {
                pq.push(x);
            }
            if (y > 0) {
                pq.push(y);
            }
            ans -= 2;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minLengthAfterRemovals(nums []int) int {
	cnt := map[int]int{}
	for _, x := range nums {
		cnt[x]++
	}
	h := &hp{}
	for _, x := range cnt {
		h.push(x)
	}
	ans := len(nums)
	for h.Len() > 1 {
		x, y := h.pop(), h.pop()
		if x > 1 {
			h.push(x - 1)
		}
		if y > 1 {
			h.push(y - 1)
		}
		ans -= 2
	}
	return ans
}

type hp struct{ sort.IntSlice }

func (h hp) Less(i, j int) bool { return h.IntSlice[i] > h.IntSlice[j] }
func (h *hp) Push(v any)        { h.IntSlice = append(h.IntSlice, v.(int)) }
func (h *hp) Pop() any {
	a := h.IntSlice
	v := a[len(a)-1]
	h.IntSlice = a[:len(a)-1]
	return v
}
func (h *hp) push(v int) { heap.Push(h, v) }
func (h *hp) pop() int   { return heap.Pop(h).(int) }
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minLengthAfterRemovals(nums: number[]): number {
    const cnt: Map<number, number> = new Map();
    for (const x of nums) {
        cnt.set(x, (cnt.get(x) ?? 0) + 1);
    }
    const pq = new MaxPriorityQueue<number>();
    for (const [_, v] of cnt) {
        pq.enqueue(v);
    }
    let ans = nums.length;
    while (pq.size() > 1) {
        let x = pq.dequeue();
        let y = pq.dequeue();
        if (--x > 0) {
            pq.enqueue(x);
        }
        if (--y > 0) {
            pq.enqueue(y);
        }
        ans -= 2;
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

<p>给你一个下标从 <strong>0</strong> 开始的 <strong>非递减</strong> 整数数组&nbsp;<code>nums</code>&nbsp;。</p>

<p>你可以执行以下操作任意次：</p>

<ul>
	<li>选择 <strong>两个&nbsp;</strong>下标&nbsp;<code>i</code> 和&nbsp;<code>j</code>&nbsp;，满足&nbsp;<code>nums[i] &lt; nums[j]</code>&nbsp;。</li>
	<li>将 <code>nums</code>&nbsp;中下标在&nbsp;<code>i</code> 和&nbsp;<code>j</code>&nbsp;处的元素删除。剩余元素按照原来的顺序组成新的数组，下标也重新从 <strong>0</strong>&nbsp;开始编号。</li>
</ul>

<p>请你返回一个整数，表示执行以上操作任意次后（可以执行 <strong>0</strong> 次），<code>nums</code>&nbsp;数组的 <strong>最小</strong>&nbsp;数组长度。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">nums = [1,2,3,4]</span></p>

<p><strong>输出：</strong><span class="example-io">0</span></p>

<p><strong>解释：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2800-2899/2856.Minimum%20Array%20Length%20After%20Pair%20Removals/images/1716779983-AHhkVn-tcase1.gif" style="width: 160px; height: 70px;" /></p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">nums = [1,1,2,2,3,3]</span></p>

<p><strong>输出：</strong><span class="example-io">0</span></p>

<p><strong>解释：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2800-2899/2856.Minimum%20Array%20Length%20After%20Pair%20Removals/images/1716779979-GyQhVf-tcase2.gif" style="width: 240px; height: 70px;" /></p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">nums = [1000000000,1000000000]</span></p>

<p><strong>输出：</strong><span class="example-io">2</span></p>

<p><strong>解释：</strong></p>

<p>由于两个数字相等，不能删除它们。</p>
</div>

<p><strong class="example">示例 4：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">nums = [2,3,4,4,4]</span></p>

<p><strong>输出：</strong><span class="example-io">1</span></p>

<p><strong>解释：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2800-2899/2856.Minimum%20Array%20Length%20After%20Pair%20Removals/images/1716779940-qRRlHk-tcase3.gif" style="width: 210px; height: 70px;" /></p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>nums</code>&nbsp;是 <strong>非递减</strong>&nbsp;数组。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 优先队列（大根堆）

我们用一个哈希表 $cnt$ 统计数组 $nums$ 中每个元素的出现次数，然后将 $cnt$ 中的每个值加入一个优先队列（大根堆） $pq$ 中。每次从 $pq$ 中取出两个元素 $x$ 和 $y$，将它们的值减一，如果减一后的值仍大于 $0$，则将减一后的值重新加入 $pq$。每次从 $pq$ 中取出两个元素，表示将数组中的两个数对删除，因此数组的长度减少 $2$。当 $pq$ 的大小小于 $2$ 时，停止删除操作。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minLengthAfterRemovals(self, nums: List[int]) -> int:
        cnt = Counter(nums)
        pq = [-x for x in cnt.values()]
        heapify(pq)
        ans = len(nums)
        while len(pq) > 1:
            x, y = -heappop(pq), -heappop(pq)
            x -= 1
            y -= 1
            if x > 0:
                heappush(pq, -x)
            if y > 0:
                heappush(pq, -y)
            ans -= 2
        return ans
```

#### Java

```java
class Solution {
    public int minLengthAfterRemovals(List<Integer> nums) {
        Map<Integer, Integer> cnt = new HashMap<>();
        for (int x : nums) {
            cnt.merge(x, 1, Integer::sum);
        }
        PriorityQueue<Integer> pq = new PriorityQueue<>(Comparator.reverseOrder());
        for (int x : cnt.values()) {
            pq.offer(x);
        }
        int ans = nums.size();
        while (pq.size() > 1) {
            int x = pq.poll();
            int y = pq.poll();
            x--;
            y--;
            if (x > 0) {
                pq.offer(x);
            }
            if (y > 0) {
                pq.offer(y);
            }
            ans -= 2;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (int x : nums) {
            ++cnt[x];
        }
        priority_queue<int> pq;
        for (auto& [_, v] : cnt) {
            pq.push(v);
        }
        int ans = nums.size();
        while (pq.size() > 1) {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            x--;
            y--;
            if (x > 0) {
                pq.push(x);
            }
            if (y > 0) {
                pq.push(y);
            }
            ans -= 2;
        }
        return ans;
    }
};
```

#### Go

```go
func minLengthAfterRemovals(nums []int) int {
	cnt := map[int]int{}
	for _, x := range nums {
		cnt[x]++
	}
	h := &hp{}
	for _, x := range cnt {
		h.push(x)
	}
	ans := len(nums)
	for h.Len() > 1 {
		x, y := h.pop(), h.pop()
		if x > 1 {
			h.push(x - 1)
		}
		if y > 1 {
			h.push(y - 1)
		}
		ans -= 2
	}
	return ans
}

type hp struct{ sort.IntSlice }

func (h hp) Less(i, j int) bool { return h.IntSlice[i] > h.IntSlice[j] }
func (h *hp) Push(v any)        { h.IntSlice = append(h.IntSlice, v.(int)) }
func (h *hp) Pop() any {
	a := h.IntSlice
	v := a[len(a)-1]
	h.IntSlice = a[:len(a)-1]
	return v
}
func (h *hp) push(v int) { heap.Push(h, v) }
func (h *hp) pop() int   { return heap.Pop(h).(int) }
```

#### TypeScript

```ts
function minLengthAfterRemovals(nums: number[]): number {
    const cnt: Map<number, number> = new Map();
    for (const x of nums) {
        cnt.set(x, (cnt.get(x) ?? 0) + 1);
    }
    const pq = new MaxPriorityQueue<number>();
    for (const [_, v] of cnt) {
        pq.enqueue(v);
    }
    let ans = nums.length;
    while (pq.size() > 1) {
        let x = pq.dequeue();
        let y = pq.dequeue();
        if (--x > 0) {
            pq.enqueue(x);
        }
        if (--y > 0) {
            pq.enqueue(y);
        }
        ans -= 2;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2857. 统计距离为 k 的点对](https://leetcode.cn/problems/count-pairs-of-points-with-distance-k){#2857}

{{< tabs "2857" >}}

{{% tab "python" %}}
```python
class Solution:
    def countPairs(self, coordinates: List[List[int]], k: int) -> int:
        cnt = Counter()
        ans = 0
        for x2, y2 in coordinates:
            for a in range(k + 1):
                b = k - a
                x1, y1 = a ^ x2, b ^ y2
                ans += cnt[(x1, y1)]
            cnt[(x2, y2)] += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countPairs(List<List<Integer>> coordinates, int k) {
        Map<List<Integer>, Integer> cnt = new HashMap<>();
        int ans = 0;
        for (var c : coordinates) {
            int x2 = c.get(0), y2 = c.get(1);
            for (int a = 0; a <= k; ++a) {
                int b = k - a;
                int x1 = a ^ x2, y1 = b ^ y2;
                ans += cnt.getOrDefault(List.of(x1, y1), 0);
            }
            cnt.merge(c, 1, Integer::sum);
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
    int countPairs(vector<vector<int>>& coordinates, int k) {
        map<pair<int, int>, int> cnt;
        int ans = 0;
        for (auto& c : coordinates) {
            int x2 = c[0], y2 = c[1];
            for (int a = 0; a <= k; ++a) {
                int b = k - a;
                int x1 = a ^ x2, y1 = b ^ y2;
                ans += cnt[{x1, y1}];
            }
            ++cnt[{x2, y2}];
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countPairs(coordinates [][]int, k int) (ans int) {
	cnt := map[[2]int]int{}
	for _, c := range coordinates {
		x2, y2 := c[0], c[1]
		for a := 0; a <= k; a++ {
			b := k - a
			x1, y1 := a^x2, b^y2
			ans += cnt[[2]int{x1, y1}]
		}
		cnt[[2]int{x2, y2}]++
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countPairs(coordinates: number[][], k: number): number {
    const cnt: Map<number, number> = new Map();
    const f = (x: number, y: number): number => x * 1000000 + y;
    let ans = 0;
    for (const [x2, y2] of coordinates) {
        for (let a = 0; a <= k; ++a) {
            const b = k - a;
            const [x1, y1] = [a ^ x2, b ^ y2];
            ans += cnt.get(f(x1, y1)) ?? 0;
        }
        cnt.set(f(x2, y2), (cnt.get(f(x2, y2)) ?? 0) + 1);
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

<p>给你一个 <strong>二维</strong>&nbsp;整数数组&nbsp;<code>coordinates</code>&nbsp;和一个整数&nbsp;<code>k</code>&nbsp;，其中&nbsp;<code>coordinates[i] = [x<sub>i</sub>, y<sub>i</sub>]</code>&nbsp;是第 <code>i</code>&nbsp;个点在二维平面里的坐标。</p>

<p>我们定义两个点&nbsp;<code>(x<sub>1</sub>, y<sub>1</sub>)</code>&nbsp;和&nbsp;<code>(x<sub>2</sub>, y<sub>2</sub>)</code>&nbsp;的 <strong>距离</strong>&nbsp;为&nbsp;<code>(x1 XOR x2) + (y1 XOR y2)</code> ，<code>XOR</code>&nbsp;指的是按位异或运算。</p>

<p>请你返回满足<em>&nbsp;</em><code>i &lt; j</code><em>&nbsp;</em>且点<em>&nbsp;</em><code>i</code><em> </em>和点<em>&nbsp;</em><code>j</code>之间距离为<em>&nbsp;</em><code>k</code>&nbsp;的点对数目。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>coordinates = [[1,2],[4,2],[1,3],[5,2]], k = 5
<b>输出：</b>2
<b>解释：</b>以下点对距离为 k ：
- (0, 1)：(1 XOR 4) + (2 XOR 2) = 5 。
- (2, 3)：(1 XOR 5) + (3 XOR 2) = 5 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>coordinates = [[1,3],[1,3],[1,3],[1,3],[1,3]], k = 0
<b>输出：</b>10
<b>解释：</b>任何两个点之间的距离都为 0 ，所以总共有 10 组点对。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= coordinates.length &lt;= 50000</code></li>
	<li><code>0 &lt;= x<sub>i</sub>, y<sub>i</sub> &lt;= 10<sup>6</sup></code></li>
	<li><code>0 &lt;= k &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 枚举

我们可以用一个哈希表 $cnt$ 统计数组 $coordinates$ 中每个点出现的次数。

接下来，我们枚举数组 $coordinates$ 中的每个点 $(x_2, y_2)$，由于 $k$ 的取值范围为 $[0, 100]$，而 $x_1 \oplus x_2$ 或 $y_1 \oplus y_2$ 的结果一定大于等于 $0$，因此我们可以在 $[0,..k]$ 范围内枚举 $x_1 \oplus x_2$ 的结果 $a$，那么 $y_1 \oplus y_2$ 的结果就是 $b = k - a$。这样一来，我们就可以计算出 $x_1$ 和 $y_1$ 的值，将 $(x_1, y_1)$ 出现的次数累加到答案中。

时间复杂度 $O(n \times k)$，空间复杂度 $O(n)$。其中 $n$ 是数组 $coordinates$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countPairs(self, coordinates: List[List[int]], k: int) -> int:
        cnt = Counter()
        ans = 0
        for x2, y2 in coordinates:
            for a in range(k + 1):
                b = k - a
                x1, y1 = a ^ x2, b ^ y2
                ans += cnt[(x1, y1)]
            cnt[(x2, y2)] += 1
        return ans
```

#### Java

```java
class Solution {
    public int countPairs(List<List<Integer>> coordinates, int k) {
        Map<List<Integer>, Integer> cnt = new HashMap<>();
        int ans = 0;
        for (var c : coordinates) {
            int x2 = c.get(0), y2 = c.get(1);
            for (int a = 0; a <= k; ++a) {
                int b = k - a;
                int x1 = a ^ x2, y1 = b ^ y2;
                ans += cnt.getOrDefault(List.of(x1, y1), 0);
            }
            cnt.merge(c, 1, Integer::sum);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int countPairs(vector<vector<int>>& coordinates, int k) {
        map<pair<int, int>, int> cnt;
        int ans = 0;
        for (auto& c : coordinates) {
            int x2 = c[0], y2 = c[1];
            for (int a = 0; a <= k; ++a) {
                int b = k - a;
                int x1 = a ^ x2, y1 = b ^ y2;
                ans += cnt[{x1, y1}];
            }
            ++cnt[{x2, y2}];
        }
        return ans;
    }
};
```

#### Go

```go
func countPairs(coordinates [][]int, k int) (ans int) {
	cnt := map[[2]int]int{}
	for _, c := range coordinates {
		x2, y2 := c[0], c[1]
		for a := 0; a <= k; a++ {
			b := k - a
			x1, y1 := a^x2, b^y2
			ans += cnt[[2]int{x1, y1}]
		}
		cnt[[2]int{x2, y2}]++
	}
	return
}
```

#### TypeScript

```ts
function countPairs(coordinates: number[][], k: number): number {
    const cnt: Map<number, number> = new Map();
    const f = (x: number, y: number): number => x * 1000000 + y;
    let ans = 0;
    for (const [x2, y2] of coordinates) {
        for (let a = 0; a <= k; ++a) {
            const b = k - a;
            const [x1, y1] = [a ^ x2, b ^ y2];
            ans += cnt.get(f(x1, y1)) ?? 0;
        }
        cnt.set(f(x2, y2), (cnt.get(f(x2, y2)) ?? 0) + 1);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2858. 可以到达每一个节点的最少边反转次数](https://leetcode.cn/problems/minimum-edge-reversals-so-every-node-is-reachable){#2858}

{{< tabs "2858" >}}

{{% tab "python" %}}
```python
class Solution:
    def minEdgeReversals(self, n: int, edges: List[List[int]]) -> List[int]:
        ans = [0] * n
        g = [[] for _ in range(n)]
        for x, y in edges:
            g[x].append((y, 1))
            g[y].append((x, -1))

        def dfs(i: int, fa: int):
            for j, k in g[i]:
                if j != fa:
                    ans[0] += int(k < 0)
                    dfs(j, i)

        dfs(0, -1)

        def dfs2(i: int, fa: int):
            for j, k in g[i]:
                if j != fa:
                    ans[j] = ans[i] + k
                    dfs2(j, i)

        dfs2(0, -1)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private List<int[]>[] g;
    private int[] ans;

    public int[] minEdgeReversals(int n, int[][] edges) {
        ans = new int[n];
        g = new List[n];
        Arrays.setAll(g, i -> new ArrayList<>());
        for (var e : edges) {
            int x = e[0], y = e[1];
            g[x].add(new int[] {y, 1});
            g[y].add(new int[] {x, -1});
        }
        dfs(0, -1);
        dfs2(0, -1);
        return ans;
    }

    private void dfs(int i, int fa) {
        for (var ne : g[i]) {
            int j = ne[0], k = ne[1];
            if (j != fa) {
                ans[0] += k < 0 ? 1 : 0;
                dfs(j, i);
            }
        }
    }

    private void dfs2(int i, int fa) {
        for (var ne : g[i]) {
            int j = ne[0], k = ne[1];
            if (j != fa) {
                ans[j] = ans[i] + k;
                dfs2(j, i);
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
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        vector<pair<int, int>> g[n];
        vector<int> ans(n);
        for (auto& e : edges) {
            int x = e[0], y = e[1];
            g[x].emplace_back(y, 1);
            g[y].emplace_back(x, -1);
        }
        function<void(int, int)> dfs = [&](int i, int fa) {
            for (auto& [j, k] : g[i]) {
                if (j != fa) {
                    ans[0] += k < 0;
                    dfs(j, i);
                }
            }
        };
        function<void(int, int)> dfs2 = [&](int i, int fa) {
            for (auto& [j, k] : g[i]) {
                if (j != fa) {
                    ans[j] = ans[i] + k;
                    dfs2(j, i);
                }
            }
        };
        dfs(0, -1);
        dfs2(0, -1);
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minEdgeReversals(n int, edges [][]int) []int {
	g := make([][][2]int, n)
	for _, e := range edges {
		x, y := e[0], e[1]
		g[x] = append(g[x], [2]int{y, 1})
		g[y] = append(g[y], [2]int{x, -1})
	}
	ans := make([]int, n)
	var dfs func(int, int)
	var dfs2 func(int, int)
	dfs = func(i, fa int) {
		for _, ne := range g[i] {
			j, k := ne[0], ne[1]
			if j != fa {
				if k < 0 {
					ans[0]++
				}
				dfs(j, i)
			}
		}
	}
	dfs2 = func(i, fa int) {
		for _, ne := range g[i] {
			j, k := ne[0], ne[1]
			if j != fa {
				ans[j] = ans[i] + k
				dfs2(j, i)
			}
		}
	}
	dfs(0, -1)
	dfs2(0, -1)
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minEdgeReversals(n: number, edges: number[][]): number[] {
    const g: number[][][] = Array.from({ length: n }, () => []);
    for (const [x, y] of edges) {
        g[x].push([y, 1]);
        g[y].push([x, -1]);
    }
    const ans: number[] = Array(n).fill(0);
    const dfs = (i: number, fa: number) => {
        for (const [j, k] of g[i]) {
            if (j !== fa) {
                ans[0] += k < 0 ? 1 : 0;
                dfs(j, i);
            }
        }
    };
    const dfs2 = (i: number, fa: number) => {
        for (const [j, k] of g[i]) {
            if (j !== fa) {
                ans[j] = ans[i] + k;
                dfs2(j, i);
            }
        }
    };
    dfs(0, -1);
    dfs2(0, -1);
    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个 <code>n</code>&nbsp;个点的 <strong>简单有向图</strong>&nbsp;（没有重复边的有向图），节点编号为 <code>0</code>&nbsp;到 <code>n - 1</code>&nbsp;。如果这些边是双向边，那么这个图形成一棵&nbsp;<strong>树</strong>&nbsp;。</p>

<p>给你一个整数&nbsp;<code>n</code>&nbsp;和一个 <strong>二维</strong>&nbsp;整数数组&nbsp;<code>edges</code>&nbsp;，其中&nbsp;<code>edges[i] = [u<sub>i</sub>, v<sub>i</sub>]</code>&nbsp;表示从节点&nbsp;<code>u<sub>i</sub></code>&nbsp;到节点&nbsp;<code>v<sub>i</sub></code>&nbsp;有一条&nbsp;<strong>有向边</strong>&nbsp;。</p>

<p><strong>边反转</strong>&nbsp;指的是将一条边的方向反转，也就是说一条从节点&nbsp;<code>u<sub>i</sub></code>&nbsp;到节点&nbsp;<code>v<sub>i</sub></code>&nbsp;的边会变为一条从节点&nbsp;<code>v<sub>i</sub></code>&nbsp;到节点&nbsp;<code>u<sub>i</sub></code>&nbsp;的边。</p>

<p>对于范围&nbsp;<code>[0, n - 1]</code>&nbsp;中的每一个节点 <code>i</code>&nbsp;，你的任务是分别 <strong>独立</strong> 计算 <strong>最少</strong>&nbsp;需要多少次 <strong>边反转</strong>&nbsp;，从节点 <code>i</code>&nbsp;出发经过 <strong>一系列有向边</strong>&nbsp;，可以到达所有的节点。</p>

<p>请你返回一个长度为 <code>n</code>&nbsp;的整数数组<em>&nbsp;</em><code>answer</code><em>&nbsp;</em>，其中<em>&nbsp;</em><code>answer[i]</code>表示从节点&nbsp;<code>i</code>&nbsp;出发，可以到达所有节点的&nbsp;<strong>最少边反转</strong>&nbsp;次数。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<p><img height="246" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2800-2899/2858.Minimum%20Edge%20Reversals%20So%20Every%20Node%20Is%20Reachable/images/image-20230826221104-3.png" width="312" /></p>

<pre>
<b>输入：</b>n = 4, edges = [[2,0],[2,1],[1,3]]
<b>输出：</b>[1,1,0,2]
<b>解释：</b>上图表示了与输入对应的简单有向图。
对于节点 0 ：反转 [2,0] ，从节点 0 出发可以到达所有节点。
所以 answer[0] = 1 。
对于节点 1 ：反转 [2,1] ，从节点 1 出发可以到达所有节点。
所以 answer[1] = 1 。
对于节点 2 ：不需要反转就可以从节点 2 出发到达所有节点。
所以 answer[2] = 0 。
对于节点 3 ：反转 [1,3] 和 [2,1] ，从节点 3 出发可以到达所有节点。
所以 answer[3] = 2 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<p><img height="217" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2800-2899/2858.Minimum%20Edge%20Reversals%20So%20Every%20Node%20Is%20Reachable/images/image-20230826225541-2.png" width="322" /></p>

<pre>
<b>输入：</b>n = 3, edges = [[1,2],[2,0]]
<b>输出：</b>[2,0,1]
<b>解释：</b>上图表示了与输入对应的简单有向图。
对于节点 0 ：反转 [2,0] 和 [1,2] ，从节点 0 出发可以到达所有节点。
所以 answer[0] = 2 。
对于节点 1 ：不需要反转就可以从节点 2 出发到达所有节点。
所以 answer[1] = 0 。
对于节点 2 ：反转 [1,2] ，从节点 2 出发可以到达所有节点。
所以 answer[2] = 1 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>edges.length == n - 1</code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>0 &lt;= u<sub>i</sub> == edges[i][0] &lt; n</code></li>
	<li><code>0 &lt;= v<sub>i</sub> == edges[i][1] &lt; n</code></li>
	<li><code>u<sub>i</sub> != v<sub>i</sub></code></li>
	<li>输入保证如果边是双向边，可以得到一棵树。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：树形 DP

时间复杂度 $O(n)$，空间复杂度 $O(n)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minEdgeReversals(self, n: int, edges: List[List[int]]) -> List[int]:
        ans = [0] * n
        g = [[] for _ in range(n)]
        for x, y in edges:
            g[x].append((y, 1))
            g[y].append((x, -1))

        def dfs(i: int, fa: int):
            for j, k in g[i]:
                if j != fa:
                    ans[0] += int(k < 0)
                    dfs(j, i)

        dfs(0, -1)

        def dfs2(i: int, fa: int):
            for j, k in g[i]:
                if j != fa:
                    ans[j] = ans[i] + k
                    dfs2(j, i)

        dfs2(0, -1)
        return ans
```

#### Java

```java
class Solution {
    private List<int[]>[] g;
    private int[] ans;

    public int[] minEdgeReversals(int n, int[][] edges) {
        ans = new int[n];
        g = new List[n];
        Arrays.setAll(g, i -> new ArrayList<>());
        for (var e : edges) {
            int x = e[0], y = e[1];
            g[x].add(new int[] {y, 1});
            g[y].add(new int[] {x, -1});
        }
        dfs(0, -1);
        dfs2(0, -1);
        return ans;
    }

    private void dfs(int i, int fa) {
        for (var ne : g[i]) {
            int j = ne[0], k = ne[1];
            if (j != fa) {
                ans[0] += k < 0 ? 1 : 0;
                dfs(j, i);
            }
        }
    }

    private void dfs2(int i, int fa) {
        for (var ne : g[i]) {
            int j = ne[0], k = ne[1];
            if (j != fa) {
                ans[j] = ans[i] + k;
                dfs2(j, i);
            }
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        vector<pair<int, int>> g[n];
        vector<int> ans(n);
        for (auto& e : edges) {
            int x = e[0], y = e[1];
            g[x].emplace_back(y, 1);
            g[y].emplace_back(x, -1);
        }
        function<void(int, int)> dfs = [&](int i, int fa) {
            for (auto& [j, k] : g[i]) {
                if (j != fa) {
                    ans[0] += k < 0;
                    dfs(j, i);
                }
            }
        };
        function<void(int, int)> dfs2 = [&](int i, int fa) {
            for (auto& [j, k] : g[i]) {
                if (j != fa) {
                    ans[j] = ans[i] + k;
                    dfs2(j, i);
                }
            }
        };
        dfs(0, -1);
        dfs2(0, -1);
        return ans;
    }
};
```

#### Go

```go
func minEdgeReversals(n int, edges [][]int) []int {
	g := make([][][2]int, n)
	for _, e := range edges {
		x, y := e[0], e[1]
		g[x] = append(g[x], [2]int{y, 1})
		g[y] = append(g[y], [2]int{x, -1})
	}
	ans := make([]int, n)
	var dfs func(int, int)
	var dfs2 func(int, int)
	dfs = func(i, fa int) {
		for _, ne := range g[i] {
			j, k := ne[0], ne[1]
			if j != fa {
				if k < 0 {
					ans[0]++
				}
				dfs(j, i)
			}
		}
	}
	dfs2 = func(i, fa int) {
		for _, ne := range g[i] {
			j, k := ne[0], ne[1]
			if j != fa {
				ans[j] = ans[i] + k
				dfs2(j, i)
			}
		}
	}
	dfs(0, -1)
	dfs2(0, -1)
	return ans
}
```

#### TypeScript

```ts
function minEdgeReversals(n: number, edges: number[][]): number[] {
    const g: number[][][] = Array.from({ length: n }, () => []);
    for (const [x, y] of edges) {
        g[x].push([y, 1]);
        g[y].push([x, -1]);
    }
    const ans: number[] = Array(n).fill(0);
    const dfs = (i: number, fa: number) => {
        for (const [j, k] of g[i]) {
            if (j !== fa) {
                ans[0] += k < 0 ? 1 : 0;
                dfs(j, i);
            }
        }
    };
    const dfs2 = (i: number, fa: number) => {
        for (const [j, k] of g[i]) {
            if (j !== fa) {
                ans[j] = ans[i] + k;
                dfs2(j, i);
            }
        }
    };
    dfs(0, -1);
    dfs2(0, -1);
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2859. 计算 K 置位下标对应元素的和](https://leetcode.cn/problems/sum-of-values-at-indices-with-k-set-bits){#2859}

{{< tabs "2859" >}}

{{% tab "python" %}}
```python
class Solution:
    def sumIndicesWithKSetBits(self, nums: List[int], k: int) -> int:
        return sum(x for i, x in enumerate(nums) if i.bit_count() == k)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int sumIndicesWithKSetBits(List<Integer> nums, int k) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (Integer.bitCount(i) == k) {
                ans += nums.get(i);
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
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (__builtin_popcount(i) == k) {
                ans += nums[i];
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func sumIndicesWithKSetBits(nums []int, k int) (ans int) {
	for i, x := range nums {
		if bits.OnesCount(uint(i)) == k {
			ans += x
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function sumIndicesWithKSetBits(nums: number[], k: number): number {
    let ans = 0;
    for (let i = 0; i < nums.length; ++i) {
        if (bitCount(i) === k) {
            ans += nums[i];
        }
    }
    return ans;
}

function bitCount(n: number): number {
    let count = 0;
    while (n) {
        n &= n - 1;
        count++;
    }
    return count;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong> 开始的整数数组 <code>nums</code> 和一个整数 <code>k</code> 。</p>

<p>请你用整数形式返回 <code>nums</code> 中的特定元素之 <strong>和</strong> ，这些特定元素满足：其对应下标的二进制表示中恰存在 <code>k</code> 个置位。</p>

<p>整数的二进制表示中的 1 就是这个整数的 <strong>置位</strong> 。</p>

<p>例如，<code>21</code> 的二进制表示为 <code>10101</code> ，其中有 <code>3</code> 个置位。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [5,10,1,5,2], k = 1
<strong>输出：</strong>13
<strong>解释：</strong>下标的二进制表示是： 
0 = 000<sub>2</sub>
1 = 001<sub>2</sub>
2 = 010<sub>2</sub>
3 = 011<sub>2</sub>
4 = 100<sub>2 
</sub>下标 1、2 和 4 在其二进制表示中都存在 k = 1 个置位。
因此，答案为 nums[1] + nums[2] + nums[4] = 13 。</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [4,3,2,1], k = 2
<strong>输出：</strong>1
<strong>解释：</strong>下标的二进制表示是： 
0 = 00<sub>2</sub>
1 = 01<sub>2</sub>
2 = 10<sub>2</sub>
3 = 11<sub>2
</sub>只有下标 3 的二进制表示中存在 k = 2 个置位。
因此，答案为 nums[3] = 1 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= k &lt;= 10</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们直接遍历每个下标 $i$，判断其二进制表示中 $1$ 的个数是否等于 $k$，如果等于则将其对应的元素累加到答案 $ans$ 中。

遍历结束后，返回答案即可。

时间复杂度 $O(n \times \log n)$，其中 $n$ 是数组 $nums$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def sumIndicesWithKSetBits(self, nums: List[int], k: int) -> int:
        return sum(x for i, x in enumerate(nums) if i.bit_count() == k)
```

#### Java

```java
class Solution {
    public int sumIndicesWithKSetBits(List<Integer> nums, int k) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (Integer.bitCount(i) == k) {
                ans += nums.get(i);
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
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (__builtin_popcount(i) == k) {
                ans += nums[i];
            }
        }
        return ans;
    }
};
```

#### Go

```go
func sumIndicesWithKSetBits(nums []int, k int) (ans int) {
	for i, x := range nums {
		if bits.OnesCount(uint(i)) == k {
			ans += x
		}
	}
	return
}
```

#### TypeScript

```ts
function sumIndicesWithKSetBits(nums: number[], k: number): number {
    let ans = 0;
    for (let i = 0; i < nums.length; ++i) {
        if (bitCount(i) === k) {
            ans += nums[i];
        }
    }
    return ans;
}

function bitCount(n: number): number {
    let count = 0;
    while (n) {
        n &= n - 1;
        count++;
    }
    return count;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
