---
title: "1790_仅执行一次字符串交换能否使两个字符串相等"
date: 2025-10-08T18:38:17+08:00
weight: 10
tags: [二分查找, 位运算, 动态规划, 单调栈, 双向链表, 双指针, 哈希表, 回溯, 图, 堆（优先队列）, 字符串, 排序, 数学, 数据库, 数组, 数论, 栈, 状态压缩, 计数, 设计, 贪心, 链表]
---

{{< markmap >}}
### [1790_仅执行一次字符串交换能否使两个字符串相等](#1790)
#### [哈希表](#1790)
#### [字符串](#1790)
#### [计数](#1790)
### [1791_找出星型图的中心节点](#1791)
#### [图](#1791)
### [1792_最大平均通过率](#1792)
#### [贪心](#1792)
#### [数组](#1792)
#### [堆（优先队列）](#1792)
### [1793_好子数组的最大分数](#1793)
#### [栈](#1793)
#### [数组](#1793)
#### [双指针](#1793)
#### [二分查找](#1793)
#### [单调栈](#1793)
### [1794_统计距离最小的子串对个数 🔒](#1794)
#### [贪心](#1794)
#### [哈希表](#1794)
#### [字符串](#1794)
### [1795_每个产品在不同商店的价格](#1795)
#### [数据库](#1795)
### [1796_字符串中第二大的数字](#1796)
#### [哈希表](#1796)
#### [字符串](#1796)
### [1797_设计一个验证系统](#1797)
#### [设计](#1797)
#### [哈希表](#1797)
#### [链表](#1797)
#### [双向链表](#1797)
### [1798_你能构造出连续值的最大数目](#1798)
#### [贪心](#1798)
#### [数组](#1798)
#### [排序](#1798)
### [1799_N 次操作后的最大分数和](#1799)
#### [位运算](#1799)
#### [数组](#1799)
#### [数学](#1799)
#### [动态规划](#1799)
#### [回溯](#1799)
#### [状态压缩](#1799)
#### [数论](#1799)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1790_仅执行一次字符串交换能否使两个字符串相等
___
#### 哈希表
___
#### 字符串
___
#### 计数
---
### 1791_找出星型图的中心节点
___
#### 图
---
### 1792_最大平均通过率
___
#### 贪心
___
#### 数组
___
#### 堆（优先队列）
---
### 1793_好子数组的最大分数
___
#### 栈
___
#### 数组
___
#### 双指针
___
#### 二分查找
___
#### 单调栈
---
### 1794_统计距离最小的子串对个数 🔒
___
#### 贪心
___
#### 哈希表
___
#### 字符串
---
### 1795_每个产品在不同商店的价格
___
#### 数据库
---
### 1796_字符串中第二大的数字
___
#### 哈希表
___
#### 字符串
---
### 1797_设计一个验证系统
___
#### 设计
___
#### 哈希表
___
#### 链表
___
#### 双向链表
---
### 1798_你能构造出连续值的最大数目
___
#### 贪心
___
#### 数组
___
#### 排序
---
### 1799_N 次操作后的最大分数和
___
#### 位运算
___
#### 数组
___
#### 数学
___
#### 动态规划
___
#### 回溯
___
#### 状态压缩
___
#### 数论
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 位运算 | 动态规划 |
| 单调栈 | 双向链表 | 双指针 |
| 哈希表 | 回溯 | 图 |
| 堆（优先队列） | 字符串 | 排序 |
| 数学 | 数据库 | 数组 |
| 数论 | 栈 | 状态压缩 |
| 计数 | 设计 | 贪心 |
| 链表 |  |  |

# [1790. 仅执行一次字符串交换能否使两个字符串相等](https://leetcode.cn/problems/check-if-one-string-swap-can-make-strings-equal){#1790}

{{< tabs "1790" >}}

{{% tab "python" %}}
```python
class Solution:
    def areAlmostEqual(self, s1: str, s2: str) -> bool:
        cnt = 0
        c1 = c2 = None
        for a, b in zip(s1, s2):
            if a != b:
                cnt += 1
                if cnt > 2 or (cnt == 2 and (a != c2 or b != c1)):
                    return False
                c1, c2 = a, b
        return cnt != 1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean areAlmostEqual(String s1, String s2) {
        int cnt = 0;
        char c1 = 0, c2 = 0;
        for (int i = 0; i < s1.length(); ++i) {
            char a = s1.charAt(i), b = s2.charAt(i);
            if (a != b) {
                if (++cnt > 2 || (cnt == 2 && (a != c2 || b != c1))) {
                    return false;
                }
                c1 = a;
                c2 = b;
            }
        }
        return cnt != 1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int cnt = 0;
        char c1 = 0, c2 = 0;
        for (int i = 0; i < s1.size(); ++i) {
            char a = s1[i], b = s2[i];
            if (a != b) {
                if (++cnt > 2 || (cnt == 2 && (a != c2 || b != c1))) {
                    return false;
                }
                c1 = a, c2 = b;
            }
        }
        return cnt != 1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func areAlmostEqual(s1 string, s2 string) bool {
	cnt := 0
	var c1, c2 byte
	for i := range s1 {
		a, b := s1[i], s2[i]
		if a != b {
			cnt++
			if cnt > 2 || (cnt == 2 && (a != c2 || b != c1)) {
				return false
			}
			c1, c2 = a, b
		}
	}
	return cnt != 1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function areAlmostEqual(s1: string, s2: string): boolean {
    let c1, c2;
    let cnt = 0;
    for (let i = 0; i < s1.length; ++i) {
        const a = s1.charAt(i);
        const b = s2.charAt(i);
        if (a != b) {
            if (++cnt > 2 || (cnt == 2 && (a != c2 || b != c1))) {
                return false;
            }
            c1 = a;
            c2 = b;
        }
    }
    return cnt != 1;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn are_almost_equal(s1: String, s2: String) -> bool {
        if s1 == s2 {
            return true;
        }
        let (s1, s2) = (s1.as_bytes(), s2.as_bytes());
        let mut idxs = vec![];
        for i in 0..s1.len() {
            if s1[i] != s2[i] {
                idxs.push(i);
            }
        }
        if idxs.len() != 2 {
            return false;
        }
        s1[idxs[0]] == s2[idxs[1]] && s2[idxs[0]] == s1[idxs[1]]
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
bool areAlmostEqual(char* s1, char* s2) {
    int n = strlen(s1);
    int i1 = -1;
    int i2 = -1;
    for (int i = 0; i < n; i++) {
        if (s1[i] != s2[i]) {
            if (i1 == -1) {
                i1 = i;
            } else if (i2 == -1) {
                i2 = i;
            } else {
                return 0;
            }
        }
    }
    if (i1 == -1 && i2 == -1) {
        return 1;
    }
    if (i1 == -1 || i2 == -1) {
        return 0;
    }
    return s1[i1] == s2[i2] && s1[i2] == s2[i1];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你长度相等的两个字符串 <code>s1</code> 和 <code>s2</code> 。一次<strong> 字符串交换 </strong>操作的步骤如下：选出某个字符串中的两个下标（不必不同），并交换这两个下标所对应的字符。</p>

<p>如果对 <strong>其中一个字符串</strong> 执行 <strong>最多一次字符串交换</strong> 就可以使两个字符串相等，返回 <code>true</code> ；否则，返回 <code>false</code> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s1 = "bank", s2 = "kanb"
<strong>输出：</strong>true
<strong>解释：</strong>例如，交换 s2 中的第一个和最后一个字符可以得到 "bank"
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s1 = "attack", s2 = "defend"
<strong>输出：</strong>false
<strong>解释：</strong>一次字符串交换无法使两个字符串相等
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>s1 = "kelb", s2 = "kelb"
<strong>输出：</strong>true
<strong>解释：</strong>两个字符串已经相等，所以不需要进行字符串交换
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>s1 = "abcd", s2 = "dcba"
<strong>输出：</strong>false
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s1.length, s2.length &lt;= 100</code></li>
	<li><code>s1.length == s2.length</code></li>
	<li><code>s1</code> 和 <code>s2</code> 仅由小写英文字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数

我们用变量 $cnt$ 记录两个字符串中相同位置字符不同的个数，两个字符串若满足题目要求，那么 $cnt$ 一定为 $0$ 或 $2$。另外用两个字符变量 $c1$ 和 $c2$ 记录两个字符串中相同位置字符不同的字符。

同时遍历两个字符串，对于相同位置的两个字符 $a$ 和 $b$，如果 $a \ne b$，那么 $cnt$ 自增 $1$。如果此时 $cnt$ 大于 $2$，或者 $cnt$ 为 $2$ 且 $a \ne c2$ 或 $b \ne c1$，那么直接返回 `false`。注意记录一下 $c1$ 和 $c2$。

遍历结束，若 $cnt \neq 1$，返回 `true`。

时间复杂度 $O(n)$，其中 $n$ 为字符串长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def areAlmostEqual(self, s1: str, s2: str) -> bool:
        cnt = 0
        c1 = c2 = None
        for a, b in zip(s1, s2):
            if a != b:
                cnt += 1
                if cnt > 2 or (cnt == 2 and (a != c2 or b != c1)):
                    return False
                c1, c2 = a, b
        return cnt != 1
```

#### Java

```java
class Solution {
    public boolean areAlmostEqual(String s1, String s2) {
        int cnt = 0;
        char c1 = 0, c2 = 0;
        for (int i = 0; i < s1.length(); ++i) {
            char a = s1.charAt(i), b = s2.charAt(i);
            if (a != b) {
                if (++cnt > 2 || (cnt == 2 && (a != c2 || b != c1))) {
                    return false;
                }
                c1 = a;
                c2 = b;
            }
        }
        return cnt != 1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int cnt = 0;
        char c1 = 0, c2 = 0;
        for (int i = 0; i < s1.size(); ++i) {
            char a = s1[i], b = s2[i];
            if (a != b) {
                if (++cnt > 2 || (cnt == 2 && (a != c2 || b != c1))) {
                    return false;
                }
                c1 = a, c2 = b;
            }
        }
        return cnt != 1;
    }
};
```

#### Go

```go
func areAlmostEqual(s1 string, s2 string) bool {
	cnt := 0
	var c1, c2 byte
	for i := range s1 {
		a, b := s1[i], s2[i]
		if a != b {
			cnt++
			if cnt > 2 || (cnt == 2 && (a != c2 || b != c1)) {
				return false
			}
			c1, c2 = a, b
		}
	}
	return cnt != 1
}
```

#### TypeScript

```ts
function areAlmostEqual(s1: string, s2: string): boolean {
    let c1, c2;
    let cnt = 0;
    for (let i = 0; i < s1.length; ++i) {
        const a = s1.charAt(i);
        const b = s2.charAt(i);
        if (a != b) {
            if (++cnt > 2 || (cnt == 2 && (a != c2 || b != c1))) {
                return false;
            }
            c1 = a;
            c2 = b;
        }
    }
    return cnt != 1;
}
```

#### Rust

