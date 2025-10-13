---
title: "2940_找到 Alice 和 Bob 可以相遇的建筑"
date: 2025-10-08T18:39:48+08:00
weight: 5
tags: [二分查找, 前缀和, 动态规划, 单调栈, 单调队列, 哈希表, 堆（优先队列）, 字符串, 并查集, 排序, 数学, 数组, 数论, 枚举, 栈, 树状数组, 模拟, 矩阵, 线段树, 队列]
---

{{< markmap >}}
### [2940_找到 Alice 和 Bob 可以相遇的建筑](#2940)
#### [栈](#2940)
#### [树状数组](#2940)
#### [线段树](#2940)
#### [数组](#2940)
#### [二分查找](#2940)
#### [单调栈](#2940)
#### [堆（优先队列）](#2940)
### [2941_子数组的最大 GCD-Sum 🔒](#2941)
#### [数组](#2941)
#### [数学](#2941)
#### [二分查找](#2941)
#### [数论](#2941)
### [2942_查找包含给定字符的单词](#2942)
#### [数组](#2942)
#### [字符串](#2942)
### [2943_最大化网格图中正方形空洞的面积](#2943)
#### [数组](#2943)
#### [排序](#2943)
### [2944_购买水果需要的最少金币数](#2944)
#### [队列](#2944)
#### [数组](#2944)
#### [动态规划](#2944)
#### [单调队列](#2944)
#### [堆（优先队列）](#2944)
### [2945_找到最大非递减数组的长度](#2945)
#### [栈](#2945)
#### [队列](#2945)
#### [数组](#2945)
#### [二分查找](#2945)
#### [动态规划](#2945)
#### [单调队列](#2945)
#### [单调栈](#2945)
### [2946_循环移位后的矩阵相似检查](#2946)
#### [数组](#2946)
#### [数学](#2946)
#### [矩阵](#2946)
#### [模拟](#2946)
### [2947_统计美丽子字符串 I](#2947)
#### [哈希表](#2947)
#### [数学](#2947)
#### [字符串](#2947)
#### [枚举](#2947)
#### [数论](#2947)
#### [前缀和](#2947)
### [2948_交换得到字典序最小的数组](#2948)
#### [并查集](#2948)
#### [数组](#2948)
#### [排序](#2948)
### [2949_统计美丽子字符串 II](#2949)
#### [哈希表](#2949)
#### [数学](#2949)
#### [字符串](#2949)
#### [数论](#2949)
#### [前缀和](#2949)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2940_找到 Alice 和 Bob 可以相遇的建筑
___
#### 栈
___
#### 树状数组
___
#### 线段树
___
#### 数组
___
#### 二分查找
___
#### 单调栈
___
#### 堆（优先队列）
---
### 2941_子数组的最大 GCD-Sum 🔒
___
#### 数组
___
#### 数学
___
#### 二分查找
___
#### 数论
---
### 2942_查找包含给定字符的单词
___
#### 数组
___
#### 字符串
---
### 2943_最大化网格图中正方形空洞的面积
___
#### 数组
___
#### 排序
---
### 2944_购买水果需要的最少金币数
___
#### 队列
___
#### 数组
___
#### 动态规划
___
#### 单调队列
___
#### 堆（优先队列）
---
### 2945_找到最大非递减数组的长度
___
#### 栈
___
#### 队列
___
#### 数组
___
#### 二分查找
___
#### 动态规划
___
#### 单调队列
___
#### 单调栈
---
### 2946_循环移位后的矩阵相似检查
___
#### 数组
___
#### 数学
___
#### 矩阵
___
#### 模拟
---
### 2947_统计美丽子字符串 I
___
#### 哈希表
___
#### 数学
___
#### 字符串
___
#### 枚举
___
#### 数论
___
#### 前缀和
---
### 2948_交换得到字典序最小的数组
___
#### 并查集
___
#### 数组
___
#### 排序
---
### 2949_统计美丽子字符串 II
___
#### 哈希表
___
#### 数学
___
#### 字符串
___
#### 数论
___
#### 前缀和
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 前缀和 | 动态规划 |
| 单调栈 | 单调队列 | 哈希表 |
| 堆（优先队列） | 字符串 | 并查集 |
| 排序 | 数学 | 数组 |
| 数论 | 枚举 | 栈 |
| 树状数组 | 模拟 | 矩阵 |
| 线段树 | 队列 |  |

# [2940. 找到 Alice 和 Bob 可以相遇的建筑](https://leetcode.cn/problems/find-building-where-alice-and-bob-can-meet){#2940}

{{< tabs "2940" >}}

{{% tab "python" %}}
```python
class BinaryIndexedTree:
    __slots__ = ["n", "c"]

    def __init__(self, n: int):
        self.n = n
        self.c = [inf] * (n + 1)

    def update(self, x: int, v: int):
        while x <= self.n:
            self.c[x] = min(self.c[x], v)
            x += x & -x

    def query(self, x: int) -> int:
        mi = inf
        while x:
            mi = min(mi, self.c[x])
            x -= x & -x
        return -1 if mi == inf else mi


class Solution:
    def leftmostBuildingQueries(
        self, heights: List[int], queries: List[List[int]]
    ) -> List[int]:
        n, m = len(heights), len(queries)
        for i in range(m):
            queries[i] = [min(queries[i]), max(queries[i])]
        j = n - 1
        s = sorted(set(heights))
        ans = [-1] * m
        tree = BinaryIndexedTree(n)
        for i in sorted(range(m), key=lambda i: -queries[i][1]):
            l, r = queries[i]
            while j > r:
                k = n - bisect_left(s, heights[j]) + 1
                tree.update(k, j)
                j -= 1
            if l == r or heights[l] < heights[r]:
                ans[i] = r
            else:
                k = n - bisect_left(s, heights[l])
                ans[i] = tree.query(k)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class BinaryIndexedTree {
    private final int inf = 1 << 30;
    private int n;
    private int[] c;

    public BinaryIndexedTree(int n) {
        this.n = n;
        c = new int[n + 1];
        Arrays.fill(c, inf);
    }

    public void update(int x, int v) {
        while (x <= n) {
            c[x] = Math.min(c[x], v);
            x += x & -x;
        }
    }

    public int query(int x) {
        int mi = inf;
        while (x > 0) {
            mi = Math.min(mi, c[x]);
            x -= x & -x;
        }
        return mi == inf ? -1 : mi;
    }
}

class Solution {
    public int[] leftmostBuildingQueries(int[] heights, int[][] queries) {
        int n = heights.length;
        int m = queries.length;
        for (int i = 0; i < m; ++i) {
            if (queries[i][0] > queries[i][1]) {
                queries[i] = new int[] {queries[i][1], queries[i][0]};
            }
        }
        Integer[] idx = new Integer[m];
        for (int i = 0; i < m; ++i) {
            idx[i] = i;
        }
        Arrays.sort(idx, (i, j) -> queries[j][1] - queries[i][1]);
        int[] s = heights.clone();
        Arrays.sort(s);
        int[] ans = new int[m];
        int j = n - 1;
        BinaryIndexedTree tree = new BinaryIndexedTree(n);
        for (int i : idx) {
            int l = queries[i][0], r = queries[i][1];
            while (j > r) {
                int k = n - Arrays.binarySearch(s, heights[j]) + 1;
                tree.update(k, j);
                --j;
            }
            if (l == r || heights[l] < heights[r]) {
                ans[i] = r;
            } else {
                int k = n - Arrays.binarySearch(s, heights[l]);
                ans[i] = tree.query(k);
            }
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class BinaryIndexedTree {
private:
    int inf = 1 << 30;
    int n;
    vector<int> c;

public:
    BinaryIndexedTree(int n) {
        this->n = n;
        c.resize(n + 1, inf);
    }

    void update(int x, int v) {
        while (x <= n) {
            c[x] = min(c[x], v);
            x += x & -x;
        }
    }

    int query(int x) {
        int mi = inf;
        while (x > 0) {
            mi = min(mi, c[x]);
            x -= x & -x;
        }
        return mi == inf ? -1 : mi;
    }
};

class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size(), m = queries.size();
        for (auto& q : queries) {
            if (q[0] > q[1]) {
                swap(q[0], q[1]);
            }
        }
        vector<int> idx(m);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int i, int j) {
            return queries[j][1] < queries[i][1];
        });
        vector<int> s = heights;
        sort(s.begin(), s.end());
        s.erase(unique(s.begin(), s.end()), s.end());
        vector<int> ans(m);
        int j = n - 1;
        BinaryIndexedTree tree(n);
        for (int i : idx) {
            int l = queries[i][0], r = queries[i][1];
            while (j > r) {
                int k = s.end() - lower_bound(s.begin(), s.end(), heights[j]) + 1;
                tree.update(k, j);
                --j;
            }
            if (l == r || heights[l] < heights[r]) {
                ans[i] = r;
            } else {
                int k = s.end() - lower_bound(s.begin(), s.end(), heights[l]);
                ans[i] = tree.query(k);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
const inf int = 1 << 30

type BinaryIndexedTree struct {
	n int
	c []int
}

func NewBinaryIndexedTree(n int) BinaryIndexedTree {
	c := make([]int, n+1)
	for i := range c {
		c[i] = inf
	}
	return BinaryIndexedTree{n: n, c: c}
}

func (bit *BinaryIndexedTree) update(x, v int) {
	for x <= bit.n {
		bit.c[x] = min(bit.c[x], v)
		x += x & -x
	}
}

func (bit *BinaryIndexedTree) query(x int) int {
	mi := inf
	for x > 0 {
		mi = min(mi, bit.c[x])
		x -= x & -x
	}
	if mi == inf {
		return -1
	}
	return mi
}

func leftmostBuildingQueries(heights []int, queries [][]int) []int {
	n, m := len(heights), len(queries)
	for _, q := range queries {
		if q[0] > q[1] {
			q[0], q[1] = q[1], q[0]
		}
	}
	idx := make([]int, m)
	for i := range idx {
		idx[i] = i
	}
	sort.Slice(idx, func(i, j int) bool { return queries[idx[j]][1] < queries[idx[i]][1] })
	s := make([]int, n)
	copy(s, heights)
	sort.Ints(s)
	ans := make([]int, m)
	tree := NewBinaryIndexedTree(n)
	j := n - 1
	for _, i := range idx {
		l, r := queries[i][0], queries[i][1]
		for ; j > r; j-- {
			k := n - sort.SearchInts(s, heights[j]) + 1
			tree.update(k, j)
		}
		if l == r || heights[l] < heights[r] {
			ans[i] = r
		} else {
			k := n - sort.SearchInts(s, heights[l])
			ans[i] = tree.query(k)
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class BinaryIndexedTree {
    private n: number;
    private c: number[];
    private inf: number = 1 << 30;

    constructor(n: number) {
        this.n = n;
        this.c = Array(n + 1).fill(this.inf);
    }

    update(x: number, v: number): void {
        while (x <= this.n) {
            this.c[x] = Math.min(this.c[x], v);
            x += x & -x;
        }
    }

    query(x: number): number {
        let mi = this.inf;
        while (x > 0) {
            mi = Math.min(mi, this.c[x]);
            x -= x & -x;
        }
        return mi === this.inf ? -1 : mi;
    }
}

function leftmostBuildingQueries(heights: number[], queries: number[][]): number[] {
    const n = heights.length;
    const m = queries.length;
    for (const q of queries) {
        if (q[0] > q[1]) {
            [q[0], q[1]] = [q[1], q[0]];
        }
    }
    const idx: number[] = Array(m)
        .fill(0)
        .map((_, i) => i);
    idx.sort((i, j) => queries[j][1] - queries[i][1]);
    const tree = new BinaryIndexedTree(n);
    const ans: number[] = Array(m).fill(-1);
    const s = [...heights];
    s.sort((a, b) => a - b);
    const search = (x: number) => {
        let [l, r] = [0, n];
        while (l < r) {
            const mid = (l + r) >> 1;
            if (s[mid] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    };
    let j = n - 1;
    for (const i of idx) {
        const [l, r] = queries[i];
        while (j > r) {
            const k = n - search(heights[j]) + 1;
            tree.update(k, j);
            --j;
        }
        if (l === r || heights[l] < heights[r]) {
            ans[i] = r;
        } else {
            const k = n - search(heights[l]);
            ans[i] = tree.query(k);
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

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的正整数数组&nbsp;<code>heights</code>&nbsp;，其中&nbsp;<code>heights[i]</code>&nbsp;表示第 <code>i</code>&nbsp;栋建筑的高度。</p>

<p>如果一个人在建筑&nbsp;<code>i</code>&nbsp;，且存在&nbsp;<code>i &lt; j</code>&nbsp;的建筑&nbsp;<code>j</code>&nbsp;满足&nbsp;<code>heights[i] &lt; heights[j]</code>&nbsp;，那么这个人可以移动到建筑&nbsp;<code>j</code>&nbsp;。</p>

<p>给你另外一个数组&nbsp;<code>queries</code>&nbsp;，其中&nbsp;<code>queries[i] = [a<sub>i</sub>, b<sub>i</sub>]</code>&nbsp;。第&nbsp;<code>i</code>&nbsp;个查询中，Alice 在建筑&nbsp;<code>a<sub>i</sub></code> ，Bob 在建筑&nbsp;<code>b<sub>i</sub></code><sub>&nbsp;</sub>。</p>

<p>请你能返回一个数组&nbsp;<code>ans</code>&nbsp;，其中&nbsp;<code>ans[i]</code>&nbsp;是第&nbsp;<code>i</code>&nbsp;个查询中，Alice 和 Bob 可以相遇的&nbsp;<strong>最左边的建筑</strong>&nbsp;。如果对于查询&nbsp;<code>i</code>&nbsp;，Alice<em> </em>和<em> </em>Bob 不能相遇，令&nbsp;<code>ans[i]</code> 为&nbsp;<code>-1</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>heights = [6,4,8,5,2,7], queries = [[0,1],[0,3],[2,4],[3,4],[2,2]]
<b>输出：</b>[2,5,-1,5,2]
<b>解释：</b>第一个查询中，Alice 和 Bob 可以移动到建筑 2 ，因为 heights[0] &lt; heights[2] 且 heights[1] &lt; heights[2] 。
第二个查询中，Alice 和 Bob 可以移动到建筑 5 ，因为 heights[0] &lt; heights[5] 且 heights[3] &lt; heights[5] 。
第三个查询中，Alice 无法与 Bob 相遇，因为 Alice 不能移动到任何其他建筑。
第四个查询中，Alice 和 Bob 可以移动到建筑 5 ，因为 heights[3] &lt; heights[5] 且 heights[4] &lt; heights[5] 。
第五个查询中，Alice 和 Bob 已经在同一栋建筑中。
对于 ans[i] != -1 ，ans[i] 是 Alice 和 Bob 可以相遇的建筑中最左边建筑的下标。
对于 ans[i] == -1 ，不存在 Alice 和 Bob 可以相遇的建筑。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>heights = [5,3,8,2,6,1,4,6], queries = [[0,7],[3,5],[5,2],[3,0],[1,6]]
<b>输出：</b>[7,6,-1,4,6]
<strong>解释：</strong>第一个查询中，Alice 可以直接移动到 Bob 的建筑，因为 heights[0] &lt; heights[7] 。
第二个查询中，Alice 和 Bob 可以移动到建筑 6 ，因为 heights[3] &lt; heights[6] 且 heights[5] &lt; heights[6] 。
第三个查询中，Alice 无法与 Bob 相遇，因为 Bob 不能移动到任何其他建筑。
第四个查询中，Alice 和 Bob 可以移动到建筑 4 ，因为 heights[3] &lt; heights[4] 且 heights[0] &lt; heights[4] 。
第五个查询中，Alice 可以直接移动到 Bob 的建筑，因为 heights[1] &lt; heights[6] 。
对于 ans[i] != -1 ，ans[i] 是 Alice 和 Bob 可以相遇的建筑中最左边建筑的下标。
对于 ans[i] == -1 ，不存在 Alice 和 Bob 可以相遇的建筑。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= heights.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= heights[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= queries.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>queries[i] = [a<sub>i</sub>, b<sub>i</sub>]</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt;= heights.length - 1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：树状数组

我们不妨记 $queries[i] = [l_i, r_i]$，其中 $l_i \le r_i$。如果 $l_i = r_i$ 或者 $heights[l_i] \lt heights[r_i]$，那么答案就是 $r_i$。否则，我们需要在所有满足 $j \gt r_i$，且 $heights[j] \gt heights[l_i]$ 的 $j$ 中找到最小的 $j$。

我们可以将 $queries$ 按照 $r_i$ 从大到小排序，用一个指针 $j$ 指向当前遍历到的 $heights$ 的下标。

接下来，我们遍历每个查询 $queries[i] = (l, r)$，对于当前查询，如果 $j \gt r$，那么我们循环将 $heights[j]$ 插入树状数组中。树状数组维护的是后缀高度（离散化后的高度）的下标的最小值。然后，我们判断是否满足 $l = r$ 或者 $heights[l] \lt heights[r]$，如果满足，那么当前查询的答案就是 $r$，否则，我们在树状数组中查询 $heights[l]$ 的下标的最小值，即为当前查询的答案。

时间复杂度 $O((n + m) \times \log n + m \times \log m)$，空间复杂度 $O(n + m)$。其中 $n$ 和 $m$ 分别为 $heights$ 和 $queries$ 的长度。

相似题目：

-   [2736. 最大和查询](https://github.com/doocs/leetcode/blob/main/solution/2700-2799/2736.Maximum%20Sum%20Queries/README.md)

<!-- tabs:start -->

#### Python3

```python
class BinaryIndexedTree:
    __slots__ = ["n", "c"]

    def __init__(self, n: int):
        self.n = n
        self.c = [inf] * (n + 1)

    def update(self, x: int, v: int):
        while x <= self.n:
            self.c[x] = min(self.c[x], v)
            x += x & -x

    def query(self, x: int) -> int:
        mi = inf
        while x:
            mi = min(mi, self.c[x])
            x -= x & -x
        return -1 if mi == inf else mi


