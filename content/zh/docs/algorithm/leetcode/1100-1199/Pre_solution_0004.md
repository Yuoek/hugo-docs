---
title: "1130_叶值的最小代价生成树"
date: 2025-10-08T18:36:57+08:00
weight: 4
tags: [动态规划, 单调栈, 哈希表, 图, 堆（优先队列）, 字符串, 并查集, 拓扑排序, 排序, 数学, 数据库, 数组, 最小生成树, 栈, 矩阵, 记忆化搜索, 贪心]
---

{{< markmap >}}
### [1130_叶值的最小代价生成树](#1130)
#### [栈](#1130)
#### [贪心](#1130)
#### [数组](#1130)
#### [动态规划](#1130)
#### [单调栈](#1130)
### [1131_绝对值表达式的最大值](#1131)
#### [数组](#1131)
#### [数学](#1131)
### [1132_报告的记录 II 🔒](#1132)
#### [数据库](#1132)
### [1133_最大唯一数 🔒](#1133)
#### [数组](#1133)
#### [哈希表](#1133)
#### [排序](#1133)
### [1134_阿姆斯特朗数 🔒](#1134)
#### [数学](#1134)
### [1135_最低成本连通所有城市 🔒](#1135)
#### [并查集](#1135)
#### [图](#1135)
#### [最小生成树](#1135)
#### [堆（优先队列）](#1135)
### [1136_并行课程 🔒](#1136)
#### [图](#1136)
#### [拓扑排序](#1136)
### [1137_第 N 个泰波那契数](#1137)
#### [记忆化搜索](#1137)
#### [数学](#1137)
#### [动态规划](#1137)
### [1138_字母板上的路径](#1138)
#### [哈希表](#1138)
#### [字符串](#1138)
### [1139_最大的以 1 为边界的正方形](#1139)
#### [数组](#1139)
#### [动态规划](#1139)
#### [矩阵](#1139)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1130_叶值的最小代价生成树
___
#### 栈
___
#### 贪心
___
#### 数组
___
#### 动态规划
___
#### 单调栈
---
### 1131_绝对值表达式的最大值
___
#### 数组
___
#### 数学
---
### 1132_报告的记录 II 🔒
___
#### 数据库
---
### 1133_最大唯一数 🔒
___
#### 数组
___
#### 哈希表
___
#### 排序
---
### 1134_阿姆斯特朗数 🔒
___
#### 数学
---
### 1135_最低成本连通所有城市 🔒
___
#### 并查集
___
#### 图
___
#### 最小生成树
___
#### 堆（优先队列）
---
### 1136_并行课程 🔒
___
#### 图
___
#### 拓扑排序
---
### 1137_第 N 个泰波那契数
___
#### 记忆化搜索
___
#### 数学
___
#### 动态规划
---
### 1138_字母板上的路径
___
#### 哈希表
___
#### 字符串
---
### 1139_最大的以 1 为边界的正方形
___
#### 数组
___
#### 动态规划
___
#### 矩阵
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 动态规划 | 单调栈 | 哈希表 |
| 图 | 堆（优先队列） | 字符串 |
| 并查集 | 拓扑排序 | 排序 |
| 数学 | 数据库 | 数组 |
| 最小生成树 | 栈 | 矩阵 |
| 记忆化搜索 | 贪心 |  |

# [1130. 叶值的最小代价生成树](https://leetcode.cn/problems/minimum-cost-tree-from-leaf-values){#1130}

{{< tabs "1130" >}}

{{% tab "python" %}}
```python
class Solution:
    def mctFromLeafValues(self, arr: List[int]) -> int:
        n = len(arr)
        f = [[0] * n for _ in range(n)]
        g = [[0] * n for _ in range(n)]
        for i in range(n - 1, -1, -1):
            g[i][i] = arr[i]
            for j in range(i + 1, n):
                g[i][j] = max(g[i][j - 1], arr[j])
                f[i][j] = min(
                    f[i][k] + f[k + 1][j] + g[i][k] * g[k + 1][j] for k in range(i, j)
                )
        return f[0][n - 1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int mctFromLeafValues(int[] arr) {
        int n = arr.length;
        int[][] f = new int[n][n];
        int[][] g = new int[n][n];
        for (int i = n - 1; i >= 0; --i) {
            g[i][i] = arr[i];
            for (int j = i + 1; j < n; ++j) {
                g[i][j] = Math.max(g[i][j - 1], arr[j]);
                f[i][j] = 1 << 30;
                for (int k = i; k < j; ++k) {
                    f[i][j] = Math.min(f[i][j], f[i][k] + f[k + 1][j] + g[i][k] * g[k + 1][j]);
                }
            }
        }
        return f[0][n - 1];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        int f[n][n];
        int g[n][n];
        memset(f, 0, sizeof(f));
        for (int i = n - 1; ~i; --i) {
            g[i][i] = arr[i];
            for (int j = i + 1; j < n; ++j) {
                g[i][j] = max(g[i][j - 1], arr[j]);
                f[i][j] = 1 << 30;
                for (int k = i; k < j; ++k) {
                    f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + g[i][k] * g[k + 1][j]);
                }
            }
        }
        return f[0][n - 1];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func mctFromLeafValues(arr []int) int {
	n := len(arr)
	f := make([][]int, n)
	g := make([][]int, n)
	for i := range g {
		f[i] = make([]int, n)
		g[i] = make([]int, n)
	}
	for i := n - 1; i >= 0; i-- {
		g[i][i] = arr[i]
		for j := i + 1; j < n; j++ {
			g[i][j] = max(g[i][j-1], arr[j])
			f[i][j] = 1 << 30
			for k := i; k < j; k++ {
				f[i][j] = min(f[i][j], f[i][k]+f[k+1][j]+g[i][k]*g[k+1][j])
			}
		}
	}
	return f[0][n-1]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function mctFromLeafValues(arr: number[]): number {
    const n = arr.length;
    const f: number[][] = new Array(n).fill(0).map(() => new Array(n).fill(0));
    const g: number[][] = new Array(n).fill(0).map(() => new Array(n).fill(0));
    for (let i = n - 1; i >= 0; --i) {
        g[i][i] = arr[i];
        for (let j = i + 1; j < n; ++j) {
            g[i][j] = Math.max(g[i][j - 1], arr[j]);
            f[i][j] = 1 << 30;
            for (let k = i; k < j; ++k) {
                f[i][j] = Math.min(f[i][j], f[i][k] + f[k + 1][j] + g[i][k] * g[k + 1][j]);
            }
        }
    }
    return f[0][n - 1];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个正整数数组&nbsp;<code>arr</code>，考虑所有满足以下条件的二叉树：</p>

<ul>
	<li>每个节点都有 <code>0</code> 个或是 <code>2</code> 个子节点。</li>
	<li>数组&nbsp;<code>arr</code>&nbsp;中的值与树的中序遍历中每个叶节点的值一一对应。</li>
	<li>每个非叶节点的值等于其左子树和右子树中叶节点的最大值的乘积。</li>
</ul>

<p>在所有这样的二叉树中，返回每个非叶节点的值的最小可能总和。这个和的值是一个&nbsp;32 位整数。</p>

<p>如果一个节点有 0 个子节点，那么该节点为叶节点。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1100-1199/1130.Minimum%20Cost%20Tree%20From%20Leaf%20Values/images/tree1.jpg" style="width: 500px; height: 169px;" />
<pre>
<strong>输入：</strong>arr = [6,2,4]
<strong>输出：</strong>32
<strong>解释：</strong>有两种可能的树，第一种的非叶节点的总和为 36 ，第二种非叶节点的总和为 32 。 
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1100-1199/1130.Minimum%20Cost%20Tree%20From%20Leaf%20Values/images/tree2.jpg" style="width: 224px; height: 145px;" />
<pre>
<strong>输入：</strong>arr = [4,11]
<strong>输出：</strong>44
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= arr.length &lt;= 40</code></li>
	<li><code>1 &lt;= arr[i] &lt;= 15</code></li>
	<li>答案保证是一个 32 位带符号整数，即小于&nbsp;<code>2<sup>31</sup></code> 。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

根据题目描述，数组 $arr$ 中的值与树的中序遍历中每个叶节点的值一一对应，我们可以将数组划分为左右两个非空子数组，分别对应树的左右子树，递归地求解每个子树的所有非叶节点的值的最小可能总和。

我们设计一个函数 $dfs(i, j)$，表示数组 $arr$ 中下标范围 $[i, j]$ 内的所有非叶节点的值的最小可能总和，那么答案就是 $dfs(0, n - 1)$，其中 $n$ 为数组 $arr$ 的长度。

函数 $dfs(i, j)$ 的计算过程如下：

-   如果 $i = j$，说明数组 $arr[i..j]$ 中只有一个元素，没有非叶节点，因此 $dfs(i, j) = 0$。
-   否则，我们枚举 $k \in [i, j - 1]$，将数组 $arr$ 划分为两个子数组 $arr[i \cdots k]$ 和 $arr[k + 1 \cdots j]$，对于每个 $k$，我们递归计算 $dfs(i, k)$ 和 $dfs(k + 1, j)$，其中 $dfs(i, k)$ 表示数组 $arr$ 中下标范围 $[i, k]$ 内的所有非叶节点的值的最小可能总和，而 $dfs(k + 1, j)$ 表示数组 $arr$ 中下标范围 $[k + 1, j]$ 内的所有非叶节点的值的最小可能总和，那么 $dfs(i, j) = \min_{i \leq k < j} \{dfs(i, k) + dfs(k + 1, j) + \max_{i \leq t \leq k} \{arr[t]\} \max_{k < t \leq j} \{arr[t]\}\}$。

综上所述，我们可以得到：

$$
dfs(i, j) = \begin{cases}
0, & \textit{if } i = j \\
\min_{i \leq k < j} \{dfs(i, k) + dfs(k + 1, j) + \max_{i \leq t \leq k} \{arr[t]\} \max_{k < t \leq j} \{arr[t]\}\}, & \textit{if } i < j
\end{cases}
$$

上述递归过程中，我们可以使用记忆化搜索的方法，避免重复计算。另外，我们还可以使用数组 $g$ 记录数组 $arr$ 中下标范围 $[i, j]$ 内的所有叶节点的最大值，那么 $dfs(i, j)$ 的计算过程可以优化为：

$$
dfs(i, j) = \begin{cases}
0, & \textit{if } i = j \\
\min_{i \leq k < j} \{dfs(i, k) + dfs(k + 1, j) + g[i][k] \cdot g[k + 1][j]\}, & \textit{if } i < j
\end{cases}
$$

最后，我们返回 $dfs(0, n - 1)$ 即可。

时间复杂度 $O(n^3)$，空间复杂度 $O(n^2)$。其中 $n$ 为数组 $arr$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def mctFromLeafValues(self, arr: List[int]) -> int:
        @cache
        def dfs(i: int, j: int) -> Tuple:
            if i == j:
                return 0, arr[i]
            s, mx = inf, -1
            for k in range(i, j):
                s1, mx1 = dfs(i, k)
                s2, mx2 = dfs(k + 1, j)
                t = s1 + s2 + mx1 * mx2
                if s > t:
                    s = t
                    mx = max(mx1, mx2)
            return s, mx

        return dfs(0, len(arr) - 1)[0]
```

