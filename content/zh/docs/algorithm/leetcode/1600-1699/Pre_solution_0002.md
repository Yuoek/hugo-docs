---
title: "1610_可见点的最大数目"
date: 2025-10-08T18:38:12+08:00
weight: 2
tags: [二分查找, 二叉树, 交互, 位运算, 几何, 动态规划, 双指针, 哈希表, 图, 字符串, 排序, 数学, 数据库, 数组, 枚举, 栈, 树, 深度优先搜索, 滑动窗口, 状态压缩, 计数, 记忆化搜索]
---

{{< markmap >}}
### [1610_可见点的最大数目](#1610)
#### [几何](#1610)
#### [数组](#1610)
#### [数学](#1610)
#### [排序](#1610)
#### [滑动窗口](#1610)
### [1611_使整数变为 0 的最少操作次数](#1611)
#### [位运算](#1611)
#### [记忆化搜索](#1611)
#### [动态规划](#1611)
### [1612_检查两棵二叉表达式树是否等价 🔒](#1612)
#### [树](#1612)
#### [深度优先搜索](#1612)
#### [哈希表](#1612)
#### [二叉树](#1612)
#### [计数](#1612)
### [1613_找到遗失的ID 🔒](#1613)
#### [数据库](#1613)
### [1614_括号的最大嵌套深度](#1614)
#### [栈](#1614)
#### [字符串](#1614)
### [1615_最大网络秩](#1615)
#### [图](#1615)
### [1616_分割两个字符串得到回文串](#1616)
#### [双指针](#1616)
#### [字符串](#1616)
### [1617_统计子树中城市之间最大距离](#1617)
#### [位运算](#1617)
#### [树](#1617)
#### [动态规划](#1617)
#### [状态压缩](#1617)
#### [枚举](#1617)
### [1618_找出适应屏幕的最大字号 🔒](#1618)
#### [数组](#1618)
#### [字符串](#1618)
#### [二分查找](#1618)
#### [交互](#1618)
### [1619_删除某些元素后的数组均值](#1619)
#### [数组](#1619)
#### [排序](#1619)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1610_可见点的最大数目
___
#### 几何
___
#### 数组
___
#### 数学
___
#### 排序
___
#### 滑动窗口
---
### 1611_使整数变为 0 的最少操作次数
___
#### 位运算
___
#### 记忆化搜索
___
#### 动态规划
---
### 1612_检查两棵二叉表达式树是否等价 🔒
___
#### 树
___
#### 深度优先搜索
___
#### 哈希表
___
#### 二叉树
___
#### 计数
---
### 1613_找到遗失的ID 🔒
___
#### 数据库
---
### 1614_括号的最大嵌套深度
___
#### 栈
___
#### 字符串
---
### 1615_最大网络秩
___
#### 图
---
### 1616_分割两个字符串得到回文串
___
#### 双指针
___
#### 字符串
---
### 1617_统计子树中城市之间最大距离
___
#### 位运算
___
#### 树
___
#### 动态规划
___
#### 状态压缩
___
#### 枚举
---
### 1618_找出适应屏幕的最大字号 🔒
___
#### 数组
___
#### 字符串
___
#### 二分查找
___
#### 交互
---
### 1619_删除某些元素后的数组均值
___
#### 数组
___
#### 排序
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 二叉树 | 交互 |
| 位运算 | 几何 | 动态规划 |
| 双指针 | 哈希表 | 图 |
| 字符串 | 排序 | 数学 |
| 数据库 | 数组 | 枚举 |
| 栈 | 树 | 深度优先搜索 |
| 滑动窗口 | 状态压缩 | 计数 |
| 记忆化搜索 |  |  |

# [1610. 可见点的最大数目](https://leetcode.cn/problems/maximum-number-of-visible-points){#1610}

{{< tabs "1610" >}}

{{% tab "python" %}}
```python
class Solution:
    def visiblePoints(
        self, points: List[List[int]], angle: int, location: List[int]
    ) -> int:
        v = []
        x, y = location
        same = 0
        for xi, yi in points:
            if xi == x and yi == y:
                same += 1
            else:
                v.append(atan2(yi - y, xi - x))
        v.sort()
        n = len(v)
        v += [deg + 2 * pi for deg in v]
        t = angle * pi / 180
        mx = max((bisect_right(v, v[i] + t) - i for i in range(n)), default=0)
        return mx + same
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int visiblePoints(List<List<Integer>> points, int angle, List<Integer> location) {
        List<Double> v = new ArrayList<>();
        int x = location.get(0), y = location.get(1);
        int same = 0;
        for (List<Integer> p : points) {
            int xi = p.get(0), yi = p.get(1);
            if (xi == x && yi == y) {
                ++same;
                continue;
            }
            v.add(Math.atan2(yi - y, xi - x));
        }
        Collections.sort(v);
        int n = v.size();
        for (int i = 0; i < n; ++i) {
            v.add(v.get(i) + 2 * Math.PI);
        }
        int mx = 0;
        Double t = angle * Math.PI / 180;
        for (int i = 0, j = 0; j < 2 * n; ++j) {
            while (i < j && v.get(j) - v.get(i) > t) {
                ++i;
            }
            mx = Math.max(mx, j - i + 1);
        }
        return mx + same;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        vector<double> v;
        int x = location[0], y = location[1];
        int same = 0;
        for (auto& p : points) {
            int xi = p[0], yi = p[1];
            if (xi == x && yi == y)
                ++same;
            else
                v.emplace_back(atan2(yi - y, xi - x));
        }
        sort(v.begin(), v.end());
        int n = v.size();
        for (int i = 0; i < n; ++i) v.emplace_back(v[i] + 2 * M_PI);

        int mx = 0;
        double t = angle * M_PI / 180;
        for (int i = 0, j = 0; j < 2 * n; ++j) {
            while (i < j && v[j] - v[i] > t) ++i;
            mx = max(mx, j - i + 1);
        }
        return mx + same;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func visiblePoints(points [][]int, angle int, location []int) int {
	same := 0
	v := []float64{}
	for _, p := range points {
		if p[0] == location[0] && p[1] == location[1] {
			same++
		} else {
			v = append(v, math.Atan2(float64(p[1]-location[1]), float64(p[0]-location[0])))
		}
	}
	sort.Float64s(v)
	for _, deg := range v {
		v = append(v, deg+2*math.Pi)
	}

	mx := 0
	t := float64(angle) * math.Pi / 180
	for i, j := 0, 0; j < len(v); j++ {
		for i < j && v[j]-v[i] > t {
			i++
		}
		mx = max(mx, j-i+1)
	}
	return same + mx
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个点数组 <code>points</code> 和一个表示角度的整数 <code>angle</code> ，你的位置是 <code>location</code> ，其中 <code>location = [pos<sub>x</sub>, pos<sub>y</sub>]</code> 且 <code>points[i] = [x<sub>i</sub>, y<sub>i</sub>]</code> 都表示 X-Y 平面上的整数坐标。</p>

<p>最开始，你面向东方进行观测。你 <strong>不能</strong> 进行移动改变位置，但可以通过 <strong>自转</strong> 调整观测角度。换句话说，<code>pos<sub>x</sub></code> 和 <code>pos<sub>y</sub></code> 不能改变。你的视野范围的角度用 <code>angle</code> 表示， 这决定了你观测任意方向时可以多宽。设 <code>d</code> 为你逆时针自转旋转的度数，那么你的视野就是角度范围 <code>[d - angle/2, d + angle/2]</code> 所指示的那片区域。</p>

<video autoplay="" controls="" height="360" muted="" style="max-width:100%;height:auto;" width="750"><source src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1600-1699/1610.Maximum%20Number%20of%20Visible%20Points/images/angle.mp4" type="video/mp4" />Your browser does not support the video tag or this video format.</video>

<p>对于每个点，如果由该点、你的位置以及从你的位置直接向东的方向形成的角度 <strong>位于你的视野中</strong> ，那么你就可以看到它。</p>

<p>同一个坐标上可以有多个点。你所在的位置也可能存在一些点，但不管你的怎么旋转，总是可以看到这些点。同时，点不会阻碍你看到其他点。</p>

<p>返回你能看到的点的最大数目。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1600-1699/1610.Maximum%20Number%20of%20Visible%20Points/images/89a07e9b-00ab-4967-976a-c723b2aa8656.png" style="height: 300px; width: 400px;" /></p>

<pre>
<strong>输入：</strong>points = [[2,1],[2,2],[3,3]], angle = 90, location = [1,1]
<strong>输出：</strong>3
<strong>解释：</strong>阴影区域代表你的视野。在你的视野中，所有的点都清晰可见，尽管 [2,2] 和 [3,3]在同一条直线上，你仍然可以看到 [3,3] 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>points = [[2,1],[2,2],[3,4],[1,1]], angle = 90, location = [1,1]
<strong>输出：</strong>4
<strong>解释：</strong>在你的视野中，所有的点都清晰可见，包括你所在位置的那个点。</pre>

<p><strong>示例 3：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1600-1699/1610.Maximum%20Number%20of%20Visible%20Points/images/5010bfd3-86e6-465f-ac64-e9df941d2e49.png" style="height: 348px; width: 690px;" /></p>

<pre>
<strong>输入：</strong>points = [[1,0],[2,1]], angle = 13, location = [1,1]
<strong>输出：</strong>1
<strong>解释：</strong>如图所示，你只能看到两点之一。</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= points.length <= 10<sup>5</sup></code></li>
	<li><code>points[i].length == 2</code></li>
	<li><code>location.length == 2</code></li>
	<li><code>0 <= angle < 360</code></li>
	<li><code>0 <= pos<sub>x</sub>, pos<sub>y</sub>, x<sub>i</sub>, y<sub>i</sub> <= 100</code></li>
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
    def visiblePoints(
        self, points: List[List[int]], angle: int, location: List[int]
    ) -> int:
        v = []
        x, y = location
        same = 0
        for xi, yi in points:
            if xi == x and yi == y:
                same += 1
            else:
                v.append(atan2(yi - y, xi - x))
        v.sort()
        n = len(v)
        v += [deg + 2 * pi for deg in v]
        t = angle * pi / 180
        mx = max((bisect_right(v, v[i] + t) - i for i in range(n)), default=0)
        return mx + same
```

#### Java

```java
class Solution {
    public int visiblePoints(List<List<Integer>> points, int angle, List<Integer> location) {
        List<Double> v = new ArrayList<>();
        int x = location.get(0), y = location.get(1);
        int same = 0;
        for (List<Integer> p : points) {
            int xi = p.get(0), yi = p.get(1);
            if (xi == x && yi == y) {
                ++same;
                continue;
            }
            v.add(Math.atan2(yi - y, xi - x));
        }
        Collections.sort(v);
        int n = v.size();
        for (int i = 0; i < n; ++i) {
            v.add(v.get(i) + 2 * Math.PI);
        }
        int mx = 0;
        Double t = angle * Math.PI / 180;
        for (int i = 0, j = 0; j < 2 * n; ++j) {
            while (i < j && v.get(j) - v.get(i) > t) {
                ++i;
            }
            mx = Math.max(mx, j - i + 1);
        }
        return mx + same;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        vector<double> v;
        int x = location[0], y = location[1];
        int same = 0;
        for (auto& p : points) {
            int xi = p[0], yi = p[1];
            if (xi == x && yi == y)
                ++same;
            else
                v.emplace_back(atan2(yi - y, xi - x));
        }
        sort(v.begin(), v.end());
        int n = v.size();
        for (int i = 0; i < n; ++i) v.emplace_back(v[i] + 2 * M_PI);

        int mx = 0;
        double t = angle * M_PI / 180;
        for (int i = 0, j = 0; j < 2 * n; ++j) {
            while (i < j && v[j] - v[i] > t) ++i;
            mx = max(mx, j - i + 1);
        }
        return mx + same;
    }
};
```

#### Go

