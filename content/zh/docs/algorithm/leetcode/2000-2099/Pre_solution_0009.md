---
title: "2080_区间内查询数字的频率"
date: 2025-10-08T18:38:57+08:00
weight: 9
tags: [二分查找, 前缀和, 动态规划, 哈希表, 字符串, 排序, 数学, 数据库, 数组, 枚举, 矩阵, 线段树, 计数, 设计, 贪心]
---

{{< markmap >}}
### [2080_区间内查询数字的频率](#2080)
#### [设计](#2080)
#### [线段树](#2080)
#### [数组](#2080)
#### [哈希表](#2080)
#### [二分查找](#2080)
### [2081_k 镜像数字的和](#2081)
#### [数学](#2081)
#### [枚举](#2081)
### [2082_富有客户的数量 🔒](#2082)
#### [数据库](#2082)
### [2083_求以相同字母开头和结尾的子串总数 🔒](#2083)
#### [哈希表](#2083)
#### [数学](#2083)
#### [字符串](#2083)
#### [计数](#2083)
#### [前缀和](#2083)
### [2084_为订单类型为 0 的客户删除类型为 1 的订单 🔒](#2084)
#### [数据库](#2084)
### [2085_统计出现过一次的公共字符串](#2085)
#### [数组](#2085)
#### [哈希表](#2085)
#### [字符串](#2085)
#### [计数](#2085)
### [2086_喂食仓鼠的最小食物桶数](#2086)
#### [贪心](#2086)
#### [字符串](#2086)
#### [动态规划](#2086)
### [2087_网格图中机器人回家的最小代价](#2087)
#### [贪心](#2087)
#### [数组](#2087)
### [2088_统计农场中肥沃金字塔的数目](#2088)
#### [数组](#2088)
#### [动态规划](#2088)
#### [矩阵](#2088)
### [2089_找出数组排序后的目标下标](#2089)
#### [数组](#2089)
#### [二分查找](#2089)
#### [排序](#2089)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2080_区间内查询数字的频率
___
#### 设计
___
#### 线段树
___
#### 数组
___
#### 哈希表
___
#### 二分查找
---
### 2081_k 镜像数字的和
___
#### 数学
___
#### 枚举
---
### 2082_富有客户的数量 🔒
___
#### 数据库
---
### 2083_求以相同字母开头和结尾的子串总数 🔒
___
#### 哈希表
___
#### 数学
___
#### 字符串
___
#### 计数
___
#### 前缀和
---
### 2084_为订单类型为 0 的客户删除类型为 1 的订单 🔒
___
#### 数据库
---
### 2085_统计出现过一次的公共字符串
___
#### 数组
___
#### 哈希表
___
#### 字符串
___
#### 计数
---
### 2086_喂食仓鼠的最小食物桶数
___
#### 贪心
___
#### 字符串
___
#### 动态规划
---
### 2087_网格图中机器人回家的最小代价
___
#### 贪心
___
#### 数组
---
### 2088_统计农场中肥沃金字塔的数目
___
#### 数组
___
#### 动态规划
___
#### 矩阵
---
### 2089_找出数组排序后的目标下标
___
#### 数组
___
#### 二分查找
___
#### 排序
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 前缀和 | 动态规划 |
| 哈希表 | 字符串 | 排序 |
| 数学 | 数据库 | 数组 |
| 枚举 | 矩阵 | 线段树 |
| 计数 | 设计 | 贪心 |

# [2080. 区间内查询数字的频率](https://leetcode.cn/problems/range-frequency-queries){#2080}

{{< tabs "2080" >}}

{{% tab "python" %}}
```python
class RangeFreqQuery:

    def __init__(self, arr: List[int]):
        self.g = defaultdict(list)
        for i, x in enumerate(arr):
            self.g[x].append(i)

    def query(self, left: int, right: int, value: int) -> int:
        idx = self.g[value]
        l = bisect_left(idx, left)
        r = bisect_left(idx, right + 1)
        return r - l


# Your RangeFreqQuery object will be instantiated and called as such:
# obj = RangeFreqQuery(arr)
# param_1 = obj.query(left,right,value)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class RangeFreqQuery {
    private Map<Integer, List<Integer>> g = new HashMap<>();

    public RangeFreqQuery(int[] arr) {
        for (int i = 0; i < arr.length; ++i) {
            g.computeIfAbsent(arr[i], k -> new ArrayList<>()).add(i);
        }
    }

    public int query(int left, int right, int value) {
        if (!g.containsKey(value)) {
            return 0;
        }
        var idx = g.get(value);
        int l = Collections.binarySearch(idx, left);
        l = l < 0 ? -l - 1 : l;
        int r = Collections.binarySearch(idx, right + 1);
        r = r < 0 ? -r - 1 : r;
        return r - l;
    }
}

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery obj = new RangeFreqQuery(arr);
 * int param_1 = obj.query(left,right,value);
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class RangeFreqQuery {
public:
    RangeFreqQuery(vector<int>& arr) {
        for (int i = 0; i < arr.size(); ++i) {
            g[arr[i]].push_back(i);
        }
    }

    int query(int left, int right, int value) {
        if (!g.contains(value)) {
            return 0;
        }
        auto& idx = g[value];
        auto l = lower_bound(idx.begin(), idx.end(), left);
        auto r = lower_bound(idx.begin(), idx.end(), right + 1);
        return r - l;
    }

private:
    unordered_map<int, vector<int>> g;
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type RangeFreqQuery struct {
	g map[int][]int
}

func Constructor(arr []int) RangeFreqQuery {
	g := make(map[int][]int)
	for i, v := range arr {
		g[v] = append(g[v], i)
	}
	return RangeFreqQuery{g}
}

func (this *RangeFreqQuery) Query(left int, right int, value int) int {
	if idx, ok := this.g[value]; ok {
		l := sort.SearchInts(idx, left)
		r := sort.SearchInts(idx, right+1)
		return r - l
	}
	return 0
}

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * obj := Constructor(arr);
 * param_1 := obj.Query(left,right,value);
 */
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class RangeFreqQuery {
    private g: Map<number, number[]> = new Map();

    constructor(arr: number[]) {
        for (let i = 0; i < arr.length; ++i) {
            if (!this.g.has(arr[i])) {
                this.g.set(arr[i], []);
            }
            this.g.get(arr[i])!.push(i);
        }
    }

    query(left: number, right: number, value: number): number {
        const idx = this.g.get(value);
        if (!idx) {
            return 0;
        }
        const l = _.sortedIndex(idx, left);
        const r = _.sortedIndex(idx, right + 1);
        return r - l;
    }
}

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * var obj = new RangeFreqQuery(arr)
 * var param_1 = obj.query(left,right,value)
 */
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashMap;

struct RangeFreqQuery {
    g: HashMap<i32, Vec<usize>>,
}

impl RangeFreqQuery {
    fn new(arr: Vec<i32>) -> Self {
        let mut g = HashMap::new();
        for (i, &value) in arr.iter().enumerate() {
            g.entry(value).or_insert_with(Vec::new).push(i);
        }
        RangeFreqQuery { g }
    }

    fn query(&self, left: i32, right: i32, value: i32) -> i32 {
        if let Some(idx) = self.g.get(&value) {
            let l = idx.partition_point(|&x| x < left as usize);
            let r = idx.partition_point(|&x| x <= right as usize);
            return (r - l) as i32;
        }
        0
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} arr
 */
var RangeFreqQuery = function (arr) {
    this.g = new Map();

    for (let i = 0; i < arr.length; ++i) {
        if (!this.g.has(arr[i])) {
            this.g.set(arr[i], []);
        }
        this.g.get(arr[i]).push(i);
    }
};

/**
 * @param {number} left
 * @param {number} right
 * @param {number} value
 * @return {number}
 */
RangeFreqQuery.prototype.query = function (left, right, value) {
    const idx = this.g.get(value);
    if (!idx) {
        return 0;
    }
    const l = _.sortedIndex(idx, left);
    const r = _.sortedIndex(idx, right + 1);
    return r - l;
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * var obj = new RangeFreqQuery(arr)
 * var param_1 = obj.query(left,right,value)
 */
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class RangeFreqQuery {
    private Dictionary<int, List<int>> g;

    public RangeFreqQuery(int[] arr) {
        g = new Dictionary<int, List<int>>();
        for (int i = 0; i < arr.Length; ++i) {
            if (!g.ContainsKey(arr[i])) {
                g[arr[i]] = new List<int>();
            }
            g[arr[i]].Add(i);
        }
    }

    public int Query(int left, int right, int value) {
        if (g.ContainsKey(value)) {
            var idx = g[value];
            int l = idx.BinarySearch(left);
            int r = idx.BinarySearch(right + 1);
            l = l < 0 ? -l - 1 : l;
            r = r < 0 ? -r - 1 : r;
            return r - l;
        }
        return 0;
    }
}

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery obj = new RangeFreqQuery(arr);
 * int param_1 = obj.Query(left, right, value);
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>请你设计一个数据结构，它能求出给定子数组内一个给定值的 <strong>频率</strong>&nbsp;。</p>

<p>子数组中一个值的 <strong>频率</strong>&nbsp;指的是这个子数组中这个值的出现次数。</p>

<p>请你实现&nbsp;<code>RangeFreqQuery</code>&nbsp;类：</p>

<ul>
	<li><code>RangeFreqQuery(int[] arr)</code>&nbsp;用下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>arr</code>&nbsp;构造一个类的实例。</li>
	<li><code>int query(int left, int right, int value)</code>&nbsp;返回子数组&nbsp;<code>arr[left...right]</code>&nbsp;中&nbsp;<code>value</code>&nbsp;的&nbsp;<strong>频率</strong>&nbsp;。</li>
</ul>

<p>一个 <strong>子数组</strong> 指的是数组中一段连续的元素。<code>arr[left...right]</code>&nbsp;指的是 <code>nums</code>&nbsp;中包含下标 <code>left</code>&nbsp;和 <code>right</code>&nbsp;<strong>在内</strong>&nbsp;的中间一段连续元素。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>
["RangeFreqQuery", "query", "query"]
[[[12, 33, 4, 56, 22, 2, 34, 33, 22, 12, 34, 56]], [1, 2, 4], [0, 11, 33]]
<strong>输出：</strong>
[null, 1, 2]

<strong>解释：</strong>
RangeFreqQuery rangeFreqQuery = new RangeFreqQuery([12, 33, 4, 56, 22, 2, 34, 33, 22, 12, 34, 56]);
rangeFreqQuery.query(1, 2, 4); // 返回 1 。4 在子数组 [33, 4] 中出现 1 次。
rangeFreqQuery.query(0, 11, 33); // 返回 2 。33 在整个子数组中出现 2 次。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= arr[i], value &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= left &lt;= right &lt; arr.length</code></li>
	<li>调用&nbsp;<code>query</code>&nbsp;不超过&nbsp;<code>10<sup>5</sup></code>&nbsp;次。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 二分查找

我们用一个哈希表 $g$ 来存储每个值对应的下标数组。在构造函数中，我们遍历数组 $\textit{arr}$，将每个值对应的下标加入到哈希表中。

在查询函数中，我们首先判断哈希表中是否存在给定的值。如果不存在，说明该值在数组中不存在，直接返回 $0$。否则，我们获取该值对应的下标数组 $\textit{idx}$。然后我们使用二分查找找到下标数组中第一个大于等于 $\textit{left}$ 的下标 $l$，以及第一个大于 $\textit{right}$ 的下标 $r$。最后返回 $r - l$ 即可。

时间复杂度方面，构造函数的时间复杂度为 $O(n)$，查询函数的时间复杂度为 $O(\log n)$。其中 $n$ 为数组的长度。空间复杂度为 $O(n)$。

<!-- tabs:start -->

#### Python3

```python
class RangeFreqQuery:

    def __init__(self, arr: List[int]):
        self.g = defaultdict(list)
        for i, x in enumerate(arr):
            self.g[x].append(i)

    def query(self, left: int, right: int, value: int) -> int:
        idx = self.g[value]
        l = bisect_left(idx, left)
        r = bisect_left(idx, right + 1)
        return r - l


