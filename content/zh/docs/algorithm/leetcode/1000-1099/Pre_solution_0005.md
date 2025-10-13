---
title: "1040_移动石子直到连续 II"
date: 2025-10-08T18:36:50+08:00
weight: 5
tags: [二分查找, 动态规划, 双指针, 后缀数组, 哈希函数, 哈希表, 图, 堆（优先队列）, 字符串, 广度优先搜索, 排序, 数学, 数据库, 数组, 栈, 模拟, 深度优先搜索, 滑动窗口, 滚动哈希]
---

{{< markmap >}}
### [1040_移动石子直到连续 II](#1040)
#### [数组](#1040)
#### [数学](#1040)
#### [排序](#1040)
#### [滑动窗口](#1040)
### [1041_困于环中的机器人](#1041)
#### [数学](#1041)
#### [字符串](#1041)
#### [模拟](#1041)
### [1042_不邻接植花](#1042)
#### [深度优先搜索](#1042)
#### [广度优先搜索](#1042)
#### [图](#1042)
### [1043_分隔数组以得到最大和](#1043)
#### [数组](#1043)
#### [动态规划](#1043)
### [1044_最长重复子串](#1044)
#### [字符串](#1044)
#### [二分查找](#1044)
#### [后缀数组](#1044)
#### [滑动窗口](#1044)
#### [哈希函数](#1044)
#### [滚动哈希](#1044)
### [1045_买下所有产品的客户](#1045)
#### [数据库](#1045)
### [1046_最后一块石头的重量](#1046)
#### [数组](#1046)
#### [堆（优先队列）](#1046)
### [1047_删除字符串中的所有相邻重复项](#1047)
#### [栈](#1047)
#### [字符串](#1047)
### [1048_最长字符串链](#1048)
#### [数组](#1048)
#### [哈希表](#1048)
#### [双指针](#1048)
#### [字符串](#1048)
#### [动态规划](#1048)
#### [排序](#1048)
### [1049_最后一块石头的重量 II](#1049)
#### [数组](#1049)
#### [动态规划](#1049)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1040_移动石子直到连续 II
___
#### 数组
___
#### 数学
___
#### 排序
___
#### 滑动窗口
---
### 1041_困于环中的机器人
___
#### 数学
___
#### 字符串
___
#### 模拟
---
### 1042_不邻接植花
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 图
---
### 1043_分隔数组以得到最大和
___
#### 数组
___
#### 动态规划
---
### 1044_最长重复子串
___
#### 字符串
___
#### 二分查找
___
#### 后缀数组
___
#### 滑动窗口
___
#### 哈希函数
___
#### 滚动哈希
---
### 1045_买下所有产品的客户
___
#### 数据库
---
### 1046_最后一块石头的重量
___
#### 数组
___
#### 堆（优先队列）
---
### 1047_删除字符串中的所有相邻重复项
___
#### 栈
___
#### 字符串
---
### 1048_最长字符串链
___
#### 数组
___
#### 哈希表
___
#### 双指针
___
#### 字符串
___
#### 动态规划
___
#### 排序
---
### 1049_最后一块石头的重量 II
___
#### 数组
___
#### 动态规划
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 动态规划 | 双指针 |
| 后缀数组 | 哈希函数 | 哈希表 |
| 图 | 堆（优先队列） | 字符串 |
| 广度优先搜索 | 排序 | 数学 |
| 数据库 | 数组 | 栈 |
| 模拟 | 深度优先搜索 | 滑动窗口 |
| 滚动哈希 |  |  |

# [1040. 移动石子直到连续 II](https://leetcode.cn/problems/moving-stones-until-consecutive-ii){#1040}

{{< tabs "1040" >}}

{{% tab "python" %}}
```python
class Solution:
    def numMovesStonesII(self, stones: List[int]) -> List[int]:
        stones.sort()
        mi = n = len(stones)
        mx = max(stones[-1] - stones[1] + 1, stones[-2] - stones[0] + 1) - (n - 1)
        i = 0
        for j, x in enumerate(stones):
            while x - stones[i] + 1 > n:
                i += 1
            if j - i + 1 == n - 1 and x - stones[i] == n - 2:
                mi = min(mi, 2)
            else:
                mi = min(mi, n - (j - i + 1))
        return [mi, mx]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] numMovesStonesII(int[] stones) {
        Arrays.sort(stones);
        int n = stones.length;
        int mi = n;
        int mx = Math.max(stones[n - 1] - stones[1] + 1, stones[n - 2] - stones[0] + 1) - (n - 1);
        for (int i = 0, j = 0; j < n; ++j) {
            while (stones[j] - stones[i] + 1 > n) {
                ++i;
            }
            if (j - i + 1 == n - 1 && stones[j] - stones[i] == n - 2) {
                mi = Math.min(mi, 2);
            } else {
                mi = Math.min(mi, n - (j - i + 1));
            }
        }
        return new int[] {mi, mx};
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        sort(stones.begin(), stones.end());
        int n = stones.size();
        int mi = n;
        int mx = max(stones[n - 1] - stones[1] + 1, stones[n - 2] - stones[0] + 1) - (n - 1);
        for (int i = 0, j = 0; j < n; ++j) {
            while (stones[j] - stones[i] + 1 > n) {
                ++i;
            }
            if (j - i + 1 == n - 1 && stones[j] - stones[i] == n - 2) {
                mi = min(mi, 2);
            } else {
                mi = min(mi, n - (j - i + 1));
            }
        }
        return {mi, mx};
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numMovesStonesII(stones []int) []int {
	sort.Ints(stones)
	n := len(stones)
	mi := n
	mx := max(stones[n-1]-stones[1]+1, stones[n-2]-stones[0]+1) - (n - 1)
	i := 0
	for j, x := range stones {
		for x-stones[i]+1 > n {
			i++
		}
		if j-i+1 == n-1 && stones[j]-stones[i] == n-2 {
			mi = min(mi, 2)
		} else {
			mi = min(mi, n-(j-i+1))
		}
	}
	return []int{mi, mx}
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numMovesStonesII(stones: number[]): number[] {
    stones.sort((a, b) => a - b);
    const n = stones.length;
    let mi = n;
    const mx = Math.max(stones[n - 1] - stones[1] + 1, stones[n - 2] - stones[0] + 1) - (n - 1);
    for (let i = 0, j = 0; j < n; ++j) {
        while (stones[j] - stones[i] + 1 > n) {
            ++i;
        }
        if (j - i + 1 === n - 1 && stones[j] - stones[i] === n - 2) {
            mi = Math.min(mi, 2);
        } else {
            mi = Math.min(mi, n - (j - i + 1));
        }
    }
    return [mi, mx];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>在 X 轴上有一些不同位置的石子。给定一个整数数组&nbsp;<code>stones</code>&nbsp;表示石子的位置。</p>

<p>如果一个石子在最小或最大的位置，称其为&nbsp;<strong>端点石子</strong>。每个回合，你可以将一颗 <strong>端点石子</strong> 拿起并移动到一个未占用的位置，使得该石子不再是一颗 <strong>端点石子</strong>。</p>

<ul>
	<li>值得注意的是，如果石子像&nbsp;<code>stones = [1,2,5]</code>&nbsp;这样，你将 <strong>无法 </strong>移动位于位置 <code>5</code> 的端点石子，因为无论将它移动到任何位置（例如 <code>0</code> 或 <code>3</code>），该石子都仍然会是端点石子。</li>
</ul>

<p>当你无法进行任何移动时，即，这些石子的位置连续时，游戏结束。</p>

<p>以长度为 2 的数组形式返回答案，其中：</p>

<ul>
	<li><code>answer[0]</code>&nbsp;是你可以移动的最小次数</li>
	<li><code>answer[1]</code>&nbsp;是你可以移动的最大次数。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>[7,4,9]
<strong>输出：</strong>[1,2]
<strong>解释：</strong>
我们可以移动一次，4 -&gt; 8，游戏结束。
或者，我们可以移动两次 9 -&gt; 5，4 -&gt; 6，游戏结束。
</pre>

<p><strong>示例&nbsp;2：</strong></p>

<pre>
<strong>输入：</strong>[6,5,4,3,10]
<strong>输出：</strong>[2,3]
<strong>解释：</strong>
我们可以移动 3 -&gt; 8，接着是 10 -&gt; 7，游戏结束。
或者，我们可以移动 3 -&gt; 7, 4 -&gt; 8, 5 -&gt; 9，游戏结束。
注意，我们无法进行 10 -&gt; 2 这样的移动来结束游戏，因为这是不合要求的移动。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= stones.length &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= stones[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>stones</code>&nbsp;的值各不相同。</li>
</ul>

<p>&nbsp;</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 分类讨论 + 双指针

我们先对数组 `stones` 进行升序排序，接下来分别考虑最大移动次数 $mx$ 和最小移动次数 $mi$。

对于最大移动次数 $mx$：

由于我们每一次只能选择将端点石子移动到未占用且不是端点石子的位置，如果我们选择 `stones[0]` 作为第一次移动的端点石子，那么从 `stones[0]` 到 `stones[1]` 之间的所有未占用的位置都会被跳过，我们可以选择移动到最近的且未占用的位置，接下来每一次都将最左端的石子移动到最近的且未占用的位置，那么最多可以移动的次数为 $stones[n - 1] - stones[1] + 1 - (n - 1)$；同理，如果我们选择 `stones[n - 1]` 作为第一次移动的端点石子，那么最多可以移动的次数为 $stones[n - 2] - stones[0] + 1 - (n - 1)$。取两者的最大值即为最大移动次数 $mx$。

对于最小移动次数 $mi$：

我们用双指针 $i$ 和 $j$ 标识一个窗口的左右端点，若窗口内的位置数 $stones[j] - stones[i] + 1 \gt n$ 时，我们需要缩小窗口，即指针 $i$ 向右移动。如果此时窗口中有连续的 $n-1$ 个石子，即满足 $j - i + 1 = n - 1$ 且 $stones[j] - stones[i] + 1 = n - 1$，那么最少需要移动的次数为 $2$；否则，我们用 $n$ 减去窗口内的石子数，可以得到最少需要移动的次数，即 $n - (j - i + 1)$。取所有情况的最小值即为最小移动次数 $mi$。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 为数组 `stones` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numMovesStonesII(self, stones: List[int]) -> List[int]:
        stones.sort()
        mi = n = len(stones)
        mx = max(stones[-1] - stones[1] + 1, stones[-2] - stones[0] + 1) - (n - 1)
        i = 0
        for j, x in enumerate(stones):
            while x - stones[i] + 1 > n:
                i += 1
            if j - i + 1 == n - 1 and x - stones[i] == n - 2:
                mi = min(mi, 2)
            else:
                mi = min(mi, n - (j - i + 1))
        return [mi, mx]
```

