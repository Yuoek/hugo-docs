---
title: "1690_石子游戏 VII"
date: 2025-10-08T18:38:12+08:00
weight: 10
tags: [动态规划, 单调队列, 博弈, 双指针, 后缀数组, 哈希函数, 哈希表, 图, 堆（优先队列）, 字典树, 字符串, 并查集, 排序, 数学, 数据库, 数组, 滑动窗口, 滚动哈希, 队列]
---

{{< markmap >}}
### [1690_石子游戏 VII](#1690)
#### [数组](#1690)
#### [数学](#1690)
#### [动态规划](#1690)
#### [博弈](#1690)
### [1691_堆叠长方体的最大高度](#1691)
#### [数组](#1691)
#### [动态规划](#1691)
#### [排序](#1691)
### [1692_计算分配糖果的不同方式 🔒](#1692)
#### [动态规划](#1692)
### [1693_每天的领导和合伙人](#1693)
#### [数据库](#1693)
### [1694_重新格式化电话号码](#1694)
#### [字符串](#1694)
### [1695_删除子数组的最大得分](#1695)
#### [数组](#1695)
#### [哈希表](#1695)
#### [滑动窗口](#1695)
### [1696_跳跃游戏 VI](#1696)
#### [队列](#1696)
#### [数组](#1696)
#### [动态规划](#1696)
#### [单调队列](#1696)
#### [堆（优先队列）](#1696)
### [1697_检查边长度限制的路径是否存在](#1697)
#### [并查集](#1697)
#### [图](#1697)
#### [数组](#1697)
#### [双指针](#1697)
#### [排序](#1697)
### [1698_字符串的不同子字符串个数 🔒](#1698)
#### [字典树](#1698)
#### [字符串](#1698)
#### [后缀数组](#1698)
#### [哈希函数](#1698)
#### [滚动哈希](#1698)
### [1699_两人之间的通话次数 🔒](#1699)
#### [数据库](#1699)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1690_石子游戏 VII
___
#### 数组
___
#### 数学
___
#### 动态规划
___
#### 博弈
---
### 1691_堆叠长方体的最大高度
___
#### 数组
___
#### 动态规划
___
#### 排序
---
### 1692_计算分配糖果的不同方式 🔒
___
#### 动态规划
---
### 1693_每天的领导和合伙人
___
#### 数据库
---
### 1694_重新格式化电话号码
___
#### 字符串
---
### 1695_删除子数组的最大得分
___
#### 数组
___
#### 哈希表
___
#### 滑动窗口
---
### 1696_跳跃游戏 VI
___
#### 队列
___
#### 数组
___
#### 动态规划
___
#### 单调队列
___
#### 堆（优先队列）
---
### 1697_检查边长度限制的路径是否存在
___
#### 并查集
___
#### 图
___
#### 数组
___
#### 双指针
___
#### 排序
---
### 1698_字符串的不同子字符串个数 🔒
___
#### 字典树
___
#### 字符串
___
#### 后缀数组
___
#### 哈希函数
___
#### 滚动哈希
---
### 1699_两人之间的通话次数 🔒
___
#### 数据库
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 动态规划 | 单调队列 | 博弈 |
| 双指针 | 后缀数组 | 哈希函数 |
| 哈希表 | 图 | 堆（优先队列） |
| 字典树 | 字符串 | 并查集 |
| 排序 | 数学 | 数据库 |
| 数组 | 滑动窗口 | 滚动哈希 |
| 队列 |  |  |

# [1690. 石子游戏 VII](https://leetcode.cn/problems/stone-game-vii){#1690}

{{< tabs "1690" >}}

{{% tab "python" %}}
```python
class Solution:
    def stoneGameVII(self, stones: List[int]) -> int:
        s = list(accumulate(stones, initial=0))
        n = len(stones)
        f = [[0] * n for _ in range(n)]
        for i in range(n - 2, -1, -1):
            for j in range(i + 1, n):
                a = s[j + 1] - s[i + 1] - f[i + 1][j]
                b = s[j] - s[i] - f[i][j - 1]
                f[i][j] = max(a, b)
        return f[0][-1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int stoneGameVII(int[] stones) {
        int n = stones.length;
        int[] s = new int[n + 1];
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + stones[i];
        }
        int[][] f = new int[n][n];
        for (int i = n - 2; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                int a = s[j + 1] - s[i + 1] - f[i + 1][j];
                int b = s[j] - s[i] - f[i][j - 1];
                f[i][j] = Math.max(a, b);
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
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        int s[n + 1];
        memset(s, 0, sizeof(s));
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + stones[i];
        }
        int f[n][n];
        memset(f, 0, sizeof(f));
        for (int i = n - 2; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                int a = s[j + 1] - s[i + 1] - f[i + 1][j];
                int b = s[j] - s[i] - f[i][j - 1];
                f[i][j] = max(a, b);
            }
        }
        return f[0][n - 1];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func stoneGameVII(stones []int) int {
	n := len(stones)
	s := make([]int, n+1)
	for i, x := range stones {
		s[i+1] = s[i] + x
	}
	f := make([][]int, n)
	for i := range f {
		f[i] = make([]int, n)
	}
	for i := n - 2; i >= 0; i-- {
		for j := i + 1; j < n; j++ {
			f[i][j] = max(s[j+1]-s[i+1]-f[i+1][j], s[j]-s[i]-f[i][j-1])
		}
	}
	return f[0][n-1]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function stoneGameVII(stones: number[]): number {
    const n = stones.length;
    const s: number[] = Array(n + 1).fill(0);
    for (let i = 0; i < n; ++i) {
        s[i + 1] = s[i] + stones[i];
    }
    const f: number[][] = Array.from({ length: n }, () => Array(n).fill(0));
    for (let i = n - 2; ~i; --i) {
        for (let j = i + 1; j < n; ++j) {
            f[i][j] = Math.max(s[j + 1] - s[i + 1] - f[i + 1][j], s[j] - s[i] - f[i][j - 1]);
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

<p>石子游戏中，爱丽丝和鲍勃轮流进行自己的回合，<strong>爱丽丝先开始</strong> 。</p>

<p>有 <code>n</code> 块石子排成一排。每个玩家的回合中，可以从行中 <strong>移除</strong> 最左边的石头或最右边的石头，并获得与该行中剩余石头值之 <strong>和</strong> 相等的得分。当没有石头可移除时，得分较高者获胜。</p>

<p>鲍勃发现他总是输掉游戏（可怜的鲍勃，他总是输），所以他决定尽力 <strong>减小得分的差值</strong> 。爱丽丝的目标是最大限度地 <strong>扩大得分的差值</strong> 。</p>

<p>给你一个整数数组 <code>stones</code> ，其中 <code>stones[i]</code> 表示 <strong>从左边开始</strong> 的第 <code>i</code> 个石头的值，如果爱丽丝和鲍勃都 <strong>发挥出最佳水平</strong> ，请返回他们 <strong>得分的差值</strong> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>stones = [5,3,1,4,2]
<strong>输出：</strong>6
<strong>解释：</strong>
- 爱丽丝移除 2 ，得分 5 + 3 + 1 + 4 = 13 。游戏情况：爱丽丝 = 13 ，鲍勃 = 0 ，石子 = [5,3,1,4] 。
- 鲍勃移除 5 ，得分 3 + 1 + 4 = 8 。游戏情况：爱丽丝 = 13 ，鲍勃 = 8 ，石子 = [3,1,4] 。
- 爱丽丝移除 3 ，得分 1 + 4 = 5 。游戏情况：爱丽丝 = 18 ，鲍勃 = 8 ，石子 = [1,4] 。
- 鲍勃移除 1 ，得分 4 。游戏情况：爱丽丝 = 18 ，鲍勃 = 12 ，石子 = [4] 。
- 爱丽丝移除 4 ，得分 0 。游戏情况：爱丽丝 = 18 ，鲍勃 = 12 ，石子 = [] 。
得分的差值 18 - 12 = 6 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>stones = [7,90,5,1,100,10,10,2]
<strong>输出：</strong>122</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == stones.length</code></li>
	<li><code>2 <= n <= 1000</code></li>
	<li><code>1 <= stones[i] <= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

我们先预处理出前缀和数组 $s$，其中 $s[i]$ 表示前 $i$ 个石头的总和。

接下来，设计一个函数 $dfs(i, j)$，表示当剩下的石子为 $stones[i], stones[i + 1], \dots, stones[j]$ 时，先手与后手的得分差值。那么答案即为 $dfs(0, n - 1)$。

函数 $dfs(i, j)$ 的计算过程如下：

-   如果 $i \gt j$，说明当前没有石子，返回 $0$；
-   否则，先手有两种选择，分别是移除 $stones[i]$ 或 $stones[j]$，然后计算得分差值，即 $a = s[j + 1] - s[i + 1] - dfs(i + 1, j)$ 和 $b = s[j] - s[i] - dfs(i, j - 1)$，我们取两者中的较大值作为 $dfs(i, j)$ 的返回值。

过程中，我们使用记忆化搜索，即使用数组 $f$ 记录函数 $dfs(i, j)$ 的返回值，避免重复计算。

时间复杂度 $O(n^2)$，空间复杂度 $O(n^2)$。其中 $n$ 为石子的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def stoneGameVII(self, stones: List[int]) -> int:
        @cache
        def dfs(i: int, j: int) -> int:
            if i > j:
                return 0
            a = s[j + 1] - s[i + 1] - dfs(i + 1, j)
            b = s[j] - s[i] - dfs(i, j - 1)
            return max(a, b)

        s = list(accumulate(stones, initial=0))
        ans = dfs(0, len(stones) - 1)
        dfs.cache_clear()
        return ans
```

#### Java

```java
class Solution {
    private int[] s;
    private Integer[][] f;

    public int stoneGameVII(int[] stones) {
        int n = stones.length;
        s = new int[n + 1];
        f = new Integer[n][n];
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + stones[i];
        }
        return dfs(0, n - 1);
    }

    private int dfs(int i, int j) {
        if (i > j) {
            return 0;
        }
        if (f[i][j] != null) {
            return f[i][j];
        }
        int a = s[j + 1] - s[i + 1] - dfs(i + 1, j);
        int b = s[j] - s[i] - dfs(i, j - 1);
        return f[i][j] = Math.max(a, b);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        int f[n][n];
        memset(f, 0, sizeof f);
        int s[n + 1];
        s[0] = 0;
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + stones[i];
        }
        function<int(int, int)> dfs = [&](int i, int j) {
            if (i > j) {
                return 0;
            }
            if (f[i][j]) {
                return f[i][j];
            }
            int a = s[j + 1] - s[i + 1] - dfs(i + 1, j);
            int b = s[j] - s[i] - dfs(i, j - 1);
            return f[i][j] = max(a, b);
        };
        return dfs(0, n - 1);
    }
};
```

#### Go

```go
func stoneGameVII(stones []int) int {
	n := len(stones)
	s := make([]int, n+1)
	f := make([][]int, n)
	for i, x := range stones {
		s[i+1] = s[i] + x
		f[i] = make([]int, n)
	}
	var dfs func(int, int) int
	dfs = func(i, j int) int {
		if i > j {
			return 0
		}
		if f[i][j] != 0 {
			return f[i][j]
		}
		a := s[j+1] - s[i+1] - dfs(i+1, j)
		b := s[j] - s[i] - dfs(i, j-1)
		f[i][j] = max(a, b)
		return f[i][j]
	}
	return dfs(0, n-1)
}
```

#### TypeScript

