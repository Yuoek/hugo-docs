---
title: "1630_等差子数组"
date: 2025-10-08T18:38:12+08:00
weight: 4
tags: [二分查找, 动态规划, 双指针, 哈希表, 图, 堆（优先队列）, 字符串, 并查集, 广度优先搜索, 拓扑排序, 排序, 数学, 数据库, 数组, 枚举, 深度优先搜索, 矩阵, 链表]
---

{{< markmap >}}
### [1630_等差子数组](#1630)
#### [数组](#1630)
#### [哈希表](#1630)
#### [排序](#1630)
### [1631_最小体力消耗路径](#1631)
#### [深度优先搜索](#1631)
#### [广度优先搜索](#1631)
#### [并查集](#1631)
#### [数组](#1631)
#### [二分查找](#1631)
#### [矩阵](#1631)
#### [堆（优先队列）](#1631)
### [1632_矩阵转换后的秩](#1632)
#### [并查集](#1632)
#### [图](#1632)
#### [拓扑排序](#1632)
#### [数组](#1632)
#### [矩阵](#1632)
#### [排序](#1632)
### [1633_各赛事的用户注册率](#1633)
#### [数据库](#1633)
### [1634_求两个多项式链表的和 🔒](#1634)
#### [链表](#1634)
#### [数学](#1634)
#### [双指针](#1634)
### [1635_Hopper 公司查询 I 🔒](#1635)
#### [数据库](#1635)
### [1636_按照频率将数组升序排序](#1636)
#### [数组](#1636)
#### [哈希表](#1636)
#### [排序](#1636)
### [1637_两点之间不包含任何点的最宽垂直区域](#1637)
#### [数组](#1637)
#### [排序](#1637)
### [1638_统计只差一个字符的子串数目](#1638)
#### [哈希表](#1638)
#### [字符串](#1638)
#### [动态规划](#1638)
#### [枚举](#1638)
### [1639_通过给定词典构造目标字符串的方案数](#1639)
#### [数组](#1639)
#### [字符串](#1639)
#### [动态规划](#1639)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1630_等差子数组
___
#### 数组
___
#### 哈希表
___
#### 排序
---
### 1631_最小体力消耗路径
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 并查集
___
#### 数组
___
#### 二分查找
___
#### 矩阵
___
#### 堆（优先队列）
---
### 1632_矩阵转换后的秩
___
#### 并查集
___
#### 图
___
#### 拓扑排序
___
#### 数组
___
#### 矩阵
___
#### 排序
---
### 1633_各赛事的用户注册率
___
#### 数据库
---
### 1634_求两个多项式链表的和 🔒
___
#### 链表
___
#### 数学
___
#### 双指针
---
### 1635_Hopper 公司查询 I 🔒
___
#### 数据库
---
### 1636_按照频率将数组升序排序
___
#### 数组
___
#### 哈希表
___
#### 排序
---
### 1637_两点之间不包含任何点的最宽垂直区域
___
#### 数组
___
#### 排序
---
### 1638_统计只差一个字符的子串数目
___
#### 哈希表
___
#### 字符串
___
#### 动态规划
___
#### 枚举
---
### 1639_通过给定词典构造目标字符串的方案数
___
#### 数组
___
#### 字符串
___
#### 动态规划
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 动态规划 | 双指针 |
| 哈希表 | 图 | 堆（优先队列） |
| 字符串 | 并查集 | 广度优先搜索 |
| 拓扑排序 | 排序 | 数学 |
| 数据库 | 数组 | 枚举 |
| 深度优先搜索 | 矩阵 | 链表 |

# [1630. 等差子数组](https://leetcode.cn/problems/arithmetic-subarrays){#1630}

{{< tabs "1630" >}}

{{% tab "python" %}}
```python
class Solution:
    def checkArithmeticSubarrays(
        self, nums: List[int], l: List[int], r: List[int]
    ) -> List[bool]:
        def check(nums, l, r):
            n = r - l + 1
            s = set(nums[l : l + n])
            a1, an = min(nums[l : l + n]), max(nums[l : l + n])
            d, mod = divmod(an - a1, n - 1)
            return mod == 0 and all((a1 + (i - 1) * d) in s for i in range(1, n))

        return [check(nums, left, right) for left, right in zip(l, r)]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<Boolean> checkArithmeticSubarrays(int[] nums, int[] l, int[] r) {
        List<Boolean> ans = new ArrayList<>();
        for (int i = 0; i < l.length; ++i) {
            ans.add(check(nums, l[i], r[i]));
        }
        return ans;
    }

    private boolean check(int[] nums, int l, int r) {
        Set<Integer> s = new HashSet<>();
        int n = r - l + 1;
        int a1 = 1 << 30, an = -a1;
        for (int i = l; i <= r; ++i) {
            s.add(nums[i]);
            a1 = Math.min(a1, nums[i]);
            an = Math.max(an, nums[i]);
        }
        if ((an - a1) % (n - 1) != 0) {
            return false;
        }
        int d = (an - a1) / (n - 1);
        for (int i = 1; i < n; ++i) {
            if (!s.contains(a1 + (i - 1) * d)) {
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
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        auto check = [](vector<int>& nums, int l, int r) {
            unordered_set<int> s;
            int n = r - l + 1;
            int a1 = 1 << 30, an = -a1;
            for (int i = l; i <= r; ++i) {
                s.insert(nums[i]);
                a1 = min(a1, nums[i]);
                an = max(an, nums[i]);
            }
            if ((an - a1) % (n - 1)) {
                return false;
            }
            int d = (an - a1) / (n - 1);
            for (int i = 1; i < n; ++i) {
                if (!s.count(a1 + (i - 1) * d)) {
                    return false;
                }
            }
            return true;
        };
        for (int i = 0; i < l.size(); ++i) {
            ans.push_back(check(nums, l[i], r[i]));
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func checkArithmeticSubarrays(nums []int, l []int, r []int) (ans []bool) {
	check := func(nums []int, l, r int) bool {
		s := map[int]struct{}{}
		n := r - l + 1
		a1, an := 1<<30, -(1 << 30)
		for _, x := range nums[l : r+1] {
			s[x] = struct{}{}
			if a1 > x {
				a1 = x
			}
			if an < x {
				an = x
			}
		}
		if (an-a1)%(n-1) != 0 {
			return false
		}
		d := (an - a1) / (n - 1)
		for i := 1; i < n; i++ {
			if _, ok := s[a1+(i-1)*d]; !ok {
				return false
			}
		}
		return true
	}
	for i := range l {
		ans = append(ans, check(nums, l[i], r[i]))
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function checkArithmeticSubarrays(nums: number[], l: number[], r: number[]): boolean[] {
    const check = (nums: number[], l: number, r: number): boolean => {
        const s = new Set<number>();
        const n = r - l + 1;
        let a1 = 1 << 30;
        let an = -a1;
        for (let i = l; i <= r; ++i) {
            s.add(nums[i]);
            a1 = Math.min(a1, nums[i]);
            an = Math.max(an, nums[i]);
        }
        if ((an - a1) % (n - 1) !== 0) {
            return false;
        }
        const d = Math.floor((an - a1) / (n - 1));
        for (let i = 1; i < n; ++i) {
            if (!s.has(a1 + (i - 1) * d)) {
                return false;
            }
        }
        return true;
    };
    const ans: boolean[] = [];
    for (let i = 0; i < l.length; ++i) {
        ans.push(check(nums, l[i], r[i]));
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn check_arithmetic_subarrays(nums: Vec<i32>, l: Vec<i32>, r: Vec<i32>) -> Vec<bool> {
        let m = l.len();
        let mut res = vec![true; m];
        for i in 0..m {
            let mut arr = nums[l[i] as usize..=r[i] as usize].to_vec();
            arr.sort();
            for j in 2..arr.len() {
                if arr[j - 2] - arr[j - 1] != arr[j - 1] - arr[j] {
                    res[i] = false;
                    break;
                }
            }
        }
        res
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
class Solution {
    public bool Check(int[] arr) {
        Array.Sort(arr);
        int diff = arr[1] - arr[0];
        for (int i = 2; i < arr.Length; i++) {
            if (arr[i] - arr[i - 1] != diff) {
                return false;
            }
        }
        return true;
    }

    public IList<bool> CheckArithmeticSubarrays(int[] nums, int[] l, int[] r) {
        List<bool> ans = new List<bool>();
        for (int i = 0; i < l.Length; i++) {
            int[] arr = new int[r[i] - l[i] + 1];
            for (int j = 0; j < arr.Length; j++) {
                arr[j] = nums[l[i] + j];
            }
            ans.Add(Check(arr));
        }
        return ans;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>如果一个数列由至少两个元素组成，且每两个连续元素之间的差值都相同，那么这个序列就是 <strong>等差数列</strong> 。更正式地，数列 <code>s</code> 是等差数列，只需要满足：对于每个有效的 <code>i</code> ， <code>s[i+1] - s[i] == s[1] - s[0]</code> 都成立。</p>

<p>例如，下面这些都是 <strong>等差数列</strong> ：</p>

<pre>1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9</pre>

<p>下面的数列 <strong>不是等差数列</strong> ：</p>

<pre>1, 1, 2, 5, 7</pre>

<p>给你一个由 <code>n</code> 个整数组成的数组 <code>nums</code>，和两个由 <code>m</code> 个整数组成的数组 <code>l</code> 和 <code>r</code>，后两个数组表示 <code>m</code> 组范围查询，其中第 <code>i</code> 个查询对应范围 <code>[l[i], r[i]]</code> 。所有数组的下标都是 <strong>从 0 开始</strong> 的。</p>

<p>返回<em> </em><code>boolean</code> 元素构成的答案列表 <code>answer</code> 。如果子数组 <code>nums[l[i]], nums[l[i]+1], ... , nums[r[i]]</code> 可以 <strong>重新排列</strong> 形成 <strong>等差数列</strong> ，<code>answer[i]</code> 的值就是 <code>true</code>；否则<code>answer[i]</code> 的值就是 <code>false</code> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = <code>[4,6,5,9,3,7]</code>, l = <code>[0,0,2]</code>, r = <code>[2,3,5]</code>
<strong>输出：</strong><code>[true,false,true]</code>
<strong>解释：</strong>
第 0 个查询，对应子数组 [4,6,5] 。可以重新排列为等差数列 [6,5,4] 。
第 1 个查询，对应子数组 [4,6,5,9] 。无法重新排列形成等差数列。
第 2 个查询，对应子数组 <code>[5,9,3,7] 。</code>可以重新排列为等差数列 <code>[3,5,7,9] 。</code></pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [-12,-9,-3,-12,-6,15,20,-25,-20,-15,-10], l = [0,1,6,4,8,7], r = [4,4,9,7,9,10]
<strong>输出：</strong>[false,true,false,false,true,true]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>m == l.length</code></li>
	<li><code>m == r.length</code></li>
	<li><code>2 &lt;= n &lt;= 500</code></li>
	<li><code>1 &lt;= m &lt;= 500</code></li>
	<li><code>0 &lt;= l[i] &lt; r[i] &lt; n</code></li>
	<li><code>-10<sup>5</sup> &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数学 + 模拟

我们设计一个函数 $check(nums, l, r)$，用于判断子数组 $nums[l], nums[l+1], \dots, nums[r]$ 是否可以重新排列形成等差数列。

函数 $check(nums, l, r)$ 的实现逻辑如下：

-   首先，我们计算子数组的长度 $n = r - l + 1$，并将子数组中的元素放入集合 $s$ 中，方便后续的查找；
-   然后，我们获取子数组中的最小值 $a_1$ 和最大值 $a_n$，如果 $a_n - a_1$ 不能被 $n - 1$ 整除，那么子数组不可能形成等差数列，直接返回 $false$；否则，我们计算等差数列的公差 $d = \frac{a_n - a_1}{n - 1}$；
-   接下来从 $a_1$ 开始，依次计算等差数列中第 $i$ 项元素，如果第 $i$ 项元素 $a_1 + (i - 1) \times d$ 不在集合 $s$ 中，那么子数组不可能形成等差数列，直接返回 $false$；否则，当我们遍历完所有的元素，说明子数组可以重新排列形成等差数列，返回 $true$。

在主函数中，我们遍历所有的查询，对于每个查询 $l[i]$ 和 $r[i]$，我们调用函数 $check(nums, l[i], r[i])$ 判断子数组是否可以重新排列形成等差数列，将结果存入答案数组中。

时间复杂度 $O(n \times m)$，空间复杂度 $O(n)$。其中 $n$ 和 $m$ 分别为数组 $nums$ 的长度以及查询的组数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def checkArithmeticSubarrays(
        self, nums: List[int], l: List[int], r: List[int]
    ) -> List[bool]:
        def check(nums, l, r):
            n = r - l + 1
            s = set(nums[l : l + n])
            a1, an = min(nums[l : l + n]), max(nums[l : l + n])
            d, mod = divmod(an - a1, n - 1)
            return mod == 0 and all((a1 + (i - 1) * d) in s for i in range(1, n))

        return [check(nums, left, right) for left, right in zip(l, r)]
```

#### Java

```java
class Solution {
    public List<Boolean> checkArithmeticSubarrays(int[] nums, int[] l, int[] r) {
        List<Boolean> ans = new ArrayList<>();
        for (int i = 0; i < l.length; ++i) {
            ans.add(check(nums, l[i], r[i]));
        }
        return ans;
    }

    private boolean check(int[] nums, int l, int r) {
        Set<Integer> s = new HashSet<>();
        int n = r - l + 1;
        int a1 = 1 << 30, an = -a1;
        for (int i = l; i <= r; ++i) {
            s.add(nums[i]);
            a1 = Math.min(a1, nums[i]);
            an = Math.max(an, nums[i]);
        }
        if ((an - a1) % (n - 1) != 0) {
            return false;
        }
        int d = (an - a1) / (n - 1);
        for (int i = 1; i < n; ++i) {
            if (!s.contains(a1 + (i - 1) * d)) {
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
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        auto check = [](vector<int>& nums, int l, int r) {
            unordered_set<int> s;
            int n = r - l + 1;
            int a1 = 1 << 30, an = -a1;
            for (int i = l; i <= r; ++i) {
                s.insert(nums[i]);
                a1 = min(a1, nums[i]);
                an = max(an, nums[i]);
            }
            if ((an - a1) % (n - 1)) {
                return false;
            }
            int d = (an - a1) / (n - 1);
            for (int i = 1; i < n; ++i) {
                if (!s.count(a1 + (i - 1) * d)) {
                    return false;
                }
            }
            return true;
        };
        for (int i = 0; i < l.size(); ++i) {
            ans.push_back(check(nums, l[i], r[i]));
        }
        return ans;
    }
};
```

#### Go

```go
func checkArithmeticSubarrays(nums []int, l []int, r []int) (ans []bool) {
	check := func(nums []int, l, r int) bool {
		s := map[int]struct{}{}
		n := r - l + 1
		a1, an := 1<<30, -(1 << 30)
		for _, x := range nums[l : r+1] {
			s[x] = struct{}{}
			if a1 > x {
				a1 = x
			}
			if an < x {
				an = x
			}
		}
		if (an-a1)%(n-1) != 0 {
			return false
		}
		d := (an - a1) / (n - 1)
		for i := 1; i < n; i++ {
			if _, ok := s[a1+(i-1)*d]; !ok {
				return false
			}
		}
		return true
	}
	for i := range l {
		ans = append(ans, check(nums, l[i], r[i]))
	}
	return
}
```

#### TypeScript

```ts
function checkArithmeticSubarrays(nums: number[], l: number[], r: number[]): boolean[] {
    const check = (nums: number[], l: number, r: number): boolean => {
        const s = new Set<number>();
        const n = r - l + 1;
        let a1 = 1 << 30;
        let an = -a1;
        for (let i = l; i <= r; ++i) {
            s.add(nums[i]);
            a1 = Math.min(a1, nums[i]);
            an = Math.max(an, nums[i]);
        }
        if ((an - a1) % (n - 1) !== 0) {
            return false;
        }
        const d = Math.floor((an - a1) / (n - 1));
        for (let i = 1; i < n; ++i) {
            if (!s.has(a1 + (i - 1) * d)) {
                return false;
            }
        }
        return true;
    };
    const ans: boolean[] = [];
    for (let i = 0; i < l.length; ++i) {
        ans.push(check(nums, l[i], r[i]));
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn check_arithmetic_subarrays(nums: Vec<i32>, l: Vec<i32>, r: Vec<i32>) -> Vec<bool> {
        let m = l.len();
        let mut res = vec![true; m];
        for i in 0..m {
            let mut arr = nums[l[i] as usize..=r[i] as usize].to_vec();
            arr.sort();
            for j in 2..arr.len() {
                if arr[j - 2] - arr[j - 1] != arr[j - 1] - arr[j] {
                    res[i] = false;
                    break;
                }
            }
        }
        res
    }
}
```

#### C#

