---
title: "1700_无法吃午餐的学生数量"
date: 2025-10-08T18:38:17+08:00
weight: 1
tags: [位运算, 前缀和, 堆（优先队列）, 字典树, 字符串, 数据库, 数组, 栈, 模拟, 滑动窗口, 矩阵, 计数, 贪心, 队列]
---

{{< markmap >}}
### [1700_无法吃午餐的学生数量](#1700)
#### [栈](#1700)
#### [队列](#1700)
#### [数组](#1700)
#### [模拟](#1700)
### [1701_平均等待时间](#1701)
#### [数组](#1701)
#### [模拟](#1701)
### [1702_修改后的最大二进制字符串](#1702)
#### [贪心](#1702)
#### [字符串](#1702)
### [1703_得到连续 K 个 1 的最少相邻交换次数](#1703)
#### [贪心](#1703)
#### [数组](#1703)
#### [前缀和](#1703)
#### [滑动窗口](#1703)
### [1704_判断字符串的两半是否相似](#1704)
#### [字符串](#1704)
#### [计数](#1704)
### [1705_吃苹果的最大数目](#1705)
#### [贪心](#1705)
#### [数组](#1705)
#### [堆（优先队列）](#1705)
### [1706_球会落何处](#1706)
#### [数组](#1706)
#### [矩阵](#1706)
#### [模拟](#1706)
### [1707_与数组中元素的最大异或值](#1707)
#### [位运算](#1707)
#### [字典树](#1707)
#### [数组](#1707)
### [1708_长度为 K 的最大子数组 🔒](#1708)
#### [贪心](#1708)
#### [数组](#1708)
### [1709_访问日期之间最大的空档期 🔒](#1709)
#### [数据库](#1709)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1700_无法吃午餐的学生数量
___
#### 栈
___
#### 队列
___
#### 数组
___
#### 模拟
---
### 1701_平均等待时间
___
#### 数组
___
#### 模拟
---
### 1702_修改后的最大二进制字符串
___
#### 贪心
___
#### 字符串
---
### 1703_得到连续 K 个 1 的最少相邻交换次数
___
#### 贪心
___
#### 数组
___
#### 前缀和
___
#### 滑动窗口
---
### 1704_判断字符串的两半是否相似
___
#### 字符串
___
#### 计数
---
### 1705_吃苹果的最大数目
___
#### 贪心
___
#### 数组
___
#### 堆（优先队列）
---
### 1706_球会落何处
___
#### 数组
___
#### 矩阵
___
#### 模拟
---
### 1707_与数组中元素的最大异或值
___
#### 位运算
___
#### 字典树
___
#### 数组
---
### 1708_长度为 K 的最大子数组 🔒
___
#### 贪心
___
#### 数组
---
### 1709_访问日期之间最大的空档期 🔒
___
#### 数据库
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 位运算 | 前缀和 | 堆（优先队列） |
| 字典树 | 字符串 | 数据库 |
| 数组 | 栈 | 模拟 |
| 滑动窗口 | 矩阵 | 计数 |
| 贪心 | 队列 |  |

# [1700. 无法吃午餐的学生数量](https://leetcode.cn/problems/number-of-students-unable-to-eat-lunch){#1700}

{{< tabs "1700" >}}

{{% tab "python" %}}
```python
class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        cnt = Counter(students)
        for v in sandwiches:
            if cnt[v] == 0:
                return cnt[v ^ 1]
            cnt[v] -= 1
        return 0
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countStudents(int[] students, int[] sandwiches) {
        int[] cnt = new int[2];
        for (int v : students) {
            ++cnt[v];
        }
        for (int v : sandwiches) {
            if (cnt[v]-- == 0) {
                return cnt[v ^ 1];
            }
        }
        return 0;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int cnt[2] = {0};
        for (int& v : students) ++cnt[v];
        for (int& v : sandwiches) {
            if (cnt[v]-- == 0) {
                return cnt[v ^ 1];
            }
        }
        return 0;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countStudents(students []int, sandwiches []int) int {
	cnt := [2]int{}
	for _, v := range students {
		cnt[v]++
	}
	for _, v := range sandwiches {
		if cnt[v] == 0 {
			return cnt[v^1]
		}
		cnt[v]--
	}
	return 0
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countStudents(students: number[], sandwiches: number[]): number {
    const count = [0, 0];
    for (const v of students) {
        count[v]++;
    }
    for (const v of sandwiches) {
        if (count[v] === 0) {
            return count[v ^ 1];
        }
        count[v]--;
    }
    return 0;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn count_students(students: Vec<i32>, sandwiches: Vec<i32>) -> i32 {
        let mut count = [0, 0];
        for &v in students.iter() {
            count[v as usize] += 1;
        }
        for &v in sandwiches.iter() {
            let v = v as usize;
            if count[v as usize] == 0 {
                return count[v ^ 1];
            }
            count[v] -= 1;
        }
        0
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
int countStudents(int* students, int studentsSize, int* sandwiches, int sandwichesSize) {
    int count[2] = {0};
    for (int i = 0; i < studentsSize; i++) {
        count[students[i]]++;
    }
    for (int i = 0; i < sandwichesSize; i++) {
        int j = sandwiches[i];
        if (count[j] == 0) {
            return count[j ^ 1];
        }
        count[j]--;
    }
    return 0;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>学校的自助午餐提供圆形和方形的三明治，分别用数字 <code>0</code> 和 <code>1</code> 表示。所有学生站在一个队列里，每个学生要么喜欢圆形的要么喜欢方形的。<br>
餐厅里三明治的数量与学生的数量相同。所有三明治都放在一个 <strong>栈</strong> 里，每一轮：</p>

<ul>
	<li>如果队列最前面的学生 <strong>喜欢</strong> 栈顶的三明治，那么会 <strong>拿走它</strong> 并离开队列。</li>
	<li>否则，这名学生会 <strong>放弃这个三明治</strong> 并回到队列的尾部。</li>
</ul>

<p>这个过程会一直持续到队列里所有学生都不喜欢栈顶的三明治为止。</p>

<p>给你两个整数数组 <code>students</code> 和 <code>sandwiches</code> ，其中 <code>sandwiches[i]</code> 是栈里面第 <code>i<sup>​​​​​​</sup></code> 个三明治的类型（<code>i = 0</code> 是栈的顶部）， <code>students[j]</code> 是初始队列里第 <code>j<sup>​​​​​​</sup></code> 名学生对三明治的喜好（<code>j = 0</code> 是队列的最开始位置）。请你返回无法吃午餐的学生数量。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>students = [1,1,0,0], sandwiches = [0,1,0,1]
<b>输出：</b>0<strong> 
解释：</strong>
- 最前面的学生放弃最顶上的三明治，并回到队列的末尾，学生队列变为 students = [1,0,0,1]。
- 最前面的学生放弃最顶上的三明治，并回到队列的末尾，学生队列变为 students = [0,0,1,1]。
- 最前面的学生拿走最顶上的三明治，剩余学生队列为 students = [0,1,1]，三明治栈为 sandwiches = [1,0,1]。
- 最前面的学生放弃最顶上的三明治，并回到队列的末尾，学生队列变为 students = [1,1,0]。
- 最前面的学生拿走最顶上的三明治，剩余学生队列为 students = [1,0]，三明治栈为 sandwiches = [0,1]。
- 最前面的学生放弃最顶上的三明治，并回到队列的末尾，学生队列变为 students = [0,1]。
- 最前面的学生拿走最顶上的三明治，剩余学生队列为 students = [1]，三明治栈为 sandwiches = [1]。
- 最前面的学生拿走最顶上的三明治，剩余学生队列为 students = []，三明治栈为 sandwiches = []。
所以所有学生都有三明治吃。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>students = [1,1,1,0,0,1], sandwiches = [1,0,0,0,1,1]
<b>输出：</b>3
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= students.length, sandwiches.length &lt;= 100</code></li>
	<li><code>students.length == sandwiches.length</code></li>
	<li><code>sandwiches[i]</code> 要么是 <code>0</code> ，要么是 <code>1</code> 。</li>
	<li><code>students[i]</code> 要么是 <code>0</code> ，要么是 <code>1</code> 。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数

我们观察发现，学生位置可调整，而三明治位置不可调整。也就是说，若前面的三明治没被拿走，则往后的所有三明治也无法被拿走。

因此，我们先用计数器 $cnt$ 统计学生喜欢的三明治种类和对应的数量。

然后遍历三明治，若在 $cnt$ 中找不到喜欢此三明治的学生，说明后面的三明治也无法被拿走，返回当前剩余的学生数量。

遍历结束。，说明所有学生都有三明治吃，返回 $0$。

时间复杂度 $O(n)$，其中 $n$ 为三明治数量。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        cnt = Counter(students)
        for v in sandwiches:
            if cnt[v] == 0:
                return cnt[v ^ 1]
            cnt[v] -= 1
        return 0
```

#### Java

```java
class Solution {
    public int countStudents(int[] students, int[] sandwiches) {
        int[] cnt = new int[2];
        for (int v : students) {
            ++cnt[v];
        }
        for (int v : sandwiches) {
            if (cnt[v]-- == 0) {
                return cnt[v ^ 1];
            }
        }
        return 0;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int cnt[2] = {0};
        for (int& v : students) ++cnt[v];
        for (int& v : sandwiches) {
            if (cnt[v]-- == 0) {
                return cnt[v ^ 1];
            }
        }
        return 0;
    }
};
```

#### Go

```go
func countStudents(students []int, sandwiches []int) int {
	cnt := [2]int{}
	for _, v := range students {
		cnt[v]++
	}
	for _, v := range sandwiches {
		if cnt[v] == 0 {
			return cnt[v^1]
		}
		cnt[v]--
	}
	return 0
}
```

#### TypeScript

```ts
function countStudents(students: number[], sandwiches: number[]): number {
    const count = [0, 0];
    for (const v of students) {
        count[v]++;
    }
    for (const v of sandwiches) {
        if (count[v] === 0) {
            return count[v ^ 1];
        }
        count[v]--;
    }
    return 0;
}
```

#### Rust

```rust
impl Solution {
    pub fn count_students(students: Vec<i32>, sandwiches: Vec<i32>) -> i32 {
        let mut count = [0, 0];
        for &v in students.iter() {
            count[v as usize] += 1;
        }
        for &v in sandwiches.iter() {
            let v = v as usize;
            if count[v as usize] == 0 {
                return count[v ^ 1];
            }
            count[v] -= 1;
        }
        0
    }
}
```

#### C

