---
title: "0780_到达终点"
date: 2025-10-08T18:36:29+08:00
weight: 9
tags: [二分查找, 二叉搜索树, 二叉树, 位运算, 动态规划, 双指针, 哈希表, 回溯, 图, 堆（优先队列）, 字符串, 并查集, 广度优先搜索, 排序, 数学, 数组, 最短路, 树, 深度优先搜索, 矩阵, 贪心]
---

{{< markmap >}}
### [0780_到达终点](#780)
#### [数学](#780)
### [0781_森林中的兔子](#781)
#### [贪心](#781)
#### [数组](#781)
#### [哈希表](#781)
#### [数学](#781)
### [0782_变为棋盘](#782)
#### [位运算](#782)
#### [数组](#782)
#### [数学](#782)
#### [矩阵](#782)
### [0783_二叉搜索树节点最小距离](#783)
#### [树](#783)
#### [深度优先搜索](#783)
#### [广度优先搜索](#783)
#### [二叉搜索树](#783)
#### [二叉树](#783)
### [0784_字母大小写全排列](#784)
#### [位运算](#784)
#### [字符串](#784)
#### [回溯](#784)
### [0785_判断二分图](#785)
#### [深度优先搜索](#785)
#### [广度优先搜索](#785)
#### [并查集](#785)
#### [图](#785)
### [0786_第 K 个最小的质数分数](#786)
#### [数组](#786)
#### [双指针](#786)
#### [二分查找](#786)
#### [排序](#786)
#### [堆（优先队列）](#786)
### [0787_K 站中转内最便宜的航班](#787)
#### [深度优先搜索](#787)
#### [广度优先搜索](#787)
#### [图](#787)
#### [动态规划](#787)
#### [最短路](#787)
#### [堆（优先队列）](#787)
### [0788_旋转数字](#788)
#### [数学](#788)
#### [动态规划](#788)
### [0789_逃脱阻碍者](#789)
#### [数组](#789)
#### [数学](#789)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0780_到达终点
___
#### 数学
---
### 0781_森林中的兔子
___
#### 贪心
___
#### 数组
___
#### 哈希表
___
#### 数学
---
### 0782_变为棋盘
___
#### 位运算
___
#### 数组
___
#### 数学
___
#### 矩阵
---
### 0783_二叉搜索树节点最小距离
___
#### 树
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 二叉搜索树
___
#### 二叉树
---
### 0784_字母大小写全排列
___
#### 位运算
___
#### 字符串
___
#### 回溯
---
### 0785_判断二分图
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 并查集
___
#### 图
---
### 0786_第 K 个最小的质数分数
___
#### 数组
___
#### 双指针
___
#### 二分查找
___
#### 排序
___
#### 堆（优先队列）
---
### 0787_K 站中转内最便宜的航班
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 图
___
#### 动态规划
___
#### 最短路
___
#### 堆（优先队列）
---
### 0788_旋转数字
___
#### 数学
___
#### 动态规划
---
### 0789_逃脱阻碍者
___
#### 数组
___
#### 数学
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 二叉搜索树 | 二叉树 |
| 位运算 | 动态规划 | 双指针 |
| 哈希表 | 回溯 | 图 |
| 堆（优先队列） | 字符串 | 并查集 |
| 广度优先搜索 | 排序 | 数学 |
| 数组 | 最短路 | 树 |
| 深度优先搜索 | 矩阵 | 贪心 |

# [780. 到达终点](https://leetcode.cn/problems/reaching-points){#780}

{{< tabs "780" >}}

{{% tab "python" %}}
```python
class Solution:
    def reachingPoints(self, sx: int, sy: int, tx: int, ty: int) -> bool:
        while tx > sx and ty > sy and tx != ty:
            if tx > ty:
                tx %= ty
            else:
                ty %= tx
        if tx == sx and ty == sy:
            return True
        if tx == sx:
            return ty > sy and (ty - sy) % tx == 0
        if ty == sy:
            return tx > sx and (tx - sx) % ty == 0
        return False
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean reachingPoints(int sx, int sy, int tx, int ty) {
        while (tx > sx && ty > sy && tx != ty) {
            if (tx > ty) {
                tx %= ty;
            } else {
                ty %= tx;
            }
        }
        if (tx == sx && ty == sy) {
            return true;
        }
        if (tx == sx) {
            return ty > sy && (ty - sy) % tx == 0;
        }
        if (ty == sy) {
            return tx > sx && (tx - sx) % ty == 0;
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
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (tx > sx && ty > sy && tx != ty) {
            if (tx > ty)
                tx %= ty;
            else
                ty %= tx;
        }
        if (tx == sx && ty == sy) return true;
        if (tx == sx) return ty > sy && (ty - sy) % tx == 0;
        if (ty == sy) return tx > sx && (tx - sx) % ty == 0;
        return false;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func reachingPoints(sx int, sy int, tx int, ty int) bool {
	for tx > sx && ty > sy && tx != ty {
		if tx > ty {
			tx %= ty
		} else {
			ty %= tx
		}
	}
	if tx == sx && ty == sy {
		return true
	}
	if tx == sx {
		return ty > sy && (ty-sy)%tx == 0
	}
	if ty == sy {
		return tx > sx && (tx-sx)%ty == 0
	}
	return false
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定四个整数&nbsp;<code>sx</code>&nbsp;,&nbsp;<code>sy</code>&nbsp;，<code>tx</code>&nbsp;和&nbsp;<code>ty</code>，如果通过一系列的<strong>转换</strong>可以从起点&nbsp;<code>(sx, sy)</code>&nbsp;到达终点&nbsp;<code>(tx, ty)</code>，则返回 <code>true</code>，否则返回&nbsp;<code>false</code>。</p>

<p>从点&nbsp;<code>(x, y)</code>&nbsp;可以<strong>转换</strong>到&nbsp;<code>(x, x+y)</code>&nbsp; 或者&nbsp;<code>(x+y, y)</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> sx = 1, sy = 1, tx = 3, ty = 5
<strong>输出:</strong> true
<strong>解释:
</strong>可以通过以下一系列<strong>转换</strong>从起点转换到终点：
(1, 1) -&gt; (1, 2)
(1, 2) -&gt; (3, 2)
(3, 2) -&gt; (3, 5)
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> sx = 1, sy = 1, tx = 2, ty = 2 
<strong>输出:</strong> false
</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入:</strong> sx = 1, sy = 1, tx = 1, ty = 1 
<strong>输出:</strong> true
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= sx, sy, tx, ty &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：逆向计算

从 `(tx, ty)` 开始逆向计算，判断是否可以到达状态 `(sx, sy)`。由于逆向计算是将 tx, ty 中的较大值减少，因此当 `tx > ty` 时可以直接将 tx 的值更新为 `tx % ty`，当 `tx < ty` 时可以将 ty 的值更新为 `ty % tx`。逆向计算需要满足 `tx > sx && ty > sy && tx != ty`。

当条件不成立时，根据此时 tx 和 ty 判断是否可以从起点转换到终点。

-   如果 `tx == sx && ty == sy`，说明此时已经到达起点状态，返回 true；
-   如果 `tx == sx`，若 `ty > sy && (ty - sy) % tx == 0`，返回 true，否则返回 false；
-   如果 `ty == sy`，若 `tx > sx && (tx - sx) % ty == 0`，返回 true，否则返回 false；
-   如果 `tx ≠ sx && ty ≠ sy`，则不可以从起点转换到终点。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def reachingPoints(self, sx: int, sy: int, tx: int, ty: int) -> bool:
        while tx > sx and ty > sy and tx != ty:
            if tx > ty:
                tx %= ty
            else:
                ty %= tx
        if tx == sx and ty == sy:
            return True
        if tx == sx:
            return ty > sy and (ty - sy) % tx == 0
        if ty == sy:
            return tx > sx and (tx - sx) % ty == 0
        return False
```

#### Java

```java
class Solution {
    public boolean reachingPoints(int sx, int sy, int tx, int ty) {
        while (tx > sx && ty > sy && tx != ty) {
            if (tx > ty) {
                tx %= ty;
            } else {
                ty %= tx;
            }
        }
        if (tx == sx && ty == sy) {
            return true;
        }
        if (tx == sx) {
            return ty > sy && (ty - sy) % tx == 0;
        }
        if (ty == sy) {
            return tx > sx && (tx - sx) % ty == 0;
        }
        return false;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (tx > sx && ty > sy && tx != ty) {
            if (tx > ty)
                tx %= ty;
            else
                ty %= tx;
        }
        if (tx == sx && ty == sy) return true;
        if (tx == sx) return ty > sy && (ty - sy) % tx == 0;
        if (ty == sy) return tx > sx && (tx - sx) % ty == 0;
        return false;
    }
};
```

#### Go