```ts
function stoneGameVII(stones: number[]): number {
    const n = stones.length;
    const s: number[] = Array(n + 1).fill(0);
    for (let i = 0; i < n; ++i) {
        s[i + 1] = s[i] + stones[i];
    }
    const f: number[][] = Array.from({ length: n }, () => Array(n).fill(0));
    const dfs = (i: number, j: number): number => {
        if (i > j) {
            return 0;
        }
        if (f[i][j]) {
            return f[i][j];
        }
        const a = s[j + 1] - s[i + 1] - dfs(i + 1, j);
        const b = s[j] - s[i] - dfs(i, j - 1);
        return (f[i][j] = Math.max(a, b));
    };
    return dfs(0, n - 1);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：动态规划

我们可以将方法一中的记忆化搜索转换为动态规划，定义 $f[i][j]$ 表示当剩下的石子为 $stones[i], stones[i + 1], \dots, stones[j]$ 时，先手与后手的得分差值。那么答案即为 $f[0][n - 1]$。

状态转移方程如下：

$$
f[i][j] = \max(s[j + 1] - s[i + 1] - f[i + 1][j], s[j] - s[i] - f[i][j - 1])
$$

在计算 $f[i][j]$ 时，我们需要保证 $f[i + 1][j]$ 和 $f[i][j - 1]$ 已经被计算出来，因此我们需要按照从大到小的顺序枚举 $i$，从小到大的顺序枚举 $j$。

最后，答案即为 $f[0][n - 1]$。

时间复杂度 $O(n^2)$，空间复杂度 $O(n^2)$。其中 $n$ 为石子的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def stoneGameVII(self, stones: List[int]) -> int:
        s = list(accumulate(stones, initial=0))
        n = len(stones)
        f = [[0] * n for _ in range(n)]
        for i in range(n - 2, -1, -1):
            for j in range(i + 1, n):
                a = s[j + 1] - s[i + 1] - f[i + 1][j]
                b = s[j] - s[i] - f[i][j - 1]
                f[i][j] = max(a, b)
        return f[0][-1]
```

#### Java

```java
class Solution {
    public int stoneGameVII(int[] stones) {
        int n = stones.length;
        int[] s = new int[n + 1];
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + stones[i];
        }
        int[][] f = new int[n][n];
        for (int i = n - 2; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                int a = s[j + 1] - s[i + 1] - f[i + 1][j];
                int b = s[j] - s[i] - f[i][j - 1];
                f[i][j] = Math.max(a, b);
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
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        int s[n + 1];
        memset(s, 0, sizeof(s));
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + stones[i];
        }
        int f[n][n];
        memset(f, 0, sizeof(f));
        for (int i = n - 2; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                int a = s[j + 1] - s[i + 1] - f[i + 1][j];
                int b = s[j] - s[i] - f[i][j - 1];
                f[i][j] = max(a, b);
            }
        }
        return f[0][n - 1];
    }
};
```

#### Go

```go
func stoneGameVII(stones []int) int {
	n := len(stones)
	s := make([]int, n+1)
	for i, x := range stones {
		s[i+1] = s[i] + x
	}
	f := make([][]int, n)
	for i := range f {
		f[i] = make([]int, n)
	}
	for i := n - 2; i >= 0; i-- {
		for j := i + 1; j < n; j++ {
			f[i][j] = max(s[j+1]-s[i+1]-f[i+1][j], s[j]-s[i]-f[i][j-1])
		}
	}
	return f[0][n-1]
}
```

#### TypeScript

```ts
function stoneGameVII(stones: number[]): number {
    const n = stones.length;
    const s: number[] = Array(n + 1).fill(0);
    for (let i = 0; i < n; ++i) {
        s[i + 1] = s[i] + stones[i];
    }
    const f: number[][] = Array.from({ length: n }, () => Array(n).fill(0));
    for (let i = n - 2; ~i; --i) {
        for (let j = i + 1; j < n; ++j) {
            f[i][j] = Math.max(s[j + 1] - s[i + 1] - f[i + 1][j], s[j] - s[i] - f[i][j - 1]);
        }
    }
    return f[0][n - 1];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1691. 堆叠长方体的最大高度](https://leetcode.cn/problems/maximum-height-by-stacking-cuboids){#1691}

{{< tabs "1691" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxHeight(self, cuboids: List[List[int]]) -> int:
        for c in cuboids:
            c.sort()
        cuboids.sort()
        n = len(cuboids)
        f = [0] * n
        for i in range(n):
            for j in range(i):
                if cuboids[j][1] <= cuboids[i][1] and cuboids[j][2] <= cuboids[i][2]:
                    f[i] = max(f[i], f[j])
            f[i] += cuboids[i][2]
        return max(f)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxHeight(int[][] cuboids) {
        for (var c : cuboids) {
            Arrays.sort(c);
        }
        Arrays.sort(cuboids,
            (a, b) -> a[0] == b[0] ? (a[1] == b[1] ? a[2] - b[2] : a[1] - b[1]) : a[0] - b[0]);
        int n = cuboids.length;
        int[] f = new int[n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (cuboids[j][1] <= cuboids[i][1] && cuboids[j][2] <= cuboids[i][2]) {
                    f[i] = Math.max(f[i], f[j]);
                }
            }
            f[i] += cuboids[i][2];
        }
        return Arrays.stream(f).max().getAsInt();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        for (auto& c : cuboids) {
            sort(c.begin(), c.end());
        }
        sort(cuboids.begin(), cuboids.end());
        int n = cuboids.size();
        vector<int> f(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (cuboids[j][1] <= cuboids[i][1] && cuboids[j][2] <= cuboids[i][2]) {
                    f[i] = max(f[i], f[j]);
                }
            }
            f[i] += cuboids[i][2];
        }
        return *max_element(f.begin(), f.end());
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxHeight(cuboids [][]int) int {
	for _, c := range cuboids {
		sort.Ints(c)
	}
	sort.Slice(cuboids, func(i, j int) bool {
		a, b := cuboids[i], cuboids[j]
		return a[0] < b[0] || a[0] == b[0] && (a[1] < b[1] || a[1] == b[1] && a[2] < b[2])
	})
	n := len(cuboids)
	f := make([]int, n)
	for i := range f {
		for j := 0; j < i; j++ {
			if cuboids[j][1] <= cuboids[i][1] && cuboids[j][2] <= cuboids[i][2] {
				f[i] = max(f[i], f[j])
			}
		}
		f[i] += cuboids[i][2]
	}
	return slices.Max(f)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxHeight(cuboids: number[][]): number {
    for (const c of cuboids) {
        c.sort((a, b) => a - b);
    }
    cuboids.sort((a, b) => {
        if (a[0] !== b[0]) {
            return a[0] - b[0];
        }
        if (a[1] !== b[1]) {
            return a[1] - b[1];
        }
        return a[2] - b[2];
    });
    const n = cuboids.length;
    const f = Array(n).fill(0);
    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < i; ++j) {
            const ok = cuboids[j][1] <= cuboids[i][1] && cuboids[j][2] <= cuboids[i][2];
            if (ok) f[i] = Math.max(f[i], f[j]);
        }
        f[i] += cuboids[i][2];
    }
    return Math.max(...f);
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[][]} cuboids
 * @return {number}
 */
var maxHeight = function (cuboids) {
    for (const c of cuboids) {
        c.sort((a, b) => a - b);
    }
    cuboids.sort((a, b) => {
        if (a[0] !== b[0]) {
            return a[0] - b[0];
        }
        if (a[1] !== b[1]) {
            return a[1] - b[1];
        }
        return a[2] - b[2];
    });
    const n = cuboids.length;
    const f = Array(n).fill(0);
    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < i; ++j) {
            const ok = cuboids[j][1] <= cuboids[i][1] && cuboids[j][2] <= cuboids[i][2];
            if (ok) f[i] = Math.max(f[i], f[j]);
        }
        f[i] += cuboids[i][2];
    }
    return Math.max(...f);
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你 <code>n</code> 个长方体 <code>cuboids</code> ，其中第 <code>i</code> 个长方体的长宽高表示为 <code>cuboids[i] = [width<sub>i</sub>, length<sub>i</sub>, height<sub>i</sub>]</code>（<strong>下标从 0 开始</strong>）。请你从 <code>cuboids</code> 选出一个 <strong>子集</strong> ，并将它们堆叠起来。</p>

<p>如果 <code>width<sub>i</sub> <= width<sub>j</sub></code> 且 <code>length<sub>i</sub> <= length<sub>j</sub></code> 且 <code>height<sub>i</sub> <= height<sub>j</sub></code> ，你就可以将长方体 <code>i</code> 堆叠在长方体 <code>j</code> 上。你可以通过旋转把长方体的长宽高重新排列，以将它放在另一个长方体上。</p>

<p>返回 <strong>堆叠长方体</strong> <code>cuboids</code> 可以得到的 <strong>最大高度</strong> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1600-1699/1691.Maximum%20Height%20by%20Stacking%20Cuboids/images/image.jpg" style="width: 420px; height: 299px;" /></strong></p>

<pre>
<strong>输入：</strong>cuboids = [[50,45,20],[95,37,53],[45,23,12]]
<strong>输出：</strong>190
<strong>解释：</strong>
第 1 个长方体放在底部，53x37 的一面朝下，高度为 95 。
第 0 个长方体放在中间，45x20 的一面朝下，高度为 50 。
第 2 个长方体放在上面，23x12 的一面朝下，高度为 45 。
总高度是 95 + 50 + 45 = 190 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>cuboids = [[38,25,45],[76,35,3]]
<strong>输出：</strong>76
<strong>解释：</strong>
无法将任何长方体放在另一个上面。
选择第 1 个长方体然后旋转它，使 35x3 的一面朝下，其高度为 76 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>cuboids = [[7,11,17],[7,17,11],[11,7,17],[11,17,7],[17,7,11],[17,11,7]]
<strong>输出：</strong>102
<strong>解释：</strong>
重新排列长方体后，可以看到所有长方体的尺寸都相同。
你可以把 11x7 的一面朝下，这样它们的高度就是 17 。
堆叠长方体的最大高度为 6 * 17 = 102 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == cuboids.length</code></li>
	<li><code>1 <= n <= 100</code></li>
	<li><code>1 <= width<sub>i</sub>, length<sub>i</sub>, height<sub>i</sub> <= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 动态规划

根据题目描述，长方体 $j$ 能够放在长方体 $i$ 上，当且仅当长方体 $j$ 的“长、宽、高”分别小于等于长方体 $i$ 的“长、宽、高”。

本题允许我们旋转长方体，意味着我们可以选择长方体的任意一边作为长方体的“高”。对于任意一种合法的堆叠，如果我们把里面每个长方体都旋转至“长 <= 宽 <= 高”，堆叠仍然是合法的，并且能够保证堆叠的高度最大化。

因此，我们可以把所有长方体的边长进行排序，使得每个长方体满足“长 <= 宽 <= 高”。然后将每个长方体升序排列。

接下来，我们可以使用动态规划的方法求解本题。

我们定义 $f[i]$ 表示以长方体 $i$ 为最底部长方体时的最大高度。我们可以枚举每个长方体 $i$ 的上方的长方体 $j$，其中 $0 \leq j < i$。如果 $j$ 可以放在 $i$ 的上方，那么我们可以得到状态转移方程：

$$
f[i] = \max_{0 \leq j < i} \{f[j] + h[i]\}
$$

其中 $h[i]$ 表示长方体 $i$ 的高度。

最终的答案即为 $f[i]$ 的最大值。

时间复杂度 $O(n^2)$，空间复杂度 $O(n)$。其中 $n$ 为长方体的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxHeight(self, cuboids: List[List[int]]) -> int:
        for c in cuboids:
            c.sort()
        cuboids.sort()
        n = len(cuboids)
        f = [0] * n
        for i in range(n):
            for j in range(i):
                if cuboids[j][1] <= cuboids[i][1] and cuboids[j][2] <= cuboids[i][2]:
                    f[i] = max(f[i], f[j])
            f[i] += cuboids[i][2]
        return max(f)
```

#### Java

```java
class Solution {
    public int maxHeight(int[][] cuboids) {
        for (var c : cuboids) {
            Arrays.sort(c);
        }
        Arrays.sort(cuboids,
            (a, b) -> a[0] == b[0] ? (a[1] == b[1] ? a[2] - b[2] : a[1] - b[1]) : a[0] - b[0]);
        int n = cuboids.length;
        int[] f = new int[n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (cuboids[j][1] <= cuboids[i][1] && cuboids[j][2] <= cuboids[i][2]) {
                    f[i] = Math.max(f[i], f[j]);
                }
            }
            f[i] += cuboids[i][2];
        }
        return Arrays.stream(f).max().getAsInt();
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        for (auto& c : cuboids) {
            sort(c.begin(), c.end());
        }
        sort(cuboids.begin(), cuboids.end());
        int n = cuboids.size();
        vector<int> f(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (cuboids[j][1] <= cuboids[i][1] && cuboids[j][2] <= cuboids[i][2]) {
                    f[i] = max(f[i], f[j]);
                }
            }
            f[i] += cuboids[i][2];
        }
        return *max_element(f.begin(), f.end());
    }
};
```