```cs
class Solution {
    public bool Check(int[] arr) {
        Array.Sort(arr);
        int diff = arr[1] - arr[0];
        for (int i = 2; i < arr.Length; i++) {
            if (arr[i] - arr[i - 1] != diff) {
                return false;
            }
        }
        return true;
    }

    public IList<bool> CheckArithmeticSubarrays(int[] nums, int[] l, int[] r) {
        List<bool> ans = new List<bool>();
        for (int i = 0; i < l.Length; i++) {
            int[] arr = new int[r[i] - l[i] + 1];
            for (int j = 0; j < arr.Length; j++) {
                arr[j] = nums[l[i] + j];
            }
            ans.Add(Check(arr));
        }
        return ans;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1631. 最小体力消耗路径](https://leetcode.cn/problems/path-with-minimum-effort){#1631}

{{< tabs "1631" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumEffortPath(self, heights: List[List[int]]) -> int:
        m, n = len(heights), len(heights[0])
        dist = [[inf] * n for _ in range(m)]
        dist[0][0] = 0
        dirs = (-1, 0, 1, 0, -1)
        q = [(0, 0, 0)]
        while q:
            t, i, j = heappop(q)
            for a, b in pairwise(dirs):
                x, y = i + a, j + b
                if (
                    0 <= x < m
                    and 0 <= y < n
                    and (d := max(t, abs(heights[i][j] - heights[x][y]))) < dist[x][y]
                ):
                    dist[x][y] = d
                    heappush(q, (d, x, y))
        return int(dist[-1][-1])
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumEffortPath(int[][] heights) {
        int m = heights.length, n = heights[0].length;
        int[][] dist = new int[m][n];
        for (var row : dist) {
            Arrays.fill(row, 1 << 30);
        }
        dist[0][0] = 0;
        int[] dirs = {-1, 0, 1, 0, -1};
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        pq.offer(new int[] {0, 0, 0});
        while (!pq.isEmpty()) {
            var p = pq.poll();
            int t = p[0], i = p[1], j = p[2];
            for (int k = 0; k < 4; ++k) {
                int x = i + dirs[k], y = j + dirs[k + 1];
                if (x >= 0 && x < m && y >= 0 && y < n) {
                    int d = Math.max(t, Math.abs(heights[x][y] - heights[i][j]));
                    if (d < dist[x][y]) {
                        dist[x][y] = d;
                        pq.offer(new int[] {d, x, y});
                    }
                }
            }
        }
        return dist[m - 1][n - 1];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        int dist[m][n];
        memset(dist, 0x3f, sizeof(dist));
        dist[0][0] = 0;
        int dirs[5] = {0, 1, 0, -1, 0};
        using T = tuple<int, int, int>;
        priority_queue<T, vector<T>, greater<T>> pq;
        pq.emplace(0, 0, 0);
        while (!pq.empty()) {
            auto [t, i, j] = pq.top();
            pq.pop();
            for (int k = 0; k < 4; ++k) {
                int x = i + dirs[k], y = j + dirs[k + 1];
                if (x < 0 || x >= m || y < 0 || y >= n) {
                    continue;
                }
                int d = max(t, abs(heights[x][y] - heights[i][j]));
                if (d < dist[x][y]) {
                    dist[x][y] = d;
                    pq.emplace(d, x, y);
                }
            }
        }
        return dist[m - 1][n - 1];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumEffortPath(heights [][]int) int {
	m, n := len(heights), len(heights[0])
	dist := make([][]int, m)
	for i := range dist {
		dist[i] = make([]int, n)
		for j := range dist[i] {
			dist[i][j] = 1 << 30
		}
	}
	dirs := [5]int{-1, 0, 1, 0, -1}
	dist[0][0] = 0
	pq := hp{}
	heap.Push(&pq, tuple{0, 0, 0})
	for pq.Len() > 0 {
		p := heap.Pop(&pq).(tuple)
		t, i, j := p.t, p.i, p.j
		for k := 0; k < 4; k++ {
			x, y := i+dirs[k], j+dirs[k+1]
			if x >= 0 && x < m && y >= 0 && y < n {
				if d := max(t, abs(heights[x][y]-heights[i][j])); d < dist[x][y] {
					dist[x][y] = d
					heap.Push(&pq, tuple{d, x, y})
				}
			}
		}
	}
	return dist[m-1][n-1]
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

type tuple struct{ t, i, j int }
type hp []tuple

func (h hp) Len() int           { return len(h) }
func (h hp) Less(i, j int) bool { return h[i].t < h[j].t }
func (h hp) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *hp) Push(v any)        { *h = append(*h, v.(tuple)) }
func (h *hp) Pop() any          { a := *h; v := a[len(a)-1]; *h = a[:len(a)-1]; return v }
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumEffortPath(heights: number[][]): number {
    const m = heights.length;
    const n = heights[0].length;
    const pq = new PriorityQueue({ compare: (a, b) => a[0] - b[0] });
    pq.enqueue([0, 0, 0]);
    const dist = Array.from({ length: m }, () => Array.from({ length: n }, () => Infinity));
    dist[0][0] = 0;
    const dirs = [-1, 0, 1, 0, -1];
    while (pq.size() > 0) {
        const [t, i, j] = pq.dequeue()!;
        for (let k = 0; k < 4; ++k) {
            const [x, y] = [i + dirs[k], j + dirs[k + 1]];
            if (x >= 0 && x < m && y >= 0 && y < n) {
                const d = Math.max(t, Math.abs(heights[x][y] - heights[i][j]));
                if (d < dist[x][y]) {
                    dist[x][y] = d;
                    pq.enqueue([d, x, y]);
                }
            }
        }
    }
    return dist[m - 1][n - 1];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你准备参加一场远足活动。给你一个二维 <code>rows x columns</code> 的地图 <code>heights</code> ，其中 <code>heights[row][col]</code> 表示格子 <code>(row, col)</code> 的高度。一开始你在最左上角的格子 <code>(0, 0)</code> ，且你希望去最右下角的格子 <code>(rows-1, columns-1)</code> （注意下标从 <strong>0</strong> 开始编号）。你每次可以往 <strong>上</strong>，<strong>下</strong>，<strong>左</strong>，<strong>右</strong> 四个方向之一移动，你想要找到耗费 <strong>体力</strong> 最小的一条路径。</p>

<p>一条路径耗费的 <strong>体力值</strong> 是路径上相邻格子之间 <strong>高度差绝对值</strong> 的 <strong>最大值</strong> 决定的。</p>

<p>请你返回从左上角走到右下角的最小<strong> 体力消耗值</strong> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1600-1699/1631.Path%20With%20Minimum%20Effort/images/ex1.png" style="width: 300px; height: 300px;" /></p>

<pre>
<b>输入：</b>heights = [[1,2,2],[3,8,2],[5,3,5]]
<b>输出：</b>2
<b>解释：</b>路径 [1,3,5,3,5] 连续格子的差值绝对值最大为 2 。
这条路径比路径 [1,2,2,2,5] 更优，因为另一条路径差值最大值为 3 。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1600-1699/1631.Path%20With%20Minimum%20Effort/images/ex2.png" style="width: 300px; height: 300px;" /></p>

<pre>
<b>输入：</b>heights = [[1,2,3],[3,8,4],[5,3,5]]
<b>输出：</b>1
<b>解释：</b>路径 [1,2,3,4,5] 的相邻格子差值绝对值最大为 1 ，比路径 [1,3,5,3,5] 更优。
</pre>

<p><strong>示例 3：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1600-1699/1631.Path%20With%20Minimum%20Effort/images/ex3.png" style="width: 300px; height: 300px;" />
<pre>
<b>输入：</b>heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
<b>输出：</b>0
<b>解释：</b>上图所示路径不需要消耗任何体力。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>rows == heights.length</code></li>
	<li><code>columns == heights[i].length</code></li>
	<li><code>1 <= rows, columns <= 100</code></li>
	<li><code>1 <= heights[i][j] <= 10<sup>6</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：并查集

对于本题，我们可以把每个格子当做图的一个节点，把相邻两个格子的高度差绝对值当做边的权重，因此本题是求解从最左上角的节点到最右下角的节点的连通性问题。

我们先构建一个边集，然后按照边的权重从小到大进行排序，逐个添加边，直到最左上角的节点和最右下角的节点连通为止，此时的边的权重就是题目的最小体力消耗值。

时间复杂度 $O(m \times n \times \log(m \times n))$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别是二维数组的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class UnionFind:
    def __init__(self, n):
        self.p = list(range(n))
        self.size = [1] * n

    def find(self, x):
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]

    def union(self, a, b):
        pa, pb = self.find(a), self.find(b)
        if pa == pb:
            return False
        if self.size[pa] > self.size[pb]:
            self.p[pb] = pa
            self.size[pa] += self.size[pb]
        else:
            self.p[pa] = pb
            self.size[pb] += self.size[pa]
        return True

    def connected(self, a, b):
        return self.find(a) == self.find(b)


class Solution:
    def minimumEffortPath(self, heights: List[List[int]]) -> int:
        m, n = len(heights), len(heights[0])
        uf = UnionFind(m * n)
        e = []
        dirs = (0, 1, 0)
        for i in range(m):
            for j in range(n):
                for a, b in pairwise(dirs):
                    x, y = i + a, j + b
                    if 0 <= x < m and 0 <= y < n:
                        e.append(
                            (abs(heights[i][j] - heights[x][y]), i * n + j, x * n + y)
                        )
        e.sort()
        for h, a, b in e:
            uf.union(a, b)
            if uf.connected(0, m * n - 1):
                return h
        return 0
```

#### Java

```java
class UnionFind {
    private final int[] p;
    private final int[] size;

    public UnionFind(int n) {
        p = new int[n];
        size = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
            size[i] = 1;
        }
    }

    public int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    public boolean union(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) {
            return false;
        }
        if (size[pa] > size[pb]) {
            p[pb] = pa;
            size[pa] += size[pb];
        } else {
            p[pa] = pb;
            size[pb] += size[pa];
        }
        return true;
    }

    public boolean connected(int a, int b) {
        return find(a) == find(b);
    }
}

class Solution {
    public int minimumEffortPath(int[][] heights) {
        int m = heights.length, n = heights[0].length;
        UnionFind uf = new UnionFind(m * n);
        List<int[]> edges = new ArrayList<>();
        int[] dirs = {1, 0, 1};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < 2; ++k) {
                    int x = i + dirs[k], y = j + dirs[k + 1];
                    if (x >= 0 && x < m && y >= 0 && y < n) {
                        int d = Math.abs(heights[i][j] - heights[x][y]);
                        edges.add(new int[] {d, i * n + j, x * n + y});
                    }
                }
            }
        }
        Collections.sort(edges, (a, b) -> a[0] - b[0]);
        for (int[] e : edges) {
            uf.union(e[1], e[2]);
            if (uf.connected(0, m * n - 1)) {
                return e[0];
            }
        }
        return 0;
    }
}
```

#### C++

```cpp
class UnionFind {
public:
    UnionFind(int n) {
        p = vector<int>(n);
        size = vector<int>(n, 1);
        iota(p.begin(), p.end(), 0);
    }

    bool unite(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) {
            return false;
        }
        if (size[pa] > size[pb]) {
            p[pb] = pa;
            size[pa] += size[pb];
        } else {
            p[pa] = pb;
            size[pb] += size[pa];
        }
        return true;
    }

    int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    bool connected(int a, int b) {
        return find(a) == find(b);
    }

private:
    vector<int> p, size;
};

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<array<int, 3>> edges;
        int dirs[3] = {0, 1, 0};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < 2; ++k) {
                    int x = i + dirs[k], y = j + dirs[k + 1];
                    if (x >= 0 && x < m && y >= 0 && y < n) {
                        edges.push_back({abs(heights[i][j] - heights[x][y]), i * n + j, x * n + y});
                    }
                }
            }
        }
        sort(edges.begin(), edges.end());
        UnionFind uf(m * n);
        for (auto& [h, a, b] : edges) {
            uf.unite(a, b);
            if (uf.connected(0, m * n - 1)) {
                return h;
            }
        }
        return 0;
    }
};
```

#### Go

```go
type unionFind struct {
	p, size []int
}

func newUnionFind(n int) *unionFind {
	p := make([]int, n)
	size := make([]int, n)
	for i := range p {
		p[i] = i
		size[i] = 1
	}
	return &unionFind{p, size}
}

func (uf *unionFind) find(x int) int {
	if uf.p[x] != x {
		uf.p[x] = uf.find(uf.p[x])
	}
	return uf.p[x]
}

func (uf *unionFind) union(a, b int) bool {
	pa, pb := uf.find(a), uf.find(b)
	if pa == pb {
		return false
	}
	if uf.size[pa] > uf.size[pb] {
		uf.p[pb] = pa
		uf.size[pa] += uf.size[pb]
	} else {
		uf.p[pa] = pb
		uf.size[pb] += uf.size[pa]
	}
	return true
}

func (uf *unionFind) connected(a, b int) bool {
	return uf.find(a) == uf.find(b)
}

func minimumEffortPath(heights [][]int) int {
	m, n := len(heights), len(heights[0])
	edges := make([][3]int, 0, m*n*2)
	dirs := [3]int{0, 1, 0}
	for i, row := range heights {
		for j, h := range row {
			for k := 0; k < 2; k++ {
				x, y := i+dirs[k], j+dirs[k+1]
				if x >= 0 && x < m && y >= 0 && y < n {
					edges = append(edges, [3]int{abs(h - heights[x][y]), i*n + j, x*n + y})
				}
			}
		}
	}
	sort.Slice(edges, func(i, j int) bool { return edges[i][0] < edges[j][0] })
	uf := newUnionFind(m * n)
	for _, e := range edges {
		uf.union(e[1], e[2])
		if uf.connected(0, m*n-1) {
			return e[0]
		}
	}
	return 0
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
class UnionFind {
    private p: number[];
    private size: number[];

    constructor(n: number) {
        this.p = Array.from({ length: n }, (_, i) => i);
        this.size = Array(n).fill(1);
    }

    find(x: number): number {
        if (this.p[x] !== x) {
            this.p[x] = this.find(this.p[x]);
        }
        return this.p[x];
    }

    union(a: number, b: number): boolean {
        const pa = this.find(a);
        const pb = this.find(b);
        if (pa === pb) {
            return false;
        }
        if (this.size[pa] > this.size[pb]) {
            this.p[pb] = pa;
            this.size[pa] += this.size[pb];
        } else {
            this.p[pa] = pb;
            this.size[pb] += this.size[pa];
        }
        return true;
    }

    connected(a: number, b: number): boolean {
        return this.find(a) === this.find(b);
    }
}

function minimumEffortPath(heights: number[][]): number {
    const m = heights.length;
    const n = heights[0].length;
    const uf = new UnionFind(m * n);
    const edges: number[][] = [];
    const dirs = [1, 0, 1];

    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            for (let k = 0; k < 2; ++k) {
                const x = i + dirs[k];
                const y = j + dirs[k + 1];
                if (x >= 0 && x < m && y >= 0 && y < n) {
                    const d = Math.abs(heights[i][j] - heights[x][y]);
                    edges.push([d, i * n + j, x * n + y]);
                }
            }
        }
    }

    edges.sort((a, b) => a[0] - b[0]);

    for (const [h, a, b] of edges) {
        uf.union(a, b);
        if (uf.connected(0, m * n - 1)) {
            return h;
        }
    }

    return 0;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：二分查找 + BFS

我们注意到，如果一个路径的最大体力消耗值为 $x$，那么对于任意 $y > x$，该路径也是满足条件的，这存在着单调性，因此我们可以使用二分查找的方法，找到最小的满足条件的体力消耗值。

我们定义二分查找的左边界 $l=0$，右边界 $r=10^6$，每次取 $mid=(l+r)/2$，然后使用 BFS 判断是否存在一条从左上角到右下角的路径，使得路径上相邻节点的高度差绝对值都不大于 $mid$，如果存在，那么说明 $mid$ 还有可能是最小的满足条件的体力消耗值，因此令 $r=mid$，否则令 $l=mid+1$。

时间复杂度 $O(m \times n \times \log M)$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别是二维数组的行数和列数，而 $M$ 是二维数组中的最大值，本题中 $M=10^6$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumEffortPath(self, heights: List[List[int]]) -> int:
        def check(h: int) -> bool:
            q = deque([(0, 0)])
            vis = {(0, 0)}
            dirs = (-1, 0, 1, 0, -1)
            while q:
                for _ in range(len(q)):
                    i, j = q.popleft()
                    if i == m - 1 and j == n - 1:
                        return True
                    for a, b in pairwise(dirs):
                        x, y = i + a, j + b
                        if (
                            0 <= x < m
                            and 0 <= y < n
                            and (x, y) not in vis
                            and abs(heights[i][j] - heights[x][y]) <= h
                        ):
                            q.append((x, y))
                            vis.add((x, y))
            return False

        m, n = len(heights), len(heights[0])
        return bisect_left(range(10**6), True, key=check)
```

#### Java