#### Java

```java
class Solution {
    public int[] numMovesStonesII(int[] stones) {
        Arrays.sort(stones);
        int n = stones.length;
        int mi = n;
        int mx = Math.max(stones[n - 1] - stones[1] + 1, stones[n - 2] - stones[0] + 1) - (n - 1);
        for (int i = 0, j = 0; j < n; ++j) {
            while (stones[j] - stones[i] + 1 > n) {
                ++i;
            }
            if (j - i + 1 == n - 1 && stones[j] - stones[i] == n - 2) {
                mi = Math.min(mi, 2);
            } else {
                mi = Math.min(mi, n - (j - i + 1));
            }
        }
        return new int[] {mi, mx};
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        sort(stones.begin(), stones.end());
        int n = stones.size();
        int mi = n;
        int mx = max(stones[n - 1] - stones[1] + 1, stones[n - 2] - stones[0] + 1) - (n - 1);
        for (int i = 0, j = 0; j < n; ++j) {
            while (stones[j] - stones[i] + 1 > n) {
                ++i;
            }
            if (j - i + 1 == n - 1 && stones[j] - stones[i] == n - 2) {
                mi = min(mi, 2);
            } else {
                mi = min(mi, n - (j - i + 1));
            }
        }
        return {mi, mx};
    }
};
```

#### Go

```go
func numMovesStonesII(stones []int) []int {
	sort.Ints(stones)
	n := len(stones)
	mi := n
	mx := max(stones[n-1]-stones[1]+1, stones[n-2]-stones[0]+1) - (n - 1)
	i := 0
	for j, x := range stones {
		for x-stones[i]+1 > n {
			i++
		}
		if j-i+1 == n-1 && stones[j]-stones[i] == n-2 {
			mi = min(mi, 2)
		} else {
			mi = min(mi, n-(j-i+1))
		}
	}
	return []int{mi, mx}
}
```

#### TypeScript

