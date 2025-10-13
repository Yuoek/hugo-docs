---
title: "0870_优势洗牌"
date: 2025-10-08T18:36:34+08:00
weight: 8
tags: [二分查找, 二叉树, 动态规划, 博弈, 双指针, 哈希表, 堆（优先队列）, 排序, 数学, 数组, 树, 模拟, 深度优先搜索, 贪心, 链表]
---

{{< markmap >}}
### [0870_优势洗牌](#870)
#### [贪心](#870)
#### [数组](#870)
#### [双指针](#870)
#### [排序](#870)
### [0871_最低加油次数](#871)
#### [贪心](#871)
#### [数组](#871)
#### [动态规划](#871)
#### [堆（优先队列）](#871)
### [0872_叶子相似的树](#872)
#### [树](#872)
#### [深度优先搜索](#872)
#### [二叉树](#872)
### [0873_最长的斐波那契子序列的长度](#873)
#### [数组](#873)
#### [哈希表](#873)
#### [动态规划](#873)
### [0874_模拟行走机器人](#874)
#### [数组](#874)
#### [哈希表](#874)
#### [模拟](#874)
### [0875_爱吃香蕉的珂珂](#875)
#### [数组](#875)
#### [二分查找](#875)
### [0876_链表的中间结点](#876)
#### [链表](#876)
#### [双指针](#876)
### [0877_石子游戏](#877)
#### [数组](#877)
#### [数学](#877)
#### [动态规划](#877)
#### [博弈](#877)
### [0878_第 N 个神奇数字](#878)
#### [数学](#878)
#### [二分查找](#878)
### [0879_盈利计划](#879)
#### [数组](#879)
#### [动态规划](#879)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0870_优势洗牌
___
#### 贪心
___
#### 数组
___
#### 双指针
___
#### 排序
---
### 0871_最低加油次数
___
#### 贪心
___
#### 数组
___
#### 动态规划
___
#### 堆（优先队列）
---
### 0872_叶子相似的树
___
#### 树
___
#### 深度优先搜索
___
#### 二叉树
---
### 0873_最长的斐波那契子序列的长度
___
#### 数组
___
#### 哈希表
___
#### 动态规划
---
### 0874_模拟行走机器人
___
#### 数组
___
#### 哈希表
___
#### 模拟
---
### 0875_爱吃香蕉的珂珂
___
#### 数组
___
#### 二分查找
---
### 0876_链表的中间结点
___
#### 链表
___
#### 双指针
---
### 0877_石子游戏
___
#### 数组
___
#### 数学
___
#### 动态规划
___
#### 博弈
---
### 0878_第 N 个神奇数字
___
#### 数学
___
#### 二分查找
---
### 0879_盈利计划
___
#### 数组
___
#### 动态规划
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 二叉树 | 动态规划 |
| 博弈 | 双指针 | 哈希表 |
| 堆（优先队列） | 排序 | 数学 |
| 数组 | 树 | 模拟 |
| 深度优先搜索 | 贪心 | 链表 |

# [870. 优势洗牌](https://leetcode.cn/problems/advantage-shuffle){#870}

{{< tabs "870" >}}

{{% tab "python" %}}
```python
class Solution:
    def advantageCount(self, nums1: List[int], nums2: List[int]) -> List[int]:
        nums1.sort()
        t = sorted((v, i) for i, v in enumerate(nums2))
        n = len(nums2)
        ans = [0] * n
        i, j = 0, n - 1
        for v in nums1:
            if v <= t[i][0]:
                ans[t[j][1]] = v
                j -= 1
            else:
                ans[t[i][1]] = v
                i += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] advantageCount(int[] nums1, int[] nums2) {
        int n = nums1.length;
        int[][] t = new int[n][2];
        for (int i = 0; i < n; ++i) {
            t[i] = new int[] {nums2[i], i};
        }
        Arrays.sort(t, (a, b) -> a[0] - b[0]);
        Arrays.sort(nums1);
        int[] ans = new int[n];
        int i = 0, j = n - 1;
        for (int v : nums1) {
            if (v <= t[i][0]) {
                ans[t[j--][1]] = v;
            } else {
                ans[t[i++][1]] = v;
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
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<pair<int, int>> t;
        for (int i = 0; i < n; ++i) t.push_back({nums2[i], i});
        sort(t.begin(), t.end());
        sort(nums1.begin(), nums1.end());
        int i = 0, j = n - 1;
        vector<int> ans(n);
        for (int v : nums1) {
            if (v <= t[i].first)
                ans[t[j--].second] = v;
            else
                ans[t[i++].second] = v;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func advantageCount(nums1 []int, nums2 []int) []int {
	n := len(nums1)
	t := make([][]int, n)
	for i, v := range nums2 {
		t[i] = []int{v, i}
	}
	sort.Slice(t, func(i, j int) bool {
		return t[i][0] < t[j][0]
	})
	sort.Ints(nums1)
	ans := make([]int, n)
	i, j := 0, n-1
	for _, v := range nums1 {
		if v <= t[i][0] {
			ans[t[j][1]] = v
			j--
		} else {
			ans[t[i][1]] = v
			i++
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function advantageCount(nums1: number[], nums2: number[]): number[] {
    const n = nums1.length;
    const idx = Array.from({ length: n }, (_, i) => i);
    idx.sort((i, j) => nums2[i] - nums2[j]);
    nums1.sort((a, b) => a - b);

    const ans = new Array(n).fill(0);
    let left = 0;
    let right = n - 1;
    for (let i = 0; i < n; i++) {
        if (nums1[i] > nums2[idx[left]]) {
            ans[idx[left]] = nums1[i];
            left++;
        } else {
            ans[idx[right]] = nums1[i];
            right--;
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn advantage_count(mut nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<i32> {
        let n = nums1.len();
        let mut idx = (0..n).collect::<Vec<usize>>();
        idx.sort_by(|&i, &j| nums2[i].cmp(&nums2[j]));
        nums1.sort();
        let mut res = vec![0; n];
        let mut left = 0;
        let mut right = n - 1;
        for &num in nums1.iter() {
            if num > nums2[idx[left]] {
                res[idx[left]] = num;
                left += 1;
            } else {
                res[idx[right]] = num;
                right -= 1;
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

<p>给定两个长度相等的数组&nbsp;<code>nums1</code>&nbsp;和&nbsp;<code>nums2</code>，<code>nums1</code>&nbsp;相对于 <code>nums2</code> 的<em>优势</em>可以用满足&nbsp;<code>nums1[i] &gt; nums2[i]</code>&nbsp;的索引 <code>i</code>&nbsp;的数目来描述。</p>

<p>返回 <code>nums1</code> 的&nbsp;<strong>任意&nbsp;</strong>排列，使其相对于 <code>nums2</code>&nbsp;的优势最大化。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums1 = [2,7,11,15], nums2 = [1,10,4,11]
<strong>输出：</strong>[2,11,7,15]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums1 = [12,24,8,32], nums2 = [13,25,32,11]
<strong>输出：</strong>[24,32,8,12]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums1.length &lt;= 10<sup>5</sup></code></li>
	<li><code>nums2.length == nums1.length</code></li>
	<li><code>0 &lt;= nums1[i], nums2[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 排序

类似田忌赛马。将 $nums1$, $nums2$ 按照升序排列。然后遍历 $nums1$ 中的每个元素 $v$，若在 $nums2[i..j]$ 中找不到比 $v$ 小的，则将 $v$ 与当前 $nums2[i..j]$ 中的最大元素匹配。

时间复杂度 $O(nlogn)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def advantageCount(self, nums1: List[int], nums2: List[int]) -> List[int]:
        nums1.sort()
        t = sorted((v, i) for i, v in enumerate(nums2))
        n = len(nums2)
        ans = [0] * n
        i, j = 0, n - 1
        for v in nums1:
            if v <= t[i][0]:
                ans[t[j][1]] = v
                j -= 1
            else:
                ans[t[i][1]] = v
                i += 1
        return ans
```

#### Java

```java
class Solution {
    public int[] advantageCount(int[] nums1, int[] nums2) {
        int n = nums1.length;
        int[][] t = new int[n][2];
        for (int i = 0; i < n; ++i) {
            t[i] = new int[] {nums2[i], i};
        }
        Arrays.sort(t, (a, b) -> a[0] - b[0]);
        Arrays.sort(nums1);
        int[] ans = new int[n];
        int i = 0, j = n - 1;
        for (int v : nums1) {
            if (v <= t[i][0]) {
                ans[t[j--][1]] = v;
            } else {
                ans[t[i++][1]] = v;
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
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<pair<int, int>> t;
        for (int i = 0; i < n; ++i) t.push_back({nums2[i], i});
        sort(t.begin(), t.end());
        sort(nums1.begin(), nums1.end());
        int i = 0, j = n - 1;
        vector<int> ans(n);
        for (int v : nums1) {
            if (v <= t[i].first)
                ans[t[j--].second] = v;
            else
                ans[t[i++].second] = v;
        }
        return ans;
    }
};
```

#### Go

```go
func advantageCount(nums1 []int, nums2 []int) []int {
	n := len(nums1)
	t := make([][]int, n)
	for i, v := range nums2 {
		t[i] = []int{v, i}
	}
	sort.Slice(t, func(i, j int) bool {
		return t[i][0] < t[j][0]
	})
	sort.Ints(nums1)
	ans := make([]int, n)
	i, j := 0, n-1
	for _, v := range nums1 {
		if v <= t[i][0] {
			ans[t[j][1]] = v
			j--
		} else {
			ans[t[i][1]] = v
			i++
		}
	}
	return ans
}
```

#### TypeScript

