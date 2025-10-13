---
title: "1900_最佳运动员的比拼回合"
date: 2025-10-08T18:38:49+08:00
weight: 1
tags: [二分查找, 二叉搜索树, 二叉树, 位运算, 动态规划, 博弈, 哈希表, 字符串, 并查集, 广度优先搜索, 数学, 数据库, 数组, 有序集合, 树, 深度优先搜索, 矩阵, 脑筋急转弯, 记忆化搜索, 贪心]
---

{{< markmap >}}
### [1900_最佳运动员的比拼回合](#1900)
#### [记忆化搜索](#1900)
#### [动态规划](#1900)
### [1901_寻找峰值 II](#1901)
#### [数组](#1901)
#### [二分查找](#1901)
#### [矩阵](#1901)
### [1902_给定二叉搜索树的插入顺序求深度 🔒](#1902)
#### [树](#1902)
#### [二叉搜索树](#1902)
#### [数组](#1902)
#### [二叉树](#1902)
#### [有序集合](#1902)
### [1903_字符串中的最大奇数](#1903)
#### [贪心](#1903)
#### [数学](#1903)
#### [字符串](#1903)
### [1904_你完成的完整对局数](#1904)
#### [数学](#1904)
#### [字符串](#1904)
### [1905_统计子岛屿](#1905)
#### [深度优先搜索](#1905)
#### [广度优先搜索](#1905)
#### [并查集](#1905)
#### [数组](#1905)
#### [矩阵](#1905)
### [1906_查询差绝对值的最小值](#1906)
#### [数组](#1906)
#### [哈希表](#1906)
### [1907_按分类统计薪水](#1907)
#### [数据库](#1907)
### [1908_Nim 游戏 II 🔒](#1908)
#### [位运算](#1908)
#### [脑筋急转弯](#1908)
#### [数组](#1908)
#### [数学](#1908)
#### [动态规划](#1908)
#### [博弈](#1908)
### [1909_删除一个元素使数组严格递增](#1909)
#### [数组](#1909)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1900_最佳运动员的比拼回合
___
#### 记忆化搜索
___
#### 动态规划
---
### 1901_寻找峰值 II
___
#### 数组
___
#### 二分查找
___
#### 矩阵
---
### 1902_给定二叉搜索树的插入顺序求深度 🔒
___
#### 树
___
#### 二叉搜索树
___
#### 数组
___
#### 二叉树
___
#### 有序集合
---
### 1903_字符串中的最大奇数
___
#### 贪心
___
#### 数学
___
#### 字符串
---
### 1904_你完成的完整对局数
___
#### 数学
___
#### 字符串
---
### 1905_统计子岛屿
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 并查集
___
#### 数组
___
#### 矩阵
---
### 1906_查询差绝对值的最小值
___
#### 数组
___
#### 哈希表
---
### 1907_按分类统计薪水
___
#### 数据库
---
### 1908_Nim 游戏 II 🔒
___
#### 位运算
___
#### 脑筋急转弯
___
#### 数组
___
#### 数学
___
#### 动态规划
___
#### 博弈
---
### 1909_删除一个元素使数组严格递增
___
#### 数组
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 二叉搜索树 | 二叉树 |
| 位运算 | 动态规划 | 博弈 |
| 哈希表 | 字符串 | 并查集 |
| 广度优先搜索 | 数学 | 数据库 |
| 数组 | 有序集合 | 树 |
| 深度优先搜索 | 矩阵 | 脑筋急转弯 |
| 记忆化搜索 | 贪心 |  |

# [1900. 最佳运动员的比拼回合](https://leetcode.cn/problems/the-earliest-and-latest-rounds-where-players-compete){#1900}

{{< tabs "1900" >}}

{{% tab "python" %}}
```python
@cache
def dfs(l: int, r: int, n: int):
    if l + r == n - 1:
        return [1, 1]
    res = [inf, -inf]
    m = n >> 1
    for i in range(1 << m):
        win = [False] * n
        for j in range(m):
            if i >> j & 1:
                win[j] = True
            else:
                win[n - 1 - j] = True
        if n & 1:
            win[m] = True
        win[n - 1 - l] = win[n - 1 - r] = False
        win[l] = win[r] = True
        a = b = c = 0
        for j in range(n):
            if j == l:
                a = c
            if j == r:
                b = c
            if win[j]:
                c += 1
        x, y = dfs(a, b, c)
        res[0] = min(res[0], x + 1)
        res[1] = max(res[1], y + 1)
    return res


class Solution:
    def earliestAndLatest(
        self, n: int, firstPlayer: int, secondPlayer: int
    ) -> List[int]:
        return dfs(firstPlayer - 1, secondPlayer - 1, n)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    static int[][][] f = new int[30][30][31];

    public int[] earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        return dfs(firstPlayer - 1, secondPlayer - 1, n);
    }

    private int[] dfs(int l, int r, int n) {
        if (f[l][r][n] != 0) {
            return decode(f[l][r][n]);
        }
        if (l + r == n - 1) {
            f[l][r][n] = encode(1, 1);
            return new int[] {1, 1};
        }
        int min = Integer.MAX_VALUE, max = Integer.MIN_VALUE;
        int m = n >> 1;
        for (int i = 0; i < (1 << m); i++) {
            boolean[] win = new boolean[n];
            for (int j = 0; j < m; j++) {
                if (((i >> j) & 1) == 1) {
                    win[j] = true;
                } else {
                    win[n - 1 - j] = true;
                }
            }
            if ((n & 1) == 1) {
                win[m] = true;
            }
            win[n - 1 - l] = win[n - 1 - r] = false;
            win[l] = win[r] = true;
            int a = 0, b = 0, c = 0;
            for (int j = 0; j < n; j++) {
                if (j == l) {
                    a = c;
                }
                if (j == r) {
                    b = c;
                }
                if (win[j]) {
                    c++;
                }
            }
            int[] t = dfs(a, b, c);
            min = Math.min(min, t[0] + 1);
            max = Math.max(max, t[1] + 1);
        }
        f[l][r][n] = encode(min, max);
        return new int[] {min, max};
    }

    private int encode(int x, int y) {
        return (x << 8) | y;
    }

    private int[] decode(int val) {
        return new int[] {val >> 8, val & 255};
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
int f[30][30][31];
class Solution {
public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        return dfs(firstPlayer - 1, secondPlayer - 1, n);
    }

private:
    vector<int> dfs(int l, int r, int n) {
        if (f[l][r][n] != 0) {
            return decode(f[l][r][n]);
        }
        if (l + r == n - 1) {
            f[l][r][n] = encode(1, 1);
            return {1, 1};
        }

        int min = INT_MAX, max = INT_MIN;
        int m = n >> 1;

        for (int i = 0; i < (1 << m); i++) {
            vector<bool> win(n, false);
            for (int j = 0; j < m; j++) {
                if ((i >> j) & 1) {
                    win[j] = true;
                } else {
                    win[n - 1 - j] = true;
                }
            }
            if (n & 1) {
                win[m] = true;
            }

            win[n - 1 - l] = false;
            win[n - 1 - r] = false;
            win[l] = true;
            win[r] = true;

            int a = 0, b = 0, c = 0;
            for (int j = 0; j < n; j++) {
                if (j == l) a = c;
                if (j == r) b = c;
                if (win[j]) c++;
            }

            vector<int> t = dfs(a, b, c);
            min = std::min(min, t[0] + 1);
            max = std::max(max, t[1] + 1);
        }

        f[l][r][n] = encode(min, max);
        return {min, max};
    }

    int encode(int x, int y) {
        return (x << 8) | y;
    }

    vector<int> decode(int val) {
        return {val >> 8, val & 255};
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
var f [30][30][31]int

func earliestAndLatest(n int, firstPlayer int, secondPlayer int) []int {
	return dfs(firstPlayer-1, secondPlayer-1, n)
}

func dfs(l, r, n int) []int {
	if f[l][r][n] != 0 {
		return decode(f[l][r][n])
	}
	if l+r == n-1 {
		f[l][r][n] = encode(1, 1)
		return []int{1, 1}
	}

	min, max := 1<<30, -1<<31
	m := n >> 1

	for i := 0; i < (1 << m); i++ {
		win := make([]bool, n)
		for j := 0; j < m; j++ {
			if (i>>j)&1 == 1 {
				win[j] = true
			} else {
				win[n-1-j] = true
			}
		}
		if n&1 == 1 {
			win[m] = true
		}
		win[n-1-l] = false
		win[n-1-r] = false
		win[l] = true
		win[r] = true

		a, b, c := 0, 0, 0
		for j := 0; j < n; j++ {
			if j == l {
				a = c
			}
			if j == r {
				b = c
			}
			if win[j] {
				c++
			}
		}

		t := dfs(a, b, c)
		if t[0]+1 < min {
			min = t[0] + 1
		}
		if t[1]+1 > max {
			max = t[1] + 1
		}
	}

	f[l][r][n] = encode(min, max)
	return []int{min, max}
}

func encode(x, y int) int {
	return (x << 8) | y
}

func decode(val int) []int {
	return []int{val >> 8, val & 255}
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function earliestAndLatest(n: number, firstPlayer: number, secondPlayer: number): number[] {
    return dfs(firstPlayer - 1, secondPlayer - 1, n);
}

const f: number[][][] = Array.from({ length: 30 }, () =>
    Array.from({ length: 30 }, () => Array(31).fill(0)),
);

function dfs(l: number, r: number, n: number): number[] {
    if (f[l][r][n] !== 0) {
        return decode(f[l][r][n]);
    }
    if (l + r === n - 1) {
        f[l][r][n] = encode(1, 1);
        return [1, 1];
    }

    let min = Number.MAX_SAFE_INTEGER;
    let max = Number.MIN_SAFE_INTEGER;
    const m = n >> 1;

    for (let i = 0; i < 1 << m; i++) {
        const win: boolean[] = Array(n).fill(false);
        for (let j = 0; j < m; j++) {
            if ((i >> j) & 1) {
                win[j] = true;
            } else {
                win[n - 1 - j] = true;
            }
        }

        if (n & 1) {
            win[m] = true;
        }

        win[n - 1 - l] = false;
        win[n - 1 - r] = false;
        win[l] = true;
        win[r] = true;

        let a = 0,
            b = 0,
            c = 0;
        for (let j = 0; j < n; j++) {
            if (j === l) a = c;
            if (j === r) b = c;
            if (win[j]) c++;
        }

        const t = dfs(a, b, c);
        min = Math.min(min, t[0] + 1);
        max = Math.max(max, t[1] + 1);
    }

    f[l][r][n] = encode(min, max);
    return [min, max];
}

function encode(x: number, y: number): number {
    return (x << 8) | y;
}

function decode(val: number): number[] {
    return [val >> 8, val & 255];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p><code>n</code> 名运动员参与一场锦标赛，所有运动员站成一排，并根据 <strong>最开始的</strong> 站位从 <code>1</code> 到 <code>n</code> 编号（运动员 <code>1</code> 是这一排中的第一个运动员，运动员 <code>2</code> 是第二个运动员，依此类推）。</p>

<p>锦标赛由多个回合组成（从回合 <code>1</code> 开始）。每一回合中，这一排从前往后数的第 <code>i</code> 名运动员需要与从后往前数的第 <code>i</code> 名运动员比拼，获胜者将会进入下一回合。如果当前回合中运动员数目为奇数，那么中间那位运动员将轮空晋级下一回合。</p>

<ul>
	<li>例如，当前回合中，运动员 <code>1, 2, 4, 6, 7</code> 站成一排

    <ul>
    	<li>运动员 <code>1</code> 需要和运动员 <code>7</code> 比拼</li>
    	<li>运动员 <code>2</code> 需要和运动员 <code>6</code> 比拼</li>
    	<li>运动员 <code>4</code> 轮空晋级下一回合</li>
    </ul>
    </li>

</ul>

<p>每回合结束后，获胜者将会基于最开始分配给他们的原始顺序（升序）重新排成一排。</p>

<p>编号为 <code>firstPlayer</code> 和 <code>secondPlayer</code> 的运动员是本场锦标赛中的最佳运动员。在他们开始比拼之前，完全可以战胜任何其他运动员。而任意两个其他运动员进行比拼时，其中任意一个都有获胜的可能，因此你可以 <strong>裁定</strong> 谁是这一回合的获胜者。</p>

<p>给你三个整数 <code>n</code>、<code>firstPlayer</code> 和 <code>secondPlayer</code> 。返回一个由两个值组成的整数数组，分别表示两位最佳运动员在本场锦标赛中比拼的 <strong>最早</strong> 回合数和 <strong>最晚</strong> 回合数。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>n = 11, firstPlayer = 2, secondPlayer = 4
<strong>输出：</strong>[3,4]
<strong>解释：</strong>
一种能够产生最早回合数的情景是：
回合 1：1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11
回合 2：2, 3, 4, 5, 6, 11
回合 3：2, 3, 4
一种能够产生最晚回合数的情景是：
回合 1：1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11
回合 2：1, 2, 3, 4, 5, 6
回合 3：1, 2, 4
回合 4：2, 4
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>n = 5, firstPlayer = 1, secondPlayer = 5
<strong>输出：</strong>[1,1]
<strong>解释：</strong>两名最佳运动员 1 和 5 将会在回合 1 进行比拼。
不存在使他们在其他回合进行比拼的可能。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 28</code></li>
	<li><code>1 &lt;= firstPlayer &lt; secondPlayer &lt;= n</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索 + 二进制枚举

我们定义一个函数 $\text{dfs}(l, r, n)$，表示在当前回合中，编号为 $l$ 和 $r$ 的运动员在 $n$ 名运动员中比拼的最早和最晚回合数。

函数 $\text{dfs}(l, r, n)$ 的执行逻辑如下：

1. 如果 $l + r = n - 1$，说明两名运动员在当前回合中比拼，返回 $[1, 1]$。
2. 如果 $f[l][r][n] \neq 0$，说明之前已经计算过这个状态，直接返回结果。
3. 初始化最早回合数为正无穷大，最晚回合数为负无穷大。
4. 计算当前回合中前半部分的运动员数目 $m = n / 2$。
5. 枚举前半部分的所有可能的胜者组合（使用二进制枚举），对于每一种组合：
    - 根据当前组合确定哪些运动员获胜。
    - 确定当前回合中编号为 $l$ 和 $r$ 的运动员在当前回合中的位置。
    - 统计当前回合中编号为 $l$ 和 $r$ 的运动员在剩余运动员中的位置，记为 $a$ 和 $b$，以及剩余运动员的总数 $c$。
    - 递归调用 $\text{dfs}(a, b, c)$，获取当前状态的最早和最晚回合数。
    - 更新最早回合数和最晚回合数。
6. 将计算结果存储在 $f[l][r][n]$ 中，并返回最早和最晚回合数。

答案为 $\text{dfs}(\text{firstPlayer} - 1, \text{secondPlayer} - 1, n)$。

<!-- tabs:start -->

#### Python3

```python
@cache
def dfs(l: int, r: int, n: int):
    if l + r == n - 1:
        return [1, 1]
    res = [inf, -inf]
    m = n >> 1
    for i in range(1 << m):
        win = [False] * n
        for j in range(m):
            if i >> j & 1:
                win[j] = True
            else:
                win[n - 1 - j] = True
        if n & 1:
            win[m] = True
        win[n - 1 - l] = win[n - 1 - r] = False
        win[l] = win[r] = True
        a = b = c = 0
        for j in range(n):
            if j == l:
                a = c
            if j == r:
                b = c
            if win[j]:
                c += 1
        x, y = dfs(a, b, c)
        res[0] = min(res[0], x + 1)
        res[1] = max(res[1], y + 1)
    return res


