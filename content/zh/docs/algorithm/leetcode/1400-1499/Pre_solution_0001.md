---
title: "1400_构造 K 个回文字符串"
date: 2025-10-08T18:37:18+08:00
weight: 1
tags: [位运算, 几何, 动态规划, 博弈, 哈希表, 堆（优先队列）, 字符串, 字符串匹配, 排序, 数学, 数据库, 数组, 树状数组, 模拟, 计数, 贪心]
---

{{< markmap >}}
### [1400_构造 K 个回文字符串](#1400)
#### [贪心](#1400)
#### [哈希表](#1400)
#### [字符串](#1400)
#### [计数](#1400)
### [1401_圆和矩形是否有重叠](#1401)
#### [几何](#1401)
#### [数学](#1401)
### [1402_做菜顺序](#1402)
#### [贪心](#1402)
#### [数组](#1402)
#### [动态规划](#1402)
#### [排序](#1402)
### [1403_非递增顺序的最小子序列](#1403)
#### [贪心](#1403)
#### [数组](#1403)
#### [排序](#1403)
### [1404_将二进制表示减到 1 的步骤数](#1404)
#### [位运算](#1404)
#### [字符串](#1404)
#### [模拟](#1404)
### [1405_最长快乐字符串](#1405)
#### [贪心](#1405)
#### [字符串](#1405)
#### [堆（优先队列）](#1405)
### [1406_石子游戏 III](#1406)
#### [数组](#1406)
#### [数学](#1406)
#### [动态规划](#1406)
#### [博弈](#1406)
### [1407_排名靠前的旅行者](#1407)
#### [数据库](#1407)
### [1408_数组中的字符串匹配](#1408)
#### [数组](#1408)
#### [字符串](#1408)
#### [字符串匹配](#1408)
### [1409_查询带键的排列](#1409)
#### [树状数组](#1409)
#### [数组](#1409)
#### [模拟](#1409)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1400_构造 K 个回文字符串
___
#### 贪心
___
#### 哈希表
___
#### 字符串
___
#### 计数
---
### 1401_圆和矩形是否有重叠
___
#### 几何
___
#### 数学
---
### 1402_做菜顺序
___
#### 贪心
___
#### 数组
___
#### 动态规划
___
#### 排序
---
### 1403_非递增顺序的最小子序列
___
#### 贪心
___
#### 数组
___
#### 排序
---
### 1404_将二进制表示减到 1 的步骤数
___
#### 位运算
___
#### 字符串
___
#### 模拟
---
### 1405_最长快乐字符串
___
#### 贪心
___
#### 字符串
___
#### 堆（优先队列）
---
### 1406_石子游戏 III
___
#### 数组
___
#### 数学
___
#### 动态规划
___
#### 博弈
---
### 1407_排名靠前的旅行者
___
#### 数据库
---
### 1408_数组中的字符串匹配
___
#### 数组
___
#### 字符串
___
#### 字符串匹配
---
### 1409_查询带键的排列
___
#### 树状数组
___
#### 数组
___
#### 模拟
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 位运算 | 几何 | 动态规划 |
| 博弈 | 哈希表 | 堆（优先队列） |
| 字符串 | 字符串匹配 | 排序 |
| 数学 | 数据库 | 数组 |
| 树状数组 | 模拟 | 计数 |
| 贪心 |  |  |

# [1400. 构造 K 个回文字符串](https://leetcode.cn/problems/construct-k-palindrome-strings){#1400}

{{< tabs "1400" >}}

{{% tab "python" %}}
```python
class Solution:
    def canConstruct(self, s: str, k: int) -> bool:
        if len(s) < k:
            return False
        cnt = Counter(s)
        return sum(v & 1 for v in cnt.values()) <= k
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean canConstruct(String s, int k) {
        int n = s.length();
        if (n < k) {
            return false;
        }
        int[] cnt = new int[26];
        for (int i = 0; i < n; ++i) {
            ++cnt[s.charAt(i) - 'a'];
        }
        int x = 0;
        for (int v : cnt) {
            x += v & 1;
        }
        return x <= k;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.size() < k) {
            return false;
        }
        int cnt[26]{};
        for (char& c : s) {
            ++cnt[c - 'a'];
        }
        int x = 0;
        for (int v : cnt) {
            x += v & 1;
        }
        return x <= k;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func canConstruct(s string, k int) bool {
	if len(s) < k {
		return false
	}
	cnt := [26]int{}
	for _, c := range s {
		cnt[c-'a']++
	}
	x := 0
	for _, v := range cnt {
		x += v & 1
	}
	return x <= k
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function canConstruct(s: string, k: number): boolean {
    if (s.length < k) {
        return false;
    }
    const cnt: number[] = new Array(26).fill(0);
    for (const c of s) {
        ++cnt[c.charCodeAt(0) - 'a'.charCodeAt(0)];
    }
    let x = 0;
    for (const v of cnt) {
        x += v & 1;
    }
    return x <= k;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串 <code>s</code>&nbsp;和一个整数 <code>k</code>&nbsp;。请你用 <code>s</code>&nbsp;字符串中 <strong>所有字符</strong>&nbsp;构造 <code>k</code>&nbsp;个<strong>非空</strong> <span data-keyword="palindrome-string">回文串</span>&nbsp;。</p>

<p>如果你可以用&nbsp;<code>s</code>&nbsp;中所有字符构造&nbsp;<code>k</code>&nbsp;个回文字符串，那么请你返回 <strong>True</strong>&nbsp;，否则返回&nbsp;<strong>False</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "annabelle", k = 2
<strong>输出：</strong>true
<strong>解释：</strong>可以用 s 中所有字符构造 2 个回文字符串。
一些可行的构造方案包括："anna" + "elble"，"anbna" + "elle"，"anellena" + "b"
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "leetcode", k = 3
<strong>输出：</strong>false
<strong>解释：</strong>无法用 s 中所有字符构造 3 个回文串。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "true", k = 4
<strong>输出：</strong>true
<strong>解释：</strong>唯一可行的方案是让 s 中每个字符单独构成一个字符串。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code>&nbsp;中所有字符都是小写英文字母。</li>
	<li><code>1 &lt;= k &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数

我们先判断字符串 $s$ 的长度是否小于 $k$，如果是，那么一定无法构造出 $k$ 个回文串，可以直接返回 `false`。

否则，我们用一个哈希表或数组 $cnt$ 统计字符串 $s$ 中每个字符出现的次数。最后，我们只需要统计 $cnt$ 中奇数次数的字符个数 $x$，如果 $x$ 大于 $k$，那么一定无法构造出 $k$ 个回文串，返回 `false`；否则，返回 `true`。

时间复杂度 $O(n)$，空间复杂度 $O(C)$。其中 $n$ 是字符串 $s$ 的长度；而 $C$ 是字符集大小，这里 $C=26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def canConstruct(self, s: str, k: int) -> bool:
        if len(s) < k:
            return False
        cnt = Counter(s)
        return sum(v & 1 for v in cnt.values()) <= k
```

#### Java

```java
class Solution {
    public boolean canConstruct(String s, int k) {
        int n = s.length();
        if (n < k) {
            return false;
        }
        int[] cnt = new int[26];
        for (int i = 0; i < n; ++i) {
            ++cnt[s.charAt(i) - 'a'];
        }
        int x = 0;
        for (int v : cnt) {
            x += v & 1;
        }
        return x <= k;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.size() < k) {
            return false;
        }
        int cnt[26]{};
        for (char& c : s) {
            ++cnt[c - 'a'];
        }
        int x = 0;
        for (int v : cnt) {
            x += v & 1;
        }
        return x <= k;
    }
};
```

#### Go

```go
func canConstruct(s string, k int) bool {
	if len(s) < k {
		return false
	}
	cnt := [26]int{}
	for _, c := range s {
		cnt[c-'a']++
	}
	x := 0
	for _, v := range cnt {
		x += v & 1
	}
	return x <= k
}
```

#### TypeScript

