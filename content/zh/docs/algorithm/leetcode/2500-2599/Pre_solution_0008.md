---
title: "2570_合并两个二维数组 - 求和法"
date: 2025-10-08T18:39:23+08:00
weight: 8
tags: [二分查找, 位运算, 前缀和, 动态规划, 双指针, 哈希表, 图, 堆（优先队列）, 字符串, 并查集, 广度优先搜索, 排序, 数学, 数组, 最短路, 状态压缩, 矩阵, 贪心]
---

{{< markmap >}}
### [2570_合并两个二维数组 - 求和法](#2570)
#### [数组](#2570)
#### [哈希表](#2570)
#### [双指针](#2570)
### [2571_将整数减少到零需要的最少操作数](#2571)
#### [贪心](#2571)
#### [位运算](#2571)
#### [动态规划](#2571)
### [2572_无平方子集计数](#2572)
#### [位运算](#2572)
#### [数组](#2572)
#### [数学](#2572)
#### [动态规划](#2572)
#### [状态压缩](#2572)
### [2573_找出对应 LCP 矩阵的字符串](#2573)
#### [贪心](#2573)
#### [并查集](#2573)
#### [数组](#2573)
#### [字符串](#2573)
#### [动态规划](#2573)
#### [矩阵](#2573)
### [2574_左右元素和的差值](#2574)
#### [数组](#2574)
#### [前缀和](#2574)
### [2575_找出字符串的可整除数组](#2575)
#### [数组](#2575)
#### [数学](#2575)
#### [字符串](#2575)
### [2576_求出最多标记下标](#2576)
#### [贪心](#2576)
#### [数组](#2576)
#### [双指针](#2576)
#### [二分查找](#2576)
#### [排序](#2576)
### [2577_在网格图中访问一个格子的最少时间](#2577)
#### [广度优先搜索](#2577)
#### [图](#2577)
#### [数组](#2577)
#### [矩阵](#2577)
#### [最短路](#2577)
#### [堆（优先队列）](#2577)
### [2578_最小和分割](#2578)
#### [贪心](#2578)
#### [数学](#2578)
#### [排序](#2578)
### [2579_统计染色格子数](#2579)
#### [数学](#2579)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2570_合并两个二维数组 - 求和法
___
#### 数组
___
#### 哈希表
___
#### 双指针
---
### 2571_将整数减少到零需要的最少操作数
___
#### 贪心
___
#### 位运算
___
#### 动态规划
---
### 2572_无平方子集计数
___
#### 位运算
___
#### 数组
___
#### 数学
___
#### 动态规划
___
#### 状态压缩
---
### 2573_找出对应 LCP 矩阵的字符串
___
#### 贪心
___
#### 并查集
___
#### 数组
___
#### 字符串
___
#### 动态规划
___
#### 矩阵
---
### 2574_左右元素和的差值
___
#### 数组
___
#### 前缀和
---
### 2575_找出字符串的可整除数组
___
#### 数组
___
#### 数学
___
#### 字符串
---
### 2576_求出最多标记下标
___
#### 贪心
___
#### 数组
___
#### 双指针
___
#### 二分查找
___
#### 排序
---
### 2577_在网格图中访问一个格子的最少时间
___
#### 广度优先搜索
___
#### 图
___
#### 数组
___
#### 矩阵
___
#### 最短路
___
#### 堆（优先队列）
---
### 2578_最小和分割
___
#### 贪心
___
#### 数学
___
#### 排序
---
### 2579_统计染色格子数
___
#### 数学
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 位运算 | 前缀和 |
| 动态规划 | 双指针 | 哈希表 |
| 图 | 堆（优先队列） | 字符串 |
| 并查集 | 广度优先搜索 | 排序 |
| 数学 | 数组 | 最短路 |
| 状态压缩 | 矩阵 | 贪心 |

# [2570. 合并两个二维数组 - 求和法](https://leetcode.cn/problems/merge-two-2d-arrays-by-summing-values){#2570}

{{< tabs "2570" >}}

{{% tab "python" %}}
```python
class Solution:
    def mergeArrays(
        self, nums1: List[List[int]], nums2: List[List[int]]
    ) -> List[List[int]]:
        cnt = Counter()
        for i, v in nums1 + nums2:
            cnt[i] += v
        return sorted(cnt.items())
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[][] mergeArrays(int[][] nums1, int[][] nums2) {
        int[] cnt = new int[1001];
        for (var x : nums1) {
            cnt[x[0]] += x[1];
        }
        for (var x : nums2) {
            cnt[x[0]] += x[1];
        }
        int n = 0;
        for (int i = 0; i < 1001; ++i) {
            if (cnt[i] > 0) {
                ++n;
            }
        }
        int[][] ans = new int[n][2];
        for (int i = 0, j = 0; i < 1001; ++i) {
            if (cnt[i] > 0) {
                ans[j++] = new int[] {i, cnt[i]};
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
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int cnt[1001]{};
        for (auto& x : nums1) {
            cnt[x[0]] += x[1];
        }
        for (auto& x : nums2) {
            cnt[x[0]] += x[1];
        }
        vector<vector<int>> ans;
        for (int i = 0; i < 1001; ++i) {
            if (cnt[i]) {
                ans.push_back({i, cnt[i]});
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func mergeArrays(nums1 [][]int, nums2 [][]int) (ans [][]int) {
	cnt := [1001]int{}
	for _, x := range nums1 {
		cnt[x[0]] += x[1]
	}
	for _, x := range nums2 {
		cnt[x[0]] += x[1]
	}
	for i, x := range cnt {
		if x > 0 {
			ans = append(ans, []int{i, x})
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function mergeArrays(nums1: number[][], nums2: number[][]): number[][] {
    const n = 1001;
    const cnt = new Array(n).fill(0);
    for (const [a, b] of nums1) {
        cnt[a] += b;
    }
    for (const [a, b] of nums2) {
        cnt[a] += b;
    }
    const ans: number[][] = [];
    for (let i = 0; i < n; ++i) {
        if (cnt[i] > 0) {
            ans.push([i, cnt[i]]);
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn merge_arrays(nums1: Vec<Vec<i32>>, nums2: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let mut cnt = vec![0; 1001];

        for x in &nums1 {
            cnt[x[0] as usize] += x[1];
        }

        for x in &nums2 {
            cnt[x[0] as usize] += x[1];
        }

        let mut ans = vec![];
        for i in 0..cnt.len() {
            if cnt[i] > 0 {
                ans.push(vec![i as i32, cnt[i] as i32]);
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

<p>给你两个 <strong>二维</strong> 整数数组 <code>nums1</code> 和 <code>nums2.</code></p>

<ul>
	<li><code>nums1[i] = [id<sub>i</sub>, val<sub>i</sub>]</code> 表示编号为 <code>id<sub>i</sub></code> 的数字对应的值等于 <code>val<sub>i</sub></code> 。</li>
	<li><code>nums2[i] = [id<sub>i</sub>, val<sub>i</sub>]</code>&nbsp;表示编号为 <code>id<sub>i</sub></code> 的数字对应的值等于 <code>val<sub>i</sub></code> 。</li>
</ul>

<p>每个数组都包含 <strong>互不相同</strong> 的 id ，并按 id 以 <strong>递增</strong> 顺序排列。</p>

<p>请你将两个数组合并为一个按 id 以递增顺序排列的数组，并符合下述条件：</p>

<ul>
	<li>只有在两个数组中至少出现过一次的 id 才能包含在结果数组内。</li>
	<li>每个 id 在结果数组中 <strong>只能出现一次</strong> ，并且其对应的值等于两个数组中该 id 所对应的值求和。如果某个数组中不存在该 id ，则假定其对应的值等于 <code>0</code> 。</li>
</ul>

<p>返回结果数组。返回的数组需要按 id 以递增顺序排列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums1 = [[1,2],[2,3],[4,5]], nums2 = [[1,4],[3,2],[4,1]]
<strong>输出：</strong>[[1,6],[2,3],[3,2],[4,6]]
<strong>解释：</strong>结果数组中包含以下元素：
- id = 1 ，对应的值等于 2 + 4 = 6 。
- id = 2 ，对应的值等于 3 。
- id = 3 ，对应的值等于 2 。
- id = 4 ，对应的值等于5 + 1 = 6 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums1 = [[2,4],[3,6],[5,5]], nums2 = [[1,3],[4,3]]
<strong>输出：</strong>[[1,3],[2,4],[3,6],[4,3],[5,5]]
<strong>解释：</strong>不存在共同 id ，在结果数组中只需要包含每个 id 和其对应的值。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums1.length, nums2.length &lt;= 200</code></li>
	<li><code>nums1[i].length == nums2[j].length == 2</code></li>
	<li><code>1 &lt;= id<sub>i</sub>, val<sub>i</sub> &lt;= 1000</code></li>
	<li>数组中的 id 互不相同</li>
	<li>数据均按 id 以严格递增顺序排列</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数 + 枚举

我们可以用一个哈希表或数组 `cnt` 统计两个数组中每个数字出现的次数。

然后我们从小到大枚举 `cnt` 中的每个数字，如果该数字出现的次数大于 $0$，则将其加入答案数组中。

时间复杂度 $O(n + m)$，空间复杂度 $O(M)$。其中 $n$ 和 $m$ 分别是两个数组的长度；而 $M$ 是两个数组中数字的最大值，本题中 $M = 1000$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def mergeArrays(
        self, nums1: List[List[int]], nums2: List[List[int]]
    ) -> List[List[int]]:
        cnt = Counter()
        for i, v in nums1 + nums2:
            cnt[i] += v
        return sorted(cnt.items())
```

#### Java

```java
class Solution {
    public int[][] mergeArrays(int[][] nums1, int[][] nums2) {
        int[] cnt = new int[1001];
        for (var x : nums1) {
            cnt[x[0]] += x[1];
        }
        for (var x : nums2) {
            cnt[x[0]] += x[1];
        }
        int n = 0;
        for (int i = 0; i < 1001; ++i) {
            if (cnt[i] > 0) {
                ++n;
            }
        }
        int[][] ans = new int[n][2];
        for (int i = 0, j = 0; i < 1001; ++i) {
            if (cnt[i] > 0) {
                ans[j++] = new int[] {i, cnt[i]};
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
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int cnt[1001]{};
        for (auto& x : nums1) {
            cnt[x[0]] += x[1];
        }
        for (auto& x : nums2) {
            cnt[x[0]] += x[1];
        }
        vector<vector<int>> ans;
        for (int i = 0; i < 1001; ++i) {
            if (cnt[i]) {
                ans.push_back({i, cnt[i]});
            }
        }
        return ans;
    }
};
```

#### Go

```go
func mergeArrays(nums1 [][]int, nums2 [][]int) (ans [][]int) {
	cnt := [1001]int{}
	for _, x := range nums1 {
		cnt[x[0]] += x[1]
	}
	for _, x := range nums2 {
		cnt[x[0]] += x[1]
	}
	for i, x := range cnt {
		if x > 0 {
			ans = append(ans, []int{i, x})
		}
	}
	return
}
```

#### TypeScript

