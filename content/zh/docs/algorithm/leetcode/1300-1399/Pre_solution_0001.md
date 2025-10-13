---
title: "1300_转变数组后最接近目标值的数组和"
date: 2025-10-08T18:37:12+08:00
weight: 1
tags: [二分查找, 二叉搜索树, 二叉树, 动态规划, 回溯, 字符串, 广度优先搜索, 排序, 数学, 数据库, 数组, 树, 深度优先搜索, 矩阵]
---

{{< markmap >}}
### [1300_转变数组后最接近目标值的数组和](#1300)
#### [数组](#1300)
#### [二分查找](#1300)
#### [排序](#1300)
### [1301_最大得分的路径数目](#1301)
#### [数组](#1301)
#### [动态规划](#1301)
#### [矩阵](#1301)
### [1302_层数最深叶子节点的和](#1302)
#### [树](#1302)
#### [深度优先搜索](#1302)
#### [广度优先搜索](#1302)
#### [二叉树](#1302)
### [1303_求团队人数 🔒](#1303)
#### [数据库](#1303)
### [1304_和为零的 N 个不同整数](#1304)
#### [数组](#1304)
#### [数学](#1304)
### [1305_两棵二叉搜索树中的所有元素](#1305)
#### [树](#1305)
#### [深度优先搜索](#1305)
#### [二叉搜索树](#1305)
#### [二叉树](#1305)
#### [排序](#1305)
### [1306_跳跃游戏 III](#1306)
#### [深度优先搜索](#1306)
#### [广度优先搜索](#1306)
#### [数组](#1306)
### [1307_口算难题](#1307)
#### [数组](#1307)
#### [数学](#1307)
#### [字符串](#1307)
#### [回溯](#1307)
### [1308_不同性别每日分数总计 🔒](#1308)
#### [数据库](#1308)
### [1309_解码字母到整数映射](#1309)
#### [字符串](#1309)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1300_转变数组后最接近目标值的数组和
___
#### 数组
___
#### 二分查找
___
#### 排序
---
### 1301_最大得分的路径数目
___
#### 数组
___
#### 动态规划
___
#### 矩阵
---
### 1302_层数最深叶子节点的和
___
#### 树
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 二叉树
---
### 1303_求团队人数 🔒
___
#### 数据库
---
### 1304_和为零的 N 个不同整数
___
#### 数组
___
#### 数学
---
### 1305_两棵二叉搜索树中的所有元素
___
#### 树
___
#### 深度优先搜索
___
#### 二叉搜索树
___
#### 二叉树
___
#### 排序
---
### 1306_跳跃游戏 III
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 数组
---
### 1307_口算难题
___
#### 数组
___
#### 数学
___
#### 字符串
___
#### 回溯
---
### 1308_不同性别每日分数总计 🔒
___
#### 数据库
---
### 1309_解码字母到整数映射
___
#### 字符串
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 二叉搜索树 | 二叉树 |
| 动态规划 | 回溯 | 字符串 |
| 广度优先搜索 | 排序 | 数学 |
| 数据库 | 数组 | 树 |
| 深度优先搜索 | 矩阵 |  |

# [1300. 转变数组后最接近目标值的数组和](https://leetcode.cn/problems/sum-of-mutated-array-closest-to-target){#1300}

{{< tabs "1300" >}}

{{% tab "python" %}}
```python
class Solution:
    def findBestValue(self, arr: List[int], target: int) -> int:
        arr.sort()
        s = list(accumulate(arr, initial=0))
        ans, diff = 0, inf
        for value in range(max(arr) + 1):
            i = bisect_right(arr, value)
            d = abs(s[i] + (len(arr) - i) * value - target)
            if diff > d:
                diff = d
                ans = value
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int findBestValue(int[] arr, int target) {
        Arrays.sort(arr);
        int n = arr.length;
        int[] s = new int[n + 1];
        int mx = 0;
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + arr[i];
            mx = Math.max(mx, arr[i]);
        }
        int ans = 0, diff = 1 << 30;
        for (int value = 0; value <= mx; ++value) {
            int i = search(arr, value);
            int d = Math.abs(s[i] + (n - i) * value - target);
            if (diff > d) {
                diff = d;
                ans = value;
            }
        }
        return ans;
    }

    private int search(int[] arr, int x) {
        int left = 0, right = arr.length;
        while (left < right) {
            int mid = (left + right) >> 1;
            if (arr[mid] > x) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int s[n + 1];
        s[0] = 0;
        int mx = 0;
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + arr[i];
            mx = max(mx, arr[i]);
        }
        int ans = 0, diff = 1 << 30;
        for (int value = 0; value <= mx; ++value) {
            int i = upper_bound(arr.begin(), arr.end(), value) - arr.begin();
            int d = abs(s[i] + (n - i) * value - target);
            if (diff > d) {
                diff = d;
                ans = value;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findBestValue(arr []int, target int) (ans int) {
	sort.Ints(arr)
	n := len(arr)
	s := make([]int, n+1)
	mx := slices.Max(arr)
	for i, x := range arr {
		s[i+1] = s[i] + x
	}
	diff := 1 << 30
	for value := 0; value <= mx; value++ {
		i := sort.SearchInts(arr, value+1)
		d := abs(s[i] + (n-i)*value - target)
		if diff > d {
			diff = d
			ans = value
		}
	}
	return
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组&nbsp;<code>arr</code> 和一个目标值&nbsp;<code>target</code> ，请你返回一个整数&nbsp;<code>value</code>&nbsp;，使得将数组中所有大于&nbsp;<code>value</code> 的值变成&nbsp;<code>value</code> 后，数组的和最接近&nbsp; <code>target</code>&nbsp;（最接近表示两者之差的绝对值最小）。</p>

<p>如果有多种使得和最接近&nbsp;<code>target</code>&nbsp;的方案，请你返回这些整数中的最小值。</p>

<p>请注意，答案不一定是&nbsp;<code>arr</code> 中的数字。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>arr = [4,9,3], target = 10
<strong>输出：</strong>3
<strong>解释：</strong>当选择 value 为 3 时，数组会变成 [3, 3, 3]，和为 9 ，这是最接近 target 的方案。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>arr = [2,3,5], target = 10
<strong>输出：</strong>5
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>arr = [60864,25176,27249,21296,20204], target = 56803
<strong>输出：</strong>11361
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 10^4</code></li>
	<li><code>1 &lt;= arr[i], target &lt;= 10^5</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 前缀和 + 二分查找 + 枚举

我们注意到，题目中要把所有大于 `value` 的值变成 `value`，并且求和，因此我们可以考虑先对数组 `arr` 进行排序，然后求出前缀和数组 $s$，其中 $s[i]$ 表示数组前 $i$ 个元素之和。

接下来，我们可以从小到大枚举所有 `value` 值，对于每个 `value`，我们可以通过二分查找找到数组中第一个大于 `value` 的元素的下标 $i$，此时数组中大于 `value` 的元素个数为 $n - i$，因此数组中小于等于 `value` 的元素个数为 $i$，此时数组中小于等于 `value` 的元素之和为 $s[i]$，数组中大于 `value` 的元素之和为 $(n - i) \times \textit{value}$，因此数组中所有元素之和为 $s[i] + (n - i) \times \textit{value}$。如果 $s[i] + (n - i) \times \textit{value}$ 与 `target` 的差的绝对值小于当前的最小差值 `diff`，则更新 `diff` 和 `ans`。

枚举完所有 `value` 后，即可得到最终答案 `ans`。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 `arr` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findBestValue(self, arr: List[int], target: int) -> int:
        arr.sort()
        s = list(accumulate(arr, initial=0))
        ans, diff = 0, inf
        for value in range(max(arr) + 1):
            i = bisect_right(arr, value)
            d = abs(s[i] + (len(arr) - i) * value - target)
            if diff > d:
                diff = d
                ans = value
        return ans
```

#### Java

