---
title: "2510_检查是否有路径经过相同数量的 0 和 1 🔒"
date: 2025-10-08T18:39:23+08:00
weight: 2
tags: [二分查找, 分治, 动态规划, 双指针, 哈希表, 堆（优先队列）, 字符串, 归并排序, 排序, 数学, 数组, 数论, 有序集合, 树状数组, 滑动窗口, 矩阵, 线段树, 组合数学, 计数, 贪心]
---

{{< markmap >}}
### [2510_检查是否有路径经过相同数量的 0 和 1 🔒](#2510)
#### [数组](#2510)
#### [动态规划](#2510)
#### [矩阵](#2510)
### [2511_最多可以摧毁的敌人城堡数目](#2511)
#### [数组](#2511)
#### [双指针](#2511)
### [2512_奖励最顶尖的 K 名学生](#2512)
#### [数组](#2512)
#### [哈希表](#2512)
#### [字符串](#2512)
#### [排序](#2512)
#### [堆（优先队列）](#2512)
### [2513_最小化两个数组中的最大值](#2513)
#### [数学](#2513)
#### [二分查找](#2513)
#### [数论](#2513)
### [2514_统计同位异构字符串数目](#2514)
#### [哈希表](#2514)
#### [数学](#2514)
#### [字符串](#2514)
#### [组合数学](#2514)
#### [计数](#2514)
### [2515_到目标字符串的最短距离](#2515)
#### [数组](#2515)
#### [字符串](#2515)
### [2516_每种字符至少取 K 个](#2516)
#### [哈希表](#2516)
#### [字符串](#2516)
#### [滑动窗口](#2516)
### [2517_礼盒的最大甜蜜度](#2517)
#### [贪心](#2517)
#### [数组](#2517)
#### [二分查找](#2517)
#### [排序](#2517)
### [2518_好分区的数目](#2518)
#### [数组](#2518)
#### [动态规划](#2518)
### [2519_统计 K-Big 索引的数量 🔒](#2519)
#### [树状数组](#2519)
#### [线段树](#2519)
#### [数组](#2519)
#### [二分查找](#2519)
#### [分治](#2519)
#### [有序集合](#2519)
#### [归并排序](#2519)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2510_检查是否有路径经过相同数量的 0 和 1 🔒
___
#### 数组
___
#### 动态规划
___
#### 矩阵
---
### 2511_最多可以摧毁的敌人城堡数目
___
#### 数组
___
#### 双指针
---
### 2512_奖励最顶尖的 K 名学生
___
#### 数组
___
#### 哈希表
___
#### 字符串
___
#### 排序
___
#### 堆（优先队列）
---
### 2513_最小化两个数组中的最大值
___
#### 数学
___
#### 二分查找
___
#### 数论
---
### 2514_统计同位异构字符串数目
___
#### 哈希表
___
#### 数学
___
#### 字符串
___
#### 组合数学
___
#### 计数
---
### 2515_到目标字符串的最短距离
___
#### 数组
___
#### 字符串
---
### 2516_每种字符至少取 K 个
___
#### 哈希表
___
#### 字符串
___
#### 滑动窗口
---
### 2517_礼盒的最大甜蜜度
___
#### 贪心
___
#### 数组
___
#### 二分查找
___
#### 排序
---
### 2518_好分区的数目
___
#### 数组
___
#### 动态规划
---
### 2519_统计 K-Big 索引的数量 🔒
___
#### 树状数组
___
#### 线段树
___
#### 数组
___
#### 二分查找
___
#### 分治
___
#### 有序集合
___
#### 归并排序
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 分治 | 动态规划 |
| 双指针 | 哈希表 | 堆（优先队列） |
| 字符串 | 归并排序 | 排序 |
| 数学 | 数组 | 数论 |
| 有序集合 | 树状数组 | 滑动窗口 |
| 矩阵 | 线段树 | 组合数学 |
| 计数 | 贪心 |  |

# [2510. 检查是否有路径经过相同数量的 0 和 1 🔒](https://leetcode.cn/problems/check-if-there-is-a-path-with-equal-number-of-0s-and-1s){#2510}

{{< tabs "2510" >}}

{{% tab "python" %}}
```python
class Solution:
    def isThereAPath(self, grid: List[List[int]]) -> bool:
        @cache
        def dfs(i, j, k):
            if i >= m or j >= n:
                return False
            k += grid[i][j]
            if k > s or i + j + 1 - k > s:
                return False
            if i == m - 1 and j == n - 1:
                return k == s
            return dfs(i + 1, j, k) or dfs(i, j + 1, k)

        m, n = len(grid), len(grid[0])
        s = m + n - 1
        if s & 1:
            return False
        s >>= 1
        return dfs(0, 0, 0)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int s;
    private int m;
    private int n;
    private int[][] grid;
    private Boolean[][][] f;

    public boolean isThereAPath(int[][] grid) {
        m = grid.length;
        n = grid[0].length;
        this.grid = grid;
        s = m + n - 1;
        f = new Boolean[m][n][s];
        if (s % 2 == 1) {
            return false;
        }
        s >>= 1;
        return dfs(0, 0, 0);
    }

    private boolean dfs(int i, int j, int k) {
        if (i >= m || j >= n) {
            return false;
        }
        k += grid[i][j];
        if (f[i][j][k] != null) {
            return f[i][j][k];
        }
        if (k > s || i + j + 1 - k > s) {
            return false;
        }
        if (i == m - 1 && j == n - 1) {
            return k == s;
        }
        f[i][j][k] = dfs(i + 1, j, k) || dfs(i, j + 1, k);
        return f[i][j][k];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool isThereAPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int s = m + n - 1;
        if (s & 1) return false;
        int f[m][n][s];
        s >>= 1;
        memset(f, -1, sizeof f);
        function<bool(int, int, int)> dfs = [&](int i, int j, int k) -> bool {
            if (i >= m || j >= n) return false;
            k += grid[i][j];
            if (f[i][j][k] != -1) return f[i][j][k];
            if (k > s || i + j + 1 - k > s) return false;
            if (i == m - 1 && j == n - 1) return k == s;
            f[i][j][k] = dfs(i + 1, j, k) || dfs(i, j + 1, k);
            return f[i][j][k];
        };
        return dfs(0, 0, 0);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func isThereAPath(grid [][]int) bool {
	m, n := len(grid), len(grid[0])
	s := m + n - 1
	if s%2 == 1 {
		return false
	}
	s >>= 1
	f := [100][100][200]int{}
	var dfs func(i, j, k int) bool
	dfs = func(i, j, k int) bool {
		if i >= m || j >= n {
			return false
		}
		k += grid[i][j]
		if f[i][j][k] != 0 {
			return f[i][j][k] == 1
		}
		f[i][j][k] = 2
		if k > s || i+j+1-k > s {
			return false
		}
		if i == m-1 && j == n-1 {
			return k == s
		}
		res := dfs(i+1, j, k) || dfs(i, j+1, k)
		if res {
			f[i][j][k] = 1
		}
		return res
	}
	return dfs(0, 0, 0)
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个 <strong>下标从 0 开始</strong> 的 <code>m x n</code> 的 <strong>二进制</strong> 矩阵 <code>grid</code> ，从坐标为 <code>(row, col)</code> 的元素可以向右走 <code>(row, col+1)</code> 或向下走 <code>(row+1, col)</code> 。</p>

<p>返回一个布尔值，表示从 <code>(0, 0)</code> 出发是否存在一条路径，经过 <strong>相同</strong> 数量的 <code>0</code> 和 <code>1</code>，到达终点 <code>(m-1, n-1)</code> 。如果存在这样的路径返回 <code>true</code> ，否则返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1 ：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2500-2599/2510.Check%20if%20There%20is%20a%20Path%20With%20Equal%20Number%20of%200%27s%20And%201%27s/images/yetgriddrawio-4.png" />
<pre>
<b>输入：</b>grid = [[0,1,0,0],[0,1,0,0],[1,0,1,0]]
<b>输出：</b>true
<b>解释：</b>以上图中用蓝色标记的路径是一个有效的路径，因为路径上有 3 个值为 1 的单元格和 3 个值为 0 的单元格。由于存在一个有效的路径，因此返回 true 。
</pre>

<p><strong class="example">示例 2 ：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2500-2599/2510.Check%20if%20There%20is%20a%20Path%20With%20Equal%20Number%20of%200%27s%20And%201%27s/images/yetgrid2drawio-1.png" style="width: 151px; height: 151px;" />
<pre>
<b>输入：</b>grid = [[1,1,0],[0,0,1],[1,0,0]]
<b>输出：</b>false
<b>解释：</b>这个网格中没有一条路径经过相等数量的0和1。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>2 &lt;= m, n &lt;= 100</code></li>
	<li><code>grid[i][j]</code> 不是&nbsp;<code>0</code> 就是&nbsp;<code>1</code> 。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

根据题目描述我们知道，从左上角到右下角的路径上 $0$ 的个数和 $1$ 的个数相等，个数总和为 $m + n - 1$，即 $0$ 的个数和 $1$ 的个数都为 $(m + n - 1) / 2$。

因此我们可以使用记忆化搜索，从左上角开始，向右或向下移动，直到到达右下角，判断路径上 $0$ 的个数和 $1$ 的个数是否相等即可。

时间复杂度 $O(m \times n \times (m + n))$。其中 $m$ 和 $n$ 分别为矩阵的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def isThereAPath(self, grid: List[List[int]]) -> bool:
        @cache
        def dfs(i, j, k):
            if i >= m or j >= n:
                return False
            k += grid[i][j]
            if k > s or i + j + 1 - k > s:
                return False
            if i == m - 1 and j == n - 1:
                return k == s
            return dfs(i + 1, j, k) or dfs(i, j + 1, k)

        m, n = len(grid), len(grid[0])
        s = m + n - 1
        if s & 1:
            return False
        s >>= 1
        return dfs(0, 0, 0)
```

#### Java

```java
class Solution {
    private int s;
    private int m;
    private int n;
    private int[][] grid;
    private Boolean[][][] f;

    public boolean isThereAPath(int[][] grid) {
        m = grid.length;
        n = grid[0].length;
        this.grid = grid;
        s = m + n - 1;
        f = new Boolean[m][n][s];
        if (s % 2 == 1) {
            return false;
        }
        s >>= 1;
        return dfs(0, 0, 0);
    }

    private boolean dfs(int i, int j, int k) {
        if (i >= m || j >= n) {
            return false;
        }
        k += grid[i][j];
        if (f[i][j][k] != null) {
            return f[i][j][k];
        }
        if (k > s || i + j + 1 - k > s) {
            return false;
        }
        if (i == m - 1 && j == n - 1) {
            return k == s;
        }
        f[i][j][k] = dfs(i + 1, j, k) || dfs(i, j + 1, k);
        return f[i][j][k];
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool isThereAPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int s = m + n - 1;
        if (s & 1) return false;
        int f[m][n][s];
        s >>= 1;
        memset(f, -1, sizeof f);
        function<bool(int, int, int)> dfs = [&](int i, int j, int k) -> bool {
            if (i >= m || j >= n) return false;
            k += grid[i][j];
            if (f[i][j][k] != -1) return f[i][j][k];
            if (k > s || i + j + 1 - k > s) return false;
            if (i == m - 1 && j == n - 1) return k == s;
            f[i][j][k] = dfs(i + 1, j, k) || dfs(i, j + 1, k);
            return f[i][j][k];
        };
        return dfs(0, 0, 0);
    }
};
```

#### Go

