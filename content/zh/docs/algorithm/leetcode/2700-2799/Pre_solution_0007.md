---
title: "2760_最长奇偶子数组"
date: 2025-10-08T18:39:33+08:00
weight: 7
tags: [二叉树, 动态规划, 单调队列, 哈希表, 回溯, 堆（优先队列）, 字符串, 排序, 数学, 数组, 数论, 有序集合, 枚举, 栈, 树, 模拟, 深度优先搜索, 滑动窗口, 队列]
---

{{< markmap >}}
### [2760_最长奇偶子数组](#2760)
#### [数组](#2760)
#### [滑动窗口](#2760)
### [2761_和等于目标值的质数对](#2761)
#### [数组](#2761)
#### [数学](#2761)
#### [枚举](#2761)
#### [数论](#2761)
### [2762_不间断子数组](#2762)
#### [队列](#2762)
#### [数组](#2762)
#### [有序集合](#2762)
#### [滑动窗口](#2762)
#### [单调队列](#2762)
#### [堆（优先队列）](#2762)
### [2763_所有子数组中不平衡数字之和](#2763)
#### [数组](#2763)
#### [哈希表](#2763)
#### [有序集合](#2763)
### [2764_数组是否表示某二叉树的前序遍历 🔒](#2764)
#### [栈](#2764)
#### [树](#2764)
#### [深度优先搜索](#2764)
#### [二叉树](#2764)
### [2765_最长交替子数组](#2765)
#### [数组](#2765)
#### [枚举](#2765)
### [2766_重新放置石块](#2766)
#### [数组](#2766)
#### [哈希表](#2766)
#### [排序](#2766)
#### [模拟](#2766)
### [2767_将字符串分割为最少的美丽子字符串](#2767)
#### [哈希表](#2767)
#### [字符串](#2767)
#### [动态规划](#2767)
#### [回溯](#2767)
### [2768_黑格子的数目](#2768)
#### [数组](#2768)
#### [哈希表](#2768)
#### [枚举](#2768)
### [2769_找出最大的可达成数字](#2769)
#### [数学](#2769)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2760_最长奇偶子数组
___
#### 数组
___
#### 滑动窗口
---
### 2761_和等于目标值的质数对
___
#### 数组
___
#### 数学
___
#### 枚举
___
#### 数论
---
### 2762_不间断子数组
___
#### 队列
___
#### 数组
___
#### 有序集合
___
#### 滑动窗口
___
#### 单调队列
___
#### 堆（优先队列）
---
### 2763_所有子数组中不平衡数字之和
___
#### 数组
___
#### 哈希表
___
#### 有序集合
---
### 2764_数组是否表示某二叉树的前序遍历 🔒
___
#### 栈
___
#### 树
___
#### 深度优先搜索
___
#### 二叉树
---
### 2765_最长交替子数组
___
#### 数组
___
#### 枚举
---
### 2766_重新放置石块
___
#### 数组
___
#### 哈希表
___
#### 排序
___
#### 模拟
---
### 2767_将字符串分割为最少的美丽子字符串
___
#### 哈希表
___
#### 字符串
___
#### 动态规划
___
#### 回溯
---
### 2768_黑格子的数目
___
#### 数组
___
#### 哈希表
___
#### 枚举
---
### 2769_找出最大的可达成数字
___
#### 数学
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二叉树 | 动态规划 | 单调队列 |
| 哈希表 | 回溯 | 堆（优先队列） |
| 字符串 | 排序 | 数学 |
| 数组 | 数论 | 有序集合 |
| 枚举 | 栈 | 树 |
| 模拟 | 深度优先搜索 | 滑动窗口 |
| 队列 |  |  |

# [2760. 最长奇偶子数组](https://leetcode.cn/problems/longest-even-odd-subarray-with-threshold){#2760}

{{< tabs "2760" >}}

{{% tab "python" %}}
```python
class Solution:
    def longestAlternatingSubarray(self, nums: List[int], threshold: int) -> int:
        ans, l, n = 0, 0, len(nums)
        while l < n:
            if nums[l] % 2 == 0 and nums[l] <= threshold:
                r = l + 1
                while r < n and nums[r] % 2 != nums[r - 1] % 2 and nums[r] <= threshold:
                    r += 1
                ans = max(ans, r - l)
                l = r
            else:
                l += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int longestAlternatingSubarray(int[] nums, int threshold) {
        int ans = 0;
        for (int l = 0, n = nums.length; l < n;) {
            if (nums[l] % 2 == 0 && nums[l] <= threshold) {
                int r = l + 1;
                while (r < n && nums[r] % 2 != nums[r - 1] % 2 && nums[r] <= threshold) {
                    ++r;
                }
                ans = Math.max(ans, r - l);
                l = r;
            } else {
                ++l;
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
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int ans = 0;
        for (int l = 0, n = nums.size(); l < n;) {
            if (nums[l] % 2 == 0 && nums[l] <= threshold) {
                int r = l + 1;
                while (r < n && nums[r] % 2 != nums[r - 1] % 2 && nums[r] <= threshold) {
                    ++r;
                }
                ans = max(ans, r - l);
                l = r;
            } else {
                ++l;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func longestAlternatingSubarray(nums []int, threshold int) (ans int) {
	for l, n := 0, len(nums); l < n; {
		if nums[l]%2 == 0 && nums[l] <= threshold {
			r := l + 1
			for r < n && nums[r]%2 != nums[r-1]%2 && nums[r] <= threshold {
				r++
			}
			ans = max(ans, r-l)
			l = r
		} else {
			l++
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function longestAlternatingSubarray(nums: number[], threshold: number): number {
    const n = nums.length;
    let ans = 0;
    for (let l = 0; l < n; ) {
        if (nums[l] % 2 === 0 && nums[l] <= threshold) {
            let r = l + 1;
            while (r < n && nums[r] % 2 !== nums[r - 1] % 2 && nums[r] <= threshold) {
                ++r;
            }
            ans = Math.max(ans, r - l);
            l = r;
        } else {
            ++l;
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

<p>给你一个下标从 <strong>0</strong> 开始的整数数组 <code>nums</code> 和一个整数 <code>threshold</code> 。</p>

<p>请你从 <code>nums</code> 的子数组中找出以下标 <code>l</code> 开头、下标 <code>r</code> 结尾 <code>(0 &lt;= l &lt;= r &lt; nums.length)</code> 且满足以下条件的 <strong>最长子数组</strong> ：</p>

<ul>
	<li><code>nums[l] % 2 == 0</code></li>
	<li>对于范围&nbsp;<code>[l, r - 1]</code> 内的所有下标 <code>i</code> ，<code>nums[i] % 2 != nums[i + 1] % 2</code></li>
	<li>对于范围&nbsp;<code>[l, r]</code> 内的所有下标 <code>i</code> ，<code>nums[i] &lt;= threshold</code></li>
</ul>

<p>以整数形式返回满足题目要求的最长子数组的长度。</p>

<p><strong>注意：子数组</strong> 是数组中的一个连续非空元素序列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [3,2,5,4], threshold = 5
<strong>输出：</strong>3
<strong>解释：</strong>在这个示例中，我们选择从 l = 1 开始、到 r = 3 结束的子数组 =&gt; [2,5,4] ，满足上述条件。
因此，答案就是这个子数组的长度 3 。可以证明 3 是满足题目要求的最大长度。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [1,2], threshold = 2
<strong>输出：</strong>1
<strong>解释：</strong>
在这个示例中，我们选择从 l = 1 开始、到 r = 1 结束的子数组 =&gt; [2] 。
该子数组满足上述全部条件。可以证明 1 是满足题目要求的最大长度。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>nums = [2,3,4,5], threshold = 4
<strong>输出：</strong>3
<strong>解释：</strong>
在这个示例中，我们选择从 l = 0 开始、到 r = 2 结束的子数组 =&gt; [2,3,4] 。 
该子数组满足上述全部条件。
因此，答案就是这个子数组的长度 3 。可以证明 3 是满足题目要求的最大长度。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100 </code></li>
	<li><code>1 &lt;= nums[i] &lt;= 100 </code></li>
	<li><code>1 &lt;= threshold &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举

我们在 $[0,..n-1]$ 范围内枚举所有 $l$，如果 $nums[l]$ 满足 $nums[l] \bmod 2 = 0$ 并且 $nums[l] \leq threshold$，那么我们就从 $l+1$ 开始，查找第一个不满足条件的 $r$，那么此时以 $nums[l]$ 作为左端点的最长奇偶子数组的长度为 $r - l$，取所有 $r - l$ 的最大值作为答案即可。

时间复杂度 $O(n^2)$，其中 $n$ 是数组 $nums$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def longestAlternatingSubarray(self, nums: List[int], threshold: int) -> int:
        ans, n = 0, len(nums)
        for l in range(n):
            if nums[l] % 2 == 0 and nums[l] <= threshold:
                r = l + 1
                while r < n and nums[r] % 2 != nums[r - 1] % 2 and nums[r] <= threshold:
                    r += 1
                ans = max(ans, r - l)
        return ans
```

#### Java

```java
class Solution {
    public int longestAlternatingSubarray(int[] nums, int threshold) {
        int ans = 0, n = nums.length;
        for (int l = 0; l < n; ++l) {
            if (nums[l] % 2 == 0 && nums[l] <= threshold) {
                int r = l + 1;
                while (r < n && nums[r] % 2 != nums[r - 1] % 2 && nums[r] <= threshold) {
                    ++r;
                }
                ans = Math.max(ans, r - l);
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
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int ans = 0, n = nums.size();
        for (int l = 0; l < n; ++l) {
            if (nums[l] % 2 == 0 && nums[l] <= threshold) {
                int r = l + 1;
                while (r < n && nums[r] % 2 != nums[r - 1] % 2 && nums[r] <= threshold) {
                    ++r;
                }
                ans = max(ans, r - l);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func longestAlternatingSubarray(nums []int, threshold int) (ans int) {
	n := len(nums)
	for l := range nums {
		if nums[l]%2 == 0 && nums[l] <= threshold {
			r := l + 1
			for r < n && nums[r]%2 != nums[r-1]%2 && nums[r] <= threshold {
				r++
			}
			ans = max(ans, r-l)
		}
	}
	return
}
```

#### TypeScript