```ts
function advantageCount(nums1: number[], nums2: number[]): number[] {
    const n = nums1.length;
    const idx = Array.from({ length: n }, (_, i) => i);
    idx.sort((i, j) => nums2[i] - nums2[j]);
    nums1.sort((a, b) => a - b);

    const ans = new Array(n).fill(0);
    let left = 0;
    let right = n - 1;
    for (let i = 0; i < n; i++) {
        if (nums1[i] > nums2[idx[left]]) {
            ans[idx[left]] = nums1[i];
            left++;
        } else {
            ans[idx[right]] = nums1[i];
            right--;
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn advantage_count(mut nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<i32> {
        let n = nums1.len();
        let mut idx = (0..n).collect::<Vec<usize>>();
        idx.sort_by(|&i, &j| nums2[i].cmp(&nums2[j]));
        nums1.sort();
        let mut res = vec![0; n];
        let mut left = 0;
        let mut right = n - 1;
        for &num in nums1.iter() {
            if num > nums2[idx[left]] {
                res[idx[left]] = num;
                left += 1;
            } else {
                res[idx[right]] = num;
                right -= 1;
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

# [871. 最低加油次数](https://leetcode.cn/problems/minimum-number-of-refueling-stops){#871}

{{< tabs "871" >}}

{{% tab "python" %}}
```python
class Solution:
    def minRefuelStops(
        self, target: int, startFuel: int, stations: List[List[int]]
    ) -> int:
        pq = []
        ans = pre = 0
        stations.append([target, 0])
        for pos, fuel in stations:
            dist = pos - pre
            startFuel -= dist
            while startFuel < 0 and pq:
                startFuel -= heappop(pq)
                ans += 1
            if startFuel < 0:
                return -1
            heappush(pq, -fuel)
            pre = pos
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minRefuelStops(int target, int startFuel, int[][] stations) {
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> b - a);
        int n = stations.length;
        int ans = 0, pre = 0;
        for (int i = 0; i <= n; ++i) {
            int pos = i < n ? stations[i][0] : target;
            int dist = pos - pre;
            startFuel -= dist;
            while (startFuel < 0 && !pq.isEmpty()) {
                startFuel += pq.poll();
                ++ans;
            }
            if (startFuel < 0) {
                return -1;
            }
            if (i < n) {
                pq.offer(stations[i][1]);
                pre = stations[i][0];
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
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        stations.push_back({target, 0});
        int ans = 0, pre = 0;
        for (const auto& station : stations) {
            int pos = station[0], fuel = station[1];
            int dist = pos - pre;
            startFuel -= dist;
            while (startFuel < 0 && !pq.empty()) {
                startFuel += pq.top();
                pq.pop();
                ++ans;
            }
            if (startFuel < 0) {
                return -1;
            }
            pq.push(fuel);
            pre = pos;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minRefuelStops(target int, startFuel int, stations [][]int) int {
	pq := &hp{}
	ans, pre := 0, 0
	stations = append(stations, []int{target, 0})
	for _, station := range stations {
		pos, fuel := station[0], station[1]
		dist := pos - pre
		startFuel -= dist
		for startFuel < 0 && pq.Len() > 0 {
			startFuel += heap.Pop(pq).(int)
			ans++
		}
		if startFuel < 0 {
			return -1
		}
		heap.Push(pq, fuel)
		pre = pos
	}
	return ans
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
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minRefuelStops(target: number, startFuel: number, stations: number[][]): number {
    const pq = new MaxPriorityQueue<number>();
    let [ans, pre] = [0, 0];
    stations.push([target, 0]);
    for (const [pos, fuel] of stations) {
        const dist = pos - pre;
        startFuel -= dist;
        while (startFuel < 0 && !pq.isEmpty()) {
            startFuel += pq.dequeue();
            ans++;
        }
        if (startFuel < 0) {
            return -1;
        }
        pq.enqueue(fuel);
        pre = pos;
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::BinaryHeap;

impl Solution {
    pub fn min_refuel_stops(target: i32, mut start_fuel: i32, mut stations: Vec<Vec<i32>>) -> i32 {
        let mut pq = BinaryHeap::new();
        let mut ans = 0;
        let mut pre = 0;

        stations.push(vec![target, 0]);

        for station in stations {
            let pos = station[0];
            let fuel = station[1];
            let dist = pos - pre;
            start_fuel -= dist;

            while start_fuel < 0 && !pq.is_empty() {
                start_fuel += pq.pop().unwrap();
                ans += 1;
            }

            if start_fuel < 0 {
                return -1;
            }

            pq.push(fuel);
            pre = pos;
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

<p>汽车从起点出发驶向目的地，该目的地位于出发位置东面 <code>target</code>&nbsp;英里处。</p>

<p>沿途有加油站，用数组&nbsp;<code>stations</code> 表示。其中 <code>stations[i] = [position<sub>i</sub>, fuel<sub>i</sub>]</code> 表示第 <code>i</code> 个加油站位于出发位置东面&nbsp;<code>position<sub>i</sub></code> 英里处，并且有&nbsp;<code>fuel<sub>i</sub></code>&nbsp;升汽油。</p>

<p>假设汽车油箱的容量是无限的，其中最初有&nbsp;<code>startFuel</code>&nbsp;升燃料。它每行驶 1 英里就会用掉 1 升汽油。当汽车到达加油站时，它可能停下来加油，将所有汽油从加油站转移到汽车中。</p>

<p>为了到达目的地，汽车所必要的最低加油次数是多少？如果无法到达目的地，则返回 <code>-1</code> 。</p>

<p>注意：如果汽车到达加油站时剩余燃料为 <code>0</code>，它仍然可以在那里加油。如果汽车到达目的地时剩余燃料为 <code>0</code>，仍然认为它已经到达目的地。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>target = 1, startFuel = 1, stations = []
<strong>输出：</strong>0
<strong>解释：</strong>可以在不加油的情况下到达目的地。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>target = 100, startFuel = 1, stations = [[10,100]]
<strong>输出：</strong>-1
<strong>解释：</strong>无法抵达目的地，甚至无法到达第一个加油站。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>target = 100, startFuel = 10, stations = [[10,60],[20,30],[30,30],[60,40]]
<strong>输出：</strong>2
<strong>解释：</strong>
出发时有 10 升燃料。
开车来到距起点 10 英里处的加油站，消耗 10 升燃料。将汽油从 0 升加到 60 升。
然后，从 10 英里处的加油站开到 60 英里处的加油站（消耗 50 升燃料），
并将汽油从 10 升加到 50 升。然后开车抵达目的地。
沿途在两个加油站停靠，所以返回 2 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= target, startFuel &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= stations.length &lt;= 500</code></li>
	<li><code>1 &lt;= position<sub>i</sub> &lt; position<sub>i+1</sub> &lt; target</code></li>
	<li><code>1 &lt;= fuel<sub>i</sub> &lt; 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 优先队列（大根堆）

我们可以利用优先队列（大根堆） $\textit{pq}$ 记录所有已经到达过的加油站的加油量，每次当油量不足时，贪心地取出最大加油量，即 $\textit{pq}$ 的堆顶元素，并累计加油次数 $\textit{ans}$。如果 $\textit{pq}$ 为空并且当前油量仍然不足，说明无法到达目的地，返回 $-1$。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 表示加油站的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minRefuelStops(
        self, target: int, startFuel: int, stations: List[List[int]]
    ) -> int:
        pq = []
        ans = pre = 0
        stations.append([target, 0])
        for pos, fuel in stations:
            dist = pos - pre
            startFuel -= dist
            while startFuel < 0 and pq:
                startFuel -= heappop(pq)
                ans += 1
            if startFuel < 0:
                return -1
            heappush(pq, -fuel)
            pre = pos
        return ans
```

#### Java

```java
class Solution {
    public int minRefuelStops(int target, int startFuel, int[][] stations) {
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> b - a);
        int n = stations.length;
        int ans = 0, pre = 0;
        for (int i = 0; i <= n; ++i) {
            int pos = i < n ? stations[i][0] : target;
            int dist = pos - pre;
            startFuel -= dist;
            while (startFuel < 0 && !pq.isEmpty()) {
                startFuel += pq.poll();
                ++ans;
            }
            if (startFuel < 0) {
                return -1;
            }
            if (i < n) {
                pq.offer(stations[i][1]);
                pre = stations[i][0];
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
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        stations.push_back({target, 0});
        int ans = 0, pre = 0;
        for (const auto& station : stations) {
            int pos = station[0], fuel = station[1];
            int dist = pos - pre;
            startFuel -= dist;
            while (startFuel < 0 && !pq.empty()) {
                startFuel += pq.top();
                pq.pop();
                ++ans;
            }
            if (startFuel < 0) {
                return -1;
            }
            pq.push(fuel);
            pre = pos;
        }
        return ans;
    }
};
```

#### Go

```go
func minRefuelStops(target int, startFuel int, stations [][]int) int {
	pq := &hp{}
	ans, pre := 0, 0
	stations = append(stations, []int{target, 0})
	for _, station := range stations {
		pos, fuel := station[0], station[1]
		dist := pos - pre
		startFuel -= dist
		for startFuel < 0 && pq.Len() > 0 {
			startFuel += heap.Pop(pq).(int)
			ans++
		}
		if startFuel < 0 {
			return -1
		}
		heap.Push(pq, fuel)
		pre = pos
	}
	return ans
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
```

#### TypeScript

```ts
function minRefuelStops(target: number, startFuel: number, stations: number[][]): number {
    const pq = new MaxPriorityQueue<number>();
    let [ans, pre] = [0, 0];
    stations.push([target, 0]);
    for (const [pos, fuel] of stations) {
        const dist = pos - pre;
        startFuel -= dist;
        while (startFuel < 0 && !pq.isEmpty()) {
            startFuel += pq.dequeue();
            ans++;
        }
        if (startFuel < 0) {
            return -1;
        }
        pq.enqueue(fuel);
        pre = pos;
    }
    return ans;
}
```

#### Rust

```rust
use std::collections::BinaryHeap;

impl Solution {
    pub fn min_refuel_stops(target: i32, mut start_fuel: i32, mut stations: Vec<Vec<i32>>) -> i32 {
        let mut pq = BinaryHeap::new();
        let mut ans = 0;
        let mut pre = 0;

        stations.push(vec![target, 0]);

        for station in stations {
            let pos = station[0];
            let fuel = station[1];
            let dist = pos - pre;
            start_fuel -= dist;

            while start_fuel < 0 && !pq.is_empty() {
                start_fuel += pq.pop().unwrap();
                ans += 1;
            }

            if start_fuel < 0 {
                return -1;
            }

            pq.push(fuel);
            pre = pos;
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

# [872. 叶子相似的树](https://leetcode.cn/problems/leaf-similar-trees){#872}

{{< tabs "872" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def leafSimilar(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        def dfs(root: Optional[TreeNode], nums: List[int]) -> None:
            if root.left == root.right:
                nums.append(root.val)
                return
            if root.left:
                dfs(root.left, nums)
            if root.right:
                dfs(root.right, nums)

        l1, l2 = [], []
        dfs(root1, l1)
        dfs(root2, l2)
        return l1 == l2
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
    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        List<Integer> l1 = new ArrayList<>();
        List<Integer> l2 = new ArrayList<>();
        dfs(root1, l1);
        dfs(root2, l2);
        return l1.equals(l2);
    }

    private void dfs(TreeNode root, List<Integer> nums) {
        if (root.left == root.right) {
            nums.add(root.val);
            return;
        }
        if (root.left != null) {
            dfs(root.left, nums);
        }
        if (root.right != null) {
            dfs(root.right, nums);
        }
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
class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> l1, l2;
        dfs(root1, l1);
        dfs(root2, l2);
        return l1 == l2;
    }

    void dfs(TreeNode* root, vector<int>& nums) {
        if (root->left == root->right) {
            nums.push_back(root->val);
            return;
        }
        if (root->left) {
            dfs(root->left, nums);
        }
        if (root->right) {
            dfs(root->right, nums);
        }
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
func leafSimilar(root1 *TreeNode, root2 *TreeNode) bool {
	l1, l2 := []int{}, []int{}
	var dfs func(*TreeNode, *[]int)
	dfs = func(root *TreeNode, nums *[]int) {
		if root.Left == root.Right {
			*nums = append(*nums, root.Val)
			return
		}
		if root.Left != nil {
			dfs(root.Left, nums)
		}
		if root.Right != nil {
			dfs(root.Right, nums)
		}
	}
	dfs(root1, &l1)
	dfs(root2, &l2)
	return reflect.DeepEqual(l1, l2)
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
use std::rc::Rc;
impl Solution {
    pub fn leaf_similar(
        root1: Option<Rc<RefCell<TreeNode>>>,
        root2: Option<Rc<RefCell<TreeNode>>>,
    ) -> bool {
        let mut l1 = Vec::new();
        let mut l2 = Vec::new();
        Self::dfs(&root1, &mut l1);
        Self::dfs(&root2, &mut l2);
        l1 == l2
    }

    fn dfs(node: &Option<Rc<RefCell<TreeNode>>>, nums: &mut Vec<i32>) {
        if let Some(n) = node {
            let n = n.borrow();
            if n.left.is_none() && n.right.is_none() {
                nums.push(n.val);
                return;
            }
            if n.left.is_some() {
                Self::dfs(&n.left, nums);
            }
            if n.right.is_some() {
                Self::dfs(&n.right, nums);
            }
        }
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
var leafSimilar = function (root1, root2) {
    const l1 = [];
    const l2 = [];
    const dfs = (root, nums) => {
        if (root.left === root.right) {
            nums.push(root.val);
            return;
        }
        root.left && dfs(root.left, nums);
        root.right && dfs(root.right, nums);
    };
    dfs(root1, l1);
    dfs(root2, l2);
    return l1.join(',') === l2.join(',');
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>请考虑一棵二叉树上所有的叶子，这些叶子的值按从左到右的顺序排列形成一个&nbsp;<strong>叶值序列 </strong>。</p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0800-0899/0872.Leaf-Similar%20Trees/images/tree.png" style="height: 336px; width: 400px;" /></p>

<p>举个例子，如上图所示，给定一棵叶值序列为&nbsp;<code>(6, 7, 4, 9, 8)</code>&nbsp;的树。</p>

<p>如果有两棵二叉树的叶值序列是相同，那么我们就认为它们是&nbsp;<em>叶相似&nbsp;</em>的。</p>

<p>如果给定的两个根结点分别为&nbsp;<code>root1</code> 和&nbsp;<code>root2</code>&nbsp;的树是叶相似的，则返回&nbsp;<code>true</code>；否则返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0800-0899/0872.Leaf-Similar%20Trees/images/leaf-similar-1.jpg" style="height: 237px; width: 600px;" /></p>

<pre>
<strong>输入：</strong>root1 = [3,5,1,6,2,9,8,null,null,7,4], root2 = [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]
<strong>输出：</strong>true
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0800-0899/0872.Leaf-Similar%20Trees/images/leaf-similar-2.jpg" style="height: 110px; width: 300px;" /></p>

<pre>
<strong>输入：</strong>root1 = [1,2,3], root2 = [1,3,2]
<strong>输出：</strong>false
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>给定的两棵树结点数在&nbsp;<code>[1, 200]</code> 范围内</li>
	<li>给定的两棵树上的值在&nbsp;<code>[0, 200]</code> 范围内</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS

我们可以使用深度优先搜索来遍历两棵树的叶子节点，分别将叶子节点的值存储在两个列表 $l_1$ 和 $l_2$ 中，最后比较两个列表是否相等。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为树的节点数。

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
    def leafSimilar(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        def dfs(root: Optional[TreeNode], nums: List[int]) -> None:
            if root.left == root.right:
                nums.append(root.val)
                return
            if root.left:
                dfs(root.left, nums)
            if root.right:
                dfs(root.right, nums)

        l1, l2 = [], []
        dfs(root1, l1)
        dfs(root2, l2)
        return l1 == l2
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
    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        List<Integer> l1 = new ArrayList<>();
        List<Integer> l2 = new ArrayList<>();
        dfs(root1, l1);
        dfs(root2, l2);
        return l1.equals(l2);
    }

    private void dfs(TreeNode root, List<Integer> nums) {
        if (root.left == root.right) {
            nums.add(root.val);
            return;
        }
        if (root.left != null) {
            dfs(root.left, nums);
        }
        if (root.right != null) {
            dfs(root.right, nums);
        }
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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> l1, l2;
        dfs(root1, l1);
        dfs(root2, l2);
        return l1 == l2;
    }

    void dfs(TreeNode* root, vector<int>& nums) {
        if (root->left == root->right) {
            nums.push_back(root->val);
            return;
        }
        if (root->left) {
            dfs(root->left, nums);
        }
        if (root->right) {
            dfs(root->right, nums);
        }
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
func leafSimilar(root1 *TreeNode, root2 *TreeNode) bool {
	l1, l2 := []int{}, []int{}
	var dfs func(*TreeNode, *[]int)
	dfs = func(root *TreeNode, nums *[]int) {
		if root.Left == root.Right {
			*nums = append(*nums, root.Val)
			return
		}
		if root.Left != nil {
			dfs(root.Left, nums)
		}
		if root.Right != nil {
			dfs(root.Right, nums)
		}
	}
	dfs(root1, &l1)
	dfs(root2, &l2)
	return reflect.DeepEqual(l1, l2)
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
use std::rc::Rc;
impl Solution {
    pub fn leaf_similar(
        root1: Option<Rc<RefCell<TreeNode>>>,
        root2: Option<Rc<RefCell<TreeNode>>>,
    ) -> bool {
        let mut l1 = Vec::new();
        let mut l2 = Vec::new();
        Self::dfs(&root1, &mut l1);
        Self::dfs(&root2, &mut l2);
        l1 == l2
    }

    fn dfs(node: &Option<Rc<RefCell<TreeNode>>>, nums: &mut Vec<i32>) {
        if let Some(n) = node {
            let n = n.borrow();
            if n.left.is_none() && n.right.is_none() {
                nums.push(n.val);
                return;
            }
            if n.left.is_some() {
                Self::dfs(&n.left, nums);
            }
            if n.right.is_some() {
                Self::dfs(&n.right, nums);
            }
        }
    }
}
```

#### JavaScript

```js
var leafSimilar = function (root1, root2) {
    const l1 = [];
    const l2 = [];
    const dfs = (root, nums) => {
        if (root.left === root.right) {
            nums.push(root.val);
            return;
        }
        root.left && dfs(root.left, nums);
        root.right && dfs(root.right, nums);
    };
    dfs(root1, l1);
    dfs(root2, l2);
    return l1.join(',') === l2.join(',');
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [873. 最长的斐波那契子序列的长度](https://leetcode.cn/problems/length-of-longest-fibonacci-subsequence){#873}

{{< tabs "873" >}}

{{% tab "python" %}}
```python
class Solution:
    def lenLongestFibSubseq(self, arr: List[int]) -> int:
        n = len(arr)
        f = [[0] * n for _ in range(n)]
        d = {x: i for i, x in enumerate(arr)}
        for i in range(n):
            for j in range(i):
                f[i][j] = 2
        ans = 0
        for i in range(2, n):
            for j in range(1, i):
                t = arr[i] - arr[j]
                if t in d and (k := d[t]) < j:
                    f[i][j] = max(f[i][j], f[j][k] + 1)
                    ans = max(ans, f[i][j])
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int lenLongestFibSubseq(int[] arr) {
        int n = arr.length;
        int[][] f = new int[n][n];
        Map<Integer, Integer> d = new HashMap<>();
        for (int i = 0; i < n; ++i) {
            d.put(arr[i], i);
            for (int j = 0; j < i; ++j) {
                f[i][j] = 2;
            }
        }
        int ans = 0;
        for (int i = 2; i < n; ++i) {
            for (int j = 1; j < i; ++j) {
                int t = arr[i] - arr[j];
                Integer k = d.get(t);
                if (k != null && k < j) {
                    f[i][j] = Math.max(f[i][j], f[j][k] + 1);
                    ans = Math.max(ans, f[i][j]);
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
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        int f[n][n];
        memset(f, 0, sizeof(f));
        unordered_map<int, int> d;
        for (int i = 0; i < n; ++i) {
            d[arr[i]] = i;
            for (int j = 0; j < i; ++j) {
                f[i][j] = 2;
            }
        }

        int ans = 0;
        for (int i = 2; i < n; ++i) {
            for (int j = 1; j < i; ++j) {
                int t = arr[i] - arr[j];
                auto it = d.find(t);
                if (it != d.end() && it->second < j) {
                    int k = it->second;
                    f[i][j] = max(f[i][j], f[j][k] + 1);
                    ans = max(ans, f[i][j]);
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
func lenLongestFibSubseq(arr []int) (ans int) {
	n := len(arr)
	f := make([][]int, n)
	for i := range f {
		f[i] = make([]int, n)
	}

	d := make(map[int]int)
	for i, x := range arr {
		d[x] = i
		for j := 0; j < i; j++ {
			f[i][j] = 2
		}
	}

	for i := 2; i < n; i++ {
		for j := 1; j < i; j++ {
			t := arr[i] - arr[j]
			if k, ok := d[t]; ok && k < j {
				f[i][j] = max(f[i][j], f[j][k]+1)
				ans = max(ans, f[i][j])
			}
		}
	}

	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function lenLongestFibSubseq(arr: number[]): number {
    const n = arr.length;
    const f: number[][] = Array.from({ length: n }, () => Array(n).fill(0));
    const d: Map<number, number> = new Map();
    for (let i = 0; i < n; ++i) {
        d.set(arr[i], i);
        for (let j = 0; j < i; ++j) {
            f[i][j] = 2;
        }
    }
    let ans = 0;
    for (let i = 2; i < n; ++i) {
        for (let j = 1; j < i; ++j) {
            const t = arr[i] - arr[j];
            const k = d.get(t);
            if (k !== undefined && k < j) {
                f[i][j] = Math.max(f[i][j], f[j][k] + 1);
                ans = Math.max(ans, f[i][j]);
            }
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashMap;
impl Solution {
    pub fn len_longest_fib_subseq(arr: Vec<i32>) -> i32 {
        let n = arr.len();
        let mut f = vec![vec![0; n]; n];
        let mut d = HashMap::new();
        for i in 0..n {
            d.insert(arr[i], i);
            for j in 0..i {
                f[i][j] = 2;
            }
        }
        let mut ans = 0;
        for i in 2..n {
            for j in 1..i {
                let t = arr[i] - arr[j];
                if let Some(&k) = d.get(&t) {
                    if k < j {
                        f[i][j] = f[i][j].max(f[j][k] + 1);
                        ans = ans.max(f[i][j]);
                    }
                }
            }
        }
        ans
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} arr
 * @return {number}
 */
var lenLongestFibSubseq = function (arr) {
    const n = arr.length;
    const f = Array.from({ length: n }, () => Array(n).fill(0));
    const d = new Map();
    for (let i = 0; i < n; ++i) {
        d.set(arr[i], i);
        for (let j = 0; j < i; ++j) {
            f[i][j] = 2;
        }
    }
    let ans = 0;
    for (let i = 2; i < n; ++i) {
        for (let j = 1; j < i; ++j) {
            const t = arr[i] - arr[j];
            const k = d.get(t);
            if (k !== undefined && k < j) {
                f[i][j] = Math.max(f[i][j], f[j][k] + 1);
                ans = Math.max(ans, f[i][j]);
            }
        }
    }
    return ans;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>如果序列&nbsp;<code>x<sub>1</sub>, x<sub>2</sub>, ..., x<sub>n</sub></code>&nbsp;满足下列条件，就说它是&nbsp;<em>斐波那契式&nbsp;</em>的：</p>

<ul>
	<li><code>n &gt;= 3</code></li>
	<li>对于所有&nbsp;<code>i + 2 &lt;= n</code>，都有&nbsp;<code>x<sub>i</sub>&nbsp;+ x<sub>i+1</sub>&nbsp;== x<sub>i+2</sub></code></li>
</ul>

<p>给定一个&nbsp;<strong>严格递增&nbsp;</strong>的正整数数组形成序列 <code>arr</code>&nbsp;，找到 <code><font color="#c7254e"><font face="Menlo, Monaco, Consolas, Courier New, monospace"><span style="font-size:12.600000381469727px"><span style="caret-color:#c7254e"><span style="background-color:#f9f2f4">arr</span></span></span></font></font></code>&nbsp;中最长的斐波那契式的子序列的长度。如果不存在，返回&nbsp;&nbsp;<code>0</code> 。</p>

<p><strong>子序列</strong> 是通过从另一个序列 <code>arr</code> 中删除任意数量的元素（包括删除 0 个元素）得到的，同时不改变剩余元素顺序。例如，<code>[3, 5, 8]</code> 是 <code>[3, 4, 5, 6, 7, 8]</code>&nbsp;的子序列。</p>

<p>&nbsp;</p>

<ul>
</ul>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入: </strong>arr =<strong> </strong>[1,2,3,4,5,6,7,8]
<strong>输出: </strong>5
<strong>解释: </strong>最长的斐波那契式子序列为 [1,2,3,5,8] 。
</pre>

<p><strong>示例&nbsp;2：</strong></p>

<pre>
<strong>输入: </strong>arr =<strong> </strong>[1,3,7,11,12,14,18]
<strong>输出: </strong>3
<strong>解释</strong>: 最长的斐波那契式子序列有 [1,11,12]、[3,11,14] 以及 [7,11,18] 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= arr.length &lt;= 1000</code></li>
	<li>
	<p><code>1 &lt;= arr[i] &lt; arr[i + 1] &lt;= 10<sup>9</sup></code></p>
	</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i][j]$ 表示以 $\textit{arr}[i]$ 作为最后一个元素，以 $\textit{arr}[j]$ 作为倒数第二个元素的最长斐波那契子序列的长度。初始时，对于任意的 $i \in [0, n)$ 和 $j \in [0, i)$，都有 $f[i][j] = 2$。其余的元素都是 $0$。

我们用一个哈希表 $d$ 记录数组 $\textit{arr}$ 中每个元素对应的下标。

然后，我们可以枚举 $\textit{arr}[i]$ 和 $\textit{arr}[j]$，其中 $i \in [2, n)$ 且 $j \in [1, i)$。假设当前枚举到的元素是 $\textit{arr}[i]$ 和 $\textit{arr}[j]$，我们可以得到 $\textit{arr}[i] - \textit{arr}[j]$，记作 $t$。如果 $t$ 在数组 $\textit{arr}$ 中，且 $t$ 的下标 $k$ 满足 $k < j$，那么我们可以得到一个以 $\textit{arr}[j]$ 和 $\textit{arr}[i]$ 作为最后两个元素的斐波那契子序列，其长度为 $f[i][j] = \max(f[i][j], f[j][k] + 1)$。我们可以用这种方法不断更新 $f[i][j]$ 的值，然后更新答案。

枚举结束后，返回答案即可。

时间复杂度 $O(n^2)$，空间复杂度 $O(n^2)$。其中 $n$ 是数组 $\textit{arr}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def lenLongestFibSubseq(self, arr: List[int]) -> int:
        n = len(arr)
        f = [[0] * n for _ in range(n)]
        d = {x: i for i, x in enumerate(arr)}
        for i in range(n):
            for j in range(i):
                f[i][j] = 2
        ans = 0
        for i in range(2, n):
            for j in range(1, i):
                t = arr[i] - arr[j]
                if t in d and (k := d[t]) < j:
                    f[i][j] = max(f[i][j], f[j][k] + 1)
                    ans = max(ans, f[i][j])
        return ans
```

#### Java

```java
class Solution {
    public int lenLongestFibSubseq(int[] arr) {
        int n = arr.length;
        int[][] f = new int[n][n];
        Map<Integer, Integer> d = new HashMap<>();
        for (int i = 0; i < n; ++i) {
            d.put(arr[i], i);
            for (int j = 0; j < i; ++j) {
                f[i][j] = 2;
            }
        }
        int ans = 0;
        for (int i = 2; i < n; ++i) {
            for (int j = 1; j < i; ++j) {
                int t = arr[i] - arr[j];
                Integer k = d.get(t);
                if (k != null && k < j) {
                    f[i][j] = Math.max(f[i][j], f[j][k] + 1);
                    ans = Math.max(ans, f[i][j]);
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
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        int f[n][n];
        memset(f, 0, sizeof(f));
        unordered_map<int, int> d;
        for (int i = 0; i < n; ++i) {
            d[arr[i]] = i;
            for (int j = 0; j < i; ++j) {
                f[i][j] = 2;
            }
        }

        int ans = 0;
        for (int i = 2; i < n; ++i) {
            for (int j = 1; j < i; ++j) {
                int t = arr[i] - arr[j];
                auto it = d.find(t);
                if (it != d.end() && it->second < j) {
                    int k = it->second;
                    f[i][j] = max(f[i][j], f[j][k] + 1);
                    ans = max(ans, f[i][j]);
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func lenLongestFibSubseq(arr []int) (ans int) {
	n := len(arr)
	f := make([][]int, n)
	for i := range f {
		f[i] = make([]int, n)
	}

	d := make(map[int]int)
	for i, x := range arr {
		d[x] = i
		for j := 0; j < i; j++ {
			f[i][j] = 2
		}
	}

	for i := 2; i < n; i++ {
		for j := 1; j < i; j++ {
			t := arr[i] - arr[j]
			if k, ok := d[t]; ok && k < j {
				f[i][j] = max(f[i][j], f[j][k]+1)
				ans = max(ans, f[i][j])
			}
		}
	}

	return
}
```

#### TypeScript

```ts
function lenLongestFibSubseq(arr: number[]): number {
    const n = arr.length;
    const f: number[][] = Array.from({ length: n }, () => Array(n).fill(0));
    const d: Map<number, number> = new Map();
    for (let i = 0; i < n; ++i) {
        d.set(arr[i], i);
        for (let j = 0; j < i; ++j) {
            f[i][j] = 2;
        }
    }
    let ans = 0;
    for (let i = 2; i < n; ++i) {
        for (let j = 1; j < i; ++j) {
            const t = arr[i] - arr[j];
            const k = d.get(t);
            if (k !== undefined && k < j) {
                f[i][j] = Math.max(f[i][j], f[j][k] + 1);
                ans = Math.max(ans, f[i][j]);
            }
        }
    }
    return ans;
}
```

#### Rust

```rust
use std::collections::HashMap;
impl Solution {
    pub fn len_longest_fib_subseq(arr: Vec<i32>) -> i32 {
        let n = arr.len();
        let mut f = vec![vec![0; n]; n];
        let mut d = HashMap::new();
        for i in 0..n {
            d.insert(arr[i], i);
            for j in 0..i {
                f[i][j] = 2;
            }
        }
        let mut ans = 0;
        for i in 2..n {
            for j in 1..i {
                let t = arr[i] - arr[j];
                if let Some(&k) = d.get(&t) {
                    if k < j {
                        f[i][j] = f[i][j].max(f[j][k] + 1);
                        ans = ans.max(f[i][j]);
                    }
                }
            }
        }
        ans
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} arr
 * @return {number}
 */
var lenLongestFibSubseq = function (arr) {
    const n = arr.length;
    const f = Array.from({ length: n }, () => Array(n).fill(0));
    const d = new Map();
    for (let i = 0; i < n; ++i) {
        d.set(arr[i], i);
        for (let j = 0; j < i; ++j) {
            f[i][j] = 2;
        }
    }
    let ans = 0;
    for (let i = 2; i < n; ++i) {
        for (let j = 1; j < i; ++j) {
            const t = arr[i] - arr[j];
            const k = d.get(t);
            if (k !== undefined && k < j) {
                f[i][j] = Math.max(f[i][j], f[j][k] + 1);
                ans = Math.max(ans, f[i][j]);
            }
        }
    }
    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [874. 模拟行走机器人](https://leetcode.cn/problems/walking-robot-simulation){#874}

{{< tabs "874" >}}

{{% tab "python" %}}
```python
class Solution:
    def robotSim(self, commands: List[int], obstacles: List[List[int]]) -> int:
        dirs = (0, 1, 0, -1, 0)
        s = {(x, y) for x, y in obstacles}
        ans = k = 0
        x = y = 0
        for c in commands:
            if c == -2:
                k = (k + 3) % 4
            elif c == -1:
                k = (k + 1) % 4
            else:
                for _ in range(c):
                    nx, ny = x + dirs[k], y + dirs[k + 1]
                    if (nx, ny) in s:
                        break
                    x, y = nx, ny
                    ans = max(ans, x * x + y * y)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int robotSim(int[] commands, int[][] obstacles) {
        int[] dirs = {0, 1, 0, -1, 0};
        Set<Integer> s = new HashSet<>(obstacles.length);
        for (var e : obstacles) {
            s.add(f(e[0], e[1]));
        }
        int ans = 0, k = 0;
        int x = 0, y = 0;
        for (int c : commands) {
            if (c == -2) {
                k = (k + 3) % 4;
            } else if (c == -1) {
                k = (k + 1) % 4;
            } else {
                while (c-- > 0) {
                    int nx = x + dirs[k], ny = y + dirs[k + 1];
                    if (s.contains(f(nx, ny))) {
                        break;
                    }
                    x = nx;
                    y = ny;
                    ans = Math.max(ans, x * x + y * y);
                }
            }
        }
        return ans;
    }

    private int f(int x, int y) {
        return x * 60010 + y;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int dirs[5] = {0, 1, 0, -1, 0};
        auto f = [](int x, int y) {
            return x * 60010 + y;
        };
        unordered_set<int> s;
        for (auto& e : obstacles) {
            s.insert(f(e[0], e[1]));
        }
        int ans = 0, k = 0;
        int x = 0, y = 0;
        for (int c : commands) {
            if (c == -2) {
                k = (k + 3) % 4;
            } else if (c == -1) {
                k = (k + 1) % 4;
            } else {
                while (c--) {
                    int nx = x + dirs[k], ny = y + dirs[k + 1];
                    if (s.count(f(nx, ny))) {
                        break;
                    }
                    x = nx;
                    y = ny;
                    ans = max(ans, x * x + y * y);
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
func robotSim(commands []int, obstacles [][]int) (ans int) {
	dirs := [5]int{0, 1, 0, -1, 0}
	type pair struct{ x, y int }
	s := map[pair]bool{}
	for _, e := range obstacles {
		s[pair{e[0], e[1]}] = true
	}
	var x, y, k int
	for _, c := range commands {
		if c == -2 {
			k = (k + 3) % 4
		} else if c == -1 {
			k = (k + 1) % 4
		} else {
			for ; c > 0 && !s[pair{x + dirs[k], y + dirs[k+1]}]; c-- {
				x += dirs[k]
				y += dirs[k+1]
				ans = max(ans, x*x+y*y)
			}
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function robotSim(commands: number[], obstacles: number[][]): number {
    const dirs = [0, 1, 0, -1, 0];
    const s: Set<number> = new Set();
    const f = (x: number, y: number) => x * 60010 + y;
    for (const [x, y] of obstacles) {
        s.add(f(x, y));
    }
    let [ans, x, y, k] = [0, 0, 0, 0];
    for (let c of commands) {
        if (c === -2) {
            k = (k + 3) % 4;
        } else if (c === -1) {
            k = (k + 1) % 4;
        } else {
            while (c-- > 0) {
                const [nx, ny] = [x + dirs[k], y + dirs[k + 1]];
                if (s.has(f(nx, ny))) {
                    break;
                }
                [x, y] = [nx, ny];
                ans = Math.max(ans, x * x + y * y);
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

<p>机器人在一个无限大小的 XY 网格平面上行走，从点&nbsp;<code>(0, 0)</code> 处开始出发，面向北方。该机器人可以接收以下三种类型的命令 <code>commands</code> ：</p>

<ul>
	<li><code>-2</code> ：向左转&nbsp;<code>90</code> 度</li>
	<li><code>-1</code> ：向右转 <code>90</code> 度</li>
	<li><code>1 &lt;= x &lt;= 9</code> ：向前移动&nbsp;<code>x</code>&nbsp;个单位长度</li>
</ul>

<p>在网格上有一些格子被视为障碍物&nbsp;<code>obstacles</code> 。第 <code>i</code>&nbsp;个障碍物位于网格点 &nbsp;<code>obstacles[i] = (x<sub>i</sub>, y<sub>i</sub>)</code> 。</p>

<p>机器人无法走到障碍物上，它将会停留在障碍物的前一个网格方块上，并继续执行下一个命令。</p>

<p>返回机器人距离原点的 <strong>最大欧式距离</strong> 的 <strong>平方</strong> 。（即，如果距离为 <code>5</code> ，则返回 <code>25</code> ）</p>

<div class="d-google dictRoot saladict-panel isAnimate">
<div>
<div class="MachineTrans-Text">
<div class="MachineTrans-Lines">
<div class="MachineTrans-Lines-collapse MachineTrans-lang-en">&nbsp;</div>
</div>

<div class="MachineTrans-Lines">
<p class="MachineTrans-lang-zh-CN"><strong>注意：</strong></p>

<ul>
	<li class="MachineTrans-lang-zh-CN">北方表示 +Y 方向。</li>
	<li class="MachineTrans-lang-zh-CN">东方表示 +X 方向。</li>
	<li class="MachineTrans-lang-zh-CN">南方表示 -Y 方向。</li>
	<li class="MachineTrans-lang-zh-CN">西方表示 -X 方向。</li>
	<li class="MachineTrans-lang-zh-CN">原点 [0,0] 可能会有障碍物。</li>
</ul>
</div>
</div>
</div>
</div>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>commands = [4,-1,3], obstacles = []
<strong>输出：</strong>25
<strong>解释：
</strong>机器人开始位于 (0, 0)：
1. 向北移动 4 个单位，到达 (0, 4)
2. 右转
3. 向东移动 3 个单位，到达 (3, 4)
距离原点最远的是 (3, 4) ，距离为 3<sup>2</sup> + 4<sup>2</sup> = 25</pre>

<p><strong>示例&nbsp;2：</strong></p>

<pre>
<strong>输入：</strong>commands = [4,-1,4,-2,4], obstacles = [[2,4]]
<strong>输出：</strong>65
<strong>解释</strong>：机器人开始位于 (0, 0)：
1. 向北移动 4 个单位，到达 (0, 4)
2. 右转
3. 向东移动 1 个单位，然后被位于 (2, 4) 的障碍物阻挡，机器人停在 (1, 4)
4. 左转
5. 向北走 4 个单位，到达 (1, 8)
距离原点最远的是 (1, 8) ，距离为 1<sup>2</sup> + 8<sup>2</sup> = 65</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>commands = [6,-1,-1,6], obstacles = []
<b>输出：</b>36
<b>解释：</b>机器人开始位于 (0, 0):
1. 向北移动 6 个单位，到达 (0, 6).
2. 右转
3. 右转
4. 向南移动 6 个单位，到达 (0, 0).
机器人距离原点最远的点是 (0, 6)，其距离的平方是 6<sup>2</sup> = 36 个单位。</pre>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= commands.length &lt;= 10<sup>4</sup></code></li>
	<li><code>commands[i]</code> 的值可以取 <code>-2</code>、<code>-1</code> 或者是范围 <code>[1, 9]</code> 内的一个整数。</li>
	<li><code>0 &lt;= obstacles.length &lt;= 10<sup>4</sup></code></li>
	<li><code>-3 * 10<sup>4</sup> &lt;= x<sub>i</sub>, y<sub>i</sub> &lt;= 3 * 10<sup>4</sup></code></li>
	<li>答案保证小于 <code>2<sup>31</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 模拟

我们定义一个长度为 $5$ 的方向数组 $dirs=[0, 1, 0, -1, 0]$，数组中的相邻两个元素表示一个方向。即 $(dirs[0], dirs[1])$ 表示向北，而 $(dirs[1], dirs[2])$ 表示向东，以此类推。

我们使用一个哈希表 $s$ 来存储所有障碍物的坐标，这样可以在 $O(1)$ 的时间内判断下一步是否会遇到障碍物。

另外，使用两个变量 $x$ 和 $y$ 来表示机器人当前所在的坐标，初始时 $x = y = 0$。变量 $k$ 表示机器人当前的方向，答案变量 $ans$ 表示机器人距离原点的最大欧式距离的平方。

接下来，我们遍历数组 $commands$ 中的每个元素 $c$：

-   如果 $c = -2$，表示机器人向左转 $90$ 度，即 $k = (k + 3) \bmod 4$；
-   如果 $c = -1$，表示机器人向右转 $90$ 度，即 $k = (k + 1) \bmod 4$；
-   否则，表示机器人向前移动 $c$ 个单位长度。我们将机器人当前的方向 $k$ 与方向数组 $dirs$ 结合，即可得到机器人在 $x$ 轴和 $y$ 轴上的增量。我们将 $c$ 个单位长度的增量分别累加到 $x$ 和 $y$ 上，并判断每次移动后的新坐标 $(nx, ny)$ 是否在障碍物的坐标中，如果不在，则更新答案 $ans$，否则停止模拟，进行下一条指令的模拟。

最后返回答案 $ans$ 即可。

时间复杂度 $O(C \times n + m)$，空间复杂度 $O(m)$。其中 $C$ 表示每次可以移动的最大步数，而 $n$ 和 $m$ 分别表示数组 $commands$ 和数组 $obstacles$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def robotSim(self, commands: List[int], obstacles: List[List[int]]) -> int:
        dirs = (0, 1, 0, -1, 0)
        s = {(x, y) for x, y in obstacles}
        ans = k = 0
        x = y = 0
        for c in commands:
            if c == -2:
                k = (k + 3) % 4
            elif c == -1:
                k = (k + 1) % 4
            else:
                for _ in range(c):
                    nx, ny = x + dirs[k], y + dirs[k + 1]
                    if (nx, ny) in s:
                        break
                    x, y = nx, ny
                    ans = max(ans, x * x + y * y)
        return ans
```

#### Java

```java
class Solution {
    public int robotSim(int[] commands, int[][] obstacles) {
        int[] dirs = {0, 1, 0, -1, 0};
        Set<Integer> s = new HashSet<>(obstacles.length);
        for (var e : obstacles) {
            s.add(f(e[0], e[1]));
        }
        int ans = 0, k = 0;
        int x = 0, y = 0;
        for (int c : commands) {
            if (c == -2) {
                k = (k + 3) % 4;
            } else if (c == -1) {
                k = (k + 1) % 4;
            } else {
                while (c-- > 0) {
                    int nx = x + dirs[k], ny = y + dirs[k + 1];
                    if (s.contains(f(nx, ny))) {
                        break;
                    }
                    x = nx;
                    y = ny;
                    ans = Math.max(ans, x * x + y * y);
                }
            }
        }
        return ans;
    }

    private int f(int x, int y) {
        return x * 60010 + y;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int dirs[5] = {0, 1, 0, -1, 0};
        auto f = [](int x, int y) {
            return x * 60010 + y;
        };
        unordered_set<int> s;
        for (auto& e : obstacles) {
            s.insert(f(e[0], e[1]));
        }
        int ans = 0, k = 0;
        int x = 0, y = 0;
        for (int c : commands) {
            if (c == -2) {
                k = (k + 3) % 4;
            } else if (c == -1) {
                k = (k + 1) % 4;
            } else {
                while (c--) {
                    int nx = x + dirs[k], ny = y + dirs[k + 1];
                    if (s.count(f(nx, ny))) {
                        break;
                    }
                    x = nx;
                    y = ny;
                    ans = max(ans, x * x + y * y);
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func robotSim(commands []int, obstacles [][]int) (ans int) {
	dirs := [5]int{0, 1, 0, -1, 0}
	type pair struct{ x, y int }
	s := map[pair]bool{}
	for _, e := range obstacles {
		s[pair{e[0], e[1]}] = true
	}
	var x, y, k int
	for _, c := range commands {
		if c == -2 {
			k = (k + 3) % 4
		} else if c == -1 {
			k = (k + 1) % 4
		} else {
			for ; c > 0 && !s[pair{x + dirs[k], y + dirs[k+1]}]; c-- {
				x += dirs[k]
				y += dirs[k+1]
				ans = max(ans, x*x+y*y)
			}
		}
	}
	return
}
```

#### TypeScript

```ts
function robotSim(commands: number[], obstacles: number[][]): number {
    const dirs = [0, 1, 0, -1, 0];
    const s: Set<number> = new Set();
    const f = (x: number, y: number) => x * 60010 + y;
    for (const [x, y] of obstacles) {
        s.add(f(x, y));
    }
    let [ans, x, y, k] = [0, 0, 0, 0];
    for (let c of commands) {
        if (c === -2) {
            k = (k + 3) % 4;
        } else if (c === -1) {
            k = (k + 1) % 4;
        } else {
            while (c-- > 0) {
                const [nx, ny] = [x + dirs[k], y + dirs[k + 1]];
                if (s.has(f(nx, ny))) {
                    break;
                }
                [x, y] = [nx, ny];
                ans = Math.max(ans, x * x + y * y);
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

# [875. 爱吃香蕉的珂珂](https://leetcode.cn/problems/koko-eating-bananas){#875}

{{< tabs "875" >}}

{{% tab "python" %}}
```python
class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        def check(k: int) -> bool:
            return sum((x + k - 1) // k for x in piles) <= h

        return 1 + bisect_left(range(1, max(piles) + 1), True, key=check)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        int l = 1, r = (int) 1e9;
        while (l < r) {
            int mid = (l + r) >> 1;
            int s = 0;
            for (int x : piles) {
                s += (x + mid - 1) / mid;
            }
            if (s <= h) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = ranges::max(piles);
        while (l < r) {
            int mid = (l + r) >> 1;
            int s = 0;
            for (int x : piles) {
                s += (x + mid - 1) / mid;
            }
            if (s <= h) {
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
func minEatingSpeed(piles []int, h int) int {
	return 1 + sort.Search(slices.Max(piles), func(k int) bool {
		k++
		s := 0
		for _, x := range piles {
			s += (x + k - 1) / k
		}
		return s <= h
	})
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minEatingSpeed(piles: number[], h: number): number {
    let [l, r] = [1, Math.max(...piles)];
    while (l < r) {
        const mid = (l + r) >> 1;
        const s = piles.map(x => Math.ceil(x / mid)).reduce((a, b) => a + b);
        if (s <= h) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn min_eating_speed(piles: Vec<i32>, h: i32) -> i32 {
        let mut l = 1;
        let mut r = *piles.iter().max().unwrap_or(&0);
        while l < r {
            let mid = (l + r) >> 1;
            let mut s = 0;
            for x in piles.iter() {
                s += (x + mid - 1) / mid;
            }
            if s <= h {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        l
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int MinEatingSpeed(int[] piles, int h) {
        int l = 1, r = (int) 1e9;
        while (l < r) {
            int mid = (l + r) >> 1;
            int s = 0;
            foreach (int x in piles) {
                s += (x + mid - 1) / mid;
            }
            if (s <= h) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>珂珂喜欢吃香蕉。这里有 <code>n</code> 堆香蕉，第 <code>i</code> 堆中有&nbsp;<code>piles[i]</code>&nbsp;根香蕉。警卫已经离开了，将在 <code>h</code> 小时后回来。</p>

<p>珂珂可以决定她吃香蕉的速度 <code>k</code> （单位：根/小时）。每个小时，她将会选择一堆香蕉，从中吃掉 <code>k</code> 根。如果这堆香蕉少于 <code>k</code> 根，她将吃掉这堆的所有香蕉，然后这一小时内不会再吃更多的香蕉。&nbsp;&nbsp;</p>

<p>珂珂喜欢慢慢吃，但仍然想在警卫回来前吃掉所有的香蕉。</p>

<p>返回她可以在 <code>h</code> 小时内吃掉所有香蕉的最小速度 <code>k</code>（<code>k</code> 为整数）。</p>

<p>&nbsp;</p>

<ul>
</ul>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>piles = [3,6,7,11], h = 8
<strong>输出：</strong>4
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>piles = [30,11,23,4,20], h = 5
<strong>输出：</strong>30
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>piles = [30,11,23,4,20], h = 6
<strong>输出：</strong>23
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= piles.length &lt;= 10<sup>4</sup></code></li>
	<li><code>piles.length &lt;= h &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= piles[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二分查找

我们注意到，如果珂珂能够以 $k$ 的速度在 $h$ 小时内吃完所有香蕉，那么她也可以以 $k' > k$ 的速度在 $h$ 小时内吃完所有香蕉。这存在着单调性，因此我们可以使用二分查找，找到最小的满足条件的 $k$。

我们定义二分查找的左边界 $l = 1$，右边界 $r = \max(\textit{piles})$。每一次二分，我们取中间值 $mid = \frac{l + r}{2}$，然后计算以 $mid$ 的速度吃香蕉需要的时间 $s$。如果 $s \leq h$，说明 $mid$ 的速度可以满足条件，我们将右边界 $r$ 更新为 $mid$；否则，我们将左边界 $l$ 更新为 $mid + 1$。最终，当 $l = r$ 时，我们找到了最小的满足条件的 $k$。

时间复杂度 $O(n \times \log M)$，其中 $n$ 和 $M$ 分别是数组 `piles` 的长度和最大值。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        def check(k: int) -> bool:
            return sum((x + k - 1) // k for x in piles) <= h

        return 1 + bisect_left(range(1, max(piles) + 1), True, key=check)
```

#### Java

```java
class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        int l = 1, r = (int) 1e9;
        while (l < r) {
            int mid = (l + r) >> 1;
            int s = 0;
            for (int x : piles) {
                s += (x + mid - 1) / mid;
            }
            if (s <= h) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = ranges::max(piles);
        while (l < r) {
            int mid = (l + r) >> 1;
            int s = 0;
            for (int x : piles) {
                s += (x + mid - 1) / mid;
            }
            if (s <= h) {
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
func minEatingSpeed(piles []int, h int) int {
	return 1 + sort.Search(slices.Max(piles), func(k int) bool {
		k++
		s := 0
		for _, x := range piles {
			s += (x + k - 1) / k
		}
		return s <= h
	})
}
```

#### TypeScript

```ts
function minEatingSpeed(piles: number[], h: number): number {
    let [l, r] = [1, Math.max(...piles)];
    while (l < r) {
        const mid = (l + r) >> 1;
        const s = piles.map(x => Math.ceil(x / mid)).reduce((a, b) => a + b);
        if (s <= h) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}
```

#### Rust

```rust
impl Solution {
    pub fn min_eating_speed(piles: Vec<i32>, h: i32) -> i32 {
        let mut l = 1;
        let mut r = *piles.iter().max().unwrap_or(&0);
        while l < r {
            let mid = (l + r) >> 1;
            let mut s = 0;
            for x in piles.iter() {
                s += (x + mid - 1) / mid;
            }
            if s <= h {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        l
    }
}
```

#### C#

```cs
public class Solution {
    public int MinEatingSpeed(int[] piles, int h) {
        int l = 1, r = (int) 1e9;
        while (l < r) {
            int mid = (l + r) >> 1;
            int s = 0;
            foreach (int x in piles) {
                s += (x + mid - 1) / mid;
            }
            if (s <= h) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [876. 链表的中间结点](https://leetcode.cn/problems/middle-of-the-linked-list){#876}

{{< tabs "876" >}}

{{% tab "python" %}}
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        slow = fast = head
        while fast and fast.next:
            slow, fast = slow.next, fast.next.next
        return slow
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
    public ListNode middleNode(ListNode head) {
        ListNode slow = head, fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
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
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
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
func middleNode(head *ListNode) *ListNode {
	slow, fast := head, head
	for fast != nil && fast.Next != nil {
		slow, fast = slow.Next, fast.Next.Next
	}
	return slow
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

function middleNode(head: ListNode | null): ListNode | null {
    let fast = head,
        slow = head;
    while (fast != null && fast.next != null) {
        fast = fast.next.next;
        slow = slow.next;
    }
    return slow;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
//
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
    pub fn middle_node(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut slow = &head;
        let mut fast = &head;
        while fast.is_some() && fast.as_ref().unwrap().next.is_some() {
            slow = &slow.as_ref().unwrap().next;
            fast = &fast.as_ref().unwrap().next.as_ref().unwrap().next;
        }
        slow.clone()
    }
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
/**
 * Definition for a singly-linked list.
 * class ListNode {
 *     public $val = 0;
 *     public $next = null;
 *     function __construct($val = 0, $next = null) {
 *         $this->val = $val;
 *         $this->next = $next;
 *     }
 * }
 */
class Solution {
    /**
     * @param ListNode $head
     * @return ListNode
     */
    function middleNode($head) {
        $count = 0;
        $tmpHead = $head;
        while ($tmpHead != null) {
            $tmpHead = $tmpHead->next;
            $count++;
        }
        $len = $count - floor($count / 2);
        while ($count != $len) {
            $head = $head->next;
            $count--;
        }
        return $head;
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你单链表的头结点 <code>head</code> ，请你找出并返回链表的中间结点。</p>

<p>如果有两个中间结点，则返回第二个中间结点。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0800-0899/0876.Middle%20of%20the%20Linked%20List/images/lc-midlist1.jpg" style="width: 544px; height: 65px;" />
<pre>
<strong>输入：</strong>head = [1,2,3,4,5]
<strong>输出：</strong>[3,4,5]
<strong>解释：</strong>链表只有一个中间结点，值为 3 。
</pre>

<p><strong class="example">示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0800-0899/0876.Middle%20of%20the%20Linked%20List/images/lc-midlist2.jpg" style="width: 664px; height: 65px;" />
<pre>
<strong>输入：</strong>head = [1,2,3,4,5,6]
<strong>输出：</strong>[4,5,6]
<strong>解释：</strong>该链表有两个中间结点，值分别为 3 和 4 ，返回第二个结点。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>链表的结点数范围是 <code>[1, 100]</code></li>
	<li><code>1 &lt;= Node.val &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：快慢指针

定义快慢指针 `fast` 和 `slow`，初始时均指向链表的头结点。

快指针 `fast` 每次走两步，慢指针 `slow` 每次走一步。当快指针走到链表的尾部时，慢指针所指的结点即为中间结点。

时间复杂度 $O(n)$，空间复杂度 $O(1)$。其中 $n$ 是链表的长度。

<!-- tabs:start -->

#### Python3

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        slow = fast = head
        while fast and fast.next:
            slow, fast = slow.next, fast.next.next
        return slow
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
    public ListNode middleNode(ListNode head) {
        ListNode slow = head, fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
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
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
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
func middleNode(head *ListNode) *ListNode {
	slow, fast := head, head
	for fast != nil && fast.Next != nil {
		slow, fast = slow.Next, fast.Next.Next
	}
	return slow
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

function middleNode(head: ListNode | null): ListNode | null {
    let fast = head,
        slow = head;
    while (fast != null && fast.next != null) {
        fast = fast.next.next;
        slow = slow.next;
    }
    return slow;
}
```

#### Rust

```rust
// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
//
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
    pub fn middle_node(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut slow = &head;
        let mut fast = &head;
        while fast.is_some() && fast.as_ref().unwrap().next.is_some() {
            slow = &slow.as_ref().unwrap().next;
            fast = &fast.as_ref().unwrap().next.as_ref().unwrap().next;
        }
        slow.clone()
    }
}
```

#### PHP

```php
/**
 * Definition for a singly-linked list.
 * class ListNode {
 *     public $val = 0;
 *     public $next = null;
 *     function __construct($val = 0, $next = null) {
 *         $this->val = $val;
 *         $this->next = $next;
 *     }
 * }
 */
class Solution {
    /**
     * @param ListNode $head
     * @return ListNode
     */
    function middleNode($head) {
        $count = 0;
        $tmpHead = $head;
        while ($tmpHead != null) {
            $tmpHead = $tmpHead->next;
            $count++;
        }
        $len = $count - floor($count / 2);
        while ($count != $len) {
            $head = $head->next;
            $count--;
        }
        return $head;
    }
}
```

#### C

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [877. 石子游戏](https://leetcode.cn/problems/stone-game){#877}

{{< tabs "877" >}}

{{% tab "python" %}}
```python
class Solution:
    def stoneGame(self, piles: List[int]) -> bool:
        n = len(piles)
        f = [[0] * n for _ in range(n)]
        for i, x in enumerate(piles):
            f[i][i] = x
        for i in range(n - 2, -1, -1):
            for j in range(i + 1, n):
                f[i][j] = max(piles[i] - f[i + 1][j], piles[j] - f[i][j - 1])
        return f[0][n - 1] > 0
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean stoneGame(int[] piles) {
        int n = piles.length;
        int[][] f = new int[n][n];
        for (int i = 0; i < n; ++i) {
            f[i][i] = piles[i];
        }
        for (int i = n - 2; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                f[i][j] = Math.max(piles[i] - f[i + 1][j], piles[j] - f[i][j - 1]);
            }
        }
        return f[0][n - 1] > 0;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int f[n][n];
        memset(f, 0, sizeof(f));
        for (int i = 0; i < n; ++i) {
            f[i][i] = piles[i];
        }
        for (int i = n - 2; ~i; --i) {
            for (int j = i + 1; j < n; ++j) {
                f[i][j] = max(piles[i] - f[i + 1][j], piles[j] - f[i][j - 1]);
            }
        }
        return f[0][n - 1] > 0;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func stoneGame(piles []int) bool {
	n := len(piles)
	f := make([][]int, n)
	for i, x := range piles {
		f[i] = make([]int, n)
		f[i][i] = x
	}
	for i := n - 2; i >= 0; i-- {
		for j := i + 1; j < n; j++ {
			f[i][j] = max(piles[i]-f[i+1][j], piles[j]-f[i][j-1])
		}
	}
	return f[0][n-1] > 0
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function stoneGame(piles: number[]): boolean {
    const n = piles.length;
    const f: number[][] = new Array(n).fill(0).map(() => new Array(n).fill(0));
    for (let i = 0; i < n; ++i) {
        f[i][i] = piles[i];
    }
    for (let i = n - 2; i >= 0; --i) {
        for (let j = i + 1; j < n; ++j) {
            f[i][j] = Math.max(piles[i] - f[i + 1][j], piles[j] - f[i][j - 1]);
        }
    }
    return f[0][n - 1] > 0;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>Alice 和 Bob 用几堆石子在做游戏。一共有偶数堆石子，<strong>排成一行</strong>；每堆都有 <strong>正</strong> 整数颗石子，数目为 <code>piles[i]</code>&nbsp;。</p>

<p>游戏以谁手中的石子最多来决出胜负。石子的 <strong>总数</strong> 是 <strong>奇数</strong> ，所以没有平局。</p>

<p>Alice 和 Bob 轮流进行，<strong>Alice 先开始</strong> 。 每回合，玩家从行的 <strong>开始</strong> 或 <strong>结束</strong> 处取走整堆石头。 这种情况一直持续到没有更多的石子堆为止，此时手中 <strong>石子最多</strong> 的玩家 <strong>获胜</strong> 。</p>

<p>假设 Alice 和 Bob 都发挥出最佳水平，当 Alice 赢得比赛时返回&nbsp;<code>true</code>&nbsp;，当 Bob 赢得比赛时返回&nbsp;<code>false</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>piles = [5,3,4,5]
<strong>输出：</strong>true
<strong>解释：</strong>
Alice 先开始，只能拿前 5 颗或后 5 颗石子 。
假设他取了前 5 颗，这一行就变成了 [3,4,5] 。
如果 Bob 拿走前 3 颗，那么剩下的是 [4,5]，Alice 拿走后 5 颗赢得 10 分。
如果 Bob 拿走后 5 颗，那么剩下的是 [3,4]，Alice 拿走后 4 颗赢得 9 分。
这表明，取前 5 颗石子对 Alice 来说是一个胜利的举动，所以返回 true 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>piles = [3,7,2,3]
<strong>输出：</strong>true
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= piles.length &lt;= 500</code></li>
	<li><code>piles.length</code> 是 <strong>偶数</strong></li>
	<li><code>1 &lt;= piles[i] &lt;= 500</code></li>
	<li><code>sum(piles[i])</code>&nbsp;是 <strong>奇数</strong></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

我们设计一个函数 $dfs(i, j)$，表示从第 $i$ 堆石子到第 $j$ 堆石子，当前玩家与另一个玩家的石子数量之差的最大值。那么答案就是 $dfs(0, n - 1) \gt 0$。

函数 $dfs(i, j)$ 的计算方法如下：

-   如果 $i \gt j$，说明当前没有石子了，所以当前玩家没有石子可以拿，差值为 $0$，即 $dfs(i, j) = 0$。
-   否则，当前玩家有两种选择，如果选择第 $i$ 堆石子，那么当前玩家与另一个玩家的石子数量之差为 $piles[i] - dfs(i + 1, j)$；如果选择第 $j$ 堆石子，那么当前玩家与另一个玩家的石子数量之差为 $piles[j] - dfs(i, j - 1)$。当前玩家会选择两种情况中差值较大的情况，也就是说 $dfs(i, j) = \max(piles[i] - dfs(i + 1, j), piles[j] - dfs(i, j - 1))$。

最后，我们只需要判断 $dfs(0, n - 1) \gt 0$ 即可。

为了避免重复计算，我们可以使用记忆化搜索的方法，用一个数组 $f$ 记录所有的 $dfs(i, j)$ 的值，当函数再次被调用到时，我们可以直接从 $f$ 中取出答案而不需要重新计算。

时间复杂度 $O(n^2)$，空间复杂度 $O(n^2)$。其中 $n$ 是石子的堆数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def stoneGame(self, piles: List[int]) -> bool:
        @cache
        def dfs(i: int, j: int) -> int:
            if i > j:
                return 0
            return max(piles[i] - dfs(i + 1, j), piles[j] - dfs(i, j - 1))

        return dfs(0, len(piles) - 1) > 0
```

#### Java

```java
class Solution {
    private int[] piles;
    private int[][] f;

    public boolean stoneGame(int[] piles) {
        this.piles = piles;
        int n = piles.length;
        f = new int[n][n];
        return dfs(0, n - 1) > 0;
    }

    private int dfs(int i, int j) {
        if (i > j) {
            return 0;
        }
        if (f[i][j] != 0) {
            return f[i][j];
        }
        return f[i][j] = Math.max(piles[i] - dfs(i + 1, j), piles[j] - dfs(i, j - 1));
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int f[n][n];
        memset(f, 0, sizeof(f));
        auto dfs = [&](this auto&& dfs, int i, int j) -> int {
            if (i > j) {
                return 0;
            }
            if (f[i][j]) {
                return f[i][j];
            }
            return f[i][j] = max(piles[i] - dfs(i + 1, j), piles[j] - dfs(i, j - 1));
        };
        return dfs(0, n - 1) > 0;
    }
};
```

#### Go

```go
func stoneGame(piles []int) bool {
	n := len(piles)
	f := make([][]int, n)
	for i := range f {
		f[i] = make([]int, n)
	}
	var dfs func(i, j int) int
	dfs = func(i, j int) int {
		if i > j {
			return 0
		}
		if f[i][j] == 0 {
			f[i][j] = max(piles[i]-dfs(i+1, j), piles[j]-dfs(i, j-1))
		}
		return f[i][j]
	}
	return dfs(0, n-1) > 0
}
```

#### TypeScript

```ts
function stoneGame(piles: number[]): boolean {
    const n = piles.length;
    const f: number[][] = new Array(n).fill(0).map(() => new Array(n).fill(0));
    const dfs = (i: number, j: number): number => {
        if (i > j) {
            return 0;
        }
        if (f[i][j] === 0) {
            f[i][j] = Math.max(piles[i] - dfs(i + 1, j), piles[j] - dfs(i, j - 1));
        }
        return f[i][j];
    };
    return dfs(0, n - 1) > 0;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：动态规划

我们也可以使用动态规划的方法，定义 $f[i][j]$ 表示当前玩家在 $piles[i..j]$ 这部分石子中能够获得的最大石子数的差值。那么最后答案就是 $f[0][n - 1] \gt 0$。

初始时 $f[i][i]=piles[i]$，因为只有一堆石子，所以当前玩家只能拿取这堆石子，差值为 $piles[i]$。

考虑 $f[i][j]$，其中 $i \lt j$，有两种情况：

-   如果当前玩家拿走了石子堆 $piles[i]$，那么剩下的石子堆为 $piles[i + 1..j]$，此时轮到另一个玩家进行游戏，所以 $f[i][j] = piles[i] - f[i + 1][j]$。
-   如果当前玩家拿走了石子堆 $piles[j]$，那么剩下的石子堆为 $piles[i..j - 1]$，此时轮到另一个玩家进行游戏，所以 $f[i][j] = piles[j] - f[i][j - 1]$。

因此，最终的状态转移方程为 $f[i][j] = \max(piles[i] - f[i + 1][j], piles[j] - f[i][j - 1])$。

最后，我们只需要判断 $f[0][n - 1] \gt 0$ 即可。

时间复杂度 $O(n^2)$，空间复杂度 $O(n^2)$。其中 $n$ 是石子的堆数。

相似题目：

-   [486. 预测赢家](https://github.com/doocs/leetcode/blob/main/solution/0400-0499/0486.Predict%20the%20Winner/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def stoneGame(self, piles: List[int]) -> bool:
        n = len(piles)
        f = [[0] * n for _ in range(n)]
        for i, x in enumerate(piles):
            f[i][i] = x
        for i in range(n - 2, -1, -1):
            for j in range(i + 1, n):
                f[i][j] = max(piles[i] - f[i + 1][j], piles[j] - f[i][j - 1])
        return f[0][n - 1] > 0
```

#### Java

```java
class Solution {
    public boolean stoneGame(int[] piles) {
        int n = piles.length;
        int[][] f = new int[n][n];
        for (int i = 0; i < n; ++i) {
            f[i][i] = piles[i];
        }
        for (int i = n - 2; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                f[i][j] = Math.max(piles[i] - f[i + 1][j], piles[j] - f[i][j - 1]);
            }
        }
        return f[0][n - 1] > 0;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int f[n][n];
        memset(f, 0, sizeof(f));
        for (int i = 0; i < n; ++i) {
            f[i][i] = piles[i];
        }
        for (int i = n - 2; ~i; --i) {
            for (int j = i + 1; j < n; ++j) {
                f[i][j] = max(piles[i] - f[i + 1][j], piles[j] - f[i][j - 1]);
            }
        }
        return f[0][n - 1] > 0;
    }
};
```

#### Go

```go
func stoneGame(piles []int) bool {
	n := len(piles)
	f := make([][]int, n)
	for i, x := range piles {
		f[i] = make([]int, n)
		f[i][i] = x
	}
	for i := n - 2; i >= 0; i-- {
		for j := i + 1; j < n; j++ {
			f[i][j] = max(piles[i]-f[i+1][j], piles[j]-f[i][j-1])
		}
	}
	return f[0][n-1] > 0
}
```

#### TypeScript

```ts
function stoneGame(piles: number[]): boolean {
    const n = piles.length;
    const f: number[][] = new Array(n).fill(0).map(() => new Array(n).fill(0));
    for (let i = 0; i < n; ++i) {
        f[i][i] = piles[i];
    }
    for (let i = n - 2; i >= 0; --i) {
        for (let j = i + 1; j < n; ++j) {
            f[i][j] = Math.max(piles[i] - f[i + 1][j], piles[j] - f[i][j - 1]);
        }
    }
    return f[0][n - 1] > 0;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [878. 第 N 个神奇数字](https://leetcode.cn/problems/nth-magical-number){#878}

{{< tabs "878" >}}

{{% tab "python" %}}
```python
class Solution:
    def nthMagicalNumber(self, n: int, a: int, b: int) -> int:
        mod = 10**9 + 7
        c = lcm(a, b)
        r = (a + b) * n
        return bisect_left(range(r), x=n, key=lambda x: x // a + x // b - x // c) % mod
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private static final int MOD = (int) 1e9 + 7;

    public int nthMagicalNumber(int n, int a, int b) {
        int c = a * b / gcd(a, b);
        long l = 0, r = (long) (a + b) * n;
        while (l < r) {
            long mid = l + r >>> 1;
            if (mid / a + mid / b - mid / c >= n) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return (int) (l % MOD);
    }

    private int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
using ll = long long;

class Solution {
public:
    const int mod = 1e9 + 7;

    int nthMagicalNumber(int n, int a, int b) {
        int c = lcm(a, b);
        ll l = 0, r = 1ll * (a + b) * n;
        while (l < r) {
            ll mid = l + r >> 1;
            if (mid / a + mid / b - mid / c >= n)
                r = mid;
            else
                l = mid + 1;
        }
        return l % mod;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func nthMagicalNumber(n int, a int, b int) int {
	c := a * b / gcd(a, b)
	const mod int = 1e9 + 7
	r := (a + b) * n
	return sort.Search(r, func(x int) bool { return x/a+x/b-x/c >= n }) % mod
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>一个正整数如果能被 <code>a</code> 或 <code>b</code> 整除，那么它是神奇的。</p>

<p>给定三个整数 <code>n</code> ,&nbsp;<code>a</code> , <code>b</code> ，返回第 <code>n</code> 个神奇的数字。因为答案可能很大，所以返回答案&nbsp;<strong>对&nbsp;</strong><code>10<sup>9</sup>&nbsp;+ 7</code> <strong>取模&nbsp;</strong>后的值。</p>

<p>&nbsp;</p>

<ol>
</ol>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 1, a = 2, b = 3
<strong>输出：</strong>2
</pre>

<p><strong>示例&nbsp;2：</strong></p>

<pre>
<strong>输入：</strong>n = 4, a = 2, b = 3
<strong>输出：</strong>6
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>9</sup></code></li>
	<li><code>2 &lt;= a, b &lt;= 4 * 10<sup>4</sup></code></li>
</ul>

<p>&nbsp;</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数学 + 二分查找

根据题目描述，神奇数字是能被 $a$ 或 $b$ 整除的正整数。

而我们知道，对于任意正整数 $x$，在 $[1,..x]$ 范围内，能被 $a$ 整除的数有 $\lfloor \frac{x}{a} \rfloor$ 个，能被 $b$ 整除的数有 $\lfloor \frac{x}{b} \rfloor$ 个，能被 $a$ 和 $b$ 同时整除的数有 $\lfloor \frac{x}{c} \rfloor$ 个，其中 $c$ 是 $a$ 和 $b$ 的最小公倍数。最小公倍数的计算公式为 $c = lcm(a, b) = \frac{a \times b}{gcd(a, b)}$。

因此，对于任意正整数 $x$，在 $[1,..x]$ 范围内，神奇数字的个数为：

$$
\lfloor \frac{x}{a} \rfloor + \lfloor \frac{x}{b} \rfloor - \lfloor \frac{x}{c} \rfloor
$$

为什么要减去 $\lfloor \frac{x}{c} \rfloor$ 呢？可以这样理解，在 $[1,..x]$ 范围内，能被 $a$ 和 $b$ 同时整除的数，它们既能被 $a$ 整除，也能被 $b$ 整除，因此它们被计算了两次，需要减去一次。

题目要我们找到第 $n$ 个神奇数字，也即是说，要找到一个最小的正整数 $x$，使得以下式子成立：

$$
\lfloor \frac{x}{a} \rfloor + \lfloor \frac{x}{b} \rfloor - \lfloor \frac{x}{c} \rfloor \geq n
$$

随着 $x$ 的增大，神奇数字的个数也会增大，因此我们可以使用二分查找的方法，找到最小的正整数 $x$，使得上述式子成立。

注意答案的取模操作。

时间复杂度 $O(\log M)$，空间复杂度 $O(1)$。其中 $M$ 是二分查找的上界，本题可以取 $M=(a+b) \times n$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def nthMagicalNumber(self, n: int, a: int, b: int) -> int:
        mod = 10**9 + 7
        c = lcm(a, b)
        r = (a + b) * n
        return bisect_left(range(r), x=n, key=lambda x: x // a + x // b - x // c) % mod
```

#### Java

```java
class Solution {
    private static final int MOD = (int) 1e9 + 7;

    public int nthMagicalNumber(int n, int a, int b) {
        int c = a * b / gcd(a, b);
        long l = 0, r = (long) (a + b) * n;
        while (l < r) {
            long mid = l + r >>> 1;
            if (mid / a + mid / b - mid / c >= n) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return (int) (l % MOD);
    }

    private int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
}
```

#### C++

```cpp
using ll = long long;

class Solution {
public:
    const int mod = 1e9 + 7;

    int nthMagicalNumber(int n, int a, int b) {
        int c = lcm(a, b);
        ll l = 0, r = 1ll * (a + b) * n;
        while (l < r) {
            ll mid = l + r >> 1;
            if (mid / a + mid / b - mid / c >= n)
                r = mid;
            else
                l = mid + 1;
        }
        return l % mod;
    }
};
```

#### Go

```go
func nthMagicalNumber(n int, a int, b int) int {
	c := a * b / gcd(a, b)
	const mod int = 1e9 + 7
	r := (a + b) * n
	return sort.Search(r, func(x int) bool { return x/a+x/b-x/c >= n }) % mod
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [879. 盈利计划](https://leetcode.cn/problems/profitable-schemes){#879}

{{< tabs "879" >}}

{{% tab "python" %}}
```python
class Solution:
    def profitableSchemes(
        self, n: int, minProfit: int, group: List[int], profit: List[int]
    ) -> int:
        mod = 10**9 + 7
        m = len(group)
        f = [[[0] * (minProfit + 1) for _ in range(n + 1)] for _ in range(m + 1)]
        for j in range(n + 1):
            f[0][j][0] = 1
        for i, (x, p) in enumerate(zip(group, profit), 1):
            for j in range(n + 1):
                for k in range(minProfit + 1):
                    f[i][j][k] = f[i - 1][j][k]
                    if j >= x:
                        f[i][j][k] = (f[i][j][k] + f[i - 1][j - x][max(0, k - p)]) % mod
        return f[m][n][minProfit]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int profitableSchemes(int n, int minProfit, int[] group, int[] profit) {
        final int mod = (int) 1e9 + 7;
        int m = group.length;
        int[][][] f = new int[m + 1][n + 1][minProfit + 1];
        for (int j = 0; j <= n; ++j) {
            f[0][j][0] = 1;
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                for (int k = 0; k <= minProfit; ++k) {
                    f[i][j][k] = f[i - 1][j][k];
                    if (j >= group[i - 1]) {
                        f[i][j][k]
                            = (f[i][j][k]
                                  + f[i - 1][j - group[i - 1]][Math.max(0, k - profit[i - 1])])
                            % mod;
                    }
                }
            }
        }
        return f[m][n][minProfit];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int m = group.size();
        int f[m + 1][n + 1][minProfit + 1];
        memset(f, 0, sizeof(f));
        for (int j = 0; j <= n; ++j) {
            f[0][j][0] = 1;
        }
        const int mod = 1e9 + 7;
        for (int i = 1; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                for (int k = 0; k <= minProfit; ++k) {
                    f[i][j][k] = f[i - 1][j][k];
                    if (j >= group[i - 1]) {
                        f[i][j][k] = (f[i][j][k] + f[i - 1][j - group[i - 1]][max(0, k - profit[i - 1])]) % mod;
                    }
                }
            }
        }
        return f[m][n][minProfit];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func profitableSchemes(n int, minProfit int, group []int, profit []int) int {
	m := len(group)
	f := make([][][]int, m+1)
	for i := range f {
		f[i] = make([][]int, n+1)
		for j := range f[i] {
			f[i][j] = make([]int, minProfit+1)
		}
	}
	for j := 0; j <= n; j++ {
		f[0][j][0] = 1
	}
	const mod = 1e9 + 7
	for i := 1; i <= m; i++ {
		for j := 0; j <= n; j++ {
			for k := 0; k <= minProfit; k++ {
				f[i][j][k] = f[i-1][j][k]
				if j >= group[i-1] {
					f[i][j][k] += f[i-1][j-group[i-1]][max(0, k-profit[i-1])]
					f[i][j][k] %= mod
				}
			}
		}
	}
	return f[m][n][minProfit]
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>集团里有 <code>n</code> 名员工，他们可以完成各种各样的工作创造利润。</p>

<p>第 <code>i</code> 种工作会产生 <code>profit[i]</code> 的利润，它要求 <code>group[i]</code> 名成员共同参与。如果成员参与了其中一项工作，就不能参与另一项工作。</p>

<p>工作的任何至少产生 <code>minProfit</code> 利润的子集称为 <strong>盈利计划</strong> 。并且工作的成员总数最多为 <code>n</code> 。</p>

<p>有多少种计划可以选择？因为答案很大，所以<strong> 返回结果模 </strong><code>10^9 + 7</code><strong> 的值</strong>。</p>

<div class="original__bRMd">
<div>
<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 5, minProfit = 3, group = [2,2], profit = [2,3]
<strong>输出：</strong>2
<strong>解释：</strong>至少产生 3 的利润，该集团可以完成工作 0 和工作 1 ，或仅完成工作 1 。
总的来说，有两种计划。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 10, minProfit = 5, group = [2,3,5], profit = [6,7,8]
<strong>输出：</strong>7
<strong>解释：</strong>至少产生 5 的利润，只要完成其中一种工作就行，所以该集团可以完成任何工作。
有 7 种可能的计划：(0)，(1)，(2)，(0,1)，(0,2)，(1,2)，以及 (0,1,2) 。</pre>
</div>
</div>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= n <= 100</code></li>
	<li><code>0 <= minProfit <= 100</code></li>
	<li><code>1 <= group.length <= 100</code></li>
	<li><code>1 <= group[i] <= 100</code></li>
	<li><code>profit.length == group.length</code></li>
	<li><code>0 <= profit[i] <= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

我们设计一个函数 $dfs(i, j, k)$，表示从第 $i$ 个工作开始，且当前已经选择了 $j$ 个员工，且当前产生的利润为 $k$，这种情况下的方案数。那么答案就是 $dfs(0, 0, 0)$。

函数 $dfs(i, j, k)$ 的执行过程如下：

-   如果 $i = n$，表示所有工作都已经考虑过了，如果 $k \geq minProfit$，则方案数为 $1$，否则方案数为 $0$；
-   如果 $i \lt n$，我们可以选择不选择第 $i$ 个工作，此时方案数为 $dfs(i + 1, j, k)$；如果 $j + group[i] \leq n$，我们也可以选择第 $i$ 个工作，此时方案数为 $dfs(i + 1, j + group[i], \min(k + profit[i], minProfit))$。这里我们将利润上限限制在 $minProfit$，是因为利润超过 $minProfit$ 对我们的答案没有任何影响。

最后返回 $dfs(0, 0, 0)$ 即可。

为了避免重复计算，我们可以使用记忆化搜索的方法，用一个三维数组 $f$ 记录所有的 $dfs(i, j, k)$ 的结果。当我们计算出 $dfs(i, j, k)$ 的值后，我们将其存入 $f[i][j][k]$ 中。调用 $dfs(i, j, k)$ 时，如果 $f[i][j][k]$ 已经被计算过，我们直接返回 $f[i][j][k]$ 即可。

时间复杂度 $O(m \times n \times minProfit)$，空间复杂度 $O(m \times n \times minProfit)$。其中 $m$ 和 $n$ 分别为工作的数量和员工的数量，而 $minProfit$ 为至少产生的利润。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def profitableSchemes(
        self, n: int, minProfit: int, group: List[int], profit: List[int]
    ) -> int:
        @cache
        def dfs(i: int, j: int, k: int) -> int:
            if i >= len(group):
                return 1 if k == minProfit else 0
            ans = dfs(i + 1, j, k)
            if j + group[i] <= n:
                ans += dfs(i + 1, j + group[i], min(k + profit[i], minProfit))
            return ans % (10**9 + 7)

        return dfs(0, 0, 0)
```

#### Java

```java
class Solution {
    private Integer[][][] f;
    private int m;
    private int n;
    private int minProfit;
    private int[] group;
    private int[] profit;
    private final int mod = (int) 1e9 + 7;

    public int profitableSchemes(int n, int minProfit, int[] group, int[] profit) {
        m = group.length;
        this.n = n;
        f = new Integer[m][n + 1][minProfit + 1];
        this.minProfit = minProfit;
        this.group = group;
        this.profit = profit;
        return dfs(0, 0, 0);
    }

    private int dfs(int i, int j, int k) {
        if (i >= m) {
            return k == minProfit ? 1 : 0;
        }
        if (f[i][j][k] != null) {
            return f[i][j][k];
        }
        int ans = dfs(i + 1, j, k);
        if (j + group[i] <= n) {
            ans += dfs(i + 1, j + group[i], Math.min(k + profit[i], minProfit));
        }
        ans %= mod;
        return f[i][j][k] = ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int m = group.size();
        int f[m][n + 1][minProfit + 1];
        memset(f, -1, sizeof(f));
        const int mod = 1e9 + 7;
        function<int(int, int, int)> dfs = [&](int i, int j, int k) -> int {
            if (i >= m) {
                return k == minProfit ? 1 : 0;
            }
            if (f[i][j][k] != -1) {
                return f[i][j][k];
            }
            int ans = dfs(i + 1, j, k);
            if (j + group[i] <= n) {
                ans += dfs(i + 1, j + group[i], min(k + profit[i], minProfit));
            }
            ans %= mod;
            return f[i][j][k] = ans;
        };
        return dfs(0, 0, 0);
    }
};
```

#### Go

```go
func profitableSchemes(n int, minProfit int, group []int, profit []int) int {
	m := len(group)
	f := make([][][]int, m)
	for i := range f {
		f[i] = make([][]int, n+1)
		for j := range f[i] {
			f[i][j] = make([]int, minProfit+1)
			for k := range f[i][j] {
				f[i][j][k] = -1
			}
		}
	}
	const mod = 1e9 + 7
	var dfs func(i, j, k int) int
	dfs = func(i, j, k int) int {
		if i >= m {
			if k >= minProfit {
				return 1
			}
			return 0
		}
		if f[i][j][k] != -1 {
			return f[i][j][k]
		}
		ans := dfs(i+1, j, k)
		if j+group[i] <= n {
			ans += dfs(i+1, j+group[i], min(k+profit[i], minProfit))
		}
		ans %= mod
		f[i][j][k] = ans
		return ans
	}
	return dfs(0, 0, 0)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：动态规划

我们定义 $f[i][j][k]$ 表示前 $i$ 个工作中，选择了不超过 $j$ 个员工，且至少产生 $k$ 的利润的方案数。初始时 $f[0][j][0] = 1$，表示不选择任何工作，且至少产生 $0$ 的利润的方案数为 $1$。答案即为 $f[m][n][minProfit]$。

对于第 $i$ 个工作，我们可以选择参与或不参与。如果不参与，则 $f[i][j][k] = f[i - 1][j][k]$；如果参与，则 $f[i][j][k] = f[i - 1][j - group[i - 1]][max(0, k - profit[i - 1])]$。我们需要枚举 $j$ 和 $k$，并将所有的方案数相加。

最终的答案即为 $f[m][n][minProfit]$。

时间复杂度 $O(m \times n \times minProfit)$，空间复杂度 $O(m \times n \times minProfit)$。其中 $m$ 和 $n$ 分别为工作的数量和员工的数量，而 $minProfit$ 为至少产生的利润。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def profitableSchemes(
        self, n: int, minProfit: int, group: List[int], profit: List[int]
    ) -> int:
        mod = 10**9 + 7
        m = len(group)
        f = [[[0] * (minProfit + 1) for _ in range(n + 1)] for _ in range(m + 1)]
        for j in range(n + 1):
            f[0][j][0] = 1
        for i, (x, p) in enumerate(zip(group, profit), 1):
            for j in range(n + 1):
                for k in range(minProfit + 1):
                    f[i][j][k] = f[i - 1][j][k]
                    if j >= x:
                        f[i][j][k] = (f[i][j][k] + f[i - 1][j - x][max(0, k - p)]) % mod
        return f[m][n][minProfit]
```

#### Java

```java
class Solution {
    public int profitableSchemes(int n, int minProfit, int[] group, int[] profit) {
        final int mod = (int) 1e9 + 7;
        int m = group.length;
        int[][][] f = new int[m + 1][n + 1][minProfit + 1];
        for (int j = 0; j <= n; ++j) {
            f[0][j][0] = 1;
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                for (int k = 0; k <= minProfit; ++k) {
                    f[i][j][k] = f[i - 1][j][k];
                    if (j >= group[i - 1]) {
                        f[i][j][k]
                            = (f[i][j][k]
                                  + f[i - 1][j - group[i - 1]][Math.max(0, k - profit[i - 1])])
                            % mod;
                    }
                }
            }
        }
        return f[m][n][minProfit];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int m = group.size();
        int f[m + 1][n + 1][minProfit + 1];
        memset(f, 0, sizeof(f));
        for (int j = 0; j <= n; ++j) {
            f[0][j][0] = 1;
        }
        const int mod = 1e9 + 7;
        for (int i = 1; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                for (int k = 0; k <= minProfit; ++k) {
                    f[i][j][k] = f[i - 1][j][k];
                    if (j >= group[i - 1]) {
                        f[i][j][k] = (f[i][j][k] + f[i - 1][j - group[i - 1]][max(0, k - profit[i - 1])]) % mod;
                    }
                }
            }
        }
        return f[m][n][minProfit];
    }
};
```

#### Go

```go
func profitableSchemes(n int, minProfit int, group []int, profit []int) int {
	m := len(group)
	f := make([][][]int, m+1)
	for i := range f {
		f[i] = make([][]int, n+1)
		for j := range f[i] {
			f[i][j] = make([]int, minProfit+1)
		}
	}
	for j := 0; j <= n; j++ {
		f[0][j][0] = 1
	}
	const mod = 1e9 + 7
	for i := 1; i <= m; i++ {
		for j := 0; j <= n; j++ {
			for k := 0; k <= minProfit; k++ {
				f[i][j][k] = f[i-1][j][k]
				if j >= group[i-1] {
					f[i][j][k] += f[i-1][j-group[i-1]][max(0, k-profit[i-1])]
					f[i][j][k] %= mod
				}
			}
		}
	}
	return f[m][n][minProfit]
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
