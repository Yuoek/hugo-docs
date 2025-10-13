---
title: "2070_每一个查询的最大美丽值"
date: 2025-10-08T18:38:57+08:00
weight: 8
tags: [二分查找, 单调队列, 双指针, 图, 字符串, 并查集, 排序, 数据库, 数组, 模拟, 贪心, 链表, 队列]
---

{{< markmap >}}
### [2070_每一个查询的最大美丽值](#2070)
#### [数组](#2070)
#### [二分查找](#2070)
#### [排序](#2070)
### [2071_你可以安排的最多任务数目](#2071)
#### [贪心](#2071)
#### [队列](#2071)
#### [数组](#2071)
#### [双指针](#2071)
#### [二分查找](#2071)
#### [排序](#2071)
#### [单调队列](#2071)
### [2072_赢得比赛的大学 🔒](#2072)
#### [数据库](#2072)
### [2073_买票需要的时间](#2073)
#### [队列](#2073)
#### [数组](#2073)
#### [模拟](#2073)
### [2074_反转偶数长度组的节点](#2074)
#### [链表](#2074)
### [2075_解码斜向换位密码](#2075)
#### [字符串](#2075)
#### [模拟](#2075)
### [2076_处理含限制条件的好友请求](#2076)
#### [并查集](#2076)
#### [图](#2076)
### [2077_殊途同归 🔒](#2077)
#### [图](#2077)
### [2078_两栋颜色不同且距离最远的房子](#2078)
#### [贪心](#2078)
#### [数组](#2078)
### [2079_给植物浇水](#2079)
#### [数组](#2079)
#### [模拟](#2079)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2070_每一个查询的最大美丽值
___
#### 数组
___
#### 二分查找
___
#### 排序
---
### 2071_你可以安排的最多任务数目
___
#### 贪心
___
#### 队列
___
#### 数组
___
#### 双指针
___
#### 二分查找
___
#### 排序
___
#### 单调队列
---
### 2072_赢得比赛的大学 🔒
___
#### 数据库
---
### 2073_买票需要的时间
___
#### 队列
___
#### 数组
___
#### 模拟
---
### 2074_反转偶数长度组的节点
___
#### 链表
---
### 2075_解码斜向换位密码
___
#### 字符串
___
#### 模拟
---
### 2076_处理含限制条件的好友请求
___
#### 并查集
___
#### 图
---
### 2077_殊途同归 🔒
___
#### 图
---
### 2078_两栋颜色不同且距离最远的房子
___
#### 贪心
___
#### 数组
---
### 2079_给植物浇水
___
#### 数组
___
#### 模拟
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 单调队列 | 双指针 |
| 图 | 字符串 | 并查集 |
| 排序 | 数据库 | 数组 |
| 模拟 | 贪心 | 链表 |
| 队列 |  |  |

# [2070. 每一个查询的最大美丽值](https://leetcode.cn/problems/most-beautiful-item-for-each-query){#2070}

