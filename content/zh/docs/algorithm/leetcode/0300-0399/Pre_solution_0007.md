---
title: "0360_有序转化数组 🔒"
date: 2025-10-08T18:35:54+08:00
weight: 7
tags: [二分查找, 二叉树, 前缀和, 动态规划, 双指针, 广度优先搜索, 排序, 数学, 数据流, 数组, 有序集合, 栈, 树, 深度优先搜索, 矩阵, 设计, 链表, 队列]
---

{{< markmap >}}
### [0360_有序转化数组 🔒](#360)
#### [数组](#360)
#### [数学](#360)
#### [双指针](#360)
#### [排序](#360)
### [0361_轰炸敌人 🔒](#361)
#### [数组](#361)
#### [动态规划](#361)
#### [矩阵](#361)
### [0362_敲击计数器 🔒](#362)
#### [设计](#362)
#### [队列](#362)
#### [数组](#362)
#### [二分查找](#362)
#### [数据流](#362)
### [0363_矩形区域不超过 K 的最大数值和](#363)
#### [数组](#363)
#### [二分查找](#363)
#### [矩阵](#363)
#### [有序集合](#363)
#### [前缀和](#363)
### [0364_嵌套列表加权和 II 🔒](#364)
#### [栈](#364)
#### [深度优先搜索](#364)
#### [广度优先搜索](#364)
### [0365_水壶问题](#365)
#### [深度优先搜索](#365)
#### [广度优先搜索](#365)
#### [数学](#365)
### [0366_寻找二叉树的叶子节点 🔒](#366)
#### [树](#366)
#### [深度优先搜索](#366)
#### [二叉树](#366)
### [0367_有效的完全平方数](#367)
#### [数学](#367)
#### [二分查找](#367)
### [0368_最大整除子集](#368)
#### [数组](#368)
#### [数学](#368)
#### [动态规划](#368)
#### [排序](#368)
### [0369_给单链表加一 🔒](#369)
#### [链表](#369)
#### [数学](#369)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0360_有序转化数组 🔒
___
#### 数组
___
#### 数学
___
#### 双指针
___
#### 排序
---
### 0361_轰炸敌人 🔒
___
#### 数组
___
#### 动态规划
___
#### 矩阵
---
### 0362_敲击计数器 🔒
___
#### 设计
___
#### 队列
___
#### 数组
___
#### 二分查找
___
#### 数据流
---
### 0363_矩形区域不超过 K 的最大数值和
___
#### 数组
___
#### 二分查找
___
#### 矩阵
___
#### 有序集合
___
#### 前缀和
---
### 0364_嵌套列表加权和 II 🔒
___
#### 栈
___
#### 深度优先搜索
___
#### 广度优先搜索
---
### 0365_水壶问题
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 数学
---
### 0366_寻找二叉树的叶子节点 🔒
___
#### 树
___
#### 深度优先搜索
___
#### 二叉树
---
### 0367_有效的完全平方数
___
#### 数学
___
#### 二分查找
---
### 0368_最大整除子集
___
#### 数组
___
#### 数学
___
#### 动态规划
___
#### 排序
---
### 0369_给单链表加一 🔒
___
#### 链表
___
#### 数学
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 二叉树 | 前缀和 |
| 动态规划 | 双指针 | 广度优先搜索 |
| 排序 | 数学 | 数据流 |
| 数组 | 有序集合 | 栈 |
| 树 | 深度优先搜索 | 矩阵 |
| 设计 | 链表 | 队列 |

# [360. 有序转化数组 🔒](https://leetcode.cn/problems/sort-transformed-array){#360}

{{< tabs "360" >}}

{{% tab "python" %}}
```python
class Solution:
    def sortTransformedArray(
        self, nums: List[int], a: int, b: int, c: int
    ) -> List[int]:
        def f(x):
            return a * x * x + b * x + c

        n = len(nums)
        i, j, k = 0, n - 1, 0 if a < 0 else n - 1
        res = [0] * n
        while i <= j:
            v1, v2 = f(nums[i]), f(nums[j])
            if a < 0:
                if v1 <= v2:
                    res[k] = v1
                    i += 1
                else:
                    res[k] = v2
                    j -= 1
                k += 1
            else:
                if v1 >= v2:
                    res[k] = v1
                    i += 1
                else:
                    res[k] = v2
                    j -= 1
                k -= 1
        return res
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] sortTransformedArray(int[] nums, int a, int b, int c) {
        int n = nums.length;
        int i = 0, j = n - 1, k = a < 0 ? 0 : n - 1;
        int[] res = new int[n];
        while (i <= j) {
            int v1 = f(a, b, c, nums[i]), v2 = f(a, b, c, nums[j]);
            if (a < 0) {
                if (v1 <= v2) {
                    res[k] = v1;
                    ++i;
                } else {
                    res[k] = v2;
                    --j;
                }
                ++k;
            } else {
                if (v1 >= v2) {
                    res[k] = v1;
                    ++i;
                } else {
                    res[k] = v2;
                    --j;
                }
                --k;
            }
        }
        return res;
    }

    private int f(int a, int b, int c, int x) {
        return a * x * x + b * x + c;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int n = nums.size();
        int i = 0, j = n - 1, k = a < 0 ? 0 : n - 1;
        vector<int> res(n);
        while (i <= j) {
            int v1 = f(a, b, c, nums[i]), v2 = f(a, b, c, nums[j]);
            if (a < 0) {
                if (v1 <= v2) {
                    res[k] = v1;
                    ++i;
                } else {
                    res[k] = v2;
                    --j;
                }
                ++k;
            } else {
                if (v1 >= v2) {
                    res[k] = v1;
                    ++i;
                } else {
                    res[k] = v2;
                    --j;
                }
                --k;
            }
        }
        return res;
    }

    int f(int a, int b, int c, int x) {
        return a * x * x + b * x + c;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func sortTransformedArray(nums []int, a int, b int, c int) []int {
	n := len(nums)
	i, j, k := 0, n-1, 0
	if a >= 0 {
		k = n - 1
	}
	res := make([]int, n)
	for i <= j {
		v1, v2 := f(a, b, c, nums[i]), f(a, b, c, nums[j])
		if a < 0 {
			if v1 <= v2 {
				res[k] = v1
				i++
			} else {
				res[k] = v2
				j--
			}
			k++
		} else {
			if v1 >= v2 {
				res[k] = v1
				i++
			} else {
				res[k] = v2
				j--
			}
			k--
		}
	}
	return res
}

func f(a, b, c, x int) int {
	return a*x*x + b*x + c
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个已经<strong>&nbsp;排好序</strong>&nbsp;的整数数组&nbsp;<code>nums</code>&nbsp;和整数&nbsp;<code>a</code>&nbsp;、&nbsp;<code>b</code>&nbsp;、&nbsp;<code>c</code>&nbsp;。对于数组中的每一个元素&nbsp;<code>nums[i]</code>&nbsp;，计算函数值&nbsp;<code>f(<em>x</em>) = <em>ax</em><sup>2</sup> + <em>bx</em> + c</code>&nbsp;，请 <em>按升序返回数组</em> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入: </strong>nums = [-4,-2,2,4], a = 1, b = 3, c = 5
<strong>输出: </strong>[3,9,15,33]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入: </strong>nums = [-4,-2,2,4], a = -1, b = 3, c = 5
<strong>输出: </strong>[-23,-5,1,7]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 200</code></li>
	<li><code>-100 &lt;= nums[i], a, b, c &lt;= 100</code></li>
	<li><code>nums</code>&nbsp;按照 <strong>升序排列</strong></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>你可以在时间复杂度为&nbsp;<code>O(n)</code>&nbsp;的情况下解决这个问题吗？</p>

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
    def sortTransformedArray(
        self, nums: List[int], a: int, b: int, c: int
    ) -> List[int]:
        def f(x):
            return a * x * x + b * x + c

        n = len(nums)
        i, j, k = 0, n - 1, 0 if a < 0 else n - 1
        res = [0] * n
        while i <= j:
            v1, v2 = f(nums[i]), f(nums[j])
            if a < 0:
                if v1 <= v2:
                    res[k] = v1
                    i += 1
                else:
                    res[k] = v2
                    j -= 1
                k += 1
            else:
                if v1 >= v2:
                    res[k] = v1
                    i += 1
                else:
                    res[k] = v2
                    j -= 1
                k -= 1
        return res
```

#### Java

```java
class Solution {
    public int[] sortTransformedArray(int[] nums, int a, int b, int c) {
        int n = nums.length;
        int i = 0, j = n - 1, k = a < 0 ? 0 : n - 1;
        int[] res = new int[n];
        while (i <= j) {
            int v1 = f(a, b, c, nums[i]), v2 = f(a, b, c, nums[j]);
            if (a < 0) {
                if (v1 <= v2) {
                    res[k] = v1;
                    ++i;
                } else {
                    res[k] = v2;
                    --j;
                }
                ++k;
            } else {
                if (v1 >= v2) {
                    res[k] = v1;
                    ++i;
                } else {
                    res[k] = v2;
                    --j;
                }
                --k;
            }
        }
        return res;
    }

    private int f(int a, int b, int c, int x) {
        return a * x * x + b * x + c;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int n = nums.size();
        int i = 0, j = n - 1, k = a < 0 ? 0 : n - 1;
        vector<int> res(n);
        while (i <= j) {
            int v1 = f(a, b, c, nums[i]), v2 = f(a, b, c, nums[j]);
            if (a < 0) {
                if (v1 <= v2) {
                    res[k] = v1;
                    ++i;
                } else {
                    res[k] = v2;
                    --j;
                }
                ++k;
            } else {
                if (v1 >= v2) {
                    res[k] = v1;
                    ++i;
                } else {
                    res[k] = v2;
                    --j;
                }
                --k;
            }
        }
        return res;
    }

    int f(int a, int b, int c, int x) {
        return a * x * x + b * x + c;
    }
};
```

#### Go