```java
class Solution {
    public int findBestValue(int[] arr, int target) {
        Arrays.sort(arr);
        int n = arr.length;
        int[] s = new int[n + 1];
        int mx = 0;
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + arr[i];
            mx = Math.max(mx, arr[i]);
        }
        int ans = 0, diff = 1 << 30;
        for (int value = 0; value <= mx; ++value) {
            int i = search(arr, value);
            int d = Math.abs(s[i] + (n - i) * value - target);
            if (diff > d) {
                diff = d;
                ans = value;
            }
        }
        return ans;
    }

    private int search(int[] arr, int x) {
        int left = 0, right = arr.length;
        while (left < right) {
            int mid = (left + right) >> 1;
            if (arr[mid] > x) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int s[n + 1];
        s[0] = 0;
        int mx = 0;
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + arr[i];
            mx = max(mx, arr[i]);
        }
        int ans = 0, diff = 1 << 30;
        for (int value = 0; value <= mx; ++value) {
            int i = upper_bound(arr.begin(), arr.end(), value) - arr.begin();
            int d = abs(s[i] + (n - i) * value - target);
            if (diff > d) {
                diff = d;
                ans = value;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func findBestValue(arr []int, target int) (ans int) {
	sort.Ints(arr)
	n := len(arr)
	s := make([]int, n+1)
	mx := slices.Max(arr)
	for i, x := range arr {
		s[i+1] = s[i] + x
	}
	diff := 1 << 30
	for value := 0; value <= mx; value++ {
		i := sort.SearchInts(arr, value+1)
		d := abs(s[i] + (n-i)*value - target)
		if diff > d {
			diff = d
			ans = value
		}
	}
	return
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1301. 最大得分的路径数目](https://leetcode.cn/problems/number-of-paths-with-max-score){#1301}

{{< tabs "1301" >}}

{{% tab "python" %}}
```python
class Solution:
    def pathsWithMaxScore(self, board: List[str]) -> List[int]:
        def update(i, j, x, y):
            if x >= n or y >= n or f[x][y] == -1 or board[i][j] in "XS":
                return
            if f[x][y] > f[i][j]:
                f[i][j] = f[x][y]
                g[i][j] = g[x][y]
            elif f[x][y] == f[i][j]:
                g[i][j] += g[x][y]

        n = len(board)
        f = [[-1] * n for _ in range(n)]
        g = [[0] * n for _ in range(n)]
        f[-1][-1], g[-1][-1] = 0, 1
        for i in range(n - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                update(i, j, i + 1, j)
                update(i, j, i, j + 1)
                update(i, j, i + 1, j + 1)
                if f[i][j] != -1 and board[i][j].isdigit():
                    f[i][j] += int(board[i][j])
        mod = 10**9 + 7
        return [0, 0] if f[0][0] == -1 else [f[0][0], g[0][0] % mod]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private List<String> board;
    private int n;
    private int[][] f;
    private int[][] g;
    private final int mod = (int) 1e9 + 7;

    public int[] pathsWithMaxScore(List<String> board) {
        n = board.size();
        this.board = board;
        f = new int[n][n];
        g = new int[n][n];
        for (var e : f) {
            Arrays.fill(e, -1);
        }
        f[n - 1][n - 1] = 0;
        g[n - 1][n - 1] = 1;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                update(i, j, i + 1, j);
                update(i, j, i, j + 1);
                update(i, j, i + 1, j + 1);
                if (f[i][j] != -1) {
                    char c = board.get(i).charAt(j);
                    if (c >= '0' && c <= '9') {
                        f[i][j] += (c - '0');
                    }
                }
            }
        }
        int[] ans = new int[2];
        if (f[0][0] != -1) {
            ans[0] = f[0][0];
            ans[1] = g[0][0];
        }
        return ans;
    }

    private void update(int i, int j, int x, int y) {
        if (x >= n || y >= n || f[x][y] == -1 || board.get(i).charAt(j) == 'X'
            || board.get(i).charAt(j) == 'S') {
            return;
        }
        if (f[x][y] > f[i][j]) {
            f[i][j] = f[x][y];
            g[i][j] = g[x][y];
        } else if (f[x][y] == f[i][j]) {
            g[i][j] = (g[i][j] + g[x][y]) % mod;
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        const int mod = 1e9 + 7;
        int f[n][n];
        int g[n][n];
        memset(f, -1, sizeof(f));
        memset(g, 0, sizeof(g));
        f[n - 1][n - 1] = 0;
        g[n - 1][n - 1] = 1;

        auto update = [&](int i, int j, int x, int y) {
            if (x >= n || y >= n || f[x][y] == -1 || board[i][j] == 'X' || board[i][j] == 'S') {
                return;
            }
            if (f[x][y] > f[i][j]) {
                f[i][j] = f[x][y];
                g[i][j] = g[x][y];
            } else if (f[x][y] == f[i][j]) {
                g[i][j] = (g[i][j] + g[x][y]) % mod;
            }
        };

        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                update(i, j, i + 1, j);
                update(i, j, i, j + 1);
                update(i, j, i + 1, j + 1);
                if (f[i][j] != -1) {
                    if (board[i][j] >= '0' && board[i][j] <= '9') {
                        f[i][j] += (board[i][j] - '0');
                    }
                }
            }
        }
        vector<int> ans(2);
        if (f[0][0] != -1) {
            ans[0] = f[0][0];
            ans[1] = g[0][0];
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func pathsWithMaxScore(board []string) []int {
	n := len(board)
	f := make([][]int, n)
	g := make([][]int, n)
	for i := range f {
		f[i] = make([]int, n)
		g[i] = make([]int, n)
		for j := range f[i] {
			f[i][j] = -1
		}
	}
	f[n-1][n-1] = 0
	g[n-1][n-1] = 1
	const mod = 1e9 + 7

	update := func(i, j, x, y int) {
		if x >= n || y >= n || f[x][y] == -1 || board[i][j] == 'X' || board[i][j] == 'S' {
			return
		}
		if f[x][y] > f[i][j] {
			f[i][j] = f[x][y]
			g[i][j] = g[x][y]
		} else if f[x][y] == f[i][j] {
			g[i][j] = (g[i][j] + g[x][y]) % mod
		}
	}
	for i := n - 1; i >= 0; i-- {
		for j := n - 1; j >= 0; j-- {
			update(i, j, i+1, j)
			update(i, j, i, j+1)
			update(i, j, i+1, j+1)
			if f[i][j] != -1 && board[i][j] >= '0' && board[i][j] <= '9' {
				f[i][j] += int(board[i][j] - '0')
			}
		}
	}
	ans := make([]int, 2)
	if f[0][0] != -1 {
		ans[0], ans[1] = f[0][0], g[0][0]
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

<p>给你一个正方形字符数组&nbsp;<code>board</code>&nbsp;，你从数组最右下方的字符&nbsp;<code>&#39;S&#39;</code>&nbsp;出发。</p>

<p>你的目标是到达数组最左上角的字符&nbsp;<code>&#39;E&#39;</code> ，数组剩余的部分为数字字符&nbsp;<code>1, 2, ..., 9</code>&nbsp;或者障碍 <code>&#39;X&#39;</code>。在每一步移动中，你可以向上、向左或者左上方移动，可以移动的前提是到达的格子没有障碍。</p>

<p>一条路径的 「得分」 定义为：路径上所有数字的和。</p>

<p>请你返回一个列表，包含两个整数：第一个整数是 「得分」 的最大值，第二个整数是得到最大得分的方案数，请把结果对&nbsp;<strong><code>10^9 + 7</code></strong> <strong>取余</strong>。</p>

<p>如果没有任何路径可以到达终点，请返回&nbsp;<code>[0, 0]</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>board = [&quot;E23&quot;,&quot;2X2&quot;,&quot;12S&quot;]
<strong>输出：</strong>[7,1]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>board = [&quot;E12&quot;,&quot;1X1&quot;,&quot;21S&quot;]
<strong>输出：</strong>[4,2]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>board = [&quot;E11&quot;,&quot;XXX&quot;,&quot;11S&quot;]
<strong>输出：</strong>[0,0]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= board.length == board[i].length &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i][j]$ 表示从起点 $(n - 1, n - 1)$ 到达 $(i, j)$ 的最大得分，定义 $g[i][j]$ 表示从起点 $(n - 1, n - 1)$ 到达 $(i, j)$ 的最大得分的方案数。初始时 $f[n - 1][n - 1] = 0$，并且 $g[n - 1][n - 1] = 1$。其它位置的 $f[i][j]$ 均为 $-1$，而 $g[i][j]$ 均为 $0$。

对于当前位置 $(i, j)$，它可以由 $(i + 1, j)$, $(i, j + 1)$, $(i + 1, j + 1)$ 三个位置转移而来，因此我们可以枚举这三个位置，更新 $f[i][j]$ 和 $g[i][j]$ 的值。如果当前位置 $(i, j)$ 有障碍，或者当前位置是起点，或者其它位置越界，则不进行更新。否则，如果其它位置 $(x, y)$ 满足 $f[x][y] \gt f[i][j]$，那么我们更新 $f[i][j] = f[x][y]$，并且 $g[i][j] = g[x][y]$。如果 $f[x][y] = f[i][j]$，那么我们更新 $g[i][j] = g[i][j] + g[x][y]$。最后，如果当前位置 $(i, j)$ 可达并且是数字，我们更新 $f[i][j] = f[i][j] + board[i][j]$。

最后，如果 $f[0][0] \lt 0$，说明没有路径可以到达终点，返回 $[0, 0]$。否则，返回 $[f[0][0], g[0][0]]$。注意，返回结果需要对 $10^9 + 7$ 取余。

时间复杂度 $O(n^2)$，空间复杂度 $O(n^2)$。其中 $n$ 是数组的边长。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def pathsWithMaxScore(self, board: List[str]) -> List[int]:
        def update(i, j, x, y):
            if x >= n or y >= n or f[x][y] == -1 or board[i][j] in "XS":
                return
            if f[x][y] > f[i][j]:
                f[i][j] = f[x][y]
                g[i][j] = g[x][y]
            elif f[x][y] == f[i][j]:
                g[i][j] += g[x][y]

        n = len(board)
        f = [[-1] * n for _ in range(n)]
        g = [[0] * n for _ in range(n)]
        f[-1][-1], g[-1][-1] = 0, 1
        for i in range(n - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                update(i, j, i + 1, j)
                update(i, j, i, j + 1)
                update(i, j, i + 1, j + 1)
                if f[i][j] != -1 and board[i][j].isdigit():
                    f[i][j] += int(board[i][j])
        mod = 10**9 + 7
        return [0, 0] if f[0][0] == -1 else [f[0][0], g[0][0] % mod]
```

#### Java

```java
class Solution {
    private List<String> board;
    private int n;
    private int[][] f;
    private int[][] g;
    private final int mod = (int) 1e9 + 7;

    public int[] pathsWithMaxScore(List<String> board) {
        n = board.size();
        this.board = board;
        f = new int[n][n];
        g = new int[n][n];
        for (var e : f) {
            Arrays.fill(e, -1);
        }
        f[n - 1][n - 1] = 0;
        g[n - 1][n - 1] = 1;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                update(i, j, i + 1, j);
                update(i, j, i, j + 1);
                update(i, j, i + 1, j + 1);
                if (f[i][j] != -1) {
                    char c = board.get(i).charAt(j);
                    if (c >= '0' && c <= '9') {
                        f[i][j] += (c - '0');
                    }
                }
            }
        }
        int[] ans = new int[2];
        if (f[0][0] != -1) {
            ans[0] = f[0][0];
            ans[1] = g[0][0];
        }
        return ans;
    }

    private void update(int i, int j, int x, int y) {
        if (x >= n || y >= n || f[x][y] == -1 || board.get(i).charAt(j) == 'X'
            || board.get(i).charAt(j) == 'S') {
            return;
        }
        if (f[x][y] > f[i][j]) {
            f[i][j] = f[x][y];
            g[i][j] = g[x][y];
        } else if (f[x][y] == f[i][j]) {
            g[i][j] = (g[i][j] + g[x][y]) % mod;
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        const int mod = 1e9 + 7;
        int f[n][n];
        int g[n][n];
        memset(f, -1, sizeof(f));
        memset(g, 0, sizeof(g));
        f[n - 1][n - 1] = 0;
        g[n - 1][n - 1] = 1;

        auto update = [&](int i, int j, int x, int y) {
            if (x >= n || y >= n || f[x][y] == -1 || board[i][j] == 'X' || board[i][j] == 'S') {
                return;
            }
            if (f[x][y] > f[i][j]) {
                f[i][j] = f[x][y];
                g[i][j] = g[x][y];
            } else if (f[x][y] == f[i][j]) {
                g[i][j] = (g[i][j] + g[x][y]) % mod;
            }
        };

        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                update(i, j, i + 1, j);
                update(i, j, i, j + 1);
                update(i, j, i + 1, j + 1);
                if (f[i][j] != -1) {
                    if (board[i][j] >= '0' && board[i][j] <= '9') {
                        f[i][j] += (board[i][j] - '0');
                    }
                }
            }
        }
        vector<int> ans(2);
        if (f[0][0] != -1) {
            ans[0] = f[0][0];
            ans[1] = g[0][0];
        }
        return ans;
    }
};
```

#### Go

```go
func pathsWithMaxScore(board []string) []int {
	n := len(board)
	f := make([][]int, n)
	g := make([][]int, n)
	for i := range f {
		f[i] = make([]int, n)
		g[i] = make([]int, n)
		for j := range f[i] {
			f[i][j] = -1
		}
	}
	f[n-1][n-1] = 0
	g[n-1][n-1] = 1
	const mod = 1e9 + 7

	update := func(i, j, x, y int) {
		if x >= n || y >= n || f[x][y] == -1 || board[i][j] == 'X' || board[i][j] == 'S' {
			return
		}
		if f[x][y] > f[i][j] {
			f[i][j] = f[x][y]
			g[i][j] = g[x][y]
		} else if f[x][y] == f[i][j] {
			g[i][j] = (g[i][j] + g[x][y]) % mod
		}
	}
	for i := n - 1; i >= 0; i-- {
		for j := n - 1; j >= 0; j-- {
			update(i, j, i+1, j)
			update(i, j, i, j+1)
			update(i, j, i+1, j+1)
			if f[i][j] != -1 && board[i][j] >= '0' && board[i][j] <= '9' {
				f[i][j] += int(board[i][j] - '0')
			}
		}
	}
	ans := make([]int, 2)
	if f[0][0] != -1 {
		ans[0], ans[1] = f[0][0], g[0][0]
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1302. 层数最深叶子节点的和](https://leetcode.cn/problems/deepest-leaves-sum){#1302}

{{< tabs "1302" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def deepestLeavesSum(self, root: Optional[TreeNode]) -> int:
        def dfs(root, i):
            nonlocal ans, mx
            if root is None:
                return
            if i == mx:
                ans += root.val
            elif i > mx:
                ans = root.val
                mx = i
            dfs(root.left, i + 1)
            dfs(root.right, i + 1)

        ans = mx = 0
        dfs(root, 1)
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
    int mx;
    int ans;

    public int deepestLeavesSum(TreeNode root) {
        dfs(root, 1);
        return ans;
    }

    private void dfs(TreeNode root, int i) {
        if (root == null) {
            return;
        }
        if (i > mx) {
            mx = i;
            ans = root.val;
        } else if (i == mx) {
            ans += root.val;
        }
        dfs(root.left, i + 1);
        dfs(root.right, i + 1);
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
    int deepestLeavesSum(TreeNode* root) {
        int mx = 0, ans = 0;
        auto dfs = [&](this auto&& dfs, TreeNode* root, int i) {
            if (!root) {
                return;
            }
            if (i == mx) {
                ans += root->val;
            } else if (i > mx) {
                mx = i;
                ans = root->val;
            }
            dfs(root->left, i + 1);
            dfs(root->right, i + 1);
        };
        dfs(root, 1);
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
func deepestLeavesSum(root *TreeNode) int {
	ans, mx := 0, 0
	var dfs func(*TreeNode, int)
	dfs = func(root *TreeNode, i int) {
		if root == nil {
			return
		}
		if i == mx {
			ans += root.Val
		} else if i > mx {
			mx = i
			ans = root.Val
		}
		dfs(root.Left, i+1)
		dfs(root.Right, i+1)
	}
	dfs(root, 1)
	return ans
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

function deepestLeavesSum(root: TreeNode | null): number {
    let [ans, mx] = [0, 0];
    const dfs = (root: TreeNode | null, i: number) => {
        if (!root) {
            return;
        }
        if (i > mx) {
            mx = i;
            ans = root.val;
        } else if (i === mx) {
            ans += root.val;
        }
        dfs(root.left, i + 1);
        dfs(root.right, i + 1);
    };
    dfs(root, 1);
    return ans;
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
use std::collections::VecDeque;

impl Solution {
    pub fn deepest_leaves_sum(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut q = VecDeque::new();
        q.push_back(root);
        let mut ans = 0;
        while !q.is_empty() {
            ans = 0;
            for _ in 0..q.len() {
                if let Some(Some(node)) = q.pop_front() {
                    let node = node.borrow();
                    ans += node.val;
                    if node.left.is_some() {
                        q.push_back(node.left.clone());
                    }
                    if node.right.is_some() {
                        q.push_back(node.right.clone());
                    }
                }
            }
        }
        ans
    }
}
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

void dfs(struct TreeNode* root, int depth, int* maxDepth, int* res) {
    if (!root->left && !root->right) {
        if (depth == *maxDepth) {
            *res += root->val;
        } else if (depth > *maxDepth) {
            *maxDepth = depth;
            *res = root->val;
        }
        return;
    }
    if (root->left) {
        dfs(root->left, depth + 1, maxDepth, res);
    }
    if (root->right) {
        dfs(root->right, depth + 1, maxDepth, res);
    }
}

int deepestLeavesSum(struct TreeNode* root) {
    int res = 0;
    int maxDepth = 0;
    dfs(root, 0, &maxDepth, &res);
    return res;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一棵二叉树的根节点 <code>root</code> ，请你返回 <strong>层数最深的叶子节点的和</strong> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1300-1399/1302.Deepest%20Leaves%20Sum/images/1483_ex1.png" style="height: 265px; width: 273px;" /></strong></p>

<pre>
<strong>输入：</strong>root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
<strong>输出：</strong>15
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
<strong>输出：</strong>19
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点数目在范围 <code>[1, 10<sup>4</sup>]</code> 之间。</li>
	<li><code>1 <= Node.val <= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：BFS

我们可以使用广度优先搜索，逐层遍历二叉树，并在遍历到每一层时计算该层的节点值之和。遍历完成后，返回最后一层的节点值之和。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是树中节点的数目。

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
    def deepestLeavesSum(self, root: Optional[TreeNode]) -> int:
        q = deque([root])
        while q:
            ans = 0
            for _ in range(len(q)):
                node = q.popleft()
                ans += node.val
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
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
    public int deepestLeavesSum(TreeNode root) {
        Deque<TreeNode> q = new ArrayDeque<>();
        q.offer(root);
        int ans = 0;
        while (!q.isEmpty()) {
            ans = 0;
            for (int k = q.size(); k > 0; --k) {
                TreeNode node = q.poll();
                ans += node.val;
                if (node.left != null) {
                    q.offer(node.left);
                }
                if (node.right != null) {
                    q.offer(node.right);
                }
            }
        }
        return ans;
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
    int deepestLeavesSum(TreeNode* root) {
        int ans = 0;
        queue<TreeNode*> q{{root}};
        while (!q.empty()) {
            ans = 0;
            for (int k = q.size(); k; --k) {
                TreeNode* node = q.front();
                q.pop();
                ans += node->val;
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
        }
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
func deepestLeavesSum(root *TreeNode) (ans int) {
	q := []*TreeNode{root}
	for len(q) > 0 {
		ans = 0
		for k := len(q); k > 0; k-- {
			node := q[0]
			q = q[1:]
			ans += node.Val
			if node.Left != nil {
				q = append(q, node.Left)
			}
			if node.Right != nil {
				q = append(q, node.Right)
			}
		}
	}
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

function deepestLeavesSum(root: TreeNode | null): number {
    let q: TreeNode[] = [root];
    let ans = 0;
    while (q.length) {
        const nq: TreeNode[] = [];
        ans = 0;
        for (const { val, left, right } of q) {
            ans += val;
            left && nq.push(left);
            right && nq.push(right);
        }
        q = nq;
    }
    return ans;
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
use std::collections::VecDeque;

impl Solution {
    pub fn deepest_leaves_sum(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut q = VecDeque::new();
        q.push_back(root);
        let mut ans = 0;
        while !q.is_empty() {
            ans = 0;
            for _ in 0..q.len() {
                if let Some(Some(node)) = q.pop_front() {
                    let node = node.borrow();
                    ans += node.val;
                    if node.left.is_some() {
                        q.push_back(node.left.clone());
                    }
                    if node.right.is_some() {
                        q.push_back(node.right.clone());
                    }
                }
            }
        }
        ans
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：DFS

我们可以使用深度优先搜索，递归遍历二叉树，并在遍历的过程中记录当前节点的深度，以及最大深度和最深叶子节点的和。遍历到当前节点时，如果当前节点的深度等于最大深度，则将当前节点的值加到最深叶子节点的和中；如果当前节点的深度大于最大深度，则将最大深度更新为当前节点的深度，并将最深叶子节点的和更新为当前节点的值。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是树中节点的数目。

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
    def deepestLeavesSum(self, root: Optional[TreeNode]) -> int:
        def dfs(root, i):
            nonlocal ans, mx
            if root is None:
                return
            if i == mx:
                ans += root.val
            elif i > mx:
                ans = root.val
                mx = i
            dfs(root.left, i + 1)
            dfs(root.right, i + 1)

        ans = mx = 0
        dfs(root, 1)
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
    int mx;
    int ans;

    public int deepestLeavesSum(TreeNode root) {
        dfs(root, 1);
        return ans;
    }

    private void dfs(TreeNode root, int i) {
        if (root == null) {
            return;
        }
        if (i > mx) {
            mx = i;
            ans = root.val;
        } else if (i == mx) {
            ans += root.val;
        }
        dfs(root.left, i + 1);
        dfs(root.right, i + 1);
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
    int deepestLeavesSum(TreeNode* root) {
        int mx = 0, ans = 0;
        auto dfs = [&](this auto&& dfs, TreeNode* root, int i) {
            if (!root) {
                return;
            }
            if (i == mx) {
                ans += root->val;
            } else if (i > mx) {
                mx = i;
                ans = root->val;
            }
            dfs(root->left, i + 1);
            dfs(root->right, i + 1);
        };
        dfs(root, 1);
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
func deepestLeavesSum(root *TreeNode) int {
	ans, mx := 0, 0
	var dfs func(*TreeNode, int)
	dfs = func(root *TreeNode, i int) {
		if root == nil {
			return
		}
		if i == mx {
			ans += root.Val
		} else if i > mx {
			mx = i
			ans = root.Val
		}
		dfs(root.Left, i+1)
		dfs(root.Right, i+1)
	}
	dfs(root, 1)
	return ans
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

function deepestLeavesSum(root: TreeNode | null): number {
    let [ans, mx] = [0, 0];
    const dfs = (root: TreeNode | null, i: number) => {
        if (!root) {
            return;
        }
        if (i > mx) {
            mx = i;
            ans = root.val;
        } else if (i === mx) {
            ans += root.val;
        }
        dfs(root.left, i + 1);
        dfs(root.right, i + 1);
    };
    dfs(root, 1);
    return ans;
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

void dfs(struct TreeNode* root, int depth, int* maxDepth, int* res) {
    if (!root->left && !root->right) {
        if (depth == *maxDepth) {
            *res += root->val;
        } else if (depth > *maxDepth) {
            *maxDepth = depth;
            *res = root->val;
        }
        return;
    }
    if (root->left) {
        dfs(root->left, depth + 1, maxDepth, res);
    }
    if (root->right) {
        dfs(root->right, depth + 1, maxDepth, res);
    }
}

int deepestLeavesSum(struct TreeNode* root) {
    int res = 0;
    int maxDepth = 0;
    dfs(root, 0, &maxDepth, &res);
    return res;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1303. 求团队人数 🔒](https://leetcode.cn/problems/find-the-team-size){#1303}

{{< tabs "1303" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT e1.employee_id, COUNT(1) AS team_size
FROM
    Employee AS e1
    LEFT JOIN Employee AS e2 USING (team_id)
GROUP BY 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>员工表：<code>Employee</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| employee_id   | int     |
| team_id       | int     |
+---------------+---------+
employee_id 字段是这张表的主键(具有唯一值的列)
表中的每一行都包含每个员工的 ID 和他们所属的团队。
</pre>

<p>&nbsp;</p>

<p>编写解决方案以求得每个员工所在团队的总人数。</p>

<p>返回结果表 <strong>无顺序要求&nbsp;</strong>。</p>

<p>返回结果格式示例如下：</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
Employee Table:
+-------------+------------+
| employee_id | team_id    |
+-------------+------------+
|     1       |     8      |
|     2       |     8      |
|     3       |     8      |
|     4       |     7      |
|     5       |     9      |
|     6       |     9      |
+-------------+------------+
<strong>输出：</strong>
+-------------+------------+
| employee_id | team_size  |
+-------------+------------+
|     1       |     3      |
|     2       |     3      |
|     3       |     3      |
|     4       |     1      |
|     5       |     2      |
|     6       |     2      |
+-------------+------------+
<strong>解释：</strong>
ID 为 1、2、3 的员工是 team_id 为 8 的团队的成员，
ID 为 4 的员工是 team_id 为 7 的团队的成员，
ID 为 5、6 的员工是 team_id 为 9 的团队的成员。
</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：分组统计 + 等值连接

我们可以先统计出每个团队的人数，记录在 `T` 表中，然后我们将 `Employee` 表与 `T` 表按照 `team_id` 进行等值连接，即可得到每个员工所在团队的总人数。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT team_id, COUNT(1) AS team_size
        FROM Employee
        GROUP BY 1
    )
SELECT employee_id, team_size
FROM
    Employee
    JOIN T USING (team_id);
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：左连接

我们也可以使用左连接，将 `Employee` 表按照 `team_id` 进行自连接，然后按照 `employee_id` 进行分组，统计每个员工所在团队的总人数。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT e1.employee_id, COUNT(1) AS team_size
FROM
    Employee AS e1
    LEFT JOIN Employee AS e2 USING (team_id)
GROUP BY 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1304. 和为零的 N 个不同整数](https://leetcode.cn/problems/find-n-unique-integers-sum-up-to-zero){#1304}

{{< tabs "1304" >}}

{{% tab "python" %}}
```python
class Solution:
    def sumZero(self, n: int) -> List[int]:
        ans = list(range(1, n))
        ans.append(-sum(ans))
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] sumZero(int n) {
        int[] ans = new int[n];
        for (int i = 1; i < n; ++i) {
            ans[i] = i;
        }
        ans[0] = -(n * (n - 1) / 2);
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans(n);
        iota(ans.begin(), ans.end(), 1);
        ans[n - 1] = -(n - 1) * n / 2;
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func sumZero(n int) []int {
	ans := make([]int, n)
	for i := 1; i < n; i++ {
		ans[i] = i
	}
	ans[0] = -n * (n - 1) / 2
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function sumZero(n: number): number[] {
    const ans = new Array(n).fill(0);
    for (let i = 1; i < n; ++i) {
        ans[i] = i;
    }
    ans[0] = -((n * (n - 1)) / 2);
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn sum_zero(n: i32) -> Vec<i32> {
        let mut ans = vec![0; n as usize];
        for i in 1..n {
            ans[i as usize] = i;
        }
        ans[0] = -(n * (n - 1) / 2);
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

<p>给你一个整数&nbsp;<code>n</code>，请你返回 <strong>任意&nbsp;</strong>一个由 <code>n</code>&nbsp;个 <strong>各不相同&nbsp;</strong>的整数组成的数组，并且这 <code>n</code> 个数相加和为 <code>0</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>n = 5
<strong>输出：</strong>[-7,-1,1,3,4]
<strong>解释：</strong>这些数组也是正确的 [-5,-1,1,2,3]，[-3,-1,2,-2,4]。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>n = 3
<strong>输出：</strong>[-1,0,1]
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>n = 1
<strong>输出：</strong>[0]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：构造

我们可以从 $1$ 开始，依次将正数和负数交替放入结果数组中，一共循环 $\frac{n}{2}$ 次，如果 $n$ 为奇数，则最后再将 $0$ 放入结果数组中。

时间复杂度 $O(n)$，其中 $n$ 为给定的整数。忽略答案的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def sumZero(self, n: int) -> List[int]:
        ans = []
        for i in range(n >> 1):
            ans.append(i + 1)
            ans.append(-(i + 1))
        if n & 1:
            ans.append(0)
        return ans
```

#### Java

```java
class Solution {
    public int[] sumZero(int n) {
        int[] ans = new int[n];
        for (int i = 1, j = 0; i <= n / 2; ++i) {
            ans[j++] = i;
            ans[j++] = -i;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans(n);
        for (int i = 1, j = 0; i <= n / 2; ++i) {
            ans[j++] = i;
            ans[j++] = -i;
        }
        return ans;
    }
};
```

#### Go

```go
func sumZero(n int) []int {
	ans := make([]int, n)
	for i, j := 1, 0; i <= n/2; i, j = i+1, j+1 {
		ans[j] = i
		j++
		ans[j] = -i
	}
	return ans
}
```

#### TypeScript

```ts
function sumZero(n: number): number[] {
    const ans: number[] = Array(n).fill(0);
    for (let i = 1, j = 0; i <= n / 2; ++i) {
        ans[j++] = i;
        ans[j++] = -i;
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn sum_zero(n: i32) -> Vec<i32> {
        let mut ans = vec![0; n as usize];
        let mut j = 0;
        for i in 1..=n / 2 {
            ans[j] = i;
            j += 1;
            ans[j] = -i;
            j += 1;
        }
        ans
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：构造 + 数学

我们也可以将 $1$ 到 $n-1$ 的所有整数放入结果数组中，最后再把前 $n-1$ 个整数的和 $\frac{n(n-1)}{2}$ 的相反数放入结果数组中。

时间复杂度 $O(n)$，其中 $n$ 为给定的整数。忽略答案的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def sumZero(self, n: int) -> List[int]:
        ans = list(range(1, n))
        ans.append(-sum(ans))
        return ans
```

#### Java

```java
class Solution {
    public int[] sumZero(int n) {
        int[] ans = new int[n];
        for (int i = 1; i < n; ++i) {
            ans[i] = i;
        }
        ans[0] = -(n * (n - 1) / 2);
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans(n);
        iota(ans.begin(), ans.end(), 1);
        ans[n - 1] = -(n - 1) * n / 2;
        return ans;
    }
};
```

#### Go

```go
func sumZero(n int) []int {
	ans := make([]int, n)
	for i := 1; i < n; i++ {
		ans[i] = i
	}
	ans[0] = -n * (n - 1) / 2
	return ans
}
```

#### TypeScript

```ts
function sumZero(n: number): number[] {
    const ans = new Array(n).fill(0);
    for (let i = 1; i < n; ++i) {
        ans[i] = i;
    }
    ans[0] = -((n * (n - 1)) / 2);
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn sum_zero(n: i32) -> Vec<i32> {
        let mut ans = vec![0; n as usize];
        for i in 1..n {
            ans[i as usize] = i;
        }
        ans[0] = -(n * (n - 1) / 2);
        ans
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1305. 两棵二叉搜索树中的所有元素](https://leetcode.cn/problems/all-elements-in-two-binary-search-trees){#1305}

{{< tabs "1305" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getAllElements(
        self, root1: Optional[TreeNode], root2: Optional[TreeNode]
    ) -> List[int]:
        def dfs(root: Optional[TreeNode], nums: List[int]) -> int:
            if root is None:
                return
            dfs(root.left, nums)
            nums.append(root.val)
            dfs(root.right, nums)

        a, b = [], []
        dfs(root1, a)
        dfs(root2, b)
        m, n = len(a), len(b)
        i = j = 0
        ans = []
        while i < m and j < n:
            if a[i] <= b[j]:
                ans.append(a[i])
                i += 1
            else:
                ans.append(b[j])
                j += 1
        while i < m:
            ans.append(a[i])
            i += 1
        while j < n:
            ans.append(b[j])
            j += 1
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
    public List<Integer> getAllElements(TreeNode root1, TreeNode root2) {
        List<Integer> a = new ArrayList<>();
        List<Integer> b = new ArrayList<>();
        dfs(root1, a);
        dfs(root2, b);
        int m = a.size(), n = b.size();
        int i = 0, j = 0;
        List<Integer> ans = new ArrayList<>();
        while (i < m && j < n) {
            if (a.get(i) <= b.get(j)) {
                ans.add(a.get(i++));
            } else {
                ans.add(b.get(j++));
            }
        }
        while (i < m) {
            ans.add(a.get(i++));
        }
        while (j < n) {
            ans.add(b.get(j++));
        }
        return ans;
    }

    private void dfs(TreeNode root, List<Integer> nums) {
        if (root == null) {
            return;
        }
        dfs(root.left, nums);
        nums.add(root.val);
        dfs(root.right, nums);
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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> a, b, ans;
        dfs(root1, a);
        dfs(root2, b);

        int i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i] <= b[j]) {
                ans.push_back(a[i++]);
            } else {
                ans.push_back(b[j++]);
            }
        }
        while (i < a.size()) {
            ans.push_back(a[i++]);
        }
        while (j < b.size()) {
            ans.push_back(b[j++]);
        }
        return ans;
    }

private:
    void dfs(TreeNode* root, vector<int>& nums) {
        if (root == nullptr) {
            return;
        }
        dfs(root->left, nums);
        nums.push_back(root->val);
        dfs(root->right, nums);
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
func getAllElements(root1 *TreeNode, root2 *TreeNode) (ans []int) {
	var dfs func(*TreeNode, *[]int)
	dfs = func(root *TreeNode, nums *[]int) {
		if root == nil {
			return
		}
		dfs(root.Left, nums)
		*nums = append(*nums, root.Val)
		dfs(root.Right, nums)
	}
	a, b := []int{}, []int{}
	dfs(root1, &a)
	dfs(root2, &b)
	i, j := 0, 0
	m, n := len(a), len(b)
	for i < m && j < n {
		if a[i] < b[j] {
			ans = append(ans, a[i])
			i++
		} else {
			ans = append(ans, b[j])
			j++
		}
	}
	for ; i < m; i++ {
		ans = append(ans, a[i])
	}
	for ; j < n; j++ {
		ans = append(ans, b[j])
	}
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

function getAllElements(root1: TreeNode | null, root2: TreeNode | null): number[] {
    const dfs = (root: TreeNode | null, nums: number[]) => {
        if (!root) {
            return;
        }
        dfs(root.left, nums);
        nums.push(root.val);
        dfs(root.right, nums);
    };
    const a: number[] = [];
    const b: number[] = [];
    dfs(root1, a);
    dfs(root2, b);
    const [m, n] = [a.length, b.length];
    const ans: number[] = [];
    let [i, j] = [0, 0];
    while (i < m && j < n) {
        if (a[i] < b[j]) {
            ans.push(a[i++]);
        } else {
            ans.push(b[j++]);
        }
    }
    while (i < m) {
        ans.push(a[i++]);
    }
    while (j < n) {
        ans.push(b[j++]);
    }
    return ans;
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
use std::cell::RefCell;
use std::rc::Rc;
impl Solution {
    pub fn get_all_elements(
        root1: Option<Rc<RefCell<TreeNode>>>,
        root2: Option<Rc<RefCell<TreeNode>>>,
    ) -> Vec<i32> {
        let mut a = Vec::new();
        let mut b = Vec::new();

        Solution::dfs(&root1, &mut a);
        Solution::dfs(&root2, &mut b);

        let mut ans = Vec::new();
        let (mut i, mut j) = (0, 0);

        while i < a.len() && j < b.len() {
            if a[i] <= b[j] {
                ans.push(a[i]);
                i += 1;
            } else {
                ans.push(b[j]);
                j += 1;
            }
        }

        while i < a.len() {
            ans.push(a[i]);
            i += 1;
        }

        while j < b.len() {
            ans.push(b[j]);
            j += 1;
        }

        ans
    }

    fn dfs(root: &Option<Rc<RefCell<TreeNode>>>, nums: &mut Vec<i32>) {
        if let Some(node) = root {
            let node = node.borrow();
            Solution::dfs(&node.left, nums);
            nums.push(node.val);
            Solution::dfs(&node.right, nums);
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

<p>给你&nbsp;<code>root1</code> 和 <code>root2</code>&nbsp;这两棵二叉搜索树。请你返回一个列表，其中包含&nbsp;<strong>两棵树&nbsp;</strong>中的所有整数并按 <strong>升序</strong> 排序。.</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1300-1399/1305.All%20Elements%20in%20Two%20Binary%20Search%20Trees/images/q2-e1.png" /></p>

<pre>
<strong>输入：</strong>root1 = [2,1,4], root2 = [1,0,3]
<strong>输出：</strong>[0,1,1,2,3,4]
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1300-1399/1305.All%20Elements%20in%20Two%20Binary%20Search%20Trees/images/q2-e5-.png" /></p>

<pre>
<strong>输入：</strong>root1 = [1,null,8], root2 = [8,1]
<strong>输出：</strong>[1,1,8,8]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>每棵树的节点数在&nbsp;<code>[0, 5000]</code> 范围内</li>
	<li><code>-10<sup>5</sup>&nbsp;&lt;= Node.val &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS + 归并

由于两棵树都是二叉搜索树，所以我们可以通过中序遍历得到两棵树的节点值序列 $\textit{a}$ 和 $\textit{b}$，然后使用双指针归并两个有序数组，得到最终的答案。

时间复杂度 $O(n+m)$，空间复杂度 $O(n+m)$。其中 $n$ 和 $m$ 分别是两棵树的节点数。

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
    def getAllElements(
        self, root1: Optional[TreeNode], root2: Optional[TreeNode]
    ) -> List[int]:
        def dfs(root: Optional[TreeNode], nums: List[int]) -> int:
            if root is None:
                return
            dfs(root.left, nums)
            nums.append(root.val)
            dfs(root.right, nums)

        a, b = [], []
        dfs(root1, a)
        dfs(root2, b)
        m, n = len(a), len(b)
        i = j = 0
        ans = []
        while i < m and j < n:
            if a[i] <= b[j]:
                ans.append(a[i])
                i += 1
            else:
                ans.append(b[j])
                j += 1
        while i < m:
            ans.append(a[i])
            i += 1
        while j < n:
            ans.append(b[j])
            j += 1
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
    public List<Integer> getAllElements(TreeNode root1, TreeNode root2) {
        List<Integer> a = new ArrayList<>();
        List<Integer> b = new ArrayList<>();
        dfs(root1, a);
        dfs(root2, b);
        int m = a.size(), n = b.size();
        int i = 0, j = 0;
        List<Integer> ans = new ArrayList<>();
        while (i < m && j < n) {
            if (a.get(i) <= b.get(j)) {
                ans.add(a.get(i++));
            } else {
                ans.add(b.get(j++));
            }
        }
        while (i < m) {
            ans.add(a.get(i++));
        }
        while (j < n) {
            ans.add(b.get(j++));
        }
        return ans;
    }

    private void dfs(TreeNode root, List<Integer> nums) {
        if (root == null) {
            return;
        }
        dfs(root.left, nums);
        nums.add(root.val);
        dfs(root.right, nums);
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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> a, b, ans;
        dfs(root1, a);
        dfs(root2, b);

        int i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i] <= b[j]) {
                ans.push_back(a[i++]);
            } else {
                ans.push_back(b[j++]);
            }
        }
        while (i < a.size()) {
            ans.push_back(a[i++]);
        }
        while (j < b.size()) {
            ans.push_back(b[j++]);
        }
        return ans;
    }

private:
    void dfs(TreeNode* root, vector<int>& nums) {
        if (root == nullptr) {
            return;
        }
        dfs(root->left, nums);
        nums.push_back(root->val);
        dfs(root->right, nums);
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
func getAllElements(root1 *TreeNode, root2 *TreeNode) (ans []int) {
	var dfs func(*TreeNode, *[]int)
	dfs = func(root *TreeNode, nums *[]int) {
		if root == nil {
			return
		}
		dfs(root.Left, nums)
		*nums = append(*nums, root.Val)
		dfs(root.Right, nums)
	}
	a, b := []int{}, []int{}
	dfs(root1, &a)
	dfs(root2, &b)
	i, j := 0, 0
	m, n := len(a), len(b)
	for i < m && j < n {
		if a[i] < b[j] {
			ans = append(ans, a[i])
			i++
		} else {
			ans = append(ans, b[j])
			j++
		}
	}
	for ; i < m; i++ {
		ans = append(ans, a[i])
	}
	for ; j < n; j++ {
		ans = append(ans, b[j])
	}
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

function getAllElements(root1: TreeNode | null, root2: TreeNode | null): number[] {
    const dfs = (root: TreeNode | null, nums: number[]) => {
        if (!root) {
            return;
        }
        dfs(root.left, nums);
        nums.push(root.val);
        dfs(root.right, nums);
    };
    const a: number[] = [];
    const b: number[] = [];
    dfs(root1, a);
    dfs(root2, b);
    const [m, n] = [a.length, b.length];
    const ans: number[] = [];
    let [i, j] = [0, 0];
    while (i < m && j < n) {
        if (a[i] < b[j]) {
            ans.push(a[i++]);
        } else {
            ans.push(b[j++]);
        }
    }
    while (i < m) {
        ans.push(a[i++]);
    }
    while (j < n) {
        ans.push(b[j++]);
    }
    return ans;
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
use std::cell::RefCell;
use std::rc::Rc;
impl Solution {
    pub fn get_all_elements(
        root1: Option<Rc<RefCell<TreeNode>>>,
        root2: Option<Rc<RefCell<TreeNode>>>,
    ) -> Vec<i32> {
        let mut a = Vec::new();
        let mut b = Vec::new();

        Solution::dfs(&root1, &mut a);
        Solution::dfs(&root2, &mut b);

        let mut ans = Vec::new();
        let (mut i, mut j) = (0, 0);

        while i < a.len() && j < b.len() {
            if a[i] <= b[j] {
                ans.push(a[i]);
                i += 1;
            } else {
                ans.push(b[j]);
                j += 1;
            }
        }

        while i < a.len() {
            ans.push(a[i]);
            i += 1;
        }

        while j < b.len() {
            ans.push(b[j]);
            j += 1;
        }

        ans
    }

    fn dfs(root: &Option<Rc<RefCell<TreeNode>>>, nums: &mut Vec<i32>) {
        if let Some(node) = root {
            let node = node.borrow();
            Solution::dfs(&node.left, nums);
            nums.push(node.val);
            Solution::dfs(&node.right, nums);
        }
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1306. 跳跃游戏 III](https://leetcode.cn/problems/jump-game-iii){#1306}

{{< tabs "1306" >}}

{{% tab "python" %}}
```python
class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        q = deque([start])
        while q:
            i = q.popleft()
            if arr[i] == 0:
                return True
            x = arr[i]
            arr[i] = -1
            for j in (i + x, i - x):
                if 0 <= j < len(arr) and arr[j] >= 0:
                    q.append(j)
        return False
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean canReach(int[] arr, int start) {
        Deque<Integer> q = new ArrayDeque<>();
        q.offer(start);
        while (!q.isEmpty()) {
            int i = q.poll();
            if (arr[i] == 0) {
                return true;
            }
            int x = arr[i];
            arr[i] = -1;
            for (int j : List.of(i + x, i - x)) {
                if (j >= 0 && j < arr.length && arr[j] >= 0) {
                    q.offer(j);
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
    bool canReach(vector<int>& arr, int start) {
        queue<int> q{{start}};
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            if (arr[i] == 0) {
                return true;
            }
            int x = arr[i];
            arr[i] = -1;
            for (int j : {i + x, i - x}) {
                if (j >= 0 && j < arr.size() && ~arr[j]) {
                    q.push(j);
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
func canReach(arr []int, start int) bool {
	q := []int{start}
	for len(q) > 0 {
		i := q[0]
		q = q[1:]
		if arr[i] == 0 {
			return true
		}
		x := arr[i]
		arr[i] = -1
		for _, j := range []int{i + x, i - x} {
			if j >= 0 && j < len(arr) && arr[j] >= 0 {
				q = append(q, j)
			}
		}
	}
	return false
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function canReach(arr: number[], start: number): boolean {
    const q = [start];
    for (const i of q) {
        if (arr[i] === 0) {
            return true;
        }
        if (arr[i] === -1 || arr[i] === undefined) {
            continue;
        }
        q.push(i + arr[i], i - arr[i]);
        arr[i] = -1;
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

<p>这里有一个非负整数数组&nbsp;<code>arr</code>，你最开始位于该数组的起始下标&nbsp;<code>start</code>&nbsp;处。当你位于下标&nbsp;<code>i</code>&nbsp;处时，你可以跳到&nbsp;<code>i + arr[i]</code> 或者 <code>i - arr[i]</code>。</p>

<p>请你判断自己是否能够跳到对应元素值为 0 的 <strong>任一</strong> 下标处。</p>

<p>注意，不管是什么情况下，你都无法跳到数组之外。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>arr = [4,2,3,0,3,1,2], start = 5
<strong>输出：</strong>true
<strong>解释：</strong>
到达值为 0 的下标 3 有以下可能方案： 
下标 5 -&gt; 下标 4 -&gt; 下标 1 -&gt; 下标 3 
下标 5 -&gt; 下标 6 -&gt; 下标 4 -&gt; 下标 1 -&gt; 下标 3 
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>arr = [4,2,3,0,3,1,2], start = 0
<strong>输出：</strong>true 
<strong>解释：
</strong>到达值为 0 的下标 3 有以下可能方案： 
下标 0 -&gt; 下标 4 -&gt; 下标 1 -&gt; 下标 3
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>arr = [3,0,2,1,2], start = 2
<strong>输出：</strong>false
<strong>解释：</strong>无法到达值为 0 的下标 1 处。 
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 5 * 10^4</code></li>
	<li><code>0 &lt;= arr[i] &lt;&nbsp;arr.length</code></li>
	<li><code>0 &lt;= start &lt; arr.length</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：BFS

我们可以使用 BFS 来判断是否能够到达值为 $0$ 的下标。

定义一个队列 $q$，用于存储当前能够到达的下标。初始时，将 $start$ 下标入队。

当队列不为空时，取出队首下标 $i$，如果 $arr[i] = 0$，则返回 `true`。否则，我们将下标 $i$ 标记为已访问，如果 $i + arr[i]$ 和 $i - arr[i]$ 在数组范围内且未被访问过，则将其入队，继续搜索。

最后，如果队列为空，说明无法到达值为 $0$ 的下标，返回 `false`。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        q = deque([start])
        while q:
            i = q.popleft()
            if arr[i] == 0:
                return True
            x = arr[i]
            arr[i] = -1
            for j in (i + x, i - x):
                if 0 <= j < len(arr) and arr[j] >= 0:
                    q.append(j)
        return False
```

#### Java

```java
class Solution {
    public boolean canReach(int[] arr, int start) {
        Deque<Integer> q = new ArrayDeque<>();
        q.offer(start);
        while (!q.isEmpty()) {
            int i = q.poll();
            if (arr[i] == 0) {
                return true;
            }
            int x = arr[i];
            arr[i] = -1;
            for (int j : List.of(i + x, i - x)) {
                if (j >= 0 && j < arr.length && arr[j] >= 0) {
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
    bool canReach(vector<int>& arr, int start) {
        queue<int> q{{start}};
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            if (arr[i] == 0) {
                return true;
            }
            int x = arr[i];
            arr[i] = -1;
            for (int j : {i + x, i - x}) {
                if (j >= 0 && j < arr.size() && ~arr[j]) {
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
func canReach(arr []int, start int) bool {
	q := []int{start}
	for len(q) > 0 {
		i := q[0]
		q = q[1:]
		if arr[i] == 0 {
			return true
		}
		x := arr[i]
		arr[i] = -1
		for _, j := range []int{i + x, i - x} {
			if j >= 0 && j < len(arr) && arr[j] >= 0 {
				q = append(q, j)
			}
		}
	}
	return false
}
```

#### TypeScript

```ts
function canReach(arr: number[], start: number): boolean {
    const q = [start];
    for (const i of q) {
        if (arr[i] === 0) {
            return true;
        }
        if (arr[i] === -1 || arr[i] === undefined) {
            continue;
        }
        q.push(i + arr[i], i - arr[i]);
        arr[i] = -1;
    }
    return false;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1307. 口算难题](https://leetcode.cn/problems/verbal-arithmetic-puzzle){#1307}

{{< tabs "1307" >}}

{{% tab "python" %}}
```python
class Solution:
    def isAnyMapping(
        self, words, row, col, bal, letToDig, digToLet, totalRows, totalCols
    ):
        # If traversed all columns.
        if col == totalCols:
            return bal == 0

        # At the end of a particular column.
        if row == totalRows:
            return bal % 10 == 0 and self.isAnyMapping(
                words, 0, col + 1, bal // 10, letToDig, digToLet, totalRows, totalCols
            )

        w = words[row]

        # If the current string 'w' has no character in the ('col')th index.
        if col >= len(w):
            return self.isAnyMapping(
                words, row + 1, col, bal, letToDig, digToLet, totalRows, totalCols
            )

        # Take the current character in the variable letter.
        letter = w[len(w) - 1 - col]

        # Create a variable 'sign' to check whether we have to add it or subtract it.
        if row < totalRows - 1:
            sign = 1
        else:
            sign = -1

        # If we have a prior valid mapping, then use that mapping.
        # The second condition is for the leading zeros.
        if letter in letToDig and (
            letToDig[letter] != 0
            or (letToDig[letter] == 0 and len(w) == 1)
            or col != len(w) - 1
        ):

            return self.isAnyMapping(
                words,
                row + 1,
                col,
                bal + sign * letToDig[letter],
                letToDig,
                digToLet,
                totalRows,
                totalCols,
            )

        # Choose a new mapping.
        else:
            for i in range(10):
                # If 'i'th mapping is valid then select it.
                if digToLet[i] == "-" and (
                    i != 0 or (i == 0 and len(w) == 1) or col != len(w) - 1
                ):
                    digToLet[i] = letter
                    letToDig[letter] = i

                    # Call the function again with the new mapping.
                    if self.isAnyMapping(
                        words,
                        row + 1,
                        col,
                        bal + sign * letToDig[letter],
                        letToDig,
                        digToLet,
                        totalRows,
                        totalCols,
                    ):
                        return True

                    # Unselect the mapping.
                    digToLet[i] = "-"
                    if letter in letToDig:
                        del letToDig[letter]

        # If nothing is correct then just return false.
        return False

    def isSolvable(self, words, result):
        # Add the string 'result' in the list 'words'.
        words.append(result)

        # Initialize 'totalRows' with the size of the list.
        totalRows = len(words)

        # Find the longest string in the list and set 'totalCols' with the size of that string.
        totalCols = max(len(word) for word in words)

        # Create a HashMap for the letter to digit mapping.
        letToDig = {}

        # Create a list for the digit to letter mapping.
        digToLet = ["-"] * 10

        return self.isAnyMapping(
            words, 0, 0, 0, letToDig, digToLet, totalRows, totalCols
        )
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private boolean isAnyMapping(List<String> words, int row, int col, int bal,
        HashMap<Character, Integer> letToDig, char[] digToLet, int totalRows, int totalCols) {
        // If traversed all columns.
        if (col == totalCols) {
            return bal == 0;
        }

        // At the end of a particular column.
        if (row == totalRows) {
            return (bal % 10 == 0
                && isAnyMapping(
                    words, 0, col + 1, bal / 10, letToDig, digToLet, totalRows, totalCols));
        }

        String w = words.get(row);

        // If the current string 'w' has no character in the ('col')th index.
        if (col >= w.length()) {
            return isAnyMapping(words, row + 1, col, bal, letToDig, digToLet, totalRows, totalCols);
        }

        // Take the current character in the variable letter.
        char letter = w.charAt(w.length() - 1 - col);

        // Create a variable 'sign' to check whether we have to add it or subtract it.
        int sign = (row < totalRows - 1) ? 1 : -1;

        // If we have a prior valid mapping, then use that mapping.
        // The second condition is for the leading zeros.
        if (letToDig.containsKey(letter)
            && (letToDig.get(letter) != 0 || (letToDig.get(letter) == 0 && w.length() == 1)
                || col != w.length() - 1)) {

            return isAnyMapping(words, row + 1, col, bal + sign * letToDig.get(letter), letToDig,
                digToLet, totalRows, totalCols);

        } else {
            // Choose a new mapping.
            for (int i = 0; i < 10; i++) {
                // If 'i'th mapping is valid then select it.
                if (digToLet[i] == '-'
                    && (i != 0 || (i == 0 && w.length() == 1) || col != w.length() - 1)) {
                    digToLet[i] = letter;
                    letToDig.put(letter, i);

                    // Call the function again with the new mapping.
                    if (isAnyMapping(words, row + 1, col, bal + sign * letToDig.get(letter),
                            letToDig, digToLet, totalRows, totalCols)) {
                        return true;
                    }

                    // Unselect the mapping.
                    digToLet[i] = '-';
                    letToDig.remove(letter);
                }
            }
        }

        // If nothing is correct then just return false.
        return false;
    }

    public boolean isSolvable(String[] wordsArr, String result) {
        // Add the string 'result' in the list 'words'.
        List<String> words = new ArrayList<>();
        for (String word : wordsArr) {
            words.add(word);
        }
        words.add(result);

        int totalRows = words.size();

        // Find the longest string in the list and set 'totalCols' with the size of that string.
        int totalCols = 0;
        for (String word : words) {
            if (totalCols < word.length()) {
                totalCols = word.length();
            }
        }

        // Create a HashMap for the letter to digit mapping.
        HashMap<Character, Integer> letToDig = new HashMap<>();

        // Create a char array for the digit to letter mapping.
        char[] digToLet = new char[10];
        for (int i = 0; i < 10; i++) {
            digToLet[i] = '-';
        }

        return isAnyMapping(words, 0, 0, 0, letToDig, digToLet, totalRows, totalCols);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool isAnyMapping(vector<string>& words, int row, int col, int bal, unordered_map<char, int>& letToDig,
        vector<char>& digToLet, int totalRows, int totalCols) {
        // If traversed all columns.
        if (col == totalCols) {
            return bal == 0;
        }

        // At the end of a particular column.
        if (row == totalRows) {
            return (bal % 10 == 0 && isAnyMapping(words, 0, col + 1, bal / 10, letToDig, digToLet, totalRows, totalCols));
        }

        string w = words[row];

        // If the current string 'W' has no character in the ('COL')th index.
        if (col >= w.length()) {
            return isAnyMapping(words, row + 1, col, bal, letToDig, digToLet, totalRows, totalCols);
        }

        // Take the current character in the variable letter.
        char letter = w[w.length() - 1 - col];

        // Create a variable 'SIGN' to check whether we have to add it or subtract it.
        int sign;

        if (row < totalRows - 1) {
            sign = 1;
        } else {
            sign = -1;
        }

        /*
            If we have a prior valid mapping, then use that mapping.
            The second condition is for the leading zeros.
        */
        if (letToDig.count(letter) && (letToDig[letter] != 0 || (letToDig[letter] == 0 && w.length() == 1) || col != w.length() - 1)) {

            return isAnyMapping(words, row + 1, col, bal + sign * letToDig[letter],
                letToDig, digToLet, totalRows, totalCols);

        }
        // Choose a new mapping.
        else {
            for (int i = 0; i < 10; i++) {

                // If 'i'th mapping is valid then select it.
                if (digToLet[i] == '-' && (i != 0 || (i == 0 && w.length() == 1) || col != w.length() - 1)) {
                    digToLet[i] = letter;
                    letToDig[letter] = i;

                    // Call the function again with the new mapping.
                    bool x = isAnyMapping(words, row + 1, col, bal + sign * letToDig[letter],
                        letToDig, digToLet, totalRows, totalCols);

                    if (x == true) {
                        return true;
                    }

                    // Unselect the mapping.
                    digToLet[i] = '-';
                    if (letToDig.find(letter) != letToDig.end()) {
                        letToDig.erase(letter);
                    }
                }
            }
        }

        // If nothing is correct then just return false.
        return false;
    }

    bool isSolvable(vector<string>& words, string result) {
        // Add the string 'RESULT' in the vector 'WORDS'.
        words.push_back(result);

        int totalRows;
        int totalCols;

        // Initialize 'TOTALROWS' with the size of the vector.
        totalRows = words.size();

        // Find the longest string in the vector and set 'TOTALCOLS' with the size of that string.
        totalCols = 0;

        for (int i = 0; i < words.size(); i++) {

            // If the current string is the longest then update 'TOTALCOLS' with its length.
            if (totalCols < words[i].size()) {
                totalCols = words[i].size();
            }
        }

        // Create a HashMap for the letter to digit mapping.
        unordered_map<char, int> letToDig;

        // Create a vector for the digit to letter mapping.
        vector<char> digToLet(10, '-');

        return isAnyMapping(words, 0, 0, 0, letToDig, digToLet, totalRows, totalCols);
    }
};
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

<p>给你一个方程，左边用&nbsp;<code>words</code>&nbsp;表示，右边用&nbsp;<code>result</code> 表示。</p>

<p>你需要根据以下规则检查方程是否可解：</p>

<ul>
	<li>每个字符都会被解码成一位数字（0 - 9）。</li>
	<li>每对不同的字符必须映射到不同的数字。</li>
	<li>每个 <code>words[i]</code> 和 <code>result</code>&nbsp;都会被解码成一个没有前导零的数字。</li>
	<li>左侧数字之和（<code>words</code>）等于右侧数字（<code>result</code>）。&nbsp;</li>
</ul>

<p>如果方程可解，返回&nbsp;<code>True</code>，否则返回&nbsp;<code>False</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>words = [&quot;SEND&quot;,&quot;MORE&quot;], result = &quot;MONEY&quot;
<strong>输出：</strong>true
<strong>解释：</strong>映射 &#39;S&#39;-&gt; 9, &#39;E&#39;-&gt;5, &#39;N&#39;-&gt;6, &#39;D&#39;-&gt;7, &#39;M&#39;-&gt;1, &#39;O&#39;-&gt;0, &#39;R&#39;-&gt;8, &#39;Y&#39;-&gt;&#39;2&#39;
所以 &quot;SEND&quot; + &quot;MORE&quot; = &quot;MONEY&quot; ,  9567 + 1085 = 10652</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>words = [&quot;SIX&quot;,&quot;SEVEN&quot;,&quot;SEVEN&quot;], result = &quot;TWENTY&quot;
<strong>输出：</strong>true
<strong>解释：</strong>映射 &#39;S&#39;-&gt; 6, &#39;I&#39;-&gt;5, &#39;X&#39;-&gt;0, &#39;E&#39;-&gt;8, &#39;V&#39;-&gt;7, &#39;N&#39;-&gt;2, &#39;T&#39;-&gt;1, &#39;W&#39;-&gt;&#39;3&#39;, &#39;Y&#39;-&gt;4
所以 &quot;SIX&quot; + &quot;SEVEN&quot; + &quot;SEVEN&quot; = &quot;TWENTY&quot; ,  650 + 68782 + 68782 = 138214</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>words = [&quot;THIS&quot;,&quot;IS&quot;,&quot;TOO&quot;], result = &quot;FUNNY&quot;
<strong>输出：</strong>true
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>words = [&quot;LEET&quot;,&quot;CODE&quot;], result = &quot;POINT&quot;
<strong>输出：</strong>false
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= words.length &lt;= 5</code></li>
	<li><code>1 &lt;= words[i].length,&nbsp;results.length&nbsp;&lt;= 7</code></li>
	<li><code>words[i], result</code>&nbsp;只含有大写英文字母</li>
	<li>表达式中使用的不同字符数最大为&nbsp;10</li>
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
    def isAnyMapping(
        self, words, row, col, bal, letToDig, digToLet, totalRows, totalCols
    ):
        # If traversed all columns.
        if col == totalCols:
            return bal == 0

        # At the end of a particular column.
        if row == totalRows:
            return bal % 10 == 0 and self.isAnyMapping(
                words, 0, col + 1, bal // 10, letToDig, digToLet, totalRows, totalCols
            )

        w = words[row]

        # If the current string 'w' has no character in the ('col')th index.
        if col >= len(w):
            return self.isAnyMapping(
                words, row + 1, col, bal, letToDig, digToLet, totalRows, totalCols
            )

        # Take the current character in the variable letter.
        letter = w[len(w) - 1 - col]

        # Create a variable 'sign' to check whether we have to add it or subtract it.
        if row < totalRows - 1:
            sign = 1
        else:
            sign = -1

        # If we have a prior valid mapping, then use that mapping.
        # The second condition is for the leading zeros.
        if letter in letToDig and (
            letToDig[letter] != 0
            or (letToDig[letter] == 0 and len(w) == 1)
            or col != len(w) - 1
        ):

            return self.isAnyMapping(
                words,
                row + 1,
                col,
                bal + sign * letToDig[letter],
                letToDig,
                digToLet,
                totalRows,
                totalCols,
            )

        # Choose a new mapping.
        else:
            for i in range(10):
                # If 'i'th mapping is valid then select it.
                if digToLet[i] == "-" and (
                    i != 0 or (i == 0 and len(w) == 1) or col != len(w) - 1
                ):
                    digToLet[i] = letter
                    letToDig[letter] = i

                    # Call the function again with the new mapping.
                    if self.isAnyMapping(
                        words,
                        row + 1,
                        col,
                        bal + sign * letToDig[letter],
                        letToDig,
                        digToLet,
                        totalRows,
                        totalCols,
                    ):
                        return True

                    # Unselect the mapping.
                    digToLet[i] = "-"
                    if letter in letToDig:
                        del letToDig[letter]

        # If nothing is correct then just return false.
        return False

    def isSolvable(self, words, result):
        # Add the string 'result' in the list 'words'.
        words.append(result)

        # Initialize 'totalRows' with the size of the list.
        totalRows = len(words)

        # Find the longest string in the list and set 'totalCols' with the size of that string.
        totalCols = max(len(word) for word in words)

        # Create a HashMap for the letter to digit mapping.
        letToDig = {}

        # Create a list for the digit to letter mapping.
        digToLet = ["-"] * 10

        return self.isAnyMapping(
            words, 0, 0, 0, letToDig, digToLet, totalRows, totalCols
        )
```

#### Java

```java
class Solution {
    private boolean isAnyMapping(List<String> words, int row, int col, int bal,
        HashMap<Character, Integer> letToDig, char[] digToLet, int totalRows, int totalCols) {
        // If traversed all columns.
        if (col == totalCols) {
            return bal == 0;
        }

        // At the end of a particular column.
        if (row == totalRows) {
            return (bal % 10 == 0
                && isAnyMapping(
                    words, 0, col + 1, bal / 10, letToDig, digToLet, totalRows, totalCols));
        }

        String w = words.get(row);

        // If the current string 'w' has no character in the ('col')th index.
        if (col >= w.length()) {
            return isAnyMapping(words, row + 1, col, bal, letToDig, digToLet, totalRows, totalCols);
        }

        // Take the current character in the variable letter.
        char letter = w.charAt(w.length() - 1 - col);

        // Create a variable 'sign' to check whether we have to add it or subtract it.
        int sign = (row < totalRows - 1) ? 1 : -1;

        // If we have a prior valid mapping, then use that mapping.
        // The second condition is for the leading zeros.
        if (letToDig.containsKey(letter)
            && (letToDig.get(letter) != 0 || (letToDig.get(letter) == 0 && w.length() == 1)
                || col != w.length() - 1)) {

            return isAnyMapping(words, row + 1, col, bal + sign * letToDig.get(letter), letToDig,
                digToLet, totalRows, totalCols);

        } else {
            // Choose a new mapping.
            for (int i = 0; i < 10; i++) {
                // If 'i'th mapping is valid then select it.
                if (digToLet[i] == '-'
                    && (i != 0 || (i == 0 && w.length() == 1) || col != w.length() - 1)) {
                    digToLet[i] = letter;
                    letToDig.put(letter, i);

                    // Call the function again with the new mapping.
                    if (isAnyMapping(words, row + 1, col, bal + sign * letToDig.get(letter),
                            letToDig, digToLet, totalRows, totalCols)) {
                        return true;
                    }

                    // Unselect the mapping.
                    digToLet[i] = '-';
                    letToDig.remove(letter);
                }
            }
        }

        // If nothing is correct then just return false.
        return false;
    }

    public boolean isSolvable(String[] wordsArr, String result) {
        // Add the string 'result' in the list 'words'.
        List<String> words = new ArrayList<>();
        for (String word : wordsArr) {
            words.add(word);
        }
        words.add(result);

        int totalRows = words.size();

        // Find the longest string in the list and set 'totalCols' with the size of that string.
        int totalCols = 0;
        for (String word : words) {
            if (totalCols < word.length()) {
                totalCols = word.length();
            }
        }

        // Create a HashMap for the letter to digit mapping.
        HashMap<Character, Integer> letToDig = new HashMap<>();

        // Create a char array for the digit to letter mapping.
        char[] digToLet = new char[10];
        for (int i = 0; i < 10; i++) {
            digToLet[i] = '-';
        }

        return isAnyMapping(words, 0, 0, 0, letToDig, digToLet, totalRows, totalCols);
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool isAnyMapping(vector<string>& words, int row, int col, int bal, unordered_map<char, int>& letToDig,
        vector<char>& digToLet, int totalRows, int totalCols) {
        // If traversed all columns.
        if (col == totalCols) {
            return bal == 0;
        }

        // At the end of a particular column.
        if (row == totalRows) {
            return (bal % 10 == 0 && isAnyMapping(words, 0, col + 1, bal / 10, letToDig, digToLet, totalRows, totalCols));
        }

        string w = words[row];

        // If the current string 'W' has no character in the ('COL')th index.
        if (col >= w.length()) {
            return isAnyMapping(words, row + 1, col, bal, letToDig, digToLet, totalRows, totalCols);
        }

        // Take the current character in the variable letter.
        char letter = w[w.length() - 1 - col];

        // Create a variable 'SIGN' to check whether we have to add it or subtract it.
        int sign;

        if (row < totalRows - 1) {
            sign = 1;
        } else {
            sign = -1;
        }

        /*
            If we have a prior valid mapping, then use that mapping.
            The second condition is for the leading zeros.
        */
        if (letToDig.count(letter) && (letToDig[letter] != 0 || (letToDig[letter] == 0 && w.length() == 1) || col != w.length() - 1)) {

            return isAnyMapping(words, row + 1, col, bal + sign * letToDig[letter],
                letToDig, digToLet, totalRows, totalCols);

        }
        // Choose a new mapping.
        else {
            for (int i = 0; i < 10; i++) {

                // If 'i'th mapping is valid then select it.
                if (digToLet[i] == '-' && (i != 0 || (i == 0 && w.length() == 1) || col != w.length() - 1)) {
                    digToLet[i] = letter;
                    letToDig[letter] = i;

                    // Call the function again with the new mapping.
                    bool x = isAnyMapping(words, row + 1, col, bal + sign * letToDig[letter],
                        letToDig, digToLet, totalRows, totalCols);

                    if (x == true) {
                        return true;
                    }

                    // Unselect the mapping.
                    digToLet[i] = '-';
                    if (letToDig.find(letter) != letToDig.end()) {
                        letToDig.erase(letter);
                    }
                }
            }
        }

        // If nothing is correct then just return false.
        return false;
    }

    bool isSolvable(vector<string>& words, string result) {
        // Add the string 'RESULT' in the vector 'WORDS'.
        words.push_back(result);

        int totalRows;
        int totalCols;

        // Initialize 'TOTALROWS' with the size of the vector.
        totalRows = words.size();

        // Find the longest string in the vector and set 'TOTALCOLS' with the size of that string.
        totalCols = 0;

        for (int i = 0; i < words.size(); i++) {

            // If the current string is the longest then update 'TOTALCOLS' with its length.
            if (totalCols < words[i].size()) {
                totalCols = words[i].size();
            }
        }

        // Create a HashMap for the letter to digit mapping.
        unordered_map<char, int> letToDig;

        // Create a vector for the digit to letter mapping.
        vector<char> digToLet(10, '-');

        return isAnyMapping(words, 0, 0, 0, letToDig, digToLet, totalRows, totalCols);
    }
};
```

#### Go

```go

```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1308. 不同性别每日分数总计 🔒](https://leetcode.cn/problems/running-total-for-different-genders){#1308}

{{< tabs "1308" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT
    gender,
    day,
    SUM(score_points) OVER (
        PARTITION BY gender
        ORDER BY gender, day
    ) AS total
FROM Scores;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表: <code>Scores</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| player_name   | varchar |
| gender        | varchar |
| day           | date    |
| score_points  | int     |
+---------------+---------+
(gender, day)是该表的主键(具有唯一值的列的组合)
一场比赛是在女队和男队之间举行的
该表的每一行表示一个名叫 (player_name) 性别为 (gender) 的参赛者在某一天获得了 (score_points) 的分数
如果参赛者是女性，那么 gender 列为 'F'，如果参赛者是男性，那么 gender 列为 'M'
</pre>

<p>&nbsp;</p>

<p>编写解决方案统计每种性别在每一天的总分。</p>

<p>返回按&nbsp;<code>gender</code>&nbsp;和&nbsp;<code>day</code>&nbsp;对查询结果 <strong>升序排序</strong>&nbsp;的结果。</p>

<p>查询结果格式的示例如下。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
Scores表:
+-------------+--------+------------+--------------+
| player_name | gender | day        | score_points |
+-------------+--------+------------+--------------+
| Aron        | F      | 2020-01-01 | 17           |
| Alice       | F      | 2020-01-07 | 23           |
| Bajrang     | M      | 2020-01-07 | 7            |
| Khali       | M      | 2019-12-25 | 11           |
| Slaman      | M      | 2019-12-30 | 13           |
| Joe         | M      | 2019-12-31 | 3            |
| Jose        | M      | 2019-12-18 | 2            |
| Priya       | F      | 2019-12-31 | 23           |
| Priyanka    | F      | 2019-12-30 | 17           |
+-------------+--------+------------+--------------+
<strong>输出：</strong>
+--------+------------+-------+
| gender | day        | total |
+--------+------------+-------+
| F      | 2019-12-30 | 17    |
| F      | 2019-12-31 | 40    |
| F      | 2020-01-01 | 57    |
| F      | 2020-01-07 | 80    |
| M      | 2019-12-18 | 2     |
| M      | 2019-12-25 | 13    |
| M      | 2019-12-30 | 26    |
| M      | 2019-12-31 | 29    |
| M      | 2020-01-07 | 36    |
+--------+------------+-------+
<strong>解释：</strong>
女性队伍:
第一天是 2019-12-30，Priyanka 获得 17 分，队伍的总分是 17 分
第二天是 2019-12-31, Priya 获得 23 分，队伍的总分是 40 分
第三天是 2020-01-01, Aron 获得 17 分，队伍的总分是 57 分
第四天是 2020-01-07, Alice 获得 23 分，队伍的总分是 80 分

男性队伍：
第一天是 2019-12-18, Jose 获得 2 分，队伍的总分是 2 分
第二天是 2019-12-25, Khali 获得 11 分，队伍的总分是 13 分
第三天是 2019-12-30, Slaman 获得 13 分，队伍的总分是 26 分
第四天是 2019-12-31, Joe 获得 3 分，队伍的总分是 29 分
第五天是 2020-01-07, Bajrang 获得 7 分，队伍的总分是 36 分</pre>

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
SELECT
    gender,
    day,
    SUM(score_points) OVER (
        PARTITION BY gender
        ORDER BY gender, day
    ) AS total
FROM Scores;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1309. 解码字母到整数映射](https://leetcode.cn/problems/decrypt-string-from-alphabet-to-integer-mapping){#1309}

{{< tabs "1309" >}}

{{% tab "python" %}}
```python
class Solution:
    def freqAlphabets(self, s: str) -> str:
        ans = []
        i, n = 0, len(s)
        while i < n:
            if i + 2 < n and s[i + 2] == "#":
                ans.append(chr(int(s[i : i + 2]) + ord("a") - 1))
                i += 3
            else:
                ans.append(chr(int(s[i]) + ord("a") - 1))
                i += 1
        return "".join(ans)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String freqAlphabets(String s) {
        int i = 0, n = s.length();
        StringBuilder ans = new StringBuilder();
        while (i < n) {
            if (i + 2 < n && s.charAt(i + 2) == '#') {
                ans.append((char) ('a' + Integer.parseInt(s.substring(i, i + 2)) - 1));
                i += 3;
            } else {
                ans.append((char) ('a' + Integer.parseInt(s.substring(i, i + 1)) - 1));
                i++;
            }
        }
        return ans.toString();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string freqAlphabets(string s) {
        string ans = "";
        int i = 0, n = s.size();
        while (i < n) {
            if (i + 2 < n && s[i + 2] == '#') {
                ans += char(stoi(s.substr(i, 2)) + 'a' - 1);
                i += 3;
            } else {
                ans += char(s[i] - '0' + 'a' - 1);
                i += 1;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func freqAlphabets(s string) string {
	var ans []byte
	for i, n := 0, len(s); i < n; {
		if i+2 < n && s[i+2] == '#' {
			num := (int(s[i])-'0')*10 + int(s[i+1]) - '0'
			ans = append(ans, byte(num+int('a')-1))
			i += 3
		} else {
			num := int(s[i]) - '0'
			ans = append(ans, byte(num+int('a')-1))
			i += 1
		}
	}
	return string(ans)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function freqAlphabets(s: string): string {
    const ans: string[] = [];
    for (let i = 0, n = s.length; i < n; ) {
        if (i + 2 < n && s[i + 2] === '#') {
            ans.push(String.fromCharCode(96 + +s.slice(i, i + 2)));
            i += 3;
        } else {
            ans.push(String.fromCharCode(96 + +s[i]));
            i++;
        }
    }
    return ans.join('');
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn freq_alphabets(s: String) -> String {
        let s = s.as_bytes();
        let mut ans = String::new();
        let mut i = 0;
        let n = s.len();
        while i < n {
            if i + 2 < n && s[i + 2] == b'#' {
                let num = (s[i] - b'0') * 10 + (s[i + 1] - b'0');
                ans.push((96 + num) as char);
                i += 3;
            } else {
                let num = s[i] - b'0';
                ans.push((96 + num) as char);
                i += 1;
            }
        }
        ans
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
char* freqAlphabets(char* s) {
    int n = strlen(s);
    int i = 0;
    int j = 0;
    char* ans = malloc(sizeof(s) * n);
    while (i < n) {
        int t;
        if (i + 2 < n && s[i + 2] == '#') {
            t = (s[i] - '0') * 10 + s[i + 1];
            i += 3;
        } else {
            t = s[i];
            i += 1;
        }
        ans[j++] = 'a' + t - '1';
    }
    ans[j] = '\0';
    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串&nbsp;<code>s</code>，它由数字（<code>'0'</code> - <code>'9'</code>）和&nbsp;<code>'#'</code>&nbsp;组成。我们希望按下述规则将&nbsp;<code>s</code>&nbsp;映射为一些小写英文字符：</p>

<ul>
	<li>字符（<code>'a'</code> - <code>'i'</code>）分别用（<code>'1'</code> -&nbsp;<code>'9'</code>）表示。</li>
	<li>字符（<code>'j'</code> - <code>'z'</code>）分别用（<code>'10#'</code>&nbsp;-&nbsp;<code>'26#'</code>）表示。&nbsp;</li>
</ul>

<p>返回映射之后形成的新字符串。</p>

<p>题目数据保证映射始终唯一。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "10#11#12"
<strong>输出：</strong>"jkab"
<strong>解释：</strong>"j" -&gt; "10#" , "k" -&gt; "11#" , "a" -&gt; "1" , "b" -&gt; "2".
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "1326#"
<strong>输出：</strong>"acz"
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s[i]</code> 只包含数字（<code>'0'</code>-<code>'9'</code>）和&nbsp;<code>'#'</code>&nbsp;字符。</li>
	<li><code>s</code>&nbsp;是映射始终存在的有效字符串。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们直接模拟即可。

遍历字符串 $s$，对于当前遍历到的下标 $i$，如果 $i + 2 < n$ 且 $s[i + 2]$ 为 `#`，则将 $s[i]$ 和 $s[i + 1]$ 组成的字符串转换为整数，加上 `a` 的 ASCII 码值减去 1，然后转换为字符，添加到结果数组中，并将 $i$ 增加 3；否则，将 $s[i]$ 转换为整数，加上 `a` 的 ASCII 码值减去 1，然后转换为字符，添加到结果数组中，并将 $i$ 增加 1。

最后将结果数组转换为字符串返回即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为字符串 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def freqAlphabets(self, s: str) -> str:
        ans = []
        i, n = 0, len(s)
        while i < n:
            if i + 2 < n and s[i + 2] == "#":
                ans.append(chr(int(s[i : i + 2]) + ord("a") - 1))
                i += 3
            else:
                ans.append(chr(int(s[i]) + ord("a") - 1))
                i += 1
        return "".join(ans)
```

#### Java

```java
class Solution {
    public String freqAlphabets(String s) {
        int i = 0, n = s.length();
        StringBuilder ans = new StringBuilder();
        while (i < n) {
            if (i + 2 < n && s.charAt(i + 2) == '#') {
                ans.append((char) ('a' + Integer.parseInt(s.substring(i, i + 2)) - 1));
                i += 3;
            } else {
                ans.append((char) ('a' + Integer.parseInt(s.substring(i, i + 1)) - 1));
                i++;
            }
        }
        return ans.toString();
    }
}
```

#### C++

```cpp
class Solution {
public:
    string freqAlphabets(string s) {
        string ans = "";
        int i = 0, n = s.size();
        while (i < n) {
            if (i + 2 < n && s[i + 2] == '#') {
                ans += char(stoi(s.substr(i, 2)) + 'a' - 1);
                i += 3;
            } else {
                ans += char(s[i] - '0' + 'a' - 1);
                i += 1;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func freqAlphabets(s string) string {
	var ans []byte
	for i, n := 0, len(s); i < n; {
		if i+2 < n && s[i+2] == '#' {
			num := (int(s[i])-'0')*10 + int(s[i+1]) - '0'
			ans = append(ans, byte(num+int('a')-1))
			i += 3
		} else {
			num := int(s[i]) - '0'
			ans = append(ans, byte(num+int('a')-1))
			i += 1
		}
	}
	return string(ans)
}
```

#### TypeScript

```ts
function freqAlphabets(s: string): string {
    const ans: string[] = [];
    for (let i = 0, n = s.length; i < n; ) {
        if (i + 2 < n && s[i + 2] === '#') {
            ans.push(String.fromCharCode(96 + +s.slice(i, i + 2)));
            i += 3;
        } else {
            ans.push(String.fromCharCode(96 + +s[i]));
            i++;
        }
    }
    return ans.join('');
}
```

#### Rust

```rust
impl Solution {
    pub fn freq_alphabets(s: String) -> String {
        let s = s.as_bytes();
        let mut ans = String::new();
        let mut i = 0;
        let n = s.len();
        while i < n {
            if i + 2 < n && s[i + 2] == b'#' {
                let num = (s[i] - b'0') * 10 + (s[i + 1] - b'0');
                ans.push((96 + num) as char);
                i += 3;
            } else {
                let num = s[i] - b'0';
                ans.push((96 + num) as char);
                i += 1;
            }
        }
        ans
    }
}
```

#### C

```c
char* freqAlphabets(char* s) {
    int n = strlen(s);
    int i = 0;
    int j = 0;
    char* ans = malloc(sizeof(s) * n);
    while (i < n) {
        int t;
        if (i + 2 < n && s[i + 2] == '#') {
            t = (s[i] - '0') * 10 + s[i + 1];
            i += 3;
        } else {
            t = s[i];
            i += 1;
        }
        ans[j++] = 'a' + t - '1';
    }
    ans[j] = '\0';
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