```ts
function longestAlternatingSubarray(nums: number[], threshold: number): number {
    const n = nums.length;
    let ans = 0;
    for (let l = 0; l < n; ++l) {
        if (nums[l] % 2 === 0 && nums[l] <= threshold) {
            let r = l + 1;
            while (r < n && nums[r] % 2 !== nums[r - 1] % 2 && nums[r] <= threshold) {
                ++r;
            }
            ans = Math.max(ans, r - l);
        }
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：枚举优化

我们注意到，题目实际上会把数组划分成不相交的若干个满足条件的子数组，我们只需要找到这些子数组中最长的一个即可。因此，在枚举 $l$ 和 $r$ 时，我们不需要回退，只需要从左往右遍历一遍即可。

时间复杂度 $O(n)$，其中 $n$ 是数组 $nums$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def longestAlternatingSubarray(self, nums: List[int], threshold: int) -> int:
        ans, l, n = 0, 0, len(nums)
        while l < n:
            if nums[l] % 2 == 0 and nums[l] <= threshold:
                r = l + 1
                while r < n and nums[r] % 2 != nums[r - 1] % 2 and nums[r] <= threshold:
                    r += 1
                ans = max(ans, r - l)
                l = r
            else:
                l += 1
        return ans
```

#### Java

```java
class Solution {
    public int longestAlternatingSubarray(int[] nums, int threshold) {
        int ans = 0;
        for (int l = 0, n = nums.length; l < n;) {
            if (nums[l] % 2 == 0 && nums[l] <= threshold) {
                int r = l + 1;
                while (r < n && nums[r] % 2 != nums[r - 1] % 2 && nums[r] <= threshold) {
                    ++r;
                }
                ans = Math.max(ans, r - l);
                l = r;
            } else {
                ++l;
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
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int ans = 0;
        for (int l = 0, n = nums.size(); l < n;) {
            if (nums[l] % 2 == 0 && nums[l] <= threshold) {
                int r = l + 1;
                while (r < n && nums[r] % 2 != nums[r - 1] % 2 && nums[r] <= threshold) {
                    ++r;
                }
                ans = max(ans, r - l);
                l = r;
            } else {
                ++l;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func longestAlternatingSubarray(nums []int, threshold int) (ans int) {
	for l, n := 0, len(nums); l < n; {
		if nums[l]%2 == 0 && nums[l] <= threshold {
			r := l + 1
			for r < n && nums[r]%2 != nums[r-1]%2 && nums[r] <= threshold {
				r++
			}
			ans = max(ans, r-l)
			l = r
		} else {
			l++
		}
	}
	return
}
```

#### TypeScript