class Solution:
    def earliestAndLatest(
        self, n: int, firstPlayer: int, secondPlayer: int
    ) -> List[int]:
        return dfs(firstPlayer - 1, secondPlayer - 1, n)
```

#### Java

```java
class Solution {
    static int[][][] f = new int[30][30][31];

    public int[] earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        return dfs(firstPlayer - 1, secondPlayer - 1, n);
    }

    private int[] dfs(int l, int r, int n) {
        if (f[l][r][n] != 0) {
            return decode(f[l][r][n]);
        }
        if (l + r == n - 1) {
            f[l][r][n] = encode(1, 1);
            return new int[] {1, 1};
        }
        int min = Integer.MAX_VALUE, max = Integer.MIN_VALUE;
        int m = n >> 1;
        for (int i = 0; i < (1 << m); i++) {
            boolean[] win = new boolean[n];
            for (int j = 0; j < m; j++) {
                if (((i >> j) & 1) == 1) {
                    win[j] = true;
                } else {
                    win[n - 1 - j] = true;
                }
            }
            if ((n & 1) == 1) {
                win[m] = true;
            }
            win[n - 1 - l] = win[n - 1 - r] = false;
            win[l] = win[r] = true;
            int a = 0, b = 0, c = 0;
            for (int j = 0; j < n; j++) {
                if (j == l) {
                    a = c;
                }
                if (j == r) {
                    b = c;
                }
                if (win[j]) {
                    c++;
                }
            }
            int[] t = dfs(a, b, c);
            min = Math.min(min, t[0] + 1);
            max = Math.max(max, t[1] + 1);
        }
        f[l][r][n] = encode(min, max);
        return new int[] {min, max};
    }

    private int encode(int x, int y) {
        return (x << 8) | y;
    }

    private int[] decode(int val) {
        return new int[] {val >> 8, val & 255};
    }
}
```

#### C++

```cpp
int f[30][30][31];
class Solution {
public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        return dfs(firstPlayer - 1, secondPlayer - 1, n);
    }

private:
    vector<int> dfs(int l, int r, int n) {
        if (f[l][r][n] != 0) {
            return decode(f[l][r][n]);
        }
        if (l + r == n - 1) {
            f[l][r][n] = encode(1, 1);
            return {1, 1};
        }

        int min = INT_MAX, max = INT_MIN;
        int m = n >> 1;

        for (int i = 0; i < (1 << m); i++) {
            vector<bool> win(n, false);
            for (int j = 0; j < m; j++) {
                if ((i >> j) & 1) {
                    win[j] = true;
                } else {
                    win[n - 1 - j] = true;
                }
            }
            if (n & 1) {
                win[m] = true;
            }

            win[n - 1 - l] = false;
            win[n - 1 - r] = false;
            win[l] = true;
            win[r] = true;

            int a = 0, b = 0, c = 0;
            for (int j = 0; j < n; j++) {
                if (j == l) a = c;
                if (j == r) b = c;
                if (win[j]) c++;
            }

            vector<int> t = dfs(a, b, c);
            min = std::min(min, t[0] + 1);
            max = std::max(max, t[1] + 1);
        }

        f[l][r][n] = encode(min, max);
        return {min, max};
    }

    int encode(int x, int y) {
        return (x << 8) | y;
    }

    vector<int> decode(int val) {
        return {val >> 8, val & 255};
    }
};
```

#### Go

```go
var f [30][30][31]int

func earliestAndLatest(n int, firstPlayer int, secondPlayer int) []int {
	return dfs(firstPlayer-1, secondPlayer-1, n)
}

func dfs(l, r, n int) []int {
	if f[l][r][n] != 0 {
		return decode(f[l][r][n])
	}
	if l+r == n-1 {
		f[l][r][n] = encode(1, 1)
		return []int{1, 1}
	}

	min, max := 1<<30, -1<<31
	m := n >> 1

	for i := 0; i < (1 << m); i++ {
		win := make([]bool, n)
		for j := 0; j < m; j++ {
			if (i>>j)&1 == 1 {
				win[j] = true
			} else {
				win[n-1-j] = true
			}
		}
		if n&1 == 1 {
			win[m] = true
		}
		win[n-1-l] = false
		win[n-1-r] = false
		win[l] = true
		win[r] = true

		a, b, c := 0, 0, 0
		for j := 0; j < n; j++ {
			if j == l {
				a = c
			}
			if j == r {
				b = c
			}
			if win[j] {
				c++
			}
		}

		t := dfs(a, b, c)
		if t[0]+1 < min {
			min = t[0] + 1
		}
		if t[1]+1 > max {
			max = t[1] + 1
		}
	}

	f[l][r][n] = encode(min, max)
	return []int{min, max}
}

func encode(x, y int) int {
	return (x << 8) | y
}

func decode(val int) []int {
	return []int{val >> 8, val & 255}
}
```

#### TypeScript

```ts
function earliestAndLatest(n: number, firstPlayer: number, secondPlayer: number): number[] {
    return dfs(firstPlayer - 1, secondPlayer - 1, n);
}

const f: number[][][] = Array.from({ length: 30 }, () =>
    Array.from({ length: 30 }, () => Array(31).fill(0)),
);

function dfs(l: number, r: number, n: number): number[] {
    if (f[l][r][n] !== 0) {
        return decode(f[l][r][n]);
    }
    if (l + r === n - 1) {
        f[l][r][n] = encode(1, 1);
        return [1, 1];
    }

    let min = Number.MAX_SAFE_INTEGER;
    let max = Number.MIN_SAFE_INTEGER;
    const m = n >> 1;

    for (let i = 0; i < 1 << m; i++) {
        const win: boolean[] = Array(n).fill(false);
        for (let j = 0; j < m; j++) {
            if ((i >> j) & 1) {
                win[j] = true;
            } else {
                win[n - 1 - j] = true;
            }
        }

        if (n & 1) {
            win[m] = true;
        }

        win[n - 1 - l] = false;
        win[n - 1 - r] = false;
        win[l] = true;
        win[r] = true;

        let a = 0,
            b = 0,
            c = 0;
        for (let j = 0; j < n; j++) {
            if (j === l) a = c;
            if (j === r) b = c;
            if (win[j]) c++;
        }

        const t = dfs(a, b, c);
        min = Math.min(min, t[0] + 1);
        max = Math.max(max, t[1] + 1);
    }

    f[l][r][n] = encode(min, max);
    return [min, max];
}

function encode(x: number, y: number): number {
    return (x << 8) | y;
}