class Solution:
    def leftmostBuildingQueries(
        self, heights: List[int], queries: List[List[int]]
    ) -> List[int]:
        n, m = len(heights), len(queries)
        for i in range(m):
            queries[i] = [min(queries[i]), max(queries[i])]
        j = n - 1
        s = sorted(set(heights))
        ans = [-1] * m
        tree = BinaryIndexedTree(n)
        for i in sorted(range(m), key=lambda i: -queries[i][1]):
            l, r = queries[i]
            while j > r:
                k = n - bisect_left(s, heights[j]) + 1
                tree.update(k, j)
                j -= 1
            if l == r or heights[l] < heights[r]:
                ans[i] = r
            else:
                k = n - bisect_left(s, heights[l])
                ans[i] = tree.query(k)
        return ans
```

#### Java

```java
class BinaryIndexedTree {
    private final int inf = 1 << 30;
    private int n;
    private int[] c;

    public BinaryIndexedTree(int n) {
        this.n = n;
        c = new int[n + 1];
        Arrays.fill(c, inf);
    }

    public void update(int x, int v) {
        while (x <= n) {
            c[x] = Math.min(c[x], v);
            x += x & -x;
        }
    }

    public int query(int x) {
        int mi = inf;
        while (x > 0) {
            mi = Math.min(mi, c[x]);
            x -= x & -x;
        }
        return mi == inf ? -1 : mi;
    }
}

class Solution {
    public int[] leftmostBuildingQueries(int[] heights, int[][] queries) {
        int n = heights.length;
        int m = queries.length;
        for (int i = 0; i < m; ++i) {
            if (queries[i][0] > queries[i][1]) {
                queries[i] = new int[] {queries[i][1], queries[i][0]};
            }
        }
        Integer[] idx = new Integer[m];
        for (int i = 0; i < m; ++i) {
            idx[i] = i;
        }
        Arrays.sort(idx, (i, j) -> queries[j][1] - queries[i][1]);
        int[] s = heights.clone();
        Arrays.sort(s);
        int[] ans = new int[m];
        int j = n - 1;
        BinaryIndexedTree tree = new BinaryIndexedTree(n);
        for (int i : idx) {
            int l = queries[i][0], r = queries[i][1];
            while (j > r) {
                int k = n - Arrays.binarySearch(s, heights[j]) + 1;
                tree.update(k, j);
                --j;
            }
            if (l == r || heights[l] < heights[r]) {
                ans[i] = r;
            } else {
                int k = n - Arrays.binarySearch(s, heights[l]);
                ans[i] = tree.query(k);
            }
        }
        return ans;
    }
}
```

#### C++

```cpp
class BinaryIndexedTree {
private:
    int inf = 1 << 30;
    int n;
    vector<int> c;

public:
    BinaryIndexedTree(int n) {
        this->n = n;
        c.resize(n + 1, inf);
    }

    void update(int x, int v) {
        while (x <= n) {
            c[x] = min(c[x], v);
            x += x & -x;
        }
    }

    int query(int x) {
        int mi = inf;
        while (x > 0) {
            mi = min(mi, c[x]);
            x -= x & -x;
        }
        return mi == inf ? -1 : mi;
    }
};

class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size(), m = queries.size();
        for (auto& q : queries) {
            if (q[0] > q[1]) {
                swap(q[0], q[1]);
            }
        }
        vector<int> idx(m);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int i, int j) {
            return queries[j][1] < queries[i][1];
        });
        vector<int> s = heights;
        sort(s.begin(), s.end());
        s.erase(unique(s.begin(), s.end()), s.end());
        vector<int> ans(m);
        int j = n - 1;
        BinaryIndexedTree tree(n);
        for (int i : idx) {
            int l = queries[i][0], r = queries[i][1];
            while (j > r) {
                int k = s.end() - lower_bound(s.begin(), s.end(), heights[j]) + 1;
                tree.update(k, j);
                --j;
            }
            if (l == r || heights[l] < heights[r]) {
                ans[i] = r;
            } else {
                int k = s.end() - lower_bound(s.begin(), s.end(), heights[l]);
                ans[i] = tree.query(k);
            }
        }
        return ans;
    }
};
```

#### Go

```go
const inf int = 1 << 30

type BinaryIndexedTree struct {
	n int
	c []int
}

func NewBinaryIndexedTree(n int) BinaryIndexedTree {
	c := make([]int, n+1)
	for i := range c {
		c[i] = inf
	}
	return BinaryIndexedTree{n: n, c: c}
}

func (bit *BinaryIndexedTree) update(x, v int) {
	for x <= bit.n {
		bit.c[x] = min(bit.c[x], v)
		x += x & -x
	}
}

func (bit *BinaryIndexedTree) query(x int) int {
	mi := inf
	for x > 0 {
		mi = min(mi, bit.c[x])
		x -= x & -x
	}
	if mi == inf {
		return -1
	}
	return mi
}

func leftmostBuildingQueries(heights []int, queries [][]int) []int {
	n, m := len(heights), len(queries)
	for _, q := range queries {
		if q[0] > q[1] {
			q[0], q[1] = q[1], q[0]
		}
	}
	idx := make([]int, m)
	for i := range idx {
		idx[i] = i
	}
	sort.Slice(idx, func(i, j int) bool { return queries[idx[j]][1] < queries[idx[i]][1] })
	s := make([]int, n)
	copy(s, heights)
	sort.Ints(s)
	ans := make([]int, m)
	tree := NewBinaryIndexedTree(n)
	j := n - 1
	for _, i := range idx {
		l, r := queries[i][0], queries[i][1]
		for ; j > r; j-- {
			k := n - sort.SearchInts(s, heights[j]) + 1
			tree.update(k, j)
		}
		if l == r || heights[l] < heights[r] {
			ans[i] = r
		} else {
			k := n - sort.SearchInts(s, heights[l])
			ans[i] = tree.query(k)
		}
	}
	return ans
}
```

#### TypeScript

```ts
class BinaryIndexedTree {
    private n: number;
    private c: number[];
    private inf: number = 1 << 30;

    constructor(n: number) {
        this.n = n;
        this.c = Array(n + 1).fill(this.inf);
    }

    update(x: number, v: number): void {
        while (x <= this.n) {
            this.c[x] = Math.min(this.c[x], v);
            x += x & -x;
        }
    }

    query(x: number): number {
        let mi = this.inf;
        while (x > 0) {
            mi = Math.min(mi, this.c[x]);
            x -= x & -x;
        }
        return mi === this.inf ? -1 : mi;
    }
}

