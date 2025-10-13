---
title: "1000_合并石头的最低成本"
date: 2025-10-08T18:36:50+08:00
weight: 1
tags: [二分查找, 二叉搜索树, 二叉树, 位运算, 前缀和, 动态规划, 单调栈, 哈希表, 字符串, 排序, 数学, 数组, 栈, 树, 模拟, 滑动窗口, 贪心]
---

{{< markmap >}}
### [1000_合并石头的最低成本](#1000)
#### [数组](#1000)
#### [动态规划](#1000)
#### [前缀和](#1000)
### [1001_网格照明](#1001)
#### [数组](#1001)
#### [哈希表](#1001)
### [1002_查找共用字符](#1002)
#### [数组](#1002)
#### [哈希表](#1002)
#### [字符串](#1002)
### [1003_检查替换后的词是否有效](#1003)
#### [栈](#1003)
#### [字符串](#1003)
### [1004_最大连续1的个数 III](#1004)
#### [数组](#1004)
#### [二分查找](#1004)
#### [前缀和](#1004)
#### [滑动窗口](#1004)
### [1005_K 次取反后最大化的数组和](#1005)
#### [贪心](#1005)
#### [数组](#1005)
#### [排序](#1005)
### [1006_笨阶乘](#1006)
#### [栈](#1006)
#### [数学](#1006)
#### [模拟](#1006)
### [1007_行相等的最少多米诺旋转](#1007)
#### [贪心](#1007)
#### [数组](#1007)
### [1008_前序遍历构造二叉搜索树](#1008)
#### [栈](#1008)
#### [树](#1008)
#### [二叉搜索树](#1008)
#### [数组](#1008)
#### [二叉树](#1008)
#### [单调栈](#1008)
### [1009_十进制整数的反码](#1009)
#### [位运算](#1009)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1000_合并石头的最低成本
___
#### 数组
___
#### 动态规划
___
#### 前缀和
---
### 1001_网格照明
___
#### 数组
___
#### 哈希表
---
### 1002_查找共用字符
___
#### 数组
___
#### 哈希表
___
#### 字符串
---
### 1003_检查替换后的词是否有效
___
#### 栈
___
#### 字符串
---
### 1004_最大连续1的个数 III
___
#### 数组
___
#### 二分查找
___
#### 前缀和
___
#### 滑动窗口
---
### 1005_K 次取反后最大化的数组和
___
#### 贪心
___
#### 数组
___
#### 排序
---
### 1006_笨阶乘
___
#### 栈
___
#### 数学
___
#### 模拟
---
### 1007_行相等的最少多米诺旋转
___
#### 贪心
___
#### 数组
---
### 1008_前序遍历构造二叉搜索树
___
#### 栈
___
#### 树
___
#### 二叉搜索树
___
#### 数组
___
#### 二叉树
___
#### 单调栈
---
### 1009_十进制整数的反码
___
#### 位运算
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 二叉搜索树 | 二叉树 |
| 位运算 | 前缀和 | 动态规划 |
| 单调栈 | 哈希表 | 字符串 |
| 排序 | 数学 | 数组 |
| 栈 | 树 | 模拟 |
| 滑动窗口 | 贪心 |  |

# [1000. 合并石头的最低成本](https://leetcode.cn/problems/minimum-cost-to-merge-stones){#1000}

{{< tabs "1000" >}}

{{% tab "python" %}}
```python
class Solution:
    def mergeStones(self, stones: List[int], K: int) -> int:
        n = len(stones)
        if (n - 1) % (K - 1):
            return -1
        s = list(accumulate(stones, initial=0))
        f = [[[inf] * (K + 1) for _ in range(n + 1)] for _ in range(n + 1)]
        for i in range(1, n + 1):
            f[i][i][1] = 0
        for l in range(2, n + 1):
            for i in range(1, n - l + 2):
                j = i + l - 1
                for k in range(1, K + 1):
                    for h in range(i, j):
                        f[i][j][k] = min(f[i][j][k], f[i][h][1] + f[h + 1][j][k - 1])
                f[i][j][1] = f[i][j][K] + s[j] - s[i - 1]
        return f[1][n][1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int mergeStones(int[] stones, int K) {
        int n = stones.length;
        if ((n - 1) % (K - 1) != 0) {
            return -1;
        }
        int[] s = new int[n + 1];
        for (int i = 1; i <= n; ++i) {
            s[i] = s[i - 1] + stones[i - 1];
        }
        int[][][] f = new int[n + 1][n + 1][K + 1];
        final int inf = 1 << 20;
        for (int[][] g : f) {
            for (int[] e : g) {
                Arrays.fill(e, inf);
            }
        }
        for (int i = 1; i <= n; ++i) {
            f[i][i][1] = 0;
        }
        for (int l = 2; l <= n; ++l) {
            for (int i = 1; i + l - 1 <= n; ++i) {
                int j = i + l - 1;
                for (int k = 1; k <= K; ++k) {
                    for (int h = i; h < j; ++h) {
                        f[i][j][k] = Math.min(f[i][j][k], f[i][h][1] + f[h + 1][j][k - 1]);
                    }
                }
                f[i][j][1] = f[i][j][K] + s[j] - s[i - 1];
            }
        }
        return f[1][n][1];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int mergeStones(vector<int>& stones, int K) {
        int n = stones.size();
        if ((n - 1) % (K - 1)) {
            return -1;
        }
        int s[n + 1];
        s[0] = 0;
        for (int i = 1; i <= n; ++i) {
            s[i] = s[i - 1] + stones[i - 1];
        }
        int f[n + 1][n + 1][K + 1];
        memset(f, 0x3f, sizeof(f));
        for (int i = 1; i <= n; ++i) {
            f[i][i][1] = 0;
        }
        for (int l = 2; l <= n; ++l) {
            for (int i = 1; i + l - 1 <= n; ++i) {
                int j = i + l - 1;
                for (int k = 1; k <= K; ++k) {
                    for (int h = i; h < j; ++h) {
                        f[i][j][k] = min(f[i][j][k], f[i][h][1] + f[h + 1][j][k - 1]);
                    }
                }
                f[i][j][1] = f[i][j][K] + s[j] - s[i - 1];
            }
        }
        return f[1][n][1];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func mergeStones(stones []int, K int) int {
	n := len(stones)
	if (n-1)%(K-1) != 0 {
		return -1
	}
	s := make([]int, n+1)
	for i, x := range stones {
		s[i+1] = s[i] + x
	}
	f := make([][][]int, n+1)
	for i := range f {
		f[i] = make([][]int, n+1)
		for j := range f[i] {
			f[i][j] = make([]int, K+1)
			for k := range f[i][j] {
				f[i][j][k] = 1 << 20
			}
		}
	}
	for i := 1; i <= n; i++ {
		f[i][i][1] = 0
	}
	for l := 2; l <= n; l++ {
		for i := 1; i <= n-l+1; i++ {
			j := i + l - 1
			for k := 2; k <= K; k++ {
				for h := i; h < j; h++ {
					f[i][j][k] = min(f[i][j][k], f[i][h][k-1]+f[h+1][j][1])
				}
			}
			f[i][j][1] = f[i][j][K] + s[j] - s[i-1]
		}
	}
	return f[1][n][1]
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>有 <code>n</code> 堆石头排成一排，第 <code>i</code> 堆中有&nbsp;<code>stones[i]</code>&nbsp;块石头。</p>

<p>每次 <strong>移动</strong> 需要将 <strong>连续的</strong> <code>k</code> 堆石头合并为一堆，而这次移动的成本为这 <code>k</code> 堆中石头的总数。</p>

<p>返回把所有石头合并成一堆的最低成本。如果无法合并成一堆，返回 <code>-1</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>stones = [3,2,4,1], K = 2
<strong>输出：</strong>20
<strong>解释：</strong>
从 [3, 2, 4, 1] 开始。
合并 [3, 2]，成本为 5，剩下 [5, 4, 1]。
合并 [4, 1]，成本为 5，剩下 [5, 5]。
合并 [5, 5]，成本为 10，剩下 [10]。
总成本 20，这是可能的最小值。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>stones = [3,2,4,1], K = 3
<strong>输出：</strong>-1
<strong>解释：</strong>任何合并操作后，都会剩下 2 堆，我们无法再进行合并。所以这项任务是不可能完成的。.
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>stones = [3,5,1,2,6], K = 3
<strong>输出：</strong>25
<strong>解释：</strong>
从 [3, 5, 1, 2, 6] 开始。
合并 [5, 1, 2]，成本为 8，剩下 [3, 8, 6]。
合并 [3, 8, 6]，成本为 17，剩下 [17]。
总成本 25，这是可能的最小值。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == stones.length</code></li>
	<li><code>1 &lt;= n &lt;= 30</code></li>
	<li><code>1 &lt;= stones[i] &lt;= 100</code></li>
	<li><code>2 &lt;= k &lt;= 30</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划（区间 DP）+ 前缀和

我们不妨记题目中的 $k$ 为 $K$，石头的堆数为 $n$。

定义 $f[i][j][k]$ 表示将区间 $[i, j]$ 中的石头合并成 $k$ 堆的最小成本。初始时 $f[i][i][1] = 0$，其他位置的值均为 $\infty$。

注意到 $k$ 的取值范围为 $[1, K]$，因此我们需要枚举 $k$ 的值。

对于 $f[i][j][k]$，我们可以枚举 $i \leq h \lt j$，将区间 $[i, j]$ 拆分成两个区间 $[i, h]$ 和 $[h + 1, j]$，然后将 $[i, h]$ 中的石头合并成 $1$ 堆，将 $[h + 1, j]$ 中的石头合并成 $k - 1$ 堆，最后将这两堆石头合并成一堆，这样就可以将区间 $[i, j]$ 中的石头合并成 $k$ 堆。因此，我们可以得到状态转移方程：

$$
f[i][j][k] = \min_{i \leq h < j} \{f[i][h][1] + f[h + 1][j][k - 1]\}
$$

我们将区间 $[i, j]$ 的 $K$ 堆石头合并成一堆，因此 $f[i][j][1] = f[i][j][K] + \sum_{t = i}^j stones[t]$，其中 $\sum_{t = i}^j stones[t]$ 表示区间 $[i, j]$ 中石头的总数。

最后答案即为 $f[1][n][1]$，其中 $n$ 为石头的堆数。

时间复杂度 $O(n^3 \times k)$，空间复杂度 $O(n^2 \times k)$。其中 $n$ 为石头的堆数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def mergeStones(self, stones: List[int], K: int) -> int:
        n = len(stones)
        if (n - 1) % (K - 1):
            return -1
        s = list(accumulate(stones, initial=0))
        f = [[[inf] * (K + 1) for _ in range(n + 1)] for _ in range(n + 1)]
        for i in range(1, n + 1):
            f[i][i][1] = 0
        for l in range(2, n + 1):
            for i in range(1, n - l + 2):
                j = i + l - 1
                for k in range(1, K + 1):
                    for h in range(i, j):
                        f[i][j][k] = min(f[i][j][k], f[i][h][1] + f[h + 1][j][k - 1])
                f[i][j][1] = f[i][j][K] + s[j] - s[i - 1]
        return f[1][n][1]
```

#### Java