```ts
function longestAlternatingSubarray(nums: number[], threshold: number): number {
    const n = nums.length;
    let ans = 0;
    for (let l = 0; l < n; ) {
        if (nums[l] % 2 === 0 && nums[l] <= threshold) {
            let r = l + 1;
            while (r < n && nums[r] % 2 !== nums[r - 1] % 2 && nums[r] <= threshold) {
                ++r;
            }
            ans = Math.max(ans, r - l);
            l = r;
        } else {
            ++l;
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

# [2761. 和等于目标值的质数对](https://leetcode.cn/problems/prime-pairs-with-target-sum){#2761}

{{< tabs "2761" >}}

{{% tab "python" %}}
```python
class Solution:
    def findPrimePairs(self, n: int) -> List[List[int]]:
        primes = [True] * n
        for i in range(2, n):
            if primes[i]:
                for j in range(i + i, n, i):
                    primes[j] = False
        ans = []
        for x in range(2, n // 2 + 1):
            y = n - x
            if primes[x] and primes[y]:
                ans.append([x, y])
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<List<Integer>> findPrimePairs(int n) {
        boolean[] primes = new boolean[n];
        Arrays.fill(primes, true);
        for (int i = 2; i < n; ++i) {
            if (primes[i]) {
                for (int j = i + i; j < n; j += i) {
                    primes[j] = false;
                }
            }
        }
        List<List<Integer>> ans = new ArrayList<>();
        for (int x = 2; x <= n / 2; ++x) {
            int y = n - x;
            if (primes[x] && primes[y]) {
                ans.add(List.of(x, y));
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
    vector<vector<int>> findPrimePairs(int n) {
        bool primes[n];
        memset(primes, true, sizeof(primes));
        for (int i = 2; i < n; ++i) {
            if (primes[i]) {
                for (int j = i + i; j < n; j += i) {
                    primes[j] = false;
                }
            }
        }
        vector<vector<int>> ans;
        for (int x = 2; x <= n / 2; ++x) {
            int y = n - x;
            if (primes[x] && primes[y]) {
                ans.push_back({x, y});
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findPrimePairs(n int) (ans [][]int) {
	primes := make([]bool, n)
	for i := range primes {
		primes[i] = true
	}
	for i := 2; i < n; i++ {
		if primes[i] {
			for j := i + i; j < n; j += i {
				primes[j] = false
			}
		}
	}
	for x := 2; x <= n/2; x++ {
		y := n - x
		if primes[x] && primes[y] {
			ans = append(ans, []int{x, y})
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findPrimePairs(n: number): number[][] {
    const primes: boolean[] = new Array(n).fill(true);
    for (let i = 2; i < n; ++i) {
        if (primes[i]) {
            for (let j = i + i; j < n; j += i) {
                primes[j] = false;
            }
        }
    }
    const ans: number[][] = [];
    for (let x = 2; x <= n / 2; ++x) {
        const y = n - x;
        if (primes[x] && primes[y]) {
            ans.push([x, y]);
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

<p>给你一个整数 <code>n</code> 。如果两个整数 <code>x</code> 和 <code>y</code> 满足下述条件，则认为二者形成一个质数对：</p>

<ul>
	<li><code>1 &lt;= x &lt;= y &lt;= n</code></li>
	<li><code>x + y == n</code></li>
	<li><code>x</code> 和 <code>y</code> 都是质数</li>
</ul>

<p>请你以二维有序列表的形式返回符合题目要求的所有 <code>[x<sub>i</sub>, y<sub>i</sub>]</code> ，列表需要按 <code>x<sub>i</sub></code> 的 <strong>非递减顺序</strong> 排序。如果不存在符合要求的质数对，则返回一个空数组。</p>

<p><strong>注意：</strong>质数是大于 <code>1</code> 的自然数，并且只有两个因子，即它本身和 <code>1</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>n = 10
<strong>输出：</strong>[[3,7],[5,5]]
<strong>解释：</strong>在这个例子中，存在满足条件的两个质数对。 
这两个质数对分别是 [3,7] 和 [5,5]，按照题面描述中的方式排序后返回。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>n = 2
<strong>输出：</strong>[]
<strong>解释：</strong>可以证明不存在和为 2 的质数对，所以返回一个空数组。 
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

### 方法一：预处理 + 枚举

我们先预处理出 $n$ 范围内的所有质数，记录在数组 $primes$ 中，其中 $primes[i]$ 为 `true` 表示 $i$ 是一个质数。

接下来，我们在 $[2, \frac{n}{2}]$ 的范围内枚举 $x$，那么 $y = n - x$，如果 $primes[x]$ 和 $primes[y]$ 均为 `true`，那么 $(x, y)$ 是一个质数对，添加到答案中。

枚举结束后，返回答案即可。

时间复杂度 $O(n \log \log n)$，空间复杂度 $O(n)$。其中 $n$ 是题目给定的数字。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findPrimePairs(self, n: int) -> List[List[int]]:
        primes = [True] * n
        for i in range(2, n):
            if primes[i]:
                for j in range(i + i, n, i):
                    primes[j] = False
        ans = []
        for x in range(2, n // 2 + 1):
            y = n - x
            if primes[x] and primes[y]:
                ans.append([x, y])
        return ans
```

#### Java

```java
class Solution {
    public List<List<Integer>> findPrimePairs(int n) {
        boolean[] primes = new boolean[n];
        Arrays.fill(primes, true);
        for (int i = 2; i < n; ++i) {
            if (primes[i]) {
                for (int j = i + i; j < n; j += i) {
                    primes[j] = false;
                }
            }
        }
        List<List<Integer>> ans = new ArrayList<>();
        for (int x = 2; x <= n / 2; ++x) {
            int y = n - x;
            if (primes[x] && primes[y]) {
                ans.add(List.of(x, y));
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
    vector<vector<int>> findPrimePairs(int n) {
        bool primes[n];
        memset(primes, true, sizeof(primes));
        for (int i = 2; i < n; ++i) {
            if (primes[i]) {
                for (int j = i + i; j < n; j += i) {
                    primes[j] = false;
                }
            }
        }
        vector<vector<int>> ans;
        for (int x = 2; x <= n / 2; ++x) {
            int y = n - x;
            if (primes[x] && primes[y]) {
                ans.push_back({x, y});
            }
        }
        return ans;
    }
};
```

#### Go

```go
func findPrimePairs(n int) (ans [][]int) {
	primes := make([]bool, n)
	for i := range primes {
		primes[i] = true
	}
	for i := 2; i < n; i++ {
		if primes[i] {
			for j := i + i; j < n; j += i {
				primes[j] = false
			}
		}
	}
	for x := 2; x <= n/2; x++ {
		y := n - x
		if primes[x] && primes[y] {
			ans = append(ans, []int{x, y})
		}
	}
	return
}
```

#### TypeScript

```ts
function findPrimePairs(n: number): number[][] {
    const primes: boolean[] = new Array(n).fill(true);
    for (let i = 2; i < n; ++i) {
        if (primes[i]) {
            for (let j = i + i; j < n; j += i) {
                primes[j] = false;
            }
        }
    }
    const ans: number[][] = [];
    for (let x = 2; x <= n / 2; ++x) {
        const y = n - x;
        if (primes[x] && primes[y]) {
            ans.push([x, y]);
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

# [2762. 不间断子数组](https://leetcode.cn/problems/continuous-subarrays){#2762}

{{< tabs "2762" >}}

{{% tab "python" %}}
```python
class Solution:
    def continuousSubarrays(self, nums: List[int]) -> int:
        ans = i = 0
        sl = SortedList()
        for x in nums:
            sl.add(x)
            while sl[-1] - sl[0] > 2:
                sl.remove(nums[i])
                i += 1
            ans += len(sl)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long continuousSubarrays(int[] nums) {
        long ans = 0;
        int i = 0, n = nums.length;
        TreeMap<Integer, Integer> tm = new TreeMap<>();
        for (int j = 0; j < n; ++j) {
            tm.merge(nums[j], 1, Integer::sum);
            while (tm.lastEntry().getKey() - tm.firstEntry().getKey() > 2) {
                tm.merge(nums[i], -1, Integer::sum);
                if (tm.get(nums[i]) == 0) {
                    tm.remove(nums[i]);
                }
                ++i;
            }
            ans += j - i + 1;
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
    long long continuousSubarrays(vector<int>& nums) {
        long long ans = 0;
        int i = 0, n = nums.size();
        multiset<int> s;
        for (int j = 0; j < n; ++j) {
            s.insert(nums[j]);
            while (*s.rbegin() - *s.begin() > 2) {
                s.erase(s.find(nums[i++]));
            }
            ans += j - i + 1;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func continuousSubarrays(nums []int) (ans int64) {
	i := 0
	tm := treemap.NewWithIntComparator()
	for j, x := range nums {
		if v, ok := tm.Get(x); ok {
			tm.Put(x, v.(int)+1)
		} else {
			tm.Put(x, 1)
		}
		for {
			a, _ := tm.Min()
			b, _ := tm.Max()
			if b.(int)-a.(int) > 2 {
				if v, _ := tm.Get(nums[i]); v.(int) == 1 {
					tm.Remove(nums[i])
				} else {
					tm.Put(nums[i], v.(int)-1)
				}
				i++
			} else {
				break
			}
		}
		ans += int64(j - i + 1)
	}
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function continuousSubarrays(nums: number[]): number {
    const [minQ, maxQ]: [number[], number[]] = [[], []];
    const n = nums.length;
    let res = 0;

    for (let r = 0, l = 0; r < n; r++) {
        const x = nums[r];
        while (minQ.length && nums[minQ.at(-1)!] > x) minQ.pop();
        while (maxQ.length && nums[maxQ.at(-1)!] < x) maxQ.pop();
        minQ.push(r);
        maxQ.push(r);

        while (minQ.length && maxQ.length && nums[maxQ[0]] - nums[minQ[0]] > 2) {
            if (maxQ[0] < minQ[0]) {
                l = maxQ[0] + 1;
                maxQ.shift();
            } else {
                l = minQ[0] + 1;
                minQ.shift();
            }
        }

        res += r - l + 1;
    }

    return res;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
function continuousSubarrays(nums) {
    const [minQ, maxQ] = [[], []];
    const n = nums.length;
    let res = 0;

    for (let r = 0, l = 0; r < n; r++) {
        const x = nums[r];
        while (minQ.length && nums[minQ.at(-1)] > x) minQ.pop();
        while (maxQ.length && nums[maxQ.at(-1)] < x) maxQ.pop();
        minQ.push(r);
        maxQ.push(r);

        while (minQ.length && maxQ.length && nums[maxQ[0]] - nums[minQ[0]] > 2) {
            if (maxQ[0] < minQ[0]) {
                l = maxQ[0] + 1;
                maxQ.shift();
            } else {
                l = minQ[0] + 1;
                minQ.shift();
            }
        }

        res += r - l + 1;
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

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>nums</code>&nbsp;。<code>nums</code>&nbsp;的一个子数组如果满足以下条件，那么它是 <strong>不间断</strong> 的：</p>

<ul>
	<li><code>i</code>，<code>i + 1</code>&nbsp;，...，<code>j</code><sub> </sub>&nbsp;表示子数组中的下标。对于所有满足&nbsp;<code>i &lt;= i<sub>1</sub>, i<sub>2</sub> &lt;= j</code>&nbsp;的下标对，都有 <code>0 &lt;= |nums[i<sub>1</sub>] - nums[i<sub>2</sub>]| &lt;= 2</code>&nbsp;。</li>
</ul>

<p>请你返回 <strong>不间断</strong> 子数组的总数目。</p>

<p>子数组是一个数组中一段连续 <strong>非空</strong>&nbsp;的元素序列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [5,4,2,4]
<strong>输出：</strong>8
<b>解释：</b>
大小为 1 的不间断子数组：[5], [4], [2], [4] 。
大小为 2 的不间断子数组：[5,4], [4,2], [2,4] 。
大小为 3 的不间断子数组：[4,2,4] 。
没有大小为 4 的不间断子数组。
不间断子数组的总数目为 4 + 3 + 1 = 8 。
除了这些以外，没有别的不间断子数组。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [1,2,3]
<b>输出：</b>6
<b>解释：</b>
大小为 1 的不间断子数组：[1], [2], [3] 。
大小为 2 的不间断子数组：[1,2], [2,3] 。
大小为 3 的不间断子数组：[1,2,3] 。
不间断子数组的总数目为 3 + 2 + 1 = 6 。
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

### 方法一：有序列表 + 双指针

我们可以用双指针 $i$ 和 $j$ 维护当前子数组的左右端点，用一个有序列表维护当前子数组的所有元素。

遍历数组 $nums$，对于当前遍历到的数字 $nums[i]$，我们将其加到有序列表中，如果此时有序列表中的最大值与最小值的差值大于 $2$，那么我们循环右移指针 $i$，不断将 $nums[i]$ 从有序列表中移出，直到列表为空或者有序列表元素的最大差值不大于 $2$。此时不间断的子数组数目为 $j - i + 1$，我们将其添加到答案中。

遍历结束，返回答案即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def continuousSubarrays(self, nums: List[int]) -> int:
        ans = i = 0
        sl = SortedList()
        for x in nums:
            sl.add(x)
            while sl[-1] - sl[0] > 2:
                sl.remove(nums[i])
                i += 1
            ans += len(sl)
        return ans
```

#### Java

```java
class Solution {
    public long continuousSubarrays(int[] nums) {
        long ans = 0;
        int i = 0, n = nums.length;
        TreeMap<Integer, Integer> tm = new TreeMap<>();
        for (int j = 0; j < n; ++j) {
            tm.merge(nums[j], 1, Integer::sum);
            while (tm.lastEntry().getKey() - tm.firstEntry().getKey() > 2) {
                tm.merge(nums[i], -1, Integer::sum);
                if (tm.get(nums[i]) == 0) {
                    tm.remove(nums[i]);
                }
                ++i;
            }
            ans += j - i + 1;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long ans = 0;
        int i = 0, n = nums.size();
        multiset<int> s;
        for (int j = 0; j < n; ++j) {
            s.insert(nums[j]);
            while (*s.rbegin() - *s.begin() > 2) {
                s.erase(s.find(nums[i++]));
            }
            ans += j - i + 1;
        }
        return ans;
    }
};
```

#### Go

```go
func continuousSubarrays(nums []int) (ans int64) {
	i := 0
	tm := treemap.NewWithIntComparator()
	for j, x := range nums {
		if v, ok := tm.Get(x); ok {
			tm.Put(x, v.(int)+1)
		} else {
			tm.Put(x, 1)
		}
		for {
			a, _ := tm.Min()
			b, _ := tm.Max()
			if b.(int)-a.(int) > 2 {
				if v, _ := tm.Get(nums[i]); v.(int) == 1 {
					tm.Remove(nums[i])
				} else {
					tm.Put(nums[i], v.(int)-1)
				}
				i++
			} else {
				break
			}
		}
		ans += int64(j - i + 1)
	}
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：单调队列 + 双指针

<!-- tabs:start -->

#### TypeScript

```ts
function continuousSubarrays(nums: number[]): number {
    const [minQ, maxQ]: [number[], number[]] = [[], []];
    const n = nums.length;
    let res = 0;

    for (let r = 0, l = 0; r < n; r++) {
        const x = nums[r];
        while (minQ.length && nums[minQ.at(-1)!] > x) minQ.pop();
        while (maxQ.length && nums[maxQ.at(-1)!] < x) maxQ.pop();
        minQ.push(r);
        maxQ.push(r);

        while (minQ.length && maxQ.length && nums[maxQ[0]] - nums[minQ[0]] > 2) {
            if (maxQ[0] < minQ[0]) {
                l = maxQ[0] + 1;
                maxQ.shift();
            } else {
                l = minQ[0] + 1;
                minQ.shift();
            }
        }

        res += r - l + 1;
    }

    return res;
}
```

#### JavaScript

```js
function continuousSubarrays(nums) {
    const [minQ, maxQ] = [[], []];
    const n = nums.length;
    let res = 0;

    for (let r = 0, l = 0; r < n; r++) {
        const x = nums[r];
        while (minQ.length && nums[minQ.at(-1)] > x) minQ.pop();
        while (maxQ.length && nums[maxQ.at(-1)] < x) maxQ.pop();
        minQ.push(r);
        maxQ.push(r);

        while (minQ.length && maxQ.length && nums[maxQ[0]] - nums[minQ[0]] > 2) {
            if (maxQ[0] < minQ[0]) {
                l = maxQ[0] + 1;
                maxQ.shift();
            } else {
                l = minQ[0] + 1;
                minQ.shift();
            }
        }

        res += r - l + 1;
    }

    return res;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2763. 所有子数组中不平衡数字之和](https://leetcode.cn/problems/sum-of-imbalance-numbers-of-all-subarrays){#2763}

{{< tabs "2763" >}}

{{% tab "python" %}}
```python
class Solution:
    def sumImbalanceNumbers(self, nums: List[int]) -> int:
        n = len(nums)
        ans = 0
        for i in range(n):
            sl = SortedList()
            cnt = 0
            for j in range(i, n):
                k = sl.bisect_left(nums[j])
                h = k - 1
                if h >= 0 and nums[j] - sl[h] > 1:
                    cnt += 1
                if k < len(sl) and sl[k] - nums[j] > 1:
                    cnt += 1
                if h >= 0 and k < len(sl) and sl[k] - sl[h] > 1:
                    cnt -= 1
                sl.add(nums[j])
                ans += cnt
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int sumImbalanceNumbers(int[] nums) {
        int n = nums.length;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            TreeMap<Integer, Integer> tm = new TreeMap<>();
            int cnt = 0;
            for (int j = i; j < n; ++j) {
                Integer k = tm.ceilingKey(nums[j]);
                if (k != null && k - nums[j] > 1) {
                    ++cnt;
                }
                Integer h = tm.floorKey(nums[j]);
                if (h != null && nums[j] - h > 1) {
                    ++cnt;
                }
                if (h != null && k != null && k - h > 1) {
                    --cnt;
                }
                tm.merge(nums[j], 1, Integer::sum);
                ans += cnt;
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
    int sumImbalanceNumbers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            multiset<int> s;
            int cnt = 0;
            for (int j = i; j < n; ++j) {
                auto it = s.lower_bound(nums[j]);
                if (it != s.end() && *it - nums[j] > 1) {
                    ++cnt;
                }
                if (it != s.begin() && nums[j] - *prev(it) > 1) {
                    ++cnt;
                }
                if (it != s.end() && it != s.begin() && *it - *prev(it) > 1) {
                    --cnt;
                }
                s.insert(nums[j]);
                ans += cnt;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>一个长度为 <code>n</code>&nbsp;下标从 <strong>0</strong>&nbsp;开始的整数数组 <code>arr</code>&nbsp;的 <strong>不平衡数字</strong>&nbsp;定义为，在&nbsp;<code>sarr = sorted(arr)</code>&nbsp;数组中，满足以下条件的下标数目：</p>

<ul>
	<li><code>0 &lt;= i &lt; n - 1</code>&nbsp;，和</li>
	<li><code>sarr[i+1] - sarr[i] &gt; 1</code></li>
</ul>

<p>这里，<code>sorted(arr)</code>&nbsp;表示将数组 <code>arr</code>&nbsp;排序后得到的数组。</p>

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>nums</code>&nbsp;，请你返回它所有&nbsp;<strong>子数组</strong>&nbsp;的&nbsp;<strong>不平衡数字</strong>&nbsp;之和。</p>

<p>子数组指的是一个数组中连续一段 <strong>非空</strong>&nbsp;的元素序列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [2,3,1,4]
<b>输出：</b>3
<b>解释：</b>总共有 3 个子数组有非 0 不平衡数字：
- 子数组 [3, 1] ，不平衡数字为 1 。
- 子数组 [3, 1, 4] ，不平衡数字为 1 。
- 子数组 [1, 4] ，不平衡数字为 1 。
其他所有子数组的不平衡数字都是 0 ，所以所有子数组的不平衡数字之和为 3 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [1,3,3,3,5]
<b>输出：</b>8
<b>解释：</b>总共有 7 个子数组有非 0 不平衡数字：
- 子数组 [1, 3] ，不平衡数字为 1 。
- 子数组 [1, 3, 3] ，不平衡数字为 1 。
- 子数组 [1, 3, 3, 3] ，不平衡数字为 1 。
- 子数组 [1, 3, 3, 3, 5] ，不平衡数字为 2 。
- 子数组 [3, 3, 3, 5] ，不平衡数字为 1 。
- 子数组 [3, 3, 5] ，不平衡数字为 1 。
- 子数组 [3, 5] ，不平衡数字为 1 。
其他所有子数组的不平衡数字都是 0 ，所以所有子数组的不平衡数字之和为 8 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= nums.length</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举 + 有序集合

我们可以先枚举子数组的左端点 $i$，对于每个 $i$，我们从小到大枚举子数组的右端点 $j$，并且用一个有序列表维护当前子数组中的所有元素，用一个变量 $cnt$ 维护当前子数组的不平衡数字。

对于每个数字 $nums[j]$，我们在有序列表中找到第一个大于等于 $nums[j]$ 的元素 $nums[k]$，以及最后一个小于 $nums[j]$ 的元素 $nums[h]$：

-   如果 $nums[k]$ 存在，并且 $nums[k]$ 与 $nums[j]$ 的差值大于 $1$，那么不平衡数字加 $1$；
-   如果 $nums[h]$ 存在，并且 $nums[j]$ 与 $nums[h]$ 的差值大于 $1$，那么不平衡数字加 $1$；
-   如果 $nums[k]$ 存在，并且 $nums[h]$ 存在，那么将元素 $nums[j]$ 插入 $nums[h]$ 和 $nums[k]$ 的中间，会使得平衡数字减 $1$。

然后，我们将当前子数组的平衡数字累加到答案中，继续遍历，直到遍历完所有子数组。

时间复杂度 $O(n^2 \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def sumImbalanceNumbers(self, nums: List[int]) -> int:
        n = len(nums)
        ans = 0
        for i in range(n):
            sl = SortedList()
            cnt = 0
            for j in range(i, n):
                k = sl.bisect_left(nums[j])
                h = k - 1
                if h >= 0 and nums[j] - sl[h] > 1:
                    cnt += 1
                if k < len(sl) and sl[k] - nums[j] > 1:
                    cnt += 1
                if h >= 0 and k < len(sl) and sl[k] - sl[h] > 1:
                    cnt -= 1
                sl.add(nums[j])
                ans += cnt
        return ans
```

#### Java

```java
class Solution {
    public int sumImbalanceNumbers(int[] nums) {
        int n = nums.length;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            TreeMap<Integer, Integer> tm = new TreeMap<>();
            int cnt = 0;
            for (int j = i; j < n; ++j) {
                Integer k = tm.ceilingKey(nums[j]);
                if (k != null && k - nums[j] > 1) {
                    ++cnt;
                }
                Integer h = tm.floorKey(nums[j]);
                if (h != null && nums[j] - h > 1) {
                    ++cnt;
                }
                if (h != null && k != null && k - h > 1) {
                    --cnt;
                }
                tm.merge(nums[j], 1, Integer::sum);
                ans += cnt;
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
    int sumImbalanceNumbers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            multiset<int> s;
            int cnt = 0;
            for (int j = i; j < n; ++j) {
                auto it = s.lower_bound(nums[j]);
                if (it != s.end() && *it - nums[j] > 1) {
                    ++cnt;
                }
                if (it != s.begin() && nums[j] - *prev(it) > 1) {
                    ++cnt;
                }
                if (it != s.end() && it != s.begin() && *it - *prev(it) > 1) {
                    --cnt;
                }
                s.insert(nums[j]);
                ans += cnt;
            }
        }
        return ans;
    }
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2764. 数组是否表示某二叉树的前序遍历 🔒](https://leetcode.cn/problems/is-array-a-preorder-of-some-binary-tree){#2764}

{{< tabs "2764" >}}

{{% tab "python" %}}
```python
class Solution:
    def isPreorder(self, nodes: List[List[int]]) -> bool:
        def dfs(i: int) -> int:
            nonlocal k
            if i != nodes[k][0]:
                return False
            k += 1
            return all(dfs(j) for j in g[i])

        g = defaultdict(list)
        for i, p in nodes:
            g[p].append(i)
        k = 0
        return dfs(nodes[0][0]) and k == len(nodes)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private Map<Integer, List<Integer>> g = new HashMap<>();
    private List<List<Integer>> nodes;
    private int k;

    public boolean isPreorder(List<List<Integer>> nodes) {
        this.nodes = nodes;
        for (var node : nodes) {
            g.computeIfAbsent(node.get(1), key -> new ArrayList<>()).add(node.get(0));
        }
        return dfs(nodes.get(0).get(0)) && k == nodes.size();
    }

    private boolean dfs(int i) {
        if (i != nodes.get(k).get(0)) {
            return false;
        }
        ++k;
        for (int j : g.getOrDefault(i, List.of())) {
            if (!dfs(j)) {
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
    bool isPreorder(vector<vector<int>>& nodes) {
        int k = 0;
        unordered_map<int, vector<int>> g;
        for (auto& node : nodes) {
            g[node[1]].push_back(node[0]);
        }
        function<bool(int)> dfs = [&](int i) {
            if (i != nodes[k][0]) {
                return false;
            }
            ++k;
            for (int j : g[i]) {
                if (!dfs(j)) {
                    return false;
                }
            }
            return true;
        };
        return dfs(nodes[0][0]) && k == nodes.size();
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func isPreorder(nodes [][]int) bool {
	k := 0
	g := map[int][]int{}
	for _, node := range nodes {
		g[node[1]] = append(g[node[1]], node[0])
	}
	var dfs func(int) bool
	dfs = func(i int) bool {
		if i != nodes[k][0] {
			return false
		}
		k++
		for _, j := range g[i] {
			if !dfs(j) {
				return false
			}
		}
		return true
	}
	return dfs(nodes[0][0]) && k == len(nodes)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function isPreorder(nodes: number[][]): boolean {
    let k = 0;
    const g: Map<number, number[]> = new Map();
    for (const [i, p] of nodes) {
        if (!g.has(p)) {
            g.set(p, []);
        }
        g.get(p)!.push(i);
    }
    const dfs = (i: number): boolean => {
        if (i !== nodes[k][0]) {
            return false;
        }
        ++k;
        for (const j of g.get(i) ?? []) {
            if (!dfs(j)) {
                return false;
            }
        }
        return true;
    };
    return dfs(nodes[0][0]) && k === nodes.length;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个以 <strong>0</strong> 为起始索引的整数 <strong>二维数组</strong> <code>nodes</code> ，你的任务是确定给定的数组是否表示某个 <strong>二叉</strong> 树的 <strong>前序</strong> 遍历。</p>

<p>对于每个索引 <code>i</code> ，<code>nodes[i] = [id, parentId]</code> ，其中 <code>id</code> 是索引 <code>i</code> 处节点的 id，<code>parentId</code> 是其在树中的父节点 id（如果该节点没有父节点，则 <code>parentId = -1</code> ）。</p>

<p>如果给定的数组表示某个树的前序遍历，则返回 <code>true</code> ，否则返回 <code>false</code> 。</p>

<p><strong>注意</strong>：树的 <strong>前序</strong> 遍历是一种递归的遍历方式，它首先访问当前节点，然后对左子节点进行前序遍历，最后对右子节点进行前序遍历。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>nodes = [[0,-1],[1,0],[2,0],[3,2],[4,2]]
<b>输出：</b>true
<b>解释：</b>给定的 nodes 数组可以构成下面图片中的树。 
我们可以验证这是树的前序遍历，首先访问节点 0，然后对左子节点进行前序遍历，即 [1] ，然后对右子节点进行前序遍历，即 [2,3,4] 。
</pre>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2700-2799/2764.Is%20Array%20a%20Preorder%20of%20Some%20%E2%80%8CBinary%20Tree/images/1.png" style="padding: 10px; background: #fff; border-radius: .5rem; width: 250px; height: 251px;" /></p>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>nodes = [[0,-1],[1,0],[2,0],[3,1],[4,1]]
<b>输出：</b>false
<b>解释：</b>给定的 nodes 数组可以构成下面图片中的树。 
对于前序遍历，首先访问节点 0，然后对左子节点进行前序遍历，即 [1,3,4]，但是我们可以看到在给定的顺序中，2 位于 1 和 3 之间，因此它不是树的前序遍历。
</pre>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2700-2799/2764.Is%20Array%20a%20Preorder%20of%20Some%20%E2%80%8CBinary%20Tree/images/2.png" style="padding: 10px; background: #fff; border-radius: .5rem; width: 250px; height: 251px;" /></p>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nodes.length &lt;= 10<sup>5</sup></code></li>
	<li><code>nodes[i].length == 2</code></li>
	<li><code>0 &lt;= nodes[i][0] &lt;= 10<sup>5</sup></code></li>
	<li><code>-1 &lt;= nodes[i][1] &lt;= 10<sup>5</sup></code></li>
	<li>生成的输入保证 <code>nodes</code> 可以组成二叉树。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS

我们先根据 $nodes$ 数据构建图 $g$，其中 $g[i]$ 表示节点 $i$ 的所有子节点。

接下来，设计一个函数 $dfs(i)$，表示从节点 $i$ 开始进行先序遍历，用一个变量 $k$ 表示当前遍历到 $nodes$ 列表的第 $k$ 个节点，初始时 $k=0$。

函数 $dfs(i)$ 的执行逻辑如下：

-   如果 $i \neq nodes[k][0]$，说明当前序列不是二叉树的先序遍历序列，返回 `false`。
-   否则，我们将 $k$ 加 $1$，然后递归搜索 $i$ 的所有子节点，如果搜索过程中发现 `false`，那么提前返回 `false`，否则搜索结束，返回 `true`。

在主函数中，我们调用 $dfs(nodes[0][0])$，如果返回值为 `true`，并且 $k = |nodes|$，那么 $nodes$ 序列是二叉树的先序遍历序列，返回 `true`，否则返回 `false`。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是 $nodes$ 中的节点数目。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def isPreorder(self, nodes: List[List[int]]) -> bool:
        def dfs(i: int) -> int:
            nonlocal k
            if i != nodes[k][0]:
                return False
            k += 1
            return all(dfs(j) for j in g[i])

        g = defaultdict(list)
        for i, p in nodes:
            g[p].append(i)
        k = 0
        return dfs(nodes[0][0]) and k == len(nodes)
```

#### Java

```java
class Solution {
    private Map<Integer, List<Integer>> g = new HashMap<>();
    private List<List<Integer>> nodes;
    private int k;

    public boolean isPreorder(List<List<Integer>> nodes) {
        this.nodes = nodes;
        for (var node : nodes) {
            g.computeIfAbsent(node.get(1), key -> new ArrayList<>()).add(node.get(0));
        }
        return dfs(nodes.get(0).get(0)) && k == nodes.size();
    }

    private boolean dfs(int i) {
        if (i != nodes.get(k).get(0)) {
            return false;
        }
        ++k;
        for (int j : g.getOrDefault(i, List.of())) {
            if (!dfs(j)) {
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
    bool isPreorder(vector<vector<int>>& nodes) {
        int k = 0;
        unordered_map<int, vector<int>> g;
        for (auto& node : nodes) {
            g[node[1]].push_back(node[0]);
        }
        function<bool(int)> dfs = [&](int i) {
            if (i != nodes[k][0]) {
                return false;
            }
            ++k;
            for (int j : g[i]) {
                if (!dfs(j)) {
                    return false;
                }
            }
            return true;
        };
        return dfs(nodes[0][0]) && k == nodes.size();
    }
};
```

#### Go

```go
func isPreorder(nodes [][]int) bool {
	k := 0
	g := map[int][]int{}
	for _, node := range nodes {
		g[node[1]] = append(g[node[1]], node[0])
	}
	var dfs func(int) bool
	dfs = func(i int) bool {
		if i != nodes[k][0] {
			return false
		}
		k++
		for _, j := range g[i] {
			if !dfs(j) {
				return false
			}
		}
		return true
	}
	return dfs(nodes[0][0]) && k == len(nodes)
}
```

#### TypeScript

```ts
function isPreorder(nodes: number[][]): boolean {
    let k = 0;
    const g: Map<number, number[]> = new Map();
    for (const [i, p] of nodes) {
        if (!g.has(p)) {
            g.set(p, []);
        }
        g.get(p)!.push(i);
    }
    const dfs = (i: number): boolean => {
        if (i !== nodes[k][0]) {
            return false;
        }
        ++k;
        for (const j of g.get(i) ?? []) {
            if (!dfs(j)) {
                return false;
            }
        }
        return true;
    };
    return dfs(nodes[0][0]) && k === nodes.length;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2765. 最长交替子数组](https://leetcode.cn/problems/longest-alternating-subarray){#2765}

{{< tabs "2765" >}}

{{% tab "python" %}}
```python
class Solution:
    def alternatingSubarray(self, nums: List[int]) -> int:
        ans, n = -1, len(nums)
        for i in range(n):
            k = 1
            j = i
            while j + 1 < n and nums[j + 1] - nums[j] == k:
                j += 1
                k *= -1
            if j - i + 1 > 1:
                ans = max(ans, j - i + 1)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int alternatingSubarray(int[] nums) {
        int ans = -1, n = nums.length;
        for (int i = 0; i < n; ++i) {
            int k = 1;
            int j = i;
            for (; j + 1 < n && nums[j + 1] - nums[j] == k; ++j) {
                k *= -1;
            }
            if (j - i + 1 > 1) {
                ans = Math.max(ans, j - i + 1);
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
    int alternatingSubarray(vector<int>& nums) {
        int ans = -1, n = nums.size();
        for (int i = 0; i < n; ++i) {
            int k = 1;
            int j = i;
            for (; j + 1 < n && nums[j + 1] - nums[j] == k; ++j) {
                k *= -1;
            }
            if (j - i + 1 > 1) {
                ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func alternatingSubarray(nums []int) int {
	ans, n := -1, len(nums)
	for i := range nums {
		k := 1
		j := i
		for ; j+1 < n && nums[j+1]-nums[j] == k; j++ {
			k *= -1
		}
		if t := j - i + 1; t > 1 && ans < t {
			ans = t
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function alternatingSubarray(nums: number[]): number {
    let ans = -1;
    const n = nums.length;
    for (let i = 0; i < n; ++i) {
        let k = 1;
        let j = i;
        for (; j + 1 < n && nums[j + 1] - nums[j] === k; ++j) {
            k *= -1;
        }
        if (j - i + 1 > 1) {
            ans = Math.max(ans, j - i + 1);
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

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>nums</code>&nbsp;。如果 <code>nums</code>&nbsp;中长度为&nbsp;<code>m</code>&nbsp;的子数组&nbsp;<code>s</code>&nbsp;满足以下条件，我们称它是一个 <strong>交替子数组</strong> ：</p>

<ul>
	<li><code>m</code>&nbsp;大于&nbsp;<code>1</code>&nbsp;。</li>
	<li><code>s<sub>1</sub> = s<sub>0</sub> + 1</code>&nbsp;。</li>
	<li>下标从 <strong>0</strong> 开始的子数组&nbsp;<code>s</code>&nbsp;与数组&nbsp;<code>[s<sub>0</sub>, s<sub>1</sub>, s<sub>0</sub>, s<sub>1</sub>,...,s<sub>(m-1) % 2</sub>]</code>&nbsp;一样。也就是说，<code>s<sub>1</sub> - s<sub>0</sub> = 1</code>&nbsp;，<code>s<sub>2</sub> - s<sub>1</sub> = -1</code>&nbsp;，<code>s<sub>3</sub> - s<sub>2</sub> = 1</code>&nbsp;，<code>s<sub>4</sub> - s<sub>3</sub> = -1</code>&nbsp;，以此类推，直到&nbsp;<code>s[m - 1] - s[m - 2] = (-1)<sup>m</sup></code>&nbsp;。</li>
</ul>

<p>请你返回 <code>nums</code>&nbsp;中所有 <strong>交替</strong>&nbsp;子数组中，最长的长度，如果不存在交替子数组，请你返回 <code>-1</code>&nbsp;。</p>

<p>子数组是一个数组中一段连续 <strong>非空</strong>&nbsp;的元素序列。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block"><b>输入：</b>nums = [2,3,4,3,4]</div>

<div class="example-block"><b>输出：</b>4</div>

<div class="example-block"><b>解释：</b>交替子数组有 <code>[2,3]</code>，<code>[3,4]</code>，<code>[3,4,3]</code> 和 <code>[3,4,3,4]</code>。最长的子数组为 <code>[3,4,3,4]</code>，长度为 4。</div>

<p>&nbsp;</p>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block"><b>输入：</b>nums = [4,5,6]</div>

<div class="example-block"><b>输出：</b>2</div>

<div class="example-block"><strong>解释：</strong><code>[4,5]</code> 和 <code>[5,6]</code> 是仅有的两个交替子数组。它们长度都为 2 。</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举

我们可以枚举子数组的左端点 $i$，对于每个 $i$，我们需要找到最长的满足条件的子数组。我们可以从 $i$ 开始向右遍历，每次遇到相邻元素差值不满足交替条件时，我们就找到了一个满足条件的子数组。我们可以用一个变量 $k$ 来记录当前元素的差值应该是 $1$ 还是 $-1$，如果当前元素的差值应该是 $-k$，那么我们就将 $k$ 取反。当我们找到一个满足条件的子数组 $nums[i..j]$ 时，我们更新答案为 $\max(ans, j - i + 1)$。

时间复杂度 $O(n^2)$，其中 $n$ 是数组的长度。我们需要枚举子数组的左端点 $i$，对于每个 $i$，我们需要 $O(n)$ 的时间来找到最长的满足条件的子数组。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def alternatingSubarray(self, nums: List[int]) -> int:
        ans, n = -1, len(nums)
        for i in range(n):
            k = 1
            j = i
            while j + 1 < n and nums[j + 1] - nums[j] == k:
                j += 1
                k *= -1
            if j - i + 1 > 1:
                ans = max(ans, j - i + 1)
        return ans
```

#### Java

```java
class Solution {
    public int alternatingSubarray(int[] nums) {
        int ans = -1, n = nums.length;
        for (int i = 0; i < n; ++i) {
            int k = 1;
            int j = i;
            for (; j + 1 < n && nums[j + 1] - nums[j] == k; ++j) {
                k *= -1;
            }
            if (j - i + 1 > 1) {
                ans = Math.max(ans, j - i + 1);
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
    int alternatingSubarray(vector<int>& nums) {
        int ans = -1, n = nums.size();
        for (int i = 0; i < n; ++i) {
            int k = 1;
            int j = i;
            for (; j + 1 < n && nums[j + 1] - nums[j] == k; ++j) {
                k *= -1;
            }
            if (j - i + 1 > 1) {
                ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func alternatingSubarray(nums []int) int {
	ans, n := -1, len(nums)
	for i := range nums {
		k := 1
		j := i
		for ; j+1 < n && nums[j+1]-nums[j] == k; j++ {
			k *= -1
		}
		if t := j - i + 1; t > 1 && ans < t {
			ans = t
		}
	}
	return ans
}
```

#### TypeScript

```ts
function alternatingSubarray(nums: number[]): number {
    let ans = -1;
    const n = nums.length;
    for (let i = 0; i < n; ++i) {
        let k = 1;
        let j = i;
        for (; j + 1 < n && nums[j + 1] - nums[j] === k; ++j) {
            k *= -1;
        }
        if (j - i + 1 > 1) {
            ans = Math.max(ans, j - i + 1);
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

# [2766. 重新放置石块](https://leetcode.cn/problems/relocate-marbles){#2766}

{{< tabs "2766" >}}

{{% tab "python" %}}
```python
class Solution:
    def relocateMarbles(
        self, nums: List[int], moveFrom: List[int], moveTo: List[int]
    ) -> List[int]:
        pos = set(nums)
        for f, t in zip(moveFrom, moveTo):
            pos.remove(f)
            pos.add(t)
        return sorted(pos)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<Integer> relocateMarbles(int[] nums, int[] moveFrom, int[] moveTo) {
        Set<Integer> pos = new HashSet<>();
        for (int x : nums) {
            pos.add(x);
        }
        for (int i = 0; i < moveFrom.length; ++i) {
            pos.remove(moveFrom[i]);
            pos.add(moveTo[i]);
        }
        List<Integer> ans = new ArrayList<>(pos);
        ans.sort((a, b) -> a - b);
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        unordered_set<int> pos(nums.begin(), nums.end());
        for (int i = 0; i < moveFrom.size(); ++i) {
            pos.erase(moveFrom[i]);
            pos.insert(moveTo[i]);
        }
        vector<int> ans(pos.begin(), pos.end());
        sort(ans.begin(), ans.end());
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func relocateMarbles(nums []int, moveFrom []int, moveTo []int) (ans []int) {
	pos := map[int]bool{}
	for _, x := range nums {
		pos[x] = true
	}
	for i, f := range moveFrom {
		t := moveTo[i]
		pos[f] = false
		pos[t] = true
	}
	for x, ok := range pos {
		if ok {
			ans = append(ans, x)
		}
	}
	sort.Ints(ans)
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function relocateMarbles(nums: number[], moveFrom: number[], moveTo: number[]): number[] {
    const pos: Set<number> = new Set(nums);
    for (let i = 0; i < moveFrom.length; i++) {
        pos.delete(moveFrom[i]);
        pos.add(moveTo[i]);
    }
    return [...pos].sort((a, b) => a - b);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>nums</code>&nbsp;，表示一些石块的初始位置。再给你两个长度<strong>&nbsp;相等</strong>&nbsp;下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>moveFrom</code> 和&nbsp;<code>moveTo</code>&nbsp;。</p>

<p>在&nbsp;<code>moveFrom.length</code>&nbsp;次操作内，你将改变石块的位置。在第&nbsp;<code>i</code>&nbsp;次操作中，你将位置在&nbsp;<code>moveFrom[i]</code>&nbsp;的所有石块移到位置&nbsp;<code>moveTo[i]</code>&nbsp;。</p>

<p>完成这些操作后，请你按升序返回所有 <strong>有</strong>&nbsp;石块的位置。</p>

<p><strong>注意：</strong></p>

<ul>
	<li>如果一个位置至少有一个石块，我们称这个位置 <strong>有</strong>&nbsp;石块。</li>
	<li>一个位置可能会有多个石块。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [1,6,7,8], moveFrom = [1,7,2], moveTo = [2,9,5]
<b>输出：</b>[5,6,8,9]
<b>解释：</b>一开始，石块在位置 1,6,7,8 。
第 i = 0 步操作中，我们将位置 1 处的石块移到位置 2 处，位置 2,6,7,8 有石块。
第 i = 1 步操作中，我们将位置 7 处的石块移到位置 9 处，位置 2,6,8,9 有石块。
第 i = 2 步操作中，我们将位置 2 处的石块移到位置 5 处，位置 5,6,8,9 有石块。
最后，至少有一个石块的位置为 [5,6,8,9] 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,1,3,3], moveFrom = [1,3], moveTo = [2,2]
<b>输出：</b>[2]
<b>解释：</b>一开始，石块在位置 [1,1,3,3] 。
第 i = 0 步操作中，我们将位置 1 处的石块移到位置 2 处，有石块的位置为 [2,2,3,3] 。
第 i = 1 步操作中，我们将位置 3 处的石块移到位置 2 处，有石块的位置为 [2,2,2,2] 。
由于 2 是唯一有石块的位置，我们返回 [2] 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= moveFrom.length &lt;= 10<sup>5</sup></code></li>
	<li><code>moveFrom.length == moveTo.length</code></li>
	<li><code>1 &lt;= nums[i], moveFrom[i], moveTo[i] &lt;= 10<sup>9</sup></code></li>
	<li>测试数据保证在进行第&nbsp;<code>i</code>&nbsp;步操作时，<code>moveFrom[i]</code>&nbsp;处至少有一个石块。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

我们用一个哈希表 $pos$ 记录所有有石块的位置，初始时 $pos$ 中包含 $nums$ 中的所有元素。然后我们遍历 $moveFrom$ 和 $moveTo$，每次将 $moveFrom[i]$ 从 $pos$ 中移除，再将 $moveTo[i]$ 添加到 $pos$ 中。最后我们将 $pos$ 中的元素排序后返回即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def relocateMarbles(
        self, nums: List[int], moveFrom: List[int], moveTo: List[int]
    ) -> List[int]:
        pos = set(nums)
        for f, t in zip(moveFrom, moveTo):
            pos.remove(f)
            pos.add(t)
        return sorted(pos)
```

#### Java

```java
class Solution {
    public List<Integer> relocateMarbles(int[] nums, int[] moveFrom, int[] moveTo) {
        Set<Integer> pos = new HashSet<>();
        for (int x : nums) {
            pos.add(x);
        }
        for (int i = 0; i < moveFrom.length; ++i) {
            pos.remove(moveFrom[i]);
            pos.add(moveTo[i]);
        }
        List<Integer> ans = new ArrayList<>(pos);
        ans.sort((a, b) -> a - b);
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        unordered_set<int> pos(nums.begin(), nums.end());
        for (int i = 0; i < moveFrom.size(); ++i) {
            pos.erase(moveFrom[i]);
            pos.insert(moveTo[i]);
        }
        vector<int> ans(pos.begin(), pos.end());
        sort(ans.begin(), ans.end());
        return ans;
    }
};
```

#### Go

```go
func relocateMarbles(nums []int, moveFrom []int, moveTo []int) (ans []int) {
	pos := map[int]bool{}
	for _, x := range nums {
		pos[x] = true
	}
	for i, f := range moveFrom {
		t := moveTo[i]
		pos[f] = false
		pos[t] = true
	}
	for x, ok := range pos {
		if ok {
			ans = append(ans, x)
		}
	}
	sort.Ints(ans)
	return
}
```

#### TypeScript

```ts
function relocateMarbles(nums: number[], moveFrom: number[], moveTo: number[]): number[] {
    const pos: Set<number> = new Set(nums);
    for (let i = 0; i < moveFrom.length; i++) {
        pos.delete(moveFrom[i]);
        pos.add(moveTo[i]);
    }
    return [...pos].sort((a, b) => a - b);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2767. 将字符串分割为最少的美丽子字符串](https://leetcode.cn/problems/partition-string-into-minimum-beautiful-substrings){#2767}

{{< tabs "2767" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumBeautifulSubstrings(self, s: str) -> int:
        @cache
        def dfs(i: int) -> int:
            if i >= n:
                return 0
            if s[i] == "0":
                return inf
            x = 0
            ans = inf
            for j in range(i, n):
                x = x << 1 | int(s[j])
                if x in ss:
                    ans = min(ans, 1 + dfs(j + 1))
            return ans

        n = len(s)
        x = 1
        ss = {x}
        for i in range(n):
            x *= 5
            ss.add(x)
        ans = dfs(0)
        return -1 if ans == inf else ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private Integer[] f;
    private String s;
    private Set<Long> ss = new HashSet<>();
    private int n;

    public int minimumBeautifulSubstrings(String s) {
        n = s.length();
        this.s = s;
        f = new Integer[n];
        long x = 1;
        for (int i = 0; i <= n; ++i) {
            ss.add(x);
            x *= 5;
        }
        int ans = dfs(0);
        return ans > n ? -1 : ans;
    }

    private int dfs(int i) {
        if (i >= n) {
            return 0;
        }
        if (s.charAt(i) == '0') {
            return n + 1;
        }
        if (f[i] != null) {
            return f[i];
        }
        long x = 0;
        int ans = n + 1;
        for (int j = i; j < n; ++j) {
            x = x << 1 | (s.charAt(j) - '0');
            if (ss.contains(x)) {
                ans = Math.min(ans, 1 + dfs(j + 1));
            }
        }
        return f[i] = ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minimumBeautifulSubstrings(string s) {
        unordered_set<long long> ss;
        int n = s.size();
        long long x = 1;
        for (int i = 0; i <= n; ++i) {
            ss.insert(x);
            x *= 5;
        }
        int f[n];
        memset(f, -1, sizeof(f));
        function<int(int)> dfs = [&](int i) {
            if (i >= n) {
                return 0;
            }
            if (s[i] == '0') {
                return n + 1;
            }
            if (f[i] != -1) {
                return f[i];
            }
            long long x = 0;
            int ans = n + 1;
            for (int j = i; j < n; ++j) {
                x = x << 1 | (s[j] - '0');
                if (ss.count(x)) {
                    ans = min(ans, 1 + dfs(j + 1));
                }
            }
            return f[i] = ans;
        };
        int ans = dfs(0);
        return ans > n ? -1 : ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumBeautifulSubstrings(s string) int {
	ss := map[int]bool{}
	n := len(s)
	x := 1
	f := make([]int, n+1)
	for i := 0; i <= n; i++ {
		ss[x] = true
		x *= 5
		f[i] = -1
	}
	var dfs func(int) int
	dfs = func(i int) int {
		if i >= n {
			return 0
		}
		if s[i] == '0' {
			return n + 1
		}
		if f[i] != -1 {
			return f[i]
		}
		f[i] = n + 1
		x := 0
		for j := i; j < n; j++ {
			x = x<<1 | int(s[j]-'0')
			if ss[x] {
				f[i] = min(f[i], 1+dfs(j+1))
			}
		}
		return f[i]
	}
	ans := dfs(0)
	if ans > n {
		return -1
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumBeautifulSubstrings(s: string): number {
    const ss: Set<number> = new Set();
    const n = s.length;
    const f: number[] = new Array(n).fill(-1);
    for (let i = 0, x = 1; i <= n; ++i) {
        ss.add(x);
        x *= 5;
    }
    const dfs = (i: number): number => {
        if (i === n) {
            return 0;
        }
        if (s[i] === '0') {
            return n + 1;
        }
        if (f[i] !== -1) {
            return f[i];
        }
        f[i] = n + 1;
        for (let j = i, x = 0; j < n; ++j) {
            x = (x << 1) | (s[j] === '1' ? 1 : 0);
            if (ss.has(x)) {
                f[i] = Math.min(f[i], 1 + dfs(j + 1));
            }
        }
        return f[i];
    };
    const ans = dfs(0);
    return ans > n ? -1 : ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个二进制字符串&nbsp;<code>s</code>&nbsp;，你需要将字符串分割成一个或者多个&nbsp;<strong>子字符串</strong>&nbsp;&nbsp;，使每个子字符串都是 <strong>美丽</strong>&nbsp;的。</p>

<p>如果一个字符串满足以下条件，我们称它是 <strong>美丽</strong>&nbsp;的：</p>

<ul>
	<li>它不包含前导 0 。</li>
	<li>它是 <code>5</code>&nbsp;的幂的 <strong>二进制</strong>&nbsp;表示。</li>
</ul>

<p>请你返回分割后的子字符串的 <strong>最少</strong>&nbsp;数目。如果无法将字符串&nbsp;<code>s</code>&nbsp;分割成美丽子字符串，请你返回 <code>-1</code>&nbsp;。</p>

<p>子字符串是一个字符串中一段连续的字符序列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>s = "1011"
<b>输出：</b>2
<b>解释：</b>我们可以将输入字符串分成 ["101", "1"] 。
- 字符串 "101" 不包含前导 0 ，且它是整数 5<sup>1</sup> = 5 的二进制表示。
- 字符串 "1" 不包含前导 0 ，且它是整数 5<sup>0</sup> = 1 的二进制表示。
最少可以将 s 分成 2 个美丽子字符串。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>s = "111"
<b>输出：</b>3
<b>解释：</b>我们可以将输入字符串分成 ["1", "1", "1"] 。
- 字符串 "1" 不包含前导 0 ，且它是整数 5<sup>0</sup> = 1 的二进制表示。
最少可以将 s 分成 3 个美丽子字符串。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>s = "0"
<b>输出：</b>-1
<b>解释：</b>无法将给定字符串分成任何美丽子字符串。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 15</code></li>
	<li><code>s[i]</code>&nbsp;要么是&nbsp;<code>'0'</code>&nbsp;要么是&nbsp;<code>'1'</code> 。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

题目中需要判断一个字符串是否是 $5$ 的幂的二进制表示，因此，我们不妨先预处理出所有 $5$ 的幂的数字，记录在哈希表 $ss$ 中。

接下来，我们设计一个函数 $dfs(i)$，表示从字符串 $s$ 的第 $i$ 个字符开始，到字符串末尾的最少分割次数。那么答案就是 $dfs(0)$。

函数 $dfs(i)$ 的计算方法如下：

-   如果 $i \geq n$，表示已经处理完了所有字符，那么答案就是 $0$；
-   如果 $s[i] = 0$，表示当前字符串包含前导 $0$，不符合美丽字符串的定义，因此答案是无穷大；
-   否则，我们从 $i$ 开始枚举子字符串的结束位置 $j$，用 $x$ 表示子字符串 $s[i..j]$ 的十进制值，如果 $x$ 在哈希表 $ss$ 中，那么我们就可以将 $s[i..j]$ 作为一个美丽子字符串，此时答案就是 $1 + dfs(j + 1)$。我们需要枚举所有可能的 $j$，并取所有答案中的最小值。

为了避免重复计算，我们可以使用记忆化搜索的方法。

在主函数中，我们首先预处理出所有 $5$ 的幂的数字，然后调用 $dfs(0)$，如果返回值为无穷大，那么说明无法将字符串 $s$ 分割成美丽子字符串，答案返回 $-1$，否则返回 $dfs(0)$ 的值。

时间复杂度 $O(n^2)$，空间复杂度 $O(n)$。其中 $n$ 是字符串 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumBeautifulSubstrings(self, s: str) -> int:
        @cache
        def dfs(i: int) -> int:
            if i >= n:
                return 0
            if s[i] == "0":
                return inf
            x = 0
            ans = inf
            for j in range(i, n):
                x = x << 1 | int(s[j])
                if x in ss:
                    ans = min(ans, 1 + dfs(j + 1))
            return ans

        n = len(s)
        x = 1
        ss = {x}
        for i in range(n):
            x *= 5
            ss.add(x)
        ans = dfs(0)
        return -1 if ans == inf else ans
```

#### Java

```java
class Solution {
    private Integer[] f;
    private String s;
    private Set<Long> ss = new HashSet<>();
    private int n;

    public int minimumBeautifulSubstrings(String s) {
        n = s.length();
        this.s = s;
        f = new Integer[n];
        long x = 1;
        for (int i = 0; i <= n; ++i) {
            ss.add(x);
            x *= 5;
        }
        int ans = dfs(0);
        return ans > n ? -1 : ans;
    }

    private int dfs(int i) {
        if (i >= n) {
            return 0;
        }
        if (s.charAt(i) == '0') {
            return n + 1;
        }
        if (f[i] != null) {
            return f[i];
        }
        long x = 0;
        int ans = n + 1;
        for (int j = i; j < n; ++j) {
            x = x << 1 | (s.charAt(j) - '0');
            if (ss.contains(x)) {
                ans = Math.min(ans, 1 + dfs(j + 1));
            }
        }
        return f[i] = ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumBeautifulSubstrings(string s) {
        unordered_set<long long> ss;
        int n = s.size();
        long long x = 1;
        for (int i = 0; i <= n; ++i) {
            ss.insert(x);
            x *= 5;
        }
        int f[n];
        memset(f, -1, sizeof(f));
        function<int(int)> dfs = [&](int i) {
            if (i >= n) {
                return 0;
            }
            if (s[i] == '0') {
                return n + 1;
            }
            if (f[i] != -1) {
                return f[i];
            }
            long long x = 0;
            int ans = n + 1;
            for (int j = i; j < n; ++j) {
                x = x << 1 | (s[j] - '0');
                if (ss.count(x)) {
                    ans = min(ans, 1 + dfs(j + 1));
                }
            }
            return f[i] = ans;
        };
        int ans = dfs(0);
        return ans > n ? -1 : ans;
    }
};
```

#### Go

```go
func minimumBeautifulSubstrings(s string) int {
	ss := map[int]bool{}
	n := len(s)
	x := 1
	f := make([]int, n+1)
	for i := 0; i <= n; i++ {
		ss[x] = true
		x *= 5
		f[i] = -1
	}
	var dfs func(int) int
	dfs = func(i int) int {
		if i >= n {
			return 0
		}
		if s[i] == '0' {
			return n + 1
		}
		if f[i] != -1 {
			return f[i]
		}
		f[i] = n + 1
		x := 0
		for j := i; j < n; j++ {
			x = x<<1 | int(s[j]-'0')
			if ss[x] {
				f[i] = min(f[i], 1+dfs(j+1))
			}
		}
		return f[i]
	}
	ans := dfs(0)
	if ans > n {
		return -1
	}
	return ans
}
```

#### TypeScript

```ts
function minimumBeautifulSubstrings(s: string): number {
    const ss: Set<number> = new Set();
    const n = s.length;
    const f: number[] = new Array(n).fill(-1);
    for (let i = 0, x = 1; i <= n; ++i) {
        ss.add(x);
        x *= 5;
    }
    const dfs = (i: number): number => {
        if (i === n) {
            return 0;
        }
        if (s[i] === '0') {
            return n + 1;
        }
        if (f[i] !== -1) {
            return f[i];
        }
        f[i] = n + 1;
        for (let j = i, x = 0; j < n; ++j) {
            x = (x << 1) | (s[j] === '1' ? 1 : 0);
            if (ss.has(x)) {
                f[i] = Math.min(f[i], 1 + dfs(j + 1));
            }
        }
        return f[i];
    };
    const ans = dfs(0);
    return ans > n ? -1 : ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2768. 黑格子的数目](https://leetcode.cn/problems/number-of-black-blocks){#2768}

{{< tabs "2768" >}}

{{% tab "python" %}}
```python
class Solution:
    def countBlackBlocks(
        self, m: int, n: int, coordinates: List[List[int]]
    ) -> List[int]:
        cnt = Counter()
        for x, y in coordinates:
            for a, b in pairwise((0, 0, -1, -1, 0)):
                i, j = x + a, y + b
                if 0 <= i < m - 1 and 0 <= j < n - 1:
                    cnt[(i, j)] += 1
        ans = [0] * 5
        for x in cnt.values():
            ans[x] += 1
        ans[0] = (m - 1) * (n - 1) - len(cnt.values())
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long[] countBlackBlocks(int m, int n, int[][] coordinates) {
        Map<Long, Integer> cnt = new HashMap<>(coordinates.length);
        int[] dirs = {0, 0, -1, -1, 0};
        for (var e : coordinates) {
            int x = e[0], y = e[1];
            for (int k = 0; k < 4; ++k) {
                int i = x + dirs[k], j = y + dirs[k + 1];
                if (i >= 0 && i < m - 1 && j >= 0 && j < n - 1) {
                    cnt.merge(1L * i * n + j, 1, Integer::sum);
                }
            }
        }
        long[] ans = new long[5];
        ans[0] = (m - 1L) * (n - 1);
        for (int x : cnt.values()) {
            ++ans[x];
            --ans[0];
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
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coordinates) {
        unordered_map<long long, int> cnt;
        int dirs[5] = {0, 0, -1, -1, 0};
        for (auto& e : coordinates) {
            int x = e[0], y = e[1];
            for (int k = 0; k < 4; ++k) {
                int i = x + dirs[k], j = y + dirs[k + 1];
                if (i >= 0 && i < m - 1 && j >= 0 && j < n - 1) {
                    ++cnt[1LL * i * n + j];
                }
            }
        }
        vector<long long> ans(5);
        ans[0] = (m - 1LL) * (n - 1);
        for (auto& [_, x] : cnt) {
            ++ans[x];
            --ans[0];
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countBlackBlocks(m int, n int, coordinates [][]int) []int64 {
	cnt := map[int64]int{}
	dirs := [5]int{0, 0, -1, -1, 0}
	for _, e := range coordinates {
		x, y := e[0], e[1]
		for k := 0; k < 4; k++ {
			i, j := x+dirs[k], y+dirs[k+1]
			if i >= 0 && i < m-1 && j >= 0 && j < n-1 {
				cnt[int64(i*n+j)]++
			}
		}
	}
	ans := make([]int64, 5)
	ans[0] = int64((m - 1) * (n - 1))
	for _, x := range cnt {
		ans[x]++
		ans[0]--
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countBlackBlocks(m: number, n: number, coordinates: number[][]): number[] {
    const cnt: Map<number, number> = new Map();
    const dirs: number[] = [0, 0, -1, -1, 0];
    for (const [x, y] of coordinates) {
        for (let k = 0; k < 4; ++k) {
            const [i, j] = [x + dirs[k], y + dirs[k + 1]];
            if (i >= 0 && i < m - 1 && j >= 0 && j < n - 1) {
                const key = i * n + j;
                cnt.set(key, (cnt.get(key) || 0) + 1);
            }
        }
    }
    const ans: number[] = Array(5).fill(0);
    ans[0] = (m - 1) * (n - 1);
    for (const [_, x] of cnt) {
        ++ans[x];
        --ans[0];
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

<p>给你两个整数&nbsp;<code>m</code> 和&nbsp;<code>n</code>&nbsp;，表示一个下标从 <strong>0</strong>&nbsp;开始的&nbsp;<code>m x n</code>&nbsp;的网格图。</p>

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的二维整数矩阵&nbsp;<code>coordinates</code>&nbsp;，其中&nbsp;<code>coordinates[i] = [x, y]</code>&nbsp;表示坐标为&nbsp;<code>[x, y]</code>&nbsp;的格子是 <strong>黑色的</strong>&nbsp;，所有没出现在&nbsp;<code>coordinates</code>&nbsp;中的格子都是 <strong>白色的</strong>。</p>

<p>一个块定义为网格图中&nbsp;<code>2 x 2</code>&nbsp;的一个子矩阵。更正式的，对于左上角格子为 <code>[x, y]</code> 的块，其中 <code>0 &lt;= x &lt; m - 1</code> 且&nbsp;<code>0 &lt;= y &lt; n - 1</code> ，包含坐标为&nbsp;<code>[x, y]</code>&nbsp;，<code>[x + 1, y]</code>&nbsp;，<code>[x, y + 1]</code>&nbsp;和&nbsp;<code>[x + 1, y + 1]</code>&nbsp;的格子。</p>

<p>请你返回一个下标从 <strong>0</strong>&nbsp;开始长度为 <code>5</code>&nbsp;的整数数组&nbsp;<code>arr</code>&nbsp;，<code>arr[i]</code>&nbsp;表示恰好包含&nbsp;<code>i</code>&nbsp;个&nbsp;<strong>黑色</strong>&nbsp;格子的块的数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>m = 3, n = 3, coordinates = [[0,0]]
<b>输出：</b>[3,1,0,0,0]
<b>解释：</b>网格图如下：
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2700-2799/2768.Number%20of%20Black%20Blocks/images/screen-shot-2023-06-18-at-44656-am.png" style="width: 150px; height: 128px;" />
只有 1 个块有一个黑色格子，这个块是左上角为 [0,0] 的块。
其他 3 个左上角分别为 [0,1] ，[1,0] 和 [1,1] 的块都有 0 个黑格子。
所以我们返回 [3,1,0,0,0] 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>m = 3, n = 3, coordinates = [[0,0],[1,1],[0,2]]
<b>输出：</b>[0,2,2,0,0]
<b>解释：</b>网格图如下：
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2700-2799/2768.Number%20of%20Black%20Blocks/images/screen-shot-2023-06-18-at-45018-am.png" style="width: 150px; height: 128px;" />
有 2 个块有 2 个黑色格子（左上角格子分别为 [0,0] 和 [0,1]）。
左上角为 [1,0] 和 [1,1] 的两个块，都有 1 个黑格子。
所以我们返回 [0,2,2,0,0] 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= m &lt;= 10<sup>5</sup></code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= coordinates.length &lt;= 10<sup>4</sup></code></li>
	<li><code>coordinates[i].length == 2</code></li>
	<li><code>0 &lt;= coordinates[i][0] &lt; m</code></li>
	<li><code>0 &lt;= coordinates[i][1] &lt; n</code></li>
	<li><code>coordinates</code>&nbsp;中的坐标对两两互不相同。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表计数

对于每个 $2 \times 2$ 的子矩阵，我们可以用其左上角的坐标 $(x, y)$ 来表示它。

而对于每个黑格子 $(x, y)$，它对 $4$ 个子矩阵的贡献为 $1$，即矩阵 $(x - 1, y - 1)$, $(x - 1, y)$, $(x, y - 1)$, $(x, y)$。

因此，我们遍历所有的黑格子，然后累计每个子矩阵中黑格子的个数，记录在哈希表 $cnt$ 中。

最后，我们遍历 $cnt$ 中的所有值（大于 $0$），统计其出现的次数，记录在答案数组 $ans$ 中，而 $ans[0]$ 则表示没有黑格子的子矩阵的个数，值为 $(m - 1) \times (n - 1) - \sum_{i = 1}^4 ans[i]$。

时间复杂度 $O(l)$，空间复杂度 $O(l)$，其中 $l$ 为 $coordinates$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countBlackBlocks(
        self, m: int, n: int, coordinates: List[List[int]]
    ) -> List[int]:
        cnt = Counter()
        for x, y in coordinates:
            for a, b in pairwise((0, 0, -1, -1, 0)):
                i, j = x + a, y + b
                if 0 <= i < m - 1 and 0 <= j < n - 1:
                    cnt[(i, j)] += 1
        ans = [0] * 5
        for x in cnt.values():
            ans[x] += 1
        ans[0] = (m - 1) * (n - 1) - len(cnt.values())
        return ans
```

#### Java

```java
class Solution {
    public long[] countBlackBlocks(int m, int n, int[][] coordinates) {
        Map<Long, Integer> cnt = new HashMap<>(coordinates.length);
        int[] dirs = {0, 0, -1, -1, 0};
        for (var e : coordinates) {
            int x = e[0], y = e[1];
            for (int k = 0; k < 4; ++k) {
                int i = x + dirs[k], j = y + dirs[k + 1];
                if (i >= 0 && i < m - 1 && j >= 0 && j < n - 1) {
                    cnt.merge(1L * i * n + j, 1, Integer::sum);
                }
            }
        }
        long[] ans = new long[5];
        ans[0] = (m - 1L) * (n - 1);
        for (int x : cnt.values()) {
            ++ans[x];
            --ans[0];
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coordinates) {
        unordered_map<long long, int> cnt;
        int dirs[5] = {0, 0, -1, -1, 0};
        for (auto& e : coordinates) {
            int x = e[0], y = e[1];
            for (int k = 0; k < 4; ++k) {
                int i = x + dirs[k], j = y + dirs[k + 1];
                if (i >= 0 && i < m - 1 && j >= 0 && j < n - 1) {
                    ++cnt[1LL * i * n + j];
                }
            }
        }
        vector<long long> ans(5);
        ans[0] = (m - 1LL) * (n - 1);
        for (auto& [_, x] : cnt) {
            ++ans[x];
            --ans[0];
        }
        return ans;
    }
};
```

#### Go

```go
func countBlackBlocks(m int, n int, coordinates [][]int) []int64 {
	cnt := map[int64]int{}
	dirs := [5]int{0, 0, -1, -1, 0}
	for _, e := range coordinates {
		x, y := e[0], e[1]
		for k := 0; k < 4; k++ {
			i, j := x+dirs[k], y+dirs[k+1]
			if i >= 0 && i < m-1 && j >= 0 && j < n-1 {
				cnt[int64(i*n+j)]++
			}
		}
	}
	ans := make([]int64, 5)
	ans[0] = int64((m - 1) * (n - 1))
	for _, x := range cnt {
		ans[x]++
		ans[0]--
	}
	return ans
}
```

#### TypeScript

```ts
function countBlackBlocks(m: number, n: number, coordinates: number[][]): number[] {
    const cnt: Map<number, number> = new Map();
    const dirs: number[] = [0, 0, -1, -1, 0];
    for (const [x, y] of coordinates) {
        for (let k = 0; k < 4; ++k) {
            const [i, j] = [x + dirs[k], y + dirs[k + 1]];
            if (i >= 0 && i < m - 1 && j >= 0 && j < n - 1) {
                const key = i * n + j;
                cnt.set(key, (cnt.get(key) || 0) + 1);
            }
        }
    }
    const ans: number[] = Array(5).fill(0);
    ans[0] = (m - 1) * (n - 1);
    for (const [_, x] of cnt) {
        ++ans[x];
        --ans[0];
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2769. 找出最大的可达成数字](https://leetcode.cn/problems/find-the-maximum-achievable-number){#2769}

{{< tabs "2769" >}}

{{% tab "python" %}}
```python
class Solution:
    def theMaximumAchievableX(self, num: int, t: int) -> int:
        return num + t * 2
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int theMaximumAchievableX(int num, int t) {
        return num + t * 2;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int theMaximumAchievableX(int num, int t) {
        return num + t * 2;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func theMaximumAchievableX(num int, t int) int {
	return num + t*2
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function theMaximumAchievableX(num: number, t: number): number {
    return num + t * 2;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个整数 <code>num</code> 和 <code>t</code> 。如果整数 <code>x</code> 可以在执行下述操作 <strong>不超过</strong> <code>t</code> 次的情况下变为与 <code>num</code> 相等，则称其为 <strong>可达成数字</strong> ：</p>

<ul>
	<li>每次操作将 <code>x</code> 的值增加或减少 <code>1</code> ，同时可以选择将 <code>num</code> 的值增加或减少 <code>1</code> 。</li>
</ul>

<p>返回所有可达成数字中的 <strong>最大</strong> 值 <code>x</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong>num = 4, t = 1</p>

<p><strong>输出：</strong>6</p>

<p><strong>解释：</strong></p>

<p>执行下述操作可以使最大可达成数字等于 <code>num</code> ：</p>

<ul>
	<li>最大可达成数字减少 1 ，同时 <code>num</code> 增加 1 。</li>
</ul>
</div>

<p><strong>示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong>num = 3, t = 2</p>

<p><strong>输出：</strong>7</p>

<p><strong>解释：</strong></p>

<p>执行两次下述操作可以使最大可达成数字等于 num ：</p>

<ul>
	<li>最大可达成数字减少 1 ，同时 <code>num</code> 增加 1。</li>
</ul>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= num, t&nbsp;&lt;= 50</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数学

我们注意到，每次操作可以将 $x$ 减少 $1$，同时将 $num$ 增加 $1$，这样 $x$ 和 $num$ 的差值就会减少 $2$，而最多可以操作 $t$ 次，所以最大可达成数字为 $num + t \times 2$。

时间复杂度 $O(1)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def theMaximumAchievableX(self, num: int, t: int) -> int:
        return num + t * 2
```

#### Java

```java
class Solution {
    public int theMaximumAchievableX(int num, int t) {
        return num + t * 2;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int theMaximumAchievableX(int num, int t) {
        return num + t * 2;
    }
};
```

#### Go

```go
func theMaximumAchievableX(num int, t int) int {
	return num + t*2
}
```

#### TypeScript

```ts
function theMaximumAchievableX(num: number, t: number): number {
    return num + t * 2;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
