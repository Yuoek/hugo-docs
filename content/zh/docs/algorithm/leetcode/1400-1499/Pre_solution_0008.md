---
title: "1470_重新排列数组"
date: 2025-10-08T18:37:18+08:00
weight: 8
tags: [二分查找, 动态规划, 单调栈, 双向链表, 双指针, 哈希表, 排序, 数学, 数据库, 数据流, 数组, 栈, 滑动窗口, 矩阵, 设计, 链表]
---

{{< markmap >}}
### [1470_重新排列数组](#1470)
#### [数组](#1470)
### [1471_数组中的 k 个最强值](#1471)
#### [数组](#1471)
#### [双指针](#1471)
#### [排序](#1471)
### [1472_设计浏览器历史记录](#1472)
#### [栈](#1472)
#### [设计](#1472)
#### [数组](#1472)
#### [链表](#1472)
#### [数据流](#1472)
#### [双向链表](#1472)
### [1473_粉刷房子 III](#1473)
#### [数组](#1473)
#### [动态规划](#1473)
### [1474_删除链表 M 个节点之后的 N 个节点 🔒](#1474)
#### [链表](#1474)
### [1475_商品折扣后的最终价格](#1475)
#### [栈](#1475)
#### [数组](#1475)
#### [单调栈](#1475)
### [1476_子矩形查询](#1476)
#### [设计](#1476)
#### [数组](#1476)
#### [矩阵](#1476)
### [1477_找两个和为目标值且不重叠的子数组](#1477)
#### [数组](#1477)
#### [哈希表](#1477)
#### [二分查找](#1477)
#### [动态规划](#1477)
#### [滑动窗口](#1477)
### [1478_安排邮筒](#1478)
#### [数组](#1478)
#### [数学](#1478)
#### [动态规划](#1478)
#### [排序](#1478)
### [1479_周内每天的销售情况 🔒](#1479)
#### [数据库](#1479)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1470_重新排列数组
___
#### 数组
---
### 1471_数组中的 k 个最强值
___
#### 数组
___
#### 双指针
___
#### 排序
---
### 1472_设计浏览器历史记录
___
#### 栈
___
#### 设计
___
#### 数组
___
#### 链表
___
#### 数据流
___
#### 双向链表
---
### 1473_粉刷房子 III
___
#### 数组
___
#### 动态规划
---
### 1474_删除链表 M 个节点之后的 N 个节点 🔒
___
#### 链表
---
### 1475_商品折扣后的最终价格
___
#### 栈
___
#### 数组
___
#### 单调栈
---
### 1476_子矩形查询
___
#### 设计
___
#### 数组
___
#### 矩阵
---
### 1477_找两个和为目标值且不重叠的子数组
___
#### 数组
___
#### 哈希表
___
#### 二分查找
___
#### 动态规划
___
#### 滑动窗口
---
### 1478_安排邮筒
___
#### 数组
___
#### 数学
___
#### 动态规划
___
#### 排序
---
### 1479_周内每天的销售情况 🔒
___
#### 数据库
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 动态规划 | 单调栈 |
| 双向链表 | 双指针 | 哈希表 |
| 排序 | 数学 | 数据库 |
| 数据流 | 数组 | 栈 |
| 滑动窗口 | 矩阵 | 设计 |
| 链表 |  |  |

# [1470. 重新排列数组](https://leetcode.cn/problems/shuffle-the-array){#1470}

{{< tabs "1470" >}}

{{% tab "python" %}}
```python
class Solution:
    def shuffle(self, nums: List[int], n: int) -> List[int]:
        return [x for pair in zip(nums[:n], nums[n:]) for x in pair]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] shuffle(int[] nums, int n) {
        int[] ans = new int[n << 1];
        for (int i = 0, j = 0; i < n; ++i) {
            ans[j++] = nums[i];
            ans[j++] = nums[i + n];
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
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            ans.push_back(nums[i]);
            ans.push_back(nums[i + n]);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func shuffle(nums []int, n int) (ans []int) {
	for i := 0; i < n; i++ {
		ans = append(ans, nums[i])
		ans = append(ans, nums[i+n])
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function shuffle(nums: number[], n: number): number[] {
    const ans: number[] = [];
    for (let i = 0; i < n; ++i) {
        ans.push(nums[i], nums[i + n]);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn shuffle(nums: Vec<i32>, n: i32) -> Vec<i32> {
        let n = n as usize;
        let mut ans = Vec::new();
        for i in 0..n {
            ans.push(nums[i]);
            ans.push(nums[i + n]);
        }
        ans
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shuffle(int* nums, int numsSize, int n, int* returnSize) {
    int* ans = (int*) malloc(sizeof(int) * n * 2);
    for (int i = 0; i < n; i++) {
        ans[2 * i] = nums[i];
        ans[2 * i + 1] = nums[i + n];
    }
    *returnSize = n * 2;
    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个数组 <code>nums</code> ，数组中有 <code>2n</code> 个元素，按 <code>[x<sub>1</sub>,x<sub>2</sub>,...,x<sub>n</sub>,y<sub>1</sub>,y<sub>2</sub>,...,y<sub>n</sub>]</code> 的格式排列。</p>

<p>请你将数组按 <code>[x<sub>1</sub>,y<sub>1</sub>,x<sub>2</sub>,y<sub>2</sub>,...,x<sub>n</sub>,y<sub>n</sub>]</code> 格式重新排列，返回重排后的数组。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [2,5,1,3,4,7], n = 3
<strong>输出：</strong>[2,3,5,4,1,7] 
<strong>解释：</strong>由于 x<sub>1</sub>=2, x<sub>2</sub>=5, x<sub>3</sub>=1, y<sub>1</sub>=3, y<sub>2</sub>=4, y<sub>3</sub>=7 ，所以答案为 [2,3,5,4,1,7]
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [1,2,3,4,4,3,2,1], n = 4
<strong>输出：</strong>[1,4,2,3,3,2,4,1]
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>nums = [1,1,2,2], n = 2
<strong>输出：</strong>[1,2,1,2]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 500</code></li>
	<li><code>nums.length == 2n</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10^3</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们在 $[0, n)$ 的范围内遍历下标 $i$，每次取出 $\textit{nums}[i]$ 和 $\textit{nums}[i+n]$，并将它们依次放入答案数组中。

遍历结束后，返回答案数组即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 $\textit{nums}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def shuffle(self, nums: List[int], n: int) -> List[int]:
        return [x for pair in zip(nums[:n], nums[n:]) for x in pair]
```

#### Java

```java
class Solution {
    public int[] shuffle(int[] nums, int n) {
        int[] ans = new int[n << 1];
        for (int i = 0, j = 0; i < n; ++i) {
            ans[j++] = nums[i];
            ans[j++] = nums[i + n];
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            ans.push_back(nums[i]);
            ans.push_back(nums[i + n]);
        }
        return ans;
    }
};
```

#### Go

```go
func shuffle(nums []int, n int) (ans []int) {
	for i := 0; i < n; i++ {
		ans = append(ans, nums[i])
		ans = append(ans, nums[i+n])
	}
	return
}
```

#### TypeScript

```ts
function shuffle(nums: number[], n: number): number[] {
    const ans: number[] = [];
    for (let i = 0; i < n; ++i) {
        ans.push(nums[i], nums[i + n]);
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn shuffle(nums: Vec<i32>, n: i32) -> Vec<i32> {
        let n = n as usize;
        let mut ans = Vec::new();
        for i in 0..n {
            ans.push(nums[i]);
            ans.push(nums[i + n]);
        }
        ans
    }
}
```