```go
func visiblePoints(points [][]int, angle int, location []int) int {
	same := 0
	v := []float64{}
	for _, p := range points {
		if p[0] == location[0] && p[1] == location[1] {
			same++
		} else {
			v = append(v, math.Atan2(float64(p[1]-location[1]), float64(p[0]-location[0])))
		}
	}
	sort.Float64s(v)
	for _, deg := range v {
		v = append(v, deg+2*math.Pi)
	}

	mx := 0
	t := float64(angle) * math.Pi / 180
	for i, j := 0, 0; j < len(v); j++ {
		for i < j && v[j]-v[i] > t {
			i++
		}
		mx = max(mx, j-i+1)
	}
	return same + mx
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1611. 使整数变为 0 的最少操作次数](https://leetcode.cn/problems/minimum-one-bit-operations-to-make-integers-zero){#1611}

{{< tabs "1611" >}}

{{% tab "java" %}}
```java
class Solution {
    public int minimumOneBitOperations(int n) {
        if (n == 0) {
            return 0;
        }
        return n ^ minimumOneBitOperations(n >> 1);
    }
}
```
{{% /tab %}}
{{% tab "python" %}}
```python
class Solution:
    def minimumOneBitOperations(self, n: int) -> int:
        if n == 0:
            return 0
        return n ^ self.minimumOneBitOperations(n >> 1)
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minimumOneBitOperations(int n) {
        if (n == 0) {
            return 0;
        }
        return n ^ minimumOneBitOperations(n >> 1);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumOneBitOperations(n int) int {
	if n == 0 {
		return 0
	}
	return n ^ minimumOneBitOperations(n>>1)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumOneBitOperations(n: number): number {
    if (n === 0) {
        return 0;
    }
    return n ^ minimumOneBitOperations(n >> 1);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数 <code>n</code>，你需要重复执行多次下述操作将其转换为 <code>0</code> ：</p>

<ul>
	<li>翻转 <code>n</code> 的二进制表示中最右侧位（第 <code>0</code> 位）。</li>
	<li>如果第 <code>(i-1)</code> 位为 <code>1</code> 且从第 <code>(i-2)</code> 位到第 <code>0</code> 位都为 <code>0</code>，则翻转 <code>n</code> 的二进制表示中的第 <code>i</code> 位。</li>
</ul>

<p>返回将 <code>n</code> 转换为 <code>0</code> 的最小操作次数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 3
<strong>输出：</strong>2
<strong>解释：</strong>3 的二进制表示为 "11"
"<strong>1</strong>1" -&gt; "<strong>0</strong>1" ，执行的是第 2 种操作，因为第 0 位为 1 。
"0<strong>1</strong>" -&gt; "0<strong>0</strong>" ，执行的是第 1 种操作。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 6
<strong>输出：</strong>4
<strong>解释：</strong>6 的二进制表示为 "110".
"<strong>1</strong>10" -&gt; "<strong>0</strong>10" ，执行的是第 2 种操作，因为第 1 位为 1 ，第 0 到 0 位为 0 。
"01<strong>0</strong>" -&gt; "01<strong>1</strong>" ，执行的是第 1 种操作。
"0<strong>1</strong>1" -&gt; "0<strong>0</strong>1" ，执行的是第 2 种操作，因为第 0 位为 1 。
"00<strong>1</strong>" -&gt; "00<strong>0</strong>" ，执行的是第 1 种操作。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= n &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：格雷码逆变换（格雷码转二进制码）

本题实际上求的是格雷码为 $n$ 的逆变换，即通过格雷码构造原数。

我们先来回顾一下二进制码转换成二进制格雷码，其法则是保留二进制码的最高位作为格雷码的最高位，而次高位格雷码为二进制码的高位与次高位相异或，而格雷码其余各位与次高位的求法相类似。

假设某个二进制数表示为 $B_{n-1}B_{n-2}...B_2B_1B_0$，其格雷码表示为 $G_{n-1}G_{n-2}...G_2G_1G_0$。最高位保留，所以 $G_{n-1} = B_{n-1}$；而其它各位 $G_i = B_{i+1} \oplus B_{i}$，其中 $i=0,1,2..,n-2$。

那么，格雷码转换成二进制码的逆变换是什么呢？

我们可以发现，格雷码的最高位保留，所以 $B_{n-1} = G_{n-1}$；而 $B_{n-2} = G_{n-2} \oplus B_{n-1} = G_{n-2} \oplus G_{n-1}$；而其它各位 $B_i = G_{i} \oplus G_{i+1} \cdots \oplus G_{n-1}$，其中 $i=0,1,2..,n-2$。因此，我们可以用下面的函数 $rev(x)$ 得到其二进制码：

```java
int rev(int x) {
    int n = 0;
    for (; x != 0; x >>= 1) {
        n ^= x;
    }
    return n;
}
```

时间复杂度 $O(\log n)$，其中 $n$ 为题目给定的整数。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumOneBitOperations(self, n: int) -> int:
        ans = 0
        while n:
            ans ^= n
            n >>= 1
        return ans
```

#### Java

```java
class Solution {
    public int minimumOneBitOperations(int n) {
        int ans = 0;
        for (; n > 0; n >>= 1) {
            ans ^= n;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumOneBitOperations(int n) {
        int ans = 0;
        for (; n > 0; n >>= 1) {
            ans ^= n;
        }
        return ans;
    }
};
```

#### Go

```go
func minimumOneBitOperations(n int) (ans int) {
	for ; n > 0; n >>= 1 {
		ans ^= n
	}
	return
}
```

#### TypeScript

```ts
function minimumOneBitOperations(n: number): number {
    let ans = 0;
    for (; n > 0; n >>= 1) {
        ans ^= n;
    }
    return ans;
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
    def minimumOneBitOperations(self, n: int) -> int:
        if n == 0:
            return 0
        return n ^ self.minimumOneBitOperations(n >> 1)
```

#### Java

```java
class Solution {
    public int minimumOneBitOperations(int n) {
        if (n == 0) {
            return 0;
        }
        return n ^ minimumOneBitOperations(n >> 1);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumOneBitOperations(int n) {
        if (n == 0) {
            return 0;
        }
        return n ^ minimumOneBitOperations(n >> 1);
    }
};
```

#### Go

```go
func minimumOneBitOperations(n int) int {
	if n == 0 {
		return 0
	}
	return n ^ minimumOneBitOperations(n>>1)
}
```

#### TypeScript

```ts
function minimumOneBitOperations(n: number): number {
    if (n === 0) {
        return 0;
    }
    return n ^ minimumOneBitOperations(n >> 1);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1612. 检查两棵二叉表达式树是否等价 🔒](https://leetcode.cn/problems/check-if-two-expression-trees-are-equivalent){#1612}

{{< tabs "1612" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class Node(object):
#     def __init__(self, val=" ", left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def checkEquivalence(self, root1: 'Node', root2: 'Node') -> bool:
        def dfs(root):
            cnt = [0] * 26
            if root is None:
                return cnt
            if root.val in '+-':
                l, r = dfs(root.left), dfs(root.right)
                k = 1 if root.val == '+' else -1
                for i in range(26):
                    cnt[i] += l[i] + r[i] * k
            else:
                cnt[ord(root.val) - ord('a')] += 1
            return cnt

        return dfs(root1) == dfs(root2)
```
{{% /tab %}}
{{% tab "java" %}}
```java
/**
 * Definition for a binary tree node.
 * class Node {
 *     char val;
 *     Node left;
 *     Node right;
 *     Node() {this.val = ' ';}
 *     Node(char val) { this.val = val; }
 *     Node(char val, Node left, Node right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public boolean checkEquivalence(Node root1, Node root2) {
        int[] cnt1 = dfs(root1);
        int[] cnt2 = dfs(root2);
        for (int i = 0; i < 26; ++i) {
            if (cnt1[i] != cnt2[i]) {
                return false;
            }
        }
        return true;
    }

    private int[] dfs(Node root) {
        int[] cnt = new int[26];
        if (root == null) {
            return cnt;
        }
        if (root.val == '+' || root.val == '-') {
            int[] l = dfs(root.left);
            int[] r = dfs(root.right);
            int k = root.val == '+' ? 1 : -1;
            for (int i = 0; i < 26; ++i) {
                cnt[i] += l[i] + r[i] * k;
            }
        } else {
            cnt[root.val - 'a']++;
        }
        return cnt;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
/**
 * Definition for a binary tree node.
 * struct Node {
 *     char val;
 *     Node *left;
 *     Node *right;
 *     Node() : val(' '), left(nullptr), right(nullptr) {}
 *     Node(char x) : val(x), left(nullptr), right(nullptr) {}
 *     Node(char x, Node *left, Node *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool checkEquivalence(Node* root1, Node* root2) {
        function<vector<int>(Node*)> dfs = [&](Node* root) -> vector<int> {
            vector<int> cnt(26);
            if (!root) {
                return cnt;
            }
            if (root->val == '+' || root->val == '-') {
                auto l = dfs(root->left);
                auto r = dfs(root->right);
                int k = root->val == '+' ? 1 : -1;
                for (int i = 0; i < 26; ++i) {
                    cnt[i] += l[i] + r[i] * k;
                }
            } else {
                cnt[root->val - 'a']++;
            }
            return cnt;
        };
        return dfs(root1) == dfs(root2);
    }
};
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * Definition for a binary tree node.
 * function Node(val, left, right) {
 *     this.val = (val===undefined ? " " : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {Node} root1
 * @param {Node} root2
 * @return {boolean}
 */
var checkEquivalence = function (root1, root2) {
    const dfs = root => {
        const cnt = new Array(26).fill(0);
        if (!root) {
            return cnt;
        }
        if (root.val === '+' || root.val === '-') {
            const l = dfs(root.left);
            const r = dfs(root.right);
            const k = root.val === '+' ? 1 : -1;
            for (let i = 0; i < 26; ++i) {
                cnt[i] = l[i] + k * r[i];
            }
        } else {
            cnt[root.val.charCodeAt(0) - 'a'.charCodeAt(0)]++;
        }
        return cnt;
    };
    const cnt1 = dfs(root1);
    const cnt2 = dfs(root2);
    for (let i = 0; i < 26; ++i) {
        if (cnt1[i] !== cnt2[i]) {
            return false;
        }
    }
    return true;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p><strong><a href="https://en.wikipedia.org/wiki/Binary_expression_tree" target="_blank">二叉表达式树</a></strong>是一种表达算术表达式的二叉树。二叉表达式树中的每一个节点都有零个或两个子节点。&nbsp;叶节点（有 0 个子节点的节点）表示操作数，非叶节点（有 2 个子节点的节点）表示运算符。在本题中，我们只考虑 <code>'+'</code> 运算符（即加法）。</p>

<p>给定两棵二叉表达式树的根节点&nbsp;<code>root1</code>&nbsp;和&nbsp;<code>root2</code>&nbsp;。<em>如果两棵二叉表达式树等价</em>，返回&nbsp;<code>true</code>&nbsp;，否则返回&nbsp;<code>false</code>&nbsp;。</p>

<p>当两棵二叉搜索树中的变量取任意值，<strong>分别求得的值都相等</strong>时，我们称这两棵二叉表达式树是等价的。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<b>输入：</b> root1 = [x], root2 = [x]
<b>输出：</b> true
</pre>

<p><strong>示例 2:</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1600-1699/1612.Check%20If%20Two%20Expression%20Trees%20are%20Equivalent/images/tree1.png" style="width: 211px; height: 131px;" /></strong></p>

<pre>
<b>输入：</b>root1 = [+,a,+,null,null,b,c], root2 = [+,+,a,b,c]
<b>输出：</b>true
<code><span style=""><b>解释：</b></span>a + (b + c) == (b + c) + a</code></pre>

<p><strong>示例 3:</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1600-1699/1612.Check%20If%20Two%20Expression%20Trees%20are%20Equivalent/images/tree2.png" style="width: 211px; height: 131px;" /></strong></p>

<pre>
<b>输入：</b> root1 = [+,a,+,null,null,b,c], root2 = [+,+,a,b,d]
<b>输出：</b> false
<b>解释：</b> <code>a + (b + c) != (b + d) + a</code>
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>两棵树中的节点个数相等，且节点个数为范围&nbsp;<code>[1, 4999]</code>&nbsp;内的奇数。</li>
	<li><code>Node.val</code>&nbsp;是&nbsp;<code>'+'</code>&nbsp;或小写英文字母。</li>
	<li>给定的树<strong>保证</strong>是有效的二叉表达式树。</li>
</ul>

<p>&nbsp;</p>

<p><b>进阶：</b>当你的答案需同时支持&nbsp;<code>'-'</code>&nbsp;运算符（减法）时，你该如何修改你的答案</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：递归

我们定义一个计数器 $cnt$，用于统计每个字母出现的次数。

然后我们分别对两棵二叉表达式树进行深度优先搜索，如果字母出现在左子树，则 $cnt$ 中对应的字母的值加 $1$，如果出现在右子树，则 $cnt$ 中对应的字母的值减 $1$。

最后，我们遍历 $cnt$，如果所有字母的值都为 $0$，则返回 `true`，否则返回 `false`。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是二叉表达式树的节点个数。

<!-- tabs:start -->

#### Python3

```python
# Definition for a binary tree node.
# class Node(object):
#     def __init__(self, val=" ", left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def checkEquivalence(self, root1: 'Node', root2: 'Node') -> bool:
        def dfs(root, v):
            if root is None:
                return
            if root.val != '+':
                cnt[root.val] += v
            dfs(root.left, v)
            dfs(root.right, v)

        cnt = Counter()
        dfs(root1, 1)
        dfs(root2, -1)
        return all(x == 0 for x in cnt.values())
```

#### Java

```java
/**
 * Definition for a binary tree node.
 * class Node {
 *     char val;
 *     Node left;
 *     Node right;
 *     Node() {this.val = ' ';}
 *     Node(char val) { this.val = val; }
 *     Node(char val, Node left, Node right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private int[] cnt = new int[26];

    public boolean checkEquivalence(Node root1, Node root2) {
        dfs(root1, 1);
        dfs(root2, -1);
        for (int x : cnt) {
            if (x != 0) {
                return false;
            }
        }
        return true;
    }

    private void dfs(Node root, int v) {
        if (root == null) {
            return;
        }
        if (root.val != '+') {
            cnt[root.val - 'a'] += v;
        }
        dfs(root.left, v);
        dfs(root.right, v);
    }
}
```

#### C++

```cpp
/**
 * Definition for a binary tree node.
 * struct Node {
 *     char val;
 *     Node *left;
 *     Node *right;
 *     Node() : val(' '), left(nullptr), right(nullptr) {}
 *     Node(char x) : val(x), left(nullptr), right(nullptr) {}
 *     Node(char x, Node *left, Node *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool checkEquivalence(Node* root1, Node* root2) {
        int cnt[26]{};
        function<void(Node*, int)> dfs = [&](Node* root, int v) {
            if (!root) {
                return;
            }
            if (root->val != '+') {
                cnt[root->val - 'a'] += v;
            }
            dfs(root->left, v);
            dfs(root->right, v);
        };
        dfs(root1, 1);
        dfs(root2, -1);
        for (int& x : cnt) {
            if (x) {
                return false;
            }
        }
        return true;
    }
};
```

#### JavaScript

```js
/**
 * Definition for a binary tree node.
 * function Node(val, left, right) {
 *     this.val = (val===undefined ? " " : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {Node} root1
 * @param {Node} root2
 * @return {boolean}
 */
var checkEquivalence = function (root1, root2) {
    const cnt = new Array(26).fill(0);
    const dfs = (root, v) => {
        if (!root) {
            return;
        }
        if (root.val !== '+') {
            cnt[root.val.charCodeAt(0) - 'a'.charCodeAt(0)] += v;
        }
        dfs(root.left, v);
        dfs(root.right, v);
    };
    dfs(root1, 1);
    dfs(root2, -1);
    for (const x of cnt) {
        if (x) {
            return false;
        }
    }
    return true;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### Python3

```python
# Definition for a binary tree node.
# class Node(object):
#     def __init__(self, val=" ", left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def checkEquivalence(self, root1: 'Node', root2: 'Node') -> bool:
        def dfs(root):
            cnt = [0] * 26
            if root is None:
                return cnt
            if root.val in '+-':
                l, r = dfs(root.left), dfs(root.right)
                k = 1 if root.val == '+' else -1
                for i in range(26):
                    cnt[i] += l[i] + r[i] * k
            else:
                cnt[ord(root.val) - ord('a')] += 1
            return cnt

        return dfs(root1) == dfs(root2)
```

#### Java

```java
/**
 * Definition for a binary tree node.
 * class Node {
 *     char val;
 *     Node left;
 *     Node right;
 *     Node() {this.val = ' ';}
 *     Node(char val) { this.val = val; }
 *     Node(char val, Node left, Node right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public boolean checkEquivalence(Node root1, Node root2) {
        int[] cnt1 = dfs(root1);
        int[] cnt2 = dfs(root2);
        for (int i = 0; i < 26; ++i) {
            if (cnt1[i] != cnt2[i]) {
                return false;
            }
        }
        return true;
    }

    private int[] dfs(Node root) {
        int[] cnt = new int[26];
        if (root == null) {
            return cnt;
        }
        if (root.val == '+' || root.val == '-') {
            int[] l = dfs(root.left);
            int[] r = dfs(root.right);
            int k = root.val == '+' ? 1 : -1;
            for (int i = 0; i < 26; ++i) {
                cnt[i] += l[i] + r[i] * k;
            }
        } else {
            cnt[root.val - 'a']++;
        }
        return cnt;
    }
}
```

#### C++

```cpp
/**
 * Definition for a binary tree node.
 * struct Node {
 *     char val;
 *     Node *left;
 *     Node *right;
 *     Node() : val(' '), left(nullptr), right(nullptr) {}
 *     Node(char x) : val(x), left(nullptr), right(nullptr) {}
 *     Node(char x, Node *left, Node *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool checkEquivalence(Node* root1, Node* root2) {
        function<vector<int>(Node*)> dfs = [&](Node* root) -> vector<int> {
            vector<int> cnt(26);
            if (!root) {
                return cnt;
            }
            if (root->val == '+' || root->val == '-') {
                auto l = dfs(root->left);
                auto r = dfs(root->right);
                int k = root->val == '+' ? 1 : -1;
                for (int i = 0; i < 26; ++i) {
                    cnt[i] += l[i] + r[i] * k;
                }
            } else {
                cnt[root->val - 'a']++;
            }
            return cnt;
        };
        return dfs(root1) == dfs(root2);
    }
};
```

#### JavaScript

```js
/**
 * Definition for a binary tree node.
 * function Node(val, left, right) {
 *     this.val = (val===undefined ? " " : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {Node} root1
 * @param {Node} root2
 * @return {boolean}
 */
var checkEquivalence = function (root1, root2) {
    const dfs = root => {
        const cnt = new Array(26).fill(0);
        if (!root) {
            return cnt;
        }
        if (root.val === '+' || root.val === '-') {
            const l = dfs(root.left);
            const r = dfs(root.right);
            const k = root.val === '+' ? 1 : -1;
            for (let i = 0; i < 26; ++i) {
                cnt[i] = l[i] + k * r[i];
            }
        } else {
            cnt[root.val.charCodeAt(0) - 'a'.charCodeAt(0)]++;
        }
        return cnt;
    };
    const cnt1 = dfs(root1);
    const cnt2 = dfs(root2);
    for (let i = 0; i < 26; ++i) {
        if (cnt1[i] !== cnt2[i]) {
            return false;
        }
    }
    return true;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1613. 找到遗失的ID 🔒](https://leetcode.cn/problems/find-the-missing-ids){#1613}

{{< tabs "1613" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH RECURSIVE
    t AS (
        SELECT
            1 AS n
        UNION ALL
        SELECT
            n + 1
        FROM t
        WHERE n < 100
    )
SELECT
    n AS ids
FROM t
WHERE
    n < (
        SELECT
            MAX(customer_id)
        FROM Customers
    )
    AND n NOT IN (
        SELECT
            customer_id
        FROM Customers
    );
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表: <code>Customers</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| customer_id   | int     |
| customer_name | varchar |
+---------------+---------+
customer_id 是该表主键.
该表第一行包含了顾客的名字和 id.
</pre>

<p>&nbsp;</p>

<p>编写一个解决方案,&nbsp;找到所有遗失的顾客 id。遗失的顾客 id 是指那些不在&nbsp;<code>Customers</code>&nbsp;表中,&nbsp;值却处于&nbsp;<code>1</code>&nbsp;和表中&nbsp;<strong>最大</strong>&nbsp;<code>customer_id</code>&nbsp;之间的 id.</p>

<p><strong>注意:&nbsp;</strong>最大的&nbsp;<code>customer_id</code>&nbsp;值不会超过&nbsp;<code>100</code>.</p>

<p>返回结果按&nbsp;<code>ids</code> <strong>升序&nbsp;</strong>排列</p>

<p>查询结果格式如下例所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<code><strong>输入：</strong>
Customers</code> 表:
+-------------+---------------+
| customer_id | customer_name |
+-------------+---------------+
| 1           | Alice         |
| 4           | Bob           |
| 5           | Charlie       |
+-------------+---------------+
<strong>输出：</strong>
+-----+
| <code>ids </code>|
+-----+
| 2   |
| 3   |
+-----+
<strong>解释：</strong>
表中最大的 customer_id 是 5, 所以在范围 [1,5] 内, ID2 和 3 从表中遗失.</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：递归

利用 `recursive` 关键字，递归生成 `[1, 100]` 的序列，然后排除已有的 `customer_id`，即可得到结果。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
WITH RECURSIVE
    t AS (
        SELECT
            1 AS n
        UNION ALL
        SELECT
            n + 1
        FROM t
        WHERE n < 100
    )
SELECT
    n AS ids
FROM t
WHERE
    n < (
        SELECT
            MAX(customer_id)
        FROM Customers
    )
    AND n NOT IN (
        SELECT
            customer_id
        FROM Customers
    );
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1614. 括号的最大嵌套深度](https://leetcode.cn/problems/maximum-nesting-depth-of-the-parentheses){#1614}

{{< tabs "1614" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxDepth(self, s: str) -> int:
        ans = d = 0
        for c in s:
            if c == '(':
                d += 1
                ans = max(ans, d)
            elif c == ')':
                d -= 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxDepth(String s) {
        int ans = 0, d = 0;
        for (int i = 0; i < s.length(); ++i) {
            char c = s.charAt(i);
            if (c == '(') {
                ans = Math.max(ans, ++d);
            } else if (c == ')') {
                --d;
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
    int maxDepth(string s) {
        int ans = 0, d = 0;
        for (char& c : s) {
            if (c == '(') {
                ans = max(ans, ++d);
            } else if (c == ')') {
                --d;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxDepth(s string) (ans int) {
	d := 0
	for _, c := range s {
		if c == '(' {
			d++
			ans = max(ans, d)
		} else if c == ')' {
			d--
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxDepth(s: string): number {
    let ans = 0;
    let d = 0;
    for (const c of s) {
        if (c === '(') {
            ans = Math.max(ans, ++d);
        } else if (c === ')') {
            --d;
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {string} s
 * @return {number}
 */
var maxDepth = function (s) {
    let ans = 0;
    let d = 0;
    for (const c of s) {
        if (c === '(') {
            ans = Math.max(ans, ++d);
        } else if (c === ')') {
            --d;
        }
    }
    return ans;
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int MaxDepth(string s) {
        int ans = 0, d = 0;
        foreach(char c in s) {
            if (c == '(') {
                ans = Math.Max(ans, ++d);
            } else if (c == ')') {
                --d;
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

<p>给定 <strong>有效括号字符串</strong> <code>s</code>，返回 <code>s</code> 的 <strong>嵌套深度</strong>。嵌套深度是嵌套括号的 <strong>最大</strong> 数量。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong>s = "(1+(2*3)+((<strong>8</strong>)/4))+1"</p>

<p><strong>输出：</strong>3</p>

<p><strong>解释：</strong>数字 8 在嵌套的 3 层括号中。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong>s = "(1)+((2))+(((<strong>3</strong>)))"</p>

<p><strong>输出：</strong>3</p>

<p><strong>解释：</strong>数字 3 在嵌套的 3 层括号中。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">s = "()(())((()()))"</span></p>

<p><strong>输出：</strong><span class="example-io">3</span></p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>s</code> 由数字 <code>0-9</code> 和字符 <code>'+'</code>、<code>'-'</code>、<code>'*'</code>、<code>'/'</code>、<code>'('</code>、<code>')'</code> 组成</li>
	<li>题目数据保证括号字符串&nbsp;<code>s</code> 是 <strong>有效的括号字符串</strong></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：遍历

我们用一个变量 $d$ 记录当前的深度，初始时 $d = 0$。

遍历字符串 $s$，当遇到左括号时，深度 $d$ 加一，同时更新答案为当前深度 $d$ 和答案的最大值。当遇到右括号时，深度 $d$ 减一。

最后返回答案即可。

时间复杂度 $O(n)$，其中 $n$ 是字符串 $s$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxDepth(self, s: str) -> int:
        ans = d = 0
        for c in s:
            if c == '(':
                d += 1
                ans = max(ans, d)
            elif c == ')':
                d -= 1
        return ans
```

#### Java

```java
class Solution {
    public int maxDepth(String s) {
        int ans = 0, d = 0;
        for (int i = 0; i < s.length(); ++i) {
            char c = s.charAt(i);
            if (c == '(') {
                ans = Math.max(ans, ++d);
            } else if (c == ')') {
                --d;
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
    int maxDepth(string s) {
        int ans = 0, d = 0;
        for (char& c : s) {
            if (c == '(') {
                ans = max(ans, ++d);
            } else if (c == ')') {
                --d;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func maxDepth(s string) (ans int) {
	d := 0
	for _, c := range s {
		if c == '(' {
			d++
			ans = max(ans, d)
		} else if c == ')' {
			d--
		}
	}
	return
}
```

#### TypeScript

```ts
function maxDepth(s: string): number {
    let ans = 0;
    let d = 0;
    for (const c of s) {
        if (c === '(') {
            ans = Math.max(ans, ++d);
        } else if (c === ')') {
            --d;
        }
    }
    return ans;
}
```

#### JavaScript

```js
/**
 * @param {string} s
 * @return {number}
 */
var maxDepth = function (s) {
    let ans = 0;
    let d = 0;
    for (const c of s) {
        if (c === '(') {
            ans = Math.max(ans, ++d);
        } else if (c === ')') {
            --d;
        }
    }
    return ans;
};
```

#### C#

```cs
public class Solution {
    public int MaxDepth(string s) {
        int ans = 0, d = 0;
        foreach(char c in s) {
            if (c == '(') {
                ans = Math.Max(ans, ++d);
            } else if (c == ')') {
                --d;
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

# [1615. 最大网络秩](https://leetcode.cn/problems/maximal-network-rank){#1615}

{{< tabs "1615" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximalNetworkRank(self, n: int, roads: List[List[int]]) -> int:
        g = [[0] * n for _ in range(n)]
        cnt = [0] * n
        for a, b in roads:
            g[a][b] = g[b][a] = 1
            cnt[a] += 1
            cnt[b] += 1
        return max(cnt[a] + cnt[b] - g[a][b] for a in range(n) for b in range(a + 1, n))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maximalNetworkRank(int n, int[][] roads) {
        int[][] g = new int[n][n];
        int[] cnt = new int[n];
        for (var r : roads) {
            int a = r[0], b = r[1];
            g[a][b] = 1;
            g[b][a] = 1;
            ++cnt[a];
            ++cnt[b];
        }
        int ans = 0;
        for (int a = 0; a < n; ++a) {
            for (int b = a + 1; b < n; ++b) {
                ans = Math.max(ans, cnt[a] + cnt[b] - g[a][b]);
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
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int cnt[n];
        int g[n][n];
        memset(cnt, 0, sizeof(cnt));
        memset(g, 0, sizeof(g));
        for (auto& r : roads) {
            int a = r[0], b = r[1];
            g[a][b] = g[b][a] = 1;
            ++cnt[a];
            ++cnt[b];
        }
        int ans = 0;
        for (int a = 0; a < n; ++a) {
            for (int b = a + 1; b < n; ++b) {
                ans = max(ans, cnt[a] + cnt[b] - g[a][b]);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximalNetworkRank(n int, roads [][]int) (ans int) {
	g := make([][]int, n)
	cnt := make([]int, n)
	for i := range g {
		g[i] = make([]int, n)
	}
	for _, r := range roads {
		a, b := r[0], r[1]
		g[a][b], g[b][a] = 1, 1
		cnt[a]++
		cnt[b]++
	}
	for a := 0; a < n; a++ {
		for b := a + 1; b < n; b++ {
			ans = max(ans, cnt[a]+cnt[b]-g[a][b])
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximalNetworkRank(n: number, roads: number[][]): number {
    const g: number[][] = Array.from({ length: n }, () => Array(n).fill(0));
    const cnt: number[] = Array(n).fill(0);
    for (const [a, b] of roads) {
        g[a][b] = 1;
        g[b][a] = 1;
        ++cnt[a];
        ++cnt[b];
    }
    let ans = 0;
    for (let a = 0; a < n; ++a) {
        for (let b = a + 1; b < n; ++b) {
            ans = Math.max(ans, cnt[a] + cnt[b] - g[a][b]);
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

<p><code>n</code> 座城市和一些连接这些城市的道路 <code>roads</code> 共同组成一个基础设施网络。每个 <code>roads[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> 都表示在城市 <code>a<sub>i</sub></code> 和 <code>b<sub>i</sub></code> 之间有一条双向道路。</p>

<p>两座不同城市构成的 <strong>城市对</strong> 的 <strong>网络秩</strong> 定义为：与这两座城市 <strong>直接</strong> 相连的道路总数。如果存在一条道路直接连接这两座城市，则这条道路只计算 <strong>一次</strong> 。</p>

<p>整个基础设施网络的 <strong>最大网络秩</strong> 是所有不同城市对中的 <strong>最大网络秩</strong> 。</p>

<p>给你整数 <code>n</code> 和数组 <code>roads</code>，返回整个基础设施网络的 <strong>最大网络秩</strong> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1600-1699/1615.Maximal%20Network%20Rank/images/ex1.png" style="width: 292px; height: 172px;" /></strong></p>

<pre>
<strong>输入：</strong>n = 4, roads = [[0,1],[0,3],[1,2],[1,3]]
<strong>输出：</strong>4
<strong>解释：</strong>城市 0 和 1 的网络秩是 4，因为共有 4 条道路与城市 0 或 1 相连。位于 0 和 1 之间的道路只计算一次。
</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1600-1699/1615.Maximal%20Network%20Rank/images/ex2.png" style="width: 292px; height: 172px;" /></strong></p>

<pre>
<strong>输入：</strong>n = 5, roads = [[0,1],[0,3],[1,2],[1,3],[2,3],[2,4]]
<strong>输出：</strong>5
<strong>解释：</strong>共有 5 条道路与城市 1 或 2 相连。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 8, roads = [[0,1],[1,2],[2,3],[2,4],[5,6],[5,7]]
<strong>输出：</strong>5
<strong>解释：</strong>2 和 5 的网络秩为 5，注意并非所有的城市都需要连接起来。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 <= n <= 100</code></li>
	<li><code>0 <= roads.length <= n * (n - 1) / 2</code></li>
	<li><code>roads[i].length == 2</code></li>
	<li><code>0 <= a<sub>i</sub>, b<sub>i</sub> <= n-1</code></li>
	<li><code>a<sub>i</sub> != b<sub>i</sub></code></li>
	<li>每对城市之间 <strong>最多只有一条</strong> 道路相连</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数

我们可以用一维数组 $\textit{cnt}$ 记录每个城市的度，用二维数组 $\textit{g}$ 记录每对城市之间是否有道路相连，如果城市 $a$ 和城市 $b$ 之间有道路相连，则 $\textit{g}[a][b] = \textit{g}[b][a] = 1$，否则 $\textit{g}[a][b] = \textit{g}[b][a] = 0$。

接下来，我们枚举每对城市 $(a, b)$，其中 $a \lt b$，计算它们的网络秩，即 $\textit{cnt}[a] + \textit{cnt}[b] - \textit{g}[a][b]$，取其中的最大值即为答案。

时间复杂度 $O(n^2)$，空间复杂度 $O(n^2)$。其中 $n$ 是城市的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximalNetworkRank(self, n: int, roads: List[List[int]]) -> int:
        g = [[0] * n for _ in range(n)]
        cnt = [0] * n
        for a, b in roads:
            g[a][b] = g[b][a] = 1
            cnt[a] += 1
            cnt[b] += 1
        return max(cnt[a] + cnt[b] - g[a][b] for a in range(n) for b in range(a + 1, n))
```

#### Java

```java
class Solution {
    public int maximalNetworkRank(int n, int[][] roads) {
        int[][] g = new int[n][n];
        int[] cnt = new int[n];
        for (var r : roads) {
            int a = r[0], b = r[1];
            g[a][b] = 1;
            g[b][a] = 1;
            ++cnt[a];
            ++cnt[b];
        }
        int ans = 0;
        for (int a = 0; a < n; ++a) {
            for (int b = a + 1; b < n; ++b) {
                ans = Math.max(ans, cnt[a] + cnt[b] - g[a][b]);
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
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int cnt[n];
        int g[n][n];
        memset(cnt, 0, sizeof(cnt));
        memset(g, 0, sizeof(g));
        for (auto& r : roads) {
            int a = r[0], b = r[1];
            g[a][b] = g[b][a] = 1;
            ++cnt[a];
            ++cnt[b];
        }
        int ans = 0;
        for (int a = 0; a < n; ++a) {
            for (int b = a + 1; b < n; ++b) {
                ans = max(ans, cnt[a] + cnt[b] - g[a][b]);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func maximalNetworkRank(n int, roads [][]int) (ans int) {
	g := make([][]int, n)
	cnt := make([]int, n)
	for i := range g {
		g[i] = make([]int, n)
	}
	for _, r := range roads {
		a, b := r[0], r[1]
		g[a][b], g[b][a] = 1, 1
		cnt[a]++
		cnt[b]++
	}
	for a := 0; a < n; a++ {
		for b := a + 1; b < n; b++ {
			ans = max(ans, cnt[a]+cnt[b]-g[a][b])
		}
	}
	return
}
```

#### TypeScript

```ts
function maximalNetworkRank(n: number, roads: number[][]): number {
    const g: number[][] = Array.from({ length: n }, () => Array(n).fill(0));
    const cnt: number[] = Array(n).fill(0);
    for (const [a, b] of roads) {
        g[a][b] = 1;
        g[b][a] = 1;
        ++cnt[a];
        ++cnt[b];
    }
    let ans = 0;
    for (let a = 0; a < n; ++a) {
        for (let b = a + 1; b < n; ++b) {
            ans = Math.max(ans, cnt[a] + cnt[b] - g[a][b]);
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

# [1616. 分割两个字符串得到回文串](https://leetcode.cn/problems/split-two-strings-to-make-palindrome){#1616}

{{< tabs "1616" >}}

{{% tab "python" %}}
```python
class Solution:
    def checkPalindromeFormation(self, a: str, b: str) -> bool:
        def check1(a: str, b: str) -> bool:
            i, j = 0, len(b) - 1
            while i < j and a[i] == b[j]:
                i, j = i + 1, j - 1
            return i >= j or check2(a, i, j) or check2(b, i, j)

        def check2(a: str, i: int, j: int) -> bool:
            return a[i : j + 1] == a[i : j + 1][::-1]

        return check1(a, b) or check1(b, a)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean checkPalindromeFormation(String a, String b) {
        return check1(a, b) || check1(b, a);
    }

    private boolean check1(String a, String b) {
        int i = 0;
        int j = b.length() - 1;
        while (i < j && a.charAt(i) == b.charAt(j)) {
            i++;
            j--;
        }
        return i >= j || check2(a, i, j) || check2(b, i, j);
    }

    private boolean check2(String a, int i, int j) {
        while (i < j && a.charAt(i) == a.charAt(j)) {
            i++;
            j--;
        }
        return i >= j;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool checkPalindromeFormation(string a, string b) {
        return check1(a, b) || check1(b, a);
    }

private:
    bool check1(string& a, string& b) {
        int i = 0, j = b.size() - 1;
        while (i < j && a[i] == b[j]) {
            ++i;
            --j;
        }
        return i >= j || check2(a, i, j) || check2(b, i, j);
    }

    bool check2(string& a, int i, int j) {
        while (i <= j && a[i] == a[j]) {
            ++i;
            --j;
        }
        return i >= j;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func checkPalindromeFormation(a string, b string) bool {
	return check1(a, b) || check1(b, a)
}

func check1(a, b string) bool {
	i, j := 0, len(b)-1
	for i < j && a[i] == b[j] {
		i++
		j--
	}
	return i >= j || check2(a, i, j) || check2(b, i, j)
}

func check2(a string, i, j int) bool {
	for i < j && a[i] == a[j] {
		i++
		j--
	}
	return i >= j
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function checkPalindromeFormation(a: string, b: string): boolean {
    const check1 = (a: string, b: string) => {
        let i = 0;
        let j = b.length - 1;
        while (i < j && a.charAt(i) === b.charAt(j)) {
            i++;
            j--;
        }
        return i >= j || check2(a, i, j) || check2(b, i, j);
    };

    const check2 = (a: string, i: number, j: number) => {
        while (i < j && a.charAt(i) === a.charAt(j)) {
            i++;
            j--;
        }
        return i >= j;
    };
    return check1(a, b) || check1(b, a);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn check_palindrome_formation(a: String, b: String) -> bool {
        fn check1(a: &[u8], b: &[u8]) -> bool {
            let (mut i, mut j) = (0, b.len() - 1);
            while i < j && a[i] == b[j] {
                i += 1;
                j -= 1;
            }
            if i >= j {
                return true;
            }
            check2(a, i, j) || check2(b, i, j)
        }

        fn check2(a: &[u8], mut i: usize, mut j: usize) -> bool {
            while i < j && a[i] == a[j] {
                i += 1;
                j -= 1;
            }
            i >= j
        }

        let a = a.as_bytes();
        let b = b.as_bytes();
        check1(a, b) || check1(b, a)
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个字符串&nbsp;<code>a</code> 和&nbsp;<code>b</code>&nbsp;，它们长度相同。请你选择一个下标，将两个字符串都在&nbsp;<strong>相同的下标 </strong>分割开。由&nbsp;<code>a</code>&nbsp;可以得到两个字符串：&nbsp;<code>a<sub>prefix</sub></code>&nbsp;和&nbsp;<code>a<sub>suffix</sub></code>&nbsp;，满足&nbsp;<code>a = a<sub>prefix</sub> + a<sub>suffix</sub></code><sub>&nbsp;</sub>，同理，由&nbsp;<code>b</code> 可以得到两个字符串&nbsp;<code>b<sub>prefix</sub></code> 和&nbsp;<code>b<sub>suffix</sub></code>&nbsp;，满足&nbsp;<code>b = b<sub>prefix</sub> + b<sub>suffix</sub></code>&nbsp;。请你判断&nbsp;<code>a<sub>prefix</sub> + b<sub>suffix</sub></code> 或者&nbsp;<code>b<sub>prefix</sub> + a<sub>suffix</sub></code>&nbsp;能否构成回文串。</p>

<p>当你将一个字符串&nbsp;<code>s</code>&nbsp;分割成&nbsp;<code>s<sub>prefix</sub></code> 和&nbsp;<code>s<sub>suffix</sub></code>&nbsp;时，&nbsp;<code>s<sub>suffix</sub></code> 或者&nbsp;<code>s<sub>prefix</sub></code> 可以为空。比方说，&nbsp;<code>s = "abc"</code>&nbsp;那么&nbsp;<code>"" + "abc"</code>&nbsp;，&nbsp;<code>"a" + "bc"&nbsp;</code>，&nbsp;<code>"ab" + "c"</code>&nbsp;和&nbsp;<code>"abc" + ""</code>&nbsp;都是合法分割。</p>

<p>如果 <strong>能构成回文字符串</strong> ，那么请返回&nbsp;<code>true</code>，否则返回<em>&nbsp;</em><code>false</code>&nbsp;。</p>

<p><strong>注意</strong>，&nbsp;<code>x + y</code>&nbsp;表示连接字符串&nbsp;<code>x</code> 和&nbsp;<code>y</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>a = "x", b = "y"
<b>输出：</b>true
<b>解释：</b>如果 a 或者 b 是回文串，那么答案一定为 true ，因为你可以如下分割：
a<sub>prefix</sub> = "", a<sub>suffix</sub> = "x"
b<sub>prefix</sub> = "", b<sub>suffix</sub> = "y"
那么 a<sub>prefix</sub> + b<sub>suffix</sub> = "" + "y" = "y" 是回文串。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>a = "xbdef", b = "xecab"
<strong>输出：</strong>false
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>a = "ulacfd", b = "jizalu"
<b>输出：</b>true
<b>解释：</b>在下标为 3 处分割：
a<sub>prefix</sub> = "ula", a<sub>suffix</sub> = "cfd"
b<sub>prefix</sub> = "jiz", b<sub>suffix</sub> = "alu"
那么 a<sub>prefix</sub> + b<sub>suffix</sub> = "ula" + "alu" = "ulaalu" 是回文串。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= a.length, b.length &lt;= 10<sup>5</sup></code></li>
	<li><code>a.length == b.length</code></li>
	<li><code>a</code> 和&nbsp;<code>b</code>&nbsp;都只包含小写英文字母</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双指针

我们可以使用双指针，其中一个指针 $i$ 从字符串 $a$ 的头部开始，另一个指针 $j$ 从字符串 $b$ 的尾部开始，如果两个指针指向的字符相等，那么两个指针同时往中间移动，直到遇到不同的字符或两指针交叉。

如果两指针交叉，即 $i \geq j$，说明 $prefix$ 和 $suffix$ 已经可以得到回文串，返回 `true`；否则，我们还需要判断 $a[i,...j]$ 或者 $b[i,...j]$ 是否是回文串，若是，返回 `true`。

否则，我们尝试交换两个字符串 $a$ 和 $b$，重复上述同样的过程。

时间复杂度 $O(n)$，空间复杂度 $O(1)$。其中 $n$ 是字符串 $a$ 或 $b$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def checkPalindromeFormation(self, a: str, b: str) -> bool:
        def check1(a: str, b: str) -> bool:
            i, j = 0, len(b) - 1
            while i < j and a[i] == b[j]:
                i, j = i + 1, j - 1
            return i >= j or check2(a, i, j) or check2(b, i, j)

        def check2(a: str, i: int, j: int) -> bool:
            return a[i : j + 1] == a[i : j + 1][::-1]

        return check1(a, b) or check1(b, a)
```

#### Java

```java
class Solution {
    public boolean checkPalindromeFormation(String a, String b) {
        return check1(a, b) || check1(b, a);
    }

    private boolean check1(String a, String b) {
        int i = 0;
        int j = b.length() - 1;
        while (i < j && a.charAt(i) == b.charAt(j)) {
            i++;
            j--;
        }
        return i >= j || check2(a, i, j) || check2(b, i, j);
    }

    private boolean check2(String a, int i, int j) {
        while (i < j && a.charAt(i) == a.charAt(j)) {
            i++;
            j--;
        }
        return i >= j;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool checkPalindromeFormation(string a, string b) {
        return check1(a, b) || check1(b, a);
    }

private:
    bool check1(string& a, string& b) {
        int i = 0, j = b.size() - 1;
        while (i < j && a[i] == b[j]) {
            ++i;
            --j;
        }
        return i >= j || check2(a, i, j) || check2(b, i, j);
    }

    bool check2(string& a, int i, int j) {
        while (i <= j && a[i] == a[j]) {
            ++i;
            --j;
        }
        return i >= j;
    }
};
```

#### Go

```go
func checkPalindromeFormation(a string, b string) bool {
	return check1(a, b) || check1(b, a)
}

func check1(a, b string) bool {
	i, j := 0, len(b)-1
	for i < j && a[i] == b[j] {
		i++
		j--
	}
	return i >= j || check2(a, i, j) || check2(b, i, j)
}

func check2(a string, i, j int) bool {
	for i < j && a[i] == a[j] {
		i++
		j--
	}
	return i >= j
}
```

#### TypeScript

```ts
function checkPalindromeFormation(a: string, b: string): boolean {
    const check1 = (a: string, b: string) => {
        let i = 0;
        let j = b.length - 1;
        while (i < j && a.charAt(i) === b.charAt(j)) {
            i++;
            j--;
        }
        return i >= j || check2(a, i, j) || check2(b, i, j);
    };

    const check2 = (a: string, i: number, j: number) => {
        while (i < j && a.charAt(i) === a.charAt(j)) {
            i++;
            j--;
        }
        return i >= j;
    };
    return check1(a, b) || check1(b, a);
}
```

#### Rust

```rust
impl Solution {
    pub fn check_palindrome_formation(a: String, b: String) -> bool {
        fn check1(a: &[u8], b: &[u8]) -> bool {
            let (mut i, mut j) = (0, b.len() - 1);
            while i < j && a[i] == b[j] {
                i += 1;
                j -= 1;
            }
            if i >= j {
                return true;
            }
            check2(a, i, j) || check2(b, i, j)
        }

        fn check2(a: &[u8], mut i: usize, mut j: usize) -> bool {
            while i < j && a[i] == a[j] {
                i += 1;
                j -= 1;
            }
            i >= j
        }

        let a = a.as_bytes();
        let b = b.as_bytes();
        check1(a, b) || check1(b, a)
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1617. 统计子树中城市之间最大距离](https://leetcode.cn/problems/count-subtrees-with-max-distance-between-cities){#1617}

{{< tabs "1617" >}}

{{% tab "python" %}}
```python
class Solution:
    def countSubgraphsForEachDiameter(
        self, n: int, edges: List[List[int]]
    ) -> List[int]:
        def bfs(u: int) -> int:
            d = -1
            q = deque([u])
            nonlocal msk, nxt
            msk ^= 1 << u
            while q:
                d += 1
                for _ in range(len(q)):
                    nxt = u = q.popleft()
                    for v in g[u]:
                        if msk >> v & 1:
                            msk ^= 1 << v
                            q.append(v)
            return d

        g = defaultdict(list)
        for u, v in edges:
            u, v = u - 1, v - 1
            g[u].append(v)
            g[v].append(u)
        ans = [0] * (n - 1)
        nxt = 0
        for mask in range(1, 1 << n):
            if mask & (mask - 1) == 0:
                continue
            msk = mask
            cur = msk.bit_length() - 1
            bfs(cur)
            if msk == 0:
                msk = mask
                mx = bfs(nxt)
                ans[mx - 1] += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private List<Integer>[] g;
    private int msk;
    private int nxt;

    public int[] countSubgraphsForEachDiameter(int n, int[][] edges) {
        g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (int[] e : edges) {
            int u = e[0] - 1, v = e[1] - 1;
            g[u].add(v);
            g[v].add(u);
        }
        int[] ans = new int[n - 1];
        for (int mask = 1; mask < 1 << n; ++mask) {
            if ((mask & (mask - 1)) == 0) {
                continue;
            }
            msk = mask;
            int cur = 31 - Integer.numberOfLeadingZeros(msk);
            bfs(cur);
            if (msk == 0) {
                msk = mask;
                int mx = bfs(nxt);
                ++ans[mx - 1];
            }
        }
        return ans;
    }

    private int bfs(int u) {
        int d = -1;
        Deque<Integer> q = new ArrayDeque<>();
        q.offer(u);
        msk ^= 1 << u;
        while (!q.isEmpty()) {
            ++d;
            for (int k = q.size(); k > 0; --k) {
                u = q.poll();
                nxt = u;
                for (int v : g[u]) {
                    if ((msk >> v & 1) == 1) {
                        msk ^= 1 << v;
                        q.offer(v);
                    }
                }
            }
        }
        return d;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        for (auto& e : edges) {
            int u = e[0] - 1, v = e[1] - 1;
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
        vector<int> ans(n - 1);
        int nxt = 0, msk = 0;
        auto bfs = [&](int u) -> int {
            int d = -1;
            msk ^= 1 << u;
            queue<int> q{{u}};
            while (!q.empty()) {
                ++d;
                for (int k = q.size(); k; --k) {
                    u = q.front();
                    nxt = u;
                    q.pop();
                    for (int& v : g[u]) {
                        if (msk >> v & 1) {
                            msk ^= 1 << v;
                            q.push(v);
                        }
                    }
                }
            }
            return d;
        };
        for (int mask = 1; mask < 1 << n; ++mask) {
            if ((mask & (mask - 1)) == 0) {
                continue;
            }
            msk = mask;
            int cur = 31 - __builtin_clz(msk);
            bfs(cur);
            if (msk == 0) {
                msk = mask;
                int mx = bfs(nxt);
                ++ans[mx - 1];
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countSubgraphsForEachDiameter(n int, edges [][]int) []int {
	g := make([][]int, n)
	for _, e := range edges {
		u, v := e[0]-1, e[1]-1
		g[u] = append(g[u], v)
		g[v] = append(g[v], u)
	}
	ans := make([]int, n-1)
	var msk, nxt int
	bfs := func(u int) int {
		d := -1
		q := []int{u}
		msk ^= 1 << u
		for len(q) > 0 {
			d++
			for k := len(q); k > 0; k-- {
				u = q[0]
				q = q[1:]
				nxt = u
				for _, v := range g[u] {
					if msk>>v&1 == 1 {
						msk ^= 1 << v
						q = append(q, v)
					}
				}
			}
		}
		return d
	}
	for mask := 1; mask < 1<<n; mask++ {
		if mask&(mask-1) == 0 {
			continue
		}
		msk = mask
		cur := bits.Len(uint(msk)) - 1
		bfs(cur)
		if msk == 0 {
			msk = mask
			mx := bfs(nxt)
			ans[mx-1]++
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countSubgraphsForEachDiameter(n: number, edges: number[][]): number[] {
    const g = Array.from({ length: n }, () => []);
    for (const [u, v] of edges) {
        g[u - 1].push(v - 1);
        g[v - 1].push(u - 1);
    }
    const ans: number[] = new Array(n - 1).fill(0);
    let [msk, nxt] = [0, 0];
    const bfs = (u: number) => {
        let d = -1;
        const q = [u];
        msk ^= 1 << u;
        while (q.length) {
            ++d;
            for (let k = q.length; k; --k) {
                u = q.shift()!;
                nxt = u;
                for (const v of g[u]) {
                    if ((msk >> v) & 1) {
                        msk ^= 1 << v;
                        q.push(v);
                    }
                }
            }
        }
        return d;
    };
    for (let mask = 1; mask < 1 << n; ++mask) {
        if ((mask & (mask - 1)) === 0) {
            continue;
        }
        msk = mask;
        const cur = 31 - numberOfLeadingZeros(msk);
        bfs(cur);
        if (msk === 0) {
            msk = mask;
            const mx = bfs(nxt);
            ++ans[mx - 1];
        }
    }
    return ans;
}

function numberOfLeadingZeros(i: number): number {
    if (i == 0) return 32;
    let n = 1;
    if (i >>> 16 == 0) {
        n += 16;
        i <<= 16;
    }
    if (i >>> 24 == 0) {
        n += 8;
        i <<= 8;
    }
    if (i >>> 28 == 0) {
        n += 4;
        i <<= 4;
    }
    if (i >>> 30 == 0) {
        n += 2;
        i <<= 2;
    }
    n -= i >>> 31;
    return n;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你 <code>n</code> 个城市，编号为从 <code>1</code> 到 <code>n</code> 。同时给你一个大小为 <code>n-1</code> 的数组 <code>edges</code> ，其中 <code>edges[i] = [u<sub>i</sub>, v<sub>i</sub>]</code> 表示城市 <code>u<sub>i</sub></code> 和 <code>v<sub>i</sub></code><sub> </sub>之间有一条双向边。题目保证任意城市之间只有唯一的一条路径。换句话说，所有城市形成了一棵 <strong>树</strong> 。</p>

<p>一棵 <strong>子树</strong> 是城市的一个子集，且子集中任意城市之间可以通过子集中的其他城市和边到达。两个子树被认为不一样的条件是至少有一个城市在其中一棵子树中存在，但在另一棵子树中不存在。</p>

<p>对于 <code>d</code> 从 <code>1</code> 到 <code>n-1</code> ，请你找到城市间 <strong>最大距离</strong> 恰好为 <code>d</code> 的所有子树数目。</p>

<p>请你返回一个大小为 <code>n-1</code> 的数组，其中第<em> </em><code>d</code><em> </em>个元素（<strong>下标从 1 开始</strong>）是城市间 <strong>最大距离</strong> 恰好等于 <code>d</code> 的子树数目。</p>

<p><strong>请注意</strong>，两个城市间距离定义为它们之间需要经过的边的数目。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1600-1699/1617.Count%20Subtrees%20With%20Max%20Distance%20Between%20Cities/images/p1.png" style="width: 161px; height: 181px;" /></strong></p>

<pre>
<b>输入：</b>n = 4, edges = [[1,2],[2,3],[2,4]]
<b>输出：</b>[3,4,0]
<strong>解释：
</strong>子树 {1,2}, {2,3} 和 {2,4} 最大距离都是 1 。
子树 {1,2,3}, {1,2,4}, {2,3,4} 和 {1,2,3,4} 最大距离都为 2 。
不存在城市间最大距离为 3 的子树。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>n = 2, edges = [[1,2]]
<b>输出：</b>[1]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>n = 3, edges = [[1,2],[2,3]]
<b>输出：</b>[2,1]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 <= n <= 15</code></li>
	<li><code>edges.length == n-1</code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>1 <= u<sub>i</sub>, v<sub>i</sub> <= n</code></li>
	<li>题目保证 <code>(u<sub>i</sub>, v<sub>i</sub>)</code> 所表示的边互不相同。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二进制枚举 + BFS 或 DFS

我们注意到 $n \leq 15$，因此可以考虑使用二进制枚举的方法枚举所有的子树。而子树中节点的最大距离，其实就是子树中两个节点之间的最长路径，也即是树的直径，求解树的直径一般可以使用 DFS 或 BFS，先找到树直径的一个端点，然后再从该端点出发，找到树的另一个端点，这两个端点之间的路径长度就是树的直径。

接下来，我们详细说明具体的代码实现。

我们先根据数组 $edges$ 构建出邻接表 $g$，其中 $g[u]$ 表示节点 $u$ 的所有邻接节点。

用一个二进制数 $mask$ 表示子树，其中 $mask$ 的第 $i$ 位为 $1$ 表示节点 $i$ 在子树中，否则表示节点 $i$ 不在子树中。每个节点都有两种状态，即在子树中或不在子树中，有 $n$ 个节点，因此一共有 $2^n$ 种状态。

接下来，我们在 $[1,..2^n-1]$ 的范围内枚举子树 $mask$，对于每个子树：

如果 $mask$ 的二进制表示中只有一个二进制位为 $1$，即 $mask \in [1,2,4,8,\cdots,2^{n-1}]$，则跳过该 $mask$，因为这些 $mask$ 表示的子树只有一个节点，不符合题意；

否则，我们找到 $mask$ 的二进制表示中最高位的二进制位为 $1$ 的位置，记为 $cur$。然后从节点 $cur$ 出发，通过深度优先搜索或者广度优先搜索，找到树直径的一个端点 $nxt$，然后我们再从节点 $nxt$ 出发，同样通过深度优先搜索或者广度优先搜索，过程中记录下最大距离 $mx$。

当走到最深的节点时，即可得知树的直径。此时我们更新答案数组 $ans$，将 $ans[mx-1]$ 的值加 $1$。注意，这里是 $mx-1$，因为题目中的最大距离是从 $1$ 开始计数的。

最后，枚举完所有的子树，返回答案数组 $ans$ 即可。

时间复杂度 $O(2^n \times n)$，空间复杂度 $O(n)$。其中 $n$ 为节点个数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countSubgraphsForEachDiameter(
        self, n: int, edges: List[List[int]]
    ) -> List[int]:
        def dfs(u: int, d: int = 0):
            nonlocal mx, nxt, msk
            if mx < d:
                mx, nxt = d, u
            msk ^= 1 << u
            for v in g[u]:
                if msk >> v & 1:
                    dfs(v, d + 1)

        g = defaultdict(list)
        for u, v in edges:
            u, v = u - 1, v - 1
            g[u].append(v)
            g[v].append(u)
        ans = [0] * (n - 1)
        nxt = mx = 0
        for mask in range(1, 1 << n):
            if mask & (mask - 1) == 0:
                continue
            msk, mx = mask, 0
            cur = msk.bit_length() - 1
            dfs(cur)
            if msk == 0:
                msk, mx = mask, 0
                dfs(nxt)
                ans[mx - 1] += 1
        return ans
```

#### Java

```java
class Solution {
    private List<Integer>[] g;
    private int msk;
    private int nxt;
    private int mx;

    public int[] countSubgraphsForEachDiameter(int n, int[][] edges) {
        g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (int[] e : edges) {
            int u = e[0] - 1, v = e[1] - 1;
            g[u].add(v);
            g[v].add(u);
        }
        int[] ans = new int[n - 1];
        for (int mask = 1; mask < 1 << n; ++mask) {
            if ((mask & (mask - 1)) == 0) {
                continue;
            }
            msk = mask;
            mx = 0;
            int cur = 31 - Integer.numberOfLeadingZeros(msk);
            dfs(cur, 0);
            if (msk == 0) {
                msk = mask;
                mx = 0;
                dfs(nxt, 0);
                ++ans[mx - 1];
            }
        }
        return ans;
    }

    private void dfs(int u, int d) {
        msk ^= 1 << u;
        if (mx < d) {
            mx = d;
            nxt = u;
        }
        for (int v : g[u]) {
            if ((msk >> v & 1) == 1) {
                dfs(v, d + 1);
            }
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        for (auto& e : edges) {
            int u = e[0] - 1, v = e[1] - 1;
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
        vector<int> ans(n - 1);
        int nxt = 0, msk = 0, mx = 0;
        function<void(int, int)> dfs = [&](int u, int d) {
            msk ^= 1 << u;
            if (mx < d) {
                mx = d;
                nxt = u;
            }
            for (int& v : g[u]) {
                if (msk >> v & 1) {
                    dfs(v, d + 1);
                }
            }
        };
        for (int mask = 1; mask < 1 << n; ++mask) {
            if ((mask & (mask - 1)) == 0) {
                continue;
            }
            msk = mask;
            mx = 0;
            int cur = 31 - __builtin_clz(msk);
            dfs(cur, 0);
            if (msk == 0) {
                msk = mask;
                mx = 0;
                dfs(nxt, 0);
                ++ans[mx - 1];
            }
        }
        return ans;
    }
};
```

#### Go

```go
func countSubgraphsForEachDiameter(n int, edges [][]int) []int {
	g := make([][]int, n)
	for _, e := range edges {
		u, v := e[0]-1, e[1]-1
		g[u] = append(g[u], v)
		g[v] = append(g[v], u)
	}
	ans := make([]int, n-1)
	var msk, nxt, mx int
	var dfs func(int, int)
	dfs = func(u, d int) {
		msk ^= 1 << u
		if mx < d {
			mx, nxt = d, u
		}
		for _, v := range g[u] {
			if msk>>v&1 == 1 {
				dfs(v, d+1)
			}
		}
	}
	for mask := 1; mask < 1<<n; mask++ {
		if mask&(mask-1) == 0 {
			continue
		}
		msk, mx = mask, 0
		cur := bits.Len(uint(msk)) - 1
		dfs(cur, 0)
		if msk == 0 {
			msk, mx = mask, 0
			dfs(nxt, 0)
			ans[mx-1]++
		}
	}
	return ans
}
```

#### TypeScript

```ts
function countSubgraphsForEachDiameter(n: number, edges: number[][]): number[] {
    const g = Array.from({ length: n }, () => []);
    for (const [u, v] of edges) {
        g[u - 1].push(v - 1);
        g[v - 1].push(u - 1);
    }
    const ans: number[] = new Array(n - 1).fill(0);
    let [mx, msk, nxt] = [0, 0, 0];
    const dfs = (u: number, d: number) => {
        if (mx < d) {
            mx = d;
            nxt = u;
        }
        msk ^= 1 << u;
        for (const v of g[u]) {
            if ((msk >> v) & 1) {
                dfs(v, d + 1);
            }
        }
    };
    for (let mask = 1; mask < 1 << n; ++mask) {
        if ((mask & (mask - 1)) === 0) {
            continue;
        }
        msk = mask;
        mx = 0;
        const cur = 31 - numberOfLeadingZeros(msk);
        dfs(cur, 0);
        if (msk === 0) {
            msk = mask;
            mx = 0;
            dfs(nxt, 0);
            ++ans[mx - 1];
        }
    }
    return ans;
}

function numberOfLeadingZeros(i: number): number {
    if (i == 0) return 32;
    let n = 1;
    if (i >>> 16 == 0) {
        n += 16;
        i <<= 16;
    }
    if (i >>> 24 == 0) {
        n += 8;
        i <<= 8;
    }
    if (i >>> 28 == 0) {
        n += 4;
        i <<= 4;
    }
    if (i >>> 30 == 0) {
        n += 2;
        i <<= 2;
    }
    n -= i >>> 31;
    return n;
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
    def countSubgraphsForEachDiameter(
        self, n: int, edges: List[List[int]]
    ) -> List[int]:
        def bfs(u: int) -> int:
            d = -1
            q = deque([u])
            nonlocal msk, nxt
            msk ^= 1 << u
            while q:
                d += 1
                for _ in range(len(q)):
                    nxt = u = q.popleft()
                    for v in g[u]:
                        if msk >> v & 1:
                            msk ^= 1 << v
                            q.append(v)
            return d

        g = defaultdict(list)
        for u, v in edges:
            u, v = u - 1, v - 1
            g[u].append(v)
            g[v].append(u)
        ans = [0] * (n - 1)
        nxt = 0
        for mask in range(1, 1 << n):
            if mask & (mask - 1) == 0:
                continue
            msk = mask
            cur = msk.bit_length() - 1
            bfs(cur)
            if msk == 0:
                msk = mask
                mx = bfs(nxt)
                ans[mx - 1] += 1
        return ans
```

#### Java

```java
class Solution {
    private List<Integer>[] g;
    private int msk;
    private int nxt;

    public int[] countSubgraphsForEachDiameter(int n, int[][] edges) {
        g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (int[] e : edges) {
            int u = e[0] - 1, v = e[1] - 1;
            g[u].add(v);
            g[v].add(u);
        }
        int[] ans = new int[n - 1];
        for (int mask = 1; mask < 1 << n; ++mask) {
            if ((mask & (mask - 1)) == 0) {
                continue;
            }
            msk = mask;
            int cur = 31 - Integer.numberOfLeadingZeros(msk);
            bfs(cur);
            if (msk == 0) {
                msk = mask;
                int mx = bfs(nxt);
                ++ans[mx - 1];
            }
        }
        return ans;
    }

    private int bfs(int u) {
        int d = -1;
        Deque<Integer> q = new ArrayDeque<>();
        q.offer(u);
        msk ^= 1 << u;
        while (!q.isEmpty()) {
            ++d;
            for (int k = q.size(); k > 0; --k) {
                u = q.poll();
                nxt = u;
                for (int v : g[u]) {
                    if ((msk >> v & 1) == 1) {
                        msk ^= 1 << v;
                        q.offer(v);
                    }
                }
            }
        }
        return d;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        for (auto& e : edges) {
            int u = e[0] - 1, v = e[1] - 1;
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
        vector<int> ans(n - 1);
        int nxt = 0, msk = 0;
        auto bfs = [&](int u) -> int {
            int d = -1;
            msk ^= 1 << u;
            queue<int> q{{u}};
            while (!q.empty()) {
                ++d;
                for (int k = q.size(); k; --k) {
                    u = q.front();
                    nxt = u;
                    q.pop();
                    for (int& v : g[u]) {
                        if (msk >> v & 1) {
                            msk ^= 1 << v;
                            q.push(v);
                        }
                    }
                }
            }
            return d;
        };
        for (int mask = 1; mask < 1 << n; ++mask) {
            if ((mask & (mask - 1)) == 0) {
                continue;
            }
            msk = mask;
            int cur = 31 - __builtin_clz(msk);
            bfs(cur);
            if (msk == 0) {
                msk = mask;
                int mx = bfs(nxt);
                ++ans[mx - 1];
            }
        }
        return ans;
    }
};
```

#### Go

```go
func countSubgraphsForEachDiameter(n int, edges [][]int) []int {
	g := make([][]int, n)
	for _, e := range edges {
		u, v := e[0]-1, e[1]-1
		g[u] = append(g[u], v)
		g[v] = append(g[v], u)
	}
	ans := make([]int, n-1)
	var msk, nxt int
	bfs := func(u int) int {
		d := -1
		q := []int{u}
		msk ^= 1 << u
		for len(q) > 0 {
			d++
			for k := len(q); k > 0; k-- {
				u = q[0]
				q = q[1:]
				nxt = u
				for _, v := range g[u] {
					if msk>>v&1 == 1 {
						msk ^= 1 << v
						q = append(q, v)
					}
				}
			}
		}
		return d
	}
	for mask := 1; mask < 1<<n; mask++ {
		if mask&(mask-1) == 0 {
			continue
		}
		msk = mask
		cur := bits.Len(uint(msk)) - 1
		bfs(cur)
		if msk == 0 {
			msk = mask
			mx := bfs(nxt)
			ans[mx-1]++
		}
	}
	return ans
}
```

#### TypeScript

```ts
function countSubgraphsForEachDiameter(n: number, edges: number[][]): number[] {
    const g = Array.from({ length: n }, () => []);
    for (const [u, v] of edges) {
        g[u - 1].push(v - 1);
        g[v - 1].push(u - 1);
    }
    const ans: number[] = new Array(n - 1).fill(0);
    let [msk, nxt] = [0, 0];
    const bfs = (u: number) => {
        let d = -1;
        const q = [u];
        msk ^= 1 << u;
        while (q.length) {
            ++d;
            for (let k = q.length; k; --k) {
                u = q.shift()!;
                nxt = u;
                for (const v of g[u]) {
                    if ((msk >> v) & 1) {
                        msk ^= 1 << v;
                        q.push(v);
                    }
                }
            }
        }
        return d;
    };
    for (let mask = 1; mask < 1 << n; ++mask) {
        if ((mask & (mask - 1)) === 0) {
            continue;
        }
        msk = mask;
        const cur = 31 - numberOfLeadingZeros(msk);
        bfs(cur);
        if (msk === 0) {
            msk = mask;
            const mx = bfs(nxt);
            ++ans[mx - 1];
        }
    }
    return ans;
}

function numberOfLeadingZeros(i: number): number {
    if (i == 0) return 32;
    let n = 1;
    if (i >>> 16 == 0) {
        n += 16;
        i <<= 16;
    }
    if (i >>> 24 == 0) {
        n += 8;
        i <<= 8;
    }
    if (i >>> 28 == 0) {
        n += 4;
        i <<= 4;
    }
    if (i >>> 30 == 0) {
        n += 2;
        i <<= 2;
    }
    n -= i >>> 31;
    return n;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1618. 找出适应屏幕的最大字号 🔒](https://leetcode.cn/problems/maximum-font-to-fit-a-sentence-in-a-screen){#1618}

{{< tabs "1618" >}}

{{% tab "python" %}}
```python
# """
# This is FontInfo's API interface.
# You should not implement it, or speculate about its implementation
# """
# class FontInfo(object):
#    Return the width of char ch when fontSize is used.
#    def getWidth(self, fontSize, ch):
#        """
#        :type fontSize: int
#        :type ch: char
#        :rtype int
#        """
#
#    def getHeight(self, fontSize):
#        """
#        :type fontSize: int
#        :rtype int
#        """
class Solution:
    def maxFont(
        self, text: str, w: int, h: int, fonts: List[int], fontInfo: 'FontInfo'
    ) -> int:
        def check(size):
            if fontInfo.getHeight(size) > h:
                return False
            return sum(fontInfo.getWidth(size, c) for c in text) <= w

        left, right = 0, len(fonts) - 1
        ans = -1
        while left < right:
            mid = (left + right + 1) >> 1
            if check(fonts[mid]):
                left = mid
            else:
                right = mid - 1
        return fonts[left] if check(fonts[left]) else -1
```
{{% /tab %}}
{{% tab "java" %}}
```java
/**
 * // This is the FontInfo's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface FontInfo {
 *     // Return the width of char ch when fontSize is used.
 *     public int getWidth(int fontSize, char ch) {}
 *     // Return Height of any char when fontSize is used.
 *     public int getHeight(int fontSize)
 * }
 */
class Solution {
    public int maxFont(String text, int w, int h, int[] fonts, FontInfo fontInfo) {
        int left = 0, right = fonts.length - 1;
        while (left < right) {
            int mid = (left + right + 1) >> 1;
            if (check(text, fonts[mid], w, h, fontInfo)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return check(text, fonts[left], w, h, fontInfo) ? fonts[left] : -1;
    }

    private boolean check(String text, int size, int w, int h, FontInfo fontInfo) {
        if (fontInfo.getHeight(size) > h) {
            return false;
        }
        int width = 0;
        for (char c : text.toCharArray()) {
            width += fontInfo.getWidth(size, c);
        }
        return width <= w;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
/**
 * // This is the FontInfo's API interface.
 * // You should not implement it, or speculate about its implementation
 * class FontInfo {
 *   public:
 *     // Return the width of char ch when fontSize is used.
 *     int getWidth(int fontSize, char ch);
 *
 *     // Return Height of any char when fontSize is used.
 *     int getHeight(int fontSize)
 * };
 */
class Solution {
public:
    int maxFont(string text, int w, int h, vector<int>& fonts, FontInfo fontInfo) {
        auto check = [&](int size) {
            if (fontInfo.getHeight(size) > h) return false;
            int width = 0;
            for (char& c : text) {
                width += fontInfo.getWidth(size, c);
            }
            return width <= w;
        };
        int left = 0, right = fonts.size() - 1;
        while (left < right) {
            int mid = (left + right + 1) >> 1;
            if (check(fonts[mid])) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return check(fonts[left]) ? fonts[left] : -1;
    }
};
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * // This is the FontInfo's API interface.
 * // You should not implement it, or speculate about its implementation
 * function FontInfo() {
 *
 *		@param {number} fontSize
 *		@param {char} ch
 *     	@return {number}
 *     	this.getWidth = function(fontSize, ch) {
 *      	...
 *     	};
 *
 *		@param {number} fontSize
 *     	@return {number}
 *     	this.getHeight = function(fontSize) {
 *      	...
 *     	};
 * };
 */
/**
 * @param {string} text
 * @param {number} w
 * @param {number} h
 * @param {number[]} fonts
 * @param {FontInfo} fontInfo
 * @return {number}
 */
var maxFont = function (text, w, h, fonts, fontInfo) {
    const check = function (size) {
        if (fontInfo.getHeight(size) > h) {
            return false;
        }
        let width = 0;
        for (const c of text) {
            width += fontInfo.getWidth(size, c);
        }
        return width <= w;
    };
    let left = 0;
    let right = fonts.length - 1;
    while (left < right) {
        const mid = (left + right + 1) >> 1;
        if (check(fonts[mid])) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }
    return check(fonts[left]) ? fonts[left] : -1;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个字符串&nbsp;<code>text</code>。并能够在 宽为 <code>w</code> 高为 <code>h</code> 的屏幕上显示该文本。</p>

<p>字体数组中包含按<strong>升序排列</strong>的可用字号，您可以从该数组中选择任何字体大小。</p>

<p>您可以使用<code>FontInfo</code>接口来获取任何<strong>可用字体大小</strong>的任何字符的宽度和高度。</p>

<p><code>FontInfo</code>接口定义如下：</p>

<pre>
interface FontInfo {
  // 返回 fontSize 大小的字符 ch 在屏幕上的宽度。
  // 每调用该函数复杂度为 O(1)
  public int getWidth(int fontSize, char ch);

  // 返回 fontSize 大小的任意字符在屏幕上的高度。
  // 每调用该函数复杂度为 O(1)
  public int getHeight(int fontSize);
}</pre>

<p>一串字符的文本宽度应该是 <strong>每一个字符 </strong>在对应字号<code>(fontSize)</code>下返回的宽度<code>getWidth(fontSize, text[i])</code>的 <strong>总和 </strong>。对应字号的文本高度可由 <code>getHeight(fontSize)</code> 计算得到。</p>

<p><strong>请注意：文本最多只能排放一排</strong></p>

<p>如果使用相同的参数调用 <code>getHeight</code>&nbsp;或&nbsp;<code>getWidth</code> ，则可以保证 <code>FontInfo</code> 将返回相同的值。</p>

<p>同时，对于任何字体大小的&nbsp;<code>fontSize</code> 和任何字符 <code>ch</code> ：</p>

<ul>
	<li><code>getHeight(fontSize) &lt;= getHeight(fontSize+1)</code></li>
	<li><code>getWidth(fontSize, ch) &lt;= getWidth(fontSize+1, ch)</code></li>
</ul>

<p>返回可用于在屏幕上显示文本的最大字体大小。<strong>如果文本不能以任何字体大小显示，则返回-1</strong>。</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> text = "helloworld", w = 80, h = 20, fonts = [6,8,10,12,14,16,18,24,36]
<strong>输出:</strong> 6
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入:</strong> text = "leetcode", w = 1000, h = 50, fonts = [1,2,4]
<strong>输出:</strong> 4
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入:</strong> text = "easyquestion", w = 100, h = 100, fonts = [10,15,20,25]
<strong>输出:</strong> -1
</pre>

<p>&nbsp;</p>

<p><strong>注意:</strong></p>

<ul>
	<li><code>1 &lt;= text.length &lt;= 50000</code></li>
	<li><code>text</code> 只包含小写字母</li>
	<li><code>1 &lt;= w &lt;= 10<sup>7</sup></code></li>
	<li><code>1 &lt;= h &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= fonts.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= fonts[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>fonts&nbsp;</code>已经按升序排序，且不包含重复项。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二分查找

根据题目描述，字体数组按升序排列。因此，我们可以二分枚举字体大小 `fontSize`，找到最大的并且能够在屏幕上显示文本字体大小即可。

时间复杂度 $O(m\log n)$。其中 $m$, $n$ 为文本 `text` 的长度以及字体大小 `fonts` 个数。

关于二分查找，见[整数二分算法模板 2](https://github.com/doocs/leetcode/blob/main/basic/searching/BinarySearch/README.md)。

<!-- tabs:start -->

#### Python3

```python
# """
# This is FontInfo's API interface.
# You should not implement it, or speculate about its implementation
# """
# class FontInfo(object):
#    Return the width of char ch when fontSize is used.
#    def getWidth(self, fontSize, ch):
#        """
#        :type fontSize: int
#        :type ch: char
#        :rtype int
#        """
#
#    def getHeight(self, fontSize):
#        """
#        :type fontSize: int
#        :rtype int
#        """
class Solution:
    def maxFont(
        self, text: str, w: int, h: int, fonts: List[int], fontInfo: 'FontInfo'
    ) -> int:
        def check(size):
            if fontInfo.getHeight(size) > h:
                return False
            return sum(fontInfo.getWidth(size, c) for c in text) <= w

        left, right = 0, len(fonts) - 1
        ans = -1
        while left < right:
            mid = (left + right + 1) >> 1
            if check(fonts[mid]):
                left = mid
            else:
                right = mid - 1
        return fonts[left] if check(fonts[left]) else -1
```

#### Java

```java
/**
 * // This is the FontInfo's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface FontInfo {
 *     // Return the width of char ch when fontSize is used.
 *     public int getWidth(int fontSize, char ch) {}
 *     // Return Height of any char when fontSize is used.
 *     public int getHeight(int fontSize)
 * }
 */
class Solution {
    public int maxFont(String text, int w, int h, int[] fonts, FontInfo fontInfo) {
        int left = 0, right = fonts.length - 1;
        while (left < right) {
            int mid = (left + right + 1) >> 1;
            if (check(text, fonts[mid], w, h, fontInfo)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return check(text, fonts[left], w, h, fontInfo) ? fonts[left] : -1;
    }

    private boolean check(String text, int size, int w, int h, FontInfo fontInfo) {
        if (fontInfo.getHeight(size) > h) {
            return false;
        }
        int width = 0;
        for (char c : text.toCharArray()) {
            width += fontInfo.getWidth(size, c);
        }
        return width <= w;
    }
}
```

#### C++

```cpp
/**
 * // This is the FontInfo's API interface.
 * // You should not implement it, or speculate about its implementation
 * class FontInfo {
 *   public:
 *     // Return the width of char ch when fontSize is used.
 *     int getWidth(int fontSize, char ch);
 *
 *     // Return Height of any char when fontSize is used.
 *     int getHeight(int fontSize)
 * };
 */
class Solution {
public:
    int maxFont(string text, int w, int h, vector<int>& fonts, FontInfo fontInfo) {
        auto check = [&](int size) {
            if (fontInfo.getHeight(size) > h) return false;
            int width = 0;
            for (char& c : text) {
                width += fontInfo.getWidth(size, c);
            }
            return width <= w;
        };
        int left = 0, right = fonts.size() - 1;
        while (left < right) {
            int mid = (left + right + 1) >> 1;
            if (check(fonts[mid])) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return check(fonts[left]) ? fonts[left] : -1;
    }
};
```

#### JavaScript

```js
/**
 * // This is the FontInfo's API interface.
 * // You should not implement it, or speculate about its implementation
 * function FontInfo() {
 *
 *		@param {number} fontSize
 *		@param {char} ch
 *     	@return {number}
 *     	this.getWidth = function(fontSize, ch) {
 *      	...
 *     	};
 *
 *		@param {number} fontSize
 *     	@return {number}
 *     	this.getHeight = function(fontSize) {
 *      	...
 *     	};
 * };
 */
/**
 * @param {string} text
 * @param {number} w
 * @param {number} h
 * @param {number[]} fonts
 * @param {FontInfo} fontInfo
 * @return {number}
 */
var maxFont = function (text, w, h, fonts, fontInfo) {
    const check = function (size) {
        if (fontInfo.getHeight(size) > h) {
            return false;
        }
        let width = 0;
        for (const c of text) {
            width += fontInfo.getWidth(size, c);
        }
        return width <= w;
    };
    let left = 0;
    let right = fonts.length - 1;
    while (left < right) {
        const mid = (left + right + 1) >> 1;
        if (check(fonts[mid])) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }
    return check(fonts[left]) ? fonts[left] : -1;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1619. 删除某些元素后的数组均值](https://leetcode.cn/problems/mean-of-array-after-removing-some-elements){#1619}

{{< tabs "1619" >}}

{{% tab "python" %}}
```python
class Solution:
    def trimMean(self, arr: List[int]) -> float:
        n = len(arr)
        start, end = int(n * 0.05), int(n * 0.95)
        arr.sort()
        t = arr[start:end]
        return round(sum(t) / len(t), 5)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public double trimMean(int[] arr) {
        Arrays.sort(arr);
        int n = arr.length;
        double s = 0;
        for (int start = (int) (n * 0.05), i = start; i < n - start; ++i) {
            s += arr[i];
        }
        return s / (n * 0.9);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    double trimMean(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        double s = 0;
        for (int start = (int) (n * 0.05), i = start; i < n - start; ++i)
            s += arr[i];
        return s / (n * 0.9);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func trimMean(arr []int) float64 {
	sort.Ints(arr)
	n := len(arr)
	sum := 0.0
	for i := n / 20; i < n-n/20; i++ {
		sum += float64(arr[i])
	}
	return sum / (float64(n) * 0.9)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function trimMean(arr: number[]): number {
    arr.sort((a, b) => a - b);
    let n = arr.length,
        rmLen = n * 0.05;
    let sum = 0;
    for (let i = rmLen; i < n - rmLen; i++) {
        sum += arr[i];
    }
    return sum / (n * 0.9);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn trim_mean(mut arr: Vec<i32>) -> f64 {
        arr.sort();
        let n = arr.len();
        let count = ((n as f64) * 0.05).floor() as usize;
        let mut sum = 0;
        for i in count..n - count {
            sum += arr[i];
        }
        (sum as f64) / ((n as f64) * 0.9)
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>arr</code> ，请你删除最小 <code>5%</code> 的数字和最大 <code>5%</code> 的数字后，剩余数字的平均值。</p>

<p>与 <strong>标准答案</strong> 误差在 <code>10<sup>-5</sup></code> 的结果都被视为正确结果。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>arr = [1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3]
<b>输出：</b>2.00000
<b>解释：</b>删除数组中最大和最小的元素后，所有元素都等于 2，所以平均值为 2 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>arr = [6,2,7,5,1,2,0,3,10,2,5,0,5,5,0,8,7,6,8,0]
<b>输出：</b>4.00000
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>arr = [6,0,7,0,7,5,7,8,3,4,0,7,8,1,6,8,1,1,2,4,8,1,9,5,4,3,8,5,10,8,6,6,1,0,6,10,8,2,3,4]
<b>输出：</b>4.77778
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<b>输入：</b>arr = [9,7,8,7,7,8,4,4,6,8,8,7,6,8,8,9,2,6,0,0,1,10,8,6,3,3,5,1,10,9,0,7,10,0,10,4,1,10,6,9,3,6,0,0,2,7,0,6,7,2,9,7,7,3,0,1,6,1,10,3]
<b>输出：</b>5.27778
</pre>

<p><strong>示例 5：</strong></p>

<pre>
<b>输入：</b>arr = [4,8,4,10,0,7,1,3,7,8,8,3,4,1,6,2,1,1,8,0,9,8,0,3,9,10,3,10,1,10,7,3,2,1,4,9,10,7,6,4,0,8,5,1,2,1,6,2,5,0,7,10,9,10,3,7,10,5,8,5,7,6,7,6,10,9,5,10,5,5,7,2,10,7,7,8,2,0,1,1]
<b>输出：</b>5.29167
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>20 <= arr.length <= 1000</code></li>
	<li><code>arr.length</code><b> </b>是 <code>20</code> 的<strong> 倍数</strong> </li>
	<li><code>0 <= arr[i] <= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

直接模拟。

先对数组 `arr` 排序，然后截取中间的 90% 个元素，求平均值。

时间复杂度 $O(n\log n)$。其中 $n$ 为数组 `arr` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def trimMean(self, arr: List[int]) -> float:
        n = len(arr)
        start, end = int(n * 0.05), int(n * 0.95)
        arr.sort()
        t = arr[start:end]
        return round(sum(t) / len(t), 5)
```

#### Java

```java
class Solution {
    public double trimMean(int[] arr) {
        Arrays.sort(arr);
        int n = arr.length;
        double s = 0;
        for (int start = (int) (n * 0.05), i = start; i < n - start; ++i) {
            s += arr[i];
        }
        return s / (n * 0.9);
    }
}
```

#### C++

```cpp
class Solution {
public:
    double trimMean(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        double s = 0;
        for (int start = (int) (n * 0.05), i = start; i < n - start; ++i)
            s += arr[i];
        return s / (n * 0.9);
    }
};
```

#### Go

```go
func trimMean(arr []int) float64 {
	sort.Ints(arr)
	n := len(arr)
	sum := 0.0
	for i := n / 20; i < n-n/20; i++ {
		sum += float64(arr[i])
	}
	return sum / (float64(n) * 0.9)
}
```

#### TypeScript

```ts
function trimMean(arr: number[]): number {
    arr.sort((a, b) => a - b);
    let n = arr.length,
        rmLen = n * 0.05;
    let sum = 0;
    for (let i = rmLen; i < n - rmLen; i++) {
        sum += arr[i];
    }
    return sum / (n * 0.9);
}
```

#### Rust

```rust
impl Solution {
    pub fn trim_mean(mut arr: Vec<i32>) -> f64 {
        arr.sort();
        let n = arr.len();
        let count = ((n as f64) * 0.05).floor() as usize;
        let mut sum = 0;
        for i in count..n - count {
            sum += arr[i];
        }
        (sum as f64) / ((n as f64) * 0.9)
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
