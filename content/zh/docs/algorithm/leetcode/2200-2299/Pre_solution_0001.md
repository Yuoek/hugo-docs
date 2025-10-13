---
title: "2200_找出数组中的所有 K 近邻下标"
date: 2025-10-08T18:39:07+08:00
weight: 1
tags: [位运算, 前缀和, 动态规划, 双指针, 哈希表, 图, 堆（优先队列）, 字符串, 并查集, 广度优先搜索, 数据库, 数组, 最短路, 模拟, 深度优先搜索, 计数, 贪心]
---

{{< markmap >}}
### [2200_找出数组中的所有 K 近邻下标](#2200)
#### [数组](#2200)
#### [双指针](#2200)
### [2201_统计可以提取的工件](#2201)
#### [数组](#2201)
#### [哈希表](#2201)
#### [模拟](#2201)
### [2202_K 次操作后最大化顶端元素](#2202)
#### [贪心](#2202)
#### [数组](#2202)
### [2203_得到要求路径的最小带权子图](#2203)
#### [图](#2203)
#### [最短路](#2203)
### [2204_无向图中到环的距离 🔒](#2204)
#### [深度优先搜索](#2204)
#### [广度优先搜索](#2204)
#### [并查集](#2204)
#### [图](#2204)
### [2205_有资格享受折扣的用户数量 🔒](#2205)
#### [数据库](#2205)
### [2206_将数组划分成相等数对](#2206)
#### [位运算](#2206)
#### [数组](#2206)
#### [哈希表](#2206)
#### [计数](#2206)
### [2207_字符串中最多数目的子序列](#2207)
#### [贪心](#2207)
#### [字符串](#2207)
#### [前缀和](#2207)
### [2208_将数组和减半的最少操作次数](#2208)
#### [贪心](#2208)
#### [数组](#2208)
#### [堆（优先队列）](#2208)
### [2209_用地毯覆盖后的最少白色砖块](#2209)
#### [字符串](#2209)
#### [动态规划](#2209)
#### [前缀和](#2209)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2200_找出数组中的所有 K 近邻下标
___
#### 数组
___
#### 双指针
---
### 2201_统计可以提取的工件
___
#### 数组
___
#### 哈希表
___
#### 模拟
---
### 2202_K 次操作后最大化顶端元素
___
#### 贪心
___
#### 数组
---
### 2203_得到要求路径的最小带权子图
___
#### 图
___
#### 最短路
---
### 2204_无向图中到环的距离 🔒
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 并查集
___
#### 图
---
### 2205_有资格享受折扣的用户数量 🔒
___
#### 数据库
---
### 2206_将数组划分成相等数对
___
#### 位运算
___
#### 数组
___
#### 哈希表
___
#### 计数
---
### 2207_字符串中最多数目的子序列
___
#### 贪心
___
#### 字符串
___
#### 前缀和
---
### 2208_将数组和减半的最少操作次数
___
#### 贪心
___
#### 数组
___
#### 堆（优先队列）
---
### 2209_用地毯覆盖后的最少白色砖块
___
#### 字符串
___
#### 动态规划
___
#### 前缀和
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 位运算 | 前缀和 | 动态规划 |
| 双指针 | 哈希表 | 图 |
| 堆（优先队列） | 字符串 | 并查集 |
| 广度优先搜索 | 数据库 | 数组 |
| 最短路 | 模拟 | 深度优先搜索 |
| 计数 | 贪心 |  |

# [2200. 找出数组中的所有 K 近邻下标](https://leetcode.cn/problems/find-all-k-distant-indices-in-an-array){#2200}

{{< tabs "2200" >}}

{{% tab "python" %}}
```python
class Solution:
    def findKDistantIndices(self, nums: List[int], key: int, k: int) -> List[int]:
        ans = []
        j, n = 0, len(nums)
        for i in range(n):
            while j < i - k or (j < n and nums[j] != key):
                j += 1
            if j < n and j <= (i + k):
                ans.append(i)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<Integer> findKDistantIndices(int[] nums, int key, int k) {
        int n = nums.length;
        List<Integer> ans = new ArrayList<>();
        for (int i = 0, j = 0; i < n; ++i) {
            while (j < i - k || (j < n && nums[j] != key)) {
                ++j;
            }
            if (j < n && j <= i + k) {
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
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0, j = 0; i < n; ++i) {
            while (j < i - k || (j < n && nums[j] != key)) {
                ++j;
            }
            if (j < n && j <= i + k) {
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
func findKDistantIndices(nums []int, key int, k int) (ans []int) {
	n := len(nums)
	for i, j := 0, 0; i < n; i++ {
		for j < i-k || (j < n && nums[j] != key) {
			j++
		}
		if j < n && j <= i+k {
			ans = append(ans, i)
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findKDistantIndices(nums: number[], key: number, k: number): number[] {
    const n = nums.length;
    const ans: number[] = [];
    for (let i = 0, j = 0; i < n; ++i) {
        while (j < i - k || (j < n && nums[j] !== key)) {
            ++j;
        }
        if (j < n && j <= i + k) {
            ans.push(i);
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn find_k_distant_indices(nums: Vec<i32>, key: i32, k: i32) -> Vec<i32> {
        let n = nums.len();
        let mut ans = Vec::new();
        let mut j = 0;
        for i in 0..n {
            while j < i.saturating_sub(k as usize) || (j < n && nums[j] != key) {
                j += 1;
            }
            if j < n && j <= i + k as usize {
                ans.push(i as i32);
            }
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

<p>给你一个下标从 <strong>0</strong> 开始的整数数组 <code>nums</code> 和两个整数 <code>key</code> 和 <code>k</code> 。<strong>K 近邻下标</strong> 是 <code>nums</code> 中的一个下标 <code>i</code> ，并满足至少存在一个下标 <code>j</code> 使得 <code>|i - j| &lt;= k</code> 且 <code>nums[j] == key</code> 。</p>

<p>以列表形式返回按 <strong>递增顺序</strong> 排序的所有 K 近邻下标。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [3,4,9,1,3,9,5], key = 9, k = 1
<strong>输出：</strong>[1,2,3,4,5,6]
<strong>解释：</strong>因此，<code>nums[2] == key</code> 且 <code>nums[5] == key</code>。
- 对下标 0 ，<code>|0 - 2| &gt; k</code> 且 <code>|0 - 5| &gt; k</code>，所以不存在 <code>j</code> 使得 <code>|0 - j| &lt;= k</code> 且 <code>nums[j] == key</code>。所以 0 不是一个 K 近邻下标。
- 对下标 1 ，<code>|1 - 2| &lt;= k</code> 且 <code>nums[2] == key</code>，所以 1 是一个 K 近邻下标。
- 对下标 2 ，<code>|2 - 2| &lt;= k</code> 且 <code>nums[2] == key</code>，所以 2 是一个 K 近邻下标。
- 对下标 3 ，<code>|3 - 2| &lt;= k</code> 且 <code>nums[2] == key</code>，所以 3 是一个 K 近邻下标。
- 对下标 4 ，<code>|4 - 5| &lt;= k</code> 且 <code>nums[5] == key</code>，所以 4 是一个 K 近邻下标。
- 对下标 5 ，<code>|5 - 5| &lt;= k</code> 且 <code>nums[5] == key</code>，所以 5 是一个 K 近邻下标。
- 对下标 6 ，<code>|6 - 5| &lt;= k</code> 且 <code>nums[5] == key</code>，所以 6 是一个 K 近邻下标。
因此，按递增顺序返回 [1,2,3,4,5,6] 。 
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,2,2,2,2], key = 2, k = 2
<strong>输出：</strong>[0,1,2,3,4]
<strong>解释：</strong>对 <code>nums</code> 的所有下标 i ，总存在某个下标 j 使得 <code>|i - j| &lt;= k</code> 且 <code>nums[j] == key</code>，所以每个下标都是一个 K 近邻下标。 
因此，返回 [0,1,2,3,4] 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 1000</code></li>
	<li><code>key</code> 是数组 <code>nums</code> 中的一个整数</li>
	<li><code>1 &lt;= k &lt;= nums.length</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举

我们在 $[0, n)$ 的范围内枚举下标 $i$，对于每个下标 $i$，我们在 $[0, n)$ 的范围内枚举下标 $j$，如果 $|i - j| \leq k$ 且 $nums[j] = key$，那么 $i$ 就是一个 K 近邻下标，我们将 $i$ 加入答案数组中，然后跳出内层循环，枚举下一个下标 $i$。

时间复杂度 $O(n^2)$，其中 $n$ 是数组 $nums$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findKDistantIndices(self, nums: List[int], key: int, k: int) -> List[int]:
        ans = []
        n = len(nums)
        for i in range(n):
            if any(abs(i - j) <= k and nums[j] == key for j in range(n)):
                ans.append(i)
        return ans
```

#### Java

```java
class Solution {
    public List<Integer> findKDistantIndices(int[] nums, int key, int k) {
        int n = nums.length;
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (Math.abs(i - j) <= k && nums[j] == key) {
                    ans.add(i);
                    break;
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
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (abs(i - j) <= k && nums[j] == key) {
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func findKDistantIndices(nums []int, key int, k int) (ans []int) {
	for i := range nums {
		for j, x := range nums {
			if abs(i-j) <= k && x == key {
				ans = append(ans, i)
				break
			}
		}
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
function findKDistantIndices(nums: number[], key: number, k: number): number[] {
    const n = nums.length;
    const ans: number[] = [];
    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < n; ++j) {
            if (Math.abs(i - j) <= k && nums[j] === key) {
                ans.push(i);
                break;
            }
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn find_k_distant_indices(nums: Vec<i32>, key: i32, k: i32) -> Vec<i32> {
        let n = nums.len();
        let mut ans = Vec::new();
        for i in 0..n {
            for j in 0..n {
                if (i as i32 - j as i32).abs() <= k && nums[j] == key {
                    ans.push(i as i32);
                    break;
                }
            }
        }
        ans
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：预处理 + 二分查找

我们可以预处理得到所有等于 $key$ 的元素的下标，记录在数组 $idx$ 中。数组 $idx$ 中的所有下标元素是按照升序排列的，

接下来，我们枚举下标 $i$，对于每个下标 $i$，我们可以使用二分查找的方法在数组 $idx$ 中查找 $[i - k, i + k]$ 范围内的元素，如果存在元素，那么 $i$ 就是一个 K 近邻下标，我们将 $i$ 加入答案数组中。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findKDistantIndices(self, nums: List[int], key: int, k: int) -> List[int]:
        idx = [i for i, x in enumerate(nums) if x == key]
        ans = []
        for i in range(len(nums)):
            l = bisect_left(idx, i - k)
            r = bisect_right(idx, i + k) - 1
            if l <= r:
                ans.append(i)
        return ans
```

#### Java