```java
class Solution {
    public int mergeStones(int[] stones, int K) {
        int n = stones.length;
        if ((n - 1) % (K - 1) != 0) {
            return -1;
        }
        int[] s = new int[n + 1];
        for (int i = 1; i <= n; ++i) {
            s[i] = s[i - 1] + stones[i - 1];
        }
        int[][][] f = new int[n + 1][n + 1][K + 1];
        final int inf = 1 << 20;
        for (int[][] g : f) {
            for (int[] e : g) {
                Arrays.fill(e, inf);
            }
        }
        for (int i = 1; i <= n; ++i) {
            f[i][i][1] = 0;
        }
        for (int l = 2; l <= n; ++l) {
            for (int i = 1; i + l - 1 <= n; ++i) {
                int j = i + l - 1;
                for (int k = 1; k <= K; ++k) {
                    for (int h = i; h < j; ++h) {
                        f[i][j][k] = Math.min(f[i][j][k], f[i][h][1] + f[h + 1][j][k - 1]);
                    }
                }
                f[i][j][1] = f[i][j][K] + s[j] - s[i - 1];
            }
        }
        return f[1][n][1];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int mergeStones(vector<int>& stones, int K) {
        int n = stones.size();
        if ((n - 1) % (K - 1)) {
            return -1;
        }
        int s[n + 1];
        s[0] = 0;
        for (int i = 1; i <= n; ++i) {
            s[i] = s[i - 1] + stones[i - 1];
        }
        int f[n + 1][n + 1][K + 1];
        memset(f, 0x3f, sizeof(f));
        for (int i = 1; i <= n; ++i) {
            f[i][i][1] = 0;
        }
        for (int l = 2; l <= n; ++l) {
            for (int i = 1; i + l - 1 <= n; ++i) {
                int j = i + l - 1;
                for (int k = 1; k <= K; ++k) {
                    for (int h = i; h < j; ++h) {
                        f[i][j][k] = min(f[i][j][k], f[i][h][1] + f[h + 1][j][k - 1]);
                    }
                }
                f[i][j][1] = f[i][j][K] + s[j] - s[i - 1];
            }
        }
        return f[1][n][1];
    }
};
```

#### Go

