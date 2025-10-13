---
title: "3000_对角线最长的矩形的面积"
date: 2025-10-08T18:39:55+08:00
weight: 1
tags: [二分查找, 位运算, 几何, 动态规划, 双指针, 哈希函数, 哈希表, 字符串, 字符串匹配, 数学, 数组, 枚举, 树, 树状数组, 深度优先搜索, 滚动哈希, 状态压缩, 计数, 贪心]
---

{{< markmap >}}
### [3000_对角线最长的矩形的面积](#3000)
#### [数组](#3000)
### [3001_捕获黑皇后需要的最少移动次数](#3001)
#### [数学](#3001)
#### [枚举](#3001)
### [3002_移除后集合的最多元素数](#3002)
#### [贪心](#3002)
#### [数组](#3002)
#### [哈希表](#3002)
### [3003_执行操作后的最大分割数量](#3003)
#### [位运算](#3003)
#### [字符串](#3003)
#### [动态规划](#3003)
#### [状态压缩](#3003)
### [3004_相同颜色的最大子树 🔒](#3004)
#### [树](#3004)
#### [深度优先搜索](#3004)
#### [数组](#3004)
#### [动态规划](#3004)
### [3005_最大频率元素计数](#3005)
#### [数组](#3005)
#### [哈希表](#3005)
#### [计数](#3005)
### [3006_找出数组中的美丽下标 I](#3006)
#### [双指针](#3006)
#### [字符串](#3006)
#### [二分查找](#3006)
#### [字符串匹配](#3006)
#### [哈希函数](#3006)
#### [滚动哈希](#3006)
### [3007_价值和小于等于 K 的最大数字](#3007)
#### [位运算](#3007)
#### [二分查找](#3007)
#### [动态规划](#3007)
### [3008_找出数组中的美丽下标 II](#3008)
#### [双指针](#3008)
#### [字符串](#3008)
#### [二分查找](#3008)
#### [字符串匹配](#3008)
#### [哈希函数](#3008)
#### [滚动哈希](#3008)
### [3009_折线图上的最大交点数量 🔒](#3009)
#### [树状数组](#3009)
#### [几何](#3009)
#### [数组](#3009)
#### [数学](#3009)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 3000_对角线最长的矩形的面积
___
#### 数组
---
### 3001_捕获黑皇后需要的最少移动次数
___
#### 数学
___
#### 枚举
---
### 3002_移除后集合的最多元素数
___
#### 贪心
___
#### 数组
___
#### 哈希表
---
### 3003_执行操作后的最大分割数量
___
#### 位运算
___
#### 字符串
___
#### 动态规划
___
#### 状态压缩
---
### 3004_相同颜色的最大子树 🔒
___
#### 树
___
#### 深度优先搜索
___
#### 数组
___
#### 动态规划
---
### 3005_最大频率元素计数
___
#### 数组
___
#### 哈希表
___
#### 计数
---
### 3006_找出数组中的美丽下标 I
___
#### 双指针
___
#### 字符串
___
#### 二分查找
___
#### 字符串匹配
___
#### 哈希函数
___
#### 滚动哈希
---
### 3007_价值和小于等于 K 的最大数字
___
#### 位运算
___
#### 二分查找
___
#### 动态规划
---
### 3008_找出数组中的美丽下标 II
___
#### 双指针
___
#### 字符串
___
#### 二分查找
___
#### 字符串匹配
___
#### 哈希函数
___
#### 滚动哈希
---
### 3009_折线图上的最大交点数量 🔒
___
#### 树状数组
___
#### 几何
___
#### 数组
___
#### 数学
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 位运算 | 几何 |
| 动态规划 | 双指针 | 哈希函数 |
| 哈希表 | 字符串 | 字符串匹配 |
| 数学 | 数组 | 枚举 |
| 树 | 树状数组 | 深度优先搜索 |
| 滚动哈希 | 状态压缩 | 计数 |
| 贪心 |  |  |

# [3000. 对角线最长的矩形的面积](https://leetcode.cn/problems/maximum-area-of-longest-diagonal-rectangle){#3000}

{{< tabs "3000" >}}

{{% tab "python" %}}
```python
class Solution:
    def areaOfMaxDiagonal(self, dimensions: List[List[int]]) -> int:
        ans = mx = 0
        for l, w in dimensions:
            t = l**2 + w**2
            if mx < t:
                mx = t
                ans = l * w
            elif mx == t:
                ans = max(ans, l * w)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int areaOfMaxDiagonal(int[][] dimensions) {
        int ans = 0, mx = 0;
        for (var d : dimensions) {
            int l = d[0], w = d[1];
            int t = l * l + w * w;
            if (mx < t) {
                mx = t;
                ans = l * w;
            } else if (mx == t) {
                ans = Math.max(ans, l * w);
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
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int ans = 0, mx = 0;
        for (auto& d : dimensions) {
            int l = d[0], w = d[1];
            int t = l * l + w * w;
            if (mx < t) {
                mx = t;
                ans = l * w;
            } else if (mx == t) {
                ans = max(ans, l * w);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func areaOfMaxDiagonal(dimensions [][]int) (ans int) {
	mx := 0
	for _, d := range dimensions {
		l, w := d[0], d[1]
		t := l*l + w*w
		if mx < t {
			mx = t
			ans = l * w
		} else if mx == t {
			ans = max(ans, l*w)
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function areaOfMaxDiagonal(dimensions: number[][]): number {
    let [ans, mx] = [0, 0];
    for (const [l, w] of dimensions) {
        const t = l * l + w * w;
        if (mx < t) {
            mx = t;
            ans = l * w;
        } else if (mx === t) {
            ans = Math.max(ans, l * w);
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn area_of_max_diagonal(dimensions: Vec<Vec<i32>>) -> i32 {
        let mut ans = 0;
        let mut mx = 0;
        for d in dimensions {
            let l = d[0];
            let w = d[1];
            let t = l * l + w * w;
            if mx < t {
                mx = t;
                ans = l * w;
            } else if mx == t {
                ans = ans.max(l * w);
            }
        }
        ans
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int AreaOfMaxDiagonal(int[][] dimensions) {
        int ans = 0, mx = 0;
        foreach (var d in dimensions) {
            int l = d[0], w = d[1];
            int t = l * l + w * w;
            if (mx < t) {
                mx = t;
                ans = l * w;
            } else if (mx == t) {
                ans = Math.Max(ans, l * w);
            }
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

<p>给你一个下标从<strong> 0</strong> 开始的二维整数数组 <code>dimensions</code>。</p>

<p>对于所有下标 <code>i</code>（<code>0 &lt;= i &lt; dimensions.length</code>），<code>dimensions[i][0]</code> 表示矩形 <span style="font-size: 13.3333px;"> <code>i</code></span> 的长度，而 <code>dimensions[i][1]</code> 表示矩形 <span style="font-size: 13.3333px;"> <code>i</code></span> 的宽度。</p>

<p>返回对角线最 <strong>长 </strong>的矩形的<strong> 面积 </strong>。如果存在多个对角线长度相同的矩形，返回其中面积最<strong> 大 </strong>的矩形的面积。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>dimensions = [[9,3],[8,6]]
<strong>输出：</strong>48
<strong>解释：</strong>
下标 = 0，长度 = 9，宽度 = 3。对角线长度 = sqrt(9 * 9 + 3 * 3) = sqrt(90) ≈<!-- notionvc: 882cf44c-3b17-428e-9c65-9940810216f1 --> 9.487。
下标 = 1，长度 = 8，宽度 = 6。对角线长度 = sqrt(8 * 8 + 6 * 6) = sqrt(100) = 10。
因此，下标为 1 的矩形对角线更长，所以返回面积 = 8 * 6 = 48。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>dimensions = [[3,4],[4,3]]
<strong>输出：</strong>12
<strong>解释：</strong>两个矩形的对角线长度相同，为 5，所以最大面积 = 12。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= dimensions.length &lt;= 100</code></li>
	<li><code>dimensions[i].length == 2</code></li>
	<li><code>1 &lt;= dimensions[i][0], dimensions[i][1] &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数学

根据勾股定理，矩形的对角线的平方为 $l^2 + w^2$，其中 $l$ 和 $w$ 分别是矩形的长度和宽度。

我们可以遍历所有矩形，计算它们的对角线长度的平方，并记录下最大的对角线长度和对应的面积。

遍历结束后，我们返回记录的最大面积。

时间复杂度 $O(n)$，其中 $n$ 是矩形的数量。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def areaOfMaxDiagonal(self, dimensions: List[List[int]]) -> int:
        ans = mx = 0
        for l, w in dimensions:
            t = l**2 + w**2
            if mx < t:
                mx = t
                ans = l * w
            elif mx == t:
                ans = max(ans, l * w)
        return ans
```

#### Java

```java
class Solution {
    public int areaOfMaxDiagonal(int[][] dimensions) {
        int ans = 0, mx = 0;
        for (var d : dimensions) {
            int l = d[0], w = d[1];
            int t = l * l + w * w;
            if (mx < t) {
                mx = t;
                ans = l * w;
            } else if (mx == t) {
                ans = Math.max(ans, l * w);
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
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int ans = 0, mx = 0;
        for (auto& d : dimensions) {
            int l = d[0], w = d[1];
            int t = l * l + w * w;
            if (mx < t) {
                mx = t;
                ans = l * w;
            } else if (mx == t) {
                ans = max(ans, l * w);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func areaOfMaxDiagonal(dimensions [][]int) (ans int) {
	mx := 0
	for _, d := range dimensions {
		l, w := d[0], d[1]
		t := l*l + w*w
		if mx < t {
			mx = t
			ans = l * w
		} else if mx == t {
			ans = max(ans, l*w)
		}
	}
	return
}
```

#### TypeScript

```ts
function areaOfMaxDiagonal(dimensions: number[][]): number {
    let [ans, mx] = [0, 0];
    for (const [l, w] of dimensions) {
        const t = l * l + w * w;
        if (mx < t) {
            mx = t;
            ans = l * w;
        } else if (mx === t) {
            ans = Math.max(ans, l * w);
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn area_of_max_diagonal(dimensions: Vec<Vec<i32>>) -> i32 {
        let mut ans = 0;
        let mut mx = 0;
        for d in dimensions {
            let l = d[0];
            let w = d[1];
            let t = l * l + w * w;
            if mx < t {
                mx = t;
                ans = l * w;
            } else if mx == t {
                ans = ans.max(l * w);
            }
        }
        ans
    }
}
```

#### C#

