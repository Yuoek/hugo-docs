---
title: "3190_使所有元素都可以被 3 整除的最少操作数"
date: 2025-10-08T18:40:09+08:00
weight: 10
tags: [位运算, 前缀和, 动态规划, 双指针, 排序, 数学, 数据库, 数组, 枚举, 滑动窗口, 矩阵, 贪心, 队列]
---

{{< markmap >}}
### [3190_使所有元素都可以被 3 整除的最少操作数](#3190)
#### [数组](#3190)
#### [数学](#3190)
### [3191_使二进制数组全部等于 1 的最少操作次数 I](#3191)
#### [位运算](#3191)
#### [队列](#3191)
#### [数组](#3191)
#### [前缀和](#3191)
#### [滑动窗口](#3191)
### [3192_使二进制数组全部等于 1 的最少操作次数 II](#3192)
#### [贪心](#3192)
#### [数组](#3192)
#### [动态规划](#3192)
### [3193_统计逆序对的数目](#3193)
#### [数组](#3193)
#### [动态规划](#3193)
### [3194_最小元素和最大元素的最小平均值](#3194)
#### [数组](#3194)
#### [双指针](#3194)
#### [排序](#3194)
### [3195_包含所有 1 的最小矩形面积 I](#3195)
#### [数组](#3195)
#### [矩阵](#3195)
### [3196_最大化子数组的总成本](#3196)
#### [数组](#3196)
#### [动态规划](#3196)
### [3197_包含所有 1 的最小矩形面积 II](#3197)
#### [数组](#3197)
#### [枚举](#3197)
#### [矩阵](#3197)
### [3198_查找每个州的城市 🔒](#3198)
#### [数据库](#3198)
### [3199_用偶数异或设置位计数三元组 I 🔒](#3199)
#### [位运算](#3199)
#### [数组](#3199)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 3190_使所有元素都可以被 3 整除的最少操作数
___
#### 数组
___
#### 数学
---
### 3191_使二进制数组全部等于 1 的最少操作次数 I
___
#### 位运算
___
#### 队列
___
#### 数组
___
#### 前缀和
___
#### 滑动窗口
---
### 3192_使二进制数组全部等于 1 的最少操作次数 II
___
#### 贪心
___
#### 数组
___
#### 动态规划
---
### 3193_统计逆序对的数目
___
#### 数组
___
#### 动态规划
---
### 3194_最小元素和最大元素的最小平均值
___
#### 数组
___
#### 双指针
___
#### 排序
---
### 3195_包含所有 1 的最小矩形面积 I
___
#### 数组
___
#### 矩阵
---
### 3196_最大化子数组的总成本
___
#### 数组
___
#### 动态规划
---
### 3197_包含所有 1 的最小矩形面积 II
___
#### 数组
___
#### 枚举
___
#### 矩阵
---
### 3198_查找每个州的城市 🔒
___
#### 数据库
---
### 3199_用偶数异或设置位计数三元组 I 🔒
___
#### 位运算
___
#### 数组
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 位运算 | 前缀和 | 动态规划 |
| 双指针 | 排序 | 数学 |
| 数据库 | 数组 | 枚举 |
| 滑动窗口 | 矩阵 | 贪心 |
| 队列 |  |  |

# [3190. 使所有元素都可以被 3 整除的最少操作数](https://leetcode.cn/problems/find-minimum-operations-to-make-all-elements-divisible-by-three){#3190}

