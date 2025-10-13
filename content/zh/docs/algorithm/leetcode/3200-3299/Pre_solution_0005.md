---
title: "3240_最少翻转次数使二进制矩阵回文 II"
date: 2025-10-08T18:40:15+08:00
weight: 5
tags: [动态规划, 双指针, 哈希表, 图, 字符串, 广度优先搜索, 数学, 数据库, 数组, 有序集合, 树, 树状数组, 模拟, 深度优先搜索, 矩阵, 组合数学, 设计, 贪心]
---

{{< markmap >}}
### [3240_最少翻转次数使二进制矩阵回文 II](#3240)
#### [数组](#3240)
#### [双指针](#3240)
#### [矩阵](#3240)
### [3241_标记所有节点需要的时间](#3241)
#### [树](#3241)
#### [深度优先搜索](#3241)
#### [图](#3241)
#### [动态规划](#3241)
### [3242_设计相邻元素求和服务](#3242)
#### [设计](#3242)
#### [数组](#3242)
#### [哈希表](#3242)
#### [矩阵](#3242)
#### [模拟](#3242)
### [3243_新增道路查询后的最短距离 I](#3243)
#### [广度优先搜索](#3243)
#### [图](#3243)
#### [数组](#3243)
### [3244_新增道路查询后的最短距离 II](#3244)
#### [贪心](#3244)
#### [图](#3244)
#### [数组](#3244)
#### [有序集合](#3244)
### [3245_交替组 III](#3245)
#### [树状数组](#3245)
#### [数组](#3245)
### [3246_英超积分榜排名 🔒](#3246)
#### [数据库](#3246)
### [3247_奇数和子序列的数量 🔒](#3247)
#### [数组](#3247)
#### [数学](#3247)
#### [动态规划](#3247)
#### [组合数学](#3247)
### [3248_矩阵中的蛇](#3248)
#### [数组](#3248)
#### [字符串](#3248)
#### [模拟](#3248)
### [3249_统计好节点的数目](#3249)
#### [树](#3249)
#### [深度优先搜索](#3249)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 3240_最少翻转次数使二进制矩阵回文 II
___
#### 数组
___
#### 双指针
___
#### 矩阵
---
### 3241_标记所有节点需要的时间
___
#### 树
___
#### 深度优先搜索
___
#### 图
___
#### 动态规划
---
### 3242_设计相邻元素求和服务
___
#### 设计
___
#### 数组
___
#### 哈希表
___
#### 矩阵
___
#### 模拟
---
### 3243_新增道路查询后的最短距离 I
___
#### 广度优先搜索
___
#### 图
___
#### 数组
---
### 3244_新增道路查询后的最短距离 II
___
#### 贪心
___
#### 图
___
#### 数组
___
#### 有序集合
---
### 3245_交替组 III
___
#### 树状数组
___
#### 数组
---
### 3246_英超积分榜排名 🔒
___
#### 数据库
---
### 3247_奇数和子序列的数量 🔒
___
#### 数组
___
#### 数学
___
#### 动态规划
___
#### 组合数学
---
### 3248_矩阵中的蛇
___
#### 数组
___
#### 字符串
___
#### 模拟
---
### 3249_统计好节点的数目
___
#### 树
___
#### 深度优先搜索
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 动态规划 | 双指针 | 哈希表 |
| 图 | 字符串 | 广度优先搜索 |
| 数学 | 数据库 | 数组 |
| 有序集合 | 树 | 树状数组 |
| 模拟 | 深度优先搜索 | 矩阵 |
| 组合数学 | 设计 | 贪心 |

# [3240. 最少翻转次数使二进制矩阵回文 II](https://leetcode.cn/problems/minimum-number-of-flips-to-make-binary-grid-palindromic-ii){#3240}

{{< tabs "3240" >}}

{{% tab "python" %}}
```python
class Solution:
    def minFlips(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        ans = 0
        for i in range(m // 2):
            for j in range(n // 2):
                x, y = m - i - 1, n - j - 1
                cnt1 = grid[i][j] + grid[x][j] + grid[i][y] + grid[x][y]
                ans += min(cnt1, 4 - cnt1)
        if m % 2 and n % 2:
            ans += grid[m // 2][n // 2]
        diff = cnt1 = 0
        if m % 2:
            for j in range(n // 2):
                if grid[m // 2][j] == grid[m // 2][n - j - 1]:
                    cnt1 += grid[m // 2][j] * 2
                else:
                    diff += 1
        if n % 2:
            for i in range(m // 2):
                if grid[i][n // 2] == grid[m - i - 1][n // 2]:
                    cnt1 += grid[i][n // 2] * 2
                else:
                    diff += 1
        ans += diff if cnt1 % 4 == 0 or diff else 2
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minFlips(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int ans = 0;
        for (int i = 0; i < m / 2; ++i) {
            for (int j = 0; j < n / 2; ++j) {
                int x = m - i - 1, y = n - j - 1;
                int cnt1 = grid[i][j] + grid[x][j] + grid[i][y] + grid[x][y];
                ans += Math.min(cnt1, 4 - cnt1);
            }
        }
        if (m % 2 == 1 && n % 2 == 1) {
            ans += grid[m / 2][n / 2];
        }

        int diff = 0, cnt1 = 0;
        if (m % 2 == 1) {
            for (int j = 0; j < n / 2; ++j) {
                if (grid[m / 2][j] == grid[m / 2][n - j - 1]) {
                    cnt1 += grid[m / 2][j] * 2;
                } else {
                    diff += 1;
                }
            }
        }
        if (n % 2 == 1) {
            for (int i = 0; i < m / 2; ++i) {
                if (grid[i][n / 2] == grid[m - i - 1][n / 2]) {
                    cnt1 += grid[i][n / 2] * 2;
                } else {
                    diff += 1;
                }
            }
        }
        ans += cnt1 % 4 == 0 || diff > 0 ? diff : 2;
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m / 2; ++i) {
            for (int j = 0; j < n / 2; ++j) {
                int x = m - i - 1, y = n - j - 1;
                int cnt1 = grid[i][j] + grid[x][j] + grid[i][y] + grid[x][y];
                ans += min(cnt1, 4 - cnt1);
            }
        }
        if (m % 2 == 1 && n % 2 == 1) {
            ans += grid[m / 2][n / 2];
        }

        int diff = 0, cnt1 = 0;
        if (m % 2 == 1) {
            for (int j = 0; j < n / 2; ++j) {
                if (grid[m / 2][j] == grid[m / 2][n - j - 1]) {
                    cnt1 += grid[m / 2][j] * 2;
                } else {
                    diff += 1;
                }
            }
        }
        if (n % 2 == 1) {
            for (int i = 0; i < m / 2; ++i) {
                if (grid[i][n / 2] == grid[m - i - 1][n / 2]) {
                    cnt1 += grid[i][n / 2] * 2;
                } else {
                    diff += 1;
                }
            }
        }
        ans += cnt1 % 4 == 0 || diff > 0 ? diff : 2;
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minFlips(grid [][]int) int {
	m, n := len(grid), len(grid[0])
	ans := 0

	for i := 0; i < m/2; i++ {
		for j := 0; j < n/2; j++ {
			x, y := m-i-1, n-j-1
			cnt1 := grid[i][j] + grid[x][j] + grid[i][y] + grid[x][y]
			ans += min(cnt1, 4-cnt1)
		}
	}

	if m%2 == 1 && n%2 == 1 {
		ans += grid[m/2][n/2]
	}

	diff, cnt1 := 0, 0

	if m%2 == 1 {
		for j := 0; j < n/2; j++ {
			if grid[m/2][j] == grid[m/2][n-j-1] {
				cnt1 += grid[m/2][j] * 2
			} else {
				diff += 1
			}
		}
	}

	if n%2 == 1 {
		for i := 0; i < m/2; i++ {
			if grid[i][n/2] == grid[m-i-1][n/2] {
				cnt1 += grid[i][n/2] * 2
			} else {
				diff += 1
			}
		}
	}

	if cnt1%4 == 0 || diff > 0 {
		ans += diff
	} else {
		ans += 2
	}

	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minFlips(grid: number[][]): number {
    const m = grid.length;
    const n = grid[0].length;
    let ans = 0;

    for (let i = 0; i < Math.floor(m / 2); i++) {
        for (let j = 0; j < Math.floor(n / 2); j++) {
            const x = m - i - 1;
            const y = n - j - 1;
            const cnt1 = grid[i][j] + grid[x][j] + grid[i][y] + grid[x][y];
            ans += Math.min(cnt1, 4 - cnt1);
        }
    }

    if (m % 2 === 1 && n % 2 === 1) {
        ans += grid[Math.floor(m / 2)][Math.floor(n / 2)];
    }

    let diff = 0,
        cnt1 = 0;

    if (m % 2 === 1) {
        for (let j = 0; j < Math.floor(n / 2); j++) {
            if (grid[Math.floor(m / 2)][j] === grid[Math.floor(m / 2)][n - j - 1]) {
                cnt1 += grid[Math.floor(m / 2)][j] * 2;
            } else {
                diff += 1;
            }
        }
    }

    if (n % 2 === 1) {
        for (let i = 0; i < Math.floor(m / 2); i++) {
            if (grid[i][Math.floor(n / 2)] === grid[m - i - 1][Math.floor(n / 2)]) {
                cnt1 += grid[i][Math.floor(n / 2)] * 2;
            } else {
                diff += 1;
            }
        }
    }

    ans += cnt1 % 4 === 0 || diff > 0 ? diff : 2;
    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个&nbsp;<code>m x n</code>&nbsp;的二进制矩阵&nbsp;<code>grid</code>&nbsp;。</p>

<p>如果矩阵中一行或者一列从前往后与从后往前读是一样的，那么我们称这一行或者这一列是 <strong>回文</strong>&nbsp;的。</p>

<p>你可以将 <code>grid</code>&nbsp;中任意格子的值 <strong>翻转</strong>&nbsp;，也就是将格子里的值从 <code>0</code>&nbsp;变成 <code>1</code>&nbsp;，或者从 <code>1</code>&nbsp;变成 <code>0</code>&nbsp;。</p>

<p>请你返回 <strong>最少</strong>&nbsp;翻转次数，使得矩阵中 <strong>所有</strong>&nbsp;行和列都是 <strong>回文的</strong>&nbsp;，且矩阵中 <code>1</code>&nbsp;的数目可以被 <code>4</code>&nbsp;<strong>整除</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>grid = [[1,0,0],[0,1,0],[0,0,1]]</span></p>

<p><span class="example-io"><b>输出：</b>3</span></p>

<p><strong>解释：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3200-3299/3240.Minimum%20Number%20of%20Flips%20to%20Make%20Binary%20Grid%20Palindromic%20II/images/image.png" style="width: 400px; height: 105px;" /></p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>grid = [[0,1],[0,1],[0,0]]</span></p>

<p><span class="example-io"><b>输出：</b>2</span></p>

<p><strong>解释：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3200-3299/3240.Minimum%20Number%20of%20Flips%20to%20Make%20Binary%20Grid%20Palindromic%20II/images/screenshot-from-2024-07-09-01-37-48.png" style="width: 300px; height: 104px;" /></p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>grid = [[1],[1]]</span></p>

<p><span class="example-io"><b>输出：</b>2</span></p>

<p><strong>解释：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3200-3299/3240.Minimum%20Number%20of%20Flips%20to%20Make%20Binary%20Grid%20Palindromic%20II/images/screenshot-from-2024-08-01-23-05-26.png" style="width: 200px; height: 70px;" /></p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m * n &lt;= 2 * 10<sup>5</sup></code></li>
	<li><code>0 &lt;= grid[i][j] &lt;= 1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：分类讨论

行和列都是回文的，那么对于任意 $i \in [0, m / 2)$ 和 $j \in [0, n / 2)$，都需要满足 $\text{grid}[i][j] = \text{grid}[m - i - 1][j] = \text{grid}[i][n - j - 1] = \text{grid}[m - i - 1][n - j - 1]$，要么都变成 $0$，要么都变成 $1$，变成 $0$ 的次数为 $c_0 = \text{grid}[i][j] + \text{grid}[m - i - 1][j] + \text{grid}[i][n - j - 1] + \text{grid}[m - i - 1][n - j - 1]$，变成 $1$ 的次数为 $c_1 = 4 - c_0$，取两者的较小值，累加到答案中。

接下来，我们再讨论 $m$ 和 $n$ 的奇偶性：

-   如果 $m$ 和 $n$ 都是偶数，那么直接返回答案；
-   如果 $m$ 和 $n$ 都是奇数，那么最中间的格子只能是 $0$，因为题目要求 $1$ 的数目可以被 $4$ 整除；
-   如果 $m$ 是奇数，而 $n$ 是偶数，那么我们需要考虑最中间的一行；
-   如果 $m$ 是偶数，而 $n$ 是奇数，那么我们需要考虑最中间的一列。

对于后两种情况，我们需要统计最中间的一行或一列中对应位置不相同的格子对数 $\text{diff}$，以及对应位置相同且为 $1$ 的格子个数 $\text{cnt1}$，然后再分情况讨论：

-   如果 $\text{cnt1} \bmod 4 = 0$，那么我们只需要将 $\text{diff}$ 个格子变成 $0$ 即可，操作次数为 $\text{diff}$；
-   否则，说明 $\text{cnt1} = 2$，此时如果 $\text{diff} \gt 0$，我们可以将其中一个格子变成 $1$，使得 $\text{cnt1} = 4$，那么剩下的 $\text{diff} - 1$ 个格子变成 $0$ 即可，操作次数一共为 $\text{diff}$。
-   否则，如果 $\text{diff} = 0$，我们就把 $\text{2}$ 个格子变成 $0$，使得 $\text{cnt1} \bmod 4 = 0$，操作次数为 $\text{2}$。

我们将操作次数累加到答案中，最后返回答案即可。

时间复杂度 $O(m \times n)$，其中 $m$ 和 $n$ 分别是矩阵的行数和列数。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minFlips(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        ans = 0
        for i in range(m // 2):
            for j in range(n // 2):
                x, y = m - i - 1, n - j - 1
                cnt1 = grid[i][j] + grid[x][j] + grid[i][y] + grid[x][y]
                ans += min(cnt1, 4 - cnt1)
        if m % 2 and n % 2:
            ans += grid[m // 2][n // 2]
        diff = cnt1 = 0
        if m % 2:
            for j in range(n // 2):
                if grid[m // 2][j] == grid[m // 2][n - j - 1]:
                    cnt1 += grid[m // 2][j] * 2
                else:
                    diff += 1
        if n % 2:
            for i in range(m // 2):
                if grid[i][n // 2] == grid[m - i - 1][n // 2]:
                    cnt1 += grid[i][n // 2] * 2
                else:
                    diff += 1
        ans += diff if cnt1 % 4 == 0 or diff else 2
        return ans
```