```go
func mergeStones(stones []int, K int) int {
	n := len(stones)
	if (n-1)%(K-1) != 0 {
		return -1
	}
	s := make([]int, n+1)
	for i, x := range stones {
		s[i+1] = s[i] + x
	}
	f := make([][][]int, n+1)
	for i := range f {
		f[i] = make([][]int, n+1)
		for j := range f[i] {
			f[i][j] = make([]int, K+1)
			for k := range f[i][j] {
				f[i][j][k] = 1 << 20
			}
		}
	}
	for i := 1; i <= n; i++ {
		f[i][i][1] = 0
	}
	for l := 2; l <= n; l++ {
		for i := 1; i <= n-l+1; i++ {
			j := i + l - 1
			for k := 2; k <= K; k++ {
				for h := i; h < j; h++ {
					f[i][j][k] = min(f[i][j][k], f[i][h][k-1]+f[h+1][j][1])
				}
			}
			f[i][j][1] = f[i][j][K] + s[j] - s[i-1]
		}
	}
	return f[1][n][1]
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1001. 网格照明](https://leetcode.cn/problems/grid-illumination){#1001}

{{< tabs "1001" >}}

{{% tab "python" %}}
```python
class Solution:
    def gridIllumination(
        self, n: int, lamps: List[List[int]], queries: List[List[int]]
    ) -> List[int]:
        s = {(i, j) for i, j in lamps}
        row, col, diag1, diag2 = Counter(), Counter(), Counter(), Counter()
        for i, j in s:
            row[i] += 1
            col[j] += 1
            diag1[i - j] += 1
            diag2[i + j] += 1
        ans = [0] * len(queries)
        for k, (i, j) in enumerate(queries):
            if row[i] or col[j] or diag1[i - j] or diag2[i + j]:
                ans[k] = 1
            for x in range(i - 1, i + 2):
                for y in range(j - 1, j + 2):
                    if (x, y) in s:
                        s.remove((x, y))
                        row[x] -= 1
                        col[y] -= 1
                        diag1[x - y] -= 1
                        diag2[x + y] -= 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int n;
    public int[] gridIllumination(int n, int[][] lamps, int[][] queries) {
        this.n = n;
        Set<Long> s = new HashSet<>();
        Map<Integer, Integer> row = new HashMap<>();
        Map<Integer, Integer> col = new HashMap<>();
        Map<Integer, Integer> diag1 = new HashMap<>();
        Map<Integer, Integer> diag2 = new HashMap<>();
        for (var lamp : lamps) {
            int i = lamp[0], j = lamp[1];
            if (s.add(f(i, j))) {
                merge(row, i, 1);
                merge(col, j, 1);
                merge(diag1, i - j, 1);
                merge(diag2, i + j, 1);
            }
        }
        int m = queries.length;
        int[] ans = new int[m];
        for (int k = 0; k < m; ++k) {
            int i = queries[k][0], j = queries[k][1];
            if (exist(row, i) || exist(col, j) || exist(diag1, i - j) || exist(diag2, i + j)) {
                ans[k] = 1;
            }
            for (int x = i - 1; x <= i + 1; ++x) {
                for (int y = j - 1; y <= j + 1; ++y) {
                    if (x < 0 || x >= n || y < 0 || y >= n || !s.contains(f(x, y))) {
                        continue;
                    }
                    s.remove(f(x, y));
                    merge(row, x, -1);
                    merge(col, y, -1);
                    merge(diag1, x - y, -1);
                    merge(diag2, x + y, -1);
                }
            }
        }
        return ans;
    }

    private void merge(Map<Integer, Integer> cnt, int x, int d) {
        if (cnt.merge(x, d, Integer::sum) == 0) {
            cnt.remove(x);
        }
    }

    private boolean exist(Map<Integer, Integer> cnt, int x) {
        return cnt.getOrDefault(x, 0) > 0;
    }

    private long f(long i, long j) {
        return i * n + j;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        auto f = [&](int i, int j) -> long long {
            return (long long) i * n + j;
        };
        unordered_set<long long> s;
        unordered_map<int, int> row, col, diag1, diag2;
        for (auto& lamp : lamps) {
            int i = lamp[0], j = lamp[1];
            if (!s.count(f(i, j))) {
                s.insert(f(i, j));
                row[i]++;
                col[j]++;
                diag1[i - j]++;
                diag2[i + j]++;
            }
        }
        int m = queries.size();
        vector<int> ans(m);
        for (int k = 0; k < m; ++k) {
            int i = queries[k][0], j = queries[k][1];
            if (row[i] > 0 || col[j] > 0 || diag1[i - j] > 0 || diag2[i + j] > 0) {
                ans[k] = 1;
            }
            for (int x = i - 1; x <= i + 1; ++x) {
                for (int y = j - 1; y <= j + 1; ++y) {
                    if (x < 0 || x >= n || y < 0 || y >= n || !s.count(f(x, y))) {
                        continue;
                    }
                    s.erase(f(x, y));
                    row[x]--;
                    col[y]--;
                    diag1[x - y]--;
                    diag2[x + y]--;
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
func gridIllumination(n int, lamps [][]int, queries [][]int) []int {
	row, col, diag1, diag2 := map[int]int{}, map[int]int{}, map[int]int{}, map[int]int{}
	type pair struct{ x, y int }
	s := map[pair]bool{}
	for _, lamp := range lamps {
		i, j := lamp[0], lamp[1]
		p := pair{i, j}
		if !s[p] {
			s[p] = true
			row[i]++
			col[j]++
			diag1[i-j]++
			diag2[i+j]++
		}
	}
	m := len(queries)
	ans := make([]int, m)
	for k, q := range queries {
		i, j := q[0], q[1]
		if row[i] > 0 || col[j] > 0 || diag1[i-j] > 0 || diag2[i+j] > 0 {
			ans[k] = 1
		}
		for x := i - 1; x <= i+1; x++ {
			for y := j - 1; y <= j+1; y++ {
				p := pair{x, y}
				if s[p] {
					s[p] = false
					row[x]--
					col[y]--
					diag1[x-y]--
					diag2[x+y]--
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
function gridIllumination(n: number, lamps: number[][], queries: number[][]): number[] {
    const row = new Map<number, number>();
    const col = new Map<number, number>();
    const diag1 = new Map<number, number>();
    const diag2 = new Map<number, number>();
    const s = new Set<number>();
    for (const [i, j] of lamps) {
        if (s.has(i * n + j)) {
            continue;
        }
        s.add(i * n + j);
        row.set(i, (row.get(i) || 0) + 1);
        col.set(j, (col.get(j) || 0) + 1);
        diag1.set(i - j, (diag1.get(i - j) || 0) + 1);
        diag2.set(i + j, (diag2.get(i + j) || 0) + 1);
    }
    const ans: number[] = [];
    for (const [i, j] of queries) {
        if (row.get(i)! > 0 || col.get(j)! > 0 || diag1.get(i - j)! > 0 || diag2.get(i + j)! > 0) {
            ans.push(1);
        } else {
            ans.push(0);
        }
        for (let x = i - 1; x <= i + 1; ++x) {
            for (let y = j - 1; y <= j + 1; ++y) {
                if (x < 0 || x >= n || y < 0 || y >= n || !s.has(x * n + y)) {
                    continue;
                }
                s.delete(x * n + y);
                row.set(x, row.get(x)! - 1);
                col.set(y, col.get(y)! - 1);
                diag1.set(x - y, diag1.get(x - y)! - 1);
                diag2.set(x + y, diag2.get(x + y)! - 1);
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

<p>在大小为 <code>n x n</code> 的网格 <code>grid</code> 上，每个单元格都有一盏灯，最初灯都处于 <strong>关闭</strong> 状态。</p>

<p>给你一个由灯的位置组成的二维数组&nbsp;<code>lamps</code> ，其中 <code>lamps[i] = [row<sub>i</sub>, col<sub>i</sub>]</code> 表示 <strong>打开</strong> 位于 <code>grid[row<sub>i</sub>][col<sub>i</sub>]</code> 的灯。即便同一盏灯可能在 <code>lamps</code> 中多次列出，不会影响这盏灯处于 <strong>打开</strong> 状态。</p>

<p>当一盏灯处于打开状态，它将会照亮 <strong>自身所在单元格</strong> 以及同一 <strong>行</strong> 、同一 <strong>列</strong> 和两条 <strong>对角线</strong> 上的 <strong>所有其他单元格</strong> 。</p>

<p>另给你一个二维数组 <code>queries</code> ，其中 <code>queries[j] = [row<sub>j</sub>, col<sub>j</sub>]</code> 。对于第 <code>j</code> 个查询，如果单元格 <code>[row<sub>j</sub>, col<sub>j</sub>]</code> 是被照亮的，则查询结果为 <code>1</code> ，否则为 <code>0</code> 。在第 <code>j</code> 次查询之后 [按照查询的顺序] ，<strong>关闭</strong> 位于单元格 <code>grid[row<sub>j</sub>][col<sub>j</sub>]</code> 上及相邻 8 个方向上（与单元格 <code>grid[row<sub>i</sub>][col<sub>i</sub>]</code> 共享角或边）的任何灯。</p>

<p>返回一个整数数组 <code>ans</code> 作为答案， <code>ans[j]</code> 应等于第 <code>j</code> 次查询&nbsp;<code>queries[j]</code>&nbsp;的结果，<code>1</code> 表示照亮，<code>0</code> 表示未照亮。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1000-1099/1001.Grid%20Illumination/images/illu_1.jpg" style="height: 209px; width: 750px;" />
<pre>
<strong>输入：</strong>n = 5, lamps = [[0,0],[4,4]], queries = [[1,1],[1,0]]
<strong>输出：</strong>[1,0]
<strong>解释：</strong>最初所有灯都是关闭的。在执行查询之前，打开位于 [0, 0] 和 [4, 4] 的灯。第 0&nbsp;次查询检查 grid[1][1] 是否被照亮（蓝色方框）。该单元格被照亮，所以 ans[0] = 1 。然后，关闭红色方框中的所有灯。
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1000-1099/1001.Grid%20Illumination/images/illu_step1.jpg" style="height: 218px; width: 500px;" />
第 1&nbsp;次查询检查 grid[1][0] 是否被照亮（蓝色方框）。该单元格没有被照亮，所以 ans[1] = 0 。然后，关闭红色矩形中的所有灯。
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1000-1099/1001.Grid%20Illumination/images/illu_step2.jpg" style="height: 219px; width: 500px;" />
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 5, lamps = [[0,0],[4,4]], queries = [[1,1],[1,1]]
<strong>输出：</strong>[1,1]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 5, lamps = [[0,0],[0,4]], queries = [[0,4],[0,1],[1,4]]
<strong>输出：</strong>[1,1,0]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= lamps.length &lt;= 20000</code></li>
	<li><code>0 &lt;= queries.length &lt;= 20000</code></li>
	<li><code>lamps[i].length == 2</code></li>
	<li><code>0 &lt;= row<sub>i</sub>, col<sub>i</sub> &lt; n</code></li>
	<li><code>queries[j].length == 2</code></li>
	<li><code>0 &lt;= row<sub>j</sub>, col<sub>j</sub> &lt; n</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

假设一盏灯的坐标为 $(x, y)$，那么它所在的行的数值为 $x$，列的数值为 $y$，正对角线的数值为 $x-y$，反对角线的数值为 $x+y$。确定某一直线的唯一数值标识后，我们就可以通过哈希表来记录某一直线所拥有的灯的数目。

我们遍历数组 $\textit{lamps}$，将当前遍历到的灯所在的行、列和正、反对角线拥有灯的数目分别加 $1$。

注意，在处理 $\textit{lamps}$ 时，需要进行去重，因为我们将重复的灯看作同一盏灯。

接下来，我们遍历 queries，判断当前查询点所在的行，列和正、反对角线是否有灯，如果有，则置 $1$，即该点在查询时是被照亮的。然后进行关闭操作，查找查询点所在的八近邻点及它本身是否有灯，如果有，将该点所在的行、列和正、反对角线的灯数目分别减 $1$，并且将灯从网格中去掉。

最后，返回答案数组即可。

时间复杂度 $O(m + q)$，其中 $m$ 和 $q$ 分别为数组 $\textit{lamps}$ 和 $\textit{queries}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def gridIllumination(
        self, n: int, lamps: List[List[int]], queries: List[List[int]]
    ) -> List[int]:
        s = {(i, j) for i, j in lamps}
        row, col, diag1, diag2 = Counter(), Counter(), Counter(), Counter()
        for i, j in s:
            row[i] += 1
            col[j] += 1
            diag1[i - j] += 1
            diag2[i + j] += 1
        ans = [0] * len(queries)
        for k, (i, j) in enumerate(queries):
            if row[i] or col[j] or diag1[i - j] or diag2[i + j]:
                ans[k] = 1
            for x in range(i - 1, i + 2):
                for y in range(j - 1, j + 2):
                    if (x, y) in s:
                        s.remove((x, y))
                        row[x] -= 1
                        col[y] -= 1
                        diag1[x - y] -= 1
                        diag2[x + y] -= 1
        return ans
```

#### Java

```java
class Solution {
    private int n;
    public int[] gridIllumination(int n, int[][] lamps, int[][] queries) {
        this.n = n;
        Set<Long> s = new HashSet<>();
        Map<Integer, Integer> row = new HashMap<>();
        Map<Integer, Integer> col = new HashMap<>();
        Map<Integer, Integer> diag1 = new HashMap<>();
        Map<Integer, Integer> diag2 = new HashMap<>();
        for (var lamp : lamps) {
            int i = lamp[0], j = lamp[1];
            if (s.add(f(i, j))) {
                merge(row, i, 1);
                merge(col, j, 1);
                merge(diag1, i - j, 1);
                merge(diag2, i + j, 1);
            }
        }
        int m = queries.length;
        int[] ans = new int[m];
        for (int k = 0; k < m; ++k) {
            int i = queries[k][0], j = queries[k][1];
            if (exist(row, i) || exist(col, j) || exist(diag1, i - j) || exist(diag2, i + j)) {
                ans[k] = 1;
            }
            for (int x = i - 1; x <= i + 1; ++x) {
                for (int y = j - 1; y <= j + 1; ++y) {
                    if (x < 0 || x >= n || y < 0 || y >= n || !s.contains(f(x, y))) {
                        continue;
                    }
                    s.remove(f(x, y));
                    merge(row, x, -1);
                    merge(col, y, -1);
                    merge(diag1, x - y, -1);
                    merge(diag2, x + y, -1);
                }
            }
        }
        return ans;
    }

    private void merge(Map<Integer, Integer> cnt, int x, int d) {
        if (cnt.merge(x, d, Integer::sum) == 0) {
            cnt.remove(x);
        }
    }

    private boolean exist(Map<Integer, Integer> cnt, int x) {
        return cnt.getOrDefault(x, 0) > 0;
    }

    private long f(long i, long j) {
        return i * n + j;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        auto f = [&](int i, int j) -> long long {
            return (long long) i * n + j;
        };
        unordered_set<long long> s;
        unordered_map<int, int> row, col, diag1, diag2;
        for (auto& lamp : lamps) {
            int i = lamp[0], j = lamp[1];
            if (!s.count(f(i, j))) {
                s.insert(f(i, j));
                row[i]++;
                col[j]++;
                diag1[i - j]++;
                diag2[i + j]++;
            }
        }
        int m = queries.size();
        vector<int> ans(m);
        for (int k = 0; k < m; ++k) {
            int i = queries[k][0], j = queries[k][1];
            if (row[i] > 0 || col[j] > 0 || diag1[i - j] > 0 || diag2[i + j] > 0) {
                ans[k] = 1;
            }
            for (int x = i - 1; x <= i + 1; ++x) {
                for (int y = j - 1; y <= j + 1; ++y) {
                    if (x < 0 || x >= n || y < 0 || y >= n || !s.count(f(x, y))) {
                        continue;
                    }
                    s.erase(f(x, y));
                    row[x]--;
                    col[y]--;
                    diag1[x - y]--;
                    diag2[x + y]--;
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func gridIllumination(n int, lamps [][]int, queries [][]int) []int {
	row, col, diag1, diag2 := map[int]int{}, map[int]int{}, map[int]int{}, map[int]int{}
	type pair struct{ x, y int }
	s := map[pair]bool{}
	for _, lamp := range lamps {
		i, j := lamp[0], lamp[1]
		p := pair{i, j}
		if !s[p] {
			s[p] = true
			row[i]++
			col[j]++
			diag1[i-j]++
			diag2[i+j]++
		}
	}
	m := len(queries)
	ans := make([]int, m)
	for k, q := range queries {
		i, j := q[0], q[1]
		if row[i] > 0 || col[j] > 0 || diag1[i-j] > 0 || diag2[i+j] > 0 {
			ans[k] = 1
		}
		for x := i - 1; x <= i+1; x++ {
			for y := j - 1; y <= j+1; y++ {
				p := pair{x, y}
				if s[p] {
					s[p] = false
					row[x]--
					col[y]--
					diag1[x-y]--
					diag2[x+y]--
				}
			}
		}
	}
	return ans
}
```

#### TypeScript

```ts
function gridIllumination(n: number, lamps: number[][], queries: number[][]): number[] {
    const row = new Map<number, number>();
    const col = new Map<number, number>();
    const diag1 = new Map<number, number>();
    const diag2 = new Map<number, number>();
    const s = new Set<number>();
    for (const [i, j] of lamps) {
        if (s.has(i * n + j)) {
            continue;
        }
        s.add(i * n + j);
        row.set(i, (row.get(i) || 0) + 1);
        col.set(j, (col.get(j) || 0) + 1);
        diag1.set(i - j, (diag1.get(i - j) || 0) + 1);
        diag2.set(i + j, (diag2.get(i + j) || 0) + 1);
    }
    const ans: number[] = [];
    for (const [i, j] of queries) {
        if (row.get(i)! > 0 || col.get(j)! > 0 || diag1.get(i - j)! > 0 || diag2.get(i + j)! > 0) {
            ans.push(1);
        } else {
            ans.push(0);
        }
        for (let x = i - 1; x <= i + 1; ++x) {
            for (let y = j - 1; y <= j + 1; ++y) {
                if (x < 0 || x >= n || y < 0 || y >= n || !s.has(x * n + y)) {
                    continue;
                }
                s.delete(x * n + y);
                row.set(x, row.get(x)! - 1);
                col.set(y, col.get(y)! - 1);
                diag1.set(x - y, diag1.get(x - y)! - 1);
                diag2.set(x + y, diag2.get(x + y)! - 1);
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

# [1002. 查找共用字符](https://leetcode.cn/problems/find-common-characters){#1002}

{{< tabs "1002" >}}

{{% tab "python" %}}
```python
class Solution:
    def commonChars(self, words: List[str]) -> List[str]:
        cnt = Counter(words[0])
        for w in words:
            t = Counter(w)
            for c in cnt:
                cnt[c] = min(cnt[c], t[c])
        return list(cnt.elements())
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<String> commonChars(String[] words) {
        int[] cnt = new int[26];
        Arrays.fill(cnt, 20000);
        for (var w : words) {
            int[] t = new int[26];
            for (int i = 0; i < w.length(); ++i) {
                ++t[w.charAt(i) - 'a'];
            }
            for (int i = 0; i < 26; ++i) {
                cnt[i] = Math.min(cnt[i], t[i]);
            }
        }
        List<String> ans = new ArrayList<>();
        for (int i = 0; i < 26; ++i) {
            ans.addAll(Collections.nCopies(cnt[i], String.valueOf((char) ('a' + i))));
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
    vector<string> commonChars(vector<string>& words) {
        vector<int> cnt(26, 20000);
        for (const auto& w : words) {
            vector<int> t(26, 0);
            for (char c : w) {
                ++t[c - 'a'];
            }
            for (int i = 0; i < 26; ++i) {
                cnt[i] = min(cnt[i], t[i]);
            }
        }
        vector<string> ans;
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < cnt[i]; ++j) {
                ans.push_back(string(1, 'a' + i));
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func commonChars(words []string) (ans []string) {
	cnt := make([]int, 26)
	for i := range cnt {
		cnt[i] = 20000
	}
	for _, w := range words {
		t := make([]int, 26)
		for _, c := range w {
			t[c-'a']++
		}
		for i := 0; i < 26; i++ {
			cnt[i] = min(cnt[i], t[i])
		}
	}
	for i := 0; i < 26; i++ {
		for j := 0; j < cnt[i]; j++ {
			ans = append(ans, string('a'+rune(i)))
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function commonChars(words: string[]): string[] {
    const cnt = Array(26).fill(20000);
    const aCode = 'a'.charCodeAt(0);
    for (const w of words) {
        const t = Array(26).fill(0);
        for (const c of w) {
            t[c.charCodeAt(0) - aCode]++;
        }
        for (let i = 0; i < 26; i++) {
            cnt[i] = Math.min(cnt[i], t[i]);
        }
    }
    const ans: string[] = [];
    for (let i = 0; i < 26; i++) {
        cnt[i] && ans.push(...String.fromCharCode(i + aCode).repeat(cnt[i]));
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

给你一个字符串数组 <code>words</code> ，请你找出所有在 <code>words</code> 的每个字符串中都出现的共用字符（<strong>包括重复字符</strong>），并以数组形式返回。你可以按 <strong>任意顺序</strong> 返回答案。

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>words = ["bella","label","roller"]
<strong>输出：</strong>["e","l","l"]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>words = ["cool","lock","cook"]
<strong>输出：</strong>["c","o"]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 100</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 100</code></li>
	<li><code>words[i]</code> 由小写英文字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数

我们用一个长度为 $26$ 的数组 $cnt$ 记录每个字符在所有字符串中出现的最小次数，最后遍历 $cnt$ 数组，将出现次数大于 $0$ 的字符加入答案即可。

时间复杂度 $O(n \sum w_i)$，空间复杂度 $O(|\Sigma|)$。其中 $n$ 为字符串数组 $words$ 的长度，而 $w_i$ 为字符串数组 $words$ 中第 $i$ 个字符串的长度，另外 $|\Sigma|$ 为字符集的大小，本题中 $|\Sigma| = 26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def commonChars(self, words: List[str]) -> List[str]:
        cnt = Counter(words[0])
        for w in words:
            t = Counter(w)
            for c in cnt:
                cnt[c] = min(cnt[c], t[c])
        return list(cnt.elements())
```

#### Java

```java
class Solution {
    public List<String> commonChars(String[] words) {
        int[] cnt = new int[26];
        Arrays.fill(cnt, 20000);
        for (var w : words) {
            int[] t = new int[26];
            for (int i = 0; i < w.length(); ++i) {
                ++t[w.charAt(i) - 'a'];
            }
            for (int i = 0; i < 26; ++i) {
                cnt[i] = Math.min(cnt[i], t[i]);
            }
        }
        List<String> ans = new ArrayList<>();
        for (int i = 0; i < 26; ++i) {
            ans.addAll(Collections.nCopies(cnt[i], String.valueOf((char) ('a' + i))));
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> cnt(26, 20000);
        for (const auto& w : words) {
            vector<int> t(26, 0);
            for (char c : w) {
                ++t[c - 'a'];
            }
            for (int i = 0; i < 26; ++i) {
                cnt[i] = min(cnt[i], t[i]);
            }
        }
        vector<string> ans;
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < cnt[i]; ++j) {
                ans.push_back(string(1, 'a' + i));
            }
        }
        return ans;
    }
};
```

#### Go

```go
func commonChars(words []string) (ans []string) {
	cnt := make([]int, 26)
	for i := range cnt {
		cnt[i] = 20000
	}
	for _, w := range words {
		t := make([]int, 26)
		for _, c := range w {
			t[c-'a']++
		}
		for i := 0; i < 26; i++ {
			cnt[i] = min(cnt[i], t[i])
		}
	}
	for i := 0; i < 26; i++ {
		for j := 0; j < cnt[i]; j++ {
			ans = append(ans, string('a'+rune(i)))
		}
	}
	return ans
}
```

#### TypeScript

```ts
function commonChars(words: string[]): string[] {
    const cnt = Array(26).fill(20000);
    const aCode = 'a'.charCodeAt(0);
    for (const w of words) {
        const t = Array(26).fill(0);
        for (const c of w) {
            t[c.charCodeAt(0) - aCode]++;
        }
        for (let i = 0; i < 26; i++) {
            cnt[i] = Math.min(cnt[i], t[i]);
        }
    }
    const ans: string[] = [];
    for (let i = 0; i < 26; i++) {
        cnt[i] && ans.push(...String.fromCharCode(i + aCode).repeat(cnt[i]));
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1003. 检查替换后的词是否有效](https://leetcode.cn/problems/check-if-word-is-valid-after-substitutions){#1003}

{{< tabs "1003" >}}

{{% tab "python" %}}
```python
class Solution:
    def isValid(self, s: str) -> bool:
        if len(s) % 3:
            return False
        t = []
        for c in s:
            t.append(c)
            if ''.join(t[-3:]) == 'abc':
                t[-3:] = []
        return not t
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean isValid(String s) {
        if (s.length() % 3 > 0) {
            return false;
        }
        StringBuilder t = new StringBuilder();
        for (char c : s.toCharArray()) {
            t.append(c);
            if (t.length() >= 3 && "abc".equals(t.substring(t.length() - 3))) {
                t.delete(t.length() - 3, t.length());
            }
        }
        return t.isEmpty();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 3) {
            return false;
        }
        string t;
        for (char c : s) {
            t.push_back(c);
            if (t.size() >= 3 && t.substr(t.size() - 3, 3) == "abc") {
                t.erase(t.end() - 3, t.end());
            }
        }
        return t.empty();
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func isValid(s string) bool {
	if len(s)%3 > 0 {
		return false
	}
	t := []byte{}
	for i := range s {
		t = append(t, s[i])
		if len(t) >= 3 && string(t[len(t)-3:]) == "abc" {
			t = t[:len(t)-3]
		}
	}
	return len(t) == 0
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function isValid(s: string): boolean {
    if (s.length % 3 !== 0) {
        return false;
    }
    const t: string[] = [];
    for (const c of s) {
        t.push(c);
        if (t.slice(-3).join('') === 'abc') {
            t.splice(-3);
        }
    }
    return t.length === 0;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

给你一个字符串 <code>s</code> ，请你判断它是否 <strong>有效</strong> 。

<p>字符串 <code>s</code> <strong>有效</strong> 需要满足：假设开始有一个空字符串 <code>t = ""</code> ，你可以执行 <strong>任意次</strong> 下述操作将<strong> </strong><code>t</code><strong> 转换为 </strong><code>s</code> ：</p>

<ul>
	<li>将字符串 <code>"abc"</code> 插入到 <code>t</code> 中的任意位置。形式上，<code>t</code> 变为 <code>t<sub>left</sub> + "abc" + t<sub>right</sub></code>，其中 <code>t == t<sub>left</sub> + t<sub>right</sub></code> 。注意，<code>t<sub>left</sub></code> 和 <code>t<sub>right</sub></code> 可能为 <strong>空</strong> 。</li>
</ul>

<p>如果字符串 <code>s</code> 有效，则返回 <code>true</code>；否则，返回 <code>false</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "aabcbc"
<strong>输出：</strong>true
<strong>解释：</strong>
"" -&gt; "<strong>abc</strong>" -&gt; "a<strong>abc</strong>bc"
因此，"aabcbc" 有效。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "abcabcababcc"
<strong>输出：</strong>true
<strong>解释：</strong>
"" -&gt; "<strong>abc</strong>" -&gt; "abc<strong>abc</strong>" -&gt; "abcabc<strong>abc</strong>" -&gt; "abcabcab<strong>abc</strong>c"
因此，"abcabcababcc" 有效。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "abccba"
<strong>输出：</strong>false
<strong>解释：</strong>执行操作无法得到 "abccba" 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>s</code> 由字母 <code>'a'</code>、<code>'b'</code> 和 <code>'c'</code> 组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：栈

我们观察题目中的操作，可以发现，每一次都会在字符串的任意位置插入字符串 $\textit{"abc"}$，所以每次插入操作之后，字符串的长度都会增加 $3$。如果字符串 $s$ 有效，那么它的长度一定是 $3$ 的倍数。因此，我们先对字符串 $s$ 的长度进行判断，如果不是 $3$ 的倍数，那么 $s$ 一定无效，可以直接返回 $\textit{false}$。

接下来我们遍历字符串 $s$ 的每个字符 $c$，我们先将字符 $c$ 压入栈 $t$ 中。如果此时栈 $t$ 的长度大于等于 $3$，并且栈顶的三个元素组成了字符串 $\textit{"abc"}$，那么我们就将栈顶的三个元素弹出。然后继续遍历字符串 $s$ 的下一个字符。

遍历结束之后，如果栈 $t$ 为空，那么说明字符串 $s$ 有效，返回 $\textit{true}$；否则，返回 $\textit{false}$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是字符串 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def isValid(self, s: str) -> bool:
        if len(s) % 3:
            return False
        t = []
        for c in s:
            t.append(c)
            if ''.join(t[-3:]) == 'abc':
                t[-3:] = []
        return not t
```

#### Java

```java
class Solution {
    public boolean isValid(String s) {
        if (s.length() % 3 > 0) {
            return false;
        }
        StringBuilder t = new StringBuilder();
        for (char c : s.toCharArray()) {
            t.append(c);
            if (t.length() >= 3 && "abc".equals(t.substring(t.length() - 3))) {
                t.delete(t.length() - 3, t.length());
            }
        }
        return t.isEmpty();
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 3) {
            return false;
        }
        string t;
        for (char c : s) {
            t.push_back(c);
            if (t.size() >= 3 && t.substr(t.size() - 3, 3) == "abc") {
                t.erase(t.end() - 3, t.end());
            }
        }
        return t.empty();
    }
};
```

#### Go

```go
func isValid(s string) bool {
	if len(s)%3 > 0 {
		return false
	}
	t := []byte{}
	for i := range s {
		t = append(t, s[i])
		if len(t) >= 3 && string(t[len(t)-3:]) == "abc" {
			t = t[:len(t)-3]
		}
	}
	return len(t) == 0
}
```

#### TypeScript

```ts
function isValid(s: string): boolean {
    if (s.length % 3 !== 0) {
        return false;
    }
    const t: string[] = [];
    for (const c of s) {
        t.push(c);
        if (t.slice(-3).join('') === 'abc') {
            t.splice(-3);
        }
    }
    return t.length === 0;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1004. 最大连续1的个数 III](https://leetcode.cn/problems/max-consecutive-ones-iii){#1004}

{{< tabs "1004" >}}

{{% tab "python" %}}
```python
class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        l = cnt = 0
        for x in nums:
            cnt += x ^ 1
            if cnt > k:
                cnt -= nums[l] ^ 1
                l += 1
        return len(nums) - l
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int longestOnes(int[] nums, int k) {
        int l = 0, cnt = 0;
        for (int x : nums) {
            cnt += x ^ 1;
            if (cnt > k) {
                cnt -= nums[l++] ^ 1;
            }
        }
        return nums.length - l;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, cnt = 0;
        for (int x : nums) {
            cnt += x ^ 1;
            if (cnt > k) {
                cnt -= nums[l++] ^ 1;
            }
        }
        return nums.size() - l;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func longestOnes(nums []int, k int) int {
	l, cnt := 0, 0
	for _, x := range nums {
		cnt += x ^ 1
		if cnt > k {
			cnt -= nums[l] ^ 1
			l++
		}
	}
	return len(nums) - l
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function longestOnes(nums: number[], k: number): number {
    let [l, cnt] = [0, 0];
    for (const x of nums) {
        cnt += x ^ 1;
        if (cnt > k) {
            cnt -= nums[l++] ^ 1;
        }
    }
    return nums.length - l;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个二进制数组&nbsp;<code>nums</code>&nbsp;和一个整数 <code>k</code>，假设最多可以翻转 <code>k</code> 个 <code>0</code> ，则返回执行操作后 <em>数组中连续 <code>1</code> 的最大个数</em> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,1,1,0,0,0,1,1,1,1,0], K = 2
<strong>输出：</strong>6
<strong>解释：</strong>[1,1,1,0,0,<strong>1</strong>,1,1,1,1,<strong>1</strong>]
粗体数字从 0 翻转到 1，最长的子数组长度为 6。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], K = 3
<strong>输出：</strong>10
<strong>解释：</strong>[0,0,1,1,<strong>1</strong>,<strong>1</strong>,1,1,1,<strong>1</strong>,1,1,0,0,0,1,1,1,1]
粗体数字从 0 翻转到 1，最长的子数组长度为 10。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>nums[i]</code>&nbsp;不是&nbsp;<code>0</code>&nbsp;就是&nbsp;<code>1</code></li>
	<li><code>0 &lt;= k &lt;= nums.length</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：滑动窗口

我们可以遍历数组，用一个变量 $\textit{cnt}$ 记录当前窗口中 0 的个数，当 $\textit{cnt} > k$ 时，我们将窗口的左边界右移一位。

遍历结束后，窗口的长度即为最大连续 1 的个数。

注意，在上述过程中，我们不需要循环将窗口的左边界右移，而是直接将左边界右移一位，这是因为，题目求的是最大连续 1 的个数，因此，窗口的长度只会增加，不会减少，所以我们不需要循环右移左边界。

时间复杂度 $O(n)$，其中 $n$ 为数组的长度。空间复杂度 $O(1)$。

相似题目：

-   [487. 最大连续 1 的个数 II](https://github.com/doocs/leetcode/blob/main/solution/0400-0499/0487.Max%20Consecutive%20Ones%20II/README.md)
-   [2024. 考试的最大困扰度](https://github.com/doocs/leetcode/blob/main/solution/2000-2099/2024.Maximize%20the%20Confusion%20of%20an%20Exam/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        l = cnt = 0
        for x in nums:
            cnt += x ^ 1
            if cnt > k:
                cnt -= nums[l] ^ 1
                l += 1
        return len(nums) - l
```

#### Java

```java
class Solution {
    public int longestOnes(int[] nums, int k) {
        int l = 0, cnt = 0;
        for (int x : nums) {
            cnt += x ^ 1;
            if (cnt > k) {
                cnt -= nums[l++] ^ 1;
            }
        }
        return nums.length - l;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, cnt = 0;
        for (int x : nums) {
            cnt += x ^ 1;
            if (cnt > k) {
                cnt -= nums[l++] ^ 1;
            }
        }
        return nums.size() - l;
    }
};
```

#### Go

```go
func longestOnes(nums []int, k int) int {
	l, cnt := 0, 0
	for _, x := range nums {
		cnt += x ^ 1
		if cnt > k {
			cnt -= nums[l] ^ 1
			l++
		}
	}
	return len(nums) - l
}
```

#### TypeScript

```ts
function longestOnes(nums: number[], k: number): number {
    let [l, cnt] = [0, 0];
    for (const x of nums) {
        cnt += x ^ 1;
        if (cnt > k) {
            cnt -= nums[l++] ^ 1;
        }
    }
    return nums.length - l;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1005. K 次取反后最大化的数组和](https://leetcode.cn/problems/maximize-sum-of-array-after-k-negations){#1005}

{{< tabs "1005" >}}

{{% tab "python" %}}
```python
class Solution:
    def largestSumAfterKNegations(self, nums: List[int], k: int) -> int:
        cnt = Counter(nums)
        for x in range(-100, 0):
            if cnt[x]:
                m = min(cnt[x], k)
                cnt[x] -= m
                cnt[-x] += m
                k -= m
                if k == 0:
                    break
        if k & 1 and cnt[0] == 0:
            for x in range(1, 101):
                if cnt[x]:
                    cnt[x] -= 1
                    cnt[-x] += 1
                    break
        return sum(x * v for x, v in cnt.items())
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int largestSumAfterKNegations(int[] nums, int k) {
        Map<Integer, Integer> cnt = new HashMap<>();
        for (int x : nums) {
            cnt.merge(x, 1, Integer::sum);
        }
        for (int x = -100; x < 0 && k > 0; ++x) {
            if (cnt.getOrDefault(x, 0) > 0) {
                int m = Math.min(cnt.get(x), k);
                cnt.merge(x, -m, Integer::sum);
                cnt.merge(-x, m, Integer::sum);
                k -= m;
            }
        }
        if ((k & 1) == 1 && cnt.getOrDefault(0, 0) == 0) {
            for (int x = 1; x <= 100; ++x) {
                if (cnt.getOrDefault(x, 0) > 0) {
                    cnt.merge(x, -1, Integer::sum);
                    cnt.merge(-x, 1, Integer::sum);
                    break;
                }
            }
        }
        int ans = 0;
        for (var e : cnt.entrySet()) {
            ans += e.getKey() * e.getValue();
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
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        for (int& x : nums) {
            ++cnt[x];
        }
        for (int x = -100; x < 0 && k > 0; ++x) {
            if (cnt[x]) {
                int m = min(cnt[x], k);
                cnt[x] -= m;
                cnt[-x] += m;
                k -= m;
            }
        }
        if ((k & 1) && !cnt[0]) {
            for (int x = 1; x <= 100; ++x) {
                if (cnt[x]) {
                    --cnt[x];
                    ++cnt[-x];
                    break;
                }
            }
        }
        int ans = 0;
        for (auto& [x, v] : cnt) {
            ans += x * v;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func largestSumAfterKNegations(nums []int, k int) (ans int) {
	cnt := map[int]int{}
	for _, x := range nums {
		cnt[x]++
	}
	for x := -100; x < 0 && k > 0; x++ {
		if cnt[x] > 0 {
			m := min(k, cnt[x])
			cnt[x] -= m
			cnt[-x] += m
			k -= m
		}
	}
	if k&1 == 1 && cnt[0] == 0 {
		for x := 1; x <= 100; x++ {
			if cnt[x] > 0 {
				cnt[x]--
				cnt[-x]++
				break
			}
		}
	}
	for x, v := range cnt {
		ans += x * v
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function largestSumAfterKNegations(nums: number[], k: number): number {
    const cnt: Map<number, number> = new Map();
    for (const x of nums) {
        cnt.set(x, (cnt.get(x) || 0) + 1);
    }
    for (let x = -100; x < 0 && k > 0; ++x) {
        if (cnt.get(x)! > 0) {
            const m = Math.min(cnt.get(x) || 0, k);
            cnt.set(x, (cnt.get(x) || 0) - m);
            cnt.set(-x, (cnt.get(-x) || 0) + m);
            k -= m;
        }
    }
    if ((k & 1) === 1 && (cnt.get(0) || 0) === 0) {
        for (let x = 1; x <= 100; ++x) {
            if (cnt.get(x)! > 0) {
                cnt.set(x, (cnt.get(x) || 0) - 1);
                cnt.set(-x, (cnt.get(-x) || 0) + 1);
                break;
            }
        }
    }
    return Array.from(cnt.entries()).reduce((acc, [k, v]) => acc + k * v, 0);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>nums</code> 和一个整数 <code>k</code> ，按以下方法修改该数组：</p>

<ul>
	<li>选择某个下标 <code>i</code>&nbsp;并将 <code>nums[i]</code> 替换为 <code>-nums[i]</code> 。</li>
</ul>

<p>重复这个过程恰好 <code>k</code> 次。可以多次选择同一个下标 <code>i</code> 。</p>

<p>以这种方式修改数组后，返回数组 <strong>可能的最大和</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [4,2,3], k = 1
<strong>输出：</strong>5
<strong>解释：</strong>选择下标 1 ，nums 变为 [4,-2,3] 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [3,-1,0,2], k = 3
<strong>输出：</strong>6
<strong>解释：</strong>选择下标 (1, 2, 2) ，nums 变为 [3,1,0,2] 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,-3,-1,5,-4], k = 2
<strong>输出：</strong>13
<strong>解释：</strong>选择下标 (1, 4) ，nums 变为 [2,3,-1,5,4] 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
	<li><code>-100 &lt;= nums[i] &lt;= 100</code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 计数

我们观察发现，要使得数组的和尽可能大，就应该尽可能地将数组中的最小负数变成正数。

而题目中元素的范围为 $[-100,100]$，因此，我们可以先用哈希表 $\textit{cnt}$ 统计数组 $\textit{nums}$ 中每个元素出现的次数。接着从 $-100$ 开始遍历 $x$，如果哈希表中存在 $x$，那么我们取 $m = \min(cnt[x], k)$ 作为元素 $x$ 取反的个数，然后我们将 $\textit{cnt}[x]$ 减去 $m$，将 $\textit{cnt}[-x]$ 加上 $m$，并将 $k$ 减去 $m$。如果 $k$ 为 $0$，说明操作已经结束，直接退出循环即可。

如果 $k$ 仍然为奇数，且 $\textit{cnt}[0]=0$，那么我们还需要取 $\textit{cnt}$ 中最小的一个正数 $x$，将 $\textit{cnt}[x]$ 减去 $1$，将 $\textit{cnt}[-x]$ 加上 $1$。

最后，我们遍历哈希表 $\textit{cnt}$，将 $x$ 与 $\textit{cnt}[x]$ 相乘的结果累加，即为答案。

时间复杂度 $O(n + M)$，空间复杂度 $O(M)$。其中 $n$ 和 $M$ 分别为数组 $\textit{nums}$ 的长度和 $\textit{nums}$ 的数据范围大小。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def largestSumAfterKNegations(self, nums: List[int], k: int) -> int:
        cnt = Counter(nums)
        for x in range(-100, 0):
            if cnt[x]:
                m = min(cnt[x], k)
                cnt[x] -= m
                cnt[-x] += m
                k -= m
                if k == 0:
                    break
        if k & 1 and cnt[0] == 0:
            for x in range(1, 101):
                if cnt[x]:
                    cnt[x] -= 1
                    cnt[-x] += 1
                    break
        return sum(x * v for x, v in cnt.items())
```

#### Java

```java
class Solution {
    public int largestSumAfterKNegations(int[] nums, int k) {
        Map<Integer, Integer> cnt = new HashMap<>();
        for (int x : nums) {
            cnt.merge(x, 1, Integer::sum);
        }
        for (int x = -100; x < 0 && k > 0; ++x) {
            if (cnt.getOrDefault(x, 0) > 0) {
                int m = Math.min(cnt.get(x), k);
                cnt.merge(x, -m, Integer::sum);
                cnt.merge(-x, m, Integer::sum);
                k -= m;
            }
        }
        if ((k & 1) == 1 && cnt.getOrDefault(0, 0) == 0) {
            for (int x = 1; x <= 100; ++x) {
                if (cnt.getOrDefault(x, 0) > 0) {
                    cnt.merge(x, -1, Integer::sum);
                    cnt.merge(-x, 1, Integer::sum);
                    break;
                }
            }
        }
        int ans = 0;
        for (var e : cnt.entrySet()) {
            ans += e.getKey() * e.getValue();
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        for (int& x : nums) {
            ++cnt[x];
        }
        for (int x = -100; x < 0 && k > 0; ++x) {
            if (cnt[x]) {
                int m = min(cnt[x], k);
                cnt[x] -= m;
                cnt[-x] += m;
                k -= m;
            }
        }
        if ((k & 1) && !cnt[0]) {
            for (int x = 1; x <= 100; ++x) {
                if (cnt[x]) {
                    --cnt[x];
                    ++cnt[-x];
                    break;
                }
            }
        }
        int ans = 0;
        for (auto& [x, v] : cnt) {
            ans += x * v;
        }
        return ans;
    }
};
```

#### Go

```go
func largestSumAfterKNegations(nums []int, k int) (ans int) {
	cnt := map[int]int{}
	for _, x := range nums {
		cnt[x]++
	}
	for x := -100; x < 0 && k > 0; x++ {
		if cnt[x] > 0 {
			m := min(k, cnt[x])
			cnt[x] -= m
			cnt[-x] += m
			k -= m
		}
	}
	if k&1 == 1 && cnt[0] == 0 {
		for x := 1; x <= 100; x++ {
			if cnt[x] > 0 {
				cnt[x]--
				cnt[-x]++
				break
			}
		}
	}
	for x, v := range cnt {
		ans += x * v
	}
	return
}
```

#### TypeScript

```ts
function largestSumAfterKNegations(nums: number[], k: number): number {
    const cnt: Map<number, number> = new Map();
    for (const x of nums) {
        cnt.set(x, (cnt.get(x) || 0) + 1);
    }
    for (let x = -100; x < 0 && k > 0; ++x) {
        if (cnt.get(x)! > 0) {
            const m = Math.min(cnt.get(x) || 0, k);
            cnt.set(x, (cnt.get(x) || 0) - m);
            cnt.set(-x, (cnt.get(-x) || 0) + m);
            k -= m;
        }
    }
    if ((k & 1) === 1 && (cnt.get(0) || 0) === 0) {
        for (let x = 1; x <= 100; ++x) {
            if (cnt.get(x)! > 0) {
                cnt.set(x, (cnt.get(x) || 0) - 1);
                cnt.set(-x, (cnt.get(-x) || 0) + 1);
                break;
            }
        }
    }
    return Array.from(cnt.entries()).reduce((acc, [k, v]) => acc + k * v, 0);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1006. 笨阶乘](https://leetcode.cn/problems/clumsy-factorial){#1006}

{{< tabs "1006" >}}

{{% tab "python" %}}
```python
class Solution:
    def clumsy(self, n: int) -> int:
        k = 0
        stk = [n]
        for x in range(n - 1, 0, -1):
            if k == 0:
                stk.append(stk.pop() * x)
            elif k == 1:
                stk.append(int(stk.pop() / x))
            elif k == 2:
                stk.append(x)
            else:
                stk.append(-x)
            k = (k + 1) % 4
        return sum(stk)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int clumsy(int n) {
        Deque<Integer> stk = new ArrayDeque<>();
        stk.push(n);
        int k = 0;
        for (int x = n - 1; x > 0; --x) {
            if (k == 0) {
                stk.push(stk.pop() * x);
            } else if (k == 1) {
                stk.push(stk.pop() / x);
            } else if (k == 2) {
                stk.push(x);
            } else {
                stk.push(-x);
            }
            k = (k + 1) % 4;
        }
        return stk.stream().mapToInt(Integer::intValue).sum();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int clumsy(int n) {
        stack<int> stk;
        stk.push(n);
        int k = 0;
        for (int x = n - 1; x; --x) {
            if (k == 0) {
                stk.top() *= x;
            } else if (k == 1) {
                stk.top() /= x;
            } else if (k == 2) {
                stk.push(x);
            } else {
                stk.push(-x);
            }
            k = (k + 1) % 4;
        }
        int ans = 0;
        while (!stk.empty()) {
            ans += stk.top();
            stk.pop();
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func clumsy(n int) (ans int) {
	stk := []int{n}
	k := 0
	for x := n - 1; x > 0; x-- {
		switch k {
		case 0:
			stk[len(stk)-1] *= x
		case 1:
			stk[len(stk)-1] /= x
		case 2:
			stk = append(stk, x)
		case 3:
			stk = append(stk, -x)
		}
		k = (k + 1) % 4
	}
	for _, x := range stk {
		ans += x
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function clumsy(n: number): number {
    const stk: number[] = [n];
    let k = 0;
    for (let x = n - 1; x; --x) {
        if (k === 0) {
            stk.push(stk.pop()! * x);
        } else if (k === 1) {
            stk.push((stk.pop()! / x) | 0);
        } else if (k === 2) {
            stk.push(x);
        } else {
            stk.push(-x);
        }
        k = (k + 1) % 4;
    }
    return stk.reduce((acc, cur) => acc + cur, 0);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>通常，正整数 <code>n</code> 的阶乘是所有小于或等于 <code>n</code> 的正整数的乘积。例如，<code>factorial(10) = 10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1</code>。</p>

<p>相反，我们设计了一个笨阶乘 <code>clumsy</code>：在整数的递减序列中，我们以一个固定顺序的操作符序列来依次替换原有的乘法操作符：乘法(*)，除法(/)，加法(+)和减法(-)。</p>

<p>例如，<code>clumsy(10) = 10 * 9 / 8 + 7 - 6 * 5 / 4 + 3 - 2 * 1</code>。然而，这些运算仍然使用通常的算术运算顺序：我们在任何加、减步骤之前执行所有的乘法和除法步骤，并且按从左到右处理乘法和除法步骤。</p>

<p>另外，我们使用的除法是地板除法（<em>floor division</em>），所以&nbsp;<code>10 * 9 / 8</code>&nbsp;等于&nbsp;<code>11</code>。这保证结果是一个整数。</p>

<p>实现上面定义的笨函数：给定一个整数 <code>N</code>，它返回 <code>N</code> 的笨阶乘。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>4
<strong>输出：</strong>7
<strong>解释：</strong>7 = 4 * 3 / 2 + 1
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>10
<strong>输出：</strong>12
<strong>解释：</strong>12 = 10 * 9 / 8 + 7 - 6 * 5 / 4 + 3 - 2 * 1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ol>
	<li><code>1 &lt;= N &lt;= 10000</code></li>
	<li><code>-2^31 &lt;= answer &lt;= 2^31 - 1</code>&nbsp; （答案保证符合 32 位整数。）</li>
</ol>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：栈 + 模拟

笨阶乘的计算过程可以看作是一个栈的模拟过程。

我们定义一个栈 `stk`，初始时我们将 $n$ 入栈，定义一个变量 $k$，表示当前的操作符，初始时 $k = 0$。

然后我们从 $n-1$ 开始，枚举 $x$，根据当前的 $k$ 的值，决定如何处理 $x$：

-   当 $k = 0$ 时，表示乘法操作，我们将栈顶元素出栈，与 $x$ 相乘后再入栈；
-   当 $k = 1$ 时，表示除法操作，我们将栈顶元素出栈，与 $x$ 相除后取整数部分再入栈；
-   当 $k = 2$ 时，表示加法操作，我们直接将 $x$ 入栈；
-   当 $k = 3$ 时，表示减法操作，我们将 $-x$ 入栈。

接着我们更新 $k = (k + 1) \mod 4$。

最后，我们将栈中的元素累加即为答案。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为题目给定的整数 $N$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def clumsy(self, n: int) -> int:
        k = 0
        stk = [n]
        for x in range(n - 1, 0, -1):
            if k == 0:
                stk.append(stk.pop() * x)
            elif k == 1:
                stk.append(int(stk.pop() / x))
            elif k == 2:
                stk.append(x)
            else:
                stk.append(-x)
            k = (k + 1) % 4
        return sum(stk)
```

#### Java

```java
class Solution {
    public int clumsy(int n) {
        Deque<Integer> stk = new ArrayDeque<>();
        stk.push(n);
        int k = 0;
        for (int x = n - 1; x > 0; --x) {
            if (k == 0) {
                stk.push(stk.pop() * x);
            } else if (k == 1) {
                stk.push(stk.pop() / x);
            } else if (k == 2) {
                stk.push(x);
            } else {
                stk.push(-x);
            }
            k = (k + 1) % 4;
        }
        return stk.stream().mapToInt(Integer::intValue).sum();
    }
}
```

#### C++

```cpp
class Solution {
public:
    int clumsy(int n) {
        stack<int> stk;
        stk.push(n);
        int k = 0;
        for (int x = n - 1; x; --x) {
            if (k == 0) {
                stk.top() *= x;
            } else if (k == 1) {
                stk.top() /= x;
            } else if (k == 2) {
                stk.push(x);
            } else {
                stk.push(-x);
            }
            k = (k + 1) % 4;
        }
        int ans = 0;
        while (!stk.empty()) {
            ans += stk.top();
            stk.pop();
        }
        return ans;
    }
};
```

#### Go

```go
func clumsy(n int) (ans int) {
	stk := []int{n}
	k := 0
	for x := n - 1; x > 0; x-- {
		switch k {
		case 0:
			stk[len(stk)-1] *= x
		case 1:
			stk[len(stk)-1] /= x
		case 2:
			stk = append(stk, x)
		case 3:
			stk = append(stk, -x)
		}
		k = (k + 1) % 4
	}
	for _, x := range stk {
		ans += x
	}
	return
}
```

#### TypeScript

```ts
function clumsy(n: number): number {
    const stk: number[] = [n];
    let k = 0;
    for (let x = n - 1; x; --x) {
        if (k === 0) {
            stk.push(stk.pop()! * x);
        } else if (k === 1) {
            stk.push((stk.pop()! / x) | 0);
        } else if (k === 2) {
            stk.push(x);
        } else {
            stk.push(-x);
        }
        k = (k + 1) % 4;
    }
    return stk.reduce((acc, cur) => acc + cur, 0);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1007. 行相等的最少多米诺旋转](https://leetcode.cn/problems/minimum-domino-rotations-for-equal-row){#1007}

{{< tabs "1007" >}}

{{% tab "python" %}}
```python
class Solution:
    def minDominoRotations(self, tops: List[int], bottoms: List[int]) -> int:
        def f(x: int) -> int:
            cnt1 = cnt2 = 0
            for a, b in zip(tops, bottoms):
                if x not in (a, b):
                    return inf
                cnt1 += a == x
                cnt2 += b == x
            return len(tops) - max(cnt1, cnt2)

        ans = min(f(tops[0]), f(bottoms[0]))
        return -1 if ans == inf else ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int n;
    private int[] tops;
    private int[] bottoms;

    public int minDominoRotations(int[] tops, int[] bottoms) {
        n = tops.length;
        this.tops = tops;
        this.bottoms = bottoms;
        int ans = Math.min(f(tops[0]), f(bottoms[0]));
        return ans > n ? -1 : ans;
    }

    private int f(int x) {
        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; ++i) {
            if (tops[i] != x && bottoms[i] != x) {
                return n + 1;
            }
            cnt1 += tops[i] == x ? 1 : 0;
            cnt2 += bottoms[i] == x ? 1 : 0;
        }
        return n - Math.max(cnt1, cnt2);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        auto f = [&](int x) {
            int cnt1 = 0, cnt2 = 0;
            for (int i = 0; i < n; ++i) {
                if (tops[i] != x && bottoms[i] != x) {
                    return n + 1;
                }
                cnt1 += tops[i] == x;
                cnt2 += bottoms[i] == x;
            }
            return n - max(cnt1, cnt2);
        };
        int ans = min(f(tops[0]), f(bottoms[0]));
        return ans > n ? -1 : ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minDominoRotations(tops []int, bottoms []int) int {
	n := len(tops)
	f := func(x int) int {
		cnt1, cnt2 := 0, 0
		for i, a := range tops {
			b := bottoms[i]
			if a != x && b != x {
				return n + 1
			}
			if a == x {
				cnt1++
			}
			if b == x {
				cnt2++
			}
		}
		return n - max(cnt1, cnt2)
	}
	ans := min(f(tops[0]), f(bottoms[0]))
	if ans > n {
		return -1
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minDominoRotations(tops: number[], bottoms: number[]): number {
    const n = tops.length;
    const f = (x: number): number => {
        let [cnt1, cnt2] = [0, 0];
        for (let i = 0; i < n; ++i) {
            if (tops[i] !== x && bottoms[i] !== x) {
                return n + 1;
            }
            cnt1 += tops[i] === x ? 1 : 0;
            cnt2 += bottoms[i] === x ? 1 : 0;
        }
        return n - Math.max(cnt1, cnt2);
    };
    const ans = Math.min(f(tops[0]), f(bottoms[0]));
    return ans > n ? -1 : ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn min_domino_rotations(tops: Vec<i32>, bottoms: Vec<i32>) -> i32 {
        let n = tops.len() as i32;
        let f = |x: i32| -> i32 {
            let mut cnt1 = 0;
            let mut cnt2 = 0;
            for i in 0..n as usize {
                if tops[i] != x && bottoms[i] != x {
                    return n + 1;
                }
                if tops[i] == x {
                    cnt1 += 1;
                }
                if bottoms[i] == x {
                    cnt2 += 1;
                }
            }
            n - cnt1.max(cnt2)
        };

        let ans = f(tops[0]).min(f(bottoms[0]));
        if ans > n { -1 } else { ans }
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>在一排多米诺骨牌中，<code>tops[i]</code> 和 <code>bottoms[i]</code>&nbsp;分别代表第 <code>i</code> 个多米诺骨牌的上半部分和下半部分。（一个多米诺是两个从 1 到 6 的数字同列平铺形成的&nbsp;—— 该平铺的每一半上都有一个数字。）</p>

<p>我们可以旋转第&nbsp;<code>i</code>&nbsp;张多米诺，使得 <code>tops[i]</code> 和 <code>bottoms[i]</code>&nbsp;的值交换。</p>

<p>返回能使 <code>tops</code> 中所有值或者 <code>bottoms</code> 中所有值都相同的最小旋转次数。</p>

<p>如果无法做到，返回&nbsp;<code>-1</code>.</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1000-1099/1007.Minimum%20Domino%20Rotations%20For%20Equal%20Row/images/domino.png" style="height: 300px; width: 421px;" />
<pre>
<strong>输入：</strong>tops = [2,1,2,4,2,2], bottoms = [5,2,6,2,3,2]
<strong>输出：</strong>2
<strong>解释：</strong> 
图一表示：在我们旋转之前， tops 和 bottoms 给出的多米诺牌。 
如果我们旋转第二个和第四个多米诺骨牌，我们可以使上面一行中的每个值都等于 2，如图二所示。 
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>tops = [3,5,1,2,3], bottoms = [3,6,3,3,4]
<strong>输出：</strong>-1
<strong>解释：</strong> 在这种情况下，不可能旋转多米诺牌使一行的值相等。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= tops.length &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>bottoms.length == tops.length</code></li>
	<li><code>1 &lt;= tops[i], bottoms[i] &lt;= 6</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心

根据题目描述，我们知道，要使得 $tops$ 中所有值或者 $bottoms$ 中所有值都相同，那么这个值必须是 $tops[0]$ 或者 $bottoms[0]$ 中的一个。

因此，我们设计一个函数 $f(x)$，表示将所有的值都变成 $x$ 的最小旋转次数，那么答案就是 $\min\{f(\textit{tops}[0]), f(\textit{bottoms}[0])\}$。

函数 $f(x)$ 的计算方法如下：

我们用两个变量 $cnt1$ 和 $cnt2$ 统计 $tops$ 和 $bottoms$ 中等于 $x$ 的个数，用 $n$ 减去它们的最大值，就是将所有值都变成 $x$ 的最小旋转次数。注意，如果 $tops$ 和 $bottoms$ 中没有等于 $x$ 的值，那么 $f(x)$ 的值就是一个很大的数，我们用 $n + 1$ 表示这个数。

时间复杂度 $O(n)$，其中 $n$ 是数组的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minDominoRotations(self, tops: List[int], bottoms: List[int]) -> int:
        def f(x: int) -> int:
            cnt1 = cnt2 = 0
            for a, b in zip(tops, bottoms):
                if x not in (a, b):
                    return inf
                cnt1 += a == x
                cnt2 += b == x
            return len(tops) - max(cnt1, cnt2)

        ans = min(f(tops[0]), f(bottoms[0]))
        return -1 if ans == inf else ans
```

#### Java

```java
class Solution {
    private int n;
    private int[] tops;
    private int[] bottoms;

    public int minDominoRotations(int[] tops, int[] bottoms) {
        n = tops.length;
        this.tops = tops;
        this.bottoms = bottoms;
        int ans = Math.min(f(tops[0]), f(bottoms[0]));
        return ans > n ? -1 : ans;
    }

    private int f(int x) {
        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; ++i) {
            if (tops[i] != x && bottoms[i] != x) {
                return n + 1;
            }
            cnt1 += tops[i] == x ? 1 : 0;
            cnt2 += bottoms[i] == x ? 1 : 0;
        }
        return n - Math.max(cnt1, cnt2);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        auto f = [&](int x) {
            int cnt1 = 0, cnt2 = 0;
            for (int i = 0; i < n; ++i) {
                if (tops[i] != x && bottoms[i] != x) {
                    return n + 1;
                }
                cnt1 += tops[i] == x;
                cnt2 += bottoms[i] == x;
            }
            return n - max(cnt1, cnt2);
        };
        int ans = min(f(tops[0]), f(bottoms[0]));
        return ans > n ? -1 : ans;
    }
};
```

#### Go

```go
func minDominoRotations(tops []int, bottoms []int) int {
	n := len(tops)
	f := func(x int) int {
		cnt1, cnt2 := 0, 0
		for i, a := range tops {
			b := bottoms[i]
			if a != x && b != x {
				return n + 1
			}
			if a == x {
				cnt1++
			}
			if b == x {
				cnt2++
			}
		}
		return n - max(cnt1, cnt2)
	}
	ans := min(f(tops[0]), f(bottoms[0]))
	if ans > n {
		return -1
	}
	return ans
}
```

#### TypeScript

```ts
function minDominoRotations(tops: number[], bottoms: number[]): number {
    const n = tops.length;
    const f = (x: number): number => {
        let [cnt1, cnt2] = [0, 0];
        for (let i = 0; i < n; ++i) {
            if (tops[i] !== x && bottoms[i] !== x) {
                return n + 1;
            }
            cnt1 += tops[i] === x ? 1 : 0;
            cnt2 += bottoms[i] === x ? 1 : 0;
        }
        return n - Math.max(cnt1, cnt2);
    };
    const ans = Math.min(f(tops[0]), f(bottoms[0]));
    return ans > n ? -1 : ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn min_domino_rotations(tops: Vec<i32>, bottoms: Vec<i32>) -> i32 {
        let n = tops.len() as i32;
        let f = |x: i32| -> i32 {
            let mut cnt1 = 0;
            let mut cnt2 = 0;
            for i in 0..n as usize {
                if tops[i] != x && bottoms[i] != x {
                    return n + 1;
                }
                if tops[i] == x {
                    cnt1 += 1;
                }
                if bottoms[i] == x {
                    cnt2 += 1;
                }
            }
            n - cnt1.max(cnt2)
        };

        let ans = f(tops[0]).min(f(bottoms[0]));
        if ans > n { -1 } else { ans }
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1008. 前序遍历构造二叉搜索树](https://leetcode.cn/problems/construct-binary-search-tree-from-preorder-traversal){#1008}

{{< tabs "1008" >}}

{{% tab "python" %}}
```python
class Solution:
    def bstFromPreorder(self, preorder: List[int]) -> Optional[TreeNode]:
        def dfs(i: int, j: int) -> Optional[TreeNode]:
            if i > j:
                return None
            root = TreeNode(preorder[i])
            l, r = i + 1, j + 1
            while l < r:
                mid = (l + r) >> 1
                if preorder[mid] > preorder[i]:
                    r = mid
                else:
                    l = mid + 1
            root.left = dfs(i + 1, l - 1)
            root.right = dfs(l, j)
            return root

        return dfs(0, len(preorder) - 1)
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
    private int[] preorder;

    public TreeNode bstFromPreorder(int[] preorder) {
        this.preorder = preorder;
        return dfs(0, preorder.length - 1);
    }

    private TreeNode dfs(int i, int j) {
        if (i > j) {
            return null;
        }
        TreeNode root = new TreeNode(preorder[i]);
        int l = i + 1, r = j + 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (preorder[mid] > preorder[i]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        root.left = dfs(i + 1, l - 1);
        root.right = dfs(l, j);
        return root;
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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        auto dfs = [&](this auto&& dfs, int i, int j) -> TreeNode* {
            if (i > j) {
                return nullptr;
            }
            TreeNode* root = new TreeNode(preorder[i]);
            int l = i + 1, r = j + 1;
            while (l < r) {
                int mid = (l + r) >> 1;
                if (preorder[mid] > preorder[i]) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            root->left = dfs(i + 1, l - 1);
            root->right = dfs(l, j);
            return root;
        };
        return dfs(0, preorder.size() - 1);
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
func bstFromPreorder(preorder []int) *TreeNode {
	var dfs func(i, j int) *TreeNode
	dfs = func(i, j int) *TreeNode {
		if i > j {
			return nil
		}
		root := &TreeNode{Val: preorder[i]}
		l, r := i+1, j+1
		for l < r {
			mid := (l + r) >> 1
			if preorder[mid] > preorder[i] {
				r = mid
			} else {
				l = mid + 1
			}
		}
		root.Left = dfs(i+1, l-1)
		root.Right = dfs(l, j)
		return root
	}
	return dfs(0, len(preorder)-1)
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

function bstFromPreorder(preorder: number[]): TreeNode | null {
    const dfs = (i: number, j: number): TreeNode | null => {
        if (i > j) {
            return null;
        }
        const root = new TreeNode(preorder[i]);
        let [l, r] = [i + 1, j + 1];
        while (l < r) {
            const mid = (l + r) >> 1;
            if (preorder[mid] > preorder[i]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        root.left = dfs(i + 1, l - 1);
        root.right = dfs(l, j);
        return root;
    };
    return dfs(0, preorder.length - 1);
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
    pub fn bst_from_preorder(preorder: Vec<i32>) -> Option<Rc<RefCell<TreeNode>>> {
        fn dfs(preorder: &Vec<i32>, i: usize, j: usize) -> Option<Rc<RefCell<TreeNode>>> {
            if i > j {
                return None;
            }
            let root = Rc::new(RefCell::new(TreeNode::new(preorder[i])));
            let mut l = i + 1;
            let mut r = j + 1;
            while l < r {
                let mid = (l + r) >> 1;
                if preorder[mid] > preorder[i] {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            let mut root_ref = root.borrow_mut();
            root_ref.left = dfs(preorder, i + 1, l - 1);
            root_ref.right = dfs(preorder, l, j);
            Some(root.clone())
        }

        dfs(&preorder, 0, preorder.len() - 1)
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个整数数组，它表示BST(即 <strong>二叉搜索树</strong> )的 <strong>先</strong><strong>序遍历</strong> ，构造树并返回其根。</p>

<p><strong>保证</strong> 对于给定的测试用例，总是有可能找到具有给定需求的二叉搜索树。</p>

<p><strong>二叉搜索树</strong> 是一棵二叉树，其中每个节点，&nbsp;<code>Node.left</code>&nbsp;的任何后代的值 <strong>严格小于</strong> <code>Node.val</code>&nbsp;,&nbsp;<code>Node.right</code>&nbsp;的任何后代的值 <strong>严格大于</strong> <code>Node.val</code>。</p>

<p>二叉树的 <strong>前序遍历</strong> 首先显示节点的值，然后遍历<code>Node.left</code>，最后遍历<code>Node.right</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1000-1099/1008.Construct%20Binary%20Search%20Tree%20from%20Preorder%20Traversal/images/1266.png" /></p>

<pre>
<strong>输入：</strong>preorder = [8,5,1,7,10,12]
<strong>输出：</strong>[8,5,10,1,7,null,12]
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> preorder = [1,3]
<strong>输出:</strong> [1,null,3]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= preorder.length &lt;= 100</code></li>
	<li><code>1 &lt;= preorder[i]&nbsp;&lt;= 10^8</code></li>
	<li><code>preorder</code> 中的值 <strong>互不相同</strong></li>
</ul>

<p>&nbsp;</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS + 二分查找

我们设计一个函数 $\textit{dfs}(i, j)$，表示构造出从 $\textit{preorder}[i]$ 到 $\textit{preorder}[j]$ 这些节点构成的二叉搜索树。那么答案就是 $\textit{dfs}(0, n - 1)$。

在 $\textit{dfs}(i, j)$ 中，我们首先构造根节点，即 $\textit{preorder}[i]$。然后使用二分查找的方法找到第一个大于 $\textit{preorder}[i]$ 的节点的下标 $\textit{mid}$，将 $\textit{dfs}(i + 1, \textit{mid} - 1)$ 作为根节点的左子树，将 $\textit{dfs}(\textit{mid}, j)$ 作为根节点的右子树。

最后返回根节点即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $\textit{preorder}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def bstFromPreorder(self, preorder: List[int]) -> Optional[TreeNode]:
        def dfs(i: int, j: int) -> Optional[TreeNode]:
            if i > j:
                return None
            root = TreeNode(preorder[i])
            l, r = i + 1, j + 1
            while l < r:
                mid = (l + r) >> 1
                if preorder[mid] > preorder[i]:
                    r = mid
                else:
                    l = mid + 1
            root.left = dfs(i + 1, l - 1)
            root.right = dfs(l, j)
            return root

        return dfs(0, len(preorder) - 1)
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
    private int[] preorder;

    public TreeNode bstFromPreorder(int[] preorder) {
        this.preorder = preorder;
        return dfs(0, preorder.length - 1);
    }

    private TreeNode dfs(int i, int j) {
        if (i > j) {
            return null;
        }
        TreeNode root = new TreeNode(preorder[i]);
        int l = i + 1, r = j + 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (preorder[mid] > preorder[i]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        root.left = dfs(i + 1, l - 1);
        root.right = dfs(l, j);
        return root;
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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        auto dfs = [&](this auto&& dfs, int i, int j) -> TreeNode* {
            if (i > j) {
                return nullptr;
            }
            TreeNode* root = new TreeNode(preorder[i]);
            int l = i + 1, r = j + 1;
            while (l < r) {
                int mid = (l + r) >> 1;
                if (preorder[mid] > preorder[i]) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            root->left = dfs(i + 1, l - 1);
            root->right = dfs(l, j);
            return root;
        };
        return dfs(0, preorder.size() - 1);
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
func bstFromPreorder(preorder []int) *TreeNode {
	var dfs func(i, j int) *TreeNode
	dfs = func(i, j int) *TreeNode {
		if i > j {
			return nil
		}
		root := &TreeNode{Val: preorder[i]}
		l, r := i+1, j+1
		for l < r {
			mid := (l + r) >> 1
			if preorder[mid] > preorder[i] {
				r = mid
			} else {
				l = mid + 1
			}
		}
		root.Left = dfs(i+1, l-1)
		root.Right = dfs(l, j)
		return root
	}
	return dfs(0, len(preorder)-1)
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

function bstFromPreorder(preorder: number[]): TreeNode | null {
    const dfs = (i: number, j: number): TreeNode | null => {
        if (i > j) {
            return null;
        }
        const root = new TreeNode(preorder[i]);
        let [l, r] = [i + 1, j + 1];
        while (l < r) {
            const mid = (l + r) >> 1;
            if (preorder[mid] > preorder[i]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        root.left = dfs(i + 1, l - 1);
        root.right = dfs(l, j);
        return root;
    };
    return dfs(0, preorder.length - 1);
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
    pub fn bst_from_preorder(preorder: Vec<i32>) -> Option<Rc<RefCell<TreeNode>>> {
        fn dfs(preorder: &Vec<i32>, i: usize, j: usize) -> Option<Rc<RefCell<TreeNode>>> {
            if i > j {
                return None;
            }
            let root = Rc::new(RefCell::new(TreeNode::new(preorder[i])));
            let mut l = i + 1;
            let mut r = j + 1;
            while l < r {
                let mid = (l + r) >> 1;
                if preorder[mid] > preorder[i] {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            let mut root_ref = root.borrow_mut();
            root_ref.left = dfs(preorder, i + 1, l - 1);
            root_ref.right = dfs(preorder, l, j);
            Some(root.clone())
        }

        dfs(&preorder, 0, preorder.len() - 1)
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1009. 十进制整数的反码](https://leetcode.cn/problems/complement-of-base-10-integer){#1009}

{{< tabs "1009" >}}

{{% tab "python" %}}
```python
class Solution:
    def bitwiseComplement(self, n: int) -> int:
        if n == 0:
            return 1
        ans = i = 0
        while n:
            ans |= ((n & 1 ^ 1) << i)
            i += 1
            n >>= 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int bitwiseComplement(int n) {
        if (n == 0) {
            return 1;
        }
        int ans = 0, i = 0;
        while (n != 0) {
            ans |= (n & 1 ^ 1) << (i++);
            n >>= 1;
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
    int bitwiseComplement(int n) {
        if (n == 0) {
            return 1;
        }
        int ans = 0, i = 0;
        while (n != 0) {
            ans |= (n & 1 ^ 1) << (i++);
            n >>= 1;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func bitwiseComplement(n int) (ans int) {
	if n == 0 {
		return 1
	}
	for i := 0; n != 0; n >>= 1 {
		ans |= (n&1 ^ 1) << i
		i++
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function bitwiseComplement(n: number): number {
    if (n === 0) {
        return 1;
    }
    let ans = 0;
    for (let i = 0; n; n >>= 1) {
        ans |= ((n & 1) ^ 1) << i++;
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn bitwise_complement(mut n: i32) -> i32 {
        if n == 0 {
            return 1;
        }
        let mut ans = 0;
        let mut i = 0;
        while n != 0 {
            ans |= ((n & 1) ^ 1) << i;
            n >>= 1;
            i += 1;
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

<p>每个非负整数&nbsp;<code>N</code>&nbsp;都有其二进制表示。例如，&nbsp;<code>5</code>&nbsp;可以被表示为二进制&nbsp;<code>&quot;101&quot;</code>，<code>11</code> 可以用二进制&nbsp;<code>&quot;1011&quot;</code>&nbsp;表示，依此类推。注意，除&nbsp;<code>N = 0</code>&nbsp;外，任何二进制表示中都不含前导零。</p>

<p>二进制的反码表示是将每个&nbsp;<code>1</code>&nbsp;改为&nbsp;<code>0</code>&nbsp;且每个&nbsp;<code>0</code>&nbsp;变为&nbsp;<code>1</code>。例如，二进制数&nbsp;<code>&quot;101&quot;</code>&nbsp;的二进制反码为&nbsp;<code>&quot;010&quot;</code>。</p>

<p>给你一个十进制数&nbsp;<code>N</code>，请你返回其二进制表示的反码所对应的十进制整数。</p>

<p>&nbsp;</p>

<ol>
</ol>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>5
<strong>输出：</strong>2
<strong>解释：</strong>5 的二进制表示为 &quot;101&quot;，其二进制反码为 &quot;010&quot;，也就是十进制中的 2 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>7
<strong>输出：</strong>0
<strong>解释：</strong>7 的二进制表示为 &quot;111&quot;，其二进制反码为 &quot;000&quot;，也就是十进制中的 0 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>10
<strong>输出：</strong>5
<strong>解释：</strong>10 的二进制表示为 &quot;1010&quot;，其二进制反码为 &quot;0101&quot;，也就是十进制中的 5 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ol>
	<li><code>0 &lt;= N &lt; 10^9</code></li>
	<li>本题与 476：<a href="https://leetcode.cn/problems/number-complement/">https://leetcode.cn/problems/number-complement/</a> 相同</li>
</ol>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：位运算

我们首先判断 $n$ 是否为 $0$，如果是，则返回 $1$。

接着我们定义两个变量 $\textit{ans}$ 和 $i$，初始化为 $0$。然后我们遍历 $n$，在每次遍历中，我们将 $\textit{ans}$ 的第 $i$ 位设置为 $n$ 的第 $i$ 位取反，然后将 $i$ 加 $1$，并且$n$ 右移 $1$ 位。

最后返回 $\textit{ans}$ 即可。

时间复杂度 $O(\log n)$，其中 $n$ 为给定的十进制数。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def bitwiseComplement(self, n: int) -> int:
        if n == 0:
            return 1
        ans = i = 0
        while n:
            ans |= ((n & 1 ^ 1) << i)
            i += 1
            n >>= 1
        return ans
```

#### Java

```java
class Solution {
    public int bitwiseComplement(int n) {
        if (n == 0) {
            return 1;
        }
        int ans = 0, i = 0;
        while (n != 0) {
            ans |= (n & 1 ^ 1) << (i++);
            n >>= 1;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) {
            return 1;
        }
        int ans = 0, i = 0;
        while (n != 0) {
            ans |= (n & 1 ^ 1) << (i++);
            n >>= 1;
        }
        return ans;
    }
};
```

#### Go

```go
func bitwiseComplement(n int) (ans int) {
	if n == 0 {
		return 1
	}
	for i := 0; n != 0; n >>= 1 {
		ans |= (n&1 ^ 1) << i
		i++
	}
	return
}
```

#### TypeScript

```ts
function bitwiseComplement(n: number): number {
    if (n === 0) {
        return 1;
    }
    let ans = 0;
    for (let i = 0; n; n >>= 1) {
        ans |= ((n & 1) ^ 1) << i++;
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn bitwise_complement(mut n: i32) -> i32 {
        if n == 0 {
            return 1;
        }
        let mut ans = 0;
        let mut i = 0;
        while n != 0 {
            ans |= ((n & 1) ^ 1) << i;
            n >>= 1;
            i += 1;
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