```go
func isThereAPath(grid [][]int) bool {
	m, n := len(grid), len(grid[0])
	s := m + n - 1
	if s%2 == 1 {
		return false
	}
	s >>= 1
	f := [100][100][200]int{}
	var dfs func(i, j, k int) bool
	dfs = func(i, j, k int) bool {
		if i >= m || j >= n {
			return false
		}
		k += grid[i][j]
		if f[i][j][k] != 0 {
			return f[i][j][k] == 1
		}
		f[i][j][k] = 2
		if k > s || i+j+1-k > s {
			return false
		}
		if i == m-1 && j == n-1 {
			return k == s
		}
		res := dfs(i+1, j, k) || dfs(i, j+1, k)
		if res {
			f[i][j][k] = 1
		}
		return res
	}
	return dfs(0, 0, 0)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2511. 最多可以摧毁的敌人城堡数目](https://leetcode.cn/problems/maximum-enemy-forts-that-can-be-captured){#2511}

{{< tabs "2511" >}}

{{% tab "python" %}}
```python
class Solution:
    def captureForts(self, forts: List[int]) -> int:
        n = len(forts)
        i = ans = 0
        while i < n:
            j = i + 1
            if forts[i]:
                while j < n and forts[j] == 0:
                    j += 1
                if j < n and forts[i] + forts[j] == 0:
                    ans = max(ans, j - i - 1)
            i = j
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int captureForts(int[] forts) {
        int n = forts.length;
        int ans = 0, i = 0;
        while (i < n) {
            int j = i + 1;
            if (forts[i] != 0) {
                while (j < n && forts[j] == 0) {
                    ++j;
                }
                if (j < n && forts[i] + forts[j] == 0) {
                    ans = Math.max(ans, j - i - 1);
                }
            }
            i = j;
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
    int captureForts(vector<int>& forts) {
        int n = forts.size();
        int ans = 0, i = 0;
        while (i < n) {
            int j = i + 1;
            if (forts[i] != 0) {
                while (j < n && forts[j] == 0) {
                    ++j;
                }
                if (j < n && forts[i] + forts[j] == 0) {
                    ans = max(ans, j - i - 1);
                }
            }
            i = j;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func captureForts(forts []int) (ans int) {
	n := len(forts)
	i := 0
	for i < n {
		j := i + 1
		if forts[i] != 0 {
			for j < n && forts[j] == 0 {
				j++
			}
			if j < n && forts[i]+forts[j] == 0 {
				ans = max(ans, j-i-1)
			}
		}
		i = j
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function captureForts(forts: number[]): number {
    const n = forts.length;
    let ans = 0;
    let i = 0;
    while (i < n) {
        let j = i + 1;
        if (forts[i] !== 0) {
            while (j < n && forts[j] === 0) {
                j++;
            }
            if (j < n && forts[i] + forts[j] === 0) {
                ans = Math.max(ans, j - i - 1);
            }
        }
        i = j;
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn capture_forts(forts: Vec<i32>) -> i32 {
        let n = forts.len();
        let mut ans = 0;
        let mut i = 0;
        while i < n {
            let mut j = i + 1;
            if forts[i] != 0 {
                while j < n && forts[j] == 0 {
                    j += 1;
                }
                if j < n && forts[i] + forts[j] == 0 {
                    ans = ans.max(j - i - 1);
                }
            }
            i = j;
        }
        ans as i32
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个长度为 <code>n</code>&nbsp;，下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>forts</code>&nbsp;，表示一些城堡。<code>forts[i]</code> 可以是&nbsp;<code>-1</code>&nbsp;，<code>0</code>&nbsp;或者&nbsp;<code>1</code>&nbsp;，其中：</p>

<ul>
	<li><code>-1</code>&nbsp;表示第&nbsp;<code>i</code>&nbsp;个位置 <strong>没有</strong>&nbsp;城堡。</li>
	<li><code>0</code>&nbsp;表示第&nbsp;<code>i</code>&nbsp;个位置有一个 <strong>敌人</strong>&nbsp;的城堡。</li>
	<li><code>1</code>&nbsp;表示第&nbsp;<code>i</code>&nbsp;个位置有一个你控制的城堡。</li>
</ul>

<p>现在，你需要决定，将你的军队从某个你控制的城堡位置&nbsp;<code>i</code>&nbsp;移动到一个空的位置&nbsp;<code>j</code>&nbsp;，满足：</p>

<ul>
	<li><code>0 &lt;= i, j &lt;= n - 1</code></li>
	<li>军队经过的位置 <strong>只有</strong>&nbsp;敌人的城堡。正式的，对于所有&nbsp;<code>min(i,j) &lt; k &lt; max(i,j)</code>&nbsp;的&nbsp;<code>k</code>&nbsp;，都满足&nbsp;<code>forts[k] == 0</code>&nbsp;。</li>
</ul>

<p>当军队移动时，所有途中经过的敌人城堡都会被 <strong>摧毁</strong> 。</p>

<p>请你返回 <strong>最多</strong>&nbsp;可以摧毁的敌人城堡数目。如果 <strong>无法</strong>&nbsp;移动你的军队，或者没有你控制的城堡，请返回 <code>0</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>forts = [1,0,0,-1,0,0,0,0,1]
<b>输出：</b>4
<strong>解释：</strong>
- 将军队从位置 0 移动到位置 3 ，摧毁 2 个敌人城堡，位置分别在 1 和 2 。
- 将军队从位置 8 移动到位置 3 ，摧毁 4 个敌人城堡。
4 是最多可以摧毁的敌人城堡数目，所以我们返回 4 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>forts = [0,0,1,-1]
<b>输出：</b>0
<b>解释：</b>由于无法摧毁敌人的城堡，所以返回 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= forts.length &lt;= 1000</code></li>
	<li><code>-1 &lt;= forts[i] &lt;= 1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双指针

我们用指针 $i$ 遍历数组 $forts$，指针 $j$ 从 $i$ 的下一个位置开始遍历，直到遇到第一个非 $0$ 的位置，即 $forts[j] \neq 0$。如果 $forts[i] + forts[j] = 0$，那么我们可以将军队在 $i$ 和 $j$ 之间移动，摧毁 $j - i - 1$ 个敌人城堡。我们用变量 $ans$ 记录最多可以摧毁的敌人城堡数目即可。

时间复杂度 $O(n)$，空间复杂度 $O(1)$。其中 $n$ 为数组 `forts` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def captureForts(self, forts: List[int]) -> int:
        n = len(forts)
        i = ans = 0
        while i < n:
            j = i + 1
            if forts[i]:
                while j < n and forts[j] == 0:
                    j += 1
                if j < n and forts[i] + forts[j] == 0:
                    ans = max(ans, j - i - 1)
            i = j
        return ans
```

#### Java

```java
class Solution {
    public int captureForts(int[] forts) {
        int n = forts.length;
        int ans = 0, i = 0;
        while (i < n) {
            int j = i + 1;
            if (forts[i] != 0) {
                while (j < n && forts[j] == 0) {
                    ++j;
                }
                if (j < n && forts[i] + forts[j] == 0) {
                    ans = Math.max(ans, j - i - 1);
                }
            }
            i = j;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int captureForts(vector<int>& forts) {
        int n = forts.size();
        int ans = 0, i = 0;
        while (i < n) {
            int j = i + 1;
            if (forts[i] != 0) {
                while (j < n && forts[j] == 0) {
                    ++j;
                }
                if (j < n && forts[i] + forts[j] == 0) {
                    ans = max(ans, j - i - 1);
                }
            }
            i = j;
        }
        return ans;
    }
};
```

#### Go

```go
func captureForts(forts []int) (ans int) {
	n := len(forts)
	i := 0
	for i < n {
		j := i + 1
		if forts[i] != 0 {
			for j < n && forts[j] == 0 {
				j++
			}
			if j < n && forts[i]+forts[j] == 0 {
				ans = max(ans, j-i-1)
			}
		}
		i = j
	}
	return
}
```

#### TypeScript

```ts
function captureForts(forts: number[]): number {
    const n = forts.length;
    let ans = 0;
    let i = 0;
    while (i < n) {
        let j = i + 1;
        if (forts[i] !== 0) {
            while (j < n && forts[j] === 0) {
                j++;
            }
            if (j < n && forts[i] + forts[j] === 0) {
                ans = Math.max(ans, j - i - 1);
            }
        }
        i = j;
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn capture_forts(forts: Vec<i32>) -> i32 {
        let n = forts.len();
        let mut ans = 0;
        let mut i = 0;
        while i < n {
            let mut j = i + 1;
            if forts[i] != 0 {
                while j < n && forts[j] == 0 {
                    j += 1;
                }
                if j < n && forts[i] + forts[j] == 0 {
                    ans = ans.max(j - i - 1);
                }
            }
            i = j;
        }
        ans as i32
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2512. 奖励最顶尖的 K 名学生](https://leetcode.cn/problems/reward-top-k-students){#2512}

{{< tabs "2512" >}}

{{% tab "python" %}}
```python
class Solution:
    def topStudents(
        self,
        positive_feedback: List[str],
        negative_feedback: List[str],
        report: List[str],
        student_id: List[int],
        k: int,
    ) -> List[int]:
        ps = set(positive_feedback)
        ns = set(negative_feedback)
        arr = []
        for sid, r in zip(student_id, report):
            t = 0
            for w in r.split():
                if w in ps:
                    t += 3
                elif w in ns:
                    t -= 1
            arr.append((t, sid))
        arr.sort(key=lambda x: (-x[0], x[1]))
        return [v[1] for v in arr[:k]]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<Integer> topStudents(String[] positive_feedback, String[] negative_feedback,
        String[] report, int[] student_id, int k) {
        Set<String> ps = new HashSet<>();
        Set<String> ns = new HashSet<>();
        for (var s : positive_feedback) {
            ps.add(s);
        }
        for (var s : negative_feedback) {
            ns.add(s);
        }
        int n = report.length;
        int[][] arr = new int[n][0];
        for (int i = 0; i < n; ++i) {
            int sid = student_id[i];
            int t = 0;
            for (var s : report[i].split(" ")) {
                if (ps.contains(s)) {
                    t += 3;
                } else if (ns.contains(s)) {
                    t -= 1;
                }
            }
            arr[i] = new int[] {t, sid};
        }
        Arrays.sort(arr, (a, b) -> a[0] == b[0] ? a[1] - b[1] : b[0] - a[0]);
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < k; ++i) {
            ans.add(arr[i][1]);
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
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        unordered_set<string> ps(positive_feedback.begin(), positive_feedback.end());
        unordered_set<string> ns(negative_feedback.begin(), negative_feedback.end());
        vector<pair<int, int>> arr;
        int n = report.size();
        for (int i = 0; i < n; ++i) {
            int sid = student_id[i];
            vector<string> ws = split(report[i], ' ');
            int t = 0;
            for (auto& w : ws) {
                if (ps.count(w)) {
                    t += 3;
                } else if (ns.count(w)) {
                    t -= 1;
                }
            }
            arr.push_back({-t, sid});
        }
        sort(arr.begin(), arr.end());
        vector<int> ans;
        for (int i = 0; i < k; ++i) {
            ans.emplace_back(arr[i].second);
        }
        return ans;
    }

    vector<string> split(string& s, char delim) {
        stringstream ss(s);
        string item;
        vector<string> res;
        while (getline(ss, item, delim)) {
            res.emplace_back(item);
        }
        return res;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func topStudents(positive_feedback []string, negative_feedback []string, report []string, student_id []int, k int) (ans []int) {
	ps := map[string]bool{}
	ns := map[string]bool{}
	for _, s := range positive_feedback {
		ps[s] = true
	}
	for _, s := range negative_feedback {
		ns[s] = true
	}
	arr := [][2]int{}
	for i, sid := range student_id {
		t := 0
		for _, w := range strings.Split(report[i], " ") {
			if ps[w] {
				t += 3
			} else if ns[w] {
				t -= 1
			}
		}
		arr = append(arr, [2]int{t, sid})
	}
	sort.Slice(arr, func(i, j int) bool { return arr[i][0] > arr[j][0] || (arr[i][0] == arr[j][0] && arr[i][1] < arr[j][1]) })
	for _, v := range arr[:k] {
		ans = append(ans, v[1])
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function topStudents(
    positive_feedback: string[],
    negative_feedback: string[],
    report: string[],
    student_id: number[],
    k: number,
): number[] {
    const n = student_id.length;
    const map = new Map<number, number>();
    const ps = new Set(positive_feedback);
    const ns = new Set(negative_feedback);
    for (let i = 0; i < n; i++) {
        map.set(
            student_id[i],
            report[i].split(' ').reduce((r, s) => {
                if (ps.has(s)) {
                    return r + 3;
                }
                if (ns.has(s)) {
                    return r - 1;
                }
                return r;
            }, 0),
        );
    }
    return [...map.entries()]
        .sort((a, b) => {
            if (a[1] === b[1]) {
                return a[0] - b[0];
            }
            return b[1] - a[1];
        })
        .map(v => v[0])
        .slice(0, k);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::{HashMap, HashSet};
impl Solution {
    pub fn top_students(
        positive_feedback: Vec<String>,
        negative_feedback: Vec<String>,
        report: Vec<String>,
        student_id: Vec<i32>,
        k: i32,
    ) -> Vec<i32> {
        let n = student_id.len();
        let ps = positive_feedback.iter().collect::<HashSet<&String>>();
        let ns = negative_feedback.iter().collect::<HashSet<&String>>();
        let mut map = HashMap::new();
        for i in 0..n {
            let id = student_id[i];
            let mut count = 0;
            for s in report[i].split(' ') {
                let s = &s.to_string();
                if ps.contains(s) {
                    count += 3;
                } else if ns.contains(s) {
                    count -= 1;
                }
            }
            map.insert(id, count);
        }
        let mut t = map.into_iter().collect::<Vec<(i32, i32)>>();
        t.sort_by(|a, b| {
            if a.1 == b.1 {
                return a.0.cmp(&b.0);
            }
            b.1.cmp(&a.1)
        });
        t.iter().map(|v| v.0).collect::<Vec<i32>>()[0..k as usize].to_vec()
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个字符串数组&nbsp;<code>positive_feedback</code> 和&nbsp;<code>negative_feedback</code>&nbsp;，分别包含表示正面的和负面的词汇。<strong>不会</strong>&nbsp;有单词同时是正面的和负面的。</p>

<p>一开始，每位学生分数为&nbsp;<code>0</code>&nbsp;。每个正面的单词会给学生的分数 <strong>加&nbsp;</strong><code>3</code>&nbsp;分，每个负面的词会给学生的分数 <strong>减&nbsp;</strong>&nbsp;<code>1</code>&nbsp;分。</p>

<p>给你&nbsp;<code>n</code>&nbsp;个学生的评语，用一个下标从 <strong>0</strong>&nbsp;开始的字符串数组&nbsp;<code>report</code>&nbsp;和一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>student_id</code>&nbsp;表示，其中&nbsp;<code>student_id[i]</code>&nbsp;表示这名学生的 ID ，这名学生的评语是&nbsp;<code>report[i]</code>&nbsp;。每名学生的 ID <strong>互不相同</strong>。</p>

<p>给你一个整数&nbsp;<code>k</code>&nbsp;，请你返回按照得分&nbsp;<strong>从高到低</strong>&nbsp;最顶尖的<em>&nbsp;</em><code>k</code>&nbsp;名学生。如果有多名学生分数相同，ID 越小排名越前。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>positive_feedback = ["smart","brilliant","studious"], negative_feedback = ["not"], report = ["this student is studious","the student is smart"], student_id = [1,2], k = 2
<b>输出：</b>[1,2]
<b>解释：</b>
两名学生都有 1 个正面词汇，都得到 3 分，学生 1 的 ID 更小所以排名更前。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>positive_feedback = ["smart","brilliant","studious"], negative_feedback = ["not"], report = ["this student is not studious","the student is smart"], student_id = [1,2], k = 2
<b>输出：</b>[2,1]
<b>解释：</b>
- ID 为 1 的学生有 1 个正面词汇和 1 个负面词汇，所以得分为 3-1=2 分。
- ID 为 2 的学生有 1 个正面词汇，得分为 3 分。
学生 2 分数更高，所以返回 [2,1] 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= positive_feedback.length, negative_feedback.length &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= positive_feedback[i].length, negative_feedback[j].length &lt;= 100</code></li>
	<li><code>positive_feedback[i]</code> 和&nbsp;<code>negative_feedback[j]</code>&nbsp;都只包含小写英文字母。</li>
	<li><code>positive_feedback</code> 和&nbsp;<code>negative_feedback</code>&nbsp;中不会有相同单词。</li>
	<li><code>n == report.length == student_id.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>report[i]</code>&nbsp;只包含小写英文字母和空格&nbsp;<code>' '</code>&nbsp;。</li>
	<li><code>report[i]</code>&nbsp;中连续单词之间有单个空格隔开。</li>
	<li><code>1 &lt;= report[i].length &lt;= 100</code></li>
	<li><code>1 &lt;= student_id[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>student_id[i]</code>&nbsp;的值 <strong>互不相同</strong>&nbsp;。</li>
	<li><code>1 &lt;= k &lt;= n</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 排序

我们可以将正面的单词存入哈希表 $ps$ 中，将负面的单词存入哈希表 $ns$ 中。

然后遍历 $report$，对于每个学生，我们将其得分存入数组 $arr$ 中，数组中的每个元素为一个二元组 $(t, sid)$，其中 $t$ 表示学生的得分，而 $sid$ 表示学生的 ID。

最后我们对数组 $arr$ 按照得分从高到低排序，如果得分相同则按照 ID 从小到大排序，然后取出前 $k$ 个学生的 ID 即可。

时间复杂度 $O(n \times \log n + (|ps| + |ns| + n) \times |s|)$，空间复杂度 $O((|ps|+|ns|) \times |s| + n)$。其中 $n$ 为学生数量，$|ps|$ 和 $|ns|$ 分别为正面和负面单词的数量，$|s|$ 为单词的平均长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def topStudents(
        self,
        positive_feedback: List[str],
        negative_feedback: List[str],
        report: List[str],
        student_id: List[int],
        k: int,
    ) -> List[int]:
        ps = set(positive_feedback)
        ns = set(negative_feedback)
        arr = []
        for sid, r in zip(student_id, report):
            t = 0
            for w in r.split():
                if w in ps:
                    t += 3
                elif w in ns:
                    t -= 1
            arr.append((t, sid))
        arr.sort(key=lambda x: (-x[0], x[1]))
        return [v[1] for v in arr[:k]]
```

#### Java

```java
class Solution {
    public List<Integer> topStudents(String[] positive_feedback, String[] negative_feedback,
        String[] report, int[] student_id, int k) {
        Set<String> ps = new HashSet<>();
        Set<String> ns = new HashSet<>();
        for (var s : positive_feedback) {
            ps.add(s);
        }
        for (var s : negative_feedback) {
            ns.add(s);
        }
        int n = report.length;
        int[][] arr = new int[n][0];
        for (int i = 0; i < n; ++i) {
            int sid = student_id[i];
            int t = 0;
            for (var s : report[i].split(" ")) {
                if (ps.contains(s)) {
                    t += 3;
                } else if (ns.contains(s)) {
                    t -= 1;
                }
            }
            arr[i] = new int[] {t, sid};
        }
        Arrays.sort(arr, (a, b) -> a[0] == b[0] ? a[1] - b[1] : b[0] - a[0]);
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < k; ++i) {
            ans.add(arr[i][1]);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        unordered_set<string> ps(positive_feedback.begin(), positive_feedback.end());
        unordered_set<string> ns(negative_feedback.begin(), negative_feedback.end());
        vector<pair<int, int>> arr;
        int n = report.size();
        for (int i = 0; i < n; ++i) {
            int sid = student_id[i];
            vector<string> ws = split(report[i], ' ');
            int t = 0;
            for (auto& w : ws) {
                if (ps.count(w)) {
                    t += 3;
                } else if (ns.count(w)) {
                    t -= 1;
                }
            }
            arr.push_back({-t, sid});
        }
        sort(arr.begin(), arr.end());
        vector<int> ans;
        for (int i = 0; i < k; ++i) {
            ans.emplace_back(arr[i].second);
        }
        return ans;
    }

    vector<string> split(string& s, char delim) {
        stringstream ss(s);
        string item;
        vector<string> res;
        while (getline(ss, item, delim)) {
            res.emplace_back(item);
        }
        return res;
    }
};
```

#### Go

```go
func topStudents(positive_feedback []string, negative_feedback []string, report []string, student_id []int, k int) (ans []int) {
	ps := map[string]bool{}
	ns := map[string]bool{}
	for _, s := range positive_feedback {
		ps[s] = true
	}
	for _, s := range negative_feedback {
		ns[s] = true
	}
	arr := [][2]int{}
	for i, sid := range student_id {
		t := 0
		for _, w := range strings.Split(report[i], " ") {
			if ps[w] {
				t += 3
			} else if ns[w] {
				t -= 1
			}
		}
		arr = append(arr, [2]int{t, sid})
	}
	sort.Slice(arr, func(i, j int) bool { return arr[i][0] > arr[j][0] || (arr[i][0] == arr[j][0] && arr[i][1] < arr[j][1]) })
	for _, v := range arr[:k] {
		ans = append(ans, v[1])
	}
	return
}
```

#### TypeScript

```ts
function topStudents(
    positive_feedback: string[],
    negative_feedback: string[],
    report: string[],
    student_id: number[],
    k: number,
): number[] {
    const n = student_id.length;
    const map = new Map<number, number>();
    const ps = new Set(positive_feedback);
    const ns = new Set(negative_feedback);
    for (let i = 0; i < n; i++) {
        map.set(
            student_id[i],
            report[i].split(' ').reduce((r, s) => {
                if (ps.has(s)) {
                    return r + 3;
                }
                if (ns.has(s)) {
                    return r - 1;
                }
                return r;
            }, 0),
        );
    }
    return [...map.entries()]
        .sort((a, b) => {
            if (a[1] === b[1]) {
                return a[0] - b[0];
            }
            return b[1] - a[1];
        })
        .map(v => v[0])
        .slice(0, k);
}
```

#### Rust

```rust
use std::collections::{HashMap, HashSet};
impl Solution {
    pub fn top_students(
        positive_feedback: Vec<String>,
        negative_feedback: Vec<String>,
        report: Vec<String>,
        student_id: Vec<i32>,
        k: i32,
    ) -> Vec<i32> {
        let n = student_id.len();
        let ps = positive_feedback.iter().collect::<HashSet<&String>>();
        let ns = negative_feedback.iter().collect::<HashSet<&String>>();
        let mut map = HashMap::new();
        for i in 0..n {
            let id = student_id[i];
            let mut count = 0;
            for s in report[i].split(' ') {
                let s = &s.to_string();
                if ps.contains(s) {
                    count += 3;
                } else if ns.contains(s) {
                    count -= 1;
                }
            }
            map.insert(id, count);
        }
        let mut t = map.into_iter().collect::<Vec<(i32, i32)>>();
        t.sort_by(|a, b| {
            if a.1 == b.1 {
                return a.0.cmp(&b.0);
            }
            b.1.cmp(&a.1)
        });
        t.iter().map(|v| v.0).collect::<Vec<i32>>()[0..k as usize].to_vec()
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2513. 最小化两个数组中的最大值](https://leetcode.cn/problems/minimize-the-maximum-of-two-arrays){#2513}

{{< tabs "2513" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimizeSet(
        self, divisor1: int, divisor2: int, uniqueCnt1: int, uniqueCnt2: int
    ) -> int:
        def f(x):
            cnt1 = x // divisor1 * (divisor1 - 1) + x % divisor1
            cnt2 = x // divisor2 * (divisor2 - 1) + x % divisor2
            cnt = x // divisor * (divisor - 1) + x % divisor
            return (
                cnt1 >= uniqueCnt1
                and cnt2 >= uniqueCnt2
                and cnt >= uniqueCnt1 + uniqueCnt2
            )

        divisor = lcm(divisor1, divisor2)
        return bisect_left(range(10**10), True, key=f)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        long divisor = lcm(divisor1, divisor2);
        long left = 1, right = 10000000000L;
        while (left < right) {
            long mid = (left + right) >> 1;
            long cnt1 = mid / divisor1 * (divisor1 - 1) + mid % divisor1;
            long cnt2 = mid / divisor2 * (divisor2 - 1) + mid % divisor2;
            long cnt = mid / divisor * (divisor - 1) + mid % divisor;
            if (cnt1 >= uniqueCnt1 && cnt2 >= uniqueCnt2 && cnt >= uniqueCnt1 + uniqueCnt2) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return (int) left;
    }

    private long lcm(int a, int b) {
        return (long) a * b / gcd(a, b);
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
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        long left = 1, right = 1e10;
        long divisor = lcm((long) divisor1, (long) divisor2);
        while (left < right) {
            long mid = (left + right) >> 1;
            long cnt1 = mid / divisor1 * (divisor1 - 1) + mid % divisor1;
            long cnt2 = mid / divisor2 * (divisor2 - 1) + mid % divisor2;
            long cnt = mid / divisor * (divisor - 1) + mid % divisor;
            if (cnt1 >= uniqueCnt1 && cnt2 >= uniqueCnt2 && cnt >= uniqueCnt1 + uniqueCnt2) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimizeSet(divisor1 int, divisor2 int, uniqueCnt1 int, uniqueCnt2 int) int {
	divisor := lcm(divisor1, divisor2)
	left, right := 1, 10000000000
	for left < right {
		mid := (left + right) >> 1
		cnt1 := mid/divisor1*(divisor1-1) + mid%divisor1
		cnt2 := mid/divisor2*(divisor2-1) + mid%divisor2
		cnt := mid/divisor*(divisor-1) + mid%divisor
		if cnt1 >= uniqueCnt1 && cnt2 >= uniqueCnt2 && cnt >= uniqueCnt1+uniqueCnt2 {
			right = mid
		} else {
			left = mid + 1
		}
	}
	return left
}

func lcm(a, b int) int {
	return a * b / gcd(a, b)
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个数组&nbsp;<code>arr1</code> 和&nbsp;<code>arr2</code>&nbsp;，它们一开始都是空的。你需要往它们中添加正整数，使它们满足以下条件：</p>

<ul>
	<li><code>arr1</code>&nbsp;包含&nbsp;<code>uniqueCnt1</code>&nbsp;个<strong>&nbsp;互不相同</strong>&nbsp;的正整数，每个整数都&nbsp;<strong>不能 </strong>被&nbsp;<code>divisor1</code>&nbsp;<strong>整除</strong>&nbsp;。</li>
	<li><code>arr2</code>&nbsp;包含&nbsp;<code>uniqueCnt2</code>&nbsp;个<strong>&nbsp;互不相同</strong>&nbsp;的正整数，每个整数都&nbsp;<strong>不能</strong>&nbsp;被&nbsp;<code>divisor2</code>&nbsp;<strong>整除</strong>&nbsp;。</li>
	<li><code>arr1</code> 和&nbsp;<code>arr2</code>&nbsp;中的元素&nbsp;<strong>互不相同</strong>&nbsp;。</li>
</ul>

<p>给你&nbsp;<code>divisor1</code>&nbsp;，<code>divisor2</code>&nbsp;，<code>uniqueCnt1</code>&nbsp;和&nbsp;<code>uniqueCnt2</code>&nbsp;，请你返回两个数组中&nbsp;<strong>最大元素</strong>&nbsp;的&nbsp;<strong>最小值</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>divisor1 = 2, divisor2 = 7, uniqueCnt1 = 1, uniqueCnt2 = 3
<b>输出：</b>4
<b>解释：</b>
我们可以把前 4 个自然数划分到 arr1 和 arr2 中。
arr1 = [1] 和 arr2 = [2,3,4] 。
可以看出两个数组都满足条件。
最大值是 4 ，所以返回 4 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>divisor1 = 3, divisor2 = 5, uniqueCnt1 = 2, uniqueCnt2 = 1
<b>输出：</b>3
<b>解释：</b>
arr1 = [1,2] 和 arr2 = [3] 满足所有条件。
最大值是 3 ，所以返回 3 。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>divisor1 = 2, divisor2 = 4, uniqueCnt1 = 8, uniqueCnt2 = 2
<b>输出：</b>15
<b>解释：</b>
最终数组为 arr1 = [1,3,5,7,9,11,13,15] 和 arr2 = [2,6] 。
上述方案是满足所有条件的最优解。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= divisor1, divisor2 &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= uniqueCnt1, uniqueCnt2 &lt; 10<sup>9</sup></code></li>
	<li><code>2 &lt;= uniqueCnt1 + uniqueCnt2 &lt;= 10<sup>9</sup></code></li>
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
    def minimizeSet(
        self, divisor1: int, divisor2: int, uniqueCnt1: int, uniqueCnt2: int
    ) -> int:
        def f(x):
            cnt1 = x // divisor1 * (divisor1 - 1) + x % divisor1
            cnt2 = x // divisor2 * (divisor2 - 1) + x % divisor2
            cnt = x // divisor * (divisor - 1) + x % divisor
            return (
                cnt1 >= uniqueCnt1
                and cnt2 >= uniqueCnt2
                and cnt >= uniqueCnt1 + uniqueCnt2
            )

        divisor = lcm(divisor1, divisor2)
        return bisect_left(range(10**10), True, key=f)
```

#### Java

```java
class Solution {
    public int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        long divisor = lcm(divisor1, divisor2);
        long left = 1, right = 10000000000L;
        while (left < right) {
            long mid = (left + right) >> 1;
            long cnt1 = mid / divisor1 * (divisor1 - 1) + mid % divisor1;
            long cnt2 = mid / divisor2 * (divisor2 - 1) + mid % divisor2;
            long cnt = mid / divisor * (divisor - 1) + mid % divisor;
            if (cnt1 >= uniqueCnt1 && cnt2 >= uniqueCnt2 && cnt >= uniqueCnt1 + uniqueCnt2) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return (int) left;
    }

    private long lcm(int a, int b) {
        return (long) a * b / gcd(a, b);
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
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        long left = 1, right = 1e10;
        long divisor = lcm((long) divisor1, (long) divisor2);
        while (left < right) {
            long mid = (left + right) >> 1;
            long cnt1 = mid / divisor1 * (divisor1 - 1) + mid % divisor1;
            long cnt2 = mid / divisor2 * (divisor2 - 1) + mid % divisor2;
            long cnt = mid / divisor * (divisor - 1) + mid % divisor;
            if (cnt1 >= uniqueCnt1 && cnt2 >= uniqueCnt2 && cnt >= uniqueCnt1 + uniqueCnt2) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
```

#### Go

```go
func minimizeSet(divisor1 int, divisor2 int, uniqueCnt1 int, uniqueCnt2 int) int {
	divisor := lcm(divisor1, divisor2)
	left, right := 1, 10000000000
	for left < right {
		mid := (left + right) >> 1
		cnt1 := mid/divisor1*(divisor1-1) + mid%divisor1
		cnt2 := mid/divisor2*(divisor2-1) + mid%divisor2
		cnt := mid/divisor*(divisor-1) + mid%divisor
		if cnt1 >= uniqueCnt1 && cnt2 >= uniqueCnt2 && cnt >= uniqueCnt1+uniqueCnt2 {
			right = mid
		} else {
			left = mid + 1
		}
	}
	return left
}

func lcm(a, b int) int {
	return a * b / gcd(a, b)
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2514. 统计同位异构字符串数目](https://leetcode.cn/problems/count-anagrams){#2514}

{{< tabs "2514" >}}

{{% tab "python" %}}
```python
class Solution:
    def countAnagrams(self, s: str) -> int:
        mod = 10**9 + 7
        ans = mul = 1
        for w in s.split():
            cnt = Counter()
            for i, c in enumerate(w, 1):
                cnt[c] += 1
                mul = mul * cnt[c] % mod
                ans = ans * i % mod
        return ans * pow(mul, -1, mod) % mod
```
{{% /tab %}}
{{% tab "java" %}}
```java
import java.math.BigInteger;

class Solution {
    private static final int MOD = (int) 1e9 + 7;

    public int countAnagrams(String s) {
        int n = s.length();
        long[] f = new long[n + 1];
        f[0] = 1;
        for (int i = 1; i <= n; ++i) {
            f[i] = f[i - 1] * i % MOD;
        }
        long p = 1;
        for (String w : s.split(" ")) {
            int[] cnt = new int[26];
            for (int i = 0; i < w.length(); ++i) {
                ++cnt[w.charAt(i) - 'a'];
            }
            p = p * f[w.length()] % MOD;
            for (int v : cnt) {
                p = p * BigInteger.valueOf(f[v]).modInverse(BigInteger.valueOf(MOD)).intValue()
                    % MOD;
            }
        }
        return (int) p;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    const int mod = 1e9 + 7;

    int countAnagrams(string s) {
        stringstream ss(s);
        string w;
        long ans = 1, mul = 1;
        while (ss >> w) {
            int cnt[26] = {0};
            for (int i = 1; i <= w.size(); ++i) {
                int c = w[i - 1] - 'a';
                ++cnt[c];
                ans = ans * i % mod;
                mul = mul * cnt[c] % mod;
            }
        }
        return ans * pow(mul, mod - 2) % mod;
    }

    long pow(long x, int n) {
        long res = 1L;
        for (; n; n /= 2) {
            if (n % 2) res = res * x % mod;
            x = x * x % mod;
        }
        return res;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
const mod int = 1e9 + 7

func countAnagrams(s string) int {
	ans, mul := 1, 1
	for _, w := range strings.Split(s, " ") {
		cnt := [26]int{}
		for i, c := range w {
			i++
			cnt[c-'a']++
			ans = ans * i % mod
			mul = mul * cnt[c-'a'] % mod
		}
	}
	return ans * pow(mul, mod-2) % mod
}

func pow(x, n int) int {
	res := 1
	for ; n > 0; n >>= 1 {
		if n&1 > 0 {
			res = res * x % mod
		}
		x = x * x % mod
	}
	return res
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串&nbsp;<code>s</code>&nbsp;，它包含一个或者多个单词。单词之间用单个空格&nbsp;<code>' '</code>&nbsp;隔开。</p>

<p>如果字符串 <code>t</code>&nbsp;中第 <code>i</code>&nbsp;个单词是 <code>s</code>&nbsp;中第 <code>i</code>&nbsp;个单词的一个&nbsp;<strong>排列</strong>&nbsp;，那么我们称字符串&nbsp;<code>t</code>&nbsp;是字符串&nbsp;<code>s</code>&nbsp;的同位异构字符串。</p>

<ul>
	<li>比方说，<code>"acb dfe"</code>&nbsp;是&nbsp;<code>"abc def"</code>&nbsp;的同位异构字符串，但是&nbsp;<code>"def cab"</code>&nbsp;和&nbsp;<code>"adc bef"</code>&nbsp;不是。</li>
</ul>

<p>请你返回<em>&nbsp;</em><code>s</code>&nbsp;的同位异构字符串的数目，由于答案可能很大，请你将它对&nbsp;<code>10<sup>9</sup> + 7</code>&nbsp;<strong>取余</strong> 后返回。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>s = "too hot"
<b>输出：</b>18
<b>解释：</b>输入字符串的一些同位异构字符串为 "too hot" ，"oot hot" ，"oto toh" ，"too toh" 以及 "too oht" 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>s = "aa"
<b>输出：</b>1
<strong>解释：</strong>输入字符串只有一个同位异构字符串。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> 只包含小写英文字母和空格&nbsp;<code>' '</code>&nbsp;。</li>
	<li>相邻单词之间由单个空格隔开。</li>
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
    def countAnagrams(self, s: str) -> int:
        mod = 10**9 + 7
        ans = mul = 1
        for w in s.split():
            cnt = Counter()
            for i, c in enumerate(w, 1):
                cnt[c] += 1
                mul = mul * cnt[c] % mod
                ans = ans * i % mod
        return ans * pow(mul, -1, mod) % mod
```

#### Java

```java
import java.math.BigInteger;

class Solution {
    private static final int MOD = (int) 1e9 + 7;

    public int countAnagrams(String s) {
        int n = s.length();
        long[] f = new long[n + 1];
        f[0] = 1;
        for (int i = 1; i <= n; ++i) {
            f[i] = f[i - 1] * i % MOD;
        }
        long p = 1;
        for (String w : s.split(" ")) {
            int[] cnt = new int[26];
            for (int i = 0; i < w.length(); ++i) {
                ++cnt[w.charAt(i) - 'a'];
            }
            p = p * f[w.length()] % MOD;
            for (int v : cnt) {
                p = p * BigInteger.valueOf(f[v]).modInverse(BigInteger.valueOf(MOD)).intValue()
                    % MOD;
            }
        }
        return (int) p;
    }
}
```

#### C++

```cpp
class Solution {
public:
    const int mod = 1e9 + 7;

    int countAnagrams(string s) {
        stringstream ss(s);
        string w;
        long ans = 1, mul = 1;
        while (ss >> w) {
            int cnt[26] = {0};
            for (int i = 1; i <= w.size(); ++i) {
                int c = w[i - 1] - 'a';
                ++cnt[c];
                ans = ans * i % mod;
                mul = mul * cnt[c] % mod;
            }
        }
        return ans * pow(mul, mod - 2) % mod;
    }

    long pow(long x, int n) {
        long res = 1L;
        for (; n; n /= 2) {
            if (n % 2) res = res * x % mod;
            x = x * x % mod;
        }
        return res;
    }
};
```

#### Go

```go
const mod int = 1e9 + 7

func countAnagrams(s string) int {
	ans, mul := 1, 1
	for _, w := range strings.Split(s, " ") {
		cnt := [26]int{}
		for i, c := range w {
			i++
			cnt[c-'a']++
			ans = ans * i % mod
			mul = mul * cnt[c-'a'] % mod
		}
	}
	return ans * pow(mul, mod-2) % mod
}

func pow(x, n int) int {
	res := 1
	for ; n > 0; n >>= 1 {
		if n&1 > 0 {
			res = res * x % mod
		}
		x = x * x % mod
	}
	return res
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2515. 到目标字符串的最短距离](https://leetcode.cn/problems/shortest-distance-to-target-string-in-a-circular-array){#2515}

{{< tabs "2515" >}}

{{% tab "python" %}}
```python
class Solution:
    def closetTarget(self, words: List[str], target: str, startIndex: int) -> int:
        n = len(words)
        ans = n
        for i, w in enumerate(words):
            if w == target:
                t = abs(i - startIndex)
                ans = min(ans, t, n - t)
        return -1 if ans == n else ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int closetTarget(String[] words, String target, int startIndex) {
        int n = words.length;
        int ans = n;
        for (int i = 0; i < n; ++i) {
            String w = words[i];
            if (w.equals(target)) {
                int t = Math.abs(i - startIndex);
                ans = Math.min(ans, Math.min(t, n - t));
            }
        }
        return ans == n ? -1 : ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int ans = n;
        for (int i = 0; i < n; ++i) {
            auto w = words[i];
            if (w == target) {
                int t = abs(i - startIndex);
                ans = min(ans, min(t, n - t));
            }
        }
        return ans == n ? -1 : ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func closetTarget(words []string, target string, startIndex int) int {
	n := len(words)
	ans := n
	for i, w := range words {
		if w == target {
			t := abs(i - startIndex)
			ans = min(ans, min(t, n-t))
		}
	}
	if ans == n {
		return -1
	}
	return ans
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
function closetTarget(words: string[], target: string, startIndex: number): number {
    const n = words.length;
    for (let i = 0; i <= n >> 1; i++) {
        if (words[(startIndex - i + n) % n] === target || words[(startIndex + i) % n] === target) {
            return i;
        }
    }
    return -1;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::cmp::min;

impl Solution {
    pub fn closet_target(words: Vec<String>, target: String, start_index: i32) -> i32 {
        let mut ans = words.len();

        for (i, w) in words.iter().enumerate() {
            if *w == target {
                let t = ((i as i32) - start_index).abs();
                ans = min(ans, min(t as usize, words.len() - (t as usize)));
            }
        }

        if ans == words.len() {
            return -1;
        }

        ans as i32
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
int closetTarget(char** words, int wordsSize, char* target, int startIndex) {
    for (int i = 0; i <= wordsSize >> 1; i++) {
        if (strcmp(words[(startIndex - i + wordsSize) % wordsSize], target) == 0 || strcmp(words[(startIndex + i) % wordsSize], target) == 0) {
            return i;
        }
    }
    return -1;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong> 开始的 <strong>环形</strong> 字符串数组 <code>words</code> 和一个字符串 <code>target</code> 。<strong>环形数组</strong> 意味着数组首尾相连。</p>

<ul>
	<li>形式上， <code>words[i]</code> 的下一个元素是 <code>words[(i + 1) % n]</code> ，而 <code>words[i]</code> 的前一个元素是 <code>words[(i - 1 + n) % n]</code> ，其中 <code>n</code> 是 <code>words</code> 的长度。</li>
</ul>

<p>从 <code>startIndex</code> 开始，你一次可以用 <code>1</code> 步移动到下一个或者前一个单词。</p>

<p>返回到达目标字符串 <code>target</code> 所需的最短距离。如果 <code>words</code> 中不存在字符串 <code>target</code> ，返回 <code>-1</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>words = ["hello","i","am","leetcode","hello"], target = "hello", startIndex = 1
<strong>输出：</strong>1
<strong>解释：</strong>从下标 1 开始，可以经由以下步骤到达 "hello" ：
- 向右移动 3 个单位，到达下标 4 。
- 向左移动 2 个单位，到达下标 4 。
- 向右移动 4 个单位，到达下标 0 。
- 向左移动 1 个单位，到达下标 0 。
到达 "hello" 的最短距离是 1 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>words = ["a","b","leetcode"], target = "leetcode", startIndex = 0
<strong>输出：</strong>1
<strong>解释：</strong>从下标 0 开始，可以经由以下步骤到达 "leetcode" ：
- 向右移动 2 个单位，到达下标 3 。
- 向左移动 1 个单位，到达下标 3 。
到达 "leetcode" 的最短距离是 1 。</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>words = ["i","eat","leetcode"], target = "ate", startIndex = 0
<strong>输出：</strong>-1
<strong>解释：</strong>因为 words 中不存在字符串 "ate" ，所以返回 -1 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 100</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 100</code></li>
	<li><code>words[i]</code> 和 <code>target</code> 仅由小写英文字母组成</li>
	<li><code>0 &lt;= startIndex &lt; words.length</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：一次遍历

遍历数组，找到与 target 相等的单词，计算其与 startIndex 的距离 $t$，则此时的最短距离为 $min(t, n - t)$，我们只需要不断更新最小值即可。

时间复杂度 $O(n)$，空间复杂度 $O(1)$。其中 $n$ 为数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def closetTarget(self, words: List[str], target: str, startIndex: int) -> int:
        n = len(words)
        ans = n
        for i, w in enumerate(words):
            if w == target:
                t = abs(i - startIndex)
                ans = min(ans, t, n - t)
        return -1 if ans == n else ans
```

#### Java

```java
class Solution {
    public int closetTarget(String[] words, String target, int startIndex) {
        int n = words.length;
        int ans = n;
        for (int i = 0; i < n; ++i) {
            String w = words[i];
            if (w.equals(target)) {
                int t = Math.abs(i - startIndex);
                ans = Math.min(ans, Math.min(t, n - t));
            }
        }
        return ans == n ? -1 : ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int ans = n;
        for (int i = 0; i < n; ++i) {
            auto w = words[i];
            if (w == target) {
                int t = abs(i - startIndex);
                ans = min(ans, min(t, n - t));
            }
        }
        return ans == n ? -1 : ans;
    }
};
```

#### Go

```go
func closetTarget(words []string, target string, startIndex int) int {
	n := len(words)
	ans := n
	for i, w := range words {
		if w == target {
			t := abs(i - startIndex)
			ans = min(ans, min(t, n-t))
		}
	}
	if ans == n {
		return -1
	}
	return ans
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
function closetTarget(words: string[], target: string, startIndex: number): number {
    const n = words.length;
    for (let i = 0; i <= n >> 1; i++) {
        if (words[(startIndex - i + n) % n] === target || words[(startIndex + i) % n] === target) {
            return i;
        }
    }
    return -1;
}
```

#### Rust

```rust
impl Solution {
    pub fn closet_target(words: Vec<String>, target: String, start_index: i32) -> i32 {
        let start_index = start_index as usize;
        let n = words.len();
        for i in 0..=n >> 1 {
            if words[(start_index - i + n) % n] == target || words[(start_index + i) % n] == target
            {
                return i as i32;
            }
        }
        -1
    }
}
```

#### C

```c
int closetTarget(char** words, int wordsSize, char* target, int startIndex) {
    for (int i = 0; i <= wordsSize >> 1; i++) {
        if (strcmp(words[(startIndex - i + wordsSize) % wordsSize], target) == 0 || strcmp(words[(startIndex + i) % wordsSize], target) == 0) {
            return i;
        }
    }
    return -1;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### Rust

```rust
use std::cmp::min;

impl Solution {
    pub fn closet_target(words: Vec<String>, target: String, start_index: i32) -> i32 {
        let mut ans = words.len();

        for (i, w) in words.iter().enumerate() {
            if *w == target {
                let t = ((i as i32) - start_index).abs();
                ans = min(ans, min(t as usize, words.len() - (t as usize)));
            }
        }

        if ans == words.len() {
            return -1;
        }

        ans as i32
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2516. 每种字符至少取 K 个](https://leetcode.cn/problems/take-k-of-each-character-from-left-and-right){#2516}

{{< tabs "2516" >}}

{{% tab "python" %}}
```python
class Solution:
    def takeCharacters(self, s: str, k: int) -> int:
        cnt = Counter(s)
        if any(cnt[c] < k for c in "abc"):
            return -1
        mx = j = 0
        for i, c in enumerate(s):
            cnt[c] -= 1
            while cnt[c] < k:
                cnt[s[j]] += 1
                j += 1
            mx = max(mx, i - j + 1)
        return len(s) - mx
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int takeCharacters(String s, int k) {
        int[] cnt = new int[3];
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            ++cnt[s.charAt(i) - 'a'];
        }
        for (int x : cnt) {
            if (x < k) {
                return -1;
            }
        }
        int mx = 0, j = 0;
        for (int i = 0; i < n; ++i) {
            int c = s.charAt(i) - 'a';
            --cnt[c];
            while (cnt[c] < k) {
                ++cnt[s.charAt(j++) - 'a'];
            }
            mx = Math.max(mx, i - j + 1);
        }
        return n - mx;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int takeCharacters(string s, int k) {
        int cnt[3]{};
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            ++cnt[s[i] - 'a'];
        }
        for (int x : cnt) {
            if (x < k) {
                return -1;
            }
        }
        int mx = 0, j = 0;
        for (int i = 0; i < n; ++i) {
            int c = s[i] - 'a';
            --cnt[c];
            while (cnt[c] < k) {
                ++cnt[s[j++] - 'a'];
            }
            mx = max(mx, i - j + 1);
        }
        return n - mx;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func takeCharacters(s string, k int) int {
	cnt := [3]int{}
	for _, c := range s {
		cnt[c-'a']++
	}
	for _, x := range cnt {
		if x < k {
			return -1
		}
	}
	mx, j := 0, 0
	for i, c := range s {
		c -= 'a'
		for cnt[c]--; cnt[c] < k; j++ {
			cnt[s[j]-'a']++
		}
		mx = max(mx, i-j+1)
	}
	return len(s) - mx
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function takeCharacters(s: string, k: number): number {
    const idx = (c: string) => c.charCodeAt(0) - 97;
    const cnt: number[] = Array(3).fill(0);
    for (const c of s) {
        ++cnt[idx(c)];
    }
    if (cnt.some(v => v < k)) {
        return -1;
    }
    const n = s.length;
    let [mx, j] = [0, 0];
    for (let i = 0; i < n; ++i) {
        const c = idx(s[i]);
        --cnt[c];
        while (cnt[c] < k) {
            ++cnt[idx(s[j++])];
        }
        mx = Math.max(mx, i - j + 1);
    }
    return n - mx;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashMap;

impl Solution {
    pub fn take_characters(s: String, k: i32) -> i32 {
        let mut cnt: HashMap<char, i32> = HashMap::new();
        for c in s.chars() {
            *cnt.entry(c).or_insert(0) += 1;
        }

        if "abc".chars().any(|c| cnt.get(&c).unwrap_or(&0) < &k) {
            return -1;
        }

        let mut mx = 0;
        let mut j = 0;
        let mut cs = s.chars().collect::<Vec<char>>();
        for i in 0..cs.len() {
            let c = cs[i];
            *cnt.get_mut(&c).unwrap() -= 1;
            while cnt.get(&c).unwrap() < &k {
                *cnt.get_mut(&cs[j]).unwrap() += 1;
                j += 1;
            }
            mx = mx.max(i - j + 1);
        }
        (cs.len() as i32) - (mx as i32)
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个由字符 <code>'a'</code>、<code>'b'</code>、<code>'c'</code> 组成的字符串 <code>s</code> 和一个非负整数 <code>k</code> 。每分钟，你可以选择取走 <code>s</code> <strong>最左侧</strong> 还是 <strong>最右侧</strong> 的那个字符。</p>

<p>你必须取走每种字符 <strong>至少</strong> <code>k</code> 个，返回需要的 <strong>最少</strong> 分钟数；如果无法取到，则返回<em> </em><code>-1</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "aabaaaacaabc", k = 2
<strong>输出：</strong>8
<strong>解释：</strong>
从 s 的左侧取三个字符，现在共取到两个字符 'a' 、一个字符 'b' 。
从 s 的右侧取五个字符，现在共取到四个字符 'a' 、两个字符 'b' 和两个字符 'c' 。
共需要 3 + 5 = 8 分钟。
可以证明需要的最少分钟数是 8 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "a", k = 1
<strong>输出：</strong>-1
<strong>解释：</strong>无法取到一个字符 'b' 或者 'c'，所以返回 -1 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> 仅由字母 <code>'a'</code>、<code>'b'</code>、<code>'c'</code> 组成</li>
	<li><code>0 &lt;= k &lt;= s.length</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：滑动窗口

我们先用哈希表或者一个长度为 $3$ 的数组 $cnt$ 统计字符串 $s$ 中每个字符的个数，如果有字符的个数小于 $k$ 个，则无法取到，提前返回 $-1$。

题目要我们在字符串左侧以及右侧取走字符，最终取到的每种字符的个数都不少于 $k$ 个。我们不妨反着考虑问题，取走中间某个窗口大小的字符串，使得剩下的两侧字符串中，每种字符的个数都不少于 $k$ 个。

因此，我们维护一个滑动窗口，用指针 $j$ 和 $i$ 分别表示窗口的左右边界，窗口内的字符串是我们要取走的。我们每一次移动右边界 $i$，将对应的字符 $s[i]$ 加入到窗口中（也即取走一个字符 $s[i]$），此时如果 $cnt[s[i]]$ 个数小于 $k$，那么我们循环移动左边界 $j$，直到 $cnt[s[i]]$ 个数不小于 $k$ 为止。此时的窗口大小为 $i - j + 1$，更新最大窗口。

最终的答案就是字符串 $s$ 的长度减去最大窗口的大小。

时间复杂度 $O(n)$，其中 $n$ 为字符串 $s$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def takeCharacters(self, s: str, k: int) -> int:
        cnt = Counter(s)
        if any(cnt[c] < k for c in "abc"):
            return -1
        mx = j = 0
        for i, c in enumerate(s):
            cnt[c] -= 1
            while cnt[c] < k:
                cnt[s[j]] += 1
                j += 1
            mx = max(mx, i - j + 1)
        return len(s) - mx
```

#### Java

```java
class Solution {
    public int takeCharacters(String s, int k) {
        int[] cnt = new int[3];
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            ++cnt[s.charAt(i) - 'a'];
        }
        for (int x : cnt) {
            if (x < k) {
                return -1;
            }
        }
        int mx = 0, j = 0;
        for (int i = 0; i < n; ++i) {
            int c = s.charAt(i) - 'a';
            --cnt[c];
            while (cnt[c] < k) {
                ++cnt[s.charAt(j++) - 'a'];
            }
            mx = Math.max(mx, i - j + 1);
        }
        return n - mx;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int takeCharacters(string s, int k) {
        int cnt[3]{};
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            ++cnt[s[i] - 'a'];
        }
        for (int x : cnt) {
            if (x < k) {
                return -1;
            }
        }
        int mx = 0, j = 0;
        for (int i = 0; i < n; ++i) {
            int c = s[i] - 'a';
            --cnt[c];
            while (cnt[c] < k) {
                ++cnt[s[j++] - 'a'];
            }
            mx = max(mx, i - j + 1);
        }
        return n - mx;
    }
};
```

#### Go

```go
func takeCharacters(s string, k int) int {
	cnt := [3]int{}
	for _, c := range s {
		cnt[c-'a']++
	}
	for _, x := range cnt {
		if x < k {
			return -1
		}
	}
	mx, j := 0, 0
	for i, c := range s {
		c -= 'a'
		for cnt[c]--; cnt[c] < k; j++ {
			cnt[s[j]-'a']++
		}
		mx = max(mx, i-j+1)
	}
	return len(s) - mx
}
```

#### TypeScript

```ts
function takeCharacters(s: string, k: number): number {
    const idx = (c: string) => c.charCodeAt(0) - 97;
    const cnt: number[] = Array(3).fill(0);
    for (const c of s) {
        ++cnt[idx(c)];
    }
    if (cnt.some(v => v < k)) {
        return -1;
    }
    const n = s.length;
    let [mx, j] = [0, 0];
    for (let i = 0; i < n; ++i) {
        const c = idx(s[i]);
        --cnt[c];
        while (cnt[c] < k) {
            ++cnt[idx(s[j++])];
        }
        mx = Math.max(mx, i - j + 1);
    }
    return n - mx;
}
```

#### Rust

```rust
use std::collections::HashMap;

impl Solution {
    pub fn take_characters(s: String, k: i32) -> i32 {
        let mut cnt: HashMap<char, i32> = HashMap::new();
        for c in s.chars() {
            *cnt.entry(c).or_insert(0) += 1;
        }

        if "abc".chars().any(|c| cnt.get(&c).unwrap_or(&0) < &k) {
            return -1;
        }

        let mut mx = 0;
        let mut j = 0;
        let mut cs = s.chars().collect::<Vec<char>>();
        for i in 0..cs.len() {
            let c = cs[i];
            *cnt.get_mut(&c).unwrap() -= 1;
            while cnt.get(&c).unwrap() < &k {
                *cnt.get_mut(&cs[j]).unwrap() += 1;
                j += 1;
            }
            mx = mx.max(i - j + 1);
        }
        (cs.len() as i32) - (mx as i32)
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2517. 礼盒的最大甜蜜度](https://leetcode.cn/problems/maximum-tastiness-of-candy-basket){#2517}

{{< tabs "2517" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumTastiness(self, price: List[int], k: int) -> int:
        def check(x: int) -> bool:
            cnt, pre = 0, -x
            for cur in price:
                if cur - pre >= x:
                    pre = cur
                    cnt += 1
            return cnt >= k

        price.sort()
        l, r = 0, price[-1] - price[0]
        while l < r:
            mid = (l + r + 1) >> 1
            if check(mid):
                l = mid
            else:
                r = mid - 1
        return l
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maximumTastiness(int[] price, int k) {
        Arrays.sort(price);
        int l = 0, r = price[price.length - 1] - price[0];
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (check(price, k, mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }

    private boolean check(int[] price, int k, int x) {
        int cnt = 0, pre = -x;
        for (int cur : price) {
            if (cur - pre >= x) {
                pre = cur;
                ++cnt;
            }
        }
        return cnt >= k;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());
        int l = 0, r = price.back() - price[0];
        auto check = [&](int x) -> bool {
            int cnt = 0, pre = -x;
            for (int& cur : price) {
                if (cur - pre >= x) {
                    pre = cur;
                    ++cnt;
                }
            }
            return cnt >= k;
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
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumTastiness(price []int, k int) int {
	sort.Ints(price)
	return sort.Search(price[len(price)-1], func(x int) bool {
		cnt, pre := 0, -x
		for _, cur := range price {
			if cur-pre >= x {
				pre = cur
				cnt++
			}
		}
		return cnt < k
	}) - 1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumTastiness(price: number[], k: number): number {
    price.sort((a, b) => a - b);
    let l = 0;
    let r = price[price.length - 1] - price[0];
    const check = (x: number): boolean => {
        let [cnt, pre] = [0, -x];
        for (const cur of price) {
            if (cur - pre >= x) {
                pre = cur;
                ++cnt;
            }
        }
        return cnt >= k;
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
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int MaximumTastiness(int[] price, int k) {
        Array.Sort(price);
        int l = 0, r = price[price.Length - 1] - price[0];
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (check(price, mid, k)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }

    private bool check(int[] price, int x, int k) {
        int cnt = 0, pre = -x;
        foreach (int cur in price) {
            if (cur - pre >= x) {
                ++cnt;
                pre = cur;
            }
        }
        return cnt >= k;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个正整数数组 <code>price</code> ，其中 <code>price[i]</code> 表示第 <code>i</code> 类糖果的价格，另给你一个正整数 <code>k</code> 。</p>

<p>商店组合 <code>k</code> 类 <strong>不同</strong> 糖果打包成礼盒出售。礼盒的 <strong>甜蜜度</strong> 是礼盒中任意两种糖果 <strong>价格</strong> 绝对差的最小值。</p>

<p>返回礼盒的 <strong>最大 </strong>甜蜜度<em>。</em></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>price = [13,5,1,8,21,2], k = 3
<strong>输出：</strong>8
<strong>解释：</strong>选出价格分别为 [13,5,21] 的三类糖果。
礼盒的甜蜜度为 min(|13 - 5|, |13 - 21|, |5 - 21|) = min(8, 8, 16) = 8 。
可以证明能够取得的最大甜蜜度就是 8 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>price = [1,3,1], k = 2
<strong>输出：</strong>2
<strong>解释：</strong>选出价格分别为 [1,3] 的两类糖果。 
礼盒的甜蜜度为 min(|1 - 3|) = min(2) = 2 。
可以证明能够取得的最大甜蜜度就是 2 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>price = [7,7,7,7], k = 2
<strong>输出：</strong>0
<strong>解释：</strong>从现有的糖果中任选两类糖果，甜蜜度都会是 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= k &lt;= price.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= price[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 二分查找

我们注意到，如果一个甜蜜度为 $x$ 的礼盒是可行的，那么甜蜜度小于 $x$ 的礼盒也是可行的，这存在着单调性，因此我们可以使用二分查找的方法，找到最大的可行甜蜜度。

我们首先将数组 $price$ 排序，然后定义二分查找的左边界 $l=0$, $r=price[n-1]-price[0]$。每一次，我们计算出当前的中间值 $mid = \lfloor \frac{l+r+1}{2} \rfloor$，以 $mid$ 作为甜蜜度，判断是否可行。若可行，那么我们将左边界 $l$ 更新为 $mid$，否则将右边界 $r$ 更新为 $mid-1$。最后返回 $l$ 即可。

那么问题的关键转化为：判断一个甜蜜度是否可行，我们通过函数 $check(x)$ 来实现。函数 $check(x)$ 的执行逻辑如下：

定义一个变量 $cnt$ 表示当前已经选取的糖果的数量，初始值为 $0$，定义一个变量 $pre$ 表示上一个选取的糖果的价格，初始值为 $-x$。然后我们遍历排好序的数组 $price$，对于每一个糖果的价格 $cur$，如果 $cur-pre \geq x$，那么我们就选取这个糖果，将 $pre$ 更新为 $cur$，并将 $cnt$ 加一。最后判断 $cnt$ 是否大于等于 $k$，如果是，那么返回 $true$，否则返回 $false$。

时间复杂度 $O(n \times (\log n + \log M))$，空间复杂度 $O(\log n)$。其中 $n$ 是数组 $price$ 的长度；而 $M$ 是数组 $price$ 中的最大值，本题中 $M \leq 10^9$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumTastiness(self, price: List[int], k: int) -> int:
        def check(x: int) -> bool:
            cnt, pre = 0, -x
            for cur in price:
                if cur - pre >= x:
                    pre = cur
                    cnt += 1
            return cnt >= k

        price.sort()
        l, r = 0, price[-1] - price[0]
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
    public int maximumTastiness(int[] price, int k) {
        Arrays.sort(price);
        int l = 0, r = price[price.length - 1] - price[0];
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (check(price, k, mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }

    private boolean check(int[] price, int k, int x) {
        int cnt = 0, pre = -x;
        for (int cur : price) {
            if (cur - pre >= x) {
                pre = cur;
                ++cnt;
            }
        }
        return cnt >= k;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());
        int l = 0, r = price.back() - price[0];
        auto check = [&](int x) -> bool {
            int cnt = 0, pre = -x;
            for (int& cur : price) {
                if (cur - pre >= x) {
                    pre = cur;
                    ++cnt;
                }
            }
            return cnt >= k;
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
func maximumTastiness(price []int, k int) int {
	sort.Ints(price)
	return sort.Search(price[len(price)-1], func(x int) bool {
		cnt, pre := 0, -x
		for _, cur := range price {
			if cur-pre >= x {
				pre = cur
				cnt++
			}
		}
		return cnt < k
	}) - 1
}
```

#### TypeScript

```ts
function maximumTastiness(price: number[], k: number): number {
    price.sort((a, b) => a - b);
    let l = 0;
    let r = price[price.length - 1] - price[0];
    const check = (x: number): boolean => {
        let [cnt, pre] = [0, -x];
        for (const cur of price) {
            if (cur - pre >= x) {
                pre = cur;
                ++cnt;
            }
        }
        return cnt >= k;
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

#### C#

```cs
public class Solution {
    public int MaximumTastiness(int[] price, int k) {
        Array.Sort(price);
        int l = 0, r = price[price.Length - 1] - price[0];
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (check(price, mid, k)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }

    private bool check(int[] price, int x, int k) {
        int cnt = 0, pre = -x;
        foreach (int cur in price) {
            if (cur - pre >= x) {
                ++cnt;
                pre = cur;
            }
        }
        return cnt >= k;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2518. 好分区的数目](https://leetcode.cn/problems/number-of-great-partitions){#2518}

{{< tabs "2518" >}}

{{% tab "python" %}}
```python
class Solution:
    def countPartitions(self, nums: List[int], k: int) -> int:
        if sum(nums) < k * 2:
            return 0
        mod = 10**9 + 7
        n = len(nums)
        f = [[0] * k for _ in range(n + 1)]
        f[0][0] = 1
        ans = 1
        for i in range(1, n + 1):
            ans = ans * 2 % mod
            for j in range(k):
                f[i][j] = f[i - 1][j]
                if j >= nums[i - 1]:
                    f[i][j] = (f[i][j] + f[i - 1][j - nums[i - 1]]) % mod
        return (ans - sum(f[-1]) * 2 + mod) % mod
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private static final int MOD = (int) 1e9 + 7;

    public int countPartitions(int[] nums, int k) {
        long s = 0;
        for (int v : nums) {
            s += v;
        }
        if (s < k * 2) {
            return 0;
        }
        int n = nums.length;
        long[][] f = new long[n + 1][k];
        f[0][0] = 1;
        long ans = 1;
        for (int i = 1; i <= n; ++i) {
            int v = nums[i - 1];
            ans = ans * 2 % MOD;
            for (int j = 0; j < k; ++j) {
                f[i][j] = f[i - 1][j];
                if (j >= v) {
                    f[i][j] = (f[i][j] + f[i - 1][j - v]) % MOD;
                }
            }
        }
        for (int j = 0; j < k; ++j) {
            ans = (ans - f[n][j] * 2 % MOD + MOD) % MOD;
        }
        return (int) ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    const int mod = 1e9 + 7;

    int countPartitions(vector<int>& nums, int k) {
        long s = accumulate(nums.begin(), nums.end(), 0l);
        if (s < k * 2) return 0;
        int n = nums.size();
        long f[n + 1][k];
        int ans = 1;
        memset(f, 0, sizeof f);
        f[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            int v = nums[i - 1];
            ans = ans * 2 % mod;
            for (int j = 0; j < k; ++j) {
                f[i][j] = f[i - 1][j];
                if (j >= v) {
                    f[i][j] = (f[i][j] + f[i - 1][j - v]) % mod;
                }
            }
        }
        for (int j = 0; j < k; ++j) {
            ans = (ans - f[n][j] * 2 % mod + mod) % mod;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countPartitions(nums []int, k int) int {
	s := 0
	for _, v := range nums {
		s += v
	}
	if s < k*2 {
		return 0
	}
	const mod int = 1e9 + 7
	n := len(nums)
	f := make([][]int, n+1)
	for i := range f {
		f[i] = make([]int, k)
	}
	f[0][0] = 1
	ans := 1
	for i := 1; i <= n; i++ {
		v := nums[i-1]
		ans = ans * 2 % mod
		for j := 0; j < k; j++ {
			f[i][j] = f[i-1][j]
			if j >= v {
				f[i][j] = (f[i][j] + f[i-1][j-v]) % mod
			}
		}
	}
	for j := 0; j < k; j++ {
		ans = (ans - f[n][j]*2%mod + mod) % mod
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

<p>给你一个正整数数组 <code>nums</code> 和一个整数 <code>k</code> 。</p>

<p><strong>分区</strong> 的定义是：将数组划分成两个有序的 <strong>组</strong> ，并满足每个元素 <strong>恰好</strong> 存在于 <strong>某一个</strong> 组中。如果分区中每个组的元素和都大于等于 <code>k</code> ，则认为分区是一个好分区。</p>

<p>返回 <strong>不同</strong> 的好分区的数目。由于答案可能很大，请返回对 <code>10<sup>9</sup> + 7</code> <strong>取余</strong> 后的结果。</p>

<p>如果在两个分区中，存在某个元素 <code>nums[i]</code> 被分在不同的组中，则认为这两个分区不同。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3,4], k = 4
<strong>输出：</strong>6
<strong>解释：</strong>好分区的情况是 ([1,2,3], [4]), ([1,3], [2,4]), ([1,4], [2,3]), ([2,3], [1,4]), ([2,4], [1,3]) 和 ([4], [1,2,3]) 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [3,3,3], k = 4
<strong>输出：</strong>0
<strong>解释：</strong>数组中不存在好分区。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [6,6], k = 2
<strong>输出：</strong>2
<strong>解释：</strong>可以将 nums[0] 放入第一个分区或第二个分区中。
好分区的情况是 ([6], [6]) 和 ([6], [6]) 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length, k &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：逆向思维 + 动态规划

对于一个长度为 $n$ 的数组 `nums`，每个元素都可以选择放入第一个分区或第二个分区，因此一共有 $2^n$ 种分区方式。每一种分区方式，得到的结果可以是“好分区”或者“坏分区”，题目要我们求“好分区”的个数，我们可以转换为求“坏分区”的个数。那么“好分区”的个数就是 $2^n$ 减去“坏分区”的个数。

“坏分区”实际上就是从数组 `nums` 中选出若干个元素，使得这若干个元素之和不超过 $k$。这可以通过动态规划（0-1 背包问题）来求解。

我们用 $f[i][j]$ 表示从数组 `nums` 的前 $i$ 个元素中选出若干个元素，使得这若干个元素之和为 $j$ 的方案数。那么 $f[i][j]$ 的状态转移方程为：

$$
f[i][j] = \left\{
\begin{aligned}
&f[i - 1][j] & \textit{如果不选第 } i \textit{ 个元素} \\
&f[i - 1][j - nums[i - 1]] & \textit{如果选第 } i \textit{ 个元素}
\end{aligned}
\right.
$$

那么“坏分区”的个数就是 $\sum_{j=0}^{k-1} f[n][j] \times 2$，其中 $n$ 为数组 `nums` 的长度。最后，我们用 $2^n$ 减去“坏分区”的个数，即可得到“好分区”的个数。

时间复杂度 $O(n \times k)$，空间复杂度 $O(n \times k)$。其中 $n$ 为数组 `nums` 的长度，而 $k$ 为整数 $k$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countPartitions(self, nums: List[int], k: int) -> int:
        if sum(nums) < k * 2:
            return 0
        mod = 10**9 + 7
        n = len(nums)
        f = [[0] * k for _ in range(n + 1)]
        f[0][0] = 1
        ans = 1
        for i in range(1, n + 1):
            ans = ans * 2 % mod
            for j in range(k):
                f[i][j] = f[i - 1][j]
                if j >= nums[i - 1]:
                    f[i][j] = (f[i][j] + f[i - 1][j - nums[i - 1]]) % mod
        return (ans - sum(f[-1]) * 2 + mod) % mod
```

#### Java

```java
class Solution {
    private static final int MOD = (int) 1e9 + 7;

    public int countPartitions(int[] nums, int k) {
        long s = 0;
        for (int v : nums) {
            s += v;
        }
        if (s < k * 2) {
            return 0;
        }
        int n = nums.length;
        long[][] f = new long[n + 1][k];
        f[0][0] = 1;
        long ans = 1;
        for (int i = 1; i <= n; ++i) {
            int v = nums[i - 1];
            ans = ans * 2 % MOD;
            for (int j = 0; j < k; ++j) {
                f[i][j] = f[i - 1][j];
                if (j >= v) {
                    f[i][j] = (f[i][j] + f[i - 1][j - v]) % MOD;
                }
            }
        }
        for (int j = 0; j < k; ++j) {
            ans = (ans - f[n][j] * 2 % MOD + MOD) % MOD;
        }
        return (int) ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    const int mod = 1e9 + 7;

    int countPartitions(vector<int>& nums, int k) {
        long s = accumulate(nums.begin(), nums.end(), 0l);
        if (s < k * 2) return 0;
        int n = nums.size();
        long f[n + 1][k];
        int ans = 1;
        memset(f, 0, sizeof f);
        f[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            int v = nums[i - 1];
            ans = ans * 2 % mod;
            for (int j = 0; j < k; ++j) {
                f[i][j] = f[i - 1][j];
                if (j >= v) {
                    f[i][j] = (f[i][j] + f[i - 1][j - v]) % mod;
                }
            }
        }
        for (int j = 0; j < k; ++j) {
            ans = (ans - f[n][j] * 2 % mod + mod) % mod;
        }
        return ans;
    }
};
```

#### Go

```go
func countPartitions(nums []int, k int) int {
	s := 0
	for _, v := range nums {
		s += v
	}
	if s < k*2 {
		return 0
	}
	const mod int = 1e9 + 7
	n := len(nums)
	f := make([][]int, n+1)
	for i := range f {
		f[i] = make([]int, k)
	}
	f[0][0] = 1
	ans := 1
	for i := 1; i <= n; i++ {
		v := nums[i-1]
		ans = ans * 2 % mod
		for j := 0; j < k; j++ {
			f[i][j] = f[i-1][j]
			if j >= v {
				f[i][j] = (f[i][j] + f[i-1][j-v]) % mod
			}
		}
	}
	for j := 0; j < k; j++ {
		ans = (ans - f[n][j]*2%mod + mod) % mod
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2519. 统计 K-Big 索引的数量 🔒](https://leetcode.cn/problems/count-the-number-of-k-big-indices){#2519}

{{< tabs "2519" >}}

{{% tab "python" %}}
```python
class BinaryIndexedTree:
    def __init__(self, n):
        self.n = n
        self.c = [0] * (n + 1)

    def update(self, x, delta):
        while x <= self.n:
            self.c[x] += delta
            x += x & -x

    def query(self, x):
        s = 0
        while x:
            s += self.c[x]
            x -= x & -x
        return s


class Solution:
    def kBigIndices(self, nums: List[int], k: int) -> int:
        n = len(nums)
        tree1 = BinaryIndexedTree(n)
        tree2 = BinaryIndexedTree(n)
        for v in nums:
            tree2.update(v, 1)
        ans = 0
        for v in nums:
            tree2.update(v, -1)
            ans += tree1.query(v - 1) >= k and tree2.query(v - 1) >= k
            tree1.update(v, 1)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class BinaryIndexedTree {
    private int n;
    private int[] c;

    public BinaryIndexedTree(int n) {
        this.n = n;
        c = new int[n + 1];
    }

    public void update(int x, int delta) {
        while (x <= n) {
            c[x] += delta;
            x += x & -x;
        }
    }

    public int query(int x) {
        int s = 0;
        while (x > 0) {
            s += c[x];
            x -= x & -x;
        }
        return s;
    }
}

class Solution {
    public int kBigIndices(int[] nums, int k) {
        int n = nums.length;
        BinaryIndexedTree tree1 = new BinaryIndexedTree(n);
        BinaryIndexedTree tree2 = new BinaryIndexedTree(n);
        for (int v : nums) {
            tree2.update(v, 1);
        }
        int ans = 0;
        for (int v : nums) {
            tree2.update(v, -1);
            if (tree1.query(v - 1) >= k && tree2.query(v - 1) >= k) {
                ++ans;
            }
            tree1.update(v, 1);
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class BinaryIndexedTree {
public:
    BinaryIndexedTree(int _n)
        : n(_n)
        , c(_n + 1) {}

    void update(int x, int delta) {
        while (x <= n) {
            c[x] += delta;
            x += x & -x;
        }
    }

    int query(int x) {
        int s = 0;
        while (x) {
            s += c[x];
            x -= x & -x;
        }
        return s;
    }

private:
    int n;
    vector<int> c;
};

class Solution {
public:
    int kBigIndices(vector<int>& nums, int k) {
        int n = nums.size();
        BinaryIndexedTree* tree1 = new BinaryIndexedTree(n);
        BinaryIndexedTree* tree2 = new BinaryIndexedTree(n);
        for (int& v : nums) {
            tree2->update(v, 1);
        }
        int ans = 0;
        for (int& v : nums) {
            tree2->update(v, -1);
            ans += tree1->query(v - 1) >= k && tree2->query(v - 1) >= k;
            tree1->update(v, 1);
        }
        return ans;
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

func newBinaryIndexedTree(n int) *BinaryIndexedTree {
	c := make([]int, n+1)
	return &BinaryIndexedTree{n, c}
}

func (this *BinaryIndexedTree) update(x, delta int) {
	for x <= this.n {
		this.c[x] += delta
		x += x & -x
	}
}

func (this *BinaryIndexedTree) query(x int) int {
	s := 0
	for x > 0 {
		s += this.c[x]
		x -= x & -x
	}
	return s
}

func kBigIndices(nums []int, k int) (ans int) {
	n := len(nums)
	tree1 := newBinaryIndexedTree(n)
	tree2 := newBinaryIndexedTree(n)
	for _, v := range nums {
		tree2.update(v, 1)
	}
	for _, v := range nums {
		tree2.update(v, -1)
		if tree1.query(v-1) >= k && tree2.query(v-1) >= k {
			ans++
		}
		tree1.update(v, 1)
	}
	return
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
        this.c = new Array(n + 1).fill(0);
    }

    update(x: number, delta: number): void {
        while (x <= this.n) {
            this.c[x] += delta;
            x += x & -x;
        }
    }

    query(x: number): number {
        let s = 0;
        while (x > 0) {
            s += this.c[x];
            x -= x & -x;
        }
        return s;
    }
}

function kBigIndices(nums: number[], k: number): number {
    const n = Math.max(...nums);
    const tree1 = new BinaryIndexedTree(n);
    const tree2 = new BinaryIndexedTree(n);

    for (const v of nums) {
        tree2.update(v, 1);
    }

    let ans = 0;
    for (const v of nums) {
        tree2.update(v, -1);
        if (tree1.query(v - 1) >= k && tree2.query(v - 1) >= k) {
            ans++;
        }
        tree1.update(v, 1);
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

<p>给定一个 <strong>下标从0开始</strong> 的整数数组 <code>nums</code> 和一个正整数 <code>k</code> 。</p>

<p>如果满足以下条件，我们称下标 <code>i</code> 为 <strong>k-big</strong> ：</p>

<ul>
	<li>存在至少 <code>k</code> 个不同的索引 <code>idx1</code> ，满足 <code>idx1 &lt; i</code> 且 <code>nums[idx1] &lt; nums[i]</code> 。</li>
	<li>存在至少 <code>k</code> 个不同的索引 <code>idx2</code> ，满足 <code>idx2 &gt; i</code> 且 <code>nums[idx2] &lt; nums[i]</code> 。</li>
</ul>

<p>返回 k-big 索引的数量。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1 ：</strong></p>

<pre>
<b>输入：</b>nums = [2,3,6,5,2,3], k = 2
<b>输出：</b>2
<b>解释：</b>在nums中只有两个 2-big 的索引:
- i = 2 --&gt; 有两个有效的 idx1: 0 和 1。有三个有效的 idx2: 2、3 和 4。
- i = 3 --&gt; 有两个有效的 idx1: 0 和 1。有两个有效的 idx2: 3 和 4。</pre>

<p><strong class="example">示例 2 ：</strong></p>

<pre>
<b>输入：</b>nums = [1,1,1], k = 3
<b>输出：</b>0
<b>解释：</b>在 nums 中没有 3-big 的索引
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i], k &lt;= nums.length</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：树状数组

我们维护两个树状数组，一个记录当前位置左边小于当前位置的数的个数，另一个记录当前位置右边小于当前位置的数的个数。

遍历数组，对于当前位置，如果左边小于当前位置的数的个数大于等于 $k$，且右边小于当前位置的数的个数大于等于 $k$，则当前位置是 $k-big$，答案加一。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为数组长度。

<!-- tabs:start -->

#### Python3

```python
class BinaryIndexedTree:
    def __init__(self, n):
        self.n = n
        self.c = [0] * (n + 1)

    def update(self, x, delta):
        while x <= self.n:
            self.c[x] += delta
            x += x & -x

    def query(self, x):
        s = 0
        while x:
            s += self.c[x]
            x -= x & -x
        return s


class Solution:
    def kBigIndices(self, nums: List[int], k: int) -> int:
        n = len(nums)
        tree1 = BinaryIndexedTree(n)
        tree2 = BinaryIndexedTree(n)
        for v in nums:
            tree2.update(v, 1)
        ans = 0
        for v in nums:
            tree2.update(v, -1)
            ans += tree1.query(v - 1) >= k and tree2.query(v - 1) >= k
            tree1.update(v, 1)
        return ans
```

#### Java

```java
class BinaryIndexedTree {
    private int n;
    private int[] c;

    public BinaryIndexedTree(int n) {
        this.n = n;
        c = new int[n + 1];
    }

    public void update(int x, int delta) {
        while (x <= n) {
            c[x] += delta;
            x += x & -x;
        }
    }

    public int query(int x) {
        int s = 0;
        while (x > 0) {
            s += c[x];
            x -= x & -x;
        }
        return s;
    }
}

class Solution {
    public int kBigIndices(int[] nums, int k) {
        int n = nums.length;
        BinaryIndexedTree tree1 = new BinaryIndexedTree(n);
        BinaryIndexedTree tree2 = new BinaryIndexedTree(n);
        for (int v : nums) {
            tree2.update(v, 1);
        }
        int ans = 0;
        for (int v : nums) {
            tree2.update(v, -1);
            if (tree1.query(v - 1) >= k && tree2.query(v - 1) >= k) {
                ++ans;
            }
            tree1.update(v, 1);
        }
        return ans;
    }
}
```

#### C++

```cpp
class BinaryIndexedTree {
public:
    BinaryIndexedTree(int _n)
        : n(_n)
        , c(_n + 1) {}

    void update(int x, int delta) {
        while (x <= n) {
            c[x] += delta;
            x += x & -x;
        }
    }

    int query(int x) {
        int s = 0;
        while (x) {
            s += c[x];
            x -= x & -x;
        }
        return s;
    }

private:
    int n;
    vector<int> c;
};

class Solution {
public:
    int kBigIndices(vector<int>& nums, int k) {
        int n = nums.size();
        BinaryIndexedTree* tree1 = new BinaryIndexedTree(n);
        BinaryIndexedTree* tree2 = new BinaryIndexedTree(n);
        for (int& v : nums) {
            tree2->update(v, 1);
        }
        int ans = 0;
        for (int& v : nums) {
            tree2->update(v, -1);
            ans += tree1->query(v - 1) >= k && tree2->query(v - 1) >= k;
            tree1->update(v, 1);
        }
        return ans;
    }
};
```

#### Go

```go
type BinaryIndexedTree struct {
	n int
	c []int
}

func newBinaryIndexedTree(n int) *BinaryIndexedTree {
	c := make([]int, n+1)
	return &BinaryIndexedTree{n, c}
}

func (this *BinaryIndexedTree) update(x, delta int) {
	for x <= this.n {
		this.c[x] += delta
		x += x & -x
	}
}

func (this *BinaryIndexedTree) query(x int) int {
	s := 0
	for x > 0 {
		s += this.c[x]
		x -= x & -x
	}
	return s
}

func kBigIndices(nums []int, k int) (ans int) {
	n := len(nums)
	tree1 := newBinaryIndexedTree(n)
	tree2 := newBinaryIndexedTree(n)
	for _, v := range nums {
		tree2.update(v, 1)
	}
	for _, v := range nums {
		tree2.update(v, -1)
		if tree1.query(v-1) >= k && tree2.query(v-1) >= k {
			ans++
		}
		tree1.update(v, 1)
	}
	return
}
```

#### TypeScript

```ts
class BinaryIndexedTree {
    private n: number;
    private c: number[];

    constructor(n: number) {
        this.n = n;
        this.c = new Array(n + 1).fill(0);
    }

    update(x: number, delta: number): void {
        while (x <= this.n) {
            this.c[x] += delta;
            x += x & -x;
        }
    }

    query(x: number): number {
        let s = 0;
        while (x > 0) {
            s += this.c[x];
            x -= x & -x;
        }
        return s;
    }
}

function kBigIndices(nums: number[], k: number): number {
    const n = Math.max(...nums);
    const tree1 = new BinaryIndexedTree(n);
    const tree2 = new BinaryIndexedTree(n);

    for (const v of nums) {
        tree2.update(v, 1);
    }

    let ans = 0;
    for (const v of nums) {
        tree2.update(v, -1);
        if (tree1.query(v - 1) >= k && tree2.query(v - 1) >= k) {
            ans++;
        }
        tree1.update(v, 1);
    }

    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
