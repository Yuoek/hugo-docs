---
title: "0630_课程表 III"
date: 2025-10-08T18:36:23+08:00
weight: 4
tags: [二分查找, 二叉树, 位运算, 动态规划, 双指针, 哈希表, 回溯, 图, 堆（优先队列）, 字符串, 广度优先搜索, 拓扑排序, 排序, 数学, 数组, 有序集合, 栈, 树, 深度优先搜索, 滑动窗口, 状态压缩, 矩阵, 组合数学, 记忆化搜索, 设计, 贪心]
---

{{< markmap >}}
### [0630_课程表 III](#630)
#### [贪心](#630)
#### [数组](#630)
#### [排序](#630)
#### [堆（优先队列）](#630)
### [0631_设计 Excel 求和公式 🔒](#631)
#### [图](#631)
#### [设计](#631)
#### [拓扑排序](#631)
#### [数组](#631)
#### [哈希表](#631)
#### [字符串](#631)
#### [矩阵](#631)
### [0632_最小区间](#632)
#### [贪心](#632)
#### [数组](#632)
#### [哈希表](#632)
#### [排序](#632)
#### [滑动窗口](#632)
#### [堆（优先队列）](#632)
### [0633_平方数之和](#633)
#### [数学](#633)
#### [双指针](#633)
#### [二分查找](#633)
### [0634_寻找数组的错位排列 🔒](#634)
#### [数学](#634)
#### [动态规划](#634)
#### [组合数学](#634)
### [0635_设计日志存储系统 🔒](#635)
#### [设计](#635)
#### [哈希表](#635)
#### [字符串](#635)
#### [有序集合](#635)
### [0636_函数的独占时间](#636)
#### [栈](#636)
#### [数组](#636)
### [0637_二叉树的层平均值](#637)
#### [树](#637)
#### [深度优先搜索](#637)
#### [广度优先搜索](#637)
#### [二叉树](#637)
### [0638_大礼包](#638)
#### [位运算](#638)
#### [记忆化搜索](#638)
#### [数组](#638)
#### [动态规划](#638)
#### [回溯](#638)
#### [状态压缩](#638)
### [0639_解码方法 II](#639)
#### [字符串](#639)
#### [动态规划](#639)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0630_课程表 III
___
#### 贪心
___
#### 数组
___
#### 排序
___
#### 堆（优先队列）
---
### 0631_设计 Excel 求和公式 🔒
___
#### 图
___
#### 设计
___
#### 拓扑排序
___
#### 数组
___
#### 哈希表
___
#### 字符串
___
#### 矩阵
---
### 0632_最小区间
___
#### 贪心
___
#### 数组
___
#### 哈希表
___
#### 排序
___
#### 滑动窗口
___
#### 堆（优先队列）
---
### 0633_平方数之和
___
#### 数学
___
#### 双指针
___
#### 二分查找
---
### 0634_寻找数组的错位排列 🔒
___
#### 数学
___
#### 动态规划
___
#### 组合数学
---
### 0635_设计日志存储系统 🔒
___
#### 设计
___
#### 哈希表
___
#### 字符串
___
#### 有序集合
---
### 0636_函数的独占时间
___
#### 栈
___
#### 数组
---
### 0637_二叉树的层平均值
___
#### 树
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 二叉树
---
### 0638_大礼包
___
#### 位运算
___
#### 记忆化搜索
___
#### 数组
___
#### 动态规划
___
#### 回溯
___
#### 状态压缩
---
### 0639_解码方法 II
___
#### 字符串
___
#### 动态规划
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 二叉树 | 位运算 |
| 动态规划 | 双指针 | 哈希表 |
| 回溯 | 图 | 堆（优先队列） |
| 字符串 | 广度优先搜索 | 拓扑排序 |
| 排序 | 数学 | 数组 |
| 有序集合 | 栈 | 树 |
| 深度优先搜索 | 滑动窗口 | 状态压缩 |
| 矩阵 | 组合数学 | 记忆化搜索 |
| 设计 | 贪心 |  |

# [630. 课程表 III](https://leetcode.cn/problems/course-schedule-iii){#630}

{{< tabs "630" >}}

{{% tab "python" %}}
```python
class Solution:
    def scheduleCourse(self, courses: List[List[int]]) -> int:
        courses.sort(key=lambda x: x[1])
        pq = []
        s = 0
        for duration, last in courses:
            heappush(pq, -duration)
            s += duration
            while s > last:
                s += heappop(pq)
        return len(pq)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int scheduleCourse(int[][] courses) {
        Arrays.sort(courses, (a, b) -> a[1] - b[1]);
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> b - a);
        int s = 0;
        for (var e : courses) {
            int duration = e[0], last = e[1];
            pq.offer(duration);
            s += duration;
            while (s > last) {
                s -= pq.poll();
            }
        }
        return pq.size();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        priority_queue<int> pq;
        int s = 0;
        for (auto& e : courses) {
            int duration = e[0], last = e[1];
            pq.push(duration);
            s += duration;
            while (s > last) {
                s -= pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func scheduleCourse(courses [][]int) int {
	sort.Slice(courses, func(i, j int) bool { return courses[i][1] < courses[j][1] })
	pq := &hp{}
	s := 0
	for _, e := range courses {
		duration, last := e[0], e[1]
		s += duration
		pq.push(duration)
		for s > last {
			s -= pq.pop()
		}
	}
	return pq.Len()
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
function scheduleCourse(courses: number[][]): number {
    courses.sort((a, b) => a[1] - b[1]);
    const pq = new MaxPriorityQueue<number>();
    let s = 0;
    for (const [duration, last] of courses) {
        pq.enqueue(duration);
        s += duration;
        while (s > last) {
            s -= pq.dequeue();
        }
    }
    return pq.size();
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>这里有 <code>n</code> 门不同的在线课程，按从 <code>1</code> 到 <code>n</code>&nbsp;编号。给你一个数组 <code>courses</code> ，其中 <code>courses[i] = [duration<sub>i</sub>, lastDay<sub>i</sub>]</code> 表示第 <code>i</code> 门课将会 <strong>持续</strong> 上 <code>duration<sub>i</sub></code> 天课，并且必须在不晚于 <code>lastDay<sub>i</sub></code> 的时候完成。</p>

<p>你的学期从第 <code>1</code> 天开始。且不能同时修读两门及两门以上的课程。</p>

<p>返回你最多可以修读的课程数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>courses = [[100, 200], [200, 1300], [1000, 1250], [2000, 3200]]
<strong>输出：</strong>3
<strong>解释：</strong>
这里一共有 4 门课程，但是你最多可以修 3 门：
首先，修第 1 门课，耗费 100 天，在第 100 天完成，在第 101 天开始下门课。
第二，修第 3 门课，耗费 1000 天，在第 1100 天完成，在第 1101 天开始下门课程。
第三，修第 2 门课，耗时 200 天，在第 1300 天完成。
第 4 门课现在不能修，因为将会在第 3300 天完成它，这已经超出了关闭日期。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>courses = [[1,2]]
<strong>输出：</strong>1
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>courses = [[3,2],[4,3]]
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= courses.length &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= duration<sub>i</sub>, lastDay<sub>i</sub> &lt;= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 优先队列（大根堆）

我们可以按照课程的结束时间进行升序排序，每次选择结束时间最早的课程进行上课。

如果已选择的课程的总时间 $s$ 超过了当前课程的结束时间 $last$，那么我们就将此前选择的课程中耗时最长的课程去掉，直到能够满足当前课程的结束时间为止。这里我们使用一个优先队列（大根堆） $pq$ 来维护当前已经选择的课程的耗时，每次我们都从优先队列中取出耗时最长的课程进行去除。

最后，优先队列中的元素个数即为我们能够选择的课程数目。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 是课程数目。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def scheduleCourse(self, courses: List[List[int]]) -> int:
        courses.sort(key=lambda x: x[1])
        pq = []
        s = 0
        for duration, last in courses:
            heappush(pq, -duration)
            s += duration
            while s > last:
                s += heappop(pq)
        return len(pq)
```

#### Java

```java
class Solution {
    public int scheduleCourse(int[][] courses) {
        Arrays.sort(courses, (a, b) -> a[1] - b[1]);
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> b - a);
        int s = 0;
        for (var e : courses) {
            int duration = e[0], last = e[1];
            pq.offer(duration);
            s += duration;
            while (s > last) {
                s -= pq.poll();
            }
        }
        return pq.size();
    }
}
```

#### C++

```cpp
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        priority_queue<int> pq;
        int s = 0;
        for (auto& e : courses) {
            int duration = e[0], last = e[1];
            pq.push(duration);
            s += duration;
            while (s > last) {
                s -= pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};
```

#### Go

```go
func scheduleCourse(courses [][]int) int {
	sort.Slice(courses, func(i, j int) bool { return courses[i][1] < courses[j][1] })
	pq := &hp{}
	s := 0
	for _, e := range courses {
		duration, last := e[0], e[1]
		s += duration
		pq.push(duration)
		for s > last {
			s -= pq.pop()
		}
	}
	return pq.Len()
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
function scheduleCourse(courses: number[][]): number {
    courses.sort((a, b) => a[1] - b[1]);
    const pq = new MaxPriorityQueue<number>();
    let s = 0;
    for (const [duration, last] of courses) {
        pq.enqueue(duration);
        s += duration;
        while (s > last) {
            s -= pq.dequeue();
        }
    }
    return pq.size();
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [631. 设计 Excel 求和公式 🔒](https://leetcode.cn/problems/design-excel-sum-formula){#631}

{{< tabs "631" >}}

{{% tab "python" %}}
```python

```
{{% /tab %}}
{{% tab "java" %}}
```java

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

<p>请你设计 <strong>Excel</strong> 中的基本功能，并实现求和公式。</p>

<p>实现 <code>Excel</code> 类：</p>

<ul>
	<li><code>Excel(int height, char width)</code>：用高度&nbsp;<code>height</code> 和宽度&nbsp;<code>width</code> 初始化对象。该表格是一个大小为 <code>height x width</code> 的整数矩阵 <code>mat</code>，其中行下标范围是 <code>[1, height]</code> ，列下标范围是 <code>['A', width]</code> 。初始情况下，所有的值都应该为 <strong>零</strong> 。</li>
	<li><code>void set(int row, char column, int val)</code>：将 <code>mat[row][column]</code> 的值更改为 <code>val</code> 。</li>
	<li><code>int get(int row, char column)</code>：返回 <code>mat[row][column]</code> 的值。</li>
	<li><code>int sum(int row, char column, List&lt;String&gt; numbers)</code>：将 <code>mat[row][column]</code> 的值设为由 <code>numbers</code> 表示的单元格的和，并返回 <code>mat[row][column]</code> 的值。此求和公式应该 <strong>长期作用于</strong> 该单元格，直到该单元格被另一个值或另一个求和公式覆盖。其中，<code>numbers[i]</code> 的格式可以为：
	<ul>
		<li><code>"ColRow"</code>：表示某个单元格。
		<ul>
			<li>例如，<code>"F7"</code> 表示单元格 <code>mat[7]['F']</code> 。</li>
		</ul>
		</li>
		<li><code>"ColRow1:ColRow2"</code>：表示一组单元格。该范围将始终为一个矩形，其中 <code>"ColRow1"</code> 表示左上角单元格的位置，<code>"ColRow2"</code> 表示右下角单元格的位置。
		<ul>
			<li>例如，<code>"B3:F7"</code> 表示 <code>3 &lt;= i &lt;= 7</code> 和 <code>'B' &lt;= j &lt;= 'F'</code> 的单元格 <code>mat[i][j]</code> 。</li>
		</ul>
		</li>
	</ul>
	</li>
</ul>

<p><strong>注意：</strong>可以假设不会出现循环求和引用。</p>

<ul>
	<li>例如，<code>mat[1]['A'] == sum(1, "B")</code>，且 <code>mat[1]['B'] == sum(1, "A")</code> 。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：
</strong>["Excel", "set", "sum", "set", "get"]
[[3, "C"], [1, "A", 2], [3, "C", ["A1", "A1:B2"]], [2, "B", 2], [3, "C"]]
<strong>输出：</strong>
[null, null, 4, null, 6]

<strong>解释：</strong>
执行以下操作：
Excel excel = new Excel(3, "C");
 // 构造一个 3 * 3 的二维数组，所有值初始化为零。
 //   A B C
 // 1 0 0 0
 // 2 0 0 0
 // 3 0 0 0
excel.set(1, "A", 2);
 // 将 mat[1]["A"] 设置为 2 。
 //   A B C
 // 1 2 0 0
 // 2 0 0 0
 // 3 0 0 0
excel.sum(3, "C", ["A1", "A1:B2"]); // 返回 4
 // 将 mat[3]["C"] 设置为 mat[1]["A"] 的值与矩形范围的单元格和的和，该范围的左上角单元格位置为 mat[1]["A"] ，右下角单元格位置为 mat[2]["B"] 。
 //   A B C
 // 1 2 0 0
 // 2 0 0 0
 // 3 0 0 4