```java
class Solution {
    public List<Integer> findKDistantIndices(int[] nums, int key, int k) {
        List<Integer> idx = new ArrayList<>();
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == key) {
                idx.add(i);
            }
        }
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < nums.length; ++i) {
            int l = Collections.binarySearch(idx, i - k);
            int r = Collections.binarySearch(idx, i + k + 1);
            l = l < 0 ? -l - 1 : l;
            r = r < 0 ? -r - 2 : r - 1;
            if (l <= r) {
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
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> idx;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] == key) {
                idx.push_back(i);
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            auto it1 = lower_bound(idx.begin(), idx.end(), i - k);
            auto it2 = upper_bound(idx.begin(), idx.end(), i + k) - 1;
            if (it1 <= it2) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func findKDistantIndices(nums []int, key int, k int) (ans []int) {
	idx := []int{}
	for i, x := range nums {
		if x == key {
			idx = append(idx, i)
		}
	}
	for i := range nums {
		l := sort.SearchInts(idx, i-k)
		r := sort.SearchInts(idx, i+k+1) - 1
		if l <= r {
			ans = append(ans, i)
		}
	}
	return
}
```

#### TypeScript

```ts
function findKDistantIndices(nums: number[], key: number, k: number): number[] {
    const n = nums.length;
    const idx: number[] = [];
    for (let i = 0; i < n; i++) {
        if (nums[i] === key) {
            idx.push(i);
        }
    }
    const search = (x: number): number => {
        let [l, r] = [0, idx.length];
        while (l < r) {
            const mid = (l + r) >> 1;
            if (idx[mid] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    };
    const ans: number[] = [];
    for (let i = 0; i < n; ++i) {
        const l = search(i - k);
        const r = search(i + k + 1) - 1;
        if (l <= r) {
            ans.push(i);
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn find_k_distant_indices(nums: Vec<i32>, key: i32, k: i32) -> Vec<i32> {
        let n = nums.len();
        let mut idx = Vec::new();
        for i in 0..n {
            if nums[i] == key {
                idx.push(i as i32);
            }
        }

        let search = |x: i32| -> usize {
            let (mut l, mut r) = (0, idx.len());
            while l < r {
                let mid = (l + r) >> 1;
                if idx[mid] >= x {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            l
        };

        let mut ans = Vec::new();
        for i in 0..n {
            let l = search(i as i32 - k);
            let r = search(i as i32 + k + 1) as i32 - 1;
            if l as i32 <= r {
                ans.push(i as i32);
            }
        }

        ans
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法三：双指针

我们枚举下标 $i$，用一个指针 $j$ 指向满足 $j \geq i - k$ 且 $nums[j] = key$ 的最小下标，如果 $j$ 存在且 $j \leq i + k$，那么 $i$ 就是一个 K 近邻下标，我们将 $i$ 加入答案数组中。

时间复杂度 $O(n)$，其中 $n$ 是数组 $nums$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findKDistantIndices(self, nums: List[int], key: int, k: int) -> List[int]:
        ans = []
        j, n = 0, len(nums)
        for i in range(n):
            while j < i - k or (j < n and nums[j] != key):
                j += 1
            if j < n and j <= (i + k):
                ans.append(i)
        return ans
```

#### Java

```java
class Solution {
    public List<Integer> findKDistantIndices(int[] nums, int key, int k) {
        int n = nums.length;
        List<Integer> ans = new ArrayList<>();
        for (int i = 0, j = 0; i < n; ++i) {
            while (j < i - k || (j < n && nums[j] != key)) {
                ++j;
            }
            if (j < n && j <= i + k) {
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
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0, j = 0; i < n; ++i) {
            while (j < i - k || (j < n && nums[j] != key)) {
                ++j;
            }
            if (j < n && j <= i + k) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func findKDistantIndices(nums []int, key int, k int) (ans []int) {
	n := len(nums)
	for i, j := 0, 0; i < n; i++ {
		for j < i-k || (j < n && nums[j] != key) {
			j++
		}
		if j < n && j <= i+k {
			ans = append(ans, i)
		}
	}
	return
}
```

#### TypeScript

