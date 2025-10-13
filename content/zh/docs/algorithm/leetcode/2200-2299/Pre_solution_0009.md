---
title: "2280_表示一个折线图的最少线段数"
date: 2025-10-08T18:39:07+08:00
weight: 9
tags: [二分查找, 几何, 前缀和, 单调栈, 哈希表, 图, 堆（优先队列）, 字符串, 排序, 数学, 数组, 数论, 栈, 树状数组, 矩阵, 线段树, 计数, 设计, 贪心, 链表]
---

{{< markmap >}}
### [2280_表示一个折线图的最少线段数](#2280)
#### [几何](#2280)
#### [数组](#2280)
#### [数学](#2280)
#### [数论](#2280)
#### [排序](#2280)
### [2281_巫师的总力量和](#2281)
#### [栈](#2281)
#### [数组](#2281)
#### [前缀和](#2281)
#### [单调栈](#2281)
### [2282_在一个网格中可以看到的人数 🔒](#2282)
#### [栈](#2282)
#### [数组](#2282)
#### [矩阵](#2282)
#### [单调栈](#2282)
### [2283_判断一个数的数字计数是否等于数位的值](#2283)
#### [哈希表](#2283)
#### [字符串](#2283)
#### [计数](#2283)
### [2284_最多单词数的发件人](#2284)
#### [数组](#2284)
#### [哈希表](#2284)
#### [字符串](#2284)
#### [计数](#2284)
### [2285_道路的最大总重要性](#2285)
#### [贪心](#2285)
#### [图](#2285)
#### [排序](#2285)
#### [堆（优先队列）](#2285)
### [2286_以组为单位订音乐会的门票](#2286)
#### [设计](#2286)
#### [树状数组](#2286)
#### [线段树](#2286)
#### [二分查找](#2286)
### [2287_重排字符形成目标字符串](#2287)
#### [哈希表](#2287)
#### [字符串](#2287)
#### [计数](#2287)
### [2288_价格减免](#2288)
#### [字符串](#2288)
### [2289_使数组按非递减顺序排列](#2289)
#### [栈](#2289)
#### [数组](#2289)
#### [链表](#2289)
#### [单调栈](#2289)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2280_表示一个折线图的最少线段数
___
#### 几何
___
#### 数组
___
#### 数学
___
#### 数论
___
#### 排序
---
### 2281_巫师的总力量和
___
#### 栈
___
#### 数组
___
#### 前缀和
___
#### 单调栈
---
### 2282_在一个网格中可以看到的人数 🔒
___
#### 栈
___
#### 数组
___
#### 矩阵
___
#### 单调栈
---
### 2283_判断一个数的数字计数是否等于数位的值
___
#### 哈希表
___
#### 字符串
___
#### 计数
---
### 2284_最多单词数的发件人
___
#### 数组
___
#### 哈希表
___
#### 字符串
___
#### 计数
---
### 2285_道路的最大总重要性
___
#### 贪心
___
#### 图
___
#### 排序
___
#### 堆（优先队列）
---
### 2286_以组为单位订音乐会的门票
___
#### 设计
___
#### 树状数组
___
#### 线段树
___
#### 二分查找
---
### 2287_重排字符形成目标字符串
___
#### 哈希表
___
#### 字符串
___
#### 计数
---
### 2288_价格减免
___
#### 字符串
---
### 2289_使数组按非递减顺序排列
___
#### 栈
___
#### 数组
___
#### 链表
___
#### 单调栈
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 几何 | 前缀和 |
| 单调栈 | 哈希表 | 图 |
| 堆（优先队列） | 字符串 | 排序 |
| 数学 | 数组 | 数论 |
| 栈 | 树状数组 | 矩阵 |
| 线段树 | 计数 | 设计 |
| 贪心 | 链表 |  |

# [2280. 表示一个折线图的最少线段数](https://leetcode.cn/problems/minimum-lines-to-represent-a-line-chart){#2280}

