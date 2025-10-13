---
title: "0840_矩阵中的幻方"
date: 2025-10-08T18:36:34+08:00
weight: 5
tags: [交互, 位运算, 前缀和, 动态规划, 博弈, 双指针, 哈希表, 回溯, 图, 字符串, 广度优先搜索, 排序, 数学, 数组, 枚举, 栈, 模拟, 深度优先搜索, 状态压缩, 矩阵, 贪心]
---

{{< markmap >}}
### [0840_矩阵中的幻方](#840)
#### [数组](#840)
#### [哈希表](#840)
#### [数学](#840)
#### [矩阵](#840)
### [0841_钥匙和房间](#841)
#### [深度优先搜索](#841)
#### [广度优先搜索](#841)
#### [图](#841)
### [0842_将数组拆分成斐波那契序列](#842)
#### [字符串](#842)
#### [回溯](#842)
### [0843_猜猜这个单词](#843)
#### [数组](#843)
#### [数学](#843)
#### [字符串](#843)
#### [博弈](#843)
#### [交互](#843)
### [0844_比较含退格的字符串](#844)
#### [栈](#844)
#### [双指针](#844)
#### [字符串](#844)
#### [模拟](#844)
### [0845_数组中的最长山脉](#845)
#### [数组](#845)
#### [双指针](#845)
#### [动态规划](#845)
#### [枚举](#845)
### [0846_一手顺子](#846)
#### [贪心](#846)
#### [数组](#846)
#### [哈希表](#846)
#### [排序](#846)
### [0847_访问所有节点的最短路径](#847)
#### [位运算](#847)
#### [广度优先搜索](#847)
#### [图](#847)
#### [动态规划](#847)
#### [状态压缩](#847)
### [0848_字母移位](#848)
#### [数组](#848)
#### [字符串](#848)
#### [前缀和](#848)
### [0849_到最近的人的最大距离](#849)
#### [数组](#849)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0840_矩阵中的幻方
___
#### 数组
___
#### 哈希表
___
#### 数学
___
#### 矩阵
---
### 0841_钥匙和房间
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 图
---
### 0842_将数组拆分成斐波那契序列
___
#### 字符串
___
#### 回溯
---
### 0843_猜猜这个单词
___
#### 数组
___
#### 数学
___
#### 字符串
___
#### 博弈
___
#### 交互
---
### 0844_比较含退格的字符串
___
#### 栈
___
#### 双指针
___
#### 字符串
___
#### 模拟
---
### 0845_数组中的最长山脉
___
#### 数组
___
#### 双指针
___
#### 动态规划
___
#### 枚举
---
### 0846_一手顺子
___
#### 贪心
___
#### 数组
___
#### 哈希表
___
#### 排序
---
### 0847_访问所有节点的最短路径
___
#### 位运算
___
#### 广度优先搜索
___
#### 图
___
#### 动态规划
___
#### 状态压缩
---
### 0848_字母移位
___
#### 数组
___
#### 字符串
___
#### 前缀和
---
### 0849_到最近的人的最大距离
___
#### 数组
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 交互 | 位运算 | 前缀和 |
| 动态规划 | 博弈 | 双指针 |
| 哈希表 | 回溯 | 图 |
| 字符串 | 广度优先搜索 | 排序 |
| 数学 | 数组 | 枚举 |
| 栈 | 模拟 | 深度优先搜索 |
| 状态压缩 | 矩阵 | 贪心 |

# [840. 矩阵中的幻方](https://leetcode.cn/problems/magic-squares-in-grid){#840}

{{< tabs "840" >}}

{{% tab "python" %}}
```python
class Solution:
    def numMagicSquaresInside(self, grid: List[List[int]]) -> int:
        def check(i: int, j: int) -> int:
            if i + 3 > m or j + 3 > n:
                return 0
            s = set()
            row = [0] * 3
            col = [0] * 3
            a = b = 0
            for x in range(i, i + 3):
                for y in range(j, j + 3):
                    v = grid[x][y]
                    if v < 1 or v > 9:
                        return 0
                    s.add(v)
                    row[x - i] += v
                    col[y - j] += v
                    if x - i == y - j:
                        a += v
                    if x - i == 2 - (y - j):
                        b += v
            if len(s) != 9 or a != b:
                return 0
            if any(x != a for x in row) or any(x != a for x in col):
                return 0
            return 1

        m, n = len(grid), len(grid[0])
        return sum(check(i, j) for i in range(m) for j in range(n))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int m;
    private int n;
    private int[][] grid;

    public int numMagicSquaresInside(int[][] grid) {
        m = grid.length;
        n = grid[0].length;
        this.grid = grid;
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans += check(i, j);
            }
        }
        return ans;
    }

    private int check(int i, int j) {
        if (i + 3 > m || j + 3 > n) {
            return 0;
        }
        int[] cnt = new int[16];
        int[] row = new int[3];
        int[] col = new int[3];
        int a = 0, b = 0;
        for (int x = i; x < i + 3; ++x) {
            for (int y = j; y < j + 3; ++y) {
                int v = grid[x][y];
                if (v < 1 || v > 9 || ++cnt[v] > 1) {
                    return 0;
                }
                row[x - i] += v;
                col[y - j] += v;
                if (x - i == y - j) {
                    a += v;
                }
                if (x - i + y - j == 2) {
                    b += v;
                }
            }
        }
        if (a != b) {
            return 0;
        }
        for (int k = 0; k < 3; ++k) {
            if (row[k] != a || col[k] != a) {
                return 0;
            }
        }
        return 1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        auto check = [&](int i, int j) {
            if (i + 3 > m || j + 3 > n) {
                return 0;
            }
            vector<int> cnt(16);
            vector<int> row(3);
            vector<int> col(3);
            int a = 0, b = 0;
            for (int x = i; x < i + 3; ++x) {
                for (int y = j; y < j + 3; ++y) {
                    int v = grid[x][y];
                    if (v < 1 || v > 9 || ++cnt[v] > 1) {
                        return 0;
                    }
                    row[x - i] += v;
                    col[y - j] += v;
                    if (x - i == y - j) {
                        a += v;
                    }
                    if (x - i + y - j == 2) {
                        b += v;
                    }
                }
            }
            if (a != b) {
                return 0;
            }
            for (int k = 0; k < 3; ++k) {
                if (row[k] != a || col[k] != a) {
                    return 0;
                }
            }
            return 1;
        };
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans += check(i, j);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numMagicSquaresInside(grid [][]int) (ans int) {
	m, n := len(grid), len(grid[0])
	check := func(i, j int) int {
		if i+3 > m || j+3 > n {
			return 0
		}
		cnt := [16]int{}
		row := [3]int{}
		col := [3]int{}
		a, b := 0, 0
		for x := i; x < i+3; x++ {
			for y := j; y < j+3; y++ {
				v := grid[x][y]
				if v < 1 || v > 9 || cnt[v] > 0 {
					return 0
				}
				cnt[v]++
				row[x-i] += v
				col[y-j] += v
				if x-i == y-j {
					a += v
				}
				if x-i == 2-(y-j) {
					b += v
				}
			}
		}
		if a != b {
			return 0
		}
		for k := 0; k < 3; k++ {
			if row[k] != a || col[k] != a {
				return 0
			}
		}
		return 1
	}
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			ans += check(i, j)
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
export function numMagicSquaresInside(grid: number[][]): number {
    const [m, n] = [grid.length, grid[0].length];
    if (m < 3 || n < 3) return 0;

    const check = (y: number, x: number) => {
        const g = grid;
        if (g[y + 1][x + 1] !== 5) return 0;

        const cells = [
            g[y][x],
            g[y][x + 1],
            g[y][x + 2],
            g[y + 1][x + 2],
            g[y + 2][x + 2],
            g[y + 2][x + 1],
            g[y + 2][x],
            g[y + 1][x],
        ];

        const i = cells.indexOf(2);
        if (i === -1) return 0;
        cells.push(...cells.splice(0, i));

        const circle = [2, 9, 4, 3, 8, 1, 6, 7];
        const reverseCircle = [2, 7, 6, 1, 8, 3, 4, 9];

        if (cells.every((x, i) => x === circle[i])) return 1;
        if (cells.every((x, i) => x === reverseCircle[i])) return 1;

        return 0;
    };

    let res = 0;
    for (let i = 0; i < m - 2; i++) {
        for (let j = 0; j < n - 2; j++) {
            res += check(i, j);
        }
    }

    return res;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
function numMagicSquaresInside(grid) {
    const [m, n] = [grid.length, grid[0].length];
    if (m < 3 || n < 3) return 0;

    const check = (y, x) => {
        const g = grid;
        if (g[y + 1][x + 1] !== 5) return false;

        const cells = [
            g[y][x],
            g[y][x + 1],
            g[y][x + 2],
            g[y + 1][x + 2],
            g[y + 2][x + 2],
            g[y + 2][x + 1],
            g[y + 2][x],
            g[y + 1][x],
        ];

        const i = cells.indexOf(2);
        if (i === -1) return false;
        cells.push(...cells.splice(0, i));

        const circle = [2, 9, 4, 3, 8, 1, 6, 7];
        const reverseCircle = [2, 7, 6, 1, 8, 3, 4, 9];

        if (cells.every((x, i) => x === circle[i])) return true;
        if (cells.every((x, i) => x === reverseCircle[i])) return true;

        return false;
    };

    let res = 0;
    for (let i = 0; i < m - 2; i++) {
        for (let j = 0; j < n - 2; j++) {
            res += +check(i, j);
        }
    }

    return res;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p><code>3 x 3</code> 的幻方是一个填充有&nbsp;<strong>从 <code>1</code> 到 <code>9</code>&nbsp;</strong> 的不同数字的 <code>3 x 3</code> 矩阵，其中每行，每列以及两条对角线上的各数之和都相等。</p>

<p>给定一个由整数组成的<code>row x col</code>&nbsp;的 <code>grid</code>，其中有多少个&nbsp;<code>3 × 3</code> 的 “幻方” 子矩阵？</p>

<p>注意：虽然幻方只能包含 1 到 9 的数字，但&nbsp;<code>grid</code> 可以包含最多15的数字。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0800-0899/0840.Magic%20Squares%20In%20Grid/images/magic_main.jpg" /></p>

<pre>
<strong>输入: </strong>grid = [[4,3,8,4],[9,5,1,9],[2,7,6,2]
<strong>输出: </strong>1
<strong>解释: </strong>
下面的子矩阵是一个 3 x 3 的幻方：
<img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0800-0899/0840.Magic%20Squares%20In%20Grid/images/magic_valid.jpg" />
而这一个不是：
<img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0800-0899/0840.Magic%20Squares%20In%20Grid/images/magic_invalid.jpg" />
总的来说，在本示例所给定的矩阵中只有一个 3 x 3 的幻方子矩阵。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> grid = [[8]]
<strong>输出:</strong> 0
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>row == grid.length</code></li>
	<li><code>col == grid[i].length</code></li>
	<li><code>1 &lt;= row, col &lt;= 10</code></li>
	<li><code>0 &lt;= grid[i][j] &lt;= 15</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举

我们直接枚举每个 $3 \times 3$ 子矩阵的左上角坐标 $(i, j)$，然后判断该子矩阵是否满足“幻方矩阵”，若是，答案加一。枚举结束后，返回答案即可。

时间复杂度 $O(m \times n)$，其中 $m$ 和 $n$ 分别是矩阵的行数和列数。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numMagicSquaresInside(self, grid: List[List[int]]) -> int:
        def check(i: int, j: int) -> int:
            if i + 3 > m or j + 3 > n:
                return 0
            s = set()
            row = [0] * 3
            col = [0] * 3
            a = b = 0
            for x in range(i, i + 3):
                for y in range(j, j + 3):
                    v = grid[x][y]
                    if v < 1 or v > 9:
                        return 0
                    s.add(v)
                    row[x - i] += v
                    col[y - j] += v
                    if x - i == y - j:
                        a += v
                    if x - i == 2 - (y - j):
                        b += v
            if len(s) != 9 or a != b:
                return 0
            if any(x != a for x in row) or any(x != a for x in col):
                return 0
            return 1

        m, n = len(grid), len(grid[0])
        return sum(check(i, j) for i in range(m) for j in range(n))
```

#### Java

```java
class Solution {
    private int m;
    private int n;
    private int[][] grid;

    public int numMagicSquaresInside(int[][] grid) {
        m = grid.length;
        n = grid[0].length;
        this.grid = grid;
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans += check(i, j);
            }
        }
        return ans;
    }

    private int check(int i, int j) {
        if (i + 3 > m || j + 3 > n) {
            return 0;
        }
        int[] cnt = new int[16];
        int[] row = new int[3];
        int[] col = new int[3];
        int a = 0, b = 0;
        for (int x = i; x < i + 3; ++x) {
            for (int y = j; y < j + 3; ++y) {
                int v = grid[x][y];
                if (v < 1 || v > 9 || ++cnt[v] > 1) {
                    return 0;
                }
                row[x - i] += v;
                col[y - j] += v;
                if (x - i == y - j) {
                    a += v;
                }
                if (x - i + y - j == 2) {
                    b += v;
                }
            }
        }
        if (a != b) {
            return 0;
        }
        for (int k = 0; k < 3; ++k) {
            if (row[k] != a || col[k] != a) {
                return 0;
            }
        }
        return 1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        auto check = [&](int i, int j) {
            if (i + 3 > m || j + 3 > n) {
                return 0;
            }
            vector<int> cnt(16);
            vector<int> row(3);
            vector<int> col(3);
            int a = 0, b = 0;
            for (int x = i; x < i + 3; ++x) {
                for (int y = j; y < j + 3; ++y) {
                    int v = grid[x][y];
                    if (v < 1 || v > 9 || ++cnt[v] > 1) {
                        return 0;
                    }
                    row[x - i] += v;
                    col[y - j] += v;
                    if (x - i == y - j) {
                        a += v;
                    }
                    if (x - i + y - j == 2) {
                        b += v;
                    }
                }
            }
            if (a != b) {
                return 0;
            }
            for (int k = 0; k < 3; ++k) {
                if (row[k] != a || col[k] != a) {
                    return 0;
                }
            }
            return 1;
        };
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans += check(i, j);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func numMagicSquaresInside(grid [][]int) (ans int) {
	m, n := len(grid), len(grid[0])
	check := func(i, j int) int {
		if i+3 > m || j+3 > n {
			return 0
		}
		cnt := [16]int{}
		row := [3]int{}
		col := [3]int{}
		a, b := 0, 0
		for x := i; x < i+3; x++ {
			for y := j; y < j+3; y++ {
				v := grid[x][y]
				if v < 1 || v > 9 || cnt[v] > 0 {
					return 0
				}
				cnt[v]++
				row[x-i] += v
				col[y-j] += v
				if x-i == y-j {
					a += v
				}
				if x-i == 2-(y-j) {
					b += v
				}
			}
		}
		if a != b {
			return 0
		}
		for k := 0; k < 3; k++ {
			if row[k] != a || col[k] != a {
				return 0
			}
		}
		return 1
	}
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			ans += check(i, j)
		}
	}
	return
}
```

#### TypeScript

```ts
function numMagicSquaresInside(grid: number[][]): number {
    const m = grid.length;
    const n = grid[0].length;
    const check = (i: number, j: number): number => {
        if (i + 3 > m || j + 3 > n) {
            return 0;
        }
        const cnt: number[] = Array(16).fill(0);
        const row: number[] = Array(3).fill(0);
        const col: number[] = Array(3).fill(0);
        let [a, b] = [0, 0];
        for (let x = i; x < i + 3; ++x) {
            for (let y = j; y < j + 3; ++y) {
                const v = grid[x][y];
                if (v < 1 || v > 9 || ++cnt[v] > 1) {
                    return 0;
                }
                row[x - i] += v;
                col[y - j] += v;
                if (x - i === y - j) {
                    a += v;
                }
                if (x - i === 2 - (y - j)) {
                    b += v;
                }
            }
        }
        if (a !== b) {
            return 0;
        }
        for (let k = 0; k < 3; ++k) {
            if (row[k] !== a || col[k] !== a) {
                return 0;
            }
        }
        return 1;
    };
    let ans = 0;
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            ans += check(i, j);
        }
    }
    return ans;
}
```