```ts
function findKDistantIndices(nums: number[], key: number, k: number): number[] {
    const n = nums.length;
    const ans: number[] = [];
    for (let i = 0, j = 0; i < n; ++i) {
        while (j < i - k || (j < n && nums[j] !== key)) {
            ++j;
        }
        if (j < n && j <= i + k) {
            ans.push(i);
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn find_k_distant_indices(nums: Vec<i32>, key: i32, k: i32) -> Vec<i32> {
        let n = nums.len();
        let mut ans = Vec::new();
        let mut j = 0;
        for i in 0..n {
            while j < i.saturating_sub(k as usize) || (j < n && nums[j] != key) {
                j += 1;
            }
            if j < n && j <= i + k as usize {
                ans.push(i as i32);
            }
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

# [2201. 统计可以提取的工件](https://leetcode.cn/problems/count-artifacts-that-can-be-extracted){#2201}

{{< tabs "2201" >}}

{{% tab "python" %}}
```python
class Solution:
    def digArtifacts(
        self, n: int, artifacts: List[List[int]], dig: List[List[int]]
    ) -> int:
        def check(a: List[int]) -> bool:
            x1, y1, x2, y2 = a
            return all(
                (x, y) in s for x in range(x1, x2 + 1) for y in range(y1, y2 + 1)
            )

        s = {(i, j) for i, j in dig}
        return sum(check(a) for a in artifacts)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private Set<Integer> s = new HashSet<>();
    private int n;

    public int digArtifacts(int n, int[][] artifacts, int[][] dig) {
        this.n = n;
        for (var p : dig) {
            s.add(p[0] * n + p[1]);
        }
        int ans = 0;
        for (var a : artifacts) {
            ans += check(a);
        }
        return ans;
    }

    private int check(int[] a) {
        int x1 = a[0], y1 = a[1], x2 = a[2], y2 = a[3];
        for (int x = x1; x <= x2; ++x) {
            for (int y = y1; y <= y2; ++y) {
                if (!s.contains(x * n + y)) {
                    return 0;
                }
            }
        }
        return 1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        unordered_set<int> s;
        for (auto& p : dig) {
            s.insert(p[0] * n + p[1]);
        }
        auto check = [&](vector<int>& a) {
            int x1 = a[0], y1 = a[1], x2 = a[2], y2 = a[3];
            for (int x = x1; x <= x2; ++x) {
                for (int y = y1; y <= y2; ++y) {
                    if (!s.count(x * n + y)) {
                        return 0;
                    }
                }
            }
            return 1;
        };
        int ans = 0;
        for (auto& a : artifacts) {
            ans += check(a);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func digArtifacts(n int, artifacts [][]int, dig [][]int) (ans int) {
	s := map[int]bool{}
	for _, p := range dig {
		s[p[0]*n+p[1]] = true
	}
	check := func(a []int) int {
		x1, y1, x2, y2 := a[0], a[1], a[2], a[3]
		for x := x1; x <= x2; x++ {
			for y := y1; y <= y2; y++ {
				if !s[x*n+y] {
					return 0
				}
			}
		}
		return 1
	}
	for _, a := range artifacts {
		ans += check(a)
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function digArtifacts(n: number, artifacts: number[][], dig: number[][]): number {
    const s: Set<number> = new Set();
    for (const [x, y] of dig) {
        s.add(x * n + y);
    }
    let ans = 0;
    const check = (a: number[]): number => {
        const [x1, y1, x2, y2] = a;
        for (let x = x1; x <= x2; ++x) {
            for (let y = y1; y <= y2; ++y) {
                if (!s.has(x * n + y)) {
                    return 0;
                }
            }
        }
        return 1;
    };
    for (const a of artifacts) {
        ans += check(a);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashSet;

impl Solution {
    pub fn dig_artifacts(n: i32, artifacts: Vec<Vec<i32>>, dig: Vec<Vec<i32>>) -> i32 {
        let mut s: HashSet<i32> = HashSet::new();
        for p in dig {
            s.insert(p[0] * n + p[1]);
        }
        let check = |a: &[i32]| -> i32 {
            let x1 = a[0];
            let y1 = a[1];
            let x2 = a[2];
            let y2 = a[3];
            for x in x1..=x2 {
                for y in y1..=y2 {
                    if !s.contains(&(x * n + y)) {
                        return 0;
                    }
                }
            }
            1
        };
        let mut ans = 0;
        for a in artifacts {
            ans += check(&a);
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

<p>存在一个 <code>n x n</code> 大小、下标从 <strong>0</strong> 开始的网格，网格中埋着一些工件。给你一个整数 <code>n</code> 和一个下标从 <strong>0</strong> 开始的二维整数数组 <code>artifacts</code> ，<code>artifacts</code> 描述了矩形工件的位置，其中 <code>artifacts[i] = [r1<sub>i</sub>, c1<sub>i</sub>, r2<sub>i</sub>, c2<sub>i</sub>]</code> 表示第 <code>i</code> 个工件在子网格中的填埋情况：</p>

<ul>
	<li><code>(r1<sub>i</sub>, c1<sub>i</sub>)</code> 是第 <code>i</code> 个工件 <strong>左上</strong> 单元格的坐标，且</li>
	<li><code>(r2<sub>i</sub>, c2<sub>i</sub>)</code> 是第 <code>i</code> 个工件 <strong>右下</strong> 单元格的坐标。</li>
</ul>

<p>你将会挖掘网格中的一些单元格，并清除其中的填埋物。如果单元格中埋着工件的一部分，那么该工件这一部分将会裸露出来。如果一个工件的所有部分都都裸露出来，你就可以提取该工件。</p>

<p>给你一个下标从 <strong>0</strong> 开始的二维整数数组 <code>dig</code> ，其中 <code>dig[i] = [r<sub>i</sub>, c<sub>i</sub>]</code> 表示你将会挖掘单元格 <code>(r<sub>i</sub>, c<sub>i</sub>)</code> ，返回你可以提取的工件数目。</p>

<p>生成的测试用例满足：</p>

<ul>
	<li>不存在重叠的两个工件。</li>
	<li>每个工件最多只覆盖 <code>4</code> 个单元格。</li>
	<li><code>dig</code> 中的元素互不相同。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2200-2299/2201.Count%20Artifacts%20That%20Can%20Be%20Extracted/images/untitled-diagram.jpg" style="width: 216px; height: 216px;">
<pre><strong>输入：</strong>n = 2, artifacts = [[0,0,0,0],[0,1,1,1]], dig = [[0,0],[0,1]]
<strong>输出：</strong>1
<strong>解释：</strong> 
不同颜色表示不同的工件。挖掘的单元格用 'D' 在网格中进行标记。
有 1 个工件可以提取，即红色工件。
蓝色工件在单元格 (1,1) 的部分尚未裸露出来，所以无法提取该工件。
因此，返回 1 。
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2200-2299/2201.Count%20Artifacts%20That%20Can%20Be%20Extracted/images/untitled-diagram-1.jpg" style="width: 216px; height: 216px;">
<pre><strong>输入：</strong>n = 2, artifacts = [[0,0,0,0],[0,1,1,1]], dig = [[0,0],[0,1],[1,1]]
<strong>输出：</strong>2
<strong>解释：</strong>红色工件和蓝色工件的所有部分都裸露出来（用 'D' 标记），都可以提取。因此，返回 2 。 
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
	<li><code>1 &lt;= artifacts.length, dig.length &lt;= min(n<sup>2</sup>, 10<sup>5</sup>)</code></li>
	<li><code>artifacts[i].length == 4</code></li>
	<li><code>dig[i].length == 2</code></li>
	<li><code>0 &lt;= r1<sub>i</sub>, c1<sub>i</sub>, r2<sub>i</sub>, c2<sub>i</sub>, r<sub>i</sub>, c<sub>i</sub> &lt;= n - 1</code></li>
	<li><code>r1<sub>i</sub> &lt;= r2<sub>i</sub></code></li>
	<li><code>c1<sub>i</sub> &lt;= c2<sub>i</sub></code></li>
	<li>不存在重叠的两个工件</li>
	<li>每个工件 <strong>最多</strong> 只覆盖 <code>4</code> 个单元格</li>
	<li><code>dig</code> 中的元素互不相同</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

我们可以用哈希表 $s$ 记录所有挖掘的单元格，然后遍历所有工件，判断工件的所有部分是否都在哈希表中，若是则可以提取该工件，答案加一。

时间复杂度 $O(m + k)$，空间复杂度 $O(k)$，其中 $m$ 是工件的数量，而 $k$ 是挖掘的单元格的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def digArtifacts(
        self, n: int, artifacts: List[List[int]], dig: List[List[int]]
    ) -> int:
        def check(a: List[int]) -> bool:
            x1, y1, x2, y2 = a
            return all(
                (x, y) in s for x in range(x1, x2 + 1) for y in range(y1, y2 + 1)
            )

        s = {(i, j) for i, j in dig}
        return sum(check(a) for a in artifacts)
```

#### Java

```java
class Solution {
    private Set<Integer> s = new HashSet<>();
    private int n;

    public int digArtifacts(int n, int[][] artifacts, int[][] dig) {
        this.n = n;
        for (var p : dig) {
            s.add(p[0] * n + p[1]);
        }
        int ans = 0;
        for (var a : artifacts) {
            ans += check(a);
        }
        return ans;
    }

    private int check(int[] a) {
        int x1 = a[0], y1 = a[1], x2 = a[2], y2 = a[3];
        for (int x = x1; x <= x2; ++x) {
            for (int y = y1; y <= y2; ++y) {
                if (!s.contains(x * n + y)) {
                    return 0;
                }
            }
        }
        return 1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        unordered_set<int> s;
        for (auto& p : dig) {
            s.insert(p[0] * n + p[1]);
        }
        auto check = [&](vector<int>& a) {
            int x1 = a[0], y1 = a[1], x2 = a[2], y2 = a[3];
            for (int x = x1; x <= x2; ++x) {
                for (int y = y1; y <= y2; ++y) {
                    if (!s.count(x * n + y)) {
                        return 0;
                    }
                }
            }
            return 1;
        };
        int ans = 0;
        for (auto& a : artifacts) {
            ans += check(a);
        }
        return ans;
    }
};
```

#### Go

```go
func digArtifacts(n int, artifacts [][]int, dig [][]int) (ans int) {
	s := map[int]bool{}
	for _, p := range dig {
		s[p[0]*n+p[1]] = true
	}
	check := func(a []int) int {
		x1, y1, x2, y2 := a[0], a[1], a[2], a[3]
		for x := x1; x <= x2; x++ {
			for y := y1; y <= y2; y++ {
				if !s[x*n+y] {
					return 0
				}
			}
		}
		return 1
	}
	for _, a := range artifacts {
		ans += check(a)
	}
	return
}
```

#### TypeScript

```ts
function digArtifacts(n: number, artifacts: number[][], dig: number[][]): number {
    const s: Set<number> = new Set();
    for (const [x, y] of dig) {
        s.add(x * n + y);
    }
    let ans = 0;
    const check = (a: number[]): number => {
        const [x1, y1, x2, y2] = a;
        for (let x = x1; x <= x2; ++x) {
            for (let y = y1; y <= y2; ++y) {
                if (!s.has(x * n + y)) {
                    return 0;
                }
            }
        }
        return 1;
    };
    for (const a of artifacts) {
        ans += check(a);
    }
    return ans;
}
```

#### Rust

```rust
use std::collections::HashSet;

impl Solution {
    pub fn dig_artifacts(n: i32, artifacts: Vec<Vec<i32>>, dig: Vec<Vec<i32>>) -> i32 {
        let mut s: HashSet<i32> = HashSet::new();
        for p in dig {
            s.insert(p[0] * n + p[1]);
        }
        let check = |a: &[i32]| -> i32 {
            let x1 = a[0];
            let y1 = a[1];
            let x2 = a[2];
            let y2 = a[3];
            for x in x1..=x2 {
                for y in y1..=y2 {
                    if !s.contains(&(x * n + y)) {
                        return 0;
                    }
                }
            }
            1
        };
        let mut ans = 0;
        for a in artifacts {
            ans += check(&a);
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

# [2202. K 次操作后最大化顶端元素](https://leetcode.cn/problems/maximize-the-topmost-element-after-k-moves){#2202}

{{< tabs "2202" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumTop(self, nums: List[int], k: int) -> int:
        if k == 0:
            return nums[0]
        n = len(nums)
        if n == 1:
            if k % 2:
                return -1
            return nums[0]
        ans = max(nums[: k - 1], default=-1)
        if k < n:
            ans = max(ans, nums[k])
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maximumTop(int[] nums, int k) {
        if (k == 0) {
            return nums[0];
        }
        int n = nums.length;
        if (n == 1) {
            if (k % 2 == 1) {
                return -1;
            }
            return nums[0];
        }
        int ans = -1;
        for (int i = 0; i < Math.min(k - 1, n); ++i) {
            ans = Math.max(ans, nums[i]);
        }
        if (k < n) {
            ans = Math.max(ans, nums[k]);
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
    int maximumTop(vector<int>& nums, int k) {
        if (k == 0) return nums[0];
        int n = nums.size();
        if (n == 1) {
            if (k % 2) return -1;
            return nums[0];
        }
        int ans = -1;
        for (int i = 0; i < min(k - 1, n); ++i) ans = max(ans, nums[i]);
        if (k < n) ans = max(ans, nums[k]);
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumTop(nums []int, k int) int {
	if k == 0 {
		return nums[0]
	}
	n := len(nums)
	if n == 1 {
		if k%2 == 1 {
			return -1
		}
		return nums[0]
	}
	ans := -1
	for i := 0; i < min(k-1, n); i++ {
		ans = max(ans, nums[i])
	}
	if k < n {
		ans = max(ans, nums[k])
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

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>nums</code>&nbsp;，它表示一个 <strong>堆</strong> ，其中 <code>nums[0]</code>&nbsp;是堆顶的元素。</p>

<p>每一次操作中，你可以执行以下操作 <strong>之一</strong>&nbsp;：</p>

<ul>
	<li>如果堆非空，那么 <strong>删除</strong>&nbsp;堆顶端的元素。</li>
	<li>如果存在 1 个或者多个被删除的元素，你可以从它们中选择任何一个，<b>添加</b>&nbsp;回堆顶，这个元素成为新的堆顶元素。</li>
</ul>

<p>同时给你一个整数&nbsp;<code>k</code>&nbsp;，它表示你总共需要执行操作的次数。</p>

<p>请你返回 <strong>恰好</strong>&nbsp;执行 <code>k</code>&nbsp;次操作以后，堆顶元素的 <strong>最大值</strong>&nbsp;。如果执行完 <code>k</code>&nbsp;次操作以后，堆一定为空，请你返回 <code>-1</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [5,2,2,4,0,6], k = 4
<b>输出：</b>5
<strong>解释：</strong>
4 次操作后，堆顶元素为 5 的方法之一为：
- 第 1 次操作：删除堆顶元素 5 ，堆变为 [2,2,4,0,6] 。
- 第 2 次操作：删除堆顶元素 2 ，堆变为 [2,4,0,6] 。
- 第 3 次操作：删除堆顶元素 2 ，堆变为 [4,0,6] 。
- 第 4 次操作：将 5 添加回堆顶，堆变为 [5,4,0,6] 。
注意，这不是最后堆顶元素为 5 的唯一方式。但可以证明，4 次操作以后 5 是能得到的最大堆顶元素。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [2], k = 1
<b>输出：</b>-1
<b>解释：</b>
第 1 次操作中，我们唯一的选择是将堆顶元素弹出堆。
由于 1 次操作后无法得到一个非空的堆，所以我们返回 -1 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i], k &lt;= 10<sup>9</sup></code></li>
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
    def maximumTop(self, nums: List[int], k: int) -> int:
        if k == 0:
            return nums[0]
        n = len(nums)
        if n == 1:
            if k % 2:
                return -1
            return nums[0]
        ans = max(nums[: k - 1], default=-1)
        if k < n:
            ans = max(ans, nums[k])
        return ans
```

#### Java

```java
class Solution {
    public int maximumTop(int[] nums, int k) {
        if (k == 0) {
            return nums[0];
        }
        int n = nums.length;
        if (n == 1) {
            if (k % 2 == 1) {
                return -1;
            }
            return nums[0];
        }
        int ans = -1;
        for (int i = 0; i < Math.min(k - 1, n); ++i) {
            ans = Math.max(ans, nums[i]);
        }
        if (k < n) {
            ans = Math.max(ans, nums[k]);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        if (k == 0) return nums[0];
        int n = nums.size();
        if (n == 1) {
            if (k % 2) return -1;
            return nums[0];
        }
        int ans = -1;
        for (int i = 0; i < min(k - 1, n); ++i) ans = max(ans, nums[i]);
        if (k < n) ans = max(ans, nums[k]);
        return ans;
    }
};
```

#### Go

```go
func maximumTop(nums []int, k int) int {
	if k == 0 {
		return nums[0]
	}
	n := len(nums)
	if n == 1 {
		if k%2 == 1 {
			return -1
		}
		return nums[0]
	}
	ans := -1
	for i := 0; i < min(k-1, n); i++ {
		ans = max(ans, nums[i])
	}
	if k < n {
		ans = max(ans, nums[k])
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2203. 得到要求路径的最小带权子图](https://leetcode.cn/problems/minimum-weighted-subgraph-with-the-required-paths){#2203}

{{< tabs "2203" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumWeight(
        self, n: int, edges: List[List[int]], src1: int, src2: int, dest: int
    ) -> int:
        def dijkstra(g, u):
            dist = [inf] * n
            dist[u] = 0
            q = [(0, u)]
            while q:
                d, u = heappop(q)
                if d > dist[u]:
                    continue
                for v, w in g[u]:
                    if dist[v] > dist[u] + w:
                        dist[v] = dist[u] + w
                        heappush(q, (dist[v], v))
            return dist

        g = defaultdict(list)
        rg = defaultdict(list)
        for f, t, w in edges:
            g[f].append((t, w))
            rg[t].append((f, w))
        d1 = dijkstra(g, src1)
        d2 = dijkstra(g, src2)
        d3 = dijkstra(rg, dest)
        ans = min(sum(v) for v in zip(d1, d2, d3))
        return -1 if ans >= inf else ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private static final Long INF = Long.MAX_VALUE;

    public long minimumWeight(int n, int[][] edges, int src1, int src2, int dest) {
        List<Pair<Integer, Long>>[] g = new List[n];
        List<Pair<Integer, Long>>[] rg = new List[n];
        for (int i = 0; i < n; ++i) {
            g[i] = new ArrayList<>();
            rg[i] = new ArrayList<>();
        }
        for (int[] e : edges) {
            int f = e[0], t = e[1];
            long w = e[2];
            g[f].add(new Pair<>(t, w));
            rg[t].add(new Pair<>(f, w));
        }
        long[] d1 = dijkstra(g, src1);
        long[] d2 = dijkstra(g, src2);
        long[] d3 = dijkstra(rg, dest);
        long ans = -1;
        for (int i = 0; i < n; ++i) {
            if (d1[i] == INF || d2[i] == INF || d3[i] == INF) {
                continue;
            }
            long t = d1[i] + d2[i] + d3[i];
            if (ans == -1 || ans > t) {
                ans = t;
            }
        }
        return ans;
    }

    private long[] dijkstra(List<Pair<Integer, Long>>[] g, int u) {
        int n = g.length;
        long[] dist = new long[n];
        Arrays.fill(dist, INF);
        dist[u] = 0;
        PriorityQueue<Pair<Long, Integer>> q
            = new PriorityQueue<>(Comparator.comparingLong(Pair::getKey));
        q.offer(new Pair<>(0L, u));
        while (!q.isEmpty()) {
            Pair<Long, Integer> p = q.poll();
            long d = p.getKey();
            u = p.getValue();
            if (d > dist[u]) {
                continue;
            }
            for (Pair<Integer, Long> e : g[u]) {
                int v = e.getKey();
                long w = e.getValue();
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    q.offer(new Pair<>(dist[v], v));
                }
            }
        }
        return dist;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数&nbsp;<code>n</code>&nbsp;，它表示一个 <strong>带权有向</strong> 图的节点数，节点编号为&nbsp;<code>0</code> 到&nbsp;<code>n - 1</code>&nbsp;。</p>

<p>同时给你一个二维整数数组&nbsp;<code>edges</code>&nbsp;，其中&nbsp;<code>edges[i] = [from<sub>i</sub>, to<sub>i</sub>, weight<sub>i</sub>]</code>&nbsp;，表示从&nbsp;<code>from<sub>i</sub></code>&nbsp;到&nbsp;<code>to<sub>i</sub></code>&nbsp;有一条边权为&nbsp;<code>weight<sub>i</sub></code>&nbsp;的 <strong>有向</strong> 边。</p>

<p>最后，给你三个 <strong>互不相同</strong>&nbsp;的整数&nbsp;<code>src1</code>&nbsp;，<code>src2</code>&nbsp;和&nbsp;<code>dest</code>&nbsp;，表示图中三个不同的点。</p>

<p>请你从图中选出一个 <b>边权和最小</b>&nbsp;的子图，使得从 <code>src1</code>&nbsp;和 <code>src2</code>&nbsp;出发，在这个子图中，都 <strong>可以</strong>&nbsp;到达 <code>dest</code>&nbsp;。如果这样的子图不存在，请返回 <code>-1</code>&nbsp;。</p>

<p><strong>子图</strong>&nbsp;中的点和边都应该属于原图的一部分。子图的边权和定义为它所包含的所有边的权值之和。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2200-2299/2203.Minimum%20Weighted%20Subgraph%20With%20the%20Required%20Paths/images/example1drawio.png" style="width: 263px; height: 250px;" /></p>

<pre>
<b>输入：</b>n = 6, edges = [[0,2,2],[0,5,6],[1,0,3],[1,4,5],[2,1,1],[2,3,3],[2,3,4],[3,4,2],[4,5,1]], src1 = 0, src2 = 1, dest = 5
<b>输出：</b>9
<strong>解释：</strong>
上图为输入的图。
蓝色边为最优子图之一。
注意，子图 [[1,0,3],[0,5,6]] 也能得到最优解，但无法在满足所有限制的前提下，得到更优解。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2200-2299/2203.Minimum%20Weighted%20Subgraph%20With%20the%20Required%20Paths/images/example2-1drawio.png" style="width: 350px; height: 51px;" /></p>

<pre>
<b>输入：</b>n = 3, edges = [[0,1,1],[2,1,1]], src1 = 0, src2 = 1, dest = 2
<b>输出：</b>-1
<strong>解释：</strong>
上图为输入的图。
可以看到，不存在从节点 1 到节点 2 的路径，所以不存在任何子图满足所有限制。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= edges.length &lt;= 10<sup>5</sup></code></li>
	<li><code>edges[i].length == 3</code></li>
	<li><code>0 &lt;= from<sub>i</sub>, to<sub>i</sub>, src1, src2, dest &lt;= n - 1</code></li>
	<li><code>from<sub>i</sub> != to<sub>i</sub></code></li>
	<li><code>src1</code>&nbsp;，<code>src2</code>&nbsp;和&nbsp;<code>dest</code>&nbsp;两两不同。</li>
	<li><code>1 &lt;= weight[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举三条最短路的交汇点

最短路问题。

我们假设从 $src1$ 出发到 $dest$ 的一条最短路径为 $A$，从 $src2$ 出发到 $dest$ 的一条最短路径为 $B$。

$A$, $B$ 两条路径一定存在着公共点 $p$，因为 $dest$ 一定是其中一个公共点。那么问题可以转换为求以下三条路径和的最小值：

1. 从 $src1$ 到 $p$ 的最短路
1. 从 $src2$ 到 $p$ 的最短路
1. 从 $p$ 到 $dest$ 的最短路（这里我们可以将原图的所有边反向，然后转换为从 $dest$ 到 $p$ 的最短路）

我们进行三次 Dijkstra 算法，就可以求出 $src1$, $src2$, $dest$ 到其他点的最短路径。

公共点可以有多个，因此我们在 $[0,n)$ 范围内枚举公共点 $p$，找出边权之和最小的值即可。

时间复杂度 $O(mlogn)$，其中 m 表示数组 $edges$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumWeight(
        self, n: int, edges: List[List[int]], src1: int, src2: int, dest: int
    ) -> int:
        def dijkstra(g, u):
            dist = [inf] * n
            dist[u] = 0
            q = [(0, u)]
            while q:
                d, u = heappop(q)
                if d > dist[u]:
                    continue
                for v, w in g[u]:
                    if dist[v] > dist[u] + w:
                        dist[v] = dist[u] + w
                        heappush(q, (dist[v], v))
            return dist

        g = defaultdict(list)
        rg = defaultdict(list)
        for f, t, w in edges:
            g[f].append((t, w))
            rg[t].append((f, w))
        d1 = dijkstra(g, src1)
        d2 = dijkstra(g, src2)
        d3 = dijkstra(rg, dest)
        ans = min(sum(v) for v in zip(d1, d2, d3))
        return -1 if ans >= inf else ans
```

#### Java

```java
class Solution {
    private static final Long INF = Long.MAX_VALUE;

    public long minimumWeight(int n, int[][] edges, int src1, int src2, int dest) {
        List<Pair<Integer, Long>>[] g = new List[n];
        List<Pair<Integer, Long>>[] rg = new List[n];
        for (int i = 0; i < n; ++i) {
            g[i] = new ArrayList<>();
            rg[i] = new ArrayList<>();
        }
        for (int[] e : edges) {
            int f = e[0], t = e[1];
            long w = e[2];
            g[f].add(new Pair<>(t, w));
            rg[t].add(new Pair<>(f, w));
        }
        long[] d1 = dijkstra(g, src1);
        long[] d2 = dijkstra(g, src2);
        long[] d3 = dijkstra(rg, dest);
        long ans = -1;
        for (int i = 0; i < n; ++i) {
            if (d1[i] == INF || d2[i] == INF || d3[i] == INF) {
                continue;
            }
            long t = d1[i] + d2[i] + d3[i];
            if (ans == -1 || ans > t) {
                ans = t;
            }
        }
        return ans;
    }

    private long[] dijkstra(List<Pair<Integer, Long>>[] g, int u) {
        int n = g.length;
        long[] dist = new long[n];
        Arrays.fill(dist, INF);
        dist[u] = 0;
        PriorityQueue<Pair<Long, Integer>> q
            = new PriorityQueue<>(Comparator.comparingLong(Pair::getKey));
        q.offer(new Pair<>(0L, u));
        while (!q.isEmpty()) {
            Pair<Long, Integer> p = q.poll();
            long d = p.getKey();
            u = p.getValue();
            if (d > dist[u]) {
                continue;
            }
            for (Pair<Integer, Long> e : g[u]) {
                int v = e.getKey();
                long w = e.getValue();
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    q.offer(new Pair<>(dist[v], v));
                }
            }
        }
        return dist;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2204. 无向图中到环的距离 🔒](https://leetcode.cn/problems/distance-to-a-cycle-in-undirected-graph){#2204}

{{< tabs "2204" >}}

{{% tab "python" %}}
```python
class Solution:
    def distanceToCycle(self, n: int, edges: List[List[int]]) -> List[int]:
        g = defaultdict(set)
        for a, b in edges:
            g[a].add(b)
            g[b].add(a)
        q = deque(i for i in range(n) if len(g[i]) == 1)
        f = [0] * n
        seq = []
        while q:
            i = q.popleft()
            seq.append(i)
            for j in g[i]:
                g[j].remove(i)
                f[i] = j
                if len(g[j]) == 1:
                    q.append(j)
            g[i].clear()
        ans = [0] * n
        for i in seq[::-1]:
            ans[i] = ans[f[i]] + 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] distanceToCycle(int n, int[][] edges) {
        Set<Integer>[] g = new Set[n];
        Arrays.setAll(g, k -> new HashSet<>());
        for (var e : edges) {
            int a = e[0], b = e[1];
            g[a].add(b);
            g[b].add(a);
        }
        Deque<Integer> q = new ArrayDeque<>();
        for (int i = 0; i < n; ++i) {
            if (g[i].size() == 1) {
                q.offer(i);
            }
        }
        int[] f = new int[n];
        Deque<Integer> seq = new ArrayDeque<>();
        while (!q.isEmpty()) {
            int i = q.poll();
            seq.push(i);
            for (int j : g[i]) {
                g[j].remove(i);
                f[i] = j;
                if (g[j].size() == 1) {
                    q.offer(j);
                }
            }
        }
        int[] ans = new int[n];
        while (!seq.isEmpty()) {
            int i = seq.pop();
            ans[i] = ans[f[i]] + 1;
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
    vector<int> distanceToCycle(int n, vector<vector<int>>& edges) {
        unordered_set<int> g[n];
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            g[a].insert(b);
            g[b].insert(a);
        }
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (g[i].size() == 1) {
                q.push(i);
            }
        }
        int f[n];
        int seq[n];
        int k = 0;
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            seq[k++] = i;
            for (int j : g[i]) {
                g[j].erase(i);
                f[i] = j;
                if (g[j].size() == 1) {
                    q.push(j);
                }
            }
            g[i].clear();
        }
        vector<int> ans(n);
        for (; k; --k) {
            int i = seq[k - 1];
            ans[i] = ans[f[i]] + 1;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func distanceToCycle(n int, edges [][]int) []int {
	g := make([]map[int]bool, n)
	for i := range g {
		g[i] = map[int]bool{}
	}
	for _, e := range edges {
		a, b := e[0], e[1]
		g[a][b] = true
		g[b][a] = true
	}
	q := []int{}
	for i := 0; i < n; i++ {
		if len(g[i]) == 1 {
			q = append(q, i)
		}
	}
	f := make([]int, n)
	seq := []int{}
	for len(q) > 0 {
		i := q[0]
		q = q[1:]
		seq = append(seq, i)
		for j := range g[i] {
			delete(g[j], i)
			f[i] = j
			if len(g[j]) == 1 {
				q = append(q, j)
			}
		}
		g[i] = map[int]bool{}
	}
	ans := make([]int, n)
	for k := len(seq) - 1; k >= 0; k-- {
		i := seq[k]
		ans[i] = ans[f[i]] + 1
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function distanceToCycle(n: number, edges: number[][]): number[] {
    const g: Set<number>[] = new Array(n).fill(0).map(() => new Set<number>());
    for (const [a, b] of edges) {
        g[a].add(b);
        g[b].add(a);
    }
    const q: number[] = [];
    for (let i = 0; i < n; ++i) {
        if (g[i].size === 1) {
            q.push(i);
        }
    }
    const f: number[] = Array(n).fill(0);
    const seq: number[] = [];
    while (q.length) {
        const i = q.pop()!;
        seq.push(i);
        for (const j of g[i]) {
            g[j].delete(i);
            f[i] = j;
            if (g[j].size === 1) {
                q.push(j);
            }
        }
        g[i].clear();
    }
    const ans: number[] = Array(n).fill(0);
    while (seq.length) {
        const i = seq.pop()!;
        ans[i] = ans[f[i]] + 1;
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

<p>给定一个正整数 <code>n</code>，表示一个 <strong>连通无向图</strong> 中的节点数，该图&nbsp;<strong>只包含一个&nbsp;</strong>环。节点编号为 <code>0</code> ~ <code>n - 1</code>(<strong>含</strong>)。</p>

<p>你还得到了一个二维整数数组 <code>edges</code>，其中 <code>edges[i] = [node1<sub>i</sub>, node2<sub>i</sub>]</code> 表示有一条&nbsp;<strong>双向&nbsp;</strong>边连接图中的 <code>node1<sub>i</sub></code> 和 <code>node2<sub>i</sub></code>。</p>

<p>两个节点 <code>a</code> 和 <code>b</code> 之间的距离定义为从 <code>a</code> 到 <code>b</code> 所需的&nbsp;<strong>最小边数</strong>。</p>

<p>返回<em>一个长度为 <code>n</code> 的整数数组 <code>answer</code>，其中 </em><code>answer[i]</code><em> 是第 <code>i</code> 个节点与环中任何节点之间的最小距离</em>。</p>

<p><strong class="example">示例 1:</strong></p>
<img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2200-2299/2204.Distance%20to%20a%20Cycle%20in%20Undirected%20Graph/images/image-20220315154238-1.png" style="width: 350px; height: 237px;" />
<pre>
<strong>输入:</strong> n = 7, edges = [[1,2],[2,4],[4,3],[3,1],[0,1],[5,2],[6,5]]
<strong>输出:</strong> [1,0,0,0,0,1,2]
<strong>解释:</strong>
节点 1, 2, 3, 和 4 来自环。
0 到 1 的距离是 1。
1 到 1 的距离是 0。
2 到 2 的距离是 0。
3 到 3 的距离是 0。
4 到 4 的距离是 0。
5 到 2 的距离是 1。
6 到 2 的距离是 2。
</pre>

<p><strong class="example">示例 2:</strong></p>
<img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2200-2299/2204.Distance%20to%20a%20Cycle%20in%20Undirected%20Graph/images/image-20220315154634-1.png" style="width: 400px; height: 297px;" />
<pre>
<strong>输入:</strong> n = 9, edges = [[0,1],[1,2],[0,2],[2,6],[6,7],[6,8],[0,3],[3,4],[3,5]]
<strong>输出:</strong> [0,0,0,1,2,2,1,2,2]
<strong>解释:</strong>
节点 0, 1, 和 2 来自环.
0 到 0 的距离是 0。
1 到 1 的距离是 0。
2 到 2 的距离是 0。
3 到 1 的距离是 1。
4 到 1 的距离是 2。
5 到 1 的距离是 2。
6 到 2 的距离是 1。
7 到 2 的距离是 2。
8 到 2 的距离是 2。
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>3 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>edges.length == n</code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>0 &lt;= node1<sub>i</sub>, node2<sub>i</sub> &lt;= n - 1</code></li>
	<li><code>node1<sub>i</sub> != node2<sub>i</sub></code></li>
	<li>图是连通的。</li>
	<li>这个图只有一个环。</li>
	<li>任何顶点对之间最多只有一条边。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：拓扑排序

我们可以先将 $edges$ 中的边转换成邻接表 $g$，其中 $g[i]$ 表示节点 $i$ 的所有邻接节点，用集合表示。

接下来，我们由外向内，逐层删除节点，直到最终只剩下一个环。具体做法如下：

我们先找出所有度为 $1$ 的节点，将这些节点从图中删除，如果删除后，其邻接节点的度变为 $1$，则将其加入队列 $q$ 中。过程中，我们按顺序记录下所有被删除的节点，记为 $seq$；并且，我们用一个数组 $f$ 记录每个节点相邻的且更接近环的节点，即 $f[i]$ 表示节点 $i$ 的相邻且更接近环的节点。

最后，我们初始化一个长度为 $n$ 的答案数组 $ans$，其中 $ans[i]$ 表示节点 $i$ 到环中任意节点的最小距离，初始时 $ans[i] = 0$。然后，我们从 $seq$ 的末尾开始遍历，对于每个节点 $i$，我们可以由它的相邻节点 $f[i]$ 得到 $ans[i]$ 的值，即 $ans[i] = ans[f[i]] + 1$。

遍历结束后，返回答案数组 $ans$ 即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为节点数。

相似题目：

-   [2603. 收集树中金币](https://github.com/doocs/leetcode/blob/main/solution/2600-2699/2603.Collect%20Coins%20in%20a%20Tree/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def distanceToCycle(self, n: int, edges: List[List[int]]) -> List[int]:
        g = defaultdict(set)
        for a, b in edges:
            g[a].add(b)
            g[b].add(a)
        q = deque(i for i in range(n) if len(g[i]) == 1)
        f = [0] * n
        seq = []
        while q:
            i = q.popleft()
            seq.append(i)
            for j in g[i]:
                g[j].remove(i)
                f[i] = j
                if len(g[j]) == 1:
                    q.append(j)
            g[i].clear()
        ans = [0] * n
        for i in seq[::-1]:
            ans[i] = ans[f[i]] + 1
        return ans
```

#### Java

```java
class Solution {
    public int[] distanceToCycle(int n, int[][] edges) {
        Set<Integer>[] g = new Set[n];
        Arrays.setAll(g, k -> new HashSet<>());
        for (var e : edges) {
            int a = e[0], b = e[1];
            g[a].add(b);
            g[b].add(a);
        }
        Deque<Integer> q = new ArrayDeque<>();
        for (int i = 0; i < n; ++i) {
            if (g[i].size() == 1) {
                q.offer(i);
            }
        }
        int[] f = new int[n];
        Deque<Integer> seq = new ArrayDeque<>();
        while (!q.isEmpty()) {
            int i = q.poll();
            seq.push(i);
            for (int j : g[i]) {
                g[j].remove(i);
                f[i] = j;
                if (g[j].size() == 1) {
                    q.offer(j);
                }
            }
        }
        int[] ans = new int[n];
        while (!seq.isEmpty()) {
            int i = seq.pop();
            ans[i] = ans[f[i]] + 1;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> distanceToCycle(int n, vector<vector<int>>& edges) {
        unordered_set<int> g[n];
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            g[a].insert(b);
            g[b].insert(a);
        }
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (g[i].size() == 1) {
                q.push(i);
            }
        }
        int f[n];
        int seq[n];
        int k = 0;
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            seq[k++] = i;
            for (int j : g[i]) {
                g[j].erase(i);
                f[i] = j;
                if (g[j].size() == 1) {
                    q.push(j);
                }
            }
            g[i].clear();
        }
        vector<int> ans(n);
        for (; k; --k) {
            int i = seq[k - 1];
            ans[i] = ans[f[i]] + 1;
        }
        return ans;
    }
};
```

#### Go

```go
func distanceToCycle(n int, edges [][]int) []int {
	g := make([]map[int]bool, n)
	for i := range g {
		g[i] = map[int]bool{}
	}
	for _, e := range edges {
		a, b := e[0], e[1]
		g[a][b] = true
		g[b][a] = true
	}
	q := []int{}
	for i := 0; i < n; i++ {
		if len(g[i]) == 1 {
			q = append(q, i)
		}
	}
	f := make([]int, n)
	seq := []int{}
	for len(q) > 0 {
		i := q[0]
		q = q[1:]
		seq = append(seq, i)
		for j := range g[i] {
			delete(g[j], i)
			f[i] = j
			if len(g[j]) == 1 {
				q = append(q, j)
			}
		}
		g[i] = map[int]bool{}
	}
	ans := make([]int, n)
	for k := len(seq) - 1; k >= 0; k-- {
		i := seq[k]
		ans[i] = ans[f[i]] + 1
	}
	return ans
}
```

#### TypeScript

```ts
function distanceToCycle(n: number, edges: number[][]): number[] {
    const g: Set<number>[] = new Array(n).fill(0).map(() => new Set<number>());
    for (const [a, b] of edges) {
        g[a].add(b);
        g[b].add(a);
    }
    const q: number[] = [];
    for (let i = 0; i < n; ++i) {
        if (g[i].size === 1) {
            q.push(i);
        }
    }
    const f: number[] = Array(n).fill(0);
    const seq: number[] = [];
    while (q.length) {
        const i = q.pop()!;
        seq.push(i);
        for (const j of g[i]) {
            g[j].delete(i);
            f[i] = j;
            if (g[j].size === 1) {
                q.push(j);
            }
        }
        g[i].clear();
    }
    const ans: number[] = Array(n).fill(0);
    while (seq.length) {
        const i = seq.pop()!;
        ans[i] = ans[f[i]] + 1;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2205. 有资格享受折扣的用户数量 🔒](https://leetcode.cn/problems/the-number-of-users-that-are-eligible-for-discount){#2205}

{{< tabs "2205" >}}

{{% tab "sql" %}}
```sql
CREATE FUNCTION getUserIDs(startDate DATE, endDate DATE, minAmount INT) RETURNS INT
BEGIN
  RETURN (
      SELECT COUNT(DISTINCT user_id) AS user_cnt
      FROM Purchases
      WHERE time_stamp BETWEEN startDate AND endDate AND amount >= minAmount
  );
END
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表: <code>Purchases</code></p>

<pre>
+-------------+----------+
| Column Name | Type     |
+-------------+----------+
| user_id     | int      |
| time_stamp  | datetime |
| amount      | int      |
+-------------+----------+
(user_id, time_stamp) 是该表的主键。
每一行都包含 ID 为 user_id 的用户的购买时间和支付金额的信息。
</pre>

<p>&nbsp;</p>

<p>如果用户在时间间隔 <code>[startDate, endDate]</code> 内购买了至少 <code>minAmount</code> 金额的商品，则有资格获得折扣。若要将日期转换为时间，两个日期都应该被视为一天的&nbsp;<strong>开始</strong> (即 <code>endDate = 2022-03-05</code>&nbsp;应该被视为时间 <code>2022-03-05 00:00:00</code>)。</p>

<p>编写一个 SQL 来查询有资格享受折扣的用户数量。</p>

<p>查询结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> 
Purchases 表:
+---------+---------------------+--------+
| user_id | time_stamp          | amount |
+---------+---------------------+--------+
| 1       | 2022-04-20 09:03:00 | 4416   |
| 2       | 2022-03-19 19:24:02 | 678    |
| 3       | 2022-03-18 12:03:09 | 4523   |
| 3       | 2022-03-30 09:43:42 | 626    |
+---------+---------------------+--------+
startDate = 2022-03-08, endDate = 2022-03-20, minAmount = 1000
<strong>输出:</strong> 
+----------+
| user_cnt |
+----------+
| 1        |
+----------+
<strong>解释:</strong>
在这三个用户中，只有用户 3 有资格享受折扣。
 - 用户 1 有一次购买的金额大于 minAmount，但不在时间间隔内。
 - 用户 2 在时间间隔内有一次购买，但金额小于 minAmount。
 - 用户 3 是唯一一个购买行为同时满足这两个条件的用户。</pre>

<p>&nbsp;</p>

<p><b>重要提示：</b>此问题与 <a href="https://leetcode.cn/problems/the-users-that-are-eligible-for-discount/">2230. 查找可享受优惠的用户</a>&nbsp;基本相同。</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：使用 count(distinct) 函数

注意需要判断的是单次购买金额是否大于等于 `minAmount`，而不是累计购买金额是否大于等于 `minAmount`。

<!-- tabs:start -->

#### MySQL

```sql
CREATE FUNCTION getUserIDs(startDate DATE, endDate DATE, minAmount INT) RETURNS INT
BEGIN
  RETURN (
      SELECT COUNT(DISTINCT user_id) AS user_cnt
      FROM Purchases
      WHERE time_stamp BETWEEN startDate AND endDate AND amount >= minAmount
  );
END
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2206. 将数组划分成相等数对](https://leetcode.cn/problems/divide-array-into-equal-pairs){#2206}

{{< tabs "2206" >}}

{{% tab "python" %}}
```python
class Solution:
    def divideArray(self, nums: List[int]) -> bool:
        cnt = Counter(nums)
        return all(v % 2 == 0 for v in cnt.values())
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean divideArray(int[] nums) {
        int[] cnt = new int[510];
        for (int v : nums) {
            ++cnt[v];
        }
        for (int v : cnt) {
            if (v % 2 != 0) {
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
    bool divideArray(vector<int>& nums) {
        int cnt[510]{};
        for (int x : nums) {
            ++cnt[x];
        }
        for (int i = 1; i <= 500; ++i) {
            if (cnt[i] % 2) {
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
func divideArray(nums []int) bool {
	cnt := [510]int{}
	for _, x := range nums {
		cnt[x]++
	}
	for _, v := range cnt {
		if v%2 != 0 {
			return false
		}
	}
	return true
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashMap;

impl Solution {
    pub fn divide_array(nums: Vec<i32>) -> bool {
        let mut cnt = HashMap::new();
        for x in nums {
            *cnt.entry(x).or_insert(0) += 1;
        }
        cnt.values().all(|&v| v % 2 == 0)
    }
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function divideArray(nums: number[]): boolean {
    const cnt = Array(501).fill(0);

    for (const x of nums) {
        cnt[x]++;
    }

    for (const x of cnt) {
        if (x & 1) return false;
    }

    return true;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} nums
 * @return {boolean}
 */
var divideArray = function (nums) {
    const cnt = Array(501).fill(0);

    for (const x of nums) {
        cnt[x]++;
    }

    for (const x of cnt) {
        if (x & 1) return false;
    }

    return true;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组&nbsp;<code>nums</code>&nbsp;，它包含&nbsp;<code>2 * n</code>&nbsp;个整数。</p>

<p>你需要将&nbsp;<code>nums</code> 划分成&nbsp;<code>n</code>&nbsp;个数对，满足：</p>

<ul>
	<li>每个元素 <strong>只属于一个 </strong>数对。</li>
	<li>同一数对中的元素 <strong>相等</strong>&nbsp;。</li>
</ul>

<p>如果可以将 <code>nums</code>&nbsp;划分成 <code>n</code>&nbsp;个数对，请你返回 <code>true</code>&nbsp;，否则返回 <code>false</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [3,2,3,2,2,2]
<b>输出：</b>true
<b>解释：</b>
nums<code>&nbsp;中总共有 6 个元素，所以它们应该被划分成</code> 6 / 2 = 3 个数对。
nums 可以划分成 (2, 2) ，(3, 3) 和 (2, 2) ，满足所有要求。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [1,2,3,4]
<b>输出：</b>false
<b>解释：</b>
无法将 nums 划分成 4 / 2 = 2 个数对且满足所有要求。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>nums.length == 2 * n</code></li>
	<li><code>1 &lt;= n &lt;= 500</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 500</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数

根据题目描述，只要数组中每个元素出现的次数都是偶数次，就可以将数组划分成 $n$ 个数对。

因此，我们可以用一个哈希表或者数组 $\textit{cnt}$ 记录每个元素出现的次数，然后遍历 $\textit{cnt}$，如果有任何一个元素出现的次数是奇数次，就返回 $\textit{false}$，否则返回 $\textit{true}$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 $\textit{nums}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def divideArray(self, nums: List[int]) -> bool:
        cnt = Counter(nums)
        return all(v % 2 == 0 for v in cnt.values())
```

#### Java

```java
class Solution {
    public boolean divideArray(int[] nums) {
        int[] cnt = new int[510];
        for (int v : nums) {
            ++cnt[v];
        }
        for (int v : cnt) {
            if (v % 2 != 0) {
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
    bool divideArray(vector<int>& nums) {
        int cnt[510]{};
        for (int x : nums) {
            ++cnt[x];
        }
        for (int i = 1; i <= 500; ++i) {
            if (cnt[i] % 2) {
                return false;
            }
        }
        return true;
    }
};
```

#### Go

```go
func divideArray(nums []int) bool {
	cnt := [510]int{}
	for _, x := range nums {
		cnt[x]++
	}
	for _, v := range cnt {
		if v%2 != 0 {
			return false
		}
	}
	return true
}
```

#### Rust

```rust
use std::collections::HashMap;

impl Solution {
    pub fn divide_array(nums: Vec<i32>) -> bool {
        let mut cnt = HashMap::new();
        for x in nums {
            *cnt.entry(x).or_insert(0) += 1;
        }
        cnt.values().all(|&v| v % 2 == 0)
    }
}
```

#### TypeScript

```ts
function divideArray(nums: number[]): boolean {
    const cnt = Array(501).fill(0);

    for (const x of nums) {
        cnt[x]++;
    }

    for (const x of cnt) {
        if (x & 1) return false;
    }

    return true;
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @return {boolean}
 */
var divideArray = function (nums) {
    const cnt = Array(501).fill(0);

    for (const x of nums) {
        cnt[x]++;
    }

    for (const x of cnt) {
        if (x & 1) return false;
    }

    return true;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2207. 字符串中最多数目的子序列](https://leetcode.cn/problems/maximize-number-of-subsequences-in-a-string){#2207}

{{< tabs "2207" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumSubsequenceCount(self, text: str, pattern: str) -> int:
        ans = x = y = 0
        for c in text:
            if c == pattern[1]:
                y += 1
                ans += x
            if c == pattern[0]:
                x += 1
        ans += max(x, y)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long maximumSubsequenceCount(String text, String pattern) {
        long ans = 0;
        int x = 0, y = 0;
        for (int i = 0; i < text.length(); ++i) {
            if (text.charAt(i) == pattern.charAt(1)) {
                ++y;
                ans += x;
            }
            if (text.charAt(i) == pattern.charAt(0)) {
                ++x;
            }
        }
        ans += Math.max(x, y);
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        long long ans = 0;
        int x = 0, y = 0;
        for (char& c : text) {
            if (c == pattern[1]) {
                ++y;
                ans += x;
            }
            if (c == pattern[0]) {
                ++x;
            }
        }
        ans += max(x, y);
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumSubsequenceCount(text string, pattern string) (ans int64) {
	x, y := 0, 0
	for _, c := range text {
		if byte(c) == pattern[1] {
			y++
			ans += int64(x)
		}
		if byte(c) == pattern[0] {
			x++
		}
	}
	ans += int64(max(x, y))
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumSubsequenceCount(text: string, pattern: string): number {
    let ans = 0;
    let [x, y] = [0, 0];
    for (const c of text) {
        if (c === pattern[1]) {
            ++y;
            ans += x;
        }
        if (c === pattern[0]) {
            ++x;
        }
    }
    ans += Math.max(x, y);
    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的字符串&nbsp;<code>text</code>&nbsp;和另一个下标从 <strong>0</strong>&nbsp;开始且长度为 <code>2</code>&nbsp;的字符串&nbsp;<code>pattern</code>&nbsp;，两者都只包含小写英文字母。</p>

<p>你可以在 <code>text</code>&nbsp;中任意位置插入 <strong>一个</strong> 字符，这个插入的字符必须是&nbsp;<code>pattern[0]</code>&nbsp;<b>或者</b>&nbsp;<code>pattern[1]</code>&nbsp;。注意，这个字符可以插入在 <code>text</code>&nbsp;开头或者结尾的位置。</p>

<p>请你返回插入一个字符后，<code>text</code>&nbsp;中最多包含多少个等于 <code>pattern</code>&nbsp;的 <strong>子序列</strong>&nbsp;。</p>

<p><strong>子序列</strong> 指的是将一个字符串删除若干个字符后（也可以不删除），剩余字符保持原本顺序得到的字符串。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>text = "abdcdbc", pattern = "ac"
<b>输出：</b>4
<strong>解释：</strong>
如果我们在 text[1] 和 text[2] 之间添加 pattern[0] = 'a' ，那么我们得到 "ab<em><strong>a</strong></em>dcdbc" 。那么 "ac" 作为子序列出现 4 次。
其他得到 4 个 "ac" 子序列的方案还有 "<em><strong>a</strong></em>abdcdbc" 和 "abd<em><strong>a</strong></em>cdbc" 。
但是，"abdc<em><strong>a</strong></em>dbc" ，"abd<em><strong>c</strong></em>cdbc" 和 "abdcdbc<em><strong>c</strong></em>" 这些字符串虽然是可行的插入方案，但是只出现了 3 次 "ac" 子序列，所以不是最优解。
可以证明插入一个字符后，无法得到超过 4 个 "ac" 子序列。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>text = "aabb", pattern = "ab"
<b>输出：</b>6
<strong>解释：</strong>
可以得到 6 个 "ab" 子序列的部分方案为 "<em><strong>a</strong></em>aabb" ，"aa<em><strong>a</strong></em>bb" 和 "aab<em><strong>b</strong></em>b" 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= text.length &lt;= 10<sup>5</sup></code></li>
	<li><code>pattern.length == 2</code></li>
	<li><code>text</code> 和&nbsp;<code>pattern</code>&nbsp;都只包含小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：遍历 + 计数

我们可以使用两个变量 $x$ 和 $y$ 分别记录当前字符串中 $\textit{pattern}[0]$ 和 $\textit{pattern}[1]$ 出现的次数。

然后遍历字符串 $\textit{text}$，对于当前遍历到的字符 $c$：

-   如果 $c$ 等于 $\textit{pattern}[1]$，我们将 $y$ 加一，此时之前出现过的所有 $\textit{pattern}[0]$ 都可以和当前的 $c$ 组成一个 $\textit{pattern}$ 子序列，因此答案加上 $x$；
-   如果 $c$ 等于 $\textit{pattern}[0]$，我们将 $x$ 加一。

遍历结束后，由于我们可以插入一个字符，因此，如果我们在字符串开头加上 $\textit{pattern}[0]$，那么可以得到 $y$ 个 $\textit{pattern}$ 子序列；如果我们在字符串结尾加上 $\textit{pattern}[1]$，那么可以得到 $x$ 个 $\textit{pattern}$ 子序列。因此，我们将答案加上 $x$ 和 $y$ 中的较大值即可。

时间复杂度 $O(n)$，其中 $n$ 为字符串 $\textit{text}$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumSubsequenceCount(self, text: str, pattern: str) -> int:
        ans = x = y = 0
        for c in text:
            if c == pattern[1]:
                y += 1
                ans += x
            if c == pattern[0]:
                x += 1
        ans += max(x, y)
        return ans
```

#### Java

```java
class Solution {
    public long maximumSubsequenceCount(String text, String pattern) {
        long ans = 0;
        int x = 0, y = 0;
        for (int i = 0; i < text.length(); ++i) {
            if (text.charAt(i) == pattern.charAt(1)) {
                ++y;
                ans += x;
            }
            if (text.charAt(i) == pattern.charAt(0)) {
                ++x;
            }
        }
        ans += Math.max(x, y);
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        long long ans = 0;
        int x = 0, y = 0;
        for (char& c : text) {
            if (c == pattern[1]) {
                ++y;
                ans += x;
            }
            if (c == pattern[0]) {
                ++x;
            }
        }
        ans += max(x, y);
        return ans;
    }
};
```

#### Go

```go
func maximumSubsequenceCount(text string, pattern string) (ans int64) {
	x, y := 0, 0
	for _, c := range text {
		if byte(c) == pattern[1] {
			y++
			ans += int64(x)
		}
		if byte(c) == pattern[0] {
			x++
		}
	}
	ans += int64(max(x, y))
	return
}
```

#### TypeScript

```ts
function maximumSubsequenceCount(text: string, pattern: string): number {
    let ans = 0;
    let [x, y] = [0, 0];
    for (const c of text) {
        if (c === pattern[1]) {
            ++y;
            ans += x;
        }
        if (c === pattern[0]) {
            ++x;
        }
    }
    ans += Math.max(x, y);
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2208. 将数组和减半的最少操作次数](https://leetcode.cn/problems/minimum-operations-to-halve-array-sum){#2208}

{{< tabs "2208" >}}

{{% tab "python" %}}
```python
class Solution:
    def halveArray(self, nums: List[int]) -> int:
        s = sum(nums) / 2
        pq = []
        for x in nums:
            heappush(pq, -x)
        ans = 0
        while s > 0:
            t = -heappop(pq) / 2
            s -= t
            heappush(pq, -t)
            ans += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int halveArray(int[] nums) {
        PriorityQueue<Double> pq = new PriorityQueue<>(Collections.reverseOrder());
        double s = 0;
        for (int x : nums) {
            s += x;
            pq.offer((double) x);
        }
        s /= 2.0;
        int ans = 0;
        while (s > 0) {
            double t = pq.poll() / 2.0;
            s -= t;
            pq.offer(t);
            ++ans;
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
    int halveArray(vector<int>& nums) {
        priority_queue<double> pq;
        double s = 0;
        for (int x : nums) {
            s += x;
            pq.push((double) x);
        }
        s /= 2.0;
        int ans = 0;
        while (s > 0) {
            double t = pq.top() / 2.0;
            pq.pop();
            s -= t;
            pq.push(t);
            ++ans;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func halveArray(nums []int) (ans int) {
	var s float64
	pq := &hp{}
	for _, x := range nums {
		s += float64(x)
		heap.Push(pq, float64(x))
	}
	s /= 2
	for s > 0 {
		t := heap.Pop(pq).(float64) / 2
		s -= t
		ans++
		heap.Push(pq, t)
	}
	return
}

type hp struct{ sort.Float64Slice }

func (h hp) Less(i, j int) bool { return h.Float64Slice[i] > h.Float64Slice[j] }
func (h *hp) Push(v any)        { h.Float64Slice = append(h.Float64Slice, v.(float64)) }
func (h *hp) Pop() any {
	a := h.Float64Slice
	v := a[len(a)-1]
	h.Float64Slice = a[:len(a)-1]
	return v
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function halveArray(nums: number[]): number {
    let s: number = nums.reduce((a, b) => a + b) / 2;
    const pq = new MaxPriorityQueue();
    for (const x of nums) {
        pq.enqueue(x, x);
    }
    let ans = 0;
    while (s > 0) {
        const t = pq.dequeue().element / 2;
        s -= t;
        ++ans;
        pq.enqueue(t, t);
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

<p>给你一个正整数数组&nbsp;<code>nums</code>&nbsp;。每一次操作中，你可以从&nbsp;<code>nums</code>&nbsp;中选择 <strong>任意</strong>&nbsp;一个数并将它减小到 <strong>恰好</strong>&nbsp;一半。（注意，在后续操作中你可以对减半过的数继续执行操作）</p>

<p>请你返回将 <code>nums</code>&nbsp;数组和 <strong>至少</strong>&nbsp;减少一半的 <strong>最少</strong>&nbsp;操作数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [5,19,8,1]
<b>输出：</b>3
<b>解释：</b>初始 nums 的和为 5 + 19 + 8 + 1 = 33 。
以下是将数组和减少至少一半的一种方法：
选择数字 19 并减小为 9.5 。
选择数字 9.5 并减小为 4.75 。
选择数字 8 并减小为 4 。
最终数组为 [5, 4.75, 4, 1] ，和为 5 + 4.75 + 4 + 1 = 14.75 。
nums 的和减小了 33 - 14.75 = 18.25 ，减小的部分超过了初始数组和的一半，18.25 &gt;= 33/2 = 16.5 。
我们需要 3 个操作实现题目要求，所以返回 3 。
可以证明，无法通过少于 3 个操作使数组和减少至少一半。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [3,8,20]
<b>输出：</b>3
<strong>解释：</strong>初始 nums 的和为 3 + 8 + 20 = 31 。
以下是将数组和减少至少一半的一种方法：
选择数字 20 并减小为 10 。
选择数字 10 并减小为 5 。
选择数字 3 并减小为 1.5 。
最终数组为 [1.5, 8, 5] ，和为 1.5 + 8 + 5 = 14.5 。
nums 的和减小了 31 - 14.5 = 16.5 ，减小的部分超过了初始数组和的一半， 16.5 &gt;= 31/2 = 15.5 。
我们需要 3 个操作实现题目要求，所以返回 3 。
可以证明，无法通过少于 3 个操作使数组和减少至少一半。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>7</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 优先队列（大根堆）

根据题目描述，每一次操作，都会将数组中的一个数减半。要使得数组和至少减少一半的操作次数最少，那么每一次操作都应该选择当前数组中的最大值进行减半。

因此，我们先算出数组要减少的总和 $s$，然后用一个优先队列（大根堆）维护数组中的所有数，每次从优先队列中取出最大值 $t$，将其减半，然后将减半后的数重新放入优先队列中，同时更新 $s$，直到 $s \le 0$ 为止。那么此时的操作次数就是答案。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 是数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def halveArray(self, nums: List[int]) -> int:
        s = sum(nums) / 2
        pq = []
        for x in nums:
            heappush(pq, -x)
        ans = 0
        while s > 0:
            t = -heappop(pq) / 2
            s -= t
            heappush(pq, -t)
            ans += 1
        return ans
```

#### Java

```java
class Solution {
    public int halveArray(int[] nums) {
        PriorityQueue<Double> pq = new PriorityQueue<>(Collections.reverseOrder());
        double s = 0;
        for (int x : nums) {
            s += x;
            pq.offer((double) x);
        }
        s /= 2.0;
        int ans = 0;
        while (s > 0) {
            double t = pq.poll() / 2.0;
            s -= t;
            pq.offer(t);
            ++ans;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> pq;
        double s = 0;
        for (int x : nums) {
            s += x;
            pq.push((double) x);
        }
        s /= 2.0;
        int ans = 0;
        while (s > 0) {
            double t = pq.top() / 2.0;
            pq.pop();
            s -= t;
            pq.push(t);
            ++ans;
        }
        return ans;
    }
};
```

#### Go

```go
func halveArray(nums []int) (ans int) {
	var s float64
	pq := &hp{}
	for _, x := range nums {
		s += float64(x)
		heap.Push(pq, float64(x))
	}
	s /= 2
	for s > 0 {
		t := heap.Pop(pq).(float64) / 2
		s -= t
		ans++
		heap.Push(pq, t)
	}
	return
}

type hp struct{ sort.Float64Slice }

func (h hp) Less(i, j int) bool { return h.Float64Slice[i] > h.Float64Slice[j] }
func (h *hp) Push(v any)        { h.Float64Slice = append(h.Float64Slice, v.(float64)) }
func (h *hp) Pop() any {
	a := h.Float64Slice
	v := a[len(a)-1]
	h.Float64Slice = a[:len(a)-1]
	return v
}
```

#### TypeScript

```ts
function halveArray(nums: number[]): number {
    let s: number = nums.reduce((a, b) => a + b) / 2;
    const pq = new MaxPriorityQueue();
    for (const x of nums) {
        pq.enqueue(x, x);
    }
    let ans = 0;
    while (s > 0) {
        const t = pq.dequeue().element / 2;
        s -= t;
        ++ans;
        pq.enqueue(t, t);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2209. 用地毯覆盖后的最少白色砖块](https://leetcode.cn/problems/minimum-white-tiles-after-covering-with-carpets){#2209}

{{< tabs "2209" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumWhiteTiles(self, floor: str, numCarpets: int, carpetLen: int) -> int:
        @cache
        def dfs(i: int, j: int) -> int:
            if i >= n:
                return 0
            if floor[i] == "0":
                return dfs(i + 1, j)
            if j == 0:
                return s[-1] - s[i]
            return min(1 + dfs(i + 1, j), dfs(i + carpetLen, j - 1))

        n = len(floor)
        s = [0] * (n + 1)
        for i, c in enumerate(floor):
            s[i + 1] = s[i] + int(c == "1")
        ans = dfs(0, numCarpets)
        dfs.cache_clear()
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private Integer[][] f;
    private int[] s;
    private int n;
    private int k;

    public int minimumWhiteTiles(String floor, int numCarpets, int carpetLen) {
        n = floor.length();
        f = new Integer[n][numCarpets + 1];
        s = new int[n + 1];
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + (floor.charAt(i) == '1' ? 1 : 0);
        }
        k = carpetLen;
        return dfs(0, numCarpets);
    }

    private int dfs(int i, int j) {
        if (i >= n) {
            return 0;
        }
        if (j == 0) {
            return s[n] - s[i];
        }
        if (f[i][j] != null) {
            return f[i][j];
        }
        if (s[i + 1] == s[i]) {
            return dfs(i + 1, j);
        }
        int ans = Math.min(1 + dfs(i + 1, j), dfs(i + k, j - 1));
        f[i][j] = ans;
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        int n = floor.size();
        vector<vector<int>> f(n, vector<int>(numCarpets + 1, -1));
        vector<int> s(n + 1);
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + (floor[i] == '1');
        }
        auto dfs = [&](this auto&& dfs, int i, int j) -> int {
            if (i >= n) {
                return 0;
            }
            if (j == 0) {
                return s[n] - s[i];
            }
            if (f[i][j] != -1) {
                return f[i][j];
            }
            if (s[i + 1] == s[i]) {
                return dfs(i + 1, j);
            }
            int ans = min(1 + dfs(i + 1, j), dfs(i + carpetLen, j - 1));
            f[i][j] = ans;
            return ans;
        };
        return dfs(0, numCarpets);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumWhiteTiles(floor string, numCarpets int, carpetLen int) int {
	n := len(floor)
	f := make([][]int, n)
	for i := range f {
		f[i] = make([]int, numCarpets+1)
		for j := range f[i] {
			f[i][j] = -1
		}
	}
	s := make([]int, n+1)
	for i, c := range floor {
		s[i+1] = s[i] + int(c-'0')
	}
	var dfs func(i, j int) int
	dfs = func(i, j int) int {
		if i >= n {
			return 0
		}
		if j == 0 {
			return s[n] - s[i]
		}
		if f[i][j] != -1 {
			return f[i][j]
		}
		if s[i+1] == s[i] {
			return dfs(i+1, j)
		}
		ans := min(1+dfs(i+1, j), dfs(i+carpetLen, j-1))
		f[i][j] = ans
		return ans
	}
	return dfs(0, numCarpets)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumWhiteTiles(floor: string, numCarpets: number, carpetLen: number): number {
    const n = floor.length;
    const f: number[][] = Array.from({ length: n }, () => Array(numCarpets + 1).fill(-1));
    const s: number[] = Array(n + 1).fill(0);
    for (let i = 0; i < n; ++i) {
        s[i + 1] = s[i] + (floor[i] === '1' ? 1 : 0);
    }
    const dfs = (i: number, j: number): number => {
        if (i >= n) {
            return 0;
        }
        if (j === 0) {
            return s[n] - s[i];
        }
        if (f[i][j] !== -1) {
            return f[i][j];
        }
        if (s[i + 1] === s[i]) {
            return dfs(i + 1, j);
        }
        const ans = Math.min(1 + dfs(i + 1, j), dfs(i + carpetLen, j - 1));
        f[i][j] = ans;
        return ans;
    };
    return dfs(0, numCarpets);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从<strong>&nbsp;0</strong>&nbsp;开始的 <strong>二进制</strong>&nbsp;字符串&nbsp;<code>floor</code>&nbsp;，它表示地板上砖块的颜色。</p>

<ul>
	<li><code>floor[i] = '0'</code>&nbsp;表示地板上第&nbsp;<code>i</code>&nbsp;块砖块的颜色是 <strong>黑色</strong>&nbsp;。</li>
	<li><code>floor[i] = '1'</code>&nbsp;表示地板上第&nbsp;<code>i</code>&nbsp;块砖块的颜色是 <strong>白色</strong>&nbsp;。</li>
</ul>

<p>同时给你&nbsp;<code>numCarpets</code> 和&nbsp;<code>carpetLen</code>&nbsp;。你有&nbsp;<code>numCarpets</code>&nbsp;条&nbsp;<strong>黑色</strong>&nbsp;的地毯，每一条&nbsp;<strong>黑色</strong>&nbsp;的地毯长度都为&nbsp;<code>carpetLen</code>&nbsp;块砖块。请你使用这些地毯去覆盖砖块，使得未被覆盖的剩余 <strong>白色</strong>&nbsp;砖块的数目 <strong>最小</strong>&nbsp;。地毯相互之间可以覆盖。</p>

<p>请你返回没被覆盖的白色砖块的 <strong>最少</strong>&nbsp;数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2200-2299/2209.Minimum%20White%20Tiles%20After%20Covering%20With%20Carpets/images/ex1-1.png" style="width: 400px; height: 73px;"></p>

<pre><b>输入：</b>floor = "10110101", numCarpets = 2, carpetLen = 2
<b>输出：</b>2
<b>解释：</b>
上图展示了剩余 2 块白色砖块的方案。
没有其他方案可以使未被覆盖的白色砖块少于 2 块。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2200-2299/2209.Minimum%20White%20Tiles%20After%20Covering%20With%20Carpets/images/ex2.png" style="width: 353px; height: 123px;"></p>

<pre><b>输入：</b>floor = "11111", numCarpets = 2, carpetLen = 3
<b>输出：</b>0
<b>解释：</b>
上图展示了所有白色砖块都被覆盖的一种方案。
注意，地毯相互之间可以覆盖。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= carpetLen &lt;= floor.length &lt;= 1000</code></li>
	<li><code>floor[i]</code> 要么是&nbsp;<code>'0'</code>&nbsp;，要么是&nbsp;<code>'1'</code>&nbsp;。</li>
	<li><code>1 &lt;= numCarpets &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

我们设计一个函数 $\textit{dfs}(i, j)$ 表示从下标 $i$ 开始，使用 $j$ 条地毯，最少有多少个白色砖块没有被覆盖。答案即为 $\textit{dfs}(0, \textit{numCarpets})$。

对于下标 $i$，我们分情况讨论：

-   如果 $i \ge n$，说明已经覆盖完所有砖块，返回 $0$；
-   如果 $\textit{floor}[i] = 0$，则不需要使用地毯，直接跳过即可，即 $\textit{dfs}(i, j) = \textit{dfs}(i + 1, j)$；
-   如果 $j = 0$，那么我们可以直接利用前缀和数组 $s$ 计算出剩余未被覆盖的白色砖块的数目，即 $\textit{dfs}(i, j) = s[n] - s[i]$；
-   如果 $\textit{floor}[i] = 1$，那么我们可以选择使用地毯覆盖，也可以选择不使用地毯覆盖，取两者的最小值即可，即 $\textit{dfs}(i, j) = \min(\textit{dfs}(i + 1,
    j), \textit{dfs}(i + \textit{carpetLen}, j - 1))$。

记忆化搜索即可。

时间复杂度 $O(n\times m)$，空间复杂度 $O(n\times m)$。其中 $n$ 和 $m$ 分别为字符串 $\textit{floor}$ 的长度和 $\textit{numCarpets}$ 的值。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumWhiteTiles(self, floor: str, numCarpets: int, carpetLen: int) -> int:
        @cache
        def dfs(i: int, j: int) -> int:
            if i >= n:
                return 0
            if floor[i] == "0":
                return dfs(i + 1, j)
            if j == 0:
                return s[-1] - s[i]
            return min(1 + dfs(i + 1, j), dfs(i + carpetLen, j - 1))

        n = len(floor)
        s = [0] * (n + 1)
        for i, c in enumerate(floor):
            s[i + 1] = s[i] + int(c == "1")
        ans = dfs(0, numCarpets)
        dfs.cache_clear()
        return ans
```

#### Java

```java
class Solution {
    private Integer[][] f;
    private int[] s;
    private int n;
    private int k;

    public int minimumWhiteTiles(String floor, int numCarpets, int carpetLen) {
        n = floor.length();
        f = new Integer[n][numCarpets + 1];
        s = new int[n + 1];
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + (floor.charAt(i) == '1' ? 1 : 0);
        }
        k = carpetLen;
        return dfs(0, numCarpets);
    }

    private int dfs(int i, int j) {
        if (i >= n) {
            return 0;
        }
        if (j == 0) {
            return s[n] - s[i];
        }
        if (f[i][j] != null) {
            return f[i][j];
        }
        if (s[i + 1] == s[i]) {
            return dfs(i + 1, j);
        }
        int ans = Math.min(1 + dfs(i + 1, j), dfs(i + k, j - 1));
        f[i][j] = ans;
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        int n = floor.size();
        vector<vector<int>> f(n, vector<int>(numCarpets + 1, -1));
        vector<int> s(n + 1);
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + (floor[i] == '1');
        }
        auto dfs = [&](this auto&& dfs, int i, int j) -> int {
            if (i >= n) {
                return 0;
            }
            if (j == 0) {
                return s[n] - s[i];
            }
            if (f[i][j] != -1) {
                return f[i][j];
            }
            if (s[i + 1] == s[i]) {
                return dfs(i + 1, j);
            }
            int ans = min(1 + dfs(i + 1, j), dfs(i + carpetLen, j - 1));
            f[i][j] = ans;
            return ans;
        };
        return dfs(0, numCarpets);
    }
};
```

#### Go

```go
func minimumWhiteTiles(floor string, numCarpets int, carpetLen int) int {
	n := len(floor)
	f := make([][]int, n)
	for i := range f {
		f[i] = make([]int, numCarpets+1)
		for j := range f[i] {
			f[i][j] = -1
		}
	}
	s := make([]int, n+1)
	for i, c := range floor {
		s[i+1] = s[i] + int(c-'0')
	}
	var dfs func(i, j int) int
	dfs = func(i, j int) int {
		if i >= n {
			return 0
		}
		if j == 0 {
			return s[n] - s[i]
		}
		if f[i][j] != -1 {
			return f[i][j]
		}
		if s[i+1] == s[i] {
			return dfs(i+1, j)
		}
		ans := min(1+dfs(i+1, j), dfs(i+carpetLen, j-1))
		f[i][j] = ans
		return ans
	}
	return dfs(0, numCarpets)
}
```

#### TypeScript

```ts
function minimumWhiteTiles(floor: string, numCarpets: number, carpetLen: number): number {
    const n = floor.length;
    const f: number[][] = Array.from({ length: n }, () => Array(numCarpets + 1).fill(-1));
    const s: number[] = Array(n + 1).fill(0);
    for (let i = 0; i < n; ++i) {
        s[i + 1] = s[i] + (floor[i] === '1' ? 1 : 0);
    }
    const dfs = (i: number, j: number): number => {
        if (i >= n) {
            return 0;
        }
        if (j === 0) {
            return s[n] - s[i];
        }
        if (f[i][j] !== -1) {
            return f[i][j];
        }
        if (s[i + 1] === s[i]) {
            return dfs(i + 1, j);
        }
        const ans = Math.min(1 + dfs(i + 1, j), dfs(i + carpetLen, j - 1));
        f[i][j] = ans;
        return ans;
    };
    return dfs(0, numCarpets);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