#### Go

```go
func maxHeight(cuboids [][]int) int {
	for _, c := range cuboids {
		sort.Ints(c)
	}
	sort.Slice(cuboids, func(i, j int) bool {
		a, b := cuboids[i], cuboids[j]
		return a[0] < b[0] || a[0] == b[0] && (a[1] < b[1] || a[1] == b[1] && a[2] < b[2])
	})
	n := len(cuboids)
	f := make([]int, n)
	for i := range f {
		for j := 0; j < i; j++ {
			if cuboids[j][1] <= cuboids[i][1] && cuboids[j][2] <= cuboids[i][2] {
				f[i] = max(f[i], f[j])
			}
		}
		f[i] += cuboids[i][2]
	}
	return slices.Max(f)
}
```

#### TypeScript

```ts
function maxHeight(cuboids: number[][]): number {
    for (const c of cuboids) {
        c.sort((a, b) => a - b);
    }
    cuboids.sort((a, b) => {
        if (a[0] !== b[0]) {
            return a[0] - b[0];
        }
        if (a[1] !== b[1]) {
            return a[1] - b[1];
        }
        return a[2] - b[2];
    });
    const n = cuboids.length;
    const f = Array(n).fill(0);
    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < i; ++j) {
            const ok = cuboids[j][1] <= cuboids[i][1] && cuboids[j][2] <= cuboids[i][2];
            if (ok) f[i] = Math.max(f[i], f[j]);
        }
        f[i] += cuboids[i][2];
    }
    return Math.max(...f);
}
```

#### JavaScript