```go
func sortTransformedArray(nums []int, a int, b int, c int) []int {
	n := len(nums)
	i, j, k := 0, n-1, 0
	if a >= 0 {
		k = n - 1
	}
	res := make([]int, n)
	for i <= j {
		v1, v2 := f(a, b, c, nums[i]), f(a, b, c, nums[j])
		if a < 0 {
			if v1 <= v2 {
				res[k] = v1
				i++
			} else {
				res[k] = v2
				j--
			}
			k++
		} else {
			if v1 >= v2 {
				res[k] = v1
				i++
			} else {
				res[k] = v2
				j--
			}
			k--
		}
	}
	return res
}

func f(a, b, c, x int) int {
	return a*x*x + b*x + c
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [361. 轰炸敌人 🔒](https://leetcode.cn/problems/bomb-enemy){#361}

{{< tabs "361" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxKilledEnemies(self, grid: List[List[str]]) -> int:
        m, n = len(grid), len(grid[0])
        g = [[0] * n for _ in range(m)]
        for i in range(m):
            t = 0
            for j in range(n):
                if grid[i][j] == 'W':
                    t = 0
                elif grid[i][j] == 'E':
                    t += 1
                g[i][j] += t
            t = 0
            for j in range(n - 1, -1, -1):
                if grid[i][j] == 'W':
                    t = 0
                elif grid[i][j] == 'E':
                    t += 1
                g[i][j] += t
        for j in range(n):
            t = 0
            for i in range(m):
                if grid[i][j] == 'W':
                    t = 0
                elif grid[i][j] == 'E':
                    t += 1
                g[i][j] += t
            t = 0
            for i in range(m - 1, -1, -1):
                if grid[i][j] == 'W':
                    t = 0
                elif grid[i][j] == 'E':
                    t += 1
                g[i][j] += t
        return max(
            [g[i][j] for i in range(m) for j in range(n) if grid[i][j] == '0'],
            default=0,
        )
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxKilledEnemies(char[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int[][] g = new int[m][n];
        for (int i = 0; i < m; ++i) {
            int t = 0;
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 'W') {
                    t = 0;
                } else if (grid[i][j] == 'E') {
                    ++t;
                }
                g[i][j] += t;
            }
            t = 0;
            for (int j = n - 1; j >= 0; --j) {
                if (grid[i][j] == 'W') {
                    t = 0;
                } else if (grid[i][j] == 'E') {
                    ++t;
                }
                g[i][j] += t;
            }
        }
        for (int j = 0; j < n; ++j) {
            int t = 0;
            for (int i = 0; i < m; ++i) {
                if (grid[i][j] == 'W') {
                    t = 0;
                } else if (grid[i][j] == 'E') {
                    ++t;
                }
                g[i][j] += t;
            }
            t = 0;
            for (int i = m - 1; i >= 0; --i) {
                if (grid[i][j] == 'W') {
                    t = 0;
                } else if (grid[i][j] == 'E') {
                    ++t;
                }
                g[i][j] += t;
            }
        }
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '0') {
                    ans = Math.max(ans, g[i][j]);
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
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> g(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            int t = 0;
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 'W')
                    t = 0;
                else if (grid[i][j] == 'E')
                    ++t;
                g[i][j] += t;
            }
            t = 0;
            for (int j = n - 1; j >= 0; --j) {
                if (grid[i][j] == 'W')
                    t = 0;
                else if (grid[i][j] == 'E')
                    ++t;
                g[i][j] += t;
            }
        }
        for (int j = 0; j < n; ++j) {
            int t = 0;
            for (int i = 0; i < m; ++i) {
                if (grid[i][j] == 'W')
                    t = 0;
                else if (grid[i][j] == 'E')
                    ++t;
                g[i][j] += t;
            }
            t = 0;
            for (int i = m - 1; i >= 0; --i) {
                if (grid[i][j] == 'W')
                    t = 0;
                else if (grid[i][j] == 'E')
                    ++t;
                g[i][j] += t;
            }
        }
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '0') ans = max(ans, g[i][j]);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxKilledEnemies(grid [][]byte) int {
	m, n := len(grid), len(grid[0])
	g := make([][]int, m)
	for i := range g {
		g[i] = make([]int, n)
	}
	for i := 0; i < m; i++ {
		t := 0
		for j := 0; j < n; j++ {
			if grid[i][j] == 'W' {
				t = 0
			} else if grid[i][j] == 'E' {
				t++
			}
			g[i][j] += t
		}
		t = 0
		for j := n - 1; j >= 0; j-- {
			if grid[i][j] == 'W' {
				t = 0
			} else if grid[i][j] == 'E' {
				t++
			}
			g[i][j] += t
		}
	}
	for j := 0; j < n; j++ {
		t := 0
		for i := 0; i < m; i++ {
			if grid[i][j] == 'W' {
				t = 0
			} else if grid[i][j] == 'E' {
				t++
			}
			g[i][j] += t
		}
		t = 0
		for i := m - 1; i >= 0; i-- {
			if grid[i][j] == 'W' {
				t = 0
			} else if grid[i][j] == 'E' {
				t++
			}
			g[i][j] += t
		}
	}
	ans := 0
	for i, row := range grid {
		for j, v := range row {
			if v == '0' && ans < g[i][j] {
				ans = g[i][j]
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

<p>给你一个大小为 <code>m x n</code> 的矩阵 <code>grid</code> ，其中每个单元格都放置有一个字符：</p>

<ul>
	<li><code>'W'</code>&nbsp;表示一堵墙</li>
	<li><code>'E'</code>&nbsp;表示一个敌人</li>
	<li><code>'0'</code>（数字 0）表示一个空位</li>
</ul>

<p>返回你使用 <strong>一颗炸弹</strong> 可以击杀的最大敌人数目。你只能把炸弹放在一个空位里。</p>

<p>由于炸弹的威力不足以穿透墙体，炸弹只能击杀同一行和同一列没被墙体挡住的敌人。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0300-0399/0361.Bomb%20Enemy/images/bomb1-grid.jpg" style="width: 600px; height: 187px;" />
<pre>
<strong>输入：</strong>grid = [["0","E","0","0"],["E","0","W","E"],["0","E","0","0"]]
<strong>输出：</strong>3
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0300-0399/0361.Bomb%20Enemy/images/bomb2-grid.jpg" style="width: 500px; height: 194px;" />
<pre>
<strong>输入：</strong>grid = [["W","W","W"],["0","0","0"],["E","E","E"]]
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 500</code></li>
	<li><code>grid[i][j]</code> 可以是 <code>'W'</code>、<code>'E'</code> 或 <code>'0'</code></li>
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
    def maxKilledEnemies(self, grid: List[List[str]]) -> int:
        m, n = len(grid), len(grid[0])
        g = [[0] * n for _ in range(m)]
        for i in range(m):
            t = 0
            for j in range(n):
                if grid[i][j] == 'W':
                    t = 0
                elif grid[i][j] == 'E':
                    t += 1
                g[i][j] += t
            t = 0
            for j in range(n - 1, -1, -1):
                if grid[i][j] == 'W':
                    t = 0
                elif grid[i][j] == 'E':
                    t += 1
                g[i][j] += t
        for j in range(n):
            t = 0
            for i in range(m):
                if grid[i][j] == 'W':
                    t = 0
                elif grid[i][j] == 'E':
                    t += 1
                g[i][j] += t
            t = 0
            for i in range(m - 1, -1, -1):
                if grid[i][j] == 'W':
                    t = 0
                elif grid[i][j] == 'E':
                    t += 1
                g[i][j] += t
        return max(
            [g[i][j] for i in range(m) for j in range(n) if grid[i][j] == '0'],
            default=0,
        )
```

#### Java

```java
class Solution {
    public int maxKilledEnemies(char[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int[][] g = new int[m][n];
        for (int i = 0; i < m; ++i) {
            int t = 0;
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 'W') {
                    t = 0;
                } else if (grid[i][j] == 'E') {
                    ++t;
                }
                g[i][j] += t;
            }
            t = 0;
            for (int j = n - 1; j >= 0; --j) {
                if (grid[i][j] == 'W') {
                    t = 0;
                } else if (grid[i][j] == 'E') {
                    ++t;
                }
                g[i][j] += t;
            }
        }
        for (int j = 0; j < n; ++j) {
            int t = 0;
            for (int i = 0; i < m; ++i) {
                if (grid[i][j] == 'W') {
                    t = 0;
                } else if (grid[i][j] == 'E') {
                    ++t;
                }
                g[i][j] += t;
            }
            t = 0;
            for (int i = m - 1; i >= 0; --i) {
                if (grid[i][j] == 'W') {
                    t = 0;
                } else if (grid[i][j] == 'E') {
                    ++t;
                }
                g[i][j] += t;
            }
        }
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '0') {
                    ans = Math.max(ans, g[i][j]);
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
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> g(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            int t = 0;
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 'W')
                    t = 0;
                else if (grid[i][j] == 'E')
                    ++t;
                g[i][j] += t;
            }
            t = 0;
            for (int j = n - 1; j >= 0; --j) {
                if (grid[i][j] == 'W')
                    t = 0;
                else if (grid[i][j] == 'E')
                    ++t;
                g[i][j] += t;
            }
        }
        for (int j = 0; j < n; ++j) {
            int t = 0;
            for (int i = 0; i < m; ++i) {
                if (grid[i][j] == 'W')
                    t = 0;
                else if (grid[i][j] == 'E')
                    ++t;
                g[i][j] += t;
            }
            t = 0;
            for (int i = m - 1; i >= 0; --i) {
                if (grid[i][j] == 'W')
                    t = 0;
                else if (grid[i][j] == 'E')
                    ++t;
                g[i][j] += t;
            }
        }
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '0') ans = max(ans, g[i][j]);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func maxKilledEnemies(grid [][]byte) int {
	m, n := len(grid), len(grid[0])
	g := make([][]int, m)
	for i := range g {
		g[i] = make([]int, n)
	}
	for i := 0; i < m; i++ {
		t := 0
		for j := 0; j < n; j++ {
			if grid[i][j] == 'W' {
				t = 0
			} else if grid[i][j] == 'E' {
				t++
			}
			g[i][j] += t
		}
		t = 0
		for j := n - 1; j >= 0; j-- {
			if grid[i][j] == 'W' {
				t = 0
			} else if grid[i][j] == 'E' {
				t++
			}
			g[i][j] += t
		}
	}
	for j := 0; j < n; j++ {
		t := 0
		for i := 0; i < m; i++ {
			if grid[i][j] == 'W' {
				t = 0
			} else if grid[i][j] == 'E' {
				t++
			}
			g[i][j] += t
		}
		t = 0
		for i := m - 1; i >= 0; i-- {
			if grid[i][j] == 'W' {
				t = 0
			} else if grid[i][j] == 'E' {
				t++
			}
			g[i][j] += t
		}
	}
	ans := 0
	for i, row := range grid {
		for j, v := range row {
			if v == '0' && ans < g[i][j] {
				ans = g[i][j]
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

# [362. 敲击计数器 🔒](https://leetcode.cn/problems/design-hit-counter){#362}

{{< tabs "362" >}}

{{% tab "python" %}}
```python
class HitCounter:

    def __init__(self):
        self.ts = []

    def hit(self, timestamp: int) -> None:
        self.ts.append(timestamp)

    def getHits(self, timestamp: int) -> int:
        return len(self.ts) - bisect_left(self.ts, timestamp - 300 + 1)