```c
int countStudents(int* students, int studentsSize, int* sandwiches, int sandwichesSize) {
    int count[2] = {0};
    for (int i = 0; i < studentsSize; i++) {
        count[students[i]]++;
    }
    for (int i = 0; i < sandwichesSize; i++) {
        int j = sandwiches[i];
        if (count[j] == 0) {
            return count[j ^ 1];
        }
        count[j]--;
    }
    return 0;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1701. 平均等待时间](https://leetcode.cn/problems/average-waiting-time){#1701}

{{< tabs "1701" >}}

{{% tab "python" %}}
```python
class Solution:
    def averageWaitingTime(self, customers: List[List[int]]) -> float:
        tot = t = 0
        for a, b in customers:
            t = max(t, a) + b
            tot += t - a
        return tot / len(customers)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public double averageWaitingTime(int[][] customers) {
        double tot = 0;
        int t = 0;
        for (var e : customers) {
            int a = e[0], b = e[1];
            t = Math.max(t, a) + b;
            tot += t - a;
        }
        return tot / customers.length;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double tot = 0;
        int t = 0;
        for (auto& e : customers) {
            int a = e[0], b = e[1];
            t = max(t, a) + b;
            tot += t - a;
        }
        return tot / customers.size();
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func averageWaitingTime(customers [][]int) float64 {
	tot, t := 0, 0
	for _, e := range customers {
		a, b := e[0], e[1]
		t = max(t, a) + b
		tot += t - a
	}
	return float64(tot) / float64(len(customers))
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function averageWaitingTime(customers: number[][]): number {
    let [tot, t] = [0, 0];
    for (const [a, b] of customers) {
        t = Math.max(t, a) + b;
        tot += t - a;
    }
    return tot / customers.length;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn average_waiting_time(customers: Vec<Vec<i32>>) -> f64 {
        let mut tot = 0.0;
        let mut t = 0;

        for e in customers.iter() {
            let a = e[0];
            let b = e[1];
            t = t.max(a) + b;
            tot += (t - a) as f64;
        }

        tot / customers.len() as f64
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
function averageWaitingTime(customers) {
    let [tot, t] = [0, 0];
    for (const [a, b] of customers) {
        t = Math.max(t, a) + b;
        tot += t - a;
    }
    return tot / customers.length;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>有一个餐厅，只有一位厨师。你有一个顾客数组 <code>customers</code> ，其中 <code>customers[i] = [arrival<sub>i</sub>, time<sub>i</sub>]</code> ：</p>

<ul>
	<li><code>arrival<sub>i</sub></code> 是第 <code>i</code> 位顾客到达的时间，到达时间按 <strong>非递减</strong> 顺序排列。</li>
	<li><code>time<sub>i</sub></code> 是给第 <code>i</code> 位顾客做菜需要的时间。</li>
</ul>

<p>当一位顾客到达时，他将他的订单给厨师，厨师一旦空闲的时候就开始做这位顾客的菜。每位顾客会一直等待到厨师完成他的订单。厨师同时只能做一个人的订单。厨师会严格按照 <strong>订单给他的顺序</strong> 做菜。</p>

<p>请你返回所有顾客需要等待的 <strong>平均 </strong>时间。与标准答案误差在 <code>10<sup>-5</sup></code> 范围以内，都视为正确结果。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>customers = [[1,2],[2,5],[4,3]]
<b>输出：</b>5.00000
<strong>解释：
</strong>1) 第一位顾客在时刻 1 到达，厨师拿到他的订单并在时刻 1 立马开始做菜，并在时刻 3 完成，第一位顾客等待时间为 3 - 1 = 2 。
2) 第二位顾客在时刻 2 到达，厨师在时刻 3 开始为他做菜，并在时刻 8 完成，第二位顾客等待时间为 8 - 2 = 6 。
3) 第三位顾客在时刻 4 到达，厨师在时刻 8 开始为他做菜，并在时刻 11 完成，第三位顾客等待时间为 11 - 4 = 7 。
平均等待时间为 (2 + 6 + 7) / 3 = 5 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>customers = [[5,2],[5,4],[10,3],[20,1]]
<b>输出：</b>3.25000
<strong>解释：
</strong>1) 第一位顾客在时刻 5 到达，厨师拿到他的订单并在时刻 5 立马开始做菜，并在时刻 7 完成，第一位顾客等待时间为 7 - 5 = 2 。
2) 第二位顾客在时刻 5 到达，厨师在时刻 7 开始为他做菜，并在时刻 11 完成，第二位顾客等待时间为 11 - 5 = 6 。
3) 第三位顾客在时刻 10 到达，厨师在时刻 11 开始为他做菜，并在时刻 14 完成，第三位顾客等待时间为 14 - 10 = 4 。
4) 第四位顾客在时刻 20 到达，厨师拿到他的订单并在时刻 20 立马开始做菜，并在时刻 21 完成，第四位顾客等待时间为 21 - 20 = 1 。
平均等待时间为 (2 + 6 + 4 + 1) / 4 = 3.25 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= customers.length <= 10<sup>5</sup></code></li>
	<li><code>1 <= arrival<sub>i</sub>, time<sub>i</sub> <= 10<sup>4</sup></code></li>
	<li><code>arrival<sub>i </sub><= arrival<sub>i+1</sub></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们用变量 `tot` 记录顾客的总等待时间，用变量 `t` 记录做完每个顾客的订单的时间，初始值均为 $0$。

遍历顾客数组 `customers`，对于每个顾客：

如果当前时间 `t` 小于等于顾客的到达时间 `customers[i][0]`，说明厨师没有在做菜，那么厨师可以立即开始做菜，做完这道菜的时间为 $t = customers[i][0] + customers[i][1]$，顾客的等待时间为 `customers[i][1]`。

否则，说明厨师正在做菜，那么顾客需要等待厨师做完此前的菜，才能开始做自己的菜，做完这道菜的时间为 $t = t + customers[i][1]$，顾客的等待时间为 $t - customers[i][0]$。

时间复杂度 $O(n)$，其中 $n$ 为顾客数组 `customers` 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def averageWaitingTime(self, customers: List[List[int]]) -> float:
        tot = t = 0
        for a, b in customers:
            t = max(t, a) + b
            tot += t - a
        return tot / len(customers)
