---
title: "3110_字符串的分数"
date: 2025-10-08T18:40:09+08:00
weight: 2
tags: [二分查找, 位运算, 动态规划, 单调栈, 图, 堆（优先队列）, 字符串, 排序, 数学, 数据库, 数组, 数论, 最短路, 枚举, 栈, 线段树, 组合数学, 贪心, 队列]
---

{{< markmap >}}
### [3110_字符串的分数](#3110)
#### [字符串](#3110)
### [3111_覆盖所有点的最少矩形数目](#3111)
#### [贪心](#3111)
#### [数组](#3111)
#### [排序](#3111)
### [3112_访问消失节点的最少时间](#3112)
#### [图](#3112)
#### [数组](#3112)
#### [最短路](#3112)
#### [堆（优先队列）](#3112)
### [3113_边界元素是最大值的子数组数目](#3113)
#### [栈](#3113)
#### [数组](#3113)
#### [二分查找](#3113)
#### [单调栈](#3113)
### [3114_替换字符可以得到的最晚时间](#3114)
#### [字符串](#3114)
#### [枚举](#3114)
### [3115_质数的最大距离](#3115)
#### [数组](#3115)
#### [数学](#3115)
#### [数论](#3115)
### [3116_单面值组合的第 K 小金额](#3116)
#### [位运算](#3116)
#### [数组](#3116)
#### [数学](#3116)
#### [二分查找](#3116)
#### [组合数学](#3116)
#### [数论](#3116)
### [3117_划分数组得到最小的值之和](#3117)
#### [位运算](#3117)
#### [线段树](#3117)
#### [队列](#3117)
#### [数组](#3117)
#### [二分查找](#3117)
#### [动态规划](#3117)
### [3118_发生在周五的交易 III 🔒](#3118)
#### [数据库](#3118)
### [3119_最大数量的可修复坑洼 🔒](#3119)
#### [贪心](#3119)
#### [字符串](#3119)
#### [排序](#3119)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 3110_字符串的分数
___
#### 字符串
---
### 3111_覆盖所有点的最少矩形数目
___
#### 贪心
___
#### 数组
___
#### 排序
---
### 3112_访问消失节点的最少时间
___
#### 图
___
#### 数组
___
#### 最短路
___
#### 堆（优先队列）
---
### 3113_边界元素是最大值的子数组数目
___
#### 栈
___
#### 数组
___
#### 二分查找
___
#### 单调栈
---
### 3114_替换字符可以得到的最晚时间
___
#### 字符串
___
#### 枚举
---
### 3115_质数的最大距离
___
#### 数组
___
#### 数学
___
#### 数论
---
### 3116_单面值组合的第 K 小金额
___
#### 位运算
___
#### 数组
___
#### 数学
___
#### 二分查找
___
#### 组合数学
___
#### 数论
---
### 3117_划分数组得到最小的值之和
___
#### 位运算
___
#### 线段树
___
#### 队列
___
#### 数组
___
#### 二分查找
___
#### 动态规划
---
### 3118_发生在周五的交易 III 🔒
___
#### 数据库
---
### 3119_最大数量的可修复坑洼 🔒
___
#### 贪心
___
#### 字符串
___
#### 排序
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 位运算 | 动态规划 |
| 单调栈 | 图 | 堆（优先队列） |
| 字符串 | 排序 | 数学 |
| 数据库 | 数组 | 数论 |
| 最短路 | 枚举 | 栈 |
| 线段树 | 组合数学 | 贪心 |
| 队列 |  |  |

# [3110. 字符串的分数](https://leetcode.cn/problems/score-of-a-string){#3110}

{{< tabs "3110" >}}

