---
title: "3200_三角形的最大高度"
date: 2025-10-08T18:40:15+08:00
weight: 1
tags: [二分查找, 位运算, 动态规划, 单调栈, 图, 广度优先搜索, 数据库, 数组, 枚举, 栈, 树, 深度优先搜索, 滑动窗口, 线段树, 贪心]
---

{{< markmap >}}
### [3200_三角形的最大高度](#3200)
#### [数组](#3200)
#### [枚举](#3200)
### [3201_找出有效子序列的最大长度 I](#3201)
#### [数组](#3201)
#### [动态规划](#3201)
### [3202_找出有效子序列的最大长度 II](#3202)
#### [数组](#3202)
#### [动态规划](#3202)
### [3203_合并两棵树后的最小直径](#3203)
#### [树](#3203)
#### [深度优先搜索](#3203)
#### [广度优先搜索](#3203)
#### [图](#3203)
### [3204_按位用户权限分析 🔒](#3204)
#### [数据库](#3204)
### [3205_最大数组跳跃得分 I 🔒](#3205)
#### [栈](#3205)
#### [贪心](#3205)
#### [数组](#3205)
#### [动态规划](#3205)
#### [单调栈](#3205)
### [3206_交替组 I](#3206)
#### [数组](#3206)
#### [滑动窗口](#3206)
### [3207_与敌人战斗后的最大分数](#3207)
#### [贪心](#3207)
#### [数组](#3207)
### [3208_交替组 II](#3208)
#### [数组](#3208)
#### [滑动窗口](#3208)
### [3209_子数组按位与值为 K 的数目](#3209)
#### [位运算](#3209)
#### [线段树](#3209)
#### [数组](#3209)
#### [二分查找](#3209)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 3200_三角形的最大高度
___
#### 数组
___
#### 枚举
---
### 3201_找出有效子序列的最大长度 I
___
#### 数组
___
#### 动态规划
---
### 3202_找出有效子序列的最大长度 II
___
#### 数组
___
#### 动态规划
---
### 3203_合并两棵树后的最小直径
___
#### 树
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 图
---
### 3204_按位用户权限分析 🔒
___
#### 数据库
---
### 3205_最大数组跳跃得分 I 🔒
___
#### 栈
___
#### 贪心
___
#### 数组
___
#### 动态规划
___
#### 单调栈
---
### 3206_交替组 I
___
#### 数组
___
#### 滑动窗口
---
### 3207_与敌人战斗后的最大分数
___
#### 贪心
___
#### 数组
---
### 3208_交替组 II
___
#### 数组
___
#### 滑动窗口
---
### 3209_子数组按位与值为 K 的数目
___
#### 位运算
___
#### 线段树
___
#### 数组
___
#### 二分查找
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 位运算 | 动态规划 |
| 单调栈 | 图 | 广度优先搜索 |
| 数据库 | 数组 | 枚举 |
| 栈 | 树 | 深度优先搜索 |
| 滑动窗口 | 线段树 | 贪心 |

# [3200. 三角形的最大高度](https://leetcode.cn/problems/maximum-height-of-a-triangle){#3200}