# Your RangeFreqQuery object will be instantiated and called as such:
# obj = RangeFreqQuery(arr)
# param_1 = obj.query(left,right,value)
```

#### Java

```java
class RangeFreqQuery {
    private Map<Integer, List<Integer>> g = new HashMap<>();

    public RangeFreqQuery(int[] arr) {
        for (int i = 0; i < arr.length; ++i) {
            g.computeIfAbsent(arr[i], k -> new ArrayList<>()).add(i);
        }
    }

    public int query(int left, int right, int value) {
        if (!g.containsKey(value)) {
            return 0;
        }
        var idx = g.get(value);
        int l = Collections.binarySearch(idx, left);
        l = l < 0 ? -l - 1 : l;
        int r = Collections.binarySearch(idx, right + 1);
        r = r < 0 ? -r - 1 : r;
        return r - l;
    }
}

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery obj = new RangeFreqQuery(arr);
 * int param_1 = obj.query(left,right,value);
 */
```

#### C++

```cpp
class RangeFreqQuery {
public:
    RangeFreqQuery(vector<int>& arr) {
        for (int i = 0; i < arr.size(); ++i) {
            g[arr[i]].push_back(i);
        }
    }

    int query(int left, int right, int value) {
        if (!g.contains(value)) {
            return 0;
        }
        auto& idx = g[value];
        auto l = lower_bound(idx.begin(), idx.end(), left);
        auto r = lower_bound(idx.begin(), idx.end(), right + 1);
        return r - l;
    }

private:
    unordered_map<int, vector<int>> g;
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
```

#### Go

```go
type RangeFreqQuery struct {
	g map[int][]int
}

func Constructor(arr []int) RangeFreqQuery {
	g := make(map[int][]int)
	for i, v := range arr {
		g[v] = append(g[v], i)
	}
	return RangeFreqQuery{g}
}

func (this *RangeFreqQuery) Query(left int, right int, value int) int {
	if idx, ok := this.g[value]; ok {
		l := sort.SearchInts(idx, left)
		r := sort.SearchInts(idx, right+1)
		return r - l
	}
	return 0
}

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * obj := Constructor(arr);
 * param_1 := obj.Query(left,right,value);
 */
```

#### TypeScript

```ts
class RangeFreqQuery {
    private g: Map<number, number[]> = new Map();

    constructor(arr: number[]) {
        for (let i = 0; i < arr.length; ++i) {
            if (!this.g.has(arr[i])) {
                this.g.set(arr[i], []);
            }
            this.g.get(arr[i])!.push(i);
        }
    }

    query(left: number, right: number, value: number): number {
        const idx = this.g.get(value);
        if (!idx) {
            return 0;
        }
        const l = _.sortedIndex(idx, left);
        const r = _.sortedIndex(idx, right + 1);
        return r - l;
    }
}

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * var obj = new RangeFreqQuery(arr)
 * var param_1 = obj.query(left,right,value)
 */
```

#### Rust

```rust
use std::collections::HashMap;

struct RangeFreqQuery {
    g: HashMap<i32, Vec<usize>>,
}

impl RangeFreqQuery {
    fn new(arr: Vec<i32>) -> Self {
        let mut g = HashMap::new();
        for (i, &value) in arr.iter().enumerate() {
            g.entry(value).or_insert_with(Vec::new).push(i);
        }
        RangeFreqQuery { g }
    }