```java
class Solution {
    public int minimumEffortPath(int[][] heights) {
        int l = 0, r = 1000000;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(heights, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }

    private boolean check(int[][] heights, int h) {
        int m = heights.length, n = heights[0].length;
        boolean[][] vis = new boolean[m][n];
        Deque<int[]> q = new ArrayDeque<>();
        q.add(new int[] {0, 0});
        vis[0][0] = true;
        int[] dirs = {-1, 0, 1, 0, -1};
        while (!q.isEmpty()) {
            var p = q.poll();
            int i = p[0], j = p[1];
            if (i == m - 1 && j == n - 1) {
                return true;
            }
            for (int k = 0; k < 4; ++k) {
                int x = i + dirs[k], y = j + dirs[k + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y]
                    && Math.abs(heights[x][y] - heights[i][j]) <= h) {
                    q.add(new int[] {x, y});
                    vis[x][y] = true;
                }
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
    int minimumEffortPath(vector<vector<int>>& heights) {
        auto check = [&](int h) {
            int m = heights.size(), n = heights[0].size();
            bool vis[m][n];
            memset(vis, false, sizeof(vis));
            queue<pair<int, int>> q{{{0, 0}}};
            vis[0][0] = true;
            int dirs[5] = {-1, 0, 1, 0, -1};
            while (!q.empty()) {
                auto [i, j] = q.front();
                q.pop();
                if (i == m - 1 && j == n - 1) {
                    return true;
                }
                for (int k = 0; k < 4; ++k) {
                    int x = i + dirs[k], y = j + dirs[k + 1];
                    if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && abs(heights[x][y] - heights[i][j]) <= h) {
                        q.push({x, y});
                        vis[x][y] = true;
                    }
                }
            }
            return false;
        };
        int l = 0, r = 1e6;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(mid)) {
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
func minimumEffortPath(heights [][]int) int {
	return sort.Search(1e6, func(h int) bool {
		m, n := len(heights), len(heights[0])
		vis := make([][]bool, m)
		for i := range vis {
			vis[i] = make([]bool, n)
		}
		vis[0][0] = true
		q := [][2]int{}
		q = append(q, [2]int{0, 0})
		dirs := [5]int{-1, 0, 1, 0, -1}
		for len(q) > 0 {
			p := q[0]
			q = q[1:]
			i, j := p[0], p[1]
			if i == m-1 && j == n-1 {
				return true
			}
			for k := 0; k < 4; k++ {
				x, y := i+dirs[k], j+dirs[k+1]
				if x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && abs(heights[x][y]-heights[i][j]) <= h {
					vis[x][y] = true
					q = append(q, [2]int{x, y})
				}
			}
		}
		return false
	})
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
function minimumEffortPath(heights: number[][]): number {
    const check = (h: number): boolean => {
        const m = heights.length;
        const n = heights[0].length;
        const vis: boolean[][] = Array.from({ length: m }, () => Array(n).fill(false));
        const dirs: number[] = [-1, 0, 1, 0, -1];
        const q: [number, number][] = [[0, 0]];
        vis[0][0] = true;

        while (q.length > 0) {
            const [i, j] = q.pop()!;
            if (i === m - 1 && j === n - 1) {
                return true;
            }

            for (let k = 0; k < 4; ++k) {
                const x = i + dirs[k];
                const y = j + dirs[k + 1];
                if (
                    x >= 0 &&
                    x < m &&
                    y >= 0 &&
                    y < n &&
                    !vis[x][y] &&
                    Math.abs(heights[x][y] - heights[i][j]) <= h
                ) {
                    q.push([x, y]);
                    vis[x][y] = true;
                }
            }
        }
        return false;
    };

    let [l, r] = [0, 10 ** 6];
    while (l < r) {
        const mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法三：堆优化的 Dijkstra 算法

我们可以把每个格子当做图的一个节点，把相邻两个格子的高度差绝对值当做边的权重，因此本题是求解从最左上角的节点到最右下角的节点的最短路径问题。

我们可以使用 Dijkstra 算法求解最短路径，使用优先队列（堆）来优化时间复杂度。具体地，我们维护一个大小为 $m \times n$ 的二维数组 $dist$，其中 $dist[i][j]$ 表示从左上角到节点 $(i,j)$ 的最短路径的最大权重，初始时 $dist[0][0]=0$，其余元素均为正无穷大。

我们用优先队列（堆）来存储节点，每次从优先队列（堆）中取出权重最小的节点，然后更新其相邻节点的权重，如果相邻节点的权重发生了改变，那么就把该节点加入优先队列（堆）中。当优先队列（堆）为空时，说明我们已经找到了最短路径。

时间复杂度 $O(m \times n \times \log(m \times n))$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别是二维数组的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumEffortPath(self, heights: List[List[int]]) -> int:
        m, n = len(heights), len(heights[0])
        dist = [[inf] * n for _ in range(m)]
        dist[0][0] = 0
        dirs = (-1, 0, 1, 0, -1)
        q = [(0, 0, 0)]
        while q:
            t, i, j = heappop(q)
            for a, b in pairwise(dirs):
                x, y = i + a, j + b
                if (
                    0 <= x < m
                    and 0 <= y < n
                    and (d := max(t, abs(heights[i][j] - heights[x][y]))) < dist[x][y]
                ):
                    dist[x][y] = d
                    heappush(q, (d, x, y))
        return int(dist[-1][-1])
```

#### Java

```java
class Solution {
    public int minimumEffortPath(int[][] heights) {
        int m = heights.length, n = heights[0].length;
        int[][] dist = new int[m][n];
        for (var row : dist) {
            Arrays.fill(row, 1 << 30);
        }
        dist[0][0] = 0;
        int[] dirs = {-1, 0, 1, 0, -1};
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        pq.offer(new int[] {0, 0, 0});
        while (!pq.isEmpty()) {
            var p = pq.poll();
            int t = p[0], i = p[1], j = p[2];
            for (int k = 0; k < 4; ++k) {
                int x = i + dirs[k], y = j + dirs[k + 1];
                if (x >= 0 && x < m && y >= 0 && y < n) {
                    int d = Math.max(t, Math.abs(heights[x][y] - heights[i][j]));
                    if (d < dist[x][y]) {
                        dist[x][y] = d;
                        pq.offer(new int[] {d, x, y});
                    }
                }
            }
        }
        return dist[m - 1][n - 1];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        int dist[m][n];
        memset(dist, 0x3f, sizeof(dist));
        dist[0][0] = 0;
        int dirs[5] = {0, 1, 0, -1, 0};
        using T = tuple<int, int, int>;
        priority_queue<T, vector<T>, greater<T>> pq;
        pq.emplace(0, 0, 0);
        while (!pq.empty()) {
            auto [t, i, j] = pq.top();
            pq.pop();
            for (int k = 0; k < 4; ++k) {
                int x = i + dirs[k], y = j + dirs[k + 1];
                if (x < 0 || x >= m || y < 0 || y >= n) {
                    continue;
                }
                int d = max(t, abs(heights[x][y] - heights[i][j]));
                if (d < dist[x][y]) {
                    dist[x][y] = d;
                    pq.emplace(d, x, y);
                }
            }
        }
        return dist[m - 1][n - 1];
    }
};
```

#### Go

```go
func minimumEffortPath(heights [][]int) int {
	m, n := len(heights), len(heights[0])
	dist := make([][]int, m)
	for i := range dist {
		dist[i] = make([]int, n)
		for j := range dist[i] {
			dist[i][j] = 1 << 30
		}
	}
	dirs := [5]int{-1, 0, 1, 0, -1}
	dist[0][0] = 0
	pq := hp{}
	heap.Push(&pq, tuple{0, 0, 0})
	for pq.Len() > 0 {
		p := heap.Pop(&pq).(tuple)
		t, i, j := p.t, p.i, p.j
		for k := 0; k < 4; k++ {
			x, y := i+dirs[k], j+dirs[k+1]
			if x >= 0 && x < m && y >= 0 && y < n {
				if d := max(t, abs(heights[x][y]-heights[i][j])); d < dist[x][y] {
					dist[x][y] = d
					heap.Push(&pq, tuple{d, x, y})
				}
			}
		}
	}
	return dist[m-1][n-1]
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

type tuple struct{ t, i, j int }
type hp []tuple

func (h hp) Len() int           { return len(h) }
func (h hp) Less(i, j int) bool { return h[i].t < h[j].t }
func (h hp) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *hp) Push(v any)        { *h = append(*h, v.(tuple)) }
func (h *hp) Pop() any          { a := *h; v := a[len(a)-1]; *h = a[:len(a)-1]; return v }
```

#### TypeScript

```ts
function minimumEffortPath(heights: number[][]): number {
    const m = heights.length;
    const n = heights[0].length;
    const pq = new PriorityQueue({ compare: (a, b) => a[0] - b[0] });
    pq.enqueue([0, 0, 0]);
    const dist = Array.from({ length: m }, () => Array.from({ length: n }, () => Infinity));
    dist[0][0] = 0;
    const dirs = [-1, 0, 1, 0, -1];
    while (pq.size() > 0) {
        const [t, i, j] = pq.dequeue()!;
        for (let k = 0; k < 4; ++k) {
            const [x, y] = [i + dirs[k], j + dirs[k + 1]];
            if (x >= 0 && x < m && y >= 0 && y < n) {
                const d = Math.max(t, Math.abs(heights[x][y] - heights[i][j]));
                if (d < dist[x][y]) {
                    dist[x][y] = d;
                    pq.enqueue([d, x, y]);
                }
            }
        }
    }
    return dist[m - 1][n - 1];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1632. 矩阵转换后的秩](https://leetcode.cn/problems/rank-transform-of-a-matrix){#1632}

{{< tabs "1632" >}}

{{% tab "python" %}}
```python
class UnionFind:
    def __init__(self, n):
        self.p = list(range(n))
        self.size = [1] * n

    def find(self, x):
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]

    def union(self, a, b):
        pa, pb = self.find(a), self.find(b)
        if pa != pb:
            if self.size[pa] > self.size[pb]:
                self.p[pb] = pa
                self.size[pa] += self.size[pb]
            else:
                self.p[pa] = pb
                self.size[pb] += self.size[pa]

    def reset(self, x):
        self.p[x] = x
        self.size[x] = 1


class Solution:
    def matrixRankTransform(self, matrix: List[List[int]]) -> List[List[int]]:
        m, n = len(matrix), len(matrix[0])
        d = defaultdict(list)
        for i, row in enumerate(matrix):
            for j, v in enumerate(row):
                d[v].append((i, j))
        row_max = [0] * m
        col_max = [0] * n
        ans = [[0] * n for _ in range(m)]
        uf = UnionFind(m + n)
        for v in sorted(d):
            rank = defaultdict(int)
            for i, j in d[v]:
                uf.union(i, j + m)
            for i, j in d[v]:
                rank[uf.find(i)] = max(rank[uf.find(i)], row_max[i], col_max[j])
            for i, j in d[v]:
                ans[i][j] = row_max[i] = col_max[j] = 1 + rank[uf.find(i)]
            for i, j in d[v]:
                uf.reset(i)
                uf.reset(j + m)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class UnionFind {
    private int[] p;
    private int[] size;

    public UnionFind(int n) {
        p = new int[n];
        size = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
            size[i] = 1;
        }
    }

    public int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    public void union(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa != pb) {
            if (size[pa] > size[pb]) {
                p[pb] = pa;
                size[pa] += size[pb];
            } else {
                p[pa] = pb;
                size[pb] += size[pa];
            }
        }
    }

    public void reset(int x) {
        p[x] = x;
        size[x] = 1;
    }
}

class Solution {
    public int[][] matrixRankTransform(int[][] matrix) {
        int m = matrix.length, n = matrix[0].length;
        TreeMap<Integer, List<int[]>> d = new TreeMap<>();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                d.computeIfAbsent(matrix[i][j], k -> new ArrayList<>()).add(new int[] {i, j});
            }
        }
        int[] rowMax = new int[m];
        int[] colMax = new int[n];
        int[][] ans = new int[m][n];
        UnionFind uf = new UnionFind(m + n);
        int[] rank = new int[m + n];
        for (var ps : d.values()) {
            for (var p : ps) {
                uf.union(p[0], p[1] + m);
            }
            for (var p : ps) {
                int i = p[0], j = p[1];
                rank[uf.find(i)] = Math.max(rank[uf.find(i)], Math.max(rowMax[i], colMax[j]));
            }
            for (var p : ps) {
                int i = p[0], j = p[1];
                ans[i][j] = 1 + rank[uf.find(i)];
                rowMax[i] = ans[i][j];
                colMax[j] = ans[i][j];
            }
            for (var p : ps) {
                uf.reset(p[0]);
                uf.reset(p[1] + m);
            }
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class UnionFind {
public:
    UnionFind(int n) {
        p = vector<int>(n);
        size = vector<int>(n, 1);
        iota(p.begin(), p.end(), 0);
    }

    void unite(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa != pb) {
            if (size[pa] > size[pb]) {
                p[pb] = pa;
                size[pa] += size[pb];
            } else {
                p[pa] = pb;
                size[pb] += size[pa];
            }
        }
    }

    int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    void reset(int x) {
        p[x] = x;
        size[x] = 1;
    }

private:
    vector<int> p, size;
};