```cs
public class Solution {
    public int AreaOfMaxDiagonal(int[][] dimensions) {
        int ans = 0, mx = 0;
        foreach (var d in dimensions) {
            int l = d[0], w = d[1];
            int t = l * l + w * w;
            if (mx < t) {
                mx = t;
                ans = l * w;
            } else if (mx == t) {
                ans = Math.Max(ans, l * w);
            }
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

# [3001. 捕获黑皇后需要的最少移动次数](https://leetcode.cn/problems/minimum-moves-to-capture-the-queen){#3001}

{{< tabs "3001" >}}

{{% tab "python" %}}
```python
class Solution:
    def minMovesToCaptureTheQueen(
        self, a: int, b: int, c: int, d: int, e: int, f: int
    ) -> int:
        if a == e and (c != a or (d - b) * (d - f) > 0):
            return 1
        if b == f and (d != b or (c - a) * (c - e) > 0):
            return 1
        if c - e == d - f and (a - e != b - f or (a - c) * (a - e) > 0):
            return 1
        if c - e == f - d and (a - e != f - b or (a - c) * (a - e) > 0):
            return 1
        return 2
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        if (a == e && (c != a || (d - b) * (d - f) > 0)) {
            return 1;
        }
        if (b == f && (d != b || (c - a) * (c - e) > 0)) {
            return 1;
        }
        if (c - e == d - f && (a - e != b - f || (a - c) * (a - e) > 0)) {
            return 1;
        }
        if (c - e == f - d && (a - e != f - b || (a - c) * (a - e) > 0)) {
            return 1;
        }
        return 2;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        if (a == e && (c != a || (d - b) * (d - f) > 0)) {
            return 1;
        }
        if (b == f && (d != b || (c - a) * (c - e) > 0)) {
            return 1;
        }
        if (c - e == d - f && (a - e != b - f || (a - c) * (a - e) > 0)) {
            return 1;
        }
        if (c - e == f - d && (a - e != f - b || (a - c) * (a - e) > 0)) {
            return 1;
        }
        return 2;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minMovesToCaptureTheQueen(a int, b int, c int, d int, e int, f int) int {
	if a == e && (c != a || (d-b)*(d-f) > 0) {
		return 1
	}
	if b == f && (d != b || (c-a)*(c-e) > 0) {
		return 1
	}
	if c-e == d-f && (a-e != b-f || (a-c)*(a-e) > 0) {
		return 1
	}
	if c-e == f-d && (a-e != f-b || (a-c)*(a-e) > 0) {
		return 1
	}
	return 2
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minMovesToCaptureTheQueen(
    a: number,
    b: number,
    c: number,
    d: number,
    e: number,
    f: number,
): number {
    if (a === e && (c !== a || (d - b) * (d - f) > 0)) {
        return 1;
    }
    if (b === f && (d !== b || (c - a) * (c - e) > 0)) {
        return 1;
    }
    if (c - e === d - f && (a - e !== b - f || (a - c) * (a - e) > 0)) {
        return 1;
    }
    if (c - e === f - d && (a - e !== f - b || (a - c) * (a - e) > 0)) {
        return 1;
    }
    return 2;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn min_moves_to_capture_the_queen(a: i32, b: i32, c: i32, d: i32, e: i32, f: i32) -> i32 {
        if a == e && (c != a || (d - b) * (d - f) > 0) {
            return 1;
        }
        if b == f && (d != b || (c - a) * (c - e) > 0) {
            return 1;
        }
        if c - e == d - f && (a - e != b - f || (a - c) * (a - e) > 0) {
            return 1;
        }
        if c - e == f - d && (a - e != f - b || (a - c) * (a - e) > 0) {
            return 1;
        }
        return 2;
    }
}
```
{{% /tab %}}
{{% tab "cj" %}}
```cj
class Solution {
    func minMovesToCaptureTheQueen(a: Int64, b: Int64, c: Int64, d: Int64, e: Int64, f: Int64): Int64 {
        if (a == e && (c != a || (d - b) * (d - f) > 0)) {
            return 1
        }
        if (b == f && (d != b || (c - a) * (c - e) > 0)) {
            return 1
        }
        if (c - e == d - f && (a - e != b - f || (a - c) * (a - e) > 0)) {
            return 1
        }
        if (c - e == f - d && (a - e != f - b || (a - c) * (a - e) > 0)) {
            return 1
        }
        2
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>现有一个下标从 <strong>1</strong> 开始的 <code>8 x 8</code> 棋盘，上面有 <code>3</code> 枚棋子。</p>

<p>给你 <code>6</code> 个整数 <code>a</code> 、<code>b</code> 、<code>c</code> 、<code>d</code> 、<code>e</code> 和 <code>f</code> ，其中：</p>

<ul>
	<li><code>(a, b)</code> 表示白色车的位置。</li>
	<li><code>(c, d)</code> 表示白色象的位置。</li>
	<li><code>(e, f)</code> 表示黑皇后的位置。</li>
</ul>

<p>假定你只能移动白色棋子，返回捕获黑皇后所需的<strong>最少</strong>移动次数。</p>

<p><strong>请注意</strong>：</p>

<ul>
	<li>车可以向垂直或水平方向移动任意数量的格子，但不能跳过其他棋子。</li>
	<li>象可以沿对角线方向移动任意数量的格子，但不能跳过其他棋子。</li>
	<li>如果车或象能移向皇后所在的格子，则认为它们可以捕获皇后。</li>
	<li>皇后不能移动。</li>
</ul>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3000-3099/3001.Minimum%20Moves%20to%20Capture%20The%20Queen/images/ex1.png" style="width: 600px; height: 600px; padding: 10px; background: #fff; border-radius: .5rem;" />
<pre>
<strong>输入：</strong>a = 1, b = 1, c = 8, d = 8, e = 2, f = 3
<strong>输出：</strong>2
<strong>解释：</strong>将白色车先移动到 (1, 3) ，然后移动到 (2, 3) 来捕获黑皇后，共需移动 2 次。
由于起始时没有任何棋子正在攻击黑皇后，要想捕获黑皇后，移动次数不可能少于 2 次。
</pre>

<p><strong class="example">示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3000-3099/3001.Minimum%20Moves%20to%20Capture%20The%20Queen/images/ex2.png" style="width: 600px; height: 600px;padding: 10px; background: #fff; border-radius: .5rem;" />
<pre>
<strong>输入：</strong>a = 5, b = 3, c = 3, d = 4, e = 5, f = 2
<strong>输出：</strong>1
<strong>解释：</strong>可以通过以下任一方式移动 1 次捕获黑皇后：
- 将白色车移动到 (5, 2) 。
- 将白色象移动到 (5, 2) 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= a, b, c, d, e, f &lt;= 8</code></li>
	<li>两枚棋子不会同时出现在同一个格子上。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：分类讨论

根据题意，我们可以将捕获黑皇后的情况分为以下几种：

1. 白色车和黑皇后在同一行，且中间没有其他棋子，此时只需要移动白色车 $1$ 一次；
1. 白色车和黑皇后在同一列，且中间没有其他棋子，此时只需要移动白色车 $1$ 一次；
1. 白色象和黑皇后在对角线 `\` 上，且中间没有其他棋子，此时只需要移动白色象 $1$ 一次；
1. 白色象和黑皇后在对角线 `/` 上，且中间没有其他棋子，此时只需要移动白色象 $1$ 一次；
1. 其他情况，只需要移动两次。

时间复杂度 $O(1)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minMovesToCaptureTheQueen(
        self, a: int, b: int, c: int, d: int, e: int, f: int
    ) -> int:
        if a == e and (c != a or (d - b) * (d - f) > 0):
            return 1
        if b == f and (d != b or (c - a) * (c - e) > 0):
            return 1
        if c - e == d - f and (a - e != b - f or (a - c) * (a - e) > 0):
            return 1
        if c - e == f - d and (a - e != f - b or (a - c) * (a - e) > 0):
            return 1
        return 2
```

#### Java

```java
class Solution {
    public int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        if (a == e && (c != a || (d - b) * (d - f) > 0)) {
            return 1;
        }
        if (b == f && (d != b || (c - a) * (c - e) > 0)) {
            return 1;
        }
        if (c - e == d - f && (a - e != b - f || (a - c) * (a - e) > 0)) {
            return 1;
        }
        if (c - e == f - d && (a - e != f - b || (a - c) * (a - e) > 0)) {
            return 1;
        }
        return 2;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        if (a == e && (c != a || (d - b) * (d - f) > 0)) {
            return 1;
        }
        if (b == f && (d != b || (c - a) * (c - e) > 0)) {
            return 1;
        }
        if (c - e == d - f && (a - e != b - f || (a - c) * (a - e) > 0)) {
            return 1;
        }
        if (c - e == f - d && (a - e != f - b || (a - c) * (a - e) > 0)) {
            return 1;
        }
        return 2;
    }
};
```

#### Go

```go
func minMovesToCaptureTheQueen(a int, b int, c int, d int, e int, f int) int {
	if a == e && (c != a || (d-b)*(d-f) > 0) {
		return 1
	}
	if b == f && (d != b || (c-a)*(c-e) > 0) {
		return 1
	}
	if c-e == d-f && (a-e != b-f || (a-c)*(a-e) > 0) {
		return 1
	}
	if c-e == f-d && (a-e != f-b || (a-c)*(a-e) > 0) {
		return 1
	}
	return 2
}
```

#### TypeScript

```ts
function minMovesToCaptureTheQueen(
    a: number,
    b: number,
    c: number,
    d: number,
    e: number,
    f: number,
): number {
    if (a === e && (c !== a || (d - b) * (d - f) > 0)) {
        return 1;
    }
    if (b === f && (d !== b || (c - a) * (c - e) > 0)) {
        return 1;
    }
    if (c - e === d - f && (a - e !== b - f || (a - c) * (a - e) > 0)) {
        return 1;
    }
    if (c - e === f - d && (a - e !== f - b || (a - c) * (a - e) > 0)) {
        return 1;
    }
    return 2;
}
```

#### Rust

```rust
impl Solution {
    pub fn min_moves_to_capture_the_queen(a: i32, b: i32, c: i32, d: i32, e: i32, f: i32) -> i32 {
        if a == e && (c != a || (d - b) * (d - f) > 0) {
            return 1;
        }
        if b == f && (d != b || (c - a) * (c - e) > 0) {
            return 1;
        }
        if c - e == d - f && (a - e != b - f || (a - c) * (a - e) > 0) {
            return 1;
        }
        if c - e == f - d && (a - e != f - b || (a - c) * (a - e) > 0) {
            return 1;
        }
        return 2;
    }
}
```

#### Cangjie

```cj
class Solution {
    func minMovesToCaptureTheQueen(a: Int64, b: Int64, c: Int64, d: Int64, e: Int64, f: Int64): Int64 {
        if (a == e && (c != a || (d - b) * (d - f) > 0)) {
            return 1
        }
        if (b == f && (d != b || (c - a) * (c - e) > 0)) {
            return 1
        }
        if (c - e == d - f && (a - e != b - f || (a - c) * (a - e) > 0)) {
            return 1
        }
        if (c - e == f - d && (a - e != f - b || (a - c) * (a - e) > 0)) {
            return 1
        }
        2
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3002. 移除后集合的最多元素数](https://leetcode.cn/problems/maximum-size-of-a-set-after-removals){#3002}

{{< tabs "3002" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumSetSize(self, nums1: List[int], nums2: List[int]) -> int:
        s1 = set(nums1)
        s2 = set(nums2)
        n = len(nums1)
        a = min(len(s1 - s2), n // 2)
        b = min(len(s2 - s1), n // 2)
        return min(a + b + len(s1 & s2), n)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maximumSetSize(int[] nums1, int[] nums2) {
        Set<Integer> s1 = new HashSet<>();
        Set<Integer> s2 = new HashSet<>();
        for (int x : nums1) {
            s1.add(x);
        }
        for (int x : nums2) {
            s2.add(x);
        }
        int n = nums1.length;
        int a = 0, b = 0, c = 0;
        for (int x : s1) {
            if (!s2.contains(x)) {
                ++a;
            }
        }
        for (int x : s2) {
            if (!s1.contains(x)) {
                ++b;
            } else {
                ++c;
            }
        }
        a = Math.min(a, n / 2);
        b = Math.min(b, n / 2);
        return Math.min(a + b + c, n);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());
        int n = nums1.size();
        int a = 0, b = 0, c = 0;
        for (int x : s1) {
            if (!s2.count(x)) {
                ++a;
            }
        }
        for (int x : s2) {
            if (!s1.count(x)) {
                ++b;
            } else {
                ++c;
            }
        }
        a = min(a, n / 2);
        b = min(b, n / 2);
        return min(a + b + c, n);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumSetSize(nums1 []int, nums2 []int) int {
	s1 := map[int]bool{}
	s2 := map[int]bool{}
	for _, x := range nums1 {
		s1[x] = true
	}
	for _, x := range nums2 {
		s2[x] = true
	}
	a, b, c := 0, 0, 0
	for x := range s1 {
		if !s2[x] {
			a++
		}
	}
	for x := range s2 {
		if !s1[x] {
			b++
		} else {
			c++
		}
	}
	n := len(nums1)
	a = min(a, n/2)
	b = min(b, n/2)
	return min(a+b+c, n)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumSetSize(nums1: number[], nums2: number[]): number {
    const s1: Set<number> = new Set(nums1);
    const s2: Set<number> = new Set(nums2);
    const n = nums1.length;
    let [a, b, c] = [0, 0, 0];
    for (const x of s1) {
        if (!s2.has(x)) {
            ++a;
        }
    }
    for (const x of s2) {
        if (!s1.has(x)) {
            ++b;
        } else {
            ++c;
        }
    }
    a = Math.min(a, n >> 1);
    b = Math.min(b, n >> 1);
    return Math.min(a + b + c, n);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个下标从 <code>0</code> 开始的整数数组 <code>nums1</code> 和 <code>nums2</code> ，它们的长度都是偶数<code> n</code> 。</p>

<p>你必须从 <code>nums1</code> 中移除 <code>n / 2</code> 个元素，同时从 <code>nums2</code> 中也移除 <code>n / 2</code> 个元素。移除之后，你将 <code>nums1</code> 和 <code>nums2</code> 中剩下的元素插入到集合 <code>s</code> 中。</p>

<p>返回集合 <code>s</code>可能的<strong> 最多 </strong>包含多少元素。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums1 = [1,2,1,2], nums2 = [1,1,1,1]
<strong>输出：</strong>2
<strong>解释：</strong>从 nums1 和 nums2 中移除两个 1 。移除后，数组变为 nums1 = [2,2] 和 nums2 = [1,1] 。因此，s = {1,2} 。
可以证明，在移除之后，集合 s 最多可以包含 2 个元素。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums1 = [1,2,3,4,5,6], nums2 = [2,3,2,3,2,3]
<strong>输出：</strong>5
<strong>解释：</strong>从 nums1 中移除 2、3 和 6 ，同时从 nums2 中移除两个 3 和一个 2 。移除后，数组变为 nums1 = [1,4,5] 和 nums2 = [2,3,2] 。因此，s = {1,2,3,4,5} 。
可以证明，在移除之后，集合 s 最多可以包含 5 个元素。 
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums1 = [1,1,2,2,3,3], nums2 = [4,4,5,5,6,6]
<strong>输出：</strong>6
<strong>解释：</strong>从 nums1 中移除 1、2 和 3 ，同时从 nums2 中移除 4、5 和 6 。移除后，数组变为 nums1 = [1,2,3] 和 nums2 = [4,5,6] 。因此，s = {1,2,3,4,5,6} 。
可以证明，在移除之后，集合 s 最多可以包含 6 个元素。 </pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nums1.length == nums2.length</code></li>
	<li><code>1 &lt;= n &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>n</code>是偶数。</li>
	<li><code>1 &lt;= nums1[i], nums2[i] &lt;= 10<sup>9</sup></code></li>
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
    def maximumSetSize(self, nums1: List[int], nums2: List[int]) -> int:
        s1 = set(nums1)
        s2 = set(nums2)
        n = len(nums1)
        a = min(len(s1 - s2), n // 2)
        b = min(len(s2 - s1), n // 2)
        return min(a + b + len(s1 & s2), n)
```

#### Java

```java
class Solution {
    public int maximumSetSize(int[] nums1, int[] nums2) {
        Set<Integer> s1 = new HashSet<>();
        Set<Integer> s2 = new HashSet<>();
        for (int x : nums1) {
            s1.add(x);
        }
        for (int x : nums2) {
            s2.add(x);
        }
        int n = nums1.length;
        int a = 0, b = 0, c = 0;
        for (int x : s1) {
            if (!s2.contains(x)) {
                ++a;
            }
        }
        for (int x : s2) {
            if (!s1.contains(x)) {
                ++b;
            } else {
                ++c;
            }
        }
        a = Math.min(a, n / 2);
        b = Math.min(b, n / 2);
        return Math.min(a + b + c, n);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());
        int n = nums1.size();
        int a = 0, b = 0, c = 0;
        for (int x : s1) {
            if (!s2.count(x)) {
                ++a;
            }
        }
        for (int x : s2) {
            if (!s1.count(x)) {
                ++b;
            } else {
                ++c;
            }
        }
        a = min(a, n / 2);
        b = min(b, n / 2);
        return min(a + b + c, n);
    }
};
```

#### Go

```go
func maximumSetSize(nums1 []int, nums2 []int) int {
	s1 := map[int]bool{}
	s2 := map[int]bool{}
	for _, x := range nums1 {
		s1[x] = true
	}
	for _, x := range nums2 {
		s2[x] = true
	}
	a, b, c := 0, 0, 0
	for x := range s1 {
		if !s2[x] {
			a++
		}
	}
	for x := range s2 {
		if !s1[x] {
			b++
		} else {
			c++
		}
	}
	n := len(nums1)
	a = min(a, n/2)
	b = min(b, n/2)
	return min(a+b+c, n)
}
```

#### TypeScript

```ts
function maximumSetSize(nums1: number[], nums2: number[]): number {
    const s1: Set<number> = new Set(nums1);
    const s2: Set<number> = new Set(nums2);
    const n = nums1.length;
    let [a, b, c] = [0, 0, 0];
    for (const x of s1) {
        if (!s2.has(x)) {
            ++a;
        }
    }
    for (const x of s2) {
        if (!s1.has(x)) {
            ++b;
        } else {
            ++c;
        }
    }
    a = Math.min(a, n >> 1);
    b = Math.min(b, n >> 1);
    return Math.min(a + b + c, n);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3003. 执行操作后的最大分割数量](https://leetcode.cn/problems/maximize-the-number-of-partitions-after-operations){#3003}

{{< tabs "3003" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxPartitionsAfterOperations(self, s: str, k: int) -> int:
        @cache
        def dfs(i: int, cur: int, t: int) -> int:
            if i >= n:
                return 1
            v = 1 << (ord(s[i]) - ord("a"))
            nxt = cur | v
            if nxt.bit_count() > k:
                ans = dfs(i + 1, v, t) + 1
            else:
                ans = dfs(i + 1, nxt, t)
            if t:
                for j in range(26):
                    nxt = cur | (1 << j)
                    if nxt.bit_count() > k:
                        ans = max(ans, dfs(i + 1, 1 << j, 0) + 1)
                    else:
                        ans = max(ans, dfs(i + 1, nxt, 0))
            return ans

        n = len(s)
        return dfs(0, 0, 1)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private Map<List<Integer>, Integer> f = new HashMap<>();
    private String s;
    private int k;

    public int maxPartitionsAfterOperations(String s, int k) {
        this.s = s;
        this.k = k;
        return dfs(0, 0, 1);
    }

    private int dfs(int i, int cur, int t) {
        if (i >= s.length()) {
            return 1;
        }
        var key = List.of(i, cur, t);
        if (f.containsKey(key)) {
            return f.get(key);
        }
        int v = 1 << (s.charAt(i) - 'a');
        int nxt = cur | v;
        int ans = Integer.bitCount(nxt) > k ? dfs(i + 1, v, t) + 1 : dfs(i + 1, nxt, t);
        if (t > 0) {
            for (int j = 0; j < 26; ++j) {
                nxt = cur | (1 << j);
                if (Integer.bitCount(nxt) > k) {
                    ans = Math.max(ans, dfs(i + 1, 1 << j, 0) + 1);
                } else {
                    ans = Math.max(ans, dfs(i + 1, nxt, 0));
                }
            }
        }
        f.put(key, ans);
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maxPartitionsAfterOperations(string s, int k) {
        int n = s.size();
        unordered_map<long long, int> f;
        function<int(int, int, int)> dfs = [&](int i, int cur, int t) {
            if (i >= n) {
                return 1;
            }
            long long key = (long long) i << 32 | cur << 1 | t;
            if (f.count(key)) {
                return f[key];
            }
            int v = 1 << (s[i] - 'a');
            int nxt = cur | v;
            int ans = __builtin_popcount(nxt) > k ? dfs(i + 1, v, t) + 1 : dfs(i + 1, nxt, t);
            if (t) {
                for (int j = 0; j < 26; ++j) {
                    nxt = cur | (1 << j);
                    if (__builtin_popcount(nxt) > k) {
                        ans = max(ans, dfs(i + 1, 1 << j, 0) + 1);
                    } else {
                        ans = max(ans, dfs(i + 1, nxt, 0));
                    }
                }
            }
            return f[key] = ans;
        };
        return dfs(0, 0, 1);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxPartitionsAfterOperations(s string, k int) int {
	n := len(s)
	type tuple struct{ i, cur, t int }
	f := map[tuple]int{}
	var dfs func(i, cur, t int) int
	dfs = func(i, cur, t int) int {
		if i >= n {
			return 1
		}
		key := tuple{i, cur, t}
		if v, ok := f[key]; ok {
			return v
		}
		v := 1 << (s[i] - 'a')
		nxt := cur | v
		var ans int
		if bits.OnesCount(uint(nxt)) > k {
			ans = dfs(i+1, v, t) + 1
		} else {
			ans = dfs(i+1, nxt, t)
		}
		if t > 0 {
			for j := 0; j < 26; j++ {
				nxt = cur | (1 << j)
				if bits.OnesCount(uint(nxt)) > k {
					ans = max(ans, dfs(i+1, 1<<j, 0)+1)
				} else {
					ans = max(ans, dfs(i+1, nxt, 0))
				}
			}
		}
		f[key] = ans
		return ans
	}
	return dfs(0, 0, 1)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxPartitionsAfterOperations(s: string, k: number): number {
    const n = s.length;
    const f: Map<bigint, number> = new Map();
    const dfs = (i: number, cur: number, t: number): number => {
        if (i >= n) {
            return 1;
        }
        const key = (BigInt(i) << 27n) | (BigInt(cur) << 1n) | BigInt(t);
        if (f.has(key)) {
            return f.get(key)!;
        }
        const v = 1 << (s.charCodeAt(i) - 97);
        let nxt = cur | v;
        let ans = 0;
        if (bitCount(nxt) > k) {
            ans = dfs(i + 1, v, t) + 1;
        } else {
            ans = dfs(i + 1, nxt, t);
        }
        if (t) {
            for (let j = 0; j < 26; ++j) {
                nxt = cur | (1 << j);
                if (bitCount(nxt) > k) {
                    ans = Math.max(ans, dfs(i + 1, 1 << j, 0) + 1);
                } else {
                    ans = Math.max(ans, dfs(i + 1, nxt, 0));
                }
            }
        }
        f.set(key, ans);
        return ans;
    };
    return dfs(0, 0, 1);
}

function bitCount(i: number): number {
    i = i - ((i >>> 1) & 0x55555555);
    i = (i & 0x33333333) + ((i >>> 2) & 0x33333333);
    i = (i + (i >>> 4)) & 0x0f0f0f0f;
    i = i + (i >>> 8);
    i = i + (i >>> 16);
    return i & 0x3f;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong> 开始的字符串&nbsp;<code>s</code>&nbsp;和一个整数&nbsp;<code>k</code>。</p>

<p>你需要执行以下分割操作，直到字符串&nbsp;<code>s&nbsp;</code>变为&nbsp;<strong>空</strong>：</p>

<ul>
	<li>选择&nbsp;<code>s</code>&nbsp;的最长&nbsp;<strong>前缀</strong>，该前缀最多包含&nbsp;<code>k&nbsp;</code>个&nbsp;<strong>不同&nbsp;</strong>字符。</li>
	<li><strong>删除&nbsp;</strong>这个前缀，并将分割数量加一。如果有剩余字符，它们在&nbsp;<code>s</code>&nbsp;中保持原来的顺序。</li>
</ul>

<p>执行操作之 <strong>前</strong> ，你可以将&nbsp;<code>s</code>&nbsp;中&nbsp;<strong>至多一处 </strong>下标的对应字符更改为另一个小写英文字母。</p>

<p>在最优选择情形下改变至多一处下标对应字符后，用整数表示并返回操作结束时得到的 <strong>最大</strong> 分割数量。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">s = "accca", k = 2</span></p>

<p><strong>输出：</strong><span class="example-io">3</span></p>

<p><strong>解释：</strong></p>

<p>最好的方式是把&nbsp;<code>s[2]</code>&nbsp;变为除了 a 和 c 之外的东西，比如&nbsp;b。然后它变成了&nbsp;<code>"acbca"</code>。</p>

<p>然后我们执行以下操作：</p>

<ol>
	<li>最多包含 2 个不同字符的最长前缀是 <code>"ac"</code>，我们删除它然后&nbsp;<code>s</code> 变为&nbsp;<code>"bca"</code>。</li>
	<li>现在最多包含 2 个不同字符的最长前缀是&nbsp;<code>"bc"</code>，所以我们删除它然后&nbsp;<code>s</code> 变为&nbsp;<code>"a"</code>。</li>
	<li>最后，我们删除&nbsp;<code>"a"</code>&nbsp;并且&nbsp;<code>s</code>&nbsp;变成空串，所以该过程结束。</li>
</ol>

<p>进行操作时，字符串被分成 3 个部分，所以答案是 3。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">s = "aabaab", k = 3</span></p>

<p><strong>输出：</strong><span class="example-io">1</span></p>

<p><strong>解释：</strong></p>

<p>一开始&nbsp;<code>s</code>&nbsp;包含 2 个不同的字符，所以无论我们改变哪个，&nbsp;它最多包含 3 个不同字符，因此最多包含 3 个不同字符的最长前缀始终是所有字符，因此答案是 1。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">s = "xxyz", k = 1</span></p>

<p><span class="example-io"><b>输出：</b>4</span></p>

<p><strong>解释：</strong></p>

<p>最好的方式是将&nbsp;<code>s[0]</code>&nbsp;或&nbsp;<code>s[1]</code>&nbsp;变为&nbsp;<code>s</code>&nbsp;中字符以外的东西，例如将&nbsp;<code>s[0]</code>&nbsp;变为&nbsp;<code>w</code>。</p>

<p>然后&nbsp;<code>s</code>&nbsp;变为&nbsp;<code>"wxyz"</code>，包含 4 个不同的字符，所以当&nbsp;<code>k</code>&nbsp;为 1，它将分为 4 个部分。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>4</sup></code></li>
	<li><code>s</code>&nbsp;只包含小写英文字母。</li>
	<li><code>1 &lt;= k &lt;= 26</code></li>
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
    def maxPartitionsAfterOperations(self, s: str, k: int) -> int:
        @cache
        def dfs(i: int, cur: int, t: int) -> int:
            if i >= n:
                return 1
            v = 1 << (ord(s[i]) - ord("a"))
            nxt = cur | v
            if nxt.bit_count() > k:
                ans = dfs(i + 1, v, t) + 1
            else:
                ans = dfs(i + 1, nxt, t)
            if t:
                for j in range(26):
                    nxt = cur | (1 << j)
                    if nxt.bit_count() > k:
                        ans = max(ans, dfs(i + 1, 1 << j, 0) + 1)
                    else:
                        ans = max(ans, dfs(i + 1, nxt, 0))
            return ans

        n = len(s)
        return dfs(0, 0, 1)
```

#### Java

```java
class Solution {
    private Map<List<Integer>, Integer> f = new HashMap<>();
    private String s;
    private int k;

    public int maxPartitionsAfterOperations(String s, int k) {
        this.s = s;
        this.k = k;
        return dfs(0, 0, 1);
    }

    private int dfs(int i, int cur, int t) {
        if (i >= s.length()) {
            return 1;
        }
        var key = List.of(i, cur, t);
        if (f.containsKey(key)) {
            return f.get(key);
        }
        int v = 1 << (s.charAt(i) - 'a');
        int nxt = cur | v;
        int ans = Integer.bitCount(nxt) > k ? dfs(i + 1, v, t) + 1 : dfs(i + 1, nxt, t);
        if (t > 0) {
            for (int j = 0; j < 26; ++j) {
                nxt = cur | (1 << j);
                if (Integer.bitCount(nxt) > k) {
                    ans = Math.max(ans, dfs(i + 1, 1 << j, 0) + 1);
                } else {
                    ans = Math.max(ans, dfs(i + 1, nxt, 0));
                }
            }
        }
        f.put(key, ans);
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxPartitionsAfterOperations(string s, int k) {
        int n = s.size();
        unordered_map<long long, int> f;
        function<int(int, int, int)> dfs = [&](int i, int cur, int t) {
            if (i >= n) {
                return 1;
            }
            long long key = (long long) i << 32 | cur << 1 | t;
            if (f.count(key)) {
                return f[key];
            }
            int v = 1 << (s[i] - 'a');
            int nxt = cur | v;
            int ans = __builtin_popcount(nxt) > k ? dfs(i + 1, v, t) + 1 : dfs(i + 1, nxt, t);
            if (t) {
                for (int j = 0; j < 26; ++j) {
                    nxt = cur | (1 << j);
                    if (__builtin_popcount(nxt) > k) {
                        ans = max(ans, dfs(i + 1, 1 << j, 0) + 1);
                    } else {
                        ans = max(ans, dfs(i + 1, nxt, 0));
                    }
                }
            }
            return f[key] = ans;
        };
        return dfs(0, 0, 1);
    }
};
```

#### Go

```go
func maxPartitionsAfterOperations(s string, k int) int {
	n := len(s)
	type tuple struct{ i, cur, t int }
	f := map[tuple]int{}
	var dfs func(i, cur, t int) int
	dfs = func(i, cur, t int) int {
		if i >= n {
			return 1
		}
		key := tuple{i, cur, t}
		if v, ok := f[key]; ok {
			return v
		}
		v := 1 << (s[i] - 'a')
		nxt := cur | v
		var ans int
		if bits.OnesCount(uint(nxt)) > k {
			ans = dfs(i+1, v, t) + 1
		} else {
			ans = dfs(i+1, nxt, t)
		}
		if t > 0 {
			for j := 0; j < 26; j++ {
				nxt = cur | (1 << j)
				if bits.OnesCount(uint(nxt)) > k {
					ans = max(ans, dfs(i+1, 1<<j, 0)+1)
				} else {
					ans = max(ans, dfs(i+1, nxt, 0))
				}
			}
		}
		f[key] = ans
		return ans
	}
	return dfs(0, 0, 1)
}
```

#### TypeScript

```ts
function maxPartitionsAfterOperations(s: string, k: number): number {
    const n = s.length;
    const f: Map<bigint, number> = new Map();
    const dfs = (i: number, cur: number, t: number): number => {
        if (i >= n) {
            return 1;
        }
        const key = (BigInt(i) << 27n) | (BigInt(cur) << 1n) | BigInt(t);
        if (f.has(key)) {
            return f.get(key)!;
        }
        const v = 1 << (s.charCodeAt(i) - 97);
        let nxt = cur | v;
        let ans = 0;
        if (bitCount(nxt) > k) {
            ans = dfs(i + 1, v, t) + 1;
        } else {
            ans = dfs(i + 1, nxt, t);
        }
        if (t) {
            for (let j = 0; j < 26; ++j) {
                nxt = cur | (1 << j);
                if (bitCount(nxt) > k) {
                    ans = Math.max(ans, dfs(i + 1, 1 << j, 0) + 1);
                } else {
                    ans = Math.max(ans, dfs(i + 1, nxt, 0));
                }
            }
        }
        f.set(key, ans);
        return ans;
    };
    return dfs(0, 0, 1);
}

function bitCount(i: number): number {
    i = i - ((i >>> 1) & 0x55555555);
    i = (i & 0x33333333) + ((i >>> 2) & 0x33333333);
    i = (i + (i >>> 4)) & 0x0f0f0f0f;
    i = i + (i >>> 8);
    i = i + (i >>> 16);
    return i & 0x3f;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3004. 相同颜色的最大子树 🔒](https://leetcode.cn/problems/maximum-subtree-of-the-same-color){#3004}

{{< tabs "3004" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumSubtreeSize(self, edges: List[List[int]], colors: List[int]) -> int:
        def dfs(a: int, fa: int) -> bool:
            ok = True
            for b in g[a]:
                if b != fa:
                    t = dfs(b, a)
                    ok = ok and colors[a] == colors[b] and t
                    size[a] += size[b]
            if ok:
                nonlocal ans
                ans = max(ans, size[a])
            return ok

        n = len(edges) + 1
        g = [[] for _ in range(n)]
        size = [1] * n
        for a, b in edges:
            g[a].append(b)
            g[b].append(a)
        ans = 0
        dfs(0, -1)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private List<Integer>[] g;
    private int[] colors;
    private int[] size;
    private int ans;

    public int maximumSubtreeSize(int[][] edges, int[] colors) {
        int n = edges.length + 1;
        g = new List[n];
        size = new int[n];
        this.colors = colors;
        Arrays.fill(size, 1);
        Arrays.setAll(g, i -> new ArrayList<>());
        for (var e : edges) {
            int a = e[0], b = e[1];
            g[a].add(b);
            g[b].add(a);
        }
        dfs(0, -1);
        return ans;
    }

    private boolean dfs(int a, int fa) {
        boolean ok = true;
        for (int b : g[a]) {
            if (b != fa) {
                boolean t = dfs(b, a);
                ok = ok && colors[a] == colors[b] && t;
                size[a] += size[b];
            }
        }
        if (ok) {
            ans = Math.max(ans, size[a]);
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
    int maximumSubtreeSize(vector<vector<int>>& edges, vector<int>& colors) {
        int n = edges.size() + 1;
        vector<int> g[n];
        vector<int> size(n, 1);
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        int ans = 0;
        function<bool(int, int)> dfs = [&](int a, int fa) {
            bool ok = true;
            for (int b : g[a]) {
                if (b != fa) {
                    bool t = dfs(b, a);
                    ok = ok && colors[a] == colors[b] && t;
                    size[a] += size[b];
                }
            }
            if (ok) {
                ans = max(ans, size[a]);
            }
            return ok;
        };
        dfs(0, -1);
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumSubtreeSize(edges [][]int, colors []int) (ans int) {
	n := len(edges) + 1
	g := make([][]int, n)
	for _, e := range edges {
		a, b := e[0], e[1]
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}
	size := make([]int, n)
	var dfs func(int, int) bool
	dfs = func(a, fa int) bool {
		size[a] = 1
		ok := true
		for _, b := range g[a] {
			if b != fa {
				t := dfs(b, a)
				ok = ok && t && colors[a] == colors[b]
				size[a] += size[b]
			}
		}
		if ok {
			ans = max(ans, size[a])
		}
		return ok
	}
	dfs(0, -1)
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumSubtreeSize(edges: number[][], colors: number[]): number {
    const n = edges.length + 1;
    const g: number[][] = Array.from({ length: n }, () => []);
    for (const [a, b] of edges) {
        g[a].push(b);
        g[b].push(a);
    }
    const size: number[] = Array(n).fill(1);
    let ans = 0;
    const dfs = (a: number, fa: number): boolean => {
        let ok = true;
        for (const b of g[a]) {
            if (b !== fa) {
                const t = dfs(b, a);
                ok = ok && t && colors[a] === colors[b];
                size[a] += size[b];
            }
        }
        if (ok) {
            ans = Math.max(ans, size[a]);
        }
        return ok;
    };
    dfs(0, -1);
    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个二维整数数组 <code>edges</code>，表示一个有 <code>n</code> 个节点的树，节点编号从 <code>0</code> 到 <code>n - 1</code>，以节点 <code>0</code> 为根，其中 <code>edges[i] = [u<sub>i</sub>, v<sub>i</sub>]</code> 表示节点 <code>v<sub>i</sub></code> 和 <code>u<sub>i</sub></code> 之间存在一条边。</p>

<p>还给定一个 <strong>下标从 0&nbsp;开始</strong>，大小为 <code>n</code> 的整数数组 <code>colors</code>，其中 <code>colors[i]</code> 表示节点 <code>i</code> 分配的颜色。</p>

<p>我们希望找到一个节点 <code>v</code>，使得 <code>v</code> 的子树中的每个节点具有 <strong>相同</strong> 的颜色。</p>

<p>返回&nbsp;<em>具有 <strong>尽可能多</strong> 节点 且 符合上述要求的<span data-keyword="subtree">子树</span>大小。</em></p>

<p>&nbsp;</p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3000-3099/3004.Maximum%20Subtree%20of%20the%20Same%20Color/images/20231216-134026.png" style="padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem; width: 221px; height: 132px;" /></strong></p>

<p><b>示例 1：</b></p>

<pre>
<b>输入：</b>edges = [[0,1],[0,2],[0,3]], colors = [1,1,2,3]
<b>输出：</b>1
<b>解释：</b>每种颜色分别对应为：1 -&gt; 红色，2 -&gt; 绿色，3 -&gt; 蓝色。我们可以看到以节点 0 为根的子树具有不同颜色的子节点。任何其他子树都是相同颜色的，并且大小为 1。因此，我们返回 1。
</pre>

<p><b>示例 2：</b></p>

<pre>
<b>输入：</b>edges = [[0,1],[0,2],[0,3]], colors = [1,1,1,1]
<b>输出：</b>4
<b>解释：</b>整个树具有相同的颜色，以节点 0 为根的子树具有节点数最多，为 4。因此，我们返回 4。
</pre>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3000-3099/3004.Maximum%20Subtree%20of%20the%20Same%20Color/images/20231216-134017.png" style="padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem; width: 221px; height: 221px;" /></strong></p>

<p><b>示例 3：</b></p>

<pre>
<b>输入：</b>edges = [[0,1],[0,2],[2,3],[2,4]], colors = [1,2,3,3,3]
<b>输出：</b>3
<b>解释：</b>每种颜色分别对应为：1 -&gt; 红色，2 -&gt; 绿色，3 -&gt; 蓝色。我们可以看到以节点 0 为根的子树有不同颜色的子节点。其他任何子树都是相同颜色的，但以节点 2 为根的子树的大小为 3，这是最大的。因此，我们返回 3。
</pre>

<p>&nbsp;</p>

<p><b>提示：</b></p>

<ul>
	<li><code>n == edges.length + 1</code></li>
	<li><code>1 &lt;= n &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>edges[i] == [u<sub>i</sub>, v<sub>i</sub>]</code></li>
	<li><code>0 &lt;= u<sub>i</sub>, v<sub>i</sub> &lt; n</code></li>
	<li><code>colors.length == n</code></li>
	<li><code>1 &lt;= colors[i] &lt;= 10<sup>5</sup></code></li>
	<li>输入被生成，使得由 <code>edges</code> 表示的图是一棵树。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS

我们先根据题目给定的边的信息，构建一个邻接表 $g$，其中 $g[a]$ 表示节点 $a$ 的所有相邻节点。然后我们创建一个长度为 $n$ 的数组 $size$，其中 $size[a]$ 表示以节点 $a$ 为根的子树的节点数。

接下来，我们设计一个函数 $dfs(a, fa)$，它将返回以节点 $a$ 为根的子树是否满足题目要求。函数 $dfs(a, fa)$ 的执行过程如下：

-   首先，我们用一个变量 $ok$ 记录以节点 $a$ 为根的子树是否满足题目要求，初始时 $ok$ 为 $true$。
-   接着，我们遍历节点 $a$ 的所有相邻节点 $b$，如果 $b$ 不是 $a$ 的父节点 $fa$，那么我们递归调用 $dfs(b, a)$，并将返回值保存到变量 $t$ 中，并且更新 $ok$ 为 $ok$ 与 $colors[a] = colors[b] \land t$ 的值，其中 $\land$ 表示逻辑与运算。然后，我们更新 $size[a] = size[a] + size[b]$。
-   然后，我们判断 $ok$ 的值，如果 $ok$ 为 $true$，那么我们更新答案 $ans = \max(ans, size[a])$。
-   最后，我们返回 $ok$ 的值。

我们调用 $dfs(0, -1)$，其中 $0$ 表示根节点的编号，$-1$ 表示根节点没有父节点。最终的答案即为 $ans$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是节点的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumSubtreeSize(self, edges: List[List[int]], colors: List[int]) -> int:
        def dfs(a: int, fa: int) -> bool:
            ok = True
            for b in g[a]:
                if b != fa:
                    t = dfs(b, a)
                    ok = ok and colors[a] == colors[b] and t
                    size[a] += size[b]
            if ok:
                nonlocal ans
                ans = max(ans, size[a])
            return ok

        n = len(edges) + 1
        g = [[] for _ in range(n)]
        size = [1] * n
        for a, b in edges:
            g[a].append(b)
            g[b].append(a)
        ans = 0
        dfs(0, -1)
        return ans
```

#### Java

```java
class Solution {
    private List<Integer>[] g;
    private int[] colors;
    private int[] size;
    private int ans;

    public int maximumSubtreeSize(int[][] edges, int[] colors) {
        int n = edges.length + 1;
        g = new List[n];
        size = new int[n];
        this.colors = colors;
        Arrays.fill(size, 1);
        Arrays.setAll(g, i -> new ArrayList<>());
        for (var e : edges) {
            int a = e[0], b = e[1];
            g[a].add(b);
            g[b].add(a);
        }
        dfs(0, -1);
        return ans;
    }

    private boolean dfs(int a, int fa) {
        boolean ok = true;
        for (int b : g[a]) {
            if (b != fa) {
                boolean t = dfs(b, a);
                ok = ok && colors[a] == colors[b] && t;
                size[a] += size[b];
            }
        }
        if (ok) {
            ans = Math.max(ans, size[a]);
        }
        return ok;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maximumSubtreeSize(vector<vector<int>>& edges, vector<int>& colors) {
        int n = edges.size() + 1;
        vector<int> g[n];
        vector<int> size(n, 1);
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        int ans = 0;
        function<bool(int, int)> dfs = [&](int a, int fa) {
            bool ok = true;
            for (int b : g[a]) {
                if (b != fa) {
                    bool t = dfs(b, a);
                    ok = ok && colors[a] == colors[b] && t;
                    size[a] += size[b];
                }
            }
            if (ok) {
                ans = max(ans, size[a]);
            }
            return ok;
        };
        dfs(0, -1);
        return ans;
    }
};
```

#### Go

```go
func maximumSubtreeSize(edges [][]int, colors []int) (ans int) {
	n := len(edges) + 1
	g := make([][]int, n)
	for _, e := range edges {
		a, b := e[0], e[1]
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}
	size := make([]int, n)
	var dfs func(int, int) bool
	dfs = func(a, fa int) bool {
		size[a] = 1
		ok := true
		for _, b := range g[a] {
			if b != fa {
				t := dfs(b, a)
				ok = ok && t && colors[a] == colors[b]
				size[a] += size[b]
			}
		}
		if ok {
			ans = max(ans, size[a])
		}
		return ok
	}
	dfs(0, -1)
	return
}
```

#### TypeScript

```ts
function maximumSubtreeSize(edges: number[][], colors: number[]): number {
    const n = edges.length + 1;
    const g: number[][] = Array.from({ length: n }, () => []);
    for (const [a, b] of edges) {
        g[a].push(b);
        g[b].push(a);
    }
    const size: number[] = Array(n).fill(1);
    let ans = 0;
    const dfs = (a: number, fa: number): boolean => {
        let ok = true;
        for (const b of g[a]) {
            if (b !== fa) {
                const t = dfs(b, a);
                ok = ok && t && colors[a] === colors[b];
                size[a] += size[b];
            }
        }
        if (ok) {
            ans = Math.max(ans, size[a]);
        }
        return ok;
    };
    dfs(0, -1);
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3005. 最大频率元素计数](https://leetcode.cn/problems/count-elements-with-maximum-frequency){#3005}

{{< tabs "3005" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxFrequencyElements(self, nums: List[int]) -> int:
        cnt = Counter(nums)
        mx = max(cnt.values())
        return sum(x for x in cnt.values() if x == mx)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxFrequencyElements(int[] nums) {
        int[] cnt = new int[101];
        for (int x : nums) {
            ++cnt[x];
        }
        int ans = 0, mx = -1;
        for (int x : cnt) {
            if (mx < x) {
                mx = x;
                ans = x;
            } else if (mx == x) {
                ans += x;
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
    int maxFrequencyElements(vector<int>& nums) {
        int cnt[101]{};
        for (int x : nums) {
            ++cnt[x];
        }
        int ans = 0, mx = -1;
        for (int x : cnt) {
            if (mx < x) {
                mx = x;
                ans = x;
            } else if (mx == x) {
                ans += x;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxFrequencyElements(nums []int) (ans int) {
	cnt := [101]int{}
	for _, x := range nums {
		cnt[x]++
	}
	mx := -1
	for _, x := range cnt {
		if mx < x {
			mx, ans = x, x
		} else if mx == x {
			ans += x
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxFrequencyElements(nums: number[]): number {
    const cnt: number[] = Array(101).fill(0);
    for (const x of nums) {
        ++cnt[x];
    }
    let [ans, mx] = [0, -1];
    for (const x of cnt) {
        if (mx < x) {
            mx = x;
            ans = x;
        } else if (mx === x) {
            ans += x;
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn max_frequency_elements(nums: Vec<i32>) -> i32 {
        let mut cnt = [0; 101];
        for &x in &nums {
            cnt[x as usize] += 1;
        }
        let mut ans = 0;
        let mut mx = -1;
        for &x in &cnt {
            if mx < x {
                mx = x;
                ans = x;
            } else if mx == x {
                ans += x;
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

<p>给你一个由 <strong>正整数 </strong>组成的数组 <code>nums</code> 。</p>

<p>返回数组 <code>nums</code> 中所有具有 <strong>最大 </strong>频率的元素的 <strong>总频率 </strong>。</p>

<p>元素的 <strong>频率 </strong>是指该元素在数组中出现的次数。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,2,3,1,4]
<strong>输出：</strong>4
<strong>解释：</strong>元素 1 和 2 的频率为 2 ，是数组中的最大频率。
因此具有最大频率的元素在数组中的数量是 4 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3,4,5]
<strong>输出：</strong>5
<strong>解释：</strong>数组中的所有元素的频率都为 1 ，是最大频率。
因此具有最大频率的元素在数组中的数量是 5 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数

我们可以用一个哈希表或数组 $cnt$ 记录每个元素出现的次数。

然后我们遍历 $cnt$，找到出现次数最多的元素，记其出现次数为 $mx$，累加出现次数等于 $mx$ 的元素的出现次数，即为答案。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxFrequencyElements(self, nums: List[int]) -> int:
        cnt = Counter(nums)
        mx = max(cnt.values())
        return sum(x for x in cnt.values() if x == mx)
```

#### Java

```java
class Solution {
    public int maxFrequencyElements(int[] nums) {
        int[] cnt = new int[101];
        for (int x : nums) {
            ++cnt[x];
        }
        int ans = 0, mx = -1;
        for (int x : cnt) {
            if (mx < x) {
                mx = x;
                ans = x;
            } else if (mx == x) {
                ans += x;
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
    int maxFrequencyElements(vector<int>& nums) {
        int cnt[101]{};
        for (int x : nums) {
            ++cnt[x];
        }
        int ans = 0, mx = -1;
        for (int x : cnt) {
            if (mx < x) {
                mx = x;
                ans = x;
            } else if (mx == x) {
                ans += x;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func maxFrequencyElements(nums []int) (ans int) {
	cnt := [101]int{}
	for _, x := range nums {
		cnt[x]++
	}
	mx := -1
	for _, x := range cnt {
		if mx < x {
			mx, ans = x, x
		} else if mx == x {
			ans += x
		}
	}
	return
}
```

#### TypeScript

```ts
function maxFrequencyElements(nums: number[]): number {
    const cnt: number[] = Array(101).fill(0);
    for (const x of nums) {
        ++cnt[x];
    }
    let [ans, mx] = [0, -1];
    for (const x of cnt) {
        if (mx < x) {
            mx = x;
            ans = x;
        } else if (mx === x) {
            ans += x;
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn max_frequency_elements(nums: Vec<i32>) -> i32 {
        let mut cnt = [0; 101];
        for &x in &nums {
            cnt[x as usize] += 1;
        }
        let mut ans = 0;
        let mut mx = -1;
        for &x in &cnt {
            if mx < x {
                mx = x;
                ans = x;
            } else if mx == x {
                ans += x;
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

# [3006. 找出数组中的美丽下标 I](https://leetcode.cn/problems/find-beautiful-indices-in-the-given-array-i){#3006}

{{< tabs "3006" >}}

{{% tab "python" %}}
```python
class Solution:
    def beautifulIndices(self, s: str, a: str, b: str, k: int) -> List[int]:
        def build_prefix_function(pattern):
            prefix_function = [0] * len(pattern)
            j = 0
            for i in range(1, len(pattern)):
                while j > 0 and pattern[i] != pattern[j]:
                    j = prefix_function[j - 1]
                if pattern[i] == pattern[j]:
                    j += 1
                prefix_function[i] = j
            return prefix_function

        def kmp_search(pattern, text, prefix_function):
            occurrences = []
            j = 0
            for i in range(len(text)):
                while j > 0 and text[i] != pattern[j]:
                    j = prefix_function[j - 1]
                if text[i] == pattern[j]:
                    j += 1
                if j == len(pattern):
                    occurrences.append(i - j + 1)
                    j = prefix_function[j - 1]
            return occurrences

        prefix_a = build_prefix_function(a)
        prefix_b = build_prefix_function(b)

        resa = kmp_search(a, s, prefix_a)
        resb = kmp_search(b, s, prefix_b)

        res = []
        print(resa, resb)
        i = 0
        j = 0
        while i < len(resa):
            while j < len(resb):
                if abs(resb[j] - resa[i]) <= k:
                    res.append(resa[i])
                    break
                elif j + 1 < len(resb) and abs(resb[j + 1] - resa[i]) < abs(
                    resb[j] - resa[i]
                ):
                    j += 1
                else:
                    break
            i += 1
        return res
```
{{% /tab %}}
{{% tab "java" %}}
```java
public class Solution {
    public void computeLPS(String pattern, int[] lps) {
        int M = pattern.length();
        int len = 0;

        lps[0] = 0;

        int i = 1;
        while (i < M) {
            if (pattern.charAt(i) == pattern.charAt(len)) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    public List<Integer> KMP_codestorywithMIK(String pat, String txt) {
        int N = txt.length();
        int M = pat.length();
        List<Integer> result = new ArrayList<>();

        int[] lps = new int[M];
        computeLPS(pat, lps);

        int i = 0; // Index for text
        int j = 0; // Index for pattern

        while (i < N) {
            if (pat.charAt(j) == txt.charAt(i)) {
                i++;
                j++;
            }

            if (j == M) {
                result.add(i - j); // Pattern found at index i-j+1 (If you have to return 1 Based
                                   // indexing, that's why added + 1)
                j = lps[j - 1];
            } else if (i < N && pat.charAt(j) != txt.charAt(i)) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }

        return result;
    }

    private int lowerBound(List<Integer> list, int target) {
        int left = 0, right = list.size() - 1, result = list.size();

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (list.get(mid) >= target) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return result;
    }

    public List<Integer> beautifulIndices(String s, String a, String b, int k) {
        int n = s.length();

        List<Integer> i_indices = KMP_codestorywithMIK(a, s);
        List<Integer> j_indices = KMP_codestorywithMIK(b, s);

        List<Integer> result = new ArrayList<>();

        for (int i : i_indices) {

            int left_limit = Math.max(0, i - k); // To avoid out of bound -> I used max(0, i-k)
            int right_limit
                = Math.min(n - 1, i + k); // To avoid out of bound -> I used min(n-1, i+k)

            int lowerBoundIndex = lowerBound(j_indices, left_limit);

            if (lowerBoundIndex < j_indices.size()
                && j_indices.get(lowerBoundIndex) <= right_limit) {
                result.add(i);
            }
        }

        return result;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> beautifulIndices(string s, string patternA, string patternB, int k) {
        vector<int> beautifulIndicesA = kmpSearch(s, patternA);
        vector<int> beautifulIndicesB = kmpSearch(s, patternB);

        sort(beautifulIndicesB.begin(), beautifulIndicesB.end());

        vector<int> result;
        for (int indexA : beautifulIndicesA) {
            int left = lower_bound(beautifulIndicesB.begin(), beautifulIndicesB.end(), indexA - k) - beautifulIndicesB.begin();
            int right = lower_bound(beautifulIndicesB.begin(), beautifulIndicesB.end(), indexA + k + patternB.length()) - beautifulIndicesB.begin();

            left = (left >= 0) ? left : -(left + 1);
            right = (right >= 0) ? right : -(right + 1);

            for (int indexB = left; indexB < right; indexB++) {
                if (abs(beautifulIndicesB[indexB] - indexA) <= k) {
                    result.push_back(indexA);
                    break;
                }
            }
        }

        return result;
    }

private:
    vector<int> kmpSearch(string text, string pattern) {
        vector<int> indices;
        vector<int> pi = computePrefixFunction(pattern);

        int q = 0;
        for (int i = 0; i < text.length(); i++) {
            while (q > 0 && pattern[q] != text[i]) {
                q = pi[q - 1];
            }
            if (pattern[q] == text[i]) {
                q++;
            }
            if (q == pattern.length()) {
                indices.push_back(i - q + 1);
                q = pi[q - 1];
            }
        }

        return indices;
    }

    vector<int> computePrefixFunction(string pattern) {
        int m = pattern.length();
        vector<int> pi(m, 0);
        int k = 0;
        for (int q = 1; q < m; q++) {
            while (k > 0 && pattern[k] != pattern[q]) {
                k = pi[k - 1];
            }
            if (pattern[k] == pattern[q]) {
                k++;
            }
            pi[q] = k;
        }
        return pi;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func beautifulIndices(s string, a string, b string, k int) []int {

	s_len := len(s)
	a_len := len(a)
	b_len := len(b)

	final := make([]int, 0)
	lps_a := make([]int, a_len)
	lps_b := make([]int, b_len)
	a_index := make([]int, 0)
	b_index := make([]int, 0)

	var pat func(lps []int, s_l int, pattern string)

	pat = func(lps []int, s_l int, pattern string) {

		l := 0
		lps[0] = 0
		i := 1

		for i < s_l {
			if pattern[i] == pattern[l] {
				l++
				lps[i] = l
				i++
			} else {
				if l != 0 {
					l = lps[l-1]
				} else {
					lps[i] = l
					i++
				}
			}
		}
	}

	pat(lps_a, a_len, a)
	pat(lps_b, b_len, b)

	var kmp func(pat string, pat_l int, lps []int, index *[]int)

	kmp = func(pat string, pat_l int, lps []int, index *[]int) {
		i := 0
		j := 0
		for s_len-i >= pat_l-j {
			if s[i] == pat[j] {
				i++
				j++
			}
			if j == pat_l {
				*index = append(*index, i-pat_l)
				j = lps[j-1]
			} else if s[i] != pat[j] {
				if j != 0 {
					j = lps[j-1]
				} else {
					i++
				}
			}
		}
	}

	kmp(a, a_len, lps_a, &a_index)
	kmp(b, b_len, lps_b, &b_index)

	// fmt.Println(a_index, b_index)

	i := 0
	j := 0

	for i < len(a_index) && j < len(b_index) {
		if a_index[i]+k >= b_index[j] && a_index[i]-k <= b_index[j] {
			final = append(final, a_index[i])
			i++
		} else if a_index[i]-k > b_index[j] {
			j++
		} else {
			i++
		}
	}

	return final
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong> 开始的字符串 <code>s</code> 、字符串 <code>a</code> 、字符串 <code>b</code> 和一个整数 <code>k</code> 。</p>

<p>如果下标 <code>i</code> 满足以下条件，则认为它是一个 <strong>美丽下标</strong>：</p>

<ul>
	<li><code>0 &lt;= i &lt;= s.length - a.length</code></li>
	<li><code>s[i..(i + a.length - 1)] == a</code></li>
	<li>存在下标 <code>j</code> 使得：
	<ul>
		<li><code>0 &lt;= j &lt;= s.length - b.length</code></li>
		<li><code>s[j..(j + b.length - 1)] == b</code></li>
		<li><code>|j - i| &lt;= k</code></li>
	</ul>
	</li>
</ul>

<p>以数组形式按<strong> 从小到大排序 </strong>返回美丽下标。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "isawsquirrelnearmysquirrelhouseohmy", a = "my", b = "squirrel", k = 15
<strong>输出：</strong>[16,33]
<strong>解释：</strong>存在 2 个美丽下标：[16,33]。
- 下标 16 是美丽下标，因为 s[16..17] == "my" ，且存在下标 4 ，满足 s[4..11] == "squirrel" 且 |16 - 4| &lt;= 15 。
- 下标 33 是美丽下标，因为 s[33..34] == "my" ，且存在下标 18 ，满足 s[18..25] == "squirrel" 且 |33 - 18| &lt;= 15 。
因此返回 [16,33] 作为结果。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "abcd", a = "a", b = "a", k = 4
<strong>输出：</strong>[0]
<strong>解释：</strong>存在 1 个美丽下标：[0]。
- 下标 0 是美丽下标，因为 s[0..0] == "a" ，且存在下标 0 ，满足 s[0..0] == "a" 且 |0 - 0| &lt;= 4 。
因此返回 [0] 作为结果。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= a.length, b.length &lt;= 10</code></li>
	<li><code>s</code>、<code>a</code>、和 <code>b</code> 只包含小写英文字母。</li>
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
    def beautifulIndices(self, s: str, a: str, b: str, k: int) -> List[int]:
        def build_prefix_function(pattern):
            prefix_function = [0] * len(pattern)
            j = 0
            for i in range(1, len(pattern)):
                while j > 0 and pattern[i] != pattern[j]:
                    j = prefix_function[j - 1]
                if pattern[i] == pattern[j]:
                    j += 1
                prefix_function[i] = j
            return prefix_function

        def kmp_search(pattern, text, prefix_function):
            occurrences = []
            j = 0
            for i in range(len(text)):
                while j > 0 and text[i] != pattern[j]:
                    j = prefix_function[j - 1]
                if text[i] == pattern[j]:
                    j += 1
                if j == len(pattern):
                    occurrences.append(i - j + 1)
                    j = prefix_function[j - 1]
            return occurrences

        prefix_a = build_prefix_function(a)
        prefix_b = build_prefix_function(b)

        resa = kmp_search(a, s, prefix_a)
        resb = kmp_search(b, s, prefix_b)

        res = []
        print(resa, resb)
        i = 0
        j = 0
        while i < len(resa):
            while j < len(resb):
                if abs(resb[j] - resa[i]) <= k:
                    res.append(resa[i])
                    break
                elif j + 1 < len(resb) and abs(resb[j + 1] - resa[i]) < abs(
                    resb[j] - resa[i]
                ):
                    j += 1
                else:
                    break
            i += 1
        return res
```

#### Java

```java
public class Solution {
    public void computeLPS(String pattern, int[] lps) {
        int M = pattern.length();
        int len = 0;

        lps[0] = 0;

        int i = 1;
        while (i < M) {
            if (pattern.charAt(i) == pattern.charAt(len)) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    public List<Integer> KMP_codestorywithMIK(String pat, String txt) {
        int N = txt.length();
        int M = pat.length();
        List<Integer> result = new ArrayList<>();

        int[] lps = new int[M];
        computeLPS(pat, lps);

        int i = 0; // Index for text
        int j = 0; // Index for pattern

        while (i < N) {
            if (pat.charAt(j) == txt.charAt(i)) {
                i++;
                j++;
            }

            if (j == M) {
                result.add(i - j); // Pattern found at index i-j+1 (If you have to return 1 Based
                                   // indexing, that's why added + 1)
                j = lps[j - 1];
            } else if (i < N && pat.charAt(j) != txt.charAt(i)) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }

        return result;
    }

    private int lowerBound(List<Integer> list, int target) {
        int left = 0, right = list.size() - 1, result = list.size();

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (list.get(mid) >= target) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return result;
    }

    public List<Integer> beautifulIndices(String s, String a, String b, int k) {
        int n = s.length();

        List<Integer> i_indices = KMP_codestorywithMIK(a, s);
        List<Integer> j_indices = KMP_codestorywithMIK(b, s);

        List<Integer> result = new ArrayList<>();

        for (int i : i_indices) {

            int left_limit = Math.max(0, i - k); // To avoid out of bound -> I used max(0, i-k)
            int right_limit
                = Math.min(n - 1, i + k); // To avoid out of bound -> I used min(n-1, i+k)

            int lowerBoundIndex = lowerBound(j_indices, left_limit);

            if (lowerBoundIndex < j_indices.size()
                && j_indices.get(lowerBoundIndex) <= right_limit) {
                result.add(i);
            }
        }

        return result;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> beautifulIndices(string s, string patternA, string patternB, int k) {
        vector<int> beautifulIndicesA = kmpSearch(s, patternA);
        vector<int> beautifulIndicesB = kmpSearch(s, patternB);

        sort(beautifulIndicesB.begin(), beautifulIndicesB.end());

        vector<int> result;
        for (int indexA : beautifulIndicesA) {
            int left = lower_bound(beautifulIndicesB.begin(), beautifulIndicesB.end(), indexA - k) - beautifulIndicesB.begin();
            int right = lower_bound(beautifulIndicesB.begin(), beautifulIndicesB.end(), indexA + k + patternB.length()) - beautifulIndicesB.begin();

            left = (left >= 0) ? left : -(left + 1);
            right = (right >= 0) ? right : -(right + 1);

            for (int indexB = left; indexB < right; indexB++) {
                if (abs(beautifulIndicesB[indexB] - indexA) <= k) {
                    result.push_back(indexA);
                    break;
                }
            }
        }

        return result;
    }

private:
    vector<int> kmpSearch(string text, string pattern) {
        vector<int> indices;
        vector<int> pi = computePrefixFunction(pattern);

        int q = 0;
        for (int i = 0; i < text.length(); i++) {
            while (q > 0 && pattern[q] != text[i]) {
                q = pi[q - 1];
            }
            if (pattern[q] == text[i]) {
                q++;
            }
            if (q == pattern.length()) {
                indices.push_back(i - q + 1);
                q = pi[q - 1];
            }
        }

        return indices;
    }

    vector<int> computePrefixFunction(string pattern) {
        int m = pattern.length();
        vector<int> pi(m, 0);
        int k = 0;
        for (int q = 1; q < m; q++) {
            while (k > 0 && pattern[k] != pattern[q]) {
                k = pi[k - 1];
            }
            if (pattern[k] == pattern[q]) {
                k++;
            }
            pi[q] = k;
        }
        return pi;
    }
};
```

#### Go

```go
func beautifulIndices(s string, a string, b string, k int) []int {

	s_len := len(s)
	a_len := len(a)
	b_len := len(b)

	final := make([]int, 0)
	lps_a := make([]int, a_len)
	lps_b := make([]int, b_len)
	a_index := make([]int, 0)
	b_index := make([]int, 0)

	var pat func(lps []int, s_l int, pattern string)

	pat = func(lps []int, s_l int, pattern string) {

		l := 0
		lps[0] = 0
		i := 1

		for i < s_l {
			if pattern[i] == pattern[l] {
				l++
				lps[i] = l
				i++
			} else {
				if l != 0 {
					l = lps[l-1]
				} else {
					lps[i] = l
					i++
				}
			}
		}
	}

	pat(lps_a, a_len, a)
	pat(lps_b, b_len, b)

	var kmp func(pat string, pat_l int, lps []int, index *[]int)

	kmp = func(pat string, pat_l int, lps []int, index *[]int) {
		i := 0
		j := 0
		for s_len-i >= pat_l-j {
			if s[i] == pat[j] {
				i++
				j++
			}
			if j == pat_l {
				*index = append(*index, i-pat_l)
				j = lps[j-1]
			} else if s[i] != pat[j] {
				if j != 0 {
					j = lps[j-1]
				} else {
					i++
				}
			}
		}
	}

	kmp(a, a_len, lps_a, &a_index)
	kmp(b, b_len, lps_b, &b_index)

	// fmt.Println(a_index, b_index)

	i := 0
	j := 0

	for i < len(a_index) && j < len(b_index) {
		if a_index[i]+k >= b_index[j] && a_index[i]-k <= b_index[j] {
			final = append(final, a_index[i])
			i++
		} else if a_index[i]-k > b_index[j] {
			j++
		} else {
			i++
		}
	}

	return final
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3007. 价值和小于等于 K 的最大数字](https://leetcode.cn/problems/maximum-number-that-sum-of-the-prices-is-less-than-or-equal-to-k){#3007}

{{< tabs "3007" >}}

{{% tab "python" %}}
```python
class Solution:
    def findMaximumNumber(self, k: int, x: int) -> int:
        @cache
        def dfs(pos, limit, cnt):
            if pos == 0:
                return cnt
            ans = 0
            up = (self.num >> (pos - 1) & 1) if limit else 1
            for i in range(up + 1):
                ans += dfs(pos - 1, limit and i == up, cnt + (i == 1 and pos % x == 0))
            return ans

        l, r = 1, 10**18
        while l < r:
            mid = (l + r + 1) >> 1
            self.num = mid
            v = dfs(mid.bit_length(), True, 0)
            dfs.cache_clear()
            if v <= k:
                l = mid
            else:
                r = mid - 1
        return l
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int x;
    private long num;
    private Long[][] f;

    public long findMaximumNumber(long k, int x) {
        this.x = x;
        long l = 1, r = (long) 1e17;
        while (l < r) {
            long mid = (l + r + 1) >>> 1;
            num = mid;
            f = new Long[65][65];
            int pos = 64 - Long.numberOfLeadingZeros(mid);
            if (dfs(pos, 0, true) <= k) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }

    private long dfs(int pos, int cnt, boolean limit) {
        if (pos == 0) {
            return cnt;
        }
        if (!limit && f[pos][cnt] != null) {
            return f[pos][cnt];
        }
        long ans = 0;
        int up = limit ? (int) (num >> (pos - 1) & 1) : 1;
        for (int i = 0; i <= up; ++i) {
            ans += dfs(pos - 1, cnt + (i == 1 && pos % x == 0 ? 1 : 0), limit && i == up);
        }
        if (!limit) {
            f[pos][cnt] = ans;
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
    long long findMaximumNumber(long long k, int x) {
        using ll = long long;
        ll l = 1, r = 1e17;
        ll num = 0;
        ll f[65][65];
        auto dfs = [&](this auto&& dfs, int pos, int cnt, bool limit) -> ll {
            if (pos == 0) {
                return cnt;
            }
            if (!limit && f[pos][cnt] != -1) {
                return f[pos][cnt];
            }
            int up = limit ? num >> (pos - 1) & 1 : 1;
            ll ans = 0;
            for (int i = 0; i <= up; ++i) {
                ans += dfs(pos - 1, cnt + (i == 1 && pos % x == 0), limit && i == up);
            }
            if (!limit) {
                f[pos][cnt] = ans;
            }
            return ans;
        };
        while (l < r) {
            ll mid = (l + r + 1) >> 1;
            num = mid;
            memset(f, -1, sizeof(f));
            int pos = 64 - __builtin_clzll(mid);
            if (dfs(pos, 0, true) <= k) {
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
func findMaximumNumber(k int64, x int) int64 {
	var l, r int64 = 1, 1e17
	var num int64
	var f [65][65]int64
	var dfs func(pos, cnt int, limit bool) int64
	dfs = func(pos, cnt int, limit bool) int64 {
		if pos == 0 {
			return int64(cnt)
		}
		if !limit && f[pos][cnt] != -1 {
			return f[pos][cnt]
		}
		var ans int64
		up := 1
		if limit {
			up = int(num >> (pos - 1) & 1)
		}
		for i := 0; i <= up; i++ {
			v := cnt
			if i == 1 && pos%x == 0 {
				v++
			}
			ans += dfs(pos-1, v, limit && i == up)
		}
		if !limit {
			f[pos][cnt] = ans
		}
		return ans
	}
	for l < r {
		mid := (l + r + 1) >> 1
		num = mid
		m := bits.Len(uint(num))
		for i := range f {
			for j := range f[i] {
				f[i][j] = -1
			}
		}
		if dfs(m, 0, true) <= k {
			l = mid
		} else {
			r = mid - 1
		}
	}
	return l
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findMaximumNumber(k: number, x: number): number {
    let [l, r] = [1n, 10n ** 17n];
    let num: bigint;
    const f: bigint[][] = Array.from({ length: 65 }, () => Array(65).fill(-1n));

    const dfs = (pos: number, cnt: number, limit: boolean): bigint => {
        if (pos === 0) {
            return BigInt(cnt);
        }
        if (!limit && f[pos][cnt] !== -1n) {
            return f[pos][cnt];
        }
        let ans: bigint = 0n;
        let up: number = 1;
        if (limit) {
            up = Number((num >> BigInt(pos - 1)) & 1n);
        }
        for (let i = 0; i <= up; i++) {
            let v: number = cnt;
            if (i === 1 && pos % x === 0) {
                v++;
            }
            ans += dfs(pos - 1, v, limit && i === up);
        }
        if (!limit) {
            f[pos][cnt] = ans;
        }
        return ans;
    };

    while (l < r) {
        let mid: bigint = (l + r + 1n) >> 1n;
        num = mid;
        let m: number = num.toString(2).length;
        for (let i = 0; i < f.length; i++) {
            f[i].fill(-1n);
        }
        if (dfs(m, 0, true) <= BigInt(k)) {
            l = mid;
        } else {
            r = mid - 1n;
        }
    }
    return Number(l);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数&nbsp;<code>k</code>&nbsp;和一个整数&nbsp;<code>x</code>&nbsp;。整数&nbsp;<code>num</code>&nbsp;的价值是它的二进制表示中在&nbsp;<code>x</code>，<code>2x</code>，<code>3x</code>&nbsp;等位置处&nbsp;<strong><span data-keyword="set-bit">设置位</span></strong>&nbsp;的数目（从最低有效位开始）。下面的表格包含了如何计算价值的例子。</p>

<table border="1">
	<tbody>
		<tr>
			<th>x</th>
			<th>num</th>
			<th>Binary Representation</th>
			<th>Price</th>
		</tr>
		<tr>
			<td>1</td>
			<td>13</td>
			<td><u>0</u><u>0</u><u>0</u><u>0</u><u>0</u><strong><u>1</u></strong><strong><u>1</u></strong><u>0</u><strong><u>1</u></strong></td>
			<td>3</td>
		</tr>
		<tr>
			<td>2</td>
			<td>13</td>
			<td>0<u>0</u>0<u>0</u>0<strong><u>1</u></strong>1<u>0</u>1</td>
			<td>1</td>
		</tr>
		<tr>
			<td>2</td>
			<td>233</td>
			<td>0<strong><u>1</u></strong>1<strong><u>1</u></strong>0<strong><u>1</u></strong>0<u>0</u>1</td>
			<td>3</td>
		</tr>
		<tr>
			<td>3</td>
			<td>13</td>
			<td><u>0</u>00<u>0</u>01<strong><u>1</u></strong>01</td>
			<td>1</td>
		</tr>
		<tr>
			<td>3</td>
			<td>362</td>
			<td><strong><u>1</u></strong>01<strong><u>1</u></strong>01<u>0</u>10</td>
			<td>2</td>
		</tr>
	</tbody>
</table>

<p>&nbsp;</p>

<p><code>num</code>&nbsp;的 <strong>累加价值</strong> 是从&nbsp;<code>1</code>&nbsp;到&nbsp;<code>num</code>&nbsp;的数字的 <strong>总</strong> 价值。如果&nbsp;<code>num</code>&nbsp;的累加价值小于或等于&nbsp;<code>k</code>&nbsp;则被认为是 <strong>廉价</strong> 的。</p>

<p>请你返回<strong>&nbsp;最大</strong>&nbsp;的廉价数字。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>k = 9, x = 1
<b>输出：</b>6
<b>解释：</b>由下表所示，6 是最大的廉价数字。
</pre>

<table border="1">
	<tbody>
		<tr>
			<th>x</th>
			<th>num</th>
			<th>Binary Representation</th>
			<th>Price</th>
			<th>Accumulated Price</th>
		</tr>
		<tr>
			<td>1</td>
			<td>1</td>
			<td><u>0</u><u>0</u><strong><u>1</u></strong></td>
			<td>1</td>
			<td>1</td>
		</tr>
		<tr>
			<td>1</td>
			<td>2</td>
			<td><u>0</u><strong><u>1</u></strong><u>0</u></td>
			<td>1</td>
			<td>2</td>
		</tr>
		<tr>
			<td>1</td>
			<td>3</td>
			<td><u>0</u><strong><u>1</u></strong><strong><u>1</u></strong></td>
			<td>2</td>
			<td>4</td>
		</tr>
		<tr>
			<td>1</td>
			<td>4</td>
			<td><strong><u>1</u></strong><u>0</u><u>0</u></td>
			<td>1</td>
			<td>5</td>
		</tr>
		<tr>
			<td>1</td>
			<td>5</td>
			<td><strong><u>1</u></strong><u>0</u><strong><u>1</u></strong></td>
			<td>2</td>
			<td>7</td>
		</tr>
		<tr>
			<td>1</td>
			<td>6</td>
			<td><strong><u>1</u></strong><strong><u>1</u></strong><u>0</u></td>
			<td>2</td>
			<td>9</td>
		</tr>
		<tr>
			<td>1</td>
			<td>7</td>
			<td><strong><u>1</u></strong><strong><u>1</u></strong><strong><u>1</u></strong></td>
			<td>3</td>
			<td>12</td>
		</tr>
	</tbody>
</table>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>k = 7, x = 2
<b>输出：</b>9
<b>解释：</b>由下表所示，9 是最大的廉价数字。
</pre>

<table border="1">
	<tbody>
		<tr>
			<th>x</th>
			<th>num</th>
			<th>Binary Representation</th>
			<th>Price</th>
			<th>Accumulated Price</th>
		</tr>
		<tr>
			<td>2</td>
			<td>1</td>
			<td><u>0</u>0<u>0</u>1</td>
			<td>0</td>
			<td>0</td>
		</tr>
		<tr>
			<td>2</td>
			<td>2</td>
			<td><u>0</u>0<strong><u>1</u></strong>0</td>
			<td>1</td>
			<td>1</td>
		</tr>
		<tr>
			<td>2</td>
			<td>3</td>
			<td><u>0</u>0<strong><u>1</u></strong>1</td>
			<td>1</td>
			<td>2</td>
		</tr>
		<tr>
			<td>2</td>
			<td>4</td>
			<td><u>0</u>1<u>0</u>0</td>
			<td>0</td>
			<td>2</td>
		</tr>
		<tr>
			<td>2</td>
			<td>5</td>
			<td><u>0</u>1<u>0</u>1</td>
			<td>0</td>
			<td>2</td>
		</tr>
		<tr>
			<td>2</td>
			<td>6</td>
			<td><u>0</u>1<strong><u>1</u></strong>0</td>
			<td>1</td>
			<td>3</td>
		</tr>
		<tr>
			<td>2</td>
			<td>7</td>
			<td><u>0</u>1<strong><u>1</u></strong>1</td>
			<td>1</td>
			<td>4</td>
		</tr>
		<tr>
			<td>2</td>
			<td>8</td>
			<td><strong><u>1</u></strong>0<u>0</u>0</td>
			<td>1</td>
			<td>5</td>
		</tr>
		<tr>
			<td>2</td>
			<td>9</td>
			<td><strong><u>1</u></strong>0<u>0</u>1</td>
			<td>1</td>
			<td>6</td>
		</tr>
		<tr>
			<td>2</td>
			<td>10</td>
			<td><strong><u>1</u></strong>0<strong><u>1</u></strong>0</td>
			<td>2</td>
			<td>8</td>
		</tr>
	</tbody>
</table>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= 10<sup>15</sup></code></li>
	<li><code>1 &lt;= x &lt;= 8</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二分查找 + 数位 DP

我们注意到，如果 $\textit{num}$ 增大，数字 $1$ 到 $\textit{num}$ 的总价值也会增大。因此，我们可以使用二分查找的方法找到最大的廉价数字。

我们定义二分查找的左边界 $l = 1$，由于每 $2^x + 1$ 个数中至少有一个数字是有价值的，而总价值不超过 $10^15$，因此我们可以设定二分查找的右边界 $r = 10^{18}$。

接下来，我们进行二分查找，对于每一个 $\textit{mid}$，我们使用数位 DP 的方法计算出 $1$ 到 $\textit{mid}$ 的总价值，如果总价值不超过 $k$，则说明 $\textit{mid}$ 是一个廉价数字，我们将左边界 $l$ 更新为 $\textit{mid}$，否则我们将右边界 $r$ 更新为 $\textit{mid} - 1$。

最后，我们返回左边界 $l$ 即可。

时间复杂度 $O(\log^2 k)$，空间复杂度 $O(\log k)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findMaximumNumber(self, k: int, x: int) -> int:
        @cache
        def dfs(pos, limit, cnt):
            if pos == 0:
                return cnt
            ans = 0
            up = (self.num >> (pos - 1) & 1) if limit else 1
            for i in range(up + 1):
                ans += dfs(pos - 1, limit and i == up, cnt + (i == 1 and pos % x == 0))
            return ans

        l, r = 1, 10**18
        while l < r:
            mid = (l + r + 1) >> 1
            self.num = mid
            v = dfs(mid.bit_length(), True, 0)
            dfs.cache_clear()
            if v <= k:
                l = mid
            else:
                r = mid - 1
        return l
```

#### Java

```java
class Solution {
    private int x;
    private long num;
    private Long[][] f;

    public long findMaximumNumber(long k, int x) {
        this.x = x;
        long l = 1, r = (long) 1e17;
        while (l < r) {
            long mid = (l + r + 1) >>> 1;
            num = mid;
            f = new Long[65][65];
            int pos = 64 - Long.numberOfLeadingZeros(mid);
            if (dfs(pos, 0, true) <= k) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }

    private long dfs(int pos, int cnt, boolean limit) {
        if (pos == 0) {
            return cnt;
        }
        if (!limit && f[pos][cnt] != null) {
            return f[pos][cnt];
        }
        long ans = 0;
        int up = limit ? (int) (num >> (pos - 1) & 1) : 1;
        for (int i = 0; i <= up; ++i) {
            ans += dfs(pos - 1, cnt + (i == 1 && pos % x == 0 ? 1 : 0), limit && i == up);
        }
        if (!limit) {
            f[pos][cnt] = ans;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long findMaximumNumber(long long k, int x) {
        using ll = long long;
        ll l = 1, r = 1e17;
        ll num = 0;
        ll f[65][65];
        auto dfs = [&](this auto&& dfs, int pos, int cnt, bool limit) -> ll {
            if (pos == 0) {
                return cnt;
            }
            if (!limit && f[pos][cnt] != -1) {
                return f[pos][cnt];
            }
            int up = limit ? num >> (pos - 1) & 1 : 1;
            ll ans = 0;
            for (int i = 0; i <= up; ++i) {
                ans += dfs(pos - 1, cnt + (i == 1 && pos % x == 0), limit && i == up);
            }
            if (!limit) {
                f[pos][cnt] = ans;
            }
            return ans;
        };
        while (l < r) {
            ll mid = (l + r + 1) >> 1;
            num = mid;
            memset(f, -1, sizeof(f));
            int pos = 64 - __builtin_clzll(mid);
            if (dfs(pos, 0, true) <= k) {
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
func findMaximumNumber(k int64, x int) int64 {
	var l, r int64 = 1, 1e17
	var num int64
	var f [65][65]int64
	var dfs func(pos, cnt int, limit bool) int64
	dfs = func(pos, cnt int, limit bool) int64 {
		if pos == 0 {
			return int64(cnt)
		}
		if !limit && f[pos][cnt] != -1 {
			return f[pos][cnt]
		}
		var ans int64
		up := 1
		if limit {
			up = int(num >> (pos - 1) & 1)
		}
		for i := 0; i <= up; i++ {
			v := cnt
			if i == 1 && pos%x == 0 {
				v++
			}
			ans += dfs(pos-1, v, limit && i == up)
		}
		if !limit {
			f[pos][cnt] = ans
		}
		return ans
	}
	for l < r {
		mid := (l + r + 1) >> 1
		num = mid
		m := bits.Len(uint(num))
		for i := range f {
			for j := range f[i] {
				f[i][j] = -1
			}
		}
		if dfs(m, 0, true) <= k {
			l = mid
		} else {
			r = mid - 1
		}
	}
	return l
}
```

#### TypeScript

```ts
function findMaximumNumber(k: number, x: number): number {
    let [l, r] = [1n, 10n ** 17n];
    let num: bigint;
    const f: bigint[][] = Array.from({ length: 65 }, () => Array(65).fill(-1n));

    const dfs = (pos: number, cnt: number, limit: boolean): bigint => {
        if (pos === 0) {
            return BigInt(cnt);
        }
        if (!limit && f[pos][cnt] !== -1n) {
            return f[pos][cnt];
        }
        let ans: bigint = 0n;
        let up: number = 1;
        if (limit) {
            up = Number((num >> BigInt(pos - 1)) & 1n);
        }
        for (let i = 0; i <= up; i++) {
            let v: number = cnt;
            if (i === 1 && pos % x === 0) {
                v++;
            }
            ans += dfs(pos - 1, v, limit && i === up);
        }
        if (!limit) {
            f[pos][cnt] = ans;
        }
        return ans;
    };

    while (l < r) {
        let mid: bigint = (l + r + 1n) >> 1n;
        num = mid;
        let m: number = num.toString(2).length;
        for (let i = 0; i < f.length; i++) {
            f[i].fill(-1n);
        }
        if (dfs(m, 0, true) <= BigInt(k)) {
            l = mid;
        } else {
            r = mid - 1n;
        }
    }
    return Number(l);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3008. 找出数组中的美丽下标 II](https://leetcode.cn/problems/find-beautiful-indices-in-the-given-array-ii){#3008}

{{< tabs "3008" >}}

{{% tab "python" %}}
```python
class Solution:
    def beautifulIndices(self, s: str, a: str, b: str, k: int) -> List[int]:
        def build_prefix_function(pattern):
            prefix_function = [0] * len(pattern)
            j = 0
            for i in range(1, len(pattern)):
                while j > 0 and pattern[i] != pattern[j]:
                    j = prefix_function[j - 1]
                if pattern[i] == pattern[j]:
                    j += 1
                prefix_function[i] = j
            return prefix_function

        def kmp_search(pattern, text, prefix_function):
            occurrences = []
            j = 0
            for i in range(len(text)):
                while j > 0 and text[i] != pattern[j]:
                    j = prefix_function[j - 1]
                if text[i] == pattern[j]:
                    j += 1
                if j == len(pattern):
                    occurrences.append(i - j + 1)
                    j = prefix_function[j - 1]
            return occurrences

        prefix_a = build_prefix_function(a)
        prefix_b = build_prefix_function(b)

        resa = kmp_search(a, s, prefix_a)
        resb = kmp_search(b, s, prefix_b)

        res = []
        print(resa, resb)
        i = 0
        j = 0
        while i < len(resa):
            while j < len(resb):
                if abs(resb[j] - resa[i]) <= k:
                    res.append(resa[i])
                    break
                elif j + 1 < len(resb) and abs(resb[j + 1] - resa[i]) < abs(
                    resb[j] - resa[i]
                ):
                    j += 1
                else:
                    break
            i += 1
        return res
```
{{% /tab %}}
{{% tab "java" %}}
```java
public class Solution {
    public void computeLPS(String pattern, int[] lps) {
        int M = pattern.length();
        int len = 0;

        lps[0] = 0;

        int i = 1;
        while (i < M) {
            if (pattern.charAt(i) == pattern.charAt(len)) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    public List<Integer> KMP_codestorywithMIK(String pat, String txt) {
        int N = txt.length();
        int M = pat.length();
        List<Integer> result = new ArrayList<>();

        int[] lps = new int[M];
        computeLPS(pat, lps);

        int i = 0; // Index for text
        int j = 0; // Index for pattern

        while (i < N) {
            if (pat.charAt(j) == txt.charAt(i)) {
                i++;
                j++;
            }

            if (j == M) {
                result.add(i - j); // Pattern found at index i-j+1 (If you have to return 1 Based
                                   // indexing, that's why added + 1)
                j = lps[j - 1];
            } else if (i < N && pat.charAt(j) != txt.charAt(i)) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }

        return result;
    }

    private int lowerBound(List<Integer> list, int target) {
        int left = 0, right = list.size() - 1, result = list.size();

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (list.get(mid) >= target) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return result;
    }

    public List<Integer> beautifulIndices(String s, String a, String b, int k) {
        int n = s.length();

        List<Integer> i_indices = KMP_codestorywithMIK(a, s);
        List<Integer> j_indices = KMP_codestorywithMIK(b, s);

        List<Integer> result = new ArrayList<>();

        for (int i : i_indices) {

            int left_limit = Math.max(0, i - k); // To avoid out of bound -> I used max(0, i-k)
            int right_limit
                = Math.min(n - 1, i + k); // To avoid out of bound -> I used min(n-1, i+k)

            int lowerBoundIndex = lowerBound(j_indices, left_limit);

            if (lowerBoundIndex < j_indices.size()
                && j_indices.get(lowerBoundIndex) <= right_limit) {
                result.add(i);
            }
        }

        return result;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> beautifulIndices(string s, string patternA, string patternB, int k) {
        vector<int> beautifulIndicesA = kmpSearch(s, patternA);
        vector<int> beautifulIndicesB = kmpSearch(s, patternB);

        sort(beautifulIndicesB.begin(), beautifulIndicesB.end());

        vector<int> result;
        for (int indexA : beautifulIndicesA) {
            int left = lower_bound(beautifulIndicesB.begin(), beautifulIndicesB.end(), indexA - k) - beautifulIndicesB.begin();
            int right = lower_bound(beautifulIndicesB.begin(), beautifulIndicesB.end(), indexA + k + patternB.length()) - beautifulIndicesB.begin();

            left = (left >= 0) ? left : -(left + 1);
            right = (right >= 0) ? right : -(right + 1);

            for (int indexB = left; indexB < right; indexB++) {
                if (abs(beautifulIndicesB[indexB] - indexA) <= k) {
                    result.push_back(indexA);
                    break;
                }
            }
        }

        return result;
    }

private:
    vector<int> kmpSearch(string text, string pattern) {
        vector<int> indices;
        vector<int> pi = computePrefixFunction(pattern);

        int q = 0;
        for (int i = 0; i < text.length(); i++) {
            while (q > 0 && pattern[q] != text[i]) {
                q = pi[q - 1];
            }
            if (pattern[q] == text[i]) {
                q++;
            }
            if (q == pattern.length()) {
                indices.push_back(i - q + 1);
                q = pi[q - 1];
            }
        }

        return indices;
    }

    vector<int> computePrefixFunction(string pattern) {
        int m = pattern.length();
        vector<int> pi(m, 0);
        int k = 0;
        for (int q = 1; q < m; q++) {
            while (k > 0 && pattern[k] != pattern[q]) {
                k = pi[k - 1];
            }
            if (pattern[k] == pattern[q]) {
                k++;
            }
            pi[q] = k;
        }
        return pi;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func beautifulIndices(s string, a string, b string, k int) []int {

	s_len := len(s)
	a_len := len(a)
	b_len := len(b)

	final := make([]int, 0)
	lps_a := make([]int, a_len)
	lps_b := make([]int, b_len)
	a_index := make([]int, 0)
	b_index := make([]int, 0)

	var pat func(lps []int, s_l int, pattern string)

	pat = func(lps []int, s_l int, pattern string) {

		l := 0
		lps[0] = 0
		i := 1

		for i < s_l {
			if pattern[i] == pattern[l] {
				l++
				lps[i] = l
				i++
			} else {
				if l != 0 {
					l = lps[l-1]
				} else {
					lps[i] = l
					i++
				}
			}
		}
	}

	pat(lps_a, a_len, a)
	pat(lps_b, b_len, b)

	var kmp func(pat string, pat_l int, lps []int, index *[]int)

	kmp = func(pat string, pat_l int, lps []int, index *[]int) {
		i := 0
		j := 0
		for s_len-i >= pat_l-j {
			if s[i] == pat[j] {
				i++
				j++
			}
			if j == pat_l {
				*index = append(*index, i-pat_l)
				j = lps[j-1]
			} else if s[i] != pat[j] {
				if j != 0 {
					j = lps[j-1]
				} else {
					i++
				}
			}
		}
	}

	kmp(a, a_len, lps_a, &a_index)
	kmp(b, b_len, lps_b, &b_index)

	// fmt.Println(a_index, b_index)

	i := 0
	j := 0

	for i < len(a_index) && j < len(b_index) {
		if a_index[i]+k >= b_index[j] && a_index[i]-k <= b_index[j] {
			final = append(final, a_index[i])
			i++
		} else if a_index[i]-k > b_index[j] {
			j++
		} else {
			i++
		}
	}

	return final
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的字符串&nbsp;<code>s</code>&nbsp;、字符串&nbsp;<code>a</code>&nbsp;、字符串&nbsp;<code>b</code>&nbsp;和一个整数&nbsp;<code>k</code>&nbsp;。</p>

<p>如果下标 <code>i</code>&nbsp;满足以下条件，则认为它是一个 <strong>美丽下标</strong>&nbsp;：</p>

<ul>
	<li><code>0 &lt;= i &lt;= s.length - a.length</code></li>
	<li><code>s[i..(i + a.length - 1)] == a</code></li>
	<li>存在下标&nbsp;<code>j</code>&nbsp;使得：
	<ul>
		<li><code>0 &lt;= j &lt;= s.length - b.length</code></li>
		<li><code>s[j..(j + b.length - 1)] == b</code></li>
		<li><code>|j - i| &lt;= k</code></li>
	</ul>
	</li>
</ul>

<p>以数组形式按<strong>&nbsp;从小到大排序&nbsp;</strong>返回美丽下标。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "isawsquirrelnearmysquirrelhouseohmy", a = "my", b = "squirrel", k = 15
<strong>输出：</strong>[16,33]
<strong>解释：</strong>存在 2 个美丽下标：[16,33]。
- 下标 16 是美丽下标，因为 s[16..17] == "my" ，且存在下标 4 ，满足 s[4..11] == "squirrel" 且 |16 - 4| &lt;= 15 。
- 下标 33 是美丽下标，因为 s[33..34] == "my" ，且存在下标 18 ，满足 s[18..25] == "squirrel" 且 |33 - 18| &lt;= 15 。
因此返回 [16,33] 作为结果。</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>s = "abcd", a = "a", b = "a", k = 4
<b>输出：</b>[0]
<strong>解释：</strong>存在 1 个美丽下标：[0]。
- 下标 0 是美丽下标，因为 s[0..0] == "a" ，且存在下标 0 ，满足 s[0..0] == "a" 且 |0 - 0| &lt;= 4 。
因此返回 [0] 作为结果。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= s.length &lt;= 5 * 10<sup>5</sup></code></li>
	<li><code>1 &lt;= a.length, b.length &lt;= 5 * 10<sup>5</sup></code></li>
	<li><code>s</code>、<code>a</code>、和&nbsp;<code>b</code>&nbsp;只包含小写英文字母。</li>
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
    def beautifulIndices(self, s: str, a: str, b: str, k: int) -> List[int]:
        def build_prefix_function(pattern):
            prefix_function = [0] * len(pattern)
            j = 0
            for i in range(1, len(pattern)):
                while j > 0 and pattern[i] != pattern[j]:
                    j = prefix_function[j - 1]
                if pattern[i] == pattern[j]:
                    j += 1
                prefix_function[i] = j
            return prefix_function

        def kmp_search(pattern, text, prefix_function):
            occurrences = []
            j = 0
            for i in range(len(text)):
                while j > 0 and text[i] != pattern[j]:
                    j = prefix_function[j - 1]
                if text[i] == pattern[j]:
                    j += 1
                if j == len(pattern):
                    occurrences.append(i - j + 1)
                    j = prefix_function[j - 1]
            return occurrences

        prefix_a = build_prefix_function(a)
        prefix_b = build_prefix_function(b)

        resa = kmp_search(a, s, prefix_a)
        resb = kmp_search(b, s, prefix_b)

        res = []
        print(resa, resb)
        i = 0
        j = 0
        while i < len(resa):
            while j < len(resb):
                if abs(resb[j] - resa[i]) <= k:
                    res.append(resa[i])
                    break
                elif j + 1 < len(resb) and abs(resb[j + 1] - resa[i]) < abs(
                    resb[j] - resa[i]
                ):
                    j += 1
                else:
                    break
            i += 1
        return res
```

#### Java

```java
public class Solution {
    public void computeLPS(String pattern, int[] lps) {
        int M = pattern.length();
        int len = 0;

        lps[0] = 0;

        int i = 1;
        while (i < M) {
            if (pattern.charAt(i) == pattern.charAt(len)) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    public List<Integer> KMP_codestorywithMIK(String pat, String txt) {
        int N = txt.length();
        int M = pat.length();
        List<Integer> result = new ArrayList<>();

        int[] lps = new int[M];
        computeLPS(pat, lps);

        int i = 0; // Index for text
        int j = 0; // Index for pattern

        while (i < N) {
            if (pat.charAt(j) == txt.charAt(i)) {
                i++;
                j++;
            }

            if (j == M) {
                result.add(i - j); // Pattern found at index i-j+1 (If you have to return 1 Based
                                   // indexing, that's why added + 1)
                j = lps[j - 1];
            } else if (i < N && pat.charAt(j) != txt.charAt(i)) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }

        return result;
    }

    private int lowerBound(List<Integer> list, int target) {
        int left = 0, right = list.size() - 1, result = list.size();

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (list.get(mid) >= target) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return result;
    }

    public List<Integer> beautifulIndices(String s, String a, String b, int k) {
        int n = s.length();

        List<Integer> i_indices = KMP_codestorywithMIK(a, s);
        List<Integer> j_indices = KMP_codestorywithMIK(b, s);

        List<Integer> result = new ArrayList<>();

        for (int i : i_indices) {

            int left_limit = Math.max(0, i - k); // To avoid out of bound -> I used max(0, i-k)
            int right_limit
                = Math.min(n - 1, i + k); // To avoid out of bound -> I used min(n-1, i+k)

            int lowerBoundIndex = lowerBound(j_indices, left_limit);

            if (lowerBoundIndex < j_indices.size()
                && j_indices.get(lowerBoundIndex) <= right_limit) {
                result.add(i);
            }
        }

        return result;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> beautifulIndices(string s, string patternA, string patternB, int k) {
        vector<int> beautifulIndicesA = kmpSearch(s, patternA);
        vector<int> beautifulIndicesB = kmpSearch(s, patternB);

        sort(beautifulIndicesB.begin(), beautifulIndicesB.end());

        vector<int> result;
        for (int indexA : beautifulIndicesA) {
            int left = lower_bound(beautifulIndicesB.begin(), beautifulIndicesB.end(), indexA - k) - beautifulIndicesB.begin();
            int right = lower_bound(beautifulIndicesB.begin(), beautifulIndicesB.end(), indexA + k + patternB.length()) - beautifulIndicesB.begin();

            left = (left >= 0) ? left : -(left + 1);
            right = (right >= 0) ? right : -(right + 1);

            for (int indexB = left; indexB < right; indexB++) {
                if (abs(beautifulIndicesB[indexB] - indexA) <= k) {
                    result.push_back(indexA);
                    break;
                }
            }
        }

        return result;
    }

private:
    vector<int> kmpSearch(string text, string pattern) {
        vector<int> indices;
        vector<int> pi = computePrefixFunction(pattern);

        int q = 0;
        for (int i = 0; i < text.length(); i++) {
            while (q > 0 && pattern[q] != text[i]) {
                q = pi[q - 1];
            }
            if (pattern[q] == text[i]) {
                q++;
            }
            if (q == pattern.length()) {
                indices.push_back(i - q + 1);
                q = pi[q - 1];
            }
        }

        return indices;
    }

    vector<int> computePrefixFunction(string pattern) {
        int m = pattern.length();
        vector<int> pi(m, 0);
        int k = 0;
        for (int q = 1; q < m; q++) {
            while (k > 0 && pattern[k] != pattern[q]) {
                k = pi[k - 1];
            }
            if (pattern[k] == pattern[q]) {
                k++;
            }
            pi[q] = k;
        }
        return pi;
    }
};
```

#### Go

```go
func beautifulIndices(s string, a string, b string, k int) []int {

	s_len := len(s)
	a_len := len(a)
	b_len := len(b)

	final := make([]int, 0)
	lps_a := make([]int, a_len)
	lps_b := make([]int, b_len)
	a_index := make([]int, 0)
	b_index := make([]int, 0)

	var pat func(lps []int, s_l int, pattern string)

	pat = func(lps []int, s_l int, pattern string) {

		l := 0
		lps[0] = 0
		i := 1

		for i < s_l {
			if pattern[i] == pattern[l] {
				l++
				lps[i] = l
				i++
			} else {
				if l != 0 {
					l = lps[l-1]
				} else {
					lps[i] = l
					i++
				}
			}
		}
	}

	pat(lps_a, a_len, a)
	pat(lps_b, b_len, b)

	var kmp func(pat string, pat_l int, lps []int, index *[]int)

	kmp = func(pat string, pat_l int, lps []int, index *[]int) {
		i := 0
		j := 0
		for s_len-i >= pat_l-j {
			if s[i] == pat[j] {
				i++
				j++
			}
			if j == pat_l {
				*index = append(*index, i-pat_l)
				j = lps[j-1]
			} else if s[i] != pat[j] {
				if j != 0 {
					j = lps[j-1]
				} else {
					i++
				}
			}
		}
	}

	kmp(a, a_len, lps_a, &a_index)
	kmp(b, b_len, lps_b, &b_index)

	// fmt.Println(a_index, b_index)

	i := 0
	j := 0

	for i < len(a_index) && j < len(b_index) {
		if a_index[i]+k >= b_index[j] && a_index[i]-k <= b_index[j] {
			final = append(final, a_index[i])
			i++
		} else if a_index[i]-k > b_index[j] {
			j++
		} else {
			i++
		}
	}

	return final
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3009. 折线图上的最大交点数量 🔒](https://leetcode.cn/problems/maximum-number-of-intersections-on-the-chart){#3009}

{{< tabs "3009" >}}

{{% tab "python" %}}
```python

```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxIntersectionCount(int[] y) {
        final int n = y.length;
        int ans = 0;
        int intersectionCount = 0;
        TreeMap<Integer, Integer> line = new TreeMap<>();

        for (int i = 1; i < n; ++i) {
            final int start = 2 * y[i - 1];
            final int end = 2 * y[i] + (i == n - 1 ? 0 : y[i] > y[i - 1] ? -1 : 1);
            line.merge(Math.min(start, end), 1, Integer::sum);
            line.merge(Math.max(start, end) + 1, -1, Integer::sum);
        }

        for (final int count : line.values()) {
            intersectionCount += count;
            ans = Math.max(ans, intersectionCount);
        }

        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp

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

<p>有一条由 <code>n</code> 个点连接而成的折线图。给定一个 <strong>下标从 1 开始&nbsp;</strong>的整数数组 <code>y</code>，第&nbsp;<code>k</code>&nbsp;个点的坐标是 <code>(k, y[k])</code>。图中没有水平线，即没有两个相邻的点有相同的 y 坐标。</p>

<p>假设在图中任意画一条无限长的水平线。请返回这条水平线与折线相交的最多交点数。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>
<strong><a href="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3000-3099/3009.Maximum%20Number%20of%20Intersections%20on%20the%20Chart/images/20231208-020549.jpeg"><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3000-3099/3009.Maximum%20Number%20of%20Intersections%20on%20the%20Chart/images/20231208-020549.jpeg" style="padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem; height: 217px; width: 600px;" /></a></strong>

<pre>
<b>输入：</b>y = [1,2,1,2,1,3,2]
<b>输出：</b>5
<b>解释：</b>如上图所示，水平线 y = 1.5 与折线相交了 5 次（用红叉表示）。水平线 y = 2 与折线相交了 4 次（用红叉表示）。可以证明没有其他水平线可以与折线有超过 5 个点相交。因此，答案是 5。
</pre>

<p><strong class="example">示例 2：</strong></p>
<strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3000-3099/3009.Maximum%20Number%20of%20Intersections%20on%20the%20Chart/images/20231208-020557.jpeg" style="padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem; width: 400px; height: 404px;" /></strong>

<pre>
<b>输入：</b>y = [2,1,3,4,5]
<b>输出：</b>2
<b>解释：</b>如上图所示，水平线 y=1.5 与折线相交了 2 次（用红叉表示）。水平线 y=2 与折线相交了 2 次（用红叉表示）。可以证明没有其他水平线可以与折线有超过 2 个点相交。因此，答案是 2。
</pre>

<p>&nbsp;</p>

<p><b>提示：</b></p>

<ul>
	<li><code>2 &lt;= y.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= y[i] &lt;= 10<sup>9</sup></code></li>
	<li>对于范围&nbsp;<code>[1, n - 1]</code> 内的所有&nbsp;<code>i</code>，都有 <code>y[i] != y[i + 1]</code></li>
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

```

#### Java

```java
class Solution {
    public int maxIntersectionCount(int[] y) {
        final int n = y.length;
        int ans = 0;
        int intersectionCount = 0;
        TreeMap<Integer, Integer> line = new TreeMap<>();

        for (int i = 1; i < n; ++i) {
            final int start = 2 * y[i - 1];
            final int end = 2 * y[i] + (i == n - 1 ? 0 : y[i] > y[i - 1] ? -1 : 1);
            line.merge(Math.min(start, end), 1, Integer::sum);
            line.merge(Math.max(start, end) + 1, -1, Integer::sum);
        }

        for (final int count : line.values()) {
            intersectionCount += count;
            ans = Math.max(ans, intersectionCount);
        }

        return ans;
    }
}
```

#### C++

```cpp

```

#### Go

```go

```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