#### Java

```java
class Solution {
    private Integer[][] f;
    private int[][] g;

    public int mctFromLeafValues(int[] arr) {
        int n = arr.length;
        f = new Integer[n][n];
        g = new int[n][n];
        for (int i = n - 1; i >= 0; --i) {
            g[i][i] = arr[i];
            for (int j = i + 1; j < n; ++j) {
                g[i][j] = Math.max(g[i][j - 1], arr[j]);
            }
        }
        return dfs(0, n - 1);
    }

    private int dfs(int i, int j) {
        if (i == j) {
            return 0;
        }
        if (f[i][j] != null) {
            return f[i][j];
        }
        int ans = 1 << 30;
        for (int k = i; k < j; k++) {
            ans = Math.min(ans, dfs(i, k) + dfs(k + 1, j) + g[i][k] * g[k + 1][j]);
        }
        return f[i][j] = ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        int f[n][n];
        int g[n][n];
        memset(f, 0, sizeof(f));
        for (int i = n - 1; ~i; --i) {
            g[i][i] = arr[i];
            for (int j = i + 1; j < n; ++j) {
                g[i][j] = max(g[i][j - 1], arr[j]);
            }
        }
        function<int(int, int)> dfs = [&](int i, int j) -> int {
            if (i == j) {
                return 0;
            }
            if (f[i][j] > 0) {
                return f[i][j];
            }
            int ans = 1 << 30;
            for (int k = i; k < j; ++k) {
                ans = min(ans, dfs(i, k) + dfs(k + 1, j) + g[i][k] * g[k + 1][j]);
            }
            return f[i][j] = ans;
        };
        return dfs(0, n - 1);
    }
};
```

#### Go

```go
func mctFromLeafValues(arr []int) int {
	n := len(arr)
	f := make([][]int, n)
	g := make([][]int, n)
	for i := range g {
		f[i] = make([]int, n)
		g[i] = make([]int, n)
		g[i][i] = arr[i]
		for j := i + 1; j < n; j++ {
			g[i][j] = max(g[i][j-1], arr[j])
		}
	}
	var dfs func(int, int) int
	dfs = func(i, j int) int {
		if i == j {
			return 0
		}
		if f[i][j] > 0 {
			return f[i][j]
		}
		f[i][j] = 1 << 30
		for k := i; k < j; k++ {
			f[i][j] = min(f[i][j], dfs(i, k)+dfs(k+1, j)+g[i][k]*g[k+1][j])
		}
		return f[i][j]
	}
	return dfs(0, n-1)
}
```

#### TypeScript

```ts
function mctFromLeafValues(arr: number[]): number {
    const n = arr.length;
    const f: number[][] = new Array(n).fill(0).map(() => new Array(n).fill(0));
    const g: number[][] = new Array(n).fill(0).map(() => new Array(n).fill(0));
    for (let i = n - 1; i >= 0; --i) {
        g[i][i] = arr[i];
        for (let j = i + 1; j < n; ++j) {
            g[i][j] = Math.max(g[i][j - 1], arr[j]);
        }
    }
    const dfs = (i: number, j: number): number => {
        if (i === j) {
            return 0;
        }
        if (f[i][j] > 0) {
            return f[i][j];
        }
        let ans = 1 << 30;
        for (let k = i; k < j; ++k) {
            ans = Math.min(ans, dfs(i, k) + dfs(k + 1, j) + g[i][k] * g[k + 1][j]);
        }
        return (f[i][j] = ans);
    };
    return dfs(0, n - 1);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：动态规划

我们可以将方法一中的记忆化搜索改为动态规划的方式进行求解。

定义 $f[i][j]$ 表示数组 $arr$ 中下标范围 $[i, j]$ 内的所有非叶节点的值的最小可能总和，而 $g[i][j]$ 表示数组 $arr$ 中下标范围 $[i, j]$ 内的所有叶节点的最大值，那么状态转移方程为：

$$
f[i][j] = \begin{cases}
0, & \textit{if } i = j \\
\min_{i \leq k < j} \{f[i][k] + f[k + 1][j] + g[i][k] \cdot g[k + 1][j]\}, & \textit{if } i < j
\end{cases}
$$

最后，我们返回 $f[0][n - 1]$ 即可。

时间复杂度 $O(n^3)$，空间复杂度 $O(n^2)$。其中 $n$ 为数组 $arr$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def mctFromLeafValues(self, arr: List[int]) -> int:
        @cache
        def dfs(i: int, j: int) -> int:
            if i == j:
                return 0
            return min(
                dfs(i, k) + dfs(k + 1, j) + g[i][k] * g[k + 1][j] for k in range(i, j)
            )

        n = len(arr)
        g = [[0] * n for _ in range(n)]
        for i in range(n - 1, -1, -1):
            g[i][i] = arr[i]
            for j in range(i + 1, n):
                g[i][j] = max(g[i][j - 1], arr[j])
        return dfs(0, n - 1)
```

#### Java

```java
class Solution {
    public int mctFromLeafValues(int[] arr) {
        int n = arr.length;
        int[][] f = new int[n][n];
        int[][] g = new int[n][n];
        for (int i = n - 1; i >= 0; --i) {
            g[i][i] = arr[i];
            for (int j = i + 1; j < n; ++j) {
                g[i][j] = Math.max(g[i][j - 1], arr[j]);
                f[i][j] = 1 << 30;
                for (int k = i; k < j; ++k) {
                    f[i][j] = Math.min(f[i][j], f[i][k] + f[k + 1][j] + g[i][k] * g[k + 1][j]);
                }
            }
        }
        return f[0][n - 1];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        int f[n][n];
        int g[n][n];
        memset(f, 0, sizeof(f));
        for (int i = n - 1; ~i; --i) {
            g[i][i] = arr[i];
            for (int j = i + 1; j < n; ++j) {
                g[i][j] = max(g[i][j - 1], arr[j]);
                f[i][j] = 1 << 30;
                for (int k = i; k < j; ++k) {
                    f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + g[i][k] * g[k + 1][j]);
                }
            }
        }
        return f[0][n - 1];
    }
};
```

#### Go

```go
func mctFromLeafValues(arr []int) int {
	n := len(arr)
	f := make([][]int, n)
	g := make([][]int, n)
	for i := range g {
		f[i] = make([]int, n)
		g[i] = make([]int, n)
	}
	for i := n - 1; i >= 0; i-- {
		g[i][i] = arr[i]
		for j := i + 1; j < n; j++ {
			g[i][j] = max(g[i][j-1], arr[j])
			f[i][j] = 1 << 30
			for k := i; k < j; k++ {
				f[i][j] = min(f[i][j], f[i][k]+f[k+1][j]+g[i][k]*g[k+1][j])
			}
		}
	}
	return f[0][n-1]
}
```

#### TypeScript

```ts
function mctFromLeafValues(arr: number[]): number {
    const n = arr.length;
    const f: number[][] = new Array(n).fill(0).map(() => new Array(n).fill(0));
    const g: number[][] = new Array(n).fill(0).map(() => new Array(n).fill(0));
    for (let i = n - 1; i >= 0; --i) {
        g[i][i] = arr[i];
        for (let j = i + 1; j < n; ++j) {
            g[i][j] = Math.max(g[i][j - 1], arr[j]);
            f[i][j] = 1 << 30;
            for (let k = i; k < j; ++k) {
                f[i][j] = Math.min(f[i][j], f[i][k] + f[k + 1][j] + g[i][k] * g[k + 1][j]);
            }
        }
    }
    return f[0][n - 1];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法三

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def mctFromLeafValues(self, arr: List[int]) -> int:
        n = len(arr)
        f = [[0] * n for _ in range(n)]
        g = [[0] * n for _ in range(n)]
        for i in range(n - 1, -1, -1):
            g[i][i] = arr[i]
            for j in range(i + 1, n):
                g[i][j] = max(g[i][j - 1], arr[j])
                f[i][j] = min(
                    f[i][k] + f[k + 1][j] + g[i][k] * g[k + 1][j] for k in range(i, j)
                )
        return f[0][n - 1]
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1131. 绝对值表达式的最大值](https://leetcode.cn/problems/maximum-of-absolute-value-expression){#1131}

{{< tabs "1131" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxAbsValExpr(self, arr1: List[int], arr2: List[int]) -> int:
        dirs = (1, -1, -1, 1, 1)
        ans = -inf
        for a, b in pairwise(dirs):
            mx, mi = -inf, inf
            for i, (x, y) in enumerate(zip(arr1, arr2)):
                mx = max(mx, a * x + b * y + i)
                mi = min(mi, a * x + b * y + i)
                ans = max(ans, mx - mi)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxAbsValExpr(int[] arr1, int[] arr2) {
        int[] dirs = {1, -1, -1, 1, 1};
        final int inf = 1 << 30;
        int ans = -inf;
        int n = arr1.length;
        for (int k = 0; k < 4; ++k) {
            int a = dirs[k], b = dirs[k + 1];
            int mx = -inf, mi = inf;
            for (int i = 0; i < n; ++i) {
                mx = Math.max(mx, a * arr1[i] + b * arr2[i] + i);
                mi = Math.min(mi, a * arr1[i] + b * arr2[i] + i);
                ans = Math.max(ans, mx - mi);
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
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int dirs[5] = {1, -1, -1, 1, 1};
        const int inf = 1 << 30;
        int ans = -inf;
        int n = arr1.size();
        for (int k = 0; k < 4; ++k) {
            int a = dirs[k], b = dirs[k + 1];
            int mx = -inf, mi = inf;
            for (int i = 0; i < n; ++i) {
                mx = max(mx, a * arr1[i] + b * arr2[i] + i);
                mi = min(mi, a * arr1[i] + b * arr2[i] + i);
                ans = max(ans, mx - mi);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxAbsValExpr(arr1 []int, arr2 []int) int {
	dirs := [5]int{1, -1, -1, 1, 1}
	const inf = 1 << 30
	ans := -inf
	for k := 0; k < 4; k++ {
		a, b := dirs[k], dirs[k+1]
		mx, mi := -inf, inf
		for i, x := range arr1 {
			y := arr2[i]
			mx = max(mx, a*x+b*y+i)
			mi = min(mi, a*x+b*y+i)
			ans = max(ans, mx-mi)
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxAbsValExpr(arr1: number[], arr2: number[]): number {
    const dirs = [1, -1, -1, 1, 1];
    const inf = 1 << 30;
    let ans = -inf;
    for (let k = 0; k < 4; ++k) {
        const [a, b] = [dirs[k], dirs[k + 1]];
        let mx = -inf;
        let mi = inf;
        for (let i = 0; i < arr1.length; ++i) {
            const [x, y] = [arr1[i], arr2[i]];
            mx = Math.max(mx, a * x + b * y + i);
            mi = Math.min(mi, a * x + b * y + i);
            ans = Math.max(ans, mx - mi);
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

<p>给你两个长度相等的整数数组，返回下面表达式的最大值：</p>

<p><code>|arr1[i] - arr1[j]| + |arr2[i] - arr2[j]| + |i - j|</code></p>

<p>其中下标 <code>i</code>，<code>j</code> 满足&nbsp;<code>0 &lt;= i, j &lt; arr1.length</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>arr1 = [1,2,3,4], arr2 = [-1,4,5,6]
<strong>输出：</strong>13
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>arr1 = [1,-2,-5,0,10], arr2 = [0,-2,-1,-7,-4]
<strong>输出：</strong>20</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= arr1.length == arr2.length &lt;= 40000</code></li>
	<li><code>-10^6 &lt;= arr1[i], arr2[i] &lt;= 10^6</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数学 + 枚举

我们不妨令 $x_i = arr1[i]$, $y_i = arr2[i]$，由于 $i$ 和 $j$ 的大小关系不影响表达式的值，我们不妨假设 $i \ge j$，那么表达式可以变为：

$$
| x_i - x_j | + | y_i - y_j | + i - j = \max \begin{cases} (x_i + y_i) - (x_j + y_j) \\ (x_i - y_i) - (x_j - y_j) \\ (-x_i + y_i) - (-x_j + y_j) \\ (-x_i - y_i) - (-x_j - y_j) \end{cases} + i - j\\
= \max \begin{cases} (x_i + y_i + i) - (x_j + y_j + j) \\ (x_i - y_i + i) - (x_j - y_j + j) \\ (-x_i + y_i + i) - (-x_j + y_j + j) \\ (-x_i - y_i + i) - (-x_j - y_j + j) \end{cases}
$$

因此，我们只要求出 $a \times x_i + b \times y_i + i$ 的最大值 $mx$，以及最小值 $mi$，其中 $a, b \in \{-1, 1\}$。那么答案就是所有 $mx - mi$ 中的最大值。

时间复杂度 $O(n)$，其中 $n$ 是数组长度。空间复杂度 $O(1)$。

相似题目：

-   [1330. 翻转子数组得到最大的数组值](https://github.com/doocs/leetcode/blob/main/solution/1300-1399/1330.Reverse%20Subarray%20To%20Maximize%20Array%20Value/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxAbsValExpr(self, arr1: List[int], arr2: List[int]) -> int:
        dirs = (1, -1, -1, 1, 1)
        ans = -inf
        for a, b in pairwise(dirs):
            mx, mi = -inf, inf
            for i, (x, y) in enumerate(zip(arr1, arr2)):
                mx = max(mx, a * x + b * y + i)
                mi = min(mi, a * x + b * y + i)
                ans = max(ans, mx - mi)
        return ans
```

