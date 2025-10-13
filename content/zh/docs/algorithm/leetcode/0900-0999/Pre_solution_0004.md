---
title: "0930_和相同的二元子数组"
date: 2025-10-08T18:36:43+08:00
weight: 4
tags: [二叉搜索树, 二叉树, 几何, 分治, 前缀和, 动态规划, 哈希表, 字符串, 广度优先搜索, 排序, 数学, 数据流, 数组, 栈, 树, 深度优先搜索, 滑动窗口, 矩阵, 设计, 贪心, 队列]
---

{{< markmap >}}
### [0930_和相同的二元子数组](#930)
#### [数组](#930)
#### [哈希表](#930)
#### [前缀和](#930)
#### [滑动窗口](#930)
### [0931_下降路径最小和](#931)
#### [数组](#931)
#### [动态规划](#931)
#### [矩阵](#931)
### [0932_漂亮数组](#932)
#### [数组](#932)
#### [数学](#932)
#### [分治](#932)
### [0933_最近的请求次数](#933)
#### [设计](#933)
#### [队列](#933)
#### [数据流](#933)
### [0934_最短的桥](#934)
#### [深度优先搜索](#934)
#### [广度优先搜索](#934)
#### [数组](#934)
#### [矩阵](#934)
### [0935_骑士拨号器](#935)
#### [动态规划](#935)
### [0936_戳印序列](#936)
#### [栈](#936)
#### [贪心](#936)
#### [队列](#936)
#### [字符串](#936)
### [0937_重新排列日志文件](#937)
#### [数组](#937)
#### [字符串](#937)
#### [排序](#937)
### [0938_二叉搜索树的范围和](#938)
#### [树](#938)
#### [深度优先搜索](#938)
#### [二叉搜索树](#938)
#### [二叉树](#938)
### [0939_最小面积矩形](#939)
#### [几何](#939)
#### [数组](#939)
#### [哈希表](#939)
#### [数学](#939)
#### [排序](#939)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0930_和相同的二元子数组
___
#### 数组
___
#### 哈希表
___
#### 前缀和
___
#### 滑动窗口
---
### 0931_下降路径最小和
___
#### 数组
___
#### 动态规划
___
#### 矩阵
---
### 0932_漂亮数组
___
#### 数组
___
#### 数学
___
#### 分治
---
### 0933_最近的请求次数
___
#### 设计
___
#### 队列
___
#### 数据流
---
### 0934_最短的桥
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 数组
___
#### 矩阵
---
### 0935_骑士拨号器
___
#### 动态规划
---
### 0936_戳印序列
___
#### 栈
___
#### 贪心
___
#### 队列
___
#### 字符串
---
### 0937_重新排列日志文件
___
#### 数组
___
#### 字符串
___
#### 排序
---
### 0938_二叉搜索树的范围和
___
#### 树
___
#### 深度优先搜索
___
#### 二叉搜索树
___
#### 二叉树
---
### 0939_最小面积矩形
___
#### 几何
___
#### 数组
___
#### 哈希表
___
#### 数学
___
#### 排序
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二叉搜索树 | 二叉树 | 几何 |
| 分治 | 前缀和 | 动态规划 |
| 哈希表 | 字符串 | 广度优先搜索 |
| 排序 | 数学 | 数据流 |
| 数组 | 栈 | 树 |
| 深度优先搜索 | 滑动窗口 | 矩阵 |
| 设计 | 贪心 | 队列 |

# [930. 和相同的二元子数组](https://leetcode.cn/problems/binary-subarrays-with-sum){#930}

{{< tabs "930" >}}

{{% tab "python" %}}
```python
class Solution:
    def numSubarraysWithSum(self, nums: List[int], goal: int) -> int:
        i1 = i2 = s1 = s2 = j = ans = 0
        n = len(nums)
        while j < n:
            s1 += nums[j]
            s2 += nums[j]
            while i1 <= j and s1 > goal:
                s1 -= nums[i1]
                i1 += 1
            while i2 <= j and s2 >= goal:
                s2 -= nums[i2]
                i2 += 1
            ans += i2 - i1
            j += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numSubarraysWithSum(int[] nums, int goal) {
        int i1 = 0, i2 = 0, s1 = 0, s2 = 0, j = 0, ans = 0;
        int n = nums.length;
        while (j < n) {
            s1 += nums[j];
            s2 += nums[j];
            while (i1 <= j && s1 > goal) {
                s1 -= nums[i1++];
            }
            while (i2 <= j && s2 >= goal) {
                s2 -= nums[i2++];
            }
            ans += i2 - i1;
            ++j;
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
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int i1 = 0, i2 = 0, s1 = 0, s2 = 0, j = 0, ans = 0;
        int n = nums.size();
        while (j < n) {
            s1 += nums[j];
            s2 += nums[j];
            while (i1 <= j && s1 > goal) s1 -= nums[i1++];
            while (i2 <= j && s2 >= goal) s2 -= nums[i2++];
            ans += i2 - i1;
            ++j;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numSubarraysWithSum(nums []int, goal int) int {
	i1, i2, s1, s2, j, ans, n := 0, 0, 0, 0, 0, 0, len(nums)
	for j < n {
		s1 += nums[j]
		s2 += nums[j]
		for i1 <= j && s1 > goal {
			s1 -= nums[i1]
			i1++
		}
		for i2 <= j && s2 >= goal {
			s2 -= nums[i2]
			i2++
		}
		ans += i2 - i1
		j++
	}
	return ans
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} nums
 * @param {number} goal
 * @return {number}
 */
var numSubarraysWithSum = function (nums, goal) {
    let i1 = 0,
        i2 = 0,
        s1 = 0,
        s2 = 0,
        j = 0,
        ans = 0;
    const n = nums.length;
    while (j < n) {
        s1 += nums[j];
        s2 += nums[j];
        while (i1 <= j && s1 > goal) s1 -= nums[i1++];
        while (i2 <= j && s2 >= goal) s2 -= nums[i2++];
        ans += i2 - i1;
        ++j;
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

<p>给你一个二元数组 <code>nums</code> ，和一个整数 <code>goal</code> ，请你统计并返回有多少个和为 <code>goal</code> 的<strong> 非空</strong> 子数组。</p>

<p><strong>子数组</strong> 是数组的一段连续部分。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,0,1,0,1], goal = 2
<strong>输出：</strong>4
<strong>解释：</strong>
有 4 个满足题目要求的子数组：[1,0,1]、[1,0,1,0]、[0,1,0,1]、[1,0,1]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [0,0,0,0,0], goal = 0
<strong>输出：</strong>15
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= nums.length <= 3 * 10<sup>4</sup></code></li>
	<li><code>nums[i]</code> 不是 <code>0</code> 就是 <code>1</code></li>
	<li><code>0 <= goal <= nums.length</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数组或哈希表 + 前缀和

我们可以用数组或哈希表 $cnt$ 记录每个前缀和出现的次数，其中 $cnt[i]$ 表示前缀和为 $i$ 的子数组个数。初始时 $cnt[0] = 1$。

接下来我们遍历数组 `nums`，用变量 $s$ 维护当前的前缀和，对于每个 $s$，我们可以计算出 $s - goal$ 出现的次数，即为以当前位置结尾的满足条件的子数组个数，累加到答案中。然后我们将 $s$ 的计数值加 $1$。

最终的答案即为满足条件的子数组个数。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 `nums` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numSubarraysWithSum(self, nums: List[int], goal: int) -> int:
        cnt = Counter({0: 1})
        ans = s = 0
        for v in nums:
            s += v
            ans += cnt[s - goal]
            cnt[s] += 1
        return ans
```

#### Java

```java
class Solution {
    public int numSubarraysWithSum(int[] nums, int goal) {
        int[] cnt = new int[nums.length + 1];
        cnt[0] = 1;
        int ans = 0, s = 0;
        for (int v : nums) {
            s += v;
            if (s - goal >= 0) {
                ans += cnt[s - goal];
            }
            ++cnt[s];
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int cnt[nums.size() + 1];
        memset(cnt, 0, sizeof cnt);
        cnt[0] = 1;
        int ans = 0, s = 0;
        for (int& v : nums) {
            s += v;
            if (s - goal >= 0) {
                ans += cnt[s - goal];
            }
            ++cnt[s];
        }
        return ans;
    }
};
```

#### Go

```go
func numSubarraysWithSum(nums []int, goal int) (ans int) {
	cnt := map[int]int{0: 1}
	s := 0
	for _, v := range nums {
		s += v
		ans += cnt[s-goal]
		cnt[s]++
	}
	return
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @param {number} goal
 * @return {number}
 */
var numSubarraysWithSum = function (nums, goal) {
    const cnt = new Array(nums.length + 1).fill(0);
    cnt[0] = 1;
    let ans = 0;
    let s = 0;
    for (const v of nums) {
        s += v;
        if (s >= goal) {
            ans += cnt[s - goal];
        }
        ++cnt[s];
    }
    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：双指针

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numSubarraysWithSum(self, nums: List[int], goal: int) -> int:
        i1 = i2 = s1 = s2 = j = ans = 0
        n = len(nums)
        while j < n:
            s1 += nums[j]
            s2 += nums[j]
            while i1 <= j and s1 > goal:
                s1 -= nums[i1]
                i1 += 1
            while i2 <= j and s2 >= goal:
                s2 -= nums[i2]
                i2 += 1
            ans += i2 - i1
            j += 1
        return ans
```

#### Java

```java
class Solution {
    public int numSubarraysWithSum(int[] nums, int goal) {
        int i1 = 0, i2 = 0, s1 = 0, s2 = 0, j = 0, ans = 0;
        int n = nums.length;
        while (j < n) {
            s1 += nums[j];
            s2 += nums[j];
            while (i1 <= j && s1 > goal) {
                s1 -= nums[i1++];
            }
            while (i2 <= j && s2 >= goal) {
                s2 -= nums[i2++];
            }
            ans += i2 - i1;
            ++j;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int i1 = 0, i2 = 0, s1 = 0, s2 = 0, j = 0, ans = 0;
        int n = nums.size();
        while (j < n) {
            s1 += nums[j];
            s2 += nums[j];
            while (i1 <= j && s1 > goal) s1 -= nums[i1++];
            while (i2 <= j && s2 >= goal) s2 -= nums[i2++];
            ans += i2 - i1;
            ++j;
        }
        return ans;
    }
};
```

#### Go