# Your HitCounter object will be instantiated and called as such:
# obj = HitCounter()
# obj.hit(timestamp)
# param_2 = obj.getHits(timestamp)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class HitCounter {
    private List<Integer> ts = new ArrayList<>();

    public HitCounter() {
    }

    public void hit(int timestamp) {
        ts.add(timestamp);
    }

    public int getHits(int timestamp) {
        int l = search(timestamp - 300 + 1);
        return ts.size() - l;
    }

    private int search(int x) {
        int l = 0, r = ts.size();
        while (l < r) {
            int mid = (l + r) >> 1;
            if (ts.get(mid) >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
}

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class HitCounter {
public:
    HitCounter() {

    }

    void hit(int timestamp) {
        ts.push_back(timestamp);
    }

    int getHits(int timestamp) {
        return ts.end() - lower_bound(ts.begin(), ts.end(), timestamp - 300 + 1);
    }

private:
    vector<int> ts;
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type HitCounter struct {
	ts []int
}

func Constructor() HitCounter {
	return HitCounter{}
}

func (this *HitCounter) Hit(timestamp int) {
	this.ts = append(this.ts, timestamp)
}

func (this *HitCounter) GetHits(timestamp int) int {
	return len(this.ts) - sort.SearchInts(this.ts, timestamp-300+1)
}

/**
 * Your HitCounter object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Hit(timestamp);
 * param_2 := obj.GetHits(timestamp);
 */
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class HitCounter {
    private ts: number[] = [];

    constructor() {}

    hit(timestamp: number): void {
        this.ts.push(timestamp);
    }

    getHits(timestamp: number): number {
        const search = (x: number) => {
            let [l, r] = [0, this.ts.length];
            while (l < r) {
                const mid = (l + r) >> 1;
                if (this.ts[mid] >= x) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            return l;
        };
        return this.ts.length - search(timestamp - 300 + 1);
    }
}

/**
 * Your HitCounter object will be instantiated and called as such:
 * var obj = new HitCounter()
 * obj.hit(timestamp)
 * var param_2 = obj.getHits(timestamp)
 */
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
struct HitCounter {
    ts: Vec<i32>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl HitCounter {
    fn new() -> Self {
        HitCounter { ts: Vec::new() }
    }

    fn hit(&mut self, timestamp: i32) {
        self.ts.push(timestamp);
    }

    fn get_hits(&self, timestamp: i32) -> i32 {
        let l = self.search(timestamp - 300 + 1);
        (self.ts.len() - l) as i32
    }

    fn search(&self, x: i32) -> usize {
        let (mut l, mut r) = (0, self.ts.len());
        while l < r {
            let mid = (l + r) / 2;
            if self.ts[mid] >= x {
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

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>设计一个敲击计数器，使它可以统计在过去 <code>5</code> 分钟内被敲击次数。（即过去 <code>300</code> 秒）</p>

<p>您的系统应该接受一个时间戳参数&nbsp;<code>timestamp</code>&nbsp;(单位为 <strong>秒</strong>&nbsp;)，并且您可以假定对系统的调用是按时间顺序进行的(即&nbsp;<code>timestamp</code>&nbsp;是单调递增的)。几次撞击可能同时发生。</p>

<p>实现&nbsp;<code>HitCounter</code>&nbsp;类:</p>

<ul>
	<li><code>HitCounter()</code>&nbsp;初始化命中计数器系统。</li>
	<li><code>void hit(int timestamp)</code>&nbsp;记录在&nbsp;<code>timestamp</code>&nbsp;(&nbsp;<strong>单位为秒</strong>&nbsp;)发生的一次命中。在同一个&nbsp;<code>timestamp</code>&nbsp;中可能会出现几个点击。</li>
	<li><code>int getHits(int timestamp)</code>&nbsp;返回&nbsp;<code>timestamp</code>&nbsp;在过去 5 分钟内(即过去 <code>300</code> 秒)的命中次数。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入：</strong>
["HitCounter", "hit", "hit", "hit", "getHits", "hit", "getHits", "getHits"]
[[], [1], [2], [3], [4], [300], [300], [301]]
<strong>输出：</strong>
[null, null, null, null, 3, null, 4, 3]

<strong>解释：</strong>
HitCounter counter = new HitCounter();
counter.hit(1);// 在时刻 1 敲击一次。
counter.hit(2);// 在时刻 2 敲击一次。
counter.hit(3);// 在时刻 3 敲击一次。
counter.getHits(4);// 在时刻 4 统计过去 5 分钟内的敲击次数, 函数返回 3 。
counter.hit(300);// 在时刻 300 敲击一次。
counter.getHits(300); // 在时刻 300 统计过去 5 分钟内的敲击次数，函数返回 4 。
counter.getHits(301); // 在时刻 301 统计过去 5 分钟内的敲击次数，函数返回 3 。
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= timestamp &lt;= 2 * 10<sup>9</sup></code></li>
	<li>所有对系统的调用都是按时间顺序进行的（即&nbsp;<code>timestamp</code>&nbsp;是单调递增的）</li>
	<li><code>hit</code>&nbsp;and&nbsp;<code>getHits&nbsp;</code>最多被调用&nbsp;<code>300</code>&nbsp;次</li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶:</strong>&nbsp;如果每秒的敲击次数是一个很大的数字，你的计数器可以应对吗？</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二分查找

由于 `timestamp` 是单调递增的，我们可以使用一个数组 `ts` 来存储所有的 `timestamp`，然后在 `getHits` 方法中使用二分查找找到第一个大于等于 `timestamp - 300 + 1` 的位置，然后返回 `ts` 的长度减去这个位置即可。

时间复杂度方面，`hit` 方法的时间复杂度为 $O(1)$，`getHits` 方法的时间复杂度为 $O(\log n)$。其中 $n$ 为 `ts` 的长度。

<!-- tabs:start -->

#### Python3

```python
class HitCounter:

    def __init__(self):
        self.ts = []

    def hit(self, timestamp: int) -> None:
        self.ts.append(timestamp)

    def getHits(self, timestamp: int) -> int:
        return len(self.ts) - bisect_left(self.ts, timestamp - 300 + 1)


# Your HitCounter object will be instantiated and called as such:
# obj = HitCounter()
# obj.hit(timestamp)
# param_2 = obj.getHits(timestamp)
```

#### Java

```java
class HitCounter {
    private List<Integer> ts = new ArrayList<>();

    public HitCounter() {
    }

    public void hit(int timestamp) {
        ts.add(timestamp);
    }

    public int getHits(int timestamp) {
        int l = search(timestamp - 300 + 1);
        return ts.size() - l;
    }

    private int search(int x) {
        int l = 0, r = ts.size();
        while (l < r) {
            int mid = (l + r) >> 1;
            if (ts.get(mid) >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
}

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */
```

#### C++

```cpp
class HitCounter {
public:
    HitCounter() {

    }

    void hit(int timestamp) {
        ts.push_back(timestamp);
    }

    int getHits(int timestamp) {
        return ts.end() - lower_bound(ts.begin(), ts.end(), timestamp - 300 + 1);
    }

private:
    vector<int> ts;
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */
```

#### Go

```go
type HitCounter struct {
	ts []int
}

func Constructor() HitCounter {
	return HitCounter{}
}

func (this *HitCounter) Hit(timestamp int) {
	this.ts = append(this.ts, timestamp)
}

func (this *HitCounter) GetHits(timestamp int) int {
	return len(this.ts) - sort.SearchInts(this.ts, timestamp-300+1)
}

/**
 * Your HitCounter object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Hit(timestamp);
 * param_2 := obj.GetHits(timestamp);
 */
```

#### TypeScript

```ts
class HitCounter {
    private ts: number[] = [];

    constructor() {}

    hit(timestamp: number): void {
        this.ts.push(timestamp);
    }

    getHits(timestamp: number): number {
        const search = (x: number) => {
            let [l, r] = [0, this.ts.length];
            while (l < r) {
                const mid = (l + r) >> 1;
                if (this.ts[mid] >= x) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            return l;
        };
        return this.ts.length - search(timestamp - 300 + 1);
    }
}

/**
 * Your HitCounter object will be instantiated and called as such:
 * var obj = new HitCounter()
 * obj.hit(timestamp)
 * var param_2 = obj.getHits(timestamp)
 */
```

#### Rust

```rust
struct HitCounter {
    ts: Vec<i32>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl HitCounter {
    fn new() -> Self {
        HitCounter { ts: Vec::new() }
    }

    fn hit(&mut self, timestamp: i32) {
        self.ts.push(timestamp);
    }

    fn get_hits(&self, timestamp: i32) -> i32 {
        let l = self.search(timestamp - 300 + 1);
        (self.ts.len() - l) as i32
    }

    fn search(&self, x: i32) -> usize {
        let (mut l, mut r) = (0, self.ts.len());
        while l < r {
            let mid = (l + r) / 2;
            if self.ts[mid] >= x {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        l
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [363. 矩形区域不超过 K 的最大数值和](https://leetcode.cn/problems/max-sum-of-rectangle-no-larger-than-k){#363}

{{< tabs "363" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxSumSubmatrix(self, matrix: List[List[int]], k: int) -> int:
        m, n = len(matrix), len(matrix[0])
        ans = -inf
        for i in range(m):
            nums = [0] * n
            for j in range(i, m):
                for h in range(n):
                    nums[h] += matrix[j][h]
                s = 0
                ts = SortedSet([0])
                for x in nums:
                    s += x
                    p = ts.bisect_left(s - k)
                    if p != len(ts):
                        ans = max(ans, s - ts[p])
                    ts.add(s)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxSumSubmatrix(int[][] matrix, int k) {
        int m = matrix.length;
        int n = matrix[0].length;
        final int inf = 1 << 30;
        int ans = -inf;
        for (int i = 0; i < m; ++i) {
            int[] nums = new int[n];
            for (int j = i; j < m; ++j) {
                for (int h = 0; h < n; ++h) {
                    nums[h] += matrix[j][h];
                }
                int s = 0;
                TreeSet<Integer> ts = new TreeSet<>();
                ts.add(0);
                for (int x : nums) {
                    s += x;
                    Integer y = ts.ceiling(s - k);
                    if (y != null) {
                        ans = Math.max(ans, s - y);
                    }
                    ts.add(s);
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
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        const int inf = 1 << 30;
        int ans = -inf;
        for (int i = 0; i < m; ++i) {
            vector<int> nums(n);
            for (int j = i; j < m; ++j) {
                for (int h = 0; h < n; ++h) {
                    nums[h] += matrix[j][h];
                }
                set<int> ts;
                int s = 0;
                ts.insert(0);
                for (int x : nums) {
                    s += x;
                    auto it = ts.lower_bound(s - k);
                    if (it != ts.end()) {
                        ans = max(ans, s - *it);
                    }
                    ts.insert(s);
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
func maxSumSubmatrix(matrix [][]int, k int) int {
	m, n := len(matrix), len(matrix[0])
	const inf = 1 << 30
	ans := -inf
	for i := 0; i < m; i++ {
		nums := make([]int, n)
		for j := i; j < m; j++ {
			for h := 0; h < n; h++ {
				nums[h] += matrix[j][h]
			}
			s := 0
			rbt := redblacktree.NewWithIntComparator()
			rbt.Put(0, nil)
			for _, x := range nums {
				s += x
				if y, ok := rbt.Ceiling(s - k); ok {
					ans = max(ans, s-y.Key.(int))
				}
				rbt.Put(s, nil)
			}
		}

	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxSumSubmatrix(matrix: number[][], k: number): number {
    const m = matrix.length;
    const n = matrix[0].length;
    let ans = -Infinity;
    for (let i = 0; i < m; ++i) {
        const nums: number[] = new Array(n).fill(0);
        for (let j = i; j < m; ++j) {
            for (let h = 0; h < n; ++h) {
                nums[h] += matrix[j][h];
            }
            let s = 0;
            const ts: TreeSet<number> = new TreeSet<number>();
            ts.add(0);
            for (const x of nums) {
                s += x;
                const p = ts.ceil(s - k);
                if (p !== undefined) {
                    ans = Math.max(ans, s - p);
                }
                ts.add(s);
            }
        }
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

class TreeMultiSet<T = number> {
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
        this._size++;
        return successful;
    }

    delete(val: T): boolean {
        const successful = this.tree.delete(val);
        if (!successful) return false;
        this._size--;
        return true;
    }

    count(val: T): number {
        const node = this.tree.find(val);
        return node ? node.count : 0;
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
        yield* this.values();
    }

    *keys(): Generator<T, void, void> {
        for (const val of this.values()) yield val;
    }

    *values(): Generator<T, undefined, void> {
        for (const val of this.tree.inOrder()) {
            let count = this.count(val);
            while (count--) yield val;
        }
        return undefined;
    }

    /**
     * Return a generator for reverse order traversing the multi-set
     */
    *rvalues(): Generator<T, undefined, void> {
        for (const val of this.tree.reverseInOrder()) {
            let count = this.count(val);
            while (count--) yield val;
        }
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

<p>给你一个 <code>m x n</code> 的矩阵 <code>matrix</code> 和一个整数 <code>k</code> ，找出并返回矩阵内部矩形区域的不超过 <code>k</code> 的最大数值和。</p>

<p>题目数据保证总会存在一个数值和不超过 <code>k</code> 的矩形区域。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0300-0399/0363.Max%20Sum%20of%20Rectangle%20No%20Larger%20Than%20K/images/sum-grid.jpg" style="width: 255px; height: 176px;" />
<pre>
<strong>输入：</strong>matrix = [[1,0,1],[0,-2,3]], k = 2
<strong>输出：</strong>2
<strong>解释：</strong>蓝色边框圈出来的矩形区域 <code>[[0, 1], [-2, 3]]</code> 的数值和是 2，且 2 是不超过 k 的最大数字（k = 2）。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>matrix = [[2,2,-1]], k = 3
<strong>输出：</strong>3
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == matrix.length</code></li>
	<li><code>n == matrix[i].length</code></li>
	<li><code>1 <= m, n <= 100</code></li>
	<li><code>-100 <= matrix[i][j] <= 100</code></li>
	<li><code>-10<sup>5</sup> <= k <= 10<sup>5</sup></code></li>
</ul>

<p> </p>

<p><strong>进阶：</strong>如果行数远大于列数，该如何设计解决方案？</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举边界 + 有序集合

我们可以枚举矩形的上下边界 $i$ 和 $j$，然后计算出该边界内每列的元素和，记录在数组 $nums$ 中，问题转化为如何在数组 $nums$ 中寻找不超过 $k$ 的最大子数组和。

我们可以使用有序集合来快速寻找小于等于 $x$ 的最大值，从而得到最大子数组和不超过 $k$ 的子数组。

时间复杂度 $O(m^2 \times n \times \log n)$，空间复杂度 $O(n)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxSumSubmatrix(self, matrix: List[List[int]], k: int) -> int:
        m, n = len(matrix), len(matrix[0])
        ans = -inf
        for i in range(m):
            nums = [0] * n
            for j in range(i, m):
                for h in range(n):
                    nums[h] += matrix[j][h]
                s = 0
                ts = SortedSet([0])
                for x in nums:
                    s += x
                    p = ts.bisect_left(s - k)
                    if p != len(ts):
                        ans = max(ans, s - ts[p])
                    ts.add(s)
        return ans
```

#### Java

```java
class Solution {
    public int maxSumSubmatrix(int[][] matrix, int k) {
        int m = matrix.length;
        int n = matrix[0].length;
        final int inf = 1 << 30;
        int ans = -inf;
        for (int i = 0; i < m; ++i) {
            int[] nums = new int[n];
            for (int j = i; j < m; ++j) {
                for (int h = 0; h < n; ++h) {
                    nums[h] += matrix[j][h];
                }
                int s = 0;
                TreeSet<Integer> ts = new TreeSet<>();
                ts.add(0);
                for (int x : nums) {
                    s += x;
                    Integer y = ts.ceiling(s - k);
                    if (y != null) {
                        ans = Math.max(ans, s - y);
                    }
                    ts.add(s);
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
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        const int inf = 1 << 30;
        int ans = -inf;
        for (int i = 0; i < m; ++i) {
            vector<int> nums(n);
            for (int j = i; j < m; ++j) {
                for (int h = 0; h < n; ++h) {
                    nums[h] += matrix[j][h];
                }
                set<int> ts;
                int s = 0;
                ts.insert(0);
                for (int x : nums) {
                    s += x;
                    auto it = ts.lower_bound(s - k);
                    if (it != ts.end()) {
                        ans = max(ans, s - *it);
                    }
                    ts.insert(s);
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func maxSumSubmatrix(matrix [][]int, k int) int {
	m, n := len(matrix), len(matrix[0])
	const inf = 1 << 30
	ans := -inf
	for i := 0; i < m; i++ {
		nums := make([]int, n)
		for j := i; j < m; j++ {
			for h := 0; h < n; h++ {
				nums[h] += matrix[j][h]
			}
			s := 0
			rbt := redblacktree.NewWithIntComparator()
			rbt.Put(0, nil)
			for _, x := range nums {
				s += x
				if y, ok := rbt.Ceiling(s - k); ok {
					ans = max(ans, s-y.Key.(int))
				}
				rbt.Put(s, nil)
			}
		}

	}
	return ans
}
```

#### TypeScript

```ts
function maxSumSubmatrix(matrix: number[][], k: number): number {
    const m = matrix.length;
    const n = matrix[0].length;
    let ans = -Infinity;
    for (let i = 0; i < m; ++i) {
        const nums: number[] = new Array(n).fill(0);
        for (let j = i; j < m; ++j) {
            for (let h = 0; h < n; ++h) {
                nums[h] += matrix[j][h];
            }
            let s = 0;
            const ts: TreeSet<number> = new TreeSet<number>();
            ts.add(0);
            for (const x of nums) {
                s += x;
                const p = ts.ceil(s - k);
                if (p !== undefined) {
                    ans = Math.max(ans, s - p);
                }
                ts.add(s);
            }
        }
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

class TreeMultiSet<T = number> {
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
        this._size++;
        return successful;
    }

    delete(val: T): boolean {
        const successful = this.tree.delete(val);
        if (!successful) return false;
        this._size--;
        return true;
    }

    count(val: T): number {
        const node = this.tree.find(val);
        return node ? node.count : 0;
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
        yield* this.values();
    }

    *keys(): Generator<T, void, void> {
        for (const val of this.values()) yield val;
    }

    *values(): Generator<T, undefined, void> {
        for (const val of this.tree.inOrder()) {
            let count = this.count(val);
            while (count--) yield val;
        }
        return undefined;
    }

    /**
     * Return a generator for reverse order traversing the multi-set
     */
    *rvalues(): Generator<T, undefined, void> {
        for (const val of this.tree.reverseInOrder()) {
            let count = this.count(val);
            while (count--) yield val;
        }
        return undefined;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [364. 嵌套列表加权和 II 🔒](https://leetcode.cn/problems/nested-list-weight-sum-ii){#364}

{{< tabs "364" >}}

{{% tab "python" %}}
```python
# """
# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation
# """
# class NestedInteger:
#    def __init__(self, value=None):
#        """
#        If value is not specified, initializes an empty list.
#        Otherwise initializes a single integer equal to value.
#        """
#
#    def isInteger(self):
#        """
#        @return True if this NestedInteger holds a single integer, rather than a nested list.
#        :rtype bool
#        """
#
#    def add(self, elem):
#        """
#        Set this NestedInteger to hold a nested list and adds a nested integer elem to it.
#        :rtype void
#        """
#
#    def setInteger(self, value):
#        """
#        Set this NestedInteger to hold a single integer equal to value.
#        :rtype void
#        """
#
#    def getInteger(self):
#        """
#        @return the single integer that this NestedInteger holds, if it holds a single integer
#        Return None if this NestedInteger holds a nested list
#        :rtype int
#        """
#
#    def getList(self):
#        """
#        @return the nested list that this NestedInteger holds, if it holds a nested list
#        Return None if this NestedInteger holds a single integer
#        :rtype List[NestedInteger]
#        """
class Solution:
    def depthSumInverse(self, nestedList: List[NestedInteger]) -> int:
        def dfs(x, d):
            nonlocal maxDepth, s, ws
            maxDepth = max(maxDepth, d)
            if x.isInteger():
                s += x.getInteger()
                ws += x.getInteger() * d
            else:
                for y in x.getList():
                    dfs(y, d + 1)

        maxDepth = s = ws = 0
        for x in nestedList:
            dfs(x, 1)
        return (maxDepth + 1) * s - ws
```
{{% /tab %}}
{{% tab "java" %}}
```java
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * public interface NestedInteger {
 *     // Constructor initializes an empty nested list.
 *     public NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     public NestedInteger(int value);
 *
 *     // @return true if this NestedInteger holds a single integer, rather than a nested list.
 *     public boolean isInteger();
 *
 *     // @return the single integer that this NestedInteger holds, if it holds a single integer
 *     // Return null if this NestedInteger holds a nested list
 *     public Integer getInteger();
 *
 *     // Set this NestedInteger to hold a single integer.
 *     public void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     public void add(NestedInteger ni);
 *
 *     // @return the nested list that this NestedInteger holds, if it holds a nested list
 *     // Return empty list if this NestedInteger holds a single integer
 *     public List<NestedInteger> getList();
 * }
 */
class Solution {
    private int maxDepth;
    private int ws;
    private int s;

    public int depthSumInverse(List<NestedInteger> nestedList) {
        for (NestedInteger x : nestedList) {
            dfs(x, 1);
        }
        return (maxDepth + 1) * s - ws;
    }

    private void dfs(NestedInteger x, int d) {
        maxDepth = Math.max(maxDepth, d);
        if (x.isInteger()) {
            ws += x.getInteger() * d;
            s += x.getInteger();
        } else {
            for (NestedInteger y : x.getList()) {
                dfs(y, d + 1);
            }
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int maxDepth = 0, ws = 0, s = 0;
        function<void(NestedInteger&, int)> dfs = [&](NestedInteger& x, int d) {
            maxDepth = max(maxDepth, d);
            if (x.isInteger()) {
                ws += x.getInteger() * d;
                s += x.getInteger();
            } else {
                for (auto& y : x.getList()) {
                    dfs(y, d + 1);
                }
            }
        };
        for (auto& x : nestedList) {
            dfs(x, 1);
        }
        return (maxDepth + 1) * s - ws;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * type NestedInteger struct {
 * }
 *
 * // Return true if this NestedInteger holds a single integer, rather than a nested list.
 * func (n NestedInteger) IsInteger() bool {}
 *
 * // Return the single integer that this NestedInteger holds, if it holds a single integer
 * // The result is undefined if this NestedInteger holds a nested list
 * // So before calling this method, you should have a check
 * func (n NestedInteger) GetInteger() int {}
 *
 * // Set this NestedInteger to hold a single integer.
 * func (n *NestedInteger) SetInteger(value int) {}
 *
 * // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 * func (n *NestedInteger) Add(elem NestedInteger) {}
 *
 * // Return the nested list that this NestedInteger holds, if it holds a nested list
 * // The list length is zero if this NestedInteger holds a single integer
 * // You can access NestedInteger's List element directly if you want to modify it
 * func (n NestedInteger) GetList() []*NestedInteger {}
 */
func depthSumInverse(nestedList []*NestedInteger) int {
	var maxDepth, ws, s int
	var dfs func(*NestedInteger, int)
	dfs = func(x *NestedInteger, d int) {
		maxDepth = max(maxDepth, d)
		if x.IsInteger() {
			ws += x.GetInteger() * d
			s += x.GetInteger()
		} else {
			for _, y := range x.GetList() {
				dfs(y, d+1)
			}
		}
	}
	for _, x := range nestedList {
		dfs(x, 1)
	}
	return (maxDepth+1)*s - ws
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *     If value is provided, then it holds a single integer
 *     Otherwise it holds an empty nested list
 *     constructor(value?: number) {
 *         ...
 *     };
 *
 *     Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     isInteger(): boolean {
 *         ...
 *     };
 *
 *     Return the single integer that this NestedInteger holds, if it holds a single integer
 *     Return null if this NestedInteger holds a nested list
 *     getInteger(): number | null {
 *         ...
 *     };
 *
 *     Set this NestedInteger to hold a single integer equal to value.
 *     setInteger(value: number) {
 *         ...
 *     };
 *
 *     Set this NestedInteger to hold a nested list and adds a nested integer elem to it.
 *     add(elem: NestedInteger) {
 *         ...
 *     };
 *
 *     Return the nested list that this NestedInteger holds,
 *     or an empty list if this NestedInteger holds a single integer
 *     getList(): NestedInteger[] {
 *         ...
 *     };
 * };
 */

function depthSumInverse(nestedList: NestedInteger[]): number {
    let [maxDepth, ws, s] = [0, 0, 0];
    const dfs = (x: NestedInteger, d: number) => {
        maxDepth = Math.max(maxDepth, d);
        if (x.isInteger()) {
            ws += x.getInteger() * d;
            s += x.getInteger();
        } else {
            for (const y of x.getList()) {
                dfs(y, d + 1);
            }
        }
    };
    for (const x of nestedList) {
        dfs(x, 1);
    }
    return (maxDepth + 1) * s - ws;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * function NestedInteger() {
 *
 *     Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     @return {boolean}
 *     this.isInteger = function() {
 *         ...
 *     };
 *
 *     Return the single integer that this NestedInteger holds, if it holds a single integer
 *     Return null if this NestedInteger holds a nested list
 *     @return {integer}
 *     this.getInteger = function() {
 *         ...
 *     };
 *
 *     Set this NestedInteger to hold a single integer equal to value.
 *     @return {void}
 *     this.setInteger = function(value) {
 *         ...
 *     };
 *
 *     Set this NestedInteger to hold a nested list and adds a nested integer elem to it.
 *     @return {void}
 *     this.add = function(elem) {
 *         ...
 *     };
 *
 *     Return the nested list that this NestedInteger holds, if it holds a nested list
 *     Return null if this NestedInteger holds a single integer
 *     @return {NestedInteger[]}
 *     this.getList = function() {
 *         ...
 *     };
 * };
 */
/**
 * @param {NestedInteger[]} nestedList
 * @return {number}
 */
var depthSumInverse = function (nestedList) {
    let [maxDepth, ws, s] = [0, 0, 0];
    const dfs = (x, d) => {
        maxDepth = Math.max(maxDepth, d);
        if (x.isInteger()) {
            ws += x.getInteger() * d;
            s += x.getInteger();
        } else {
            for (const y of x.getList()) {
                dfs(y, d + 1);
            }
        }
    };
    for (const x of nestedList) {
        dfs(x, 1);
    }
    return (maxDepth + 1) * s - ws;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数嵌套列表&nbsp;<code>nestedList</code> ，每一个元素要么是一个整数，要么是一个列表（这个列表中的每个元素也同样是整数或列表）。</p>

<p>整数的 <strong>深度</strong> 取决于它位于多少个列表内部。例如，嵌套列表 <code>[1,[2,2],[[3],2],1]</code> 的每个整数的值都等于它的 <strong>深度</strong> 。令 <code>maxDepth</code> 是任意整数的 <strong>最大深度</strong> 。</p>

<p>整数的 <strong>权重</strong> 为 <code>maxDepth - (整数的深度) + 1</code> 。</p>

<p>将 <code>nestedList</code> 列表中每个整数先乘权重再求和，返回该加权和。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0300-0399/0364.Nested%20List%20Weight%20Sum%20II/images/nestedlistweightsumiiex1.png" style="width: 426px; height: 181px;" />
<pre>
<strong>输入：</strong>nestedList = [[1,1],2,[1,1]]
<strong>输出：</strong>8
<strong>解释：</strong>4<strong> </strong>个 1 在深度为 1 的位置， 一个 2 在深度为 2 的位置。
1*1 + 1*1 + 2*2 + 1*1 + 1*1 = 8
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0300-0399/0364.Nested%20List%20Weight%20Sum%20II/images/nestedlistweightsumiiex2.png" style="width: 349px; height: 192px;" />
<pre>
<strong>输入：</strong>nestedList = [1,[4,[6]]]
<strong>输出：</strong>17
<strong>解释：</strong>一个 1 在深度为 3 的位置， 一个 4 在深度为 2 的位置，一个 6 在深度为 1 的位置。 
1*3 + 4*2 + 6*1 = 17
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nestedList.length &lt;= 50</code></li>
	<li>嵌套列表中整数的值在范围 <code>[-100, 100]</code></li>
	<li>任意整数的最大 <strong>深度</strong> 小于等于 <code>50</code></li>
	<li>没有空列表</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS

我们不妨假设整数分别为 $a_1, a_2, \cdots, a_n$，它们的深度分别为 $d_1, d_2, \cdots, d_n$，最大深度为 $\textit{maxDepth}$，那么答案就是：

$$
a_1 \times \textit{maxDepth} - a_1 \times d_1 + a_1 + a_2 \times \textit{maxDepth} - a_2 \times d_2 + a_2 + \cdots + a_n \times \textit{maxDepth} - a_n \times d_n + a_n
$$

即：

$$
(\textit{maxDepth} + 1) \times (a_1 + a_2 + \cdots + a_n) - (a_1 \times d_1 + a_2 \times d_2 + \cdots + a_n \times d_n)
$$

如果我们记所有整数的和为 $s$，所有整数乘以深度的和为 $ws$，那么答案就是：

$$
(\textit{maxDepth} + 1) \times s - ws
$$

因此，我们设计一个函数 $dfs(x, d)$，表示从 $x$ 开始，深度为 $d$ 开始搜索，函数 $dfs(x, d)$ 的执行过程如下：

-   我们先更新 $\textit{maxDepth} = \max(\textit{maxDepth}, d)$；
-   如果 $x$ 是一个整数，那么我们更新 $s = s + x$, $ws = ws + x \times d$；
-   否则，我们递归地遍历 $x$ 的每一个元素 $y$，调用 $dfs(y, d + 1)$。

我们遍历整个列表，对于每一个元素 $x$，我们调用 $dfs(x, 1)$，最终返回 $(\textit{maxDepth} + 1) \times s - ws$ 即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为整数的个数。

<!-- tabs:start -->

#### Python3

```python
# """
# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation
# """
# class NestedInteger:
#    def __init__(self, value=None):
#        """
#        If value is not specified, initializes an empty list.
#        Otherwise initializes a single integer equal to value.
#        """
#
#    def isInteger(self):
#        """
#        @return True if this NestedInteger holds a single integer, rather than a nested list.
#        :rtype bool
#        """
#
#    def add(self, elem):
#        """
#        Set this NestedInteger to hold a nested list and adds a nested integer elem to it.
#        :rtype void
#        """
#
#    def setInteger(self, value):
#        """
#        Set this NestedInteger to hold a single integer equal to value.
#        :rtype void
#        """
#
#    def getInteger(self):
#        """
#        @return the single integer that this NestedInteger holds, if it holds a single integer
#        Return None if this NestedInteger holds a nested list
#        :rtype int
#        """
#
#    def getList(self):
#        """
#        @return the nested list that this NestedInteger holds, if it holds a nested list
#        Return None if this NestedInteger holds a single integer
#        :rtype List[NestedInteger]
#        """
class Solution:
    def depthSumInverse(self, nestedList: List[NestedInteger]) -> int:
        def dfs(x, d):
            nonlocal maxDepth, s, ws
            maxDepth = max(maxDepth, d)
            if x.isInteger():
                s += x.getInteger()
                ws += x.getInteger() * d
            else:
                for y in x.getList():
                    dfs(y, d + 1)

        maxDepth = s = ws = 0
        for x in nestedList:
            dfs(x, 1)
        return (maxDepth + 1) * s - ws
```

#### Java

```java
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * public interface NestedInteger {
 *     // Constructor initializes an empty nested list.
 *     public NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     public NestedInteger(int value);
 *
 *     // @return true if this NestedInteger holds a single integer, rather than a nested list.
 *     public boolean isInteger();
 *
 *     // @return the single integer that this NestedInteger holds, if it holds a single integer
 *     // Return null if this NestedInteger holds a nested list
 *     public Integer getInteger();
 *
 *     // Set this NestedInteger to hold a single integer.
 *     public void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     public void add(NestedInteger ni);
 *
 *     // @return the nested list that this NestedInteger holds, if it holds a nested list
 *     // Return empty list if this NestedInteger holds a single integer
 *     public List<NestedInteger> getList();
 * }
 */
class Solution {
    private int maxDepth;
    private int ws;
    private int s;

    public int depthSumInverse(List<NestedInteger> nestedList) {
        for (NestedInteger x : nestedList) {
            dfs(x, 1);
        }
        return (maxDepth + 1) * s - ws;
    }

    private void dfs(NestedInteger x, int d) {
        maxDepth = Math.max(maxDepth, d);
        if (x.isInteger()) {
            ws += x.getInteger() * d;
            s += x.getInteger();
        } else {
            for (NestedInteger y : x.getList()) {
                dfs(y, d + 1);
            }
        }
    }
}
```

#### C++

```cpp
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int maxDepth = 0, ws = 0, s = 0;
        function<void(NestedInteger&, int)> dfs = [&](NestedInteger& x, int d) {
            maxDepth = max(maxDepth, d);
            if (x.isInteger()) {
                ws += x.getInteger() * d;
                s += x.getInteger();
            } else {
                for (auto& y : x.getList()) {
                    dfs(y, d + 1);
                }
            }
        };
        for (auto& x : nestedList) {
            dfs(x, 1);
        }
        return (maxDepth + 1) * s - ws;
    }
};
```

#### Go

```go
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * type NestedInteger struct {
 * }
 *
 * // Return true if this NestedInteger holds a single integer, rather than a nested list.
 * func (n NestedInteger) IsInteger() bool {}
 *
 * // Return the single integer that this NestedInteger holds, if it holds a single integer
 * // The result is undefined if this NestedInteger holds a nested list
 * // So before calling this method, you should have a check
 * func (n NestedInteger) GetInteger() int {}
 *
 * // Set this NestedInteger to hold a single integer.
 * func (n *NestedInteger) SetInteger(value int) {}
 *
 * // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 * func (n *NestedInteger) Add(elem NestedInteger) {}
 *
 * // Return the nested list that this NestedInteger holds, if it holds a nested list
 * // The list length is zero if this NestedInteger holds a single integer
 * // You can access NestedInteger's List element directly if you want to modify it
 * func (n NestedInteger) GetList() []*NestedInteger {}
 */
func depthSumInverse(nestedList []*NestedInteger) int {
	var maxDepth, ws, s int
	var dfs func(*NestedInteger, int)
	dfs = func(x *NestedInteger, d int) {
		maxDepth = max(maxDepth, d)
		if x.IsInteger() {
			ws += x.GetInteger() * d
			s += x.GetInteger()
		} else {
			for _, y := range x.GetList() {
				dfs(y, d+1)
			}
		}
	}
	for _, x := range nestedList {
		dfs(x, 1)
	}
	return (maxDepth+1)*s - ws
}
```

#### TypeScript

```ts
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *     If value is provided, then it holds a single integer
 *     Otherwise it holds an empty nested list
 *     constructor(value?: number) {
 *         ...
 *     };
 *
 *     Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     isInteger(): boolean {
 *         ...
 *     };
 *
 *     Return the single integer that this NestedInteger holds, if it holds a single integer
 *     Return null if this NestedInteger holds a nested list
 *     getInteger(): number | null {
 *         ...
 *     };
 *
 *     Set this NestedInteger to hold a single integer equal to value.
 *     setInteger(value: number) {
 *         ...
 *     };
 *
 *     Set this NestedInteger to hold a nested list and adds a nested integer elem to it.
 *     add(elem: NestedInteger) {
 *         ...
 *     };
 *
 *     Return the nested list that this NestedInteger holds,
 *     or an empty list if this NestedInteger holds a single integer
 *     getList(): NestedInteger[] {
 *         ...
 *     };
 * };
 */

function depthSumInverse(nestedList: NestedInteger[]): number {
    let [maxDepth, ws, s] = [0, 0, 0];
    const dfs = (x: NestedInteger, d: number) => {
        maxDepth = Math.max(maxDepth, d);
        if (x.isInteger()) {
            ws += x.getInteger() * d;
            s += x.getInteger();
        } else {
            for (const y of x.getList()) {
                dfs(y, d + 1);
            }
        }
    };
    for (const x of nestedList) {
        dfs(x, 1);
    }
    return (maxDepth + 1) * s - ws;
}
```

#### JavaScript

```js
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * function NestedInteger() {
 *
 *     Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     @return {boolean}
 *     this.isInteger = function() {
 *         ...
 *     };
 *
 *     Return the single integer that this NestedInteger holds, if it holds a single integer
 *     Return null if this NestedInteger holds a nested list
 *     @return {integer}
 *     this.getInteger = function() {
 *         ...
 *     };
 *
 *     Set this NestedInteger to hold a single integer equal to value.
 *     @return {void}
 *     this.setInteger = function(value) {
 *         ...
 *     };
 *
 *     Set this NestedInteger to hold a nested list and adds a nested integer elem to it.
 *     @return {void}
 *     this.add = function(elem) {
 *         ...
 *     };
 *
 *     Return the nested list that this NestedInteger holds, if it holds a nested list
 *     Return null if this NestedInteger holds a single integer
 *     @return {NestedInteger[]}
 *     this.getList = function() {
 *         ...
 *     };
 * };
 */
/**
 * @param {NestedInteger[]} nestedList
 * @return {number}
 */
var depthSumInverse = function (nestedList) {
    let [maxDepth, ws, s] = [0, 0, 0];
    const dfs = (x, d) => {
        maxDepth = Math.max(maxDepth, d);
        if (x.isInteger()) {
            ws += x.getInteger() * d;
            s += x.getInteger();
        } else {
            for (const y of x.getList()) {
                dfs(y, d + 1);
            }
        }
    };
    for (const x of nestedList) {
        dfs(x, 1);
    }
    return (maxDepth + 1) * s - ws;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [365. 水壶问题](https://leetcode.cn/problems/water-and-jug-problem){#365}

{{< tabs "365" >}}

{{% tab "python" %}}
```python
class Solution:
    def canMeasureWater(self, x: int, y: int, z: int) -> bool:
        def dfs(i: int, j: int) -> bool:
            if (i, j) in vis:
                return False
            vis.add((i, j))
            if i == z or j == z or i + j == z:
                return True
            if dfs(x, j) or dfs(i, y) or dfs(0, j) or dfs(i, 0):
                return True
            a = min(i, y - j)
            b = min(j, x - i)
            return dfs(i - a, j + a) or dfs(i + b, j - b)

        vis = set()
        return dfs(0, 0)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private Set<Long> vis = new HashSet<>();
    private int x, y, z;

    public boolean canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        x = jug1Capacity;
        y = jug2Capacity;
        z = targetCapacity;
        return dfs(0, 0);
    }

    private boolean dfs(int i, int j) {
        long st = f(i, j);
        if (!vis.add(st)) {
            return false;
        }
        if (i == z || j == z || i + j == z) {
            return true;
        }
        if (dfs(x, j) || dfs(i, y) || dfs(0, j) || dfs(i, 0)) {
            return true;
        }
        int a = Math.min(i, y - j);
        int b = Math.min(j, x - i);
        return dfs(i - a, j + a) || dfs(i + b, j - b);
    }

    private long f(int i, int j) {
        return i * 1000000L + j;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        using pii = pair<int, int>;
        stack<pii> stk;
        stk.emplace(0, 0);
        auto hash_function = [](const pii& o) { return hash<int>()(o.first) ^ hash<int>()(o.second); };
        unordered_set<pii, decltype(hash_function)> vis(0, hash_function);
        while (stk.size()) {
            auto st = stk.top();
            stk.pop();
            if (vis.count(st)) {
                continue;
            }
            vis.emplace(st);
            auto [i, j] = st;
            if (i == z || j == z || i + j == z) {
                return true;
            }
            stk.emplace(x, j);
            stk.emplace(i, y);
            stk.emplace(0, j);
            stk.emplace(i, 0);
            int a = min(i, y - j);
            int b = min(j, x - i);
            stk.emplace(i - a, j + a);
            stk.emplace(i + b, j - b);
        }
        return false;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func canMeasureWater(x int, y int, z int) bool {
	type pair struct{ x, y int }
	vis := map[pair]bool{}
	var dfs func(int, int) bool
	dfs = func(i, j int) bool {
		st := pair{i, j}
		if vis[st] {
			return false
		}
		vis[st] = true
		if i == z || j == z || i+j == z {
			return true
		}
		if dfs(x, j) || dfs(i, y) || dfs(0, j) || dfs(i, 0) {
			return true
		}
		a := min(i, y-j)
		b := min(j, x-i)
		return dfs(i-a, j+a) || dfs(i+b, j-b)
	}
	return dfs(0, 0)
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>有两个水壶，容量分别为&nbsp;<code>x</code>&nbsp;和 <code>y</code> 升。水的供应是无限的。确定是否有可能使用这两个壶准确得到&nbsp;<code>target</code>&nbsp;升。</p>

<p>你可以：</p>

<ul>
	<li>装满任意一个水壶</li>
	<li>清空任意一个水壶</li>
	<li>将水从一个水壶倒入另一个水壶，直到接水壶已满，或倒水壶已空。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1:</strong>&nbsp;</p>

<pre>
<strong>输入:</strong> x = 3,y = 5,target = 4
<strong>输出:</strong> true
<strong>解释：
</strong>按照以下步骤操作，以达到总共 4 升水：
1. 装满 5 升的水壶(0, 5)。
2. 把 5 升的水壶倒进 3 升的水壶，留下 2 升(3, 2)。
3. 倒空 3 升的水壶(0, 2)。
4. 把 2 升水从 5 升的水壶转移到 3 升的水壶(2, 0)。
5. 再次加满 5 升的水壶(2, 5)。
6. 从 5 升的水壶向 3 升的水壶倒水直到 3 升的水壶倒满。5 升的水壶里留下了 4 升水(3, 4)。
7. 倒空 3 升的水壶。现在，5 升的水壶里正好有 4 升水(0, 4)。
参考：来自著名的&nbsp;<a href="https://www.youtube.com/watch?v=BVtQNK_ZUJg"><em>"Die Hard"</em></a></pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> x = 2, y = 6, target = 5
<strong>输出:</strong> false
</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入:</strong> x = 1, y = 2, target = 3
<strong>输出:</strong> true
<b>解释：</b>同时倒满两个水壶。现在两个水壶中水的总量等于 3。</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= x, y, target &lt;= 10<sup>3</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS

我们不妨记 $\textit{jug1Capacity}$ 为 $x$, $\textit{jug2Capacity}$ 为 $y$, $\textit{targetCapacity}$ 为 $z$。

接下来，我们设计一个函数 $dfs(i, j)$，表示当前 $jug1$ 中有 $i$ 升水，$jug2$ 中有 $j$ 升水，是否可以得到 $z$ 升水。

函数 $dfs(i, j)$ 的执行过程如下：

-   如果 $(i, j)$ 已经被访问过，返回 $false$。
-   如果 $i = z$ 或者 $j = z$ 或者 $i + j = z$，返回 $true$。
-   如果我们给 $jug1$ 倒满水，或者给 $jug2$ 倒满水，或者将 $jug1$ 清空，或者将 $jug2$ 清空，可以得到 $z$ 升水，返回 $true$。
-   如果我们将 $jug1$ 中的水倒入 $jug2$，或者将 $jug2$ 中的水倒入 $jug1$，可以得到 $z$ 升水，返回 $true$。

答案即为 $dfs(0, 0)$。

时间复杂度 $O(x + y)$，空间复杂度 $O(x + y)$。其中 $x$ 和 $y$ 分别为 $\textit{jug1Capacity}$ 和 $\textit{jug2Capacity}$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def canMeasureWater(self, x: int, y: int, z: int) -> bool:
        def dfs(i: int, j: int) -> bool:
            if (i, j) in vis:
                return False
            vis.add((i, j))
            if i == z or j == z or i + j == z:
                return True
            if dfs(x, j) or dfs(i, y) or dfs(0, j) or dfs(i, 0):
                return True
            a = min(i, y - j)
            b = min(j, x - i)
            return dfs(i - a, j + a) or dfs(i + b, j - b)

        vis = set()
        return dfs(0, 0)
```

#### Java

```java
class Solution {
    private Set<Long> vis = new HashSet<>();
    private int x, y, z;

    public boolean canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        x = jug1Capacity;
        y = jug2Capacity;
        z = targetCapacity;
        return dfs(0, 0);
    }

    private boolean dfs(int i, int j) {
        long st = f(i, j);
        if (!vis.add(st)) {
            return false;
        }
        if (i == z || j == z || i + j == z) {
            return true;
        }
        if (dfs(x, j) || dfs(i, y) || dfs(0, j) || dfs(i, 0)) {
            return true;
        }
        int a = Math.min(i, y - j);
        int b = Math.min(j, x - i);
        return dfs(i - a, j + a) || dfs(i + b, j - b);
    }

    private long f(int i, int j) {
        return i * 1000000L + j;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        using pii = pair<int, int>;
        stack<pii> stk;
        stk.emplace(0, 0);
        auto hash_function = [](const pii& o) { return hash<int>()(o.first) ^ hash<int>()(o.second); };
        unordered_set<pii, decltype(hash_function)> vis(0, hash_function);
        while (stk.size()) {
            auto st = stk.top();
            stk.pop();
            if (vis.count(st)) {
                continue;
            }
            vis.emplace(st);
            auto [i, j] = st;
            if (i == z || j == z || i + j == z) {
                return true;
            }
            stk.emplace(x, j);
            stk.emplace(i, y);
            stk.emplace(0, j);
            stk.emplace(i, 0);
            int a = min(i, y - j);
            int b = min(j, x - i);
            stk.emplace(i - a, j + a);
            stk.emplace(i + b, j - b);
        }
        return false;
    }
};
```

#### Go

```go
func canMeasureWater(x int, y int, z int) bool {
	type pair struct{ x, y int }
	vis := map[pair]bool{}
	var dfs func(int, int) bool
	dfs = func(i, j int) bool {
		st := pair{i, j}
		if vis[st] {
			return false
		}
		vis[st] = true
		if i == z || j == z || i+j == z {
			return true
		}
		if dfs(x, j) || dfs(i, y) || dfs(0, j) || dfs(i, 0) {
			return true
		}
		a := min(i, y-j)
		b := min(j, x-i)
		return dfs(i-a, j+a) || dfs(i+b, j-b)
	}
	return dfs(0, 0)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [366. 寻找二叉树的叶子节点 🔒](https://leetcode.cn/problems/find-leaves-of-binary-tree){#366}

{{< tabs "366" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findLeaves(self, root: Optional[TreeNode]) -> List[List[int]]:
        def dfs(root: Optional[TreeNode]) -> int:
            if root is None:
                return 0
            l, r = dfs(root.left), dfs(root.right)
            h = max(l, r)
            if len(ans) == h:
                ans.append([])
            ans[h].append(root.val)
            return h + 1

        ans = []
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
    private List<List<Integer>> ans = new ArrayList<>();

    public List<List<Integer>> findLeaves(TreeNode root) {
        dfs(root);
        return ans;
    }

    private int dfs(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int l = dfs(root.left);
        int r = dfs(root.right);
        int h = Math.max(l, r);
        if (ans.size() == h) {
            ans.add(new ArrayList<>());
        }
        ans.get(h).add(root.val);
        return h + 1;
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
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> ans;
        function<int(TreeNode*)> dfs = [&](TreeNode* root) {
            if (!root) {
                return 0;
            }
            int l = dfs(root->left);
            int r = dfs(root->right);
            int h = max(l, r);
            if (ans.size() == h) {
                ans.push_back({});
            }
            ans[h].push_back(root->val);
            return h + 1;
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
func findLeaves(root *TreeNode) (ans [][]int) {
	var dfs func(*TreeNode) int
	dfs = func(root *TreeNode) int {
		if root == nil {
			return 0
		}
		l, r := dfs(root.Left), dfs(root.Right)
		h := max(l, r)
		if len(ans) == h {
			ans = append(ans, []int{})
		}
		ans[h] = append(ans[h], root.Val)
		return h + 1
	}
	dfs(root)
	return
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

function findLeaves(root: TreeNode | null): number[][] {
    const ans: number[][] = [];
    const dfs = (root: TreeNode | null): number => {
        if (root === null) {
            return 0;
        }
        const l = dfs(root.left);
        const r = dfs(root.right);
        const h = Math.max(l, r);
        if (ans.length === h) {
            ans.push([]);
        }
        ans[h].push(root.val);
        return h + 1;
    };
    dfs(root);
    return ans;
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
    public IList<IList<int>> FindLeaves(TreeNode root) {
        var ans = new List<IList<int>>();

        int Dfs(TreeNode node) {
            if (node == null) {
                return 0;
            }
            int l = Dfs(node.left);
            int r = Dfs(node.right);
            int h = Math.Max(l, r);
            if (ans.Count == h) {
                ans.Add(new List<int>());
            }
            ans[h].Add(node.val);
            return h + 1;
        }

        Dfs(root);
        return ans;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一棵二叉树的 <code>root</code> 节点，请按照以下方式收集树的节点：</p>

<ul>
	<li>收集所有的叶子节点。</li>
	<li>移除所有的叶子节点。</li>
	<li>重复以上步骤，直到树为空。</li>
</ul>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0300-0399/0366.Find%20Leaves%20of%20Binary%20Tree/images/remleaves-tree.jpg" style="width: 500px; height: 215px;" />
<pre>
<strong>输入：</strong>root = [1,2,3,4,5]
<strong>输出：</strong>[[4,5,3],[2],[1]]
<strong>解释：</strong>
[[3,5,4],[2],[1]] 和 [[3,4,5],[2],[1]] 也被视作正确答案，因为每一层返回元素的顺序不影响结果。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>root = [1]
<strong>输出：</strong>[[1]]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点的数量在<code>[1, 100]</code>范围内。</li>
	<li><code>-100 &lt;= Node.val &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS

我们可以使用深度优先搜索的方法，递归遍历二叉树，将每个节点的高度作为索引，将节点的值添加到对应索引的数组中。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为二叉树的节点个数。

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
    def findLeaves(self, root: Optional[TreeNode]) -> List[List[int]]:
        def dfs(root: Optional[TreeNode]) -> int:
            if root is None:
                return 0
            l, r = dfs(root.left), dfs(root.right)
            h = max(l, r)
            if len(ans) == h:
                ans.append([])
            ans[h].append(root.val)
            return h + 1

        ans = []
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
    private List<List<Integer>> ans = new ArrayList<>();

    public List<List<Integer>> findLeaves(TreeNode root) {
        dfs(root);
        return ans;
    }

    private int dfs(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int l = dfs(root.left);
        int r = dfs(root.right);
        int h = Math.max(l, r);
        if (ans.size() == h) {
            ans.add(new ArrayList<>());
        }
        ans.get(h).add(root.val);
        return h + 1;
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
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> ans;
        function<int(TreeNode*)> dfs = [&](TreeNode* root) {
            if (!root) {
                return 0;
            }
            int l = dfs(root->left);
            int r = dfs(root->right);
            int h = max(l, r);
            if (ans.size() == h) {
                ans.push_back({});
            }
            ans[h].push_back(root->val);
            return h + 1;
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
func findLeaves(root *TreeNode) (ans [][]int) {
	var dfs func(*TreeNode) int
	dfs = func(root *TreeNode) int {
		if root == nil {
			return 0
		}
		l, r := dfs(root.Left), dfs(root.Right)
		h := max(l, r)
		if len(ans) == h {
			ans = append(ans, []int{})
		}
		ans[h] = append(ans[h], root.Val)
		return h + 1
	}
	dfs(root)
	return
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

function findLeaves(root: TreeNode | null): number[][] {
    const ans: number[][] = [];
    const dfs = (root: TreeNode | null): number => {
        if (root === null) {
            return 0;
        }
        const l = dfs(root.left);
        const r = dfs(root.right);
        const h = Math.max(l, r);
        if (ans.length === h) {
            ans.push([]);
        }
        ans[h].push(root.val);
        return h + 1;
    };
    dfs(root);
    return ans;
}
```

#### C#

```cs
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
    public IList<IList<int>> FindLeaves(TreeNode root) {
        var ans = new List<IList<int>>();

        int Dfs(TreeNode node) {
            if (node == null) {
                return 0;
            }
            int l = Dfs(node.left);
            int r = Dfs(node.right);
            int h = Math.Max(l, r);
            if (ans.Count == h) {
                ans.Add(new List<int>());
            }
            ans[h].Add(node.val);
            return h + 1;
        }

        Dfs(root);
        return ans;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [367. 有效的完全平方数](https://leetcode.cn/problems/valid-perfect-square){#367}

{{< tabs "367" >}}

{{% tab "python" %}}
```python
class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        i = 1
        while num > 0:
            num -= i
            i += 2
        return num == 0
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean isPerfectSquare(int num) {
        for (int i = 1; num > 0; i += 2) {
            num -= i;
        }
        return num == 0;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool isPerfectSquare(int num) {
        for (int i = 1; num > 0; i += 2) {
            num -= i;
        }
        return num == 0;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func isPerfectSquare(num int) bool {
	for i := 1; num > 0; i += 2 {
		num -= i
	}
	return num == 0
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function isPerfectSquare(num: number): boolean {
    let i = 1;
    while (num > 0) {
        num -= i;
        i += 2;
    }
    return num === 0;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn is_perfect_square(mut num: i32) -> bool {
        let mut i = 1;
        while num > 0 {
            num -= i;
            i += 2;
        }
        num == 0
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个正整数 <code>num</code> 。如果 <code>num</code> 是一个完全平方数，则返回 <code>true</code> ，否则返回 <code>false</code> 。</p>

<p><strong>完全平方数</strong> 是一个可以写成某个整数的平方的整数。换句话说，它可以写成某个整数和自身的乘积。</p>

<p>不能使用任何内置的库函数，如&nbsp; <code>sqrt</code> 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>num = 16
<strong>输出：</strong>true
<strong>解释：</strong>返回 true ，因为 4 * 4 = 16 且 4 是一个整数。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>num = 14
<strong>输出：</strong>false
<strong>解释：</strong>返回 false ，因为 3.742 * 3.742 = 14 但 3.742 不是一个整数。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= num &lt;= 2<sup>31</sup> - 1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二分查找

我们可以使用二分查找来解决这个问题。定义二分查找的左边界 $l = 1$，右边界 $r = num$，然后在 $[l, r]$ 的范围内查找满足 $x^2 \geq num$ 的最小整数 $x$。最后，如果 $x^2 = num$，则说明 $num$ 是一个完全平方数。

时间复杂度 $O(\log n)$，其中 $n$ 是给定的数字。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        l = bisect_left(range(1, num + 1), num, key=lambda x: x * x) + 1
        return l * l == num
```

#### Java

```java
class Solution {
    public boolean isPerfectSquare(int num) {
        int l = 1, r = num;
        while (l < r) {
            int mid = (l + r) >>> 1;
            if (1L * mid * mid >= num) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l * l == num;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 1, r = num;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (1LL * mid * mid >= num) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return 1LL * l * l == num;
    }
};
```

#### Go

```go
func isPerfectSquare(num int) bool {
	l := sort.Search(num, func(i int) bool { return i*i >= num })
	return l*l == num
}
```

#### TypeScript

```ts
function isPerfectSquare(num: number): boolean {
    let [l, r] = [1, num];
    while (l < r) {
        const mid = (l + r) >> 1;
        if (mid >= num / mid) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l * l === num;
}
```

#### Rust

```rust
impl Solution {
    pub fn is_perfect_square(num: i32) -> bool {
        let mut l = 1;
        let mut r = num as i64;
        while l < r {
            let mid = (l + r) / 2;
            if mid * mid >= (num as i64) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        l * l == (num as i64)
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：数学

由于 $1 + 3 + 5 + \cdots + (2n - 1) = n^2$，我们可以将 $num$ 逐渐减去 $1, 3, 5, \cdots$，如果最后 $num = 0$，则说明 $num$ 是一个完全平方数。

时间复杂度 $O(\sqrt n)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        i = 1
        while num > 0:
            num -= i
            i += 2
        return num == 0
```

#### Java

```java
class Solution {
    public boolean isPerfectSquare(int num) {
        for (int i = 1; num > 0; i += 2) {
            num -= i;
        }
        return num == 0;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool isPerfectSquare(int num) {
        for (int i = 1; num > 0; i += 2) {
            num -= i;
        }
        return num == 0;
    }
};
```

#### Go

```go
func isPerfectSquare(num int) bool {
	for i := 1; num > 0; i += 2 {
		num -= i
	}
	return num == 0
}
```

#### TypeScript

```ts
function isPerfectSquare(num: number): boolean {
    let i = 1;
    while (num > 0) {
        num -= i;
        i += 2;
    }
    return num === 0;
}
```

#### Rust

```rust
impl Solution {
    pub fn is_perfect_square(mut num: i32) -> bool {
        let mut i = 1;
        while num > 0 {
            num -= i;
            i += 2;
        }
        num == 0
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [368. 最大整除子集](https://leetcode.cn/problems/largest-divisible-subset){#368}

{{< tabs "368" >}}

{{% tab "python" %}}
```python
class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        nums.sort()
        n = len(nums)
        f = [1] * n
        k = 0
        for i in range(n):
            for j in range(i):
                if nums[i] % nums[j] == 0:
                    f[i] = max(f[i], f[j] + 1)
            if f[k] < f[i]:
                k = i
        m = f[k]
        i = k
        ans = []
        while m:
            if nums[k] % nums[i] == 0 and f[i] == m:
                ans.append(nums[i])
                k, m = i, m - 1
            i -= 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<Integer> largestDivisibleSubset(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        int[] f = new int[n];
        Arrays.fill(f, 1);
        int k = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0) {
                    f[i] = Math.max(f[i], f[j] + 1);
                }
            }
            if (f[k] < f[i]) {
                k = i;
            }
        }
        int m = f[k];
        List<Integer> ans = new ArrayList<>();
        for (int i = k; m > 0; --i) {
            if (nums[k] % nums[i] == 0 && f[i] == m) {
                ans.add(nums[i]);
                k = i;
                --m;
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
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        ranges::sort(nums);
        int n = nums.size();
        int f[n];
        int k = 0;
        for (int i = 0; i < n; ++i) {
            f[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0) {
                    f[i] = max(f[i], f[j] + 1);
                }
            }
            if (f[k] < f[i]) {
                k = i;
            }
        }
        int m = f[k];
        vector<int> ans;
        for (int i = k; m > 0; --i) {
            if (nums[k] % nums[i] == 0 && f[i] == m) {
                ans.push_back(nums[i]);
                k = i;
                --m;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func largestDivisibleSubset(nums []int) (ans []int) {
	sort.Ints(nums)
	n := len(nums)
	f := make([]int, n)
	k := 0
	for i := 0; i < n; i++ {
		f[i] = 1
		for j := 0; j < i; j++ {
			if nums[i]%nums[j] == 0 {
				f[i] = max(f[i], f[j]+1)
			}
		}
		if f[k] < f[i] {
			k = i
		}
	}
	m := f[k]
	for i := k; m > 0; i-- {
		if nums[k]%nums[i] == 0 && f[i] == m {
			ans = append(ans, nums[i])
			k = i
			m--
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function largestDivisibleSubset(nums: number[]): number[] {
    nums.sort((a, b) => a - b);
    const n = nums.length;
    const f: number[] = Array(n).fill(1);
    let k = 0;

    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < i; ++j) {
            if (nums[i] % nums[j] === 0) {
                f[i] = Math.max(f[i], f[j] + 1);
            }
        }
        if (f[k] < f[i]) {
            k = i;
        }
    }

    let m = f[k];
    const ans: number[] = [];
    for (let i = k; m > 0; --i) {
        if (nums[k] % nums[i] === 0 && f[i] === m) {
            ans.push(nums[i]);
            k = i;
            --m;
        }
    }

    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn largest_divisible_subset(nums: Vec<i32>) -> Vec<i32> {
        let mut nums = nums;
        nums.sort();

        let n = nums.len();
        let mut f = vec![1; n];
        let mut k = 0;

        for i in 0..n {
            for j in 0..i {
                if nums[i] % nums[j] == 0 {
                    f[i] = f[i].max(f[j] + 1);
                }
            }
            if f[k] < f[i] {
                k = i;
            }
        }

        let mut m = f[k];
        let mut ans = Vec::new();

        for i in (0..=k).rev() {
            if nums[k] % nums[i] == 0 && f[i] == m {
                ans.push(nums[i]);
                k = i;
                m -= 1;
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

给你一个由 <strong>无重复</strong> 正整数组成的集合 <code>nums</code> ，请你找出并返回其中最大的整除子集 <code>answer</code> ，子集中每一元素对 <code>(answer[i], answer[j])</code> 都应当满足：

<ul>
	<li><code>answer[i] % answer[j] == 0</code> ，或</li>
	<li><code>answer[j] % answer[i] == 0</code></li>
</ul>

<p>如果存在多个有效解子集，返回其中任何一个均可。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3]
<strong>输出：</strong>[1,2]
<strong>解释：</strong>[1,3] 也会被视为正确答案。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,4,8]
<strong>输出：</strong>[1,2,4,8]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= nums.length <= 1000</code></li>
	<li><code>1 <= nums[i] <= 2 * 10<sup>9</sup></code></li>
	<li><code>nums</code> 中的所有整数 <strong>互不相同</strong></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 动态规划

我们先对数组进行排序，这样可以保证对于任意的 $i \lt j$，如果 $nums[i]$ 可以整除 $nums[j]$，那么 $nums[i]$ 一定在 $nums[j]$ 的左边。

接下来，我们定义 $f[i]$ 表示以 $nums[i]$ 为最大元素的最大整除子集的大小，初始时 $f[i]=1$。

对于每一个 $i$，我们从左往右枚举 $j$，如果 $nums[i]$ 可以被 $nums[j]$ 整除，那么 $f[i]$ 可以从 $f[j]$ 转移而来，我们更新 $f[i]=max(f[i], f[j]+1)$。过程中，我们记录 $f[i]$ 的最大值的下标 $k$ 以及对应的子集大小 $m$。

最后，我们从 $k$ 开始倒序遍历，如果 $nums[k]$ 可以被 $nums[i]$ 整除，且 $f[i]=m$，那么 $nums[i]$ 就是一个整除子集的元素，我们将 $nums[i]$ 加入答案，并将 $m$ 减 $1$，同时更新 $k=i$。继续倒序遍历，直到 $m=0$。

时间复杂度 $O(n^2)$，空间复杂度 $O(n)$。其中 $n$ 是数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        nums.sort()
        n = len(nums)
        f = [1] * n
        k = 0
        for i in range(n):
            for j in range(i):
                if nums[i] % nums[j] == 0:
                    f[i] = max(f[i], f[j] + 1)
            if f[k] < f[i]:
                k = i
        m = f[k]
        i = k
        ans = []
        while m:
            if nums[k] % nums[i] == 0 and f[i] == m:
                ans.append(nums[i])
                k, m = i, m - 1
            i -= 1
        return ans
```

#### Java

```java
class Solution {
    public List<Integer> largestDivisibleSubset(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        int[] f = new int[n];
        Arrays.fill(f, 1);
        int k = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0) {
                    f[i] = Math.max(f[i], f[j] + 1);
                }
            }
            if (f[k] < f[i]) {
                k = i;
            }
        }
        int m = f[k];
        List<Integer> ans = new ArrayList<>();
        for (int i = k; m > 0; --i) {
            if (nums[k] % nums[i] == 0 && f[i] == m) {
                ans.add(nums[i]);
                k = i;
                --m;
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
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        ranges::sort(nums);
        int n = nums.size();
        int f[n];
        int k = 0;
        for (int i = 0; i < n; ++i) {
            f[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0) {
                    f[i] = max(f[i], f[j] + 1);
                }
            }
            if (f[k] < f[i]) {
                k = i;
            }
        }
        int m = f[k];
        vector<int> ans;
        for (int i = k; m > 0; --i) {
            if (nums[k] % nums[i] == 0 && f[i] == m) {
                ans.push_back(nums[i]);
                k = i;
                --m;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func largestDivisibleSubset(nums []int) (ans []int) {
	sort.Ints(nums)
	n := len(nums)
	f := make([]int, n)
	k := 0
	for i := 0; i < n; i++ {
		f[i] = 1
		for j := 0; j < i; j++ {
			if nums[i]%nums[j] == 0 {
				f[i] = max(f[i], f[j]+1)
			}
		}
		if f[k] < f[i] {
			k = i
		}
	}
	m := f[k]
	for i := k; m > 0; i-- {
		if nums[k]%nums[i] == 0 && f[i] == m {
			ans = append(ans, nums[i])
			k = i
			m--
		}
	}
	return
}
```

#### TypeScript

```ts
function largestDivisibleSubset(nums: number[]): number[] {
    nums.sort((a, b) => a - b);
    const n = nums.length;
    const f: number[] = Array(n).fill(1);
    let k = 0;

    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < i; ++j) {
            if (nums[i] % nums[j] === 0) {
                f[i] = Math.max(f[i], f[j] + 1);
            }
        }
        if (f[k] < f[i]) {
            k = i;
        }
    }

    let m = f[k];
    const ans: number[] = [];
    for (let i = k; m > 0; --i) {
        if (nums[k] % nums[i] === 0 && f[i] === m) {
            ans.push(nums[i]);
            k = i;
            --m;
        }
    }

    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn largest_divisible_subset(nums: Vec<i32>) -> Vec<i32> {
        let mut nums = nums;
        nums.sort();

        let n = nums.len();
        let mut f = vec![1; n];
        let mut k = 0;

        for i in 0..n {
            for j in 0..i {
                if nums[i] % nums[j] == 0 {
                    f[i] = f[i].max(f[j] + 1);
                }
            }
            if f[k] < f[i] {
                k = i;
            }
        }

        let mut m = f[k];
        let mut ans = Vec::new();

        for i in (0..=k).rev() {
            if nums[k] % nums[i] == 0 && f[i] == m {
                ans.push(nums[i]);
                k = i;
                m -= 1;
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

# [369. 给单链表加一 🔒](https://leetcode.cn/problems/plus-one-linked-list){#369}

{{< tabs "369" >}}

{{% tab "python" %}}
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def plusOne(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(0, head)
        target = dummy
        while head:
            if head.val != 9:
                target = head
            head = head.next
        target.val += 1
        target = target.next
        while target:
            target.val = 0
            target = target.next
        return dummy if dummy.val else dummy.next
```
{{% /tab %}}
{{% tab "java" %}}
```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode plusOne(ListNode head) {
        ListNode dummy = new ListNode(0, head);
        ListNode target = dummy;
        while (head != null) {
            if (head.val != 9) {
                target = head;
            }
            head = head.next;
        }
        ++target.val;
        target = target.next;
        while (target != null) {
            target.val = 0;
            target = target.next;
        }
        return dummy.val == 1 ? dummy : dummy.next;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* target = dummy;
        for (; head; head = head->next) {
            if (head->val != 9) {
                target = head;
            }
        }
        target->val++;
        for (target = target->next; target; target = target->next) {
            target->val = 0;
        }
        return dummy->val ? dummy : dummy->next;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func plusOne(head *ListNode) *ListNode {
	dummy := &ListNode{0, head}
	target := dummy
	for head != nil {
		if head.Val != 9 {
			target = head
		}
		head = head.Next
	}
	target.Val++
	for target = target.Next; target != nil; target = target.Next {
		target.Val = 0
	}
	if dummy.Val == 1 {
		return dummy
	}
	return dummy.Next
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function plusOne(head: ListNode | null): ListNode | null {
    const dummy = new ListNode(0, head);
    let target = dummy;
    while (head) {
        if (head.val !== 9) {
            target = head;
        }
        head = head.next;
    }
    target.val++;
    for (target = target.next; target; target = target.next) {
        target.val = 0;
    }
    return dummy.val ? dummy : dummy.next;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个用<strong>链表</strong>表示的非负整数， 然后将这个整数&nbsp;<em>再加上 1</em> 。</p>

<p>这些数字的存储是这样的：最高位有效的数字位于链表的首位<meta charset="UTF-8" />&nbsp;<code>head</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入: </strong>head = [1,2,3]
<strong>输出: </strong>[1,2,4]
</pre>

<p><meta charset="UTF-8" /></p>

<p><strong>示例</strong><strong>&nbsp;2:</strong></p>

<pre>
<strong>输入: </strong>head = [0]
<strong>输出: </strong>[1]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>链表中的节点数在<meta charset="UTF-8" />&nbsp;<code>[1, 100]</code>&nbsp;的范围内。</li>
	<li><code>0 &lt;= Node.val &lt;= 9</code></li>
	<li>由链表表示的数字不包含前导零，除了零本身。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：链表遍历

我们先设置一个虚拟头节点 $\textit{dummy}$，初始时 $\textit{dummy}$ 的值为 $0$，并且 $\textit{dummy}$ 的后继节点为链表 $\textit{head}$。

接下来，我们从虚拟头节点开始遍历链表，找到最后一个不为 $9$ 的节点，将其值加 $1$，并将该节点之后的所有节点的值置为 $0$。

最后，我们判断虚拟头节点的值是否为 $1$，如果为 $1$，则返回 $\textit{dummy}$，否则返回 $\textit{dummy}$ 的后继节点。

时间复杂度 $O(n)$，其中 $n$ 是链表的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def plusOne(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(0, head)
        target = dummy
        while head:
            if head.val != 9:
                target = head
            head = head.next
        target.val += 1
        target = target.next
        while target:
            target.val = 0
            target = target.next
        return dummy if dummy.val else dummy.next
```

#### Java

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode plusOne(ListNode head) {
        ListNode dummy = new ListNode(0, head);
        ListNode target = dummy;
        while (head != null) {
            if (head.val != 9) {
                target = head;
            }
            head = head.next;
        }
        ++target.val;
        target = target.next;
        while (target != null) {
            target.val = 0;
            target = target.next;
        }
        return dummy.val == 1 ? dummy : dummy.next;
    }
}
```

#### C++

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* target = dummy;
        for (; head; head = head->next) {
            if (head->val != 9) {
                target = head;
            }
        }
        target->val++;
        for (target = target->next; target; target = target->next) {
            target->val = 0;
        }
        return dummy->val ? dummy : dummy->next;
    }
};
```

#### Go

```go
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func plusOne(head *ListNode) *ListNode {
	dummy := &ListNode{0, head}
	target := dummy
	for head != nil {
		if head.Val != 9 {
			target = head
		}
		head = head.Next
	}
	target.Val++
	for target = target.Next; target != nil; target = target.Next {
		target.Val = 0
	}
	if dummy.Val == 1 {
		return dummy
	}
	return dummy.Next
}
```

#### TypeScript

```ts
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function plusOne(head: ListNode | null): ListNode | null {
    const dummy = new ListNode(0, head);
    let target = dummy;
    while (head) {
        if (head.val !== 9) {
            target = head;
        }
        head = head.next;
    }
    target.val++;
    for (target = target.next; target; target = target.next) {
        target.val = 0;
    }
    return dummy.val ? dummy : dummy.next;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