#### Java

```java
class Solution {
    public int maxAbsValExpr(int[] arr1, int[] arr2) {
        int[] dirs = {1, -1, -1, 1, 1};
        final int inf = 1 << 30;
        int ans = -inf;
        int n = arr1.length;
        for (int k = 0; k < 4; ++k) {
            int a = dirs[k], b = dirs[k + 1];
            int mx = -inf, mi = inf;
            for (int i = 0; i < n; ++i) {
                mx = Math.max(mx, a * arr1[i] + b * arr2[i] + i);
                mi = Math.min(mi, a * arr1[i] + b * arr2[i] + i);
                ans = Math.max(ans, mx - mi);
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
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int dirs[5] = {1, -1, -1, 1, 1};
        const int inf = 1 << 30;
        int ans = -inf;
        int n = arr1.size();
        for (int k = 0; k < 4; ++k) {
            int a = dirs[k], b = dirs[k + 1];
            int mx = -inf, mi = inf;
            for (int i = 0; i < n; ++i) {
                mx = max(mx, a * arr1[i] + b * arr2[i] + i);
                mi = min(mi, a * arr1[i] + b * arr2[i] + i);
                ans = max(ans, mx - mi);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func maxAbsValExpr(arr1 []int, arr2 []int) int {
	dirs := [5]int{1, -1, -1, 1, 1}
	const inf = 1 << 30
	ans := -inf
	for k := 0; k < 4; k++ {
		a, b := dirs[k], dirs[k+1]
		mx, mi := -inf, inf
		for i, x := range arr1 {
			y := arr2[i]
			mx = max(mx, a*x+b*y+i)
			mi = min(mi, a*x+b*y+i)
			ans = max(ans, mx-mi)
		}
	}
	return ans
}
```

#### TypeScript