```js
/**
 * @param {number[][]} cuboids
 * @return {number}
 */
var maxHeight = function (cuboids) {
    for (const c of cuboids) {
        c.sort((a, b) => a - b);
    }
    cuboids.sort((a, b) => {
        if (a[0] !== b[0]) {
            return a[0] - b[0];
        }
        if (a[1] !== b[1]) {
            return a[1] - b[1];
        }
        return a[2] - b[2];
    });
    const n = cuboids.length;
    const f = Array(n).fill(0);
    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < i; ++j) {
            const ok = cuboids[j][1] <= cuboids[i][1] && cuboids[j][2] <= cuboids[i][2];
            if (ok) f[i] = Math.max(f[i], f[j]);
        }
        f[i] += cuboids[i][2];
    }
    return Math.max(...f);
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1692. 计算分配糖果的不同方式 🔒](https://leetcode.cn/problems/count-ways-to-distribute-candies){#1692}

{{< tabs "1692" >}}

{{% tab "python" %}}
```python
class Solution:
    def waysToDistribute(self, n: int, k: int) -> int:
        mod = 10**9 + 7
        f = [[0] * (k + 1) for _ in range(n + 1)]
        f[0][0] = 1
        for i in range(1, n + 1):
            for j in range(1, k + 1):
                f[i][j] = (f[i - 1][j] * j + f[i - 1][j - 1]) % mod
        return f[n][k]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int waysToDistribute(int n, int k) {
        final int mod = (int) 1e9 + 7;
        int[][] f = new int[n + 1][k + 1];
        f[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                f[i][j] = (int) ((long) f[i - 1][j] * j % mod + f[i - 1][j - 1]) % mod;
            }
        }
        return f[n][k];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int waysToDistribute(int n, int k) {
        const int mod = 1e9 + 7;
        int f[n + 1][k + 1];
        memset(f, 0, sizeof(f));
        f[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                f[i][j] = (1LL * f[i - 1][j] * j + f[i - 1][j - 1]) % mod;
            }
        }
        return f[n][k];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func waysToDistribute(n int, k int) int {
	f := make([][]int, n+1)
	for i := range f {
		f[i] = make([]int, k+1)
	}
	f[0][0] = 1
	const mod = 1e9 + 7
	for i := 1; i <= n; i++ {
		for j := 1; j <= k; j++ {
			f[i][j] = (f[i-1][j]*j + f[i-1][j-1]) % mod
		}
	}
	return f[n][k]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function waysToDistribute(n: number, k: number): number {
    const mod = 10 ** 9 + 7;
    const f: number[][] = Array.from({ length: n + 1 }, () =>
        Array.from({ length: k + 1 }, () => 0),
    );
    f[0][0] = 1;
    for (let i = 1; i <= n; ++i) {
        for (let j = 1; j <= k; ++j) {
            f[i][j] = (f[i - 1][j] * j + f[i - 1][j - 1]) % mod;
        }
    }
    return f[n][k];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>现有 <code>n</code> 颗 <strong>不同</strong> 糖果（分别标记为 <code>1</code> 到 <code>n</code> ）和 <code>k</code> 个相同的手袋。请把糖果分配到各个手袋中并保证每个手袋里至少有一颗糖果。</p>

<p>不考虑手袋和糖果的摆放顺序，会有多种不同的分配方式。如果某种分配方式中其中一个手袋里的糖果与另一种分配方式中所有手袋里的糖果都不相同，则认为这两种分配方式不同。</p>

<p>例如，<code>(1), (2,3)</code>&nbsp;与<code>(2), (1,3)</code>的分配方式是不同的，因为第一种分配方式中手袋(2,3)里的糖果2和3，在第二种分配方式中被分配到了手袋<code>(2)</code>和<code>(1,3)</code>&nbsp;中。</p>

<p>已知整数&nbsp;<code>n</code>&nbsp;和&nbsp;<code>k</code>, 请返回分配糖果的不同方式。返回的答案如果数值太大，请取<code>10<sup>9</sup> + 7</code>的模，并返回。</p>

<p>&nbsp;</p>

<p><strong>示例&nbsp;1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1600-1699/1692.Count%20Ways%20to%20Distribute%20Candies/images/candies-1.png" style="height: 248px; width: 600px;" /></p>

<pre>
<strong>输入：</strong>n = 3, k = 2
<strong>输出：</strong>3
<strong>解释：</strong>把糖果 3 分配到 2 个手袋中的一个，共有 3 种方式:
(1), (2,3)
(1,2), (3)
(1,3), (2)
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 4, k = 2
<strong>输出：</strong>7
<strong>解释：</strong>把糖果 4 分配到 2 个手袋中的一个，共有 7 种方式:
(1), (2,3,4)
(1,2), (3,4)
(1,3), (2,4)
(1,4), (2,3)
(1,2,3), (4)
(1,2,4), (3)
(1,3,4), (2)
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 20, k = 5
<strong>输出：</strong>206085257
<strong>解释：</strong>把 20 颗糖果分配到 5 个手袋种，共有 1881780996 种方式。1881780996 取 10<sup>9</sup> + 7的模，等于 206085257。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= n &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i][j]$ 表示将 $i$ 个糖果分配给 $j$ 个手袋的不同分配方式的数量。初始时 $f[0][0]=1$，答案为 $f[n][k]$。

我们考虑第 $i$ 个糖果如何分配，如果第 $i$ 个糖果分配给一个新的手袋，那么 $f[i][j]=f[i-1][j-1]$；如果第 $i$ 个糖果分配给一个已有的手袋，那么 $f[i][j]=f[i-1][j]\times j$。因此，状态转移方程为：

$$
f[i][j]=f[i-1][j-1]+f[i-1][j]\times j
$$

最终的答案为 $f[n][k]$。

时间复杂度 $O(n \times k)$，空间复杂度 $O(n \times k)$。其中 $n$ 和 $k$ 分别为糖果的数量和手袋的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def waysToDistribute(self, n: int, k: int) -> int:
        mod = 10**9 + 7
        f = [[0] * (k + 1) for _ in range(n + 1)]
        f[0][0] = 1
        for i in range(1, n + 1):
            for j in range(1, k + 1):
                f[i][j] = (f[i - 1][j] * j + f[i - 1][j - 1]) % mod
        return f[n][k]
```

#### Java

```java
class Solution {
    public int waysToDistribute(int n, int k) {
        final int mod = (int) 1e9 + 7;
        int[][] f = new int[n + 1][k + 1];
        f[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                f[i][j] = (int) ((long) f[i - 1][j] * j % mod + f[i - 1][j - 1]) % mod;
            }
        }
        return f[n][k];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int waysToDistribute(int n, int k) {
        const int mod = 1e9 + 7;
        int f[n + 1][k + 1];
        memset(f, 0, sizeof(f));
        f[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                f[i][j] = (1LL * f[i - 1][j] * j + f[i - 1][j - 1]) % mod;
            }
        }
        return f[n][k];
    }
};
```

#### Go

```go
func waysToDistribute(n int, k int) int {
	f := make([][]int, n+1)
	for i := range f {
		f[i] = make([]int, k+1)
	}
	f[0][0] = 1
	const mod = 1e9 + 7
	for i := 1; i <= n; i++ {
		for j := 1; j <= k; j++ {
			f[i][j] = (f[i-1][j]*j + f[i-1][j-1]) % mod
		}
	}
	return f[n][k]
}
```

#### TypeScript

```ts
function waysToDistribute(n: number, k: number): number {
    const mod = 10 ** 9 + 7;
    const f: number[][] = Array.from({ length: n + 1 }, () =>
        Array.from({ length: k + 1 }, () => 0),
    );
    f[0][0] = 1;
    for (let i = 1; i <= n; ++i) {
        for (let j = 1; j <= k; ++j) {
            f[i][j] = (f[i - 1][j] * j + f[i - 1][j - 1]) % mod;
        }
    }
    return f[n][k];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1693. 每天的领导和合伙人](https://leetcode.cn/problems/daily-leads-and-partners){#1693}

{{< tabs "1693" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT
    date_id,
    make_name,
    COUNT(DISTINCT lead_id) AS unique_leads,
    COUNT(DISTINCT partner_id) AS unique_partners
FROM DailySales
GROUP BY 1, 2;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code>DailySales</code></p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| date_id     | date    |
| make_name   | varchar |
| lead_id     | int     |
| partner_id  | int     |
+-------------+---------+
该表没有主键(具有唯一值的列)。它可能包含重复项。
该表包含日期、产品的名称，以及售给的领导和合伙人的编号。
名称只包含小写英文字母。</pre>

<p>&nbsp;</p>

<p>对于每一个&nbsp;<code>date_id</code>&nbsp;和&nbsp;<code>make_name</code>，找出&nbsp;<strong>不同&nbsp;</strong>的&nbsp;<code>lead_id</code>&nbsp;以及&nbsp;<strong>不同&nbsp;</strong>的&nbsp;<code>partner_id</code>&nbsp;的数量。</p>

<p>按 <strong>任意顺序</strong> 返回结果表。</p>

<p>返回结果格式如下示例所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入：</strong>
DailySales 表：
+-----------+-----------+---------+------------+
| date_id   | make_name | lead_id | partner_id |
+-----------+-----------+---------+------------+
| 2020-12-8 | toyota    | 0       | 1          |
| 2020-12-8 | toyota    | 1       | 0          |
| 2020-12-8 | toyota    | 1       | 2          |
| 2020-12-7 | toyota    | 0       | 2          |
| 2020-12-7 | toyota    | 0       | 1          |
| 2020-12-8 | honda     | 1       | 2          |
| 2020-12-8 | honda     | 2       | 1          |
| 2020-12-7 | honda     | 0       | 1          |
| 2020-12-7 | honda     | 1       | 2          |
| 2020-12-7 | honda     | 2       | 1          |
+-----------+-----------+---------+------------+
<strong>输出：</strong>
+-----------+-----------+--------------+-----------------+
| date_id   | make_name | unique_leads | unique_partners |
+-----------+-----------+--------------+-----------------+
| 2020-12-8 | toyota    | 2            | 3               |
| 2020-12-7 | toyota    | 1            | 2               |
| 2020-12-8 | honda     | 2            | 2               |
| 2020-12-7 | honda     | 3            | 2               |
+-----------+-----------+--------------+-----------------+
<strong>解释：</strong>
在 2020-12-8，丰田（toyota）有领导者 = [0, 1] 和合伙人 = [0, 1, 2] ，同时本田（honda）有领导者 = [1, 2] 和合伙人 = [1, 2]。
在 2020-12-7，丰田（toyota）有领导者 = [0] 和合伙人 = [1, 2] ，同时本田（honda）有领导者 = [0, 1, 2] 和合伙人 = [1, 2]。</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：分组统计

我们可以使用 `GROUP BY` 语句，按照 `date_id` 和 `make_name` 字段进行分组，然后使用 `COUNT(DISTINCT)` 函数，统计 `lead_id` 和 `partner_id` 的不同值的数量。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT
    date_id,
    make_name,
    COUNT(DISTINCT lead_id) AS unique_leads,
    COUNT(DISTINCT partner_id) AS unique_partners
FROM DailySales
GROUP BY 1, 2;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1694. 重新格式化电话号码](https://leetcode.cn/problems/reformat-phone-number){#1694}

{{< tabs "1694" >}}

{{% tab "python" %}}
```python
class Solution:
    def reformatNumber(self, number: str) -> str:
        number = number.replace("-", "").replace(" ", "")
        n = len(number)
        ans = [number[i * 3 : i * 3 + 3] for i in range(n // 3)]
        if n % 3 == 1:
            ans[-1] = ans[-1][:2]
            ans.append(number[-2:])
        elif n % 3 == 2:
            ans.append(number[-2:])
        return "-".join(ans)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String reformatNumber(String number) {
        number = number.replace("-", "").replace(" ", "");
        int n = number.length();
        List<String> ans = new ArrayList<>();
        for (int i = 0; i < n / 3; ++i) {
            ans.add(number.substring(i * 3, i * 3 + 3));
        }
        if (n % 3 == 1) {
            ans.set(ans.size() - 1, ans.get(ans.size() - 1).substring(0, 2));
            ans.add(number.substring(n - 2));
        } else if (n % 3 == 2) {
            ans.add(number.substring(n - 2));
        }
        return String.join("-", ans);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string reformatNumber(string number) {
        string s;
        for (char c : number) {
            if (c != ' ' && c != '-') {
                s.push_back(c);
            }
        }
        int n = s.size();
        vector<string> res;
        for (int i = 0; i < n / 3; ++i) {
            res.push_back(s.substr(i * 3, 3));
        }
        if (n % 3 == 1) {
            res.back() = res.back().substr(0, 2);
            res.push_back(s.substr(n - 2));
        } else if (n % 3 == 2) {
            res.push_back(s.substr(n - 2));
        }
        string ans;
        for (auto& v : res) {
            ans += v;
            ans += "-";
        }
        ans.pop_back();
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func reformatNumber(number string) string {
	number = strings.ReplaceAll(number, " ", "")
	number = strings.ReplaceAll(number, "-", "")
	n := len(number)
	ans := []string{}
	for i := 0; i < n/3; i++ {
		ans = append(ans, number[i*3:i*3+3])
	}
	if n%3 == 1 {
		ans[len(ans)-1] = ans[len(ans)-1][:2]
		ans = append(ans, number[n-2:])
	} else if n%3 == 2 {
		ans = append(ans, number[n-2:])
	}
	return strings.Join(ans, "-")
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function reformatNumber(number: string): string {
    const cs = [...number].filter(c => c !== ' ' && c !== '-');
    const n = cs.length;
    return cs
        .map((v, i) => {
            if (((i + 1) % 3 === 0 && i < n - 2) || (n % 3 === 1 && n - 3 === i)) {
                return v + '-';
            }
            return v;
        })
        .join('');
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn reformat_number(number: String) -> String {
        let cs: Vec<char> = number.chars().filter(|&c| c != ' ' && c != '-').collect();
        let n = cs.len();
        cs.iter()
            .enumerate()
            .map(|(i, c)| {
                if ((i + 1) % 3 == 0 && i < n - 2) || (n % 3 == 1 && i == n - 3) {
                    return c.to_string() + &"-";
                }
                c.to_string()
            })
            .collect()
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串形式的电话号码 <code>number</code> 。<code>number</code> 由数字、空格 <code>' '</code>、和破折号 <code>'-'</code> 组成。</p>

<p>请你按下述方式重新格式化电话号码。</p>

<ul>
	<li>首先，<strong>删除</strong> 所有的空格和破折号。</li>
	<li>其次，将数组从左到右 <strong>每 3 个一组</strong> 分块，<strong>直到 </strong>剩下 4 个或更少数字。剩下的数字将按下述规定再分块：
	<ul>
		<li>2 个数字：单个含 2 个数字的块。</li>
		<li>3 个数字：单个含 3 个数字的块。</li>
		<li>4 个数字：两个分别含 2 个数字的块。</li>
	</ul>
	</li>
</ul>

<p>最后用破折号将这些块连接起来。注意，重新格式化过程中 <strong>不应该</strong> 生成仅含 1 个数字的块，并且 <strong>最多</strong> 生成两个含 2 个数字的块。</p>

<p>返回格式化后的电话号码。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>number = "1-23-45 6"
<strong>输出：</strong>"123-456"
<strong>解释：</strong>数字是 "123456"
步骤 1：共有超过 4 个数字，所以先取 3 个数字分为一组。第 1 个块是 "123" 。
步骤 2：剩下 3 个数字，将它们放入单个含 3 个数字的块。第 2 个块是 "456" 。
连接这些块后得到 "123-456" 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>number = "123 4-567"
<strong>输出：</strong>"123-45-67"
<strong>解释：</strong>数字是 "1234567".
步骤 1：共有超过 4 个数字，所以先取 3 个数字分为一组。第 1 个块是 "123" 。
步骤 2：剩下 4 个数字，所以将它们分成两个含 2 个数字的块。这 2 块分别是 "45" 和 "67" 。
连接这些块后得到 "123-45-67" 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>number = "123 4-5678"
<strong>输出：</strong>"123-456-78"
<strong>解释：</strong>数字是 "12345678" 。
步骤 1：第 1 个块 "123" 。
步骤 2：第 2 个块 "456" 。
步骤 3：剩下 2 个数字，将它们放入单个含 2 个数字的块。第 3 个块是 "78" 。
连接这些块后得到 "123-456-78" 。</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>number = "12"
<strong>输出：</strong>"12"
</pre>

<p><strong>示例 5：</strong></p>

<pre>
<strong>输入：</strong>number = "--17-5 229 35-39475 "
<strong>输出：</strong>"175-229-353-94-75"
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 <= number.length <= 100</code></li>
	<li><code>number</code> 由数字和字符 <code>'-'</code> 及 <code>' '</code> 组成。</li>
	<li><code>number</code> 中至少含 <strong>2</strong> 个数字。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：简单模拟

我们先按照题意，去除字符串中的所有空格和破折号。

记当前字符串长度为 $n$，然后从前往后遍历字符串，每 $3$ 个字符为一组，将其加入结果字符串中，共取 $n / 3$ 组。

若最后剩余 $1$ 个字符，则将前面的最后一组的最后一个字符与该字符组成一个新的两个字符的组，加入结果字符串中；若最后剩余 $2$ 个字符，直接将这连个字符组成一个新的组，加入结果字符串中。

最后将所有组之间加上破折号，返回结果字符串即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为字符串长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def reformatNumber(self, number: str) -> str:
        number = number.replace("-", "").replace(" ", "")
        n = len(number)
        ans = [number[i * 3 : i * 3 + 3] for i in range(n // 3)]
        if n % 3 == 1:
            ans[-1] = ans[-1][:2]
            ans.append(number[-2:])
        elif n % 3 == 2:
            ans.append(number[-2:])
        return "-".join(ans)
```

#### Java

```java
class Solution {
    public String reformatNumber(String number) {
        number = number.replace("-", "").replace(" ", "");
        int n = number.length();
        List<String> ans = new ArrayList<>();
        for (int i = 0; i < n / 3; ++i) {
            ans.add(number.substring(i * 3, i * 3 + 3));
        }
        if (n % 3 == 1) {
            ans.set(ans.size() - 1, ans.get(ans.size() - 1).substring(0, 2));
            ans.add(number.substring(n - 2));
        } else if (n % 3 == 2) {
            ans.add(number.substring(n - 2));
        }
        return String.join("-", ans);
    }
}
```

#### C++

```cpp
class Solution {
public:
    string reformatNumber(string number) {
        string s;
        for (char c : number) {
            if (c != ' ' && c != '-') {
                s.push_back(c);
            }
        }
        int n = s.size();
        vector<string> res;
        for (int i = 0; i < n / 3; ++i) {
            res.push_back(s.substr(i * 3, 3));
        }
        if (n % 3 == 1) {
            res.back() = res.back().substr(0, 2);
            res.push_back(s.substr(n - 2));
        } else if (n % 3 == 2) {
            res.push_back(s.substr(n - 2));
        }
        string ans;
        for (auto& v : res) {
            ans += v;
            ans += "-";
        }
        ans.pop_back();
        return ans;
    }
};
```

#### Go

```go
func reformatNumber(number string) string {
	number = strings.ReplaceAll(number, " ", "")
	number = strings.ReplaceAll(number, "-", "")
	n := len(number)
	ans := []string{}
	for i := 0; i < n/3; i++ {
		ans = append(ans, number[i*3:i*3+3])
	}
	if n%3 == 1 {
		ans[len(ans)-1] = ans[len(ans)-1][:2]
		ans = append(ans, number[n-2:])
	} else if n%3 == 2 {
		ans = append(ans, number[n-2:])
	}
	return strings.Join(ans, "-")
}
```

#### TypeScript

```ts
function reformatNumber(number: string): string {
    const cs = [...number].filter(c => c !== ' ' && c !== '-');
    const n = cs.length;
    return cs
        .map((v, i) => {
            if (((i + 1) % 3 === 0 && i < n - 2) || (n % 3 === 1 && n - 3 === i)) {
                return v + '-';
            }
            return v;
        })
        .join('');
}
```

#### Rust

```rust
impl Solution {
    pub fn reformat_number(number: String) -> String {
        let cs: Vec<char> = number.chars().filter(|&c| c != ' ' && c != '-').collect();
        let n = cs.len();
        cs.iter()
            .enumerate()
            .map(|(i, c)| {
                if ((i + 1) % 3 == 0 && i < n - 2) || (n % 3 == 1 && i == n - 3) {
                    return c.to_string() + &"-";
                }
                c.to_string()
            })
            .collect()
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1695. 删除子数组的最大得分](https://leetcode.cn/problems/maximum-erasure-value){#1695}

{{< tabs "1695" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumUniqueSubarray(self, nums: List[int]) -> int:
        vis = set()
        ans = s = i = 0
        for x in nums:
            while x in vis:
                y = nums[i]
                s -= y
                vis.remove(y)
                i += 1
            vis.add(x)
            s += x
            ans = max(ans, s)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maximumUniqueSubarray(int[] nums) {
        Set<Integer> vis = new HashSet<>();
        int ans = 0, s = 0, i = 0;
        for (int x : nums) {
            while (vis.contains(x)) {
                s -= nums[i];
                vis.remove(nums[i++]);
            }
            vis.add(x);
            s += x;
            ans = Math.max(ans, s);
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
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> vis;
        int ans = 0, s = 0, i = 0;
        for (int x : nums) {
            while (vis.contains(x)) {
                s -= nums[i];
                vis.erase(nums[i++]);
            }
            vis.insert(x);
            s += x;
            ans = max(ans, s);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumUniqueSubarray(nums []int) (ans int) {
	vis := map[int]bool{}
	var s, i int
	for _, x := range nums {
		for vis[x] {
			s -= nums[i]
			vis[nums[i]] = false
			i++
		}
		vis[x] = true
		s += x
		ans = max(ans, s)
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumUniqueSubarray(nums: number[]): number {
    const vis: Set<number> = new Set();
    let [ans, s, i] = [0, 0, 0];
    for (const x of nums) {
        while (vis.has(x)) {
            s -= nums[i];
            vis.delete(nums[i++]);
        }
        vis.add(x);
        s += x;
        ans = Math.max(ans, s);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashSet;

impl Solution {
    pub fn maximum_unique_subarray(nums: Vec<i32>) -> i32 {
        let mut vis = HashSet::new();
        let (mut ans, mut s, mut i) = (0, 0, 0);

        for &x in &nums {
            while vis.contains(&x) {
                let y = nums[i];
                s -= y;
                vis.remove(&y);
                i += 1;
            }
            vis.insert(x);
            s += x;
            ans = ans.max(s);
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

<p>给你一个正整数数组 <code>nums</code> ，请你从中删除一个含有 <strong>若干不同元素</strong> 的子数组<strong>。</strong>删除子数组的 <strong>得分</strong> 就是子数组各元素之 <strong>和</strong> 。</p>

<p>返回 <strong>只删除一个</strong> 子数组可获得的 <strong>最大得分</strong><em> 。</em></p>

<p>如果数组 <code>b</code> 是数组 <code>a</code> 的一个连续子序列，即如果它等于 <code>a[l],a[l+1],...,a[r]</code> ，那么它就是 <code>a</code> 的一个子数组。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [4,2,4,5,6]
<strong>输出：</strong>17
<strong>解释：</strong>最优子数组是 [2,4,5,6]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [5,2,1,2,5,2,1,2,5]
<strong>输出：</strong>8
<strong>解释：</strong>最优子数组是 [5,2,1] 或 [1,2,5]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= nums.length <= 10<sup>5</sup></code></li>
	<li><code>1 <= nums[i] <= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数组或哈希表 + 前缀和

我们用数组或哈希表 $\text{d}$ 记录每个数字最后一次出现的位置，用前缀和数组 $\text{s}$ 记录从起点到当前位置的和。我们用变量 $j$ 记录当前不重复子数组的左端点。

遍历数组，对于每个数字 $v$，如果 $\text{d}[v]$ 存在，那么我们更新 $j$ 为 $\max(j, \text{d}[v])$，这样就保证了当前不重复子数组不包含 $v$。然后我们更新答案为 $\max(\text{ans}, \text{s}[i] - \text{s}[j])$，最后更新 $\text{d}[v]$ 为 $i$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $\text{nums}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumUniqueSubarray(self, nums: List[int]) -> int:
        d = [0] * (max(nums) + 1)
        s = list(accumulate(nums, initial=0))
        ans = j = 0
        for i, v in enumerate(nums, 1):
            j = max(j, d[v])
            ans = max(ans, s[i] - s[j])
            d[v] = i
        return ans
```

#### Java

```java
class Solution {
    public int maximumUniqueSubarray(int[] nums) {
        int[] d = new int[10001];
        int n = nums.length;
        int[] s = new int[n + 1];
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + nums[i];
        }
        int ans = 0, j = 0;
        for (int i = 1; i <= n; ++i) {
            int v = nums[i - 1];
            j = Math.max(j, d[v]);
            ans = Math.max(ans, s[i] - s[j]);
            d[v] = i;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int d[10001]{};
        int n = nums.size();
        int s[n + 1];
        s[0] = 0;
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + nums[i];
        }
        int ans = 0, j = 0;
        for (int i = 1; i <= n; ++i) {
            int v = nums[i - 1];
            j = max(j, d[v]);
            ans = max(ans, s[i] - s[j]);
            d[v] = i;
        }
        return ans;
    }
};
```

#### Go

```go
func maximumUniqueSubarray(nums []int) (ans int) {
	d := [10001]int{}
	n := len(nums)
	s := make([]int, n+1)
	for i, v := range nums {
		s[i+1] = s[i] + v
	}
	for i, j := 1, 0; i <= n; i++ {
		v := nums[i-1]
		j = max(j, d[v])
		ans = max(ans, s[i]-s[j])
		d[v] = i
	}
	return
}
```

#### TypeScript

```ts
function maximumUniqueSubarray(nums: number[]): number {
    const m = Math.max(...nums);
    const n = nums.length;
    const s: number[] = Array.from({ length: n + 1 }, () => 0);
    for (let i = 1; i <= n; ++i) {
        s[i] = s[i - 1] + nums[i - 1];
    }
    const d = Array.from({ length: m + 1 }, () => 0);
    let [ans, j] = [0, 0];
    for (let i = 1; i <= n; ++i) {
        j = Math.max(j, d[nums[i - 1]]);
        ans = Math.max(ans, s[i] - s[j]);
        d[nums[i - 1]] = i;
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn maximum_unique_subarray(nums: Vec<i32>) -> i32 {
        let m = *nums.iter().max().unwrap() as usize;
        let mut d = vec![0; m + 1];
        let n = nums.len();

        let mut s = vec![0; n + 1];
        for i in 0..n {
            s[i + 1] = s[i] + nums[i];
        }

        let mut ans = 0;
        let mut j = 0;
        for (i, &v) in nums.iter().enumerate().map(|(i, v)| (i + 1, v)) {
            j = j.max(d[v as usize]);
            ans = ans.max(s[i] - s[j]);
            d[v as usize] = i;
        }

        ans
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：双指针（滑动窗口）

题目实际上是让我们找出一个最长的子数组，该子数组中所有元素都不相同。我们可以用两个指针 $i$ 和 $j$ 分别指向子数组的左右边界，初始时 $i = 0$, $j = 0$。另外，我们用一个哈希表 $\text{vis}$ 记录子数组中的元素。

遍历数组，对于每个数字 $x$，如果 $x$ 在 $\text{vis}$ 中，那么我们不断地将 $\text{nums}[i]$ 从 $\text{vis}$ 中移除，直到 $x$ 不在 $\text{vis}$ 中为止。这样我们就找到了一个不包含重复元素的子数组。我们将 $x$ 加入 $\text{vis}$，并更新子数组的和 $s$，然后更新答案 $\text{ans} = \max(\text{ans}, s)$。

遍历结束后，我们就可以得到最大的子数组和。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $\text{nums}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumUniqueSubarray(self, nums: List[int]) -> int:
        vis = set()
        ans = s = i = 0
        for x in nums:
            while x in vis:
                y = nums[i]
                s -= y
                vis.remove(y)
                i += 1
            vis.add(x)
            s += x
            ans = max(ans, s)
        return ans
```

#### Java

```java
class Solution {
    public int maximumUniqueSubarray(int[] nums) {
        Set<Integer> vis = new HashSet<>();
        int ans = 0, s = 0, i = 0;
        for (int x : nums) {
            while (vis.contains(x)) {
                s -= nums[i];
                vis.remove(nums[i++]);
            }
            vis.add(x);
            s += x;
            ans = Math.max(ans, s);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> vis;
        int ans = 0, s = 0, i = 0;
        for (int x : nums) {
            while (vis.contains(x)) {
                s -= nums[i];
                vis.erase(nums[i++]);
            }
            vis.insert(x);
            s += x;
            ans = max(ans, s);
        }
        return ans;
    }
};
```

#### Go

```go
func maximumUniqueSubarray(nums []int) (ans int) {
	vis := map[int]bool{}
	var s, i int
	for _, x := range nums {
		for vis[x] {
			s -= nums[i]
			vis[nums[i]] = false
			i++
		}
		vis[x] = true
		s += x
		ans = max(ans, s)
	}
	return
}
```

#### TypeScript

```ts
function maximumUniqueSubarray(nums: number[]): number {
    const vis: Set<number> = new Set();
    let [ans, s, i] = [0, 0, 0];
    for (const x of nums) {
        while (vis.has(x)) {
            s -= nums[i];
            vis.delete(nums[i++]);
        }
        vis.add(x);
        s += x;
        ans = Math.max(ans, s);
    }
    return ans;
}
```

#### Rust

```rust
use std::collections::HashSet;

impl Solution {
    pub fn maximum_unique_subarray(nums: Vec<i32>) -> i32 {
        let mut vis = HashSet::new();
        let (mut ans, mut s, mut i) = (0, 0, 0);

        for &x in &nums {
            while vis.contains(&x) {
                let y = nums[i];
                s -= y;
                vis.remove(&y);
                i += 1;
            }
            vis.insert(x);
            s += x;
            ans = ans.max(s);
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

# [1696. 跳跃游戏 VI](https://leetcode.cn/problems/jump-game-vi){#1696}

{{< tabs "1696" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxResult(self, nums: List[int], k: int) -> int:
        n = len(nums)
        f = [0] * n
        q = deque([0])
        for i in range(n):
            if i - q[0] > k:
                q.popleft()
            f[i] = nums[i] + f[q[0]]
            while q and f[q[-1]] <= f[i]:
                q.pop()
            q.append(i)
        return f[-1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxResult(int[] nums, int k) {
        int n = nums.length;
        int[] f = new int[n];
        Deque<Integer> q = new ArrayDeque<>();
        q.offer(0);
        for (int i = 0; i < n; ++i) {
            if (i - q.peekFirst() > k) {
                q.pollFirst();
            }
            f[i] = nums[i] + f[q.peekFirst()];
            while (!q.isEmpty() && f[q.peekLast()] <= f[i]) {
                q.pollLast();
            }
            q.offerLast(i);
        }
        return f[n - 1];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        int f[n];
        f[0] = 0;
        deque<int> q = {0};
        for (int i = 0; i < n; ++i) {
            if (i - q.front() > k) {
                q.pop_front();
            }
            f[i] = nums[i] + f[q.front()];
            while (!q.empty() && f[i] >= f[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
        }
        return f[n - 1];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxResult(nums []int, k int) int {
	n := len(nums)
	f := make([]int, n)
	q := Deque{}
	q.PushBack(0)
	for i := 0; i < n; i++ {
		if i-q.Front() > k {
			q.PopFront()
		}
		f[i] = nums[i] + f[q.Front()]
		for !q.Empty() && f[i] >= f[q.Back()] {
			q.PopBack()
		}
		q.PushBack(i)
	}
	return f[n-1]
}

type Deque struct{ l, r []int }

func (q Deque) Empty() bool {
	return len(q.l) == 0 && len(q.r) == 0
}

func (q Deque) Size() int {
	return len(q.l) + len(q.r)
}

func (q *Deque) PushFront(v int) {
	q.l = append(q.l, v)
}

func (q *Deque) PushBack(v int) {
	q.r = append(q.r, v)
}

func (q *Deque) PopFront() (v int) {
	if len(q.l) > 0 {
		q.l, v = q.l[:len(q.l)-1], q.l[len(q.l)-1]
	} else {
		v, q.r = q.r[0], q.r[1:]
	}
	return
}

func (q *Deque) PopBack() (v int) {
	if len(q.r) > 0 {
		q.r, v = q.r[:len(q.r)-1], q.r[len(q.r)-1]
	} else {
		v, q.l = q.l[0], q.l[1:]
	}
	return
}

func (q Deque) Front() int {
	if len(q.l) > 0 {
		return q.l[len(q.l)-1]
	}
	return q.r[0]
}

func (q Deque) Back() int {
	if len(q.r) > 0 {
		return q.r[len(q.r)-1]
	}
	return q.l[0]
}

func (q Deque) Get(i int) int {
	if i < len(q.l) {
		return q.l[len(q.l)-1-i]
	}
	return q.r[i-len(q.l)]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxResult(nums: number[], k: number): number {
    const n = nums.length;
    const f: number[] = Array(n).fill(0);
    const q = new Deque<number>();
    q.pushBack(0);
    for (let i = 0; i < n; ++i) {
        if (i - q.frontValue()! > k) {
            q.popFront();
        }
        f[i] = nums[i] + f[q.frontValue()!];
        while (!q.isEmpty() && f[i] >= f[q.backValue()!]) {
            q.popBack();
        }
        q.pushBack(i);
    }
    return f[n - 1];
}

class Node<T> {
    value: T;
    next: Node<T> | null;
    prev: Node<T> | null;

    constructor(value: T) {
        this.value = value;
        this.next = null;
        this.prev = null;
    }
}

class Deque<T> {
    private front: Node<T> | null;
    private back: Node<T> | null;
    private size: number;

    constructor() {
        this.front = null;
        this.back = null;
        this.size = 0;
    }

    pushFront(val: T): void {
        const newNode = new Node(val);
        if (this.isEmpty()) {
            this.front = newNode;
            this.back = newNode;
        } else {
            newNode.next = this.front;
            this.front!.prev = newNode;
            this.front = newNode;
        }
        this.size++;
    }

    pushBack(val: T): void {
        const newNode = new Node(val);
        if (this.isEmpty()) {
            this.front = newNode;
            this.back = newNode;
        } else {
            newNode.prev = this.back;
            this.back!.next = newNode;
            this.back = newNode;
        }
        this.size++;
    }

    popFront(): T | undefined {
        if (this.isEmpty()) {
            return undefined;
        }
        const value = this.front!.value;
        this.front = this.front!.next;
        if (this.front !== null) {
            this.front.prev = null;
        } else {
            this.back = null;
        }
        this.size--;
        return value;
    }

    popBack(): T | undefined {
        if (this.isEmpty()) {
            return undefined;
        }
        const value = this.back!.value;
        this.back = this.back!.prev;
        if (this.back !== null) {
            this.back.next = null;
        } else {
            this.front = null;
        }
        this.size--;
        return value;
    }

    frontValue(): T | undefined {
        return this.front?.value;
    }

    backValue(): T | undefined {
        return this.back?.value;
    }

    getSize(): number {
        return this.size;
    }

    isEmpty(): boolean {
        return this.size === 0;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong> 开始的整数数组 <code>nums</code> 和一个整数 <code>k</code> 。</p>

<p>一开始你在下标 <code>0</code> 处。每一步，你最多可以往前跳 <code>k</code> 步，但你不能跳出数组的边界。也就是说，你可以从下标 <code>i</code> 跳到 <code>[i + 1， min(n - 1, i + k)]</code> <strong>包含</strong> 两个端点的任意位置。</p>

<p>你的目标是到达数组最后一个位置（下标为 <code>n - 1</code> ），你的 <strong>得分</strong> 为经过的所有数字之和。</p>

<p>请你返回你能得到的 <strong>最大得分</strong> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [<strong>1</strong>,<strong>-1</strong>,-2,<strong>4</strong>,-7,<strong>3</strong>], k = 2
<b>输出：</b>7
<b>解释：</b>你可以选择子序列 [1,-1,4,3] （上面加粗的数字），和为 7 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [<strong>10</strong>,-5,-2,<strong>4</strong>,0,<strong>3</strong>], k = 3
<b>输出：</b>17
<b>解释：</b>你可以选择子序列 [10,4,3] （上面加粗数字），和为 17 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>nums = [1,-5,-20,4,-1,3,-6,-3], k = 2
<b>输出：</b>0
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li> <code>1 <= nums.length, k <= 10<sup>5</sup></code></li>
	<li><code>-10<sup>4</sup> <= nums[i] <= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划 + 单调队列优化

我们定义 $f[i]$ 表示到达下标 $i$ 的最大得分，那么 $f[i]$ 的值可以从 $f[j]$ 转移而来，其中 $j$ 满足 $i - k \leq j \leq i - 1$。因此我们可以使用动态规划求解。

状态转移方程为：

$$
f[i] = \max_{j \in [i - k, i - 1]} f[j] + nums[i]
$$

我们可以使用单调队列优化状态转移方程，具体做法是维护一个单调递减的队列，队列中存储的是下标 $j$，并且队列中的下标对应的 $f[j]$ 值是单调递减的。在进行状态转移时，我们只需要取出队首的下标 $j$，即可得到 $f[j]$ 的最大值，然后将 $f[i]$ 的值更新为 $f[j] + nums[i]$ 即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxResult(self, nums: List[int], k: int) -> int:
        n = len(nums)
        f = [0] * n
        q = deque([0])
        for i in range(n):
            if i - q[0] > k:
                q.popleft()
            f[i] = nums[i] + f[q[0]]
            while q and f[q[-1]] <= f[i]:
                q.pop()
            q.append(i)
        return f[-1]
```

#### Java

```java
class Solution {
    public int maxResult(int[] nums, int k) {
        int n = nums.length;
        int[] f = new int[n];
        Deque<Integer> q = new ArrayDeque<>();
        q.offer(0);
        for (int i = 0; i < n; ++i) {
            if (i - q.peekFirst() > k) {
                q.pollFirst();
            }
            f[i] = nums[i] + f[q.peekFirst()];
            while (!q.isEmpty() && f[q.peekLast()] <= f[i]) {
                q.pollLast();
            }
            q.offerLast(i);
        }
        return f[n - 1];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        int f[n];
        f[0] = 0;
        deque<int> q = {0};
        for (int i = 0; i < n; ++i) {
            if (i - q.front() > k) {
                q.pop_front();
            }
            f[i] = nums[i] + f[q.front()];
            while (!q.empty() && f[i] >= f[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
        }
        return f[n - 1];
    }
};
```

#### Go

```go
func maxResult(nums []int, k int) int {
	n := len(nums)
	f := make([]int, n)
	q := Deque{}
	q.PushBack(0)
	for i := 0; i < n; i++ {
		if i-q.Front() > k {
			q.PopFront()
		}
		f[i] = nums[i] + f[q.Front()]
		for !q.Empty() && f[i] >= f[q.Back()] {
			q.PopBack()
		}
		q.PushBack(i)
	}
	return f[n-1]
}

type Deque struct{ l, r []int }

func (q Deque) Empty() bool {
	return len(q.l) == 0 && len(q.r) == 0
}

func (q Deque) Size() int {
	return len(q.l) + len(q.r)
}

func (q *Deque) PushFront(v int) {
	q.l = append(q.l, v)
}

func (q *Deque) PushBack(v int) {
	q.r = append(q.r, v)
}

func (q *Deque) PopFront() (v int) {
	if len(q.l) > 0 {
		q.l, v = q.l[:len(q.l)-1], q.l[len(q.l)-1]
	} else {
		v, q.r = q.r[0], q.r[1:]
	}
	return
}

func (q *Deque) PopBack() (v int) {
	if len(q.r) > 0 {
		q.r, v = q.r[:len(q.r)-1], q.r[len(q.r)-1]
	} else {
		v, q.l = q.l[0], q.l[1:]
	}
	return
}

func (q Deque) Front() int {
	if len(q.l) > 0 {
		return q.l[len(q.l)-1]
	}
	return q.r[0]
}

func (q Deque) Back() int {
	if len(q.r) > 0 {
		return q.r[len(q.r)-1]
	}
	return q.l[0]
}

func (q Deque) Get(i int) int {
	if i < len(q.l) {
		return q.l[len(q.l)-1-i]
	}
	return q.r[i-len(q.l)]
}
```

#### TypeScript

```ts
function maxResult(nums: number[], k: number): number {
    const n = nums.length;
    const f: number[] = Array(n).fill(0);
    const q = new Deque<number>();
    q.pushBack(0);
    for (let i = 0; i < n; ++i) {
        if (i - q.frontValue()! > k) {
            q.popFront();
        }
        f[i] = nums[i] + f[q.frontValue()!];
        while (!q.isEmpty() && f[i] >= f[q.backValue()!]) {
            q.popBack();
        }
        q.pushBack(i);
    }
    return f[n - 1];
}

class Node<T> {
    value: T;
    next: Node<T> | null;
    prev: Node<T> | null;

    constructor(value: T) {
        this.value = value;
        this.next = null;
        this.prev = null;
    }
}

class Deque<T> {
    private front: Node<T> | null;
    private back: Node<T> | null;
    private size: number;

    constructor() {
        this.front = null;
        this.back = null;
        this.size = 0;
    }

    pushFront(val: T): void {
        const newNode = new Node(val);
        if (this.isEmpty()) {
            this.front = newNode;
            this.back = newNode;
        } else {
            newNode.next = this.front;
            this.front!.prev = newNode;
            this.front = newNode;
        }
        this.size++;
    }

    pushBack(val: T): void {
        const newNode = new Node(val);
        if (this.isEmpty()) {
            this.front = newNode;
            this.back = newNode;
        } else {
            newNode.prev = this.back;
            this.back!.next = newNode;
            this.back = newNode;
        }
        this.size++;
    }

    popFront(): T | undefined {
        if (this.isEmpty()) {
            return undefined;
        }
        const value = this.front!.value;
        this.front = this.front!.next;
        if (this.front !== null) {
            this.front.prev = null;
        } else {
            this.back = null;
        }
        this.size--;
        return value;
    }

    popBack(): T | undefined {
        if (this.isEmpty()) {
            return undefined;
        }
        const value = this.back!.value;
        this.back = this.back!.prev;
        if (this.back !== null) {
            this.back.next = null;
        } else {
            this.front = null;
        }
        this.size--;
        return value;
    }

    frontValue(): T | undefined {
        return this.front?.value;
    }

    backValue(): T | undefined {
        return this.back?.value;
    }

    getSize(): number {
        return this.size;
    }

    isEmpty(): boolean {
        return this.size === 0;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1697. 检查边长度限制的路径是否存在](https://leetcode.cn/problems/checking-existence-of-edge-length-limited-paths){#1697}

{{< tabs "1697" >}}

{{% tab "python" %}}
```python
p = list(range(n))
size = [1] * n

def find(x):
    if p[x] != x:
        # 路径压缩
        p[x] = find(p[x])
    return p[x]


def union(a, b):
    pa, pb = find(a), find(b)
    if pa == pb:
        return
    p[pa] = pb
    size[pb] += size[pa]
```
{{% /tab %}}
{{% tab "java" %}}
```java
int[] p = new int[n];
int[] size = new int[n];
for (int i = 0; i < n; ++i) {
    p[i] = i;
    size[i] = 1;
}

int find(int x) {
    if (p[x] != x) {
        // 路径压缩
        p[x] = find(p[x]);
    }
    return p[x];
}

void union(int a, int b) {
    int pa = find(a), pb = find(b);
    if (pa == pb) {
        return;
    }
    p[pa] = pb;
    size[pb] += size[pa];
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
vector<int> p(n);
iota(p.begin(), p.end(), 0);
vector<int> size(n, 1);

int find(int x) {
    if (p[x] != x) {
        // 路径压缩
        p[x] = find(p[x]);
    }
    return p[x];
}

void unite(int a, int b) {
    int pa = find(a), pb = find(b);
    if (pa == pb) return;
    p[pa] = pb;
    size[pb] += size[pa];
}
```
{{% /tab %}}
{{% tab "go" %}}
```go
p := make([]int, n)
size := make([]int, n)
for i := range p {
    p[i] = i
    size[i] = 1
}

func find(x int) int {
    if p[x] != x {
        // 路径压缩
        p[x] = find(p[x])
    }
    return p[x]
}

func union(a, b int) {
    pa, pb := find(a), find(b)
    if pa == pb {
        return
    }
    p[pa] = pb
    size[pb] += size[pa]
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    #[allow(dead_code)]
    pub fn distance_limited_paths_exist(
        n: i32,
        edge_list: Vec<Vec<i32>>,
        queries: Vec<Vec<i32>>,
    ) -> Vec<bool> {
        let mut disjoint_set: Vec<usize> = vec![0; n as usize];
        let mut ans_vec: Vec<bool> = vec![false; queries.len()];
        let mut q_vec: Vec<usize> = vec![0; queries.len()];

        // Initialize the set
        for i in 0..n {
            disjoint_set[i as usize] = i as usize;
        }

        // Initialize the q_vec
        for i in 0..queries.len() {
            q_vec[i] = i;
        }

        // Sort the q_vec based on the query limit, from the lowest to highest
        q_vec.sort_by(|i, j| queries[*i][2].cmp(&queries[*j][2]));

        // Sort the edge_list based on the edge weight, from the lowest to highest
        let mut edge_list = edge_list.clone();
        edge_list.sort_by(|i, j| i[2].cmp(&j[2]));

        let mut edge_idx: usize = 0;
        for q_idx in &q_vec {
            let s = queries[*q_idx][0] as usize;
            let d = queries[*q_idx][1] as usize;
            let limit = queries[*q_idx][2];
            // Construct the disjoint set
            while edge_idx < edge_list.len() && edge_list[edge_idx][2] < limit {
                Solution::union(
                    edge_list[edge_idx][0] as usize,
                    edge_list[edge_idx][1] as usize,
                    &mut disjoint_set,
                );
                edge_idx += 1;
            }
            // If the parents of s & d are the same, this query should be `true`
            // Otherwise, the current query is `false`
            ans_vec[*q_idx] = Solution::check_valid(s, d, &mut disjoint_set);
        }

        ans_vec
    }

    #[allow(dead_code)]
    pub fn find(x: usize, d_set: &mut Vec<usize>) -> usize {
        if d_set[x] != x {
            d_set[x] = Solution::find(d_set[x], d_set);
        }
        return d_set[x];
    }

    #[allow(dead_code)]
    pub fn union(s: usize, d: usize, d_set: &mut Vec<usize>) {
        let p_s = Solution::find(s, d_set);
        let p_d = Solution::find(d, d_set);
        d_set[p_s] = p_d;
    }

    #[allow(dead_code)]
    pub fn check_valid(s: usize, d: usize, d_set: &mut Vec<usize>) -> bool {
        let p_s = Solution::find(s, d_set);
        let p_d = Solution::find(d, d_set);
        p_s == p_d
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个 <code>n</code> 个点组成的无向图边集 <code>edgeList</code> ，其中 <code>edgeList[i] = [u<sub>i</sub>, v<sub>i</sub>, dis<sub>i</sub>]</code> 表示点 <code>u<sub>i</sub></code> 和点 <code>v<sub>i</sub></code> 之间有一条长度为 <code>dis<sub>i</sub></code> 的边。请注意，两个点之间可能有 <strong>超过一条边 </strong>。</p>

<p>给你一个查询数组<code>queries</code> ，其中 <code>queries[j] = [p<sub>j</sub>, q<sub>j</sub>, limit<sub>j</sub>]</code> ，你的任务是对于每个查询 <code>queries[j]</code> ，判断是否存在从 <code>p<sub>j</sub></code> 到 <code>q<sub>j</sub></code><sub> </sub>的路径，且这条路径上的每一条边都 <strong>严格小于</strong> <code>limit<sub>j</sub></code> 。</p>

<p>请你返回一个 <b>布尔数组</b><em> </em><code>answer</code><em> </em>，其中<em> </em><code>answer.length == queries.length</code> ，当 <code>queries[j]</code> 的查询结果为 <code>true</code> 时， <code>answer</code> 第<em> </em><code>j</code> 个值为<em> </em><code>true</code><em> </em>，否则为 <code>false</code> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1600-1699/1697.Checking%20Existence%20of%20Edge%20Length%20Limited%20Paths/images/h.png" style="width: 267px; height: 262px;" />
<pre>
<b>输入：</b>n = 3, edgeList = [[0,1,2],[1,2,4],[2,0,8],[1,0,16]], queries = [[0,1,2],[0,2,5]]
<b>输出：</b>[false,true]
<b>解释：</b>上图为给定的输入数据。注意到 0 和 1 之间有两条重边，分别为 2 和 16 。
对于第一个查询，0 和 1 之间没有小于 2 的边，所以我们返回 false 。
对于第二个查询，有一条路径（0 -> 1 -> 2）两条边都小于 5 ，所以这个查询我们返回 true 。
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1600-1699/1697.Checking%20Existence%20of%20Edge%20Length%20Limited%20Paths/images/q.png" style="width: 390px; height: 358px;" />
<pre>
<b>输入：</b>n = 5, edgeList = [[0,1,10],[1,2,5],[2,3,9],[3,4,13]], queries = [[0,4,14],[1,4,13]]
<b>输出：</b>[true,false]
<b>解释：</b>上图为给定数据。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 <= n <= 10<sup>5</sup></code></li>
	<li><code>1 <= edgeList.length, queries.length <= 10<sup>5</sup></code></li>
	<li><code>edgeList[i].length == 3</code></li>
	<li><code>queries[j].length == 3</code></li>
	<li><code>0 <= u<sub>i</sub>, v<sub>i</sub>, p<sub>j</sub>, q<sub>j</sub> <= n - 1</code></li>
	<li><code>u<sub>i</sub> != v<sub>i</sub></code></li>
	<li><code>p<sub>j</sub> != q<sub>j</sub></code></li>
	<li><code>1 <= dis<sub>i</sub>, limit<sub>j</sub> <= 10<sup>9</sup></code></li>
	<li>两个点之间可能有 <strong>多条</strong> 边。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：离线查询 + 并查集

根据题目要求，我们需要对每个查询 $queries[i]$ 进行判断，即判断当前查询的两个点 $a$ 和 $b$ 之间是否存在一条边权小于等于 $limit$ 的路径。

判断两点是否连通可以通过并查集来实现。另外，由于查询的顺序对结果没有影响，因此我们可以先将所有查询按照 $limit$ 从小到大排序，所有边也按照边权从小到大排序。

然后对于每个查询，我们从边权最小的边开始，将边权严格小于 $limit$ 的所有边加入并查集，接着利用并查集的查询操作判断两点是否连通即可。

时间复杂度 $O(m \times \log m + q \times \log q)$，其中 $m$ 和 $q$ 分别为边数和查询数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def distanceLimitedPathsExist(
        self, n: int, edgeList: List[List[int]], queries: List[List[int]]
    ) -> List[bool]:
        def find(x):
            if p[x] != x:
                p[x] = find(p[x])
            return p[x]

        p = list(range(n))
        edgeList.sort(key=lambda x: x[2])
        j = 0
        ans = [False] * len(queries)
        for i, (a, b, limit) in sorted(enumerate(queries), key=lambda x: x[1][2]):
            while j < len(edgeList) and edgeList[j][2] < limit:
                u, v, _ = edgeList[j]
                p[find(u)] = find(v)
                j += 1
            ans[i] = find(a) == find(b)
        return ans
```

#### Java

```java
class Solution {
    private int[] p;

    public boolean[] distanceLimitedPathsExist(int n, int[][] edgeList, int[][] queries) {
        p = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
        }
        Arrays.sort(edgeList, (a, b) -> a[2] - b[2]);
        int m = queries.length;
        boolean[] ans = new boolean[m];
        Integer[] qid = new Integer[m];
        for (int i = 0; i < m; ++i) {
            qid[i] = i;
        }
        Arrays.sort(qid, (i, j) -> queries[i][2] - queries[j][2]);
        int j = 0;
        for (int i : qid) {
            int a = queries[i][0], b = queries[i][1], limit = queries[i][2];
            while (j < edgeList.length && edgeList[j][2] < limit) {
                int u = edgeList[j][0], v = edgeList[j][1];
                p[find(u)] = find(v);
                ++j;
            }
            ans[i] = find(a) == find(b);
        }
        return ans;
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
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        vector<int> p(n);
        iota(p.begin(), p.end(), 0);
        sort(edgeList.begin(), edgeList.end(), [](auto& a, auto& b) { return a[2] < b[2]; });
        function<int(int)> find = [&](int x) -> int {
            if (p[x] != x) p[x] = find(p[x]);
            return p[x];
        };
        int m = queries.size();
        vector<bool> ans(m);
        vector<int> qid(m);
        iota(qid.begin(), qid.end(), 0);
        sort(qid.begin(), qid.end(), [&](int i, int j) { return queries[i][2] < queries[j][2]; });
        int j = 0;
        for (int i : qid) {
            int a = queries[i][0], b = queries[i][1], limit = queries[i][2];
            while (j < edgeList.size() && edgeList[j][2] < limit) {
                int u = edgeList[j][0], v = edgeList[j][1];
                p[find(u)] = find(v);
                ++j;
            }
            ans[i] = find(a) == find(b);
        }
        return ans;
    }
};
```

#### Go

```go
func distanceLimitedPathsExist(n int, edgeList [][]int, queries [][]int) []bool {
	p := make([]int, n)
	for i := range p {
		p[i] = i
	}
	sort.Slice(edgeList, func(i, j int) bool { return edgeList[i][2] < edgeList[j][2] })
	var find func(int) int
	find = func(x int) int {
		if p[x] != x {
			p[x] = find(p[x])
		}
		return p[x]
	}
	m := len(queries)
	qid := make([]int, m)
	ans := make([]bool, m)
	for i := range qid {
		qid[i] = i
	}
	sort.Slice(qid, func(i, j int) bool { return queries[qid[i]][2] < queries[qid[j]][2] })
	j := 0
	for _, i := range qid {
		a, b, limit := queries[i][0], queries[i][1], queries[i][2]
		for j < len(edgeList) && edgeList[j][2] < limit {
			u, v := edgeList[j][0], edgeList[j][1]
			p[find(u)] = find(v)
			j++
		}
		ans[i] = find(a) == find(b)
	}
	return ans
}
```

#### Rust

```rust
impl Solution {
    #[allow(dead_code)]
    pub fn distance_limited_paths_exist(
        n: i32,
        edge_list: Vec<Vec<i32>>,
        queries: Vec<Vec<i32>>,
    ) -> Vec<bool> {
        let mut disjoint_set: Vec<usize> = vec![0; n as usize];
        let mut ans_vec: Vec<bool> = vec![false; queries.len()];
        let mut q_vec: Vec<usize> = vec![0; queries.len()];

        // Initialize the set
        for i in 0..n {
            disjoint_set[i as usize] = i as usize;
        }

        // Initialize the q_vec
        for i in 0..queries.len() {
            q_vec[i] = i;
        }

        // Sort the q_vec based on the query limit, from the lowest to highest
        q_vec.sort_by(|i, j| queries[*i][2].cmp(&queries[*j][2]));

        // Sort the edge_list based on the edge weight, from the lowest to highest
        let mut edge_list = edge_list.clone();
        edge_list.sort_by(|i, j| i[2].cmp(&j[2]));

        let mut edge_idx: usize = 0;
        for q_idx in &q_vec {
            let s = queries[*q_idx][0] as usize;
            let d = queries[*q_idx][1] as usize;
            let limit = queries[*q_idx][2];
            // Construct the disjoint set
            while edge_idx < edge_list.len() && edge_list[edge_idx][2] < limit {
                Solution::union(
                    edge_list[edge_idx][0] as usize,
                    edge_list[edge_idx][1] as usize,
                    &mut disjoint_set,
                );
                edge_idx += 1;
            }
            // If the parents of s & d are the same, this query should be `true`
            // Otherwise, the current query is `false`
            ans_vec[*q_idx] = Solution::check_valid(s, d, &mut disjoint_set);
        }

        ans_vec
    }

    #[allow(dead_code)]
    pub fn find(x: usize, d_set: &mut Vec<usize>) -> usize {
        if d_set[x] != x {
            d_set[x] = Solution::find(d_set[x], d_set);
        }
        return d_set[x];
    }

    #[allow(dead_code)]
    pub fn union(s: usize, d: usize, d_set: &mut Vec<usize>) {
        let p_s = Solution::find(s, d_set);
        let p_d = Solution::find(d, d_set);
        d_set[p_s] = p_d;
    }

    #[allow(dead_code)]
    pub fn check_valid(s: usize, d: usize, d_set: &mut Vec<usize>) -> bool {
        let p_s = Solution::find(s, d_set);
        let p_d = Solution::find(d, d_set);
        p_s == p_d
    }
}
```

<!-- tabs:end -->

附并查集相关介绍以及常用模板：

并查集是一种树形的数据结构，顾名思义，它用于处理一些不交集的**合并**及**查询**问题。 它支持两种操作：

1. 查找（Find）：确定某个元素处于哪个子集，单次操作时间复杂度 $O(\alpha(n))$
1. 合并（Union）：将两个子集合并成一个集合，单次操作时间复杂度 $O(\alpha(n))$

其中 $\alpha$ 为阿克曼函数的反函数，其增长极其缓慢，也就是说其单次操作的平均运行时间可以认为是一个很小的常数。

以下是并查集的常用模板，需要熟练掌握。其中：

-   `n` 表示节点数
-   `p` 存储每个点的父节点，初始时每个点的父节点都是自己
-   `size` 只有当节点是祖宗节点时才有意义，表示祖宗节点所在集合中，点的数量
-   `find(x)` 函数用于查找 $x$ 所在集合的祖宗节点
-   `union(a, b)` 函数用于合并 $a$ 和 $b$ 所在的集合

<!-- tabs:start -->

#### Python3

```python
p = list(range(n))
size = [1] * n

def find(x):
    if p[x] != x:
        # 路径压缩
        p[x] = find(p[x])
    return p[x]


def union(a, b):
    pa, pb = find(a), find(b)
    if pa == pb:
        return
    p[pa] = pb
    size[pb] += size[pa]
```

#### Java

```java
int[] p = new int[n];
int[] size = new int[n];
for (int i = 0; i < n; ++i) {
    p[i] = i;
    size[i] = 1;
}

int find(int x) {
    if (p[x] != x) {
        // 路径压缩
        p[x] = find(p[x]);
    }
    return p[x];
}

void union(int a, int b) {
    int pa = find(a), pb = find(b);
    if (pa == pb) {
        return;
    }
    p[pa] = pb;
    size[pb] += size[pa];
}
```

#### C++

```cpp
vector<int> p(n);
iota(p.begin(), p.end(), 0);
vector<int> size(n, 1);

int find(int x) {
    if (p[x] != x) {
        // 路径压缩
        p[x] = find(p[x]);
    }
    return p[x];
}

void unite(int a, int b) {
    int pa = find(a), pb = find(b);
    if (pa == pb) return;
    p[pa] = pb;
    size[pb] += size[pa];
}
```

#### Go

```go
p := make([]int, n)
size := make([]int, n)
for i := range p {
    p[i] = i
    size[i] = 1
}

func find(x int) int {
    if p[x] != x {
        // 路径压缩
        p[x] = find(p[x])
    }
    return p[x]
}

func union(a, b int) {
    pa, pb := find(a), find(b)
    if pa == pb {
        return
    }
    p[pa] = pb
    size[pb] += size[pa]
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1698. 字符串的不同子字符串个数 🔒](https://leetcode.cn/problems/number-of-distinct-substrings-in-a-string){#1698}

{{< tabs "1698" >}}

{{% tab "python" %}}
```python
class Solution:
    def countDistinct(self, s: str) -> int:
        base = 131
        n = len(s)
        p = [0] * (n + 10)
        h = [0] * (n + 10)
        p[0] = 1
        for i, c in enumerate(s):
            p[i + 1] = p[i] * base
            h[i + 1] = h[i] * base + ord(c)
        ss = set()
        for i in range(1, n + 1):
            for j in range(i, n + 1):
                t = h[j] - h[i - 1] * p[j - i + 1]
                ss.add(t)
        return len(ss)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countDistinct(String s) {
        int base = 131;
        int n = s.length();
        long[] p = new long[n + 10];
        long[] h = new long[n + 10];
        p[0] = 1;
        for (int i = 0; i < n; ++i) {
            p[i + 1] = p[i] * base;
            h[i + 1] = h[i] * base + s.charAt(i);
        }
        Set<Long> ss = new HashSet<>();
        for (int i = 1; i <= n; ++i) {
            for (int j = i; j <= n; ++j) {
                long t = h[j] - h[i - 1] * p[j - i + 1];
                ss.add(t);
            }
        }
        return ss.size();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int countDistinct(string s) {
        using ull = unsigned long long;
        int n = s.size();
        ull p[n + 10];
        ull h[n + 10];
        int base = 131;
        p[0] = 1;
        for (int i = 0; i < n; ++i) {
            p[i + 1] = p[i] * base;
            h[i + 1] = h[i] * base + s[i];
        }
        unordered_set<ull> ss;
        for (int i = 1; i <= n; ++i) {
            for (int j = i; j <= n; ++j) {
                ss.insert(h[j] - h[i - 1] * p[j - i + 1]);
            }
        }
        return ss.size();
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countDistinct(s string) int {
	n := len(s)
	p := make([]int, n+10)
	h := make([]int, n+10)
	p[0] = 1
	base := 131
	for i, c := range s {
		p[i+1] = p[i] * base
		h[i+1] = h[i]*base + int(c)
	}
	ss := map[int]struct{}{}
	for i := 1; i <= n; i++ {
		for j := i; j <= n; j++ {
			ss[h[j]-h[i-1]*p[j-i+1]] = struct{}{}
		}
	}
	return len(ss)
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个字符串 <code>s</code>，返回 <code>s</code> 的不同子字符串的个数。</p>

<p>字符串的 <strong>子字符串 </strong>是由原字符串删除开头若干个字符（可能是 0 个）并删除结尾若干个字符（可能是 0 个）形成的字符串。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "aabbaba"
<strong>输出：</strong>21
<strong>解释：</strong>不同子字符串的集合是 ["a","b","aa","bb","ab","ba","aab","abb","bab","bba","aba","aabb","abba","bbab","baba","aabba","abbab","bbaba","aabbab","abbaba","aabbaba"]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "abcdefg"
<strong>输出：</strong>28
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= s.length <= 500</code></li>
	<li><code>s</code> 由小写英文字母组成。</li>
</ul>

<p><b>进阶：</b>你可以以 <code>O(n)</code> 时间复杂度解决此问题吗？</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：暴力枚举

枚举所有子串，使用哈希表记录不同子串的个数。

时间复杂度 $O(n^3)$，空间复杂度 $O(n^2)$。其中 $n$ 为字符串长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countDistinct(self, s: str) -> int:
        n = len(s)
        return len({s[i:j] for i in range(n) for j in range(i + 1, n + 1)})
```

#### Java

```java
class Solution {
    public int countDistinct(String s) {
        Set<String> ss = new HashSet<>();
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                ss.add(s.substring(i, j));
            }
        }
        return ss.size();
    }
}
```

#### C++

```cpp
class Solution {
public:
    int countDistinct(string s) {
        unordered_set<string_view> ss;
        int n = s.size();
        string_view t, v = s;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                t = v.substr(i, j - i);
                ss.insert(t);
            }
        }
        return ss.size();
    }
};
```

#### Go

```go
func countDistinct(s string) int {
	ss := map[string]struct{}{}
	for i := range s {
		for j := i + 1; j <= len(s); j++ {
			ss[s[i:j]] = struct{}{}
		}
	}
	return len(ss)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：字符串哈希

**字符串哈希**是把一个任意长度的字符串映射成一个非负整数，并且其冲突的概率几乎为 0。字符串哈希用于计算字符串哈希值，快速判断两个字符串是否相等。

取一固定值 BASE，把字符串看作是 BASE 进制数，并分配一个大于 0 的数值，代表每种字符。一般来说，我们分配的数值都远小于 BASE。例如，对于小写字母构成的字符串，可以令 a=1, b=2, ..., z=26。取一固定值 MOD，求出该 BASE 进制对 M 的余数，作为该字符串的 hash 值。

一般来说，取 BASE=131 或者 BASE=13331，此时 hash 值产生的冲突概率极低。只要两个字符串 hash 值相同，我们就认为两个字符串是相等的。通常 MOD 取 2^64，C++ 里，可以直接使用 unsigned long long 类型存储这个 hash 值，在计算时不处理算术溢出问题，产生溢出时相当于自动对 2^64 取模，这样可以避免低效取模运算。

除了在极特殊构造的数据上，上述 hash 算法很难产生冲突，一般情况下上述 hash 算法完全可以出现在题目的标准答案中。我们还可以多取一些恰当的 BASE 和 MOD 的值（例如大质数），多进行几组 hash 运算，当结果都相同时才认为原字符串相等，就更加难以构造出使这个 hash 产生错误的数据。

时间复杂度 $O(n^2)$，空间复杂度 $O(n^2)$。其中 $n$ 为字符串长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countDistinct(self, s: str) -> int:
        base = 131
        n = len(s)
        p = [0] * (n + 10)
        h = [0] * (n + 10)
        p[0] = 1
        for i, c in enumerate(s):
            p[i + 1] = p[i] * base
            h[i + 1] = h[i] * base + ord(c)
        ss = set()
        for i in range(1, n + 1):
            for j in range(i, n + 1):
                t = h[j] - h[i - 1] * p[j - i + 1]
                ss.add(t)
        return len(ss)
```

#### Java

```java
class Solution {
    public int countDistinct(String s) {
        int base = 131;
        int n = s.length();
        long[] p = new long[n + 10];
        long[] h = new long[n + 10];
        p[0] = 1;
        for (int i = 0; i < n; ++i) {
            p[i + 1] = p[i] * base;
            h[i + 1] = h[i] * base + s.charAt(i);
        }
        Set<Long> ss = new HashSet<>();
        for (int i = 1; i <= n; ++i) {
            for (int j = i; j <= n; ++j) {
                long t = h[j] - h[i - 1] * p[j - i + 1];
                ss.add(t);
            }
        }
        return ss.size();
    }
}
```

#### C++

```cpp
class Solution {
public:
    int countDistinct(string s) {
        using ull = unsigned long long;
        int n = s.size();
        ull p[n + 10];
        ull h[n + 10];
        int base = 131;
        p[0] = 1;
        for (int i = 0; i < n; ++i) {
            p[i + 1] = p[i] * base;
            h[i + 1] = h[i] * base + s[i];
        }
        unordered_set<ull> ss;
        for (int i = 1; i <= n; ++i) {
            for (int j = i; j <= n; ++j) {
                ss.insert(h[j] - h[i - 1] * p[j - i + 1]);
            }
        }
        return ss.size();
    }
};
```

#### Go

```go
func countDistinct(s string) int {
	n := len(s)
	p := make([]int, n+10)
	h := make([]int, n+10)
	p[0] = 1
	base := 131
	for i, c := range s {
		p[i+1] = p[i] * base
		h[i+1] = h[i]*base + int(c)
	}
	ss := map[int]struct{}{}
	for i := 1; i <= n; i++ {
		for j := i; j <= n; j++ {
			ss[h[j]-h[i-1]*p[j-i+1]] = struct{}{}
		}
	}
	return len(ss)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1699. 两人之间的通话次数 🔒](https://leetcode.cn/problems/number-of-calls-between-two-persons){#1699}

{{< tabs "1699" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT
    LEAST(from_id, to_id) AS person1,
    GREATEST(from_id, to_id) AS person2,
    COUNT(1) AS call_count,
    SUM(duration) AS total_duration
FROM Calls
GROUP BY 1, 2;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：&nbsp;<code>Calls</code></p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| from_id     | int     |
| to_id       | int     |
| duration    | int     |
+-------------+---------+
该表没有主键(具有唯一值的列)，它可能包含重复项。
该表包含 from_id 与 to_id 间的一次电话的时长。
from_id != to_id
</pre>

<p>&nbsp;</p>

<p>编写解决方案，统计每一对用户&nbsp;<code>(person1, person2)</code>&nbsp;之间的通话次数和通话总时长，其中&nbsp;<code>person1 &lt; person2</code>&nbsp;。</p>

<p>以 <strong>任意顺序</strong> 返回结果表。</p>

<p>返回结果格式如下示例所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
Calls 表：
+---------+-------+----------+
| from_id | to_id | duration |
+---------+-------+----------+
| 1       | 2     | 59       |
| 2       | 1     | 11       |
| 1       | 3     | 20       |
| 3       | 4     | 100      |
| 3       | 4     | 200      |
| 3       | 4     | 200      |
| 4       | 3     | 499      |
+---------+-------+----------+
<strong>输出：</strong>
+---------+---------+------------+----------------+
| person1 | person2 | call_count | total_duration |
+---------+---------+------------+----------------+
| 1       | 2       | 2          | 70             |
| 1       | 3       | 1          | 20             |
| 3       | 4       | 4          | 999            |
+---------+---------+------------+----------------+
<strong>解释：</strong>
用户 1 和 2 打过 2 次电话，总时长为 70 (59 + 11)。
用户 1 和 3 打过 1 次电话，总时长为 20。
用户 3 和 4 打过 4 次电话，总时长为 999 (100 + 200 + 200 + 499)。</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：分组求和统计

我们可以用 `if` 函数或者 `least` 和 `greatest` 函数来将 `from_id` 和 `to_id` 转换成 `person1` 和 `person2`，然后按照 `person1` 和 `person2` 分组求和统计即可。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT
    IF(from_id < to_id, from_id, to_id) AS person1,
    IF(from_id < to_id, to_id, from_id) AS person2,
    COUNT(1) AS call_count,
    SUM(duration) AS total_duration
FROM Calls
GROUP BY 1, 2;
```

#### MySQL

```sql
# Write your MySQL query statement below
SELECT
    LEAST(from_id, to_id) AS person1,
    GREATEST(from_id, to_id) AS person2,
    COUNT(1) AS call_count,
    SUM(duration) AS total_duration
FROM Calls
GROUP BY 1, 2;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
