---
title: "1800_最大升序子数组和"
date: 2025-10-08T18:38:27+08:00
weight: 1
tags: [二分查找, 位运算, 哈希表, 堆（优先队列）, 字典树, 字符串, 数学, 数据库, 数组, 数论, 模拟, 设计, 贪心, 递归]
---

{{< markmap >}}
### [1800_最大升序子数组和](#1800)
#### [数组](#1800)
### [1801_积压订单中的订单总数](#1801)
#### [数组](#1801)
#### [模拟](#1801)
#### [堆（优先队列）](#1801)
### [1802_有界数组中指定下标处的最大值](#1802)
#### [贪心](#1802)
#### [数学](#1802)
#### [二分查找](#1802)
### [1803_统计异或值在范围内的数对有多少](#1803)
#### [位运算](#1803)
#### [字典树](#1803)
#### [数组](#1803)
### [1804_实现 Trie （前缀树） II 🔒](#1804)
#### [设计](#1804)
#### [字典树](#1804)
#### [哈希表](#1804)
#### [字符串](#1804)
### [1805_字符串中不同整数的数目](#1805)
#### [哈希表](#1805)
#### [字符串](#1805)
### [1806_还原排列的最少操作步数](#1806)
#### [数组](#1806)
#### [数学](#1806)
#### [模拟](#1806)
### [1807_替换字符串中的括号内容](#1807)
#### [数组](#1807)
#### [哈希表](#1807)
#### [字符串](#1807)
### [1808_好因子的最大数目](#1808)
#### [递归](#1808)
#### [数学](#1808)
#### [数论](#1808)
### [1809_没有广告的剧集 🔒](#1809)
#### [数据库](#1809)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1800_最大升序子数组和
___
#### 数组
---
### 1801_积压订单中的订单总数
___
#### 数组
___
#### 模拟
___
#### 堆（优先队列）
---
### 1802_有界数组中指定下标处的最大值
___
#### 贪心
___
#### 数学
___
#### 二分查找
---
### 1803_统计异或值在范围内的数对有多少
___
#### 位运算
___
#### 字典树
___
#### 数组
---
### 1804_实现 Trie （前缀树） II 🔒
___
#### 设计
___
#### 字典树
___
#### 哈希表
___
#### 字符串
---
### 1805_字符串中不同整数的数目
___
#### 哈希表
___
#### 字符串
---
### 1806_还原排列的最少操作步数
___
#### 数组
___
#### 数学
___
#### 模拟
---
### 1807_替换字符串中的括号内容
___
#### 数组
___
#### 哈希表
___
#### 字符串
---
### 1808_好因子的最大数目
___
#### 递归
___
#### 数学
___
#### 数论
---
### 1809_没有广告的剧集 🔒
___
#### 数据库
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 位运算 | 哈希表 |
| 堆（优先队列） | 字典树 | 字符串 |
| 数学 | 数据库 | 数组 |
| 数论 | 模拟 | 设计 |
| 贪心 | 递归 |  |

# [1800. 最大升序子数组和](https://leetcode.cn/problems/maximum-ascending-subarray-sum){#1800}

