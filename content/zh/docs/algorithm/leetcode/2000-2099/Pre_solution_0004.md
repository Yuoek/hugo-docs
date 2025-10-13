---
title: "2030_含特定字母的最小子序列"
date: 2025-10-08T18:38:57+08:00
weight: 4
tags: [二分查找, 位运算, 分治, 动态规划, 单调栈, 博弈, 双指针, 哈希表, 图, 堆（优先队列）, 字符串, 广度优先搜索, 归并排序, 排序, 数学, 数据流, 数组, 有序集合, 栈, 树状数组, 状态压缩, 矩阵, 线段树, 计数排序, 设计, 贪心]
---

{{< markmap >}}
### [2030_含特定字母的最小子序列](#2030)
#### [栈](#2030)
#### [贪心](#2030)
#### [字符串](#2030)
#### [单调栈](#2030)
### [2031_1 比 0 多的子数组个数 🔒](#2031)
#### [树状数组](#2031)
#### [线段树](#2031)
#### [数组](#2031)
#### [二分查找](#2031)
#### [分治](#2031)
#### [有序集合](#2031)
#### [归并排序](#2031)
### [2032_至少在两个数组中出现的值](#2032)
#### [位运算](#2032)
#### [数组](#2032)
#### [哈希表](#2032)
### [2033_获取单值网格的最小操作数](#2033)
#### [数组](#2033)
#### [数学](#2033)
#### [矩阵](#2033)
#### [排序](#2033)
### [2034_股票价格波动](#2034)
#### [设计](#2034)
#### [哈希表](#2034)
#### [数据流](#2034)
#### [有序集合](#2034)
#### [堆（优先队列）](#2034)
### [2035_将数组分成两个数组并最小化数组和的差](#2035)
#### [位运算](#2035)
#### [数组](#2035)
#### [双指针](#2035)
#### [二分查找](#2035)
#### [动态规划](#2035)
#### [状态压缩](#2035)
#### [有序集合](#2035)
### [2036_最大交替子数组和 🔒](#2036)
#### [数组](#2036)
#### [动态规划](#2036)
### [2037_使每位学生都有座位的最少移动次数](#2037)
#### [贪心](#2037)
#### [数组](#2037)
#### [计数排序](#2037)
#### [排序](#2037)
### [2038_如果相邻两个颜色均相同则删除当前颜色](#2038)
#### [贪心](#2038)
#### [数学](#2038)
#### [字符串](#2038)
#### [博弈](#2038)
### [2039_网络空闲的时刻](#2039)
#### [广度优先搜索](#2039)
#### [图](#2039)
#### [数组](#2039)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2030_含特定字母的最小子序列
___
#### 栈
___
#### 贪心
___
#### 字符串
___
#### 单调栈
---
### 2031_1 比 0 多的子数组个数 🔒
___
#### 树状数组
___
#### 线段树
___
#### 数组
___
#### 二分查找
___
#### 分治
___
#### 有序集合
___
#### 归并排序
---
### 2032_至少在两个数组中出现的值
___
#### 位运算
___
#### 数组
___
#### 哈希表
---
### 2033_获取单值网格的最小操作数
___
#### 数组
___
#### 数学
___
#### 矩阵
___
#### 排序
---
### 2034_股票价格波动
___
#### 设计
___
#### 哈希表
___
#### 数据流
___
#### 有序集合
___
#### 堆（优先队列）
---
### 2035_将数组分成两个数组并最小化数组和的差
___
#### 位运算
___
#### 数组
___
#### 双指针
___
#### 二分查找
___
#### 动态规划
___
#### 状态压缩
___
#### 有序集合
---
### 2036_最大交替子数组和 🔒
___
#### 数组
___
#### 动态规划
---
### 2037_使每位学生都有座位的最少移动次数
___
#### 贪心
___
#### 数组
___
#### 计数排序
___
#### 排序
---
### 2038_如果相邻两个颜色均相同则删除当前颜色
___
#### 贪心
___
#### 数学
___
#### 字符串
___
#### 博弈
---
### 2039_网络空闲的时刻
___
#### 广度优先搜索
___
#### 图
___
#### 数组
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 位运算 | 分治 |
| 动态规划 | 单调栈 | 博弈 |
| 双指针 | 哈希表 | 图 |
| 堆（优先队列） | 字符串 | 广度优先搜索 |
| 归并排序 | 排序 | 数学 |
| 数据流 | 数组 | 有序集合 |
| 栈 | 树状数组 | 状态压缩 |
| 矩阵 | 线段树 | 计数排序 |
| 设计 | 贪心 |  |

# [2030. 含特定字母的最小子序列](https://leetcode.cn/problems/smallest-k-length-subsequence-with-occurrences-of-a-letter){#2030}

{{< tabs "2030" >}}

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

<p>给你一个字符串 <code>s</code> ，一个整数 <code>k</code> ，一个字母 <code>letter</code> 以及另一个整数 <code>repetition</code> 。</p>

<p>返回 <code>s</code> 中长度为 <code>k</code> 且 <strong>字典序最小</strong> 的子序列，该子序列同时应满足字母 <code>letter</code> 出现<strong> 至少</strong> <code>repetition</code> 次。生成的测试用例满足 <code>letter</code> 在 <code>s</code> 中出现 <strong>至少</strong> <code>repetition</code> 次。</p>

<p><strong>子序列</strong> 是由原字符串删除一些（或不删除）字符且不改变剩余字符顺序得到的剩余字符串。</p>

<p>字符串 <code>a</code> 字典序比字符串 <code>b</code> 小的定义为：在 <code>a</code> 和 <code>b</code> 出现不同字符的第一个位置上，字符串 <code>a</code> 的字符在字母表中的顺序早于字符串 <code>b</code>&nbsp;的字符。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "leet", k = 3, letter = "e", repetition = 1
<strong>输出：</strong>"eet"
<strong>解释：</strong>存在 4 个长度为 3 ，且满足字母 'e' 出现至少 1 次的子序列：
- "lee"（"<em><strong>lee</strong></em>t"）
- "let"（"<em><strong>le</strong></em>e<em><strong>t</strong></em>"）
- "let"（"<em><strong>l</strong></em>e<em><strong>et</strong></em>"）
- "eet"（"l<em><strong>eet</strong></em>"）
其中字典序最小的子序列是 "eet" 。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="example-2" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2030.Smallest%20K-Length%20Subsequence%20With%20Occurrences%20of%20a%20Letter/images/smallest-k-length-subsequence.png" style="width: 339px; height: 67px;" /></p>

<pre>
<strong>输入：</strong>s = "leetcode", k = 4, letter = "e", repetition = 2
<strong>输出：</strong>"ecde"
<strong>解释：</strong>"ecde" 是长度为 4 且满足字母 "e" 出现至少 2 次的字典序最小的子序列。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "bb", k = 2, letter = "b", repetition = 2
<strong>输出：</strong>"bb"
<strong>解释：</strong>"bb" 是唯一一个长度为 2 且满足字母 "b" 出现至少 2 次的子序列。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= repetition &lt;= k &lt;= s.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>s</code> 由小写英文字母组成</li>
	<li><code>letter</code> 是一个小写英文字母，在 <code>s</code>&nbsp;中至少出现 <code>repetition</code> 次</li>
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

# [2031. 1 比 0 多的子数组个数 🔒](https://leetcode.cn/problems/count-subarrays-with-more-ones-than-zeros){#2031}

{{< tabs "2031" >}}

{{% tab "python" %}}
```python
class Solution:
    def subarraysWithMoreZerosThanOnes(self, nums: List[int]) -> int:
        sl = SortedList([0])
        mod = 10**9 + 7
        ans = s = 0
        for x in nums:
            s += x or -1
            ans += sl.bisect_left(s)
            ans %= mod
            sl.add(s)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class BinaryIndexedTree {
    private int n;
    private int[] c;

    public BinaryIndexedTree(int n) {
        this.n = n;
        c = new int[n + 1];
    }

    public void update(int x, int v) {
        for (; x <= n; x += x & -x) {
            c[x] += v;
        }
    }

    public int query(int x) {
        int s = 0;
        for (; x > 0; x -= x & -x) {
            s += c[x];
        }
        return s;
    }
}

class Solution {
    public int subarraysWithMoreZerosThanOnes(int[] nums) {
        int n = nums.length;
        int base = n + 1;
        BinaryIndexedTree tree = new BinaryIndexedTree(n + base);
        tree.update(base, 1);
        final int mod = (int) 1e9 + 7;
        int ans = 0, s = 0;
        for (int x : nums) {
            s += x == 0 ? -1 : 1;
            ans += tree.query(s - 1 + base);
            ans %= mod;
            tree.update(s + base, 1);
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
    int n;
    vector<int> c;

public:
    BinaryIndexedTree(int n)
        : n(n)
        , c(n + 1, 0) {}

    void update(int x, int v) {
        for (; x <= n; x += x & -x) {
            c[x] += v;
        }
    }

    int query(int x) {
        int s = 0;
        for (; x > 0; x -= x & -x) {
            s += c[x];
        }
        return s;
    }
};

class Solution {
public:
    int subarraysWithMoreZerosThanOnes(vector<int>& nums) {
        int n = nums.size();
        int base = n + 1;
        BinaryIndexedTree tree(n + base);
        tree.update(base, 1);
        const int mod = 1e9 + 7;
        int ans = 0, s = 0;
        for (int x : nums) {
            s += (x == 0) ? -1 : 1;
            ans += tree.query(s - 1 + base);
            ans %= mod;
            tree.update(s + base, 1);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
type BinaryIndexedTree struct {
	n int
	c []int
}

func newBinaryIndexedTree(n int) *BinaryIndexedTree {
	return &BinaryIndexedTree{n: n, c: make([]int, n+1)}
}

func (bit *BinaryIndexedTree) update(x, v int) {
	for ; x <= bit.n; x += x & -x {
		bit.c[x] += v
	}
}

func (bit *BinaryIndexedTree) query(x int) (s int) {
	for ; x > 0; x -= x & -x {
		s += bit.c[x]
	}
	return
}

func subarraysWithMoreZerosThanOnes(nums []int) (ans int) {
	n := len(nums)
	base := n + 1
	tree := newBinaryIndexedTree(n + base)
	tree.update(base, 1)
	const mod = int(1e9) + 7
	s := 0
	for _, x := range nums {
		if x == 0 {
			s--
		} else {
			s++
		}
		ans += tree.query(s - 1 + base)
		ans %= mod
		tree.update(s+base, 1)
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class BinaryIndexedTree {
    private n: number;
    private c: number[];

    constructor(n: number) {
        this.n = n;
        this.c = Array(n + 1).fill(0);
    }

    update(x: number, v: number): void {
        for (; x <= this.n; x += x & -x) {
            this.c[x] += v;
        }
    }

    query(x: number): number {
        let s = 0;
        for (; x > 0; x -= x & -x) {
            s += this.c[x];
        }
        return s;
    }
}

function subarraysWithMoreZerosThanOnes(nums: number[]): number {
    const n: number = nums.length;
    const base: number = n + 1;
    const tree: BinaryIndexedTree = new BinaryIndexedTree(n + base);
    tree.update(base, 1);
    const mod: number = 1e9 + 7;
    let ans: number = 0;
    let s: number = 0;
    for (const x of nums) {
        s += x || -1;
        ans += tree.query(s - 1 + base);
        ans %= mod;
        tree.update(s + base, 1);
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

<p>给你一个只包含 <code>0</code> 和 <code>1</code> 的数组 <code>nums</code>，请返回 <code>1</code> 的数量 <strong>大于 </strong><code>0</code> 的数量的子数组的个数。由于答案可能很大，请返回答案对&nbsp;<code>10<sup>9</sup>&nbsp;+ 7</code>&nbsp;<strong>取余</strong>&nbsp;的结果。</p>

<p>一个 <strong>子数组</strong> 指的是原数组中连续的一个子序列。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> nums = [0,1,1,0,1]
<strong>输出:</strong> 9
<strong>解释:</strong>
长度为 1 的、1 的数量大于 0 的数量的子数组有: [1], [1], [1]
长度为 2 的、1 的数量大于 0 的数量的子数组有: [1,1]
长度为 3 的、1 的数量大于 0 的数量的子数组有: [0,1,1], [1,1,0], [1,0,1]
长度为 4 的、1 的数量大于 0 的数量的子数组有: [1,1,0,1]
长度为 5 的、1 的数量大于 0 的数量的子数组有: [0,1,1,0,1]
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> nums = [0]
<strong>输出:</strong> 0
<strong>解释:</strong>
没有子数组的 1 的数量大于 0 的数量。
</pre>

<p><strong>示例 3:</strong></p>

<pre><strong>输入:</strong> nums = [1]
<strong>输出:</strong> 1
<strong>解释:</strong>
长度为 1 的、1 的数量大于 0 的数量的子数组有: [1]
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前缀和 + 树状数组

题目需要我们统计所有子数组中 $1$ 的数量大于 $0$ 的数量的子数组的个数，如果我们将数组中的元素 $0$ 看作 $-1$，那么题目就变成了统计所有子数组中元素和大于 $0$ 的子数组的个数。

求子数组的元素和，可以使用前缀和来实现。为了统计所有子数组中元素和大于 $0$ 的子数组的个数，我们可以用树状数组维护每个前缀和出现的次数。初始时前缀和为 $0$ 的次数为 $1$。

接下来，我们遍历数组 $nums$，用变量 $s$ 记录当前的前缀和，用变量 $ans$ 记录答案。对于每个位置 $i$，更新前缀和 $s$，然后我们在树状数组中查询 $[0, s)$ 范围内的前缀和出现的次数，将其加到 $ans$ 中，然后在树状数组中更新 $s$ 出现的次数。

最后返回 $ans$ 即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class BinaryIndexedTree:
    __slots__ = ["n", "c"]

    def __init__(self, n: int):
        self.n = n
        self.c = [0] * (n + 1)

    def update(self, x: int, v: int):
        while x <= self.n:
            self.c[x] += v
            x += x & -x

    def query(self, x: int) -> int:
        s = 0
        while x:
            s += self.c[x]
            x -= x & -x
        return s


class Solution:
    def subarraysWithMoreZerosThanOnes(self, nums: List[int]) -> int:
        n = len(nums)
        base = n + 1
        tree = BinaryIndexedTree(n + base)
        tree.update(base, 1)
        mod = 10**9 + 7
        ans = s = 0
        for x in nums:
            s += x or -1
            ans += tree.query(s - 1 + base)
            ans %= mod
            tree.update(s + base, 1)
        return ans
```

