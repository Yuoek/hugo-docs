---
title: "3070_元素和小于等于 k 的子矩阵的数目"
date: 2025-10-08T18:39:55+08:00
weight: 8
tags: [前缀和, 动态规划, 哈希表, 字典树, 字符串, 排序, 数学, 数组, 有序集合, 树状数组, 模拟, 矩阵, 线段树, 计数, 贪心]
---

{{< markmap >}}
### [3070_元素和小于等于 k 的子矩阵的数目](#3070)
#### [数组](#3070)
#### [矩阵](#3070)
#### [前缀和](#3070)
### [3071_在矩阵上写出字母 Y 所需的最少操作次数](#3071)
#### [数组](#3071)
#### [哈希表](#3071)
#### [计数](#3071)
#### [矩阵](#3071)
### [3072_将元素分配到两个数组中 II](#3072)
#### [树状数组](#3072)
#### [线段树](#3072)
#### [数组](#3072)
#### [模拟](#3072)
### [3073_最大递增三元组 🔒](#3073)
#### [数组](#3073)
#### [有序集合](#3073)
### [3074_重新分装苹果](#3074)
#### [贪心](#3074)
#### [数组](#3074)
#### [排序](#3074)
### [3075_幸福值最大化的选择方案](#3075)
#### [贪心](#3075)
#### [数组](#3075)
#### [排序](#3075)
### [3076_数组中的最短非公共子字符串](#3076)
#### [字典树](#3076)
#### [数组](#3076)
#### [哈希表](#3076)
#### [字符串](#3076)
### [3077_K 个不相交子数组的最大能量值](#3077)
#### [数组](#3077)
#### [动态规划](#3077)
#### [前缀和](#3077)
### [3078_矩阵中的字母数字模式匹配 I 🔒](#3078)
#### [数组](#3078)
#### [哈希表](#3078)
#### [字符串](#3078)
#### [矩阵](#3078)
### [3079_求出加密整数的和](#3079)
#### [数组](#3079)
#### [数学](#3079)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 3070_元素和小于等于 k 的子矩阵的数目
___
#### 数组
___
#### 矩阵
___
#### 前缀和
---
### 3071_在矩阵上写出字母 Y 所需的最少操作次数
___
#### 数组
___
#### 哈希表
___
#### 计数
___
#### 矩阵
---
### 3072_将元素分配到两个数组中 II
___
#### 树状数组
___
#### 线段树
___
#### 数组
___
#### 模拟
---
### 3073_最大递增三元组 🔒
___
#### 数组
___
#### 有序集合
---
### 3074_重新分装苹果
___
#### 贪心
___
#### 数组
___
#### 排序
---
### 3075_幸福值最大化的选择方案
___
#### 贪心
___
#### 数组
___
#### 排序
---
### 3076_数组中的最短非公共子字符串
___
#### 字典树
___
#### 数组
___
#### 哈希表
___
#### 字符串
---
### 3077_K 个不相交子数组的最大能量值
___
#### 数组
___
#### 动态规划
___
#### 前缀和
---
### 3078_矩阵中的字母数字模式匹配 I 🔒
___
#### 数组
___
#### 哈希表
___
#### 字符串
___
#### 矩阵
---
### 3079_求出加密整数的和
___
#### 数组
___
#### 数学
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 前缀和 | 动态规划 | 哈希表 |
| 字典树 | 字符串 | 排序 |
| 数学 | 数组 | 有序集合 |
| 树状数组 | 模拟 | 矩阵 |
| 线段树 | 计数 | 贪心 |

# [3070. 元素和小于等于 k 的子矩阵的数目](https://leetcode.cn/problems/count-submatrices-with-top-left-element-and-sum-less-than-k){#3070}

{{< tabs "3070" >}}

{{% tab "python" %}}
```python
class Solution:
    def countSubmatrices(self, grid: List[List[int]], k: int) -> int:
        s = [[0] * (len(grid[0]) + 1) for _ in range(len(grid) + 1)]
        ans = 0
        for i, row in enumerate(grid, 1):
            for j, x in enumerate(row, 1):
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + x
                ans += s[i][j] <= k
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countSubmatrices(int[][] grid, int k) {
        int m = grid.length, n = grid[0].length;
        int[][] s = new int[m + 1][n + 1];
        int ans = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + grid[i - 1][j - 1];
                if (s[i][j] <= k) {
                    ++ans;
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
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int s[m + 1][n + 1];
        memset(s, 0, sizeof(s));
        int ans = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + grid[i - 1][j - 1];
                if (s[i][j] <= k) {
                    ++ans;
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
func countSubmatrices(grid [][]int, k int) (ans int) {
	s := make([][]int, len(grid)+1)
	for i := range s {
		s[i] = make([]int, len(grid[0])+1)
	}
	for i, row := range grid {
		for j, x := range row {
			s[i+1][j+1] = s[i+1][j] + s[i][j+1] - s[i][j] + x
			if s[i+1][j+1] <= k {
				ans++
			}
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countSubmatrices(grid: number[][], k: number): number {
    const m = grid.length;
    const n = grid[0].length;
    const s: number[][] = Array.from({ length: m + 1 }, () => Array(n + 1).fill(0));
    let ans: number = 0;
    for (let i = 1; i <= m; ++i) {
        for (let j = 1; j <= n; ++j) {
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + grid[i - 1][j - 1];
            if (s[i][j] <= k) {
                ++ans;
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

<p>给你一个下标从 <strong>0</strong> 开始的整数矩阵 <code>grid</code> 和一个整数 <code>k</code>。</p>

<p>返回包含 <code>grid</code> 左上角元素、元素和小于或等于 <code>k</code> 的 <strong><span data-keyword="submatrix">子矩阵</span></strong>的数目。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3000-3099/3070.Count%20Submatrices%20with%20Top-Left%20Element%20and%20Sum%20Less%20Than%20k/images/example1.png" style="padding: 10px; background: #fff; border-radius: .5rem;" />
<pre>
<strong>输入：</strong>grid = [[7,6,3],[6,6,1]], k = 18
<strong>输出：</strong>4
<strong>解释：</strong>如上图所示，只有 4 个子矩阵满足：包含 grid 的左上角元素，并且元素和小于或等于 18 。</pre>

<p><strong class="example">示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3000-3099/3070.Count%20Submatrices%20with%20Top-Left%20Element%20and%20Sum%20Less%20Than%20k/images/example21.png" style="padding: 10px; background: #fff; border-radius: .5rem;" />
<pre>
<strong>输入：</strong>grid = [[7,2,9],[1,5,0],[2,6,6]], k = 20
<strong>输出：</strong>6
<strong>解释：</strong>如上图所示，只有 6 个子矩阵满足：包含 grid 的左上角元素，并且元素和小于或等于 20 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length </code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= n, m &lt;= 1000 </code></li>
	<li><code>0 &lt;= grid[i][j] &lt;= 1000</code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二维前缀和

题目实际上求的是二维矩阵有多少个和小于等于 $k$ 的前缀子矩阵。

二维前缀和的计算公式为：

$$
s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + x
$$

时间复杂度 $O(m \times n)$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别是矩阵的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countSubmatrices(self, grid: List[List[int]], k: int) -> int:
        s = [[0] * (len(grid[0]) + 1) for _ in range(len(grid) + 1)]
        ans = 0
        for i, row in enumerate(grid, 1):
            for j, x in enumerate(row, 1):
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + x
                ans += s[i][j] <= k
        return ans
```

#### Java

```java
class Solution {
    public int countSubmatrices(int[][] grid, int k) {
        int m = grid.length, n = grid[0].length;
        int[][] s = new int[m + 1][n + 1];
        int ans = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + grid[i - 1][j - 1];
                if (s[i][j] <= k) {
                    ++ans;
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
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int s[m + 1][n + 1];
        memset(s, 0, sizeof(s));
        int ans = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + grid[i - 1][j - 1];
                if (s[i][j] <= k) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func countSubmatrices(grid [][]int, k int) (ans int) {
	s := make([][]int, len(grid)+1)
	for i := range s {
		s[i] = make([]int, len(grid[0])+1)
	}
	for i, row := range grid {
		for j, x := range row {
			s[i+1][j+1] = s[i+1][j] + s[i][j+1] - s[i][j] + x
			if s[i+1][j+1] <= k {
				ans++
			}
		}
	}
	return
}
```

#### TypeScript

```ts
function countSubmatrices(grid: number[][], k: number): number {
    const m = grid.length;
    const n = grid[0].length;
    const s: number[][] = Array.from({ length: m + 1 }, () => Array(n + 1).fill(0));
    let ans: number = 0;
    for (let i = 1; i <= m; ++i) {
        for (let j = 1; j <= n; ++j) {
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + grid[i - 1][j - 1];
            if (s[i][j] <= k) {
                ++ans;
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

# [3071. 在矩阵上写出字母 Y 所需的最少操作次数](https://leetcode.cn/problems/minimum-operations-to-write-the-letter-y-on-a-grid){#3071}

{{< tabs "3071" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumOperationsToWriteY(self, grid: List[List[int]]) -> int:
        n = len(grid)
        cnt1 = Counter()
        cnt2 = Counter()
        for i, row in enumerate(grid):
            for j, x in enumerate(row):
                a = i == j and i <= n // 2
                b = i + j == n - 1 and i <= n // 2
                c = j == n // 2 and i >= n // 2
                if a or b or c:
                    cnt1[x] += 1
                else:
                    cnt2[x] += 1
        return min(
            n * n - cnt1[i] - cnt2[j] for i in range(3) for j in range(3) if i != j
        )
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumOperationsToWriteY(int[][] grid) {
        int n = grid.length;
        int[] cnt1 = new int[3];
        int[] cnt2 = new int[3];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                boolean a = i == j && i <= n / 2;
                boolean b = i + j == n - 1 && i <= n / 2;
                boolean c = j == n / 2 && i >= n / 2;
                if (a || b || c) {
                    ++cnt1[grid[i][j]];
                } else {
                    ++cnt2[grid[i][j]];
                }
            }
        }
        int ans = n * n;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (i != j) {
                    ans = Math.min(ans, n * n - cnt1[i] - cnt2[j]);
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
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        int n = grid.size();
        int cnt1[3]{};
        int cnt2[3]{};
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                bool a = i == j && i <= n / 2;
                bool b = i + j == n - 1 && i <= n / 2;
                bool c = j == n / 2 && i >= n / 2;
                if (a || b || c) {
                    ++cnt1[grid[i][j]];
                } else {
                    ++cnt2[grid[i][j]];
                }
            }
        }
        int ans = n * n;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (i != j) {
                    ans = min(ans, n * n - cnt1[i] - cnt2[j]);
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
func minimumOperationsToWriteY(grid [][]int) int {
	n := len(grid)
	cnt1 := [3]int{}
	cnt2 := [3]int{}
	for i, row := range grid {
		for j, x := range row {
			a := i == j && i <= n/2
			b := i+j == n-1 && i <= n/2
			c := j == n/2 && i >= n/2
			if a || b || c {
				cnt1[x]++
			} else {
				cnt2[x]++
			}
		}
	}
	ans := n * n
	for i := 0; i < 3; i++ {
		for j := 0; j < 3; j++ {
			if i != j {
				ans = min(ans, n*n-cnt1[i]-cnt2[j])
			}
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumOperationsToWriteY(grid: number[][]): number {
    const n = grid.length;
    const cnt1: number[] = Array(3).fill(0);
    const cnt2: number[] = Array(3).fill(0);
    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < n; ++j) {
            const a = i === j && i <= n >> 1;
            const b = i + j === n - 1 && i <= n >> 1;
            const c = j === n >> 1 && i >= n >> 1;
            if (a || b || c) {
                ++cnt1[grid[i][j]];
            } else {
                ++cnt2[grid[i][j]];
            }
        }
    }
    let ans = n * n;
    for (let i = 0; i < 3; ++i) {
        for (let j = 0; j < 3; ++j) {
            if (i !== j) {
                ans = Math.min(ans, n * n - cnt1[i] - cnt2[j]);
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

<p>给你一个下标从 <strong>0</strong> 开始、大小为 <code>n x n</code> 的矩阵 <code>grid</code> ，其中 <code>n</code> 为奇数，且 <code>grid[r][c]</code> 的值为 <code>0</code> 、<code>1</code> 或 <code>2</code> 。</p>

<p>如果一个单元格属于以下三条线中的任一一条，我们就认为它是字母 <strong>Y</strong> 的一部分：</p>

<ul>
	<li>从左上角单元格开始到矩阵中心单元格结束的对角线。</li>
	<li>从右上角单元格开始到矩阵中心单元格结束的对角线。</li>
	<li>从中心单元格开始到矩阵底部边界结束的垂直线。</li>
</ul>

<p>当且仅当满足以下全部条件时，可以判定矩阵上写有字母 <strong>Y </strong>：</p>

<ul>
	<li>属于 Y 的所有单元格的值相等。</li>
	<li>不属于 Y 的所有单元格的值相等。</li>
	<li>属于 Y 的单元格的值与不属于Y的单元格的值不同。</li>
</ul>

<p>每次操作你可以将任意单元格的值改变为 <code>0</code> 、<code>1</code> 或 <code>2</code> 。返回在矩阵上写出字母 Y 所需的 <strong>最少 </strong>操作次数。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3000-3099/3071.Minimum%20Operations%20to%20Write%20the%20Letter%20Y%20on%20a%20Grid/images/y2.png" style="width: 461px; height: 121px;" />
<pre>
<strong>输入：</strong>grid = [[1,2,2],[1,1,0],[0,1,0]]
<strong>输出：</strong>3
<strong>解释：</strong>将在矩阵上写出字母 Y 需要执行的操作用蓝色高亮显示。操作后，所有属于 Y 的单元格（加粗显示）的值都为 1 ，而不属于 Y 的单元格的值都为 0 。
可以证明，写出 Y 至少需要进行 3 次操作。
</pre>

<p><strong class="example">示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3000-3099/3071.Minimum%20Operations%20to%20Write%20the%20Letter%20Y%20on%20a%20Grid/images/y3.png" style="width: 701px; height: 201px;" />
<pre>
<strong>输入：</strong>grid = [[0,1,0,1,0],[2,1,0,1,2],[2,2,2,0,1],[2,2,2,2,2],[2,1,2,2,2]]
<strong>输出：</strong>12
<strong>解释：</strong>将在矩阵上写出字母 Y 需要执行的操作用蓝色高亮显示。操作后，所有属于 Y 的单元格（加粗显示）的值都为 0 ，而不属于 Y 的单元格的值都为 2 。
可以证明，写出 Y 至少需要进行 12 次操作。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= n &lt;= 49</code></li>
	<li><code>n == grid.length == grid[i].length</code></li>
	<li><code>0 &lt;= grid[i][j] &lt;= 2</code></li>
	<li><code>n</code> 为奇数。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数

我们用两个长度为 $3$ 的数组 `cnt1` 和 `cnt2` 分别记录属于 `Y` 的单元格和不属于 `Y` 的单元格的值的个数。然后我们枚举 `i` 和 `j`，分别表示属于 `Y` 的单元格和不属于 `Y` 的单元格的值，计算出最少操作次数。

时间复杂度 $O(n^2)$，其中 $n$ 是矩阵的大小。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumOperationsToWriteY(self, grid: List[List[int]]) -> int:
        n = len(grid)
        cnt1 = Counter()
        cnt2 = Counter()
        for i, row in enumerate(grid):
            for j, x in enumerate(row):
                a = i == j and i <= n // 2
                b = i + j == n - 1 and i <= n // 2
                c = j == n // 2 and i >= n // 2
                if a or b or c:
                    cnt1[x] += 1
                else:
                    cnt2[x] += 1
        return min(
            n * n - cnt1[i] - cnt2[j] for i in range(3) for j in range(3) if i != j
        )
```