#### C

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shuffle(int* nums, int numsSize, int n, int* returnSize) {
    int* ans = (int*) malloc(sizeof(int) * n * 2);
    for (int i = 0; i < n; i++) {
        ans[2 * i] = nums[i];
        ans[2 * i + 1] = nums[i + n];
    }
    *returnSize = n * 2;
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1471. 数组中的 k 个最强值](https://leetcode.cn/problems/the-k-strongest-values-in-an-array){#1471}

{{< tabs "1471" >}}

{{% tab "python" %}}
```python
class Solution:
    def getStrongest(self, arr: List[int], k: int) -> List[int]:
        arr.sort()
        m = arr[(len(arr) - 1) >> 1]
        arr.sort(key=lambda x: (-abs(x - m), -x))
        return arr[:k]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] getStrongest(int[] arr, int k) {
        Arrays.sort(arr);
        int m = arr[(arr.length - 1) >> 1];
        List<Integer> nums = new ArrayList<>();
        for (int v : arr) {
            nums.add(v);
        }
        nums.sort((a, b) -> {
            int x = Math.abs(a - m);
            int y = Math.abs(b - m);
            return x == y ? b - a : y - x;
        });
        int[] ans = new int[k];
        for (int i = 0; i < k; ++i) {
            ans[i] = nums.get(i);
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
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int m = arr[(arr.size() - 1) >> 1];
        sort(arr.begin(), arr.end(), [&](int a, int b) {
            int x = abs(a - m), y = abs(b - m);
            return x == y ? a > b : x > y;
        });
        vector<int> ans(arr.begin(), arr.begin() + k);
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func getStrongest(arr []int, k int) []int {
	sort.Ints(arr)
	m := arr[(len(arr)-1)>>1]
	sort.Slice(arr, func(i, j int) bool {
		x, y := abs(arr[i]-m), abs(arr[j]-m)
		if x == y {
			return arr[i] > arr[j]
		}
		return x > y
	})
	return arr[:k]
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
function getStrongest(arr: number[], k: number): number[] {
    arr.sort((a, b) => a - b);
    const m = arr[(arr.length - 1) >> 1];
    return arr.sort((a, b) => Math.abs(b - m) - Math.abs(a - m) || b - a).slice(0, k);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>arr</code> 和一个整数 <code>k</code> 。</p>

<p>设 <code>m</code> 为数组的中位数，只要满足下述两个前提之一，就可以判定 <code>arr[i]</code> 的值比 <code>arr[j]</code> 的值更强：</p>

<ul>
	<li>&nbsp;<code>|arr[i] - m| &gt; |arr[j]&nbsp;- m|</code></li>
	<li>&nbsp;<code>|arr[i] - m| == |arr[j] - m|</code>，且 <code>arr[i] &gt; arr[j]</code></li>
</ul>

<p>请返回由数组中最强的 <code>k</code> 个值组成的列表。答案可以以 <strong>任意顺序</strong> 返回。</p>

<p><strong>中位数</strong> 是一个有序整数列表中处于中间位置的值。形式上，如果列表的长度为 <code>n</code> ，那么中位数就是该有序列表（下标从 0 开始）中位于 <code>((n - 1) / 2)</code> 的元素。</p>

<ul>
	<li>例如 <code>arr =&nbsp;[6, -3, 7, 2, 11]</code>，<code>n = 5</code>：数组排序后得到 <code>arr = [-3, 2, 6, 7, 11]</code> ，数组的中间位置为 <code>m = ((5 - 1) / 2) = 2</code> ，中位数 <code>arr[m]</code> 的值为 <code>6</code> 。</li>
	<li>例如 <code>arr =&nbsp;[-7, 22, 17, 3]</code>，<code>n = 4</code>：数组排序后得到&nbsp;<code>arr = [-7, 3, 17, 22]</code> ，数组的中间位置为&nbsp;<code>m = ((4 - 1) / 2) = 1</code> ，中位数 <code>arr[m]</code> 的值为 <code>3</code> 。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>arr = [1,2,3,4,5], k = 2
<strong>输出：</strong>[5,1]
<strong>解释：</strong>中位数为 3，按从强到弱顺序排序后，数组变为 [5,1,4,2,3]。最强的两个元素是 [5, 1]。[1, 5] 也是正确答案。
注意，尽管 |5 - 3| == |1 - 3| ，但是 5 比 1 更强，因为 5 &gt; 1 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>arr = [1,1,3,5,5], k = 2
<strong>输出：</strong>[5,5]
<strong>解释：</strong>中位数为 3, 按从强到弱顺序排序后，数组变为 [5,5,1,1,3]。最强的两个元素是 [5, 5]。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>arr = [6,7,11,7,6,8], k = 5
<strong>输出：</strong>[11,8,6,6,7]
<strong>解释：</strong>中位数为 7, 按从强到弱顺序排序后，数组变为 [11,8,6,6,7,7]。
[11,8,6,6,7] 的任何排列都是正确答案。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>5</sup> &lt;= arr[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= k &lt;= arr.length</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序

我们首先对数组 $\textit{arr}$ 进行排序，然后找到数组的中位数 $m$。

接下来，我们按照题目描述的规则对数组进行排序，最后返回数组的前 $k$ 个元素即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 $\textit{arr}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def getStrongest(self, arr: List[int], k: int) -> List[int]:
        arr.sort()
        m = arr[(len(arr) - 1) >> 1]
        arr.sort(key=lambda x: (-abs(x - m), -x))
        return arr[:k]
```

#### Java

```java
class Solution {
    public int[] getStrongest(int[] arr, int k) {
        Arrays.sort(arr);
        int m = arr[(arr.length - 1) >> 1];
        List<Integer> nums = new ArrayList<>();
        for (int v : arr) {
            nums.add(v);
        }
        nums.sort((a, b) -> {
            int x = Math.abs(a - m);
            int y = Math.abs(b - m);
            return x == y ? b - a : y - x;
        });
        int[] ans = new int[k];
        for (int i = 0; i < k; ++i) {
            ans[i] = nums.get(i);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int m = arr[(arr.size() - 1) >> 1];
        sort(arr.begin(), arr.end(), [&](int a, int b) {
            int x = abs(a - m), y = abs(b - m);
            return x == y ? a > b : x > y;
        });
        vector<int> ans(arr.begin(), arr.begin() + k);
        return ans;
    }
};
```

#### Go

```go
func getStrongest(arr []int, k int) []int {
	sort.Ints(arr)
	m := arr[(len(arr)-1)>>1]
	sort.Slice(arr, func(i, j int) bool {
		x, y := abs(arr[i]-m), abs(arr[j]-m)
		if x == y {
			return arr[i] > arr[j]
		}
		return x > y
	})
	return arr[:k]
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
function getStrongest(arr: number[], k: number): number[] {
    arr.sort((a, b) => a - b);
    const m = arr[(arr.length - 1) >> 1];
    return arr.sort((a, b) => Math.abs(b - m) - Math.abs(a - m) || b - a).slice(0, k);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1472. 设计浏览器历史记录](https://leetcode.cn/problems/design-browser-history){#1472}

{{< tabs "1472" >}}

{{% tab "python" %}}
```python
class BrowserHistory:
    def __init__(self, homepage: str):
        self.stk1 = []
        self.stk2 = []
        self.visit(homepage)

    def visit(self, url: str) -> None:
        self.stk1.append(url)
        self.stk2.clear()

    def back(self, steps: int) -> str:
        while steps and len(self.stk1) > 1:
            self.stk2.append(self.stk1.pop())
            steps -= 1
        return self.stk1[-1]

    def forward(self, steps: int) -> str:
        while steps and self.stk2:
            self.stk1.append(self.stk2.pop())
            steps -= 1
        return self.stk1[-1]


# Your BrowserHistory object will be instantiated and called as such:
# obj = BrowserHistory(homepage)
# obj.visit(url)
# param_2 = obj.back(steps)
# param_3 = obj.forward(steps)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class BrowserHistory {
    private Deque<String> stk1 = new ArrayDeque<>();
    private Deque<String> stk2 = new ArrayDeque<>();

    public BrowserHistory(String homepage) {
        visit(homepage);
    }

    public void visit(String url) {
        stk1.push(url);
        stk2.clear();
    }

    public String back(int steps) {
        for (; steps > 0 && stk1.size() > 1; --steps) {
            stk2.push(stk1.pop());
        }
        return stk1.peek();
    }

    public String forward(int steps) {
        for (; steps > 0 && !stk2.isEmpty(); --steps) {
            stk1.push(stk2.pop());
        }
        return stk1.peek();
    }
}

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory obj = new BrowserHistory(homepage);
 * obj.visit(url);
 * String param_2 = obj.back(steps);
 * String param_3 = obj.forward(steps);
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class BrowserHistory {
public:
    stack<string> stk1;
    stack<string> stk2;

    BrowserHistory(string homepage) {
        visit(homepage);
    }

    void visit(string url) {
        stk1.push(url);
        stk2 = stack<string>();
    }

    string back(int steps) {
        for (; steps && stk1.size() > 1; --steps) {
            stk2.push(stk1.top());
            stk1.pop();
        }
        return stk1.top();
    }

    string forward(int steps) {
        for (; steps && !stk2.empty(); --steps) {
            stk1.push(stk2.top());
            stk2.pop();
        }
        return stk1.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type BrowserHistory struct {
	stk1 []string
	stk2 []string
}

func Constructor(homepage string) BrowserHistory {
	t := BrowserHistory{[]string{}, []string{}}
	t.Visit(homepage)
	return t
}

func (this *BrowserHistory) Visit(url string) {
	this.stk1 = append(this.stk1, url)
	this.stk2 = []string{}
}

func (this *BrowserHistory) Back(steps int) string {
	for i := 0; i < steps && len(this.stk1) > 1; i++ {
		this.stk2 = append(this.stk2, this.stk1[len(this.stk1)-1])
		this.stk1 = this.stk1[:len(this.stk1)-1]
	}
	return this.stk1[len(this.stk1)-1]
}

func (this *BrowserHistory) Forward(steps int) string {
	for i := 0; i < steps && len(this.stk2) > 0; i++ {
		this.stk1 = append(this.stk1, this.stk2[len(this.stk2)-1])
		this.stk2 = this.stk2[:len(this.stk2)-1]
	}
	return this.stk1[len(this.stk1)-1]
}

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * obj := Constructor(homepage);
 * obj.Visit(url);
 * param_2 := obj.Back(steps);
 * param_3 := obj.Forward(steps);
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你有一个只支持单个标签页的 <strong>浏览器</strong>&nbsp;，最开始你浏览的网页是&nbsp;<code>homepage</code>&nbsp;，你可以访问其他的网站&nbsp;<code>url</code>&nbsp;，也可以在浏览历史中后退&nbsp;<code>steps</code>&nbsp;步或前进&nbsp;<code>steps</code>&nbsp;步。</p>

<p>请你实现&nbsp;<code>BrowserHistory</code> 类：</p>

<ul>
	<li><code>BrowserHistory(string homepage)</code>&nbsp;，用&nbsp;<code>homepage</code>&nbsp;初始化浏览器类。</li>
	<li><code>void visit(string url)</code>&nbsp;从当前页跳转访问 <code>url</code> 对应的页面&nbsp;&nbsp;。执行此操作会把浏览历史前进的记录全部删除。</li>
	<li><code>string back(int steps)</code>&nbsp;在浏览历史中后退&nbsp;<code>steps</code>&nbsp;步。如果你只能在浏览历史中后退至多&nbsp;<code>x</code> 步且&nbsp;<code>steps &gt; x</code>&nbsp;，那么你只后退&nbsp;<code>x</code>&nbsp;步。请返回后退 <strong>至多</strong> <code>steps</code>&nbsp;步以后的&nbsp;<code>url</code>&nbsp;。</li>
	<li><code>string forward(int steps)</code>&nbsp;在浏览历史中前进&nbsp;<code>steps</code>&nbsp;步。如果你只能在浏览历史中前进至多&nbsp;<code>x</code>&nbsp;步且&nbsp;<code>steps &gt; x</code>&nbsp;，那么你只前进 <code>x</code>&nbsp;步。请返回前进&nbsp;<strong>至多</strong>&nbsp;<code>steps</code>步以后的 <code>url</code>&nbsp;。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre><strong>输入：</strong>
[&quot;BrowserHistory&quot;,&quot;visit&quot;,&quot;visit&quot;,&quot;visit&quot;,&quot;back&quot;,&quot;back&quot;,&quot;forward&quot;,&quot;visit&quot;,&quot;forward&quot;,&quot;back&quot;,&quot;back&quot;]
[[&quot;leetcode.com&quot;],[&quot;google.com&quot;],[&quot;facebook.com&quot;],[&quot;youtube.com&quot;],[1],[1],[1],[&quot;linkedin.com&quot;],[2],[2],[7]]
<strong>输出：</strong>
[null,null,null,null,&quot;facebook.com&quot;,&quot;google.com&quot;,&quot;facebook.com&quot;,null,&quot;linkedin.com&quot;,&quot;google.com&quot;,&quot;leetcode.com&quot;]

<strong>解释：</strong>
BrowserHistory browserHistory = new BrowserHistory(&quot;leetcode.com&quot;);
browserHistory.visit(&quot;google.com&quot;);       // 你原本在浏览 &quot;leetcode.com&quot; 。访问 &quot;google.com&quot;
browserHistory.visit(&quot;facebook.com&quot;);     // 你原本在浏览 &quot;google.com&quot; 。访问 &quot;facebook.com&quot;
browserHistory.visit(&quot;youtube.com&quot;);      // 你原本在浏览 &quot;facebook.com&quot; 。访问 &quot;youtube.com&quot;
browserHistory.back(1);                   // 你原本在浏览 &quot;youtube.com&quot; ，后退到 &quot;facebook.com&quot; 并返回 &quot;facebook.com&quot;
browserHistory.back(1);                   // 你原本在浏览 &quot;facebook.com&quot; ，后退到 &quot;google.com&quot; 并返回 &quot;google.com&quot;
browserHistory.forward(1);                // 你原本在浏览 &quot;google.com&quot; ，前进到 &quot;facebook.com&quot; 并返回 &quot;facebook.com&quot;
browserHistory.visit(&quot;linkedin.com&quot;);     // 你原本在浏览 &quot;facebook.com&quot; 。 访问 &quot;linkedin.com&quot;
browserHistory.forward(2);                // 你原本在浏览 &quot;linkedin.com&quot; ，你无法前进任何步数。
browserHistory.back(2);                   // 你原本在浏览 &quot;linkedin.com&quot; ，后退两步依次先到 &quot;facebook.com&quot; ，然后到 &quot;google.com&quot; ，并返回 &quot;google.com&quot;
browserHistory.back(7);                   // 你原本在浏览 &quot;google.com&quot;， 你只能后退一步到 &quot;leetcode.com&quot; ，并返回 &quot;leetcode.com&quot;
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= homepage.length &lt;= 20</code></li>
	<li><code>1 &lt;= url.length &lt;= 20</code></li>
	<li><code>1 &lt;= steps &lt;= 100</code></li>
	<li><code>homepage</code> 和&nbsp;<code>url</code>&nbsp;都只包含&nbsp;&#39;.&#39; 或者小写英文字母。</li>
	<li>最多调用&nbsp;<code>5000</code>&nbsp;次&nbsp;<code>visit</code>，&nbsp;<code>back</code>&nbsp;和&nbsp;<code>forward</code>&nbsp;函数。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双栈

我们可以使用两个栈 $\textit{stk1}$ 和 $\textit{stk2}$ 分别存储浏览后退页面和前进页面。初始时 $\textit{stk1}$ 包含 $\textit{homepage}$，而 $\textit{stk2}$ 为空。

调用 $\text{visit}(url)$ 时，我们将 $\textit{url}$ 加入 $\textit{stk1}$，并清空 $\textit{stk2}$。时间复杂度 $O(1)$。

调用 $\text{back}(steps)$ 时，我们将 $\textit{stk1}$ 的栈顶元素弹出并加入 $\textit{stk2}$，重复这一操作 $steps$ 次，直到 $\textit{stk1}$ 的长度为 $1$ 或者 $steps$ 为 $0$。最后返回 $\textit{stk1}$ 的栈顶元素。时间复杂度 $O(\textit{steps})$。

调用 $\text{forward}(steps)$ 时，我们将 $\textit{stk2}$ 的栈顶元素弹出并加入 $\textit{stk1}$，重复这一操作 $steps$ 次，直到 $\textit{stk2}$ 为空或者 $steps$ 为 $0$。最后返回 $\textit{stk1}$ 的栈顶元素。时间复杂度 $O(\textit{steps})$。

空间复杂度 $O(n)$，其中 $n$ 是浏览历史记录的长度。

<!-- tabs:start -->

#### Python3

```python
class BrowserHistory:
    def __init__(self, homepage: str):
        self.stk1 = []
        self.stk2 = []
        self.visit(homepage)

    def visit(self, url: str) -> None:
        self.stk1.append(url)
        self.stk2.clear()

    def back(self, steps: int) -> str:
        while steps and len(self.stk1) > 1:
            self.stk2.append(self.stk1.pop())
            steps -= 1
        return self.stk1[-1]

    def forward(self, steps: int) -> str:
        while steps and self.stk2:
            self.stk1.append(self.stk2.pop())
            steps -= 1
        return self.stk1[-1]


# Your BrowserHistory object will be instantiated and called as such:
# obj = BrowserHistory(homepage)
# obj.visit(url)
# param_2 = obj.back(steps)
# param_3 = obj.forward(steps)
```

#### Java

```java
class BrowserHistory {
    private Deque<String> stk1 = new ArrayDeque<>();
    private Deque<String> stk2 = new ArrayDeque<>();

    public BrowserHistory(String homepage) {
        visit(homepage);
    }

    public void visit(String url) {
        stk1.push(url);
        stk2.clear();
    }

    public String back(int steps) {
        for (; steps > 0 && stk1.size() > 1; --steps) {
            stk2.push(stk1.pop());
        }
        return stk1.peek();
    }

    public String forward(int steps) {
        for (; steps > 0 && !stk2.isEmpty(); --steps) {
            stk1.push(stk2.pop());
        }
        return stk1.peek();
    }
}

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory obj = new BrowserHistory(homepage);
 * obj.visit(url);
 * String param_2 = obj.back(steps);
 * String param_3 = obj.forward(steps);
 */
```

#### C++

```cpp
class BrowserHistory {
public:
    stack<string> stk1;
    stack<string> stk2;

    BrowserHistory(string homepage) {
        visit(homepage);
    }

    void visit(string url) {
        stk1.push(url);
        stk2 = stack<string>();
    }

    string back(int steps) {
        for (; steps && stk1.size() > 1; --steps) {
            stk2.push(stk1.top());
            stk1.pop();
        }
        return stk1.top();
    }

    string forward(int steps) {
        for (; steps && !stk2.empty(); --steps) {
            stk1.push(stk2.top());
            stk2.pop();
        }
        return stk1.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
```

#### Go

```go
type BrowserHistory struct {
	stk1 []string
	stk2 []string
}

func Constructor(homepage string) BrowserHistory {
	t := BrowserHistory{[]string{}, []string{}}
	t.Visit(homepage)
	return t
}

func (this *BrowserHistory) Visit(url string) {
	this.stk1 = append(this.stk1, url)
	this.stk2 = []string{}
}

func (this *BrowserHistory) Back(steps int) string {
	for i := 0; i < steps && len(this.stk1) > 1; i++ {
		this.stk2 = append(this.stk2, this.stk1[len(this.stk1)-1])
		this.stk1 = this.stk1[:len(this.stk1)-1]
	}
	return this.stk1[len(this.stk1)-1]
}

func (this *BrowserHistory) Forward(steps int) string {
	for i := 0; i < steps && len(this.stk2) > 0; i++ {
		this.stk1 = append(this.stk1, this.stk2[len(this.stk2)-1])
		this.stk2 = this.stk2[:len(this.stk2)-1]
	}
	return this.stk1[len(this.stk1)-1]
}

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * obj := Constructor(homepage);
 * obj.Visit(url);
 * param_2 := obj.Back(steps);
 * param_3 := obj.Forward(steps);
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1473. 粉刷房子 III](https://leetcode.cn/problems/paint-house-iii){#1473}

{{< tabs "1473" >}}

{{% tab "python" %}}
```python
class Solution:
    def minCost(
        self, houses: List[int], cost: List[List[int]], m: int, n: int, target: int
    ) -> int:
        f = [[[inf] * (target + 1) for _ in range(n + 1)] for _ in range(m)]
        if houses[0] == 0:
            for j, c in enumerate(cost[0], 1):
                f[0][j][1] = c
        else:
            f[0][houses[0]][1] = 0
        for i in range(1, m):
            if houses[i] == 0:
                for j in range(1, n + 1):
                    for k in range(1, min(target + 1, i + 2)):
                        for j0 in range(1, n + 1):
                            if j == j0:
                                f[i][j][k] = min(
                                    f[i][j][k], f[i - 1][j][k] + cost[i][j - 1]
                                )
                            else:
                                f[i][j][k] = min(
                                    f[i][j][k], f[i - 1][j0][k - 1] + cost[i][j - 1]
                                )
            else:
                j = houses[i]
                for k in range(1, min(target + 1, i + 2)):
                    for j0 in range(1, n + 1):
                        if j == j0:
                            f[i][j][k] = min(f[i][j][k], f[i - 1][j][k])
                        else:
                            f[i][j][k] = min(f[i][j][k], f[i - 1][j0][k - 1])

        ans = min(f[-1][j][target] for j in range(1, n + 1))
        return -1 if ans >= inf else ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minCost(int[] houses, int[][] cost, int m, int n, int target) {
        int[][][] f = new int[m][n + 1][target + 1];
        final int inf = 1 << 30;
        for (int[][] g : f) {
            for (int[] e : g) {
                Arrays.fill(e, inf);
            }
        }
        if (houses[0] == 0) {
            for (int j = 1; j <= n; ++j) {
                f[0][j][1] = cost[0][j - 1];
            }
        } else {
            f[0][houses[0]][1] = 0;
        }
        for (int i = 1; i < m; ++i) {
            if (houses[i] == 0) {
                for (int j = 1; j <= n; ++j) {
                    for (int k = 1; k <= Math.min(target, i + 1); ++k) {
                        for (int j0 = 1; j0 <= n; ++j0) {
                            if (j == j0) {
                                f[i][j][k] = Math.min(f[i][j][k], f[i - 1][j][k] + cost[i][j - 1]);
                            } else {
                                f[i][j][k]
                                    = Math.min(f[i][j][k], f[i - 1][j0][k - 1] + cost[i][j - 1]);
                            }
                        }
                    }
                }
            } else {
                int j = houses[i];
                for (int k = 1; k <= Math.min(target, i + 1); ++k) {
                    for (int j0 = 1; j0 <= n; ++j0) {
                        if (j == j0) {
                            f[i][j][k] = Math.min(f[i][j][k], f[i - 1][j][k]);
                        } else {
                            f[i][j][k] = Math.min(f[i][j][k], f[i - 1][j0][k - 1]);
                        }
                    }
                }
            }
        }
        int ans = inf;
        for (int j = 1; j <= n; ++j) {
            ans = Math.min(ans, f[m - 1][j][target]);
        }
        return ans >= inf ? -1 : ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        int f[m][n + 1][target + 1];
        memset(f, 0x3f, sizeof(f));
        if (houses[0] == 0) {
            for (int j = 1; j <= n; ++j) {
                f[0][j][1] = cost[0][j - 1];
            }
        } else {
            f[0][houses[0]][1] = 0;
        }
        for (int i = 1; i < m; ++i) {
            if (houses[i] == 0) {
                for (int j = 1; j <= n; ++j) {
                    for (int k = 1; k <= min(target, i + 1); ++k) {
                        for (int j0 = 1; j0 <= n; ++j0) {
                            if (j == j0) {
                                f[i][j][k] = min(f[i][j][k], f[i - 1][j][k] + cost[i][j - 1]);
                            } else {
                                f[i][j][k] = min(f[i][j][k], f[i - 1][j0][k - 1] + cost[i][j - 1]);
                            }
                        }
                    }
                }
            } else {
                int j = houses[i];
                for (int k = 1; k <= min(target, i + 1); ++k) {
                    for (int j0 = 1; j0 <= n; ++j0) {
                        if (j == j0) {
                            f[i][j][k] = min(f[i][j][k], f[i - 1][j][k]);
                        } else {
                            f[i][j][k] = min(f[i][j][k], f[i - 1][j0][k - 1]);
                        }
                    }
                }
            }
        }
        int ans = 0x3f3f3f3f;
        for (int j = 1; j <= n; ++j) {
            ans = min(ans, f[m - 1][j][target]);
        }
        return ans == 0x3f3f3f3f ? -1 : ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minCost(houses []int, cost [][]int, m int, n int, target int) int {
	f := make([][][]int, m)
	const inf = 1 << 30
	for i := range f {
		f[i] = make([][]int, n+1)
		for j := range f[i] {
			f[i][j] = make([]int, target+1)
			for k := range f[i][j] {
				f[i][j][k] = inf
			}
		}
	}
	if houses[0] == 0 {
		for j := 1; j <= n; j++ {
			f[0][j][1] = cost[0][j-1]
		}
	} else {
		f[0][houses[0]][1] = 0
	}
	for i := 1; i < m; i++ {
		if houses[i] == 0 {
			for j := 1; j <= n; j++ {
				for k := 1; k <= target && k <= i+1; k++ {
					for j0 := 1; j0 <= n; j0++ {
						if j == j0 {
							f[i][j][k] = min(f[i][j][k], f[i-1][j][k]+cost[i][j-1])
						} else {
							f[i][j][k] = min(f[i][j][k], f[i-1][j0][k-1]+cost[i][j-1])
						}
					}
				}
			}
		} else {
			j := houses[i]
			for k := 1; k <= target && k <= i+1; k++ {
				for j0 := 1; j0 <= n; j0++ {
					if j == j0 {
						f[i][j][k] = min(f[i][j][k], f[i-1][j][k])
					} else {
						f[i][j][k] = min(f[i][j][k], f[i-1][j0][k-1])
					}
				}
			}
		}
	}
	ans := inf
	for j := 1; j <= n; j++ {
		ans = min(ans, f[m-1][j][target])
	}
	if ans == inf {
		return -1
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minCost(houses: number[], cost: number[][], m: number, n: number, target: number): number {
    const inf = 1 << 30;
    const f: number[][][] = new Array(m)
        .fill(0)
        .map(() => new Array(n + 1).fill(0).map(() => new Array(target + 1).fill(inf)));
    if (houses[0] === 0) {
        for (let j = 1; j <= n; ++j) {
            f[0][j][1] = cost[0][j - 1];
        }
    } else {
        f[0][houses[0]][1] = 0;
    }
    for (let i = 1; i < m; ++i) {
        if (houses[i] === 0) {
            for (let j = 1; j <= n; ++j) {
                for (let k = 1; k <= Math.min(target, i + 1); ++k) {
                    for (let j0 = 1; j0 <= n; ++j0) {
                        if (j0 === j) {
                            f[i][j][k] = Math.min(f[i][j][k], f[i - 1][j][k] + cost[i][j - 1]);
                        } else {
                            f[i][j][k] = Math.min(f[i][j][k], f[i - 1][j0][k - 1] + cost[i][j - 1]);
                        }
                    }
                }
            }
        } else {
            const j = houses[i];
            for (let k = 1; k <= Math.min(target, i + 1); ++k) {
                for (let j0 = 1; j0 <= n; ++j0) {
                    if (j0 === j) {
                        f[i][j][k] = Math.min(f[i][j][k], f[i - 1][j][k]);
                    } else {
                        f[i][j][k] = Math.min(f[i][j][k], f[i - 1][j0][k - 1]);
                    }
                }
            }
        }
    }
    let ans = inf;
    for (let j = 1; j <= n; ++j) {
        ans = Math.min(ans, f[m - 1][j][target]);
    }
    return ans >= inf ? -1 : ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>在一个小城市里，有 <code>m</code> 个房子排成一排，你需要给每个房子涂上 <code>n</code> 种颜色之一（颜色编号为 <code>1</code> 到 <code>n</code> ）。有的房子去年夏天已经涂过颜色了，所以这些房子不可以被重新涂色。</p>

<p>我们将连续相同颜色尽可能多的房子称为一个街区。（比方说 <code>houses = [1,2,2,3,3,2,1,1]</code> ，它包含 5 个街区 <code> [{1}, {2,2}, {3,3}, {2}, {1,1}]</code> 。）</p>

<p>给你一个数组 <code>houses</code> ，一个 <code>m * n</code> 的矩阵 <code>cost</code> 和一个整数 <code>target</code> ，其中：</p>

<ul>
	<li><code>houses[i]</code>：是第 <code>i</code> 个房子的颜色，<strong>0</strong> 表示这个房子还没有被涂色。</li>
	<li><code>cost[i][j]</code>：是将第 <code>i</code> 个房子涂成颜色 <code>j+1</code> 的花费。</li>
</ul>

<p>请你返回房子涂色方案的最小总花费，使得每个房子都被涂色后，恰好组成 <code>target</code> 个街区。如果没有可用的涂色方案，请返回 <strong>-1</strong> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>houses = [0,0,0,0,0], cost = [[1,10],[10,1],[10,1],[1,10],[5,1]], m = 5, n = 2, target = 3
<strong>输出：</strong>9
<strong>解释：</strong>房子涂色方案为 [1,2,2,1,1]
此方案包含 target = 3 个街区，分别是 [{1}, {2,2}, {1,1}]。
涂色的总花费为 (1 + 1 + 1 + 1 + 5) = 9。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>houses = [0,2,1,2,0], cost = [[1,10],[10,1],[10,1],[1,10],[5,1]], m = 5, n = 2, target = 3
<strong>输出：</strong>11
<strong>解释：</strong>有的房子已经被涂色了，在此基础上涂色方案为 [2,2,1,2,2]
此方案包含 target = 3 个街区，分别是 [{2,2}, {1}, {2,2}]。
给第一个和最后一个房子涂色的花费为 (10 + 1) = 11。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>houses = [0,0,0,0,0], cost = [[1,10],[10,1],[1,10],[10,1],[1,10]], m = 5, n = 2, target = 5
<strong>输出：</strong>5
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>houses = [3,1,2,3], cost = [[1,1,1],[1,1,1],[1,1,1],[1,1,1]], m = 4, n = 3, target = 3
<strong>输出：</strong>-1
<strong>解释：</strong>房子已经被涂色并组成了 4 个街区，分别是 [{3},{1},{2},{3}] ，无法形成 target = 3 个街区。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == houses.length == cost.length</code></li>
	<li><code>n == cost[i].length</code></li>
	<li><code>1 <= m <= 100</code></li>
	<li><code>1 <= n <= 20</code></li>
	<li><code>1 <= target <= m</code></li>
	<li><code>0 <= houses[i] <= n</code></li>
	<li><code>1 <= cost[i][j] <= 10^4</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i][j][k]$ 表示将下标 $[0,..i]$ 的房子涂上颜色，最后一个房子的颜色为 $j$，且恰好形成 $k$ 个街区的最小花费。那么答案就是 $f[m-1][j][\textit{target}]$，其中 $j$ 的取值范围为 $[1,..n]$。初始时，我们判断下标为 $0$ 的房子是否已经涂色，如果未涂色，那么 $f[0][j][1] = \textit{cost}[0][j - 1]$，其中 $j \in [1,..n]$。如果已经涂色，那么 $f[0][\textit{houses}[0]][1] = 0$。其他的 $f[i][j][k]$ 的值都初始化为 $\infty$。

接下来，我们从下标 $i=1$ 开始遍历，对于每个 $i$，我们判断下标为 $i$ 的房子是否已经涂色：

如果未涂色，那么我们可以将下标为 $i$ 的房子涂成颜色 $j$，我们枚举街区的数量 $k$，其中 $k \in [1,..\min(\textit{target}, i + 1)]$，并且枚举下标为 $i$ 的房子的前一个房子的颜色 $j_0$，其中 $j_0 \in [1,..n]$，那么我们可以得到状态转移方程：

$$
f[i][j][k] = \min_{j_0 \in [1,..n]} \{ f[i - 1][j_0][k - (j \neq j_0)] + \textit{cost}[i][j - 1] \}
$$

如果已经涂色，那么我们可以将下标为 $i$ 的房子涂成颜色 $j$，我们枚举街区的数量 $k$，其中 $k \in [1,..\min(\textit{target}, i + 1)]$，并且枚举下标为 $i$ 的房子的前一个房子的颜色 $j_0$，其中 $j_0 \in [1,..n]$，那么我们可以得到状态转移方程：

$$
f[i][j][k] = \min_{j_0 \in [1,..n]} \{ f[i - 1][j_0][k - (j \neq j_0)] \}
$$

最后，我们返回 $f[m - 1][j][\textit{target}]$，其中 $j \in [1,..n]$，如果所有的 $f[m - 1][j][\textit{target}]$ 的值都为 $\infty$，那么返回 $-1$。

时间复杂度 $O(m \times n^2 \times \textit{target})$，空间复杂度 $O(m \times n \times \textit{target})$。其中 $m$, $n$, $\textit{target}$ 分别为房子的数量，颜色的数量，街区的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minCost(
        self, houses: List[int], cost: List[List[int]], m: int, n: int, target: int
    ) -> int:
        f = [[[inf] * (target + 1) for _ in range(n + 1)] for _ in range(m)]
        if houses[0] == 0:
            for j, c in enumerate(cost[0], 1):
                f[0][j][1] = c
        else:
            f[0][houses[0]][1] = 0
        for i in range(1, m):
            if houses[i] == 0:
                for j in range(1, n + 1):
                    for k in range(1, min(target + 1, i + 2)):
                        for j0 in range(1, n + 1):
                            if j == j0:
                                f[i][j][k] = min(
                                    f[i][j][k], f[i - 1][j][k] + cost[i][j - 1]
                                )
                            else:
                                f[i][j][k] = min(
                                    f[i][j][k], f[i - 1][j0][k - 1] + cost[i][j - 1]
                                )
            else:
                j = houses[i]
                for k in range(1, min(target + 1, i + 2)):
                    for j0 in range(1, n + 1):
                        if j == j0:
                            f[i][j][k] = min(f[i][j][k], f[i - 1][j][k])
                        else:
                            f[i][j][k] = min(f[i][j][k], f[i - 1][j0][k - 1])

        ans = min(f[-1][j][target] for j in range(1, n + 1))
        return -1 if ans >= inf else ans
```

#### Java

```java
class Solution {
    public int minCost(int[] houses, int[][] cost, int m, int n, int target) {
        int[][][] f = new int[m][n + 1][target + 1];
        final int inf = 1 << 30;
        for (int[][] g : f) {
            for (int[] e : g) {
                Arrays.fill(e, inf);
            }
        }
        if (houses[0] == 0) {
            for (int j = 1; j <= n; ++j) {
                f[0][j][1] = cost[0][j - 1];
            }
        } else {
            f[0][houses[0]][1] = 0;
        }
        for (int i = 1; i < m; ++i) {
            if (houses[i] == 0) {
                for (int j = 1; j <= n; ++j) {
                    for (int k = 1; k <= Math.min(target, i + 1); ++k) {
                        for (int j0 = 1; j0 <= n; ++j0) {
                            if (j == j0) {
                                f[i][j][k] = Math.min(f[i][j][k], f[i - 1][j][k] + cost[i][j - 1]);
                            } else {
                                f[i][j][k]
                                    = Math.min(f[i][j][k], f[i - 1][j0][k - 1] + cost[i][j - 1]);
                            }
                        }
                    }
                }
            } else {
                int j = houses[i];
                for (int k = 1; k <= Math.min(target, i + 1); ++k) {
                    for (int j0 = 1; j0 <= n; ++j0) {
                        if (j == j0) {
                            f[i][j][k] = Math.min(f[i][j][k], f[i - 1][j][k]);
                        } else {
                            f[i][j][k] = Math.min(f[i][j][k], f[i - 1][j0][k - 1]);
                        }
                    }
                }
            }
        }
        int ans = inf;
        for (int j = 1; j <= n; ++j) {
            ans = Math.min(ans, f[m - 1][j][target]);
        }
        return ans >= inf ? -1 : ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        int f[m][n + 1][target + 1];
        memset(f, 0x3f, sizeof(f));
        if (houses[0] == 0) {
            for (int j = 1; j <= n; ++j) {
                f[0][j][1] = cost[0][j - 1];
            }
        } else {
            f[0][houses[0]][1] = 0;
        }
        for (int i = 1; i < m; ++i) {
            if (houses[i] == 0) {
                for (int j = 1; j <= n; ++j) {
                    for (int k = 1; k <= min(target, i + 1); ++k) {
                        for (int j0 = 1; j0 <= n; ++j0) {
                            if (j == j0) {
                                f[i][j][k] = min(f[i][j][k], f[i - 1][j][k] + cost[i][j - 1]);
                            } else {
                                f[i][j][k] = min(f[i][j][k], f[i - 1][j0][k - 1] + cost[i][j - 1]);
                            }
                        }
                    }
                }
            } else {
                int j = houses[i];
                for (int k = 1; k <= min(target, i + 1); ++k) {
                    for (int j0 = 1; j0 <= n; ++j0) {
                        if (j == j0) {
                            f[i][j][k] = min(f[i][j][k], f[i - 1][j][k]);
                        } else {
                            f[i][j][k] = min(f[i][j][k], f[i - 1][j0][k - 1]);
                        }
                    }
                }
            }
        }
        int ans = 0x3f3f3f3f;
        for (int j = 1; j <= n; ++j) {
            ans = min(ans, f[m - 1][j][target]);
        }
        return ans == 0x3f3f3f3f ? -1 : ans;
    }
};
```

#### Go

```go
func minCost(houses []int, cost [][]int, m int, n int, target int) int {
	f := make([][][]int, m)
	const inf = 1 << 30
	for i := range f {
		f[i] = make([][]int, n+1)
		for j := range f[i] {
			f[i][j] = make([]int, target+1)
			for k := range f[i][j] {
				f[i][j][k] = inf
			}
		}
	}
	if houses[0] == 0 {
		for j := 1; j <= n; j++ {
			f[0][j][1] = cost[0][j-1]
		}
	} else {
		f[0][houses[0]][1] = 0
	}
	for i := 1; i < m; i++ {
		if houses[i] == 0 {
			for j := 1; j <= n; j++ {
				for k := 1; k <= target && k <= i+1; k++ {
					for j0 := 1; j0 <= n; j0++ {
						if j == j0 {
							f[i][j][k] = min(f[i][j][k], f[i-1][j][k]+cost[i][j-1])
						} else {
							f[i][j][k] = min(f[i][j][k], f[i-1][j0][k-1]+cost[i][j-1])
						}
					}
				}
			}
		} else {
			j := houses[i]
			for k := 1; k <= target && k <= i+1; k++ {
				for j0 := 1; j0 <= n; j0++ {
					if j == j0 {
						f[i][j][k] = min(f[i][j][k], f[i-1][j][k])
					} else {
						f[i][j][k] = min(f[i][j][k], f[i-1][j0][k-1])
					}
				}
			}
		}
	}
	ans := inf
	for j := 1; j <= n; j++ {
		ans = min(ans, f[m-1][j][target])
	}
	if ans == inf {
		return -1
	}
	return ans
}
```

#### TypeScript

```ts
function minCost(houses: number[], cost: number[][], m: number, n: number, target: number): number {
    const inf = 1 << 30;
    const f: number[][][] = new Array(m)
        .fill(0)
        .map(() => new Array(n + 1).fill(0).map(() => new Array(target + 1).fill(inf)));
    if (houses[0] === 0) {
        for (let j = 1; j <= n; ++j) {
            f[0][j][1] = cost[0][j - 1];
        }
    } else {
        f[0][houses[0]][1] = 0;
    }
    for (let i = 1; i < m; ++i) {
        if (houses[i] === 0) {
            for (let j = 1; j <= n; ++j) {
                for (let k = 1; k <= Math.min(target, i + 1); ++k) {
                    for (let j0 = 1; j0 <= n; ++j0) {
                        if (j0 === j) {
                            f[i][j][k] = Math.min(f[i][j][k], f[i - 1][j][k] + cost[i][j - 1]);
                        } else {
                            f[i][j][k] = Math.min(f[i][j][k], f[i - 1][j0][k - 1] + cost[i][j - 1]);
                        }
                    }
                }
            }
        } else {
            const j = houses[i];
            for (let k = 1; k <= Math.min(target, i + 1); ++k) {
                for (let j0 = 1; j0 <= n; ++j0) {
                    if (j0 === j) {
                        f[i][j][k] = Math.min(f[i][j][k], f[i - 1][j][k]);
                    } else {
                        f[i][j][k] = Math.min(f[i][j][k], f[i - 1][j0][k - 1]);
                    }
                }
            }
        }
    }
    let ans = inf;
    for (let j = 1; j <= n; ++j) {
        ans = Math.min(ans, f[m - 1][j][target]);
    }
    return ans >= inf ? -1 : ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1474. 删除链表 M 个节点之后的 N 个节点 🔒](https://leetcode.cn/problems/delete-n-nodes-after-m-nodes-of-a-linked-list){#1474}

{{< tabs "1474" >}}

{{% tab "python" %}}
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteNodes(self, head: ListNode, m: int, n: int) -> ListNode:
        pre = head
        while pre:
            for _ in range(m - 1):
                if pre:
                    pre = pre.next
            if pre is None:
                return head
            cur = pre
            for _ in range(n):
                if cur:
                    cur = cur.next
            pre.next = None if cur is None else cur.next
            pre = pre.next
        return head
```
{{% /tab %}}
{{% tab "java" %}}
```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode deleteNodes(ListNode head, int m, int n) {
        ListNode pre = head;
        while (pre != null) {
            for (int i = 0; i < m - 1 && pre != null; ++i) {
                pre = pre.next;
            }
            if (pre == null) {
                return head;
            }
            ListNode cur = pre;
            for (int i = 0; i < n && cur != null; ++i) {
                cur = cur.next;
            }
            pre.next = cur == null ? null : cur.next;
            pre = pre.next;
        }
        return head;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        auto pre = head;
        while (pre) {
            for (int i = 0; i < m - 1 && pre; ++i) {
                pre = pre->next;
            }
            if (!pre) {
                return head;
            }
            auto cur = pre;
            for (int i = 0; i < n && cur; ++i) {
                cur = cur->next;
            }
            pre->next = cur ? cur->next : nullptr;
            pre = pre->next;
        }
        return head;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func deleteNodes(head *ListNode, m int, n int) *ListNode {
	pre := head
	for pre != nil {
		for i := 0; i < m-1 && pre != nil; i++ {
			pre = pre.Next
		}
		if pre == nil {
			return head
		}
		cur := pre
		for i := 0; i < n && cur != nil; i++ {
			cur = cur.Next
		}
		pre.Next = nil
		if cur != nil {
			pre.Next = cur.Next
		}
		pre = pre.Next
	}
	return head
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function deleteNodes(head: ListNode | null, m: number, n: number): ListNode | null {
    let pre = head;
    while (pre) {
        for (let i = 0; i < m - 1 && pre; ++i) {
            pre = pre.next;
        }
        if (!pre) {
            break;
        }
        let cur = pre;
        for (let i = 0; i < n && cur; ++i) {
            cur = cur.next;
        }
        pre.next = cur?.next || null;
        pre = pre.next;
    }
    return head;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定链表&nbsp;<code>head</code>&nbsp;和两个整数&nbsp;<code>m</code>&nbsp;和&nbsp;<code>n</code>. 遍历该链表并按照如下方式删除节点:</p>

<ul>
	<li>开始时以头节点作为当前节点.</li>
	<li>保留以当前节点开始的前&nbsp;<code>m</code>&nbsp;个节点.</li>
	<li>删除接下来的&nbsp;<code>n</code>&nbsp;个节点.</li>
	<li>重复步骤 2 和 3,&nbsp;直到到达链表结尾.</li>
</ul>

<p>在删除了指定结点之后,&nbsp;返回修改过后的链表的头节点.</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1400-1499/1474.Delete%20N%20Nodes%20After%20M%20Nodes%20of%20a%20Linked%20List/images/sample_1_1848.png" style="height: 95px; width: 620px;" /></strong></p>

<pre>
<strong>输入:</strong> head = [1,2,3,4,5,6,7,8,9,10,11,12,13], m = 2, n = 3
<strong>输出:</strong> [1,2,6,7,11,12]
<strong>解析: </strong>保留前(m = 2)个结点,  也就是以黑色节点表示的从链表头结点开始的结点(1 -&gt;2).
删除接下来的(n = 3)个结点(3 -&gt; 4 -&gt; 5), 在图中以红色结点表示.
继续相同的操作, 直到链表的末尾.
返回删除结点之后的链表的头结点.</pre>

<p><strong>示例 2:</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1400-1499/1474.Delete%20N%20Nodes%20After%20M%20Nodes%20of%20a%20Linked%20List/images/sample_2_1848.png" style="height: 123px; width: 620px;" /></strong></p>

<pre>
<strong>输入:</strong> head = [1,2,3,4,5,6,7,8,9,10,11], m = 1, n = 3
<strong>输出:</strong> [1,5,9]
<strong>解析:</strong> 返回删除结点之后的链表的头结点.</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入:</strong> head = [1,2,3,4,5,6,7,8,9,10,11], m = 3, n = 1
<strong>输出:</strong> [1,2,3,5,6,7,9,10,11]
</pre>

<p><strong>示例&nbsp;4:</strong></p>

<pre>
<strong>输入:</strong> head = [9,3,7,7,9,10,8,2], m = 1, n = 2
<strong>输出:</strong> [9,7,8]
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li>链表中节点数目在范围 <code>[1, 10<sup>4</sup>]</code> 内</li>
	<li><code>1 &lt;= Node.val &lt;= 10<sup>6</sup></code></li>
	<li><code>1 &lt;= m, n &lt;= 1000</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶:</strong> 你能通过<strong> 就地 </strong>修改链表的方式解决这个问题吗?</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们可以模拟整个删除过程，首先用 $\textit{pre}$ 指针指向链表头部，然后遍历链表，移动 $m - 1$ 步，如果 $\textit{pre}$ 为空，说明从当前节点开始的节点个数小于 $m$，直接返回头部；否则，用 $\textit{cur}$ 指针指向 $\textit{pre}$，然后移动 $n$ 步，如果 $\textit{cur}$ 为空，说明从 $\textit{pre}$ 开始的节点个数小于 $m + n$，直接将 $\textit{pre}$ 的 $\textit{next}$ 指向 $\text{null}$；否则，将 $\textit{pre}$ 的 $\textit{next}$ 指向 $\textit{cur}$ 的 $\textit{next}$，然后将 $\textit{pre}$ 移动到 $\textit{pre}$ 的 $\textit{next}$。继续遍历链表，直到 $\textit{pre}$ 为空，返回头部。

时间复杂度 $O(n)$，其中 $n$ 是链表中节点的个数。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteNodes(self, head: ListNode, m: int, n: int) -> ListNode:
        pre = head
        while pre:
            for _ in range(m - 1):
                if pre:
                    pre = pre.next
            if pre is None:
                return head
            cur = pre
            for _ in range(n):
                if cur:
                    cur = cur.next
            pre.next = None if cur is None else cur.next
            pre = pre.next
        return head
```

#### Java

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode deleteNodes(ListNode head, int m, int n) {
        ListNode pre = head;
        while (pre != null) {
            for (int i = 0; i < m - 1 && pre != null; ++i) {
                pre = pre.next;
            }
            if (pre == null) {
                return head;
            }
            ListNode cur = pre;
            for (int i = 0; i < n && cur != null; ++i) {
                cur = cur.next;
            }
            pre.next = cur == null ? null : cur.next;
            pre = pre.next;
        }
        return head;
    }
}
```

#### C++

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        auto pre = head;
        while (pre) {
            for (int i = 0; i < m - 1 && pre; ++i) {
                pre = pre->next;
            }
            if (!pre) {
                return head;
            }
            auto cur = pre;
            for (int i = 0; i < n && cur; ++i) {
                cur = cur->next;
            }
            pre->next = cur ? cur->next : nullptr;
            pre = pre->next;
        }
        return head;
    }
};
```

#### Go

```go
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func deleteNodes(head *ListNode, m int, n int) *ListNode {
	pre := head
	for pre != nil {
		for i := 0; i < m-1 && pre != nil; i++ {
			pre = pre.Next
		}
		if pre == nil {
			return head
		}
		cur := pre
		for i := 0; i < n && cur != nil; i++ {
			cur = cur.Next
		}
		pre.Next = nil
		if cur != nil {
			pre.Next = cur.Next
		}
		pre = pre.Next
	}
	return head
}
```

#### TypeScript

```ts
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function deleteNodes(head: ListNode | null, m: number, n: number): ListNode | null {
    let pre = head;
    while (pre) {
        for (let i = 0; i < m - 1 && pre; ++i) {
            pre = pre.next;
        }
        if (!pre) {
            break;
        }
        let cur = pre;
        for (let i = 0; i < n && cur; ++i) {
            cur = cur.next;
        }
        pre.next = cur?.next || null;
        pre = pre.next;
    }
    return head;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1475. 商品折扣后的最终价格](https://leetcode.cn/problems/final-prices-with-a-special-discount-in-a-shop){#1475}

{{< tabs "1475" >}}

{{% tab "python" %}}
```python
class Solution:
    def finalPrices(self, prices: List[int]) -> List[int]:
        stk = []
        for i in reversed(range(len(prices))):
            x = prices[i]
            while stk and x < stk[-1]:
                stk.pop()
            if stk:
                prices[i] -= stk[-1]
            stk.append(x)
        return prices
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] finalPrices(int[] prices) {
        int n = prices.length;
        Deque<Integer> stk = new ArrayDeque<>();
        for (int i = n - 1; i >= 0; --i) {
            int x = prices[i];
            while (!stk.isEmpty() && stk.peek() > x) {
                stk.pop();
            }
            if (!stk.isEmpty()) {
                prices[i] -= stk.peek();
            }
            stk.push(x);
        }
        return prices;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> stk;
        for (int i = prices.size() - 1; ~i; --i) {
            int x = prices[i];
            while (!stk.empty() && stk.top() > x) {
                stk.pop();
            }
            if (!stk.empty()) {
                prices[i] -= stk.top();
            }
            stk.push(x);
        }
        return prices;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func finalPrices(prices []int) []int {
	stk := []int{}
	for i := len(prices) - 1; i >= 0; i-- {
		x := prices[i]
		for len(stk) > 0 && stk[len(stk)-1] > x {
			stk = stk[:len(stk)-1]
		}
		if len(stk) > 0 {
			prices[i] -= stk[len(stk)-1]
		}
		stk = append(stk, x)
	}
	return prices
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function finalPrices(prices: number[]): number[] {
    const stk: number[] = [];
    for (let i = prices.length - 1; ~i; --i) {
        const x = prices[i];
        while (stk.length && stk.at(-1)! > x) {
            stk.pop();
        }
        prices[i] -= stk.at(-1) || 0;
        stk.push(x);
    }
    return prices;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn final_prices(mut prices: Vec<i32>) -> Vec<i32> {
        let mut stk: Vec<i32> = Vec::new();
        for i in (0..prices.len()).rev() {
            let x = prices[i];
            while !stk.is_empty() && x < *stk.last().unwrap() {
                stk.pop();
            }
            if let Some(&top) = stk.last() {
                prices[i] -= top;
            }
            stk.push(x);
        }
        prices
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} prices
 * @return {number[]}
 */
var finalPrices = function (prices) {
    const stk = [];
    for (let i = prices.length - 1; ~i; --i) {
        const x = prices[i];
        while (stk.length && stk.at(-1) > x) {
            stk.pop();
        }
        prices[i] -= stk.at(-1) || 0;
        stk.push(x);
    }
    return prices;
};
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param Integer[] $prices
     * @return Integer[]
     */
    function finalPrices($prices) {
        $stk = [];
        $n = count($prices);

        for ($i = $n - 1; $i >= 0; $i--) {
            $x = $prices[$i];
            while (!empty($stk) && $x < end($stk)) {
                array_pop($stk);
            }
            if (!empty($stk)) {
                $prices[$i] -= end($stk);
            }
            $stk[] = $x;
        }

        return $prices;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个数组&nbsp;<code>prices</code>&nbsp;，其中&nbsp;<code>prices[i]</code>&nbsp;是商店里第&nbsp;<code>i</code>&nbsp;件商品的价格。</p>

<p>商店里正在进行促销活动，如果你要买第&nbsp;<code>i</code>&nbsp;件商品，那么你可以得到与 <code>prices[j]</code> 相等的折扣，其中&nbsp;<code>j</code>&nbsp;是满足&nbsp;<code>j &gt; i</code>&nbsp;且&nbsp;<code>prices[j] &lt;= prices[i]</code>&nbsp;的&nbsp;<strong>最小下标</strong>&nbsp;，如果没有满足条件的&nbsp;<code>j</code>&nbsp;，你将没有任何折扣。</p>

<p>请你返回一个数组，数组中第&nbsp;<code>i</code>&nbsp;个元素是折扣后你购买商品 <code>i</code>&nbsp;最终需要支付的价格。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>prices = [8,4,6,2,3]
<strong>输出：</strong>[4,2,4,2,3]
<strong>解释：</strong>
商品 0 的价格为 price[0]=8 ，你将得到 prices[1]=4 的折扣，所以最终价格为 8 - 4 = 4 。
商品 1 的价格为 price[1]=4 ，你将得到 prices[3]=2 的折扣，所以最终价格为 4 - 2 = 2 。
商品 2 的价格为 price[2]=6 ，你将得到 prices[3]=2 的折扣，所以最终价格为 6 - 2 = 4 。
商品 3 和 4 都没有折扣。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>prices = [1,2,3,4,5]
<strong>输出：</strong>[1,2,3,4,5]
<strong>解释：</strong>在这个例子中，所有商品都没有折扣。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>prices = [10,1,1,6]
<strong>输出：</strong>[9,0,1,6]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= prices.length &lt;= 500</code></li>
	<li><code>1 &lt;= prices[i] &lt;= 10^3</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：单调栈

题目实际上是求每个元素右侧第一个比它小的元素，可以使用单调栈来解决。

我们逆序遍历数组 $\textit{prices}$，利用单调栈找出左侧最近一个比当前元素小的元素，然后计算折扣。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 $\textit{prices}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def finalPrices(self, prices: List[int]) -> List[int]:
        stk = []
        for i in reversed(range(len(prices))):
            x = prices[i]
            while stk and x < stk[-1]:
                stk.pop()
            if stk:
                prices[i] -= stk[-1]
            stk.append(x)
        return prices
```

#### Java

```java
class Solution {
    public int[] finalPrices(int[] prices) {
        int n = prices.length;
        Deque<Integer> stk = new ArrayDeque<>();
        for (int i = n - 1; i >= 0; --i) {
            int x = prices[i];
            while (!stk.isEmpty() && stk.peek() > x) {
                stk.pop();
            }
            if (!stk.isEmpty()) {
                prices[i] -= stk.peek();
            }
            stk.push(x);
        }
        return prices;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> stk;
        for (int i = prices.size() - 1; ~i; --i) {
            int x = prices[i];
            while (!stk.empty() && stk.top() > x) {
                stk.pop();
            }
            if (!stk.empty()) {
                prices[i] -= stk.top();
            }
            stk.push(x);
        }
        return prices;
    }
};
```

#### Go

```go
func finalPrices(prices []int) []int {
	stk := []int{}
	for i := len(prices) - 1; i >= 0; i-- {
		x := prices[i]
		for len(stk) > 0 && stk[len(stk)-1] > x {
			stk = stk[:len(stk)-1]
		}
		if len(stk) > 0 {
			prices[i] -= stk[len(stk)-1]
		}
		stk = append(stk, x)
	}
	return prices
}
```

#### TypeScript

```ts
function finalPrices(prices: number[]): number[] {
    const stk: number[] = [];
    for (let i = prices.length - 1; ~i; --i) {
        const x = prices[i];
        while (stk.length && stk.at(-1)! > x) {
            stk.pop();
        }
        prices[i] -= stk.at(-1) || 0;
        stk.push(x);
    }
    return prices;
}
```

#### Rust

```rust
impl Solution {
    pub fn final_prices(mut prices: Vec<i32>) -> Vec<i32> {
        let mut stk: Vec<i32> = Vec::new();
        for i in (0..prices.len()).rev() {
            let x = prices[i];
            while !stk.is_empty() && x < *stk.last().unwrap() {
                stk.pop();
            }
            if let Some(&top) = stk.last() {
                prices[i] -= top;
            }
            stk.push(x);
        }
        prices
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} prices
 * @return {number[]}
 */
var finalPrices = function (prices) {
    const stk = [];
    for (let i = prices.length - 1; ~i; --i) {
        const x = prices[i];
        while (stk.length && stk.at(-1) > x) {
            stk.pop();
        }
        prices[i] -= stk.at(-1) || 0;
        stk.push(x);
    }
    return prices;
};
```

#### PHP

```php
class Solution {
    /**
     * @param Integer[] $prices
     * @return Integer[]
     */
    function finalPrices($prices) {
        $stk = [];
        $n = count($prices);

        for ($i = $n - 1; $i >= 0; $i--) {
            $x = $prices[$i];
            while (!empty($stk) && $x < end($stk)) {
                array_pop($stk);
            }
            if (!empty($stk)) {
                $prices[$i] -= end($stk);
            }
            $stk[] = $x;
        }

        return $prices;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1476. 子矩形查询](https://leetcode.cn/problems/subrectangle-queries){#1476}

{{< tabs "1476" >}}

{{% tab "python" %}}
```python
class SubrectangleQueries:
    def __init__(self, rectangle: List[List[int]]):
        self.g = rectangle
        self.ops = []

    def updateSubrectangle(
        self, row1: int, col1: int, row2: int, col2: int, newValue: int
    ) -> None:
        self.ops.append((row1, col1, row2, col2, newValue))

    def getValue(self, row: int, col: int) -> int:
        for r1, c1, r2, c2, v in self.ops[::-1]:
            if r1 <= row <= r2 and c1 <= col <= c2:
                return v
        return self.g[row][col]


# Your SubrectangleQueries object will be instantiated and called as such:
# obj = SubrectangleQueries(rectangle)
# obj.updateSubrectangle(row1,col1,row2,col2,newValue)
# param_2 = obj.getValue(row,col)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class SubrectangleQueries {
    private int[][] g;
    private LinkedList<int[]> ops = new LinkedList<>();

    public SubrectangleQueries(int[][] rectangle) {
        g = rectangle;
    }

    public void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        ops.addFirst(new int[] {row1, col1, row2, col2, newValue});
    }

    public int getValue(int row, int col) {
        for (var op : ops) {
            if (op[0] <= row && row <= op[2] && op[1] <= col && col <= op[3]) {
                return op[4];
            }
        }
        return g[row][col];
    }
}

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries obj = new SubrectangleQueries(rectangle);
 * obj.updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj.getValue(row,col);
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class SubrectangleQueries {
public:
    vector<vector<int>> g;
    vector<vector<int>> ops;

    SubrectangleQueries(vector<vector<int>>& rectangle) {
        g = rectangle;
    }

    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        ops.push_back({row1, col1, row2, col2, newValue});
    }

    int getValue(int row, int col) {
        for (int i = ops.size() - 1; ~i; --i) {
            auto op = ops[i];
            if (op[0] <= row && row <= op[2] && op[1] <= col && col <= op[3]) {
                return op[4];
            }
        }
        return g[row][col];
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type SubrectangleQueries struct {
	g   [][]int
	ops [][]int
}

func Constructor(rectangle [][]int) SubrectangleQueries {
	return SubrectangleQueries{rectangle, [][]int{}}
}

func (this *SubrectangleQueries) UpdateSubrectangle(row1 int, col1 int, row2 int, col2 int, newValue int) {
	this.ops = append(this.ops, []int{row1, col1, row2, col2, newValue})
}

func (this *SubrectangleQueries) GetValue(row int, col int) int {
	for i := len(this.ops) - 1; i >= 0; i-- {
		op := this.ops[i]
		if op[0] <= row && row <= op[2] && op[1] <= col && col <= op[3] {
			return op[4]
		}
	}
	return this.g[row][col]
}

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * obj := Constructor(rectangle);
 * obj.UpdateSubrectangle(row1,col1,row2,col2,newValue);
 * param_2 := obj.GetValue(row,col);
 */
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class SubrectangleQueries {
    g: number[][];
    ops: number[][];
    constructor(rectangle: number[][]) {
        this.g = rectangle;
        this.ops = [];
    }

    updateSubrectangle(
        row1: number,
        col1: number,
        row2: number,
        col2: number,
        newValue: number,
    ): void {
        this.ops.push([row1, col1, row2, col2, newValue]);
    }

    getValue(row: number, col: number): number {
        for (let i = this.ops.length - 1; ~i; --i) {
            const [r1, c1, r2, c2, v] = this.ops[i];
            if (r1 <= row && row <= r2 && c1 <= col && col <= c2) {
                return v;
            }
        }
        return this.g[row][col];
    }
}

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * var obj = new SubrectangleQueries(rectangle)
 * obj.updateSubrectangle(row1,col1,row2,col2,newValue)
 * var param_2 = obj.getValue(row,col)
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>请你实现一个类&nbsp;<code>SubrectangleQueries</code>&nbsp;，它的构造函数的参数是一个 <code>rows x cols</code>&nbsp;的矩形（这里用整数矩阵表示），并支持以下两种操作：</p>

<p>1.<code>&nbsp;updateSubrectangle(int row1, int col1, int row2, int col2, int newValue)</code></p>

<ul>
	<li>用&nbsp;<code>newValue</code>&nbsp;更新以&nbsp;<code>(row1,col1)</code>&nbsp;为左上角且以&nbsp;<code>(row2,col2)</code>&nbsp;为右下角的子矩形。</li>
</ul>

<p>2.<code>&nbsp;getValue(int row, int col)</code></p>

<ul>
	<li>返回矩形中坐标 <code>(row,col)</code> 的当前值。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>
[&quot;SubrectangleQueries&quot;,&quot;getValue&quot;,&quot;updateSubrectangle&quot;,&quot;getValue&quot;,&quot;getValue&quot;,&quot;updateSubrectangle&quot;,&quot;getValue&quot;,&quot;getValue&quot;]
[[[[1,2,1],[4,3,4],[3,2,1],[1,1,1]]],[0,2],[0,0,3,2,5],[0,2],[3,1],[3,0,3,2,10],[3,1],[0,2]]
<strong>输出：</strong>
[null,1,null,5,5,null,10,5]
<strong>解释：</strong>
SubrectangleQueries subrectangleQueries = new SubrectangleQueries([[1,2,1],[4,3,4],[3,2,1],[1,1,1]]);  
// 初始的 (4x3) 矩形如下：
// 1 2 1
// 4 3 4
// 3 2 1
// 1 1 1
subrectangleQueries.getValue(0, 2); // 返回 1
subrectangleQueries.updateSubrectangle(0, 0, 3, 2, 5);
// 此次更新后矩形变为：
// 5 5 5
// 5 5 5
// 5 5 5
// 5 5 5 
subrectangleQueries.getValue(0, 2); // 返回 5
subrectangleQueries.getValue(3, 1); // 返回 5
subrectangleQueries.updateSubrectangle(3, 0, 3, 2, 10);
// 此次更新后矩形变为：
// 5   5   5
// 5   5   5
// 5   5   5
// 10  10  10 
subrectangleQueries.getValue(3, 1); // 返回 10
subrectangleQueries.getValue(0, 2); // 返回 5
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>
[&quot;SubrectangleQueries&quot;,&quot;getValue&quot;,&quot;updateSubrectangle&quot;,&quot;getValue&quot;,&quot;getValue&quot;,&quot;updateSubrectangle&quot;,&quot;getValue&quot;]
[[[[1,1,1],[2,2,2],[3,3,3]]],[0,0],[0,0,2,2,100],[0,0],[2,2],[1,1,2,2,20],[2,2]]
<strong>输出：</strong>
[null,1,null,100,100,null,20]
<strong>解释：</strong>
SubrectangleQueries subrectangleQueries = new SubrectangleQueries([[1,1,1],[2,2,2],[3,3,3]]);
subrectangleQueries.getValue(0, 0); // 返回 1
subrectangleQueries.updateSubrectangle(0, 0, 2, 2, 100);
subrectangleQueries.getValue(0, 0); // 返回 100
subrectangleQueries.getValue(2, 2); // 返回 100
subrectangleQueries.updateSubrectangle(1, 1, 2, 2, 20);
subrectangleQueries.getValue(2, 2); // 返回 20
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>最多有&nbsp;<code>500</code>&nbsp;次<code>updateSubrectangle</code> 和&nbsp;<code>getValue</code>&nbsp;操作。</li>
	<li><code>1 &lt;= rows, cols &lt;= 100</code></li>
	<li><code>rows ==&nbsp;rectangle.length</code></li>
	<li><code>cols == rectangle[i].length</code></li>
	<li><code>0 &lt;= row1 &lt;= row2 &lt; rows</code></li>
	<li><code>0 &lt;= col1 &lt;= col2 &lt; cols</code></li>
	<li><code>1 &lt;= newValue, rectangle[i][j] &lt;= 10^9</code></li>
	<li><code>0 &lt;= row &lt; rows</code></li>
	<li><code>0 &lt;= col &lt; cols</code></li>
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
class SubrectangleQueries:
    def __init__(self, rectangle: List[List[int]]):
        self.g = rectangle
        self.ops = []

    def updateSubrectangle(
        self, row1: int, col1: int, row2: int, col2: int, newValue: int
    ) -> None:
        self.ops.append((row1, col1, row2, col2, newValue))

    def getValue(self, row: int, col: int) -> int:
        for r1, c1, r2, c2, v in self.ops[::-1]:
            if r1 <= row <= r2 and c1 <= col <= c2:
                return v
        return self.g[row][col]


# Your SubrectangleQueries object will be instantiated and called as such:
# obj = SubrectangleQueries(rectangle)
# obj.updateSubrectangle(row1,col1,row2,col2,newValue)
# param_2 = obj.getValue(row,col)
```

#### Java

```java
class SubrectangleQueries {
    private int[][] g;
    private LinkedList<int[]> ops = new LinkedList<>();

    public SubrectangleQueries(int[][] rectangle) {
        g = rectangle;
    }

    public void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        ops.addFirst(new int[] {row1, col1, row2, col2, newValue});
    }

    public int getValue(int row, int col) {
        for (var op : ops) {
            if (op[0] <= row && row <= op[2] && op[1] <= col && col <= op[3]) {
                return op[4];
            }
        }
        return g[row][col];
    }
}

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries obj = new SubrectangleQueries(rectangle);
 * obj.updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj.getValue(row,col);
 */
```

#### C++

```cpp
class SubrectangleQueries {
public:
    vector<vector<int>> g;
    vector<vector<int>> ops;

    SubrectangleQueries(vector<vector<int>>& rectangle) {
        g = rectangle;
    }

    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        ops.push_back({row1, col1, row2, col2, newValue});
    }

    int getValue(int row, int col) {
        for (int i = ops.size() - 1; ~i; --i) {
            auto op = ops[i];
            if (op[0] <= row && row <= op[2] && op[1] <= col && col <= op[3]) {
                return op[4];
            }
        }
        return g[row][col];
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */
```

#### Go

```go
type SubrectangleQueries struct {
	g   [][]int
	ops [][]int
}

func Constructor(rectangle [][]int) SubrectangleQueries {
	return SubrectangleQueries{rectangle, [][]int{}}
}

func (this *SubrectangleQueries) UpdateSubrectangle(row1 int, col1 int, row2 int, col2 int, newValue int) {
	this.ops = append(this.ops, []int{row1, col1, row2, col2, newValue})
}

func (this *SubrectangleQueries) GetValue(row int, col int) int {
	for i := len(this.ops) - 1; i >= 0; i-- {
		op := this.ops[i]
		if op[0] <= row && row <= op[2] && op[1] <= col && col <= op[3] {
			return op[4]
		}
	}
	return this.g[row][col]
}

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * obj := Constructor(rectangle);
 * obj.UpdateSubrectangle(row1,col1,row2,col2,newValue);
 * param_2 := obj.GetValue(row,col);
 */
```

#### TypeScript

```ts
class SubrectangleQueries {
    g: number[][];
    ops: number[][];
    constructor(rectangle: number[][]) {
        this.g = rectangle;
        this.ops = [];
    }

    updateSubrectangle(
        row1: number,
        col1: number,
        row2: number,
        col2: number,
        newValue: number,
    ): void {
        this.ops.push([row1, col1, row2, col2, newValue]);
    }

    getValue(row: number, col: number): number {
        for (let i = this.ops.length - 1; ~i; --i) {
            const [r1, c1, r2, c2, v] = this.ops[i];
            if (r1 <= row && row <= r2 && c1 <= col && col <= c2) {
                return v;
            }
        }
        return this.g[row][col];
    }
}

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * var obj = new SubrectangleQueries(rectangle)
 * obj.updateSubrectangle(row1,col1,row2,col2,newValue)
 * var param_2 = obj.getValue(row,col)
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1477. 找两个和为目标值且不重叠的子数组](https://leetcode.cn/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum){#1477}

{{< tabs "1477" >}}

{{% tab "python" %}}
```python
class Solution:
    def minSumOfLengths(self, arr: List[int], target: int) -> int:
        d = {0: 0}
        s, n = 0, len(arr)
        f = [inf] * (n + 1)
        ans = inf
        for i, v in enumerate(arr, 1):
            s += v
            f[i] = f[i - 1]
            if s - target in d:
                j = d[s - target]
                f[i] = min(f[i], i - j)
                ans = min(ans, f[j] + i - j)
            d[s] = i
        return -1 if ans > n else ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minSumOfLengths(int[] arr, int target) {
        Map<Integer, Integer> d = new HashMap<>();
        d.put(0, 0);
        int n = arr.length;
        int[] f = new int[n + 1];
        final int inf = 1 << 30;
        f[0] = inf;
        int s = 0, ans = inf;
        for (int i = 1; i <= n; ++i) {
            int v = arr[i - 1];
            s += v;
            f[i] = f[i - 1];
            if (d.containsKey(s - target)) {
                int j = d.get(s - target);
                f[i] = Math.min(f[i], i - j);
                ans = Math.min(ans, f[j] + i - j);
            }
            d.put(s, i);
        }
        return ans > n ? -1 : ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        unordered_map<int, int> d;
        d[0] = 0;
        int s = 0, n = arr.size();
        int f[n + 1];
        const int inf = 1 << 30;
        f[0] = inf;
        int ans = inf;
        for (int i = 1; i <= n; ++i) {
            int v = arr[i - 1];
            s += v;
            f[i] = f[i - 1];
            if (d.count(s - target)) {
                int j = d[s - target];
                f[i] = min(f[i], i - j);
                ans = min(ans, f[j] + i - j);
            }
            d[s] = i;
        }
        return ans > n ? -1 : ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minSumOfLengths(arr []int, target int) int {
	d := map[int]int{0: 0}
	const inf = 1 << 30
	s, n := 0, len(arr)
	f := make([]int, n+1)
	f[0] = inf
	ans := inf
	for i, v := range arr {
		i++
		f[i] = f[i-1]
		s += v
		if j, ok := d[s-target]; ok {
			f[i] = min(f[i], i-j)
			ans = min(ans, f[j]+i-j)
		}
		d[s] = i
	}
	if ans > n {
		return -1
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minSumOfLengths(arr: number[], target: number): number {
    const d = new Map<number, number>();
    d.set(0, 0);
    let s = 0;
    const n = arr.length;
    const f: number[] = Array(n + 1);
    const inf = 1 << 30;
    f[0] = inf;
    let ans = inf;
    for (let i = 1; i <= n; ++i) {
        const v = arr[i - 1];
        s += v;
        f[i] = f[i - 1];
        if (d.has(s - target)) {
            const j = d.get(s - target)!;
            f[i] = Math.min(f[i], i - j);
            ans = Math.min(ans, f[j] + i - j);
        }
        d.set(s, i);
    }
    return ans > n ? -1 : ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组&nbsp;<code>arr</code> 和一个整数值&nbsp;<code>target</code>&nbsp;。</p>

<p>请你在 <code>arr</code>&nbsp;中找 <strong>两个互不重叠的子数组</strong>&nbsp;且它们的和都等于&nbsp;<code>target</code>&nbsp;。可能会有多种方案，请你返回满足要求的两个子数组长度和的 <strong>最小值</strong> 。</p>

<p>请返回满足要求的最小长度和，如果无法找到这样的两个子数组，请返回 <strong>-1</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>arr = [3,2,2,4,3], target = 3
<strong>输出：</strong>2
<strong>解释：</strong>只有两个子数组和为 3 （[3] 和 [3]）。它们的长度和为 2 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>arr = [7,3,4,7], target = 7
<strong>输出：</strong>2
<strong>解释：</strong>尽管我们有 3 个互不重叠的子数组和为 7 （[7], [3,4] 和 [7]），但我们会选择第一个和第三个子数组，因为它们的长度和 2 是最小值。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>arr = [4,3,2,6,2,3,4], target = 6
<strong>输出：</strong>-1
<strong>解释：</strong>我们只有一个和为 6 的子数组。
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>arr = [5,5,4,4,5], target = 3
<strong>输出：</strong>-1
<strong>解释：</strong>我们无法找到和为 3 的子数组。
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>arr = [3,1,1,1,5,1,2,1], target = 3
<strong>输出：</strong>3
<strong>解释：</strong>注意子数组 [1,2] 和 [2,1] 不能成为一个方案因为它们重叠了。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 10^5</code></li>
	<li><code>1 &lt;= arr[i] &lt;= 1000</code></li>
	<li><code>1 &lt;= target &lt;= 10^8</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 前缀和 + 动态规划

我们可以使用哈希表 $d$ 记录前缀和最近一次出现的位置，初始时 $d[0]=0$。

定义 $f[i]$ 表示前 $i$ 个元素中，长度和为 $target$ 的最短子数组的长度。初始时 $f[0]= \infty$。

遍历数组 $\textit{arr}$，对于当前位置 $i$，计算前缀和 $s$，如果 $s - \textit{target}$ 在哈希表中，记 $j=d[s - \textit{target}]$，则 $f[i]=\min(f[i], i - j)$，答案为 $ans=\min(ans, f[j] + i - j)$。继续遍历下个位置。

最后，如果答案大于数组长度，则返回 $-1$，否则返回答案。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minSumOfLengths(self, arr: List[int], target: int) -> int:
        d = {0: 0}
        s, n = 0, len(arr)
        f = [inf] * (n + 1)
        ans = inf
        for i, v in enumerate(arr, 1):
            s += v
            f[i] = f[i - 1]
            if s - target in d:
                j = d[s - target]
                f[i] = min(f[i], i - j)
                ans = min(ans, f[j] + i - j)
            d[s] = i
        return -1 if ans > n else ans
```

#### Java

```java
class Solution {
    public int minSumOfLengths(int[] arr, int target) {
        Map<Integer, Integer> d = new HashMap<>();
        d.put(0, 0);
        int n = arr.length;
        int[] f = new int[n + 1];
        final int inf = 1 << 30;
        f[0] = inf;
        int s = 0, ans = inf;
        for (int i = 1; i <= n; ++i) {
            int v = arr[i - 1];
            s += v;
            f[i] = f[i - 1];
            if (d.containsKey(s - target)) {
                int j = d.get(s - target);
                f[i] = Math.min(f[i], i - j);
                ans = Math.min(ans, f[j] + i - j);
            }
            d.put(s, i);
        }
        return ans > n ? -1 : ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        unordered_map<int, int> d;
        d[0] = 0;
        int s = 0, n = arr.size();
        int f[n + 1];
        const int inf = 1 << 30;
        f[0] = inf;
        int ans = inf;
        for (int i = 1; i <= n; ++i) {
            int v = arr[i - 1];
            s += v;
            f[i] = f[i - 1];
            if (d.count(s - target)) {
                int j = d[s - target];
                f[i] = min(f[i], i - j);
                ans = min(ans, f[j] + i - j);
            }
            d[s] = i;
        }
        return ans > n ? -1 : ans;
    }
};
```

#### Go

```go
func minSumOfLengths(arr []int, target int) int {
	d := map[int]int{0: 0}
	const inf = 1 << 30
	s, n := 0, len(arr)
	f := make([]int, n+1)
	f[0] = inf
	ans := inf
	for i, v := range arr {
		i++
		f[i] = f[i-1]
		s += v
		if j, ok := d[s-target]; ok {
			f[i] = min(f[i], i-j)
			ans = min(ans, f[j]+i-j)
		}
		d[s] = i
	}
	if ans > n {
		return -1
	}
	return ans
}
```

#### TypeScript

```ts
function minSumOfLengths(arr: number[], target: number): number {
    const d = new Map<number, number>();
    d.set(0, 0);
    let s = 0;
    const n = arr.length;
    const f: number[] = Array(n + 1);
    const inf = 1 << 30;
    f[0] = inf;
    let ans = inf;
    for (let i = 1; i <= n; ++i) {
        const v = arr[i - 1];
        s += v;
        f[i] = f[i - 1];
        if (d.has(s - target)) {
            const j = d.get(s - target)!;
            f[i] = Math.min(f[i], i - j);
            ans = Math.min(ans, f[j] + i - j);
        }
        d.set(s, i);
    }
    return ans > n ? -1 : ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1478. 安排邮筒](https://leetcode.cn/problems/allocate-mailboxes){#1478}

{{< tabs "1478" >}}

{{% tab "python" %}}
```python
class Solution:
    def minDistance(self, houses: List[int], k: int) -> int:
        houses.sort()
        n = len(houses)
        g = [[0] * n for _ in range(n)]
        for i in range(n - 2, -1, -1):
            for j in range(i + 1, n):
                g[i][j] = g[i + 1][j - 1] + houses[j] - houses[i]
        f = [[inf] * (k + 1) for _ in range(n)]
        for i in range(n):
            f[i][1] = g[0][i]
            for j in range(2, min(k + 1, i + 2)):
                for p in range(i):
                    f[i][j] = min(f[i][j], f[p][j - 1] + g[p + 1][i])
        return f[-1][k]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minDistance(int[] houses, int k) {
        Arrays.sort(houses);
        int n = houses.length;
        int[][] g = new int[n][n];
        for (int i = n - 2; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                g[i][j] = g[i + 1][j - 1] + houses[j] - houses[i];
            }
        }
        int[][] f = new int[n][k + 1];
        final int inf = 1 << 30;
        for (int[] e : f) {
            Arrays.fill(e, inf);
        }
        for (int i = 0; i < n; ++i) {
            f[i][1] = g[0][i];
            for (int j = 2; j <= k && j <= i + 1; ++j) {
                for (int p = 0; p < i; ++p) {
                    f[i][j] = Math.min(f[i][j], f[p][j - 1] + g[p + 1][i]);
                }
            }
        }
        return f[n - 1][k];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minDistance(vector<int>& houses, int k) {
        int n = houses.size();
        sort(houses.begin(), houses.end());
        int g[n][n];
        memset(g, 0, sizeof(g));
        for (int i = n - 2; ~i; --i) {
            for (int j = i + 1; j < n; ++j) {
                g[i][j] = g[i + 1][j - 1] + houses[j] - houses[i];
            }
        }
        int f[n][k + 1];
        memset(f, 0x3f, sizeof(f));
        for (int i = 0; i < n; ++i) {
            f[i][1] = g[0][i];
            for (int j = 1; j <= k && j <= i + 1; ++j) {
                for (int p = 0; p < i; ++p) {
                    f[i][j] = min(f[i][j], f[p][j - 1] + g[p + 1][i]);
                }
            }
        }
        return f[n - 1][k];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minDistance(houses []int, k int) int {
	sort.Ints(houses)
	n := len(houses)
	g := make([][]int, n)
	f := make([][]int, n)
	const inf = 1 << 30
	for i := range g {
		g[i] = make([]int, n)
		f[i] = make([]int, k+1)
		for j := range f[i] {
			f[i][j] = inf
		}
	}
	for i := n - 2; i >= 0; i-- {
		for j := i + 1; j < n; j++ {
			g[i][j] = g[i+1][j-1] + houses[j] - houses[i]
		}
	}
	for i := 0; i < n; i++ {
		f[i][1] = g[0][i]
		for j := 2; j <= k && j <= i+1; j++ {
			for p := 0; p < i; p++ {
				f[i][j] = min(f[i][j], f[p][j-1]+g[p+1][i])
			}
		}
	}
	return f[n-1][k]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minDistance(houses: number[], k: number): number {
    houses.sort((a, b) => a - b);
    const n = houses.length;
    const g: number[][] = Array.from({ length: n }, () => Array(n).fill(0));

    for (let i = n - 2; i >= 0; i--) {
        for (let j = i + 1; j < n; j++) {
            g[i][j] = g[i + 1][j - 1] + houses[j] - houses[i];
        }
    }

    const inf = Number.POSITIVE_INFINITY;
    const f: number[][] = Array.from({ length: n }, () => Array(k + 1).fill(inf));

    for (let i = 0; i < n; i++) {
        f[i][1] = g[0][i];
    }

    for (let j = 2; j <= k; j++) {
        for (let i = j - 1; i < n; i++) {
            for (let p = i - 1; p >= 0; p--) {
                f[i][j] = Math.min(f[i][j], f[p][j - 1] + g[p + 1][i]);
            }
        }
    }

    return f[n - 1][k];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个房屋数组<code>houses</code>&nbsp;和一个整数&nbsp;<code>k</code>&nbsp;，其中&nbsp;<code>houses[i]</code>&nbsp;是第 <code>i</code>&nbsp;栋房子在一条街上的位置，现需要在这条街上安排 <code>k</code>&nbsp;个邮筒。</p>

<p>请你返回每栋房子与离它最近的邮筒之间的距离的 <strong>最小 </strong>总和。</p>

<p>答案保证在 32 位有符号整数范围以内。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1400-1499/1478.Allocate%20Mailboxes/images/sample_11_1816.png" style="height: 154px; width: 454px;"></p>

<pre><strong>输入：</strong>houses = [1,4,8,10,20], k = 3
<strong>输出：</strong>5
<strong>解释：</strong>将邮筒分别安放在位置 3， 9 和 20 处。
每个房子到最近邮筒的距离和为 |3-1| + |4-3| + |9-8| + |10-9| + |20-20| = 5 。
</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1400-1499/1478.Allocate%20Mailboxes/images/sample_2_1816.png" style="height: 154px; width: 433px;"></strong></p>

<pre><strong>输入：</strong>houses = [2,3,5,12,18], k = 2
<strong>输出：</strong>9
<strong>解释：</strong>将邮筒分别安放在位置 3 和 14 处。
每个房子到最近邮筒距离和为 |2-3| + |3-3| + |5-3| + |12-14| + |18-14| = 9 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>houses = [7,4,6,1], k = 1
<strong>输出：</strong>8
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>houses = [3,6,14,10], k = 4
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == houses.length</code></li>
	<li><code>1 &lt;= n&nbsp;&lt;= 100</code></li>
	<li><code>1 &lt;= houses[i] &lt;= 10^4</code></li>
	<li><code>1 &lt;= k &lt;= n</code></li>
	<li>数组&nbsp;<code>houses</code>&nbsp;中的整数互不相同。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i][j]$ 表示前 $i+1$ 栋房子，安排了 $j$ 个邮筒时，每栋房子与离它最近的邮筒之间的距离的最小总和。初始时 $f[i][j]=\infty$，答案即为 $f[n-1][k]$。

我们可以枚举第 $j-1$ 个邮筒“管辖”的最后一栋房子 $p$，即 $0 \leq p \leq i-1$，那么第 $j$ 个邮筒“管辖”的房子就是 $[p+1,..i]$，我们记 $g[i][j]$ 表示给房子 $[i,..j]$ 安排一个邮筒的最小总和，那么有状态转移方程：

$$
f[i][j] = \min_{0 \leq p \leq i-1} \{f[p][j-1] + g[p+1][i]\}
$$

其中 $g[i][j]$ 的计算方法如下：

$$
g[i][j] = g[i + 1][j - 1] + \textit{houses}[j] - \textit{houses}[i]
$$

时间复杂度 $O(n^2 \times k)$，空间复杂度 $O(n^2)$。其中 $n$ 为房子的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minDistance(self, houses: List[int], k: int) -> int:
        houses.sort()
        n = len(houses)
        g = [[0] * n for _ in range(n)]
        for i in range(n - 2, -1, -1):
            for j in range(i + 1, n):
                g[i][j] = g[i + 1][j - 1] + houses[j] - houses[i]
        f = [[inf] * (k + 1) for _ in range(n)]
        for i in range(n):
            f[i][1] = g[0][i]
            for j in range(2, min(k + 1, i + 2)):
                for p in range(i):
                    f[i][j] = min(f[i][j], f[p][j - 1] + g[p + 1][i])
        return f[-1][k]
```

#### Java

```java
class Solution {
    public int minDistance(int[] houses, int k) {
        Arrays.sort(houses);
        int n = houses.length;
        int[][] g = new int[n][n];
        for (int i = n - 2; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                g[i][j] = g[i + 1][j - 1] + houses[j] - houses[i];
            }
        }
        int[][] f = new int[n][k + 1];
        final int inf = 1 << 30;
        for (int[] e : f) {
            Arrays.fill(e, inf);
        }
        for (int i = 0; i < n; ++i) {
            f[i][1] = g[0][i];
            for (int j = 2; j <= k && j <= i + 1; ++j) {
                for (int p = 0; p < i; ++p) {
                    f[i][j] = Math.min(f[i][j], f[p][j - 1] + g[p + 1][i]);
                }
            }
        }
        return f[n - 1][k];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minDistance(vector<int>& houses, int k) {
        int n = houses.size();
        sort(houses.begin(), houses.end());
        int g[n][n];
        memset(g, 0, sizeof(g));
        for (int i = n - 2; ~i; --i) {
            for (int j = i + 1; j < n; ++j) {
                g[i][j] = g[i + 1][j - 1] + houses[j] - houses[i];
            }
        }
        int f[n][k + 1];
        memset(f, 0x3f, sizeof(f));
        for (int i = 0; i < n; ++i) {
            f[i][1] = g[0][i];
            for (int j = 1; j <= k && j <= i + 1; ++j) {
                for (int p = 0; p < i; ++p) {
                    f[i][j] = min(f[i][j], f[p][j - 1] + g[p + 1][i]);
                }
            }
        }
        return f[n - 1][k];
    }
};
```

#### Go

```go
func minDistance(houses []int, k int) int {
	sort.Ints(houses)
	n := len(houses)
	g := make([][]int, n)
	f := make([][]int, n)
	const inf = 1 << 30
	for i := range g {
		g[i] = make([]int, n)
		f[i] = make([]int, k+1)
		for j := range f[i] {
			f[i][j] = inf
		}
	}
	for i := n - 2; i >= 0; i-- {
		for j := i + 1; j < n; j++ {
			g[i][j] = g[i+1][j-1] + houses[j] - houses[i]
		}
	}
	for i := 0; i < n; i++ {
		f[i][1] = g[0][i]
		for j := 2; j <= k && j <= i+1; j++ {
			for p := 0; p < i; p++ {
				f[i][j] = min(f[i][j], f[p][j-1]+g[p+1][i])
			}
		}
	}
	return f[n-1][k]
}
```

#### TypeScript

```ts
function minDistance(houses: number[], k: number): number {
    houses.sort((a, b) => a - b);
    const n = houses.length;
    const g: number[][] = Array.from({ length: n }, () => Array(n).fill(0));

    for (let i = n - 2; i >= 0; i--) {
        for (let j = i + 1; j < n; j++) {
            g[i][j] = g[i + 1][j - 1] + houses[j] - houses[i];
        }
    }

    const inf = Number.POSITIVE_INFINITY;
    const f: number[][] = Array.from({ length: n }, () => Array(k + 1).fill(inf));

    for (let i = 0; i < n; i++) {
        f[i][1] = g[0][i];
    }

    for (let j = 2; j <= k; j++) {
        for (let i = j - 1; i < n; i++) {
            for (let p = i - 1; p >= 0; p--) {
                f[i][j] = Math.min(f[i][j], f[p][j - 1] + g[p + 1][i]);
            }
        }
    }

    return f[n - 1][k];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1479. 周内每天的销售情况 🔒](https://leetcode.cn/problems/sales-by-day-of-the-week){#1479}

{{< tabs "1479" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT
    item_category AS category,
    SUM(IF(DAYOFWEEK(order_date) = '2', quantity, 0)) AS Monday,
    SUM(IF(DAYOFWEEK(order_date) = '3', quantity, 0)) AS Tuesday,
    SUM(IF(DAYOFWEEK(order_date) = '4', quantity, 0)) AS Wednesday,
    SUM(IF(DAYOFWEEK(order_date) = '5', quantity, 0)) AS Thursday,
    SUM(IF(DAYOFWEEK(order_date) = '6', quantity, 0)) AS Friday,
    SUM(IF(DAYOFWEEK(order_date) = '7', quantity, 0)) AS Saturday,
    SUM(IF(DAYOFWEEK(order_date) = '1', quantity, 0)) AS Sunday
FROM
    Orders AS o
    RIGHT JOIN Items AS i ON o.item_id = i.item_id
GROUP BY category
ORDER BY category;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code>Orders</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| order_id      | int     |
| customer_id   | int     |
| order_date    | date    | 
| item_id       | varchar |
| quantity      | int     |
+---------------+---------+
(order_id, item_id) 是该表主键(具有唯一值的列的组合)
该表包含了订单信息
order_date 是id为 item_id 的商品被id为 customer_id 的消费者订购的日期.</pre>

<p>表：<code>Items</code></p>

<pre>
+---------------------+---------+
| Column Name         | Type    |
+---------------------+---------+
| item_id             | varchar |
| item_name           | varchar |
| item_category       | varchar |
+---------------------+---------+
item_id 是该表主键(具有唯一值的列)
item_name 是商品的名字
item_category&nbsp;是商品的类别
</pre>

<p>&nbsp;</p>

<p>你是企业主，想要获得分类商品和周内每天的销售报告。</p>

<p>编写解决方案，报告 <strong>周内每天 </strong>每个商品类别下订购了多少单位。</p>

<p>返回结果表单<strong> 按商品类别排序 </strong>。</p>

<p>结果格式如下例所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<code><strong>输入：</strong>
Orders</code> 表：
+------------+--------------+-------------+--------------+-------------+
| order_id   | customer_id  | order_date  | item_id      | quantity    |
+------------+--------------+-------------+--------------+-------------+
| 1          | 1            | 2020-06-01  | 1            | 10          |
| 2          | 1            | 2020-06-08  | 2            | 10          |
| 3          | 2            | 2020-06-02  | 1            | 5           |
| 4          | 3            | 2020-06-03  | 3            | 5           |
| 5          | 4            | 2020-06-04  | 4            | 1           |
| 6          | 4            | 2020-06-05  | 5            | 5           |
| 7          | 5            | 2020-06-05  | 1            | 10          |
| 8          | 5            | 2020-06-14  | 4            | 5           |
| 9          | 5            | 2020-06-21  | 3            | 5           |
+------------+--------------+-------------+--------------+-------------+

<code>Items</code> 表：
+------------+----------------+---------------+
| item_id    | item_name      | item_category |
+------------+----------------+---------------+
| 1          | LC Alg. Book   | Book          |
| 2          | LC DB. Book    | Book          |
| 3          | LC SmarthPhone | Phone         |
| 4          | LC Phone 2020  | Phone         |
| 5          | LC SmartGlass  | Glasses       |
| 6          | LC T-Shirt XL  | T-Shirt       |
+------------+----------------+---------------+
<strong>输出：</strong>
+------------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+
| Category   | Monday    | Tuesday   | Wednesday | Thursday  | Friday    | Saturday  | Sunday    |
+------------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+
| Book       | 20        | 5         | 0         | 0         | 10        | 0         | 0         |
| Glasses    | 0         | 0         | 0         | 0         | 5         | 0         | 0         |
| Phone      | 0         | 0         | 5         | 1         | 0         | 0         | 10        |
| T-Shirt    | 0         | 0         | 0         | 0         | 0         | 0         | 0         |
+------------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+
<strong>解释：</strong>
在周一(2020-06-01, 2020-06-08)，Book分类(ids: 1, 2)下，总共销售了20个单位(10 + 10)
在周二(2020-06-02)，Book分类(ids: 1, 2)下，总共销售了5个单位
在周三(2020-06-03)，Phone分类(ids: 3, 4)下，总共销售了5个单位
在周四(2020-06-04)，Phone分类(ids: 3, 4)下，总共销售了1个单位
在周五(2020-06-05)，Book分类(ids: 1, 2)下，总共销售了10个单位，Glasses分类(ids: 5)下，总共销售了5个单位
在周六, 没有商品销售
在周天(2020-06-14, 2020-06-21)，Phone分类(ids: 3, 4)下，总共销售了10个单位(5 + 5)
没有销售 T-Shirt 类别的商品</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT
    item_category AS category,
    SUM(IF(DAYOFWEEK(order_date) = '2', quantity, 0)) AS Monday,
    SUM(IF(DAYOFWEEK(order_date) = '3', quantity, 0)) AS Tuesday,
    SUM(IF(DAYOFWEEK(order_date) = '4', quantity, 0)) AS Wednesday,
    SUM(IF(DAYOFWEEK(order_date) = '5', quantity, 0)) AS Thursday,
    SUM(IF(DAYOFWEEK(order_date) = '6', quantity, 0)) AS Friday,
    SUM(IF(DAYOFWEEK(order_date) = '7', quantity, 0)) AS Saturday,
    SUM(IF(DAYOFWEEK(order_date) = '1', quantity, 0)) AS Sunday
FROM
    Orders AS o
    RIGHT JOIN Items AS i ON o.item_id = i.item_id
GROUP BY category
ORDER BY category;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