{{< tabs "2280" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumLines(self, stockPrices: List[List[int]]) -> int:
        stockPrices.sort()
        dx, dy = 0, 1
        ans = 0
        for (x, y), (x1, y1) in pairwise(stockPrices):
            dx1, dy1 = x1 - x, y1 - y
            if dy * dx1 != dx * dy1:
                ans += 1
            dx, dy = dx1, dy1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumLines(int[][] stockPrices) {
        Arrays.sort(stockPrices, (a, b) -> a[0] - b[0]);
        int dx = 0, dy = 1;
        int ans = 0;
        for (int i = 1; i < stockPrices.length; ++i) {
            int x = stockPrices[i - 1][0], y = stockPrices[i - 1][1];
            int x1 = stockPrices[i][0], y1 = stockPrices[i][1];
            int dx1 = x1 - x, dy1 = y1 - y;
            if (dy * dx1 != dx * dy1) {
                ++ans;
            }
            dx = dx1;
            dy = dy1;
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
    int minimumLines(vector<vector<int>>& stockPrices) {
        sort(stockPrices.begin(), stockPrices.end());
        int dx = 0, dy = 1;
        int ans = 0;
        for (int i = 1; i < stockPrices.size(); ++i) {
            int x = stockPrices[i - 1][0], y = stockPrices[i - 1][1];
            int x1 = stockPrices[i][0], y1 = stockPrices[i][1];
            int dx1 = x1 - x, dy1 = y1 - y;
            if ((long long) dy * dx1 != (long long) dx * dy1) ++ans;
            dx = dx1;
            dy = dy1;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumLines(stockPrices [][]int) int {
	ans := 0
	sort.Slice(stockPrices, func(i, j int) bool { return stockPrices[i][0] < stockPrices[j][0] })
	for i, dx, dy := 1, 0, 1; i < len(stockPrices); i++ {
		x, y := stockPrices[i-1][0], stockPrices[i-1][1]
		x1, y1 := stockPrices[i][0], stockPrices[i][1]
		dx1, dy1 := x1-x, y1-y
		if dy*dx1 != dx*dy1 {
			ans++
		}
		dx, dy = dx1, dy1
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumLines(stockPrices: number[][]): number {
    const n = stockPrices.length;
    stockPrices.sort((a, b) => a[0] - b[0]);
    let ans = 0;
    let pre = [BigInt(0), BigInt(0)];
    for (let i = 1; i < n; i++) {
        const [x1, y1] = stockPrices[i - 1];
        const [x2, y2] = stockPrices[i];
        const dx = BigInt(x2 - x1),
            dy = BigInt(y2 - y1);
        if (i == 1 || dx * pre[1] !== dy * pre[0]) ans++;
        pre = [dx, dy];
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

<p>给你一个二维整数数组&nbsp;<code>stockPrices</code> ，其中&nbsp;<code>stockPrices[i] = [day<sub>i</sub>, price<sub>i</sub>]</code>&nbsp;表示股票在&nbsp;<code>day<sub>i</sub></code>&nbsp;的价格为&nbsp;<code>price<sub>i</sub></code>&nbsp;。<strong>折线图</strong>&nbsp;是一个二维平面上的若干个点组成的图，横坐标表示日期，纵坐标表示价格，折线图由相邻的点连接而成。比方说下图是一个例子：</p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2200-2299/2280.Minimum%20Lines%20to%20Represent%20a%20Line%20Chart/images/1920px-pushkin_population_historysvg.png" style="width: 500px; height: 313px;">
<p>请你返回要表示一个折线图所需要的 <strong>最少线段数</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2200-2299/2280.Minimum%20Lines%20to%20Represent%20a%20Line%20Chart/images/ex0.png" style="width: 400px; height: 400px;"></p>

<pre><b>输入：</b>stockPrices = [[1,7],[2,6],[3,5],[4,4],[5,4],[6,3],[7,2],[8,1]]
<b>输出：</b>3
<strong>解释：</strong>
上图为输入对应的图，横坐标表示日期，纵坐标表示价格。
以下 3 个线段可以表示折线图：
- 线段 1 （红色）从 (1,7) 到 (4,4) ，经过 (1,7) ，(2,6) ，(3,5) 和 (4,4) 。
- 线段 2 （蓝色）从 (4,4) 到 (5,4) 。
- 线段 3 （绿色）从 (5,4) 到 (8,1) ，经过 (5,4) ，(6,3) ，(7,2) 和 (8,1) 。
可以证明，无法用少于 3 条线段表示这个折线图。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2200-2299/2280.Minimum%20Lines%20to%20Represent%20a%20Line%20Chart/images/ex1.png" style="width: 325px; height: 325px;"></p>

<pre><b>输入：</b>stockPrices = [[3,4],[1,2],[7,8],[2,3]]
<b>输出：</b>1
<strong>解释：</strong>
如上图所示，折线图可以用一条线段表示。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= stockPrices.length &lt;= 10<sup>5</sup></code></li>
	<li><code>stockPrices[i].length == 2</code></li>
	<li><code>1 &lt;= day<sub>i</sub>, price<sub>i</sub> &lt;= 10<sup>9</sup></code></li>
	<li>所有&nbsp;<code>day<sub>i</sub></code>&nbsp;<strong>互不相同</strong>&nbsp;。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：斜率比较

需要注意：

1. 只有一个点时，需要的线段数为 0；
1. 利用除法计算斜率时，会有浮点误差，可以改成乘法比较。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumLines(self, stockPrices: List[List[int]]) -> int:
        stockPrices.sort()
        dx, dy = 0, 1
        ans = 0
        for (x, y), (x1, y1) in pairwise(stockPrices):
            dx1, dy1 = x1 - x, y1 - y
            if dy * dx1 != dx * dy1:
                ans += 1
            dx, dy = dx1, dy1
        return ans
```

#### Java

```java
class Solution {
    public int minimumLines(int[][] stockPrices) {
        Arrays.sort(stockPrices, (a, b) -> a[0] - b[0]);
        int dx = 0, dy = 1;
        int ans = 0;
        for (int i = 1; i < stockPrices.length; ++i) {
            int x = stockPrices[i - 1][0], y = stockPrices[i - 1][1];
            int x1 = stockPrices[i][0], y1 = stockPrices[i][1];
            int dx1 = x1 - x, dy1 = y1 - y;
            if (dy * dx1 != dx * dy1) {
                ++ans;
            }
            dx = dx1;
            dy = dy1;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        sort(stockPrices.begin(), stockPrices.end());
        int dx = 0, dy = 1;
        int ans = 0;
        for (int i = 1; i < stockPrices.size(); ++i) {
            int x = stockPrices[i - 1][0], y = stockPrices[i - 1][1];
            int x1 = stockPrices[i][0], y1 = stockPrices[i][1];
            int dx1 = x1 - x, dy1 = y1 - y;
            if ((long long) dy * dx1 != (long long) dx * dy1) ++ans;
            dx = dx1;
            dy = dy1;
        }
        return ans;
    }
};
```

#### Go

```go
func minimumLines(stockPrices [][]int) int {
	ans := 0
	sort.Slice(stockPrices, func(i, j int) bool { return stockPrices[i][0] < stockPrices[j][0] })
	for i, dx, dy := 1, 0, 1; i < len(stockPrices); i++ {
		x, y := stockPrices[i-1][0], stockPrices[i-1][1]
		x1, y1 := stockPrices[i][0], stockPrices[i][1]
		dx1, dy1 := x1-x, y1-y
		if dy*dx1 != dx*dy1 {
			ans++
		}
		dx, dy = dx1, dy1
	}
	return ans
}
```

#### TypeScript

```ts
function minimumLines(stockPrices: number[][]): number {
    const n = stockPrices.length;
    stockPrices.sort((a, b) => a[0] - b[0]);
    let ans = 0;
    let pre = [BigInt(0), BigInt(0)];
    for (let i = 1; i < n; i++) {
        const [x1, y1] = stockPrices[i - 1];
        const [x2, y2] = stockPrices[i];
        const dx = BigInt(x2 - x1),
            dy = BigInt(y2 - y1);
        if (i == 1 || dx * pre[1] !== dy * pre[0]) ans++;
        pre = [dx, dy];
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2281. 巫师的总力量和](https://leetcode.cn/problems/sum-of-total-strength-of-wizards){#2281}

{{< tabs "2281" >}}

{{% tab "python" %}}
```python
class Solution:
    def totalStrength(self, strength: List[int]) -> int:
        n = len(strength)
        left = [-1] * n
        right = [n] * n
        stk = []
        for i, v in enumerate(strength):
            while stk and strength[stk[-1]] >= v:
                stk.pop()
            if stk:
                left[i] = stk[-1]
            stk.append(i)
        stk = []
        for i in range(n - 1, -1, -1):
            while stk and strength[stk[-1]] > strength[i]:
                stk.pop()
            if stk:
                right[i] = stk[-1]
            stk.append(i)

        ss = list(accumulate(list(accumulate(strength, initial=0)), initial=0))
        mod = int(1e9) + 7
        ans = 0
        for i, v in enumerate(strength):
            l, r = left[i] + 1, right[i] - 1
            a = (ss[r + 2] - ss[i + 1]) * (i - l + 1)
            b = (ss[i + 1] - ss[l]) * (r - i + 1)
            ans = (ans + (a - b) * v) % mod
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int totalStrength(int[] strength) {
        int n = strength.length;
        int[] left = new int[n];
        int[] right = new int[n];
        Arrays.fill(left, -1);
        Arrays.fill(right, n);
        Deque<Integer> stk = new ArrayDeque<>();
        for (int i = 0; i < n; ++i) {
            while (!stk.isEmpty() && strength[stk.peek()] >= strength[i]) {
                stk.pop();
            }
            if (!stk.isEmpty()) {
                left[i] = stk.peek();
            }
            stk.push(i);
        }
        stk.clear();
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.isEmpty() && strength[stk.peek()] > strength[i]) {
                stk.pop();
            }
            if (!stk.isEmpty()) {
                right[i] = stk.peek();
            }
            stk.push(i);
        }
        int mod = (int) 1e9 + 7;
        int[] s = new int[n + 1];
        for (int i = 0; i < n; ++i) {
            s[i + 1] = (s[i] + strength[i]) % mod;
        }
        int[] ss = new int[n + 2];
        for (int i = 0; i < n + 1; ++i) {
            ss[i + 1] = (ss[i] + s[i]) % mod;
        }
        long ans = 0;
        for (int i = 0; i < n; ++i) {
            int v = strength[i];
            int l = left[i] + 1, r = right[i] - 1;
            long a = (long) (i - l + 1) * (ss[r + 2] - ss[i + 1]);
            long b = (long) (r - i + 1) * (ss[i + 1] - ss[l]);
            ans = (ans + v * ((a - b) % mod)) % mod;
        }
        return (int) (ans + mod) % mod;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int totalStrength(vector<int>& strength) {
        int n = strength.size();
        vector<int> left(n, -1);
        vector<int> right(n, n);
        stack<int> stk;
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && strength[stk.top()] >= strength[i]) stk.pop();
            if (!stk.empty()) left[i] = stk.top();
            stk.push(i);
        }
        stk = stack<int>();
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.empty() && strength[stk.top()] > strength[i]) stk.pop();
            if (!stk.empty()) right[i] = stk.top();
            stk.push(i);
        }
        int mod = 1e9 + 7;
        vector<int> s(n + 1);
        for (int i = 0; i < n; ++i) s[i + 1] = (s[i] + strength[i]) % mod;
        vector<int> ss(n + 2);
        for (int i = 0; i < n + 1; ++i) ss[i + 1] = (ss[i] + s[i]) % mod;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int v = strength[i];
            int l = left[i] + 1, r = right[i] - 1;
            long a = (long) (i - l + 1) * (ss[r + 2] - ss[i + 1]);
            long b = (long) (r - i + 1) * (ss[i + 1] - ss[l]);
            ans = (ans + v * ((a - b) % mod)) % mod;
        }
        return (int) (ans + mod) % mod;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func totalStrength(strength []int) int {
	n := len(strength)
	left := make([]int, n)
	right := make([]int, n)
	for i := range left {
		left[i] = -1
		right[i] = n
	}
	stk := []int{}
	for i, v := range strength {
		for len(stk) > 0 && strength[stk[len(stk)-1]] >= v {
			stk = stk[:len(stk)-1]
		}
		if len(stk) > 0 {
			left[i] = stk[len(stk)-1]
		}
		stk = append(stk, i)
	}
	stk = []int{}
	for i := n - 1; i >= 0; i-- {
		for len(stk) > 0 && strength[stk[len(stk)-1]] > strength[i] {
			stk = stk[:len(stk)-1]
		}
		if len(stk) > 0 {
			right[i] = stk[len(stk)-1]
		}
		stk = append(stk, i)
	}
	mod := int(1e9) + 7
	s := make([]int, n+1)
	for i, v := range strength {
		s[i+1] = (s[i] + v) % mod
	}
	ss := make([]int, n+2)
	for i, v := range s {
		ss[i+1] = (ss[i] + v) % mod
	}
	ans := 0
	for i, v := range strength {
		l, r := left[i]+1, right[i]-1
		a := (ss[r+2] - ss[i+1]) * (i - l + 1)
		b := (ss[i+1] - ss[l]) * (r - i + 1)
		ans = (ans + v*((a-b)%mod)) % mod
	}
	return (ans + mod) % mod
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>作为国王的统治者，你有一支巫师军队听你指挥。</p>

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>strength</code>&nbsp;，其中&nbsp;<code>strength[i]</code>&nbsp;表示第&nbsp;<code>i</code>&nbsp;位巫师的力量值。对于连续的一组巫师（也就是这些巫师的力量值是&nbsp;<code>strength</code>&nbsp;的&nbsp;<strong>子数组</strong>），<strong>总力量</strong>&nbsp;定义为以下两个值的&nbsp;<strong>乘积</strong>&nbsp;：</p>

<ul>
	<li>巫师中 <strong>最弱</strong>&nbsp;的能力值。</li>
	<li>组中所有巫师的个人力量值 <strong>之和</strong>&nbsp;。</li>
</ul>

<p>请你返回 <strong>所有</strong>&nbsp;巫师组的 <strong>总</strong>&nbsp;力量之和。由于答案可能很大，请将答案对&nbsp;<code>10<sup>9</sup> + 7</code>&nbsp;<strong>取余</strong>&nbsp;后返回。</p>

<p><strong>子数组</strong>&nbsp;是一个数组里 <strong>非空</strong>&nbsp;连续子序列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>strength = [1,3,1,2]
<b>输出：</b>44
<b>解释：</b>以下是所有连续巫师组：
- [<em><strong>1</strong></em>,3,1,2] 中 [1] ，总力量值为 min([1]) * sum([1]) = 1 * 1 = 1
- [1,<em><strong>3</strong></em>,1,2] 中 [3] ，总力量值为 min([3]) * sum([3]) = 3 * 3 = 9
- [1,3,<em><strong>1</strong></em>,2] 中 [1] ，总力量值为 min([1]) * sum([1]) = 1 * 1 = 1
- [1,3,1,<em><strong>2</strong></em>] 中 [2] ，总力量值为 min([2]) * sum([2]) = 2 * 2 = 4
- [<em><strong>1,3</strong></em>,1,2] 中 [1,3] ，总力量值为 min([1,3]) * sum([1,3]) = 1 * 4 = 4
- [1,<em><strong>3,1</strong></em>,2] 中 [3,1] ，总力量值为 min([3,1]) * sum([3,1]) = 1 * 4 = 4
- [1,3,<em><strong>1,2</strong></em>] 中 [1,2] ，总力量值为 min([1,2]) * sum([1,2]) = 1 * 3 = 3
- [<em><strong>1,3,1</strong></em>,2] 中 [1,3,1] ，总力量值为 min([1,3,1]) * sum([1,3,1]) = 1 * 5 = 5
- [1,<em><strong>3,1,2</strong></em>] 中 [3,1,2] ，总力量值为 min([3,1,2]) * sum([3,1,2]) = 1 * 6 = 6
- [<em><strong>1,3,1,2</strong></em>] 中 [1,3,1,2] ，总力量值为 min([1,3,1,2]) * sum([1,3,1,2]) = 1 * 7 = 7
所有力量值之和为 1 + 9 + 1 + 4 + 4 + 4 + 3 + 5 + 6 + 7 = 44 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>strength = [5,4,6]
<b>输出：</b>213
<b>解释：</b>以下是所有连续巫师组：
- [<em><strong>5</strong></em>,4,6] 中 [5] ，总力量值为 min([5]) * sum([5]) = 5 * 5 = 25
- [5,<em><strong>4</strong></em>,6] 中 [4] ，总力量值为 min([4]) * sum([4]) = 4 * 4 = 16
- [5,4,<em><strong>6</strong></em>] 中 [6] ，总力量值为 min([6]) * sum([6]) = 6 * 6 = 36
- [<em><strong>5,4</strong></em>,6] 中 [5,4] ，总力量值为 min([5,4]) * sum([5,4]) = 4 * 9 = 36
- [5,<em><strong>4,6</strong></em>] 中 [4,6] ，总力量值为 min([4,6]) * sum([4,6]) = 4 * 10 = 40
- [<em><strong>5,4,6</strong></em>] 中 [5,4,6] ，总力量值为 min([5,4,6]) * sum([5,4,6]) = 4 * 15 = 60
所有力量值之和为 25 + 16 + 36 + 36 + 40 + 60 = 213 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= strength.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= strength[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：单调栈 + 前缀和

相似题目：

-   [907. 子数组的最小值之和](https://github.com/doocs/leetcode/blob/main/solution/0900-0999/0907.Sum%20of%20Subarray%20Minimums/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def totalStrength(self, strength: List[int]) -> int:
        n = len(strength)
        left = [-1] * n
        right = [n] * n
        stk = []
        for i, v in enumerate(strength):
            while stk and strength[stk[-1]] >= v:
                stk.pop()
            if stk:
                left[i] = stk[-1]
            stk.append(i)
        stk = []
        for i in range(n - 1, -1, -1):
            while stk and strength[stk[-1]] > strength[i]:
                stk.pop()
            if stk:
                right[i] = stk[-1]
            stk.append(i)

        ss = list(accumulate(list(accumulate(strength, initial=0)), initial=0))
        mod = int(1e9) + 7
        ans = 0
        for i, v in enumerate(strength):
            l, r = left[i] + 1, right[i] - 1
            a = (ss[r + 2] - ss[i + 1]) * (i - l + 1)
            b = (ss[i + 1] - ss[l]) * (r - i + 1)
            ans = (ans + (a - b) * v) % mod
        return ans
```

#### Java

```java
class Solution {
    public int totalStrength(int[] strength) {
        int n = strength.length;
        int[] left = new int[n];
        int[] right = new int[n];
        Arrays.fill(left, -1);
        Arrays.fill(right, n);
        Deque<Integer> stk = new ArrayDeque<>();
        for (int i = 0; i < n; ++i) {
            while (!stk.isEmpty() && strength[stk.peek()] >= strength[i]) {
                stk.pop();
            }
            if (!stk.isEmpty()) {
                left[i] = stk.peek();
            }
            stk.push(i);
        }
        stk.clear();
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.isEmpty() && strength[stk.peek()] > strength[i]) {
                stk.pop();
            }
            if (!stk.isEmpty()) {
                right[i] = stk.peek();
            }
            stk.push(i);
        }
        int mod = (int) 1e9 + 7;
        int[] s = new int[n + 1];
        for (int i = 0; i < n; ++i) {
            s[i + 1] = (s[i] + strength[i]) % mod;
        }
        int[] ss = new int[n + 2];
        for (int i = 0; i < n + 1; ++i) {
            ss[i + 1] = (ss[i] + s[i]) % mod;
        }
        long ans = 0;
        for (int i = 0; i < n; ++i) {
            int v = strength[i];
            int l = left[i] + 1, r = right[i] - 1;
            long a = (long) (i - l + 1) * (ss[r + 2] - ss[i + 1]);
            long b = (long) (r - i + 1) * (ss[i + 1] - ss[l]);
            ans = (ans + v * ((a - b) % mod)) % mod;
        }
        return (int) (ans + mod) % mod;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int totalStrength(vector<int>& strength) {
        int n = strength.size();
        vector<int> left(n, -1);
        vector<int> right(n, n);
        stack<int> stk;
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && strength[stk.top()] >= strength[i]) stk.pop();
            if (!stk.empty()) left[i] = stk.top();
            stk.push(i);
        }
        stk = stack<int>();
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.empty() && strength[stk.top()] > strength[i]) stk.pop();
            if (!stk.empty()) right[i] = stk.top();
            stk.push(i);
        }
        int mod = 1e9 + 7;
        vector<int> s(n + 1);
        for (int i = 0; i < n; ++i) s[i + 1] = (s[i] + strength[i]) % mod;
        vector<int> ss(n + 2);
        for (int i = 0; i < n + 1; ++i) ss[i + 1] = (ss[i] + s[i]) % mod;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int v = strength[i];
            int l = left[i] + 1, r = right[i] - 1;
            long a = (long) (i - l + 1) * (ss[r + 2] - ss[i + 1]);
            long b = (long) (r - i + 1) * (ss[i + 1] - ss[l]);
            ans = (ans + v * ((a - b) % mod)) % mod;
        }
        return (int) (ans + mod) % mod;
    }
};
```

#### Go

```go
func totalStrength(strength []int) int {
	n := len(strength)
	left := make([]int, n)
	right := make([]int, n)
	for i := range left {
		left[i] = -1
		right[i] = n
	}
	stk := []int{}
	for i, v := range strength {
		for len(stk) > 0 && strength[stk[len(stk)-1]] >= v {
			stk = stk[:len(stk)-1]
		}
		if len(stk) > 0 {
			left[i] = stk[len(stk)-1]
		}
		stk = append(stk, i)
	}
	stk = []int{}
	for i := n - 1; i >= 0; i-- {
		for len(stk) > 0 && strength[stk[len(stk)-1]] > strength[i] {
			stk = stk[:len(stk)-1]
		}
		if len(stk) > 0 {
			right[i] = stk[len(stk)-1]
		}
		stk = append(stk, i)
	}
	mod := int(1e9) + 7
	s := make([]int, n+1)
	for i, v := range strength {
		s[i+1] = (s[i] + v) % mod
	}
	ss := make([]int, n+2)
	for i, v := range s {
		ss[i+1] = (ss[i] + v) % mod
	}
	ans := 0
	for i, v := range strength {
		l, r := left[i]+1, right[i]-1
		a := (ss[r+2] - ss[i+1]) * (i - l + 1)
		b := (ss[i+1] - ss[l]) * (r - i + 1)
		ans = (ans + v*((a-b)%mod)) % mod
	}
	return (ans + mod) % mod
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2282. 在一个网格中可以看到的人数 🔒](https://leetcode.cn/problems/number-of-people-that-can-be-seen-in-a-grid){#2282}

{{< tabs "2282" >}}

{{% tab "python" %}}
```python
class Solution:
    def seePeople(self, heights: List[List[int]]) -> List[List[int]]:
        def f(nums: List[int]) -> List[int]:
            n = len(nums)
            stk = []
            ans = [0] * n
            for i in range(n - 1, -1, -1):
                while stk and stk[-1] < nums[i]:
                    ans[i] += 1
                    stk.pop()
                if stk:
                    ans[i] += 1
                while stk and stk[-1] == nums[i]:
                    stk.pop()
                stk.append(nums[i])
            return ans

        ans = [f(row) for row in heights]
        m, n = len(heights), len(heights[0])
        for j in range(n):
            add = f([heights[i][j] for i in range(m)])
            for i in range(m):
                ans[i][j] += add[i]
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[][] seePeople(int[][] heights) {
        int m = heights.length, n = heights[0].length;
        int[][] ans = new int[m][0];
        for (int i = 0; i < m; ++i) {
            ans[i] = f(heights[i]);
        }
        for (int j = 0; j < n; ++j) {
            int[] nums = new int[m];
            for (int i = 0; i < m; ++i) {
                nums[i] = heights[i][j];
            }
            int[] add = f(nums);
            for (int i = 0; i < m; ++i) {
                ans[i][j] += add[i];
            }
        }
        return ans;
    }

    private int[] f(int[] nums) {
        int n = nums.length;
        int[] ans = new int[n];
        Deque<Integer> stk = new ArrayDeque<>();
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.isEmpty() && stk.peek() < nums[i]) {
                stk.pop();
                ++ans[i];
            }
            if (!stk.isEmpty()) {
                ++ans[i];
            }
            while (!stk.isEmpty() && stk.peek() == nums[i]) {
                stk.pop();
            }
            stk.push(nums[i]);
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
    vector<vector<int>> seePeople(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        auto f = [](vector<int>& nums) {
            int n = nums.size();
            vector<int> ans(n);
            stack<int> stk;
            for (int i = n - 1; ~i; --i) {
                while (stk.size() && stk.top() < nums[i]) {
                    ++ans[i];
                    stk.pop();
                }
                if (stk.size()) {
                    ++ans[i];
                }
                while (stk.size() && stk.top() == nums[i]) {
                    stk.pop();
                }
                stk.push(nums[i]);
            }
            return ans;
        };
        vector<vector<int>> ans;
        for (auto& row : heights) {
            ans.push_back(f(row));
        }
        for (int j = 0; j < n; ++j) {
            vector<int> col;
            for (int i = 0; i < m; ++i) {
                col.push_back(heights[i][j]);
            }
            vector<int> add = f(col);
            for (int i = 0; i < m; ++i) {
                ans[i][j] += add[i];
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func seePeople(heights [][]int) (ans [][]int) {
	f := func(nums []int) []int {
		n := len(nums)
		ans := make([]int, n)
		stk := []int{}
		for i := n - 1; i >= 0; i-- {
			for len(stk) > 0 && stk[len(stk)-1] < nums[i] {
				ans[i]++
				stk = stk[:len(stk)-1]
			}
			if len(stk) > 0 {
				ans[i]++
			}
			for len(stk) > 0 && stk[len(stk)-1] == nums[i] {
				stk = stk[:len(stk)-1]
			}
			stk = append(stk, nums[i])
		}
		return ans
	}
	for _, row := range heights {
		ans = append(ans, f(row))
	}
	n := len(heights[0])
	for j := 0; j < n; j++ {
		col := make([]int, len(heights))
		for i := range heights {
			col[i] = heights[i][j]
		}
		for i, v := range f(col) {
			ans[i][j] += v
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function seePeople(heights: number[][]): number[][] {
    const f = (nums: number[]): number[] => {
        const n = nums.length;
        const ans: number[] = new Array(n).fill(0);
        const stk: number[] = [];
        for (let i = n - 1; ~i; --i) {
            while (stk.length && stk.at(-1) < nums[i]) {
                stk.pop();
                ++ans[i];
            }
            if (stk.length) {
                ++ans[i];
            }
            while (stk.length && stk.at(-1) === nums[i]) {
                stk.pop();
            }
            stk.push(nums[i]);
        }
        return ans;
    };
    const ans: number[][] = [];
    for (const row of heights) {
        ans.push(f(row));
    }
    const n = heights[0].length;
    for (let j = 0; j < n; ++j) {
        const col: number[] = [];
        for (const row of heights) {
            col.push(row[j]);
        }
        const add = f(col);
        for (let i = 0; i < ans.length; ++i) {
            ans[i][j] += add[i];
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

<p>给定一个 <code>m x n</code> <strong>下标从 0 开始</strong>的二维正整数数组 <code>heights</code>，其中 <code>heights[i][j]</code> 是站在位置 <code>(i, j)</code>&nbsp;上的人的高度。</p>

<p>站在 <code>(row<sub>1</sub>, col<sub>1</sub>)</code>&nbsp;位置的人可以看到站在 <code>(row<sub>2</sub>, col<sub>2</sub>)</code> 位置的人，前提是:</p>

<ul>
	<li><code>(row<sub>2</sub>, col<sub>2</sub>)</code>&nbsp;的人在&nbsp;<code>(row<sub>1</sub>, col<sub>1</sub>)</code> 的人的右边&nbsp;<strong>或&nbsp;</strong>下面。更正式地说，要么 <code>row<sub>1</sub> == row<sub>2</sub></code>&nbsp;时&nbsp;<code>col<sub>1</sub> &lt; col<sub>2</sub></code>，要么&nbsp;<code>row<sub>1</sub> &lt; row<sub>2</sub></code><sub>&nbsp;</sub>时 <code>col<sub>1</sub> == col<sub>2</sub></code>。</li>
	<li>他们中间的人&nbsp;<strong>都&nbsp;</strong>比他们两个矮。</li>
</ul>

<p>返回<em>一个&nbsp;<code>m x n</code> 的二维整数数组<code>answer</code>，其中&nbsp;<code>answer[i][j]</code>&nbsp;是位于&nbsp;<code>(i, j)</code> 位置的人可以看到的人数。</em></p>

<p>&nbsp;</p>

<p><strong class="example">示例 1:</strong></p>
<img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2200-2299/2282.Number%20of%20People%20That%20Can%20Be%20Seen%20in%20a%20Grid/images/image-20220524180458-1.png" style="width: 700px; height: 164px;" />
<pre>
<strong>输入:</strong> heights = [[3,1,4,2,5]]
<strong>输出:</strong> [[2,1,2,1,0]]
<strong>解释:</strong>
- (0,0) 上的人可以看到 (0,1) 和 (0,2) 的人。
  注意，他看不到 (0,4) 上的人，因为 (0,2) 上的人比他高。
- (0,1) 上的人可以看到 (0,2) 上的人。
- (0,2) 上的人可以看到 (0,3) 和 (0,4) 的人。
- (0,3) 上的人可以看到 (0,4) 上的人。
- (0,4) 上的人看不到任何人。</pre>

<p><strong class="example">示例 2:</strong></p>
<img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2200-2299/2282.Number%20of%20People%20That%20Can%20Be%20Seen%20in%20a%20Grid/images/image-20220523113533-2.png" style="width: 400px; height: 249px;" />
<pre>
<strong>输入:</strong> heights = [[5,1],[3,1],[4,1]]
<strong>输出:</strong> [[3,1],[2,1],[1,0]]
<strong>解释:</strong>
- (0,0) 上的人可以看到 (0,1)、(1,0) 和 (2,0) 的人。
- (0,1) 上的人可以看到 (1,1) 上的人。
- (1,0) 上的人可以看到 (1,1) 和 (2,0) 的人。
- (1,1) 上的人可以看到 (2,1) 上的人。
- (2,0) 上的人可以看到 (2,1) 上的人。
- (2,1) 上的人看不到任何人。</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= heights.length &lt;= 400</code></li>
	<li><code>1 &lt;= heights[i].length &lt;= 400</code></li>
	<li><code>1 &lt;= heights[i][j] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：单调栈

我们观察发现，对于第 $i$ 个人来说，他能看到的人一定是按从左到右（或者从上到下）高度严格单调递增的。

因此，对于每一行，我们可以用单调栈来求出每个人能看到的人数。

具体地，我们可以倒序遍历数组，用一个从栈顶到栈底单调递增的栈 $stk$ 记录已经遍历过的人的高度。

对于第 $i$ 个人，如果栈不为空并且栈顶元素小于 $heights[i]$，累加当前第 $i$ 个人能看到的人数，然后将栈顶元素出栈，直到栈为空或者栈顶元素大于等于 $heights[i]$。如果此时栈不为空，说明栈顶元素大于等于 $heights[i]$，那么第 $i$ 个人能看到的人数还要再加 $1$。接下来，如果栈不为空并且栈顶元素等于 $heights[i]$，那么栈顶元素出栈。最后，将 $heights[i]$ 入栈，继续遍历下一个人。

这样处理过后，我们就可以得到每一行每个人能看到的人数。

同理，我们可以对每一列进行处理，得到每一列每个人能看到的人数。最后，我们将每一行和每一列的答案相加，就可以得到最终的答案。

时间复杂度 $O(m \times n)$，空间复杂度 $O(\max(m, n))$。其中 $m$ 和 $n$ 分别是数组 $heights$ 的行数和列数。

相似题目：

-   [1944. 队列中可以看到的人数](https://github.com/doocs/leetcode/blob/main/solution/1900-1999/1944.Number%20of%20Visible%20People%20in%20a%20Queue/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def seePeople(self, heights: List[List[int]]) -> List[List[int]]:
        def f(nums: List[int]) -> List[int]:
            n = len(nums)
            stk = []
            ans = [0] * n
            for i in range(n - 1, -1, -1):
                while stk and stk[-1] < nums[i]:
                    ans[i] += 1
                    stk.pop()
                if stk:
                    ans[i] += 1
                while stk and stk[-1] == nums[i]:
                    stk.pop()
                stk.append(nums[i])
            return ans

        ans = [f(row) for row in heights]
        m, n = len(heights), len(heights[0])
        for j in range(n):
            add = f([heights[i][j] for i in range(m)])
            for i in range(m):
                ans[i][j] += add[i]
        return ans
```

#### Java

```java
class Solution {
    public int[][] seePeople(int[][] heights) {
        int m = heights.length, n = heights[0].length;
        int[][] ans = new int[m][0];
        for (int i = 0; i < m; ++i) {
            ans[i] = f(heights[i]);
        }
        for (int j = 0; j < n; ++j) {
            int[] nums = new int[m];
            for (int i = 0; i < m; ++i) {
                nums[i] = heights[i][j];
            }
            int[] add = f(nums);
            for (int i = 0; i < m; ++i) {
                ans[i][j] += add[i];
            }
        }
        return ans;
    }

    private int[] f(int[] nums) {
        int n = nums.length;
        int[] ans = new int[n];
        Deque<Integer> stk = new ArrayDeque<>();
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.isEmpty() && stk.peek() < nums[i]) {
                stk.pop();
                ++ans[i];
            }
            if (!stk.isEmpty()) {
                ++ans[i];
            }
            while (!stk.isEmpty() && stk.peek() == nums[i]) {
                stk.pop();
            }
            stk.push(nums[i]);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<vector<int>> seePeople(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        auto f = [](vector<int>& nums) {
            int n = nums.size();
            vector<int> ans(n);
            stack<int> stk;
            for (int i = n - 1; ~i; --i) {
                while (stk.size() && stk.top() < nums[i]) {
                    ++ans[i];
                    stk.pop();
                }
                if (stk.size()) {
                    ++ans[i];
                }
                while (stk.size() && stk.top() == nums[i]) {
                    stk.pop();
                }
                stk.push(nums[i]);
            }
            return ans;
        };
        vector<vector<int>> ans;
        for (auto& row : heights) {
            ans.push_back(f(row));
        }
        for (int j = 0; j < n; ++j) {
            vector<int> col;
            for (int i = 0; i < m; ++i) {
                col.push_back(heights[i][j]);
            }
            vector<int> add = f(col);
            for (int i = 0; i < m; ++i) {
                ans[i][j] += add[i];
            }
        }
        return ans;
    }
};
```

#### Go

```go
func seePeople(heights [][]int) (ans [][]int) {
	f := func(nums []int) []int {
		n := len(nums)
		ans := make([]int, n)
		stk := []int{}
		for i := n - 1; i >= 0; i-- {
			for len(stk) > 0 && stk[len(stk)-1] < nums[i] {
				ans[i]++
				stk = stk[:len(stk)-1]
			}
			if len(stk) > 0 {
				ans[i]++
			}
			for len(stk) > 0 && stk[len(stk)-1] == nums[i] {
				stk = stk[:len(stk)-1]
			}
			stk = append(stk, nums[i])
		}
		return ans
	}
	for _, row := range heights {
		ans = append(ans, f(row))
	}
	n := len(heights[0])
	for j := 0; j < n; j++ {
		col := make([]int, len(heights))
		for i := range heights {
			col[i] = heights[i][j]
		}
		for i, v := range f(col) {
			ans[i][j] += v
		}
	}
	return
}
```

#### TypeScript

```ts
function seePeople(heights: number[][]): number[][] {
    const f = (nums: number[]): number[] => {
        const n = nums.length;
        const ans: number[] = new Array(n).fill(0);
        const stk: number[] = [];
        for (let i = n - 1; ~i; --i) {
            while (stk.length && stk.at(-1) < nums[i]) {
                stk.pop();
                ++ans[i];
            }
            if (stk.length) {
                ++ans[i];
            }
            while (stk.length && stk.at(-1) === nums[i]) {
                stk.pop();
            }
            stk.push(nums[i]);
        }
        return ans;
    };
    const ans: number[][] = [];
    for (const row of heights) {
        ans.push(f(row));
    }
    const n = heights[0].length;
    for (let j = 0; j < n; ++j) {
        const col: number[] = [];
        for (const row of heights) {
            col.push(row[j]);
        }
        const add = f(col);
        for (let i = 0; i < ans.length; ++i) {
            ans[i][j] += add[i];
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

# [2283. 判断一个数的数字计数是否等于数位的值](https://leetcode.cn/problems/check-if-number-has-equal-digit-count-and-digit-value){#2283}

{{< tabs "2283" >}}

{{% tab "python" %}}
```python
class Solution:
    def digitCount(self, num: str) -> bool:
        cnt = Counter(int(x) for x in num)
        return all(cnt[i] == int(x) for i, x in enumerate(num))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean digitCount(String num) {
        int[] cnt = new int[10];
        int n = num.length();
        for (int i = 0; i < n; ++i) {
            ++cnt[num.charAt(i) - '0'];
        }
        for (int i = 0; i < n; ++i) {
            if (num.charAt(i) - '0' != cnt[i]) {
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
    bool digitCount(string num) {
        int cnt[10]{};
        for (char& c : num) {
            ++cnt[c - '0'];
        }
        for (int i = 0; i < num.size(); ++i) {
            if (cnt[i] != num[i] - '0') {
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
func digitCount(num string) bool {
	cnt := [10]int{}
	for _, c := range num {
		cnt[c-'0']++
	}
	for i, c := range num {
		if int(c-'0') != cnt[i] {
			return false
		}
	}
	return true
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function digitCount(num: string): boolean {
    const cnt: number[] = Array(10).fill(0);
    for (const c of num) {
        ++cnt[+c];
    }
    for (let i = 0; i < num.length; ++i) {
        if (cnt[i] !== +num[i]) {
            return false;
        }
    }
    return true;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn digit_count(num: String) -> bool {
        let mut cnt = vec![0; 10];
        for c in num.chars() {
            let x = c.to_digit(10).unwrap() as usize;
            cnt[x] += 1;
        }
        for (i, c) in num.chars().enumerate() {
            let x = c.to_digit(10).unwrap() as usize;
            if cnt[i] != x {
                return false;
            }
        }
        true
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
bool digitCount(char* num) {
    int cnt[10] = {0};
    for (int i = 0; num[i] != '\0'; ++i) {
        ++cnt[num[i] - '0'];
    }
    for (int i = 0; num[i] != '\0'; ++i) {
        if (cnt[i] != num[i] - '0') {
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

<p>给你一个下标从 <strong>0</strong>&nbsp;开始长度为 <code>n</code>&nbsp;的字符串&nbsp;<code>num</code>&nbsp;，它只包含数字。</p>

<p>如果对于 <strong>每个</strong><em>&nbsp;</em><code>0 &lt;= i &lt; n</code>&nbsp;的下标&nbsp;<code>i</code>&nbsp;，都满足数位<em>&nbsp;</em><code>i</code>&nbsp;在 <code>num</code>&nbsp;中出现了&nbsp;<code>num[i]</code>次，那么请你返回&nbsp;<code>true</code>&nbsp;，否则返回&nbsp;<code>false</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>num = "1210"
<b>输出：</b>true
<strong>解释：</strong>
num[0] = '1' 。数字 0 在 num 中出现了一次。
num[1] = '2' 。数字 1 在 num 中出现了两次。
num[2] = '1' 。数字 2 在 num 中出现了一次。
num[3] = '0' 。数字 3 在 num 中出现了零次。
"1210" 满足题目要求条件，所以返回 true 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>num = "030"
<b>输出：</b>false
<strong>解释：</strong>
num[0] = '0' 。数字 0 应该出现 0 次，但是在 num 中出现了两次。
num[1] = '3' 。数字 1 应该出现 3 次，但是在 num 中出现了零次。
num[2] = '0' 。数字 2 在 num 中出现了 0 次。
下标 0 和 1 都违反了题目要求，所以返回 false 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == num.length</code></li>
	<li><code>1 &lt;= n &lt;= 10</code></li>
	<li><code>num</code>&nbsp;只包含数字。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数 + 枚举

我们可以用一个长度为 $10$ 的数组 $\textit{cnt}$ 统计字符串 $\textit{num}$ 中每个数字出现的次数，然后再枚举字符串 $\textit{num}$ 中的每个数字，判断其出现的次数是否等于该数字本身。如果对于所有的数字都满足这个条件，那么返回 $\text{true}$，否则返回 $\text{false}$。

时间复杂度 $O(n)$，空间复杂度 $O(|\Sigma|)$。其中 $n$ 是字符串 $\textit{num}$ 的长度，而 $|\Sigma|$ 是数字的取值范围，即 $10$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def digitCount(self, num: str) -> bool:
        cnt = Counter(int(x) for x in num)
        return all(cnt[i] == int(x) for i, x in enumerate(num))
```

#### Java

```java
class Solution {
    public boolean digitCount(String num) {
        int[] cnt = new int[10];
        int n = num.length();
        for (int i = 0; i < n; ++i) {
            ++cnt[num.charAt(i) - '0'];
        }
        for (int i = 0; i < n; ++i) {
            if (num.charAt(i) - '0' != cnt[i]) {
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
    bool digitCount(string num) {
        int cnt[10]{};
        for (char& c : num) {
            ++cnt[c - '0'];
        }
        for (int i = 0; i < num.size(); ++i) {
            if (cnt[i] != num[i] - '0') {
                return false;
            }
        }
        return true;
    }
};
```

#### Go

```go
func digitCount(num string) bool {
	cnt := [10]int{}
	for _, c := range num {
		cnt[c-'0']++
	}
	for i, c := range num {
		if int(c-'0') != cnt[i] {
			return false
		}
	}
	return true
}
```

#### TypeScript

```ts
function digitCount(num: string): boolean {
    const cnt: number[] = Array(10).fill(0);
    for (const c of num) {
        ++cnt[+c];
    }
    for (let i = 0; i < num.length; ++i) {
        if (cnt[i] !== +num[i]) {
            return false;
        }
    }
    return true;
}
```

#### Rust

```rust
impl Solution {
    pub fn digit_count(num: String) -> bool {
        let mut cnt = vec![0; 10];
        for c in num.chars() {
            let x = c.to_digit(10).unwrap() as usize;
            cnt[x] += 1;
        }
        for (i, c) in num.chars().enumerate() {
            let x = c.to_digit(10).unwrap() as usize;
            if cnt[i] != x {
                return false;
            }
        }
        true
    }
}
```

#### C

```c
bool digitCount(char* num) {
    int cnt[10] = {0};
    for (int i = 0; num[i] != '\0'; ++i) {
        ++cnt[num[i] - '0'];
    }
    for (int i = 0; num[i] != '\0'; ++i) {
        if (cnt[i] != num[i] - '0') {
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

# [2284. 最多单词数的发件人](https://leetcode.cn/problems/sender-with-largest-word-count){#2284}

{{< tabs "2284" >}}

{{% tab "python" %}}
```python
class Solution:
    def largestWordCount(self, messages: List[str], senders: List[str]) -> str:
        cnt = Counter()
        for message, sender in zip(messages, senders):
            cnt[sender] += message.count(" ") + 1
        ans = senders[0]
        for k, v in cnt.items():
            if cnt[ans] < v or (cnt[ans] == v and ans < k):
                ans = k
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String largestWordCount(String[] messages, String[] senders) {
        Map<String, Integer> cnt = new HashMap<>(senders.length);
        for (int i = 0; i < messages.length; ++i) {
            int v = 1;
            for (int j = 0; j < messages[i].length(); ++j) {
                if (messages[i].charAt(j) == ' ') {
                    ++v;
                }
            }
            cnt.merge(senders[i], v, Integer::sum);
        }
        String ans = senders[0];
        for (var e : cnt.entrySet()) {
            String k = e.getKey();
            int v = e.getValue();
            if (cnt.get(ans) < v || (cnt.get(ans) == v && ans.compareTo(k) < 0)) {
                ans = k;
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
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        unordered_map<string, int> cnt;
        for (int i = 0; i < messages.size(); ++i) {
            int v = count(messages[i].begin(), messages[i].end(), ' ') + 1;
            cnt[senders[i]] += v;
        }
        string ans = senders[0];
        for (auto& [k, v] : cnt) {
            if (cnt[ans] < v || (cnt[ans] == v && ans < k)) {
                ans = k;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func largestWordCount(messages []string, senders []string) string {
	cnt := make(map[string]int)
	for i, message := range messages {
		v := strings.Count(message, " ") + 1
		cnt[senders[i]] += v
	}

	ans := senders[0]
	for k, v := range cnt {
		if cnt[ans] < v || (cnt[ans] == v && ans < k) {
			ans = k
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function largestWordCount(messages: string[], senders: string[]): string {
    const cnt: { [key: string]: number } = {};

    for (let i = 0; i < messages.length; ++i) {
        const v = messages[i].split(' ').length;
        cnt[senders[i]] = (cnt[senders[i]] || 0) + v;
    }

    let ans = senders[0];
    for (const k in cnt) {
        if (cnt[ans] < cnt[k] || (cnt[ans] === cnt[k] && ans < k)) {
            ans = k;
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

<p>给你一个聊天记录，共包含 <code>n</code>&nbsp;条信息。给你两个字符串数组&nbsp;<code>messages</code> 和&nbsp;<code>senders</code>&nbsp;，其中&nbsp;<code>messages[i]</code>&nbsp;是&nbsp;<code>senders[i]</code>&nbsp;发出的一条&nbsp;<strong>信息</strong>&nbsp;。</p>

<p>一条 <strong>信息</strong>&nbsp;是若干用单个空格连接的 <strong>单词</strong>&nbsp;，信息开头和结尾不会有多余空格。发件人的 <strong>单词计数</strong>&nbsp;是这个发件人总共发出的 <strong>单词数</strong>&nbsp;。注意，一个发件人可能会发出多于一条信息。</p>

<p>请你返回发出单词数 <strong>最多</strong>&nbsp;的发件人名字。如果有多个发件人发出最多单词数，请你返回 <strong>字典序</strong>&nbsp;最大的名字。</p>

<p><strong>注意：</strong></p>

<ul>
	<li>字典序里，大写字母小于小写字母。</li>
	<li><code>"Alice"</code> 和&nbsp;<code>"alice"</code>&nbsp;是不同的名字。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>messages = ["Hello userTwooo","Hi userThree","Wonderful day Alice","Nice day userThree"], senders = ["Alice","userTwo","userThree","Alice"]
<b>输出：</b>"Alice"
<b>解释：</b>Alice 总共发出了 2 + 3 = 5 个单词。
userTwo 发出了 2 个单词。
userThree 发出了 3 个单词。
由于 Alice 发出单词数最多，所以我们返回 "Alice" 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>messages = ["How is leetcode for everyone","Leetcode is useful for practice"], senders = ["Bob","Charlie"]
<b>输出：</b>"Charlie"
<b>解释：</b>Bob 总共发出了 5 个单词。
Charlie 总共发出了 5 个单词。
由于最多单词数打平，返回字典序最大的名字，也就是 Charlie 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == messages.length == senders.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= messages[i].length &lt;= 100</code></li>
	<li><code>1 &lt;= senders[i].length &lt;= 10</code></li>
	<li><code>messages[i]</code>&nbsp;包含大写字母、小写字母和&nbsp;<code>' '</code>&nbsp;。</li>
	<li><code>messages[i]</code>&nbsp;中所有单词都由 <strong>单个空格</strong>&nbsp;隔开。</li>
	<li><code>messages[i]</code>&nbsp;不包含前导和后缀空格。</li>
	<li><code>senders[i]</code>&nbsp;只包含大写英文字母和小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 枚举

我们可以用一个哈希表 $\textit{cnt}$ 记录每个发件人的单词数，然后遍历哈希表找到单词数最多的发件人，如果有多个发件人发出最多单词数，我们返回字典序最大的名字。

时间复杂度 $O(n + L)$，空间复杂度 $O(n)$，其中 $n$ 是消息的数量，而 $L$ 是所有消息的总长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def largestWordCount(self, messages: List[str], senders: List[str]) -> str:
        cnt = Counter()
        for message, sender in zip(messages, senders):
            cnt[sender] += message.count(" ") + 1
        ans = senders[0]
        for k, v in cnt.items():
            if cnt[ans] < v or (cnt[ans] == v and ans < k):
                ans = k
        return ans
```

#### Java

```java
class Solution {
    public String largestWordCount(String[] messages, String[] senders) {
        Map<String, Integer> cnt = new HashMap<>(senders.length);
        for (int i = 0; i < messages.length; ++i) {
            int v = 1;
            for (int j = 0; j < messages[i].length(); ++j) {
                if (messages[i].charAt(j) == ' ') {
                    ++v;
                }
            }
            cnt.merge(senders[i], v, Integer::sum);
        }
        String ans = senders[0];
        for (var e : cnt.entrySet()) {
            String k = e.getKey();
            int v = e.getValue();
            if (cnt.get(ans) < v || (cnt.get(ans) == v && ans.compareTo(k) < 0)) {
                ans = k;
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
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        unordered_map<string, int> cnt;
        for (int i = 0; i < messages.size(); ++i) {
            int v = count(messages[i].begin(), messages[i].end(), ' ') + 1;
            cnt[senders[i]] += v;
        }
        string ans = senders[0];
        for (auto& [k, v] : cnt) {
            if (cnt[ans] < v || (cnt[ans] == v && ans < k)) {
                ans = k;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func largestWordCount(messages []string, senders []string) string {
	cnt := make(map[string]int)
	for i, message := range messages {
		v := strings.Count(message, " ") + 1
		cnt[senders[i]] += v
	}

	ans := senders[0]
	for k, v := range cnt {
		if cnt[ans] < v || (cnt[ans] == v && ans < k) {
			ans = k
		}
	}
	return ans
}
```

#### TypeScript

```ts
function largestWordCount(messages: string[], senders: string[]): string {
    const cnt: { [key: string]: number } = {};

    for (let i = 0; i < messages.length; ++i) {
        const v = messages[i].split(' ').length;
        cnt[senders[i]] = (cnt[senders[i]] || 0) + v;
    }

    let ans = senders[0];
    for (const k in cnt) {
        if (cnt[ans] < cnt[k] || (cnt[ans] === cnt[k] && ans < k)) {
            ans = k;
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

# [2285. 道路的最大总重要性](https://leetcode.cn/problems/maximum-total-importance-of-roads){#2285}

{{< tabs "2285" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumImportance(self, n: int, roads: List[List[int]]) -> int:
        deg = [0] * n
        for a, b in roads:
            deg[a] += 1
            deg[b] += 1
        deg.sort()
        return sum(i * v for i, v in enumerate(deg, 1))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long maximumImportance(int n, int[][] roads) {
        int[] deg = new int[n];
        for (int[] r : roads) {
            ++deg[r[0]];
            ++deg[r[1]];
        }
        Arrays.sort(deg);
        long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += (long) (i + 1) * deg[i];
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
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> deg(n);
        for (auto& r : roads) {
            ++deg[r[0]];
            ++deg[r[1]];
        }
        sort(deg.begin(), deg.end());
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += (i + 1LL) * deg[i];
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumImportance(n int, roads [][]int) (ans int64) {
	deg := make([]int, n)
	for _, r := range roads {
		deg[r[0]]++
		deg[r[1]]++
	}
	sort.Ints(deg)
	for i, x := range deg {
		ans += int64(x) * int64(i+1)
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumImportance(n: number, roads: number[][]): number {
    const deg: number[] = Array(n).fill(0);
    for (const [a, b] of roads) {
        ++deg[a];
        ++deg[b];
    }
    deg.sort((a, b) => a - b);
    return deg.reduce((acc, cur, idx) => acc + (idx + 1) * cur, 0);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数&nbsp;<code>n</code>&nbsp;，表示一个国家里的城市数目。城市编号为&nbsp;<code>0</code>&nbsp;到&nbsp;<code>n - 1</code>&nbsp;。</p>

<p>给你一个二维整数数组&nbsp;<code>roads</code>&nbsp;，其中&nbsp;<code>roads[i] = [a<sub>i</sub>, b<sub>i</sub>]</code>&nbsp;表示城市&nbsp;<code>a<sub>i</sub></code>&nbsp;和&nbsp;<code>b<sub>i</sub></code>&nbsp;之间有一条&nbsp;<strong>双向</strong>&nbsp;道路。</p>

<p>你需要给每个城市安排一个从 <code>1</code>&nbsp;到 <code>n</code>&nbsp;之间的整数值，且每个值只能被使用 <strong>一次</strong>&nbsp;。道路的 <strong>重要性</strong>&nbsp;定义为这条道路连接的两座城市数值 <strong>之和</strong>&nbsp;。</p>

<p>请你返回在最优安排下，<strong>所有道路重要性</strong> 之和 <strong>最大</strong>&nbsp;为多少。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2200-2299/2285.Maximum%20Total%20Importance%20of%20Roads/images/ex1drawio.png" style="width: 290px; height: 215px;"></p>

<pre><b>输入：</b>n = 5, roads = [[0,1],[1,2],[2,3],[0,2],[1,3],[2,4]]
<b>输出：</b>43
<b>解释：</b>上图展示了国家图和每个城市被安排的值 [2,4,5,3,1] 。
- 道路 (0,1) 重要性为 2 + 4 = 6 。
- 道路 (1,2) 重要性为 4 + 5 = 9 。
- 道路 (2,3) 重要性为 5 + 3 = 8 。
- 道路 (0,2) 重要性为 2 + 5 = 7 。
- 道路 (1,3) 重要性为 4 + 3 = 7 。
- 道路 (2,4) 重要性为 5 + 1 = 6 。
所有道路重要性之和为 6 + 9 + 8 + 7 + 7 + 6 = 43 。
可以证明，重要性之和不可能超过 43 。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2200-2299/2285.Maximum%20Total%20Importance%20of%20Roads/images/ex2drawio.png" style="width: 281px; height: 151px;"></p>

<pre><b>输入：</b>n = 5, roads = [[0,3],[2,4],[1,3]]
<b>输出：</b>20
<b>解释：</b>上图展示了国家图和每个城市被安排的值 [4,3,2,5,1] 。
- 道路 (0,3) 重要性为 4 + 5 = 9 。
- 道路 (2,4) 重要性为 2 + 1 = 3 。
- 道路 (1,3) 重要性为 3 + 5 = 8 。
所有道路重要性之和为 9 + 3 + 8 = 20 。
可以证明，重要性之和不可能超过 20 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= roads.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>roads[i].length == 2</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt;= n - 1</code></li>
	<li><code>a<sub>i</sub> != b<sub>i</sub></code></li>
	<li>没有重复道路。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 排序

我们考虑每个城市对所有道路的总重要性的贡献度，记录在数组 $\textit{deg}$ 中。然后将 $\textit{deg}$ 按贡献度从小到大排序，为城市依次分配 $[1, 2, ..., n]$。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumImportance(self, n: int, roads: List[List[int]]) -> int:
        deg = [0] * n
        for a, b in roads:
            deg[a] += 1
            deg[b] += 1
        deg.sort()
        return sum(i * v for i, v in enumerate(deg, 1))
```

#### Java

```java
class Solution {
    public long maximumImportance(int n, int[][] roads) {
        int[] deg = new int[n];
        for (int[] r : roads) {
            ++deg[r[0]];
            ++deg[r[1]];
        }
        Arrays.sort(deg);
        long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += (long) (i + 1) * deg[i];
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> deg(n);
        for (auto& r : roads) {
            ++deg[r[0]];
            ++deg[r[1]];
        }
        sort(deg.begin(), deg.end());
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += (i + 1LL) * deg[i];
        }
        return ans;
    }
};
```

#### Go

```go
func maximumImportance(n int, roads [][]int) (ans int64) {
	deg := make([]int, n)
	for _, r := range roads {
		deg[r[0]]++
		deg[r[1]]++
	}
	sort.Ints(deg)
	for i, x := range deg {
		ans += int64(x) * int64(i+1)
	}
	return
}
```

#### TypeScript

```ts
function maximumImportance(n: number, roads: number[][]): number {
    const deg: number[] = Array(n).fill(0);
    for (const [a, b] of roads) {
        ++deg[a];
        ++deg[b];
    }
    deg.sort((a, b) => a - b);
    return deg.reduce((acc, cur, idx) => acc + (idx + 1) * cur, 0);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2286. 以组为单位订音乐会的门票](https://leetcode.cn/problems/booking-concert-tickets-in-groups){#2286}

{{< tabs "2286" >}}

{{% tab "python" %}}
```python
class Node:
    __slots__ = "l", "r", "s", "mx"

    def __init__(self):
        self.l = self.r = 0
        self.s = self.mx = 0


class SegmentTree:
    def __init__(self, n, m):
        self.m = m
        self.tr = [Node() for _ in range(n << 2)]
        self.build(1, 1, n)

    def build(self, u, l, r):
        self.tr[u].l, self.tr[u].r = l, r
        if l == r:
            self.tr[u].s = self.tr[u].mx = self.m
            return
        mid = (l + r) >> 1
        self.build(u << 1, l, mid)
        self.build(u << 1 | 1, mid + 1, r)
        self.pushup(u)

    def modify(self, u, x, v):
        if self.tr[u].l == x and self.tr[u].r == x:
            self.tr[u].s = self.tr[u].mx = v
            return
        mid = (self.tr[u].l + self.tr[u].r) >> 1
        if x <= mid:
            self.modify(u << 1, x, v)
        else:
            self.modify(u << 1 | 1, x, v)
        self.pushup(u)

    def query_sum(self, u, l, r):
        if self.tr[u].l >= l and self.tr[u].r <= r:
            return self.tr[u].s
        mid = (self.tr[u].l + self.tr[u].r) >> 1
        v = 0
        if l <= mid:
            v += self.query_sum(u << 1, l, r)
        if r > mid:
            v += self.query_sum(u << 1 | 1, l, r)
        return v

    def query_idx(self, u, l, r, k):
        if self.tr[u].mx < k:
            return 0
        if self.tr[u].l == self.tr[u].r:
            return self.tr[u].l
        mid = (self.tr[u].l + self.tr[u].r) >> 1
        if self.tr[u << 1].mx >= k:
            return self.query_idx(u << 1, l, r, k)
        if r > mid:
            return self.query_idx(u << 1 | 1, l, r, k)
        return 0

    def pushup(self, u):
        self.tr[u].s = self.tr[u << 1].s + self.tr[u << 1 | 1].s
        self.tr[u].mx = max(self.tr[u << 1].mx, self.tr[u << 1 | 1].mx)


class BookMyShow:
    def __init__(self, n: int, m: int):
        self.n = n
        self.tree = SegmentTree(n, m)

    def gather(self, k: int, maxRow: int) -> List[int]:
        maxRow += 1
        i = self.tree.query_idx(1, 1, maxRow, k)
        if i == 0:
            return []
        s = self.tree.query_sum(1, i, i)
        self.tree.modify(1, i, s - k)
        return [i - 1, self.tree.m - s]

    def scatter(self, k: int, maxRow: int) -> bool:
        maxRow += 1
        if self.tree.query_sum(1, 1, maxRow) < k:
            return False
        i = self.tree.query_idx(1, 1, maxRow, 1)
        for j in range(i, self.n + 1):
            s = self.tree.query_sum(1, j, j)
            if s >= k:
                self.tree.modify(1, j, s - k)
                return True
            k -= s
            self.tree.modify(1, j, 0)
        return True


# Your BookMyShow object will be instantiated and called as such:
# obj = BookMyShow(n, m)
# param_1 = obj.gather(k,maxRow)
# param_2 = obj.scatter(k,maxRow)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Node {
    int l, r;
    long mx, s;
}

class SegmentTree {
    private Node[] tr;
    private int m;

    public SegmentTree(int n, int m) {
        this.m = m;
        tr = new Node[n << 2];
        for (int i = 0; i < tr.length; ++i) {
            tr[i] = new Node();
        }
        build(1, 1, n);
    }

    private void build(int u, int l, int r) {
        tr[u].l = l;
        tr[u].r = r;
        if (l == r) {
            tr[u].s = m;
            tr[u].mx = m;
            return;
        }
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }

    public void modify(int u, int x, long v) {
        if (tr[u].l == x && tr[u].r == x) {
            tr[u].s = v;
            tr[u].mx = v;
            return;
        }
        int mid = (tr[u].l + tr[u].r) >> 1;
        if (x <= mid) {
            modify(u << 1, x, v);
        } else {
            modify(u << 1 | 1, x, v);
        }
        pushup(u);
    }

    public long querySum(int u, int l, int r) {
        if (tr[u].l >= l && tr[u].r <= r) {
            return tr[u].s;
        }
        int mid = (tr[u].l + tr[u].r) >> 1;
        long v = 0;
        if (l <= mid) {
            v += querySum(u << 1, l, r);
        }
        if (r > mid) {
            v += querySum(u << 1 | 1, l, r);
        }
        return v;
    }

    public int queryIdx(int u, int l, int r, int k) {
        if (tr[u].mx < k) {
            return 0;
        }
        if (tr[u].l == tr[u].r) {
            return tr[u].l;
        }
        int mid = (tr[u].l + tr[u].r) >> 1;
        if (tr[u << 1].mx >= k) {
            return queryIdx(u << 1, l, r, k);
        }
        if (r > mid) {
            return queryIdx(u << 1 | 1, l, r, k);
        }
        return 0;
    }

    private void pushup(int u) {
        tr[u].s = tr[u << 1].s + tr[u << 1 | 1].s;
        tr[u].mx = Math.max(tr[u << 1].mx, tr[u << 1 | 1].mx);
    }
}

class BookMyShow {
    private int n;
    private int m;
    private SegmentTree tree;

    public BookMyShow(int n, int m) {
        this.n = n;
        this.m = m;
        tree = new SegmentTree(n, m);
    }

    public int[] gather(int k, int maxRow) {
        ++maxRow;
        int i = tree.queryIdx(1, 1, maxRow, k);
        if (i == 0) {
            return new int[] {};
        }
        long s = tree.querySum(1, i, i);
        tree.modify(1, i, s - k);
        return new int[] {i - 1, (int) (m - s)};
    }

    public boolean scatter(int k, int maxRow) {
        ++maxRow;
        if (tree.querySum(1, 1, maxRow) < k) {
            return false;
        }
        int i = tree.queryIdx(1, 1, maxRow, 1);
        for (int j = i; j <= n; ++j) {
            long s = tree.querySum(1, j, j);
            if (s >= k) {
                tree.modify(1, j, s - k);
                return true;
            }
            k -= s;
            tree.modify(1, j, 0);
        }
        return true;
    }
}

/**
 * Your BookMyShow object will be instantiated and called as such:
 * BookMyShow obj = new BookMyShow(n, m);
 * int[] param_1 = obj.gather(k,maxRow);
 * boolean param_2 = obj.scatter(k,maxRow);
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Node {
public:
    int l, r;
    long s, mx;
};

class SegmentTree {
public:
    SegmentTree(int n, int m) {
        this->m = m;
        tr.resize(n << 2);
        for (int i = 0; i < n << 2; ++i) {
            tr[i] = new Node();
        }
        build(1, 1, n);
    }

    void modify(int u, int x, int v) {
        if (tr[u]->l == x && tr[u]->r == x) {
            tr[u]->s = tr[u]->mx = v;
            return;
        }
        int mid = (tr[u]->l + tr[u]->r) >> 1;
        if (x <= mid) {
            modify(u << 1, x, v);
        } else {
            modify(u << 1 | 1, x, v);
        }
        pushup(u);
    }

    long querySum(int u, int l, int r) {
        if (tr[u]->l >= l && tr[u]->r <= r) {
            return tr[u]->s;
        }
        int mid = (tr[u]->l + tr[u]->r) >> 1;
        long v = 0;
        if (l <= mid) {
            v += querySum(u << 1, l, r);
        }
        if (r > mid) {
            v += querySum(u << 1 | 1, l, r);
        }
        return v;
    }

    int queryIdx(int u, int l, int r, int k) {
        if (tr[u]->mx < k) {
            return 0;
        }
        if (tr[u]->l == tr[u]->r) {
            return tr[u]->l;
        }
        int mid = (tr[u]->l + tr[u]->r) >> 1;
        if (tr[u << 1]->mx >= k) {
            return queryIdx(u << 1, l, r, k);
        }
        if (r > mid) {
            return queryIdx(u << 1 | 1, l, r, k);
        }
        return 0;
    }

private:
    vector<Node*> tr;
    int m;

    void build(int u, int l, int r) {
        tr[u]->l = l;
        tr[u]->r = r;
        if (l == r) {
            tr[u]->s = m;
            tr[u]->mx = m;
            return;
        }
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }

    void pushup(int u) {
        tr[u]->s = tr[u << 1]->s + tr[u << 1 | 1]->s;
        tr[u]->mx = max(tr[u << 1]->mx, tr[u << 1 | 1]->mx);
    }
};

class BookMyShow {
public:
    BookMyShow(int n, int m) {
        this->n = n;
        this->m = m;
        tree = new SegmentTree(n, m);
    }

    vector<int> gather(int k, int maxRow) {
        ++maxRow;
        int i = tree->queryIdx(1, 1, maxRow, k);
        if (i == 0) {
            return {};
        }
        long s = tree->querySum(1, i, i);
        tree->modify(1, i, s - k);
        return {i - 1, (int) (m - s)};
    }

    bool scatter(int k, int maxRow) {
        ++maxRow;
        if (tree->querySum(1, 1, maxRow) < k) {
            return false;
        }
        int i = tree->queryIdx(1, 1, maxRow, 1);
        for (int j = i; j <= n; ++j) {
            long s = tree->querySum(1, j, j);
            if (s >= k) {
                tree->modify(1, j, s - k);
                return true;
            }
            k -= s;
            tree->modify(1, j, 0);
        }
        return true;
    }

private:
    SegmentTree* tree;
    int m, n;
};

/**
 * Your BookMyShow object will be instantiated and called as such:
 * BookMyShow* obj = new BookMyShow(n, m);
 * vector<int> param_1 = obj->gather(k,maxRow);
 * bool param_2 = obj->scatter(k,maxRow);
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type BookMyShow struct {
	n, m int
	tree *segmentTree
}

func Constructor(n int, m int) BookMyShow {
	return BookMyShow{n, m, newSegmentTree(n, m)}
}

func (this *BookMyShow) Gather(k int, maxRow int) []int {
	maxRow++
	i := this.tree.queryIdx(1, 1, maxRow, k)
	if i == 0 {
		return []int{}
	}
	s := this.tree.querySum(1, i, i)
	this.tree.modify(1, i, s-k)
	return []int{i - 1, this.m - s}
}

func (this *BookMyShow) Scatter(k int, maxRow int) bool {
	maxRow++
	if this.tree.querySum(1, 1, maxRow) < k {
		return false
	}
	i := this.tree.queryIdx(1, 1, maxRow, 1)
	for j := i; j <= this.n; j++ {
		s := this.tree.querySum(1, j, j)
		if s >= k {
			this.tree.modify(1, j, s-k)
			return true
		}
		k -= s
		this.tree.modify(1, j, 0)
	}
	return true
}

type node struct {
	l, r, s, mx int
}

type segmentTree struct {
	tr []*node
	m  int
}

func newSegmentTree(n, m int) *segmentTree {
	tr := make([]*node, n<<2)
	for i := range tr {
		tr[i] = &node{}
	}
	t := &segmentTree{tr, m}
	t.build(1, 1, n)
	return t
}

func (t *segmentTree) build(u, l, r int) {
	t.tr[u].l, t.tr[u].r = l, r
	if l == r {
		t.tr[u].s, t.tr[u].mx = t.m, t.m
		return
	}
	mid := (l + r) >> 1
	t.build(u<<1, l, mid)
	t.build(u<<1|1, mid+1, r)
	t.pushup(u)
}

func (t *segmentTree) modify(u, x, v int) {
	if t.tr[u].l == x && t.tr[u].r == x {
		t.tr[u].s, t.tr[u].mx = v, v
		return
	}
	mid := (t.tr[u].l + t.tr[u].r) >> 1
	if x <= mid {
		t.modify(u<<1, x, v)
	} else {
		t.modify(u<<1|1, x, v)
	}
	t.pushup(u)
}

func (t *segmentTree) querySum(u, l, r int) int {
	if t.tr[u].l >= l && t.tr[u].r <= r {
		return t.tr[u].s
	}
	mid := (t.tr[u].l + t.tr[u].r) >> 1
	v := 0
	if l <= mid {
		v = t.querySum(u<<1, l, r)
	}
	if r > mid {
		v += t.querySum(u<<1|1, l, r)
	}
	return v
}

func (t *segmentTree) queryIdx(u, l, r, k int) int {
	if t.tr[u].mx < k {
		return 0
	}
	if t.tr[u].l == t.tr[u].r {
		return t.tr[u].l
	}
	mid := (t.tr[u].l + t.tr[u].r) >> 1
	if t.tr[u<<1].mx >= k {
		return t.queryIdx(u<<1, l, r, k)
	}
	if r > mid {
		return t.queryIdx(u<<1|1, l, r, k)
	}
	return 0
}

func (t *segmentTree) pushup(u int) {
	t.tr[u].s = t.tr[u<<1].s + t.tr[u<<1|1].s
	t.tr[u].mx = max(t.tr[u<<1].mx, t.tr[u<<1|1].mx)
}

/**
 * Your BookMyShow object will be instantiated and called as such:
 * obj := Constructor(n, m);
 * param_1 := obj.Gather(k,maxRow);
 * param_2 := obj.Scatter(k,maxRow);
 */
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class Node {
    l: number;
    r: number;
    mx: number;
    s: number;

    constructor() {
        this.l = 0;
        this.r = 0;
        this.mx = 0;
        this.s = 0;
    }
}

class SegmentTree {
    private tr: Node[];
    private m: number;

    constructor(n: number, m: number) {
        this.m = m;
        this.tr = Array.from({ length: n << 2 }, () => new Node());
        this.build(1, 1, n);
    }

    private build(u: number, l: number, r: number): void {
        this.tr[u].l = l;
        this.tr[u].r = r;
        if (l === r) {
            this.tr[u].s = this.m;
            this.tr[u].mx = this.m;
            return;
        }
        const mid = (l + r) >> 1;
        this.build(u << 1, l, mid);
        this.build((u << 1) | 1, mid + 1, r);
        this.pushup(u);
    }

    public modify(u: number, x: number, v: number): void {
        if (this.tr[u].l === x && this.tr[u].r === x) {
            this.tr[u].s = v;
            this.tr[u].mx = v;
            return;
        }
        const mid = (this.tr[u].l + this.tr[u].r) >> 1;
        if (x <= mid) {
            this.modify(u << 1, x, v);
        } else {
            this.modify((u << 1) | 1, x, v);
        }
        this.pushup(u);
    }

    public querySum(u: number, l: number, r: number): number {
        if (this.tr[u].l >= l && this.tr[u].r <= r) {
            return this.tr[u].s;
        }
        const mid = (this.tr[u].l + this.tr[u].r) >> 1;
        let v = 0;
        if (l <= mid) {
            v += this.querySum(u << 1, l, r);
        }
        if (r > mid) {
            v += this.querySum((u << 1) | 1, l, r);
        }
        return v;
    }

    public queryIdx(u: number, l: number, r: number, k: number): number {
        if (this.tr[u].mx < k) {
            return 0;
        }
        if (this.tr[u].l === this.tr[u].r) {
            return this.tr[u].l;
        }
        const mid = (this.tr[u].l + this.tr[u].r) >> 1;
        if (this.tr[u << 1].mx >= k) {
            return this.queryIdx(u << 1, l, r, k);
        }
        if (r > mid) {
            return this.queryIdx((u << 1) | 1, l, r, k);
        }
        return 0;
    }

    private pushup(u: number): void {
        this.tr[u].s = this.tr[u << 1].s + this.tr[(u << 1) | 1].s;
        this.tr[u].mx = Math.max(this.tr[u << 1].mx, this.tr[(u << 1) | 1].mx);
    }
}

class BookMyShow {
    private n: number;
    private m: number;
    private tree: SegmentTree;

    constructor(n: number, m: number) {
        this.n = n;
        this.m = m;
        this.tree = new SegmentTree(n, m);
    }

    public gather(k: number, maxRow: number): number[] {
        ++maxRow;
        const i = this.tree.queryIdx(1, 1, maxRow, k);
        if (i === 0) {
            return [];
        }
        const s = this.tree.querySum(1, i, i);
        this.tree.modify(1, i, s - k);
        return [i - 1, this.m - s];
    }

    public scatter(k: number, maxRow: number): boolean {
        ++maxRow;
        if (this.tree.querySum(1, 1, maxRow) < k) {
            return false;
        }
        let i = this.tree.queryIdx(1, 1, maxRow, 1);
        for (let j = i; j <= this.n; ++j) {
            const s = this.tree.querySum(1, j, j);
            if (s >= k) {
                this.tree.modify(1, j, s - k);
                return true;
            }
            k -= s;
            this.tree.modify(1, j, 0);
        }
        return true;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>一个音乐会总共有&nbsp;<code>n</code>&nbsp;排座位，编号从&nbsp;<code>0</code>&nbsp;到&nbsp;<code>n - 1</code>&nbsp;，每一排有&nbsp;<code>m</code>&nbsp;个座椅，编号为&nbsp;<code>0</code>&nbsp;到&nbsp;<code>m - 1</code>&nbsp;。你需要设计一个买票系统，针对以下情况进行座位安排：</p>

<ul>
	<li>同一组的 <code>k</code>&nbsp;位观众坐在<strong> 同一排座位，且座位连续 </strong>。</li>
	<li><code>k</code>&nbsp;位观众中 <strong>每一位</strong>&nbsp;都有座位坐，但他们 <strong>不一定</strong>&nbsp;坐在一起。</li>
</ul>

<p>由于观众非常挑剔，所以：</p>

<ul>
	<li>只有当一个组里所有成员座位的排数都 <strong>小于等于</strong>&nbsp;<code>maxRow</code>&nbsp;，这个组才能订座位。每一组的&nbsp;<code>maxRow</code>&nbsp;可能 <strong>不同</strong>&nbsp;。</li>
	<li>如果有多排座位可以选择，优先选择 <strong>最小</strong>&nbsp;的排数。如果同一排中有多个座位可以坐，优先选择号码 <strong>最小</strong>&nbsp;的。</li>
</ul>

<p>请你实现&nbsp;<code>BookMyShow</code>&nbsp;类：</p>

<ul>
	<li><code>BookMyShow(int n, int m)</code>&nbsp;，初始化对象，<code>n</code>&nbsp;是排数，<code>m</code>&nbsp;是每一排的座位数。</li>
	<li><code>int[] gather(int k, int maxRow)</code>&nbsp;返回长度为 <code>2</code>&nbsp;的数组，表示 <code>k</code>&nbsp;个成员中 <strong>第一个座位</strong>&nbsp;的排数和座位编号，这 <code>k</code>&nbsp;位成员必须坐在 <strong>同一排座位，且座位连续 </strong>。换言之，返回最小可能的&nbsp;<code>r</code> 和&nbsp;<code>c</code>&nbsp;满足第&nbsp;<code>r</code>&nbsp;排中&nbsp;<code>[c, c + k - 1]</code>&nbsp;的座位都是空的，且&nbsp;<code>r &lt;= maxRow</code>&nbsp;。如果&nbsp;<strong>无法</strong>&nbsp;安排座位，返回&nbsp;<code>[]</code>&nbsp;。</li>
	<li><code>boolean scatter(int k, int maxRow)</code>&nbsp;如果组里所有&nbsp;<code>k</code>&nbsp;个成员&nbsp;<strong>不一定</strong>&nbsp;要坐在一起的前提下，都能在第&nbsp;<code>0</code> 排到第&nbsp;<code>maxRow</code>&nbsp;排之间找到座位，那么请返回&nbsp;<code>true</code>&nbsp;。这种情况下，每个成员都优先找排数&nbsp;<strong>最小</strong>&nbsp;，然后是座位编号最小的座位。如果不能安排所有&nbsp;<code>k</code>&nbsp;个成员的座位，请返回&nbsp;<code>false</code>&nbsp;。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
["BookMyShow", "gather", "gather", "scatter", "scatter"]
[[2, 5], [4, 0], [2, 0], [5, 1], [5, 1]]
<strong>输出：</strong>
[null, [0, 0], [], true, false]

<strong>解释：</strong>
BookMyShow bms = new BookMyShow(2, 5); // 总共有 2 排，每排 5 个座位。
bms.gather(4, 0); // 返回 [0, 0]
                  // 这一组安排第 0 排 [0, 3] 的座位。
bms.gather(2, 0); // 返回 []
                  // 第 0 排只剩下 1 个座位。
                  // 所以无法安排 2 个连续座位。
bms.scatter(5, 1); // 返回 True
                   // 这一组安排第 0 排第 4 个座位和第 1 排 [0, 3] 的座位。
bms.scatter(5, 1); // 返回 False
                   // 总共只剩下 1 个座位。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= m, k &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= maxRow &lt;= n - 1</code></li>
	<li><code>gather</code> 和&nbsp;<code>scatter</code>&nbsp;<strong>总</strong> 调用次数不超过&nbsp;<code>5 * 10<sup>4</sup></code> 次。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：线段树

分析题意我们得知：

-   对于 `gather(k, maxRow)` 操作，要求 $k$ 个人坐在同一行并且座位连续，也就是说，我们要找到最小的行，满足该行的剩余座位大于等于 $k$。
-   对于 `scatter(k, maxRow)` 操作，只需要找到 $k$ 个座位就行，但是要求这 $k$ 个座位的行数尽可能小，因此，我们要找到第一个满足剩余座位数大于 $0$ 的行，进行座位分配，然后继续往后查找。

我们可以用线段树来实现。线段树每个节点的信息有：

-   `l`：节点对应的区间左端点
-   `r`：节点对应的区间右端点
-   `s`：节点对应的区间总的剩余座位数
-   `mx`：节点对应的区间最大剩余座位数

注意，线段树节点区间的下标从 $1$ 开始。

线段树的操作有：

-   `build(u, l, r)`：建立节点 $u$，对应区间 $[l, r]$，并递归建立其左右子节点。
-   `modify(u, x, v)`：从节点 $u$ 开始，找到对应区间 $[l, r]$ 中的第一个满足 $l = r = x$ 的节点，将该节点的 `s` 和 `mx` 修改为 $v$，并向上更新。
-   `query_sum(u, l, r)`：从节点 $u$ 开始，统计对应区间 $[l, r]$ 中的 `s` 之和。
-   `query_idx(u, l, r, k)`：从节点 $u$ 开始，找到对应区间 $[l, r]$ 中的第一个满足 `mx` 大于等于 $k$ 的节点，返回该节点的 `l`。查找时，我们从最大的区间 $[1, maxRow]$ 开始，由于我们要找最左边的满足 `mx` 大于等于 $k$ 的节点。因此，对于当前区间，我们判断前半部分区间的 `mx` 是否符合要求，是则说明答案就在前半部分区间，递归查找即可。否则说明答案在后半部分区间，递归查找后半部分区间。
-   `pushup(u)`：利用 $u$ 的子节点信息更新当前 $u$ 的信息。

对于 `gather(k, maxRow)` 操作，我们先用 `query_idx(1, 1, n, k)` 找到第一个满足剩余座位数大于等于 $k$ 的行，记为 $i$。然后我们用 `query_sum(1, i, i)` 得到该行的剩余座位数，记为 $s$。接下来，我们用 `modify(1, i, s - k)` 将该行的剩余座位数修改为 $s - k$，并向上更新。最后，我们返回 $[i - 1, m - s]$ 即可。

对于 `scatter(k, maxRow)` 操作，我们先用 `query_sum(1, 1, maxRow)` 统计前 $maxRow$ 行的剩余座位数，记为 $s$。如果 $s \lt k$，说明没有足够的座位，返回 `false`；否则，我们用 `query_idx(1, 1, maxRow, 1)` 找到第一个满足剩余座位数大于等于 $1$ 的行，记为 $i$。从该行开始，每次用 `query_sum(1, i, i)` 得到该行的剩余座位数，记为 $s_i$。如果 $s_i \geq k$，我们直接用 `modify(1, i, s_i - k)` 将该行的剩余座位数修改为 $s_i - k$，并向上更新，然后返回 `true`。否则，我们更新 $k = k - s_i$，然后将该行的剩余座位数修改为 $0$，并向上更新。最后，我们返回 `true`。

时间复杂度：

-   初始化的时间复杂度为 $O(n)$。
-   `gather(k, maxRow)` 的时间复杂度为 $O(\log n)$。
-   `scatter(k, maxRow)` 的时间复杂度为 $O((n + q) \times \log n)$。

整体时间复杂度为 $O(n + q \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 和 $q$ 分别为行数和操作数。

<!-- tabs:start -->

#### Python3

```python
class Node:
    __slots__ = "l", "r", "s", "mx"

    def __init__(self):
        self.l = self.r = 0
        self.s = self.mx = 0


class SegmentTree:
    def __init__(self, n, m):
        self.m = m
        self.tr = [Node() for _ in range(n << 2)]
        self.build(1, 1, n)

    def build(self, u, l, r):
        self.tr[u].l, self.tr[u].r = l, r
        if l == r:
            self.tr[u].s = self.tr[u].mx = self.m
            return
        mid = (l + r) >> 1
        self.build(u << 1, l, mid)
        self.build(u << 1 | 1, mid + 1, r)
        self.pushup(u)

    def modify(self, u, x, v):
        if self.tr[u].l == x and self.tr[u].r == x:
            self.tr[u].s = self.tr[u].mx = v
            return
        mid = (self.tr[u].l + self.tr[u].r) >> 1
        if x <= mid:
            self.modify(u << 1, x, v)
        else:
            self.modify(u << 1 | 1, x, v)
        self.pushup(u)

    def query_sum(self, u, l, r):
        if self.tr[u].l >= l and self.tr[u].r <= r:
            return self.tr[u].s
        mid = (self.tr[u].l + self.tr[u].r) >> 1
        v = 0
        if l <= mid:
            v += self.query_sum(u << 1, l, r)
        if r > mid:
            v += self.query_sum(u << 1 | 1, l, r)
        return v

    def query_idx(self, u, l, r, k):
        if self.tr[u].mx < k:
            return 0
        if self.tr[u].l == self.tr[u].r:
            return self.tr[u].l
        mid = (self.tr[u].l + self.tr[u].r) >> 1
        if self.tr[u << 1].mx >= k:
            return self.query_idx(u << 1, l, r, k)
        if r > mid:
            return self.query_idx(u << 1 | 1, l, r, k)
        return 0

    def pushup(self, u):
        self.tr[u].s = self.tr[u << 1].s + self.tr[u << 1 | 1].s
        self.tr[u].mx = max(self.tr[u << 1].mx, self.tr[u << 1 | 1].mx)


class BookMyShow:
    def __init__(self, n: int, m: int):
        self.n = n
        self.tree = SegmentTree(n, m)

    def gather(self, k: int, maxRow: int) -> List[int]:
        maxRow += 1
        i = self.tree.query_idx(1, 1, maxRow, k)
        if i == 0:
            return []
        s = self.tree.query_sum(1, i, i)
        self.tree.modify(1, i, s - k)
        return [i - 1, self.tree.m - s]

    def scatter(self, k: int, maxRow: int) -> bool:
        maxRow += 1
        if self.tree.query_sum(1, 1, maxRow) < k:
            return False
        i = self.tree.query_idx(1, 1, maxRow, 1)
        for j in range(i, self.n + 1):
            s = self.tree.query_sum(1, j, j)
            if s >= k:
                self.tree.modify(1, j, s - k)
                return True
            k -= s
            self.tree.modify(1, j, 0)
        return True


# Your BookMyShow object will be instantiated and called as such:
# obj = BookMyShow(n, m)
# param_1 = obj.gather(k,maxRow)
# param_2 = obj.scatter(k,maxRow)
```

#### Java

```java
class Node {
    int l, r;
    long mx, s;
}

class SegmentTree {
    private Node[] tr;
    private int m;

    public SegmentTree(int n, int m) {
        this.m = m;
        tr = new Node[n << 2];
        for (int i = 0; i < tr.length; ++i) {
            tr[i] = new Node();
        }
        build(1, 1, n);
    }

    private void build(int u, int l, int r) {
        tr[u].l = l;
        tr[u].r = r;
        if (l == r) {
            tr[u].s = m;
            tr[u].mx = m;
            return;
        }
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }

    public void modify(int u, int x, long v) {
        if (tr[u].l == x && tr[u].r == x) {
            tr[u].s = v;
            tr[u].mx = v;
            return;
        }
        int mid = (tr[u].l + tr[u].r) >> 1;
        if (x <= mid) {
            modify(u << 1, x, v);
        } else {
            modify(u << 1 | 1, x, v);
        }
        pushup(u);
    }

    public long querySum(int u, int l, int r) {
        if (tr[u].l >= l && tr[u].r <= r) {
            return tr[u].s;
        }
        int mid = (tr[u].l + tr[u].r) >> 1;
        long v = 0;
        if (l <= mid) {
            v += querySum(u << 1, l, r);
        }
        if (r > mid) {
            v += querySum(u << 1 | 1, l, r);
        }
        return v;
    }

    public int queryIdx(int u, int l, int r, int k) {
        if (tr[u].mx < k) {
            return 0;
        }
        if (tr[u].l == tr[u].r) {
            return tr[u].l;
        }
        int mid = (tr[u].l + tr[u].r) >> 1;
        if (tr[u << 1].mx >= k) {
            return queryIdx(u << 1, l, r, k);
        }
        if (r > mid) {
            return queryIdx(u << 1 | 1, l, r, k);
        }
        return 0;
    }

    private void pushup(int u) {
        tr[u].s = tr[u << 1].s + tr[u << 1 | 1].s;
        tr[u].mx = Math.max(tr[u << 1].mx, tr[u << 1 | 1].mx);
    }
}

class BookMyShow {
    private int n;
    private int m;
    private SegmentTree tree;

    public BookMyShow(int n, int m) {
        this.n = n;
        this.m = m;
        tree = new SegmentTree(n, m);
    }

    public int[] gather(int k, int maxRow) {
        ++maxRow;
        int i = tree.queryIdx(1, 1, maxRow, k);
        if (i == 0) {
            return new int[] {};
        }
        long s = tree.querySum(1, i, i);
        tree.modify(1, i, s - k);
        return new int[] {i - 1, (int) (m - s)};
    }

    public boolean scatter(int k, int maxRow) {
        ++maxRow;
        if (tree.querySum(1, 1, maxRow) < k) {
            return false;
        }
        int i = tree.queryIdx(1, 1, maxRow, 1);
        for (int j = i; j <= n; ++j) {
            long s = tree.querySum(1, j, j);
            if (s >= k) {
                tree.modify(1, j, s - k);
                return true;
            }
            k -= s;
            tree.modify(1, j, 0);
        }
        return true;
    }
}

/**
 * Your BookMyShow object will be instantiated and called as such:
 * BookMyShow obj = new BookMyShow(n, m);
 * int[] param_1 = obj.gather(k,maxRow);
 * boolean param_2 = obj.scatter(k,maxRow);
 */
```

#### C++

```cpp
class Node {
public:
    int l, r;
    long s, mx;
};

class SegmentTree {
public:
    SegmentTree(int n, int m) {
        this->m = m;
        tr.resize(n << 2);
        for (int i = 0; i < n << 2; ++i) {
            tr[i] = new Node();
        }
        build(1, 1, n);
    }

    void modify(int u, int x, int v) {
        if (tr[u]->l == x && tr[u]->r == x) {
            tr[u]->s = tr[u]->mx = v;
            return;
        }
        int mid = (tr[u]->l + tr[u]->r) >> 1;
        if (x <= mid) {
            modify(u << 1, x, v);
        } else {
            modify(u << 1 | 1, x, v);
        }
        pushup(u);
    }

    long querySum(int u, int l, int r) {
        if (tr[u]->l >= l && tr[u]->r <= r) {
            return tr[u]->s;
        }
        int mid = (tr[u]->l + tr[u]->r) >> 1;
        long v = 0;
        if (l <= mid) {
            v += querySum(u << 1, l, r);
        }
        if (r > mid) {
            v += querySum(u << 1 | 1, l, r);
        }
        return v;
    }

    int queryIdx(int u, int l, int r, int k) {
        if (tr[u]->mx < k) {
            return 0;
        }
        if (tr[u]->l == tr[u]->r) {
            return tr[u]->l;
        }
        int mid = (tr[u]->l + tr[u]->r) >> 1;
        if (tr[u << 1]->mx >= k) {
            return queryIdx(u << 1, l, r, k);
        }
        if (r > mid) {
            return queryIdx(u << 1 | 1, l, r, k);
        }
        return 0;
    }

private:
    vector<Node*> tr;
    int m;

    void build(int u, int l, int r) {
        tr[u]->l = l;
        tr[u]->r = r;
        if (l == r) {
            tr[u]->s = m;
            tr[u]->mx = m;
            return;
        }
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }

    void pushup(int u) {
        tr[u]->s = tr[u << 1]->s + tr[u << 1 | 1]->s;
        tr[u]->mx = max(tr[u << 1]->mx, tr[u << 1 | 1]->mx);
    }
};

class BookMyShow {
public:
    BookMyShow(int n, int m) {
        this->n = n;
        this->m = m;
        tree = new SegmentTree(n, m);
    }

    vector<int> gather(int k, int maxRow) {
        ++maxRow;
        int i = tree->queryIdx(1, 1, maxRow, k);
        if (i == 0) {
            return {};
        }
        long s = tree->querySum(1, i, i);
        tree->modify(1, i, s - k);
        return {i - 1, (int) (m - s)};
    }

    bool scatter(int k, int maxRow) {
        ++maxRow;
        if (tree->querySum(1, 1, maxRow) < k) {
            return false;
        }
        int i = tree->queryIdx(1, 1, maxRow, 1);
        for (int j = i; j <= n; ++j) {
            long s = tree->querySum(1, j, j);
            if (s >= k) {
                tree->modify(1, j, s - k);
                return true;
            }
            k -= s;
            tree->modify(1, j, 0);
        }
        return true;
    }

private:
    SegmentTree* tree;
    int m, n;
};

/**
 * Your BookMyShow object will be instantiated and called as such:
 * BookMyShow* obj = new BookMyShow(n, m);
 * vector<int> param_1 = obj->gather(k,maxRow);
 * bool param_2 = obj->scatter(k,maxRow);
 */
```

#### Go

```go
type BookMyShow struct {
	n, m int
	tree *segmentTree
}

func Constructor(n int, m int) BookMyShow {
	return BookMyShow{n, m, newSegmentTree(n, m)}
}

func (this *BookMyShow) Gather(k int, maxRow int) []int {
	maxRow++
	i := this.tree.queryIdx(1, 1, maxRow, k)
	if i == 0 {
		return []int{}
	}
	s := this.tree.querySum(1, i, i)
	this.tree.modify(1, i, s-k)
	return []int{i - 1, this.m - s}
}

func (this *BookMyShow) Scatter(k int, maxRow int) bool {
	maxRow++
	if this.tree.querySum(1, 1, maxRow) < k {
		return false
	}
	i := this.tree.queryIdx(1, 1, maxRow, 1)
	for j := i; j <= this.n; j++ {
		s := this.tree.querySum(1, j, j)
		if s >= k {
			this.tree.modify(1, j, s-k)
			return true
		}
		k -= s
		this.tree.modify(1, j, 0)
	}
	return true
}

type node struct {
	l, r, s, mx int
}

type segmentTree struct {
	tr []*node
	m  int
}

func newSegmentTree(n, m int) *segmentTree {
	tr := make([]*node, n<<2)
	for i := range tr {
		tr[i] = &node{}
	}
	t := &segmentTree{tr, m}
	t.build(1, 1, n)
	return t
}

func (t *segmentTree) build(u, l, r int) {
	t.tr[u].l, t.tr[u].r = l, r
	if l == r {
		t.tr[u].s, t.tr[u].mx = t.m, t.m
		return
	}
	mid := (l + r) >> 1
	t.build(u<<1, l, mid)
	t.build(u<<1|1, mid+1, r)
	t.pushup(u)
}

func (t *segmentTree) modify(u, x, v int) {
	if t.tr[u].l == x && t.tr[u].r == x {
		t.tr[u].s, t.tr[u].mx = v, v
		return
	}
	mid := (t.tr[u].l + t.tr[u].r) >> 1
	if x <= mid {
		t.modify(u<<1, x, v)
	} else {
		t.modify(u<<1|1, x, v)
	}
	t.pushup(u)
}

func (t *segmentTree) querySum(u, l, r int) int {
	if t.tr[u].l >= l && t.tr[u].r <= r {
		return t.tr[u].s
	}
	mid := (t.tr[u].l + t.tr[u].r) >> 1
	v := 0
	if l <= mid {
		v = t.querySum(u<<1, l, r)
	}
	if r > mid {
		v += t.querySum(u<<1|1, l, r)
	}
	return v
}

func (t *segmentTree) queryIdx(u, l, r, k int) int {
	if t.tr[u].mx < k {
		return 0
	}
	if t.tr[u].l == t.tr[u].r {
		return t.tr[u].l
	}
	mid := (t.tr[u].l + t.tr[u].r) >> 1
	if t.tr[u<<1].mx >= k {
		return t.queryIdx(u<<1, l, r, k)
	}
	if r > mid {
		return t.queryIdx(u<<1|1, l, r, k)
	}
	return 0
}

func (t *segmentTree) pushup(u int) {
	t.tr[u].s = t.tr[u<<1].s + t.tr[u<<1|1].s
	t.tr[u].mx = max(t.tr[u<<1].mx, t.tr[u<<1|1].mx)
}

/**
 * Your BookMyShow object will be instantiated and called as such:
 * obj := Constructor(n, m);
 * param_1 := obj.Gather(k,maxRow);
 * param_2 := obj.Scatter(k,maxRow);
 */
```

#### TypeScript

```ts
class Node {
    l: number;
    r: number;
    mx: number;
    s: number;

    constructor() {
        this.l = 0;
        this.r = 0;
        this.mx = 0;
        this.s = 0;
    }
}

class SegmentTree {
    private tr: Node[];
    private m: number;

    constructor(n: number, m: number) {
        this.m = m;
        this.tr = Array.from({ length: n << 2 }, () => new Node());
        this.build(1, 1, n);
    }

    private build(u: number, l: number, r: number): void {
        this.tr[u].l = l;
        this.tr[u].r = r;
        if (l === r) {
            this.tr[u].s = this.m;
            this.tr[u].mx = this.m;
            return;
        }
        const mid = (l + r) >> 1;
        this.build(u << 1, l, mid);
        this.build((u << 1) | 1, mid + 1, r);
        this.pushup(u);
    }

    public modify(u: number, x: number, v: number): void {
        if (this.tr[u].l === x && this.tr[u].r === x) {
            this.tr[u].s = v;
            this.tr[u].mx = v;
            return;
        }
        const mid = (this.tr[u].l + this.tr[u].r) >> 1;
        if (x <= mid) {
            this.modify(u << 1, x, v);
        } else {
            this.modify((u << 1) | 1, x, v);
        }
        this.pushup(u);
    }

    public querySum(u: number, l: number, r: number): number {
        if (this.tr[u].l >= l && this.tr[u].r <= r) {
            return this.tr[u].s;
        }
        const mid = (this.tr[u].l + this.tr[u].r) >> 1;
        let v = 0;
        if (l <= mid) {
            v += this.querySum(u << 1, l, r);
        }
        if (r > mid) {
            v += this.querySum((u << 1) | 1, l, r);
        }
        return v;
    }

    public queryIdx(u: number, l: number, r: number, k: number): number {
        if (this.tr[u].mx < k) {
            return 0;
        }
        if (this.tr[u].l === this.tr[u].r) {
            return this.tr[u].l;
        }
        const mid = (this.tr[u].l + this.tr[u].r) >> 1;
        if (this.tr[u << 1].mx >= k) {
            return this.queryIdx(u << 1, l, r, k);
        }
        if (r > mid) {
            return this.queryIdx((u << 1) | 1, l, r, k);
        }
        return 0;
    }

    private pushup(u: number): void {
        this.tr[u].s = this.tr[u << 1].s + this.tr[(u << 1) | 1].s;
        this.tr[u].mx = Math.max(this.tr[u << 1].mx, this.tr[(u << 1) | 1].mx);
    }
}

class BookMyShow {
    private n: number;
    private m: number;
    private tree: SegmentTree;

    constructor(n: number, m: number) {
        this.n = n;
        this.m = m;
        this.tree = new SegmentTree(n, m);
    }

    public gather(k: number, maxRow: number): number[] {
        ++maxRow;
        const i = this.tree.queryIdx(1, 1, maxRow, k);
        if (i === 0) {
            return [];
        }
        const s = this.tree.querySum(1, i, i);
        this.tree.modify(1, i, s - k);
        return [i - 1, this.m - s];
    }

    public scatter(k: number, maxRow: number): boolean {
        ++maxRow;
        if (this.tree.querySum(1, 1, maxRow) < k) {
            return false;
        }
        let i = this.tree.queryIdx(1, 1, maxRow, 1);
        for (let j = i; j <= this.n; ++j) {
            const s = this.tree.querySum(1, j, j);
            if (s >= k) {
                this.tree.modify(1, j, s - k);
                return true;
            }
            k -= s;
            this.tree.modify(1, j, 0);
        }
        return true;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2287. 重排字符形成目标字符串](https://leetcode.cn/problems/rearrange-characters-to-make-target-string){#2287}

{{< tabs "2287" >}}

{{% tab "python" %}}
```python
class Solution:
    def rearrangeCharacters(self, s: str, target: str) -> int:
        cnt1 = Counter(s)
        cnt2 = Counter(target)
        return min(cnt1[c] // v for c, v in cnt2.items())
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int rearrangeCharacters(String s, String target) {
        int[] cnt1 = new int[26];
        int[] cnt2 = new int[26];
        for (int i = 0; i < s.length(); ++i) {
            ++cnt1[s.charAt(i) - 'a'];
        }
        for (int i = 0; i < target.length(); ++i) {
            ++cnt2[target.charAt(i) - 'a'];
        }
        int ans = 100;
        for (int i = 0; i < 26; ++i) {
            if (cnt2[i] > 0) {
                ans = Math.min(ans, cnt1[i] / cnt2[i]);
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
    int rearrangeCharacters(string s, string target) {
        int cnt1[26]{};
        int cnt2[26]{};
        for (char& c : s) {
            ++cnt1[c - 'a'];
        }
        for (char& c : target) {
            ++cnt2[c - 'a'];
        }
        int ans = 100;
        for (int i = 0; i < 26; ++i) {
            if (cnt2[i]) {
                ans = min(ans, cnt1[i] / cnt2[i]);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func rearrangeCharacters(s string, target string) int {
	var cnt1, cnt2 [26]int
	for _, c := range s {
		cnt1[c-'a']++
	}
	for _, c := range target {
		cnt2[c-'a']++
	}
	ans := 100
	for i, v := range cnt2 {
		if v > 0 {
			ans = min(ans, cnt1[i]/v)
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function rearrangeCharacters(s: string, target: string): number {
    const idx = (s: string) => s.charCodeAt(0) - 97;
    const cnt1 = new Array(26).fill(0);
    const cnt2 = new Array(26).fill(0);
    for (const c of s) {
        ++cnt1[idx(c)];
    }
    for (const c of target) {
        ++cnt2[idx(c)];
    }
    let ans = 100;
    for (let i = 0; i < 26; ++i) {
        if (cnt2[i]) {
            ans = Math.min(ans, Math.floor(cnt1[i] / cnt2[i]));
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn rearrange_characters(s: String, target: String) -> i32 {
        let mut count1 = [0; 26];
        let mut count2 = [0; 26];
        for c in s.as_bytes() {
            count1[(c - b'a') as usize] += 1;
        }
        for c in target.as_bytes() {
            count2[(c - b'a') as usize] += 1;
        }
        let mut ans = i32::MAX;
        for i in 0..26 {
            if count2[i] != 0 {
                ans = ans.min(count1[i] / count2[i]);
            }
        }
        ans
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
#define min(a, b) (((a) < (b)) ? (a) : (b))

int rearrangeCharacters(char* s, char* target) {
    int count1[26] = {0};
    int count2[26] = {0};
    for (int i = 0; s[i]; i++) {
        count1[s[i] - 'a']++;
    }
    for (int i = 0; target[i]; i++) {
        count2[target[i] - 'a']++;
    }
    int ans = INT_MAX;
    for (int i = 0; i < 26; i++) {
        if (count2[i]) {
            ans = min(ans, count1[i] / count2[i]);
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

<p>给你两个下标从 <strong>0</strong> 开始的字符串 <code>s</code> 和 <code>target</code> 。你可以从 <code>s</code> 取出一些字符并将其重排，得到若干新的字符串。</p>

<p>从 <code>s</code> 中取出字符并重新排列，返回可以形成 <code>target</code> 的 <strong>最大</strong> 副本数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "ilovecodingonleetcode", target = "code"
<strong>输出：</strong>2
<strong>解释：</strong>
对于 "code" 的第 1 个副本，选取下标为 4 、5 、6 和 7 的字符。
对于 "code" 的第 2 个副本，选取下标为 17 、18 、19 和 20 的字符。
形成的字符串分别是 "ecod" 和 "code" ，都可以重排为 "code" 。
可以形成最多 2 个 "code" 的副本，所以返回 2 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "abcba", target = "abc"
<strong>输出：</strong>1
<strong>解释：</strong>
选取下标为 0 、1 和 2 的字符，可以形成 "abc" 的 1 个副本。 
可以形成最多 1 个 "abc" 的副本，所以返回 1 。
注意，尽管下标 3 和 4 分别有额外的 'a' 和 'b' ，但不能重用下标 2 处的 'c' ，所以无法形成 "abc" 的第 2 个副本。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "abbaccaddaeea", target = "aaaaa"
<strong>输出：</strong>1
<strong>解释：</strong>
选取下标为 0 、3 、6 、9 和 12 的字符，可以形成 "aaaaa" 的 1 个副本。
可以形成最多 1 个 "aaaaa" 的副本，所以返回 1 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>1 &lt;= target.length &lt;= 10</code></li>
	<li><code>s</code> 和 <code>target</code> 由小写英文字母组成</li>
</ul>

<p>&nbsp;</p>

<p><strong>注意：</strong>本题与&nbsp;<a href="https://leetcode.cn/problems/maximum-number-of-balloons/">1189. “气球” 的最大数量</a> 相同。</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数

我们统计字符串 $\textit{s}$ 和 $\textit{target}$ 中每个字符出现的次数，记为 $\textit{cnt1}$ 和 $\textit{cnt2}$。对于 $\textit{target}$ 中的每个字符，我们计算 $\textit{cnt1}$ 中该字符出现的次数除以 $\textit{cnt2}$ 中该字符出现的次数，取最小值即可。

时间复杂度 $O(n + m)$，空间复杂度 $O(|\Sigma|)$。其中 $n$ 和 $m$ 分别是字符串 $\textit{s}$ 和 $\textit{target}$ 的长度。而 $|\Sigma|$ 是字符集的大小，本题中 $|\Sigma|=26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def rearrangeCharacters(self, s: str, target: str) -> int:
        cnt1 = Counter(s)
        cnt2 = Counter(target)
        return min(cnt1[c] // v for c, v in cnt2.items())
```

#### Java

```java
class Solution {
    public int rearrangeCharacters(String s, String target) {
        int[] cnt1 = new int[26];
        int[] cnt2 = new int[26];
        for (int i = 0; i < s.length(); ++i) {
            ++cnt1[s.charAt(i) - 'a'];
        }
        for (int i = 0; i < target.length(); ++i) {
            ++cnt2[target.charAt(i) - 'a'];
        }
        int ans = 100;
        for (int i = 0; i < 26; ++i) {
            if (cnt2[i] > 0) {
                ans = Math.min(ans, cnt1[i] / cnt2[i]);
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
    int rearrangeCharacters(string s, string target) {
        int cnt1[26]{};
        int cnt2[26]{};
        for (char& c : s) {
            ++cnt1[c - 'a'];
        }
        for (char& c : target) {
            ++cnt2[c - 'a'];
        }
        int ans = 100;
        for (int i = 0; i < 26; ++i) {
            if (cnt2[i]) {
                ans = min(ans, cnt1[i] / cnt2[i]);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func rearrangeCharacters(s string, target string) int {
	var cnt1, cnt2 [26]int
	for _, c := range s {
		cnt1[c-'a']++
	}
	for _, c := range target {
		cnt2[c-'a']++
	}
	ans := 100
	for i, v := range cnt2 {
		if v > 0 {
			ans = min(ans, cnt1[i]/v)
		}
	}
	return ans
}
```

#### TypeScript

```ts
function rearrangeCharacters(s: string, target: string): number {
    const idx = (s: string) => s.charCodeAt(0) - 97;
    const cnt1 = new Array(26).fill(0);
    const cnt2 = new Array(26).fill(0);
    for (const c of s) {
        ++cnt1[idx(c)];
    }
    for (const c of target) {
        ++cnt2[idx(c)];
    }
    let ans = 100;
    for (let i = 0; i < 26; ++i) {
        if (cnt2[i]) {
            ans = Math.min(ans, Math.floor(cnt1[i] / cnt2[i]));
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn rearrange_characters(s: String, target: String) -> i32 {
        let mut count1 = [0; 26];
        let mut count2 = [0; 26];
        for c in s.as_bytes() {
            count1[(c - b'a') as usize] += 1;
        }
        for c in target.as_bytes() {
            count2[(c - b'a') as usize] += 1;
        }
        let mut ans = i32::MAX;
        for i in 0..26 {
            if count2[i] != 0 {
                ans = ans.min(count1[i] / count2[i]);
            }
        }
        ans
    }
}
```

#### C

```c
#define min(a, b) (((a) < (b)) ? (a) : (b))

int rearrangeCharacters(char* s, char* target) {
    int count1[26] = {0};
    int count2[26] = {0};
    for (int i = 0; s[i]; i++) {
        count1[s[i] - 'a']++;
    }
    for (int i = 0; target[i]; i++) {
        count2[target[i] - 'a']++;
    }
    int ans = INT_MAX;
    for (int i = 0; i < 26; i++) {
        if (count2[i]) {
            ans = min(ans, count1[i] / count2[i]);
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

# [2288. 价格减免](https://leetcode.cn/problems/apply-discount-to-prices){#2288}

{{< tabs "2288" >}}

{{% tab "python" %}}
```python
class Solution:
    def discountPrices(self, sentence: str, discount: int) -> str:
        ans = []
        for w in sentence.split():
            if w[0] == '$' and w[1:].isdigit():
                w = f'${int(w[1:]) * (1 - discount / 100):.2f}'
            ans.append(w)
        return ' '.join(ans)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String discountPrices(String sentence, int discount) {
        String[] words = sentence.split(" ");
        for (int i = 0; i < words.length; ++i) {
            if (check(words[i])) {
                double t = Long.parseLong(words[i].substring(1)) * (1 - discount / 100.0);
                words[i] = String.format("$%.2f", t);
            }
        }
        return String.join(" ", words);
    }

    private boolean check(String s) {
        if (s.charAt(0) != '$' || s.length() == 1) {
            return false;
        }
        for (int i = 1; i < s.length(); ++i) {
            if (!Character.isDigit(s.charAt(i))) {
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
    string discountPrices(string sentence, int discount) {
        istringstream is(sentence);
        string w;
        string ans;
        auto check = [](string s) {
            if (s[0] != '$' || s.size() == 1) {
                return false;
            }
            for (int i = 1; i < s.size(); ++i) {
                if (!isdigit(s[i])) {
                    return false;
                }
            }
            return true;
        };
        while (is >> w) {
            if (check(w)) {
                long long v = stoll(w.substr(1)) * (100 - discount);
                char t[20];
                sprintf(t, "$%lld.%02lld", v / 100, v % 100);
                ans += t;
            } else {
                ans += w;
            }
            ans += ' ';
        }
        ans.pop_back();
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func discountPrices(sentence string, discount int) string {
	words := strings.Split(sentence, " ")
	for i, w := range words {
		if w[0] == '$' {
			if v, err := strconv.Atoi(w[1:]); err == nil {
				words[i] = fmt.Sprintf("$%.2f", float64(v*(100-discount))/100)
			}
		}
	}
	return strings.Join(words, " ")
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function discountPrices(sentence: string, discount: number): string {
    const sell = (100 - discount) / 100;
    const reg = new RegExp(/^(\$)(([1-9]\d*\.?\d*)|(0\.\d*))$/g);
    const words = sentence.split(' ').map(d => {
        if (!reg.test(d)) return d;
        return d.replace(reg, (s, $1, $2) => {
            return `$${(sell * $2).toFixed(2)}`;
        });
    });
    return words.join(' ');
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p><strong>句子</strong> 是由若干个单词组成的字符串，单词之间用单个空格分隔，其中每个单词可以包含数字、小写字母、和美元符号 <code>'$'</code> 。如果单词的形式为美元符号后跟着一个非负实数，那么这个单词就表示一个 <strong>价格</strong> 。</p>

<ul>
	<li>例如 <code>"$100"</code>、<code>"$23"</code> 和 <code>"$6"</code> 表示价格，而 <code>"100"</code>、<code>"$"</code> 和 <code>"$1e5</code> 不是。</li>
</ul>

<p>给你一个字符串 <code>sentence</code> 表示一个句子和一个整数 <code>discount</code> 。对于每个表示价格的单词，都在价格的基础上减免 <code>discount%</code> ，并 <strong>更新</strong> 该单词到句子中。所有更新后的价格应该表示为一个 <strong>恰好保留小数点后两位</strong> 的数字。</p>

<p>返回表示修改后句子的字符串。</p>

<p>注意：所有价格 <strong>最多</strong> 为&nbsp;<code>10</code> 位数字。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>sentence = "there are $1 $2 and 5$ candies in the shop", discount = 50
<strong>输出：</strong>"there are $0.50 $1.00 and 5$ candies in the shop"
<strong>解释：</strong>
表示价格的单词是 "$1" 和 "$2" 。 
- "$1" 减免 50% 为 "$0.50" ，所以 "$1" 替换为 "$0.50" 。
- "$2" 减免 50% 为 "$1" ，所以 "$2" 替换为 "$1.00" 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>sentence = "1 2 $3 4 $5 $6 7 8$ $9 $10$", discount = 100
<strong>输出：</strong>"1 2 $0.00 4 $0.00 $0.00 7 8$ $0.00 $10$"
<strong>解释：</strong>
任何价格减免 100% 都会得到 0 。
表示价格的单词分别是 "$3"、"$5"、"$6" 和 "$9"。
每个单词都替换为 "$0.00"。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= sentence.length &lt;= 10<sup>5</sup></code></li>
	<li><code>sentence</code> 由小写英文字母、数字、<code>' '</code> 和&nbsp;<code>'$'</code> 组成</li>
	<li><code>sentence</code> 不含前导和尾随空格</li>
	<li><code>sentence</code> 的所有单词都用单个空格分隔</li>
	<li>所有价格都是 <strong>正</strong> 整数且不含前导零</li>
	<li>所有价格 <strong>最多</strong> 为&nbsp; <code>10</code> 位数字</li>
	<li><code>0 &lt;= discount &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们可以将句子按空格分割成单词数组，然后遍历单词数组，对于每个单词，如果其表示价格，则将其更新为减免折扣后的价格。最后将更新后的单词数组拼接成以空格分隔的字符串即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为字符串 `sentence` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def discountPrices(self, sentence: str, discount: int) -> str:
        ans = []
        for w in sentence.split():
            if w[0] == '$' and w[1:].isdigit():
                w = f'${int(w[1:]) * (1 - discount / 100):.2f}'
            ans.append(w)
        return ' '.join(ans)
```

#### Java

```java
class Solution {
    public String discountPrices(String sentence, int discount) {
        String[] words = sentence.split(" ");
        for (int i = 0; i < words.length; ++i) {
            if (check(words[i])) {
                double t = Long.parseLong(words[i].substring(1)) * (1 - discount / 100.0);
                words[i] = String.format("$%.2f", t);
            }
        }
        return String.join(" ", words);
    }

    private boolean check(String s) {
        if (s.charAt(0) != '$' || s.length() == 1) {
            return false;
        }
        for (int i = 1; i < s.length(); ++i) {
            if (!Character.isDigit(s.charAt(i))) {
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
    string discountPrices(string sentence, int discount) {
        istringstream is(sentence);
        string w;
        string ans;
        auto check = [](string s) {
            if (s[0] != '$' || s.size() == 1) {
                return false;
            }
            for (int i = 1; i < s.size(); ++i) {
                if (!isdigit(s[i])) {
                    return false;
                }
            }
            return true;
        };
        while (is >> w) {
            if (check(w)) {
                long long v = stoll(w.substr(1)) * (100 - discount);
                char t[20];
                sprintf(t, "$%lld.%02lld", v / 100, v % 100);
                ans += t;
            } else {
                ans += w;
            }
            ans += ' ';
        }
        ans.pop_back();
        return ans;
    }
};
```

#### Go

```go
func discountPrices(sentence string, discount int) string {
	words := strings.Split(sentence, " ")
	for i, w := range words {
		if w[0] == '$' {
			if v, err := strconv.Atoi(w[1:]); err == nil {
				words[i] = fmt.Sprintf("$%.2f", float64(v*(100-discount))/100)
			}
		}
	}
	return strings.Join(words, " ")
}
```

#### TypeScript

```ts
function discountPrices(sentence: string, discount: number): string {
    const sell = (100 - discount) / 100;
    const reg = new RegExp(/^(\$)(([1-9]\d*\.?\d*)|(0\.\d*))$/g);
    const words = sentence.split(' ').map(d => {
        if (!reg.test(d)) return d;
        return d.replace(reg, (s, $1, $2) => {
            return `$${(sell * $2).toFixed(2)}`;
        });
    });
    return words.join(' ');
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2289. 使数组按非递减顺序排列](https://leetcode.cn/problems/steps-to-make-array-non-decreasing){#2289}

{{< tabs "2289" >}}

{{% tab "python" %}}
```python
class Solution:
    def totalSteps(self, nums: List[int]) -> int:
        stk = []
        ans, n = 0, len(nums)
        dp = [0] * n
        for i in range(n - 1, -1, -1):
            while stk and nums[i] > nums[stk[-1]]:
                dp[i] = max(dp[i] + 1, dp[stk.pop()])
            stk.append(i)
        return max(dp)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int totalSteps(int[] nums) {
        Deque<Integer> stk = new ArrayDeque<>();
        int ans = 0;
        int n = nums.length;
        int[] dp = new int[n];
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.isEmpty() && nums[i] > nums[stk.peek()]) {
                dp[i] = Math.max(dp[i] + 1, dp[stk.pop()]);
                ans = Math.max(ans, dp[i]);
            }
            stk.push(i);
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
    int totalSteps(vector<int>& nums) {
        stack<int> stk;
        int ans = 0, n = nums.size();
        vector<int> dp(n);
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.empty() && nums[i] > nums[stk.top()]) {
                dp[i] = max(dp[i] + 1, dp[stk.top()]);
                ans = max(ans, dp[i]);
                stk.pop();
            }
            stk.push(i);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func totalSteps(nums []int) int {
	stk := []int{}
	ans, n := 0, len(nums)
	dp := make([]int, n)
	for i := n - 1; i >= 0; i-- {
		for len(stk) > 0 && nums[i] > nums[stk[len(stk)-1]] {
			dp[i] = max(dp[i]+1, dp[stk[len(stk)-1]])
			stk = stk[:len(stk)-1]
			ans = max(ans, dp[i])
		}
		stk = append(stk, i)
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function totalSteps(nums: number[]): number {
    let ans = 0;
    let stack = [];
    for (let num of nums) {
        let max = 0;
        while (stack.length && stack[0][0] <= num) {
            max = Math.max(stack[0][1], max);
            stack.shift();
        }
        if (stack.length) max++;
        ans = Math.max(max, ans);
        stack.unshift([num, max]);
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

<p>给你一个下标从 <strong>0</strong> 开始的整数数组 <code>nums</code> 。在一步操作中，移除所有满足&nbsp;<code>nums[i - 1] &gt; nums[i]</code> 的 <code>nums[i]</code> ，其中 <code>0 &lt; i &lt; nums.length</code> 。</p>

<p>重复执行步骤，直到 <code>nums</code> 变为 <strong>非递减</strong> 数组，返回所需执行的操作数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [5,3,4,4,7,3,6,11,8,5,11]
<strong>输出：</strong>3
<strong>解释：</strong>执行下述几个步骤：
- 步骤 1 ：[5,<em><strong>3</strong></em>,4,4,7,<em><strong>3</strong></em>,6,11,<em><strong>8</strong></em>,<em><strong>5</strong></em>,11] 变为 [5,4,4,7,6,11,11]
- 步骤 2 ：[5,<em><strong>4</strong></em>,4,7,<em><strong>6</strong></em>,11,11] 变为 [5,4,7,11,11]
- 步骤 3 ：[5,<em><strong>4</strong></em>,7,11,11] 变为 [5,7,11,11]
[5,7,11,11] 是一个非递减数组，因此，返回 3 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [4,5,7,7,13]
<strong>输出：</strong>0
<strong>解释：</strong>nums 已经是一个非递减数组，因此，返回 0 。
</pre>

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

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def totalSteps(self, nums: List[int]) -> int:
        stk = []
        ans, n = 0, len(nums)
        dp = [0] * n
        for i in range(n - 1, -1, -1):
            while stk and nums[i] > nums[stk[-1]]:
                dp[i] = max(dp[i] + 1, dp[stk.pop()])
            stk.append(i)
        return max(dp)
```

#### Java

```java
class Solution {
    public int totalSteps(int[] nums) {
        Deque<Integer> stk = new ArrayDeque<>();
        int ans = 0;
        int n = nums.length;
        int[] dp = new int[n];
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.isEmpty() && nums[i] > nums[stk.peek()]) {
                dp[i] = Math.max(dp[i] + 1, dp[stk.pop()]);
                ans = Math.max(ans, dp[i]);
            }
            stk.push(i);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int totalSteps(vector<int>& nums) {
        stack<int> stk;
        int ans = 0, n = nums.size();
        vector<int> dp(n);
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.empty() && nums[i] > nums[stk.top()]) {
                dp[i] = max(dp[i] + 1, dp[stk.top()]);
                ans = max(ans, dp[i]);
                stk.pop();
            }
            stk.push(i);
        }
        return ans;
    }
};
```

#### Go

```go
func totalSteps(nums []int) int {
	stk := []int{}
	ans, n := 0, len(nums)
	dp := make([]int, n)
	for i := n - 1; i >= 0; i-- {
		for len(stk) > 0 && nums[i] > nums[stk[len(stk)-1]] {
			dp[i] = max(dp[i]+1, dp[stk[len(stk)-1]])
			stk = stk[:len(stk)-1]
			ans = max(ans, dp[i])
		}
		stk = append(stk, i)
	}
	return ans
}
```

#### TypeScript

```ts
function totalSteps(nums: number[]): number {
    let ans = 0;
    let stack = [];
    for (let num of nums) {
        let max = 0;
        while (stack.length && stack[0][0] <= num) {
            max = Math.max(stack[0][1], max);
            stack.shift();
        }
        if (stack.length) max++;
        ans = Math.max(max, ans);
        stack.unshift([num, max]);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