```go
func reachingPoints(sx int, sy int, tx int, ty int) bool {
	for tx > sx && ty > sy && tx != ty {
		if tx > ty {
			tx %= ty
		} else {
			ty %= tx
		}
	}
	if tx == sx && ty == sy {
		return true
	}
	if tx == sx {
		return ty > sy && (ty-sy)%tx == 0
	}
	if ty == sy {
		return tx > sx && (tx-sx)%ty == 0
	}
	return false
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [781. 森林中的兔子](https://leetcode.cn/problems/rabbits-in-forest){#781}

{{< tabs "781" >}}

{{% tab "python" %}}
```python
class Solution:
    def numRabbits(self, answers: List[int]) -> int:
        cnt = Counter(answers)
        ans = 0
        for x, v in cnt.items():
            group = x + 1
            ans += (v + group - 1) // group * group
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numRabbits(int[] answers) {
        Map<Integer, Integer> cnt = new HashMap<>();
        for (int x : answers) {
            cnt.merge(x, 1, Integer::sum);
        }
        int ans = 0;
        for (var e : cnt.entrySet()) {
            int group = e.getKey() + 1;
            ans += (e.getValue() + group - 1) / group * group;
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
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> cnt;
        for (int x : answers) {
            ++cnt[x];
        }
        int ans = 0;
        for (auto& [x, v] : cnt) {
            int group = x + 1;
            ans += (v + group - 1) / group * group;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numRabbits(answers []int) (ans int) {
	cnt := map[int]int{}
	for _, x := range answers {
		cnt[x]++
	}
	for x, v := range cnt {
		group := x + 1
		ans += (v + group - 1) / group * group
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numRabbits(answers: number[]): number {
    const cnt: Record<number, number> = {};
    let ans = 0;

    for (const x of answers) {
        if (cnt[x]) {
            cnt[x]--;
        } else {
            cnt[x] = x;
            ans += x + 1;
        }
    }

    return ans;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
function numRabbits(answers) {
    const cnt = {};
    let ans = 0;

    for (const x of answers) {
        if (cnt[x]) {
            cnt[x]--;
        } else {
            cnt[x] = x;
            ans += x + 1;
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

<p>森林中有未知数量的兔子。提问其中若干只兔子<strong> "还有多少只兔子与你（指被提问的兔子）颜色相同?"</strong> ，将答案收集到一个整数数组 <code>answers</code> 中，其中 <code>answers[i]</code> 是第 <code>i</code> 只兔子的回答。</p>

<p>给你数组 <code>answers</code> ，返回森林中兔子的最少数量。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>answers = [1,1,2]
<strong>输出：</strong>5
<strong>解释：</strong>
两只回答了 "1" 的兔子可能有相同的颜色，设为红色。 
之后回答了 "2" 的兔子不会是红色，否则他们的回答会相互矛盾。
设回答了 "2" 的兔子为蓝色。 
此外，森林中还应有另外 2 只蓝色兔子的回答没有包含在数组中。 
因此森林中兔子的最少数量是 5 只：3 只回答的和 2 只没有回答的。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>answers = [10,10,10]
<strong>输出：</strong>11
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= answers.length &lt;= 1000</code></li>
	<li><code>0 &lt;= answers[i] &lt; 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 哈希表

根据题目描述，回答相同的兔子，可能属于同一种颜色，而回答不同的兔子，不可能属于同一种颜色。

因此，我们用一个哈希表 $\textit{cnt}$ 记录每种回答出现的次数。对于每种回答 $x$ 及其出现次数 $v$，我们按照每种颜色有 $x + 1$ 只兔子的原则，计算出兔子的最少数量，并将其加入答案。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $\textit{answers}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numRabbits(self, answers: List[int]) -> int:
        cnt = Counter(answers)
        ans = 0
        for x, v in cnt.items():
            group = x + 1
            ans += (v + group - 1) // group * group
        return ans
```

#### Java

```java
class Solution {
    public int numRabbits(int[] answers) {
        Map<Integer, Integer> cnt = new HashMap<>();
        for (int x : answers) {
            cnt.merge(x, 1, Integer::sum);
        }
        int ans = 0;
        for (var e : cnt.entrySet()) {
            int group = e.getKey() + 1;
            ans += (e.getValue() + group - 1) / group * group;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> cnt;
        for (int x : answers) {
            ++cnt[x];
        }
        int ans = 0;
        for (auto& [x, v] : cnt) {
            int group = x + 1;
            ans += (v + group - 1) / group * group;
        }
        return ans;
    }
};
```

#### Go

```go
func numRabbits(answers []int) (ans int) {
	cnt := map[int]int{}
	for _, x := range answers {
		cnt[x]++
	}
	for x, v := range cnt {
		group := x + 1
		ans += (v + group - 1) / group * group
	}
	return
}
```

#### TypeScript

```ts
function numRabbits(answers: number[]): number {
    const cnt = new Map<number, number>();
    for (const x of answers) {
        cnt.set(x, (cnt.get(x) || 0) + 1);
    }
    let ans = 0;
    for (const [x, v] of cnt.entries()) {
        const group = x + 1;
        ans += Math.floor((v + group - 1) / group) * group;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

### Solution 2: Greedy + Hash Map

<!-- tabs:start -->

#### TypeScript

```ts
function numRabbits(answers: number[]): number {
    const cnt: Record<number, number> = {};
    let ans = 0;

    for (const x of answers) {
        if (cnt[x]) {
            cnt[x]--;
        } else {
            cnt[x] = x;
            ans += x + 1;
        }
    }

    return ans;
}
```

#### JavaScript

```js
function numRabbits(answers) {
    const cnt = {};
    let ans = 0;

    for (const x of answers) {
        if (cnt[x]) {
            cnt[x]--;
        } else {
            cnt[x] = x;
            ans += x + 1;
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

# [782. 变为棋盘](https://leetcode.cn/problems/transform-to-chessboard){#782}

{{< tabs "782" >}}

{{% tab "python" %}}
```python
class Solution:
    def movesToChessboard(self, board: List[List[int]]) -> int:
        def f(mask, cnt):
            ones = mask.bit_count()
            if n & 1:
                if abs(n - 2 * ones) != 1 or abs(n - 2 * cnt) != 1:
                    return -1
                if ones == n // 2:
                    return n // 2 - (mask & 0xAAAAAAAA).bit_count()
                return (n + 1) // 2 - (mask & 0x55555555).bit_count()
            else:
                if ones != n // 2 or cnt != n // 2:
                    return -1
                cnt0 = n // 2 - (mask & 0xAAAAAAAA).bit_count()
                cnt1 = n // 2 - (mask & 0x55555555).bit_count()
                return min(cnt0, cnt1)

        n = len(board)
        mask = (1 << n) - 1
        rowMask = colMask = 0
        for i in range(n):
            rowMask |= board[0][i] << i
            colMask |= board[i][0] << i
        revRowMask = mask ^ rowMask
        revColMask = mask ^ colMask
        sameRow = sameCol = 0
        for i in range(n):
            curRowMask = curColMask = 0
            for j in range(n):
                curRowMask |= board[i][j] << j
                curColMask |= board[j][i] << j
            if curRowMask not in (rowMask, revRowMask) or curColMask not in (
                colMask,
                revColMask,
            ):
                return -1
            sameRow += curRowMask == rowMask
            sameCol += curColMask == colMask
        t1 = f(rowMask, sameRow)
        t2 = f(colMask, sameCol)
        return -1 if t1 == -1 or t2 == -1 else t1 + t2
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int n;

    public int movesToChessboard(int[][] board) {
        n = board.length;
        int mask = (1 << n) - 1;
        int rowMask = 0, colMask = 0;
        for (int i = 0; i < n; ++i) {
            rowMask |= board[0][i] << i;
            colMask |= board[i][0] << i;
        }
        int revRowMask = mask ^ rowMask;
        int revColMask = mask ^ colMask;
        int sameRow = 0, sameCol = 0;
        for (int i = 0; i < n; ++i) {
            int curRowMask = 0, curColMask = 0;
            for (int j = 0; j < n; ++j) {
                curRowMask |= board[i][j] << j;
                curColMask |= board[j][i] << j;
            }
            if (curRowMask != rowMask && curRowMask != revRowMask) {
                return -1;
            }
            if (curColMask != colMask && curColMask != revColMask) {
                return -1;
            }
            sameRow += curRowMask == rowMask ? 1 : 0;
            sameCol += curColMask == colMask ? 1 : 0;
        }
        int t1 = f(rowMask, sameRow);
        int t2 = f(colMask, sameCol);
        return t1 == -1 || t2 == -1 ? -1 : t1 + t2;
    }

    private int f(int mask, int cnt) {
        int ones = Integer.bitCount(mask);
        if (n % 2 == 1) {
            if (Math.abs(n - ones * 2) != 1 || Math.abs(n - cnt * 2) != 1) {
                return -1;
            }
            if (ones == n / 2) {
                return n / 2 - Integer.bitCount(mask & 0xAAAAAAAA);
            }
            return (n / 2 + 1) - Integer.bitCount(mask & 0x55555555);
        } else {
            if (ones != n / 2 || cnt != n / 2) {
                return -1;
            }
            int cnt0 = n / 2 - Integer.bitCount(mask & 0xAAAAAAAA);
            int cnt1 = n / 2 - Integer.bitCount(mask & 0x55555555);
            return Math.min(cnt0, cnt1);
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int n;
    int movesToChessboard(vector<vector<int>>& board) {
        n = board.size();
        int mask = (1 << n) - 1;
        int rowMask = 0, colMask = 0;
        for (int i = 0; i < n; ++i) {
            rowMask |= board[0][i] << i;
            colMask |= board[i][0] << i;
        }
        int revRowMask = mask ^ rowMask;
        int revColMask = mask ^ colMask;
        int sameRow = 0, sameCol = 0;
        for (int i = 0; i < n; ++i) {
            int curRowMask = 0, curColMask = 0;
            for (int j = 0; j < n; ++j) {
                curRowMask |= board[i][j] << j;
                curColMask |= board[j][i] << j;
            }
            if (curRowMask != rowMask && curRowMask != revRowMask) return -1;
            if (curColMask != colMask && curColMask != revColMask) return -1;
            sameRow += curRowMask == rowMask;
            sameCol += curColMask == colMask;
        }
        int t1 = f(rowMask, sameRow);
        int t2 = f(colMask, sameCol);
        return t1 == -1 || t2 == -1 ? -1 : t1 + t2;
    }

    int f(int mask, int cnt) {
        int ones = __builtin_popcount(mask);
        if (n & 1) {
            if (abs(n - ones * 2) != 1 || abs(n - cnt * 2) != 1) return -1;
            if (ones == n / 2) return n / 2 - __builtin_popcount(mask & 0xAAAAAAAA);
            return (n + 1) / 2 - __builtin_popcount(mask & 0x55555555);
        } else {
            if (ones != n / 2 || cnt != n / 2) return -1;
            int cnt0 = (n / 2 - __builtin_popcount(mask & 0xAAAAAAAA));
            int cnt1 = (n / 2 - __builtin_popcount(mask & 0x55555555));
            return min(cnt0, cnt1);
        }
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func movesToChessboard(board [][]int) int {
	n := len(board)
	mask := (1 << n) - 1
	rowMask, colMask := 0, 0
	for i := 0; i < n; i++ {
		rowMask |= board[0][i] << i
		colMask |= board[i][0] << i
	}
	revRowMask := mask ^ rowMask
	revColMask := mask ^ colMask
	sameRow, sameCol := 0, 0
	for i := 0; i < n; i++ {
		curRowMask, curColMask := 0, 0
		for j := 0; j < n; j++ {
			curRowMask |= board[i][j] << j
			curColMask |= board[j][i] << j
		}
		if curRowMask != rowMask && curRowMask != revRowMask {
			return -1
		}
		if curColMask != colMask && curColMask != revColMask {
			return -1
		}
		if curRowMask == rowMask {
			sameRow++
		}
		if curColMask == colMask {
			sameCol++
		}
	}
	f := func(mask, cnt int) int {
		ones := bits.OnesCount(uint(mask))
		if n%2 == 1 {
			if abs(n-ones*2) != 1 || abs(n-cnt*2) != 1 {
				return -1
			}
			if ones == n/2 {
				return n/2 - bits.OnesCount(uint(mask&0xAAAAAAAA))
			}
			return (n+1)/2 - bits.OnesCount(uint(mask&0x55555555))
		} else {
			if ones != n/2 || cnt != n/2 {
				return -1
			}
			cnt0 := n/2 - bits.OnesCount(uint(mask&0xAAAAAAAA))
			cnt1 := n/2 - bits.OnesCount(uint(mask&0x55555555))
			return min(cnt0, cnt1)
		}
	}
	t1 := f(rowMask, sameRow)
	t2 := f(colMask, sameCol)
	if t1 == -1 || t2 == -1 {
		return -1
	}
	return t1 + t2
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

<p>一个&nbsp;<code>n x n</code>&nbsp;的二维网络&nbsp;<code>board</code>&nbsp;仅由&nbsp;<code>0</code>&nbsp;和&nbsp;<code>1</code>&nbsp;组成&nbsp;。每次移动，你能交换任意两列或是两行的位置。</p>

<p>返回 <em>将这个矩阵变为<strong>&nbsp; “棋盘”&nbsp;&nbsp;</strong>所需的最小移动次数&nbsp;</em>。如果不存在可行的变换，输出 <code>-1</code>。</p>

<p><strong>“棋盘”</strong> 是指任意一格的上下左右四个方向的值均与本身不同的矩阵。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0700-0799/0782.Transform%20to%20Chessboard/images/chessboard1-grid.jpg" style="height: 145px; width: 500px;" /></p>

<pre>
<strong>输入:</strong> board = [[0,1,1,0],[0,1,1,0],[1,0,0,1],[1,0,0,1]]
<strong>输出:</strong> 2
<strong>解释:</strong>一种可行的变换方式如下，从左到右：
第一次移动交换了第一列和第二列。
第二次移动交换了第二行和第三行。
</pre>

<p><strong>示例 2:</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0700-0799/0782.Transform%20to%20Chessboard/images/chessboard2-grid.jpg" /></p>

<pre>
<strong>输入:</strong> board = [[0, 1], [1, 0]]
<strong>输出:</strong> 0
<strong>解释: </strong>注意左上角的格值为0时也是合法的棋盘，也是合法的棋盘.
</pre>

<p><strong>示例 3:</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0700-0799/0782.Transform%20to%20Chessboard/images/chessboard3-grid.jpg" /></p>

<pre>
<strong>输入:</strong> board = [[1, 0], [1, 0]]
<strong>输出:</strong> -1
<strong>解释: </strong>任意的变换都不能使这个输入变为合法的棋盘。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == board.length</code></li>
	<li><code>n == board[i].length</code></li>
	<li><code>2 &lt;= n &lt;= 30</code></li>
	<li><code>board[i][j]</code>&nbsp;将只包含&nbsp;<code>0</code>或&nbsp;<code>1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：规律观察 + 状态压缩

在一个有效的棋盘中，有且仅有两种“行”。

例如，如果棋盘中有一行为“01010011”，那么任何其它行只能为“01010011”或者“10101100”。列也满足这种性质。

另外，每一行和每一列都有一半 $0$ 和一半 $1$。假设棋盘为 $n \times n$：

-   若 $n = 2 \times k$，则每一行和每一列都有 $k$ 个 $1$ 和 $k$ 个 $0$。
-   若 $n = 2 \times k + 1$，则每一行都有 $k$ 个 $1$ 和 $k + 1$ 个 $0$，或者 $k + 1$ 个 $1$ 和 $k$ 个 $0$。

基于以上的结论，我们可以判断一个棋盘是否有效。若有效，可以计算出最小的移动次数。

若 $n$ 为偶数，最终的合法棋盘有两种可能，即第一行的元素为“010101...”，或者“101010...”。我们计算出这两种可能所需要交换的次数的较小值作为答案。

若 $n$ 为奇数，那么最终的合法棋盘只有一种可能。如果第一行中 $0$ 的数目大于 $1$，那么最终一盘的第一行只能是“01010...”，否则就是“10101...”。同样算出次数作为答案。

时间复杂度 $O(n^2)$，其中 $n$ 是棋盘的大小。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def movesToChessboard(self, board: List[List[int]]) -> int:
        def f(mask, cnt):
            ones = mask.bit_count()
            if n & 1:
                if abs(n - 2 * ones) != 1 or abs(n - 2 * cnt) != 1:
                    return -1
                if ones == n // 2:
                    return n // 2 - (mask & 0xAAAAAAAA).bit_count()
                return (n + 1) // 2 - (mask & 0x55555555).bit_count()
            else:
                if ones != n // 2 or cnt != n // 2:
                    return -1
                cnt0 = n // 2 - (mask & 0xAAAAAAAA).bit_count()
                cnt1 = n // 2 - (mask & 0x55555555).bit_count()
                return min(cnt0, cnt1)

        n = len(board)
        mask = (1 << n) - 1
        rowMask = colMask = 0
        for i in range(n):
            rowMask |= board[0][i] << i
            colMask |= board[i][0] << i
        revRowMask = mask ^ rowMask
        revColMask = mask ^ colMask
        sameRow = sameCol = 0
        for i in range(n):
            curRowMask = curColMask = 0
            for j in range(n):
                curRowMask |= board[i][j] << j
                curColMask |= board[j][i] << j
            if curRowMask not in (rowMask, revRowMask) or curColMask not in (
                colMask,
                revColMask,
            ):
                return -1
            sameRow += curRowMask == rowMask
            sameCol += curColMask == colMask
        t1 = f(rowMask, sameRow)
        t2 = f(colMask, sameCol)
        return -1 if t1 == -1 or t2 == -1 else t1 + t2
```

#### Java

```java
class Solution {
    private int n;

    public int movesToChessboard(int[][] board) {
        n = board.length;
        int mask = (1 << n) - 1;
        int rowMask = 0, colMask = 0;
        for (int i = 0; i < n; ++i) {
            rowMask |= board[0][i] << i;
            colMask |= board[i][0] << i;
        }
        int revRowMask = mask ^ rowMask;
        int revColMask = mask ^ colMask;
        int sameRow = 0, sameCol = 0;
        for (int i = 0; i < n; ++i) {
            int curRowMask = 0, curColMask = 0;
            for (int j = 0; j < n; ++j) {
                curRowMask |= board[i][j] << j;
                curColMask |= board[j][i] << j;
            }
            if (curRowMask != rowMask && curRowMask != revRowMask) {
                return -1;
            }
            if (curColMask != colMask && curColMask != revColMask) {
                return -1;
            }
            sameRow += curRowMask == rowMask ? 1 : 0;
            sameCol += curColMask == colMask ? 1 : 0;
        }
        int t1 = f(rowMask, sameRow);
        int t2 = f(colMask, sameCol);
        return t1 == -1 || t2 == -1 ? -1 : t1 + t2;
    }

    private int f(int mask, int cnt) {
        int ones = Integer.bitCount(mask);
        if (n % 2 == 1) {
            if (Math.abs(n - ones * 2) != 1 || Math.abs(n - cnt * 2) != 1) {
                return -1;
            }
            if (ones == n / 2) {
                return n / 2 - Integer.bitCount(mask & 0xAAAAAAAA);
            }
            return (n / 2 + 1) - Integer.bitCount(mask & 0x55555555);
        } else {
            if (ones != n / 2 || cnt != n / 2) {
                return -1;
            }
            int cnt0 = n / 2 - Integer.bitCount(mask & 0xAAAAAAAA);
            int cnt1 = n / 2 - Integer.bitCount(mask & 0x55555555);
            return Math.min(cnt0, cnt1);
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    int n;
    int movesToChessboard(vector<vector<int>>& board) {
        n = board.size();
        int mask = (1 << n) - 1;
        int rowMask = 0, colMask = 0;
        for (int i = 0; i < n; ++i) {
            rowMask |= board[0][i] << i;
            colMask |= board[i][0] << i;
        }
        int revRowMask = mask ^ rowMask;
        int revColMask = mask ^ colMask;
        int sameRow = 0, sameCol = 0;
        for (int i = 0; i < n; ++i) {
            int curRowMask = 0, curColMask = 0;
            for (int j = 0; j < n; ++j) {
                curRowMask |= board[i][j] << j;
                curColMask |= board[j][i] << j;
            }
            if (curRowMask != rowMask && curRowMask != revRowMask) return -1;
            if (curColMask != colMask && curColMask != revColMask) return -1;
            sameRow += curRowMask == rowMask;
            sameCol += curColMask == colMask;
        }
        int t1 = f(rowMask, sameRow);
        int t2 = f(colMask, sameCol);
        return t1 == -1 || t2 == -1 ? -1 : t1 + t2;
    }

    int f(int mask, int cnt) {
        int ones = __builtin_popcount(mask);
        if (n & 1) {
            if (abs(n - ones * 2) != 1 || abs(n - cnt * 2) != 1) return -1;
            if (ones == n / 2) return n / 2 - __builtin_popcount(mask & 0xAAAAAAAA);
            return (n + 1) / 2 - __builtin_popcount(mask & 0x55555555);
        } else {
            if (ones != n / 2 || cnt != n / 2) return -1;
            int cnt0 = (n / 2 - __builtin_popcount(mask & 0xAAAAAAAA));
            int cnt1 = (n / 2 - __builtin_popcount(mask & 0x55555555));
            return min(cnt0, cnt1);
        }
    }
};
```

#### Go

```go
func movesToChessboard(board [][]int) int {
	n := len(board)
	mask := (1 << n) - 1
	rowMask, colMask := 0, 0
	for i := 0; i < n; i++ {
		rowMask |= board[0][i] << i
		colMask |= board[i][0] << i
	}
	revRowMask := mask ^ rowMask
	revColMask := mask ^ colMask
	sameRow, sameCol := 0, 0
	for i := 0; i < n; i++ {
		curRowMask, curColMask := 0, 0
		for j := 0; j < n; j++ {
			curRowMask |= board[i][j] << j
			curColMask |= board[j][i] << j
		}
		if curRowMask != rowMask && curRowMask != revRowMask {
			return -1
		}
		if curColMask != colMask && curColMask != revColMask {
			return -1
		}
		if curRowMask == rowMask {
			sameRow++
		}
		if curColMask == colMask {
			sameCol++
		}
	}
	f := func(mask, cnt int) int {
		ones := bits.OnesCount(uint(mask))
		if n%2 == 1 {
			if abs(n-ones*2) != 1 || abs(n-cnt*2) != 1 {
				return -1
			}
			if ones == n/2 {
				return n/2 - bits.OnesCount(uint(mask&0xAAAAAAAA))
			}
			return (n+1)/2 - bits.OnesCount(uint(mask&0x55555555))
		} else {
			if ones != n/2 || cnt != n/2 {
				return -1
			}
			cnt0 := n/2 - bits.OnesCount(uint(mask&0xAAAAAAAA))
			cnt1 := n/2 - bits.OnesCount(uint(mask&0x55555555))
			return min(cnt0, cnt1)
		}
	}
	t1 := f(rowMask, sameRow)
	t2 := f(colMask, sameCol)
	if t1 == -1 || t2 == -1 {
		return -1
	}
	return t1 + t2
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

# [783. 二叉搜索树节点最小距离](https://leetcode.cn/problems/minimum-distance-between-bst-nodes){#783}

{{< tabs "783" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minDiffInBST(self, root: Optional[TreeNode]) -> int:
        def dfs(root: Optional[TreeNode]):
            if root is None:
                return
            dfs(root.left)
            nonlocal pre, ans
            ans = min(ans, root.val - pre)
            pre = root.val
            dfs(root.right)

        pre = -inf
        ans = inf
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
    private final int inf = 1 << 30;
    private int ans = inf;
    private int pre = -inf;

    public int minDiffInBST(TreeNode root) {
        dfs(root);
        return ans;
    }

    private void dfs(TreeNode root) {
        if (root == null) {
            return;
        }
        dfs(root.left);
        ans = Math.min(ans, root.val - pre);
        pre = root.val;
        dfs(root.right);
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
    int minDiffInBST(TreeNode* root) {
        const int inf = 1 << 30;
        int ans = inf, pre = -inf;
        auto dfs = [&](this auto&& dfs, TreeNode* root) -> void {
            if (!root) {
                return;
            }
            dfs(root->left);
            ans = min(ans, root->val - pre);
            pre = root->val;
            dfs(root->right);
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
func minDiffInBST(root *TreeNode) int {
	const inf int = 1 << 30
	ans, pre := inf, -inf
	var dfs func(*TreeNode)
	dfs = func(root *TreeNode) {
		if root == nil {
			return
		}
		dfs(root.Left)
		ans = min(ans, root.Val-pre)
		pre = root.Val
		dfs(root.Right)
	}
	dfs(root)
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

function minDiffInBST(root: TreeNode | null): number {
    let [ans, pre] = [Infinity, -Infinity];
    const dfs = (root: TreeNode | null) => {
        if (!root) {
            return;
        }
        dfs(root.left);
        ans = Math.min(ans, root.val - pre);
        pre = root.val;
        dfs(root.right);
    };
    dfs(root);
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
    pub fn min_diff_in_bst(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        const inf: i32 = 1 << 30;
        let mut ans = inf;
        let mut pre = -inf;

        fn dfs(node: Option<Rc<RefCell<TreeNode>>>, ans: &mut i32, pre: &mut i32) {
            if let Some(n) = node {
                let n = n.borrow();
                dfs(n.left.clone(), ans, pre);
                *ans = (*ans).min(n.val - *pre);
                *pre = n.val;
                dfs(n.right.clone(), ans, pre);
            }
        }

        dfs(root, &mut ans, &mut pre);
        ans
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var minDiffInBST = function (root) {
    let [ans, pre] = [Infinity, -Infinity];
    const dfs = root => {
        if (!root) {
            return;
        }
        dfs(root.left);
        ans = Math.min(ans, root.val - pre);
        pre = root.val;
        dfs(root.right);
    };
    dfs(root);
    return ans;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个二叉搜索树的根节点 <code>root</code> ，返回 <strong>树中任意两不同节点值之间的最小差值</strong> 。</p>

<p>差值是一个正数，其数值等于两值之差的绝对值。</p>

<p>&nbsp;</p>

<div class="original__bRMd">
<div>
<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0700-0799/0783.Minimum%20Distance%20Between%20BST%20Nodes/images/bst1.jpg" style="width: 292px; height: 301px;" />
<pre>
<strong>输入：</strong>root = [4,2,6,1,3]
<strong>输出：</strong>1
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0700-0799/0783.Minimum%20Distance%20Between%20BST%20Nodes/images/bst2.jpg" style="width: 282px; height: 301px;" />
<pre>
<strong>输入：</strong>root = [1,0,48,null,null,12,49]
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点的数目范围是 <code>[2, 100]</code></li>
	<li><code>0 &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
</ul>

<p>&nbsp;</p>

<p><strong>注意：</strong>本题与 530：<a href="https://leetcode.cn/problems/minimum-absolute-difference-in-bst/">https://leetcode.cn/problems/minimum-absolute-difference-in-bst/</a> 相同</p>
</div>
</div>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：中序遍历

题目需要我们求任意两个节点值之间的最小差值，而二叉搜索树的中序遍历是一个递增序列，因此我们只需要求中序遍历中相邻两个节点值之间的最小差值即可。

我们可以使用递归的方法来实现中序遍历，过程中用一个变量 $\textit{pre}$ 来保存前一个节点的值，这样我们就可以在遍历的过程中求出相邻两个节点值之间的最小差值。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为二叉搜索树的节点个数。

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
    def minDiffInBST(self, root: Optional[TreeNode]) -> int:
        def dfs(root: Optional[TreeNode]):
            if root is None:
                return
            dfs(root.left)
            nonlocal pre, ans
            ans = min(ans, root.val - pre)
            pre = root.val
            dfs(root.right)

        pre = -inf
        ans = inf
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
    private final int inf = 1 << 30;
    private int ans = inf;
    private int pre = -inf;

    public int minDiffInBST(TreeNode root) {
        dfs(root);
        return ans;
    }

    private void dfs(TreeNode root) {
        if (root == null) {
            return;
        }
        dfs(root.left);
        ans = Math.min(ans, root.val - pre);
        pre = root.val;
        dfs(root.right);
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
    int minDiffInBST(TreeNode* root) {
        const int inf = 1 << 30;
        int ans = inf, pre = -inf;
        auto dfs = [&](this auto&& dfs, TreeNode* root) -> void {
            if (!root) {
                return;
            }
            dfs(root->left);
            ans = min(ans, root->val - pre);
            pre = root->val;
            dfs(root->right);
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
func minDiffInBST(root *TreeNode) int {
	const inf int = 1 << 30
	ans, pre := inf, -inf
	var dfs func(*TreeNode)
	dfs = func(root *TreeNode) {
		if root == nil {
			return
		}
		dfs(root.Left)
		ans = min(ans, root.Val-pre)
		pre = root.Val
		dfs(root.Right)
	}
	dfs(root)
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

function minDiffInBST(root: TreeNode | null): number {
    let [ans, pre] = [Infinity, -Infinity];
    const dfs = (root: TreeNode | null) => {
        if (!root) {
            return;
        }
        dfs(root.left);
        ans = Math.min(ans, root.val - pre);
        pre = root.val;
        dfs(root.right);
    };
    dfs(root);
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
    pub fn min_diff_in_bst(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        const inf: i32 = 1 << 30;
        let mut ans = inf;
        let mut pre = -inf;

        fn dfs(node: Option<Rc<RefCell<TreeNode>>>, ans: &mut i32, pre: &mut i32) {
            if let Some(n) = node {
                let n = n.borrow();
                dfs(n.left.clone(), ans, pre);
                *ans = (*ans).min(n.val - *pre);
                *pre = n.val;
                dfs(n.right.clone(), ans, pre);
            }
        }

        dfs(root, &mut ans, &mut pre);
        ans
    }
}
```

#### JavaScript

```js
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var minDiffInBST = function (root) {
    let [ans, pre] = [Infinity, -Infinity];
    const dfs = root => {
        if (!root) {
            return;
        }
        dfs(root.left);
        ans = Math.min(ans, root.val - pre);
        pre = root.val;
        dfs(root.right);
    };
    dfs(root);
    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [784. 字母大小写全排列](https://leetcode.cn/problems/letter-case-permutation){#784}

{{< tabs "784" >}}

{{% tab "python" %}}
```python
class Solution:
    def letterCasePermutation(self, s: str) -> List[str]:
        ans = []
        n = sum(c.isalpha() for c in s)
        for i in range(1 << n):
            j, t = 0, []
            for c in s:
                if c.isalpha():
                    c = c.lower() if (i >> j) & 1 else c.upper()
                    j += 1
                t.append(c)
            ans.append(''.join(t))
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<String> letterCasePermutation(String s) {
        int n = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s.charAt(i) >= 'A') {
                ++n;
            }
        }
        List<String> ans = new ArrayList<>();
        for (int i = 0; i < 1 << n; ++i) {
            int j = 0;
            StringBuilder t = new StringBuilder();
            for (int k = 0; k < s.length(); ++k) {
                char x = s.charAt(k);
                if (x >= 'A') {
                    x = ((i >> j) & 1) == 1 ? Character.toLowerCase(x) : Character.toUpperCase(x);
                    ++j;
                }
                t.append(x);
            }
            ans.add(t.toString());
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
    vector<string> letterCasePermutation(string s) {
        int n = count_if(s.begin(), s.end(), [](char c) { return isalpha(c); });
        vector<string> ans;
        for (int i = 0; i < 1 << n; ++i) {
            int j = 0;
            string t;
            for (char c : s) {
                if (isalpha(c)) {
                    c = (i >> j & 1) ? tolower(c) : toupper(c);
                    ++j;
                }
                t += c;
            }
            ans.emplace_back(t);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func letterCasePermutation(s string) (ans []string) {
	n := 0
	for _, c := range s {
		if c >= 'A' {
			n++
		}
	}
	for i := 0; i < 1<<n; i++ {
		j := 0
		t := []rune{}
		for _, c := range s {
			if c >= 'A' {
				if ((i >> j) & 1) == 1 {
					c = unicode.ToLower(c)
				} else {
					c = unicode.ToUpper(c)
				}
				j++
			}
			t = append(t, c)
		}
		ans = append(ans, string(t))
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function letterCasePermutation(s: string): string[] {
    const ans: string[] = [];
    const n: number = Array.from(s).filter(c => /[a-zA-Z]/.test(c)).length;
    for (let i = 0; i < 1 << n; ++i) {
        let j = 0;
        const t: string[] = [];
        for (let c of s) {
            if (/[a-zA-Z]/.test(c)) {
                t.push((i >> j) & 1 ? c.toLowerCase() : c.toUpperCase());
                j++;
            } else {
                t.push(c);
            }
        }
        ans.push(t.join(''));
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn letter_case_permutation(s: String) -> Vec<String> {
        let n = s.chars().filter(|&c| c.is_alphabetic()).count();
        let mut ans = Vec::new();
        for i in 0..(1 << n) {
            let mut j = 0;
            let mut t = String::new();
            for c in s.chars() {
                if c.is_alphabetic() {
                    if (i >> j) & 1 == 1 {
                        t.push(c.to_lowercase().next().unwrap());
                    } else {
                        t.push(c.to_uppercase().next().unwrap());
                    }
                    j += 1;
                } else {
                    t.push(c);
                }
            }
            ans.push(t);
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

<p>给定一个字符串&nbsp;<code>s</code>&nbsp;，通过将字符串&nbsp;<code>s</code>&nbsp;中的每个字母转变大小写，我们可以获得一个新的字符串。</p>

<p>返回 <em>所有可能得到的字符串集合</em> 。以 <strong>任意顺序</strong> 返回输出。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "a1b2"
<strong>输出：</strong>["a1b2", "a1B2", "A1b2", "A1B2"]
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> s = "3z4"
<strong>输出:</strong> ["3z4","3Z4"]
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 12</code></li>
	<li><code>s</code>&nbsp;由小写英文字母、大写英文字母和数字组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS

由于 $s$ 中的每个字母都可以转换为大写或小写，因此可以使用 DFS 深度优先搜索的方法，枚举所有可能的情况。

具体地，从左到右遍历字符串 $s$，对于遍历到的每个字母，可以选择将其转变为大写或小写，然后继续遍历后面的字母。当遍历到字符串的末尾时，得到一个转换方案，将该方案加入答案即可。

转变大小写的方法可以使用位运算实现。对于一个字母，小写形式与大写形式的 ASCII 码之差为 $32$，因此，我们可以通过将该字母的 ASCII 码与 $32$ 进行异或运算来实现大小写转换。

时间复杂度 $O(n \times 2^n)$，其中 $n$ 是字符串 $s$ 的长度。对于每个字母，我们可以选择将其转换为大写或小写，因此一共有 $2^n$ 种转换方案。对于每种转换方案，我们需要 $O(n)$ 的时间生成一个新的字符串。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def letterCasePermutation(self, s: str) -> List[str]:
        def dfs(i: int) -> None:
            if i >= len(t):
                ans.append("".join(t))
                return
            dfs(i + 1)
            if t[i].isalpha():
                t[i] = chr(ord(t[i]) ^ 32)
                dfs(i + 1)

        t = list(s)
        ans = []
        dfs(0)
        return ans
```

#### Java

```java
class Solution {
    private List<String> ans = new ArrayList<>();
    private char[] t;

    public List<String> letterCasePermutation(String s) {
        t = s.toCharArray();
        dfs(0);
        return ans;
    }

    private void dfs(int i) {
        if (i >= t.length) {
            ans.add(new String(t));
            return;
        }
        dfs(i + 1);
        if (Character.isLetter(t[i])) {
            t[i] ^= 32;
            dfs(i + 1);
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        string t = s;
        vector<string> ans;
        auto dfs = [&](this auto&& dfs, int i) -> void {
            if (i >= t.size()) {
                ans.push_back(t);
                return;
            }
            dfs(i + 1);
            if (isalpha(t[i])) {
                t[i] ^= 32;
                dfs(i + 1);
            }
        };
        dfs(0);
        return ans;
    }
};
```

#### Go

```go
func letterCasePermutation(s string) (ans []string) {
	t := []byte(s)
	var dfs func(int)
	dfs = func(i int) {
		if i >= len(t) {
			ans = append(ans, string(t))
			return
		}
		dfs(i + 1)
		if t[i] >= 'A' {
			t[i] ^= 32
			dfs(i + 1)
		}
	}

	dfs(0)
	return ans
}
```

#### TypeScript

```ts
function letterCasePermutation(s: string): string[] {
    const t = s.split('');
    const ans: string[] = [];
    const dfs = (i: number) => {
        if (i >= t.length) {
            ans.push(t.join(''));
            return;
        }
        dfs(i + 1);
        if (t[i].charCodeAt(0) >= 65) {
            t[i] = String.fromCharCode(t[i].charCodeAt(0) ^ 32);
            dfs(i + 1);
        }
    };
    dfs(0);
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn letter_case_permutation(s: String) -> Vec<String> {
        fn dfs(i: usize, t: &mut Vec<char>, ans: &mut Vec<String>) {
            if i >= t.len() {
                ans.push(t.iter().collect());
                return;
            }
            dfs(i + 1, t, ans);
            if t[i].is_alphabetic() {
                t[i] = (t[i] as u8 ^ 32) as char;
                dfs(i + 1, t, ans);
            }
        }

        let mut t: Vec<char> = s.chars().collect();
        let mut ans = Vec::new();
        dfs(0, &mut t, &mut ans);
        ans
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：二进制枚举

对于一个字母，我们可以将其转换为大写或小写，因此对于每个字母，我们可以使用一个二进制位表示其转换的方案，其中 $1$ 表示小写，而 $0$ 表示大写。

我们先统计字符串 $s$ 中字母的个数，记为 $n$，那么一共有 $2^n$ 种转换方案，我们可以使用二进制数的每一位表示每个字母的转换方案，从 $0$ 到 $2^n-1$ 进行枚举。

具体地，我们可以使用一个变量 $i$ 表示当前枚举到的二进制数，其中 $i$ 的第 $j$ 位表示第 $j$ 个字母的转换方案。即 $i$ 的第 $j$ 位为 $1$ 表示第 $j$ 个字母转换为小写，而 $i$ 的第 $j$ 位为 $0$ 表示第 $j$ 个字母转换为大写。

时间复杂度 $O(n \times 2^n)$，其中 $n$ 是字符串 $s$ 的长度。对于每个字母，我们可以选择将其转换为大写或小写，因此一共有 $2^n$ 种转换方案。对于每种转换方案，我们需要 $O(n)$ 的时间生成一个新的字符串。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def letterCasePermutation(self, s: str) -> List[str]:
        ans = []
        n = sum(c.isalpha() for c in s)
        for i in range(1 << n):
            j, t = 0, []
            for c in s:
                if c.isalpha():
                    c = c.lower() if (i >> j) & 1 else c.upper()
                    j += 1
                t.append(c)
            ans.append(''.join(t))
        return ans
```

#### Java

```java
class Solution {
    public List<String> letterCasePermutation(String s) {
        int n = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s.charAt(i) >= 'A') {
                ++n;
            }
        }
        List<String> ans = new ArrayList<>();
        for (int i = 0; i < 1 << n; ++i) {
            int j = 0;
            StringBuilder t = new StringBuilder();
            for (int k = 0; k < s.length(); ++k) {
                char x = s.charAt(k);
                if (x >= 'A') {
                    x = ((i >> j) & 1) == 1 ? Character.toLowerCase(x) : Character.toUpperCase(x);
                    ++j;
                }
                t.append(x);
            }
            ans.add(t.toString());
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        int n = count_if(s.begin(), s.end(), [](char c) { return isalpha(c); });
        vector<string> ans;
        for (int i = 0; i < 1 << n; ++i) {
            int j = 0;
            string t;
            for (char c : s) {
                if (isalpha(c)) {
                    c = (i >> j & 1) ? tolower(c) : toupper(c);
                    ++j;
                }
                t += c;
            }
            ans.emplace_back(t);
        }
        return ans;
    }
};
```

#### Go

```go
func letterCasePermutation(s string) (ans []string) {
	n := 0
	for _, c := range s {
		if c >= 'A' {
			n++
		}
	}
	for i := 0; i < 1<<n; i++ {
		j := 0
		t := []rune{}
		for _, c := range s {
			if c >= 'A' {
				if ((i >> j) & 1) == 1 {
					c = unicode.ToLower(c)
				} else {
					c = unicode.ToUpper(c)
				}
				j++
			}
			t = append(t, c)
		}
		ans = append(ans, string(t))
	}
	return ans
}
```

#### TypeScript

```ts
function letterCasePermutation(s: string): string[] {
    const ans: string[] = [];
    const n: number = Array.from(s).filter(c => /[a-zA-Z]/.test(c)).length;
    for (let i = 0; i < 1 << n; ++i) {
        let j = 0;
        const t: string[] = [];
        for (let c of s) {
            if (/[a-zA-Z]/.test(c)) {
                t.push((i >> j) & 1 ? c.toLowerCase() : c.toUpperCase());
                j++;
            } else {
                t.push(c);
            }
        }
        ans.push(t.join(''));
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn letter_case_permutation(s: String) -> Vec<String> {
        let n = s.chars().filter(|&c| c.is_alphabetic()).count();
        let mut ans = Vec::new();
        for i in 0..(1 << n) {
            let mut j = 0;
            let mut t = String::new();
            for c in s.chars() {
                if c.is_alphabetic() {
                    if (i >> j) & 1 == 1 {
                        t.push(c.to_lowercase().next().unwrap());
                    } else {
                        t.push(c.to_uppercase().next().unwrap());
                    }
                    j += 1;
                } else {
                    t.push(c);
                }
            }
            ans.push(t);
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

# [785. 判断二分图](https://leetcode.cn/problems/is-graph-bipartite){#785}

{{< tabs "785" >}}

{{% tab "python" %}}
```python
class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        def find(x: int) -> int:
            if p[x] != x:
                p[x] = find(p[x])
            return p[x]

        p = list(range(len(graph)))
        for a, bs in enumerate(graph):
            for b in bs:
                pa, pb = find(a), find(b)
                if pa == pb:
                    return False
                p[pb] = find(bs[0])
        return True
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[] p;

    public boolean isBipartite(int[][] graph) {
        int n = graph.length;
        p = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
        }
        for (int a = 0; a < n; ++a) {
            for (int b : graph[a]) {
                int pa = find(a), pb = find(b);
                if (pa == pb) {
                    return false;
                }
                p[pb] = find(graph[a][0]);
            }
        }
        return true;
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
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> p(n);
        iota(p.begin(), p.end(), 0);
        auto find = [&](this auto&& find, int x) -> int {
            if (p[x] != x) {
                p[x] = find(p[x]);
            }
            return p[x];
        };
        for (int a = 0; a < n; ++a) {
            for (int b : graph[a]) {
                int pa = find(a), pb = find(b);
                if (pa == pb) {
                    return false;
                }
                p[pb] = find(graph[a][0]);
            }
        }
        return true;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func isBipartite(graph [][]int) bool {
	n := len(graph)
	p := make([]int, n)
	for i := range p {
		p[i] = i
	}
	var find func(x int) int
	find = func(x int) int {
		if p[x] != x {
			p[x] = find(p[x])
		}
		return p[x]
	}
	for a, bs := range graph {
		for _, b := range bs {
			pa, pb := find(a), find(b)
			if pa == pb {
				return false
			}
			p[pb] = find(bs[0])
		}
	}
	return true
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function isBipartite(graph: number[][]): boolean {
    const n = graph.length;
    const p: number[] = Array.from({ length: n }, (_, i) => i);
    const find = (x: number): number => {
        if (x !== p[x]) {
            p[x] = find(p[x]);
        }
        return p[x];
    };
    for (let a = 0; a < n; ++a) {
        for (const b of graph[a]) {
            const [pa, pb] = [find(a), find(b)];
            if (pa === pb) {
                return false;
            }
            p[pb] = find(graph[a][0]);
        }
    }
    return true;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn is_bipartite(graph: Vec<Vec<i32>>) -> bool {
        let n = graph.len();
        let mut p: Vec<usize> = (0..n).collect();

        fn find(x: usize, p: &mut Vec<usize>) -> usize {
            if p[x] != x {
                p[x] = find(p[x], p);
            }
            p[x]
        }

        for a in 0..n {
            for &b in &graph[a] {
                let pa = find(a, &mut p);
                let pb = find(b as usize, &mut p);
                if pa == pb {
                    return false;
                }
                p[pb] = find(graph[a][0] as usize, &mut p);
            }
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

存在一个 <strong>无向图</strong> ，图中有 <code>n</code> 个节点。其中每个节点都有一个介于 <code>0</code> 到 <code>n - 1</code> 之间的唯一编号。给你一个二维数组 <code>graph</code> ，其中 <code>graph[u]</code> 是一个节点数组，由节点 <code>u</code> 的邻接节点组成。形式上，对于 <code>graph[u]</code> 中的每个 <code>v</code> ，都存在一条位于节点 <code>u</code> 和节点 <code>v</code> 之间的无向边。该无向图同时具有以下属性：

<ul>
	<li>不存在自环（<code>graph[u]</code> 不包含 <code>u</code>）。</li>
	<li>不存在平行边（<code>graph[u]</code> 不包含重复值）。</li>
	<li>如果 <code>v</code> 在 <code>graph[u]</code> 内，那么 <code>u</code> 也应该在 <code>graph[v]</code> 内（该图是无向图）</li>
	<li>这个图可能不是连通图，也就是说两个节点 <code>u</code> 和 <code>v</code> 之间可能不存在一条连通彼此的路径。</li>
</ul>

<p><strong>二分图</strong> 定义：如果能将一个图的节点集合分割成两个独立的子集 <code>A</code> 和 <code>B</code> ，并使图中的每一条边的两个节点一个来自 <code>A</code> 集合，一个来自 <code>B</code> 集合，就将这个图称为 <strong>二分图</strong> 。</p>

<p>如果图是二分图，返回 <code>true</code><em> </em>；否则，返回 <code>false</code> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0700-0799/0785.Is%20Graph%20Bipartite/images/bi2.jpg" style="width: 222px; height: 222px;" />
<pre>
<strong>输入：</strong>graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
<strong>输出：</strong>false
<strong>解释：</strong><code>不能将节点分割成两个独立的子集，</code>以使每条边都连通一个子集中的一个节点与另一个子集中的一个节点。</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0700-0799/0785.Is%20Graph%20Bipartite/images/bi1.jpg" style="width: 222px; height: 222px;" />
<pre>
<strong>输入：</strong>graph = [[1,3],[0,2],[1,3],[0,2]]
<strong>输出：</strong>true
<strong>解释：</strong><code>可以将节点分成两组: {0, 2} 和 {1, 3} 。</code></pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>graph.length == n</code></li>
	<li><code>1 <= n <= 100</code></li>
	<li><code>0 <= graph[u].length < n</code></li>
	<li><code>0 <= graph[u][i] <= n - 1</code></li>
	<li><code>graph[u]</code> 不会包含 <code>u</code></li>
	<li><code>graph[u]</code> 的所有值 <strong>互不相同</strong></li>
	<li>如果 <code>graph[u]</code> 包含 <code>v</code>，那么 <code>graph[v]</code> 也会包含 <code>u</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：染色法判定二分图

遍历所有节点进行染色，比如初始为白色，DFS 对节点相邻的点染上另外一种颜色。如果要染色某节点时，要染的目标颜色和该节点的已经染过的颜色不同，则说明不能构成二分图。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为节点数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        def dfs(a: int, c: int) -> bool:
            color[a] = c
            for b in graph[a]:
                if color[b] == c or (color[b] == 0 and not dfs(b, -c)):
                    return False
            return True

        n = len(graph)
        color = [0] * n
        for i in range(n):
            if color[i] == 0 and not dfs(i, 1):
                return False
        return True
```

#### Java

```java
class Solution {
    private int[] color;
    private int[][] g;

    public boolean isBipartite(int[][] graph) {
        int n = graph.length;
        color = new int[n];
        g = graph;
        for (int i = 0; i < n; ++i) {
            if (color[i] == 0 && !dfs(i, 1)) {
                return false;
            }
        }
        return true;
    }

    private boolean dfs(int a, int c) {
        color[a] = c;
        for (int b : g[a]) {
            if (color[b] == c || (color[b] == 0 && !dfs(b, -c))) {
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
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n);
        auto dfs = [&](this auto&& dfs, int a, int c) -> bool {
            color[a] = c;
            for (int b : graph[a]) {
                if (color[b] == c || (color[b] == 0 && !dfs(b, -c))) {
                    return false;
                }
            }
            return true;
        };
        for (int i = 0; i < n; ++i) {
            if (color[i] == 0 && !dfs(i, 1)) {
                return false;
            }
        }
        return true;
    }
};
```

#### Go

```go
func isBipartite(graph [][]int) bool {
	n := len(graph)
	color := make([]int, n)
	var dfs func(int, int) bool
	dfs = func(a, c int) bool {
		color[a] = c
		for _, b := range graph[a] {
			if color[b] == c || (color[b] == 0 && !dfs(b, -c)) {
				return false
			}
		}
		return true
	}
	for i := range graph {
		if color[i] == 0 && !dfs(i, 1) {
			return false
		}
	}
	return true
}
```

#### TypeScript

```ts
function isBipartite(graph: number[][]): boolean {
    const n = graph.length;
    const color: number[] = Array(n).fill(0);
    const dfs = (a: number, c: number): boolean => {
        color[a] = c;
        for (const b of graph[a]) {
            if (color[b] === c || (color[b] === 0 && !dfs(b, -c))) {
                return false;
            }
        }
        return true;
    };
    for (let i = 0; i < n; i++) {
        if (color[i] === 0 && !dfs(i, 1)) {
            return false;
        }
    }
    return true;
}
```

#### Rust

```rust
impl Solution {
    pub fn is_bipartite(graph: Vec<Vec<i32>>) -> bool {
        let n = graph.len();
        let mut color = vec![0; n];

        fn dfs(a: usize, c: i32, graph: &Vec<Vec<i32>>, color: &mut Vec<i32>) -> bool {
            color[a] = c;
            for &b in &graph[a] {
                if color[b as usize] == c
                    || (color[b as usize] == 0 && !dfs(b as usize, -c, graph, color))
                {
                    return false;
                }
            }
            true
        }

        for i in 0..n {
            if color[i] == 0 && !dfs(i, 1, &graph, &mut color) {
                return false;
            }
        }
        true
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：并查集

对于本题，如果是二分图，那么图中每个顶点的所有邻接点都应该属于同一集合，且不与顶点处于同一集合，因此我们可以使用并查集。遍历图中每个顶点，如果发现存在当前顶点与对应的邻接点处于同一个集合，说明不是二分图。否则将当前节点的邻接点相互进行合并。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为节点数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        def find(x: int) -> int:
            if p[x] != x:
                p[x] = find(p[x])
            return p[x]

        p = list(range(len(graph)))
        for a, bs in enumerate(graph):
            for b in bs:
                pa, pb = find(a), find(b)
                if pa == pb:
                    return False
                p[pb] = find(bs[0])
        return True
```

#### Java

```java
class Solution {
    private int[] p;

    public boolean isBipartite(int[][] graph) {
        int n = graph.length;
        p = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
        }
        for (int a = 0; a < n; ++a) {
            for (int b : graph[a]) {
                int pa = find(a), pb = find(b);
                if (pa == pb) {
                    return false;
                }
                p[pb] = find(graph[a][0]);
            }
        }
        return true;
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
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> p(n);
        iota(p.begin(), p.end(), 0);
        auto find = [&](this auto&& find, int x) -> int {
            if (p[x] != x) {
                p[x] = find(p[x]);
            }
            return p[x];
        };
        for (int a = 0; a < n; ++a) {
            for (int b : graph[a]) {
                int pa = find(a), pb = find(b);
                if (pa == pb) {
                    return false;
                }
                p[pb] = find(graph[a][0]);
            }
        }
        return true;
    }
};
```

#### Go

```go
func isBipartite(graph [][]int) bool {
	n := len(graph)
	p := make([]int, n)
	for i := range p {
		p[i] = i
	}
	var find func(x int) int
	find = func(x int) int {
		if p[x] != x {
			p[x] = find(p[x])
		}
		return p[x]
	}
	for a, bs := range graph {
		for _, b := range bs {
			pa, pb := find(a), find(b)
			if pa == pb {
				return false
			}
			p[pb] = find(bs[0])
		}
	}
	return true
}
```

#### TypeScript

```ts
function isBipartite(graph: number[][]): boolean {
    const n = graph.length;
    const p: number[] = Array.from({ length: n }, (_, i) => i);
    const find = (x: number): number => {
        if (x !== p[x]) {
            p[x] = find(p[x]);
        }
        return p[x];
    };
    for (let a = 0; a < n; ++a) {
        for (const b of graph[a]) {
            const [pa, pb] = [find(a), find(b)];
            if (pa === pb) {
                return false;
            }
            p[pb] = find(graph[a][0]);
        }
    }
    return true;
}
```

#### Rust

```rust
impl Solution {
    pub fn is_bipartite(graph: Vec<Vec<i32>>) -> bool {
        let n = graph.len();
        let mut p: Vec<usize> = (0..n).collect();

        fn find(x: usize, p: &mut Vec<usize>) -> usize {
            if p[x] != x {
                p[x] = find(p[x], p);
            }
            p[x]
        }

        for a in 0..n {
            for &b in &graph[a] {
                let pa = find(a, &mut p);
                let pb = find(b as usize, &mut p);
                if pa == pb {
                    return false;
                }
                p[pb] = find(graph[a][0] as usize, &mut p);
            }
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

# [786. 第 K 个最小的质数分数](https://leetcode.cn/problems/k-th-smallest-prime-fraction){#786}

{{< tabs "786" >}}

{{% tab "python" %}}
```python
class Solution:
    def kthSmallestPrimeFraction(self, arr: List[int], k: int) -> List[int]:
        h = [(1 / y, 0, j + 1) for j, y in enumerate(arr[1:])]
        heapify(h)
        for _ in range(k - 1):
            _, i, j = heappop(h)
            if i + 1 < j:
                heappush(h, (arr[i + 1] / arr[j], i + 1, j))
        return [arr[h[0][1]], arr[h[0][2]]]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] kthSmallestPrimeFraction(int[] arr, int k) {
        int n = arr.length;
        Queue<Frac> pq = new PriorityQueue<>();
        for (int i = 1; i < n; i++) {
            pq.offer(new Frac(1, arr[i], 0, i));
        }
        for (int i = 1; i < k; i++) {
            Frac f = pq.poll();
            if (f.i + 1 < f.j) {
                pq.offer(new Frac(arr[f.i + 1], arr[f.j], f.i + 1, f.j));
            }
        }
        Frac f = pq.peek();
        return new int[] {f.x, f.y};
    }

    static class Frac implements Comparable {
        int x, y, i, j;

        public Frac(int x, int y, int i, int j) {
            this.x = x;
            this.y = y;
            this.i = i;
            this.j = j;
        }

        @Override
        public int compareTo(Object o) {
            return x * ((Frac) o).y - ((Frac) o).x * y;
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        using pii = pair<int, int>;
        int n = arr.size();
        auto cmp = [&](const pii& a, const pii& b) {
            return arr[a.first] * arr[b.second] > arr[b.first] * arr[a.second];
        };
        priority_queue<pii, vector<pii>, decltype(cmp)> pq(cmp);
        for (int i = 1; i < n; ++i) {
            pq.push({0, i});
        }
        for (int i = 1; i < k; ++i) {
            pii f = pq.top();
            pq.pop();
            if (f.first + 1 < f.second) {
                pq.push({f.first + 1, f.second});
            }
        }
        return {arr[pq.top().first], arr[pq.top().second]};
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
type frac struct{ x, y, i, j int }
type hp []frac

func (a hp) Len() int           { return len(a) }
func (a hp) Swap(i, j int)      { a[i], a[j] = a[j], a[i] }
func (a hp) Less(i, j int) bool { return a[i].x*a[j].y < a[j].x*a[i].y }
func (a *hp) Push(x any)        { *a = append(*a, x.(frac)) }
func (a *hp) Pop() any          { l := len(*a); tmp := (*a)[l-1]; *a = (*a)[:l-1]; return tmp }

func kthSmallestPrimeFraction(arr []int, k int) []int {
	n := len(arr)
	h := make(hp, 0, n-1)
	for i := 1; i < n; i++ {
		h = append(h, frac{1, arr[i], 0, i})
	}
	heap.Init(&h)
	for i := 1; i < k; i++ {
		f := heap.Pop(&h).(frac)
		if f.i+1 < f.j {
			heap.Push(&h, frac{arr[f.i+1], arr[f.j], f.i + 1, f.j})
		}
	}
	return []int{h[0].x, h[0].y}
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个按递增顺序排序的数组 <code>arr</code> 和一个整数 <code>k</code> 。数组 <code>arr</code> 由 <code>1</code> 和若干 <strong>质数</strong> 组成，且其中所有整数互不相同。</p>

<p>对于每对满足 <code>0 &lt;= i &lt; j &lt; arr.length</code> 的 <code>i</code> 和 <code>j</code> ，可以得到分数 <code>arr[i] / arr[j]</code> 。</p>

<p>那么第&nbsp;<code>k</code>&nbsp;个最小的分数是多少呢?&nbsp; 以长度为 <code>2</code> 的整数数组返回你的答案, 这里&nbsp;<code>answer[0] == arr[i]</code>&nbsp;且&nbsp;<code>answer[1] == arr[j]</code> 。</p>
&nbsp;

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>arr = [1,2,3,5], k = 3
<strong>输出：</strong>[2,5]
<strong>解释：</strong>已构造好的分数,排序后如下所示: 
1/5, 1/3, 2/5, 1/2, 3/5, 2/3
很明显第三个最小的分数是 2/5
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>arr = [1,7], k = 1
<strong>输出：</strong>[1,7]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= arr.length &lt;= 1000</code></li>
	<li><code>1 &lt;= arr[i] &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>arr[0] == 1</code></li>
	<li><code>arr[i]</code> 是一个 <strong>质数</strong> ，<code>i &gt; 0</code></li>
	<li><code>arr</code> 中的所有数字 <strong>互不相同</strong> ，且按 <strong>严格递增</strong> 排序</li>
	<li><code>1 &lt;= k &lt;= arr.length * (arr.length - 1) / 2</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>你可以设计并实现时间复杂度小于 <code>O(n<sup>2</sup>)</code> 的算法解决此问题吗？</p>

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
    def kthSmallestPrimeFraction(self, arr: List[int], k: int) -> List[int]:
        h = [(1 / y, 0, j + 1) for j, y in enumerate(arr[1:])]
        heapify(h)
        for _ in range(k - 1):
            _, i, j = heappop(h)
            if i + 1 < j:
                heappush(h, (arr[i + 1] / arr[j], i + 1, j))
        return [arr[h[0][1]], arr[h[0][2]]]
```

#### Java

```java
class Solution {
    public int[] kthSmallestPrimeFraction(int[] arr, int k) {
        int n = arr.length;
        Queue<Frac> pq = new PriorityQueue<>();
        for (int i = 1; i < n; i++) {
            pq.offer(new Frac(1, arr[i], 0, i));
        }
        for (int i = 1; i < k; i++) {
            Frac f = pq.poll();
            if (f.i + 1 < f.j) {
                pq.offer(new Frac(arr[f.i + 1], arr[f.j], f.i + 1, f.j));
            }
        }
        Frac f = pq.peek();
        return new int[] {f.x, f.y};
    }

    static class Frac implements Comparable {
        int x, y, i, j;

        public Frac(int x, int y, int i, int j) {
            this.x = x;
            this.y = y;
            this.i = i;
            this.j = j;
        }

        @Override
        public int compareTo(Object o) {
            return x * ((Frac) o).y - ((Frac) o).x * y;
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        using pii = pair<int, int>;
        int n = arr.size();
        auto cmp = [&](const pii& a, const pii& b) {
            return arr[a.first] * arr[b.second] > arr[b.first] * arr[a.second];
        };
        priority_queue<pii, vector<pii>, decltype(cmp)> pq(cmp);
        for (int i = 1; i < n; ++i) {
            pq.push({0, i});
        }
        for (int i = 1; i < k; ++i) {
            pii f = pq.top();
            pq.pop();
            if (f.first + 1 < f.second) {
                pq.push({f.first + 1, f.second});
            }
        }
        return {arr[pq.top().first], arr[pq.top().second]};
    }
};
```

#### Go

```go
type frac struct{ x, y, i, j int }
type hp []frac

func (a hp) Len() int           { return len(a) }
func (a hp) Swap(i, j int)      { a[i], a[j] = a[j], a[i] }
func (a hp) Less(i, j int) bool { return a[i].x*a[j].y < a[j].x*a[i].y }
func (a *hp) Push(x any)        { *a = append(*a, x.(frac)) }
func (a *hp) Pop() any          { l := len(*a); tmp := (*a)[l-1]; *a = (*a)[:l-1]; return tmp }

func kthSmallestPrimeFraction(arr []int, k int) []int {
	n := len(arr)
	h := make(hp, 0, n-1)
	for i := 1; i < n; i++ {
		h = append(h, frac{1, arr[i], 0, i})
	}
	heap.Init(&h)
	for i := 1; i < k; i++ {
		f := heap.Pop(&h).(frac)
		if f.i+1 < f.j {
			heap.Push(&h, frac{arr[f.i+1], arr[f.j], f.i + 1, f.j})
		}
	}
	return []int{h[0].x, h[0].y}
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [787. K 站中转内最便宜的航班](https://leetcode.cn/problems/cheapest-flights-within-k-stops){#787}

{{< tabs "787" >}}

{{% tab "python" %}}
```python
class Solution:
    def findCheapestPrice(
        self, n: int, flights: List[List[int]], src: int, dst: int, k: int
    ) -> int:
        @cache
        def dfs(u, k):
            if u == dst:
                return 0
            if k <= 0:
                return inf
            k -= 1
            ans = inf
            for v, p in g[u]:
                ans = min(ans, dfs(v, k) + p)
            return ans

        g = defaultdict(list)
        for u, v, p in flights:
            g[u].append((v, p))
        ans = dfs(src, k + 1)
        return -1 if ans >= inf else ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[][] memo;
    private int[][] g;
    private int dst;
    private static final int INF = (int) 1e6;

    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
        n += 10;
        memo = new int[n][n];
        for (int i = 0; i < n; ++i) {
            Arrays.fill(memo[i], -1);
        }
        g = new int[n][n];
        for (int[] e : flights) {
            g[e[0]][e[1]] = e[2];
        }
        this.dst = dst;
        int ans = dfs(src, k + 1);
        return ans >= INF ? -1 : ans;
    }

    private int dfs(int u, int k) {
        if (memo[u][k] != -1) {
            return memo[u][k];
        }
        if (u == dst) {
            return 0;
        }
        if (k <= 0) {
            return INF;
        }
        int ans = INF;
        for (int v = 0; v < g[u].length; ++v) {
            if (g[u][v] > 0) {
                ans = Math.min(ans, dfs(v, k - 1) + g[u][v]);
            }
        }
        memo[u][k] = ans;
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<vector<int>> memo;
    vector<vector<int>> g;
    int dst;
    int inf = 1e6;

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        n += 10;
        memo.resize(n, vector<int>(n, -1));
        g.resize(n, vector<int>(n));
        for (auto& e : flights) g[e[0]][e[1]] = e[2];
        this->dst = dst;
        int ans = dfs(src, k + 1);
        return ans >= inf ? -1 : ans;
    }

    int dfs(int u, int k) {
        if (memo[u][k] != -1) return memo[u][k];
        if (u == dst) return 0;
        if (k <= 0) return inf;
        int ans = inf;
        for (int v = 0; v < g[u].size(); ++v)
            if (g[u][v] > 0)
                ans = min(ans, dfs(v, k - 1) + g[u][v]);
        memo[u][k] = ans;
        return memo[u][k];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findCheapestPrice(n int, flights [][]int, src int, dst int, k int) int {
	n += 10
	memo := make([][]int, n)
	g := make([][]int, n)
	for i := range memo {
		memo[i] = make([]int, n)
		g[i] = make([]int, n)
		for j := range memo[i] {
			memo[i][j] = -1
		}
	}

	for _, e := range flights {
		g[e[0]][e[1]] = e[2]
	}
	inf := int(1e6)
	var dfs func(u, k int) int
	dfs = func(u, k int) int {
		if memo[u][k] != -1 {
			return memo[u][k]
		}
		if u == dst {
			return 0
		}
		if k <= 0 {
			return inf
		}
		ans := inf
		for v, p := range g[u] {
			if p > 0 {
				ans = min(ans, dfs(v, k-1)+p)
			}
		}
		memo[u][k] = ans
		return ans
	}
	ans := dfs(src, k+1)
	if ans >= inf {
		return -1
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

<p>有 <code>n</code> 个城市通过一些航班连接。给你一个数组&nbsp;<code>flights</code> ，其中&nbsp;<code>flights[i] = [from<sub>i</sub>, to<sub>i</sub>, price<sub>i</sub>]</code> ，表示该航班都从城市 <code>from<sub>i</sub></code> 开始，以价格 <code>price<sub>i</sub></code> 抵达 <code>to<sub>i</sub></code>。</p>

<p>现在给定所有的城市和航班，以及出发城市 <code>src</code> 和目的地 <code>dst</code>，你的任务是找到出一条最多经过 <code>k</code>&nbsp;站中转的路线，使得从 <code>src</code> 到 <code>dst</code> 的 <strong>价格最便宜</strong> ，并返回该价格。 如果不存在这样的路线，则输出 <code>-1</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0700-0799/0787.Cheapest%20Flights%20Within%20K%20Stops/images/cheapest-flights-within-k-stops-3drawio.png" style="width: 332px; height: 392px;" />
<pre>
<strong>输入:</strong> 
n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
<strong>输出:</strong> 700 
<strong>解释:</strong> 城市航班图如上
从城市 0 到城市 3 经过最多 1 站的最佳路径用红色标记，费用为 100 + 600 = 700。
请注意，通过城市 [0, 1, 2, 3] 的路径更便宜，但无效，因为它经过了 2 站。
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0700-0799/0787.Cheapest%20Flights%20Within%20K%20Stops/images/cheapest-flights-within-k-stops-1drawio.png" style="width: 332px; height: 242px;" />
<pre>
<strong>输入:</strong> 
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
<strong>输出:</strong> 200
<strong>解释:</strong> 
城市航班图如上
从城市 0 到城市 2 经过最多 1 站的最佳路径标记为红色，费用为 100 + 100 = 200。
</pre>

<p><strong class="example">示例 3：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0700-0799/0787.Cheapest%20Flights%20Within%20K%20Stops/images/cheapest-flights-within-k-stops-2drawio.png" style="width: 332px; height: 242px;" />
<pre>
<b>输入：</b>n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
<b>输出：</b>500
<strong>解释：</strong>
城市航班图如上
从城市 0 到城市 2 不经过站点的最佳路径标记为红色，费用为 500。
</pre>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>0 &lt;= flights.length &lt;= (n * (n - 1) / 2)</code></li>
	<li><code>flights[i].length == 3</code></li>
	<li><code>0 &lt;= from<sub>i</sub>, to<sub>i</sub> &lt; n</code></li>
	<li><code>from<sub>i</sub> != to<sub>i</sub></code></li>
	<li><code>1 &lt;= price<sub>i</sub> &lt;= 10<sup>4</sup></code></li>
	<li>航班没有重复，且不存在自环</li>
	<li><code>0 &lt;= src, dst, k &lt; n</code></li>
	<li><code>src != dst</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：Bellman Ford 算法

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findCheapestPrice(
        self, n: int, flights: List[List[int]], src: int, dst: int, k: int
    ) -> int:
        INF = 0x3F3F3F3F
        dist = [INF] * n
        dist[src] = 0
        for _ in range(k + 1):
            backup = dist.copy()
            for f, t, p in flights:
                dist[t] = min(dist[t], backup[f] + p)
        return -1 if dist[dst] == INF else dist[dst]
```

#### Java

```java
class Solution {
    private static final int INF = 0x3f3f3f3f;

    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
        int[] dist = new int[n];
        int[] backup = new int[n];
        Arrays.fill(dist, INF);
        dist[src] = 0;
        for (int i = 0; i < k + 1; ++i) {
            System.arraycopy(dist, 0, backup, 0, n);
            for (int[] e : flights) {
                int f = e[0], t = e[1], p = e[2];
                dist[t] = Math.min(dist[t], backup[f] + p);
            }
        }
        return dist[dst] == INF ? -1 : dist[dst];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        const int inf = 0x3f3f3f3f;
        vector<int> dist(n, inf);
        vector<int> backup;
        dist[src] = 0;
        for (int i = 0; i < k + 1; ++i) {
            backup = dist;
            for (auto& e : flights) {
                int f = e[0], t = e[1], p = e[2];
                dist[t] = min(dist[t], backup[f] + p);
            }
        }
        return dist[dst] == inf ? -1 : dist[dst];
    }
};
```

#### Go

```go
func findCheapestPrice(n int, flights [][]int, src int, dst int, k int) int {
	const inf = 0x3f3f3f3f
	dist := make([]int, n)
	backup := make([]int, n)
	for i := range dist {
		dist[i] = inf
	}
	dist[src] = 0
	for i := 0; i < k+1; i++ {
		copy(backup, dist)
		for _, e := range flights {
			f, t, p := e[0], e[1], e[2]
			dist[t] = min(dist[t], backup[f]+p)
		}
	}
	if dist[dst] == inf {
		return -1
	}
	return dist[dst]
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：DFS + 记忆化搜索

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findCheapestPrice(
        self, n: int, flights: List[List[int]], src: int, dst: int, k: int
    ) -> int:
        @cache
        def dfs(u, k):
            if u == dst:
                return 0
            if k <= 0:
                return inf
            k -= 1
            ans = inf
            for v, p in g[u]:
                ans = min(ans, dfs(v, k) + p)
            return ans

        g = defaultdict(list)
        for u, v, p in flights:
            g[u].append((v, p))
        ans = dfs(src, k + 1)
        return -1 if ans >= inf else ans
```

#### Java

```java
class Solution {
    private int[][] memo;
    private int[][] g;
    private int dst;
    private static final int INF = (int) 1e6;

    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
        n += 10;
        memo = new int[n][n];
        for (int i = 0; i < n; ++i) {
            Arrays.fill(memo[i], -1);
        }
        g = new int[n][n];
        for (int[] e : flights) {
            g[e[0]][e[1]] = e[2];
        }
        this.dst = dst;
        int ans = dfs(src, k + 1);
        return ans >= INF ? -1 : ans;
    }

    private int dfs(int u, int k) {
        if (memo[u][k] != -1) {
            return memo[u][k];
        }
        if (u == dst) {
            return 0;
        }
        if (k <= 0) {
            return INF;
        }
        int ans = INF;
        for (int v = 0; v < g[u].length; ++v) {
            if (g[u][v] > 0) {
                ans = Math.min(ans, dfs(v, k - 1) + g[u][v]);
            }
        }
        memo[u][k] = ans;
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<vector<int>> memo;
    vector<vector<int>> g;
    int dst;
    int inf = 1e6;

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        n += 10;
        memo.resize(n, vector<int>(n, -1));
        g.resize(n, vector<int>(n));
        for (auto& e : flights) g[e[0]][e[1]] = e[2];
        this->dst = dst;
        int ans = dfs(src, k + 1);
        return ans >= inf ? -1 : ans;
    }

    int dfs(int u, int k) {
        if (memo[u][k] != -1) return memo[u][k];
        if (u == dst) return 0;
        if (k <= 0) return inf;
        int ans = inf;
        for (int v = 0; v < g[u].size(); ++v)
            if (g[u][v] > 0)
                ans = min(ans, dfs(v, k - 1) + g[u][v]);
        memo[u][k] = ans;
        return memo[u][k];
    }
};
```

#### Go

```go
func findCheapestPrice(n int, flights [][]int, src int, dst int, k int) int {
	n += 10
	memo := make([][]int, n)
	g := make([][]int, n)
	for i := range memo {
		memo[i] = make([]int, n)
		g[i] = make([]int, n)
		for j := range memo[i] {
			memo[i][j] = -1
		}
	}

	for _, e := range flights {
		g[e[0]][e[1]] = e[2]
	}
	inf := int(1e6)
	var dfs func(u, k int) int
	dfs = func(u, k int) int {
		if memo[u][k] != -1 {
			return memo[u][k]
		}
		if u == dst {
			return 0
		}
		if k <= 0 {
			return inf
		}
		ans := inf
		for v, p := range g[u] {
			if p > 0 {
				ans = min(ans, dfs(v, k-1)+p)
			}
		}
		memo[u][k] = ans
		return ans
	}
	ans := dfs(src, k+1)
	if ans >= inf {
		return -1
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [788. 旋转数字](https://leetcode.cn/problems/rotated-digits){#788}

{{< tabs "788" >}}

{{% tab "python" %}}
```python
class Solution:
    def rotatedDigits(self, n: int) -> int:
        @cache
        def dfs(i: int, ok: int, limit: bool) -> int:
            if i >= len(s):
                return ok
            up = int(s[i]) if limit else 9
            ans = 0
            for j in range(up + 1):
                if j in (0, 1, 8):
                    ans += dfs(i + 1, ok, limit and j == up)
                elif j in (2, 5, 6, 9):
                    ans += dfs(i + 1, 1, limit and j == up)
            return ans

        s = str(n)
        return dfs(0, 0, True)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private char[] s;
    private Integer[][] f;

    public int rotatedDigits(int n) {
        s = String.valueOf(n).toCharArray();
        f = new Integer[s.length][2];
        return dfs(0, 0, true);
    }

    private int dfs(int i, int ok, boolean limit) {
        if (i >= s.length) {
            return ok;
        }
        if (!limit && f[i][ok] != null) {
            return f[i][ok];
        }
        int up = limit ? s[i] - '0' : 9;
        int ans = 0;
        for (int j = 0; j <= up; ++j) {
            if (j == 0 || j == 1 || j == 8) {
                ans += dfs(i + 1, ok, limit && j == up);
            } else if (j == 2 || j == 5 || j == 6 || j == 9) {
                ans += dfs(i + 1, 1, limit && j == up);
            }
        }
        if (!limit) {
            f[i][ok] = ans;
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
    int rotatedDigits(int n) {
        string s = to_string(n);
        int m = s.size();
        int f[m][2];
        memset(f, -1, sizeof(f));
        auto dfs = [&](this auto&& dfs, int i, int ok, bool limit) -> int {
            if (i >= m) {
                return ok;
            }
            if (!limit && f[i][ok] != -1) {
                return f[i][ok];
            }
            int up = limit ? s[i] - '0' : 9;
            int ans = 0;
            for (int j = 0; j <= up; ++j) {
                if (j == 0 || j == 1 || j == 8) {
                    ans += dfs(i + 1, ok, limit && j == up);
                } else if (j == 2 || j == 5 || j == 6 || j == 9) {
                    ans += dfs(i + 1, 1, limit && j == up);
                }
            }
            if (!limit) {
                f[i][ok] = ans;
            }
            return ans;
        };
        return dfs(0, 0, true);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func rotatedDigits(n int) int {
	s := strconv.Itoa(n)
	m := len(s)
	f := make([][2]int, m)
	for i := range f {
		f[i] = [2]int{-1, -1}
	}
	var dfs func(i, ok int, limit bool) int
	dfs = func(i, ok int, limit bool) int {
		if i >= m {
			return ok
		}
		if !limit && f[i][ok] != -1 {
			return f[i][ok]
		}
		up := 9
		if limit {
			up = int(s[i] - '0')
		}
		ans := 0
		for j := 0; j <= up; j++ {
			if j == 0 || j == 1 || j == 8 {
				ans += dfs(i+1, ok, limit && j == up)
			} else if j == 2 || j == 5 || j == 6 || j == 9 {
				ans += dfs(i+1, 1, limit && j == up)
			}
		}
		if !limit {
			f[i][ok] = ans
		}
		return ans
	}
	return dfs(0, 0, true)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function rotatedDigits(n: number): number {
    const s = n.toString();
    const m = s.length;
    const f: number[][] = Array.from({ length: m }, () => Array(2).fill(-1));
    const dfs = (i: number, ok: number, limit: boolean): number => {
        if (i >= m) {
            return ok;
        }
        if (!limit && f[i][ok] !== -1) {
            return f[i][ok];
        }
        const up = limit ? +s[i] : 9;
        let ans = 0;
        for (let j = 0; j <= up; ++j) {
            if ([0, 1, 8].includes(j)) {
                ans += dfs(i + 1, ok, limit && j === up);
            } else if ([2, 5, 6, 9].includes(j)) {
                ans += dfs(i + 1, 1, limit && j === up);
            }
        }
        if (!limit) {
            f[i][ok] = ans;
        }
        return ans;
    };
    return dfs(0, 0, true);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>我们称一个数 X 为好数, 如果它的每位数字逐个地被旋转 180 度后，我们仍可以得到一个有效的，且和 X 不同的数。要求每位数字都要被旋转。</p>

<p>如果一个数的每位数字被旋转以后仍然还是一个数字，&nbsp;则这个数是有效的。0, 1, 和 8 被旋转后仍然是它们自己；2 和 5 可以互相旋转成对方（在这种情况下，它们以不同的方向旋转，换句话说，2 和 5 互为镜像）；6 和 9 同理，除了这些以外其他的数字旋转以后都不再是有效的数字。</p>

<p>现在我们有一个正整数&nbsp;<code>N</code>, 计算从&nbsp;<code>1</code> 到&nbsp;<code>N</code> 中有多少个数&nbsp;X 是好数？</p>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre><strong>输入:</strong> 10
<strong>输出:</strong> 4
<strong>解释:</strong> 
在[1, 10]中有四个好数： 2, 5, 6, 9。
注意 1 和 10 不是好数, 因为他们在旋转之后不变。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>N&nbsp;的取值范围是&nbsp;<code>[1, 10000]</code>。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：直接枚举

一种直观且有效的思路是，直接枚举 $[1,2,..n]$ 中的每个数，判断其是否为好数，若为好数，则答案加一。

那么题目的重点转化为如何判断一个数字 $x$ 是否为好数。判断的逻辑如下：

我们先用一个长度为 $10$ 的数组 $d$ 记录每个有效数字对应的旋转数字，在这道题中，有效数字有 $[0, 1, 8, 2, 5, 6, 9]$，分别对应旋转数字 $[0, 1, 8, 5, 2, 9, 6]$。如果不是有效数字，我们将对应的旋转数字设为 $-1$。

然后遍历数字 $x$ 的每一位数字 $v$，如果 $v$ 不是有效数字，说明 $x$ 不是好数，直接返回 $\textit{false}$。否则，我们将数字 $v$ 对应的旋转数字 $d[v]$ 加入到 $y$ 中。最后，判断 $x$ 和 $y$ 是否相等，若不相等，则说明 $x$ 是好数，返回 $\textit{true}$。

时间复杂度 $O(n \times \log n)$，其中 $n$ 为题目给定的数字。空间复杂度 $O(1)$。

相似题目：

-   [1056. 易混淆数](https://github.com/doocs/leetcode/blob/main/solution/1000-1099/1056.Confusing%20Number/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def rotatedDigits(self, n: int) -> int:
        def check(x):
            y, t = 0, x
            k = 1
            while t:
                v = t % 10
                if d[v] == -1:
                    return False
                y = d[v] * k + y
                k *= 10
                t //= 10
            return x != y

        d = [0, 1, 5, -1, -1, 2, 9, -1, 8, 6]
        return sum(check(i) for i in range(1, n + 1))
```

#### Java

```java
class Solution {
    private int[] d = new int[] {0, 1, 5, -1, -1, 2, 9, -1, 8, 6};

    public int rotatedDigits(int n) {
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (check(i)) {
                ++ans;
            }
        }
        return ans;
    }

    private boolean check(int x) {
        int y = 0, t = x;
        int k = 1;
        while (t > 0) {
            int v = t % 10;
            if (d[v] == -1) {
                return false;
            }
            y = d[v] * k + y;
            k *= 10;
            t /= 10;
        }
        return x != y;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int rotatedDigits(int n) {
        int d[10] = {0, 1, 5, -1, -1, 2, 9, -1, 8, 6};
        auto check = [&](int x) -> bool {
            int y = 0, t = x;
            int k = 1;
            while (t) {
                int v = t % 10;
                if (d[v] == -1) {
                    return false;
                }
                y = d[v] * k + y;
                k *= 10;
                t /= 10;
            }
            return x != y;
        };
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            ans += check(i);
        }
        return ans;
    }
};
```

#### Go

```go
func rotatedDigits(n int) int {
	d := []int{0, 1, 5, -1, -1, 2, 9, -1, 8, 6}
	check := func(x int) bool {
		y, t := 0, x
		k := 1
		for ; t > 0; t /= 10 {
			v := t % 10
			if d[v] == -1 {
				return false
			}
			y = d[v]*k + y
			k *= 10
		}
		return x != y
	}
	ans := 0
	for i := 1; i <= n; i++ {
		if check(i) {
			ans++
		}
	}
	return ans
}
```

#### TypeScript

```ts
function rotatedDigits(n: number): number {
    const d: number[] = [0, 1, 5, -1, -1, 2, 9, -1, 8, 6];
    const check = (x: number): boolean => {
        let y = 0;
        let t = x;
        let k = 1;

        while (t > 0) {
            const v = t % 10;
            if (d[v] === -1) {
                return false;
            }
            y = d[v] * k + y;
            k *= 10;
            t = Math.floor(t / 10);
        }
        return x !== y;
    };
    return Array.from({ length: n }, (_, i) => i + 1).filter(check).length;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：数位 DP

方法一的做法足以通过本题，但时间复杂度较高。如果题目的数据范围达到 $10^9$ 级别，则方法一的做法会超出时间限制。

这道题实际上是求在给定区间 $[l,..r]$ 中，满足条件的数的个数。条件与数的大小无关，而只与数的组成有关，因此可以使用数位 DP 的思想求解。数位 DP 中，数的大小对复杂度的影响很小。

对于区间 $[l,..r]$ 问题，我们一般会将其转化为 $[1,..r]$ 然后再减去 $[1,..l - 1]$ 的问题，即：

$$
ans = \sum_{i=1}^{r} ans_i -  \sum_{i=1}^{l-1} ans_i
$$

不过对于本题而言，我们只需要求出区间 $[1,..r]$ 的值即可。

这里我们用记忆化搜索来实现数位 DP。从起点向下搜索，到最底层得到方案数，一层层向上返回答案并累加，最后从搜索起点得到最终的答案。

基本步骤如下：

我们将数字 $n$ 转为字符串 $s$。然后定义函数 $\textit{dfs}(i, \textit{ok}, \textit{limit})$，其中 $i$ 表示数字的位数，数字 $\textit{ok}$ 表示当前数字是否满足题目要求，布尔值 $\textit{limit}$ 表示可填的数字的限制。

函数的执行逻辑如下：

如果 $i$ 大于等于字符串 $s$ 的长度，返回 $\textit{ok}$；

否则，我们获取当前位的数字 $up$，如果 $\textit{limit}$ 为 $\textit{true}$，则 $up$ 为当前位的数字，否则 $up$ 为 $9$；

接下来，我们遍历 $[0,..up]$，如果 $j$ 是有效数字 $[0, 1, 8]$，则递归调用 $\textit{dfs}(i + 1, \textit{ok}, \textit{limit} \land j = \textit{up})$；如果 $j$ 是有效数字 $[2, 5, 6, 9]$，则递归调用 $\textit{dfs}(i + 1, 1, \textit{limit} \land j = \textit{up})$；将所有递归调用的结果累加并返回。

时间复杂度 $O(\log n \times D)$，空间复杂度 $O(\log n)$。其中 $D = 10$。

相似题目：

-   [233. 数字 1 的个数](https://github.com/doocs/leetcode/blob/main/solution/0200-0299/0233.Number%20of%20Digit%20One/README.md)
-   [357. 统计各位数字都不同的数字个数](https://github.com/doocs/leetcode/blob/main/solution/0300-0399/0357.Count%20Numbers%20with%20Unique%20Digits/README.md)
-   [600. 不含连续 1 的非负整数](https://github.com/doocs/leetcode/blob/main/solution/0600-0699/0600.Non-negative%20Integers%20without%20Consecutive%20Ones/README.md)
-   [902. 最大为 N 的数字组合](https://github.com/doocs/leetcode/blob/main/solution/0900-0999/0902.Numbers%20At%20Most%20N%20Given%20Digit%20Set/README.md)
-   [1012. 至少有 1 位重复的数字](https://github.com/doocs/leetcode/blob/main/solution/1000-1099/1012.Numbers%20With%20Repeated%20Digits/README.md)
-   [2376. 统计特殊整数](https://github.com/doocs/leetcode/blob/main/solution/2300-2399/2376.Count%20Special%20Integers/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def rotatedDigits(self, n: int) -> int:
        @cache
        def dfs(i: int, ok: int, limit: bool) -> int:
            if i >= len(s):
                return ok
            up = int(s[i]) if limit else 9
            ans = 0
            for j in range(up + 1):
                if j in (0, 1, 8):
                    ans += dfs(i + 1, ok, limit and j == up)
                elif j in (2, 5, 6, 9):
                    ans += dfs(i + 1, 1, limit and j == up)
            return ans

        s = str(n)
        return dfs(0, 0, True)
```

#### Java

```java
class Solution {
    private char[] s;
    private Integer[][] f;

    public int rotatedDigits(int n) {
        s = String.valueOf(n).toCharArray();
        f = new Integer[s.length][2];
        return dfs(0, 0, true);
    }

    private int dfs(int i, int ok, boolean limit) {
        if (i >= s.length) {
            return ok;
        }
        if (!limit && f[i][ok] != null) {
            return f[i][ok];
        }
        int up = limit ? s[i] - '0' : 9;
        int ans = 0;
        for (int j = 0; j <= up; ++j) {
            if (j == 0 || j == 1 || j == 8) {
                ans += dfs(i + 1, ok, limit && j == up);
            } else if (j == 2 || j == 5 || j == 6 || j == 9) {
                ans += dfs(i + 1, 1, limit && j == up);
            }
        }
        if (!limit) {
            f[i][ok] = ans;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int rotatedDigits(int n) {
        string s = to_string(n);
        int m = s.size();
        int f[m][2];
        memset(f, -1, sizeof(f));
        auto dfs = [&](this auto&& dfs, int i, int ok, bool limit) -> int {
            if (i >= m) {
                return ok;
            }
            if (!limit && f[i][ok] != -1) {
                return f[i][ok];
            }
            int up = limit ? s[i] - '0' : 9;
            int ans = 0;
            for (int j = 0; j <= up; ++j) {
                if (j == 0 || j == 1 || j == 8) {
                    ans += dfs(i + 1, ok, limit && j == up);
                } else if (j == 2 || j == 5 || j == 6 || j == 9) {
                    ans += dfs(i + 1, 1, limit && j == up);
                }
            }
            if (!limit) {
                f[i][ok] = ans;
            }
            return ans;
        };
        return dfs(0, 0, true);
    }
};
```

#### Go

```go
func rotatedDigits(n int) int {
	s := strconv.Itoa(n)
	m := len(s)
	f := make([][2]int, m)
	for i := range f {
		f[i] = [2]int{-1, -1}
	}
	var dfs func(i, ok int, limit bool) int
	dfs = func(i, ok int, limit bool) int {
		if i >= m {
			return ok
		}
		if !limit && f[i][ok] != -1 {
			return f[i][ok]
		}
		up := 9
		if limit {
			up = int(s[i] - '0')
		}
		ans := 0
		for j := 0; j <= up; j++ {
			if j == 0 || j == 1 || j == 8 {
				ans += dfs(i+1, ok, limit && j == up)
			} else if j == 2 || j == 5 || j == 6 || j == 9 {
				ans += dfs(i+1, 1, limit && j == up)
			}
		}
		if !limit {
			f[i][ok] = ans
		}
		return ans
	}
	return dfs(0, 0, true)
}
```

#### TypeScript

```ts
function rotatedDigits(n: number): number {
    const s = n.toString();
    const m = s.length;
    const f: number[][] = Array.from({ length: m }, () => Array(2).fill(-1));
    const dfs = (i: number, ok: number, limit: boolean): number => {
        if (i >= m) {
            return ok;
        }
        if (!limit && f[i][ok] !== -1) {
            return f[i][ok];
        }
        const up = limit ? +s[i] : 9;
        let ans = 0;
        for (let j = 0; j <= up; ++j) {
            if ([0, 1, 8].includes(j)) {
                ans += dfs(i + 1, ok, limit && j === up);
            } else if ([2, 5, 6, 9].includes(j)) {
                ans += dfs(i + 1, 1, limit && j === up);
            }
        }
        if (!limit) {
            f[i][ok] = ans;
        }
        return ans;
    };
    return dfs(0, 0, true);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [789. 逃脱阻碍者](https://leetcode.cn/problems/escape-the-ghosts){#789}

{{< tabs "789" >}}

{{% tab "python" %}}
```python
class Solution:
    def escapeGhosts(self, ghosts: List[List[int]], target: List[int]) -> bool:
        tx, ty = target
        return all(abs(tx - x) + abs(ty - y) > abs(tx) + abs(ty) for x, y in ghosts)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean escapeGhosts(int[][] ghosts, int[] target) {
        int tx = target[0], ty = target[1];
        for (var g : ghosts) {
            int x = g[0], y = g[1];
            if (Math.abs(tx - x) + Math.abs(ty - y) <= Math.abs(tx) + Math.abs(ty)) {
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
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int tx = target[0], ty = target[1];
        for (auto& g : ghosts) {
            int x = g[0], y = g[1];
            if (abs(tx - x) + abs(ty - y) <= abs(tx) + abs(ty)) {
                return false;
            }
        }
        return true;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func escapeGhosts(ghosts [][]int, target []int) bool {
	tx, ty := target[0], target[1]
	for _, g := range ghosts {
		x, y := g[0], g[1]
		if abs(tx-x)+abs(ty-y) <= abs(tx)+abs(ty) {
			return false
		}
	}
	return true
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
function escapeGhosts(ghosts: number[][], target: number[]): boolean {
    const [tx, ty] = target;
    for (const [x, y] of ghosts) {
        if (Math.abs(tx - x) + Math.abs(ty - y) <= Math.abs(tx) + Math.abs(ty)) {
            return false;
        }
    }
    return true;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你在进行一个简化版的吃豆人游戏。你从 <code>[0, 0]</code> 点开始出发，你的目的地是&nbsp;<code>target = [x<sub>target</sub>, y<sub>target</sub>]</code> 。地图上有一些阻碍者，以数组 <code>ghosts</code> 给出，第 <code>i</code> 个阻碍者从&nbsp;<code>ghosts[i] = [x<sub>i</sub>, y<sub>i</sub>]</code>&nbsp;出发。所有输入均为 <strong>整数坐标</strong> 。</p>

<p>每一回合，你和阻碍者们可以同时向东，西，南，北四个方向移动，每次可以移动到距离原位置 <strong>1 个单位</strong> 的新位置。当然，也可以选择 <strong>不动</strong> 。所有动作 <strong>同时</strong> 发生。</p>

<p>如果你可以在任何阻碍者抓住你 <strong>之前</strong> 到达目的地（阻碍者可以采取任意行动方式），则被视为逃脱成功。如果你和阻碍者 <strong>同时</strong> 到达了一个位置（包括目的地）&nbsp;<strong>都不算</strong>&nbsp;是逃脱成功。</p>

<p>如果不管阻碍者怎么移动都可以成功逃脱时，输出 <code>true</code> ；否则，输出 <code>false</code> 。</p>
&nbsp;

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>ghosts = [[1,0],[0,3]], target = [0,1]
<strong>输出：</strong>true
<strong>解释：</strong>你可以直接一步到达目的地 (0,1) ，在 (1, 0) 或者 (0, 3) 位置的阻碍者都不可能抓住你。 
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>ghosts = [[1,0]], target = [2,0]
<strong>输出：</strong>false
<strong>解释：</strong>你需要走到位于 (2, 0) 的目的地，但是在 (1, 0) 的阻碍者位于你和目的地之间。 
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>ghosts = [[2,0]], target = [1,0]
<strong>输出：</strong>false
<strong>解释：</strong>阻碍者可以和你同时达到目的地。 
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= ghosts.length &lt;= 100</code></li>
	<li><code>ghosts[i].length == 2</code></li>
	<li><code>-10<sup>4</sup> &lt;= x<sub>i</sub>, y<sub>i</sub> &lt;= 10<sup>4</sup></code></li>
	<li>同一位置可能有 <strong>多个阻碍者</strong> 。</li>
	<li><code>target.length == 2</code></li>
	<li><code>-10<sup>4</sup> &lt;= x<sub>target</sub>, y<sub>target</sub> &lt;= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：曼哈顿距离

对于任意一个阻碍者，如果它到目的地的曼哈顿距离小于等于你到目的地的曼哈顿距离，那么它就可以在你到达目的地之前抓住你。因此，我们只需要判断所有阻碍者到目的地的曼哈顿距离是否都大于你到目的地的曼哈顿距离即可。

时间复杂度 $O(n)$，空间复杂度 $O(1)$。其中 $n$ 为阻碍者的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def escapeGhosts(self, ghosts: List[List[int]], target: List[int]) -> bool:
        tx, ty = target
        return all(abs(tx - x) + abs(ty - y) > abs(tx) + abs(ty) for x, y in ghosts)
```

#### Java

```java
class Solution {
    public boolean escapeGhosts(int[][] ghosts, int[] target) {
        int tx = target[0], ty = target[1];
        for (var g : ghosts) {
            int x = g[0], y = g[1];
            if (Math.abs(tx - x) + Math.abs(ty - y) <= Math.abs(tx) + Math.abs(ty)) {
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
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int tx = target[0], ty = target[1];
        for (auto& g : ghosts) {
            int x = g[0], y = g[1];
            if (abs(tx - x) + abs(ty - y) <= abs(tx) + abs(ty)) {
                return false;
            }
        }
        return true;
    }
};
```

#### Go

```go
func escapeGhosts(ghosts [][]int, target []int) bool {
	tx, ty := target[0], target[1]
	for _, g := range ghosts {
		x, y := g[0], g[1]
		if abs(tx-x)+abs(ty-y) <= abs(tx)+abs(ty) {
			return false
		}
	}
	return true
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
function escapeGhosts(ghosts: number[][], target: number[]): boolean {
    const [tx, ty] = target;
    for (const [x, y] of ghosts) {
        if (Math.abs(tx - x) + Math.abs(ty - y) <= Math.abs(tx) + Math.abs(ty)) {
            return false;
        }
    }
    return true;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