```rust
impl Solution {
    pub fn are_almost_equal(s1: String, s2: String) -> bool {
        if s1 == s2 {
            return true;
        }
        let (s1, s2) = (s1.as_bytes(), s2.as_bytes());
        let mut idxs = vec![];
        for i in 0..s1.len() {
            if s1[i] != s2[i] {
                idxs.push(i);
            }
        }
        if idxs.len() != 2 {
            return false;
        }
        s1[idxs[0]] == s2[idxs[1]] && s2[idxs[0]] == s1[idxs[1]]
    }
}
```

#### C

```c
bool areAlmostEqual(char* s1, char* s2) {
    int n = strlen(s1);
    int i1 = -1;
    int i2 = -1;
    for (int i = 0; i < n; i++) {
        if (s1[i] != s2[i]) {
            if (i1 == -1) {
                i1 = i;
            } else if (i2 == -1) {
                i2 = i;
            } else {
                return 0;
            }
        }
    }
    if (i1 == -1 && i2 == -1) {
        return 1;
    }
    if (i1 == -1 || i2 == -1) {
        return 0;
    }
    return s1[i1] == s2[i2] && s1[i2] == s2[i1];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1791. 找出星型图的中心节点](https://leetcode.cn/problems/find-center-of-star-graph){#1791}

{{< tabs "1791" >}}

{{% tab "python" %}}
```python
class Solution:
    def findCenter(self, edges: List[List[int]]) -> int:
        return edges[0][0] if edges[0][0] in edges[1] else edges[0][1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int findCenter(int[][] edges) {
        int a = edges[0][0], b = edges[0][1];
        int c = edges[1][0], d = edges[1][1];
        return a == c || a == d ? a : b;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int a = edges[0][0], b = edges[0][1];
        int c = edges[1][0], d = edges[1][1];
        return a == c || a == d ? a : b;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findCenter(edges [][]int) int {
	a, b := edges[0][0], edges[0][1]
	c, d := edges[1][0], edges[1][1]
	if a == c || a == d {
		return a
	}
	return b
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findCenter(edges: number[][]): number {
    for (let num of edges[0]) {
        if (edges[1].includes(num)) {
            return num;
        }
    }
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn find_center(edges: Vec<Vec<i32>>) -> i32 {
        if edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1] {
            return edges[0][0];
        }
        edges[0][1]
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[][]} edges
 * @return {number}
 */
var findCenter = function (edges) {
    const [a, b] = edges[0];
    const [c, d] = edges[1];
    return a == c || a == d ? a : b;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>有一个无向的 <strong>星型</strong> 图，由 <code>n</code> 个编号从 <code>1</code> 到 <code>n</code> 的节点组成。星型图有一个 <strong>中心</strong> 节点，并且恰有 <code>n - 1</code> 条边将中心节点与其他每个节点连接起来。</p>

<p>给你一个二维整数数组 <code>edges</code> ，其中 <code>edges[i] = [u<sub>i</sub>, v<sub>i</sub>]</code> 表示在节点 <code>u<sub>i</sub></code> 和 <code>v<sub>i</sub></code> 之间存在一条边。请你找出并返回 <code>edges</code> 所表示星型图的中心节点。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1700-1799/1791.Find%20Center%20of%20Star%20Graph/images/star_graph.png" style="width: 331px; height: 321px;" />
<pre>
<strong>输入：</strong>edges = [[1,2],[2,3],[4,2]]
<strong>输出：</strong>2
<strong>解释：</strong>如上图所示，节点 2 与其他每个节点都相连，所以节点 2 是中心节点。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>edges = [[1,2],[5,1],[1,3],[1,4]]
<strong>输出：</strong>1
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 <= n <= 10<sup>5</sup></code></li>
	<li><code>edges.length == n - 1</code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>1 <= u<sub>i,</sub> v<sub>i</sub> <= n</code></li>
	<li><code>u<sub>i</sub> != v<sub>i</sub></code></li>
	<li>题目数据给出的 <code>edges</code> 表示一个有效的星型图</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：直接比较前两条边的点

中心点的特点是，它与其他所有点都相连，因此只要比较前两条边的点，如果有相同的点，那么这个点就是中心点。

时间复杂度 $O(1)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findCenter(self, edges: List[List[int]]) -> int:
        return edges[0][0] if edges[0][0] in edges[1] else edges[0][1]
```

#### Java

```java
class Solution {
    public int findCenter(int[][] edges) {
        int a = edges[0][0], b = edges[0][1];
        int c = edges[1][0], d = edges[1][1];
        return a == c || a == d ? a : b;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int a = edges[0][0], b = edges[0][1];
        int c = edges[1][0], d = edges[1][1];
        return a == c || a == d ? a : b;
    }
};
```

#### Go

```go
func findCenter(edges [][]int) int {
	a, b := edges[0][0], edges[0][1]
	c, d := edges[1][0], edges[1][1]
	if a == c || a == d {
		return a
	}
	return b
}
```

#### TypeScript

```ts
function findCenter(edges: number[][]): number {
    for (let num of edges[0]) {
        if (edges[1].includes(num)) {
            return num;
        }
    }
}
```

#### Rust

```rust
impl Solution {
    pub fn find_center(edges: Vec<Vec<i32>>) -> i32 {
        if edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1] {
            return edges[0][0];
        }
        edges[0][1]
    }
}
```

#### JavaScript

```js
/**
 * @param {number[][]} edges
 * @return {number}
 */
var findCenter = function (edges) {
    const [a, b] = edges[0];
    const [c, d] = edges[1];
    return a == c || a == d ? a : b;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1792. 最大平均通过率](https://leetcode.cn/problems/maximum-average-pass-ratio){#1792}

{{< tabs "1792" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxAverageRatio(self, classes: List[List[int]], extraStudents: int) -> float:
        h = [(a / b - (a + 1) / (b + 1), a, b) for a, b in classes]
        heapify(h)
        for _ in range(extraStudents):
            _, a, b = heappop(h)
            a, b = a + 1, b + 1
            heappush(h, (a / b - (a + 1) / (b + 1), a, b))
        return sum(v[1] / v[2] for v in h) / len(classes)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public double maxAverageRatio(int[][] classes, int extraStudents) {
        PriorityQueue<double[]> pq = new PriorityQueue<>((a, b) -> {
            double x = (a[0] + 1) / (a[1] + 1) - a[0] / a[1];
            double y = (b[0] + 1) / (b[1] + 1) - b[0] / b[1];
            return Double.compare(y, x);
        });
        for (var e : classes) {
            pq.offer(new double[] {e[0], e[1]});
        }
        while (extraStudents-- > 0) {
            var e = pq.poll();
            double a = e[0] + 1, b = e[1] + 1;
            pq.offer(new double[] {a, b});
        }
        double ans = 0;
        while (!pq.isEmpty()) {
            var e = pq.poll();
            ans += e[0] / e[1];
        }
        return ans / classes.length;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<tuple<double, int, int>> pq;
        for (auto& e : classes) {
            int a = e[0], b = e[1];
            double x = (double) (a + 1) / (b + 1) - (double) a / b;
            pq.push({x, a, b});
        }
        while (extraStudents--) {
            auto [_, a, b] = pq.top();
            pq.pop();
            a++;
            b++;
            double x = (double) (a + 1) / (b + 1) - (double) a / b;
            pq.push({x, a, b});
        }
        double ans = 0;
        while (pq.size()) {
            auto [_, a, b] = pq.top();
            pq.pop();
            ans += (double) a / b;
        }
        return ans / classes.size();
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxAverageRatio(classes [][]int, extraStudents int) float64 {
	pq := hp{}
	for _, e := range classes {
		a, b := e[0], e[1]
		x := float64(a+1)/float64(b+1) - float64(a)/float64(b)
		heap.Push(&pq, tuple{x, a, b})
	}
	for i := 0; i < extraStudents; i++ {
		e := heap.Pop(&pq).(tuple)
		a, b := e.a+1, e.b+1
		x := float64(a+1)/float64(b+1) - float64(a)/float64(b)
		heap.Push(&pq, tuple{x, a, b})
	}
	var ans float64
	for len(pq) > 0 {
		e := heap.Pop(&pq).(tuple)
		ans += float64(e.a) / float64(e.b)
	}
	return ans / float64(len(classes))
}

type tuple struct {
	x float64
	a int
	b int
}

type hp []tuple

func (h hp) Len() int { return len(h) }
func (h hp) Less(i, j int) bool {
	a, b := h[i], h[j]
	return a.x > b.x
}
func (h hp) Swap(i, j int) { h[i], h[j] = h[j], h[i] }
func (h *hp) Push(v any)   { *h = append(*h, v.(tuple)) }
func (h *hp) Pop() any     { a := *h; v := a[len(a)-1]; *h = a[:len(a)-1]; return v }
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxAverageRatio(classes: number[][], extraStudents: number): number {
    function calcGain(a: number, b: number): number {
        return (a + 1) / (b + 1) - a / b;
    }
    const pq = new PriorityQueue<[number, number]>(
        (p, q) => calcGain(q[0], q[1]) - calcGain(p[0], p[1]),
    );
    for (const [a, b] of classes) {
        pq.enqueue([a, b]);
    }
    while (extraStudents-- > 0) {
        const item = pq.dequeue();
        const [a, b] = item;
        pq.enqueue([a + 1, b + 1]);
    }
    let ans = 0;
    while (!pq.isEmpty()) {
        const item = pq.dequeue()!;
        const [a, b] = item;
        ans += a / b;
    }
    return ans / classes.length;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::cmp::Ordering;
use std::collections::BinaryHeap;

impl Solution {
    pub fn max_average_ratio(classes: Vec<Vec<i32>>, extra_students: i32) -> f64 {
        struct Node {
            gain: f64,
            a: i32,
            b: i32,
        }

        impl PartialEq for Node {
            fn eq(&self, other: &Self) -> bool {
                self.gain == other.gain
            }
        }
        impl Eq for Node {}

        impl PartialOrd for Node {
            fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
                self.gain.partial_cmp(&other.gain)
            }
        }
        impl Ord for Node {
            fn cmp(&self, other: &Self) -> Ordering {
                self.partial_cmp(other).unwrap()
            }
        }

        fn calc_gain(a: i32, b: i32) -> f64 {
            (a + 1) as f64 / (b + 1) as f64 - a as f64 / b as f64
        }

        let n = classes.len() as f64;
        let mut pq = BinaryHeap::new();

        for c in classes {
            let a = c[0];
            let b = c[1];
            pq.push(Node { gain: calc_gain(a, b), a, b });
        }

        let mut extra = extra_students;
        while extra > 0 {
            if let Some(mut node) = pq.pop() {
                node.a += 1;
                node.b += 1;
                node.gain = calc_gain(node.a, node.b);
                pq.push(node);
            }
            extra -= 1;
        }

        let mut sum = 0.0;
        while let Some(node) = pq.pop() {
            sum += node.a as f64 / node.b as f64;
        }

        sum / n
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>一所学校里有一些班级，每个班级里有一些学生，现在每个班都会进行一场期末考试。给你一个二维数组 <code>classes</code> ，其中 <code>classes[i] = [pass<sub>i</sub>, total<sub>i</sub>]</code> ，表示你提前知道了第 <code>i</code> 个班级总共有 <code>total<sub>i</sub></code> 个学生，其中只有 <code>pass<sub>i</sub></code> 个学生可以通过考试。</p>

<p>给你一个整数 <code>extraStudents</code> ，表示额外有 <code>extraStudents</code> 个聪明的学生，他们 <strong>一定</strong> 能通过任何班级的期末考。你需要给这 <code>extraStudents</code> 个学生每人都安排一个班级，使得 <strong>所有</strong> 班级的 <strong>平均</strong> 通过率 <strong>最大</strong> 。</p>

<p>一个班级的 <strong>通过率</strong> 等于这个班级通过考试的学生人数除以这个班级的总人数。<strong>平均通过率</strong> 是所有班级的通过率之和除以班级数目。</p>

<p>请你返回在安排这 <code><span style="">extraStudents</span></code> 个学生去对应班级后的 <strong>最大</strong> 平均通过率。与标准答案误差范围在 <code>10<sup>-5</sup></code> 以内的结果都会视为正确结果。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>classes = [[1,2],[3,5],[2,2]], <code>extraStudents</code> = 2
<b>输出：</b>0.78333
<b>解释：</b>你可以将额外的两个学生都安排到第一个班级，平均通过率为 (3/4 + 3/5 + 2/2) / 3 = 0.78333 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>classes = [[2,4],[3,9],[4,5],[2,10]], <code>extraStudents</code> = 4
<strong>输出：</strong>0.53485
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= classes.length <= 10<sup>5</sup></code></li>
	<li><code>classes[i].length == 2</code></li>
	<li><code>1 <= pass<sub>i</sub> <= total<sub>i</sub> <= 10<sup>5</sup></code></li>
	<li><code>1 <= extraStudents <= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：优先队列（增量大根堆）

假设一个班级当前的通过率为 $\frac{a}{b}$，那么如果我们将一个聪明的学生安排到此班级，那么班级的通过率就会变为 $\frac{a+1}{b+1}$。我们可以发现，通过率的增量为 $\frac{a+1}{b+1} - \frac{a}{b}$。

我们维护一个大根堆，堆中存储的是每个班级的通过率增量。

进行 `extraStudents` 次操作，每次从堆顶取出一个班级，将这个班级的人数和通过人数都加 $1$，然后将这个班级的通过率增量重新计算并放回堆中。重复这个过程，直到将所有的学生都分配完毕。

最后，我们将所有班级的通过率求和，然后除以班级数目，即为答案。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为班级数目。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxAverageRatio(self, classes: List[List[int]], extraStudents: int) -> float:
        h = [(a / b - (a + 1) / (b + 1), a, b) for a, b in classes]
        heapify(h)
        for _ in range(extraStudents):
            _, a, b = heappop(h)
            a, b = a + 1, b + 1
            heappush(h, (a / b - (a + 1) / (b + 1), a, b))
        return sum(v[1] / v[2] for v in h) / len(classes)
```

#### Java

```java
class Solution {
    public double maxAverageRatio(int[][] classes, int extraStudents) {
        PriorityQueue<double[]> pq = new PriorityQueue<>((a, b) -> {
            double x = (a[0] + 1) / (a[1] + 1) - a[0] / a[1];
            double y = (b[0] + 1) / (b[1] + 1) - b[0] / b[1];
            return Double.compare(y, x);
        });
        for (var e : classes) {
            pq.offer(new double[] {e[0], e[1]});
        }
        while (extraStudents-- > 0) {
            var e = pq.poll();
            double a = e[0] + 1, b = e[1] + 1;
            pq.offer(new double[] {a, b});
        }
        double ans = 0;
        while (!pq.isEmpty()) {
            var e = pq.poll();
            ans += e[0] / e[1];
        }
        return ans / classes.length;
    }
}
```

#### C++

```cpp
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<tuple<double, int, int>> pq;
        for (auto& e : classes) {
            int a = e[0], b = e[1];
            double x = (double) (a + 1) / (b + 1) - (double) a / b;
            pq.push({x, a, b});
        }
        while (extraStudents--) {
            auto [_, a, b] = pq.top();
            pq.pop();
            a++;
            b++;
            double x = (double) (a + 1) / (b + 1) - (double) a / b;
            pq.push({x, a, b});
        }
        double ans = 0;
        while (pq.size()) {
            auto [_, a, b] = pq.top();
            pq.pop();
            ans += (double) a / b;
        }
        return ans / classes.size();
    }
};
```

#### Go

```go
func maxAverageRatio(classes [][]int, extraStudents int) float64 {
	pq := hp{}
	for _, e := range classes {
		a, b := e[0], e[1]
		x := float64(a+1)/float64(b+1) - float64(a)/float64(b)
		heap.Push(&pq, tuple{x, a, b})
	}
	for i := 0; i < extraStudents; i++ {
		e := heap.Pop(&pq).(tuple)
		a, b := e.a+1, e.b+1
		x := float64(a+1)/float64(b+1) - float64(a)/float64(b)
		heap.Push(&pq, tuple{x, a, b})
	}
	var ans float64
	for len(pq) > 0 {
		e := heap.Pop(&pq).(tuple)
		ans += float64(e.a) / float64(e.b)
	}
	return ans / float64(len(classes))
}

type tuple struct {
	x float64
	a int
	b int
}

type hp []tuple

func (h hp) Len() int { return len(h) }
func (h hp) Less(i, j int) bool {
	a, b := h[i], h[j]
	return a.x > b.x
}
func (h hp) Swap(i, j int) { h[i], h[j] = h[j], h[i] }
func (h *hp) Push(v any)   { *h = append(*h, v.(tuple)) }
func (h *hp) Pop() any     { a := *h; v := a[len(a)-1]; *h = a[:len(a)-1]; return v }
```

#### TypeScript

```ts
function maxAverageRatio(classes: number[][], extraStudents: number): number {
    function calcGain(a: number, b: number): number {
        return (a + 1) / (b + 1) - a / b;
    }
    const pq = new PriorityQueue<[number, number]>(
        (p, q) => calcGain(q[0], q[1]) - calcGain(p[0], p[1]),
    );
    for (const [a, b] of classes) {
        pq.enqueue([a, b]);
    }
    while (extraStudents-- > 0) {
        const item = pq.dequeue();
        const [a, b] = item;
        pq.enqueue([a + 1, b + 1]);
    }
    let ans = 0;
    while (!pq.isEmpty()) {
        const item = pq.dequeue()!;
        const [a, b] = item;
        ans += a / b;
    }
    return ans / classes.length;
}
```

#### Rust

```rust
use std::cmp::Ordering;
use std::collections::BinaryHeap;

impl Solution {
    pub fn max_average_ratio(classes: Vec<Vec<i32>>, extra_students: i32) -> f64 {
        struct Node {
            gain: f64,
            a: i32,
            b: i32,
        }

        impl PartialEq for Node {
            fn eq(&self, other: &Self) -> bool {
                self.gain == other.gain
            }
        }
        impl Eq for Node {}

        impl PartialOrd for Node {
            fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
                self.gain.partial_cmp(&other.gain)
            }
        }
        impl Ord for Node {
            fn cmp(&self, other: &Self) -> Ordering {
                self.partial_cmp(other).unwrap()
            }
        }

        fn calc_gain(a: i32, b: i32) -> f64 {
            (a + 1) as f64 / (b + 1) as f64 - a as f64 / b as f64
        }

        let n = classes.len() as f64;
        let mut pq = BinaryHeap::new();

        for c in classes {
            let a = c[0];
            let b = c[1];
            pq.push(Node { gain: calc_gain(a, b), a, b });
        }

        let mut extra = extra_students;
        while extra > 0 {
            if let Some(mut node) = pq.pop() {
                node.a += 1;
                node.b += 1;
                node.gain = calc_gain(node.a, node.b);
                pq.push(node);
            }
            extra -= 1;
        }

        let mut sum = 0.0;
        while let Some(node) = pq.pop() {
            sum += node.a as f64 / node.b as f64;
        }

        sum / n
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1793. 好子数组的最大分数](https://leetcode.cn/problems/maximum-score-of-a-good-subarray){#1793}

{{< tabs "1793" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumScore(self, nums: List[int], k: int) -> int:
        n = len(nums)
        left = [-1] * n
        right = [n] * n
        stk = []
        for i, v in enumerate(nums):
            while stk and nums[stk[-1]] >= v:
                stk.pop()
            if stk:
                left[i] = stk[-1]
            stk.append(i)
        stk = []
        for i in range(n - 1, -1, -1):
            v = nums[i]
            while stk and nums[stk[-1]] > v:
                stk.pop()
            if stk:
                right[i] = stk[-1]
            stk.append(i)
        ans = 0
        for i, v in enumerate(nums):
            if left[i] + 1 <= k <= right[i] - 1:
                ans = max(ans, v * (right[i] - left[i] - 1))
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maximumScore(int[] nums, int k) {
        int n = nums.length;
        int[] left = new int[n];
        int[] right = new int[n];
        Arrays.fill(left, -1);
        Arrays.fill(right, n);
        Deque<Integer> stk = new ArrayDeque<>();
        for (int i = 0; i < n; ++i) {
            int v = nums[i];
            while (!stk.isEmpty() && nums[stk.peek()] >= v) {
                stk.pop();
            }
            if (!stk.isEmpty()) {
                left[i] = stk.peek();
            }
            stk.push(i);
        }
        stk.clear();
        for (int i = n - 1; i >= 0; --i) {
            int v = nums[i];
            while (!stk.isEmpty() && nums[stk.peek()] > v) {
                stk.pop();
            }
            if (!stk.isEmpty()) {
                right[i] = stk.peek();
            }
            stk.push(i);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (left[i] + 1 <= k && k <= right[i] - 1) {
                ans = Math.max(ans, nums[i] * (right[i] - left[i] - 1));
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
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> left(n, -1);
        vector<int> right(n, n);
        stack<int> stk;
        for (int i = 0; i < n; ++i) {
            int v = nums[i];
            while (!stk.empty() && nums[stk.top()] >= v) {
                stk.pop();
            }
            if (!stk.empty()) {
                left[i] = stk.top();
            }
            stk.push(i);
        }
        stk = stack<int>();
        for (int i = n - 1; i >= 0; --i) {
            int v = nums[i];
            while (!stk.empty() && nums[stk.top()] > v) {
                stk.pop();
            }
            if (!stk.empty()) {
                right[i] = stk.top();
            }
            stk.push(i);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (left[i] + 1 <= k && k <= right[i] - 1) {
                ans = max(ans, nums[i] * (right[i] - left[i] - 1));
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumScore(nums []int, k int) (ans int) {
	n := len(nums)
	left := make([]int, n)
	right := make([]int, n)
	for i := range left {
		left[i] = -1
		right[i] = n
	}
	stk := []int{}
	for i, v := range nums {
		for len(stk) > 0 && nums[stk[len(stk)-1]] >= v {
			stk = stk[:len(stk)-1]
		}
		if len(stk) > 0 {
			left[i] = stk[len(stk)-1]
		}
		stk = append(stk, i)
	}
	stk = []int{}
	for i := n - 1; i >= 0; i-- {
		v := nums[i]
		for len(stk) > 0 && nums[stk[len(stk)-1]] > v {
			stk = stk[:len(stk)-1]
		}
		if len(stk) > 0 {
			right[i] = stk[len(stk)-1]
		}
		stk = append(stk, i)
	}
	for i, v := range nums {
		if left[i]+1 <= k && k <= right[i]-1 {
			ans = max(ans, v*(right[i]-left[i]-1))
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumScore(nums: number[], k: number): number {
    const n = nums.length;
    const left: number[] = Array(n).fill(-1);
    const right: number[] = Array(n).fill(n);
    const stk: number[] = [];
    for (let i = 0; i < n; ++i) {
        while (stk.length && nums[stk.at(-1)] >= nums[i]) {
            stk.pop();
        }
        if (stk.length) {
            left[i] = stk.at(-1);
        }
        stk.push(i);
    }
    stk.length = 0;
    for (let i = n - 1; ~i; --i) {
        while (stk.length && nums[stk.at(-1)] > nums[i]) {
            stk.pop();
        }
        if (stk.length) {
            right[i] = stk.at(-1);
        }
        stk.push(i);
    }
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        if (left[i] + 1 <= k && k <= right[i] - 1) {
            ans = Math.max(ans, nums[i] * (right[i] - left[i] - 1));
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

<p>给你一个整数数组 <code>nums</code> <strong>（下标从 0 开始）</strong>和一个整数 <code>k</code> 。</p>

<p>一个子数组 <code>(i, j)</code> 的 <strong>分数</strong> 定义为 <code>min(nums[i], nums[i+1], ..., nums[j]) * (j - i + 1)</code> 。一个 <strong>好</strong> 子数组的两个端点下标需要满足 <code>i &lt;= k &lt;= j</code> 。</p>

<p>请你返回 <strong>好</strong> 子数组的最大可能 <strong>分数</strong> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [1,4,3,7,4,5], k = 3
<b>输出：</b>15
<b>解释：</b>最优子数组的左右端点下标是 (1, 5) ，分数为 min(4,3,7,4,5) * (5-1+1) = 3 * 5 = 15 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [5,5,4,5,4,1,1,1], k = 0
<b>输出：</b>20
<b>解释：</b>最优子数组的左右端点下标是 (0, 4) ，分数为 min(5,5,4,5,4) * (4-0+1) = 4 * 5 = 20 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>0 &lt;= k &lt; nums.length</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：单调栈

我们可以枚举 $nums$ 中的每个元素 $nums[i]$ 作为子数组的最小值，利用单调栈找出其左边第一个小于 $nums[i]$ 的位置 $left[i]$ 和右边第一个小于等于 $nums[i]$ 的位置 $right[i]$，则以 $nums[i]$ 为最小值的子数组的分数为 $nums[i] \times (right[i] - left[i] - 1)$。

需要注意的是，只有当左右边界 $left[i]$ 和 $right[i]$ 满足 $left[i]+1 \leq k \leq right[i]-1$ 时，答案才有可能更新。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumScore(self, nums: List[int], k: int) -> int:
        n = len(nums)
        left = [-1] * n
        right = [n] * n
        stk = []
        for i, v in enumerate(nums):
            while stk and nums[stk[-1]] >= v:
                stk.pop()
            if stk:
                left[i] = stk[-1]
            stk.append(i)
        stk = []
        for i in range(n - 1, -1, -1):
            v = nums[i]
            while stk and nums[stk[-1]] > v:
                stk.pop()
            if stk:
                right[i] = stk[-1]
            stk.append(i)
        ans = 0
        for i, v in enumerate(nums):
            if left[i] + 1 <= k <= right[i] - 1:
                ans = max(ans, v * (right[i] - left[i] - 1))
        return ans
```

#### Java

```java
class Solution {
    public int maximumScore(int[] nums, int k) {
        int n = nums.length;
        int[] left = new int[n];
        int[] right = new int[n];
        Arrays.fill(left, -1);
        Arrays.fill(right, n);
        Deque<Integer> stk = new ArrayDeque<>();
        for (int i = 0; i < n; ++i) {
            int v = nums[i];
            while (!stk.isEmpty() && nums[stk.peek()] >= v) {
                stk.pop();
            }
            if (!stk.isEmpty()) {
                left[i] = stk.peek();
            }
            stk.push(i);
        }
        stk.clear();
        for (int i = n - 1; i >= 0; --i) {
            int v = nums[i];
            while (!stk.isEmpty() && nums[stk.peek()] > v) {
                stk.pop();
            }
            if (!stk.isEmpty()) {
                right[i] = stk.peek();
            }
            stk.push(i);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (left[i] + 1 <= k && k <= right[i] - 1) {
                ans = Math.max(ans, nums[i] * (right[i] - left[i] - 1));
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
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> left(n, -1);
        vector<int> right(n, n);
        stack<int> stk;
        for (int i = 0; i < n; ++i) {
            int v = nums[i];
            while (!stk.empty() && nums[stk.top()] >= v) {
                stk.pop();
            }
            if (!stk.empty()) {
                left[i] = stk.top();
            }
            stk.push(i);
        }
        stk = stack<int>();
        for (int i = n - 1; i >= 0; --i) {
            int v = nums[i];
            while (!stk.empty() && nums[stk.top()] > v) {
                stk.pop();
            }
            if (!stk.empty()) {
                right[i] = stk.top();
            }
            stk.push(i);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (left[i] + 1 <= k && k <= right[i] - 1) {
                ans = max(ans, nums[i] * (right[i] - left[i] - 1));
            }
        }
        return ans;
    }
};
```

#### Go

```go
func maximumScore(nums []int, k int) (ans int) {
	n := len(nums)
	left := make([]int, n)
	right := make([]int, n)
	for i := range left {
		left[i] = -1
		right[i] = n
	}
	stk := []int{}
	for i, v := range nums {
		for len(stk) > 0 && nums[stk[len(stk)-1]] >= v {
			stk = stk[:len(stk)-1]
		}
		if len(stk) > 0 {
			left[i] = stk[len(stk)-1]
		}
		stk = append(stk, i)
	}
	stk = []int{}
	for i := n - 1; i >= 0; i-- {
		v := nums[i]
		for len(stk) > 0 && nums[stk[len(stk)-1]] > v {
			stk = stk[:len(stk)-1]
		}
		if len(stk) > 0 {
			right[i] = stk[len(stk)-1]
		}
		stk = append(stk, i)
	}
	for i, v := range nums {
		if left[i]+1 <= k && k <= right[i]-1 {
			ans = max(ans, v*(right[i]-left[i]-1))
		}
	}
	return
}
```

#### TypeScript

```ts
function maximumScore(nums: number[], k: number): number {
    const n = nums.length;
    const left: number[] = Array(n).fill(-1);
    const right: number[] = Array(n).fill(n);
    const stk: number[] = [];
    for (let i = 0; i < n; ++i) {
        while (stk.length && nums[stk.at(-1)] >= nums[i]) {
            stk.pop();
        }
        if (stk.length) {
            left[i] = stk.at(-1);
        }
        stk.push(i);
    }
    stk.length = 0;
    for (let i = n - 1; ~i; --i) {
        while (stk.length && nums[stk.at(-1)] > nums[i]) {
            stk.pop();
        }
        if (stk.length) {
            right[i] = stk.at(-1);
        }
        stk.push(i);
    }
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        if (left[i] + 1 <= k && k <= right[i] - 1) {
            ans = Math.max(ans, nums[i] * (right[i] - left[i] - 1));
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

# [1794. 统计距离最小的子串对个数 🔒](https://leetcode.cn/problems/count-pairs-of-equal-substrings-with-minimum-difference){#1794}

{{< tabs "1794" >}}

{{% tab "python" %}}
```python
class Solution:
    def countQuadruples(self, firstString: str, secondString: str) -> int:
        last = {c: i for i, c in enumerate(secondString)}
        ans, mi = 0, inf
        for i, c in enumerate(firstString):
            if c in last:
                t = i - last[c]
                if mi > t:
                    mi = t
                    ans = 1
                elif mi == t:
                    ans += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countQuadruples(String firstString, String secondString) {
        int[] last = new int[26];
        for (int i = 0; i < secondString.length(); ++i) {
            last[secondString.charAt(i) - 'a'] = i + 1;
        }
        int ans = 0, mi = 1 << 30;
        for (int i = 0; i < firstString.length(); ++i) {
            int j = last[firstString.charAt(i) - 'a'];
            if (j > 0) {
                int t = i - j;
                if (mi > t) {
                    mi = t;
                    ans = 1;
                } else if (mi == t) {
                    ++ans;
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
    int countQuadruples(string firstString, string secondString) {
        int last[26] = {0};
        for (int i = 0; i < secondString.size(); ++i) {
            last[secondString[i] - 'a'] = i + 1;
        }
        int ans = 0, mi = 1 << 30;
        for (int i = 0; i < firstString.size(); ++i) {
            int j = last[firstString[i] - 'a'];
            if (j) {
                int t = i - j;
                if (mi > t) {
                    mi = t;
                    ans = 1;
                } else if (mi == t) {
                    ++ans;
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
func countQuadruples(firstString string, secondString string) (ans int) {
	last := [26]int{}
	for i, c := range secondString {
		last[c-'a'] = i + 1
	}
	mi := 1 << 30
	for i, c := range firstString {
		j := last[c-'a']
		if j > 0 {
			t := i - j
			if mi > t {
				mi = t
				ans = 1
			} else if mi == t {
				ans++
			}
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countQuadruples(firstString: string, secondString: string): number {
    const last: number[] = new Array(26).fill(0);
    for (let i = 0; i < secondString.length; ++i) {
        last[secondString.charCodeAt(i) - 97] = i + 1;
    }
    let [ans, mi] = [0, Infinity];
    for (let i = 0; i < firstString.length; ++i) {
        const j = last[firstString.charCodeAt(i) - 97];
        if (j) {
            const t = i - j;
            if (mi > t) {
                mi = t;
                ans = 1;
            } else if (mi === t) {
                ++ans;
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

<p>输入数据为两个字符串<code>firstString</code> 和 <code>secondString</code>，两个字符串下标均从0开始，且均只包含小写的英文字符，请计算满足下列要求的下标四元组<code>(i,j,a,b)</code>的个数：</p>

<ul>
	<li><code>0 <= i <= j < firstString.length</code></li>
	<li><code>0 <= a <= b < secondString.length</code></li>
	<li><code>firstString</code>字符串中从<code>i</code>位置到<code>j</code>位置的子串(包括<code>j</code>位置的字符)和<code>secondString</code>字符串从<code>a</code>位置到<code>b</code>位置的子串(包括<code>b</code>位置字符)相等</li>
	<li><code>j-a</code>的数值是所有符合前面三个条件的四元组中可能的最小值</li>
</ul>

<p>返回符合上述 4 个条件的四元组的 <strong>个数</strong> 。</p>

<p> </p>

<p><strong>示例1：</strong></p>

<pre>
<strong>输入：</strong>firstString = "abcd", secondString = "bccda"
<strong>输出：</strong>1
<strong>解释：</strong>(0,0,4,4)是唯一符合条件的四元组且其<code>j-a</code>的数值是最小的.
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>firstString = "ab", secondString = "cd"
<strong>输出：</strong>0
<strong>解释：</strong>没有任何一个四元组能满足上述4个要求.
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= firstString.length, secondString.length <= 2 * 10<sup>5</sup></code></li>
	<li>两个输入字符串均只包含小写英文字符.</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 哈希表

题目实际上要我们找到一个最小的下标 $i$ 和一个最大的下标 $j$，使得 $firstString[i]$ 与 $secondString[j]$ 相等，且 $i - j$ 的值是所有满足条件的下标对中最小的。

因此，我们先用哈希表 $last$ 记录 $secondString$ 中每个字符最后一次出现的下标，然后遍历 $firstString$，对于每个字符 $c$，如果 $c$ 在 $secondString$ 中出现过，则计算 $i - last[c]$，如果 $i - last[c]$ 的值小于当前最小值，则更新最小值，同时更新答案为 1；如果 $i - last[c]$ 的值等于当前最小值，则答案加 1。

时间复杂度 $O(m + n)$，空间复杂度 $O(C)$。其中 $m$ 和 $n$ 分别是 $firstString$ 和 $secondString$ 的长度，而 $C$ 是字符集的大小。本题中 $C = 26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countQuadruples(self, firstString: str, secondString: str) -> int:
        last = {c: i for i, c in enumerate(secondString)}
        ans, mi = 0, inf
        for i, c in enumerate(firstString):
            if c in last:
                t = i - last[c]
                if mi > t:
                    mi = t
                    ans = 1
                elif mi == t:
                    ans += 1
        return ans
```

#### Java

```java
class Solution {
    public int countQuadruples(String firstString, String secondString) {
        int[] last = new int[26];
        for (int i = 0; i < secondString.length(); ++i) {
            last[secondString.charAt(i) - 'a'] = i + 1;
        }
        int ans = 0, mi = 1 << 30;
        for (int i = 0; i < firstString.length(); ++i) {
            int j = last[firstString.charAt(i) - 'a'];
            if (j > 0) {
                int t = i - j;
                if (mi > t) {
                    mi = t;
                    ans = 1;
                } else if (mi == t) {
                    ++ans;
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
    int countQuadruples(string firstString, string secondString) {
        int last[26] = {0};
        for (int i = 0; i < secondString.size(); ++i) {
            last[secondString[i] - 'a'] = i + 1;
        }
        int ans = 0, mi = 1 << 30;
        for (int i = 0; i < firstString.size(); ++i) {
            int j = last[firstString[i] - 'a'];
            if (j) {
                int t = i - j;
                if (mi > t) {
                    mi = t;
                    ans = 1;
                } else if (mi == t) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func countQuadruples(firstString string, secondString string) (ans int) {
	last := [26]int{}
	for i, c := range secondString {
		last[c-'a'] = i + 1
	}
	mi := 1 << 30
	for i, c := range firstString {
		j := last[c-'a']
		if j > 0 {
			t := i - j
			if mi > t {
				mi = t
				ans = 1
			} else if mi == t {
				ans++
			}
		}
	}
	return
}
```

#### TypeScript

```ts
function countQuadruples(firstString: string, secondString: string): number {
    const last: number[] = new Array(26).fill(0);
    for (let i = 0; i < secondString.length; ++i) {
        last[secondString.charCodeAt(i) - 97] = i + 1;
    }
    let [ans, mi] = [0, Infinity];
    for (let i = 0; i < firstString.length; ++i) {
        const j = last[firstString.charCodeAt(i) - 97];
        if (j) {
            const t = i - j;
            if (mi > t) {
                mi = t;
                ans = 1;
            } else if (mi === t) {
                ++ans;
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

# [1795. 每个产品在不同商店的价格](https://leetcode.cn/problems/rearrange-products-table){#1795}

{{< tabs "1795" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT product_id, 'store1' AS store, store1 AS price FROM Products WHERE store1 IS NOT NULL
UNION
SELECT product_id, 'store2' AS store, store2 AS price FROM Products WHERE store2 IS NOT NULL
UNION
SELECT product_id, 'store3' AS store, store3 AS price FROM Products WHERE store3 IS NOT NULL;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code>Products</code></p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| product_id  | int     |
| store1      | int     |
| store2      | int     |
| store3      | int     |
+-------------+---------+
在 SQL 中，这张表的主键是 product_id（产品Id）。
每行存储了这一产品在不同商店 store1, store2, store3 的价格。
如果这一产品在商店里没有出售，则值将为 null。
</pre>

<p>&nbsp;</p>

<p>请你重构 <code>Products</code> 表，查询每个产品在不同商店的价格，使得输出的格式变为<code>(product_id, store, price)</code> 。如果这一产品在商店里没有出售，则不输出这一行。</p>

<p>输出结果表中的 <strong>顺序不作要求</strong> 。</p>

<p>查询输出格式请参考下面示例。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
Products table:
+------------+--------+--------+--------+
| product_id | store1 | store2 | store3 |
+------------+--------+--------+--------+
| 0          | 95     | 100    | 105    |
| 1          | 70     | null   | 80     |
+------------+--------+--------+--------+
<strong>输出：</strong>
+------------+--------+-------+
| product_id | store  | price |
+------------+--------+-------+
| 0          | store1 | 95    |
| 0          | store2 | 100   |
| 0          | store3 | 105   |
| 1          | store1 | 70    |
| 1          | store3 | 80    |
+------------+--------+-------+
<strong>解释：</strong>
产品 0 在 store1、store2、store3 的价格分别为 95、100、105。
产品 1 在 store1、store3 的价格分别为 70、80。在 store2 无法买到。</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：合并

我们可以筛选出每个商店的产品和价格，然后使用 `UNION` 合并即可。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT product_id, 'store1' AS store, store1 AS price FROM Products WHERE store1 IS NOT NULL
UNION
SELECT product_id, 'store2' AS store, store2 AS price FROM Products WHERE store2 IS NOT NULL
UNION
SELECT product_id, 'store3' AS store, store3 AS price FROM Products WHERE store3 IS NOT NULL;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1796. 字符串中第二大的数字](https://leetcode.cn/problems/second-largest-digit-in-a-string){#1796}

{{< tabs "1796" >}}

{{% tab "python" %}}
```python
class Solution:
    def secondHighest(self, s: str) -> int:
        mask = reduce(or_, (1 << int(c) for c in s if c.isdigit()), 0)
        cnt = 0
        for i in range(9, -1, -1):
            if (mask >> i) & 1:
                cnt += 1
            if cnt == 2:
                return i
        return -1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int secondHighest(String s) {
        int mask = 0;
        for (int i = 0; i < s.length(); ++i) {
            char c = s.charAt(i);
            if (Character.isDigit(c)) {
                mask |= 1 << (c - '0');
            }
        }
        for (int i = 9, cnt = 0; i >= 0; --i) {
            if (((mask >> i) & 1) == 1 && ++cnt == 2) {
                return i;
            }
        }
        return -1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int secondHighest(string s) {
        int mask = 0;
        for (char& c : s)
            if (isdigit(c)) mask |= 1 << c - '0';
        for (int i = 9, cnt = 0; ~i; --i)
            if (mask >> i & 1 && ++cnt == 2) return i;
        return -1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func secondHighest(s string) int {
	mask := 0
	for _, c := range s {
		if c >= '0' && c <= '9' {
			mask |= 1 << int(c-'0')
		}
	}
	for i, cnt := 9, 0; i >= 0; i-- {
		if mask>>i&1 == 1 {
			cnt++
			if cnt == 2 {
				return i
			}
		}
	}
	return -1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function secondHighest(s: string): number {
    let first = -1;
    let second = -1;
    for (const c of s) {
        if (c >= '0' && c <= '9') {
            const num = c.charCodeAt(0) - '0'.charCodeAt(0);
            if (first < num) {
                [first, second] = [num, first];
            } else if (first !== num && second < num) {
                second = num;
            }
        }
    }
    return second;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn second_highest(s: String) -> i32 {
        let mut first = -1;
        let mut second = -1;
        for c in s.as_bytes() {
            if char::is_digit(*c as char, 10) {
                let num = (c - b'0') as i32;
                if first < num {
                    second = first;
                    first = num;
                } else if num < first && second < num {
                    second = num;
                }
            }
        }
        second
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
int secondHighest(char* s) {
    int first = -1;
    int second = -1;
    for (int i = 0; s[i]; i++) {
        if (isdigit(s[i])) {
            int num = s[i] - '0';
            if (num > first) {
                second = first;
                first = num;
            } else if (num < first && second < num) {
                second = num;
            }
        }
    }
    return second;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个混合字符串 <code>s</code> ，请你返回 <code>s</code> 中 <strong>第二大 </strong>的数字，如果不存在第二大的数字，请你返回 <code>-1</code> 。</p>

<p><strong>混合字符串 </strong>由小写英文字母和数字组成。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>s = "dfa12321afd"
<b>输出：</b>2
<b>解释：</b>出现在 s 中的数字包括 [1, 2, 3] 。第二大的数字是 2 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>s = "abc1111"
<b>输出：</b>-1
<b>解释：</b>出现在 s 中的数字只包含 [1] 。没有第二大的数字。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= s.length <= 500</code></li>
	<li><code>s</code> 只包含小写英文字母和（或）数字。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：一次遍历

我们定义 $a$ 和 $b$ 分别表示字符串中出现的最大数字和第二大数字，初始时 $a = b = -1$。

遍历字符串 $s$，如果当前字符是数字，我们将其转换为数字 $v$，如果 $v \gt a$，说明 $v$ 是当前出现的最大数字，我们将 $b$ 更新为 $a$，并将 $a$ 更新为 $v$；如果 $v \lt a$，说明 $v$ 是当前出现的第二大数字，我们将 $b$ 更新为 $v$。

遍历结束，返回 $b$ 即可。

时间复杂度 $O(n)$，其中 $n$ 为字符串 $s$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def secondHighest(self, s: str) -> int:
        a = b = -1
        for c in s:
            if c.isdigit():
                v = int(c)
                if v > a:
                    a, b = v, a
                elif b < v < a:
                    b = v
        return b
```

#### Java

```java
class Solution {
    public int secondHighest(String s) {
        int a = -1, b = -1;
        for (int i = 0; i < s.length(); ++i) {
            char c = s.charAt(i);
            if (Character.isDigit(c)) {
                int v = c - '0';
                if (v > a) {
                    b = a;
                    a = v;
                } else if (v > b && v < a) {
                    b = v;
                }
            }
        }
        return b;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int secondHighest(string s) {
        int a = -1, b = -1;
        for (char& c : s) {
            if (isdigit(c)) {
                int v = c - '0';
                if (v > a) {
                    b = a, a = v;
                } else if (v > b && v < a) {
                    b = v;
                }
            }
        }
        return b;
    }
};
```

#### Go

```go
func secondHighest(s string) int {
	a, b := -1, -1
	for _, c := range s {
		if c >= '0' && c <= '9' {
			v := int(c - '0')
			if v > a {
				b, a = a, v
			} else if v > b && v < a {
				b = v
			}
		}
	}
	return b
}
```

#### TypeScript

```ts
function secondHighest(s: string): number {
    let first = -1;
    let second = -1;
    for (const c of s) {
        if (c >= '0' && c <= '9') {
            const num = c.charCodeAt(0) - '0'.charCodeAt(0);
            if (first < num) {
                [first, second] = [num, first];
            } else if (first !== num && second < num) {
                second = num;
            }
        }
    }
    return second;
}
```

#### Rust

```rust
impl Solution {
    pub fn second_highest(s: String) -> i32 {
        let mut first = -1;
        let mut second = -1;
        for c in s.as_bytes() {
            if char::is_digit(*c as char, 10) {
                let num = (c - b'0') as i32;
                if first < num {
                    second = first;
                    first = num;
                } else if num < first && second < num {
                    second = num;
                }
            }
        }
        second
    }
}
```

#### C

```c
int secondHighest(char* s) {
    int first = -1;
    int second = -1;
    for (int i = 0; s[i]; i++) {
        if (isdigit(s[i])) {
            int num = s[i] - '0';
            if (num > first) {
                second = first;
                first = num;
            } else if (num < first && second < num) {
                second = num;
            }
        }
    }
    return second;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：位运算

我们可以用一个整数 $mask$ 来标识字符串中出现的数字，其中 $mask$ 的第 $i$ 位表示数字 $i$ 是否出现过。

遍历字符串 $s$，如果当前字符是数字，我们将其转换为数字 $v$，将 $mask$ 的第 $v$ 个二进制位的值置为 $1$。

最后，我们从高位向低位遍历 $mask$，找到第二个为 $1$ 的二进制位，其对应的数字即为第二大数字。如果不存在第二大数字，返回 $-1$。

时间复杂度 $O(n)$，其中 $n$ 为字符串 $s$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def secondHighest(self, s: str) -> int:
        mask = reduce(or_, (1 << int(c) for c in s if c.isdigit()), 0)
        cnt = 0
        for i in range(9, -1, -1):
            if (mask >> i) & 1:
                cnt += 1
            if cnt == 2:
                return i
        return -1
```

#### Java

```java
class Solution {
    public int secondHighest(String s) {
        int mask = 0;
        for (int i = 0; i < s.length(); ++i) {
            char c = s.charAt(i);
            if (Character.isDigit(c)) {
                mask |= 1 << (c - '0');
            }
        }
        for (int i = 9, cnt = 0; i >= 0; --i) {
            if (((mask >> i) & 1) == 1 && ++cnt == 2) {
                return i;
            }
        }
        return -1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int secondHighest(string s) {
        int mask = 0;
        for (char& c : s)
            if (isdigit(c)) mask |= 1 << c - '0';
        for (int i = 9, cnt = 0; ~i; --i)
            if (mask >> i & 1 && ++cnt == 2) return i;
        return -1;
    }
};
```

#### Go

```go
func secondHighest(s string) int {
	mask := 0
	for _, c := range s {
		if c >= '0' && c <= '9' {
			mask |= 1 << int(c-'0')
		}
	}
	for i, cnt := 9, 0; i >= 0; i-- {
		if mask>>i&1 == 1 {
			cnt++
			if cnt == 2 {
				return i
			}
		}
	}
	return -1
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1797. 设计一个验证系统](https://leetcode.cn/problems/design-authentication-manager){#1797}

{{< tabs "1797" >}}

{{% tab "python" %}}
```python
class AuthenticationManager:
    def __init__(self, timeToLive: int):
        self.t = timeToLive
        self.d = defaultdict(int)

    def generate(self, tokenId: str, currentTime: int) -> None:
        self.d[tokenId] = currentTime + self.t

    def renew(self, tokenId: str, currentTime: int) -> None:
        if self.d[tokenId] <= currentTime:
            return
        self.d[tokenId] = currentTime + self.t

    def countUnexpiredTokens(self, currentTime: int) -> int:
        return sum(exp > currentTime for exp in self.d.values())


# Your AuthenticationManager object will be instantiated and called as such:
# obj = AuthenticationManager(timeToLive)
# obj.generate(tokenId,currentTime)
# obj.renew(tokenId,currentTime)
# param_3 = obj.countUnexpiredTokens(currentTime)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class AuthenticationManager {
    private int t;
    private Map<String, Integer> d = new HashMap<>();

    public AuthenticationManager(int timeToLive) {
        t = timeToLive;
    }

    public void generate(String tokenId, int currentTime) {
        d.put(tokenId, currentTime + t);
    }

    public void renew(String tokenId, int currentTime) {
        if (d.getOrDefault(tokenId, 0) <= currentTime) {
            return;
        }
        generate(tokenId, currentTime);
    }

    public int countUnexpiredTokens(int currentTime) {
        int ans = 0;
        for (int exp : d.values()) {
            if (exp > currentTime) {
                ++ans;
            }
        }
        return ans;
    }
}

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager obj = new AuthenticationManager(timeToLive);
 * obj.generate(tokenId,currentTime);
 * obj.renew(tokenId,currentTime);
 * int param_3 = obj.countUnexpiredTokens(currentTime);
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class AuthenticationManager {
public:
    AuthenticationManager(int timeToLive) {
        t = timeToLive;
    }

    void generate(string tokenId, int currentTime) {
        d[tokenId] = currentTime + t;
    }

    void renew(string tokenId, int currentTime) {
        if (d[tokenId] <= currentTime) return;
        generate(tokenId, currentTime);
    }

    int countUnexpiredTokens(int currentTime) {
        int ans = 0;
        for (auto& [_, v] : d) ans += v > currentTime;
        return ans;
    }

private:
    int t;
    unordered_map<string, int> d;
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type AuthenticationManager struct {
	t int
	d map[string]int
}

func Constructor(timeToLive int) AuthenticationManager {
	return AuthenticationManager{timeToLive, map[string]int{}}
}

func (this *AuthenticationManager) Generate(tokenId string, currentTime int) {
	this.d[tokenId] = currentTime + this.t
}

func (this *AuthenticationManager) Renew(tokenId string, currentTime int) {
	if v, ok := this.d[tokenId]; !ok || v <= currentTime {
		return
	}
	this.Generate(tokenId, currentTime)
}

func (this *AuthenticationManager) CountUnexpiredTokens(currentTime int) int {
	ans := 0
	for _, exp := range this.d {
		if exp > currentTime {
			ans++
		}
	}
	return ans
}

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * obj := Constructor(timeToLive);
 * obj.Generate(tokenId,currentTime);
 * obj.Renew(tokenId,currentTime);
 * param_3 := obj.CountUnexpiredTokens(currentTime);
 */
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class AuthenticationManager {
    private timeToLive: number;
    private map: Map<string, number>;

    constructor(timeToLive: number) {
        this.timeToLive = timeToLive;
        this.map = new Map<string, number>();
    }

    generate(tokenId: string, currentTime: number): void {
        this.map.set(tokenId, currentTime + this.timeToLive);
    }

    renew(tokenId: string, currentTime: number): void {
        if ((this.map.get(tokenId) ?? 0) <= currentTime) {
            return;
        }
        this.map.set(tokenId, currentTime + this.timeToLive);
    }

    countUnexpiredTokens(currentTime: number): number {
        let res = 0;
        for (const time of this.map.values()) {
            if (time > currentTime) {
                res++;
            }
        }
        return res;
    }
}

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * var obj = new AuthenticationManager(timeToLive)
 * obj.generate(tokenId,currentTime)
 * obj.renew(tokenId,currentTime)
 * var param_3 = obj.countUnexpiredTokens(currentTime)
 */
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashMap;
struct AuthenticationManager {
    time_to_live: i32,
    map: HashMap<String, i32>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl AuthenticationManager {
    fn new(timeToLive: i32) -> Self {
        Self {
            time_to_live: timeToLive,
            map: HashMap::new(),
        }
    }

    fn generate(&mut self, token_id: String, current_time: i32) {
        self.map.insert(token_id, current_time + self.time_to_live);
    }

    fn renew(&mut self, token_id: String, current_time: i32) {
        if self.map.get(&token_id).unwrap_or(&0) <= &current_time {
            return;
        }
        self.map.insert(token_id, current_time + self.time_to_live);
    }

    fn count_unexpired_tokens(&self, current_time: i32) -> i32 {
        self.map
            .values()
            .filter(|&time| *time > current_time)
            .count() as i32
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你需要设计一个包含验证码的验证系统。每一次验证中，用户会收到一个新的验证码，这个验证码在 <code>currentTime</code> 时刻之后 <code>timeToLive</code> 秒过期。如果验证码被更新了，那么它会在 <code>currentTime</code> （可能与之前的 <code>currentTime</code> 不同）时刻延长 <code>timeToLive</code> 秒。</p>

<p>请你实现 <code>AuthenticationManager</code> 类：</p>

<ul>
	<li><code>AuthenticationManager(int timeToLive)</code> 构造 <code>AuthenticationManager</code> 并设置 <code>timeToLive</code> 参数。</li>
	<li><code>generate(string tokenId, int currentTime)</code> 给定 <code>tokenId</code> ，在当前时间 <code>currentTime</code> 生成一个新的验证码。</li>
	<li><code>renew(string tokenId, int currentTime)</code> 将给定 <code>tokenId</code> 且 <strong>未过期</strong> 的验证码在 <code>currentTime</code> 时刻更新。如果给定 <code>tokenId</code> 对应的验证码不存在或已过期，请你忽略该操作，不会有任何更新操作发生。</li>
	<li><code>countUnexpiredTokens(int currentTime)</code> 请返回在给定 <code>currentTime</code> 时刻，<strong>未过期</strong> 的验证码数目。</li>
</ul>

<p>如果一个验证码在时刻 <code>t</code> 过期，且另一个操作恰好在时刻 <code>t</code> 发生（<code>renew</code> 或者 <code>countUnexpiredTokens</code> 操作），过期事件 <strong>优先于</strong> 其他操作。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1700-1799/1797.Design%20Authentication%20Manager/images/copy-of-pc68_q2.png" style="width: 500px; height: 287px;" />
<pre>
<strong>输入：</strong>
["AuthenticationManager", "<code>renew</code>", "generate", "<code>countUnexpiredTokens</code>", "generate", "<code>renew</code>", "<code>renew</code>", "<code>countUnexpiredTokens</code>"]
[[5], ["aaa", 1], ["aaa", 2], [6], ["bbb", 7], ["aaa", 8], ["bbb", 10], [15]]
<strong>输出：</strong>
[null, null, null, 1, null, null, null, 0]

<strong>解释：</strong>
AuthenticationManager authenticationManager = new AuthenticationManager(5); // 构造 AuthenticationManager ，设置 <code>timeToLive</code> = 5 秒。
authenticationManager.<code>renew</code>("aaa", 1); // 时刻 1 时，没有验证码的 tokenId 为 "aaa" ，没有验证码被更新。
authenticationManager.generate("aaa", 2); // 时刻 2 时，生成一个 tokenId 为 "aaa" 的新验证码。
authenticationManager.<code>countUnexpiredTokens</code>(6); // 时刻 6 时，只有 tokenId 为 "aaa" 的验证码未过期，所以返回 1 。
authenticationManager.generate("bbb", 7); // 时刻 7 时，生成一个 tokenId 为 "bbb" 的新验证码。
authenticationManager.<code>renew</code>("aaa", 8); // tokenId 为 "aaa" 的验证码在时刻 7 过期，且 8 >= 7 ，所以时刻 8 的renew 操作被忽略，没有验证码被更新。
authenticationManager.<code>renew</code>("bbb", 10); // tokenId 为 "bbb" 的验证码在时刻 10 没有过期，所以 renew 操作会执行，该 token 将在时刻 15 过期。
authenticationManager.<code>countUnexpiredTokens</code>(15); // tokenId 为 "bbb" 的验证码在时刻 15 过期，tokenId 为 "aaa" 的验证码在时刻 7 过期，所有验证码均已过期，所以返回 0 。

</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= timeToLive <= 10<sup>8</sup></code></li>
	<li><code>1 <= currentTime <= 10<sup>8</sup></code></li>
	<li><code>1 <= tokenId.length <= 5</code></li>
	<li><code>tokenId</code> 只包含小写英文字母。</li>
	<li>所有 <code>generate</code> 函数的调用都会包含独一无二的 <code>tokenId</code> 值。</li>
	<li>所有函数调用中，<code>currentTime</code> 的值 <strong>严格递增</strong> 。</li>
	<li>所有函数的调用次数总共不超过 <code>2000</code> 次。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

我们可以简单维护一个哈希表 $d$，键为 `tokenId`，值为过期时间。

-   `generate` 操作时，将 `tokenId` 作为键，`currentTime + timeToLive` 作为值存入哈希表 $d$ 中。
-   `renew` 操作时，如果 `tokenId` 不在哈希表 $d$ 中，或者 `currentTime >= d[tokenId]`，则忽略该操作；否则，更新 `d[tokenId]` 为 `currentTime + timeToLive`。
-   `countUnexpiredTokens` 操作时，遍历哈希表 $d$，统计未过期的 `tokenId` 个数。

时间复杂度方面，`generate` 和 `renew` 操作的时间复杂度均为 $O(1)$，`countUnexpiredTokens` 操作的时间复杂度为 $O(n)$，其中 $n$ 为哈希表 $d$ 的键值对个数。

空间复杂度为 $O(n)$，其中 $n$ 为哈希表 $d$ 的键值对个数。

<!-- tabs:start -->

#### Python3

```python
class AuthenticationManager:
    def __init__(self, timeToLive: int):
        self.t = timeToLive
        self.d = defaultdict(int)

    def generate(self, tokenId: str, currentTime: int) -> None:
        self.d[tokenId] = currentTime + self.t

    def renew(self, tokenId: str, currentTime: int) -> None:
        if self.d[tokenId] <= currentTime:
            return
        self.d[tokenId] = currentTime + self.t

    def countUnexpiredTokens(self, currentTime: int) -> int:
        return sum(exp > currentTime for exp in self.d.values())


# Your AuthenticationManager object will be instantiated and called as such:
# obj = AuthenticationManager(timeToLive)
# obj.generate(tokenId,currentTime)
# obj.renew(tokenId,currentTime)
# param_3 = obj.countUnexpiredTokens(currentTime)
```

#### Java

```java
class AuthenticationManager {
    private int t;
    private Map<String, Integer> d = new HashMap<>();

    public AuthenticationManager(int timeToLive) {
        t = timeToLive;
    }

    public void generate(String tokenId, int currentTime) {
        d.put(tokenId, currentTime + t);
    }

    public void renew(String tokenId, int currentTime) {
        if (d.getOrDefault(tokenId, 0) <= currentTime) {
            return;
        }
        generate(tokenId, currentTime);
    }

    public int countUnexpiredTokens(int currentTime) {
        int ans = 0;
        for (int exp : d.values()) {
            if (exp > currentTime) {
                ++ans;
            }
        }
        return ans;
    }
}

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager obj = new AuthenticationManager(timeToLive);
 * obj.generate(tokenId,currentTime);
 * obj.renew(tokenId,currentTime);
 * int param_3 = obj.countUnexpiredTokens(currentTime);
 */
```

#### C++

```cpp
class AuthenticationManager {
public:
    AuthenticationManager(int timeToLive) {
        t = timeToLive;
    }

    void generate(string tokenId, int currentTime) {
        d[tokenId] = currentTime + t;
    }

    void renew(string tokenId, int currentTime) {
        if (d[tokenId] <= currentTime) return;
        generate(tokenId, currentTime);
    }

    int countUnexpiredTokens(int currentTime) {
        int ans = 0;
        for (auto& [_, v] : d) ans += v > currentTime;
        return ans;
    }

private:
    int t;
    unordered_map<string, int> d;
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */
```

#### Go

```go
type AuthenticationManager struct {
	t int
	d map[string]int
}

func Constructor(timeToLive int) AuthenticationManager {
	return AuthenticationManager{timeToLive, map[string]int{}}
}

func (this *AuthenticationManager) Generate(tokenId string, currentTime int) {
	this.d[tokenId] = currentTime + this.t
}

func (this *AuthenticationManager) Renew(tokenId string, currentTime int) {
	if v, ok := this.d[tokenId]; !ok || v <= currentTime {
		return
	}
	this.Generate(tokenId, currentTime)
}

func (this *AuthenticationManager) CountUnexpiredTokens(currentTime int) int {
	ans := 0
	for _, exp := range this.d {
		if exp > currentTime {
			ans++
		}
	}
	return ans
}

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * obj := Constructor(timeToLive);
 * obj.Generate(tokenId,currentTime);
 * obj.Renew(tokenId,currentTime);
 * param_3 := obj.CountUnexpiredTokens(currentTime);
 */
```

#### TypeScript

```ts
class AuthenticationManager {
    private timeToLive: number;
    private map: Map<string, number>;

    constructor(timeToLive: number) {
        this.timeToLive = timeToLive;
        this.map = new Map<string, number>();
    }

    generate(tokenId: string, currentTime: number): void {
        this.map.set(tokenId, currentTime + this.timeToLive);
    }

    renew(tokenId: string, currentTime: number): void {
        if ((this.map.get(tokenId) ?? 0) <= currentTime) {
            return;
        }
        this.map.set(tokenId, currentTime + this.timeToLive);
    }

    countUnexpiredTokens(currentTime: number): number {
        let res = 0;
        for (const time of this.map.values()) {
            if (time > currentTime) {
                res++;
            }
        }
        return res;
    }
}

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * var obj = new AuthenticationManager(timeToLive)
 * obj.generate(tokenId,currentTime)
 * obj.renew(tokenId,currentTime)
 * var param_3 = obj.countUnexpiredTokens(currentTime)
 */
```

#### Rust

```rust
use std::collections::HashMap;
struct AuthenticationManager {
    time_to_live: i32,
    map: HashMap<String, i32>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl AuthenticationManager {
    fn new(timeToLive: i32) -> Self {
        Self {
            time_to_live: timeToLive,
            map: HashMap::new(),
        }
    }

    fn generate(&mut self, token_id: String, current_time: i32) {
        self.map.insert(token_id, current_time + self.time_to_live);
    }

    fn renew(&mut self, token_id: String, current_time: i32) {
        if self.map.get(&token_id).unwrap_or(&0) <= &current_time {
            return;
        }
        self.map.insert(token_id, current_time + self.time_to_live);
    }

    fn count_unexpired_tokens(&self, current_time: i32) -> i32 {
        self.map
            .values()
            .filter(|&time| *time > current_time)
            .count() as i32
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1798. 你能构造出连续值的最大数目](https://leetcode.cn/problems/maximum-number-of-consecutive-values-you-can-make){#1798}

{{< tabs "1798" >}}

{{% tab "python" %}}
```python
class Solution:
    def getMaximumConsecutive(self, coins: List[int]) -> int:
        ans = 1
        for v in sorted(coins):
            if v > ans:
                break
            ans += v
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int getMaximumConsecutive(int[] coins) {
        Arrays.sort(coins);
        int ans = 1;
        for (int v : coins) {
            if (v > ans) {
                break;
            }
            ans += v;
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
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(), coins.end());
        int ans = 1;
        for (int& v : coins) {
            if (v > ans) break;
            ans += v;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func getMaximumConsecutive(coins []int) int {
	sort.Ints(coins)
	ans := 1
	for _, v := range coins {
		if v > ans {
			break
		}
		ans += v
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function getMaximumConsecutive(coins: number[]): number {
    coins.sort((a, b) => a - b);
    let ans = 1;
    for (const v of coins) {
        if (v > ans) {
            break;
        }
        ans += v;
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

<p>给你一个长度为 <code>n</code> 的整数数组 <code>coins</code> ，它代表你拥有的 <code>n</code> 个硬币。第 <code>i</code> 个硬币的值为 <code>coins[i]</code> 。如果你从这些硬币中选出一部分硬币，它们的和为 <code>x</code> ，那么称，你可以 <strong>构造</strong> 出 <code>x</code> 。</p>

<p>请返回从 <code>0</code> 开始（<strong>包括</strong> <code>0</code> ），你最多能 <strong>构造</strong> 出多少个连续整数。</p>

<p>你可能有多个相同值的硬币。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>coins = [1,3]
<b>输出：</b>2
<strong>解释：</strong>你可以得到以下这些值：
- 0：什么都不取 []
- 1：取 [1]
从 0 开始，你可以构造出 2 个连续整数。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>coins = [1,1,1,4]
<b>输出：</b>8
<strong>解释：</strong>你可以得到以下这些值：
- 0：什么都不取 []
- 1：取 [1]
- 2：取 [1,1]
- 3：取 [1,1,1]
- 4：取 [4]
- 5：取 [4,1]
- 6：取 [4,1,1]
- 7：取 [4,1,1,1]
从 0 开始，你可以构造出 8 个连续整数。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>nums = [1,4,10,3,1]
<b>输出：</b>20</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>coins.length == n</code></li>
	<li><code>1 <= n <= 4 * 10<sup>4</sup></code></li>
	<li><code>1 <= coins[i] <= 4 * 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 贪心

我们先对数组进行排序。然后定义 $ans$ 表示当前能够构造的连续整数的个数，初始化为 $1$。

遍历数组，对于当前遍历到的元素 $v$，如果 $v \gt ans$，说明无法构造出 $ans+1$ 个连续的整数，因此直接跳出循环，返回 $ans$ 即可。否则，说明可以构造出 $ans+v$ 个连续的整数，因此更新 $ans$ 为 $ans+v$。

最后返回 $ans$ 即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 为数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def getMaximumConsecutive(self, coins: List[int]) -> int:
        ans = 1
        for v in sorted(coins):
            if v > ans:
                break
            ans += v
        return ans
```

#### Java

```java
class Solution {
    public int getMaximumConsecutive(int[] coins) {
        Arrays.sort(coins);
        int ans = 1;
        for (int v : coins) {
            if (v > ans) {
                break;
            }
            ans += v;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(), coins.end());
        int ans = 1;
        for (int& v : coins) {
            if (v > ans) break;
            ans += v;
        }
        return ans;
    }
};
```

#### Go

```go
func getMaximumConsecutive(coins []int) int {
	sort.Ints(coins)
	ans := 1
	for _, v := range coins {
		if v > ans {
			break
		}
		ans += v
	}
	return ans
}
```

#### TypeScript

```ts
function getMaximumConsecutive(coins: number[]): number {
    coins.sort((a, b) => a - b);
    let ans = 1;
    for (const v of coins) {
        if (v > ans) {
            break;
        }
        ans += v;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1799. N 次操作后的最大分数和](https://leetcode.cn/problems/maximize-score-after-n-operations){#1799}

{{< tabs "1799" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxScore(self, nums: List[int]) -> int:
        m = len(nums)
        f = [0] * (1 << m)
        g = [[0] * m for _ in range(m)]
        for i in range(m):
            for j in range(i + 1, m):
                g[i][j] = gcd(nums[i], nums[j])
        for k in range(1 << m):
            if (cnt := k.bit_count()) % 2 == 0:
                for i in range(m):
                    if k >> i & 1:
                        for j in range(i + 1, m):
                            if k >> j & 1:
                                f[k] = max(
                                    f[k],
                                    f[k ^ (1 << i) ^ (1 << j)] + cnt // 2 * g[i][j],
                                )
        return f[-1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxScore(int[] nums) {
        int m = nums.length;
        int[][] g = new int[m][m];
        for (int i = 0; i < m; ++i) {
            for (int j = i + 1; j < m; ++j) {
                g[i][j] = gcd(nums[i], nums[j]);
            }
        }
        int[] f = new int[1 << m];
        for (int k = 0; k < 1 << m; ++k) {
            int cnt = Integer.bitCount(k);
            if (cnt % 2 == 0) {
                for (int i = 0; i < m; ++i) {
                    if (((k >> i) & 1) == 1) {
                        for (int j = i + 1; j < m; ++j) {
                            if (((k >> j) & 1) == 1) {
                                f[k] = Math.max(
                                    f[k], f[k ^ (1 << i) ^ (1 << j)] + cnt / 2 * g[i][j]);
                            }
                        }
                    }
                }
            }
        }
        return f[(1 << m) - 1];
    }

    private int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maxScore(vector<int>& nums) {
        int m = nums.size();
        int g[m][m];
        for (int i = 0; i < m; ++i) {
            for (int j = i + 1; j < m; ++j) {
                g[i][j] = gcd(nums[i], nums[j]);
            }
        }
        int f[1 << m];
        memset(f, 0, sizeof f);
        for (int k = 0; k < 1 << m; ++k) {
            int cnt = __builtin_popcount(k);
            if (cnt % 2 == 0) {
                for (int i = 0; i < m; ++i) {
                    if (k >> i & 1) {
                        for (int j = i + 1; j < m; ++j) {
                            if (k >> j & 1) {
                                f[k] = max(f[k], f[k ^ (1 << i) ^ (1 << j)] + cnt / 2 * g[i][j]);
                            }
                        }
                    }
                }
            }
        }
        return f[(1 << m) - 1];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxScore(nums []int) int {
	m := len(nums)
	g := [14][14]int{}
	for i := 0; i < m; i++ {
		for j := i + 1; j < m; j++ {
			g[i][j] = gcd(nums[i], nums[j])
		}
	}
	f := make([]int, 1<<m)
	for k := 0; k < 1<<m; k++ {
		cnt := bits.OnesCount(uint(k))
		if cnt%2 == 0 {
			for i := 0; i < m; i++ {
				if k>>i&1 == 1 {
					for j := i + 1; j < m; j++ {
						if k>>j&1 == 1 {
							f[k] = max(f[k], f[k^(1<<i)^(1<<j)]+cnt/2*g[i][j])
						}
					}
				}
			}
		}
	}
	return f[1<<m-1]
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxScore(nums: number[]): number {
    const m = nums.length;
    const f: number[] = new Array(1 << m).fill(0);
    const g: number[][] = new Array(m).fill(0).map(() => new Array(m).fill(0));
    for (let i = 0; i < m; ++i) {
        for (let j = i + 1; j < m; ++j) {
            g[i][j] = gcd(nums[i], nums[j]);
        }
    }
    for (let k = 0; k < 1 << m; ++k) {
        const cnt = bitCount(k);
        if (cnt % 2 === 0) {
            for (let i = 0; i < m; ++i) {
                if ((k >> i) & 1) {
                    for (let j = i + 1; j < m; ++j) {
                        if ((k >> j) & 1) {
                            const t = f[k ^ (1 << i) ^ (1 << j)] + ~~(cnt / 2) * g[i][j];
                            f[k] = Math.max(f[k], t);
                        }
                    }
                }
            }
        }
    }
    return f[(1 << m) - 1];
}

function gcd(a: number, b: number): number {
    return b ? gcd(b, a % b) : a;
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

<p>给你 <code>nums</code> ，它是一个大小为 <code>2 * n</code> 的正整数数组。你必须对这个数组执行 <code>n</code> 次操作。</p>

<p>在第 <code>i</code> 次操作时（操作编号从 <strong>1</strong> 开始），你需要：</p>

<ul>
	<li>选择两个元素 <code>x</code> 和 <code>y</code> 。</li>
	<li>获得分数 <code>i * gcd(x, y)</code> 。</li>
	<li>将 <code>x</code> 和 <code>y</code> 从 <code>nums</code> 中删除。</li>
</ul>

<p>请你返回 <code>n</code> 次操作后你能获得的分数和最大为多少。</p>

<p>函数 <code>gcd(x, y)</code> 是 <code>x</code> 和 <code>y</code> 的最大公约数。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [1,2]
<b>输出：</b>1
<b>解释：</b>最优操作是：
(1 * gcd(1, 2)) = 1
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [3,4,6,8]
<b>输出：</b>11
<b>解释：</b>最优操作是：
(1 * gcd(3, 6)) + (2 * gcd(4, 8)) = 3 + 8 = 11
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>nums = [1,2,3,4,5,6]
<b>输出：</b>14
<b>解释：</b>最优操作是：
(1 * gcd(1, 5)) + (2 * gcd(2, 4)) + (3 * gcd(3, 6)) = 1 + 4 + 9 = 14
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 7</code></li>
	<li><code>nums.length == 2 * n</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：状态压缩 + 动态规划

我们可以先预处理得到数组 `nums` 中任意两个数的最大公约数，存储在二维数组 $g$ 中，其中 $g[i][j]$ 表示 $nums[i]$ 和 $nums[j]$ 的最大公约数。

然后定义 $f[k]$ 表示当前操作后的状态为 $k$ 时，可以获得的最大分数和。假设 $m$ 为数组 `nums` 中的元素个数，那么状态一共有 $2^m$ 种，即 $k$ 的取值范围为 $[0, 2^m - 1]$。

从小到大枚举所有状态，对于每个状态 $k$，先判断此状态的二进制位中 $1$ 的个数 $cnt$ 是否为偶数，是则进行如下操作：

枚举 $k$ 中二进制位为 1 的位置，假设为 $i$ 和 $j$，则 $i$ 和 $j$ 两个位置的元素可以进行一次操作，此时可以获得的分数为 $\frac{cnt}{2} \times g[i][j]$，更新 $f[k]$ 的最大值。

最终答案即为 $f[2^m - 1]$。

时间复杂度 $O(2^m \times m^2)$，空间复杂度 $O(2^m)$。其中 $m$ 为数组 `nums` 中的元素个数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxScore(self, nums: List[int]) -> int:
        m = len(nums)
        f = [0] * (1 << m)
        g = [[0] * m for _ in range(m)]
        for i in range(m):
            for j in range(i + 1, m):
                g[i][j] = gcd(nums[i], nums[j])
        for k in range(1 << m):
            if (cnt := k.bit_count()) % 2 == 0:
                for i in range(m):
                    if k >> i & 1:
                        for j in range(i + 1, m):
                            if k >> j & 1:
                                f[k] = max(
                                    f[k],
                                    f[k ^ (1 << i) ^ (1 << j)] + cnt // 2 * g[i][j],
                                )
        return f[-1]
```

#### Java

```java
class Solution {
    public int maxScore(int[] nums) {
        int m = nums.length;
        int[][] g = new int[m][m];
        for (int i = 0; i < m; ++i) {
            for (int j = i + 1; j < m; ++j) {
                g[i][j] = gcd(nums[i], nums[j]);
            }
        }
        int[] f = new int[1 << m];
        for (int k = 0; k < 1 << m; ++k) {
            int cnt = Integer.bitCount(k);
            if (cnt % 2 == 0) {
                for (int i = 0; i < m; ++i) {
                    if (((k >> i) & 1) == 1) {
                        for (int j = i + 1; j < m; ++j) {
                            if (((k >> j) & 1) == 1) {
                                f[k] = Math.max(
                                    f[k], f[k ^ (1 << i) ^ (1 << j)] + cnt / 2 * g[i][j]);
                            }
                        }
                    }
                }
            }
        }
        return f[(1 << m) - 1];
    }

    private int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxScore(vector<int>& nums) {
        int m = nums.size();
        int g[m][m];
        for (int i = 0; i < m; ++i) {
            for (int j = i + 1; j < m; ++j) {
                g[i][j] = gcd(nums[i], nums[j]);
            }
        }
        int f[1 << m];
        memset(f, 0, sizeof f);
        for (int k = 0; k < 1 << m; ++k) {
            int cnt = __builtin_popcount(k);
            if (cnt % 2 == 0) {
                for (int i = 0; i < m; ++i) {
                    if (k >> i & 1) {
                        for (int j = i + 1; j < m; ++j) {
                            if (k >> j & 1) {
                                f[k] = max(f[k], f[k ^ (1 << i) ^ (1 << j)] + cnt / 2 * g[i][j]);
                            }
                        }
                    }
                }
            }
        }
        return f[(1 << m) - 1];
    }
};
```

#### Go

```go
func maxScore(nums []int) int {
	m := len(nums)
	g := [14][14]int{}
	for i := 0; i < m; i++ {
		for j := i + 1; j < m; j++ {
			g[i][j] = gcd(nums[i], nums[j])
		}
	}
	f := make([]int, 1<<m)
	for k := 0; k < 1<<m; k++ {
		cnt := bits.OnesCount(uint(k))
		if cnt%2 == 0 {
			for i := 0; i < m; i++ {
				if k>>i&1 == 1 {
					for j := i + 1; j < m; j++ {
						if k>>j&1 == 1 {
							f[k] = max(f[k], f[k^(1<<i)^(1<<j)]+cnt/2*g[i][j])
						}
					}
				}
			}
		}
	}
	return f[1<<m-1]
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}
```

#### TypeScript

```ts
function maxScore(nums: number[]): number {
    const m = nums.length;
    const f: number[] = new Array(1 << m).fill(0);
    const g: number[][] = new Array(m).fill(0).map(() => new Array(m).fill(0));
    for (let i = 0; i < m; ++i) {
        for (let j = i + 1; j < m; ++j) {
            g[i][j] = gcd(nums[i], nums[j]);
        }
    }
    for (let k = 0; k < 1 << m; ++k) {
        const cnt = bitCount(k);
        if (cnt % 2 === 0) {
            for (let i = 0; i < m; ++i) {
                if ((k >> i) & 1) {
                    for (let j = i + 1; j < m; ++j) {
                        if ((k >> j) & 1) {
                            const t = f[k ^ (1 << i) ^ (1 << j)] + ~~(cnt / 2) * g[i][j];
                            f[k] = Math.max(f[k], t);
                        }
                    }
                }
            }
        }
    }
    return f[(1 << m) - 1];
}

function gcd(a: number, b: number): number {
    return b ? gcd(b, a % b) : a;
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