function leftmostBuildingQueries(heights: number[], queries: number[][]): number[] {
    const n = heights.length;
    const m = queries.length;
    for (const q of queries) {
        if (q[0] > q[1]) {
            [q[0], q[1]] = [q[1], q[0]];
        }
    }
    const idx: number[] = Array(m)
        .fill(0)
        .map((_, i) => i);
    idx.sort((i, j) => queries[j][1] - queries[i][1]);
    const tree = new BinaryIndexedTree(n);
    const ans: number[] = Array(m).fill(-1);
    const s = [...heights];
    s.sort((a, b) => a - b);
    const search = (x: number) => {
        let [l, r] = [0, n];
        while (l < r) {
            const mid = (l + r) >> 1;
            if (s[mid] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    };
    let j = n - 1;
    for (const i of idx) {
        const [l, r] = queries[i];
        while (j > r) {
            const k = n - search(heights[j]) + 1;
            tree.update(k, j);
            --j;
        }
        if (l === r || heights[l] < heights[r]) {
            ans[i] = r;
        } else {
            const k = n - search(heights[l]);
            ans[i] = tree.query(k);
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

# [2941. 子数组的最大 GCD-Sum 🔒](https://leetcode.cn/problems/maximum-gcd-sum-of-a-subarray){#2941}

{{< tabs "2941" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxGcdSum(self, nums: List[int], k: int) -> int:
        s = list(accumulate(nums, initial=0))
        f = []
        ans = 0
        for i, v in enumerate(nums):
            g = []
            for j, x in f:
                y = gcd(x, v)
                if not g or g[-1][1] != y:
                    g.append((j, y))
            f = g
            f.append((i, v))
            for j, x in f:
                if i - j + 1 >= k:
                    ans = max(ans, (s[i + 1] - s[j]) * x)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long maxGcdSum(int[] nums, int k) {
        int n = nums.length;
        long[] s = new long[n + 1];
        for (int i = 1; i <= n; ++i) {
            s[i] = s[i - 1] + nums[i - 1];
        }
        List<int[]> f = new ArrayList<>();
        long ans = 0;
        for (int i = 0; i < n; ++i) {
            List<int[]> g = new ArrayList<>();
            for (var e : f) {
                int j = e[0], x = e[1];
                int y = gcd(x, nums[i]);
                if (g.isEmpty() || g.get(g.size() - 1)[1] != y) {
                    g.add(new int[] {j, y});
                }
            }
            f = g;
            f.add(new int[] {i, nums[i]});
            for (var e : f) {
                int j = e[0], x = e[1];
                if (i - j + 1 >= k) {
                    ans = Math.max(ans, (s[i + 1] - s[j]) * x);
                }
            }
        }
        return ans;
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
    long long maxGcdSum(vector<int>& nums, int k) {
        int n = nums.size();
        long long s[n + 1];
        s[0] = 0;
        for (int i = 1; i <= n; ++i) {
            s[i] = s[i - 1] + nums[i - 1];
        }
        vector<pair<int, int>> f;
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            vector<pair<int, int>> g;
            for (auto [j, x] : f) {
                int y = gcd(x, nums[i]);
                if (g.empt() || g.back().second != y) {
                    g.emplace_back(j, y);
                }
            }
            f = move(g);
            f.emplace_back(i, nums[i]);
            for (auto [j, x] : f) {
                if (i - j + 1 >= k) {
                    ans = max(ans, (s[i + 1] - s[j]) * x);
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
func maxGcdSum(nums []int, k int) int64 {
	n := len(nums)
	s := make([]int64, n+1)
	s[0] = 0
	for i, x := range nums {
		s[i+1] = s[i] + int64(x)
	}
	type pair [2]int
	var f []pair
	var ans int64
	for i := 0; i < n; i++ {
		var g []pair
		for _, p := range f {
			j, x := p[0], p[1]
			y := int(gcd(int(x), nums[i]))
			if len(g) == 0 || g[len(g)-1][1] != y {
				g = append(g, pair{j, y})
			}
		}
		f = g
		f = append(f, pair{i, nums[i]})
		for _, p := range f {
			j, x := p[0], p[1]
			if i-j+1 >= k {
				ans = max(ans, (s[i+1]-s[j])*int64(x))
			}
		}
	}
	return ans
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
function maxGcdSum(nums: number[], k: number): number {
    const n: number = nums.length;
    const s: number[] = Array(n + 1).fill(0);
    for (let i = 1; i <= n; i++) {
        s[i] = s[i - 1] + nums[i - 1];
    }

    let f: [number, number][] = [];
    let ans: number = 0;

    for (let i = 0; i < n; ++i) {
        const g: [number, number][] = [];
        for (const [j, x] of f) {
            const y: number = gcd(x, nums[i]);
            if (g.length === 0 || g.at(-1)[1] !== y) {
                g.push([j, y]);
            }
        }
        f = g;
        f.push([i, nums[i]]);
        for (const [j, x] of f) {
            if (i - j + 1 >= k) {
                ans = Math.max(ans, (s[i + 1] - s[j]) * x);
            }
        }
    }

    return ans;
}

function gcd(a: number, b: number): number {
    return b === 0 ? a : gcd(b, a % b);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个整数数组 <code>nums</code> 和一个整数 <code>k</code>.</p>

<p>数组 <code>a</code> 的 <strong>gcd-sum</strong>&nbsp;计算方法如下：</p>

<ul>
	<li>设&nbsp;<code>s</code>&nbsp;为&nbsp;<code>a</code>&nbsp;的所有元素的和。</li>
	<li>设&nbsp;<code>g</code>&nbsp;为&nbsp;<code>a</code>&nbsp;的所有元素的 <strong>最大公约数</strong>。</li>
	<li><code>a</code> 的 gcd-sum&nbsp;等于 <code>s * g</code>.</li>
</ul>

<p>返回 <em><code>nums</code> 的至少包含 <code>k</code> 个元素的子数组的 <strong>最大 gcd-sum</strong>。</em></p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [2,1,4,4,4,2], k = 2
<b>输出：</b>48
<b>解释：</b>我们选择子数组 [4,4,4]，该数组的 gcd-sum 为 4 * (4 + 4 + 4) = 48。
可以证明我们无法选择任何其他 gcd-sum 大于 48 的子数组。</pre>

<p><b>示例 2：</b></p>

<pre>
<b>输入：</b>nums = [7,3,9,4], k = 1
<b>输出：</b>81
<b>解释：</b>我们选择子数组 [9]，该数组的 gcd-sum 为 9 * 9 = 81。
可以证明我们无法选择任何其他 gcd-sum 大于 81 的子数组。</pre>

<p>&nbsp;</p>

<p><b>提示：</b></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
	<li><code>1 &lt;= k &lt;= n</code></li>
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
    def maxGcdSum(self, nums: List[int], k: int) -> int:
        s = list(accumulate(nums, initial=0))
        f = []
        ans = 0
        for i, v in enumerate(nums):
            g = []
            for j, x in f:
                y = gcd(x, v)
                if not g or g[-1][1] != y:
                    g.append((j, y))
            f = g
            f.append((i, v))
            for j, x in f:
                if i - j + 1 >= k:
                    ans = max(ans, (s[i + 1] - s[j]) * x)
        return ans
```

#### Java

```java
class Solution {
    public long maxGcdSum(int[] nums, int k) {
        int n = nums.length;
        long[] s = new long[n + 1];
        for (int i = 1; i <= n; ++i) {
            s[i] = s[i - 1] + nums[i - 1];
        }
        List<int[]> f = new ArrayList<>();
        long ans = 0;
        for (int i = 0; i < n; ++i) {
            List<int[]> g = new ArrayList<>();
            for (var e : f) {
                int j = e[0], x = e[1];
                int y = gcd(x, nums[i]);
                if (g.isEmpty() || g.get(g.size() - 1)[1] != y) {
                    g.add(new int[] {j, y});
                }
            }
            f = g;
            f.add(new int[] {i, nums[i]});
            for (var e : f) {
                int j = e[0], x = e[1];
                if (i - j + 1 >= k) {
                    ans = Math.max(ans, (s[i + 1] - s[j]) * x);
                }
            }
        }
        return ans;
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
    long long maxGcdSum(vector<int>& nums, int k) {
        int n = nums.size();
        long long s[n + 1];
        s[0] = 0;
        for (int i = 1; i <= n; ++i) {
            s[i] = s[i - 1] + nums[i - 1];
        }
        vector<pair<int, int>> f;
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            vector<pair<int, int>> g;
            for (auto [j, x] : f) {
                int y = gcd(x, nums[i]);
                if (g.empt() || g.back().second != y) {
                    g.emplace_back(j, y);
                }
            }
            f = move(g);
            f.emplace_back(i, nums[i]);
            for (auto [j, x] : f) {
                if (i - j + 1 >= k) {
                    ans = max(ans, (s[i + 1] - s[j]) * x);
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func maxGcdSum(nums []int, k int) int64 {
	n := len(nums)
	s := make([]int64, n+1)
	s[0] = 0
	for i, x := range nums {
		s[i+1] = s[i] + int64(x)
	}
	type pair [2]int
	var f []pair
	var ans int64
	for i := 0; i < n; i++ {
		var g []pair
		for _, p := range f {
			j, x := p[0], p[1]
			y := int(gcd(int(x), nums[i]))
			if len(g) == 0 || g[len(g)-1][1] != y {
				g = append(g, pair{j, y})
			}
		}
		f = g
		f = append(f, pair{i, nums[i]})
		for _, p := range f {
			j, x := p[0], p[1]
			if i-j+1 >= k {
				ans = max(ans, (s[i+1]-s[j])*int64(x))
			}
		}
	}
	return ans
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
function maxGcdSum(nums: number[], k: number): number {
    const n: number = nums.length;
    const s: number[] = Array(n + 1).fill(0);
    for (let i = 1; i <= n; i++) {
        s[i] = s[i - 1] + nums[i - 1];
    }

    let f: [number, number][] = [];
    let ans: number = 0;

    for (let i = 0; i < n; ++i) {
        const g: [number, number][] = [];
        for (const [j, x] of f) {
            const y: number = gcd(x, nums[i]);
            if (g.length === 0 || g.at(-1)[1] !== y) {
                g.push([j, y]);
            }
        }
        f = g;
        f.push([i, nums[i]]);
        for (const [j, x] of f) {
            if (i - j + 1 >= k) {
                ans = Math.max(ans, (s[i + 1] - s[j]) * x);
            }
        }
    }

    return ans;
}

function gcd(a: number, b: number): number {
    return b === 0 ? a : gcd(b, a % b);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### TypeScript

```ts
function maxGcdSum(nums: number[], k: number): number {
    const n: number = nums.length;
    const s: number[] = Array(n + 1).fill(0);
    for (let i = 1; i <= n; i++) {
        s[i] = s[i - 1] + nums[i - 1];
    }

    let f: [number, number][] = [];
    let ans: number = 0;

    for (let i = 0; i < n; ++i) {
        const g: [number, number][] = [];
        for (const [j, x] of f) {
            const y: number = gcd(x, nums[i]);
            if (g.length === 0 || g.at(-1)[1] !== y) {
                g.push([j, y]);
            }
        }
        f = g;
        f.push([i, nums[i]]);
        for (const [j, x] of f) {
            if (i - j + 1 >= k) {
                ans = Math.max(ans, (s[i + 1] - s[j]) * x);
            }
        }
    }

    return ans;
}

function gcd(a: number, b: number): number {
    return b === 0 ? a : gcd(b, a % b);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2942. 查找包含给定字符的单词](https://leetcode.cn/problems/find-words-containing-character){#2942}

{{< tabs "2942" >}}

{{% tab "python" %}}
```python
class Solution:
    def findWordsContaining(self, words: List[str], x: str) -> List[int]:
        return [i for i, w in enumerate(words) if x in w]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<Integer> findWordsContaining(String[] words, char x) {
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < words.length; ++i) {
            if (words[i].indexOf(x) != -1) {
                ans.add(i);
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
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;
        for (int i = 0; i < words.size(); ++i) {
            if (words[i].find(x) != string::npos) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findWordsContaining(words []string, x byte) (ans []int) {
	for i, w := range words {
		for _, c := range w {
			if byte(c) == x {
				ans = append(ans, i)
				break
			}
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findWordsContaining(words: string[], x: string): number[] {
    return words.flatMap((w, i) => (w.includes(x) ? [i] : []));
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn find_words_containing(words: Vec<String>, x: char) -> Vec<i32> {
        words.into_iter().enumerate()
            .filter_map(|(i, w)| w.contains(x).then(|| i as i32))
            .collect()
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的字符串数组&nbsp;<code>words</code>&nbsp;和一个字符&nbsp;<code>x</code>&nbsp;。</p>

<p>请你返回一个 <strong>下标数组</strong>&nbsp;，表示下标在数组中对应的单词包含字符 <code>x</code>&nbsp;。</p>

<p><b>注意</b>&nbsp;，返回的数组可以是&nbsp;<strong>任意</strong>&nbsp;顺序。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>words = ["leet","code"], x = "e"
<b>输出：</b>[0,1]
<b>解释：</b>"e" 在两个单词中都出现了："l<em><strong>ee</strong></em>t" 和 "cod<em><strong>e</strong></em>" 。所以我们返回下标 0 和 1 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>words = ["abc","bcd","aaaa","cbc"], x = "a"
<b>输出：</b>[0,2]
<b>解释：</b>"a" 在 "<em><strong>a</strong></em>bc" 和 "<em><strong>aaaa</strong></em>" 中出现了，所以我们返回下标 0 和 2 。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>words = ["abc","bcd","aaaa","cbc"], x = "z"
<b>输出：</b>[]
<b>解释：</b>"z" 没有在任何单词中出现。所以我们返回空数组。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 50</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 50</code></li>
	<li><code>x</code>&nbsp;是一个小写英文字母。</li>
	<li><code>words[i]</code>&nbsp;只包含小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：遍历

我们直接遍历字符串数组 $words$ 中的每一个字符串 $words[i]$，如果 $x$ 在 $words[i]$ 中出现，就将 $i$ 加入答案数组中。

遍历结束后，返回答案数组即可。

时间复杂度 $O(L)$，其中 $L$ 为字符串数组 $words$ 中所有字符串的长度和。忽略答案数组的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findWordsContaining(self, words: List[str], x: str) -> List[int]:
        return [i for i, w in enumerate(words) if x in w]
```

#### Java

```java
class Solution {
    public List<Integer> findWordsContaining(String[] words, char x) {
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < words.length; ++i) {
            if (words[i].indexOf(x) != -1) {
                ans.add(i);
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
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;
        for (int i = 0; i < words.size(); ++i) {
            if (words[i].find(x) != string::npos) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func findWordsContaining(words []string, x byte) (ans []int) {
	for i, w := range words {
		for _, c := range w {
			if byte(c) == x {
				ans = append(ans, i)
				break
			}
		}
	}
	return
}
```

#### TypeScript

```ts
function findWordsContaining(words: string[], x: string): number[] {
    return words.flatMap((w, i) => (w.includes(x) ? [i] : []));
}
```

#### Rust

```rust
impl Solution {
    pub fn find_words_containing(words: Vec<String>, x: char) -> Vec<i32> {
        words.into_iter().enumerate()
            .filter_map(|(i, w)| w.contains(x).then(|| i as i32))
            .collect()
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2943. 最大化网格图中正方形空洞的面积](https://leetcode.cn/problems/maximize-area-of-square-hole-in-grid){#2943}

{{< tabs "2943" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximizeSquareHoleArea(
        self, n: int, m: int, hBars: List[int], vBars: List[int]
    ) -> int:
        def f(nums: List[int]) -> int:
            nums.sort()
            ans = cnt = 1
            for i in range(1, len(nums)):
                if nums[i] == nums[i - 1] + 1:
                    cnt += 1
                    ans = max(ans, cnt)
                else:
                    cnt = 1
            return ans + 1

        return min(f(hBars), f(vBars)) ** 2
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maximizeSquareHoleArea(int n, int m, int[] hBars, int[] vBars) {
        int x = Math.min(f(hBars), f(vBars));
        return x * x;
    }

    private int f(int[] nums) {
        Arrays.sort(nums);
        int ans = 1, cnt = 1;
        for (int i = 1; i < nums.length; ++i) {
            if (nums[i] == nums[i - 1] + 1) {
                ans = Math.max(ans, ++cnt);
            } else {
                cnt = 1;
            }
        }
        return ans + 1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        auto f = [](vector<int>& nums) {
            int ans = 1, cnt = 1;
            sort(nums.begin(), nums.end());
            for (int i = 1; i < nums.size(); ++i) {
                if (nums[i] == nums[i - 1] + 1) {
                    ans = max(ans, ++cnt);
                } else {
                    cnt = 1;
                }
            }
            return ans + 1;
        };
        int x = min(f(hBars), f(vBars));
        return x * x;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximizeSquareHoleArea(n int, m int, hBars []int, vBars []int) int {
	f := func(nums []int) int {
		sort.Ints(nums)
		ans, cnt := 1, 1
		for i, x := range nums[1:] {
			if x == nums[i]+1 {
				cnt++
				ans = max(ans, cnt)
			} else {
				cnt = 1
			}
		}
		return ans + 1
	}
	x := min(f(hBars), f(vBars))
	return x * x
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximizeSquareHoleArea(n: number, m: number, hBars: number[], vBars: number[]): number {
    const f = (nums: number[]): number => {
        nums.sort((a, b) => a - b);
        let [ans, cnt] = [1, 1];
        for (let i = 1; i < nums.length; ++i) {
            if (nums[i] === nums[i - 1] + 1) {
                ans = Math.max(ans, ++cnt);
            } else {
                cnt = 1;
            }
        }
        return ans + 1;
    };
    return Math.min(f(hBars), f(vBars)) ** 2;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn maximize_square_hole_area(n: i32, m: i32, h_bars: Vec<i32>, v_bars: Vec<i32>) -> i32 {
        let f = |nums: &mut Vec<i32>| -> i32 {
            let mut ans = 1;
            let mut cnt = 1;
            nums.sort();
            for i in 1..nums.len() {
                if nums[i] == nums[i - 1] + 1 {
                    cnt += 1;
                    ans = ans.max(cnt);
                } else {
                    cnt = 1;
                }
            }
            ans + 1
        };

        let mut h_bars = h_bars;
        let mut v_bars = v_bars;
        let x = f(&mut h_bars).min(f(&mut v_bars));
        x * x
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个网格图，由&nbsp;<code>n + 2</code>&nbsp;条 <strong>横线段</strong>&nbsp;和&nbsp;<code>m + 2</code>&nbsp;条&nbsp;<strong>竖线段</strong>&nbsp;组成，一开始所有区域均为&nbsp;<code>1 x 1</code>&nbsp;的单元格。</p>

<p>所有线段的编号从 <strong>1</strong>&nbsp;开始。</p>

<p>给你两个整数&nbsp;<code>n</code> 和&nbsp;<code>m</code>&nbsp;。</p>

<p>同时给你两个整数数组&nbsp;<code>hBars</code> 和&nbsp;<code>vBars</code>&nbsp;。</p>

<ul>
	<li><code>hBars</code> 包含区间&nbsp;<code>[2, n + 1]</code>&nbsp;内&nbsp;<strong>互不相同</strong>&nbsp;的横线段编号。</li>
	<li><code>vBars</code>&nbsp;包含&nbsp;<code>[2, m + 1]</code>&nbsp;内&nbsp;<strong>互不相同的</strong>&nbsp;竖线段编号。</li>
</ul>

<p>如果满足以下条件之一，你可以 <strong>移除</strong>&nbsp;两个数组中的部分线段：</p>

<ul>
	<li>如果移除的是横线段，它必须是&nbsp;<code>hBars</code>&nbsp;中的值。</li>
	<li>如果移除的是竖线段，它必须是&nbsp;<code>vBars</code>&nbsp;中的值。</li>
</ul>

<p>请你返回移除一些线段后（<strong>可能不移除任何线段）</strong>，剩余网格图中 <strong>最大正方形</strong>&nbsp;空洞的面积，正方形空洞的意思是正方形 <strong>内部</strong> 不含有任何线段。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2900-2999/2943.Maximize%20Area%20of%20Square%20Hole%20in%20Grid/images/screenshot-from-2023-11-05-22-40-25.png" style="width: 411px; height: 220px;" /></p>

<pre>
<b>输入：</b>n = 2, m = 1, hBars = [2,3], vBars = [2]
<b>输出：</b>4
<b>解释：</b>左边的图是一开始的网格图。
横线编号的范围是区间 [1,4] ，竖线编号的范围是区间 [1,3] 。
可以移除的横线段为 [2,3] ，竖线段为 [2] 。
一种得到最大正方形面积的方法是移除横线段 2 和竖线段 2 。
操作后得到的网格图如右图所示。
正方形空洞面积为 4。
无法得到面积大于 4 的正方形空洞。
所以答案为 4 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2900-2999/2943.Maximize%20Area%20of%20Square%20Hole%20in%20Grid/images/screenshot-from-2023-11-04-17-01-02.png" style="width: 368px; height: 145px;" /></p>

<pre>
<b>输入：</b>n = 1, m = 1, hBars = [2], vBars = [2]
<b>输出：</b>4
<b>解释：</b>左边的图是一开始的网格图。
横线编号的范围是区间 [1,3] ，竖线编号的范围是区间 [1,3] 。
可以移除的横线段为 [2] ，竖线段为 [2] 。
一种得到最大正方形面积的方法是移除横线段 2 和竖线段 2 。
操作后得到的网格图如右图所示。
正方形空洞面积为 4。
无法得到面积大于 4 的正方形空洞。
所以答案为 4 。
</pre>

<p><strong class="example">示例 3：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2900-2999/2943.Maximize%20Area%20of%20Square%20Hole%20in%20Grid/images/screenshot-from-2023-11-05-22-33-35.png" style="width: 648px; height: 218px;" /></p>

<pre>
<b>输入：</b>n = 2, m = 3, hBars = [2,3], vBars = [2,3,4]
<b>输出：</b>9
<b>解释：</b>左边的图是一开始的网格图。
横线编号的范围是区间 [1,4] ，竖线编号的范围是区间 [1,5] 。
可以移除的横线段为 [2,3] ，竖线段为 [2,3,4] 。
一种得到最大正方形面积的方法是移除横线段 2、3 和竖线段 3、4 。
操作后得到的网格图如右图所示。
正方形空洞面积为 9。
无法得到面积大于 9 的正方形空洞。
所以答案为 9 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= m &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= hBars.length &lt;= 100</code></li>
	<li><code>2 &lt;= hBars[i] &lt;= n + 1</code></li>
	<li><code>1 &lt;= vBars.length &lt;= 100</code></li>
	<li><code>2 &lt;= vBars[i] &lt;= m + 1</code></li>
	<li><code>hBars</code>&nbsp;中的值互不相同。</li>
	<li><code>vBars</code> 中的值互不相同。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序

题目实际上要我们找出数组中最长的连续递增子序列的长度，然后再加上 $1$。

我们定义一个函数 $f(nums)$，表示数组 $nums$ 中最长的连续递增子序列的长度。

对于数组 $nums$，我们先对其进行排序，然后遍历数组，如果当前元素 $nums[i]$ 等于前一个元素 $nums[i - 1]$ 加 $1$，则说明当前元素可以加入到连续递增子序列中，否则，说明当前元素不能加入到连续递增子序列中，我们需要重新开始计算连续递增子序列的长度。最后，我们返回连续递增子序列的长度加 $1$。

我们在求出 $hBars$ 和 $vBars$ 中最长的连续递增子序列的长度之后，我们取两者中的最小值作为正方形的边长，然后再求出正方形的面积即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $hBars$ 或 $vBars$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximizeSquareHoleArea(
        self, n: int, m: int, hBars: List[int], vBars: List[int]
    ) -> int:
        def f(nums: List[int]) -> int:
            nums.sort()
            ans = cnt = 1
            for i in range(1, len(nums)):
                if nums[i] == nums[i - 1] + 1:
                    cnt += 1
                    ans = max(ans, cnt)
                else:
                    cnt = 1
            return ans + 1

        return min(f(hBars), f(vBars)) ** 2
```

#### Java

```java
class Solution {
    public int maximizeSquareHoleArea(int n, int m, int[] hBars, int[] vBars) {
        int x = Math.min(f(hBars), f(vBars));
        return x * x;
    }

    private int f(int[] nums) {
        Arrays.sort(nums);
        int ans = 1, cnt = 1;
        for (int i = 1; i < nums.length; ++i) {
            if (nums[i] == nums[i - 1] + 1) {
                ans = Math.max(ans, ++cnt);
            } else {
                cnt = 1;
            }
        }
        return ans + 1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        auto f = [](vector<int>& nums) {
            int ans = 1, cnt = 1;
            sort(nums.begin(), nums.end());
            for (int i = 1; i < nums.size(); ++i) {
                if (nums[i] == nums[i - 1] + 1) {
                    ans = max(ans, ++cnt);
                } else {
                    cnt = 1;
                }
            }
            return ans + 1;
        };
        int x = min(f(hBars), f(vBars));
        return x * x;
    }
};
```

#### Go

```go
func maximizeSquareHoleArea(n int, m int, hBars []int, vBars []int) int {
	f := func(nums []int) int {
		sort.Ints(nums)
		ans, cnt := 1, 1
		for i, x := range nums[1:] {
			if x == nums[i]+1 {
				cnt++
				ans = max(ans, cnt)
			} else {
				cnt = 1
			}
		}
		return ans + 1
	}
	x := min(f(hBars), f(vBars))
	return x * x
}
```

#### TypeScript

```ts
function maximizeSquareHoleArea(n: number, m: number, hBars: number[], vBars: number[]): number {
    const f = (nums: number[]): number => {
        nums.sort((a, b) => a - b);
        let [ans, cnt] = [1, 1];
        for (let i = 1; i < nums.length; ++i) {
            if (nums[i] === nums[i - 1] + 1) {
                ans = Math.max(ans, ++cnt);
            } else {
                cnt = 1;
            }
        }
        return ans + 1;
    };
    return Math.min(f(hBars), f(vBars)) ** 2;
}
```

#### Rust

```rust
impl Solution {
    pub fn maximize_square_hole_area(n: i32, m: i32, h_bars: Vec<i32>, v_bars: Vec<i32>) -> i32 {
        let f = |nums: &mut Vec<i32>| -> i32 {
            let mut ans = 1;
            let mut cnt = 1;
            nums.sort();
            for i in 1..nums.len() {
                if nums[i] == nums[i - 1] + 1 {
                    cnt += 1;
                    ans = ans.max(cnt);
                } else {
                    cnt = 1;
                }
            }
            ans + 1
        };

        let mut h_bars = h_bars;
        let mut v_bars = v_bars;
        let x = f(&mut h_bars).min(f(&mut v_bars));
        x * x
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2944. 购买水果需要的最少金币数](https://leetcode.cn/problems/minimum-number-of-coins-for-fruits){#2944}

{{< tabs "2944" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumCoins(self, prices: List[int]) -> int:
        n = len(prices)
        q = deque()
        for i in range(n, 0, -1):
            while q and q[0] > i * 2 + 1:
                q.popleft()
            if i <= (n - 1) // 2:
                prices[i - 1] += prices[q[0] - 1]
            while q and prices[q[-1] - 1] >= prices[i - 1]:
                q.pop()
            q.append(i)
        return prices[0]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumCoins(int[] prices) {
        int n = prices.length;
        Deque<Integer> q = new ArrayDeque<>();
        for (int i = n; i > 0; --i) {
            while (!q.isEmpty() && q.peek() > i * 2 + 1) {
                q.poll();
            }
            if (i <= (n - 1) / 2) {
                prices[i - 1] += prices[q.peek() - 1];
            }
            while (!q.isEmpty() && prices[q.peekLast() - 1] >= prices[i - 1]) {
                q.pollLast();
            }
            q.offer(i);
        }
        return prices[0];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        int n = prices.size();
        deque<int> q;
        for (int i = n; i; --i) {
            while (q.size() && q.front() > i * 2 + 1) {
                q.pop_front();
            }
            if (i <= (n - 1) / 2) {
                prices[i - 1] += prices[q.front() - 1];
            }
            while (q.size() && prices[q.back() - 1] >= prices[i - 1]) {
                q.pop_back();
            }
            q.push_back(i);
        }
        return prices[0];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumCoins(prices []int) int {
	n := len(prices)
	q := Deque{}
	for i := n; i > 0; i-- {
		for q.Size() > 0 && q.Front() > i*2+1 {
			q.PopFront()
		}
		if i <= (n-1)/2 {
			prices[i-1] += prices[q.Front()-1]
		}
		for q.Size() > 0 && prices[q.Back()-1] >= prices[i-1] {
			q.PopBack()
		}
		q.PushBack(i)
	}
	return prices[0]
}

// template
type Deque struct{ l, r []int }

func (q Deque) Empty() bool {
	return len(q.l) == 0 && len(q.r) == 0
}

func (q Deque) Size() int {
	return len(q.l) + len(q.r)
}

func (q *Deque) PushFront(v int) {
	q.l = append(q.l, v)
}

func (q *Deque) PushBack(v int) {
	q.r = append(q.r, v)
}

func (q *Deque) PopFront() (v int) {
	if len(q.l) > 0 {
		q.l, v = q.l[:len(q.l)-1], q.l[len(q.l)-1]
	} else {
		v, q.r = q.r[0], q.r[1:]
	}
	return
}

func (q *Deque) PopBack() (v int) {
	if len(q.r) > 0 {
		q.r, v = q.r[:len(q.r)-1], q.r[len(q.r)-1]
	} else {
		v, q.l = q.l[0], q.l[1:]
	}
	return
}

func (q Deque) Front() int {
	if len(q.l) > 0 {
		return q.l[len(q.l)-1]
	}
	return q.r[0]
}

func (q Deque) Back() int {
	if len(q.r) > 0 {
		return q.r[len(q.r)-1]
	}
	return q.l[0]
}

func (q Deque) Get(i int) int {
	if i < len(q.l) {
		return q.l[len(q.l)-1-i]
	}
	return q.r[i-len(q.l)]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumCoins(prices: number[]): number {
    const n = prices.length;
    const q = new Deque<number>();
    for (let i = n; i; --i) {
        while (q.getSize() && q.frontValue()! > i * 2 + 1) {
            q.popFront();
        }
        if (i <= (n - 1) >> 1) {
            prices[i - 1] += prices[q.frontValue()! - 1];
        }
        while (q.getSize() && prices[q.backValue()! - 1] >= prices[i - 1]) {
            q.popBack();
        }
        q.pushBack(i);
    }
    return prices[0];
}

class Node<T> {
    value: T;
    next: Node<T> | null;
    prev: Node<T> | null;

    constructor(value: T) {
        this.value = value;
        this.next = null;
        this.prev = null;
    }
}

class Deque<T> {
    private front: Node<T> | null;
    private back: Node<T> | null;
    private size: number;

    constructor() {
        this.front = null;
        this.back = null;
        this.size = 0;
    }

    pushFront(val: T): void {
        const newNode = new Node(val);
        if (this.isEmpty()) {
            this.front = newNode;
            this.back = newNode;
        } else {
            newNode.next = this.front;
            this.front!.prev = newNode;
            this.front = newNode;
        }
        this.size++;
    }

    pushBack(val: T): void {
        const newNode = new Node(val);
        if (this.isEmpty()) {
            this.front = newNode;
            this.back = newNode;
        } else {
            newNode.prev = this.back;
            this.back!.next = newNode;
            this.back = newNode;
        }
        this.size++;
    }

    popFront(): T | undefined {
        if (this.isEmpty()) {
            return undefined;
        }
        const value = this.front!.value;
        this.front = this.front!.next;
        if (this.front !== null) {
            this.front.prev = null;
        } else {
            this.back = null;
        }
        this.size--;
        return value;
    }

    popBack(): T | undefined {
        if (this.isEmpty()) {
            return undefined;
        }
        const value = this.back!.value;
        this.back = this.back!.prev;
        if (this.back !== null) {
            this.back.next = null;
        } else {
            this.front = null;
        }
        this.size--;
        return value;
    }

    frontValue(): T | undefined {
        return this.front?.value;
    }

    backValue(): T | undefined {
        return this.back?.value;
    }

    getSize(): number {
        return this.size;
    }

    isEmpty(): boolean {
        return this.size === 0;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个 <strong>下标从 0&nbsp;开始的</strong> 整数数组&nbsp;<code>prices</code>&nbsp;，其中&nbsp;<code>prices[i]</code>&nbsp;表示你购买第 <code>i + 1</code>&nbsp;个水果需要花费的金币数目。</p>

<p>水果超市有如下促销活动：</p>

<ul>
	<li>如果你花费 <code>prices[i]</code>&nbsp;购买了下标为&nbsp;<code>i + 1</code>&nbsp;的水果，那么你可以免费获得下标范围在&nbsp;<code>[i + 1, i + i]</code>&nbsp;的水果。</li>
</ul>

<p><strong>注意</strong>&nbsp;，即使你&nbsp;<strong>可以</strong>&nbsp;免费获得水果&nbsp;<code>j</code>&nbsp;，你仍然可以花费&nbsp;<code>prices[j - 1]</code>&nbsp;个金币去购买它以获得它的奖励。</p>

<p>请你返回获得所有水果所需要的 <strong>最少</strong>&nbsp;金币数。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">prices = [3,1,2]</span></p>

<p><strong>输出：</strong><span class="example-io">4</span></p>

<p><strong>解释：</strong></p>

<ul>
	<li>用&nbsp;<code>prices[0] = 3</code>&nbsp;个金币购买第 1 个水果，你可以免费获得第 2 个水果。</li>
	<li>用&nbsp;<code>prices[1] = 1</code>&nbsp;个金币购买第 2 个水果，你可以免费获得第 3 个水果。</li>
	<li>免费获得第 3 个水果。</li>
</ul>

<p>请注意，即使您可以免费获得第 2 个水果作为购买第 1 个水果的奖励，但您购买它是为了获得其奖励，这是更优化的。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">prices = [1,10,1,1]</span></p>

<p><strong>输出：</strong><span class="example-io">2</span></p>

<p><strong>解释：</strong></p>

<ul>
	<li>用&nbsp;<code>prices[0] = 1</code> 个金币购买第 1 个水果，你可以免费获得第 2 个水果。</li>
	<li>免费获得第 2 个水果。</li>
	<li>用&nbsp;<code>prices[2] = 1</code> 个金币购买第 3 个水果，你可以免费获得第 4 个水果。</li>
	<li>免费获得第 4 个水果。</li>
</ul>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">prices = [26,18,6,12,49,7,45,45]</span></p>

<p><strong>输出：</strong><span class="example-io">39</span></p>

<p><strong>解释：</strong></p>

<ul>
	<li>用&nbsp;<code>prices[0] = 26</code> 个金币购买第 1 个水果，你可以免费获得第 2 个水果。</li>
	<li>免费获得第 2 个水果。</li>
	<li>用&nbsp;<code>prices[2] = 6</code> 个金币购买第 3 个水果，你可以免费获得第 4，5，6（接下来的三个）水果。</li>
	<li>免费获得第 4 个水果。</li>
	<li>免费获得第 5&nbsp;个水果。</li>
	<li>用&nbsp;<code>prices[5] = 7</code>&nbsp;个金币购买第 6 个水果，你可以免费获得第 7 和 第 8 个水果。</li>
	<li>免费获得第 7&nbsp;个水果。</li>
	<li>免费获得第 8&nbsp;个水果。</li>
</ul>

<p>请注意，即使您可以免费获得第 6 个水果作为购买第 3 个水果的奖励，但您购买它是为了获得其奖励，这是更优化的。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= prices.length &lt;= 1000</code></li>
	<li><code>1 &lt;= prices[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

我们定义一个函数 $\textit{dfs}(i)$，表示从第 $i$ 个水果开始购买所有水果所需要的最少金币数。那么答案就是 $\textit{dfs}(1)$。

函数 $\textit{dfs}(i)$ 的执行逻辑如下：

-   如果 $i \times 2 \geq n$，说明只要买第 $i - 1$ 个水果即可，剩余的水果都可以免费获得，所以返回 $\textit{prices}[i - 1]$。
-   否则，我们可以购买水果 $i$，然后在接下来的 $i + 1$ 到 $2i + 1$ 个水果中选择一个水果 $j$ 开始购买，那么 $\textit{dfs}(i) = \textit{prices}[i - 1] + \min_{i + 1 \le j \le 2i + 1} \textit{dfs}(j)$。

为了避免重复计算，我们使用记忆化搜索的方法，将已经计算过的结果保存起来，下次遇到相同的情况时，直接返回结果即可。

时间复杂度 $O(n^2)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $\textit{prices}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumCoins(self, prices: List[int]) -> int:
        @cache
        def dfs(i: int) -> int:
            if i * 2 >= len(prices):
                return prices[i - 1]
            return prices[i - 1] + min(dfs(j) for j in range(i + 1, i * 2 + 2))

        return dfs(1)
```

#### Java

```java
class Solution {
    private int[] prices;
    private int[] f;
    private int n;

    public int minimumCoins(int[] prices) {
        n = prices.length;
        f = new int[n + 1];
        this.prices = prices;
        return dfs(1);
    }

    private int dfs(int i) {
        if (i * 2 >= n) {
            return prices[i - 1];
        }
        if (f[i] == 0) {
            f[i] = 1 << 30;
            for (int j = i + 1; j <= i * 2 + 1; ++j) {
                f[i] = Math.min(f[i], prices[i - 1] + dfs(j));
            }
        }
        return f[i];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        int n = prices.size();
        int f[n + 1];
        memset(f, 0x3f, sizeof(f));
        function<int(int)> dfs = [&](int i) {
            if (i * 2 >= n) {
                return prices[i - 1];
            }
            if (f[i] == 0x3f3f3f3f) {
                for (int j = i + 1; j <= i * 2 + 1; ++j) {
                    f[i] = min(f[i], prices[i - 1] + dfs(j));
                }
            }
            return f[i];
        };
        return dfs(1);
    }
};
```

#### Go

```go
func minimumCoins(prices []int) int {
	n := len(prices)
	f := make([]int, n+1)
	var dfs func(int) int
	dfs = func(i int) int {
		if i*2 >= n {
			return prices[i-1]
		}
		if f[i] == 0 {
			f[i] = 1 << 30
			for j := i + 1; j <= i*2+1; j++ {
				f[i] = min(f[i], dfs(j)+prices[i-1])
			}
		}
		return f[i]
	}
	return dfs(1)
}
```

#### TypeScript

```ts
function minimumCoins(prices: number[]): number {
    const n = prices.length;
    const f: number[] = Array(n + 1).fill(0);
    const dfs = (i: number): number => {
        if (i * 2 >= n) {
            return prices[i - 1];
        }
        if (f[i] === 0) {
            f[i] = 1 << 30;
            for (let j = i + 1; j <= i * 2 + 1; ++j) {
                f[i] = Math.min(f[i], prices[i - 1] + dfs(j));
            }
        }
        return f[i];
    };
    return dfs(1);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：动态规划

我们可以将方法一中的记忆化搜索改写成动态规划的形式。

与方法一类似，我们定义 $f[i]$ 表示从第 $i$ 个水果开始购买所有水果所需要的最少金币数。那么答案就是 $f[1]$。

状态转移方程为 $f[i] = \min_{i + 1 \le j \le 2i + 1} f[j] + \textit{prices}[i - 1]$。

时间复杂度 $O(n^2)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $\textit{prices}$ 的长度。

在代码实现上，我们可以直接使用 $\textit{prices}$ 数组来存储 $f$ 数组，那么空间复杂度可以优化到 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumCoins(self, prices: List[int]) -> int:
        n = len(prices)
        for i in range((n - 1) // 2, 0, -1):
            prices[i - 1] += min(prices[i : i * 2 + 1])
        return prices[0]
```

#### Java

```java
class Solution {
    public int minimumCoins(int[] prices) {
        int n = prices.length;
        for (int i = (n - 1) / 2; i > 0; --i) {
            int mi = 1 << 30;
            for (int j = i; j <= i * 2; ++j) {
                mi = Math.min(mi, prices[j]);
            }
            prices[i - 1] += mi;
        }
        return prices[0];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        int n = prices.size();
        for (int i = (n - 1) / 2; i; --i) {
            prices[i - 1] += *min_element(prices.begin() + i, prices.begin() + 2 * i + 1);
        }
        return prices[0];
    }
};
```

#### Go

```go
func minimumCoins(prices []int) int {
	for i := (len(prices) - 1) / 2; i > 0; i-- {
		prices[i-1] += slices.Min(prices[i : i*2+1])
	}
	return prices[0]
}
```

#### TypeScript

```ts
function minimumCoins(prices: number[]): number {
    for (let i = (prices.length - 1) >> 1; i; --i) {
        prices[i - 1] += Math.min(...prices.slice(i, i * 2 + 1));
    }
    return prices[0];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法三：动态规划 + 单调队列优化

我们观察方法二中的状态转移方程，可以发现，对于每个 $i$，我们需要求出 $f[i + 1], f[i + 2], \cdots, f[2i + 1]$ 的最小值，并且随着 $i$ 的减小，这些值的范围也在减小。这实际上是求一个单调收窄的滑动窗口的最小值，我们可以使用单调队列来优化。

我们从后往前计算，维护一个单调递增的队列 $q$，队列中存储的是下标。如果 $q$ 的队首元素大于 $i \times 2 + 1$，说明 $i$ 之后的元素都不会被用到，所以我们将队首元素出队。如果 $i$ 不大于 $(n - 1) / 2$，那么我们可以将 $\textit{prices}[q[0] - 1]$ 加到 $\textit{prices}[i - 1]$ 上，然后将 $i$ 加入队尾。如果 $q$ 的队尾元素对应的水果价格大于等于 $\textit{prices}[i - 1]$，那么我们将队尾元素出队，直到队尾元素对应的水果价格小于 $\textit{prices}[i - 1]$ 或者队列为空，然后将 $i$ 加入队尾。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $\textit{prices}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumCoins(self, prices: List[int]) -> int:
        n = len(prices)
        q = deque()
        for i in range(n, 0, -1):
            while q and q[0] > i * 2 + 1:
                q.popleft()
            if i <= (n - 1) // 2:
                prices[i - 1] += prices[q[0] - 1]
            while q and prices[q[-1] - 1] >= prices[i - 1]:
                q.pop()
            q.append(i)
        return prices[0]
```

#### Java

```java
class Solution {
    public int minimumCoins(int[] prices) {
        int n = prices.length;
        Deque<Integer> q = new ArrayDeque<>();
        for (int i = n; i > 0; --i) {
            while (!q.isEmpty() && q.peek() > i * 2 + 1) {
                q.poll();
            }
            if (i <= (n - 1) / 2) {
                prices[i - 1] += prices[q.peek() - 1];
            }
            while (!q.isEmpty() && prices[q.peekLast() - 1] >= prices[i - 1]) {
                q.pollLast();
            }
            q.offer(i);
        }
        return prices[0];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        int n = prices.size();
        deque<int> q;
        for (int i = n; i; --i) {
            while (q.size() && q.front() > i * 2 + 1) {
                q.pop_front();
            }
            if (i <= (n - 1) / 2) {
                prices[i - 1] += prices[q.front() - 1];
            }
            while (q.size() && prices[q.back() - 1] >= prices[i - 1]) {
                q.pop_back();
            }
            q.push_back(i);
        }
        return prices[0];
    }
};
```

#### Go

```go
func minimumCoins(prices []int) int {
	n := len(prices)
	q := Deque{}
	for i := n; i > 0; i-- {
		for q.Size() > 0 && q.Front() > i*2+1 {
			q.PopFront()
		}
		if i <= (n-1)/2 {
			prices[i-1] += prices[q.Front()-1]
		}
		for q.Size() > 0 && prices[q.Back()-1] >= prices[i-1] {
			q.PopBack()
		}
		q.PushBack(i)
	}
	return prices[0]
}

// template
type Deque struct{ l, r []int }

func (q Deque) Empty() bool {
	return len(q.l) == 0 && len(q.r) == 0
}

func (q Deque) Size() int {
	return len(q.l) + len(q.r)
}

func (q *Deque) PushFront(v int) {
	q.l = append(q.l, v)
}

func (q *Deque) PushBack(v int) {
	q.r = append(q.r, v)
}

func (q *Deque) PopFront() (v int) {
	if len(q.l) > 0 {
		q.l, v = q.l[:len(q.l)-1], q.l[len(q.l)-1]
	} else {
		v, q.r = q.r[0], q.r[1:]
	}
	return
}

func (q *Deque) PopBack() (v int) {
	if len(q.r) > 0 {
		q.r, v = q.r[:len(q.r)-1], q.r[len(q.r)-1]
	} else {
		v, q.l = q.l[0], q.l[1:]
	}
	return
}

func (q Deque) Front() int {
	if len(q.l) > 0 {
		return q.l[len(q.l)-1]
	}
	return q.r[0]
}

func (q Deque) Back() int {
	if len(q.r) > 0 {
		return q.r[len(q.r)-1]
	}
	return q.l[0]
}

func (q Deque) Get(i int) int {
	if i < len(q.l) {
		return q.l[len(q.l)-1-i]
	}
	return q.r[i-len(q.l)]
}
```

#### TypeScript

```ts
function minimumCoins(prices: number[]): number {
    const n = prices.length;
    const q = new Deque<number>();
    for (let i = n; i; --i) {
        while (q.getSize() && q.frontValue()! > i * 2 + 1) {
            q.popFront();
        }
        if (i <= (n - 1) >> 1) {
            prices[i - 1] += prices[q.frontValue()! - 1];
        }
        while (q.getSize() && prices[q.backValue()! - 1] >= prices[i - 1]) {
            q.popBack();
        }
        q.pushBack(i);
    }
    return prices[0];
}

class Node<T> {
    value: T;
    next: Node<T> | null;
    prev: Node<T> | null;

    constructor(value: T) {
        this.value = value;
        this.next = null;
        this.prev = null;
    }
}

class Deque<T> {
    private front: Node<T> | null;
    private back: Node<T> | null;
    private size: number;

    constructor() {
        this.front = null;
        this.back = null;
        this.size = 0;
    }

    pushFront(val: T): void {
        const newNode = new Node(val);
        if (this.isEmpty()) {
            this.front = newNode;
            this.back = newNode;
        } else {
            newNode.next = this.front;
            this.front!.prev = newNode;
            this.front = newNode;
        }
        this.size++;
    }

    pushBack(val: T): void {
        const newNode = new Node(val);
        if (this.isEmpty()) {
            this.front = newNode;
            this.back = newNode;
        } else {
            newNode.prev = this.back;
            this.back!.next = newNode;
            this.back = newNode;
        }
        this.size++;
    }

    popFront(): T | undefined {
        if (this.isEmpty()) {
            return undefined;
        }
        const value = this.front!.value;
        this.front = this.front!.next;
        if (this.front !== null) {
            this.front.prev = null;
        } else {
            this.back = null;
        }
        this.size--;
        return value;
    }

    popBack(): T | undefined {
        if (this.isEmpty()) {
            return undefined;
        }
        const value = this.back!.value;
        this.back = this.back!.prev;
        if (this.back !== null) {
            this.back.next = null;
        } else {
            this.front = null;
        }
        this.size--;
        return value;
    }

    frontValue(): T | undefined {
        return this.front?.value;
    }

    backValue(): T | undefined {
        return this.back?.value;
    }

    getSize(): number {
        return this.size;
    }

    isEmpty(): boolean {
        return this.size === 0;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2945. 找到最大非递减数组的长度](https://leetcode.cn/problems/find-maximum-non-decreasing-array-length){#2945}

{{< tabs "2945" >}}

{{% tab "python" %}}
```python
class Solution:
    def findMaximumLength(self, nums: List[int]) -> int:
        n = len(nums)
        s = list(accumulate(nums, initial=0))
        f = [0] * (n + 1)
        pre = [0] * (n + 2)
        for i in range(1, n + 1):
            pre[i] = max(pre[i], pre[i - 1])
            f[i] = f[pre[i]] + 1
            j = bisect_left(s, s[i] * 2 - s[pre[i]])
            pre[j] = i
        return f[n]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int findMaximumLength(int[] nums) {
        int n = nums.length;
        long[] s = new long[n + 1];
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + nums[i];
        }
        int[] f = new int[n + 1];
        int[] pre = new int[n + 2];
        for (int i = 1; i <= n; ++i) {
            pre[i] = Math.max(pre[i], pre[i - 1]);
            f[i] = f[pre[i]] + 1;
            int j = Arrays.binarySearch(s, s[i] * 2 - s[pre[i]]);
            pre[j < 0 ? -j - 1 : j] = i;
        }
        return f[n];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int findMaximumLength(vector<int>& nums) {
        int n = nums.size();
        int f[n + 1];
        int pre[n + 2];
        long long s[n + 1];
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + nums[i];
        }
        memset(f, 0, sizeof(f));
        memset(pre, 0, sizeof(pre));
        for (int i = 1; i <= n; ++i) {
            pre[i] = max(pre[i], pre[i - 1]);
            f[i] = f[pre[i]] + 1;
            int j = lower_bound(s, s + n + 1, s[i] * 2 - s[pre[i]]) - s;
            pre[j] = i;
        }
        return f[n];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findMaximumLength(nums []int) int {
	n := len(nums)
	f := make([]int, n+1)
	pre := make([]int, n+2)
	s := make([]int, n+1)
	for i, x := range nums {
		s[i+1] = s[i] + x
	}
	for i := 1; i <= n; i++ {
		pre[i] = max(pre[i], pre[i-1])
		f[i] = f[pre[i]] + 1
		j := sort.SearchInts(s, s[i]*2-s[pre[i]])
		pre[j] = max(pre[j], i)
	}
	return f[n]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findMaximumLength(nums: number[]): number {
    const n = nums.length;
    const f: number[] = Array(n + 1).fill(0);
    const pre: number[] = Array(n + 2).fill(0);
    const s: number[] = Array(n + 1).fill(0);
    for (let i = 1; i <= n; ++i) {
        s[i] = s[i - 1] + nums[i - 1];
    }
    const search = (nums: number[], x: number): number => {
        let [l, r] = [0, nums.length];
        while (l < r) {
            const mid = (l + r) >> 1;
            if (nums[mid] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    };
    for (let i = 1; i <= n; ++i) {
        pre[i] = Math.max(pre[i], pre[i - 1]);
        f[i] = f[pre[i]] + 1;
        const j = search(s, s[i] * 2 - s[pre[i]]);
        pre[j] = i;
    }
    return f[n];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>nums</code>&nbsp;。</p>

<p>你可以执行任意次操作。每次操作中，你需要选择一个 <strong>子数组</strong>&nbsp;，并将这个子数组用它所包含元素的 <strong>和</strong>&nbsp;替换。比方说，给定数组是&nbsp;<code>[1,3,5,6]</code>&nbsp;，你可以选择子数组&nbsp;<code>[3,5]</code>&nbsp;，用子数组的和 <code>8</code>&nbsp;替换掉子数组，然后数组会变为&nbsp;<code>[1,8,6]</code>&nbsp;。</p>

<p>请你返回执行任意次操作以后，可以得到的 <strong>最长非递减</strong>&nbsp;数组的长度。</p>

<p><strong>子数组</strong>&nbsp;指的是一个数组中一段连续 <strong>非空</strong>&nbsp;的元素序列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [5,2,2]
<b>输出：</b>1
<strong>解释：</strong>这个长度为 3 的数组不是非递减的。
我们有 2 种方案使数组长度为 2 。
第一种，选择子数组 [2,2] ，对数组执行操作后得到 [5,4] 。
第二种，选择子数组 [5,2] ，对数组执行操作后得到 [7,2] 。
这两种方案中，数组最后都不是 <strong>非递减</strong>&nbsp;的，所以不是可行的答案。
如果我们选择子数组 [5,2,2] ，并将它替换为 [9] ，数组变成非递减的。
所以答案为 1 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [1,2,3,4]
<b>输出：</b>4
<b>解释：</b>数组已经是非递减的。所以答案为 4 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>nums = [4,3,2,6]
<b>输出：</b>3
<b>解释：</b>将 [3,2] 替换为 [5] ，得到数组 [4,5,6] ，它是非递减的。
最大可能的答案为 3 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
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
    def findMaximumLength(self, nums: List[int]) -> int:
        n = len(nums)
        s = list(accumulate(nums, initial=0))
        f = [0] * (n + 1)
        pre = [0] * (n + 2)
        for i in range(1, n + 1):
            pre[i] = max(pre[i], pre[i - 1])
            f[i] = f[pre[i]] + 1
            j = bisect_left(s, s[i] * 2 - s[pre[i]])
            pre[j] = i
        return f[n]
```

#### Java

```java
class Solution {
    public int findMaximumLength(int[] nums) {
        int n = nums.length;
        long[] s = new long[n + 1];
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + nums[i];
        }
        int[] f = new int[n + 1];
        int[] pre = new int[n + 2];
        for (int i = 1; i <= n; ++i) {
            pre[i] = Math.max(pre[i], pre[i - 1]);
            f[i] = f[pre[i]] + 1;
            int j = Arrays.binarySearch(s, s[i] * 2 - s[pre[i]]);
            pre[j < 0 ? -j - 1 : j] = i;
        }
        return f[n];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int findMaximumLength(vector<int>& nums) {
        int n = nums.size();
        int f[n + 1];
        int pre[n + 2];
        long long s[n + 1];
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + nums[i];
        }
        memset(f, 0, sizeof(f));
        memset(pre, 0, sizeof(pre));
        for (int i = 1; i <= n; ++i) {
            pre[i] = max(pre[i], pre[i - 1]);
            f[i] = f[pre[i]] + 1;
            int j = lower_bound(s, s + n + 1, s[i] * 2 - s[pre[i]]) - s;
            pre[j] = i;
        }
        return f[n];
    }
};
```

#### Go

```go
func findMaximumLength(nums []int) int {
	n := len(nums)
	f := make([]int, n+1)
	pre := make([]int, n+2)
	s := make([]int, n+1)
	for i, x := range nums {
		s[i+1] = s[i] + x
	}
	for i := 1; i <= n; i++ {
		pre[i] = max(pre[i], pre[i-1])
		f[i] = f[pre[i]] + 1
		j := sort.SearchInts(s, s[i]*2-s[pre[i]])
		pre[j] = max(pre[j], i)
	}
	return f[n]
}
```

#### TypeScript

```ts
function findMaximumLength(nums: number[]): number {
    const n = nums.length;
    const f: number[] = Array(n + 1).fill(0);
    const pre: number[] = Array(n + 2).fill(0);
    const s: number[] = Array(n + 1).fill(0);
    for (let i = 1; i <= n; ++i) {
        s[i] = s[i - 1] + nums[i - 1];
    }
    const search = (nums: number[], x: number): number => {
        let [l, r] = [0, nums.length];
        while (l < r) {
            const mid = (l + r) >> 1;
            if (nums[mid] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    };
    for (let i = 1; i <= n; ++i) {
        pre[i] = Math.max(pre[i], pre[i - 1]);
        f[i] = f[pre[i]] + 1;
        const j = search(s, s[i] * 2 - s[pre[i]]);
        pre[j] = i;
    }
    return f[n];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2946. 循环移位后的矩阵相似检查](https://leetcode.cn/problems/matrix-similarity-after-cyclic-shifts){#2946}

{{< tabs "2946" >}}

{{% tab "python" %}}
```python
class Solution:
    def areSimilar(self, mat: List[List[int]], k: int) -> bool:
        n = len(mat[0])
        for i, row in enumerate(mat):
            for j, x in enumerate(row):
                if i % 2 == 1 and x != mat[i][(j + k) % n]:
                    return False
                if i % 2 == 0 and x != mat[i][(j - k + n) % n]:
                    return False
        return True
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean areSimilar(int[][] mat, int k) {
        int m = mat.length, n = mat[0].length;
        k %= n;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i % 2 == 1 && mat[i][j] != mat[i][(j + k) % n]) {
                    return false;
                }
                if (i % 2 == 0 && mat[i][j] != mat[i][(j - k + n) % n]) {
                    return false;
                }
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
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        k %= n;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i % 2 == 1 && mat[i][j] != mat[i][(j + k) % n]) {
                    return false;
                }
                if (i % 2 == 0 && mat[i][j] != mat[i][(j - k + n) % n]) {
                    return false;
                }
            }
        }
        return true;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func areSimilar(mat [][]int, k int) bool {
	n := len(mat[0])
	k %= n
	for i, row := range mat {
		for j, x := range row {
			if i%2 == 1 && x != mat[i][(j+k)%n] {
				return false
			}
			if i%2 == 0 && x != mat[i][(j-k+n)%n] {
				return false
			}
		}
	}
	return true
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function areSimilar(mat: number[][], k: number): boolean {
    const m = mat.length;
    const n = mat[0].length;
    k %= n;
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            if (i % 2 === 1 && mat[i][j] !== mat[i][(j + k) % n]) {
                return false;
            }
            if (i % 2 === 0 && mat[i][j] !== mat[i][(j - k + n) % n]) {
                return false;
            }
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

<p>给你一个<strong>下标从 0 开始</strong>且大小为 <code>m x n</code> 的整数矩阵 <code>mat</code> 和一个整数 <code>k</code> 。请你将矩阵中的<strong> 奇数</strong> 行循环 <strong>右</strong> 移 <code>k</code> 次，<strong>偶数</strong> 行循环 <strong>左</strong> 移 <code>k</code> 次。</p>

<p>如果初始矩阵和最终矩阵完全相同，则返回 <code>true</code> ，否则返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>mat = [[1,2,1,2],[5,5,5,5],[6,3,6,3]], k = 2
<strong>输出：</strong>true
<strong>解释：</strong>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2900-2999/2946.Matrix%20Similarity%20After%20Cyclic%20Shifts/images/similarmatrix.png" style="width: 500px; height: 117px;" />

初始矩阵如图一所示。
图二表示对奇数行右移一次且对偶数行左移一次后的矩阵状态。
图三是经过两次循环移位后的最终矩阵状态，与初始矩阵相同。
因此，返回 true 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>mat = [[2,2],[2,2]], k = 3
<strong>输出：</strong>true
<strong>解释：</strong>由于矩阵中的所有值都相等，即使进行循环移位，矩阵仍然保持不变。因此，返回 true 。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>mat = [[1,2]], k = 1
<strong>输出：</strong>false
<strong>解释：</strong>循环移位一次后，mat = [[2,1]]，与初始矩阵不相等。因此，返回 false 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= mat.length &lt;= 25</code></li>
	<li><code>1 &lt;= mat[i].length &lt;= 25</code></li>
	<li><code>1 &lt;= mat[i][j] &lt;= 25</code></li>
	<li><code>1 &lt;= k &lt;= 50</code></li>
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
    def areSimilar(self, mat: List[List[int]], k: int) -> bool:
        n = len(mat[0])
        for i, row in enumerate(mat):
            for j, x in enumerate(row):
                if i % 2 == 1 and x != mat[i][(j + k) % n]:
                    return False
                if i % 2 == 0 and x != mat[i][(j - k + n) % n]:
                    return False
        return True
```

#### Java

```java
class Solution {
    public boolean areSimilar(int[][] mat, int k) {
        int m = mat.length, n = mat[0].length;
        k %= n;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i % 2 == 1 && mat[i][j] != mat[i][(j + k) % n]) {
                    return false;
                }
                if (i % 2 == 0 && mat[i][j] != mat[i][(j - k + n) % n]) {
                    return false;
                }
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
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        k %= n;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i % 2 == 1 && mat[i][j] != mat[i][(j + k) % n]) {
                    return false;
                }
                if (i % 2 == 0 && mat[i][j] != mat[i][(j - k + n) % n]) {
                    return false;
                }
            }
        }
        return true;
    }
};
```

#### Go

```go
func areSimilar(mat [][]int, k int) bool {
	n := len(mat[0])
	k %= n
	for i, row := range mat {
		for j, x := range row {
			if i%2 == 1 && x != mat[i][(j+k)%n] {
				return false
			}
			if i%2 == 0 && x != mat[i][(j-k+n)%n] {
				return false
			}
		}
	}
	return true
}
```

#### TypeScript

```ts
function areSimilar(mat: number[][], k: number): boolean {
    const m = mat.length;
    const n = mat[0].length;
    k %= n;
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            if (i % 2 === 1 && mat[i][j] !== mat[i][(j + k) % n]) {
                return false;
            }
            if (i % 2 === 0 && mat[i][j] !== mat[i][(j - k + n) % n]) {
                return false;
            }
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

# [2947. 统计美丽子字符串 I](https://leetcode.cn/problems/count-beautiful-substrings-i){#2947}

{{< tabs "2947" >}}

{{% tab "python" %}}
```python
class Solution:
    def beautifulSubstrings(self, s: str, k: int) -> int:
        n = len(s)
        vs = set("aeiou")
        ans = 0
        for i in range(n):
            vowels = 0
            for j in range(i, n):
                vowels += s[j] in vs
                consonants = j - i + 1 - vowels
                if vowels == consonants and vowels * consonants % k == 0:
                    ans += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int beautifulSubstrings(String s, int k) {
        int n = s.length();
        int[] vs = new int[26];
        for (char c : "aeiou".toCharArray()) {
            vs[c - 'a'] = 1;
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int vowels = 0;
            for (int j = i; j < n; ++j) {
                vowels += vs[s.charAt(j) - 'a'];
                int consonants = j - i + 1 - vowels;
                if (vowels == consonants && vowels * consonants % k == 0) {
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
    int beautifulSubstrings(string s, int k) {
        int n = s.size();
        int vs[26]{};
        string t = "aeiou";
        for (char c : t) {
            vs[c - 'a'] = 1;
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int vowels = 0;
            for (int j = i; j < n; ++j) {
                vowels += vs[s[j] - 'a'];
                int consonants = j - i + 1 - vowels;
                if (vowels == consonants && vowels * consonants % k == 0) {
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
func beautifulSubstrings(s string, k int) (ans int) {
	n := len(s)
	vs := [26]int{}
	for _, c := range "aeiou" {
		vs[c-'a'] = 1
	}
	for i := 0; i < n; i++ {
		vowels := 0
		for j := i; j < n; j++ {
			vowels += vs[s[j]-'a']
			consonants := j - i + 1 - vowels
			if vowels == consonants && vowels*consonants%k == 0 {
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
function beautifulSubstrings(s: string, k: number): number {
    const n = s.length;
    const vs: number[] = Array(26).fill(0);
    for (const c of 'aeiou') {
        vs[c.charCodeAt(0) - 'a'.charCodeAt(0)] = 1;
    }
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        let vowels = 0;
        for (let j = i; j < n; ++j) {
            vowels += vs[s.charCodeAt(j) - 'a'.charCodeAt(0)];
            const consonants = j - i + 1 - vowels;
            if (vowels === consonants && (vowels * consonants) % k === 0) {
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

<p>给你一个字符串 <code>s</code> 和一个正整数 <code>k</code> 。</p>

<p>用 <code>vowels</code> 和 <code>consonants</code> 分别表示字符串中元音字母和辅音字母的数量。</p>

<p>如果某个字符串满足以下条件，则称其为 <strong>美丽字符串</strong> ：</p>

<ul>
	<li><code>vowels == consonants</code>，即元音字母和辅音字母的数量相等。</li>
	<li><code>(vowels * consonants) % k == 0</code>，即元音字母和辅音字母的数量的乘积能被 <code>k</code> 整除。</li>
</ul>

<p>返回字符串 <code>s</code> 中 <strong>非空美丽子字符串</strong> 的数量。</p>

<p>子字符串是字符串中的一个连续字符序列。</p>

<p>英语中的<strong> 元音字母 </strong>为 <code>'a'</code>、<code>'e'</code>、<code>'i'</code>、<code>'o'</code> 和 <code>'u'</code> 。</p>

<p>英语中的<strong> 辅音字母 </strong>为除了元音字母之外的所有字母。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "baeyh", k = 2
<strong>输出：</strong>2
<strong>解释：</strong>字符串 s 中有 2 个美丽子字符串。
- 子字符串 "b<em><strong>aeyh</strong></em>"，vowels = 2（["a","e"]），consonants = 2（["y","h"]）。
可以看出字符串 "aeyh" 是美丽字符串，因为 vowels == consonants 且 vowels * consonants % k == 0 。
- 子字符串 "<em><strong>baey</strong></em>h"，vowels = 2（["a","e"]），consonants = 2（["b","y"]）。
可以看出字符串 "baey" 是美丽字符串，因为 vowels == consonants 且 vowels * consonants % k == 0 。
可以证明字符串 s 中只有 2 个美丽子字符串。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "abba", k = 1
<strong>输出：</strong>3
<strong>解释：</strong>字符串 s 中有 3 个美丽子字符串。
- 子字符串 "<strong><em>ab</em></strong>ba"，vowels = 1（["a"]），consonants = 1（["b"]）。
- 子字符串 "ab<strong><em>ba</em></strong>"，vowels = 1（["a"]），consonants = 1（["b"]）。
- 子字符串 "<em><strong>abba</strong></em>"，vowels = 2（["a","a"]），consonants = 2（["b","b"]）。
可以证明字符串 s 中只有 3 个美丽子字符串。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "bcdf", k = 1
<strong>输出：</strong>0
<strong>解释：</strong>字符串 s 中没有美丽子字符串。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>1 &lt;= k &lt;= 1000</code></li>
	<li><code>s</code> 仅由小写英文字母组成。</li>
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
    def beautifulSubstrings(self, s: str, k: int) -> int:
        n = len(s)
        vs = set("aeiou")
        ans = 0
        for i in range(n):
            vowels = 0
            for j in range(i, n):
                vowels += s[j] in vs
                consonants = j - i + 1 - vowels
                if vowels == consonants and vowels * consonants % k == 0:
                    ans += 1
        return ans
```

#### Java

```java
class Solution {
    public int beautifulSubstrings(String s, int k) {
        int n = s.length();
        int[] vs = new int[26];
        for (char c : "aeiou".toCharArray()) {
            vs[c - 'a'] = 1;
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int vowels = 0;
            for (int j = i; j < n; ++j) {
                vowels += vs[s.charAt(j) - 'a'];
                int consonants = j - i + 1 - vowels;
                if (vowels == consonants && vowels * consonants % k == 0) {
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
    int beautifulSubstrings(string s, int k) {
        int n = s.size();
        int vs[26]{};
        string t = "aeiou";
        for (char c : t) {
            vs[c - 'a'] = 1;
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int vowels = 0;
            for (int j = i; j < n; ++j) {
                vowels += vs[s[j] - 'a'];
                int consonants = j - i + 1 - vowels;
                if (vowels == consonants && vowels * consonants % k == 0) {
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
func beautifulSubstrings(s string, k int) (ans int) {
	n := len(s)
	vs := [26]int{}
	for _, c := range "aeiou" {
		vs[c-'a'] = 1
	}
	for i := 0; i < n; i++ {
		vowels := 0
		for j := i; j < n; j++ {
			vowels += vs[s[j]-'a']
			consonants := j - i + 1 - vowels
			if vowels == consonants && vowels*consonants%k == 0 {
				ans++
			}
		}
	}
	return
}
```

#### TypeScript

```ts
function beautifulSubstrings(s: string, k: number): number {
    const n = s.length;
    const vs: number[] = Array(26).fill(0);
    for (const c of 'aeiou') {
        vs[c.charCodeAt(0) - 'a'.charCodeAt(0)] = 1;
    }
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        let vowels = 0;
        for (let j = i; j < n; ++j) {
            vowels += vs[s.charCodeAt(j) - 'a'.charCodeAt(0)];
            const consonants = j - i + 1 - vowels;
            if (vowels === consonants && (vowels * consonants) % k === 0) {
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

# [2948. 交换得到字典序最小的数组](https://leetcode.cn/problems/make-lexicographically-smallest-array-by-swapping-elements){#2948}

{{< tabs "2948" >}}

{{% tab "python" %}}
```python
class Solution:
    def lexicographicallySmallestArray(self, nums: List[int], limit: int) -> List[int]:
        n = len(nums)
        arr = sorted(zip(nums, range(n)))
        ans = [0] * n
        i = 0
        while i < n:
            j = i + 1
            while j < n and arr[j][0] - arr[j - 1][0] <= limit:
                j += 1
            idx = sorted(k for _, k in arr[i:j])
            for k, (x, _) in zip(idx, arr[i:j]):
                ans[k] = x
            i = j
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] lexicographicallySmallestArray(int[] nums, int limit) {
        int n = nums.length;
        Integer[] idx = new Integer[n];
        Arrays.setAll(idx, i -> i);
        Arrays.sort(idx, (i, j) -> nums[i] - nums[j]);
        int[] ans = new int[n];
        for (int i = 0; i < n;) {
            int j = i + 1;
            while (j < n && nums[idx[j]] - nums[idx[j - 1]] <= limit) {
                ++j;
            }
            Integer[] t = Arrays.copyOfRange(idx, i, j);
            Arrays.sort(t, (x, y) -> x - y);
            for (int k = i; k < j; ++k) {
                ans[t[k - i]] = nums[idx[k]];
            }
            i = j;
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
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int i, int j) {
            return nums[i] < nums[j];
        });
        vector<int> ans(n);
        for (int i = 0; i < n;) {
            int j = i + 1;
            while (j < n && nums[idx[j]] - nums[idx[j - 1]] <= limit) {
                ++j;
            }
            vector<int> t(idx.begin() + i, idx.begin() + j);
            sort(t.begin(), t.end());
            for (int k = i; k < j; ++k) {
                ans[t[k - i]] = nums[idx[k]];
            }
            i = j;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func lexicographicallySmallestArray(nums []int, limit int) []int {
	n := len(nums)
	idx := make([]int, n)
	for i := range idx {
		idx[i] = i
	}
	slices.SortFunc(idx, func(i, j int) int { return nums[i] - nums[j] })
	ans := make([]int, n)
	for i := 0; i < n; {
		j := i + 1
		for j < n && nums[idx[j]]-nums[idx[j-1]] <= limit {
			j++
		}
		t := slices.Clone(idx[i:j])
		slices.Sort(t)
		for k := i; k < j; k++ {
			ans[t[k-i]] = nums[idx[k]]
		}
		i = j
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function lexicographicallySmallestArray(nums: number[], limit: number): number[] {
    const n: number = nums.length;
    const idx: number[] = Array.from({ length: n }, (_, i) => i);
    idx.sort((i, j) => nums[i] - nums[j]);
    const ans: number[] = Array(n).fill(0);
    for (let i = 0; i < n; ) {
        let j = i + 1;
        while (j < n && nums[idx[j]] - nums[idx[j - 1]] <= limit) {
            j++;
        }
        const t: number[] = idx.slice(i, j).sort((a, b) => a - b);
        for (let k: number = i; k < j; k++) {
            ans[t[k - i]] = nums[idx[k]];
        }
        i = j;
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

<p>给你一个下标从 <strong>0 </strong>开始的 <strong>正整数</strong> 数组 <code>nums</code> 和一个 <strong>正整数</strong> <code>limit</code> 。</p>

<p>在一次操作中，你可以选择任意两个下标 <code>i</code> 和 <code>j</code>，<strong>如果</strong> 满足 <code>|nums[i] - nums[j]| &lt;= limit</code> ，则交换 <code>nums[i]</code> 和 <code>nums[j]</code> 。</p>

<p>返回执行任意次操作后能得到的 <strong>字典序最小的数组</strong><em> </em>。</p>

<p>如果在数组 <code>a</code> 和数组 <code>b</code> 第一个不同的位置上，数组 <code>a</code> 中的对应元素比数组 <code>b</code> 中的对应元素的字典序更小，则认为数组 <code>a</code> 就比数组 <code>b</code> 字典序更小。例如，数组 <code>[2,10,3]</code> 比数组 <code>[10,2,3]</code> 字典序更小，下标 <code>0</code> 处是两个数组第一个不同的位置，且 <code>2 &lt; 10</code> 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,5,3,9,8], limit = 2
<strong>输出：</strong>[1,3,5,8,9]
<strong>解释：</strong>执行 2 次操作：
- 交换 nums[1] 和 nums[2] 。数组变为 [1,3,5,9,8] 。
- 交换 nums[3] 和 nums[4] 。数组变为 [1,3,5,8,9] 。
即便执行更多次操作，也无法得到字典序更小的数组。
注意，执行不同的操作也可能会得到相同的结果。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,7,6,18,2,1], limit = 3
<strong>输出：</strong>[1,6,7,18,1,2]
<strong>解释：</strong>执行 3 次操作：
- 交换 nums[1] 和 nums[2] 。数组变为 [1,6,7,18,2,1] 。
- 交换 nums[0] 和 nums[4] 。数组变为 [2,6,7,18,1,1] 。
- 交换 nums[0] 和 nums[5] 。数组变为 [1,6,7,18,1,2] 。
即便执行更多次操作，也无法得到字典序更小的数组。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,7,28,19,10], limit = 3
<strong>输出：</strong>[1,7,28,19,10]
<strong>解释：</strong>[1,7,28,19,10] 是字典序最小的数组，因为不管怎么选择下标都无法执行操作。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= limit &lt;= 10<sup>9</sup></code></li>
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
    def lexicographicallySmallestArray(self, nums: List[int], limit: int) -> List[int]:
        n = len(nums)
        arr = sorted(zip(nums, range(n)))
        ans = [0] * n
        i = 0
        while i < n:
            j = i + 1
            while j < n and arr[j][0] - arr[j - 1][0] <= limit:
                j += 1
            idx = sorted(k for _, k in arr[i:j])
            for k, (x, _) in zip(idx, arr[i:j]):
                ans[k] = x
            i = j
        return ans
```

#### Java

```java
class Solution {
    public int[] lexicographicallySmallestArray(int[] nums, int limit) {
        int n = nums.length;
        Integer[] idx = new Integer[n];
        Arrays.setAll(idx, i -> i);
        Arrays.sort(idx, (i, j) -> nums[i] - nums[j]);
        int[] ans = new int[n];
        for (int i = 0; i < n;) {
            int j = i + 1;
            while (j < n && nums[idx[j]] - nums[idx[j - 1]] <= limit) {
                ++j;
            }
            Integer[] t = Arrays.copyOfRange(idx, i, j);
            Arrays.sort(t, (x, y) -> x - y);
            for (int k = i; k < j; ++k) {
                ans[t[k - i]] = nums[idx[k]];
            }
            i = j;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int i, int j) {
            return nums[i] < nums[j];
        });
        vector<int> ans(n);
        for (int i = 0; i < n;) {
            int j = i + 1;
            while (j < n && nums[idx[j]] - nums[idx[j - 1]] <= limit) {
                ++j;
            }
            vector<int> t(idx.begin() + i, idx.begin() + j);
            sort(t.begin(), t.end());
            for (int k = i; k < j; ++k) {
                ans[t[k - i]] = nums[idx[k]];
            }
            i = j;
        }
        return ans;
    }
};
```

#### Go

```go
func lexicographicallySmallestArray(nums []int, limit int) []int {
	n := len(nums)
	idx := make([]int, n)
	for i := range idx {
		idx[i] = i
	}
	slices.SortFunc(idx, func(i, j int) int { return nums[i] - nums[j] })
	ans := make([]int, n)
	for i := 0; i < n; {
		j := i + 1
		for j < n && nums[idx[j]]-nums[idx[j-1]] <= limit {
			j++
		}
		t := slices.Clone(idx[i:j])
		slices.Sort(t)
		for k := i; k < j; k++ {
			ans[t[k-i]] = nums[idx[k]]
		}
		i = j
	}
	return ans
}
```

#### TypeScript

```ts
function lexicographicallySmallestArray(nums: number[], limit: number): number[] {
    const n: number = nums.length;
    const idx: number[] = Array.from({ length: n }, (_, i) => i);
    idx.sort((i, j) => nums[i] - nums[j]);
    const ans: number[] = Array(n).fill(0);
    for (let i = 0; i < n; ) {
        let j = i + 1;
        while (j < n && nums[idx[j]] - nums[idx[j - 1]] <= limit) {
            j++;
        }
        const t: number[] = idx.slice(i, j).sort((a, b) => a - b);
        for (let k: number = i; k < j; k++) {
            ans[t[k - i]] = nums[idx[k]];
        }
        i = j;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2949. 统计美丽子字符串 II](https://leetcode.cn/problems/count-beautiful-substrings-ii){#2949}

{{< tabs "2949" >}}

{{% tab "ts" %}}
```ts
function beautifulSubstrings(s: string, k: number): number {
    const l = pSqrt(k * 4);
    const n = s.length;
    let sum = n;
    let ans = 0;
    const counter = new Map();
    counter.set(((l - 1) << 17) | sum, 1);
    for (let i = 0; i < n; i++) {
        const char = s[i];
        const bit = (AEIOU_MASK >> (char.charCodeAt(0) - 'a'.charCodeAt(0))) & 1;
        sum += bit * 2 - 1; // 1 -> 1    0 -> -1
        const key = (i % l << 17) | sum;
        ans += counter.get(key) || 0; // ans += cnt[(i%k,sum)]++
        counter.set(key, (counter.get(key) ?? 0) + 1);
    }
    return ans;
}
const AEIOU_MASK = 1065233;

function pSqrt(n: number) {
    let res = 1;
    for (let i = 2; i * i <= n; i++) {
        let i2 = i * i;
        while (n % i2 == 0) {
            res *= i;
            n /= i2;
        }
        if (n % i == 0) {
            res *= i;
            n /= i;
        }
    }
    if (n > 1) {
        res *= n;
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

<p>给你一个字符串 <code>s</code> 和一个正整数 <code>k</code> 。</p>

<p>用 <code>vowels</code> 和 <code>consonants</code> 分别表示字符串中元音字母和辅音字母的数量。</p>

<p>如果某个字符串满足以下条件，则称其为 <strong>美丽字符串</strong> ：</p>

<ul>
	<li><code>vowels == consonants</code>，即元音字母和辅音字母的数量相等。</li>
	<li><code>(vowels * consonants) % k == 0</code>，即元音字母和辅音字母的数量的乘积能被 <code>k</code> 整除。</li>
</ul>

<p>返回字符串 <code>s</code> 中 <strong>非空美丽子字符串</strong> 的数量。</p>

<p>子字符串是字符串中的一个连续字符序列。</p>

<p>英语中的<strong> 元音字母 </strong>为 <code>'a'</code>、<code>'e'</code>、<code>'i'</code>、<code>'o'</code> 和 <code>'u'</code> 。</p>

<p>英语中的<strong> 辅音字母 </strong>为除了元音字母之外的所有字母。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "baeyh", k = 2
<strong>输出：</strong>2
<strong>解释：</strong>字符串 s 中有 2 个美丽子字符串。
- 子字符串 "b<em><strong>aeyh</strong></em>"，vowels = 2（["a","e"]），consonants = 2（["y","h"]）。
可以看出字符串 "aeyh" 是美丽字符串，因为 vowels == consonants 且 vowels * consonants % k == 0 。
- 子字符串 "<em><strong>baey</strong></em>h"，vowels = 2（["a","e"]），consonants = 2（["b","y"]）。
可以看出字符串 "baey" 是美丽字符串，因为 vowels == consonants 且 vowels * consonants % k == 0 。
可以证明字符串 s 中只有 2 个美丽子字符串。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "abba", k = 1
<strong>输出：</strong>3
<strong>解释：</strong>字符串 s 中有 3 个美丽子字符串。
- 子字符串 "<strong><em>ab</em></strong>ba"，vowels = 1（["a"]），consonants = 1（["b"]）。
- 子字符串 "ab<strong><em>ba</em></strong>"，vowels = 1（["a"]），consonants = 1（["b"]）。
- 子字符串 "<em><strong>abba</strong></em>"，vowels = 2（["a","a"]），consonants = 2（["b","b"]）。
可以证明字符串 s 中只有 3 个美丽子字符串。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "bcdf", k = 1
<strong>输出：</strong>0
<strong>解释：</strong>字符串 s 中没有美丽子字符串。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= k &lt;= 1000</code></li>
	<li><code>s</code> 仅由小写英文字母组成。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前缀和 + 哈希表 + 分解质因子

<!-- tabs:start -->

#### TypeScript

```ts
function beautifulSubstrings(s: string, k: number): number {
    const l = pSqrt(k * 4);
    const n = s.length;
    let sum = n;
    let ans = 0;
    const counter = new Map();
    counter.set(((l - 1) << 17) | sum, 1);
    for (let i = 0; i < n; i++) {
        const char = s[i];
        const bit = (AEIOU_MASK >> (char.charCodeAt(0) - 'a'.charCodeAt(0))) & 1;
        sum += bit * 2 - 1; // 1 -> 1    0 -> -1
        const key = (i % l << 17) | sum;
        ans += counter.get(key) || 0; // ans += cnt[(i%k,sum)]++
        counter.set(key, (counter.get(key) ?? 0) + 1);
    }
    return ans;
}
const AEIOU_MASK = 1065233;

function pSqrt(n: number) {
    let res = 1;
    for (let i = 2; i * i <= n; i++) {
        let i2 = i * i;
        while (n % i2 == 0) {
            res *= i;
            n /= i2;
        }
        if (n % i == 0) {
            res *= i;
            n /= i;
        }
    }
    if (n > 1) {
        res *= n;
    }
    return res;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