#### Java

```java
class BinaryIndexedTree {
    private int n;
    private int[] c;

    public BinaryIndexedTree(int n) {
        this.n = n;
        c = new int[n + 1];
    }

    public void update(int x, int v) {
        for (; x <= n; x += x & -x) {
            c[x] += v;
        }
    }

    public int query(int x) {
        int s = 0;
        for (; x > 0; x -= x & -x) {
            s += c[x];
        }
        return s;
    }
}

class Solution {
    public int subarraysWithMoreZerosThanOnes(int[] nums) {
        int n = nums.length;
        int base = n + 1;
        BinaryIndexedTree tree = new BinaryIndexedTree(n + base);
        tree.update(base, 1);
        final int mod = (int) 1e9 + 7;
        int ans = 0, s = 0;
        for (int x : nums) {
            s += x == 0 ? -1 : 1;
            ans += tree.query(s - 1 + base);
            ans %= mod;
            tree.update(s + base, 1);
        }
        return ans;
    }
}
```

#### C++

```cpp
class BinaryIndexedTree {
private:
    int n;
    vector<int> c;

public:
    BinaryIndexedTree(int n)
        : n(n)
        , c(n + 1, 0) {}

    void update(int x, int v) {
        for (; x <= n; x += x & -x) {
            c[x] += v;
        }
    }

    int query(int x) {
        int s = 0;
        for (; x > 0; x -= x & -x) {
            s += c[x];
        }
        return s;
    }
};

class Solution {
public:
    int subarraysWithMoreZerosThanOnes(vector<int>& nums) {
        int n = nums.size();
        int base = n + 1;
        BinaryIndexedTree tree(n + base);
        tree.update(base, 1);
        const int mod = 1e9 + 7;
        int ans = 0, s = 0;
        for (int x : nums) {
            s += (x == 0) ? -1 : 1;
            ans += tree.query(s - 1 + base);
            ans %= mod;
            tree.update(s + base, 1);
        }
        return ans;
    }
};
```

#### Go

```go
type BinaryIndexedTree struct {
	n int
	c []int
}

func newBinaryIndexedTree(n int) *BinaryIndexedTree {
	return &BinaryIndexedTree{n: n, c: make([]int, n+1)}
}

func (bit *BinaryIndexedTree) update(x, v int) {
	for ; x <= bit.n; x += x & -x {
		bit.c[x] += v
	}
}

func (bit *BinaryIndexedTree) query(x int) (s int) {
	for ; x > 0; x -= x & -x {
		s += bit.c[x]
	}
	return
}

func subarraysWithMoreZerosThanOnes(nums []int) (ans int) {
	n := len(nums)
	base := n + 1
	tree := newBinaryIndexedTree(n + base)
	tree.update(base, 1)
	const mod = int(1e9) + 7
	s := 0
	for _, x := range nums {
		if x == 0 {
			s--
		} else {
			s++
		}
		ans += tree.query(s - 1 + base)
		ans %= mod
		tree.update(s+base, 1)
	}
	return
}
```

#### TypeScript