excel.set(2, "B", 2);
 // 将 mat[2]["B"] 设置为 2 。注意 mat[3]["C"] 也应该更改。
 //   A B C
 // 1 2 0 0
 // 2 0 2 0
 // 3 0 0 6
excel.get(3, "C"); // 返回 6
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= height &lt;= 26</code></li>
	<li><code>'A' &lt;= width &lt;= 'Z'</code></li>
	<li><code>1 &lt;= row &lt;= height</code></li>
	<li><code>'A' &lt;= column &lt;= width</code></li>
	<li><code>-100 &lt;= val &lt;= 100</code></li>
	<li><code>1 &lt;= numbers.length &lt;= 5</code></li>
	<li><code>numbers[i]</code> 的格式为 <code>"ColRow"</code> 或 <code>"ColRow1:ColRow2"</code> 。</li>
	<li>最多会对 <code>set</code> 、<code>get</code> 和 <code>sum</code> 进行 <code>100</code> 次调用。</li>
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

# [632. 最小区间](https://leetcode.cn/problems/smallest-range-covering-elements-from-k-lists){#632}

{{< tabs "632" >}}

{{% tab "python" %}}
```python
class Solution:
    def smallestRange(self, nums: List[List[int]]) -> List[int]:
        t = [(x, i) for i, v in enumerate(nums) for x in v]
        t.sort()
        cnt = Counter()
        ans = [-inf, inf]
        j = 0
        for i, (b, v) in enumerate(t):
            cnt[v] += 1
            while len(cnt) == len(nums):
                a = t[j][0]
                x = b - a - (ans[1] - ans[0])
                if x < 0 or (x == 0 and a < ans[0]):
                    ans = [a, b]
                w = t[j][1]
                cnt[w] -= 1
                if cnt[w] == 0:
                    cnt.pop(w)
                j += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] smallestRange(List<List<Integer>> nums) {
        int n = 0;
        for (var v : nums) {
            n += v.size();
        }
        int[][] t = new int[n][2];
        int k = nums.size();
        for (int i = 0, j = 0; i < k; ++i) {
            for (int x : nums.get(i)) {
                t[j++] = new int[] {x, i};
            }
        }
        Arrays.sort(t, (a, b) -> a[0] - b[0]);
        int j = 0;
        Map<Integer, Integer> cnt = new HashMap<>();
        int[] ans = new int[] {-1000000, 1000000};
        for (int[] e : t) {
            int b = e[0];
            int v = e[1];
            cnt.merge(v, 1, Integer::sum);
            while (cnt.size() == k) {
                int a = t[j][0];
                int w = t[j][1];
                int x = b - a - (ans[1] - ans[0]);
                if (x < 0 || (x == 0 && a < ans[0])) {
                    ans[0] = a;
                    ans[1] = b;
                }
                if (cnt.merge(w, -1, Integer::sum) == 0) {
                    cnt.remove(w);
                }
                ++j;
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
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = 0;
        for (auto& v : nums) n += v.size();
        vector<pair<int, int>> t(n);
        int k = nums.size();
        for (int i = 0, j = 0; i < k; ++i) {
            for (int v : nums[i]) {
                t[j++] = {v, i};
            }
        }
        sort(t.begin(), t.end());
        int j = 0;
        unordered_map<int, int> cnt;
        vector<int> ans = {-1000000, 1000000};
        for (int i = 0; i < n; ++i) {
            int b = t[i].first;
            int v = t[i].second;
            ++cnt[v];
            while (cnt.size() == k) {
                int a = t[j].first;
                int w = t[j].second;
                int x = b - a - (ans[1] - ans[0]);
                if (x < 0 || (x == 0 && a < ans[0])) {
                    ans[0] = a;
                    ans[1] = b;
                }
                if (--cnt[w] == 0) {
                    cnt.erase(w);
                }
                ++j;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func smallestRange(nums [][]int) []int {
	t := [][]int{}
	for i, x := range nums {
		for _, v := range x {
			t = append(t, []int{v, i})
		}
	}
	sort.Slice(t, func(i, j int) bool { return t[i][0] < t[j][0] })
	ans := []int{-1000000, 1000000}
	j := 0
	cnt := map[int]int{}
	for _, x := range t {
		b, v := x[0], x[1]
		cnt[v]++
		for len(cnt) == len(nums) {
			a, w := t[j][0], t[j][1]
			x := b - a - (ans[1] - ans[0])
			if x < 0 || (x == 0 && a < ans[0]) {
				ans[0], ans[1] = a, b
			}
			cnt[w]--
			if cnt[w] == 0 {
				delete(cnt, w)
			}
			j++
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn smallest_range(nums: Vec<Vec<i32>>) -> Vec<i32> {
        let mut t = vec![];
        for (i, x) in nums.iter().enumerate() {
            for &v in x {
                t.push((v, i));
            }
        }
        t.sort_unstable();
        let (mut ans, n) = (vec![-1000000, 1000000], nums.len());
        let mut j = 0;
        let mut cnt = std::collections::HashMap::new();

        for (b, v) in t.iter() {
            let (b, v) = (*b, *v);
            if let Some(x) = cnt.get_mut(&v) {
                *x += 1;
            } else {
                cnt.insert(v, 1);
            }
            while cnt.len() == n {
                let (a, w) = t[j];
                let x = b - a - (ans[1] - ans[0]);
                if x < 0 || (x == 0 && a < ans[0]) {
                    ans = vec![a, b];
                }
                if let Some(x) = cnt.get_mut(&w) {
                    *x -= 1;
                }
                if cnt[&w] == 0 {
                    cnt.remove(&w);
                }
                j += 1;
            }
        }
        ans
    }
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
const smallestRange = (nums: number[][]): number[] => {
    const pq = new MinPriorityQueue<[number, number, number]>({ priority: ([x]) => x });
    const n = nums.length;
    let [l, r, max] = [0, Number.POSITIVE_INFINITY, Number.NEGATIVE_INFINITY];

    for (let j = 0; j < n; j++) {
        const x = nums[j][0];
        pq.enqueue([x, j, 0]);
        max = Math.max(max, x);
    }

    while (pq.size() === n) {
        const [min, j, i] = pq.dequeue().element;

        if (max - min < r - l) {
            [l, r] = [min, max];
        }

        const iNext = i + 1;
        if (iNext < nums[j].length) {
            const next = nums[j][iNext];
            pq.enqueue([next, j, iNext]);
            max = Math.max(max, next);
        }
    }

    return [l, r];
};
```
{{% /tab %}}
{{% tab "js" %}}
```js
const smallestRange = nums => {
    const pq = new MinPriorityQueue({ priority: ([x]) => x });
    const n = nums.length;
    let [l, r, max] = [0, Number.POSITIVE_INFINITY, Number.NEGATIVE_INFINITY];

    for (let j = 0; j < n; j++) {
        const x = nums[j][0];
        pq.enqueue([x, j, 0]);
        max = Math.max(max, x);
    }

    while (pq.size() === n) {
        const [min, j, i] = pq.dequeue().element;

        if (max - min < r - l) {
            [l, r] = [min, max];
        }

        const iNext = i + 1;
        if (iNext < nums[j].length) {
            const next = nums[j][iNext];
            pq.enqueue([next, j, iNext]);
            max = Math.max(max, next);
        }
    }

    return [l, r];
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你有&nbsp;<code>k</code>&nbsp;个 <strong>非递减排列</strong> 的整数列表。找到一个 <strong>最小 </strong>区间，使得&nbsp;<code>k</code>&nbsp;个列表中的每个列表至少有一个数包含在其中。</p>

<p>我们定义如果&nbsp;<code>b-a &lt; d-c</code>&nbsp;或者在&nbsp;<code>b-a == d-c</code>&nbsp;时&nbsp;<code>a &lt; c</code>，则区间 <code>[a,b]</code> 比 <code>[c,d]</code> 小。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [[4,10,15,24,26], [0,9,12,20], [5,18,22,30]]
<strong>输出：</strong>[20,24]
<strong>解释：</strong> 
列表 1：[4, 10, 15, 24, 26]，24 在区间 [20,24] 中。
列表 2：[0, 9, 12, 20]，20 在区间 [20,24] 中。
列表 3：[5, 18, 22, 30]，22 在区间 [20,24] 中。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [[1,2,3],[1,2,3],[1,2,3]]
<strong>输出：</strong>[1,1]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>nums.length == k</code></li>
	<li><code>1 &lt;= k &lt;= 3500</code></li>
	<li><code>1 &lt;= nums[i].length &lt;= 50</code></li>
	<li><code>-10<sup>5</sup> &lt;= nums[i][j] &lt;= 10<sup>5</sup></code></li>
	<li><code>nums[i]</code> 按非递减顺序排列</li>
</ul>

<p>&nbsp;</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 滑动窗口

我们将每个数字 $x$ 及其所在的组 $i$，构成数据项 $(x, i)$，存放在一个新的数组 $t$ 中，然后对 $t$ 按照数字的大小进行排序（类似于将多个有序数组合并成一个新的有序数组）。

接下来，我们遍历 $t$ 中的每个数据项，只看其中数字所在的组，用哈希表记录滑动窗口内的数字出现的组，如果组数为 $k$，说明当前窗口满足题目要求，此时算出窗口的起始和结束位置，更新答案。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为所有数组中数字的个数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def smallestRange(self, nums: List[List[int]]) -> List[int]:
        t = [(x, i) for i, v in enumerate(nums) for x in v]
        t.sort()
        cnt = Counter()
        ans = [-inf, inf]
        j = 0
        for i, (b, v) in enumerate(t):
            cnt[v] += 1
            while len(cnt) == len(nums):
                a = t[j][0]
                x = b - a - (ans[1] - ans[0])
                if x < 0 or (x == 0 and a < ans[0]):
                    ans = [a, b]
                w = t[j][1]
                cnt[w] -= 1
                if cnt[w] == 0:
                    cnt.pop(w)
                j += 1
        return ans
```

#### Java

```java
class Solution {
    public int[] smallestRange(List<List<Integer>> nums) {
        int n = 0;
        for (var v : nums) {
            n += v.size();
        }
        int[][] t = new int[n][2];
        int k = nums.size();
        for (int i = 0, j = 0; i < k; ++i) {
            for (int x : nums.get(i)) {
                t[j++] = new int[] {x, i};
            }
        }
        Arrays.sort(t, (a, b) -> a[0] - b[0]);
        int j = 0;
        Map<Integer, Integer> cnt = new HashMap<>();
        int[] ans = new int[] {-1000000, 1000000};
        for (int[] e : t) {
            int b = e[0];
            int v = e[1];
            cnt.merge(v, 1, Integer::sum);
            while (cnt.size() == k) {
                int a = t[j][0];
                int w = t[j][1];
                int x = b - a - (ans[1] - ans[0]);
                if (x < 0 || (x == 0 && a < ans[0])) {
                    ans[0] = a;
                    ans[1] = b;
                }
                if (cnt.merge(w, -1, Integer::sum) == 0) {
                    cnt.remove(w);
                }
                ++j;
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
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = 0;
        for (auto& v : nums) n += v.size();
        vector<pair<int, int>> t(n);
        int k = nums.size();
        for (int i = 0, j = 0; i < k; ++i) {
            for (int v : nums[i]) {
                t[j++] = {v, i};
            }
        }
        sort(t.begin(), t.end());
        int j = 0;
        unordered_map<int, int> cnt;
        vector<int> ans = {-1000000, 1000000};
        for (int i = 0; i < n; ++i) {
            int b = t[i].first;
            int v = t[i].second;
            ++cnt[v];
            while (cnt.size() == k) {
                int a = t[j].first;
                int w = t[j].second;
                int x = b - a - (ans[1] - ans[0]);
                if (x < 0 || (x == 0 && a < ans[0])) {
                    ans[0] = a;
                    ans[1] = b;
                }
                if (--cnt[w] == 0) {
                    cnt.erase(w);
                }
                ++j;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func smallestRange(nums [][]int) []int {
	t := [][]int{}
	for i, x := range nums {
		for _, v := range x {
			t = append(t, []int{v, i})
		}
	}
	sort.Slice(t, func(i, j int) bool { return t[i][0] < t[j][0] })
	ans := []int{-1000000, 1000000}
	j := 0
	cnt := map[int]int{}
	for _, x := range t {
		b, v := x[0], x[1]
		cnt[v]++
		for len(cnt) == len(nums) {
			a, w := t[j][0], t[j][1]
			x := b - a - (ans[1] - ans[0])
			if x < 0 || (x == 0 && a < ans[0]) {
				ans[0], ans[1] = a, b
			}
			cnt[w]--
			if cnt[w] == 0 {
				delete(cnt, w)
			}
			j++
		}
	}
	return ans
}
```

#### Rust