```ts
function maxAbsValExpr(arr1: number[], arr2: number[]): number {
    const dirs = [1, -1, -1, 1, 1];
    const inf = 1 << 30;
    let ans = -inf;
    for (let k = 0; k < 4; ++k) {
        const [a, b] = [dirs[k], dirs[k + 1]];
        let mx = -inf;
        let mi = inf;
        for (let i = 0; i < arr1.length; ++i) {
            const [x, y] = [arr1[i], arr2[i]];
            mx = Math.max(mx, a * x + b * y + i);
            mi = Math.min(mi, a * x + b * y + i);
            ans = Math.max(ans, mx - mi);
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

# [1132. 报告的记录 II 🔒](https://leetcode.cn/problems/reported-posts-ii){#1132}

{{< tabs "1132" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            COUNT(DISTINCT t2.post_id) / COUNT(DISTINCT t1.post_id) * 100 AS percent
        FROM
            Actions AS t1
            LEFT JOIN Removals AS t2 ON t1.post_id = t2.post_id
        WHERE extra = 'spam'
        GROUP BY action_date
    )
SELECT ROUND(AVG(percent), 2) AS average_daily_percent
FROM T;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>动作表：&nbsp;<code>Actions</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| user_id       | int     |
| post_id       | int     |
| action_date   | date    |
| action        | enum    |
| extra         | varchar |
+---------------+---------+
这张表可能存在重复的行。
action 列的类型是 ENUM，可能的值为 ('view', 'like', 'reaction', 'comment', 'report', 'share')。
extra 列拥有一些可选信息，例如：报告理由（a reason for report）或反应类型（a type of reaction）等。</pre>

<p>&nbsp;</p>

<p>移除表：&nbsp;<code>Removals</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| post_id       | int     |
| remove_date   | date    | 
+---------------+---------+
这张表的主键是 post_id（具有唯一值的列）。
这张表的每一行表示一个被移除的帖子，原因可能是由于被举报或被管理员审查。
</pre>

<p>&nbsp;</p>

<p>编写解决方案，统计在被报告为垃圾广告的帖子中，被移除的帖子的每日平均占比，<strong>四舍五入到小数点后 2 位</strong>。</p>

<p>结果的格式如下。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入：</strong>
Actions table:
+---------+---------+-------------+--------+--------+
| user_id | post_id | action_date | action | extra  |
+---------+---------+-------------+--------+--------+
| 1       | 1       | 2019-07-01  | view   | null   |
| 1       | 1       | 2019-07-01  | like   | null   |
| 1       | 1       | 2019-07-01  | share  | null   |
| 2       | 2       | 2019-07-04  | view   | null   |
| 2       | 2       | 2019-07-04  | report | spam   |
| 3       | 4       | 2019-07-04  | view   | null   |
| 3       | 4       | 2019-07-04  | report | spam   |
| 4       | 3       | 2019-07-02  | view   | null   |
| 4       | 3       | 2019-07-02  | report | spam   |
| 5       | 2       | 2019-07-03  | view   | null   |
| 5       | 2       | 2019-07-03  | report | racism |
| 5       | 5       | 2019-07-03  | view   | null   |
| 5       | 5       | 2019-07-03  | report | racism |
+---------+---------+-------------+--------+--------+
Removals table:
+---------+-------------+
| post_id | remove_date |
+---------+-------------+
| 2       | 2019-07-20  |
| 3       | 2019-07-18  |
+---------+-------------+
<strong>输出：</strong>
+-----------------------+
| average_daily_percent |
+-----------------------+
| 75.00                 |
+-----------------------+
<strong>解释：</strong>
2019-07-04 的垃圾广告移除率是 50%，因为有两张帖子被报告为垃圾广告，但只有一个得到移除。
2019-07-02 的垃圾广告移除率是 100%，因为有一张帖子被举报为垃圾广告并得到移除。
其余几天没有收到垃圾广告的举报，因此平均值为：(50 + 100) / 2 = 75%
注意，输出仅需要一个平均值即可，我们并不关注移除操作的日期。</pre>

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
WITH
    T AS (
        SELECT
            COUNT(DISTINCT t2.post_id) / COUNT(DISTINCT t1.post_id) * 100 AS percent
        FROM
            Actions AS t1
            LEFT JOIN Removals AS t2 ON t1.post_id = t2.post_id
        WHERE extra = 'spam'
        GROUP BY action_date
    )
SELECT ROUND(AVG(percent), 2) AS average_daily_percent
FROM T;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1133. 最大唯一数 🔒](https://leetcode.cn/problems/largest-unique-number){#1133}

{{< tabs "1133" >}}

{{% tab "python" %}}
```python
class Solution:
    def largestUniqueNumber(self, nums: List[int]) -> int:
        cnt = Counter(nums)
        return max((x for x, v in cnt.items() if v == 1), default=-1)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int largestUniqueNumber(int[] nums) {
        int[] cnt = new int[1001];
        for (int x : nums) {
            ++cnt[x];
        }
        for (int x = 1000; x >= 0; --x) {
            if (cnt[x] == 1) {
                return x;
            }
        }
        return -1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        int cnt[1001]{};
        for (int& x : nums) {
            ++cnt[x];
        }
        for (int x = 1000; ~x; --x) {
            if (cnt[x] == 1) {
                return x;
            }
        }
        return -1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func largestUniqueNumber(nums []int) int {
	cnt := [1001]int{}
	for _, x := range nums {
		cnt[x]++
	}
	for x := 1000; x >= 0; x-- {
		if cnt[x] == 1 {
			return x
		}
	}
	return -1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function largestUniqueNumber(nums: number[]): number {
    const cnt = Array(1001).fill(0);
    for (const x of nums) {
        ++cnt[x];
    }
    for (let x = 1000; x >= 0; --x) {
        if (cnt[x] === 1) {
            return x;
        }
    }
    return -1;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var largestUniqueNumber = function (nums) {
    const cnt = Array(1001).fill(0);
    for (const x of nums) {
        ++cnt[x];
    }
    for (let x = 1000; x >= 0; --x) {
        if (cnt[x] === 1) {
            return x;
        }
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

<p>给你一个整数数组&nbsp;<code>A</code>，请找出并返回在该数组中仅出现一次的最大整数。</p>

<p>如果不存在这个只出现一次的整数，则返回 -1。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>[5,7,3,9,4,9,8,3,1]
<strong>输出：</strong>8
<strong>解释： </strong>
数组中最大的整数是 9，但它在数组中重复出现了。而第二大的整数是 8，它只出现了一次，所以答案是 8。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>[9,9,8,8]
<strong>输出：</strong>-1
<strong>解释： </strong>
数组中不存在仅出现一次的整数。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ol>
	<li><code>1 &lt;= A.length &lt;= 2000</code></li>
	<li><code>0 &lt;= A[i] &lt;= 1000</code></li>
</ol>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数 + 倒序遍历

注意到题目的数据范围，我们可以使用一个长度为 $1001$ 的数组来统计每个数字出现的次数，然后倒序遍历数组，找到第一个出现次数为 $1$ 的数字即可。如果没有找到，则返回 $-1$。

时间复杂度 $O(n + M)$，空间复杂度 $O(M)$。其中 $n$ 为数组长度；而 $M$ 为数组中出现的最大数字，本题中 $M \leq 1000$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def largestUniqueNumber(self, nums: List[int]) -> int:
        cnt = Counter(nums)
        return max((x for x, v in cnt.items() if v == 1), default=-1)
```

#### Java

```java
class Solution {
    public int largestUniqueNumber(int[] nums) {
        int[] cnt = new int[1001];
        for (int x : nums) {
            ++cnt[x];
        }
        for (int x = 1000; x >= 0; --x) {
            if (cnt[x] == 1) {
                return x;
            }
        }
        return -1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        int cnt[1001]{};
        for (int& x : nums) {
            ++cnt[x];
        }
        for (int x = 1000; ~x; --x) {
            if (cnt[x] == 1) {
                return x;
            }
        }
        return -1;
    }
};
```

#### Go

```go
func largestUniqueNumber(nums []int) int {
	cnt := [1001]int{}
	for _, x := range nums {
		cnt[x]++
	}
	for x := 1000; x >= 0; x-- {
		if cnt[x] == 1 {
			return x
		}
	}
	return -1
}
```

#### TypeScript

```ts
function largestUniqueNumber(nums: number[]): number {
    const cnt = Array(1001).fill(0);
    for (const x of nums) {
        ++cnt[x];
    }
    for (let x = 1000; x >= 0; --x) {
        if (cnt[x] === 1) {
            return x;
        }
    }
    return -1;
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var largestUniqueNumber = function (nums) {
    const cnt = Array(1001).fill(0);
    for (const x of nums) {
        ++cnt[x];
    }
    for (let x = 1000; x >= 0; --x) {
        if (cnt[x] === 1) {
            return x;
        }
    }
    return -1;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1134. 阿姆斯特朗数 🔒](https://leetcode.cn/problems/armstrong-number){#1134}

{{< tabs "1134" >}}

{{% tab "python" %}}
```python
class Solution:
    def isArmstrong(self, n: int) -> bool:
        k = len(str(n))
        s, x = 0, n
        while x:
            s += (x % 10) ** k
            x //= 10
        return s == n
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean isArmstrong(int n) {
        int k = (n + "").length();
        int s = 0;
        for (int x = n; x > 0; x /= 10) {
            s += Math.pow(x % 10, k);
        }
        return s == n;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool isArmstrong(int n) {
        int k = to_string(n).size();
        int s = 0;
        for (int x = n; x; x /= 10) {
            s += pow(x % 10, k);
        }
        return s == n;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func isArmstrong(n int) bool {
	k := 0
	for x := n; x > 0; x /= 10 {
		k++
	}
	s := 0
	for x := n; x > 0; x /= 10 {
		s += int(math.Pow(float64(x%10), float64(k)))
	}
	return s == n
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function isArmstrong(n: number): boolean {
    const k = String(n).length;
    let s = 0;
    for (let x = n; x; x = Math.floor(x / 10)) {
        s += Math.pow(x % 10, k);
    }
    return s == n;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number} n
 * @return {boolean}
 */
var isArmstrong = function (n) {
    const k = String(n).length;
    let s = 0;
    for (let x = n; x; x = Math.floor(x / 10)) {
        s += Math.pow(x % 10, k);
    }
    return s == n;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数 <code>n</code>&nbsp;，让你来判定他是否是<strong>&nbsp;</strong><strong>阿姆斯特朗数</strong>，是则返回 <code>true</code>，不是则返回 <code>false</code>。</p>

<p>假设存在一个 <code>k</code> 位数 <code>n</code>&nbsp;，其每一位上的数字的 <code>k</code> 次幂的总和也是 <code>n</code>&nbsp;，那么这个数是阿姆斯特朗数 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 153
<strong>输出：</strong>true
<strong>解释： </strong>
153 是一个 3 位数，且 153 = 1<sup>3</sup> + 5<sup>3</sup> + 3<sup>3</sup>。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 123
<strong>输出：</strong>false
<strong>解释：</strong>123 是一个 3 位数，且 123 != 1<sup>3</sup> + 2<sup>3</sup> + 3<sup>3</sup> = 36。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>8</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们可以先计算出数字的位数 $k$，然后计算每一位上的数字的 $k$ 次幂的总和 $s$，最后判断 $s$ 是否等于 $n$ 即可。

时间复杂度 $O(\log n)$，空间复杂度 $O(\log n)$。其中 $n$ 为给定的数字。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def isArmstrong(self, n: int) -> bool:
        k = len(str(n))
        s, x = 0, n
        while x:
            s += (x % 10) ** k
            x //= 10
        return s == n
```

#### Java

```java
class Solution {
    public boolean isArmstrong(int n) {
        int k = (n + "").length();
        int s = 0;
        for (int x = n; x > 0; x /= 10) {
            s += Math.pow(x % 10, k);
        }
        return s == n;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool isArmstrong(int n) {
        int k = to_string(n).size();
        int s = 0;
        for (int x = n; x; x /= 10) {
            s += pow(x % 10, k);
        }
        return s == n;
    }
};
```

#### Go

```go
func isArmstrong(n int) bool {
	k := 0
	for x := n; x > 0; x /= 10 {
		k++
	}
	s := 0
	for x := n; x > 0; x /= 10 {
		s += int(math.Pow(float64(x%10), float64(k)))
	}
	return s == n
}
```

#### TypeScript

```ts
function isArmstrong(n: number): boolean {
    const k = String(n).length;
    let s = 0;
    for (let x = n; x; x = Math.floor(x / 10)) {
        s += Math.pow(x % 10, k);
    }
    return s == n;
}
```

#### JavaScript

```js
/**
 * @param {number} n
 * @return {boolean}
 */
var isArmstrong = function (n) {
    const k = String(n).length;
    let s = 0;
    for (let x = n; x; x = Math.floor(x / 10)) {
        s += Math.pow(x % 10, k);
    }
    return s == n;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1135. 最低成本连通所有城市 🔒](https://leetcode.cn/problems/connecting-cities-with-minimum-cost){#1135}

{{< tabs "1135" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumCost(self, n: int, connections: List[List[int]]) -> int:
        def find(x):
            if p[x] != x:
                p[x] = find(p[x])
            return p[x]

        connections.sort(key=lambda x: x[2])
        p = list(range(n))
        ans = 0
        for x, y, cost in connections:
            x, y = x - 1, y - 1
            if find(x) == find(y):
                continue
            p[find(x)] = find(y)
            ans += cost
            n -= 1
            if n == 1:
                return ans
        return -1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[] p;

    public int minimumCost(int n, int[][] connections) {
        Arrays.sort(connections, Comparator.comparingInt(a -> a[2]));
        p = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
        }
        int ans = 0;
        for (int[] e : connections) {
            int x = e[0] - 1, y = e[1] - 1, cost = e[2];
            if (find(x) == find(y)) {
                continue;
            }
            p[find(x)] = find(y);
            ans += cost;
            if (--n == 1) {
                return ans;
            }
        }
        return -1;
    }

    private int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& connections) {
        vector<int> p(n);
        iota(p.begin(), p.end(), 0);
        sort(connections.begin(), connections.end(), [](auto& a, auto& b) { return a[2] < b[2]; });
        int ans = 0;
        function<int(int)> find = [&](int x) -> int {
            if (p[x] != x) {
                p[x] = find(p[x]);
            }
            return p[x];
        };
        for (auto& e : connections) {
            int x = e[0] - 1, y = e[1] - 1, cost = e[2];
            if (find(x) == find(y)) {
                continue;
            }
            p[find(x)] = find(y);
            ans += cost;
            if (--n == 1) {
                return ans;
            }
        }
        return -1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumCost(n int, connections [][]int) (ans int) {
	p := make([]int, n)
	for i := range p {
		p[i] = i
	}
	sort.Slice(connections, func(i, j int) bool { return connections[i][2] < connections[j][2] })
	var find func(int) int
	find = func(x int) int {
		if p[x] != x {
			p[x] = find(p[x])
		}
		return p[x]
	}
	for _, e := range connections {
		x, y, cost := e[0]-1, e[1]-1, e[2]
		if find(x) == find(y) {
			continue
		}
		p[find(x)] = find(y)
		ans += cost
		n--
		if n == 1 {
			return
		}
	}
	return -1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumCost(n: number, connections: number[][]): number {
    const p: number[] = Array.from({ length: n }, (_, i) => i);
    const find = (x: number): number => {
        if (p[x] !== x) {
            p[x] = find(p[x]);
        }
        return p[x];
    };
    connections.sort((a, b) => a[2] - b[2]);
    let ans = 0;
    for (const [x, y, cost] of connections) {
        if (find(x - 1) === find(y - 1)) {
            continue;
        }
        p[find(x - 1)] = find(y - 1);
        ans += cost;
        if (--n === 1) {
            return ans;
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

<p>想象一下你是个城市基建规划者，地图上有&nbsp;<code>n</code>&nbsp;座城市，它们按以&nbsp;<code>1</code> 到&nbsp;<code>n</code>&nbsp;的次序编号。</p>

<p>给你整数 <code>n</code> 和一个数组&nbsp;<code>conections</code>，其中&nbsp;<code>connections[i] = [x<sub>i</sub>, y<sub>i</sub>, cost<sub>i</sub>]</code>&nbsp;表示将城市&nbsp;<code>x<sub>i</sub></code>&nbsp;和城市&nbsp;<code>y<sub>i</sub></code>&nbsp;连接所要的<code>cost<sub>i</sub></code>（<strong>连接是双向的</strong>）。</p>

<p>返回连接所有城市的<strong>最低成本</strong>，每对城市之间<strong>至少</strong>有一条路径。如果无法连接所有 <code>n</code>&nbsp;个城市，返回 <code>-1</code></p>

<p>该 <strong>最小成本</strong> 应该是所用全部连接成本的总和。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1100-1199/1135.Connecting%20Cities%20With%20Minimum%20Cost/images/1314_ex2.png" /></p>

<pre>
<strong>输入：</strong>n = 3, conections = [[1,2,5],[1,3,6],[2,3,1]]
<strong>输出：</strong>6
<strong>解释：</strong>选出任意 2 条边都可以连接所有城市，我们从中选取成本最小的 2 条。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1100-1199/1135.Connecting%20Cities%20With%20Minimum%20Cost/images/1314_ex1.png" /></p>

<pre>
<strong>输入：</strong>n = 4, conections = [[1,2,3],[3,4,4]]
<strong>输出：</strong>-1
<strong>解释：</strong>即使连通所有的边，也无法连接所有城市。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= connections.length &lt;= 10<sup>4</sup></code></li>
	<li><code>connections[i].length == 3</code></li>
	<li><code>1 &lt;= x<sub>i</sub>, y<sub>i</sub>&nbsp;&lt;= n</code></li>
	<li><code>x<sub>i</sub>&nbsp;!= y<sub>i</sub></code></li>
	<li><code>0 &lt;= cost<sub>i</sub>&nbsp;&lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：Kruskal 算法

Kruskal 算法是一种贪心算法，用于计算最小生成树。

Kruskal 算法的基本思想是，每次从边集中选择一条最小的边，如果这条边连接的两个顶点不在同一个连通分量中，则将这条边加入到最小生成树中，否则舍弃这条边。

对于本题，我们可以将边按照连通成本从小到大排序，用并查集维护连通分量，每次选择一条最小的边，如果这条边连接的两个顶点不在同一个连通分量中，则合并这两个顶点，然后累加连通成本。如果出现连通份量为 $1$ 的情况，则说明所有顶点都连通了，返回累加的连通成本，否则返回 $-1$。

时间复杂度 $O(m \times \log m)$，空间复杂度 $O(n)$。其中 $m$ 和 $n$ 分别为边数和顶点数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumCost(self, n: int, connections: List[List[int]]) -> int:
        def find(x):
            if p[x] != x:
                p[x] = find(p[x])
            return p[x]

        connections.sort(key=lambda x: x[2])
        p = list(range(n))
        ans = 0
        for x, y, cost in connections:
            x, y = x - 1, y - 1
            if find(x) == find(y):
                continue
            p[find(x)] = find(y)
            ans += cost
            n -= 1
            if n == 1:
                return ans
        return -1
```

#### Java

```java
class Solution {
    private int[] p;

    public int minimumCost(int n, int[][] connections) {
        Arrays.sort(connections, Comparator.comparingInt(a -> a[2]));
        p = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
        }
        int ans = 0;
        for (int[] e : connections) {
            int x = e[0] - 1, y = e[1] - 1, cost = e[2];
            if (find(x) == find(y)) {
                continue;
            }
            p[find(x)] = find(y);
            ans += cost;
            if (--n == 1) {
                return ans;
            }
        }
        return -1;
    }

    private int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& connections) {
        vector<int> p(n);
        iota(p.begin(), p.end(), 0);
        sort(connections.begin(), connections.end(), [](auto& a, auto& b) { return a[2] < b[2]; });
        int ans = 0;
        function<int(int)> find = [&](int x) -> int {
            if (p[x] != x) {
                p[x] = find(p[x]);
            }
            return p[x];
        };
        for (auto& e : connections) {
            int x = e[0] - 1, y = e[1] - 1, cost = e[2];
            if (find(x) == find(y)) {
                continue;
            }
            p[find(x)] = find(y);
            ans += cost;
            if (--n == 1) {
                return ans;
            }
        }
        return -1;
    }
};
```

#### Go

```go
func minimumCost(n int, connections [][]int) (ans int) {
	p := make([]int, n)
	for i := range p {
		p[i] = i
	}
	sort.Slice(connections, func(i, j int) bool { return connections[i][2] < connections[j][2] })
	var find func(int) int
	find = func(x int) int {
		if p[x] != x {
			p[x] = find(p[x])
		}
		return p[x]
	}
	for _, e := range connections {
		x, y, cost := e[0]-1, e[1]-1, e[2]
		if find(x) == find(y) {
			continue
		}
		p[find(x)] = find(y)
		ans += cost
		n--
		if n == 1 {
			return
		}
	}
	return -1
}
```

#### TypeScript

```ts
function minimumCost(n: number, connections: number[][]): number {
    const p: number[] = Array.from({ length: n }, (_, i) => i);
    const find = (x: number): number => {
        if (p[x] !== x) {
            p[x] = find(p[x]);
        }
        return p[x];
    };
    connections.sort((a, b) => a[2] - b[2]);
    let ans = 0;
    for (const [x, y, cost] of connections) {
        if (find(x - 1) === find(y - 1)) {
            continue;
        }
        p[find(x - 1)] = find(y - 1);
        ans += cost;
        if (--n === 1) {
            return ans;
        }
    }
    return -1;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1136. 并行课程 🔒](https://leetcode.cn/problems/parallel-courses){#1136}

{{< tabs "1136" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumSemesters(self, n: int, relations: List[List[int]]) -> int:
        g = defaultdict(list)
        indeg = [0] * n
        for prev, nxt in relations:
            prev, nxt = prev - 1, nxt - 1
            g[prev].append(nxt)
            indeg[nxt] += 1
        q = deque(i for i, v in enumerate(indeg) if v == 0)
        ans = 0
        while q:
            ans += 1
            for _ in range(len(q)):
                i = q.popleft()
                n -= 1
                for j in g[i]:
                    indeg[j] -= 1
                    if indeg[j] == 0:
                        q.append(j)
        return -1 if n else ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumSemesters(int n, int[][] relations) {
        List<Integer>[] g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        int[] indeg = new int[n];
        for (var r : relations) {
            int prev = r[0] - 1, nxt = r[1] - 1;
            g[prev].add(nxt);
            ++indeg[nxt];
        }
        Deque<Integer> q = new ArrayDeque<>();
        for (int i = 0; i < n; ++i) {
            if (indeg[i] == 0) {
                q.offer(i);
            }
        }
        int ans = 0;
        while (!q.isEmpty()) {
            ++ans;
            for (int k = q.size(); k > 0; --k) {
                int i = q.poll();
                --n;
                for (int j : g[i]) {
                    if (--indeg[j] == 0) {
                        q.offer(j);
                    }
                }
            }
        }
        return n == 0 ? ans : -1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<vector<int>> g(n);
        vector<int> indeg(n);
        for (auto& r : relations) {
            int prev = r[0] - 1, nxt = r[1] - 1;
            g[prev].push_back(nxt);
            ++indeg[nxt];
        }
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }
        int ans = 0;
        while (!q.empty()) {
            ++ans;
            for (int k = q.size(); k; --k) {
                int i = q.front();
                q.pop();
                --n;
                for (int& j : g[i]) {
                    if (--indeg[j] == 0) {
                        q.push(j);
                    }
                }
            }
        }
        return n == 0 ? ans : -1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumSemesters(n int, relations [][]int) (ans int) {
	g := make([][]int, n)
	indeg := make([]int, n)
	for _, r := range relations {
		prev, nxt := r[0]-1, r[1]-1
		g[prev] = append(g[prev], nxt)
		indeg[nxt]++
	}
	q := []int{}
	for i, v := range indeg {
		if v == 0 {
			q = append(q, i)
		}
	}
	for len(q) > 0 {
		ans++
		for k := len(q); k > 0; k-- {
			i := q[0]
			q = q[1:]
			n--
			for _, j := range g[i] {
				indeg[j]--
				if indeg[j] == 0 {
					q = append(q, j)
				}
			}
		}
	}
	if n == 0 {
		return
	}
	return -1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumSemesters(n: number, relations: number[][]): number {
    const g: number[][] = Array.from({ length: n }, () => []);
    const indeg = new Array(n).fill(0);
    for (const [prev, nxt] of relations) {
        g[prev - 1].push(nxt - 1);
        indeg[nxt - 1]++;
    }
    const q: number[] = [];
    for (let i = 0; i < n; ++i) {
        if (indeg[i] === 0) {
            q.push(i);
        }
    }
    let ans = 0;
    while (q.length) {
        ++ans;
        for (let k = q.length; k; --k) {
            const i = q.shift()!;
            --n;
            for (const j of g[i]) {
                if (--indeg[j] === 0) {
                    q.push(j);
                }
            }
        }
    }
    return n === 0 ? ans : -1;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数 <code>n</code> ，表示编号从 <code>1</code> 到 <code>n</code> 的 <code>n</code> 门课程。另给你一个数组 <code>relations</code> ，其中 <code>relations[i] = [prevCourse<sub>i</sub>, nextCourse<sub>i</sub>]</code> ，表示课程 <code>prevCourse<sub>i</sub></code> 和课程 <code>nextCourse<sub>i</sub></code> 之间存在先修关系：课程 <code>prevCourse<sub>i</sub></code> 必须在 <code>nextCourse<sub>i</sub></code> 之前修读完成。</p>

<p>在一个学期内，你可以学习 <strong>任意数量</strong> 的课程，但前提是你已经在 <strong>上</strong> 一学期修读完待学习课程的所有先修课程。</p>

<div class="original__bRMd">
<div>
<p>请你返回学完全部课程所需的 <strong>最少</strong> 学期数。如果没有办法做到学完全部这些课程的话，就返回&nbsp;<code>-1</code>。</p>

<p>&nbsp;</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1100-1199/1136.Parallel%20Courses/images/course1graph.jpg" style="width: 222px; height: 222px;" />
<pre>
<strong>输入：</strong>n = 3, relations = [[1,3],[2,3]]
<strong>输出：</strong>2
<strong>解释：</strong>上图表示课程之间的关系图：
在第一学期，可以修读课程 1 和 2 。
在第二学期，可以修读课程 3 。
</pre>

<p><strong class="example">示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1100-1199/1136.Parallel%20Courses/images/course2graph.jpg" style="width: 222px; height: 222px;" />
<pre>
<strong>输入：</strong>n = 3, relations = [[1,2],[2,3],[3,1]]
<strong>输出：</strong>-1
<strong>解释：</strong>没有课程可以学习，因为它们互为先修课程。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 5000</code></li>
	<li><code>1 &lt;= relations.length &lt;= 5000</code></li>
	<li><code>relations[i].length == 2</code></li>
	<li><code>1 &lt;= prevCourse<sub>i</sub>, nextCourse<sub>i</sub> &lt;= n</code></li>
	<li><code>prevCourse<sub>i</sub> != nextCourse<sub>i</sub></code></li>
	<li>所有 <code>[prevCourse<sub>i</sub>, nextCourse<sub>i</sub>]</code> <strong>互不相同</strong></li>
</ul>
</div>
</div>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：拓扑排序

我们可以先将课程之间的先修关系建立图 $g$，并统计每个课程的入度 $indeg$。

然后我们将入度为 $0$ 的课程入队，然后开始进行拓扑排序。每次从队列中取出一个课程，将其出队，并将其出度的课程的入度减 $1$，如果减 $1$ 后入度为 $0$，则将该课程入队。当队列为空时，如果还有课程没有修完，则说明无法修完所有课程，返回 $-1$。否则返回修完所有课程所需的学期数。

时间复杂度 $O(n + m)$，空间复杂度 $O(n + m)$。其中 $n$ 和 $m$ 分别为课程数和先修关系数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumSemesters(self, n: int, relations: List[List[int]]) -> int:
        g = defaultdict(list)
        indeg = [0] * n
        for prev, nxt in relations:
            prev, nxt = prev - 1, nxt - 1
            g[prev].append(nxt)
            indeg[nxt] += 1
        q = deque(i for i, v in enumerate(indeg) if v == 0)
        ans = 0
        while q:
            ans += 1
            for _ in range(len(q)):
                i = q.popleft()
                n -= 1
                for j in g[i]:
                    indeg[j] -= 1
                    if indeg[j] == 0:
                        q.append(j)
        return -1 if n else ans
```

#### Java

```java
class Solution {
    public int minimumSemesters(int n, int[][] relations) {
        List<Integer>[] g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        int[] indeg = new int[n];
        for (var r : relations) {
            int prev = r[0] - 1, nxt = r[1] - 1;
            g[prev].add(nxt);
            ++indeg[nxt];
        }
        Deque<Integer> q = new ArrayDeque<>();
        for (int i = 0; i < n; ++i) {
            if (indeg[i] == 0) {
                q.offer(i);
            }
        }
        int ans = 0;
        while (!q.isEmpty()) {
            ++ans;
            for (int k = q.size(); k > 0; --k) {
                int i = q.poll();
                --n;
                for (int j : g[i]) {
                    if (--indeg[j] == 0) {
                        q.offer(j);
                    }
                }
            }
        }
        return n == 0 ? ans : -1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<vector<int>> g(n);
        vector<int> indeg(n);
        for (auto& r : relations) {
            int prev = r[0] - 1, nxt = r[1] - 1;
            g[prev].push_back(nxt);
            ++indeg[nxt];
        }
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }
        int ans = 0;
        while (!q.empty()) {
            ++ans;
            for (int k = q.size(); k; --k) {
                int i = q.front();
                q.pop();
                --n;
                for (int& j : g[i]) {
                    if (--indeg[j] == 0) {
                        q.push(j);
                    }
                }
            }
        }
        return n == 0 ? ans : -1;
    }
};
```

#### Go

```go
func minimumSemesters(n int, relations [][]int) (ans int) {
	g := make([][]int, n)
	indeg := make([]int, n)
	for _, r := range relations {
		prev, nxt := r[0]-1, r[1]-1
		g[prev] = append(g[prev], nxt)
		indeg[nxt]++
	}
	q := []int{}
	for i, v := range indeg {
		if v == 0 {
			q = append(q, i)
		}
	}
	for len(q) > 0 {
		ans++
		for k := len(q); k > 0; k-- {
			i := q[0]
			q = q[1:]
			n--
			for _, j := range g[i] {
				indeg[j]--
				if indeg[j] == 0 {
					q = append(q, j)
				}
			}
		}
	}
	if n == 0 {
		return
	}
	return -1
}
```

#### TypeScript

```ts
function minimumSemesters(n: number, relations: number[][]): number {
    const g: number[][] = Array.from({ length: n }, () => []);
    const indeg = new Array(n).fill(0);
    for (const [prev, nxt] of relations) {
        g[prev - 1].push(nxt - 1);
        indeg[nxt - 1]++;
    }
    const q: number[] = [];
    for (let i = 0; i < n; ++i) {
        if (indeg[i] === 0) {
            q.push(i);
        }
    }
    let ans = 0;
    while (q.length) {
        ++ans;
        for (let k = q.length; k; --k) {
            const i = q.shift()!;
            --n;
            for (const j of g[i]) {
                if (--indeg[j] === 0) {
                    q.push(j);
                }
            }
        }
    }
    return n === 0 ? ans : -1;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1137. 第 N 个泰波那契数](https://leetcode.cn/problems/n-th-tribonacci-number){#1137}

{{< tabs "1137" >}}

{{% tab "python" %}}
```python
import numpy as np


class Solution:
    def tribonacci(self, n: int) -> int:
        if n == 0:
            return 0
        if n < 3:
            return 1
        factor = np.asmatrix([(1, 1, 0), (1, 0, 1), (1, 0, 0)], np.dtype("O"))
        res = np.asmatrix([(1, 1, 0)], np.dtype("O"))
        n -= 3
        while n:
            if n & 1:
                res *= factor
            factor *= factor
            n >>= 1
        return res.sum()
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int tribonacci(int n) {
        if (n == 0) {
            return 0;
        }
        if (n < 3) {
            return 1;
        }
        int[][] a = {{1, 1, 0}, {1, 0, 1}, {1, 0, 0}};
        int[][] res = pow(a, n - 3);
        int ans = 0;
        for (int x : res[0]) {
            ans += x;
        }
        return ans;
    }

    private int[][] mul(int[][] a, int[][] b) {
        int m = a.length, n = b[0].length;
        int[][] c = new int[m][n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < b.length; ++k) {
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        return c;
    }

    private int[][] pow(int[][] a, int n) {
        int[][] res = {{1, 1, 0}};
        while (n > 0) {
            if ((n & 1) == 1) {
                res = mul(res, a);
            }
            a = mul(a, a);
            n >>= 1;
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
    int tribonacci(int n) {
        if (n == 0) {
            return 0;
        }
        if (n < 3) {
            return 1;
        }
        vector<vector<ll>> a = {{1, 1, 0}, {1, 0, 1}, {1, 0, 0}};
        vector<vector<ll>> res = pow(a, n - 3);
        return accumulate(res[0].begin(), res[0].end(), 0);
    }

private:
    using ll = long long;
    vector<vector<ll>> mul(vector<vector<ll>>& a, vector<vector<ll>>& b) {
        int m = a.size(), n = b[0].size();
        vector<vector<ll>> c(m, vector<ll>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < b.size(); ++k) {
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        return c;
    }

    vector<vector<ll>> pow(vector<vector<ll>>& a, int n) {
        vector<vector<ll>> res = {{1, 1, 0}};
        while (n) {
            if (n & 1) {
                res = mul(res, a);
            }
            a = mul(a, a);
            n >>= 1;
        }
        return res;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func tribonacci(n int) (ans int) {
	if n == 0 {
		return 0
	}
	if n < 3 {
		return 1
	}
	a := [][]int{{1, 1, 0}, {1, 0, 1}, {1, 0, 0}}
	res := pow(a, n-3)
	for _, x := range res[0] {
		ans += x
	}
	return
}

func mul(a, b [][]int) [][]int {
	m, n := len(a), len(b[0])
	c := make([][]int, m)
	for i := range c {
		c[i] = make([]int, n)
	}
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			for k := 0; k < len(b); k++ {
				c[i][j] += a[i][k] * b[k][j]
			}
		}
	}
	return c
}

func pow(a [][]int, n int) [][]int {
	res := [][]int{{1, 1, 0}}
	for n > 0 {
		if n&1 == 1 {
			res = mul(res, a)
		}
		a = mul(a, a)
		n >>= 1
	}
	return res
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function tribonacci(n: number): number {
    if (n === 0) {
        return 0;
    }
    if (n < 3) {
        return 1;
    }
    const a = [
        [1, 1, 0],
        [1, 0, 1],
        [1, 0, 0],
    ];
    return pow(a, n - 3)[0].reduce((a, b) => a + b);
}

function mul(a: number[][], b: number[][]): number[][] {
    const [m, n] = [a.length, b[0].length];
    const c = Array.from({ length: m }, () => Array.from({ length: n }, () => 0));
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            for (let k = 0; k < b.length; ++k) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return c;
}

function pow(a: number[][], n: number): number[][] {
    let res = [[1, 1, 0]];
    while (n) {
        if (n & 1) {
            res = mul(res, a);
        }
        a = mul(a, a);
        n >>= 1;
    }
    return res;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number} n
 * @return {number}
 */
var tribonacci = function (n) {
    if (n === 0) {
        return 0;
    }
    if (n < 3) {
        return 1;
    }
    const a = [
        [1, 1, 0],
        [1, 0, 1],
        [1, 0, 0],
    ];
    return pow(a, n - 3)[0].reduce((a, b) => a + b);
};

function mul(a, b) {
    const [m, n] = [a.length, b[0].length];
    const c = Array.from({ length: m }, () => Array.from({ length: n }, () => 0));
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            for (let k = 0; k < b.length; ++k) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return c;
}

function pow(a, n) {
    let res = [[1, 1, 0]];
    while (n) {
        if (n & 1) {
            res = mul(res, a);
        }
        a = mul(a, a);
        n >>= 1;
    }
    return res;
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param Integer $n
     * @return Integer
     */
    function tribonacci($n) {
        if ($n === 0) {
            return 0;
        }
        if ($n < 3) {
            return 1;
        }

        $a = [[1, 1, 0], [1, 0, 1], [1, 0, 0]];

        $res = $this->pow($a, $n - 3);
        return array_sum($res[0]);
    }

    private function mul($a, $b) {
        $m = count($a);
        $n = count($b[0]);
        $p = count($b);

        $c = array_fill(0, $m, array_fill(0, $n, 0));

        for ($i = 0; $i < $m; ++$i) {
            for ($j = 0; $j < $n; ++$j) {
                for ($k = 0; $k < $p; ++$k) {
                    $c[$i][$j] += $a[$i][$k] * $b[$k][$j];
                }
            }
        }

        return $c;
    }

    private function pow($a, $n) {
        $res = [[1, 1, 0]];
        while ($n > 0) {
            if ($n & 1) {
                $res = $this->mul($res, $a);
            }
            $a = $this->mul($a, $a);
            $n >>= 1;
        }
        return $res;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>泰波那契序列&nbsp;T<sub>n</sub>&nbsp;定义如下：&nbsp;</p>

<p>T<sub>0</sub> = 0, T<sub>1</sub> = 1, T<sub>2</sub> = 1, 且在 n &gt;= 0&nbsp;的条件下 T<sub>n+3</sub> = T<sub>n</sub> + T<sub>n+1</sub> + T<sub>n+2</sub></p>

<p>给你整数&nbsp;<code>n</code>，请返回第 n 个泰波那契数&nbsp;T<sub>n </sub>的值。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>n = 4
<strong>输出：</strong>4
<strong>解释：</strong>
T_3 = 0 + 1 + 1 = 2
T_4 = 1 + 1 + 2 = 4
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>n = 25
<strong>输出：</strong>1389537
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= n &lt;= 37</code></li>
	<li>答案保证是一个 32 位整数，即&nbsp;<code>answer &lt;= 2^31 - 1</code>。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

根据题目中给出的递推式，我们可以使用动态规划求解。

我们定义三个变量 $a$, $b$, $c$，分别表示 $T_{n-3}$, $T_{n-2}$, $T_{n-1}$，初始值分别为 $0$, $1$, $1$。

然后从 $n$ 减小到 $0$，每次更新 $a$, $b$, $c$ 的值，直到 $n$ 为 $0$ 时，答案即为 $a$。

时间复杂度 $O(n)$，空间复杂度 $O(1)$。其中 $n$ 为给定的整数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def tribonacci(self, n: int) -> int:
        a, b, c = 0, 1, 1
        for _ in range(n):
            a, b, c = b, c, a + b + c
        return a
```

#### Java

```java
class Solution {
    public int tribonacci(int n) {
        int a = 0, b = 1, c = 1;
        while (n-- > 0) {
            int d = a + b + c;
            a = b;
            b = c;
            c = d;
        }
        return a;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int tribonacci(int n) {
        long long a = 0, b = 1, c = 1;
        while (n--) {
            long long d = a + b + c;
            a = b;
            b = c;
            c = d;
        }
        return (int) a;
    }
};
```

#### Go

```go
func tribonacci(n int) int {
	a, b, c := 0, 1, 1
	for i := 0; i < n; i++ {
		a, b, c = b, c, a+b+c
	}
	return a
}
```

#### TypeScript

```ts
function tribonacci(n: number): number {
    let [a, b, c] = [0, 1, 1];
    while (n--) {
        let d = a + b + c;
        a = b;
        b = c;
        c = d;
    }
    return a;
}
```

#### JavaScript

```js
/**
 * @param {number} n
 * @return {number}
 */
var tribonacci = function (n) {
    let a = 0;
    let b = 1;
    let c = 1;
    while (n--) {
        let d = a + b + c;
        a = b;
        b = c;
        c = d;
    }
    return a;
};
```

#### PHP

```php
class Solution {
    /**
     * @param Integer $n
     * @return Integer
     */
    function tribonacci($n) {
        $a = 0;
        $b = 1;
        $c = 1;

        while ($n--) {
            $d = $a + $b + $c;
            $a = $b;
            $b = $c;
            $c = $d;
        }

        return $a;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：矩阵快速幂加速递推

我们设 $Tib(n)$ 表示一个 $1 \times 3$ 的矩阵 $\begin{bmatrix} T_n & T_{n - 1} & T_{n - 2} \end{bmatrix}$，其中 $T_n$, $T_{n - 1}$ 和 $T_{n - 2}$ 分别表示第 $n$ 个、第 $n - 1$ 个和第 $n - 2$ 个泰波那契数。

我们希望根据 $Tib(n-1) = \begin{bmatrix} T_{n - 1} & T_{n - 2} & T_{n - 3} \end{bmatrix}$ 推出 $Tib(n)$。也即是说，我们需要一个矩阵 $base$，使得 $Tib(n - 1) \times base = Tib(n)$，即：

$$
\begin{bmatrix}
T_{n - 1} & T_{n - 2} & T_{n - 3}
\end{bmatrix} \times base = \begin{bmatrix} T_n & T_{n - 1} & T_{n - 2} \end{bmatrix}
$$

由于 $T_n = T_{n - 1} + T_{n - 2} + T_{n - 3}$，所以矩阵 $base$ 为：

$$
\begin{bmatrix}
 1 & 1 & 0 \\
 1 & 0 & 1 \\
 1 & 0 & 0
\end{bmatrix}
$$

我们定义初始矩阵 $res = \begin{bmatrix} 1 & 1  & 0 \end{bmatrix}$，那么 $T_n$ 等于 $res$ 乘以 $base^{n - 3}$ 的结果矩阵中所有元素之和。使用矩阵快速幂求解即可。

时间复杂度 $O(\log n)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
import numpy as np


class Solution:
    def tribonacci(self, n: int) -> int:
        if n == 0:
            return 0
        if n < 3:
            return 1
        factor = np.asmatrix([(1, 1, 0), (1, 0, 1), (1, 0, 0)], np.dtype("O"))
        res = np.asmatrix([(1, 1, 0)], np.dtype("O"))
        n -= 3
        while n:
            if n & 1:
                res *= factor
            factor *= factor
            n >>= 1
        return res.sum()
```

#### Java

```java
class Solution {
    public int tribonacci(int n) {
        if (n == 0) {
            return 0;
        }
        if (n < 3) {
            return 1;
        }
        int[][] a = {{1, 1, 0}, {1, 0, 1}, {1, 0, 0}};
        int[][] res = pow(a, n - 3);
        int ans = 0;
        for (int x : res[0]) {
            ans += x;
        }
        return ans;
    }

    private int[][] mul(int[][] a, int[][] b) {
        int m = a.length, n = b[0].length;
        int[][] c = new int[m][n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < b.length; ++k) {
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        return c;
    }

    private int[][] pow(int[][] a, int n) {
        int[][] res = {{1, 1, 0}};
        while (n > 0) {
            if ((n & 1) == 1) {
                res = mul(res, a);
            }
            a = mul(a, a);
            n >>= 1;
        }
        return res;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) {
            return 0;
        }
        if (n < 3) {
            return 1;
        }
        vector<vector<ll>> a = {{1, 1, 0}, {1, 0, 1}, {1, 0, 0}};
        vector<vector<ll>> res = pow(a, n - 3);
        return accumulate(res[0].begin(), res[0].end(), 0);
    }

private:
    using ll = long long;
    vector<vector<ll>> mul(vector<vector<ll>>& a, vector<vector<ll>>& b) {
        int m = a.size(), n = b[0].size();
        vector<vector<ll>> c(m, vector<ll>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < b.size(); ++k) {
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        return c;
    }

    vector<vector<ll>> pow(vector<vector<ll>>& a, int n) {
        vector<vector<ll>> res = {{1, 1, 0}};
        while (n) {
            if (n & 1) {
                res = mul(res, a);
            }
            a = mul(a, a);
            n >>= 1;
        }
        return res;
    }
};
```

#### Go

```go
func tribonacci(n int) (ans int) {
	if n == 0 {
		return 0
	}
	if n < 3 {
		return 1
	}
	a := [][]int{{1, 1, 0}, {1, 0, 1}, {1, 0, 0}}
	res := pow(a, n-3)
	for _, x := range res[0] {
		ans += x
	}
	return
}

func mul(a, b [][]int) [][]int {
	m, n := len(a), len(b[0])
	c := make([][]int, m)
	for i := range c {
		c[i] = make([]int, n)
	}
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			for k := 0; k < len(b); k++ {
				c[i][j] += a[i][k] * b[k][j]
			}
		}
	}
	return c
}

func pow(a [][]int, n int) [][]int {
	res := [][]int{{1, 1, 0}}
	for n > 0 {
		if n&1 == 1 {
			res = mul(res, a)
		}
		a = mul(a, a)
		n >>= 1
	}
	return res
}
```

#### TypeScript

```ts
function tribonacci(n: number): number {
    if (n === 0) {
        return 0;
    }
    if (n < 3) {
        return 1;
    }
    const a = [
        [1, 1, 0],
        [1, 0, 1],
        [1, 0, 0],
    ];
    return pow(a, n - 3)[0].reduce((a, b) => a + b);
}

function mul(a: number[][], b: number[][]): number[][] {
    const [m, n] = [a.length, b[0].length];
    const c = Array.from({ length: m }, () => Array.from({ length: n }, () => 0));
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            for (let k = 0; k < b.length; ++k) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return c;
}

function pow(a: number[][], n: number): number[][] {
    let res = [[1, 1, 0]];
    while (n) {
        if (n & 1) {
            res = mul(res, a);
        }
        a = mul(a, a);
        n >>= 1;
    }
    return res;
}
```

#### JavaScript

```js
/**
 * @param {number} n
 * @return {number}
 */
var tribonacci = function (n) {
    if (n === 0) {
        return 0;
    }
    if (n < 3) {
        return 1;
    }
    const a = [
        [1, 1, 0],
        [1, 0, 1],
        [1, 0, 0],
    ];
    return pow(a, n - 3)[0].reduce((a, b) => a + b);
};

function mul(a, b) {
    const [m, n] = [a.length, b[0].length];
    const c = Array.from({ length: m }, () => Array.from({ length: n }, () => 0));
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            for (let k = 0; k < b.length; ++k) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return c;
}

function pow(a, n) {
    let res = [[1, 1, 0]];
    while (n) {
        if (n & 1) {
            res = mul(res, a);
        }
        a = mul(a, a);
        n >>= 1;
    }
    return res;
}
```

#### PHP

```php
class Solution {
    /**
     * @param Integer $n
     * @return Integer
     */
    function tribonacci($n) {
        if ($n === 0) {
            return 0;
        }
        if ($n < 3) {
            return 1;
        }

        $a = [[1, 1, 0], [1, 0, 1], [1, 0, 0]];

        $res = $this->pow($a, $n - 3);
        return array_sum($res[0]);
    }

    private function mul($a, $b) {
        $m = count($a);
        $n = count($b[0]);
        $p = count($b);

        $c = array_fill(0, $m, array_fill(0, $n, 0));

        for ($i = 0; $i < $m; ++$i) {
            for ($j = 0; $j < $n; ++$j) {
                for ($k = 0; $k < $p; ++$k) {
                    $c[$i][$j] += $a[$i][$k] * $b[$k][$j];
                }
            }
        }

        return $c;
    }

    private function pow($a, $n) {
        $res = [[1, 1, 0]];
        while ($n > 0) {
            if ($n & 1) {
                $res = $this->mul($res, $a);
            }
            $a = $this->mul($a, $a);
            $n >>= 1;
        }
        return $res;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1138. 字母板上的路径](https://leetcode.cn/problems/alphabet-board-path){#1138}

{{< tabs "1138" >}}

{{% tab "python" %}}
```python
class Solution:
    def alphabetBoardPath(self, target: str) -> str:
        i = j = 0
        ans = []
        for c in target:
            v = ord(c) - ord("a")
            x, y = v // 5, v % 5
            while j > y:
                j -= 1
                ans.append("L")
            while i > x:
                i -= 1
                ans.append("U")
            while j < y:
                j += 1
                ans.append("R")
            while i < x:
                i += 1
                ans.append("D")
            ans.append("!")
        return "".join(ans)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String alphabetBoardPath(String target) {
        StringBuilder ans = new StringBuilder();
        int i = 0, j = 0;
        for (int k = 0; k < target.length(); ++k) {
            int v = target.charAt(k) - 'a';
            int x = v / 5, y = v % 5;
            while (j > y) {
                --j;
                ans.append('L');
            }
            while (i > x) {
                --i;
                ans.append('U');
            }
            while (j < y) {
                ++j;
                ans.append('R');
            }
            while (i < x) {
                ++i;
                ans.append('D');
            }
            ans.append("!");
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
    string alphabetBoardPath(string target) {
        string ans;
        int i = 0, j = 0;
        for (char& c : target) {
            int v = c - 'a';
            int x = v / 5, y = v % 5;
            while (j > y) {
                --j;
                ans += 'L';
            }
            while (i > x) {
                --i;
                ans += 'U';
            }
            while (j < y) {
                ++j;
                ans += 'R';
            }
            while (i < x) {
                ++i;
                ans += 'D';
            }
            ans += '!';
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func alphabetBoardPath(target string) string {
	ans := []byte{}
	var i, j int
	for _, c := range target {
		v := int(c - 'a')
		x, y := v/5, v%5
		for j > y {
			j--
			ans = append(ans, 'L')
		}
		for i > x {
			i--
			ans = append(ans, 'U')
		}
		for j < y {
			j++
			ans = append(ans, 'R')
		}
		for i < x {
			i++
			ans = append(ans, 'D')
		}
		ans = append(ans, '!')
	}
	return string(ans)
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>我们从一块字母板上的位置&nbsp;<code>(0, 0)</code>&nbsp;出发，该坐标对应的字符为&nbsp;<code>board[0][0]</code>。</p>

<p>在本题里，字母板为<code>board = ["abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"]</code>，如下所示。</p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1100-1199/1138.Alphabet%20Board%20Path/images/azboard.png" style="width: 300px;" /></p>

<p>我们可以按下面的指令规则行动：</p>

<ul>
	<li>如果方格存在，<code>'U'</code>&nbsp;意味着将我们的位置上移一行；</li>
	<li>如果方格存在，<code>'D'</code>&nbsp;意味着将我们的位置下移一行；</li>
	<li>如果方格存在，<code>'L'</code>&nbsp;意味着将我们的位置左移一列；</li>
	<li>如果方格存在，<code>'R'</code>&nbsp;意味着将我们的位置右移一列；</li>
	<li><code>'!'</code>&nbsp;会把在我们当前位置 <code>(r, c)</code> 的字符&nbsp;<code>board[r][c]</code>&nbsp;添加到答案中。</li>
</ul>

<p>（注意，字母板上只存在有字母的位置。）</p>

<p>返回指令序列，用最小的行动次数让答案和目标&nbsp;<code>target</code>&nbsp;相同。你可以返回任何达成目标的路径。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>target = "leet"
<strong>输出：</strong>"DDR!UURRR!!DDD!"
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>target = "code"
<strong>输出：</strong>"RR!DDRR!UUL!R!"
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= target.length &lt;= 100</code></li>
	<li><code>target</code>&nbsp;仅含有小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

从起点 $(0, 0)$ 出发，模拟每一步的移动，将每一步的移动结果拼接到答案中。注意移动的方向遵循“左、上、右、下”的顺序。

时间复杂度 $O(n)$，其中 $n$ 是字符串 $target$ 的长度，需要遍历字符串 $target$ 中的每一个字符。忽略答案的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def alphabetBoardPath(self, target: str) -> str:
        i = j = 0
        ans = []
        for c in target:
            v = ord(c) - ord("a")
            x, y = v // 5, v % 5
            while j > y:
                j -= 1
                ans.append("L")
            while i > x:
                i -= 1
                ans.append("U")
            while j < y:
                j += 1
                ans.append("R")
            while i < x:
                i += 1
                ans.append("D")
            ans.append("!")
        return "".join(ans)
```

#### Java

```java
class Solution {
    public String alphabetBoardPath(String target) {
        StringBuilder ans = new StringBuilder();
        int i = 0, j = 0;
        for (int k = 0; k < target.length(); ++k) {
            int v = target.charAt(k) - 'a';
            int x = v / 5, y = v % 5;
            while (j > y) {
                --j;
                ans.append('L');
            }
            while (i > x) {
                --i;
                ans.append('U');
            }
            while (j < y) {
                ++j;
                ans.append('R');
            }
            while (i < x) {
                ++i;
                ans.append('D');
            }
            ans.append("!");
        }
        return ans.toString();
    }
}
```

#### C++

```cpp
class Solution {
public:
    string alphabetBoardPath(string target) {
        string ans;
        int i = 0, j = 0;
        for (char& c : target) {
            int v = c - 'a';
            int x = v / 5, y = v % 5;
            while (j > y) {
                --j;
                ans += 'L';
            }
            while (i > x) {
                --i;
                ans += 'U';
            }
            while (j < y) {
                ++j;
                ans += 'R';
            }
            while (i < x) {
                ++i;
                ans += 'D';
            }
            ans += '!';
        }
        return ans;
    }
};
```

#### Go

```go
func alphabetBoardPath(target string) string {
	ans := []byte{}
	var i, j int
	for _, c := range target {
		v := int(c - 'a')
		x, y := v/5, v%5
		for j > y {
			j--
			ans = append(ans, 'L')
		}
		for i > x {
			i--
			ans = append(ans, 'U')
		}
		for j < y {
			j++
			ans = append(ans, 'R')
		}
		for i < x {
			i++
			ans = append(ans, 'D')
		}
		ans = append(ans, '!')
	}
	return string(ans)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1139. 最大的以 1 为边界的正方形](https://leetcode.cn/problems/largest-1-bordered-square){#1139}

{{< tabs "1139" >}}

{{% tab "python" %}}
```python
class Solution:
    def largest1BorderedSquare(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        down = [[0] * n for _ in range(m)]
        right = [[0] * n for _ in range(m)]
        for i in range(m - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                if grid[i][j]:
                    down[i][j] = down[i + 1][j] + 1 if i + 1 < m else 1
                    right[i][j] = right[i][j + 1] + 1 if j + 1 < n else 1
        for k in range(min(m, n), 0, -1):
            for i in range(m - k + 1):
                for j in range(n - k + 1):
                    if (
                        down[i][j] >= k
                        and right[i][j] >= k
                        and right[i + k - 1][j] >= k
                        and down[i][j + k - 1] >= k
                    ):
                        return k * k
        return 0
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int largest1BorderedSquare(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int[][] down = new int[m][n];
        int[][] right = new int[m][n];
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (grid[i][j] == 1) {
                    down[i][j] = i + 1 < m ? down[i + 1][j] + 1 : 1;
                    right[i][j] = j + 1 < n ? right[i][j + 1] + 1 : 1;
                }
            }
        }
        for (int k = Math.min(m, n); k > 0; --k) {
            for (int i = 0; i <= m - k; ++i) {
                for (int j = 0; j <= n - k; ++j) {
                    if (down[i][j] >= k && right[i][j] >= k && right[i + k - 1][j] >= k
                        && down[i][j + k - 1] >= k) {
                        return k * k;
                    }
                }
            }
        }
        return 0;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int down[m][n];
        int right[m][n];
        memset(down, 0, sizeof down);
        memset(right, 0, sizeof right);
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (grid[i][j] == 1) {
                    down[i][j] = i + 1 < m ? down[i + 1][j] + 1 : 1;
                    right[i][j] = j + 1 < n ? right[i][j + 1] + 1 : 1;
                }
            }
        }
        for (int k = min(m, n); k > 0; --k) {
            for (int i = 0; i <= m - k; ++i) {
                for (int j = 0; j <= n - k; ++j) {
                    if (down[i][j] >= k && right[i][j] >= k && right[i + k - 1][j] >= k
                        && down[i][j + k - 1] >= k) {
                        return k * k;
                    }
                }
            }
        }
        return 0;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func largest1BorderedSquare(grid [][]int) int {
	m, n := len(grid), len(grid[0])
	down := make([][]int, m)
	right := make([][]int, m)
	for i := range down {
		down[i] = make([]int, n)
		right[i] = make([]int, n)
	}
	for i := m - 1; i >= 0; i-- {
		for j := n - 1; j >= 0; j-- {
			if grid[i][j] == 1 {
				down[i][j], right[i][j] = 1, 1
				if i+1 < m {
					down[i][j] += down[i+1][j]
				}
				if j+1 < n {
					right[i][j] += right[i][j+1]
				}
			}
		}
	}
	for k := min(m, n); k > 0; k-- {
		for i := 0; i <= m-k; i++ {
			for j := 0; j <= n-k; j++ {
				if down[i][j] >= k && right[i][j] >= k && right[i+k-1][j] >= k && down[i][j+k-1] >= k {
					return k * k
				}
			}
		}
	}
	return 0
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个由若干 <code>0</code> 和 <code>1</code> 组成的二维网格&nbsp;<code>grid</code>，请你找出边界全部由 <code>1</code> 组成的最大 <strong>正方形</strong> 子网格，并返回该子网格中的元素数量。如果不存在，则返回 <code>0</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>grid = [[1,1,1],[1,0,1],[1,1,1]]
<strong>输出：</strong>9
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>grid = [[1,1,0,0]]
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= grid.length &lt;= 100</code></li>
	<li><code>1 &lt;= grid[0].length &lt;= 100</code></li>
	<li><code>grid[i][j]</code> 为&nbsp;<code>0</code>&nbsp;或&nbsp;<code>1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前缀和 + 枚举

我们可以使用前缀和的方法预处理出每个位置向下和向右的连续 $1$ 的个数，记为 `down[i][j]` 和 `right[i][j]`。

然后我们枚举正方形的边长 $k$，从最大的边长开始枚举，然后枚举正方形的左上角位置 $(i, j)$，如果满足条件，即可返回 $k^2$。

时间复杂度 $O(m \times n \times \min(m, n))$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别是网格的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def largest1BorderedSquare(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        down = [[0] * n for _ in range(m)]
        right = [[0] * n for _ in range(m)]
        for i in range(m - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                if grid[i][j]:
                    down[i][j] = down[i + 1][j] + 1 if i + 1 < m else 1
                    right[i][j] = right[i][j + 1] + 1 if j + 1 < n else 1
        for k in range(min(m, n), 0, -1):
            for i in range(m - k + 1):
                for j in range(n - k + 1):
                    if (
                        down[i][j] >= k
                        and right[i][j] >= k
                        and right[i + k - 1][j] >= k
                        and down[i][j + k - 1] >= k
                    ):
                        return k * k
        return 0
```

#### Java

```java
class Solution {
    public int largest1BorderedSquare(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int[][] down = new int[m][n];
        int[][] right = new int[m][n];
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (grid[i][j] == 1) {
                    down[i][j] = i + 1 < m ? down[i + 1][j] + 1 : 1;
                    right[i][j] = j + 1 < n ? right[i][j + 1] + 1 : 1;
                }
            }
        }
        for (int k = Math.min(m, n); k > 0; --k) {
            for (int i = 0; i <= m - k; ++i) {
                for (int j = 0; j <= n - k; ++j) {
                    if (down[i][j] >= k && right[i][j] >= k && right[i + k - 1][j] >= k
                        && down[i][j + k - 1] >= k) {
                        return k * k;
                    }
                }
            }
        }
        return 0;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int down[m][n];
        int right[m][n];
        memset(down, 0, sizeof down);
        memset(right, 0, sizeof right);
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (grid[i][j] == 1) {
                    down[i][j] = i + 1 < m ? down[i + 1][j] + 1 : 1;
                    right[i][j] = j + 1 < n ? right[i][j + 1] + 1 : 1;
                }
            }
        }
        for (int k = min(m, n); k > 0; --k) {
            for (int i = 0; i <= m - k; ++i) {
                for (int j = 0; j <= n - k; ++j) {
                    if (down[i][j] >= k && right[i][j] >= k && right[i + k - 1][j] >= k
                        && down[i][j + k - 1] >= k) {
                        return k * k;
                    }
                }
            }
        }
        return 0;
    }
};
```

#### Go

```go
func largest1BorderedSquare(grid [][]int) int {
	m, n := len(grid), len(grid[0])
	down := make([][]int, m)
	right := make([][]int, m)
	for i := range down {
		down[i] = make([]int, n)
		right[i] = make([]int, n)
	}
	for i := m - 1; i >= 0; i-- {
		for j := n - 1; j >= 0; j-- {
			if grid[i][j] == 1 {
				down[i][j], right[i][j] = 1, 1
				if i+1 < m {
					down[i][j] += down[i+1][j]
				}
				if j+1 < n {
					right[i][j] += right[i][j+1]
				}
			}
		}
	}
	for k := min(m, n); k > 0; k-- {
		for i := 0; i <= m-k; i++ {
			for j := 0; j <= n-k; j++ {
				if down[i][j] >= k && right[i][j] >= k && right[i+k-1][j] >= k && down[i][j+k-1] >= k {
					return k * k
				}
			}
		}
	}
	return 0
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