#### Java

```java
class Solution {
    public int minFlips(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int ans = 0;
        for (int i = 0; i < m / 2; ++i) {
            for (int j = 0; j < n / 2; ++j) {
                int x = m - i - 1, y = n - j - 1;
                int cnt1 = grid[i][j] + grid[x][j] + grid[i][y] + grid[x][y];
                ans += Math.min(cnt1, 4 - cnt1);
            }
        }
        if (m % 2 == 1 && n % 2 == 1) {
            ans += grid[m / 2][n / 2];
        }

        int diff = 0, cnt1 = 0;
        if (m % 2 == 1) {
            for (int j = 0; j < n / 2; ++j) {
                if (grid[m / 2][j] == grid[m / 2][n - j - 1]) {
                    cnt1 += grid[m / 2][j] * 2;
                } else {
                    diff += 1;
                }
            }
        }
        if (n % 2 == 1) {
            for (int i = 0; i < m / 2; ++i) {
                if (grid[i][n / 2] == grid[m - i - 1][n / 2]) {
                    cnt1 += grid[i][n / 2] * 2;
                } else {
                    diff += 1;
                }
            }
        }
        ans += cnt1 % 4 == 0 || diff > 0 ? diff : 2;
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m / 2; ++i) {
            for (int j = 0; j < n / 2; ++j) {
                int x = m - i - 1, y = n - j - 1;
                int cnt1 = grid[i][j] + grid[x][j] + grid[i][y] + grid[x][y];
                ans += min(cnt1, 4 - cnt1);
            }
        }
        if (m % 2 == 1 && n % 2 == 1) {
            ans += grid[m / 2][n / 2];
        }

        int diff = 0, cnt1 = 0;
        if (m % 2 == 1) {
            for (int j = 0; j < n / 2; ++j) {
                if (grid[m / 2][j] == grid[m / 2][n - j - 1]) {
                    cnt1 += grid[m / 2][j] * 2;
                } else {
                    diff += 1;
                }
            }
        }
        if (n % 2 == 1) {
            for (int i = 0; i < m / 2; ++i) {
                if (grid[i][n / 2] == grid[m - i - 1][n / 2]) {
                    cnt1 += grid[i][n / 2] * 2;
                } else {
                    diff += 1;
                }
            }
        }
        ans += cnt1 % 4 == 0 || diff > 0 ? diff : 2;
        return ans;
    }
};
```

#### Go

```go
func minFlips(grid [][]int) int {
	m, n := len(grid), len(grid[0])
	ans := 0

	for i := 0; i < m/2; i++ {
		for j := 0; j < n/2; j++ {
			x, y := m-i-1, n-j-1
			cnt1 := grid[i][j] + grid[x][j] + grid[i][y] + grid[x][y]
			ans += min(cnt1, 4-cnt1)
		}
	}

	if m%2 == 1 && n%2 == 1 {
		ans += grid[m/2][n/2]
	}

	diff, cnt1 := 0, 0

	if m%2 == 1 {
		for j := 0; j < n/2; j++ {
			if grid[m/2][j] == grid[m/2][n-j-1] {
				cnt1 += grid[m/2][j] * 2
			} else {
				diff += 1
			}
		}
	}

	if n%2 == 1 {
		for i := 0; i < m/2; i++ {
			if grid[i][n/2] == grid[m-i-1][n/2] {
				cnt1 += grid[i][n/2] * 2
			} else {
				diff += 1
			}
		}
	}

	if cnt1%4 == 0 || diff > 0 {
		ans += diff
	} else {
		ans += 2
	}

	return ans
}
```

#### TypeScript

```ts
function minFlips(grid: number[][]): number {
    const m = grid.length;
    const n = grid[0].length;
    let ans = 0;

    for (let i = 0; i < Math.floor(m / 2); i++) {
        for (let j = 0; j < Math.floor(n / 2); j++) {
            const x = m - i - 1;
            const y = n - j - 1;
            const cnt1 = grid[i][j] + grid[x][j] + grid[i][y] + grid[x][y];
            ans += Math.min(cnt1, 4 - cnt1);
        }
    }

    if (m % 2 === 1 && n % 2 === 1) {
        ans += grid[Math.floor(m / 2)][Math.floor(n / 2)];
    }

    let diff = 0,
        cnt1 = 0;

    if (m % 2 === 1) {
        for (let j = 0; j < Math.floor(n / 2); j++) {
            if (grid[Math.floor(m / 2)][j] === grid[Math.floor(m / 2)][n - j - 1]) {
                cnt1 += grid[Math.floor(m / 2)][j] * 2;
            } else {
                diff += 1;
            }
        }
    }

    if (n % 2 === 1) {
        for (let i = 0; i < Math.floor(m / 2); i++) {
            if (grid[i][Math.floor(n / 2)] === grid[m - i - 1][Math.floor(n / 2)]) {
                cnt1 += grid[i][Math.floor(n / 2)] * 2;
            } else {
                diff += 1;
            }
        }
    }

    ans += cnt1 % 4 === 0 || diff > 0 ? diff : 2;
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3241. 标记所有节点需要的时间](https://leetcode.cn/problems/time-taken-to-mark-all-nodes){#3241}

{{< tabs "3241" >}}

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

<p>给你一棵 <strong>无向</strong>&nbsp;树，树中节点从 <code>0</code>&nbsp;到 <code>n - 1</code>&nbsp;编号。同时给你一个长度为 <code>n - 1</code>&nbsp;的二维整数数组&nbsp;<code>edges</code>&nbsp;，其中&nbsp;<code>edges[i] = [u<sub>i</sub>, v<sub>i</sub>]</code>&nbsp;表示节点&nbsp;<code>u<sub>i</sub></code> 和&nbsp;<code>v<sub>i</sub></code>&nbsp;在树中有一条边。</p>

<p>一开始，<strong>所有</strong>&nbsp;节点都 <strong>未标记</strong>&nbsp;。对于节点 <code>i</code>&nbsp;：</p>

<ul>
	<li>当&nbsp;<code>i</code>&nbsp;是奇数时，如果时刻 <code>x - 1</code>&nbsp;该节点有 <strong>至少</strong>&nbsp;一个相邻节点已经被标记了，那么节点 <code>i</code>&nbsp;会在时刻 <code>x</code>&nbsp;被标记。</li>
	<li>当&nbsp;<code>i</code>&nbsp;是偶数时，如果时刻 <code>x - 2</code>&nbsp;该节点有 <strong>至少</strong>&nbsp;一个相邻节点已经被标记了，那么节点 <code>i</code>&nbsp;会在时刻 <code>x</code>&nbsp;被标记。</li>
</ul>

<p>请你返回一个数组&nbsp;<code>times</code>&nbsp;，表示如果你在时刻 <code>t = 0</code>&nbsp;标记节点 <code>i</code>&nbsp;，那么时刻 <code>times[i]</code>&nbsp;时，树中所有节点都会被标记。</p>

<p>请注意，每个 <code>times[i]</code> 的答案都是独立的，即当你标记节点 <code>i</code> 时，所有其他节点都未标记。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>edges = [[0,1],[0,2]]</span></p>

<p><b>输出：</b>[2,4,3]</p>

<p><strong>解释：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3200-3299/3241.Time%20Taken%20to%20Mark%20All%20Nodes/images/screenshot-2024-06-02-122236.png" style="width: 500px; height: 241px;" /></p>

<ul>
	<li>对于&nbsp;<code>i = 0</code>&nbsp;：

    <ul>
    	<li>节点 1 在时刻&nbsp;<code>t = 1</code>&nbsp;被标记，节点 2 在时刻&nbsp;<code>t = 2</code>&nbsp;被标记。</li>
    </ul>
    </li>
    <li>对于&nbsp;<code>i = 1</code>&nbsp;：
    <ul>
    	<li>节点 0 在时刻&nbsp;<code>t = 2</code>&nbsp;被标记，节点 2 在时刻&nbsp;<code>t = 4</code>&nbsp;被标记。</li>
    </ul>
    </li>
    <li>对于&nbsp;<code>i = 2</code>&nbsp;：
    <ul>
    	<li>节点 0 在时刻&nbsp;<code>t = 2</code>&nbsp;被标记，节点 1 在时刻&nbsp;<code>t = 3</code>&nbsp;被标记。</li>
    </ul>
    </li>

</ul>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>edges = [[0,1]]</span></p>

<p><b>输出：</b>[1,2]</p>

<p><strong>解释：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3200-3299/3241.Time%20Taken%20to%20Mark%20All%20Nodes/images/screenshot-2024-06-02-122249.png" style="width: 500px; height: 257px;" /></p>

<ul>
	<li>对于&nbsp;<code>i = 0</code>&nbsp;：

    <ul>
    	<li>节点 1 在时刻&nbsp;<code>t = 1</code>&nbsp;被标记。</li>
    </ul>
    </li>
    <li>对于&nbsp;<code>i = 1</code>&nbsp;：
    <ul>
    	<li>节点 0 在时刻&nbsp;<code>t = 2</code>&nbsp;被标记。</li>
    </ul>
    </li>

</ul>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>edges = </span>[[2,4],[0,1],[2,3],[0,2]]</p>

<p><b>输出：</b>[4,6,3,5,5]</p>

<p><b>解释：</b></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3200-3299/3241.Time%20Taken%20to%20Mark%20All%20Nodes/images/screenshot-2024-06-03-210550.png" style="height: 266px; width: 500px;" /></p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>edges.length == n - 1</code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>0 &lt;= edges[i][0], edges[i][1] &lt;= n - 1</code></li>
	<li>输入保证&nbsp;<code>edges</code>&nbsp;表示一棵合法的树。</li>
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

# [3242. 设计相邻元素求和服务](https://leetcode.cn/problems/design-neighbor-sum-service){#3242}

{{< tabs "3242" >}}

{{% tab "python" %}}
```python
class NeighborSum:

    def __init__(self, grid: List[List[int]]):
        self.grid = grid
        self.d = {}
        self.dirs = ((-1, 0, 1, 0, -1), (-1, 1, 1, -1, -1))
        for i, row in enumerate(grid):
            for j, x in enumerate(row):
                self.d[x] = (i, j)

    def adjacentSum(self, value: int) -> int:
        return self.cal(value, 0)

    def cal(self, value: int, k: int):
        i, j = self.d[value]
        s = 0
        for a, b in pairwise(self.dirs[k]):
            x, y = i + a, j + b
            if 0 <= x < len(self.grid) and 0 <= y < len(self.grid[0]):
                s += self.grid[x][y]
        return s

    def diagonalSum(self, value: int) -> int:
        return self.cal(value, 1)