```rust
impl Solution {
    pub fn smallest_range(nums: Vec<Vec<i32>>) -> Vec<i32> {
        let mut t = vec![];
        for (i, x) in nums.iter().enumerate() {
            for &v in x {
                t.push((v, i));
            }
        }
        t.sort_unstable();
        let (mut ans, n) = (vec![-1000000, 1000000], nums.len());
        let mut j = 0;
        let mut cnt = std::collections::HashMap::new();

        for (b, v) in t.iter() {
            let (b, v) = (*b, *v);
            if let Some(x) = cnt.get_mut(&v) {
                *x += 1;
            } else {
                cnt.insert(v, 1);
            }
            while cnt.len() == n {
                let (a, w) = t[j];
                let x = b - a - (ans[1] - ans[0]);
                if x < 0 || (x == 0 && a < ans[0]) {
                    ans = vec![a, b];
                }
                if let Some(x) = cnt.get_mut(&w) {
                    *x -= 1;
                }
                if cnt[&w] == 0 {
                    cnt.remove(&w);
                }
                j += 1;
            }
        }
        ans
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：优先队列（小根堆）

<!-- tabs:start -->

#### TypeScript

```ts
const smallestRange = (nums: number[][]): number[] => {
    const pq = new MinPriorityQueue<[number, number, number]>({ priority: ([x]) => x });
    const n = nums.length;
    let [l, r, max] = [0, Number.POSITIVE_INFINITY, Number.NEGATIVE_INFINITY];

    for (let j = 0; j < n; j++) {
        const x = nums[j][0];
        pq.enqueue([x, j, 0]);
        max = Math.max(max, x);
    }

    while (pq.size() === n) {
        const [min, j, i] = pq.dequeue().element;

        if (max - min < r - l) {
            [l, r] = [min, max];
        }

        const iNext = i + 1;
        if (iNext < nums[j].length) {
            const next = nums[j][iNext];
            pq.enqueue([next, j, iNext]);
            max = Math.max(max, next);
        }
    }

    return [l, r];
};
```

#### JavaScript

```js
const smallestRange = nums => {
    const pq = new MinPriorityQueue({ priority: ([x]) => x });
    const n = nums.length;
    let [l, r, max] = [0, Number.POSITIVE_INFINITY, Number.NEGATIVE_INFINITY];

    for (let j = 0; j < n; j++) {
        const x = nums[j][0];
        pq.enqueue([x, j, 0]);
        max = Math.max(max, x);
    }

    while (pq.size() === n) {
        const [min, j, i] = pq.dequeue().element;

        if (max - min < r - l) {
            [l, r] = [min, max];
        }

        const iNext = i + 1;
        if (iNext < nums[j].length) {
            const next = nums[j][iNext];
            pq.enqueue([next, j, iNext]);
            max = Math.max(max, next);
        }
    }

    return [l, r];
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [633. 平方数之和](https://leetcode.cn/problems/sum-of-square-numbers){#633}

{{< tabs "633" >}}

{{% tab "python" %}}
```python
class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        for i in range(2, int(sqrt(c)) + 1):
            if c % i == 0:
                exp = 0
                while c % i == 0:
                    c //= i
                    exp += 1
                if i % 4 == 3 and exp % 2 != 0:
                    return False
        return c % 4 != 3
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean judgeSquareSum(int c) {
        int n = (int) Math.sqrt(c);
        for (int i = 2; i <= n; ++i) {
            if (c % i == 0) {
                int exp = 0;
                while (c % i == 0) {
                    c /= i;
                    ++exp;
                }
                if (i % 4 == 3 && exp % 2 != 0) {
                    return false;
                }
            }
        }
        return c % 4 != 3;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool judgeSquareSum(int c) {
        int n = sqrt(c);
        for (int i = 2; i <= n; ++i) {
            if (c % i == 0) {
                int exp = 0;
                while (c % i == 0) {
                    c /= i;
                    ++exp;
                }
                if (i % 4 == 3 && exp % 2 != 0) {
                    return false;
                }
            }
        }
        return c % 4 != 3;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func judgeSquareSum(c int) bool {
	n := int(math.Sqrt(float64(c)))
	for i := 2; i <= n; i++ {
		if c%i == 0 {
			exp := 0
			for c%i == 0 {
				c /= i
				exp++
			}
			if i%4 == 3 && exp%2 != 0 {
				return false
			}
		}
	}
	return c%4 != 3
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function judgeSquareSum(c: number): boolean {
    const n = Math.floor(Math.sqrt(c));
    for (let i = 2; i <= n; ++i) {
        if (c % i === 0) {
            let exp = 0;
            while (c % i === 0) {
                c /= i;
                ++exp;
            }
            if (i % 4 === 3 && exp % 2 !== 0) {
                return false;
            }
        }
    }
    return c % 4 !== 3;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::cmp::Ordering;

impl Solution {
    pub fn judge_square_sum(c: i32) -> bool {
        let mut a: i64 = 0;
        let mut b: i64 = (c as f64).sqrt() as i64;
        while a <= b {
            let s = a * a + b * b;
            match s.cmp(&(c as i64)) {
                Ordering::Equal => {
                    return true;
                }
                Ordering::Less => {
                    a += 1;
                }
                Ordering::Greater => {
                    b -= 1;
                }
            }
        }
        false
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个非负整数&nbsp;<code>c</code>&nbsp;，你要判断是否存在两个整数 <code>a</code> 和 <code>b</code>，使得&nbsp;<code>a<sup>2</sup> + b<sup>2</sup> = c</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>c = 5
<strong>输出：</strong>true
<strong>解释：</strong>1 * 1 + 2 * 2 = 5
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>c = 3
<strong>输出：</strong>false
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= c &lt;= 2<sup>31</sup> - 1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数学 + 双指针

我们可以使用双指针的方法来解决这个问题，定义两个指针 $a$ 和 $b$，分别指向 $0$ 和 $\sqrt{c}$。在每一步中，我们会计算 $s = a^2 + b^2$ 的值，然后比较 $s$ 与 $c$ 的大小。如果 $s = c$，我们就找到了两个整数 $a$ 和 $b$，使得 $a^2 + b^2 = c$。如果 $s < c$，我们将 $a$ 的值增加 $1$，如果 $s > c$，我们将 $b$ 的值减小 $1$。我们不断进行这个过程直到找到答案，或者 $a$ 的值大于 $b$ 的值，返回 `false`。

时间复杂度 $O(\sqrt{c})$，其中 $c$ 是给定的非负整数。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        a, b = 0, int(sqrt(c))
        while a <= b:
            s = a**2 + b**2
            if s == c:
                return True
            if s < c:
                a += 1
            else:
                b -= 1
        return False
```

#### Java

```java
class Solution {
    public boolean judgeSquareSum(int c) {
        long a = 0, b = (long) Math.sqrt(c);
        while (a <= b) {
            long s = a * a + b * b;
            if (s == c) {
                return true;
            }
            if (s < c) {
                ++a;
            } else {
                --b;
            }
        }
        return false;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool judgeSquareSum(int c) {
        long long a = 0, b = sqrt(c);
        while (a <= b) {
            long long s = a * a + b * b;
            if (s == c) {
                return true;
            }
            if (s < c) {
                ++a;
            } else {
                --b;
            }
        }
        return false;
    }
};
```

#### Go

```go
func judgeSquareSum(c int) bool {
	a, b := 0, int(math.Sqrt(float64(c)))
	for a <= b {
		s := a*a + b*b
		if s == c {
			return true
		}
		if s < c {
			a++
		} else {
			b--
		}
	}
	return false
}
```

#### TypeScript

```ts
function judgeSquareSum(c: number): boolean {
    let [a, b] = [0, Math.floor(Math.sqrt(c))];
    while (a <= b) {
        const s = a * a + b * b;
        if (s === c) {
            return true;
        }
        if (s < c) {
            ++a;
        } else {
            --b;
        }
    }
    return false;
}
```

#### Rust

```rust
use std::cmp::Ordering;

impl Solution {
    pub fn judge_square_sum(c: i32) -> bool {
        let mut a: i64 = 0;
        let mut b: i64 = (c as f64).sqrt() as i64;
        while a <= b {
            let s = a * a + b * b;
            match s.cmp(&(c as i64)) {
                Ordering::Equal => {
                    return true;
                }
                Ordering::Less => {
                    a += 1;
                }
                Ordering::Greater => {
                    b -= 1;
                }
            }
        }
        false
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：数学

这个问题实际上是关于一个数能否表示为两个平方数之和的条件。这个定理可以追溯到费马（Fermat）和欧拉（Euler），它在数论中是一个经典结果。

具体来说，这个定理可以表述为：

**一个正整数 \( n \) 能表示为两个平方数之和的充要条件是：\( n \) 的所有形如 \( 4k + 3 \) 的素数因子的幂次均为偶数。**

这意味着，如果我们将 $n$ 分解成素数因子乘积的形式，即 $n = p_1^{e_1} p_2^{e_2} \cdots p_k^{e_k}$，其中 $p_i$ 是素数且 $e_i$ 是它们对应的幂次，那么 $n$ 可以表示为两个平方数之和，当且仅当所有 $4k + 3$ 形式的素数因子 $p_i$ 的幂次 $e_i$ 都是偶数。

更正式地，假设 $p_i$ 是形如 $4k + 3$ 的素数，则对于每一个这样的 $p_i$，要求 $e_i$ 是偶数。

例如：

-   数字 $13$ 是素数，且 $13 \equiv 1 \pmod{4}$，因此它可以表示为两个平方数之和，即 $13 = 2^2 + 3^2$。
-   数字 $21$ 分解为 $3 \times 7$，其中 $3$ 和 $7$ 都是形如 $4k + 3$ 的素数因子，并且它们的幂次都是 $1$（奇数），因此 $21$ 不能表示为两个平方数之和。

总结起来，这个定理在数论中非常重要，用于判断一个数是否可以表示为两个平方数之和。

时间复杂度 $O(\sqrt{c})$，其中 $c$ 是给定的非负整数。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        for i in range(2, int(sqrt(c)) + 1):
            if c % i == 0:
                exp = 0
                while c % i == 0:
                    c //= i
                    exp += 1
                if i % 4 == 3 and exp % 2 != 0:
                    return False
        return c % 4 != 3
```

#### Java

```java
class Solution {
    public boolean judgeSquareSum(int c) {
        int n = (int) Math.sqrt(c);
        for (int i = 2; i <= n; ++i) {
            if (c % i == 0) {
                int exp = 0;
                while (c % i == 0) {
                    c /= i;
                    ++exp;
                }
                if (i % 4 == 3 && exp % 2 != 0) {
                    return false;
                }
            }
        }
        return c % 4 != 3;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool judgeSquareSum(int c) {
        int n = sqrt(c);
        for (int i = 2; i <= n; ++i) {
            if (c % i == 0) {
                int exp = 0;
                while (c % i == 0) {
                    c /= i;
                    ++exp;
                }
                if (i % 4 == 3 && exp % 2 != 0) {
                    return false;
                }
            }
        }
        return c % 4 != 3;
    }
};
```

#### Go

```go
func judgeSquareSum(c int) bool {
	n := int(math.Sqrt(float64(c)))
	for i := 2; i <= n; i++ {
		if c%i == 0 {
			exp := 0
			for c%i == 0 {
				c /= i
				exp++
			}
			if i%4 == 3 && exp%2 != 0 {
				return false
			}
		}
	}
	return c%4 != 3
}
```

#### TypeScript

```ts
function judgeSquareSum(c: number): boolean {
    const n = Math.floor(Math.sqrt(c));
    for (let i = 2; i <= n; ++i) {
        if (c % i === 0) {
            let exp = 0;
            while (c % i === 0) {
                c /= i;
                ++exp;
            }
            if (i % 4 === 3 && exp % 2 !== 0) {
                return false;
            }
        }
    }
    return c % 4 !== 3;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [634. 寻找数组的错位排列 🔒](https://leetcode.cn/problems/find-the-derangement-of-an-array){#634}

{{< tabs "634" >}}

{{% tab "python" %}}
```python
class Solution:
    def findDerangement(self, n: int) -> int:
        mod = 10**9 + 7
        a, b = 1, 0
        for i in range(2, n + 1):
            a, b = b, ((i - 1) * (a + b)) % mod
        return b
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int findDerangement(int n) {
        final int mod = (int) 1e9 + 7;
        long a = 1, b = 0;
        for (int i = 2; i <= n; ++i) {
            long c = (i - 1) * (a + b) % mod;
            a = b;
            b = c;
        }
        return (int) b;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int findDerangement(int n) {
        long long a = 1, b = 0;
        const int mod = 1e9 + 7;
        for (int i = 2; i <= n; ++i) {
            long long c = (i - 1) * (a + b) % mod;
            a = b;
            b = c;
        }
        return b;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findDerangement(n int) int {
	a, b := 1, 0
	const mod = 1e9 + 7
	for i := 2; i <= n; i++ {
		a, b = b, (i-1)*(a+b)%mod
	}
	return b
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>在组合数学中，如果一个排列中所有元素都不在原先的位置上，那么这个排列就被称为 <strong>错位排列</strong> 。</p>

<p>给定一个从&nbsp;<code>1</code> 到 <code>n</code>&nbsp;升序排列的数组，返回&nbsp;<em><strong>不同的错位排列</strong> 的数量&nbsp;</em>。由于答案可能非常大，你只需要将答案对 <code>10<sup>9</sup>+7</code> <strong>取余</strong>&nbsp;输出即可。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> n = 3
<strong>输出:</strong> 2
<strong>解释:</strong> 原始的数组为 [1,2,3]。两个错位排列的数组为 [2,3,1] 和 [3,1,2]。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> n = 2
<strong>输出:</strong> 1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>6</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i]$ 表示长度为 $i$ 的数组的错位排列的数量。初始时 $f[0] = 1$, $f[1] = 0$。答案即为 $f[n]$。

对于长度为 $i$ 的数组，我们考虑将数字 $1$ 放在哪个位置，假设放在第 $j$ 个位置，这里有 $i-1$ 种选择，那么接下来数字 $j$ 可以有两种选择：

-   放在第 $1$ 个位置，那么剩下的 $i - 2$ 个位置可以有 $f[i - 2]$ 种错位排列，因此总共有 $(i - 1) \times f[i - 2]$ 种错位排列；
-   不放在第 $1$ 个位置，那么相当于转化为了长度为 $i - 1$ 的数组的错位排列，因此总共有 $(i - 1) \times f[i - 1]$ 种错位排列。

综上，我们有如下状态转移方程：

$$
f[i] = (i - 1) \times (f[i - 1] + f[i - 2])
$$

最终答案即为 $f[n]$。注意答案的取模操作。

时间复杂度 $O(n)$，其中 $n$ 为数组的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findDerangement(self, n: int) -> int:
        mod = 10**9 + 7
        f = [1] + [0] * n
        for i in range(2, n + 1):
            f[i] = (i - 1) * (f[i - 1] + f[i - 2]) % mod
        return f[n]
```

#### Java

```java
class Solution {
    public int findDerangement(int n) {
        long[] f = new long[n + 1];
        f[0] = 1;
        final int mod = (int) 1e9 + 7;
        for (int i = 2; i <= n; ++i) {
            f[i] = (i - 1) * (f[i - 1] + f[i - 2]) % mod;
        }
        return (int) f[n];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int findDerangement(int n) {
        long long f[n + 1];
        memset(f, 0, sizeof(f));
        f[0] = 1;
        const int mod = 1e9 + 7;
        for (int i = 2; i <= n; i++) {
            f[i] = (i - 1LL) * (f[i - 1] + f[i - 2]) % mod;
        }
        return f[n];
    }
};
```

#### Go

```go
func findDerangement(n int) int {
	f := make([]int, n+1)
	f[0] = 1
	const mod = 1e9 + 7
	for i := 2; i <= n; i++ {
		f[i] = (i - 1) * (f[i-1] + f[i-2]) % mod
	}
	return f[n]
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：动态规划（空间优化）

我们发现，状态转移方程中只与 $f[i - 1]$ 和 $f[i - 2]$ 有关，因此我们可以使用两个变量 $a$ 和 $b$ 来分别表示 $f[i - 1]$ 和 $f[i - 2]$，从而将空间复杂度降低到 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findDerangement(self, n: int) -> int:
        mod = 10**9 + 7
        a, b = 1, 0
        for i in range(2, n + 1):
            a, b = b, ((i - 1) * (a + b)) % mod
        return b
```

#### Java

```java
class Solution {
    public int findDerangement(int n) {
        final int mod = (int) 1e9 + 7;
        long a = 1, b = 0;
        for (int i = 2; i <= n; ++i) {
            long c = (i - 1) * (a + b) % mod;
            a = b;
            b = c;
        }
        return (int) b;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int findDerangement(int n) {
        long long a = 1, b = 0;
        const int mod = 1e9 + 7;
        for (int i = 2; i <= n; ++i) {
            long long c = (i - 1) * (a + b) % mod;
            a = b;
            b = c;
        }
        return b;
    }
};
```

#### Go

```go
func findDerangement(n int) int {
	a, b := 1, 0
	const mod = 1e9 + 7
	for i := 2; i <= n; i++ {
		a, b = b, (i-1)*(a+b)%mod
	}
	return b
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [635. 设计日志存储系统 🔒](https://leetcode.cn/problems/design-log-storage-system){#635}

{{< tabs "635" >}}

{{% tab "python" %}}
```python
class LogSystem:
    def __init__(self):
        self.logs = []
        self.d = {
            "Year": 4,
            "Month": 7,
            "Day": 10,
            "Hour": 13,
            "Minute": 16,
            "Second": 19,
        }

    def put(self, id: int, timestamp: str) -> None:
        self.logs.append((id, timestamp))

    def retrieve(self, start: str, end: str, granularity: str) -> List[int]:
        i = self.d[granularity]
        return [id for id, ts in self.logs if start[:i] <= ts[:i] <= end[:i]]


# Your LogSystem object will be instantiated and called as such:
# obj = LogSystem()
# obj.put(id,timestamp)
# param_2 = obj.retrieve(start,end,granularity)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class LogSystem {
    private List<Log> logs = new ArrayList<>();
    private Map<String, Integer> d = new HashMap<>();

    public LogSystem() {
        d.put("Year", 4);
        d.put("Month", 7);
        d.put("Day", 10);
        d.put("Hour", 13);
        d.put("Minute", 16);
        d.put("Second", 19);
    }

    public void put(int id, String timestamp) {
        logs.add(new Log(id, timestamp));
    }

    public List<Integer> retrieve(String start, String end, String granularity) {
        List<Integer> ans = new ArrayList<>();
        int i = d.get(granularity);
        String s = start.substring(0, i);
        String e = end.substring(0, i);
        for (var log : logs) {
            String t = log.ts.substring(0, i);
            if (s.compareTo(t) <= 0 && t.compareTo(e) <= 0) {
                ans.add(log.id);
            }
        }
        return ans;
    }
}

class Log {
    int id;
    String ts;

    Log(int id, String ts) {
        this.id = id;
        this.ts = ts;
    }
}

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem obj = new LogSystem();
 * obj.put(id,timestamp);
 * List<Integer> param_2 = obj.retrieve(start,end,granularity);
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class LogSystem {
public:
    LogSystem() {
        d["Year"] = 4;
        d["Month"] = 7;
        d["Day"] = 10;
        d["Hour"] = 13;
        d["Minute"] = 16;
        d["Second"] = 19;
    }

    void put(int id, string timestamp) {
        logs.push_back({id, timestamp});
    }

    vector<int> retrieve(string start, string end, string granularity) {
        vector<int> ans;
        int i = d[granularity];
        auto s = start.substr(0, i);
        auto e = end.substr(0, i);
        for (auto& [id, ts] : logs) {
            auto t = ts.substr(0, i);
            if (s <= t && t <= e) {
                ans.emplace_back(id);
            }
        }
        return ans;
    }

private:
    vector<pair<int, string>> logs;
    unordered_map<string, int> d;
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem* obj = new LogSystem();
 * obj->put(id,timestamp);
 * vector<int> param_2 = obj->retrieve(start,end,granularity);
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type LogSystem struct {
	logs []pair
	d    map[string]int
}

func Constructor() LogSystem {
	d := map[string]int{
		"Year":   4,
		"Month":  7,
		"Day":    10,
		"Hour":   13,
		"Minute": 16,
		"Second": 19,
	}
	return LogSystem{[]pair{}, d}
}

func (this *LogSystem) Put(id int, timestamp string) {
	this.logs = append(this.logs, pair{id, timestamp})
}

func (this *LogSystem) Retrieve(start string, end string, granularity string) (ans []int) {
	i := this.d[granularity]
	s, e := start[:i], end[:i]
	for _, log := range this.logs {
		t := log.ts[:i]
		if s <= t && t <= e {
			ans = append(ans, log.id)
		}
	}
	return
}

type pair struct {
	id int
	ts string
}

/**
 * Your LogSystem object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Put(id,timestamp);
 * param_2 := obj.Retrieve(start,end,granularity);
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你将获得多条日志，每条日志都有唯一的 <code>id</code> 和 <code>timestamp</code> ，<code>timestamp</code> 是形如 <code>Year:Month:Day:Hour:Minute:Second</code> 的字符串，<code>2017:01:01:23:59:59</code> ，所有值域都是零填充的十进制数。</p>

<p>实现 <code>LogSystem</code> 类：</p>

<ul>
	<li><code>LogSystem()</code> 初始化 <code>LogSystem</code><b> </b>对象</li>
	<li><code>void put(int id, string timestamp)</code> 给定日志的 <code>id</code> 和 <code>timestamp</code> ，将这个日志存入你的存储系统中。</li>
	<li><code>int[] retrieve(string start, string end, string granularity)</code> 返回在给定时间区间 <code>[start, end]</code> （包含两端）内的所有日志的 <code>id</code> 。<code>start</code> 、<code>end</code> 和 <code>timestamp</code> 的格式相同，<code>granularity</code> 表示考虑的时间粒度（例如，精确到 <code>Day</code>、<code>Minute</code> 等）。例如 <code>start = "2017:01:01:23:59:59"</code>、<code>end = "2017:01:02:23:59:59"</code> 且 <code>granularity = "Day"</code> 意味着需要查找从 <strong>Jan. 1st 2017</strong> 到 <strong>Jan. 2nd 2017 </strong>范围内的日志，可以忽略日志的 <code>Hour</code>、<code>Minute</code> 和 <code>Second</code> 。</li>
</ul>
 

<p><strong>示例：</strong></p>

<pre>
<strong>输入：</strong>
["LogSystem", "put", "put", "put", "retrieve", "retrieve"]
[[], [1, "2017:01:01:23:59:59"], [2, "2017:01:01:22:59:59"], [3, "2016:01:01:00:00:00"], ["2016:01:01:01:01:01", "2017:01:01:23:00:00", "Year"], ["2016:01:01:01:01:01", "2017:01:01:23:00:00", "Hour"]]
<strong>输出：</strong>
[null, null, null, null, [3, 2, 1], [2, 1]]

<strong>解释：</strong>
LogSystem logSystem = new LogSystem();
logSystem.put(1, "2017:01:01:23:59:59");
logSystem.put(2, "2017:01:01:22:59:59");
logSystem.put(3, "2016:01:01:00:00:00");

// 返回 [3,2,1]，返回从 2016 年到 2017 年所有的日志。
logSystem.retrieve("2016:01:01:01:01:01", "2017:01:01:23:00:00", "Year");

// 返回 [2,1]，返回从 Jan. 1, 2016 01:XX:XX 到 Jan. 1, 2017 23:XX:XX 之间的所有日志
// 不返回日志 3 因为记录时间 Jan. 1, 2016 00:00:00 超过范围的起始时间
logSystem.retrieve("2016:01:01:01:01:01", "2017:01:01:23:00:00", "Hour");
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= id <= 500</code></li>
	<li><code>2000 <= Year <= 2017</code></li>
	<li><code>1 <= Month <= 12</code></li>
	<li><code>1 <= Day <= 31</code></li>
	<li><code>0 <= Hour <= 23</code></li>
	<li><code>0 <= Minute, Second <= 59</code></li>
	<li><code>granularity</code> 是这些值 <code>["Year", "Month", "Day", "Hour", "Minute", "Second"]</code> 之一</li>
	<li>最多调用 <code>500</code> 次 <code>put</code> 和 <code>retrieve</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：字符串比较

将日志的 `id` 和 `timestamp` 作为元组存入数组中，然后在 `retrieve()` 方法中，根据 `granularity` 截取 `start` 和 `end` 的相应部分，然后遍历数组，将符合条件的 `id` 加入结果数组中。

时间复杂度方面，`put()` 方法的时间复杂度为 $O(1)$，`retrieve()` 方法的时间复杂度为 $O(n)$，其中 $n$ 为数组的长度。

<!-- tabs:start -->

#### Python3

```python
class LogSystem:
    def __init__(self):
        self.logs = []
        self.d = {
            "Year": 4,
            "Month": 7,
            "Day": 10,
            "Hour": 13,
            "Minute": 16,
            "Second": 19,
        }

    def put(self, id: int, timestamp: str) -> None:
        self.logs.append((id, timestamp))

    def retrieve(self, start: str, end: str, granularity: str) -> List[int]:
        i = self.d[granularity]
        return [id for id, ts in self.logs if start[:i] <= ts[:i] <= end[:i]]


# Your LogSystem object will be instantiated and called as such:
# obj = LogSystem()
# obj.put(id,timestamp)
# param_2 = obj.retrieve(start,end,granularity)
```

#### Java

```java
class LogSystem {
    private List<Log> logs = new ArrayList<>();
    private Map<String, Integer> d = new HashMap<>();

    public LogSystem() {
        d.put("Year", 4);
        d.put("Month", 7);
        d.put("Day", 10);
        d.put("Hour", 13);
        d.put("Minute", 16);
        d.put("Second", 19);
    }

    public void put(int id, String timestamp) {
        logs.add(new Log(id, timestamp));
    }

    public List<Integer> retrieve(String start, String end, String granularity) {
        List<Integer> ans = new ArrayList<>();
        int i = d.get(granularity);
        String s = start.substring(0, i);
        String e = end.substring(0, i);
        for (var log : logs) {
            String t = log.ts.substring(0, i);
            if (s.compareTo(t) <= 0 && t.compareTo(e) <= 0) {
                ans.add(log.id);
            }
        }
        return ans;
    }
}

class Log {
    int id;
    String ts;

    Log(int id, String ts) {
        this.id = id;
        this.ts = ts;
    }
}

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem obj = new LogSystem();
 * obj.put(id,timestamp);
 * List<Integer> param_2 = obj.retrieve(start,end,granularity);
 */
```

#### C++

```cpp
class LogSystem {
public:
    LogSystem() {
        d["Year"] = 4;
        d["Month"] = 7;
        d["Day"] = 10;
        d["Hour"] = 13;
        d["Minute"] = 16;
        d["Second"] = 19;
    }

    void put(int id, string timestamp) {
        logs.push_back({id, timestamp});
    }

    vector<int> retrieve(string start, string end, string granularity) {
        vector<int> ans;
        int i = d[granularity];
        auto s = start.substr(0, i);
        auto e = end.substr(0, i);
        for (auto& [id, ts] : logs) {
            auto t = ts.substr(0, i);
            if (s <= t && t <= e) {
                ans.emplace_back(id);
            }
        }
        return ans;
    }

private:
    vector<pair<int, string>> logs;
    unordered_map<string, int> d;
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem* obj = new LogSystem();
 * obj->put(id,timestamp);
 * vector<int> param_2 = obj->retrieve(start,end,granularity);
 */
```

#### Go

```go
type LogSystem struct {
	logs []pair
	d    map[string]int
}

func Constructor() LogSystem {
	d := map[string]int{
		"Year":   4,
		"Month":  7,
		"Day":    10,
		"Hour":   13,
		"Minute": 16,
		"Second": 19,
	}
	return LogSystem{[]pair{}, d}
}

func (this *LogSystem) Put(id int, timestamp string) {
	this.logs = append(this.logs, pair{id, timestamp})
}

func (this *LogSystem) Retrieve(start string, end string, granularity string) (ans []int) {
	i := this.d[granularity]
	s, e := start[:i], end[:i]
	for _, log := range this.logs {
		t := log.ts[:i]
		if s <= t && t <= e {
			ans = append(ans, log.id)
		}
	}
	return
}

type pair struct {
	id int
	ts string
}

/**
 * Your LogSystem object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Put(id,timestamp);
 * param_2 := obj.Retrieve(start,end,granularity);
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [636. 函数的独占时间](https://leetcode.cn/problems/exclusive-time-of-functions){#636}

{{< tabs "636" >}}

{{% tab "python" %}}
```python
class Solution:
    def exclusiveTime(self, n: int, logs: List[str]) -> List[int]:
        stk = []
        ans = [0] * n
        pre = 0
        for log in logs:
            i, op, t = log.split(":")
            i, cur = int(i), int(t)
            if op[0] == "s":
                if stk:
                    ans[stk[-1]] += cur - pre
                stk.append(i)
                pre = cur
            else:
                ans[stk.pop()] += cur - pre + 1
                pre = cur + 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] exclusiveTime(int n, List<String> logs) {
        int[] ans = new int[n];
        Deque<Integer> stk = new ArrayDeque<>();
        int pre = 0;
        for (var log : logs) {
            var parts = log.split(":");
            int i = Integer.parseInt(parts[0]);
            int cur = Integer.parseInt(parts[2]);
            if (parts[1].charAt(0) == 's') {
                if (!stk.isEmpty()) {
                    ans[stk.peek()] += cur - pre;
                }
                stk.push(i);
                pre = cur;
            } else {
                ans[stk.pop()] += cur - pre + 1;
                pre = cur + 1;
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
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n);
        stack<int> stk;
        int pre = 0;
        for (const auto& log : logs) {
            int i, cur;
            char c[10];
            sscanf(log.c_str(), "%d:%[^:]:%d", &i, c, &cur);
            if (c[0] == 's') {
                if (stk.size()) {
                    ans[stk.top()] += cur - pre;
                }
                stk.push(i);
                pre = cur;
            } else {
                ans[stk.top()] += cur - pre + 1;
                stk.pop();
                pre = cur + 1;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func exclusiveTime(n int, logs []string) []int {
	ans := make([]int, n)
	stk := []int{}
	pre := 0
	for _, log := range logs {
		parts := strings.Split(log, ":")
		i, _ := strconv.Atoi(parts[0])
		cur, _ := strconv.Atoi(parts[2])
		if parts[1][0] == 's' {
			if len(stk) > 0 {
				ans[stk[len(stk)-1]] += cur - pre
			}
			stk = append(stk, i)
			pre = cur
		} else {
			ans[stk[len(stk)-1]] += cur - pre + 1
			stk = stk[:len(stk)-1]
			pre = cur + 1
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function exclusiveTime(n: number, logs: string[]): number[] {
    const ans: number[] = Array(n).fill(0);
    let pre = 0;
    const stk: number[] = [];
    for (const log of logs) {
        const [i, op, cur] = log.split(':');
        if (op[0] === 's') {
            if (stk.length) {
                ans[stk.at(-1)!] += +cur - pre;
            }
            stk.push(+i);
            pre = +cur;
        } else {
            ans[stk.pop()!] += +cur - pre + 1;
            pre = +cur + 1;
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

<p>有一个 <strong>单线程</strong> CPU 正在运行一个含有 <code>n</code> 道函数的程序。每道函数都有一个位于&nbsp; <code>0</code> 和 <code>n-1</code> 之间的唯一标识符。</p>

<p>函数调用 <strong>存储在一个 <a href="https://baike.baidu.com/item/%E8%B0%83%E7%94%A8%E6%A0%88/22718047?fr=aladdin" target="_blank">调用栈</a> 上</strong> ：当一个函数调用开始时，它的标识符将会推入栈中。而当一个函数调用结束时，它的标识符将会从栈中弹出。标识符位于栈顶的函数是 <strong>当前正在执行的函数</strong> 。每当一个函数开始或者结束时，将会记录一条日志，包括函数标识符、是开始还是结束、以及相应的时间戳。</p>

<p>给你一个由日志组成的列表 <code>logs</code> ，其中 <code>logs[i]</code> 表示第 <code>i</code> 条日志消息，该消息是一个按 <code>"{function_id}:{"start" | "end"}:{timestamp}"</code> 进行格式化的字符串。例如，<code>"0:start:3"</code> 意味着标识符为 <code>0</code> 的函数调用在时间戳 <code>3</code> 的 <strong>起始开始执行</strong> ；而 <code>"1:end:2"</code> 意味着标识符为 <code>1</code> 的函数调用在时间戳 <code>2</code> 的 <strong>末尾结束执行</strong>。注意，函数可以 <strong>调用多次，可能存在递归调用 </strong>。</p>

<p>函数的 <strong>独占时间</strong> 定义是在这个函数在程序所有函数调用中执行时间的总和，调用其他函数花费的时间不算该函数的独占时间。例如，如果一个函数被调用两次，一次调用执行 <code>2</code> 单位时间，另一次调用执行 <code>1</code> 单位时间，那么该函数的 <strong>独占时间</strong> 为 <code>2 + 1 = 3</code> 。</p>

<p>以数组形式返回每个函数的 <strong>独占时间</strong> ，其中第 <code>i</code> 个下标对应的值表示标识符 <code>i</code> 的函数的独占时间。</p>
&nbsp;

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0600-0699/0636.Exclusive%20Time%20of%20Functions/images/diag1b.png" style="width: 550px; height: 239px;" />
<pre>
<strong>输入：</strong>n = 2, logs = ["0:start:0","1:start:2","1:end:5","0:end:6"]
<strong>输出：</strong>[3,4]
<strong>解释：</strong>
函数 0 在时间戳 0 的起始开始执行，执行 2 个单位时间，于时间戳 1 的末尾结束执行。 
函数 1 在时间戳 2 的起始开始执行，执行 4 个单位时间，于时间戳 5 的末尾结束执行。 
函数 0 在时间戳 6 的开始恢复执行，执行 1 个单位时间。 
所以函数 0 总共执行 2 + 1 = 3 个单位时间，函数 1 总共执行 4 个单位时间。 
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 1, logs = ["0:start:0","0:start:2","0:end:5","0:start:6","0:end:6","0:end:7"]
<strong>输出：</strong>[8]
<strong>解释：</strong>
函数 0 在时间戳 0 的起始开始执行，执行 2 个单位时间，并递归调用它自身。
函数 0（递归调用）在时间戳 2 的起始开始执行，执行 4 个单位时间。
函数 0（初始调用）恢复执行，并立刻再次调用它自身。
函数 0（第二次递归调用）在时间戳 6 的起始开始执行，执行 1 个单位时间。
函数 0（初始调用）在时间戳 7 的起始恢复执行，执行 1 个单位时间。
所以函数 0 总共执行 2 + 4 + 1 + 1 = 8 个单位时间。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 2, logs = ["0:start:0","0:start:2","0:end:5","1:start:6","1:end:6","0:end:7"]
<strong>输出：</strong>[7,1]
<strong>解释：</strong>
函数 0 在时间戳 0 的起始开始执行，执行 2 个单位时间，并递归调用它自身。
函数 0（递归调用）在时间戳 2 的起始开始执行，执行 4 个单位时间。
函数 0（初始调用）恢复执行，并立刻调用函数 1 。
函数 1在时间戳 6 的起始开始执行，执行 1 个单位时间，于时间戳 6 的末尾结束执行。
函数 0（初始调用）在时间戳 7 的起始恢复执行，执行 1 个单位时间，于时间戳 7 的末尾结束执行。
所以函数 0 总共执行 2 + 4 + 1 = 7 个单位时间，函数 1 总共执行 1 个单位时间。 </pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>2 &lt;= logs.length &lt;= 500</code></li>
	<li><code>0 &lt;= function_id &lt; n</code></li>
	<li><code>0 &lt;= timestamp &lt;= 10<sup>9</sup></code></li>
	<li>两个开始事件不会在同一时间戳发生</li>
	<li>两个结束事件不会在同一时间戳发生</li>
	<li>每道函数都有一个对应&nbsp;<code>"start"</code> 日志的 <code>"end"</code> 日志</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：栈 + 模拟

我们定义一个栈 $\textit{stk}$，用于存储当前正在执行的函数的标识符。同时，我们定义一个数组 $\textit{ans}$，用于存储每个函数的独占时间，初始时每个函数的独占时间都为 $0$。用一个变量 $\textit{pre}$ 记录上一个时间戳。

遍历日志数组，对于每一条日志，我们首先将其按照冒号分隔，得到函数标识符 $\textit{i}$，操作类型 $\textit{op}$ 和时间戳 $\textit{t}$。

如果 $\textit{op}$ 为 $\text{start}$，则表示函数 $\textit{i}$ 开始执行，我们需要判断栈是否为空，如果不为空，则将栈顶函数的独占时间增加 $\textit{cur} - \textit{pre}$，然后将 $\textit{i}$ 入栈，更新 $\textit{pre}$ 为 $\textit{cur}$；如果 $\textit{op}$ 为 $\text{end}$，则表示函数 $\textit{i}$ 结束执行，我们将栈顶函数的独占时间增加 $\textit{cur} - \textit{pre} + 1$，然后将栈顶元素出栈，更新 $\textit{pre}$ 为 $\textit{cur} + 1$。

最后返回数组 $\textit{ans}$ 即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为日志数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def exclusiveTime(self, n: int, logs: List[str]) -> List[int]:
        stk = []
        ans = [0] * n
        pre = 0
        for log in logs:
            i, op, t = log.split(":")
            i, cur = int(i), int(t)
            if op[0] == "s":
                if stk:
                    ans[stk[-1]] += cur - pre
                stk.append(i)
                pre = cur
            else:
                ans[stk.pop()] += cur - pre + 1
                pre = cur + 1
        return ans
```

#### Java

```java
class Solution {
    public int[] exclusiveTime(int n, List<String> logs) {
        int[] ans = new int[n];
        Deque<Integer> stk = new ArrayDeque<>();
        int pre = 0;
        for (var log : logs) {
            var parts = log.split(":");
            int i = Integer.parseInt(parts[0]);
            int cur = Integer.parseInt(parts[2]);
            if (parts[1].charAt(0) == 's') {
                if (!stk.isEmpty()) {
                    ans[stk.peek()] += cur - pre;
                }
                stk.push(i);
                pre = cur;
            } else {
                ans[stk.pop()] += cur - pre + 1;
                pre = cur + 1;
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
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n);
        stack<int> stk;
        int pre = 0;
        for (const auto& log : logs) {
            int i, cur;
            char c[10];
            sscanf(log.c_str(), "%d:%[^:]:%d", &i, c, &cur);
            if (c[0] == 's') {
                if (stk.size()) {
                    ans[stk.top()] += cur - pre;
                }
                stk.push(i);
                pre = cur;
            } else {
                ans[stk.top()] += cur - pre + 1;
                stk.pop();
                pre = cur + 1;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func exclusiveTime(n int, logs []string) []int {
	ans := make([]int, n)
	stk := []int{}
	pre := 0
	for _, log := range logs {
		parts := strings.Split(log, ":")
		i, _ := strconv.Atoi(parts[0])
		cur, _ := strconv.Atoi(parts[2])
		if parts[1][0] == 's' {
			if len(stk) > 0 {
				ans[stk[len(stk)-1]] += cur - pre
			}
			stk = append(stk, i)
			pre = cur
		} else {
			ans[stk[len(stk)-1]] += cur - pre + 1
			stk = stk[:len(stk)-1]
			pre = cur + 1
		}
	}
	return ans
}
```

#### TypeScript

```ts
function exclusiveTime(n: number, logs: string[]): number[] {
    const ans: number[] = Array(n).fill(0);
    let pre = 0;
    const stk: number[] = [];
    for (const log of logs) {
        const [i, op, cur] = log.split(':');
        if (op[0] === 's') {
            if (stk.length) {
                ans[stk.at(-1)!] += +cur - pre;
            }
            stk.push(+i);
            pre = +cur;
        } else {
            ans[stk.pop()!] += +cur - pre + 1;
            pre = +cur + 1;
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

# [637. 二叉树的层平均值](https://leetcode.cn/problems/average-of-levels-in-binary-tree){#637}

{{< tabs "637" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:
        def dfs(root, i):
            if root is None:
                return
            if len(s) == i:
                s.append([root.val, 1])
            else:
                s[i][0] += root.val
                s[i][1] += 1
            dfs(root.left, i + 1)
            dfs(root.right, i + 1)

        s = []
        dfs(root, 0)
        return [a / b for a, b in s]
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
    private List<Long> s = new ArrayList<>();
    private List<Integer> cnt = new ArrayList<>();

    public List<Double> averageOfLevels(TreeNode root) {
        dfs(root, 0);
        List<Double> ans = new ArrayList<>();
        for (int i = 0; i < s.size(); ++i) {
            ans.add(s.get(i) * 1.0 / cnt.get(i));
        }
        return ans;
    }

    private void dfs(TreeNode root, int i) {
        if (root == null) {
            return;
        }
        if (s.size() == i) {
            s.add((long) root.val);
            cnt.add(1);
        } else {
            s.set(i, s.get(i) + root.val);
            cnt.set(i, cnt.get(i) + 1);
        }
        dfs(root.left, i + 1);
        dfs(root.right, i + 1);
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

using ll = long long;

class Solution {
public:
    vector<ll> s;
    vector<int> cnt;

    vector<double> averageOfLevels(TreeNode* root) {
        dfs(root, 0);
        vector<double> ans(s.size());
        for (int i = 0; i < s.size(); ++i) {
            ans[i] = (s[i] * 1.0 / cnt[i]);
        }
        return ans;
    }

    void dfs(TreeNode* root, int i) {
        if (!root) return;
        if (s.size() == i) {
            s.push_back(root->val);
            cnt.push_back(1);
        } else {
            s[i] += root->val;
            cnt[i]++;
        }
        dfs(root->left, i + 1);
        dfs(root->right, i + 1);
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
func averageOfLevels(root *TreeNode) []float64 {
	s := []int{}
	cnt := []int{}
	var dfs func(root *TreeNode, i int)
	dfs = func(root *TreeNode, i int) {
		if root == nil {
			return
		}
		if len(s) == i {
			s = append(s, root.Val)
			cnt = append(cnt, 1)
		} else {
			s[i] += root.Val
			cnt[i]++
		}
		dfs(root.Left, i+1)
		dfs(root.Right, i+1)
	}
	dfs(root, 0)
	ans := []float64{}
	for i, t := range s {
		ans = append(ans, float64(t)/float64(cnt[i]))
	}
	return ans
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
use std::collections::VecDeque;
use std::rc::Rc;

impl Solution {
    pub fn average_of_levels(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<f64> {
        let mut ans = vec![];
        let mut q = VecDeque::new();
        if let Some(root_node) = root {
            q.push_back(root_node);
        }
        while !q.is_empty() {
            let n = q.len();
            let mut s: i64 = 0;
            for _ in 0..n {
                if let Some(node) = q.pop_front() {
                    let node_borrow = node.borrow();
                    s += node_borrow.val as i64;
                    if let Some(left) = node_borrow.left.clone() {
                        q.push_back(left);
                    }
                    if let Some(right) = node_borrow.right.clone() {
                        q.push_back(right);
                    }
                }
            }
            ans.push((s as f64) / (n as f64));
        }
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
 * @return {number[]}
 */
var averageOfLevels = function (root) {
    const s = [];
    const cnt = [];
    function dfs(root, i) {
        if (!root) {
            return;
        }
        if (s.length == i) {
            s.push(root.val);
            cnt.push(1);
        } else {
            s[i] += root.val;
            cnt[i]++;
        }
        dfs(root.left, i + 1);
        dfs(root.right, i + 1);
    }
    dfs(root, 0);
    return s.map((v, i) => v / cnt[i]);
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个非空二叉树的根节点<meta charset="UTF-8" />&nbsp;<code>root</code>&nbsp;, 以数组的形式返回每一层节点的平均值。与实际答案相差&nbsp;<code>10<sup>-5</sup></code> 以内的答案可以被接受。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0600-0699/0637.Average%20of%20Levels%20in%20Binary%20Tree/images/avg1-tree.jpg" /></p>

<pre>
<strong>输入：</strong>root = [3,9,20,null,null,15,7]
<strong>输出：</strong>[3.00000,14.50000,11.00000]
<strong>解释：</strong>第 0 层的平均值为 3,第 1 层的平均值为 14.5,第 2 层的平均值为 11 。
因此返回 [3, 14.5, 11] 。
</pre>

<p><strong>示例 2:</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0600-0699/0637.Average%20of%20Levels%20in%20Binary%20Tree/images/avg2-tree.jpg" /></p>

<pre>
<strong>输入：</strong>root = [3,9,20,15,7]
<strong>输出：</strong>[3.00000,14.50000,11.00000]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<p><meta charset="UTF-8" /></p>

<ul>
	<li>树中节点数量在&nbsp;<code>[1, 10<sup>4</sup>]</code> 范围内</li>
	<li><code>-2<sup>31</sup>&nbsp;&lt;= Node.val &lt;= 2<sup>31</sup>&nbsp;- 1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：BFS

我们可以使用广度优先搜索的方法，遍历每一层的节点，计算每一层的平均值。

具体地，我们定义一个队列 $q$，初始时将根节点加入队列。每次将队列中的所有节点取出，计算这些节点的平均值，加入答案数组中，并将这些节点的子节点加入队列。重复这一过程，直到队列为空。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是二叉树的节点个数。

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
    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:
        q = deque([root])
        ans = []
        while q:
            s, n = 0, len(q)
            for _ in range(n):
                root = q.popleft()
                s += root.val
                if root.left:
                    q.append(root.left)
                if root.right:
                    q.append(root.right)
            ans.append(s / n)
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
    public List<Double> averageOfLevels(TreeNode root) {
        List<Double> ans = new ArrayList<>();
        Deque<TreeNode> q = new ArrayDeque<>();
        q.offer(root);
        while (!q.isEmpty()) {
            int n = q.size();
            long s = 0;
            for (int i = 0; i < n; ++i) {
                root = q.pollFirst();
                s += root.val;
                if (root.left != null) {
                    q.offer(root.left);
                }
                if (root.right != null) {
                    q.offer(root.right);
                }
            }
            ans.add(s * 1.0 / n);
        }
        return ans;
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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q{{root}};
        vector<double> ans;
        while (!q.empty()) {
            int n = q.size();
            long long s = 0;
            for (int i = 0; i < n; ++i) {
                root = q.front();
                q.pop();
                s += root->val;
                if (root->left) {
                    q.push(root->left);
                }
                if (root->right) {
                    q.push(root->right);
                }
            }
            ans.push_back(s * 1.0 / n);
        }
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
func averageOfLevels(root *TreeNode) []float64 {
	q := []*TreeNode{root}
	ans := []float64{}
	for len(q) > 0 {
		n := len(q)
		s := 0
		for i := 0; i < n; i++ {
			root = q[0]
			q = q[1:]
			s += root.Val
			if root.Left != nil {
				q = append(q, root.Left)
			}
			if root.Right != nil {
				q = append(q, root.Right)
			}
		}
		ans = append(ans, float64(s)/float64(n))
	}
	return ans
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
use std::collections::VecDeque;
use std::rc::Rc;

impl Solution {
    pub fn average_of_levels(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<f64> {
        let mut ans = vec![];
        let mut q = VecDeque::new();
        if let Some(root_node) = root {
            q.push_back(root_node);
        }
        while !q.is_empty() {
            let n = q.len();
            let mut s: i64 = 0;
            for _ in 0..n {
                if let Some(node) = q.pop_front() {
                    let node_borrow = node.borrow();
                    s += node_borrow.val as i64;
                    if let Some(left) = node_borrow.left.clone() {
                        q.push_back(left);
                    }
                    if let Some(right) = node_borrow.right.clone() {
                        q.push_back(right);
                    }
                }
            }
            ans.push((s as f64) / (n as f64));
        }
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
 * @return {number[]}
 */
var averageOfLevels = function (root) {
    const q = [root];
    const ans = [];
    while (q.length) {
        const n = q.length;
        const nq = [];
        let s = 0;
        for (const { val, left, right } of q) {
            s += val;
            left && nq.push(left);
            right && nq.push(right);
        }
        ans.push(s / n);
        q.splice(0, q.length, ...nq);
    }
    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：DFS

我们也可以使用深度优先搜索的方法，来计算每一层的平均值。

具体地，我们定义一个数组 $s$，其中 $s[i]$ 是一个二元组，表示第 $i$ 层的节点值之和以及节点个数。我们对树进行深度优先搜索，对于每一个节点，我们将节点的值加到对应的 $s[i]$ 中，并将节点个数加一。最后，对于每一个 $s[i]$，我们计算平均值，加入答案数组中。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是二叉树的节点个数。

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
    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:
        def dfs(root, i):
            if root is None:
                return
            if len(s) == i:
                s.append([root.val, 1])
            else:
                s[i][0] += root.val
                s[i][1] += 1
            dfs(root.left, i + 1)
            dfs(root.right, i + 1)

        s = []
        dfs(root, 0)
        return [a / b for a, b in s]
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
    private List<Long> s = new ArrayList<>();
    private List<Integer> cnt = new ArrayList<>();

    public List<Double> averageOfLevels(TreeNode root) {
        dfs(root, 0);
        List<Double> ans = new ArrayList<>();
        for (int i = 0; i < s.size(); ++i) {
            ans.add(s.get(i) * 1.0 / cnt.get(i));
        }
        return ans;
    }

    private void dfs(TreeNode root, int i) {
        if (root == null) {
            return;
        }
        if (s.size() == i) {
            s.add((long) root.val);
            cnt.add(1);
        } else {
            s.set(i, s.get(i) + root.val);
            cnt.set(i, cnt.get(i) + 1);
        }
        dfs(root.left, i + 1);
        dfs(root.right, i + 1);
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

using ll = long long;

class Solution {
public:
    vector<ll> s;
    vector<int> cnt;

    vector<double> averageOfLevels(TreeNode* root) {
        dfs(root, 0);
        vector<double> ans(s.size());
        for (int i = 0; i < s.size(); ++i) {
            ans[i] = (s[i] * 1.0 / cnt[i]);
        }
        return ans;
    }

    void dfs(TreeNode* root, int i) {
        if (!root) return;
        if (s.size() == i) {
            s.push_back(root->val);
            cnt.push_back(1);
        } else {
            s[i] += root->val;
            cnt[i]++;
        }
        dfs(root->left, i + 1);
        dfs(root->right, i + 1);
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
func averageOfLevels(root *TreeNode) []float64 {
	s := []int{}
	cnt := []int{}
	var dfs func(root *TreeNode, i int)
	dfs = func(root *TreeNode, i int) {
		if root == nil {
			return
		}
		if len(s) == i {
			s = append(s, root.Val)
			cnt = append(cnt, 1)
		} else {
			s[i] += root.Val
			cnt[i]++
		}
		dfs(root.Left, i+1)
		dfs(root.Right, i+1)
	}
	dfs(root, 0)
	ans := []float64{}
	for i, t := range s {
		ans = append(ans, float64(t)/float64(cnt[i]))
	}
	return ans
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
 * @return {number[]}
 */
var averageOfLevels = function (root) {
    const s = [];
    const cnt = [];
    function dfs(root, i) {
        if (!root) {
            return;
        }
        if (s.length == i) {
            s.push(root.val);
            cnt.push(1);
        } else {
            s[i] += root.val;
            cnt[i]++;
        }
        dfs(root.left, i + 1);
        dfs(root.right, i + 1);
    }
    dfs(root, 0);
    return s.map((v, i) => v / cnt[i]);
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [638. 大礼包](https://leetcode.cn/problems/shopping-offers){#638}

{{< tabs "638" >}}

{{% tab "python" %}}
```python
class Solution:
    def shoppingOffers(
        self, price: List[int], special: List[List[int]], needs: List[int]
    ) -> int:
        @cache
        def dfs(cur: int) -> int:
            ans = sum(p * (cur >> (i * bits) & 0xF) for i, p in enumerate(price))
            for offer in special:
                nxt = cur
                for j in range(len(needs)):
                    if (cur >> (j * bits) & 0xF) < offer[j]:
                        break
                    nxt -= offer[j] << (j * bits)
                else:
                    ans = min(ans, offer[-1] + dfs(nxt))
            return ans

        bits, mask = 4, 0
        for i, need in enumerate(needs):
            mask |= need << i * bits
        return dfs(mask)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private final int bits = 4;
    private int n;
    private List<Integer> price;
    private List<List<Integer>> special;
    private Map<Integer, Integer> f = new HashMap<>();

    public int shoppingOffers(
        List<Integer> price, List<List<Integer>> special, List<Integer> needs) {
        n = needs.size();
        this.price = price;
        this.special = special;
        int mask = 0;
        for (int i = 0; i < n; ++i) {
            mask |= needs.get(i) << (i * bits);
        }
        return dfs(mask);
    }

    private int dfs(int cur) {
        if (f.containsKey(cur)) {
            return f.get(cur);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += price.get(i) * (cur >> (i * bits) & 0xf);
        }
        for (List<Integer> offer : special) {
            int nxt = cur;
            boolean ok = true;
            for (int j = 0; j < n; ++j) {
                if ((cur >> (j * bits) & 0xf) < offer.get(j)) {
                    ok = false;
                    break;
                }
                nxt -= offer.get(j) << (j * bits);
            }
            if (ok) {
                ans = Math.min(ans, offer.get(n) + dfs(nxt));
            }
        }
        f.put(cur, ans);
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        const int bits = 4;
        int n = needs.size();
        unordered_map<int, int> f;
        int mask = 0;
        for (int i = 0; i < n; ++i) {
            mask |= needs[i] << (i * bits);
        }
        function<int(int)> dfs = [&](int cur) {
            if (f.contains(cur)) {
                return f[cur];
            }
            int ans = 0;
            for (int i = 0; i < n; ++i) {
                ans += price[i] * ((cur >> (i * bits)) & 0xf);
            }
            for (const auto& offer : special) {
                int nxt = cur;
                bool ok = true;
                for (int j = 0; j < n; ++j) {
                    if (((cur >> (j * bits)) & 0xf) < offer[j]) {
                        ok = false;
                        break;
                    }
                    nxt -= offer[j] << (j * bits);
                }
                if (ok) {
                    ans = min(ans, offer[n] + dfs(nxt));
                }
            }
            f[cur] = ans;
            return ans;
        };
        return dfs(mask);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func shoppingOffers(price []int, special [][]int, needs []int) int {
	const bits = 4
	n := len(needs)
	f := make(map[int]int)
	mask := 0
	for i, need := range needs {
		mask |= need << (i * bits)
	}

	var dfs func(int) int
	dfs = func(cur int) int {
		if v, ok := f[cur]; ok {
			return v
		}
		ans := 0
		for i := 0; i < n; i++ {
			ans += price[i] * ((cur >> (i * bits)) & 0xf)
		}
		for _, offer := range special {
			nxt := cur
			ok := true
			for j := 0; j < n; j++ {
				if ((cur >> (j * bits)) & 0xf) < offer[j] {
					ok = false
					break
				}
				nxt -= offer[j] << (j * bits)
			}
			if ok {
				ans = min(ans, offer[n]+dfs(nxt))
			}
		}
		f[cur] = ans
		return ans
	}

	return dfs(mask)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function shoppingOffers(price: number[], special: number[][], needs: number[]): number {
    const bits = 4;
    const n = needs.length;
    const f: Map<number, number> = new Map();

    let mask = 0;
    for (let i = 0; i < n; i++) {
        mask |= needs[i] << (i * bits);
    }

    const dfs = (cur: number): number => {
        if (f.has(cur)) {
            return f.get(cur)!;
        }
        let ans = 0;
        for (let i = 0; i < n; i++) {
            ans += price[i] * ((cur >> (i * bits)) & 0xf);
        }
        for (const offer of special) {
            let nxt = cur;
            let ok = true;
            for (let j = 0; j < n; j++) {
                if (((cur >> (j * bits)) & 0xf) < offer[j]) {
                    ok = false;
                    break;
                }
                nxt -= offer[j] << (j * bits);
            }
            if (ok) {
                ans = Math.min(ans, offer[n] + dfs(nxt));
            }
        }
        f.set(cur, ans);
        return ans;
    };

    return dfs(mask);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>在 LeetCode 商店中， 有 <code>n</code> 件在售的物品。每件物品都有对应的价格。然而，也有一些大礼包，每个大礼包以优惠的价格捆绑销售一组物品。</p>

<p>给你一个整数数组 <code>price</code> 表示物品价格，其中 <code>price[i]</code> 是第 <code>i</code> 件物品的价格。另有一个整数数组 <code>needs</code> 表示购物清单，其中 <code>needs[i]</code> 是需要购买第 <code>i</code> 件物品的数量。</p>

<p>还有一个数组 <code>special</code> 表示大礼包，<code>special[i]</code> 的长度为 <code>n + 1</code> ，其中 <code>special[i][j]</code> 表示第 <code>i</code> 个大礼包中内含第 <code>j</code> 件物品的数量，且 <code>special[i][n]</code> （也就是数组中的最后一个整数）为第 <code>i</code> 个大礼包的价格。</p>

<p>返回<strong> 确切 </strong>满足购物清单所需花费的最低价格，你可以充分利用大礼包的优惠活动。你不能购买超出购物清单指定数量的物品，即使那样会降低整体价格。任意大礼包可无限次购买。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>price = [2,5], special = [[3,0,5],[1,2,10]], needs = [3,2]
<strong>输出：</strong>14
<strong>解释：</strong>有 A 和 B 两种物品，价格分别为 ¥2 和 ¥5 。 
大礼包 1 ，你可以以 ¥5 的价格购买 3A 和 0B 。 
大礼包 2 ，你可以以 ¥10 的价格购买 1A 和 2B 。 
需要购买 3 个 A 和 2 个 B ， 所以付 ¥10 购买 1A 和 2B（大礼包 2），以及 ¥4 购买 2A 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>price = [2,3,4], special = [[1,1,0,4],[2,2,1,9]], needs = [1,2,1]
<strong>输出：</strong>11
<strong>解释：</strong>A ，B ，C 的价格分别为 ¥2 ，¥3 ，¥4 。
可以用 ¥4 购买 1A 和 1B ，也可以用 ¥9 购买 2A ，2B 和 1C 。 
需要买 1A ，2B 和 1C ，所以付 ¥4 买 1A 和 1B（大礼包 1），以及 ¥3 购买 1B ， ¥4 购买 1C 。 
不可以购买超出待购清单的物品，尽管购买大礼包 2 更加便宜。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == price.length == needs.length</code></li>
	<li><code>1 &lt;= n &lt;= 6</code></li>
	<li><code>0 &lt;= price[i], needs[i] &lt;= 10</code></li>
	<li><code>1 &lt;= special.length &lt;= 100</code></li>
	<li><code>special[i].length == n + 1</code></li>
	<li><code>0 &lt;= special[i][j] &lt;= 50</code></li>
	<li>生成的输入对于&nbsp;<code>0 &lt;= j &lt;= n - 1</code> 至少有一个&nbsp;<code>special[i][j]</code>&nbsp;非零。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：状态压缩 + 记忆化搜索

我们注意到，题目中物品的种类 $n \leq 6$，而每种物品需要购买的数量不超过 $10$，我们可以用 $4$ 个二进制位来表示每种物品需要购买的数量，这样，我们只需要最多 $6 \times 4 = 24$ 个二进制位来表示整个购物清单。

我们首先将购物清单 $\textit{needs}$ 转换为一个整数 $\textit{mask}$，其中第 $i$ 个物品需要购买的数量存储在 $\textit{mask}$ 的第 $i \times 4$ 位到第 $(i + 1) \times 4 - 1$ 位。例如，当 $\textit{needs} = [1, 2, 1]$ 时，有 $\textit{mask} = 0b0001 0010 0001$。

然后，我们设计一个函数 $\textit{dfs}(cur)$，表示当前购物清单的状态为 $\textit{cur}$ 时，我们需要花费的最少金额。那么答案即为 $\textit{dfs}(\textit{mask})$。

函数 $\textit{dfs}(cur)$ 的计算方法如下：

-   我们首先计算当前购物清单 $\textit{cur}$ 不使用大礼包时的花费，记为 $\textit{ans}$。
-   然后，我们遍历每一个大礼包 $\textit{offer}$，如果当前购物清单 $\textit{cur}$ 能够使用大礼包 $\textit{offer}$，即 $\textit{cur}$ 中每种物品的数量都不小于大礼包 $\textit{offer}$ 中的数量，那么我们可以尝试使用这个大礼包。我们将 $\textit{cur}$ 中每种物品的数量减去大礼包 $\textit{offer}$ 中的数量，得到一个新的购物清单 $\textit{nxt}$，然后递归计算 $\textit{nxt}$ 的最少花费，并加上大礼包的价格 $\textit{offer}[n]$，更新 $\textit{ans}$，即 $\textit{ans} = \min(\textit{ans}, \textit{offer}[n] + \textit{dfs}(\textit{nxt}))$。
-   最后，返回 $\textit{ans}$。

为了避免重复计算，我们使用一个哈希表 $\textit{f}$ 记录每一个状态 $\textit{cur}$ 对应的最少花费。

时间复杂度 $O(n \times k \times m^n)$，其中 $n$ 表示物品的种类，而 $k$ 和 $m$ 分别表示大礼包的数量以及每种物品的最大需求量。空间复杂度 $O(n \times m^n)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def shoppingOffers(
        self, price: List[int], special: List[List[int]], needs: List[int]
    ) -> int:
        @cache
        def dfs(cur: int) -> int:
            ans = sum(p * (cur >> (i * bits) & 0xF) for i, p in enumerate(price))
            for offer in special:
                nxt = cur
                for j in range(len(needs)):
                    if (cur >> (j * bits) & 0xF) < offer[j]:
                        break
                    nxt -= offer[j] << (j * bits)
                else:
                    ans = min(ans, offer[-1] + dfs(nxt))
            return ans

        bits, mask = 4, 0
        for i, need in enumerate(needs):
            mask |= need << i * bits
        return dfs(mask)
```

#### Java

```java
class Solution {
    private final int bits = 4;
    private int n;
    private List<Integer> price;
    private List<List<Integer>> special;
    private Map<Integer, Integer> f = new HashMap<>();

    public int shoppingOffers(
        List<Integer> price, List<List<Integer>> special, List<Integer> needs) {
        n = needs.size();
        this.price = price;
        this.special = special;
        int mask = 0;
        for (int i = 0; i < n; ++i) {
            mask |= needs.get(i) << (i * bits);
        }
        return dfs(mask);
    }

    private int dfs(int cur) {
        if (f.containsKey(cur)) {
            return f.get(cur);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += price.get(i) * (cur >> (i * bits) & 0xf);
        }
        for (List<Integer> offer : special) {
            int nxt = cur;
            boolean ok = true;
            for (int j = 0; j < n; ++j) {
                if ((cur >> (j * bits) & 0xf) < offer.get(j)) {
                    ok = false;
                    break;
                }
                nxt -= offer.get(j) << (j * bits);
            }
            if (ok) {
                ans = Math.min(ans, offer.get(n) + dfs(nxt));
            }
        }
        f.put(cur, ans);
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        const int bits = 4;
        int n = needs.size();
        unordered_map<int, int> f;
        int mask = 0;
        for (int i = 0; i < n; ++i) {
            mask |= needs[i] << (i * bits);
        }
        function<int(int)> dfs = [&](int cur) {
            if (f.contains(cur)) {
                return f[cur];
            }
            int ans = 0;
            for (int i = 0; i < n; ++i) {
                ans += price[i] * ((cur >> (i * bits)) & 0xf);
            }
            for (const auto& offer : special) {
                int nxt = cur;
                bool ok = true;
                for (int j = 0; j < n; ++j) {
                    if (((cur >> (j * bits)) & 0xf) < offer[j]) {
                        ok = false;
                        break;
                    }
                    nxt -= offer[j] << (j * bits);
                }
                if (ok) {
                    ans = min(ans, offer[n] + dfs(nxt));
                }
            }
            f[cur] = ans;
            return ans;
        };
        return dfs(mask);
    }
};
```

#### Go

```go
func shoppingOffers(price []int, special [][]int, needs []int) int {
	const bits = 4
	n := len(needs)
	f := make(map[int]int)
	mask := 0
	for i, need := range needs {
		mask |= need << (i * bits)
	}

	var dfs func(int) int
	dfs = func(cur int) int {
		if v, ok := f[cur]; ok {
			return v
		}
		ans := 0
		for i := 0; i < n; i++ {
			ans += price[i] * ((cur >> (i * bits)) & 0xf)
		}
		for _, offer := range special {
			nxt := cur
			ok := true
			for j := 0; j < n; j++ {
				if ((cur >> (j * bits)) & 0xf) < offer[j] {
					ok = false
					break
				}
				nxt -= offer[j] << (j * bits)
			}
			if ok {
				ans = min(ans, offer[n]+dfs(nxt))
			}
		}
		f[cur] = ans
		return ans
	}

	return dfs(mask)
}
```

#### TypeScript

```ts
function shoppingOffers(price: number[], special: number[][], needs: number[]): number {
    const bits = 4;
    const n = needs.length;
    const f: Map<number, number> = new Map();

    let mask = 0;
    for (let i = 0; i < n; i++) {
        mask |= needs[i] << (i * bits);
    }

    const dfs = (cur: number): number => {
        if (f.has(cur)) {
            return f.get(cur)!;
        }
        let ans = 0;
        for (let i = 0; i < n; i++) {
            ans += price[i] * ((cur >> (i * bits)) & 0xf);
        }
        for (const offer of special) {
            let nxt = cur;
            let ok = true;
            for (let j = 0; j < n; j++) {
                if (((cur >> (j * bits)) & 0xf) < offer[j]) {
                    ok = false;
                    break;
                }
                nxt -= offer[j] << (j * bits);
            }
            if (ok) {
                ans = Math.min(ans, offer[n] + dfs(nxt));
            }
        }
        f.set(cur, ans);
        return ans;
    };

    return dfs(mask);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [639. 解码方法 II](https://leetcode.cn/problems/decode-ways-ii){#639}

{{< tabs "639" >}}

{{% tab "python" %}}
```python
class Solution:
    def numDecodings(self, s: str) -> int:
        mod = int(1e9 + 7)
        n = len(s)

        # dp[i - 2], dp[i - 1], dp[i]
        a, b, c = 0, 1, 0
        for i in range(1, n + 1):
            # 1 digit
            if s[i - 1] == "*":
                c = 9 * b % mod
            elif s[i - 1] != "0":
                c = b
            else:
                c = 0

            # 2 digits
            if i > 1:
                if s[i - 2] == "*" and s[i - 1] == "*":
                    c = (c + 15 * a) % mod
                elif s[i - 2] == "*":
                    if s[i - 1] > "6":
                        c = (c + a) % mod
                    else:
                        c = (c + 2 * a) % mod
                elif s[i - 1] == "*":
                    if s[i - 2] == "1":
                        c = (c + 9 * a) % mod
                    elif s[i - 2] == "2":
                        c = (c + 6 * a) % mod
                elif (
                    s[i - 2] != "0"
                    and (ord(s[i - 2]) - ord("0")) * 10 + ord(s[i - 1]) - ord("0") <= 26
                ):
                    c = (c + a) % mod

            a, b = b, c

        return c
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {

    private static final int MOD = 1000000007;

    public int numDecodings(String s) {
        int n = s.length();
        char[] cs = s.toCharArray();

        // dp[i - 2], dp[i - 1], dp[i]
        long a = 0, b = 1, c = 0;
        for (int i = 1; i <= n; i++) {
            // 1 digit
            if (cs[i - 1] == '*') {
                c = 9 * b % MOD;
            } else if (cs[i - 1] != '0') {
                c = b;
            } else {
                c = 0;
            }

            // 2 digits
            if (i > 1) {
                if (cs[i - 2] == '*' && cs[i - 1] == '*') {
                    c = (c + 15 * a) % MOD;
                } else if (cs[i - 2] == '*') {
                    if (cs[i - 1] > '6') {
                        c = (c + a) % MOD;
                    } else {
                        c = (c + 2 * a) % MOD;
                    }
                } else if (cs[i - 1] == '*') {
                    if (cs[i - 2] == '1') {
                        c = (c + 9 * a) % MOD;
                    } else if (cs[i - 2] == '2') {
                        c = (c + 6 * a) % MOD;
                    }
                } else if (cs[i - 2] != '0' && (cs[i - 2] - '0') * 10 + cs[i - 1] - '0' <= 26) {
                    c = (c + a) % MOD;
                }
            }

            a = b;
            b = c;
        }

        return (int) c;
    }
}
```
{{% /tab %}}
{{% tab "go" %}}
```go
const mod int = 1e9 + 7

func numDecodings(s string) int {
	n := len(s)

	// dp[i - 2], dp[i - 1], dp[i]
	a, b, c := 0, 1, 0
	for i := 1; i <= n; i++ {
		// 1 digit
		if s[i-1] == '*' {
			c = 9 * b % mod
		} else if s[i-1] != '0' {
			c = b
		} else {
			c = 0
		}

		// 2 digits
		if i > 1 {
			if s[i-2] == '*' && s[i-1] == '*' {
				c = (c + 15*a) % mod
			} else if s[i-2] == '*' {
				if s[i-1] > '6' {
					c = (c + a) % mod
				} else {
					c = (c + 2*a) % mod
				}
			} else if s[i-1] == '*' {
				if s[i-2] == '1' {
					c = (c + 9*a) % mod
				} else if s[i-2] == '2' {
					c = (c + 6*a) % mod
				}
			} else if s[i-2] != '0' && (s[i-2]-'0')*10+s[i-1]-'0' <= 26 {
				c = (c + a) % mod
			}
		}

		a, b = b, c
	}
	return c
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>一条包含字母&nbsp;<code>A-Z</code> 的消息通过以下的方式进行了 <strong>编码</strong> ：</p>

<pre>
'A' -&gt; "1"
'B' -&gt; "2"
...
'Z' -&gt; "26"</pre>

<p>要 <strong>解码</strong> 一条已编码的消息，所有的数字都必须分组，然后按原来的编码方案反向映射回字母（可能存在多种方式）。例如，<code>"11106"</code> 可以映射为：</p>

<ul>
	<li><code>"AAJF"</code> 对应分组 <code>(1 1 10 6)</code></li>
	<li><code>"KJF"</code> 对应分组 <code>(11 10 6)</code></li>
</ul>

<p>注意，像 <code>(1 11 06)</code> 这样的分组是无效的，因为 <code>"06"</code> 不可以映射为 <code>'F'</code> ，因为 <code>"6"</code> 与 <code>"06"</code> 不同。</p>

<p><strong>除了</strong> 上面描述的数字字母映射方案，编码消息中可能包含 <code>'*'</code> 字符，可以表示从 <code>'1'</code> 到 <code>'9'</code> 的任一数字（不包括 <code>'0'</code>）。例如，编码字符串 <code>"1*"</code> 可以表示 <code>"11"</code>、<code>"12"</code>、<code>"13"</code>、<code>"14"</code>、<code>"15"</code>、<code>"16"</code>、<code>"17"</code>、<code>"18"</code> 或 <code>"19"</code> 中的任意一条消息。对 <code>"1*"</code> 进行解码，相当于解码该字符串可以表示的任何编码消息。</p>

<p>给你一个字符串 <code>s</code> ，由数字和 <code>'*'</code> 字符组成，返回 <strong>解码</strong> 该字符串的方法 <strong>数目</strong> 。</p>

<p>由于答案数目可能非常大，返回&nbsp;<code>10<sup>9</sup> + 7</code>&nbsp;的&nbsp;<b>模</b>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "*"
<strong>输出：</strong>9
<strong>解释：</strong>这一条编码消息可以表示 "1"、"2"、"3"、"4"、"5"、"6"、"7"、"8" 或 "9" 中的任意一条。
可以分别解码成字符串 "A"、"B"、"C"、"D"、"E"、"F"、"G"、"H" 和 "I" 。
因此，"*" 总共有 9 种解码方法。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "1*"
<strong>输出：</strong>18
<strong>解释：</strong>这一条编码消息可以表示 "11"、"12"、"13"、"14"、"15"、"16"、"17"、"18" 或 "19" 中的任意一条。
每种消息都可以由 2 种方法解码（例如，"11" 可以解码成 "AA" 或 "K"）。
因此，"1*" 共有 9 * 2 = 18 种解码方法。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "2*"
<strong>输出：</strong>15
<strong>解释：</strong>这一条编码消息可以表示 "21"、"22"、"23"、"24"、"25"、"26"、"27"、"28" 或 "29" 中的任意一条。
"21"、"22"、"23"、"24"、"25" 和 "26" 由 2 种解码方法，但 "27"、"28" 和 "29" 仅有 1 种解码方法。
因此，"2*" 共有 (6 * 2) + (3 * 1) = 12 + 3 = 15 种解码方法。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s[i]</code> 是 <code>0 - 9</code> 中的一位数字或字符 <code>'*'</code></li>
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
    def numDecodings(self, s: str) -> int:
        mod = int(1e9 + 7)
        n = len(s)

        # dp[i - 2], dp[i - 1], dp[i]
        a, b, c = 0, 1, 0
        for i in range(1, n + 1):
            # 1 digit
            if s[i - 1] == "*":
                c = 9 * b % mod
            elif s[i - 1] != "0":
                c = b
            else:
                c = 0

            # 2 digits
            if i > 1:
                if s[i - 2] == "*" and s[i - 1] == "*":
                    c = (c + 15 * a) % mod
                elif s[i - 2] == "*":
                    if s[i - 1] > "6":
                        c = (c + a) % mod
                    else:
                        c = (c + 2 * a) % mod
                elif s[i - 1] == "*":
                    if s[i - 2] == "1":
                        c = (c + 9 * a) % mod
                    elif s[i - 2] == "2":
                        c = (c + 6 * a) % mod
                elif (
                    s[i - 2] != "0"
                    and (ord(s[i - 2]) - ord("0")) * 10 + ord(s[i - 1]) - ord("0") <= 26
                ):
                    c = (c + a) % mod

            a, b = b, c

        return c
```

#### Java

```java
class Solution {

    private static final int MOD = 1000000007;

    public int numDecodings(String s) {
        int n = s.length();
        char[] cs = s.toCharArray();

        // dp[i - 2], dp[i - 1], dp[i]
        long a = 0, b = 1, c = 0;
        for (int i = 1; i <= n; i++) {
            // 1 digit
            if (cs[i - 1] == '*') {
                c = 9 * b % MOD;
            } else if (cs[i - 1] != '0') {
                c = b;
            } else {
                c = 0;
            }

            // 2 digits
            if (i > 1) {
                if (cs[i - 2] == '*' && cs[i - 1] == '*') {
                    c = (c + 15 * a) % MOD;
                } else if (cs[i - 2] == '*') {
                    if (cs[i - 1] > '6') {
                        c = (c + a) % MOD;
                    } else {
                        c = (c + 2 * a) % MOD;
                    }
                } else if (cs[i - 1] == '*') {
                    if (cs[i - 2] == '1') {
                        c = (c + 9 * a) % MOD;
                    } else if (cs[i - 2] == '2') {
                        c = (c + 6 * a) % MOD;
                    }
                } else if (cs[i - 2] != '0' && (cs[i - 2] - '0') * 10 + cs[i - 1] - '0' <= 26) {
                    c = (c + a) % MOD;
                }
            }

            a = b;
            b = c;
        }

        return (int) c;
    }
}
```

#### Go

```go
const mod int = 1e9 + 7

func numDecodings(s string) int {
	n := len(s)

	// dp[i - 2], dp[i - 1], dp[i]
	a, b, c := 0, 1, 0
	for i := 1; i <= n; i++ {
		// 1 digit
		if s[i-1] == '*' {
			c = 9 * b % mod
		} else if s[i-1] != '0' {
			c = b
		} else {
			c = 0
		}

		// 2 digits
		if i > 1 {
			if s[i-2] == '*' && s[i-1] == '*' {
				c = (c + 15*a) % mod
			} else if s[i-2] == '*' {
				if s[i-1] > '6' {
					c = (c + a) % mod
				} else {
					c = (c + 2*a) % mod
				}
			} else if s[i-1] == '*' {
				if s[i-2] == '1' {
					c = (c + 9*a) % mod
				} else if s[i-2] == '2' {
					c = (c + 6*a) % mod
				}
			} else if s[i-2] != '0' && (s[i-2]-'0')*10+s[i-1]-'0' <= 26 {
				c = (c + a) % mod
			}
		}

		a, b = b, c
	}
	return c
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