    fn query(&self, left: i32, right: i32, value: i32) -> i32 {
        if let Some(idx) = self.g.get(&value) {
            let l = idx.partition_point(|&x| x < left as usize);
            let r = idx.partition_point(|&x| x <= right as usize);
            return (r - l) as i32;
        }
        0
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} arr
 */
var RangeFreqQuery = function (arr) {
    this.g = new Map();

    for (let i = 0; i < arr.length; ++i) {
        if (!this.g.has(arr[i])) {
            this.g.set(arr[i], []);
        }
        this.g.get(arr[i]).push(i);
    }
};

/**
 * @param {number} left
 * @param {number} right
 * @param {number} value
 * @return {number}
 */
RangeFreqQuery.prototype.query = function (left, right, value) {
    const idx = this.g.get(value);
    if (!idx) {
        return 0;
    }
    const l = _.sortedIndex(idx, left);
    const r = _.sortedIndex(idx, right + 1);
    return r - l;
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * var obj = new RangeFreqQuery(arr)
 * var param_1 = obj.query(left,right,value)
 */
```

#### C#

```cs
public class RangeFreqQuery {
    private Dictionary<int, List<int>> g;

    public RangeFreqQuery(int[] arr) {
        g = new Dictionary<int, List<int>>();
        for (int i = 0; i < arr.Length; ++i) {
            if (!g.ContainsKey(arr[i])) {
                g[arr[i]] = new List<int>();
            }
            g[arr[i]].Add(i);
        }
    }

    public int Query(int left, int right, int value) {
        if (g.ContainsKey(value)) {
            var idx = g[value];
            int l = idx.BinarySearch(left);
            int r = idx.BinarySearch(right + 1);
            l = l < 0 ? -l - 1 : l;
            r = r < 0 ? -r - 1 : r;
            return r - l;
        }
        return 0;
    }
}

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery obj = new RangeFreqQuery(arr);
 * int param_1 = obj.Query(left, right, value);
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2081. k 镜像数字的和](https://leetcode.cn/problems/sum-of-k-mirror-numbers){#2081}

{{< tabs "2081" >}}

{{% tab "python" %}}
```python
class Solution:
    def kMirror(self, k: int, n: int) -> int:
        def check(x: int, k: int) -> bool:
            s = []
            while x:
                s.append(x % k)
                x //= k
            return s == s[::-1]

        ans = 0
        for l in count(1):
            x = 10 ** ((l - 1) // 2)
            y = 10 ** ((l + 1) // 2)
            for i in range(x, y):
                v = i
                j = i if l % 2 == 0 else i // 10
                while j > 0:
                    v = v * 10 + j % 10
                    j //= 10
                if check(v, k):
                    ans += v
                    n -= 1
                    if n == 0:
                        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long kMirror(int k, int n) {
        long ans = 0;
        for (int l = 1;; l++) {
            int x = (int) Math.pow(10, (l - 1) / 2);
            int y = (int) Math.pow(10, (l + 1) / 2);
            for (int i = x; i < y; i++) {
                long v = i;
                int j = (l % 2 == 0) ? i : i / 10;
                while (j > 0) {
                    v = v * 10 + j % 10;
                    j /= 10;
                }
                if (check(v, k)) {
                    ans += v;
                    n--;
                    if (n == 0) {
                        return ans;
                    }
                }
            }
        }
    }

    private boolean check(long x, int k) {
        List<Integer> s = new ArrayList<>();
        while (x > 0) {
            s.add((int) (x % k));
            x /= k;
        }
        for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
            if (!s.get(i).equals(s.get(j))) {
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
    long long kMirror(int k, int n) {
        long long ans = 0;
        for (int l = 1;; ++l) {
            int x = pow(10, (l - 1) / 2);
            int y = pow(10, (l + 1) / 2);
            for (int i = x; i < y; ++i) {
                long long v = i;
                int j = (l % 2 == 0) ? i : i / 10;
                while (j > 0) {
                    v = v * 10 + j % 10;
                    j /= 10;
                }
                if (check(v, k)) {
                    ans += v;
                    if (--n == 0) {
                        return ans;
                    }
                }
            }
        }
    }

private:
    bool check(long long x, int k) {
        vector<int> s;
        while (x > 0) {
            s.push_back(x % k);
            x /= k;
        }
        for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
            if (s[i] != s[j]) {
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
func kMirror(k int, n int) int64 {
	check := func(x int64, k int) bool {
		s := []int{}
		for x > 0 {
			s = append(s, int(x%int64(k)))
			x /= int64(k)
		}
		for i, j := 0, len(s)-1; i < j; i, j = i+1, j-1 {
			if s[i] != s[j] {
				return false
			}
		}
		return true
	}

	var ans int64 = 0
	for l := 1; ; l++ {
		x := pow10((l - 1) / 2)
		y := pow10((l + 1) / 2)
		for i := x; i < y; i++ {
			v := int64(i)
			j := i
			if l%2 != 0 {
				j = i / 10
			}
			for j > 0 {
				v = v*10 + int64(j%10)
				j /= 10
			}
			if check(v, k) {
				ans += v
				n--
				if n == 0 {
					return ans
				}
			}
		}
	}
}

func pow10(exp int) int {
	res := 1
	for i := 0; i < exp; i++ {
		res *= 10
	}
	return res
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function kMirror(k: number, n: number): number {
    function check(x: number, k: number): boolean {
        const s: number[] = [];
        while (x > 0) {
            s.push(x % k);
            x = Math.floor(x / k);
        }
        for (let i = 0, j = s.length - 1; i < j; i++, j--) {
            if (s[i] !== s[j]) {
                return false;
            }
        }
        return true;
    }

    let ans = 0;
    for (let l = 1; ; l++) {
        const x = Math.pow(10, Math.floor((l - 1) / 2));
        const y = Math.pow(10, Math.floor((l + 1) / 2));
        for (let i = x; i < y; i++) {
            let v = i;
            let j = l % 2 === 0 ? i : Math.floor(i / 10);
            while (j > 0) {
                v = v * 10 + (j % 10);
                j = Math.floor(j / 10);
            }
            if (check(v, k)) {
                ans += v;
                n--;
                if (n === 0) {
                    return ans;
                }
            }
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

<p>一个 <strong>k 镜像数字</strong>&nbsp;指的是一个在十进制和 k 进制下从前往后读和从后往前读都一样的&nbsp;<strong>没有前导 0</strong>&nbsp;的&nbsp;<strong>正</strong>&nbsp;整数。</p>

<ul>
	<li>比方说，<code>9</code>&nbsp;是一个 2 镜像数字。<code>9</code>&nbsp;在十进制下为&nbsp;<code>9</code>&nbsp;，二进制下为&nbsp;<code>1001</code>&nbsp;，两者从前往后读和从后往前读都一样。</li>
	<li>相反地，<code>4</code>&nbsp;不是一个 2 镜像数字。<code>4</code>&nbsp;在二进制下为&nbsp;<code>100</code>&nbsp;，从前往后和从后往前读不相同。</li>
</ul>

<p>给你进制&nbsp;<code>k</code>&nbsp;和一个数字&nbsp;<code>n</code>&nbsp;，请你返回 k 镜像数字中 <strong>最小</strong> 的 <code>n</code>&nbsp;个数 <strong>之和</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><b>示例 1：</b></p>

<pre><b>输入：</b>k = 2, n = 5
<b>输出：</b>25
<strong>解释：
</strong>最小的 5 个 2 镜像数字和它们的二进制表示如下：
  十进制       二进制
    1          1
    3          11
    5          101
    7          111
    9          1001
它们的和为 1 + 3 + 5 + 7 + 9 = 25 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>k = 3, n = 7
<b>输出：</b>499
<strong>解释：
</strong>7 个最小的 3 镜像数字和它们的三进制表示如下：
  十进制       三进制
    1          1
    2          2
    4          11
    8          22
    121        11111
    151        12121
    212        21212
它们的和为 1 + 2 + 4 + 8 + 121 + 151 + 212 = 499 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>k = 7, n = 17
<b>输出：</b>20379000
<b>解释：</b>17 个最小的 7 镜像数字分别为：
1, 2, 3, 4, 5, 6, 8, 121, 171, 242, 292, 16561, 65656, 2137312, 4602064, 6597956, 6958596
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= k &lt;= 9</code></li>
	<li><code>1 &lt;= n &lt;= 30</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：折半枚举 + 数学

对于一个 k 镜像数字，我们可以将其分为两部分：前半部分和后半部分。对于偶数长度的数字，前半部分和后半部分完全相同；对于奇数长度的数字，前半部分和后半部分相同，但中间的数字可以是任意数字。

我们可以通过枚举前半部分的数字，然后根据前半部分构造出完整的 k 镜像数字。具体步骤如下：

1. **枚举长度**：从 1 开始枚举数字的长度，直到找到满足条件的 k 镜像数字。
2. **计算前半部分的范围**：对于长度为 $l$ 的数字，前半部分的范围是 $[10^{(l-1)/2}, 10^{(l+1)/2})$。
3. **构造 k 镜像数字**：对于每个前半部分的数字 $i$，如果长度为偶数，则直接将 $i$ 作为前半部分；如果长度为奇数，则将 $i$ 除以 10 得到前半部分。然后将前半部分的数字反转并添加到后半部分，构造出完整的 k 镜像数字。
4. **检查 k 镜像数字**：将构造出的数字转换为 k 进制，检查其是否是回文数。
5. **累加结果**：如果是 k 镜像数字，则将其累加到结果中，并减少计数器 $n$。当计数器 $n$ 减至 0 时，返回结果。

时间复杂度主要取决于枚举的长度和前半部分的范围。由于 $n$ 的最大值为 30，因此在实际操作中，枚举的次数是有限的。空间复杂度 $O(1)$，因为我们只使用了常数级别的额外空间。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def kMirror(self, k: int, n: int) -> int:
        def check(x: int, k: int) -> bool:
            s = []
            while x:
                s.append(x % k)
                x //= k
            return s == s[::-1]

        ans = 0
        for l in count(1):
            x = 10 ** ((l - 1) // 2)
            y = 10 ** ((l + 1) // 2)
            for i in range(x, y):
                v = i
                j = i if l % 2 == 0 else i // 10
                while j > 0:
                    v = v * 10 + j % 10
                    j //= 10
                if check(v, k):
                    ans += v
                    n -= 1
                    if n == 0:
                        return ans
```

#### Java

```java
class Solution {
    public long kMirror(int k, int n) {
        long ans = 0;
        for (int l = 1;; l++) {
            int x = (int) Math.pow(10, (l - 1) / 2);
            int y = (int) Math.pow(10, (l + 1) / 2);
            for (int i = x; i < y; i++) {
                long v = i;
                int j = (l % 2 == 0) ? i : i / 10;
                while (j > 0) {
                    v = v * 10 + j % 10;
                    j /= 10;
                }
                if (check(v, k)) {
                    ans += v;
                    n--;
                    if (n == 0) {
                        return ans;
                    }
                }
            }
        }
    }

    private boolean check(long x, int k) {
        List<Integer> s = new ArrayList<>();
        while (x > 0) {
            s.add((int) (x % k));
            x /= k;
        }
        for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
            if (!s.get(i).equals(s.get(j))) {
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
    long long kMirror(int k, int n) {
        long long ans = 0;
        for (int l = 1;; ++l) {
            int x = pow(10, (l - 1) / 2);
            int y = pow(10, (l + 1) / 2);
            for (int i = x; i < y; ++i) {
                long long v = i;
                int j = (l % 2 == 0) ? i : i / 10;
                while (j > 0) {
                    v = v * 10 + j % 10;
                    j /= 10;
                }
                if (check(v, k)) {
                    ans += v;
                    if (--n == 0) {
                        return ans;
                    }
                }
            }
        }
    }

private:
    bool check(long long x, int k) {
        vector<int> s;
        while (x > 0) {
            s.push_back(x % k);
            x /= k;
        }
        for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }
};
```

#### Go

```go
func kMirror(k int, n int) int64 {
	check := func(x int64, k int) bool {
		s := []int{}
		for x > 0 {
			s = append(s, int(x%int64(k)))
			x /= int64(k)
		}
		for i, j := 0, len(s)-1; i < j; i, j = i+1, j-1 {
			if s[i] != s[j] {
				return false
			}
		}
		return true
	}

	var ans int64 = 0
	for l := 1; ; l++ {
		x := pow10((l - 1) / 2)
		y := pow10((l + 1) / 2)
		for i := x; i < y; i++ {
			v := int64(i)
			j := i
			if l%2 != 0 {
				j = i / 10
			}
			for j > 0 {
				v = v*10 + int64(j%10)
				j /= 10
			}
			if check(v, k) {
				ans += v
				n--
				if n == 0 {
					return ans
				}
			}
		}
	}
}

func pow10(exp int) int {
	res := 1
	for i := 0; i < exp; i++ {
		res *= 10
	}
	return res
}
```

#### TypeScript

```ts
function kMirror(k: number, n: number): number {
    function check(x: number, k: number): boolean {
        const s: number[] = [];
        while (x > 0) {
            s.push(x % k);
            x = Math.floor(x / k);
        }
        for (let i = 0, j = s.length - 1; i < j; i++, j--) {
            if (s[i] !== s[j]) {
                return false;
            }
        }
        return true;
    }

    let ans = 0;
    for (let l = 1; ; l++) {
        const x = Math.pow(10, Math.floor((l - 1) / 2));
        const y = Math.pow(10, Math.floor((l + 1) / 2));
        for (let i = x; i < y; i++) {
            let v = i;
            let j = l % 2 === 0 ? i : Math.floor(i / 10);
            while (j > 0) {
                v = v * 10 + (j % 10);
                j = Math.floor(j / 10);
            }
            if (check(v, k)) {
                ans += v;
                n--;
                if (n === 0) {
                    return ans;
                }
            }
        }
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2082. 富有客户的数量 🔒](https://leetcode.cn/problems/the-number-of-rich-customers){#2082}

{{< tabs "2082" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT
    COUNT(DISTINCT customer_id) AS rich_count
FROM Store
WHERE amount > 500;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表： <code>Store</code></p>

<pre>
+-------------+------+
| Column Name | Type |
+-------------+------+
| bill_id     | int  |
| customer_id | int  |
| amount      | int  |
+-------------+------+
bill_id 是这个表的主键(具有唯一值的列)。
每一行包含一个订单的金额及相关客户的信息。
</pre>

<p>&nbsp;</p>

<p>编写解决方案找出&nbsp;<strong>至少有一个&nbsp;</strong>订单的金额&nbsp;<strong>严格大于</strong> <code>500</code> 的客户的数量。</p>

<p>返回结果格式如下示例所示：</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入：</strong>
Store 表:
+---------+-------------+--------+
| bill_id | customer_id | amount |
+---------+-------------+--------+
| 6       | 1           | 549    |
| 8       | 1           | 834    |
| 4       | 2           | 394    |
| 11      | 3           | 657    |
| 13      | 3           | 257    |
+---------+-------------+--------+
<strong>输出：</strong> 
+------------+
| rich_count |
+------------+
| 2          |
+------------+
<strong>解释：</strong>
客户 1 有 2 个订单金额严格大于 500。
客户 2 没有任何订单金额严格大于 500。
客户 3 有 1 个订单金额严格大于 500。
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
    COUNT(DISTINCT customer_id) AS rich_count
FROM Store
WHERE amount > 500;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2083. 求以相同字母开头和结尾的子串总数 🔒](https://leetcode.cn/problems/substrings-that-begin-and-end-with-the-same-letter){#2083}

{{< tabs "2083" >}}

{{% tab "python" %}}
```python
class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        cnt = Counter()
        ans = 0
        for c in s:
            cnt[c] += 1
            ans += cnt[c]
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long numberOfSubstrings(String s) {
        int[] cnt = new int[26];
        long ans = 0;
        for (char c : s.toCharArray()) {
            ans += ++cnt[c - 'a'];
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
    long long numberOfSubstrings(string s) {
        int cnt[26]{};
        long long ans = 0;
        for (char& c : s) {
            ans += ++cnt[c - 'a'];
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numberOfSubstrings(s string) (ans int64) {
	cnt := [26]int{}
	for _, c := range s {
		c -= 'a'
		cnt[c]++
		ans += int64(cnt[c])
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numberOfSubstrings(s: string): number {
    const cnt: Record<string, number> = {};
    let ans = 0;
    for (const c of s) {
        cnt[c] = (cnt[c] || 0) + 1;
        ans += cnt[c];
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn number_of_substrings(s: String) -> i64 {
        let mut cnt = [0; 26];
        let mut ans = 0_i64;
        for c in s.chars() {
            let idx = (c as u8 - b'a') as usize;
            cnt[idx] += 1;
            ans += cnt[idx];
        }
        ans
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {string} s
 * @return {number}
 */
var numberOfSubstrings = function (s) {
    const cnt = {};
    let ans = 0;
    for (const c of s) {
        cnt[c] = (cnt[c] || 0) + 1;
        ans += cnt[c];
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

<p>给你一个仅由小写英文字母组成的，&nbsp; 下标从 <code>0</code> 开始的字符串 <code>s</code> 。返回 <code>s</code> 中以相同字符开头和结尾的子字符串总数。</p>

<p>子字符串是字符串中连续的非空字符序列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "abcba"
<strong>输出：</strong>7
<strong>解释：</strong>
以相同字母开头和结尾的长度为 1 的子串是："a"、"b"、"c"、"b" 和 "a" 。
以相同字母开头和结尾的长度为 3 的子串是："bcb" 。
以相同字母开头和结尾的长度为 5 的子串是："abcba" 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "abacad"
<strong>输出：</strong>9
<strong>解释：</strong>
以相同字母开头和结尾的长度为 1 的子串是："a"、"b"、"a"、"c"、"a" 和 "d" 。
以相同字母开头和结尾的长度为 3 的子串是："aba" 和 "aca" 。
以相同字母开头和结尾的长度为 5 的子串是："abaca" 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "a"
<strong>输出：</strong>1
<strong>解释：</strong>
只有一个，以相同字母开头和结尾的长度为 1 的子串是："a"。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> 仅包含小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数组或哈希表

我们可以用哈希表或者一个长度为 $26$ 的数组 $\textit{cnt}$ 来记录每个字符出现的次数。

遍历字符串 $\textit{s}$，对于每个字符 $\textit{c}$，我们将 $\textit{cnt}[c]$ 的值加 $1$，然后将 $\textit{cnt}[c]$ 的值加到答案中。

最后返回答案即可。

时间复杂度 $O(n)$，其中 $n$ 是字符串 $\textit{s}$ 的长度。空间复杂度 $O(|\Sigma|)$，其中 $\Sigma$ 是字符集，这里是小写英文字母，所以 $|\Sigma|=26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        cnt = Counter()
        ans = 0
        for c in s:
            cnt[c] += 1
            ans += cnt[c]
        return ans
```

#### Java

```java
class Solution {
    public long numberOfSubstrings(String s) {
        int[] cnt = new int[26];
        long ans = 0;
        for (char c : s.toCharArray()) {
            ans += ++cnt[c - 'a'];
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long numberOfSubstrings(string s) {
        int cnt[26]{};
        long long ans = 0;
        for (char& c : s) {
            ans += ++cnt[c - 'a'];
        }
        return ans;
    }
};
```

#### Go

```go
func numberOfSubstrings(s string) (ans int64) {
	cnt := [26]int{}
	for _, c := range s {
		c -= 'a'
		cnt[c]++
		ans += int64(cnt[c])
	}
	return ans
}
```

#### TypeScript

```ts
function numberOfSubstrings(s: string): number {
    const cnt: Record<string, number> = {};
    let ans = 0;
    for (const c of s) {
        cnt[c] = (cnt[c] || 0) + 1;
        ans += cnt[c];
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn number_of_substrings(s: String) -> i64 {
        let mut cnt = [0; 26];
        let mut ans = 0_i64;
        for c in s.chars() {
            let idx = (c as u8 - b'a') as usize;
            cnt[idx] += 1;
            ans += cnt[idx];
        }
        ans
    }
}
```

#### JavaScript

```js
/**
 * @param {string} s
 * @return {number}
 */
var numberOfSubstrings = function (s) {
    const cnt = {};
    let ans = 0;
    for (const c of s) {
        cnt[c] = (cnt[c] || 0) + 1;
        ans += cnt[c];
    }
    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2084. 为订单类型为 0 的客户删除类型为 1 的订单 🔒](https://leetcode.cn/problems/drop-type-1-orders-for-customers-with-type-0-orders){#2084}

{{< tabs "2084" >}}

{{% tab "sql" %}}
```sql
SELECT DISTINCT
    a.order_id,
    a.customer_id,
    a.order_type
FROM
    Orders AS a
    LEFT JOIN Orders AS b ON a.customer_id = b.customer_id AND a.order_type != b.order_type
WHERE b.order_type IS NULL OR b.order_type = 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>活动表: <code>Orders</code></p>

<pre>+-------------+------+
| Column Name | Type |
+-------------+------+
| order_id    | int  | 
| customer_id | int  |
| order_type  | int  | 
+-------------+------+
order_id是此表的主键列。
此表的每一行都表示订单的ID、订购该订单的客户的ID以及订单类型。
订单可以是类型0或类型1。
</pre>

<p>&nbsp;</p>

<p>编写SQL查询以根据以下条件报告所有订单：</p>

<ul>
	<li>如果客户至少有一个类型为0的订单，则不要报告该客户的任何类型为1的订单。</li>
	<li>否则，报告客户的所有订单。</li>
</ul>

<p>按任意顺序返回结果表。</p>

<p>查询结果格式如下例所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> 
Orders table:
+----------+-------------+------------+
| order_id | customer_id | order_type |
+----------+-------------+------------+
| 1        | 1           | 0          |
| 2        | 1           | 0          |
| 11       | 2           | 0          |
| 12       | 2           | 1          |
| 21       | 3           | 1          |
| 22       | 3           | 0          |
| 31       | 4           | 1          |
| 32       | 4           | 1          |
+----------+-------------+------------+
<strong>输出:</strong> 
+----------+-------------+------------+
| order_id | customer_id | order_type |
+----------+-------------+------------+
| 31       | 4           | 1          |
| 32       | 4           | 1          |
| 1        | 1           | 0          |
| 2        | 1           | 0          |
| 11       | 2           | 0          |
| 22       | 3           | 0          |
+----------+-------------+------------+
<strong>解释:</strong> 
客户1有两个类型为0的订单。我们两个都返回。
客户2的订单类型为0，订单类型为1。我们只返回类型为0的订单。
客户3的订单类型为0，订单类型为1。我们只返回类型为0的订单。
客户4有两个类型1的订单。我们两个都返回。
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
WITH
    T AS (
        SELECT DISTINCT customer_id
        FROM Orders
        WHERE order_type = 0
    )
SELECT *
FROM Orders AS o
WHERE order_type = 0 OR NOT EXISTS (SELECT 1 FROM T AS t WHERE t.customer_id = o.customer_id);
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### MySQL

```sql
SELECT DISTINCT
    a.order_id,
    a.customer_id,
    a.order_type
FROM
    Orders AS a
    LEFT JOIN Orders AS b ON a.customer_id = b.customer_id AND a.order_type != b.order_type
WHERE b.order_type IS NULL OR b.order_type = 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2085. 统计出现过一次的公共字符串](https://leetcode.cn/problems/count-common-words-with-one-occurrence){#2085}

{{< tabs "2085" >}}

{{% tab "python" %}}
```python
class Solution:
    def countWords(self, words1: List[str], words2: List[str]) -> int:
        cnt1 = Counter(words1)
        cnt2 = Counter(words2)
        return sum(v == 1 and cnt2[w] == 1 for w, v in cnt1.items())
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countWords(String[] words1, String[] words2) {
        Map<String, Integer> cnt1 = new HashMap<>();
        Map<String, Integer> cnt2 = new HashMap<>();
        for (var w : words1) {
            cnt1.merge(w, 1, Integer::sum);
        }
        for (var w : words2) {
            cnt2.merge(w, 1, Integer::sum);
        }
        int ans = 0;
        for (var e : cnt1.entrySet()) {
            if (e.getValue() == 1 && cnt2.getOrDefault(e.getKey(), 0) == 1) {
                ++ans;
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
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> cnt1;
        unordered_map<string, int> cnt2;
        for (auto& w : words1) {
            ++cnt1[w];
        }
        for (auto& w : words2) {
            ++cnt2[w];
        }
        int ans = 0;
        for (auto& [w, v] : cnt1) {
            ans += v == 1 && cnt2[w] == 1;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countWords(words1 []string, words2 []string) (ans int) {
	cnt1 := map[string]int{}
	cnt2 := map[string]int{}
	for _, w := range words1 {
		cnt1[w]++
	}
	for _, w := range words2 {
		cnt2[w]++
	}
	for w, v := range cnt1 {
		if v == 1 && cnt2[w] == 1 {
			ans++
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countWords(words1: string[], words2: string[]): number {
    const cnt1 = new Map<string, number>();
    const cnt2 = new Map<string, number>();
    for (const w of words1) {
        cnt1.set(w, (cnt1.get(w) ?? 0) + 1);
    }
    for (const w of words2) {
        cnt2.set(w, (cnt2.get(w) ?? 0) + 1);
    }
    let ans = 0;
    for (const [w, v] of cnt1) {
        if (v === 1 && cnt2.get(w) === 1) {
            ++ans;
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

<p>给你两个字符串数组&nbsp;<code>words1</code>&nbsp;和&nbsp;<code>words2</code>&nbsp;，请你返回在两个字符串数组中 <strong>都恰好出现一次</strong>&nbsp;的字符串的数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>words1 = ["leetcode","is","amazing","as","is"], words2 = ["amazing","leetcode","is"]
<b>输出：</b>2
<strong>解释：</strong>
- "leetcode" 在两个数组中都恰好出现一次，计入答案。
- "amazing" 在两个数组中都恰好出现一次，计入答案。
- "is" 在两个数组中都出现过，但在 words1 中出现了 2 次，不计入答案。
- "as" 在 words1 中出现了一次，但是在 words2 中没有出现过，不计入答案。
所以，有 2 个字符串在两个数组中都恰好出现了一次。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>words1 = ["b","bb","bbb"], words2 = ["a","aa","aaa"]
<b>输出：</b>0
<b>解释：</b>没有字符串在两个数组中都恰好出现一次。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>words1 = ["a","ab"], words2 = ["a","a","a","ab"]
<b>输出：</b>1
<b>解释：</b>唯一在两个数组中都出现一次的字符串是 "ab" 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= words1.length, words2.length &lt;= 1000</code></li>
	<li><code>1 &lt;= words1[i].length, words2[j].length &lt;= 30</code></li>
	<li><code>words1[i]</code> 和&nbsp;<code>words2[j]</code>&nbsp;都只包含小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表计数

我们可以用两个哈希表 $cnt1$ 和 $cnt2$ 分别统计两个字符串数组中每个字符串出现的次数，然后遍历其中一个哈希表，如果某个字符串在另一个哈希表中出现了一次，且在当前哈希表中也出现了一次，则答案加一。

时间复杂度 $O(n + m)$，空间复杂度 $O(n + m)$。其中 $n$ 和 $m$ 分别是两个字符串数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countWords(self, words1: List[str], words2: List[str]) -> int:
        cnt1 = Counter(words1)
        cnt2 = Counter(words2)
        return sum(v == 1 and cnt2[w] == 1 for w, v in cnt1.items())
```

#### Java

```java
class Solution {
    public int countWords(String[] words1, String[] words2) {
        Map<String, Integer> cnt1 = new HashMap<>();
        Map<String, Integer> cnt2 = new HashMap<>();
        for (var w : words1) {
            cnt1.merge(w, 1, Integer::sum);
        }
        for (var w : words2) {
            cnt2.merge(w, 1, Integer::sum);
        }
        int ans = 0;
        for (var e : cnt1.entrySet()) {
            if (e.getValue() == 1 && cnt2.getOrDefault(e.getKey(), 0) == 1) {
                ++ans;
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
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> cnt1;
        unordered_map<string, int> cnt2;
        for (auto& w : words1) {
            ++cnt1[w];
        }
        for (auto& w : words2) {
            ++cnt2[w];
        }
        int ans = 0;
        for (auto& [w, v] : cnt1) {
            ans += v == 1 && cnt2[w] == 1;
        }
        return ans;
    }
};
```

#### Go

```go
func countWords(words1 []string, words2 []string) (ans int) {
	cnt1 := map[string]int{}
	cnt2 := map[string]int{}
	for _, w := range words1 {
		cnt1[w]++
	}
	for _, w := range words2 {
		cnt2[w]++
	}
	for w, v := range cnt1 {
		if v == 1 && cnt2[w] == 1 {
			ans++
		}
	}
	return
}
```

#### TypeScript

```ts
function countWords(words1: string[], words2: string[]): number {
    const cnt1 = new Map<string, number>();
    const cnt2 = new Map<string, number>();
    for (const w of words1) {
        cnt1.set(w, (cnt1.get(w) ?? 0) + 1);
    }
    for (const w of words2) {
        cnt2.set(w, (cnt2.get(w) ?? 0) + 1);
    }
    let ans = 0;
    for (const [w, v] of cnt1) {
        if (v === 1 && cnt2.get(w) === 1) {
            ++ans;
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

# [2086. 喂食仓鼠的最小食物桶数](https://leetcode.cn/problems/minimum-number-of-food-buckets-to-feed-the-hamsters){#2086}

{{< tabs "2086" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumBuckets(self, street: str) -> int:
        ans = 0
        i, n = 0, len(street)
        while i < n:
            if street[i] == 'H':
                if i + 1 < n and street[i + 1] == '.':
                    i += 2
                    ans += 1
                elif i and street[i - 1] == '.':
                    ans += 1
                else:
                    return -1
            i += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumBuckets(String street) {
        int n = street.length();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (street.charAt(i) == 'H') {
                if (i + 1 < n && street.charAt(i + 1) == '.') {
                    ++ans;
                    i += 2;
                } else if (i > 0 && street.charAt(i - 1) == '.') {
                    ++ans;
                } else {
                    return -1;
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
    int minimumBuckets(string street) {
        int n = street.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (street[i] == 'H') {
                if (i + 1 < n && street[i + 1] == '.') {
                    ++ans;
                    i += 2;
                } else if (i && street[i - 1] == '.') {
                    ++ans;
                } else {
                    return -1;
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
func minimumBuckets(street string) int {
	ans, n := 0, len(street)
	for i := 0; i < n; i++ {
		if street[i] == 'H' {
			if i+1 < n && street[i+1] == '.' {
				ans++
				i += 2
			} else if i > 0 && street[i-1] == '.' {
				ans++
			} else {
				return -1
			}
		}
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

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的字符串&nbsp;<code>hamsters</code>&nbsp;，其中&nbsp;<code>hamsters[i]</code>&nbsp; 要么是：</p>

<ul>
	<li><code>'H'</code>&nbsp;表示有一个仓鼠在下标&nbsp;<code>i</code>&nbsp;，或者</li>
	<li><code>'.'</code>&nbsp;表示下标&nbsp;<code>i</code>&nbsp;是空的。</li>
</ul>

<p>你将要在空的位置上添加一定数量的食物桶来喂养仓鼠。如果仓鼠的左边或右边至少有一个食物桶，就可以喂食它。更正式地说，如果你在位置&nbsp;<code>i - 1</code>&nbsp;<strong>或者</strong> <code>i + 1</code>&nbsp;放置一个食物桶，就可以喂养位置为 <code>i</code>&nbsp;处的仓鼠。</p>

<p>在 <strong>空的位置</strong> 放置食物桶以喂养所有仓鼠的前提下，请你返回需要的 <strong>最少</strong>&nbsp;食物桶数。如果无解请返回 <code>-1</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2086.Minimum%20Number%20of%20Food%20Buckets%20to%20Feed%20the%20Hamsters/images/1710141378-bfEGUX-image.png" style="width: 482px; height: 162px;" /></strong></p>

<pre>
<b>输入：</b>hamsters = "H..H"
<b>输出：</b>2
<strong>解释：</strong>
我们可以在下标为 1 和 2 处放食物桶。
可以发现如果我们只放置 1 个食物桶，其中一只仓鼠将得不到喂养。
</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2086.Minimum%20Number%20of%20Food%20Buckets%20to%20Feed%20the%20Hamsters/images/1710141384-oLAScv-image.png" style="width: 602px; height: 162px;" /></strong></p>

<pre>
<b>输入：</b>street = ".H.H."
<b>输出：</b>1
<strong>解释：</strong>
我们可以在下标为 2 处放置一个食物桶。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>street = ".HHH."
<b>输出：</b>-1
<strong>解释：</strong>
如果我们如图那样在每个空位放置食物桶，下标 2 处的仓鼠将吃不到食物。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= hamsters.length &lt;= 10<sup>5</sup></code></li>
	<li><code>hamsters[i]</code>&nbsp;要么是&nbsp;<code>'H'</code>&nbsp;，要么是&nbsp;<code>'.'</code> 。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心

从左到右遍历字符串，遇到 `H` 时，优先考虑右边是否有空位，如果有则放置水桶，并且跳过水桶的下一个位置；如果右边没有空位，则考虑左边是否有空位，如果有则放置水桶，否则无解。

时间复杂度 $O(n)$，空间复杂度 $O(1)$。其中 $n$ 为字符串 `street` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumBuckets(self, street: str) -> int:
        ans = 0
        i, n = 0, len(street)
        while i < n:
            if street[i] == 'H':
                if i + 1 < n and street[i + 1] == '.':
                    i += 2
                    ans += 1
                elif i and street[i - 1] == '.':
                    ans += 1
                else:
                    return -1
            i += 1
        return ans
```

#### Java

```java
class Solution {
    public int minimumBuckets(String street) {
        int n = street.length();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (street.charAt(i) == 'H') {
                if (i + 1 < n && street.charAt(i + 1) == '.') {
                    ++ans;
                    i += 2;
                } else if (i > 0 && street.charAt(i - 1) == '.') {
                    ++ans;
                } else {
                    return -1;
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
    int minimumBuckets(string street) {
        int n = street.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (street[i] == 'H') {
                if (i + 1 < n && street[i + 1] == '.') {
                    ++ans;
                    i += 2;
                } else if (i && street[i - 1] == '.') {
                    ++ans;
                } else {
                    return -1;
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func minimumBuckets(street string) int {
	ans, n := 0, len(street)
	for i := 0; i < n; i++ {
		if street[i] == 'H' {
			if i+1 < n && street[i+1] == '.' {
				ans++
				i += 2
			} else if i > 0 && street[i-1] == '.' {
				ans++
			} else {
				return -1
			}
		}
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2087. 网格图中机器人回家的最小代价](https://leetcode.cn/problems/minimum-cost-homecoming-of-a-robot-in-a-grid){#2087}

{{< tabs "2087" >}}

{{% tab "python" %}}
```python
class Solution:
    def minCost(
        self,
        startPos: List[int],
        homePos: List[int],
        rowCosts: List[int],
        colCosts: List[int],
    ) -> int:
        i, j = startPos
        x, y = homePos
        ans = 0
        if i < x:
            ans += sum(rowCosts[i + 1 : x + 1])
        else:
            ans += sum(rowCosts[x:i])
        if j < y:
            ans += sum(colCosts[j + 1 : y + 1])
        else:
            ans += sum(colCosts[y:j])
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minCost(int[] startPos, int[] homePos, int[] rowCosts, int[] colCosts) {
        int i = startPos[0], j = startPos[1];
        int x = homePos[0], y = homePos[1];
        int ans = 0;
        if (i < x) {
            for (int k = i + 1; k <= x; ++k) {
                ans += rowCosts[k];
            }
        } else {
            for (int k = x; k < i; ++k) {
                ans += rowCosts[k];
            }
        }
        if (j < y) {
            for (int k = j + 1; k <= y; ++k) {
                ans += colCosts[k];
            }
        } else {
            for (int k = y; k < j; ++k) {
                ans += colCosts[k];
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
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int i = startPos[0], j = startPos[1];
        int x = homePos[0], y = homePos[1];
        int ans = 0;
        if (i < x) {
            ans += accumulate(rowCosts.begin() + i + 1, rowCosts.begin() + x + 1, 0);
        } else {
            ans += accumulate(rowCosts.begin() + x, rowCosts.begin() + i, 0);
        }
        if (j < y) {
            ans += accumulate(colCosts.begin() + j + 1, colCosts.begin() + y + 1, 0);
        } else {
            ans += accumulate(colCosts.begin() + y, colCosts.begin() + j, 0);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minCost(startPos []int, homePos []int, rowCosts []int, colCosts []int) (ans int) {
	i, j := startPos[0], startPos[1]
	x, y := homePos[0], homePos[1]
	if i < x {
		ans += sum(rowCosts, i+1, x+1)
	} else {
		ans += sum(rowCosts, x, i)
	}
	if j < y {
		ans += sum(colCosts, j+1, y+1)
	} else {
		ans += sum(colCosts, y, j)
	}
	return
}

func sum(nums []int, i, j int) (s int) {
	for k := i; k < j; k++ {
		s += nums[k]
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

<p>给你一个&nbsp;<code>m x n</code>&nbsp;的网格图，其中&nbsp;<code>(0, 0)</code>&nbsp;是最左上角的格子，<code>(m - 1, n - 1)</code>&nbsp;是最右下角的格子。给你一个整数数组&nbsp;<code>startPos</code>&nbsp;，<code>startPos = [start<sub>row</sub>, start<sub>col</sub>]</code>&nbsp;表示 <strong>初始</strong>&nbsp;有一个 <strong>机器人</strong>&nbsp;在格子&nbsp;<code>(start<sub>row</sub>, start<sub>col</sub>)</code>&nbsp;处。同时给你一个整数数组&nbsp;<code>homePos</code>&nbsp;，<code>homePos = [home<sub>row</sub>, home<sub>col</sub>]</code>&nbsp;表示机器人的 <strong>家</strong>&nbsp;在格子&nbsp;<code>(home<sub>row</sub>, home<sub>col</sub>)</code>&nbsp;处。</p>

<p>机器人需要回家。每一步它可以往四个方向移动：<strong>上</strong>，<strong>下</strong>，<strong>左</strong>，<strong>右</strong>，同时机器人不能移出边界。每一步移动都有一定代价。再给你两个下标从&nbsp;<strong>0</strong>&nbsp;开始的额整数数组：长度为&nbsp;<code>m</code>&nbsp;的数组&nbsp;<code>rowCosts</code> &nbsp;和长度为 <code>n</code>&nbsp;的数组&nbsp;<code>colCosts</code>&nbsp;。</p>

<ul>
	<li>如果机器人往 <strong>上</strong>&nbsp;或者往 <strong>下</strong>&nbsp;移动到第 <code>r</code>&nbsp;<strong>行</strong>&nbsp;的格子，那么代价为&nbsp;<code>rowCosts[r]</code>&nbsp;。</li>
	<li>如果机器人往 <strong>左</strong>&nbsp;或者往 <strong>右</strong>&nbsp;移动到第 <code>c</code>&nbsp;<strong>列</strong> 的格子，那么代价为&nbsp;<code>colCosts[c]</code>&nbsp;。</li>
</ul>

<p>请你返回机器人回家需要的 <strong>最小总代价</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2087.Minimum%20Cost%20Homecoming%20of%20a%20Robot%20in%20a%20Grid/images/eg-1.png" style="width: 282px; height: 217px;"></p>

<pre><strong>输入：</strong>startPos = [1, 0], homePos = [2, 3], rowCosts = [5, 4, 3], colCosts = [8, 2, 6, 7]
<b>输出：</b>18
<b>解释：</b>一个最优路径为：
从 (1, 0) 开始
-&gt; 往下走到 (<em><strong>2</strong></em>, 0) 。代价为 rowCosts[2] = 3 。
-&gt; 往右走到 (2, <em><strong>1</strong></em>) 。代价为 colCosts[1] = 2 。
-&gt; 往右走到 (2, <em><strong>2</strong></em>) 。代价为 colCosts[2] = 6 。
-&gt; 往右走到 (2, <em><strong>3</strong></em>) 。代价为 colCosts[3] = 7 。
总代价为 3 + 2 + 6 + 7 = 18</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>startPos = [0, 0], homePos = [0, 0], rowCosts = [5], colCosts = [26]
<b>输出：</b>0
<b>解释：</b>机器人已经在家了，所以不需要移动。总代价为 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == rowCosts.length</code></li>
	<li><code>n == colCosts.length</code></li>
	<li><code>1 &lt;= m, n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= rowCosts[r], colCosts[c] &lt;= 10<sup>4</sup></code></li>
	<li><code>startPos.length == 2</code></li>
	<li><code>homePos.length == 2</code></li>
	<li><code>0 &lt;= start<sub>row</sub>, home<sub>row</sub> &lt; m</code></li>
	<li><code>0 &lt;= start<sub>col</sub>, home<sub>col</sub> &lt; n</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心

设机器人当前位置为 $(i, j)$，目标位置为 $(x, y)$。

-   如果 $i \lt x$，则机器人往下移动，代价为 $rowCosts[i + 1] + rowCosts[i + 2] + \cdots + rowCosts[x]$。
-   如果 $i \gt x$，则机器人往上移动，代价为 $rowCosts[x] + rowCosts[x + 1] + \cdots + rowCosts[i - 1]$。
-   如果 $j \lt y$，则机器人往右移动，代价为 $colCosts[j + 1] + colCosts[j + 2] + \cdots + colCosts[y]$。
-   如果 $j \gt y$，则机器人往左移动，代价为 $colCosts[y] + colCosts[y + 1] + \cdots + colCosts[j - 1]$。

时间复杂度 $O(m + n)$，空间复杂度 $O(1)$。其中 $m$ 和 $n$ 分别为 $rowCosts$ 和 $colCosts$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minCost(
        self,
        startPos: List[int],
        homePos: List[int],
        rowCosts: List[int],
        colCosts: List[int],
    ) -> int:
        i, j = startPos
        x, y = homePos
        ans = 0
        if i < x:
            ans += sum(rowCosts[i + 1 : x + 1])
        else:
            ans += sum(rowCosts[x:i])
        if j < y:
            ans += sum(colCosts[j + 1 : y + 1])
        else:
            ans += sum(colCosts[y:j])
        return ans
```

#### Java

```java
class Solution {
    public int minCost(int[] startPos, int[] homePos, int[] rowCosts, int[] colCosts) {
        int i = startPos[0], j = startPos[1];
        int x = homePos[0], y = homePos[1];
        int ans = 0;
        if (i < x) {
            for (int k = i + 1; k <= x; ++k) {
                ans += rowCosts[k];
            }
        } else {
            for (int k = x; k < i; ++k) {
                ans += rowCosts[k];
            }
        }
        if (j < y) {
            for (int k = j + 1; k <= y; ++k) {
                ans += colCosts[k];
            }
        } else {
            for (int k = y; k < j; ++k) {
                ans += colCosts[k];
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
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int i = startPos[0], j = startPos[1];
        int x = homePos[0], y = homePos[1];
        int ans = 0;
        if (i < x) {
            ans += accumulate(rowCosts.begin() + i + 1, rowCosts.begin() + x + 1, 0);
        } else {
            ans += accumulate(rowCosts.begin() + x, rowCosts.begin() + i, 0);
        }
        if (j < y) {
            ans += accumulate(colCosts.begin() + j + 1, colCosts.begin() + y + 1, 0);
        } else {
            ans += accumulate(colCosts.begin() + y, colCosts.begin() + j, 0);
        }
        return ans;
    }
};
```

#### Go

```go
func minCost(startPos []int, homePos []int, rowCosts []int, colCosts []int) (ans int) {
	i, j := startPos[0], startPos[1]
	x, y := homePos[0], homePos[1]
	if i < x {
		ans += sum(rowCosts, i+1, x+1)
	} else {
		ans += sum(rowCosts, x, i)
	}
	if j < y {
		ans += sum(colCosts, j+1, y+1)
	} else {
		ans += sum(colCosts, y, j)
	}
	return
}

func sum(nums []int, i, j int) (s int) {
	for k := i; k < j; k++ {
		s += nums[k]
	}
	return
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2088. 统计农场中肥沃金字塔的数目](https://leetcode.cn/problems/count-fertile-pyramids-in-a-land){#2088}

{{< tabs "2088" >}}

{{% tab "python" %}}
```python
class Solution:
    def countPyramids(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        f = [[0] * n for _ in range(m)]
        ans = 0
        for i in range(m - 1, -1, -1):
            for j in range(n):
                if grid[i][j] == 0:
                    f[i][j] = -1
                elif not (i == m - 1 or j == 0 or j == n - 1):
                    f[i][j] = min(f[i + 1][j - 1], f[i + 1][j], f[i + 1][j + 1]) + 1
                    ans += f[i][j]
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 0:
                    f[i][j] = -1
                elif i == 0 or j == 0 or j == n - 1:
                    f[i][j] = 0
                else:
                    f[i][j] = min(f[i - 1][j - 1], f[i - 1][j], f[i - 1][j + 1]) + 1
                    ans += f[i][j]
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countPyramids(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int[][] f = new int[m][n];
        int ans = 0;
        for (int i = m - 1; i >= 0; --i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    f[i][j] = -1;
                } else if (i == m - 1 || j == 0 || j == n - 1) {
                    f[i][j] = 0;
                } else {
                    f[i][j] = Math.min(f[i + 1][j - 1], Math.min(f[i + 1][j], f[i + 1][j + 1])) + 1;
                    ans += f[i][j];
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    f[i][j] = -1;
                } else if (i == 0 || j == 0 || j == n - 1) {
                    f[i][j] = 0;
                } else {
                    f[i][j] = Math.min(f[i - 1][j - 1], Math.min(f[i - 1][j], f[i - 1][j + 1])) + 1;
                    ans += f[i][j];
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
    int countPyramids(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int f[m][n];
        int ans = 0;
        for (int i = m - 1; ~i; --i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    f[i][j] = -1;
                } else if (i == m - 1 || j == 0 || j == n - 1) {
                    f[i][j] = 0;
                } else {
                    f[i][j] = min({f[i + 1][j - 1], f[i + 1][j], f[i + 1][j + 1]}) + 1;
                    ans += f[i][j];
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    f[i][j] = -1;
                } else if (i == 0 || j == 0 || j == n - 1) {
                    f[i][j] = 0;
                } else {
                    f[i][j] = min({f[i - 1][j - 1], f[i - 1][j], f[i - 1][j + 1]}) + 1;
                    ans += f[i][j];
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
func countPyramids(grid [][]int) (ans int) {
	m, n := len(grid), len(grid[0])
	f := make([][]int, m)
	for i := range f {
		f[i] = make([]int, n)
	}
	for i := m - 1; i >= 0; i-- {
		for j := 0; j < n; j++ {
			if grid[i][j] == 0 {
				f[i][j] = -1
			} else if i == m-1 || j == 0 || j == n-1 {
				f[i][j] = 0
			} else {
				f[i][j] = min(f[i+1][j-1], min(f[i+1][j], f[i+1][j+1])) + 1
				ans += f[i][j]
			}
		}
	}
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if grid[i][j] == 0 {
				f[i][j] = -1
			} else if i == 0 || j == 0 || j == n-1 {
				f[i][j] = 0
			} else {
				f[i][j] = min(f[i-1][j-1], min(f[i-1][j], f[i-1][j+1])) + 1
				ans += f[i][j]
			}
		}
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

<p>有一个 <strong>矩形网格</strong>&nbsp;状的农场，划分为&nbsp;<code>m</code>&nbsp;行&nbsp;<code>n</code>&nbsp;列的单元格。每个格子要么是 <strong>肥沃的</strong>&nbsp;（用 <code>1</code>&nbsp;表示），要么是 <strong>贫瘠</strong>&nbsp;的（用 <code>0</code>&nbsp;表示）。网格图以外的所有与格子都视为贫瘠的。</p>

<p>农场中的&nbsp;<strong>金字塔</strong>&nbsp;区域定义如下：</p>

<ol>
	<li>区域内格子数目 <strong>大于&nbsp;</strong><code>1</code>&nbsp;且所有格子都是 <strong>肥沃的</strong>&nbsp;。</li>
	<li>金字塔 <strong>顶端</strong>&nbsp;是这个金字塔 <strong>最上方</strong>&nbsp;的格子。金字塔的高度是它所覆盖的行数。令&nbsp;<code>(r, c)</code>&nbsp;为金字塔的顶端且高度为 <code>h</code>&nbsp;，那么金字塔区域内包含的任一格子&nbsp;<code>(i, j)</code>&nbsp;需满足&nbsp;<code>r &lt;= i &lt;= r + h - 1</code>&nbsp;<strong>且</strong>&nbsp;<code>c - (i - r) &lt;= j &lt;= c + (i - r)</code>&nbsp;。</li>
</ol>

<p>一个 <strong>倒金字塔</strong>&nbsp;类似定义如下：</p>

<ol>
	<li>区域内格子数目 <strong>大于</strong>&nbsp;<code>1</code>&nbsp;且所有格子都是 <b>肥沃的</b>&nbsp;。</li>
	<li>倒金字塔的 <strong>顶端</strong>&nbsp;是这个倒金字塔 <strong>最下方</strong>&nbsp;的格子。倒金字塔的高度是它所覆盖的行数。令&nbsp;<code>(r, c)</code>&nbsp;为金字塔的顶端且高度为 <code>h</code>&nbsp;，那么金字塔区域内包含的任一格子&nbsp;<code>(i, j)</code>&nbsp;需满足&nbsp;<code>r - h + 1 &lt;= i &lt;= r</code> <strong>且</strong> <code>c - (r - i) &lt;= j &lt;= c + (r - i)</code>&nbsp;。</li>
</ol>

<p>下图展示了部分符合定义和不符合定义的金字塔区域。黑色区域表示肥沃的格子。</p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2088.Count%20Fertile%20Pyramids%20in%20a%20Land/images/image.png" style="width: 700px; height: 156px;"></p>

<p>给你一个下标从 <strong>0</strong>&nbsp;开始且大小为 <code>m x n</code>&nbsp;的二进制矩阵&nbsp;<code>grid</code>&nbsp;，它表示农场，请你返回 <code>grid</code>&nbsp;中金字塔和倒金字塔的&nbsp;<strong>总数目</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2088.Count%20Fertile%20Pyramids%20in%20a%20Land/images/eg11.png" style="width: 200px; height: 102px;">&nbsp;<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2088.Count%20Fertile%20Pyramids%20in%20a%20Land/images/exa12.png" style="width: 200px; height: 102px;">&nbsp;<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2088.Count%20Fertile%20Pyramids%20in%20a%20Land/images/exa13.png" style="width: 200px; height: 102px;"></p>

<pre><b>输入：</b>grid = [[0,1,1,0],[1,1,1,1]]
<b>输出：</b>2
<strong>解释：</strong>
2 个可能的金字塔区域分别如上图蓝色和红色区域所示。
这个网格图中没有倒金字塔区域。
所以金字塔区域总数为 2 + 0 = 2 。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2088.Count%20Fertile%20Pyramids%20in%20a%20Land/images/eg21.png" style="width: 180px; height: 122px;">&nbsp;<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2088.Count%20Fertile%20Pyramids%20in%20a%20Land/images/exa22.png" style="width: 180px; height: 122px;">&nbsp;<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2088.Count%20Fertile%20Pyramids%20in%20a%20Land/images/exa23.png" style="width: 180px; height: 122px;"></p>

<pre><b>输入：</b>grid = [[1,1,1],[1,1,1]]
<b>输出：</b>2
<strong>解释：</strong>
金字塔区域如上图蓝色区域所示，倒金字塔如上图红色区域所示。
所以金字塔区域总数目为 1 + 1 = 2 。
</pre>

<p><strong>示例 3：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2088.Count%20Fertile%20Pyramids%20in%20a%20Land/images/eg3.png" style="width: 149px; height: 150px;"></p>

<pre><b>输入：</b>grid = [[1,0,1],[0,0,0],[1,0,1]]
<b>输出：</b>0
<strong>解释：</strong>
网格图中没有任何金字塔或倒金字塔区域。
</pre>

<p><strong>示例 4：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2088.Count%20Fertile%20Pyramids%20in%20a%20Land/images/eg41.png" style="width: 180px; height: 144px;">&nbsp;<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2088.Count%20Fertile%20Pyramids%20in%20a%20Land/images/eg42.png" style="width: 180px; height: 144px;">&nbsp;<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2088.Count%20Fertile%20Pyramids%20in%20a%20Land/images/eg43.png" style="width: 180px; height: 144px;">&nbsp;<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2088.Count%20Fertile%20Pyramids%20in%20a%20Land/images/eg44.png" style="width: 180px; height: 144px;"></p>

<pre><strong>输入：</strong>grid = [[1,1,1,1,0],[1,1,1,1,1],[1,1,1,1,1],[0,1,0,0,1]]
<b>输出：</b>13
<strong>解释：</strong>
有 7 个金字塔区域。上图第二和第三张图中展示了它们中的 3 个。
有 6 个倒金字塔区域。上图中最后一张图展示了它们中的 2 个。
所以金字塔区域总数目为 7 + 6 = 13.
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 1000</code></li>
	<li><code>1 &lt;= m * n &lt;= 10<sup>5</sup></code></li>
	<li><code>grid[i][j]</code>&nbsp;要么是&nbsp;<code>0</code>&nbsp;，要么是&nbsp;<code>1</code> 。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i][j]$ 表示以 $(i, j)$ 为顶点的金字塔的最大高度，那么有如下状态转移方程：

$$
f[i][j] = \begin{cases} 0 & \textit{grid}[i][j] = 0 \\ \min(f[i + 1][j - 1], f[i + 1][j], f[i + 1][j + 1]) + 1 & \textit{grid}[i][j] = 1 \end{cases}
$$

因此，我们可以从下往上、从左往右遍历网格，计算出所有的 $f[i][j]$，并累加所有的 $f[i][j]$ 即可得到正金字塔的个数。

接下来，我们考虑倒金字塔的个数。与金字塔类似，我们定义 $g[i][j]$ 表示以 $(i, j)$ 为顶点的倒金字塔的最大高度，那么有如下状态转移方程：

$$
g[i][j] = \begin{cases} 0 & \textit{grid}[i][j] = 0 \\ \min(g[i - 1][j - 1], g[i - 1][j], g[i - 1][j + 1]) + 1 & \textit{grid}[i][j] = 1 \end{cases}
$$

因此，我们可以从上往下、从左往右遍历网格，计算出所有的 $g[i][j]$，并累加所有的 $g[i][j]$ 即可得到倒金字塔的个数。

最后，正金字塔的个数加上倒金字塔的个数即为答案。实际代码中，我们可以只用一个二维数组 $f[i][j]$ 即可。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别为网格的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countPyramids(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        f = [[0] * n for _ in range(m)]
        ans = 0
        for i in range(m - 1, -1, -1):
            for j in range(n):
                if grid[i][j] == 0:
                    f[i][j] = -1
                elif not (i == m - 1 or j == 0 or j == n - 1):
                    f[i][j] = min(f[i + 1][j - 1], f[i + 1][j], f[i + 1][j + 1]) + 1
                    ans += f[i][j]
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 0:
                    f[i][j] = -1
                elif i == 0 or j == 0 or j == n - 1:
                    f[i][j] = 0
                else:
                    f[i][j] = min(f[i - 1][j - 1], f[i - 1][j], f[i - 1][j + 1]) + 1
                    ans += f[i][j]
        return ans
```

#### Java

```java
class Solution {
    public int countPyramids(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int[][] f = new int[m][n];
        int ans = 0;
        for (int i = m - 1; i >= 0; --i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    f[i][j] = -1;
                } else if (i == m - 1 || j == 0 || j == n - 1) {
                    f[i][j] = 0;
                } else {
                    f[i][j] = Math.min(f[i + 1][j - 1], Math.min(f[i + 1][j], f[i + 1][j + 1])) + 1;
                    ans += f[i][j];
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    f[i][j] = -1;
                } else if (i == 0 || j == 0 || j == n - 1) {
                    f[i][j] = 0;
                } else {
                    f[i][j] = Math.min(f[i - 1][j - 1], Math.min(f[i - 1][j], f[i - 1][j + 1])) + 1;
                    ans += f[i][j];
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
    int countPyramids(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int f[m][n];
        int ans = 0;
        for (int i = m - 1; ~i; --i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    f[i][j] = -1;
                } else if (i == m - 1 || j == 0 || j == n - 1) {
                    f[i][j] = 0;
                } else {
                    f[i][j] = min({f[i + 1][j - 1], f[i + 1][j], f[i + 1][j + 1]}) + 1;
                    ans += f[i][j];
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    f[i][j] = -1;
                } else if (i == 0 || j == 0 || j == n - 1) {
                    f[i][j] = 0;
                } else {
                    f[i][j] = min({f[i - 1][j - 1], f[i - 1][j], f[i - 1][j + 1]}) + 1;
                    ans += f[i][j];
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func countPyramids(grid [][]int) (ans int) {
	m, n := len(grid), len(grid[0])
	f := make([][]int, m)
	for i := range f {
		f[i] = make([]int, n)
	}
	for i := m - 1; i >= 0; i-- {
		for j := 0; j < n; j++ {
			if grid[i][j] == 0 {
				f[i][j] = -1
			} else if i == m-1 || j == 0 || j == n-1 {
				f[i][j] = 0
			} else {
				f[i][j] = min(f[i+1][j-1], min(f[i+1][j], f[i+1][j+1])) + 1
				ans += f[i][j]
			}
		}
	}
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if grid[i][j] == 0 {
				f[i][j] = -1
			} else if i == 0 || j == 0 || j == n-1 {
				f[i][j] = 0
			} else {
				f[i][j] = min(f[i-1][j-1], min(f[i-1][j], f[i-1][j+1])) + 1
				ans += f[i][j]
			}
		}
	}
	return
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2089. 找出数组排序后的目标下标](https://leetcode.cn/problems/find-target-indices-after-sorting-array){#2089}

{{< tabs "2089" >}}

{{% tab "python" %}}
```python
class Solution:
    def targetIndices(self, nums: List[int], target: int) -> List[int]:
        nums.sort()
        return [i for i, v in enumerate(nums) if v == target]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<Integer> targetIndices(int[] nums, int target) {
        Arrays.sort(nums);
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < nums.length; ++i) {
            if (nums[i] == target) {
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
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == target) {
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
func targetIndices(nums []int, target int) (ans []int) {
	sort.Ints(nums)
	for i, v := range nums {
		if v == target {
			ans = append(ans, i)
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function targetIndices(nums: number[], target: number): number[] {
    nums.sort((a, b) => a - b);
    let ans: number[] = [];
    for (let i = 0; i < nums.length; ++i) {
        if (nums[i] == target) {
            ans.push(i);
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

<p>给你一个下标从 <strong>0</strong> 开始的整数数组 <code>nums</code> 以及一个目标元素 <code>target</code> 。</p>

<p><strong>目标下标</strong> 是一个满足&nbsp;<code>nums[i] == target</code> 的下标 <code>i</code> 。</p>

<p>将 <code>nums</code> 按 <strong>非递减</strong> 顺序排序后，返回由 <code>nums</code> 中目标下标组成的列表。如果不存在目标下标，返回一个 <strong>空</strong> 列表。返回的列表必须按 <strong>递增</strong> 顺序排列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [1,2,5,2,3], target = 2
<strong>输出：</strong>[1,2]
<strong>解释：</strong>排序后，nums 变为 [1,<em><strong>2</strong></em>,<em><strong>2</strong></em>,3,5] 。
满足 nums[i] == 2 的下标是 1 和 2 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [1,2,5,2,3], target = 3
<strong>输出：</strong>[3]
<strong>解释：</strong>排序后，nums 变为 [1,2,2,<em><strong>3</strong></em>,5] 。
满足 nums[i] == 3 的下标是 3 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>nums = [1,2,5,2,3], target = 5
<strong>输出：</strong>[4]
<strong>解释：</strong>排序后，nums 变为 [1,2,2,3,<em><strong>5</strong></em>] 。
满足 nums[i] == 5 的下标是 4 。
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>nums = [1,2,5,2,3], target = 4
<strong>输出：</strong>[]
<strong>解释：</strong>nums 中不含值为 4 的元素。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i], target &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序

将数组 `nums` 排序后，遍历数组，找出所有等于 `target` 的元素的下标，将其加入结果数组中。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 为数组 `nums` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def targetIndices(self, nums: List[int], target: int) -> List[int]:
        nums.sort()
        return [i for i, v in enumerate(nums) if v == target]
```

#### Java

```java
class Solution {
    public List<Integer> targetIndices(int[] nums, int target) {
        Arrays.sort(nums);
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < nums.length; ++i) {
            if (nums[i] == target) {
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
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == target) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func targetIndices(nums []int, target int) (ans []int) {
	sort.Ints(nums)
	for i, v := range nums {
		if v == target {
			ans = append(ans, i)
		}
	}
	return
}
```

#### TypeScript

```ts
function targetIndices(nums: number[], target: number): number[] {
    nums.sort((a, b) => a - b);
    let ans: number[] = [];
    for (let i = 0; i < nums.length; ++i) {
        if (nums[i] == target) {
            ans.push(i);
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