# Your NeighborSum object will be instantiated and called as such:
# obj = NeighborSum(grid)
# param_1 = obj.adjacentSum(value)
# param_2 = obj.diagonalSum(value)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class NeighborSum {
    private int[][] grid;
    private final Map<Integer, int[]> d = new HashMap<>();
    private final int[][] dirs = {{-1, 0, 1, 0, -1}, {-1, 1, 1, -1, -1}};

    public NeighborSum(int[][] grid) {
        this.grid = grid;
        int m = grid.length, n = grid[0].length;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                d.put(grid[i][j], new int[] {i, j});
            }
        }
    }

    public int adjacentSum(int value) {
        return cal(value, 0);
    }

    public int diagonalSum(int value) {
        return cal(value, 1);
    }

    private int cal(int value, int k) {
        int[] p = d.get(value);
        int s = 0;
        for (int q = 0; q < 4; ++q) {
            int x = p[0] + dirs[k][q], y = p[1] + dirs[k][q + 1];
            if (x >= 0 && x < grid.length && y >= 0 && y < grid[0].length) {
                s += grid[x][y];
            }
        }
        return s;
    }
}

/**
 * Your NeighborSum object will be instantiated and called as such:
 * NeighborSum obj = new NeighborSum(grid);
 * int param_1 = obj.adjacentSum(value);
 * int param_2 = obj.diagonalSum(value);
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class NeighborSum {
public:
    NeighborSum(vector<vector<int>>& grid) {
        this->grid = grid;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                d[grid[i][j]] = {i, j};
            }
        }
    }

    int adjacentSum(int value) {
        return cal(value, 0);
    }

    int diagonalSum(int value) {
        return cal(value, 1);
    }

private:
    vector<vector<int>> grid;
    unordered_map<int, pair<int, int>> d;
    int dirs[2][5] = {{-1, 0, 1, 0, -1}, {-1, 1, 1, -1, -1}};

    int cal(int value, int k) {
        auto [i, j] = d[value];
        int s = 0;
        for (int q = 0; q < 4; ++q) {
            int x = i + dirs[k][q], y = j + dirs[k][q + 1];
            if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size()) {
                s += grid[x][y];
            }
        }
        return s;
    }
};

/**
 * Your NeighborSum object will be instantiated and called as such:
 * NeighborSum* obj = new NeighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type NeighborSum struct {
	grid [][]int
	d    map[int][2]int
	dirs [2][5]int
}

func Constructor(grid [][]int) NeighborSum {
	d := map[int][2]int{}
	for i, row := range grid {
		for j, x := range row {
			d[x] = [2]int{i, j}
		}
	}
	dirs := [2][5]int{{-1, 0, 1, 0, -1}, {-1, 1, 1, -1, -1}}
	return NeighborSum{grid, d, dirs}
}

func (this *NeighborSum) AdjacentSum(value int) int {
	return this.cal(value, 0)
}

func (this *NeighborSum) DiagonalSum(value int) int {
	return this.cal(value, 1)
}

func (this *NeighborSum) cal(value, k int) int {
	p := this.d[value]
	s := 0
	for q := 0; q < 4; q++ {
		x, y := p[0]+this.dirs[k][q], p[1]+this.dirs[k][q+1]
		if x >= 0 && x < len(this.grid) && y >= 0 && y < len(this.grid[0]) {
			s += this.grid[x][y]
		}
	}
	return s
}

/**
 * Your NeighborSum object will be instantiated and called as such:
 * obj := Constructor(grid);
 * param_1 := obj.AdjacentSum(value);
 * param_2 := obj.DiagonalSum(value);
 */
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class NeighborSum {
    private grid: number[][];
    private d: Map<number, [number, number]> = new Map();
    private dirs: number[][] = [
        [-1, 0, 1, 0, -1],
        [-1, 1, 1, -1, -1],
    ];
    constructor(grid: number[][]) {
        for (let i = 0; i < grid.length; ++i) {
            for (let j = 0; j < grid[0].length; ++j) {
                this.d.set(grid[i][j], [i, j]);
            }
        }
        this.grid = grid;
    }

    adjacentSum(value: number): number {
        return this.cal(value, 0);
    }

    diagonalSum(value: number): number {
        return this.cal(value, 1);
    }

    cal(value: number, k: number): number {
        const [i, j] = this.d.get(value)!;
        let s = 0;
        for (let q = 0; q < 4; ++q) {
            const [x, y] = [i + this.dirs[k][q], j + this.dirs[k][q + 1]];
            if (x >= 0 && x < this.grid.length && y >= 0 && y < this.grid[0].length) {
                s += this.grid[x][y];
            }
        }
        return s;
    }
}

/**
 * Your NeighborSum object will be instantiated and called as such:
 * var obj = new NeighborSum(grid)
 * var param_1 = obj.adjacentSum(value)
 * var param_2 = obj.diagonalSum(value)
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个 <code>n x n</code> 的二维数组 <code>grid</code>，它包含范围 <code>[0, n<sup>2</sup> - 1]</code> 内的<strong>不重复</strong>元素。</p>

<p>实现 <code>neighborSum</code> 类：</p>

<ul>
	<li><code>neighborSum(int [][]grid)</code> 初始化对象。</li>
	<li><code>int adjacentSum(int value)</code> 返回在 <code>grid</code> 中与 <code>value</code> 相邻的元素之<strong>和</strong>，相邻指的是与 <code>value</code> 在上、左、右或下的元素。</li>
	<li><code>int diagonalSum(int value)</code> 返回在 <code>grid</code> 中与 <code>value</code> 对角线相邻的元素之<strong>和</strong>，对角线相邻指的是与 <code>value</code> 在左上、右上、左下或右下的元素。</li>
</ul>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3200-3299/3242.Design%20Neighbor%20Sum%20Service/images/design.png" style="width: 400px; height: 248px;" /></p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong></p>

<p>["neighborSum", "adjacentSum", "adjacentSum", "diagonalSum", "diagonalSum"]</p>

<p>[[[[0, 1, 2], [3, 4, 5], [6, 7, 8]]], [1], [4], [4], [8]]</p>

<p><strong>输出：</strong> [null, 6, 16, 16, 4]</p>

<p><strong>解释：</strong></p>

<p><strong class="example"><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3200-3299/3242.Design%20Neighbor%20Sum%20Service/images/designexample0.png" style="width: 250px; height: 249px;" /></strong></p>

<ul>
	<li>1 的相邻元素是 0、2 和 4。</li>
	<li>4 的相邻元素是 1、3、5 和 7。</li>
	<li>4 的对角线相邻元素是 0、2、6 和 8。</li>
	<li>8 的对角线相邻元素是 4。</li>
</ul>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong></p>

<p>["neighborSum", "adjacentSum", "diagonalSum"]</p>

<p>[[[[1, 2, 0, 3], [4, 7, 15, 6], [8, 9, 10, 11], [12, 13, 14, 5]]], [15], [9]]</p>

<p><strong>输出：</strong> [null, 23, 45]</p>

<p><strong>解释：</strong></p>

<p><strong class="example"><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3200-3299/3242.Design%20Neighbor%20Sum%20Service/images/designexample2.png" style="width: 300px; height: 300px;" /></strong></p>

<ul>
	<li>15 的相邻元素是 0、10、7 和 6。</li>
	<li>9 的对角线相邻元素是 4、12、14 和 15。</li>
</ul>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= n == grid.length == grid[0].length &lt;= 10</code></li>
	<li><code>0 &lt;= grid[i][j] &lt;= n<sup>2</sup> - 1</code></li>
	<li>所有 <code>grid[i][j]</code> 值均不重复。</li>
	<li><code>adjacentSum</code> 和 <code>diagonalSum</code> 中的 <code>value</code> 均在范围 <code>[0, n<sup>2</sup> - 1]</code> 内。</li>
	<li>最多会调用 <code>adjacentSum</code> 和 <code>diagonalSum</code> 总共 <code>2 * n<sup>2</sup></code> 次。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

我们可以用一个哈希表 $\textit{d}$ 来存储每个元素的坐标，然后根据题意，分别计算相邻元素和对角线相邻元素的和。

时间复杂度方面，初始化哈希表的时间复杂度为 $O(m \times n)$，计算相邻元素和对角线相邻元素的和的时间复杂度为 $O(1)$。空间复杂度为 $O(m \times n)$。

<!-- tabs:start -->

#### Python3

```python
class NeighborSum:

    def __init__(self, grid: List[List[int]]):
        self.grid = grid
        self.d = {}
        self.dirs = ((-1, 0, 1, 0, -1), (-1, 1, 1, -1, -1))
        for i, row in enumerate(grid):
            for j, x in enumerate(row):
                self.d[x] = (i, j)

    def adjacentSum(self, value: int) -> int:
        return self.cal(value, 0)

    def cal(self, value: int, k: int):
        i, j = self.d[value]
        s = 0
        for a, b in pairwise(self.dirs[k]):
            x, y = i + a, j + b
            if 0 <= x < len(self.grid) and 0 <= y < len(self.grid[0]):
                s += self.grid[x][y]
        return s

    def diagonalSum(self, value: int) -> int:
        return self.cal(value, 1)


# Your NeighborSum object will be instantiated and called as such:
# obj = NeighborSum(grid)
# param_1 = obj.adjacentSum(value)
# param_2 = obj.diagonalSum(value)
```

#### Java

```java
class NeighborSum {
    private int[][] grid;
    private final Map<Integer, int[]> d = new HashMap<>();
    private final int[][] dirs = {{-1, 0, 1, 0, -1}, {-1, 1, 1, -1, -1}};

    public NeighborSum(int[][] grid) {
        this.grid = grid;
        int m = grid.length, n = grid[0].length;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                d.put(grid[i][j], new int[] {i, j});
            }
        }
    }

    public int adjacentSum(int value) {
        return cal(value, 0);
    }

    public int diagonalSum(int value) {
        return cal(value, 1);
    }

    private int cal(int value, int k) {
        int[] p = d.get(value);
        int s = 0;
        for (int q = 0; q < 4; ++q) {
            int x = p[0] + dirs[k][q], y = p[1] + dirs[k][q + 1];
            if (x >= 0 && x < grid.length && y >= 0 && y < grid[0].length) {
                s += grid[x][y];
            }
        }
        return s;
    }
}

/**
 * Your NeighborSum object will be instantiated and called as such:
 * NeighborSum obj = new NeighborSum(grid);
 * int param_1 = obj.adjacentSum(value);
 * int param_2 = obj.diagonalSum(value);
 */
```

#### C++

```cpp
class NeighborSum {
public:
    NeighborSum(vector<vector<int>>& grid) {
        this->grid = grid;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                d[grid[i][j]] = {i, j};
            }
        }
    }

    int adjacentSum(int value) {
        return cal(value, 0);
    }

    int diagonalSum(int value) {
        return cal(value, 1);
    }

private:
    vector<vector<int>> grid;
    unordered_map<int, pair<int, int>> d;
    int dirs[2][5] = {{-1, 0, 1, 0, -1}, {-1, 1, 1, -1, -1}};

    int cal(int value, int k) {
        auto [i, j] = d[value];
        int s = 0;
        for (int q = 0; q < 4; ++q) {
            int x = i + dirs[k][q], y = j + dirs[k][q + 1];
            if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size()) {
                s += grid[x][y];
            }
        }
        return s;
    }
};

/**
 * Your NeighborSum object will be instantiated and called as such:
 * NeighborSum* obj = new NeighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */
```

#### Go

```go
type NeighborSum struct {
	grid [][]int
	d    map[int][2]int
	dirs [2][5]int
}

func Constructor(grid [][]int) NeighborSum {
	d := map[int][2]int{}
	for i, row := range grid {
		for j, x := range row {
			d[x] = [2]int{i, j}
		}
	}
	dirs := [2][5]int{{-1, 0, 1, 0, -1}, {-1, 1, 1, -1, -1}}
	return NeighborSum{grid, d, dirs}
}

func (this *NeighborSum) AdjacentSum(value int) int {
	return this.cal(value, 0)
}

func (this *NeighborSum) DiagonalSum(value int) int {
	return this.cal(value, 1)
}

func (this *NeighborSum) cal(value, k int) int {
	p := this.d[value]
	s := 0
	for q := 0; q < 4; q++ {
		x, y := p[0]+this.dirs[k][q], p[1]+this.dirs[k][q+1]
		if x >= 0 && x < len(this.grid) && y >= 0 && y < len(this.grid[0]) {
			s += this.grid[x][y]
		}
	}
	return s
}