#### Java

```java
class Solution {
    public int minimumOperationsToWriteY(int[][] grid) {
        int n = grid.length;
        int[] cnt1 = new int[3];
        int[] cnt2 = new int[3];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                boolean a = i == j && i <= n / 2;
                boolean b = i + j == n - 1 && i <= n / 2;
                boolean c = j == n / 2 && i >= n / 2;
                if (a || b || c) {
                    ++cnt1[grid[i][j]];
                } else {
                    ++cnt2[grid[i][j]];
                }
            }
        }
        int ans = n * n;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (i != j) {
                    ans = Math.min(ans, n * n - cnt1[i] - cnt2[j]);
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
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        int n = grid.size();
        int cnt1[3]{};
        int cnt2[3]{};
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                bool a = i == j && i <= n / 2;
                bool b = i + j == n - 1 && i <= n / 2;
                bool c = j == n / 2 && i >= n / 2;
                if (a || b || c) {
                    ++cnt1[grid[i][j]];
                } else {
                    ++cnt2[grid[i][j]];
                }
            }
        }
        int ans = n * n;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (i != j) {
                    ans = min(ans, n * n - cnt1[i] - cnt2[j]);
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func minimumOperationsToWriteY(grid [][]int) int {
	n := len(grid)
	cnt1 := [3]int{}
	cnt2 := [3]int{}
	for i, row := range grid {
		for j, x := range row {
			a := i == j && i <= n/2
			b := i+j == n-1 && i <= n/2
			c := j == n/2 && i >= n/2
			if a || b || c {
				cnt1[x]++
			} else {
				cnt2[x]++
			}
		}
	}
	ans := n * n
	for i := 0; i < 3; i++ {
		for j := 0; j < 3; j++ {
			if i != j {
				ans = min(ans, n*n-cnt1[i]-cnt2[j])
			}
		}
	}
	return ans
}
```

#### TypeScript

```ts
function minimumOperationsToWriteY(grid: number[][]): number {
    const n = grid.length;
    const cnt1: number[] = Array(3).fill(0);
    const cnt2: number[] = Array(3).fill(0);
    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < n; ++j) {
            const a = i === j && i <= n >> 1;
            const b = i + j === n - 1 && i <= n >> 1;
            const c = j === n >> 1 && i >= n >> 1;
            if (a || b || c) {
                ++cnt1[grid[i][j]];
            } else {
                ++cnt2[grid[i][j]];
            }
        }
    }
    let ans = n * n;
    for (let i = 0; i < 3; ++i) {
        for (let j = 0; j < 3; ++j) {
            if (i !== j) {
                ans = Math.min(ans, n * n - cnt1[i] - cnt2[j]);
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

# [3072. 将元素分配到两个数组中 II](https://leetcode.cn/problems/distribute-elements-into-two-arrays-ii){#3072}

{{< tabs "3072" >}}

{{% tab "python" %}}
```python
class Solution:
    def resultArray(self, nums: List[int]) -> List[int]:
        arr1 = [nums[0]]
        arr2 = [nums[1]]
        sl1 = SortedList(arr1)
        sl2 = SortedList(arr2)
        for x in nums[2:]:
            i = sl1.bisect_right(x)
            j = sl2.bisect_right(x)
            if len(sl1) - i > len(sl2) - j:
                arr1.append(x)
                sl1.add(x)
            elif len(sl1) - i < len(sl2) - j:
                arr2.append(x)
                sl2.add(x)
            elif len(sl1) <= len(sl2):
                arr1.append(x)
                sl1.add(x)
            else:
                arr2.append(x)
                sl2.add(x)
        return arr1 + arr2
```
{{% /tab %}}
{{% tab "java" %}}
```java
class BinaryIndexedTree {
    private int n;
    private int[] c;

    public BinaryIndexedTree(int n) {
        this.n = n;
        this.c = new int[n + 1];
    }

    public void update(int x, int delta) {
        for (; x <= n; x += x & -x) {
            c[x] += delta;
        }
    }

    public int query(int x) {
        int s = 0;
        for (; x > 0; x -= x & -x) {
            s += c[x];
        }
        return s;
    }
}