{{< tabs "3190" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        ans = 0
        for x in nums:
            if mod := x % 3:
                ans += min(mod, 3 - mod)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumOperations(int[] nums) {
        int ans = 0;
        for (int x : nums) {
            int mod = x % 3;
            if (mod != 0) {
                ans += Math.min(mod, 3 - mod);
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
    int minimumOperations(vector<int>& nums) {
        int ans = 0;
        for (int x : nums) {
            int mod = x % 3;
            if (mod) {
                ans += min(mod, 3 - mod);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumOperations(nums []int) (ans int) {
	for _, x := range nums {
		if mod := x % 3; mod > 0 {
			ans += min(mod, 3-mod)
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumOperations(nums: number[]): number {
    let ans = 0;
    for (const x of nums) {
        const mod = x % 3;
        if (mod) {
            ans += Math.min(mod, 3 - mod);
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

<p>给你一个整数数组&nbsp;<code>nums</code>&nbsp;。一次操作中，你可以将&nbsp;<code>nums</code>&nbsp;中的&nbsp;<strong>任意</strong>&nbsp;一个元素增加或者减少 1 。</p>

<p>请你返回将 <code>nums</code>&nbsp;中所有元素都可以被 3 整除的 <strong>最少</strong>&nbsp;操作次数。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [1,2,3,4]</span></p>

<p><span class="example-io"><b>输出：</b>3</span></p>

<p><strong>解释：</strong></p>

<p>通过以下 3 个操作，数组中的所有元素都可以被 3 整除：</p>

<ul>
	<li>将 1 减少 1 。</li>
	<li>将 2 增加 1 。</li>
	<li>将 4 减少 1 。</li>
</ul>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [3,6,9]</span></p>

<p><span class="example-io"><b>输出：</b>0</span></p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 50</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 50</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数学

我们直接遍历数组 $\textit{nums}$，对于每个元素 $x$，我们计算 $x$ 除以 3 的余数 $x \bmod 3$，如果余数不为 0，我们需要将 $x$ 变为能被 3 整除且操作次数最少，那么我们可以选择将 $x$ 减少 $x \bmod 3$ 或者增加 $3 - x \bmod 3$，取两者的最小值累加到答案中。

时间复杂度 $O(n)$，其中 $n$ 为数组 $\textit{nums}$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        ans = 0
        for x in nums:
            if mod := x % 3:
                ans += min(mod, 3 - mod)
        return ans
```

#### Java

```java
class Solution {
    public int minimumOperations(int[] nums) {
        int ans = 0;
        for (int x : nums) {
            int mod = x % 3;
            if (mod != 0) {
                ans += Math.min(mod, 3 - mod);
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
    int minimumOperations(vector<int>& nums) {
        int ans = 0;
        for (int x : nums) {
            int mod = x % 3;
            if (mod) {
                ans += min(mod, 3 - mod);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func minimumOperations(nums []int) (ans int) {
	for _, x := range nums {
		if mod := x % 3; mod > 0 {
			ans += min(mod, 3-mod)
		}
	}
	return
}
```

#### TypeScript

```ts
function minimumOperations(nums: number[]): number {
    let ans = 0;
    for (const x of nums) {
        const mod = x % 3;
        if (mod) {
            ans += Math.min(mod, 3 - mod);
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

# [3191. 使二进制数组全部等于 1 的最少操作次数 I](https://leetcode.cn/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i){#3191}

{{< tabs "3191" >}}

{{% tab "python" %}}
```python
class Solution:
    def minOperations(self, nums: List[int]) -> int:
        ans = 0
        for i, x in enumerate(nums):
            if x == 0:
                if i + 2 >= len(nums):
                    return -1
                nums[i + 1] ^= 1
                nums[i + 2] ^= 1
                ans += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minOperations(int[] nums) {
        int ans = 0;
        int n = nums.length;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                if (i + 2 >= n) {
                    return -1;
                }
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1;
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
    int minOperations(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                if (i + 2 >= n) {
                    return -1;
                }
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1;
                ++ans;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minOperations(nums []int) (ans int) {
	for i, x := range nums {
		if x == 0 {
			if i+2 >= len(nums) {
				return -1
			}
			nums[i+1] ^= 1
			nums[i+2] ^= 1
			ans++
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minOperations(nums: number[]): number {
    const n = nums.length;
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        if (nums[i] === 0) {
            if (i + 2 >= n) {
                return -1;
            }
            nums[i + 1] ^= 1;
            nums[i + 2] ^= 1;
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

<p>给你一个二进制数组&nbsp;<code>nums</code>&nbsp;。</p>

<p>你可以对数组执行以下操作 <strong>任意</strong>&nbsp;次（也可以 0 次）：</p>

<ul>
	<li>选择数组中 <strong>任意连续</strong>&nbsp;3 个元素，并将它们 <strong>全部反转</strong>&nbsp;。</li>
</ul>

<p><strong>反转</strong>&nbsp;一个元素指的是将它的值从 0 变 1 ，或者从 1 变 0 。</p>

<p>请你返回将 <code>nums</code>&nbsp;中所有元素变为 1 的 <strong>最少</strong>&nbsp;操作次数。如果无法全部变成 1 ，返回 -1 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [0,1,1,1,0,0]</span></p>

<p><span class="example-io"><b>输出：</b>3</span></p>

<p><strong>解释：</strong><br />
我们可以执行以下操作：</p>

<ul>
	<li>选择下标为 0 ，1 和 2 的元素并反转，得到&nbsp;<code>nums = [<u><strong>1</strong></u>,<u><strong>0</strong></u>,<u><strong>0</strong></u>,1,0,0]</code>&nbsp;。</li>
	<li>选择下标为 1 ，2 和 3 的元素并反转，得到&nbsp;<code>nums = [1,<u><strong>1</strong></u>,<u><strong>1</strong></u>,<strong><u>0</u></strong>,0,0]</code>&nbsp;。</li>
	<li>选择下标为 3 ，4 和 5 的元素并反转，得到&nbsp;<code>nums = [1,1,1,<strong><u>1</u></strong>,<u><strong>1</strong></u>,<u><strong>1</strong></u>]</code>&nbsp;。</li>
</ul>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [0,1,1,1]</span></p>

<p><span class="example-io"><b>输出：</b>-1</span></p>

<p><strong>解释：</strong><br />
无法将所有元素都变为 1 。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：顺序遍历 + 模拟

我们注意到，数组中的第一个为 $0$ 的位置，一定需要进行一次反转操作，否则无法将其变为 $1$。因此，我们可以顺序遍历数组，每次遇到 $0$，就将其后两个元素进行反转操作，累计一次操作次数。

遍历结束后，返回答案即可。

时间复杂度 $O(n)$，其中 $n$ 为数组 $\textit{nums}$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minOperations(self, nums: List[int]) -> int:
        ans = 0
        for i, x in enumerate(nums):
            if x == 0:
                if i + 2 >= len(nums):
                    return -1
                nums[i + 1] ^= 1
                nums[i + 2] ^= 1
                ans += 1
        return ans
```

#### Java

```java
class Solution {
    public int minOperations(int[] nums) {
        int ans = 0;
        int n = nums.length;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                if (i + 2 >= n) {
                    return -1;
                }
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1;
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
    int minOperations(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                if (i + 2 >= n) {
                    return -1;
                }
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1;
                ++ans;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func minOperations(nums []int) (ans int) {
	for i, x := range nums {
		if x == 0 {
			if i+2 >= len(nums) {
				return -1
			}
			nums[i+1] ^= 1
			nums[i+2] ^= 1
			ans++
		}
	}
	return
}
```

#### TypeScript

```ts
function minOperations(nums: number[]): number {
    const n = nums.length;
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        if (nums[i] === 0) {
            if (i + 2 >= n) {
                return -1;
            }
            nums[i + 1] ^= 1;
            nums[i + 2] ^= 1;
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

# [3192. 使二进制数组全部等于 1 的最少操作次数 II](https://leetcode.cn/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-ii){#3192}

{{< tabs "3192" >}}

{{% tab "python" %}}
```python
class Solution:
    def minOperations(self, nums: List[int]) -> int:
        ans = v = 0
        for x in nums:
            x ^= v
            if x == 0:
                ans += 1
                v ^= 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minOperations(int[] nums) {
        int ans = 0, v = 0;
        for (int x : nums) {
            x ^= v;
            if (x == 0) {
                v ^= 1;
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
    int minOperations(vector<int>& nums) {
        int ans = 0, v = 0;
        for (int x : nums) {
            x ^= v;
            if (x == 0) {
                v ^= 1;
                ++ans;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minOperations(nums []int) (ans int) {
	v := 0
	for _, x := range nums {
		x ^= v
		if x == 0 {
			v ^= 1
			ans++
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minOperations(nums: number[]): number {
    let [ans, v] = [0, 0];
    for (let x of nums) {
        x ^= v;
        if (x === 0) {
            v ^= 1;
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

<p>给你一个二进制数组&nbsp;<code>nums</code>&nbsp;。</p>

<p>你可以对数组执行以下操作&nbsp;<strong>任意</strong>&nbsp;次（也可以 0 次）：</p>

<ul>
	<li>选择数组中 <strong>任意</strong>&nbsp;一个下标 <code>i</code>&nbsp;，并将从下标 <code>i</code>&nbsp;开始一直到数组末尾 <strong>所有</strong>&nbsp;元素 <strong>反转</strong>&nbsp;。</li>
</ul>

<p><b>反转</b>&nbsp;一个元素指的是将它的值从 0 变 1 ，或者从 1 变 0 。</p>

<p>请你返回将 <code>nums</code>&nbsp;中所有元素变为 1 的 <strong>最少</strong>&nbsp;操作次数。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [0,1,1,0,1]</span></p>

<p><span class="example-io"><b>输出：</b>4</span></p>

<p><strong>解释：</strong><br />
我们可以执行以下操作：</p>

<ul>
	<li>选择下标&nbsp;<code>i = 1</code>&nbsp;执行操作，得到<span class="example-io">&nbsp;<code>nums = [0,<u><strong>0</strong></u>,<u><strong>0</strong></u>,<u><strong>1</strong></u>,<u><strong>0</strong></u>]</code>&nbsp;。</span></li>
	<li>选择下标&nbsp;<code>i = 0</code>&nbsp;执行操作，得到<span class="example-io">&nbsp;<code>nums = [<u><strong>1</strong></u>,<u><strong>1</strong></u>,<u><strong>1</strong></u>,<u><strong>0</strong></u>,<u><strong>1</strong></u>]</code>&nbsp;。</span></li>
	<li>选择下标&nbsp;<code>i = 4</code>&nbsp;执行操作，得到<span class="example-io">&nbsp;<code>nums = [1,1,1,0,<u><strong>0</strong></u>]</code>&nbsp;。</span></li>
	<li>选择下标&nbsp;<code>i = 3</code>&nbsp;执行操作，得到<span class="example-io">&nbsp;<code>nums = [1,1,1,<u><strong>1</strong></u>,<u><strong>1</strong></u>]</code>&nbsp;。</span></li>
</ul>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [1,0,0,0]</span></p>

<p><span class="example-io"><b>输出：</b>1</span></p>

<p><strong>解释：</strong><br />
我们可以执行以下操作：</p>

<ul>
	<li>选择下标&nbsp;<code>i = 1</code>&nbsp;执行操作，得到<span class="example-io">&nbsp;<code>nums = [1,<u><strong>1</strong></u>,<u><strong>1</strong></u>,<u><strong>1</strong></u>]</code>&nbsp;。</span></li>
</ul>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

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

### 方法一：位运算

我们注意到，每当我们将某个位置的元素变为 1 时，它的右侧的所有元素都会被反转。因此，我们可以用一个变量 $v$ 来记录当前位置及其右侧的元素是否被反转，如果被反转，那么 $v$ 的值为 1，否则为 0。

我们遍历数组 $\textit{nums}$，对于每个元素 $x$，我们将 $x$ 与 $v$ 进行异或运算，如果 $x$ 为 0，那么我们需要将 $x$ 变为 1，我们需要进行反转操作，我们将答案加一，并将 $v$ 取反。

遍历结束后，我们就可以得到最少操作次数。

时间复杂度 $O(n)$，其中 $n$ 为数组 $\textit{nums}$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minOperations(self, nums: List[int]) -> int:
        ans = v = 0
        for x in nums:
            x ^= v
            if x == 0:
                ans += 1
                v ^= 1
        return ans
```

#### Java

```java
class Solution {
    public int minOperations(int[] nums) {
        int ans = 0, v = 0;
        for (int x : nums) {
            x ^= v;
            if (x == 0) {
                v ^= 1;
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
    int minOperations(vector<int>& nums) {
        int ans = 0, v = 0;
        for (int x : nums) {
            x ^= v;
            if (x == 0) {
                v ^= 1;
                ++ans;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func minOperations(nums []int) (ans int) {
	v := 0
	for _, x := range nums {
		x ^= v
		if x == 0 {
			v ^= 1
			ans++
		}
	}
	return
}
```

#### TypeScript

```ts
function minOperations(nums: number[]): number {
    let [ans, v] = [0, 0];
    for (let x of nums) {
        x ^= v;
        if (x === 0) {
            v ^= 1;
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

# [3193. 统计逆序对的数目](https://leetcode.cn/problems/count-the-number-of-inversions){#3193}

{{< tabs "3193" >}}

{{% tab "python" %}}
```python
class Solution:
    def numberOfPermutations(self, n: int, requirements: List[List[int]]) -> int:
        req = [-1] * n
        for end, cnt in requirements:
            req[end] = cnt
        if req[0] > 0:
            return 0
        req[0] = 0
        mod = 10**9 + 7
        m = max(req)
        f = [[0] * (m + 1) for _ in range(n)]
        f[0][0] = 1
        for i in range(1, n):
            l, r = 0, m
            if req[i] >= 0:
                l = r = req[i]
            for j in range(l, r + 1):
                for k in range(min(i, j) + 1):
                    f[i][j] = (f[i][j] + f[i - 1][j - k]) % mod
        return f[n - 1][req[n - 1]]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numberOfPermutations(int n, int[][] requirements) {
        int[] req = new int[n];
        Arrays.fill(req, -1);
        int m = 0;
        for (var r : requirements) {
            req[r[0]] = r[1];
            m = Math.max(m, r[1]);
        }
        if (req[0] > 0) {
            return 0;
        }
        req[0] = 0;
        final int mod = (int) 1e9 + 7;
        int[][] f = new int[n][m + 1];
        f[0][0] = 1;
        for (int i = 1; i < n; ++i) {
            int l = 0, r = m;
            if (req[i] >= 0) {
                l = r = req[i];
            }
            for (int j = l; j <= r; ++j) {
                for (int k = 0; k <= Math.min(i, j); ++k) {
                    f[i][j] = (f[i][j] + f[i - 1][j - k]) % mod;
                }
            }
        }
        return f[n - 1][req[n - 1]];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        vector<int> req(n, -1);
        int m = 0;
        for (const auto& r : requirements) {
            req[r[0]] = r[1];
            m = max(m, r[1]);
        }
        if (req[0] > 0) {
            return 0;
        }
        req[0] = 0;
        const int mod = 1e9 + 7;
        vector<vector<int>> f(n, vector<int>(m + 1, 0));
        f[0][0] = 1;
        for (int i = 1; i < n; ++i) {
            int l = 0, r = m;
            if (req[i] >= 0) {
                l = r = req[i];
            }
            for (int j = l; j <= r; ++j) {
                for (int k = 0; k <= min(i, j); ++k) {
                    f[i][j] = (f[i][j] + f[i - 1][j - k]) % mod;
                }
            }
        }
        return f[n - 1][req[n - 1]];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numberOfPermutations(n int, requirements [][]int) int {
	req := make([]int, n)
	for i := range req {
		req[i] = -1
	}
	for _, r := range requirements {
		req[r[0]] = r[1]
	}
	if req[0] > 0 {
		return 0
	}
	req[0] = 0
	m := slices.Max(req)
	const mod = int(1e9 + 7)
	f := make([][]int, n)
	for i := range f {
		f[i] = make([]int, m+1)
	}
	f[0][0] = 1
	for i := 1; i < n; i++ {
		l, r := 0, m
		if req[i] >= 0 {
			l, r = req[i], req[i]
		}
		for j := l; j <= r; j++ {
			for k := 0; k <= min(i, j); k++ {
				f[i][j] = (f[i][j] + f[i-1][j-k]) % mod
			}
		}
	}
	return f[n-1][req[n-1]]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numberOfPermutations(n: number, requirements: number[][]): number {
    const req: number[] = Array(n).fill(-1);
    for (const [end, cnt] of requirements) {
        req[end] = cnt;
    }
    if (req[0] > 0) {
        return 0;
    }
    req[0] = 0;
    const m = Math.max(...req);
    const mod = 1e9 + 7;
    const f = Array.from({ length: n }, () => Array(m + 1).fill(0));
    f[0][0] = 1;
    for (let i = 1; i < n; ++i) {
        let [l, r] = [0, m];
        if (req[i] >= 0) {
            l = r = req[i];
        }
        for (let j = l; j <= r; ++j) {
            for (let k = 0; k <= Math.min(i, j); ++k) {
                f[i][j] = (f[i][j] + f[i - 1][j - k]) % mod;
            }
        }
    }
    return f[n - 1][req[n - 1]];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数&nbsp;<code>n</code>&nbsp;和一个二维数组&nbsp;<code>requirements</code>&nbsp;，其中&nbsp;<code>requirements[i] = [end<sub>i</sub>, cnt<sub>i</sub>]</code> <span class="text-only" data-eleid="10" style="white-space: pre;">表示这个要求中的末尾下标和 <strong>逆序对</strong> 的数目。</span></p>

<p>整数数组 <code>nums</code>&nbsp;中一个下标对&nbsp;<code>(i, j)</code>&nbsp;如果满足以下条件，那么它们被称为一个 <strong>逆序对</strong>&nbsp;：</p>

<ul>
	<li><code>i &lt; j</code>&nbsp;且&nbsp;<code>nums[i] &gt; nums[j]</code></li>
</ul>

<p>请你返回&nbsp;<code>[0, 1, 2, ..., n - 1]</code>&nbsp;的&nbsp;<span data-keyword="permutation">排列</span> <code>perm</code>&nbsp;的数目，满足对 <strong>所有</strong>&nbsp;的&nbsp;<code>requirements[i]</code>&nbsp;都满足&nbsp;<code>perm[0..end<sub>i</sub>]</code>&nbsp;中恰好有&nbsp;<code>cnt<sub>i</sub></code>&nbsp;个逆序对。</p>

<p>由于答案可能会很大，将它对&nbsp;<code>10<sup>9</sup> + 7</code>&nbsp;<strong>取余</strong>&nbsp;后返回。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>n = 3, requirements = [[2,2],[0,0]]</span></p>

<p><span class="example-io"><b>输出：</b>2</span></p>

<p><strong>解释：</strong></p>

<p>两个排列为：</p>

<ul>
	<li><code>[2, 0, 1]</code>

    <ul>
    	<li>前缀&nbsp;<code>[2, 0, 1]</code>&nbsp;的逆序对为&nbsp;<code>(0, 1)</code> 和&nbsp;<code>(0, 2)</code>&nbsp;。</li>
    	<li>前缀&nbsp;<code>[2]</code>&nbsp;的逆序对数目为 0 个。</li>
    </ul>
    </li>
    <li><code>[1, 2, 0]</code>
    <ul>
    	<li>前缀&nbsp;<code>[1, 2, 0]</code>&nbsp;的逆序对为&nbsp;<code>(0, 2)</code> 和&nbsp;<code>(1, 2)</code>&nbsp;。</li>
    	<li>前缀&nbsp;<code>[1]</code>&nbsp;的逆序对数目为 0 个。</li>
    </ul>
    </li>

</ul>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>n = 3, requirements = [[2,2],[1,1],[0,0]]</span></p>

<p><b>输出：</b>1</p>

<p><strong>解释：</strong></p>

<p>唯一满足要求的排列是&nbsp;<code>[2, 0, 1]</code>&nbsp;：</p>

<ul>
	<li>前缀&nbsp;<code>[2, 0, 1]</code>&nbsp;的逆序对为&nbsp;<code>(0, 1)</code> 和&nbsp;<code>(0, 2)</code>&nbsp;。</li>
	<li>前缀&nbsp;<code>[2, 0]</code>&nbsp;的逆序对为&nbsp;<code>(0, 1)</code>&nbsp;。</li>
	<li>前缀&nbsp;<code>[2]</code>&nbsp;的逆序对数目为 0 。</li>
</ul>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>n = 2, requirements = [[0,0],[1,0]]</span></p>

<p><span class="example-io"><b>输出：</b>1</span></p>

<p><b>解释：</b></p>

<p>唯一满足要求的排列为&nbsp;<code>[0, 1]</code>&nbsp;：</p>

<ul>
	<li>前缀&nbsp;<code>[0]</code>&nbsp;的逆序对数目为 0 。</li>
	<li>前缀&nbsp;<code>[0, 1]</code>&nbsp;的逆序对为&nbsp;<code>(0, 1)</code>&nbsp;。</li>
</ul>
</div>

<div id="gtx-trans" style="position: absolute; left: 198px; top: 756px;">
<div class="gtx-trans-icon">&nbsp;</div>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 300</code></li>
	<li><code>1 &lt;= requirements.length &lt;= n</code></li>
	<li><code>requirements[i] = [end<sub>i</sub>, cnt<sub>i</sub>]</code></li>
	<li><code>0 &lt;= end<sub>i</sub> &lt;= n - 1</code></li>
	<li><code>0 &lt;= cnt<sub>i</sub> &lt;= 400</code></li>
	<li>输入保证至少有一个&nbsp;<code>i</code>&nbsp;满足&nbsp;<code>end<sub>i</sub> == n - 1</code>&nbsp;。</li>
	<li>输入保证所有的&nbsp;<code>end<sub>i</sub></code>&nbsp;互不相同。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i][j]$ 表示 $[0..i]$ 的排列中，逆序对数量为 $j$ 的排列数。考虑下标为 $i$ 的数 $a_i$ 与前面 $i$ 个数的大小关系。如果 $a_i$ 比前面 $k$ 个数小，那么前面的 $k$ 个数与 $a_i$ 都构成了逆序对，逆序对数量为 $k$。因此，我们可以得到状态转移方程：

$$
f[i][j] = \sum_{k=0}^{\min(i, j)} f[i-1][j-k]
$$

由于题目要求 $[0..\textit{end}_i]$ 的逆序对数量为 $\textit{cnt}_i$，因此，当我们计算 $i = \textit{end}_i$ 时，我们只需要计算 $f[i][\textit{cnt}_i]$ 即可。其余的 $f[i][..]$ 都为 $0$。

时间复杂度 $O(n \times m \times \min(n, m))$，空间复杂度 $O(n \times m)$。其中 $m$ 是逆序对数量的最大值。本题中 $m \le 400$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numberOfPermutations(self, n: int, requirements: List[List[int]]) -> int:
        req = [-1] * n
        for end, cnt in requirements:
            req[end] = cnt
        if req[0] > 0:
            return 0
        req[0] = 0
        mod = 10**9 + 7
        m = max(req)
        f = [[0] * (m + 1) for _ in range(n)]
        f[0][0] = 1
        for i in range(1, n):
            l, r = 0, m
            if req[i] >= 0:
                l = r = req[i]
            for j in range(l, r + 1):
                for k in range(min(i, j) + 1):
                    f[i][j] = (f[i][j] + f[i - 1][j - k]) % mod
        return f[n - 1][req[n - 1]]
```

#### Java

```java
class Solution {
    public int numberOfPermutations(int n, int[][] requirements) {
        int[] req = new int[n];
        Arrays.fill(req, -1);
        int m = 0;
        for (var r : requirements) {
            req[r[0]] = r[1];
            m = Math.max(m, r[1]);
        }
        if (req[0] > 0) {
            return 0;
        }
        req[0] = 0;
        final int mod = (int) 1e9 + 7;
        int[][] f = new int[n][m + 1];
        f[0][0] = 1;
        for (int i = 1; i < n; ++i) {
            int l = 0, r = m;
            if (req[i] >= 0) {
                l = r = req[i];
            }
            for (int j = l; j <= r; ++j) {
                for (int k = 0; k <= Math.min(i, j); ++k) {
                    f[i][j] = (f[i][j] + f[i - 1][j - k]) % mod;
                }
            }
        }
        return f[n - 1][req[n - 1]];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        vector<int> req(n, -1);
        int m = 0;
        for (const auto& r : requirements) {
            req[r[0]] = r[1];
            m = max(m, r[1]);
        }
        if (req[0] > 0) {
            return 0;
        }
        req[0] = 0;
        const int mod = 1e9 + 7;
        vector<vector<int>> f(n, vector<int>(m + 1, 0));
        f[0][0] = 1;
        for (int i = 1; i < n; ++i) {
            int l = 0, r = m;
            if (req[i] >= 0) {
                l = r = req[i];
            }
            for (int j = l; j <= r; ++j) {
                for (int k = 0; k <= min(i, j); ++k) {
                    f[i][j] = (f[i][j] + f[i - 1][j - k]) % mod;
                }
            }
        }
        return f[n - 1][req[n - 1]];
    }
};
```

#### Go

```go
func numberOfPermutations(n int, requirements [][]int) int {
	req := make([]int, n)
	for i := range req {
		req[i] = -1
	}
	for _, r := range requirements {
		req[r[0]] = r[1]
	}
	if req[0] > 0 {
		return 0
	}
	req[0] = 0
	m := slices.Max(req)
	const mod = int(1e9 + 7)
	f := make([][]int, n)
	for i := range f {
		f[i] = make([]int, m+1)
	}
	f[0][0] = 1
	for i := 1; i < n; i++ {
		l, r := 0, m
		if req[i] >= 0 {
			l, r = req[i], req[i]
		}
		for j := l; j <= r; j++ {
			for k := 0; k <= min(i, j); k++ {
				f[i][j] = (f[i][j] + f[i-1][j-k]) % mod
			}
		}
	}
	return f[n-1][req[n-1]]
}
```

#### TypeScript

```ts
function numberOfPermutations(n: number, requirements: number[][]): number {
    const req: number[] = Array(n).fill(-1);
    for (const [end, cnt] of requirements) {
        req[end] = cnt;
    }
    if (req[0] > 0) {
        return 0;
    }
    req[0] = 0;
    const m = Math.max(...req);
    const mod = 1e9 + 7;
    const f = Array.from({ length: n }, () => Array(m + 1).fill(0));
    f[0][0] = 1;
    for (let i = 1; i < n; ++i) {
        let [l, r] = [0, m];
        if (req[i] >= 0) {
            l = r = req[i];
        }
        for (let j = l; j <= r; ++j) {
            for (let k = 0; k <= Math.min(i, j); ++k) {
                f[i][j] = (f[i][j] + f[i - 1][j - k]) % mod;
            }
        }
    }
    return f[n - 1][req[n - 1]];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3194. 最小元素和最大元素的最小平均值](https://leetcode.cn/problems/minimum-average-of-smallest-and-largest-elements){#3194}

{{< tabs "3194" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumAverage(self, nums: List[int]) -> float:
        nums.sort()
        n = len(nums)
        return min(nums[i] + nums[-i - 1] for i in range(n // 2)) / 2
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public double minimumAverage(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        int ans = 1 << 30;
        for (int i = 0; i < n / 2; ++i) {
            ans = Math.min(ans, nums[i] + nums[n - i - 1]);
        }
        return ans / 2.0;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 1 << 30, n = nums.size();
        for (int i = 0; i < n; ++i) {
            ans = min(ans, nums[i] + nums[n - i - 1]);
        }
        return ans / 2.0;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumAverage(nums []int) float64 {
	sort.Ints(nums)
	n := len(nums)
	ans := 1 << 30
	for i, x := range nums[:n/2] {
		ans = min(ans, x+nums[n-i-1])
	}
	return float64(ans) / 2
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumAverage(nums: number[]): number {
    nums.sort((a, b) => a - b);
    const n = nums.length;
    let ans = Infinity;
    for (let i = 0; i * 2 < n; ++i) {
        ans = Math.min(ans, nums[i] + nums[n - 1 - i]);
    }
    return ans / 2;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn minimum_average(mut nums: Vec<i32>) -> f64 {
        nums.sort();
        let n = nums.len();
        let ans = (0..n / 2).map(|i| nums[i] + nums[n - i - 1]).min().unwrap();
        ans as f64 / 2.0
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你有一个初始为空的浮点数数组 <code>averages</code>。另给你一个包含 <code>n</code> 个整数的数组 <code>nums</code>，其中 <code>n</code> 为偶数。</p>

<p>你需要重复以下步骤 <code>n / 2</code> 次：</p>

<ul>
	<li>从 <code>nums</code> 中移除<strong> 最小 </strong>的元素 <code>minElement</code> 和<strong> 最大 </strong>的元素 <code>maxElement</code>。</li>
	<li>将 <code>(minElement + maxElement) / 2</code> 加入到 <code>averages</code> 中。</li>
</ul>

<p>返回 <code>averages</code> 中的 <strong>最小 </strong>元素。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">nums = [7,8,3,4,15,13,4,1]</span></p>

<p><strong>输出：</strong> <span class="example-io">5.5</span></p>

<p><strong>解释：</strong></p>

<table>
	<tbody>
		<tr>
			<th>步骤</th>
			<th>nums</th>
			<th>averages</th>
		</tr>
		<tr>
			<td>0</td>
			<td>[7,8,3,4,15,13,4,1]</td>
			<td>[]</td>
		</tr>
		<tr>
			<td>1</td>
			<td>[7,8,3,4,13,4]</td>
			<td>[8]</td>
		</tr>
		<tr>
			<td>2</td>
			<td>[7,8,4,4]</td>
			<td>[8,8]</td>
		</tr>
		<tr>
			<td>3</td>
			<td>[7,4]</td>
			<td>[8,8,6]</td>
		</tr>
		<tr>
			<td>4</td>
			<td>[]</td>
			<td>[8,8,6,5.5]</td>
		</tr>
	</tbody>
</table>
返回 averages 中最小的元素，即 5.5。</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">nums = [1,9,8,3,10,5]</span></p>

<p><strong>输出：</strong> <span class="example-io">5.5</span></p>

<p><strong>解释：</strong></p>

<table>
	<tbody>
		<tr>
			<th>步骤</th>
			<th>nums</th>
			<th>averages</th>
		</tr>
		<tr>
			<td>0</td>
			<td>[1,9,8,3,10,5]</td>
			<td>[]</td>
		</tr>
		<tr>
			<td>1</td>
			<td>[9,8,3,5]</td>
			<td>[5.5]</td>
		</tr>
		<tr>
			<td>2</td>
			<td>[8,5]</td>
			<td>[5.5,6]</td>
		</tr>
		<tr>
			<td>3</td>
			<td>[]</td>
			<td>[5.5,6,6.5]</td>
		</tr>
	</tbody>
</table>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">nums = [1,2,3,7,8,9]</span></p>

<p><strong>输出：</strong> <span class="example-io">5.0</span></p>

<p><strong>解释：</strong></p>

<table>
	<tbody>
		<tr>
			<th>步骤</th>
			<th>nums</th>
			<th>averages</th>
		</tr>
		<tr>
			<td>0</td>
			<td>[1,2,3,7,8,9]</td>
			<td>[]</td>
		</tr>
		<tr>
			<td>1</td>
			<td>[2,3,7,8]</td>
			<td>[5]</td>
		</tr>
		<tr>
			<td>2</td>
			<td>[3,7]</td>
			<td>[5,5]</td>
		</tr>
		<tr>
			<td>3</td>
			<td>[]</td>
			<td>[5,5,5]</td>
		</tr>
	</tbody>
</table>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n == nums.length &lt;= 50</code></li>
	<li><code>n</code> 为偶数。</li>
	<li><code>1 &lt;= nums[i] &lt;= 50</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序

我们首先对数组 $\textit{nums}$ 进行排序，然后从数组的两端开始取元素，分别计算两个元素的和，取最小值。最后将最小值除以 2 作为答案返回即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 为数组 $\textit{nums}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumAverage(self, nums: List[int]) -> float:
        nums.sort()
        n = len(nums)
        return min(nums[i] + nums[-i - 1] for i in range(n // 2)) / 2
```

#### Java

```java
class Solution {
    public double minimumAverage(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        int ans = 1 << 30;
        for (int i = 0; i < n / 2; ++i) {
            ans = Math.min(ans, nums[i] + nums[n - i - 1]);
        }
        return ans / 2.0;
    }
}
```

#### C++

```cpp
class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 1 << 30, n = nums.size();
        for (int i = 0; i < n; ++i) {
            ans = min(ans, nums[i] + nums[n - i - 1]);
        }
        return ans / 2.0;
    }
};
```

#### Go

```go
func minimumAverage(nums []int) float64 {
	sort.Ints(nums)
	n := len(nums)
	ans := 1 << 30
	for i, x := range nums[:n/2] {
		ans = min(ans, x+nums[n-i-1])
	}
	return float64(ans) / 2
}
```

#### TypeScript

```ts
function minimumAverage(nums: number[]): number {
    nums.sort((a, b) => a - b);
    const n = nums.length;
    let ans = Infinity;
    for (let i = 0; i * 2 < n; ++i) {
        ans = Math.min(ans, nums[i] + nums[n - 1 - i]);
    }
    return ans / 2;
}
```

#### Rust

```rust
impl Solution {
    pub fn minimum_average(mut nums: Vec<i32>) -> f64 {
        nums.sort();
        let n = nums.len();
        let ans = (0..n / 2).map(|i| nums[i] + nums[n - i - 1]).min().unwrap();
        ans as f64 / 2.0
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3195. 包含所有 1 的最小矩形面积 I](https://leetcode.cn/problems/find-the-minimum-area-to-cover-all-ones-i){#3195}

{{< tabs "3195" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumArea(self, grid: List[List[int]]) -> int:
        x1 = y1 = inf
        x2 = y2 = -inf
        for i, row in enumerate(grid):
            for j, x in enumerate(row):
                if x == 1:
                    x1 = min(x1, i)
                    y1 = min(y1, j)
                    x2 = max(x2, i)
                    y2 = max(y2, j)
        return (x2 - x1 + 1) * (y2 - y1 + 1)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumArea(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int x1 = m, y1 = n;
        int x2 = 0, y2 = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    x1 = Math.min(x1, i);
                    y1 = Math.min(y1, j);
                    x2 = Math.max(x2, i);
                    y2 = Math.max(y2, j);
                }
            }
        }
        return (x2 - x1 + 1) * (y2 - y1 + 1);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int x1 = m, y1 = n;
        int x2 = 0, y2 = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    x1 = min(x1, i);
                    y1 = min(y1, j);
                    x2 = max(x2, i);
                    y2 = max(y2, j);
                }
            }
        }
        return (x2 - x1 + 1) * (y2 - y1 + 1);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumArea(grid [][]int) int {
	x1, y1 := len(grid), len(grid[0])
	x2, y2 := 0, 0
	for i, row := range grid {
		for j, x := range row {
			if x == 1 {
				x1, y1 = min(x1, i), min(y1, j)
				x2, y2 = max(x2, i), max(y2, j)
			}
		}
	}
	return (x2 - x1 + 1) * (y2 - y1 + 1)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumArea(grid: number[][]): number {
    const [m, n] = [grid.length, grid[0].length];
    let [x1, y1] = [m, n];
    let [x2, y2] = [0, 0];
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            if (grid[i][j] === 1) {
                x1 = Math.min(x1, i);
                y1 = Math.min(y1, j);
                x2 = Math.max(x2, i);
                y2 = Math.max(y2, j);
            }
        }
    }
    return (x2 - x1 + 1) * (y2 - y1 + 1);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn minimum_area(grid: Vec<Vec<i32>>) -> i32 {
        let m = grid.len();
        let n = grid[0].len();
        let mut x1 = m as i32;
        let mut y1 = n as i32;
        let mut x2 = 0i32;
        let mut y2 = 0i32;

        for i in 0..m {
            for j in 0..n {
                if grid[i][j] == 1 {
                    x1 = x1.min(i as i32);
                    y1 = y1.min(j as i32);
                    x2 = x2.max(i as i32);
                    y2 = y2.max(j as i32);
                }
            }
        }

        (x2 - x1 + 1) * (y2 - y1 + 1)
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[][]} grid
 * @return {number}
 */
var minimumArea = function (grid) {
    const [m, n] = [grid.length, grid[0].length];
    let [x1, y1] = [m, n];
    let [x2, y2] = [0, 0];
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            if (grid[i][j] === 1) {
                x1 = Math.min(x1, i);
                y1 = Math.min(y1, j);
                x2 = Math.max(x2, i);
                y2 = Math.max(y2, j);
            }
        }
    }
    return (x2 - x1 + 1) * (y2 - y1 + 1);
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int MinimumArea(int[][] grid) {
        int m = grid.Length, n = grid[0].Length;
        int x1 = m, y1 = n;
        int x2 = 0, y2 = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    x1 = Math.Min(x1, i);
                    y1 = Math.Min(y1, j);
                    x2 = Math.Max(x2, i);
                    y2 = Math.Max(y2, j);
                }
            }
        }

        return (x2 - x1 + 1) * (y2 - y1 + 1);
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个二维 <strong>二进制 </strong>数组 <code>grid</code>。请你找出一个边在水平方向和竖直方向上、面积 <strong>最小</strong> 的矩形，并且满足 <code>grid</code> 中所有的 1 都在矩形的内部。</p>

<p>返回这个矩形可能的 <strong>最小 </strong>面积。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">grid = [[0,1,0],[1,0,1]]</span></p>

<p><strong>输出：</strong> <span class="example-io">6</span></p>

<p><strong>解释：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3100-3199/3195.Find%20the%20Minimum%20Area%20to%20Cover%20All%20Ones%20I/images/examplerect0.png" style="padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem; width: 279px; height: 198px;" /></p>

<p>这个最小矩形的高度为 2，宽度为 3，因此面积为 <code>2 * 3 = 6</code>。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">grid = [[0,0],[1,0]]</span></p>

<p><strong>输出：</strong> <span class="example-io">1</span></p>

<p><strong>解释：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3100-3199/3195.Find%20the%20Minimum%20Area%20to%20Cover%20All%20Ones%20I/images/examplerect1.png" style="padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem; width: 204px; height: 201px;" /></p>

<p>这个最小矩形的高度和宽度都是 1，因此面积为 <code>1 * 1 = 1</code>。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= grid.length, grid[i].length &lt;= 1000</code></li>
	<li><code>grid[i][j]</code> 是 0 或 1。</li>
	<li>输入保证 <code>grid</code> 中至少有一个 1 。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：求最小边界和最大边界

我们可以遍历 `grid`，找到所有 `1` 的最小边界，记为 $(x_1, y_1)$，最大边界，记为 $(x_2, y_2)$，那么最小矩形的面积就是 $(x_2 - x_1 + 1) \times (y_2 - y_1 + 1)$。

时间复杂度 $O(m \times n)$，其中 $m$ 和 $n$ 分别是 `grid` 的行数和列数。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumArea(self, grid: List[List[int]]) -> int:
        x1 = y1 = inf
        x2 = y2 = -inf
        for i, row in enumerate(grid):
            for j, x in enumerate(row):
                if x == 1:
                    x1 = min(x1, i)
                    y1 = min(y1, j)
                    x2 = max(x2, i)
                    y2 = max(y2, j)
        return (x2 - x1 + 1) * (y2 - y1 + 1)
```

#### Java

```java
class Solution {
    public int minimumArea(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int x1 = m, y1 = n;
        int x2 = 0, y2 = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    x1 = Math.min(x1, i);
                    y1 = Math.min(y1, j);
                    x2 = Math.max(x2, i);
                    y2 = Math.max(y2, j);
                }
            }
        }
        return (x2 - x1 + 1) * (y2 - y1 + 1);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int x1 = m, y1 = n;
        int x2 = 0, y2 = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    x1 = min(x1, i);
                    y1 = min(y1, j);
                    x2 = max(x2, i);
                    y2 = max(y2, j);
                }
            }
        }
        return (x2 - x1 + 1) * (y2 - y1 + 1);
    }
};
```

#### Go

```go
func minimumArea(grid [][]int) int {
	x1, y1 := len(grid), len(grid[0])
	x2, y2 := 0, 0
	for i, row := range grid {
		for j, x := range row {
			if x == 1 {
				x1, y1 = min(x1, i), min(y1, j)
				x2, y2 = max(x2, i), max(y2, j)
			}
		}
	}
	return (x2 - x1 + 1) * (y2 - y1 + 1)
}
```

#### TypeScript

```ts
function minimumArea(grid: number[][]): number {
    const [m, n] = [grid.length, grid[0].length];
    let [x1, y1] = [m, n];
    let [x2, y2] = [0, 0];
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            if (grid[i][j] === 1) {
                x1 = Math.min(x1, i);
                y1 = Math.min(y1, j);
                x2 = Math.max(x2, i);
                y2 = Math.max(y2, j);
            }
        }
    }
    return (x2 - x1 + 1) * (y2 - y1 + 1);
}
```

#### Rust

```rust
impl Solution {
    pub fn minimum_area(grid: Vec<Vec<i32>>) -> i32 {
        let m = grid.len();
        let n = grid[0].len();
        let mut x1 = m as i32;
        let mut y1 = n as i32;
        let mut x2 = 0i32;
        let mut y2 = 0i32;

        for i in 0..m {
            for j in 0..n {
                if grid[i][j] == 1 {
                    x1 = x1.min(i as i32);
                    y1 = y1.min(j as i32);
                    x2 = x2.max(i as i32);
                    y2 = y2.max(j as i32);
                }
            }
        }

        (x2 - x1 + 1) * (y2 - y1 + 1)
    }
}
```

#### JavaScript

```js
/**
 * @param {number[][]} grid
 * @return {number}
 */
var minimumArea = function (grid) {
    const [m, n] = [grid.length, grid[0].length];
    let [x1, y1] = [m, n];
    let [x2, y2] = [0, 0];
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            if (grid[i][j] === 1) {
                x1 = Math.min(x1, i);
                y1 = Math.min(y1, j);
                x2 = Math.max(x2, i);
                y2 = Math.max(y2, j);
            }
        }
    }
    return (x2 - x1 + 1) * (y2 - y1 + 1);
};
```

#### C#

```cs
public class Solution {
    public int MinimumArea(int[][] grid) {
        int m = grid.Length, n = grid[0].Length;
        int x1 = m, y1 = n;
        int x2 = 0, y2 = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    x1 = Math.Min(x1, i);
                    y1 = Math.Min(y1, j);
                    x2 = Math.Max(x2, i);
                    y2 = Math.Max(y2, j);
                }
            }
        }

        return (x2 - x1 + 1) * (y2 - y1 + 1);
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3196. 最大化子数组的总成本](https://leetcode.cn/problems/maximize-total-cost-of-alternating-subarrays){#3196}

{{< tabs "3196" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumTotalCost(self, nums: List[int]) -> int:
        f, g = -inf, 0
        for x in nums:
            f, g = max(f, g) + x, f - x
        return max(f, g)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long maximumTotalCost(int[] nums) {
        long f = Long.MIN_VALUE / 2, g = 0;
        for (int x : nums) {
            long ff = Math.max(f, g) + x;
            long gg = f - x;
            f = ff;
            g = gg;
        }
        return Math.max(f, g);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    long long maximumTotalCost(vector<int>& nums) {
        long long f = LLONG_MIN / 2, g = 0;
        for (int x : nums) {
            long long ff = max(f, g) + x, gg = f - x;
            f = ff;
            g = gg;
        }
        return max(f, g);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumTotalCost(nums []int) int64 {
	f, g := math.MinInt64/2, 0
	for _, x := range nums {
		f, g = max(f, g)+x, f-x
	}
	return int64(max(f, g))
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumTotalCost(nums: number[]): number {
    let [f, g] = [-Infinity, 0];
    for (const x of nums) {
        [f, g] = [Math.max(f, g) + x, f - x];
    }
    return Math.max(f, g);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个长度为 <code>n</code> 的整数数组 <code>nums</code>。</p>

<p>子数组 <code>nums[l..r]</code>（其中 <code>0 &lt;= l &lt;= r &lt; n</code>）的 <strong>成本 </strong>定义为：</p>

<p><code>cost(l, r) = nums[l] - nums[l + 1] + ... + nums[r] * (−1)<sup>r − l</sup></code></p>

<p>你的任务是将 <code>nums</code> 分割成若干子数组，使得所有子数组的成本之和 <strong>最大化</strong>，并确保每个元素 <strong>正好 </strong>属于一个子数组。</p>

<p>具体来说，如果 <code>nums</code> 被分割成 <code>k</code> 个子数组，且分割点为索引 <code>i<sub>1</sub>, i<sub>2</sub>, ..., i<sub>k − 1</sub></code>（其中 <code>0 &lt;= i<sub>1</sub> &lt; i<sub>2</sub> &lt; ... &lt; i<sub>k - 1</sub> &lt; n - 1</code>），则总成本为：</p>

<p><code>cost(0, i<sub>1</sub>) + cost(i<sub>1</sub> + 1, i<sub>2</sub>) + ... + cost(i<sub>k − 1</sub> + 1, n − 1)</code></p>

<p>返回在最优分割方式下的子数组成本之和的最大值。</p>

<p><strong>注意：</strong>如果 <code>nums</code> 没有被分割，即 <code>k = 1</code>，则总成本即为 <code>cost(0, n - 1)</code>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">nums = [1,-2,3,4]</span></p>

<p><strong>输出：</strong> <span class="example-io">10</span></p>

<p><strong>解释：</strong></p>

<p>一种总成本最大化的方法是将 <code>[1, -2, 3, 4]</code> 分割成子数组 <code>[1, -2, 3]</code> 和 <code>[4]</code>。总成本为 <code>(1 + 2 + 3) + 4 = 10</code>。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">nums = [1,-1,1,-1]</span></p>

<p><strong>输出：</strong> <span class="example-io">4</span></p>

<p><strong>解释：</strong></p>

<p>一种总成本最大化的方法是将 <code>[1, -1, 1, -1]</code> 分割成子数组 <code>[1, -1]</code> 和 <code>[1, -1]</code>。总成本为 <code>(1 + 1) + (1 + 1) = 4</code>。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">nums = [0]</span></p>

<p><strong>输出：</strong> 0</p>

<p><strong>解释：</strong></p>

<p>无法进一步分割数组，因此答案为 0。</p>
</div>

<p><strong class="example">示例 4：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">nums = [1,-1]</span></p>

<p><strong>输出：</strong> <span class="example-io">2</span></p>

<p><strong>解释：</strong></p>

<p>选择整个数组，总成本为 <code>1 + 1 = 2</code>，这是可能的最大成本。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

根据题目描述，如果当前数没取反，那么下一个可以取反，也可以不取反；如果当前数取反了，那么下一个只能不取反。

因此，我们定义一个函数 $\textit{dfs}(i, j)$，表示从第 $i$ 个数开始，第 $i$ 个数是否能取反，其中 $j$ 表示第 $i$ 个数是否取反。如果 $j = 0$，表示第 $i$ 个数不能取反，否则可以取反。答案为 $\textit{dfs}(0, 0)$。

函数 $dfs(i, j)$ 的执行过程如下：

-   如果 $i \geq \textit{len}(nums)$，表示已经遍历完了数组，返回 $0$；
-   否则，第 $i$ 个数可以不取反，此时答案为 $nums[i] + \textit{dfs}(i + 1, 1)$；如果 $j = 1$，表示第 $i$ 个数可以取反，此时答案为 $\max(\textit{dfs}(i + 1, 0) - nums[i])$。我们取两者的最大值即可。

为了避免重复计算，我们可以使用记忆化搜索，将已经计算过的结果保存起来。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumTotalCost(self, nums: List[int]) -> int:
        @cache
        def dfs(i: int, j: int) -> int:
            if i >= len(nums):
                return 0
            ans = nums[i] + dfs(i + 1, 1)
            if j == 1:
                ans = max(ans, -nums[i] + dfs(i + 1, 0))
            return ans

        return dfs(0, 0)
```

#### Java

```java
class Solution {
    private Long[][] f;
    private int[] nums;
    private int n;

    public long maximumTotalCost(int[] nums) {
        n = nums.length;
        this.nums = nums;
        f = new Long[n][2];
        return dfs(0, 0);
    }

    private long dfs(int i, int j) {
        if (i >= n) {
            return 0;
        }
        if (f[i][j] != null) {
            return f[i][j];
        }
        f[i][j] = nums[i] + dfs(i + 1, 1);
        if (j == 1) {
            f[i][j] = Math.max(f[i][j], -nums[i] + dfs(i + 1, 0));
        }
        return f[i][j];
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long maximumTotalCost(vector<int>& nums) {
        int n = nums.size();
        long long f[n][2];
        fill(f[0], f[n], LLONG_MIN);
        auto dfs = [&](this auto&& dfs, int i, int j) -> long long {
            if (i >= n) {
                return 0;
            }
            if (f[i][j] != LLONG_MIN) {
                return f[i][j];
            }
            f[i][j] = nums[i] + dfs(i + 1, 1);
            if (j) {
                f[i][j] = max(f[i][j], -nums[i] + dfs(i + 1, 0));
            }
            return f[i][j];
        };
        return dfs(0, 0);
    }
};
```

#### Go

```go
func maximumTotalCost(nums []int) int64 {
	n := len(nums)
	f := make([][2]int64, n)
	for i := range f {
		f[i] = [2]int64{-1e18, -1e18}
	}
	var dfs func(int, int) int64
	dfs = func(i, j int) int64 {
		if i >= n {
			return 0
		}
		if f[i][j] != -1e18 {
			return f[i][j]
		}
		f[i][j] = int64(nums[i]) + dfs(i+1, 1)
		if j > 0 {
			f[i][j] = max(f[i][j], int64(-nums[i])+dfs(i+1, 0))
		}
		return f[i][j]
	}
	return dfs(0, 0)
}
```

#### TypeScript

```ts
function maximumTotalCost(nums: number[]): number {
    const n = nums.length;
    const f: number[][] = Array.from({ length: n }, () => Array(2).fill(-Infinity));
    const dfs = (i: number, j: number): number => {
        if (i >= n) {
            return 0;
        }
        if (f[i][j] !== -Infinity) {
            return f[i][j];
        }
        f[i][j] = nums[i] + dfs(i + 1, 1);
        if (j) {
            f[i][j] = Math.max(f[i][j], -nums[i] + dfs(i + 1, 0));
        }
        return f[i][j];
    };
    return dfs(0, 0);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：动态规划

我们可以将方法一中的记忆化搜索转换为动态规划。

定义 $f$ 和 $g$ 为两个状态，其中 $f$ 表示当前数不取反的最大值，而 $g$ 表示当前数取反的最大值。

遍历数组 $nums$，对于第 $i$ 个数，我们可以根据 $f$ 和 $g$ 的状态更新 $f$ 和 $g$ 的值：

-   如果当前数不取反，那么 $f$ 的值为 $\max(f, g) + x$，表示当前数不取反，那么前一个数可以取反或不取反；
-   如果当前数取反，那么 $g$ 的值为 $f - x$，表示当前数取反，那么前一个数不能取反

最终答案为 $\max(f, g)$。

时间复杂度 $O(n)$，其中 $n$ 是数组 $nums$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumTotalCost(self, nums: List[int]) -> int:
        f, g = -inf, 0
        for x in nums:
            f, g = max(f, g) + x, f - x
        return max(f, g)
```

#### Java

```java
class Solution {
    public long maximumTotalCost(int[] nums) {
        long f = Long.MIN_VALUE / 2, g = 0;
        for (int x : nums) {
            long ff = Math.max(f, g) + x;
            long gg = f - x;
            f = ff;
            g = gg;
        }
        return Math.max(f, g);
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long maximumTotalCost(vector<int>& nums) {
        long long f = LLONG_MIN / 2, g = 0;
        for (int x : nums) {
            long long ff = max(f, g) + x, gg = f - x;
            f = ff;
            g = gg;
        }
        return max(f, g);
    }
};
```

#### Go

```go
func maximumTotalCost(nums []int) int64 {
	f, g := math.MinInt64/2, 0
	for _, x := range nums {
		f, g = max(f, g)+x, f-x
	}
	return int64(max(f, g))
}
```

#### TypeScript

```ts
function maximumTotalCost(nums: number[]): number {
    let [f, g] = [-Infinity, 0];
    for (const x of nums) {
        [f, g] = [Math.max(f, g) + x, f - x];
    }
    return Math.max(f, g);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3197. 包含所有 1 的最小矩形面积 II](https://leetcode.cn/problems/find-the-minimum-area-to-cover-all-ones-ii){#3197}

{{< tabs "3197" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumSum(self, grid: List[List[int]]) -> int:
        def f(i1: int, j1: int, i2: int, j2: int) -> int:
            x1 = y1 = inf
            x2 = y2 = -inf
            for i in range(i1, i2 + 1):
                for j in range(j1, j2 + 1):
                    if grid[i][j] == 1:
                        x1 = min(x1, i)
                        y1 = min(y1, j)
                        x2 = max(x2, i)
                        y2 = max(y2, j)
            return (x2 - x1 + 1) * (y2 - y1 + 1)

        m, n = len(grid), len(grid[0])
        ans = m * n
        for i1 in range(m - 1):
            for i2 in range(i1 + 1, m - 1):
                ans = min(
                    ans,
                    f(0, 0, i1, n - 1)
                    + f(i1 + 1, 0, i2, n - 1)
                    + f(i2 + 1, 0, m - 1, n - 1),
                )
        for j1 in range(n - 1):
            for j2 in range(j1 + 1, n - 1):
                ans = min(
                    ans,
                    f(0, 0, m - 1, j1)
                    + f(0, j1 + 1, m - 1, j2)
                    + f(0, j2 + 1, m - 1, n - 1),
                )
        for i in range(m - 1):
            for j in range(n - 1):
                ans = min(
                    ans,
                    f(0, 0, i, j) + f(0, j + 1, i, n - 1) + f(i + 1, 0, m - 1, n - 1),
                )
                ans = min(
                    ans,
                    f(0, 0, i, n - 1)
                    + f(i + 1, 0, m - 1, j)
                    + f(i + 1, j + 1, m - 1, n - 1),
                )

                ans = min(
                    ans,
                    f(0, 0, i, j) + f(i + 1, 0, m - 1, j) + f(0, j + 1, m - 1, n - 1),
                )
                ans = min(
                    ans,
                    f(0, 0, m - 1, j)
                    + f(0, j + 1, i, n - 1)
                    + f(i + 1, j + 1, m - 1, n - 1),
                )
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private final int inf = 1 << 30;
    private int[][] grid;

    public int minimumSum(int[][] grid) {
        this.grid = grid;
        int m = grid.length;
        int n = grid[0].length;
        int ans = m * n;

        for (int i1 = 0; i1 < m - 1; i1++) {
            for (int i2 = i1 + 1; i2 < m - 1; i2++) {
                ans = Math.min(
                    ans, f(0, 0, i1, n - 1) + f(i1 + 1, 0, i2, n - 1) + f(i2 + 1, 0, m - 1, n - 1));
            }
        }

        for (int j1 = 0; j1 < n - 1; j1++) {
            for (int j2 = j1 + 1; j2 < n - 1; j2++) {
                ans = Math.min(
                    ans, f(0, 0, m - 1, j1) + f(0, j1 + 1, m - 1, j2) + f(0, j2 + 1, m - 1, n - 1));
            }
        }

        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                ans = Math.min(
                    ans, f(0, 0, i, j) + f(0, j + 1, i, n - 1) + f(i + 1, 0, m - 1, n - 1));
                ans = Math.min(
                    ans, f(0, 0, i, n - 1) + f(i + 1, 0, m - 1, j) + f(i + 1, j + 1, m - 1, n - 1));

                ans = Math.min(
                    ans, f(0, 0, i, j) + f(i + 1, 0, m - 1, j) + f(0, j + 1, m - 1, n - 1));
                ans = Math.min(
                    ans, f(0, 0, m - 1, j) + f(0, j + 1, i, n - 1) + f(i + 1, j + 1, m - 1, n - 1));
            }
        }
        return ans;
    }

    private int f(int i1, int j1, int i2, int j2) {
        int x1 = inf, y1 = inf;
        int x2 = -inf, y2 = -inf;
        for (int i = i1; i <= i2; i++) {
            for (int j = j1; j <= j2; j++) {
                if (grid[i][j] == 1) {
                    x1 = Math.min(x1, i);
                    y1 = Math.min(y1, j);
                    x2 = Math.max(x2, i);
                    y2 = Math.max(y2, j);
                }
            }
        }
        return (x2 - x1 + 1) * (y2 - y1 + 1);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minimumSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = m * n;
        int inf = INT_MAX / 4;
        auto f = [&](int i1, int j1, int i2, int j2) {
            int x1 = inf, y1 = inf;
            int x2 = -inf, y2 = -inf;
            for (int i = i1; i <= i2; i++) {
                for (int j = j1; j <= j2; j++) {
                    if (grid[i][j] == 1) {
                        x1 = min(x1, i);
                        y1 = min(y1, j);
                        x2 = max(x2, i);
                        y2 = max(y2, j);
                    }
                }
            }
            return x1 > x2 || y1 > y2 ? inf : (x2 - x1 + 1) * (y2 - y1 + 1);
        };

        for (int i1 = 0; i1 < m - 1; i1++) {
            for (int i2 = i1 + 1; i2 < m - 1; i2++) {
                ans = min(ans, f(0, 0, i1, n - 1) + f(i1 + 1, 0, i2, n - 1) + f(i2 + 1, 0, m - 1, n - 1));
            }
        }

        for (int j1 = 0; j1 < n - 1; j1++) {
            for (int j2 = j1 + 1; j2 < n - 1; j2++) {
                ans = min(ans, f(0, 0, m - 1, j1) + f(0, j1 + 1, m - 1, j2) + f(0, j2 + 1, m - 1, n - 1));
            }
        }

        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                ans = min(ans, f(0, 0, i, j) + f(0, j + 1, i, n - 1) + f(i + 1, 0, m - 1, n - 1));
                ans = min(ans, f(0, 0, i, n - 1) + f(i + 1, 0, m - 1, j) + f(i + 1, j + 1, m - 1, n - 1));
                ans = min(ans, f(0, 0, i, j) + f(i + 1, 0, m - 1, j) + f(0, j + 1, m - 1, n - 1));
                ans = min(ans, f(0, 0, m - 1, j) + f(0, j + 1, i, n - 1) + f(i + 1, j + 1, m - 1, n - 1));
            }
        }

        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumSum(grid [][]int) int {
	m := len(grid)
	n := len(grid[0])
	ans := m * n
	inf := math.MaxInt32

	f := func(i1, j1, i2, j2 int) int {
		x1, y1 := inf, inf
		x2, y2 := -inf, -inf
		for i := i1; i <= i2; i++ {
			for j := j1; j <= j2; j++ {
				if grid[i][j] == 1 {
					x1 = min(x1, i)
					y1 = min(y1, j)
					x2 = max(x2, i)
					y2 = max(y2, j)
				}
			}
		}
		if x1 == inf {
			return 0
		}
		return (x2 - x1 + 1) * (y2 - y1 + 1)
	}

	for i1 := 0; i1 < m-1; i1++ {
		for i2 := i1 + 1; i2 < m-1; i2++ {
			ans = min(ans, f(0, 0, i1, n-1)+f(i1+1, 0, i2, n-1)+f(i2+1, 0, m-1, n-1))
		}
	}

	for j1 := 0; j1 < n-1; j1++ {
		for j2 := j1 + 1; j2 < n-1; j2++ {
			ans = min(ans, f(0, 0, m-1, j1)+f(0, j1+1, m-1, j2)+f(0, j2+1, m-1, n-1))
		}
	}

	for i := 0; i < m-1; i++ {
		for j := 0; j < n-1; j++ {
			ans = min(ans, f(0, 0, i, j)+f(0, j+1, i, n-1)+f(i+1, 0, m-1, n-1))
			ans = min(ans, f(0, 0, i, n-1)+f(i+1, 0, m-1, j)+f(i+1, j+1, m-1, n-1))
			ans = min(ans, f(0, 0, i, j)+f(i+1, 0, m-1, j)+f(0, j+1, m-1, n-1))
			ans = min(ans, f(0, 0, m-1, j)+f(0, j+1, i, n-1)+f(i+1, j+1, m-1, n-1))
		}
	}

	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumSum(grid: number[][]): number {
    const m = grid.length;
    const n = grid[0].length;
    let ans = m * n;
    const inf = Number.MAX_SAFE_INTEGER;
    const f = (i1: number, j1: number, i2: number, j2: number): number => {
        let [x1, y1] = [inf, inf];
        let [x2, y2] = [-inf, -inf];
        for (let i = i1; i <= i2; i++) {
            for (let j = j1; j <= j2; j++) {
                if (grid[i][j] === 1) {
                    x1 = Math.min(x1, i);
                    y1 = Math.min(y1, j);
                    x2 = Math.max(x2, i);
                    y2 = Math.max(y2, j);
                }
            }
        }
        return x1 === inf ? 0 : (x2 - x1 + 1) * (y2 - y1 + 1);
    };

    for (let i1 = 0; i1 < m - 1; i1++) {
        for (let i2 = i1 + 1; i2 < m - 1; i2++) {
            ans = Math.min(
                ans,
                f(0, 0, i1, n - 1) + f(i1 + 1, 0, i2, n - 1) + f(i2 + 1, 0, m - 1, n - 1),
            );
        }
    }

    for (let j1 = 0; j1 < n - 1; j1++) {
        for (let j2 = j1 + 1; j2 < n - 1; j2++) {
            ans = Math.min(
                ans,
                f(0, 0, m - 1, j1) + f(0, j1 + 1, m - 1, j2) + f(0, j2 + 1, m - 1, n - 1),
            );
        }
    }

    for (let i = 0; i < m - 1; i++) {
        for (let j = 0; j < n - 1; j++) {
            ans = Math.min(ans, f(0, 0, i, j) + f(0, j + 1, i, n - 1) + f(i + 1, 0, m - 1, n - 1));
            ans = Math.min(
                ans,
                f(0, 0, i, n - 1) + f(i + 1, 0, m - 1, j) + f(i + 1, j + 1, m - 1, n - 1),
            );
            ans = Math.min(ans, f(0, 0, i, j) + f(i + 1, 0, m - 1, j) + f(0, j + 1, m - 1, n - 1));
            ans = Math.min(
                ans,
                f(0, 0, m - 1, j) + f(0, j + 1, i, n - 1) + f(i + 1, j + 1, m - 1, n - 1),
            );
        }
    }

    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn minimum_sum(grid: Vec<Vec<i32>>) -> i32 {
        let m = grid.len();
        let n = grid[0].len();
        let mut ans = (m * n) as i32;
        let inf = i32::MAX / 4;

        let f = |i1: usize, j1: usize, i2: usize, j2: usize| -> i32 {
            let mut x1 = inf;
            let mut y1 = inf;
            let mut x2 = -inf;
            let mut y2 = -inf;

            for i in i1..=i2 {
                for j in j1..=j2 {
                    if grid[i][j] == 1 {
                        x1 = x1.min(i as i32);
                        y1 = y1.min(j as i32);
                        x2 = x2.max(i as i32);
                        y2 = y2.max(j as i32);
                    }
                }
            }
            if x1 > x2 || y1 > y2 {
                inf
            } else {
                (x2 - x1 + 1) * (y2 - y1 + 1)
            }
        };

        for i1 in 0..m - 1 {
            for i2 in i1 + 1..m - 1 {
                ans = ans.min(
                    f(0, 0, i1, n - 1)
                    + f(i1 + 1, 0, i2, n - 1)
                    + f(i2 + 1, 0, m - 1, n - 1),
                );
            }
        }

        for j1 in 0..n - 1 {
            for j2 in j1 + 1..n - 1 {
                ans = ans.min(
                    f(0, 0, m - 1, j1)
                    + f(0, j1 + 1, m - 1, j2)
                    + f(0, j2 + 1, m - 1, n - 1),
                );
            }
        }

        for i in 0..m - 1 {
            for j in 0..n - 1 {
                ans = ans.min(
                    f(0, 0, i, j)
                    + f(0, j + 1, i, n - 1)
                    + f(i + 1, 0, m - 1, n - 1),
                );
                ans = ans.min(
                    f(0, 0, i, n - 1)
                    + f(i + 1, 0, m - 1, j)
                    + f(i + 1, j + 1, m - 1, n - 1),
                );
                ans = ans.min(
                    f(0, 0, i, j)
                    + f(i + 1, 0, m - 1, j)
                    + f(0, j + 1, m - 1, n - 1),
                );
                ans = ans.min(
                    f(0, 0, m - 1, j)
                    + f(0, j + 1, i, n - 1)
                    + f(i + 1, j + 1, m - 1, n - 1),
                );
            }
        }

        ans
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[][]} grid
 * @return {number}
 */
var minimumSum = function (grid) {
    const m = grid.length;
    const n = grid[0].length;
    let ans = m * n;
    const inf = Number.MAX_SAFE_INTEGER;
    const f = (i1, j1, i2, j2) => {
        let [x1, y1] = [inf, inf];
        let [x2, y2] = [-inf, -inf];
        for (let i = i1; i <= i2; i++) {
            for (let j = j1; j <= j2; j++) {
                if (grid[i][j] === 1) {
                    x1 = Math.min(x1, i);
                    y1 = Math.min(y1, j);
                    x2 = Math.max(x2, i);
                    y2 = Math.max(y2, j);
                }
            }
        }
        return x1 === inf ? 0 : (x2 - x1 + 1) * (y2 - y1 + 1);
    };

    for (let i1 = 0; i1 < m - 1; i1++) {
        for (let i2 = i1 + 1; i2 < m - 1; i2++) {
            ans = Math.min(
                ans,
                f(0, 0, i1, n - 1) + f(i1 + 1, 0, i2, n - 1) + f(i2 + 1, 0, m - 1, n - 1),
            );
        }
    }

    for (let j1 = 0; j1 < n - 1; j1++) {
        for (let j2 = j1 + 1; j2 < n - 1; j2++) {
            ans = Math.min(
                ans,
                f(0, 0, m - 1, j1) + f(0, j1 + 1, m - 1, j2) + f(0, j2 + 1, m - 1, n - 1),
            );
        }
    }

    for (let i = 0; i < m - 1; i++) {
        for (let j = 0; j < n - 1; j++) {
            ans = Math.min(ans, f(0, 0, i, j) + f(0, j + 1, i, n - 1) + f(i + 1, 0, m - 1, n - 1));
            ans = Math.min(
                ans,
                f(0, 0, i, n - 1) + f(i + 1, 0, m - 1, j) + f(i + 1, j + 1, m - 1, n - 1),
            );
            ans = Math.min(ans, f(0, 0, i, j) + f(i + 1, 0, m - 1, j) + f(0, j + 1, m - 1, n - 1));
            ans = Math.min(
                ans,
                f(0, 0, m - 1, j) + f(0, j + 1, i, n - 1) + f(i + 1, j + 1, m - 1, n - 1),
            );
        }
    }

    return ans;
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    private const int INF = 1 << 30;
    private int[][] grid;

    public int MinimumSum(int[][] grid) {
        this.grid = grid;
        int m = grid.Length;
        int n = grid[0].Length;
        int ans = m * n;

        for (int i1 = 0; i1 < m - 1; i1++) {
            for (int i2 = i1 + 1; i2 < m - 1; i2++) {
                ans = Math.Min(
                    ans, F(0, 0, i1, n - 1) + F(i1 + 1, 0, i2, n - 1) + F(i2 + 1, 0, m - 1, n - 1));
            }
        }

        for (int j1 = 0; j1 < n - 1; j1++) {
            for (int j2 = j1 + 1; j2 < n - 1; j2++) {
                ans = Math.Min(
                    ans, F(0, 0, m - 1, j1) + F(0, j1 + 1, m - 1, j2) + F(0, j2 + 1, m - 1, n - 1));
            }
        }

        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                ans = Math.Min(
                    ans, F(0, 0, i, j) + F(0, j + 1, i, n - 1) + F(i + 1, 0, m - 1, n - 1));
                ans = Math.Min(
                    ans, F(0, 0, i, n - 1) + F(i + 1, 0, m - 1, j) + F(i + 1, j + 1, m - 1, n - 1));

                ans = Math.Min(
                    ans, F(0, 0, i, j) + F(i + 1, 0, m - 1, j) + F(0, j + 1, m - 1, n - 1));
                ans = Math.Min(
                    ans, F(0, 0, m - 1, j) + F(0, j + 1, i, n - 1) + F(i + 1, j + 1, m - 1, n - 1));
            }
        }
        return ans;
    }

    private int F(int i1, int j1, int i2, int j2) {
        int x1 = INF, y1 = INF;
        int x2 = -INF, y2 = -INF;
        for (int i = i1; i <= i2; i++) {
            for (int j = j1; j <= j2; j++) {
                if (grid[i][j] == 1) {
                    x1 = Math.Min(x1, i);
                    y1 = Math.Min(y1, j);
                    x2 = Math.Max(x2, i);
                    y2 = Math.Max(y2, j);
                }
            }
        }
        return (x2 - x1 + 1) * (y2 - y1 + 1);
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个二维 <strong>二进制 </strong>数组 <code>grid</code>。你需要找到 3 个<strong> 不重叠</strong>、面积 <strong>非零</strong> 、边在水平方向和竖直方向上的矩形，并且满足 <code>grid</code> 中所有的 1 都在这些矩形的内部。</p>

<p>返回这些矩形面积之和的<strong> 最小 </strong>可能值。</p>

<p><strong>注意</strong>，这些矩形可以相接。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">grid = [[1,0,1],[1,1,1]]</span></p>

<p><strong>输出：</strong> <span class="example-io">5</span></p>

<p><strong>解释：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3100-3199/3197.Find%20the%20Minimum%20Area%20to%20Cover%20All%20Ones%20II/images/example0rect21.png" style="padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem; width: 280px; height: 198px;" /></p>

<ul>
	<li>位于 <code>(0, 0)</code> 和 <code>(1, 0)</code> 的 1 被一个面积为 2 的矩形覆盖。</li>
	<li>位于 <code>(0, 2)</code> 和 <code>(1, 2)</code> 的 1 被一个面积为 2 的矩形覆盖。</li>
	<li>位于 <code>(1, 1)</code> 的 1 被一个面积为 1 的矩形覆盖。</li>
</ul>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">grid = [[1,0,1,0],[0,1,0,1]]</span></p>

<p><strong>输出：</strong> <span class="example-io">5</span></p>

<p><strong>解释：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3100-3199/3197.Find%20the%20Minimum%20Area%20to%20Cover%20All%20Ones%20II/images/example1rect2.png" style="padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem; width: 356px; height: 198px;" /></p>

<ul>
	<li>位于 <code>(0, 0)</code> 和 <code>(0, 2)</code> 的 1 被一个面积为 3 的矩形覆盖。</li>
	<li>位于 <code>(1, 1)</code> 的 1 被一个面积为 1 的矩形覆盖。</li>
	<li>位于 <code>(1, 3)</code> 的 1 被一个面积为 1 的矩形覆盖。</li>
</ul>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= grid.length, grid[i].length &lt;= 30</code></li>
	<li><code>grid[i][j]</code> 是 0 或 1。</li>
	<li>输入保证 <code>grid</code> 中至少有三个 1 。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举

根据题目描述，我们可以用两条分割线，将矩形分成三个部分，我们分别计算每一部分包含所有 $1$ 的最小矩形面积，然后取三个部分面积之和的最小值。

我们可以枚举两条分割线的位置，共有 $6$ 种情况：

1. 两次横向分割
1. 两次纵向分割
1. 先进行一次横向分割，再对上部分进行一次纵向分割
1. 先进行一次横向分割，再对下部分进行一次纵向分割
1. 先进行一次纵向分割，再对左部分进行一次横向分割
1. 先进行一次纵向分割，再对右部分进行一次横向分割

我们可以用一个函数 $\textit{f}(i_1, j_1, i_2, j_2)$ 来计算矩形 $(i_1, j_1)$ 到 $(i_2, j_2)$ 包含所有 $1$ 的最小矩形面积。

时间复杂度 $O(m^2 \times n^2)$，其中 $m$ 和 $n$ 分别是矩形的行数和列数。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumSum(self, grid: List[List[int]]) -> int:
        def f(i1: int, j1: int, i2: int, j2: int) -> int:
            x1 = y1 = inf
            x2 = y2 = -inf
            for i in range(i1, i2 + 1):
                for j in range(j1, j2 + 1):
                    if grid[i][j] == 1:
                        x1 = min(x1, i)
                        y1 = min(y1, j)
                        x2 = max(x2, i)
                        y2 = max(y2, j)
            return (x2 - x1 + 1) * (y2 - y1 + 1)

        m, n = len(grid), len(grid[0])
        ans = m * n
        for i1 in range(m - 1):
            for i2 in range(i1 + 1, m - 1):
                ans = min(
                    ans,
                    f(0, 0, i1, n - 1)
                    + f(i1 + 1, 0, i2, n - 1)
                    + f(i2 + 1, 0, m - 1, n - 1),
                )
        for j1 in range(n - 1):
            for j2 in range(j1 + 1, n - 1):
                ans = min(
                    ans,
                    f(0, 0, m - 1, j1)
                    + f(0, j1 + 1, m - 1, j2)
                    + f(0, j2 + 1, m - 1, n - 1),
                )
        for i in range(m - 1):
            for j in range(n - 1):
                ans = min(
                    ans,
                    f(0, 0, i, j) + f(0, j + 1, i, n - 1) + f(i + 1, 0, m - 1, n - 1),
                )
                ans = min(
                    ans,
                    f(0, 0, i, n - 1)
                    + f(i + 1, 0, m - 1, j)
                    + f(i + 1, j + 1, m - 1, n - 1),
                )

                ans = min(
                    ans,
                    f(0, 0, i, j) + f(i + 1, 0, m - 1, j) + f(0, j + 1, m - 1, n - 1),
                )
                ans = min(
                    ans,
                    f(0, 0, m - 1, j)
                    + f(0, j + 1, i, n - 1)
                    + f(i + 1, j + 1, m - 1, n - 1),
                )
        return ans
```

#### Java

```java
class Solution {
    private final int inf = 1 << 30;
    private int[][] grid;

    public int minimumSum(int[][] grid) {
        this.grid = grid;
        int m = grid.length;
        int n = grid[0].length;
        int ans = m * n;

        for (int i1 = 0; i1 < m - 1; i1++) {
            for (int i2 = i1 + 1; i2 < m - 1; i2++) {
                ans = Math.min(
                    ans, f(0, 0, i1, n - 1) + f(i1 + 1, 0, i2, n - 1) + f(i2 + 1, 0, m - 1, n - 1));
            }
        }

        for (int j1 = 0; j1 < n - 1; j1++) {
            for (int j2 = j1 + 1; j2 < n - 1; j2++) {
                ans = Math.min(
                    ans, f(0, 0, m - 1, j1) + f(0, j1 + 1, m - 1, j2) + f(0, j2 + 1, m - 1, n - 1));
            }
        }

        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                ans = Math.min(
                    ans, f(0, 0, i, j) + f(0, j + 1, i, n - 1) + f(i + 1, 0, m - 1, n - 1));
                ans = Math.min(
                    ans, f(0, 0, i, n - 1) + f(i + 1, 0, m - 1, j) + f(i + 1, j + 1, m - 1, n - 1));

                ans = Math.min(
                    ans, f(0, 0, i, j) + f(i + 1, 0, m - 1, j) + f(0, j + 1, m - 1, n - 1));
                ans = Math.min(
                    ans, f(0, 0, m - 1, j) + f(0, j + 1, i, n - 1) + f(i + 1, j + 1, m - 1, n - 1));
            }
        }
        return ans;
    }

    private int f(int i1, int j1, int i2, int j2) {
        int x1 = inf, y1 = inf;
        int x2 = -inf, y2 = -inf;
        for (int i = i1; i <= i2; i++) {
            for (int j = j1; j <= j2; j++) {
                if (grid[i][j] == 1) {
                    x1 = Math.min(x1, i);
                    y1 = Math.min(y1, j);
                    x2 = Math.max(x2, i);
                    y2 = Math.max(y2, j);
                }
            }
        }
        return (x2 - x1 + 1) * (y2 - y1 + 1);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = m * n;
        int inf = INT_MAX / 4;
        auto f = [&](int i1, int j1, int i2, int j2) {
            int x1 = inf, y1 = inf;
            int x2 = -inf, y2 = -inf;
            for (int i = i1; i <= i2; i++) {
                for (int j = j1; j <= j2; j++) {
                    if (grid[i][j] == 1) {
                        x1 = min(x1, i);
                        y1 = min(y1, j);
                        x2 = max(x2, i);
                        y2 = max(y2, j);
                    }
                }
            }
            return x1 > x2 || y1 > y2 ? inf : (x2 - x1 + 1) * (y2 - y1 + 1);
        };

        for (int i1 = 0; i1 < m - 1; i1++) {
            for (int i2 = i1 + 1; i2 < m - 1; i2++) {
                ans = min(ans, f(0, 0, i1, n - 1) + f(i1 + 1, 0, i2, n - 1) + f(i2 + 1, 0, m - 1, n - 1));
            }
        }

        for (int j1 = 0; j1 < n - 1; j1++) {
            for (int j2 = j1 + 1; j2 < n - 1; j2++) {
                ans = min(ans, f(0, 0, m - 1, j1) + f(0, j1 + 1, m - 1, j2) + f(0, j2 + 1, m - 1, n - 1));
            }
        }

        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                ans = min(ans, f(0, 0, i, j) + f(0, j + 1, i, n - 1) + f(i + 1, 0, m - 1, n - 1));
                ans = min(ans, f(0, 0, i, n - 1) + f(i + 1, 0, m - 1, j) + f(i + 1, j + 1, m - 1, n - 1));
                ans = min(ans, f(0, 0, i, j) + f(i + 1, 0, m - 1, j) + f(0, j + 1, m - 1, n - 1));
                ans = min(ans, f(0, 0, m - 1, j) + f(0, j + 1, i, n - 1) + f(i + 1, j + 1, m - 1, n - 1));
            }
        }

        return ans;
    }
};
```

#### Go

```go
func minimumSum(grid [][]int) int {
	m := len(grid)
	n := len(grid[0])
	ans := m * n
	inf := math.MaxInt32

	f := func(i1, j1, i2, j2 int) int {
		x1, y1 := inf, inf
		x2, y2 := -inf, -inf
		for i := i1; i <= i2; i++ {
			for j := j1; j <= j2; j++ {
				if grid[i][j] == 1 {
					x1 = min(x1, i)
					y1 = min(y1, j)
					x2 = max(x2, i)
					y2 = max(y2, j)
				}
			}
		}
		if x1 == inf {
			return 0
		}
		return (x2 - x1 + 1) * (y2 - y1 + 1)
	}

	for i1 := 0; i1 < m-1; i1++ {
		for i2 := i1 + 1; i2 < m-1; i2++ {
			ans = min(ans, f(0, 0, i1, n-1)+f(i1+1, 0, i2, n-1)+f(i2+1, 0, m-1, n-1))
		}
	}

	for j1 := 0; j1 < n-1; j1++ {
		for j2 := j1 + 1; j2 < n-1; j2++ {
			ans = min(ans, f(0, 0, m-1, j1)+f(0, j1+1, m-1, j2)+f(0, j2+1, m-1, n-1))
		}
	}

	for i := 0; i < m-1; i++ {
		for j := 0; j < n-1; j++ {
			ans = min(ans, f(0, 0, i, j)+f(0, j+1, i, n-1)+f(i+1, 0, m-1, n-1))
			ans = min(ans, f(0, 0, i, n-1)+f(i+1, 0, m-1, j)+f(i+1, j+1, m-1, n-1))
			ans = min(ans, f(0, 0, i, j)+f(i+1, 0, m-1, j)+f(0, j+1, m-1, n-1))
			ans = min(ans, f(0, 0, m-1, j)+f(0, j+1, i, n-1)+f(i+1, j+1, m-1, n-1))
		}
	}

	return ans
}
```

#### TypeScript

```ts
function minimumSum(grid: number[][]): number {
    const m = grid.length;
    const n = grid[0].length;
    let ans = m * n;
    const inf = Number.MAX_SAFE_INTEGER;
    const f = (i1: number, j1: number, i2: number, j2: number): number => {
        let [x1, y1] = [inf, inf];
        let [x2, y2] = [-inf, -inf];
        for (let i = i1; i <= i2; i++) {
            for (let j = j1; j <= j2; j++) {
                if (grid[i][j] === 1) {
                    x1 = Math.min(x1, i);
                    y1 = Math.min(y1, j);
                    x2 = Math.max(x2, i);
                    y2 = Math.max(y2, j);
                }
            }
        }
        return x1 === inf ? 0 : (x2 - x1 + 1) * (y2 - y1 + 1);
    };

    for (let i1 = 0; i1 < m - 1; i1++) {
        for (let i2 = i1 + 1; i2 < m - 1; i2++) {
            ans = Math.min(
                ans,
                f(0, 0, i1, n - 1) + f(i1 + 1, 0, i2, n - 1) + f(i2 + 1, 0, m - 1, n - 1),
            );
        }
    }

    for (let j1 = 0; j1 < n - 1; j1++) {
        for (let j2 = j1 + 1; j2 < n - 1; j2++) {
            ans = Math.min(
                ans,
                f(0, 0, m - 1, j1) + f(0, j1 + 1, m - 1, j2) + f(0, j2 + 1, m - 1, n - 1),
            );
        }
    }

    for (let i = 0; i < m - 1; i++) {
        for (let j = 0; j < n - 1; j++) {
            ans = Math.min(ans, f(0, 0, i, j) + f(0, j + 1, i, n - 1) + f(i + 1, 0, m - 1, n - 1));
            ans = Math.min(
                ans,
                f(0, 0, i, n - 1) + f(i + 1, 0, m - 1, j) + f(i + 1, j + 1, m - 1, n - 1),
            );
            ans = Math.min(ans, f(0, 0, i, j) + f(i + 1, 0, m - 1, j) + f(0, j + 1, m - 1, n - 1));
            ans = Math.min(
                ans,
                f(0, 0, m - 1, j) + f(0, j + 1, i, n - 1) + f(i + 1, j + 1, m - 1, n - 1),
            );
        }
    }

    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn minimum_sum(grid: Vec<Vec<i32>>) -> i32 {
        let m = grid.len();
        let n = grid[0].len();
        let mut ans = (m * n) as i32;
        let inf = i32::MAX / 4;

        let f = |i1: usize, j1: usize, i2: usize, j2: usize| -> i32 {
            let mut x1 = inf;
            let mut y1 = inf;
            let mut x2 = -inf;
            let mut y2 = -inf;

            for i in i1..=i2 {
                for j in j1..=j2 {
                    if grid[i][j] == 1 {
                        x1 = x1.min(i as i32);
                        y1 = y1.min(j as i32);
                        x2 = x2.max(i as i32);
                        y2 = y2.max(j as i32);
                    }
                }
            }
            if x1 > x2 || y1 > y2 {
                inf
            } else {
                (x2 - x1 + 1) * (y2 - y1 + 1)
            }
        };

        for i1 in 0..m - 1 {
            for i2 in i1 + 1..m - 1 {
                ans = ans.min(
                    f(0, 0, i1, n - 1)
                    + f(i1 + 1, 0, i2, n - 1)
                    + f(i2 + 1, 0, m - 1, n - 1),
                );
            }
        }

        for j1 in 0..n - 1 {
            for j2 in j1 + 1..n - 1 {
                ans = ans.min(
                    f(0, 0, m - 1, j1)
                    + f(0, j1 + 1, m - 1, j2)
                    + f(0, j2 + 1, m - 1, n - 1),
                );
            }
        }

        for i in 0..m - 1 {
            for j in 0..n - 1 {
                ans = ans.min(
                    f(0, 0, i, j)
                    + f(0, j + 1, i, n - 1)
                    + f(i + 1, 0, m - 1, n - 1),
                );
                ans = ans.min(
                    f(0, 0, i, n - 1)
                    + f(i + 1, 0, m - 1, j)
                    + f(i + 1, j + 1, m - 1, n - 1),
                );
                ans = ans.min(
                    f(0, 0, i, j)
                    + f(i + 1, 0, m - 1, j)
                    + f(0, j + 1, m - 1, n - 1),
                );
                ans = ans.min(
                    f(0, 0, m - 1, j)
                    + f(0, j + 1, i, n - 1)
                    + f(i + 1, j + 1, m - 1, n - 1),
                );
            }
        }

        ans
    }
}
```

#### JavaScript

```js
/**
 * @param {number[][]} grid
 * @return {number}
 */
var minimumSum = function (grid) {
    const m = grid.length;
    const n = grid[0].length;
    let ans = m * n;
    const inf = Number.MAX_SAFE_INTEGER;
    const f = (i1, j1, i2, j2) => {
        let [x1, y1] = [inf, inf];
        let [x2, y2] = [-inf, -inf];
        for (let i = i1; i <= i2; i++) {
            for (let j = j1; j <= j2; j++) {
                if (grid[i][j] === 1) {
                    x1 = Math.min(x1, i);
                    y1 = Math.min(y1, j);
                    x2 = Math.max(x2, i);
                    y2 = Math.max(y2, j);
                }
            }
        }
        return x1 === inf ? 0 : (x2 - x1 + 1) * (y2 - y1 + 1);
    };

    for (let i1 = 0; i1 < m - 1; i1++) {
        for (let i2 = i1 + 1; i2 < m - 1; i2++) {
            ans = Math.min(
                ans,
                f(0, 0, i1, n - 1) + f(i1 + 1, 0, i2, n - 1) + f(i2 + 1, 0, m - 1, n - 1),
            );
        }
    }

    for (let j1 = 0; j1 < n - 1; j1++) {
        for (let j2 = j1 + 1; j2 < n - 1; j2++) {
            ans = Math.min(
                ans,
                f(0, 0, m - 1, j1) + f(0, j1 + 1, m - 1, j2) + f(0, j2 + 1, m - 1, n - 1),
            );
        }
    }

    for (let i = 0; i < m - 1; i++) {
        for (let j = 0; j < n - 1; j++) {
            ans = Math.min(ans, f(0, 0, i, j) + f(0, j + 1, i, n - 1) + f(i + 1, 0, m - 1, n - 1));
            ans = Math.min(
                ans,
                f(0, 0, i, n - 1) + f(i + 1, 0, m - 1, j) + f(i + 1, j + 1, m - 1, n - 1),
            );
            ans = Math.min(ans, f(0, 0, i, j) + f(i + 1, 0, m - 1, j) + f(0, j + 1, m - 1, n - 1));
            ans = Math.min(
                ans,
                f(0, 0, m - 1, j) + f(0, j + 1, i, n - 1) + f(i + 1, j + 1, m - 1, n - 1),
            );
        }
    }

    return ans;
};
```

#### C#

```cs
public class Solution {
    private const int INF = 1 << 30;
    private int[][] grid;

    public int MinimumSum(int[][] grid) {
        this.grid = grid;
        int m = grid.Length;
        int n = grid[0].Length;
        int ans = m * n;

        for (int i1 = 0; i1 < m - 1; i1++) {
            for (int i2 = i1 + 1; i2 < m - 1; i2++) {
                ans = Math.Min(
                    ans, F(0, 0, i1, n - 1) + F(i1 + 1, 0, i2, n - 1) + F(i2 + 1, 0, m - 1, n - 1));
            }
        }

        for (int j1 = 0; j1 < n - 1; j1++) {
            for (int j2 = j1 + 1; j2 < n - 1; j2++) {
                ans = Math.Min(
                    ans, F(0, 0, m - 1, j1) + F(0, j1 + 1, m - 1, j2) + F(0, j2 + 1, m - 1, n - 1));
            }
        }

        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                ans = Math.Min(
                    ans, F(0, 0, i, j) + F(0, j + 1, i, n - 1) + F(i + 1, 0, m - 1, n - 1));
                ans = Math.Min(
                    ans, F(0, 0, i, n - 1) + F(i + 1, 0, m - 1, j) + F(i + 1, j + 1, m - 1, n - 1));

                ans = Math.Min(
                    ans, F(0, 0, i, j) + F(i + 1, 0, m - 1, j) + F(0, j + 1, m - 1, n - 1));
                ans = Math.Min(
                    ans, F(0, 0, m - 1, j) + F(0, j + 1, i, n - 1) + F(i + 1, j + 1, m - 1, n - 1));
            }
        }
        return ans;
    }

    private int F(int i1, int j1, int i2, int j2) {
        int x1 = INF, y1 = INF;
        int x2 = -INF, y2 = -INF;
        for (int i = i1; i <= i2; i++) {
            for (int j = j1; j <= j2; j++) {
                if (grid[i][j] == 1) {
                    x1 = Math.Min(x1, i);
                    y1 = Math.Min(y1, j);
                    x2 = Math.Max(x2, i);
                    y2 = Math.Max(y2, j);
                }
            }
        }
        return (x2 - x1 + 1) * (y2 - y1 + 1);
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3198. 查找每个州的城市 🔒](https://leetcode.cn/problems/find-cities-in-each-state){#3198}

{{< tabs "3198" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT
    state,
    GROUP_CONCAT(city ORDER BY city SEPARATOR ', ') cities
FROM cities
GROUP BY 1
ORDER BY 1;
```
{{% /tab %}}
{{% tab "python" %}}
```python
import pandas as pd


def find_cities(cities: pd.DataFrame) -> pd.DataFrame:
    result = (
        cities.groupby("state")["city"]
        .apply(lambda x: ", ".join(sorted(x)))
        .reset_index()
    )
    result.columns = ["state", "cities"]
    return result
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code>cities</code></p>

<pre>
+-------------+---------+
| Column Name | Type    | 
+-------------+---------+
| state       | varchar |
| city        | varchar |
+-------------+---------+
(state, city) 是这张表的主键（有不同值的列的组合）。
这张表的每一行包含州名和其中的城市名。
</pre>

<p>编写一个解决方案来 <strong>查找每个州的所有城市</strong>，并将它们组合成 <strong>一个逗号分隔</strong> 的字符串。</p>

<p>返回结果表以&nbsp;<code>state</code> <strong>升序&nbsp;</strong>排序。</p>

<p>结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong class="example">示例：</strong></p>

<div class="example-block">
<p><strong>输入：</strong></p>

<p>cities 表：</p>

<pre class="example-io">
+-------------+---------------+
| state       | city          |
+-------------+---------------+
| California  | Los Angeles   |
| California  | San Francisco |
| California  | San Diego     |
| Texas       | Houston       |
| Texas       | Austin        |
| Texas       | Dallas        |
| New York    | New York City |
| New York    | Buffalo       |
| New York    | Rochester     |
+-------------+---------------+
</pre>

<p><strong>输出：</strong></p>

<pre class="example-io">
+-------------+---------------------------------------+
| state       | cities                                |
+-------------+---------------------------------------+
| California  | Los Angeles, San Diego, San Francisco |
| New York    | Buffalo, New York City, Rochester     |
| Texas       | Austin, Dallas, Houston               |
+-------------+---------------------------------------+
</pre>

<p><strong>解释：</strong></p>

<ul>
	<li><strong>California：</strong>所有城市 ("Los Angeles", "San Diego", "San Francisco") 以逗号分隔的字符串列出。</li>
	<li><strong>New York：</strong>所有城市 ("Buffalo", "New York City", "Rochester") 以逗号分隔的字符串列出。</li>
	<li><strong>Texas：</strong>所有城市 ("Austin", "Dallas", "Houston") 以逗号分隔的字符串列出。</li>
</ul>

<p><b>注意：</b>输出表以州名升序排序。</p>
</div>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：分组聚合

我们可以先按照 `state` 字段进行分组，然后对每个分组内的 `city` 字段进行排序，最后使用 `GROUP_CONCAT` 函数将排序后的城市名连接成一个逗号分隔的字符串。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT
    state,
    GROUP_CONCAT(city ORDER BY city SEPARATOR ', ') cities
FROM cities
GROUP BY 1
ORDER BY 1;
```

#### Pandas

```python
import pandas as pd


def find_cities(cities: pd.DataFrame) -> pd.DataFrame:
    result = (
        cities.groupby("state")["city"]
        .apply(lambda x: ", ".join(sorted(x)))
        .reset_index()
    )
    result.columns = ["state", "cities"]
    return result
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3199. 用偶数异或设置位计数三元组 I 🔒](https://leetcode.cn/problems/count-triplets-with-even-xor-set-bits-i){#3199}

{{< tabs "3199" >}}

{{% tab "python" %}}
```python
class Solution:
    def tripletCount(self, a: List[int], b: List[int], c: List[int]) -> int:
        cnt1 = Counter(x.bit_count() & 1 for x in a)
        cnt2 = Counter(x.bit_count() & 1 for x in b)
        cnt3 = Counter(x.bit_count() & 1 for x in c)
        ans = 0
        for i in range(2):
            for j in range(2):
                for k in range(2):
                    if (i + j + k) & 1 ^ 1:
                        ans += cnt1[i] * cnt2[j] * cnt3[k]
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int tripletCount(int[] a, int[] b, int[] c) {
        int[] cnt1 = new int[2];
        int[] cnt2 = new int[2];
        int[] cnt3 = new int[2];
        for (int x : a) {
            ++cnt1[Integer.bitCount(x) & 1];
        }
        for (int x : b) {
            ++cnt2[Integer.bitCount(x) & 1];
        }
        for (int x : c) {
            ++cnt3[Integer.bitCount(x) & 1];
        }
        int ans = 0;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                for (int k = 0; k < 2; ++k) {
                    if ((i + j + k) % 2 == 0) {
                        ans += cnt1[i] * cnt2[j] * cnt3[k];
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
    int tripletCount(vector<int>& a, vector<int>& b, vector<int>& c) {
        int cnt1[2]{};
        int cnt2[2]{};
        int cnt3[2]{};
        for (int x : a) {
            ++cnt1[__builtin_popcount(x) & 1];
        }
        for (int x : b) {
            ++cnt2[__builtin_popcount(x) & 1];
        }
        for (int x : c) {
            ++cnt3[__builtin_popcount(x) & 1];
        }
        int ans = 0;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                for (int k = 0; k < 2; ++k) {
                    if ((i + j + k) % 2 == 0) {
                        ans += cnt1[i] * cnt2[j] * cnt3[k];
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
func tripletCount(a []int, b []int, c []int) (ans int) {
	cnt1 := [2]int{}
	cnt2 := [2]int{}
	cnt3 := [2]int{}
	for _, x := range a {
		cnt1[bits.OnesCount(uint(x))%2]++
	}
	for _, x := range b {
		cnt2[bits.OnesCount(uint(x))%2]++
	}
	for _, x := range c {
		cnt3[bits.OnesCount(uint(x))%2]++
	}
	for i := 0; i < 2; i++ {
		for j := 0; j < 2; j++ {
			for k := 0; k < 2; k++ {
				if (i+j+k)%2 == 0 {
					ans += cnt1[i] * cnt2[j] * cnt3[k]
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
function tripletCount(a: number[], b: number[], c: number[]): number {
    const cnt1: [number, number] = [0, 0];
    const cnt2: [number, number] = [0, 0];
    const cnt3: [number, number] = [0, 0];
    for (const x of a) {
        ++cnt1[bitCount(x) & 1];
    }
    for (const x of b) {
        ++cnt2[bitCount(x) & 1];
    }
    for (const x of c) {
        ++cnt3[bitCount(x) & 1];
    }
    let ans = 0;
    for (let i = 0; i < 2; ++i) {
        for (let j = 0; j < 2; ++j) {
            for (let k = 0; k < 2; ++k) {
                if ((i + j + k) % 2 === 0) {
                    ans += cnt1[i] * cnt2[j] * cnt3[k];
                }
            }
        }
    }
    return ans;
}

function bitCount(i: number): number {
    i = i - ((i >>> 1) & 0x55555555);
    i = (i & 0x33333333) + ((i >>> 2) & 0x33333333);
    i = (i + (i >>> 4)) & 0x0f0f0f0f;
    i = i + (i >>> 8);
    i = i + (i >>> 16);
    return i & 0x3f;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定三个整数数组&nbsp;<code>a</code>，<code>b</code>&nbsp;和&nbsp;<code>c</code>，返回组内元素按位&nbsp;<code>XOR</code>&nbsp;有&nbsp;<strong>偶数</strong>&nbsp;个 <span data-keyword="set-bit">设置位</span> 的三元组&nbsp;<code>(a[i], b[j], c[k])</code>&nbsp;的数量。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1:</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>a = [1], b = [2], c = [3]</span></p>

<p><strong>输出：</strong><span class="example-io">1</span></p>

<p><strong>解释：</strong></p>

<p>只有一个三元组&nbsp;<code>(a[0], b[0], c[0])</code>&nbsp;并且它们的&nbsp;<code>XOR</code>&nbsp;为：<code>1 XOR 2 XOR 3 = 00<sub>2</sub></code>。</p>
</div>

<p><strong class="example">示例 2:</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b></span><span class="example-io">a = [1,1], b = [2,3], c = [1,5]</span></p>

<p><strong>输出：</strong><span class="example-io">4</span></p>

<p><strong>解释：</strong></p>

<p>考虑以下 4 个三元组：</p>

<ul>
	<li><code>(a[0], b[1], c[0])</code>: <code>1 XOR 3 XOR 1 = 011<sub>2</sub></code></li>
	<li><code>(a[1], b[1], c[0])</code>: <code>1 XOR 3 XOR 1 = 011<sub>2</sub></code></li>
	<li><code>(a[0], b[0], c[1])</code>: <code>1 XOR 2 XOR 5 = 110<sub>2</sub></code></li>
	<li><code>(a[1], b[0], c[1])</code>: <code>1 XOR 2 XOR 5 = 110<sub>2</sub></code></li>
</ul>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= a.length, b.length, c.length &lt;= 100</code></li>
	<li><code>0 &lt;= a[i], b[i], c[i] &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：位运算

对于两个整数，异或结果中 $1$ 的个数的奇偶性，取决于两个整数的二进制表示中 $1$ 的个数的奇偶性。

我们可以用三个数组 `cnt1`、`cnt2`、`cnt3` 分别记录数组 `a`、`b`、`c` 中每个数的二进制表示中 $1$ 的个数的奇偶性。

然后我们在 $[0, 1]$ 的范围内枚举三个数组中的每个数的二进制表示中 $1$ 的个数的奇偶性，如果三个数的二进制表示中 $1$ 的个数的奇偶性之和为偶数，那么这三个数的异或结果中 $1$ 的个数也为偶数，此时我们将这三个数的组合数相乘累加到答案中。

最后返回答案即可。

时间复杂度 $O(n)$，其中 $n$ 为数组 `a`、`b`、`c` 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def tripletCount(self, a: List[int], b: List[int], c: List[int]) -> int:
        cnt1 = Counter(x.bit_count() & 1 for x in a)
        cnt2 = Counter(x.bit_count() & 1 for x in b)
        cnt3 = Counter(x.bit_count() & 1 for x in c)
        ans = 0
        for i in range(2):
            for j in range(2):
                for k in range(2):
                    if (i + j + k) & 1 ^ 1:
                        ans += cnt1[i] * cnt2[j] * cnt3[k]
        return ans
```

#### Java

```java
class Solution {
    public int tripletCount(int[] a, int[] b, int[] c) {
        int[] cnt1 = new int[2];
        int[] cnt2 = new int[2];
        int[] cnt3 = new int[2];
        for (int x : a) {
            ++cnt1[Integer.bitCount(x) & 1];
        }
        for (int x : b) {
            ++cnt2[Integer.bitCount(x) & 1];
        }
        for (int x : c) {
            ++cnt3[Integer.bitCount(x) & 1];
        }
        int ans = 0;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                for (int k = 0; k < 2; ++k) {
                    if ((i + j + k) % 2 == 0) {
                        ans += cnt1[i] * cnt2[j] * cnt3[k];
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
    int tripletCount(vector<int>& a, vector<int>& b, vector<int>& c) {
        int cnt1[2]{};
        int cnt2[2]{};
        int cnt3[2]{};
        for (int x : a) {
            ++cnt1[__builtin_popcount(x) & 1];
        }
        for (int x : b) {
            ++cnt2[__builtin_popcount(x) & 1];
        }
        for (int x : c) {
            ++cnt3[__builtin_popcount(x) & 1];
        }
        int ans = 0;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                for (int k = 0; k < 2; ++k) {
                    if ((i + j + k) % 2 == 0) {
                        ans += cnt1[i] * cnt2[j] * cnt3[k];
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
func tripletCount(a []int, b []int, c []int) (ans int) {
	cnt1 := [2]int{}
	cnt2 := [2]int{}
	cnt3 := [2]int{}
	for _, x := range a {
		cnt1[bits.OnesCount(uint(x))%2]++
	}
	for _, x := range b {
		cnt2[bits.OnesCount(uint(x))%2]++
	}
	for _, x := range c {
		cnt3[bits.OnesCount(uint(x))%2]++
	}
	for i := 0; i < 2; i++ {
		for j := 0; j < 2; j++ {
			for k := 0; k < 2; k++ {
				if (i+j+k)%2 == 0 {
					ans += cnt1[i] * cnt2[j] * cnt3[k]
				}
			}
		}
	}
	return
}
```

#### TypeScript

```ts
function tripletCount(a: number[], b: number[], c: number[]): number {
    const cnt1: [number, number] = [0, 0];
    const cnt2: [number, number] = [0, 0];
    const cnt3: [number, number] = [0, 0];
    for (const x of a) {
        ++cnt1[bitCount(x) & 1];
    }
    for (const x of b) {
        ++cnt2[bitCount(x) & 1];
    }
    for (const x of c) {
        ++cnt3[bitCount(x) & 1];
    }
    let ans = 0;
    for (let i = 0; i < 2; ++i) {
        for (let j = 0; j < 2; ++j) {
            for (let k = 0; k < 2; ++k) {
                if ((i + j + k) % 2 === 0) {
                    ans += cnt1[i] * cnt2[j] * cnt3[k];
                }
            }
        }
    }
    return ans;
}

function bitCount(i: number): number {
    i = i - ((i >>> 1) & 0x55555555);
    i = (i & 0x33333333) + ((i >>> 2) & 0x33333333);
    i = (i + (i >>> 4)) & 0x0f0f0f0f;
    i = i + (i >>> 8);
    i = i + (i >>> 16);
    return i & 0x3f;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