{{< tabs "1800" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxAscendingSum(self, nums: List[int]) -> int:
        ans = t = 0
        for i, v in enumerate(nums):
            if i == 0 or v > nums[i - 1]:
                t += v
                ans = max(ans, t)
            else:
                t = v
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxAscendingSum(int[] nums) {
        int ans = 0, t = 0;
        for (int i = 0; i < nums.length; ++i) {
            if (i == 0 || nums[i] > nums[i - 1]) {
                t += nums[i];
                ans = Math.max(ans, t);
            } else {
                t = nums[i];
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
    int maxAscendingSum(vector<int>& nums) {
        int ans = 0, t = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i == 0 || nums[i] > nums[i - 1]) {
                t += nums[i];
                ans = max(ans, t);
            } else {
                t = nums[i];
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxAscendingSum(nums []int) int {
	ans, t := 0, 0
	for i, v := range nums {
		if i == 0 || v > nums[i-1] {
			t += v
			if ans < t {
				ans = t
			}
		} else {
			t = v
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxAscendingSum(nums: number[]): number {
    const n = nums.length;
    let res = nums[0];
    let sum = nums[0];
    for (let i = 1; i < n; i++) {
        if (nums[i] <= nums[i - 1]) {
            res = Math.max(res, sum);
            sum = 0;
        }
        sum += nums[i];
    }
    return Math.max(res, sum);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn max_ascending_sum(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut res = nums[0];
        let mut sum = nums[0];
        for i in 1..n {
            if nums[i - 1] >= nums[i] {
                res = res.max(sum);
                sum = 0;
            }
            sum += nums[i];
        }
        res.max(sum)
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
#define max(a, b) (((a) > (b)) ? (a) : (b))

int maxAscendingSum(int* nums, int numsSize) {
    int res = nums[0];
    int sum = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (nums[i - 1] >= nums[i]) {
            res = max(res, sum);
            sum = 0;
        }
        sum += nums[i];
    }
    return max(res, sum);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个正整数组成的数组 <code>nums</code> ，返回 <code>nums</code> 中一个 <span data-keyword="strictly-increasing-array">严格递增子数组</span> 的最大可能元素和。</p>

<p>子数组是数组中的一个连续数字序列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [10,20,30,5,10,50]
<strong>输出：</strong>65
<strong>解释：</strong>[5,10,50] 是元素和最大的升序子数组，最大元素和为 65 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [10,20,30,40,50]
<strong>输出：</strong>150
<strong>解释：</strong>[10,20,30,40,50] 是元素和最大的升序子数组，最大元素和为 150 。 
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [12,17,15,13,10,11,12]
<strong>输出：</strong>33
<strong>解释：</strong>[10,11,12] 是元素和最大的升序子数组，最大元素和为 33 。 
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

### 方法一：直接模拟

我们用变量 $t$ 记录当前升序子数组的和，用变量 $ans$ 记录最大的升序子数组和。

遍历数组 $nums$：

如果当前元素是数组的第一个元素，或者当前元素大于前一个元素，那么将当前元素加入到当前升序子数组的和，即 $t = t + nums[i]$，并且更新最大升序子数组和 $ans = \max(ans, t)$；否则，当前元素不满足升序子数组的条件，那么将当前升序子数组的和 $t$ 重置为当前元素，即 $t = nums[i]$。

遍历结束，返回最大升序子数组和 $ans$。

时间复杂度 $O(n)$，其中 $n$ 为数组 $nums$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxAscendingSum(self, nums: List[int]) -> int:
        ans = t = 0
        for i, v in enumerate(nums):
            if i == 0 or v > nums[i - 1]:
                t += v
                ans = max(ans, t)
            else:
                t = v
        return ans
```

#### Java

```java
class Solution {
    public int maxAscendingSum(int[] nums) {
        int ans = 0, t = 0;
        for (int i = 0; i < nums.length; ++i) {
            if (i == 0 || nums[i] > nums[i - 1]) {
                t += nums[i];
                ans = Math.max(ans, t);
            } else {
                t = nums[i];
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
    int maxAscendingSum(vector<int>& nums) {
        int ans = 0, t = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i == 0 || nums[i] > nums[i - 1]) {
                t += nums[i];
                ans = max(ans, t);
            } else {
                t = nums[i];
            }
        }
        return ans;
    }
};
```

#### Go

```go
func maxAscendingSum(nums []int) int {
	ans, t := 0, 0
	for i, v := range nums {
		if i == 0 || v > nums[i-1] {
			t += v
			if ans < t {
				ans = t
			}
		} else {
			t = v
		}
	}
	return ans
}
```

#### TypeScript

```ts
function maxAscendingSum(nums: number[]): number {
    const n = nums.length;
    let res = nums[0];
    let sum = nums[0];
    for (let i = 1; i < n; i++) {
        if (nums[i] <= nums[i - 1]) {
            res = Math.max(res, sum);
            sum = 0;
        }
        sum += nums[i];
    }
    return Math.max(res, sum);
}
```

#### Rust

```rust
impl Solution {
    pub fn max_ascending_sum(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut res = nums[0];
        let mut sum = nums[0];
        for i in 1..n {
            if nums[i - 1] >= nums[i] {
                res = res.max(sum);
                sum = 0;
            }
            sum += nums[i];
        }
        res.max(sum)
    }
}
```

#### C

```c
#define max(a, b) (((a) > (b)) ? (a) : (b))

int maxAscendingSum(int* nums, int numsSize) {
    int res = nums[0];
    int sum = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (nums[i - 1] >= nums[i]) {
            res = max(res, sum);
            sum = 0;
        }
        sum += nums[i];
    }
    return max(res, sum);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1801. 积压订单中的订单总数](https://leetcode.cn/problems/number-of-orders-in-the-backlog){#1801}

{{< tabs "1801" >}}

{{% tab "python" %}}
```python
class Solution:
    def getNumberOfBacklogOrders(self, orders: List[List[int]]) -> int:
        buy, sell = [], []
        for p, a, t in orders:
            if t == 0:
                while a and sell and sell[0][0] <= p:
                    x, y = heappop(sell)
                    if a >= y:
                        a -= y
                    else:
                        heappush(sell, (x, y - a))
                        a = 0
                if a:
                    heappush(buy, (-p, a))
            else:
                while a and buy and -buy[0][0] >= p:
                    x, y = heappop(buy)
                    if a >= y:
                        a -= y
                    else:
                        heappush(buy, (x, y - a))
                        a = 0
                if a:
                    heappush(sell, (p, a))
        mod = 10**9 + 7
        return sum(v[1] for v in buy + sell) % mod
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int getNumberOfBacklogOrders(int[][] orders) {
        PriorityQueue<int[]> buy = new PriorityQueue<>((a, b) -> b[0] - a[0]);
        PriorityQueue<int[]> sell = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        for (var e : orders) {
            int p = e[0], a = e[1], t = e[2];
            if (t == 0) {
                while (a > 0 && !sell.isEmpty() && sell.peek()[0] <= p) {
                    var q = sell.poll();
                    int x = q[0], y = q[1];
                    if (a >= y) {
                        a -= y;
                    } else {
                        sell.offer(new int[] {x, y - a});
                        a = 0;
                    }
                }
                if (a > 0) {
                    buy.offer(new int[] {p, a});
                }
            } else {
                while (a > 0 && !buy.isEmpty() && buy.peek()[0] >= p) {
                    var q = buy.poll();
                    int x = q[0], y = q[1];
                    if (a >= y) {
                        a -= y;
                    } else {
                        buy.offer(new int[] {x, y - a});
                        a = 0;
                    }
                }
                if (a > 0) {
                    sell.offer(new int[] {p, a});
                }
            }
        }
        long ans = 0;
        final int mod = (int) 1e9 + 7;
        while (!buy.isEmpty()) {
            ans += buy.poll()[1];
        }
        while (!sell.isEmpty()) {
            ans += sell.poll()[1];
        }
        return (int) (ans % mod);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        using pii = pair<int, int>;
        priority_queue<pii, vector<pii>, greater<pii>> sell;
        priority_queue<pii> buy;
        for (auto& e : orders) {
            int p = e[0], a = e[1], t = e[2];
            if (t == 0) {
                while (a && !sell.empty() && sell.top().first <= p) {
                    auto [x, y] = sell.top();
                    sell.pop();
                    if (a >= y) {
                        a -= y;
                    } else {
                        sell.push({x, y - a});
                        a = 0;
                    }
                }
                if (a) {
                    buy.push({p, a});
                }
            } else {
                while (a && !buy.empty() && buy.top().first >= p) {
                    auto [x, y] = buy.top();
                    buy.pop();
                    if (a >= y) {
                        a -= y;
                    } else {
                        buy.push({x, y - a});
                        a = 0;
                    }
                }
                if (a) {
                    sell.push({p, a});
                }
            }
        }
        long ans = 0;
        while (!buy.empty()) {
            ans += buy.top().second;
            buy.pop();
        }
        while (!sell.empty()) {
            ans += sell.top().second;
            sell.pop();
        }
        const int mod = 1e9 + 7;
        return ans % mod;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func getNumberOfBacklogOrders(orders [][]int) (ans int) {
	sell := hp{}
	buy := hp{}
	for _, e := range orders {
		p, a, t := e[0], e[1], e[2]
		if t == 0 {
			for a > 0 && len(sell) > 0 && sell[0].p <= p {
				q := heap.Pop(&sell).(pair)
				x, y := q.p, q.a
				if a >= y {
					a -= y
				} else {
					heap.Push(&sell, pair{x, y - a})
					a = 0
				}
			}
			if a > 0 {
				heap.Push(&buy, pair{-p, a})
			}
		} else {
			for a > 0 && len(buy) > 0 && -buy[0].p >= p {
				q := heap.Pop(&buy).(pair)
				x, y := q.p, q.a
				if a >= y {
					a -= y
				} else {
					heap.Push(&buy, pair{x, y - a})
					a = 0
				}
			}
			if a > 0 {
				heap.Push(&sell, pair{p, a})
			}
		}
	}
	const mod int = 1e9 + 7
	for len(buy) > 0 {
		ans += heap.Pop(&buy).(pair).a
	}
	for len(sell) > 0 {
		ans += heap.Pop(&sell).(pair).a
	}
	return ans % mod
}

type pair struct{ p, a int }
type hp []pair

func (h hp) Len() int           { return len(h) }
func (h hp) Less(i, j int) bool { return h[i].p < h[j].p }
func (h hp) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *hp) Push(v any)        { *h = append(*h, v.(pair)) }
func (h *hp) Pop() any          { a := *h; v := a[len(a)-1]; *h = a[:len(a)-1]; return v }
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个二维整数数组 <code>orders</code> ，其中每个 <code>orders[i] = [price<sub>i</sub>, amount<sub>i</sub>, orderType<sub>i</sub>]</code> 表示有 <code>amount<sub>i</sub></code><sub> </sub>笔类型为 <code>orderType<sub>i</sub></code> 、价格为 <code>price<sub>i</sub></code> 的订单。</p>

<p>订单类型 <code>orderType<sub>i</sub></code> 可以分为两种：</p>

<ul>
	<li><code>0</code> 表示这是一批采购订单 <code>buy</code></li>
	<li><code>1</code> 表示这是一批销售订单 <code>sell</code></li>
</ul>

<p>注意，<code>orders[i]</code> 表示一批共计 <code>amount<sub>i</sub></code> 笔的独立订单，这些订单的价格和类型相同。对于所有有效的 <code>i</code> ，由 <code>orders[i]</code> 表示的所有订单提交时间均早于 <code>orders[i+1]</code> 表示的所有订单。</p>

<p>存在由未执行订单组成的 <strong>积压订单</strong> 。积压订单最初是空的。提交订单时，会发生以下情况：</p>

<ul>
	<li>如果该订单是一笔采购订单 <code>buy</code> ，则可以查看积压订单中价格 <strong>最低</strong> 的销售订单 <code>sell</code> 。如果该销售订单 <code>sell</code> 的价格 <strong>低于或等于</strong> 当前采购订单 <code>buy</code> 的价格，则匹配并执行这两笔订单，并将销售订单 <code>sell</code> 从积压订单中删除。否则，采购订单 <code>buy</code> 将会添加到积压订单中。</li>
	<li>反之亦然，如果该订单是一笔销售订单 <code>sell</code> ，则可以查看积压订单中价格 <strong>最高</strong> 的采购订单 <code>buy</code> 。如果该采购订单 <code>buy</code> 的价格 <strong>高于或等于</strong> 当前销售订单 <code>sell</code> 的价格，则匹配并执行这两笔订单，并将采购订单 <code>buy</code> 从积压订单中删除。否则，销售订单 <code>sell</code> 将会添加到积压订单中。</li>
</ul>

<p>输入所有订单后，返回积压订单中的 <strong>订单总数</strong> 。由于数字可能很大，所以需要返回对 <code>10<sup>9</sup> + 7</code> 取余的结果。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1800-1899/1801.Number%20of%20Orders%20in%20the%20Backlog/images/ex1.png" style="width: 450px; height: 479px;" />
<pre>
<strong>输入：</strong>orders = [[10,5,0],[15,2,1],[25,1,1],[30,4,0]]
<strong>输出：</strong>6
<strong>解释：</strong>输入订单后会发生下述情况：
- 提交 5 笔采购订单，价格为 10 。没有销售订单，所以这 5 笔订单添加到积压订单中。
- 提交 2 笔销售订单，价格为 15 。没有采购订单的价格大于或等于 15 ，所以这 2 笔订单添加到积压订单中。
- 提交 1 笔销售订单，价格为 25 。没有采购订单的价格大于或等于 25 ，所以这 1 笔订单添加到积压订单中。
- 提交 4 笔采购订单，价格为 30 。前 2 笔采购订单与价格最低（价格为 15）的 2 笔销售订单匹配，从积压订单中删除这 2 笔销售订单。第 3 笔采购订单与价格最低的 1 笔销售订单匹配，销售订单价格为 25 ，从积压订单中删除这 1 笔销售订单。积压订单中不存在更多销售订单，所以第 4 笔采购订单需要添加到积压订单中。
最终，积压订单中有 5 笔价格为 10 的采购订单，和 1 笔价格为 30 的采购订单。所以积压订单中的订单总数为 6 。
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1800-1899/1801.Number%20of%20Orders%20in%20the%20Backlog/images/ex2.png" style="width: 450px; height: 584px;" />
<pre>
<strong>输入：</strong>orders = [[7,1000000000,1],[15,3,0],[5,999999995,0],[5,1,1]]
<strong>输出：</strong>999999984
<strong>解释：</strong>输入订单后会发生下述情况：
- 提交 10<sup>9</sup> 笔销售订单，价格为 7 。没有采购订单，所以这 10<sup>9</sup> 笔订单添加到积压订单中。
- 提交 3 笔采购订单，价格为 15 。这些采购订单与价格最低（价格为 7 ）的 3 笔销售订单匹配，从积压订单中删除这 3 笔销售订单。
- 提交 999999995 笔采购订单，价格为 5 。销售订单的最低价为 7 ，所以这 999999995 笔订单添加到积压订单中。
- 提交 1 笔销售订单，价格为 5 。这笔销售订单与价格最高（价格为 5 ）的 1 笔采购订单匹配，从积压订单中删除这 1 笔采购订单。
最终，积压订单中有 (1000000000-3) 笔价格为 7 的销售订单，和 (999999995-1) 笔价格为 5 的采购订单。所以积压订单中的订单总数为 1999999991 ，等于 999999984 % (10<sup>9</sup> + 7) 。</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= orders.length <= 10<sup>5</sup></code></li>
	<li><code>orders[i].length == 3</code></li>
	<li><code>1 <= price<sub>i</sub>, amount<sub>i</sub> <= 10<sup>9</sup></code></li>
	<li><code>orderType<sub>i</sub></code> 为 <code>0</code> 或 <code>1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：优先队列（大小根堆） + 模拟

我们可以使用优先队列（大小根堆）维护当前的积压订单，其中大根堆 `buy` 维护积压的采购订单，小根堆 `sell` 维护积压的销售订单。堆中每个元素是一个二元组 $(price, amount)$，表示价格为 `price` 的订单数量为 `amount`。

接下来，我们遍历订单数组 `orders` ，根据题意模拟即可。

遍历结束后，我们将 `buy` 和 `sell` 中的订单数量相加，即为最终的积压订单数量。注意答案可能很大，需要对 $10^9 + 7$ 取模。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 是 `orders` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def getNumberOfBacklogOrders(self, orders: List[List[int]]) -> int:
        buy, sell = [], []
        for p, a, t in orders:
            if t == 0:
                while a and sell and sell[0][0] <= p:
                    x, y = heappop(sell)
                    if a >= y:
                        a -= y
                    else:
                        heappush(sell, (x, y - a))
                        a = 0
                if a:
                    heappush(buy, (-p, a))
            else:
                while a and buy and -buy[0][0] >= p:
                    x, y = heappop(buy)
                    if a >= y:
                        a -= y
                    else:
                        heappush(buy, (x, y - a))
                        a = 0
                if a:
                    heappush(sell, (p, a))
        mod = 10**9 + 7
        return sum(v[1] for v in buy + sell) % mod
```

#### Java

```java
class Solution {
    public int getNumberOfBacklogOrders(int[][] orders) {
        PriorityQueue<int[]> buy = new PriorityQueue<>((a, b) -> b[0] - a[0]);
        PriorityQueue<int[]> sell = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        for (var e : orders) {
            int p = e[0], a = e[1], t = e[2];
            if (t == 0) {
                while (a > 0 && !sell.isEmpty() && sell.peek()[0] <= p) {
                    var q = sell.poll();
                    int x = q[0], y = q[1];
                    if (a >= y) {
                        a -= y;
                    } else {
                        sell.offer(new int[] {x, y - a});
                        a = 0;
                    }
                }
                if (a > 0) {
                    buy.offer(new int[] {p, a});
                }
            } else {
                while (a > 0 && !buy.isEmpty() && buy.peek()[0] >= p) {
                    var q = buy.poll();
                    int x = q[0], y = q[1];
                    if (a >= y) {
                        a -= y;
                    } else {
                        buy.offer(new int[] {x, y - a});
                        a = 0;
                    }
                }
                if (a > 0) {
                    sell.offer(new int[] {p, a});
                }
            }
        }
        long ans = 0;
        final int mod = (int) 1e9 + 7;
        while (!buy.isEmpty()) {
            ans += buy.poll()[1];
        }
        while (!sell.isEmpty()) {
            ans += sell.poll()[1];
        }
        return (int) (ans % mod);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        using pii = pair<int, int>;
        priority_queue<pii, vector<pii>, greater<pii>> sell;
        priority_queue<pii> buy;
        for (auto& e : orders) {
            int p = e[0], a = e[1], t = e[2];
            if (t == 0) {
                while (a && !sell.empty() && sell.top().first <= p) {
                    auto [x, y] = sell.top();
                    sell.pop();
                    if (a >= y) {
                        a -= y;
                    } else {
                        sell.push({x, y - a});
                        a = 0;
                    }
                }
                if (a) {
                    buy.push({p, a});
                }
            } else {
                while (a && !buy.empty() && buy.top().first >= p) {
                    auto [x, y] = buy.top();
                    buy.pop();
                    if (a >= y) {
                        a -= y;
                    } else {
                        buy.push({x, y - a});
                        a = 0;
                    }
                }
                if (a) {
                    sell.push({p, a});
                }
            }
        }
        long ans = 0;
        while (!buy.empty()) {
            ans += buy.top().second;
            buy.pop();
        }
        while (!sell.empty()) {
            ans += sell.top().second;
            sell.pop();
        }
        const int mod = 1e9 + 7;
        return ans % mod;
    }
};
```

#### Go

```go
func getNumberOfBacklogOrders(orders [][]int) (ans int) {
	sell := hp{}
	buy := hp{}
	for _, e := range orders {
		p, a, t := e[0], e[1], e[2]
		if t == 0 {
			for a > 0 && len(sell) > 0 && sell[0].p <= p {
				q := heap.Pop(&sell).(pair)
				x, y := q.p, q.a
				if a >= y {
					a -= y
				} else {
					heap.Push(&sell, pair{x, y - a})
					a = 0
				}
			}
			if a > 0 {
				heap.Push(&buy, pair{-p, a})
			}
		} else {
			for a > 0 && len(buy) > 0 && -buy[0].p >= p {
				q := heap.Pop(&buy).(pair)
				x, y := q.p, q.a
				if a >= y {
					a -= y
				} else {
					heap.Push(&buy, pair{x, y - a})
					a = 0
				}
			}
			if a > 0 {
				heap.Push(&sell, pair{p, a})
			}
		}
	}
	const mod int = 1e9 + 7
	for len(buy) > 0 {
		ans += heap.Pop(&buy).(pair).a
	}
	for len(sell) > 0 {
		ans += heap.Pop(&sell).(pair).a
	}
	return ans % mod
}

type pair struct{ p, a int }
type hp []pair

func (h hp) Len() int           { return len(h) }
func (h hp) Less(i, j int) bool { return h[i].p < h[j].p }
func (h hp) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *hp) Push(v any)        { *h = append(*h, v.(pair)) }
func (h *hp) Pop() any          { a := *h; v := a[len(a)-1]; *h = a[:len(a)-1]; return v }
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1802. 有界数组中指定下标处的最大值](https://leetcode.cn/problems/maximum-value-at-a-given-index-in-a-bounded-array){#1802}

{{< tabs "1802" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxValue(self, n: int, index: int, maxSum: int) -> int:
        def sum(x, cnt):
            return (
                (x + x - cnt + 1) * cnt // 2 if x >= cnt else (x + 1) * x // 2 + cnt - x
            )

        left, right = 1, maxSum
        while left < right:
            mid = (left + right + 1) >> 1
            if sum(mid - 1, index) + sum(mid, n - index) <= maxSum:
                left = mid
            else:
                right = mid - 1
        return left
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxValue(int n, int index, int maxSum) {
        int left = 1, right = maxSum;
        while (left < right) {
            int mid = (left + right + 1) >>> 1;
            if (sum(mid - 1, index) + sum(mid, n - index) <= maxSum) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }

    private long sum(long x, int cnt) {
        return x >= cnt ? (x + x - cnt + 1) * cnt / 2 : (x + 1) * x / 2 + cnt - x;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        auto sum = [](long x, int cnt) {
            return x >= cnt ? (x + x - cnt + 1) * cnt / 2 : (x + 1) * x / 2 + cnt - x;
        };
        int left = 1, right = maxSum;
        while (left < right) {
            int mid = (left + right + 1) >> 1;
            if (sum(mid - 1, index) + sum(mid, n - index) <= maxSum) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxValue(n int, index int, maxSum int) int {
	sum := func(x, cnt int) int {
		if x >= cnt {
			return (x + x - cnt + 1) * cnt / 2
		}
		return (x+1)*x/2 + cnt - x
	}
	return sort.Search(maxSum, func(x int) bool {
		x++
		return sum(x-1, index)+sum(x, n-index) > maxSum
	})
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你三个正整数 <code>n</code>、<code>index</code> 和 <code>maxSum</code> 。你需要构造一个同时满足下述所有条件的数组 <code>nums</code>（下标 <strong>从 0 开始</strong> 计数）：</p>

<ul>
	<li><code>nums.length == n</code></li>
	<li><code>nums[i]</code> 是 <strong>正整数</strong> ，其中 <code>0 &lt;= i &lt; n</code></li>
	<li><code>abs(nums[i] - nums[i+1]) &lt;= 1</code> ，其中 <code>0 &lt;= i &lt; n-1</code></li>
	<li><code>nums</code> 中所有元素之和不超过 <code>maxSum</code></li>
	<li><code>nums[index]</code> 的值被 <strong>最大化</strong></li>
</ul>

<p>返回你所构造的数组中的 <code>nums[index]</code> 。</p>

<p>注意：<code>abs(x)</code> 等于 <code>x</code> 的前提是 <code>x &gt;= 0</code> ；否则，<code>abs(x)</code> 等于 <code>-x</code> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>n = 4, index = 2,  maxSum = 6
<strong>输出：</strong>2
<strong>解释：</strong>数组 [1,1,<strong>2</strong>,1] 和 [1,2,<strong>2</strong>,1] 满足所有条件。不存在其他在指定下标处具有更大值的有效数组。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>n = 6, index = 1,  maxSum = 10
<strong>输出：</strong>3
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= maxSum &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= index &lt; n</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二分查找

根据题目描述，如果我们确定了 $nums[index]$ 的值为 $x$，此时我们可以找到一个最小的数组总和。也就是说，在 $index$ 左侧的数组元素从 $x-1$ 一直递减到 $1$，如果还有剩余的元素，那么剩余的元素都为 $1$；同理，在 $index$ 及右侧的数组元素从 $x$ 一直递减到 $1$，如果还有剩余的元素，那么剩余的元素都为 $1$。

这样我们就可以计算出数组的总和，如果总和小于等于 $maxSum$，那么此时的 $x$ 是合法的。随着 $x$ 的增大，数组的总和也会增大，因此我们可以使用二分查找的方法，找到一个最大的且符合条件的 $x$。

为了方便计算数组左侧、右侧的元素之和，我们定义一个函数 $sum(x, cnt)$，表示一共有 $cnt$ 个元素，且最大值为 $x$ 的数组的总和。函数 $sum(x, cnt)$ 可以分为两种情况：

-   如果 $x \geq cnt$，那么数组的总和为 $\frac{(x + x - cnt + 1) \times cnt}{2}$
-   如果 $x \lt cnt$，那么数组的总和为 $\frac{(x + 1) \times x}{2} + cnt - x$

接下来，定义二分的左边界 $left = 1$，右边界 $right = maxSum$，然后二分查找 $nums[index]$ 的值 $mid$，如果 $sum(mid - 1, index) + sum(mid, n - index) \leq maxSum$，那么此时的 $mid$ 是合法的，我们可以将 $left$ 更新为 $mid$，否则我们将 $right$ 更新为 $mid - 1$。

最后将 $left$ 作为答案返回即可。

时间复杂度 $O(\log M)$，其中 $M=maxSum$。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxValue(self, n: int, index: int, maxSum: int) -> int:
        def sum(x, cnt):
            return (
                (x + x - cnt + 1) * cnt // 2 if x >= cnt else (x + 1) * x // 2 + cnt - x
            )

        left, right = 1, maxSum
        while left < right:
            mid = (left + right + 1) >> 1
            if sum(mid - 1, index) + sum(mid, n - index) <= maxSum:
                left = mid
            else:
                right = mid - 1
        return left
```

#### Java

```java
class Solution {
    public int maxValue(int n, int index, int maxSum) {
        int left = 1, right = maxSum;
        while (left < right) {
            int mid = (left + right + 1) >>> 1;
            if (sum(mid - 1, index) + sum(mid, n - index) <= maxSum) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }

    private long sum(long x, int cnt) {
        return x >= cnt ? (x + x - cnt + 1) * cnt / 2 : (x + 1) * x / 2 + cnt - x;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        auto sum = [](long x, int cnt) {
            return x >= cnt ? (x + x - cnt + 1) * cnt / 2 : (x + 1) * x / 2 + cnt - x;
        };
        int left = 1, right = maxSum;
        while (left < right) {
            int mid = (left + right + 1) >> 1;
            if (sum(mid - 1, index) + sum(mid, n - index) <= maxSum) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};
```

#### Go

```go
func maxValue(n int, index int, maxSum int) int {
	sum := func(x, cnt int) int {
		if x >= cnt {
			return (x + x - cnt + 1) * cnt / 2
		}
		return (x+1)*x/2 + cnt - x
	}
	return sort.Search(maxSum, func(x int) bool {
		x++
		return sum(x-1, index)+sum(x, n-index) > maxSum
	})
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1803. 统计异或值在范围内的数对有多少](https://leetcode.cn/problems/count-pairs-with-xor-in-a-range){#1803}

{{< tabs "1803" >}}

{{% tab "python" %}}
```python
class Trie:
    def __init__(self):
        self.children = [None] * 2
        self.cnt = 0

    def insert(self, x):
        node = self
        for i in range(15, -1, -1):
            v = x >> i & 1
            if node.children[v] is None:
                node.children[v] = Trie()
            node = node.children[v]
            node.cnt += 1

    def search(self, x, limit):
        node = self
        ans = 0
        for i in range(15, -1, -1):
            if node is None:
                return ans
            v = x >> i & 1
            if limit >> i & 1:
                if node.children[v]:
                    ans += node.children[v].cnt
                node = node.children[v ^ 1]
            else:
                node = node.children[v]
        return ans


class Solution:
    def countPairs(self, nums: List[int], low: int, high: int) -> int:
        ans = 0
        tree = Trie()
        for x in nums:
            ans += tree.search(x, high + 1) - tree.search(x, low)
            tree.insert(x)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Trie {
    private Trie[] children = new Trie[2];
    private int cnt;

    public void insert(int x) {
        Trie node = this;
        for (int i = 15; i >= 0; --i) {
            int v = (x >> i) & 1;
            if (node.children[v] == null) {
                node.children[v] = new Trie();
            }
            node = node.children[v];
            ++node.cnt;
        }
    }

    public int search(int x, int limit) {
        Trie node = this;
        int ans = 0;
        for (int i = 15; i >= 0 && node != null; --i) {
            int v = (x >> i) & 1;
            if (((limit >> i) & 1) == 1) {
                if (node.children[v] != null) {
                    ans += node.children[v].cnt;
                }
                node = node.children[v ^ 1];
            } else {
                node = node.children[v];
            }
        }
        return ans;
    }
}

class Solution {
    public int countPairs(int[] nums, int low, int high) {
        Trie trie = new Trie();
        int ans = 0;
        for (int x : nums) {
            ans += trie.search(x, high + 1) - trie.search(x, low);
            trie.insert(x);
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Trie {
public:
    Trie()
        : children(2)
        , cnt(0) {}

    void insert(int x) {
        Trie* node = this;
        for (int i = 15; ~i; --i) {
            int v = x >> i & 1;
            if (!node->children[v]) {
                node->children[v] = new Trie();
            }
            node = node->children[v];
            ++node->cnt;
        }
    }

    int search(int x, int limit) {
        Trie* node = this;
        int ans = 0;
        for (int i = 15; ~i && node; --i) {
            int v = x >> i & 1;
            if (limit >> i & 1) {
                if (node->children[v]) {
                    ans += node->children[v]->cnt;
                }
                node = node->children[v ^ 1];
            } else {
                node = node->children[v];
            }
        }
        return ans;
    }

private:
    vector<Trie*> children;
    int cnt;
};

class Solution {
public:
    int countPairs(vector<int>& nums, int low, int high) {
        Trie* tree = new Trie();
        int ans = 0;
        for (int& x : nums) {
            ans += tree->search(x, high + 1) - tree->search(x, low);
            tree->insert(x);
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
	cnt      int
}

func newTrie() *Trie {
	return &Trie{}
}

func (this *Trie) insert(x int) {
	node := this
	for i := 15; i >= 0; i-- {
		v := (x >> i) & 1
		if node.children[v] == nil {
			node.children[v] = newTrie()
		}
		node = node.children[v]
		node.cnt++
	}
}

func (this *Trie) search(x, limit int) (ans int) {
	node := this
	for i := 15; i >= 0 && node != nil; i-- {
		v := (x >> i) & 1
		if (limit >> i & 1) == 1 {
			if node.children[v] != nil {
				ans += node.children[v].cnt
			}
			node = node.children[v^1]
		} else {
			node = node.children[v]
		}
	}
	return
}

func countPairs(nums []int, low int, high int) (ans int) {
	tree := newTrie()
	for _, x := range nums {
		ans += tree.search(x, high+1) - tree.search(x, low)
		tree.insert(x)
	}
	return
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>nums</code> （下标 <strong>从 0 开始</strong> 计数）以及两个整数：<code>low</code> 和 <code>high</code> ，请返回 <strong>漂亮数对</strong> 的数目。</p>

<p><strong>漂亮数对</strong> 是一个形如 <code>(i, j)</code> 的数对，其中 <code>0 &lt;= i &lt; j &lt; nums.length</code> 且 <code>low &lt;= (nums[i] XOR nums[j]) &lt;= high</code> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [1,4,2,7], low = 2, high = 6
<strong>输出：</strong>6
<strong>解释：</strong>所有漂亮数对 (i, j) 列出如下：
    - (0, 1): nums[0] XOR nums[1] = 5 
    - (0, 2): nums[0] XOR nums[2] = 3
    - (0, 3): nums[0] XOR nums[3] = 6
    - (1, 2): nums[1] XOR nums[2] = 6
    - (1, 3): nums[1] XOR nums[3] = 3
    - (2, 3): nums[2] XOR nums[3] = 5
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [9,8,4,2,1], low = 5, high = 14
<strong>输出：</strong>8
<strong>解释：</strong>所有漂亮数对 (i, j) 列出如下：
​​​​​    - (0, 2): nums[0] XOR nums[2] = 13
    - (0, 3): nums[0] XOR nums[3] = 11
    - (0, 4): nums[0] XOR nums[4] = 8
    - (1, 2): nums[1] XOR nums[2] = 12
    - (1, 3): nums[1] XOR nums[3] = 10
    - (1, 4): nums[1] XOR nums[4] = 9
    - (2, 3): nums[2] XOR nums[3] = 6
    - (2, 4): nums[2] XOR nums[4] = 5</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= low &lt;= high &lt;= 2 * 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：0-1 字典树

对于这种区间 $[low, high]$ 统计的问题，我们可以考虑将其转换为统计 $[0, high]$ 和 $[0, low - 1]$ 的问题，然后相减即可得到答案。

在这道题中，我们可以统计有多少数对的异或值小于 $high+1$，然后再统计有多少数对的异或值小于 $low$，相减的结果就是异或值在区间 $[low, high]$ 之间的数对数量。

另外，对于数组异或计数问题，我们通常可以使用“0-1 字典树”来解决。

字典树的节点定义如下：

-   `children[0]` 和 `children[1]` 分别表示当前节点的左右子节点；
-   `cnt` 表示以当前节点为结尾的数的数量。

在字典树中，我们还定义了以下两个函数：

其中一个函数是 $insert(x)$，表示将数 $x$ 插入到字典树中。该函数将数字 $x$ 按照二进制位从高到低的顺序，插入到“0-1 字典树”中。如果当前二进制位为 $0$，则插入到左子节点，否则插入到右子节点。然后将节点的计数值 $cnt$ 加 $1$。

另一个函数是 $search(x, limit)$，表示在字典树中查找与 $x$ 异或值小于 $limit$ 的数量。该函数从字典树的根节点 `node` 开始，遍历 $x$ 的二进制位，从高到低，记当前 $x$ 的二进制位的数为 $v$。如果当前 $limit$ 的二进制位为 $1$，此时我们可以直接将答案加上与 $x$ 的当前二进制位 $v$ 相同的子节点的计数值 $cnt$，然后将当前节点移动到与 $x$ 的当前二进制位 $v$ 不同的子节点，即 `node = node.children[v ^ 1]`。继续遍历下一位。如果当前 $limit$ 的二进制位为 $0$，此时我们只能将当前节点移动到与 $x$ 的当前二进制位 $v$ 相同的子节点，即 `node = node.children[v]`。继续遍历下一位。遍历完 $x$ 的二进制位后，返回答案。

有了以上两个函数，我们就可以解决本题了。

我们遍历数组 `nums`，对于每个数 $x$，我们先在字典树中查找与 $x$ 异或值小于 $high+1$ 的数量，然后在字典树中查找与 $x$ 异或值小于 $low$ 的数对数量，将两者的差值加到答案中。接着将 $x$ 插入到字典树中。继续遍历下一个数 $x$，直到遍历完数组 `nums`。最后返回答案即可。

时间复杂度 $O(n \times \log M)$，空间复杂度 $O(n \times \log M)$。其中 $n$ 为数组 `nums` 的长度，而 $M$ 为数组 `nums` 中的最大值。本题中我们直接取 $\log M = 16$。

<!-- tabs:start -->

#### Python3

```python
class Trie:
    def __init__(self):
        self.children = [None] * 2
        self.cnt = 0

    def insert(self, x):
        node = self
        for i in range(15, -1, -1):
            v = x >> i & 1
            if node.children[v] is None:
                node.children[v] = Trie()
            node = node.children[v]
            node.cnt += 1

    def search(self, x, limit):
        node = self
        ans = 0
        for i in range(15, -1, -1):
            if node is None:
                return ans
            v = x >> i & 1
            if limit >> i & 1:
                if node.children[v]:
                    ans += node.children[v].cnt
                node = node.children[v ^ 1]
            else:
                node = node.children[v]
        return ans


class Solution:
    def countPairs(self, nums: List[int], low: int, high: int) -> int:
        ans = 0
        tree = Trie()
        for x in nums:
            ans += tree.search(x, high + 1) - tree.search(x, low)
            tree.insert(x)
        return ans
```

#### Java

```java
class Trie {
    private Trie[] children = new Trie[2];
    private int cnt;

    public void insert(int x) {
        Trie node = this;
        for (int i = 15; i >= 0; --i) {
            int v = (x >> i) & 1;
            if (node.children[v] == null) {
                node.children[v] = new Trie();
            }
            node = node.children[v];
            ++node.cnt;
        }
    }

    public int search(int x, int limit) {
        Trie node = this;
        int ans = 0;
        for (int i = 15; i >= 0 && node != null; --i) {
            int v = (x >> i) & 1;
            if (((limit >> i) & 1) == 1) {
                if (node.children[v] != null) {
                    ans += node.children[v].cnt;
                }
                node = node.children[v ^ 1];
            } else {
                node = node.children[v];
            }
        }
        return ans;
    }
}

class Solution {
    public int countPairs(int[] nums, int low, int high) {
        Trie trie = new Trie();
        int ans = 0;
        for (int x : nums) {
            ans += trie.search(x, high + 1) - trie.search(x, low);
            trie.insert(x);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Trie {
public:
    Trie()
        : children(2)
        , cnt(0) {}

    void insert(int x) {
        Trie* node = this;
        for (int i = 15; ~i; --i) {
            int v = x >> i & 1;
            if (!node->children[v]) {
                node->children[v] = new Trie();
            }
            node = node->children[v];
            ++node->cnt;
        }
    }

    int search(int x, int limit) {
        Trie* node = this;
        int ans = 0;
        for (int i = 15; ~i && node; --i) {
            int v = x >> i & 1;
            if (limit >> i & 1) {
                if (node->children[v]) {
                    ans += node->children[v]->cnt;
                }
                node = node->children[v ^ 1];
            } else {
                node = node->children[v];
            }
        }
        return ans;
    }

private:
    vector<Trie*> children;
    int cnt;
};

class Solution {
public:
    int countPairs(vector<int>& nums, int low, int high) {
        Trie* tree = new Trie();
        int ans = 0;
        for (int& x : nums) {
            ans += tree->search(x, high + 1) - tree->search(x, low);
            tree->insert(x);
        }
        return ans;
    }
};
```

#### Go

```go
type Trie struct {
	children [2]*Trie
	cnt      int
}

func newTrie() *Trie {
	return &Trie{}
}

func (this *Trie) insert(x int) {
	node := this
	for i := 15; i >= 0; i-- {
		v := (x >> i) & 1
		if node.children[v] == nil {
			node.children[v] = newTrie()
		}
		node = node.children[v]
		node.cnt++
	}
}

func (this *Trie) search(x, limit int) (ans int) {
	node := this
	for i := 15; i >= 0 && node != nil; i-- {
		v := (x >> i) & 1
		if (limit >> i & 1) == 1 {
			if node.children[v] != nil {
				ans += node.children[v].cnt
			}
			node = node.children[v^1]
		} else {
			node = node.children[v]
		}
	}
	return
}

func countPairs(nums []int, low int, high int) (ans int) {
	tree := newTrie()
	for _, x := range nums {
		ans += tree.search(x, high+1) - tree.search(x, low)
		tree.insert(x)
	}
	return
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1804. 实现 Trie （前缀树） II 🔒](https://leetcode.cn/problems/implement-trie-ii-prefix-tree){#1804}

{{< tabs "1804" >}}

{{% tab "python" %}}
```python
class Trie:
    def __init__(self):
        self.children = [None] * 26
        self.v = self.pv = 0

    def insert(self, word: str) -> None:
        node = self
        for c in word:
            idx = ord(c) - ord('a')
            if node.children[idx] is None:
                node.children[idx] = Trie()
            node = node.children[idx]
            node.pv += 1
        node.v += 1

    def countWordsEqualTo(self, word: str) -> int:
        node = self.search(word)
        return 0 if node is None else node.v

    def countWordsStartingWith(self, prefix: str) -> int:
        node = self.search(prefix)
        return 0 if node is None else node.pv

    def erase(self, word: str) -> None:
        node = self
        for c in word:
            idx = ord(c) - ord('a')
            node = node.children[idx]
            node.pv -= 1
        node.v -= 1

    def search(self, word):
        node = self
        for c in word:
            idx = ord(c) - ord('a')
            if node.children[idx] is None:
                return None
            node = node.children[idx]
        return node


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.countWordsEqualTo(word)
# param_3 = obj.countWordsStartingWith(prefix)
# obj.erase(word)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Trie {
    private Trie[] children = new Trie[26];
    private int v;
    private int pv;

    public Trie() {
    }

    public void insert(String word) {
        Trie node = this;
        for (char c : word.toCharArray()) {
            c -= 'a';
            if (node.children[c] == null) {
                node.children[c] = new Trie();
            }
            node = node.children[c];
            ++node.pv;
        }
        ++node.v;
    }

    public int countWordsEqualTo(String word) {
        Trie node = search(word);
        return node == null ? 0 : node.v;
    }

    public int countWordsStartingWith(String prefix) {
        Trie node = search(prefix);
        return node == null ? 0 : node.pv;
    }

    public void erase(String word) {
        Trie node = this;
        for (char c : word.toCharArray()) {
            c -= 'a';
            node = node.children[c];
            --node.pv;
        }
        --node.v;
    }

    private Trie search(String word) {
        Trie node = this;
        for (char c : word.toCharArray()) {
            c -= 'a';
            if (node.children[c] == null) {
                return null;
            }
            node = node.children[c];
        }
        return node;
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * int param_2 = obj.countWordsEqualTo(word);
 * int param_3 = obj.countWordsStartingWith(prefix);
 * obj.erase(word);
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Trie {
public:
    Trie()
        : children(26)
        , v(0)
        , pv(0) {
    }

    void insert(string word) {
        Trie* node = this;
        for (char c : word) {
            c -= 'a';
            if (!node->children[c]) {
                node->children[c] = new Trie();
            }
            node = node->children[c];
            ++node->pv;
        }
        ++node->v;
    }

    int countWordsEqualTo(string word) {
        Trie* node = search(word);
        return node ? node->v : 0;
    }

    int countWordsStartingWith(string prefix) {
        Trie* node = search(prefix);
        return node ? node->pv : 0;
    }

    void erase(string word) {
        Trie* node = this;
        for (char c : word) {
            c -= 'a';
            node = node->children[c];
            --node->pv;
        }
        --node->v;
    }

private:
    vector<Trie*> children;
    int v, pv;

    Trie* search(string& word) {
        Trie* node = this;
        for (char c : word) {
            c -= 'a';
            if (!node->children[c]) {
                return nullptr;
            }
            node = node->children[c];
        }
        return node;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * int param_2 = obj->countWordsEqualTo(word);
 * int param_3 = obj->countWordsStartingWith(prefix);
 * obj->erase(word);
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type Trie struct {
	children [26]*Trie
	v        int
	pv       int
}

func Constructor() (_ Trie) { return }

func (this *Trie) Insert(word string) {
	node := this
	for _, c := range word {
		c -= 'a'
		if node.children[c] == nil {
			node.children[c] = &Trie{}
		}
		node = node.children[c]
		node.pv++
	}
	node.v++
}

func (this *Trie) CountWordsEqualTo(word string) int {
	node := this.search(word)
	if node == nil {
		return 0
	}
	return node.v
}

func (this *Trie) CountWordsStartingWith(prefix string) int {
	node := this.search(prefix)
	if node == nil {
		return 0
	}
	return node.pv
}

func (this *Trie) Erase(word string) {
	node := this
	for _, c := range word {
		c -= 'a'
		node = node.children[c]
		node.pv--
	}
	node.v--
}

func (this *Trie) search(word string) *Trie {
	node := this
	for _, c := range word {
		c -= 'a'
		if node.children[c] == nil {
			return nil
		}
		node = node.children[c]
	}
	return node
}

/**
 * Your Trie object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Insert(word);
 * param_2 := obj.CountWordsEqualTo(word);
 * param_3 := obj.CountWordsStartingWith(prefix);
 * obj.Erase(word);
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>前缀树（<strong><a href="https://en.wikipedia.org/wiki/Trie" target="_blank">trie</a></strong> ，发音为 "try"）是一个树状的数据结构，用于高效地存储和检索一系列字符串的前缀。前缀树有许多应用，如自动补全和拼写检查。</p>

<p>实现前缀树 Trie 类：</p>

<ul>
	<li><code>Trie()</code> 初始化前缀树对象。</li>
	<li><code>void insert(String word)</code> 将字符串 <code>word</code> 插入前缀树中。</li>
	<li><code>int countWordsEqualTo(String word)</code> 返回前缀树中字符串 <code>word</code> 的实例个数。</li>
	<li><code>int countWordsStartingWith(String prefix)</code> 返回前缀树中以 <code>prefix</code> 为前缀的字符串个数。</li>
	<li><code>void erase(String word)</code> 从前缀树中移除字符串 <code>word</code> 。</li>
</ul>

<p> </p>

<p><strong>示例 1:</strong></p>

<pre><b>输入</b>
["Trie", "insert", "insert", "countWordsEqualTo", "countWordsStartingWith", "erase", "countWordsEqualTo", "countWordsStartingWith", "erase", "countWordsStartingWith"]
[[], ["apple"], ["apple"], ["apple"], ["app"], ["apple"], ["apple"], ["app"], ["apple"], ["app"]]
<b>输出</b>
[null, null, null, 2, 2, null, 1, 1, null, 0]

<b>解释</b>
Trie trie = new Trie();
trie.insert("apple");               // 插入 "apple"。
trie.insert("apple");               // 插入另一个 "apple"。
trie.countWordsEqualTo("apple");    // 有两个 "apple" 实例，所以返回 2。
trie.countWordsStartingWith("app"); // "app" 是 "apple" 的前缀，所以返回 2。
trie.erase("apple");                // 移除一个 "apple"。
trie.countWordsEqualTo("apple");    // 现在只有一个 "apple" 实例，所以返回 1。
trie.countWordsStartingWith("app"); // 返回 1
trie.erase("apple");                // 移除 "apple"。现在前缀树是空的。
trie.countWordsStartingWith("app"); // 返回 0
</pre>

<p> </p>

<p><b>提示：</b></p>

<ul>
	<li><code>1 &lt;= word.length, prefix.length &lt;= 2000</code></li>
	<li><code>word</code> 和 <code>prefix</code> 只包含小写英文字母。</li>
	<li><code>insert</code>、 <code>countWordsEqualTo</code>、 <code>countWordsStartingWith</code> 和 <code>erase</code> <strong>总共</strong>调用最多 <code>3 * 10<sup>4</sup></code> 次。</li>
	<li>保证每次调用 <code>erase</code> 时，字符串 <code>word</code> 总是存在于前缀树中。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数组实现前缀树

前缀树每个节点包括三部分：

1. 指向子节点的指针数组 children，对于本题而言，数组长度为 26，即小写英文字母的数量。`children[0]` 对应小写字母 a，...，`children[25]` 对应小写字母 z。
1. int 变量 `v`，表示以该节点结尾的字符串个数。
1. int 变量 `pv`，表示以该节点作为前缀节点的字符串个数。

### 1. 插入字符串

我们从字典树的根开始，插入字符串。对于当前字符对应的子节点，有两种情况：

-   子节点存在。沿着指针移动到子节点，继续处理下一个字符。
-   子节点不存在。创建一个新的子节点，记录在 `children` 数组的对应位置上，然后沿着指针移动到子节点，让子节点的 `pv` 值加 1。继续搜索下一个字符。

重复以上步骤，直到处理字符串的最后一个字符，然后将当前节点的 `v` 值加 1。

时间复杂度 $O(n)$，其中 $n$ 为字符串的长度。

### 2. 查找前缀

我们从字典树的根开始，查找前缀。对于当前字符对应的子节点，有两种情况：

-   子节点存在。沿着指针移动到子节点，继续搜索下一个字符。
-   子节点不存在。说明字典树中不包含该前缀，返回空指针。

重复以上步骤，直到返回空指针或搜索完前缀的最后一个字符。

时间复杂度 $O(n)$，其中 $n$ 为字符串的长度。

### 3. 移除字符串

我们从字典树的根节点开始，依次将对应的子节点的 `pv` 值减 1，直到搜索完字符串的最后一个字符。然后将当前节点的 `v` 值减 1。

时间复杂度 $O(n)$，其中 $n$ 为字符串的长度。

<!-- tabs:start -->

#### Python3

```python
class Trie:
    def __init__(self):
        self.children = [None] * 26
        self.v = self.pv = 0

    def insert(self, word: str) -> None:
        node = self
        for c in word:
            idx = ord(c) - ord('a')
            if node.children[idx] is None:
                node.children[idx] = Trie()
            node = node.children[idx]
            node.pv += 1
        node.v += 1

    def countWordsEqualTo(self, word: str) -> int:
        node = self.search(word)
        return 0 if node is None else node.v

    def countWordsStartingWith(self, prefix: str) -> int:
        node = self.search(prefix)
        return 0 if node is None else node.pv

    def erase(self, word: str) -> None:
        node = self
        for c in word:
            idx = ord(c) - ord('a')
            node = node.children[idx]
            node.pv -= 1
        node.v -= 1

    def search(self, word):
        node = self
        for c in word:
            idx = ord(c) - ord('a')
            if node.children[idx] is None:
                return None
            node = node.children[idx]
        return node


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.countWordsEqualTo(word)
# param_3 = obj.countWordsStartingWith(prefix)
# obj.erase(word)
```

#### Java

```java
class Trie {
    private Trie[] children = new Trie[26];
    private int v;
    private int pv;

    public Trie() {
    }

    public void insert(String word) {
        Trie node = this;
        for (char c : word.toCharArray()) {
            c -= 'a';
            if (node.children[c] == null) {
                node.children[c] = new Trie();
            }
            node = node.children[c];
            ++node.pv;
        }
        ++node.v;
    }

    public int countWordsEqualTo(String word) {
        Trie node = search(word);
        return node == null ? 0 : node.v;
    }

    public int countWordsStartingWith(String prefix) {
        Trie node = search(prefix);
        return node == null ? 0 : node.pv;
    }

    public void erase(String word) {
        Trie node = this;
        for (char c : word.toCharArray()) {
            c -= 'a';
            node = node.children[c];
            --node.pv;
        }
        --node.v;
    }

    private Trie search(String word) {
        Trie node = this;
        for (char c : word.toCharArray()) {
            c -= 'a';
            if (node.children[c] == null) {
                return null;
            }
            node = node.children[c];
        }
        return node;
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * int param_2 = obj.countWordsEqualTo(word);
 * int param_3 = obj.countWordsStartingWith(prefix);
 * obj.erase(word);
 */
```

#### C++

```cpp
class Trie {
public:
    Trie()
        : children(26)
        , v(0)
        , pv(0) {
    }

    void insert(string word) {
        Trie* node = this;
        for (char c : word) {
            c -= 'a';
            if (!node->children[c]) {
                node->children[c] = new Trie();
            }
            node = node->children[c];
            ++node->pv;
        }
        ++node->v;
    }

    int countWordsEqualTo(string word) {
        Trie* node = search(word);
        return node ? node->v : 0;
    }

    int countWordsStartingWith(string prefix) {
        Trie* node = search(prefix);
        return node ? node->pv : 0;
    }

    void erase(string word) {
        Trie* node = this;
        for (char c : word) {
            c -= 'a';
            node = node->children[c];
            --node->pv;
        }
        --node->v;
    }

private:
    vector<Trie*> children;
    int v, pv;

    Trie* search(string& word) {
        Trie* node = this;
        for (char c : word) {
            c -= 'a';
            if (!node->children[c]) {
                return nullptr;
            }
            node = node->children[c];
        }
        return node;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * int param_2 = obj->countWordsEqualTo(word);
 * int param_3 = obj->countWordsStartingWith(prefix);
 * obj->erase(word);
 */
```

#### Go

```go
type Trie struct {
	children [26]*Trie
	v        int
	pv       int
}

func Constructor() (_ Trie) { return }

func (this *Trie) Insert(word string) {
	node := this
	for _, c := range word {
		c -= 'a'
		if node.children[c] == nil {
			node.children[c] = &Trie{}
		}
		node = node.children[c]
		node.pv++
	}
	node.v++
}

func (this *Trie) CountWordsEqualTo(word string) int {
	node := this.search(word)
	if node == nil {
		return 0
	}
	return node.v
}

func (this *Trie) CountWordsStartingWith(prefix string) int {
	node := this.search(prefix)
	if node == nil {
		return 0
	}
	return node.pv
}

func (this *Trie) Erase(word string) {
	node := this
	for _, c := range word {
		c -= 'a'
		node = node.children[c]
		node.pv--
	}
	node.v--
}

func (this *Trie) search(word string) *Trie {
	node := this
	for _, c := range word {
		c -= 'a'
		if node.children[c] == nil {
			return nil
		}
		node = node.children[c]
	}
	return node
}

/**
 * Your Trie object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Insert(word);
 * param_2 := obj.CountWordsEqualTo(word);
 * param_3 := obj.CountWordsStartingWith(prefix);
 * obj.Erase(word);
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1805. 字符串中不同整数的数目](https://leetcode.cn/problems/number-of-different-integers-in-a-string){#1805}

{{< tabs "1805" >}}

{{% tab "python" %}}
```python
class Solution:
    def numDifferentIntegers(self, word: str) -> int:
        s = set()
        i, n = 0, len(word)
        while i < n:
            if word[i].isdigit():
                while i < n and word[i] == '0':
                    i += 1
                j = i
                while j < n and word[j].isdigit():
                    j += 1
                s.add(word[i:j])
                i = j
            i += 1
        return len(s)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numDifferentIntegers(String word) {
        Set<String> s = new HashSet<>();
        int n = word.length();
        for (int i = 0; i < n; ++i) {
            if (Character.isDigit(word.charAt(i))) {
                while (i < n && word.charAt(i) == '0') {
                    ++i;
                }
                int j = i;
                while (j < n && Character.isDigit(word.charAt(j))) {
                    ++j;
                }
                s.add(word.substring(i, j));
                i = j;
            }
        }
        return s.size();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_set<string> s;
        int n = word.size();
        for (int i = 0; i < n; ++i) {
            if (isdigit(word[i])) {
                while (i < n && word[i] == '0') ++i;
                int j = i;
                while (j < n && isdigit(word[j])) ++j;
                s.insert(word.substr(i, j - i));
                i = j;
            }
        }
        return s.size();
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numDifferentIntegers(word string) int {
	s := map[string]struct{}{}
	n := len(word)
	for i := 0; i < n; i++ {
		if word[i] >= '0' && word[i] <= '9' {
			for i < n && word[i] == '0' {
				i++
			}
			j := i
			for j < n && word[j] >= '0' && word[j] <= '9' {
				j++
			}
			s[word[i:j]] = struct{}{}
			i = j
		}
	}
	return len(s)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numDifferentIntegers(word: string): number {
    return new Set(
        word
            .replace(/\D+/g, ' ')
            .trim()
            .split(' ')
            .filter(v => v !== '')
            .map(v => v.replace(/^0+/g, '')),
    ).size;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashSet;
impl Solution {
    pub fn num_different_integers(word: String) -> i32 {
        let s = word.as_bytes();
        let n = s.len();
        let mut set = HashSet::new();
        let mut i = 0;
        while i < n {
            if s[i] >= b'0' && s[i] <= b'9' {
                let mut j = i;
                while j < n && s[j] >= b'0' && s[j] <= b'9' {
                    j += 1;
                }
                while i < j - 1 && s[i] == b'0' {
                    i += 1;
                }
                set.insert(String::from_utf8(s[i..j].to_vec()).unwrap());
                i = j;
            } else {
                i += 1;
            }
        }
        set.len() as i32
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串 <code>word</code> ，该字符串由数字和小写英文字母组成。</p>

<p>请你用空格替换每个不是数字的字符。例如，<code>"a123bc34d8ef34"</code> 将会变成 <code>" 123  34 8  34"</code> 。注意，剩下的这些整数为（相邻彼此至少有一个空格隔开）：<code>"123"</code>、<code>"34"</code>、<code>"8"</code> 和 <code>"34"</code> 。</p>

<p>返回对 <code>word</code> 完成替换后形成的 <strong>不同</strong> 整数的数目。</p>

<p>只有当两个整数的 <strong>不含前导零</strong> 的十进制表示不同， 才认为这两个整数也不同。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>word = "a<strong>123</strong>bc<strong>34</strong>d<strong>8</strong>ef<strong>34</strong>"
<strong>输出：</strong>3
<strong>解释：</strong>不同的整数有 "123"、"34" 和 "8" 。注意，"34" 只计数一次。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>word = "leet<strong>1234</strong>code<strong>234</strong>"
<strong>输出：</strong>2
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>word = "a<strong>1</strong>b<strong>01</strong>c<strong>001</strong>"
<strong>输出：</strong>1
<strong>解释：</strong>"1"、"01" 和 "001" 视为同一个整数的十进制表示，因为在比较十进制值时会忽略前导零的存在。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= word.length <= 1000</code></li>
	<li><code>word</code> 由数字和小写英文字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双指针 + 模拟

遍历字符串 `word`，找到每个整数的起始位置和结束位置，截取出这一个子串，将其存入哈希表 $s$ 中。

遍历结束，返回哈希表 $s$ 的大小即可。

> 注意，每个子串所表示的整数可能很大，我们不能直接将其转为整数。因此，我们可以去掉每个子串的前导零之后，再存入哈希表。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为字符串 `word` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numDifferentIntegers(self, word: str) -> int:
        s = set()
        i, n = 0, len(word)
        while i < n:
            if word[i].isdigit():
                while i < n and word[i] == '0':
                    i += 1
                j = i
                while j < n and word[j].isdigit():
                    j += 1
                s.add(word[i:j])
                i = j
            i += 1
        return len(s)
```

#### Java

```java
class Solution {
    public int numDifferentIntegers(String word) {
        Set<String> s = new HashSet<>();
        int n = word.length();
        for (int i = 0; i < n; ++i) {
            if (Character.isDigit(word.charAt(i))) {
                while (i < n && word.charAt(i) == '0') {
                    ++i;
                }
                int j = i;
                while (j < n && Character.isDigit(word.charAt(j))) {
                    ++j;
                }
                s.add(word.substring(i, j));
                i = j;
            }
        }
        return s.size();
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_set<string> s;
        int n = word.size();
        for (int i = 0; i < n; ++i) {
            if (isdigit(word[i])) {
                while (i < n && word[i] == '0') ++i;
                int j = i;
                while (j < n && isdigit(word[j])) ++j;
                s.insert(word.substr(i, j - i));
                i = j;
            }
        }
        return s.size();
    }
};
```

#### Go

```go
func numDifferentIntegers(word string) int {
	s := map[string]struct{}{}
	n := len(word)
	for i := 0; i < n; i++ {
		if word[i] >= '0' && word[i] <= '9' {
			for i < n && word[i] == '0' {
				i++
			}
			j := i
			for j < n && word[j] >= '0' && word[j] <= '9' {
				j++
			}
			s[word[i:j]] = struct{}{}
			i = j
		}
	}
	return len(s)
}
```

#### TypeScript

```ts
function numDifferentIntegers(word: string): number {
    return new Set(
        word
            .replace(/\D+/g, ' ')
            .trim()
            .split(' ')
            .filter(v => v !== '')
            .map(v => v.replace(/^0+/g, '')),
    ).size;
}
```

#### Rust

```rust
use std::collections::HashSet;
impl Solution {
    pub fn num_different_integers(word: String) -> i32 {
        let s = word.as_bytes();
        let n = s.len();
        let mut set = HashSet::new();
        let mut i = 0;
        while i < n {
            if s[i] >= b'0' && s[i] <= b'9' {
                let mut j = i;
                while j < n && s[j] >= b'0' && s[j] <= b'9' {
                    j += 1;
                }
                while i < j - 1 && s[i] == b'0' {
                    i += 1;
                }
                set.insert(String::from_utf8(s[i..j].to_vec()).unwrap());
                i = j;
            } else {
                i += 1;
            }
        }
        set.len() as i32
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1806. 还原排列的最少操作步数](https://leetcode.cn/problems/minimum-number-of-operations-to-reinitialize-a-permutation){#1806}

{{< tabs "1806" >}}

{{% tab "python" %}}
```python
class Solution:
    def reinitializePermutation(self, n: int) -> int:
        ans, i = 0, 1
        while 1:
            ans += 1
            if i < n >> 1:
                i <<= 1
            else:
                i = (i - (n >> 1)) << 1 | 1
            if i == 1:
                return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int reinitializePermutation(int n) {
        int ans = 0;
        for (int i = 1;;) {
            ++ans;
            if (i < (n >> 1)) {
                i <<= 1;
            } else {
                i = (i - (n >> 1)) << 1 | 1;
            }
            if (i == 1) {
                return ans;
            }
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int reinitializePermutation(int n) {
        int ans = 0;
        for (int i = 1;;) {
            ++ans;
            if (i < (n >> 1)) {
                i <<= 1;
            } else {
                i = (i - (n >> 1)) << 1 | 1;
            }
            if (i == 1) {
                return ans;
            }
        }
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func reinitializePermutation(n int) (ans int) {
	for i := 1; ; {
		ans++
		if i < (n >> 1) {
			i <<= 1
		} else {
			i = (i-(n>>1))<<1 | 1
		}
		if i == 1 {
			return ans
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

<p>给你一个偶数 <code>n</code>​​​​​​ ，已知存在一个长度为 <code>n</code> 的排列 <code>perm</code> ，其中 <code>perm[i] == i</code>​（下标 <strong>从 0 开始</strong> 计数）。</p>

<p>一步操作中，你将创建一个新数组 <code>arr</code> ，对于每个 <code>i</code> ：</p>

<ul>
	<li>如果 <code>i % 2 == 0</code> ，那么 <code>arr[i] = perm[i / 2]</code></li>
	<li>如果 <code>i % 2 == 1</code> ，那么 <code>arr[i] = perm[n / 2 + (i - 1) / 2]</code></li>
</ul>

<p>然后将 <code>arr</code>​​ 赋值​​给 <code>perm</code> 。</p>

<p>要想使 <code>perm</code> 回到排列初始值，至少需要执行多少步操作？返回最小的 <strong>非零</strong> 操作步数。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 2
<strong>输出：</strong>1
<strong>解释：</strong>最初，perm = [0,1]
第 1 步操作后，perm = [0,1]
所以，仅需执行 1 步操作</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 4
<strong>输出：</strong>2
<strong>解释：</strong>最初，perm = [0,1,2,3]
第 1 步操作后，perm = [0,2,1,3]
第 2 步操作后，perm = [0,1,2,3]
所以，仅需执行 2 步操作</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 6
<strong>输出：</strong>4
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 <= n <= 1000</code></li>
	<li><code>n</code>​​​​​​ 是一个偶数</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：找规律 + 模拟

我们观察数字的变化规律，发现：

1. 新数组的偶数位数字依次是原数组的前半段数字；
1. 新数组的奇数位数字依次是原数组的后半段数字。

即，如果原数组的某个数字下标 $i$ 在 `[0, n >> 1)` 范围内，那么这个数字的新下标就是 `i << 1`；否则，新下标就是 `(i - (n >> 1)) << 1 | 1`。

另外，每一轮操作，数字移动的路径都是一样的，只要有一个数字（数字 $0$ 和 $n-1$ 除外）回到了它原来的位置，那么整个序列就和之前的一致了。

因此，我们选择数字 $1$，初始时下标也是 $1$，每次将数字 $1$ 移动到新的位置，直到数字 $1$ 回到原来的位置，就可以得到最小的操作次数。

时间复杂度 $O(n)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def reinitializePermutation(self, n: int) -> int:
        ans, i = 0, 1
        while 1:
            ans += 1
            if i < n >> 1:
                i <<= 1
            else:
                i = (i - (n >> 1)) << 1 | 1
            if i == 1:
                return ans
```

#### Java

```java
class Solution {
    public int reinitializePermutation(int n) {
        int ans = 0;
        for (int i = 1;;) {
            ++ans;
            if (i < (n >> 1)) {
                i <<= 1;
            } else {
                i = (i - (n >> 1)) << 1 | 1;
            }
            if (i == 1) {
                return ans;
            }
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    int reinitializePermutation(int n) {
        int ans = 0;
        for (int i = 1;;) {
            ++ans;
            if (i < (n >> 1)) {
                i <<= 1;
            } else {
                i = (i - (n >> 1)) << 1 | 1;
            }
            if (i == 1) {
                return ans;
            }
        }
    }
};
```

#### Go

```go
func reinitializePermutation(n int) (ans int) {
	for i := 1; ; {
		ans++
		if i < (n >> 1) {
			i <<= 1
		} else {
			i = (i-(n>>1))<<1 | 1
		}
		if i == 1 {
			return ans
		}
	}
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1807. 替换字符串中的括号内容](https://leetcode.cn/problems/evaluate-the-bracket-pairs-of-a-string){#1807}

{{< tabs "1807" >}}

{{% tab "python" %}}
```python
class Solution:
    def evaluate(self, s: str, knowledge: List[List[str]]) -> str:
        d = {a: b for a, b in knowledge}
        i, n = 0, len(s)
        ans = []
        while i < n:
            if s[i] == '(':
                j = s.find(')', i + 1)
                ans.append(d.get(s[i + 1 : j], '?'))
                i = j
            else:
                ans.append(s[i])
            i += 1
        return ''.join(ans)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String evaluate(String s, List<List<String>> knowledge) {
        Map<String, String> d = new HashMap<>(knowledge.size());
        for (var e : knowledge) {
            d.put(e.get(0), e.get(1));
        }
        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < s.length(); ++i) {
            if (s.charAt(i) == '(') {
                int j = s.indexOf(')', i + 1);
                ans.append(d.getOrDefault(s.substring(i + 1, j), "?"));
                i = j;
            } else {
                ans.append(s.charAt(i));
            }
        }
        return ans.toString();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> d;
        for (auto& e : knowledge) {
            d[e[0]] = e[1];
        }
        string ans;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                int j = s.find(")", i + 1);
                auto t = s.substr(i + 1, j - i - 1);
                ans += d.count(t) ? d[t] : "?";
                i = j;
            } else {
                ans += s[i];
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func evaluate(s string, knowledge [][]string) string {
	d := map[string]string{}
	for _, v := range knowledge {
		d[v[0]] = v[1]
	}
	var ans strings.Builder
	for i := 0; i < len(s); i++ {
		if s[i] == '(' {
			j := i + 1
			for s[j] != ')' {
				j++
			}
			if v, ok := d[s[i+1:j]]; ok {
				ans.WriteString(v)
			} else {
				ans.WriteByte('?')
			}
			i = j
		} else {
			ans.WriteByte(s[i])
		}
	}
	return ans.String()
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function evaluate(s: string, knowledge: string[][]): string {
    const n = s.length;
    const map = new Map();
    for (const [k, v] of knowledge) {
        map.set(k, v);
    }
    const ans = [];
    let i = 0;
    while (i < n) {
        if (s[i] === '(') {
            const j = s.indexOf(')', i + 1);
            ans.push(map.get(s.slice(i + 1, j)) ?? '?');
            i = j;
        } else {
            ans.push(s[i]);
        }
        i++;
    }
    return ans.join('');
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashMap;
impl Solution {
    pub fn evaluate(s: String, knowledge: Vec<Vec<String>>) -> String {
        let s = s.as_bytes();
        let n = s.len();
        let mut map = HashMap::new();
        for v in knowledge.iter() {
            map.insert(&v[0], &v[1]);
        }
        let mut ans = String::new();
        let mut i = 0;
        while i < n {
            if s[i] == b'(' {
                i += 1;
                let mut j = i;
                let mut key = String::new();
                while s[j] != b')' {
                    key.push(s[j] as char);
                    j += 1;
                }
                ans.push_str(map.get(&key).unwrap_or(&&'?'.to_string()));
                i = j;
            } else {
                ans.push(s[i] as char);
            }
            i += 1;
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

<p>给你一个字符串&nbsp;<code>s</code>&nbsp;，它包含一些括号对，每个括号中包含一个 <strong>非空</strong>&nbsp;的键。</p>

<ul>
	<li>比方说，字符串&nbsp;<code>"(name)is(age)yearsold"</code>&nbsp;中，有&nbsp;<strong>两个</strong>&nbsp;括号对，分别包含键&nbsp;<code>"name"</code> 和&nbsp;<code>"age"</code>&nbsp;。</li>
</ul>

<p>你知道许多键对应的值，这些关系由二维字符串数组&nbsp;<code>knowledge</code>&nbsp;表示，其中&nbsp;<code>knowledge[i] = [key<sub>i</sub>, value<sub>i</sub>]</code>&nbsp;，表示键&nbsp;<code>key<sub>i</sub></code>&nbsp;对应的值为&nbsp;<code>value<sub>i</sub></code><sub>&nbsp;</sub>。</p>

<p>你需要替换 <strong>所有</strong>&nbsp;的括号对。当你替换一个括号对，且它包含的键为&nbsp;<code>key<sub>i</sub></code>&nbsp;时，你需要：</p>

<ul>
	<li>将&nbsp;<code>key<sub>i</sub></code>&nbsp;和括号用对应的值&nbsp;<code>value<sub>i</sub></code>&nbsp;替换。</li>
	<li>如果从 <code>knowledge</code>&nbsp;中无法得知某个键对应的值，你需要将&nbsp;<code>key<sub>i</sub></code>&nbsp;和括号用问号&nbsp;<code>"?"</code>&nbsp;替换（不需要引号）。</li>
</ul>

<p><code>knowledge</code>&nbsp;中每个键最多只会出现一次。<code>s</code>&nbsp;中不会有嵌套的括号。</p>

<p>请你返回替换 <strong>所有</strong>&nbsp;括号对后的结果字符串。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>s = "(name)is(age)yearsold", knowledge = [["name","bob"],["age","two"]]
<b>输出：</b>"bobistwoyearsold"
<strong>解释：</strong>
键 "name" 对应的值为 "bob" ，所以将 "(name)" 替换为 "bob" 。
键 "age" 对应的值为 "two" ，所以将 "(age)" 替换为 "two" 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>s = "hi(name)", knowledge = [["a","b"]]
<b>输出：</b>"hi?"
<b>解释：</b>由于不知道键 "name" 对应的值，所以用 "?" 替换 "(name)" 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>s = "(a)(a)(a)aaa", knowledge = [["a","yes"]]
<b>输出：</b>"yesyesyesaaa"
<b>解释：</b>相同的键在 s 中可能会出现多次。
键 "a" 对应的值为 "yes" ，所以将所有的 "(a)" 替换为 "yes" 。
注意，不在括号里的 "a" 不需要被替换。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= knowledge.length &lt;= 10<sup>5</sup></code></li>
	<li><code>knowledge[i].length == 2</code></li>
	<li><code>1 &lt;= key<sub>i</sub>.length, value<sub>i</sub>.length &lt;= 10</code></li>
	<li><code>s</code>&nbsp;只包含小写英文字母和圆括号&nbsp;<code>'('</code>&nbsp;和&nbsp;<code>')'</code>&nbsp;。</li>
	<li><code>s</code>&nbsp;中每一个左圆括号&nbsp;<code>'('</code>&nbsp;都有对应的右圆括号&nbsp;<code>')'</code>&nbsp;。</li>
	<li><code>s</code>&nbsp;中每对括号内的键都不会为空。</li>
	<li><code>s</code>&nbsp;中不会有嵌套括号对。</li>
	<li><code>key<sub>i</sub></code>&nbsp;和&nbsp;<code>value<sub>i</sub></code>&nbsp;只包含小写英文字母。</li>
	<li><code>knowledge</code>&nbsp;中的&nbsp;<code>key<sub>i</sub></code>&nbsp;不会重复。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 模拟

我们先用哈希表 $d$ 记录 `knowledge` 中的键值对。

然后遍历字符串 $s$，如果当前字符是左括号 `'('`，则从当前位置开始向后遍历，直到遇到右括号 `')'`，此时括号内的字符串即为键，我们在哈希表 $d$ 中查找该键对应的值，如果找到了，则将该值替换到括号内，否则替换为 `'?'`。

时间复杂度 $O(n + m)$，空间复杂度 $O(L)$。其中 $n$ 和 $m$ 分别为字符串 $s$ 和列表 `knowledge` 的长度，而 $L$ 为 `knowledge` 中所有字符串的长度之和。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def evaluate(self, s: str, knowledge: List[List[str]]) -> str:
        d = {a: b for a, b in knowledge}
        i, n = 0, len(s)
        ans = []
        while i < n:
            if s[i] == '(':
                j = s.find(')', i + 1)
                ans.append(d.get(s[i + 1 : j], '?'))
                i = j
            else:
                ans.append(s[i])
            i += 1
        return ''.join(ans)
```

#### Java

```java
class Solution {
    public String evaluate(String s, List<List<String>> knowledge) {
        Map<String, String> d = new HashMap<>(knowledge.size());
        for (var e : knowledge) {
            d.put(e.get(0), e.get(1));
        }
        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < s.length(); ++i) {
            if (s.charAt(i) == '(') {
                int j = s.indexOf(')', i + 1);
                ans.append(d.getOrDefault(s.substring(i + 1, j), "?"));
                i = j;
            } else {
                ans.append(s.charAt(i));
            }
        }
        return ans.toString();
    }
}
```

#### C++

```cpp
class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> d;
        for (auto& e : knowledge) {
            d[e[0]] = e[1];
        }
        string ans;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                int j = s.find(")", i + 1);
                auto t = s.substr(i + 1, j - i - 1);
                ans += d.count(t) ? d[t] : "?";
                i = j;
            } else {
                ans += s[i];
            }
        }
        return ans;
    }
};
```

#### Go

```go
func evaluate(s string, knowledge [][]string) string {
	d := map[string]string{}
	for _, v := range knowledge {
		d[v[0]] = v[1]
	}
	var ans strings.Builder
	for i := 0; i < len(s); i++ {
		if s[i] == '(' {
			j := i + 1
			for s[j] != ')' {
				j++
			}
			if v, ok := d[s[i+1:j]]; ok {
				ans.WriteString(v)
			} else {
				ans.WriteByte('?')
			}
			i = j
		} else {
			ans.WriteByte(s[i])
		}
	}
	return ans.String()
}
```

#### TypeScript

```ts
function evaluate(s: string, knowledge: string[][]): string {
    const n = s.length;
    const map = new Map();
    for (const [k, v] of knowledge) {
        map.set(k, v);
    }
    const ans = [];
    let i = 0;
    while (i < n) {
        if (s[i] === '(') {
            const j = s.indexOf(')', i + 1);
            ans.push(map.get(s.slice(i + 1, j)) ?? '?');
            i = j;
        } else {
            ans.push(s[i]);
        }
        i++;
    }
    return ans.join('');
}
```

#### Rust

```rust
use std::collections::HashMap;
impl Solution {
    pub fn evaluate(s: String, knowledge: Vec<Vec<String>>) -> String {
        let s = s.as_bytes();
        let n = s.len();
        let mut map = HashMap::new();
        for v in knowledge.iter() {
            map.insert(&v[0], &v[1]);
        }
        let mut ans = String::new();
        let mut i = 0;
        while i < n {
            if s[i] == b'(' {
                i += 1;
                let mut j = i;
                let mut key = String::new();
                while s[j] != b')' {
                    key.push(s[j] as char);
                    j += 1;
                }
                ans.push_str(map.get(&key).unwrap_or(&&'?'.to_string()));
                i = j;
            } else {
                ans.push(s[i] as char);
            }
            i += 1;
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

# [1808. 好因子的最大数目](https://leetcode.cn/problems/maximize-number-of-nice-divisors){#1808}

{{< tabs "1808" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxNiceDivisors(self, primeFactors: int) -> int:
        mod = 10**9 + 7
        if primeFactors < 4:
            return primeFactors
        if primeFactors % 3 == 0:
            return pow(3, primeFactors // 3, mod) % mod
        if primeFactors % 3 == 1:
            return 4 * pow(3, primeFactors // 3 - 1, mod) % mod
        return 2 * pow(3, primeFactors // 3, mod) % mod
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private final int mod = (int) 1e9 + 7;

    public int maxNiceDivisors(int primeFactors) {
        if (primeFactors < 4) {
            return primeFactors;
        }
        if (primeFactors % 3 == 0) {
            return qpow(3, primeFactors / 3);
        }
        if (primeFactors % 3 == 1) {
            return (int) (4L * qpow(3, primeFactors / 3 - 1) % mod);
        }
        return 2 * qpow(3, primeFactors / 3) % mod;
    }

    private int qpow(long a, long n) {
        long ans = 1;
        for (; n > 0; n >>= 1) {
            if ((n & 1) == 1) {
                ans = ans * a % mod;
            }
            a = a * a % mod;
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
    int maxNiceDivisors(int primeFactors) {
        if (primeFactors < 4) {
            return primeFactors;
        }
        const int mod = 1e9 + 7;
        auto qpow = [&](long long a, long long n) {
            long long ans = 1;
            for (; n; n >>= 1) {
                if (n & 1) {
                    ans = ans * a % mod;
                }
                a = a * a % mod;
            }
            return (int) ans;
        };
        if (primeFactors % 3 == 0) {
            return qpow(3, primeFactors / 3);
        }
        if (primeFactors % 3 == 1) {
            return qpow(3, primeFactors / 3 - 1) * 4L % mod;
        }
        return qpow(3, primeFactors / 3) * 2 % mod;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxNiceDivisors(primeFactors int) int {
	if primeFactors < 4 {
		return primeFactors
	}
	const mod = 1e9 + 7
	qpow := func(a, n int) int {
		ans := 1
		for ; n > 0; n >>= 1 {
			if n&1 == 1 {
				ans = ans * a % mod
			}
			a = a * a % mod
		}
		return ans
	}
	if primeFactors%3 == 0 {
		return qpow(3, primeFactors/3)
	}
	if primeFactors%3 == 1 {
		return qpow(3, primeFactors/3-1) * 4 % mod
	}
	return qpow(3, primeFactors/3) * 2 % mod
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number} primeFactors
 * @return {number}
 */
var maxNiceDivisors = function (primeFactors) {
    if (primeFactors < 4) {
        return primeFactors;
    }
    const mod = 1e9 + 7;
    const qpow = (a, n) => {
        let ans = 1;
        for (; n; n >>= 1) {
            if (n & 1) {
                ans = Number((BigInt(ans) * BigInt(a)) % BigInt(mod));
            }
            a = Number((BigInt(a) * BigInt(a)) % BigInt(mod));
        }
        return ans;
    };
    const k = Math.floor(primeFactors / 3);
    if (primeFactors % 3 === 0) {
        return qpow(3, k);
    }
    if (primeFactors % 3 === 1) {
        return (4 * qpow(3, k - 1)) % mod;
    }
    return (2 * qpow(3, k)) % mod;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个正整数 <code>primeFactors</code> 。你需要构造一个正整数 <code>n</code> ，它满足以下条件：</p>

<ul>
	<li><code>n</code> 质因数（质因数需要考虑重复的情况）的数目 <strong>不超过 </strong><code>primeFactors</code> 个。</li>
	<li><code>n</code> 好因子的数目最大化。如果 <code>n</code> 的一个因子可以被 <code>n</code> 的每一个质因数整除，我们称这个因子是 <strong>好因子</strong> 。比方说，如果 <code>n = 12</code> ，那么它的质因数为 <code>[2,2,3]</code> ，那么 <code>6</code> 和 <code>12</code> 是好因子，但 <code>3</code> 和 <code>4</code> 不是。</li>
</ul>

<p>请你返回 <code>n</code> 的好因子的数目。由于答案可能会很大，请返回答案对 <code>10<sup>9</sup> + 7</code> <b>取余</b> 的结果。</p>

<p>请注意，一个质数的定义是大于 <code>1</code> ，且不能被分解为两个小于该数的自然数相乘。一个数 <code>n</code> 的质因子是将 <code>n</code> 分解为若干个质因子，且它们的乘积为 <code>n</code> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>primeFactors = 5
<strong>输出：</strong>6
<b>解释：</b>200 是一个可行的 n 。
它有 5 个质因子：[2,2,2,5,5] ，且有 6 个好因子：[10,20,40,50,100,200] 。
不存在别的 n 有至多 5 个质因子，且同时有更多的好因子。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>primeFactors = 8
<b>输出：</b>18
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= primeFactors <= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：问题转换 + 快速幂

我们可以将 $n$ 进行质因数分解，即 $n = a_1^{k_1} \times a_2^{k_2} \times\cdots \times a_m^{k_m}$，其中 $a_i$ 为质因子，而 $k_i$ 为质因子 $a_i$ 的指数。由于 $n$ 的质因子个数不超过 $primeFactors$ 个，因此 $k_1 + k_2 + \cdots + k_m \leq primeFactors$。

而根据题意描述，我们知道 $n$ 的好因子要满足能被所有的质因子整除，也即是说 $n$ 的好因子需要包含 $a_1 \times a_2 \times \cdots \times a_m$ 作为因数。那么好因子的个数 $k= k_1 \times k_2 \times \cdots \times k_m$，即 $k$ 为 $k_1, k_2, \cdots, k_m$ 的乘积。要最大化好因子的个数，也即是说我们要将 `primeFactors` 拆分成 $k_1, k_2, \cdots, k_m$，使得 $k_1 \times k_2 \times \cdots \times k_m$ 最大。因此问题转换为：将整数 `primeFactors` 拆分成若干个整数的乘积，使得乘积最大。

接下来，我们只需要分情况讨论。

-   如果 $primeFactors \lt 4$，那么直接返回 `primeFactors` 即可。
-   如果 $primeFactors$ 为 $3$ 的倍数，那么我们将 `primeFactors` 拆分成 $3$ 的倍数个 $3$，即 $3^{\frac{primeFactors}{3}}$。
-   如果 $primeFactors$ 除以 $3$ 余 $1$，那么我们将 `primeFactors` 拆分成 $\frac{primeFactors}{3} - 1$ 个 $3$，再乘以 $4$，即 $3^{\frac{primeFactors}{3} - 1} \times 4$。
-   如果 $primeFactors$ 除以 $3$ 余 $2$，那么我们将 `primeFactors` 拆分成 $\frac{primeFactors}{3}$ 个 $3$，再乘以 $2$，即 $3^{\frac{primeFactors}{3}} \times 2$。

以上过程中，我们利用快速幂取模求解。

时间复杂度 $O(\log n)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxNiceDivisors(self, primeFactors: int) -> int:
        mod = 10**9 + 7
        if primeFactors < 4:
            return primeFactors
        if primeFactors % 3 == 0:
            return pow(3, primeFactors // 3, mod) % mod
        if primeFactors % 3 == 1:
            return 4 * pow(3, primeFactors // 3 - 1, mod) % mod
        return 2 * pow(3, primeFactors // 3, mod) % mod
```

#### Java

```java
class Solution {
    private final int mod = (int) 1e9 + 7;

    public int maxNiceDivisors(int primeFactors) {
        if (primeFactors < 4) {
            return primeFactors;
        }
        if (primeFactors % 3 == 0) {
            return qpow(3, primeFactors / 3);
        }
        if (primeFactors % 3 == 1) {
            return (int) (4L * qpow(3, primeFactors / 3 - 1) % mod);
        }
        return 2 * qpow(3, primeFactors / 3) % mod;
    }

    private int qpow(long a, long n) {
        long ans = 1;
        for (; n > 0; n >>= 1) {
            if ((n & 1) == 1) {
                ans = ans * a % mod;
            }
            a = a * a % mod;
        }
        return (int) ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxNiceDivisors(int primeFactors) {
        if (primeFactors < 4) {
            return primeFactors;
        }
        const int mod = 1e9 + 7;
        auto qpow = [&](long long a, long long n) {
            long long ans = 1;
            for (; n; n >>= 1) {
                if (n & 1) {
                    ans = ans * a % mod;
                }
                a = a * a % mod;
            }
            return (int) ans;
        };
        if (primeFactors % 3 == 0) {
            return qpow(3, primeFactors / 3);
        }
        if (primeFactors % 3 == 1) {
            return qpow(3, primeFactors / 3 - 1) * 4L % mod;
        }
        return qpow(3, primeFactors / 3) * 2 % mod;
    }
};
```

#### Go

```go
func maxNiceDivisors(primeFactors int) int {
	if primeFactors < 4 {
		return primeFactors
	}
	const mod = 1e9 + 7
	qpow := func(a, n int) int {
		ans := 1
		for ; n > 0; n >>= 1 {
			if n&1 == 1 {
				ans = ans * a % mod
			}
			a = a * a % mod
		}
		return ans
	}
	if primeFactors%3 == 0 {
		return qpow(3, primeFactors/3)
	}
	if primeFactors%3 == 1 {
		return qpow(3, primeFactors/3-1) * 4 % mod
	}
	return qpow(3, primeFactors/3) * 2 % mod
}
```

#### JavaScript

```js
/**
 * @param {number} primeFactors
 * @return {number}
 */
var maxNiceDivisors = function (primeFactors) {
    if (primeFactors < 4) {
        return primeFactors;
    }
    const mod = 1e9 + 7;
    const qpow = (a, n) => {
        let ans = 1;
        for (; n; n >>= 1) {
            if (n & 1) {
                ans = Number((BigInt(ans) * BigInt(a)) % BigInt(mod));
            }
            a = Number((BigInt(a) * BigInt(a)) % BigInt(mod));
        }
        return ans;
    };
    const k = Math.floor(primeFactors / 3);
    if (primeFactors % 3 === 0) {
        return qpow(3, k);
    }
    if (primeFactors % 3 === 1) {
        return (4 * qpow(3, k - 1)) % mod;
    }
    return (2 * qpow(3, k)) % mod;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1809. 没有广告的剧集 🔒](https://leetcode.cn/problems/ad-free-sessions){#1809}

{{< tabs "1809" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT session_id
FROM Playback
WHERE
    session_id NOT IN (
        SELECT session_id
        FROM
            Playback AS p
            JOIN Ads AS a
                ON p.customer_id = a.customer_id AND a.timestamp BETWEEN p.start_time AND p.end_time
    );
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code>Playback</code></p>

<pre>
+-------------+------+
| Column Name | Type |
+-------------+------+
| session_id  | int  |
| customer_id | int  |
| start_time  | int  |
| end_time    | int  |
+-------------+------+
session_id 是该表中具有唯一值的列。
customer_id 是观看该剧集的客户的 id。
剧集播放时间包含start_time（开始时间） 及 end_time（结束时间）
可以保证的是，start_time（开始时间）&lt;= end_time（结束时间），一个观众观看的两个剧集的时间不会出现重叠。</pre>

<p>&nbsp;</p>

<p>表：<code>Ads</code></p>

<pre>
+-------------+------+
| Column Name | Type |
+-------------+------+
| ad_id       | int  |
| customer_id | int  |
| timestamp   | int  |
+-------------+------+
ad_id 是该表中具有唯一值的列。
customer_id 为 观看广告的用户 id
timestamp 表示广告出现的时间点
</pre>

<p>&nbsp;</p>

<p>编写解决方案找出所有没有广告出现过的剧集。</p>

<p>返回结果 <strong>无顺序要求</strong> 。</p>

<p>返回结果格式如下例所示：</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
Playback table:
+------------+-------------+------------+----------+
| session_id | customer_id | start_time | end_time |
+------------+-------------+------------+----------+
| 1          | 1           | 1          | 5        |
| 2          | 1           | 15         | 23       |
| 3          | 2           | 10         | 12       |
| 4          | 2           | 17         | 28       |
| 5          | 2           | 2          | 8        |
+------------+-------------+------------+----------+
Ads table:
+-------+-------------+-----------+
| ad_id | customer_id | timestamp |
+-------+-------------+-----------+
| 1     | 1           | 5         |
| 2     | 2           | 17        |
| 3     | 2           | 20        |
+-------+-------------+-----------+
<strong>输出：</strong>
+------------+
| session_id |
+------------+
| 2          |
| 3          |
| 5          |
+------------+
<strong>解释：</strong>
广告1出现在了剧集1的时间段，被观众1看到了。
广告2出现在了剧集4的时间段，被观众2看到了。
广告3出现在了剧集4的时间段，被观众2看到了。
我们可以得出结论，剧集1 、4 内，起码有1处广告。 剧集2 、3 、5 没有广告。</pre>

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
SELECT session_id
FROM Playback
WHERE
    session_id NOT IN (
        SELECT session_id
        FROM
            Playback AS p
            JOIN Ads AS a
                ON p.customer_id = a.customer_id AND a.timestamp BETWEEN p.start_time AND p.end_time
    );
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