#### JavaScript

```js
function numMagicSquaresInside(grid) {
    const m = grid.length;
    const n = grid[0].length;
    const check = (i, j) => {
        if (i + 3 > m || j + 3 > n) {
            return 0;
        }
        const cnt = Array(16).fill(0);
        const row = Array(3).fill(0);
        const col = Array(3).fill(0);
        let [a, b] = [0, 0];
        for (let x = i; x < i + 3; ++x) {
            for (let y = j; y < j + 3; ++y) {
                const v = grid[x][y];
                if (v < 1 || v > 9 || ++cnt[v] > 1) {
                    return 0;
                }
                row[x - i] += v;
                col[y - j] += v;
                if (x - i === y - j) {
                    a += v;
                }
                if (x - i === 2 - (y - j)) {
                    b += v;
                }
            }
        }
        if (a !== b) {
            return 0;
        }
        for (let k = 0; k < 3; ++k) {
            if (row[k] !== a || col[k] !== a) {
                return 0;
            }
        }
        return 1;
    };
    let ans = 0;
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            ans += check(i, j);
        }
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### Solution 2

<!-- tabs:start -->

#### TypeScript

```ts
export function numMagicSquaresInside(grid: number[][]): number {
    const [m, n] = [grid.length, grid[0].length];
    if (m < 3 || n < 3) return 0;

    const check = (y: number, x: number) => {
        const g = grid;
        if (g[y + 1][x + 1] !== 5) return 0;

        const cells = [
            g[y][x],
            g[y][x + 1],
            g[y][x + 2],
            g[y + 1][x + 2],
            g[y + 2][x + 2],
            g[y + 2][x + 1],
            g[y + 2][x],
            g[y + 1][x],
        ];

        const i = cells.indexOf(2);
        if (i === -1) return 0;
        cells.push(...cells.splice(0, i));

        const circle = [2, 9, 4, 3, 8, 1, 6, 7];
        const reverseCircle = [2, 7, 6, 1, 8, 3, 4, 9];

        if (cells.every((x, i) => x === circle[i])) return 1;
        if (cells.every((x, i) => x === reverseCircle[i])) return 1;

        return 0;
    };

    let res = 0;
    for (let i = 0; i < m - 2; i++) {
        for (let j = 0; j < n - 2; j++) {
            res += check(i, j);
        }
    }

    return res;
}
```

#### JavaScript

```js
function numMagicSquaresInside(grid) {
    const [m, n] = [grid.length, grid[0].length];
    if (m < 3 || n < 3) return 0;

    const check = (y, x) => {
        const g = grid;
        if (g[y + 1][x + 1] !== 5) return false;

        const cells = [
            g[y][x],
            g[y][x + 1],
            g[y][x + 2],
            g[y + 1][x + 2],
            g[y + 2][x + 2],
            g[y + 2][x + 1],
            g[y + 2][x],
            g[y + 1][x],
        ];

        const i = cells.indexOf(2);
        if (i === -1) return false;
        cells.push(...cells.splice(0, i));

        const circle = [2, 9, 4, 3, 8, 1, 6, 7];
        const reverseCircle = [2, 7, 6, 1, 8, 3, 4, 9];

        if (cells.every((x, i) => x === circle[i])) return true;
        if (cells.every((x, i) => x === reverseCircle[i])) return true;

        return false;
    };

    let res = 0;
    for (let i = 0; i < m - 2; i++) {
        for (let j = 0; j < n - 2; j++) {
            res += +check(i, j);
        }
    }

    return res;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [841. 钥匙和房间](https://leetcode.cn/problems/keys-and-rooms){#841}

{{< tabs "841" >}}

{{% tab "python" %}}
```python
class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        vis = set()
        q = deque([0])
        while q:
            i = q.popleft()
            if i in vis:
                continue
            vis.add(i)
            q.extend(j for j in rooms[i])
        return len(vis) == len(rooms)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean canVisitAllRooms(List<List<Integer>> rooms) {
        int n = rooms.size();
        boolean[] vis = new boolean[n];
        Deque<Integer> q = new ArrayDeque<>();
        q.offer(0);
        int cnt = 0;
        while (!q.isEmpty()) {
            int i = q.poll();
            if (vis[i]) {
                continue;
            }
            vis[i] = true;
            ++cnt;
            for (int j : rooms.get(i)) {
                q.offer(j);
            }
        }
        return cnt == n;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n);
        queue<int> q{{0}};
        int cnt = 0;
        while (q.size()) {
            int i = q.front();
            q.pop();
            if (vis[i]) {
                continue;
            }
            vis[i] = true;
            ++cnt;
            for (int j : rooms[i]) {
                q.push(j);
            }
        }
        return cnt == n;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func canVisitAllRooms(rooms [][]int) bool {
	n := len(rooms)
	vis := make([]bool, n)
	cnt := 0
	q := []int{0}
	for len(q) > 0 {
		i := q[0]
		q = q[1:]
		if vis[i] {
			continue
		}
		vis[i] = true
		cnt++
		for _, j := range rooms[i] {
			q = append(q, j)
		}
	}
	return cnt == n
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function canVisitAllRooms(rooms: number[][]): boolean {
    const vis = new Set<number>();
    const q: number[] = [0];

    while (q.length) {
        const i = q.pop()!;
        if (vis.has(i)) {
            continue;
        }
        vis.add(i);
        q.push(...rooms[i]);
    }

    return vis.size == rooms.length;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn can_visit_all_rooms(rooms: Vec<Vec<i32>>) -> bool {
        let n = rooms.len();
        let mut is_open = vec![false; n];
        let mut keys = vec![0];
        while !keys.is_empty() {
            let i = keys.pop().unwrap();
            if is_open[i] {
                continue;
            }
            is_open[i] = true;
            rooms[i].iter().for_each(|&key| keys.push(key as usize));
        }
        is_open.iter().all(|&v| v)
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>有 <code>n</code> 个房间，房间按从 <code>0</code> 到 <code>n - 1</code> 编号。最初，除 <code>0</code> 号房间外的其余所有房间都被锁住。你的目标是进入所有的房间。然而，你不能在没有获得钥匙的时候进入锁住的房间。</p>

<p>当你进入一个房间，你可能会在里面找到一套 <strong>不同的钥匙</strong>，每把钥匙上都有对应的房间号，即表示钥匙可以打开的房间。你可以拿上所有钥匙去解锁其他房间。</p>

<p>给你一个数组 <code>rooms</code> 其中 <code>rooms[i]</code> 是你进入 <code>i</code> 号房间可以获得的钥匙集合。如果能进入 <strong>所有</strong> 房间返回 <code>true</code>，否则返回 <code>false</code>。</p>

<p>&nbsp;</p>

<ol>
</ol>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>rooms = [[1],[2],[3],[]]
<strong>输出：</strong>true
<strong>解释：</strong>
我们从 0 号房间开始，拿到钥匙 1。
之后我们去 1 号房间，拿到钥匙 2。
然后我们去 2 号房间，拿到钥匙 3。
最后我们去了 3 号房间。
由于我们能够进入每个房间，我们返回 true。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>rooms = [[1,3],[3,0,1],[2],[0]]
<strong>输出：</strong>false
<strong>解释：</strong>我们不能进入 2 号房间。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == rooms.length</code></li>
	<li><code>2 &lt;= n &lt;= 1000</code></li>
	<li><code>0 &lt;= rooms[i].length &lt;= 1000</code></li>
	<li><code>1 &lt;= sum(rooms[i].length) &lt;= 3000</code></li>
	<li><code>0 &lt;= rooms[i][j] &lt; n</code></li>
	<li>所有 <code>rooms[i]</code> 的值 <strong>互不相同</strong></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS

我们可以使用深度优先搜索的方法遍历整张图，统计可以到达的节点个数，并利用数组 `vis` 标记当前节点是否访问过，以防止重复访问。

最后统计访问过的节点个数，若与节点总数相同则说明可以访问所有节点，否则说明存在无法到达的节点。

时间复杂度 $O(n + m)$，空间复杂度 $O(n)$，其中 $n$ 为节点个数，而 $m$ 为边的个数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        def dfs(i: int):
            if i in vis:
                return
            vis.add(i)
            for j in rooms[i]:
                dfs(j)

        vis = set()
        dfs(0)
        return len(vis) == len(rooms)
```

#### Java

```java
class Solution {
    private int cnt;
    private boolean[] vis;
    private List<List<Integer>> g;

    public boolean canVisitAllRooms(List<List<Integer>> rooms) {
        g = rooms;
        vis = new boolean[g.size()];
        dfs(0);
        return cnt == g.size();
    }

    private void dfs(int i) {
        if (vis[i]) {
            return;
        }
        vis[i] = true;
        ++cnt;
        for (int j : g.get(i)) {
            dfs(j);
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        int cnt = 0;
        bool vis[n];
        memset(vis, false, sizeof(vis));
        function<void(int)> dfs = [&](int i) {
            if (vis[i]) {
                return;
            }
            vis[i] = true;
            ++cnt;
            for (int j : rooms[i]) {
                dfs(j);
            }
        };
        dfs(0);
        return cnt == n;
    }
};
```

#### Go

```go
func canVisitAllRooms(rooms [][]int) bool {
	n := len(rooms)
	cnt := 0
	vis := make([]bool, n)
	var dfs func(int)
	dfs = func(i int) {
		if vis[i] {
			return
		}
		vis[i] = true
		cnt++
		for _, j := range rooms[i] {
			dfs(j)
		}
	}
	dfs(0)
	return cnt == n
}
```

#### TypeScript

```ts
function canVisitAllRooms(rooms: number[][]): boolean {
    const n = rooms.length;
    const vis: boolean[] = Array(n).fill(false);
    const dfs = (i: number) => {
        if (vis[i]) {
            return;
        }
        vis[i] = true;
        for (const j of rooms[i]) {
            dfs(j);
        }
    };
    dfs(0);
    return vis.every(v => v);
}
```

#### Rust

```rust
impl Solution {
    pub fn can_visit_all_rooms(rooms: Vec<Vec<i32>>) -> bool {
        let n = rooms.len();
        let mut is_open = vec![false; n];
        let mut keys = vec![0];
        while !keys.is_empty() {
            let i = keys.pop().unwrap();
            if is_open[i] {
                continue;
            }
            is_open[i] = true;
            rooms[i].iter().for_each(|&key| keys.push(key as usize));
        }
        is_open.iter().all(|&v| v)
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：BFS

我们也可以使用广度优先搜索的方法遍历整张图，用一个哈希表或者数组 `vis` 标记当前节点是否访问过，以防止重复访问。

具体地，我们定义一个队列 $q$，初始时将节点 $0$ 放入队列中，然后不断遍历队列。每次取出队首节点 $i$，如果 $i$ 被访问过则直接跳过，否则我们将其标记为已访问，然后将 $i$ 可以到达的节点加入队列中。

最后统计访问过的节点个数，若与节点总数相同则说明可以访问所有节点，否则说明存在无法到达的节点。

时间复杂度 $O(n + m)$，空间复杂度 $O(n)$，其中 $n$ 为节点个数，而 $m$ 为边的个数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        vis = set()
        q = deque([0])
        while q:
            i = q.popleft()
            if i in vis:
                continue
            vis.add(i)
            q.extend(j for j in rooms[i])
        return len(vis) == len(rooms)
```

#### Java

```java
class Solution {
    public boolean canVisitAllRooms(List<List<Integer>> rooms) {
        int n = rooms.size();
        boolean[] vis = new boolean[n];
        Deque<Integer> q = new ArrayDeque<>();
        q.offer(0);
        int cnt = 0;
        while (!q.isEmpty()) {
            int i = q.poll();
            if (vis[i]) {
                continue;
            }
            vis[i] = true;
            ++cnt;
            for (int j : rooms.get(i)) {
                q.offer(j);
            }
        }
        return cnt == n;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n);
        queue<int> q{{0}};
        int cnt = 0;
        while (q.size()) {
            int i = q.front();
            q.pop();
            if (vis[i]) {
                continue;
            }
            vis[i] = true;
            ++cnt;
            for (int j : rooms[i]) {
                q.push(j);
            }
        }
        return cnt == n;
    }
};
```

#### Go

```go
func canVisitAllRooms(rooms [][]int) bool {
	n := len(rooms)
	vis := make([]bool, n)
	cnt := 0
	q := []int{0}
	for len(q) > 0 {
		i := q[0]
		q = q[1:]
		if vis[i] {
			continue
		}
		vis[i] = true
		cnt++
		for _, j := range rooms[i] {
			q = append(q, j)
		}
	}
	return cnt == n
}
```

#### TypeScript

```ts
function canVisitAllRooms(rooms: number[][]): boolean {
    const vis = new Set<number>();
    const q: number[] = [0];

    while (q.length) {
        const i = q.pop()!;
        if (vis.has(i)) {
            continue;
        }
        vis.add(i);
        q.push(...rooms[i]);
    }

    return vis.size == rooms.length;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [842. 将数组拆分成斐波那契序列](https://leetcode.cn/problems/split-array-into-fibonacci-sequence){#842}

{{< tabs "842" >}}

{{% tab "python" %}}
```python
class Solution:
    def splitIntoFibonacci(self, num: str) -> List[int]:
        def dfs(i):
            if i == n:
                return len(ans) > 2
            x = 0
            for j in range(i, n):
                if j > i and num[i] == '0':
                    break
                x = x * 10 + int(num[j])
                if x > 2**31 - 1 or (len(ans) > 2 and x > ans[-2] + ans[-1]):
                    break
                if len(ans) < 2 or ans[-2] + ans[-1] == x:
                    ans.append(x)
                    if dfs(j + 1):
                        return True
                    ans.pop()
            return False

        n = len(num)
        ans = []
        dfs(0)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private List<Integer> ans = new ArrayList<>();
    private String num;

    public List<Integer> splitIntoFibonacci(String num) {
        this.num = num;
        dfs(0);
        return ans;
    }

    private boolean dfs(int i) {
        if (i == num.length()) {
            return ans.size() >= 3;
        }
        long x = 0;
        for (int j = i; j < num.length(); ++j) {
            if (j > i && num.charAt(i) == '0') {
                break;
            }
            x = x * 10 + num.charAt(j) - '0';
            if (x > Integer.MAX_VALUE
                || (ans.size() >= 2 && x > ans.get(ans.size() - 1) + ans.get(ans.size() - 2))) {
                break;
            }
            if (ans.size() < 2 || x == ans.get(ans.size() - 1) + ans.get(ans.size() - 2)) {
                ans.add((int) x);
                if (dfs(j + 1)) {
                    return true;
                }
                ans.remove(ans.size() - 1);
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
    vector<int> splitIntoFibonacci(string num) {
        int n = num.size();
        vector<int> ans;
        function<bool(int)> dfs = [&](int i) -> bool {
            if (i == n) {
                return ans.size() > 2;
            }
            long long x = 0;
            for (int j = i; j < n; ++j) {
                if (j > i && num[i] == '0') {
                    break;
                }
                x = x * 10 + num[j] - '0';
                if (x > INT_MAX || (ans.size() > 1 && x > (long long) ans[ans.size() - 1] + ans[ans.size() - 2])) {
                    break;
                }
                if (ans.size() < 2 || x == (long long) ans[ans.size() - 1] + ans[ans.size() - 2]) {
                    ans.push_back(x);
                    if (dfs(j + 1)) {
                        return true;
                    }
                    ans.pop_back();
                }
            }
            return false;
        };
        dfs(0);
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func splitIntoFibonacci(num string) []int {
	n := len(num)
	ans := []int{}
	var dfs func(int) bool
	dfs = func(i int) bool {
		if i == n {
			return len(ans) > 2
		}
		x := 0
		for j := i; j < n; j++ {
			if j > i && num[i] == '0' {
				break
			}
			x = x*10 + int(num[j]-'0')
			if x > math.MaxInt32 || (len(ans) > 1 && x > ans[len(ans)-1]+ans[len(ans)-2]) {
				break
			}
			if len(ans) < 2 || x == ans[len(ans)-1]+ans[len(ans)-2] {
				ans = append(ans, x)
				if dfs(j + 1) {
					return true
				}
				ans = ans[:len(ans)-1]
			}
		}
		return false
	}
	dfs(0)
	return ans
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个数字字符串 <code>num</code>，比如 <code>"123456579"</code>，我们可以将它分成「斐波那契式」的序列 <code>[123, 456, 579]</code>。</p>

<p>形式上，<strong>斐波那契式&nbsp;</strong>序列是一个非负整数列表 <code>f</code>，且满足：</p>

<ul>
	<li><code>0 &lt;= f[i] &lt; 2<sup>31</sup></code>&nbsp;，（也就是说，每个整数都符合 <strong>32 位</strong>&nbsp;有符号整数类型）</li>
	<li><code>f.length &gt;= 3</code></li>
	<li>对于所有的<code>0 &lt;= i &lt; f.length - 2</code>，都有 <code>f[i] + f[i + 1] = f[i + 2]</code></li>
</ul>

<p>另外，请注意，将字符串拆分成小块时，每个块的数字一定不要以零开头，除非这个块是数字 <code>0</code> 本身。</p>

<p>返回从 <code>num</code> 拆分出来的任意一组斐波那契式的序列块，如果不能拆分则返回 <code>[]</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>num = "1101111"
<strong>输出：</strong>[11,0,11,11]
<strong>解释：</strong>输出 [110,1,111] 也可以。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入: </strong>num = "112358130"
<strong>输出: </strong>[]
<strong>解释: </strong>无法拆分。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>"0123"
<strong>输出：</strong>[]
<strong>解释：</strong>每个块的数字不能以零开头，因此 "01"，"2"，"3" 不是有效答案。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= num.length &lt;= 200</code></li>
	<li><code>num</code>&nbsp;中只含有数字</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：回溯 + 剪枝

我们设计一个函数 $dfs(i)$，表示从字符串 $num$ 的第 $i$ 个字符开始拆分，拆分出的斐波那契式序列是否满足题目要求。如果满足，我们就返回 $true$，否则返回 $false$。

函数 $dfs(i)$ 的具体实现如下：

如果 $i$ 等于字符串 $num$ 的长度，说明我们已经拆分完整个字符串，此时我们只需要判断拆分出的序列的长度是否大于 $2$ 即可。如果大于 $2$，说明我们找到了一组满足题目要求的斐波那契式序列，返回 $true$；否则返回 $false$。

如果 $i$ 小于字符串 $num$ 的长度，我们需要枚举拆分出的第一个数 $x$，如果 $x$ 的长度大于 $1$，且以 $0$ 开头，说明 $x$ 不是一个合法的数，我们直接返回 $false$。否则我们将 $x$ 转换成十进制数，如果 $x$ 大于 $2^{31} - 1$，或者 $x$ 大于 $ans$ 的最后两个数之和，直接返回 $false$。如果 $ans$ 的长度小于 $2$，或者 $x$ 等于 $ans$ 的最后两个数之和，我们将 $x$ 加入到 $ans$ 中，然后继续拆分字符串 $num$ 的后面的部分，如果返回 $true$，说明我们找到了一组满足题目要求的斐波那契式序列，返回 $true$；否则我们将 $x$ 从 $ans$ 中移除，然后继续枚举拆分出的第一个数 $x$。

时间复杂度 $O(n \times \log^2 M)$，空间复杂度 $O(n)$。其中 $n$ 和 $M$ 分别是字符串 $num$ 的长度和整型数的最大值。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def splitIntoFibonacci(self, num: str) -> List[int]:
        def dfs(i):
            if i == n:
                return len(ans) > 2
            x = 0
            for j in range(i, n):
                if j > i and num[i] == '0':
                    break
                x = x * 10 + int(num[j])
                if x > 2**31 - 1 or (len(ans) > 2 and x > ans[-2] + ans[-1]):
                    break
                if len(ans) < 2 or ans[-2] + ans[-1] == x:
                    ans.append(x)
                    if dfs(j + 1):
                        return True
                    ans.pop()
            return False

        n = len(num)
        ans = []
        dfs(0)
        return ans
```

#### Java

```java
class Solution {
    private List<Integer> ans = new ArrayList<>();
    private String num;

    public List<Integer> splitIntoFibonacci(String num) {
        this.num = num;
        dfs(0);
        return ans;
    }

    private boolean dfs(int i) {
        if (i == num.length()) {
            return ans.size() >= 3;
        }
        long x = 0;
        for (int j = i; j < num.length(); ++j) {
            if (j > i && num.charAt(i) == '0') {
                break;
            }
            x = x * 10 + num.charAt(j) - '0';
            if (x > Integer.MAX_VALUE
                || (ans.size() >= 2 && x > ans.get(ans.size() - 1) + ans.get(ans.size() - 2))) {
                break;
            }
            if (ans.size() < 2 || x == ans.get(ans.size() - 1) + ans.get(ans.size() - 2)) {
                ans.add((int) x);
                if (dfs(j + 1)) {
                    return true;
                }
                ans.remove(ans.size() - 1);
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
    vector<int> splitIntoFibonacci(string num) {
        int n = num.size();
        vector<int> ans;
        function<bool(int)> dfs = [&](int i) -> bool {
            if (i == n) {
                return ans.size() > 2;
            }
            long long x = 0;
            for (int j = i; j < n; ++j) {
                if (j > i && num[i] == '0') {
                    break;
                }
                x = x * 10 + num[j] - '0';
                if (x > INT_MAX || (ans.size() > 1 && x > (long long) ans[ans.size() - 1] + ans[ans.size() - 2])) {
                    break;
                }
                if (ans.size() < 2 || x == (long long) ans[ans.size() - 1] + ans[ans.size() - 2]) {
                    ans.push_back(x);
                    if (dfs(j + 1)) {
                        return true;
                    }
                    ans.pop_back();
                }
            }
            return false;
        };
        dfs(0);
        return ans;
    }
};
```

#### Go

```go
func splitIntoFibonacci(num string) []int {
	n := len(num)
	ans := []int{}
	var dfs func(int) bool
	dfs = func(i int) bool {
		if i == n {
			return len(ans) > 2
		}
		x := 0
		for j := i; j < n; j++ {
			if j > i && num[i] == '0' {
				break
			}
			x = x*10 + int(num[j]-'0')
			if x > math.MaxInt32 || (len(ans) > 1 && x > ans[len(ans)-1]+ans[len(ans)-2]) {
				break
			}
			if len(ans) < 2 || x == ans[len(ans)-1]+ans[len(ans)-2] {
				ans = append(ans, x)
				if dfs(j + 1) {
					return true
				}
				ans = ans[:len(ans)-1]
			}
		}
		return false
	}
	dfs(0)
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [843. 猜猜这个单词](https://leetcode.cn/problems/guess-the-word){#843}

{{< tabs "843" >}}

{{% tab "python" %}}
```python

```
{{% /tab %}}
{{% tab "java" %}}
```java

```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp

```
{{% /tab %}}
{{% tab "go" %}}
```go

```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个由 <strong>不同</strong> 字符串组成的单词列表&nbsp;<code>words</code> ，其中 <code>words[i]</code>&nbsp;长度均为&nbsp;<code>6</code> 。<code>words</code> 中的一个单词将被选作秘密单词 <code>secret</code>&nbsp;。</p>

<p>另给你一个辅助对象&nbsp;<code>Master</code> ，你可以调用&nbsp;<code>Master.guess(word)</code> 来猜单词，其中参数 <code>word</code> 长度为 6 且必须是 <code>words</code> 中的字符串。</p>

<p><code>Master.guess(word)</code> 将会返回如下结果：</p>

<ul>
	<li>如果 <code>word</code> 不是 <code>words</code> 中的字符串，返回 <code>-1</code> ，或者</li>
	<li>一个整数，表示你所猜测的单词 <code>word</code> 与 <strong>秘密单词</strong>&nbsp;<code>secret</code>&nbsp;的准确匹配（值和位置同时匹配）的数目。</li>
</ul>

<p>每组测试用例都会包含一个参数 <code>allowedGuesses</code> ，其中 <code>allowedGuesses</code> 是你可以调用 <code>Master.guess(word)</code> 的最大次数。</p>

<p>对于每组测试用例，在不超过允许猜测的次数的前提下，你应该调用 <code>Master.guess</code> 来猜出秘密单词。最终，你将会得到以下结果：</p>

<ul>
	<li>如果你调用 <code>Master.guess</code> 的次数大于 <code>allowedGuesses</code> 所限定的次数或者你没有用 <code>Master.guess</code> 猜到秘密单词，则得到 <strong><code>"Either you took too many guesses, or you did not find the secret word."</code> 。</strong></li>
	<li>如果你调用 <code>Master.guess</code> 猜到秘密单词，且调用 <code>Master.guess</code> 的次数小于或等于 <code>allowedGuesses</code> ，则得到 <strong><code>"You guessed the secret word correctly."</code> 。</strong></li>
</ul>

<p>生成的测试用例保证你可以利用某种合理的策略（而不是暴力）猜到秘密单词。</p>
&nbsp;

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>secret = "acckzz", words = ["acckzz","ccbazz","eiowzz","abcczz"], allowedGuesses = 10
<strong>输出：</strong>You guessed the secret word correctly.
<strong>解释：</strong>
master.guess("aaaaaa") 返回 -1 ，因为 "aaaaaa" 不在 words 中。
master.guess("acckzz") 返回 6 ，因为 "acckzz" 是秘密单词 secret ，共有 6 个字母匹配。
master.guess("ccbazz") 返回 3 ，因为 "ccbazz" 共有 3 个字母匹配。
master.guess("eiowzz") 返回 2 ，因为 "eiowzz" 共有 2 个字母匹配。
master.guess("abcczz") 返回 4 ，因为 "abcczz" 共有 4 个字母匹配。
一共调用 5 次 master.guess ，其中一个为秘密单词，所以通过测试用例。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>secret = "hamada", words = ["hamada","khaled"], allowedGuesses = 10
<strong>输出：</strong>You guessed the secret word correctly.
<strong>解释：</strong>共有 2 个单词，且其中一个为秘密单词，可以通过测试用例。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 100</code></li>
	<li><code>words[i].length == 6</code></li>
	<li><code>words[i]</code> 仅由小写英文字母组成</li>
	<li><code>words</code> 中所有字符串 <strong>互不相同</strong></li>
	<li><code>secret</code> 存在于 <code>words</code> 中</li>
	<li><code>10 &lt;= allowedGuesses &lt;= 30</code></li>
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

```

#### Java

```java

```

#### C++

```cpp

```

#### Go

```go

```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [844. 比较含退格的字符串](https://leetcode.cn/problems/backspace-string-compare){#844}

{{< tabs "844" >}}

{{% tab "python" %}}
```python
class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        i, j, skip1, skip2 = len(s) - 1, len(t) - 1, 0, 0
        while i >= 0 or j >= 0:
            while i >= 0:
                if s[i] == '#':
                    skip1 += 1
                    i -= 1
                elif skip1:
                    skip1 -= 1
                    i -= 1
                else:
                    break
            while j >= 0:
                if t[j] == '#':
                    skip2 += 1
                    j -= 1
                elif skip2:
                    skip2 -= 1
                    j -= 1
                else:
                    break
            if i >= 0 and j >= 0:
                if s[i] != t[j]:
                    return False
            elif i >= 0 or j >= 0:
                return False
            i, j = i - 1, j - 1
        return True
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean backspaceCompare(String s, String t) {
        int i = s.length() - 1, j = t.length() - 1;
        int skip1 = 0, skip2 = 0;
        for (; i >= 0 || j >= 0; --i, --j) {
            while (i >= 0) {
                if (s.charAt(i) == '#') {
                    ++skip1;
                    --i;
                } else if (skip1 > 0) {
                    --skip1;
                    --i;
                } else {
                    break;
                }
            }
            while (j >= 0) {
                if (t.charAt(j) == '#') {
                    ++skip2;
                    --j;
                } else if (skip2 > 0) {
                    --skip2;
                    --j;
                } else {
                    break;
                }
            }
            if (i >= 0 && j >= 0) {
                if (s.charAt(i) != t.charAt(j)) {
                    return false;
                }
            } else if (i >= 0 || j >= 0) {
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
    bool backspaceCompare(string s, string t) {
        int i = s.size() - 1, j = t.size() - 1;
        int skip1 = 0, skip2 = 0;
        for (; i >= 0 || j >= 0; --i, --j) {
            while (i >= 0) {
                if (s[i] == '#') {
                    ++skip1;
                    --i;
                } else if (skip1) {
                    --skip1;
                    --i;
                } else
                    break;
            }
            while (j >= 0) {
                if (t[j] == '#') {
                    ++skip2;
                    --j;
                } else if (skip2) {
                    --skip2;
                    --j;
                } else
                    break;
            }
            if (i >= 0 && j >= 0) {
                if (s[i] != t[j]) return false;
            } else if (i >= 0 || j >= 0)
                return false;
        }
        return true;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func backspaceCompare(s string, t string) bool {
	i, j := len(s)-1, len(t)-1
	skip1, skip2 := 0, 0
	for ; i >= 0 || j >= 0; i, j = i-1, j-1 {
		for i >= 0 {
			if s[i] == '#' {
				skip1++
				i--
			} else if skip1 > 0 {
				skip1--
				i--
			} else {
				break
			}
		}
		for j >= 0 {
			if t[j] == '#' {
				skip2++
				j--
			} else if skip2 > 0 {
				skip2--
				j--
			} else {
				break
			}
		}
		if i >= 0 && j >= 0 {
			if s[i] != t[j] {
				return false
			}
		} else if i >= 0 || j >= 0 {
			return false
		}
	}
	return true
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function backspaceCompare(s: string, t: string): boolean {
    let i = s.length - 1;
    let j = t.length - 1;
    while (i >= 0 || j >= 0) {
        let skip = 0;
        while (i >= 0) {
            if (s[i] === '#') {
                skip++;
            } else if (skip !== 0) {
                skip--;
            } else {
                break;
            }
            i--;
        }
        skip = 0;
        while (j >= 0) {
            if (t[j] === '#') {
                skip++;
            } else if (skip !== 0) {
                skip--;
            } else {
                break;
            }
            j--;
        }
        if (s[i] !== t[j]) {
            return false;
        }
        i--;
        j--;
    }
    return true;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn backspace_compare(s: String, t: String) -> bool {
        let (s, t) = (s.as_bytes(), t.as_bytes());
        let (mut i, mut j) = (s.len(), t.len());
        while i != 0 || j != 0 {
            let mut skip = 0;
            while i != 0 {
                if s[i - 1] == b'#' {
                    skip += 1;
                } else if skip != 0 {
                    skip -= 1;
                } else {
                    break;
                }
                i -= 1;
            }
            skip = 0;
            while j != 0 {
                if t[j - 1] == b'#' {
                    skip += 1;
                } else if skip != 0 {
                    skip -= 1;
                } else {
                    break;
                }
                j -= 1;
            }
            if i == 0 && j == 0 {
                break;
            }
            if i == 0 || j == 0 {
                return false;
            }
            if s[i - 1] != t[j - 1] {
                return false;
            }
            i -= 1;
            j -= 1;
        }
        true
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定 <code>s</code> 和 <code>t</code> 两个字符串，当它们分别被输入到空白的文本编辑器后，如果两者相等，返回 <code>true</code> 。<code>#</code> 代表退格字符。</p>

<p><strong>注意：</strong>如果对空文本输入退格字符，文本继续为空。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "ab#c", t = "ad#c"
<strong>输出：</strong>true
<strong>解释：</strong>s 和 t 都会变成 "ac"。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "ab##", t = "c#d#"
<strong>输出：</strong>true
<strong>解释：</strong>s 和 t 都会变成 ""。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "a#c", t = "b"
<strong>输出：</strong>false
<strong>解释：</strong>s 会变成 "c"，但 t 仍然是 "b"。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length, t.length &lt;= 200</code></li>
	<li><code>s</code> 和 <code>t</code> 只含有小写字母以及字符 <code>'#'</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong></p>

<ul>
	<li>你可以用 <code>O(n)</code> 的时间复杂度和 <code>O(1)</code> 的空间复杂度解决该问题吗？</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双指针

我们用双指针 $i$ 和 $j$ 分别指向字符串 $s$ 和 $t$ 的末尾。

每次向前移动一个字符，如果当前字符是退格符，则跳过当前字符，同时退格符的数量加一，如果当前字符不是退格符，则判断退格符的数量，如果退格符的数量大于 $0$，则跳过当前字符，同时退格符的数量减一，如果退格符的数量等于 $0$，那么该字符需要进行比较。

我们每次找到两个字符串中需要比较的字符，然后进行比较，如果两个字符不相等，则返回 $false$，如果遍历完两个字符串，都没有发现不相等的字符，则返回 $true$。

时间复杂度 $O(m + n)$，空间复杂度 $O(1)$。其中 $m$ 和 $n$ 分别是字符串 $s$ 和 $t$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        i, j, skip1, skip2 = len(s) - 1, len(t) - 1, 0, 0
        while i >= 0 or j >= 0:
            while i >= 0:
                if s[i] == '#':
                    skip1 += 1
                    i -= 1
                elif skip1:
                    skip1 -= 1
                    i -= 1
                else:
                    break
            while j >= 0:
                if t[j] == '#':
                    skip2 += 1
                    j -= 1
                elif skip2:
                    skip2 -= 1
                    j -= 1
                else:
                    break
            if i >= 0 and j >= 0:
                if s[i] != t[j]:
                    return False
            elif i >= 0 or j >= 0:
                return False
            i, j = i - 1, j - 1
        return True
```

#### Java

```java
class Solution {
    public boolean backspaceCompare(String s, String t) {
        int i = s.length() - 1, j = t.length() - 1;
        int skip1 = 0, skip2 = 0;
        for (; i >= 0 || j >= 0; --i, --j) {
            while (i >= 0) {
                if (s.charAt(i) == '#') {
                    ++skip1;
                    --i;
                } else if (skip1 > 0) {
                    --skip1;
                    --i;
                } else {
                    break;
                }
            }
            while (j >= 0) {
                if (t.charAt(j) == '#') {
                    ++skip2;
                    --j;
                } else if (skip2 > 0) {
                    --skip2;
                    --j;
                } else {
                    break;
                }
            }
            if (i >= 0 && j >= 0) {
                if (s.charAt(i) != t.charAt(j)) {
                    return false;
                }
            } else if (i >= 0 || j >= 0) {
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
    bool backspaceCompare(string s, string t) {
        int i = s.size() - 1, j = t.size() - 1;
        int skip1 = 0, skip2 = 0;
        for (; i >= 0 || j >= 0; --i, --j) {
            while (i >= 0) {
                if (s[i] == '#') {
                    ++skip1;
                    --i;
                } else if (skip1) {
                    --skip1;
                    --i;
                } else
                    break;
            }
            while (j >= 0) {
                if (t[j] == '#') {
                    ++skip2;
                    --j;
                } else if (skip2) {
                    --skip2;
                    --j;
                } else
                    break;
            }
            if (i >= 0 && j >= 0) {
                if (s[i] != t[j]) return false;
            } else if (i >= 0 || j >= 0)
                return false;
        }
        return true;
    }
};
```

#### Go

```go
func backspaceCompare(s string, t string) bool {
	i, j := len(s)-1, len(t)-1
	skip1, skip2 := 0, 0
	for ; i >= 0 || j >= 0; i, j = i-1, j-1 {
		for i >= 0 {
			if s[i] == '#' {
				skip1++
				i--
			} else if skip1 > 0 {
				skip1--
				i--
			} else {
				break
			}
		}
		for j >= 0 {
			if t[j] == '#' {
				skip2++
				j--
			} else if skip2 > 0 {
				skip2--
				j--
			} else {
				break
			}
		}
		if i >= 0 && j >= 0 {
			if s[i] != t[j] {
				return false
			}
		} else if i >= 0 || j >= 0 {
			return false
		}
	}
	return true
}
```

#### TypeScript

```ts
function backspaceCompare(s: string, t: string): boolean {
    let i = s.length - 1;
    let j = t.length - 1;
    while (i >= 0 || j >= 0) {
        let skip = 0;
        while (i >= 0) {
            if (s[i] === '#') {
                skip++;
            } else if (skip !== 0) {
                skip--;
            } else {
                break;
            }
            i--;
        }
        skip = 0;
        while (j >= 0) {
            if (t[j] === '#') {
                skip++;
            } else if (skip !== 0) {
                skip--;
            } else {
                break;
            }
            j--;
        }
        if (s[i] !== t[j]) {
            return false;
        }
        i--;
        j--;
    }
    return true;
}
```

#### Rust

```rust
impl Solution {
    pub fn backspace_compare(s: String, t: String) -> bool {
        let (s, t) = (s.as_bytes(), t.as_bytes());
        let (mut i, mut j) = (s.len(), t.len());
        while i != 0 || j != 0 {
            let mut skip = 0;
            while i != 0 {
                if s[i - 1] == b'#' {
                    skip += 1;
                } else if skip != 0 {
                    skip -= 1;
                } else {
                    break;
                }
                i -= 1;
            }
            skip = 0;
            while j != 0 {
                if t[j - 1] == b'#' {
                    skip += 1;
                } else if skip != 0 {
                    skip -= 1;
                } else {
                    break;
                }
                j -= 1;
            }
            if i == 0 && j == 0 {
                break;
            }
            if i == 0 || j == 0 {
                return false;
            }
            if s[i - 1] != t[j - 1] {
                return false;
            }
            i -= 1;
            j -= 1;
        }
        true
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [845. 数组中的最长山脉](https://leetcode.cn/problems/longest-mountain-in-array){#845}

{{< tabs "845" >}}

{{% tab "python" %}}
```python
class Solution:
    def longestMountain(self, arr: List[int]) -> int:
        n = len(arr)
        ans = l = 0
        while l + 2 < n:
            r = l + 1
            if arr[l] < arr[r]:
                while r + 1 < n and arr[r] < arr[r + 1]:
                    r += 1
                if r < n - 1 and arr[r] > arr[r + 1]:
                    while r < n - 1 and arr[r] > arr[r + 1]:
                        r += 1
                    ans = max(ans, r - l + 1)
                else:
                    r += 1
            l = r
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int longestMountain(int[] arr) {
        int n = arr.length;
        int ans = 0;
        for (int l = 0, r = 0; l + 2 < n; l = r) {
            r = l + 1;
            if (arr[l] < arr[r]) {
                while (r + 1 < n && arr[r] < arr[r + 1]) {
                    ++r;
                }
                if (r + 1 < n && arr[r] > arr[r + 1]) {
                    while (r + 1 < n && arr[r] > arr[r + 1]) {
                        ++r;
                    }
                    ans = Math.max(ans, r - l + 1);
                } else {
                    ++r;
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
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        for (int l = 0, r = 0; l + 2 < n; l = r) {
            r = l + 1;
            if (arr[l] < arr[r]) {
                while (r + 1 < n && arr[r] < arr[r + 1]) {
                    ++r;
                }
                if (r + 1 < n && arr[r] > arr[r + 1]) {
                    while (r + 1 < n && arr[r] > arr[r + 1]) {
                        ++r;
                    }
                    ans = max(ans, r - l + 1);
                } else {
                    ++r;
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
func longestMountain(arr []int) (ans int) {
	n := len(arr)
	for l, r := 0, 0; l+2 < n; l = r {
		r = l + 1
		if arr[l] < arr[r] {
			for r+1 < n && arr[r] < arr[r+1] {
				r++
			}
			if r+1 < n && arr[r] > arr[r+1] {
				for r+1 < n && arr[r] > arr[r+1] {
					r++
				}
				ans = max(ans, r-l+1)
			} else {
				r++
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

<p>把符合下列属性的数组 <code>arr</code> 称为 <strong>山脉数组</strong> ：</p>

<ul>
	<li><code>arr.length &gt;= 3</code></li>
	<li>存在下标 <code>i</code>（<code>0 &lt; i &lt; arr.length - 1</code>），满足
	<ul>
		<li><code>arr[0] &lt; arr[1] &lt; ... &lt; arr[i - 1] &lt; arr[i]</code></li>
		<li><code>arr[i] &gt; arr[i + 1] &gt; ... &gt; arr[arr.length - 1]</code></li>
	</ul>
	</li>
</ul>

<p>给出一个整数数组 <code>arr</code>，返回最长山脉子数组的长度。如果不存在山脉子数组，返回 <code>0</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>arr = [2,1,4,7,3,2,5]
<strong>输出：</strong>5
<strong>解释：</strong>最长的山脉子数组是 [1,4,7,3,2]，长度为 5。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>arr = [2,2,2]
<strong>输出：</strong>0
<strong>解释：</strong>不存在山脉子数组。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= arr[i] &lt;= 10<sup>4</sup></code></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong></p>

<ul>
	<li>你可以仅用一趟扫描解决此问题吗？</li>
	<li>你可以用 <code>O(1)</code> 空间解决此问题吗？</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：预处理 + 枚举

我们定义两个数组 $f$ 和 $g$，其中 $f[i]$ 表示以 $arr[i]$ 结尾的最长上升子序列的长度，而 $g[i]$ 表示以 $arr[i]$ 开头的最长下降子序列的长度。那么对于每个下标 $i$，如果 $f[i] \gt 1$ 且 $g[i] \gt 1$，那么以 $arr[i]$ 为山顶的山脉的长度为 $f[i] + g[i] - 1$，我们只需要枚举所有的 $i$，找出最大的那个值即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $arr$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def longestMountain(self, arr: List[int]) -> int:
        n = len(arr)
        f = [1] * n
        g = [1] * n
        for i in range(1, n):
            if arr[i] > arr[i - 1]:
                f[i] = f[i - 1] + 1
        ans = 0
        for i in range(n - 2, -1, -1):
            if arr[i] > arr[i + 1]:
                g[i] = g[i + 1] + 1
                if f[i] > 1:
                    ans = max(ans, f[i] + g[i] - 1)
        return ans
```

#### Java

```java
class Solution {
    public int longestMountain(int[] arr) {
        int n = arr.length;
        int[] f = new int[n];
        int[] g = new int[n];
        Arrays.fill(f, 1);
        Arrays.fill(g, 1);
        for (int i = 1; i < n; ++i) {
            if (arr[i] > arr[i - 1]) {
                f[i] = f[i - 1] + 1;
            }
        }
        int ans = 0;
        for (int i = n - 2; i >= 0; --i) {
            if (arr[i] > arr[i + 1]) {
                g[i] = g[i + 1] + 1;
                if (f[i] > 1) {
                    ans = Math.max(ans, f[i] + g[i] - 1);
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
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        int f[n];
        int g[n];
        fill(f, f + n, 1);
        fill(g, g + n, 1);
        for (int i = 1; i < n; ++i) {
            if (arr[i] > arr[i - 1]) {
                f[i] = f[i - 1] + 1;
            }
        }
        int ans = 0;
        for (int i = n - 2; ~i; --i) {
            if (arr[i] > arr[i + 1]) {
                g[i] = g[i + 1] + 1;
                if (f[i] > 1) {
                    ans = max(ans, f[i] + g[i] - 1);
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func longestMountain(arr []int) (ans int) {
	n := len(arr)
	f := make([]int, n)
	g := make([]int, n)
	for i := range f {
		f[i] = 1
		g[i] = 1
	}
	for i := 1; i < n; i++ {
		if arr[i] > arr[i-1] {
			f[i] = f[i-1] + 1
		}
	}
	for i := n - 2; i >= 0; i-- {
		if arr[i] > arr[i+1] {
			g[i] = g[i+1] + 1
			if f[i] > 1 {
				ans = max(ans, f[i]+g[i]-1)
			}
		}
	}
	return
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：一次遍历（枚举左侧山脚）

我们可以枚举山脉的左侧山脚，然后向右寻找山脉的右侧山脚。我们可以使用两个指针 $l$ 和 $r$，其中 $l$ 表示左侧山脚的下标，$r$ 表示右侧山脚的下标，初始时 $l=0$,$r=0$，然后我们向右移动 $r$，找到山顶的位置，此时判断 $r$ 是否满足 $r + 1 \lt n$ 并且 $arr[r] \gt arr[r + 1]$，如果满足，我们向右继续移动 $r$，直到找到右侧山脚的位置，此时山脉的长度为 $r - l + 1$，我们更新答案，然后将 $l$ 的值更新为 $r$，继续寻找下一个山脉。

时间复杂度 $O(n)$，空间复杂度 $O(1)$。其中 $n$ 为数组 $arr$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def longestMountain(self, arr: List[int]) -> int:
        n = len(arr)
        ans = l = 0
        while l + 2 < n:
            r = l + 1
            if arr[l] < arr[r]:
                while r + 1 < n and arr[r] < arr[r + 1]:
                    r += 1
                if r < n - 1 and arr[r] > arr[r + 1]:
                    while r < n - 1 and arr[r] > arr[r + 1]:
                        r += 1
                    ans = max(ans, r - l + 1)
                else:
                    r += 1
            l = r
        return ans
```

#### Java

```java
class Solution {
    public int longestMountain(int[] arr) {
        int n = arr.length;
        int ans = 0;
        for (int l = 0, r = 0; l + 2 < n; l = r) {
            r = l + 1;
            if (arr[l] < arr[r]) {
                while (r + 1 < n && arr[r] < arr[r + 1]) {
                    ++r;
                }
                if (r + 1 < n && arr[r] > arr[r + 1]) {
                    while (r + 1 < n && arr[r] > arr[r + 1]) {
                        ++r;
                    }
                    ans = Math.max(ans, r - l + 1);
                } else {
                    ++r;
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
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        for (int l = 0, r = 0; l + 2 < n; l = r) {
            r = l + 1;
            if (arr[l] < arr[r]) {
                while (r + 1 < n && arr[r] < arr[r + 1]) {
                    ++r;
                }
                if (r + 1 < n && arr[r] > arr[r + 1]) {
                    while (r + 1 < n && arr[r] > arr[r + 1]) {
                        ++r;
                    }
                    ans = max(ans, r - l + 1);
                } else {
                    ++r;
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func longestMountain(arr []int) (ans int) {
	n := len(arr)
	for l, r := 0, 0; l+2 < n; l = r {
		r = l + 1
		if arr[l] < arr[r] {
			for r+1 < n && arr[r] < arr[r+1] {
				r++
			}
			if r+1 < n && arr[r] > arr[r+1] {
				for r+1 < n && arr[r] > arr[r+1] {
					r++
				}
				ans = max(ans, r-l+1)
			} else {
				r++
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

# [846. 一手顺子](https://leetcode.cn/problems/hand-of-straights){#846}

{{< tabs "846" >}}

{{% tab "python" %}}
```python
class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        if len(hand) % groupSize:
            return False
        cnt = Counter(hand)
        sd = SortedDict(cnt)
        while sd:
            x = next(iter(sd))
            for y in range(x, x + groupSize):
                if y not in sd:
                    return False
                if sd[y] == 1:
                    del sd[y]
                else:
                    sd[y] -= 1
        return True
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean isNStraightHand(int[] hand, int groupSize) {
        if (hand.length % groupSize != 0) {
            return false;
        }
        TreeMap<Integer, Integer> tm = new TreeMap<>();
        for (int x : hand) {
            tm.merge(x, 1, Integer::sum);
        }
        while (!tm.isEmpty()) {
            int x = tm.firstKey();
            for (int y = x; y < x + groupSize; ++y) {
                int t = tm.merge(y, -1, Integer::sum);
                if (t < 0) {
                    return false;
                }
                if (t == 0) {
                    tm.remove(y);
                }
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
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize) {
            return false;
        }
        map<int, int> mp;
        for (int x : hand) {
            ++mp[x];
        }
        while (!mp.empty()) {
            int x = mp.begin()->first;
            for (int y = x; y < x + groupSize; ++y) {
                if (!mp.contains(y)) {
                    return false;
                }
                if (--mp[y] == 0) {
                    mp.erase(y);
                }
            }
        }
        return true;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func isNStraightHand(hand []int, groupSize int) bool {
	if len(hand)%groupSize != 0 {
		return false
	}
	tm := treemap.NewWithIntComparator()
	for _, x := range hand {
		if v, ok := tm.Get(x); ok {
			tm.Put(x, v.(int)+1)
		} else {
			tm.Put(x, 1)
		}
	}
	for !tm.Empty() {
		x, _ := tm.Min()
		for y := x.(int); y < x.(int)+groupSize; y++ {
			if v, ok := tm.Get(y); ok {
				if v.(int) == 1 {
					tm.Remove(y)
				} else {
					tm.Put(y, v.(int)-1)
				}
			} else {
				return false
			}
		}
	}
	return true
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function isNStraightHand(hand: number[], groupSize: number): boolean {
    if (hand.length % groupSize !== 0) {
        return false;
    }
    const tm = new TreeMap<number, number>();
    for (const x of hand) {
        tm.set(x, (tm.get(x) || 0) + 1);
    }
    while (tm.size()) {
        const x = tm.first()![0];
        for (let y = x; y < x + groupSize; ++y) {
            if (!tm.has(y)) {
                return false;
            }
            if (tm.get(y)! === 1) {
                tm.delete(y);
            } else {
                tm.set(y, tm.get(y)! - 1);
            }
        }
    }
    return true;
}

type Compare<T> = (lhs: T, rhs: T) => number;

class RBTreeNode<T = number> {
    data: T;
    count: number;
    left: RBTreeNode<T> | null;
    right: RBTreeNode<T> | null;
    parent: RBTreeNode<T> | null;
    color: number;
    constructor(data: T) {
        this.data = data;
        this.left = this.right = this.parent = null;
        this.color = 0;
        this.count = 1;
    }

    sibling(): RBTreeNode<T> | null {
        if (!this.parent) return null; // sibling null if no parent
        return this.isOnLeft() ? this.parent.right : this.parent.left;
    }

    isOnLeft(): boolean {
        return this === this.parent!.left;
    }

    hasRedChild(): boolean {
        return (
            Boolean(this.left && this.left.color === 0) ||
            Boolean(this.right && this.right.color === 0)
        );
    }
}

class RBTree<T> {
    root: RBTreeNode<T> | null;
    lt: (l: T, r: T) => boolean;
    constructor(compare: Compare<T> = (l: T, r: T) => (l < r ? -1 : l > r ? 1 : 0)) {
        this.root = null;
        this.lt = (l: T, r: T) => compare(l, r) < 0;
    }

    rotateLeft(pt: RBTreeNode<T>): void {
        const right = pt.right!;
        pt.right = right.left;

        if (pt.right) pt.right.parent = pt;
        right.parent = pt.parent;

        if (!pt.parent) this.root = right;
        else if (pt === pt.parent.left) pt.parent.left = right;
        else pt.parent.right = right;

        right.left = pt;
        pt.parent = right;
    }

    rotateRight(pt: RBTreeNode<T>): void {
        const left = pt.left!;
        pt.left = left.right;

        if (pt.left) pt.left.parent = pt;
        left.parent = pt.parent;

        if (!pt.parent) this.root = left;
        else if (pt === pt.parent.left) pt.parent.left = left;
        else pt.parent.right = left;

        left.right = pt;
        pt.parent = left;
    }

    swapColor(p1: RBTreeNode<T>, p2: RBTreeNode<T>): void {
        const tmp = p1.color;
        p1.color = p2.color;
        p2.color = tmp;
    }

    swapData(p1: RBTreeNode<T>, p2: RBTreeNode<T>): void {
        const tmp = p1.data;
        p1.data = p2.data;
        p2.data = tmp;
    }

    fixAfterInsert(pt: RBTreeNode<T>): void {
        let parent = null;
        let grandParent = null;

        while (pt !== this.root && pt.color !== 1 && pt.parent?.color === 0) {
            parent = pt.parent;
            grandParent = pt.parent.parent;

            /*  Case : A
                Parent of pt is left child of Grand-parent of pt */
            if (parent === grandParent?.left) {
                const uncle = grandParent.right;

                /* Case : 1
                   The uncle of pt is also red
                   Only Recoloring required */
                if (uncle && uncle.color === 0) {
                    grandParent.color = 0;
                    parent.color = 1;
                    uncle.color = 1;
                    pt = grandParent;
                } else {
                    /* Case : 2
                       pt is right child of its parent
                       Left-rotation required */
                    if (pt === parent.right) {
                        this.rotateLeft(parent);
                        pt = parent;
                        parent = pt.parent;
                    }

                    /* Case : 3
                       pt is left child of its parent
                       Right-rotation required */
                    this.rotateRight(grandParent);
                    this.swapColor(parent!, grandParent);
                    pt = parent!;
                }
            } else {
                /* Case : B
               Parent of pt is right child of Grand-parent of pt */
                const uncle = grandParent!.left;

                /*  Case : 1
                    The uncle of pt is also red
                    Only Recoloring required */
                if (uncle != null && uncle.color === 0) {
                    grandParent!.color = 0;
                    parent.color = 1;
                    uncle.color = 1;
                    pt = grandParent!;
                } else {
                    /* Case : 2
                       pt is left child of its parent
                       Right-rotation required */
                    if (pt === parent.left) {
                        this.rotateRight(parent);
                        pt = parent;
                        parent = pt.parent;
                    }

                    /* Case : 3
                       pt is right child of its parent
                       Left-rotation required */
                    this.rotateLeft(grandParent!);
                    this.swapColor(parent!, grandParent!);
                    pt = parent!;
                }
            }
        }
        this.root!.color = 1;
    }

    delete(val: T): boolean {
        const node = this.find(val);
        if (!node) return false;
        node.count--;
        if (!node.count) this.deleteNode(node);
        return true;
    }

    deleteAll(val: T): boolean {
        const node = this.find(val);
        if (!node) return false;
        this.deleteNode(node);
        return true;
    }

    deleteNode(v: RBTreeNode<T>): void {
        const u = BSTreplace(v);

        // True when u and v are both black
        const uvBlack = (u === null || u.color === 1) && v.color === 1;
        const parent = v.parent!;

        if (!u) {
            // u is null therefore v is leaf
            if (v === this.root) this.root = null;
            // v is root, making root null
            else {
                if (uvBlack) {
                    // u and v both black
                    // v is leaf, fix double black at v
                    this.fixDoubleBlack(v);
                } else {
                    // u or v is red
                    if (v.sibling()) {
                        // sibling is not null, make it red"
                        v.sibling()!.color = 0;
                    }
                }
                // delete v from the tree
                if (v.isOnLeft()) parent.left = null;
                else parent.right = null;
            }
            return;
        }

        if (!v.left || !v.right) {
            // v has 1 child
            if (v === this.root) {
                // v is root, assign the value of u to v, and delete u
                v.data = u.data;
                v.left = v.right = null;
            } else {
                // Detach v from tree and move u up
                if (v.isOnLeft()) parent.left = u;
                else parent.right = u;
                u.parent = parent;
                if (uvBlack) this.fixDoubleBlack(u);
                // u and v both black, fix double black at u
                else u.color = 1; // u or v red, color u black
            }
            return;
        }

        // v has 2 children, swap data with successor and recurse
        this.swapData(u, v);
        this.deleteNode(u);

        // find node that replaces a deleted node in BST
        function BSTreplace(x: RBTreeNode<T>): RBTreeNode<T> | null {
            // when node have 2 children
            if (x.left && x.right) return successor(x.right);
            // when leaf
            if (!x.left && !x.right) return null;
            // when single child
            return x.left ?? x.right;
        }
        // find node that do not have a left child
        // in the subtree of the given node
        function successor(x: RBTreeNode<T>): RBTreeNode<T> {
            let temp = x;
            while (temp.left) temp = temp.left;
            return temp;
        }
    }

    fixDoubleBlack(x: RBTreeNode<T>): void {
        if (x === this.root) return; // Reached root

        const sibling = x.sibling();
        const parent = x.parent!;
        if (!sibling) {
            // No sibiling, double black pushed up
            this.fixDoubleBlack(parent);
        } else {
            if (sibling.color === 0) {
                // Sibling red
                parent.color = 0;
                sibling.color = 1;
                if (sibling.isOnLeft()) this.rotateRight(parent);
                // left case
                else this.rotateLeft(parent); // right case
                this.fixDoubleBlack(x);
            } else {
                // Sibling black
                if (sibling.hasRedChild()) {
                    // at least 1 red children
                    if (sibling.left && sibling.left.color === 0) {
                        if (sibling.isOnLeft()) {
                            // left left
                            sibling.left.color = sibling.color;
                            sibling.color = parent.color;
                            this.rotateRight(parent);
                        } else {
                            // right left
                            sibling.left.color = parent.color;
                            this.rotateRight(sibling);
                            this.rotateLeft(parent);
                        }
                    } else {
                        if (sibling.isOnLeft()) {
                            // left right
                            sibling.right!.color = parent.color;
                            this.rotateLeft(sibling);
                            this.rotateRight(parent);
                        } else {
                            // right right
                            sibling.right!.color = sibling.color;
                            sibling.color = parent.color;
                            this.rotateLeft(parent);
                        }
                    }
                    parent.color = 1;
                } else {
                    // 2 black children
                    sibling.color = 0;
                    if (parent.color === 1) this.fixDoubleBlack(parent);
                    else parent.color = 1;
                }
            }
        }
    }

    insert(data: T): boolean {
        // search for a position to insert
        let parent = this.root;
        while (parent) {
            if (this.lt(data, parent.data)) {
                if (!parent.left) break;
                else parent = parent.left;
            } else if (this.lt(parent.data, data)) {
                if (!parent.right) break;
                else parent = parent.right;
            } else break;
        }

        // insert node into parent
        const node = new RBTreeNode(data);
        if (!parent) this.root = node;
        else if (this.lt(node.data, parent.data)) parent.left = node;
        else if (this.lt(parent.data, node.data)) parent.right = node;
        else {
            parent.count++;
            return false;
        }
        node.parent = parent;
        this.fixAfterInsert(node);
        return true;
    }

    search(predicate: (val: T) => boolean, direction: 'left' | 'right'): T | undefined {
        let p = this.root;
        let result = null;
        while (p) {
            if (predicate(p.data)) {
                result = p;
                p = p[direction];
            } else {
                p = p[direction === 'left' ? 'right' : 'left'];
            }
        }
        return result?.data;
    }

    find(data: T): RBTreeNode<T> | null {
        let p = this.root;
        while (p) {
            if (this.lt(data, p.data)) {
                p = p.left;
            } else if (this.lt(p.data, data)) {
                p = p.right;
            } else break;
        }
        return p ?? null;
    }

    count(data: T): number {
        const node = this.find(data);
        return node ? node.count : 0;
    }

    *inOrder(root: RBTreeNode<T> = this.root!): Generator<T, undefined, void> {
        if (!root) return;
        for (const v of this.inOrder(root.left!)) yield v;
        yield root.data;
        for (const v of this.inOrder(root.right!)) yield v;
    }

    *reverseInOrder(root: RBTreeNode<T> = this.root!): Generator<T, undefined, void> {
        if (!root) return;
        for (const v of this.reverseInOrder(root.right!)) yield v;
        yield root.data;
        for (const v of this.reverseInOrder(root.left!)) yield v;
    }
}

class TreeMap<K = number, V = unknown> {
    _size: number;
    tree: RBTree<K>;
    map: Map<K, V> = new Map();
    compare: Compare<K>;
    constructor(
        collection: Array<[K, V]> | Compare<K> = [],
        compare: Compare<K> = (l: K, r: K) => (l < r ? -1 : l > r ? 1 : 0),
    ) {
        if (typeof collection === 'function') {
            compare = collection;
            collection = [];
        }
        this._size = 0;
        this.compare = compare;
        this.tree = new RBTree(compare);
        for (const [key, val] of collection) this.set(key, val);
    }

    size(): number {
        return this._size;
    }

    has(key: K): boolean {
        return !!this.tree.find(key);
    }

    get(key: K): V | undefined {
        return this.map.get(key);
    }

    set(key: K, val: V): boolean {
        const successful = this.tree.insert(key);
        this._size += successful ? 1 : 0;
        this.map.set(key, val);
        return successful;
    }

    delete(key: K): boolean {
        const deleted = this.tree.deleteAll(key);
        this._size -= deleted ? 1 : 0;
        return deleted;
    }

    ceil(target: K): [K, V] | undefined {
        return this.toKeyValue(this.tree.search(key => this.compare(key, target) >= 0, 'left'));
    }

    floor(target: K): [K, V] | undefined {
        return this.toKeyValue(this.tree.search(key => this.compare(key, target) <= 0, 'right'));
    }

    higher(target: K): [K, V] | undefined {
        return this.toKeyValue(this.tree.search(key => this.compare(key, target) > 0, 'left'));
    }

    lower(target: K): [K, V] | undefined {
        return this.toKeyValue(this.tree.search(key => this.compare(key, target) < 0, 'right'));
    }

    first(): [K, V] | undefined {
        return this.toKeyValue(this.tree.inOrder().next().value);
    }

    last(): [K, V] | undefined {
        return this.toKeyValue(this.tree.reverseInOrder().next().value);
    }

    shift(): [K, V] | undefined {
        const first = this.first();
        if (first === undefined) return undefined;
        this.delete(first[0]);
        return first;
    }

    pop(): [K, V] | undefined {
        const last = this.last();
        if (last === undefined) return undefined;
        this.delete(last[0]);
        return last;
    }

    toKeyValue(key: K): [K, V];
    toKeyValue(key: undefined): undefined;
    toKeyValue(key: K | undefined): [K, V] | undefined;
    toKeyValue(key: K | undefined): [K, V] | undefined {
        return key != null ? [key, this.map.get(key)!] : undefined;
    }

    *[Symbol.iterator](): Generator<[K, V], void, void> {
        for (const key of this.keys()) yield this.toKeyValue(key);
    }

    *keys(): Generator<K, void, void> {
        for (const key of this.tree.inOrder()) yield key;
    }

    *values(): Generator<V, undefined, void> {
        for (const key of this.keys()) yield this.map.get(key)!;
        return undefined;
    }

    *rkeys(): Generator<K, undefined, void> {
        for (const key of this.tree.reverseInOrder()) yield key;
        return undefined;
    }

    *rvalues(): Generator<V, undefined, void> {
        for (const key of this.rkeys()) yield this.map.get(key)!;
        return undefined;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>Alice 手中有一把牌，她想要重新排列这些牌，分成若干组，使每一组的牌数都是 <code>groupSize</code> ，并且由 <code>groupSize</code> 张连续的牌组成。</p>

<p>给你一个整数数组 <code>hand</code> 其中 <code>hand[i]</code> 是写在第 <code>i</code> 张牌上的<strong>数值</strong>。如果她可能重新排列这些牌，返回 <code>true</code> ；否则，返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<ol>
</ol>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
<strong>输出：</strong>true
<strong>解释：</strong>Alice 手中的牌可以被重新排列为 <code>[1,2,3]，[2,3,4]，[6,7,8]</code>。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>hand = [1,2,3,4,5], groupSize = 4
<strong>输出：</strong>false
<strong>解释：</strong>Alice 手中的牌无法被重新排列成几个大小为 4 的组。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= hand.length &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= hand[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= groupSize &lt;= hand.length</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>注意：</strong>此题目与 1296 重复：<a href="https://leetcode.cn/problems/divide-array-in-sets-of-k-consecutive-numbers/" target="_blank">https://leetcode.cn/problems/divide-array-in-sets-of-k-consecutive-numbers/</a></p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 排序

我们首先判断数组 $\textit{hand}$ 的长度是否能被 $\textit{groupSize}$ 整除，如果不能整除，说明无法将数组划分成若干个长度为 $\textit{groupSize}$ 的子数组，直接返回 $\text{false}$。

接下来，我们用一个哈希表 $\textit{cnt}$ 统计数组 $\textit{hand}$ 中每个数字出现的次数，然后对数组 $\textit{hand}$ 进行排序。

然后，我们遍历排序后的数组 $\textit{hand}$，对于每个数字 $x$，如果 $\textit{cnt}[x]$ 不为 $0$，我们枚举 $x$ 到 $x+\textit{groupSize}-1$ 的每个数字 $y$，如果 $\textit{cnt}[y]$ 为 $0$，说明无法将数组划分成若干个长度为 $\textit{groupSize}$ 的子数组，直接返回 $\text{false}$。否则，我们将 $\textit{cnt}[y]$ 减 $1$。

遍历结束后，说明可以将数组划分成若干个长度为 $\textit{groupSize}$ 的子数组，返回 $\text{true}$。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 $\textit{hand}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        if len(hand) % groupSize:
            return False
        cnt = Counter(hand)
        for x in sorted(hand):
            if cnt[x]:
                for y in range(x, x + groupSize):
                    if cnt[y] == 0:
                        return False
                    cnt[y] -= 1
        return True
```

#### Java

```java
class Solution {
    public boolean isNStraightHand(int[] hand, int groupSize) {
        if (hand.length % groupSize != 0) {
            return false;
        }
        Arrays.sort(hand);
        Map<Integer, Integer> cnt = new HashMap<>();
        for (int x : hand) {
            cnt.merge(x, 1, Integer::sum);
        }
        for (int x : hand) {
            if (cnt.getOrDefault(x, 0) > 0) {
                for (int y = x; y < x + groupSize; ++y) {
                    if (cnt.merge(y, -1, Integer::sum) < 0) {
                        return false;
                    }
                }
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
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize) {
            return false;
        }
        ranges::sort(hand);
        unordered_map<int, int> cnt;
        for (int x : hand) {
            ++cnt[x];
        }
        for (int x : hand) {
            if (cnt.contains(x)) {
                for (int y = x; y < x + groupSize; ++y) {
                    if (!cnt.contains(y)) {
                        return false;
                    }
                    if (--cnt[y] == 0) {
                        cnt.erase(y);
                    }
                }
            }
        }
        return true;
    }
};
```

#### Go

```go
func isNStraightHand(hand []int, groupSize int) bool {
	if len(hand)%groupSize != 0 {
		return false
	}
	sort.Ints(hand)
	cnt := map[int]int{}
	for _, x := range hand {
		cnt[x]++
	}
	for _, x := range hand {
		if cnt[x] > 0 {
			for y := x; y < x+groupSize; y++ {
				if cnt[y] == 0 {
					return false
				}
				cnt[y]--
			}
		}
	}
	return true
}
```

#### TypeScript

```ts
function isNStraightHand(hand: number[], groupSize: number): boolean {
    if (hand.length % groupSize !== 0) {
        return false;
    }
    const cnt = new Map<number, number>();
    for (const x of hand) {
        cnt.set(x, (cnt.get(x) || 0) + 1);
    }
    hand.sort((a, b) => a - b);
    for (const x of hand) {
        if (cnt.get(x)! > 0) {
            for (let y = x; y < x + groupSize; y++) {
                if ((cnt.get(y) || 0) === 0) {
                    return false;
                }
                cnt.set(y, cnt.get(y)! - 1);
            }
        }
    }
    return true;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：有序集合

与方法一类似，我们首先判断数组 $\textit{hand}$ 的长度是否能被 $\textit{groupSize}$ 整除，如果不能整除，说明无法将数组划分成若干个长度为 $\textit{groupSize}$ 的子数组，直接返回 $\text{false}$。

接下来，我们用一个有序集合 $\textit{sd}$ 统计数组 $\textit{hand}$ 中每个数字出现的次数。

然后，我们循环取出有序集合中的最小值 $x$，然后枚举 $x$ 到 $x+\textit{groupSize}-1$ 的每个数字 $y$，如果这些数字在有序集合中出现的次数都不为 $0$，则我们将这些数字的出现次数减 $1$，如果出现次数减 $1$ 后为 $0$，则将该数字从有序集合中删除，否则说明无法将数组划分成若干个长度为 $\textit{groupSize}$ 的子数组，返回 $\text{false}$。如果可以将数组划分成若干个长度为 $\textit{groupSize}$ 的子数组，则遍历结束后返回 $\text{true}$。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 $\textit{hand}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        if len(hand) % groupSize:
            return False
        cnt = Counter(hand)
        sd = SortedDict(cnt)
        while sd:
            x = next(iter(sd))
            for y in range(x, x + groupSize):
                if y not in sd:
                    return False
                if sd[y] == 1:
                    del sd[y]
                else:
                    sd[y] -= 1
        return True
```

#### Java

```java
class Solution {
    public boolean isNStraightHand(int[] hand, int groupSize) {
        if (hand.length % groupSize != 0) {
            return false;
        }
        TreeMap<Integer, Integer> tm = new TreeMap<>();
        for (int x : hand) {
            tm.merge(x, 1, Integer::sum);
        }
        while (!tm.isEmpty()) {
            int x = tm.firstKey();
            for (int y = x; y < x + groupSize; ++y) {
                int t = tm.merge(y, -1, Integer::sum);
                if (t < 0) {
                    return false;
                }
                if (t == 0) {
                    tm.remove(y);
                }
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
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize) {
            return false;
        }
        map<int, int> mp;
        for (int x : hand) {
            ++mp[x];
        }
        while (!mp.empty()) {
            int x = mp.begin()->first;
            for (int y = x; y < x + groupSize; ++y) {
                if (!mp.contains(y)) {
                    return false;
                }
                if (--mp[y] == 0) {
                    mp.erase(y);
                }
            }
        }
        return true;
    }
};
```

#### Go

```go
func isNStraightHand(hand []int, groupSize int) bool {
	if len(hand)%groupSize != 0 {
		return false
	}
	tm := treemap.NewWithIntComparator()
	for _, x := range hand {
		if v, ok := tm.Get(x); ok {
			tm.Put(x, v.(int)+1)
		} else {
			tm.Put(x, 1)
		}
	}
	for !tm.Empty() {
		x, _ := tm.Min()
		for y := x.(int); y < x.(int)+groupSize; y++ {
			if v, ok := tm.Get(y); ok {
				if v.(int) == 1 {
					tm.Remove(y)
				} else {
					tm.Put(y, v.(int)-1)
				}
			} else {
				return false
			}
		}
	}
	return true
}
```

#### TypeScript

```ts
function isNStraightHand(hand: number[], groupSize: number): boolean {
    if (hand.length % groupSize !== 0) {
        return false;
    }
    const tm = new TreeMap<number, number>();
    for (const x of hand) {
        tm.set(x, (tm.get(x) || 0) + 1);
    }
    while (tm.size()) {
        const x = tm.first()![0];
        for (let y = x; y < x + groupSize; ++y) {
            if (!tm.has(y)) {
                return false;
            }
            if (tm.get(y)! === 1) {
                tm.delete(y);
            } else {
                tm.set(y, tm.get(y)! - 1);
            }
        }
    }
    return true;
}

type Compare<T> = (lhs: T, rhs: T) => number;

class RBTreeNode<T = number> {
    data: T;
    count: number;
    left: RBTreeNode<T> | null;
    right: RBTreeNode<T> | null;
    parent: RBTreeNode<T> | null;
    color: number;
    constructor(data: T) {
        this.data = data;
        this.left = this.right = this.parent = null;
        this.color = 0;
        this.count = 1;
    }

    sibling(): RBTreeNode<T> | null {
        if (!this.parent) return null; // sibling null if no parent
        return this.isOnLeft() ? this.parent.right : this.parent.left;
    }

    isOnLeft(): boolean {
        return this === this.parent!.left;
    }

    hasRedChild(): boolean {
        return (
            Boolean(this.left && this.left.color === 0) ||
            Boolean(this.right && this.right.color === 0)
        );
    }
}

class RBTree<T> {
    root: RBTreeNode<T> | null;
    lt: (l: T, r: T) => boolean;
    constructor(compare: Compare<T> = (l: T, r: T) => (l < r ? -1 : l > r ? 1 : 0)) {
        this.root = null;
        this.lt = (l: T, r: T) => compare(l, r) < 0;
    }

    rotateLeft(pt: RBTreeNode<T>): void {
        const right = pt.right!;
        pt.right = right.left;

        if (pt.right) pt.right.parent = pt;
        right.parent = pt.parent;

        if (!pt.parent) this.root = right;
        else if (pt === pt.parent.left) pt.parent.left = right;
        else pt.parent.right = right;

        right.left = pt;
        pt.parent = right;
    }

    rotateRight(pt: RBTreeNode<T>): void {
        const left = pt.left!;
        pt.left = left.right;

        if (pt.left) pt.left.parent = pt;
        left.parent = pt.parent;

        if (!pt.parent) this.root = left;
        else if (pt === pt.parent.left) pt.parent.left = left;
        else pt.parent.right = left;

        left.right = pt;
        pt.parent = left;
    }

    swapColor(p1: RBTreeNode<T>, p2: RBTreeNode<T>): void {
        const tmp = p1.color;
        p1.color = p2.color;
        p2.color = tmp;
    }

    swapData(p1: RBTreeNode<T>, p2: RBTreeNode<T>): void {
        const tmp = p1.data;
        p1.data = p2.data;
        p2.data = tmp;
    }

    fixAfterInsert(pt: RBTreeNode<T>): void {
        let parent = null;
        let grandParent = null;

        while (pt !== this.root && pt.color !== 1 && pt.parent?.color === 0) {
            parent = pt.parent;
            grandParent = pt.parent.parent;

            /*  Case : A
                Parent of pt is left child of Grand-parent of pt */
            if (parent === grandParent?.left) {
                const uncle = grandParent.right;

                /* Case : 1
                   The uncle of pt is also red
                   Only Recoloring required */
                if (uncle && uncle.color === 0) {
                    grandParent.color = 0;
                    parent.color = 1;
                    uncle.color = 1;
                    pt = grandParent;
                } else {
                    /* Case : 2
                       pt is right child of its parent
                       Left-rotation required */
                    if (pt === parent.right) {
                        this.rotateLeft(parent);
                        pt = parent;
                        parent = pt.parent;
                    }

                    /* Case : 3
                       pt is left child of its parent
                       Right-rotation required */
                    this.rotateRight(grandParent);
                    this.swapColor(parent!, grandParent);
                    pt = parent!;
                }
            } else {
                /* Case : B
               Parent of pt is right child of Grand-parent of pt */
                const uncle = grandParent!.left;

                /*  Case : 1
                    The uncle of pt is also red
                    Only Recoloring required */
                if (uncle != null && uncle.color === 0) {
                    grandParent!.color = 0;
                    parent.color = 1;
                    uncle.color = 1;
                    pt = grandParent!;
                } else {
                    /* Case : 2
                       pt is left child of its parent
                       Right-rotation required */
                    if (pt === parent.left) {
                        this.rotateRight(parent);
                        pt = parent;
                        parent = pt.parent;
                    }

                    /* Case : 3
                       pt is right child of its parent
                       Left-rotation required */
                    this.rotateLeft(grandParent!);
                    this.swapColor(parent!, grandParent!);
                    pt = parent!;
                }
            }
        }
        this.root!.color = 1;
    }

    delete(val: T): boolean {
        const node = this.find(val);
        if (!node) return false;
        node.count--;
        if (!node.count) this.deleteNode(node);
        return true;
    }

    deleteAll(val: T): boolean {
        const node = this.find(val);
        if (!node) return false;
        this.deleteNode(node);
        return true;
    }

    deleteNode(v: RBTreeNode<T>): void {
        const u = BSTreplace(v);

        // True when u and v are both black
        const uvBlack = (u === null || u.color === 1) && v.color === 1;
        const parent = v.parent!;

        if (!u) {
            // u is null therefore v is leaf
            if (v === this.root) this.root = null;
            // v is root, making root null
            else {
                if (uvBlack) {
                    // u and v both black
                    // v is leaf, fix double black at v
                    this.fixDoubleBlack(v);
                } else {
                    // u or v is red
                    if (v.sibling()) {
                        // sibling is not null, make it red"
                        v.sibling()!.color = 0;
                    }
                }
                // delete v from the tree
                if (v.isOnLeft()) parent.left = null;
                else parent.right = null;
            }
            return;
        }

        if (!v.left || !v.right) {
            // v has 1 child
            if (v === this.root) {
                // v is root, assign the value of u to v, and delete u
                v.data = u.data;
                v.left = v.right = null;
            } else {
                // Detach v from tree and move u up
                if (v.isOnLeft()) parent.left = u;
                else parent.right = u;
                u.parent = parent;
                if (uvBlack) this.fixDoubleBlack(u);
                // u and v both black, fix double black at u
                else u.color = 1; // u or v red, color u black
            }
            return;
        }

        // v has 2 children, swap data with successor and recurse
        this.swapData(u, v);
        this.deleteNode(u);

        // find node that replaces a deleted node in BST
        function BSTreplace(x: RBTreeNode<T>): RBTreeNode<T> | null {
            // when node have 2 children
            if (x.left && x.right) return successor(x.right);
            // when leaf
            if (!x.left && !x.right) return null;
            // when single child
            return x.left ?? x.right;
        }
        // find node that do not have a left child
        // in the subtree of the given node
        function successor(x: RBTreeNode<T>): RBTreeNode<T> {
            let temp = x;
            while (temp.left) temp = temp.left;
            return temp;
        }
    }

    fixDoubleBlack(x: RBTreeNode<T>): void {
        if (x === this.root) return; // Reached root

        const sibling = x.sibling();
        const parent = x.parent!;
        if (!sibling) {
            // No sibiling, double black pushed up
            this.fixDoubleBlack(parent);
        } else {
            if (sibling.color === 0) {
                // Sibling red
                parent.color = 0;
                sibling.color = 1;
                if (sibling.isOnLeft()) this.rotateRight(parent);
                // left case
                else this.rotateLeft(parent); // right case
                this.fixDoubleBlack(x);
            } else {
                // Sibling black
                if (sibling.hasRedChild()) {
                    // at least 1 red children
                    if (sibling.left && sibling.left.color === 0) {
                        if (sibling.isOnLeft()) {
                            // left left
                            sibling.left.color = sibling.color;
                            sibling.color = parent.color;
                            this.rotateRight(parent);
                        } else {
                            // right left
                            sibling.left.color = parent.color;
                            this.rotateRight(sibling);
                            this.rotateLeft(parent);
                        }
                    } else {
                        if (sibling.isOnLeft()) {
                            // left right
                            sibling.right!.color = parent.color;
                            this.rotateLeft(sibling);
                            this.rotateRight(parent);
                        } else {
                            // right right
                            sibling.right!.color = sibling.color;
                            sibling.color = parent.color;
                            this.rotateLeft(parent);
                        }
                    }
                    parent.color = 1;
                } else {
                    // 2 black children
                    sibling.color = 0;
                    if (parent.color === 1) this.fixDoubleBlack(parent);
                    else parent.color = 1;
                }
            }
        }
    }

    insert(data: T): boolean {
        // search for a position to insert
        let parent = this.root;
        while (parent) {
            if (this.lt(data, parent.data)) {
                if (!parent.left) break;
                else parent = parent.left;
            } else if (this.lt(parent.data, data)) {
                if (!parent.right) break;
                else parent = parent.right;
            } else break;
        }

        // insert node into parent
        const node = new RBTreeNode(data);
        if (!parent) this.root = node;
        else if (this.lt(node.data, parent.data)) parent.left = node;
        else if (this.lt(parent.data, node.data)) parent.right = node;
        else {
            parent.count++;
            return false;
        }
        node.parent = parent;
        this.fixAfterInsert(node);
        return true;
    }

    search(predicate: (val: T) => boolean, direction: 'left' | 'right'): T | undefined {
        let p = this.root;
        let result = null;
        while (p) {
            if (predicate(p.data)) {
                result = p;
                p = p[direction];
            } else {
                p = p[direction === 'left' ? 'right' : 'left'];
            }
        }
        return result?.data;
    }

    find(data: T): RBTreeNode<T> | null {
        let p = this.root;
        while (p) {
            if (this.lt(data, p.data)) {
                p = p.left;
            } else if (this.lt(p.data, data)) {
                p = p.right;
            } else break;
        }
        return p ?? null;
    }

    count(data: T): number {
        const node = this.find(data);
        return node ? node.count : 0;
    }

    *inOrder(root: RBTreeNode<T> = this.root!): Generator<T, undefined, void> {
        if (!root) return;
        for (const v of this.inOrder(root.left!)) yield v;
        yield root.data;
        for (const v of this.inOrder(root.right!)) yield v;
    }

    *reverseInOrder(root: RBTreeNode<T> = this.root!): Generator<T, undefined, void> {
        if (!root) return;
        for (const v of this.reverseInOrder(root.right!)) yield v;
        yield root.data;
        for (const v of this.reverseInOrder(root.left!)) yield v;
    }
}

class TreeMap<K = number, V = unknown> {
    _size: number;
    tree: RBTree<K>;
    map: Map<K, V> = new Map();
    compare: Compare<K>;
    constructor(
        collection: Array<[K, V]> | Compare<K> = [],
        compare: Compare<K> = (l: K, r: K) => (l < r ? -1 : l > r ? 1 : 0),
    ) {
        if (typeof collection === 'function') {
            compare = collection;
            collection = [];
        }
        this._size = 0;
        this.compare = compare;
        this.tree = new RBTree(compare);
        for (const [key, val] of collection) this.set(key, val);
    }

    size(): number {
        return this._size;
    }

    has(key: K): boolean {
        return !!this.tree.find(key);
    }

    get(key: K): V | undefined {
        return this.map.get(key);
    }

    set(key: K, val: V): boolean {
        const successful = this.tree.insert(key);
        this._size += successful ? 1 : 0;
        this.map.set(key, val);
        return successful;
    }

    delete(key: K): boolean {
        const deleted = this.tree.deleteAll(key);
        this._size -= deleted ? 1 : 0;
        return deleted;
    }

    ceil(target: K): [K, V] | undefined {
        return this.toKeyValue(this.tree.search(key => this.compare(key, target) >= 0, 'left'));
    }

    floor(target: K): [K, V] | undefined {
        return this.toKeyValue(this.tree.search(key => this.compare(key, target) <= 0, 'right'));
    }

    higher(target: K): [K, V] | undefined {
        return this.toKeyValue(this.tree.search(key => this.compare(key, target) > 0, 'left'));
    }

    lower(target: K): [K, V] | undefined {
        return this.toKeyValue(this.tree.search(key => this.compare(key, target) < 0, 'right'));
    }

    first(): [K, V] | undefined {
        return this.toKeyValue(this.tree.inOrder().next().value);
    }

    last(): [K, V] | undefined {
        return this.toKeyValue(this.tree.reverseInOrder().next().value);
    }

    shift(): [K, V] | undefined {
        const first = this.first();
        if (first === undefined) return undefined;
        this.delete(first[0]);
        return first;
    }

    pop(): [K, V] | undefined {
        const last = this.last();
        if (last === undefined) return undefined;
        this.delete(last[0]);
        return last;
    }

    toKeyValue(key: K): [K, V];
    toKeyValue(key: undefined): undefined;
    toKeyValue(key: K | undefined): [K, V] | undefined;
    toKeyValue(key: K | undefined): [K, V] | undefined {
        return key != null ? [key, this.map.get(key)!] : undefined;
    }

    *[Symbol.iterator](): Generator<[K, V], void, void> {
        for (const key of this.keys()) yield this.toKeyValue(key);
    }

    *keys(): Generator<K, void, void> {
        for (const key of this.tree.inOrder()) yield key;
    }

    *values(): Generator<V, undefined, void> {
        for (const key of this.keys()) yield this.map.get(key)!;
        return undefined;
    }

    *rkeys(): Generator<K, undefined, void> {
        for (const key of this.tree.reverseInOrder()) yield key;
        return undefined;
    }

    *rvalues(): Generator<V, undefined, void> {
        for (const key of this.rkeys()) yield this.map.get(key)!;
        return undefined;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [847. 访问所有节点的最短路径](https://leetcode.cn/problems/shortest-path-visiting-all-nodes){#847}

{{< tabs "847" >}}

{{% tab "python" %}}
```python
class Solution:
    def shortestPathLength(self, graph: List[List[int]]) -> int:
        n = len(graph)

        def f(state):
            return sum(((state >> i) & 1) == 0 for i in range(n))

        q = []
        dist = [[inf] * (1 << n) for _ in range(n)]
        for i in range(n):
            heappush(q, (f(1 << i), i, 1 << i))
            dist[i][1 << i] = 0
        while q:
            _, u, state = heappop(q)
            if state == (1 << n) - 1:
                return dist[u][state]
            for v in graph[u]:
                nxt = state | (1 << v)
                if dist[v][nxt] > dist[u][state] + 1:
                    dist[v][nxt] = dist[u][state] + 1
                    heappush(q, (dist[v][nxt] + f(nxt), v, nxt))
        return 0
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int n;

    public int shortestPathLength(int[][] graph) {
        n = graph.length;
        int[][] dist = new int[n][1 << n];
        for (int i = 0; i < n; ++i) {
            Arrays.fill(dist[i], Integer.MAX_VALUE);
        }
        PriorityQueue<int[]> q = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        for (int i = 0; i < n; ++i) {
            q.offer(new int[] {f(1 << i), i, 1 << i});
            dist[i][1 << i] = 0;
        }
        while (!q.isEmpty()) {
            int[] p = q.poll();
            int u = p[1], state = p[2];
            if (state == (1 << n) - 1) {
                return dist[u][state];
            }
            for (int v : graph[u]) {
                int nxt = state | (1 << v);
                if (dist[v][nxt] > dist[u][state] + 1) {
                    dist[v][nxt] = dist[u][state] + 1;
                    q.offer(new int[] {dist[v][nxt] + f(nxt), v, nxt});
                }
            }
        }
        return 0;
    }

    private int f(int state) {
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (((state >> i) & 1) == 0) {
                ++ans;
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
    int n;

    int shortestPathLength(vector<vector<int>>& graph) {
        n = graph.size();
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;
        vector<vector<int>> dist(n, vector<int>(1 << n, INT_MAX));
        for (int i = 0; i < n; ++i) {
            q.push({f(1 << i), i, 1 << i});
            dist[i][1 << i] = 0;
        }
        while (!q.empty()) {
            auto [_, u, state] = q.top();
            q.pop();
            if (state == (1 << n) - 1) return dist[u][state];
            for (int v : graph[u]) {
                int nxt = state | (1 << v);
                if (dist[v][nxt] > dist[u][state] + 1) {
                    dist[v][nxt] = dist[u][state] + 1;
                    q.push({dist[v][nxt] + f(nxt), v, nxt});
                }
            }
        }
        return 0;
    }

    int f(int state) {
        int ans = 0;
        for (int i = 0; i < n; ++i)
            if (((state >> i) & 1) == 0)
                ++ans;
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func shortestPathLength(graph [][]int) int {
	n := len(graph)
	q := [][2]int{}
	vis := make([][]bool, n)
	for i := range vis {
		vis[i] = make([]bool, 1<<n)
		vis[i][1<<i] = true
		q = append(q, [2]int{i, 1 << i})
	}
	for ans := 0; ; ans++ {
		for k := len(q); k > 0; k-- {
			p := q[0]
			q = q[1:]
			i, st := p[0], p[1]
			if st == (1<<n)-1 {
				return ans
			}
			for _, j := range graph[i] {
				nst := st | 1<<j
				if !vis[j][nst] {
					vis[j][nst] = true
					q = append(q, [2]int{j, nst})
				}
			}
		}
	}
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function shortestPathLength(graph: number[][]): number {
    const n = graph.length;
    const q: number[][] = [];
    const vis: boolean[][] = new Array(n).fill(false).map(() => new Array(1 << n).fill(false));
    for (let i = 0; i < n; ++i) {
        q.push([i, 1 << i]);
        vis[i][1 << i] = true;
    }
    for (let ans = 0; ; ++ans) {
        for (let k = q.length; k; --k) {
            const [i, st] = q.shift()!;
            if (st === (1 << n) - 1) {
                return ans;
            }
            for (const j of graph[i]) {
                const nst = st | (1 << j);
                if (!vis[j][nst]) {
                    vis[j][nst] = true;
                    q.push([j, nst]);
                }
            }
        }
    }
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::VecDeque;

impl Solution {
    #[allow(dead_code)]
    pub fn shortest_path_length(graph: Vec<Vec<i32>>) -> i32 {
        let n = graph.len();
        let mut vis = vec![vec![false; 1 << n]; n];
        let mut q = VecDeque::new();

        // Initialize the queue
        for i in 0..n {
            q.push_back(((i, 1 << i), 0));
            vis[i][1 << i] = true;
        }

        // Begin BFS
        while !q.is_empty() {
            let ((i, st), count) = q.pop_front().unwrap();
            if st == (1 << n) - 1 {
                return count;
            }
            // If the path has not been visited
            for j in &graph[i] {
                let nst = st | (1 << *j);
                if !vis[*j as usize][nst] {
                    q.push_back(((*j as usize, nst), count + 1));
                    vis[*j as usize][nst] = true;
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

<p>存在一个由 <code>n</code> 个节点组成的无向连通图，图中的节点按从 <code>0</code> 到 <code>n - 1</code> 编号。</p>

<p>给你一个数组 <code>graph</code> 表示这个图。其中，<code>graph[i]</code> 是一个列表，由所有与节点 <code>i</code> 直接相连的节点组成。</p>

<p>返回能够访问所有节点的最短路径的长度。你可以在任一节点开始和停止，也可以多次重访节点，并且可以重用边。</p>

<p>&nbsp;</p>

<ol>
</ol>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0800-0899/0847.Shortest%20Path%20Visiting%20All%20Nodes/images/shortest1-graph.jpg" style="width: 222px; height: 183px;" />
<pre>
<strong>输入：</strong>graph = [[1,2,3],[0],[0],[0]]
<strong>输出：</strong>4
<strong>解释：</strong>一种可能的路径为 [1,0,2,0,3]</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0800-0899/0847.Shortest%20Path%20Visiting%20All%20Nodes/images/shortest2-graph.jpg" style="width: 382px; height: 222px;" /></p>

<pre>
<strong>输入：</strong>graph = [[1],[0,2,4],[1,3,4],[2],[1,2]]
<strong>输出：</strong>4
<strong>解释：</strong>一种可能的路径为 [0,1,4,2,3]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == graph.length</code></li>
	<li><code>1 &lt;= n &lt;= 12</code></li>
	<li><code>0 &lt;= graph[i].length &lt;&nbsp;n</code></li>
	<li><code>graph[i]</code> 不包含 <code>i</code></li>
	<li>如果 <code>graph[a]</code> 包含 <code>b</code> ，那么 <code>graph[b]</code> 也包含 <code>a</code></li>
	<li>输入的图总是连通图</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：状态压缩 + BFS

我们注意到 $n$ 的范围不超过 $12$，因此，我们可以用一个 $12$ 位的二进制数来表示每个节点的访问情况，其中第 $i$ 位为 $1$ 表示第 $i$ 个节点已经被访问过，为 $0$ 表示该节点还没有被访问过。

我们初始化队列 $q$，其中每个元素是一个二元素 $(i, st)$，表示当前位于节点 $i$，且已经遍历过的节点的集合为 $st$。初始时，队列中只有 $n$ 个元素，即 $(i, 2^i)$，表示可以从任一节点出发开始遍历。另外，我们用一个哈希表或数组 $vis$ 记录每个状态是否已经被搜索过，防止无效的重复搜索。

在 BFS 的过程中，我们每次取出队首元素 $(i, st)$，如果当前 $st$ 包含 $n$ 个 $1$，那么我们就找到了一条从起点出发的遍历路径，返回当前的步数即可。否则我们枚举当前节点 $i$ 的所有连边 $(i, j)$，如果 $(j, st \lor 2^j)$ 没有被搜索过，那么就将 $(j, st \lor 2^j)$ 加入队列 $q$ 中，并且用 $vis$ 记录它已经被搜索过。循环此过程，直到找到一条路径。

时间复杂度 $(n^2 \times 2^n)$，空间复杂度 $O(n \times 2^n)$。其中 $n$ 是图中的节点数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def shortestPathLength(self, graph: List[List[int]]) -> int:
        n = len(graph)
        q = deque()
        vis = set()
        for i in range(n):
            q.append((i, 1 << i))
            vis.add((i, 1 << i))
        ans = 0
        while 1:
            for _ in range(len(q)):
                i, st = q.popleft()
                if st == (1 << n) - 1:
                    return ans
                for j in graph[i]:
                    nst = st | 1 << j
                    if (j, nst) not in vis:
                        vis.add((j, nst))
                        q.append((j, nst))
            ans += 1
```

#### Java

```java
class Solution {
    public int shortestPathLength(int[][] graph) {
        int n = graph.length;
        Deque<int[]> q = new ArrayDeque<>();
        boolean[][] vis = new boolean[n][1 << n];
        for (int i = 0; i < n; ++i) {
            q.offer(new int[] {i, 1 << i});
            vis[i][1 << i] = true;
        }
        for (int ans = 0;; ++ans) {
            for (int k = q.size(); k > 0; --k) {
                var p = q.poll();
                int i = p[0], st = p[1];
                if (st == (1 << n) - 1) {
                    return ans;
                }
                for (int j : graph[i]) {
                    int nst = st | 1 << j;
                    if (!vis[j][nst]) {
                        vis[j][nst] = true;
                        q.offer(new int[] {j, nst});
                    }
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
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<pair<int, int>> q;
        bool vis[n][1 << n];
        memset(vis, false, sizeof(vis));
        for (int i = 0; i < n; ++i) {
            q.emplace(i, 1 << i);
            vis[i][1 << i] = true;
        }
        for (int ans = 0;; ++ans) {
            for (int k = q.size(); k; --k) {
                auto [i, st] = q.front();
                q.pop();
                if (st == (1 << n) - 1) {
                    return ans;
                }
                for (int j : graph[i]) {
                    int nst = st | 1 << j;
                    if (!vis[j][nst]) {
                        vis[j][nst] = true;
                        q.emplace(j, nst);
                    }
                }
            }
        }
    }
};
```

#### Go

```go
func shortestPathLength(graph [][]int) int {
	n := len(graph)
	q := [][2]int{}
	vis := make([][]bool, n)
	for i := range vis {
		vis[i] = make([]bool, 1<<n)
		vis[i][1<<i] = true
		q = append(q, [2]int{i, 1 << i})
	}
	for ans := 0; ; ans++ {
		for k := len(q); k > 0; k-- {
			p := q[0]
			q = q[1:]
			i, st := p[0], p[1]
			if st == (1<<n)-1 {
				return ans
			}
			for _, j := range graph[i] {
				nst := st | 1<<j
				if !vis[j][nst] {
					vis[j][nst] = true
					q = append(q, [2]int{j, nst})
				}
			}
		}
	}
}
```

#### TypeScript

```ts
function shortestPathLength(graph: number[][]): number {
    const n = graph.length;
    const q: number[][] = [];
    const vis: boolean[][] = new Array(n).fill(false).map(() => new Array(1 << n).fill(false));
    for (let i = 0; i < n; ++i) {
        q.push([i, 1 << i]);
        vis[i][1 << i] = true;
    }
    for (let ans = 0; ; ++ans) {
        for (let k = q.length; k; --k) {
            const [i, st] = q.shift()!;
            if (st === (1 << n) - 1) {
                return ans;
            }
            for (const j of graph[i]) {
                const nst = st | (1 << j);
                if (!vis[j][nst]) {
                    vis[j][nst] = true;
                    q.push([j, nst]);
                }
            }
        }
    }
}
```

#### Rust

```rust
use std::collections::VecDeque;

impl Solution {
    #[allow(dead_code)]
    pub fn shortest_path_length(graph: Vec<Vec<i32>>) -> i32 {
        let n = graph.len();
        let mut vis = vec![vec![false; 1 << n]; n];
        let mut q = VecDeque::new();

        // Initialize the queue
        for i in 0..n {
            q.push_back(((i, 1 << i), 0));
            vis[i][1 << i] = true;
        }

        // Begin BFS
        while !q.is_empty() {
            let ((i, st), count) = q.pop_front().unwrap();
            if st == (1 << n) - 1 {
                return count;
            }
            // If the path has not been visited
            for j in &graph[i] {
                let nst = st | (1 << *j);
                if !vis[*j as usize][nst] {
                    q.push_back(((*j as usize, nst), count + 1));
                    vis[*j as usize][nst] = true;
                }
            }
        }

        -1
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：BFS(A\* 算法)

因为每条边权值一样，所以用 BFS 就能得出最短路径，过程中可以用**状态压缩**记录节点的访问情况。另外，同一个节点 u 以及对应的节点访问情况需要保证只被搜索过一次，因此可以用 `vis(u, state)` 表示是否已经被搜索过，防止无效的重复搜索。

本题也属于 BFS 最小步数模型，可以使用 A\* 算法优化搜索。

A\* 算法主要思想如下：

1. 将 BFS 队列转换为优先队列（小根堆）；
1. 队列中的每个元素为 `(dist[state] + f(state), state)`，`dist[state]` 表示从起点到当前 state 的距离，`f(state)` 表示从当前 state 到终点的估计距离，这两个距离之和作为堆排序的依据；
1. 当终点第一次出队时，说明找到了从起点到终点的最短路径，直接返回对应的 step；
1. `f(state)` 是估价函数，并且估价函数要满足 `f(state) <= g(state)`，其中 `g(state)` 表示 state 到终点的真实距离；
1. A\* 算法只能保证终点第一次出队时，即找到了一条从起点到终点的最小路径，不能保证其他点出队时也是从起点到当前点的最短路径。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def shortestPathLength(self, graph: List[List[int]]) -> int:
        n = len(graph)

        def f(state):
            return sum(((state >> i) & 1) == 0 for i in range(n))

        q = []
        dist = [[inf] * (1 << n) for _ in range(n)]
        for i in range(n):
            heappush(q, (f(1 << i), i, 1 << i))
            dist[i][1 << i] = 0
        while q:
            _, u, state = heappop(q)
            if state == (1 << n) - 1:
                return dist[u][state]
            for v in graph[u]:
                nxt = state | (1 << v)
                if dist[v][nxt] > dist[u][state] + 1:
                    dist[v][nxt] = dist[u][state] + 1
                    heappush(q, (dist[v][nxt] + f(nxt), v, nxt))
        return 0
```

#### Java

```java
class Solution {
    private int n;

    public int shortestPathLength(int[][] graph) {
        n = graph.length;
        int[][] dist = new int[n][1 << n];
        for (int i = 0; i < n; ++i) {
            Arrays.fill(dist[i], Integer.MAX_VALUE);
        }
        PriorityQueue<int[]> q = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        for (int i = 0; i < n; ++i) {
            q.offer(new int[] {f(1 << i), i, 1 << i});
            dist[i][1 << i] = 0;
        }
        while (!q.isEmpty()) {
            int[] p = q.poll();
            int u = p[1], state = p[2];
            if (state == (1 << n) - 1) {
                return dist[u][state];
            }
            for (int v : graph[u]) {
                int nxt = state | (1 << v);
                if (dist[v][nxt] > dist[u][state] + 1) {
                    dist[v][nxt] = dist[u][state] + 1;
                    q.offer(new int[] {dist[v][nxt] + f(nxt), v, nxt});
                }
            }
        }
        return 0;
    }

    private int f(int state) {
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (((state >> i) & 1) == 0) {
                ++ans;
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
    int n;

    int shortestPathLength(vector<vector<int>>& graph) {
        n = graph.size();
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;
        vector<vector<int>> dist(n, vector<int>(1 << n, INT_MAX));
        for (int i = 0; i < n; ++i) {
            q.push({f(1 << i), i, 1 << i});
            dist[i][1 << i] = 0;
        }
        while (!q.empty()) {
            auto [_, u, state] = q.top();
            q.pop();
            if (state == (1 << n) - 1) return dist[u][state];
            for (int v : graph[u]) {
                int nxt = state | (1 << v);
                if (dist[v][nxt] > dist[u][state] + 1) {
                    dist[v][nxt] = dist[u][state] + 1;
                    q.push({dist[v][nxt] + f(nxt), v, nxt});
                }
            }
        }
        return 0;
    }

    int f(int state) {
        int ans = 0;
        for (int i = 0; i < n; ++i)
            if (((state >> i) & 1) == 0)
                ++ans;
        return ans;
    }
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [848. 字母移位](https://leetcode.cn/problems/shifting-letters){#848}

{{< tabs "848" >}}

{{% tab "python" %}}
```python
class Solution:
    def shiftingLetters(self, s: str, shifts: List[int]) -> str:
        n, t = len(s), 0
        s = list(s)
        for i in range(n - 1, -1, -1):
            t += shifts[i]
            j = (ord(s[i]) - ord('a') + t) % 26
            s[i] = ascii_lowercase[j]
        return ''.join(s)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String shiftingLetters(String s, int[] shifts) {
        char[] cs = s.toCharArray();
        int n = cs.length;
        long t = 0;
        for (int i = n - 1; i >= 0; --i) {
            t += shifts[i];
            int j = (int) ((cs[i] - 'a' + t) % 26);
            cs[i] = (char) ('a' + j);
        }
        return String.valueOf(cs);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        long long t = 0;
        int n = s.size();
        for (int i = n - 1; ~i; --i) {
            t += shifts[i];
            int j = (s[i] - 'a' + t) % 26;
            s[i] = 'a' + j;
        }
        return s;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func shiftingLetters(s string, shifts []int) string {
	t := 0
	n := len(s)
	cs := []byte(s)
	for i := n - 1; i >= 0; i-- {
		t += shifts[i]
		j := (int(cs[i]-'a') + t) % 26
		cs[i] = byte('a' + j)
	}
	return string(cs)
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>有一个由小写字母组成的字符串 <code>s</code>，和一个长度相同的整数数组 <code>shifts</code>。</p>

<p>我们将字母表中的下一个字母称为原字母的 <em>移位</em>&nbsp;<code>shift()</code>&nbsp;（由于字母表是环绕的， <code>'z'</code>&nbsp;将会变成&nbsp;<code>'a'</code>）。</p>

<ul>
	<li>例如，<code>shift('a') = 'b'<font color="#333333"><font face="Helvetica Neue, Helvetica, Arial, sans-serif"><span style="font-size:14px"><span style="background-color:#ffffff">,&nbsp;</span></span></font></font></code><code>shift('t') = 'u'</code>,&nbsp;以及&nbsp;<code>shift('z') = 'a'</code>。</li>
</ul>

<p>对于每个&nbsp;<code>shifts[i] = x</code>&nbsp;， 我们会将 <code>s</code>&nbsp;中的前&nbsp;<code>i + 1</code>&nbsp;个字母移位&nbsp;<code>x</code>&nbsp;次。</p>

<p>返回 <em>将所有这些移位都应用到 <code>s</code> 后最终得到的字符串</em> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "abc", shifts = [3,5,9]
<strong>输出：</strong>"rpl"
<strong>解释： </strong>
我们以 "abc" 开始。
将 S 中的第 1 个字母移位 3 次后，我们得到 "dbc"。
再将 S 中的前 2 个字母移位 5 次后，我们得到 "igc"。
最后将 S 中的这 3 个字母移位 9 次后，我们得到答案 "rpl"。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> s = "aaa", shifts = [1,2,3]
<strong>输出:</strong> "gfd"
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code>&nbsp;由小写英文字母组成</li>
	<li><code>shifts.length == s.length</code></li>
	<li><code>0 &lt;= shifts[i] &lt;= 10<sup>9</sup></code></li>
</ul>
<span style="display:block"><span style="height:0px"><span style="position:absolute">​​​​​​</span></span></span>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：后缀和

对于字符串 $s$ 中的每个字符，我们需要计算其最终的偏移量，即 $\textit{shifts}[i]$ 与 $\textit{shifts}[i + 1]$ 与 $\textit{shifts}[i + 2]$ ... 的和。我们可以使用后缀和的思想，从后往前遍历 $\textit{shifts}$，计算每个字符的最终偏移量，然后对 $26$ 取模，得到最终的字符。

时间复杂度 $O(n)$，其中 $n$ 为字符串 $s$ 的长度。忽略答案的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def shiftingLetters(self, s: str, shifts: List[int]) -> str:
        n, t = len(s), 0
        s = list(s)
        for i in range(n - 1, -1, -1):
            t += shifts[i]
            j = (ord(s[i]) - ord('a') + t) % 26
            s[i] = ascii_lowercase[j]
        return ''.join(s)
```

#### Java

```java
class Solution {
    public String shiftingLetters(String s, int[] shifts) {
        char[] cs = s.toCharArray();
        int n = cs.length;
        long t = 0;
        for (int i = n - 1; i >= 0; --i) {
            t += shifts[i];
            int j = (int) ((cs[i] - 'a' + t) % 26);
            cs[i] = (char) ('a' + j);
        }
        return String.valueOf(cs);
    }
}
```

#### C++

```cpp
class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        long long t = 0;
        int n = s.size();
        for (int i = n - 1; ~i; --i) {
            t += shifts[i];
            int j = (s[i] - 'a' + t) % 26;
            s[i] = 'a' + j;
        }
        return s;
    }
};
```

#### Go

```go
func shiftingLetters(s string, shifts []int) string {
	t := 0
	n := len(s)
	cs := []byte(s)
	for i := n - 1; i >= 0; i-- {
		t += shifts[i]
		j := (int(cs[i]-'a') + t) % 26
		cs[i] = byte('a' + j)
	}
	return string(cs)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [849. 到最近的人的最大距离](https://leetcode.cn/problems/maximize-distance-to-closest-person){#849}

{{< tabs "849" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxDistToClosest(self, seats: List[int]) -> int:
        first = last = None
        d = 0
        for i, c in enumerate(seats):
            if c:
                if last is not None:
                    d = max(d, i - last)
                if first is None:
                    first = i
                last = i
        return max(first, len(seats) - last - 1, d // 2)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxDistToClosest(int[] seats) {
        int first = -1, last = -1;
        int d = 0, n = seats.length;
        for (int i = 0; i < n; ++i) {
            if (seats[i] == 1) {
                if (last != -1) {
                    d = Math.max(d, i - last);
                }
                if (first == -1) {
                    first = i;
                }
                last = i;
            }
        }
        return Math.max(d / 2, Math.max(first, n - last - 1));
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int first = -1, last = -1;
        int d = 0, n = seats.size();
        for (int i = 0; i < n; ++i) {
            if (seats[i] == 1) {
                if (last != -1) {
                    d = max(d, i - last);
                }
                if (first == -1) {
                    first = i;
                }
                last = i;
            }
        }
        return max({d / 2, max(first, n - last - 1)});
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxDistToClosest(seats []int) int {
	first, last := -1, -1
	d := 0
	for i, c := range seats {
		if c == 1 {
			if last != -1 {
				d = max(d, i-last)
			}
			if first == -1 {
				first = i
			}
			last = i
		}
	}
	return max(d/2, max(first, len(seats)-last-1))
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxDistToClosest(seats: number[]): number {
    let first = -1,
        last = -1;
    let d = 0,
        n = seats.length;
    for (let i = 0; i < n; ++i) {
        if (seats[i] === 1) {
            if (last !== -1) {
                d = Math.max(d, i - last);
            }
            if (first === -1) {
                first = i;
            }
            last = i;
        }
    }
    return Math.max(first, n - last - 1, d >> 1);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个数组 <code>seats</code> 表示一排座位，其中 <code>seats[i] = 1</code> 代表有人坐在第 <code>i</code> 个座位上，<code>seats[i] = 0</code> 代表座位 <code>i</code> 上是空的（<strong>下标从 0 开始</strong>）。</p>

<p>至少有一个空座位，且至少有一人已经坐在座位上。</p>

<p>亚历克斯希望坐在一个能够使他与离他最近的人之间的距离达到最大化的座位上。</p>

<p>返回他到离他最近的人的最大距离。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0800-0899/0849.Maximize%20Distance%20to%20Closest%20Person/images/distance.jpg" style="width: 650px; height: 257px;" />
<pre>
<strong>输入：</strong>seats = [1,0,0,0,1,0,1]
<strong>输出：</strong>2
<strong>解释：
</strong>如果亚历克斯坐在第二个空位（seats[2]）上，他到离他最近的人的距离为 2 。
如果亚历克斯坐在其它任何一个空位上，他到离他最近的人的距离为 1 。
因此，他到离他最近的人的最大距离是 2 。 
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>seats = [1,0,0,0]
<strong>输出：</strong>3
<strong>解释：</strong>
如果亚历克斯坐在最后一个座位上，他离最近的人有 3 个座位远。
这是可能的最大距离，所以答案是 3 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>seats = [0,1]
<strong>输出：</strong>1
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 <= seats.length <= 2 * 10<sup>4</sup></code></li>
	<li><code>seats[i]</code> 为 <code>0</code> 或 <code>1</code></li>
	<li>至少有一个 <strong>空座位</strong></li>
	<li>至少有一个 <strong>座位上有人</strong></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：一次遍历

我们定义两个变量 $\textit{first}$ 和 $\textit{last}$ 分别表示第一个人和最后一个人的位置，用变量 $d$ 表示两个人之间的最大距离。

然后遍历数组 $\textit{seats}$，如果当前位置有人，如果此前 $\textit{last}$ 更新过，说明此前有人，此时更新 $d = \max(d, i - \textit{last})$；如果此前 $\textit{first}$ 没有更新过，说明此前没有人，此时更新 $\textit{first} = i$。接下来更新 $\textit{last} = i$。

最后返回 $\max(\textit{first}, n - \textit{last} - 1, d / 2)$ 即可。

时间复杂度 $O(n)$，其中 $n$ 为数组 $\textit{seats}$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxDistToClosest(self, seats: List[int]) -> int:
        first = last = None
        d = 0
        for i, c in enumerate(seats):
            if c:
                if last is not None:
                    d = max(d, i - last)
                if first is None:
                    first = i
                last = i
        return max(first, len(seats) - last - 1, d // 2)
```

#### Java

```java
class Solution {
    public int maxDistToClosest(int[] seats) {
        int first = -1, last = -1;
        int d = 0, n = seats.length;
        for (int i = 0; i < n; ++i) {
            if (seats[i] == 1) {
                if (last != -1) {
                    d = Math.max(d, i - last);
                }
                if (first == -1) {
                    first = i;
                }
                last = i;
            }
        }
        return Math.max(d / 2, Math.max(first, n - last - 1));
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int first = -1, last = -1;
        int d = 0, n = seats.size();
        for (int i = 0; i < n; ++i) {
            if (seats[i] == 1) {
                if (last != -1) {
                    d = max(d, i - last);
                }
                if (first == -1) {
                    first = i;
                }
                last = i;
            }
        }
        return max({d / 2, max(first, n - last - 1)});
    }
};
```

#### Go

```go
func maxDistToClosest(seats []int) int {
	first, last := -1, -1
	d := 0
	for i, c := range seats {
		if c == 1 {
			if last != -1 {
				d = max(d, i-last)
			}
			if first == -1 {
				first = i
			}
			last = i
		}
	}
	return max(d/2, max(first, len(seats)-last-1))
}
```

#### TypeScript

```ts
function maxDistToClosest(seats: number[]): number {
    let first = -1,
        last = -1;
    let d = 0,
        n = seats.length;
    for (let i = 0; i < n; ++i) {
        if (seats[i] === 1) {
            if (last !== -1) {
                d = Math.max(d, i - last);
            }
            if (first === -1) {
                first = i;
            }
            last = i;
        }
    }
    return Math.max(first, n - last - 1, d >> 1);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