{{< tabs "3200" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxHeightOfTriangle(self, red: int, blue: int) -> int:
        ans = 0
        for k in range(2):
            c = [red, blue]
            i, j = 1, k
            while i <= c[j]:
                c[j] -= i
                j ^= 1
                ans = max(ans, i)
                i += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxHeightOfTriangle(int red, int blue) {
        int ans = 0;
        for (int k = 0; k < 2; ++k) {
            int[] c = {red, blue};
            for (int i = 1, j = k; i <= c[j]; j ^= 1, ++i) {
                c[j] -= i;
                ans = Math.max(ans, i);
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
    int maxHeightOfTriangle(int red, int blue) {
        int ans = 0;
        for (int k = 0; k < 2; ++k) {
            int c[2] = {red, blue};
            for (int i = 1, j = k; i <= c[j]; j ^= 1, ++i) {
                c[j] -= i;
                ans = max(ans, i);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxHeightOfTriangle(red int, blue int) (ans int) {
	for k := 0; k < 2; k++ {
		c := [2]int{red, blue}
		for i, j := 1, k; i <= c[j]; i, j = i+1, j^1 {
			c[j] -= i
			ans = max(ans, i)
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxHeightOfTriangle(red: number, blue: number): number {
    let ans = 0;
    for (let k = 0; k < 2; ++k) {
        const c: [number, number] = [red, blue];
        for (let i = 1, j = k; i <= c[j]; ++i, j ^= 1) {
            c[j] -= i;
            ans = Math.max(ans, i);
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

<p>给你两个整数 <code>red</code> 和 <code>blue</code>，分别表示红色球和蓝色球的数量。你需要使用这些球来组成一个三角形，满足第 1 行有 1 个球，第 2 行有 2 个球，第 3 行有 3 个球，依此类推。</p>

<p>每一行的球必须是 <strong>相同 </strong>颜色，且相邻行的颜色必须<strong> 不同</strong>。</p>

<p>返回可以实现的三角形的 <strong>最大 </strong>高度。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">red = 2, blue = 4</span></p>

<p><strong>输出：</strong> 3</p>

<p><strong>解释：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3200-3299/3200.Maximum%20Height%20of%20a%20Triangle/images/brb.png" style="width: 300px; height: 240px; padding: 10px;" /></p>

<p>上图显示了唯一可能的排列方式。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">red = 2, blue = 1</span></p>

<p><strong>输出：</strong> <span class="example-io">2</span></p>

<p><strong>解释：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3200-3299/3200.Maximum%20Height%20of%20a%20Triangle/images/br.png" style="width: 150px; height: 135px; padding: 10px;" /><br />
上图显示了唯一可能的排列方式。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">red = 1, blue = 1</span></p>

<p><strong>输出：</strong> <span class="example-io">1</span></p>
</div>

<p><strong class="example">示例 4：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">red = 10, blue = 1</span></p>

<p><strong>输出：</strong> <span class="example-io">2</span></p>

<p><strong>解释：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3200-3299/3200.Maximum%20Height%20of%20a%20Triangle/images/br.png" style="width: 150px; height: 135px; padding: 10px;" /><br />
上图显示了唯一可能的排列方式。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= red, blue &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们可以枚举第一行的颜色，然后模拟构造三角形，计算最大高度。

时间复杂度 $O(\sqrt{n})$，其中 $n$ 为红色球和蓝色球的数量。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxHeightOfTriangle(self, red: int, blue: int) -> int:
        ans = 0
        for k in range(2):
            c = [red, blue]
            i, j = 1, k
            while i <= c[j]:
                c[j] -= i
                j ^= 1
                ans = max(ans, i)
                i += 1
        return ans
```

#### Java

```java
class Solution {
    public int maxHeightOfTriangle(int red, int blue) {
        int ans = 0;
        for (int k = 0; k < 2; ++k) {
            int[] c = {red, blue};
            for (int i = 1, j = k; i <= c[j]; j ^= 1, ++i) {
                c[j] -= i;
                ans = Math.max(ans, i);
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
    int maxHeightOfTriangle(int red, int blue) {
        int ans = 0;
        for (int k = 0; k < 2; ++k) {
            int c[2] = {red, blue};
            for (int i = 1, j = k; i <= c[j]; j ^= 1, ++i) {
                c[j] -= i;
                ans = max(ans, i);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func maxHeightOfTriangle(red int, blue int) (ans int) {
	for k := 0; k < 2; k++ {
		c := [2]int{red, blue}
		for i, j := 1, k; i <= c[j]; i, j = i+1, j^1 {
			c[j] -= i
			ans = max(ans, i)
		}
	}
	return
}
```

#### TypeScript

```ts
function maxHeightOfTriangle(red: number, blue: number): number {
    let ans = 0;
    for (let k = 0; k < 2; ++k) {
        const c: [number, number] = [red, blue];
        for (let i = 1, j = k; i <= c[j]; ++i, j ^= 1) {
            c[j] -= i;
            ans = Math.max(ans, i);
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

# [3201. 找出有效子序列的最大长度 I](https://leetcode.cn/problems/find-the-maximum-length-of-valid-subsequence-i){#3201}

{{< tabs "3201" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumLength(self, nums: List[int]) -> int:
        k = 2
        f = [[0] * k for _ in range(k)]
        ans = 0
        for x in nums:
            x %= k
            for j in range(k):
                y = (j - x + k) % k
                f[x][y] = f[y][x] + 1
                ans = max(ans, f[x][y])
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maximumLength(int[] nums) {
        int k = 2;
        int[][] f = new int[k][k];
        int ans = 0;
        for (int x : nums) {
            x %= k;
            for (int j = 0; j < k; ++j) {
                int y = (j - x + k) % k;
                f[x][y] = f[y][x] + 1;
                ans = Math.max(ans, f[x][y]);
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
    int maximumLength(vector<int>& nums) {
        int k = 2;
        int f[k][k];
        memset(f, 0, sizeof(f));
        int ans = 0;
        for (int x : nums) {
            x %= k;
            for (int j = 0; j < k; ++j) {
                int y = (j - x + k) % k;
                f[x][y] = f[y][x] + 1;
                ans = max(ans, f[x][y]);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumLength(nums []int) (ans int) {
	k := 2
	f := make([][]int, k)
	for i := range f {
		f[i] = make([]int, k)
	}
	for _, x := range nums {
		x %= k
		for j := 0; j < k; j++ {
			y := (j - x + k) % k
			f[x][y] = f[y][x] + 1
			ans = max(ans, f[x][y])
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumLength(nums: number[]): number {
    const k = 2;
    const f: number[][] = Array.from({ length: k }, () => Array(k).fill(0));
    let ans: number = 0;
    for (let x of nums) {
        x %= k;
        for (let j = 0; j < k; ++j) {
            const y = (j - x + k) % k;
            f[x][y] = f[y][x] + 1;
            ans = Math.max(ans, f[x][y]);
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn maximum_length(nums: Vec<i32>) -> i32 {
        let mut f = [[0; 2]; 2];
        let mut ans = 0;
        for x in nums {
            let x = (x % 2) as usize;
            for j in 0..2 {
                let y = ((j + 2 - x) % 2) as usize;
                f[x][y] = f[y][x] + 1;
                ans = ans.max(f[x][y]);
            }
        }
        ans
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int MaximumLength(int[] nums) {
        int k = 2;
        int[,] f = new int[k, k];
        int ans = 0;
        foreach (int num in nums) {
            int x = num % k;
            for (int j = 0; j < k; ++j) {
                int y = (j - x + k) % k;
                f[x, y] = f[y, x] + 1;
                ans = Math.Max(ans, f[x, y]);
            }
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

<p>给你一个整数数组 <code>nums</code>。</p>

<p><code>nums</code> 的子序列 <code>sub</code> 的长度为 <code>x</code> ，如果其满足以下条件，则称其为 <strong>有效子序列</strong>：</p>

<ul>
	<li><code>(sub[0] + sub[1]) % 2 == (sub[1] + sub[2]) % 2 == ... == (sub[x - 2] + sub[x - 1]) % 2</code></li>
</ul>

<p>返回 <code>nums</code> 的 <strong>最长的有效子序列</strong> 的长度。</p>

<p>一个&nbsp;<strong>子序列</strong>&nbsp;指的是从原数组中删除一些元素（也可以不删除任何元素），剩余元素保持原来顺序组成的新数组。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">nums = [1,2,3,4]</span></p>

<p><strong>输出：</strong> <span class="example-io">4</span></p>

<p><strong>解释：</strong></p>

<p>最长的有效子序列是 <code>[1, 2, 3, 4]</code>。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">nums = [1,2,1,1,2,1,2]</span></p>

<p><strong>输出：</strong> 6</p>

<p><strong>解释：</strong></p>

<p>最长的有效子序列是 <code>[1, 2, 1, 2, 1, 2]</code>。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">nums = [1,3]</span></p>

<p><strong>输出：</strong> <span class="example-io">2</span></p>

<p><strong>解释：</strong></p>

<p>最长的有效子序列是 <code>[1, 3]</code>。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 2 * 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>7</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们令 $k = 2$。

根据题目描述，我们可以得知，对于子序列 $a_1, a_2, a_3, \cdots, a_x$，如果满足 $(a_1 + a_2) \bmod k = (a_2 + a_3) \bmod k$。那么 $a_1 \bmod k = a_3 \bmod k$。也即是说，所有奇数项元素对 $k$ 取模的结果相同，所有偶数项元素对 $k$ 取模的结果相同。

我们可以使用动态规划的方法解决这个问题。定义状态 $f[x][y]$ 表示最后一项对 $k$ 取模为 $x$，倒数第二项对 $k$ 取模为 $y$ 的最长有效子序列的长度。初始时 $f[x][y] = 0$。

遍历数组 $nums$，对于每一个数 $x$，我们得到 $x = x \bmod k$。然后我们可以枚举序列连续两个数对 $j$ 取模结果相同，其中 $j \in [0, k)$。那么 $x$ 的前一个数对 $k$ 取模结果为 $y = (j - x + k) \bmod k$。此时 $f[x][y] = f[y][x] + 1$。

答案为所有 $f[x][y]$ 中的最大值。

时间复杂度 $O(n \times k)$，空间复杂度 $O(k^2)$。其中 $n$ 为数组 $\textit{nums}$ 的长度，而 $k=2$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumLength(self, nums: List[int]) -> int:
        k = 2
        f = [[0] * k for _ in range(k)]
        ans = 0
        for x in nums:
            x %= k
            for j in range(k):
                y = (j - x + k) % k
                f[x][y] = f[y][x] + 1
                ans = max(ans, f[x][y])
        return ans
```

#### Java

```java
class Solution {
    public int maximumLength(int[] nums) {
        int k = 2;
        int[][] f = new int[k][k];
        int ans = 0;
        for (int x : nums) {
            x %= k;
            for (int j = 0; j < k; ++j) {
                int y = (j - x + k) % k;
                f[x][y] = f[y][x] + 1;
                ans = Math.max(ans, f[x][y]);
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
    int maximumLength(vector<int>& nums) {
        int k = 2;
        int f[k][k];
        memset(f, 0, sizeof(f));
        int ans = 0;
        for (int x : nums) {
            x %= k;
            for (int j = 0; j < k; ++j) {
                int y = (j - x + k) % k;
                f[x][y] = f[y][x] + 1;
                ans = max(ans, f[x][y]);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func maximumLength(nums []int) (ans int) {
	k := 2
	f := make([][]int, k)
	for i := range f {
		f[i] = make([]int, k)
	}
	for _, x := range nums {
		x %= k
		for j := 0; j < k; j++ {
			y := (j - x + k) % k
			f[x][y] = f[y][x] + 1
			ans = max(ans, f[x][y])
		}
	}
	return
}
```

#### TypeScript

```ts
function maximumLength(nums: number[]): number {
    const k = 2;
    const f: number[][] = Array.from({ length: k }, () => Array(k).fill(0));
    let ans: number = 0;
    for (let x of nums) {
        x %= k;
        for (let j = 0; j < k; ++j) {
            const y = (j - x + k) % k;
            f[x][y] = f[y][x] + 1;
            ans = Math.max(ans, f[x][y]);
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn maximum_length(nums: Vec<i32>) -> i32 {
        let mut f = [[0; 2]; 2];
        let mut ans = 0;
        for x in nums {
            let x = (x % 2) as usize;
            for j in 0..2 {
                let y = ((j + 2 - x) % 2) as usize;
                f[x][y] = f[y][x] + 1;
                ans = ans.max(f[x][y]);
            }
        }
        ans
    }
}
```

#### C#

```cs
public class Solution {
    public int MaximumLength(int[] nums) {
        int k = 2;
        int[,] f = new int[k, k];
        int ans = 0;
        foreach (int num in nums) {
            int x = num % k;
            for (int j = 0; j < k; ++j) {
                int y = (j - x + k) % k;
                f[x, y] = f[y, x] + 1;
                ans = Math.Max(ans, f[x, y]);
            }
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

# [3202. 找出有效子序列的最大长度 II](https://leetcode.cn/problems/find-the-maximum-length-of-valid-subsequence-ii){#3202}

{{< tabs "3202" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumLength(self, nums: List[int], k: int) -> int:
        f = [[0] * k for _ in range(k)]
        ans = 0
        for x in nums:
            x %= k
            for j in range(k):
                y = (j - x + k) % k
                f[x][y] = f[y][x] + 1
                ans = max(ans, f[x][y])
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maximumLength(int[] nums, int k) {
        int[][] f = new int[k][k];
        int ans = 0;
        for (int x : nums) {
            x %= k;
            for (int j = 0; j < k; ++j) {
                int y = (j - x + k) % k;
                f[x][y] = f[y][x] + 1;
                ans = Math.max(ans, f[x][y]);
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
    int maximumLength(vector<int>& nums, int k) {
        int f[k][k];
        memset(f, 0, sizeof(f));
        int ans = 0;
        for (int x : nums) {
            x %= k;
            for (int j = 0; j < k; ++j) {
                int y = (j - x + k) % k;
                f[x][y] = f[y][x] + 1;
                ans = max(ans, f[x][y]);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumLength(nums []int, k int) (ans int) {
	f := make([][]int, k)
	for i := range f {
		f[i] = make([]int, k)
	}
	for _, x := range nums {
		x %= k
		for j := 0; j < k; j++ {
			y := (j - x + k) % k
			f[x][y] = f[y][x] + 1
			ans = max(ans, f[x][y])
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumLength(nums: number[], k: number): number {
    const f: number[][] = Array.from({ length: k }, () => Array(k).fill(0));
    let ans: number = 0;
    for (let x of nums) {
        x %= k;
        for (let j = 0; j < k; ++j) {
            const y = (j - x + k) % k;
            f[x][y] = f[y][x] + 1;
            ans = Math.max(ans, f[x][y]);
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn maximum_length(nums: Vec<i32>, k: i32) -> i32 {
        let k = k as usize;
        let mut f = vec![vec![0; k]; k];
        let mut ans = 0;
        for x in nums {
            let x = (x % k as i32) as usize;
            for j in 0..k {
                let y = (j + k - x) % k;
                f[x][y] = f[y][x] + 1;
                ans = ans.max(f[x][y]);
            }
        }
        ans
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int MaximumLength(int[] nums, int k) {
        int[,] f = new int[k, k];
        int ans = 0;
        foreach (int num in nums) {
            int x = num % k;
            for (int j = 0; j < k; ++j) {
                int y = (j - x + k) % k;
                f[x, y] = f[y, x] + 1;
                ans = Math.Max(ans, f[x, y]);
            }
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

给你一个整数数组&nbsp;<code>nums</code>&nbsp;和一个 <strong>正</strong>&nbsp;整数&nbsp;<code>k</code>&nbsp;。

<p><code>nums</code>&nbsp;的一个&nbsp;<span data-keyword="subsequence-array">子序列</span> <code>sub</code>&nbsp;的长度为 <code>x</code>&nbsp;，如果其满足以下条件，则称其为 <strong>有效子序列</strong>&nbsp;：</p>

<ul>
	<li><code>(sub[0] + sub[1]) % k == (sub[1] + sub[2]) % k == ... == (sub[x - 2] + sub[x - 1]) % k</code></li>
</ul>
返回 <code>nums</code>&nbsp;的 <strong>最长</strong><strong>有效子序列</strong>&nbsp;的长度。

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [1,2,3,4,5], k = 2</span></p>

<p><span class="example-io"><b>输出：</b>5</span></p>

<p><b>解释：</b></p>

<p>最长有效子序列是&nbsp;<code>[1, 2, 3, 4, 5]</code>&nbsp;。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [1,4,2,3,1,4], k = 3</span></p>

<p><span class="example-io"><b>输出：</b>4</span></p>

<p><strong>解释：</strong></p>

<p>最长有效子序列是&nbsp;<code>[1, 4, 1, 4]</code>&nbsp;。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 10<sup>3</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>7</sup></code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>3</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

根据题目描述，我们可以得知，对于子序列 $a_1, a_2, a_3, \cdots, a_x$，如果满足 $(a_1 + a_2) \bmod k = (a_2 + a_3) \bmod k$。那么 $a_1 \bmod k = a_3 \bmod k$。也即是说，所有奇数项元素对 $k$ 取模的结果相同，所有偶数项元素对 $k$ 取模的结果相同。

我们可以使用动态规划的方法解决这个问题。定义状态 $f[x][y]$ 表示最后一项对 $k$ 取模为 $x$，倒数第二项对 $k$ 取模为 $y$ 的最长有效子序列的长度。初始时 $f[x][y] = 0$。

遍历数组 $nums$，对于每一个数 $x$，我们得到 $x = x \bmod k$。然后我们可以枚举序列连续两个数对 $j$ 取模结果相同，其中 $j \in [0, k)$。那么 $x$ 的前一个数对 $k$ 取模结果为 $y = (j - x + k) \bmod k$。此时 $f[x][y] = f[y][x] + 1$。

答案为所有 $f[x][y]$ 中的最大值。

时间复杂度 $O(n \times k)$，空间复杂度 $O(k^2)$。其中 $n$ 为数组 $\textit{nums}$ 的长度，而 $k$ 为给定的正整数。

#### Python3

```python
class Solution:
    def maximumLength(self, nums: List[int], k: int) -> int:
        f = [[0] * k for _ in range(k)]
        ans = 0
        for x in nums:
            x %= k
            for j in range(k):
                y = (j - x + k) % k
                f[x][y] = f[y][x] + 1
                ans = max(ans, f[x][y])
        return ans
```

#### Java

```java
class Solution {
    public int maximumLength(int[] nums, int k) {
        int[][] f = new int[k][k];
        int ans = 0;
        for (int x : nums) {
            x %= k;
            for (int j = 0; j < k; ++j) {
                int y = (j - x + k) % k;
                f[x][y] = f[y][x] + 1;
                ans = Math.max(ans, f[x][y]);
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
    int maximumLength(vector<int>& nums, int k) {
        int f[k][k];
        memset(f, 0, sizeof(f));
        int ans = 0;
        for (int x : nums) {
            x %= k;
            for (int j = 0; j < k; ++j) {
                int y = (j - x + k) % k;
                f[x][y] = f[y][x] + 1;
                ans = max(ans, f[x][y]);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func maximumLength(nums []int, k int) (ans int) {
	f := make([][]int, k)
	for i := range f {
		f[i] = make([]int, k)
	}
	for _, x := range nums {
		x %= k
		for j := 0; j < k; j++ {
			y := (j - x + k) % k
			f[x][y] = f[y][x] + 1
			ans = max(ans, f[x][y])
		}
	}
	return
}
```

#### TypeScript

```ts
function maximumLength(nums: number[], k: number): number {
    const f: number[][] = Array.from({ length: k }, () => Array(k).fill(0));
    let ans: number = 0;
    for (let x of nums) {
        x %= k;
        for (let j = 0; j < k; ++j) {
            const y = (j - x + k) % k;
            f[x][y] = f[y][x] + 1;
            ans = Math.max(ans, f[x][y]);
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn maximum_length(nums: Vec<i32>, k: i32) -> i32 {
        let k = k as usize;
        let mut f = vec![vec![0; k]; k];
        let mut ans = 0;
        for x in nums {
            let x = (x % k as i32) as usize;
            for j in 0..k {
                let y = (j + k - x) % k;
                f[x][y] = f[y][x] + 1;
                ans = ans.max(f[x][y]);
            }
        }
        ans
    }
}
```

#### C#

```cs
public class Solution {
    public int MaximumLength(int[] nums, int k) {
        int[,] f = new int[k, k];
        int ans = 0;
        foreach (int num in nums) {
            int x = num % k;
            for (int j = 0; j < k; ++j) {
                int y = (j - x + k) % k;
                f[x, y] = f[y, x] + 1;
                ans = Math.Max(ans, f[x, y]);
            }
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

# [3203. 合并两棵树后的最小直径](https://leetcode.cn/problems/find-minimum-diameter-after-merging-two-trees){#3203}

{{< tabs "3203" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumDiameterAfterMerge(
        self, edges1: List[List[int]], edges2: List[List[int]]
    ) -> int:
        d1 = self.treeDiameter(edges1)
        d2 = self.treeDiameter(edges2)
        return max(d1, d2, (d1 + 1) // 2 + (d2 + 1) // 2 + 1)

    def treeDiameter(self, edges: List[List[int]]) -> int:
        def dfs(i: int, fa: int, t: int):
            for j in g[i]:
                if j != fa:
                    dfs(j, i, t + 1)
            nonlocal ans, a
            if ans < t:
                ans = t
                a = i

        g = defaultdict(list)
        for a, b in edges:
            g[a].append(b)
            g[b].append(a)
        ans = a = 0
        dfs(0, -1, 0)
        dfs(a, -1, 0)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private List<Integer>[] g;
    private int ans;
    private int a;

    public int minimumDiameterAfterMerge(int[][] edges1, int[][] edges2) {
        int d1 = treeDiameter(edges1);
        int d2 = treeDiameter(edges2);
        return Math.max(Math.max(d1, d2), (d1 + 1) / 2 + (d2 + 1) / 2 + 1);
    }

    public int treeDiameter(int[][] edges) {
        int n = edges.length + 1;
        g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        ans = 0;
        a = 0;
        for (var e : edges) {
            int a = e[0], b = e[1];
            g[a].add(b);
            g[b].add(a);
        }
        dfs(0, -1, 0);
        dfs(a, -1, 0);
        return ans;
    }

    private void dfs(int i, int fa, int t) {
        for (int j : g[i]) {
            if (j != fa) {
                dfs(j, i, t + 1);
            }
        }
        if (ans < t) {
            ans = t;
            a = i;
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int d1 = treeDiameter(edges1);
        int d2 = treeDiameter(edges2);
        return max({d1, d2, (d1 + 1) / 2 + (d2 + 1) / 2 + 1});
    }

    int treeDiameter(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<int> g[n];
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        int ans = 0, a = 0;
        auto dfs = [&](this auto&& dfs, int i, int fa, int t) -> void {
            for (int j : g[i]) {
                if (j != fa) {
                    dfs(j, i, t + 1);
                }
            }
            if (ans < t) {
                ans = t;
                a = i;
            }
        };
        dfs(0, -1, 0);
        dfs(a, -1, 0);
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumDiameterAfterMerge(edges1 [][]int, edges2 [][]int) int {
	d1 := treeDiameter(edges1)
	d2 := treeDiameter(edges2)
	return max(d1, d2, (d1+1)/2+(d2+1)/2+1)
}

func treeDiameter(edges [][]int) (ans int) {
	n := len(edges) + 1
	g := make([][]int, n)
	for _, e := range edges {
		a, b := e[0], e[1]
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}
	a := 0
	var dfs func(i, fa, t int)
	dfs = func(i, fa, t int) {
		for _, j := range g[i] {
			if j != fa {
				dfs(j, i, t+1)
			}
		}
		if ans < t {
			ans = t
			a = i
		}
	}
	dfs(0, -1, 0)
	dfs(a, -1, 0)
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumDiameterAfterMerge(edges1: number[][], edges2: number[][]): number {
    const d1 = treeDiameter(edges1);
    const d2 = treeDiameter(edges2);
    return Math.max(d1, d2, Math.ceil(d1 / 2) + Math.ceil(d2 / 2) + 1);
}

function treeDiameter(edges: number[][]): number {
    const n = edges.length + 1;
    const g: number[][] = Array.from({ length: n }, () => []);
    for (const [a, b] of edges) {
        g[a].push(b);
        g[b].push(a);
    }
    let [ans, a] = [0, 0];
    const dfs = (i: number, fa: number, t: number): void => {
        for (const j of g[i]) {
            if (j !== fa) {
                dfs(j, i, t + 1);
            }
        }
        if (ans < t) {
            ans = t;
            a = i;
        }
    };
    dfs(0, -1, 0);
    dfs(a, -1, 0);
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn minimum_diameter_after_merge(edges1: Vec<Vec<i32>>, edges2: Vec<Vec<i32>>) -> i32 {
        let d1 = Self::tree_diameter(&edges1);
        let d2 = Self::tree_diameter(&edges2);
        d1.max(d2).max((d1 + 1) / 2 + (d2 + 1) / 2 + 1)
    }

    fn tree_diameter(edges: &Vec<Vec<i32>>) -> i32 {
        let n = edges.len() + 1;
        let mut g = vec![vec![]; n];
        for e in edges {
            let a = e[0] as usize;
            let b = e[1] as usize;
            g[a].push(b);
            g[b].push(a);
        }
        let mut ans = 0;
        let mut a = 0;
        fn dfs(g: &Vec<Vec<usize>>, i: usize, fa: isize, t: i32, ans: &mut i32, a: &mut usize) {
            for &j in &g[i] {
                if j as isize != fa {
                    dfs(g, j, i as isize, t + 1, ans, a);
                }
            }
            if *ans < t {
                *ans = t;
                *a = i;
            }
        }
        dfs(&g, 0, -1, 0, &mut ans, &mut a);
        dfs(&g, a, -1, 0, &mut ans, &mut a);
        ans
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    private List<int>[] g;
    private int ans;
    private int a;

    public int MinimumDiameterAfterMerge(int[][] edges1, int[][] edges2) {
        int d1 = TreeDiameter(edges1);
        int d2 = TreeDiameter(edges2);
        return Math.Max(Math.Max(d1, d2), (d1 + 1) / 2 + (d2 + 1) / 2 + 1);
    }

    public int TreeDiameter(int[][] edges) {
        int n = edges.Length + 1;
        g = new List<int>[n];
        for (int k = 0; k < n; ++k) {
            g[k] = new List<int>();
        }
        ans = 0;
        a = 0;
        foreach (var e in edges) {
            int a = e[0], b = e[1];
            g[a].Add(b);
            g[b].Add(a);
        }
        Dfs(0, -1, 0);
        Dfs(a, -1, 0);
        return ans;
    }

    private void Dfs(int i, int fa, int t) {
        foreach (int j in g[i]) {
            if (j != fa) {
                Dfs(j, i, t + 1);
            }
        }
        if (ans < t) {
            ans = t;
            a = i;
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

<p>给你两棵 <strong>无向</strong>&nbsp;树，分别有&nbsp;<code>n</code> 和&nbsp;<code>m</code>&nbsp;个节点，节点编号分别为&nbsp;<code>0</code>&nbsp;到&nbsp;<code>n - 1</code>&nbsp;和&nbsp;<code>0</code>&nbsp;到&nbsp;<code>m - 1</code>&nbsp;。给你两个二维整数数组&nbsp;<code>edges1</code> 和&nbsp;<code>edges2</code>&nbsp;，长度分别为&nbsp;<code>n - 1</code> 和&nbsp;<code>m - 1</code>&nbsp;，其中&nbsp;<code>edges1[i] = [a<sub>i</sub>, b<sub>i</sub>]</code>&nbsp;表示在第一棵树中节点&nbsp;<code>a<sub>i</sub></code> 和&nbsp;<code>b<sub>i</sub></code>&nbsp;之间有一条边，<code>edges2[i] = [u<sub>i</sub>, v<sub>i</sub>]</code>&nbsp;表示在第二棵树中节点&nbsp;<code>u<sub>i</sub></code> 和&nbsp;<code>v<sub>i</sub></code>&nbsp;之间有一条边。</p>

<p>你必须在第一棵树和第二棵树中分别选一个节点，并用一条边连接它们。</p>

<p>请你返回添加边后得到的树中，<strong>最小直径</strong>&nbsp;为多少。</p>

<p>一棵树的 <strong>直径</strong>&nbsp;指的是树中任意两个节点之间的最长路径长度。</p>

<p>&nbsp;</p>

<p><b>示例 1：</b><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3200-3299/3203.Find%20Minimum%20Diameter%20After%20Merging%20Two%20Trees/images/example11-transformed.png" style="width: 1000px; height: 494px;" /></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>edges1 = [[0,1],[0,2],[0,3]], edges2 = [[0,1]]</span></p>

<p><span class="example-io"><b>输出：</b>3</span></p>

<p><strong>解释：</strong></p>

<p>将第一棵树中的节点 0 与第二棵树中的任意节点连接，得到一棵直径为 3 的树。</p>
</div>

<p><strong class="example">示例 2：<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3200-3299/3203.Find%20Minimum%20Diameter%20After%20Merging%20Two%20Trees/images/example211.png" style="width: 1000px; height: 492px;" /></strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>edges1 = [[0,1],[0,2],[0,3],[2,4],[2,5],[3,6],[2,7]], edges2 = [[0,1],[0,2],[0,3],[2,4],[2,5],[3,6],[2,7]]</span></p>

<p><span class="example-io"><b>输出：</b>5</span></p>

<p><strong>解释：</strong></p>

<p>将第一棵树中的节点 0 和第二棵树中的节点 0 连接，可以得到一棵直径为 5 的树。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n, m &lt;= 10<sup>5</sup></code></li>
	<li><code>edges1.length == n - 1</code></li>
	<li><code>edges2.length == m - 1</code></li>
	<li><code>edges1[i].length == edges2[i].length == 2</code></li>
	<li><code>edges1[i] = [a<sub>i</sub>, b<sub>i</sub>]</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt; n</code></li>
	<li><code>edges2[i] = [u<sub>i</sub>, v<sub>i</sub>]</code></li>
	<li><code>0 &lt;= u<sub>i</sub>, v<sub>i</sub> &lt; m</code></li>
	<li>输入保证&nbsp;<code>edges1</code> 和&nbsp;<code>edges2</code>&nbsp;分别表示一棵合法的树。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：两次 DFS

我们记 $d_1$ 和 $d_2$ 分别为两棵树的直径，那么合并后的树的直径有以下两种情况：

1. 合并后的树的直径为原始的一棵树的直径，即 $\max(d_1, d_2)$；
2. 合并后的树的直径经过原始的两棵树。我们分别计算原始的两棵树的半径 $r_1 = \lceil \frac{d_1}{2} \rceil$ 和 $r_2 = \lceil \frac{d_2}{2} \rceil$，那么合并后的树的直径为 $r_1 + r_2 + 1$。

我们取这两种情况的最大值即可。

在计算树的直径时，我们可以使用两次 DFS。首先我们任选一点出发，找到距离该点最远的点，记为 $a$。然后从点 $a$ 出发，找到距离点 $a$ 最远的点，记为 $b$。可以证明，点 $a$ 和点 $b$ 之间的路径即为树的直径。

时间复杂度 $O(n + m)$，空间复杂度 $O(n + m)$。其中 $n$ 和 $m$ 分别为两棵树的节点数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumDiameterAfterMerge(
        self, edges1: List[List[int]], edges2: List[List[int]]
    ) -> int:
        d1 = self.treeDiameter(edges1)
        d2 = self.treeDiameter(edges2)
        return max(d1, d2, (d1 + 1) // 2 + (d2 + 1) // 2 + 1)

    def treeDiameter(self, edges: List[List[int]]) -> int:
        def dfs(i: int, fa: int, t: int):
            for j in g[i]:
                if j != fa:
                    dfs(j, i, t + 1)
            nonlocal ans, a
            if ans < t:
                ans = t
                a = i

        g = defaultdict(list)
        for a, b in edges:
            g[a].append(b)
            g[b].append(a)
        ans = a = 0
        dfs(0, -1, 0)
        dfs(a, -1, 0)
        return ans
```

#### Java

```java
class Solution {
    private List<Integer>[] g;
    private int ans;
    private int a;

    public int minimumDiameterAfterMerge(int[][] edges1, int[][] edges2) {
        int d1 = treeDiameter(edges1);
        int d2 = treeDiameter(edges2);
        return Math.max(Math.max(d1, d2), (d1 + 1) / 2 + (d2 + 1) / 2 + 1);
    }

    public int treeDiameter(int[][] edges) {
        int n = edges.length + 1;
        g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        ans = 0;
        a = 0;
        for (var e : edges) {
            int a = e[0], b = e[1];
            g[a].add(b);
            g[b].add(a);
        }
        dfs(0, -1, 0);
        dfs(a, -1, 0);
        return ans;
    }

    private void dfs(int i, int fa, int t) {
        for (int j : g[i]) {
            if (j != fa) {
                dfs(j, i, t + 1);
            }
        }
        if (ans < t) {
            ans = t;
            a = i;
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int d1 = treeDiameter(edges1);
        int d2 = treeDiameter(edges2);
        return max({d1, d2, (d1 + 1) / 2 + (d2 + 1) / 2 + 1});
    }

    int treeDiameter(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<int> g[n];
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        int ans = 0, a = 0;
        auto dfs = [&](this auto&& dfs, int i, int fa, int t) -> void {
            for (int j : g[i]) {
                if (j != fa) {
                    dfs(j, i, t + 1);
                }
            }
            if (ans < t) {
                ans = t;
                a = i;
            }
        };
        dfs(0, -1, 0);
        dfs(a, -1, 0);
        return ans;
    }
};
```

#### Go

```go
func minimumDiameterAfterMerge(edges1 [][]int, edges2 [][]int) int {
	d1 := treeDiameter(edges1)
	d2 := treeDiameter(edges2)
	return max(d1, d2, (d1+1)/2+(d2+1)/2+1)
}

func treeDiameter(edges [][]int) (ans int) {
	n := len(edges) + 1
	g := make([][]int, n)
	for _, e := range edges {
		a, b := e[0], e[1]
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}
	a := 0
	var dfs func(i, fa, t int)
	dfs = func(i, fa, t int) {
		for _, j := range g[i] {
			if j != fa {
				dfs(j, i, t+1)
			}
		}
		if ans < t {
			ans = t
			a = i
		}
	}
	dfs(0, -1, 0)
	dfs(a, -1, 0)
	return
}
```

#### TypeScript

```ts
function minimumDiameterAfterMerge(edges1: number[][], edges2: number[][]): number {
    const d1 = treeDiameter(edges1);
    const d2 = treeDiameter(edges2);
    return Math.max(d1, d2, Math.ceil(d1 / 2) + Math.ceil(d2 / 2) + 1);
}

function treeDiameter(edges: number[][]): number {
    const n = edges.length + 1;
    const g: number[][] = Array.from({ length: n }, () => []);
    for (const [a, b] of edges) {
        g[a].push(b);
        g[b].push(a);
    }
    let [ans, a] = [0, 0];
    const dfs = (i: number, fa: number, t: number): void => {
        for (const j of g[i]) {
            if (j !== fa) {
                dfs(j, i, t + 1);
            }
        }
        if (ans < t) {
            ans = t;
            a = i;
        }
    };
    dfs(0, -1, 0);
    dfs(a, -1, 0);
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn minimum_diameter_after_merge(edges1: Vec<Vec<i32>>, edges2: Vec<Vec<i32>>) -> i32 {
        let d1 = Self::tree_diameter(&edges1);
        let d2 = Self::tree_diameter(&edges2);
        d1.max(d2).max((d1 + 1) / 2 + (d2 + 1) / 2 + 1)
    }

    fn tree_diameter(edges: &Vec<Vec<i32>>) -> i32 {
        let n = edges.len() + 1;
        let mut g = vec![vec![]; n];
        for e in edges {
            let a = e[0] as usize;
            let b = e[1] as usize;
            g[a].push(b);
            g[b].push(a);
        }
        let mut ans = 0;
        let mut a = 0;
        fn dfs(g: &Vec<Vec<usize>>, i: usize, fa: isize, t: i32, ans: &mut i32, a: &mut usize) {
            for &j in &g[i] {
                if j as isize != fa {
                    dfs(g, j, i as isize, t + 1, ans, a);
                }
            }
            if *ans < t {
                *ans = t;
                *a = i;
            }
        }
        dfs(&g, 0, -1, 0, &mut ans, &mut a);
        dfs(&g, a, -1, 0, &mut ans, &mut a);
        ans
    }
}
```

#### C#

```cs
public class Solution {
    private List<int>[] g;
    private int ans;
    private int a;

    public int MinimumDiameterAfterMerge(int[][] edges1, int[][] edges2) {
        int d1 = TreeDiameter(edges1);
        int d2 = TreeDiameter(edges2);
        return Math.Max(Math.Max(d1, d2), (d1 + 1) / 2 + (d2 + 1) / 2 + 1);
    }

    public int TreeDiameter(int[][] edges) {
        int n = edges.Length + 1;
        g = new List<int>[n];
        for (int k = 0; k < n; ++k) {
            g[k] = new List<int>();
        }
        ans = 0;
        a = 0;
        foreach (var e in edges) {
            int a = e[0], b = e[1];
            g[a].Add(b);
            g[b].Add(a);
        }
        Dfs(0, -1, 0);
        Dfs(a, -1, 0);
        return ans;
    }

    private void Dfs(int i, int fa, int t) {
        foreach (int j in g[i]) {
            if (j != fa) {
                Dfs(j, i, t + 1);
            }
        }
        if (ans < t) {
            ans = t;
            a = i;
        }
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3204. 按位用户权限分析 🔒](https://leetcode.cn/problems/bitwise-user-permissions-analysis){#3204}

{{< tabs "3204" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT
    BIT_AND(permissions) AS common_perms,
    BIT_OR(permissions) AS any_perms
FROM user_permissions;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code>user_permissions</code></p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| user_id     | int     |
| permissions | int     |
+-------------+---------+
user_id 是主键。
这张表的每一行包含用户 ID 和他们的权限，编码为一个整数。
</pre>

<p><code>permissions</code>&nbsp;整数中的每一个二进制位代表一个用户拥有的一个不同的访问级别或功能。</p>

<p>编写一个解决方案来计算以下内容：</p>

<ul>
	<li>common_perms：授予 <strong>所有用户</strong> 的访问级别。在&nbsp;<code>permissions</code>&nbsp;列上使用 <strong>按位与&nbsp;</strong>操作来计算。</li>
	<li>any_perms：授予 <strong>任一用户</strong> 的访问级别。在&nbsp;<code>permissions</code>&nbsp;列上使用 <strong>按位或 </strong>操作来计算。</li>
</ul>

<p>以&nbsp;<strong>任意&nbsp;</strong>顺序返回结果表。</p>

<p>结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong class="example">示例：</strong></p>

<div class="example-block">
<p><strong>输入：</strong></p>

<p>user_permissions 表：</p>

<pre class="example-io">
+---------+-------------+
| user_id | permissions |
+---------+-------------+
| 1       | 5           |
| 2       | 12          |
| 3       | 7           |
| 4       | 3           |
+---------+-------------+
 </pre>

<p><strong>输出：</strong></p>

<pre class="example-io">
+-------------+--------------+
| common_perms | any_perms   |
+--------------+-------------+
| 0            | 15          |
+--------------+-------------+
    </pre>

<p><strong>解释：</strong></p>

<ul>
	<li><strong>common_perms:</strong> 代表所有权限的按位与结果：

    <ul>
    	<li>对于用户 1 (5): 5 (二进制 0101)</li>
    	<li>对于用户 2 (12): 12 (二进制 1100)</li>
    	<li>对于用户 3 (7): 7 (二进制 0111)</li>
    	<li>对于用户 4 (3): 3 (二进制 0011)</li>
    	<li>按位与：5 &amp; 12 &amp; 7 &amp; 3 = 0 (二进制 0000)</li>
    </ul>
    </li>
    <li><strong>any_perms:</strong> 代表所有权限的按位或结果：
    <ul>
    	<li>按位或：5 | 12 | 7 | 3 = 15 (二进制 1111)</li>
    </ul>
    </li>

</ul>
</div>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：位运算

我们可以使用 `BIT_AND` 和 `BIT_OR` 函数来计算 `common_perms` 和 `any_perms`。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT
    BIT_AND(permissions) AS common_perms,
    BIT_OR(permissions) AS any_perms
FROM user_permissions;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3205. 最大数组跳跃得分 I 🔒](https://leetcode.cn/problems/maximum-array-hopping-score-i){#3205}

{{< tabs "3205" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxScore(self, nums: List[int]) -> int:
        stk = []
        for i, x in enumerate(nums):
            while stk and nums[stk[-1]] <= x:
                stk.pop()
            stk.append(i)
        ans = i = 0
        for j in stk:
            ans += nums[j] * (j - i)
            i = j
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxScore(int[] nums) {
        Deque<Integer> stk = new ArrayDeque<>();
        for (int i = 0; i < nums.length; ++i) {
            while (!stk.isEmpty() && nums[stk.peek()] <= nums[i]) {
                stk.pop();
            }
            stk.push(i);
        }
        int ans = 0, i = 0;
        while (!stk.isEmpty()) {
            int j = stk.pollLast();
            ans += (j - i) * nums[j];
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
    int maxScore(vector<int>& nums) {
        vector<int> stk;
        for (int i = 0; i < nums.size(); ++i) {
            while (stk.size() && nums[stk.back()] <= nums[i]) {
                stk.pop_back();
            }
            stk.push_back(i);
        }
        int ans = 0, i = 0;
        for (int j : stk) {
            ans += (j - i) * nums[j];
            i = j;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxScore(nums []int) (ans int) {
	stk := []int{}
	for i, x := range nums {
		for len(stk) > 0 && nums[stk[len(stk)-1]] <= x {
			stk = stk[:len(stk)-1]
		}
		stk = append(stk, i)
	}
	i := 0
	for _, j := range stk {
		ans += (j - i) * nums[j]
		i = j
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxScore(nums: number[]): number {
    const stk: number[] = [];
    for (let i = 0; i < nums.length; ++i) {
        while (stk.length && nums[stk.at(-1)!] <= nums[i]) {
            stk.pop();
        }
        stk.push(i);
    }
    let ans = 0;
    let i = 0;
    for (const j of stk) {
        ans += (j - i) * nums[j];
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

<p>给定一个数组&nbsp;<code>nums</code>，你必须从索引 0 开始跳跃，直到到达数组的最后一个元素，使得获取 <strong>最大</strong> 分数。</p>

<p>每一次 <strong>跳跃</strong> 中，你可以从下标&nbsp;<code>i</code>&nbsp;跳到一个&nbsp;<code>j &gt; i</code>&nbsp;的下标，并且可以得到&nbsp;<code>(j - i) * nums[j]</code>&nbsp;的分数。</p>

<p>返回你能够取得的最大分数。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b></span><span class="example-io">nums = [1,5,8]</span></p>

<p><span class="example-io"><b>输出：</b>16</span></p>

<p><strong>解释：</strong></p>

<p>有两种可能的方法可以到达最后一个元素：</p>

<ul>
	<li><code>0 -&gt; 1 -&gt; 2</code> 得分为&nbsp;<code>(1 - 0) * 5 + (2 - 1) * 8 = 13</code>。</li>
	<li><code>0 -&gt; 2</code> 得分为&nbsp;<code>(2 - 0) * 8 =&nbsp;16</code>。</li>
</ul>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [4,5,2,8,9,1,3]</span></p>

<p><span class="example-io"><b>输出：</b>42</span></p>

<p><strong>解释：</strong></p>

<p>我们可以按&nbsp;<code>0 -&gt; 4 -&gt; 6</code>&nbsp;进行跳跃，得分为&nbsp;<code>(4 - 0) * 9 + (6 - 4) * 3 = 42</code>。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 10<sup>3</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

我们设计一个函数 $\textit{dfs}(i)$，表示从下标 $i$ 出发，能够获得的最大分数。那么答案就是 $\textit{dfs}(0)$。

函数 $\textit{dfs}(i)$ 的执行过程如下：

我们枚举下一个跳跃的位置 $j$，那么从下标 $i$ 出发，能够获得的分数就是 $(j - i) \times \textit{nums}[j]$，加上从下标 $j$ 出发，能够获得的最大分数，总分数就是 $(j - i) \times \textit{nums}[j] + \textit{dfs}(j)$。我们枚举所有的 $j$，取分数的最大值即可。

为了避免重复计算，我们使用记忆化搜索的方法，将已经计算过的 $\textit{dfs}(i)$ 的值保存起来，下次直接返回即可。

时间复杂度 $O(n^2)$，空间复杂度 $O(n)$。其中 $n$ 是数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxScore(self, nums: List[int]) -> int:
        @cache
        def dfs(i: int) -> int:
            return max(
                [(j - i) * nums[j] + dfs(j) for j in range(i + 1, len(nums))] or [0]
            )

        return dfs(0)
```

#### Java

```java
class Solution {
    private Integer[] f;
    private int[] nums;
    private int n;

    public int maxScore(int[] nums) {
        n = nums.length;
        f = new Integer[n];
        this.nums = nums;
        return dfs(0);
    }

    private int dfs(int i) {
        if (f[i] != null) {
            return f[i];
        }
        f[i] = 0;
        for (int j = i + 1; j < n; ++j) {
            f[i] = Math.max(f[i], (j - i) * nums[j] + dfs(j));
        }
        return f[i];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n);
        auto dfs = [&](this auto&& dfs, int i) -> int {
            if (f[i]) {
                return f[i];
            }
            for (int j = i + 1; j < n; ++j) {
                f[i] = max(f[i], (j - i) * nums[j] + dfs(j));
            }
            return f[i];
        };
        return dfs(0);
    }
};
```

#### Go

```go
func maxScore(nums []int) int {
	n := len(nums)
	f := make([]int, n)
	var dfs func(int) int
	dfs = func(i int) int {
		if f[i] > 0 {
			return f[i]
		}
		for j := i + 1; j < n; j++ {
			f[i] = max(f[i], (j-i)*nums[j]+dfs(j))
		}
		return f[i]
	}
	return dfs(0)
}
```

#### TypeScript

```ts
function maxScore(nums: number[]): number {
    const n = nums.length;
    const f: number[] = Array(n).fill(0);
    const dfs = (i: number): number => {
        if (f[i]) {
            return f[i];
        }
        for (let j = i + 1; j < n; ++j) {
            f[i] = Math.max(f[i], (j - i) * nums[j] + dfs(j));
        }
        return f[i];
    };
    return dfs(0);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：动态规划

我们可以将方法一中的记忆化搜索转换为动态规划。

定义 $f[j]$ 表示从下标 $0$ 出发，到下标 $j$ 结束，能够获得的最大分数。那么答案就是 $f[n - 1]$。

状态转移方程为：

$$
f[j] = \max_{0 \leq i < j} \{ f[i] + (j - i) \times \textit{nums}[j] \}
$$

时间复杂度 $O(n^2)$，空间复杂度 $O(n)$。其中 $n$ 是数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxScore(self, nums: List[int]) -> int:
        n = len(nums)
        f = [0] * n
        for j in range(1, n):
            for i in range(j):
                f[j] = max(f[j], f[i] + (j - i) * nums[j])
        return f[n - 1]
```

#### Java

```java
class Solution {
    public int maxScore(int[] nums) {
        int n = nums.length;
        int[] f = new int[n];
        for (int j = 1; j < n; ++j) {
            for (int i = 0; i < j; ++i) {
                f[j] = Math.max(f[j], f[i] + (j - i) * nums[j]);
            }
        }
        return f[n - 1];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n);
        for (int j = 1; j < n; ++j) {
            for (int i = 0; i < j; ++i) {
                f[j] = max(f[j], f[i] + (j - i) * nums[j]);
            }
        }
        return f[n - 1];
    }
};
```

#### Go

```go
func maxScore(nums []int) int {
	n := len(nums)
	f := make([]int, n)
	for j := 1; j < n; j++ {
		for i := 0; i < j; i++ {
			f[j] = max(f[j], f[i]+(j-i)*nums[j])
		}
	}
	return f[n-1]
}
```

#### TypeScript

```ts
function maxScore(nums: number[]): number {
    const n = nums.length;
    const f: number[] = Array(n).fill(0);
    for (let j = 1; j < n; ++j) {
        for (let i = 0; i < j; ++i) {
            f[j] = Math.max(f[j], f[i] + (j - i) * nums[j]);
        }
    }
    return f[n - 1];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法三：单调栈

我们观察发现，对于当前位置 $i$，我们应该跳到下一个值最大的位置 $j$，这样才能获得最大的分数。

因此，我们遍历数组 $\textit{nums}$，维护一个从栈底到栈顶单调递减的栈 $\textit{stk}$。对于当前遍历到的位置 $i$，如果栈顶元素对应的值小于等于 $\textit{nums}[i]$，我们就不断地弹出栈顶元素，直到栈为空或者栈顶元素对应的值大于 $\textit{nums}[i]$，然后将 $i$ 入栈。

然后，我们初始化答案 $\textit{ans}$ 和当前位置 $i = 0$，遍历栈中的元素，每次取出栈顶元素 $j$，更新答案 $\textit{ans} += \textit{nums}[j] \times (j - i)$，然后更新 $i = j$。

最后返回答案 $\textit{ans}$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxScore(self, nums: List[int]) -> int:
        stk = []
        for i, x in enumerate(nums):
            while stk and nums[stk[-1]] <= x:
                stk.pop()
            stk.append(i)
        ans = i = 0
        for j in stk:
            ans += nums[j] * (j - i)
            i = j
        return ans
```

#### Java

```java
class Solution {
    public int maxScore(int[] nums) {
        Deque<Integer> stk = new ArrayDeque<>();
        for (int i = 0; i < nums.length; ++i) {
            while (!stk.isEmpty() && nums[stk.peek()] <= nums[i]) {
                stk.pop();
            }
            stk.push(i);
        }
        int ans = 0, i = 0;
        while (!stk.isEmpty()) {
            int j = stk.pollLast();
            ans += (j - i) * nums[j];
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
    int maxScore(vector<int>& nums) {
        vector<int> stk;
        for (int i = 0; i < nums.size(); ++i) {
            while (stk.size() && nums[stk.back()] <= nums[i]) {
                stk.pop_back();
            }
            stk.push_back(i);
        }
        int ans = 0, i = 0;
        for (int j : stk) {
            ans += (j - i) * nums[j];
            i = j;
        }
        return ans;
    }
};
```

#### Go

```go
func maxScore(nums []int) (ans int) {
	stk := []int{}
	for i, x := range nums {
		for len(stk) > 0 && nums[stk[len(stk)-1]] <= x {
			stk = stk[:len(stk)-1]
		}
		stk = append(stk, i)
	}
	i := 0
	for _, j := range stk {
		ans += (j - i) * nums[j]
		i = j
	}
	return
}
```

#### TypeScript

```ts
function maxScore(nums: number[]): number {
    const stk: number[] = [];
    for (let i = 0; i < nums.length; ++i) {
        while (stk.length && nums[stk.at(-1)!] <= nums[i]) {
            stk.pop();
        }
        stk.push(i);
    }
    let ans = 0;
    let i = 0;
    for (const j of stk) {
        ans += (j - i) * nums[j];
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

# [3206. 交替组 I](https://leetcode.cn/problems/alternating-groups-i){#3206}

{{< tabs "3206" >}}

{{% tab "python" %}}
```python
class Solution:
    def numberOfAlternatingGroups(self, colors: List[int]) -> int:
        k = 3
        n = len(colors)
        ans = cnt = 0
        for i in range(n << 1):
            if i and colors[i % n] == colors[(i - 1) % n]:
                cnt = 1
            else:
                cnt += 1
            ans += i >= n and cnt >= k
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numberOfAlternatingGroups(int[] colors) {
        int k = 3;
        int n = colors.length;
        int ans = 0, cnt = 0;
        for (int i = 0; i < n << 1; ++i) {
            if (i > 0 && colors[i % n] == colors[(i - 1) % n]) {
                cnt = 1;
            } else {
                ++cnt;
            }
            ans += i >= n && cnt >= k ? 1 : 0;
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
    int numberOfAlternatingGroups(vector<int>& colors) {
        int k = 3;
        int n = colors.size();
        int ans = 0, cnt = 0;
        for (int i = 0; i < n << 1; ++i) {
            if (i && colors[i % n] == colors[(i - 1) % n]) {
                cnt = 1;
            } else {
                ++cnt;
            }
            ans += i >= n && cnt >= k ? 1 : 0;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numberOfAlternatingGroups(colors []int) (ans int) {
	k := 3
	n := len(colors)
	cnt := 0
	for i := 0; i < n<<1; i++ {
		if i > 0 && colors[i%n] == colors[(i-1)%n] {
			cnt = 1
		} else {
			cnt++
		}
		if i >= n && cnt >= k {
			ans++
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numberOfAlternatingGroups(colors: number[]): number {
    const k = 3;
    const n = colors.length;
    let [ans, cnt] = [0, 0];
    for (let i = 0; i < n << 1; ++i) {
        if (i && colors[i % n] === colors[(i - 1) % n]) {
            cnt = 1;
        } else {
            ++cnt;
        }
        ans += i >= n && cnt >= k ? 1 : 0;
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

<p>给你一个整数数组 <code>colors</code>&nbsp;，它表示一个由红色和蓝色瓷砖组成的环，第 <code>i</code>&nbsp;块瓷砖的颜色为&nbsp;<code>colors[i]</code>&nbsp;：</p>

<ul>
	<li><code>colors[i] == 0</code>&nbsp;表示第&nbsp;<code>i</code>&nbsp;块瓷砖的颜色是 <strong>红色</strong>&nbsp;。</li>
	<li><code>colors[i] == 1</code>&nbsp;表示第 <code>i</code>&nbsp;块瓷砖的颜色是 <strong>蓝色</strong>&nbsp;。</li>
</ul>

<p>环中连续 3 块瓷砖的颜色如果是 <strong>交替</strong>&nbsp;颜色（也就是说中间瓷砖的颜色与它<strong>&nbsp;左边</strong>&nbsp;和 <strong>右边</strong>&nbsp;的颜色都不同），那么它被称为一个 <strong>交替</strong>&nbsp;组。</p>

<p>请你返回 <strong>交替</strong>&nbsp;组的数目。</p>

<p><b>注意</b>&nbsp;，由于&nbsp;<code>colors</code>&nbsp;表示一个 <strong>环</strong>&nbsp;，<strong>第一块</strong>&nbsp;瓷砖和 <strong>最后一块</strong>&nbsp;瓷砖是相邻的。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>colors = [1,1,1]</span></p>

<p><span class="example-io"><b>输出：</b>0</span></p>

<p><strong>解释：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3200-3299/3206.Alternating%20Groups%20I/images/image_2024-05-16_23-53-171.png" style="width: 150px; height: 150px; padding: 10px; background: #fff; border-radius: .5rem;" /></p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>colors = [0,1,0,0,1]</span></p>

<p><b>输出：</b>3</p>

<p><b>解释：</b></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3200-3299/3206.Alternating%20Groups%20I/images/image_2024-05-16_23-47-491.png" style="width: 150px; height: 150px; padding: 10px; background: #fff; border-radius: .5rem;" /></p>

<p>交替组包括：</p>

<p><strong class="example"><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3200-3299/3206.Alternating%20Groups%20I/images/image_2024-05-16_23-50-441.png" style="width: 150px; height: 150px; padding: 10px; background: #fff; border-radius: .5rem;" /></strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3200-3299/3206.Alternating%20Groups%20I/images/image_2024-05-16_23-48-211.png" style="width: 150px; height: 150px; padding: 10px; background: #fff; border-radius: .5rem;" /><strong class="example"><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3200-3299/3206.Alternating%20Groups%20I/images/image_2024-05-16_23-49-351.png" style="width: 150px; height: 150px; padding: 10px; background: #fff; border-radius: .5rem;" /></strong></p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= colors.length &lt;= 100</code></li>
	<li><code>0 &lt;= colors[i] &lt;= 1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：一次遍历

我们令 $k = 3$，表示交替组的长度为 $3$。

为了方便处理，我们可以将环展开成一个长度为 $2n$ 的数组，然后从左到右遍历这个数组，用一个变量 $\textit{cnt}$ 记录当前交替组的长度，如果遇到了相同的颜色，就将 $\textit{cnt}$ 重置为 $1$，否则将 $\textit{cnt}$ 加一。如果 $\textit{cnt} \ge k$，并且当前位置 $i$ 大于等于 $n$，那么就找到了一个交替组，答案加一。

遍历结束后，返回答案即可。

时间复杂度 $O(n)$，其中 $n$ 为数组 $\textit{colors}$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numberOfAlternatingGroups(self, colors: List[int]) -> int:
        k = 3
        n = len(colors)
        ans = cnt = 0
        for i in range(n << 1):
            if i and colors[i % n] == colors[(i - 1) % n]:
                cnt = 1
            else:
                cnt += 1
            ans += i >= n and cnt >= k
        return ans
```

#### Java

```java
class Solution {
    public int numberOfAlternatingGroups(int[] colors) {
        int k = 3;
        int n = colors.length;
        int ans = 0, cnt = 0;
        for (int i = 0; i < n << 1; ++i) {
            if (i > 0 && colors[i % n] == colors[(i - 1) % n]) {
                cnt = 1;
            } else {
                ++cnt;
            }
            ans += i >= n && cnt >= k ? 1 : 0;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int k = 3;
        int n = colors.size();
        int ans = 0, cnt = 0;
        for (int i = 0; i < n << 1; ++i) {
            if (i && colors[i % n] == colors[(i - 1) % n]) {
                cnt = 1;
            } else {
                ++cnt;
            }
            ans += i >= n && cnt >= k ? 1 : 0;
        }
        return ans;
    }
};
```

#### Go

```go
func numberOfAlternatingGroups(colors []int) (ans int) {
	k := 3
	n := len(colors)
	cnt := 0
	for i := 0; i < n<<1; i++ {
		if i > 0 && colors[i%n] == colors[(i-1)%n] {
			cnt = 1
		} else {
			cnt++
		}
		if i >= n && cnt >= k {
			ans++
		}
	}
	return
}
```

#### TypeScript

```ts
function numberOfAlternatingGroups(colors: number[]): number {
    const k = 3;
    const n = colors.length;
    let [ans, cnt] = [0, 0];
    for (let i = 0; i < n << 1; ++i) {
        if (i && colors[i % n] === colors[(i - 1) % n]) {
            cnt = 1;
        } else {
            ++cnt;
        }
        ans += i >= n && cnt >= k ? 1 : 0;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3207. 与敌人战斗后的最大分数](https://leetcode.cn/problems/maximum-points-after-enemy-battles){#3207}

{{< tabs "3207" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumPoints(self, enemyEnergies: List[int], currentEnergy: int) -> int:
        enemyEnergies.sort()
        if currentEnergy < enemyEnergies[0]:
            return 0
        ans = 0
        for i in range(len(enemyEnergies) - 1, -1, -1):
            ans += currentEnergy // enemyEnergies[0]
            currentEnergy %= enemyEnergies[0]
            currentEnergy += enemyEnergies[i]
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long maximumPoints(int[] enemyEnergies, int currentEnergy) {
        Arrays.sort(enemyEnergies);
        if (currentEnergy < enemyEnergies[0]) {
            return 0;
        }
        long ans = 0;
        for (int i = enemyEnergies.length - 1; i >= 0; --i) {
            ans += currentEnergy / enemyEnergies[0];
            currentEnergy %= enemyEnergies[0];
            currentEnergy += enemyEnergies[i];
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        sort(enemyEnergies.begin(), enemyEnergies.end());
        if (currentEnergy < enemyEnergies[0]) {
            return 0;
        }
        long long ans = 0;
        for (int i = enemyEnergies.size() - 1; i >= 0; --i) {
            ans += currentEnergy / enemyEnergies[0];
            currentEnergy %= enemyEnergies[0];
            currentEnergy += enemyEnergies[i];
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumPoints(enemyEnergies []int, currentEnergy int) (ans int64) {
	sort.Ints(enemyEnergies)
	if currentEnergy < enemyEnergies[0] {
		return 0
	}
	for i := len(enemyEnergies) - 1; i >= 0; i-- {
		ans += int64(currentEnergy / enemyEnergies[0])
		currentEnergy %= enemyEnergies[0]
		currentEnergy += enemyEnergies[i]
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumPoints(enemyEnergies: number[], currentEnergy: number): number {
    enemyEnergies.sort((a, b) => a - b);
    if (currentEnergy < enemyEnergies[0]) {
        return 0;
    }
    let ans = 0;
    for (let i = enemyEnergies.length - 1; ~i; --i) {
        ans += Math.floor(currentEnergy / enemyEnergies[0]);
        currentEnergy %= enemyEnergies[0];
        currentEnergy += enemyEnergies[i];
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

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>enemyEnergies</code>&nbsp;，它表示一个下标从 <strong>0</strong>&nbsp;开始的敌人能量数组。</p>

<p>同时给你一个整数&nbsp;<code>currentEnergy</code>&nbsp;，它表示你一开始拥有的能量值总量。</p>

<p>你一开始的分数为&nbsp;<code>0</code>&nbsp;，且一开始所有的敌人都未标记。</p>

<p>你可以通过以下操作 <b>之一</b>&nbsp;<strong>任意次</strong>（也可以&nbsp;<strong>0</strong>&nbsp;次）来得分：</p>

<ul>
	<li>选择一个 <strong>未标记</strong>&nbsp;且满足&nbsp;<code>currentEnergy &gt;= enemyEnergies[i]</code>&nbsp;的敌人&nbsp;<code>i</code>&nbsp;。在这个操作中：

    <ul>
    	<li>你会获得 <code>1</code>&nbsp;分。</li>
    	<li>你的能量值减少&nbsp;<code>enemyEnergies[i]</code>&nbsp;，也就是说&nbsp;<code>currentEnergy = currentEnergy - enemyEnergies[i]</code>&nbsp;。</li>
    </ul>
    </li>
    <li>如果你目前&nbsp;<strong>至少</strong>&nbsp;有 <code>1</code>&nbsp;分，你可以选择一个&nbsp;<strong>未标记</strong>&nbsp;的敌人&nbsp;<code>i</code>&nbsp;。在这个操作中：
    <ul>
    	<li>你的能量值增加 <code>enemyEnergies[i]</code>&nbsp;，也就是说&nbsp;<code>currentEnergy = currentEnergy + enemyEnergies[i]</code>&nbsp;。</li>
    	<li>敌人&nbsp;<code>i</code> <strong>被标记</strong>&nbsp;。</li>
    </ul>
    </li>

</ul>

<p>请你返回通过以上操作，<strong>最多</strong>&nbsp;可以获得多少分。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><b>输入：</b>enemyEnergies = [3,2,2], currentEnergy = 2</p>

<p><b>输出：</b>3</p>

<p><strong>解释：</strong></p>

<p>通过以下操作可以得到最大得分 3 分：</p>

<ul>
	<li>对敌人 1 使用第一种操作：<code>points</code>&nbsp;增加 1 ，<code>currentEnergy</code>&nbsp;减少 2 。所以&nbsp;<code>points = 1</code>&nbsp;且&nbsp;<code>currentEnergy = 0</code>&nbsp;。</li>
	<li>对敌人 0 使用第二种操作：<code>currentEnergy</code>&nbsp;增加 3 ，敌人 0 被标记。所以&nbsp;<code>points = 1</code>&nbsp;，<code>currentEnergy = 3</code>&nbsp;，被标记的敌人包括&nbsp;<code>[0]</code>&nbsp;。</li>
	<li>对敌人 2 使用第一种操作：<code>points</code>&nbsp;增加 1 ，<code>currentEnergy</code>&nbsp;减少 2 。所以&nbsp;<code>points = 2</code>&nbsp;且&nbsp;<code>currentEnergy = 1</code>&nbsp;，被标记的敌人包括<code>[0]</code>&nbsp;。</li>
	<li>对敌人 2 使用第二种操作：<code>currentEnergy</code>&nbsp;增加 2 ，敌人 2 被标记。所以&nbsp;<code>points = 2</code>&nbsp;，<code>currentEnergy = 3</code>&nbsp;且被标记的敌人包括&nbsp;<code>[0, 2]</code>&nbsp;。</li>
	<li>对敌人 1 使用第一种操作：<code>points</code>&nbsp;增加 1 ，<code>currentEnergy</code>&nbsp;减少 2 。所以&nbsp;<code>points = 3</code>&nbsp;，<code>currentEnergy = 1</code>&nbsp;，被标记的敌人包括&nbsp;<code>[0, 2]</code>&nbsp;。</li>
</ul>

<p><strong>示例 2：</strong></p>

<p><b>输入：</b>enemyEnergies =&nbsp;[2], currentEnergy = 10</p>

<p><b>输出：</b>5</p>

<p><strong>解释：</strong></p>

<p>通过对敌人 0 进行第一种操作 5 次，得到最大得分。</p>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= enemyEnergies.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= enemyEnergies[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= currentEnergy &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 排序

根据题目描述，我们每次需要通过具有最小能量值的敌人来获得分数，通过具有最大能量值的敌人来增加能量值并进行标记。

因此，我们可以对敌人的能量值进行排序，然后从能量值最大的敌人开始，每次都选择能量值最小的敌人来获得分数，并消耗能量值。然后，我们将能量值最大的敌人的能量值加到当前能量值上，并标记该敌人。重复上述操作，直到所有敌人都被标记。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 是敌人的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumPoints(self, enemyEnergies: List[int], currentEnergy: int) -> int:
        enemyEnergies.sort()
        if currentEnergy < enemyEnergies[0]:
            return 0
        ans = 0
        for i in range(len(enemyEnergies) - 1, -1, -1):
            ans += currentEnergy // enemyEnergies[0]
            currentEnergy %= enemyEnergies[0]
            currentEnergy += enemyEnergies[i]
        return ans
```

#### Java

```java
class Solution {
    public long maximumPoints(int[] enemyEnergies, int currentEnergy) {
        Arrays.sort(enemyEnergies);
        if (currentEnergy < enemyEnergies[0]) {
            return 0;
        }
        long ans = 0;
        for (int i = enemyEnergies.length - 1; i >= 0; --i) {
            ans += currentEnergy / enemyEnergies[0];
            currentEnergy %= enemyEnergies[0];
            currentEnergy += enemyEnergies[i];
        }
        return ans;
    }
};
```

#### C++

```cpp
class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        sort(enemyEnergies.begin(), enemyEnergies.end());
        if (currentEnergy < enemyEnergies[0]) {
            return 0;
        }
        long long ans = 0;
        for (int i = enemyEnergies.size() - 1; i >= 0; --i) {
            ans += currentEnergy / enemyEnergies[0];
            currentEnergy %= enemyEnergies[0];
            currentEnergy += enemyEnergies[i];
        }
        return ans;
    }
};
```

#### Go

```go
func maximumPoints(enemyEnergies []int, currentEnergy int) (ans int64) {
	sort.Ints(enemyEnergies)
	if currentEnergy < enemyEnergies[0] {
		return 0
	}
	for i := len(enemyEnergies) - 1; i >= 0; i-- {
		ans += int64(currentEnergy / enemyEnergies[0])
		currentEnergy %= enemyEnergies[0]
		currentEnergy += enemyEnergies[i]
	}
	return
}
```

#### TypeScript

```ts
function maximumPoints(enemyEnergies: number[], currentEnergy: number): number {
    enemyEnergies.sort((a, b) => a - b);
    if (currentEnergy < enemyEnergies[0]) {
        return 0;
    }
    let ans = 0;
    for (let i = enemyEnergies.length - 1; ~i; --i) {
        ans += Math.floor(currentEnergy / enemyEnergies[0]);
        currentEnergy %= enemyEnergies[0];
        currentEnergy += enemyEnergies[i];
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3208. 交替组 II](https://leetcode.cn/problems/alternating-groups-ii){#3208}

{{< tabs "3208" >}}

{{% tab "python" %}}
```python
class Solution:
    def numberOfAlternatingGroups(self, colors: List[int], k: int) -> int:
        n = len(colors)
        ans = cnt = 0
        for i in range(n << 1):
            if i and colors[i % n] == colors[(i - 1) % n]:
                cnt = 1
            else:
                cnt += 1
            ans += i >= n and cnt >= k
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numberOfAlternatingGroups(int[] colors, int k) {
        int n = colors.length;
        int ans = 0, cnt = 0;
        for (int i = 0; i < n << 1; ++i) {
            if (i > 0 && colors[i % n] == colors[(i - 1) % n]) {
                cnt = 1;
            } else {
                ++cnt;
            }
            ans += i >= n && cnt >= k ? 1 : 0;
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
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int ans = 0, cnt = 0;
        for (int i = 0; i < n << 1; ++i) {
            if (i && colors[i % n] == colors[(i - 1) % n]) {
                cnt = 1;
            } else {
                ++cnt;
            }
            ans += i >= n && cnt >= k ? 1 : 0;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numberOfAlternatingGroups(colors []int, k int) (ans int) {
	n := len(colors)
	cnt := 0
	for i := 0; i < n<<1; i++ {
		if i > 0 && colors[i%n] == colors[(i-1)%n] {
			cnt = 1
		} else {
			cnt++
		}
		if i >= n && cnt >= k {
			ans++
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numberOfAlternatingGroups(colors: number[], k: number): number {
    const n = colors.length;
    let [ans, cnt] = [0, 0];
    for (let i = 0; i < n << 1; ++i) {
        if (i && colors[i % n] === colors[(i - 1) % n]) {
            cnt = 1;
        } else {
            ++cnt;
        }
        ans += i >= n && cnt >= k ? 1 : 0;
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

<p>给你一个整数数组 <code>colors</code>&nbsp;和一个整数&nbsp;<code>k</code>&nbsp;，<code>colors</code>表示一个由红色和蓝色瓷砖组成的环，第 <code>i</code>&nbsp;块瓷砖的颜色为&nbsp;<code>colors[i]</code>&nbsp;：</p>

<ul>
	<li><code>colors[i] == 0</code>&nbsp;表示第&nbsp;<code>i</code>&nbsp;块瓷砖的颜色是 <strong>红色</strong>&nbsp;。</li>
	<li><code>colors[i] == 1</code>&nbsp;表示第 <code>i</code>&nbsp;块瓷砖的颜色是 <strong>蓝色</strong>&nbsp;。</li>
</ul>

<p>环中连续 <code>k</code>&nbsp;块瓷砖的颜色如果是 <strong>交替</strong>&nbsp;颜色（也就是说除了第一块和最后一块瓷砖以外，中间瓷砖的颜色与它<strong>&nbsp;左边</strong>&nbsp;和 <strong>右边</strong>&nbsp;的颜色都不同），那么它被称为一个 <strong>交替</strong>&nbsp;组。</p>

<p>请你返回 <strong>交替</strong>&nbsp;组的数目。</p>

<p><b>注意</b>&nbsp;，由于&nbsp;<code>colors</code>&nbsp;表示一个 <strong>环</strong>&nbsp;，<strong>第一块</strong>&nbsp;瓷砖和 <strong>最后一块</strong>&nbsp;瓷砖是相邻的。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>colors = [0,1,0,1,0], k = 3</span></p>

<p><span class="example-io"><b>输出：</b>3</span></p>

<p><strong>解释：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3200-3299/3208.Alternating%20Groups%20II/images/screenshot-2024-05-28-183519.png" style="width: 150px; height: 150px; padding: 10px; background: #fff; border-radius: .5rem;" /></p>

<p>交替组包括：</p>

<p><strong class="example"><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3200-3299/3208.Alternating%20Groups%20II/images/screenshot-2024-05-28-182448.png" style="width: 150px; height: 150px; padding: 10px; background: #fff; border-radius: .5rem;" /></strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3200-3299/3208.Alternating%20Groups%20II/images/screenshot-2024-05-28-182844.png" style="width: 150px; height: 150px; padding: 10px; background: #fff; border-radius: .5rem;" /><strong class="example"><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3200-3299/3208.Alternating%20Groups%20II/images/screenshot-2024-05-28-183057.png" style="width: 150px; height: 150px; padding: 10px; background: #fff; border-radius: .5rem;" /></strong></p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>colors = [0,1,0,0,1,0,1], k = 6</span></p>

<p><b>输出：</b>2</p>

<p><b>解释：</b></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3200-3299/3208.Alternating%20Groups%20II/images/screenshot-2024-05-28-183907.png" style="width: 150px; height: 150px; padding: 10px; background: #fff; border-radius: .5rem;" /></p>

<p>交替组包括：</p>

<p><strong class="example"><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3200-3299/3208.Alternating%20Groups%20II/images/screenshot-2024-05-28-184128.png" style="width: 150px; height: 150px; padding: 10px; background: #fff; border-radius: .5rem;" /></strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3200-3299/3208.Alternating%20Groups%20II/images/screenshot-2024-05-28-184240.png" style="width: 150px; height: 150px; padding: 10px; background: #fff; border-radius: .5rem;" /></p>

<p><strong>示例 3：</strong></p>

<p><strong>输入：</strong>colors = [1,1,0,1], k = 4</p>

<p><strong>输出：</strong>0</p>

<p><strong>解释：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3200-3299/3208.Alternating%20Groups%20II/images/screenshot-2024-05-28-184516.png" style="width: 150px; height: 150px; padding: 10px; background: #fff; border-radius: .5rem;" /></p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= colors.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= colors[i] &lt;= 1</code></li>
	<li><code>3 &lt;= k &lt;= colors.length</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：一次遍历

我们可以将环展开成一个长度为 $2n$ 的数组，然后从左到右遍历这个数组，用一个变量 $\textit{cnt}$ 记录当前交替组的长度，如果遇到了相同的颜色，就将 $\textit{cnt}$ 重置为 $1$，否则将 $\textit{cnt}$ 加一。如果 $\textit{cnt} \ge k$，并且当前位置 $i$ 大于等于 $n$，那么就找到了一个交替组，答案加一。

遍历结束后，返回答案即可。

时间复杂度 $O(n)$，其中 $n$ 为数组 $\textit{colors}$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numberOfAlternatingGroups(self, colors: List[int], k: int) -> int:
        n = len(colors)
        ans = cnt = 0
        for i in range(n << 1):
            if i and colors[i % n] == colors[(i - 1) % n]:
                cnt = 1
            else:
                cnt += 1
            ans += i >= n and cnt >= k
        return ans
```

#### Java

```java
class Solution {
    public int numberOfAlternatingGroups(int[] colors, int k) {
        int n = colors.length;
        int ans = 0, cnt = 0;
        for (int i = 0; i < n << 1; ++i) {
            if (i > 0 && colors[i % n] == colors[(i - 1) % n]) {
                cnt = 1;
            } else {
                ++cnt;
            }
            ans += i >= n && cnt >= k ? 1 : 0;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int ans = 0, cnt = 0;
        for (int i = 0; i < n << 1; ++i) {
            if (i && colors[i % n] == colors[(i - 1) % n]) {
                cnt = 1;
            } else {
                ++cnt;
            }
            ans += i >= n && cnt >= k ? 1 : 0;
        }
        return ans;
    }
};
```

#### Go

```go
func numberOfAlternatingGroups(colors []int, k int) (ans int) {
	n := len(colors)
	cnt := 0
	for i := 0; i < n<<1; i++ {
		if i > 0 && colors[i%n] == colors[(i-1)%n] {
			cnt = 1
		} else {
			cnt++
		}
		if i >= n && cnt >= k {
			ans++
		}
	}
	return
}
```

#### TypeScript

```ts
function numberOfAlternatingGroups(colors: number[], k: number): number {
    const n = colors.length;
    let [ans, cnt] = [0, 0];
    for (let i = 0; i < n << 1; ++i) {
        if (i && colors[i % n] === colors[(i - 1) % n]) {
            cnt = 1;
        } else {
            ++cnt;
        }
        ans += i >= n && cnt >= k ? 1 : 0;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3209. 子数组按位与值为 K 的数目](https://leetcode.cn/problems/number-of-subarrays-with-and-value-of-k){#3209}

{{< tabs "3209" >}}

{{% tab "python" %}}
```python
class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        ans = 0
        pre = Counter()
        for x in nums:
            cur = Counter()
            for y, v in pre.items():
                cur[x & y] += v
            cur[x] += 1
            ans += cur[k]
            pre = cur
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long countSubarrays(int[] nums, int k) {
        long ans = 0;
        Map<Integer, Integer> pre = new HashMap<>();
        for (int x : nums) {
            Map<Integer, Integer> cur = new HashMap<>();
            for (var e : pre.entrySet()) {
                int y = e.getKey(), v = e.getValue();
                cur.merge(x & y, v, Integer::sum);
            }
            cur.merge(x, 1, Integer::sum);
            ans += cur.getOrDefault(k, 0);
            pre = cur;
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
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans = 0;
        unordered_map<int, int> pre;
        for (int x : nums) {
            unordered_map<int, int> cur;
            for (auto& [y, v] : pre) {
                cur[x & y] += v;
            }
            cur[x]++;
            ans += cur[k];
            pre = cur;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countSubarrays(nums []int, k int) (ans int64) {
	pre := map[int]int{}
	for _, x := range nums {
		cur := map[int]int{}
		for y, v := range pre {
			cur[x&y] += v
		}
		cur[x]++
		ans += int64(cur[k])
		pre = cur
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countSubarrays(nums: number[], k: number): number {
    let ans = 0;
    let pre = new Map<number, number>();
    for (const x of nums) {
        const cur = new Map<number, number>();
        for (const [y, v] of pre) {
            const z = x & y;
            cur.set(z, (cur.get(z) || 0) + v);
        }
        cur.set(x, (cur.get(x) || 0) + 1);
        ans += cur.get(k) || 0;
        pre = cur;
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

<p>给你一个整数数组&nbsp;<code>nums</code>&nbsp;和一个整数&nbsp;<code>k</code>&nbsp;，请你返回&nbsp;<code>nums</code>&nbsp;中有多少个<span data-keyword="subarray-nonempty">子数组</span>满足：子数组中所有元素按位&nbsp;<code>AND</code>&nbsp;的结果为 <code>k</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [1,1,1], k = 1</span></p>

<p><span class="example-io"><b>输出：</b>6</span></p>

<p><strong>解释：</strong></p>

<p>所有子数组都只含有元素 1 。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [1,1,2], k = 1</span></p>

<p><span class="example-io"><b>输出：</b>3</span></p>

<p><b>解释：</b></p>

<p>按位&nbsp;<code>AND</code>&nbsp;值为 1 的子数组包括：<code>[<u><strong>1</strong></u>,1,2]</code>, <code>[1,<u><strong>1</strong></u>,2]</code>, <code>[<u><strong>1,1</strong></u>,2]</code>&nbsp;。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [1,2,3], k = 2</span></p>

<p><span class="example-io"><b>输出：</b>2</span></p>

<p><strong>解释：</strong></p>

<p>按位&nbsp;<code>AND</code>&nbsp;值为 2 的子数组包括：<code>[1,<b><u>2</u></b>,3]</code>, <code>[1,<u><strong>2,3</strong></u>]</code>&nbsp;。</p>
</div>

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

### 方法一：哈希表 + 枚举

根据题目描述，我们需要求出数组 $\textit{nums}$ 下标 $l$ 到 $r$ 的元素的按位与运算的结果，即 $\textit{nums}[l] \land \textit{nums}[l + 1] \land \cdots \land \textit{nums}[r]$。其中 $\land$ 表示按位与运算。

如果我们每次固定右端点 $r$，那么左端点 $l$ 的范围是 $[0, r]$。由于按位与之和随着 $l$ 的减小而单调递减，并且 $nums[i]$ 的值不超过 $10^9$，因此区间 $[0, r]$ 最多只有 $30$ 种不同的值。因此，我们可以用一个集合来维护所有的 $\textit{nums}[l] \land \textit{nums}[l + 1] \land \cdots \land \textit{nums}[r]$ 的值，以及这些值出现的次数。

当我们从 $r$ 遍历到 $r+1$ 时，以 $r+1$ 为右端点的值，就是集合中每个值与 $nums[r + 1]$ 进行按位与运算得到的值，再加上 $\textit{nums}[r + 1]$ 本身。

因此，我们只需要枚举集合中的每个值，与 $\textit{nums[r]}$ 进行按位与运算，就可以得到以 $r$ 为右端点的所有值及其出现的次数。然后，我们还需要将 $\textit{nums[r]}$ 的出现次数加上去。此时，我们将值为 $k$ 的出现次数累加到答案中。继续遍历 $r$，直到遍历完整个数组。

时间复杂度 $O(n \times \log M)$，空间复杂度 $O(\log M)$。其中 $n$ 和 $M$ 分别是数组 $\textit{nums}$ 的长度和数组 $\textit{nums}$ 中元素的最大值。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        ans = 0
        pre = Counter()
        for x in nums:
            cur = Counter()
            for y, v in pre.items():
                cur[x & y] += v
            cur[x] += 1
            ans += cur[k]
            pre = cur
        return ans
```

#### Java

```java
class Solution {
    public long countSubarrays(int[] nums, int k) {
        long ans = 0;
        Map<Integer, Integer> pre = new HashMap<>();
        for (int x : nums) {
            Map<Integer, Integer> cur = new HashMap<>();
            for (var e : pre.entrySet()) {
                int y = e.getKey(), v = e.getValue();
                cur.merge(x & y, v, Integer::sum);
            }
            cur.merge(x, 1, Integer::sum);
            ans += cur.getOrDefault(k, 0);
            pre = cur;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans = 0;
        unordered_map<int, int> pre;
        for (int x : nums) {
            unordered_map<int, int> cur;
            for (auto& [y, v] : pre) {
                cur[x & y] += v;
            }
            cur[x]++;
            ans += cur[k];
            pre = cur;
        }
        return ans;
    }
};
```

#### Go

```go
func countSubarrays(nums []int, k int) (ans int64) {
	pre := map[int]int{}
	for _, x := range nums {
		cur := map[int]int{}
		for y, v := range pre {
			cur[x&y] += v
		}
		cur[x]++
		ans += int64(cur[k])
		pre = cur
	}
	return
}
```

#### TypeScript

```ts
function countSubarrays(nums: number[], k: number): number {
    let ans = 0;
    let pre = new Map<number, number>();
    for (const x of nums) {
        const cur = new Map<number, number>();
        for (const [y, v] of pre) {
            const z = x & y;
            cur.set(z, (cur.get(z) || 0) + v);
        }
        cur.set(x, (cur.get(x) || 0) + 1);
        ans += cur.get(k) || 0;
        pre = cur;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