/**
 * Your NeighborSum object will be instantiated and called as such:
 * obj := Constructor(grid);
 * param_1 := obj.AdjacentSum(value);
 * param_2 := obj.DiagonalSum(value);
 */
```

#### TypeScript

```ts
class NeighborSum {
    private grid: number[][];
    private d: Map<number, [number, number]> = new Map();
    private dirs: number[][] = [
        [-1, 0, 1, 0, -1],
        [-1, 1, 1, -1, -1],
    ];
    constructor(grid: number[][]) {
        for (let i = 0; i < grid.length; ++i) {
            for (let j = 0; j < grid[0].length; ++j) {
                this.d.set(grid[i][j], [i, j]);
            }
        }
        this.grid = grid;
    }

    adjacentSum(value: number): number {
        return this.cal(value, 0);
    }

    diagonalSum(value: number): number {
        return this.cal(value, 1);
    }

    cal(value: number, k: number): number {
        const [i, j] = this.d.get(value)!;
        let s = 0;
        for (let q = 0; q < 4; ++q) {
            const [x, y] = [i + this.dirs[k][q], j + this.dirs[k][q + 1]];
            if (x >= 0 && x < this.grid.length && y >= 0 && y < this.grid[0].length) {
                s += this.grid[x][y];
            }
        }
        return s;
    }
}