class Solution {
    public int[] resultArray(int[] nums) {
        int[] st = nums.clone();
        Arrays.sort(st);
        int n = st.length;
        BinaryIndexedTree tree1 = new BinaryIndexedTree(n + 1);
        BinaryIndexedTree tree2 = new BinaryIndexedTree(n + 1);
        tree1.update(Arrays.binarySearch(st, nums[0]) + 1, 1);
        tree2.update(Arrays.binarySearch(st, nums[1]) + 1, 1);
        int[] arr1 = new int[n];
        int[] arr2 = new int[n];
        arr1[0] = nums[0];
        arr2[0] = nums[1];
        int i = 1, j = 1;
        for (int k = 2; k < n; ++k) {
            int x = Arrays.binarySearch(st, nums[k]) + 1;
            int a = i - tree1.query(x);
            int b = j - tree2.query(x);
            if (a > b) {
                arr1[i++] = nums[k];
                tree1.update(x, 1);
            } else if (a < b) {
                arr2[j++] = nums[k];
                tree2.update(x, 1);
            } else if (i <= j) {
                arr1[i++] = nums[k];
                tree1.update(x, 1);
            } else {
                arr2[j++] = nums[k];
                tree2.update(x, 1);
            }
        }
        for (int k = 0; k < j; ++k) {
            arr1[i++] = arr2[k];
        }
        return arr1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class BinaryIndexedTree {
private:
    int n;
    vector<int> c;

public:
    BinaryIndexedTree(int n)
        : n(n)
        , c(n + 1) {}

    void update(int x, int delta) {
        for (; x <= n; x += x & -x) {
            c[x] += delta;
        }
    }

    int query(int x) {
        int s = 0;
        for (; x > 0; x -= x & -x) {
            s += c[x];
        }
        return s;
    }
};

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> st = nums;
        sort(st.begin(), st.end());
        int n = st.size();
        BinaryIndexedTree tree1(n + 1);
        BinaryIndexedTree tree2(n + 1);
        tree1.update(distance(st.begin(), lower_bound(st.begin(), st.end(), nums[0])) + 1, 1);
        tree2.update(distance(st.begin(), lower_bound(st.begin(), st.end(), nums[1])) + 1, 1);
        vector<int> arr1 = {nums[0]};
        vector<int> arr2 = {nums[1]};
        for (int k = 2; k < n; ++k) {
            int x = distance(st.begin(), lower_bound(st.begin(), st.end(), nums[k])) + 1;
            int a = arr1.size() - tree1.query(x);
            int b = arr2.size() - tree2.query(x);
            if (a > b) {
                arr1.push_back(nums[k]);
                tree1.update(x, 1);
            } else if (a < b) {
                arr2.push_back(nums[k]);
                tree2.update(x, 1);
            } else if (arr1.size() <= arr2.size()) {
                arr1.push_back(nums[k]);
                tree1.update(x, 1);
            } else {
                arr2.push_back(nums[k]);
                tree2.update(x, 1);
            }
        }
        arr1.insert(arr1.end(), arr2.begin(), arr2.end());
        return arr1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
type BinaryIndexedTree struct {
	n int
	c []int
}

func NewBinaryIndexedTree(n int) *BinaryIndexedTree {
	return &BinaryIndexedTree{n: n, c: make([]int, n+1)}
}

func (bit *BinaryIndexedTree) update(x, delta int) {
	for ; x <= bit.n; x += x & -x {
		bit.c[x] += delta
	}
}

func (bit *BinaryIndexedTree) query(x int) int {
	s := 0
	for ; x > 0; x -= x & -x {
		s += bit.c[x]
	}
	return s
}

func resultArray(nums []int) []int {
	st := make([]int, len(nums))
	copy(st, nums)
	sort.Ints(st)
	n := len(st)
	tree1 := NewBinaryIndexedTree(n + 1)
	tree2 := NewBinaryIndexedTree(n + 1)
	tree1.update(sort.SearchInts(st, nums[0])+1, 1)
	tree2.update(sort.SearchInts(st, nums[1])+1, 1)
	arr1 := []int{nums[0]}
	arr2 := []int{nums[1]}
	for _, x := range nums[2:] {
		i := sort.SearchInts(st, x) + 1
		a := len(arr1) - tree1.query(i)
		b := len(arr2) - tree2.query(i)
		if a > b {
			arr1 = append(arr1, x)
			tree1.update(i, 1)
		} else if a < b {
			arr2 = append(arr2, x)
			tree2.update(i, 1)
		} else if len(arr1) <= len(arr2) {
			arr1 = append(arr1, x)
			tree1.update(i, 1)
		} else {
			arr2 = append(arr2, x)
			tree2.update(i, 1)
		}
	}
	arr1 = append(arr1, arr2...)
	return arr1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class BinaryIndexedTree {
    private n: number;
    private c: number[];

    constructor(n: number) {
        this.n = n;
        this.c = Array(n + 1).fill(0);
    }

    update(x: number, delta: number): void {
        for (; x <= this.n; x += x & -x) {
            this.c[x] += delta;
        }
    }

    query(x: number): number {
        let s = 0;
        for (; x > 0; x -= x & -x) {
            s += this.c[x];
        }
        return s;
    }
}

function resultArray(nums: number[]): number[] {
    const st: number[] = nums.slice().sort((a, b) => a - b);
    const n: number = st.length;
    const search = (x: number): number => {
        let [l, r] = [0, n];
        while (l < r) {
            const mid = (l + r) >> 1;
            if (st[mid] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    };
    const tree1: BinaryIndexedTree = new BinaryIndexedTree(n + 1);
    const tree2: BinaryIndexedTree = new BinaryIndexedTree(n + 1);
    tree1.update(search(nums[0]) + 1, 1);
    tree2.update(search(nums[1]) + 1, 1);
    const arr1: number[] = [nums[0]];
    const arr2: number[] = [nums[1]];
    for (const x of nums.slice(2)) {
        const i: number = search(x) + 1;
        const a: number = arr1.length - tree1.query(i);
        const b: number = arr2.length - tree2.query(i);
        if (a > b) {
            arr1.push(x);
            tree1.update(i, 1);
        } else if (a < b) {
            arr2.push(x);
            tree2.update(i, 1);
        } else if (arr1.length <= arr2.length) {
            arr1.push(x);
            tree1.update(i, 1);
        } else {
            arr2.push(x);
            tree2.update(i, 1);
        }
    }
    return arr1.concat(arr2);
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param String $s
     * @param String[] $words
     * @return Integer[]
     */
    function findSubstring($s, $words) {
        $cnt = [];
        foreach ($words as $w) {
            if (!isset($cnt[$w])) {
                $cnt[$w] = 1;
            } else {
                $cnt[$w]++;
            }
        }
        $m = strlen($s);
        $n = count($words);
        $k = strlen($words[0]);
        $ans = [];
        for ($i = 0; $i < $k; ++$i) {
            $cnt1 = [];
            $l = $i;
            $r = $i;
            $t = 0;
            while ($r + $k <= $m) {
                $w = substr($s, $r, $k);
                $r += $k;
                if (!array_key_exists($w, $cnt)) {
                    $cnt1 = [];
                    $l = $r;
                    $t = 0;
                    continue;
                }
                if (!isset($cnt1[$w])) {
                    $cnt1[$w] = 1;
                } else {
                    $cnt1[$w]++;
                }
                ++$t;
                while ($cnt1[$w] > $cnt[$w]) {
                    $remove = substr($s, $l, $k);
                    $l += $k;
                    $cnt1[$remove]--;
                    $t--;
                }
                if ($t == $n) {
                    $ans[] = $l;
                }
            }
        }
        return $ans;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>1</strong> 开始、长度为 <code>n</code> 的整数数组 <code>nums</code> 。</p>

<p>现定义函数 <code>greaterCount</code> ，使得 <code>greaterCount(arr, val)</code> 返回数组 <code>arr</code> 中<strong> 严格大于</strong> <code>val</code> 的元素数量。</p>

<p>你需要使用 <code>n</code> 次操作，将 <code>nums</code> 的所有元素分配到两个数组 <code>arr1</code> 和 <code>arr2</code> 中。在第一次操作中，将 <code>nums[1]</code> 追加到 <code>arr1</code> 。在第二次操作中，将 <code>nums[2]</code> 追加到 <code>arr2</code> 。之后，在第 <code>i</code> 次操作中：</p>

<ul>
	<li>如果 <code>greaterCount(arr1, nums[i]) &gt; greaterCount(arr2, nums[i])</code> ，将 <code>nums[i]</code> 追加到 <code>arr1</code> 。</li>
	<li>如果 <code>greaterCount(arr1, nums[i]) &lt; greaterCount(arr2, nums[i])</code> ，将 <code>nums[i]</code> 追加到 <code>arr2</code> 。</li>
	<li>如果 <code>greaterCount(arr1, nums[i]) == greaterCount(arr2, nums[i])</code> ，将 <code>nums[i]</code> 追加到元素数量较少的数组中。</li>
	<li>如果仍然相等，那么将 <code>nums[i]</code> 追加到 <code>arr1</code> 。</li>
</ul>

<p>连接数组 <code>arr1</code> 和 <code>arr2</code> 形成数组 <code>result</code> 。例如，如果 <code>arr1 == [1,2,3]</code> 且 <code>arr2 == [4,5,6]</code> ，那么 <code>result = [1,2,3,4,5,6]</code> 。</p>

<p>返回整数数组 <code>result</code> 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,1,3,3]
<strong>输出：</strong>[2,3,1,3]
<strong>解释：</strong>在前两次操作后，arr1 = [2] ，arr2 = [1] 。
在第 3 次操作中，两个数组中大于 3 的元素数量都是零，并且长度相等，因此，将 nums[3] 追加到 arr1 。
在第 4 次操作中，两个数组中大于 3 的元素数量都是零，但 arr2 的长度较小，因此，将 nums[4] 追加到 arr2 。
在 4 次操作后，arr1 = [2,3] ，arr2 = [1,3] 。
因此，连接形成的数组 result 是 [2,3,1,3] 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [5,14,3,1,2]
<strong>输出：</strong>[5,3,1,2,14]
<strong>解释：</strong>在前两次操作后，arr1 = [5] ，arr2 = [14] 。
在第 3 次操作中，两个数组中大于 3 的元素数量都是一，并且长度相等，因此，将 nums[3] 追加到 arr1 。
在第 4 次操作中，arr1 中大于 1 的元素数量大于 arr2 中的数量（2 &gt; 1），因此，将 nums[4] 追加到 arr1 。
在第 5 次操作中，arr1 中大于 2 的元素数量大于 arr2 中的数量（2 &gt; 1），因此，将 nums[5] 追加到 arr1 。
在 5 次操作后，arr1 = [5,3,1,2] ，arr2 = [14] 。
因此，连接形成的数组 result 是 [5,3,1,2,14] 。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [3,3,3,3]
<strong>输出：</strong>[3,3,3,3]
<strong>解释：</strong>在 4 次操作后，arr1 = [3,3] ，arr2 = [3,3] 。
因此，连接形成的数组 result 是 [3,3,3,3] 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：离散化 + 树状数组

我们可以用两个树状数组 `tree1` 和 `tree2` 分别维护 `arr1` 和 `arr2` 中小于等于某个数的元素个数。每一次，我们在树状数组中查询小于等于当前数的元素个数，那么大于当前数的元素个数就是当前数组的长度减去查询的结果。然后我们就可以根据这个差值来决定将当前数加入到哪个数组中。

由于题目中给出的数的范围很大，所以我们需要对这些数进行离散化。我们可以将这些数排序后去重，然后用二分查找来找到每个数在排序后的数组中的位置。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 `nums` 的长度。

<!-- tabs:start -->

#### Python3

```python
class BinaryIndexedTree:
    __slots__ = "n", "c"

    def __init__(self, n: int):
        self.n = n
        self.c = [0] * (n + 1)

    def update(self, x: int, delta: int) -> None:
        while x <= self.n:
            self.c[x] += delta
            x += x & -x

    def query(self, x: int) -> int:
        s = 0
        while x:
            s += self.c[x]
            x -= x & -x
        return s


class Solution:
    def resultArray(self, nums: List[int]) -> List[int]:
        st = sorted(set(nums))
        m = len(st)
        tree1 = BinaryIndexedTree(m + 1)
        tree2 = BinaryIndexedTree(m + 1)
        tree1.update(bisect_left(st, nums[0]) + 1, 1)
        tree2.update(bisect_left(st, nums[1]) + 1, 1)
        arr1 = [nums[0]]
        arr2 = [nums[1]]
        for x in nums[2:]:
            i = bisect_left(st, x) + 1
            a = len(arr1) - tree1.query(i)
            b = len(arr2) - tree2.query(i)
            if a > b:
                arr1.append(x)
                tree1.update(i, 1)
            elif a < b:
                arr2.append(x)
                tree2.update(i, 1)
            elif len(arr1) <= len(arr2):
                arr1.append(x)
                tree1.update(i, 1)
            else:
                arr2.append(x)
                tree2.update(i, 1)
        return arr1 + arr2
```

#### Python3

```python
class Solution:
    def resultArray(self, nums: List[int]) -> List[int]:
        arr1 = [nums[0]]
        arr2 = [nums[1]]
        sl1 = SortedList(arr1)
        sl2 = SortedList(arr2)
        for x in nums[2:]:
            i = sl1.bisect_right(x)
            j = sl2.bisect_right(x)
            if len(sl1) - i > len(sl2) - j:
                arr1.append(x)
                sl1.add(x)
            elif len(sl1) - i < len(sl2) - j:
                arr2.append(x)
                sl2.add(x)
            elif len(sl1) <= len(sl2):
                arr1.append(x)
                sl1.add(x)
            else:
                arr2.append(x)
                sl2.add(x)
        return arr1 + arr2
```

#### Java

```java
class BinaryIndexedTree {
    private int n;
    private int[] c;

    public BinaryIndexedTree(int n) {
        this.n = n;
        this.c = new int[n + 1];
    }

    public void update(int x, int delta) {
        for (; x <= n; x += x & -x) {
            c[x] += delta;
        }
    }

    public int query(int x) {
        int s = 0;
        for (; x > 0; x -= x & -x) {
            s += c[x];
        }
        return s;
    }
}

class Solution {
    public int[] resultArray(int[] nums) {
        int[] st = nums.clone();
        Arrays.sort(st);
        int n = st.length;
        BinaryIndexedTree tree1 = new BinaryIndexedTree(n + 1);
        BinaryIndexedTree tree2 = new BinaryIndexedTree(n + 1);
        tree1.update(Arrays.binarySearch(st, nums[0]) + 1, 1);
        tree2.update(Arrays.binarySearch(st, nums[1]) + 1, 1);
        int[] arr1 = new int[n];
        int[] arr2 = new int[n];
        arr1[0] = nums[0];
        arr2[0] = nums[1];
        int i = 1, j = 1;
        for (int k = 2; k < n; ++k) {
            int x = Arrays.binarySearch(st, nums[k]) + 1;
            int a = i - tree1.query(x);
            int b = j - tree2.query(x);
            if (a > b) {
                arr1[i++] = nums[k];
                tree1.update(x, 1);
            } else if (a < b) {
                arr2[j++] = nums[k];
                tree2.update(x, 1);
            } else if (i <= j) {
                arr1[i++] = nums[k];
                tree1.update(x, 1);
            } else {
                arr2[j++] = nums[k];
                tree2.update(x, 1);
            }
        }
        for (int k = 0; k < j; ++k) {
            arr1[i++] = arr2[k];
        }
        return arr1;
    }
}
```

#### C++

```cpp
class BinaryIndexedTree {
private:
    int n;
    vector<int> c;

public:
    BinaryIndexedTree(int n)
        : n(n)
        , c(n + 1) {}

    void update(int x, int delta) {
        for (; x <= n; x += x & -x) {
            c[x] += delta;
        }
    }

    int query(int x) {
        int s = 0;
        for (; x > 0; x -= x & -x) {
            s += c[x];
        }
        return s;
    }
};

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> st = nums;
        sort(st.begin(), st.end());
        int n = st.size();
        BinaryIndexedTree tree1(n + 1);
        BinaryIndexedTree tree2(n + 1);
        tree1.update(distance(st.begin(), lower_bound(st.begin(), st.end(), nums[0])) + 1, 1);
        tree2.update(distance(st.begin(), lower_bound(st.begin(), st.end(), nums[1])) + 1, 1);
        vector<int> arr1 = {nums[0]};
        vector<int> arr2 = {nums[1]};
        for (int k = 2; k < n; ++k) {
            int x = distance(st.begin(), lower_bound(st.begin(), st.end(), nums[k])) + 1;
            int a = arr1.size() - tree1.query(x);
            int b = arr2.size() - tree2.query(x);
            if (a > b) {
                arr1.push_back(nums[k]);
                tree1.update(x, 1);
            } else if (a < b) {
                arr2.push_back(nums[k]);
                tree2.update(x, 1);
            } else if (arr1.size() <= arr2.size()) {
                arr1.push_back(nums[k]);
                tree1.update(x, 1);
            } else {
                arr2.push_back(nums[k]);
                tree2.update(x, 1);
            }
        }
        arr1.insert(arr1.end(), arr2.begin(), arr2.end());
        return arr1;
    }
};
```

#### Go

```go
type BinaryIndexedTree struct {
	n int
	c []int
}

func NewBinaryIndexedTree(n int) *BinaryIndexedTree {
	return &BinaryIndexedTree{n: n, c: make([]int, n+1)}
}

func (bit *BinaryIndexedTree) update(x, delta int) {
	for ; x <= bit.n; x += x & -x {
		bit.c[x] += delta
	}
}

func (bit *BinaryIndexedTree) query(x int) int {
	s := 0
	for ; x > 0; x -= x & -x {
		s += bit.c[x]
	}
	return s
}

func resultArray(nums []int) []int {
	st := make([]int, len(nums))
	copy(st, nums)
	sort.Ints(st)
	n := len(st)
	tree1 := NewBinaryIndexedTree(n + 1)
	tree2 := NewBinaryIndexedTree(n + 1)
	tree1.update(sort.SearchInts(st, nums[0])+1, 1)
	tree2.update(sort.SearchInts(st, nums[1])+1, 1)
	arr1 := []int{nums[0]}
	arr2 := []int{nums[1]}
	for _, x := range nums[2:] {
		i := sort.SearchInts(st, x) + 1
		a := len(arr1) - tree1.query(i)
		b := len(arr2) - tree2.query(i)
		if a > b {
			arr1 = append(arr1, x)
			tree1.update(i, 1)
		} else if a < b {
			arr2 = append(arr2, x)
			tree2.update(i, 1)
		} else if len(arr1) <= len(arr2) {
			arr1 = append(arr1, x)
			tree1.update(i, 1)
		} else {
			arr2 = append(arr2, x)
			tree2.update(i, 1)
		}
	}
	arr1 = append(arr1, arr2...)
	return arr1
}
```

#### TypeScript

```ts
class BinaryIndexedTree {
    private n: number;
    private c: number[];

    constructor(n: number) {
        this.n = n;
        this.c = Array(n + 1).fill(0);
    }

    update(x: number, delta: number): void {
        for (; x <= this.n; x += x & -x) {
            this.c[x] += delta;
        }
    }

    query(x: number): number {
        let s = 0;
        for (; x > 0; x -= x & -x) {
            s += this.c[x];
        }
        return s;
    }
}

function resultArray(nums: number[]): number[] {
    const st: number[] = nums.slice().sort((a, b) => a - b);
    const n: number = st.length;
    const search = (x: number): number => {
        let [l, r] = [0, n];
        while (l < r) {
            const mid = (l + r) >> 1;
            if (st[mid] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    };
    const tree1: BinaryIndexedTree = new BinaryIndexedTree(n + 1);
    const tree2: BinaryIndexedTree = new BinaryIndexedTree(n + 1);
    tree1.update(search(nums[0]) + 1, 1);
    tree2.update(search(nums[1]) + 1, 1);
    const arr1: number[] = [nums[0]];
    const arr2: number[] = [nums[1]];
    for (const x of nums.slice(2)) {
        const i: number = search(x) + 1;
        const a: number = arr1.length - tree1.query(i);
        const b: number = arr2.length - tree2.query(i);
        if (a > b) {
            arr1.push(x);
            tree1.update(i, 1);
        } else if (a < b) {
            arr2.push(x);
            tree2.update(i, 1);
        } else if (arr1.length <= arr2.length) {
            arr1.push(x);
            tree1.update(i, 1);
        } else {
            arr2.push(x);
            tree2.update(i, 1);
        }
    }
    return arr1.concat(arr2);
}
```

#### PHP

```php
class Solution {
    /**
     * @param String $s
     * @param String[] $words
     * @return Integer[]
     */
    function findSubstring($s, $words) {
        $cnt = [];
        foreach ($words as $w) {
            if (!isset($cnt[$w])) {
                $cnt[$w] = 1;
            } else {
                $cnt[$w]++;
            }
        }
        $m = strlen($s);
        $n = count($words);
        $k = strlen($words[0]);
        $ans = [];
        for ($i = 0; $i < $k; ++$i) {
            $cnt1 = [];
            $l = $i;
            $r = $i;
            $t = 0;
            while ($r + $k <= $m) {
                $w = substr($s, $r, $k);
                $r += $k;
                if (!array_key_exists($w, $cnt)) {
                    $cnt1 = [];
                    $l = $r;
                    $t = 0;
                    continue;
                }
                if (!isset($cnt1[$w])) {
                    $cnt1[$w] = 1;
                } else {
                    $cnt1[$w]++;
                }
                ++$t;
                while ($cnt1[$w] > $cnt[$w]) {
                    $remove = substr($s, $l, $k);
                    $l += $k;
                    $cnt1[$remove]--;
                    $t--;
                }
                if ($t == $n) {
                    $ans[] = $l;
                }
            }
        }
        return $ans;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3073. 最大递增三元组 🔒](https://leetcode.cn/problems/maximum-increasing-triplet-value){#3073}

{{< tabs "3073" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumTripletValue(self, nums: List[int]) -> int:
        n = len(nums)
        right = [nums[-1]] * n
        for i in range(n - 2, -1, -1):
            right[i] = max(nums[i], right[i + 1])
        sl = SortedList([nums[0]])
        ans = 0
        for j in range(1, n - 1):
            if right[j + 1] > nums[j]:
                i = sl.bisect_left(nums[j]) - 1
                if i >= 0:
                    ans = max(ans, sl[i] - nums[j] + right[j + 1])
            sl.add(nums[j])
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maximumTripletValue(int[] nums) {
        int n = nums.length;
        int[] right = new int[n];
        right[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            right[i] = Math.max(nums[i], right[i + 1]);
        }
        TreeSet<Integer> ts = new TreeSet<>();
        ts.add(nums[0]);
        int ans = 0;
        for (int j = 1; j < n - 1; ++j) {
            if (right[j + 1] > nums[j]) {
                Integer it = ts.lower(nums[j]);
                if (it != null) {
                    ans = Math.max(ans, it - nums[j] + right[j + 1]);
                }
            }
            ts.add(nums[j]);
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
    int maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> right(n, nums.back());
        for (int i = n - 2; ~i; --i) {
            right[i] = max(nums[i], right[i + 1]);
        }
        set<int> ts;
        ts.insert(nums[0]);
        int ans = 0;
        for (int j = 1; j < n - 1; ++j) {
            if (right[j + 1] > nums[j]) {
                auto it = ts.lower_bound(nums[j]);
                if (it != ts.begin()) {
                    --it;
                    ans = max(ans, *it - nums[j] + right[j + 1]);
                }
            }
            ts.insert(nums[j]);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumTripletValue(nums []int) (ans int) {
	n := len(nums)
	right := make([]int, n)
	right[n-1] = nums[n-1]
	for i := n - 2; i >= 0; i-- {
		right[i] = max(nums[i], right[i+1])
	}
	ts := treemap.NewWithIntComparator()
	ts.Put(nums[0], nil)
	for j := 1; j < n-1; j++ {
		if right[j+1] > nums[j] {
			val, _ := ts.Floor(nums[j] - 1)
			if val != nil {
				ans = max(ans, val.(int)-nums[j]+right[j+1])
			}
		}
		ts.Put(nums[j], nil)
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumTripletValue(nums: number[]): number {
    const n = nums.length;
    const right: number[] = Array(n).fill(nums[n - 1]);
    for (let i = n - 2; ~i; --i) {
        right[i] = Math.max(nums[i], right[i + 1]);
    }
    const ts = new TreeSet<number>();
    ts.add(nums[0]);
    let ans = 0;
    for (let j = 1; j < n - 1; ++j) {
        if (right[j + 1] > nums[j]) {
            const val = ts.lower(nums[j]);
            if (val !== undefined) {
                ans = Math.max(ans, val - nums[j] + right[j + 1]);
            }
        }
        ts.add(nums[j]);
    }
    return ans;
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

class TreeSet<T = number> {
    _size: number;
    tree: RBTree<T>;
    compare: Compare<T>;
    constructor(
        collection: T[] | Compare<T> = [],
        compare: Compare<T> = (l: T, r: T) => (l < r ? -1 : l > r ? 1 : 0),
    ) {
        if (typeof collection === 'function') {
            compare = collection;
            collection = [];
        }
        this._size = 0;
        this.compare = compare;
        this.tree = new RBTree(compare);
        for (const val of collection) this.add(val);
    }

    size(): number {
        return this._size;
    }

    has(val: T): boolean {
        return !!this.tree.find(val);
    }

    add(val: T): boolean {
        const successful = this.tree.insert(val);
        this._size += successful ? 1 : 0;
        return successful;
    }

    delete(val: T): boolean {
        const deleted = this.tree.deleteAll(val);
        this._size -= deleted ? 1 : 0;
        return deleted;
    }

    ceil(val: T): T | undefined {
        let p = this.tree.root;
        let higher = null;
        while (p) {
            if (this.compare(p.data, val) >= 0) {
                higher = p;
                p = p.left;
            } else {
                p = p.right;
            }
        }
        return higher?.data;
    }

    floor(val: T): T | undefined {
        let p = this.tree.root;
        let lower = null;
        while (p) {
            if (this.compare(val, p.data) >= 0) {
                lower = p;
                p = p.right;
            } else {
                p = p.left;
            }
        }
        return lower?.data;
    }

    higher(val: T): T | undefined {
        let p = this.tree.root;
        let higher = null;
        while (p) {
            if (this.compare(val, p.data) < 0) {
                higher = p;
                p = p.left;
            } else {
                p = p.right;
            }
        }
        return higher?.data;
    }

    lower(val: T): T | undefined {
        let p = this.tree.root;
        let lower = null;
        while (p) {
            if (this.compare(p.data, val) < 0) {
                lower = p;
                p = p.right;
            } else {
                p = p.left;
            }
        }
        return lower?.data;
    }

    first(): T | undefined {
        return this.tree.inOrder().next().value;
    }

    last(): T | undefined {
        return this.tree.reverseInOrder().next().value;
    }

    shift(): T | undefined {
        const first = this.first();
        if (first === undefined) return undefined;
        this.delete(first);
        return first;
    }

    pop(): T | undefined {
        const last = this.last();
        if (last === undefined) return undefined;
        this.delete(last);
        return last;
    }

    *[Symbol.iterator](): Generator<T, void, void> {
        for (const val of this.values()) yield val;
    }

    *keys(): Generator<T, void, void> {
        for (const val of this.values()) yield val;
    }

    *values(): Generator<T, undefined, void> {
        for (const val of this.tree.inOrder()) yield val;
        return undefined;
    }

    /**
     * Return a generator for reverse order traversing the set
     */
    *rvalues(): Generator<T, undefined, void> {
        for (const val of this.tree.reverseInOrder()) yield val;
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

<p>给定一个数组&nbsp;<code>nums</code>，返回满足 <code>i &lt; j &lt; k</code> 且 <code>nums[i] &lt; nums[j] &lt; nums[k]</code>&nbsp;的三元组 <code>(i, j, k)</code> <em>&nbsp;</em>的 <strong>最大值</strong><i>。</i></p>

<p>三元组&nbsp;<code>(i, j, k)</code> &nbsp;的&nbsp;<strong>值&nbsp;</strong>为&nbsp;<code>nums[i] - nums[j] + nums[k]</code>。</p>

<div id="gtx-trans" style="position: absolute; left: 274px; top: 102px;">
<div class="gtx-trans-icon">&nbsp;</div>
</div>

<p>&nbsp;</p>

<p><strong class="example">示例 1: </strong></p>

<pre>
输入：nums = [5,6,9]
输出：8
解释：对于一个递增的三元组，我们只有一个选择，那就是选择所有三个元素。三元组的值为 5 - 6 + 9 = 8。
</pre>

<p><strong class="example">示例 2: </strong></p>

<pre>
输入：nums = [1,5,3,6]
输出：4
解释：只有两个递增三元组：
(0, 1, 3)：这个三元组的值为 nums[0] - nums[1] + nums[3] = 1 - 5 + 6 = 2。
(0, 2, 3)：这个三元组的值为 nums[0] - nums[2] + nums[3] = 1 - 3 + 6 = 4。
因此答案是 4。
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>3 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li>输入数据保证至少一个三元组满足给定条件。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：后缀最大值 + 有序集合

我们不妨考虑枚举 $nums[j]$，那么我们需要在 $j$ 的左侧找到一个最大的 $nums[i]$，使得 $nums[i] < nums[j]$，并且在 $j$ 的右侧找到一个最大的 $nums[k]$，使得 $nums[k] > nums[j]$。

因此，我们可以预处理出数组 $right$，其中 $right[i]$ 表示 $nums[i]$ 右侧的最大值。然后我们可以使用有序集合来维护 $nums[j]$ 左侧的值，这样我们就可以在 $O(\log n)$ 的时间内找到最大的小于 $nums[j]$ 的 $nums[i]$。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumTripletValue(self, nums: List[int]) -> int:
        n = len(nums)
        right = [nums[-1]] * n
        for i in range(n - 2, -1, -1):
            right[i] = max(nums[i], right[i + 1])
        sl = SortedList([nums[0]])
        ans = 0
        for j in range(1, n - 1):
            if right[j + 1] > nums[j]:
                i = sl.bisect_left(nums[j]) - 1
                if i >= 0:
                    ans = max(ans, sl[i] - nums[j] + right[j + 1])
            sl.add(nums[j])
        return ans
```

#### Java

```java
class Solution {
    public int maximumTripletValue(int[] nums) {
        int n = nums.length;
        int[] right = new int[n];
        right[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            right[i] = Math.max(nums[i], right[i + 1]);
        }
        TreeSet<Integer> ts = new TreeSet<>();
        ts.add(nums[0]);
        int ans = 0;
        for (int j = 1; j < n - 1; ++j) {
            if (right[j + 1] > nums[j]) {
                Integer it = ts.lower(nums[j]);
                if (it != null) {
                    ans = Math.max(ans, it - nums[j] + right[j + 1]);
                }
            }
            ts.add(nums[j]);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> right(n, nums.back());
        for (int i = n - 2; ~i; --i) {
            right[i] = max(nums[i], right[i + 1]);
        }
        set<int> ts;
        ts.insert(nums[0]);
        int ans = 0;
        for (int j = 1; j < n - 1; ++j) {
            if (right[j + 1] > nums[j]) {
                auto it = ts.lower_bound(nums[j]);
                if (it != ts.begin()) {
                    --it;
                    ans = max(ans, *it - nums[j] + right[j + 1]);
                }
            }
            ts.insert(nums[j]);
        }
        return ans;
    }
};
```

#### Go

```go
func maximumTripletValue(nums []int) (ans int) {
	n := len(nums)
	right := make([]int, n)
	right[n-1] = nums[n-1]
	for i := n - 2; i >= 0; i-- {
		right[i] = max(nums[i], right[i+1])
	}
	ts := treemap.NewWithIntComparator()
	ts.Put(nums[0], nil)
	for j := 1; j < n-1; j++ {
		if right[j+1] > nums[j] {
			val, _ := ts.Floor(nums[j] - 1)
			if val != nil {
				ans = max(ans, val.(int)-nums[j]+right[j+1])
			}
		}
		ts.Put(nums[j], nil)
	}
	return
}
```

#### TypeScript

```ts
function maximumTripletValue(nums: number[]): number {
    const n = nums.length;
    const right: number[] = Array(n).fill(nums[n - 1]);
    for (let i = n - 2; ~i; --i) {
        right[i] = Math.max(nums[i], right[i + 1]);
    }
    const ts = new TreeSet<number>();
    ts.add(nums[0]);
    let ans = 0;
    for (let j = 1; j < n - 1; ++j) {
        if (right[j + 1] > nums[j]) {
            const val = ts.lower(nums[j]);
            if (val !== undefined) {
                ans = Math.max(ans, val - nums[j] + right[j + 1]);
            }
        }
        ts.add(nums[j]);
    }
    return ans;
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

class TreeSet<T = number> {
    _size: number;
    tree: RBTree<T>;
    compare: Compare<T>;
    constructor(
        collection: T[] | Compare<T> = [],
        compare: Compare<T> = (l: T, r: T) => (l < r ? -1 : l > r ? 1 : 0),
    ) {
        if (typeof collection === 'function') {
            compare = collection;
            collection = [];
        }
        this._size = 0;
        this.compare = compare;
        this.tree = new RBTree(compare);
        for (const val of collection) this.add(val);
    }

    size(): number {
        return this._size;
    }

    has(val: T): boolean {
        return !!this.tree.find(val);
    }

    add(val: T): boolean {
        const successful = this.tree.insert(val);
        this._size += successful ? 1 : 0;
        return successful;
    }

    delete(val: T): boolean {
        const deleted = this.tree.deleteAll(val);
        this._size -= deleted ? 1 : 0;
        return deleted;
    }

    ceil(val: T): T | undefined {
        let p = this.tree.root;
        let higher = null;
        while (p) {
            if (this.compare(p.data, val) >= 0) {
                higher = p;
                p = p.left;
            } else {
                p = p.right;
            }
        }
        return higher?.data;
    }

    floor(val: T): T | undefined {
        let p = this.tree.root;
        let lower = null;
        while (p) {
            if (this.compare(val, p.data) >= 0) {
                lower = p;
                p = p.right;
            } else {
                p = p.left;
            }
        }
        return lower?.data;
    }

    higher(val: T): T | undefined {
        let p = this.tree.root;
        let higher = null;
        while (p) {
            if (this.compare(val, p.data) < 0) {
                higher = p;
                p = p.left;
            } else {
                p = p.right;
            }
        }
        return higher?.data;
    }

    lower(val: T): T | undefined {
        let p = this.tree.root;
        let lower = null;
        while (p) {
            if (this.compare(p.data, val) < 0) {
                lower = p;
                p = p.right;
            } else {
                p = p.left;
            }
        }
        return lower?.data;
    }

    first(): T | undefined {
        return this.tree.inOrder().next().value;
    }

    last(): T | undefined {
        return this.tree.reverseInOrder().next().value;
    }

    shift(): T | undefined {
        const first = this.first();
        if (first === undefined) return undefined;
        this.delete(first);
        return first;
    }

    pop(): T | undefined {
        const last = this.last();
        if (last === undefined) return undefined;
        this.delete(last);
        return last;
    }

    *[Symbol.iterator](): Generator<T, void, void> {
        for (const val of this.values()) yield val;
    }

    *keys(): Generator<T, void, void> {
        for (const val of this.values()) yield val;
    }

    *values(): Generator<T, undefined, void> {
        for (const val of this.tree.inOrder()) yield val;
        return undefined;
    }

    /**
     * Return a generator for reverse order traversing the set
     */
    *rvalues(): Generator<T, undefined, void> {
        for (const val of this.tree.reverseInOrder()) yield val;
        return undefined;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3074. 重新分装苹果](https://leetcode.cn/problems/apple-redistribution-into-boxes){#3074}

{{< tabs "3074" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumBoxes(self, apple: List[int], capacity: List[int]) -> int:
        capacity.sort(reverse=True)
        s = sum(apple)
        for i, c in enumerate(capacity, 1):
            s -= c
            if s <= 0:
                return i
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumBoxes(int[] apple, int[] capacity) {
        Arrays.sort(capacity);
        int s = 0;
        for (int x : apple) {
            s += x;
        }
        for (int i = 1, n = capacity.length;; ++i) {
            s -= capacity[n - i];
            if (s <= 0) {
                return i;
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
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.rbegin(), capacity.rend());
        int s = accumulate(apple.begin(), apple.end(), 0);
        for (int i = 1;; ++i) {
            s -= capacity[i - 1];
            if (s <= 0) {
                return i;
            }
        }
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumBoxes(apple []int, capacity []int) int {
	sort.Ints(capacity)
	s := 0
	for _, x := range apple {
		s += x
	}
	for i := 1; ; i++ {
		s -= capacity[len(capacity)-i]
		if s <= 0 {
			return i
		}
	}
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumBoxes(apple: number[], capacity: number[]): number {
    capacity.sort((a, b) => b - a);
    let s = apple.reduce((acc, cur) => acc + cur, 0);
    for (let i = 1; ; ++i) {
        s -= capacity[i - 1];
        if (s <= 0) {
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

<p>给你一个长度为 <code>n</code> 的数组 <code>apple</code> 和另一个长度为 <code>m</code> 的数组 <code>capacity</code> 。</p>

<p>一共有 <code>n</code> 个包裹，其中第 <code>i</code> 个包裹中装着 <code>apple[i]</code> 个苹果。同时，还有 <code>m</code> 个箱子，第 <code>i</code> 个箱子的容量为 <code>capacity[i]</code> 个苹果。</p>

<p>请你选择一些箱子来将这 <code>n</code> 个包裹中的苹果重新分装到箱子中，返回你需要选择的箱子的<strong> 最小</strong> 数量。</p>

<p><strong>注意</strong>，同一个包裹中的苹果可以分装到不同的箱子中。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>apple = [1,3,2], capacity = [4,3,1,5,2]
<strong>输出：</strong>2
<strong>解释：</strong>使用容量为 4 和 5 的箱子。
总容量大于或等于苹果的总数，所以可以完成重新分装。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>apple = [5,5,5], capacity = [2,4,2,7]
<strong>输出：</strong>4
<strong>解释：</strong>需要使用所有箱子。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n == apple.length &lt;= 50</code></li>
	<li><code>1 &lt;= m == capacity.length &lt;= 50</code></li>
	<li><code>1 &lt;= apple[i], capacity[i] &lt;= 50</code></li>
	<li>输入数据保证可以将包裹中的苹果重新分装到箱子中。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 排序

为了使得需要的箱子数量尽可能少，我们应该优先使用容量大的箱子。因此，我们可以对箱子按照容量从大到小排序，然后依次使用箱子，直到所有的苹果都被分装完，返回此时使用的箱子数量。

时间复杂度 $O(m \times \log m + n)$，空间复杂度 $O(\log m)$。其中 $m$ 和 $n$ 分别是数组 `capacity` 和 `apple` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumBoxes(self, apple: List[int], capacity: List[int]) -> int:
        capacity.sort(reverse=True)
        s = sum(apple)
        for i, c in enumerate(capacity, 1):
            s -= c
            if s <= 0:
                return i
```

#### Java

```java
class Solution {
    public int minimumBoxes(int[] apple, int[] capacity) {
        Arrays.sort(capacity);
        int s = 0;
        for (int x : apple) {
            s += x;
        }
        for (int i = 1, n = capacity.length;; ++i) {
            s -= capacity[n - i];
            if (s <= 0) {
                return i;
            }
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.rbegin(), capacity.rend());
        int s = accumulate(apple.begin(), apple.end(), 0);
        for (int i = 1;; ++i) {
            s -= capacity[i - 1];
            if (s <= 0) {
                return i;
            }
        }
    }
};
```

#### Go

```go
func minimumBoxes(apple []int, capacity []int) int {
	sort.Ints(capacity)
	s := 0
	for _, x := range apple {
		s += x
	}
	for i := 1; ; i++ {
		s -= capacity[len(capacity)-i]
		if s <= 0 {
			return i
		}
	}
}
```

#### TypeScript

```ts
function minimumBoxes(apple: number[], capacity: number[]): number {
    capacity.sort((a, b) => b - a);
    let s = apple.reduce((acc, cur) => acc + cur, 0);
    for (let i = 1; ; ++i) {
        s -= capacity[i - 1];
        if (s <= 0) {
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

# [3075. 幸福值最大化的选择方案](https://leetcode.cn/problems/maximize-happiness-of-selected-children){#3075}

{{< tabs "3075" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumHappinessSum(self, happiness: List[int], k: int) -> int:
        happiness.sort(reverse=True)
        ans = 0
        for i, x in enumerate(happiness[:k]):
            x -= i
            ans += max(x, 0)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long maximumHappinessSum(int[] happiness, int k) {
        Arrays.sort(happiness);
        long ans = 0;
        for (int i = 0, n = happiness.length; i < k; ++i) {
            int x = happiness[n - i - 1] - i;
            ans += Math.max(x, 0);
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
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.rbegin(), happiness.rend());
        long long ans = 0;
        for (int i = 0, n = happiness.size(); i < k; ++i) {
            int x = happiness[i] - i;
            ans += max(x, 0);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumHappinessSum(happiness []int, k int) (ans int64) {
	sort.Ints(happiness)
	for i := 0; i < k; i++ {
		x := happiness[len(happiness)-i-1] - i
		ans += int64(max(x, 0))
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumHappinessSum(happiness: number[], k: number): number {
    happiness.sort((a, b) => b - a);
    let ans = 0;
    for (let i = 0; i < k; ++i) {
        const x = happiness[i] - i;
        ans += Math.max(x, 0);
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

<p>给你一个长度为 <code>n</code> 的数组 <code>happiness</code> ，以及一个<strong> 正整数 </strong><code>k</code> 。</p>

<p><code>n</code> 个孩子站成一队，其中第 <code>i</code> 个孩子的 <strong>幸福值</strong> 是<strong> </strong><code>happiness[i]</code> 。你计划组织 <code>k</code> 轮筛选从这 <code>n</code> 个孩子中选出 <code>k</code> 个孩子。</p>

<p>在每一轮选择一个孩子时，所有<strong> 尚未 </strong>被选中的孩子的 <strong>幸福值 </strong>将减少 <code>1</code> 。注意，幸福值<strong> 不能 </strong>变成负数，且只有在它是正数的情况下才会减少。</p>

<p>选择 <code>k</code> 个孩子，并使你选中的孩子幸福值之和最大，返回你能够得到的<strong> </strong><strong>最大值</strong> 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>happiness = [1,2,3], k = 2
<strong>输出：</strong>4
<strong>解释：</strong>按以下方式选择 2 个孩子：
- 选择幸福值为 3 的孩子。剩余孩子的幸福值变为 [0,1] 。
- 选择幸福值为 1 的孩子。剩余孩子的幸福值变为 [0] 。注意幸福值不能小于 0 。
所选孩子的幸福值之和为 3 + 1 = 4 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>happiness = [1,1,1,1], k = 2
<strong>输出：</strong>1
<strong>解释：</strong>按以下方式选择 2 个孩子：
- 选择幸福值为 1 的任意一个孩子。剩余孩子的幸福值变为 [0,0,0] 。
- 选择幸福值为 0 的孩子。剩余孩子的幸福值变为 [0,0] 。
所选孩子的幸福值之和为 1 + 0 = 1 。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>happiness = [2,3,4,5], k = 1
<strong>输出：</strong>5
<strong>解释：</strong>按以下方式选择 1 个孩子：
- 选择幸福值为 5 的孩子。剩余孩子的幸福值变为 [1,2,3] 。
所选孩子的幸福值之和为 5 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n == happiness.length &lt;= 2 * 10<sup>5</sup></code></li>
	<li><code>1 &lt;= happiness[i] &lt;= 10<sup>8</sup></code></li>
	<li><code>1 &lt;= k &lt;= n</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 排序

为了使得幸福值之和尽可能大，我们应该优先选择幸福值大的孩子。因此，我们可以对孩子按照幸福值从大到小排序，然后依次选择 $k$ 个孩子。对于当前第 $i$ 个孩子，能够得到的幸福值为 $\max(happiness[i] - i, 0)$，最后返回这 $k$ 个孩子的幸福值之和。

时间复杂度 $O(n \times \log n + k)$，空间复杂度 $O(\log n)$。其中 $n$ 是数组 `happiness` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumHappinessSum(self, happiness: List[int], k: int) -> int:
        happiness.sort(reverse=True)
        ans = 0
        for i, x in enumerate(happiness[:k]):
            x -= i
            ans += max(x, 0)
        return ans
```

#### Java

```java
class Solution {
    public long maximumHappinessSum(int[] happiness, int k) {
        Arrays.sort(happiness);
        long ans = 0;
        for (int i = 0, n = happiness.length; i < k; ++i) {
            int x = happiness[n - i - 1] - i;
            ans += Math.max(x, 0);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.rbegin(), happiness.rend());
        long long ans = 0;
        for (int i = 0, n = happiness.size(); i < k; ++i) {
            int x = happiness[i] - i;
            ans += max(x, 0);
        }
        return ans;
    }
};
```

#### Go

```go
func maximumHappinessSum(happiness []int, k int) (ans int64) {
	sort.Ints(happiness)
	for i := 0; i < k; i++ {
		x := happiness[len(happiness)-i-1] - i
		ans += int64(max(x, 0))
	}
	return
}
```

#### TypeScript

```ts
function maximumHappinessSum(happiness: number[], k: number): number {
    happiness.sort((a, b) => b - a);
    let ans = 0;
    for (let i = 0; i < k; ++i) {
        const x = happiness[i] - i;
        ans += Math.max(x, 0);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3076. 数组中的最短非公共子字符串](https://leetcode.cn/problems/shortest-uncommon-substring-in-an-array){#3076}

{{< tabs "3076" >}}

{{% tab "python" %}}
```python
class Solution:
    def shortestSubstrings(self, arr: List[str]) -> List[str]:
        ans = [""] * len(arr)
        for i, s in enumerate(arr):
            m = len(s)
            for j in range(1, m + 1):
                for l in range(m - j + 1):
                    sub = s[l : l + j]
                    if not ans[i] or ans[i] > sub:
                        if all(k == i or sub not in t for k, t in enumerate(arr)):
                            ans[i] = sub
                if ans[i]:
                    break
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String[] shortestSubstrings(String[] arr) {
        int n = arr.length;
        String[] ans = new String[n];
        Arrays.fill(ans, "");
        for (int i = 0; i < n; ++i) {
            int m = arr[i].length();
            for (int j = 1; j <= m && ans[i].isEmpty(); ++j) {
                for (int l = 0; l <= m - j; ++l) {
                    String sub = arr[i].substring(l, l + j);
                    if (ans[i].isEmpty() || sub.compareTo(ans[i]) < 0) {
                        boolean ok = true;
                        for (int k = 0; k < n && ok; ++k) {
                            if (k != i && arr[k].contains(sub)) {
                                ok = false;
                            }
                        }
                        if (ok) {
                            ans[i] = sub;
                        }
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
    vector<string> shortestSubstrings(vector<string>& arr) {
        int n = arr.size();
        vector<string> ans(n);
        for (int i = 0; i < n; ++i) {
            int m = arr[i].size();
            for (int j = 1; j <= m && ans[i].empty(); ++j) {
                for (int l = 0; l <= m - j; ++l) {
                    string sub = arr[i].substr(l, j);
                    if (ans[i].empty() || sub < ans[i]) {
                        bool ok = true;
                        for (int k = 0; k < n && ok; ++k) {
                            if (k != i && arr[k].find(sub) != string::npos) {
                                ok = false;
                            }
                        }
                        if (ok) {
                            ans[i] = sub;
                        }
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
func shortestSubstrings(arr []string) []string {
	ans := make([]string, len(arr))
	for i, s := range arr {
		m := len(s)
		for j := 1; j <= m && len(ans[i]) == 0; j++ {
			for l := 0; l <= m-j; l++ {
				sub := s[l : l+j]
				if len(ans[i]) == 0 || ans[i] > sub {
					ok := true
					for k, t := range arr {
						if k != i && strings.Contains(t, sub) {
							ok = false
							break
						}
					}
					if ok {
						ans[i] = sub
					}
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
function shortestSubstrings(arr: string[]): string[] {
    const n: number = arr.length;
    const ans: string[] = Array(n).fill('');
    for (let i = 0; i < n; ++i) {
        const m: number = arr[i].length;
        for (let j = 1; j <= m && ans[i] === ''; ++j) {
            for (let l = 0; l <= m - j; ++l) {
                const sub: string = arr[i].slice(l, l + j);
                if (ans[i] === '' || sub.localeCompare(ans[i]) < 0) {
                    let ok: boolean = true;
                    for (let k = 0; k < n && ok; ++k) {
                        if (k !== i && arr[k].includes(sub)) {
                            ok = false;
                        }
                    }
                    if (ok) {
                        ans[i] = sub;
                    }
                }
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

<p>给你一个数组 <code>arr</code>&nbsp;，数组中有 <code>n</code>&nbsp;个 <b>非空</b>&nbsp;字符串。</p>

<p>请你求出一个长度为 <code>n</code>&nbsp;的字符串数组&nbsp;<code>answer</code>&nbsp;，满足：</p>

<ul>
	<li><code>answer[i]</code>&nbsp;是 <code>arr[i]</code>&nbsp;<strong>最短</strong>&nbsp;的子字符串，且它不是 <code>arr</code>&nbsp;中其他任何字符串的子字符串。如果有多个这样的子字符串存在，<code>answer[i]</code>&nbsp;应该是它们中字典序最小的一个。如果不存在这样的子字符串，<code>answer[i]</code>&nbsp;为空字符串。</li>
</ul>

<p>请你返回数组<em>&nbsp;</em><code>answer</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>arr = ["cab","ad","bad","c"]
<b>输出：</b>["ab","","ba",""]
<b>解释：</b>求解过程如下：
- 对于字符串 "cab" ，最短没有在其他字符串中出现过的子字符串是 "ca" 或者 "ab" ，我们选择字典序更小的子字符串，也就是 "ab" 。
- 对于字符串 "ad" ，不存在没有在其他字符串中出现过的子字符串。
- 对于字符串 "bad" ，最短没有在其他字符串中出现过的子字符串是 "ba" 。
- 对于字符串 "c" ，不存在没有在其他字符串中出现过的子字符串。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>arr = ["abc","bcd","abcd"]
<b>输出：</b>["","","abcd"]
<b>解释：</b>求解过程如下：
- 对于字符串 "abc" ，不存在没有在其他字符串中出现过的子字符串。
- 对于字符串 "bcd" ，不存在没有在其他字符串中出现过的子字符串。
- 对于字符串 "abcd" ，最短没有在其他字符串中出现过的子字符串是 "abcd" 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == arr.length</code></li>
	<li><code>2 &lt;= n &lt;= 100</code></li>
	<li><code>1 &lt;= arr[i].length &lt;= 20</code></li>
	<li><code>arr[i]</code>&nbsp;只包含小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举

我们注意到数据规模很小，所以可以直接枚举每个字符串的所有子串，然后判断是否是其他字符串的子串。

具体地，我们先枚举每个字符串 `arr[i]`，然后从小到大枚举每个子串的长度 $j$，然后枚举每个子串的起始位置 $l$，可以得到当前子串为 `sub = arr[i][l:l+j]`，然后判断 `sub` 是否是其他字符串的子串，如果是的话，就跳过当前子串，否则更新答案。

时间复杂度 $O(n^2 \times m^4)$，空间复杂度 $O(m)$。其中 $n$ 是字符串数组 `arr` 的长度，而 $m$ 是字符串的最大长度，本题中 $m \le 20$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def shortestSubstrings(self, arr: List[str]) -> List[str]:
        ans = [""] * len(arr)
        for i, s in enumerate(arr):
            m = len(s)
            for j in range(1, m + 1):
                for l in range(m - j + 1):
                    sub = s[l : l + j]
                    if not ans[i] or ans[i] > sub:
                        if all(k == i or sub not in t for k, t in enumerate(arr)):
                            ans[i] = sub
                if ans[i]:
                    break
        return ans
```

#### Java

```java
class Solution {
    public String[] shortestSubstrings(String[] arr) {
        int n = arr.length;
        String[] ans = new String[n];
        Arrays.fill(ans, "");
        for (int i = 0; i < n; ++i) {
            int m = arr[i].length();
            for (int j = 1; j <= m && ans[i].isEmpty(); ++j) {
                for (int l = 0; l <= m - j; ++l) {
                    String sub = arr[i].substring(l, l + j);
                    if (ans[i].isEmpty() || sub.compareTo(ans[i]) < 0) {
                        boolean ok = true;
                        for (int k = 0; k < n && ok; ++k) {
                            if (k != i && arr[k].contains(sub)) {
                                ok = false;
                            }
                        }
                        if (ok) {
                            ans[i] = sub;
                        }
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
    vector<string> shortestSubstrings(vector<string>& arr) {
        int n = arr.size();
        vector<string> ans(n);
        for (int i = 0; i < n; ++i) {
            int m = arr[i].size();
            for (int j = 1; j <= m && ans[i].empty(); ++j) {
                for (int l = 0; l <= m - j; ++l) {
                    string sub = arr[i].substr(l, j);
                    if (ans[i].empty() || sub < ans[i]) {
                        bool ok = true;
                        for (int k = 0; k < n && ok; ++k) {
                            if (k != i && arr[k].find(sub) != string::npos) {
                                ok = false;
                            }
                        }
                        if (ok) {
                            ans[i] = sub;
                        }
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
func shortestSubstrings(arr []string) []string {
	ans := make([]string, len(arr))
	for i, s := range arr {
		m := len(s)
		for j := 1; j <= m && len(ans[i]) == 0; j++ {
			for l := 0; l <= m-j; l++ {
				sub := s[l : l+j]
				if len(ans[i]) == 0 || ans[i] > sub {
					ok := true
					for k, t := range arr {
						if k != i && strings.Contains(t, sub) {
							ok = false
							break
						}
					}
					if ok {
						ans[i] = sub
					}
				}
			}
		}
	}
	return ans
}
```

#### TypeScript

```ts
function shortestSubstrings(arr: string[]): string[] {
    const n: number = arr.length;
    const ans: string[] = Array(n).fill('');
    for (let i = 0; i < n; ++i) {
        const m: number = arr[i].length;
        for (let j = 1; j <= m && ans[i] === ''; ++j) {
            for (let l = 0; l <= m - j; ++l) {
                const sub: string = arr[i].slice(l, l + j);
                if (ans[i] === '' || sub.localeCompare(ans[i]) < 0) {
                    let ok: boolean = true;
                    for (let k = 0; k < n && ok; ++k) {
                        if (k !== i && arr[k].includes(sub)) {
                            ok = false;
                        }
                    }
                    if (ok) {
                        ans[i] = sub;
                    }
                }
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

# [3077. K 个不相交子数组的最大能量值](https://leetcode.cn/problems/maximum-strength-of-k-disjoint-subarrays){#3077}

{{< tabs "3077" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumStrength(self, nums: List[int], k: int) -> int:
        n = len(nums)
        f = [[[-inf, -inf] for _ in range(k + 1)] for _ in range(n + 1)]
        f[0][0][0] = 0
        for i, x in enumerate(nums, 1):
            for j in range(k + 1):
                sign = 1 if j & 1 else -1
                f[i][j][0] = max(f[i - 1][j][0], f[i - 1][j][1])
                f[i][j][1] = max(f[i][j][1], f[i - 1][j][1] + sign * x * (k - j + 1))
                if j:
                    f[i][j][1] = max(
                        f[i][j][1], max(f[i - 1][j - 1]) + sign * x * (k - j + 1)
                    )
        return max(f[n][k])
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long maximumStrength(int[] nums, int k) {
        int n = nums.length;
        long[][][] f = new long[n + 1][k + 1][2];
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                Arrays.fill(f[i][j], Long.MIN_VALUE / 2);
            }
        }
        f[0][0][0] = 0;
        for (int i = 1; i <= n; i++) {
            int x = nums[i - 1];
            for (int j = 0; j <= k; j++) {
                long sign = (j & 1) == 1 ? 1 : -1;
                long val = sign * x * (k - j + 1);
                f[i][j][0] = Math.max(f[i - 1][j][0], f[i - 1][j][1]);
                f[i][j][1] = Math.max(f[i][j][1], f[i - 1][j][1] + val);
                if (j > 0) {
                    long t = Math.max(f[i - 1][j - 1][0], f[i - 1][j - 1][1]) + val;
                    f[i][j][1] = Math.max(f[i][j][1], t);
                }
            }
        }
        return Math.max(f[n][k][0], f[n][k][1]);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    long long maximumStrength(vector<int>& nums, int k) {
        int n = nums.size();
        long long f[n + 1][k + 1][2];
        memset(f, -0x3f3f3f3f3f3f3f3f, sizeof(f));
        f[0][0][0] = 0;
        for (int i = 1; i <= n; i++) {
            int x = nums[i - 1];
            for (int j = 0; j <= k; j++) {
                long long sign = (j & 1) == 1 ? 1 : -1;
                long long val = sign * x * (k - j + 1);
                f[i][j][0] = max(f[i - 1][j][0], f[i - 1][j][1]);
                f[i][j][1] = max(f[i][j][1], f[i - 1][j][1] + val);
                if (j > 0) {
                    long long t = max(f[i - 1][j - 1][0], f[i - 1][j - 1][1]) + val;
                    f[i][j][1] = max(f[i][j][1], t);
                }
            }
        }
        return max(f[n][k][0], f[n][k][1]);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumStrength(nums []int, k int) int64 {
	n := len(nums)
	f := make([][][]int64, n+1)
	const inf int64 = math.MinInt64 / 2
	for i := range f {
		f[i] = make([][]int64, k+1)
		for j := range f[i] {
			f[i][j] = []int64{inf, inf}
		}
	}
	f[0][0][0] = 0
	for i := 1; i <= n; i++ {
		x := nums[i-1]
		for j := 0; j <= k; j++ {
			sign := int64(-1)
			if j&1 == 1 {
				sign = 1
			}
			val := sign * int64(x) * int64(k-j+1)
			f[i][j][0] = max(f[i-1][j][0], f[i-1][j][1])
			f[i][j][1] = max(f[i][j][1], f[i-1][j][1]+val)
			if j > 0 {
				t := max(f[i-1][j-1][0], f[i-1][j-1][1]) + val
				f[i][j][1] = max(f[i][j][1], t)
			}
		}
	}
	return max(f[n][k][0], f[n][k][1])
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumStrength(nums: number[], k: number): number {
    const n: number = nums.length;
    const f: number[][][] = Array.from({ length: n + 1 }, () =>
        Array.from({ length: k + 1 }, () => [-Infinity, -Infinity]),
    );
    f[0][0][0] = 0;
    for (let i = 1; i <= n; i++) {
        const x: number = nums[i - 1];
        for (let j = 0; j <= k; j++) {
            const sign: number = (j & 1) === 1 ? 1 : -1;
            const val: number = sign * x * (k - j + 1);
            f[i][j][0] = Math.max(f[i - 1][j][0], f[i - 1][j][1]);
            f[i][j][1] = Math.max(f[i][j][1], f[i - 1][j][1] + val);
            if (j > 0) {
                f[i][j][1] = Math.max(f[i][j][1], Math.max(...f[i - 1][j - 1]) + val);
            }
        }
    }
    return Math.max(...f[n][k]);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个长度为 <code>n</code>&nbsp;下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>nums</code>&nbsp;和一个 <strong>正奇数</strong>&nbsp;整数&nbsp;<code>k</code>&nbsp;。</p>

<p><code>x</code> 个子数组的能量值定义为&nbsp;<code>strength = sum[1] * x - sum[2] * (x - 1) + sum[3] * (x - 2) - sum[4] * (x - 3) + ... + sum[x] * 1</code> ，其中&nbsp;<code>sum[i]</code>&nbsp;是第 <code>i</code>&nbsp;个子数组的和。更正式的，能量值是满足&nbsp;<code>1 &lt;= i &lt;= x</code>&nbsp;的所有&nbsp;<code>i</code>&nbsp;对应的&nbsp;<code>(-1)<sup>i+1</sup> * sum[i] * (x - i + 1)</code>&nbsp;之和。</p>

<p>你需要在 <code>nums</code>&nbsp;中选择 <code>k</code>&nbsp;个 <strong>不相交</strong><strong>子数组</strong>&nbsp;，使得&nbsp;<strong>能量值最大</strong>&nbsp;。</p>

<p>请你返回可以得到的 <strong>最大</strong><strong>能量值</strong>&nbsp;。</p>

<p><strong>注意</strong>，选出来的所有子数组&nbsp;<strong>不</strong>&nbsp;需要覆盖整个数组。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [1,2,3,-1,2], k = 3
<b>输出：</b>22
<b>解释：</b>选择 3 个子数组的最好方式是选择：nums[0..2] ，nums[3..3] 和 nums[4..4] 。能量值为 (1 + 2 + 3) * 3 - (-1) * 2 + 2 * 1 = 22 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [12,-2,-2,-2,-2], k = 5
<b>输出：</b>64
<b>解释：</b>唯一一种选 5 个不相交子数组的方案是：nums[0..0] ，nums[1..1] ，nums[2..2] ，nums[3..3] 和 nums[4..4] 。能量值为 12 * 5 - (-2) * 4 + (-2) * 3 - (-2) * 2 + (-2) * 1 = 64 。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>nums = [-1,-2,-3], k = 1
<b>输出：</b>-1
<b>解释：</b>选择 1 个子数组的最优方案是：nums[0..0] 。能量值为 -1 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= k &lt;= n</code></li>
	<li><code>1 &lt;= n * k &lt;= 10<sup>6</sup></code></li>
	<li><code>k</code> 是奇数。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

对于第 $i$ 个数 $nums[i - 1]$，如果它被选择，且位于第 $j$ 个子数组，那么它对答案的贡献是 $nums[i - 1] \times (k - j + 1) \times (-1)^{j+1}$，我们不妨将 $(-1)^{j+1}$ 记为 $sign$，那么它对答案的贡献是 $sign \times nums[i - 1] \times (k - j + 1)$。

我们定义 $f[i][j][0]$ 表示从前 $i 个数中选择 $j$ 个子数组，且第 $i$ 个数不被选的最大能量值，定义 $f[i][j][1]$ 表示从前 $i$ 个数中选择 $j$ 个子数组，且第 $i$ 个数被选的最大能量值。初始时 $f[0][0][1] = 0$，其余的值都是 $-\infty$。

当 $i > 0$ 时，我们考虑 $f[i][j]$ 如何进行状态转移。

如果第 $i$ 个数不被选，那么第 $i-1$ 个数既可以被选，也可以不被选，所以 $f[i][j][0] = \max(f[i-1][j][0], f[i-1][j][1])$。

如果第 $i$ 个数被选，此时如果第 $i-1$ 个数与第 $i$ 个数位于同一个子数组中，那么 $f[i][j][1] = \max(f[i][j][1], f[i-1][j][1] + sign \times nums[i-1] \times (k - j + 1))$，否则 $f[i][j][1] = \max(f[i][j][1], \max(f[i-1][j-1][0], f[i-1][j-1][1]) + sign \times nums[i-1] \times (k - j + 1))$。我们取这两种情况的最大值作为 $f[i][j][1]$。

最终答案是 $\max(f[n][k][0], f[n][k][1])$。

时间复杂度 $O(n \times k)$，空间复杂度 $O(n \times k)$。其中 $n$ 是数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumStrength(self, nums: List[int], k: int) -> int:
        n = len(nums)
        f = [[[-inf, -inf] for _ in range(k + 1)] for _ in range(n + 1)]
        f[0][0][0] = 0
        for i, x in enumerate(nums, 1):
            for j in range(k + 1):
                sign = 1 if j & 1 else -1
                f[i][j][0] = max(f[i - 1][j][0], f[i - 1][j][1])
                f[i][j][1] = max(f[i][j][1], f[i - 1][j][1] + sign * x * (k - j + 1))
                if j:
                    f[i][j][1] = max(
                        f[i][j][1], max(f[i - 1][j - 1]) + sign * x * (k - j + 1)
                    )
        return max(f[n][k])
```

#### Java

```java
class Solution {
    public long maximumStrength(int[] nums, int k) {
        int n = nums.length;
        long[][][] f = new long[n + 1][k + 1][2];
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                Arrays.fill(f[i][j], Long.MIN_VALUE / 2);
            }
        }
        f[0][0][0] = 0;
        for (int i = 1; i <= n; i++) {
            int x = nums[i - 1];
            for (int j = 0; j <= k; j++) {
                long sign = (j & 1) == 1 ? 1 : -1;
                long val = sign * x * (k - j + 1);
                f[i][j][0] = Math.max(f[i - 1][j][0], f[i - 1][j][1]);
                f[i][j][1] = Math.max(f[i][j][1], f[i - 1][j][1] + val);
                if (j > 0) {
                    long t = Math.max(f[i - 1][j - 1][0], f[i - 1][j - 1][1]) + val;
                    f[i][j][1] = Math.max(f[i][j][1], t);
                }
            }
        }
        return Math.max(f[n][k][0], f[n][k][1]);
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long maximumStrength(vector<int>& nums, int k) {
        int n = nums.size();
        long long f[n + 1][k + 1][2];
        memset(f, -0x3f3f3f3f3f3f3f3f, sizeof(f));
        f[0][0][0] = 0;
        for (int i = 1; i <= n; i++) {
            int x = nums[i - 1];
            for (int j = 0; j <= k; j++) {
                long long sign = (j & 1) == 1 ? 1 : -1;
                long long val = sign * x * (k - j + 1);
                f[i][j][0] = max(f[i - 1][j][0], f[i - 1][j][1]);
                f[i][j][1] = max(f[i][j][1], f[i - 1][j][1] + val);
                if (j > 0) {
                    long long t = max(f[i - 1][j - 1][0], f[i - 1][j - 1][1]) + val;
                    f[i][j][1] = max(f[i][j][1], t);
                }
            }
        }
        return max(f[n][k][0], f[n][k][1]);
    }
};
```

#### Go

```go
func maximumStrength(nums []int, k int) int64 {
	n := len(nums)
	f := make([][][]int64, n+1)
	const inf int64 = math.MinInt64 / 2
	for i := range f {
		f[i] = make([][]int64, k+1)
		for j := range f[i] {
			f[i][j] = []int64{inf, inf}
		}
	}
	f[0][0][0] = 0
	for i := 1; i <= n; i++ {
		x := nums[i-1]
		for j := 0; j <= k; j++ {
			sign := int64(-1)
			if j&1 == 1 {
				sign = 1
			}
			val := sign * int64(x) * int64(k-j+1)
			f[i][j][0] = max(f[i-1][j][0], f[i-1][j][1])
			f[i][j][1] = max(f[i][j][1], f[i-1][j][1]+val)
			if j > 0 {
				t := max(f[i-1][j-1][0], f[i-1][j-1][1]) + val
				f[i][j][1] = max(f[i][j][1], t)
			}
		}
	}
	return max(f[n][k][0], f[n][k][1])
}
```

#### TypeScript

```ts
function maximumStrength(nums: number[], k: number): number {
    const n: number = nums.length;
    const f: number[][][] = Array.from({ length: n + 1 }, () =>
        Array.from({ length: k + 1 }, () => [-Infinity, -Infinity]),
    );
    f[0][0][0] = 0;
    for (let i = 1; i <= n; i++) {
        const x: number = nums[i - 1];
        for (let j = 0; j <= k; j++) {
            const sign: number = (j & 1) === 1 ? 1 : -1;
            const val: number = sign * x * (k - j + 1);
            f[i][j][0] = Math.max(f[i - 1][j][0], f[i - 1][j][1]);
            f[i][j][1] = Math.max(f[i][j][1], f[i - 1][j][1] + val);
            if (j > 0) {
                f[i][j][1] = Math.max(f[i][j][1], Math.max(...f[i - 1][j - 1]) + val);
            }
        }
    }
    return Math.max(...f[n][k]);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3078. 矩阵中的字母数字模式匹配 I 🔒](https://leetcode.cn/problems/match-alphanumerical-pattern-in-matrix-i){#3078}

{{< tabs "3078" >}}

{{% tab "python" %}}
```python
class Solution:
    def findPattern(self, board: List[List[int]], pattern: List[str]) -> List[int]:
        def check(i: int, j: int) -> bool:
            d1 = {}
            d2 = {}
            for a in range(r):
                for b in range(c):
                    x, y = i + a, j + b
                    if pattern[a][b].isdigit():
                        if int(pattern[a][b]) != board[x][y]:
                            return False
                    else:
                        if pattern[a][b] in d1 and d1[pattern[a][b]] != board[x][y]:
                            return False
                        if board[x][y] in d2 and d2[board[x][y]] != pattern[a][b]:
                            return False
                        d1[pattern[a][b]] = board[x][y]
                        d2[board[x][y]] = pattern[a][b]
            return True

        m, n = len(board), len(board[0])
        r, c = len(pattern), len(pattern[0])
        for i in range(m - r + 1):
            for j in range(n - c + 1):
                if check(i, j):
                    return [i, j]
        return [-1, -1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] findPattern(int[][] board, String[] pattern) {
        int m = board.length, n = board[0].length;
        int r = pattern.length, c = pattern[0].length();
        for (int i = 0; i < m - r + 1; ++i) {
            for (int j = 0; j < n - c + 1; ++j) {
                if (check(board, pattern, i, j)) {
                    return new int[] {i, j};
                }
            }
        }
        return new int[] {-1, -1};
    }

    private boolean check(int[][] board, String[] pattern, int i, int j) {
        int[] d1 = new int[26];
        int[] d2 = new int[10];
        Arrays.fill(d1, -1);
        Arrays.fill(d2, -1);
        for (int a = 0; a < pattern.length; ++a) {
            for (int b = 0; b < pattern[0].length(); ++b) {
                int x = i + a, y = j + b;
                if (Character.isDigit(pattern[a].charAt(b))) {
                    int v = pattern[a].charAt(b) - '0';
                    if (v != board[x][y]) {
                        return false;
                    }
                } else {
                    int v = pattern[a].charAt(b) - 'a';
                    if (d1[v] != -1 && d1[v] != board[x][y]) {
                        return false;
                    }
                    if (d2[board[x][y]] != -1 && d2[board[x][y]] != v) {
                        return false;
                    }
                    d1[v] = board[x][y];
                    d2[board[x][y]] = v;
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
    vector<int> findPattern(vector<vector<int>>& board, vector<string>& pattern) {
        int m = board.size(), n = board[0].size();
        int r = pattern.size(), c = pattern[0].size();
        auto check = [&](int i, int j) {
            vector<int> d1(26, -1);
            vector<int> d2(10, -1);
            for (int a = 0; a < r; ++a) {
                for (int b = 0; b < c; ++b) {
                    int x = i + a, y = j + b;
                    if (isdigit(pattern[a][b])) {
                        int v = pattern[a][b] - '0';
                        if (v != board[x][y]) {
                            return false;
                        }
                    } else {
                        int v = pattern[a][b] - 'a';
                        if (d1[v] != -1 && d1[v] != board[x][y]) {
                            return false;
                        }
                        if (d2[board[x][y]] != -1 && d2[board[x][y]] != v) {
                            return false;
                        }
                        d1[v] = board[x][y];
                        d2[board[x][y]] = v;
                    }
                }
            }
            return true;
        };
        for (int i = 0; i < m - r + 1; ++i) {
            for (int j = 0; j < n - c + 1; ++j) {
                if (check(i, j)) {
                    return {i, j};
                }
            }
        }
        return {-1, -1};
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findPattern(board [][]int, pattern []string) []int {
	m, n := len(board), len(board[0])
	r, c := len(pattern), len(pattern[0])
	check := func(i, j int) bool {
		d1 := [26]int{}
		d2 := [10]int{}
		for a := 0; a < r; a++ {
			for b := 0; b < c; b++ {
				x, y := i+a, j+b
				if pattern[a][b] >= '0' && pattern[a][b] <= '9' {
					v := int(pattern[a][b] - '0')
					if v != board[x][y] {
						return false
					}
				} else {
					v := int(pattern[a][b] - 'a')
					if d1[v] > 0 && d1[v]-1 != board[x][y] {
						return false
					}
					if d2[board[x][y]] > 0 && d2[board[x][y]]-1 != v {
						return false
					}
					d1[v] = board[x][y] + 1
					d2[board[x][y]] = v + 1
				}
			}
		}
		return true
	}
	for i := 0; i < m-r+1; i++ {
		for j := 0; j < n-c+1; j++ {
			if check(i, j) {
				return []int{i, j}
			}
		}
	}
	return []int{-1, -1}
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findPattern(board: number[][], pattern: string[]): number[] {
    const m: number = board.length;
    const n: number = board[0].length;
    const r: number = pattern.length;
    const c: number = pattern[0].length;

    const check = (i: number, j: number): boolean => {
        const d1: number[] = Array(26).fill(-1);
        const d2: number[] = Array(10).fill(-1);

        for (let a = 0; a < r; ++a) {
            for (let b = 0; b < c; ++b) {
                const x: number = i + a;
                const y: number = j + b;

                if (!isNaN(Number(pattern[a][b]))) {
                    const v: number = Number(pattern[a][b]);
                    if (v !== board[x][y]) {
                        return false;
                    }
                } else {
                    const v: number = pattern[a].charCodeAt(b) - 'a'.charCodeAt(0);
                    if (d1[v] !== -1 && d1[v] !== board[x][y]) {
                        return false;
                    }
                    if (d2[board[x][y]] !== -1 && d2[board[x][y]] !== v) {
                        return false;
                    }
                    d1[v] = board[x][y];
                    d2[board[x][y]] = v;
                }
            }
        }
        return true;
    };

    for (let i = 0; i < m - r + 1; ++i) {
        for (let j = 0; j < n - c + 1; ++j) {
            if (check(i, j)) {
                return [i, j];
            }
        }
    }
    return [-1, -1];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个二维整数矩阵&nbsp;<code>board</code>&nbsp;和一个二维字符矩阵&nbsp;<code>pattern</code>。其中&nbsp;<code>0 &lt;= board[r][c] &lt;= 9</code>&nbsp;并且&nbsp;<code>pattern</code>&nbsp;的每个元素是一个数字或一个小写英文字母。</p>

<p>你的任务是找到 <strong>匹配</strong>&nbsp;<code>board</code>&nbsp;的子矩阵&nbsp;<code>pattern</code>。</p>

<p>如果我们能用一些数字（每个 <strong>不同</strong> 的字母对应 <strong>不同</strong> 的数字）替换&nbsp;<code>pattern</code>&nbsp;中包含的字母使得结果矩阵与整数矩阵&nbsp;<code>part</code>&nbsp;相同，我们称整数矩阵&nbsp;<code>part</code>&nbsp;与&nbsp;<code>pattern</code>&nbsp;匹配。换句话说，</p>

<ul>
	<li>这两个矩阵具有相同的维数。</li>
	<li>如果&nbsp;<code>pattern[r][c]</code>&nbsp;是一个数字，那么&nbsp;<code>part[r][c]</code>&nbsp;必须是&nbsp;<strong>相同的</strong> 数字。</li>
	<li>如果&nbsp;<code>pattern[r][c]</code>&nbsp;是一个字母&nbsp;<code>x</code>：
	<ul>
		<li>对于每个&nbsp;<code>pattern[i][j] == x</code>，<code>part[i][j]</code>&nbsp;一定与 <code>part[r][c]</code>&nbsp;<strong>相同</strong>。</li>
		<li>对于每个&nbsp;<code>pattern[i][j] != x</code>，<code>part[i][j]</code>&nbsp;一定与 <code>part[r][c]</code>&nbsp;<strong>不同</strong>。<span style="display: none;"> </span></li>
	</ul>
	</li>
</ul>

<p>返回一个长度为<em>&nbsp;</em><code>2</code>&nbsp;的数组，包含匹配&nbsp;<code>pattern</code>&nbsp;的&nbsp;<code>board</code>&nbsp;的子矩阵左上角的行号和列号。如果有多个这样的子矩阵，返回行号更小的子矩阵。如果依然有多个，则返回列号更小的子矩阵。如果没有符合的答案，返回&nbsp;<code>[-1, -1]</code>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div style="display:flex; flex-wrap: wrap; align-items: flex-start; gap: 12px;">
<table border="1" cellspacing="3" style="border-collapse: separate; text-align: center;">
	<tbody>
		<tr>
			<td style="padding: 5px 10px; border: 1px solid red; --darkreader-inline-border-top: #b30000; --darkreader-inline-border-right: #b30000; --darkreader-inline-border-bottom: #b30000; --darkreader-inline-border-left: #b30000;">1</td>
			<td style="padding: 5px 10px; border: 1px solid red; --darkreader-inline-border-top: #b30000; --darkreader-inline-border-right: #b30000; --darkreader-inline-border-bottom: #b30000; --darkreader-inline-border-left: #b30000;">2</td>
			<td style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">2</td>
		</tr>
		<tr>
			<td style="padding: 5px 10px; border: 1px solid red; --darkreader-inline-border-top: #b30000; --darkreader-inline-border-right: #b30000; --darkreader-inline-border-bottom: #b30000; --darkreader-inline-border-left: #b30000;">2</td>
			<td style="padding: 5px 10px; border: 1px solid red; --darkreader-inline-border-top: #b30000; --darkreader-inline-border-right: #b30000; --darkreader-inline-border-bottom: #b30000; --darkreader-inline-border-left: #b30000;">2</td>
			<td style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">3</td>
		</tr>
		<tr>
			<td style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">2</td>
			<td style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">3</td>
			<td style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">3</td>
		</tr>
	</tbody>
</table>

<table border="1" cellspacing="3" style="border-collapse: separate; text-align: center;">
	<tbody>
		<tr>
			<td style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">a</td>
			<td style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">b</td>
		</tr>
		<tr>
			<td style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">b</td>
			<td style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">b</td>
		</tr>
	</tbody>
</table>
</div>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">board = [[1,2,2],[2,2,3],[2,3,3]], pattern = ["ab","bb"]</span></p>

<p><strong>输出：</strong><span class="example-io">[0,0]</span></p>

<p><strong>解释：</strong>如果我们考虑这个映射：<code>"a" -&gt; 1</code> 并且&nbsp;<code>"b" -&gt; 2</code>；左上角为&nbsp;<code>(0,0)</code>&nbsp;的子矩阵与上面的矩阵中加粗的相匹配。</p>

<p>注意左上角为&nbsp;<code>(1,1)</code>&nbsp;的子矩阵同样匹配，但它在另一个之后出现，所以我们返回&nbsp;<code>[0,0]</code>。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div style="display:flex; flex-wrap: wrap; align-items: flex-start; gap: 12px;">
<table border="1" cellspacing="3" style="border-collapse: separate; text-align: center;">
	<tbody>
		<tr>
			<td style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">1</td>
			<td style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">1</td>
			<td style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">2</td>
		</tr>
		<tr>
			<td style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">3</td>
			<td style="padding: 5px 10px; border: 1px solid red; --darkreader-inline-border-top: #b30000; --darkreader-inline-border-right: #b30000; --darkreader-inline-border-bottom: #b30000; --darkreader-inline-border-left: #b30000;">3</td>
			<td style="padding: 5px 10px; border: 1px solid red; --darkreader-inline-border-top: #b30000; --darkreader-inline-border-right: #b30000; --darkreader-inline-border-bottom: #b30000; --darkreader-inline-border-left: #b30000;">4</td>
		</tr>
		<tr>
			<td style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">6</td>
			<td style="padding: 5px 10px; border: 1px solid red; --darkreader-inline-border-top: #b30000; --darkreader-inline-border-right: #b30000; --darkreader-inline-border-bottom: #b30000; --darkreader-inline-border-left: #b30000;">6</td>
			<td style="padding: 5px 10px; border: 1px solid red; --darkreader-inline-border-top: #b30000; --darkreader-inline-border-right: #b30000; --darkreader-inline-border-bottom: #b30000; --darkreader-inline-border-left: #b30000;">6</td>
		</tr>
	</tbody>
</table>

<table border="1" cellspacing="3" style="border-collapse: separate; text-align: center;">
	<tbody>
		<tr>
			<td style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">a</td>
			<td style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">b</td>
		</tr>
		<tr>
			<td style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">6</td>
			<td style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">6</td>
		</tr>
	</tbody>
</table>
</div>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">board = [[1,1,2],[3,3,4],[6,6,6]], pattern = ["ab","66"]</span></p>

<p><strong>输出：</strong><span class="example-io">[1,1]</span></p>

<p><strong>解释：</strong>如果我们考虑这个映射：<code>"a" -&gt; 3</code>&nbsp;并且&nbsp;<code>"b" -&gt; 4</code>；左上角为&nbsp;<code>(1,1)</code>&nbsp;的子矩阵与上面的矩阵中加粗的匹配。</p>

<p>注意&nbsp;<code>"a"</code>&nbsp;和&nbsp;<code>"b"</code>&nbsp;对应的值必须不同，左上角为 <code>(1,0)</code>&nbsp;的子矩阵不匹配。因此，我们返回&nbsp;<code>[1,1]</code>。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div style="display:flex; flex-wrap: wrap; align-items: flex-start; gap: 12px;">
<table border="1" cellspacing="3" style="border-collapse: separate; text-align: center;">
	<tbody>
		<tr>
			<td style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">1</td>
			<td style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">2</td>
		</tr>
		<tr>
			<td style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">2</td>
			<td style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">1</td>
		</tr>
	</tbody>
</table>

<table border="1" cellspacing="3" style="border-collapse: separate; text-align: center;">
	<tbody>
		<tr>
			<td style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">x</td>
			<td style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #8c8273; --darkreader-inline-border-right: #8c8273; --darkreader-inline-border-bottom: #8c8273; --darkreader-inline-border-left: #8c8273;">x</td>
		</tr>
	</tbody>
</table>
</div>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">board = [[1,2],[2,1]], pattern = ["xx"]</span></p>

<p><b>输出：</b><span class="example-io">[-1,-1]</span></p>

<p><strong>解释：</strong>&nbsp;由于匹配子矩阵的值必须相同，因此不存在匹配。因此，我们返回&nbsp;<code>[-1,-1]</code>。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= board.length &lt;= 50</code></li>
	<li><code>1 &lt;= board[i].length &lt;= 50</code></li>
	<li><code>0 &lt;= board[i][j] &lt;= 9</code></li>
	<li><code>1 &lt;= pattern.length &lt;= 50</code></li>
	<li><code>1 &lt;= pattern[i].length &lt;= 50</code></li>
	<li><code>pattern[i][j]</code> 表示为一个数字的字符串或一个小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举

我们不妨记 $m$ 和 $n$ 分别为矩阵 `board` 的行数和列数，记 $r$ 和 $c$ 分别为矩阵 `pattern` 的行数和列数。

我们可以从小到大枚举矩阵 `board` 中的每一个可能的子矩阵的左上角位置 $(i, j)$，然后判断以 $(i, j)$ 为左上角的 $r \times c$ 的子矩阵是否与 `pattern` 匹配。如果找到了一个匹配的子矩阵，我们就返回 $(i, j)$。否则，我们返回 $(-1, -1)$。

时间复杂度 $O(m \times n \times r \times c)$，其中 $m$ 和 $n$ 分别是矩阵 `board` 的行数和列数，而 $r$ 和 $c$ 分别是矩阵 `pattern` 的行数和列数。空间复杂度 $O(|\Sigma|)$，其中 $\Sigma$ 是字符集，本题中 $\Sigma$ 包括数字和小写字母，因此 $|\Sigma| \leq 36$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findPattern(self, board: List[List[int]], pattern: List[str]) -> List[int]:
        def check(i: int, j: int) -> bool:
            d1 = {}
            d2 = {}
            for a in range(r):
                for b in range(c):
                    x, y = i + a, j + b
                    if pattern[a][b].isdigit():
                        if int(pattern[a][b]) != board[x][y]:
                            return False
                    else:
                        if pattern[a][b] in d1 and d1[pattern[a][b]] != board[x][y]:
                            return False
                        if board[x][y] in d2 and d2[board[x][y]] != pattern[a][b]:
                            return False
                        d1[pattern[a][b]] = board[x][y]
                        d2[board[x][y]] = pattern[a][b]
            return True

        m, n = len(board), len(board[0])
        r, c = len(pattern), len(pattern[0])
        for i in range(m - r + 1):
            for j in range(n - c + 1):
                if check(i, j):
                    return [i, j]
        return [-1, -1]
```

#### Java

```java
class Solution {
    public int[] findPattern(int[][] board, String[] pattern) {
        int m = board.length, n = board[0].length;
        int r = pattern.length, c = pattern[0].length();
        for (int i = 0; i < m - r + 1; ++i) {
            for (int j = 0; j < n - c + 1; ++j) {
                if (check(board, pattern, i, j)) {
                    return new int[] {i, j};
                }
            }
        }
        return new int[] {-1, -1};
    }

    private boolean check(int[][] board, String[] pattern, int i, int j) {
        int[] d1 = new int[26];
        int[] d2 = new int[10];
        Arrays.fill(d1, -1);
        Arrays.fill(d2, -1);
        for (int a = 0; a < pattern.length; ++a) {
            for (int b = 0; b < pattern[0].length(); ++b) {
                int x = i + a, y = j + b;
                if (Character.isDigit(pattern[a].charAt(b))) {
                    int v = pattern[a].charAt(b) - '0';
                    if (v != board[x][y]) {
                        return false;
                    }
                } else {
                    int v = pattern[a].charAt(b) - 'a';
                    if (d1[v] != -1 && d1[v] != board[x][y]) {
                        return false;
                    }
                    if (d2[board[x][y]] != -1 && d2[board[x][y]] != v) {
                        return false;
                    }
                    d1[v] = board[x][y];
                    d2[board[x][y]] = v;
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
    vector<int> findPattern(vector<vector<int>>& board, vector<string>& pattern) {
        int m = board.size(), n = board[0].size();
        int r = pattern.size(), c = pattern[0].size();
        auto check = [&](int i, int j) {
            vector<int> d1(26, -1);
            vector<int> d2(10, -1);
            for (int a = 0; a < r; ++a) {
                for (int b = 0; b < c; ++b) {
                    int x = i + a, y = j + b;
                    if (isdigit(pattern[a][b])) {
                        int v = pattern[a][b] - '0';
                        if (v != board[x][y]) {
                            return false;
                        }
                    } else {
                        int v = pattern[a][b] - 'a';
                        if (d1[v] != -1 && d1[v] != board[x][y]) {
                            return false;
                        }
                        if (d2[board[x][y]] != -1 && d2[board[x][y]] != v) {
                            return false;
                        }
                        d1[v] = board[x][y];
                        d2[board[x][y]] = v;
                    }
                }
            }
            return true;
        };
        for (int i = 0; i < m - r + 1; ++i) {
            for (int j = 0; j < n - c + 1; ++j) {
                if (check(i, j)) {
                    return {i, j};
                }
            }
        }
        return {-1, -1};
    }
};
```

#### Go

```go
func findPattern(board [][]int, pattern []string) []int {
	m, n := len(board), len(board[0])
	r, c := len(pattern), len(pattern[0])
	check := func(i, j int) bool {
		d1 := [26]int{}
		d2 := [10]int{}
		for a := 0; a < r; a++ {
			for b := 0; b < c; b++ {
				x, y := i+a, j+b
				if pattern[a][b] >= '0' && pattern[a][b] <= '9' {
					v := int(pattern[a][b] - '0')
					if v != board[x][y] {
						return false
					}
				} else {
					v := int(pattern[a][b] - 'a')
					if d1[v] > 0 && d1[v]-1 != board[x][y] {
						return false
					}
					if d2[board[x][y]] > 0 && d2[board[x][y]]-1 != v {
						return false
					}
					d1[v] = board[x][y] + 1
					d2[board[x][y]] = v + 1
				}
			}
		}
		return true
	}
	for i := 0; i < m-r+1; i++ {
		for j := 0; j < n-c+1; j++ {
			if check(i, j) {
				return []int{i, j}
			}
		}
	}
	return []int{-1, -1}
}
```

#### TypeScript

```ts
function findPattern(board: number[][], pattern: string[]): number[] {
    const m: number = board.length;
    const n: number = board[0].length;
    const r: number = pattern.length;
    const c: number = pattern[0].length;

    const check = (i: number, j: number): boolean => {
        const d1: number[] = Array(26).fill(-1);
        const d2: number[] = Array(10).fill(-1);

        for (let a = 0; a < r; ++a) {
            for (let b = 0; b < c; ++b) {
                const x: number = i + a;
                const y: number = j + b;

                if (!isNaN(Number(pattern[a][b]))) {
                    const v: number = Number(pattern[a][b]);
                    if (v !== board[x][y]) {
                        return false;
                    }
                } else {
                    const v: number = pattern[a].charCodeAt(b) - 'a'.charCodeAt(0);
                    if (d1[v] !== -1 && d1[v] !== board[x][y]) {
                        return false;
                    }
                    if (d2[board[x][y]] !== -1 && d2[board[x][y]] !== v) {
                        return false;
                    }
                    d1[v] = board[x][y];
                    d2[board[x][y]] = v;
                }
            }
        }
        return true;
    };

    for (let i = 0; i < m - r + 1; ++i) {
        for (let j = 0; j < n - c + 1; ++j) {
            if (check(i, j)) {
                return [i, j];
            }
        }
    }
    return [-1, -1];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3079. 求出加密整数的和](https://leetcode.cn/problems/find-the-sum-of-encrypted-integers){#3079}

{{< tabs "3079" >}}

{{% tab "python" %}}
```python
class Solution:
    def sumOfEncryptedInt(self, nums: List[int]) -> int:
        def encrypt(x: int) -> int:
            mx = p = 0
            while x:
                x, v = divmod(x, 10)
                mx = max(mx, v)
                p = p * 10 + 1
            return mx * p

        return sum(encrypt(x) for x in nums)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int sumOfEncryptedInt(int[] nums) {
        int ans = 0;
        for (int x : nums) {
            ans += encrypt(x);
        }
        return ans;
    }

    private int encrypt(int x) {
        int mx = 0, p = 0;
        for (; x > 0; x /= 10) {
            mx = Math.max(mx, x % 10);
            p = p * 10 + 1;
        }
        return mx * p;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        auto encrypt = [&](int x) {
            int mx = 0, p = 0;
            for (; x; x /= 10) {
                mx = max(mx, x % 10);
                p = p * 10 + 1;
            }
            return mx * p;
        };
        int ans = 0;
        for (int x : nums) {
            ans += encrypt(x);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func sumOfEncryptedInt(nums []int) (ans int) {
	encrypt := func(x int) int {
		mx, p := 0, 0
		for ; x > 0; x /= 10 {
			mx = max(mx, x%10)
			p = p*10 + 1
		}
		return mx * p
	}
	for _, x := range nums {
		ans += encrypt(x)
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function sumOfEncryptedInt(nums: number[]): number {
    const encrypt = (x: number): number => {
        let [mx, p] = [0, 0];
        for (; x > 0; x = Math.floor(x / 10)) {
            mx = Math.max(mx, x % 10);
            p = p * 10 + 1;
        }
        return mx * p;
    };
    return nums.reduce((acc, x) => acc + encrypt(x), 0);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组&nbsp;<code>nums</code>&nbsp;，数组中的元素都是&nbsp;<strong>正</strong>&nbsp;整数。定义一个加密函数&nbsp;<code>encrypt</code>&nbsp;，<code>encrypt(x)</code>&nbsp;将一个整数 <code>x</code>&nbsp;中 <strong>每一个</strong>&nbsp;数位都用 <code>x</code>&nbsp;中的&nbsp;<strong>最大</strong>&nbsp;数位替换。比方说&nbsp;<code>encrypt(523) = 555</code> 且&nbsp;<code>encrypt(213) = 333</code>&nbsp;。</p>

<p>请你返回数组中所有元素加密后的 <strong>和</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block" style="border-color: var(--border-tertiary); border-left-width: 2px; color: var(--text-secondary); font-size: .875rem; margin-bottom: 1rem; margin-top: 1rem; overflow: visible; padding-left: 1rem;">
<p><strong>输入：</strong><span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;">nums = [1,2,3]</span></p>

<p><strong>输出：</strong><span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;">6</span></p>

<p><b>解释：</b>加密后的元素位&nbsp;<code>[1,2,3]</code>&nbsp;。加密元素的和为&nbsp;<code>1 + 2 + 3 == 6</code>&nbsp;。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block" style="border-color: var(--border-tertiary); border-left-width: 2px; color: var(--text-secondary); font-size: .875rem; margin-bottom: 1rem; margin-top: 1rem; overflow: visible; padding-left: 1rem;">
<p><strong>输入：</strong><span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;">nums = [10,21,31]</span></p>

<p><strong>输出：</strong><span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;">66</span></p>

<p><b>解释：</b>加密后的元素为&nbsp;<code>[11,22,33]</code>&nbsp;。加密元素的和为&nbsp;<code>11 + 22 + 33 == 66</code> 。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 50</code></li>
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

我们直接模拟加密的过程，定义一个函数 $encrypt(x)$，将一个整数 $x$ 中每一个数位都用 $x$ 中的最大数位替换。函数的实现如下：

我们可以通过不断地对 $x$ 取模和整除 $10$ 来得到 $x$ 的每一位数，找到最大的数位，记为 $mx$。在循环的过程中，我们还可以用一个变量 $p$ 来记录 $mx$ 的基础底数，即 $p = 1, 11, 111, \cdots$。最后返回 $mx \times p$ 即可。

时间复杂度 $O(n \times \log M)$，其中 $n$ 是数组的长度，而 $M$ 是数组中元素的最大值。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def sumOfEncryptedInt(self, nums: List[int]) -> int:
        def encrypt(x: int) -> int:
            mx = p = 0
            while x:
                x, v = divmod(x, 10)
                mx = max(mx, v)
                p = p * 10 + 1
            return mx * p

        return sum(encrypt(x) for x in nums)
```

#### Java

```java
class Solution {
    public int sumOfEncryptedInt(int[] nums) {
        int ans = 0;
        for (int x : nums) {
            ans += encrypt(x);
        }
        return ans;
    }

    private int encrypt(int x) {
        int mx = 0, p = 0;
        for (; x > 0; x /= 10) {
            mx = Math.max(mx, x % 10);
            p = p * 10 + 1;
        }
        return mx * p;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        auto encrypt = [&](int x) {
            int mx = 0, p = 0;
            for (; x; x /= 10) {
                mx = max(mx, x % 10);
                p = p * 10 + 1;
            }
            return mx * p;
        };
        int ans = 0;
        for (int x : nums) {
            ans += encrypt(x);
        }
        return ans;
    }
};
```

#### Go

```go
func sumOfEncryptedInt(nums []int) (ans int) {
	encrypt := func(x int) int {
		mx, p := 0, 0
		for ; x > 0; x /= 10 {
			mx = max(mx, x%10)
			p = p*10 + 1
		}
		return mx * p
	}
	for _, x := range nums {
		ans += encrypt(x)
	}
	return
}
```

#### TypeScript

```ts
function sumOfEncryptedInt(nums: number[]): number {
    const encrypt = (x: number): number => {
        let [mx, p] = [0, 0];
        for (; x > 0; x = Math.floor(x / 10)) {
            mx = Math.max(mx, x % 10);
            p = p * 10 + 1;
        }
        return mx * p;
    };
    return nums.reduce((acc, x) => acc + encrypt(x), 0);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