```ts
function canConstruct(s: string, k: number): boolean {
    if (s.length < k) {
        return false;
    }
    const cnt: number[] = new Array(26).fill(0);
    for (const c of s) {
        ++cnt[c.charCodeAt(0) - 'a'.charCodeAt(0)];
    }
    let x = 0;
    for (const v of cnt) {
        x += v & 1;
    }
    return x <= k;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1401. 圆和矩形是否有重叠](https://leetcode.cn/problems/circle-and-rectangle-overlapping){#1401}

{{< tabs "1401" >}}

{{% tab "python" %}}
```python
class Solution:
    def checkOverlap(
        self,
        radius: int,
        xCenter: int,
        yCenter: int,
        x1: int,
        y1: int,
        x2: int,
        y2: int,
    ) -> bool:
        def f(i: int, j: int, k: int) -> int:
            if i <= k <= j:
                return 0
            return i - k if k < i else k - j

        a = f(x1, x2, xCenter)
        b = f(y1, y2, yCenter)
        return a * a + b * b <= radius * radius
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean checkOverlap(
        int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int a = f(x1, x2, xCenter);
        int b = f(y1, y2, yCenter);
        return a * a + b * b <= radius * radius;
    }

    private int f(int i, int j, int k) {
        if (i <= k && k <= j) {
            return 0;
        }
        return k < i ? i - k : k - j;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        auto f = [](int i, int j, int k) -> int {
            if (i <= k && k <= j) {
                return 0;
            }
            return k < i ? i - k : k - j;
        };
        int a = f(x1, x2, xCenter);
        int b = f(y1, y2, yCenter);
        return a * a + b * b <= radius * radius;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func checkOverlap(radius int, xCenter int, yCenter int, x1 int, y1 int, x2 int, y2 int) bool {
	f := func(i, j, k int) int {
		if i <= k && k <= j {
			return 0
		}
		if k < i {
			return i - k
		}
		return k - j
	}
	a := f(x1, x2, xCenter)
	b := f(y1, y2, yCenter)
	return a*a+b*b <= radius*radius
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function checkOverlap(
    radius: number,
    xCenter: number,
    yCenter: number,
    x1: number,
    y1: number,
    x2: number,
    y2: number,
): boolean {
    const f = (i: number, j: number, k: number) => {
        if (i <= k && k <= j) {
            return 0;
        }
        return k < i ? i - k : k - j;
    };
    const a = f(x1, x2, xCenter);
    const b = f(y1, y2, yCenter);
    return a * a + b * b <= radius * radius;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个以 <code>(radius, xCenter, yCenter)</code> 表示的圆和一个与坐标轴平行的矩形 <code>(x1, y1, x2, y2)</code> ，其中 <code>(x1, y1)</code> 是矩形左下角的坐标，而 <code>(x2, y2)</code> 是右上角的坐标。</p>

<p>如果圆和矩形有重叠的部分，请你返回 <code>true</code> ，否则返回 <code>false</code>&nbsp;。</p>

<p>换句话说，请你检测是否 <strong>存在</strong> 点 <code>(x<sub>i</sub>, y<sub>i</sub>)</code> ，它既在圆上也在矩形上（两者都包括点落在边界上的情况）。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1 ：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1400-1499/1401.Circle%20and%20Rectangle%20Overlapping/images/sample_4_1728.png" style="width: 258px; height: 167px;" />
<pre>
<strong>输入：</strong>radius = 1, xCenter = 0, yCenter = 0, x1 = 1, y1 = -1, x2 = 3, y2 = 1
<strong>输出：</strong>true
<strong>解释：</strong>圆和矩形存在公共点 (1,0) 。
</pre>

<p><strong class="example">示例 2 ：</strong></p>

<pre>
<strong>输入：</strong>radius = 1, xCenter = 1, yCenter = 1, x1 = 1, y1 = -3, x2 = 2, y2 = -1
<strong>输出：</strong>false
</pre>

<p><strong class="example">示例 3 ：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1400-1499/1401.Circle%20and%20Rectangle%20Overlapping/images/sample_2_1728.png" style="width: 150px; height: 135px;" />
<pre>
<strong>输入：</strong>radius = 1, xCenter = 0, yCenter = 0, x1 = -1, y1 = 0, x2 = 0, y2 = 1
<strong>输出：</strong>true
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= radius &lt;= 2000</code></li>
	<li><code>-10<sup>4</sup> &lt;= xCenter, yCenter &lt;= 10<sup>4</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= x1 &lt; x2 &lt;= 10<sup>4</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= y1 &lt; y2 &lt;= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数学

对于一个点 $(x, y)$，它到圆心 $(xCenter, yCenter)$ 的最短距离为 $\sqrt{(x - xCenter)^2 + (y - yCenter)^2}$，如果这个距离小于等于半径 $radius$，那么这个点就在圆内（包括边界）。

而对于矩形内（包括边界）的点，它们的横坐标 $x$ 满足 $x_1 \leq x \leq x_2$，纵坐标 $y$ 满足 $y_1 \leq y \leq y_2$。要判断圆和矩形是否有重叠的部分，相当于在矩形内找到一个点 $(x, y)$，使得 $a = |x - xCenter|$ 和 $b = |y - yCenter|$ 都取到最小值，此时若 $a^2 + b^2 \leq radius^2$，则说明圆和矩形有重叠的部分。

因此，问题转化为求 $x \in [x_1, x_2]$ 时 $a = |x - xCenter|$ 的最小值，以及 $y \in [y_1, y_2]$ 时 $b = |y - yCenter|$ 的最小值。

对于 $x \in [x_1, x_2]$：

-   如果 $x_1 \leq xCenter \leq x_2$，那么 $|x - xCenter|$ 的最小值为 $0$；
-   如果 $xCenter \lt x_1$，那么 $|x - xCenter|$ 的最小值为 $x_1 - xCenter$；
-   如果 $xCenter \gt x_2$，那么 $|x - xCenter|$ 的最小值为 $xCenter - x_2$。

同理，我们可以求出 $y \in [y_1, y_2]$ 时 $|y - yCenter|$ 的最小值。以上我们可以统一用函数 $f(i, j, k)$ 来处理。

即 $a = f(x_1, x_2, xCenter)$, $b = f(y_1, y_2, yCenter)$，如果 $a^2 + b^2 \leq radius^2$，则说明圆和矩形有重叠的部分。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def checkOverlap(
        self,
        radius: int,
        xCenter: int,
        yCenter: int,
        x1: int,
        y1: int,
        x2: int,
        y2: int,
    ) -> bool:
        def f(i: int, j: int, k: int) -> int:
            if i <= k <= j:
                return 0
            return i - k if k < i else k - j

        a = f(x1, x2, xCenter)
        b = f(y1, y2, yCenter)
        return a * a + b * b <= radius * radius
```

#### Java

```java
class Solution {
    public boolean checkOverlap(
        int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int a = f(x1, x2, xCenter);
        int b = f(y1, y2, yCenter);
        return a * a + b * b <= radius * radius;
    }

    private int f(int i, int j, int k) {
        if (i <= k && k <= j) {
            return 0;
        }
        return k < i ? i - k : k - j;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        auto f = [](int i, int j, int k) -> int {
            if (i <= k && k <= j) {
                return 0;
            }
            return k < i ? i - k : k - j;
        };
        int a = f(x1, x2, xCenter);
        int b = f(y1, y2, yCenter);
        return a * a + b * b <= radius * radius;
    }
};
```

#### Go

```go
func checkOverlap(radius int, xCenter int, yCenter int, x1 int, y1 int, x2 int, y2 int) bool {
	f := func(i, j, k int) int {
		if i <= k && k <= j {
			return 0
		}
		if k < i {
			return i - k
		}
		return k - j
	}
	a := f(x1, x2, xCenter)
	b := f(y1, y2, yCenter)
	return a*a+b*b <= radius*radius
}
```

#### TypeScript

```ts
function checkOverlap(
    radius: number,
    xCenter: number,
    yCenter: number,
    x1: number,
    y1: number,
    x2: number,
    y2: number,
): boolean {
    const f = (i: number, j: number, k: number) => {
        if (i <= k && k <= j) {
            return 0;
        }
        return k < i ? i - k : k - j;
    };
    const a = f(x1, x2, xCenter);
    const b = f(y1, y2, yCenter);
    return a * a + b * b <= radius * radius;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1402. 做菜顺序](https://leetcode.cn/problems/reducing-dishes){#1402}

{{< tabs "1402" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxSatisfaction(self, satisfaction: List[int]) -> int:
        satisfaction.sort(reverse=True)
        ans = s = 0
        for x in satisfaction:
            s += x
            if s <= 0:
                break
            ans += s
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxSatisfaction(int[] satisfaction) {
        Arrays.sort(satisfaction);
        int ans = 0, s = 0;
        for (int i = satisfaction.length - 1; i >= 0; --i) {
            s += satisfaction[i];
            if (s <= 0) {
                break;
            }
            ans += s;
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
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(rbegin(satisfaction), rend(satisfaction));
        int ans = 0, s = 0;
        for (int x : satisfaction) {
            s += x;
            if (s <= 0) {
                break;
            }
            ans += s;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxSatisfaction(satisfaction []int) (ans int) {
	sort.Slice(satisfaction, func(i, j int) bool { return satisfaction[i] > satisfaction[j] })
	s := 0
	for _, x := range satisfaction {
		s += x
		if s <= 0 {
			break
		}
		ans += s
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxSatisfaction(satisfaction: number[]): number {
    satisfaction.sort((a, b) => b - a);
    let [ans, s] = [0, 0];
    for (const x of satisfaction) {
        s += x;
        if (s <= 0) {
            break;
        }
        ans += s;
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

<p>一个厨师收集了他&nbsp;<code>n</code>&nbsp;道菜的满意程度&nbsp;<code>satisfaction</code>&nbsp;，这个厨师做出每道菜的时间都是 1 单位时间。</p>

<p>一道菜的 「&nbsp;<strong>like-time 系数&nbsp;</strong>」定义为烹饪这道菜结束的时间（包含之前每道菜所花费的时间）乘以这道菜的满意程度，也就是&nbsp;<code>time[i]</code>*<code>satisfaction[i]</code>&nbsp;。</p>

<p>返回厨师在准备了一定数量的菜肴后可以获得的最大 <strong>like-time 系数</strong> 总和。</p>

<p>你可以按&nbsp;<strong>任意</strong>&nbsp;顺序安排做菜的顺序，你也可以选择放弃做某些菜来获得更大的总和。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>satisfaction = [-1,-8,0,5,-9]
<strong>输出：</strong>14
<strong>解释：</strong>去掉第二道和最后一道菜，最大的 like-time 系数和为 (-1*1 + 0*2 + 5*3 = 14) 。每道菜都需要花费 1 单位时间完成。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>satisfaction = [4,3,2]
<strong>输出：</strong>20
<strong>解释：可以</strong>按照任意顺序做菜 (2*1 + 3*2 + 4*3 = 20)
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>satisfaction = [-1,-4,-5]
<strong>输出：</strong>0
<strong>解释：</strong>大家都不喜欢这些菜，所以不做任何菜就可以获得最大的 like-time 系数。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == satisfaction.length</code></li>
	<li><code>1 &lt;= n &lt;= 500</code></li>
	<li><code>-1000 &lt;= satisfaction[i] &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 排序

假如我们只选择一道菜，那么我们应该选择满意度最大的那道菜 $s_0$，并且判断 $s_0$ 是否大于 0，如果 $s_0 \leq 0$，那么我们就不做菜了，否则我们做这道菜，得到的总满意度为 $s_0$。

假如我们选择两道菜，那么我们应该选择满足度最大的两道菜 $s_0$ 和 $s_1$，满意度为 $s_1 + 2 \times s_0$，此时要保证选择之后的满意度大于选择之前的满意度，即 $s_1 + 2 \times s_0 > s_0$，即 只要满足 $s_1 + s_0 > 0$，我们就可以选择这两道菜。

依此类推，我们可以得到一个规律，即我们应该选择满意度最大的 $k$ 道菜，并且保证前 $k$ 道菜的满意度之和大于 $0$。

在实现上，我们可以先对所有菜的满意度进行排序，然后从满意度最大的菜开始选择，每次累加当前这道菜的满意度，如果累加的结果小于等于 $0$，那么我们就不再选择后面的菜了，否则我们就选择这道菜。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 是数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxSatisfaction(self, satisfaction: List[int]) -> int:
        satisfaction.sort(reverse=True)
        ans = s = 0
        for x in satisfaction:
            s += x
            if s <= 0:
                break
            ans += s
        return ans
```

#### Java

```java
class Solution {
    public int maxSatisfaction(int[] satisfaction) {
        Arrays.sort(satisfaction);
        int ans = 0, s = 0;
        for (int i = satisfaction.length - 1; i >= 0; --i) {
            s += satisfaction[i];
            if (s <= 0) {
                break;
            }
            ans += s;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(rbegin(satisfaction), rend(satisfaction));
        int ans = 0, s = 0;
        for (int x : satisfaction) {
            s += x;
            if (s <= 0) {
                break;
            }
            ans += s;
        }
        return ans;
    }
};
```

#### Go

```go
func maxSatisfaction(satisfaction []int) (ans int) {
	sort.Slice(satisfaction, func(i, j int) bool { return satisfaction[i] > satisfaction[j] })
	s := 0
	for _, x := range satisfaction {
		s += x
		if s <= 0 {
			break
		}
		ans += s
	}
	return
}
```

#### TypeScript

```ts
function maxSatisfaction(satisfaction: number[]): number {
    satisfaction.sort((a, b) => b - a);
    let [ans, s] = [0, 0];
    for (const x of satisfaction) {
        s += x;
        if (s <= 0) {
            break;
        }
        ans += s;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1403. 非递增顺序的最小子序列](https://leetcode.cn/problems/minimum-subsequence-in-non-increasing-order){#1403}

{{< tabs "1403" >}}

{{% tab "python" %}}
```python
class Solution:
    def minSubsequence(self, nums: List[int]) -> List[int]:
        ans = []
        s, t = sum(nums), 0
        for x in sorted(nums, reverse=True):
            t += x
            ans.append(x)
            if t > s - t:
                break
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<Integer> minSubsequence(int[] nums) {
        Arrays.sort(nums);
        List<Integer> ans = new ArrayList<>();
        int s = Arrays.stream(nums).sum();
        int t = 0;
        for (int i = nums.length - 1; i >= 0; i--) {
            t += nums[i];
            ans.add(nums[i]);
            if (t > s - t) {
                break;
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
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        int s = accumulate(nums.begin(), nums.end(), 0);
        int t = 0;
        vector<int> ans;
        for (int x : nums) {
            t += x;
            ans.push_back(x);
            if (t > s - t) {
                break;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minSubsequence(nums []int) (ans []int) {
	sort.Ints(nums)
	s, t := 0, 0
	for _, x := range nums {
		s += x
	}
	for i := len(nums) - 1; ; i-- {
		t += nums[i]
		ans = append(ans, nums[i])
		if t > s-t {
			return
		}
	}
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minSubsequence(nums: number[]): number[] {
    nums.sort((a, b) => b - a);
    const s = nums.reduce((r, c) => r + c);
    let t = 0;
    for (let i = 0; ; ++i) {
        t += nums[i];
        if (t > s - t) {
            return nums.slice(0, i + 1);
        }
    }
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn min_subsequence(mut nums: Vec<i32>) -> Vec<i32> {
        nums.sort_by(|a, b| b.cmp(a));
        let sum = nums.iter().sum::<i32>();
        let mut res = vec![];
        let mut t = 0;
        for num in nums.into_iter() {
            t += num;
            res.push(num);
            if t > sum - t {
                break;
            }
        }
        res
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个数组 <code>nums</code>，请你从中抽取一个子序列，满足该子序列的元素之和 <strong>严格</strong> 大于未包含在该子序列中的各元素之和。</p>

<p>如果存在多个解决方案，只需返回 <strong>长度最小</strong> 的子序列。如果仍然有多个解决方案，则返回 <strong>元素之和最大</strong> 的子序列。</p>

<p>与子数组不同的地方在于，「数组的子序列」不强调元素在原数组中的连续性，也就是说，它可以通过从数组中分离一些（也可能不分离）元素得到。</p>

<p><strong>注意</strong>，题目数据保证满足所有约束条件的解决方案是 <strong>唯一</strong> 的。同时，返回的答案应当按 <strong>非递增顺序</strong> 排列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [4,3,10,9,8]
<strong>输出：</strong>[10,9] 
<strong>解释：</strong>子序列 [10,9] 和 [10,8] 是最小的、满足元素之和大于其他各元素之和的子序列。但是 [10,9] 的元素之和最大。&nbsp;
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [4,4,7,6,7]
<strong>输出：</strong>[7,7,6] 
<strong>解释：</strong>子序列 [7,7] 的和为 14 ，不严格大于剩下的其他元素之和（14 = 4 + 4 + 6）。因此，[7,6,7] 是满足题意的最小子序列。注意，元素按非递增顺序返回。  
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 500</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序

我们可以先对数组 $nums$ 按照从大到小的顺序排序，然后依次从大到小加入数组中的元素，每次加入后判断当前元素之和是否大于剩余元素之和，如果大于则返回当前数组。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 是数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minSubsequence(self, nums: List[int]) -> List[int]:
        ans = []
        s, t = sum(nums), 0
        for x in sorted(nums, reverse=True):
            t += x
            ans.append(x)
            if t > s - t:
                break
        return ans
```

#### Java

```java
class Solution {
    public List<Integer> minSubsequence(int[] nums) {
        Arrays.sort(nums);
        List<Integer> ans = new ArrayList<>();
        int s = Arrays.stream(nums).sum();
        int t = 0;
        for (int i = nums.length - 1; i >= 0; i--) {
            t += nums[i];
            ans.add(nums[i]);
            if (t > s - t) {
                break;
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
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        int s = accumulate(nums.begin(), nums.end(), 0);
        int t = 0;
        vector<int> ans;
        for (int x : nums) {
            t += x;
            ans.push_back(x);
            if (t > s - t) {
                break;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func minSubsequence(nums []int) (ans []int) {
	sort.Ints(nums)
	s, t := 0, 0
	for _, x := range nums {
		s += x
	}
	for i := len(nums) - 1; ; i-- {
		t += nums[i]
		ans = append(ans, nums[i])
		if t > s-t {
			return
		}
	}
}
```

#### TypeScript

```ts
function minSubsequence(nums: number[]): number[] {
    nums.sort((a, b) => b - a);
    const s = nums.reduce((r, c) => r + c);
    let t = 0;
    for (let i = 0; ; ++i) {
        t += nums[i];
        if (t > s - t) {
            return nums.slice(0, i + 1);
        }
    }
}
```

#### Rust

```rust
impl Solution {
    pub fn min_subsequence(mut nums: Vec<i32>) -> Vec<i32> {
        nums.sort_by(|a, b| b.cmp(a));
        let sum = nums.iter().sum::<i32>();
        let mut res = vec![];
        let mut t = 0;
        for num in nums.into_iter() {
            t += num;
            res.push(num);
            if t > sum - t {
                break;
            }
        }
        res
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1404. 将二进制表示减到 1 的步骤数](https://leetcode.cn/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one){#1404}

{{< tabs "1404" >}}

{{% tab "python" %}}
```python
class Solution:
    def numSteps(self, s: str) -> int:
        carry = False
        ans = 0
        for c in s[:0:-1]:
            if carry:
                if c == '0':
                    c = '1'
                    carry = False
                else:
                    c = '0'
            if c == '1':
                ans += 1
                carry = True
            ans += 1
        if carry:
            ans += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numSteps(String s) {
        boolean carry = false;
        int ans = 0;
        for (int i = s.length() - 1; i > 0; --i) {
            char c = s.charAt(i);
            if (carry) {
                if (c == '0') {
                    c = '1';
                    carry = false;
                } else {
                    c = '0';
                }
            }
            if (c == '1') {
                ++ans;
                carry = true;
            }
            ++ans;
        }
        if (carry) {
            ++ans;
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
    int numSteps(string s) {
        int ans = 0;
        bool carry = false;
        for (int i = s.size() - 1; i; --i) {
            char c = s[i];
            if (carry) {
                if (c == '0') {
                    c = '1';
                    carry = false;
                } else
                    c = '0';
            }
            if (c == '1') {
                ++ans;
                carry = true;
            }
            ++ans;
        }
        if (carry) ++ans;
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numSteps(s string) int {
	ans := 0
	carry := false
	for i := len(s) - 1; i > 0; i-- {
		c := s[i]
		if carry {
			if c == '0' {
				c = '1'
				carry = false
			} else {
				c = '0'
			}
		}
		if c == '1' {
			ans++
			carry = true
		}
		ans++
	}
	if carry {
		ans++
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

<p>给你一个以二进制形式表示的数字 <code>s</code> 。请你返回按下述规则将其减少到 1 所需要的步骤数：</p>

<ul>
	<li>
	<p>如果当前数字为偶数，则将其除以 <code>2</code> 。</p>
	</li>
	<li>
	<p>如果当前数字为奇数，则将其加上 <code>1</code> 。</p>
	</li>
</ul>

<p>题目保证你总是可以按上述规则将测试用例变为 1 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "1101"
<strong>输出：</strong>6
<strong>解释：</strong>"1101" 表示十进制数 13 。
Step 1) 13 是奇数，加 1 得到 14&nbsp;
Step 2) 14 是偶数，除 2 得到 7
Step 3) 7  是奇数，加 1 得到 8
Step 4) 8  是偶数，除 2 得到 4&nbsp; 
Step 5) 4  是偶数，除 2 得到 2&nbsp;
Step 6) 2  是偶数，除 2 得到 1&nbsp; 
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "10"
<strong>输出：</strong>1
<strong>解释：</strong>"10" 表示十进制数 2 。
Step 1) 2 是偶数，除 2 得到 1 
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "1"
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length&nbsp;&lt;= 500</code></li>
	<li><code>s</code> 由字符 <code>'0'</code> 或 <code>'1'</code> 组成。</li>
	<li><code>s[0] == '1'</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟操作

我们模拟操作 $1$ 和 $2$，同时用 carry 记录进位。

时间复杂度 $O(n)$，其中 $n$ 是字符串 $s$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numSteps(self, s: str) -> int:
        carry = False
        ans = 0
        for c in s[:0:-1]:
            if carry:
                if c == '0':
                    c = '1'
                    carry = False
                else:
                    c = '0'
            if c == '1':
                ans += 1
                carry = True
            ans += 1
        if carry:
            ans += 1
        return ans
```

#### Java

```java
class Solution {
    public int numSteps(String s) {
        boolean carry = false;
        int ans = 0;
        for (int i = s.length() - 1; i > 0; --i) {
            char c = s.charAt(i);
            if (carry) {
                if (c == '0') {
                    c = '1';
                    carry = false;
                } else {
                    c = '0';
                }
            }
            if (c == '1') {
                ++ans;
                carry = true;
            }
            ++ans;
        }
        if (carry) {
            ++ans;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numSteps(string s) {
        int ans = 0;
        bool carry = false;
        for (int i = s.size() - 1; i; --i) {
            char c = s[i];
            if (carry) {
                if (c == '0') {
                    c = '1';
                    carry = false;
                } else
                    c = '0';
            }
            if (c == '1') {
                ++ans;
                carry = true;
            }
            ++ans;
        }
        if (carry) ++ans;
        return ans;
    }
};
```

#### Go

```go
func numSteps(s string) int {
	ans := 0
	carry := false
	for i := len(s) - 1; i > 0; i-- {
		c := s[i]
		if carry {
			if c == '0' {
				c = '1'
				carry = false
			} else {
				c = '0'
			}
		}
		if c == '1' {
			ans++
			carry = true
		}
		ans++
	}
	if carry {
		ans++
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1405. 最长快乐字符串](https://leetcode.cn/problems/longest-happy-string){#1405}

{{< tabs "1405" >}}

{{% tab "python" %}}
```python
class Solution:
    def longestDiverseString(self, a: int, b: int, c: int) -> str:
        h = []
        if a > 0:
            heappush(h, [-a, 'a'])
        if b > 0:
            heappush(h, [-b, 'b'])
        if c > 0:
            heappush(h, [-c, 'c'])

        ans = []
        while len(h) > 0:
            cur = heappop(h)
            if len(ans) >= 2 and ans[-1] == cur[1] and ans[-2] == cur[1]:
                if len(h) == 0:
                    break
                nxt = heappop(h)
                ans.append(nxt[1])
                if -nxt[0] > 1:
                    nxt[0] += 1
                    heappush(h, nxt)
                heappush(h, cur)
            else:
                ans.append(cur[1])
                if -cur[0] > 1:
                    cur[0] += 1
                    heappush(h, cur)

        return ''.join(ans)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String longestDiverseString(int a, int b, int c) {
        Queue<int[]> pq = new PriorityQueue<>((x, y) -> y[1] - x[1]);
        if (a > 0) {
            pq.offer(new int[] {'a', a});
        }
        if (b > 0) {
            pq.offer(new int[] {'b', b});
        }
        if (c > 0) {
            pq.offer(new int[] {'c', c});
        }

        StringBuilder sb = new StringBuilder();
        while (pq.size() > 0) {
            int[] cur = pq.poll();
            int n = sb.length();
            if (n >= 2 && sb.codePointAt(n - 1) == cur[0] && sb.codePointAt(n - 2) == cur[0]) {
                if (pq.size() == 0) {
                    break;
                }
                int[] next = pq.poll();
                sb.append((char) next[0]);
                if (next[1] > 1) {
                    next[1]--;
                    pq.offer(next);
                }
                pq.offer(cur);
            } else {
                sb.append((char) cur[0]);
                if (cur[1] > 1) {
                    cur[1]--;
                    pq.offer(cur);
                }
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
    string longestDiverseString(int a, int b, int c) {
        using pci = pair<char, int>;
        auto cmp = [](pci x, pci y) { return x.second < y.second; };
        priority_queue<pci, vector<pci>, decltype(cmp)> pq(cmp);

        if (a > 0) pq.push({'a', a});
        if (b > 0) pq.push({'b', b});
        if (c > 0) pq.push({'c', c});

        string ans;
        while (!pq.empty()) {
            pci cur = pq.top();
            pq.pop();
            int n = ans.size();
            if (n >= 2 && ans[n - 1] == cur.first && ans[n - 2] == cur.first) {
                if (pq.empty()) break;
                pci nxt = pq.top();
                pq.pop();
                ans.push_back(nxt.first);
                if (--nxt.second > 0) {
                    pq.push(nxt);
                }
                pq.push(cur);
            } else {
                ans.push_back(cur.first);
                if (--cur.second > 0) {
                    pq.push(cur);
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
type pair struct {
	c   byte
	num int
}

type hp []pair

func (a hp) Len() int           { return len(a) }
func (a hp) Swap(i, j int)      { a[i], a[j] = a[j], a[i] }
func (a hp) Less(i, j int) bool { return a[i].num > a[j].num }
func (a *hp) Push(x any)        { *a = append(*a, x.(pair)) }
func (a *hp) Pop() any          { l := len(*a); t := (*a)[l-1]; *a = (*a)[:l-1]; return t }

func longestDiverseString(a int, b int, c int) string {
	var h hp
	if a > 0 {
		heap.Push(&h, pair{'a', a})
	}
	if b > 0 {
		heap.Push(&h, pair{'b', b})
	}
	if c > 0 {
		heap.Push(&h, pair{'c', c})
	}

	var ans []byte
	for len(h) > 0 {
		cur := heap.Pop(&h).(pair)
		if len(ans) >= 2 && ans[len(ans)-1] == cur.c && ans[len(ans)-2] == cur.c {
			if len(h) == 0 {
				break
			}
			next := heap.Pop(&h).(pair)
			ans = append(ans, next.c)
			if next.num > 1 {
				next.num--
				heap.Push(&h, next)
			}
			heap.Push(&h, cur)
		} else {
			ans = append(ans, cur.c)
			if cur.num > 1 {
				cur.num--
				heap.Push(&h, cur)
			}
		}
	}

	return string(ans)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function longestDiverseString(a: number, b: number, c: number): string {
    let res = '';
    let prev = { ch: '', c: 0 };
    let last = { ch: '', c: 0 };
    const pq = new MaxPriorityQueue({ priority: ({ c }) => c });

    pq.enqueue({ ch: 'a', c: a });
    pq.enqueue({ ch: 'b', c: b });
    pq.enqueue({ ch: 'c', c });

    while (pq.size()) {
        const item = pq.dequeue().element;
        let c = item.c < prev.c ? 1 : 2;

        if (prev.c) pq.enqueue(prev);
        if (last.ch !== item.ch && item.c) last = { ...item, c: 0 };

        while (c-- && item.c && last.c++ < 2) {
            item.c--;
            res += item.ch;
        }
        prev = item;
    }

    return res;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
function longestDiverseString(a, b, c) {
    let res = '';
    let prev = { ch: '', c: 0 };
    let last = { ch: '', c: 0 };
    const pq = new MaxPriorityQueue({ priority: ({ c }) => c });

    pq.enqueue({ ch: 'a', c: a });
    pq.enqueue({ ch: 'b', c: b });
    pq.enqueue({ ch: 'c', c });

    while (pq.size()) {
        const item = pq.dequeue().element;
        let c = item.c < prev.c ? 1 : 2;

        if (prev.c) pq.enqueue(prev);
        if (last.ch !== item.ch && item.c) last = { ...item, c: 0 };

        while (c-- && item.c && last.c++ < 2) {
            item.c--;
            res += item.ch;
        }
        prev = item;
    }

    return res;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>如果字符串中不含有任何 <code>&#39;aaa&#39;</code>，<code>&#39;bbb&#39;</code> 或 <code>&#39;ccc&#39;</code> 这样的字符串作为子串，那么该字符串就是一个「快乐字符串」。</p>

<p>给你三个整数 <code>a</code>，<code>b</code> ，<code>c</code>，请你返回 <strong>任意一个</strong> 满足下列全部条件的字符串 <code>s</code>：</p>

<ul>
	<li><code>s</code> 是一个尽可能长的快乐字符串。</li>
	<li><code>s</code> 中 <strong>最多</strong> 有<code>a</code> 个字母 <code>&#39;a&#39;</code>、<code>b</code>&nbsp;个字母 <code>&#39;b&#39;</code>、<code>c</code> 个字母 <code>&#39;c&#39;</code> 。</li>
	<li><code>s </code>中只含有 <code>&#39;a&#39;</code>、<code>&#39;b&#39;</code> 、<code>&#39;c&#39;</code> 三种字母。</li>
</ul>

<p>如果不存在这样的字符串 <code>s</code> ，请返回一个空字符串 <code>&quot;&quot;</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>a = 1, b = 1, c = 7
<strong>输出：</strong>&quot;ccaccbcc&quot;
<strong>解释：</strong>&quot;ccbccacc&quot; 也是一种正确答案。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>a = 2, b = 2, c = 1
<strong>输出：</strong>&quot;aabbc&quot;
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>a = 7, b = 1, c = 0
<strong>输出：</strong>&quot;aabaa&quot;
<strong>解释：</strong>这是该测试用例的唯一正确答案。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= a, b, c &lt;= 100</code></li>
	<li><code>a + b + c &gt; 0</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 优先队列

贪心，优先选择剩余最多的字符，通过优先队列或排序，确保每次选到的字符都是剩余最多的（为了避免出现连续 3 个一样的字符，一些情况需要选择剩余第二多的字符）。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def longestDiverseString(self, a: int, b: int, c: int) -> str:
        h = []
        if a > 0:
            heappush(h, [-a, 'a'])
        if b > 0:
            heappush(h, [-b, 'b'])
        if c > 0:
            heappush(h, [-c, 'c'])

        ans = []
        while len(h) > 0:
            cur = heappop(h)
            if len(ans) >= 2 and ans[-1] == cur[1] and ans[-2] == cur[1]:
                if len(h) == 0:
                    break
                nxt = heappop(h)
                ans.append(nxt[1])
                if -nxt[0] > 1:
                    nxt[0] += 1
                    heappush(h, nxt)
                heappush(h, cur)
            else:
                ans.append(cur[1])
                if -cur[0] > 1:
                    cur[0] += 1
                    heappush(h, cur)

        return ''.join(ans)
```

#### Java

```java
class Solution {
    public String longestDiverseString(int a, int b, int c) {
        Queue<int[]> pq = new PriorityQueue<>((x, y) -> y[1] - x[1]);
        if (a > 0) {
            pq.offer(new int[] {'a', a});
        }
        if (b > 0) {
            pq.offer(new int[] {'b', b});
        }
        if (c > 0) {
            pq.offer(new int[] {'c', c});
        }

        StringBuilder sb = new StringBuilder();
        while (pq.size() > 0) {
            int[] cur = pq.poll();
            int n = sb.length();
            if (n >= 2 && sb.codePointAt(n - 1) == cur[0] && sb.codePointAt(n - 2) == cur[0]) {
                if (pq.size() == 0) {
                    break;
                }
                int[] next = pq.poll();
                sb.append((char) next[0]);
                if (next[1] > 1) {
                    next[1]--;
                    pq.offer(next);
                }
                pq.offer(cur);
            } else {
                sb.append((char) cur[0]);
                if (cur[1] > 1) {
                    cur[1]--;
                    pq.offer(cur);
                }
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
    string longestDiverseString(int a, int b, int c) {
        using pci = pair<char, int>;
        auto cmp = [](pci x, pci y) { return x.second < y.second; };
        priority_queue<pci, vector<pci>, decltype(cmp)> pq(cmp);

        if (a > 0) pq.push({'a', a});
        if (b > 0) pq.push({'b', b});
        if (c > 0) pq.push({'c', c});

        string ans;
        while (!pq.empty()) {
            pci cur = pq.top();
            pq.pop();
            int n = ans.size();
            if (n >= 2 && ans[n - 1] == cur.first && ans[n - 2] == cur.first) {
                if (pq.empty()) break;
                pci nxt = pq.top();
                pq.pop();
                ans.push_back(nxt.first);
                if (--nxt.second > 0) {
                    pq.push(nxt);
                }
                pq.push(cur);
            } else {
                ans.push_back(cur.first);
                if (--cur.second > 0) {
                    pq.push(cur);
                }
            }
        }

        return ans;
    }
};
```

#### Go

```go
type pair struct {
	c   byte
	num int
}

type hp []pair

func (a hp) Len() int           { return len(a) }
func (a hp) Swap(i, j int)      { a[i], a[j] = a[j], a[i] }
func (a hp) Less(i, j int) bool { return a[i].num > a[j].num }
func (a *hp) Push(x any)        { *a = append(*a, x.(pair)) }
func (a *hp) Pop() any          { l := len(*a); t := (*a)[l-1]; *a = (*a)[:l-1]; return t }

func longestDiverseString(a int, b int, c int) string {
	var h hp
	if a > 0 {
		heap.Push(&h, pair{'a', a})
	}
	if b > 0 {
		heap.Push(&h, pair{'b', b})
	}
	if c > 0 {
		heap.Push(&h, pair{'c', c})
	}

	var ans []byte
	for len(h) > 0 {
		cur := heap.Pop(&h).(pair)
		if len(ans) >= 2 && ans[len(ans)-1] == cur.c && ans[len(ans)-2] == cur.c {
			if len(h) == 0 {
				break
			}
			next := heap.Pop(&h).(pair)
			ans = append(ans, next.c)
			if next.num > 1 {
				next.num--
				heap.Push(&h, next)
			}
			heap.Push(&h, cur)
		} else {
			ans = append(ans, cur.c)
			if cur.num > 1 {
				cur.num--
				heap.Push(&h, cur)
			}
		}
	}

	return string(ans)
}
```

#### TypeScript

```ts
function longestDiverseString(a: number, b: number, c: number): string {
    let ans = [];
    let store: Array<[string, number]> = [
        ['a', a],
        ['b', b],
        ['c', c],
    ];
    while (true) {
        store.sort((a, b) => b[1] - a[1]);
        let hasNext = false;
        for (let [i, [ch, ctn]] of store.entries()) {
            if (ctn < 1) {
                break;
            }
            const n = ans.length;
            if (n >= 2 && ans[n - 1] == ch && ans[n - 2] == ch) {
                continue;
            }
            hasNext = true;
            ans.push(ch);
            store[i][1] -= 1;
            break;
        }
        if (!hasNext) {
            break;
        }
    }
    return ans.join('');
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：贪心 + 优先队列（另一种写法）

<!-- tabs:start -->

#### TypeScript

```ts
function longestDiverseString(a: number, b: number, c: number): string {
    let res = '';
    let prev = { ch: '', c: 0 };
    let last = { ch: '', c: 0 };
    const pq = new MaxPriorityQueue({ priority: ({ c }) => c });

    pq.enqueue({ ch: 'a', c: a });
    pq.enqueue({ ch: 'b', c: b });
    pq.enqueue({ ch: 'c', c });

    while (pq.size()) {
        const item = pq.dequeue().element;
        let c = item.c < prev.c ? 1 : 2;

        if (prev.c) pq.enqueue(prev);
        if (last.ch !== item.ch && item.c) last = { ...item, c: 0 };

        while (c-- && item.c && last.c++ < 2) {
            item.c--;
            res += item.ch;
        }
        prev = item;
    }

    return res;
}
```

#### JavaScript

```js
function longestDiverseString(a, b, c) {
    let res = '';
    let prev = { ch: '', c: 0 };
    let last = { ch: '', c: 0 };
    const pq = new MaxPriorityQueue({ priority: ({ c }) => c });

    pq.enqueue({ ch: 'a', c: a });
    pq.enqueue({ ch: 'b', c: b });
    pq.enqueue({ ch: 'c', c });

    while (pq.size()) {
        const item = pq.dequeue().element;
        let c = item.c < prev.c ? 1 : 2;

        if (prev.c) pq.enqueue(prev);
        if (last.ch !== item.ch && item.c) last = { ...item, c: 0 };

        while (c-- && item.c && last.c++ < 2) {
            item.c--;
            res += item.ch;
        }
        prev = item;
    }

    return res;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1406. 石子游戏 III](https://leetcode.cn/problems/stone-game-iii){#1406}

{{< tabs "1406" >}}

{{% tab "python" %}}
```python
class Solution:
    def stoneGameIII(self, stoneValue: List[int]) -> str:
        @cache
        def dfs(i: int) -> int:
            if i >= n:
                return 0
            ans, s = -inf, 0
            for j in range(3):
                if i + j >= n:
                    break
                s += stoneValue[i + j]
                ans = max(ans, s - dfs(i + j + 1))
            return ans

        n = len(stoneValue)
        ans = dfs(0)
        if ans == 0:
            return 'Tie'
        return 'Alice' if ans > 0 else 'Bob'
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[] stoneValue;
    private Integer[] f;
    private int n;

    public String stoneGameIII(int[] stoneValue) {
        n = stoneValue.length;
        f = new Integer[n];
        this.stoneValue = stoneValue;
        int ans = dfs(0);
        if (ans == 0) {
            return "Tie";
        }
        return ans > 0 ? "Alice" : "Bob";
    }

    private int dfs(int i) {
        if (i >= n) {
            return 0;
        }
        if (f[i] != null) {
            return f[i];
        }
        int ans = -(1 << 30);
        int s = 0;
        for (int j = 0; j < 3 && i + j < n; ++j) {
            s += stoneValue[i + j];
            ans = Math.max(ans, s - dfs(i + j + 1));
        }
        return f[i] = ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        int f[n];
        memset(f, 0x3f, sizeof(f));
        function<int(int)> dfs = [&](int i) -> int {
            if (i >= n) {
                return 0;
            }
            if (f[i] != 0x3f3f3f3f) {
                return f[i];
            }
            int ans = -(1 << 30), s = 0;
            for (int j = 0; j < 3 && i + j < n; ++j) {
                s += stoneValue[i + j];
                ans = max(ans, s - dfs(i + j + 1));
            }
            return f[i] = ans;
        };
        int ans = dfs(0);
        if (ans == 0) {
            return "Tie";
        }
        return ans > 0 ? "Alice" : "Bob";
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func stoneGameIII(stoneValue []int) string {
	n := len(stoneValue)
	f := make([]int, n)
	const inf = 1 << 30
	for i := range f {
		f[i] = inf
	}
	var dfs func(int) int
	dfs = func(i int) int {
		if i >= n {
			return 0
		}
		if f[i] != inf {
			return f[i]
		}
		ans, s := -(1 << 30), 0
		for j := 0; j < 3 && i+j < n; j++ {
			s += stoneValue[i+j]
			ans = max(ans, s-dfs(i+j+1))
		}
		f[i] = ans
		return ans
	}
	ans := dfs(0)
	if ans == 0 {
		return "Tie"
	}
	if ans > 0 {
		return "Alice"
	}
	return "Bob"
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function stoneGameIII(stoneValue: number[]): string {
    const n = stoneValue.length;
    const inf = 1 << 30;
    const f: number[] = new Array(n).fill(inf);
    const dfs = (i: number): number => {
        if (i >= n) {
            return 0;
        }
        if (f[i] !== inf) {
            return f[i];
        }
        let ans = -inf;
        let s = 0;
        for (let j = 0; j < 3 && i + j < n; ++j) {
            s += stoneValue[i + j];
            ans = Math.max(ans, s - dfs(i + j + 1));
        }
        return (f[i] = ans);
    };
    const ans = dfs(0);
    if (ans === 0) {
        return 'Tie';
    }
    return ans > 0 ? 'Alice' : 'Bob';
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>Alice 和 Bob 继续他们的石子游戏。几堆石子 <strong>排成一行</strong> ，每堆石子都对应一个得分，由数组 <code>stoneValue</code> 给出。</p>

<p>Alice 和 Bob 轮流取石子，<strong>Alice</strong> 总是先开始。在每个玩家的回合中，该玩家可以拿走剩下石子中的的前 <strong>1、2 或 3 堆石子</strong> 。比赛一直持续到所有石头都被拿走。</p>

<p>每个玩家的最终得分为他所拿到的每堆石子的对应得分之和。每个玩家的初始分数都是 <strong>0</strong> 。</p>

<p>比赛的目标是决出最高分，得分最高的选手将会赢得比赛，比赛也可能会出现平局。</p>

<p>假设 Alice 和 Bob 都采取 <strong>最优策略</strong> 。</p>

<p>如果 Alice 赢了就返回 <code>"Alice"</code> <em>，</em>Bob 赢了就返回<em> </em><code>"Bob"</code><em>，</em>分数相同返回 <code>"Tie"</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>values = [1,2,3,7]
<strong>输出：</strong>"Bob"
<strong>解释：</strong>Alice 总是会输，她的最佳选择是拿走前三堆，得分变成 6 。但是 Bob 的得分为 7，Bob 获胜。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>values = [1,2,3,-9]
<strong>输出：</strong>"Alice"
<strong>解释：</strong>Alice 要想获胜就必须在第一个回合拿走前三堆石子，给 Bob 留下负分。
如果 Alice 只拿走第一堆，那么她的得分为 1，接下来 Bob 拿走第二、三堆，得分为 5 。之后 Alice 只能拿到分数 -9 的石子堆，输掉比赛。
如果 Alice 拿走前两堆，那么她的得分为 3，接下来 Bob 拿走第三堆，得分为 3 。之后 Alice 只能拿到分数 -9 的石子堆，同样会输掉比赛。
注意，他们都应该采取 <strong>最优策略 </strong>，所以在这里 Alice 将选择能够使她获胜的方案。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>values = [1,2,3,6]
<strong>输出：</strong>"Tie"
<strong>解释：</strong>Alice 无法赢得比赛。如果她决定选择前三堆，她可以以平局结束比赛，否则她就会输。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= stoneValue.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>-1000&nbsp;&lt;= stoneValue[i] &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

我们设计一个函数 $dfs(i)$，表示当前玩家在 $[i, n)$ 范围内进行游戏时，可以获得的最大得分差值。如果 $dfs(0) \gt 0$，则表示先手玩家 Alice 可以获胜；如果 $dfs(0) \lt 0$，则表示后手玩家 Bob 可以获胜；否则，表示两人打成平局。

函数 $dfs(i)$ 的执行逻辑如下：

-   如果 $i \geq n$，说明当前没有石子可以拿了，直接返回 $0$ 即可；
-   否则，我们枚举当前玩家拿走前 $j+1$ 堆石子，其中 $j \in \{0, 1, 2\}$，那么另一个玩家在下一轮可以获得的得分差值为 $dfs(i + j + 1)$，从而当前玩家可以获得的得分差值为 $\sum_{k=i}^{i+j} stoneValue[k] - dfs(i + j + 1)$。我们要使得当前玩家的得分差值最大，因此可以用 $\max$ 函数得到最大得分差值，即：

$$
dfs(i) = \max_{j \in \{0, 1, 2\}} \left\{\sum_{k=i}^{i+j} stoneValue[k] - dfs(i + j + 1)\right\}
$$

为了防止重复计算，我们可以使用记忆化搜索。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是石子的堆数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def stoneGameIII(self, stoneValue: List[int]) -> str:
        @cache
        def dfs(i: int) -> int:
            if i >= n:
                return 0
            ans, s = -inf, 0
            for j in range(3):
                if i + j >= n:
                    break
                s += stoneValue[i + j]
                ans = max(ans, s - dfs(i + j + 1))
            return ans

        n = len(stoneValue)
        ans = dfs(0)
        if ans == 0:
            return 'Tie'
        return 'Alice' if ans > 0 else 'Bob'
```

#### Java

```java
class Solution {
    private int[] stoneValue;
    private Integer[] f;
    private int n;

    public String stoneGameIII(int[] stoneValue) {
        n = stoneValue.length;
        f = new Integer[n];
        this.stoneValue = stoneValue;
        int ans = dfs(0);
        if (ans == 0) {
            return "Tie";
        }
        return ans > 0 ? "Alice" : "Bob";
    }

    private int dfs(int i) {
        if (i >= n) {
            return 0;
        }
        if (f[i] != null) {
            return f[i];
        }
        int ans = -(1 << 30);
        int s = 0;
        for (int j = 0; j < 3 && i + j < n; ++j) {
            s += stoneValue[i + j];
            ans = Math.max(ans, s - dfs(i + j + 1));
        }
        return f[i] = ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        int f[n];
        memset(f, 0x3f, sizeof(f));
        function<int(int)> dfs = [&](int i) -> int {
            if (i >= n) {
                return 0;
            }
            if (f[i] != 0x3f3f3f3f) {
                return f[i];
            }
            int ans = -(1 << 30), s = 0;
            for (int j = 0; j < 3 && i + j < n; ++j) {
                s += stoneValue[i + j];
                ans = max(ans, s - dfs(i + j + 1));
            }
            return f[i] = ans;
        };
        int ans = dfs(0);
        if (ans == 0) {
            return "Tie";
        }
        return ans > 0 ? "Alice" : "Bob";
    }
};
```

#### Go

```go
func stoneGameIII(stoneValue []int) string {
	n := len(stoneValue)
	f := make([]int, n)
	const inf = 1 << 30
	for i := range f {
		f[i] = inf
	}
	var dfs func(int) int
	dfs = func(i int) int {
		if i >= n {
			return 0
		}
		if f[i] != inf {
			return f[i]
		}
		ans, s := -(1 << 30), 0
		for j := 0; j < 3 && i+j < n; j++ {
			s += stoneValue[i+j]
			ans = max(ans, s-dfs(i+j+1))
		}
		f[i] = ans
		return ans
	}
	ans := dfs(0)
	if ans == 0 {
		return "Tie"
	}
	if ans > 0 {
		return "Alice"
	}
	return "Bob"
}
```

#### TypeScript

```ts
function stoneGameIII(stoneValue: number[]): string {
    const n = stoneValue.length;
    const inf = 1 << 30;
    const f: number[] = new Array(n).fill(inf);
    const dfs = (i: number): number => {
        if (i >= n) {
            return 0;
        }
        if (f[i] !== inf) {
            return f[i];
        }
        let ans = -inf;
        let s = 0;
        for (let j = 0; j < 3 && i + j < n; ++j) {
            s += stoneValue[i + j];
            ans = Math.max(ans, s - dfs(i + j + 1));
        }
        return (f[i] = ans);
    };
    const ans = dfs(0);
    if (ans === 0) {
        return 'Tie';
    }
    return ans > 0 ? 'Alice' : 'Bob';
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1407. 排名靠前的旅行者](https://leetcode.cn/problems/top-travellers){#1407}

{{< tabs "1407" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT name, IFNULL(SUM(distance), 0) AS travelled_distance
FROM
    Users AS u
    LEFT JOIN Rides AS r ON u.id = r.user_id
GROUP BY u.id
ORDER BY 2 DESC, 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code>Users</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| id            | int     |
| name          | varchar |
+---------------+---------+
id 是该表中具有唯一值的列。
name 是用户名字。</pre>

<p>&nbsp;</p>

<p>表：<code>Rides</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| id            | int     |
| user_id       | int     |
| distance      | int     |
+---------------+---------+
id 是该表中具有唯一值的列。
user_id 是本次行程的用户的 id, 而该用户此次行程距离为 distance 。
</pre>

<p>&nbsp;</p>

<p>编写解决方案，报告每个用户的旅行距离。</p>

<p>返回的结果表单，以&nbsp;<code>travelled_distance</code>&nbsp;<strong>降序排列</strong> ，如果有两个或者更多的用户旅行了相同的距离,&nbsp;那么再以&nbsp;<code>name</code>&nbsp;<strong>升序排列</strong> 。</p>

<p>返回结果格式如下例所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
Users 表：
+------+-----------+
| id   | name      |
+------+-----------+
| 1    | Alice     |
| 2    | Bob       |
| 3    | Alex      |
| 4    | Donald    |
| 7    | Lee       |
| 13   | Jonathan  |
| 19   | Elvis     |
+------+-----------+

Rides 表：
+------+----------+----------+
| id   | user_id  | distance |
+------+----------+----------+
| 1    | 1        | 120      |
| 2    | 2        | 317      |
| 3    | 3        | 222      |
| 4    | 7        | 100      |
| 5    | 13       | 312      |
| 6    | 19       | 50       |
| 7    | 7        | 120      |
| 8    | 19       | 400      |
| 9    | 7        | 230      |
+------+----------+----------+
<strong>输出：</strong>
+----------+--------------------+
| name     | travelled_distance |
+----------+--------------------+
| Elvis    | 450                |
| Lee      | 450                |
| Bob      | 317                |
| Jonathan | 312                |
| Alex     | 222                |
| Alice    | 120                |
| Donald   | 0                  |
+----------+--------------------+
<strong>解释：</strong>
Elvis 和 Lee 旅行了 450 英里，Elvis 是排名靠前的旅行者，因为他的名字在字母表上的排序比 Lee 更小。
Bob, Jonathan, Alex 和 Alice 只有一次行程，我们只按此次行程的全部距离对他们排序。
Donald 没有任何行程, 他的旅行距离为 0。
</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：左连接 + 分组统计

我们可以使用左连接，将 `Users` 表与 `Rides` 表按照用户 id 连接，然后按照用户 id 分组，统计每个用户的旅行距离。注意，如果用户没有旅行记录，那么旅行距离为 $0$。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT name, IFNULL(SUM(distance), 0) AS travelled_distance
FROM
    Users AS u
    LEFT JOIN Rides AS r ON u.id = r.user_id
GROUP BY u.id
ORDER BY 2 DESC, 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1408. 数组中的字符串匹配](https://leetcode.cn/problems/string-matching-in-an-array){#1408}

{{< tabs "1408" >}}

{{% tab "python" %}}
```python
class Solution:
    def stringMatching(self, words: List[str]) -> List[str]:
        ans = []
        for i, s in enumerate(words):
            if any(i != j and s in t for j, t in enumerate(words)):
                ans.append(s)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<String> stringMatching(String[] words) {
        List<String> ans = new ArrayList<>();
        int n = words.length;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j && words[j].contains(words[i])) {
                    ans.add(words[i]);
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
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        int n = words.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j && words[j].find(words[i]) != string::npos) {
                    ans.push_back(words[i]);
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
func stringMatching(words []string) []string {
	ans := []string{}
	for i, w1 := range words {
		for j, w2 := range words {
			if i != j && strings.Contains(w2, w1) {
				ans = append(ans, w1)
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
function stringMatching(words: string[]): string[] {
    const ans: string[] = [];
    const n = words.length;
    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < n; ++j) {
            if (words[j].includes(words[i]) && i !== j) {
                ans.push(words[i]);
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
    pub fn string_matching(words: Vec<String>) -> Vec<String> {
        let mut ans = Vec::new();
        let n = words.len();
        for i in 0..n {
            for j in 0..n {
                if i != j && words[j].contains(&words[i]) {
                    ans.push(words[i].clone());
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

<p>给你一个字符串数组 <code>words</code> ，数组中的每个字符串都可以看作是一个单词。请你按 <strong>任意</strong> 顺序返回 <code>words</code> 中是其他单词的 <span data-keyword="substring-nonempty">子字符串</span> 的所有单词。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>words = ["mass","as","hero","superhero"]
<strong>输出：</strong>["as","hero"]
<strong>解释：</strong>"as" 是 "mass" 的子字符串，"hero" 是 "superhero" 的子字符串。
["hero","as"] 也是有效的答案。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>words = ["leetcode","et","code"]
<strong>输出：</strong>["et","code"]
<strong>解释：</strong>"et" 和 "code" 都是 "leetcode" 的子字符串。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>words = ["blue","green","bu"]
<strong>输出：</strong>[]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 100</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 30</code></li>
	<li><code>words[i]</code> 仅包含小写英文字母。</li>
	<li>题目数据 <strong>保证</strong> <code>words</code>&nbsp;的每个字符串都是独一无二的。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：暴力枚举

我们直接枚举所有的字符串 $words[i]$，判断其是否为其他字符串的子串，如果是，将其加入答案。

时间复杂度 $O(n^3)$，空间复杂度 $O(n)$。其中 $n$ 为字符串数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def stringMatching(self, words: List[str]) -> List[str]:
        ans = []
        for i, s in enumerate(words):
            if any(i != j and s in t for j, t in enumerate(words)):
                ans.append(s)
        return ans
```

#### Java

```java
class Solution {
    public List<String> stringMatching(String[] words) {
        List<String> ans = new ArrayList<>();
        int n = words.length;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j && words[j].contains(words[i])) {
                    ans.add(words[i]);
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
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        int n = words.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j && words[j].find(words[i]) != string::npos) {
                    ans.push_back(words[i]);
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
func stringMatching(words []string) []string {
	ans := []string{}
	for i, w1 := range words {
		for j, w2 := range words {
			if i != j && strings.Contains(w2, w1) {
				ans = append(ans, w1)
				break
			}
		}
	}
	return ans
}
```

#### TypeScript

```ts
function stringMatching(words: string[]): string[] {
    const ans: string[] = [];
    const n = words.length;
    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < n; ++j) {
            if (words[j].includes(words[i]) && i !== j) {
                ans.push(words[i]);
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
    pub fn string_matching(words: Vec<String>) -> Vec<String> {
        let mut ans = Vec::new();
        let n = words.len();
        for i in 0..n {
            for j in 0..n {
                if i != j && words[j].contains(&words[i]) {
                    ans.push(words[i].clone());
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

# [1409. 查询带键的排列](https://leetcode.cn/problems/queries-on-a-permutation-with-key){#1409}

{{< tabs "1409" >}}

{{% tab "python" %}}
```python
class BinaryIndexedTree:
    def __init__(self, n):
        self.n = n
        self.c = [0] * (n + 1)

    @staticmethod
    def lowbit(x):
        return x & -x

    def update(self, x, delta):
        while x <= self.n:
            self.c[x] += delta
            x += BinaryIndexedTree.lowbit(x)

    def query(self, x):
        s = 0
        while x > 0:
            s += self.c[x]
            x -= BinaryIndexedTree.lowbit(x)
        return s


class Solution:
    def processQueries(self, queries: List[int], m: int) -> List[int]:
        n = len(queries)
        pos = [0] * (m + 1)
        tree = BinaryIndexedTree(m + n)
        for i in range(1, m + 1):
            pos[i] = n + i
            tree.update(n + i, 1)

        ans = []
        for i, v in enumerate(queries):
            j = pos[v]
            tree.update(j, -1)
            ans.append(tree.query(j))
            pos[v] = n - i
            tree.update(n - i, 1)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class BinaryIndexedTree {
    private int n;
    private int[] c;

    public BinaryIndexedTree(int n) {
        this.n = n;
        c = new int[n + 1];
    }

    public void update(int x, int delta) {
        while (x <= n) {
            c[x] += delta;
            x += lowbit(x);
        }
    }

    public int query(int x) {
        int s = 0;
        while (x > 0) {
            s += c[x];
            x -= lowbit(x);
        }
        return s;
    }

    public static int lowbit(int x) {
        return x & -x;
    }
}

class Solution {
    public int[] processQueries(int[] queries, int m) {
        int n = queries.length;
        BinaryIndexedTree tree = new BinaryIndexedTree(m + n);
        int[] pos = new int[m + 1];
        for (int i = 1; i <= m; ++i) {
            pos[i] = n + i;
            tree.update(n + i, 1);
        }
        int[] ans = new int[n];
        int k = 0;
        for (int i = 0; i < n; ++i) {
            int v = queries[i];
            int j = pos[v];
            tree.update(j, -1);
            ans[k++] = tree.query(j);
            pos[v] = n - i;
            tree.update(n - i, 1);
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class BinaryIndexedTree {
public:
    int n;
    vector<int> c;

    BinaryIndexedTree(int _n)
        : n(_n)
        , c(_n + 1) {}

    void update(int x, int delta) {
        while (x <= n) {
            c[x] += delta;
            x += lowbit(x);
        }
    }

    int query(int x) {
        int s = 0;
        while (x > 0) {
            s += c[x];
            x -= lowbit(x);
        }
        return s;
    }

    int lowbit(int x) {
        return x & -x;
    }
};

class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        int n = queries.size();
        vector<int> pos(m + 1);
        BinaryIndexedTree* tree = new BinaryIndexedTree(m + n);
        for (int i = 1; i <= m; ++i) {
            pos[i] = n + i;
            tree->update(n + i, 1);
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            int v = queries[i];
            int j = pos[v];
            tree->update(j, -1);
            ans.push_back(tree->query(j));
            pos[v] = n - i;
            tree->update(n - i, 1);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
type BinaryIndexedTree struct {
	n int
	c []int
}

func newBinaryIndexedTree(n int) *BinaryIndexedTree {
	c := make([]int, n+1)
	return &BinaryIndexedTree{n, c}
}

func (this *BinaryIndexedTree) lowbit(x int) int {
	return x & -x
}

func (this *BinaryIndexedTree) update(x, delta int) {
	for x <= this.n {
		this.c[x] += delta
		x += this.lowbit(x)
	}
}

func (this *BinaryIndexedTree) query(x int) int {
	s := 0
	for x > 0 {
		s += this.c[x]
		x -= this.lowbit(x)
	}
	return s
}

func processQueries(queries []int, m int) []int {
	n := len(queries)
	pos := make([]int, m+1)
	tree := newBinaryIndexedTree(m + n)
	for i := 1; i <= m; i++ {
		pos[i] = n + i
		tree.update(n+i, 1)
	}
	ans := []int{}
	for i, v := range queries {
		j := pos[v]
		tree.update(j, -1)
		ans = append(ans, tree.query(j))
		pos[v] = n - i
		tree.update(n-i, 1)
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

<p>给定一个正整数数组&nbsp;<code>queries</code> ，其取值范围在&nbsp;<code>1</code> 到 <code>m</code> 之间。 请你根据以下规则按顺序处理所有&nbsp;<code>queries[i]</code>（从 <code>i=0</code> 到 <code>i=queries.length-1</code>）：</p>

<ul>
	<li>首先，你有一个排列&nbsp;<code>P=[1,2,3,...,m]</code>。</li>
	<li>对于当前的 <code>i</code> ，找到&nbsp;<code>queries[i]</code> 在排列 <code>P</code> 中的位置（<b>从 0 开始索引</b>），然后将它移到排列&nbsp;<code>P</code> 的开头（即下标为 0 处）。注意， <code>queries[i]</code>&nbsp;的查询结果是 <code>queries[i]</code> 在 <code>P</code> 中移动前的位置。</li>
</ul>

<p>返回一个数组，包含从给定 &nbsp;<code>queries</code>&nbsp;中查询到的结果。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>queries = [3,1,2,1], m = 5
<strong>输出：</strong>[2,1,2,1] 
<strong>解释：处理</strong> queries 的过程如下：
对于 i=0: queries[i]=3, P=[1,2,3,4,5], 3 在 P 中的位置是 <strong>2</strong>，然后我们把 3 移动到 P 的开头，得到 P=[3,1,2,4,5] 。
对于 i=1: queries[i]=1, P=[3,1,2,4,5], 1 在 P 中的位置是 <strong>1</strong>，然后我们把 1 移动到 P 的开头，得到 P=[1,3,2,4,5] 。 
对于 i=2: queries[i]=2, P=[1,3,2,4,5], 2 在 P 中的位置是 <strong>2</strong>，然后我们把 2 移动到 P 的开头，得到 P=[2,1,3,4,5] 。
对于 i=3: queries[i]=1, P=[2,1,3,4,5], 1 在 P 中的位置是 <strong>1</strong>，然后我们把 1 移动到 P 的开头，得到 P=[1,2,3,4,5] 。 
因此，包含结果的数组为 [2,1,2,1] 。  
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>queries = [4,1,2,2], m = 4
<strong>输出：</strong>[3,1,2,0]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>queries = [7,5,5,8,3], m = 8
<strong>输出：</strong>[6,5,0,7,5]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= m &lt;= 10^3</code></li>
	<li><code>1 &lt;= queries.length &lt;= m</code></li>
	<li><code>1 &lt;= queries[i] &lt;= m</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

题目数据规模不大，可以直接模拟。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def processQueries(self, queries: List[int], m: int) -> List[int]:
        p = list(range(1, m + 1))
        ans = []
        for v in queries:
            j = p.index(v)
            ans.append(j)
            p.pop(j)
            p.insert(0, v)
        return ans
```

#### Java

```java
class Solution {
    public int[] processQueries(int[] queries, int m) {
        List<Integer> p = new LinkedList<>();
        for (int i = 1; i <= m; ++i) {
            p.add(i);
        }
        int[] ans = new int[queries.length];
        int i = 0;
        for (int v : queries) {
            int j = p.indexOf(v);
            ans[i++] = j;
            p.remove(j);
            p.add(0, v);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> p(m);
        iota(p.begin(), p.end(), 1);
        vector<int> ans;
        for (int v : queries) {
            int j = 0;
            for (int i = 0; i < m; ++i) {
                if (p[i] == v) {
                    j = i;
                    break;
                }
            }
            ans.push_back(j);
            p.erase(p.begin() + j);
            p.insert(p.begin(), v);
        }
        return ans;
    }
};
```

#### Go

```go
func processQueries(queries []int, m int) []int {
	p := make([]int, m)
	for i := range p {
		p[i] = i + 1
	}
	ans := []int{}
	for _, v := range queries {
		j := 0
		for i := range p {
			if p[i] == v {
				j = i
				break
			}
		}
		ans = append(ans, j)
		p = append(p[:j], p[j+1:]...)
		p = append([]int{v}, p...)
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：树状数组

树状数组，也称作“二叉索引树”（Binary Indexed Tree）或 Fenwick 树。 它可以高效地实现如下两个操作：

1. **单点更新** `update(x, delta)`： 把序列 x 位置的数加上一个值 delta；
1. **前缀和查询** `query(x)`：查询序列 `[1,...x]` 区间的区间和，即位置 x 的前缀和。

这两个操作的时间复杂度均为 $O(\log n)$。

树状数组最基本的功能就是求比某点 x 小的点的个数（这里的比较是抽象的概念，可以是数的大小、坐标的大小、质量的大小等等）。

比如给定数组 `a[5] = {2, 5, 3, 4, 1}`，求 `b[i] = 位置 i 左边小于等于 a[i] 的数的个数`。对于此例，`b[5] = {0, 1, 1, 2, 0}`。

解决方案是直接遍历数组，每个位置先求出 `query(a[i])`，然后再修改树状数组 `update(a[i], 1)` 即可。当数的范围比较大时，需要进行离散化，即先进行去重并排序，然后对每个数字进行编号。

<!-- tabs:start -->

#### Python3

```python
class BinaryIndexedTree:
    def __init__(self, n):
        self.n = n
        self.c = [0] * (n + 1)

    @staticmethod
    def lowbit(x):
        return x & -x

    def update(self, x, delta):
        while x <= self.n:
            self.c[x] += delta
            x += BinaryIndexedTree.lowbit(x)

    def query(self, x):
        s = 0
        while x > 0:
            s += self.c[x]
            x -= BinaryIndexedTree.lowbit(x)
        return s


class Solution:
    def processQueries(self, queries: List[int], m: int) -> List[int]:
        n = len(queries)
        pos = [0] * (m + 1)
        tree = BinaryIndexedTree(m + n)
        for i in range(1, m + 1):
            pos[i] = n + i
            tree.update(n + i, 1)

        ans = []
        for i, v in enumerate(queries):
            j = pos[v]
            tree.update(j, -1)
            ans.append(tree.query(j))
            pos[v] = n - i
            tree.update(n - i, 1)
        return ans
```

#### Java

```java
class BinaryIndexedTree {
    private int n;
    private int[] c;

    public BinaryIndexedTree(int n) {
        this.n = n;
        c = new int[n + 1];
    }

    public void update(int x, int delta) {
        while (x <= n) {
            c[x] += delta;
            x += lowbit(x);
        }
    }

    public int query(int x) {
        int s = 0;
        while (x > 0) {
            s += c[x];
            x -= lowbit(x);
        }
        return s;
    }

    public static int lowbit(int x) {
        return x & -x;
    }
}

class Solution {
    public int[] processQueries(int[] queries, int m) {
        int n = queries.length;
        BinaryIndexedTree tree = new BinaryIndexedTree(m + n);
        int[] pos = new int[m + 1];
        for (int i = 1; i <= m; ++i) {
            pos[i] = n + i;
            tree.update(n + i, 1);
        }
        int[] ans = new int[n];
        int k = 0;
        for (int i = 0; i < n; ++i) {
            int v = queries[i];
            int j = pos[v];
            tree.update(j, -1);
            ans[k++] = tree.query(j);
            pos[v] = n - i;
            tree.update(n - i, 1);
        }
        return ans;
    }
}
```

#### C++

```cpp
class BinaryIndexedTree {
public:
    int n;
    vector<int> c;

    BinaryIndexedTree(int _n)
        : n(_n)
        , c(_n + 1) {}

    void update(int x, int delta) {
        while (x <= n) {
            c[x] += delta;
            x += lowbit(x);
        }
    }

    int query(int x) {
        int s = 0;
        while (x > 0) {
            s += c[x];
            x -= lowbit(x);
        }
        return s;
    }

    int lowbit(int x) {
        return x & -x;
    }
};

class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        int n = queries.size();
        vector<int> pos(m + 1);
        BinaryIndexedTree* tree = new BinaryIndexedTree(m + n);
        for (int i = 1; i <= m; ++i) {
            pos[i] = n + i;
            tree->update(n + i, 1);
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            int v = queries[i];
            int j = pos[v];
            tree->update(j, -1);
            ans.push_back(tree->query(j));
            pos[v] = n - i;
            tree->update(n - i, 1);
        }
        return ans;
    }
};
```

#### Go

```go
type BinaryIndexedTree struct {
	n int
	c []int
}

func newBinaryIndexedTree(n int) *BinaryIndexedTree {
	c := make([]int, n+1)
	return &BinaryIndexedTree{n, c}
}

func (this *BinaryIndexedTree) lowbit(x int) int {
	return x & -x
}

func (this *BinaryIndexedTree) update(x, delta int) {
	for x <= this.n {
		this.c[x] += delta
		x += this.lowbit(x)
	}
}

func (this *BinaryIndexedTree) query(x int) int {
	s := 0
	for x > 0 {
		s += this.c[x]
		x -= this.lowbit(x)
	}
	return s
}

func processQueries(queries []int, m int) []int {
	n := len(queries)
	pos := make([]int, m+1)
	tree := newBinaryIndexedTree(m + n)
	for i := 1; i <= m; i++ {
		pos[i] = n + i
		tree.update(n+i, 1)
	}
	ans := []int{}
	for i, v := range queries {
		j := pos[v]
		tree.update(j, -1)
		ans = append(ans, tree.query(j))
		pos[v] = n - i
		tree.update(n-i, 1)
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