{{% tab "python" %}}
```python
class Solution:
    def scoreOfString(self, s: str) -> int:
        return sum(abs(a - b) for a, b in pairwise(map(ord, s)))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int scoreOfString(String s) {
        int ans = 0;
        for (int i = 1; i < s.length(); ++i) {
            ans += Math.abs(s.charAt(i - 1) - s.charAt(i));
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
    int scoreOfString(string s) {
        int ans = 0;
        for (int i = 1; i < s.size(); ++i) {
            ans += abs(s[i] - s[i - 1]);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func scoreOfString(s string) (ans int) {
	for i := 1; i < len(s); i++ {
		ans += abs(int(s[i-1]) - int(s[i]))
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
{{% tab "ts" %}}
```ts
function scoreOfString(s: string): number {
    let ans = 0;
    for (let i = 1; i < s.length; ++i) {
        ans += Math.abs(s.charCodeAt(i) - s.charCodeAt(i - 1));
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn score_of_string(s: String) -> i32 {
        s.as_bytes()
            .windows(2)
            .map(|w| (w[0] as i32 - w[1] as i32).abs())
            .sum()
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int ScoreOfString(string s) {
        int ans = 0;
        for (int i = 1; i < s.Length; ++i) {
            ans += Math.Abs(s[i] - s[i - 1]);
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param String $s
     * @return Integer
     */
    function scoreOfString($s) {
        $ans = 0;
        $n = strlen($s);
        for ($i = 1; $i < $n; ++$i) {
            $ans += abs(ord($s[$i]) - ord($s[$i - 1]));
        }
        return $ans;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串&nbsp;<code>s</code>&nbsp;。一个字符串的&nbsp;<strong>分数</strong>&nbsp;定义为相邻字符 <strong>ASCII</strong>&nbsp;码差值绝对值的和。</p>

<p>请你返回 <code>s</code>&nbsp;的 <strong>分数</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>s = "hello"</span></p>

<p><span class="example-io"><b>输出：</b>13</span></p>

<p><strong>解释：</strong></p>

<p><code>s</code>&nbsp;中字符的 <strong>ASCII </strong>码分别为：<code>'h' = 104</code>&nbsp;，<code>'e' = 101</code>&nbsp;，<code>'l' = 108</code>&nbsp;，<code>'o' = 111</code>&nbsp;。所以&nbsp;<code>s</code>&nbsp;的分数为&nbsp;<code>|104 - 101| + |101 - 108| + |108 - 108| + |108 - 111| = 3 + 7 + 0 + 3 = 13</code>&nbsp;。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>s = "zaz"</span></p>

<p><span class="example-io"><b>输出：</b>50</span></p>

<p><strong>解释：</strong></p>

<p><code>s</code>&nbsp;中字符的 <strong>ASCII&nbsp;</strong>码分别为：<code>'z' = 122</code>&nbsp;，<code>'a' = 97</code>&nbsp;。所以&nbsp;<code>s</code>&nbsp;的分数为&nbsp;<code>|122 - 97| + |97 - 122| = 25 + 25 = 50</code>&nbsp;。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= s.length &lt;= 100</code></li>
	<li><code>s</code>&nbsp;只包含小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们直接遍历字符串 $s$，计算相邻字符的 ASCII 码差值的绝对值之和即可。

时间复杂度 $O(n)$，其中 $n$ 是字符串 $s$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def scoreOfString(self, s: str) -> int:
        return sum(abs(a - b) for a, b in pairwise(map(ord, s)))
```

#### Java

```java
class Solution {
    public int scoreOfString(String s) {
        int ans = 0;
        for (int i = 1; i < s.length(); ++i) {
            ans += Math.abs(s.charAt(i - 1) - s.charAt(i));
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int scoreOfString(string s) {
        int ans = 0;
        for (int i = 1; i < s.size(); ++i) {
            ans += abs(s[i] - s[i - 1]);
        }
        return ans;
    }
};
```

#### Go

```go
func scoreOfString(s string) (ans int) {
	for i := 1; i < len(s); i++ {
		ans += abs(int(s[i-1]) - int(s[i]))
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

#### TypeScript

```ts
function scoreOfString(s: string): number {
    let ans = 0;
    for (let i = 1; i < s.length; ++i) {
        ans += Math.abs(s.charCodeAt(i) - s.charCodeAt(i - 1));
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn score_of_string(s: String) -> i32 {
        s.as_bytes()
            .windows(2)
            .map(|w| (w[0] as i32 - w[1] as i32).abs())
            .sum()
    }
}
```

#### C#

```cs
public class Solution {
    public int ScoreOfString(string s) {
        int ans = 0;
        for (int i = 1; i < s.Length; ++i) {
            ans += Math.Abs(s[i] - s[i - 1]);
        }
        return ans;
    }
}
```

#### PHP

```php
class Solution {
    /**
     * @param String $s
     * @return Integer
     */
    function scoreOfString($s) {
        $ans = 0;
        $n = strlen($s);
        for ($i = 1; $i < $n; ++$i) {
            $ans += abs(ord($s[$i]) - ord($s[$i - 1]));
        }
        return $ans;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3111. 覆盖所有点的最少矩形数目](https://leetcode.cn/problems/minimum-rectangles-to-cover-points){#3111}

{{< tabs "3111" >}}

{{% tab "python" %}}
```python
class Solution:
    def minRectanglesToCoverPoints(self, points: List[List[int]], w: int) -> int:
        points.sort()
        ans, x1 = 0, -1
        for x, _ in points:
            if x > x1:
                ans += 1
                x1 = x + w
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minRectanglesToCoverPoints(int[][] points, int w) {
        Arrays.sort(points, (a, b) -> a[0] - b[0]);
        int ans = 0, x1 = -1;
        for (int[] p : points) {
            int x = p[0];
            if (x > x1) {
                ++ans;
                x1 = x + w;
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
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        sort(points.begin(), points.end());
        int ans = 0, x1 = -1;
        for (const auto& p : points) {
            int x = p[0];
            if (x > x1) {
                ++ans;
                x1 = x + w;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minRectanglesToCoverPoints(points [][]int, w int) (ans int) {
	sort.Slice(points, func(i, j int) bool { return points[i][0] < points[j][0] })
	x1 := -1
	for _, p := range points {
		if x := p[0]; x > x1 {
			ans++
			x1 = x + w
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minRectanglesToCoverPoints(points: number[][], w: number): number {
    points.sort((a, b) => a[0] - b[0]);
    let [ans, x1] = [0, -1];
    for (const [x, _] of points) {
        if (x > x1) {
            ++ans;
            x1 = x + w;
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn min_rectangles_to_cover_points(mut points: Vec<Vec<i32>>, w: i32) -> i32 {
        points.sort_by(|a, b| a[0].cmp(&b[0]));
        let mut ans = 0;
        let mut x1 = -1;
        for p in points {
            let x = p[0];
            if x > x1 {
                ans += 1;
                x1 = x + w;
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
    public int MinRectanglesToCoverPoints(int[][] points, int w) {
        Array.Sort(points, (a, b) => a[0] - b[0]);
        int ans = 0, x1 = -1;
        foreach (int[] p in points) {
            int x = p[0];
            if (x > x1) {
                ans++;
                x1 = x + w;
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

<p>给你一个二维整数数组&nbsp;<code>point</code>&nbsp;，其中&nbsp;<code>points[i] = [x<sub>i</sub>, y<sub>i</sub>]</code>&nbsp;表示二维平面内的一个点。同时给你一个整数&nbsp;<code>w</code>&nbsp;。你需要用矩形&nbsp;<strong>覆盖所有</strong>&nbsp;点。</p>

<p>每个矩形的左下角在某个点&nbsp;<code>(x<sub>1</sub>, 0)</code>&nbsp;处，且右上角在某个点&nbsp;<code>(x<sub>2</sub>, y<sub>2</sub>)</code>&nbsp;处，其中&nbsp;<code>x<sub>1</sub> &lt;= x<sub>2</sub></code>&nbsp;且&nbsp;<code>y<sub>2</sub> &gt;= 0</code>&nbsp;，同时对于每个矩形都&nbsp;<strong>必须</strong>&nbsp;满足&nbsp;<code>x<sub>2</sub> - x<sub>1</sub> &lt;= w</code>&nbsp;。</p>

<p>如果一个点在矩形内或者在边上，我们说这个点被矩形覆盖了。</p>

<p>请你在确保每个点都 <strong>至少</strong>&nbsp;被一个矩形覆盖的前提下，<strong>最少</strong>&nbsp;需要多少个矩形。</p>

<p><strong>注意：</strong>一个点可以被多个矩形覆盖。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3100-3199/3111.Minimum%20Rectangles%20to%20Cover%20Points/images/screenshot-from-2024-03-04-20-33-05.png" style="width: 205px; height: 300px;" /></p>

<div class="example-block" style="border-color: var(--border-tertiary); border-left-width: 2px; color: var(--text-secondary); margin-bottom: 1rem; margin-top: 1rem; overflow: visible; padding-left: 1rem;">
<p style=""><span class="example-io" style="font-size: 8.75px;"><b>输入：</b></span><span class="example-io" style="font-size: 0.85rem; font-family: Menlo, sans-serif;">points = [[2,1],[1,0],[1,4],[1,8],[3,5],[4,6]], w = 1</span></p>

<p style=""><span class="example-io" style="font-size: 8.75px;"><b>输出：</b></span><span class="example-io" style="font-size: 0.85rem; font-family: Menlo, sans-serif;">2</span></p>

<p style="font-size: 0.875rem;"><strong>解释：</strong></p>

<p style="font-size: 0.875rem;">上图展示了一种可行的矩形放置方案：</p>

<ul style="font-size: 0.875rem;">
	<li>一个矩形的左下角在&nbsp;<code>(1, 0)</code>&nbsp;，右上角在&nbsp;<code>(2, 8)</code>&nbsp;。</li>
	<li>一个矩形的左下角在&nbsp;<code>(3, 0)</code>&nbsp;，右上角在&nbsp;<code>(4, 8)</code>&nbsp;。</li>
</ul>
</div>

<p><strong class="example">示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3100-3199/3111.Minimum%20Rectangles%20to%20Cover%20Points/images/screenshot-from-2024-03-04-18-59-12.png" style="width: 260px; height: 250px;" /></p>

<div class="example-block" style="border-color: var(--border-tertiary); border-left-width: 2px; color: var(--text-secondary); margin-bottom: 1rem; margin-top: 1rem; overflow: visible; padding-left: 1rem;">
<p style=""><span class="example-io" style="font-size: 8.75px;"><b>输入：</b></span><span class="example-io" style="font-size: 0.85rem; font-family: Menlo, sans-serif;">points = [[0,0],[1,1],[2,2],[3,3],[4,4],[5,5],[6,6]], w = 2</span></p>

<p style=""><span class="example-io" style="font-size: 8.75px;"><b>输出：</b></span><span class="example-io" style="font-size: 0.85rem; font-family: Menlo, sans-serif;">3</span></p>

<p style="font-size: 0.875rem;"><b>解释：</b></p>

<p style="font-size: 0.875rem;">上图展示了一种可行的矩形放置方案：</p>

<ul style="font-size: 0.875rem;">
	<li>一个矩形的左下角在&nbsp;<code>(0, 0)</code>&nbsp;，右上角在&nbsp;<code>(2, 2)</code>&nbsp;。</li>
	<li>一个矩形的左下角在&nbsp;<code>(3, 0)</code>&nbsp;，右上角在&nbsp;<code>(5, 5)</code>&nbsp;。</li>
	<li>一个矩形的左下角在&nbsp;<code>(6, 0)</code>&nbsp;，右上角在&nbsp;<code>(6, 6)</code>&nbsp;。</li>
</ul>
</div>

<p><strong class="example">示例 3：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3100-3199/3111.Minimum%20Rectangles%20to%20Cover%20Points/images/screenshot-from-2024-03-04-20-24-03.png" style="height: 150px; width: 127px;" /></p>

<div class="example-block" style="border-color: var(--border-tertiary); border-left-width: 2px; color: var(--text-secondary); margin-bottom: 1rem; margin-top: 1rem; overflow: visible; padding-left: 1rem;">
<p style=""><span class="example-io" style="font-size: 8.75px;"><b>输入：</b></span><span class="example-io" style="font-size: 0.85rem; font-family: Menlo, sans-serif;">points = [[2,3],[1,2]], w = 0</span></p>

<p style=""><span class="example-io" style="font-size: 8.75px;"><b>输出：</b></span><span class="example-io" style="font-size: 0.85rem; font-family: Menlo, sans-serif;">2</span></p>

<p style="font-size: 0.875rem;"><strong>解释：</strong></p>

<p style="font-size: 0.875rem;">上图展示了一种可行的矩形放置方案：</p>

<ul style="font-size: 0.875rem;">
	<li>一个矩形的左下角在&nbsp;<code>(1, 0)</code>&nbsp;，右上角在&nbsp;<code>(1, 2)</code>&nbsp;。</li>
	<li>一个矩形的左下角在&nbsp;<code>(2, 0)</code>&nbsp;，右上角在&nbsp;<code>(2, 3)</code>&nbsp;。</li>
</ul>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= points.length &lt;= 10<sup>5</sup></code></li>
	<li><code>points[i].length == 2</code></li>
	<li><code>0 &lt;= x<sub>i</sub> == points[i][0] &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= y<sub>i</sub> == points[i][1] &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= w &lt;= 10<sup>9</sup></code></li>
	<li>所有点坐标&nbsp;<code>(x<sub>i</sub>, y<sub>i</sub>)</code>&nbsp;互不相同。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 排序

根据题目描述，我们不需要考虑矩形的高度，只需要考虑矩形的宽度。

我们可以将所有的点按照横坐标进行排序，用一个变量 $x_1$ 记录当前矩形所能覆盖的最右边的横坐标，初始时 $x_1 = -1$。

接下来我们遍历所有的点，如果当前点的横坐标 $x$ 大于 $x_1$，说明已有的矩形无法覆盖当前点，我们就需要增加一个矩形，答案加一，然后我们更新 $x_1 = x + w$。

遍历完成后，我们就得到了最少需要的矩形数目。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 是点的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minRectanglesToCoverPoints(self, points: List[List[int]], w: int) -> int:
        points.sort()
        ans, x1 = 0, -1
        for x, _ in points:
            if x > x1:
                ans += 1
                x1 = x + w
        return ans
```

#### Java

```java
class Solution {
    public int minRectanglesToCoverPoints(int[][] points, int w) {
        Arrays.sort(points, (a, b) -> a[0] - b[0]);
        int ans = 0, x1 = -1;
        for (int[] p : points) {
            int x = p[0];
            if (x > x1) {
                ++ans;
                x1 = x + w;
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
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        sort(points.begin(), points.end());
        int ans = 0, x1 = -1;
        for (const auto& p : points) {
            int x = p[0];
            if (x > x1) {
                ++ans;
                x1 = x + w;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func minRectanglesToCoverPoints(points [][]int, w int) (ans int) {
	sort.Slice(points, func(i, j int) bool { return points[i][0] < points[j][0] })
	x1 := -1
	for _, p := range points {
		if x := p[0]; x > x1 {
			ans++
			x1 = x + w
		}
	}
	return
}
```

#### TypeScript

```ts
function minRectanglesToCoverPoints(points: number[][], w: number): number {
    points.sort((a, b) => a[0] - b[0]);
    let [ans, x1] = [0, -1];
    for (const [x, _] of points) {
        if (x > x1) {
            ++ans;
            x1 = x + w;
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn min_rectangles_to_cover_points(mut points: Vec<Vec<i32>>, w: i32) -> i32 {
        points.sort_by(|a, b| a[0].cmp(&b[0]));
        let mut ans = 0;
        let mut x1 = -1;
        for p in points {
            let x = p[0];
            if x > x1 {
                ans += 1;
                x1 = x + w;
            }
        }
        ans
    }
}
```

#### C#

```cs
public class Solution {
    public int MinRectanglesToCoverPoints(int[][] points, int w) {
        Array.Sort(points, (a, b) => a[0] - b[0]);
        int ans = 0, x1 = -1;
        foreach (int[] p in points) {
            int x = p[0];
            if (x > x1) {
                ans++;
                x1 = x + w;
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

# [3112. 访问消失节点的最少时间](https://leetcode.cn/problems/minimum-time-to-visit-disappearing-nodes){#3112}

{{< tabs "3112" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumTime(
        self, n: int, edges: List[List[int]], disappear: List[int]
    ) -> List[int]:
        g = defaultdict(list)
        for u, v, w in edges:
            g[u].append((v, w))
            g[v].append((u, w))
        dist = [inf] * n
        dist[0] = 0
        pq = [(0, 0)]
        while pq:
            du, u = heappop(pq)
            if du > dist[u]:
                continue
            for v, w in g[u]:
                if dist[v] > dist[u] + w and dist[u] + w < disappear[v]:
                    dist[v] = dist[u] + w
                    heappush(pq, (dist[v], v))
        return [a if a < b else -1 for a, b in zip(dist, disappear)]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] minimumTime(int n, int[][] edges, int[] disappear) {
        List<int[]>[] g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (var e : edges) {
            int u = e[0], v = e[1], w = e[2];
            g[u].add(new int[] {v, w});
            g[v].add(new int[] {u, w});
        }
        int[] dist = new int[n];
        Arrays.fill(dist, 1 << 30);
        dist[0] = 0;
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        pq.offer(new int[] {0, 0});
        while (!pq.isEmpty()) {
            var e = pq.poll();
            int du = e[0], u = e[1];
            if (du > dist[u]) {
                continue;
            }
            for (var nxt : g[u]) {
                int v = nxt[0], w = nxt[1];
                if (dist[v] > dist[u] + w && dist[u] + w < disappear[v]) {
                    dist[v] = dist[u] + w;
                    pq.offer(new int[] {dist[v], v});
                }
            }
        }
        int[] ans = new int[n];
        for (int i = 0; i < n; ++i) {
            ans[i] = dist[i] < disappear[i] ? dist[i] : -1;
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
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<vector<pair<int, int>>> g(n);
        for (const auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        }

        vector<int> dist(n, 1 << 30);
        dist[0] = 0;

        using pii = pair<int, int>;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [du, u] = pq.top();
            pq.pop();

            if (du > dist[u]) {
                continue;
            }

            for (auto [v, w] : g[u]) {
                if (dist[v] > dist[u] + w && dist[u] + w < disappear[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[i] = dist[i] < disappear[i] ? dist[i] : -1;
        }

        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumTime(n int, edges [][]int, disappear []int) []int {
	g := make([][]pair, n)
	for _, e := range edges {
		u, v, w := e[0], e[1], e[2]
		g[u] = append(g[u], pair{v, w})
		g[v] = append(g[v], pair{u, w})
	}

	dist := make([]int, n)
	for i := range dist {
		dist[i] = 1 << 30
	}
	dist[0] = 0

	pq := hp{{0, 0}}

	for len(pq) > 0 {
		du, u := pq[0].dis, pq[0].u
		heap.Pop(&pq)

		if du > dist[u] {
			continue
		}

		for _, nxt := range g[u] {
			v, w := nxt.dis, nxt.u
			if dist[v] > dist[u]+w && dist[u]+w < disappear[v] {
				dist[v] = dist[u] + w
				heap.Push(&pq, pair{dist[v], v})
			}
		}
	}

	ans := make([]int, n)
	for i := 0; i < n; i++ {
		if dist[i] < disappear[i] {
			ans[i] = dist[i]
		} else {
			ans[i] = -1
		}
	}

	return ans
}

type pair struct{ dis, u int }
type hp []pair

func (h hp) Len() int           { return len(h) }
func (h hp) Less(i, j int) bool { return h[i].dis < h[j].dis }
func (h hp) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *hp) Push(v any)        { *h = append(*h, v.(pair)) }
func (h *hp) Pop() any          { a := *h; v := a[len(a)-1]; *h = a[:len(a)-1]; return v }
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumTime(n: number, edges: number[][], disappear: number[]): number[] {
    const g: [number, number][][] = Array.from({ length: n }, () => []);
    for (const [u, v, w] of edges) {
        g[u].push([v, w]);
        g[v].push([u, w]);
    }
    const dist = Array.from({ length: n }, () => Infinity);
    dist[0] = 0;
    const pq = new PriorityQueue({
        compare: (a, b) => (a[0] === b[0] ? a[1] - b[1] : a[0] - b[0]),
    });
    pq.enqueue([0, 0]);
    while (pq.size() > 0) {
        const [du, u] = pq.dequeue()!;
        if (du > dist[u]) {
            continue;
        }
        for (const [v, w] of g[u]) {
            if (dist[v] > dist[u] + w && dist[u] + w < disappear[v]) {
                dist[v] = dist[u] + w;
                pq.enqueue([dist[v], v]);
            }
        }
    }
    return dist.map((a, i) => (a < disappear[i] ? a : -1));
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个二维数组 <code>edges</code>&nbsp;表示一个 <code>n</code>&nbsp;个点的无向图，其中&nbsp;<code>edges[i] = [u<sub>i</sub>, v<sub>i</sub>, length<sub>i</sub>]</code>&nbsp;表示节点&nbsp;<code>u<sub>i</sub></code> 和节点&nbsp;<code>v<sub>i</sub></code>&nbsp;之间有一条需要&nbsp;<code>length<sub>i</sub></code>&nbsp;单位时间通过的无向边。</p>

<p>同时给你一个数组&nbsp;<code>disappear</code>&nbsp;，其中&nbsp;<code>disappear[i]</code>&nbsp;表示节点 <code>i</code>&nbsp;从图中消失的时间点，在那一刻及以后，你无法再访问这个节点。</p>

<p><strong>注意</strong>，图有可能一开始是不连通的，两个节点之间也可能有多条边。</p>

<p>请你返回数组&nbsp;<code>answer</code>&nbsp;，<code>answer[i]</code>&nbsp;表示从节点 <code>0</code>&nbsp;到节点 <code>i</code>&nbsp;需要的 <strong>最少</strong>&nbsp;单位时间。如果从节点 <code>0</code>&nbsp;出发 <strong>无法</strong> 到达节点 <code>i</code>&nbsp;，那么 <code>answer[i]</code>&nbsp;为 <code>-1</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<p><img 10px="" alt="" padding:="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3100-3199/3112.Minimum%20Time%20to%20Visit%20Disappearing%20Nodes/images/example1.png" style="width: 350px; height: 210px;" /></p>

<div class="example-block" style="border-color: var(--border-tertiary); border-left-width: 2px; color: var(--text-secondary); margin-bottom: 1rem; margin-top: 1rem; overflow: visible; padding-left: 1rem;">
<p style=""><span class="example-io"><b>输入：</b></span><span class="example-io" style="font-size: 0.85rem; font-family: Menlo, sans-serif;">n = 3, edges = [[0,1,2],[1,2,1],[0,2,4]], disappear = [1,1,5]</span></p>

<p style=""><span class="example-io"><b>输出：</b></span><span class="example-io" style="font-size: 0.85rem; font-family: Menlo, sans-serif;">[0,-1,4]</span></p>

<p style="font-size: 0.875rem;"><strong>解释：</strong></p>

<p style="font-size: 0.875rem;">我们从节点 0 出发，目的是用最少的时间在其他节点消失之前到达它们。</p>

<ul style="font-size: 0.875rem;">
	<li>对于节点 0 ，我们不需要任何时间，因为它就是我们的起点。</li>
	<li>对于节点 1 ，我们需要至少 2 单位时间，通过&nbsp;<code>edges[0]</code>&nbsp;到达。但当我们到达的时候，它已经消失了，所以我们无法到达它。</li>
	<li>对于节点 2 ，我们需要至少 4 单位时间，通过&nbsp;<code>edges[2]</code>&nbsp;到达。</li>
</ul>
</div>

<p><strong class="example">示例 2：</strong></p>

<p><img 10px="" alt="" padding:="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3100-3199/3112.Minimum%20Time%20to%20Visit%20Disappearing%20Nodes/images/example2.png" style="width: 350px; height: 210px;" /></p>

<div class="example-block" style="border-color: var(--border-tertiary); border-left-width: 2px; color: var(--text-secondary); margin-bottom: 1rem; margin-top: 1rem; overflow: visible; padding-left: 1rem;">
<p style=""><span class="example-io"><b>输入：</b></span><span class="example-io" style="font-size: 0.85rem; font-family: Menlo, sans-serif;">n = 3, edges = [[0,1,2],[1,2,1],[0,2,4]], disappear = [1,3,5]</span></p>

<p style=""><span class="example-io"><b>输出：</b></span><span class="example-io" style="font-size: 0.85rem; font-family: Menlo, sans-serif;">[0,2,3]</span></p>

<p style="font-size: 0.875rem;"><strong>解释：</strong></p>

<p style="font-size: 0.875rem;">我们从节点 0 出发，目的是用最少的时间在其他节点消失之前到达它们。</p>

<ul style="font-size: 0.875rem;">
	<li>对于节点 0 ，我们不需要任何时间，因为它就是我们的起点。</li>
	<li>对于节点 1 ，我们需要至少 2 单位时间，通过&nbsp;<code>edges[0]</code>&nbsp;到达。</li>
	<li>对于节点 2&nbsp;，我们需要至少 3&nbsp;单位时间，通过&nbsp;<code>edges[0]</code>&nbsp;和 <code>edges[1]</code>&nbsp;到达。</li>
</ul>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block" style="border-color: var(--border-tertiary); border-left-width: 2px; color: var(--text-secondary); margin-bottom: 1rem; margin-top: 1rem; overflow: visible; padding-left: 1rem;">
<p><span class="example-io"><b>输入：</b>n = 2, edges = [[0,1,1]], disappear = [1,1]</span></p>

<p><span class="example-io"><b>输出：</b>[0,-1]</span></p>

<p><strong>解释：</strong></p>

<p>当我们到达节点 1 的时候，它恰好消失，所以我们无法到达节点 1 。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>0 &lt;= edges.length &lt;= 10<sup>5</sup></code></li>
	<li><code>edges[i] == [u<sub>i</sub>, v<sub>i</sub>, length<sub>i</sub>]</code></li>
	<li><code>0 &lt;= u<sub>i</sub>, v<sub>i</sub> &lt;= n - 1</code></li>
	<li><code>1 &lt;= length<sub>i</sub> &lt;= 10<sup>5</sup></code></li>
	<li><code>disappear.length == n</code></li>
	<li><code>1 &lt;= disappear[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：堆优化的 Dijkstra

我们先创建一个邻接表 $\textit{g}$，用于存储图的边。然后创建一个数组 $\textit{dist}$，用于存储从节点 $0$ 到其他节点的最短距离。初始化 $\textit{dist}[0] = 0$，其余节点的距离初始化为无穷大。

然后，我们使用 Dijkstra 算法计算从节点 $0$ 到其他节点的最短距离。具体步骤如下：

1. 创建一个优先队列 $\textit{pq}$，用于存储节点的距离和节点编号，初始时将节点 $0$ 加入队列，距离为 $0$。
2. 从队列中取出一个节点 $u$，如果 $u$ 的距离 $du$ 大于 $\textit{dist}[u]$，说明 $u$ 已经被更新过了，直接跳过。
3. 遍历节点 $u$ 的所有邻居节点 $v$，如果 $\textit{dist}[v] > \textit{dist}[u] + w$ 且 $\textit{dist}[u] + w < \textit{disappear}[v]$，则更新 $\textit{dist}[v] = \textit{dist}[u] + w$，并将节点 $v$ 加入队列。
4. 重复步骤 2 和步骤 3，直到队列为空。

最后，我们遍历 $\textit{dist}$ 数组，如果 $\textit{dist}[i] < \textit{disappear}[i]$，则 $\textit{answer}[i] = \textit{dist}[i]$，否则 $\textit{answer}[i] = -1$。

时间复杂度 $O(m \times \log m)$，空间复杂度 $O(m)$。其中 $m$ 是边的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumTime(
        self, n: int, edges: List[List[int]], disappear: List[int]
    ) -> List[int]:
        g = defaultdict(list)
        for u, v, w in edges:
            g[u].append((v, w))
            g[v].append((u, w))
        dist = [inf] * n
        dist[0] = 0
        pq = [(0, 0)]
        while pq:
            du, u = heappop(pq)
            if du > dist[u]:
                continue
            for v, w in g[u]:
                if dist[v] > dist[u] + w and dist[u] + w < disappear[v]:
                    dist[v] = dist[u] + w
                    heappush(pq, (dist[v], v))
        return [a if a < b else -1 for a, b in zip(dist, disappear)]
```

#### Java

```java
class Solution {
    public int[] minimumTime(int n, int[][] edges, int[] disappear) {
        List<int[]>[] g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (var e : edges) {
            int u = e[0], v = e[1], w = e[2];
            g[u].add(new int[] {v, w});
            g[v].add(new int[] {u, w});
        }
        int[] dist = new int[n];
        Arrays.fill(dist, 1 << 30);
        dist[0] = 0;
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        pq.offer(new int[] {0, 0});
        while (!pq.isEmpty()) {
            var e = pq.poll();
            int du = e[0], u = e[1];
            if (du > dist[u]) {
                continue;
            }
            for (var nxt : g[u]) {
                int v = nxt[0], w = nxt[1];
                if (dist[v] > dist[u] + w && dist[u] + w < disappear[v]) {
                    dist[v] = dist[u] + w;
                    pq.offer(new int[] {dist[v], v});
                }
            }
        }
        int[] ans = new int[n];
        for (int i = 0; i < n; ++i) {
            ans[i] = dist[i] < disappear[i] ? dist[i] : -1;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<vector<pair<int, int>>> g(n);
        for (const auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        }

        vector<int> dist(n, 1 << 30);
        dist[0] = 0;

        using pii = pair<int, int>;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [du, u] = pq.top();
            pq.pop();

            if (du > dist[u]) {
                continue;
            }

            for (auto [v, w] : g[u]) {
                if (dist[v] > dist[u] + w && dist[u] + w < disappear[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[i] = dist[i] < disappear[i] ? dist[i] : -1;
        }

        return ans;
    }
};
```

#### Go

```go
func minimumTime(n int, edges [][]int, disappear []int) []int {
	g := make([][]pair, n)
	for _, e := range edges {
		u, v, w := e[0], e[1], e[2]
		g[u] = append(g[u], pair{v, w})
		g[v] = append(g[v], pair{u, w})
	}

	dist := make([]int, n)
	for i := range dist {
		dist[i] = 1 << 30
	}
	dist[0] = 0

	pq := hp{{0, 0}}

	for len(pq) > 0 {
		du, u := pq[0].dis, pq[0].u
		heap.Pop(&pq)

		if du > dist[u] {
			continue
		}

		for _, nxt := range g[u] {
			v, w := nxt.dis, nxt.u
			if dist[v] > dist[u]+w && dist[u]+w < disappear[v] {
				dist[v] = dist[u] + w
				heap.Push(&pq, pair{dist[v], v})
			}
		}
	}

	ans := make([]int, n)
	for i := 0; i < n; i++ {
		if dist[i] < disappear[i] {
			ans[i] = dist[i]
		} else {
			ans[i] = -1
		}
	}

	return ans
}

type pair struct{ dis, u int }
type hp []pair

func (h hp) Len() int           { return len(h) }
func (h hp) Less(i, j int) bool { return h[i].dis < h[j].dis }
func (h hp) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *hp) Push(v any)        { *h = append(*h, v.(pair)) }
func (h *hp) Pop() any          { a := *h; v := a[len(a)-1]; *h = a[:len(a)-1]; return v }
```

#### TypeScript

```ts
function minimumTime(n: number, edges: number[][], disappear: number[]): number[] {
    const g: [number, number][][] = Array.from({ length: n }, () => []);
    for (const [u, v, w] of edges) {
        g[u].push([v, w]);
        g[v].push([u, w]);
    }
    const dist = Array.from({ length: n }, () => Infinity);
    dist[0] = 0;
    const pq = new PriorityQueue({
        compare: (a, b) => (a[0] === b[0] ? a[1] - b[1] : a[0] - b[0]),
    });
    pq.enqueue([0, 0]);
    while (pq.size() > 0) {
        const [du, u] = pq.dequeue()!;
        if (du > dist[u]) {
            continue;
        }
        for (const [v, w] of g[u]) {
            if (dist[v] > dist[u] + w && dist[u] + w < disappear[v]) {
                dist[v] = dist[u] + w;
                pq.enqueue([dist[v], v]);
            }
        }
    }
    return dist.map((a, i) => (a < disappear[i] ? a : -1));
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3113. 边界元素是最大值的子数组数目](https://leetcode.cn/problems/find-the-number-of-subarrays-where-boundary-elements-are-maximum){#3113}

{{< tabs "3113" >}}

{{% tab "python" %}}
```python
class Solution:
    def numberOfSubarrays(self, nums: List[int]) -> int:
        stk = []
        ans = 0
        for x in nums:
            while stk and stk[-1][0] < x:
                stk.pop()
            if not stk or stk[-1][0] > x:
                stk.append([x, 1])
            else:
                stk[-1][1] += 1
            ans += stk[-1][1]
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long numberOfSubarrays(int[] nums) {
        Deque<int[]> stk = new ArrayDeque<>();
        long ans = 0;
        for (int x : nums) {
            while (!stk.isEmpty() && stk.peek()[0] < x) {
                stk.pop();
            }
            if (stk.isEmpty() || stk.peek()[0] > x) {
                stk.push(new int[] {x, 1});
            } else {
                stk.peek()[1]++;
            }
            ans += stk.peek()[1];
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
    long long numberOfSubarrays(vector<int>& nums) {
        vector<pair<int, int>> stk;
        long long ans = 0;
        for (int x : nums) {
            while (!stk.empty() && stk.back().first < x) {
                stk.pop_back();
            }
            if (stk.empty() || stk.back().first > x) {
                stk.push_back(make_pair(x, 1));
            } else {
                stk.back().second++;
            }
            ans += stk.back().second;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numberOfSubarrays(nums []int) (ans int64) {
	stk := [][2]int{}
	for _, x := range nums {
		for len(stk) > 0 && stk[len(stk)-1][0] < x {
			stk = stk[:len(stk)-1]
		}
		if len(stk) == 0 || stk[len(stk)-1][0] > x {
			stk = append(stk, [2]int{x, 1})
		} else {
			stk[len(stk)-1][1]++
		}
		ans += int64(stk[len(stk)-1][1])
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numberOfSubarrays(nums: number[]): number {
    const stk: number[][] = [];
    let ans = 0;
    for (const x of nums) {
        while (stk.length > 0 && stk.at(-1)![0] < x) {
            stk.pop();
        }
        if (stk.length === 0 || stk.at(-1)![0] > x) {
            stk.push([x, 1]);
        } else {
            stk.at(-1)![1]++;
        }
        ans += stk.at(-1)![1];
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

<p>给你一个 <strong>正</strong>&nbsp;整数数组&nbsp;<code>nums</code>&nbsp;。</p>

<p>请你求出&nbsp;<code>nums</code>&nbsp;中有多少个子数组，满足子数组中&nbsp;<strong>第一个</strong>&nbsp;和 <strong>最后一个</strong>&nbsp;元素都是这个子数组中的 <strong>最大</strong>&nbsp;值。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [1,4,3,3,2]</span></p>

<p><span class="example-io"><b>输出：</b>6</span></p>

<p><strong>解释：</strong></p>

<p>总共有 6 个子数组满足第一个元素和最后一个元素都是子数组中的最大值：</p>

<ul>
	<li>子数组&nbsp;<code>[<u><em><strong>1</strong></em></u>,4,3,3,2]</code>&nbsp;，最大元素为 1 ，第一个和最后一个元素都是 1 。</li>
	<li>子数组&nbsp;<code>[1,<u><em><strong>4</strong></em></u>,3,3,2]</code>&nbsp;，最大元素为 4 ，第一个和最后一个元素都是 4 。</li>
	<li>子数组&nbsp;<code>[1,4,<u><em><strong>3</strong></em></u>,3,2]</code>&nbsp;，最大元素为 3 ，第一个和最后一个元素都是 3 。</li>
	<li>子数组&nbsp;<code>[1,4,3,<u><em><strong>3</strong></em></u>,2]</code>&nbsp;，最大元素为 3 ，第一个和最后一个元素都是 3 。</li>
	<li>子数组&nbsp;<code>[1,4,3,3,<u><em><strong>2</strong></em></u>]</code>&nbsp;，最大元素为 2 ，第一个和最后一个元素都是 2 。</li>
	<li>子数组&nbsp;<code>[1,4,<u><em><strong>3,3</strong></em></u>,2]</code>&nbsp;，最大元素为 3 ，第一个和最后一个元素都是 3 。</li>
</ul>

<p>所以我们返回 6 。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [3,3,3]</span></p>

<p><span class="example-io"><b>输出：</b>6</span></p>

<p><strong>解释：</strong></p>

<p>总共有 6 个子数组满足第一个元素和最后一个元素都是子数组中的最大值：</p>

<ul>
	<li>子数组 <code>[<u><em><strong>3</strong></em></u>,3,3]</code>&nbsp;，最大元素为 3&nbsp;，第一个和最后一个元素都是 3&nbsp;。</li>
	<li>子数组 <code>[3,<u><em><strong>3</strong></em></u>,3]</code>&nbsp;，最大元素为 3&nbsp;，第一个和最后一个元素都是 3&nbsp;。</li>
	<li>子数组 <code>[3,3,<u><em><strong>3</strong></em></u>]</code>&nbsp;，最大元素为 3&nbsp;，第一个和最后一个元素都是 3&nbsp;。</li>
	<li>子数组 <code>[<u><em><strong>3,3</strong></em></u>,3]</code>&nbsp;，最大元素为 3&nbsp;，第一个和最后一个元素都是 3&nbsp;。</li>
	<li>子数组 <code>[3,<u><em><strong>3,3</strong></em></u>]</code>&nbsp;，最大元素为 3&nbsp;，第一个和最后一个元素都是 3&nbsp;。</li>
	<li>子数组 <code>[<u><em><strong>3,3,3</strong></em></u>]</code>&nbsp;，最大元素为 3&nbsp;，第一个和最后一个元素都是 3&nbsp;。</li>
</ul>

<p>所以我们返回 6 。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [1]</span></p>

<p><span class="example-io"><b>输出：</b>1</span></p>

<p><strong>解释：</strong></p>

<p><code>nums</code>&nbsp;中只有一个子数组&nbsp;<code>[<em><strong>1</strong></em>]</code>&nbsp;，最大元素为 1 ，第一个和最后一个元素都是 1 。</p>

<p>所以我们返回 1 。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：单调栈

我们考虑以数组 $nums$ 中的每个元素 $x$ 作为子数组的边界元素且最大值的情况。

每个长度为 $1$ 的子数组都满足条件，而对于长度大于 $1$ 的子数组，子数组中的所有元素都不能大于边界元素 $x$，我们可以用单调栈来实现。

我们维护一个从栈底到栈顶单调递减的栈，单调栈的每个元素是一个二元组 $[x, cnt]$，表示元素 $x$ 且以 $x$ 为边界元素且最大值的子数组的个数为 $cnt$。

我们从左到右遍历数组 $nums$，对于每个元素 $x$，我们不断地将栈顶元素弹出，直到栈为空或者栈顶元素的第一个元素大于等于 $x$。如果栈为空，或者栈顶元素的第一个元素大于 $x$，说明当前遇到第一个边界元素为 $x$ 且最大值的子数组，该子数组的长度为 $1$，所以我们将 $[x, 1]$ 入栈。如果栈顶元素的第一个元素等于 $x$，说明当前遇到的边界元素为 $x$ 且最大值的子数组，我们将栈顶元素的第二个元素加 $1$。然后，我们将栈顶元素的第二个元素加到答案中。

遍历结束后，返回答案即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numberOfSubarrays(self, nums: List[int]) -> int:
        stk = []
        ans = 0
        for x in nums:
            while stk and stk[-1][0] < x:
                stk.pop()
            if not stk or stk[-1][0] > x:
                stk.append([x, 1])
            else:
                stk[-1][1] += 1
            ans += stk[-1][1]
        return ans
```

#### Java

```java
class Solution {
    public long numberOfSubarrays(int[] nums) {
        Deque<int[]> stk = new ArrayDeque<>();
        long ans = 0;
        for (int x : nums) {
            while (!stk.isEmpty() && stk.peek()[0] < x) {
                stk.pop();
            }
            if (stk.isEmpty() || stk.peek()[0] > x) {
                stk.push(new int[] {x, 1});
            } else {
                stk.peek()[1]++;
            }
            ans += stk.peek()[1];
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long numberOfSubarrays(vector<int>& nums) {
        vector<pair<int, int>> stk;
        long long ans = 0;
        for (int x : nums) {
            while (!stk.empty() && stk.back().first < x) {
                stk.pop_back();
            }
            if (stk.empty() || stk.back().first > x) {
                stk.push_back(make_pair(x, 1));
            } else {
                stk.back().second++;
            }
            ans += stk.back().second;
        }
        return ans;
    }
};
```

#### Go

```go
func numberOfSubarrays(nums []int) (ans int64) {
	stk := [][2]int{}
	for _, x := range nums {
		for len(stk) > 0 && stk[len(stk)-1][0] < x {
			stk = stk[:len(stk)-1]
		}
		if len(stk) == 0 || stk[len(stk)-1][0] > x {
			stk = append(stk, [2]int{x, 1})
		} else {
			stk[len(stk)-1][1]++
		}
		ans += int64(stk[len(stk)-1][1])
	}
	return
}
```

#### TypeScript

```ts
function numberOfSubarrays(nums: number[]): number {
    const stk: number[][] = [];
    let ans = 0;
    for (const x of nums) {
        while (stk.length > 0 && stk.at(-1)![0] < x) {
            stk.pop();
        }
        if (stk.length === 0 || stk.at(-1)![0] > x) {
            stk.push([x, 1]);
        } else {
            stk.at(-1)![1]++;
        }
        ans += stk.at(-1)![1];
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3114. 替换字符可以得到的最晚时间](https://leetcode.cn/problems/latest-time-you-can-obtain-after-replacing-characters){#3114}

{{< tabs "3114" >}}

{{% tab "python" %}}
```python
class Solution:
    def findLatestTime(self, s: str) -> str:
        s = list(s)
        if s[0] == "?":
            s[0] = "1" if s[1] == "?" or s[1] < "2" else "0"
        if s[1] == "?":
            s[1] = "1" if s[0] == "1" else "9"
        if s[3] == "?":
            s[3] = "5"
        if s[4] == "?":
            s[4] = "9"
        return "".join(s)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String findLatestTime(String s) {
        char[] cs = s.toCharArray();
        if (cs[0] == '?') {
            cs[0] = cs[1] == '?' || cs[1] < '2' ? '1' : '0';
        }
        if (cs[1] == '?') {
            cs[1] = cs[0] == '1' ? '1' : '9';
        }
        if (cs[3] == '?') {
            cs[3] = '5';
        }
        if (cs[4] == '?') {
            cs[4] = '9';
        }
        return new String(cs);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string findLatestTime(string s) {
        if (s[0] == '?') {
            s[0] = s[1] == '?' || s[1] < '2' ? '1' : '0';
        }
        if (s[1] == '?') {
            s[1] = s[0] == '1' ? '1' : '9';
        }
        if (s[3] == '?') {
            s[3] = '5';
        }
        if (s[4] == '?') {
            s[4] = '9';
        }
        return s;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findLatestTime(s string) string {
	cs := []byte(s)
	if cs[0] == '?' {
		if cs[1] == '?' || cs[1] < '2' {
			cs[0] = '1'
		} else {
			cs[0] = '0'
		}
	}
	if cs[1] == '?' {
		if cs[0] == '1' {
			cs[1] = '1'
		} else {
			cs[1] = '9'
		}
	}
	if cs[3] == '?' {
		cs[3] = '5'
	}
	if cs[4] == '?' {
		cs[4] = '9'
	}
	return string(cs)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findLatestTime(s: string): string {
    const cs = s.split('');
    if (cs[0] === '?') {
        cs[0] = cs[1] === '?' || cs[1] < '2' ? '1' : '0';
    }
    if (cs[1] === '?') {
        cs[1] = cs[0] === '1' ? '1' : '9';
    }
    if (cs[3] === '?') {
        cs[3] = '5';
    }
    if (cs[4] === '?') {
        cs[4] = '9';
    }
    return cs.join('');
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串 <code>s</code>，表示一个 12 小时制的时间格式，其中一些数字（可能没有）被 <code>"?"</code> 替换。</p>

<p>12 小时制时间格式为 <code>"HH:MM"</code> ，其中 <code>HH</code> 的取值范围为 <code>00</code> 至 <code>11</code>，<code>MM</code> 的取值范围为 <code>00</code> 至 <code>59</code>。最早的时间为 <code>00:00</code>，最晚的时间为 <code>11:59</code>。</p>

<p>你需要将 <code>s</code> 中的<strong> 所有</strong> <code>"?"</code> 字符替换为数字，使得结果字符串代表的时间是一个<strong> 有效 </strong>的 12 小时制时间，并且是可能的 <strong>最晚 </strong>时间。</p>

<p>返回结果字符串。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">s = "1?:?4"</span></p>

<p><strong>输出：</strong> <span class="example-io">"11:54"</span></p>

<p><strong>解释：</strong> 通过替换 <code>"?"</code> 字符，可以得到的最晚12小时制时间是 <code>"11:54"</code>。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">s = "0?:5?"</span></p>

<p><strong>输出：</strong> <span class="example-io">"09:59"</span></p>

<p><strong>解释：</strong> 通过替换 <code>"?"</code> 字符，可以得到的最晚12小时制时间是 <code>"09:59"</code>。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>s.length == 5</code></li>
	<li><code>s[2]</code> 是字符 <code>":"</code></li>
	<li>除 <code>s[2]</code> 外，其他字符都是数字或 <code>"?"</code></li>
	<li>输入保证在替换 <code>"?"</code> 字符后至少存在一个介于 <code>"00:00"</code> 和 <code>"11:59"</code> 之间的时间。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举

我们可以从大到小枚举所有的时间，其中小时 $h$ 从 $11$ 到 $0$，分钟 $m$ 从 $59$ 到 $0$。对于每一个时间 $t$，我们检查是否满足 $t$ 的每一位字符都与 $s$ 的对应位置字符相等（如果 $s$ 的对应位置字符不是 "?" 的话）。如果满足，那么我们就找到了答案，返回 $t$。

时间复杂度 $O(h \times m)$，其中 $h = 12$, $m = 60$。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findLatestTime(self, s: str) -> str:
        for h in range(11, -1, -1):
            for m in range(59, -1, -1):
                t = f"{h:02d}:{m:02d}"
                if all(a == b for a, b in zip(s, t) if a != "?"):
                    return t
```

#### Java

```java
class Solution {
    public String findLatestTime(String s) {
        for (int h = 11;; h--) {
            for (int m = 59; m >= 0; m--) {
                String t = String.format("%02d:%02d", h, m);
                boolean ok = true;
                for (int i = 0; i < s.length(); i++) {
                    if (s.charAt(i) != '?' && s.charAt(i) != t.charAt(i)) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    return t;
                }
            }
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    string findLatestTime(string s) {
        for (int h = 11;; h--) {
            for (int m = 59; m >= 0; m--) {
                char t[6];
                sprintf(t, "%02d:%02d", h, m);
                bool ok = true;
                for (int i = 0; i < s.length(); i++) {
                    if (s[i] != '?' && s[i] != t[i]) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    return t;
                }
            }
        }
    }
};
```

#### Go

```go
func findLatestTime(s string) string {
	for h := 11; ; h-- {
		for m := 59; m >= 0; m-- {
			t := fmt.Sprintf("%02d:%02d", h, m)
			ok := true
			for i := 0; i < len(s); i++ {
				if s[i] != '?' && s[i] != t[i] {
					ok = false
					break
				}
			}
			if ok {
				return t
			}
		}
	}
}
```

#### TypeScript

```ts
function findLatestTime(s: string): string {
    for (let h = 11; ; h--) {
        for (let m = 59; m >= 0; m--) {
            const t: string = `${h.toString().padStart(2, '0')}:${m.toString().padStart(2, '0')}`;
            let ok: boolean = true;
            for (let i = 0; i < s.length; i++) {
                if (s[i] !== '?' && s[i] !== t[i]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                return t;
            }
        }
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：逐个判断

我们可以逐个判断 $s$ 的每一位字符，如果是 "?" 的话，我们就根据前后的字符来确定这一位字符的值。具体地，我们有以下规则：

-   如果 $s[0]$ 是 "?"，那么 $s[0]$ 的值应该是 "1" 或 "0"，具体取决于 $s[1]$ 的值。如果 $s[1]$ 是 "?" 或者 $s[1]$ 小于 "2"，那么 $s[0]$ 的值应该是 "1"，否则 $s[0]$ 的值应该是 "0"。
-   如果 $s[1]$ 是 "?"，那么 $s[1]$ 的值应该是 "1" 或 "9"，具体取决于 $s[0]$ 的值。如果 $s[0]$ 是 "1"，那么 $s[1]$ 的值应该是 "1"，否则 $s[1]$ 的值应该是 "9"。
-   如果 $s[3]$ 是 "?"，那么 $s[3]$ 的值应该是 "5"。
-   如果 $s[4]$ 是 "?"，那么 $s[4]$ 的值应该是 "9"。

时间复杂度 $O(1)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findLatestTime(self, s: str) -> str:
        s = list(s)
        if s[0] == "?":
            s[0] = "1" if s[1] == "?" or s[1] < "2" else "0"
        if s[1] == "?":
            s[1] = "1" if s[0] == "1" else "9"
        if s[3] == "?":
            s[3] = "5"
        if s[4] == "?":
            s[4] = "9"
        return "".join(s)
```

#### Java

```java
class Solution {
    public String findLatestTime(String s) {
        char[] cs = s.toCharArray();
        if (cs[0] == '?') {
            cs[0] = cs[1] == '?' || cs[1] < '2' ? '1' : '0';
        }
        if (cs[1] == '?') {
            cs[1] = cs[0] == '1' ? '1' : '9';
        }
        if (cs[3] == '?') {
            cs[3] = '5';
        }
        if (cs[4] == '?') {
            cs[4] = '9';
        }
        return new String(cs);
    }
}
```

#### C++

```cpp
class Solution {
public:
    string findLatestTime(string s) {
        if (s[0] == '?') {
            s[0] = s[1] == '?' || s[1] < '2' ? '1' : '0';
        }
        if (s[1] == '?') {
            s[1] = s[0] == '1' ? '1' : '9';
        }
        if (s[3] == '?') {
            s[3] = '5';
        }
        if (s[4] == '?') {
            s[4] = '9';
        }
        return s;
    }
};
```

#### Go

```go
func findLatestTime(s string) string {
	cs := []byte(s)
	if cs[0] == '?' {
		if cs[1] == '?' || cs[1] < '2' {
			cs[0] = '1'
		} else {
			cs[0] = '0'
		}
	}
	if cs[1] == '?' {
		if cs[0] == '1' {
			cs[1] = '1'
		} else {
			cs[1] = '9'
		}
	}
	if cs[3] == '?' {
		cs[3] = '5'
	}
	if cs[4] == '?' {
		cs[4] = '9'
	}
	return string(cs)
}
```

#### TypeScript

```ts
function findLatestTime(s: string): string {
    const cs = s.split('');
    if (cs[0] === '?') {
        cs[0] = cs[1] === '?' || cs[1] < '2' ? '1' : '0';
    }
    if (cs[1] === '?') {
        cs[1] = cs[0] === '1' ? '1' : '9';
    }
    if (cs[3] === '?') {
        cs[3] = '5';
    }
    if (cs[4] === '?') {
        cs[4] = '9';
    }
    return cs.join('');
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3115. 质数的最大距离](https://leetcode.cn/problems/maximum-prime-difference){#3115}

{{< tabs "3115" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumPrimeDifference(self, nums: List[int]) -> int:
        def is_prime(x: int) -> bool:
            if x < 2:
                return False
            return all(x % i for i in range(2, int(sqrt(x)) + 1))

        for i, x in enumerate(nums):
            if is_prime(x):
                for j in range(len(nums) - 1, i - 1, -1):
                    if is_prime(nums[j]):
                        return j - i
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maximumPrimeDifference(int[] nums) {
        for (int i = 0;; ++i) {
            if (isPrime(nums[i])) {
                for (int j = nums.length - 1;; --j) {
                    if (isPrime(nums[j])) {
                        return j - i;
                    }
                }
            }
        }
    }

    private boolean isPrime(int x) {
        if (x < 2) {
            return false;
        }
        for (int v = 2; v * v <= x; ++v) {
            if (x % v == 0) {
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
    int maximumPrimeDifference(vector<int>& nums) {
        for (int i = 0;; ++i) {
            if (isPrime(nums[i])) {
                for (int j = nums.size() - 1;; --j) {
                    if (isPrime(nums[j])) {
                        return j - i;
                    }
                }
            }
        }
    }

    bool isPrime(int n) {
        if (n < 2) {
            return false;
        }
        for (int i = 2; i <= n / i; ++i) {
            if (n % i == 0) {
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
func maximumPrimeDifference(nums []int) int {
	for i := 0; ; i++ {
		if isPrime(nums[i]) {
			for j := len(nums) - 1; ; j-- {
				if isPrime(nums[j]) {
					return j - i
				}
			}
		}
	}
}

func isPrime(n int) bool {
	if n < 2 {
		return false
	}
	for i := 2; i <= n/i; i++ {
		if n%i == 0 {
			return false
		}
	}
	return true
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumPrimeDifference(nums: number[]): number {
    const isPrime = (x: number): boolean => {
        if (x < 2) {
            return false;
        }
        for (let i = 2; i <= x / i; i++) {
            if (x % i === 0) {
                return false;
            }
        }
        return true;
    };
    for (let i = 0; ; ++i) {
        if (isPrime(nums[i])) {
            for (let j = nums.length - 1; ; --j) {
                if (isPrime(nums[j])) {
                    return j - i;
                }
            }
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

<p>给你一个整数数组 <code>nums</code>。</p>

<p>返回两个（不一定不同的）质数在 <code>nums</code> 中&nbsp;<strong>下标</strong> 的 <strong>最大距离</strong>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">nums = [4,2,9,5,3]</span></p>

<p><strong>输出：</strong> <span class="example-io">3</span></p>

<p><strong>解释：</strong> <code>nums[1]</code>、<code>nums[3]</code> 和 <code>nums[4]</code> 是质数。因此答案是 <code>|4 - 1| = 3</code>。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">nums = [4,8,2,8]</span></p>

<p><strong>输出：</strong> <span class="example-io">0</span></p>

<p><strong>解释：</strong> <code>nums[2]</code> 是质数。因为只有一个质数，所以答案是 <code>|2 - 2| = 0</code>。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 3 * 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 100</code></li>
	<li>输入保证 <code>nums</code> 中至少有一个质数。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：遍历

根据题目描述，我们需要找出第一个质数所在的下标 $i$，然后找出最后一个质数所在的下标 $j$，将 $j - i$ 作为答案返回即可。

因此，我们可以从左到右遍历数组，找到第一个质数所在的下标 $i$，然后从右到左遍历数组，找到最后一个质数所在的下标 $j$，答案即为 $j - i$。

时间复杂度 $O(n \times \sqrt{M})$，其中 $n$ 和 $M$ 分别是数组 $nums$ 的长度和数组中的最大值。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumPrimeDifference(self, nums: List[int]) -> int:
        def is_prime(x: int) -> bool:
            if x < 2:
                return False
            return all(x % i for i in range(2, int(sqrt(x)) + 1))

        for i, x in enumerate(nums):
            if is_prime(x):
                for j in range(len(nums) - 1, i - 1, -1):
                    if is_prime(nums[j]):
                        return j - i
```

#### Java

```java
class Solution {
    public int maximumPrimeDifference(int[] nums) {
        for (int i = 0;; ++i) {
            if (isPrime(nums[i])) {
                for (int j = nums.length - 1;; --j) {
                    if (isPrime(nums[j])) {
                        return j - i;
                    }
                }
            }
        }
    }

    private boolean isPrime(int x) {
        if (x < 2) {
            return false;
        }
        for (int v = 2; v * v <= x; ++v) {
            if (x % v == 0) {
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
    int maximumPrimeDifference(vector<int>& nums) {
        for (int i = 0;; ++i) {
            if (isPrime(nums[i])) {
                for (int j = nums.size() - 1;; --j) {
                    if (isPrime(nums[j])) {
                        return j - i;
                    }
                }
            }
        }
    }

    bool isPrime(int n) {
        if (n < 2) {
            return false;
        }
        for (int i = 2; i <= n / i; ++i) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
};
```

#### Go

```go
func maximumPrimeDifference(nums []int) int {
	for i := 0; ; i++ {
		if isPrime(nums[i]) {
			for j := len(nums) - 1; ; j-- {
				if isPrime(nums[j]) {
					return j - i
				}
			}
		}
	}
}

func isPrime(n int) bool {
	if n < 2 {
		return false
	}
	for i := 2; i <= n/i; i++ {
		if n%i == 0 {
			return false
		}
	}
	return true
}
```

#### TypeScript

```ts
function maximumPrimeDifference(nums: number[]): number {
    const isPrime = (x: number): boolean => {
        if (x < 2) {
            return false;
        }
        for (let i = 2; i <= x / i; i++) {
            if (x % i === 0) {
                return false;
            }
        }
        return true;
    };
    for (let i = 0; ; ++i) {
        if (isPrime(nums[i])) {
            for (let j = nums.length - 1; ; --j) {
                if (isPrime(nums[j])) {
                    return j - i;
                }
            }
        }
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3116. 单面值组合的第 K 小金额](https://leetcode.cn/problems/kth-smallest-amount-with-single-denomination-combination){#3116}

{{< tabs "3116" >}}

{{% tab "python" %}}
```python
class Solution:
    def findKthSmallest(self, coins: List[int], k: int) -> int:
        def check(mx: int) -> bool:
            cnt = 0
            for i in range(1, 1 << len(coins)):
                v = 1
                for j, x in enumerate(coins):
                    if i >> j & 1:
                        v = lcm(v, x)
                        if v > mx:
                            break
                m = i.bit_count()
                if m & 1:
                    cnt += mx // v
                else:
                    cnt -= mx // v
            return cnt >= k

        return bisect_left(range(10**11), True, key=check)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[] coins;
    private int k;

    public long findKthSmallest(int[] coins, int k) {
        this.coins = coins;
        this.k = k;
        long l = 1, r = (long) 1e11;
        while (l < r) {
            long mid = (l + r) >> 1;
            if (check(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }

    private boolean check(long mx) {
        long cnt = 0;
        int n = coins.length;
        for (int i = 1; i < 1 << n; ++i) {
            long v = 1;
            for (int j = 0; j < n; ++j) {
                if ((i >> j & 1) == 1) {
                    v = lcm(v, coins[j]);
                    if (v > mx) {
                        break;
                    }
                }
            }
            int m = Integer.bitCount(i);
            if (m % 2 == 1) {
                cnt += mx / v;
            } else {
                cnt -= mx / v;
            }
        }
        return cnt >= k;
    }

    private long lcm(long a, long b) {
        return a * b / gcd(a, b);
    }

    private long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        using ll = long long;
        ll l = 1, r = 1e11;
        int n = coins.size();

        auto check = [&](ll mx) {
            ll cnt = 0;
            for (int i = 1; i < 1 << n; ++i) {
                ll v = 1;
                for (int j = 0; j < n; ++j) {
                    if (i >> j & 1) {
                        v = lcm(v, coins[j]);
                        if (v > mx) {
                            break;
                        }
                    }
                }
                int m = __builtin_popcount(i);
                if (m & 1) {
                    cnt += mx / v;
                } else {
                    cnt -= mx / v;
                }
            }
            return cnt >= k;
        };

        while (l < r) {
            ll mid = (l + r) >> 1;
            if (check(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findKthSmallest(coins []int, k int) int64 {
	var r int = 1e11
	n := len(coins)
	ans := sort.Search(r, func(mx int) bool {
		cnt := 0
		for i := 1; i < 1<<n; i++ {
			v := 1
			for j, x := range coins {
				if i>>j&1 == 1 {
					v = lcm(v, x)
					if v > mx {
						break
					}
				}
			}
			m := bits.OnesCount(uint(i))
			if m%2 == 1 {
				cnt += mx / v
			} else {
				cnt -= mx / v
			}
		}
		return cnt >= k
	})
	return int64(ans)
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func lcm(a, b int) int {
	return a * b / gcd(a, b)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findKthSmallest(coins: number[], k: number): number {
    let [l, r] = [1n, BigInt(1e11)];
    const n = coins.length;
    const check = (mx: bigint): boolean => {
        let cnt = 0n;
        for (let i = 1; i < 1 << n; ++i) {
            let v = 1n;
            for (let j = 0; j < n; ++j) {
                if ((i >> j) & 1) {
                    v = lcm(v, BigInt(coins[j]));
                    if (v > mx) {
                        break;
                    }
                }
            }
            const m = bitCount(i);
            if (m & 1) {
                cnt += mx / v;
            } else {
                cnt -= mx / v;
            }
        }
        return cnt >= BigInt(k);
    };
    while (l < r) {
        const mid = (l + r) >> 1n;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1n;
        }
    }
    return Number(l);
}

function gcd(a: bigint, b: bigint): bigint {
    return b === 0n ? a : gcd(b, a % b);
}

function lcm(a: bigint, b: bigint): bigint {
    return (a * b) / gcd(a, b);
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

<p>给你一个整数数组 <code>coins</code> 表示不同面额的硬币，另给你一个整数 <code>k</code> 。</p>

<p>你有无限量的每种面额的硬币。但是，你<strong> 不能 </strong>组合使用不同面额的硬币。</p>

<p>返回使用这些硬币能制造的<strong> 第 </strong><code>k<sup>th</sup></code><strong> 小</strong> 金额。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block" style="
    border-color: var(--border-tertiary);
    border-left-width: 2px;
    color: var(--text-secondary);
    font-size: .875rem;
    margin-bottom: 1rem;
    margin-top: 1rem;
    overflow: visible;
    padding-left: 1rem;">
<p><strong>输入：</strong> <span class="example-io" style="
    font-family: Menlo,sans-serif;
    font-size: 0.85rem;">coins = [3,6,9], k = 3</span></p>

<p><strong>输出：</strong> <span class="example-io" style="
    font-family: Menlo,sans-serif;
    font-size: 0.85rem;">9</span></p>

<p><strong>解释：</strong>给定的硬币可以制造以下金额：<br />
3元硬币产生3的倍数：3, 6, 9, 12, 15等。<br />
6元硬币产生6的倍数：6, 12, 18, 24等。<br />
9元硬币产生9的倍数：9, 18, 27, 36等。<br />
所有硬币合起来可以产生：3, 6, <u><strong>9</strong></u>, 12, 15等。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block" style="
    border-color: var(--border-tertiary);
    border-left-width: 2px;
    color: var(--text-secondary);
    font-size: .875rem;
    margin-bottom: 1rem;
    margin-top: 1rem;
    overflow: visible;
    padding-left: 1rem;">
<p><strong>输入：</strong><span class="example-io" style="
    font-family: Menlo,sans-serif;
    font-size: 0.85rem;">coins = [5,2], k = 7</span></p>

<p><strong>输出：</strong><span class="example-io" style="
    font-family: Menlo,sans-serif;
    font-size: 0.85rem;">12</span></p>

<p><strong>解释：</strong>给定的硬币可以制造以下金额：<br />
5元硬币产生5的倍数：5, 10, 15, 20等。<br />
2元硬币产生2的倍数：2, 4, 6, 8, 10, 12等。<br />
所有硬币合起来可以产生：2, 4, 5, 6, 8, 10, <u><strong>12</strong></u>, 14, 15等。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= coins.length &lt;= 15</code></li>
	<li><code>1 &lt;= coins[i] &lt;= 25</code></li>
	<li><code>1 &lt;= k &lt;= 2 * 10<sup>9</sup></code></li>
	<li><code>coins</code> 包含两两不同的整数。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二分查找 + 容斥原理

我们可以将题目转化为：找到最小的正整数 $x$，使得小于等于 $x$ 的且满足条件的数的个数恰好为 $k$ 个。如果 $x$ 满足条件，那么对任意 $x' > x$ 的 $x'$ 也满足条件，这存在单调性，因此我们可以使用二分查找，找到最小的满足条件的 $x$。

我们定义一个函数 `check(x)`，用来判断小于等于 $x$ 的且满足条件的数的个数是否大于等于 $k$。我们需要计算有多少个数可以由 $coins$ 中的数组合得到。

假设 $coins$ 为 $[a, b]$，根据容斥原理，小于等于 $x$ 的满足条件的数的个数为：

$$
\left\lfloor \frac{x}{a} \right\rfloor + \left\lfloor \frac{x}{b} \right\rfloor - \left\lfloor \frac{x}{lcm(a, b)} \right\rfloor
$$

如果 $coins$ 为 $[a, b, c]$，小于等于 $x$ 的满足条件的数的个数为：

$$
\left\lfloor \frac{x}{a} \right\rfloor + \left\lfloor \frac{x}{b} \right\rfloor + \left\lfloor \frac{x}{c} \right\rfloor - \left\lfloor \frac{x}{lcm(a, b)} \right\rfloor - \left\lfloor \frac{x}{lcm(a, c)} \right\rfloor - \left\lfloor \frac{x}{lcm(b, c)} \right\rfloor + \left\lfloor \frac{x}{lcm(a, b, c)} \right\rfloor
$$

可以看到，我们需要累加所有任意奇数个数的情况，减去所有任意偶数个数的情况。

由于 $n \leq 15$，我们可以使用二进制枚举的方式，枚举所有的子集，计算满足条件的数的个数，我们记为 $cnt$。如果 $cnt \geq k$，那么我们需要找到最小的 $x$，使得 $check(x)$ 为真。

在二分查找开始时，我们定义二分查找的左边界 $l=1$，右边界 $r={10}^{11}$，然后我们不断地将中间值 $mid$ 代入 `check` 函数中，如果 `check(mid)` 为真，那么我们将右边界 $r$ 更新为 $mid$，否则我们将左边界 $l$ 更新为 $mid+1$。最终返回 $l$。

时间复杂度 $O(n \times 2^n \times \log (k \times M))$，其中 $n$ 是数组 $coins$ 的长度，而 $M$ 是数组 $coins$ 中的最大值。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findKthSmallest(self, coins: List[int], k: int) -> int:
        def check(mx: int) -> bool:
            cnt = 0
            for i in range(1, 1 << len(coins)):
                v = 1
                for j, x in enumerate(coins):
                    if i >> j & 1:
                        v = lcm(v, x)
                        if v > mx:
                            break
                m = i.bit_count()
                if m & 1:
                    cnt += mx // v
                else:
                    cnt -= mx // v
            return cnt >= k

        return bisect_left(range(10**11), True, key=check)
```

#### Java

```java
class Solution {
    private int[] coins;
    private int k;

    public long findKthSmallest(int[] coins, int k) {
        this.coins = coins;
        this.k = k;
        long l = 1, r = (long) 1e11;
        while (l < r) {
            long mid = (l + r) >> 1;
            if (check(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }

    private boolean check(long mx) {
        long cnt = 0;
        int n = coins.length;
        for (int i = 1; i < 1 << n; ++i) {
            long v = 1;
            for (int j = 0; j < n; ++j) {
                if ((i >> j & 1) == 1) {
                    v = lcm(v, coins[j]);
                    if (v > mx) {
                        break;
                    }
                }
            }
            int m = Integer.bitCount(i);
            if (m % 2 == 1) {
                cnt += mx / v;
            } else {
                cnt -= mx / v;
            }
        }
        return cnt >= k;
    }

    private long lcm(long a, long b) {
        return a * b / gcd(a, b);
    }

    private long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        using ll = long long;
        ll l = 1, r = 1e11;
        int n = coins.size();

        auto check = [&](ll mx) {
            ll cnt = 0;
            for (int i = 1; i < 1 << n; ++i) {
                ll v = 1;
                for (int j = 0; j < n; ++j) {
                    if (i >> j & 1) {
                        v = lcm(v, coins[j]);
                        if (v > mx) {
                            break;
                        }
                    }
                }
                int m = __builtin_popcount(i);
                if (m & 1) {
                    cnt += mx / v;
                } else {
                    cnt -= mx / v;
                }
            }
            return cnt >= k;
        };

        while (l < r) {
            ll mid = (l + r) >> 1;
            if (check(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
```

#### Go

```go
func findKthSmallest(coins []int, k int) int64 {
	var r int = 1e11
	n := len(coins)
	ans := sort.Search(r, func(mx int) bool {
		cnt := 0
		for i := 1; i < 1<<n; i++ {
			v := 1
			for j, x := range coins {
				if i>>j&1 == 1 {
					v = lcm(v, x)
					if v > mx {
						break
					}
				}
			}
			m := bits.OnesCount(uint(i))
			if m%2 == 1 {
				cnt += mx / v
			} else {
				cnt -= mx / v
			}
		}
		return cnt >= k
	})
	return int64(ans)
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func lcm(a, b int) int {
	return a * b / gcd(a, b)
}
```

#### TypeScript

```ts
function findKthSmallest(coins: number[], k: number): number {
    let [l, r] = [1n, BigInt(1e11)];
    const n = coins.length;
    const check = (mx: bigint): boolean => {
        let cnt = 0n;
        for (let i = 1; i < 1 << n; ++i) {
            let v = 1n;
            for (let j = 0; j < n; ++j) {
                if ((i >> j) & 1) {
                    v = lcm(v, BigInt(coins[j]));
                    if (v > mx) {
                        break;
                    }
                }
            }
            const m = bitCount(i);
            if (m & 1) {
                cnt += mx / v;
            } else {
                cnt -= mx / v;
            }
        }
        return cnt >= BigInt(k);
    };
    while (l < r) {
        const mid = (l + r) >> 1n;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1n;
        }
    }
    return Number(l);
}

function gcd(a: bigint, b: bigint): bigint {
    return b === 0n ? a : gcd(b, a % b);
}

function lcm(a: bigint, b: bigint): bigint {
    return (a * b) / gcd(a, b);
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

# [3117. 划分数组得到最小的值之和](https://leetcode.cn/problems/minimum-sum-of-values-by-dividing-array){#3117}

{{< tabs "3117" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumValueSum(self, nums: List[int], andValues: List[int]) -> int:
        @cache
        def dfs(i: int, j: int, a: int) -> int:
            if n - i < m - j:
                return inf
            if j == m:
                return 0 if i == n else inf
            a &= nums[i]
            if a < andValues[j]:
                return inf
            ans = dfs(i + 1, j, a)
            if a == andValues[j]:
                ans = min(ans, dfs(i + 1, j + 1, -1) + nums[i])
            return ans

        n, m = len(nums), len(andValues)
        ans = dfs(0, 0, -1)
        return ans if ans < inf else -1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[] nums;
    private int[] andValues;
    private final int inf = 1 << 29;
    private Map<Long, Integer> f = new HashMap<>();

    public int minimumValueSum(int[] nums, int[] andValues) {
        this.nums = nums;
        this.andValues = andValues;
        int ans = dfs(0, 0, -1);
        return ans >= inf ? -1 : ans;
    }

    private int dfs(int i, int j, int a) {
        if (nums.length - i < andValues.length - j) {
            return inf;
        }
        if (j == andValues.length) {
            return i == nums.length ? 0 : inf;
        }
        a &= nums[i];
        if (a < andValues[j]) {
            return inf;
        }
        long key = (long) i << 36 | (long) j << 32 | a;
        if (f.containsKey(key)) {
            return f.get(key);
        }

        int ans = dfs(i + 1, j, a);
        if (a == andValues[j]) {
            ans = Math.min(ans, dfs(i + 1, j + 1, -1) + nums[i]);
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
    int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
        this->nums = nums;
        this->andValues = andValues;
        n = nums.size();
        m = andValues.size();
        int ans = dfs(0, 0, -1);
        return ans >= inf ? -1 : ans;
    }

private:
    vector<int> nums;
    vector<int> andValues;
    int n;
    int m;
    const int inf = 1 << 29;
    unordered_map<long long, int> f;

    int dfs(int i, int j, int a) {
        if (n - i < m - j) {
            return inf;
        }
        if (j == m) {
            return i == n ? 0 : inf;
        }
        a &= nums[i];
        if (a < andValues[j]) {
            return inf;
        }
        long long key = (long long) i << 36 | (long long) j << 32 | a;
        if (f.contains(key)) {
            return f[key];
        }
        int ans = dfs(i + 1, j, a);
        if (a == andValues[j]) {
            ans = min(ans, dfs(i + 1, j + 1, -1) + nums[i]);
        }
        return f[key] = ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumValueSum(nums []int, andValues []int) int {
	n, m := len(nums), len(andValues)
	f := map[int]int{}
	const inf int = 1 << 29
	var dfs func(i, j, a int) int
	dfs = func(i, j, a int) int {
		if n-i < m-j {
			return inf
		}
		if j == m {
			if i == n {
				return 0
			}
			return inf
		}
		a &= nums[i]
		if a < andValues[j] {
			return inf
		}
		key := i<<36 | j<<32 | a
		if v, ok := f[key]; ok {
			return v
		}
		ans := dfs(i+1, j, a)
		if a == andValues[j] {
			ans = min(ans, dfs(i+1, j+1, -1)+nums[i])
		}
		f[key] = ans
		return ans
	}
	if ans := dfs(0, 0, -1); ans < inf {
		return ans
	}
	return -1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumValueSum(nums: number[], andValues: number[]): number {
    const [n, m] = [nums.length, andValues.length];
    const f: Map<bigint, number> = new Map();
    const dfs = (i: number, j: number, a: number): number => {
        if (n - i < m - j) {
            return Infinity;
        }
        if (j === m) {
            return i === n ? 0 : Infinity;
        }
        a &= nums[i];
        if (a < andValues[j]) {
            return Infinity;
        }
        const key = (BigInt(i) << 36n) | (BigInt(j) << 32n) | BigInt(a);
        if (f.has(key)) {
            return f.get(key)!;
        }
        let ans = dfs(i + 1, j, a);
        if (a === andValues[j]) {
            ans = Math.min(ans, dfs(i + 1, j + 1, -1) + nums[i]);
        }
        f.set(key, ans);
        return ans;
    };
    const ans = dfs(0, 0, -1);
    return ans >= Infinity ? -1 : ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个数组 <code>nums</code> 和 <code>andValues</code>，长度分别为 <code>n</code> 和 <code>m</code>。</p>

<p>数组的 <strong>值 </strong>等于该数组的 <strong>最后一个 </strong>元素。</p>

<p>你需要将 <code>nums</code> 划分为 <code>m</code> 个 <strong>不相交的连续 </strong><span data-keyword="subarray-nonempty">子数组</span>，对于第 <code>i<sup>th</sup></code> 个子数组 <code>[l<sub>i</sub>, r<sub>i</sub>]</code>，子数组元素的按位&nbsp;<code>AND</code>&nbsp;运算结果等于 <code>andValues[i]</code>，换句话说，对所有的 <code>1 &lt;= i &lt;= m</code>，<code>nums[l<sub>i</sub>] &amp; nums[l<sub>i</sub> + 1] &amp; ... &amp; nums[r<sub>i</sub>] == andValues[i]</code> ，其中 <code>&amp;</code> 表示按位&nbsp;<code>AND</code>&nbsp;运算符。</p>

<p>返回将 <code>nums</code> 划分为 <code>m</code> 个子数组所能得到的可能的 <strong>最小 </strong>子数组 <strong>值</strong> 之和。如果无法完成这样的划分，则返回 <code>-1</code> 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">nums = [1,4,3,3,2], andValues = [0,3,3,2]</span></p>

<p><strong>输出：</strong> <span class="example-io">12</span></p>

<p><strong>解释：</strong></p>

<p>唯一可能的划分方法为：</p>

<ol>
	<li><code>[1,4]</code> 因为 <code>1 &amp; 4 == 0</code></li>
	<li><code>[3]</code> 因为单元素子数组的按位 <code>AND</code> 结果就是该元素本身</li>
	<li><code>[3]</code> 因为单元素子数组的按位 <code>AND</code> 结果就是该元素本身</li>
	<li><code>[2]</code> 因为单元素子数组的按位 <code>AND</code> 结果就是该元素本身</li>
</ol>

<p>这些子数组的值之和为 <code>4 + 3 + 3 + 2 = 12</code></p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">nums = [2,3,5,7,7,7,5], andValues = [0,7,5]</span></p>

<p><strong>输出：</strong> <span class="example-io">17</span></p>

<p><strong>解释：</strong></p>

<p>划分 <code>nums</code> 的三种方式为：</p>

<ol>
	<li><code>[[2,3,5],[7,7,7],[5]]</code> 其中子数组的值之和为 <code>5 + 7 + 5 = 17</code></li>
	<li><code>[[2,3,5,7],[7,7],[5]]</code> 其中子数组的值之和为 <code>7 + 7 + 5 = 19</code></li>
	<li><code>[[2,3,5,7,7],[7],[5]]</code> 其中子数组的值之和为 <code>7 + 7 + 5 = 19</code></li>
</ol>

<p>子数组值之和的最小可能值为 <code>17</code></p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">nums = [1,2,3,4], andValues = [2]</span></p>

<p><strong>输出：</strong> <span class="example-io">-1</span></p>

<p><strong>解释：</strong></p>

<p>整个数组 <code>nums</code> 的按位 <code>AND</code> 结果为 <code>0</code>。由于无法将 <code>nums</code> 划分为单个子数组使得元素的按位 <code>AND</code> 结果为 <code>2</code>，因此返回 <code>-1</code>。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n == nums.length &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= m == andValues.length &lt;= min(n, 10)</code></li>
	<li><code>1 &lt;= nums[i] &lt; 10<sup>5</sup></code></li>
	<li><code>0 &lt;= andValues[j] &lt; 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

我们设计一个函数 $dfs(i, j, a)$，表示从第 $i$ 个元素开始，当前已经划分了 $j$ 个子数组，且当前待划分的子数组的按位与结果为 $a$ 的情况下，所能得到的可能的最小子数组值之和。那么答案就是 $dfs(0, 0, -1)$。

函数 $dfs(i, j, a)$ 的执行过程如下：

-   如果 $n - i < m - j$，那么说明剩下的元素不足以划分出 $m - j$ 个子数组，返回 $+\infty$。
-   如果 $j = m$，那么说明已经划分出了 $m$ 个子数组，此时判断 $i = n$ 是否成立，如果成立返回 $0$，否则返回 $+\infty$。
-   否则，我们将 $a$ 与 $nums[i]$ 进行按位与操作，得到新的 $a$。如果 $a < andValues[j]$，那么说明当前待划分的子数组的按位与结果不满足要求，返回 $+\infty$。否则，我们有两种选择：
    -   不划分当前元素，即 $dfs(i + 1, j, a)$。
    -   划分当前元素，即 $dfs(i + 1, j + 1, -1) + nums[i]$。
-   返回上述两种选择的最小值。

为了避免重复计算，我们使用记忆化搜索的方法，将 $dfs(i, j, a)$ 的结果存储在一个哈希表中。

时间复杂度 $O(n \times m \times \log M)$，空间复杂度 $O(n \times m \times \log M)$。其中 $n$ 和 $m$ 分别是数组 $nums$ 和 $andValues$ 的长度；而 $M$ 是数组 $nums$ 中的最大值，本题中 $M \leq 10^5$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumValueSum(self, nums: List[int], andValues: List[int]) -> int:
        @cache
        def dfs(i: int, j: int, a: int) -> int:
            if n - i < m - j:
                return inf
            if j == m:
                return 0 if i == n else inf
            a &= nums[i]
            if a < andValues[j]:
                return inf
            ans = dfs(i + 1, j, a)
            if a == andValues[j]:
                ans = min(ans, dfs(i + 1, j + 1, -1) + nums[i])
            return ans

        n, m = len(nums), len(andValues)
        ans = dfs(0, 0, -1)
        return ans if ans < inf else -1
```

#### Java

```java
class Solution {
    private int[] nums;
    private int[] andValues;
    private final int inf = 1 << 29;
    private Map<Long, Integer> f = new HashMap<>();

    public int minimumValueSum(int[] nums, int[] andValues) {
        this.nums = nums;
        this.andValues = andValues;
        int ans = dfs(0, 0, -1);
        return ans >= inf ? -1 : ans;
    }

    private int dfs(int i, int j, int a) {
        if (nums.length - i < andValues.length - j) {
            return inf;
        }
        if (j == andValues.length) {
            return i == nums.length ? 0 : inf;
        }
        a &= nums[i];
        if (a < andValues[j]) {
            return inf;
        }
        long key = (long) i << 36 | (long) j << 32 | a;
        if (f.containsKey(key)) {
            return f.get(key);
        }

        int ans = dfs(i + 1, j, a);
        if (a == andValues[j]) {
            ans = Math.min(ans, dfs(i + 1, j + 1, -1) + nums[i]);
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
    int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
        this->nums = nums;
        this->andValues = andValues;
        n = nums.size();
        m = andValues.size();
        int ans = dfs(0, 0, -1);
        return ans >= inf ? -1 : ans;
    }

private:
    vector<int> nums;
    vector<int> andValues;
    int n;
    int m;
    const int inf = 1 << 29;
    unordered_map<long long, int> f;

    int dfs(int i, int j, int a) {
        if (n - i < m - j) {
            return inf;
        }
        if (j == m) {
            return i == n ? 0 : inf;
        }
        a &= nums[i];
        if (a < andValues[j]) {
            return inf;
        }
        long long key = (long long) i << 36 | (long long) j << 32 | a;
        if (f.contains(key)) {
            return f[key];
        }
        int ans = dfs(i + 1, j, a);
        if (a == andValues[j]) {
            ans = min(ans, dfs(i + 1, j + 1, -1) + nums[i]);
        }
        return f[key] = ans;
    }
};
```

#### Go

```go
func minimumValueSum(nums []int, andValues []int) int {
	n, m := len(nums), len(andValues)
	f := map[int]int{}
	const inf int = 1 << 29
	var dfs func(i, j, a int) int
	dfs = func(i, j, a int) int {
		if n-i < m-j {
			return inf
		}
		if j == m {
			if i == n {
				return 0
			}
			return inf
		}
		a &= nums[i]
		if a < andValues[j] {
			return inf
		}
		key := i<<36 | j<<32 | a
		if v, ok := f[key]; ok {
			return v
		}
		ans := dfs(i+1, j, a)
		if a == andValues[j] {
			ans = min(ans, dfs(i+1, j+1, -1)+nums[i])
		}
		f[key] = ans
		return ans
	}
	if ans := dfs(0, 0, -1); ans < inf {
		return ans
	}
	return -1
}
```

#### TypeScript

```ts
function minimumValueSum(nums: number[], andValues: number[]): number {
    const [n, m] = [nums.length, andValues.length];
    const f: Map<bigint, number> = new Map();
    const dfs = (i: number, j: number, a: number): number => {
        if (n - i < m - j) {
            return Infinity;
        }
        if (j === m) {
            return i === n ? 0 : Infinity;
        }
        a &= nums[i];
        if (a < andValues[j]) {
            return Infinity;
        }
        const key = (BigInt(i) << 36n) | (BigInt(j) << 32n) | BigInt(a);
        if (f.has(key)) {
            return f.get(key)!;
        }
        let ans = dfs(i + 1, j, a);
        if (a === andValues[j]) {
            ans = Math.min(ans, dfs(i + 1, j + 1, -1) + nums[i]);
        }
        f.set(key, ans);
        return ans;
    };
    const ans = dfs(0, 0, -1);
    return ans >= Infinity ? -1 : ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3118. 发生在周五的交易 III 🔒](https://leetcode.cn/problems/friday-purchase-iii){#3118}

{{< tabs "3118" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH RECURSIVE
    T AS (
        SELECT 1 AS week_of_month
        UNION
        SELECT week_of_month + 1
        FROM T
        WHERE week_of_month < 4
    ),
    M AS (
        SELECT 'Premium' AS membership
        UNION
        SELECT 'VIP'
    ),
    P AS (
        SELECT CEIL(DAYOFMONTH(purchase_date) / 7) AS week_of_month, membership, amount_spend
        FROM
            Purchases
            JOIN Users USING (user_id)
        WHERE DAYOFWEEK(purchase_date) = 6
    )
SELECT week_of_month, membership, IFNULL(SUM(amount_spend), 0) AS total_amount
FROM
    T
    JOIN M
    LEFT JOIN P USING (week_of_month, membership)
GROUP BY 1, 2
ORDER BY 1, 2;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code>Purchases</code></p>

<pre>
+---------------+------+
| Column Name   | Type |
+---------------+------+
| user_id       | int  |
| purchase_date | date |
| amount_spend  | int  |
+---------------+------+
(user_id, purchase_date, amount_spend) 是该表的主键(具有唯一值的列)。
purchase_date 的范围从 2023 年 11 月 1 日到 2023 年 11 月 30 日，并包括这两个日期。
每一行包含 user_id, purchase_date，和 amount_spend。
</pre>

<p>表：<code>Users</code></p>

<pre>
+-------------+------+
| Column Name | Type |
+-------------+------+
| user_id     | int  |
| membership  | enum |
+-------------+------+
user_id 是这张表的主键。
membership 是 ('Standard', 'Premium', 'VIP') 的枚举类型。
这张表的每一行表示 user_id 和会员类型。
</pre>

<p>编写一个解决方案来计算&nbsp;<code>Premium</code>&nbsp;和&nbsp;<code>VIP</code>&nbsp;会员在 2023 年 11 月&nbsp;<strong>每周的周五</strong>&nbsp;的 <strong>总花费</strong>。如果某个周五没有&nbsp;<code>Premium</code> 或&nbsp;<code>VIP</code> 会员购买，把它当作&nbsp;<code>0</code>。</p>

<p>按照每月的周次序&nbsp;<strong>升序</strong>&nbsp;排列结果表，然后以&nbsp;<code>membership</code>&nbsp;<strong>升序&nbsp;</strong>排序。</p>

<p>结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong class="example">示例：</strong></p>

<div class="example-block">
<p><strong>输入：</strong></p>

<p>Purchases 表：</p>

<pre class="example-io">
+---------+---------------+--------------+
| user_id | purchase_date | amount_spend |
+---------+---------------+--------------+
| 11      | 2023-11-03    | 1126         |
| 15      | 2023-11-10    | 7473         |
| 17      | 2023-11-17    | 2414         |
| 12      | 2023-11-24    | 9692         |
| 8       | 2023-11-24    | 5117         |
| 1       | 2023-11-24    | 5241         |
| 10      | 2023-11-22    | 8266         |
| 13      | 2023-11-21    | 12000        |
+---------+---------------+--------------+
</pre>

<p>Users 表：</p>

<pre class="example-io">
+---------+------------+
| user_id | membership |
+---------+------------+
| 11      | Premium    |
| 15      | VIP        |
| 17      | Standard   |
| 12      | VIP        |
| 8       | Premium    |
| 1       | VIP        |
| 10      | Standard   |
| 13      | Premium    |
+---------+------------+
</pre>

<p><strong>输出：</strong></p>

<pre class="example-io">
+---------------+-------------+--------------+
| week_of_month | membership  | total_amount |
+---------------+-------------+--------------+
| 1             | Premium     | 1126         |
| 1             | VIP         | 0            |
| 2             | Premium     | 0            |
| 2             | VIP         | 7473         |
| 3             | Premium     | 0            |
| 3             | VIP         | 0            |
| 4             | Premium     | 5117         |
| 4             | VIP         | 14933        |
+---------------+-------------+--------------+
        </pre>

<p><strong>解释：</strong></p>

<ul>
	<li>在 2023 年 11 月的第一周，周五有一笔交易，2023-11-03，由一个&nbsp;Premium 会员花费了 $1,126。这天没有 VIP 会员交易，所以值为 0。</li>
	<li>在 2023 年 11 月的第二周，周五有一笔交易，2023-11-10，由一个 VIP 会员花费了 $7,473。因为这条没有&nbsp;Premium 会员交易，Premium 会员的输出为 0。</li>
	<li>相似地，在 2023 年 11 月的第三周，周五没有&nbsp;Premium 或 VIP 会员交易，2023-11-17，所以这周两种分类都输出 0。</li>
	<li>在 2023 年 11 月的第四周，周五存在交易，2023-11-24，有一名 Premium 会员购买了 $5,117 以及 VIP 会员购买了总共 $14,933（一个花费 $9,692，另一个花费 $5,241）。</li>
</ul>

<p><strong>注意：</strong>输出表以&nbsp;week_of_month 和 membership 升序排序。</p>
</div>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：递归 + 连接

我们首先创建一个递归表 `T`，其中包含 `week_of_month` 列，表示月份的第几周。然后创建一个表 `M`，包含 `membership` 列，表示会员类型，取值为 `'Premium'` 和 `'VIP'`。

接着创建一个表 `P`，包含 `week_of_month`、`membership` 和 `amount_spend` 列，筛选出每个会员在每个月的第几周的周五的消费金额。最后，我们将 `T` 和 `M` 表连接，再左连接 `P` 表，并且按照 `week_of_month` 和 `membership` 列进行分组，计算每周每种会员的总消费金额。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
WITH RECURSIVE
    T AS (
        SELECT 1 AS week_of_month
        UNION
        SELECT week_of_month + 1
        FROM T
        WHERE week_of_month < 4
    ),
    M AS (
        SELECT 'Premium' AS membership
        UNION
        SELECT 'VIP'
    ),
    P AS (
        SELECT CEIL(DAYOFMONTH(purchase_date) / 7) AS week_of_month, membership, amount_spend
        FROM
            Purchases
            JOIN Users USING (user_id)
        WHERE DAYOFWEEK(purchase_date) = 6
    )
SELECT week_of_month, membership, IFNULL(SUM(amount_spend), 0) AS total_amount
FROM
    T
    JOIN M
    LEFT JOIN P USING (week_of_month, membership)
GROUP BY 1, 2
ORDER BY 1, 2;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3119. 最大数量的可修复坑洼 🔒](https://leetcode.cn/problems/maximum-number-of-potholes-that-can-be-fixed){#3119}

{{< tabs "3119" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxPotholes(self, road: str, budget: int) -> int:
        road += "."
        n = len(road)
        cnt = [0] * n
        k = 0
        for c in road:
            if c == "x":
                k += 1
            elif k:
                cnt[k] += 1
                k = 0
        ans = 0
        for k in range(n - 1, 0, -1):
            if cnt[k] == 0:
                continue
            t = min(budget // (k + 1), cnt[k])
            ans += t * k
            budget -= t * (k + 1)
            if budget == 0:
                break
            cnt[k - 1] += cnt[k] - t
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxPotholes(String road, int budget) {
        road += ".";
        int n = road.length();
        int[] cnt = new int[n];
        int k = 0;
        for (char c : road.toCharArray()) {
            if (c == 'x') {
                ++k;
            } else if (k > 0) {
                ++cnt[k];
                k = 0;
            }
        }
        int ans = 0;
        for (k = n - 1; k > 0 && budget > 0; --k) {
            int t = Math.min(budget / (k + 1), cnt[k]);
            ans += t * k;
            budget -= t * (k + 1);
            cnt[k - 1] += cnt[k] - t;
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
    int maxPotholes(string road, int budget) {
        road.push_back('.');
        int n = road.size();
        vector<int> cnt(n);
        int k = 0;
        for (char& c : road) {
            if (c == 'x') {
                ++k;
            } else if (k) {
                ++cnt[k];
                k = 0;
            }
        }
        int ans = 0;
        for (k = n - 1; k && budget; --k) {
            int t = min(budget / (k + 1), cnt[k]);
            ans += t * k;
            budget -= t * (k + 1);
            cnt[k - 1] += cnt[k] - t;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxPotholes(road string, budget int) (ans int) {
	road += "."
	n := len(road)
	cnt := make([]int, n)
	k := 0
	for _, c := range road {
		if c == 'x' {
			k++
		} else if k > 0 {
			cnt[k]++
			k = 0
		}
	}
	for k = n - 1; k > 0 && budget > 0; k-- {
		t := min(budget/(k+1), cnt[k])
		ans += t * k
		budget -= t * (k + 1)
		cnt[k-1] += cnt[k] - t
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxPotholes(road: string, budget: number): number {
    road += '.';
    const n = road.length;
    const cnt: number[] = Array(n).fill(0);
    let k = 0;
    for (const c of road) {
        if (c === 'x') {
            ++k;
        } else if (k) {
            ++cnt[k];
            k = 0;
        }
    }
    let ans = 0;
    for (k = n - 1; k && budget; --k) {
        const t = Math.min(Math.floor(budget / (k + 1)), cnt[k]);
        ans += t * k;
        budget -= t * (k + 1);
        cnt[k - 1] += cnt[k] - t;
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn max_potholes(road: String, budget: i32) -> i32 {
        let mut cs: Vec<char> = road.chars().collect();
        cs.push('.');
        let n = cs.len();
        let mut cnt: Vec<i32> = vec![0; n];
        let mut k = 0;

        for c in cs.iter() {
            if *c == 'x' {
                k += 1;
            } else if k > 0 {
                cnt[k] += 1;
                k = 0;
            }
        }

        let mut ans = 0;
        let mut budget = budget;

        for k in (1..n).rev() {
            if budget == 0 {
                break;
            }
            let t = std::cmp::min(budget / ((k as i32) + 1), cnt[k]);
            ans += t * (k as i32);
            budget -= t * ((k as i32) + 1);
            cnt[k - 1] += cnt[k] - t;
        }

        ans
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int MaxPotholes(string road, int budget) {
        road += '.';
        int n = road.Length;
        int[] cnt = new int[n];
        int k = 0;
        foreach (char c in road) {
            if (c == 'x') {
                ++k;
            } else if (k > 0) {
                ++cnt[k];
                k = 0;
            }
        }
        int ans = 0;
        for (k = n - 1; k > 0 && budget > 0; --k) {
            int t = Math.Min(budget / (k + 1), cnt[k]);
            ans += t * k;
            budget -= t * (k + 1);
            cnt[k - 1] += cnt[k] - t;
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

<p>给定一个字符串&nbsp;<code>road</code>，只包含字符&nbsp;<code>"x"</code>&nbsp;和&nbsp;<code>"."</code>，其中每个&nbsp;<code>"x"</code>&nbsp;代表一个坑洼，每个&nbsp;<code>"."</code>&nbsp;代表一个平滑的道路，以及一个整数&nbsp;<code>budget</code>。</p>

<p>在一次修复操作中，您可以以 <code>n + 1</code> 的价格修复 <code>n</code> 个连续坑洼。</p>

<p>返回可以修复的坑洼的 <strong>最大</strong> 数量，以便所有修复的价格总和 <strong>不会超过</strong> 给定的预算&nbsp;<code>budget</code>。</p>

<p><strong class="example">示例 1:</strong></p>

<div class="example-block">
<p><strong>输入:</strong> <span class="example-io">road = "..", budget = 5</span></p>

<p><strong>输出:</strong> <span class="example-io">0</span></p>

<p><strong>解释:</strong></p>

<p>没有坑洼需要修复。</p>
</div>

<p><strong class="example">示例 2:</strong></p>

<div class="example-block">
<p><strong>输入:</strong> <span class="example-io">road = "..xxxxx", budget = 4</span></p>

<p><strong>输出:</strong> <span class="example-io">3</span></p>

<p><strong>解释:</strong></p>

<p>我们修复了前三个坑洼（它们是连续的）。任务所需的预算为&nbsp;<code>3 + 1 = 4</code>。</p>
</div>

<p><strong class="example">示例 3:</strong></p>

<div class="example-block">
<p><strong>输入:</strong> <span class="example-io">road = "x.x.xxx...x", budget = 14</span></p>

<p><strong>输出:</strong> <span class="example-io">6</span></p>

<p><strong>解释:</strong></p>

<p>我们可以修复所有的坑洼。总花费为&nbsp;<code>(1 + 1) + (1 + 1) + (3 + 1) + (1 + 1) = 10</code>&nbsp;在我们的预算 14&nbsp;之内。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= road.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= budget &lt;= 10<sup>5</sup> + 1</code></li>
	<li><code>road</code>&nbsp;只包含字符&nbsp;<code>'.'</code>&nbsp;和&nbsp;<code>'x'</code>。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数 + 贪心

我们首先统计出每个连续的坑洼的数量，记录在数组 $cnt$ 中，即 $cnt[k]$ 表示有 $cnt[k]$ 个长度为 $k$ 的连续坑洼。

由于我们要尽可能多地修补坑洼，而对于长度为 $k$ 的连续坑洼，我们需要花费 $k + 1$ 的代价，应该优先修补长度较长的坑洼，这样可以使得代价最小。

因此，我们从最长的坑洼开始修补，对于长度为 $k$ 的坑洼，我们最多可以修补的个数为 $t = \min(\textit{budget} / (k + 1), \textit{cnt}[k])$，我们将修补的个数乘以长度 $k$ 加到答案中，然后更新剩余的预算。对于长度为 $k$ 的其余 $cnt[k] - t$ 个坑洼，我们将它们合并到长度为 $k - 1$ 的坑洼中。继续这个过程，直到遍历完所有的坑洼。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为字符串 $road$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxPotholes(self, road: str, budget: int) -> int:
        road += "."
        n = len(road)
        cnt = [0] * n
        k = 0
        for c in road:
            if c == "x":
                k += 1
            elif k:
                cnt[k] += 1
                k = 0
        ans = 0
        for k in range(n - 1, 0, -1):
            if cnt[k] == 0:
                continue
            t = min(budget // (k + 1), cnt[k])
            ans += t * k
            budget -= t * (k + 1)
            if budget == 0:
                break
            cnt[k - 1] += cnt[k] - t
        return ans
```

#### Java

```java
class Solution {
    public int maxPotholes(String road, int budget) {
        road += ".";
        int n = road.length();
        int[] cnt = new int[n];
        int k = 0;
        for (char c : road.toCharArray()) {
            if (c == 'x') {
                ++k;
            } else if (k > 0) {
                ++cnt[k];
                k = 0;
            }
        }
        int ans = 0;
        for (k = n - 1; k > 0 && budget > 0; --k) {
            int t = Math.min(budget / (k + 1), cnt[k]);
            ans += t * k;
            budget -= t * (k + 1);
            cnt[k - 1] += cnt[k] - t;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxPotholes(string road, int budget) {
        road.push_back('.');
        int n = road.size();
        vector<int> cnt(n);
        int k = 0;
        for (char& c : road) {
            if (c == 'x') {
                ++k;
            } else if (k) {
                ++cnt[k];
                k = 0;
            }
        }
        int ans = 0;
        for (k = n - 1; k && budget; --k) {
            int t = min(budget / (k + 1), cnt[k]);
            ans += t * k;
            budget -= t * (k + 1);
            cnt[k - 1] += cnt[k] - t;
        }
        return ans;
    }
};
```

#### Go

```go
func maxPotholes(road string, budget int) (ans int) {
	road += "."
	n := len(road)
	cnt := make([]int, n)
	k := 0
	for _, c := range road {
		if c == 'x' {
			k++
		} else if k > 0 {
			cnt[k]++
			k = 0
		}
	}
	for k = n - 1; k > 0 && budget > 0; k-- {
		t := min(budget/(k+1), cnt[k])
		ans += t * k
		budget -= t * (k + 1)
		cnt[k-1] += cnt[k] - t
	}
	return
}
```

#### TypeScript

```ts
function maxPotholes(road: string, budget: number): number {
    road += '.';
    const n = road.length;
    const cnt: number[] = Array(n).fill(0);
    let k = 0;
    for (const c of road) {
        if (c === 'x') {
            ++k;
        } else if (k) {
            ++cnt[k];
            k = 0;
        }
    }
    let ans = 0;
    for (k = n - 1; k && budget; --k) {
        const t = Math.min(Math.floor(budget / (k + 1)), cnt[k]);
        ans += t * k;
        budget -= t * (k + 1);
        cnt[k - 1] += cnt[k] - t;
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn max_potholes(road: String, budget: i32) -> i32 {
        let mut cs: Vec<char> = road.chars().collect();
        cs.push('.');
        let n = cs.len();
        let mut cnt: Vec<i32> = vec![0; n];
        let mut k = 0;

        for c in cs.iter() {
            if *c == 'x' {
                k += 1;
            } else if k > 0 {
                cnt[k] += 1;
                k = 0;
            }
        }

        let mut ans = 0;
        let mut budget = budget;

        for k in (1..n).rev() {
            if budget == 0 {
                break;
            }
            let t = std::cmp::min(budget / ((k as i32) + 1), cnt[k]);
            ans += t * (k as i32);
            budget -= t * ((k as i32) + 1);
            cnt[k - 1] += cnt[k] - t;
        }

        ans
    }
}
```

#### C#

```cs
public class Solution {
    public int MaxPotholes(string road, int budget) {
        road += '.';
        int n = road.Length;
        int[] cnt = new int[n];
        int k = 0;
        foreach (char c in road) {
            if (c == 'x') {
                ++k;
            } else if (k > 0) {
                ++cnt[k];
                k = 0;
            }
        }
        int ans = 0;
        for (k = n - 1; k > 0 && budget > 0; --k) {
            int t = Math.Min(budget / (k + 1), cnt[k]);
            ans += t * k;
            budget -= t * (k + 1);
            cnt[k - 1] += cnt[k] - t;
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