/**
 * Your NeighborSum object will be instantiated and called as such:
 * var obj = new NeighborSum(grid)
 * var param_1 = obj.adjacentSum(value)
 * var param_2 = obj.diagonalSum(value)
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3243. 新增道路查询后的最短距离 I](https://leetcode.cn/problems/shortest-distance-after-road-addition-queries-i){#3243}

{{< tabs "3243" >}}

{{% tab "python" %}}
```python
class Solution:
    def shortestDistanceAfterQueries(
        self, n: int, queries: List[List[int]]
    ) -> List[int]:
        def bfs(i: int) -> int:
            q = deque([i])
            vis = [False] * n
            vis[i] = True
            d = 0
            while 1:
                for _ in range(len(q)):
                    u = q.popleft()
                    if u == n - 1:
                        return d
                    for v in g[u]:
                        if not vis[v]:
                            vis[v] = True
                            q.append(v)
                d += 1

        g = [[i + 1] for i in range(n - 1)]
        ans = []
        for u, v in queries:
            g[u].append(v)
            ans.append(bfs(0))
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private List<Integer>[] g;
    private int n;

    public int[] shortestDistanceAfterQueries(int n, int[][] queries) {
        this.n = n;
        g = new List[n];
        Arrays.setAll(g, i -> new ArrayList<>());
        for (int i = 0; i < n - 1; ++i) {
            g[i].add(i + 1);
        }
        int m = queries.length;
        int[] ans = new int[m];
        for (int i = 0; i < m; ++i) {
            int u = queries[i][0], v = queries[i][1];
            g[u].add(v);
            ans[i] = bfs(0);
        }
        return ans;
    }

    private int bfs(int i) {
        Deque<Integer> q = new ArrayDeque<>();
        q.offer(i);
        boolean[] vis = new boolean[n];
        vis[i] = true;
        for (int d = 0;; ++d) {
            for (int k = q.size(); k > 0; --k) {
                int u = q.poll();
                if (u == n - 1) {
                    return d;
                }
                for (int v : g[u]) {
                    if (!vis[v]) {
                        vis[v] = true;
                        q.offer(v);
                    }
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
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> g[n];
        for (int i = 0; i < n - 1; ++i) {
            g[i].push_back(i + 1);
        }
        auto bfs = [&](int i) -> int {
            queue<int> q{{i}};
            vector<bool> vis(n);
            vis[i] = true;
            for (int d = 0;; ++d) {
                for (int k = q.size(); k; --k) {
                    int u = q.front();
                    q.pop();
                    if (u == n - 1) {
                        return d;
                    }
                    for (int v : g[u]) {
                        if (!vis[v]) {
                            vis[v] = true;
                            q.push(v);
                        }
                    }
                }
            }
        };
        vector<int> ans;
        for (const auto& q : queries) {
            g[q[0]].push_back(q[1]);
            ans.push_back(bfs(0));
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func shortestDistanceAfterQueries(n int, queries [][]int) []int {
	g := make([][]int, n)
	for i := range g {
		g[i] = append(g[i], i+1)
	}
	bfs := func(i int) int {
		q := []int{i}
		vis := make([]bool, n)
		vis[i] = true
		for d := 0; ; d++ {
			for k := len(q); k > 0; k-- {
				u := q[0]
				if u == n-1 {
					return d
				}
				q = q[1:]
				for _, v := range g[u] {
					if !vis[v] {
						vis[v] = true
						q = append(q, v)
					}
				}
			}
		}
	}
	ans := make([]int, len(queries))
	for i, q := range queries {
		g[q[0]] = append(g[q[0]], q[1])
		ans[i] = bfs(0)
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function shortestDistanceAfterQueries(n: number, queries: number[][]): number[] {
    const g: number[][] = Array.from({ length: n }, () => []);
    for (let i = 0; i < n - 1; ++i) {
        g[i].push(i + 1);
    }
    const bfs = (i: number): number => {
        const q: number[] = [i];
        const vis: boolean[] = Array(n).fill(false);
        vis[i] = true;
        for (let d = 0; ; ++d) {
            const nq: number[] = [];
            for (const u of q) {
                if (u === n - 1) {
                    return d;
                }
                for (const v of g[u]) {
                    if (!vis[v]) {
                        vis[v] = true;
                        nq.push(v);
                    }
                }
            }
            q.splice(0, q.length, ...nq);
        }
    };
    const ans: number[] = [];
    for (const [u, v] of queries) {
        g[u].push(v);
        ans.push(bfs(0));
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

<p>给你一个整数 <code>n</code> 和一个二维整数数组 <code>queries</code>。</p>

<p>有 <code>n</code> 个城市，编号从 <code>0</code> 到 <code>n - 1</code>。初始时，每个城市 <code>i</code> 都有一条<strong>单向</strong>道路通往城市 <code>i + 1</code>（ <code>0 &lt;= i &lt; n - 1</code>）。</p>

<p><code>queries[i] = [u<sub>i</sub>, v<sub>i</sub>]</code> 表示新建一条从城市 <code>u<sub>i</sub></code> 到城市 <code>v<sub>i</sub></code> 的<strong>单向</strong>道路。每次查询后，你需要找到从城市 <code>0</code> 到城市 <code>n - 1</code> 的<strong>最短路径</strong>的<strong>长度</strong>。</p>

<p>返回一个数组 <code>answer</code>，对于范围 <code>[0, queries.length - 1]</code> 中的每个 <code>i</code>，<code>answer[i]</code> 是处理完<strong>前</strong> <code>i + 1</code> 个查询后，从城市 <code>0</code> 到城市 <code>n - 1</code> 的最短路径的<em>长度</em>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">n = 5, queries = [[2, 4], [0, 2], [0, 4]]</span></p>

<p><strong>输出：</strong> <span class="example-io">[3, 2, 1]</span></p>

<p><strong>解释：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3200-3299/3243.Shortest%20Distance%20After%20Road%20Addition%20Queries%20I/images/image8.jpg" style="width: 350px; height: 60px;" /></p>

<p>新增一条从 2 到 4 的道路后，从 0 到 4 的最短路径长度为 3。</p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3200-3299/3243.Shortest%20Distance%20After%20Road%20Addition%20Queries%20I/images/image9.jpg" style="width: 350px; height: 60px;" /></p>

<p>新增一条从 0 到 2 的道路后，从 0 到 4 的最短路径长度为 2。</p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3200-3299/3243.Shortest%20Distance%20After%20Road%20Addition%20Queries%20I/images/image10.jpg" style="width: 350px; height: 96px;" /></p>

<p>新增一条从 0 到 4 的道路后，从 0 到 4 的最短路径长度为 1。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">n = 4, queries = [[0, 3], [0, 2]]</span></p>

<p><strong>输出：</strong> <span class="example-io">[1, 1]</span></p>

<p><strong>解释：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3200-3299/3243.Shortest%20Distance%20After%20Road%20Addition%20Queries%20I/images/image11.jpg" style="width: 300px; height: 70px;" /></p>

<p>新增一条从 0 到 3 的道路后，从 0 到 3 的最短路径长度为 1。</p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3200-3299/3243.Shortest%20Distance%20After%20Road%20Addition%20Queries%20I/images/image12.jpg" style="width: 300px; height: 70px;" /></p>

<p>新增一条从 0 到 2 的道路后，从 0 到 3 的最短路径长度仍为 1。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= n &lt;= 500</code></li>
	<li><code>1 &lt;= queries.length &lt;= 500</code></li>
	<li><code>queries[i].length == 2</code></li>
	<li><code>0 &lt;= queries[i][0] &lt; queries[i][1] &lt; n</code></li>
	<li><code>1 &lt; queries[i][1] - queries[i][0]</code></li>
	<li>查询中没有重复的道路。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：BFS

我们先建立一个有向图 $\textit{g}$，其中 $\textit{g}[i]$ 表示从城市 $i$ 出发可以到达的城市列表，初始时，每个城市 $i$ 都有一条单向道路通往城市 $i + 1$。

然后，我们对每个查询 $[u, v]$，将 $v$ 添加到 $u$ 的可达城市列表中，然后使用 BFS 求出从城市 $0$ 到城市 $n - 1$ 的最短路径长度，将结果添加到答案数组中。

最后返回答案数组即可。

时间复杂度 $O(q \times (n + q))$，空间复杂度 $O(n + q)$。其中 $n$ 和 $q$ 分别为城市数量和查询数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def shortestDistanceAfterQueries(
        self, n: int, queries: List[List[int]]
    ) -> List[int]:
        def bfs(i: int) -> int:
            q = deque([i])
            vis = [False] * n
            vis[i] = True
            d = 0
            while 1:
                for _ in range(len(q)):
                    u = q.popleft()
                    if u == n - 1:
                        return d
                    for v in g[u]:
                        if not vis[v]:
                            vis[v] = True
                            q.append(v)
                d += 1

        g = [[i + 1] for i in range(n - 1)]
        ans = []
        for u, v in queries:
            g[u].append(v)
            ans.append(bfs(0))
        return ans
```

#### Java

```java
class Solution {
    private List<Integer>[] g;
    private int n;

    public int[] shortestDistanceAfterQueries(int n, int[][] queries) {
        this.n = n;
        g = new List[n];
        Arrays.setAll(g, i -> new ArrayList<>());
        for (int i = 0; i < n - 1; ++i) {
            g[i].add(i + 1);
        }
        int m = queries.length;
        int[] ans = new int[m];
        for (int i = 0; i < m; ++i) {
            int u = queries[i][0], v = queries[i][1];
            g[u].add(v);
            ans[i] = bfs(0);
        }
        return ans;
    }

    private int bfs(int i) {
        Deque<Integer> q = new ArrayDeque<>();
        q.offer(i);
        boolean[] vis = new boolean[n];
        vis[i] = true;
        for (int d = 0;; ++d) {
            for (int k = q.size(); k > 0; --k) {
                int u = q.poll();
                if (u == n - 1) {
                    return d;
                }
                for (int v : g[u]) {
                    if (!vis[v]) {
                        vis[v] = true;
                        q.offer(v);
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
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> g[n];
        for (int i = 0; i < n - 1; ++i) {
            g[i].push_back(i + 1);
        }
        auto bfs = [&](int i) -> int {
            queue<int> q{{i}};
            vector<bool> vis(n);
            vis[i] = true;
            for (int d = 0;; ++d) {
                for (int k = q.size(); k; --k) {
                    int u = q.front();
                    q.pop();
                    if (u == n - 1) {
                        return d;
                    }
                    for (int v : g[u]) {
                        if (!vis[v]) {
                            vis[v] = true;
                            q.push(v);
                        }
                    }
                }
            }
        };
        vector<int> ans;
        for (const auto& q : queries) {
            g[q[0]].push_back(q[1]);
            ans.push_back(bfs(0));
        }
        return ans;
    }
};
```

#### Go

```go
func shortestDistanceAfterQueries(n int, queries [][]int) []int {
	g := make([][]int, n)
	for i := range g {
		g[i] = append(g[i], i+1)
	}
	bfs := func(i int) int {
		q := []int{i}
		vis := make([]bool, n)
		vis[i] = true
		for d := 0; ; d++ {
			for k := len(q); k > 0; k-- {
				u := q[0]
				if u == n-1 {
					return d
				}
				q = q[1:]
				for _, v := range g[u] {
					if !vis[v] {
						vis[v] = true
						q = append(q, v)
					}
				}
			}
		}
	}
	ans := make([]int, len(queries))
	for i, q := range queries {
		g[q[0]] = append(g[q[0]], q[1])
		ans[i] = bfs(0)
	}
	return ans
}
```

#### TypeScript

```ts
function shortestDistanceAfterQueries(n: number, queries: number[][]): number[] {
    const g: number[][] = Array.from({ length: n }, () => []);
    for (let i = 0; i < n - 1; ++i) {
        g[i].push(i + 1);
    }
    const bfs = (i: number): number => {
        const q: number[] = [i];
        const vis: boolean[] = Array(n).fill(false);
        vis[i] = true;
        for (let d = 0; ; ++d) {
            const nq: number[] = [];
            for (const u of q) {
                if (u === n - 1) {
                    return d;
                }
                for (const v of g[u]) {
                    if (!vis[v]) {
                        vis[v] = true;
                        nq.push(v);
                    }
                }
            }
            q.splice(0, q.length, ...nq);
        }
    };
    const ans: number[] = [];
    for (const [u, v] of queries) {
        g[u].push(v);
        ans.push(bfs(0));
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3244. 新增道路查询后的最短距离 II](https://leetcode.cn/problems/shortest-distance-after-road-addition-queries-ii){#3244}

{{< tabs "3244" >}}

{{% tab "python" %}}
```python
class Solution:
    def shortestDistanceAfterQueries(
        self, n: int, queries: List[List[int]]
    ) -> List[int]:
        nxt = list(range(1, n))
        ans = []
        cnt = n - 1
        for u, v in queries:
            if 0 < nxt[u] < v:
                i = nxt[u]
                while i < v:
                    cnt -= 1
                    nxt[i], i = 0, nxt[i]
                nxt[u] = v
            ans.append(cnt)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] shortestDistanceAfterQueries(int n, int[][] queries) {
        int[] nxt = new int[n - 1];
        for (int i = 1; i < n; ++i) {
            nxt[i - 1] = i;
        }
        int m = queries.length;
        int cnt = n - 1;
        int[] ans = new int[m];
        for (int i = 0; i < m; ++i) {
            int u = queries[i][0], v = queries[i][1];
            if (nxt[u] > 0 && nxt[u] < v) {
                int j = nxt[u];
                while (j < v) {
                    --cnt;
                    int t = nxt[j];
                    nxt[j] = 0;
                    j = t;
                }
                nxt[u] = v;
            }
            ans[i] = cnt;
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
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> nxt(n - 1);
        iota(nxt.begin(), nxt.end(), 1);
        int cnt = n - 1;
        vector<int> ans;
        for (const auto& q : queries) {
            int u = q[0], v = q[1];
            if (nxt[u] && nxt[u] < v) {
                int i = nxt[u];
                while (i < v) {
                    --cnt;
                    int t = nxt[i];
                    nxt[i] = 0;
                    i = t;
                }
                nxt[u] = v;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func shortestDistanceAfterQueries(n int, queries [][]int) (ans []int) {
	nxt := make([]int, n-1)
	for i := range nxt {
		nxt[i] = i + 1
	}
	cnt := n - 1
	for _, q := range queries {
		u, v := q[0], q[1]
		if nxt[u] > 0 && nxt[u] < v {
			i := nxt[u]
			for i < v {
				cnt--
				nxt[i], i = 0, nxt[i]
			}
			nxt[u] = v
		}
		ans = append(ans, cnt)
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function shortestDistanceAfterQueries(n: number, queries: number[][]): number[] {
    const nxt: number[] = Array.from({ length: n - 1 }, (_, i) => i + 1);
    const ans: number[] = [];
    let cnt = n - 1;
    for (const [u, v] of queries) {
        if (nxt[u] && nxt[u] < v) {
            let i = nxt[u];
            while (i < v) {
                --cnt;
                [nxt[i], i] = [0, nxt[i]];
            }
            nxt[u] = v;
        }
        ans.push(cnt);
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

<p>给你一个整数 <code>n</code> 和一个二维整数数组 <code>queries</code>。</p>

<p>有 <code>n</code> 个城市，编号从 <code>0</code> 到 <code>n - 1</code>。初始时，每个城市 <code>i</code> 都有一条<strong>单向</strong>道路通往城市 <code>i + 1</code>（ <code>0 &lt;= i &lt; n - 1</code>）。</p>

<p><code>queries[i] = [u<sub>i</sub>, v<sub>i</sub>]</code> 表示新建一条从城市 <code>u<sub>i</sub></code> 到城市 <code>v<sub>i</sub></code> 的<strong>单向</strong>道路。每次查询后，你需要找到从城市 <code>0</code> 到城市 <code>n - 1</code> 的<strong>最短路径</strong>的<strong>长度</strong>。</p>

<p>所有查询中不会存在两个查询都满足 <code>queries[i][0] &lt; queries[j][0] &lt; queries[i][1] &lt; queries[j][1]</code>。</p>

<p>返回一个数组 <code>answer</code>，对于范围 <code>[0, queries.length - 1]</code> 中的每个 <code>i</code>，<code>answer[i]</code> 是处理完<strong>前</strong> <code>i + 1</code> 个查询后，从城市 <code>0</code> 到城市 <code>n - 1</code> 的最短路径的<em>长度</em>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">n = 5, queries = [[2, 4], [0, 2], [0, 4]]</span></p>

<p><strong>输出：</strong> <span class="example-io">[3, 2, 1]</span></p>

<p><strong>解释：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3200-3299/3244.Shortest%20Distance%20After%20Road%20Addition%20Queries%20II/images/image8.jpg" style="width: 350px; height: 60px;" /></p>

<p>新增一条从 2 到 4 的道路后，从 0 到 4 的最短路径长度为 3。</p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3200-3299/3244.Shortest%20Distance%20After%20Road%20Addition%20Queries%20II/images/image9.jpg" style="width: 350px; height: 60px;" /></p>

<p>新增一条从 0 到 2 的道路后，从 0 到 4 的最短路径长度为 2。</p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3200-3299/3244.Shortest%20Distance%20After%20Road%20Addition%20Queries%20II/images/image10.jpg" style="width: 350px; height: 96px;" /></p>

<p>新增一条从 0 到 4 的道路后，从 0 到 4 的最短路径长度为 1。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">n = 4, queries = [[0, 3], [0, 2]]</span></p>

<p><strong>输出：</strong> <span class="example-io">[1, 1]</span></p>

<p><strong>解释：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3200-3299/3244.Shortest%20Distance%20After%20Road%20Addition%20Queries%20II/images/image11.jpg" style="width: 300px; height: 70px;" /></p>

<p>新增一条从 0 到 3 的道路后，从 0 到 3 的最短路径长度为 1。</p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3200-3299/3244.Shortest%20Distance%20After%20Road%20Addition%20Queries%20II/images/image12.jpg" style="width: 300px; height: 70px;" /></p>

<p>新增一条从 0 到 2 的道路后，从 0 到 3 的最短路径长度仍为 1。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>3 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= queries.length &lt;= 10<sup>5</sup></code></li>
	<li><code>queries[i].length == 2</code></li>
	<li><code>0 &lt;= queries[i][0] &lt; queries[i][1] &lt; n</code></li>
	<li><code>1 &lt; queries[i][1] - queries[i][0]</code></li>
	<li>查询中不存在重复的道路。</li>
	<li>不存在两个查询都满足 <code>i != j</code> 且 <code>queries[i][0] &lt; queries[j][0] &lt; queries[i][1] &lt; queries[j][1]</code>。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 记录跳转位置

我们定义一个长度为 $n - 1$ 的数组 $\textit{nxt}$，其中 $\textit{nxt}[i]$ 表示从城市 $i$ 可以到达的下一个城市的编号。初始时 $\textit{nxt}[i] = i + 1$。

对于每次查询 $[u, v]$，如果此前已经连通了 $u'$ 和 $v'$，且 $u' <= u < v <= v'$，那么我们可以跳过这次查询。否则，我们需要将 $nxt[u]$ 到 $nxt[v - 1]$ 这些城市的下一个城市编号设置为 $0$，并将 $nxt[u]$ 设置为 $v$。

在这个过程中，我们维护一个变量 $\textit{cnt}$，表示从城市 $0$ 到城市 $n - 1$ 的最短路径的长度。初始时 $\textit{cnt} = n - 1$。每一次，如果我们将 $[\textit{nxt}[u], \textit{v})$ 这些城市的下一个城市编号设置为 $0$，那么 $\textit{cnt}$ 就会减少 $1$。

时间复杂度 $O(n + q)$，空间复杂度 $O(n)$。其中 $n$ 和 $q$ 分别是城市数量和查询数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def shortestDistanceAfterQueries(
        self, n: int, queries: List[List[int]]
    ) -> List[int]:
        nxt = list(range(1, n))
        ans = []
        cnt = n - 1
        for u, v in queries:
            if 0 < nxt[u] < v:
                i = nxt[u]
                while i < v:
                    cnt -= 1
                    nxt[i], i = 0, nxt[i]
                nxt[u] = v
            ans.append(cnt)
        return ans
```

#### Java

```java
class Solution {
    public int[] shortestDistanceAfterQueries(int n, int[][] queries) {
        int[] nxt = new int[n - 1];
        for (int i = 1; i < n; ++i) {
            nxt[i - 1] = i;
        }
        int m = queries.length;
        int cnt = n - 1;
        int[] ans = new int[m];
        for (int i = 0; i < m; ++i) {
            int u = queries[i][0], v = queries[i][1];
            if (nxt[u] > 0 && nxt[u] < v) {
                int j = nxt[u];
                while (j < v) {
                    --cnt;
                    int t = nxt[j];
                    nxt[j] = 0;
                    j = t;
                }
                nxt[u] = v;
            }
            ans[i] = cnt;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> nxt(n - 1);
        iota(nxt.begin(), nxt.end(), 1);
        int cnt = n - 1;
        vector<int> ans;
        for (const auto& q : queries) {
            int u = q[0], v = q[1];
            if (nxt[u] && nxt[u] < v) {
                int i = nxt[u];
                while (i < v) {
                    --cnt;
                    int t = nxt[i];
                    nxt[i] = 0;
                    i = t;
                }
                nxt[u] = v;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};
```

#### Go

```go
func shortestDistanceAfterQueries(n int, queries [][]int) (ans []int) {
	nxt := make([]int, n-1)
	for i := range nxt {
		nxt[i] = i + 1
	}
	cnt := n - 1
	for _, q := range queries {
		u, v := q[0], q[1]
		if nxt[u] > 0 && nxt[u] < v {
			i := nxt[u]
			for i < v {
				cnt--
				nxt[i], i = 0, nxt[i]
			}
			nxt[u] = v
		}
		ans = append(ans, cnt)
	}
	return
}
```

#### TypeScript

```ts
function shortestDistanceAfterQueries(n: number, queries: number[][]): number[] {
    const nxt: number[] = Array.from({ length: n - 1 }, (_, i) => i + 1);
    const ans: number[] = [];
    let cnt = n - 1;
    for (const [u, v] of queries) {
        if (nxt[u] && nxt[u] < v) {
            let i = nxt[u];
            while (i < v) {
                --cnt;
                [nxt[i], i] = [0, nxt[i]];
            }
            nxt[u] = v;
        }
        ans.push(cnt);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3245. 交替组 III](https://leetcode.cn/problems/alternating-groups-iii){#3245}

{{< tabs "3245" >}}

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

<p>给你一个整数数组 <code>colors</code> 和一个二维整数数组 <code>queries</code> 。<code>colors</code>表示一个由红色和蓝色瓷砖组成的环，第 <code>i</code>&nbsp;块瓷砖的颜色为&nbsp;<code>colors[i]</code>&nbsp;：</p>

<ul>
	<li><code>colors[i] == 0</code>&nbsp;表示第&nbsp;<code>i</code>&nbsp;块瓷砖的颜色是 <strong>红色</strong>&nbsp;。</li>
	<li><code>colors[i] == 1</code>&nbsp;表示第 <code>i</code>&nbsp;块瓷砖的颜色是 <strong>蓝色</strong>&nbsp;。</li>
</ul>

<p>环中连续若干块瓷砖的颜色如果是 <strong>交替</strong>&nbsp;颜色（也就是说这组瓷砖中除了第一块和最后一块瓷砖以外，中间瓷砖的颜色与它<strong>&nbsp;左边</strong>&nbsp;和 <strong>右边</strong>&nbsp;的颜色都不同），那么它被称为一个 <strong>交替组</strong>。</p>

<p>你需要处理两种类型的查询：</p>

<ul>
	<li><code>queries[i] = [1, size<sub>i</sub>]</code>，确定大小为<code>size<sub>i</sub></code>的<strong> </strong><strong>交替组</strong> 的数量。</li>
	<li><code>queries[i] = [2, index<sub>i</sub>, color<sub>i</sub>]</code>，将<code>colors[index<sub>i</sub>]</code>更改为<code>color<sub>i</sub></code>。</li>
</ul>

<p>返回数组 <code>answer</code>，数组中按顺序包含第一种类型查询的结果。</p>

<p><b>注意</b>&nbsp;，由于&nbsp;<code>colors</code>&nbsp;表示一个 <strong>环</strong>&nbsp;，<strong>第一块</strong>&nbsp;瓷砖和 <strong>最后一块</strong>&nbsp;瓷砖是相邻的。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">colors = [0,1,1,0,1], queries = [[2,1,0],[1,4]]</span></p>

<p><strong>输出：</strong><span class="example-io">[2]</span></p>

<p><strong>解释：</strong></p>

<p>第一次查询：</p>

<p>将 <code>colors[1]</code> 改为 0。</p>

<p><img alt="" data-darkreader-inline-bgcolor="" data-darkreader-inline-bgimage="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3200-3299/3245.Alternating%20Groups%20III/images/screenshot-from-2024-06-03-20-20-25.png" style="width: 150px; height: 150px; padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem; --darkreader-inline-bgimage: initial; --darkreader-inline-bgcolor: #181a1b;" /></p>

<p>第二次查询：</p>

<p>统计大小为 4 的交替组的数量：</p>

<p><img alt="" data-darkreader-inline-bgcolor="" data-darkreader-inline-bgimage="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3200-3299/3245.Alternating%20Groups%20III/images/screenshot-from-2024-06-03-20-25-02-2.png" style="width: 150px; height: 150px; padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem; --darkreader-inline-bgimage: initial; --darkreader-inline-bgcolor: #181a1b;" /><img alt="" data-darkreader-inline-bgcolor="" data-darkreader-inline-bgimage="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3200-3299/3245.Alternating%20Groups%20III/images/screenshot-from-2024-06-03-20-24-12.png" style="width: 150px; height: 150px; padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem; --darkreader-inline-bgimage: initial; --darkreader-inline-bgcolor: #181a1b;" /></p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">colors = [0,0,1,0,1,1], queries = [[1,3],[2,3,0],[1,5]]</span></p>

<p><strong>输出：</strong><span class="example-io">[2,0]</span></p>

<p><strong>解释：</strong></p>

<p><img alt="" data-darkreader-inline-bgcolor="" data-darkreader-inline-bgimage="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3200-3299/3245.Alternating%20Groups%20III/images/screenshot-from-2024-06-03-20-35-50.png" style="width: 150px; height: 150px; padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem; --darkreader-inline-bgimage: initial; --darkreader-inline-bgcolor: #181a1b;" /></p>

<p>第一次查询：</p>

<p>统计大小为 3 的交替组的数量。</p>

<p><img alt="" data-darkreader-inline-bgcolor="" data-darkreader-inline-bgimage="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3200-3299/3245.Alternating%20Groups%20III/images/screenshot-from-2024-06-03-20-37-13.png" style="width: 150px; height: 150px; padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem; --darkreader-inline-bgimage: initial; --darkreader-inline-bgcolor: #181a1b;" /><img alt="" data-darkreader-inline-bgcolor="" data-darkreader-inline-bgimage="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3200-3299/3245.Alternating%20Groups%20III/images/screenshot-from-2024-06-03-20-36-40.png" style="width: 150px; height: 150px; padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem; --darkreader-inline-bgimage: initial; --darkreader-inline-bgcolor: #181a1b;" /></p>

<p>第二次查询：<code>colors</code>不变。</p>

<p>第三次查询：不存在大小为 5 的交替组。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>4 &lt;= colors.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>0 &lt;= colors[i] &lt;= 1</code></li>
	<li><code>1 &lt;= queries.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>queries[i][0] == 1</code> 或 <code>queries[i][0] == 2</code></li>
	<li>对于所有的<code>i</code>：
	<ul>
		<li><code>queries[i][0] == 1</code>： <code>queries[i].length == 2</code>, <code>3 &lt;= queries[i][1] &lt;= colors.length - 1</code></li>
		<li><code>queries[i][0] == 2</code>： <code>queries[i].length == 3</code>, <code>0 &lt;= queries[i][1] &lt;= colors.length - 1</code>, <code>0 &lt;= queries[i][2] &lt;= 1</code></li>
	</ul>
	</li>
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

# [3246. 英超积分榜排名 🔒](https://leetcode.cn/problems/premier-league-table-ranking){#3246}

{{< tabs "3246" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT
    team_id,
    team_name,
    wins * 3 + draws points,
    RANK() OVER (ORDER BY (wins * 3 + draws) DESC) position
FROM TeamStats
ORDER BY 3 DESC, 2;
```
{{% /tab %}}
{{% tab "python" %}}
```python
import pandas as pd


def calculate_team_standings(team_stats: pd.DataFrame) -> pd.DataFrame:
    team_stats["points"] = team_stats["wins"] * 3 + team_stats["draws"]
    team_stats["position"] = team_stats["points"].rank(method="min", ascending=False)
    team_stats = team_stats.sort_values(
        by=["points", "team_name"], ascending=[False, True]
    )
    return team_stats[["team_id", "team_name", "points", "position"]]
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code>TeamStats</code></p>

<pre>
+------------------+---------+
| Column Name      | Type    |
+------------------+---------+
| team_id          | int     |
| team_name        | varchar |
| matches_played   | int     |
| wins             | int     |
| draws            | int     |
| losses           | int     |
+------------------+---------+
team_id 是这张表的唯一主键。
这张表包含队伍 id，队伍名，场次，赢局，平局和输局。
</pre>

<p>编写一个解决方案来计算联盟中每支球队的 <strong>得分</strong> 和 <strong>排名</strong>。积分计算方式如下：</p>

<ul>
	<li><strong>赢局</strong> 有&nbsp;<code>3</code>&nbsp;点得分</li>
	<li><strong>平局</strong> 有&nbsp;<code>1</code>&nbsp;点得分</li>
	<li><strong>输局</strong> 有&nbsp;<code>0</code>&nbsp;点得分</li>
</ul>

<p><b>注意：</b>积分相同的球队必须分配相同的排名。</p>

<p>返回结果表以&nbsp;<code>points</code>&nbsp;<strong>降序</strong>&nbsp;排序，然后以&nbsp;<code>team_name</code> <strong>升序</strong>&nbsp;排序。</p>

<p>结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong class="example">示例：</strong></p>

<div class="example-block">
<p><strong>输入：</strong></p>

<p><code>TeamStats</code> 表：</p>

<pre class="example-io">
+---------+-----------------+----------------+------+-------+--------+
| team_id | team_name       | matches_played | wins | draws | losses |
+---------+-----------------+----------------+------+-------+--------+
| 1       | Manchester City | 10             | 6    | 2     | 2      |
| 2       | Liverpool       | 10             | 6    | 2     | 2      |
| 3       | Chelsea         | 10             | 5    | 3     | 2      |
| 4       | Arsenal         | 10             | 4    | 4     | 2      |
| 5       | Tottenham       | 10             | 3    | 5     | 2      |
+---------+-----------------+----------------+------+-------+--------+
</pre>

<p><strong>输出：</strong></p>

<pre class="example-io">
+---------+-----------------+--------+----------+
| team_id | team_name       | points | position |
+---------+-----------------+--------+----------+
| 2       | Liverpool       | 20     | 1        |
| 1       | Manchester City | 20     | 1        |
| 3       | Chelsea         | 18     | 3        |
| 4       | Arsenal         | 16     | 4        |
| 5       | Tottenham       | 14     | 5        |
+---------+-----------------+--------+----------+
</pre>

<p><strong>解释：</strong></p>

<ul>
	<li>曼城和利物浦均拿下 20 分（6 赢 * 3 分 + 2 平 * 1 分），所以他们并列第一。</li>
	<li>切尔西拿下&nbsp;18 分（5 赢 * 3 分 + 3 平 * 1 分）所以位列第三。</li>
	<li>阿森纳拿下 16 分（4 赢 * 3 分 + 4 平 * 1 分）位列第四。</li>
	<li>托特纳姆热刺队拿下 14 分（3 赢 * 3 分 + 5 平 * 1 分）位列第五。</li>
</ul>

<p>输出表以得分降序排序，然后以&nbsp;team_name 升序排序。</p>
</div>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：窗口函数

我们可以使用 `RANK()` 窗口函数来计算球队的排名，然后按照得分和球队名进行排序。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT
    team_id,
    team_name,
    wins * 3 + draws points,
    RANK() OVER (ORDER BY (wins * 3 + draws) DESC) position
FROM TeamStats
ORDER BY 3 DESC, 2;
```

#### Pandas

```python
import pandas as pd


def calculate_team_standings(team_stats: pd.DataFrame) -> pd.DataFrame:
    team_stats["points"] = team_stats["wins"] * 3 + team_stats["draws"]
    team_stats["position"] = team_stats["points"].rank(method="min", ascending=False)
    team_stats = team_stats.sort_values(
        by=["points", "team_name"], ascending=[False, True]
    )
    return team_stats[["team_id", "team_name", "points", "position"]]
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3247. 奇数和子序列的数量 🔒](https://leetcode.cn/problems/number-of-subsequences-with-odd-sum){#3247}

{{< tabs "3247" >}}

{{% tab "python" %}}
```python
class Solution:
    def subsequenceCount(self, nums: List[int]) -> int:
        mod = 10**9 + 7
        f = [0] * 2
        for x in nums:
            if x % 2:
                f[0], f[1] = (f[0] + f[1]) % mod, (f[0] + f[1] + 1) % mod
            else:
                f[0], f[1] = (f[0] + f[0] + 1) % mod, (f[1] + f[1]) % mod
        return f[1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int subsequenceCount(int[] nums) {
        final int mod = (int) 1e9 + 7;
        int[] f = new int[2];
        for (int x : nums) {
            int[] g = new int[2];
            if (x % 2 == 1) {
                g[0] = (f[0] + f[1]) % mod;
                g[1] = (f[0] + f[1] + 1) % mod;
            } else {
                g[0] = (f[0] + f[0] + 1) % mod;
                g[1] = (f[1] + f[1]) % mod;
            }
            f = g;
        }
        return f[1];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int subsequenceCount(vector<int>& nums) {
        const int mod = 1e9 + 7;
        vector<int> f(2);
        for (int x : nums) {
            vector<int> g(2);
            if (x % 2 == 1) {
                g[0] = (f[0] + f[1]) % mod;
                g[1] = (f[0] + f[1] + 1) % mod;
            } else {
                g[0] = (f[0] + f[0] + 1) % mod;
                g[1] = (f[1] + f[1]) % mod;
            }
            f = g;
        }
        return f[1];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func subsequenceCount(nums []int) int {
	mod := int(1e9 + 7)
	f := [2]int{}
	for _, x := range nums {
		g := [2]int{}
		if x%2 == 1 {
			g[0] = (f[0] + f[1]) % mod
			g[1] = (f[0] + f[1] + 1) % mod
		} else {
			g[0] = (f[0] + f[0] + 1) % mod
			g[1] = (f[1] + f[1]) % mod
		}
		f = g
	}
	return f[1]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function subsequenceCount(nums: number[]): number {
    const mod = 1e9 + 7;
    let f = [0, 0];
    for (const x of nums) {
        const g = [0, 0];
        if (x % 2 === 1) {
            g[0] = (f[0] + f[1]) % mod;
            g[1] = (f[0] + f[1] + 1) % mod;
        } else {
            g[0] = (f[0] + f[0] + 1) % mod;
            g[1] = (f[1] + f[1]) % mod;
        }
        f = g;
    }
    return f[1];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个数组&nbsp;<code>nums</code>，返回元素和为奇数的 <span data-keyword="subsequence-array">子序列</span> 的数量。</p>

<p>由于答案可能很大，返回答案对&nbsp;<code>10<sup>9</sup> + 7</code>&nbsp;<strong>取模</strong>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b></span><span class="example-io">nums = [1,1,1]</span></p>

<p><span class="example-io"><b>输出：</b></span><span class="example-io">4</span></p>

<p><strong>解释：</strong></p>

<p>奇数和子序列为：<code>[<u><strong>1</strong></u>, 1, 1]</code>, <code>[1, <u><strong>1</strong></u>, 1],</code> <code>[1, 1, <u><strong>1</strong></u>]</code>, <code>[<u><strong>1, 1, 1</strong></u>]</code>.</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [1,2,2]</span></p>

<p><span class="example-io"><b>输出：</b>4</span></p>

<p><strong>解释：</strong></p>

<p>奇数和子序列为：<code>[<u><strong>1</strong></u>, 2, 2]</code>, <code>[<u><strong>1, 2</strong></u>, 2],</code> <code>[<u><strong>1</strong></u>, 2, <b><u>2</u></b>]</code>, <code>[<u><strong>1, 2, 2</strong></u>]</code>.</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[0]$ 表示目前为止的子序列中，和为偶数的子序列个数，而 $f[1]$ 表示目前为止的子序列中，和为奇数的子序列个数。初始时 $f[0] = 0$, $f[1] = 0$。

遍历数组 $\textit{nums}$，对于每个数 $x$：

如果 $x$ 为奇数，那么 $f[0]$ 和 $f[1]$ 的更新方式为：

$$
\begin{aligned}
f[0] & = (f[0] + f[1]) \bmod 10^9 + 7, \\
f[1] & = (f[0] + f[1] + 1) \bmod 10^9 + 7.
\end{aligned}
$$

即，当前的和为偶数的子序列个数等于之前的和为偶数的子序列个数，加上之前的和为奇数的子序列拼上当前数 $x$ 的子序列个数；当前的和为奇数的子序列个数等于之前的和为偶数的子序列拼上当前数 $x$ 的子序列个数，加上之前的和为奇数的子序列个数，再加上一个只包含当前数 $x$ 的子序列。

如果 $x$ 为偶数，那么 $f[0]$ 和 $f[1]$ 的更新方式为：

$$
\begin{aligned}
f[0] & = (f[0] + f[0] + 1) \bmod 10^9 + 7, \\
f[1] & = (f[1] + f[1]) \bmod 10^9 + 7.
\end{aligned}
$$

即，当前的和为偶数的子序列个数等于之前的和为偶数的子序列个数，加上之前的和为偶数的子序列拼上当前数 $x$ 的子序列个数，再加上一个只包含当前数 $x$ 的子序列；当前的和为奇数的子序列个数等于之前的和为奇数的子序列拼上当前数 $x$ 的子序列个数，加上之前的和为奇数的子序列个数。

最终，返回 $f[1]$ 即可。

时间复杂度 $O(n)$，其中 $n$ 为数组 $\textit{nums}$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def subsequenceCount(self, nums: List[int]) -> int:
        mod = 10**9 + 7
        f = [0] * 2
        for x in nums:
            if x % 2:
                f[0], f[1] = (f[0] + f[1]) % mod, (f[0] + f[1] + 1) % mod
            else:
                f[0], f[1] = (f[0] + f[0] + 1) % mod, (f[1] + f[1]) % mod
        return f[1]
```

#### Java

```java
class Solution {
    public int subsequenceCount(int[] nums) {
        final int mod = (int) 1e9 + 7;
        int[] f = new int[2];
        for (int x : nums) {
            int[] g = new int[2];
            if (x % 2 == 1) {
                g[0] = (f[0] + f[1]) % mod;
                g[1] = (f[0] + f[1] + 1) % mod;
            } else {
                g[0] = (f[0] + f[0] + 1) % mod;
                g[1] = (f[1] + f[1]) % mod;
            }
            f = g;
        }
        return f[1];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int subsequenceCount(vector<int>& nums) {
        const int mod = 1e9 + 7;
        vector<int> f(2);
        for (int x : nums) {
            vector<int> g(2);
            if (x % 2 == 1) {
                g[0] = (f[0] + f[1]) % mod;
                g[1] = (f[0] + f[1] + 1) % mod;
            } else {
                g[0] = (f[0] + f[0] + 1) % mod;
                g[1] = (f[1] + f[1]) % mod;
            }
            f = g;
        }
        return f[1];
    }
};
```

#### Go

```go
func subsequenceCount(nums []int) int {
	mod := int(1e9 + 7)
	f := [2]int{}
	for _, x := range nums {
		g := [2]int{}
		if x%2 == 1 {
			g[0] = (f[0] + f[1]) % mod
			g[1] = (f[0] + f[1] + 1) % mod
		} else {
			g[0] = (f[0] + f[0] + 1) % mod
			g[1] = (f[1] + f[1]) % mod
		}
		f = g
	}
	return f[1]
}
```

#### TypeScript

```ts
function subsequenceCount(nums: number[]): number {
    const mod = 1e9 + 7;
    let f = [0, 0];
    for (const x of nums) {
        const g = [0, 0];
        if (x % 2 === 1) {
            g[0] = (f[0] + f[1]) % mod;
            g[1] = (f[0] + f[1] + 1) % mod;
        } else {
            g[0] = (f[0] + f[0] + 1) % mod;
            g[1] = (f[1] + f[1]) % mod;
        }
        f = g;
    }
    return f[1];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3248. 矩阵中的蛇](https://leetcode.cn/problems/snake-in-matrix){#3248}

{{< tabs "3248" >}}

{{% tab "python" %}}
```python
class Solution:
    def finalPositionOfSnake(self, n: int, commands: List[str]) -> int:
        x = y = 0
        for c in commands:
            match c[0]:
                case "U":
                    x -= 1
                case "D":
                    x += 1
                case "L":
                    y -= 1
                case "R":
                    y += 1
        return x * n + y
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int finalPositionOfSnake(int n, List<String> commands) {
        int x = 0, y = 0;
        for (var c : commands) {
            switch (c.charAt(0)) {
                case 'U' -> x--;
                case 'D' -> x++;
                case 'L' -> y--;
                case 'R' -> y++;
            }
        }
        return x * n + y;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int x = 0, y = 0;
        for (const auto& c : commands) {
            switch (c[0]) {
            case 'U': x--; break;
            case 'D': x++; break;
            case 'L': y--; break;
            case 'R': y++; break;
            }
        }
        return x * n + y;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func finalPositionOfSnake(n int, commands []string) int {
	x, y := 0, 0
	for _, c := range commands {
		switch c[0] {
		case 'U':
			x--
		case 'D':
			x++
		case 'L':
			y--
		case 'R':
			y++
		}
	}
	return x*n + y
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function finalPositionOfSnake(n: number, commands: string[]): number {
    let [x, y] = [0, 0];
    for (const c of commands) {
        c[0] === 'U' && x--;
        c[0] === 'D' && x++;
        c[0] === 'L' && y--;
        c[0] === 'R' && y++;
    }
    return x * n + y;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>大小为 <code>n x n</code> 的矩阵 <code>grid</code> 中有一条蛇。蛇可以朝 <strong>四个可能的方向 </strong>移动。矩阵中的每个单元格都使用位置进行标识： <code>grid[i][j] = (i * n) + j</code>。</p>

<p>蛇从单元格 0 开始，并遵循一系列命令移动。</p>

<p>给你一个整数 <code>n</code> 表示 <code>grid</code> 的大小，另给你一个字符串数组 <code>commands</code>，其中包括 <code>"UP"</code>、<code>"RIGHT"</code>、<code>"DOWN"</code> 和 <code>"LEFT"</code>。题目测评数据保证蛇在整个移动过程中将始终位于 <code>grid</code> 边界内。</p>

<p>返回执行 <code>commands</code> 后蛇所停留的最终单元格的位置。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">n = 2, commands = ["RIGHT","DOWN"]</span></p>

<p><strong>输出：</strong><span class="example-io">3</span></p>

<p><strong>解释：</strong></p>

<div style="display:flex; gap: 12px;">
<table border="1" cellspacing="3" style="border-collapse: separate; text-align: center;">
	<tbody>
		<tr>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid red; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">0</td>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #b30000; --darkreader-inline-border-right: #b30000; --darkreader-inline-border-bottom: #b30000; --darkreader-inline-border-left: #b30000;">1</td>
		</tr>
		<tr>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">2</td>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #b30000; --darkreader-inline-border-right: #b30000; --darkreader-inline-border-bottom: #b30000; --darkreader-inline-border-left: #b30000;">3</td>
		</tr>
	</tbody>
</table>

<table border="1" cellspacing="3" style="border-collapse: separate; text-align: center;">
	<tbody>
		<tr>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">0</td>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid red; --darkreader-inline-border-top: #b30000; --darkreader-inline-border-right: #b30000; --darkreader-inline-border-bottom: #b30000; --darkreader-inline-border-left: #b30000;">1</td>
		</tr>
		<tr>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">2</td>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #b30000; --darkreader-inline-border-right: #b30000; --darkreader-inline-border-bottom: #b30000; --darkreader-inline-border-left: #b30000;">3</td>
		</tr>
	</tbody>
</table>

<table border="1" cellspacing="3" style="border-collapse: separate; text-align: center;">
	<tbody>
		<tr>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">0</td>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #b30000; --darkreader-inline-border-right: #b30000; --darkreader-inline-border-bottom: #b30000; --darkreader-inline-border-left: #b30000;">1</td>
		</tr>
		<tr>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">2</td>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid red; --darkreader-inline-border-top: #b30000; --darkreader-inline-border-right: #b30000; --darkreader-inline-border-bottom: #b30000; --darkreader-inline-border-left: #b30000;">3</td>
		</tr>
	</tbody>
</table>
</div>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">n = 3, commands = ["DOWN","RIGHT","UP"]</span></p>

<p><strong>输出：</strong><span class="example-io">1</span></p>

<p><strong>解释：</strong></p>

<div style="display:flex; gap: 12px;">
<table border="1" cellspacing="3" style="border-collapse: separate; text-align: center;">
	<tbody>
		<tr>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid red; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">0</td>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #b30000; --darkreader-inline-border-right: #b30000; --darkreader-inline-border-bottom: #b30000; --darkreader-inline-border-left: #b30000;">1</td>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">2</td>
		</tr>
		<tr>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">3</td>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #b30000; --darkreader-inline-border-right: #b30000; --darkreader-inline-border-bottom: #b30000; --darkreader-inline-border-left: #b30000;">4</td>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #b30000; --darkreader-inline-border-right: #b30000; --darkreader-inline-border-bottom: #b30000; --darkreader-inline-border-left: #b30000;">5</td>
		</tr>
		<tr>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">6</td>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">7</td>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">8</td>
		</tr>
	</tbody>
</table>

<table border="1" cellspacing="3" style="border-collapse: separate; text-align: center;">
	<tbody>
		<tr>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">0</td>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #b30000; --darkreader-inline-border-right: #b30000; --darkreader-inline-border-bottom: #b30000; --darkreader-inline-border-left: #b30000;">1</td>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">2</td>
		</tr>
		<tr>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid red; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">3</td>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #b30000; --darkreader-inline-border-right: #b30000; --darkreader-inline-border-bottom: #b30000; --darkreader-inline-border-left: #b30000;">4</td>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #b30000; --darkreader-inline-border-right: #b30000; --darkreader-inline-border-bottom: #b30000; --darkreader-inline-border-left: #b30000;">5</td>
		</tr>
		<tr>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">6</td>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">7</td>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">8</td>
		</tr>
	</tbody>
</table>

<table border="1" cellspacing="3" style="border-collapse: separate; text-align: center;">
	<tbody>
		<tr>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">0</td>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">1</td>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">2</td>
		</tr>
		<tr>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">3</td>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid red; --darkreader-inline-border-top: #b30000; --darkreader-inline-border-right: #b30000; --darkreader-inline-border-bottom: #b30000; --darkreader-inline-border-left: #b30000;">4</td>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #b30000; --darkreader-inline-border-right: #b30000; --darkreader-inline-border-bottom: #b30000; --darkreader-inline-border-left: #b30000;">5</td>
		</tr>
		<tr>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">6</td>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #b30000; --darkreader-inline-border-right: #b30000; --darkreader-inline-border-bottom: #b30000; --darkreader-inline-border-left: #b30000;">7</td>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">8</td>
		</tr>
	</tbody>
</table>

<table border="1" cellspacing="3" style="border-collapse: separate; text-align: center;">
	<tbody>
		<tr>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">0</td>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid red; --darkreader-inline-border-top: #b30000; --darkreader-inline-border-right: #b30000; --darkreader-inline-border-bottom: #b30000; --darkreader-inline-border-left: #b30000;">1</td>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">2</td>
		</tr>
		<tr>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">3</td>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #b30000; --darkreader-inline-border-right: #b30000; --darkreader-inline-border-bottom: #b30000; --darkreader-inline-border-left: #b30000;">4</td>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #b30000; --darkreader-inline-border-right: #b30000; --darkreader-inline-border-bottom: #b30000; --darkreader-inline-border-left: #b30000;">5</td>
		</tr>
		<tr>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">6</td>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">7</td>
			<td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">8</td>
		</tr>
	</tbody>
</table>
</div>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 10</code></li>
	<li><code>1 &lt;= commands.length &lt;= 100</code></li>
	<li><code>commands</code> 仅由 <code>"UP"</code>、<code>"RIGHT"</code>、<code>"DOWN"</code> 和 <code>"LEFT"</code> 组成。</li>
	<li>生成的测评数据确保蛇不会移动到矩阵的边界外。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们可以用两个变量 $x$ 和 $y$ 来表示蛇的位置，初始时 $x = y = 0$，然后遍历 $\textit{commands}$，根据当前的命令更新 $x$ 和 $y$ 的值，最后返回 $x \times n + y$ 即可。

时间复杂度 $O(n)$，其中 $n$ 是数组 $\textit{commands}$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def finalPositionOfSnake(self, n: int, commands: List[str]) -> int:
        x = y = 0
        for c in commands:
            match c[0]:
                case "U":
                    x -= 1
                case "D":
                    x += 1
                case "L":
                    y -= 1
                case "R":
                    y += 1
        return x * n + y
```

#### Java

```java
class Solution {
    public int finalPositionOfSnake(int n, List<String> commands) {
        int x = 0, y = 0;
        for (var c : commands) {
            switch (c.charAt(0)) {
                case 'U' -> x--;
                case 'D' -> x++;
                case 'L' -> y--;
                case 'R' -> y++;
            }
        }
        return x * n + y;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int x = 0, y = 0;
        for (const auto& c : commands) {
            switch (c[0]) {
            case 'U': x--; break;
            case 'D': x++; break;
            case 'L': y--; break;
            case 'R': y++; break;
            }
        }
        return x * n + y;
    }
};
```

#### Go

```go
func finalPositionOfSnake(n int, commands []string) int {
	x, y := 0, 0
	for _, c := range commands {
		switch c[0] {
		case 'U':
			x--
		case 'D':
			x++
		case 'L':
			y--
		case 'R':
			y++
		}
	}
	return x*n + y
}
```

#### TypeScript

```ts
function finalPositionOfSnake(n: number, commands: string[]): number {
    let [x, y] = [0, 0];
    for (const c of commands) {
        c[0] === 'U' && x--;
        c[0] === 'D' && x++;
        c[0] === 'L' && y--;
        c[0] === 'R' && y++;
    }
    return x * n + y;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3249. 统计好节点的数目](https://leetcode.cn/problems/count-the-number-of-good-nodes){#3249}

{{< tabs "3249" >}}

{{% tab "python" %}}
```python
class Solution:
    def countGoodNodes(self, edges: List[List[int]]) -> int:
        def dfs(a: int, fa: int) -> int:
            pre = -1
            cnt = ok = 1
            for b in g[a]:
                if b != fa:
                    cur = dfs(b, a)
                    cnt += cur
                    if pre < 0:
                        pre = cur
                    elif pre != cur:
                        ok = 0
            nonlocal ans
            ans += ok
            return cnt

        g = defaultdict(list)
        for a, b in edges:
            g[a].append(b)
            g[b].append(a)
        ans = 0
        dfs(0, -1)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int ans;
    private List<Integer>[] g;

    public int countGoodNodes(int[][] edges) {
        int n = edges.length + 1;
        g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (var e : edges) {
            int a = e[0], b = e[1];
            g[a].add(b);
            g[b].add(a);
        }
        dfs(0, -1);
        return ans;
    }

    private int dfs(int a, int fa) {
        int pre = -1, cnt = 1, ok = 1;
        for (int b : g[a]) {
            if (b != fa) {
                int cur = dfs(b, a);
                cnt += cur;
                if (pre < 0) {
                    pre = cur;
                } else if (pre != cur) {
                    ok = 0;
                }
            }
        }
        ans += ok;
        return cnt;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<int> g[n];
        for (const auto& e : edges) {
            int a = e[0], b = e[1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        int ans = 0;
        auto dfs = [&](this auto&& dfs, int a, int fa) -> int {
            int pre = -1, cnt = 1, ok = 1;
            for (int b : g[a]) {
                if (b != fa) {
                    int cur = dfs(b, a);
                    cnt += cur;
                    if (pre < 0) {
                        pre = cur;
                    } else if (pre != cur) {
                        ok = 0;
                    }
                }
            }
            ans += ok;
            return cnt;
        };
        dfs(0, -1);
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countGoodNodes(edges [][]int) (ans int) {
	n := len(edges) + 1
	g := make([][]int, n)
	for _, e := range edges {
		a, b := e[0], e[1]
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}
	var dfs func(int, int) int
	dfs = func(a, fa int) int {
		pre, cnt, ok := -1, 1, 1
		for _, b := range g[a] {
			if b != fa {
				cur := dfs(b, a)
				cnt += cur
				if pre < 0 {
					pre = cur
				} else if pre != cur {
					ok = 0
				}
			}
		}
		ans += ok
		return cnt
	}
	dfs(0, -1)
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countGoodNodes(edges: number[][]): number {
    const n = edges.length + 1;
    const g: number[][] = Array.from({ length: n }, () => []);
    for (const [a, b] of edges) {
        g[a].push(b);
        g[b].push(a);
    }
    let ans = 0;
    const dfs = (a: number, fa: number): number => {
        let [pre, cnt, ok] = [-1, 1, 1];
        for (const b of g[a]) {
            if (b !== fa) {
                const cur = dfs(b, a);
                cnt += cur;
                if (pre < 0) {
                    pre = cur;
                } else if (pre !== cur) {
                    ok = 0;
                }
            }
        }
        ans += ok;
        return cnt;
    };
    dfs(0, -1);
    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>现有一棵 <strong>无向</strong> 树，树中包含 <code>n</code> 个节点，按从 <code>0</code> 到 <code>n - 1</code> 标记。树的根节点是节点 <code>0</code> 。给你一个长度为 <code>n - 1</code> 的二维整数数组 <code>edges</code>，其中 <code>edges[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> 表示树中节点 <code>a<sub>i</sub></code> 与节点 <code>b<sub>i</sub></code> 之间存在一条边。</p>

<p>如果一个节点的所有子节点为根的&nbsp;<span data-keyword="subtree">子树</span>&nbsp;包含的节点数相同，则认为该节点是一个 <strong>好节点</strong>。</p>

<p>返回给定树中<strong> 好节点 </strong>的数量。</p>

<p><strong>子树</strong>&nbsp;指的是一个节点以及它所有后代节点构成的一棵树。</p>

<p>&nbsp;</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">edges = [[0,1],[0,2],[1,3],[1,4],[2,5],[2,6]]</span></p>

<p><strong>输出：</strong><span class="example-io">7</span></p>

<p><strong>说明：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3200-3299/3249.Count%20the%20Number%20of%20Good%20Nodes/images/tree1.png" style="width: 360px; height: 158px;" />
<p>树的所有节点都是好节点。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">edges = [[0,1],[1,2],[2,3],[3,4],[0,5],[1,6],[2,7],[3,8]]</span></p>

<p><strong>输出：</strong><span class="example-io">6</span></p>

<p><strong>说明：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3200-3299/3249.Count%20the%20Number%20of%20Good%20Nodes/images/screenshot-2024-06-03-193552.png" style="width: 360px; height: 303px;" />
<p>树中有 6 个好节点。上图中已将这些节点着色。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>edges = [[0,1],[1,2],[1,3],[1,4],[0,5],[5,6],[6,7],[7,8],[0,9],[9,10],[9,12],[10,11]]</span></p>

<p><span class="example-io"><b>输出：</b>12</span></p>

<p><strong>解释：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3200-3299/3249.Count%20the%20Number%20of%20Good%20Nodes/images/rob.jpg" style="width: 450px; height: 277px;" />
<p>除了节点 9 以外其他所有节点都是好节点。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>edges.length == n - 1</code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt; n</code></li>
	<li>输入确保 <code>edges</code> 总表示一棵有效的树。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS

我们先根据题目给定的边 $\textit{edges}$ 构建出树的邻接表 $\textit{g}$，其中 $\textit{g}[a]$ 表示节点 $a$ 的所有邻居节点。

然后，我们设计一个函数 $\textit{dfs}(a, \textit{fa})$，表示计算以节点 $a$ 为根的子树中的节点数，并累计好节点的数量。其中 $\textit{fa}$ 表示节点 $a$ 的父节点。

函数 $\textit{dfs}(a, \textit{fa})$ 的执行过程如下：

1. 初始化变量 $\textit{pre} = -1$, $\textit{cnt} = 1$, $\textit{ok} = 1$，分别表示节点 $a$ 的某个子树的节点数、节点 $a$ 的所有子树的节点数、以及节点 $a$ 是否为好节点。
2. 遍历节点 $a$ 的所有邻居节点 $b$，如果 $b$ 不等于 $\textit{fa}$，则递归调用 $\textit{dfs}(b, a)$，返回值为 $\textit{cur}$，并累加到 $\textit{cnt}$ 中。如果 $\textit{pre} < 0$，则将 $\textit{cur}$ 赋值给 $\textit{pre}$；否则，如果 $\textit{pre}$ 不等于 $\textit{cur}$，说明节点 $a$ 的不同子树的节点数不同，将 $\textit{ok}$ 置为 $0$。
3. 最后，累加 $\textit{ok}$ 到答案中，并返回 $\textit{cnt}$。

在主函数中，我们调用 $\textit{dfs}(0, -1)$，最后返回答案。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 表示节点的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countGoodNodes(self, edges: List[List[int]]) -> int:
        def dfs(a: int, fa: int) -> int:
            pre = -1
            cnt = ok = 1
            for b in g[a]:
                if b != fa:
                    cur = dfs(b, a)
                    cnt += cur
                    if pre < 0:
                        pre = cur
                    elif pre != cur:
                        ok = 0
            nonlocal ans
            ans += ok
            return cnt

        g = defaultdict(list)
        for a, b in edges:
            g[a].append(b)
            g[b].append(a)
        ans = 0
        dfs(0, -1)
        return ans
```

#### Java

```java
class Solution {
    private int ans;
    private List<Integer>[] g;

    public int countGoodNodes(int[][] edges) {
        int n = edges.length + 1;
        g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (var e : edges) {
            int a = e[0], b = e[1];
            g[a].add(b);
            g[b].add(a);
        }
        dfs(0, -1);
        return ans;
    }

    private int dfs(int a, int fa) {
        int pre = -1, cnt = 1, ok = 1;
        for (int b : g[a]) {
            if (b != fa) {
                int cur = dfs(b, a);
                cnt += cur;
                if (pre < 0) {
                    pre = cur;
                } else if (pre != cur) {
                    ok = 0;
                }
            }
        }
        ans += ok;
        return cnt;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<int> g[n];
        for (const auto& e : edges) {
            int a = e[0], b = e[1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        int ans = 0;
        auto dfs = [&](this auto&& dfs, int a, int fa) -> int {
            int pre = -1, cnt = 1, ok = 1;
            for (int b : g[a]) {
                if (b != fa) {
                    int cur = dfs(b, a);
                    cnt += cur;
                    if (pre < 0) {
                        pre = cur;
                    } else if (pre != cur) {
                        ok = 0;
                    }
                }
            }
            ans += ok;
            return cnt;
        };
        dfs(0, -1);
        return ans;
    }
};
```

#### Go

```go
func countGoodNodes(edges [][]int) (ans int) {
	n := len(edges) + 1
	g := make([][]int, n)
	for _, e := range edges {
		a, b := e[0], e[1]
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}
	var dfs func(int, int) int
	dfs = func(a, fa int) int {
		pre, cnt, ok := -1, 1, 1
		for _, b := range g[a] {
			if b != fa {
				cur := dfs(b, a)
				cnt += cur
				if pre < 0 {
					pre = cur
				} else if pre != cur {
					ok = 0
				}
			}
		}
		ans += ok
		return cnt
	}
	dfs(0, -1)
	return
}
```

#### TypeScript

```ts
function countGoodNodes(edges: number[][]): number {
    const n = edges.length + 1;
    const g: number[][] = Array.from({ length: n }, () => []);
    for (const [a, b] of edges) {
        g[a].push(b);
        g[b].push(a);
    }
    let ans = 0;
    const dfs = (a: number, fa: number): number => {
        let [pre, cnt, ok] = [-1, 1, 1];
        for (const b of g[a]) {
            if (b !== fa) {
                const cur = dfs(b, a);
                cnt += cur;
                if (pre < 0) {
                    pre = cur;
                } else if (pre !== cur) {
                    ok = 0;
                }
            }
        }
        ans += ok;
        return cnt;
    };
    dfs(0, -1);
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