```go
func numSubarraysWithSum(nums []int, goal int) int {
	i1, i2, s1, s2, j, ans, n := 0, 0, 0, 0, 0, 0, len(nums)
	for j < n {
		s1 += nums[j]
		s2 += nums[j]
		for i1 <= j && s1 > goal {
			s1 -= nums[i1]
			i1++
		}
		for i2 <= j && s2 >= goal {
			s2 -= nums[i2]
			i2++
		}
		ans += i2 - i1
		j++
	}
	return ans
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @param {number} goal
 * @return {number}
 */
var numSubarraysWithSum = function (nums, goal) {
    let i1 = 0,
        i2 = 0,
        s1 = 0,
        s2 = 0,
        j = 0,
        ans = 0;
    const n = nums.length;
    while (j < n) {
        s1 += nums[j];
        s2 += nums[j];
        while (i1 <= j && s1 > goal) s1 -= nums[i1++];
        while (i2 <= j && s2 >= goal) s2 -= nums[i2++];
        ans += i2 - i1;
        ++j;
    }
    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [931. 下降路径最小和](https://leetcode.cn/problems/minimum-falling-path-sum){#931}

{{< tabs "931" >}}

{{% tab "python" %}}
```python
class Solution:
    def minFallingPathSum(self, matrix: List[List[int]]) -> int:
        n = len(matrix)
        f = [0] * n
        for row in matrix:
            g = [0] * n
            for j, x in enumerate(row):
                l, r = max(0, j - 1), min(n, j + 2)
                g[j] = min(f[l:r]) + x
            f = g
        return min(f)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minFallingPathSum(int[][] matrix) {
        int n = matrix.length;
        var f = new int[n];
        for (var row : matrix) {
            var g = f.clone();
            for (int j = 0; j < n; ++j) {
                if (j > 0) {
                    g[j] = Math.min(g[j], f[j - 1]);
                }
                if (j + 1 < n) {
                    g[j] = Math.min(g[j], f[j + 1]);
                }
                g[j] += row[j];
            }
            f = g;
        }
        // return Arrays.stream(f).min().getAsInt();
        int ans = 1 << 30;
        for (int x : f) {
            ans = Math.min(ans, x);
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
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> f(n);
        for (auto& row : matrix) {
            auto g = f;
            for (int j = 0; j < n; ++j) {
                if (j) {
                    g[j] = min(g[j], f[j - 1]);
                }
                if (j + 1 < n) {
                    g[j] = min(g[j], f[j + 1]);
                }
                g[j] += row[j];
            }
            f = move(g);
        }
        return *min_element(f.begin(), f.end());
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minFallingPathSum(matrix [][]int) int {
	n := len(matrix)
	f := make([]int, n)
	for _, row := range matrix {
		g := make([]int, n)
		copy(g, f)
		for j, x := range row {
			if j > 0 {
				g[j] = min(g[j], f[j-1])
			}
			if j+1 < n {
				g[j] = min(g[j], f[j+1])
			}
			g[j] += x
		}
		f = g
	}
	return slices.Min(f)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minFallingPathSum(matrix: number[][]): number {
    const n = matrix.length;
    const f: number[] = new Array(n).fill(0);
    for (const row of matrix) {
        const g = f.slice();
        for (let j = 0; j < n; ++j) {
            if (j > 0) {
                g[j] = Math.min(g[j], f[j - 1]);
            }
            if (j + 1 < n) {
                g[j] = Math.min(g[j], f[j + 1]);
            }
            g[j] += row[j];
        }
        f.splice(0, n, ...g);
    }
    return Math.min(...f);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个 <code>n x n</code> 的<strong> 方形 </strong>整数数组&nbsp;<code>matrix</code> ，请你找出并返回通过 <code>matrix</code> 的<strong>下降路径</strong><em> </em>的<strong> </strong><strong>最小和</strong> 。</p>

<p><strong>下降路径</strong> 可以从第一行中的任何元素开始，并从每一行中选择一个元素。在下一行选择的元素和当前行所选元素最多相隔一列（即位于正下方或者沿对角线向左或者向右的第一个元素）。具体来说，位置 <code>(row, col)</code> 的下一个元素应当是 <code>(row + 1, col - 1)</code>、<code>(row + 1, col)</code> 或者 <code>(row + 1, col + 1)</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0900-0999/0931.Minimum%20Falling%20Path%20Sum/images/1729566253-aneDag-image.png" style="height: 500px; width: 499px;" /></p>

<pre>
<strong>输入：</strong>matrix = [[2,1,3],[6,5,4],[7,8,9]]
<strong>输出：</strong>13
<strong>解释：</strong>如图所示，为和最小的两条下降路径
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0900-0999/0931.Minimum%20Falling%20Path%20Sum/images/1729566282-dtXwRd-image.png" style="height: 365px; width: 164px;" /></p>

<pre>
<strong>输入：</strong>matrix = [[-19,57],[-40,-5]]
<strong>输出：</strong>-59
<strong>解释：</strong>如图所示，为和最小的下降路径
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == matrix.length == matrix[i].length</code></li>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>-100 &lt;= matrix[i][j] &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i][j]$ 表示从第一行开始下降，到达第 $i$ 行第 $j$ 列的最小路径和。那么我们可以得到这样的动态规划转移方程：

$$
f[i][j] = matrix[i][j] + \min \left\{ \begin{aligned} & f[i - 1][j - 1], & j > 0 \\ & f[i - 1][j], & 0 \leq j < n \\ & f[i - 1][j + 1], & j + 1 < n \end{aligned} \right.
$$

最终的答案即为 $\min \limits_{0 \leq j < n} f[n - 1][j]$。

时间复杂度 $O(n^2)$，空间复杂度 $O(n^2)$。

我们注意到，状态 $f[i][j]$ 只与上一行的状态有关，因此我们可以使用滚动数组的方式，去掉第一维的状态，将空间复杂度优化到 $O(n)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minFallingPathSum(self, matrix: List[List[int]]) -> int:
        n = len(matrix)
        f = [0] * n
        for row in matrix:
            g = [0] * n
            for j, x in enumerate(row):
                l, r = max(0, j - 1), min(n, j + 2)
                g[j] = min(f[l:r]) + x
            f = g
        return min(f)
```

#### Java

```java
class Solution {
    public int minFallingPathSum(int[][] matrix) {
        int n = matrix.length;
        var f = new int[n];
        for (var row : matrix) {
            var g = f.clone();
            for (int j = 0; j < n; ++j) {
                if (j > 0) {
                    g[j] = Math.min(g[j], f[j - 1]);
                }
                if (j + 1 < n) {
                    g[j] = Math.min(g[j], f[j + 1]);
                }
                g[j] += row[j];
            }
            f = g;
        }
        // return Arrays.stream(f).min().getAsInt();
        int ans = 1 << 30;
        for (int x : f) {
            ans = Math.min(ans, x);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> f(n);
        for (auto& row : matrix) {
            auto g = f;
            for (int j = 0; j < n; ++j) {
                if (j) {
                    g[j] = min(g[j], f[j - 1]);
                }
                if (j + 1 < n) {
                    g[j] = min(g[j], f[j + 1]);
                }
                g[j] += row[j];
            }
            f = move(g);
        }
        return *min_element(f.begin(), f.end());
    }
};
```

#### Go

```go
func minFallingPathSum(matrix [][]int) int {
	n := len(matrix)
	f := make([]int, n)
	for _, row := range matrix {
		g := make([]int, n)
		copy(g, f)
		for j, x := range row {
			if j > 0 {
				g[j] = min(g[j], f[j-1])
			}
			if j+1 < n {
				g[j] = min(g[j], f[j+1])
			}
			g[j] += x
		}
		f = g
	}
	return slices.Min(f)
}
```

#### TypeScript

```ts
function minFallingPathSum(matrix: number[][]): number {
    const n = matrix.length;
    const f: number[] = new Array(n).fill(0);
    for (const row of matrix) {
        const g = f.slice();
        for (let j = 0; j < n; ++j) {
            if (j > 0) {
                g[j] = Math.min(g[j], f[j - 1]);
            }
            if (j + 1 < n) {
                g[j] = Math.min(g[j], f[j + 1]);
            }
            g[j] += row[j];
        }
        f.splice(0, n, ...g);
    }
    return Math.min(...f);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [932. 漂亮数组](https://leetcode.cn/problems/beautiful-array){#932}

{{< tabs "932" >}}

{{% tab "python" %}}
```python
class Solution:
    def beautifulArray(self, n: int) -> List[int]:
        if n == 1:
            return [1]
        left = self.beautifulArray((n + 1) >> 1)
        right = self.beautifulArray(n >> 1)
        left = [x * 2 - 1 for x in left]
        right = [x * 2 for x in right]
        return left + right
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] beautifulArray(int n) {
        if (n == 1) {
            return new int[] {1};
        }
        int[] left = beautifulArray((n + 1) >> 1);
        int[] right = beautifulArray(n >> 1);
        int[] ans = new int[n];
        int i = 0;
        for (int x : left) {
            ans[i++] = x * 2 - 1;
        }
        for (int x : right) {
            ans[i++] = x * 2;
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
    vector<int> beautifulArray(int n) {
        if (n == 1) return {1};
        vector<int> left = beautifulArray((n + 1) >> 1);
        vector<int> right = beautifulArray(n >> 1);
        vector<int> ans(n);
        int i = 0;
        for (int& x : left) ans[i++] = x * 2 - 1;
        for (int& x : right) ans[i++] = x * 2;
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func beautifulArray(n int) []int {
	if n == 1 {
		return []int{1}
	}
	left := beautifulArray((n + 1) >> 1)
	right := beautifulArray(n >> 1)
	var ans []int
	for _, x := range left {
		ans = append(ans, x*2-1)
	}
	for _, x := range right {
		ans = append(ans, x*2)
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

<p>如果长度为 <code>n</code> 的数组 <code>nums</code> 满足下述条件，则认为该数组是一个 <strong>漂亮数组</strong> ：</p>

<ul>
	<li><code>nums</code> 是由范围 <code>[1, n]</code> 的整数组成的一个排列。</li>
	<li>对于每个 <code>0 &lt;= i &lt; j &lt; n</code> ，均不存在下标 <code>k</code>（<code>i &lt; k &lt; j</code>）使得 <code>2 * nums[k] == nums[i] + nums[j]</code> 。</li>
</ul>

<p>给你整数 <code>n</code> ，返回长度为 <code>n</code> 的任一 <strong>漂亮数组</strong> 。本题保证对于给定的 <code>n</code> 至少存在一个有效答案。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1 ：</strong></p>

<pre>
<strong>输入：</strong>n = 4
<strong>输出：</strong>[2,1,4,3]
</pre>

<p><strong class="example">示例 2 ：</strong></p>

<pre>
<strong>输入：</strong>n = 5
<strong>输出：</strong>[3,1,2,5,4]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
</ul>

<p>&nbsp;</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：分治

根据题意，漂亮数组 $A$ 需要满足对于任意 $i<k<j$, $A_k*2 \neq A_i+A_j$。

我们可以发现，不等式左侧一定是偶数，那么我们只要保证不等式右侧 $A_i$ 和 $A_j$ 分别是一奇一偶，那么不等式就恒成立。

利用分治，我们将 $n$ 缩小规模为原来的一半，递归调用，可以得到两个漂亮数组 $left$, $right$。我们将 $left$ 中每个元素 $x_i$ 变为 $x_i*2-1$ 可以得到一个奇数数组；将 $right$ 中每个元素 $x_i$ 变为 $x_i*2$，可以得到一个偶数数组。这两个数组仍然是漂亮数组。

> 基于一个性质，将漂亮数组中的每个元素 $x_i$ 变换为 $kx_i+b$，得到的数组仍然是漂亮数组。

将这两个漂亮数组合并在一起，由于满足一奇一偶，那么合并后的数组也是漂亮数组，从而得到了答案。

时间复杂度 $O(nlogn)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def beautifulArray(self, n: int) -> List[int]:
        if n == 1:
            return [1]
        left = self.beautifulArray((n + 1) >> 1)
        right = self.beautifulArray(n >> 1)
        left = [x * 2 - 1 for x in left]
        right = [x * 2 for x in right]
        return left + right
```

#### Java

```java
class Solution {
    public int[] beautifulArray(int n) {
        if (n == 1) {
            return new int[] {1};
        }
        int[] left = beautifulArray((n + 1) >> 1);
        int[] right = beautifulArray(n >> 1);
        int[] ans = new int[n];
        int i = 0;
        for (int x : left) {
            ans[i++] = x * 2 - 1;
        }
        for (int x : right) {
            ans[i++] = x * 2;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> beautifulArray(int n) {
        if (n == 1) return {1};
        vector<int> left = beautifulArray((n + 1) >> 1);
        vector<int> right = beautifulArray(n >> 1);
        vector<int> ans(n);
        int i = 0;
        for (int& x : left) ans[i++] = x * 2 - 1;
        for (int& x : right) ans[i++] = x * 2;
        return ans;
    }
};
```

#### Go

```go
func beautifulArray(n int) []int {
	if n == 1 {
		return []int{1}
	}
	left := beautifulArray((n + 1) >> 1)
	right := beautifulArray(n >> 1)
	var ans []int
	for _, x := range left {
		ans = append(ans, x*2-1)
	}
	for _, x := range right {
		ans = append(ans, x*2)
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [933. 最近的请求次数](https://leetcode.cn/problems/number-of-recent-calls){#933}

{{< tabs "933" >}}

{{% tab "python" %}}
```python
class RecentCounter:
    def __init__(self):
        self.s = []

    def ping(self, t: int) -> int:
        self.s.append(t)
        return len(self.s) - bisect_left(self.s, t - 3000)


# Your RecentCounter object will be instantiated and called as such:
# obj = RecentCounter()
# param_1 = obj.ping(t)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class RecentCounter {
    private int[] s = new int[10010];
    private int idx;

    public RecentCounter() {
    }

    public int ping(int t) {
        s[idx++] = t;
        return idx - search(t - 3000);
    }

    private int search(int x) {
        int left = 0, right = idx;
        while (left < right) {
            int mid = (left + right) >> 1;
            if (s[mid] >= x) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
}

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter obj = new RecentCounter();
 * int param_1 = obj.ping(t);
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class RecentCounter {
public:
    vector<int> s;

    RecentCounter() {
    }

    int ping(int t) {
        s.push_back(t);
        return s.size() - (lower_bound(s.begin(), s.end(), t - 3000) - s.begin());
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type RecentCounter struct {
	s []int
}

func Constructor() RecentCounter {
	return RecentCounter{[]int{}}
}

func (this *RecentCounter) Ping(t int) int {
	this.s = append(this.s, t)
	search := func(x int) int {
		left, right := 0, len(this.s)
		for left < right {
			mid := (left + right) >> 1
			if this.s[mid] >= x {
				right = mid
			} else {
				left = mid + 1
			}
		}
		return left
	}
	return len(this.s) - search(t-3000)
}

/**
 * Your RecentCounter object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Ping(t);
 */
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class RecentCounter {
    private queue: number[];

    constructor() {
        this.queue = [];
    }

    ping(t: number): number {
        this.queue.push(t);
        while (this.queue[0] < t - 3000) {
            this.queue.shift();
        }
        return this.queue.length;
    }
}

/**
 * Your RecentCounter object will be instantiated and called as such:
 * var obj = new RecentCounter()
 * var param_1 = obj.ping(t)
 */
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::VecDeque;
struct RecentCounter {
    queue: VecDeque<i32>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl RecentCounter {
    fn new() -> Self {
        Self {
            queue: VecDeque::new(),
        }
    }

    fn ping(&mut self, t: i32) -> i32 {
        self.queue.push_back(t);
        while let Some(&v) = self.queue.front() {
            if v >= t - 3000 {
                break;
            }
            self.queue.pop_front();
        }
        self.queue.len() as i32
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
var RecentCounter = function () {
    this.q = [];
};

/**
 * @param {number} t
 * @return {number}
 */
RecentCounter.prototype.ping = function (t) {
    this.q.push(t);
    while (this.q[0] < t - 3000) {
        this.q.shift();
    }
    return this.q.length;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * var obj = new RecentCounter()
 * var param_1 = obj.ping(t)
 */
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class RecentCounter {
    private Queue<int> q = new Queue<int>();

    public RecentCounter() {

    }

    public int Ping(int t) {
        q.Enqueue(t);
        while (q.Peek() < t - 3000)
        {
            q.Dequeue();
        }
        return q.Count;
    }
}

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter obj = new RecentCounter();
 * int param_1 = obj.Ping(t);
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>写一个&nbsp;<code>RecentCounter</code>&nbsp;类来计算特定时间范围内最近的请求。</p>

<p>请你实现 <code>RecentCounter</code> 类：</p>

<ul>
	<li><code>RecentCounter()</code> 初始化计数器，请求数为 0 。</li>
	<li><code>int ping(int t)</code> 在时间 <code>t</code> 添加一个新请求，其中 <code>t</code> 表示以毫秒为单位的某个时间，并返回过去 <code>3000</code> 毫秒内发生的所有请求数（包括新请求）。确切地说，返回在 <code>[t-3000, t]</code> 内发生的请求数。</li>
</ul>

<p><strong>保证</strong> 每次对 <code>ping</code> 的调用都使用比之前更大的 <code>t</code> 值。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
["RecentCounter", "ping", "ping", "ping", "ping"]
[[], [1], [100], [3001], [3002]]
<strong>输出：</strong>
[null, 1, 2, 3, 3]

<strong>解释：</strong>
RecentCounter recentCounter = new RecentCounter();
recentCounter.ping(1);     // requests = [<strong>1</strong>]，范围是 [-2999,1]，返回 1
recentCounter.ping(100);   // requests = [<strong>1</strong>, <strong>100</strong>]，范围是 [-2900,100]，返回 2
recentCounter.ping(3001);  // requests = [<strong>1</strong>, <strong>100</strong>, <strong>3001</strong>]，范围是 [1,3001]，返回 3
recentCounter.ping(3002);  // requests = [1, <strong>100</strong>, <strong>3001</strong>, <strong>3002</strong>]，范围是 [2,3002]，返回 3
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= t &lt;= 10<sup>9</sup></code></li>
	<li>保证每次对 <code>ping</code> 调用所使用的 <code>t</code> 值都 <strong>严格递增</strong></li>
	<li>至多调用 <code>ping</code> 方法 <code>10<sup>4</sup></code> 次</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：队列

由题得知，`t` 是**严格递增**的，当一个元素不满足 `[t - 3000, t]` 条件时，在后续的请求当中，它也不可能满足。

对此，需要将其从记录容器中移除，减少无意义的比较。

可以使用队列。每次将 `t` 进入队尾，同时从队头开始，依次移除小于 `t - 3000` 的元素。然后返回队列的大小（`q.size()`）即可。

<!-- tabs:start -->

#### Python3

```python
class RecentCounter:
    def __init__(self):
        self.q = deque()

    def ping(self, t: int) -> int:
        self.q.append(t)
        while self.q[0] < t - 3000:
            self.q.popleft()
        return len(self.q)


# Your RecentCounter object will be instantiated and called as such:
# obj = RecentCounter()
# param_1 = obj.ping(t)
```

#### Java

```java
class RecentCounter {
    private int[] s = new int[10010];
    private int idx;

    public RecentCounter() {
    }

    public int ping(int t) {
        s[idx++] = t;
        return idx - search(t - 3000);
    }

    private int search(int x) {
        int left = 0, right = idx;
        while (left < right) {
            int mid = (left + right) >> 1;
            if (s[mid] >= x) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
}

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter obj = new RecentCounter();
 * int param_1 = obj.ping(t);
 */
```

#### C++

```cpp
class RecentCounter {
public:
    queue<int> q;

    RecentCounter() {
    }

    int ping(int t) {
        q.push(t);
        while (q.front() < t - 3000) q.pop();
        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
```

#### Go

```go
type RecentCounter struct {
	q []int
}

func Constructor() RecentCounter {
	return RecentCounter{[]int{}}
}

func (this *RecentCounter) Ping(t int) int {
	this.q = append(this.q, t)
	for this.q[0] < t-3000 {
		this.q = this.q[1:]
	}
	return len(this.q)
}

/**
 * Your RecentCounter object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Ping(t);
 */
```

#### TypeScript

```ts
class RecentCounter {
    private queue: number[];

    constructor() {
        this.queue = [];
    }

    ping(t: number): number {
        this.queue.push(t);
        while (this.queue[0] < t - 3000) {
            this.queue.shift();
        }
        return this.queue.length;
    }
}

/**
 * Your RecentCounter object will be instantiated and called as such:
 * var obj = new RecentCounter()
 * var param_1 = obj.ping(t)
 */
```

#### Rust

```rust
use std::collections::VecDeque;
struct RecentCounter {
    queue: VecDeque<i32>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl RecentCounter {
    fn new() -> Self {
        Self {
            queue: VecDeque::new(),
        }
    }

    fn ping(&mut self, t: i32) -> i32 {
        self.queue.push_back(t);
        while let Some(&v) = self.queue.front() {
            if v >= t - 3000 {
                break;
            }
            self.queue.pop_front();
        }
        self.queue.len() as i32
    }
}
```

#### JavaScript

```js
var RecentCounter = function () {
    this.q = [];
};

/**
 * @param {number} t
 * @return {number}
 */
RecentCounter.prototype.ping = function (t) {
    this.q.push(t);
    while (this.q[0] < t - 3000) {
        this.q.shift();
    }
    return this.q.length;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * var obj = new RecentCounter()
 * var param_1 = obj.ping(t)
 */
```

#### C#

```cs
public class RecentCounter {
    private Queue<int> q = new Queue<int>();

    public RecentCounter() {

    }

    public int Ping(int t) {
        q.Enqueue(t);
        while (q.Peek() < t - 3000)
        {
            q.Dequeue();
        }
        return q.Count;
    }
}

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter obj = new RecentCounter();
 * int param_1 = obj.Ping(t);
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：二分查找

`t` 严格单调递增，非常适合用二分查找来定位 `[t-3000, t]` 的左右边界。

<!-- tabs:start -->

#### Python3

```python
class RecentCounter:
    def __init__(self):
        self.s = []

    def ping(self, t: int) -> int:
        self.s.append(t)
        return len(self.s) - bisect_left(self.s, t - 3000)


# Your RecentCounter object will be instantiated and called as such:
# obj = RecentCounter()
# param_1 = obj.ping(t)
```

#### C++

```cpp
class RecentCounter {
public:
    vector<int> s;

    RecentCounter() {
    }

    int ping(int t) {
        s.push_back(t);
        return s.size() - (lower_bound(s.begin(), s.end(), t - 3000) - s.begin());
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
```

#### Go

```go
type RecentCounter struct {
	s []int
}

func Constructor() RecentCounter {
	return RecentCounter{[]int{}}
}

func (this *RecentCounter) Ping(t int) int {
	this.s = append(this.s, t)
	search := func(x int) int {
		left, right := 0, len(this.s)
		for left < right {
			mid := (left + right) >> 1
			if this.s[mid] >= x {
				right = mid
			} else {
				left = mid + 1
			}
		}
		return left
	}
	return len(this.s) - search(t-3000)
}

/**
 * Your RecentCounter object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Ping(t);
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [934. 最短的桥](https://leetcode.cn/problems/shortest-bridge){#934}

{{< tabs "934" >}}

{{% tab "python" %}}
```python
class Solution:
    def shortestBridge(self, grid: List[List[int]]) -> int:
        def dfs(i, j):
            q.append((i, j))
            grid[i][j] = 2
            for a, b in pairwise(dirs):
                x, y = i + a, j + b
                if 0 <= x < n and 0 <= y < n and grid[x][y] == 1:
                    dfs(x, y)

        n = len(grid)
        dirs = (-1, 0, 1, 0, -1)
        q = deque()
        i, j = next((i, j) for i in range(n) for j in range(n) if grid[i][j])
        dfs(i, j)
        ans = 0
        while 1:
            for _ in range(len(q)):
                i, j = q.popleft()
                for a, b in pairwise(dirs):
                    x, y = i + a, j + b
                    if 0 <= x < n and 0 <= y < n:
                        if grid[x][y] == 1:
                            return ans
                        if grid[x][y] == 0:
                            grid[x][y] = 2
                            q.append((x, y))
            ans += 1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[] dirs = {-1, 0, 1, 0, -1};
    private Deque<int[]> q = new ArrayDeque<>();
    private int[][] grid;
    private int n;

    public int shortestBridge(int[][] grid) {
        this.grid = grid;
        n = grid.length;
        for (int i = 0, x = 1; i < n && x == 1; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    dfs(i, j);
                    x = 0;
                    break;
                }
            }
        }
        int ans = 0;
        while (true) {
            for (int i = q.size(); i > 0; --i) {
                var p = q.pollFirst();
                for (int k = 0; k < 4; ++k) {
                    int x = p[0] + dirs[k], y = p[1] + dirs[k + 1];
                    if (x >= 0 && x < n && y >= 0 && y < n) {
                        if (grid[x][y] == 1) {
                            return ans;
                        }
                        if (grid[x][y] == 0) {
                            grid[x][y] = 2;
                            q.offer(new int[] {x, y});
                        }
                    }
                }
            }
            ++ans;
        }
    }

    private void dfs(int i, int j) {
        grid[i][j] = 2;
        q.offer(new int[] {i, j});
        for (int k = 0; k < 4; ++k) {
            int x = i + dirs[k], y = j + dirs[k + 1];
            if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 1) {
                dfs(x, y);
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
    const static inline vector<int> dirs = {-1, 0, 1, 0, -1};

    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        function<void(int, int)> dfs = [&](int i, int j) {
            grid[i][j] = 2;
            q.emplace(i, j);
            for (int k = 0; k < 4; ++k) {
                int x = i + dirs[k], y = j + dirs[k + 1];
                if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 1) {
                    dfs(x, y);
                }
            }
        };
        for (int i = 0, x = 1; i < n && x; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    dfs(i, j);
                    x = 0;
                    break;
                }
            }
        }
        int ans = 0;
        while (1) {
            for (int h = q.size(); h; --h) {
                auto [i, j] = q.front();
                q.pop();
                for (int k = 0; k < 4; ++k) {
                    int x = i + dirs[k], y = j + dirs[k + 1];
                    if (x >= 0 && x < n && y >= 0 && y < n) {
                        if (grid[x][y] == 1) return ans;
                        if (grid[x][y] == 0) {
                            grid[x][y] = 2;
                            q.emplace(x, y);
                        }
                    }
                }
            }
            ++ans;
        }
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func shortestBridge(grid [][]int) (ans int) {
	n := len(grid)
	dirs := []int{-1, 0, 1, 0, -1}
	type pair struct{ i, j int }
	q := []pair{}
	var dfs func(int, int)
	dfs = func(i, j int) {
		grid[i][j] = 2
		q = append(q, pair{i, j})
		for k := 0; k < 4; k++ {
			x, y := i+dirs[k], j+dirs[k+1]
			if x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 1 {
				dfs(x, y)
			}
		}
	}
	for i, x := 0, 1; i < n && x == 1; i++ {
		for j := 0; j < n; j++ {
			if grid[i][j] == 1 {
				dfs(i, j)
				x = 0
				break
			}
		}
	}
	for {
		for i := len(q); i > 0; i-- {
			p := q[0]
			q = q[1:]
			for k := 0; k < 4; k++ {
				x, y := p.i+dirs[k], p.j+dirs[k+1]
				if x >= 0 && x < n && y >= 0 && y < n {
					if grid[x][y] == 1 {
						return
					}
					if grid[x][y] == 0 {
						grid[x][y] = 2
						q = append(q, pair{x, y})
					}
				}
			}
		}
		ans++
	}
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个大小为 <code>n x n</code> 的二元矩阵 <code>grid</code> ，其中 <code>1</code> 表示陆地，<code>0</code> 表示水域。</p>

<p><strong>岛</strong> 是由四面相连的 <code>1</code> 形成的一个最大组，即不会与非组内的任何其他 <code>1</code> 相连。<code>grid</code> 中 <strong>恰好存在两座岛</strong> 。</p>

<div class="original__bRMd">
<div>
<p>你可以将任意数量的 <code>0</code> 变为 <code>1</code> ，以使两座岛连接起来，变成 <strong>一座岛</strong> 。</p>

<p>返回必须翻转的 <code>0</code> 的最小数目。</p>
</div>
</div>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>grid = [[0,1],[1,0]]
<strong>输出：</strong>1
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>grid = [[0,1,0],[0,0,0],[0,0,1]]
<strong>输出：</strong>2
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == grid.length == grid[i].length</code></li>
	<li><code>2 &lt;= n &lt;= 100</code></li>
	<li><code>grid[i][j]</code> 为 <code>0</code> 或 <code>1</code></li>
	<li><code>grid</code> 中恰有两个岛</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS + BFS

题目求解的是最小翻转次数，使得两个岛屿相连，实际上等价于求解两个岛屿之间的最短距离。

因此，我们可以先通过 DFS 将其中一个岛屿的所有点找出来，放到一个队列 $q$ 中。然后通过 BFS 一层层向外扩展，直至碰到另一个岛屿，此时将当前扩展的层数作为答案返回即可。

在 DFS 和 BFS 搜索的过程中，我们直接将已经访问过的点标记为 $2$，这样就不会重复访问。

时间复杂度 $O(n^2)$，空间复杂度 $O(n^2)$。其中 $n$ 为矩阵的行数或列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def shortestBridge(self, grid: List[List[int]]) -> int:
        def dfs(i, j):
            q.append((i, j))
            grid[i][j] = 2
            for a, b in pairwise(dirs):
                x, y = i + a, j + b
                if 0 <= x < n and 0 <= y < n and grid[x][y] == 1:
                    dfs(x, y)

        n = len(grid)
        dirs = (-1, 0, 1, 0, -1)
        q = deque()
        i, j = next((i, j) for i in range(n) for j in range(n) if grid[i][j])
        dfs(i, j)
        ans = 0
        while 1:
            for _ in range(len(q)):
                i, j = q.popleft()
                for a, b in pairwise(dirs):
                    x, y = i + a, j + b
                    if 0 <= x < n and 0 <= y < n:
                        if grid[x][y] == 1:
                            return ans
                        if grid[x][y] == 0:
                            grid[x][y] = 2
                            q.append((x, y))
            ans += 1
```

#### Java

```java
class Solution {
    private int[] dirs = {-1, 0, 1, 0, -1};
    private Deque<int[]> q = new ArrayDeque<>();
    private int[][] grid;
    private int n;

    public int shortestBridge(int[][] grid) {
        this.grid = grid;
        n = grid.length;
        for (int i = 0, x = 1; i < n && x == 1; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    dfs(i, j);
                    x = 0;
                    break;
                }
            }
        }
        int ans = 0;
        while (true) {
            for (int i = q.size(); i > 0; --i) {
                var p = q.pollFirst();
                for (int k = 0; k < 4; ++k) {
                    int x = p[0] + dirs[k], y = p[1] + dirs[k + 1];
                    if (x >= 0 && x < n && y >= 0 && y < n) {
                        if (grid[x][y] == 1) {
                            return ans;
                        }
                        if (grid[x][y] == 0) {
                            grid[x][y] = 2;
                            q.offer(new int[] {x, y});
                        }
                    }
                }
            }
            ++ans;
        }
    }

    private void dfs(int i, int j) {
        grid[i][j] = 2;
        q.offer(new int[] {i, j});
        for (int k = 0; k < 4; ++k) {
            int x = i + dirs[k], y = j + dirs[k + 1];
            if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 1) {
                dfs(x, y);
            }
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    const static inline vector<int> dirs = {-1, 0, 1, 0, -1};

    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        function<void(int, int)> dfs = [&](int i, int j) {
            grid[i][j] = 2;
            q.emplace(i, j);
            for (int k = 0; k < 4; ++k) {
                int x = i + dirs[k], y = j + dirs[k + 1];
                if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 1) {
                    dfs(x, y);
                }
            }
        };
        for (int i = 0, x = 1; i < n && x; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    dfs(i, j);
                    x = 0;
                    break;
                }
            }
        }
        int ans = 0;
        while (1) {
            for (int h = q.size(); h; --h) {
                auto [i, j] = q.front();
                q.pop();
                for (int k = 0; k < 4; ++k) {
                    int x = i + dirs[k], y = j + dirs[k + 1];
                    if (x >= 0 && x < n && y >= 0 && y < n) {
                        if (grid[x][y] == 1) return ans;
                        if (grid[x][y] == 0) {
                            grid[x][y] = 2;
                            q.emplace(x, y);
                        }
                    }
                }
            }
            ++ans;
        }
    }
};
```

#### Go

```go
func shortestBridge(grid [][]int) (ans int) {
	n := len(grid)
	dirs := []int{-1, 0, 1, 0, -1}
	type pair struct{ i, j int }
	q := []pair{}
	var dfs func(int, int)
	dfs = func(i, j int) {
		grid[i][j] = 2
		q = append(q, pair{i, j})
		for k := 0; k < 4; k++ {
			x, y := i+dirs[k], j+dirs[k+1]
			if x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 1 {
				dfs(x, y)
			}
		}
	}
	for i, x := 0, 1; i < n && x == 1; i++ {
		for j := 0; j < n; j++ {
			if grid[i][j] == 1 {
				dfs(i, j)
				x = 0
				break
			}
		}
	}
	for {
		for i := len(q); i > 0; i-- {
			p := q[0]
			q = q[1:]
			for k := 0; k < 4; k++ {
				x, y := p.i+dirs[k], p.j+dirs[k+1]
				if x >= 0 && x < n && y >= 0 && y < n {
					if grid[x][y] == 1 {
						return
					}
					if grid[x][y] == 0 {
						grid[x][y] = 2
						q = append(q, pair{x, y})
					}
				}
			}
		}
		ans++
	}
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [935. 骑士拨号器](https://leetcode.cn/problems/knight-dialer){#935}

{{< tabs "935" >}}

{{% tab "python" %}}
```python
import numpy as np

base = [
    (0, 0, 0, 0, 1, 0, 1, 0, 0, 0),
    (0, 0, 0, 0, 0, 0, 1, 0, 1, 0),
    (0, 0, 0, 0, 0, 0, 0, 1, 0, 1),
    (0, 0, 0, 0, 1, 0, 0, 0, 1, 0),
    (1, 0, 0, 1, 0, 0, 0, 0, 0, 1),
    (0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    (1, 1, 0, 0, 0, 0, 0, 1, 0, 0),
    (0, 0, 1, 0, 0, 0, 1, 0, 0, 0),
    (0, 1, 0, 1, 0, 0, 0, 0, 0, 0),
    (0, 0, 1, 0, 1, 0, 0, 0, 0, 0),
]


class Solution:
    def knightDialer(self, n: int) -> int:
        factor = np.asmatrix(base, np.dtype("O"))
        res = np.asmatrix([[1] * 10], np.dtype("O"))
        n -= 1
        mod = 10**9 + 7
        while n:
            if n & 1:
                res = res * factor % mod
            factor = factor * factor % mod
            n >>= 1
        return res.sum() % mod
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private final int mod = (int) 1e9 + 7;
    private final int[][] base = {{0, 0, 0, 0, 1, 0, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 1}, {0, 0, 0, 0, 1, 0, 0, 0, 1, 0},
        {1, 0, 0, 1, 0, 0, 0, 0, 0, 1}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 1, 0, 0, 0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 1, 0, 0, 0, 0, 0}};

    public int knightDialer(int n) {
        int[][] res = pow(base, n - 1);
        int ans = 0;
        for (int x : res[0]) {
            ans = (ans + x) % mod;
        }
        return ans;
    }

    private int[][] mul(int[][] a, int[][] b) {
        int m = a.length, n = b[0].length;
        int[][] c = new int[m][n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < b.length; ++k) {
                    c[i][j] = (int) ((c[i][j] + 1L * a[i][k] * b[k][j] % mod) % mod);
                }
            }
        }
        return c;
    }

    private int[][] pow(int[][] a, int n) {
        int[][] res = new int[1][a.length];
        Arrays.fill(res[0], 1);
        while (n > 0) {
            if ((n & 1) == 1) {
                res = mul(res, a);
            }
            a = mul(a, a);
            n >>= 1;
        }
        return res;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int knightDialer(int n) {
        const int mod = 1e9 + 7;
        vector<vector<int>> base = {
            {0, 0, 0, 0, 1, 0, 1, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 1, 0, 1, 0},
            {0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
            {0, 0, 0, 0, 1, 0, 0, 0, 1, 0},
            {1, 0, 0, 1, 0, 0, 0, 0, 0, 1},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {1, 1, 0, 0, 0, 0, 0, 1, 0, 0},
            {0, 0, 1, 0, 0, 0, 1, 0, 0, 0},
            {0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
            {0, 0, 1, 0, 1, 0, 0, 0, 0, 0}};
        vector<vector<int>> res = pow(base, n - 1, mod);
        return accumulate(res[0].begin(), res[0].end(), 0LL) % mod;
    }

private:
    vector<vector<int>> mul(const vector<vector<int>>& a, const vector<vector<int>>& b, int mod) {
        int m = a.size(), n = b[0].size();
        vector<vector<int>> c(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < b.size(); ++k) {
                    c[i][j] = (c[i][j] + (1LL * a[i][k] * b[k][j]) % mod) % mod;
                }
            }
        }
        return c;
    }

    vector<vector<int>> pow(vector<vector<int>>& a, int n, int mod) {
        int size = a.size();
        vector<vector<int>> res(1, vector<int>(size, 1));
        while (n > 0) {
            if (n % 2 == 1) {
                res = mul(res, a, mod);
            }
            a = mul(a, a, mod);
            n /= 2;
        }
        return res;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
const mod = 1e9 + 7

func knightDialer(n int) int {
	base := [][]int{
		{0, 0, 0, 0, 1, 0, 1, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 1, 0, 1, 0},
		{0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
		{0, 0, 0, 0, 1, 0, 0, 0, 1, 0},
		{1, 0, 0, 1, 0, 0, 0, 0, 0, 1},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{1, 1, 0, 0, 0, 0, 0, 1, 0, 0},
		{0, 0, 1, 0, 0, 0, 1, 0, 0, 0},
		{0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
		{0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
	}

	res := pow(base, n-1)
	ans := 0
	for _, x := range res[0] {
		ans = (ans + x) % mod
	}
	return ans
}

func mul(a, b [][]int) [][]int {
	m := len(a)
	n := len(b[0])
	c := make([][]int, m)
	for i := range c {
		c[i] = make([]int, n)
	}
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			for k := 0; k < len(b); k++ {
				c[i][j] = (c[i][j] + a[i][k]*b[k][j]) % mod
			}
		}
	}
	return c
}

func pow(a [][]int, n int) [][]int {
	size := len(a)
	res := make([][]int, 1)
	res[0] = make([]int, size)
	for i := 0; i < size; i++ {
		res[0][i] = 1
	}

	for n > 0 {
		if n%2 == 1 {
			res = mul(res, a)
		}
		a = mul(a, a)
		n /= 2
	}

	return res
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
const mod = 1e9 + 7;

function knightDialer(n: number): number {
    const base: number[][] = [
        [0, 0, 0, 0, 1, 0, 1, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 1, 0, 1, 0],
        [0, 0, 0, 0, 0, 0, 0, 1, 0, 1],
        [0, 0, 0, 0, 1, 0, 0, 0, 1, 0],
        [1, 0, 0, 1, 0, 0, 0, 0, 0, 1],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [1, 1, 0, 0, 0, 0, 0, 1, 0, 0],
        [0, 0, 1, 0, 0, 0, 1, 0, 0, 0],
        [0, 1, 0, 1, 0, 0, 0, 0, 0, 0],
        [0, 0, 1, 0, 1, 0, 0, 0, 0, 0],
    ];

    const res = pow(base, n - 1);
    let ans = 0;
    for (const x of res[0]) {
        ans = (ans + x) % mod;
    }
    return ans;
}

function mul(a: number[][], b: number[][]): number[][] {
    const m = a.length;
    const n = b[0].length;
    const c: number[][] = Array.from({ length: m }, () => Array(n).fill(0));

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            for (let k = 0; k < b.length; k++) {
                c[i][j] =
                    (c[i][j] + Number((BigInt(a[i][k]) * BigInt(b[k][j])) % BigInt(mod))) % mod;
            }
        }
    }
    return c;
}

function pow(a: number[][], n: number): number[][] {
    const size = a.length;
    let res: number[][] = Array.from({ length: 1 }, () => Array(size).fill(1));

    while (n > 0) {
        if (n % 2 === 1) {
            res = mul(res, a);
        }
        a = mul(a, a);
        n = Math.floor(n / 2);
    }

    return res;
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int KnightDialer(int n) {
        const int mod = 1000000007;
        long[] f = new long[10];
        for (int i = 0; i < 10; i++) {
            f[i] = 1;
        }

        while (--n > 0) {
            long[] g = new long[10];
            g[0] = (f[4] + f[6]) % mod;
            g[1] = (f[6] + f[8]) % mod;
            g[2] = (f[7] + f[9]) % mod;
            g[3] = (f[4] + f[8]) % mod;
            g[4] = (f[0] + f[3] + f[9]) % mod;
            g[6] = (f[0] + f[1] + f[7]) % mod;
            g[7] = (f[2] + f[6]) % mod;
            g[8] = (f[1] + f[3]) % mod;
            g[9] = (f[2] + f[4]) % mod;
            f = g;
        }

        return (int)(f.Sum() % mod);
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>象棋骑士有一个<strong>独特的移动方式</strong>，它可以垂直移动两个方格，水平移动一个方格，或者水平移动两个方格，垂直移动一个方格(两者都形成一个&nbsp;<strong>L&nbsp;</strong>的形状)。</p>

<p>象棋骑士可能的移动方式如下图所示:</p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0900-0999/0935.Knight%20Dialer/images/chess.jpg" style="height: 200px; width: 200px;" /></p>

<p>我们有一个象棋骑士和一个电话垫，如下所示，骑士<strong>只能站在一个数字单元格上</strong>(即蓝色单元格)。</p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0900-0999/0935.Knight%20Dialer/images/phone.jpg" style="height: 200px; width: 150px;" /></p>

<p>给定一个整数 n，返回我们可以拨多少个长度为 n 的不同电话号码。</p>

<p>你可以将骑士放置在<strong>任何数字单元格</strong>上，然后你应该执行 n - 1 次移动来获得长度为 n 的号码。所有的跳跃应该是<strong>有效</strong>的骑士跳跃。</p>

<p>因为答案可能很大，<strong>所以输出答案模&nbsp;</strong><code>10<sup>9</sup>&nbsp;+ 7</code>.</p>

<p>&nbsp;</p>

<ul>
</ul>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 1
<strong>输出：</strong>10
<strong>解释：</strong>我们需要拨一个长度为1的数字，所以把骑士放在10个单元格中的任何一个数字单元格上都能满足条件。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 2
<strong>输出：</strong>20
<strong>解释：</strong>我们可以拨打的所有有效号码为[04, 06, 16, 18, 27, 29, 34, 38, 40, 43, 49, 60, 61, 67, 72, 76, 81, 83, 92, 94]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 3131
<strong>输出：</strong>136006598
<strong>解释：</strong>注意取模
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 5000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：递推

根据题目描述，我们需要计算出长度为 $n$ 的不同电话号码的数量。其中，每个数字的上一个数字只有固定的几个，我们可以列出每个数字的上一个数字：

| 当前数字 | 上一个数字 |
| -------- | ---------- |
| 0        | 4, 6       |
| 1        | 6, 8       |
| 2        | 7, 9       |
| 3        | 4, 8       |
| 4        | 0, 3, 9    |
| 5        |            |
| 6        | 0, 1, 7    |
| 7        | 2, 6       |
| 8        | 1, 3       |
| 9        | 2, 4       |

我们可以通过递推的方式，计算出长度为 $n$ 的不同电话号码的数量。设 $f[i]$ 表示长度为 $i$ 的不同电话号码的数量，初始时 $f[1] = 1$。对于长度为 $i$ 的电话号码，我们可以通过长度为 $i - 1$ 的电话号码计算出来，因此我们可以得到递推关系：

$$
\begin{aligned}
g[0] & = f[4] + f[6] \\
g[1] & = f[6] + f[8] \\
g[2] & = f[7] + f[9] \\
g[3] & = f[4] + f[8] \\
g[4] & = f[0] + f[3] + f[9] \\
g[6] & = f[0] + f[1] + f[7] \\
g[7] & = f[2] + f[6] \\
g[8] & = f[1] + f[3] \\
g[9] & = f[2] + f[4]
\end{aligned}
$$

然后，我们将 $f$ 更新为 $g$，继续计算下一个长度的电话号码，直到计算出长度为 $n$ 的电话号码的数量。

最后，我们将 $f$ 中所有元素相加，取模 $10^9 + 7$，即为答案。

时间复杂度 $O(n)$，其中 $n$ 为电话号码的长度。空间复杂度 $O(|\Sigma|)$，其中 $\Sigma$ 为数字集合，本题中 $|\Sigma| = 10$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def knightDialer(self, n: int) -> int:
        f = [1] * 10
        for _ in range(n - 1):
            g = [0] * 10
            g[0] = f[4] + f[6]
            g[1] = f[6] + f[8]
            g[2] = f[7] + f[9]
            g[3] = f[4] + f[8]
            g[4] = f[0] + f[3] + f[9]
            g[6] = f[0] + f[1] + f[7]
            g[7] = f[2] + f[6]
            g[8] = f[1] + f[3]
            g[9] = f[2] + f[4]
            f = g
        return sum(f) % (10**9 + 7)
```

#### Java

```java
class Solution {
    public int knightDialer(int n) {
        final int mod = (int) 1e9 + 7;
        long[] f = new long[10];
        Arrays.fill(f, 1);
        while (--n > 0) {
            long[] g = new long[10];
            g[0] = (f[4] + f[6]) % mod;
            g[1] = (f[6] + f[8]) % mod;
            g[2] = (f[7] + f[9]) % mod;
            g[3] = (f[4] + f[8]) % mod;
            g[4] = (f[0] + f[3] + f[9]) % mod;
            g[6] = (f[0] + f[1] + f[7]) % mod;
            g[7] = (f[2] + f[6]) % mod;
            g[8] = (f[1] + f[3]) % mod;
            g[9] = (f[2] + f[4]) % mod;
            f = g;
        }
        return (int) (Arrays.stream(f).sum() % mod);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int knightDialer(int n) {
        const int mod = 1e9 + 7;
        vector<long long> f(10, 1);
        while (--n) {
            vector<long long> g(10);
            g[0] = (f[4] + f[6]) % mod;
            g[1] = (f[6] + f[8]) % mod;
            g[2] = (f[7] + f[9]) % mod;
            g[3] = (f[4] + f[8]) % mod;
            g[4] = (f[0] + f[3] + f[9]) % mod;
            g[6] = (f[0] + f[1] + f[7]) % mod;
            g[7] = (f[2] + f[6]) % mod;
            g[8] = (f[1] + f[3]) % mod;
            g[9] = (f[2] + f[4]) % mod;
            f = g;
        }
        return accumulate(f.begin(), f.end(), 0LL) % mod;
    }
};
```

#### Go

```go
func knightDialer(n int) (ans int) {
	f := make([]int, 10)
	for i := range f {
		f[i] = 1
	}
	const mod int = 1e9 + 7
	for i := 1; i < n; i++ {
		g := make([]int, 10)
		g[0] = (f[4] + f[6]) % mod
		g[1] = (f[6] + f[8]) % mod
		g[2] = (f[7] + f[9]) % mod
		g[3] = (f[4] + f[8]) % mod
		g[4] = (f[0] + f[3] + f[9]) % mod
		g[6] = (f[0] + f[1] + f[7]) % mod
		g[7] = (f[2] + f[6]) % mod
		g[8] = (f[1] + f[3]) % mod
		g[9] = (f[2] + f[4]) % mod
		f = g
	}
	for _, x := range f {
		ans = (ans + x) % mod
	}
	return
}
```

#### TypeScript

```ts
function knightDialer(n: number): number {
    const mod = 1e9 + 7;
    const f: number[] = Array(10).fill(1);
    while (--n) {
        const g: number[] = Array(10).fill(0);
        g[0] = (f[4] + f[6]) % mod;
        g[1] = (f[6] + f[8]) % mod;
        g[2] = (f[7] + f[9]) % mod;
        g[3] = (f[4] + f[8]) % mod;
        g[4] = (f[0] + f[3] + f[9]) % mod;
        g[6] = (f[0] + f[1] + f[7]) % mod;
        g[7] = (f[2] + f[6]) % mod;
        g[8] = (f[1] + f[3]) % mod;
        g[9] = (f[2] + f[4]) % mod;
        f.splice(0, 10, ...g);
    }
    return f.reduce((a, b) => (a + b) % mod);
}
```

#### C#

```cs
public class Solution {
    public int KnightDialer(int n) {
        const int mod = 1000000007;
        long[] f = new long[10];
        for (int i = 0; i < 10; i++) {
            f[i] = 1;
        }

        while (--n > 0) {
            long[] g = new long[10];
            g[0] = (f[4] + f[6]) % mod;
            g[1] = (f[6] + f[8]) % mod;
            g[2] = (f[7] + f[9]) % mod;
            g[3] = (f[4] + f[8]) % mod;
            g[4] = (f[0] + f[3] + f[9]) % mod;
            g[6] = (f[0] + f[1] + f[7]) % mod;
            g[7] = (f[2] + f[6]) % mod;
            g[8] = (f[1] + f[3]) % mod;
            g[9] = (f[2] + f[4]) % mod;
            f = g;
        }

        return (int)(f.Sum() % mod);
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：矩阵快速幂加速递推

我们假设 $T(n)$ 表示一个 $1 \times 10$ 的矩阵 $\begin{bmatrix} F_0 & F_1 & F_2 \cdots F_9 \end{bmatrix}$，其中 $F_i$ 表示第 $i$ 个电话号码的数量。我们希望根据 $T(n - 1)$ 推出 $T(n)$。也即是说，我们需要一个矩阵 $\textit{base}$，使得 $T(n - 1) \times \textit{base} = T(n)$，即：

$$
\begin{bmatrix}
F_0 & F_1 & F_2 \cdots F_9
\end{bmatrix} \times \textit{base} = \begin{bmatrix} F_0' & F_1' & F_2' \cdots F_9' \end{bmatrix}
$$

由于 $F_i' = \sum_{j} F_j$，其中 $j$ 是 $i$ 的上一个数字，所以矩阵 $\textit{base}$ 的第 $1$ 列为：

$$
\begin{bmatrix}
0 \\
0 \\
0 \\
0 \\
1 \\
0 \\
1 \\
0 \\
0 \\
0
\end{bmatrix}
$$

依次类推，我们可以得到矩阵 $\textit{base}$ 如下：

$$
\begin{bmatrix}
0 & 0 & 0 & 0 & 1 & 0 & 1 & 0 & 0 & 0 \\
0 & 0 & 0 & 0 & 0 & 0 & 1 & 0 & 1 & 0 \\
0 & 0 & 0 & 0 & 0 & 0 & 0 & 1 & 0 & 1 \\
0 & 0 & 0 & 0 & 1 & 0 & 0 & 0 & 1 & 0 \\
1 & 0 & 0 & 1 & 0 & 0 & 0 & 0 & 0 & 1 \\
0 & 0 & 0 & 0 & 0 & 0 & 0 & 0 & 0 & 0 \\
1 & 1 & 0 & 0 & 0 & 0 & 0 & 1 & 0 & 0 \\
0 & 0 & 1 & 0 & 0 & 0 & 1 & 0 & 0 & 0 \\
0 & 1 & 0 & 1 & 0 & 0 & 0 & 0 & 0 & 0 \\
0 & 0 & 1 & 0 & 1 & 0 & 0 & 0 & 0 & 0
\end{bmatrix}
$$

我们定义初始矩阵 $res = \begin{bmatrix} 1 & 1 & 1 \cdots 1 \end{bmatrix}$，与 $n - 1$ 个 $\textit{base}$ 矩阵相乘，即可得到 $T(n)$。最后，我们将 $T(n)$ 中所有元素相加，取模 $10^9 + 7$，即为答案。求 $\textit{base}^{n - 1}$，可以通过矩阵快速幂的方式，时间复杂度为 $O(\log n)$。

时间复杂度 $O(\log n)$，空间复杂度 $O(|\Sigma|^2)$，其中 $\Sigma$ 为数字集合，本题中 $|\Sigma| = 10$。

<!-- tabs:start -->

#### Python3

```python
import numpy as np

base = [
    (0, 0, 0, 0, 1, 0, 1, 0, 0, 0),
    (0, 0, 0, 0, 0, 0, 1, 0, 1, 0),
    (0, 0, 0, 0, 0, 0, 0, 1, 0, 1),
    (0, 0, 0, 0, 1, 0, 0, 0, 1, 0),
    (1, 0, 0, 1, 0, 0, 0, 0, 0, 1),
    (0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    (1, 1, 0, 0, 0, 0, 0, 1, 0, 0),
    (0, 0, 1, 0, 0, 0, 1, 0, 0, 0),
    (0, 1, 0, 1, 0, 0, 0, 0, 0, 0),
    (0, 0, 1, 0, 1, 0, 0, 0, 0, 0),
]


class Solution:
    def knightDialer(self, n: int) -> int:
        factor = np.asmatrix(base, np.dtype("O"))
        res = np.asmatrix([[1] * 10], np.dtype("O"))
        n -= 1
        mod = 10**9 + 7
        while n:
            if n & 1:
                res = res * factor % mod
            factor = factor * factor % mod
            n >>= 1
        return res.sum() % mod
```

#### Java

```java
class Solution {
    private final int mod = (int) 1e9 + 7;
    private final int[][] base = {{0, 0, 0, 0, 1, 0, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 1}, {0, 0, 0, 0, 1, 0, 0, 0, 1, 0},
        {1, 0, 0, 1, 0, 0, 0, 0, 0, 1}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 1, 0, 0, 0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 1, 0, 0, 0, 0, 0}};

    public int knightDialer(int n) {
        int[][] res = pow(base, n - 1);
        int ans = 0;
        for (int x : res[0]) {
            ans = (ans + x) % mod;
        }
        return ans;
    }

    private int[][] mul(int[][] a, int[][] b) {
        int m = a.length, n = b[0].length;
        int[][] c = new int[m][n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < b.length; ++k) {
                    c[i][j] = (int) ((c[i][j] + 1L * a[i][k] * b[k][j] % mod) % mod);
                }
            }
        }
        return c;
    }

    private int[][] pow(int[][] a, int n) {
        int[][] res = new int[1][a.length];
        Arrays.fill(res[0], 1);
        while (n > 0) {
            if ((n & 1) == 1) {
                res = mul(res, a);
            }
            a = mul(a, a);
            n >>= 1;
        }
        return res;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int knightDialer(int n) {
        const int mod = 1e9 + 7;
        vector<vector<int>> base = {
            {0, 0, 0, 0, 1, 0, 1, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 1, 0, 1, 0},
            {0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
            {0, 0, 0, 0, 1, 0, 0, 0, 1, 0},
            {1, 0, 0, 1, 0, 0, 0, 0, 0, 1},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {1, 1, 0, 0, 0, 0, 0, 1, 0, 0},
            {0, 0, 1, 0, 0, 0, 1, 0, 0, 0},
            {0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
            {0, 0, 1, 0, 1, 0, 0, 0, 0, 0}};
        vector<vector<int>> res = pow(base, n - 1, mod);
        return accumulate(res[0].begin(), res[0].end(), 0LL) % mod;
    }

private:
    vector<vector<int>> mul(const vector<vector<int>>& a, const vector<vector<int>>& b, int mod) {
        int m = a.size(), n = b[0].size();
        vector<vector<int>> c(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < b.size(); ++k) {
                    c[i][j] = (c[i][j] + (1LL * a[i][k] * b[k][j]) % mod) % mod;
                }
            }
        }
        return c;
    }

    vector<vector<int>> pow(vector<vector<int>>& a, int n, int mod) {
        int size = a.size();
        vector<vector<int>> res(1, vector<int>(size, 1));
        while (n > 0) {
            if (n % 2 == 1) {
                res = mul(res, a, mod);
            }
            a = mul(a, a, mod);
            n /= 2;
        }
        return res;
    }
};
```

#### Go

```go
const mod = 1e9 + 7

func knightDialer(n int) int {
	base := [][]int{
		{0, 0, 0, 0, 1, 0, 1, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 1, 0, 1, 0},
		{0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
		{0, 0, 0, 0, 1, 0, 0, 0, 1, 0},
		{1, 0, 0, 1, 0, 0, 0, 0, 0, 1},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{1, 1, 0, 0, 0, 0, 0, 1, 0, 0},
		{0, 0, 1, 0, 0, 0, 1, 0, 0, 0},
		{0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
		{0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
	}

	res := pow(base, n-1)
	ans := 0
	for _, x := range res[0] {
		ans = (ans + x) % mod
	}
	return ans
}

func mul(a, b [][]int) [][]int {
	m := len(a)
	n := len(b[0])
	c := make([][]int, m)
	for i := range c {
		c[i] = make([]int, n)
	}
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			for k := 0; k < len(b); k++ {
				c[i][j] = (c[i][j] + a[i][k]*b[k][j]) % mod
			}
		}
	}
	return c
}

func pow(a [][]int, n int) [][]int {
	size := len(a)
	res := make([][]int, 1)
	res[0] = make([]int, size)
	for i := 0; i < size; i++ {
		res[0][i] = 1
	}

	for n > 0 {
		if n%2 == 1 {
			res = mul(res, a)
		}
		a = mul(a, a)
		n /= 2
	}

	return res
}
```

#### TypeScript

```ts
const mod = 1e9 + 7;

function knightDialer(n: number): number {
    const base: number[][] = [
        [0, 0, 0, 0, 1, 0, 1, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 1, 0, 1, 0],
        [0, 0, 0, 0, 0, 0, 0, 1, 0, 1],
        [0, 0, 0, 0, 1, 0, 0, 0, 1, 0],
        [1, 0, 0, 1, 0, 0, 0, 0, 0, 1],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [1, 1, 0, 0, 0, 0, 0, 1, 0, 0],
        [0, 0, 1, 0, 0, 0, 1, 0, 0, 0],
        [0, 1, 0, 1, 0, 0, 0, 0, 0, 0],
        [0, 0, 1, 0, 1, 0, 0, 0, 0, 0],
    ];

    const res = pow(base, n - 1);
    let ans = 0;
    for (const x of res[0]) {
        ans = (ans + x) % mod;
    }
    return ans;
}

function mul(a: number[][], b: number[][]): number[][] {
    const m = a.length;
    const n = b[0].length;
    const c: number[][] = Array.from({ length: m }, () => Array(n).fill(0));

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            for (let k = 0; k < b.length; k++) {
                c[i][j] =
                    (c[i][j] + Number((BigInt(a[i][k]) * BigInt(b[k][j])) % BigInt(mod))) % mod;
            }
        }
    }
    return c;
}

function pow(a: number[][], n: number): number[][] {
    const size = a.length;
    let res: number[][] = Array.from({ length: 1 }, () => Array(size).fill(1));

    while (n > 0) {
        if (n % 2 === 1) {
            res = mul(res, a);
        }
        a = mul(a, a);
        n = Math.floor(n / 2);
    }

    return res;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [936. 戳印序列](https://leetcode.cn/problems/stamping-the-sequence){#936}

{{< tabs "936" >}}

{{% tab "python" %}}
```python
class Solution:
    def movesToStamp(self, stamp: str, target: str) -> List[int]:
        m, n = len(stamp), len(target)
        indeg = [m] * (n - m + 1)
        q = deque()
        g = [[] for _ in range(n)]
        for i in range(n - m + 1):
            for j, c in enumerate(stamp):
                if target[i + j] == c:
                    indeg[i] -= 1
                    if indeg[i] == 0:
                        q.append(i)
                else:
                    g[i + j].append(i)
        ans = []
        vis = [False] * n
        while q:
            i = q.popleft()
            ans.append(i)
            for j in range(m):
                if not vis[i + j]:
                    vis[i + j] = True
                    for k in g[i + j]:
                        indeg[k] -= 1
                        if indeg[k] == 0:
                            q.append(k)
        return ans[::-1] if all(vis) else []
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] movesToStamp(String stamp, String target) {
        int m = stamp.length(), n = target.length();
        int[] indeg = new int[n - m + 1];
        Arrays.fill(indeg, m);
        List<Integer>[] g = new List[n];
        Arrays.setAll(g, i -> new ArrayList<>());
        Deque<Integer> q = new ArrayDeque<>();
        for (int i = 0; i < n - m + 1; ++i) {
            for (int j = 0; j < m; ++j) {
                if (target.charAt(i + j) == stamp.charAt(j)) {
                    if (--indeg[i] == 0) {
                        q.offer(i);
                    }
                } else {
                    g[i + j].add(i);
                }
            }
        }
        List<Integer> ans = new ArrayList<>();
        boolean[] vis = new boolean[n];
        while (!q.isEmpty()) {
            int i = q.poll();
            ans.add(i);
            for (int j = 0; j < m; ++j) {
                if (!vis[i + j]) {
                    vis[i + j] = true;
                    for (int k : g[i + j]) {
                        if (--indeg[k] == 0) {
                            q.offer(k);
                        }
                    }
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                return new int[0];
            }
        }
        Collections.reverse(ans);
        return ans.stream().mapToInt(Integer::intValue).toArray();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        int m = stamp.size(), n = target.size();
        vector<int> indeg(n - m + 1, m);
        vector<int> g[n];
        queue<int> q;
        for (int i = 0; i < n - m + 1; ++i) {
            for (int j = 0; j < m; ++j) {
                if (target[i + j] == stamp[j]) {
                    if (--indeg[i] == 0) {
                        q.push(i);
                    }
                } else {
                    g[i + j].push_back(i);
                }
            }
        }
        vector<int> ans;
        vector<bool> vis(n);
        while (q.size()) {
            int i = q.front();
            q.pop();
            ans.push_back(i);
            for (int j = 0; j < m; ++j) {
                if (!vis[i + j]) {
                    vis[i + j] = true;
                    for (int k : g[i + j]) {
                        if (--indeg[k] == 0) {
                            q.push(k);
                        }
                    }
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                return {};
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func movesToStamp(stamp string, target string) (ans []int) {
	m, n := len(stamp), len(target)
	indeg := make([]int, n-m+1)
	for i := range indeg {
		indeg[i] = m
	}
	g := make([][]int, n)
	q := []int{}
	for i := 0; i < n-m+1; i++ {
		for j := range stamp {
			if target[i+j] == stamp[j] {
				indeg[i]--
				if indeg[i] == 0 {
					q = append(q, i)
				}
			} else {
				g[i+j] = append(g[i+j], i)
			}
		}
	}
	vis := make([]bool, n)
	for len(q) > 0 {
		i := q[0]
		q = q[1:]
		ans = append(ans, i)
		for j := range stamp {
			if !vis[i+j] {
				vis[i+j] = true
				for _, k := range g[i+j] {
					indeg[k]--
					if indeg[k] == 0 {
						q = append(q, k)
					}
				}
			}
		}
	}
	for _, v := range vis {
		if !v {
			return []int{}
		}
	}
	for i, j := 0, len(ans)-1; i < j; i, j = i+1, j-1 {
		ans[i], ans[j] = ans[j], ans[i]
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function movesToStamp(stamp: string, target: string): number[] {
    const m: number = stamp.length;
    const n: number = target.length;
    const indeg: number[] = Array(n - m + 1).fill(m);
    const g: number[][] = Array.from({ length: n }, () => []);
    const q: number[] = [];
    for (let i = 0; i < n - m + 1; ++i) {
        for (let j = 0; j < m; ++j) {
            if (target[i + j] === stamp[j]) {
                if (--indeg[i] === 0) {
                    q.push(i);
                }
            } else {
                g[i + j].push(i);
            }
        }
    }

    const ans: number[] = [];
    const vis: boolean[] = Array(n).fill(false);
    while (q.length) {
        const i: number = q.shift()!;
        ans.push(i);
        for (let j = 0; j < m; ++j) {
            if (!vis[i + j]) {
                vis[i + j] = true;
                for (const k of g[i + j]) {
                    if (--indeg[k] === 0) {
                        q.push(k);
                    }
                }
            }
        }
    }
    if (!vis.every(v => v)) {
        return [];
    }
    ans.reverse();
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::VecDeque;

impl Solution {
    pub fn moves_to_stamp(stamp: String, target: String) -> Vec<i32> {
        let m = stamp.len();
        let n = target.len();

        let mut indeg: Vec<usize> = vec![m; n - m + 1];
        let mut g: Vec<Vec<usize>> = vec![Vec::new(); n];
        let mut q: VecDeque<usize> = VecDeque::new();

        for i in 0..n - m + 1 {
            for j in 0..m {
                if target.chars().nth(i + j).unwrap() == stamp.chars().nth(j).unwrap() {
                    indeg[i] -= 1;
                    if indeg[i] == 0 {
                        q.push_back(i);
                    }
                } else {
                    g[i + j].push(i);
                }
            }
        }

        let mut ans: Vec<i32> = Vec::new();
        let mut vis: Vec<bool> = vec![false; n];

        while let Some(i) = q.pop_front() {
            ans.push(i as i32);

            for j in 0..m {
                if !vis[i + j] {
                    vis[i + j] = true;

                    for &k in g[i + j].iter() {
                        indeg[k] -= 1;
                        if indeg[k] == 0 {
                            q.push_back(k);
                        }
                    }
                }
            }
        }

        if vis.iter().all(|&v| v) {
            ans.reverse();
            ans
        } else {
            Vec::new()
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

<p>你想要用<strong>小写字母</strong>组成一个目标字符串&nbsp;<code>target</code>。&nbsp;</p>

<p>开始的时候，序列由&nbsp;<code>target.length</code>&nbsp;个&nbsp;<code>&#39;?&#39;</code>&nbsp;记号组成。而你有一个小写字母印章&nbsp;<code>stamp</code>。</p>

<p>在每个回合，你可以将印章放在序列上，并将序列中的每个字母替换为印章上的相应字母。你最多可以进行&nbsp;<code>10 * target.length</code>&nbsp; 个回合。</p>

<p>举个例子，如果初始序列为 &quot;?????&quot;，而你的印章 <code>stamp</code>&nbsp;是&nbsp;<code>&quot;abc&quot;</code>，那么在第一回合，你可以得到&nbsp;&quot;abc??&quot;、&quot;?abc?&quot;、&quot;??abc&quot;。（请注意，印章必须完全包含在序列的边界内才能盖下去。）</p>

<p>如果可以印出序列，那么返回一个数组，该数组由每个回合中被印下的最左边字母的索引组成。如果不能印出序列，就返回一个空数组。</p>

<p>例如，如果序列是 &quot;ababc&quot;，印章是 <code>&quot;abc&quot;</code>，那么我们就可以返回与操作&nbsp;&quot;?????&quot; -&gt; &quot;abc??&quot; -&gt; &quot;ababc&quot; 相对应的答案 <code>[0, 2]</code>；</p>

<p>另外，如果可以印出序列，那么需要保证可以在 <code>10 * target.length</code>&nbsp;个回合内完成。任何超过此数字的答案将不被接受。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>stamp = &quot;abc&quot;, target = &quot;ababc&quot;
<strong>输出：</strong>[0,2]
（[1,0,2] 以及其他一些可能的结果也将作为答案被接受）
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>stamp = &quot;abca&quot;, target = &quot;aabcaca&quot;
<strong>输出：</strong>[3,0,1]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ol>
	<li><code>1 &lt;= stamp.length &lt;= target.length &lt;= 1000</code></li>
	<li><code>stamp</code> 和&nbsp;<code>target</code>&nbsp;只包含小写字母。</li>
</ol>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：逆向思维 + 拓扑排序

如果我们正向地对序列进行操作，那么处理起来会比较麻烦，因为后续的操作会把前面的操作覆盖掉。我们不妨考虑逆向地对序列进行操作，即从目标字符串 $target$ 开始，考虑将 $target$ 变成 $?????$ 的过程。

我们不妨记字母印章的长度为 $m$，目标字符串的长度为 $n$。如果我们拿着字母印章在目标字符串上操作，那么一共有 $n-m+1$ 个开始位置可以放置字母印章。我们可以枚举这 $n-m+1$ 个开始位置，利用类似拓扑排序的方法，逆向地进行操作。

首先，我们明确，每个开始位置都对应着一个长度为 $m$ 的窗口。

接下来，我们定义以下数据结构或变量，其中：

-   入度数组 $indeg$，其中 $indeg[i]$ 表示第 $i$ 个窗口中有多少位置的字符与字母印章中的字符不同，初始时，$indeg[i]=m$。若 $indeg[i]=0$，说明第 $i$ 个窗口中的字符都与字母印章中的字符相同，那么我们就可以在第 $i$ 个窗口中放置字母印章。
-   邻接表 $g$，其中 $g[i]$ 表示目标字符串 $target$ 的第 $i$ 个位置上，所有与字母印章存在不同字符的窗口的集合。
-   队列 $q$，用于存储所有入度为 $0$ 的窗口的编号。
-   数组 $vis$，用于标记目标字符串 $target$ 的每个位置是否已经被覆盖。
-   数组 $ans$，用于存储答案。

接下来，我们进行拓扑排序。在拓扑排序的每一步中，我们取出队首的窗口编号 $i$，并将 $i$ 放入答案数组 $ans$ 中。然后，我们枚举字母印章中的每个位置 $j$，如果第 $i$ 个窗口中的第 $j$ 个位置未被覆盖，那么我们就将其覆盖，并将 $indeg$ 数组中所有与第 $i$ 个窗口中的第 $j$ 个位置相同的窗口的入度减少 $1$。如果某个窗口的入度变为 $0$，那么我们就将其放入队列 $q$ 中等待下一次处理。

在拓扑排序结束后，如果目标字符串 $target$ 的每个位置都被覆盖，那么答案数组 $ans$ 中存储的就是我们要求的答案。否则，目标字符串 $target$ 无法被覆盖，我们就返回一个空数组。

时间复杂度 $O(n \times (n - m + 1))$，空间复杂度 $O(n \times (n - m + 1))$。其中 $n$ 和 $m$ 分别是目标字符串 $target$ 和字母印章的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def movesToStamp(self, stamp: str, target: str) -> List[int]:
        m, n = len(stamp), len(target)
        indeg = [m] * (n - m + 1)
        q = deque()
        g = [[] for _ in range(n)]
        for i in range(n - m + 1):
            for j, c in enumerate(stamp):
                if target[i + j] == c:
                    indeg[i] -= 1
                    if indeg[i] == 0:
                        q.append(i)
                else:
                    g[i + j].append(i)
        ans = []
        vis = [False] * n
        while q:
            i = q.popleft()
            ans.append(i)
            for j in range(m):
                if not vis[i + j]:
                    vis[i + j] = True
                    for k in g[i + j]:
                        indeg[k] -= 1
                        if indeg[k] == 0:
                            q.append(k)
        return ans[::-1] if all(vis) else []
```

#### Java

```java
class Solution {
    public int[] movesToStamp(String stamp, String target) {
        int m = stamp.length(), n = target.length();
        int[] indeg = new int[n - m + 1];
        Arrays.fill(indeg, m);
        List<Integer>[] g = new List[n];
        Arrays.setAll(g, i -> new ArrayList<>());
        Deque<Integer> q = new ArrayDeque<>();
        for (int i = 0; i < n - m + 1; ++i) {
            for (int j = 0; j < m; ++j) {
                if (target.charAt(i + j) == stamp.charAt(j)) {
                    if (--indeg[i] == 0) {
                        q.offer(i);
                    }
                } else {
                    g[i + j].add(i);
                }
            }
        }
        List<Integer> ans = new ArrayList<>();
        boolean[] vis = new boolean[n];
        while (!q.isEmpty()) {
            int i = q.poll();
            ans.add(i);
            for (int j = 0; j < m; ++j) {
                if (!vis[i + j]) {
                    vis[i + j] = true;
                    for (int k : g[i + j]) {
                        if (--indeg[k] == 0) {
                            q.offer(k);
                        }
                    }
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                return new int[0];
            }
        }
        Collections.reverse(ans);
        return ans.stream().mapToInt(Integer::intValue).toArray();
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        int m = stamp.size(), n = target.size();
        vector<int> indeg(n - m + 1, m);
        vector<int> g[n];
        queue<int> q;
        for (int i = 0; i < n - m + 1; ++i) {
            for (int j = 0; j < m; ++j) {
                if (target[i + j] == stamp[j]) {
                    if (--indeg[i] == 0) {
                        q.push(i);
                    }
                } else {
                    g[i + j].push_back(i);
                }
            }
        }
        vector<int> ans;
        vector<bool> vis(n);
        while (q.size()) {
            int i = q.front();
            q.pop();
            ans.push_back(i);
            for (int j = 0; j < m; ++j) {
                if (!vis[i + j]) {
                    vis[i + j] = true;
                    for (int k : g[i + j]) {
                        if (--indeg[k] == 0) {
                            q.push(k);
                        }
                    }
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                return {};
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```

#### Go

```go
func movesToStamp(stamp string, target string) (ans []int) {
	m, n := len(stamp), len(target)
	indeg := make([]int, n-m+1)
	for i := range indeg {
		indeg[i] = m
	}
	g := make([][]int, n)
	q := []int{}
	for i := 0; i < n-m+1; i++ {
		for j := range stamp {
			if target[i+j] == stamp[j] {
				indeg[i]--
				if indeg[i] == 0 {
					q = append(q, i)
				}
			} else {
				g[i+j] = append(g[i+j], i)
			}
		}
	}
	vis := make([]bool, n)
	for len(q) > 0 {
		i := q[0]
		q = q[1:]
		ans = append(ans, i)
		for j := range stamp {
			if !vis[i+j] {
				vis[i+j] = true
				for _, k := range g[i+j] {
					indeg[k]--
					if indeg[k] == 0 {
						q = append(q, k)
					}
				}
			}
		}
	}
	for _, v := range vis {
		if !v {
			return []int{}
		}
	}
	for i, j := 0, len(ans)-1; i < j; i, j = i+1, j-1 {
		ans[i], ans[j] = ans[j], ans[i]
	}
	return
}
```

#### TypeScript

```ts
function movesToStamp(stamp: string, target: string): number[] {
    const m: number = stamp.length;
    const n: number = target.length;
    const indeg: number[] = Array(n - m + 1).fill(m);
    const g: number[][] = Array.from({ length: n }, () => []);
    const q: number[] = [];
    for (let i = 0; i < n - m + 1; ++i) {
        for (let j = 0; j < m; ++j) {
            if (target[i + j] === stamp[j]) {
                if (--indeg[i] === 0) {
                    q.push(i);
                }
            } else {
                g[i + j].push(i);
            }
        }
    }

    const ans: number[] = [];
    const vis: boolean[] = Array(n).fill(false);
    while (q.length) {
        const i: number = q.shift()!;
        ans.push(i);
        for (let j = 0; j < m; ++j) {
            if (!vis[i + j]) {
                vis[i + j] = true;
                for (const k of g[i + j]) {
                    if (--indeg[k] === 0) {
                        q.push(k);
                    }
                }
            }
        }
    }
    if (!vis.every(v => v)) {
        return [];
    }
    ans.reverse();
    return ans;
}
```

#### Rust

```rust
use std::collections::VecDeque;

impl Solution {
    pub fn moves_to_stamp(stamp: String, target: String) -> Vec<i32> {
        let m = stamp.len();
        let n = target.len();

        let mut indeg: Vec<usize> = vec![m; n - m + 1];
        let mut g: Vec<Vec<usize>> = vec![Vec::new(); n];
        let mut q: VecDeque<usize> = VecDeque::new();

        for i in 0..n - m + 1 {
            for j in 0..m {
                if target.chars().nth(i + j).unwrap() == stamp.chars().nth(j).unwrap() {
                    indeg[i] -= 1;
                    if indeg[i] == 0 {
                        q.push_back(i);
                    }
                } else {
                    g[i + j].push(i);
                }
            }
        }

        let mut ans: Vec<i32> = Vec::new();
        let mut vis: Vec<bool> = vec![false; n];

        while let Some(i) = q.pop_front() {
            ans.push(i as i32);

            for j in 0..m {
                if !vis[i + j] {
                    vis[i + j] = true;

                    for &k in g[i + j].iter() {
                        indeg[k] -= 1;
                        if indeg[k] == 0 {
                            q.push_back(k);
                        }
                    }
                }
            }
        }

        if vis.iter().all(|&v| v) {
            ans.reverse();
            ans
        } else {
            Vec::new()
        }
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [937. 重新排列日志文件](https://leetcode.cn/problems/reorder-data-in-log-files){#937}

{{< tabs "937" >}}

{{% tab "python" %}}
```python
class Solution:
    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        def f(log: str):
            id_, rest = log.split(" ", 1)
            return (0, rest, id_) if rest[0].isalpha() else (1,)

        return sorted(logs, key=f)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String[] reorderLogFiles(String[] logs) {
        Arrays.sort(logs, (log1, log2) -> {
            String[] split1 = log1.split(" ", 2);
            String[] split2 = log2.split(" ", 2);

            boolean isLetter1 = Character.isLetter(split1[1].charAt(0));
            boolean isLetter2 = Character.isLetter(split2[1].charAt(0));

            if (isLetter1 && isLetter2) {
                int cmp = split1[1].compareTo(split2[1]);
                if (cmp != 0) {
                    return cmp;
                }
                return split1[0].compareTo(split2[0]);
            }

            return isLetter1 ? -1 : (isLetter2 ? 1 : 0);
        });

        return logs;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        stable_sort(logs.begin(), logs.end(), [](const string& log1, const string& log2) {
            int idx1 = log1.find(' ');
            int idx2 = log2.find(' ');
            string id1 = log1.substr(0, idx1);
            string id2 = log2.substr(0, idx2);
            string content1 = log1.substr(idx1 + 1);
            string content2 = log2.substr(idx2 + 1);

            bool isLetter1 = isalpha(content1[0]);
            bool isLetter2 = isalpha(content2[0]);

            if (isLetter1 && isLetter2) {
                if (content1 != content2) {
                    return content1 < content2;
                }
                return id1 < id2;
            }

            return isLetter1 > isLetter2;
        });

        return logs;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func reorderLogFiles(logs []string) []string {
	sort.SliceStable(logs, func(i, j int) bool {
		log1, log2 := logs[i], logs[j]
		idx1 := strings.IndexByte(log1, ' ')
		idx2 := strings.IndexByte(log2, ' ')
		id1, content1 := log1[:idx1], log1[idx1+1:]
		id2, content2 := log2[:idx2], log2[idx2+1:]

		isLetter1 := 'a' <= content1[0] && content1[0] <= 'z'
		isLetter2 := 'a' <= content2[0] && content2[0] <= 'z'

		if isLetter1 && isLetter2 {
			if content1 != content2 {
				return content1 < content2
			}
			return id1 < id2
		}

		return isLetter1 && !isLetter2
	})

	return logs
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function reorderLogFiles(logs: string[]): string[] {
    return logs.sort((log1, log2) => {
        const [id1, content1] = log1.split(/ (.+)/);
        const [id2, content2] = log2.split(/ (.+)/);

        const isLetter1 = isNaN(Number(content1[0]));
        const isLetter2 = isNaN(Number(content2[0]));

        if (isLetter1 && isLetter2) {
            const cmp = content1.localeCompare(content2);
            if (cmp !== 0) {
                return cmp;
            }
            return id1.localeCompare(id2);
        }

        return isLetter1 ? -1 : isLetter2 ? 1 : 0;
    });
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::cmp::Ordering;

impl Solution {
    pub fn reorder_log_files(logs: Vec<String>) -> Vec<String> {
        let mut logs = logs;

        logs.sort_by(|log1, log2| {
            let split1: Vec<&str> = log1.splitn(2, ' ').collect();
            let split2: Vec<&str> = log2.splitn(2, ' ').collect();

            let is_letter1 = split1[1].chars().next().unwrap().is_alphabetic();
            let is_letter2 = split2[1].chars().next().unwrap().is_alphabetic();

            if is_letter1 && is_letter2 {
                let cmp = split1[1].cmp(split2[1]);
                if cmp != Ordering::Equal {
                    return cmp;
                }
                return split1[0].cmp(split2[0]);
            }

            if is_letter1 {
                Ordering::Less
            } else if is_letter2 {
                Ordering::Greater
            } else {
                Ordering::Equal
            }
        });

        logs
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个日志数组 <code>logs</code>。每条日志都是以空格分隔的字串，其第一个字为字母与数字混合的<em> </em><strong>标识符 </strong>。</p>

<p>有两种不同类型的日志：</p>

<ul>
	<li><strong>字母日志</strong>：除标识符之外，所有字均由小写字母组成</li>
	<li><strong>数字日志</strong>：除标识符之外，所有字均由数字组成</li>
</ul>

<p>请按下述规则将日志重新排序：</p>

<ul>
	<li>所有 <strong>字母日志</strong> 都排在 <strong>数字日志</strong> 之前。</li>
	<li><strong>字母日志</strong> 在内容不同时，忽略标识符后，按内容字母顺序排序；在内容相同时，按标识符排序。</li>
	<li><strong>数字日志</strong> 应该保留原来的相对顺序。</li>
</ul>

<p>返回日志的最终顺序。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>logs = ["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]
<strong>输出：</strong>["let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5 1","dig2 3 6"]
<strong>解释：</strong>
字母日志的内容都不同，所以顺序为 "art can", "art zero", "own kit dig" 。
数字日志保留原来的相对顺序 "dig1 8 1 5 1", "dig2 3 6" 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>logs = ["a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"]
<strong>输出：</strong>["g1 act car","a8 act zoo","ab1 off key dog","a1 9 2 3 1","zo4 4 7"]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= logs.length <= 100</code></li>
	<li><code>3 <= logs[i].length <= 100</code></li>
	<li><code>logs[i]</code> 中，字与字之间都用 <strong>单个</strong> 空格分隔</li>
	<li>题目数据保证 <code>logs[i]</code> 都有一个标识符，并且在标识符之后至少存在一个字</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：自定义排序

我们可以使用自定义排序的方法，将日志分为两类：字母日志和数字日志。

对于字母日志，我们需要按照题目要求进行排序，即先按内容排序，再按标识符排序。

对于数字日志，我们只需要保留原来的相对顺序。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 是日志的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        def f(log: str):
            id_, rest = log.split(" ", 1)
            return (0, rest, id_) if rest[0].isalpha() else (1,)

        return sorted(logs, key=f)
```

#### Java

```java
class Solution {
    public String[] reorderLogFiles(String[] logs) {
        Arrays.sort(logs, (log1, log2) -> {
            String[] split1 = log1.split(" ", 2);
            String[] split2 = log2.split(" ", 2);

            boolean isLetter1 = Character.isLetter(split1[1].charAt(0));
            boolean isLetter2 = Character.isLetter(split2[1].charAt(0));

            if (isLetter1 && isLetter2) {
                int cmp = split1[1].compareTo(split2[1]);
                if (cmp != 0) {
                    return cmp;
                }
                return split1[0].compareTo(split2[0]);
            }

            return isLetter1 ? -1 : (isLetter2 ? 1 : 0);
        });

        return logs;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        stable_sort(logs.begin(), logs.end(), [](const string& log1, const string& log2) {
            int idx1 = log1.find(' ');
            int idx2 = log2.find(' ');
            string id1 = log1.substr(0, idx1);
            string id2 = log2.substr(0, idx2);
            string content1 = log1.substr(idx1 + 1);
            string content2 = log2.substr(idx2 + 1);

            bool isLetter1 = isalpha(content1[0]);
            bool isLetter2 = isalpha(content2[0]);

            if (isLetter1 && isLetter2) {
                if (content1 != content2) {
                    return content1 < content2;
                }
                return id1 < id2;
            }

            return isLetter1 > isLetter2;
        });

        return logs;
    }
};
```

#### Go

```go
func reorderLogFiles(logs []string) []string {
	sort.SliceStable(logs, func(i, j int) bool {
		log1, log2 := logs[i], logs[j]
		idx1 := strings.IndexByte(log1, ' ')
		idx2 := strings.IndexByte(log2, ' ')
		id1, content1 := log1[:idx1], log1[idx1+1:]
		id2, content2 := log2[:idx2], log2[idx2+1:]

		isLetter1 := 'a' <= content1[0] && content1[0] <= 'z'
		isLetter2 := 'a' <= content2[0] && content2[0] <= 'z'

		if isLetter1 && isLetter2 {
			if content1 != content2 {
				return content1 < content2
			}
			return id1 < id2
		}

		return isLetter1 && !isLetter2
	})

	return logs
}
```

#### TypeScript

```ts
function reorderLogFiles(logs: string[]): string[] {
    return logs.sort((log1, log2) => {
        const [id1, content1] = log1.split(/ (.+)/);
        const [id2, content2] = log2.split(/ (.+)/);

        const isLetter1 = isNaN(Number(content1[0]));
        const isLetter2 = isNaN(Number(content2[0]));

        if (isLetter1 && isLetter2) {
            const cmp = content1.localeCompare(content2);
            if (cmp !== 0) {
                return cmp;
            }
            return id1.localeCompare(id2);
        }

        return isLetter1 ? -1 : isLetter2 ? 1 : 0;
    });
}
```

#### Rust

```rust
use std::cmp::Ordering;

impl Solution {
    pub fn reorder_log_files(logs: Vec<String>) -> Vec<String> {
        let mut logs = logs;

        logs.sort_by(|log1, log2| {
            let split1: Vec<&str> = log1.splitn(2, ' ').collect();
            let split2: Vec<&str> = log2.splitn(2, ' ').collect();

            let is_letter1 = split1[1].chars().next().unwrap().is_alphabetic();
            let is_letter2 = split2[1].chars().next().unwrap().is_alphabetic();

            if is_letter1 && is_letter2 {
                let cmp = split1[1].cmp(split2[1]);
                if cmp != Ordering::Equal {
                    return cmp;
                }
                return split1[0].cmp(split2[0]);
            }

            if is_letter1 {
                Ordering::Less
            } else if is_letter2 {
                Ordering::Greater
            } else {
                Ordering::Equal
            }
        });

        logs
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [938. 二叉搜索树的范围和](https://leetcode.cn/problems/range-sum-of-bst){#938}

{{< tabs "938" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rangeSumBST(self, root: Optional[TreeNode], low: int, high: int) -> int:
        def dfs(root: Optional[TreeNode]) -> int:
            if root is None:
                return 0
            x = root.val
            ans = x if low <= x <= high else 0
            if x > low:
                ans += dfs(root.left)
            if x < high:
                ans += dfs(root.right)
            return ans

        return dfs(root)
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
    public int rangeSumBST(TreeNode root, int low, int high) {
        return dfs(root, low, high);
    }

    private int dfs(TreeNode root, int low, int high) {
        if (root == null) {
            return 0;
        }
        int x = root.val;
        int ans = low <= x && x <= high ? x : 0;
        if (x > low) {
            ans += dfs(root.left, low, high);
        }
        if (x < high) {
            ans += dfs(root.right, low, high);
        }
        return ans;
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
    int rangeSumBST(TreeNode* root, int low, int high) {
        function<int(TreeNode*)> dfs = [&](TreeNode* root) {
            if (!root) {
                return 0;
            }
            int x = root->val;
            int ans = low <= x && x <= high ? x : 0;
            if (x > low) {
                ans += dfs(root->left);
            }
            if (x < high) {
                ans += dfs(root->right);
            }
            return ans;
        };
        return dfs(root);
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
func rangeSumBST(root *TreeNode, low int, high int) int {
	var dfs func(*TreeNode) int
	dfs = func(root *TreeNode) (ans int) {
		if root == nil {
			return 0
		}
		x := root.Val
		if low <= x && x <= high {
			ans += x
		}
		if x > low {
			ans += dfs(root.Left)
		}
		if x < high {
			ans += dfs(root.Right)
		}
		return
	}
	return dfs(root)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function rangeSumBST(root: TreeNode | null, low: number, high: number): number {
    const dfs = (root: TreeNode | null): number => {
        if (!root) {
            return 0;
        }
        const { val, left, right } = root;
        let ans = low <= val && val <= high ? val : 0;
        if (val > low) {
            ans += dfs(left);
        }
        if (val < high) {
            ans += dfs(right);
        }
        return ans;
    };
    return dfs(root);
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
    public int RangeSumBST(TreeNode root, int low, int high) {
        return dfs(root, low, high);
    }

    private int dfs(TreeNode root, int low, int high) {
        if (root == null) {
            return 0;
        }
        int x = root.val;
        int ans = low <= x && x <= high ? x : 0;
        if (x > low) {
            ans += dfs(root.left, low, high);
        }
        if (x < high) {
            ans += dfs(root.right, low, high);
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

<p>给定二叉搜索树的根结点 <code>root</code>，返回值位于范围 <em><code>[low, high]</code></em> 之间的所有结点的值的和。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0900-0999/0938.Range%20Sum%20of%20BST/images/bst1.jpg" style="width: 400px; height: 222px;" />
<pre>
<strong>输入：</strong>root = [10,5,15,3,7,null,18], low = 7, high = 15
<strong>输出：</strong>32
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0900-0999/0938.Range%20Sum%20of%20BST/images/bst2.jpg" style="width: 400px; height: 335px;" />
<pre>
<strong>输入：</strong>root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10
<strong>输出：</strong>23
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点数目在范围 <code>[1, 2 * 10<sup>4</sup>]</code> 内</li>
	<li><code>1 <= Node.val <= 10<sup>5</sup></code></li>
	<li><code>1 <= low <= high <= 10<sup>5</sup></code></li>
	<li>所有 <code>Node.val</code> <strong>互不相同</strong></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS

我们设计一个函数 $dfs(root)$，表示求以 $root$ 为根的子树中，值位于范围 $[low, high]$ 之间的所有结点的值的和。那么答案就是 $dfs(root)$。

函数 $dfs(root)$ 的执行逻辑如下：

-   如果 $root$ 为空，返回 $0$。
-   如果 $root$ 的值 $x$ 在范围 $[low, high]$ 之间，那么函数 $dfs(root)$ 的初始答案就是 $x$，否则为 $0$。
-   如果 $x > low$，说明 $root$ 的左子树中可能有值在范围 $[low, high]$ 之间的结点，所以我们需要递归调用 $dfs(root.left)$，并将结果加到答案上。
-   如果 $x < high$，说明 $root$ 的右子树中可能有值在范围 $[low, high]$ 之间的结点，所以我们需要递归调用 $dfs(root.right)$，并将结果加到答案上。
-   最后返回答案。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是二叉搜索树的结点个数。

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
    def rangeSumBST(self, root: Optional[TreeNode], low: int, high: int) -> int:
        def dfs(root: Optional[TreeNode]) -> int:
            if root is None:
                return 0
            x = root.val
            ans = x if low <= x <= high else 0
            if x > low:
                ans += dfs(root.left)
            if x < high:
                ans += dfs(root.right)
            return ans

        return dfs(root)
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
    public int rangeSumBST(TreeNode root, int low, int high) {
        return dfs(root, low, high);
    }

    private int dfs(TreeNode root, int low, int high) {
        if (root == null) {
            return 0;
        }
        int x = root.val;
        int ans = low <= x && x <= high ? x : 0;
        if (x > low) {
            ans += dfs(root.left, low, high);
        }
        if (x < high) {
            ans += dfs(root.right, low, high);
        }
        return ans;
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
    int rangeSumBST(TreeNode* root, int low, int high) {
        function<int(TreeNode*)> dfs = [&](TreeNode* root) {
            if (!root) {
                return 0;
            }
            int x = root->val;
            int ans = low <= x && x <= high ? x : 0;
            if (x > low) {
                ans += dfs(root->left);
            }
            if (x < high) {
                ans += dfs(root->right);
            }
            return ans;
        };
        return dfs(root);
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
func rangeSumBST(root *TreeNode, low int, high int) int {
	var dfs func(*TreeNode) int
	dfs = func(root *TreeNode) (ans int) {
		if root == nil {
			return 0
		}
		x := root.Val
		if low <= x && x <= high {
			ans += x
		}
		if x > low {
			ans += dfs(root.Left)
		}
		if x < high {
			ans += dfs(root.Right)
		}
		return
	}
	return dfs(root)
}
```

#### TypeScript

```ts
/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function rangeSumBST(root: TreeNode | null, low: number, high: number): number {
    const dfs = (root: TreeNode | null): number => {
        if (!root) {
            return 0;
        }
        const { val, left, right } = root;
        let ans = low <= val && val <= high ? val : 0;
        if (val > low) {
            ans += dfs(left);
        }
        if (val < high) {
            ans += dfs(right);
        }
        return ans;
    };
    return dfs(root);
}
```

#### C#

```cs
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
    public int RangeSumBST(TreeNode root, int low, int high) {
        return dfs(root, low, high);
    }

    private int dfs(TreeNode root, int low, int high) {
        if (root == null) {
            return 0;
        }
        int x = root.val;
        int ans = low <= x && x <= high ? x : 0;
        if (x > low) {
            ans += dfs(root.left, low, high);
        }
        if (x < high) {
            ans += dfs(root.right, low, high);
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

# [939. 最小面积矩形](https://leetcode.cn/problems/minimum-area-rectangle){#939}

{{< tabs "939" >}}

{{% tab "python" %}}
```python
class Solution:
    def minAreaRect(self, points: List[List[int]]) -> int:
        d = defaultdict(list)
        for x, y in points:
            d[x].append(y)
        pos = {}
        ans = inf
        for x in sorted(d):
            ys = d[x]
            ys.sort()
            n = len(ys)
            for i, y1 in enumerate(ys):
                for y2 in ys[i + 1 :]:
                    if (y1, y2) in pos:
                        ans = min(ans, (x - pos[(y1, y2)]) * (y2 - y1))
                    pos[(y1, y2)] = x
        return 0 if ans == inf else ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minAreaRect(int[][] points) {
        TreeMap<Integer, List<Integer>> d = new TreeMap<>();
        for (var p : points) {
            int x = p[0], y = p[1];
            d.computeIfAbsent(x, k -> new ArrayList<>()).add(y);
        }
        Map<Integer, Integer> pos = new HashMap<>();
        int ans = 1 << 30;
        for (var e : d.entrySet()) {
            int x = e.getKey();
            var ys = e.getValue();
            Collections.sort(ys);
            int n = ys.size();
            for (int i = 0; i < n; ++i) {
                int y1 = ys.get(i);
                for (int j = i + 1; j < n; ++j) {
                    int y2 = ys.get(j);
                    int p = y1 * 40001 + y2;
                    if (pos.containsKey(p)) {
                        ans = Math.min(ans, (x - pos.get(p)) * (y2 - y1));
                    }
                    pos.put(p, x);
                }
            }
        }
        return ans == 1 << 30 ? 0 : ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        map<int, vector<int>> d;
        for (auto& p : points) {
            int x = p[0], y = p[1];
            d[x].emplace_back(y);
        }
        unordered_map<int, int> pos;
        int ans = 1 << 30;
        for (auto& [x, ys] : d) {
            sort(ys.begin(), ys.end());
            int n = ys.size();
            for (int i = 0; i < n; ++i) {
                int y1 = ys[i];
                for (int j = i + 1; j < n; ++j) {
                    int y2 = ys[j];
                    int p = y1 * 40001 + y2;
                    if (pos.count(p)) {
                        ans = min(ans, (x - pos[p]) * (y2 - y1));
                    }
                    pos[p] = x;
                }
            }
        }
        return ans == 1 << 30 ? 0 : ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minAreaRect(points [][]int) int {
	d := map[int][]int{}
	xs := []int{}
	for _, p := range points {
		x, y := p[0], p[1]
		d[x] = append(d[x], y)
	}
	for x := range d {
		xs = append(xs, x)
	}
	sort.Ints(xs)
	type pair struct{ x, y int }
	pos := map[pair]int{}
	ans := 1 << 30
	for _, x := range xs {
		ys := d[x]
		sort.Ints(ys)
		for i, y1 := range ys {
			for _, y2 := range ys[i+1:] {
				p := pair{y1, y2}
				if x1, ok := pos[p]; ok {
					ans = min(ans, (x-x1)*(y2-y1))
				}
				pos[p] = x
			}
		}
	}
	if ans == 1<<30 {
		return 0
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

<p>给你一个&nbsp;<strong>X-Y&nbsp;</strong>平面上的点数组 <code>points</code>，其中 <code>points[i] = [x<sub>i</sub>, y<sub>i</sub>]</code>。</p>

<p>返回由这些点形成的矩形的最小面积，矩形的边与 X 轴和 Y 轴平行。如果不存在这样的矩形，则返回 <code>0</code>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0900-0999/0939.Minimum%20Area%20Rectangle/images/rec1.jpg" style="width: 500px; height: 447px;" />
<pre>
<strong>输入：</strong> points = [[1,1],[1,3],[3,1],[3,3],[2,2]]
<strong>输出：</strong> 4
</pre>

<p><strong class="example">示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0900-0999/0939.Minimum%20Area%20Rectangle/images/rec2.jpg" style="width: 500px; height: 477px;" />
<pre>
<strong>输入：</strong> points = [[1,1],[1,3],[3,1],[3,3],[4,1],[4,3]]
<strong>输出：</strong> 2
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= points.length &lt;= 500</code></li>
	<li><code>points[i].length == 2</code></li>
	<li><code>0 &lt;= x<sub>i</sub>, y<sub>i</sub> &lt;= 4 * 10<sup>4</sup></code></li>
	<li>所有给定的点都是&nbsp;<strong>唯一&nbsp;</strong>的。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 排序 + 枚举

对于每个点，我们将其横坐标作为键，纵坐标作为值存入哈希表 $d$ 中。对于哈希表中的每个键，我们将其对应的纵坐标按照从小到大的顺序排序。

然后我们从小到大枚举横坐标，对于每个横坐标，我们枚举其对应的纵坐标中的所有点对 $(y_1, y_2)$，其中 $y_1 \lt y_2$。如果我们之前已经遇到过点对 $(y_1, y_2)$，那么就可以用当前的横坐标和之前的横坐标计算出一个矩形的面积。我们用哈希表 $pos$ 记录每个点对 $(y_1, y_2)$ 第一次出现的横坐标，这样我们就可以在常数时间内找到这个横坐标。

最后，我们返回所有矩形的面积中的最小值。

时间复杂度 $O(n^2 \times \log n)$，空间复杂度 $O(n^2)$。其中 $n$ 是点的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minAreaRect(self, points: List[List[int]]) -> int:
        d = defaultdict(list)
        for x, y in points:
            d[x].append(y)
        pos = {}
        ans = inf
        for x in sorted(d):
            ys = d[x]
            ys.sort()
            n = len(ys)
            for i, y1 in enumerate(ys):
                for y2 in ys[i + 1 :]:
                    if (y1, y2) in pos:
                        ans = min(ans, (x - pos[(y1, y2)]) * (y2 - y1))
                    pos[(y1, y2)] = x
        return 0 if ans == inf else ans
```

#### Java

```java
class Solution {
    public int minAreaRect(int[][] points) {
        TreeMap<Integer, List<Integer>> d = new TreeMap<>();
        for (var p : points) {
            int x = p[0], y = p[1];
            d.computeIfAbsent(x, k -> new ArrayList<>()).add(y);
        }
        Map<Integer, Integer> pos = new HashMap<>();
        int ans = 1 << 30;
        for (var e : d.entrySet()) {
            int x = e.getKey();
            var ys = e.getValue();
            Collections.sort(ys);
            int n = ys.size();
            for (int i = 0; i < n; ++i) {
                int y1 = ys.get(i);
                for (int j = i + 1; j < n; ++j) {
                    int y2 = ys.get(j);
                    int p = y1 * 40001 + y2;
                    if (pos.containsKey(p)) {
                        ans = Math.min(ans, (x - pos.get(p)) * (y2 - y1));
                    }
                    pos.put(p, x);
                }
            }
        }
        return ans == 1 << 30 ? 0 : ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        map<int, vector<int>> d;
        for (auto& p : points) {
            int x = p[0], y = p[1];
            d[x].emplace_back(y);
        }
        unordered_map<int, int> pos;
        int ans = 1 << 30;
        for (auto& [x, ys] : d) {
            sort(ys.begin(), ys.end());
            int n = ys.size();
            for (int i = 0; i < n; ++i) {
                int y1 = ys[i];
                for (int j = i + 1; j < n; ++j) {
                    int y2 = ys[j];
                    int p = y1 * 40001 + y2;
                    if (pos.count(p)) {
                        ans = min(ans, (x - pos[p]) * (y2 - y1));
                    }
                    pos[p] = x;
                }
            }
        }
        return ans == 1 << 30 ? 0 : ans;
    }
};
```

#### Go

```go
func minAreaRect(points [][]int) int {
	d := map[int][]int{}
	xs := []int{}
	for _, p := range points {
		x, y := p[0], p[1]
		d[x] = append(d[x], y)
	}
	for x := range d {
		xs = append(xs, x)
	}
	sort.Ints(xs)
	type pair struct{ x, y int }
	pos := map[pair]int{}
	ans := 1 << 30
	for _, x := range xs {
		ys := d[x]
		sort.Ints(ys)
		for i, y1 := range ys {
			for _, y2 := range ys[i+1:] {
				p := pair{y1, y2}
				if x1, ok := pos[p]; ok {
					ans = min(ans, (x-x1)*(y2-y1))
				}
				pos[p] = x
			}
		}
	}
	if ans == 1<<30 {
		return 0
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