{{< tabs "2070" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumBeauty(self, items: List[List[int]], queries: List[int]) -> List[int]:
        items.sort()
        prices = [p for p, _ in items]
        n = len(items)
        mx = [items[0][1]]
        for i in range(1, n):
            mx.append(max(mx[i - 1], items[i][1]))
        ans = []
        for q in queries:
            j = bisect_right(prices, q) - 1
            ans.append(0 if j < 0 else mx[j])
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] maximumBeauty(int[][] items, int[] queries) {
        Arrays.sort(items, (a, b) -> a[0] - b[0]);
        int n = items.length;
        int m = queries.length;
        int[] prices = new int[n];
        prices[0] = items[0][0];
        for (int i = 1; i < n; ++i) {
            prices[i] = items[i][0];
            items[i][1] = Math.max(items[i - 1][1], items[i][1]);
        }
        int[] ans = new int[m];
        for (int i = 0; i < m; ++i) {
            int j = Arrays.binarySearch(prices, queries[i] + 1);
            j = j < 0 ? -j - 2 : j - 1;
            ans[i] = j < 0 ? 0 : items[j][1];
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
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());
        int n = items.size();
        int m = queries.size();
        vector<int> prices(n, items[0][0]);
        for (int i = 1; i < n; ++i) {
            prices[i] = items[i][0];
            items[i][1] = max(items[i - 1][1], items[i][1]);
        }
        vector<int> ans;
        for (int q : queries) {
            int j = upper_bound(prices.begin(), prices.end(), q) - prices.begin() - 1;
            ans.push_back(j < 0 ? 0 : items[j][1]);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumBeauty(items [][]int, queries []int) []int {
	sort.Slice(items, func(i, j int) bool {
		return items[i][0] < items[j][0]
	})
	n, m := len(items), len(queries)
	prices := make([]int, n)
	prices[0] = items[0][0]
	for i := 1; i < n; i++ {
		prices[i] = items[i][0]
		items[i][1] = max(items[i][1], items[i-1][1])
	}
	ans := make([]int, m)
	for i, q := range queries {
		j := sort.SearchInts(prices, q+1) - 1
		if j >= 0 {
			ans[i] = items[j][1]
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumBeauty(items: number[][], queries: number[]): number[] {
    items.sort((a, b) => a[0] - b[0]);
    const n = items.length;
    for (let i = 1; i < n; ++i) {
        items[i][1] = Math.max(items[i][1], items[i - 1][1]);
    }
    const ans: number[] = [];
    for (const q of queries) {
        let l = 0,
            r = n;
        while (l < r) {
            const mid = (l + r) >> 1;
            if (items[mid][0] > q) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        ans.push(--l >= 0 ? items[l][1] : 0);
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

<p>给你一个二维整数数组&nbsp;<code>items</code>&nbsp;，其中&nbsp;<code>items[i] = [price<sub>i</sub>, beauty<sub>i</sub>]</code>&nbsp;分别表示每一个物品的 <strong>价格</strong>&nbsp;和 <strong>美丽值</strong>&nbsp;。</p>

<p>同时给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>queries</code>&nbsp;。对于每个查询&nbsp;<code>queries[j]</code>&nbsp;，你想求出价格小于等于&nbsp;<code>queries[j]</code>&nbsp;的物品中，<strong>最大的美丽值</strong>&nbsp;是多少。如果不存在符合条件的物品，那么查询的结果为&nbsp;<code>0</code>&nbsp;。</p>

<p>请你返回一个长度与 <code>queries</code>&nbsp;相同的数组<em>&nbsp;</em><code>answer</code>，其中<em>&nbsp;</em><code>answer[j]</code>是第&nbsp;<code>j</code>&nbsp;个查询的答案。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>items = [[1,2],[3,2],[2,4],[5,6],[3,5]], queries = [1,2,3,4,5,6]
<b>输出：</b>[2,4,5,5,6,6]
<strong>解释：</strong>
- queries[0]=1 ，[1,2] 是唯一价格 &lt;= 1 的物品。所以这个查询的答案为 2 。
- queries[1]=2 ，符合条件的物品有 [1,2] 和 [2,4] 。
  它们中的最大美丽值为 4 。
- queries[2]=3 和 queries[3]=4 ，符合条件的物品都为 [1,2] ，[3,2] ，[2,4] 和 [3,5] 。
  它们中的最大美丽值为 5 。
- queries[4]=5 和 queries[5]=6 ，所有物品都符合条件。
  所以，答案为所有物品中的最大美丽值，为 6 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>items = [[1,2],[1,2],[1,3],[1,4]], queries = [1]
<b>输出：</b>[4]
<b>解释：</b>
每个物品的价格均为 1 ，所以我们选择最大美丽值 4 。
注意，多个物品可能有相同的价格和美丽值。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>items = [[10,1000]], queries = [5]
<b>输出：</b>[0]
<strong>解释：</strong>
没有物品的价格小于等于 5 ，所以没有物品可以选择。
因此，查询的结果为 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= items.length, queries.length &lt;= 10<sup>5</sup></code></li>
	<li><code>items[i].length == 2</code></li>
	<li><code>1 &lt;= price<sub>i</sub>, beauty<sub>i</sub>, queries[j] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 离线查询

对于每一个查询，我们需要找到价格小于等于查询价格的物品中的最大美丽值，我们不妨采用离线查询的方式，先对物品按价格排序，然后对查询按照价格排序。

接下来，我们从小到大遍历查询，对于每一个查询，我们用一个指针 $i$ 指向物品数组，如果物品的价格小于等于查询价格，我们更新当前的最大美丽值，向右移动指针 $i$，直到物品的价格大于查询价格，我们将当前的最大美丽值记录下来，就是当前查询的答案。继续遍历下一个查询，直到所有的查询都处理完。

时间复杂度 $(n \times \log n + m \times \log m)$，空间复杂度 $O(\log n + m)$。其中 $n$ 和 $m$ 分别为物品数组和查询数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumBeauty(self, items: List[List[int]], queries: List[int]) -> List[int]:
        items.sort()
        n, m = len(items), len(queries)
        ans = [0] * len(queries)
        i = mx = 0
        for q, j in sorted(zip(queries, range(m))):
            while i < n and items[i][0] <= q:
                mx = max(mx, items[i][1])
                i += 1
            ans[j] = mx
        return ans
```

#### Java

```java
class Solution {
    public int[] maximumBeauty(int[][] items, int[] queries) {
        Arrays.sort(items, (a, b) -> a[0] - b[0]);
        int n = items.length;
        int m = queries.length;
        int[] ans = new int[m];
        Integer[] idx = new Integer[m];
        for (int i = 0; i < m; ++i) {
            idx[i] = i;
        }
        Arrays.sort(idx, (i, j) -> queries[i] - queries[j]);
        int i = 0, mx = 0;
        for (int j : idx) {
            while (i < n && items[i][0] <= queries[j]) {
                mx = Math.max(mx, items[i][1]);
                ++i;
            }
            ans[j] = mx;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());
        int n = items.size();
        int m = queries.size();
        vector<int> idx(m);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int i, int j) {
            return queries[i] < queries[j];
        });
        int mx = 0, i = 0;
        vector<int> ans(m);
        for (int j : idx) {
            while (i < n && items[i][0] <= queries[j]) {
                mx = max(mx, items[i][1]);
                ++i;
            }
            ans[j] = mx;
        }
        return ans;
    }
};
```

#### Go

```go
func maximumBeauty(items [][]int, queries []int) []int {
	sort.Slice(items, func(i, j int) bool {
		return items[i][0] < items[j][0]
	})
	n, m := len(items), len(queries)
	idx := make([]int, m)
	for i := range idx {
		idx[i] = i
	}
	sort.Slice(idx, func(i, j int) bool { return queries[idx[i]] < queries[idx[j]] })
	ans := make([]int, m)
	i, mx := 0, 0
	for _, j := range idx {
		for i < n && items[i][0] <= queries[j] {
			mx = max(mx, items[i][1])
			i++
		}
		ans[j] = mx
	}
	return ans
}
```

#### TypeScript

```ts
function maximumBeauty(items: number[][], queries: number[]): number[] {
    const n = items.length;
    const m = queries.length;
    items.sort((a, b) => a[0] - b[0]);
    const idx: number[] = Array(m)
        .fill(0)
        .map((_, i) => i);
    idx.sort((i, j) => queries[i] - queries[j]);
    let [i, mx] = [0, 0];
    const ans: number[] = Array(m).fill(0);
    for (const j of idx) {
        while (i < n && items[i][0] <= queries[j]) {
            mx = Math.max(mx, items[i][1]);
            ++i;
        }
        ans[j] = mx;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：排序 + 二分查找

我们可以将物品按照价格排序，然后预处理出小于等于每个价格的物品中的最大美丽值，记录在数组 $mx$ 或者原 $items$ 数组中。

对于每一个查询，我们可以使用二分查找找到第一个价格大于查询价格的物品的下标 $j$，然后 $j - 1$ 就是小于等于查询价格且最大美丽值的物品的下标，添加到答案中。

时间复杂度 $O((m + n) \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 和 $m$ 分别为物品数组和查询数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumBeauty(self, items: List[List[int]], queries: List[int]) -> List[int]:
        items.sort()
        prices = [p for p, _ in items]
        n = len(items)
        mx = [items[0][1]]
        for i in range(1, n):
            mx.append(max(mx[i - 1], items[i][1]))
        ans = []
        for q in queries:
            j = bisect_right(prices, q) - 1
            ans.append(0 if j < 0 else mx[j])
        return ans
```

#### Java

```java
class Solution {
    public int[] maximumBeauty(int[][] items, int[] queries) {
        Arrays.sort(items, (a, b) -> a[0] - b[0]);
        int n = items.length;
        int m = queries.length;
        int[] prices = new int[n];
        prices[0] = items[0][0];
        for (int i = 1; i < n; ++i) {
            prices[i] = items[i][0];
            items[i][1] = Math.max(items[i - 1][1], items[i][1]);
        }
        int[] ans = new int[m];
        for (int i = 0; i < m; ++i) {
            int j = Arrays.binarySearch(prices, queries[i] + 1);
            j = j < 0 ? -j - 2 : j - 1;
            ans[i] = j < 0 ? 0 : items[j][1];
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());
        int n = items.size();
        int m = queries.size();
        vector<int> prices(n, items[0][0]);
        for (int i = 1; i < n; ++i) {
            prices[i] = items[i][0];
            items[i][1] = max(items[i - 1][1], items[i][1]);
        }
        vector<int> ans;
        for (int q : queries) {
            int j = upper_bound(prices.begin(), prices.end(), q) - prices.begin() - 1;
            ans.push_back(j < 0 ? 0 : items[j][1]);
        }
        return ans;
    }
};
```

#### Go

```go
func maximumBeauty(items [][]int, queries []int) []int {
	sort.Slice(items, func(i, j int) bool {
		return items[i][0] < items[j][0]
	})
	n, m := len(items), len(queries)
	prices := make([]int, n)
	prices[0] = items[0][0]
	for i := 1; i < n; i++ {
		prices[i] = items[i][0]
		items[i][1] = max(items[i][1], items[i-1][1])
	}
	ans := make([]int, m)
	for i, q := range queries {
		j := sort.SearchInts(prices, q+1) - 1
		if j >= 0 {
			ans[i] = items[j][1]
		}
	}
	return ans
}
```

#### TypeScript

```ts
function maximumBeauty(items: number[][], queries: number[]): number[] {
    items.sort((a, b) => a[0] - b[0]);
    const n = items.length;
    for (let i = 1; i < n; ++i) {
        items[i][1] = Math.max(items[i][1], items[i - 1][1]);
    }
    const ans: number[] = [];
    for (const q of queries) {
        let l = 0,
            r = n;
        while (l < r) {
            const mid = (l + r) >> 1;
            if (items[mid][0] > q) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        ans.push(--l >= 0 ? items[l][1] : 0);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2071. 你可以安排的最多任务数目](https://leetcode.cn/problems/maximum-number-of-tasks-you-can-assign){#2071}

{{< tabs "2071" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxTaskAssign(
        self, tasks: List[int], workers: List[int], pills: int, strength: int
    ) -> int:
        def check(x):
            i = 0
            q = deque()
            p = pills
            for j in range(m - x, m):
                while i < x and tasks[i] <= workers[j] + strength:
                    q.append(tasks[i])
                    i += 1
                if not q:
                    return False
                if q[0] <= workers[j]:
                    q.popleft()
                elif p == 0:
                    return False
                else:
                    p -= 1
                    q.pop()
            return True

        n, m = len(tasks), len(workers)
        tasks.sort()
        workers.sort()
        left, right = 0, min(n, m)
        while left < right:
            mid = (left + right + 1) >> 1
            if check(mid):
                left = mid
            else:
                right = mid - 1
        return left
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[] tasks;
    private int[] workers;
    private int strength;
    private int pills;
    private int m;
    private int n;

    public int maxTaskAssign(int[] tasks, int[] workers, int pills, int strength) {
        Arrays.sort(tasks);
        Arrays.sort(workers);
        this.tasks = tasks;
        this.workers = workers;
        this.strength = strength;
        this.pills = pills;
        n = tasks.length;
        m = workers.length;
        int left = 0, right = Math.min(m, n);
        while (left < right) {
            int mid = (left + right + 1) >> 1;
            if (check(mid)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }

    private boolean check(int x) {
        int i = 0;
        Deque<Integer> q = new ArrayDeque<>();
        int p = pills;
        for (int j = m - x; j < m; ++j) {
            while (i < x && tasks[i] <= workers[j] + strength) {
                q.offer(tasks[i++]);
            }
            if (q.isEmpty()) {
                return false;
            }
            if (q.peekFirst() <= workers[j]) {
                q.pollFirst();
            } else if (p == 0) {
                return false;
            } else {
                --p;
                q.pollLast();
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
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        int n = tasks.size(), m = workers.size();
        int left = 0, right = min(m, n);
        auto check = [&](int x) {
            int p = pills;
            deque<int> q;
            int i = 0;
            for (int j = m - x; j < m; ++j) {
                while (i < x && tasks[i] <= workers[j] + strength) {
                    q.push_back(tasks[i++]);
                }
                if (q.empty()) {
                    return false;
                }
                if (q.front() <= workers[j]) {
                    q.pop_front();
                } else if (p == 0) {
                    return false;
                } else {
                    --p;
                    q.pop_back();
                }
            }
            return true;
        };
        while (left < right) {
            int mid = (left + right + 1) >> 1;
            if (check(mid)) {
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
func maxTaskAssign(tasks []int, workers []int, pills int, strength int) int {
	sort.Ints(tasks)
	sort.Ints(workers)
	n, m := len(tasks), len(workers)
	left, right := 0, min(m, n)
	check := func(x int) bool {
		p := pills
		q := []int{}
		i := 0
		for j := m - x; j < m; j++ {
			for i < x && tasks[i] <= workers[j]+strength {
				q = append(q, tasks[i])
				i++
			}
			if len(q) == 0 {
				return false
			}
			if q[0] <= workers[j] {
				q = q[1:]
			} else if p == 0 {
				return false
			} else {
				p--
				q = q[:len(q)-1]
			}
		}
		return true
	}
	for left < right {
		mid := (left + right + 1) >> 1
		if check(mid) {
			left = mid
		} else {
			right = mid - 1
		}
	}
	return left
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxTaskAssign(
    tasks: number[],
    workers: number[],
    pills: number,
    strength: number,
): number {
    tasks.sort((a, b) => a - b);
    workers.sort((a, b) => a - b);

    const n = tasks.length;
    const m = workers.length;

    const check = (x: number): boolean => {
        const dq = new Array<number>(x);
        let head = 0;
        let tail = 0;
        const empty = () => head === tail;
        const pushBack = (val: number) => {
            dq[tail++] = val;
        };
        const popFront = () => {
            head++;
        };
        const popBack = () => {
            tail--;
        };
        const front = () => dq[head];

        let i = 0;
        let p = pills;

        for (let j = m - x; j < m; j++) {
            while (i < x && tasks[i] <= workers[j] + strength) {
                pushBack(tasks[i]);
                i++;
            }

            if (empty()) return false;

            if (front() <= workers[j]) {
                popFront();
            } else {
                if (p === 0) return false;
                p--;
                popBack();
            }
        }
        return true;
    };

    let [left, right] = [0, Math.min(n, m)];
    while (left < right) {
        const mid = (left + right + 1) >> 1;
        if (check(mid)) left = mid;
        else right = mid - 1;
    }
    return left;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你&nbsp;<code>n</code>&nbsp;个任务和&nbsp;<code>m</code>&nbsp;个工人。每个任务需要一定的力量值才能完成，需要的力量值保存在下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>tasks</code>&nbsp;中，第 <code>i</code>&nbsp;个任务需要&nbsp;<code>tasks[i]</code>&nbsp;的力量才能完成。每个工人的力量值保存在下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>workers</code>&nbsp;中，第&nbsp;<code>j</code>&nbsp;个工人的力量值为&nbsp;<code>workers[j]</code>&nbsp;。每个工人只能完成 <strong>一个</strong>&nbsp;任务，且力量值需要 <strong>大于等于</strong>&nbsp;该任务的力量要求值（即&nbsp;<code>workers[j] &gt;= tasks[i]</code>&nbsp;）。</p>

<p>除此以外，你还有&nbsp;<code>pills</code>&nbsp;个神奇药丸，可以给 <strong>一个工人的力量值</strong>&nbsp;增加&nbsp;<code>strength</code>&nbsp;。你可以决定给哪些工人使用药丸，但每个工人&nbsp;<strong>最多</strong>&nbsp;只能使用&nbsp;<strong>一片</strong>&nbsp;药丸。</p>

<p>给你下标从 <strong>0</strong>&nbsp;开始的整数数组<code>tasks</code> 和&nbsp;<code>workers</code>&nbsp;以及两个整数&nbsp;<code>pills</code> 和&nbsp;<code>strength</code>&nbsp;，请你返回 <strong>最多</strong>&nbsp;有多少个任务可以被完成。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>tasks = [<em><strong>3</strong></em>,<em><strong>2</strong></em>,<em><strong>1</strong></em>], workers = [<em><strong>0</strong></em>,<em><strong>3</strong></em>,<em><strong>3</strong></em>], pills = 1, strength = 1
<b>输出：</b>3
<strong>解释：</strong>
我们可以按照如下方案安排药丸：
- 给 0 号工人药丸。
- 0 号工人完成任务 2（0 + 1 &gt;= 1）
- 1 号工人完成任务 1（3 &gt;= 2）
- 2 号工人完成任务 0（3 &gt;= 3）
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>tasks = [<em><strong>5</strong></em>,4], workers = [<em><strong>0</strong></em>,0,0], pills = 1, strength = 5
<b>输出：</b>1
<strong>解释：</strong>
我们可以按照如下方案安排药丸：
- 给 0 号工人药丸。
- 0 号工人完成任务 0（0 + 5 &gt;= 5）
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>tasks = [<em><strong>10</strong></em>,<em><strong>15</strong></em>,30], workers = [<em><strong>0</strong></em>,<em><strong>10</strong></em>,10,10,10], pills = 3, strength = 10
<b>输出：</b>2
<strong>解释：</strong>
我们可以按照如下方案安排药丸：
- 给 0 号和 1 号工人药丸。
- 0 号工人完成任务 0（0 + 10 &gt;= 10）
- 1 号工人完成任务 1（10 + 10 &gt;= 15）
</pre>

<p><strong>示例 4：</strong></p>

<pre><b>输入：</b>tasks = [<em><strong>5</strong></em>,9,<em><strong>8</strong></em>,<em><strong>5</strong></em>,9], workers = [1,<em><strong>6</strong></em>,<em><strong>4</strong></em>,2,<em><strong>6</strong></em>], pills = 1, strength = 5
<b>输出：</b>3
<strong>解释：</strong>
我们可以按照如下方案安排药丸：
- 给 2 号工人药丸。
- 1 号工人完成任务 0（6 &gt;= 5）
- 2 号工人完成任务 2（4 + 5 &gt;= 8）
- 4 号工人完成任务 3（6 &gt;= 5）
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == tasks.length</code></li>
	<li><code>m == workers.length</code></li>
	<li><code>1 &lt;= n, m &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>0 &lt;= pills &lt;= m</code></li>
	<li><code>0 &lt;= tasks[i], workers[j], strength &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 二分查找

将任务按照完成时间从小到大排序，将工人按照能力从小到大排序。

假设我们要安排的任务数为 $x$，那么我们可以贪心地将前 $x$ 个任务分配给力量值最大的 $x$ 个工人。假设能完成任务数为 $x$，那么也一定能完成任务数为 $x-1$，$x-2$，$x-3$，…，$1$，$0$ 的情况。因此，我们可以使用二分查找的方法，找到最大的 $x$，使得能够完成任务数为 $x$ 的情况。

我们定义一个函数 $check(x)$，表示是否能够完成任务数为 $x$ 的情况。

函数 $check(x)$ 的实现如下：

从小到大遍历力量值最大的 $x$ 个工人，记当前遍历到的工人为 $j$，那么当前可选任务必须满足 $tasks[i] \leq workers[j] + strength$。

如果当前可选任务中要求力量值最小的一个 $task[i]$ 小于等于 $workers[j]$，那么第 $j$ 个工人不用吃药就可以完成任务 $task[i]$。否则，当前工人必须吃药，如果还有药丸，那么吃药，并且在当前可选任务中选择要求力量值最大的一个任务完成。否则，返回 `false`。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为任务数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxTaskAssign(
        self, tasks: List[int], workers: List[int], pills: int, strength: int
    ) -> int:
        def check(x):
            i = 0
            q = deque()
            p = pills
            for j in range(m - x, m):
                while i < x and tasks[i] <= workers[j] + strength:
                    q.append(tasks[i])
                    i += 1
                if not q:
                    return False
                if q[0] <= workers[j]:
                    q.popleft()
                elif p == 0:
                    return False
                else:
                    p -= 1
                    q.pop()
            return True

        n, m = len(tasks), len(workers)
        tasks.sort()
        workers.sort()
        left, right = 0, min(n, m)
        while left < right:
            mid = (left + right + 1) >> 1
            if check(mid):
                left = mid
            else:
                right = mid - 1
        return left
```

#### Java

```java
class Solution {
    private int[] tasks;
    private int[] workers;
    private int strength;
    private int pills;
    private int m;
    private int n;

    public int maxTaskAssign(int[] tasks, int[] workers, int pills, int strength) {
        Arrays.sort(tasks);
        Arrays.sort(workers);
        this.tasks = tasks;
        this.workers = workers;
        this.strength = strength;
        this.pills = pills;
        n = tasks.length;
        m = workers.length;
        int left = 0, right = Math.min(m, n);
        while (left < right) {
            int mid = (left + right + 1) >> 1;
            if (check(mid)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }

    private boolean check(int x) {
        int i = 0;
        Deque<Integer> q = new ArrayDeque<>();
        int p = pills;
        for (int j = m - x; j < m; ++j) {
            while (i < x && tasks[i] <= workers[j] + strength) {
                q.offer(tasks[i++]);
            }
            if (q.isEmpty()) {
                return false;
            }
            if (q.peekFirst() <= workers[j]) {
                q.pollFirst();
            } else if (p == 0) {
                return false;
            } else {
                --p;
                q.pollLast();
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
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        int n = tasks.size(), m = workers.size();
        int left = 0, right = min(m, n);
        auto check = [&](int x) {
            int p = pills;
            deque<int> q;
            int i = 0;
            for (int j = m - x; j < m; ++j) {
                while (i < x && tasks[i] <= workers[j] + strength) {
                    q.push_back(tasks[i++]);
                }
                if (q.empty()) {
                    return false;
                }
                if (q.front() <= workers[j]) {
                    q.pop_front();
                } else if (p == 0) {
                    return false;
                } else {
                    --p;
                    q.pop_back();
                }
            }
            return true;
        };
        while (left < right) {
            int mid = (left + right + 1) >> 1;
            if (check(mid)) {
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
func maxTaskAssign(tasks []int, workers []int, pills int, strength int) int {
	sort.Ints(tasks)
	sort.Ints(workers)
	n, m := len(tasks), len(workers)
	left, right := 0, min(m, n)
	check := func(x int) bool {
		p := pills
		q := []int{}
		i := 0
		for j := m - x; j < m; j++ {
			for i < x && tasks[i] <= workers[j]+strength {
				q = append(q, tasks[i])
				i++
			}
			if len(q) == 0 {
				return false
			}
			if q[0] <= workers[j] {
				q = q[1:]
			} else if p == 0 {
				return false
			} else {
				p--
				q = q[:len(q)-1]
			}
		}
		return true
	}
	for left < right {
		mid := (left + right + 1) >> 1
		if check(mid) {
			left = mid
		} else {
			right = mid - 1
		}
	}
	return left
}
```

#### TypeScript

```ts
function maxTaskAssign(
    tasks: number[],
    workers: number[],
    pills: number,
    strength: number,
): number {
    tasks.sort((a, b) => a - b);
    workers.sort((a, b) => a - b);

    const n = tasks.length;
    const m = workers.length;

    const check = (x: number): boolean => {
        const dq = new Array<number>(x);
        let head = 0;
        let tail = 0;
        const empty = () => head === tail;
        const pushBack = (val: number) => {
            dq[tail++] = val;
        };
        const popFront = () => {
            head++;
        };
        const popBack = () => {
            tail--;
        };
        const front = () => dq[head];

        let i = 0;
        let p = pills;

        for (let j = m - x; j < m; j++) {
            while (i < x && tasks[i] <= workers[j] + strength) {
                pushBack(tasks[i]);
                i++;
            }

            if (empty()) return false;

            if (front() <= workers[j]) {
                popFront();
            } else {
                if (p === 0) return false;
                p--;
                popBack();
            }
        }
        return true;
    };

    let [left, right] = [0, Math.min(n, m)];
    while (left < right) {
        const mid = (left + right + 1) >> 1;
        if (check(mid)) left = mid;
        else right = mid - 1;
    }
    return left;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2072. 赢得比赛的大学 🔒](https://leetcode.cn/problems/the-winner-university){#2072}

{{< tabs "2072" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT
    CASE
        WHEN n1.cnt > n2.cnt THEN 'New York University'
        WHEN n1.cnt < n2.cnt THEN 'California University'
        ELSE 'No Winner'
    END AS winner
FROM
    (SELECT COUNT(1) AS cnt FROM NewYork WHERE score >= 90) AS n1,
    (SELECT COUNT(1) AS cnt FROM California WHERE score >= 90) AS n2;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表： <code>NewYork</code></p>

<pre>
+-------------+------+
| Column Name | Type |
+-------------+------+
| student_id  | int  |
| score       | int  |
+-------------+------+
在 SQL 中，student_id 是这个表的主键。
每一行包含纽约大学 (New York University) 中一名学生一次考试的成绩。
</pre>

<p>&nbsp;</p>

<p>表： <code>California</code></p>

<pre>
+-------------+------+
| Column Name | Type |
+-------------+------+
| student_id  | int  |
| score       | int  |
+-------------+------+
在 SQL 中，student_id 是这个表的主键。
每一行包含加州大学 (California University) 中一名学生一次考试的成绩。
</pre>

<p>&nbsp;</p>

<p>纽约大学和加州大学之间举行了一场比赛。这场比赛由两所大学中相同数量的学生参加。拥有更多<strong>优秀学生</strong>的大学赢得这场比赛。如果两所大学的<strong>优秀学生</strong>数量相同，则这场比赛平局。</p>

<p><strong>优秀学生</strong>是指在考试中获得 <code>90%</code> 或更高成绩的学生。</p>

<p>返回：</p>

<ul>
	<li><strong>"New York University"</strong> 若纽约大学赢得这场比赛。</li>
	<li><strong>"California University"</strong> 若加州大学赢得这场比赛。</li>
	<li><strong>"No Winner"</strong> 若这场比赛平局。</li>
</ul>

<p>返回结果格式如下示例所示：</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> 
NewYork 表:
+------------+-------+
| student_id | score |
+------------+-------+
| 1          | 90    |
| 2          | 87    |
+------------+-------+
California 表:
+------------+-------+
| student_id | score |
+------------+-------+
| 2          | 89    |
| 3          | 88    |
+------------+-------+
<strong>输出:</strong> 
+---------------------+
| winner              |
+---------------------+
| New York University |
+---------------------+
<strong>解释:</strong>
纽约大学有 1 名优秀学生，加州大学有 0 名优秀学生。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> 
NewYork 表:
+------------+-------+
| student_id | score |
+------------+-------+
| 1          | 89    |
| 2          | 88    |
+------------+-------+
California 表:
+------------+-------+
| student_id | score |
+------------+-------+
| 2          | 90    |
| 3          | 87    |
+------------+-------+
<strong>输出:</strong> 
+-----------------------+
| winner                |
+-----------------------+
| California University |
+-----------------------+
<strong>解释:</strong>
纽约大学有 0 名优秀学生，加州大学有 1 名优秀学生。
</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入:</strong> 
NewYork 表:
+------------+-------+
| student_id | score |
+------------+-------+
| 1          | 89    |
| 2          | 90    |
+------------+-------+
California 表:
+------------+-------+
| student_id | score |
+------------+-------+
| 2          | 87    |
| 3          | 99    |
+------------+-------+
<strong>输出:</strong> 
+-----------+
| winner    |
+-----------+
| No Winner |
+-----------+
<strong>解释:</strong>
纽约大学和加州大学均有 1 名优秀学生。
</pre>

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
    CASE
        WHEN n1.cnt > n2.cnt THEN 'New York University'
        WHEN n1.cnt < n2.cnt THEN 'California University'
        ELSE 'No Winner'
    END AS winner
FROM
    (SELECT COUNT(1) AS cnt FROM NewYork WHERE score >= 90) AS n1,
    (SELECT COUNT(1) AS cnt FROM California WHERE score >= 90) AS n2;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2073. 买票需要的时间](https://leetcode.cn/problems/time-needed-to-buy-tickets){#2073}

{{< tabs "2073" >}}

{{% tab "python" %}}
```python
class Solution:
    def timeRequiredToBuy(self, tickets: List[int], k: int) -> int:
        ans = 0
        for i, x in enumerate(tickets):
            ans += min(x, tickets[k] if i <= k else tickets[k] - 1)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int timeRequiredToBuy(int[] tickets, int k) {
        int ans = 0;
        for (int i = 0; i < tickets.length; ++i) {
            ans += Math.min(tickets[i], i <= k ? tickets[k] : tickets[k] - 1);
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
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ans = 0;
        for (int i = 0; i < tickets.size(); ++i) {
            ans += min(tickets[i], i <= k ? tickets[k] : tickets[k] - 1);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func timeRequiredToBuy(tickets []int, k int) (ans int) {
	for i, x := range tickets {
		t := tickets[k]
		if i > k {
			t--
		}
		ans += min(x, t)
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function timeRequiredToBuy(tickets: number[], k: number): number {
    let ans = 0;
    const n = tickets.length;
    for (let i = 0; i < n; ++i) {
        ans += Math.min(tickets[i], i <= k ? tickets[k] : tickets[k] - 1);
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

<p>有 <code>n</code> 个人前来排队买票，其中第 <code>0</code> 人站在队伍 <strong>最前方</strong> ，第 <code>(n - 1)</code> 人站在队伍 <strong>最后方</strong> 。</p>

<p>给你一个下标从 <strong>0</strong> 开始的整数数组 <code>tickets</code> ，数组长度为 <code>n</code> ，其中第 <code>i</code> 人想要购买的票数为 <code>tickets[i]</code> 。</p>

<p>每个人买票都需要用掉 <strong>恰好 1 秒</strong> 。一个人 <strong>一次只能买一张票</strong> ，如果需要购买更多票，他必须走到&nbsp; <strong>队尾</strong> 重新排队（<strong>瞬间 </strong>发生，不计时间）。如果一个人没有剩下需要买的票，那他将会 <strong>离开</strong> 队伍。</p>

<p>返回位于位置 <code>k</code>（下标从 <strong>0</strong> 开始）的人完成买票需要的时间（以秒为单位）。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong>tickets = [2,3,2], k = 2</p>

<p><strong>输出：</strong>6</p>

<p><strong>解释：</strong></p>

<ul>
	<li>队伍一开始为 [2,3,2]，第 k 个人以下划线标识。</li>
	<li>在最前面的人买完票后，队伍在第 1 秒变成 [3,<u>2</u>,1]。</li>
	<li>继续这个过程，队伍在第 2 秒变为[<u>2</u>,1,2]。</li>
	<li>继续这个过程，队伍在第 3 秒变为[1,2,<u>1</u>]。</li>
	<li>继续这个过程，队伍在第 4 秒变为[2,<u>1</u>]。</li>
	<li>继续这个过程，队伍在第 5 秒变为[<u>1</u>,1]。</li>
	<li>继续这个过程，队伍在第 6 秒变为[1]。第 k 个人完成买票，所以返回 6。</li>
</ul>
</div>

<p><strong>示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong>tickets = [5,1,1,1], k = 0</p>

<p><strong>输出：</strong>8</p>

<p><strong>解释：</strong></p>

<ul>
	<li>队伍一开始为 [<u>5</u>,1,1,1]，第 k 个人以下划线标识。</li>
	<li>在最前面的人买完票后，队伍在第 1 秒变成 [1,1,1,<u>4</u>]。</li>
	<li>继续这个过程 3 秒，队伍在第 4&nbsp;秒变为[<u>4</u>]。</li>
	<li>继续这个过程 4 秒，队伍在第 8&nbsp;秒变为[]。第 k 个人完成买票，所以返回 8。</li>
</ul>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == tickets.length</code></li>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>1 &lt;= tickets[i] &lt;= 100</code></li>
	<li><code>0 &lt;= k &lt; n</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：一次遍历

根据题目描述，当第 $k$ 个人完成购票时，在第 $k$ 个人前面的所有人，购买的票数都不会超过第 $k$ 个人购买的票数，而在第 $k$ 个人后面的所有人，购买的票数都不会超过第 $k$ 个人购买的票数减 $1$。

因此，我们可以遍历整个队伍，对于第 $i$ 个人，如果 $i \leq k$，购票时间为 $\min(\textit{tickets}[i], \textit{tickets}[k])$，否则购票时间为 $\min(\textit{tickets}[i], \textit{tickets}[k] - 1)$。我们将所有人的购票时间相加即可。

时间复杂度 $O(n)$，其中 $n$ 为队伍的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def timeRequiredToBuy(self, tickets: List[int], k: int) -> int:
        ans = 0
        for i, x in enumerate(tickets):
            ans += min(x, tickets[k] if i <= k else tickets[k] - 1)
        return ans
```

#### Java

```java
class Solution {
    public int timeRequiredToBuy(int[] tickets, int k) {
        int ans = 0;
        for (int i = 0; i < tickets.length; ++i) {
            ans += Math.min(tickets[i], i <= k ? tickets[k] : tickets[k] - 1);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ans = 0;
        for (int i = 0; i < tickets.size(); ++i) {
            ans += min(tickets[i], i <= k ? tickets[k] : tickets[k] - 1);
        }
        return ans;
    }
};
```

#### Go

```go
func timeRequiredToBuy(tickets []int, k int) (ans int) {
	for i, x := range tickets {
		t := tickets[k]
		if i > k {
			t--
		}
		ans += min(x, t)
	}
	return
}
```

#### TypeScript

```ts
function timeRequiredToBuy(tickets: number[], k: number): number {
    let ans = 0;
    const n = tickets.length;
    for (let i = 0; i < n; ++i) {
        ans += Math.min(tickets[i], i <= k ? tickets[k] : tickets[k] - 1);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2074. 反转偶数长度组的节点](https://leetcode.cn/problems/reverse-nodes-in-even-length-groups){#2074}

{{< tabs "2074" >}}

{{% tab "python" %}}
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseEvenLengthGroups(self, head: Optional[ListNode]) -> Optional[ListNode]:
        def reverse(head, l):
            prev, cur, tail = None, head, head
            i = 0
            while cur and i < l:
                t = cur.next
                cur.next = prev
                prev = cur
                cur = t
                i += 1
            tail.next = cur
            return prev

        n = 0
        t = head
        while t:
            t = t.next
            n += 1
        dummy = ListNode(0, head)
        prev = dummy
        l = 1
        while (1 + l) * l // 2 <= n and prev:
            if l % 2 == 0:
                prev.next = reverse(prev.next, l)
            i = 0
            while i < l and prev:
                prev = prev.next
                i += 1
            l += 1
        left = n - l * (l - 1) // 2
        if left > 0 and left % 2 == 0:
            prev.next = reverse(prev.next, left)
        return dummy.next
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
    public ListNode reverseEvenLengthGroups(ListNode head) {
        int n = 0;
        for (ListNode t = head; t != null; t = t.next) {
            ++n;
        }
        ListNode dummy = new ListNode(0, head);
        ListNode prev = dummy;
        int l = 1;
        for (; (1 + l) * l / 2 <= n && prev != null; ++l) {
            if (l % 2 == 0) {
                ListNode node = prev.next;
                prev.next = reverse(node, l);
            }
            for (int i = 0; i < l && prev != null; ++i) {
                prev = prev.next;
            }
        }
        int left = n - l * (l - 1) / 2;
        if (left > 0 && left % 2 == 0) {
            ListNode node = prev.next;
            prev.next = reverse(node, left);
        }
        return dummy.next;
    }

    private ListNode reverse(ListNode head, int l) {
        ListNode prev = null;
        ListNode cur = head;
        ListNode tail = cur;
        int i = 0;
        while (cur != null && i < l) {
            ListNode t = cur.next;
            cur.next = prev;
            prev = cur;
            cur = t;
            ++i;
        }
        tail.next = cur;
        return prev;
    }
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

function reverseEvenLengthGroups(head: ListNode | null): ListNode | null {
    let nums = [];
    let cur = head;
    while (cur) {
        nums.push(cur.val);
        cur = cur.next;
    }

    const n = nums.length;
    for (let i = 0, k = 1; i < n; i += k, k++) {
        // 最后一组， 可能出现不足
        k = Math.min(n - i, k);
        if (!(k & 1)) {
            let tmp = nums.splice(i, k);
            tmp.reverse();
            nums.splice(i, 0, ...tmp);
        }
    }

    cur = head;
    for (let num of nums) {
        cur.val = num;
        cur = cur.next;
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

<p>给你一个链表的头节点 <code>head</code> 。</p>

<p>链表中的节点 <strong>按顺序</strong> 划分成若干 <strong>非空</strong> 组，这些非空组的长度构成一个自然数序列（<code>1, 2, 3, 4, ...</code>）。一个组的 <strong>长度</strong> 就是组中分配到的节点数目。换句话说：</p>

<ul>
	<li>节点 <code>1</code> 分配给第一组</li>
	<li>节点 <code>2</code> 和 <code>3</code> 分配给第二组</li>
	<li>节点 <code>4</code>、<code>5</code> 和 <code>6</code> 分配给第三组，以此类推</li>
</ul>

<p>注意，最后一组的长度可能小于或者等于 <code>1 + 倒数第二组的长度</code> 。</p>

<p><strong>反转</strong> 每个 <strong>偶数</strong> 长度组中的节点，并返回修改后链表的头节点 <code>head</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2074.Reverse%20Nodes%20in%20Even%20Length%20Groups/images/eg1.png" style="width: 699px; height: 124px;" /></p>

<pre>
<strong>输入：</strong>head = [5,2,6,3,9,1,7,3,8,4]
<strong>输出：</strong>[5,6,2,3,9,1,4,8,3,7]
<strong>解释：</strong>
- 第一组长度为 1 ，奇数，没有发生反转。
- 第二组长度为 2 ，偶数，节点反转。
- 第三组长度为 3 ，奇数，没有发生反转。
- 最后一组长度为 4 ，偶数，节点反转。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2074.Reverse%20Nodes%20in%20Even%20Length%20Groups/images/eg2.png" style="width: 284px; height: 114px;" /></p>

<pre>
<strong>输入：</strong>head = [1,1,0,6]
<strong>输出：</strong>[1,0,1,6]
<strong>解释：</strong>
- 第一组长度为 1 ，没有发生反转。
- 第二组长度为 2 ，节点反转。
- 最后一组长度为 1 ，没有发生反转。
</pre>

<p><strong>示例 3：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2074.Reverse%20Nodes%20in%20Even%20Length%20Groups/images/eg3.png" style="width: 139px; height: 114px;" /></p>

<pre>
<strong>输入：</strong>head = [2,1]
<strong>输出：</strong>[2,1]
<strong>解释：</strong>
- 第一组长度为 1 ，没有发生反转。
- 最后一组长度为 1 ，没有发生反转。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>链表中节点数目范围是 <code>[1, 10<sup>5</sup>]</code></li>
	<li><code>0 &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
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
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseEvenLengthGroups(self, head: Optional[ListNode]) -> Optional[ListNode]:
        def reverse(head, l):
            prev, cur, tail = None, head, head
            i = 0
            while cur and i < l:
                t = cur.next
                cur.next = prev
                prev = cur
                cur = t
                i += 1
            tail.next = cur
            return prev

        n = 0
        t = head
        while t:
            t = t.next
            n += 1
        dummy = ListNode(0, head)
        prev = dummy
        l = 1
        while (1 + l) * l // 2 <= n and prev:
            if l % 2 == 0:
                prev.next = reverse(prev.next, l)
            i = 0
            while i < l and prev:
                prev = prev.next
                i += 1
            l += 1
        left = n - l * (l - 1) // 2
        if left > 0 and left % 2 == 0:
            prev.next = reverse(prev.next, left)
        return dummy.next
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
    public ListNode reverseEvenLengthGroups(ListNode head) {
        int n = 0;
        for (ListNode t = head; t != null; t = t.next) {
            ++n;
        }
        ListNode dummy = new ListNode(0, head);
        ListNode prev = dummy;
        int l = 1;
        for (; (1 + l) * l / 2 <= n && prev != null; ++l) {
            if (l % 2 == 0) {
                ListNode node = prev.next;
                prev.next = reverse(node, l);
            }
            for (int i = 0; i < l && prev != null; ++i) {
                prev = prev.next;
            }
        }
        int left = n - l * (l - 1) / 2;
        if (left > 0 && left % 2 == 0) {
            ListNode node = prev.next;
            prev.next = reverse(node, left);
        }
        return dummy.next;
    }

    private ListNode reverse(ListNode head, int l) {
        ListNode prev = null;
        ListNode cur = head;
        ListNode tail = cur;
        int i = 0;
        while (cur != null && i < l) {
            ListNode t = cur.next;
            cur.next = prev;
            prev = cur;
            cur = t;
            ++i;
        }
        tail.next = cur;
        return prev;
    }
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

function reverseEvenLengthGroups(head: ListNode | null): ListNode | null {
    let nums = [];
    let cur = head;
    while (cur) {
        nums.push(cur.val);
        cur = cur.next;
    }

    const n = nums.length;
    for (let i = 0, k = 1; i < n; i += k, k++) {
        // 最后一组， 可能出现不足
        k = Math.min(n - i, k);
        if (!(k & 1)) {
            let tmp = nums.splice(i, k);
            tmp.reverse();
            nums.splice(i, 0, ...tmp);
        }
    }

    cur = head;
    for (let num of nums) {
        cur.val = num;
        cur = cur.next;
    }
    return head;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2075. 解码斜向换位密码](https://leetcode.cn/problems/decode-the-slanted-ciphertext){#2075}

{{< tabs "2075" >}}

{{% tab "python" %}}
```python
class Solution:
    def decodeCiphertext(self, encodedText: str, rows: int) -> str:
        ans = []
        cols = len(encodedText) // rows
        for j in range(cols):
            x, y = 0, j
            while x < rows and y < cols:
                ans.append(encodedText[x * cols + y])
                x, y = x + 1, y + 1
        return ''.join(ans).rstrip()
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String decodeCiphertext(String encodedText, int rows) {
        StringBuilder ans = new StringBuilder();
        int cols = encodedText.length() / rows;
        for (int j = 0; j < cols; ++j) {
            for (int x = 0, y = j; x < rows && y < cols; ++x, ++y) {
                ans.append(encodedText.charAt(x * cols + y));
            }
        }
        while (ans.length() > 0 && ans.charAt(ans.length() - 1) == ' ') {
            ans.deleteCharAt(ans.length() - 1);
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
    string decodeCiphertext(string encodedText, int rows) {
        string ans;
        int cols = encodedText.size() / rows;
        for (int j = 0; j < cols; ++j) {
            for (int x = 0, y = j; x < rows && y < cols; ++x, ++y) {
                ans += encodedText[x * cols + y];
            }
        }
        while (ans.size() && ans.back() == ' ') {
            ans.pop_back();
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func decodeCiphertext(encodedText string, rows int) string {
	ans := []byte{}
	cols := len(encodedText) / rows
	for j := 0; j < cols; j++ {
		for x, y := 0, j; x < rows && y < cols; x, y = x+1, y+1 {
			ans = append(ans, encodedText[x*cols+y])
		}
	}
	for len(ans) > 0 && ans[len(ans)-1] == ' ' {
		ans = ans[:len(ans)-1]
	}
	return string(ans)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function decodeCiphertext(encodedText: string, rows: number): string {
    const cols = Math.ceil(encodedText.length / rows);
    const ans: string[] = [];
    for (let k = 0; k <= cols; k++) {
        for (let i = 0, j = k; i < rows && j < cols; i++, j++) {
            ans.push(encodedText[i * cols + j]);
        }
    }
    return ans.join('').trimEnd();
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>字符串 <code>originalText</code> 使用 <strong>斜向换位密码</strong> ，经由 <strong>行数固定</strong> 为 <code>rows</code> 的矩阵辅助，加密得到一个字符串 <code>encodedText</code> 。</p>

<p><code>originalText</code> 先按从左上到右下的方式放置到矩阵中。</p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2075.Decode%20the%20Slanted%20Ciphertext/images/exa11.png" style="width: 300px; height: 185px;" />
<p>先填充蓝色单元格，接着是红色单元格，然后是黄色单元格，以此类推，直到到达 <code>originalText</code> 末尾。箭头指示顺序即为单元格填充顺序。所有空单元格用 <code>' '</code> 进行填充。矩阵的列数需满足：用 <code>originalText</code> 填充之后，最右侧列 <strong>不为空</strong> 。</p>

<p>接着按行将字符附加到矩阵中，构造&nbsp;<code>encodedText</code> 。</p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2075.Decode%20the%20Slanted%20Ciphertext/images/exa12.png" style="width: 300px; height: 200px;" />
<p>先把蓝色单元格中的字符附加到 <code>encodedText</code> 中，接着是红色单元格，最后是黄色单元格。箭头指示单元格访问顺序。</p>

<p>例如，如果 <code>originalText = "cipher"</code> 且 <code>rows = 3</code> ，那么我们可以按下述方法将其编码：</p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2075.Decode%20the%20Slanted%20Ciphertext/images/desc2.png" style="width: 281px; height: 211px;" />
<p>蓝色箭头标识 <code>originalText</code> 是如何放入矩阵中的，红色箭头标识形成 <code>encodedText</code> 的顺序。在上述例子中，<code>encodedText = "ch&nbsp; &nbsp;ie&nbsp; &nbsp;pr"</code> 。</p>

<p>给你编码后的字符串 <code>encodedText</code> 和矩阵的行数 <code>rows</code> ，返回源字符串 <code>originalText</code> 。</p>

<p><strong>注意：</strong><code>originalText</code> <strong>不</strong> 含任何尾随空格 <code>' '</code> 。生成的测试用例满足 <strong>仅存在一个</strong> 可能的 <code>originalText</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>encodedText = "ch   ie   pr", rows = 3
<strong>输出：</strong>"cipher"
<strong>解释：</strong>此示例与问题描述中的例子相同。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2075.Decode%20the%20Slanted%20Ciphertext/images/exam1.png" style="width: 250px; height: 168px;" /></p>

<pre>
<strong>输入：</strong>encodedText = "iveo    eed   l te   olc", rows = 4
<strong>输出：</strong>"i love leetcode"
<strong>解释：</strong>上图标识用于编码 originalText 的矩阵。 
蓝色箭头展示如何从 encodedText 找到 originalText 。
</pre>

<p><strong>示例 3：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2075.Decode%20the%20Slanted%20Ciphertext/images/eg2.png" style="width: 300px; height: 51px;" /></p>

<pre>
<strong>输入：</strong>encodedText = "coding", rows = 1
<strong>输出：</strong>"coding"
<strong>解释：</strong>由于只有 1 行，所以 originalText 和 encodedText 是相同的。
</pre>

<p><strong>示例 4：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2075.Decode%20the%20Slanted%20Ciphertext/images/exam3.png" style="width: 150px; height: 101px;" />
<pre>
<strong>输入：</strong>encodedText = " b  ac", rows = 2
<strong>输出：</strong>" abc"
<strong>解释：</strong>originalText 不能含尾随空格，但它可能会有一个或者多个前置空格。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= encodedText.length &lt;= 10<sup>6</sup></code></li>
	<li><code>encodedText</code> 仅由小写英文字母和 <code>' '</code> 组成</li>
	<li><code>encodedText</code> 是对某个 <strong>不含</strong> 尾随空格的 <code>originalText</code> 的一个有效编码</li>
	<li><code>1 &lt;= rows &lt;= 1000</code></li>
	<li>生成的测试用例满足 <strong>仅存在一个</strong> 可能的 <code>originalText</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们先计算出矩阵的列数 $cols = \textit{len}(encodedText) / rows$，然后按照题目描述的规则，从左上角开始遍历矩阵，将字符添加到答案中。

最后返回答案，注意去掉末尾的空格。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为字符串 $encodedText$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def decodeCiphertext(self, encodedText: str, rows: int) -> str:
        ans = []
        cols = len(encodedText) // rows
        for j in range(cols):
            x, y = 0, j
            while x < rows and y < cols:
                ans.append(encodedText[x * cols + y])
                x, y = x + 1, y + 1
        return ''.join(ans).rstrip()
```

#### Java

```java
class Solution {
    public String decodeCiphertext(String encodedText, int rows) {
        StringBuilder ans = new StringBuilder();
        int cols = encodedText.length() / rows;
        for (int j = 0; j < cols; ++j) {
            for (int x = 0, y = j; x < rows && y < cols; ++x, ++y) {
                ans.append(encodedText.charAt(x * cols + y));
            }
        }
        while (ans.length() > 0 && ans.charAt(ans.length() - 1) == ' ') {
            ans.deleteCharAt(ans.length() - 1);
        }
        return ans.toString();
    }
}
```

#### C++

```cpp
class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        string ans;
        int cols = encodedText.size() / rows;
        for (int j = 0; j < cols; ++j) {
            for (int x = 0, y = j; x < rows && y < cols; ++x, ++y) {
                ans += encodedText[x * cols + y];
            }
        }
        while (ans.size() && ans.back() == ' ') {
            ans.pop_back();
        }
        return ans;
    }
};
```

#### Go

```go
func decodeCiphertext(encodedText string, rows int) string {
	ans := []byte{}
	cols := len(encodedText) / rows
	for j := 0; j < cols; j++ {
		for x, y := 0, j; x < rows && y < cols; x, y = x+1, y+1 {
			ans = append(ans, encodedText[x*cols+y])
		}
	}
	for len(ans) > 0 && ans[len(ans)-1] == ' ' {
		ans = ans[:len(ans)-1]
	}
	return string(ans)
}
```

#### TypeScript

```ts
function decodeCiphertext(encodedText: string, rows: number): string {
    const cols = Math.ceil(encodedText.length / rows);
    const ans: string[] = [];
    for (let k = 0; k <= cols; k++) {
        for (let i = 0, j = k; i < rows && j < cols; i++, j++) {
            ans.push(encodedText[i * cols + j]);
        }
    }
    return ans.join('').trimEnd();
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2076. 处理含限制条件的好友请求](https://leetcode.cn/problems/process-restricted-friend-requests){#2076}

{{< tabs "2076" >}}

{{% tab "python" %}}
```python
class Solution:
    def friendRequests(
        self, n: int, restrictions: List[List[int]], requests: List[List[int]]
    ) -> List[bool]:
        def find(x: int) -> int:
            if p[x] != x:
                p[x] = find(p[x])
            return p[x]

        p = list(range(n))
        ans = []
        for u, v in requests:
            pu, pv = find(u), find(v)
            if pu == pv:
                ans.append(True)
            else:
                ok = True
                for x, y in restrictions:
                    px, py = find(x), find(y)
                    if (pu == px and pv == py) or (pu == py and pv == px):
                        ok = False
                        break
                ans.append(ok)
                if ok:
                    p[pu] = pv
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[] p;

    public boolean[] friendRequests(int n, int[][] restrictions, int[][] requests) {
        p = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
        }
        int m = requests.length;
        boolean[] ans = new boolean[m];
        for (int i = 0; i < m; ++i) {
            int u = requests[i][0], v = requests[i][1];
            int pu = find(u), pv = find(v);
            if (pu == pv) {
                ans[i] = true;
            } else {
                boolean ok = true;
                for (var r : restrictions) {
                    int px = find(r[0]), py = find(r[1]);
                    if ((pu == px && pv == py) || (pu == py && pv == px)) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    ans[i] = true;
                    p[pu] = pv;
                }
            }
        }
        return ans;
    }

    private int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        vector<int> p(n);
        iota(p.begin(), p.end(), 0);
        function<int(int)> find = [&](int x) {
            if (p[x] != x) {
                p[x] = find(p[x]);
            }
            return p[x];
        };
        vector<bool> ans;
        for (auto& req : requests) {
            int u = req[0], v = req[1];
            int pu = find(u), pv = find(v);
            if (pu == pv) {
                ans.push_back(true);
            } else {
                bool ok = true;
                for (auto& r : restrictions) {
                    int px = find(r[0]), py = find(r[1]);
                    if ((pu == px && pv == py) || (pu == py && pv == px)) {
                        ok = false;
                        break;
                    }
                }
                ans.push_back(ok);
                if (ok) {
                    p[pu] = pv;
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
func friendRequests(n int, restrictions [][]int, requests [][]int) (ans []bool) {
	p := make([]int, n)
	for i := range p {
		p[i] = i
	}
	var find func(int) int
	find = func(x int) int {
		if p[x] != x {
			p[x] = find(p[x])
		}
		return p[x]
	}
	for _, req := range requests {
		pu, pv := find(req[0]), find(req[1])
		if pu == pv {
			ans = append(ans, true)
		} else {
			ok := true
			for _, r := range restrictions {
				px, py := find(r[0]), find(r[1])
				if px == pu && py == pv || px == pv && py == pu {
					ok = false
					break
				}
			}
			ans = append(ans, ok)
			if ok {
				p[pv] = pu
			}
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function friendRequests(n: number, restrictions: number[][], requests: number[][]): boolean[] {
    const p: number[] = Array.from({ length: n }, (_, i) => i);
    const find = (x: number): number => {
        if (p[x] !== x) {
            p[x] = find(p[x]);
        }
        return p[x];
    };
    const ans: boolean[] = [];
    for (const [u, v] of requests) {
        const pu = find(u);
        const pv = find(v);
        if (pu === pv) {
            ans.push(true);
        } else {
            let ok = true;
            for (const [x, y] of restrictions) {
                const px = find(x);
                const py = find(y);
                if ((px === pu && py === pv) || (px === pv && py === pu)) {
                    ok = false;
                    break;
                }
            }
            ans.push(ok);
            if (ok) {
                p[pu] = pv;
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

<p>给你一个整数 <code>n</code> ，表示网络上的用户数目。每个用户按从 <code>0</code> 到 <code>n - 1</code> 进行编号。</p>

<p>给你一个下标从 <strong>0</strong> 开始的二维整数数组 <code>restrictions</code> ，其中 <code>restrictions[i] = [x<sub>i</sub>, y<sub>i</sub>]</code> 意味着用户 <code>x<sub>i</sub></code> 和用户 <code>y<sub>i</sub></code> <strong>不能</strong> 成为 <strong>朋友</strong> ，不管是 <strong>直接</strong> 还是通过其他用户 <strong>间接</strong> 。</p>

<p>最初，用户里没有人是其他用户的朋友。给你一个下标从 <strong>0</strong> 开始的二维整数数组 <code>requests</code> 表示好友请求的列表，其中 <code>requests[j] = [u<sub>j</sub>, v<sub>j</sub>]</code> 是用户 <code>u<sub>j</sub></code> 和用户 <code>v<sub>j</sub></code> 之间的一条好友请求。</p>

<p>如果 <code>u<sub>j</sub></code> 和 <code>v<sub>j</sub></code> 可以成为 <strong>朋友</strong> ，那么好友请求将会 <strong>成功</strong> 。每个好友请求都会按列表中给出的顺序进行处理（即，<code>requests[j]</code> 会在 <code>requests[j + 1]</code> 前）。一旦请求成功，那么对所有未来的好友请求而言， <code>u<sub>j</sub></code> 和 <code>v<sub>j</sub></code> 将会 <strong>成为直接朋友 。</strong></p>

<p>返回一个 <strong>布尔数组</strong> <code>result</code> ，其中元素遵循此规则：如果第 <code>j</code> 个好友请求 <strong>成功</strong><em> </em>，那么 <code>result[j]</code><em> </em>就是<em> </em><code>true</code><em> </em>；否则，为<em> </em><code>false</code> 。</p>

<p><strong>注意：</strong>如果 <code>u<sub>j</sub></code> 和 <code>v<sub>j</sub></code> 已经是直接朋友，那么他们之间的请求将仍然&nbsp;<strong>成功</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 3, restrictions = [[0,1]], requests = [[0,2],[2,1]]
<strong>输出：</strong>[true,false]
<strong>解释：
</strong>请求 0 ：用户 0 和 用户 2 可以成为朋友，所以他们成为直接朋友。 
请求 1 ：用户 2 和 用户 1 不能成为朋友，因为这会使 用户 0 和 用户 1 成为间接朋友 (1--2--0) 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 3, restrictions = [[0,1]], requests = [[1,2],[0,2]]
<strong>输出：</strong>[true,false]
<strong>解释：</strong>
请求 0 ：用户 1 和 用户 2 可以成为朋友，所以他们成为直接朋友。 
请求 1 ：用户 0 和 用户 2 不能成为朋友，因为这会使 用户 0 和 用户 1 成为间接朋友 (0--2--1) 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 5, restrictions = [[0,1],[1,2],[2,3]], requests = [[0,4],[1,2],[3,1],[3,4]]
<strong>输出：</strong>[true,false,true,false]
<strong>解释：
</strong>请求 0 ：用户 0 和 用户 4 可以成为朋友，所以他们成为直接朋友。 
请求 1 ：用户 1 和 用户 2 不能成为朋友，因为他们之间存在限制。
请求 2 ：用户 3 和 用户 1 可以成为朋友，所以他们成为直接朋友。 
请求 3 ：用户 3 和 用户 4 不能成为朋友，因为这会使 用户 0 和 用户 1 成为间接朋友 (0--4--3--1) 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 1000</code></li>
	<li><code>0 &lt;= restrictions.length &lt;= 1000</code></li>
	<li><code>restrictions[i].length == 2</code></li>
	<li><code>0 &lt;= x<sub>i</sub>, y<sub>i</sub> &lt;= n - 1</code></li>
	<li><code>x<sub>i</sub> != y<sub>i</sub></code></li>
	<li><code>1 &lt;= requests.length &lt;= 1000</code></li>
	<li><code>requests[j].length == 2</code></li>
	<li><code>0 &lt;= u<sub>j</sub>, v<sub>j</sub> &lt;= n - 1</code></li>
	<li><code>u<sub>j</sub> != v<sub>j</sub></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：并查集

我们可以用并查集来维护朋友关系，然后对于每个请求，判断是否满足限制条件。

对于当前请求的两个人 $(u, v)$，如果他们已经是朋友，那么可以直接接受请求；否则，我们遍历限制条件，如果存在限制条件 $(x, y)$，使得 $u$ 和 $x$ 互为朋友并且 $v$ 和 $y$ 互为朋友，或者 $u$ 和 $y$ 互为朋友并且 $v$ 和 $x$ 互为朋友，那么就不能接受请求。

时间复杂度 $O(q \times m \times \log(n))$，空间复杂度 $O(n)$。其中 $q$ 和 $m$ 分别是请求的数量和限制条件的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def friendRequests(
        self, n: int, restrictions: List[List[int]], requests: List[List[int]]
    ) -> List[bool]:
        def find(x: int) -> int:
            if p[x] != x:
                p[x] = find(p[x])
            return p[x]

        p = list(range(n))
        ans = []
        for u, v in requests:
            pu, pv = find(u), find(v)
            if pu == pv:
                ans.append(True)
            else:
                ok = True
                for x, y in restrictions:
                    px, py = find(x), find(y)
                    if (pu == px and pv == py) or (pu == py and pv == px):
                        ok = False
                        break
                ans.append(ok)
                if ok:
                    p[pu] = pv
        return ans
```

#### Java

```java
class Solution {
    private int[] p;

    public boolean[] friendRequests(int n, int[][] restrictions, int[][] requests) {
        p = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
        }
        int m = requests.length;
        boolean[] ans = new boolean[m];
        for (int i = 0; i < m; ++i) {
            int u = requests[i][0], v = requests[i][1];
            int pu = find(u), pv = find(v);
            if (pu == pv) {
                ans[i] = true;
            } else {
                boolean ok = true;
                for (var r : restrictions) {
                    int px = find(r[0]), py = find(r[1]);
                    if ((pu == px && pv == py) || (pu == py && pv == px)) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    ans[i] = true;
                    p[pu] = pv;
                }
            }
        }
        return ans;
    }

    private int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        vector<int> p(n);
        iota(p.begin(), p.end(), 0);
        function<int(int)> find = [&](int x) {
            if (p[x] != x) {
                p[x] = find(p[x]);
            }
            return p[x];
        };
        vector<bool> ans;
        for (auto& req : requests) {
            int u = req[0], v = req[1];
            int pu = find(u), pv = find(v);
            if (pu == pv) {
                ans.push_back(true);
            } else {
                bool ok = true;
                for (auto& r : restrictions) {
                    int px = find(r[0]), py = find(r[1]);
                    if ((pu == px && pv == py) || (pu == py && pv == px)) {
                        ok = false;
                        break;
                    }
                }
                ans.push_back(ok);
                if (ok) {
                    p[pu] = pv;
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func friendRequests(n int, restrictions [][]int, requests [][]int) (ans []bool) {
	p := make([]int, n)
	for i := range p {
		p[i] = i
	}
	var find func(int) int
	find = func(x int) int {
		if p[x] != x {
			p[x] = find(p[x])
		}
		return p[x]
	}
	for _, req := range requests {
		pu, pv := find(req[0]), find(req[1])
		if pu == pv {
			ans = append(ans, true)
		} else {
			ok := true
			for _, r := range restrictions {
				px, py := find(r[0]), find(r[1])
				if px == pu && py == pv || px == pv && py == pu {
					ok = false
					break
				}
			}
			ans = append(ans, ok)
			if ok {
				p[pv] = pu
			}
		}
	}
	return
}
```

#### TypeScript

```ts
function friendRequests(n: number, restrictions: number[][], requests: number[][]): boolean[] {
    const p: number[] = Array.from({ length: n }, (_, i) => i);
    const find = (x: number): number => {
        if (p[x] !== x) {
            p[x] = find(p[x]);
        }
        return p[x];
    };
    const ans: boolean[] = [];
    for (const [u, v] of requests) {
        const pu = find(u);
        const pv = find(v);
        if (pu === pv) {
            ans.push(true);
        } else {
            let ok = true;
            for (const [x, y] of restrictions) {
                const px = find(x);
                const py = find(y);
                if ((px === pu && py === pv) || (px === pv && py === pu)) {
                    ok = false;
                    break;
                }
            }
            ans.push(ok);
            if (ok) {
                p[pu] = pv;
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

# [2077. 殊途同归 🔒](https://leetcode.cn/problems/paths-in-maze-that-lead-to-same-room){#2077}

{{< tabs "2077" >}}

{{% tab "python" %}}
```python
class Solution:
    def numberOfPaths(self, n: int, corridors: List[List[int]]) -> int:
        g = defaultdict(set)
        for a, b in corridors:
            g[a].add(b)
            g[b].add(a)
        ans = 0
        for i in range(1, n + 1):
            for j, k in combinations(g[i], 2):
                if j in g[k]:
                    ans += 1
        return ans // 3
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numberOfPaths(int n, int[][] corridors) {
        Set<Integer>[] g = new Set[n + 1];
        for (int i = 0; i <= n; ++i) {
            g[i] = new HashSet<>();
        }
        for (var c : corridors) {
            int a = c[0], b = c[1];
            g[a].add(b);
            g[b].add(a);
        }
        int ans = 0;
        for (int c = 1; c <= n; ++c) {
            var nxt = new ArrayList<>(g[c]);
            int m = nxt.size();
            for (int i = 0; i < m; ++i) {
                for (int j = i + 1; j < m; ++j) {
                    int a = nxt.get(i), b = nxt.get(j);
                    if (g[b].contains(a)) {
                        ++ans;
                    }
                }
            }
        }
        return ans / 3;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int numberOfPaths(int n, vector<vector<int>>& corridors) {
        vector<unordered_set<int>> g(n + 1);
        for (auto& c : corridors) {
            int a = c[0], b = c[1];
            g[a].insert(b);
            g[b].insert(a);
        }
        int ans = 0;
        for (int c = 1; c <= n; ++c) {
            vector<int> nxt;
            nxt.assign(g[c].begin(), g[c].end());
            int m = nxt.size();
            for (int i = 0; i < m; ++i) {
                for (int j = i + 1; j < m; ++j) {
                    int a = nxt[i], b = nxt[j];
                    ans += g[b].count(a);
                }
            }
        }
        return ans / 3;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numberOfPaths(n int, corridors [][]int) int {
	g := make([]map[int]bool, n+1)
	for i := range g {
		g[i] = make(map[int]bool)
	}
	for _, c := range corridors {
		a, b := c[0], c[1]
		g[a][b] = true
		g[b][a] = true
	}
	ans := 0
	for c := 1; c <= n; c++ {
		nxt := []int{}
		for v := range g[c] {
			nxt = append(nxt, v)
		}
		m := len(nxt)
		for i := 0; i < m; i++ {
			for j := i + 1; j < m; j++ {
				a, b := nxt[i], nxt[j]
				if g[b][a] {
					ans++
				}
			}
		}
	}
	return ans / 3
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>迷宫由 <code>n</code> 个从 <code>1</code> 到 <code>n</code> 的房间组成，有些房间由走廊连接。给定一个二维整数数组 <code>corridors</code>，其中 <code>corridors[i] = [room1<sub>i</sub>, room2<sub>i</sub>]</code>&nbsp;表示有一条走廊连接 <code>room1<sub>i</sub></code> 和<code>room2<sub>i</sub></code>，允许迷宫中的一个人从 <code>room1<sub>i</sub></code> 到 <code>room2<sub>i</sub></code> ，<strong>反之亦然</strong>。</p>

<p>迷宫的设计者想知道迷宫有多让人困惑。迷宫的&nbsp;<strong>混乱分数&nbsp;</strong>是&nbsp;<strong>长度为 3</strong> 的不同的环的数量。</p>

<ul>
	<li>例如, <code>1 → 2 → 3 → 1</code>&nbsp;是长度为 3 的环, 但&nbsp;<code>1 → 2 → 3 → 4</code> 和&nbsp;<code>1 → 2 → 3 → 2 → 1</code> 不是。</li>
</ul>

<p>如果在第一个环中访问的一个或多个房间&nbsp;<strong>不在&nbsp;</strong>第二个环中，则认为两个环是&nbsp;<strong>不同&nbsp;</strong>的。</p>

<p data-group="1-1">返回<em>迷宫的混乱分数</em>。</p>

<p><strong class="example">示例 1:</strong></p>
<img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2077.Paths%20in%20Maze%20That%20Lead%20to%20Same%20Room/images/image-20211114164827-1.png" style="width: 440px; height: 350px;" />
<pre>
<strong>输入:</strong> n = 5, corridors = [[1,2],[5,2],[4,1],[2,4],[3,1],[3,4]]
<strong>输出:</strong> 2
<strong>解释:</strong>
一个长度为 3 的环为 4→1→3→4，用红色表示。
注意，这是与 3→4→1→3 或 1→3→4→1 相同的环，因为房间是相同的。
另一个长度为 3 的环为 1→2→4→1，用蓝色表示。
因此，有两个长度为 3 的不同的环。
</pre>

<p><strong class="example">示例&nbsp;2:</strong></p>
<img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2077.Paths%20in%20Maze%20That%20Lead%20to%20Same%20Room/images/image-20211114164851-2.png" style="width: 329px; height: 250px;" />
<pre>
<strong>输入:</strong> n = 4, corridors = [[1,2],[3,4]]
<strong>输出:</strong> 0
<strong>解释:</strong>
没有长度为 3 的环。</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 1000</code></li>
	<li><code>1 &lt;= corridors.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>corridors[i].length == 2</code></li>
	<li><code>1 &lt;= room1<sub>i</sub>, room2<sub>i</sub> &lt;= n</code></li>
	<li><code>room1<sub>i</sub> != room2<sub>i</sub></code></li>
	<li>
	<p data-group="1-1">没有重复的走廊。</p>
	</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

长度为 `3` 的环，由三个顶点、三条边组成。我们假设三个顶点分别为 `a`, `b`, `c`。

那么一定存在 `c <=> a`，`c <=> b` 以及 `a <=> b`，即环中的每个点都与其他两点直接相连。我们可以用哈希表来存放每个点的相邻点。

由于环的长度为 `3`，每个相同的环会被重复统计 `3` 次，因此答案需除以 `3`。

时间复杂度 $O(n^2)$，空间复杂度 $O(n)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numberOfPaths(self, n: int, corridors: List[List[int]]) -> int:
        g = defaultdict(set)
        for a, b in corridors:
            g[a].add(b)
            g[b].add(a)
        ans = 0
        for i in range(1, n + 1):
            for j, k in combinations(g[i], 2):
                if j in g[k]:
                    ans += 1
        return ans // 3
```

#### Java

```java
class Solution {
    public int numberOfPaths(int n, int[][] corridors) {
        Set<Integer>[] g = new Set[n + 1];
        for (int i = 0; i <= n; ++i) {
            g[i] = new HashSet<>();
        }
        for (var c : corridors) {
            int a = c[0], b = c[1];
            g[a].add(b);
            g[b].add(a);
        }
        int ans = 0;
        for (int c = 1; c <= n; ++c) {
            var nxt = new ArrayList<>(g[c]);
            int m = nxt.size();
            for (int i = 0; i < m; ++i) {
                for (int j = i + 1; j < m; ++j) {
                    int a = nxt.get(i), b = nxt.get(j);
                    if (g[b].contains(a)) {
                        ++ans;
                    }
                }
            }
        }
        return ans / 3;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numberOfPaths(int n, vector<vector<int>>& corridors) {
        vector<unordered_set<int>> g(n + 1);
        for (auto& c : corridors) {
            int a = c[0], b = c[1];
            g[a].insert(b);
            g[b].insert(a);
        }
        int ans = 0;
        for (int c = 1; c <= n; ++c) {
            vector<int> nxt;
            nxt.assign(g[c].begin(), g[c].end());
            int m = nxt.size();
            for (int i = 0; i < m; ++i) {
                for (int j = i + 1; j < m; ++j) {
                    int a = nxt[i], b = nxt[j];
                    ans += g[b].count(a);
                }
            }
        }
        return ans / 3;
    }
};
```

#### Go

```go
func numberOfPaths(n int, corridors [][]int) int {
	g := make([]map[int]bool, n+1)
	for i := range g {
		g[i] = make(map[int]bool)
	}
	for _, c := range corridors {
		a, b := c[0], c[1]
		g[a][b] = true
		g[b][a] = true
	}
	ans := 0
	for c := 1; c <= n; c++ {
		nxt := []int{}
		for v := range g[c] {
			nxt = append(nxt, v)
		}
		m := len(nxt)
		for i := 0; i < m; i++ {
			for j := i + 1; j < m; j++ {
				a, b := nxt[i], nxt[j]
				if g[b][a] {
					ans++
				}
			}
		}
	}
	return ans / 3
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2078. 两栋颜色不同且距离最远的房子](https://leetcode.cn/problems/two-furthest-houses-with-different-colors){#2078}

{{< tabs "2078" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxDistance(self, colors: List[int]) -> int:
        n = len(colors)
        if colors[0] != colors[-1]:
            return n - 1
        i, j = 1, n - 2
        while colors[i] == colors[0]:
            i += 1
        while colors[j] == colors[0]:
            j -= 1
        return max(n - i - 1, j)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxDistance(int[] colors) {
        int n = colors.length;
        if (colors[0] != colors[n - 1]) {
            return n - 1;
        }
        int i = 0, j = n - 1;
        while (colors[++i] == colors[0])
            ;
        while (colors[--j] == colors[0])
            ;
        return Math.max(n - i - 1, j);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        if (colors[0] != colors[n - 1]) return n - 1;
        int i = 0, j = n;
        while (colors[++i] == colors[0])
            ;
        while (colors[--j] == colors[0])
            ;
        return max(n - i - 1, j);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxDistance(colors []int) int {
	n := len(colors)
	if colors[0] != colors[n-1] {
		return n - 1
	}
	i, j := 1, n-2
	for colors[i] == colors[0] {
		i++
	}
	for colors[j] == colors[0] {
		j--
	}
	return max(n-i-1, j)
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>街上有 <code>n</code> 栋房子整齐地排成一列，每栋房子都粉刷上了漂亮的颜色。给你一个下标从 <strong>0</strong> 开始且长度为 <code>n</code> 的整数数组 <code>colors</code> ，其中 <code>colors[i]</code> 表示第&nbsp; <code>i</code> 栋房子的颜色。</p>

<p>返回 <strong>两栋</strong> 颜色 <strong>不同</strong> 房子之间的 <strong>最大</strong> 距离。</p>

<p>第 <code>i</code> 栋房子和第 <code>j</code> 栋房子之间的距离是 <code>abs(i - j)</code> ，其中 <code>abs(x)</code> 是 <code>x</code> 的绝对值。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2078.Two%20Furthest%20Houses%20With%20Different%20Colors/images/eg1.png" style="width: 610px; height: 84px;" /></p>

<pre>
<strong>输入：</strong>colors = [<strong><em>1</em></strong>,1,1,<em><strong>6</strong></em>,1,1,1]
<strong>输出：</strong>3
<strong>解释：</strong>上图中，颜色 1 标识成蓝色，颜色 6 标识成红色。
两栋颜色不同且距离最远的房子是房子 0 和房子 3 。
房子 0 的颜色是颜色 1 ，房子 3 的颜色是颜色 6 。两栋房子之间的距离是 abs(0 - 3) = 3 。
注意，房子 3 和房子 6 也可以产生最佳答案。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2078.Two%20Furthest%20Houses%20With%20Different%20Colors/images/eg2.png" style="width: 426px; height: 84px;" /></p>

<pre>
<strong>输入：</strong>colors = [<em><strong>1</strong></em>,8,3,8,<em><strong>3</strong></em>]
<strong>输出：</strong>4
<strong>解释：</strong>上图中，颜色 1 标识成蓝色，颜色 8 标识成黄色，颜色 3 标识成绿色。
两栋颜色不同且距离最远的房子是房子 0 和房子 4 。
房子 0 的颜色是颜色 1 ，房子 4 的颜色是颜色 3 。两栋房子之间的距离是 abs(0 - 4) = 4 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>colors = [<em><strong>0</strong></em>,<em><strong>1</strong></em>]
<strong>输出：</strong>1
<strong>解释：</strong>两栋颜色不同且距离最远的房子是房子 0 和房子 1 。
房子 0 的颜色是颜色 0 ，房子 1 的颜色是颜色 1 。两栋房子之间的距离是 abs(0 - 1) = 1 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n ==&nbsp;colors.length</code></li>
	<li><code>2 &lt;= n &lt;= 100</code></li>
	<li><code>0 &lt;= colors[i] &lt;= 100</code></li>
	<li>生成的测试数据满足 <strong>至少 </strong>存在 2 栋颜色不同的房子</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：暴力枚举

时间复杂度 $O(n^2)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxDistance(self, colors: List[int]) -> int:
        ans, n = 0, len(colors)
        for i in range(n):
            for j in range(i + 1, n):
                if colors[i] != colors[j]:
                    ans = max(ans, abs(i - j))
        return ans
```

#### Java

```java
class Solution {
    public int maxDistance(int[] colors) {
        int ans = 0, n = colors.length;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (colors[i] != colors[j]) {
                    ans = Math.max(ans, Math.abs(i - j));
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
    int maxDistance(vector<int>& colors) {
        int ans = 0, n = colors.size();
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                if (colors[i] != colors[j])
                    ans = max(ans, abs(i - j));
        return ans;
    }
};
```

#### Go

```go
func maxDistance(colors []int) int {
	ans, n := 0, len(colors)
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			if colors[i] != colors[j] {
				ans = max(ans, abs(i-j))
			}
		}
	}
	return ans
}

func abs(x int) int {
	if x >= 0 {
		return x
	}
	return -x
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：贪心

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxDistance(self, colors: List[int]) -> int:
        n = len(colors)
        if colors[0] != colors[-1]:
            return n - 1
        i, j = 1, n - 2
        while colors[i] == colors[0]:
            i += 1
        while colors[j] == colors[0]:
            j -= 1
        return max(n - i - 1, j)
```

#### Java

```java
class Solution {
    public int maxDistance(int[] colors) {
        int n = colors.length;
        if (colors[0] != colors[n - 1]) {
            return n - 1;
        }
        int i = 0, j = n - 1;
        while (colors[++i] == colors[0])
            ;
        while (colors[--j] == colors[0])
            ;
        return Math.max(n - i - 1, j);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        if (colors[0] != colors[n - 1]) return n - 1;
        int i = 0, j = n;
        while (colors[++i] == colors[0])
            ;
        while (colors[--j] == colors[0])
            ;
        return max(n - i - 1, j);
    }
};
```

#### Go

```go
func maxDistance(colors []int) int {
	n := len(colors)
	if colors[0] != colors[n-1] {
		return n - 1
	}
	i, j := 1, n-2
	for colors[i] == colors[0] {
		i++
	}
	for colors[j] == colors[0] {
		j--
	}
	return max(n-i-1, j)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2079. 给植物浇水](https://leetcode.cn/problems/watering-plants){#2079}

{{< tabs "2079" >}}

{{% tab "python" %}}
```python
class Solution:
    def wateringPlants(self, plants: List[int], capacity: int) -> int:
        ans, water = 0, capacity
        for i, p in enumerate(plants):
            if water >= p:
                water -= p
                ans += 1
            else:
                water = capacity - p
                ans += i * 2 + 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int wateringPlants(int[] plants, int capacity) {
        int ans = 0, water = capacity;
        for (int i = 0; i < plants.length; ++i) {
            if (water >= plants[i]) {
                water -= plants[i];
                ans += 1;
            } else {
                water = capacity - plants[i];
                ans += i * 2 + 1;
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
    int wateringPlants(vector<int>& plants, int capacity) {
        int ans = 0, water = capacity;
        for (int i = 0; i < plants.size(); ++i) {
            if (water >= plants[i]) {
                water -= plants[i];
                ans += 1;
            } else {
                water = capacity - plants[i];
                ans += i * 2 + 1;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func wateringPlants(plants []int, capacity int) (ans int) {
	water := capacity
	for i, p := range plants {
		if water >= p {
			water -= p
			ans++
		} else {
			water = capacity - p
			ans += i*2 + 1
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function wateringPlants(plants: number[], capacity: number): number {
    let [ans, water] = [0, capacity];
    for (let i = 0; i < plants.length; ++i) {
        if (water >= plants[i]) {
            water -= plants[i];
            ++ans;
        } else {
            water = capacity - plants[i];
            ans += i * 2 + 1;
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn watering_plants(plants: Vec<i32>, capacity: i32) -> i32 {
        let mut ans = 0;
        let mut water = capacity;
        for (i, &p) in plants.iter().enumerate() {
            if water >= p {
                water -= p;
                ans += 1;
            } else {
                water = capacity - p;
                ans += (i as i32) * 2 + 1;
            }
        }
        ans
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
int wateringPlants(int* plants, int plantsSize, int capacity) {
    int ans = 0, water = capacity;
    for (int i = 0; i < plantsSize; ++i) {
        if (water >= plants[i]) {
            water -= plants[i];
            ans += 1;
        } else {
            water = capacity - plants[i];
            ans += i * 2 + 1;
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

<p>你打算用一个水罐给花园里的 <code>n</code> 株植物浇水。植物排成一行，从左到右进行标记，编号从 <code>0</code> 到 <code>n - 1</code> 。其中，第 <code>i</code> 株植物的位置是 <code>x = i</code> 。<code>x = -1</code>&nbsp;处有一条河，你可以在那里重新灌满你的水罐。</p>

<p>每一株植物都需要浇特定量的水。你将会按下面描述的方式完成浇水：</p>

<ul>
	<li>按从左到右的顺序给植物浇水。</li>
	<li>在给当前植物浇完水之后，如果你没有足够的水 <strong>完全</strong> 浇灌下一株植物，那么你就需要返回河边重新装满水罐。</li>
	<li>你 <strong>不能</strong> 提前重新灌满水罐。</li>
</ul>

<p>最初，你在河边（也就是，<code>x = -1</code>），在 x 轴上每移动 <strong>一个单位</strong>&nbsp;都需要 <strong>一步</strong> 。</p>

<p>给你一个下标从 <strong>0</strong> 开始的整数数组 <code>plants</code> ，数组由 <code>n</code> 个整数组成。其中，<code>plants[i]</code> 为第 <code>i</code> 株植物需要的水量。另有一个整数 <code>capacity</code> 表示水罐的容量，返回浇灌所有植物需要的 <strong>步数</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>plants = [2,2,3,3], capacity = 5
<strong>输出：</strong>14
<strong>解释：</strong>从河边开始，此时水罐是装满的：
- 走到植物 0 (1 步) ，浇水。水罐中还有 3 单位的水。
- 走到植物 1 (1 步) ，浇水。水罐中还有 1 单位的水。
- 由于不能完全浇灌植物 2 ，回到河边取水 (2 步)。
- 走到植物 2 (3 步) ，浇水。水罐中还有 2 单位的水。
- 由于不能完全浇灌植物 3 ，回到河边取水 (3 步)。
- 走到植物 3 (4 步) ，浇水。
需要的步数是 = 1 + 1 + 2 + 3 + 3 + 4 = 14 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>plants = [1,1,1,4,2,3], capacity = 4
<strong>输出：</strong>30
<strong>解释：</strong>从河边开始，此时水罐是装满的：
- 走到植物 0，1，2 (3 步) ，浇水。回到河边取水 (3 步)。
- 走到植物 3 (4 步) ，浇水。回到河边取水 (4 步)。
- 走到植物 4 (5 步) ，浇水。回到河边取水 (5 步)。
- 走到植物 5 (6 步) ，浇水。
需要的步数是 = 3 + 3 + 4 + 4 + 5 + 5 + 6 = 30 。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>plants = [7,7,7,7,7,7,7], capacity = 8
<strong>输出：</strong>49
<strong>解释：</strong>每次浇水都需要重新灌满水罐。
需要的步数是 = 1 + 1 + 2 + 2 + 3 + 3 + 4 + 4 + 5 + 5 + 6 + 6 + 7 = 49 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == plants.length</code></li>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
	<li><code>1 &lt;= plants[i] &lt;= 10<sup>6</sup></code></li>
	<li><code>max(plants[i]) &lt;= capacity &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们可以模拟给植物浇水的过程，用一个变量 $\textit{water}$ 表示当前水罐中的水量，初始时 $\textit{water} = \textit{capacity}$。

我们遍历植物，对于每一株植物：

-   如果当前水罐中的水量足够浇灌这株植物，我们就向前移动一步，浇灌这株植物，同时更新 $\textit{water} = \textit{water} - \textit{plants}[i]$。
-   否则我们就需要返回河边重新装满水罐，再次走到当前位置，然后向前移动一步，此时我们需要的步数为 $i \times 2 + 1$，然后我们浇灌这株植物，更新 $\textit{water} = \textit{capacity} - \textit{plants}[i]$。

最后返回总的步数即可。

时间复杂度 $O(n)$，其中 $n$ 为植物的数量。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def wateringPlants(self, plants: List[int], capacity: int) -> int:
        ans, water = 0, capacity
        for i, p in enumerate(plants):
            if water >= p:
                water -= p
                ans += 1
            else:
                water = capacity - p
                ans += i * 2 + 1
        return ans
```

#### Java

```java
class Solution {
    public int wateringPlants(int[] plants, int capacity) {
        int ans = 0, water = capacity;
        for (int i = 0; i < plants.length; ++i) {
            if (water >= plants[i]) {
                water -= plants[i];
                ans += 1;
            } else {
                water = capacity - plants[i];
                ans += i * 2 + 1;
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
    int wateringPlants(vector<int>& plants, int capacity) {
        int ans = 0, water = capacity;
        for (int i = 0; i < plants.size(); ++i) {
            if (water >= plants[i]) {
                water -= plants[i];
                ans += 1;
            } else {
                water = capacity - plants[i];
                ans += i * 2 + 1;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func wateringPlants(plants []int, capacity int) (ans int) {
	water := capacity
	for i, p := range plants {
		if water >= p {
			water -= p
			ans++
		} else {
			water = capacity - p
			ans += i*2 + 1
		}
	}
	return
}
```

#### TypeScript

```ts
function wateringPlants(plants: number[], capacity: number): number {
    let [ans, water] = [0, capacity];
    for (let i = 0; i < plants.length; ++i) {
        if (water >= plants[i]) {
            water -= plants[i];
            ++ans;
        } else {
            water = capacity - plants[i];
            ans += i * 2 + 1;
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn watering_plants(plants: Vec<i32>, capacity: i32) -> i32 {
        let mut ans = 0;
        let mut water = capacity;
        for (i, &p) in plants.iter().enumerate() {
            if water >= p {
                water -= p;
                ans += 1;
            } else {
                water = capacity - p;
                ans += (i as i32) * 2 + 1;
            }
        }
        ans
    }
}
```

#### C

```c
int wateringPlants(int* plants, int plantsSize, int capacity) {
    int ans = 0, water = capacity;
    for (int i = 0; i < plantsSize; ++i) {
        if (water >= plants[i]) {
            water -= plants[i];
            ans += 1;
        } else {
            water = capacity - plants[i];
            ans += i * 2 + 1;
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