```

#### Java

```java
class Solution {
    public double averageWaitingTime(int[][] customers) {
        double tot = 0;
        int t = 0;
        for (var e : customers) {
            int a = e[0], b = e[1];
            t = Math.max(t, a) + b;
            tot += t - a;
        }
        return tot / customers.length;
    }
}
```

#### C++

```cpp
class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double tot = 0;
        int t = 0;
        for (auto& e : customers) {
            int a = e[0], b = e[1];
            t = max(t, a) + b;
            tot += t - a;
        }
        return tot / customers.size();
    }
};
```

#### Go

```go
func averageWaitingTime(customers [][]int) float64 {
	tot, t := 0, 0
	for _, e := range customers {
		a, b := e[0], e[1]
		t = max(t, a) + b
		tot += t - a
	}
	return float64(tot) / float64(len(customers))
}
```

#### TypeScript

```ts
function averageWaitingTime(customers: number[][]): number {
    let [tot, t] = [0, 0];
    for (const [a, b] of customers) {
        t = Math.max(t, a) + b;
        tot += t - a;
    }
    return tot / customers.length;
}
```

#### Rust

```rust
impl Solution {
    pub fn average_waiting_time(customers: Vec<Vec<i32>>) -> f64 {
        let mut tot = 0.0;
        let mut t = 0;

        for e in customers.iter() {
            let a = e[0];
            let b = e[1];
            t = t.max(a) + b;
            tot += (t - a) as f64;
        }

        tot / customers.len() as f64
    }
}
```

#### JavaScript

```js
function averageWaitingTime(customers) {
    let [tot, t] = [0, 0];
    for (const [a, b] of customers) {
        t = Math.max(t, a) + b;
        tot += t - a;
    }
    return tot / customers.length;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1702. 修改后的最大二进制字符串](https://leetcode.cn/problems/maximum-binary-string-after-change){#1702}

{{< tabs "1702" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumBinaryString(self, binary: str) -> str:
        k = binary.find('0')
        if k == -1:
            return binary
        k += binary[k + 1 :].count('0')
        return '1' * k + '0' + '1' * (len(binary) - k - 1)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String maximumBinaryString(String binary) {
        int k = binary.indexOf('0');
        if (k == -1) {
            return binary;
        }
        int n = binary.length();
        for (int i = k + 1; i < n; ++i) {
            if (binary.charAt(i) == '0') {
                ++k;
            }
        }
        char[] ans = binary.toCharArray();
        Arrays.fill(ans, '1');
        ans[k] = '0';
        return String.valueOf(ans);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string maximumBinaryString(string binary) {
        int k = binary.find('0');
        if (k == binary.npos) {
            return binary;
        }
        int n = binary.size();
        for (int i = k + 1; i < n; ++i) {
            if (binary[i] == '0') {
                ++k;
            }
        }
        return string(k, '1') + '0' + string(n - k - 1, '1');
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumBinaryString(binary string) string {
	k := strings.IndexByte(binary, '0')
	if k == -1 {
		return binary
	}
	for _, c := range binary[k+1:] {
		if c == '0' {
			k++
		}
	}
	ans := []byte(binary)
	for i := range ans {
		ans[i] = '1'
	}
	ans[k] = '0'
	return string(ans)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumBinaryString(binary: string): string {
    let k = binary.indexOf('0');
    if (k === -1) {
        return binary;
    }
    k += binary.slice(k + 1).split('0').length - 1;
    return '1'.repeat(k) + '0' + '1'.repeat(binary.length - k - 1);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn maximum_binary_string(binary: String) -> String {
        if let Some(k) = binary.find('0') {
            let k = k + binary[k + 1..].chars().filter(|&c| c == '0').count();
            return format!(
                "{}{}{}",
                "1".repeat(k),
                "0",
                "1".repeat(binary.len() - k - 1)
            );
        }
        binary
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public string MaximumBinaryString(string binary) {
        int k = binary.IndexOf('0');
        if (k == -1) {
            return binary;
        }
        k += binary.Substring(k + 1).Count(c => c == '0');
        return new string('1', k) + '0' + new string('1', binary.Length - k - 1);
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个二进制字符串 <code>binary</code> ，它仅有 <code>0</code> 或者 <code>1</code> 组成。你可以使用下面的操作任意次对它进行修改：</p>

<ul>
	<li>操作 1 ：如果二进制串包含子字符串 <code>"00"</code> ，你可以用 <code>"10"</code> 将其替换。

    <ul>
    	<li>比方说， <code>"<strong>00</strong>010" -> "<strong>10</strong>010"</code></li>
    </ul>
    </li>
    <li>操作 2 ：如果二进制串包含子字符串 <code>"10"</code> ，你可以用 <code>"01"</code> 将其替换。
    <ul>
    	<li>比方说， <code>"000<strong>10</strong>" -> "000<strong>01</strong>"</code></li>
    </ul>
    </li>

</ul>

<p>请你返回执行上述操作任意次以后能得到的 <strong>最大二进制字符串</strong> 。如果二进制字符串 <code>x</code> 对应的十进制数字大于二进制字符串 <code>y</code> 对应的十进制数字，那么我们称二进制字符串<em> </em><code>x</code><em> </em>大于二进制字符串<em> </em><code>y</code><em> </em>。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>binary = "000110"
<b>输出：</b>"111011"
<b>解释：</b>一个可行的转换为：
"0001<strong>10</strong>" -> "0001<strong>01</strong>" 
"<strong>00</strong>0101" -> "<strong>10</strong>0101" 
"1<strong>00</strong>101" -> "1<strong>10</strong>101" 
"110<strong>10</strong>1" -> "110<strong>01</strong>1" 
"11<strong>00</strong>11" -> "11<strong>10</strong>11"
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>binary = "01"
<b>输出：</b>"01"
<b>解释：</b>"01" 没办法进行任何转换。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= binary.length <= 10<sup>5</sup></code></li>
	<li><code>binary</code> 仅包含 <code>'0'</code> 和 <code>'1'</code> 。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：脑筋急转弯

我们观察发现，操作 $2$ 可以把所有的 $1$ 都移动到字符串的末尾，而操作 $1$ 可以把所有的 `0000..000` 串变为 `111..110`。

因此，要想得到最大的二进制串，我们应该把所有不在开头的 $1$ 移动到字符串末尾，使得字符串变为 `111..11...000..00..11` 的形式，然后借助操作 $1$ 把中间的 `000..00` 变为 `111..10`。这样我们最终可以得到一个最多包含一个 $0$ 的二进制字符串，这个字符串就是我们要求的最大二进制串。

在代码实现上，我们首先判断字符串是否包含 $0$，如果不包含，直接返回原字符串。否则，我们找到第一个 $0$ 的位置 $k$，加上该位置之后的 $0$ 的个数，得到的就是修改后的字符串的 $0$ 所在的位置，其余位置都是 $1$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是字符串的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumBinaryString(self, binary: str) -> str:
        k = binary.find('0')
        if k == -1:
            return binary
        k += binary[k + 1 :].count('0')
        return '1' * k + '0' + '1' * (len(binary) - k - 1)
```

#### Java

```java
class Solution {
    public String maximumBinaryString(String binary) {
        int k = binary.indexOf('0');
        if (k == -1) {
            return binary;
        }
        int n = binary.length();
        for (int i = k + 1; i < n; ++i) {
            if (binary.charAt(i) == '0') {
                ++k;
            }
        }
        char[] ans = binary.toCharArray();
        Arrays.fill(ans, '1');
        ans[k] = '0';
        return String.valueOf(ans);
    }
}
```

#### C++

```cpp
class Solution {
public:
    string maximumBinaryString(string binary) {
        int k = binary.find('0');
        if (k == binary.npos) {
            return binary;
        }
        int n = binary.size();
        for (int i = k + 1; i < n; ++i) {
            if (binary[i] == '0') {
                ++k;
            }
        }
        return string(k, '1') + '0' + string(n - k - 1, '1');
    }
};
```

#### Go

```go
func maximumBinaryString(binary string) string {
	k := strings.IndexByte(binary, '0')
	if k == -1 {
		return binary
	}
	for _, c := range binary[k+1:] {
		if c == '0' {
			k++
		}
	}
	ans := []byte(binary)
	for i := range ans {
		ans[i] = '1'
	}
	ans[k] = '0'
	return string(ans)
}
```

#### TypeScript

```ts
function maximumBinaryString(binary: string): string {
    let k = binary.indexOf('0');
    if (k === -1) {
        return binary;
    }
    k += binary.slice(k + 1).split('0').length - 1;
    return '1'.repeat(k) + '0' + '1'.repeat(binary.length - k - 1);
}
```

#### Rust

```rust
impl Solution {
    pub fn maximum_binary_string(binary: String) -> String {
        if let Some(k) = binary.find('0') {
            let k = k + binary[k + 1..].chars().filter(|&c| c == '0').count();
            return format!(
                "{}{}{}",
                "1".repeat(k),
                "0",
                "1".repeat(binary.len() - k - 1)
            );
        }
        binary
    }
}
```

#### C#

```cs
public class Solution {
    public string MaximumBinaryString(string binary) {
        int k = binary.IndexOf('0');
        if (k == -1) {
            return binary;
        }
        k += binary.Substring(k + 1).Count(c => c == '0');
        return new string('1', k) + '0' + new string('1', binary.Length - k - 1);
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1703. 得到连续 K 个 1 的最少相邻交换次数](https://leetcode.cn/problems/minimum-adjacent-swaps-for-k-consecutive-ones){#1703}

{{< tabs "1703" >}}

{{% tab "python" %}}
```python
class Solution:
    def minMoves(self, nums: List[int], k: int) -> int:
        arr = [i for i, x in enumerate(nums) if x]
        s = list(accumulate(arr, initial=0))
        ans = inf
        x = (k + 1) // 2
        y = k - x
        for i in range(x - 1, len(arr) - y):
            j = arr[i]
            ls = s[i + 1] - s[i + 1 - x]
            rs = s[i + 1 + y] - s[i + 1]
            a = (j + j - x + 1) * x // 2 - ls
            b = rs - (j + 1 + j + y) * y // 2
            ans = min(ans, a + b)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minMoves(int[] nums, int k) {
        List<Integer> arr = new ArrayList<>();
        int n = nums.length;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != 0) {
                arr.add(i);
            }
        }
        int m = arr.size();
        int[] s = new int[m + 1];
        for (int i = 0; i < m; ++i) {
            s[i + 1] = s[i] + arr.get(i);
        }
        long ans = 1 << 60;
        int x = (k + 1) / 2;
        int y = k - x;
        for (int i = x - 1; i < m - y; ++i) {
            int j = arr.get(i);
            int ls = s[i + 1] - s[i + 1 - x];
            int rs = s[i + 1 + y] - s[i + 1];
            long a = (j + j - x + 1L) * x / 2 - ls;
            long b = rs - (j + 1L + j + y) * y / 2;
            ans = Math.min(ans, a + b);
        }
        return (int) ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minMoves(vector<int>& nums, int k) {
        vector<int> arr;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i]) {
                arr.push_back(i);
            }
        }
        int m = arr.size();
        long s[m + 1];
        s[0] = 1;
        for (int i = 0; i < m; ++i) {
            s[i + 1] = s[i] + arr[i];
        }
        long ans = 1L << 60;
        int x = (k + 1) / 2;
        int y = k - x;
        for (int i = x - 1; i < m - y; ++i) {
            int j = arr[i];
            int ls = s[i + 1] - s[i + 1 - x];
            int rs = s[i + 1 + y] - s[i + 1];
            long a = (j + j - x + 1L) * x / 2 - ls;
            long b = rs - (j + 1L + j + y) * y / 2;
            ans = min(ans, a + b);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minMoves(nums []int, k int) int {
	arr := []int{}
	for i, x := range nums {
		if x != 0 {
			arr = append(arr, i)
		}
	}
	s := make([]int, len(arr)+1)
	for i, x := range arr {
		s[i+1] = s[i] + x
	}
	ans := 1 << 60
	x := (k + 1) / 2
	y := k - x
	for i := x - 1; i < len(arr)-y; i++ {
		j := arr[i]
		ls := s[i+1] - s[i+1-x]
		rs := s[i+1+y] - s[i+1]
		a := (j+j-x+1)*x/2 - ls
		b := rs - (j+1+j+y)*y/2
		ans = min(ans, a+b)
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

<p>给你一个整数数组 <code>nums</code> 和一个整数 <code>k</code> 。 <code>nums</code> 仅包含 <code>0</code> 和 <code>1</code> 。每一次移动，你可以选择 <strong>相邻</strong> 两个数字并将它们交换。</p>

<p>请你返回使 <code>nums</code> 中包含 <code>k</code> 个 <strong>连续 </strong><code>1</code> 的 <strong>最少</strong> 交换次数。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [1,0,0,1,0,1], k = 2
<b>输出：</b>1
<b>解释：</b>在第一次操作时，nums 可以变成 [1,0,0,0,<strong>1</strong>,<strong>1</strong>] 得到连续两个 1 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [1,0,0,0,0,0,1,1], k = 3
<b>输出：</b>5
<b>解释：</b>通过 5 次操作，最左边的 1 可以移到右边直到 nums 变为 [0,0,0,0,0,<strong>1</strong>,<strong>1</strong>,<strong>1</strong>] 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>nums = [1,1,0,1], k = 2
<b>输出：</b>0
<b>解释：</b>nums 已经有连续 2 个 1 了。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>nums[i]</code> 要么是 <code>0</code> ，要么是 <code>1</code> 。</li>
	<li><code>1 &lt;= k &lt;= sum(nums)</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前缀和 + 中位数枚举

我们可以将数组 $nums$ 中的 $1$ 的下标存入数组 $arr$ 中。接下来，我们预处理数组 $arr$ 的前缀和数组 $s$，其中 $s[i]$ 表示数组 $arr$ 中前 $i$ 个元素的和。

对于长度为 $k$ 的子数组，左侧（包含中位数）的元素个数 $x=\frac{k+1}{2}$，右侧的元素个数为 $y=k-x$。

我们枚举中位数的下标 $i$，其中 $x-1\leq i\leq len(arr)-y$，那么左侧数组的前缀和 $ls=s[i+1]-s[i+1-x]$，右侧数组的前缀和 $rs=s[i+1+y]-s[i+1]$。当前中位数在 $nums$ 中的下标为 $j=arr[i]$，将左侧 $x$ 个元素移动到 $[j-x+1,..j]$ 所需要的操作次数为 $a=(j+j-x+1)\times\frac{x}{2}-ls$，将右侧 $y$ 个元素移动到 $[j+1,..j+y]$ 所需要的操作次数为 $b=rs-(j+1+j+y)\times\frac{y}{2}$，那么总的操作次数为 $a+b$，我们取所有总的操作次数的最小值即可。

时间复杂度 $O(n)$，空间复杂度 $O(m)$。其中 $n$ 和 $m$ 分别为数组 $nums$ 的长度以及数组 $nums$ 中 $1$ 的个数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minMoves(self, nums: List[int], k: int) -> int:
        arr = [i for i, x in enumerate(nums) if x]
        s = list(accumulate(arr, initial=0))
        ans = inf
        x = (k + 1) // 2
        y = k - x
        for i in range(x - 1, len(arr) - y):
            j = arr[i]
            ls = s[i + 1] - s[i + 1 - x]
            rs = s[i + 1 + y] - s[i + 1]
            a = (j + j - x + 1) * x // 2 - ls
            b = rs - (j + 1 + j + y) * y // 2
            ans = min(ans, a + b)
        return ans
```

#### Java

```java
class Solution {
    public int minMoves(int[] nums, int k) {
        List<Integer> arr = new ArrayList<>();
        int n = nums.length;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != 0) {
                arr.add(i);
            }
        }
        int m = arr.size();
        int[] s = new int[m + 1];
        for (int i = 0; i < m; ++i) {
            s[i + 1] = s[i] + arr.get(i);
        }
        long ans = 1 << 60;
        int x = (k + 1) / 2;
        int y = k - x;
        for (int i = x - 1; i < m - y; ++i) {
            int j = arr.get(i);
            int ls = s[i + 1] - s[i + 1 - x];
            int rs = s[i + 1 + y] - s[i + 1];
            long a = (j + j - x + 1L) * x / 2 - ls;
            long b = rs - (j + 1L + j + y) * y / 2;
            ans = Math.min(ans, a + b);
        }
        return (int) ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minMoves(vector<int>& nums, int k) {
        vector<int> arr;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i]) {
                arr.push_back(i);
            }
        }
        int m = arr.size();
        long s[m + 1];
        s[0] = 1;
        for (int i = 0; i < m; ++i) {
            s[i + 1] = s[i] + arr[i];
        }
        long ans = 1L << 60;
        int x = (k + 1) / 2;
        int y = k - x;
        for (int i = x - 1; i < m - y; ++i) {
            int j = arr[i];
            int ls = s[i + 1] - s[i + 1 - x];
            int rs = s[i + 1 + y] - s[i + 1];
            long a = (j + j - x + 1L) * x / 2 - ls;
            long b = rs - (j + 1L + j + y) * y / 2;
            ans = min(ans, a + b);
        }
        return ans;
    }
};
```

#### Go

```go
func minMoves(nums []int, k int) int {
	arr := []int{}
	for i, x := range nums {
		if x != 0 {
			arr = append(arr, i)
		}
	}
	s := make([]int, len(arr)+1)
	for i, x := range arr {
		s[i+1] = s[i] + x
	}
	ans := 1 << 60
	x := (k + 1) / 2
	y := k - x
	for i := x - 1; i < len(arr)-y; i++ {
		j := arr[i]
		ls := s[i+1] - s[i+1-x]
		rs := s[i+1+y] - s[i+1]
		a := (j+j-x+1)*x/2 - ls
		b := rs - (j+1+j+y)*y/2
		ans = min(ans, a+b)
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1704. 判断字符串的两半是否相似](https://leetcode.cn/problems/determine-if-string-halves-are-alike){#1704}

{{< tabs "1704" >}}

{{% tab "python" %}}
```python
class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        cnt, n = 0, len(s) >> 1
        vowels = set('aeiouAEIOU')
        for i in range(n):
            cnt += s[i] in vowels
            cnt -= s[i + n] in vowels
        return cnt == 0
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean halvesAreAlike(String s) {
        Set<Character> vowels = Set.of('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U');
        int n = s.length() >> 1;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            cnt += vowels.contains(s.charAt(i)) ? 1 : 0;
            cnt -= vowels.contains(s.charAt(i + n)) ? 1 : 0;
        }
        return cnt == 0;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool halvesAreAlike(string s) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int cnt = 0, n = s.size() / 2;
        for (int i = 0; i < n; ++i) {
            cnt += vowels.count(s[i]);
            cnt -= vowels.count(s[i + n]);
        }
        return cnt == 0;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func halvesAreAlike(s string) bool {
	vowels := map[byte]bool{}
	for _, c := range "aeiouAEIOU" {
		vowels[byte(c)] = true
	}
	cnt, n := 0, len(s)>>1
	for i := 0; i < n; i++ {
		if vowels[s[i]] {
			cnt++
		}
		if vowels[s[i+n]] {
			cnt--
		}
	}
	return cnt == 0
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function halvesAreAlike(s: string): boolean {
    const vowels = new Set('aeiouAEIOU'.split(''));
    let cnt = 0;
    const n = s.length >> 1;
    for (let i = 0; i < n; ++i) {
        cnt += vowels.has(s[i]) ? 1 : 0;
        cnt -= vowels.has(s[n + i]) ? 1 : 0;
    }
    return cnt === 0;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn halves_are_alike(s: String) -> bool {
        let n = s.len() / 2;
        let vowels: std::collections::HashSet<char> = "aeiouAEIOU".chars().collect();
        let mut cnt = 0;

        for i in 0..n {
            if vowels.contains(&s.chars().nth(i).unwrap()) {
                cnt += 1;
            }
            if vowels.contains(&s.chars().nth(i + n).unwrap()) {
                cnt -= 1;
            }
        }

        cnt == 0
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {string} s
 * @return {boolean}
 */
var halvesAreAlike = function (s) {
    const vowels = new Set('aeiouAEIOU'.split(''));
    let cnt = 0;
    const n = s.length >> 1;
    for (let i = 0; i < n; ++i) {
        cnt += vowels.has(s[i]);
        cnt -= vowels.has(s[n + i]);
    }
    return cnt === 0;
};
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param String $s
     * @return Boolean
     */
    function halvesAreAlike($s) {
        $n = strlen($s) / 2;
        $vowels = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'];
        $cnt = 0;

        for ($i = 0; $i < $n; $i++) {
            if (in_array($s[$i], $vowels)) {
                $cnt++;
            }
            if (in_array($s[$i + $n], $vowels)) {
                $cnt--;
            }
        }

        return $cnt == 0;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个偶数长度的字符串 <code>s</code> 。将其拆分成长度相同的两半，前一半为 <code>a</code> ，后一半为 <code>b</code> 。</p>

<p>两个字符串 <strong>相似</strong> 的前提是它们都含有相同数目的元音（<code>'a'</code>，<code>'e'</code>，<code>'i'</code>，<code>'o'</code>，<code>'u'</code>，<code>'A'</code>，<code>'E'</code>，<code>'I'</code>，<code>'O'</code>，<code>'U'</code>）。注意，<code>s</code> 可能同时含有大写和小写字母。</p>

<p>如果<em> </em><code>a</code><em> </em>和<em> </em><code>b</code> 相似，返回 <code>true</code> ；否则，返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "book"
<strong>输出：</strong>true
<strong>解释：</strong>a = "b<strong>o</strong>" 且 b = "<strong>o</strong>k" 。a 中有 1 个元音，b 也有 1 个元音。所以，a 和 b 相似。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "textbook"
<strong>输出：</strong>false
<strong>解释：</strong>a = "t<strong>e</strong>xt" 且 b = "b<strong>oo</strong>k" 。a 中有 1 个元音，b 中有 2 个元音。因此，a 和 b 不相似。
注意，元音 o 在 b 中出现两次，记为 2 个。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s.length</code> 是偶数</li>
	<li><code>s</code> 由 <strong>大写和小写</strong> 字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数

遍历字符串，若字符串前半段的元音个数等于后半段的元音个数，则返回 `true`，否则返回 `false`。

时间复杂度 $O(n)$，其中 $n$ 为字符串的长度。空间复杂度 $O(C)$，其中 $C$ 为元音字母的个数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        cnt, n = 0, len(s) >> 1
        vowels = set('aeiouAEIOU')
        for i in range(n):
            cnt += s[i] in vowels
            cnt -= s[i + n] in vowels
        return cnt == 0
```

#### Java

```java
class Solution {
    public boolean halvesAreAlike(String s) {
        Set<Character> vowels = Set.of('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U');
        int n = s.length() >> 1;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            cnt += vowels.contains(s.charAt(i)) ? 1 : 0;
            cnt -= vowels.contains(s.charAt(i + n)) ? 1 : 0;
        }
        return cnt == 0;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool halvesAreAlike(string s) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int cnt = 0, n = s.size() / 2;
        for (int i = 0; i < n; ++i) {
            cnt += vowels.count(s[i]);
            cnt -= vowels.count(s[i + n]);
        }
        return cnt == 0;
    }
};
```

#### Go

```go
func halvesAreAlike(s string) bool {
	vowels := map[byte]bool{}
	for _, c := range "aeiouAEIOU" {
		vowels[byte(c)] = true
	}
	cnt, n := 0, len(s)>>1
	for i := 0; i < n; i++ {
		if vowels[s[i]] {
			cnt++
		}
		if vowels[s[i+n]] {
			cnt--
		}
	}
	return cnt == 0
}
```

#### TypeScript

```ts
function halvesAreAlike(s: string): boolean {
    const vowels = new Set('aeiouAEIOU'.split(''));
    let cnt = 0;
    const n = s.length >> 1;
    for (let i = 0; i < n; ++i) {
        cnt += vowels.has(s[i]) ? 1 : 0;
        cnt -= vowels.has(s[n + i]) ? 1 : 0;
    }
    return cnt === 0;
}
```

#### Rust

```rust
impl Solution {
    pub fn halves_are_alike(s: String) -> bool {
        let n = s.len() / 2;
        let vowels: std::collections::HashSet<char> = "aeiouAEIOU".chars().collect();
        let mut cnt = 0;

        for i in 0..n {
            if vowels.contains(&s.chars().nth(i).unwrap()) {
                cnt += 1;
            }
            if vowels.contains(&s.chars().nth(i + n).unwrap()) {
                cnt -= 1;
            }
        }

        cnt == 0
    }
}
```

#### JavaScript

```js
/**
 * @param {string} s
 * @return {boolean}
 */
var halvesAreAlike = function (s) {
    const vowels = new Set('aeiouAEIOU'.split(''));
    let cnt = 0;
    const n = s.length >> 1;
    for (let i = 0; i < n; ++i) {
        cnt += vowels.has(s[i]);
        cnt -= vowels.has(s[n + i]);
    }
    return cnt === 0;
};
```

#### PHP

```php
class Solution {
    /**
     * @param String $s
     * @return Boolean
     */
    function halvesAreAlike($s) {
        $n = strlen($s) / 2;
        $vowels = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'];
        $cnt = 0;

        for ($i = 0; $i < $n; $i++) {
            if (in_array($s[$i], $vowels)) {
                $cnt++;
            }
            if (in_array($s[$i + $n], $vowels)) {
                $cnt--;
            }
        }

        return $cnt == 0;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1705. 吃苹果的最大数目](https://leetcode.cn/problems/maximum-number-of-eaten-apples){#1705}

{{< tabs "1705" >}}

{{% tab "python" %}}
```python
class Solution:
    def eatenApples(self, apples: List[int], days: List[int]) -> int:
        n = len(days)
        i = ans = 0
        q = []
        while i < n or q:
            if i < n and apples[i]:
                heappush(q, (i + days[i] - 1, apples[i]))
            while q and q[0][0] < i:
                heappop(q)
            if q:
                t, v = heappop(q)
                v -= 1
                ans += 1
                if v and t > i:
                    heappush(q, (t, v))
            i += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int eatenApples(int[] apples, int[] days) {
        PriorityQueue<int[]> q = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        int n = days.length;
        int ans = 0, i = 0;
        while (i < n || !q.isEmpty()) {
            if (i < n && apples[i] > 0) {
                q.offer(new int[] {i + days[i] - 1, apples[i]});
            }
            while (!q.isEmpty() && q.peek()[0] < i) {
                q.poll();
            }
            if (!q.isEmpty()) {
                var p = q.poll();
                ++ans;
                if (--p[1] > 0 && p[0] > i) {
                    q.offer(p);
                }
            }
            ++i;
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
    int eatenApples(vector<int>& apples, vector<int>& days) {
        using pii = pair<int, int>;
        priority_queue<pii, vector<pii>, greater<pii>> q;
        int n = days.size();
        int ans = 0, i = 0;
        while (i < n || !q.empty()) {
            if (i < n && apples[i]) {
                q.emplace(i + days[i] - 1, apples[i]);
            }
            while (!q.empty() && q.top().first < i) {
                q.pop();
            }
            if (!q.empty()) {
                auto [t, v] = q.top();
                q.pop();
                --v;
                ++ans;
                if (v && t > i) {
                    q.emplace(t, v);
                }
            }
            ++i;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func eatenApples(apples []int, days []int) int {
	var h hp
	ans, n := 0, len(apples)
	for i := 0; i < n || len(h) > 0; i++ {
		if i < n && apples[i] > 0 {
			heap.Push(&h, pair{i + days[i] - 1, apples[i]})
		}
		for len(h) > 0 && h[0].first < i {
			heap.Pop(&h)
		}
		if len(h) > 0 {
			h[0].second--
			if h[0].first == i || h[0].second == 0 {
				heap.Pop(&h)
			}
			ans++
		}
	}
	return ans
}

type pair struct {
	first  int
	second int
}

type hp []pair

func (a hp) Len() int           { return len(a) }
func (a hp) Swap(i, j int)      { a[i], a[j] = a[j], a[i] }
func (a hp) Less(i, j int) bool { return a[i].first < a[j].first }
func (a *hp) Push(x any)        { *a = append(*a, x.(pair)) }
func (a *hp) Pop() any          { l := len(*a); t := (*a)[l-1]; *a = (*a)[:l-1]; return t }
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>有一棵特殊的苹果树，一连 <code>n</code> 天，每天都可以长出若干个苹果。在第 <code>i</code> 天，树上会长出 <code>apples[i]</code> 个苹果，这些苹果将会在 <code>days[i]</code> 天后（也就是说，第 <code>i + days[i]</code> 天时）腐烂，变得无法食用。也可能有那么几天，树上不会长出新的苹果，此时用 <code>apples[i] == 0</code> 且 <code>days[i] == 0</code> 表示。</p>

<p>你打算每天 <strong>最多</strong> 吃一个苹果来保证营养均衡。注意，你可以在这 <code>n</code> 天之后继续吃苹果。</p>

<p>给你两个长度为 <code>n</code> 的整数数组 <code>days</code> 和 <code>apples</code> ，返回你可以吃掉的苹果的最大数目<em>。</em></p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>apples = [1,2,3,5,2], days = [3,2,1,4,2]
<strong>输出：</strong>7
<strong>解释：</strong>你可以吃掉 7 个苹果：
- 第一天，你吃掉第一天长出来的苹果。
- 第二天，你吃掉一个第二天长出来的苹果。
- 第三天，你吃掉一个第二天长出来的苹果。过了这一天，第三天长出来的苹果就已经腐烂了。
- 第四天到第七天，你吃的都是第四天长出来的苹果。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>apples = [3,0,0,0,0,2], days = [3,0,0,0,0,2]
<strong>输出：</strong>5
<strong>解释：</strong>你可以吃掉 5 个苹果：
- 第一天到第三天，你吃的都是第一天长出来的苹果。
- 第四天和第五天不吃苹果。
- 第六天和第七天，你吃的都是第六天长出来的苹果。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>apples.length == n</code></li>
	<li><code>days.length == n</code></li>
	<li><code>1 &lt;= n &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>0 &lt;= apples[i], days[i] &lt;= 2 * 10<sup>4</sup></code></li>
	<li>只有在 <code>apples[i] = 0</code> 时，<code>days[i] = 0</code> 才成立</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 优先队列

我们可以贪心地在未腐烂的苹果中优先选择最容易腐烂的苹果，这样可以使得吃到的苹果尽可能多。

因此，我们可以用优先队列（小根堆）存储苹果的腐烂时间以及对应苹果的数量，每次从优先队列中取出腐烂时间最小的苹果，然后将其数量减一，若减一后苹果的数量不为零，则将其重新放入优先队列中。若苹果已经腐烂，则从优先队列中弹出。

时间复杂度 $O(n \times \log n + M)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $\textit{days}$ 的长度，而 $M = \max(\textit{days})$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def eatenApples(self, apples: List[int], days: List[int]) -> int:
        n = len(days)
        i = ans = 0
        q = []
        while i < n or q:
            if i < n and apples[i]:
                heappush(q, (i + days[i] - 1, apples[i]))
            while q and q[0][0] < i:
                heappop(q)
            if q:
                t, v = heappop(q)
                v -= 1
                ans += 1
                if v and t > i:
                    heappush(q, (t, v))
            i += 1
        return ans
```

#### Java

```java
class Solution {
    public int eatenApples(int[] apples, int[] days) {
        PriorityQueue<int[]> q = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        int n = days.length;
        int ans = 0, i = 0;
        while (i < n || !q.isEmpty()) {
            if (i < n && apples[i] > 0) {
                q.offer(new int[] {i + days[i] - 1, apples[i]});
            }
            while (!q.isEmpty() && q.peek()[0] < i) {
                q.poll();
            }
            if (!q.isEmpty()) {
                var p = q.poll();
                ++ans;
                if (--p[1] > 0 && p[0] > i) {
                    q.offer(p);
                }
            }
            ++i;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        using pii = pair<int, int>;
        priority_queue<pii, vector<pii>, greater<pii>> q;
        int n = days.size();
        int ans = 0, i = 0;
        while (i < n || !q.empty()) {
            if (i < n && apples[i]) {
                q.emplace(i + days[i] - 1, apples[i]);
            }
            while (!q.empty() && q.top().first < i) {
                q.pop();
            }
            if (!q.empty()) {
                auto [t, v] = q.top();
                q.pop();
                --v;
                ++ans;
                if (v && t > i) {
                    q.emplace(t, v);
                }
            }
            ++i;
        }
        return ans;
    }
};
```

#### Go

```go
func eatenApples(apples []int, days []int) int {
	var h hp
	ans, n := 0, len(apples)
	for i := 0; i < n || len(h) > 0; i++ {
		if i < n && apples[i] > 0 {
			heap.Push(&h, pair{i + days[i] - 1, apples[i]})
		}
		for len(h) > 0 && h[0].first < i {
			heap.Pop(&h)
		}
		if len(h) > 0 {
			h[0].second--
			if h[0].first == i || h[0].second == 0 {
				heap.Pop(&h)
			}
			ans++
		}
	}
	return ans
}

type pair struct {
	first  int
	second int
}

type hp []pair

func (a hp) Len() int           { return len(a) }
func (a hp) Swap(i, j int)      { a[i], a[j] = a[j], a[i] }
func (a hp) Less(i, j int) bool { return a[i].first < a[j].first }
func (a *hp) Push(x any)        { *a = append(*a, x.(pair)) }
func (a *hp) Pop() any          { l := len(*a); t := (*a)[l-1]; *a = (*a)[:l-1]; return t }
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1706. 球会落何处](https://leetcode.cn/problems/where-will-the-ball-fall){#1706}

{{< tabs "1706" >}}

{{% tab "python" %}}
```python
class Solution:
    def findBall(self, grid: List[List[int]]) -> List[int]:
        def dfs(i: int, j: int) -> int:
            if i == m:
                return j
            if j == 0 and grid[i][j] == -1:
                return -1
            if j == n - 1 and grid[i][j] == 1:
                return -1
            if grid[i][j] == 1 and grid[i][j + 1] == -1:
                return -1
            if grid[i][j] == -1 and grid[i][j - 1] == 1:
                return -1
            return dfs(i + 1, j + 1) if grid[i][j] == 1 else dfs(i + 1, j - 1)

        m, n = len(grid), len(grid[0])
        return [dfs(0, j) for j in range(n)]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int m;
    private int n;
    private int[][] grid;

    public int[] findBall(int[][] grid) {
        m = grid.length;
        n = grid[0].length;
        this.grid = grid;
        int[] ans = new int[n];
        for (int j = 0; j < n; ++j) {
            ans[j] = dfs(0, j);
        }
        return ans;
    }

    private int dfs(int i, int j) {
        if (i == m) {
            return j;
        }
        if (j == 0 && grid[i][j] == -1) {
            return -1;
        }
        if (j == n - 1 && grid[i][j] == 1) {
            return -1;
        }
        if (grid[i][j] == 1 && grid[i][j + 1] == -1) {
            return -1;
        }
        if (grid[i][j] == -1 && grid[i][j - 1] == 1) {
            return -1;
        }
        return grid[i][j] == 1 ? dfs(i + 1, j + 1) : dfs(i + 1, j - 1);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> ans(n);
        function<int(int, int)> dfs = [&](int i, int j) {
            if (i == m) {
                return j;
            }
            if (j == 0 && grid[i][j] == -1) {
                return -1;
            }
            if (j == n - 1 && grid[i][j] == 1) {
                return -1;
            }
            if (grid[i][j] == 1 && grid[i][j + 1] == -1) {
                return -1;
            }
            if (grid[i][j] == -1 && grid[i][j - 1] == 1) {
                return -1;
            }
            return grid[i][j] == 1 ? dfs(i + 1, j + 1) : dfs(i + 1, j - 1);
        };
        for (int j = 0; j < n; ++j) {
            ans[j] = dfs(0, j);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findBall(grid [][]int) (ans []int) {
	m, n := len(grid), len(grid[0])
	var dfs func(i, j int) int
	dfs = func(i, j int) int {
		if i == m {
			return j
		}
		if j == 0 && grid[i][j] == -1 {
			return -1
		}
		if j == n-1 && grid[i][j] == 1 {
			return -1
		}
		if grid[i][j] == 1 && grid[i][j+1] == -1 {
			return -1
		}
		if grid[i][j] == -1 && grid[i][j-1] == 1 {
			return -1
		}
		if grid[i][j] == 1 {
			return dfs(i+1, j+1)
		}
		return dfs(i+1, j-1)
	}
	for j := 0; j < n; j++ {
		ans = append(ans, dfs(0, j))
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findBall(grid: number[][]): number[] {
    const m = grid.length;
    const n = grid[0].length;
    const dfs = (i: number, j: number) => {
        if (i === m) {
            return j;
        }
        if (grid[i][j] === 1) {
            if (j === n - 1 || grid[i][j + 1] === -1) {
                return -1;
            }
            return dfs(i + 1, j + 1);
        } else {
            if (j === 0 || grid[i][j - 1] === 1) {
                return -1;
            }
            return dfs(i + 1, j - 1);
        }
    };
    return Array.from({ length: n }, (_, j) => dfs(0, j));
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    fn dfs(grid: &Vec<Vec<i32>>, i: usize, j: usize) -> i32 {
        if i == grid.len() {
            return j as i32;
        }
        if grid[i][j] == 1 {
            if j == grid[0].len() - 1 || grid[i][j + 1] == -1 {
                return -1;
            }
            Self::dfs(grid, i + 1, j + 1)
        } else {
            if j == 0 || grid[i][j - 1] == 1 {
                return -1;
            }
            Self::dfs(grid, i + 1, j - 1)
        }
    }

    pub fn find_ball(grid: Vec<Vec<i32>>) -> Vec<i32> {
        let m = grid.len();
        let n = grid[0].len();
        let mut ans = vec![0; n];
        for i in 0..n {
            ans[i] = Self::dfs(&grid, 0, i);
        }
        ans
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[][]} grid
 * @return {number[]}
 */
var findBall = function (grid) {
    const m = grid.length;
    const n = grid[0].length;
    const dfs = (i, j) => {
        if (i === m) {
            return j;
        }
        if (grid[i][j] === 1) {
            if (j === n - 1 || grid[i][j + 1] === -1) {
                return -1;
            }
            return dfs(i + 1, j + 1);
        } else {
            if (j === 0 || grid[i][j - 1] === 1) {
                return -1;
            }
            return dfs(i + 1, j - 1);
        }
    };
    return Array.from({ length: n }, (_, j) => dfs(0, j));
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>用一个大小为 <code>m x n</code> 的二维网格 <code>grid</code> 表示一个箱子。你有 <code>n</code> 颗球。箱子的顶部和底部都是开着的。</p>

<p>箱子中的每个单元格都有一个对角线挡板，跨过单元格的两个角，可以将球导向左侧或者右侧。</p>

<ul>
	<li>将球导向右侧的挡板跨过左上角和右下角，在网格中用 <code>1</code> 表示。</li>
	<li>将球导向左侧的挡板跨过右上角和左下角，在网格中用 <code>-1</code> 表示。</li>
</ul>

<p>在箱子每一列的顶端各放一颗球。每颗球都可能卡在箱子里或从底部掉出来。如果球恰好卡在两块挡板之间的 "V" 形图案，或者被一块挡导向到箱子的任意一侧边上，就会卡住。</p>

<p>返回一个大小为 <code>n</code> 的数组 <code>answer</code> ，其中 <code>answer[i]</code> 是球放在顶部的第 <code>i</code> 列后从底部掉出来的那一列对应的下标，如果球卡在盒子里，则返回 <code>-1</code> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1700-1799/1706.Where%20Will%20the%20Ball%20Fall/images/ball.jpg" style="width: 500px; height: 385px;" /></strong></p>

<pre>
<strong>输入：</strong>grid = [[1,1,1,-1,-1],[1,1,1,-1,-1],[-1,-1,-1,1,1],[1,1,1,1,-1],[-1,-1,-1,-1,-1]]
<strong>输出：</strong>[1,-1,-1,-1,-1]
<strong>解释：</strong>示例如图：
b0 球开始放在第 0 列上，最终从箱子底部第 1 列掉出。
b1 球开始放在第 1 列上，会卡在第 2、3 列和第 1 行之间的 "V" 形里。
b2 球开始放在第 2 列上，会卡在第 2、3 列和第 0 行之间的 "V" 形里。
b3 球开始放在第 3 列上，会卡在第 2、3 列和第 0 行之间的 "V" 形里。
b4 球开始放在第 4 列上，会卡在第 2、3 列和第 1 行之间的 "V" 形里。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>grid = [[-1]]
<strong>输出：</strong>[-1]
<strong>解释：</strong>球被卡在箱子左侧边上。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>grid = [[1,1,1,1,1,1],[-1,-1,-1,-1,-1,-1],[1,1,1,1,1,1],[-1,-1,-1,-1,-1,-1]]
<strong>输出：</strong>[0,1,2,3,4,-1]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 <= m, n <= 100</code></li>
	<li><code>grid[i][j]</code> 为 <code>1</code> 或 <code>-1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：分情况讨论 + DFS

我们可以使用 DFS 来模拟球的运动过程，设计一个函数 $\textit{dfs}(i, j)$，表示球从第 $i$ 行第 $j$ 列出发，最终会落在第几列。对于以下情况，球会卡住：

1. 球位于最左一列，并且球所在的单元格单元格挡板将球导向左侧
1. 球位于最右一列，并且此单元格挡板将球导向右侧
1. 球所在的单元格挡板将球导向右侧，并且球右侧相邻单元格挡板将球导向左侧
1. 球所在的单元格挡板将球导向左侧，并且球左侧相邻单元格挡板将球导向右侧

如果满足以上任意一种情况，我们就可以判断球会卡住，返回 $-1$。否则，我们就可以继续递归地寻找球的下一个位置。最后，如果球到了最后一行，我们就可以返回当前列的编号。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m)$。其中 $m$ 和 $n$ 分别是数组 $\textit{grid}$ 的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findBall(self, grid: List[List[int]]) -> List[int]:
        def dfs(i: int, j: int) -> int:
            if i == m:
                return j
            if j == 0 and grid[i][j] == -1:
                return -1
            if j == n - 1 and grid[i][j] == 1:
                return -1
            if grid[i][j] == 1 and grid[i][j + 1] == -1:
                return -1
            if grid[i][j] == -1 and grid[i][j - 1] == 1:
                return -1
            return dfs(i + 1, j + 1) if grid[i][j] == 1 else dfs(i + 1, j - 1)

        m, n = len(grid), len(grid[0])
        return [dfs(0, j) for j in range(n)]
```

#### Java

```java
class Solution {
    private int m;
    private int n;
    private int[][] grid;

    public int[] findBall(int[][] grid) {
        m = grid.length;
        n = grid[0].length;
        this.grid = grid;
        int[] ans = new int[n];
        for (int j = 0; j < n; ++j) {
            ans[j] = dfs(0, j);
        }
        return ans;
    }

    private int dfs(int i, int j) {
        if (i == m) {
            return j;
        }
        if (j == 0 && grid[i][j] == -1) {
            return -1;
        }
        if (j == n - 1 && grid[i][j] == 1) {
            return -1;
        }
        if (grid[i][j] == 1 && grid[i][j + 1] == -1) {
            return -1;
        }
        if (grid[i][j] == -1 && grid[i][j - 1] == 1) {
            return -1;
        }
        return grid[i][j] == 1 ? dfs(i + 1, j + 1) : dfs(i + 1, j - 1);
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> ans(n);
        function<int(int, int)> dfs = [&](int i, int j) {
            if (i == m) {
                return j;
            }
            if (j == 0 && grid[i][j] == -1) {
                return -1;
            }
            if (j == n - 1 && grid[i][j] == 1) {
                return -1;
            }
            if (grid[i][j] == 1 && grid[i][j + 1] == -1) {
                return -1;
            }
            if (grid[i][j] == -1 && grid[i][j - 1] == 1) {
                return -1;
            }
            return grid[i][j] == 1 ? dfs(i + 1, j + 1) : dfs(i + 1, j - 1);
        };
        for (int j = 0; j < n; ++j) {
            ans[j] = dfs(0, j);
        }
        return ans;
    }
};
```

#### Go

```go
func findBall(grid [][]int) (ans []int) {
	m, n := len(grid), len(grid[0])
	var dfs func(i, j int) int
	dfs = func(i, j int) int {
		if i == m {
			return j
		}
		if j == 0 && grid[i][j] == -1 {
			return -1
		}
		if j == n-1 && grid[i][j] == 1 {
			return -1
		}
		if grid[i][j] == 1 && grid[i][j+1] == -1 {
			return -1
		}
		if grid[i][j] == -1 && grid[i][j-1] == 1 {
			return -1
		}
		if grid[i][j] == 1 {
			return dfs(i+1, j+1)
		}
		return dfs(i+1, j-1)
	}
	for j := 0; j < n; j++ {
		ans = append(ans, dfs(0, j))
	}
	return
}
```

#### TypeScript

```ts
function findBall(grid: number[][]): number[] {
    const m = grid.length;
    const n = grid[0].length;
    const dfs = (i: number, j: number) => {
        if (i === m) {
            return j;
        }
        if (grid[i][j] === 1) {
            if (j === n - 1 || grid[i][j + 1] === -1) {
                return -1;
            }
            return dfs(i + 1, j + 1);
        } else {
            if (j === 0 || grid[i][j - 1] === 1) {
                return -1;
            }
            return dfs(i + 1, j - 1);
        }
    };
    return Array.from({ length: n }, (_, j) => dfs(0, j));
}
```

#### Rust

```rust
impl Solution {
    fn dfs(grid: &Vec<Vec<i32>>, i: usize, j: usize) -> i32 {
        if i == grid.len() {
            return j as i32;
        }
        if grid[i][j] == 1 {
            if j == grid[0].len() - 1 || grid[i][j + 1] == -1 {
                return -1;
            }
            Self::dfs(grid, i + 1, j + 1)
        } else {
            if j == 0 || grid[i][j - 1] == 1 {
                return -1;
            }
            Self::dfs(grid, i + 1, j - 1)
        }
    }

    pub fn find_ball(grid: Vec<Vec<i32>>) -> Vec<i32> {
        let m = grid.len();
        let n = grid[0].len();
        let mut ans = vec![0; n];
        for i in 0..n {
            ans[i] = Self::dfs(&grid, 0, i);
        }
        ans
    }
}
```

#### JavaScript

```js
/**
 * @param {number[][]} grid
 * @return {number[]}
 */
var findBall = function (grid) {
    const m = grid.length;
    const n = grid[0].length;
    const dfs = (i, j) => {
        if (i === m) {
            return j;
        }
        if (grid[i][j] === 1) {
            if (j === n - 1 || grid[i][j + 1] === -1) {
                return -1;
            }
            return dfs(i + 1, j + 1);
        } else {
            if (j === 0 || grid[i][j - 1] === 1) {
                return -1;
            }
            return dfs(i + 1, j - 1);
        }
    };
    return Array.from({ length: n }, (_, j) => dfs(0, j));
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1707. 与数组中元素的最大异或值](https://leetcode.cn/problems/maximum-xor-with-an-element-from-array){#1707}

{{< tabs "1707" >}}

{{% tab "python" %}}
```python
class Trie:
    __slots__ = ["children"]

    def __init__(self):
        self.children = [None] * 2

    def insert(self, x: int):
        node = self
        for i in range(30, -1, -1):
            v = x >> i & 1
            if node.children[v] is None:
                node.children[v] = Trie()
            node = node.children[v]

    def search(self, x: int) -> int:
        node = self
        ans = 0
        for i in range(30, -1, -1):
            v = x >> i & 1
            if node.children[v ^ 1]:
                ans |= 1 << i
                node = node.children[v ^ 1]
            elif node.children[v]:
                node = node.children[v]
            else:
                return -1
        return ans


class Solution:
    def maximizeXor(self, nums: List[int], queries: List[List[int]]) -> List[int]:
        trie = Trie()
        nums.sort()
        j, n = 0, len(queries)
        ans = [-1] * n
        for i, (x, m) in sorted(zip(range(n), queries), key=lambda x: x[1][1]):
            while j < len(nums) and nums[j] <= m:
                trie.insert(nums[j])
                j += 1
            ans[i] = trie.search(x)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Trie {
    private Trie[] children = new Trie[2];

    public void insert(int x) {
        Trie node = this;
        for (int i = 30; i >= 0; --i) {
            int v = x >> i & 1;
            if (node.children[v] == null) {
                node.children[v] = new Trie();
            }
            node = node.children[v];
        }
    }

    public int search(int x) {
        Trie node = this;
        int ans = 0;
        for (int i = 30; i >= 0; --i) {
            int v = x >> i & 1;
            if (node.children[v ^ 1] != null) {
                ans |= 1 << i;
                node = node.children[v ^ 1];
            } else if (node.children[v] != null) {
                node = node.children[v];
            } else {
                return -1;
            }
        }
        return ans;
    }
}

class Solution {
    public int[] maximizeXor(int[] nums, int[][] queries) {
        Arrays.sort(nums);
        int n = queries.length;
        Integer[] idx = new Integer[n];
        Arrays.setAll(idx, i -> i);
        Arrays.sort(idx, (i, j) -> queries[i][1] - queries[j][1]);
        int[] ans = new int[n];
        Trie trie = new Trie();
        int j = 0;
        for (int i : idx) {
            int x = queries[i][0], m = queries[i][1];
            while (j < nums.length && nums[j] <= m) {
                trie.insert(nums[j++]);
            }
            ans[i] = trie.search(x);
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Trie {
private:
    Trie* children[2];

public:
    Trie()
        : children{nullptr, nullptr} {}

    void insert(int x) {
        Trie* node = this;
        for (int i = 30; ~i; --i) {
            int v = (x >> i) & 1;
            if (!node->children[v]) {
                node->children[v] = new Trie();
            }
            node = node->children[v];
        }
    }

    int search(int x) {
        Trie* node = this;
        int ans = 0;
        for (int i = 30; ~i; --i) {
            int v = (x >> i) & 1;
            if (node->children[v ^ 1]) {
                ans |= 1 << i;
                node = node->children[v ^ 1];
            } else if (node->children[v]) {
                node = node->children[v];
            } else {
                return -1;
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());
        int n = queries.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int i, int j) { return queries[i][1] < queries[j][1]; });
        vector<int> ans(n);
        Trie trie;
        int j = 0;
        for (int i : idx) {
            int x = queries[i][0], m = queries[i][1];
            while (j < nums.size() && nums[j] <= m) {
                trie.insert(nums[j++]);
            }
            ans[i] = trie.search(x);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
type Trie struct {
	children [2]*Trie
}

func NewTrie() *Trie {
	return &Trie{}
}

func (t *Trie) insert(x int) {
	node := t
	for i := 30; i >= 0; i-- {
		v := x >> i & 1
		if node.children[v] == nil {
			node.children[v] = NewTrie()
		}
		node = node.children[v]
	}
}

func (t *Trie) search(x int) int {
	node := t
	ans := 0
	for i := 30; i >= 0; i-- {
		v := x >> i & 1
		if node.children[v^1] != nil {
			ans |= 1 << i
			node = node.children[v^1]
		} else if node.children[v] != nil {
			node = node.children[v]
		} else {
			return -1
		}
	}
	return ans
}

func maximizeXor(nums []int, queries [][]int) []int {
	sort.Ints(nums)
	n := len(queries)
	idx := make([]int, n)
	for i := 0; i < n; i++ {
		idx[i] = i
	}
	sort.Slice(idx, func(i, j int) bool {
		return queries[idx[i]][1] < queries[idx[j]][1]
	})
	ans := make([]int, n)
	trie := NewTrie()
	j := 0
	for _, i := range idx {
		x, m := queries[i][0], queries[i][1]
		for j < len(nums) && nums[j] <= m {
			trie.insert(nums[j])
			j++
		}
		ans[i] = trie.search(x)
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class Trie {
    children: (Trie | null)[];

    constructor() {
        this.children = [null, null];
    }

    insert(x: number): void {
        let node: Trie | null = this;
        for (let i = 30; ~i; i--) {
            const v = (x >> i) & 1;
            if (node.children[v] === null) {
                node.children[v] = new Trie();
            }
            node = node.children[v] as Trie;
        }
    }

    search(x: number): number {
        let node: Trie | null = this;
        let ans = 0;
        for (let i = 30; ~i; i--) {
            const v = (x >> i) & 1;
            if (node.children[v ^ 1] !== null) {
                ans |= 1 << i;
                node = node.children[v ^ 1] as Trie;
            } else if (node.children[v] !== null) {
                node = node.children[v] as Trie;
            } else {
                return -1;
            }
        }
        return ans;
    }
}

function maximizeXor(nums: number[], queries: number[][]): number[] {
    nums.sort((a, b) => a - b);
    const n = queries.length;
    const idx = Array.from({ length: n }, (_, i) => i);
    idx.sort((i, j) => queries[i][1] - queries[j][1]);
    const ans: number[] = [];
    const trie = new Trie();
    let j = 0;
    for (const i of idx) {
        const x = queries[i][0];
        const m = queries[i][1];
        while (j < nums.length && nums[j] <= m) {
            trie.insert(nums[j++]);
        }
        ans[i] = trie.search(x);
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

<p>给你一个由非负整数组成的数组 <code>nums</code> 。另有一个查询数组 <code>queries</code> ，其中 <code>queries[i] = [x<sub>i</sub>, m<sub>i</sub>]</code> 。</p>

<p>第 <code>i</code> 个查询的答案是 <code>x<sub>i</sub></code> 和任何 <code>nums</code> 数组中不超过 <code>m<sub>i</sub></code> 的元素按位异或（<code>XOR</code>）得到的最大值。换句话说，答案是 <code>max(nums[j] XOR x<sub>i</sub>)</code> ，其中所有 <code>j</code> 均满足 <code>nums[j] &lt;= m<sub>i</sub></code> 。如果 <code>nums</code> 中的所有元素都大于 <code>m<sub>i</sub></code>，最终答案就是 <code>-1</code> 。</p>

<p>返回一个整数数组<em> </em><code>answer</code><em> </em>作为查询的答案，其中<em> </em><code>answer.length == queries.length</code><em> </em>且<em> </em><code>answer[i]</code><em> </em>是第<em> </em><code>i</code><em> </em>个查询的答案。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [0,1,2,3,4], queries = [[3,1],[1,3],[5,6]]
<strong>输出：</strong>[3,3,7]
<strong>解释：</strong>
1) 0 和 1 是仅有的两个不超过 1 的整数。0 XOR 3 = 3 而 1 XOR 3 = 2 。二者中的更大值是 3 。
2) 1 XOR 2 = 3.
3) 5 XOR 2 = 7.
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [5,2,4,6,6,3], queries = [[12,4],[8,1],[6,3]]
<strong>输出：</strong>[15,-1,5]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length, queries.length &lt;= 10<sup>5</sup></code></li>
	<li><code>queries[i].length == 2</code></li>
	<li><code>0 &lt;= nums[j], x<sub>i</sub>, m<sub>i</sub> &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：离线查询 + 0-1 字典树

根据题目描述我们知道，每个查询相互独立，并且查询的结果与 $nums$ 中的元素顺序无关，因此，我们考虑将所有的查询按照 $m_i$ 从小到大排序，并且将 $nums$ 从小到大排序。

接下来，我们使用一个 $0-1$ 字典树来维护 $nums$ 中的元素。我们用一个指针 $j$ 来记录当前字典树中的元素，初始时 $j=0$。对于每个查询 $[x_i, m_i]$，我们不断地将 $nums$ 中的元素插入到字典树中，直到 $nums[j] > m_i$，此时我们就可以在字典树中查询到所有不超过 $m_i$ 的元素，我们将其中与 $x_i$ 异或值最大的元素的异或值作为答案。

时间复杂度 $O(m \times \log m + n \times (\log n + \log M))$，空间复杂度 $O(n \times \log M)$，其中 $m$ 和 $n$ 分别是数组 $nums$ 和 $queries$ 的长度，而 $M$ 是数组 $nums$ 中的最大值，本题中 $M \le 10^9$。

<!-- tabs:start -->

#### Python3

```python
class Trie:
    __slots__ = ["children"]

    def __init__(self):
        self.children = [None] * 2

    def insert(self, x: int):
        node = self
        for i in range(30, -1, -1):
            v = x >> i & 1
            if node.children[v] is None:
                node.children[v] = Trie()
            node = node.children[v]

    def search(self, x: int) -> int:
        node = self
        ans = 0
        for i in range(30, -1, -1):
            v = x >> i & 1
            if node.children[v ^ 1]:
                ans |= 1 << i
                node = node.children[v ^ 1]
            elif node.children[v]:
                node = node.children[v]
            else:
                return -1
        return ans


class Solution:
    def maximizeXor(self, nums: List[int], queries: List[List[int]]) -> List[int]:
        trie = Trie()
        nums.sort()
        j, n = 0, len(queries)
        ans = [-1] * n
        for i, (x, m) in sorted(zip(range(n), queries), key=lambda x: x[1][1]):
            while j < len(nums) and nums[j] <= m:
                trie.insert(nums[j])
                j += 1
            ans[i] = trie.search(x)
        return ans
```

#### Java

```java
class Trie {
    private Trie[] children = new Trie[2];

    public void insert(int x) {
        Trie node = this;
        for (int i = 30; i >= 0; --i) {
            int v = x >> i & 1;
            if (node.children[v] == null) {
                node.children[v] = new Trie();
            }
            node = node.children[v];
        }
    }

    public int search(int x) {
        Trie node = this;
        int ans = 0;
        for (int i = 30; i >= 0; --i) {
            int v = x >> i & 1;
            if (node.children[v ^ 1] != null) {
                ans |= 1 << i;
                node = node.children[v ^ 1];
            } else if (node.children[v] != null) {
                node = node.children[v];
            } else {
                return -1;
            }
        }
        return ans;
    }
}

class Solution {
    public int[] maximizeXor(int[] nums, int[][] queries) {
        Arrays.sort(nums);
        int n = queries.length;
        Integer[] idx = new Integer[n];
        Arrays.setAll(idx, i -> i);
        Arrays.sort(idx, (i, j) -> queries[i][1] - queries[j][1]);
        int[] ans = new int[n];
        Trie trie = new Trie();
        int j = 0;
        for (int i : idx) {
            int x = queries[i][0], m = queries[i][1];
            while (j < nums.length && nums[j] <= m) {
                trie.insert(nums[j++]);
            }
            ans[i] = trie.search(x);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Trie {
private:
    Trie* children[2];

public:
    Trie()
        : children{nullptr, nullptr} {}

    void insert(int x) {
        Trie* node = this;
        for (int i = 30; ~i; --i) {
            int v = (x >> i) & 1;
            if (!node->children[v]) {
                node->children[v] = new Trie();
            }
            node = node->children[v];
        }
    }

    int search(int x) {
        Trie* node = this;
        int ans = 0;
        for (int i = 30; ~i; --i) {
            int v = (x >> i) & 1;
            if (node->children[v ^ 1]) {
                ans |= 1 << i;
                node = node->children[v ^ 1];
            } else if (node->children[v]) {
                node = node->children[v];
            } else {
                return -1;
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());
        int n = queries.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int i, int j) { return queries[i][1] < queries[j][1]; });
        vector<int> ans(n);
        Trie trie;
        int j = 0;
        for (int i : idx) {
            int x = queries[i][0], m = queries[i][1];
            while (j < nums.size() && nums[j] <= m) {
                trie.insert(nums[j++]);
            }
            ans[i] = trie.search(x);
        }
        return ans;
    }
};
```

#### Go

```go
type Trie struct {
	children [2]*Trie
}

func NewTrie() *Trie {
	return &Trie{}
}

func (t *Trie) insert(x int) {
	node := t
	for i := 30; i >= 0; i-- {
		v := x >> i & 1
		if node.children[v] == nil {
			node.children[v] = NewTrie()
		}
		node = node.children[v]
	}
}

func (t *Trie) search(x int) int {
	node := t
	ans := 0
	for i := 30; i >= 0; i-- {
		v := x >> i & 1
		if node.children[v^1] != nil {
			ans |= 1 << i
			node = node.children[v^1]
		} else if node.children[v] != nil {
			node = node.children[v]
		} else {
			return -1
		}
	}
	return ans
}

func maximizeXor(nums []int, queries [][]int) []int {
	sort.Ints(nums)
	n := len(queries)
	idx := make([]int, n)
	for i := 0; i < n; i++ {
		idx[i] = i
	}
	sort.Slice(idx, func(i, j int) bool {
		return queries[idx[i]][1] < queries[idx[j]][1]
	})
	ans := make([]int, n)
	trie := NewTrie()
	j := 0
	for _, i := range idx {
		x, m := queries[i][0], queries[i][1]
		for j < len(nums) && nums[j] <= m {
			trie.insert(nums[j])
			j++
		}
		ans[i] = trie.search(x)
	}
	return ans
}
```

#### TypeScript

```ts
class Trie {
    children: (Trie | null)[];

    constructor() {
        this.children = [null, null];
    }

    insert(x: number): void {
        let node: Trie | null = this;
        for (let i = 30; ~i; i--) {
            const v = (x >> i) & 1;
            if (node.children[v] === null) {
                node.children[v] = new Trie();
            }
            node = node.children[v] as Trie;
        }
    }

    search(x: number): number {
        let node: Trie | null = this;
        let ans = 0;
        for (let i = 30; ~i; i--) {
            const v = (x >> i) & 1;
            if (node.children[v ^ 1] !== null) {
                ans |= 1 << i;
                node = node.children[v ^ 1] as Trie;
            } else if (node.children[v] !== null) {
                node = node.children[v] as Trie;
            } else {
                return -1;
            }
        }
        return ans;
    }
}

function maximizeXor(nums: number[], queries: number[][]): number[] {
    nums.sort((a, b) => a - b);
    const n = queries.length;
    const idx = Array.from({ length: n }, (_, i) => i);
    idx.sort((i, j) => queries[i][1] - queries[j][1]);
    const ans: number[] = [];
    const trie = new Trie();
    let j = 0;
    for (const i of idx) {
        const x = queries[i][0];
        const m = queries[i][1];
        while (j < nums.length && nums[j] <= m) {
            trie.insert(nums[j++]);
        }
        ans[i] = trie.search(x);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1708. 长度为 K 的最大子数组 🔒](https://leetcode.cn/problems/largest-subarray-length-k){#1708}

{{< tabs "1708" >}}

{{% tab "python" %}}
```python
class Solution:
    def largestSubarray(self, nums: List[int], k: int) -> List[int]:
        i = nums.index(max(nums[: len(nums) - k + 1]))
        return nums[i : i + k]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] largestSubarray(int[] nums, int k) {
        int j = 0;
        for (int i = 1; i < nums.length - k + 1; ++i) {
            if (nums[j] < nums[i]) {
                j = i;
            }
        }
        return Arrays.copyOfRange(nums, j, j + k);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> largestSubarray(vector<int>& nums, int k) {
        auto i = max_element(nums.begin(), nums.end() - k + 1);
        return {i, i + k};
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func largestSubarray(nums []int, k int) []int {
	j := 0
	for i := 1; i < len(nums)-k+1; i++ {
		if nums[j] < nums[i] {
			j = i
		}
	}
	return nums[j : j+k]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function largestSubarray(nums: number[], k: number): number[] {
    let j = 0;
    for (let i = 1; i < nums.length - k + 1; ++i) {
        if (nums[j] < nums[i]) {
            j = i;
        }
    }
    return nums.slice(j, j + k);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn largest_subarray(nums: Vec<i32>, k: i32) -> Vec<i32> {
        let mut j = 0;
        for i in 1..=nums.len() - (k as usize) {
            if nums[i] > nums[j] {
                j = i;
            }
        }
        nums[j..j + (k as usize)].to_vec()
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>在数组&nbsp;<code>A</code>&nbsp;和数组 <code>B</code>&nbsp;中，对于第一个满足 <code>A[i] != B[i]</code>&nbsp;的索引&nbsp;<code>i</code>&nbsp;，当 <code>A[i] &gt; B[i]</code>&nbsp;时，数组 <code>A</code> 大于数组 <code>B</code>。</p>

<p>例如，对于索引从 <code>0</code> 开始的数组：</p>

<ul>
	<li><code>[1,3,2,4] &gt; [1,2,2,4]</code>&nbsp;，因为在索引&nbsp;<code>1</code>&nbsp;上，&nbsp;<code>3 &gt; 2</code>。</li>
	<li><code>[1,4,4,4] &lt; [2,1,1,1]</code>&nbsp;，因为在索引 <code>0</code> 上，&nbsp;<code>1 &lt; 2</code>。</li>
</ul>

<p>一个数组的子数组是原数组上的一个连续子序列。</p>

<p>给定一个包含<strong>不同</strong>整数的整数类型数组&nbsp;<code>nums</code>&nbsp;，返回&nbsp;<code>nums</code>&nbsp;中长度为 <code>k</code> 的最大子数组。</p>

<p>&nbsp;</p>

<p><b>示例 1:</b></p>

<pre>
<strong>输入:</strong> nums = [1,4,5,2,3], k = 3
<strong>输出:</strong> [5,2,3]
<strong>解释:</strong> 长度为 3 的子数组有： [1,4,5]、 [4,5,2] 和 [5,2,3]。
在这些数组中， [5,2,3] 是最大的。</pre>

<p><b>示例</b><strong> 2:</strong></p>

<pre>
<strong>输入:</strong> nums = [1,4,5,2,3], k = 4
<strong>输出:</strong> [4,5,2,3]
<strong>解释:</strong> 长度为 4 的子数组有： [1,4,5,2] 和 [4,5,2,3]。
在这些数组中， [4,5,2,3] 是最大的。</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入:</strong> nums = [1,4,5,2,3], k = 1
<strong>输出:</strong> [5]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>nums</code>&nbsp;中的所有整数都是<strong>不同</strong>的。</li>
</ul>

<p>&nbsp;</p>
<b>进阶：</b>如果允许&nbsp;<code>nums</code>&nbsp;中存在相同元素，你该如何解决该问题？

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

数组中所有整数都不同，我们可以先在 $[0,..n-k]$ 范围内找到最大的元素的下标，然后从该下标开始取 $k$ 个元素即可。

时间复杂度 $O(n)$，其中 $n$ 为数组的长度。忽略答案的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def largestSubarray(self, nums: List[int], k: int) -> List[int]:
        i = nums.index(max(nums[: len(nums) - k + 1]))
        return nums[i : i + k]
```

#### Java

```java
class Solution {
    public int[] largestSubarray(int[] nums, int k) {
        int j = 0;
        for (int i = 1; i < nums.length - k + 1; ++i) {
            if (nums[j] < nums[i]) {
                j = i;
            }
        }
        return Arrays.copyOfRange(nums, j, j + k);
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> largestSubarray(vector<int>& nums, int k) {
        auto i = max_element(nums.begin(), nums.end() - k + 1);
        return {i, i + k};
    }
};
```

#### Go

```go
func largestSubarray(nums []int, k int) []int {
	j := 0
	for i := 1; i < len(nums)-k+1; i++ {
		if nums[j] < nums[i] {
			j = i
		}
	}
	return nums[j : j+k]
}
```

#### TypeScript

```ts
function largestSubarray(nums: number[], k: number): number[] {
    let j = 0;
    for (let i = 1; i < nums.length - k + 1; ++i) {
        if (nums[j] < nums[i]) {
            j = i;
        }
    }
    return nums.slice(j, j + k);
}
```

#### Rust

```rust
impl Solution {
    pub fn largest_subarray(nums: Vec<i32>, k: i32) -> Vec<i32> {
        let mut j = 0;
        for i in 1..=nums.len() - (k as usize) {
            if nums[i] > nums[j] {
                j = i;
            }
        }
        nums[j..j + (k as usize)].to_vec()
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1709. 访问日期之间最大的空档期 🔒](https://leetcode.cn/problems/biggest-window-between-visits){#1709}

{{< tabs "1709" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            user_id,
            DATEDIFF(
                LEAD(visit_date, 1, '2021-1-1') OVER (
                    PARTITION BY user_id
                    ORDER BY visit_date
                ),
                visit_date
            ) AS diff
        FROM UserVisits
    )
SELECT user_id, MAX(diff) AS biggest_window
FROM T
GROUP BY 1
ORDER BY 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：&nbsp;<code>UserVisits</code></p>

<pre>
+-------------+------+
| Column Name | Type |
+-------------+------+
| user_id     | int  |
| visit_date  | date |
+-------------+------+
该表没有主键，它可能有重复的行
该表包含用户访问某特定零售商的日期日志。</pre>

<p>&nbsp;</p>

<p>假设今天的日期是&nbsp;<code>'2021-1-1'</code>&nbsp;。</p>

<p>编写解决方案，对于每个&nbsp;<code>user_id</code>&nbsp;，求出每次访问及其下一个访问（若该次访问是最后一次，则为今天）之间最大的空档期天数&nbsp;<code>window</code>&nbsp;。</p>

<p>返回结果表，按用户编号&nbsp;<code>user_id</code>&nbsp;排序。</p>

<p>结果格式如下示例所示：</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
UserVisits 表：
+---------+------------+
| user_id | visit_date |
+---------+------------+
| 1       | 2020-11-28 |
| 1       | 2020-10-20 |
| 1       | 2020-12-3  |
| 2       | 2020-10-5  |
| 2       | 2020-12-9  |
| 3       | 2020-11-11 |
+---------+------------+
<strong>输出：</strong>
+---------+---------------+
| user_id | biggest_window|
+---------+---------------+
| 1       | 39            |
| 2       | 65            |
| 3       | 51            |
+---------+---------------+
<strong>解释：</strong>
对于第一个用户，问题中的空档期在以下日期之间：
    - 2020-10-20 至 2020-11-28 ，共计 39 天。
    - 2020-11-28 至 2020-12-3 ，共计 5 天。
    - 2020-12-3 至 2021-1-1 ，共计 29 天。
由此得出，最大的空档期为 39 天。
对于第二个用户，问题中的空档期在以下日期之间：
    - 2020-10-5 至 2020-12-9 ，共计 65 天。
    - 2020-12-9 至 2021-1-1 ，共计 23 天。
由此得出，最大的空档期为 65 天。
对于第三个用户，问题中的唯一空档期在 2020-11-11 至 2021-1-1 之间，共计 51 天。</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：窗口函数

我们可以使用窗口函数 `LEAD` 来获取每个用户每次访问的下一次访问的日期（如果下一次访问的日期不存在，则视为 `2021-1-1`），然后利用 `DATEDIFF` 函数来计算两次访问之间的天数差值，最后对每个用户的天数差值求最大值即可。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            user_id,
            DATEDIFF(
                LEAD(visit_date, 1, '2021-1-1') OVER (
                    PARTITION BY user_id
                    ORDER BY visit_date
                ),
                visit_date
            ) AS diff
        FROM UserVisits
    )
SELECT user_id, MAX(diff) AS biggest_window
FROM T
GROUP BY 1
ORDER BY 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