class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        map<int, vector<pair<int, int>>> d;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                d[matrix[i][j]].push_back({i, j});
            }
        }
        vector<int> rowMax(m);
        vector<int> colMax(n);
        vector<vector<int>> ans(m, vector<int>(n));
        UnionFind uf(m + n);
        vector<int> rank(m + n);
        for (auto& [_, ps] : d) {
            for (auto& [i, j] : ps) {
                uf.unite(i, j + m);
            }
            for (auto& [i, j] : ps) {
                rank[uf.find(i)] = max({rank[uf.find(i)], rowMax[i], colMax[j]});
            }
            for (auto& [i, j] : ps) {
                ans[i][j] = rowMax[i] = colMax[j] = 1 + rank[uf.find(i)];
            }
            for (auto& [i, j] : ps) {
                uf.reset(i);
                uf.reset(j + m);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
type unionFind struct {
	p, size []int
}

func newUnionFind(n int) *unionFind {
	p := make([]int, n)
	size := make([]int, n)
	for i := range p {
		p[i] = i
		size[i] = 1
	}
	return &unionFind{p, size}
}

func (uf *unionFind) find(x int) int {
	if uf.p[x] != x {
		uf.p[x] = uf.find(uf.p[x])
	}
	return uf.p[x]
}

func (uf *unionFind) union(a, b int) {
	pa, pb := uf.find(a), uf.find(b)
	if pa != pb {
		if uf.size[pa] > uf.size[pb] {
			uf.p[pb] = pa
			uf.size[pa] += uf.size[pb]
		} else {
			uf.p[pa] = pb
			uf.size[pb] += uf.size[pa]
		}
	}
}

func (uf *unionFind) reset(x int) {
	uf.p[x] = x
	uf.size[x] = 1
}

func matrixRankTransform(matrix [][]int) [][]int {
	m, n := len(matrix), len(matrix[0])
	type pair struct{ i, j int }
	d := map[int][]pair{}
	for i, row := range matrix {
		for j, v := range row {
			d[v] = append(d[v], pair{i, j})
		}
	}
	rowMax := make([]int, m)
	colMax := make([]int, n)
	ans := make([][]int, m)
	for i := range ans {
		ans[i] = make([]int, n)
	}
	vs := []int{}
	for v := range d {
		vs = append(vs, v)
	}
	sort.Ints(vs)
	uf := newUnionFind(m + n)
	rank := make([]int, m+n)
	for _, v := range vs {
		ps := d[v]
		for _, p := range ps {
			uf.union(p.i, p.j+m)
		}
		for _, p := range ps {
			i, j := p.i, p.j
			rank[uf.find(i)] = max(rank[uf.find(i)], max(rowMax[i], colMax[j]))
		}
		for _, p := range ps {
			i, j := p.i, p.j
			ans[i][j] = 1 + rank[uf.find(i)]
			rowMax[i], colMax[j] = ans[i][j], ans[i][j]
		}
		for _, p := range ps {
			uf.reset(p.i)
			uf.reset(p.j + m)
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

<p>给你一个&nbsp;<code>m x n</code>&nbsp;的矩阵 <code>matrix</code>&nbsp;，请你返回一个新的矩阵<em>&nbsp;</em><code>answer</code>&nbsp;，其中<em>&nbsp;</em><code>answer[row][col]</code>&nbsp;是&nbsp;<code>matrix[row][col]</code>&nbsp;的秩。</p>

<p>每个元素的&nbsp;<b>秩</b>&nbsp;是一个整数，表示这个元素相对于其他元素的大小关系，它按照如下规则计算：</p>

<ul>
	<li>秩是从 1 开始的一个整数。</li>
	<li>如果两个元素&nbsp;<code>p</code> 和&nbsp;<code>q</code>&nbsp;在 <strong>同一行</strong>&nbsp;或者 <strong>同一列</strong>&nbsp;，那么：
	<ul>
		<li>如果&nbsp;<code>p &lt; q</code> ，那么&nbsp;<code>rank(p) &lt; rank(q)</code></li>
		<li>如果&nbsp;<code>p == q</code>&nbsp;，那么&nbsp;<code>rank(p) == rank(q)</code></li>
		<li>如果&nbsp;<code>p &gt; q</code>&nbsp;，那么&nbsp;<code>rank(p) &gt; rank(q)</code></li>
	</ul>
	</li>
	<li><b>秩</b>&nbsp;需要越 <strong>小</strong>&nbsp;越好。</li>
</ul>

<p>题目保证按照上面规则&nbsp;<code>answer</code>&nbsp;数组是唯一的。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1600-1699/1632.Rank%20Transform%20of%20a%20Matrix/images/rank1.jpg" style="width: 442px; height: 162px;" />
<pre>
<b>输入：</b>matrix = [[1,2],[3,4]]
<b>输出：</b>[[1,2],[2,3]]
<strong>解释：</strong>
matrix[0][0] 的秩为 1 ，因为它是所在行和列的最小整数。
matrix[0][1] 的秩为 2 ，因为 matrix[0][1] &gt; matrix[0][0] 且 matrix[0][0] 的秩为 1 。
matrix[1][0] 的秩为 2 ，因为 matrix[1][0] &gt; matrix[0][0] 且 matrix[0][0] 的秩为 1 。
matrix[1][1] 的秩为 3 ，因为 matrix[1][1] &gt; matrix[0][1]， matrix[1][1] &gt; matrix[1][0] 且 matrix[0][1] 和 matrix[1][0] 的秩都为 2 。
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1600-1699/1632.Rank%20Transform%20of%20a%20Matrix/images/rank2.jpg" style="width: 442px; height: 162px;" />
<pre>
<b>输入：</b>matrix = [[7,7],[7,7]]
<b>输出：</b>[[1,1],[1,1]]
</pre>

<p><strong>示例 3：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1600-1699/1632.Rank%20Transform%20of%20a%20Matrix/images/rank3.jpg" style="width: 601px; height: 322px;" />
<pre>
<b>输入：</b>matrix = [[20,-21,14],[-19,4,19],[22,-47,24],[-19,4,19]]
<b>输出：</b>[[4,2,3],[1,3,4],[5,1,6],[1,3,4]]
</pre>

<p>&nbsp;</p>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == matrix.length</code></li>
	<li><code>n == matrix[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 500</code></li>
	<li><code>-10<sup>9</sup> &lt;= matrix[row][col] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 并查集

我们先考虑简化情形：没有相同的元素。那么显然最小的元素的秩为 $1$，第二小的元素则要考虑是否和最小元素同行或同列。于是得到贪心解法：从小到大遍历元素，并维护每行、每列的最大秩，该元素的秩即为同行、同列的最大秩加 $1$。见题目：[2371. 最小化网格中的最大值](https://github.com/doocs/leetcode/blob/main/solution/2300-2399/2371.Minimize%20Maximum%20Value%20in%20a%20Grid/README.md)。

存在相同元素时则较为复杂，假设两个相同元素同行（或同列），那么就要考虑到两个元素分别对应的行（或列）的最大秩。同时还可能出现联动，比如元素 `a` 和 `b` 同行，`b` 和 `c` 同列，那么要同时考虑这三个元素。

这种联动容易想到并查集，于是我们用并查集将元素分为几个连通块，对于每个连通块，里面所有元素对应的行或列的最大秩加 $1$，即为该连通块内所有元素的秩。

时间复杂度 $O(m \times n \times \log(m \times n))$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别为矩阵的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class UnionFind:
    def __init__(self, n):
        self.p = list(range(n))
        self.size = [1] * n

    def find(self, x):
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]

    def union(self, a, b):
        pa, pb = self.find(a), self.find(b)
        if pa != pb:
            if self.size[pa] > self.size[pb]:
                self.p[pb] = pa
                self.size[pa] += self.size[pb]
            else:
                self.p[pa] = pb
                self.size[pb] += self.size[pa]

    def reset(self, x):
        self.p[x] = x
        self.size[x] = 1


class Solution:
    def matrixRankTransform(self, matrix: List[List[int]]) -> List[List[int]]:
        m, n = len(matrix), len(matrix[0])
        d = defaultdict(list)
        for i, row in enumerate(matrix):
            for j, v in enumerate(row):
                d[v].append((i, j))
        row_max = [0] * m
        col_max = [0] * n
        ans = [[0] * n for _ in range(m)]
        uf = UnionFind(m + n)
        for v in sorted(d):
            rank = defaultdict(int)
            for i, j in d[v]:
                uf.union(i, j + m)
            for i, j in d[v]:
                rank[uf.find(i)] = max(rank[uf.find(i)], row_max[i], col_max[j])
            for i, j in d[v]:
                ans[i][j] = row_max[i] = col_max[j] = 1 + rank[uf.find(i)]
            for i, j in d[v]:
                uf.reset(i)
                uf.reset(j + m)
        return ans
```

#### Java

```java
class UnionFind {
    private int[] p;
    private int[] size;

    public UnionFind(int n) {
        p = new int[n];
        size = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
            size[i] = 1;
        }
    }

    public int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    public void union(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa != pb) {
            if (size[pa] > size[pb]) {
                p[pb] = pa;
                size[pa] += size[pb];
            } else {
                p[pa] = pb;
                size[pb] += size[pa];
            }
        }
    }

    public void reset(int x) {
        p[x] = x;
        size[x] = 1;
    }
}

class Solution {
    public int[][] matrixRankTransform(int[][] matrix) {
        int m = matrix.length, n = matrix[0].length;
        TreeMap<Integer, List<int[]>> d = new TreeMap<>();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                d.computeIfAbsent(matrix[i][j], k -> new ArrayList<>()).add(new int[] {i, j});
            }
        }
        int[] rowMax = new int[m];
        int[] colMax = new int[n];
        int[][] ans = new int[m][n];
        UnionFind uf = new UnionFind(m + n);
        int[] rank = new int[m + n];
        for (var ps : d.values()) {
            for (var p : ps) {
                uf.union(p[0], p[1] + m);
            }
            for (var p : ps) {
                int i = p[0], j = p[1];
                rank[uf.find(i)] = Math.max(rank[uf.find(i)], Math.max(rowMax[i], colMax[j]));
            }
            for (var p : ps) {
                int i = p[0], j = p[1];
                ans[i][j] = 1 + rank[uf.find(i)];
                rowMax[i] = ans[i][j];
                colMax[j] = ans[i][j];
            }
            for (var p : ps) {
                uf.reset(p[0]);
                uf.reset(p[1] + m);
            }
        }
        return ans;
    }
}
```

#### C++

```cpp
class UnionFind {
public:
    UnionFind(int n) {
        p = vector<int>(n);
        size = vector<int>(n, 1);
        iota(p.begin(), p.end(), 0);
    }

    void unite(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa != pb) {
            if (size[pa] > size[pb]) {
                p[pb] = pa;
                size[pa] += size[pb];
            } else {
                p[pa] = pb;
                size[pb] += size[pa];
            }
        }
    }

    int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    void reset(int x) {
        p[x] = x;
        size[x] = 1;
    }

private:
    vector<int> p, size;
};

class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        map<int, vector<pair<int, int>>> d;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                d[matrix[i][j]].push_back({i, j});
            }
        }
        vector<int> rowMax(m);
        vector<int> colMax(n);
        vector<vector<int>> ans(m, vector<int>(n));
        UnionFind uf(m + n);
        vector<int> rank(m + n);
        for (auto& [_, ps] : d) {
            for (auto& [i, j] : ps) {
                uf.unite(i, j + m);
            }
            for (auto& [i, j] : ps) {
                rank[uf.find(i)] = max({rank[uf.find(i)], rowMax[i], colMax[j]});
            }
            for (auto& [i, j] : ps) {
                ans[i][j] = rowMax[i] = colMax[j] = 1 + rank[uf.find(i)];
            }
            for (auto& [i, j] : ps) {
                uf.reset(i);
                uf.reset(j + m);
            }
        }
        return ans;
    }
};
```

#### Go

```go
type unionFind struct {
	p, size []int
}

func newUnionFind(n int) *unionFind {
	p := make([]int, n)
	size := make([]int, n)
	for i := range p {
		p[i] = i
		size[i] = 1
	}
	return &unionFind{p, size}
}

func (uf *unionFind) find(x int) int {
	if uf.p[x] != x {
		uf.p[x] = uf.find(uf.p[x])
	}
	return uf.p[x]
}

func (uf *unionFind) union(a, b int) {
	pa, pb := uf.find(a), uf.find(b)
	if pa != pb {
		if uf.size[pa] > uf.size[pb] {
			uf.p[pb] = pa
			uf.size[pa] += uf.size[pb]
		} else {
			uf.p[pa] = pb
			uf.size[pb] += uf.size[pa]
		}
	}
}

func (uf *unionFind) reset(x int) {
	uf.p[x] = x
	uf.size[x] = 1
}