```ts
function numMovesStonesII(stones: number[]): number[] {
    stones.sort((a, b) => a - b);
    const n = stones.length;
    let mi = n;
    const mx = Math.max(stones[n - 1] - stones[1] + 1, stones[n - 2] - stones[0] + 1) - (n - 1);
    for (let i = 0, j = 0; j < n; ++j) {
        while (stones[j] - stones[i] + 1 > n) {
            ++i;
        }
        if (j - i + 1 === n - 1 && stones[j] - stones[i] === n - 2) {
            mi = Math.min(mi, 2);
        } else {
            mi = Math.min(mi, n - (j - i + 1));
        }
    }
    return [mi, mx];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1041. 困于环中的机器人](https://leetcode.cn/problems/robot-bounded-in-circle){#1041}

{{< tabs "1041" >}}

{{% tab "python" %}}
```python
class Solution:
    def isRobotBounded(self, instructions: str) -> bool:
        k = 0
        dist = [0] * 4
        for c in instructions:
            if c == 'L':
                k = (k + 1) % 4
            elif c == 'R':
                k = (k + 3) % 4
            else:
                dist[k] += 1
        return (dist[0] == dist[2] and dist[1] == dist[3]) or k != 0
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean isRobotBounded(String instructions) {
        int k = 0;
        int[] dist = new int[4];
        for (int i = 0; i < instructions.length(); ++i) {
            char c = instructions.charAt(i);
            if (c == 'L') {
                k = (k + 1) % 4;
            } else if (c == 'R') {
                k = (k + 3) % 4;
            } else {
                ++dist[k];
            }
        }
        return (dist[0] == dist[2] && dist[1] == dist[3]) || (k != 0);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool isRobotBounded(string instructions) {
        int dist[4]{};
        int k = 0;
        for (char& c : instructions) {
            if (c == 'L') {
                k = (k + 1) % 4;
            } else if (c == 'R') {
                k = (k + 3) % 4;
            } else {
                ++dist[k];
            }
        }
        return (dist[0] == dist[2] && dist[1] == dist[3]) || k;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func isRobotBounded(instructions string) bool {
	dist := [4]int{}
	k := 0
	for _, c := range instructions {
		if c == 'L' {
			k = (k + 1) % 4
		} else if c == 'R' {
			k = (k + 3) % 4
		} else {
			dist[k]++
		}
	}
	return (dist[0] == dist[2] && dist[1] == dist[3]) || k != 0
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function isRobotBounded(instructions: string): boolean {
    const dist: number[] = new Array(4).fill(0);
    let k = 0;
    for (const c of instructions) {
        if (c === 'L') {
            k = (k + 1) % 4;
        } else if (c === 'R') {
            k = (k + 3) % 4;
        } else {
            ++dist[k];
        }
    }
    return (dist[0] === dist[2] && dist[1] === dist[3]) || k !== 0;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>在无限的平面上，机器人最初位于&nbsp;<code>(0, 0)</code>&nbsp;处，面朝北方。注意:</p>

<ul>
	<li><strong>北方向</strong> 是y轴的正方向。</li>
	<li><strong>南方向</strong> 是y轴的负方向。</li>
	<li><strong>东方向</strong> 是x轴的正方向。</li>
	<li><strong>西方向</strong> 是x轴的负方向。</li>
</ul>

<p>机器人可以接受下列三条指令之一：</p>

<ul>
	<li><code>"G"</code>：直走 1 个单位</li>
	<li><code>"L"</code>：左转 90 度</li>
	<li><code>"R"</code>：右转 90 度</li>
</ul>

<p>机器人按顺序执行指令&nbsp;<code>instructions</code>，并一直重复它们。</p>

<p>只有在平面中存在环使得机器人永远无法离开时，返回&nbsp;<code>true</code>。否则，返回 <code>false</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>instructions = "GGLLGG"
<strong>输出：</strong>true
<strong>解释：</strong>机器人最初在(0,0)处，面向北方。
“G”:移动一步。位置:(0,1)方向:北。
“G”:移动一步。位置:(0,2).方向:北。
“L”:逆时针旋转90度。位置:(0,2).方向:西。
“L”:逆时针旋转90度。位置:(0,2)方向:南。
“G”:移动一步。位置:(0,1)方向:南。
“G”:移动一步。位置:(0,0)方向:南。
重复指令，机器人进入循环:(0,0)——&gt;(0,1)——&gt;(0,2)——&gt;(0,1)——&gt;(0,0)。
在此基础上，我们返回true。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>instructions = "GG"
<strong>输出：</strong>false
<strong>解释：</strong>机器人最初在(0,0)处，面向北方。
“G”:移动一步。位置:(0,1)方向:北。
“G”:移动一步。位置:(0,2).方向:北。
重复这些指示，继续朝北前进，不会进入循环。
在此基础上，返回false。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>instructions = "GL"
<strong>输出：</strong>true
<strong>解释：</strong>机器人最初在(0,0)处，面向北方。
“G”:移动一步。位置:(0,1)方向:北。
“L”:逆时针旋转90度。位置:(0,1).方向:西。
“G”:移动一步。位置:(- 1,1)方向:西。
“L”:逆时针旋转90度。位置:(- 1,1)方向:南。
“G”:移动一步。位置:(- 1,0)方向:南。
“L”:逆时针旋转90度。位置:(- 1,0)方向:东方。
“G”:移动一步。位置:(0,0)方向:东方。
“L”:逆时针旋转90度。位置:(0,0)方向:北。
重复指令，机器人进入循环:(0,0)——&gt;(0,1)——&gt;(- 1,1)——&gt;(- 1,0)——&gt;(0,0)。
在此基础上，我们返回true。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= instructions.length &lt;= 100</code></li>
	<li><code>instructions[i]</code>&nbsp;仅包含&nbsp;<code>'G', 'L', 'R'</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们可以模拟机器人的行走过程，用一个变量 $k$ 表示机器人的方向，初始值为 $0$，表示机器人面向北方。变量 $k$ 的取值范围为 $[0, 3]$，分别表示机器人面向北、西、南、东。另外，我们用一个长度为 $4$ 的数组 $dist$ 记录机器人在四个方向上行走的距离，初始值为 $[0, 0, 0, 0]$。

遍历指令字符串 $\textit{instructions}$，如果当前指令为 `'L'`，那么机器人转向西方，即 $k = (k + 1) \bmod 4$；如果当前指令为 `'R'`，那么机器人转向东方，即 $k = (k + 3) \bmod 4$；否则，机器人在当前方向上行走一步，即 $dist[k]++$。

如果给定的指令字符串 $\textit{instructions}$ 执行一遍后，使得机器人最终回到原点，即 $dist[0] = dist[2]$ 且 $dist[1] = dist[3]$，那么机器人一定会进入循环。因为无论重复多少次指令，机器人都回到了原点，所以机器人一定会进入循环。

如果给定的指令字符串 $\textit{instructions}$ 执行一遍后，机器人没回到原点，不妨假设此时机器人位于 $(x, y)$，且方向为 $k$。

-   若 $k=0$，即机器人面向北方，那么执行第二遍指令后，坐标变化量是 $(x, y)$；继续执行第三遍指令后，坐标变化量还是 $(x, y)$...累加这些变化量，机器人最终会到 $(n \times x, n \times y)$，其中 $n$ 是一个正整数。由于机器人最终没有回到原点，即 $x \neq 0$ 或 $y \neq 0$，所以 $n \times x \neq 0$ 或 $n \times y \neq 0$，因此机器人不会进入循环；
-   若 $k=1$，即机器人面向西方，那么机器人执行第二遍指令后，坐标变化量是 $(-y, x)$；继续执行第三遍执行后，坐标变化量是 $(-x, -y)$；继续执行第四遍指令后，坐标变化量是 $(y, -x)$。累加这些坐标变化量，我们可以发现，机器人最终会回到原点 $(0, 0)$；
-   若 $k=2$，即机器人面向南方，那么执行第二遍指令后，坐标变化量是 $(-x, -y)$，累加这两次坐标变化量，我们可以发现，机器人最终会回到原点 $(0, 0)$；
-   若 $k=3$，即机器人面向东方，那么执行第二遍指令后，坐标变化量是 $(y, -x)$；继续执行第三遍指令后，坐标变化量是 $(-x, -y)$；继续执行第四遍指令后，坐标变化量是 $(-y, x)$。累加这些坐标变化量，我们可以发现，机器人最终会回到原点 $(0, 0)$。

综上所述，如果给定的指令字符串 $\textit{instructions}$ 执行一遍后，机器人回到了原点，或者机器人的方向与初始方向不同，那么机器人一定会进入循环。

时间复杂度 $O(n)$，空间复杂度 $O(1)$。其中 $n$ 为指令字符串 $\textit{instructions}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def isRobotBounded(self, instructions: str) -> bool:
        k = 0
        dist = [0] * 4
        for c in instructions:
            if c == 'L':
                k = (k + 1) % 4
            elif c == 'R':
                k = (k + 3) % 4
            else:
                dist[k] += 1
        return (dist[0] == dist[2] and dist[1] == dist[3]) or k != 0
```

#### Java

```java
class Solution {
    public boolean isRobotBounded(String instructions) {
        int k = 0;
        int[] dist = new int[4];
        for (int i = 0; i < instructions.length(); ++i) {
            char c = instructions.charAt(i);
            if (c == 'L') {
                k = (k + 1) % 4;
            } else if (c == 'R') {
                k = (k + 3) % 4;
            } else {
                ++dist[k];
            }
        }
        return (dist[0] == dist[2] && dist[1] == dist[3]) || (k != 0);
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool isRobotBounded(string instructions) {
        int dist[4]{};
        int k = 0;
        for (char& c : instructions) {
            if (c == 'L') {
                k = (k + 1) % 4;
            } else if (c == 'R') {
                k = (k + 3) % 4;
            } else {
                ++dist[k];
            }
        }
        return (dist[0] == dist[2] && dist[1] == dist[3]) || k;
    }
};
```

#### Go

```go
func isRobotBounded(instructions string) bool {
	dist := [4]int{}
	k := 0
	for _, c := range instructions {
		if c == 'L' {
			k = (k + 1) % 4
		} else if c == 'R' {
			k = (k + 3) % 4
		} else {
			dist[k]++
		}
	}
	return (dist[0] == dist[2] && dist[1] == dist[3]) || k != 0
}
```

#### TypeScript

```ts
function isRobotBounded(instructions: string): boolean {
    const dist: number[] = new Array(4).fill(0);
    let k = 0;
    for (const c of instructions) {
        if (c === 'L') {
            k = (k + 1) % 4;
        } else if (c === 'R') {
            k = (k + 3) % 4;
        } else {
            ++dist[k];
        }
    }
    return (dist[0] === dist[2] && dist[1] === dist[3]) || k !== 0;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1042. 不邻接植花](https://leetcode.cn/problems/flower-planting-with-no-adjacent){#1042}

{{< tabs "1042" >}}

{{% tab "python" %}}
```python
class Solution:
    def gardenNoAdj(self, n: int, paths: List[List[int]]) -> List[int]:
        g = defaultdict(list)
        for x, y in paths:
            x, y = x - 1, y - 1
            g[x].append(y)
            g[y].append(x)
        ans = [0] * n
        for x in range(n):
            used = {ans[y] for y in g[x]}
            for c in range(1, 5):
                if c not in used:
                    ans[x] = c
                    break
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] gardenNoAdj(int n, int[][] paths) {
        List<Integer>[] g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (var p : paths) {
            int x = p[0] - 1, y = p[1] - 1;
            g[x].add(y);
            g[y].add(x);
        }
        int[] ans = new int[n];
        boolean[] used = new boolean[5];
        for (int x = 0; x < n; ++x) {
            Arrays.fill(used, false);
            for (int y : g[x]) {
                used[ans[y]] = true;
            }
            for (int c = 1; c < 5; ++c) {
                if (!used[c]) {
                    ans[x] = c;
                    break;
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
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> g(n);
        for (auto& p : paths) {
            int x = p[0] - 1, y = p[1] - 1;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        vector<int> ans(n);
        bool used[5];
        for (int x = 0; x < n; ++x) {
            memset(used, false, sizeof(used));
            for (int y : g[x]) {
                used[ans[y]] = true;
            }
            for (int c = 1; c < 5; ++c) {
                if (!used[c]) {
                    ans[x] = c;
                    break;
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
func gardenNoAdj(n int, paths [][]int) []int {
	g := make([][]int, n)
	for _, p := range paths {
		x, y := p[0]-1, p[1]-1
		g[x] = append(g[x], y)
		g[y] = append(g[y], x)
	}
	ans := make([]int, n)
	for x := 0; x < n; x++ {
		used := [5]bool{}
		for _, y := range g[x] {
			used[ans[y]] = true
		}
		for c := 1; c < 5; c++ {
			if !used[c] {
				ans[x] = c
				break
			}
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function gardenNoAdj(n: number, paths: number[][]): number[] {
    const g: number[][] = Array.from({ length: n }, () => []);
    for (const [x, y] of paths) {
        g[x - 1].push(y - 1);
        g[y - 1].push(x - 1);
    }
    const ans: number[] = Array(n).fill(0);
    for (let x = 0; x < n; ++x) {
        const used: boolean[] = Array(5).fill(false);
        for (const y of g[x]) {
            used[ans[y]] = true;
        }
        for (let c = 1; c < 5; ++c) {
            if (!used[c]) {
                ans[x] = c;
                break;
            }
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn garden_no_adj(n: i32, paths: Vec<Vec<i32>>) -> Vec<i32> {
        let n = n as usize;
        let mut g = vec![vec![]; n];

        for path in paths {
            let (x, y) = (path[0] as usize - 1, path[1] as usize - 1);
            g[x].push(y);
            g[y].push(x);
        }

        let mut ans = vec![0; n];
        for x in 0..n {
            let mut used = [false; 5];
            for &y in &g[x] {
                used[ans[y] as usize] = true;
            }
            for c in 1..5 {
                if !used[c] {
                    ans[x] = c as i32;
                    break;
                }
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

<p>有 <code>n</code> 个花园，按从&nbsp;<code>1</code>&nbsp;到 <code>n</code> 标记。另有数组 <code>paths</code> ，其中 <code>paths[i] = [x<sub>i</sub>, y<sub>i</sub>]</code>&nbsp;描述了花园&nbsp;<code>x<sub>i</sub></code> 到花园&nbsp;<code>y<sub>i</sub></code> 的双向路径。在每个花园中，你打算种下四种花之一。</p>

<p>另外，所有花园 <strong>最多</strong> 有 <strong>3</strong> 条路径可以进入或离开.</p>

<p>你需要为每个花园选择一种花，使得通过路径相连的任何两个花园中的花的种类互不相同。</p>

<p><em>以数组形式返回 <strong>任一</strong> 可行的方案作为答案&nbsp;<code>answer</code>，其中&nbsp;<code>answer[i]</code>&nbsp;为在第&nbsp;<code>(i+1)</code>&nbsp;个花园中种植的花的种类。花的种类用 &nbsp;1、2、3、4 表示。保证存在答案。</em></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 3, paths = [[1,2],[2,3],[3,1]]
<strong>输出：</strong>[1,2,3]
<strong>解释：</strong>
花园 1 和 2 花的种类不同。
花园 2 和 3 花的种类不同。
花园 3 和 1 花的种类不同。
因此，[1,2,3] 是一个满足题意的答案。其他满足题意的答案有 [1,2,4]、[1,4,2] 和 [3,2,1]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 4, paths = [[1,2],[3,4]]
<strong>输出：</strong>[1,2,1,2]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 4, paths = [[1,2],[2,3],[3,4],[4,1],[1,3],[2,4]]
<strong>输出：</strong>[1,2,3,4]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= paths.length &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>paths[i].length == 2</code></li>
	<li><code>1 &lt;= x<sub>i</sub>, y<sub>i</sub> &lt;= n</code></li>
	<li><code>x<sub>i</sub> != y<sub>i</sub></code></li>
	<li>每个花园 <strong>最多</strong> 有 <strong>3</strong> 条路径可以进入或离开</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举

我们先根据数组 $\textit{paths}$ 构建图 $g$，其中 $g[x]$ 表示与花园 $x$ 相邻的花园列表。

接下来，对于每个花园 $x$，我们先找出与 $x$ 相邻的花园 $y$，并将 $y$ 花园中种植的花的种类标记为已使用。然后我们从花的种类 $1$ 开始枚举，直到找到一个未被使用的花的种类 $c$，将 $c$ 标记为 $x$ 花园中种植的花的种类，然后继续枚举下一个花园。

枚举结束后，返回答案即可。

时间复杂度 $O(n + m)$，空间复杂度 $O(n + m)$。其中 $n$ 和 $m$ 分别是花园的数量和路径的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def gardenNoAdj(self, n: int, paths: List[List[int]]) -> List[int]:
        g = defaultdict(list)
        for x, y in paths:
            x, y = x - 1, y - 1
            g[x].append(y)
            g[y].append(x)
        ans = [0] * n
        for x in range(n):
            used = {ans[y] for y in g[x]}
            for c in range(1, 5):
                if c not in used:
                    ans[x] = c
                    break
        return ans
```

#### Java

```java
class Solution {
    public int[] gardenNoAdj(int n, int[][] paths) {
        List<Integer>[] g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (var p : paths) {
            int x = p[0] - 1, y = p[1] - 1;
            g[x].add(y);
            g[y].add(x);
        }
        int[] ans = new int[n];
        boolean[] used = new boolean[5];
        for (int x = 0; x < n; ++x) {
            Arrays.fill(used, false);
            for (int y : g[x]) {
                used[ans[y]] = true;
            }
            for (int c = 1; c < 5; ++c) {
                if (!used[c]) {
                    ans[x] = c;
                    break;
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
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> g(n);
        for (auto& p : paths) {
            int x = p[0] - 1, y = p[1] - 1;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        vector<int> ans(n);
        bool used[5];
        for (int x = 0; x < n; ++x) {
            memset(used, false, sizeof(used));
            for (int y : g[x]) {
                used[ans[y]] = true;
            }
            for (int c = 1; c < 5; ++c) {
                if (!used[c]) {
                    ans[x] = c;
                    break;
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func gardenNoAdj(n int, paths [][]int) []int {
	g := make([][]int, n)
	for _, p := range paths {
		x, y := p[0]-1, p[1]-1
		g[x] = append(g[x], y)
		g[y] = append(g[y], x)
	}
	ans := make([]int, n)
	for x := 0; x < n; x++ {
		used := [5]bool{}
		for _, y := range g[x] {
			used[ans[y]] = true
		}
		for c := 1; c < 5; c++ {
			if !used[c] {
				ans[x] = c
				break
			}
		}
	}
	return ans
}
```

#### TypeScript

```ts
function gardenNoAdj(n: number, paths: number[][]): number[] {
    const g: number[][] = Array.from({ length: n }, () => []);
    for (const [x, y] of paths) {
        g[x - 1].push(y - 1);
        g[y - 1].push(x - 1);
    }
    const ans: number[] = Array(n).fill(0);
    for (let x = 0; x < n; ++x) {
        const used: boolean[] = Array(5).fill(false);
        for (const y of g[x]) {
            used[ans[y]] = true;
        }
        for (let c = 1; c < 5; ++c) {
            if (!used[c]) {
                ans[x] = c;
                break;
            }
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn garden_no_adj(n: i32, paths: Vec<Vec<i32>>) -> Vec<i32> {
        let n = n as usize;
        let mut g = vec![vec![]; n];

        for path in paths {
            let (x, y) = (path[0] as usize - 1, path[1] as usize - 1);
            g[x].push(y);
            g[y].push(x);
        }

        let mut ans = vec![0; n];
        for x in 0..n {
            let mut used = [false; 5];
            for &y in &g[x] {
                used[ans[y] as usize] = true;
            }
            for c in 1..5 {
                if !used[c] {
                    ans[x] = c as i32;
                    break;
                }
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

# [1043. 分隔数组以得到最大和](https://leetcode.cn/problems/partition-array-for-maximum-sum){#1043}

{{< tabs "1043" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxSumAfterPartitioning(self, arr: List[int], k: int) -> int:
        n = len(arr)
        f = [0] * (n + 1)
        for i in range(1, n + 1):
            mx = 0
            for j in range(i, max(0, i - k), -1):
                mx = max(mx, arr[j - 1])
                f[i] = max(f[i], f[j - 1] + mx * (i - j + 1))
        return f[n]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxSumAfterPartitioning(int[] arr, int k) {
        int n = arr.length;
        int[] f = new int[n + 1];
        for (int i = 1; i <= n; ++i) {
            int mx = 0;
            for (int j = i; j > Math.max(0, i - k); --j) {
                mx = Math.max(mx, arr[j - 1]);
                f[i] = Math.max(f[i], f[j - 1] + mx * (i - j + 1));
            }
        }
        return f[n];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        int f[n + 1];
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= n; ++i) {
            int mx = 0;
            for (int j = i; j > max(0, i - k); --j) {
                mx = max(mx, arr[j - 1]);
                f[i] = max(f[i], f[j - 1] + mx * (i - j + 1));
            }
        }
        return f[n];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxSumAfterPartitioning(arr []int, k int) int {
	n := len(arr)
	f := make([]int, n+1)
	for i := 1; i <= n; i++ {
		mx := 0
		for j := i; j > max(0, i-k); j-- {
			mx = max(mx, arr[j-1])
			f[i] = max(f[i], f[j-1]+mx*(i-j+1))
		}
	}
	return f[n]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxSumAfterPartitioning(arr: number[], k: number): number {
    const n: number = arr.length;
    const f: number[] = new Array(n + 1).fill(0);
    for (let i = 1; i <= n; ++i) {
        let mx: number = 0;
        for (let j = i; j > Math.max(0, i - k); --j) {
            mx = Math.max(mx, arr[j - 1]);
            f[i] = Math.max(f[i], f[j - 1] + mx * (i - j + 1));
        }
    }
    return f[n];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>arr</code>，请你将该数组分隔为长度 <strong>最多 </strong>为 k 的一些（连续）子数组。分隔完成后，每个子数组的中的所有值都会变为该子数组中的最大值。</p>

<p>返回将数组分隔变换后能够得到的元素最大和。本题所用到的测试用例会确保答案是一个 32 位整数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>arr = [1,15,7,9,2,5,10], k = 3
<strong>输出：</strong>84
<strong>解释：</strong>数组变为 [15,15,15,9,10,10,10]</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4
<strong>输出：</strong>83
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>arr = [1], k = 1
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 500</code></li>
	<li><code>0 &lt;= arr[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= k &lt;= arr.length</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i]$ 表示将数组的前 $i$ 个元素分隔成若干个子数组，最终的最大元素和。初始时 $f[i]=0$，答案为 $f[n]$。

我们考虑如何计算 $f[i]$，其中 $i \geq 1$。

对于 $f[i]$，它的最后一个元素是 $arr[i-1]$。由于每个子数组的长度最多为 $k$，并且我们需要求得子数组中的最大值，因此，我们可以从右往左枚举最后一个子数组的第一个元素 $arr[j - 1]$，其中 $\max(0, i - k) \lt j \leq i$，过程中维护一个变量 $mx$，表示最后一个子数组中的最大值，那么状态转移方程为：

$$
f[i] = \max\{f[i], f[j - 1] + mx \times (i - j + 1)\}
$$

最终的答案即为 $f[n]$。

时间复杂度 $O(n \times k)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $arr$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxSumAfterPartitioning(self, arr: List[int], k: int) -> int:
        n = len(arr)
        f = [0] * (n + 1)
        for i in range(1, n + 1):
            mx = 0
            for j in range(i, max(0, i - k), -1):
                mx = max(mx, arr[j - 1])
                f[i] = max(f[i], f[j - 1] + mx * (i - j + 1))
        return f[n]
```

#### Java

```java
class Solution {
    public int maxSumAfterPartitioning(int[] arr, int k) {
        int n = arr.length;
        int[] f = new int[n + 1];
        for (int i = 1; i <= n; ++i) {
            int mx = 0;
            for (int j = i; j > Math.max(0, i - k); --j) {
                mx = Math.max(mx, arr[j - 1]);
                f[i] = Math.max(f[i], f[j - 1] + mx * (i - j + 1));
            }
        }
        return f[n];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        int f[n + 1];
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= n; ++i) {
            int mx = 0;
            for (int j = i; j > max(0, i - k); --j) {
                mx = max(mx, arr[j - 1]);
                f[i] = max(f[i], f[j - 1] + mx * (i - j + 1));
            }
        }
        return f[n];
    }
};
```

#### Go

```go
func maxSumAfterPartitioning(arr []int, k int) int {
	n := len(arr)
	f := make([]int, n+1)
	for i := 1; i <= n; i++ {
		mx := 0
		for j := i; j > max(0, i-k); j-- {
			mx = max(mx, arr[j-1])
			f[i] = max(f[i], f[j-1]+mx*(i-j+1))
		}
	}
	return f[n]
}
```

#### TypeScript

```ts
function maxSumAfterPartitioning(arr: number[], k: number): number {
    const n: number = arr.length;
    const f: number[] = new Array(n + 1).fill(0);
    for (let i = 1; i <= n; ++i) {
        let mx: number = 0;
        for (let j = i; j > Math.max(0, i - k); --j) {
            mx = Math.max(mx, arr[j - 1]);
            f[i] = Math.max(f[i], f[j - 1] + mx * (i - j + 1));
        }
    }
    return f[n];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1044. 最长重复子串](https://leetcode.cn/problems/longest-duplicate-substring){#1044}

{{< tabs "1044" >}}

{{% tab "python" %}}
```python
class Solution:
    def longestDupSubstring(self, s: str) -> str:
        def check(l):
            vis = set()
            for i in range(n - l + 1):
                t = s[i : i + l]
                if t in vis:
                    return t
                vis.add(t)
            return ''

        n = len(s)
        left, right = 0, n
        ans = ''
        while left < right:
            mid = (left + right + 1) >> 1
            t = check(mid)
            ans = t or ans
            if t:
                left = mid
            else:
                right = mid - 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private long[] p;
    private long[] h;

    public String longestDupSubstring(String s) {
        int base = 131;
        int n = s.length();
        p = new long[n + 10];
        h = new long[n + 10];
        p[0] = 1;
        for (int i = 0; i < n; ++i) {
            p[i + 1] = p[i] * base;
            h[i + 1] = h[i] * base + s.charAt(i);
        }
        String ans = "";
        int left = 0, right = n;
        while (left < right) {
            int mid = (left + right + 1) >> 1;
            String t = check(s, mid);
            if (t.length() > 0) {
                left = mid;
                ans = t;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }

    private String check(String s, int len) {
        int n = s.length();
        Set<Long> vis = new HashSet<>();
        for (int i = 1; i + len - 1 <= n; ++i) {
            int j = i + len - 1;
            long t = h[j] - h[i - 1] * p[j - i + 1];
            if (vis.contains(t)) {
                return s.substring(i - 1, j);
            }
            vis.add(t);
        }
        return "";
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
typedef unsigned long long ULL;

class Solution {
public:
    ULL p[30010];
    ULL h[30010];
    string longestDupSubstring(string s) {
        int base = 131, n = s.size();
        p[0] = 1;
        for (int i = 0; i < n; ++i) {
            p[i + 1] = p[i] * base;
            h[i + 1] = h[i] * base + s[i];
        }
        int left = 0, right = n;
        string ans = "";
        while (left < right) {
            int mid = (left + right + 1) >> 1;
            string t = check(s, mid);
            if (t.empty())
                right = mid - 1;
            else {
                left = mid;
                ans = t;
            }
        }
        return ans;
    }

    string check(string& s, int len) {
        int n = s.size();
        unordered_set<ULL> vis;
        for (int i = 1; i + len - 1 <= n; ++i) {
            int j = i + len - 1;
            ULL t = h[j] - h[i - 1] * p[j - i + 1];
            if (vis.count(t)) return s.substr(i - 1, len);
            vis.insert(t);
        }
        return "";
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func longestDupSubstring(s string) string {
	base, n := 131, len(s)
	p := make([]int64, n+10)
	h := make([]int64, n+10)
	p[0] = 1
	for i := 0; i < n; i++ {
		p[i+1] = p[i] * int64(base)
		h[i+1] = h[i]*int64(base) + int64(s[i])
	}
	check := func(l int) string {
		vis := make(map[int64]bool)
		for i := 1; i+l-1 <= n; i++ {
			j := i + l - 1
			t := h[j] - h[i-1]*p[j-i+1]
			if vis[t] {
				return s[i-1 : j]
			}
			vis[t] = true
		}
		return ""
	}
	left, right := 0, n
	ans := ""
	for left < right {
		mid := (left + right + 1) >> 1
		t := check(mid)
		if len(t) > 0 {
			left = mid
			ans = t
		} else {
			right = mid - 1
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

<p>给你一个字符串 <code>s</code> ，考虑其所有 <em>重复子串</em> ：即&nbsp;<code>s</code> 的（连续）子串，在 <code>s</code> 中出现 2 次或更多次。这些出现之间可能存在重叠。</p>

<p>返回 <strong>任意一个</strong> 可能具有最长长度的重复子串。如果 <code>s</code> 不含重复子串，那么答案为 <code>""</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "banana"
<strong>输出：</strong>"ana"
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "abcd"
<strong>输出：</strong>""
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= s.length &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>s</code> 由小写英文字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：字符串哈希 + 二分查找

**字符串哈希**是把一个任意长度的字符串映射成一个非负整数，并且其冲突的概率几乎为 0。字符串哈希用于计算字符串哈希值，快速判断两个字符串是否相等。

取一固定值 BASE，把字符串看作是 BASE 进制数，并分配一个大于 0 的数值，代表每种字符。一般来说，我们分配的数值都远小于 BASE。例如，对于小写字母构成的字符串，可以令 a=1, b=2, ..., z=26。取一固定值 MOD，求出该 BASE 进制对 M 的余数，作为该字符串的 hash 值。

一般来说，取 BASE=131 或者 BASE=13331，此时 hash 值产生的冲突概率极低。只要两个字符串 hash 值相同，我们就认为两个字符串是相等的。通常 MOD 取 2^64，C++ 里，可以直接使用 unsigned long long 类型存储这个 hash 值，在计算时不处理算术溢出问题，产生溢出时相当于自动对 2^64 取模，这样可以避免低效取模运算。

除了在极特殊构造的数据上，上述 hash 算法很难产生冲突，一般情况下上述 hash 算法完全可以出现在题目的标准答案中。我们还可以多取一些恰当的 BASE 和 MOD 的值（例如大质数），多进行几组 hash 运算，当结果都相同时才认为原字符串相等，就更加难以构造出使这个 hash 产生错误的数据。

对于本题，二分枚举长度，找到满足条件的最大长度即可。

时间复杂度 $O(n\log n)$。其中 $n$ 为字符串长度。

相似题目：

-   [1062. 最长重复子串](https://github.com/doocs/leetcode/blob/main/solution/1000-1099/1062.Longest%20Repeating%20Substring/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def longestDupSubstring(self, s: str) -> str:
        def check(l):
            vis = set()
            for i in range(n - l + 1):
                t = s[i : i + l]
                if t in vis:
                    return t
                vis.add(t)
            return ''

        n = len(s)
        left, right = 0, n
        ans = ''
        while left < right:
            mid = (left + right + 1) >> 1
            t = check(mid)
            ans = t or ans
            if t:
                left = mid
            else:
                right = mid - 1
        return ans
```

#### Java

```java
class Solution {
    private long[] p;
    private long[] h;

    public String longestDupSubstring(String s) {
        int base = 131;
        int n = s.length();
        p = new long[n + 10];
        h = new long[n + 10];
        p[0] = 1;
        for (int i = 0; i < n; ++i) {
            p[i + 1] = p[i] * base;
            h[i + 1] = h[i] * base + s.charAt(i);
        }
        String ans = "";
        int left = 0, right = n;
        while (left < right) {
            int mid = (left + right + 1) >> 1;
            String t = check(s, mid);
            if (t.length() > 0) {
                left = mid;
                ans = t;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }

    private String check(String s, int len) {
        int n = s.length();
        Set<Long> vis = new HashSet<>();
        for (int i = 1; i + len - 1 <= n; ++i) {
            int j = i + len - 1;
            long t = h[j] - h[i - 1] * p[j - i + 1];
            if (vis.contains(t)) {
                return s.substring(i - 1, j);
            }
            vis.add(t);
        }
        return "";
    }
}
```

#### C++

```cpp
typedef unsigned long long ULL;

class Solution {
public:
    ULL p[30010];
    ULL h[30010];
    string longestDupSubstring(string s) {
        int base = 131, n = s.size();
        p[0] = 1;
        for (int i = 0; i < n; ++i) {
            p[i + 1] = p[i] * base;
            h[i + 1] = h[i] * base + s[i];
        }
        int left = 0, right = n;
        string ans = "";
        while (left < right) {
            int mid = (left + right + 1) >> 1;
            string t = check(s, mid);
            if (t.empty())
                right = mid - 1;
            else {
                left = mid;
                ans = t;
            }
        }
        return ans;
    }

    string check(string& s, int len) {
        int n = s.size();
        unordered_set<ULL> vis;
        for (int i = 1; i + len - 1 <= n; ++i) {
            int j = i + len - 1;
            ULL t = h[j] - h[i - 1] * p[j - i + 1];
            if (vis.count(t)) return s.substr(i - 1, len);
            vis.insert(t);
        }
        return "";
    }
};
```

#### Go

```go
func longestDupSubstring(s string) string {
	base, n := 131, len(s)
	p := make([]int64, n+10)
	h := make([]int64, n+10)
	p[0] = 1
	for i := 0; i < n; i++ {
		p[i+1] = p[i] * int64(base)
		h[i+1] = h[i]*int64(base) + int64(s[i])
	}
	check := func(l int) string {
		vis := make(map[int64]bool)
		for i := 1; i+l-1 <= n; i++ {
			j := i + l - 1
			t := h[j] - h[i-1]*p[j-i+1]
			if vis[t] {
				return s[i-1 : j]
			}
			vis[t] = true
		}
		return ""
	}
	left, right := 0, n
	ans := ""
	for left < right {
		mid := (left + right + 1) >> 1
		t := check(mid)
		if len(t) > 0 {
			left = mid
			ans = t
		} else {
			right = mid - 1
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

# [1045. 买下所有产品的客户](https://leetcode.cn/problems/customers-who-bought-all-products){#1045}

{{< tabs "1045" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT customer_id
FROM Customer
GROUP BY 1
HAVING COUNT(DISTINCT product_key) = (SELECT COUNT(1) FROM Product);
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p><code>Customer</code>&nbsp;表：</p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| customer_id | int     |
| product_key | int     |
+-------------+---------+
该表可能包含重复的行。
customer_id 不为 NULL。
product_key 是 Product 表的外键(reference 列)。
</pre>

<p><code>Product</code>&nbsp;表：</p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| product_key | int     |
+-------------+---------+
product_key 是这张表的主键（具有唯一值的列）。
</pre>

<p>&nbsp;</p>

<p>编写解决方案，报告&nbsp;<code>Customer</code> 表中购买了 <code>Product</code> 表中所有产品的客户的 id。</p>

<p>返回结果表 <strong>无顺序要求</strong> 。</p>

<p>返回结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
Customer 表：
+-------------+-------------+
| customer_id | product_key |
+-------------+-------------+
| 1           | 5           |
| 2           | 6           |
| 3           | 5           |
| 3           | 6           |
| 1           | 6           |
+-------------+-------------+
Product 表：
+-------------+
| product_key |
+-------------+
| 5           |
| 6           |
+-------------+
<strong>输出：</strong>
+-------------+
| customer_id |
+-------------+
| 1           |
| 3           |
+-------------+
<strong>解释：</strong>
购买了所有产品（5 和 6）的客户的 id 是 1 和 3 。
</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：分组统计 + 子查询

我们将 `Customer` 表按照 `customer_id` 进行分组，然后使用 `HAVING` 子句筛选出购买了所有产品的客户。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT customer_id
FROM Customer
GROUP BY 1
HAVING COUNT(DISTINCT product_key) = (SELECT COUNT(1) FROM Product);
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1046. 最后一块石头的重量](https://leetcode.cn/problems/last-stone-weight){#1046}

{{< tabs "1046" >}}

{{% tab "python" %}}
```python
class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        h = [-x for x in stones]
        heapify(h)
        while len(h) > 1:
            y, x = -heappop(h), -heappop(h)
            if x != y:
                heappush(h, x - y)
        return 0 if not h else -h[0]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int lastStoneWeight(int[] stones) {
        PriorityQueue<Integer> q = new PriorityQueue<>((a, b) -> b - a);
        for (int x : stones) {
            q.offer(x);
        }
        while (q.size() > 1) {
            int y = q.poll();
            int x = q.poll();
            if (x != y) {
                q.offer(y - x);
            }
        }
        return q.isEmpty() ? 0 : q.poll();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (int x : stones) {
            pq.push(x);
        }
        while (pq.size() > 1) {
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();
            if (x != y) {
                pq.push(y - x);
            }
        }
        return pq.empty() ? 0 : pq.top();
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func lastStoneWeight(stones []int) int {
	q := &hp{stones}
	heap.Init(q)
	for q.Len() > 1 {
		y, x := q.pop(), q.pop()
		if x != y {
			q.push(y - x)
		}
	}
	if q.Len() > 0 {
		return q.IntSlice[0]
	}
	return 0
}

type hp struct{ sort.IntSlice }

func (h hp) Less(i, j int) bool { return h.IntSlice[i] > h.IntSlice[j] }
func (h *hp) Push(v any)        { h.IntSlice = append(h.IntSlice, v.(int)) }
func (h *hp) Pop() any {
	a := h.IntSlice
	v := a[len(a)-1]
	h.IntSlice = a[:len(a)-1]
	return v
}
func (h *hp) push(v int) { heap.Push(h, v) }
func (h *hp) pop() int   { return heap.Pop(h).(int) }
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function lastStoneWeight(stones: number[]): number {
    const pq = new MaxPriorityQueue<number>();
    for (const x of stones) {
        pq.enqueue(x);
    }
    while (pq.size() > 1) {
        const y = pq.dequeue();
        const x = pq.dequeue();
        if (x !== y) {
            pq.enqueue(y - x);
        }
    }
    return pq.isEmpty() ? 0 : pq.dequeue();
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} stones
 * @return {number}
 */
var lastStoneWeight = function (stones) {
    const pq = new MaxPriorityQueue();
    for (const x of stones) {
        pq.enqueue(x);
    }
    while (pq.size() > 1) {
        const y = pq.dequeue();
        const x = pq.dequeue();
        if (x != y) {
            pq.enqueue(y - x);
        }
    }
    return pq.isEmpty() ? 0 : pq.dequeue();
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>有一堆石头，每块石头的重量都是正整数。</p>

<p>每一回合，从中选出两块<strong> 最重的</strong> 石头，然后将它们一起粉碎。假设石头的重量分别为 <code>x</code> 和 <code>y</code>，且 <code>x <= y</code>。那么粉碎的可能结果如下：</p>

<ul>
	<li>如果 <code>x == y</code>，那么两块石头都会被完全粉碎；</li>
	<li>如果 <code>x != y</code>，那么重量为 <code>x</code> 的石头将会完全粉碎，而重量为 <code>y</code> 的石头新重量为 <code>y-x</code>。</li>
</ul>

<p>最后，最多只会剩下一块石头。返回此石头的重量。如果没有石头剩下，就返回 <code>0</code>。</p>

<p> </p>

<p><strong>示例：</strong></p>

<pre>
<strong>输入：</strong>[2,7,4,1,8,1]
<strong>输出：</strong>1
<strong>解释：</strong>
先选出 7 和 8，得到 1，所以数组转换为 [2,4,1,1,1]，
再选出 2 和 4，得到 2，所以数组转换为 [2,1,1,1]，
接着是 2 和 1，得到 1，所以数组转换为 [1,1,1]，
最后选出 1 和 1，得到 0，最终数组转换为 [1]，这就是最后剩下那块石头的重量。</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= stones.length <= 30</code></li>
	<li><code>1 <= stones[i] <= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：优先队列（大根堆）

我们将数组 `stones` 所有元素放入大根堆，然后执行循环操作，每次弹出两个元素 $y$ 和 $x$，如果 $x \neq y$，将 $y - x$ 放入大根堆。当堆元素个数小于 $2$ 时，退出循环。

最后如果存在堆顶元素，则将其返回，否则返回 $0$。

时间复杂度 $O(n\log n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 `stones` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        h = [-x for x in stones]
        heapify(h)
        while len(h) > 1:
            y, x = -heappop(h), -heappop(h)
            if x != y:
                heappush(h, x - y)
        return 0 if not h else -h[0]
```

#### Java

```java
class Solution {
    public int lastStoneWeight(int[] stones) {
        PriorityQueue<Integer> q = new PriorityQueue<>((a, b) -> b - a);
        for (int x : stones) {
            q.offer(x);
        }
        while (q.size() > 1) {
            int y = q.poll();
            int x = q.poll();
            if (x != y) {
                q.offer(y - x);
            }
        }
        return q.isEmpty() ? 0 : q.poll();
    }
}
```

#### C++

```cpp
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (int x : stones) {
            pq.push(x);
        }
        while (pq.size() > 1) {
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();
            if (x != y) {
                pq.push(y - x);
            }
        }
        return pq.empty() ? 0 : pq.top();
    }
};
```

#### Go

```go
func lastStoneWeight(stones []int) int {
	q := &hp{stones}
	heap.Init(q)
	for q.Len() > 1 {
		y, x := q.pop(), q.pop()
		if x != y {
			q.push(y - x)
		}
	}
	if q.Len() > 0 {
		return q.IntSlice[0]
	}
	return 0
}

type hp struct{ sort.IntSlice }

func (h hp) Less(i, j int) bool { return h.IntSlice[i] > h.IntSlice[j] }
func (h *hp) Push(v any)        { h.IntSlice = append(h.IntSlice, v.(int)) }
func (h *hp) Pop() any {
	a := h.IntSlice
	v := a[len(a)-1]
	h.IntSlice = a[:len(a)-1]
	return v
}
func (h *hp) push(v int) { heap.Push(h, v) }
func (h *hp) pop() int   { return heap.Pop(h).(int) }
```

#### TypeScript

```ts
function lastStoneWeight(stones: number[]): number {
    const pq = new MaxPriorityQueue<number>();
    for (const x of stones) {
        pq.enqueue(x);
    }
    while (pq.size() > 1) {
        const y = pq.dequeue();
        const x = pq.dequeue();
        if (x !== y) {
            pq.enqueue(y - x);
        }
    }
    return pq.isEmpty() ? 0 : pq.dequeue();
}
```

#### JavaScript

```js
/**
 * @param {number[]} stones
 * @return {number}
 */
var lastStoneWeight = function (stones) {
    const pq = new MaxPriorityQueue();
    for (const x of stones) {
        pq.enqueue(x);
    }
    while (pq.size() > 1) {
        const y = pq.dequeue();
        const x = pq.dequeue();
        if (x != y) {
            pq.enqueue(y - x);
        }
    }
    return pq.isEmpty() ? 0 : pq.dequeue();
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1047. 删除字符串中的所有相邻重复项](https://leetcode.cn/problems/remove-all-adjacent-duplicates-in-string){#1047}

{{< tabs "1047" >}}

{{% tab "python" %}}
```python
class Solution:
    def removeDuplicates(self, s: str) -> str:
        stk = []
        for c in s:
            if stk and stk[-1] == c:
                stk.pop()
            else:
                stk.append(c)
        return ''.join(stk)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String removeDuplicates(String s) {
        StringBuilder sb = new StringBuilder();
        for (char c : s.toCharArray()) {
            if (sb.length() > 0 && sb.charAt(sb.length() - 1) == c) {
                sb.deleteCharAt(sb.length() - 1);
            } else {
                sb.append(c);
            }
        }
        return sb.toString();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string removeDuplicates(string s) {
        string stk;
        for (char c : s) {
            if (!stk.empty() && stk[stk.size() - 1] == c) {
                stk.pop_back();
            } else {
                stk += c;
            }
        }
        return stk;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func removeDuplicates(s string) string {
	stk := []rune{}
	for _, c := range s {
		if len(stk) > 0 && stk[len(stk)-1] == c {
			stk = stk[:len(stk)-1]
		} else {
			stk = append(stk, c)
		}
	}
	return string(stk)
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn remove_duplicates(s: String) -> String {
        let mut stack = Vec::new();
        for c in s.chars() {
            if !stack.is_empty() && *stack.last().unwrap() == c {
                stack.pop();
            } else {
                stack.push(c);
            }
        }
        stack.into_iter().collect()
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {string} s
 * @return {string}
 */
var removeDuplicates = function (s) {
    const stk = [];
    for (const c of s) {
        if (stk.length && stk[stk.length - 1] == c) {
            stk.pop();
        } else {
            stk.push(c);
        }
    }
    return stk.join('');
};
```
{{% /tab %}}
{{% tab "c" %}}
```c
char* removeDuplicates(char* s) {
    int n = strlen(s);
    char* stack = malloc(sizeof(char) * (n + 1));
    int i = 0;
    for (int j = 0; j < n; j++) {
        char c = s[j];
        if (i && stack[i - 1] == c) {
            i--;
        } else {
            stack[i++] = c;
        }
    }
    stack[i] = '\0';
    return stack;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给出由小写字母组成的字符串&nbsp;<code>s</code>，<strong>重复项删除操作</strong>会选择两个相邻且相同的字母，并删除它们。</p>

<p>在 <code>s</code> 上反复执行重复项删除操作，直到无法继续删除。</p>

<p>在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。</p>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre>
<strong>输入：</strong>"abbaca"
<strong>输出：</strong>"ca"
<strong>解释：</strong>
例如，在 "abbaca" 中，我们可以删除 "bb" 由于两字母相邻且相同，这是此时唯一可以执行删除操作的重复项。之后我们得到字符串 "aaca"，其中又只有 "aa" 可以执行重复项删除操作，所以最后的字符串为 "ca"。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ol>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> 仅由小写英文字母组成。</li>
</ol>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：栈

遍历字符串 `s` 中的每个字符 `c`，若栈为空或者栈顶值不等于字符 `c`，将 `c` 入栈，否则栈顶元素出栈。

最后返回栈中元素所组成的字符串。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是字符串 `s` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def removeDuplicates(self, s: str) -> str:
        stk = []
        for c in s:
            if stk and stk[-1] == c:
                stk.pop()
            else:
                stk.append(c)
        return ''.join(stk)
```

#### Java

```java
class Solution {
    public String removeDuplicates(String s) {
        StringBuilder sb = new StringBuilder();
        for (char c : s.toCharArray()) {
            if (sb.length() > 0 && sb.charAt(sb.length() - 1) == c) {
                sb.deleteCharAt(sb.length() - 1);
            } else {
                sb.append(c);
            }
        }
        return sb.toString();
    }
}
```

#### C++

```cpp
class Solution {
public:
    string removeDuplicates(string s) {
        string stk;
        for (char c : s) {
            if (!stk.empty() && stk[stk.size() - 1] == c) {
                stk.pop_back();
            } else {
                stk += c;
            }
        }
        return stk;
    }
};
```

#### Go

```go
func removeDuplicates(s string) string {
	stk := []rune{}
	for _, c := range s {
		if len(stk) > 0 && stk[len(stk)-1] == c {
			stk = stk[:len(stk)-1]
		} else {
			stk = append(stk, c)
		}
	}
	return string(stk)
}
```

#### Rust

```rust
impl Solution {
    pub fn remove_duplicates(s: String) -> String {
        let mut stack = Vec::new();
        for c in s.chars() {
            if !stack.is_empty() && *stack.last().unwrap() == c {
                stack.pop();
            } else {
                stack.push(c);
            }
        }
        stack.into_iter().collect()
    }
}
```

#### JavaScript

```js
/**
 * @param {string} s
 * @return {string}
 */
var removeDuplicates = function (s) {
    const stk = [];
    for (const c of s) {
        if (stk.length && stk[stk.length - 1] == c) {
            stk.pop();
        } else {
            stk.push(c);
        }
    }
    return stk.join('');
};
```

#### C

```c
char* removeDuplicates(char* s) {
    int n = strlen(s);
    char* stack = malloc(sizeof(char) * (n + 1));
    int i = 0;
    for (int j = 0; j < n; j++) {
        char c = s[j];
        if (i && stack[i - 1] == c) {
            i--;
        } else {
            stack[i++] = c;
        }
    }
    stack[i] = '\0';
    return stack;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1048. 最长字符串链](https://leetcode.cn/problems/longest-string-chain){#1048}

{{< tabs "1048" >}}

{{% tab "python" %}}
```python
class Solution:
    def longestStrChain(self, words: List[str]) -> int:
        words.sort(key=lambda x: len(x))
        res = 0
        mp = {}
        for word in words:
            x = 1
            for i in range(len(word)):
                pre = word[:i] + word[i + 1 :]
                x = max(x, mp.get(pre, 0) + 1)
            mp[word] = x
            res = max(res, x)
        return res
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int longestStrChain(String[] words) {
        Arrays.sort(words, Comparator.comparingInt(String::length));
        int res = 0;
        Map<String, Integer> map = new HashMap<>();
        for (String word : words) {
            int x = 1;
            for (int i = 0; i < word.length(); ++i) {
                String pre = word.substring(0, i) + word.substring(i + 1);
                x = Math.max(x, map.getOrDefault(pre, 0) + 1);
            }
            map.put(word, x);
            res = Math.max(res, x);
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
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [&](string a, string b) { return a.size() < b.size(); });
        int res = 0;
        unordered_map<string, int> map;
        for (auto word : words) {
            int x = 1;
            for (int i = 0; i < word.size(); ++i) {
                string pre = word.substr(0, i) + word.substr(i + 1);
                x = max(x, map[pre] + 1);
            }
            map[word] = x;
            res = max(res, x);
        }
        return res;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func longestStrChain(words []string) int {
	sort.Slice(words, func(i, j int) bool { return len(words[i]) < len(words[j]) })
	res := 0
	mp := make(map[string]int)
	for _, word := range words {
		x := 1
		for i := 0; i < len(word); i++ {
			pre := word[0:i] + word[i+1:len(word)]
			x = max(x, mp[pre]+1)
		}
		mp[word] = x
		res = max(res, x)
	}
	return res
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function longestStrChain(words: string[]): number {
    words.sort((a, b) => a.length - b.length);
    let ans = 0;
    let hashTable = new Map();
    for (let word of words) {
        let c = 1;
        for (let i = 0; i < word.length; i++) {
            let pre = word.substring(0, i) + word.substring(i + 1);
            c = Math.max(c, (hashTable.get(pre) || 0) + 1);
        }
        hashTable.set(word, c);
        ans = Math.max(ans, c);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashMap;

impl Solution {
    #[allow(dead_code)]
    pub fn longest_str_chain(words: Vec<String>) -> i32 {
        let mut words = words;
        let mut ret = 0;
        let mut map: HashMap<String, i32> = HashMap::new();

        // Sort the words vector first
        words.sort_by(|lhs, rhs| lhs.len().cmp(&rhs.len()));

        // Begin the "dp" process
        for w in words.iter() {
            let n = w.len();
            let mut x = 1;

            for i in 0..n {
                let s = w[..i].to_string() + &w[i + 1..];
                let v = map.entry(s.clone()).or_default();
                x = std::cmp::max(x, *v + 1);
            }

            map.insert(w.clone(), x);

            ret = std::cmp::max(ret, x);
        }

        ret
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给出一个单词数组&nbsp;<code>words</code>&nbsp;，其中每个单词都由小写英文字母组成。</p>

<p>如果我们可以&nbsp;<strong>不改变其他字符的顺序&nbsp;</strong>，在 <code>word<sub>A</sub></code>&nbsp;的任何地方添加 <strong>恰好一个</strong> 字母使其变成&nbsp;<code>word<sub>B</sub></code>&nbsp;，那么我们认为&nbsp;<code>word<sub>A</sub></code>&nbsp;是&nbsp;<code>word<sub>B</sub></code>&nbsp;的 <strong>前身</strong> 。</p>

<ul>
	<li>例如，<code>"abc"</code>&nbsp;是&nbsp;<code>"abac"</code>&nbsp;的 <strong>前身</strong>&nbsp;，而&nbsp;<code>"cba"</code>&nbsp;不是&nbsp;<code>"bcad"</code>&nbsp;的 <strong>前身</strong></li>
</ul>

<p><strong>词链</strong>是单词&nbsp;<code>[word_1, word_2, ..., word_k]</code>&nbsp;组成的序列，<code>k &gt;= 1</code>，其中&nbsp;<code>word<sub>1</sub></code>&nbsp;是&nbsp;<code>word<sub>2</sub></code>&nbsp;的前身，<code>word<sub>2</sub></code>&nbsp;是&nbsp;<code>word<sub>3</sub></code>&nbsp;的前身，依此类推。一个单词通常是 <code>k == 1</code> 的 <strong>单词链</strong>&nbsp;。</p>

<p>从给定单词列表 <code>words</code> 中选择单词组成词链，返回 词链的&nbsp;<strong>最长可能长度</strong> 。<br />
&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>words = ["a","b","ba","bca","bda","bdca"]
<strong>输出：</strong>4
<strong>解释：</strong>最长单词链之一为 ["a","<u>b</u>a","b<u>d</u>a","bd<u>c</u>a"]
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<b>输入：</b>words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
<b>输出：</b>5
<b>解释：</b>所有的单词都可以放入单词链 ["xb", "xb<u>c</u>", "<u>c</u>xbc", "<u>p</u>cxbc", "pcxbc<u>f</u>"].
</pre>

<p><strong>示例&nbsp;3:</strong></p>

<pre>
<b>输入：</b>words = ["abcd","dbqca"]
<strong>输出：</strong>1
<b>解释：</b>字链["abcd"]是最长的字链之一。
["abcd"，"dbqca"]不是一个有效的单词链，因为字母的顺序被改变了。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 1000</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 16</code></li>
	<li><code>words[i]</code>&nbsp;仅由小写英文字母组成。</li>
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
    def longestStrChain(self, words: List[str]) -> int:
        def check(w1, w2):
            if len(w2) - len(w1) != 1:
                return False
            i = j = cnt = 0
            while i < len(w1) and j < len(w2):
                if w1[i] != w2[j]:
                    cnt += 1
                else:
                    i += 1
                j += 1
            return cnt < 2 and i == len(w1)

        n = len(words)
        dp = [1] * (n + 1)
        words.sort(key=lambda x: len(x))
        res = 1
        for i in range(1, n):
            for j in range(i):
                if check(words[j], words[i]):
                    dp[i] = max(dp[i], dp[j] + 1)
            res = max(res, dp[i])
        return res
```

#### Java

```java
class Solution {
    public int longestStrChain(String[] words) {
        Arrays.sort(words, Comparator.comparingInt(String::length));
        int res = 0;
        Map<String, Integer> map = new HashMap<>();
        for (String word : words) {
            int x = 1;
            for (int i = 0; i < word.length(); ++i) {
                String pre = word.substring(0, i) + word.substring(i + 1);
                x = Math.max(x, map.getOrDefault(pre, 0) + 1);
            }
            map.put(word, x);
            res = Math.max(res, x);
        }
        return res;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [&](string a, string b) { return a.size() < b.size(); });
        int res = 0;
        unordered_map<string, int> map;
        for (auto word : words) {
            int x = 1;
            for (int i = 0; i < word.size(); ++i) {
                string pre = word.substr(0, i) + word.substr(i + 1);
                x = max(x, map[pre] + 1);
            }
            map[word] = x;
            res = max(res, x);
        }
        return res;
    }
};
```

#### Go

```go
func longestStrChain(words []string) int {
	sort.Slice(words, func(i, j int) bool { return len(words[i]) < len(words[j]) })
	res := 0
	mp := make(map[string]int)
	for _, word := range words {
		x := 1
		for i := 0; i < len(word); i++ {
			pre := word[0:i] + word[i+1:len(word)]
			x = max(x, mp[pre]+1)
		}
		mp[word] = x
		res = max(res, x)
	}
	return res
}
```

#### TypeScript

```ts
function longestStrChain(words: string[]): number {
    words.sort((a, b) => a.length - b.length);
    let ans = 0;
    let hashTable = new Map();
    for (let word of words) {
        let c = 1;
        for (let i = 0; i < word.length; i++) {
            let pre = word.substring(0, i) + word.substring(i + 1);
            c = Math.max(c, (hashTable.get(pre) || 0) + 1);
        }
        hashTable.set(word, c);
        ans = Math.max(ans, c);
    }
    return ans;
}
```

#### Rust

```rust
use std::collections::HashMap;

impl Solution {
    #[allow(dead_code)]
    pub fn longest_str_chain(words: Vec<String>) -> i32 {
        let mut words = words;
        let mut ret = 0;
        let mut map: HashMap<String, i32> = HashMap::new();

        // Sort the words vector first
        words.sort_by(|lhs, rhs| lhs.len().cmp(&rhs.len()));

        // Begin the "dp" process
        for w in words.iter() {
            let n = w.len();
            let mut x = 1;

            for i in 0..n {
                let s = w[..i].to_string() + &w[i + 1..];
                let v = map.entry(s.clone()).or_default();
                x = std::cmp::max(x, *v + 1);
            }

            map.insert(w.clone(), x);

            ret = std::cmp::max(ret, x);
        }

        ret
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def longestStrChain(self, words: List[str]) -> int:
        words.sort(key=lambda x: len(x))
        res = 0
        mp = {}
        for word in words:
            x = 1
            for i in range(len(word)):
                pre = word[:i] + word[i + 1 :]
                x = max(x, mp.get(pre, 0) + 1)
            mp[word] = x
            res = max(res, x)
        return res
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1049. 最后一块石头的重量 II](https://leetcode.cn/problems/last-stone-weight-ii){#1049}

{{< tabs "1049" >}}

{{% tab "python" %}}
```python
class Solution:
    def lastStoneWeightII(self, stones: List[int]) -> int:
        s = sum(stones)
        m, n = len(stones), s >> 1
        dp = [0] * (n + 1)
        for v in stones:
            for j in range(n, v - 1, -1):
                dp[j] = max(dp[j], dp[j - v] + v)
        return s - dp[-1] * 2
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int lastStoneWeightII(int[] stones) {
        int s = 0;
        for (int v : stones) {
            s += v;
        }
        int m = stones.length;
        int n = s >> 1;
        int[] dp = new int[n + 1];
        for (int v : stones) {
            for (int j = n; j >= v; --j) {
                dp[j] = Math.max(dp[j], dp[j - v] + v);
            }
        }
        return s - dp[n] * 2;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int s = accumulate(stones.begin(), stones.end(), 0);
        int n = s >> 1;
        vector<int> dp(n + 1);
        for (int& v : stones)
            for (int j = n; j >= v; --j)
                dp[j] = max(dp[j], dp[j - v] + v);
        return s - dp[n] * 2;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func lastStoneWeightII(stones []int) int {
	s := 0
	for _, v := range stones {
		s += v
	}
	n := s >> 1
	dp := make([]int, n+1)
	for _, v := range stones {
		for j := n; j >= v; j-- {
			dp[j] = max(dp[j], dp[j-v]+v)
		}
	}
	return s - dp[n]*2
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    #[allow(dead_code)]
    pub fn last_stone_weight_ii(stones: Vec<i32>) -> i32 {
        let n = stones.len();
        let mut sum = 0;

        for e in &stones {
            sum += *e;
        }

        let m = (sum / 2) as usize;
        let mut dp: Vec<Vec<i32>> = vec![vec![0; m + 1]; n + 1];

        // Begin the actual dp process
        for i in 1..=n {
            for j in 1..=m {
                dp[i][j] = if stones[i - 1] > (j as i32) {
                    dp[i - 1][j]
                } else {
                    std::cmp::max(
                        dp[i - 1][j],
                        dp[i - 1][j - (stones[i - 1] as usize)] + stones[i - 1],
                    )
                };
            }
        }

        sum - 2 * dp[n][m]
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} stones
 * @return {number}
 */
var lastStoneWeightII = function (stones) {
    let s = 0;
    for (let v of stones) {
        s += v;
    }
    const n = s >> 1;
    let dp = new Array(n + 1).fill(0);
    for (let v of stones) {
        for (let j = n; j >= v; --j) {
            dp[j] = Math.max(dp[j], dp[j - v] + v);
        }
    }
    return s - dp[n] * 2;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>有一堆石头，用整数数组&nbsp;<code>stones</code> 表示。其中&nbsp;<code>stones[i]</code> 表示第 <code>i</code> 块石头的重量。</p>

<p>每一回合，从中选出<strong>任意两块石头</strong>，然后将它们一起粉碎。假设石头的重量分别为&nbsp;<code>x</code> 和&nbsp;<code>y</code>，且&nbsp;<code>x &lt;= y</code>。那么粉碎的可能结果如下：</p>

<ul>
	<li>如果&nbsp;<code>x == y</code>，那么两块石头都会被完全粉碎；</li>
	<li>如果&nbsp;<code>x != y</code>，那么重量为&nbsp;<code>x</code>&nbsp;的石头将会完全粉碎，而重量为&nbsp;<code>y</code>&nbsp;的石头新重量为&nbsp;<code>y-x</code>。</li>
</ul>

<p>最后，<strong>最多只会剩下一块 </strong>石头。返回此石头 <strong>最小的可能重量 </strong>。如果没有石头剩下，就返回 <code>0</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>stones = [2,7,4,1,8,1]
<strong>输出：</strong>1
<strong>解释：</strong>
组合 2 和 4，得到 2，所以数组转化为 [2,7,1,8,1]，
组合 7 和 8，得到 1，所以数组转化为 [2,1,1,1]，
组合 2 和 1，得到 1，所以数组转化为 [1,1,1]，
组合 1 和 1，得到 0，所以数组转化为 [1]，这就是最优值。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>stones = [31,26,33,21,40]
<strong>输出：</strong>5
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= stones.length &lt;= 30</code></li>
	<li><code>1 &lt;= stones[i] &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

**两个**石头的重量越接近，粉碎后的新重量就越小。同样的，**两堆**石头的重量越接近，它们粉碎后的新重量也越小。

所以本题可以转换为，计算容量为 `sum / 2` 的背包最多能装多少重量的石头。

定义 `dp[i][j]` 表示从前 i 个石头中选出若干个，使得所选石头重量之和为不超过 j 的最大重量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def lastStoneWeightII(self, stones: List[int]) -> int:
        s = sum(stones)
        m, n = len(stones), s >> 1
        dp = [[0] * (n + 1) for _ in range(m + 1)]
        for i in range(1, m + 1):
            for j in range(n + 1):
                dp[i][j] = dp[i - 1][j]
                if stones[i - 1] <= j:
                    dp[i][j] = max(
                        dp[i][j], dp[i - 1][j - stones[i - 1]] + stones[i - 1]
                    )
        return s - 2 * dp[-1][-1]
```

#### Java

```java
class Solution {
    public int lastStoneWeightII(int[] stones) {
        int s = 0;
        for (int v : stones) {
            s += v;
        }
        int m = stones.length;
        int n = s >> 1;
        int[][] dp = new int[m + 1][n + 1];
        for (int i = 1; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (stones[i - 1] <= j) {
                    dp[i][j] = Math.max(dp[i][j], dp[i - 1][j - stones[i - 1]] + stones[i - 1]);
                }
            }
        }
        return s - dp[m][n] * 2;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int s = accumulate(stones.begin(), stones.end(), 0);
        int m = stones.size(), n = s >> 1;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (stones[i - 1] <= j) dp[i][j] = max(dp[i][j], dp[i - 1][j - stones[i - 1]] + stones[i - 1]);
            }
        }
        return s - dp[m][n] * 2;
    }
};
```

#### Go

```go
func lastStoneWeightII(stones []int) int {
	s := 0
	for _, v := range stones {
		s += v
	}
	m, n := len(stones), s>>1
	dp := make([][]int, m+1)
	for i := range dp {
		dp[i] = make([]int, n+1)
	}
	for i := 1; i <= m; i++ {
		for j := 0; j <= n; j++ {
			dp[i][j] = dp[i-1][j]
			if stones[i-1] <= j {
				dp[i][j] = max(dp[i][j], dp[i-1][j-stones[i-1]]+stones[i-1])
			}
		}
	}
	return s - dp[m][n]*2
}
```

#### Rust

```rust
impl Solution {
    #[allow(dead_code)]
    pub fn last_stone_weight_ii(stones: Vec<i32>) -> i32 {
        let n = stones.len();
        let mut sum = 0;

        for e in &stones {
            sum += *e;
        }

        let m = (sum / 2) as usize;
        let mut dp: Vec<Vec<i32>> = vec![vec![0; m + 1]; n + 1];

        // Begin the actual dp process
        for i in 1..=n {
            for j in 1..=m {
                dp[i][j] = if stones[i - 1] > (j as i32) {
                    dp[i - 1][j]
                } else {
                    std::cmp::max(
                        dp[i - 1][j],
                        dp[i - 1][j - (stones[i - 1] as usize)] + stones[i - 1],
                    )
                };
            }
        }

        sum - 2 * dp[n][m]
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} stones
 * @return {number}
 */
var lastStoneWeightII = function (stones) {
    let s = 0;
    for (let v of stones) {
        s += v;
    }
    const n = s >> 1;
    let dp = new Array(n + 1).fill(0);
    for (let v of stones) {
        for (let j = n; j >= v; --j) {
            dp[j] = Math.max(dp[j], dp[j - v] + v);
        }
    }
    return s - dp[n] * 2;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def lastStoneWeightII(self, stones: List[int]) -> int:
        s = sum(stones)
        m, n = len(stones), s >> 1
        dp = [0] * (n + 1)
        for v in stones:
            for j in range(n, v - 1, -1):
                dp[j] = max(dp[j], dp[j - v] + v)
        return s - dp[-1] * 2
```

#### Java

```java
class Solution {
    public int lastStoneWeightII(int[] stones) {
        int s = 0;
        for (int v : stones) {
            s += v;
        }
        int m = stones.length;
        int n = s >> 1;
        int[] dp = new int[n + 1];
        for (int v : stones) {
            for (int j = n; j >= v; --j) {
                dp[j] = Math.max(dp[j], dp[j - v] + v);
            }
        }
        return s - dp[n] * 2;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int s = accumulate(stones.begin(), stones.end(), 0);
        int n = s >> 1;
        vector<int> dp(n + 1);
        for (int& v : stones)
            for (int j = n; j >= v; --j)
                dp[j] = max(dp[j], dp[j - v] + v);
        return s - dp[n] * 2;
    }
};
```

#### Go

```go
func lastStoneWeightII(stones []int) int {
	s := 0
	for _, v := range stones {
		s += v
	}
	n := s >> 1
	dp := make([]int, n+1)
	for _, v := range stones {
		for j := n; j >= v; j-- {
			dp[j] = max(dp[j], dp[j-v]+v)
		}
	}
	return s - dp[n]*2
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