function decode(val: number): number[] {
    return [val >> 8, val & 255];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1901. 寻找峰值 II](https://leetcode.cn/problems/find-a-peak-element-ii){#1901}

{{< tabs "1901" >}}

{{% tab "python" %}}
```python
class Solution:
    def findPeakGrid(self, mat: List[List[int]]) -> List[int]:
        l, r = 0, len(mat) - 1
        while l < r:
            mid = (l + r) >> 1
            j = mat[mid].index(max(mat[mid]))
            if mat[mid][j] > mat[mid + 1][j]:
                r = mid
            else:
                l = mid + 1
        return [l, mat[l].index(max(mat[l]))]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] findPeakGrid(int[][] mat) {
        int l = 0, r = mat.length - 1;
        int n = mat[0].length;
        while (l < r) {
            int mid = (l + r) >> 1;
            int j = maxPos(mat[mid]);
            if (mat[mid][j] > mat[mid + 1][j]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return new int[] {l, maxPos(mat[l])};
    }

    private int maxPos(int[] arr) {
        int j = 0;
        for (int i = 1; i < arr.length; ++i) {
            if (arr[j] < arr[i]) {
                j = i;
            }
        }
        return j;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int l = 0, r = mat.size() - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            int j = distance(mat[mid].begin(), max_element(mat[mid].begin(), mat[mid].end()));
            if (mat[mid][j] > mat[mid + 1][j]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        int j = distance(mat[l].begin(), max_element(mat[l].begin(), mat[l].end()));
        return {l, j};
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findPeakGrid(mat [][]int) []int {
	maxPos := func(arr []int) int {
		j := 0
		for i := 1; i < len(arr); i++ {
			if arr[i] > arr[j] {
				j = i
			}
		}
		return j
	}
	l, r := 0, len(mat)-1
	for l < r {
		mid := (l + r) >> 1
		j := maxPos(mat[mid])
		if mat[mid][j] > mat[mid+1][j] {
			r = mid
		} else {
			l = mid + 1
		}
	}
	return []int{l, maxPos(mat[l])}
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findPeakGrid(mat: number[][]): number[] {
    let [l, r] = [0, mat.length - 1];
    while (l < r) {
        const mid = (l + r) >> 1;
        const j = mat[mid].indexOf(Math.max(...mat[mid]));
        if (mat[mid][j] > mat[mid + 1][j]) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return [l, mat[l].indexOf(Math.max(...mat[l]))];
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn find_peak_grid(mat: Vec<Vec<i32>>) -> Vec<i32> {
        let mut l: usize = 0;
        let mut r: usize = mat.len() - 1;
        while l < r {
            let mid: usize = (l + r) >> 1;
            let j: usize = mat[mid]
                .iter()
                .position(|&x| x == *mat[mid].iter().max().unwrap())
                .unwrap();
            if mat[mid][j] > mat[mid + 1][j] {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        let j: usize = mat[l]
            .iter()
            .position(|&x| x == *mat[l].iter().max().unwrap())
            .unwrap();
        vec![l as i32, j as i32]
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>一个 2D 网格中的 <strong>峰值</strong><strong> </strong>是指那些 <strong>严格大于 </strong>其相邻格子(上、下、左、右)的元素。</p>

<p>给你一个<strong> 从 0 开始编号 </strong>的 <code>m x n</code> 矩阵 <code>mat</code> ，其中任意两个相邻格子的值都<strong> 不相同</strong> 。找出 <strong>任意一个 峰值</strong> <code>mat[i][j]</code> 并 <strong>返回其位置 </strong><code>[i,j]</code> 。</p>

<p>你可以假设整个矩阵周边环绕着一圈值为 <code>-1</code> 的格子。</p>

<p>要求必须写出时间复杂度为 <code>O(m log(n))</code> 或 <code>O(n log(m))</code> 的算法</p>

<p>&nbsp;</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1900-1999/1901.Find%20a%20Peak%20Element%20II/images/1.png" style="width: 206px; height: 209px;" /></p>

<pre>
<strong>输入:</strong> mat = [[1,4],[3,2]]
<strong>输出:</strong> [0,1]
<strong>解释:</strong>&nbsp;3 和 4 都是峰值，所以[1,0]和[0,1]都是可接受的答案。
</pre>

<p><strong>示例 2:</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1900-1999/1901.Find%20a%20Peak%20Element%20II/images/3.png" style="width: 254px; height: 257px;" /></strong></p>

<pre>
<strong>输入:</strong> mat = [[10,20,15],[21,30,14],[7,16,32]]
<strong>输出:</strong> [1,1]
<strong>解释:</strong>&nbsp;30 和 32 都是峰值，所以[1,1]和[2,2]都是可接受的答案。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == mat.length</code></li>
	<li><code>n == mat[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 500</code></li>
	<li><code>1 &lt;= mat[i][j] &lt;= 10<sup>5</sup></code></li>
	<li>任意两个相邻元素均不相等.</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二分查找

记 $m$ 和 $n$ 分别为矩阵的行数和列数。

题目要求我们寻找峰值，并且时间复杂度为 $O(m \times \log n)$ 或 $O(n \times \log m)$，那么我们可以考虑使用二分查找。

我们考虑第 $i$ 行的最大值，不妨将其下标记为 $j$。

如果 $mat[i][j] \gt mat[i + 1][j]$，那么第 $[0,..i]$ 行中必然存在一个峰值，我们只需要在第 $[0,..i]$ 行中找到最大值即可。同理，如果 $mat[i][j] \lt mat[i + 1][j]$，那么第 $[i + 1,..m - 1]$ 行中必然存在一个峰值，我们只需要在第 $[i + 1,..m - 1]$ 行中找到最大值即可。

为什么上述做法是对的？我们不妨用反证法来证明。

如果 $mat[i][j] \gt mat[i + 1][j]$，假设第 $[0,..i]$ 行中不存在峰值，那么 $mat[i][j]$ 不是峰值，而由于 $mat[i][j]$ 是第 $i$ 行的最大值，并且 $mat[i][j] \gt mat[i + 1][j]$，那么 $mat[i][j] \lt mat[i - 1][j]$。我们继续从第 $i - 1$ 行往上考虑，每一行的最大值都小于上一行的最大值。那么当遍历到 $i = 0$ 时，由于矩阵中的元素都是正整数，并且矩阵周边一圈的格子的值都为 $-1$。因此，在第 $0$ 行时，其最大值大于其所有相邻元素，那么第 $0$ 行的最大值就是峰值，与假设矛盾。因此，第 $[0,..i]$ 行中必然存在一个峰值。

对于 $mat[i][j] \lt mat[i + 1][j]$ 的情况，我们可以用类似的方法证明第 $[i + 1,..m - 1]$ 行中必然存在一个峰值。

因此，我们可以使用二分查找来寻找峰值。

我们二分查找矩阵的行，初始时查找的边界为 $l = 0$, $r = m - 1$。每一次，我们找到当前的中间行 $mid$，并找到该行的最大值下标 $j$。如果 $mat[mid][j] \gt mat[mid + 1][j]$，那么我们就在第 $[0,..mid]$ 行中寻找峰值，即更新 $r = mid$。否则，我们就在第 $[mid + 1,..m - 1]$ 行中寻找峰值，即更新 $l = mid + 1$。当 $l = r$ 时，我们就找到了峰值所在的位置 $[l, j_l]$。其中 $j_l$ 是第 $l$ 行的最大值下标。

时间复杂度 $O(n \times \log m)$，其中 $m$ 和 $n$ 分别为矩阵的行数和列数。二分查找的时间复杂度为 $O(\log m)$，每次二分查找时，我们需要遍历第 $mid$ 行的所有元素，时间复杂度为 $O(n)$。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findPeakGrid(self, mat: List[List[int]]) -> List[int]:
        l, r = 0, len(mat) - 1
        while l < r:
            mid = (l + r) >> 1
            j = mat[mid].index(max(mat[mid]))
            if mat[mid][j] > mat[mid + 1][j]:
                r = mid
            else:
                l = mid + 1
        return [l, mat[l].index(max(mat[l]))]
```

#### Java

```java
class Solution {
    public int[] findPeakGrid(int[][] mat) {
        int l = 0, r = mat.length - 1;
        int n = mat[0].length;
        while (l < r) {
            int mid = (l + r) >> 1;
            int j = maxPos(mat[mid]);
            if (mat[mid][j] > mat[mid + 1][j]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return new int[] {l, maxPos(mat[l])};
    }

    private int maxPos(int[] arr) {
        int j = 0;
        for (int i = 1; i < arr.length; ++i) {
            if (arr[j] < arr[i]) {
                j = i;
            }
        }
        return j;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int l = 0, r = mat.size() - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            int j = distance(mat[mid].begin(), max_element(mat[mid].begin(), mat[mid].end()));
            if (mat[mid][j] > mat[mid + 1][j]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        int j = distance(mat[l].begin(), max_element(mat[l].begin(), mat[l].end()));
        return {l, j};
    }
};
```

#### Go

```go
func findPeakGrid(mat [][]int) []int {
	maxPos := func(arr []int) int {
		j := 0
		for i := 1; i < len(arr); i++ {
			if arr[i] > arr[j] {
				j = i
			}
		}
		return j
	}
	l, r := 0, len(mat)-1
	for l < r {
		mid := (l + r) >> 1
		j := maxPos(mat[mid])
		if mat[mid][j] > mat[mid+1][j] {
			r = mid
		} else {
			l = mid + 1
		}
	}
	return []int{l, maxPos(mat[l])}
}
```

#### TypeScript

```ts
function findPeakGrid(mat: number[][]): number[] {
    let [l, r] = [0, mat.length - 1];
    while (l < r) {
        const mid = (l + r) >> 1;
        const j = mat[mid].indexOf(Math.max(...mat[mid]));
        if (mat[mid][j] > mat[mid + 1][j]) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return [l, mat[l].indexOf(Math.max(...mat[l]))];
}
```

#### Rust

```rust
impl Solution {
    pub fn find_peak_grid(mat: Vec<Vec<i32>>) -> Vec<i32> {
        let mut l: usize = 0;
        let mut r: usize = mat.len() - 1;
        while l < r {
            let mid: usize = (l + r) >> 1;
            let j: usize = mat[mid]
                .iter()
                .position(|&x| x == *mat[mid].iter().max().unwrap())
                .unwrap();
            if mat[mid][j] > mat[mid + 1][j] {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        let j: usize = mat[l]
            .iter()
            .position(|&x| x == *mat[l].iter().max().unwrap())
            .unwrap();
        vec![l as i32, j as i32]
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1902. 给定二叉搜索树的插入顺序求深度 🔒](https://leetcode.cn/problems/depth-of-bst-given-insertion-order){#1902}

{{< tabs "1902" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxDepthBST(self, order: List[int]) -> int:
        sd = SortedDict({0: 0, inf: 0, order[0]: 1})
        ans = 1
        for v in order[1:]:
            lower = sd.bisect_left(v) - 1
            higher = lower + 1
            depth = 1 + max(sd.values()[lower], sd.values()[higher])
            ans = max(ans, depth)
            sd[v] = depth
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxDepthBST(int[] order) {
        TreeMap<Integer, Integer> tm = new TreeMap<>();
        tm.put(0, 0);
        tm.put(Integer.MAX_VALUE, 0);
        tm.put(order[0], 1);
        int ans = 1;
        for (int i = 1; i < order.length; ++i) {
            int v = order[i];
            Map.Entry<Integer, Integer> lower = tm.lowerEntry(v);
            Map.Entry<Integer, Integer> higher = tm.higherEntry(v);
            int depth = 1 + Math.max(lower.getValue(), higher.getValue());
            ans = Math.max(ans, depth);
            tm.put(v, depth);
        }
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

<p>给定一个<strong>从 0 开始索引</strong>的整数类型数组 <code>order</code> ，其长度为 <code>n</code>，是从 <code>1</code> 到 <code>n</code> 的所有整数的一个排列，表示插入到一棵二叉搜索树的顺序。</p>

<p>二叉搜索树的定义如下：</p>

<ul>
	<li>一个节点的左子树只包含键值<strong>小于</strong>该节点键值的节点。</li>
	<li>一个节点的右子树只包含键值<strong>大于</strong>该节点键值的节点。</li>
	<li>左子树和右子树须均为二叉搜索树。</li>
</ul>

<p>该二叉搜索树的构造方式如下：</p>

<ul>
	<li><code>order[0]</code> 将成为该二叉搜索树的根。</li>
	<li>所有后续的元素均在维持二叉搜索树性质的前提下作为<strong>任何</strong>已存在节点的<strong>子节点</strong>插入。</li>
</ul>

<p>返回该二叉搜索树的<strong>深度</strong>。</p>

<p>一棵二叉树的<strong>深度</strong>是从根节点到最远叶节点的<strong>最长路径</strong>所经<strong>节点</strong>的个数。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1900-1999/1902.Depth%20of%20BST%20Given%20Insertion%20Order/images/1.png" style="width: 624px; height: 154px;" />
<pre>
<strong>输入:</strong> order = [2,1,4,3]
<strong>输出:</strong> 3
<strong>解释: </strong>该二叉搜索树的深度为 3，路径为 2-&gt;4-&gt;3。
</pre>

<p><strong>示例 2:</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1900-1999/1902.Depth%20of%20BST%20Given%20Insertion%20Order/images/2.png" style="width: 624px; height: 146px;" />
<pre>
<strong>输入:</strong> order = [2,1,3,4]
<strong>输出:</strong> 3
<strong>解释: </strong>该二叉搜索树的深度为 3，路径为 2-&gt;3-&gt;4。
</pre>

<p><strong>示例 3:</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1900-1999/1902.Depth%20of%20BST%20Given%20Insertion%20Order/images/3.png" style="width: 624px; height: 225px;" />
<pre>
<strong>输入:</strong> order = [1,2,3,4]
<strong>输出:</strong> 4
<strong>解释: </strong>该二叉搜索树的深度为 4，路径为 1-&gt;2-&gt;3-&gt;4。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == order.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>order</code> 是从 <code>1</code> 到 <code>n</code> 的整数的一个排列。</li>
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
    def maxDepthBST(self, order: List[int]) -> int:
        sd = SortedDict({0: 0, inf: 0, order[0]: 1})
        ans = 1
        for v in order[1:]:
            lower = sd.bisect_left(v) - 1
            higher = lower + 1
            depth = 1 + max(sd.values()[lower], sd.values()[higher])
            ans = max(ans, depth)
            sd[v] = depth
        return ans
```

#### Java

```java
class Solution {
    public int maxDepthBST(int[] order) {
        TreeMap<Integer, Integer> tm = new TreeMap<>();
        tm.put(0, 0);
        tm.put(Integer.MAX_VALUE, 0);
        tm.put(order[0], 1);
        int ans = 1;
        for (int i = 1; i < order.length; ++i) {
            int v = order[i];
            Map.Entry<Integer, Integer> lower = tm.lowerEntry(v);
            Map.Entry<Integer, Integer> higher = tm.higherEntry(v);
            int depth = 1 + Math.max(lower.getValue(), higher.getValue());
            ans = Math.max(ans, depth);
            tm.put(v, depth);
        }
        return ans;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1903. 字符串中的最大奇数](https://leetcode.cn/problems/largest-odd-number-in-string){#1903}

{{< tabs "1903" >}}

{{% tab "python" %}}
```python
class Solution:
    def largestOddNumber(self, num: str) -> str:
        for i in range(len(num) - 1, -1, -1):
            if (int(num[i]) & 1) == 1:
                return num[: i + 1]
        return ''
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String largestOddNumber(String num) {
        for (int i = num.length() - 1; i >= 0; --i) {
            int c = num.charAt(i) - '0';
            if ((c & 1) == 1) {
                return num.substring(0, i + 1);
            }
        }
        return "";
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string largestOddNumber(string num) {
        for (int i = num.size() - 1; i >= 0; --i) {
            int c = num[i] - '0';
            if ((c & 1) == 1) {
                return num.substr(0, i + 1);
            }
        }
        return "";
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func largestOddNumber(num string) string {
	for i := len(num) - 1; i >= 0; i-- {
		c := num[i] - '0'
		if (c & 1) == 1 {
			return num[:i+1]
		}
	}
	return ""
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function largestOddNumber(num: string): string {
    for (let i = num.length - 1; ~i; --i) {
        if (Number(num[i]) & 1) {
            return num.slice(0, i + 1);
        }
    }
    return '';
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {string} num
 * @return {string}
 */
var largestOddNumber = function (num) {
    for (let i = num.length - 1; ~i; --i) {
        if (Number(num[i]) & 1) {
            return num.slice(0, i + 1);
        }
    }
    return '';
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串 <code>num</code> ，表示一个大整数。请你在字符串 <code>num</code> 的所有 <strong>非空子字符串</strong> 中找出 <strong>值最大的奇数</strong> ，并以字符串形式返回。如果不存在奇数，则返回一个空字符串<em> </em><code>""</code><em> </em>。</p>

<p><strong>子字符串</strong> 是字符串中的一个连续的字符序列。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>num = "52"
<strong>输出：</strong>"5"
<strong>解释：</strong>非空子字符串仅有 "5"、"2" 和 "52" 。"5" 是其中唯一的奇数。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>num = "4206"
<strong>输出：</strong>""
<strong>解释：</strong>在 "4206" 中不存在奇数。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>num = "35427"
<strong>输出：</strong>"35427"
<strong>解释：</strong>"35427" 本身就是一个奇数。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= num.length <= 10<sup>5</sup></code></li>
	<li><code>num</code> 仅由数字组成且不含前导零</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：逆序遍历

我们可以从后往前遍历字符串，找到第一个奇数，然后返回从开头到该奇数的子字符串即可。如果不存在奇数，则返回空字符串。

时间复杂度 $O(n)$，其中 $n$ 是字符串 $num$ 的长度。忽略答案字符串的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def largestOddNumber(self, num: str) -> str:
        for i in range(len(num) - 1, -1, -1):
            if (int(num[i]) & 1) == 1:
                return num[: i + 1]
        return ''
```

#### Java

```java
class Solution {
    public String largestOddNumber(String num) {
        for (int i = num.length() - 1; i >= 0; --i) {
            int c = num.charAt(i) - '0';
            if ((c & 1) == 1) {
                return num.substring(0, i + 1);
            }
        }
        return "";
    }
}
```

#### C++

```cpp
class Solution {
public:
    string largestOddNumber(string num) {
        for (int i = num.size() - 1; i >= 0; --i) {
            int c = num[i] - '0';
            if ((c & 1) == 1) {
                return num.substr(0, i + 1);
            }
        }
        return "";
    }
};
```

#### Go

```go
func largestOddNumber(num string) string {
	for i := len(num) - 1; i >= 0; i-- {
		c := num[i] - '0'
		if (c & 1) == 1 {
			return num[:i+1]
		}
	}
	return ""
}
```

#### TypeScript

```ts
function largestOddNumber(num: string): string {
    for (let i = num.length - 1; ~i; --i) {
        if (Number(num[i]) & 1) {
            return num.slice(0, i + 1);
        }
    }
    return '';
}
```

#### JavaScript

```js
/**
 * @param {string} num
 * @return {string}
 */
var largestOddNumber = function (num) {
    for (let i = num.length - 1; ~i; --i) {
        if (Number(num[i]) & 1) {
            return num.slice(0, i + 1);
        }
    }
    return '';
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1904. 你完成的完整对局数](https://leetcode.cn/problems/the-number-of-full-rounds-you-have-played){#1904}

{{< tabs "1904" >}}

{{% tab "python" %}}
```python
class Solution:
    def numberOfRounds(self, loginTime: str, logoutTime: str) -> int:
        def f(s: str) -> int:
            return int(s[:2]) * 60 + int(s[3:])

        a, b = f(loginTime), f(logoutTime)
        if a > b:
            b += 1440
        a, b = (a + 14) // 15, b // 15
        return max(0, b - a)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numberOfRounds(String loginTime, String logoutTime) {
        int a = f(loginTime), b = f(logoutTime);
        if (a > b) {
            b += 1440;
        }
        return Math.max(0, b / 15 - (a + 14) / 15);
    }

    private int f(String s) {
        int h = Integer.parseInt(s.substring(0, 2));
        int m = Integer.parseInt(s.substring(3, 5));
        return h * 60 + m;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int numberOfRounds(string loginTime, string logoutTime) {
        auto f = [](string& s) {
            int h, m;
            sscanf(s.c_str(), "%d:%d", &h, &m);
            return h * 60 + m;
        };
        int a = f(loginTime), b = f(logoutTime);
        if (a > b) {
            b += 1440;
        }
        return max(0, b / 15 - (a + 14) / 15);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numberOfRounds(loginTime string, logoutTime string) int {
	f := func(s string) int {
		var h, m int
		fmt.Sscanf(s, "%d:%d", &h, &m)
		return h*60 + m
	}
	a, b := f(loginTime), f(logoutTime)
	if a > b {
		b += 1440
	}
	return max(0, b/15-(a+14)/15)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numberOfRounds(startTime: string, finishTime: string): number {
    const f = (s: string): number => {
        const [h, m] = s.split(':').map(Number);
        return h * 60 + m;
    };
    let [a, b] = [f(startTime), f(finishTime)];
    if (a > b) {
        b += 1440;
    }
    return Math.max(0, Math.floor(b / 15) - Math.ceil(a / 15));
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>一款新的在线电子游戏在近期发布，在该电子游戏中，以 <strong>刻钟</strong> 为周期规划若干时长为 <strong>15 分钟</strong> 的游戏对局。这意味着，在 <code>HH:00</code>、<code>HH:15</code>、<code>HH:30</code> 和 <code>HH:45</code> ，将会开始一个新的对局，其中 <code>HH</code> 用一个从 <code>00</code> 到 <code>23</code> 的整数表示。游戏中使用 <strong>24 小时制的时钟</strong> ，所以一天中最早的时间是 <code>00:00</code> ，最晚的时间是 <code>23:59</code> 。</p>

<p>给你两个字符串 <code>startTime</code> 和 <code>finishTime</code> ，均符合 <code>"HH:MM"</code> 格式，分别表示你 <strong>进入</strong> 和 <strong>退出</strong> 游戏的确切时间，请计算在整个游戏会话期间，你完成的 <strong>完整对局的对局数</strong> 。</p>

<ul>
	<li>例如，如果 <code>startTime = "05:20"</code> 且 <code>finishTime = "05:59"</code> ，这意味着你仅仅完成从 <code>05:30</code> 到 <code>05:45</code> 这一个完整对局。而你没有完成从 <code>05:15</code> 到 <code>05:30</code> 的完整对局，因为你是在对局开始后进入的游戏；同时，你也没有完成从 <code>05:45</code> 到 <code>06:00</code> 的完整对局，因为你是在对局结束前退出的游戏。</li>
</ul>

<p>如果 <code>finishTime</code> <strong>早于</strong> <code>startTime</code> ，这表示你玩了个通宵（也就是从 <code>startTime</code> 到午夜，再从午夜到 <code>finishTime</code>）。</p>

<p>假设你是从 <code>startTime</code> 进入游戏，并在 <code>finishTime</code> 退出游戏，请计算并返回你完成的 <strong>完整对局的对局数</strong> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>startTime = "12:01", finishTime = "12:44"
<strong>输出：</strong>1
<strong>解释：</strong>你完成了从 12:15 到 12:30 的一个完整对局。
你没有完成从 12:00 到 12:15 的完整对局，因为你是在对局开始后的 12:01 进入的游戏。
你没有完成从 12:30 到 12:45 的完整对局，因为你是在对局结束前的 12:44 退出的游戏。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>startTime = "20:00", finishTime = "06:00"
<strong>输出：</strong>40
<strong>解释：</strong>你完成了从 20:00 到 00:00 的 16 个完整的对局，以及从 00:00 到 06:00 的 24 个完整的对局。
16 + 24 = 40
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>startTime = "00:00", finishTime = "23:59"
<strong>输出：</strong>95
<strong>解释：</strong>除最后一个小时你只完成了 3 个完整对局外，其余每个小时均完成了 4 场完整对局。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>startTime</code> 和 <code>finishTime</code> 的格式为 <code>HH:MM</code></li>
	<li><code>00 <= HH <= 23</code></li>
	<li><code>00 <= MM <= 59</code></li>
	<li><code>startTime</code> 和 <code>finishTime</code> 不相等</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：转换为分钟数

我们可以将输入的字符串转换为分钟数 $a$ 和 $b$，如果 $a > b$，则说明跨越了午夜，需要将 $b$ 加上一天的分钟数 $1440$。

然后我们将 $a$ 向上取整到 $15$ 的倍数，将 $b$ 向下取整到 $15$ 的倍数，最后返回 $b$ 与 $a$ 的差值即可，注意要取 $0$ 和 $b - a$ 中的较大值。

时间复杂度 $O(1)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numberOfRounds(self, loginTime: str, logoutTime: str) -> int:
        def f(s: str) -> int:
            return int(s[:2]) * 60 + int(s[3:])

        a, b = f(loginTime), f(logoutTime)
        if a > b:
            b += 1440
        a, b = (a + 14) // 15, b // 15
        return max(0, b - a)
```

#### Java

```java
class Solution {
    public int numberOfRounds(String loginTime, String logoutTime) {
        int a = f(loginTime), b = f(logoutTime);
        if (a > b) {
            b += 1440;
        }
        return Math.max(0, b / 15 - (a + 14) / 15);
    }

    private int f(String s) {
        int h = Integer.parseInt(s.substring(0, 2));
        int m = Integer.parseInt(s.substring(3, 5));
        return h * 60 + m;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numberOfRounds(string loginTime, string logoutTime) {
        auto f = [](string& s) {
            int h, m;
            sscanf(s.c_str(), "%d:%d", &h, &m);
            return h * 60 + m;
        };
        int a = f(loginTime), b = f(logoutTime);
        if (a > b) {
            b += 1440;
        }
        return max(0, b / 15 - (a + 14) / 15);
    }
};
```

#### Go

```go
func numberOfRounds(loginTime string, logoutTime string) int {
	f := func(s string) int {
		var h, m int
		fmt.Sscanf(s, "%d:%d", &h, &m)
		return h*60 + m
	}
	a, b := f(loginTime), f(logoutTime)
	if a > b {
		b += 1440
	}
	return max(0, b/15-(a+14)/15)
}
```

#### TypeScript

```ts
function numberOfRounds(startTime: string, finishTime: string): number {
    const f = (s: string): number => {
        const [h, m] = s.split(':').map(Number);
        return h * 60 + m;
    };
    let [a, b] = [f(startTime), f(finishTime)];
    if (a > b) {
        b += 1440;
    }
    return Math.max(0, Math.floor(b / 15) - Math.ceil(a / 15));
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1905. 统计子岛屿](https://leetcode.cn/problems/count-sub-islands){#1905}

{{< tabs "1905" >}}

{{% tab "python" %}}
```python
class Solution:
    def countSubIslands(self, grid1: List[List[int]], grid2: List[List[int]]) -> int:
        def dfs(i: int, j: int) -> int:
            ok = grid1[i][j]
            grid2[i][j] = 0
            for a, b in pairwise(dirs):
                x, y = i + a, j + b
                if 0 <= x < m and 0 <= y < n and grid2[x][y] and not dfs(x, y):
                    ok = 0
            return ok

        m, n = len(grid1), len(grid1[0])
        dirs = (-1, 0, 1, 0, -1)
        return sum(dfs(i, j) for i in range(m) for j in range(n) if grid2[i][j])
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private final int[] dirs = {-1, 0, 1, 0, -1};
    private int[][] grid1;
    private int[][] grid2;
    private int m;
    private int n;

    public int countSubIslands(int[][] grid1, int[][] grid2) {
        m = grid1.length;
        n = grid1[0].length;
        this.grid1 = grid1;
        this.grid2 = grid2;
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid2[i][j] == 1) {
                    ans += dfs(i, j);
                }
            }
        }
        return ans;
    }

    private int dfs(int i, int j) {
        int ok = grid1[i][j];
        grid2[i][j] = 0;
        for (int k = 0; k < 4; ++k) {
            int x = i + dirs[k], y = j + dirs[k + 1];
            if (x >= 0 && x < m && y >= 0 && y < n && grid2[x][y] == 1) {
                ok &= dfs(x, y);
            }
        }
        return ok;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size(), n = grid1[0].size();
        int ans = 0;
        int dirs[5] = {-1, 0, 1, 0, -1};
        function<int(int, int)> dfs = [&](int i, int j) {
            int ok = grid1[i][j];
            grid2[i][j] = 0;
            for (int k = 0; k < 4; ++k) {
                int x = i + dirs[k], y = j + dirs[k + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && grid2[x][y]) {
                    ok &= dfs(x, y);
                }
            }
            return ok;
        };
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid2[i][j]) {
                    ans += dfs(i, j);
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
func countSubIslands(grid1 [][]int, grid2 [][]int) (ans int) {
	m, n := len(grid1), len(grid1[0])
	dirs := [5]int{-1, 0, 1, 0, -1}
	var dfs func(i, j int) int
	dfs = func(i, j int) int {
		ok := grid1[i][j]
		grid2[i][j] = 0
		for k := 0; k < 4; k++ {
			x, y := i+dirs[k], j+dirs[k+1]
			if x >= 0 && x < m && y >= 0 && y < n && grid2[x][y] == 1 && dfs(x, y) == 0 {
				ok = 0
			}
		}
		return ok
	}
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if grid2[i][j] == 1 {
				ans += dfs(i, j)
			}
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countSubIslands(grid1: number[][], grid2: number[][]): number {
    const [m, n] = [grid1.length, grid1[0].length];
    let ans = 0;
    const dirs: number[] = [-1, 0, 1, 0, -1];
    const dfs = (i: number, j: number): number => {
        let ok = grid1[i][j];
        grid2[i][j] = 0;
        for (let k = 0; k < 4; ++k) {
            const [x, y] = [i + dirs[k], j + dirs[k + 1]];
            if (x >= 0 && x < m && y >= 0 && y < n && grid2[x][y]) {
                ok &= dfs(x, y);
            }
        }
        return ok;
    };
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; j++) {
            if (grid2[i][j]) {
                ans += dfs(i, j);
            }
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
function countSubIslands(grid1, grid2) {
    const [m, n] = [grid1.length, grid1[0].length];
    let ans = 0;
    const dirs = [-1, 0, 1, 0, -1];
    const dfs = (i, j) => {
        let ok = grid1[i][j];
        grid2[i][j] = 0;
        for (let k = 0; k < 4; ++k) {
            const [x, y] = [i + dirs[k], j + dirs[k + 1]];
            if (x >= 0 && x < m && y >= 0 && y < n && grid2[x][y]) {
                ok &= dfs(x, y);
            }
        }
        return ok;
    };
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; j++) {
            if (grid2[i][j]) {
                ans += dfs(i, j);
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

<p>给你两个 <code>m x n</code> 的二进制矩阵 <code>grid1</code> 和 <code>grid2</code> ，它们只包含 <code>0</code> （表示水域）和 <code>1</code> （表示陆地）。一个 <strong>岛屿</strong> 是由 <strong>四个方向</strong> （水平或者竖直）上相邻的 <code>1</code> 组成的区域。任何矩阵以外的区域都视为水域。</p>

<p>如果 <code>grid2</code> 的一个岛屿，被 <code>grid1</code> 的一个岛屿 <strong>完全</strong> 包含，也就是说 <code>grid2</code> 中该岛屿的每一个格子都被 <code>grid1</code> 中同一个岛屿完全包含，那么我们称 <code>grid2</code> 中的这个岛屿为 <strong>子岛屿</strong> 。</p>

<p>请你返回 <code>grid2</code> 中 <strong>子岛屿</strong> 的 <strong>数目</strong> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1900-1999/1905.Count%20Sub%20Islands/images/test1.png" style="width: 493px; height: 205px;">
<pre><b>输入：</b>grid1 = [[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]], grid2 = [[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]
<b>输出：</b>3
<strong>解释：</strong>如上图所示，左边为 grid1 ，右边为 grid2 。
grid2 中标红的 1 区域是子岛屿，总共有 3 个子岛屿。
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1900-1999/1905.Count%20Sub%20Islands/images/testcasex2.png" style="width: 491px; height: 201px;">
<pre><b>输入：</b>grid1 = [[1,0,1,0,1],[1,1,1,1,1],[0,0,0,0,0],[1,1,1,1,1],[1,0,1,0,1]], grid2 = [[0,0,0,0,0],[1,1,1,1,1],[0,1,0,1,0],[0,1,0,1,0],[1,0,0,0,1]]
<b>输出：</b>2 
<strong>解释：</strong>如上图所示，左边为 grid1 ，右边为 grid2 。
grid2 中标红的 1 区域是子岛屿，总共有 2 个子岛屿。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid1.length == grid2.length</code></li>
	<li><code>n == grid1[i].length == grid2[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 500</code></li>
	<li><code>grid1[i][j]</code> 和 <code>grid2[i][j]</code> 都要么是 <code>0</code> 要么是 <code>1</code> 。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS

我们可以遍历矩阵 `grid2` 中的每一个格子 $(i, j)$，如果该格子为 $1$，则从该格子开始进行深度优先搜索，将与该格子相连的所有格子的值都置为 $0$，并记录与该格子相连的所有格子中，`grid1` 中对应格子的值是否为 $1$，如果为 $1$，则说明该格子在 `grid1` 中也是一个岛屿，否则不是。最后统计 `grid2` 中子岛屿的数量即可。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别是矩阵 `grid1` 和 `grid2` 的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countSubIslands(self, grid1: List[List[int]], grid2: List[List[int]]) -> int:
        def dfs(i: int, j: int) -> int:
            ok = grid1[i][j]
            grid2[i][j] = 0
            for a, b in pairwise(dirs):
                x, y = i + a, j + b
                if 0 <= x < m and 0 <= y < n and grid2[x][y] and not dfs(x, y):
                    ok = 0
            return ok

        m, n = len(grid1), len(grid1[0])
        dirs = (-1, 0, 1, 0, -1)
        return sum(dfs(i, j) for i in range(m) for j in range(n) if grid2[i][j])
```

#### Java

```java
class Solution {
    private final int[] dirs = {-1, 0, 1, 0, -1};
    private int[][] grid1;
    private int[][] grid2;
    private int m;
    private int n;

    public int countSubIslands(int[][] grid1, int[][] grid2) {
        m = grid1.length;
        n = grid1[0].length;
        this.grid1 = grid1;
        this.grid2 = grid2;
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid2[i][j] == 1) {
                    ans += dfs(i, j);
                }
            }
        }
        return ans;
    }

    private int dfs(int i, int j) {
        int ok = grid1[i][j];
        grid2[i][j] = 0;
        for (int k = 0; k < 4; ++k) {
            int x = i + dirs[k], y = j + dirs[k + 1];
            if (x >= 0 && x < m && y >= 0 && y < n && grid2[x][y] == 1) {
                ok &= dfs(x, y);
            }
        }
        return ok;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size(), n = grid1[0].size();
        int ans = 0;
        int dirs[5] = {-1, 0, 1, 0, -1};
        function<int(int, int)> dfs = [&](int i, int j) {
            int ok = grid1[i][j];
            grid2[i][j] = 0;
            for (int k = 0; k < 4; ++k) {
                int x = i + dirs[k], y = j + dirs[k + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && grid2[x][y]) {
                    ok &= dfs(x, y);
                }
            }
            return ok;
        };
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid2[i][j]) {
                    ans += dfs(i, j);
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func countSubIslands(grid1 [][]int, grid2 [][]int) (ans int) {
	m, n := len(grid1), len(grid1[0])
	dirs := [5]int{-1, 0, 1, 0, -1}
	var dfs func(i, j int) int
	dfs = func(i, j int) int {
		ok := grid1[i][j]
		grid2[i][j] = 0
		for k := 0; k < 4; k++ {
			x, y := i+dirs[k], j+dirs[k+1]
			if x >= 0 && x < m && y >= 0 && y < n && grid2[x][y] == 1 && dfs(x, y) == 0 {
				ok = 0
			}
		}
		return ok
	}
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if grid2[i][j] == 1 {
				ans += dfs(i, j)
			}
		}
	}
	return
}
```

#### TypeScript

```ts
function countSubIslands(grid1: number[][], grid2: number[][]): number {
    const [m, n] = [grid1.length, grid1[0].length];
    let ans = 0;
    const dirs: number[] = [-1, 0, 1, 0, -1];
    const dfs = (i: number, j: number): number => {
        let ok = grid1[i][j];
        grid2[i][j] = 0;
        for (let k = 0; k < 4; ++k) {
            const [x, y] = [i + dirs[k], j + dirs[k + 1]];
            if (x >= 0 && x < m && y >= 0 && y < n && grid2[x][y]) {
                ok &= dfs(x, y);
            }
        }
        return ok;
    };
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; j++) {
            if (grid2[i][j]) {
                ans += dfs(i, j);
            }
        }
    }
    return ans;
}
```

#### JavaScript

```js
function countSubIslands(grid1, grid2) {
    const [m, n] = [grid1.length, grid1[0].length];
    let ans = 0;
    const dirs = [-1, 0, 1, 0, -1];
    const dfs = (i, j) => {
        let ok = grid1[i][j];
        grid2[i][j] = 0;
        for (let k = 0; k < 4; ++k) {
            const [x, y] = [i + dirs[k], j + dirs[k + 1]];
            if (x >= 0 && x < m && y >= 0 && y < n && grid2[x][y]) {
                ok &= dfs(x, y);
            }
        }
        return ok;
    };
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; j++) {
            if (grid2[i][j]) {
                ans += dfs(i, j);
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

# [1906. 查询差绝对值的最小值](https://leetcode.cn/problems/minimum-absolute-difference-queries){#1906}

{{< tabs "1906" >}}

{{% tab "python" %}}
```python
class Solution:
    def minDifference(self, nums: List[int], queries: List[List[int]]) -> List[int]:
        m, n = len(nums), len(queries)
        pre_sum = [[0] * 101 for _ in range(m + 1)]
        for i in range(1, m + 1):
            for j in range(1, 101):
                t = 1 if nums[i - 1] == j else 0
                pre_sum[i][j] = pre_sum[i - 1][j] + t

        ans = []
        for i in range(n):
            left, right = queries[i][0], queries[i][1] + 1
            t = inf
            last = -1
            for j in range(1, 101):
                if pre_sum[right][j] - pre_sum[left][j] > 0:
                    if last != -1:
                        t = min(t, j - last)
                    last = j
            if t == inf:
                t = -1
            ans.append(t)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] minDifference(int[] nums, int[][] queries) {
        int m = nums.length, n = queries.length;
        int[][] preSum = new int[m + 1][101];
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= 100; ++j) {
                int t = nums[i - 1] == j ? 1 : 0;
                preSum[i][j] = preSum[i - 1][j] + t;
            }
        }

        int[] ans = new int[n];
        for (int i = 0; i < n; ++i) {
            int left = queries[i][0], right = queries[i][1] + 1;
            int t = Integer.MAX_VALUE;
            int last = -1;
            for (int j = 1; j <= 100; ++j) {
                if (preSum[right][j] > preSum[left][j]) {
                    if (last != -1) {
                        t = Math.min(t, j - last);
                    }
                    last = j;
                }
            }
            if (t == Integer.MAX_VALUE) {
                t = -1;
            }
            ans[i] = t;
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
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        int m = nums.size(), n = queries.size();
        int preSum[m + 1][101];
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= 100; ++j) {
                int t = nums[i - 1] == j ? 1 : 0;
                preSum[i][j] = preSum[i - 1][j] + t;
            }
        }

        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            int left = queries[i][0], right = queries[i][1] + 1;
            int t = 101;
            int last = -1;
            for (int j = 1; j <= 100; ++j) {
                if (preSum[right][j] > preSum[left][j]) {
                    if (last != -1) {
                        t = min(t, j - last);
                    }
                    last = j;
                }
            }
            if (t == 101) {
                t = -1;
            }
            ans[i] = t;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minDifference(nums []int, queries [][]int) []int {
	m, n := len(nums), len(queries)
	preSum := make([][101]int, m+1)
	for i := 1; i <= m; i++ {
		for j := 1; j <= 100; j++ {
			t := 0
			if nums[i-1] == j {
				t = 1
			}
			preSum[i][j] = preSum[i-1][j] + t
		}
	}

	ans := make([]int, n)
	for i := 0; i < n; i++ {
		left, right := queries[i][0], queries[i][1]+1
		t, last := 101, -1
		for j := 1; j <= 100; j++ {
			if preSum[right][j]-preSum[left][j] > 0 {
				if last != -1 {
					if t > j-last {
						t = j - last
					}
				}
				last = j
			}
		}
		if t == 101 {
			t = -1
		}
		ans[i] = t
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minDifference(nums: number[], queries: number[][]): number[] {
    let m = nums.length,
        n = queries.length;
    let max = 100;
    // let max = Math.max(...nums);
    let pre: number[][] = [];
    pre.push(new Array(max + 1).fill(0));
    for (let i = 0; i < m; ++i) {
        let num = nums[i];
        pre.push(pre[i].slice());
        pre[i + 1][num] += 1;
    }

    let ans = [];
    for (let [left, right] of queries) {
        let last = -1;
        let min = Infinity;
        for (let j = 1; j < max + 1; ++j) {
            if (pre[left][j] < pre[right + 1][j]) {
                if (last != -1) {
                    min = Math.min(min, j - last);
                }
                last = j;
            }
        }
        ans.push(min == Infinity ? -1 : min);
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

<p>一个数组 <code>a</code> 的 <strong>差绝对值的最小值</strong> 定义为：<code>0 <= i < j < a.length</code> 且 <code>a[i] != a[j]</code> 的<strong> </strong><code><span style="">|a[i] - a[j]|</span></code> 的 <strong>最小值</strong>。如果 <code>a</code> 中所有元素都 <strong>相同</strong> ，那么差绝对值的最小值为 <code>-1</code> 。</p>

<ul>
	<li>比方说，数组 <code>[5,<strong>2</strong>,<strong>3</strong>,7,2]</code> 差绝对值的最小值是 <code>|2 - 3| = 1</code> 。注意答案不为 <code>0</code> ，因为 <code>a[i]</code> 和 <code>a[j]</code> 必须不相等。</li>
</ul>

<p>给你一个整数数组 <code>nums</code> 和查询数组 <code>queries</code> ，其中 <code>queries[i] = [l<sub>i</sub>, r<sub>i</sub>]</code> 。对于每个查询 <code>i</code> ，计算 <strong>子数组</strong> <code>nums[l<sub>i</sub>...r<sub>i</sub>]</code> 中 <strong>差绝对值的最小值</strong> ，子数组 <code>nums[l<sub>i</sub>...r<sub>i</sub>]</code> 包含 <code>nums</code> 数组（下标从 <strong>0</strong> 开始）中下标在 <code>l<sub>i</sub></code> 和 <code>r<sub>i</sub></code> 之间的所有元素（包含 <code>l<sub>i</sub></code> 和 <code>r<sub>i</sub></code> 在内）。</p>

<p>请你返回 <code>ans</code> <strong>数组</strong>，其中 <code>ans[i]</code> 是第 <code>i</code> 个查询的答案。</p>

<p><strong>子数组</strong> 是一个数组中连续的一段元素。</p>

<p><code>|x|</code> 的值定义为：</p>

<ul>
	<li>如果 <code>x >= 0</code> ，那么值为 <code>x</code> 。</li>
	<li>如果 <code>x < 0</code> ，那么值为 <code>-x</code> 。</li>
</ul>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [1,3,4,8], queries = [[0,1],[1,2],[2,3],[0,3]]
<b>输出：</b>[2,1,4,1]
<b>解释：</b>查询结果如下：
- queries[0] = [0,1]：子数组是 [<strong>1</strong>,<strong>3</strong>] ，差绝对值的最小值为 |1-3| = 2 。
- queries[1] = [1,2]：子数组是 [<strong>3</strong>,<strong>4</strong>] ，差绝对值的最小值为 |3-4| = 1 。
- queries[2] = [2,3]：子数组是 [<strong>4</strong>,<strong>8</strong>] ，差绝对值的最小值为 |4-8| = 4 。
- queries[3] = [0,3]：子数组是 [1,<strong>3</strong>,<strong>4</strong>,8] ，差的绝对值的最小值为 |3-4| = 1 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [4,5,2,2,7,10], queries = [[2,3],[0,2],[0,5],[3,5]]
<b>输出：</b>[-1,1,1,3]
<strong>解释：</strong>查询结果如下：
- queries[0] = [2,3]：子数组是 [2,2] ，差绝对值的最小值为 -1 ，因为所有元素相等。
- queries[1] = [0,2]：子数组是 [<strong>4</strong>,<strong>5</strong>,2] ，差绝对值的最小值为 |4-5| = 1 。
- queries[2] = [0,5]：子数组是 [<strong>4</strong>,<strong>5</strong>,2,2,7,10] ，差绝对值的最小值为 |4-5| = 1 。
- queries[3] = [3,5]：子数组是 [2,<strong>7</strong>,<strong>10</strong>] ，差绝对值的最小值为 |7-10| = 3 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 <= nums.length <= 10<sup>5</sup></code></li>
	<li><code>1 <= nums[i] <= 100</code></li>
	<li><code>1 <= queries.length <= 2 * 10<sup>4</sup></code></li>
	<li><code>0 <= l<sub>i</sub> < r<sub>i</sub> < nums.length</code></li>
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
    def minDifference(self, nums: List[int], queries: List[List[int]]) -> List[int]:
        m, n = len(nums), len(queries)
        pre_sum = [[0] * 101 for _ in range(m + 1)]
        for i in range(1, m + 1):
            for j in range(1, 101):
                t = 1 if nums[i - 1] == j else 0
                pre_sum[i][j] = pre_sum[i - 1][j] + t

        ans = []
        for i in range(n):
            left, right = queries[i][0], queries[i][1] + 1
            t = inf
            last = -1
            for j in range(1, 101):
                if pre_sum[right][j] - pre_sum[left][j] > 0:
                    if last != -1:
                        t = min(t, j - last)
                    last = j
            if t == inf:
                t = -1
            ans.append(t)
        return ans
```

#### Java

```java
class Solution {
    public int[] minDifference(int[] nums, int[][] queries) {
        int m = nums.length, n = queries.length;
        int[][] preSum = new int[m + 1][101];
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= 100; ++j) {
                int t = nums[i - 1] == j ? 1 : 0;
                preSum[i][j] = preSum[i - 1][j] + t;
            }
        }

        int[] ans = new int[n];
        for (int i = 0; i < n; ++i) {
            int left = queries[i][0], right = queries[i][1] + 1;
            int t = Integer.MAX_VALUE;
            int last = -1;
            for (int j = 1; j <= 100; ++j) {
                if (preSum[right][j] > preSum[left][j]) {
                    if (last != -1) {
                        t = Math.min(t, j - last);
                    }
                    last = j;
                }
            }
            if (t == Integer.MAX_VALUE) {
                t = -1;
            }
            ans[i] = t;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        int m = nums.size(), n = queries.size();
        int preSum[m + 1][101];
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= 100; ++j) {
                int t = nums[i - 1] == j ? 1 : 0;
                preSum[i][j] = preSum[i - 1][j] + t;
            }
        }

        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            int left = queries[i][0], right = queries[i][1] + 1;
            int t = 101;
            int last = -1;
            for (int j = 1; j <= 100; ++j) {
                if (preSum[right][j] > preSum[left][j]) {
                    if (last != -1) {
                        t = min(t, j - last);
                    }
                    last = j;
                }
            }
            if (t == 101) {
                t = -1;
            }
            ans[i] = t;
        }
        return ans;
    }
};
```

#### Go

```go
func minDifference(nums []int, queries [][]int) []int {
	m, n := len(nums), len(queries)
	preSum := make([][101]int, m+1)
	for i := 1; i <= m; i++ {
		for j := 1; j <= 100; j++ {
			t := 0
			if nums[i-1] == j {
				t = 1
			}
			preSum[i][j] = preSum[i-1][j] + t
		}
	}

	ans := make([]int, n)
	for i := 0; i < n; i++ {
		left, right := queries[i][0], queries[i][1]+1
		t, last := 101, -1
		for j := 1; j <= 100; j++ {
			if preSum[right][j]-preSum[left][j] > 0 {
				if last != -1 {
					if t > j-last {
						t = j - last
					}
				}
				last = j
			}
		}
		if t == 101 {
			t = -1
		}
		ans[i] = t
	}
	return ans
}
```

#### TypeScript

```ts
function minDifference(nums: number[], queries: number[][]): number[] {
    let m = nums.length,
        n = queries.length;
    let max = 100;
    // let max = Math.max(...nums);
    let pre: number[][] = [];
    pre.push(new Array(max + 1).fill(0));
    for (let i = 0; i < m; ++i) {
        let num = nums[i];
        pre.push(pre[i].slice());
        pre[i + 1][num] += 1;
    }

    let ans = [];
    for (let [left, right] of queries) {
        let last = -1;
        let min = Infinity;
        for (let j = 1; j < max + 1; ++j) {
            if (pre[left][j] < pre[right + 1][j]) {
                if (last != -1) {
                    min = Math.min(min, j - last);
                }
                last = j;
            }
        }
        ans.push(min == Infinity ? -1 : min);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1907. 按分类统计薪水](https://leetcode.cn/problems/count-salary-categories){#1907}

{{< tabs "1907" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT 'Low Salary' AS category, IFNULL(SUM(income < 20000), 0) AS accounts_count FROM Accounts
UNION
SELECT
    'Average Salary' AS category,
    IFNULL(SUM(income BETWEEN 20000 AND 50000), 0) AS accounts_count
FROM Accounts
UNION
SELECT 'High Salary' AS category, IFNULL(SUM(income > 50000), 0) AS accounts_count FROM Accounts;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表: <code>Accounts</code></p>

<pre>
+-------------+------+
| 列名        | 类型  |
+-------------+------+
| account_id  | int  |
| income      | int  |
+-------------+------+
在 SQL 中，account_id&nbsp;是这个表的主键。
每一行都包含一个银行帐户的月收入的信息。
</pre>

<p>&nbsp;</p>

<p>查询每个工资类别的银行账户数量。&nbsp;工资类别如下：</p>

<ul>
	<li><code>"Low Salary"</code>：所有工资 <strong>严格低于</strong> <code>20000</code> 美元。</li>
	<li><code>"Average Salary"</code>： <strong>包含</strong> 范围内的所有工资&nbsp;<code>[$20000,&nbsp;$50000]</code> 。</li>
	<li>
	<p><code>"High Salary"</code>：所有工资 <strong>严格大于</strong> <code>50000</code> 美元。</p>
	</li>
</ul>

<p>结果表 <strong>必须</strong> 包含所有三个类别。&nbsp;如果某个类别中没有帐户，则报告&nbsp;<code>0</code> 。</p>

<p>按 <strong>任意顺序</strong> 返回结果表。</p>

<p>查询结果格式如下示例。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>
Accounts 表:
+------------+--------+
| account_id | income |
+------------+--------+
| 3          | 108939 |
| 2          | 12747  |
| 8          | 87709  |
| 6          | 91796  |
+------------+--------+
<strong>输出：</strong>
+----------------+----------------+
| category       | accounts_count |
+----------------+----------------+
| Low Salary     | 1              |
| Average Salary | 0              |
| High Salary    | 3              |
+----------------+----------------+
<strong>解释：</strong>
低薪: 有一个账户 2.
中等薪水: 没有.
高薪: 有三个账户，他们是 3, 6和 8.</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：构建临时表 + 分组统计 + 左连接

我们可以先构建一个临时表，包含所有工资类别，然后再统计每个工资类别的银行账户数量。最后我们使用左连接，将临时表和统计结果表连接起来，这样就可以保证结果表中包含所有工资类别。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
WITH
    S AS (
        SELECT 'Low Salary' AS category
        UNION
        SELECT 'Average Salary'
        UNION
        SELECT 'High Salary'
    ),
    T AS (
        SELECT
            CASE
                WHEN income < 20000 THEN "Low Salary"
                WHEN income > 50000 THEN 'High Salary'
                ELSE 'Average Salary'
            END AS category,
            COUNT(1) AS accounts_count
        FROM Accounts
        GROUP BY 1
    )
SELECT category, IFNULL(accounts_count, 0) AS accounts_count
FROM
    S
    LEFT JOIN T USING (category);
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：筛选 + 合并

我们可以分别筛选出每个工资类别的银行账户数量，然后再将结果合并起来。这里我们使用 `UNION` 来合并结果。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT 'Low Salary' AS category, IFNULL(SUM(income < 20000), 0) AS accounts_count FROM Accounts
UNION
SELECT
    'Average Salary' AS category,
    IFNULL(SUM(income BETWEEN 20000 AND 50000), 0) AS accounts_count
FROM Accounts
UNION
SELECT 'High Salary' AS category, IFNULL(SUM(income > 50000), 0) AS accounts_count FROM Accounts;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1908. Nim 游戏 II 🔒](https://leetcode.cn/problems/game-of-nim){#1908}

{{< tabs "1908" >}}

{{% tab "python" %}}
```python
class Solution:
    def nimGame(self, piles: List[int]) -> bool:
        @cache
        def dfs(st):
            lst = list(st)
            for i, x in enumerate(lst):
                for j in range(1, x + 1):
                    lst[i] -= j
                    if not dfs(tuple(lst)):
                        return True
                    lst[i] += j
            return False

        return dfs(tuple(piles))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private Map<Integer, Boolean> memo = new HashMap<>();
    private int[] p = new int[8];

    public Solution() {
        p[0] = 1;
        for (int i = 1; i < 8; ++i) {
            p[i] = p[i - 1] * 8;
        }
    }

    public boolean nimGame(int[] piles) {
        return dfs(piles);
    }

    private boolean dfs(int[] piles) {
        int st = f(piles);
        if (memo.containsKey(st)) {
            return memo.get(st);
        }
        for (int i = 0; i < piles.length; ++i) {
            for (int j = 1; j <= piles[i]; ++j) {
                piles[i] -= j;
                if (!dfs(piles)) {
                    piles[i] += j;
                    memo.put(st, true);
                    return true;
                }
                piles[i] += j;
            }
        }
        memo.put(st, false);
        return false;
    }

    private int f(int[] piles) {
        int st = 0;
        for (int i = 0; i < piles.length; ++i) {
            st += piles[i] * p[i];
        }
        return st;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool nimGame(vector<int>& piles) {
        unordered_map<int, int> memo;
        int p[8] = {1};
        for (int i = 1; i < 8; ++i) {
            p[i] = p[i - 1] * 8;
        }
        auto f = [&](vector<int>& piles) {
            int st = 0;
            for (int i = 0; i < piles.size(); ++i) {
                st += piles[i] * p[i];
            }
            return st;
        };
        function<bool(vector<int>&)> dfs = [&](vector<int>& piles) {
            int st = f(piles);
            if (memo.count(st)) {
                return memo[st];
            }
            for (int i = 0; i < piles.size(); ++i) {
                for (int j = 1; j <= piles[i]; ++j) {
                    piles[i] -= j;
                    if (!dfs(piles)) {
                        piles[i] += j;
                        return memo[st] = true;
                    }
                    piles[i] += j;
                }
            }
            return memo[st] = false;
        };
        return dfs(piles);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func nimGame(piles []int) bool {
	memo := map[int]bool{}
	p := make([]int, 8)
	p[0] = 1
	for i := 1; i < 8; i++ {
		p[i] = p[i-1] * 8
	}
	f := func(piles []int) int {
		st := 0
		for i, x := range piles {
			st += x * p[i]
		}
		return st
	}
	var dfs func(piles []int) bool
	dfs = func(piles []int) bool {
		st := f(piles)
		if v, ok := memo[st]; ok {
			return v
		}
		for i, x := range piles {
			for j := 1; j <= x; j++ {
				piles[i] -= j
				if !dfs(piles) {
					piles[i] += j
					memo[st] = true
					return true
				}
				piles[i] += j
			}
		}
		memo[st] = false
		return false
	}
	return dfs(piles)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function nimGame(piles: number[]): boolean {
    const p: number[] = Array(8).fill(1);
    for (let i = 1; i < 8; ++i) {
        p[i] = p[i - 1] * 8;
    }
    const f = (piles: number[]): number => {
        let st = 0;
        for (let i = 0; i < piles.length; ++i) {
            st += piles[i] * p[i];
        }
        return st;
    };
    const memo: Map<number, boolean> = new Map();
    const dfs = (piles: number[]): boolean => {
        const st = f(piles);
        if (memo.has(st)) {
            return memo.get(st)!;
        }
        for (let i = 0; i < piles.length; ++i) {
            for (let j = 1; j <= piles[i]; ++j) {
                piles[i] -= j;
                if (!dfs(piles)) {
                    piles[i] += j;
                    memo.set(st, true);
                    return true;
                }
                piles[i] += j;
            }
        }
        memo.set(st, false);
        return false;
    };
    return dfs(piles);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>Alice 和&nbsp;Bob 交替进行一个游戏，<strong>由 Alice 先手</strong>。</p>

<p>在游戏中，共有&nbsp;<code>n</code>&nbsp;堆石头。在每个玩家的回合中，玩家需要 <strong>选择</strong> 任一非空石头堆，从中移除任意 <strong>非零</strong> 数量的石头。如果不能移除任意的石头，就输掉游戏，同时另一人获胜。</p>

<p>给定一个整数数组&nbsp;<code>piles</code> ，<code>piles[i]</code> 为 第&nbsp;<code>i</code>&nbsp;堆石头的数量，如果 Alice 能获胜返回&nbsp;<code>true</code><em>&nbsp;</em>，反之返回&nbsp;<code>false</code><em>&nbsp;。</em></p>

<p>Alice 和 Bob 都会采取<strong> 最优策略 </strong>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>piles = [1]
<strong>输出：</strong>true
<strong>解释：</strong>只有一种可能的情况：
- 第一回合，Alice 移除了第 1 堆中 1 块石头。piles = [0]。
- 第二回合，Bob 没有任何石头可以移除。Alice 获胜。
</pre>

<p><strong>示例&nbsp;2：</strong></p>

<pre>
<strong>输入：</strong>piles = [1,1]
<strong>输出：</strong>false
<strong>解释：</strong>可以证明，Bob一定能获胜。一种可能的情况：
- 第一回合，Alice 移除了第 1 堆中 1 块石头。 piles = [0,1]。
- 第二回合，Bob 移除了第 2 堆中 1 块石头。 piles = [0,0]。
- 第三回合，Alice 没有任何石头可以移除。Bob 获胜。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>piles = [1,2,3]
<strong>输出：</strong>false
<strong>解释：</strong>可以证明，Bob一定能获胜。一种可能的情况：
- 第一回合，Alice 移除了第 3 堆中 3 块石头。 piles = [1,2,0]。
- 第二回合，Bob 移除了第 2 堆中 1 块石头。 piles = [1,1,0]。
- 第三回合，Alice 移除了第 1 堆中 1 块石头。piles = [0,1,0]。
- 第四回合，Bob 移除了第 2 堆中 1 块石头。 piles = [0,0,0]。
- 第三回合，Alice 没有任何石头可以移除。Bob 获胜。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == piles.length</code></li>
	<li><code>1 &lt;= n &lt;= 7</code></li>
	<li><code>1 &lt;= piles[i] &lt;= 7</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>你能想出一个&nbsp;<strong>线性时间&nbsp;</strong>的解决方案吗？虽然这一答案可能超出了面试所需的范围，但了解它可能会很有趣。</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

我们发现，一共最多有 $7$ 堆石头，每堆石头最多有 $7$ 个，那么一共有 $7^7$ 种状态，因此我们可以用一个八进制数来表示当前的状态。

接下来，我们用记忆化搜索的方法来解决这个问题。定义一个函数 $dfs(piles)$，表示当前的状态为 $piles$ 时，当前玩家是否能获胜。

函数 $dfs(piles)$ 的执行过程如下：

-   如果 $piles$ 所表示的状态已经被计算过，直接返回结果；
-   否则，我们枚举每一堆石头，尝试移除 $1,2,3,...,x$ 个石头，如果移除后的状态 $piles'$ 不能获胜，那么当前玩家就能获胜，返回结果。
-   如果所有的移除方案都不能获胜，那么当前玩家不能获胜，返回结果。

时间复杂度 $(7^7 \times 7^2)$，空间复杂度 $O(7^7)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def nimGame(self, piles: List[int]) -> bool:
        @cache
        def dfs(st):
            lst = list(st)
            for i, x in enumerate(lst):
                for j in range(1, x + 1):
                    lst[i] -= j
                    if not dfs(tuple(lst)):
                        return True
                    lst[i] += j
            return False

        return dfs(tuple(piles))
```

#### Java

```java
class Solution {
    private Map<Integer, Boolean> memo = new HashMap<>();
    private int[] p = new int[8];

    public Solution() {
        p[0] = 1;
        for (int i = 1; i < 8; ++i) {
            p[i] = p[i - 1] * 8;
        }
    }

    public boolean nimGame(int[] piles) {
        return dfs(piles);
    }

    private boolean dfs(int[] piles) {
        int st = f(piles);
        if (memo.containsKey(st)) {
            return memo.get(st);
        }
        for (int i = 0; i < piles.length; ++i) {
            for (int j = 1; j <= piles[i]; ++j) {
                piles[i] -= j;
                if (!dfs(piles)) {
                    piles[i] += j;
                    memo.put(st, true);
                    return true;
                }
                piles[i] += j;
            }
        }
        memo.put(st, false);
        return false;
    }

    private int f(int[] piles) {
        int st = 0;
        for (int i = 0; i < piles.length; ++i) {
            st += piles[i] * p[i];
        }
        return st;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool nimGame(vector<int>& piles) {
        unordered_map<int, int> memo;
        int p[8] = {1};
        for (int i = 1; i < 8; ++i) {
            p[i] = p[i - 1] * 8;
        }
        auto f = [&](vector<int>& piles) {
            int st = 0;
            for (int i = 0; i < piles.size(); ++i) {
                st += piles[i] * p[i];
            }
            return st;
        };
        function<bool(vector<int>&)> dfs = [&](vector<int>& piles) {
            int st = f(piles);
            if (memo.count(st)) {
                return memo[st];
            }
            for (int i = 0; i < piles.size(); ++i) {
                for (int j = 1; j <= piles[i]; ++j) {
                    piles[i] -= j;
                    if (!dfs(piles)) {
                        piles[i] += j;
                        return memo[st] = true;
                    }
                    piles[i] += j;
                }
            }
            return memo[st] = false;
        };
        return dfs(piles);
    }
};
```

#### Go

```go
func nimGame(piles []int) bool {
	memo := map[int]bool{}
	p := make([]int, 8)
	p[0] = 1
	for i := 1; i < 8; i++ {
		p[i] = p[i-1] * 8
	}
	f := func(piles []int) int {
		st := 0
		for i, x := range piles {
			st += x * p[i]
		}
		return st
	}
	var dfs func(piles []int) bool
	dfs = func(piles []int) bool {
		st := f(piles)
		if v, ok := memo[st]; ok {
			return v
		}
		for i, x := range piles {
			for j := 1; j <= x; j++ {
				piles[i] -= j
				if !dfs(piles) {
					piles[i] += j
					memo[st] = true
					return true
				}
				piles[i] += j
			}
		}
		memo[st] = false
		return false
	}
	return dfs(piles)
}
```

#### TypeScript

```ts
function nimGame(piles: number[]): boolean {
    const p: number[] = Array(8).fill(1);
    for (let i = 1; i < 8; ++i) {
        p[i] = p[i - 1] * 8;
    }
    const f = (piles: number[]): number => {
        let st = 0;
        for (let i = 0; i < piles.length; ++i) {
            st += piles[i] * p[i];
        }
        return st;
    };
    const memo: Map<number, boolean> = new Map();
    const dfs = (piles: number[]): boolean => {
        const st = f(piles);
        if (memo.has(st)) {
            return memo.get(st)!;
        }
        for (let i = 0; i < piles.length; ++i) {
            for (let j = 1; j <= piles[i]; ++j) {
                piles[i] -= j;
                if (!dfs(piles)) {
                    piles[i] += j;
                    memo.set(st, true);
                    return true;
                }
                piles[i] += j;
            }
        }
        memo.set(st, false);
        return false;
    };
    return dfs(piles);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1909. 删除一个元素使数组严格递增](https://leetcode.cn/problems/remove-one-element-to-make-the-array-strictly-increasing){#1909}

{{< tabs "1909" >}}

{{% tab "python" %}}
```python
class Solution:
    def canBeIncreasing(self, nums: List[int]) -> bool:
        def check(k: int) -> bool:
            pre = -inf
            for i, x in enumerate(nums):
                if i == k:
                    continue
                if pre >= x:
                    return False
                pre = x
            return True

        i = 0
        while i + 1 < len(nums) and nums[i] < nums[i + 1]:
            i += 1
        return check(i) or check(i + 1)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean canBeIncreasing(int[] nums) {
        int i = 0;
        while (i + 1 < nums.length && nums[i] < nums[i + 1]) {
            ++i;
        }
        return check(nums, i) || check(nums, i + 1);
    }

    private boolean check(int[] nums, int k) {
        int pre = 0;
        for (int i = 0; i < nums.length; ++i) {
            if (i == k) {
                continue;
            }
            if (pre >= nums[i]) {
                return false;
            }
            pre = nums[i];
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
    bool canBeIncreasing(vector<int>& nums) {
        int n = nums.size();
        auto check = [&](int k) -> bool {
            int pre = 0;
            for (int i = 0; i < n; ++i) {
                if (i == k) {
                    continue;
                }
                if (pre >= nums[i]) {
                    return false;
                }
                pre = nums[i];
            }
            return true;
        };
        int i = 0;
        while (i + 1 < n && nums[i] < nums[i + 1]) {
            ++i;
        }
        return check(i) || check(i + 1);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func canBeIncreasing(nums []int) bool {
	check := func(k int) bool {
		pre := 0
		for i, x := range nums {
			if i == k {
				continue
			}
			if pre >= x {
				return false
			}
			pre = x
		}
		return true
	}
	i := 0
	for i+1 < len(nums) && nums[i] < nums[i+1] {
		i++
	}
	return check(i) || check(i+1)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function canBeIncreasing(nums: number[]): boolean {
    const n = nums.length;
    const check = (k: number): boolean => {
        let pre = 0;
        for (let i = 0; i < n; ++i) {
            if (i === k) {
                continue;
            }
            if (pre >= nums[i]) {
                return false;
            }
            pre = nums[i];
        }
        return true;
    };
    let i = 0;
    while (i + 1 < n && nums[i] < nums[i + 1]) {
        ++i;
    }
    return check(i) || check(i + 1);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn can_be_increasing(nums: Vec<i32>) -> bool {
        let check = |k: usize| -> bool {
            let mut pre = 0;
            for (i, &x) in nums.iter().enumerate() {
                if i == k {
                    continue;
                }
                if pre >= x {
                    return false;
                }
                pre = x;
            }
            true
        };

        let mut i = 0;
        while i + 1 < nums.len() && nums[i] < nums[i + 1] {
            i += 1;
        }
        check(i) || check(i + 1)
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public bool CanBeIncreasing(int[] nums) {
        int n = nums.Length;
        bool check(int k) {
            int pre = 0;
            for (int i = 0; i < n; ++i) {
                if (i == k) {
                    continue;
                }
                if (pre >= nums[i]) {
                    return false;
                }
                pre = nums[i];
            }
            return true;
        }
        int i = 0;
        while (i + 1 < n && nums[i] < nums[i + 1]) {
            ++i;
        }
        return check(i) || check(i + 1);
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong> 开始的整数数组 <code>nums</code> ，如果 <strong>恰好</strong> 删除 <strong>一个</strong> 元素后，数组 <strong>严格递增</strong> ，那么请你返回 <code>true</code> ，否则返回 <code>false</code> 。如果数组本身已经是严格递增的，请你也返回 <code>true</code> 。</p>

<p>数组 <code>nums</code> 是 <strong>严格递增</strong> 的定义为：对于任意下标的 <code>1 &lt;= i &lt; nums.length</code> 都满足 <code>nums[i - 1] &lt; nums[i]</code> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [1,2,<strong>10</strong>,5,7]
<b>输出：</b>true
<b>解释：</b>从 nums 中删除下标 2 处的 10 ，得到 [1,2,5,7] 。
[1,2,5,7] 是严格递增的，所以返回 true 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [2,3,1,2]
<b>输出：</b>false
<b>解释：</b>
[3,1,2] 是删除下标 0 处元素后得到的结果。
[2,1,2] 是删除下标 1 处元素后得到的结果。
[2,3,2] 是删除下标 2 处元素后得到的结果。
[2,3,1] 是删除下标 3 处元素后得到的结果。
没有任何结果数组是严格递增的，所以返回 false 。</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>nums = [1,1,1]
<b>输出：</b>false
<b>解释：</b>删除任意元素后的结果都是 [1,1] 。
[1,1] 不是严格递增的，所以返回 false 。
</pre>

<p><strong>示例 4：</strong></p>

<pre><b>输入：</b>nums = [1,2,3]
<b>输出：</b>true
<b>解释：</b>[1,2,3] 已经是严格递增的，所以返回 true 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：遍历

我们可以遍历数组，找到第一个不满足 $\textit{nums}[i] < \textit{nums}[i+1]$ 的位置 $i$，然后检查删除 $i$ 或者 $i+1$ 后的数组是否严格递增，如果是则返回 $\textit{true}$，否则返回 $\textit{false}$。

时间复杂度 $O(n)$，其中 $n$ 是数组 $\textit{nums}$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def canBeIncreasing(self, nums: List[int]) -> bool:
        def check(k: int) -> bool:
            pre = -inf
            for i, x in enumerate(nums):
                if i == k:
                    continue
                if pre >= x:
                    return False
                pre = x
            return True

        i = 0
        while i + 1 < len(nums) and nums[i] < nums[i + 1]:
            i += 1
        return check(i) or check(i + 1)
```

#### Java

```java
class Solution {
    public boolean canBeIncreasing(int[] nums) {
        int i = 0;
        while (i + 1 < nums.length && nums[i] < nums[i + 1]) {
            ++i;
        }
        return check(nums, i) || check(nums, i + 1);
    }

    private boolean check(int[] nums, int k) {
        int pre = 0;
        for (int i = 0; i < nums.length; ++i) {
            if (i == k) {
                continue;
            }
            if (pre >= nums[i]) {
                return false;
            }
            pre = nums[i];
        }
        return true;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int n = nums.size();
        auto check = [&](int k) -> bool {
            int pre = 0;
            for (int i = 0; i < n; ++i) {
                if (i == k) {
                    continue;
                }
                if (pre >= nums[i]) {
                    return false;
                }
                pre = nums[i];
            }
            return true;
        };
        int i = 0;
        while (i + 1 < n && nums[i] < nums[i + 1]) {
            ++i;
        }
        return check(i) || check(i + 1);
    }
};
```

#### Go

```go
func canBeIncreasing(nums []int) bool {
	check := func(k int) bool {
		pre := 0
		for i, x := range nums {
			if i == k {
				continue
			}
			if pre >= x {
				return false
			}
			pre = x
		}
		return true
	}
	i := 0
	for i+1 < len(nums) && nums[i] < nums[i+1] {
		i++
	}
	return check(i) || check(i+1)
}
```

#### TypeScript

```ts
function canBeIncreasing(nums: number[]): boolean {
    const n = nums.length;
    const check = (k: number): boolean => {
        let pre = 0;
        for (let i = 0; i < n; ++i) {
            if (i === k) {
                continue;
            }
            if (pre >= nums[i]) {
                return false;
            }
            pre = nums[i];
        }
        return true;
    };
    let i = 0;
    while (i + 1 < n && nums[i] < nums[i + 1]) {
        ++i;
    }
    return check(i) || check(i + 1);
}
```

#### Rust

```rust
impl Solution {
    pub fn can_be_increasing(nums: Vec<i32>) -> bool {
        let check = |k: usize| -> bool {
            let mut pre = 0;
            for (i, &x) in nums.iter().enumerate() {
                if i == k {
                    continue;
                }
                if pre >= x {
                    return false;
                }
                pre = x;
            }
            true
        };

        let mut i = 0;
        while i + 1 < nums.len() && nums[i] < nums[i + 1] {
            i += 1;
        }
        check(i) || check(i + 1)
    }
}
```

#### C#

```cs
public class Solution {
    public bool CanBeIncreasing(int[] nums) {
        int n = nums.Length;
        bool check(int k) {
            int pre = 0;
            for (int i = 0; i < n; ++i) {
                if (i == k) {
                    continue;
                }
                if (pre >= nums[i]) {
                    return false;
                }
                pre = nums[i];
            }
            return true;
        }
        int i = 0;
        while (i + 1 < n && nums[i] < nums[i + 1]) {
            ++i;
        }
        return check(i) || check(i + 1);
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