```ts
function mergeArrays(nums1: number[][], nums2: number[][]): number[][] {
    const n = 1001;
    const cnt = new Array(n).fill(0);
    for (const [a, b] of nums1) {
        cnt[a] += b;
    }
    for (const [a, b] of nums2) {
        cnt[a] += b;
    }
    const ans: number[][] = [];
    for (let i = 0; i < n; ++i) {
        if (cnt[i] > 0) {
            ans.push([i, cnt[i]]);
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn merge_arrays(nums1: Vec<Vec<i32>>, nums2: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let mut cnt = vec![0; 1001];

        for x in &nums1 {
            cnt[x[0] as usize] += x[1];
        }

        for x in &nums2 {
            cnt[x[0] as usize] += x[1];
        }

        let mut ans = vec![];
        for i in 0..cnt.len() {
            if cnt[i] > 0 {
                ans.push(vec![i as i32, cnt[i] as i32]);
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

# [2571. 将整数减少到零需要的最少操作数](https://leetcode.cn/problems/minimum-operations-to-reduce-an-integer-to-0){#2571}

{{< tabs "2571" >}}

{{% tab "python" %}}
```python
class Solution:
    def minOperations(self, n: int) -> int:
        ans = cnt = 0
        while n:
            if n & 1:
                cnt += 1
            elif cnt:
                ans += 1
                cnt = 0 if cnt == 1 else 1
            n >>= 1
        if cnt == 1:
            ans += 1
        elif cnt > 1:
            ans += 2
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minOperations(int n) {
        int ans = 0, cnt = 0;
        for (; n > 0; n >>= 1) {
            if ((n & 1) == 1) {
                ++cnt;
            } else if (cnt > 0) {
                ++ans;
                cnt = cnt == 1 ? 0 : 1;
            }
        }
        ans += cnt == 1 ? 1 : 0;
        ans += cnt > 1 ? 2 : 0;
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minOperations(int n) {
        int ans = 0, cnt = 0;
        for (; n > 0; n >>= 1) {
            if ((n & 1) == 1) {
                ++cnt;
            } else if (cnt > 0) {
                ++ans;
                cnt = cnt == 1 ? 0 : 1;
            }
        }
        ans += cnt == 1 ? 1 : 0;
        ans += cnt > 1 ? 2 : 0;
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minOperations(n int) (ans int) {
	cnt := 0
	for ; n > 0; n >>= 1 {
		if n&1 == 1 {
			cnt++
		} else if cnt > 0 {
			ans++
			if cnt == 1 {
				cnt = 0
			} else {
				cnt = 1
			}
		}
	}
	if cnt == 1 {
		ans++
	} else if cnt > 1 {
		ans += 2
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minOperations(n: number): number {
    let [ans, cnt] = [0, 0];
    for (; n; n >>= 1) {
        if (n & 1) {
            ++cnt;
        } else if (cnt) {
            ++ans;
            cnt = cnt === 1 ? 0 : 1;
        }
    }
    if (cnt === 1) {
        ++ans;
    } else if (cnt > 1) {
        ans += 2;
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

<p>给你一个正整数 <code>n</code> ，你可以执行下述操作 <strong>任意</strong> 次：</p>

<ul>
	<li><code>n</code> 加上或减去 <code>2</code> 的某个 <strong>幂</strong></li>
</ul>

<p>返回使 <code>n</code> 等于 <code>0</code> 需要执行的 <strong>最少</strong> 操作数。</p>

<p>如果 <code>x == 2<sup>i</sup></code> 且其中 <code>i &gt;= 0</code> ，则数字 <code>x</code> 是 <code>2</code> 的幂。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 39
<strong>输出：</strong>3
<strong>解释：</strong>我们可以执行下述操作：
- n 加上 2<sup>0</sup> = 1 ，得到 n = 40 。
- n 减去 2<sup>3</sup> = 8 ，得到 n = 32 。
- n 减去 2<sup>5</sup> = 32 ，得到 n = 0 。
可以证明使 n 等于 0 需要执行的最少操作数是 3 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 54
<strong>输出：</strong>3
<strong>解释：</strong>我们可以执行下述操作：
- n 加上 2<sup>1</sup> = 2 ，得到 n = 56 。
- n 加上 2<sup>3</sup> = 8 ，得到 n = 64 。
- n 减去 2<sup>6</sup> = 64 ，得到 n = 0 。
使 n 等于 0 需要执行的最少操作数是 3 。 
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 位运算

我们将整数 $n$ 转换为二进制，从最低位开始：

-   如果当前位为 $1$，我们就累加当前连续的 $1$ 的个数；
-   如果当前位为 $0$，我们就判断当前连续的 $1$ 的个数是否超过 $0$。如果是，判断当前连续的 $1$ 的个数是否为 $1$，如果是，说明我们通过一次操作可以消除 $1$；如果大于 $1$，说明我们通过一次操作，可以把连续的 $1$ 的个数减少到 $1$。

最后，我们还需要判断当前连续的 $1$ 的个数是否为 $1$，如果是，说明我们通过一次操作可以消除 $1$；如果大于 $1$，我们通过两次操作，可以把连续的 $1$ 的消除。

时间复杂度 $O(\log n)$，空间复杂度 $O(1)$。其中 $n$ 为题目给定的整数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minOperations(self, n: int) -> int:
        ans = cnt = 0
        while n:
            if n & 1:
                cnt += 1
            elif cnt:
                ans += 1
                cnt = 0 if cnt == 1 else 1
            n >>= 1
        if cnt == 1:
            ans += 1
        elif cnt > 1:
            ans += 2
        return ans
```

#### Java

```java
class Solution {
    public int minOperations(int n) {
        int ans = 0, cnt = 0;
        for (; n > 0; n >>= 1) {
            if ((n & 1) == 1) {
                ++cnt;
            } else if (cnt > 0) {
                ++ans;
                cnt = cnt == 1 ? 0 : 1;
            }
        }
        ans += cnt == 1 ? 1 : 0;
        ans += cnt > 1 ? 2 : 0;
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minOperations(int n) {
        int ans = 0, cnt = 0;
        for (; n > 0; n >>= 1) {
            if ((n & 1) == 1) {
                ++cnt;
            } else if (cnt > 0) {
                ++ans;
                cnt = cnt == 1 ? 0 : 1;
            }
        }
        ans += cnt == 1 ? 1 : 0;
        ans += cnt > 1 ? 2 : 0;
        return ans;
    }
};
```

#### Go

```go
func minOperations(n int) (ans int) {
	cnt := 0
	for ; n > 0; n >>= 1 {
		if n&1 == 1 {
			cnt++
		} else if cnt > 0 {
			ans++
			if cnt == 1 {
				cnt = 0
			} else {
				cnt = 1
			}
		}
	}
	if cnt == 1 {
		ans++
	} else if cnt > 1 {
		ans += 2
	}
	return
}
```

#### TypeScript

```ts
function minOperations(n: number): number {
    let [ans, cnt] = [0, 0];
    for (; n; n >>= 1) {
        if (n & 1) {
            ++cnt;
        } else if (cnt) {
            ++ans;
            cnt = cnt === 1 ? 0 : 1;
        }
    }
    if (cnt === 1) {
        ++ans;
    } else if (cnt > 1) {
        ans += 2;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2572. 无平方子集计数](https://leetcode.cn/problems/count-the-number-of-square-free-subsets){#2572}

{{< tabs "2572" >}}

{{% tab "python" %}}
```python
class Solution:
    def squareFreeSubsets(self, nums: List[int]) -> int:
        primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29]
        cnt = Counter(nums)
        mod = 10**9 + 7
        n = len(primes)
        f = [0] * (1 << n)
        f[0] = pow(2, cnt[1])
        for x in range(2, 31):
            if cnt[x] == 0 or x % 4 == 0 or x % 9 == 0 or x % 25 == 0:
                continue
            mask = 0
            for i, p in enumerate(primes):
                if x % p == 0:
                    mask |= 1 << i
            for state in range((1 << n) - 1, 0, -1):
                if state & mask == mask:
                    f[state] = (f[state] + cnt[x] * f[state ^ mask]) % mod
        return sum(v for v in f) % mod - 1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int squareFreeSubsets(int[] nums) {
        int[] primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        int[] cnt = new int[31];
        for (int x : nums) {
            ++cnt[x];
        }
        final int mod = (int) 1e9 + 7;
        int n = primes.length;
        long[] f = new long[1 << n];
        f[0] = 1;
        for (int i = 0; i < cnt[1]; ++i) {
            f[0] = (f[0] * 2) % mod;
        }
        for (int x = 2; x < 31; ++x) {
            if (cnt[x] == 0 || x % 4 == 0 || x % 9 == 0 || x % 25 == 0) {
                continue;
            }
            int mask = 0;
            for (int i = 0; i < n; ++i) {
                if (x % primes[i] == 0) {
                    mask |= 1 << i;
                }
            }
            for (int state = (1 << n) - 1; state > 0; --state) {
                if ((state & mask) == mask) {
                    f[state] = (f[state] + cnt[x] * f[state ^ mask]) % mod;
                }
            }
        }
        long ans = 0;
        for (int i = 0; i < 1 << n; ++i) {
            ans = (ans + f[i]) % mod;
        }
        ans -= 1;
        return (int) ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int squareFreeSubsets(vector<int>& nums) {
        int primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        int cnt[31]{};
        for (int& x : nums) {
            ++cnt[x];
        }
        int n = 10;
        const int mod = 1e9 + 7;
        vector<long long> f(1 << n);
        f[0] = 1;
        for (int i = 0; i < cnt[1]; ++i) {
            f[0] = f[0] * 2 % mod;
        }
        for (int x = 2; x < 31; ++x) {
            if (cnt[x] == 0 || x % 4 == 0 || x % 9 == 0 || x % 25 == 0) {
                continue;
            }
            int mask = 0;
            for (int i = 0; i < n; ++i) {
                if (x % primes[i] == 0) {
                    mask |= 1 << i;
                }
            }
            for (int state = (1 << n) - 1; state; --state) {
                if ((state & mask) == mask) {
                    f[state] = (f[state] + 1LL * cnt[x] * f[state ^ mask]) % mod;
                }
            }
        }
        long long ans = -1;
        for (int i = 0; i < 1 << n; ++i) {
            ans = (ans + f[i]) % mod;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func squareFreeSubsets(nums []int) (ans int) {
	primes := []int{2, 3, 5, 7, 11, 13, 17, 19, 23, 29}
	cnt := [31]int{}
	for _, x := range nums {
		cnt[x]++
	}
	const mod int = 1e9 + 7
	n := 10
	f := make([]int, 1<<n)
	f[0] = 1
	for i := 0; i < cnt[1]; i++ {
		f[0] = f[0] * 2 % mod
	}
	for x := 2; x < 31; x++ {
		if cnt[x] == 0 || x%4 == 0 || x%9 == 0 || x%25 == 0 {
			continue
		}
		mask := 0
		for i, p := range primes {
			if x%p == 0 {
				mask |= 1 << i
			}
		}
		for state := 1<<n - 1; state > 0; state-- {
			if state&mask == mask {
				f[state] = (f[state] + f[state^mask]*cnt[x]) % mod
			}
		}
	}
	ans = -1
	for _, v := range f {
		ans = (ans + v) % mod
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function squareFreeSubsets(nums: number[]): number {
    const primes: number[] = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29];
    const cnt: number[] = Array(31).fill(0);
    for (const x of nums) {
        ++cnt[x];
    }
    const mod: number = Math.pow(10, 9) + 7;
    const n: number = primes.length;
    const f: number[] = Array(1 << n).fill(0);
    f[0] = 1;
    for (let i = 0; i < cnt[1]; ++i) {
        f[0] = (f[0] * 2) % mod;
    }
    for (let x = 2; x < 31; ++x) {
        if (cnt[x] === 0 || x % 4 === 0 || x % 9 === 0 || x % 25 === 0) {
            continue;
        }
        let mask: number = 0;
        for (let i = 0; i < n; ++i) {
            if (x % primes[i] === 0) {
                mask |= 1 << i;
            }
        }
        for (let state = (1 << n) - 1; state > 0; --state) {
            if ((state & mask) === mask) {
                f[state] = (f[state] + cnt[x] * f[state ^ mask]) % mod;
            }
        }
    }
    let ans: number = 0;
    for (let i = 0; i < 1 << n; ++i) {
        ans = (ans + f[i]) % mod;
    }
    ans -= 1;
    return ans >= 0 ? ans : ans + mod;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个正整数数组 <code>nums</code> 。</p>

<p>如果数组 <code>nums</code> 的子集中的元素乘积是一个 <strong>无平方因子数</strong> ，则认为该子集是一个 <strong>无平方</strong> 子集。</p>

<p><strong>无平方因子数</strong> 是无法被除 <code>1</code> 之外任何平方数整除的数字。</p>

<p>返回数组 <code>nums</code> 中 <strong>无平方</strong> 且 <strong>非空</strong> 的子集数目。因为答案可能很大，返回对 <code>10<sup>9</sup> + 7</code> 取余的结果。</p>

<p><code>nums</code> 的 <strong>非空子集</strong> 是可以由删除 <code>nums</code> 中一些元素（可以不删除，但不能全部删除）得到的一个数组。如果构成两个子集时选择删除的下标不同，则认为这两个子集不同。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [3,4,4,5]
<strong>输出：</strong>3
<strong>解释：</strong>示例中有 3 个无平方子集：
- 由第 0 个元素 [3] 组成的子集。其元素的乘积是 3 ，这是一个无平方因子数。
- 由第 3 个元素 [5] 组成的子集。其元素的乘积是 5 ，这是一个无平方因子数。
- 由第 0 个和第 3 个元素 [3,5] 组成的子集。其元素的乘积是 15 ，这是一个无平方因子数。
可以证明给定数组中不存在超过 3 个无平方子集。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1]
<strong>输出：</strong>1
<strong>解释：</strong>示例中有 1 个无平方子集：
- 由第 0 个元素 [1] 组成的子集。其元素的乘积是 1 ，这是一个无平方因子数。
可以证明给定数组中不存在超过 1 个无平方子集。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length&nbsp;&lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 30</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：状态压缩动态规划

注意到题目中 $nums[i]$ 的范围为 $[1, 30]$，因此我们可以预处理出所有小于等于 $30$ 的质数，即 $[2, 3, 5, 7, 11, 13, 17, 19, 23, 29]$。

无平方子集中，所有元素的乘积可以表示为一个或多个互不相同的质数的乘积，也即是说，每个质因数最多只能出现一次。因此，我们可以使用一个二进制数来表示一个子集中的质因数，其中二进制数的第 $i$ 位表示质数 $primes[i]$ 是否出现在子集中。

我们可以使用状态压缩动态规划的方法来求解本题。设 $f[i]$ 表示二进制数 $i$ 表示的子集中的质因数的乘积为一个或多个互不相同的质数的乘积的方案数。初始时 $f[0]=1$。

我们在 $[2,..30]$ 的范围内枚举一个数 $x$，如果 $x$ 不在 $nums$ 中，或者 $x$ 为 $4, 9, 25$ 的倍数，那么我们可以直接跳过。否则，我们可以将 $x$ 的质因数用一个二进制数 $mask$ 表示，然后我们从大到小枚举当前的状态 $state$，如果 $state$ 与 $mask$ 按位与的结果为 $mask$，那么我们可以从状态 $f[state \oplus mask]$ 转移到状态 $f[state]$，转移方程为 $f[state] = f[state] + cnt[x] \times f[state \oplus mask]$，其中 $cnt[x]$ 表示 $x$ 在 $nums$ 中出现的次数。

注意，我们没有从数字 $1$ 开始枚举，因为我们可以选择任意个数字 $1$，加入到无平方子集中。也可以只选择任意个数字 $1$，不加入到无平方子集中，这两种情况都是合法的。那么答案就是 $(\sum_{i=0}^{2^{10}-1} f[i]) - 1$。

时间复杂度 $O(n + C \times M)$，空间复杂度 $O(M)$。其中 $n$ 为 $nums$ 的长度；而 $C$ 和 $M$ 分别为题目中 $nums[i]$ 的范围和状态的个数，本题中 $C=30$, $M=2^{10}$。

相似题目：

-   [1994. 好子集的数目](https://github.com/doocs/leetcode/blob/main/solution/1900-1999/1994.The%20Number%20of%20Good%20Subsets/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def squareFreeSubsets(self, nums: List[int]) -> int:
        primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29]
        cnt = Counter(nums)
        mod = 10**9 + 7
        n = len(primes)
        f = [0] * (1 << n)
        f[0] = pow(2, cnt[1])
        for x in range(2, 31):
            if cnt[x] == 0 or x % 4 == 0 or x % 9 == 0 or x % 25 == 0:
                continue
            mask = 0
            for i, p in enumerate(primes):
                if x % p == 0:
                    mask |= 1 << i
            for state in range((1 << n) - 1, 0, -1):
                if state & mask == mask:
                    f[state] = (f[state] + cnt[x] * f[state ^ mask]) % mod
        return sum(v for v in f) % mod - 1
```

#### Java

```java
class Solution {
    public int squareFreeSubsets(int[] nums) {
        int[] primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        int[] cnt = new int[31];
        for (int x : nums) {
            ++cnt[x];
        }
        final int mod = (int) 1e9 + 7;
        int n = primes.length;
        long[] f = new long[1 << n];
        f[0] = 1;
        for (int i = 0; i < cnt[1]; ++i) {
            f[0] = (f[0] * 2) % mod;
        }
        for (int x = 2; x < 31; ++x) {
            if (cnt[x] == 0 || x % 4 == 0 || x % 9 == 0 || x % 25 == 0) {
                continue;
            }
            int mask = 0;
            for (int i = 0; i < n; ++i) {
                if (x % primes[i] == 0) {
                    mask |= 1 << i;
                }
            }
            for (int state = (1 << n) - 1; state > 0; --state) {
                if ((state & mask) == mask) {
                    f[state] = (f[state] + cnt[x] * f[state ^ mask]) % mod;
                }
            }
        }
        long ans = 0;
        for (int i = 0; i < 1 << n; ++i) {
            ans = (ans + f[i]) % mod;
        }
        ans -= 1;
        return (int) ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int squareFreeSubsets(vector<int>& nums) {
        int primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        int cnt[31]{};
        for (int& x : nums) {
            ++cnt[x];
        }
        int n = 10;
        const int mod = 1e9 + 7;
        vector<long long> f(1 << n);
        f[0] = 1;
        for (int i = 0; i < cnt[1]; ++i) {
            f[0] = f[0] * 2 % mod;
        }
        for (int x = 2; x < 31; ++x) {
            if (cnt[x] == 0 || x % 4 == 0 || x % 9 == 0 || x % 25 == 0) {
                continue;
            }
            int mask = 0;
            for (int i = 0; i < n; ++i) {
                if (x % primes[i] == 0) {
                    mask |= 1 << i;
                }
            }
            for (int state = (1 << n) - 1; state; --state) {
                if ((state & mask) == mask) {
                    f[state] = (f[state] + 1LL * cnt[x] * f[state ^ mask]) % mod;
                }
            }
        }
        long long ans = -1;
        for (int i = 0; i < 1 << n; ++i) {
            ans = (ans + f[i]) % mod;
        }
        return ans;
    }
};
```

#### Go

```go
func squareFreeSubsets(nums []int) (ans int) {
	primes := []int{2, 3, 5, 7, 11, 13, 17, 19, 23, 29}
	cnt := [31]int{}
	for _, x := range nums {
		cnt[x]++
	}
	const mod int = 1e9 + 7
	n := 10
	f := make([]int, 1<<n)
	f[0] = 1
	for i := 0; i < cnt[1]; i++ {
		f[0] = f[0] * 2 % mod
	}
	for x := 2; x < 31; x++ {
		if cnt[x] == 0 || x%4 == 0 || x%9 == 0 || x%25 == 0 {
			continue
		}
		mask := 0
		for i, p := range primes {
			if x%p == 0 {
				mask |= 1 << i
			}
		}
		for state := 1<<n - 1; state > 0; state-- {
			if state&mask == mask {
				f[state] = (f[state] + f[state^mask]*cnt[x]) % mod
			}
		}
	}
	ans = -1
	for _, v := range f {
		ans = (ans + v) % mod
	}
	return
}
```

#### TypeScript

```ts
function squareFreeSubsets(nums: number[]): number {
    const primes: number[] = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29];
    const cnt: number[] = Array(31).fill(0);
    for (const x of nums) {
        ++cnt[x];
    }
    const mod: number = Math.pow(10, 9) + 7;
    const n: number = primes.length;
    const f: number[] = Array(1 << n).fill(0);
    f[0] = 1;
    for (let i = 0; i < cnt[1]; ++i) {
        f[0] = (f[0] * 2) % mod;
    }
    for (let x = 2; x < 31; ++x) {
        if (cnt[x] === 0 || x % 4 === 0 || x % 9 === 0 || x % 25 === 0) {
            continue;
        }
        let mask: number = 0;
        for (let i = 0; i < n; ++i) {
            if (x % primes[i] === 0) {
                mask |= 1 << i;
            }
        }
        for (let state = (1 << n) - 1; state > 0; --state) {
            if ((state & mask) === mask) {
                f[state] = (f[state] + cnt[x] * f[state ^ mask]) % mod;
            }
        }
    }
    let ans: number = 0;
    for (let i = 0; i < 1 << n; ++i) {
        ans = (ans + f[i]) % mod;
    }
    ans -= 1;
    return ans >= 0 ? ans : ans + mod;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2573. 找出对应 LCP 矩阵的字符串](https://leetcode.cn/problems/find-the-string-with-lcp){#2573}

{{< tabs "2573" >}}

{{% tab "python" %}}
```python
class Solution:
    def findTheString(self, lcp: List[List[int]]) -> str:
        n = len(lcp)
        s = [""] * n
        i = 0
        for c in ascii_lowercase:
            while i < n and s[i]:
                i += 1
            if i == n:
                break
            for j in range(i, n):
                if lcp[i][j]:
                    s[j] = c
        if "" in s:
            return ""
        for i in range(n - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                if s[i] == s[j]:
                    if i == n - 1 or j == n - 1:
                        if lcp[i][j] != 1:
                            return ""
                    elif lcp[i][j] != lcp[i + 1][j + 1] + 1:
                        return ""
                elif lcp[i][j]:
                    return ""
        return "".join(s)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String findTheString(int[][] lcp) {
        int n = lcp.length;
        char[] s = new char[n];
        int i = 0;
        for (char c = 'a'; c <= 'z'; ++c) {
            while (i < n && s[i] != '\0') {
                ++i;
            }
            if (i == n) {
                break;
            }
            for (int j = i; j < n; ++j) {
                if (lcp[i][j] > 0) {
                    s[j] = c;
                }
            }
        }
        for (i = 0; i < n; ++i) {
            if (s[i] == '\0') {
                return "";
            }
        }
        for (i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (s[i] == s[j]) {
                    if (i == n - 1 || j == n - 1) {
                        if (lcp[i][j] != 1) {
                            return "";
                        }
                    } else if (lcp[i][j] != lcp[i + 1][j + 1] + 1) {
                        return "";
                    }
                } else if (lcp[i][j] > 0) {
                    return "";
                }
            }
        }
        return String.valueOf(s);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int i = 0, n = lcp.size();
        string s(n, '\0');
        for (char c = 'a'; c <= 'z'; ++c) {
            while (i < n && s[i]) {
                ++i;
            }
            if (i == n) {
                break;
            }
            for (int j = i; j < n; ++j) {
                if (lcp[i][j]) {
                    s[j] = c;
                }
            }
        }
        if (s.find('\0') != -1) {
            return "";
        }
        for (i = n - 1; ~i; --i) {
            for (int j = n - 1; ~j; --j) {
                if (s[i] == s[j]) {
                    if (i == n - 1 || j == n - 1) {
                        if (lcp[i][j] != 1) {
                            return "";
                        }
                    } else if (lcp[i][j] != lcp[i + 1][j + 1] + 1) {
                        return "";
                    }
                } else if (lcp[i][j]) {
                    return "";
                }
            }
        }
        return s;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findTheString(lcp [][]int) string {
	i, n := 0, len(lcp)
	s := make([]byte, n)
	for c := 'a'; c <= 'z'; c++ {
		for i < n && s[i] != 0 {
			i++
		}
		if i == n {
			break
		}
		for j := i; j < n; j++ {
			if lcp[i][j] > 0 {
				s[j] = byte(c)
			}
		}
	}
	if bytes.IndexByte(s, 0) >= 0 {
		return ""
	}
	for i := n - 1; i >= 0; i-- {
		for j := n - 1; j >= 0; j-- {
			if s[i] == s[j] {
				if i == n-1 || j == n-1 {
					if lcp[i][j] != 1 {
						return ""
					}
				} else if lcp[i][j] != lcp[i+1][j+1]+1 {
					return ""
				}
			} else if lcp[i][j] > 0 {
				return ""
			}
		}
	}
	return string(s)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findTheString(lcp: number[][]): string {
    let i: number = 0;
    const n: number = lcp.length;
    let s: string = '\0'.repeat(n);
    for (let ascii = 97; ascii < 123; ++ascii) {
        const c: string = String.fromCharCode(ascii);
        while (i < n && s[i] !== '\0') {
            ++i;
        }
        if (i === n) {
            break;
        }
        for (let j = i; j < n; ++j) {
            if (lcp[i][j]) {
                s = s.substring(0, j) + c + s.substring(j + 1);
            }
        }
    }
    if (s.indexOf('\0') !== -1) {
        return '';
    }
    for (i = n - 1; ~i; --i) {
        for (let j = n - 1; ~j; --j) {
            if (s[i] === s[j]) {
                if (i === n - 1 || j === n - 1) {
                    if (lcp[i][j] !== 1) {
                        return '';
                    }
                } else if (lcp[i][j] !== lcp[i + 1][j + 1] + 1) {
                    return '';
                }
            } else if (lcp[i][j]) {
                return '';
            }
        }
    }
    return s;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>对任一由 <code>n</code> 个小写英文字母组成的字符串 <code>word</code> ，我们可以定义一个 <code>n x n</code> 的矩阵，并满足：</p>

<ul>
	<li><code>lcp[i][j]</code> 等于子字符串&nbsp;<code>word[i,...,n-1]</code> 和 <code>word[j,...,n-1]</code> 之间的最长公共前缀的长度。</li>
</ul>

<p>给你一个 <code>n x n</code> 的矩阵 <code>lcp</code> 。返回与 <code>lcp</code> 对应的、按字典序最小的字符串&nbsp;<code>word</code> 。如果不存在这样的字符串，则返回空字符串。</p>

<p>对于长度相同的两个字符串 <code>a</code> 和 <code>b</code> ，如果在 <code>a</code> 和 <code>b</code> 不同的第一个位置，字符串 <code>a</code> 的字母在字母表中出现的顺序先于 <code>b</code> 中的对应字母，则认为字符串 <code>a</code> 按字典序比字符串 <code>b</code> 小。例如，<code>"aabd"</code> 在字典上小于 <code>"aaca"</code> ，因为二者不同的第一位置是第三个字母，而&nbsp;<code>'b'</code> 先于 <code>'c'</code> 出现。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>lcp = [[4,0,2,0],[0,3,0,1],[2,0,2,0],[0,1,0,1]]
<strong>输出：</strong>"abab"
<strong>解释：</strong>lcp 对应由两个交替字母组成的任意 4 字母字符串，字典序最小的是 "abab" 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>lcp = [[4,3,2,1],[3,3,2,1],[2,2,2,1],[1,1,1,1]]
<strong>输出：</strong>"aaaa"
<strong>解释：</strong>lcp 对应只有一个不同字母的任意 4 字母字符串，字典序最小的是 "aaaa" 。 
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>lcp = [[4,3,2,1],[3,3,2,1],[2,2,2,1],[1,1,1,3]]
<strong>输出：</strong>""
<strong>解释：</strong>lcp[3][3] 无法等于 3 ，因为 word[3,...,3] 仅由单个字母组成；因此，不存在答案。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n ==&nbsp;</code><code>lcp.length == </code><code>lcp[i].length</code>&nbsp;<code>&lt;= 1000</code></li>
	<li><code><font face="monospace">0 &lt;= lcp[i][j] &lt;= n</font></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 构造

由于构造的字符串要求字典序最小，因此我们可以从字符 `'a'` 开始，填充到字符串 $s$ 中。

如果当前位置 $i$ 还未填充字符，那么我们可以将字符 `'a'` 填充到 $i$ 位置，然后枚举所有 $j \gt i$ 的位置，如果 $lcp[i][j] \gt 0$，那么位置 $j$ 也应该填充字符 `'a'`。然后我们将字符 `'a'` 的 ASCII 码加一，继续填充剩余未填充的位置。

填充结束后，如果字符串中存在未填充的位置，说明无法构造出对应的字符串，返回空字符串。

接下来，我们可以从大到小枚举字符串中的每个位置 $i$ 和 $j$，然后判断 $s[i]$ 和 $s[j]$ 是否相等：

-   如果 $s[i] = s[j]$，此时我们需要判断 $i$ 和 $j$ 是否为字符串的最后一个位置，如果是，那么 $lcp[i][j]$ 应该等于 $1$，否则 $lcp[i][j]$ 应该等于 $0$。如果不满足上述条件，说明无法构造出对应的字符串，返回空字符串。如果 $i$ 和 $j$ 不是字符串的最后一个位置，那么 $lcp[i][j]$ 应该等于 $lcp[i + 1][j + 1] + 1$，否则说明无法构造出对应的字符串，返回空字符串。
-   否则，如果 $lcp[i][j] \gt 0$，说明无法构造出对应的字符串，返回空字符串。

如果字符串中的每个位置都满足上述条件，那么我们就可以构造出对应的字符串，返回即可。

时间复杂度为 $O(n^2)$，空间复杂度为 $O(n)$。其中 $n$ 为字符串的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findTheString(self, lcp: List[List[int]]) -> str:
        n = len(lcp)
        s = [""] * n
        i = 0
        for c in ascii_lowercase:
            while i < n and s[i]:
                i += 1
            if i == n:
                break
            for j in range(i, n):
                if lcp[i][j]:
                    s[j] = c
        if "" in s:
            return ""
        for i in range(n - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                if s[i] == s[j]:
                    if i == n - 1 or j == n - 1:
                        if lcp[i][j] != 1:
                            return ""
                    elif lcp[i][j] != lcp[i + 1][j + 1] + 1:
                        return ""
                elif lcp[i][j]:
                    return ""
        return "".join(s)
```

#### Java

```java
class Solution {
    public String findTheString(int[][] lcp) {
        int n = lcp.length;
        char[] s = new char[n];
        int i = 0;
        for (char c = 'a'; c <= 'z'; ++c) {
            while (i < n && s[i] != '\0') {
                ++i;
            }
            if (i == n) {
                break;
            }
            for (int j = i; j < n; ++j) {
                if (lcp[i][j] > 0) {
                    s[j] = c;
                }
            }
        }
        for (i = 0; i < n; ++i) {
            if (s[i] == '\0') {
                return "";
            }
        }
        for (i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (s[i] == s[j]) {
                    if (i == n - 1 || j == n - 1) {
                        if (lcp[i][j] != 1) {
                            return "";
                        }
                    } else if (lcp[i][j] != lcp[i + 1][j + 1] + 1) {
                        return "";
                    }
                } else if (lcp[i][j] > 0) {
                    return "";
                }
            }
        }
        return String.valueOf(s);
    }
}
```

#### C++

```cpp
class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int i = 0, n = lcp.size();
        string s(n, '\0');
        for (char c = 'a'; c <= 'z'; ++c) {
            while (i < n && s[i]) {
                ++i;
            }
            if (i == n) {
                break;
            }
            for (int j = i; j < n; ++j) {
                if (lcp[i][j]) {
                    s[j] = c;
                }
            }
        }
        if (s.find('\0') != -1) {
            return "";
        }
        for (i = n - 1; ~i; --i) {
            for (int j = n - 1; ~j; --j) {
                if (s[i] == s[j]) {
                    if (i == n - 1 || j == n - 1) {
                        if (lcp[i][j] != 1) {
                            return "";
                        }
                    } else if (lcp[i][j] != lcp[i + 1][j + 1] + 1) {
                        return "";
                    }
                } else if (lcp[i][j]) {
                    return "";
                }
            }
        }
        return s;
    }
};
```

#### Go

```go
func findTheString(lcp [][]int) string {
	i, n := 0, len(lcp)
	s := make([]byte, n)
	for c := 'a'; c <= 'z'; c++ {
		for i < n && s[i] != 0 {
			i++
		}
		if i == n {
			break
		}
		for j := i; j < n; j++ {
			if lcp[i][j] > 0 {
				s[j] = byte(c)
			}
		}
	}
	if bytes.IndexByte(s, 0) >= 0 {
		return ""
	}
	for i := n - 1; i >= 0; i-- {
		for j := n - 1; j >= 0; j-- {
			if s[i] == s[j] {
				if i == n-1 || j == n-1 {
					if lcp[i][j] != 1 {
						return ""
					}
				} else if lcp[i][j] != lcp[i+1][j+1]+1 {
					return ""
				}
			} else if lcp[i][j] > 0 {
				return ""
			}
		}
	}
	return string(s)
}
```

#### TypeScript

```ts
function findTheString(lcp: number[][]): string {
    let i: number = 0;
    const n: number = lcp.length;
    let s: string = '\0'.repeat(n);
    for (let ascii = 97; ascii < 123; ++ascii) {
        const c: string = String.fromCharCode(ascii);
        while (i < n && s[i] !== '\0') {
            ++i;
        }
        if (i === n) {
            break;
        }
        for (let j = i; j < n; ++j) {
            if (lcp[i][j]) {
                s = s.substring(0, j) + c + s.substring(j + 1);
            }
        }
    }
    if (s.indexOf('\0') !== -1) {
        return '';
    }
    for (i = n - 1; ~i; --i) {
        for (let j = n - 1; ~j; --j) {
            if (s[i] === s[j]) {
                if (i === n - 1 || j === n - 1) {
                    if (lcp[i][j] !== 1) {
                        return '';
                    }
                } else if (lcp[i][j] !== lcp[i + 1][j + 1] + 1) {
                    return '';
                }
            } else if (lcp[i][j]) {
                return '';
            }
        }
    }
    return s;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2574. 左右元素和的差值](https://leetcode.cn/problems/left-and-right-sum-differences){#2574}

{{< tabs "2574" >}}

{{% tab "python" %}}
```python
class Solution:
    def leftRigthDifference(self, nums: List[int]) -> List[int]:
        left, right = 0, sum(nums)
        ans = []
        for x in nums:
            right -= x
            ans.append(abs(left - right))
            left += x
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] leftRigthDifference(int[] nums) {
        int left = 0, right = Arrays.stream(nums).sum();
        int n = nums.length;
        int[] ans = new int[n];
        for (int i = 0; i < n; ++i) {
            right -= nums[i];
            ans[i] = Math.abs(left - right);
            left += nums[i];
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
    vector<int> leftRigthDifference(vector<int>& nums) {
        int left = 0, right = accumulate(nums.begin(), nums.end(), 0);
        vector<int> ans;
        for (int& x : nums) {
            right -= x;
            ans.push_back(abs(left - right));
            left += x;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func leftRigthDifference(nums []int) (ans []int) {
	var left, right int
	for _, x := range nums {
		right += x
	}
	for _, x := range nums {
		right -= x
		ans = append(ans, abs(left-right))
		left += x
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
function leftRigthDifference(nums: number[]): number[] {
    let left = 0;
    let right = nums.reduce((r, v) => r + v);
    return nums.map(v => {
        right -= v;
        const res = Math.abs(left - right);
        left += v;
        return res;
    });
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn left_right_difference(nums: Vec<i32>) -> Vec<i32> {
        let mut left = 0;
        let mut right: i32 = nums.iter().sum();
        let mut ans = vec![];

        for &x in &nums {
            right -= x;
            ans.push((left - right).abs());
            left += x;
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
int* leftRigthDifference(int* nums, int numsSize, int* returnSize) {
    int left = 0;
    int right = 0;
    for (int i = 0; i < numsSize; i++) {
        right += nums[i];
    }
    int* ans = malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        right -= nums[i];
        ans[i] = abs(left - right);
        left += nums[i];
    }
    *returnSize = numsSize;
    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong> 开始的长度为&nbsp;<code>n</code>&nbsp;的整数数组 <code>nums</code>。</p>

<p>定义两个数组&nbsp;<code>leftSum</code>&nbsp;和&nbsp;<code>rightSum</code>，其中：</p>

<ul>
	<li><code>leftSum[i]</code> 是数组 <code>nums</code> 中下标 <code>i</code> 左侧元素之和。如果不存在对应的元素，<code>leftSum[i] = 0</code> 。</li>
	<li><code>rightSum[i]</code> 是数组 <code>nums</code> 中下标 <code>i</code> 右侧元素之和。如果不存在对应的元素，<code>rightSum[i] = 0</code> 。</li>
</ul>

<p>返回长度为&nbsp;<code>n</code> 数组 <code>answer</code>，其中 <code>answer[i] = |leftSum[i] - rightSum[i]|</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [10,4,8,3]
<strong>输出：</strong>[15,1,11,22]
<strong>解释：</strong>数组 leftSum 为 [0,10,14,22] 且数组 rightSum 为 [15,11,3,0] 。
数组 answer 为 [|0 - 15|,|10 - 11|,|14 - 3|,|22 - 0|] = [15,1,11,22] 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1]
<strong>输出：</strong>[0]
<strong>解释：</strong>数组 leftSum 为 [0] 且数组 rightSum 为 [0] 。
数组 answer 为 [|0 - 0|] = [0] 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前缀和

我们定义变量 $left$ 表示数组 `nums` 中下标 $i$ 左侧元素之和，变量 $right$ 表示数组 `nums` 中下标 $i$ 右侧元素之和。初始时 $left = 0$, $right = \sum_{i = 0}^{n - 1} nums[i]$。

遍历数组 `nums`，对于当前遍历到的数字 $x$，我们更新 $right = right - x$，此时 $left$ 和 $right$ 分别表示数组 `nums` 中下标 $i$ 左侧元素之和和右侧元素之和。我们将 $left$ 和 $right$ 的差的绝对值加入答案数组 `ans` 中，然后更新 $left = left + x$。

遍历完成后，返回答案数组 `ans` 即可。

时间复杂度 $O(n)$，空间复杂度 $O(1)$。其中 $n$ 为数组 `nums` 的长度。

相似题目：

-   [0724. 寻找数组的中心下标](https://github.com/doocs/leetcode/blob/main/solution/0700-0799/0724.Find%20Pivot%20Index/README.md)
-   [1991. 找到数组的中间位置](https://github.com/doocs/leetcode/blob/main/solution/1900-1999/1991.Find%20the%20Middle%20Index%20in%20Array/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def leftRigthDifference(self, nums: List[int]) -> List[int]:
        left, right = 0, sum(nums)
        ans = []
        for x in nums:
            right -= x
            ans.append(abs(left - right))
            left += x
        return ans
```

#### Java

```java
class Solution {
    public int[] leftRigthDifference(int[] nums) {
        int left = 0, right = Arrays.stream(nums).sum();
        int n = nums.length;
        int[] ans = new int[n];
        for (int i = 0; i < n; ++i) {
            right -= nums[i];
            ans[i] = Math.abs(left - right);
            left += nums[i];
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        int left = 0, right = accumulate(nums.begin(), nums.end(), 0);
        vector<int> ans;
        for (int& x : nums) {
            right -= x;
            ans.push_back(abs(left - right));
            left += x;
        }
        return ans;
    }
};
```

#### Go

```go
func leftRigthDifference(nums []int) (ans []int) {
	var left, right int
	for _, x := range nums {
		right += x
	}
	for _, x := range nums {
		right -= x
		ans = append(ans, abs(left-right))
		left += x
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
function leftRigthDifference(nums: number[]): number[] {
    let left = 0,
        right = nums.reduce((a, b) => a + b);
    const ans: number[] = [];
    for (const x of nums) {
        right -= x;
        ans.push(Math.abs(left - right));
        left += x;
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn left_rigth_difference(nums: Vec<i32>) -> Vec<i32> {
        let mut left = 0;
        let mut right = nums.iter().sum::<i32>();
        nums.iter()
            .map(|v| {
                right -= v;
                let res = (left - right).abs();
                left += v;
                res
            })
            .collect()
    }
}
```

#### C

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* leftRigthDifference(int* nums, int numsSize, int* returnSize) {
    int left = 0;
    int right = 0;
    for (int i = 0; i < numsSize; i++) {
        right += nums[i];
    }
    int* ans = malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        right -= nums[i];
        ans[i] = abs(left - right);
        left += nums[i];
    }
    *returnSize = numsSize;
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### TypeScript

```ts
function leftRigthDifference(nums: number[]): number[] {
    let left = 0;
    let right = nums.reduce((r, v) => r + v);
    return nums.map(v => {
        right -= v;
        const res = Math.abs(left - right);
        left += v;
        return res;
    });
}
```

#### Rust

```rust
impl Solution {
    pub fn left_right_difference(nums: Vec<i32>) -> Vec<i32> {
        let mut ans = vec![];

        for i in 0..nums.len() {
            let mut left = 0;
            for j in 0..i {
                left += nums[j];
            }

            let mut right = 0;
            for k in i + 1..nums.len() {
                right += nums[k];
            }

            ans.push((left - right).abs());
        }

        ans
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法三

<!-- tabs:start -->

#### Rust

```rust
impl Solution {
    pub fn left_right_difference(nums: Vec<i32>) -> Vec<i32> {
        let mut left = 0;
        let mut right: i32 = nums.iter().sum();
        let mut ans = vec![];

        for &x in &nums {
            right -= x;
            ans.push((left - right).abs());
            left += x;
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

# [2575. 找出字符串的可整除数组](https://leetcode.cn/problems/find-the-divisibility-array-of-a-string){#2575}

{{< tabs "2575" >}}

{{% tab "python" %}}
```python
class Solution:
    def divisibilityArray(self, word: str, m: int) -> List[int]:
        ans = []
        x = 0
        for c in word:
            x = (x * 10 + int(c)) % m
            ans.append(1 if x == 0 else 0)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] divisibilityArray(String word, int m) {
        int n = word.length();
        int[] ans = new int[n];
        long x = 0;
        for (int i = 0; i < n; ++i) {
            x = (x * 10 + word.charAt(i) - '0') % m;
            if (x == 0) {
                ans[i] = 1;
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
    vector<int> divisibilityArray(string word, int m) {
        vector<int> ans;
        long long x = 0;
        for (char& c : word) {
            x = (x * 10 + c - '0') % m;
            ans.push_back(x == 0 ? 1 : 0);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func divisibilityArray(word string, m int) (ans []int) {
	x := 0
	for _, c := range word {
		x = (x*10 + int(c-'0')) % m
		if x == 0 {
			ans = append(ans, 1)
		} else {
			ans = append(ans, 0)
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function divisibilityArray(word: string, m: number): number[] {
    const ans: number[] = [];
    let x = 0;
    for (const c of word) {
        x = (x * 10 + Number(c)) % m;
        ans.push(x === 0 ? 1 : 0);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn divisibility_array(word: String, m: i32) -> Vec<i32> {
        let m = m as i64;
        let mut x = 0i64;
        word.as_bytes()
            .iter()
            .map(|&c| {
                x = (x * 10 + i64::from(c - b'0')) % m;
                if x == 0 {
                    1
                } else {
                    0
                }
            })
            .collect()
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* divisibilityArray(char* word, int m, int* returnSize) {
    int n = strlen(word);
    int* ans = malloc(sizeof(int) * n);
    long long x = 0;
    for (int i = 0; i < n; i++) {
        x = (x * 10 + word[i] - '0') % m;
        ans[i] = x == 0 ? 1 : 0;
    }
    *returnSize = n;
    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong> 开始的字符串 <code>word</code> ，长度为 <code>n</code> ，由从 <code>0</code> 到 <code>9</code> 的数字组成。另给你一个正整数 <code>m</code> 。</p>

<p><code>word</code> 的 <strong>可整除数组</strong> <code>div</code>&nbsp; 是一个长度为 <code>n</code> 的整数数组，并满足：</p>

<ul>
	<li>如果 <code>word[0,...,i]</code> 所表示的 <strong>数值</strong> 能被 <code>m</code> 整除，<code>div[i] = 1</code></li>
	<li>否则，<code>div[i] = 0</code></li>
</ul>

<p>返回<em> </em><code>word</code> 的可整除数组。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>word = "998244353", m = 3
<strong>输出：</strong>[1,1,0,0,0,1,1,0,0]
<strong>解释：</strong>仅有 4 个前缀可以被 3 整除："9"、"99"、"998244" 和 "9982443" 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>word = "1010", m = 10
<strong>输出：</strong>[0,1,0,1]
<strong>解释：</strong>仅有 2 个前缀可以被 10 整除："10" 和 "1010" 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>word.length == n</code></li>
	<li><code>word</code> 由数字 <code>0</code> 到 <code>9</code> 组成</li>
	<li><code>1 &lt;= m &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：遍历 + 取模

我们遍历字符串 `word`，用变量 $x$ 记录当前前缀与 $m$ 的取模结果，如果 $x$ 为 $0$，则当前位置的可整除数组值为 $1$，否则为 $0$。

时间复杂度 $O(n)$，其中 $n$ 为字符串 `word` 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def divisibilityArray(self, word: str, m: int) -> List[int]:
        ans = []
        x = 0
        for c in word:
            x = (x * 10 + int(c)) % m
            ans.append(1 if x == 0 else 0)
        return ans
```

#### Java

```java
class Solution {
    public int[] divisibilityArray(String word, int m) {
        int n = word.length();
        int[] ans = new int[n];
        long x = 0;
        for (int i = 0; i < n; ++i) {
            x = (x * 10 + word.charAt(i) - '0') % m;
            if (x == 0) {
                ans[i] = 1;
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
    vector<int> divisibilityArray(string word, int m) {
        vector<int> ans;
        long long x = 0;
        for (char& c : word) {
            x = (x * 10 + c - '0') % m;
            ans.push_back(x == 0 ? 1 : 0);
        }
        return ans;
    }
};
```

#### Go

```go
func divisibilityArray(word string, m int) (ans []int) {
	x := 0
	for _, c := range word {
		x = (x*10 + int(c-'0')) % m
		if x == 0 {
			ans = append(ans, 1)
		} else {
			ans = append(ans, 0)
		}
	}
	return ans
}
```

#### TypeScript

```ts
function divisibilityArray(word: string, m: number): number[] {
    const ans: number[] = [];
    let x = 0;
    for (const c of word) {
        x = (x * 10 + Number(c)) % m;
        ans.push(x === 0 ? 1 : 0);
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn divisibility_array(word: String, m: i32) -> Vec<i32> {
        let m = m as i64;
        let mut x = 0i64;
        word.as_bytes()
            .iter()
            .map(|&c| {
                x = (x * 10 + i64::from(c - b'0')) % m;
                if x == 0 {
                    1
                } else {
                    0
                }
            })
            .collect()
    }
}
```

#### C

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* divisibilityArray(char* word, int m, int* returnSize) {
    int n = strlen(word);
    int* ans = malloc(sizeof(int) * n);
    long long x = 0;
    for (int i = 0; i < n; i++) {
        x = (x * 10 + word[i] - '0') % m;
        ans[i] = x == 0 ? 1 : 0;
    }
    *returnSize = n;
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2576. 求出最多标记下标](https://leetcode.cn/problems/find-the-maximum-number-of-marked-indices){#2576}

{{< tabs "2576" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxNumOfMarkedIndices(self, nums: List[int]) -> int:
        nums.sort()
        i, n = 0, len(nums)
        for x in nums[(n + 1) // 2 :]:
            if nums[i] * 2 <= x:
                i += 1
        return i * 2
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxNumOfMarkedIndices(int[] nums) {
        Arrays.sort(nums);
        int i = 0, n = nums.length;
        for (int j = (n + 1) / 2; j < n; ++j) {
            if (nums[i] * 2 <= nums[j]) {
                ++i;
            }
        }
        return i * 2;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        ranges::sort(nums);
        int i = 0, n = nums.size();
        for (int j = (n + 1) / 2; j < n; ++j) {
            if (nums[i] * 2 <= nums[j]) {
                ++i;
            }
        }
        return i * 2;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxNumOfMarkedIndices(nums []int) (ans int) {
	sort.Ints(nums)
	i, n := 0, len(nums)
	for _, x := range nums[(n+1)/2:] {
		if nums[i]*2 <= x {
			i++
		}
	}
	return i * 2
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxNumOfMarkedIndices(nums: number[]): number {
    nums.sort((a, b) => a - b);
    const n = nums.length;
    let i = 0;
    for (let j = (n + 1) >> 1; j < n; ++j) {
        if (nums[i] * 2 <= nums[j]) {
            ++i;
        }
    }
    return i * 2;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn max_num_of_marked_indices(mut nums: Vec<i32>) -> i32 {
        nums.sort();
        let mut i = 0;
        let n = nums.len();
        for j in (n + 1) / 2..n {
            if nums[i] * 2 <= nums[j] {
                i += 1;
            }
        }
        (i * 2) as i32
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>nums</code>&nbsp;。</p>

<p>一开始，所有下标都没有被标记。你可以执行以下操作任意次：</p>

<ul>
	<li>选择两个 <strong>互不相同且未标记</strong>&nbsp;的下标&nbsp;<code>i</code> 和&nbsp;<code>j</code>&nbsp;，满足&nbsp;<code>2 * nums[i] &lt;= nums[j]</code>&nbsp;，标记下标&nbsp;<code>i</code> 和&nbsp;<code>j</code>&nbsp;。</li>
</ul>

<p>请你执行上述操作任意次，返回<em>&nbsp;</em><code>nums</code>&nbsp;中最多可以标记的下标数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [3,5,2,4]
<b>输出：</b>2
<strong>解释：</strong>第一次操作中，选择 i = 2 和 j = 1 ，操作可以执行的原因是 2 * nums[2] &lt;= nums[1] ，标记下标 2 和 1 。
没有其他更多可执行的操作，所以答案为 2 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [9,2,5,4]
<b>输出：</b>4
<strong>解释：</strong>第一次操作中，选择 i = 3 和 j = 0 ，操作可以执行的原因是 2 * nums[3] &lt;= nums[0] ，标记下标 3 和 0 。
第二次操作中，选择 i = 1 和 j = 2 ，操作可以执行的原因是 2 * nums[1] &lt;= nums[2] ，标记下标 1 和 2 。
没有其他更多可执行的操作，所以答案为 4 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>nums = [7,6,8]
<b>输出：</b>0
<strong>解释：</strong>没有任何可以执行的操作，所以答案为 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 双指针

根据题目描述，题目最多产生 $n / 2$ 组标记，其中 $n$ 为数组 $\textit{nums}$ 的长度。

为了将下标尽可能多地标记，我们可以将数组 $\textit{nums}$ 排序，接下来，我们遍历右半部分的每个元素 $\textit{nums}[j]$，用一个指针 $\textit{i}$ 指向左半部分的最小元素，如果 $\textit{nums}[i] \times 2 \leq \textit{nums}[j]$，则可以标记下标 $\textit{i}$ 和 $\textit{j}$，我们将 $\textit{i}$ 向右移动一个位置。继续遍历右半部分的元素，直到到达数组的末尾。此时，我们可以标记的下标数目为 $\textit{i} \times 2$。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 为数组 $\textit{nums}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxNumOfMarkedIndices(self, nums: List[int]) -> int:
        nums.sort()
        i, n = 0, len(nums)
        for x in nums[(n + 1) // 2 :]:
            if nums[i] * 2 <= x:
                i += 1
        return i * 2
```

#### Java

```java
class Solution {
    public int maxNumOfMarkedIndices(int[] nums) {
        Arrays.sort(nums);
        int i = 0, n = nums.length;
        for (int j = (n + 1) / 2; j < n; ++j) {
            if (nums[i] * 2 <= nums[j]) {
                ++i;
            }
        }
        return i * 2;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        ranges::sort(nums);
        int i = 0, n = nums.size();
        for (int j = (n + 1) / 2; j < n; ++j) {
            if (nums[i] * 2 <= nums[j]) {
                ++i;
            }
        }
        return i * 2;
    }
};
```

#### Go

```go
func maxNumOfMarkedIndices(nums []int) (ans int) {
	sort.Ints(nums)
	i, n := 0, len(nums)
	for _, x := range nums[(n+1)/2:] {
		if nums[i]*2 <= x {
			i++
		}
	}
	return i * 2
}
```

#### TypeScript

```ts
function maxNumOfMarkedIndices(nums: number[]): number {
    nums.sort((a, b) => a - b);
    const n = nums.length;
    let i = 0;
    for (let j = (n + 1) >> 1; j < n; ++j) {
        if (nums[i] * 2 <= nums[j]) {
            ++i;
        }
    }
    return i * 2;
}
```

#### Rust

```rust
impl Solution {
    pub fn max_num_of_marked_indices(mut nums: Vec<i32>) -> i32 {
        nums.sort();
        let mut i = 0;
        let n = nums.len();
        for j in (n + 1) / 2..n {
            if nums[i] * 2 <= nums[j] {
                i += 1;
            }
        }
        (i * 2) as i32
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2577. 在网格图中访问一个格子的最少时间](https://leetcode.cn/problems/minimum-time-to-visit-a-cell-in-a-grid){#2577}

{{< tabs "2577" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumTime(self, grid: List[List[int]]) -> int:
        if grid[0][1] > 1 and grid[1][0] > 1:
            return -1
        m, n = len(grid), len(grid[0])
        dist = [[inf] * n for _ in range(m)]
        dist[0][0] = 0
        q = [(0, 0, 0)]
        dirs = (-1, 0, 1, 0, -1)
        while 1:
            t, i, j = heappop(q)
            if i == m - 1 and j == n - 1:
                return t
            for a, b in pairwise(dirs):
                x, y = i + a, j + b
                if 0 <= x < m and 0 <= y < n:
                    nt = t + 1
                    if nt < grid[x][y]:
                        nt = grid[x][y] + (grid[x][y] - nt) % 2
                    if nt < dist[x][y]:
                        dist[x][y] = nt
                        heappush(q, (nt, x, y))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumTime(int[][] grid) {
        if (grid[0][1] > 1 && grid[1][0] > 1) {
            return -1;
        }
        int m = grid.length, n = grid[0].length;
        int[][] dist = new int[m][n];
        for (var e : dist) {
            Arrays.fill(e, 1 << 30);
        }
        dist[0][0] = 0;
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        pq.offer(new int[] {0, 0, 0});
        int[] dirs = {-1, 0, 1, 0, -1};
        while (true) {
            var p = pq.poll();
            int i = p[1], j = p[2];
            if (i == m - 1 && j == n - 1) {
                return p[0];
            }
            for (int k = 0; k < 4; ++k) {
                int x = i + dirs[k], y = j + dirs[k + 1];
                if (x >= 0 && x < m && y >= 0 && y < n) {
                    int nt = p[0] + 1;
                    if (nt < grid[x][y]) {
                        nt = grid[x][y] + (grid[x][y] - nt) % 2;
                    }
                    if (nt < dist[x][y]) {
                        dist[x][y] = nt;
                        pq.offer(new int[] {nt, x, y});
                    }
                }
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
    int minimumTime(vector<vector<int>>& grid) {
        if (grid[0][1] > 1 && grid[1][0] > 1) {
            return -1;
        }
        int m = grid.size(), n = grid[0].size();
        int dist[m][n];
        memset(dist, 0x3f, sizeof dist);
        dist[0][0] = 0;
        using tii = tuple<int, int, int>;
        priority_queue<tii, vector<tii>, greater<tii>> pq;
        pq.emplace(0, 0, 0);
        int dirs[5] = {-1, 0, 1, 0, -1};
        while (1) {
            auto [t, i, j] = pq.top();
            pq.pop();
            if (i == m - 1 && j == n - 1) {
                return t;
            }
            for (int k = 0; k < 4; ++k) {
                int x = i + dirs[k], y = j + dirs[k + 1];
                if (x >= 0 && x < m && y >= 0 && y < n) {
                    int nt = t + 1;
                    if (nt < grid[x][y]) {
                        nt = grid[x][y] + (grid[x][y] - nt) % 2;
                    }
                    if (nt < dist[x][y]) {
                        dist[x][y] = nt;
                        pq.emplace(nt, x, y);
                    }
                }
            }
        }
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumTime(grid [][]int) int {
	if grid[0][1] > 1 && grid[1][0] > 1 {
		return -1
	}
	m, n := len(grid), len(grid[0])
	dist := make([][]int, m)
	for i := range dist {
		dist[i] = make([]int, n)
		for j := range dist[i] {
			dist[i][j] = 1 << 30
		}
	}
	dist[0][0] = 0
	pq := hp{}
	heap.Push(&pq, tuple{0, 0, 0})
	dirs := [5]int{-1, 0, 1, 0, -1}
	for {
		p := heap.Pop(&pq).(tuple)
		i, j := p.i, p.j
		if i == m-1 && j == n-1 {
			return p.t
		}
		for k := 0; k < 4; k++ {
			x, y := i+dirs[k], j+dirs[k+1]
			if x >= 0 && x < m && y >= 0 && y < n {
				nt := p.t + 1
				if nt < grid[x][y] {
					nt = grid[x][y] + (grid[x][y]-nt)%2
				}
				if nt < dist[x][y] {
					dist[x][y] = nt
					heap.Push(&pq, tuple{nt, x, y})
				}
			}
		}
	}
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
function minimumTime(grid: number[][]): number {
    if (grid[0][1] > 1 && grid[1][0] > 1) return -1;

    const [m, n] = [grid.length, grid[0].length];
    const DIRS = [-1, 0, 1, 0, -1];
    const q = new MinPriorityQueue({ priority: ([x]) => x });
    const dist: number[][] = Array.from({ length: m }, () =>
        new Array(n).fill(Number.POSITIVE_INFINITY),
    );
    dist[0][0] = 0;
    q.enqueue([0, 0, 0]);

    while (true) {
        const [t, i, j] = q.dequeue().element;
        if (i === m - 1 && j === n - 1) return t;

        for (let k = 0; k < 4; k++) {
            const [x, y] = [i + DIRS[k], j + DIRS[k + 1]];
            if (x < 0 || x >= m || y < 0 || y >= n) continue;

            let nt = t + 1;
            if (nt < grid[x][y]) {
                nt = grid[x][y] + ((grid[x][y] - nt) % 2);
            }
            if (nt < dist[x][y]) {
                dist[x][y] = nt;
                q.enqueue([nt, x, y]);
            }
        }
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
function minimumTime(grid) {
    if (grid[0][1] > 1 && grid[1][0] > 1) return -1;

    const [m, n] = [grid.length, grid[0].length];
    const DIRS = [-1, 0, 1, 0, -1];
    const q = new MinPriorityQueue({ priority: ([x]) => x });
    const dist = Array.from({ length: m }, () => new Array(n).fill(Number.POSITIVE_INFINITY));
    dist[0][0] = 0;
    q.enqueue([0, 0, 0]);

    while (true) {
        const [t, i, j] = q.dequeue().element;
        if (i === m - 1 && j === n - 1) return t;

        for (let k = 0; k < 4; k++) {
            const [x, y] = [i + DIRS[k], j + DIRS[k + 1]];
            if (x < 0 || x >= m || y < 0 || y >= n) continue;

            let nt = t + 1;
            if (nt < grid[x][y]) {
                nt = grid[x][y] + ((grid[x][y] - nt) % 2);
            }
            if (nt < dist[x][y]) {
                dist[x][y] = nt;
                q.enqueue([nt, x, y]);
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

<p>给你一个&nbsp;<code>m x n</code>&nbsp;的矩阵&nbsp;<code>grid</code>&nbsp;，每个元素都为 <strong>非负</strong>&nbsp;整数，其中&nbsp;<code>grid[row][col]</code>&nbsp;表示可以访问格子&nbsp;<code>(row, col)</code>&nbsp;的&nbsp;<strong>最早</strong>&nbsp;时间。也就是说当你访问格子&nbsp;<code>(row, col)</code>&nbsp;时，最少已经经过的时间为&nbsp;<code>grid[row][col]</code>&nbsp;。</p>

<p>你从 <strong>最左上角</strong>&nbsp;出发，出发时刻为 <code>0</code>&nbsp;，你必须一直移动到上下左右相邻四个格子中的 <strong>任意</strong>&nbsp;一个格子（即不能停留在格子上）。每次移动都需要花费 1 单位时间。</p>

<p>请你返回 <strong>最早</strong>&nbsp;到达右下角格子的时间，如果你无法到达右下角的格子，请你返回 <code>-1</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2500-2599/2577.Minimum%20Time%20to%20Visit%20a%20Cell%20In%20a%20Grid/images/yetgriddrawio-8.png" /></p>

<pre>
<b>输入：</b>grid = [[0,1,3,2],[5,1,2,5],[4,3,8,6]]
<b>输出：</b>7
<b>解释：</b>一条可行的路径为：
- 时刻 t = 0 ，我们在格子 (0,0) 。
- 时刻 t = 1 ，我们移动到格子 (0,1) ，可以移动的原因是 grid[0][1] &lt;= 1 。
- 时刻 t = 2 ，我们移动到格子 (1,1) ，可以移动的原因是 grid[1][1] &lt;= 2 。
- 时刻 t = 3 ，我们移动到格子 (1,2) ，可以移动的原因是 grid[1][2] &lt;= 3 。
- 时刻 t = 4 ，我们移动到格子 (1,1) ，可以移动的原因是 grid[1][1] &lt;= 4 。
- 时刻 t = 5 ，我们移动到格子 (1,2) ，可以移动的原因是 grid[1][2] &lt;= 5 。
- 时刻 t = 6 ，我们移动到格子 (1,3) ，可以移动的原因是 grid[1][3] &lt;= 6 。
- 时刻 t = 7 ，我们移动到格子 (2,3) ，可以移动的原因是 grid[2][3] &lt;= 7 。
最终到达时刻为 7 。这是最早可以到达的时间。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2500-2599/2577.Minimum%20Time%20to%20Visit%20a%20Cell%20In%20a%20Grid/images/yetgriddrawio-9.png" style="width: 151px; height: 151px;" /></p>

<pre>
<b>输入：</b>grid = [[0,2,4],[3,2,1],[1,0,4]]
<b>输出：</b>-1
<b>解释：</b>没法从左上角按题目规定走到右下角。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>2 &lt;= m, n &lt;= 1000</code></li>
	<li><code>4 &lt;= m * n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= grid[i][j] &lt;= 10<sup>5</sup></code></li>
	<li><code>grid[0][0] == 0</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：最短路 + 优先队列（小根堆）

我们观察发现，如果在格子 $(0, 0)$ 处无法移动，即 $grid[0][1] \gt 1$ 且 $grid[1][0] \gt 1$，那么我们在格子 $(0, 0)$ 无法再移动，此时返回 $-1$ 即可。而对于其他情况，我们都可以移动。

接下来，我们定义 $dist[i][j]$ 表示 $(i, j)$ 处的最早到达时间，初始时 $dist[0][0] = 0$，而其他位置的 $dist$ 均初始化为 $\infty$。

我们使用优先队列（小根堆）来维护当前可以移动的格子，优先队列中的元素为 $(dist[i][j], i, j)$，即 $(dist[i][j], i, j)$ 表示 $(i, j)$ 处的最早到达时间。

我们每次从优先队列中取出当前最早到达的格子 $(t, i, j)$，如果 $(i, j)$ 为 $(m - 1, n - 1)$，那么我们直接返回 $t$ 即可，否则，我们遍历 $(i, j)$ 的上下左右四个相邻格子 $(x, y)$，如果 $t + 1 \lt grid[x][y]$，那么我们移动到 $(x, y)$ 的时间 $nt = grid[x][y] + (grid[x][y] - (t + 1)) \bmod 2$，此时我们可以通过反复移动将时间拉长至不小于 $grid[x][y]$，这取决于 $t + 1$ 和 $grid[x][y]$ 距离的奇偶性。否则，我们移动到 $(x, y)$ 的时间 $nt = t + 1$。如果 $nt \lt dist[x][y]$，那么我们更新 $dist[x][y] = nt$，并将 $(nt, x, y)$ 加入优先队列中。

时间复杂度 $O(m \times n \times \log (m \times n))$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别为网格的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumTime(self, grid: List[List[int]]) -> int:
        if grid[0][1] > 1 and grid[1][0] > 1:
            return -1
        m, n = len(grid), len(grid[0])
        dist = [[inf] * n for _ in range(m)]
        dist[0][0] = 0
        q = [(0, 0, 0)]
        dirs = (-1, 0, 1, 0, -1)
        while 1:
            t, i, j = heappop(q)
            if i == m - 1 and j == n - 1:
                return t
            for a, b in pairwise(dirs):
                x, y = i + a, j + b
                if 0 <= x < m and 0 <= y < n:
                    nt = t + 1
                    if nt < grid[x][y]:
                        nt = grid[x][y] + (grid[x][y] - nt) % 2
                    if nt < dist[x][y]:
                        dist[x][y] = nt
                        heappush(q, (nt, x, y))
```

#### Java

```java
class Solution {
    public int minimumTime(int[][] grid) {
        if (grid[0][1] > 1 && grid[1][0] > 1) {
            return -1;
        }
        int m = grid.length, n = grid[0].length;
        int[][] dist = new int[m][n];
        for (var e : dist) {
            Arrays.fill(e, 1 << 30);
        }
        dist[0][0] = 0;
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        pq.offer(new int[] {0, 0, 0});
        int[] dirs = {-1, 0, 1, 0, -1};
        while (true) {
            var p = pq.poll();
            int i = p[1], j = p[2];
            if (i == m - 1 && j == n - 1) {
                return p[0];
            }
            for (int k = 0; k < 4; ++k) {
                int x = i + dirs[k], y = j + dirs[k + 1];
                if (x >= 0 && x < m && y >= 0 && y < n) {
                    int nt = p[0] + 1;
                    if (nt < grid[x][y]) {
                        nt = grid[x][y] + (grid[x][y] - nt) % 2;
                    }
                    if (nt < dist[x][y]) {
                        dist[x][y] = nt;
                        pq.offer(new int[] {nt, x, y});
                    }
                }
            }
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        if (grid[0][1] > 1 && grid[1][0] > 1) {
            return -1;
        }
        int m = grid.size(), n = grid[0].size();
        int dist[m][n];
        memset(dist, 0x3f, sizeof dist);
        dist[0][0] = 0;
        using tii = tuple<int, int, int>;
        priority_queue<tii, vector<tii>, greater<tii>> pq;
        pq.emplace(0, 0, 0);
        int dirs[5] = {-1, 0, 1, 0, -1};
        while (1) {
            auto [t, i, j] = pq.top();
            pq.pop();
            if (i == m - 1 && j == n - 1) {
                return t;
            }
            for (int k = 0; k < 4; ++k) {
                int x = i + dirs[k], y = j + dirs[k + 1];
                if (x >= 0 && x < m && y >= 0 && y < n) {
                    int nt = t + 1;
                    if (nt < grid[x][y]) {
                        nt = grid[x][y] + (grid[x][y] - nt) % 2;
                    }
                    if (nt < dist[x][y]) {
                        dist[x][y] = nt;
                        pq.emplace(nt, x, y);
                    }
                }
            }
        }
    }
};
```

#### Go

```go
func minimumTime(grid [][]int) int {
	if grid[0][1] > 1 && grid[1][0] > 1 {
		return -1
	}
	m, n := len(grid), len(grid[0])
	dist := make([][]int, m)
	for i := range dist {
		dist[i] = make([]int, n)
		for j := range dist[i] {
			dist[i][j] = 1 << 30
		}
	}
	dist[0][0] = 0
	pq := hp{}
	heap.Push(&pq, tuple{0, 0, 0})
	dirs := [5]int{-1, 0, 1, 0, -1}
	for {
		p := heap.Pop(&pq).(tuple)
		i, j := p.i, p.j
		if i == m-1 && j == n-1 {
			return p.t
		}
		for k := 0; k < 4; k++ {
			x, y := i+dirs[k], j+dirs[k+1]
			if x >= 0 && x < m && y >= 0 && y < n {
				nt := p.t + 1
				if nt < grid[x][y] {
					nt = grid[x][y] + (grid[x][y]-nt)%2
				}
				if nt < dist[x][y] {
					dist[x][y] = nt
					heap.Push(&pq, tuple{nt, x, y})
				}
			}
		}
	}
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
function minimumTime(grid: number[][]): number {
    if (grid[0][1] > 1 && grid[1][0] > 1) return -1;

    const [m, n] = [grid.length, grid[0].length];
    const DIRS = [-1, 0, 1, 0, -1];
    const q = new MinPriorityQueue({ priority: ([x]) => x });
    const dist: number[][] = Array.from({ length: m }, () =>
        new Array(n).fill(Number.POSITIVE_INFINITY),
    );
    dist[0][0] = 0;
    q.enqueue([0, 0, 0]);

    while (true) {
        const [t, i, j] = q.dequeue().element;
        if (i === m - 1 && j === n - 1) return t;

        for (let k = 0; k < 4; k++) {
            const [x, y] = [i + DIRS[k], j + DIRS[k + 1]];
            if (x < 0 || x >= m || y < 0 || y >= n) continue;

            let nt = t + 1;
            if (nt < grid[x][y]) {
                nt = grid[x][y] + ((grid[x][y] - nt) % 2);
            }
            if (nt < dist[x][y]) {
                dist[x][y] = nt;
                q.enqueue([nt, x, y]);
            }
        }
    }
}
```

#### JavaScript

```js
function minimumTime(grid) {
    if (grid[0][1] > 1 && grid[1][0] > 1) return -1;

    const [m, n] = [grid.length, grid[0].length];
    const DIRS = [-1, 0, 1, 0, -1];
    const q = new MinPriorityQueue({ priority: ([x]) => x });
    const dist = Array.from({ length: m }, () => new Array(n).fill(Number.POSITIVE_INFINITY));
    dist[0][0] = 0;
    q.enqueue([0, 0, 0]);

    while (true) {
        const [t, i, j] = q.dequeue().element;
        if (i === m - 1 && j === n - 1) return t;

        for (let k = 0; k < 4; k++) {
            const [x, y] = [i + DIRS[k], j + DIRS[k + 1]];
            if (x < 0 || x >= m || y < 0 || y >= n) continue;

            let nt = t + 1;
            if (nt < grid[x][y]) {
                nt = grid[x][y] + ((grid[x][y] - nt) % 2);
            }
            if (nt < dist[x][y]) {
                dist[x][y] = nt;
                q.enqueue([nt, x, y]);
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

# [2578. 最小和分割](https://leetcode.cn/problems/split-with-minimum-sum){#2578}

{{< tabs "2578" >}}

{{% tab "python" %}}
```python
class Solution:
    def splitNum(self, num: int) -> int:
        s = sorted(str(num))
        return int(''.join(s[::2])) + int(''.join(s[1::2]))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int splitNum(int num) {
        char[] s = (num + "").toCharArray();
        Arrays.sort(s);
        int[] ans = new int[2];
        for (int i = 0; i < s.length; ++i) {
            ans[i & 1] = ans[i & 1] * 10 + s[i] - '0';
        }
        return ans[0] + ans[1];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int splitNum(int num) {
        string s = to_string(num);
        sort(s.begin(), s.end());
        int ans[2]{};
        for (int i = 0; i < s.size(); ++i) {
            ans[i & 1] = ans[i & 1] * 10 + s[i] - '0';
        }
        return ans[0] + ans[1];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func splitNum(num int) int {
	s := []byte(strconv.Itoa(num))
	sort.Slice(s, func(i, j int) bool { return s[i] < s[j] })
	ans := [2]int{}
	for i, c := range s {
		ans[i&1] = ans[i&1]*10 + int(c-'0')
	}
	return ans[0] + ans[1]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function splitNum(num: number): number {
    const s: string[] = String(num).split('');
    s.sort();
    const ans: number[] = Array(2).fill(0);
    for (let i = 0; i < s.length; ++i) {
        ans[i & 1] = ans[i & 1] * 10 + Number(s[i]);
    }
    return ans[0] + ans[1];
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn split_num(num: i32) -> i32 {
        let mut s = num.to_string().into_bytes();
        s.sort_unstable();

        let mut ans = vec![0; 2];
        for (i, c) in s.iter().enumerate() {
            ans[i & 1] = ans[i & 1] * 10 + ((c - b'0') as i32);
        }

        ans[0] + ans[1]
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个正整数&nbsp;<code>num</code>&nbsp;，请你将它分割成两个非负整数&nbsp;<code>num1</code> 和&nbsp;<code>num2</code>&nbsp;，满足：</p>

<ul>
	<li><code>num1</code> 和&nbsp;<code>num2</code>&nbsp;直接连起来，得到&nbsp;<code>num</code>&nbsp;各数位的一个排列。

    <ul>
    	<li>换句话说，<code>num1</code> 和&nbsp;<code>num2</code>&nbsp;中所有数字出现的次数之和等于&nbsp;<code>num</code>&nbsp;中所有数字出现的次数。</li>
    </ul>
    </li>
    <li><code>num1</code> 和&nbsp;<code>num2</code>&nbsp;可以包含前导 0 。</li>

</ul>

<p>请你返回&nbsp;<code>num1</code> 和 <code>num2</code>&nbsp;可以得到的和的 <strong>最小</strong> 值。</p>

<p><strong>注意：</strong></p>

<ul>
	<li><code>num</code>&nbsp;保证没有前导 0 。</li>
	<li><code>num1</code> 和&nbsp;<code>num2</code>&nbsp;中数位顺序可以与&nbsp;<code>num</code>&nbsp;中数位顺序不同。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>num = 4325
<b>输出：</b>59
<b>解释：</b>我们可以将 4325 分割成 <code>num1 </code>= 24 和 <code>num2 </code>= 35 ，和为 59 ，59 是最小和。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>num = 687
<b>输出：</b>75
<b>解释：</b>我们可以将 687 分割成 <code>num1</code> = 68 和 <code>num2 </code>= 7 ，和为最优值 75 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>10 &lt;= num &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数 + 贪心

我们先用哈希表或数组 $cnt$ 统计 $num$ 中各个数字出现的次数，用变量 $n$ 记录 $num$ 的位数。

接下来，枚举 $nums$ 所有位数 $i$，将 $cnt$ 中的数字按照从小到大的顺序交替地分配给 $num1$ 和 $num2$，记录在一个长度为 $2$ 的数组 $ans$ 中。最后，返回 $ans$ 中的两个数之和即可。

时间复杂度 $O(n)$，空间复杂度 $O(C)$。其中 $n$ 为 $num$ 的位数；而 $C$ 为 $num$ 中不同数字的个数，本题中 $C \leq 10$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def splitNum(self, num: int) -> int:
        cnt = Counter()
        n = 0
        while num:
            cnt[num % 10] += 1
            num //= 10
            n += 1
        ans = [0] * 2
        j = 0
        for i in range(n):
            while cnt[j] == 0:
                j += 1
            cnt[j] -= 1
            ans[i & 1] = ans[i & 1] * 10 + j
        return sum(ans)
```

#### Java

```java
class Solution {
    public int splitNum(int num) {
        int[] cnt = new int[10];
        int n = 0;
        for (; num > 0; num /= 10) {
            ++cnt[num % 10];
            ++n;
        }
        int[] ans = new int[2];
        for (int i = 0, j = 0; i < n; ++i) {
            while (cnt[j] == 0) {
                ++j;
            }
            --cnt[j];
            ans[i & 1] = ans[i & 1] * 10 + j;
        }
        return ans[0] + ans[1];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int splitNum(int num) {
        int cnt[10]{};
        int n = 0;
        for (; num; num /= 10) {
            ++cnt[num % 10];
            ++n;
        }
        int ans[2]{};
        for (int i = 0, j = 0; i < n; ++i) {
            while (cnt[j] == 0) {
                ++j;
            }
            --cnt[j];
            ans[i & 1] = ans[i & 1] * 10 + j;
        }
        return ans[0] + ans[1];
    }
};
```

#### Go

```go
func splitNum(num int) int {
	cnt := [10]int{}
	n := 0
	for ; num > 0; num /= 10 {
		cnt[num%10]++
		n++
	}
	ans := [2]int{}
	for i, j := 0, 0; i < n; i++ {
		for cnt[j] == 0 {
			j++
		}
		cnt[j]--
		ans[i&1] = ans[i&1]*10 + j
	}
	return ans[0] + ans[1]
}
```

#### TypeScript

```ts
function splitNum(num: number): number {
    const cnt: number[] = Array(10).fill(0);
    let n = 0;
    for (; num > 0; num = Math.floor(num / 10)) {
        ++cnt[num % 10];
        ++n;
    }
    const ans: number[] = Array(2).fill(0);
    for (let i = 0, j = 0; i < n; ++i) {
        while (cnt[j] === 0) {
            ++j;
        }
        --cnt[j];
        ans[i & 1] = ans[i & 1] * 10 + j;
    }
    return ans[0] + ans[1];
}
```

#### Rust

```rust
impl Solution {
    pub fn split_num(mut num: i32) -> i32 {
        let mut cnt = vec![0; 10];
        let mut n = 0;

        while num != 0 {
            cnt[(num as usize) % 10] += 1;
            num /= 10;
            n += 1;
        }

        let mut ans = vec![0; 2];
        let mut j = 0;
        for i in 0..n {
            while cnt[j] == 0 {
                j += 1;
            }
            cnt[j] -= 1;

            ans[i & 1] = ans[i & 1] * 10 + (j as i32);
        }

        ans[0] + ans[1]
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：排序 + 贪心

我们可以将 $num$ 转换成字符串或者字符数组，然后对其进行排序，接下来将排序后的数组中的数字按照从小到大的顺序交替地分配给 $num1$ 和 $num2$，最后返回 $num1$ 和 $num2$ 的和即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为 $num$ 的位数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def splitNum(self, num: int) -> int:
        s = sorted(str(num))
        return int(''.join(s[::2])) + int(''.join(s[1::2]))
```

#### Java

```java
class Solution {
    public int splitNum(int num) {
        char[] s = (num + "").toCharArray();
        Arrays.sort(s);
        int[] ans = new int[2];
        for (int i = 0; i < s.length; ++i) {
            ans[i & 1] = ans[i & 1] * 10 + s[i] - '0';
        }
        return ans[0] + ans[1];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int splitNum(int num) {
        string s = to_string(num);
        sort(s.begin(), s.end());
        int ans[2]{};
        for (int i = 0; i < s.size(); ++i) {
            ans[i & 1] = ans[i & 1] * 10 + s[i] - '0';
        }
        return ans[0] + ans[1];
    }
};
```

#### Go

```go
func splitNum(num int) int {
	s := []byte(strconv.Itoa(num))
	sort.Slice(s, func(i, j int) bool { return s[i] < s[j] })
	ans := [2]int{}
	for i, c := range s {
		ans[i&1] = ans[i&1]*10 + int(c-'0')
	}
	return ans[0] + ans[1]
}
```

#### TypeScript

```ts
function splitNum(num: number): number {
    const s: string[] = String(num).split('');
    s.sort();
    const ans: number[] = Array(2).fill(0);
    for (let i = 0; i < s.length; ++i) {
        ans[i & 1] = ans[i & 1] * 10 + Number(s[i]);
    }
    return ans[0] + ans[1];
}
```

#### Rust

```rust
impl Solution {
    pub fn split_num(num: i32) -> i32 {
        let mut s = num.to_string().into_bytes();
        s.sort_unstable();

        let mut ans = vec![0; 2];
        for (i, c) in s.iter().enumerate() {
            ans[i & 1] = ans[i & 1] * 10 + ((c - b'0') as i32);
        }

        ans[0] + ans[1]
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2579. 统计染色格子数](https://leetcode.cn/problems/count-total-number-of-colored-cells){#2579}

{{< tabs "2579" >}}

{{% tab "python" %}}
```python
class Solution:
    def coloredCells(self, n: int) -> int:
        return 2 * n * (n - 1) + 1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long coloredCells(int n) {
        return 2L * n * (n - 1) + 1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    long long coloredCells(int n) {
        return 2LL * n * (n - 1) + 1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func coloredCells(n int) int64 {
	return int64(2*n*(n-1) + 1)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function coloredCells(n: number): number {
    return 2 * n * (n - 1) + 1;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn colored_cells(n: i32) -> i64 {
        2 * (n as i64) * ((n as i64) - 1) + 1
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>有一个无穷大的二维网格图，一开始所有格子都未染色。给你一个正整数&nbsp;<code>n</code>&nbsp;，表示你需要执行以下步骤&nbsp;<code>n</code>&nbsp;分钟：</p>

<ul>
	<li>第一分钟，将 <strong>任一</strong> 格子染成蓝色。</li>
	<li>之后的每一分钟，将与蓝色格子相邻的 <strong>所有</strong> 未染色格子染成蓝色。</li>
</ul>

<p>下图分别是 1、2、3 分钟后的网格图。</p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2500-2599/2579.Count%20Total%20Number%20of%20Colored%20Cells/images/example-copy-2.png" style="width: 500px; height: 279px;">
<p>请你返回 <code>n</code>&nbsp;分钟之后 <strong>被染色的格子&nbsp;</strong>数目。</p>

<p>&nbsp;</p>

<p><b>示例 1：</b></p>

<pre><b>输入：</b>n = 1
<b>输出：</b>1
<b>解释：</b>1 分钟后，只有 1 个蓝色的格子，所以返回 1 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>n = 2
<b>输出：</b>5
<b>解释：</b>2 分钟后，有 4 个在边缘的蓝色格子和 1 个在中间的蓝色格子，所以返回 5 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数学

我们观察发现，第 $n$ 分钟后，网格中共有 $2 \times n - 1$ 列，每一列上的数字分别为 $1, 3, 5, \cdots, 2 \times n - 1, 2 \times n - 3, \cdots, 3, 1$。左右两部分均为等差数列，求和可以得到答案 $2 \times n \times (n - 1) + 1$。

时间复杂度 $O(1)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def coloredCells(self, n: int) -> int:
        return 2 * n * (n - 1) + 1
```

#### Java

```java
class Solution {
    public long coloredCells(int n) {
        return 2L * n * (n - 1) + 1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long coloredCells(int n) {
        return 2LL * n * (n - 1) + 1;
    }
};
```

#### Go

```go
func coloredCells(n int) int64 {
	return int64(2*n*(n-1) + 1)
}
```

#### TypeScript

```ts
function coloredCells(n: number): number {
    return 2 * n * (n - 1) + 1;
}
```

#### Rust

```rust
impl Solution {
    pub fn colored_cells(n: i32) -> i64 {
        2 * (n as i64) * ((n as i64) - 1) + 1
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