```ts
class BinaryIndexedTree {
    private n: number;
    private c: number[];

    constructor(n: number) {
        this.n = n;
        this.c = Array(n + 1).fill(0);
    }

    update(x: number, v: number): void {
        for (; x <= this.n; x += x & -x) {
            this.c[x] += v;
        }
    }

    query(x: number): number {
        let s = 0;
        for (; x > 0; x -= x & -x) {
            s += this.c[x];
        }
        return s;
    }
}

function subarraysWithMoreZerosThanOnes(nums: number[]): number {
    const n: number = nums.length;
    const base: number = n + 1;
    const tree: BinaryIndexedTree = new BinaryIndexedTree(n + base);
    tree.update(base, 1);
    const mod: number = 1e9 + 7;
    let ans: number = 0;
    let s: number = 0;
    for (const x of nums) {
        s += x || -1;
        ans += tree.query(s - 1 + base);
        ans %= mod;
        tree.update(s + base, 1);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def subarraysWithMoreZerosThanOnes(self, nums: List[int]) -> int:
        sl = SortedList([0])
        mod = 10**9 + 7
        ans = s = 0
        for x in nums:
            s += x or -1
            ans += sl.bisect_left(s)
            ans %= mod
            sl.add(s)
        return ans
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2032. 至少在两个数组中出现的值](https://leetcode.cn/problems/two-out-of-three){#2032}

{{< tabs "2032" >}}

{{% tab "python" %}}
```python
class Solution:
    def twoOutOfThree(
        self, nums1: List[int], nums2: List[int], nums3: List[int]
    ) -> List[int]:
        s1, s2, s3 = set(nums1), set(nums2), set(nums3)
        return [i for i in range(1, 101) if (i in s1) + (i in s2) + (i in s3) > 1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<Integer> twoOutOfThree(int[] nums1, int[] nums2, int[] nums3) {
        int[] s1 = get(nums1), s2 = get(nums2), s3 = get(nums3);
        List<Integer> ans = new ArrayList<>();
        for (int i = 1; i <= 100; ++i) {
            if (s1[i] + s2[i] + s3[i] > 1) {
                ans.add(i);
            }
        }
        return ans;
    }

    private int[] get(int[] nums) {
        int[] s = new int[101];
        for (int num : nums) {
            s[num] = 1;
        }
        return s;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        auto get = [](vector<int>& nums) {
            vector<int> cnt(101);
            for (int& v : nums) cnt[v] = 1;
            return cnt;
        };
        auto s1 = get(nums1), s2 = get(nums2), s3 = get(nums3);
        vector<int> ans;
        for (int i = 1; i <= 100; ++i) {
            if (s1[i] + s2[i] + s3[i] > 1) {
                ans.emplace_back(i);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func twoOutOfThree(nums1 []int, nums2 []int, nums3 []int) (ans []int) {
	get := func(nums []int) (s [101]int) {
		for _, v := range nums {
			s[v] = 1
		}
		return
	}
	s1, s2, s3 := get(nums1), get(nums2), get(nums3)
	for i := 1; i <= 100; i++ {
		if s1[i]+s2[i]+s3[i] > 1 {
			ans = append(ans, i)
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function twoOutOfThree(nums1: number[], nums2: number[], nums3: number[]): number[] {
    const count = new Array(101).fill(0);
    new Set(nums1).forEach(v => count[v]++);
    new Set(nums2).forEach(v => count[v]++);
    new Set(nums3).forEach(v => count[v]++);
    const ans = [];
    count.forEach((v, i) => {
        if (v >= 2) {
            ans.push(i);
        }
    });
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashSet;
impl Solution {
    pub fn two_out_of_three(nums1: Vec<i32>, nums2: Vec<i32>, nums3: Vec<i32>) -> Vec<i32> {
        let mut count = vec![0; 101];
        nums1
            .into_iter()
            .collect::<HashSet<i32>>()
            .iter()
            .for_each(|&v| {
                count[v as usize] += 1;
            });
        nums2
            .into_iter()
            .collect::<HashSet<i32>>()
            .iter()
            .for_each(|&v| {
                count[v as usize] += 1;
            });
        nums3
            .into_iter()
            .collect::<HashSet<i32>>()
            .iter()
            .for_each(|&v| {
                count[v as usize] += 1;
            });
        let mut ans = Vec::new();
        count.iter().enumerate().for_each(|(i, v)| {
            if *v >= 2 {
                ans.push(i as i32);
            }
        });
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

给你三个整数数组 <code>nums1</code>、<code>nums2</code> 和 <code>nums3</code> ，请你构造并返回一个 <strong>元素各不相同的</strong> 数组，且由 <strong>至少</strong> 在 <strong>两个</strong> 数组中出现的所有值组成<em>。</em>数组中的元素可以按 <strong>任意</strong> 顺序排列。

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums1 = [1,1,3,2], nums2 = [2,3], nums3 = [3]
<strong>输出：</strong>[3,2]
<strong>解释：</strong>至少在两个数组中出现的所有值为：
- 3 ，在全部三个数组中都出现过。
- 2 ，在数组 nums1 和 nums2 中出现过。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums1 = [3,1], nums2 = [2,3], nums3 = [1,2]
<strong>输出：</strong>[2,3,1]
<strong>解释：</strong>至少在两个数组中出现的所有值为：
- 2 ，在数组 nums2 和 nums3 中出现过。
- 3 ，在数组 nums1 和 nums2 中出现过。
- 1 ，在数组 nums1 和 nums3 中出现过。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums1 = [1,2,2], nums2 = [4,3,3], nums3 = [5]
<strong>输出：</strong>[]
<strong>解释：</strong>不存在至少在两个数组中出现的值。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums1.length, nums2.length, nums3.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums1[i], nums2[j], nums3[k] &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数组 + 枚举

我们可以先将每个数组中的元素放入数组中，然后枚举 $1$ 到 $100$ 中的每个数 $i$，判断 $i$ 是否在至少两个数组中出现过。若是，则将 $i$ 加入答案数组中。

时间复杂度 $O(n_1 + n_2 + n_3)$，空间复杂度 $O(n_1 + n_2 + n_3)$。其中 $n_1, n_2, n_3$ 分别为数组 `nums1`、`nums2` 和 `nums3` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def twoOutOfThree(
        self, nums1: List[int], nums2: List[int], nums3: List[int]
    ) -> List[int]:
        s1, s2, s3 = set(nums1), set(nums2), set(nums3)
        return [i for i in range(1, 101) if (i in s1) + (i in s2) + (i in s3) > 1]
```

#### Java

```java
class Solution {
    public List<Integer> twoOutOfThree(int[] nums1, int[] nums2, int[] nums3) {
        int[] s1 = get(nums1), s2 = get(nums2), s3 = get(nums3);
        List<Integer> ans = new ArrayList<>();
        for (int i = 1; i <= 100; ++i) {
            if (s1[i] + s2[i] + s3[i] > 1) {
                ans.add(i);
            }
        }
        return ans;
    }

    private int[] get(int[] nums) {
        int[] s = new int[101];
        for (int num : nums) {
            s[num] = 1;
        }
        return s;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        auto get = [](vector<int>& nums) {
            vector<int> cnt(101);
            for (int& v : nums) cnt[v] = 1;
            return cnt;
        };
        auto s1 = get(nums1), s2 = get(nums2), s3 = get(nums3);
        vector<int> ans;
        for (int i = 1; i <= 100; ++i) {
            if (s1[i] + s2[i] + s3[i] > 1) {
                ans.emplace_back(i);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func twoOutOfThree(nums1 []int, nums2 []int, nums3 []int) (ans []int) {
	get := func(nums []int) (s [101]int) {
		for _, v := range nums {
			s[v] = 1
		}
		return
	}
	s1, s2, s3 := get(nums1), get(nums2), get(nums3)
	for i := 1; i <= 100; i++ {
		if s1[i]+s2[i]+s3[i] > 1 {
			ans = append(ans, i)
		}
	}
	return
}
```

#### TypeScript

```ts
function twoOutOfThree(nums1: number[], nums2: number[], nums3: number[]): number[] {
    const count = new Array(101).fill(0);
    new Set(nums1).forEach(v => count[v]++);
    new Set(nums2).forEach(v => count[v]++);
    new Set(nums3).forEach(v => count[v]++);
    const ans = [];
    count.forEach((v, i) => {
        if (v >= 2) {
            ans.push(i);
        }
    });
    return ans;
}
```

#### Rust

```rust
use std::collections::HashSet;
impl Solution {
    pub fn two_out_of_three(nums1: Vec<i32>, nums2: Vec<i32>, nums3: Vec<i32>) -> Vec<i32> {
        let mut count = vec![0; 101];
        nums1
            .into_iter()
            .collect::<HashSet<i32>>()
            .iter()
            .for_each(|&v| {
                count[v as usize] += 1;
            });
        nums2
            .into_iter()
            .collect::<HashSet<i32>>()
            .iter()
            .for_each(|&v| {
                count[v as usize] += 1;
            });
        nums3
            .into_iter()
            .collect::<HashSet<i32>>()
            .iter()
            .for_each(|&v| {
                count[v as usize] += 1;
            });
        let mut ans = Vec::new();
        count.iter().enumerate().for_each(|(i, v)| {
            if *v >= 2 {
                ans.push(i as i32);
            }
        });
        ans
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2033. 获取单值网格的最小操作数](https://leetcode.cn/problems/minimum-operations-to-make-a-uni-value-grid){#2033}

{{< tabs "2033" >}}

{{% tab "python" %}}
```python
class Solution:
    def minOperations(self, grid: List[List[int]], x: int) -> int:
        nums = []
        mod = grid[0][0] % x
        for row in grid:
            for v in row:
                if v % x != mod:
                    return -1
                nums.append(v)
        nums.sort()
        mid = nums[len(nums) >> 1]
        return sum(abs(v - mid) // x for v in nums)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minOperations(int[][] grid, int x) {
        int m = grid.length, n = grid[0].length;
        int[] nums = new int[m * n];
        int mod = grid[0][0] % x;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] % x != mod) {
                    return -1;
                }
                nums[i * n + j] = grid[i][j];
            }
        }
        Arrays.sort(nums);
        int mid = nums[nums.length >> 1];
        int ans = 0;
        for (int v : nums) {
            ans += Math.abs(v - mid) / x;
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
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size(), n = grid[0].size();
        int mod = grid[0][0] % x;
        int nums[m * n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] % x != mod) {
                    return -1;
                }
                nums[i * n + j] = grid[i][j];
            }
        }
        sort(nums, nums + m * n);
        int mid = nums[(m * n) >> 1];
        int ans = 0;
        for (int v : nums) {
            ans += abs(v - mid) / x;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minOperations(grid [][]int, x int) int {
	mod := grid[0][0] % x
	nums := []int{}
	for _, row := range grid {
		for _, v := range row {
			if v%x != mod {
				return -1
			}
			nums = append(nums, v)
		}
	}
	sort.Ints(nums)
	mid := nums[len(nums)>>1]
	ans := 0
	for _, v := range nums {
		ans += abs(v-mid) / x
	}
	return ans
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
function minOperations(grid: number[][], x: number): number {
    const arr = grid.flat(2);
    arr.sort((a, b) => a - b);
    const median = arr[Math.floor(arr.length / 2)];

    let res = 0;
    for (const val of arr) {
        const c = Math.abs(val - median) / x;
        if (c !== (c | 0)) return -1;
        res += c;
    }

    return res;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
function minOperations(grid, x) {
    const arr = grid.flat(2);
    arr.sort((a, b) => a - b);
    const median = arr[Math.floor(arr.length / 2)];

    let res = 0;
    for (const val of arr) {
        const c = Math.abs(val - median) / x;
        if (c !== (c | 0)) return -1;
        res += c;
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

<p>给你一个大小为&nbsp;<code>m x n</code> 的二维整数网格 <code>grid</code> 和一个整数 <code>x</code> 。每一次操作，你可以对 <code>grid</code> 中的任一元素 <strong>加</strong> <code>x</code> 或 <strong>减</strong> <code>x</code> 。</p>

<p><strong>单值网格</strong> 是全部元素都相等的网格。</p>

<p>返回使网格化为单值网格所需的 <strong>最小</strong> 操作数。如果不能，返回 <code>-1</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2033.Minimum%20Operations%20to%20Make%20a%20Uni-Value%20Grid/images/gridtxt.png" style="width: 164px; height: 165px;" /></p>

<pre>
<strong>输入：</strong>grid = [[2,4],[6,8]], x = 2
<strong>输出：</strong>4
<strong>解释：</strong>可以执行下述操作使所有元素都等于 4 ： 
- 2 加 x 一次。
- 6 减 x 一次。
- 8 减 x 两次。
共计 4 次操作。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2033.Minimum%20Operations%20to%20Make%20a%20Uni-Value%20Grid/images/gridtxt-1.png" style="width: 164px; height: 165px;" /></p>

<pre>
<strong>输入：</strong>grid = [[1,5],[2,3]], x = 1
<strong>输出：</strong>5
<strong>解释：</strong>可以使所有元素都等于 3 。
</pre>

<p><strong>示例 3：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2033.Minimum%20Operations%20to%20Make%20a%20Uni-Value%20Grid/images/gridtxt-2.png" style="width: 164px; height: 165px;" /></p>

<pre>
<strong>输入：</strong>grid = [[1,2],[3,4]], x = 2
<strong>输出：</strong>-1
<strong>解释：</strong>无法使所有元素相等。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= m * n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= x, grid[i][j] &lt;= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心

首先，要使得网格化为单值网格，那么网格的所有元素与 $x$ 的余数必须相同。

因此，我们可以先遍历网格，判断所有元素与 $x$ 的余数是否相同，若不同则返回 $-1$。否则，我们将所有元素放入数组中，对数组进行排序，取中位数，然后遍历数组，计算每个元素与中位数的差值，再除以 $x$，将所有的差值相加，即为答案。

时间复杂度 $O((m \times n) \times \log (m \times n))$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别为网格的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minOperations(self, grid: List[List[int]], x: int) -> int:
        nums = []
        mod = grid[0][0] % x
        for row in grid:
            for v in row:
                if v % x != mod:
                    return -1
                nums.append(v)
        nums.sort()
        mid = nums[len(nums) >> 1]
        return sum(abs(v - mid) // x for v in nums)
```

#### Java

```java
class Solution {
    public int minOperations(int[][] grid, int x) {
        int m = grid.length, n = grid[0].length;
        int[] nums = new int[m * n];
        int mod = grid[0][0] % x;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] % x != mod) {
                    return -1;
                }
                nums[i * n + j] = grid[i][j];
            }
        }
        Arrays.sort(nums);
        int mid = nums[nums.length >> 1];
        int ans = 0;
        for (int v : nums) {
            ans += Math.abs(v - mid) / x;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size(), n = grid[0].size();
        int mod = grid[0][0] % x;
        int nums[m * n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] % x != mod) {
                    return -1;
                }
                nums[i * n + j] = grid[i][j];
            }
        }
        sort(nums, nums + m * n);
        int mid = nums[(m * n) >> 1];
        int ans = 0;
        for (int v : nums) {
            ans += abs(v - mid) / x;
        }
        return ans;
    }
};
```

#### Go

```go
func minOperations(grid [][]int, x int) int {
	mod := grid[0][0] % x
	nums := []int{}
	for _, row := range grid {
		for _, v := range row {
			if v%x != mod {
				return -1
			}
			nums = append(nums, v)
		}
	}
	sort.Ints(nums)
	mid := nums[len(nums)>>1]
	ans := 0
	for _, v := range nums {
		ans += abs(v-mid) / x
	}
	return ans
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
function minOperations(grid: number[][], x: number): number {
    const arr = grid.flat(2);
    arr.sort((a, b) => a - b);
    const median = arr[Math.floor(arr.length / 2)];

    let res = 0;
    for (const val of arr) {
        const c = Math.abs(val - median) / x;
        if (c !== (c | 0)) return -1;
        res += c;
    }

    return res;
}
```

#### JavaScript

```js
function minOperations(grid, x) {
    const arr = grid.flat(2);
    arr.sort((a, b) => a - b);
    const median = arr[Math.floor(arr.length / 2)];

    let res = 0;
    for (const val of arr) {
        const c = Math.abs(val - median) / x;
        if (c !== (c | 0)) return -1;
        res += c;
    }

    return res;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2034. 股票价格波动](https://leetcode.cn/problems/stock-price-fluctuation){#2034}

{{< tabs "2034" >}}

{{% tab "python" %}}
```python
class StockPrice:
    def __init__(self):
        self.d = {}
        self.ls = SortedList()
        self.last = 0

    def update(self, timestamp: int, price: int) -> None:
        if timestamp in self.d:
            self.ls.remove(self.d[timestamp])
        self.d[timestamp] = price
        self.ls.add(price)
        self.last = max(self.last, timestamp)

    def current(self) -> int:
        return self.d[self.last]

    def maximum(self) -> int:
        return self.ls[-1]

    def minimum(self) -> int:
        return self.ls[0]


# Your StockPrice object will be instantiated and called as such:
# obj = StockPrice()
# obj.update(timestamp,price)
# param_2 = obj.current()
# param_3 = obj.maximum()
# param_4 = obj.minimum()
```
{{% /tab %}}
{{% tab "java" %}}
```java
class StockPrice {
    private Map<Integer, Integer> d = new HashMap<>();
    private TreeMap<Integer, Integer> ls = new TreeMap<>();
    private int last;

    public StockPrice() {
    }

    public void update(int timestamp, int price) {
        if (d.containsKey(timestamp)) {
            int old = d.get(timestamp);
            if (ls.merge(old, -1, Integer::sum) == 0) {
                ls.remove(old);
            }
        }
        d.put(timestamp, price);
        ls.merge(price, 1, Integer::sum);
        last = Math.max(last, timestamp);
    }

    public int current() {
        return d.get(last);
    }

    public int maximum() {
        return ls.lastKey();
    }

    public int minimum() {
        return ls.firstKey();
    }
}

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice obj = new StockPrice();
 * obj.update(timestamp,price);
 * int param_2 = obj.current();
 * int param_3 = obj.maximum();
 * int param_4 = obj.minimum();
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class StockPrice {
public:
    StockPrice() {
    }

    void update(int timestamp, int price) {
        if (d.count(timestamp)) {
            ls.erase(ls.find(d[timestamp]));
        }
        d[timestamp] = price;
        ls.insert(price);
        last = max(last, timestamp);
    }

    int current() {
        return d[last];
    }

    int maximum() {
        return *ls.rbegin();
    }

    int minimum() {
        return *ls.begin();
    }

private:
    unordered_map<int, int> d;
    multiset<int> ls;
    int last = 0;
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type StockPrice struct {
	d    map[int]int
	ls   *redblacktree.Tree
	last int
}

func Constructor() StockPrice {
	return StockPrice{
		d:    make(map[int]int),
		ls:   redblacktree.NewWithIntComparator(),
		last: 0,
	}
}

func (this *StockPrice) Update(timestamp int, price int) {
	merge := func(rbt *redblacktree.Tree, key, value int) {
		if v, ok := rbt.Get(key); ok {
			nxt := v.(int) + value
			if nxt == 0 {
				rbt.Remove(key)
			} else {
				rbt.Put(key, nxt)
			}
		} else {
			rbt.Put(key, value)
		}
	}
	if v, ok := this.d[timestamp]; ok {
		merge(this.ls, v, -1)
	}
	this.d[timestamp] = price
	merge(this.ls, price, 1)
	this.last = max(this.last, timestamp)
}

func (this *StockPrice) Current() int {
	return this.d[this.last]
}

func (this *StockPrice) Maximum() int {
	return this.ls.Right().Key.(int)
}

func (this *StockPrice) Minimum() int {
	return this.ls.Left().Key.(int)
}

/**
 * Your StockPrice object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Update(timestamp,price);
 * param_2 := obj.Current();
 * param_3 := obj.Maximum();
 * param_4 := obj.Minimum();
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一支股票价格的数据流。数据流中每一条记录包含一个 <strong>时间戳</strong>&nbsp;和该时间点股票对应的 <strong>价格</strong>&nbsp;。</p>

<p>不巧的是，由于股票市场内在的波动性，股票价格记录可能不是按时间顺序到来的。某些情况下，有的记录可能是错的。如果两个有相同时间戳的记录出现在数据流中，前一条记录视为错误记录，后出现的记录 <b>更正</b>&nbsp;前一条错误的记录。</p>

<p>请你设计一个算法，实现：</p>

<ul>
	<li><strong>更新 </strong>股票在某一时间戳的股票价格，如果有之前同一时间戳的价格，这一操作将&nbsp;<strong>更正</strong>&nbsp;之前的错误价格。</li>
	<li>找到当前记录里 <b>最新股票价格</b>&nbsp;。<strong>最新股票价格</strong>&nbsp;定义为时间戳最晚的股票价格。</li>
	<li>找到当前记录里股票的 <strong>最高价格</strong>&nbsp;。</li>
	<li>找到当前记录里股票的 <strong>最低价格</strong>&nbsp;。</li>
</ul>

<p>请你实现&nbsp;<code>StockPrice</code>&nbsp;类：</p>

<ul>
	<li><code>StockPrice()</code>&nbsp;初始化对象，当前无股票价格记录。</li>
	<li><code>void update(int timestamp, int price)</code>&nbsp;在时间点 <code>timestamp</code>&nbsp;更新股票价格为 <code>price</code>&nbsp;。</li>
	<li><code>int current()</code>&nbsp;返回股票 <strong>最新价格</strong>&nbsp;。</li>
	<li><code>int maximum()</code>&nbsp;返回股票 <strong>最高价格</strong>&nbsp;。</li>
	<li><code>int minimum()</code>&nbsp;返回股票 <strong>最低价格</strong>&nbsp;。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>
["StockPrice", "update", "update", "current", "maximum", "update", "maximum", "update", "minimum"]
[[], [1, 10], [2, 5], [], [], [1, 3], [], [4, 2], []]
<strong>输出：</strong>
[null, null, null, 5, 10, null, 5, null, 2]

<strong>解释：</strong>
StockPrice stockPrice = new StockPrice();
stockPrice.update(1, 10); // 时间戳为 [1] ，对应的股票价格为 [10] 。
stockPrice.update(2, 5);  // 时间戳为 [1,2] ，对应的股票价格为 [10,5] 。
stockPrice.current();     // 返回 5 ，最新时间戳为 2 ，对应价格为 5 。
stockPrice.maximum();     // 返回 10 ，最高价格的时间戳为 1 ，价格为 10 。
stockPrice.update(1, 3);  // 之前时间戳为 1 的价格错误，价格更新为 3 。
                          // 时间戳为 [1,2] ，对应股票价格为 [3,5] 。
stockPrice.maximum();     // 返回 5 ，更正后最高价格为 5 。
stockPrice.update(4, 2);  // 时间戳为 [1,2,4] ，对应价格为 [3,5,2] 。
stockPrice.minimum();     // 返回 2 ，最低价格时间戳为 4 ，价格为 2 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= timestamp, price &lt;= 10<sup>9</sup></code></li>
	<li><code>update</code>，<code>current</code>，<code>maximum</code>&nbsp;和&nbsp;<code>minimum</code>&nbsp;<strong>总</strong> 调用次数不超过&nbsp;<code>10<sup>5</sup></code>&nbsp;。</li>
	<li><code>current</code>，<code>maximum</code>&nbsp;和&nbsp;<code>minimum</code>&nbsp;被调用时，<code>update</code>&nbsp;操作 <strong>至少</strong>&nbsp;已经被调用过 <strong>一次</strong>&nbsp;。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 有序集合

我们定义以下几个数据结构或变量，其中：

-   `d`：表示一个哈希表，用于存储时间戳和对应的价格；
-   `ls`：表示一个有序集合，用于存储所有的价格；
-   `last`：表示最后一次更新的时间戳。

那么，我们可以得到以下几个操作：

-   `update(timestamp, price)`：更新时间戳 `timestamp` 对应的价格为 `price`。如果 `timestamp` 已经存在，那么我们需要先将其对应的价格从有序集合中删除，再将其更新为 `price`。否则，我们直接将其更新为 `price`。然后，我们需要更新 `last` 为 `max(last, timestamp)`。时间复杂度为 $O(\log n)$。
-   `current()`：返回 `last` 对应的价格。时间复杂度为 $O(1)$。
-   `maximum()`：返回有序集合中的最大值。时间复杂度为 $O(\log n)$。
-   `minimum()`：返回有序集合中的最小值。时间复杂度为 $O(\log n)$。

空间复杂度为 $O(n)$。其中，$n$ 为 `update` 操作的次数。

<!-- tabs:start -->

#### Python3

```python
class StockPrice:
    def __init__(self):
        self.d = {}
        self.ls = SortedList()
        self.last = 0

    def update(self, timestamp: int, price: int) -> None:
        if timestamp in self.d:
            self.ls.remove(self.d[timestamp])
        self.d[timestamp] = price
        self.ls.add(price)
        self.last = max(self.last, timestamp)

    def current(self) -> int:
        return self.d[self.last]

    def maximum(self) -> int:
        return self.ls[-1]

    def minimum(self) -> int:
        return self.ls[0]


# Your StockPrice object will be instantiated and called as such:
# obj = StockPrice()
# obj.update(timestamp,price)
# param_2 = obj.current()
# param_3 = obj.maximum()
# param_4 = obj.minimum()
```

#### Java

```java
class StockPrice {
    private Map<Integer, Integer> d = new HashMap<>();
    private TreeMap<Integer, Integer> ls = new TreeMap<>();
    private int last;

    public StockPrice() {
    }

    public void update(int timestamp, int price) {
        if (d.containsKey(timestamp)) {
            int old = d.get(timestamp);
            if (ls.merge(old, -1, Integer::sum) == 0) {
                ls.remove(old);
            }
        }
        d.put(timestamp, price);
        ls.merge(price, 1, Integer::sum);
        last = Math.max(last, timestamp);
    }

    public int current() {
        return d.get(last);
    }

    public int maximum() {
        return ls.lastKey();
    }

    public int minimum() {
        return ls.firstKey();
    }
}

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice obj = new StockPrice();
 * obj.update(timestamp,price);
 * int param_2 = obj.current();
 * int param_3 = obj.maximum();
 * int param_4 = obj.minimum();
 */
```

#### C++

```cpp
class StockPrice {
public:
    StockPrice() {
    }

    void update(int timestamp, int price) {
        if (d.count(timestamp)) {
            ls.erase(ls.find(d[timestamp]));
        }
        d[timestamp] = price;
        ls.insert(price);
        last = max(last, timestamp);
    }

    int current() {
        return d[last];
    }

    int maximum() {
        return *ls.rbegin();
    }

    int minimum() {
        return *ls.begin();
    }

private:
    unordered_map<int, int> d;
    multiset<int> ls;
    int last = 0;
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
```

#### Go

```go
type StockPrice struct {
	d    map[int]int
	ls   *redblacktree.Tree
	last int
}

func Constructor() StockPrice {
	return StockPrice{
		d:    make(map[int]int),
		ls:   redblacktree.NewWithIntComparator(),
		last: 0,
	}
}

func (this *StockPrice) Update(timestamp int, price int) {
	merge := func(rbt *redblacktree.Tree, key, value int) {
		if v, ok := rbt.Get(key); ok {
			nxt := v.(int) + value
			if nxt == 0 {
				rbt.Remove(key)
			} else {
				rbt.Put(key, nxt)
			}
		} else {
			rbt.Put(key, value)
		}
	}
	if v, ok := this.d[timestamp]; ok {
		merge(this.ls, v, -1)
	}
	this.d[timestamp] = price
	merge(this.ls, price, 1)
	this.last = max(this.last, timestamp)
}

func (this *StockPrice) Current() int {
	return this.d[this.last]
}

func (this *StockPrice) Maximum() int {
	return this.ls.Right().Key.(int)
}

func (this *StockPrice) Minimum() int {
	return this.ls.Left().Key.(int)
}

/**
 * Your StockPrice object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Update(timestamp,price);
 * param_2 := obj.Current();
 * param_3 := obj.Maximum();
 * param_4 := obj.Minimum();
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2035. 将数组分成两个数组并最小化数组和的差](https://leetcode.cn/problems/partition-array-into-two-arrays-to-minimize-sum-difference){#2035}

{{< tabs "2035" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumDifference(self, nums: List[int]) -> int:
        n = len(nums) >> 1
        f = defaultdict(set)
        g = defaultdict(set)
        for i in range(1 << n):
            s = cnt = 0
            s1 = cnt1 = 0
            for j in range(n):
                if (i & (1 << j)) != 0:
                    s += nums[j]
                    cnt += 1
                    s1 += nums[n + j]
                    cnt1 += 1
                else:
                    s -= nums[j]
                    s1 -= nums[n + j]
            f[cnt].add(s)
            g[cnt1].add(s1)

        ans = inf
        for i in range(n + 1):
            fi, gi = sorted(list(f[i])), sorted(list(g[n - i]))
            # min(abs(f[i] + g[n - i]))
            for a in fi:
                left, right = 0, len(gi) - 1
                b = -a
                while left < right:
                    mid = (left + right) >> 1
                    if gi[mid] >= b:
                        right = mid
                    else:
                        left = mid + 1
                ans = min(ans, abs(a + gi[left]))
                if left > 0:
                    ans = min(ans, abs(a + gi[left - 1]))
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumDifference(int[] nums) {
        int n = nums.length >> 1;
        Map<Integer, Set<Integer>> f = new HashMap<>();
        Map<Integer, Set<Integer>> g = new HashMap<>();
        for (int i = 0; i < (1 << n); ++i) {
            int s = 0, cnt = 0;
            int s1 = 0, cnt1 = 0;
            for (int j = 0; j < n; ++j) {
                if ((i & (1 << j)) != 0) {
                    s += nums[j];
                    ++cnt;
                    s1 += nums[n + j];
                    ++cnt1;
                } else {
                    s -= nums[j];
                    s1 -= nums[n + j];
                }
            }
            f.computeIfAbsent(cnt, k -> new HashSet<>()).add(s);
            g.computeIfAbsent(cnt1, k -> new HashSet<>()).add(s1);
        }
        int ans = Integer.MAX_VALUE;
        for (int i = 0; i <= n; ++i) {
            List<Integer> fi = new ArrayList<>(f.get(i));
            List<Integer> gi = new ArrayList<>(g.get(n - i));
            Collections.sort(fi);
            Collections.sort(gi);
            for (int a : fi) {
                int left = 0, right = gi.size() - 1;
                int b = -a;
                while (left < right) {
                    int mid = (left + right) >> 1;
                    if (gi.get(mid) >= b) {
                        right = mid;
                    } else {
                        left = mid + 1;
                    }
                }
                ans = Math.min(ans, Math.abs(a + gi.get(left)));
                if (left > 0) {
                    ans = Math.min(ans, Math.abs(a + gi.get(left - 1)));
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
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() >> 1;
        vector<vector<int>> f(n + 1), g(n + 1);
        for (int i = 0; i < (1 << n); ++i) {
            int s = 0, cnt = 0;
            int s1 = 0, cnt1 = 0;
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    s += nums[j];
                    ++cnt;
                    s1 += nums[n + j];
                    ++cnt1;
                } else {
                    s -= nums[j];
                    s1 -= nums[n + j];
                }
            }
            f[cnt].push_back(s);
            g[cnt1].push_back(s1);
        }
        for (int i = 0; i <= n; ++i) {
            sort(f[i].begin(), f[i].end());
            sort(g[i].begin(), g[i].end());
        }
        int ans = INT_MAX;
        for (int i = 0; i <= n; ++i) {
            for (int a : f[i]) {
                int left = 0, right = g[n - i].size() - 1;
                int b = -a;
                while (left < right) {
                    int mid = (left + right) >> 1;
                    if (g[n - i][mid] >= b)
                        right = mid;
                    else
                        left = mid + 1;
                }
                ans = min(ans, abs(a + g[n - i][left]));
                if (left > 0) ans = min(ans, abs(a + g[n - i][left - 1]));
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumDifference(nums []int) int {
	n := len(nums) >> 1
	f := make([][]int, n+1)
	g := make([][]int, n+1)
	for i := 0; i < (1 << n); i++ {
		s, cnt := 0, 0
		s1, cnt1 := 0, 0
		for j := 0; j < n; j++ {
			if (i & (1 << j)) != 0 {
				s += nums[j]
				cnt++
				s1 += nums[n+j]
				cnt1++
			} else {
				s -= nums[j]
				s1 -= nums[n+j]
			}
		}
		f[cnt] = append(f[cnt], s)
		g[cnt1] = append(g[cnt1], s1)
	}

	for i := 0; i <= n; i++ {
		sort.Ints(f[i])
		sort.Ints(g[i])
	}
	ans := 1 << 30
	for i := 0; i <= n; i++ {
		for _, a := range f[i] {
			left, right := 0, len(g[n-i])-1
			b := -a
			for left < right {
				mid := (left + right) >> 1
				if g[n-i][mid] >= b {
					right = mid
				} else {
					left = mid + 1
				}
			}
			ans = min(ans, abs(a+g[n-i][left]))
			if left > 0 {
				ans = min(ans, abs(a+g[n-i][left-1]))
			}
		}
	}
	return ans
}

func abs(x int) int {
	if x > 0 {
		return x
	}
	return -x
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个长度为 <code>2 * n</code>&nbsp;的整数数组。你需要将&nbsp;<code>nums</code>&nbsp;分成&nbsp;<strong>两个</strong>&nbsp;长度为&nbsp;<code>n</code>&nbsp;的数组，分别求出两个数组的和，并 <strong>最小化</strong>&nbsp;两个数组和之&nbsp;<b>差的绝对值</b>&nbsp;。<code>nums</code>&nbsp;中每个元素都需要放入两个数组之一。</p>

<p>请你返回&nbsp;<strong>最小</strong>&nbsp;的数组和之差。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="example-1" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2035.Partition%20Array%20Into%20Two%20Arrays%20to%20Minimize%20Sum%20Difference/images/ex1.png" style="width: 240px; height: 106px;"></p>

<pre><b>输入：</b>nums = [3,9,7,3]
<b>输出：</b>2
<strong>解释：</strong>最优分组方案是分成 [3,9] 和 [7,3] 。
数组和之差的绝对值为 abs((3 + 9) - (7 + 3)) = 2 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [-36,36]
<b>输出：</b>72
<strong>解释：</strong>最优分组方案是分成 [-36] 和 [36] 。
数组和之差的绝对值为 abs((-36) - (36)) = 72 。
</pre>

<p><strong>示例 3：</strong></p>

<p><img alt="example-3" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2035.Partition%20Array%20Into%20Two%20Arrays%20to%20Minimize%20Sum%20Difference/images/ex3.png" style="width: 316px; height: 106px;"></p>

<pre><b>输入：</b>nums = [2,-1,0,4,-2,-9]
<b>输出：</b>0
<strong>解释：</strong>最优分组方案是分成 [2,4,-9] 和 [-1,0,-2] 。
数组和之差的绝对值为 abs((2 + 4 + -9) - (-1 + 0 + -2)) = 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 15</code></li>
	<li><code>nums.length == 2 * n</code></li>
	<li><code>-10<sup>7</sup> &lt;= nums[i] &lt;= 10<sup>7</sup></code></li>
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
    def minimumDifference(self, nums: List[int]) -> int:
        n = len(nums) >> 1
        f = defaultdict(set)
        g = defaultdict(set)
        for i in range(1 << n):
            s = cnt = 0
            s1 = cnt1 = 0
            for j in range(n):
                if (i & (1 << j)) != 0:
                    s += nums[j]
                    cnt += 1
                    s1 += nums[n + j]
                    cnt1 += 1
                else:
                    s -= nums[j]
                    s1 -= nums[n + j]
            f[cnt].add(s)
            g[cnt1].add(s1)

        ans = inf
        for i in range(n + 1):
            fi, gi = sorted(list(f[i])), sorted(list(g[n - i]))
            # min(abs(f[i] + g[n - i]))
            for a in fi:
                left, right = 0, len(gi) - 1
                b = -a
                while left < right:
                    mid = (left + right) >> 1
                    if gi[mid] >= b:
                        right = mid
                    else:
                        left = mid + 1
                ans = min(ans, abs(a + gi[left]))
                if left > 0:
                    ans = min(ans, abs(a + gi[left - 1]))
        return ans
```

#### Java

```java
class Solution {
    public int minimumDifference(int[] nums) {
        int n = nums.length >> 1;
        Map<Integer, Set<Integer>> f = new HashMap<>();
        Map<Integer, Set<Integer>> g = new HashMap<>();
        for (int i = 0; i < (1 << n); ++i) {
            int s = 0, cnt = 0;
            int s1 = 0, cnt1 = 0;
            for (int j = 0; j < n; ++j) {
                if ((i & (1 << j)) != 0) {
                    s += nums[j];
                    ++cnt;
                    s1 += nums[n + j];
                    ++cnt1;
                } else {
                    s -= nums[j];
                    s1 -= nums[n + j];
                }
            }
            f.computeIfAbsent(cnt, k -> new HashSet<>()).add(s);
            g.computeIfAbsent(cnt1, k -> new HashSet<>()).add(s1);
        }
        int ans = Integer.MAX_VALUE;
        for (int i = 0; i <= n; ++i) {
            List<Integer> fi = new ArrayList<>(f.get(i));
            List<Integer> gi = new ArrayList<>(g.get(n - i));
            Collections.sort(fi);
            Collections.sort(gi);
            for (int a : fi) {
                int left = 0, right = gi.size() - 1;
                int b = -a;
                while (left < right) {
                    int mid = (left + right) >> 1;
                    if (gi.get(mid) >= b) {
                        right = mid;
                    } else {
                        left = mid + 1;
                    }
                }
                ans = Math.min(ans, Math.abs(a + gi.get(left)));
                if (left > 0) {
                    ans = Math.min(ans, Math.abs(a + gi.get(left - 1)));
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
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() >> 1;
        vector<vector<int>> f(n + 1), g(n + 1);
        for (int i = 0; i < (1 << n); ++i) {
            int s = 0, cnt = 0;
            int s1 = 0, cnt1 = 0;
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    s += nums[j];
                    ++cnt;
                    s1 += nums[n + j];
                    ++cnt1;
                } else {
                    s -= nums[j];
                    s1 -= nums[n + j];
                }
            }
            f[cnt].push_back(s);
            g[cnt1].push_back(s1);
        }
        for (int i = 0; i <= n; ++i) {
            sort(f[i].begin(), f[i].end());
            sort(g[i].begin(), g[i].end());
        }
        int ans = INT_MAX;
        for (int i = 0; i <= n; ++i) {
            for (int a : f[i]) {
                int left = 0, right = g[n - i].size() - 1;
                int b = -a;
                while (left < right) {
                    int mid = (left + right) >> 1;
                    if (g[n - i][mid] >= b)
                        right = mid;
                    else
                        left = mid + 1;
                }
                ans = min(ans, abs(a + g[n - i][left]));
                if (left > 0) ans = min(ans, abs(a + g[n - i][left - 1]));
            }
        }
        return ans;
    }
};
```

#### Go

```go
func minimumDifference(nums []int) int {
	n := len(nums) >> 1
	f := make([][]int, n+1)
	g := make([][]int, n+1)
	for i := 0; i < (1 << n); i++ {
		s, cnt := 0, 0
		s1, cnt1 := 0, 0
		for j := 0; j < n; j++ {
			if (i & (1 << j)) != 0 {
				s += nums[j]
				cnt++
				s1 += nums[n+j]
				cnt1++
			} else {
				s -= nums[j]
				s1 -= nums[n+j]
			}
		}
		f[cnt] = append(f[cnt], s)
		g[cnt1] = append(g[cnt1], s1)
	}

	for i := 0; i <= n; i++ {
		sort.Ints(f[i])
		sort.Ints(g[i])
	}
	ans := 1 << 30
	for i := 0; i <= n; i++ {
		for _, a := range f[i] {
			left, right := 0, len(g[n-i])-1
			b := -a
			for left < right {
				mid := (left + right) >> 1
				if g[n-i][mid] >= b {
					right = mid
				} else {
					left = mid + 1
				}
			}
			ans = min(ans, abs(a+g[n-i][left]))
			if left > 0 {
				ans = min(ans, abs(a+g[n-i][left-1]))
			}
		}
	}
	return ans
}

func abs(x int) int {
	if x > 0 {
		return x
	}
	return -x
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2036. 最大交替子数组和 🔒](https://leetcode.cn/problems/maximum-alternating-subarray-sum){#2036}

{{< tabs "2036" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumAlternatingSubarraySum(self, nums: List[int]) -> int:
        ans = f = g = -inf
        for x in nums:
            f, g = max(g, 0) + x, f - x
            ans = max(ans, f, g)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long maximumAlternatingSubarraySum(int[] nums) {
        final long inf = 1L << 60;
        long ans = -inf, f = -inf, g = -inf;
        for (int x : nums) {
            long ff = Math.max(g, 0) + x;
            g = f - x;
            f = ff;
            ans = Math.max(ans, Math.max(f, g));
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
    long long maximumAlternatingSubarraySum(vector<int>& nums) {
        using ll = long long;
        const ll inf = 1LL << 60;
        ll ans = -inf, f = -inf, g = -inf;
        for (int x : nums) {
            ll ff = max(g, 0LL) + x;
            g = f - x;
            f = ff;
            ans = max({ans, f, g});
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumAlternatingSubarraySum(nums []int) int64 {
	const inf = 1 << 60
	ans, f, g := -inf, -inf, -inf
	for _, x := range nums {
		f, g = max(g, 0)+x, f-x
		ans = max(ans, max(f, g))
	}
	return int64(ans)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumAlternatingSubarraySum(nums: number[]): number {
    let [ans, f, g] = [-Infinity, -Infinity, -Infinity];
    for (const x of nums) {
        [f, g] = [Math.max(g, 0) + x, f - x];
        ans = Math.max(ans, f, g);
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

<p><strong>子数组</strong>是以<strong>0</strong>下标开始的数组的连续非空子序列，从 <code>i</code> 到 <code>j</code>（<code>0 &lt;= i &lt;= j &lt; nums.length</code>）的 <strong>子数组交替和</strong> 被定义为 <code>nums[i] - nums[i+1] + nums[i+2] - ... +/- nums[j]</code> 。</p>

<p>给定一个以<strong>0</strong>下标开始的整数数组<code>nums</code>，返回它所有可能的交替子数组和的最大值。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [3,-1,1,2]
<strong>输出：</strong>5
<strong>解释：</strong>
子数组 [3,-1,1]有最大的交替子数组和3 - (-1) + 1 = 5.
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,2,2,2,2]
<strong>输出：</strong>2
<strong>解释：</strong>
子数组 [2], [2,2,2]和 [2,2,2,2,2]有相同的最大交替子数组和为2
[2]: 2.
[2,2,2]: 2 - 2 + 2 = 2.
[2,2,2,2,2]: 2 - 2 + 2 - 2 + 2 = 2.
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [1]
<strong>输出：</strong>1
<strong>解释：</strong>
仅有一个非空子数组，为 [1]，它的交替子数组和为 1
</pre>

<p>&nbsp;</p>

<p><b>提示：</b></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>5</sup> &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f$ 表示以 $nums[i]$ 结尾的交替子数组的最大和，定义 $g$ 表示以 $-nums[i]$ 结尾的交替子数组的最大和，初始时 $f$ 和 $g$ 均为 $-\infty$。

接下来，我们遍历数组 $nums$，对于位置 $i$，我们需要维护 $f$ 和 $g$ 的值，即 $f = \max(g, 0) + nums[i]$，而 $g = f - nums[i]$。答案即为所有 $f$ 和 $g$ 中的最大值。

时间复杂度 $O(n)$，其中 $n$ 是数组 $nums$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumAlternatingSubarraySum(self, nums: List[int]) -> int:
        ans = f = g = -inf
        for x in nums:
            f, g = max(g, 0) + x, f - x
            ans = max(ans, f, g)
        return ans
```

#### Java

```java
class Solution {
    public long maximumAlternatingSubarraySum(int[] nums) {
        final long inf = 1L << 60;
        long ans = -inf, f = -inf, g = -inf;
        for (int x : nums) {
            long ff = Math.max(g, 0) + x;
            g = f - x;
            f = ff;
            ans = Math.max(ans, Math.max(f, g));
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long maximumAlternatingSubarraySum(vector<int>& nums) {
        using ll = long long;
        const ll inf = 1LL << 60;
        ll ans = -inf, f = -inf, g = -inf;
        for (int x : nums) {
            ll ff = max(g, 0LL) + x;
            g = f - x;
            f = ff;
            ans = max({ans, f, g});
        }
        return ans;
    }
};
```

#### Go

```go
func maximumAlternatingSubarraySum(nums []int) int64 {
	const inf = 1 << 60
	ans, f, g := -inf, -inf, -inf
	for _, x := range nums {
		f, g = max(g, 0)+x, f-x
		ans = max(ans, max(f, g))
	}
	return int64(ans)
}
```

#### TypeScript

```ts
function maximumAlternatingSubarraySum(nums: number[]): number {
    let [ans, f, g] = [-Infinity, -Infinity, -Infinity];
    for (const x of nums) {
        [f, g] = [Math.max(g, 0) + x, f - x];
        ans = Math.max(ans, f, g);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2037. 使每位学生都有座位的最少移动次数](https://leetcode.cn/problems/minimum-number-of-moves-to-seat-everyone){#2037}

{{< tabs "2037" >}}

{{% tab "python" %}}
```python
class Solution:
    def minMovesToSeat(self, seats: List[int], students: List[int]) -> int:
        seats.sort()
        students.sort()
        return sum(abs(a - b) for a, b in zip(seats, students))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minMovesToSeat(int[] seats, int[] students) {
        Arrays.sort(seats);
        Arrays.sort(students);
        int ans = 0;
        for (int i = 0; i < seats.length; ++i) {
            ans += Math.abs(seats[i] - students[i]);
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
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        int ans = 0;
        for (int i = 0; i < seats.size(); ++i) {
            ans += abs(seats[i] - students[i]);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minMovesToSeat(seats []int, students []int) (ans int) {
	sort.Ints(seats)
	sort.Ints(students)
	for i, a := range seats {
		b := students[i]
		ans += abs(a - b)
	}
	return
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
function minMovesToSeat(seats: number[], students: number[]): number {
    seats.sort((a, b) => a - b);
    students.sort((a, b) => a - b);
    return seats.reduce((acc, seat, i) => acc + Math.abs(seat - students[i]), 0);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn min_moves_to_seat(mut seats: Vec<i32>, mut students: Vec<i32>) -> i32 {
        seats.sort();
        students.sort();
        let n = seats.len();
        let mut ans = 0;
        for i in 0..n {
            ans += (seats[i] - students[i]).abs();
        }
        ans
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
int cmp(const void* a, const void* b) {
    return *(int*) a - *(int*) b;
}

int minMovesToSeat(int* seats, int seatsSize, int* students, int studentsSize) {
    qsort(seats, seatsSize, sizeof(int), cmp);
    qsort(students, studentsSize, sizeof(int), cmp);
    int ans = 0;
    for (int i = 0; i < seatsSize; i++) {
        ans += abs(seats[i] - students[i]);
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

<p>一个房间里有 <code>n</code>&nbsp;个 <strong>空闲</strong> 座位和 <code>n</code>&nbsp;名 <strong>站着的</strong>&nbsp;学生，房间用一个数轴表示。给你一个长度为 <code>n</code>&nbsp;的数组&nbsp;<code>seats</code>&nbsp;，其中&nbsp;<code>seats[i]</code> 是第 <code>i</code>&nbsp;个座位的位置。同时给你一个长度为 <code>n</code>&nbsp;的数组&nbsp;<code>students</code>&nbsp;，其中&nbsp;<code>students[j]</code>&nbsp;是第 <code>j</code>&nbsp;位学生的位置。</p>

<p>你可以执行以下操作任意次：</p>

<ul>
	<li>增加或者减少第&nbsp;<code>i</code>&nbsp;位学生的位置，每次变化量为 <code>1</code>&nbsp;（也就是将第 <code>i</code>&nbsp;位学生从位置 <code>x</code>&nbsp;移动到 <code>x + 1</code>&nbsp;或者 <code>x - 1</code>）</li>
</ul>

<p>请你返回使所有学生都有座位坐的 <strong>最少移动次数</strong>&nbsp;，并确保没有两位学生的座位相同。</p>

<p>请注意，初始时有可能有多个座位或者多位学生在 <strong>同一</strong>&nbsp;位置。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>seats = [3,1,5], students = [2,7,4]
<b>输出：</b>4
<b>解释：</b>学生移动方式如下：
- 第一位学生从位置 2 移动到位置 1 ，移动 1 次。
- 第二位学生从位置 7 移动到位置 5 ，移动 2 次。
- 第三位学生从位置 4 移动到位置 3 ，移动 1 次。
总共 1 + 2 + 1 = 4 次移动。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>seats = [4,1,5,9], students = [1,3,2,6]
<b>输出：</b>7
<strong>解释：</strong>学生移动方式如下：
- 第一位学生不移动。
- 第二位学生从位置 3 移动到位置 4 ，移动 1 次。
- 第三位学生从位置 2 移动到位置 5 ，移动 3 次。
- 第四位学生从位置 6 移动到位置 9 ，移动 3 次。
总共 0 + 1 + 3 + 3 = 7 次移动。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>seats = [2,2,6,6], students = [1,3,2,6]
<b>输出：</b>4
<b>解释：</b>学生移动方式如下：
- 第一位学生从位置 1 移动到位置 2 ，移动 1 次。
- 第二位学生从位置 3 移动到位置 6 ，移动 3 次。
- 第三位学生不移动。
- 第四位学生不移动。
总共 1 + 3 + 0 + 0 = 4 次移动。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == seats.length == students.length</code></li>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>1 &lt;= seats[i], students[j] &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序

将两个数组分别排序，然后遍历两个数组，计算每个学生的座位与其实际座位的距离，将所有距离相加即为答案。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 为数组 `seats` 和 `students` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minMovesToSeat(self, seats: List[int], students: List[int]) -> int:
        seats.sort()
        students.sort()
        return sum(abs(a - b) for a, b in zip(seats, students))
```

#### Java

```java
class Solution {
    public int minMovesToSeat(int[] seats, int[] students) {
        Arrays.sort(seats);
        Arrays.sort(students);
        int ans = 0;
        for (int i = 0; i < seats.length; ++i) {
            ans += Math.abs(seats[i] - students[i]);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        int ans = 0;
        for (int i = 0; i < seats.size(); ++i) {
            ans += abs(seats[i] - students[i]);
        }
        return ans;
    }
};
```

#### Go

```go
func minMovesToSeat(seats []int, students []int) (ans int) {
	sort.Ints(seats)
	sort.Ints(students)
	for i, a := range seats {
		b := students[i]
		ans += abs(a - b)
	}
	return
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
function minMovesToSeat(seats: number[], students: number[]): number {
    seats.sort((a, b) => a - b);
    students.sort((a, b) => a - b);
    return seats.reduce((acc, seat, i) => acc + Math.abs(seat - students[i]), 0);
}
```

#### Rust

```rust
impl Solution {
    pub fn min_moves_to_seat(mut seats: Vec<i32>, mut students: Vec<i32>) -> i32 {
        seats.sort();
        students.sort();
        let n = seats.len();
        let mut ans = 0;
        for i in 0..n {
            ans += (seats[i] - students[i]).abs();
        }
        ans
    }
}
```

#### C

```c
int cmp(const void* a, const void* b) {
    return *(int*) a - *(int*) b;
}

int minMovesToSeat(int* seats, int seatsSize, int* students, int studentsSize) {
    qsort(seats, seatsSize, sizeof(int), cmp);
    qsort(students, studentsSize, sizeof(int), cmp);
    int ans = 0;
    for (int i = 0; i < seatsSize; i++) {
        ans += abs(seats[i] - students[i]);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2038. 如果相邻两个颜色均相同则删除当前颜色](https://leetcode.cn/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color){#2038}

{{< tabs "2038" >}}

{{% tab "python" %}}
```python
class Solution:
    def winnerOfGame(self, colors: str) -> bool:
        a = b = 0
        for c, v in groupby(colors):
            m = len(list(v)) - 2
            if m > 0 and c == 'A':
                a += m
            elif m > 0 and c == 'B':
                b += m
        return a > b
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean winnerOfGame(String colors) {
        int n = colors.length();
        int a = 0, b = 0;
        for (int i = 0, j = 0; i < n; i = j) {
            while (j < n && colors.charAt(j) == colors.charAt(i)) {
                ++j;
            }
            int m = j - i - 2;
            if (m > 0) {
                if (colors.charAt(i) == 'A') {
                    a += m;
                } else {
                    b += m;
                }
            }
        }
        return a > b;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.size();
        int a = 0, b = 0;
        for (int i = 0, j = 0; i < n; i = j) {
            while (j < n && colors[j] == colors[i]) {
                ++j;
            }
            int m = j - i - 2;
            if (m > 0) {
                if (colors[i] == 'A') {
                    a += m;
                } else {
                    b += m;
                }
            }
        }
        return a > b;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func winnerOfGame(colors string) bool {
	n := len(colors)
	a, b := 0, 0
	for i, j := 0, 0; i < n; i = j {
		for j < n && colors[j] == colors[i] {
			j++
		}
		m := j - i - 2
		if m > 0 {
			if colors[i] == 'A' {
				a += m
			} else {
				b += m
			}
		}
	}
	return a > b
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function winnerOfGame(colors: string): boolean {
    const n = colors.length;
    let [a, b] = [0, 0];
    for (let i = 0, j = 0; i < n; i = j) {
        while (j < n && colors[j] === colors[i]) {
            ++j;
        }
        const m = j - i - 2;
        if (m > 0) {
            if (colors[i] === 'A') {
                a += m;
            } else {
                b += m;
            }
        }
    }
    return a > b;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>总共有 <code>n</code>&nbsp;个颜色片段排成一列，每个颜色片段要么是&nbsp;<code>'A'</code>&nbsp;要么是&nbsp;<code>'B'</code>&nbsp;。给你一个长度为&nbsp;<code>n</code>&nbsp;的字符串&nbsp;<code>colors</code>&nbsp;，其中&nbsp;<code>colors[i]</code>&nbsp;表示第&nbsp;<code>i</code>&nbsp;个颜色片段的颜色。</p>

<p>Alice 和 Bob 在玩一个游戏，他们 <strong>轮流</strong>&nbsp;从这个字符串中删除颜色。Alice <strong>先手</strong>&nbsp;。</p>

<ul>
	<li>如果一个颜色片段为 <code>'A'</code>&nbsp;且 <strong>相邻两个颜色</strong>&nbsp;都是颜色 <code>'A'</code>&nbsp;，那么 Alice 可以删除该颜色片段。Alice&nbsp;<strong>不可以</strong>&nbsp;删除任何颜色&nbsp;<code>'B'</code>&nbsp;片段。</li>
	<li>如果一个颜色片段为 <code>'B'</code>&nbsp;且 <strong>相邻两个颜色</strong>&nbsp;都是颜色 <code>'B'</code>&nbsp;，那么 Bob 可以删除该颜色片段。Bob <strong>不可以</strong>&nbsp;删除任何颜色 <code>'A'</code>&nbsp;片段。</li>
	<li>Alice 和 Bob <strong>不能</strong>&nbsp;从字符串两端删除颜色片段。</li>
	<li>如果其中一人无法继续操作，则该玩家 <b>输</b>&nbsp;掉游戏且另一玩家 <strong>获胜</strong>&nbsp;。</li>
</ul>

<p>假设 Alice 和 Bob 都采用最优策略，如果 Alice 获胜，请返回&nbsp;<code>true</code>，否则 Bob 获胜，返回<em>&nbsp;</em><code>false</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>colors = "AAABABB"
<b>输出：</b>true
<b>解释：</b>
A<em><strong>A</strong></em>ABABB -&gt; AABABB
Alice 先操作。
她删除从左数第二个 'A' ，这也是唯一一个相邻颜色片段都是 'A' 的 'A' 。

现在轮到 Bob 操作。
Bob 无法执行任何操作，因为没有相邻位置都是 'B' 的颜色片段 'B' 。
因此，Alice 获胜，返回 true 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>colors = "AA"
<b>输出：</b>false
<strong>解释：</strong>
Alice 先操作。
只有 2 个 'A' 且它们都在字符串的两端，所以她无法执行任何操作。
因此，Bob 获胜，返回 false 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>colors = "ABBBBBBBAAA"
<b>输出：</b>false
<strong>解释：</strong>
ABBBBBBBA<em><strong>A</strong></em>A -&gt; ABBBBBBBAA
Alice 先操作。
她唯一的选择是删除从右数起第二个 'A' 。

ABBBB<strong><em>B</em></strong>BBAA -&gt; ABBBBBBAA
接下来轮到 Bob 操作。
他有许多选择，他可以选择任何一个 'B' 删除。

然后轮到 Alice 操作，她无法删除任何片段。
所以 Bob 获胜，返回 false 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;=&nbsp;colors.length &lt;= 10<sup>5</sup></code></li>
	<li><code>colors</code>&nbsp;只包含字母&nbsp;<code>'A'</code>&nbsp;和&nbsp;<code>'B'</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数

我们统计字符串 `colors` 中连续出现 $3$ 个 `'A'` 或 $3$ 个 `'B'` 的个数，分别记为 $a$ 和 $b$。

最后判断 $a$ 是否大于 $b$，是则返回 `true`，否则返回 `false`。

时间复杂度 $O(n)$，其中 $n$ 为字符串 `colors` 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def winnerOfGame(self, colors: str) -> bool:
        a = b = 0
        for c, v in groupby(colors):
            m = len(list(v)) - 2
            if m > 0 and c == 'A':
                a += m
            elif m > 0 and c == 'B':
                b += m
        return a > b
```

#### Java

```java
class Solution {
    public boolean winnerOfGame(String colors) {
        int n = colors.length();
        int a = 0, b = 0;
        for (int i = 0, j = 0; i < n; i = j) {
            while (j < n && colors.charAt(j) == colors.charAt(i)) {
                ++j;
            }
            int m = j - i - 2;
            if (m > 0) {
                if (colors.charAt(i) == 'A') {
                    a += m;
                } else {
                    b += m;
                }
            }
        }
        return a > b;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.size();
        int a = 0, b = 0;
        for (int i = 0, j = 0; i < n; i = j) {
            while (j < n && colors[j] == colors[i]) {
                ++j;
            }
            int m = j - i - 2;
            if (m > 0) {
                if (colors[i] == 'A') {
                    a += m;
                } else {
                    b += m;
                }
            }
        }
        return a > b;
    }
};
```

#### Go

```go
func winnerOfGame(colors string) bool {
	n := len(colors)
	a, b := 0, 0
	for i, j := 0, 0; i < n; i = j {
		for j < n && colors[j] == colors[i] {
			j++
		}
		m := j - i - 2
		if m > 0 {
			if colors[i] == 'A' {
				a += m
			} else {
				b += m
			}
		}
	}
	return a > b
}
```

#### TypeScript

```ts
function winnerOfGame(colors: string): boolean {
    const n = colors.length;
    let [a, b] = [0, 0];
    for (let i = 0, j = 0; i < n; i = j) {
        while (j < n && colors[j] === colors[i]) {
            ++j;
        }
        const m = j - i - 2;
        if (m > 0) {
            if (colors[i] === 'A') {
                a += m;
            } else {
                b += m;
            }
        }
    }
    return a > b;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2039. 网络空闲的时刻](https://leetcode.cn/problems/the-time-when-the-network-becomes-idle){#2039}

{{< tabs "2039" >}}

{{% tab "python" %}}
```python
class Solution:
    def networkBecomesIdle(self, edges: List[List[int]], patience: List[int]) -> int:
        g = defaultdict(list)
        for u, v in edges:
            g[u].append(v)
            g[v].append(u)
        q = deque([0])
        vis = {0}
        ans = d = 0
        while q:
            d += 1
            t = d * 2
            for _ in range(len(q)):
                u = q.popleft()
                for v in g[u]:
                    if v not in vis:
                        vis.add(v)
                        q.append(v)
                        ans = max(ans, (t - 1) // patience[v] * patience[v] + t + 1)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int networkBecomesIdle(int[][] edges, int[] patience) {
        int n = patience.length;
        List<Integer>[] g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (int[] e : edges) {
            int u = e[0], v = e[1];
            g[u].add(v);
            g[v].add(u);
        }
        Deque<Integer> q = new ArrayDeque<>();
        q.offer(0);
        boolean[] vis = new boolean[n];
        vis[0] = true;
        int ans = 0, d = 0;
        while (!q.isEmpty()) {
            ++d;
            int t = d * 2;
            for (int i = q.size(); i > 0; --i) {
                int u = q.poll();
                for (int v : g[u]) {
                    if (!vis[v]) {
                        vis[v] = true;
                        q.offer(v);
                        ans = Math.max(ans, (t - 1) / patience[v] * patience[v] + t + 1);
                    }
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
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();
        vector<int> g[n];
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        queue<int> q{{0}};
        bool vis[n];
        memset(vis, false, sizeof(vis));
        vis[0] = true;
        int ans = 0, d = 0;
        while (!q.empty()) {
            ++d;
            int t = d * 2;
            for (int i = q.size(); i; --i) {
                int u = q.front();
                q.pop();
                for (int v : g[u]) {
                    if (!vis[v]) {
                        vis[v] = true;
                        q.push(v);
                        ans = max(ans, (t - 1) / patience[v] * patience[v] + t + 1);
                    }
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
func networkBecomesIdle(edges [][]int, patience []int) (ans int) {
	n := len(patience)
	g := make([][]int, n)
	for _, e := range edges {
		u, v := e[0], e[1]
		g[u] = append(g[u], v)
		g[v] = append(g[v], u)
	}
	q := []int{0}
	vis := make([]bool, n)
	vis[0] = true
	for d := 1; len(q) > 0; d++ {
		t := d * 2
		for i := len(q); i > 0; i-- {
			u := q[0]
			q = q[1:]
			for _, v := range g[u] {
				if !vis[v] {
					vis[v] = true
					q = append(q, v)
					ans = max(ans, (t-1)/patience[v]*patience[v]+t+1)
				}
			}
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function networkBecomesIdle(edges: number[][], patience: number[]): number {
    const n = patience.length;
    const g: number[][] = Array.from({ length: n }, () => []);
    for (const [u, v] of edges) {
        g[u].push(v);
        g[v].push(u);
    }
    const vis: boolean[] = Array.from({ length: n }, () => false);
    vis[0] = true;
    let q: number[] = [0];
    let ans = 0;
    for (let d = 1; q.length > 0; ++d) {
        const t = d * 2;
        const nq: number[] = [];
        for (const u of q) {
            for (const v of g[u]) {
                if (!vis[v]) {
                    vis[v] = true;
                    nq.push(v);
                    ans = Math.max(ans, (((t - 1) / patience[v]) | 0) * patience[v] + t + 1);
                }
            }
        }
        q = nq;
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

<p>给你一个有 <code>n</code>&nbsp;个服务器的计算机网络，服务器编号为&nbsp;<code>0</code>&nbsp;到&nbsp;<code>n - 1</code>&nbsp;。同时给你一个二维整数数组&nbsp;<code>edges</code>&nbsp;，其中&nbsp;<code>edges[i] = [u<sub>i</sub>, v<sub>i</sub>]</code>&nbsp;表示服务器&nbsp;<code>u<sub>i</sub></code> 和&nbsp;<code>v<sub>i</sub></code><sub>&nbsp;</sub>之间有一条信息线路，在&nbsp;<strong>一秒</strong>&nbsp;内它们之间可以传输&nbsp;<strong>任意</strong>&nbsp;数目的信息。再给你一个长度为 <code>n</code>&nbsp;且下标从&nbsp;<strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>patience</code>&nbsp;。</p>

<p>题目保证所有服务器都是 <b>相通</b>&nbsp;的，也就是说一个信息从任意服务器出发，都可以通过这些信息线路直接或间接地到达任何其他服务器。</p>

<p>编号为 <code>0</code>&nbsp;的服务器是 <strong>主</strong>&nbsp;服务器，其他服务器为 <strong>数据</strong>&nbsp;服务器。每个数据服务器都要向主服务器发送信息，并等待回复。信息在服务器之间按 <strong>最优</strong>&nbsp;线路传输，也就是说每个信息都会以 <strong>最少时间</strong>&nbsp;到达主服务器。主服务器会处理 <strong>所有</strong>&nbsp;新到达的信息并 <strong>立即</strong>&nbsp;按照每条信息来时的路线 <strong>反方向</strong> 发送回复信息。</p>

<p>在 <code>0</code>&nbsp;秒的开始，所有数据服务器都会发送各自需要处理的信息。从第 <code>1</code>&nbsp;秒开始，<strong>每</strong>&nbsp;一秒最 <strong>开始</strong>&nbsp;时，每个数据服务器都会检查它是否收到了主服务器的回复信息（包括新发出信息的回复信息）：</p>

<ul>
	<li>如果还没收到任何回复信息，那么该服务器会周期性&nbsp;<strong>重发</strong>&nbsp;信息。数据服务器&nbsp;<code>i</code>&nbsp;每&nbsp;<code>patience[i]</code>&nbsp;秒都会重发一条信息，也就是说，数据服务器&nbsp;<code>i</code>&nbsp;在上一次发送信息给主服务器后的 <code>patience[i]</code>&nbsp;秒 <strong>后</strong>&nbsp;会重发一条信息给主服务器。</li>
	<li>否则，该数据服务器&nbsp;<strong>不会重发</strong>&nbsp;信息。</li>
</ul>

<p>当没有任何信息在线路上传输或者到达某服务器时，该计算机网络变为 <strong>空闲</strong>&nbsp;状态。</p>

<p>请返回计算机网络变为 <strong>空闲</strong>&nbsp;状态的&nbsp;<strong>最早秒数</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="example 1" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2039.The%20Time%20When%20the%20Network%20Becomes%20Idle/images/quiet-place-example1.png" style="width: 750px; height: 384px;"></p>

<pre><b>输入：</b>edges = [[0,1],[1,2]], patience = [0,2,1]
<b>输出：</b>8
<strong>解释：</strong>
0 秒最开始时，
- 数据服务器 1 给主服务器发出信息（用 1A 表示）。
- 数据服务器 2 给主服务器发出信息（用 2A 表示）。

1 秒时，
- 信息 1A 到达主服务器，主服务器立刻处理信息 1A 并发出 1A 的回复信息。
- 数据服务器 1 还没收到任何回复。距离上次发出信息过去了 1 秒（1 &lt; patience[1] = 2），所以不会重发信息。
- 数据服务器 2 还没收到任何回复。距离上次发出信息过去了 1 秒（1 == patience[2] = 1），所以它重发一条信息（用 2B 表示）。

2 秒时，
- 回复信息 1A 到达服务器 1 ，服务器 1 不会再重发信息。
- 信息 2A 到达主服务器，主服务器立刻处理信息 2A 并发出 2A 的回复信息。
- 服务器 2 重发一条信息（用 2C 表示）。
...
4 秒时，
- 回复信息 2A 到达服务器 2 ，服务器 2 不会再重发信息。
...
7 秒时，回复信息 2D 到达服务器 2 。

从第 8 秒开始，不再有任何信息在服务器之间传输，也不再有信息到达服务器。
所以第 8 秒是网络变空闲的最早时刻。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="example 2" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2039.The%20Time%20When%20the%20Network%20Becomes%20Idle/images/network_a_quiet_place_2.png" style="width: 100px; height: 85px;"></p>

<pre><b>输入：</b>edges = [[0,1],[0,2],[1,2]], patience = [0,10,10]
<b>输出：</b>3
<b>解释：</b>数据服务器 1 和 2 第 2 秒初收到回复信息。
从第 3 秒开始，网络变空闲。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == patience.length</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>patience[0] == 0</code></li>
	<li>对于&nbsp;<code>1 &lt;= i &lt; n</code> ，满足&nbsp;<code>1 &lt;= patience[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= edges.length &lt;= min(10<sup>5</sup>, n * (n - 1) / 2)</code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>0 &lt;= u<sub>i</sub>, v<sub>i</sub> &lt; n</code></li>
	<li><code>u<sub>i</sub> != v<sub>i</sub></code></li>
	<li>不会有重边。</li>
	<li>每个服务器都直接或间接与别的服务器相连。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：BFS

我们先根据二维数组 $edges$ 构建无向图 $g$，其中 $g[u]$ 表示节点 $u$ 的所有邻居节点。

然后，我们可以使用广度优先搜索的方式，找出每个节点 $i$ 距离主服务器的最短距离 $d_i$，那么节点 $i$ 发出信息后，最早能收到回复的时间为 $2 \times d_i$。由于每个数据服务器 $i$ 每隔 $patience[i]$ 会重发一条信息，因此，每个数据服务器最后一次发出信息的时间为 $(2 \times d_i - 1) / patience[i] \times patience[i]$，那么最后收到回复的时间为 $(2 \times d_i - 1) / patience[i] \times patience[i] + 2 \times d_i$，再加上 $1$ 秒的处理时间，即为该数据服务器变为空闲的最早时间。我们找出最晚的这个时间，即为计算机网络变为空闲的最早时间。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为节点数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def networkBecomesIdle(self, edges: List[List[int]], patience: List[int]) -> int:
        g = defaultdict(list)
        for u, v in edges:
            g[u].append(v)
            g[v].append(u)
        q = deque([0])
        vis = {0}
        ans = d = 0
        while q:
            d += 1
            t = d * 2
            for _ in range(len(q)):
                u = q.popleft()
                for v in g[u]:
                    if v not in vis:
                        vis.add(v)
                        q.append(v)
                        ans = max(ans, (t - 1) // patience[v] * patience[v] + t + 1)
        return ans
```

#### Java

```java
class Solution {
    public int networkBecomesIdle(int[][] edges, int[] patience) {
        int n = patience.length;
        List<Integer>[] g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (int[] e : edges) {
            int u = e[0], v = e[1];
            g[u].add(v);
            g[v].add(u);
        }
        Deque<Integer> q = new ArrayDeque<>();
        q.offer(0);
        boolean[] vis = new boolean[n];
        vis[0] = true;
        int ans = 0, d = 0;
        while (!q.isEmpty()) {
            ++d;
            int t = d * 2;
            for (int i = q.size(); i > 0; --i) {
                int u = q.poll();
                for (int v : g[u]) {
                    if (!vis[v]) {
                        vis[v] = true;
                        q.offer(v);
                        ans = Math.max(ans, (t - 1) / patience[v] * patience[v] + t + 1);
                    }
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
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();
        vector<int> g[n];
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        queue<int> q{{0}};
        bool vis[n];
        memset(vis, false, sizeof(vis));
        vis[0] = true;
        int ans = 0, d = 0;
        while (!q.empty()) {
            ++d;
            int t = d * 2;
            for (int i = q.size(); i; --i) {
                int u = q.front();
                q.pop();
                for (int v : g[u]) {
                    if (!vis[v]) {
                        vis[v] = true;
                        q.push(v);
                        ans = max(ans, (t - 1) / patience[v] * patience[v] + t + 1);
                    }
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func networkBecomesIdle(edges [][]int, patience []int) (ans int) {
	n := len(patience)
	g := make([][]int, n)
	for _, e := range edges {
		u, v := e[0], e[1]
		g[u] = append(g[u], v)
		g[v] = append(g[v], u)
	}
	q := []int{0}
	vis := make([]bool, n)
	vis[0] = true
	for d := 1; len(q) > 0; d++ {
		t := d * 2
		for i := len(q); i > 0; i-- {
			u := q[0]
			q = q[1:]
			for _, v := range g[u] {
				if !vis[v] {
					vis[v] = true
					q = append(q, v)
					ans = max(ans, (t-1)/patience[v]*patience[v]+t+1)
				}
			}
		}
	}
	return
}
```

#### TypeScript

```ts
function networkBecomesIdle(edges: number[][], patience: number[]): number {
    const n = patience.length;
    const g: number[][] = Array.from({ length: n }, () => []);
    for (const [u, v] of edges) {
        g[u].push(v);
        g[v].push(u);
    }
    const vis: boolean[] = Array.from({ length: n }, () => false);
    vis[0] = true;
    let q: number[] = [0];
    let ans = 0;
    for (let d = 1; q.length > 0; ++d) {
        const t = d * 2;
        const nq: number[] = [];
        for (const u of q) {
            for (const v of g[u]) {
                if (!vis[v]) {
                    vis[v] = true;
                    nq.push(v);
                    ans = Math.max(ans, (((t - 1) / patience[v]) | 0) * patience[v] + t + 1);
                }
            }
        }
        q = nq;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