func matrixRankTransform(matrix [][]int) [][]int {
	m, n := len(matrix), len(matrix[0])
	type pair struct{ i, j int }
	d := map[int][]pair{}
	for i, row := range matrix {
		for j, v := range row {
			d[v] = append(d[v], pair{i, j})
		}
	}
	rowMax := make([]int, m)
	colMax := make([]int, n)
	ans := make([][]int, m)
	for i := range ans {
		ans[i] = make([]int, n)
	}
	vs := []int{}
	for v := range d {
		vs = append(vs, v)
	}
	sort.Ints(vs)
	uf := newUnionFind(m + n)
	rank := make([]int, m+n)
	for _, v := range vs {
		ps := d[v]
		for _, p := range ps {
			uf.union(p.i, p.j+m)
		}
		for _, p := range ps {
			i, j := p.i, p.j
			rank[uf.find(i)] = max(rank[uf.find(i)], max(rowMax[i], colMax[j]))
		}
		for _, p := range ps {
			i, j := p.i, p.j
			ans[i][j] = 1 + rank[uf.find(i)]
			rowMax[i], colMax[j] = ans[i][j], ans[i][j]
		}
		for _, p := range ps {
			uf.reset(p.i)
			uf.reset(p.j + m)
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

# [1633. 各赛事的用户注册率](https://leetcode.cn/problems/percentage-of-users-attended-a-contest){#1633}

{{< tabs "1633" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT
    contest_id,
    ROUND(COUNT(1) * 100 / (SELECT COUNT(1) FROM Users), 2) AS percentage
FROM Register
GROUP BY 1
ORDER BY 2 DESC, 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>用户表：&nbsp;<code>Users</code></p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| user_id     | int     |
| user_name   | varchar |
+-------------+---------+
user_id 是该表的主键(具有唯一值的列)。
该表中的每行包括用户 ID 和用户名。</pre>

<p>&nbsp;</p>

<p>注册表：&nbsp;<code>Register</code></p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| contest_id  | int     |
| user_id     | int     |
+-------------+---------+
(contest_id, user_id) 是该表的主键(具有唯一值的列的组合)。
该表中的每行包含用户的 ID 和他们注册的赛事。</pre>

<p>&nbsp;</p>

<p>编写解决方案统计出各赛事的用户注册百分率，保留两位小数。</p>

<p>返回的结果表按&nbsp;<code>percentage</code>&nbsp;的&nbsp;<strong>降序&nbsp;</strong>排序，若相同则按&nbsp;<code>contest_id</code>&nbsp;的&nbsp;<strong>升序&nbsp;</strong>排序。</p>

<p>返回结果如下示例所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<code><strong>输入：</strong>
Users</code> 表：
+---------+-----------+
| user_id | user_name |
+---------+-----------+
| 6       | Alice     |
| 2       | Bob       |
| 7       | Alex      |
+---------+-----------+

<code>Register</code> 表：
+------------+---------+
| contest_id | user_id |
+------------+---------+
| 215        | 6       |
| 209        | 2       |
| 208        | 2       |
| 210        | 6       |
| 208        | 6       |
| 209        | 7       |
| 209        | 6       |
| 215        | 7       |
| 208        | 7       |
| 210        | 2       |
| 207        | 2       |
| 210        | 7       |
+------------+---------+
<strong>输出：</strong>
+------------+------------+
| contest_id | percentage |
+------------+------------+
| 208        | 100.0      |
| 209        | 100.0      |
| 210        | 100.0      |
| 215        | 66.67      |
| 207        | 33.33      |
+------------+------------+
<strong>解释：</strong>
所有用户都注册了 208、209 和 210 赛事，因此这些赛事的注册率为 100% ，我们按 contest_id 的降序排序加入结果表中。
Alice 和 Alex 注册了 215 赛事，注册率为 ((2/3) * 100) = 66.67%
Bob 注册了 207 赛事，注册率为 ((1/3) * 100) = 33.33%</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：分组统计 + 子查询

我们可以将 `Register` 表按照 `contest_id` 分组，统计每个赛事的注册人数，每个赛事的注册人数除以总注册人数即为该赛事的注册率。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT
    contest_id,
    ROUND(COUNT(1) * 100 / (SELECT COUNT(1) FROM Users), 2) AS percentage
FROM Register
GROUP BY 1
ORDER BY 2 DESC, 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1634. 求两个多项式链表的和 🔒](https://leetcode.cn/problems/add-two-polynomials-represented-as-linked-lists){#1634}

{{< tabs "1634" >}}

{{% tab "python" %}}
```python
# Definition for polynomial singly-linked list.
# class PolyNode:
#     def __init__(self, x=0, y=0, next=None):
#         self.coefficient = x
#         self.power = y
#         self.next = next


class Solution:
    def addPoly(self, poly1: "PolyNode", poly2: "PolyNode") -> "PolyNode":
        dummy = curr = PolyNode()
        while poly1 and poly2:
            if poly1.power > poly2.power:
                curr.next = poly1
                poly1 = poly1.next
                curr = curr.next
            elif poly1.power < poly2.power:
                curr.next = poly2
                poly2 = poly2.next
                curr = curr.next
            else:
                if c := poly1.coefficient + poly2.coefficient:
                    curr.next = PolyNode(c, poly1.power)
                    curr = curr.next
                poly1 = poly1.next
                poly2 = poly2.next
        curr.next = poly1 or poly2
        return dummy.next
```
{{% /tab %}}
{{% tab "java" %}}
```java
/**
 * Definition for polynomial singly-linked list.
 * class PolyNode {
 *     int coefficient, power;
 *     PolyNode next = null;

 *     PolyNode() {}
 *     PolyNode(int x, int y) { this.coefficient = x; this.power = y; }
 *     PolyNode(int x, int y, PolyNode next) { this.coefficient = x; this.power = y; this.next =
 next; }
 * }
 */

class Solution {
    public PolyNode addPoly(PolyNode poly1, PolyNode poly2) {
        PolyNode dummy = new PolyNode();
        PolyNode curr = dummy;
        while (poly1 != null && poly2 != null) {
            if (poly1.power > poly2.power) {
                curr.next = poly1;
                poly1 = poly1.next;
                curr = curr.next;
            } else if (poly1.power < poly2.power) {
                curr.next = poly2;
                poly2 = poly2.next;
                curr = curr.next;
            } else {
                int c = poly1.coefficient + poly2.coefficient;
                if (c != 0) {
                    curr.next = new PolyNode(c, poly1.power);
                    curr = curr.next;
                }
                poly1 = poly1.next;
                poly2 = poly2.next;
            }
        }
        if (poly1 == null) {
            curr.next = poly2;
        }
        if (poly2 == null) {
            curr.next = poly1;
        }
        return dummy.next;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
/**
 * Definition for polynomial singly-linked list->
 * struct PolyNode {
 *     int coefficient, power;
 *     PolyNode *next;
 *     PolyNode(): coefficient(0), power(0), next(nullptr) {};
 *     PolyNode(int x, int y): coefficient(x), power(y), next(nullptr) {};
 *     PolyNode(int x, int y, PolyNode* next): coefficient(x), power(y), next(next) {};
 * };
 */

class Solution {
public:
    PolyNode* addPoly(PolyNode* poly1, PolyNode* poly2) {
        PolyNode* dummy = new PolyNode();
        PolyNode* curr = dummy;
        while (poly1 && poly2) {
            if (poly1->power > poly2->power) {
                curr->next = poly1;
                poly1 = poly1->next;
                curr = curr->next;
            } else if (poly1->power < poly2->power) {
                curr->next = poly2;
                poly2 = poly2->next;
                curr = curr->next;
            } else {
                int c = poly1->coefficient + poly2->coefficient;
                if (c != 0) {
                    curr->next = new PolyNode(c, poly1->power);
                    curr = curr->next;
                }
                poly1 = poly1->next;
                poly2 = poly2->next;
            }
        }
        if (!poly1) {
            curr->next = poly2;
        }
        if (!poly2) {
            curr->next = poly1;
        }
        return dummy->next;
    }
};
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * Definition for polynomial singly-linked list.
 * function PolyNode(x=0, y=0, next=null) {
 *     this.coefficient = x;
 *     this.power = y;
 *     this.next = next;
 * }
 */

/**
 * @param {PolyNode} poly1
 * @param {PolyNode} poly2
 * @return {PolyNode}
 */
var addPoly = function (poly1, poly2) {
    const dummy = new PolyNode();
    let curr = dummy;
    while (poly1 && poly2) {
        if (poly1.power > poly2.power) {
            curr.next = poly1;
            poly1 = poly1.next;
            curr = curr.next;
        } else if (poly1.power < poly2.power) {
            curr.next = poly2;
            poly2 = poly2.next;
            curr = curr.next;
        } else {
            const c = poly1.coefficient + poly2.coefficient;
            if (c != 0) {
                curr.next = new PolyNode(c, poly1.power);
                curr = curr.next;
            }
            poly1 = poly1.next;
            poly2 = poly2.next;
        }
    }
    curr.next = poly1 || poly2;
    return dummy.next;
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
/**
 * Definition for polynomial singly-linked list.
 * public class PolyNode {
 *     public int coefficient, power;
 *     public PolyNode next;
 *
 *     public PolyNode(int x=0, int y=0, PolyNode next=null) {
 *         this.coefficient = x;
 *         this.power = y;
 *         this.next = next;
 *     }
 * }
 */

public class Solution {
    public PolyNode AddPoly(PolyNode poly1, PolyNode poly2) {
        PolyNode dummy = new PolyNode();
        PolyNode curr = dummy;
        while (poly1 != null && poly2 != null) {
            if (poly1.power > poly2.power) {
                curr.next = poly1;
                poly1 = poly1.next;
                curr = curr.next;
            } else if (poly1.power < poly2.power) {
                curr.next = poly2;
                poly2 = poly2.next;
                curr = curr.next;
            } else {
                int c = poly1.coefficient + poly2.coefficient;
                if (c != 0) {
                    curr.next = new PolyNode(c, poly1.power);
                    curr = curr.next;
                }
                poly1 = poly1.next;
                poly2 = poly2.next;
            }
        }
        if (poly1 == null) {
            curr.next = poly2;
        }
        if (poly2 == null) {
            curr.next = poly1;
        }
        return dummy.next;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>多项式链表是一种特殊形式的链表，每个节点表示多项式的一项。</p>

<p>每个节点有三个属性：</p>

<ul>
	<li><code>coefficient</code>：该项的系数。项 <code><strong>9</strong>x<sup>4</sup></code> 的系数是 <code>9</code> 。</li>
	<li><code>power</code>：该项的指数。项 <code>9x<strong><sup>4</sup></strong></code> 的指数是 <code>4</code> 。</li>
	<li><code>next</code>：指向下一个节点的指针（引用），如果当前节点为链表的最后一个节点则为 <code>null</code> 。</li>
</ul>

<p>例如，多项式 <code>5x<sup>3</sup> + 4x - 7</code> 可以表示成如下图所示的多项式链表：</p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1600-1699/1634.Add%20Two%20Polynomials%20Represented%20as%20Linked%20Lists/images/polynomial2.png" style="width: 500px; height: 91px;" /></p>

<p>多项式链表必须是标准形式的，即多项式必须<strong> 严格 </strong>按指数 <code>power</code> 的递减顺序排列（即降幂排列）。另外，系数 <code>coefficient</code> 为 <code>0</code> 的项需要省略。</p>

<p>给定两个多项式链表的头节点 <code>poly1</code> 和 <code>poly2</code>，返回它们的和的头节点。</p>

<p><strong><code>PolyNode</code> 格式：</strong></p>

<p>输入/输出格式表示为 <code>n</code> 个节点的列表，其中每个节点表示为 <code>[coefficient, power]</code> 。例如，多项式 <code>5x<sup>3</sup> + 4x - 7</code> 表示为： <code>[[5,3],[4,1],[-7,0]]</code> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1600-1699/1634.Add%20Two%20Polynomials%20Represented%20as%20Linked%20Lists/images/ex1.png" style="width: 600px; height: 322px;" /></p>

<pre>
<strong>输入：</strong>poly1 = [[1,1]], poly2 = [[1,0]]
<strong>输出：</strong>[[1,1],[1,0]]
<strong>解释：</strong>poly1 = x. poly2 = 1. 和为 x + 1.
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>poly1 = [[2,2],[4,1],[3,0]], poly2 = [[3,2],[-4,1],[-1,0]]
<strong>输出：</strong>[[5,2],[2,0]]
<strong>解释：</strong>poly1 = 2x<sup>2</sup> + 4x + 3. poly2 = 3x<sup>2</sup> - 4x - 1. 和为 5x<sup>2</sup> + 2. 注意，我们省略 "0x" 项。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>poly1 = [[1,2]], poly2 = [[-1,2]]
<strong>输出：</strong>[]
<strong>解释：</strong>和为 0。我们返回空链表。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 <= n <= 10<sup>4</sup></code></li>
	<li><code>-10<sup>9</sup> <= PolyNode.coefficient <= 10<sup>9</sup></code></li>
	<li><code>PolyNode.coefficient != 0</code></li>
	<li><code>0 <= PolyNode.power <= 10<sup>9</sup></code></li>
	<li><code>PolyNode.power > PolyNode.next.power</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：遍历链表

我们可以同时遍历两个链表，根据指数大小关系，将节点添加到结果链表中。

最后，如果链表 $1$ 或链表 $2$ 还有剩余节点，将其添加到结果链表中。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为两个链表中节点数的较大值。

<!-- tabs:start -->

#### Python3

```python
# Definition for polynomial singly-linked list.
# class PolyNode:
#     def __init__(self, x=0, y=0, next=None):
#         self.coefficient = x
#         self.power = y
#         self.next = next


class Solution:
    def addPoly(self, poly1: "PolyNode", poly2: "PolyNode") -> "PolyNode":
        dummy = curr = PolyNode()
        while poly1 and poly2:
            if poly1.power > poly2.power:
                curr.next = poly1
                poly1 = poly1.next
                curr = curr.next
            elif poly1.power < poly2.power:
                curr.next = poly2
                poly2 = poly2.next
                curr = curr.next
            else:
                if c := poly1.coefficient + poly2.coefficient:
                    curr.next = PolyNode(c, poly1.power)
                    curr = curr.next
                poly1 = poly1.next
                poly2 = poly2.next
        curr.next = poly1 or poly2
        return dummy.next
```

#### Java

```java
/**
 * Definition for polynomial singly-linked list.
 * class PolyNode {
 *     int coefficient, power;
 *     PolyNode next = null;

 *     PolyNode() {}
 *     PolyNode(int x, int y) { this.coefficient = x; this.power = y; }
 *     PolyNode(int x, int y, PolyNode next) { this.coefficient = x; this.power = y; this.next =
 next; }
 * }
 */

class Solution {
    public PolyNode addPoly(PolyNode poly1, PolyNode poly2) {
        PolyNode dummy = new PolyNode();
        PolyNode curr = dummy;
        while (poly1 != null && poly2 != null) {
            if (poly1.power > poly2.power) {
                curr.next = poly1;
                poly1 = poly1.next;
                curr = curr.next;
            } else if (poly1.power < poly2.power) {
                curr.next = poly2;
                poly2 = poly2.next;
                curr = curr.next;
            } else {
                int c = poly1.coefficient + poly2.coefficient;
                if (c != 0) {
                    curr.next = new PolyNode(c, poly1.power);
                    curr = curr.next;
                }
                poly1 = poly1.next;
                poly2 = poly2.next;
            }
        }
        if (poly1 == null) {
            curr.next = poly2;
        }
        if (poly2 == null) {
            curr.next = poly1;
        }
        return dummy.next;
    }
}
```

#### C++

```cpp
/**
 * Definition for polynomial singly-linked list->
 * struct PolyNode {
 *     int coefficient, power;
 *     PolyNode *next;
 *     PolyNode(): coefficient(0), power(0), next(nullptr) {};
 *     PolyNode(int x, int y): coefficient(x), power(y), next(nullptr) {};
 *     PolyNode(int x, int y, PolyNode* next): coefficient(x), power(y), next(next) {};
 * };
 */

class Solution {
public:
    PolyNode* addPoly(PolyNode* poly1, PolyNode* poly2) {
        PolyNode* dummy = new PolyNode();
        PolyNode* curr = dummy;
        while (poly1 && poly2) {
            if (poly1->power > poly2->power) {
                curr->next = poly1;
                poly1 = poly1->next;
                curr = curr->next;
            } else if (poly1->power < poly2->power) {
                curr->next = poly2;
                poly2 = poly2->next;
                curr = curr->next;
            } else {
                int c = poly1->coefficient + poly2->coefficient;
                if (c != 0) {
                    curr->next = new PolyNode(c, poly1->power);
                    curr = curr->next;
                }
                poly1 = poly1->next;
                poly2 = poly2->next;
            }
        }
        if (!poly1) {
            curr->next = poly2;
        }
        if (!poly2) {
            curr->next = poly1;
        }
        return dummy->next;
    }
};
```

#### JavaScript

```js
/**
 * Definition for polynomial singly-linked list.
 * function PolyNode(x=0, y=0, next=null) {
 *     this.coefficient = x;
 *     this.power = y;
 *     this.next = next;
 * }
 */

/**
 * @param {PolyNode} poly1
 * @param {PolyNode} poly2
 * @return {PolyNode}
 */
var addPoly = function (poly1, poly2) {
    const dummy = new PolyNode();
    let curr = dummy;
    while (poly1 && poly2) {
        if (poly1.power > poly2.power) {
            curr.next = poly1;
            poly1 = poly1.next;
            curr = curr.next;
        } else if (poly1.power < poly2.power) {
            curr.next = poly2;
            poly2 = poly2.next;
            curr = curr.next;
        } else {
            const c = poly1.coefficient + poly2.coefficient;
            if (c != 0) {
                curr.next = new PolyNode(c, poly1.power);
                curr = curr.next;
            }
            poly1 = poly1.next;
            poly2 = poly2.next;
        }
    }
    curr.next = poly1 || poly2;
    return dummy.next;
};
```

#### C#

```cs
/**
 * Definition for polynomial singly-linked list.
 * public class PolyNode {
 *     public int coefficient, power;
 *     public PolyNode next;
 *
 *     public PolyNode(int x=0, int y=0, PolyNode next=null) {
 *         this.coefficient = x;
 *         this.power = y;
 *         this.next = next;
 *     }
 * }
 */

public class Solution {
    public PolyNode AddPoly(PolyNode poly1, PolyNode poly2) {
        PolyNode dummy = new PolyNode();
        PolyNode curr = dummy;
        while (poly1 != null && poly2 != null) {
            if (poly1.power > poly2.power) {
                curr.next = poly1;
                poly1 = poly1.next;
                curr = curr.next;
            } else if (poly1.power < poly2.power) {
                curr.next = poly2;
                poly2 = poly2.next;
                curr = curr.next;
            } else {
                int c = poly1.coefficient + poly2.coefficient;
                if (c != 0) {
                    curr.next = new PolyNode(c, poly1.power);
                    curr = curr.next;
                }
                poly1 = poly1.next;
                poly2 = poly2.next;
            }
        }
        if (poly1 == null) {
            curr.next = poly2;
        }
        if (poly2 == null) {
            curr.next = poly1;
        }
        return dummy.next;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1635. Hopper 公司查询 I 🔒](https://leetcode.cn/problems/hopper-company-queries-i){#1635}

{{< tabs "1635" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    recursive Months AS (
        SELECT
            1 AS month
        UNION ALL
        SELECT
            month + 1
        FROM Months
        WHERE month < 12
    ),
    Ride AS (
        SELECT MONTH(requested_at) AS month, COUNT(1) AS cnt
        FROM
            Rides AS r
            JOIN AcceptedRides AS a
                ON r.ride_id = a.ride_id AND YEAR(requested_at) = 2020
        GROUP BY month
    )
SELECT
    m.month,
    COUNT(driver_id) AS active_drivers,
    IFNULL(r.cnt, 0) AS accepted_rides
FROM
    Months AS m
    LEFT JOIN Drivers AS d
        ON (m.month >= MONTH(d.join_date) AND YEAR(d.join_date) = 2020)
        OR YEAR(d.join_date) < 2020
    LEFT JOIN Ride AS r ON m.month = r.month
GROUP BY month;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表: <code>Drivers</code></p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| driver_id   | int     |
| join_date   | date    |
+-------------+---------+
driver_id 是该表的主键(具有唯一值的列)。
该表的每一行均包含驾驶员的ID以及他们加入Hopper公司的日期。
</pre>

<p>&nbsp;</p>

<p>表: <code>Rides</code></p>

<pre>
+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| ride_id      | int     |
| user_id      | int     |
| requested_at | date    |
+--------------+---------+
ride_id 是该表的主键(具有唯一值的列)。
该表的每一行均包含行程ID(ride_id)，用户ID(user_id)以及该行程的日期(requested_at)。
该表中可能有一些不被接受的乘车请求。
</pre>

<p>&nbsp;</p>

<p>表: <code>AcceptedRides</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| ride_id       | int     |
| driver_id     | int     |
| ride_distance | int     |
| ride_duration | int     |
+---------------+---------+
ride_id 是该表的主键(具有唯一值的列)。
该表的每一行都包含已接受的行程信息。
表中的行程信息都在“<code>Rides</code>”表中存在。
</pre>

<p>&nbsp;</p>

<p>编写解决方案以报告 <strong>2020</strong> 年每个月的以下统计信息：</p>

<ul>
	<li>截至某月底，当前在Hopper公司工作的驾驶员数量（<code>active_drivers</code>）。</li>
	<li>该月接受的乘车次数（<code>accepted_rides</code>）。</li>
</ul>

<p>返回按<code>month</code> 升序排列的结果表，其中<code>month</code> 是月份的数字（一月是<code>1</code>，二月是<code>2</code>，依此类推）。</p>

<p>返回结果格式如下例所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
表 Drivers:
+-----------+------------+
| driver_id | join_date  |
+-----------+------------+
| 10        | 2019-12-10 |
| 8         | 2020-1-13  |
| 5         | 2020-2-16  |
| 7         | 2020-3-8   |
| 4         | 2020-5-17  |
| 1         | 2020-10-24 |
| 6         | 2021-1-5   |
+-----------+------------+
表 Rides:
+---------+---------+--------------+
| ride_id | user_id | requested_at |
+---------+---------+--------------+
| 6       | 75      | 2019-12-9    |
| 1       | 54      | 2020-2-9     |
| 10      | 63      | 2020-3-4     |
| 19      | 39      | 2020-4-6     |
| 3       | 41      | 2020-6-3     |
| 13      | 52      | 2020-6-22    |
| 7       | 69      | 2020-7-16    |
| 17      | 70      | 2020-8-25    |
| 20      | 81      | 2020-11-2    |
| 5       | 57      | 2020-11-9    |
| 2       | 42      | 2020-12-9    |
| 11      | 68      | 2021-1-11    |
| 15      | 32      | 2021-1-17    |
| 12      | 11      | 2021-1-19    |
| 14      | 18      | 2021-1-27    |
+---------+---------+--------------+
表 AcceptedRides:
+---------+-----------+---------------+---------------+
| ride_id | driver_id | ride_distance | ride_duration |
+---------+-----------+---------------+---------------+
| 10      | 10        | 63            | 38            |
| 13      | 10        | 73            | 96            |
| 7       | 8         | 100           | 28            |
| 17      | 7         | 119           | 68            |
| 20      | 1         | 121           | 92            |
| 5       | 7         | 42            | 101           |
| 2       | 4         | 6             | 38            |
| 11      | 8         | 37            | 43            |
| 15      | 8         | 108           | 82            |
| 12      | 8         | 38            | 34            |
| 14      | 1         | 90            | 74            |
+---------+-----------+---------------+---------------+
<strong>输出：</strong>
+-------+----------------+----------------+
| month | active_drivers | accepted_rides |
+-------+----------------+----------------+
| 1     | 2              | 0              |
| 2     | 3              | 0              |
| 3     | 4              | 1              |
| 4     | 4              | 0              |
| 5     | 5              | 0              |
| 6     | 5              | 1              |
| 7     | 5              | 1              |
| 8     | 5              | 1              |
| 9     | 5              | 0              |
| 10    | 6              | 0              |
| 11    | 6              | 2              |
| 12    | 6              | 1              |
+-------+----------------+----------------+
<strong>解释：</strong>
截至1月底-&gt;两个活跃的驾驶员（10,8），没有被接受的行程。
截至2月底-&gt;三个活跃的驾驶员（10,8,5），没有被接受的行程。
截至3月底-&gt;四个活跃的驾驶员（10,8,5,7），一个被接受的行程（10）。
截至4月底-&gt;四个活跃的驾驶员（10,8,5,7），没有被接受的行程。
截至5月底-&gt;五个活跃的驾驶员（10,8,5,7,4），没有被接受的行程。
截至6月底-&gt;五个活跃的驾驶员（10,8,5,7,4），一个被接受的行程（13）。
截至7月底-&gt;五个活跃的驾驶员（10,8,5,7,4），一个被接受的行程（7）。
截至8月底-&gt;五个活跃的驾驶员（10,8,5,7,4），一位接受的行程（17）。
截至9月底-&gt;五个活跃的驾驶员（10,8,5,7,4），没有被接受的行程。
截至10月底-&gt;六个活跃的驾驶员（10,8,5,7,4,1），没有被接受的行程。
截至11月底-&gt;六个活跃的驾驶员（10,8,5,7,4,1），两个被接受的行程（20,5）。
截至12月底-&gt;六个活跃的驾驶员（10,8,5,7,4,1），一个被接受的行程（2）。</pre>

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
    recursive Months AS (
        SELECT
            1 AS month
        UNION ALL
        SELECT
            month + 1
        FROM Months
        WHERE month < 12
    ),
    Ride AS (
        SELECT MONTH(requested_at) AS month, COUNT(1) AS cnt
        FROM
            Rides AS r
            JOIN AcceptedRides AS a
                ON r.ride_id = a.ride_id AND YEAR(requested_at) = 2020
        GROUP BY month
    )
SELECT
    m.month,
    COUNT(driver_id) AS active_drivers,
    IFNULL(r.cnt, 0) AS accepted_rides
FROM
    Months AS m
    LEFT JOIN Drivers AS d
        ON (m.month >= MONTH(d.join_date) AND YEAR(d.join_date) = 2020)
        OR YEAR(d.join_date) < 2020
    LEFT JOIN Ride AS r ON m.month = r.month
GROUP BY month;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1636. 按照频率将数组升序排序](https://leetcode.cn/problems/sort-array-by-increasing-frequency){#1636}

{{< tabs "1636" >}}

{{% tab "python" %}}
```python
class Solution:
    def frequencySort(self, nums: List[int]) -> List[int]:
        cnt = Counter(nums)
        return sorted(nums, key=lambda x: (cnt[x], -x))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] frequencySort(int[] nums) {
        int[] cnt = new int[201];
        List<Integer> t = new ArrayList<>();
        for (int v : nums) {
            v += 100;
            ++cnt[v];
            t.add(v);
        }
        t.sort((a, b) -> cnt[a] == cnt[b] ? b - a : cnt[a] - cnt[b]);
        int[] ans = new int[nums.length];
        int i = 0;
        for (int v : t) {
            ans[i++] = v - 100;
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
    vector<int> frequencySort(vector<int>& nums) {
        vector<int> cnt(201);
        for (int v : nums) {
            ++cnt[v + 100];
        }
        sort(nums.begin(), nums.end(), [&](const int a, const int b) {
            if (cnt[a + 100] == cnt[b + 100]) return a > b;
            return cnt[a + 100] < cnt[b + 100];
        });
        return nums;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func frequencySort(nums []int) []int {
	cnt := make([]int, 201)
	for _, v := range nums {
		cnt[v+100]++
	}
	sort.Slice(nums, func(i, j int) bool {
		a, b := nums[i]+100, nums[j]+100
		return cnt[a] < cnt[b] || cnt[a] == cnt[b] && a > b
	})
	return nums
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function frequencySort(nums: number[]): number[] {
    const map = new Map<number, number>();
    for (const num of nums) {
        map.set(num, (map.get(num) ?? 0) + 1);
    }
    return nums.sort((a, b) => map.get(a) - map.get(b) || b - a);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashMap;
impl Solution {
    pub fn frequency_sort(mut nums: Vec<i32>) -> Vec<i32> {
        let n = nums.len();
        let mut map = HashMap::new();
        for &num in nums.iter() {
            *map.entry(num).or_insert(0) += 1;
        }
        nums.sort_by(|a, b| {
            if map.get(a) == map.get(b) {
                return b.cmp(a);
            }
            map.get(a).cmp(&map.get(b))
        });
        nums
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var frequencySort = function (nums) {
    const m = new Map();
    for (let i = 0; i < nums.length; i++) {
        m.set(nums[i], (m.get(nums[i]) || 0) + 1);
    }
    nums.sort((a, b) => (m.get(a) != m.get(b) ? m.get(a) - m.get(b) : b - a));
    return nums;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>nums</code> ，请你将数组按照每个值的频率 <strong>升序</strong> 排序。如果有多个值的频率相同，请你按照数值本身将它们 <strong>降序</strong> 排序。 </p>

<p>请你返回排序后的数组。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [1,1,2,2,2,3]
<b>输出：</b>[3,1,1,2,2,2]
<b>解释：</b>'3' 频率为 1，'1' 频率为 2，'2' 频率为 3 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [2,3,1,3,2]
<b>输出：</b>[1,3,3,2,2]
<b>解释：</b>'2' 和 '3' 频率都为 2 ，所以它们之间按照数值本身降序排序。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>nums = [-1,1,-6,4,5,-6,1,4,1]
<b>输出：</b>[5,-1,4,4,-6,-6,1,1,1]</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>-100 &lt;= nums[i] &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数组或哈希表计数

用数组或者哈希表统计 `nums` 中每个数字出现的次数，由于题目中数字的范围是 $[-100, 100]$，我们可以直接创建一个大小为 $201$ 的数组来统计。

然后对 `nums` 按照数字出现次数升序排序，如果出现次数相同，则按照数字降序排序。

时间复杂度为 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 `nums` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def frequencySort(self, nums: List[int]) -> List[int]:
        cnt = Counter(nums)
        return sorted(nums, key=lambda x: (cnt[x], -x))
```

#### Java

```java
class Solution {
    public int[] frequencySort(int[] nums) {
        int[] cnt = new int[201];
        List<Integer> t = new ArrayList<>();
        for (int v : nums) {
            v += 100;
            ++cnt[v];
            t.add(v);
        }
        t.sort((a, b) -> cnt[a] == cnt[b] ? b - a : cnt[a] - cnt[b]);
        int[] ans = new int[nums.length];
        int i = 0;
        for (int v : t) {
            ans[i++] = v - 100;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<int> cnt(201);
        for (int v : nums) {
            ++cnt[v + 100];
        }
        sort(nums.begin(), nums.end(), [&](const int a, const int b) {
            if (cnt[a + 100] == cnt[b + 100]) return a > b;
            return cnt[a + 100] < cnt[b + 100];
        });
        return nums;
    }
};
```

#### Go

```go
func frequencySort(nums []int) []int {
	cnt := make([]int, 201)
	for _, v := range nums {
		cnt[v+100]++
	}
	sort.Slice(nums, func(i, j int) bool {
		a, b := nums[i]+100, nums[j]+100
		return cnt[a] < cnt[b] || cnt[a] == cnt[b] && a > b
	})
	return nums
}
```

#### TypeScript

```ts
function frequencySort(nums: number[]): number[] {
    const map = new Map<number, number>();
    for (const num of nums) {
        map.set(num, (map.get(num) ?? 0) + 1);
    }
    return nums.sort((a, b) => map.get(a) - map.get(b) || b - a);
}
```

#### Rust

```rust
use std::collections::HashMap;
impl Solution {
    pub fn frequency_sort(mut nums: Vec<i32>) -> Vec<i32> {
        let n = nums.len();
        let mut map = HashMap::new();
        for &num in nums.iter() {
            *map.entry(num).or_insert(0) += 1;
        }
        nums.sort_by(|a, b| {
            if map.get(a) == map.get(b) {
                return b.cmp(a);
            }
            map.get(a).cmp(&map.get(b))
        });
        nums
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var frequencySort = function (nums) {
    const m = new Map();
    for (let i = 0; i < nums.length; i++) {
        m.set(nums[i], (m.get(nums[i]) || 0) + 1);
    }
    nums.sort((a, b) => (m.get(a) != m.get(b) ? m.get(a) - m.get(b) : b - a));
    return nums;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1637. 两点之间不包含任何点的最宽垂直区域](https://leetcode.cn/problems/widest-vertical-area-between-two-points-containing-no-points){#1637}

{{< tabs "1637" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxWidthOfVerticalArea(self, points: List[List[int]]) -> int:
        nums = [x for x, _ in points]
        n = len(nums)
        mi, mx = min(nums), max(nums)
        bucket_size = max(1, (mx - mi) // (n - 1))
        bucket_count = (mx - mi) // bucket_size + 1
        buckets = [[inf, -inf] for _ in range(bucket_count)]
        for x in nums:
            i = (x - mi) // bucket_size
            buckets[i][0] = min(buckets[i][0], x)
            buckets[i][1] = max(buckets[i][1], x)
        ans = 0
        prev = inf
        for curmin, curmax in buckets:
            if curmin > curmax:
                continue
            ans = max(ans, curmin - prev)
            prev = curmax
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxWidthOfVerticalArea(int[][] points) {
        int n = points.length;
        int[] nums = new int[n];
        for (int i = 0; i < n; ++i) {
            nums[i] = points[i][0];
        }
        final int inf = 1 << 30;
        int mi = inf, mx = -inf;
        for (int v : nums) {
            mi = Math.min(mi, v);
            mx = Math.max(mx, v);
        }
        int bucketSize = Math.max(1, (mx - mi) / (n - 1));
        int bucketCount = (mx - mi) / bucketSize + 1;
        int[][] buckets = new int[bucketCount][2];
        for (var bucket : buckets) {
            bucket[0] = inf;
            bucket[1] = -inf;
        }
        for (int v : nums) {
            int i = (v - mi) / bucketSize;
            buckets[i][0] = Math.min(buckets[i][0], v);
            buckets[i][1] = Math.max(buckets[i][1], v);
        }
        int prev = inf;
        int ans = 0;
        for (var bucket : buckets) {
            if (bucket[0] > bucket[1]) {
                continue;
            }
            ans = Math.max(ans, bucket[0] - prev);
            prev = bucket[1];
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
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> nums;
        for (auto& p : points) {
            nums.push_back(p[0]);
        }
        const int inf = 1 << 30;
        int mi = inf, mx = -inf;
        for (int v : nums) {
            mi = min(mi, v);
            mx = max(mx, v);
        }
        int bucketSize = max(1, (mx - mi) / (n - 1));
        int bucketCount = (mx - mi) / bucketSize + 1;
        vector<pair<int, int>> buckets(bucketCount, {inf, -inf});
        for (int v : nums) {
            int i = (v - mi) / bucketSize;
            buckets[i].first = min(buckets[i].first, v);
            buckets[i].second = max(buckets[i].second, v);
        }
        int ans = 0;
        int prev = inf;
        for (auto [curmin, curmax] : buckets) {
            if (curmin > curmax) continue;
            ans = max(ans, curmin - prev);
            prev = curmax;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxWidthOfVerticalArea(points [][]int) (ans int) {
	n := len(points)
	nums := make([]int, 0, n)
	for _, p := range points {
		nums = append(nums, p[0])
	}
	const inf = 1 << 30
	mi, mx := inf, -inf
	for _, v := range nums {
		mi = min(mi, v)
		mx = max(mx, v)
	}
	bucketSize := max(1, (mx-mi)/(n-1))
	bucketCount := (mx-mi)/bucketSize + 1
	buckets := make([][]int, bucketCount)
	for i := range buckets {
		buckets[i] = []int{inf, -inf}
	}
	for _, v := range nums {
		i := (v - mi) / bucketSize
		buckets[i][0] = min(buckets[i][0], v)
		buckets[i][1] = max(buckets[i][1], v)
	}
	prev := inf
	for _, bucket := range buckets {
		if bucket[0] > bucket[1] {
			continue
		}
		ans = max(ans, bucket[0]-prev)
		prev = bucket[1]
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxWidthOfVerticalArea(points: number[][]): number {
    const nums: number[] = points.map(point => point[0]);
    const inf = 1 << 30;
    const n = nums.length;
    let mi = inf;
    let mx = -inf;
    for (const x of nums) {
        mi = Math.min(mi, x);
        mx = Math.max(mx, x);
    }
    const bucketSize = Math.max(1, Math.floor((mx - mi) / (n - 1)));
    const bucketCount = Math.floor((mx - mi) / bucketSize) + 1;
    const buckets = new Array(bucketCount).fill(0).map(() => [inf, -inf]);
    for (const x of nums) {
        const i = Math.floor((x - mi) / bucketSize);
        buckets[i][0] = Math.min(buckets[i][0], x);
        buckets[i][1] = Math.max(buckets[i][1], x);
    }
    let prev = inf;
    let ans = 0;
    for (const [left, right] of buckets) {
        if (left > right) {
            continue;
        }
        ans = Math.max(ans, left - prev);
        prev = right;
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[][]} points
 * @return {number}
 */
var maxWidthOfVerticalArea = function (points) {
    const nums = points.map(point => point[0]);
    const inf = 1 << 30;
    const n = nums.length;
    let mi = inf;
    let mx = -inf;
    for (const x of nums) {
        mi = Math.min(mi, x);
        mx = Math.max(mx, x);
    }
    const bucketSize = Math.max(1, Math.floor((mx - mi) / (n - 1)));
    const bucketCount = Math.floor((mx - mi) / bucketSize) + 1;
    const buckets = new Array(bucketCount).fill(0).map(() => [inf, -inf]);
    for (const x of nums) {
        const i = Math.floor((x - mi) / bucketSize);
        buckets[i][0] = Math.min(buckets[i][0], x);
        buckets[i][1] = Math.max(buckets[i][1], x);
    }
    let prev = inf;
    let ans = 0;
    for (const [left, right] of buckets) {
        if (left > right) {
            continue;
        }
        ans = Math.max(ans, left - prev);
        prev = right;
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

<p>给你&nbsp;<code>n</code>&nbsp;个二维平面上的点 <code>points</code> ，其中&nbsp;<code>points[i] = [x<sub>i</sub>, y<sub>i</sub>]</code>&nbsp;，请你返回两点之间内部不包含任何点的&nbsp;<strong>最宽垂直区域</strong> 的宽度。</p>

<p><strong>垂直区域</strong> 的定义是固定宽度，而 y 轴上无限延伸的一块区域（也就是高度为无穷大）。 <strong>最宽垂直区域</strong> 为宽度最大的一个垂直区域。</p>

<p>请注意，垂直区域&nbsp;<strong>边上</strong>&nbsp;的点&nbsp;<strong>不在</strong>&nbsp;区域内。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1600-1699/1637.Widest%20Vertical%20Area%20Between%20Two%20Points%20Containing%20No%20Points/images/points3.png" style="width: 276px; height: 371px;" />​
<pre>
<b>输入：</b>points = [[8,7],[9,9],[7,4],[9,7]]
<b>输出：</b>1
<b>解释：</b>红色区域和蓝色区域都是最优区域。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>points = [[3,1],[9,0],[1,0],[1,4],[5,3],[8,8]]
<b>输出：</b>3
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == points.length</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>points[i].length == 2</code></li>
	<li><code>0 &lt;= x<sub>i</sub>, y<sub>i</sub>&nbsp;&lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序

我们可以对数组 $points$ 按照 $x$ 升序排列，获取相邻点之间 $x$ 的差值的最大值。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 为数组 $points$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxWidthOfVerticalArea(self, points: List[List[int]]) -> int:
        points.sort()
        return max(b[0] - a[0] for a, b in pairwise(points))
```

#### Java

```java
class Solution {
    public int maxWidthOfVerticalArea(int[][] points) {
        Arrays.sort(points, (a, b) -> a[0] - b[0]);
        int ans = 0;
        for (int i = 0; i < points.length - 1; ++i) {
            ans = Math.max(ans, points[i + 1][0] - points[i][0]);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int ans = 0;
        for (int i = 0; i < points.size() - 1; ++i) {
            ans = max(ans, points[i + 1][0] - points[i][0]);
        }
        return ans;
    }
};
```

#### Go

```go
func maxWidthOfVerticalArea(points [][]int) (ans int) {
	sort.Slice(points, func(i, j int) bool { return points[i][0] < points[j][0] })
	for i, p := range points[1:] {
		ans = max(ans, p[0]-points[i][0])
	}
	return
}
```

#### TypeScript

```ts
function maxWidthOfVerticalArea(points: number[][]): number {
    points.sort((a, b) => a[0] - b[0]);
    let ans = 0;
    for (let i = 1; i < points.length; ++i) {
        ans = Math.max(ans, points[i][0] - points[i - 1][0]);
    }
    return ans;
}
```

#### JavaScript

```js
/**
 * @param {number[][]} points
 * @return {number}
 */
var maxWidthOfVerticalArea = function (points) {
    points.sort((a, b) => a[0] - b[0]);
    let ans = 0;
    let px = points[0][0];
    for (const [x, _] of points) {
        ans = Math.max(ans, x - px);
        px = x;
    }
    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：桶排序

方法一中排序的时间复杂度为 $O(n \times \log n)$，其实我们可以利用桶排序的思想，将时间复杂度降低到 $O(n)$。

我们将数组 $points$ 的横坐标放入数组 $nums$ 中。

假设数组 $nums$ 有 $n$ 个元素，所有元素从小到大依次是 $nums_0$ 到 $nums_{n - 1}$，最大间距是 $maxGap$。考虑数组中的最大元素和最小元素之差：

$$
nums_{n - 1} - nums_0 = \sum_{i = 1}^{n - 1} (nums_i - nums_{i - 1}) \le{maxGap} \times (n - 1)
$$

因此 $maxGap \ge \dfrac{nums_{n - 1} - nums_0}{n - 1}$，即最大间距至少为 $\dfrac{nums_{n - 1} - nums_0}{n - 1}$。

可以利用桶排序的思想，设定桶的大小（即每个桶最多包含的不同元素个数）为 $\dfrac{nums_{n - 1} - nums_0}{n - 1}$，将元素按照元素值均匀分布到各个桶内，则同一个桶内的任意两个元素之差小于 ${maxGap}$，差为 ${maxGap}$ 的两个元素一定在两个不同的桶内。对于每个桶，维护桶内的最小值和最大值，初始时每个桶内的最小值和最大值分别是正无穷和负无穷，表示桶内没有元素。

遍历数组 ${nums}$ 中的所有元素。对于每个元素，根据该元素与最小元素之差以及桶的大小计算该元素应该分到的桶的编号，可以确保编号小的桶内的元素都小于编号大的桶内的元素，使用元素值更新元素所在的桶内的最小值和最大值。

遍历数组结束之后，每个非空的桶内的最小值和最大值都可以确定。按照桶的编号从小到大的顺序依次遍历每个桶，当前的桶的最小值和上一个非空的桶的最大值是排序后的相邻元素，计算两个相邻元素之差，并更新最大间距。遍历桶结束之后即可得到最大间距。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $points$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxWidthOfVerticalArea(self, points: List[List[int]]) -> int:
        nums = [x for x, _ in points]
        n = len(nums)
        mi, mx = min(nums), max(nums)
        bucket_size = max(1, (mx - mi) // (n - 1))
        bucket_count = (mx - mi) // bucket_size + 1
        buckets = [[inf, -inf] for _ in range(bucket_count)]
        for x in nums:
            i = (x - mi) // bucket_size
            buckets[i][0] = min(buckets[i][0], x)
            buckets[i][1] = max(buckets[i][1], x)
        ans = 0
        prev = inf
        for curmin, curmax in buckets:
            if curmin > curmax:
                continue
            ans = max(ans, curmin - prev)
            prev = curmax
        return ans
```

#### Java

```java
class Solution {
    public int maxWidthOfVerticalArea(int[][] points) {
        int n = points.length;
        int[] nums = new int[n];
        for (int i = 0; i < n; ++i) {
            nums[i] = points[i][0];
        }
        final int inf = 1 << 30;
        int mi = inf, mx = -inf;
        for (int v : nums) {
            mi = Math.min(mi, v);
            mx = Math.max(mx, v);
        }
        int bucketSize = Math.max(1, (mx - mi) / (n - 1));
        int bucketCount = (mx - mi) / bucketSize + 1;
        int[][] buckets = new int[bucketCount][2];
        for (var bucket : buckets) {
            bucket[0] = inf;
            bucket[1] = -inf;
        }
        for (int v : nums) {
            int i = (v - mi) / bucketSize;
            buckets[i][0] = Math.min(buckets[i][0], v);
            buckets[i][1] = Math.max(buckets[i][1], v);
        }
        int prev = inf;
        int ans = 0;
        for (var bucket : buckets) {
            if (bucket[0] > bucket[1]) {
                continue;
            }
            ans = Math.max(ans, bucket[0] - prev);
            prev = bucket[1];
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> nums;
        for (auto& p : points) {
            nums.push_back(p[0]);
        }
        const int inf = 1 << 30;
        int mi = inf, mx = -inf;
        for (int v : nums) {
            mi = min(mi, v);
            mx = max(mx, v);
        }
        int bucketSize = max(1, (mx - mi) / (n - 1));
        int bucketCount = (mx - mi) / bucketSize + 1;
        vector<pair<int, int>> buckets(bucketCount, {inf, -inf});
        for (int v : nums) {
            int i = (v - mi) / bucketSize;
            buckets[i].first = min(buckets[i].first, v);
            buckets[i].second = max(buckets[i].second, v);
        }
        int ans = 0;
        int prev = inf;
        for (auto [curmin, curmax] : buckets) {
            if (curmin > curmax) continue;
            ans = max(ans, curmin - prev);
            prev = curmax;
        }
        return ans;
    }
};
```

#### Go

```go
func maxWidthOfVerticalArea(points [][]int) (ans int) {
	n := len(points)
	nums := make([]int, 0, n)
	for _, p := range points {
		nums = append(nums, p[0])
	}
	const inf = 1 << 30
	mi, mx := inf, -inf
	for _, v := range nums {
		mi = min(mi, v)
		mx = max(mx, v)
	}
	bucketSize := max(1, (mx-mi)/(n-1))
	bucketCount := (mx-mi)/bucketSize + 1
	buckets := make([][]int, bucketCount)
	for i := range buckets {
		buckets[i] = []int{inf, -inf}
	}
	for _, v := range nums {
		i := (v - mi) / bucketSize
		buckets[i][0] = min(buckets[i][0], v)
		buckets[i][1] = max(buckets[i][1], v)
	}
	prev := inf
	for _, bucket := range buckets {
		if bucket[0] > bucket[1] {
			continue
		}
		ans = max(ans, bucket[0]-prev)
		prev = bucket[1]
	}
	return ans
}
```

#### TypeScript

```ts
function maxWidthOfVerticalArea(points: number[][]): number {
    const nums: number[] = points.map(point => point[0]);
    const inf = 1 << 30;
    const n = nums.length;
    let mi = inf;
    let mx = -inf;
    for (const x of nums) {
        mi = Math.min(mi, x);
        mx = Math.max(mx, x);
    }
    const bucketSize = Math.max(1, Math.floor((mx - mi) / (n - 1)));
    const bucketCount = Math.floor((mx - mi) / bucketSize) + 1;
    const buckets = new Array(bucketCount).fill(0).map(() => [inf, -inf]);
    for (const x of nums) {
        const i = Math.floor((x - mi) / bucketSize);
        buckets[i][0] = Math.min(buckets[i][0], x);
        buckets[i][1] = Math.max(buckets[i][1], x);
    }
    let prev = inf;
    let ans = 0;
    for (const [left, right] of buckets) {
        if (left > right) {
            continue;
        }
        ans = Math.max(ans, left - prev);
        prev = right;
    }
    return ans;
}
```

#### JavaScript

```js
/**
 * @param {number[][]} points
 * @return {number}
 */
var maxWidthOfVerticalArea = function (points) {
    const nums = points.map(point => point[0]);
    const inf = 1 << 30;
    const n = nums.length;
    let mi = inf;
    let mx = -inf;
    for (const x of nums) {
        mi = Math.min(mi, x);
        mx = Math.max(mx, x);
    }
    const bucketSize = Math.max(1, Math.floor((mx - mi) / (n - 1)));
    const bucketCount = Math.floor((mx - mi) / bucketSize) + 1;
    const buckets = new Array(bucketCount).fill(0).map(() => [inf, -inf]);
    for (const x of nums) {
        const i = Math.floor((x - mi) / bucketSize);
        buckets[i][0] = Math.min(buckets[i][0], x);
        buckets[i][1] = Math.max(buckets[i][1], x);
    }
    let prev = inf;
    let ans = 0;
    for (const [left, right] of buckets) {
        if (left > right) {
            continue;
        }
        ans = Math.max(ans, left - prev);
        prev = right;
    }
    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1638. 统计只差一个字符的子串数目](https://leetcode.cn/problems/count-substrings-that-differ-by-one-character){#1638}

{{< tabs "1638" >}}

{{% tab "python" %}}
```python
class Solution:
    def countSubstrings(self, s: str, t: str) -> int:
        ans = 0
        m, n = len(s), len(t)
        f = [[0] * (n + 1) for _ in range(m + 1)]
        g = [[0] * (n + 1) for _ in range(m + 1)]
        for i, a in enumerate(s, 1):
            for j, b in enumerate(t, 1):
                if a == b:
                    f[i][j] = f[i - 1][j - 1] + 1
        for i in range(m - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                if s[i] == t[j]:
                    g[i][j] = g[i + 1][j + 1] + 1
                else:
                    ans += (f[i][j] + 1) * (g[i + 1][j + 1] + 1)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countSubstrings(String s, String t) {
        int ans = 0;
        int m = s.length(), n = t.length();
        int[][] f = new int[m + 1][n + 1];
        int[][] g = new int[m + 1][n + 1];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (s.charAt(i) == t.charAt(j)) {
                    f[i + 1][j + 1] = f[i][j] + 1;
                }
            }
        }
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (s.charAt(i) == t.charAt(j)) {
                    g[i][j] = g[i + 1][j + 1] + 1;
                } else {
                    ans += (f[i][j] + 1) * (g[i + 1][j + 1] + 1);
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
    int countSubstrings(string s, string t) {
        int ans = 0;
        int m = s.length(), n = t.length();
        int f[m + 1][n + 1];
        int g[m + 1][n + 1];
        memset(f, 0, sizeof(f));
        memset(g, 0, sizeof(g));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (s[i] == t[j]) {
                    f[i + 1][j + 1] = f[i][j] + 1;
                }
            }
        }
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (s[i] == t[j]) {
                    g[i][j] = g[i + 1][j + 1] + 1;
                } else {
                    ans += (f[i][j] + 1) * (g[i + 1][j + 1] + 1);
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
func countSubstrings(s string, t string) (ans int) {
	m, n := len(s), len(t)
	f := make([][]int, m+1)
	g := make([][]int, m+1)
	for i := range f {
		f[i] = make([]int, n+1)
		g[i] = make([]int, n+1)
	}
	for i, a := range s {
		for j, b := range t {
			if a == b {
				f[i+1][j+1] = f[i][j] + 1
			}
		}
	}
	for i := m - 1; i >= 0; i-- {
		for j := n - 1; j >= 0; j-- {
			if s[i] == t[j] {
				g[i][j] = g[i+1][j+1] + 1
			} else {
				ans += (f[i][j] + 1) * (g[i+1][j+1] + 1)
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

<p>给你两个字符串&nbsp;<code>s</code> 和&nbsp;<code>t</code>&nbsp;，请你找出 <code>s</code>&nbsp;中的非空子串的数目，这些子串满足替换 <strong>一个不同字符</strong>&nbsp;以后，是 <code>t</code>&nbsp;串的子串。换言之，请你找到 <code>s</code>&nbsp;和 <code>t</code>&nbsp;串中 <strong>恰好</strong>&nbsp;只有一个字符不同的子字符串对的数目。</p>

<p>比方说，&nbsp;<code>"<u>compute</u>r"</code>&nbsp;and&nbsp;<code>"<u>computa</u>tion"&nbsp;</code>只有一个字符不同：&nbsp;<code>'e'</code>/<code>'a'</code>&nbsp;，所以这一对子字符串会给答案加 1 。</p>

<p>请你返回满足上述条件的不同子字符串对数目。</p>

<p>一个 <strong>子字符串</strong>&nbsp;是一个字符串中连续的字符。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>s = "aba", t = "baba"
<b>输出：</b>6
<strong>解释：</strong>以下为只相差 1 个字符的 s 和 t 串的子字符串对：
("<strong>a</strong>ba", "<strong>b</strong>aba")
("<strong>a</strong>ba", "ba<strong>b</strong>a")
("ab<strong>a</strong>", "<strong>b</strong>aba")
("ab<strong>a</strong>", "ba<strong>b</strong>a")
("a<strong>b</strong>a", "b<strong>a</strong>ba")
("a<strong>b</strong>a", "bab<strong>a</strong>")
加粗部分分别表示 s 和 t 串选出来的子字符串。
</pre>

<strong>示例 2：</strong>

<pre>
<b>输入：</b>s = "ab", t = "bb"
<b>输出：</b>3
<strong>解释：</strong>以下为只相差 1 个字符的 s 和 t 串的子字符串对：
("<strong>a</strong>b", "<strong>b</strong>b")
("<strong>a</strong>b", "b<strong>b</strong>")
("<strong>ab</strong>", "<strong>bb</strong>")
加粗部分分别表示 s 和 t 串选出来的子字符串。
</pre>

<strong>示例 3：</strong>

<pre>
<b>输入：</b>s = "a", t = "a"
<b>输出：</b>0
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<b>输入：</b>s = "abe", t = "bbc"
<b>输出：</b>10
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length, t.length &lt;= 100</code></li>
	<li><code>s</code> 和&nbsp;<code>t</code>&nbsp;都只包含小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举

我们可以枚举字符串 $s$ 和 $t$ 中不同的那个字符位置，然后分别向两边扩展，直到遇到不同的字符为止，这样就可以得到以该位置为中心的满足条件的子串对数目。我们记左边扩展的相同字符个数为 $l$，右边扩展的相同字符个数为 $r$，那么以该位置为中心的满足条件的子串对数目为 $(l + 1) \times (r + 1)$，累加到答案中即可。

枚举结束后，即可得到答案。

时间复杂度 $O(m \times n \times \min(m, n))$，空间复杂度 $O(1)$。其中 $m$ 和 $n$ 分别为字符串 $s$ 和 $t$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countSubstrings(self, s: str, t: str) -> int:
        ans = 0
        m, n = len(s), len(t)
        for i, a in enumerate(s):
            for j, b in enumerate(t):
                if a != b:
                    l = r = 0
                    while i > l and j > l and s[i - l - 1] == t[j - l - 1]:
                        l += 1
                    while (
                        i + r + 1 < m and j + r + 1 < n and s[i + r + 1] == t[j + r + 1]
                    ):
                        r += 1
                    ans += (l + 1) * (r + 1)
        return ans
```

#### Java

```java
class Solution {
    public int countSubstrings(String s, String t) {
        int ans = 0;
        int m = s.length(), n = t.length();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (s.charAt(i) != t.charAt(j)) {
                    int l = 0, r = 0;
                    while (i - l > 0 && j - l > 0 && s.charAt(i - l - 1) == t.charAt(j - l - 1)) {
                        ++l;
                    }
                    while (i + r + 1 < m && j + r + 1 < n
                        && s.charAt(i + r + 1) == t.charAt(j + r + 1)) {
                        ++r;
                    }
                    ans += (l + 1) * (r + 1);
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
    int countSubstrings(string s, string t) {
        int ans = 0;
        int m = s.size(), n = t.size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (s[i] != t[j]) {
                    int l = 0, r = 0;
                    while (i - l > 0 && j - l > 0 && s[i - l - 1] == t[j - l - 1]) {
                        ++l;
                    }
                    while (i + r + 1 < m && j + r + 1 < n && s[i + r + 1] == t[j + r + 1]) {
                        ++r;
                    }
                    ans += (l + 1) * (r + 1);
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func countSubstrings(s string, t string) (ans int) {
	m, n := len(s), len(t)
	for i, a := range s {
		for j, b := range t {
			if a != b {
				l, r := 0, 0
				for i > l && j > l && s[i-l-1] == t[j-l-1] {
					l++
				}
				for i+r+1 < m && j+r+1 < n && s[i+r+1] == t[j+r+1] {
					r++
				}
				ans += (l + 1) * (r + 1)
			}
		}
	}
	return
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：预处理 + 枚举

方法一中，我们每次需要分别往左右两边扩展，得出 $l$ 和 $r$ 的值。实际上，我们可以预处理出以每个位置 $(i, j)$ 结尾的最长相同后缀的长度，以及以每个位置 $(i, j)$ 开头的最长相同前缀的长度，分别记录在数组 $f$ 和 $g$ 中。

接下来，与方法一类似，我们枚举字符串 $s$ 和 $t$ 中不同的那个字符位置 $(i, j)$，那么以该位置为中心的满足条件的子串对数目为 $(f[i][j] + 1) \times (g[i + 1][j + 1] + 1)$，累加到答案中即可。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别为字符串 $s$ 和 $t$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countSubstrings(self, s: str, t: str) -> int:
        ans = 0
        m, n = len(s), len(t)
        f = [[0] * (n + 1) for _ in range(m + 1)]
        g = [[0] * (n + 1) for _ in range(m + 1)]
        for i, a in enumerate(s, 1):
            for j, b in enumerate(t, 1):
                if a == b:
                    f[i][j] = f[i - 1][j - 1] + 1
        for i in range(m - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                if s[i] == t[j]:
                    g[i][j] = g[i + 1][j + 1] + 1
                else:
                    ans += (f[i][j] + 1) * (g[i + 1][j + 1] + 1)
        return ans
```

#### Java

```java
class Solution {
    public int countSubstrings(String s, String t) {
        int ans = 0;
        int m = s.length(), n = t.length();
        int[][] f = new int[m + 1][n + 1];
        int[][] g = new int[m + 1][n + 1];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (s.charAt(i) == t.charAt(j)) {
                    f[i + 1][j + 1] = f[i][j] + 1;
                }
            }
        }
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (s.charAt(i) == t.charAt(j)) {
                    g[i][j] = g[i + 1][j + 1] + 1;
                } else {
                    ans += (f[i][j] + 1) * (g[i + 1][j + 1] + 1);
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
    int countSubstrings(string s, string t) {
        int ans = 0;
        int m = s.length(), n = t.length();
        int f[m + 1][n + 1];
        int g[m + 1][n + 1];
        memset(f, 0, sizeof(f));
        memset(g, 0, sizeof(g));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (s[i] == t[j]) {
                    f[i + 1][j + 1] = f[i][j] + 1;
                }
            }
        }
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (s[i] == t[j]) {
                    g[i][j] = g[i + 1][j + 1] + 1;
                } else {
                    ans += (f[i][j] + 1) * (g[i + 1][j + 1] + 1);
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func countSubstrings(s string, t string) (ans int) {
	m, n := len(s), len(t)
	f := make([][]int, m+1)
	g := make([][]int, m+1)
	for i := range f {
		f[i] = make([]int, n+1)
		g[i] = make([]int, n+1)
	}
	for i, a := range s {
		for j, b := range t {
			if a == b {
				f[i+1][j+1] = f[i][j] + 1
			}
		}
	}
	for i := m - 1; i >= 0; i-- {
		for j := n - 1; j >= 0; j-- {
			if s[i] == t[j] {
				g[i][j] = g[i+1][j+1] + 1
			} else {
				ans += (f[i][j] + 1) * (g[i+1][j+1] + 1)
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

# [1639. 通过给定词典构造目标字符串的方案数](https://leetcode.cn/problems/number-of-ways-to-form-a-target-string-given-a-dictionary){#1639}

{{< tabs "1639" >}}

{{% tab "python" %}}
```python
class Solution:
    def numWays(self, words: List[str], target: str) -> int:
        m, n = len(target), len(words[0])
        cnt = [[0] * 26 for _ in range(n)]
        for w in words:
            for j, c in enumerate(w):
                cnt[j][ord(c) - ord('a')] += 1
        mod = 10**9 + 7
        f = [[0] * (n + 1) for _ in range(m + 1)]
        f[0] = [1] * (n + 1)
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                f[i][j] = (
                    f[i][j - 1]
                    + f[i - 1][j - 1] * cnt[j - 1][ord(target[i - 1]) - ord('a')]
                )
                f[i][j] %= mod
        return f[m][n]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numWays(String[] words, String target) {
        int m = target.length();
        int n = words[0].length();
        final int mod = (int) 1e9 + 7;
        long[][] f = new long[m + 1][n + 1];
        Arrays.fill(f[0], 1);
        int[][] cnt = new int[n][26];
        for (var w : words) {
            for (int j = 0; j < n; ++j) {
                cnt[j][w.charAt(j) - 'a']++;
            }
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                f[i][j] = f[i][j - 1] + f[i - 1][j - 1] * cnt[j - 1][target.charAt(i - 1) - 'a'];
                f[i][j] %= mod;
            }
        }
        return (int) f[m][n];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int m = target.size(), n = words[0].size();
        const int mod = 1e9 + 7;
        long long f[m + 1][n + 1];
        memset(f, 0, sizeof(f));
        fill(f[0], f[0] + n + 1, 1);
        vector<vector<int>> cnt(n, vector<int>(26));
        for (auto& w : words) {
            for (int j = 0; j < n; ++j) {
                ++cnt[j][w[j] - 'a'];
            }
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                f[i][j] = f[i][j - 1] + f[i - 1][j - 1] * cnt[j - 1][target[i - 1] - 'a'];
                f[i][j] %= mod;
            }
        }
        return f[m][n];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numWays(words []string, target string) int {
	const mod = 1e9 + 7
	m, n := len(target), len(words[0])
	f := make([][]int, m+1)
	for i := range f {
		f[i] = make([]int, n+1)
	}
	for j := range f[0] {
		f[0][j] = 1
	}
	cnt := make([][26]int, n)
	for _, w := range words {
		for j, c := range w {
			cnt[j][c-'a']++
		}
	}
	for i := 1; i <= m; i++ {
		for j := 1; j <= n; j++ {
			f[i][j] = f[i][j-1] + f[i-1][j-1]*cnt[j-1][target[i-1]-'a']
			f[i][j] %= mod
		}
	}
	return f[m][n]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numWays(words: string[], target: string): number {
    const m = target.length;
    const n = words[0].length;
    const f = new Array(m + 1).fill(0).map(() => new Array(n + 1).fill(0));
    const mod = 1e9 + 7;
    for (let j = 0; j <= n; ++j) {
        f[0][j] = 1;
    }
    const cnt = new Array(n).fill(0).map(() => new Array(26).fill(0));
    for (const w of words) {
        for (let j = 0; j < n; ++j) {
            ++cnt[j][w.charCodeAt(j) - 97];
        }
    }
    for (let i = 1; i <= m; ++i) {
        for (let j = 1; j <= n; ++j) {
            f[i][j] = f[i][j - 1] + f[i - 1][j - 1] * cnt[j - 1][target.charCodeAt(i - 1) - 97];
            f[i][j] %= mod;
        }
    }
    return f[m][n];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串列表 <code>words</code> 和一个目标字符串 <code>target</code> 。<code>words</code> 中所有字符串都 <strong>长度相同</strong>  。</p>

<p>你的目标是使用给定的 <code>words</code> 字符串列表按照下述规则构造 <code>target</code> ：</p>

<ul>
	<li>从左到右依次构造 <code>target</code> 的每一个字符。</li>
	<li>为了得到 <code>target</code> 第 <code>i</code> 个字符（下标从 <strong>0</strong> 开始），当 <code>target[i] = words[j][k]</code> 时，你可以使用 <code>words</code> 列表中第 <code>j</code> 个字符串的第 <code>k</code> 个字符。</li>
	<li>一旦你使用了 <code>words</code> 中第 <code>j</code> 个字符串的第 <code>k</code> 个字符，你不能再使用 <code>words</code> 字符串列表中任意单词的第 <code>x</code> 个字符（<code>x <= k</code>）。也就是说，所有单词下标小于等于 <code>k</code> 的字符都不能再被使用。</li>
	<li>请你重复此过程直到得到目标字符串 <code>target</code> 。</li>
</ul>

<p><strong>请注意</strong>， 在构造目标字符串的过程中，你可以按照上述规定使用 <code>words</code> 列表中 <strong>同一个字符串</strong> 的 <strong>多个字符</strong> 。</p>

<p>请你返回使用 <code>words</code> 构造 <code>target</code> 的方案数。由于答案可能会很大，请对 <code>10<sup>9</sup> + 7</code> <strong>取余</strong> 后返回。</p>

<p>（译者注：此题目求的是有多少个不同的 <code>k</code> 序列，详情请见示例。）</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>words = ["acca","bbbb","caca"], target = "aba"
<b>输出：</b>6
<b>解释：</b>总共有 6 种方法构造目标串。
"aba" -> 下标为 0 ("<strong>a</strong>cca")，下标为 1 ("b<strong>b</strong>bb")，下标为 3 ("cac<strong>a</strong>")
"aba" -> 下标为 0 ("<strong>a</strong>cca")，下标为 2 ("bb<strong>b</strong>b")，下标为 3 ("cac<strong>a</strong>")
"aba" -> 下标为 0 ("<strong>a</strong>cca")，下标为 1 ("b<strong>b</strong>bb")，下标为 3 ("acc<strong>a</strong>")
"aba" -> 下标为 0 ("<strong>a</strong>cca")，下标为 2 ("bb<strong>b</strong>b")，下标为 3 ("acc<strong>a</strong>")
"aba" -> 下标为 1 ("c<strong>a</strong>ca")，下标为 2 ("bb<strong>b</strong>b")，下标为 3 ("acc<strong>a</strong>")
"aba" -> 下标为 1 ("c<strong>a</strong>ca")，下标为 2 ("bb<strong>b</strong>b")，下标为 3 ("cac<strong>a</strong>")
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>words = ["abba","baab"], target = "bab"
<b>输出：</b>4
<b>解释：</b>总共有 4 种不同形成 target 的方法。
"bab" -> 下标为 0 ("<strong>b</strong>aab")，下标为 1 ("b<strong>a</strong>ab")，下标为 2 ("ab<strong>b</strong>a")
"bab" -> 下标为 0 ("<strong>b</strong>aab")，下标为 1 ("b<strong>a</strong>ab")，下标为 3 ("baa<strong>b</strong>")
"bab" -> 下标为 0 ("<strong>b</strong>aab")，下标为 2 ("ba<strong>a</strong>b")，下标为 3 ("baa<strong>b</strong>")
"bab" -> 下标为 1 ("a<strong>b</strong>ba")，下标为 2 ("ba<strong>a</strong>b")，下标为 3 ("baa<strong>b</strong>")
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>words = ["abcd"], target = "abcd"
<b>输出：</b>1
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<b>输入：</b>words = ["abab","baba","abba","baab"], target = "abba"
<b>输出：</b>16
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= words.length <= 1000</code></li>
	<li><code>1 <= words[i].length <= 1000</code></li>
	<li><code>words</code> 中所有单词长度相同。</li>
	<li><code>1 <= target.length <= 1000</code></li>
	<li><code>words[i]</code> 和 <code>target</code> 都仅包含小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：预处理 + 记忆化搜索

我们注意到，字符串数组 $words$ 中的每一个字符串长度都相同，不妨记为 $n$，那么我们可以预处理出一个二维数组 $cnt$，其中 $cnt[j][c]$ 表示字符串数组 $words$ 中第 $j$ 个位置的字符 $c$ 的数量。

接下来，我们设计一个函数 $dfs(i, j)$，表示构造 $target[i,..]$ 且当前从 $words$ 中选取的字符位置为 $j$ 的方案数。那么答案就是 $dfs(0, 0)$。

函数 $dfs(i, j)$ 的计算逻辑如下：

-   如果 $i \geq m$，说明 $target$ 中的所有字符都已经被选取，那么方案数为 $1$。
-   如果 $j \geq n$，说明 $words$ 中的所有字符都已经被选取，那么方案数为 $0$。
-   否则，我们可以不选择 $words$ 中的第 $j$ 个位置的字符，那么方案数为 $dfs(i, j + 1)$；或者我们选择 $words$ 中的第 $j$ 个位置的字符，那么方案数为 $dfs(i + 1, j + 1) \times cnt[j][target[i] - 'a']$。

最后，我们返回 $dfs(0, 0)$ 即可。注意答案的取模操作。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m \times n)$。其中 $m$ 为字符串 $target$ 的长度，而 $n$ 为字符串数组 $words$ 中每个字符串的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numWays(self, words: List[str], target: str) -> int:
        @cache
        def dfs(i: int, j: int) -> int:
            if i >= m:
                return 1
            if j >= n:
                return 0
            ans = dfs(i + 1, j + 1) * cnt[j][ord(target[i]) - ord('a')]
            ans = (ans + dfs(i, j + 1)) % mod
            return ans

        m, n = len(target), len(words[0])
        cnt = [[0] * 26 for _ in range(n)]
        for w in words:
            for j, c in enumerate(w):
                cnt[j][ord(c) - ord('a')] += 1
        mod = 10**9 + 7
        return dfs(0, 0)
```

#### Java

```java
class Solution {
    private int m;
    private int n;
    private String target;
    private Integer[][] f;
    private int[][] cnt;
    private final int mod = (int) 1e9 + 7;

    public int numWays(String[] words, String target) {
        m = target.length();
        n = words[0].length();
        f = new Integer[m][n];
        this.target = target;
        cnt = new int[n][26];
        for (var w : words) {
            for (int j = 0; j < n; ++j) {
                cnt[j][w.charAt(j) - 'a']++;
            }
        }
        return dfs(0, 0);
    }

    private int dfs(int i, int j) {
        if (i >= m) {
            return 1;
        }
        if (j >= n) {
            return 0;
        }
        if (f[i][j] != null) {
            return f[i][j];
        }
        long ans = dfs(i, j + 1);
        ans += 1L * dfs(i + 1, j + 1) * cnt[j][target.charAt(i) - 'a'];
        ans %= mod;
        return f[i][j] = (int) ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numWays(vector<string>& words, string target) {
        const int mod = 1e9 + 7;
        int m = target.size(), n = words[0].size();
        vector<vector<int>> cnt(n, vector<int>(26));
        for (auto& w : words) {
            for (int j = 0; j < n; ++j) {
                ++cnt[j][w[j] - 'a'];
            }
        }
        int f[m][n];
        memset(f, -1, sizeof(f));
        function<int(int, int)> dfs = [&](int i, int j) -> int {
            if (i >= m) {
                return 1;
            }
            if (j >= n) {
                return 0;
            }
            if (f[i][j] != -1) {
                return f[i][j];
            }
            int ans = dfs(i, j + 1);
            ans = (ans + 1LL * dfs(i + 1, j + 1) * cnt[j][target[i] - 'a']) % mod;
            return f[i][j] = ans;
        };
        return dfs(0, 0);
    }
};
```

#### Go

```go
func numWays(words []string, target string) int {
	m, n := len(target), len(words[0])
	f := make([][]int, m)
	cnt := make([][26]int, n)
	for _, w := range words {
		for j, c := range w {
			cnt[j][c-'a']++
		}
	}
	for i := range f {
		f[i] = make([]int, n)
		for j := range f[i] {
			f[i][j] = -1
		}
	}
	const mod = 1e9 + 7
	var dfs func(i, j int) int
	dfs = func(i, j int) int {
		if i >= m {
			return 1
		}
		if j >= n {
			return 0
		}
		if f[i][j] != -1 {
			return f[i][j]
		}
		ans := dfs(i, j+1)
		ans = (ans + dfs(i+1, j+1)*cnt[j][target[i]-'a']) % mod
		f[i][j] = ans
		return ans
	}
	return dfs(0, 0)
}
```

#### TypeScript

```ts
function numWays(words: string[], target: string): number {
    const m = target.length;
    const n = words[0].length;
    const f = new Array(m + 1).fill(0).map(() => new Array(n + 1).fill(0));
    const mod = 1e9 + 7;
    for (let j = 0; j <= n; ++j) {
        f[0][j] = 1;
    }
    const cnt = new Array(n).fill(0).map(() => new Array(26).fill(0));
    for (const w of words) {
        for (let j = 0; j < n; ++j) {
            ++cnt[j][w.charCodeAt(j) - 97];
        }
    }
    for (let i = 1; i <= m; ++i) {
        for (let j = 1; j <= n; ++j) {
            f[i][j] = f[i][j - 1] + f[i - 1][j - 1] * cnt[j - 1][target.charCodeAt(i - 1) - 97];
            f[i][j] %= mod;
        }
    }
    return f[m][n];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：预处理 + 动态规划

与方法一类似，我们可以先预处理出一个二维数组 $cnt$，其中 $cnt[j][c]$ 表示字符串数组 $words$ 中第 $j$ 个位置的字符 $c$ 的数量。

接下来，我们定义 $f[i][j]$ 表示构造 $target$ 的前 $i$ 个字符，且当前是从 $words$ 中每个单词的前 $j$ 个字符中选取字符的方案数。那么答案就是 $f[m][n]$。初始时 $f[0][j] = 1$，其中 $0 \leq j \leq n$。

考虑 $f[i][j]$，其中 $i \gt 0$, $j \gt 0$。我们可以不选取 $words$ 中的第 $j$ 个位置的字符，那么方案数为 $f[i][j - 1]$；或者我们选择 $words$ 中的第 $j$ 个位置的字符，那么方案数为 $f[i - 1][j - 1] \times cnt[j - 1][target[i - 1] - 'a']$。最后，我们将这两种情况的方案数相加，即为 $f[i][j]$ 的值。

最后，我们返回 $f[m][n]$ 即可。注意答案的取模操作。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m \times n)$。其中 $m$ 为字符串 $target$ 的长度，而 $n$ 为字符串数组 $words$ 中每个字符串的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numWays(self, words: List[str], target: str) -> int:
        m, n = len(target), len(words[0])
        cnt = [[0] * 26 for _ in range(n)]
        for w in words:
            for j, c in enumerate(w):
                cnt[j][ord(c) - ord('a')] += 1
        mod = 10**9 + 7
        f = [[0] * (n + 1) for _ in range(m + 1)]
        f[0] = [1] * (n + 1)
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                f[i][j] = (
                    f[i][j - 1]
                    + f[i - 1][j - 1] * cnt[j - 1][ord(target[i - 1]) - ord('a')]
                )
                f[i][j] %= mod
        return f[m][n]
```

#### Java

```java
class Solution {
    public int numWays(String[] words, String target) {
        int m = target.length();
        int n = words[0].length();
        final int mod = (int) 1e9 + 7;
        long[][] f = new long[m + 1][n + 1];
        Arrays.fill(f[0], 1);
        int[][] cnt = new int[n][26];
        for (var w : words) {
            for (int j = 0; j < n; ++j) {
                cnt[j][w.charAt(j) - 'a']++;
            }
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                f[i][j] = f[i][j - 1] + f[i - 1][j - 1] * cnt[j - 1][target.charAt(i - 1) - 'a'];
                f[i][j] %= mod;
            }
        }
        return (int) f[m][n];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int m = target.size(), n = words[0].size();
        const int mod = 1e9 + 7;
        long long f[m + 1][n + 1];
        memset(f, 0, sizeof(f));
        fill(f[0], f[0] + n + 1, 1);
        vector<vector<int>> cnt(n, vector<int>(26));
        for (auto& w : words) {
            for (int j = 0; j < n; ++j) {
                ++cnt[j][w[j] - 'a'];
            }
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                f[i][j] = f[i][j - 1] + f[i - 1][j - 1] * cnt[j - 1][target[i - 1] - 'a'];
                f[i][j] %= mod;
            }
        }
        return f[m][n];
    }
};
```

#### Go

```go
func numWays(words []string, target string) int {
	const mod = 1e9 + 7
	m, n := len(target), len(words[0])
	f := make([][]int, m+1)
	for i := range f {
		f[i] = make([]int, n+1)
	}
	for j := range f[0] {
		f[0][j] = 1
	}
	cnt := make([][26]int, n)
	for _, w := range words {
		for j, c := range w {
			cnt[j][c-'a']++
		}
	}
	for i := 1; i <= m; i++ {
		for j := 1; j <= n; j++ {
			f[i][j] = f[i][j-1] + f[i-1][j-1]*cnt[j-1][target[i-1]-'a']
			f[i][j] %= mod
		}
	}
	return f[m][n]
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
