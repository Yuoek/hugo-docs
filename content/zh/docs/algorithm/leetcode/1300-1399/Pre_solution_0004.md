---
title: "1330_翻转子数组得到最大的数组值"
date: 2025-10-08T18:37:12+08:00
weight: 4
tags: [二分查找, 二叉树, 动态规划, 双指针, 哈希表, 图, 堆（优先队列）, 字符串, 排序, 数学, 数据库, 数组, 最短路, 树, 深度优先搜索, 矩阵, 贪心]
---

{{< markmap >}}
### [1330_翻转子数组得到最大的数组值](#1330)
#### [贪心](#1330)
#### [数组](#1330)
#### [数学](#1330)
### [1331_数组序号转换](#1331)
#### [数组](#1331)
#### [哈希表](#1331)
#### [排序](#1331)
### [1332_删除回文子序列](#1332)
#### [双指针](#1332)
#### [字符串](#1332)
### [1333_餐厅过滤器](#1333)
#### [数组](#1333)
#### [排序](#1333)
### [1334_阈值距离内邻居最少的城市](#1334)
#### [图](#1334)
#### [动态规划](#1334)
#### [最短路](#1334)
### [1335_工作计划的最低难度](#1335)
#### [数组](#1335)
#### [动态规划](#1335)
### [1336_每次访问的交易次数 🔒](#1336)
#### [数据库](#1336)
### [1337_矩阵中战斗力最弱的 K 行](#1337)
#### [数组](#1337)
#### [二分查找](#1337)
#### [矩阵](#1337)
#### [排序](#1337)
#### [堆（优先队列）](#1337)
### [1338_数组大小减半](#1338)
#### [贪心](#1338)
#### [数组](#1338)
#### [哈希表](#1338)
#### [排序](#1338)
#### [堆（优先队列）](#1338)
### [1339_分裂二叉树的最大乘积](#1339)
#### [树](#1339)
#### [深度优先搜索](#1339)
#### [二叉树](#1339)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1330_翻转子数组得到最大的数组值
___
#### 贪心
___
#### 数组
___
#### 数学
---
### 1331_数组序号转换
___
#### 数组
___
#### 哈希表
___
#### 排序
---
### 1332_删除回文子序列
___
#### 双指针
___
#### 字符串
---
### 1333_餐厅过滤器
___
#### 数组
___
#### 排序
---
### 1334_阈值距离内邻居最少的城市
___
#### 图
___
#### 动态规划
___
#### 最短路
---
### 1335_工作计划的最低难度
___
#### 数组
___
#### 动态规划
---
### 1336_每次访问的交易次数 🔒
___
#### 数据库
---
### 1337_矩阵中战斗力最弱的 K 行
___
#### 数组
___
#### 二分查找
___
#### 矩阵
___
#### 排序
___
#### 堆（优先队列）
---
### 1338_数组大小减半
___
#### 贪心
___
#### 数组
___
#### 哈希表
___
#### 排序
___
#### 堆（优先队列）
---
### 1339_分裂二叉树的最大乘积
___
#### 树
___
#### 深度优先搜索
___
#### 二叉树
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 二叉树 | 动态规划 |
| 双指针 | 哈希表 | 图 |
| 堆（优先队列） | 字符串 | 排序 |
| 数学 | 数据库 | 数组 |
| 最短路 | 树 | 深度优先搜索 |
| 矩阵 | 贪心 |  |

# [1330. 翻转子数组得到最大的数组值](https://leetcode.cn/problems/reverse-subarray-to-maximize-array-value){#1330}

{{< tabs "1330" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxValueAfterReverse(self, nums: List[int]) -> int:
        ans = s = sum(abs(x - y) for x, y in pairwise(nums))
        for x, y in pairwise(nums):
            ans = max(ans, s + abs(nums[0] - y) - abs(x - y))
            ans = max(ans, s + abs(nums[-1] - x) - abs(x - y))
        for k1, k2 in pairwise((1, -1, -1, 1, 1)):
            mx, mi = -inf, inf
            for x, y in pairwise(nums):
                a = k1 * x + k2 * y
                b = abs(x - y)
                mx = max(mx, a - b)
                mi = min(mi, a + b)
            ans = max(ans, s + max(mx - mi, 0))
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxValueAfterReverse(int[] nums) {
        int n = nums.length;
        int s = 0;
        for (int i = 0; i < n - 1; ++i) {
            s += Math.abs(nums[i] - nums[i + 1]);
        }
        int ans = s;
        for (int i = 0; i < n - 1; ++i) {
            ans = Math.max(
                ans, s + Math.abs(nums[0] - nums[i + 1]) - Math.abs(nums[i] - nums[i + 1]));
            ans = Math.max(
                ans, s + Math.abs(nums[n - 1] - nums[i]) - Math.abs(nums[i] - nums[i + 1]));
        }
        int[] dirs = {1, -1, -1, 1, 1};
        final int inf = 1 << 30;
        for (int k = 0; k < 4; ++k) {
            int k1 = dirs[k], k2 = dirs[k + 1];
            int mx = -inf, mi = inf;
            for (int i = 0; i < n - 1; ++i) {
                int a = k1 * nums[i] + k2 * nums[i + 1];
                int b = Math.abs(nums[i] - nums[i + 1]);
                mx = Math.max(mx, a - b);
                mi = Math.min(mi, a + b);
            }
            ans = Math.max(ans, s + Math.max(0, mx - mi));
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
    int maxValueAfterReverse(vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        for (int i = 0; i < n - 1; ++i) {
            s += abs(nums[i] - nums[i + 1]);
        }
        int ans = s;
        for (int i = 0; i < n - 1; ++i) {
            ans = max(ans, s + abs(nums[0] - nums[i + 1]) - abs(nums[i] - nums[i + 1]));
            ans = max(ans, s + abs(nums[n - 1] - nums[i]) - abs(nums[i] - nums[i + 1]));
        }
        int dirs[5] = {1, -1, -1, 1, 1};
        const int inf = 1 << 30;
        for (int k = 0; k < 4; ++k) {
            int k1 = dirs[k], k2 = dirs[k + 1];
            int mx = -inf, mi = inf;
            for (int i = 0; i < n - 1; ++i) {
                int a = k1 * nums[i] + k2 * nums[i + 1];
                int b = abs(nums[i] - nums[i + 1]);
                mx = max(mx, a - b);
                mi = min(mi, a + b);
            }
            ans = max(ans, s + max(0, mx - mi));
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxValueAfterReverse(nums []int) int {
	s, n := 0, len(nums)
	for i, x := range nums[:n-1] {
		y := nums[i+1]
		s += abs(x - y)
	}
	ans := s
	for i, x := range nums[:n-1] {
		y := nums[i+1]
		ans = max(ans, s+abs(nums[0]-y)-abs(x-y))
		ans = max(ans, s+abs(nums[n-1]-x)-abs(x-y))
	}
	dirs := [5]int{1, -1, -1, 1, 1}
	const inf = 1 << 30
	for k := 0; k < 4; k++ {
		k1, k2 := dirs[k], dirs[k+1]
		mx, mi := -inf, inf
		for i, x := range nums[:n-1] {
			y := nums[i+1]
			a := k1*x + k2*y
			b := abs(x - y)
			mx = max(mx, a-b)
			mi = min(mi, a+b)
		}
		ans = max(ans, s+max(mx-mi, 0))
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
function maxValueAfterReverse(nums: number[]): number {
    const n = nums.length;
    let s = 0;
    for (let i = 0; i < n - 1; ++i) {
        s += Math.abs(nums[i] - nums[i + 1]);
    }
    let ans = s;
    for (let i = 0; i < n - 1; ++i) {
        const d = Math.abs(nums[i] - nums[i + 1]);
        ans = Math.max(ans, s + Math.abs(nums[0] - nums[i + 1]) - d);
        ans = Math.max(ans, s + Math.abs(nums[n - 1] - nums[i]) - d);
    }
    const dirs = [1, -1, -1, 1, 1];
    const inf = 1 << 30;
    for (let k = 0; k < 4; ++k) {
        let mx = -inf;
        let mi = inf;
        for (let i = 0; i < n - 1; ++i) {
            const a = dirs[k] * nums[i] + dirs[k + 1] * nums[i + 1];
            const b = Math.abs(nums[i] - nums[i + 1]);
            mx = Math.max(mx, a - b);
            mi = Math.min(mi, a + b);
        }
        ans = Math.max(ans, s + Math.max(0, mx - mi));
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

<p>给你一个整数数组&nbsp;<code>nums</code> 。「数组值」定义为所有满足&nbsp;<code>0 &lt;= i &lt; nums.length-1</code>&nbsp;的&nbsp;<code>|nums[i]-nums[i+1]|</code>&nbsp;的和。</p>

<p>你可以选择给定数组的任意子数组，并将该子数组翻转。但你只能执行这个操作&nbsp;<strong>一次</strong> 。</p>

<p>请你找到可行的最大 <strong>数组值&nbsp;</strong>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,3,1,5,4]
<strong>输出：</strong>10
<strong>解释：</strong>通过翻转子数组 [3,1,5] ，数组变成 [2,5,1,3,4] ，数组值为 10 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,4,9,24,2,1,10]
<strong>输出：</strong>68
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 3*10<sup>4</sup></code></li>
	<li><code>-10<sup>5</sup> &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
	<li>答案保证在 32 位整数范围内。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：分类讨论 + 枚举

根据题目描述，我们需要求出：在翻转一次子数组的情况下，数组值 $\sum_{i=0}^{n-2} |a_i - a_{i+1}|$ 的最大值。

接下来，我们分以下几种情况讨论：

1. 不翻转子数组
1. 翻转子数组，且子数组“包含”第一个元素
1. 翻转子数组，且子数组“包含”最后一个元素
1. 翻转子数组，且子数组“不包含”第一个元素和最后一个元素

我们记不翻转子数组时的数组值为 $s$，此时有 $s = \sum_{i=0}^{n-2} |a_i - a_{i+1}|$。我们可以将答案 $ans$ 初始化为 $s$。

如果翻转子数组，且子数组包含第一个元素，我们可以枚举翻转的子数组的最后一个元素 $a_i$，其中 $0 \leq i \lt n-1$，此时有 $ans = \max(ans, s + |a_0 - a_{i+1}| - |a_i - a_{i+1}|)$。

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1300-1399/1330.Reverse%20Subarray%20To%20Maximize%20Array%20Value/images/1-drawio.png" /></p>

同理，如果翻转子数组，且子数组包含最后一个元素，我们可以枚举翻转的子数组的第一个元素 $a_{i+1}$，其中 $0 \leq i \lt n-1$，此时有 $ans = \max(ans, s + |a_{n-1} - a_i| - |a_i - a_{i+1}|)$。

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1300-1399/1330.Reverse%20Subarray%20To%20Maximize%20Array%20Value/images/2-drawio.png" /></p>

如果翻转子数组，且子数组不包含第一个元素和最后一个元素，我们将数组任意两个相邻元素视为一个点对 $(x, y)$，记翻转的第一个元素为 $y_1$，其左侧相邻元素为 $x_1$；翻转的最后一个元素为 $x_2$，其右侧相邻元素为 $y_2$。

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1300-1399/1330.Reverse%20Subarray%20To%20Maximize%20Array%20Value/images/3-drawio.png" /></p>

此时相比较于不翻转子数组，数组值的变化量为 $|x_1 - x_2| + |y_1 - y_2| - |x_1 - y_1| - |x_2 - y_2|$，其中，前两项可以表示为：

$$
\left | x_1 - x_2 \right |  + \left | y_1 - y_2 \right | = \max \begin{cases} (x_1 + y_1) - (x_2 + y_2) \\ (x_1 - y_1) - (x_2 - y_2) \\ (-x_1 + y_1) - (-x_2 + y_2) \\ (-x_1 - y_1) - (-x_2 - y_2) \end{cases}
$$

那么数组值变化量为：

$$
\left | x_1 - x_2 \right |  + \left | y_1 - y_2 \right | - \left | x_1 - y_1 \right | - \left | x_2 - y_2 \right |  = \max \begin{cases} (x_1 + y_1) - \left |x_1 - y_1 \right | - \left ( (x_2 + y_2) + \left |x_2 - y_2 \right | \right ) \\ (x_1 - y_1) - \left |x_1 - y_1 \right | - \left ( (x_2 - y_2) + \left |x_2 - y_2 \right | \right ) \\ (-x_1 + y_1) - \left |x_1 - y_1 \right | - \left ( (-x_2 + y_2) + \left |x_2 - y_2 \right | \right ) \\ (-x_1 - y_1) - \left |x_1 - y_1 \right | - \left ( (-x_2 - y_2) + \left |x_2 - y_2 \right | \right ) \end{cases}
$$

因此，我们只要求出 $k_1 \times x + k_2 \times y$ 的最大值 $mx$，其中 $k_1, k_2 \in \{-1, 1\}$，以及对应的 $|x - y|$ 的最小值 $mi$，那么数组值变化量的最大值为 $mx - mi$。答案为 $ans = \max(ans, s + \max(0, mx - mi))$。

在代码实现上，我们定义了一个长度为 $5$ 的数组 $dirs=[1, -1, -1, 1, 1]$，每次取数组相邻两个元素作为 $k_1, k_2$ 的值，这样可以覆盖 $k_1, k_2 \in \{-1, 1\}$ 的所有情况。

时间复杂度 $O(n)$，其中 $n$ 是数组 $nums$ 的长度。空间复杂度 $O(1)$。

相似题目：

-   [1131. 绝对值表达式的最大值](https://github.com/doocs/leetcode/blob/main/solution/1100-1199/1131.Maximum%20of%20Absolute%20Value%20Expression/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxValueAfterReverse(self, nums: List[int]) -> int:
        ans = s = sum(abs(x - y) for x, y in pairwise(nums))
        for x, y in pairwise(nums):
            ans = max(ans, s + abs(nums[0] - y) - abs(x - y))
            ans = max(ans, s + abs(nums[-1] - x) - abs(x - y))
        for k1, k2 in pairwise((1, -1, -1, 1, 1)):
            mx, mi = -inf, inf
            for x, y in pairwise(nums):
                a = k1 * x + k2 * y
                b = abs(x - y)
                mx = max(mx, a - b)
                mi = min(mi, a + b)
            ans = max(ans, s + max(mx - mi, 0))
        return ans
```

#### Java

```java
class Solution {
    public int maxValueAfterReverse(int[] nums) {
        int n = nums.length;
        int s = 0;
        for (int i = 0; i < n - 1; ++i) {
            s += Math.abs(nums[i] - nums[i + 1]);
        }
        int ans = s;
        for (int i = 0; i < n - 1; ++i) {
            ans = Math.max(
                ans, s + Math.abs(nums[0] - nums[i + 1]) - Math.abs(nums[i] - nums[i + 1]));
            ans = Math.max(
                ans, s + Math.abs(nums[n - 1] - nums[i]) - Math.abs(nums[i] - nums[i + 1]));
        }
        int[] dirs = {1, -1, -1, 1, 1};
        final int inf = 1 << 30;
        for (int k = 0; k < 4; ++k) {
            int k1 = dirs[k], k2 = dirs[k + 1];
            int mx = -inf, mi = inf;
            for (int i = 0; i < n - 1; ++i) {
                int a = k1 * nums[i] + k2 * nums[i + 1];
                int b = Math.abs(nums[i] - nums[i + 1]);
                mx = Math.max(mx, a - b);
                mi = Math.min(mi, a + b);
            }
            ans = Math.max(ans, s + Math.max(0, mx - mi));
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxValueAfterReverse(vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        for (int i = 0; i < n - 1; ++i) {
            s += abs(nums[i] - nums[i + 1]);
        }
        int ans = s;
        for (int i = 0; i < n - 1; ++i) {
            ans = max(ans, s + abs(nums[0] - nums[i + 1]) - abs(nums[i] - nums[i + 1]));
            ans = max(ans, s + abs(nums[n - 1] - nums[i]) - abs(nums[i] - nums[i + 1]));
        }
        int dirs[5] = {1, -1, -1, 1, 1};
        const int inf = 1 << 30;
        for (int k = 0; k < 4; ++k) {
            int k1 = dirs[k], k2 = dirs[k + 1];
            int mx = -inf, mi = inf;
            for (int i = 0; i < n - 1; ++i) {
                int a = k1 * nums[i] + k2 * nums[i + 1];
                int b = abs(nums[i] - nums[i + 1]);
                mx = max(mx, a - b);
                mi = min(mi, a + b);
            }
            ans = max(ans, s + max(0, mx - mi));
        }
        return ans;
    }
};
```

#### Go

```go
func maxValueAfterReverse(nums []int) int {
	s, n := 0, len(nums)
	for i, x := range nums[:n-1] {
		y := nums[i+1]
		s += abs(x - y)
	}
	ans := s
	for i, x := range nums[:n-1] {
		y := nums[i+1]
		ans = max(ans, s+abs(nums[0]-y)-abs(x-y))
		ans = max(ans, s+abs(nums[n-1]-x)-abs(x-y))
	}
	dirs := [5]int{1, -1, -1, 1, 1}
	const inf = 1 << 30
	for k := 0; k < 4; k++ {
		k1, k2 := dirs[k], dirs[k+1]
		mx, mi := -inf, inf
		for i, x := range nums[:n-1] {
			y := nums[i+1]
			a := k1*x + k2*y
			b := abs(x - y)
			mx = max(mx, a-b)
			mi = min(mi, a+b)
		}
		ans = max(ans, s+max(mx-mi, 0))
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
function maxValueAfterReverse(nums: number[]): number {
    const n = nums.length;
    let s = 0;
    for (let i = 0; i < n - 1; ++i) {
        s += Math.abs(nums[i] - nums[i + 1]);
    }
    let ans = s;
    for (let i = 0; i < n - 1; ++i) {
        const d = Math.abs(nums[i] - nums[i + 1]);
        ans = Math.max(ans, s + Math.abs(nums[0] - nums[i + 1]) - d);
        ans = Math.max(ans, s + Math.abs(nums[n - 1] - nums[i]) - d);
    }
    const dirs = [1, -1, -1, 1, 1];
    const inf = 1 << 30;
    for (let k = 0; k < 4; ++k) {
        let mx = -inf;
        let mi = inf;
        for (let i = 0; i < n - 1; ++i) {
            const a = dirs[k] * nums[i] + dirs[k + 1] * nums[i + 1];
            const b = Math.abs(nums[i] - nums[i + 1]);
            mx = Math.max(mx, a - b);
            mi = Math.min(mi, a + b);
        }
        ans = Math.max(ans, s + Math.max(0, mx - mi));
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1331. 数组序号转换](https://leetcode.cn/problems/rank-transform-of-an-array){#1331}

{{< tabs "1331" >}}

{{% tab "python" %}}
```python
class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        t = sorted(set(arr))
        return [bisect_right(t, x) for x in arr]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] arrayRankTransform(int[] arr) {
        int n = arr.length;
        int[] t = arr.clone();
        Arrays.sort(t);
        int m = 0;
        for (int i = 0; i < n; ++i) {
            if (i == 0 || t[i] != t[i - 1]) {
                t[m++] = t[i];
            }
        }
        int[] ans = new int[n];
        for (int i = 0; i < n; ++i) {
            ans[i] = Arrays.binarySearch(t, 0, m, arr[i]) + 1;
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
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> t = arr;
        sort(t.begin(), t.end());
        t.erase(unique(t.begin(), t.end()), t.end());
        vector<int> ans;
        for (int x : arr) {
            ans.push_back(upper_bound(t.begin(), t.end(), x) - t.begin());
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func arrayRankTransform(arr []int) (ans []int) {
	t := make([]int, len(arr))
	copy(t, arr)
	sort.Ints(t)
	m := 0
	for i, x := range t {
		if i == 0 || x != t[i-1] {
			t[m] = x
			m++
		}
	}
	t = t[:m]
	for _, x := range arr {
		ans = append(ans, sort.SearchInts(t, x)+1)
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function arrayRankTransform(arr: number[]): number[] {
    const sorted = [...new Set(arr)].sort((a, b) => a - b);
    const map = new Map<number, number>();
    let c = 1;

    for (const x of sorted) {
        map.set(x, c++);
    }

    return arr.map(x => map.get(x)!);
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
function arrayRankTransform(arr) {
    const sorted = [...new Set(arr)].sort((a, b) => a - b);
    const map = new Map();
    let c = 1;

    for (const x of sorted) {
        map.set(x, c++);
    }

    return arr.map(x => map.get(x));
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组&nbsp;<code>arr</code> ，请你将数组中的每个元素替换为它们排序后的序号。</p>

<p>序号代表了一个元素有多大。序号编号的规则如下：</p>

<ul>
	<li>序号从 1 开始编号。</li>
	<li>一个元素越大，那么序号越大。如果两个元素相等，那么它们的序号相同。</li>
	<li>每个数字的序号都应该尽可能地小。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>arr = [40,10,20,30]
<strong>输出：</strong>[4,1,2,3]
<strong>解释：</strong>40 是最大的元素。 10 是最小的元素。 20 是第二小的数字。 30 是第三小的数字。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>arr = [100,100,100]
<strong>输出：</strong>[1,1,1]
<strong>解释：</strong>所有元素有相同的序号。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>arr = [37,12,28,9,100,56,80,5,12]
<strong>输出：</strong>[5,3,4,2,8,6,7,1,3]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= arr.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>9</sup>&nbsp;&lt;= arr[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：离散化

我们先复制一个数组 $t$，然后对其进行排序并去重，得到一个长度为 $m$ 且严格单调递增的数组。

然后我们遍历原数组 $arr$，对于其中的每个元素 $x$，我们利用二分查找得到 $x$ 在 $t$ 中的位置，那么该位置加一就是 $x$ 的排名。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 $arr$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        t = sorted(set(arr))
        return [bisect_right(t, x) for x in arr]
```

#### Java

```java
class Solution {
    public int[] arrayRankTransform(int[] arr) {
        int n = arr.length;
        int[] t = arr.clone();
        Arrays.sort(t);
        int m = 0;
        for (int i = 0; i < n; ++i) {
            if (i == 0 || t[i] != t[i - 1]) {
                t[m++] = t[i];
            }
        }
        int[] ans = new int[n];
        for (int i = 0; i < n; ++i) {
            ans[i] = Arrays.binarySearch(t, 0, m, arr[i]) + 1;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> t = arr;
        sort(t.begin(), t.end());
        t.erase(unique(t.begin(), t.end()), t.end());
        vector<int> ans;
        for (int x : arr) {
            ans.push_back(upper_bound(t.begin(), t.end(), x) - t.begin());
        }
        return ans;
    }
};
```

#### Go

```go
func arrayRankTransform(arr []int) (ans []int) {
	t := make([]int, len(arr))
	copy(t, arr)
	sort.Ints(t)
	m := 0
	for i, x := range t {
		if i == 0 || x != t[i-1] {
			t[m] = x
			m++
		}
	}
	t = t[:m]
	for _, x := range arr {
		ans = append(ans, sort.SearchInts(t, x)+1)
	}
	return
}
```

#### TypeScript

```ts
function arrayRankTransform(arr: number[]): number[] {
    const t = [...arr].sort((a, b) => a - b);
    let m = 0;
    for (let i = 0; i < t.length; ++i) {
        if (i === 0 || t[i] !== t[i - 1]) {
            t[m++] = t[i];
        }
    }
    const search = (t: number[], right: number, x: number) => {
        let left = 0;
        while (left < right) {
            const mid = (left + right) >> 1;
            if (t[mid] > x) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    };
    const ans: number[] = [];
    for (const x of arr) {
        ans.push(search(t, m, x));
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：排序 + 哈希表

<!-- tabs:start -->

#### TypeScript

```ts
function arrayRankTransform(arr: number[]): number[] {
    const sorted = [...new Set(arr)].sort((a, b) => a - b);
    const map = new Map<number, number>();
    let c = 1;

    for (const x of sorted) {
        map.set(x, c++);
    }

    return arr.map(x => map.get(x)!);
}
```

#### JavaScript

```js
function arrayRankTransform(arr) {
    const sorted = [...new Set(arr)].sort((a, b) => a - b);
    const map = new Map();
    let c = 1;

    for (const x of sorted) {
        map.set(x, c++);
    }

    return arr.map(x => map.get(x));
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1332. 删除回文子序列](https://leetcode.cn/problems/remove-palindromic-subsequences){#1332}

{{< tabs "1332" >}}

{{% tab "python" %}}
```python
class Solution:
    def removePalindromeSub(self, s: str) -> int:
        return 1 if s[::-1] == s else 2
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int removePalindromeSub(String s) {
        for (int i = 0, j = s.length() - 1; i < j; ++i, --j) {
            if (s.charAt(i) != s.charAt(j)) {
                return 2;
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
    int removePalindromeSub(string s) {
        for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
            if (s[i] != s[j]) {
                return 2;
            }
        }
        return 1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func removePalindromeSub(s string) int {
	for i, j := 0, len(s)-1; i < j; i, j = i+1, j-1 {
		if s[i] != s[j] {
			return 2
		}
	}
	return 1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function removePalindromeSub(s: string): number {
    for (let i = 0, j = s.length - 1; i < j; ++i, --j) {
        if (s[i] !== s[j]) {
            return 2;
        }
    }
    return 1;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn remove_palindrome_sub(s: String) -> i32 {
        let mut l = 0;
        let mut r = s.len() - 1;
        let s: Vec<char> = s.chars().collect();
        while l < r {
            if s[l] != s[r] {
                return 2;
            }
            l += 1;
            r -= 1;
        }
        1
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串&nbsp;<code>s</code>，它仅由字母&nbsp;<code>'a'</code> 和 <code>'b'</code>&nbsp;组成。每一次删除操作都可以从 <code>s</code> 中删除一个回文 <strong>子序列</strong>。</p>

<p>返回删除给定字符串中所有字符（字符串为空）的最小删除次数。</p>

<p>「子序列」定义：如果一个字符串可以通过删除原字符串某些字符而不改变原字符顺序得到，那么这个字符串就是原字符串的一个子序列。</p>

<p>「回文」定义：如果一个字符串向后和向前读是一致的，那么这个字符串就是一个回文。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "ababa"
<strong>输出：</strong>1
<strong>解释：</strong>字符串本身就是回文序列，只需要删除一次。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "abb"
<strong>输出：</strong>2
<strong>解释：</strong>"<strong>a</strong>bb" -&gt; "<strong>bb</strong>" -&gt; "". 
先删除回文子序列 "a"，然后再删除 "bb"。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "baabb"
<strong>输出：</strong>2
<strong>解释：</strong>"<strong>baa</strong>b<strong>b</strong>" -&gt; "b" -&gt; "". 
先删除回文子序列 "baab"，然后再删除 "b"。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s</code> 仅包含字母&nbsp;<code>'a'</code>&nbsp; 和 <code>'b'</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：脑筋急转弯

如果字符串 $s$ 本身是个回文串，那么只需要删除 $1$ 次。

如果字符串 $s$ 不是个回文串，那么先删除所有的 `'a'`，再删除所有的 `'b'`，总共需要删除 $2$ 次。

时间复杂度 $O(n)$，其中 $n$ 是字符串 $s$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def removePalindromeSub(self, s: str) -> int:
        return 1 if s[::-1] == s else 2
```

#### Java

```java
class Solution {
    public int removePalindromeSub(String s) {
        for (int i = 0, j = s.length() - 1; i < j; ++i, --j) {
            if (s.charAt(i) != s.charAt(j)) {
                return 2;
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
    int removePalindromeSub(string s) {
        for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
            if (s[i] != s[j]) {
                return 2;
            }
        }
        return 1;
    }
};
```

#### Go

```go
func removePalindromeSub(s string) int {
	for i, j := 0, len(s)-1; i < j; i, j = i+1, j-1 {
		if s[i] != s[j] {
			return 2
		}
	}
	return 1
}
```

#### TypeScript

```ts
function removePalindromeSub(s: string): number {
    for (let i = 0, j = s.length - 1; i < j; ++i, --j) {
        if (s[i] !== s[j]) {
            return 2;
        }
    }
    return 1;
}
```

#### Rust

```rust
impl Solution {
    pub fn remove_palindrome_sub(s: String) -> i32 {
        let mut l = 0;
        let mut r = s.len() - 1;
        let s: Vec<char> = s.chars().collect();
        while l < r {
            if s[l] != s[r] {
                return 2;
            }
            l += 1;
            r -= 1;
        }
        1
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1333. 餐厅过滤器](https://leetcode.cn/problems/filter-restaurants-by-vegan-friendly-price-and-distance){#1333}

{{< tabs "1333" >}}

{{% tab "python" %}}
```python
class Solution:
    def filterRestaurants(
        self,
        restaurants: List[List[int]],
        veganFriendly: int,
        maxPrice: int,
        maxDistance: int,
    ) -> List[int]:
        restaurants.sort(key=lambda x: (-x[1], -x[0]))
        ans = []
        for idx, _, vegan, price, dist in restaurants:
            if vegan >= veganFriendly and price <= maxPrice and dist <= maxDistance:
                ans.append(idx)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<Integer> filterRestaurants(
        int[][] restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        Arrays.sort(restaurants, (a, b) -> a[1] == b[1] ? b[0] - a[0] : b[1] - a[1]);
        List<Integer> ans = new ArrayList<>();
        for (int[] r : restaurants) {
            if (r[2] >= veganFriendly && r[3] <= maxPrice && r[4] <= maxDistance) {
                ans.add(r[0]);
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
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        sort(restaurants.begin(), restaurants.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[1] != b[1]) {
                return a[1] > b[1];
            }
            return a[0] > b[0];
        });
        vector<int> ans;
        for (auto& r : restaurants) {
            if (r[2] >= veganFriendly && r[3] <= maxPrice && r[4] <= maxDistance) {
                ans.push_back(r[0]);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func filterRestaurants(restaurants [][]int, veganFriendly int, maxPrice int, maxDistance int) (ans []int) {
	sort.Slice(restaurants, func(i, j int) bool {
		a, b := restaurants[i], restaurants[j]
		if a[1] != b[1] {
			return a[1] > b[1]
		}
		return a[0] > b[0]
	})
	for _, r := range restaurants {
		if r[2] >= veganFriendly && r[3] <= maxPrice && r[4] <= maxDistance {
			ans = append(ans, r[0])
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function filterRestaurants(
    restaurants: number[][],
    veganFriendly: number,
    maxPrice: number,
    maxDistance: number,
): number[] {
    restaurants.sort((a, b) => (a[1] === b[1] ? b[0] - a[0] : b[1] - a[1]));
    const ans: number[] = [];
    for (const [id, _, vegan, price, distance] of restaurants) {
        if (vegan >= veganFriendly && price <= maxPrice && distance <= maxDistance) {
            ans.push(id);
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

<p>给你一个餐馆信息数组&nbsp;<code>restaurants</code>，其中&nbsp;&nbsp;<code>restaurants[i] = [id<sub>i</sub>, rating<sub>i</sub>, veganFriendly<sub>i</sub>, price<sub>i</sub>, distance<sub>i</sub>]</code>。你必须使用以下三个过滤器来过滤这些餐馆信息。</p>

<p>其中素食者友好过滤器&nbsp;<code>veganFriendly</code>&nbsp;的值可以为 <code>true</code> 或者 <code>false</code>，如果为 <em>true</em>&nbsp;就意味着你应该只包括&nbsp;<code>veganFriendly<sub>i</sub></code>&nbsp;为 true 的餐馆，为&nbsp;<em>false</em>&nbsp;则意味着可以包括任何餐馆。此外，我们还有最大价格&nbsp;<code>maxPrice</code>&nbsp;和最大距离&nbsp;<code>maxDistance</code>&nbsp;两个过滤器，它们分别考虑餐厅的价格因素和距离因素的最大值。</p>

<p>过滤后返回餐馆的 <strong><em>id</em></strong>，按照 <em><strong>rating</strong></em>&nbsp;从高到低排序。如果 <em><strong>rating</strong></em> 相同，那么按 <em><strong>id</strong></em> 从高到低排序。简单起见，&nbsp;<code>veganFriendly<sub>i</sub></code> 和 <code>veganFriendly</code>&nbsp;为&nbsp;<em>true</em>&nbsp;时取值为 <em>1</em>，为 <em>false</em> 时，取值为&nbsp;<em>0 。</em></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>restaurants = [[1,4,1,40,10],[2,8,0,50,5],[3,8,1,30,4],[4,10,0,10,3],[5,1,1,15,1]], veganFriendly = 1, maxPrice = 50, maxDistance = 10
<strong>输出：</strong>[3,1,5] 
<strong>解释： 
</strong>这些餐馆为：
餐馆 1 [id=1, rating=4, veganFriendly=1, price=40, distance=10]
餐馆 2 [id=2, rating=8, veganFriendly=0, price=50, distance=5]
餐馆 3 [id=3, rating=8, veganFriendly=1, price=30, distance=4]
餐馆 4 [id=4, rating=10, veganFriendly=0, price=10, distance=3]
餐馆 5 [id=5, rating=1, veganFriendly=1, price=15, distance=1] 
在按照 veganFriendly = 1, maxPrice = 50 和 maxDistance = 10 进行过滤后，我们得到了餐馆 3, 餐馆 1 和 餐馆 5（按评分从高到低排序）。 
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>restaurants = [[1,4,1,40,10],[2,8,0,50,5],[3,8,1,30,4],[4,10,0,10,3],[5,1,1,15,1]], veganFriendly = 0, maxPrice = 50, maxDistance = 10
<strong>输出：</strong>[4,3,2,1,5]
<strong>解释：</strong>餐馆与示例 1 相同，但在 veganFriendly = 0 的过滤条件下，应该考虑所有餐馆。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>restaurants = [[1,4,1,40,10],[2,8,0,50,5],[3,8,1,30,4],[4,10,0,10,3],[5,1,1,15,1]], veganFriendly = 0, maxPrice = 30, maxDistance = 3
<strong>输出：</strong>[4,5]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;=&nbsp;restaurants.length &lt;= 10^4</code></li>
	<li><code>restaurants[i].length == 5</code></li>
	<li><code>1 &lt;=&nbsp;id<sub>i</sub>, rating<sub>i</sub>, price<sub>i</sub>, distance<sub>i </sub>&lt;= 10^5</code></li>
	<li><code>1 &lt;=&nbsp;maxPrice,&nbsp;maxDistance &lt;= 10^5</code></li>
	<li><code>veganFriendly<sub>i</sub></code> 和&nbsp;<code>veganFriendly</code>&nbsp;的值为 0 或 1 。</li>
	<li>所有 <code>id<sub>i</sub></code> 各不相同。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序

我们先将数组 `restaurants` 按照 `rating` 和 `id` 两个维度进行排序，然后再按照题目给定的条件进行筛选即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 是数组 `restaurants` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def filterRestaurants(
        self,
        restaurants: List[List[int]],
        veganFriendly: int,
        maxPrice: int,
        maxDistance: int,
    ) -> List[int]:
        restaurants.sort(key=lambda x: (-x[1], -x[0]))
        ans = []
        for idx, _, vegan, price, dist in restaurants:
            if vegan >= veganFriendly and price <= maxPrice and dist <= maxDistance:
                ans.append(idx)
        return ans
```

#### Java

```java
class Solution {
    public List<Integer> filterRestaurants(
        int[][] restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        Arrays.sort(restaurants, (a, b) -> a[1] == b[1] ? b[0] - a[0] : b[1] - a[1]);
        List<Integer> ans = new ArrayList<>();
        for (int[] r : restaurants) {
            if (r[2] >= veganFriendly && r[3] <= maxPrice && r[4] <= maxDistance) {
                ans.add(r[0]);
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
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        sort(restaurants.begin(), restaurants.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[1] != b[1]) {
                return a[1] > b[1];
            }
            return a[0] > b[0];
        });
        vector<int> ans;
        for (auto& r : restaurants) {
            if (r[2] >= veganFriendly && r[3] <= maxPrice && r[4] <= maxDistance) {
                ans.push_back(r[0]);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func filterRestaurants(restaurants [][]int, veganFriendly int, maxPrice int, maxDistance int) (ans []int) {
	sort.Slice(restaurants, func(i, j int) bool {
		a, b := restaurants[i], restaurants[j]
		if a[1] != b[1] {
			return a[1] > b[1]
		}
		return a[0] > b[0]
	})
	for _, r := range restaurants {
		if r[2] >= veganFriendly && r[3] <= maxPrice && r[4] <= maxDistance {
			ans = append(ans, r[0])
		}
	}
	return
}
```

#### TypeScript

```ts
function filterRestaurants(
    restaurants: number[][],
    veganFriendly: number,
    maxPrice: number,
    maxDistance: number,
): number[] {
    restaurants.sort((a, b) => (a[1] === b[1] ? b[0] - a[0] : b[1] - a[1]));
    const ans: number[] = [];
    for (const [id, _, vegan, price, distance] of restaurants) {
        if (vegan >= veganFriendly && price <= maxPrice && distance <= maxDistance) {
            ans.push(id);
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

# [1334. 阈值距离内邻居最少的城市](https://leetcode.cn/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance){#1334}

{{< tabs "1334" >}}

{{% tab "python" %}}
```python
class Solution:
    def findTheCity(
        self, n: int, edges: List[List[int]], distanceThreshold: int
    ) -> int:
        g = [[inf] * n for _ in range(n)]
        for f, t, w in edges:
            g[f][t] = g[t][f] = w

        for k in range(n):
            g[k][k] = 0
            for i in range(n):
                for j in range(n):
                    # g[i][j] = min(g[i][j], g[i][k] + g[k][j])
                    if g[i][k] + g[k][j] < g[i][j]:
                        g[i][j] = g[i][k] + g[k][j]

        ans, cnt = n, inf
        for i in range(n - 1, -1, -1):
            t = sum(d <= distanceThreshold for d in g[i])
            if t < cnt:
                cnt, ans = t, i
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int findTheCity(int n, int[][] edges, int distanceThreshold) {
        final int inf = 1 << 29;
        int[][] g = new int[n][n];
        for (var e : g) {
            Arrays.fill(e, inf);
        }
        for (var e : edges) {
            int f = e[0], t = e[1], w = e[2];
            g[f][t] = w;
            g[t][f] = w;
        }
        for (int k = 0; k < n; ++k) {
            g[k][k] = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    g[i][j] = Math.min(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }
        int ans = n, cnt = inf;
        for (int i = n - 1; i >= 0; --i) {
            int t = 0;
            for (int d : g[i]) {
                if (d <= distanceThreshold) {
                    ++t;
                }
            }
            if (t < cnt) {
                cnt = t;
                ans = i;
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
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int g[n][n];
        memset(g, 0x3f, sizeof(g));
        for (auto& e : edges) {
            int f = e[0], t = e[1], w = e[2];
            g[f][t] = g[t][f] = w;
        }
        for (int k = 0; k < n; ++k) {
            g[k][k] = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }
        int ans = n, cnt = n + 1;
        for (int i = n - 1; ~i; --i) {
            int t = count_if(g[i], g[i] + n, [&](int x) { return x <= distanceThreshold; });
            if (t < cnt) {
                cnt = t;
                ans = i;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findTheCity(n int, edges [][]int, distanceThreshold int) int {
	g := make([][]int, n)
	const inf int = 1e7
	for i := range g {
		g[i] = make([]int, n)
		for j := range g[i] {
			g[i][j] = inf
		}
	}

	for _, e := range edges {
		f, t, w := e[0], e[1], e[2]
		g[f][t], g[t][f] = w, w
	}

	for k := 0; k < n; k++ {
		g[k][k] = 0
		for i := 0; i < n; i++ {
			for j := 0; j < n; j++ {
				g[i][j] = min(g[i][j], g[i][k]+g[k][j])
			}
		}
	}

	ans, cnt := n, n+1
	for i := n - 1; i >= 0; i-- {
		t := 0
		for _, x := range g[i] {
			if x <= distanceThreshold {
				t++
			}
		}
		if t < cnt {
			cnt, ans = t, i
		}
	}

	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findTheCity(n: number, edges: number[][], distanceThreshold: number): number {
    const MAX = Number.POSITIVE_INFINITY;
    const g = Array.from({ length: n }, () => new Map<number, number>());
    const dist: number[] = Array(n).fill(MAX);
    const vis: boolean[] = Array(n).fill(false);
    for (const [f, t, w] of edges) {
        g[f].set(t, w);
        g[t].set(f, w);
    }

    const dijkstra = (u: number): number => {
        dist.fill(MAX);
        vis.fill(false);
        dist[u] = 0;
        const pq = new MinPriorityQueue();
        pq.enqueue(u, 0);

        while (!pq.isEmpty()) {
            const u = pq.dequeue().element;
            if (vis[u]) continue;
            vis[u] = true;

            for (const [v, w] of g[u]) {
                if (vis[v]) continue;

                const wNext = dist[u] + w;
                if (wNext < dist[v]) {
                    dist[v] = wNext;
                    pq.enqueue(v, dist[v]);
                }
            }
        }

        return dist.filter(d => d <= distanceThreshold).length;
    };

    let ans = n;
    let cnt = MAX;
    for (let i = n - 1; i >= 0; --i) {
        const t = dijkstra(i);
        if (t < cnt) {
            cnt = t;
            ans = i;
        }
    }

    return ans;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
export function findTheCity(n, edges, distanceThreshold) {
    const MAX = Number.POSITIVE_INFINITY;
    const g = Array.from({ length: n }, () => new Map());
    const dist = Array(n).fill(MAX);
    const vis = Array(n).fill(false);
    for (const [f, t, w] of edges) {
        g[f].set(t, w);
        g[t].set(f, w);
    }

    const dijkstra = u => {
        dist.fill(MAX);
        vis.fill(false);
        dist[u] = 0;
        const pq = new MinPriorityQueue();
        pq.enqueue(u, 0);

        while (!pq.isEmpty()) {
            const u = pq.dequeue().element;
            if (vis[u]) continue;
            vis[u] = true;

            for (const [v, w] of g[u]) {
                if (vis[v]) continue;

                const wNext = dist[u] + w;
                if (wNext < dist[v]) {
                    dist[v] = wNext;
                    pq.enqueue(v, dist[v]);
                }
            }
        }

        return dist.filter(d => d <= distanceThreshold).length;
    };

    let ans = n;
    let cnt = MAX;
    for (let i = n - 1; i >= 0; --i) {
        const t = dijkstra(i);
        if (t < cnt) {
            cnt = t;
            ans = i;
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

<p>有 <code>n</code>&nbsp;个城市，按从 <code>0</code> 到 <code>n-1</code>&nbsp;编号。给你一个边数组&nbsp;<code>edges</code>，其中 <code>edges[i] = [from<sub>i</sub>, to<sub>i</sub>, weight<sub>i</sub>]</code>&nbsp;代表&nbsp;<code>from<sub>i</sub></code>&nbsp;和&nbsp;<code>to<sub>i</sub></code><sub>&nbsp;</sub>两个城市之间的双向加权边，距离阈值是一个整数&nbsp;<code>distanceThreshold</code>。</p>

<p>返回在路径距离限制为 <code>distanceThreshold</code> 以内可到达城市最少的城市。如果有多个这样的城市，则返回编号最大的城市。</p>

<p>注意，连接城市 <em><strong>i</strong></em> 和 <em><strong>j</strong></em> 的路径的距离等于沿该路径的所有边的权重之和。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1300-1399/1334.Find%20the%20City%20With%20the%20Smallest%20Number%20of%20Neighbors%20at%20a%20Threshold%20Distance/images/problem1334example1.png" style="width: 300px; height: 224px;" /></p>

<pre>
<strong>输入：</strong>n = 4, edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]], distanceThreshold = 4
<strong>输出：</strong>3
<strong>解释：</strong>城市分布图如上。
每个城市阈值距离 distanceThreshold = 4 内的邻居城市分别是：
城市 0 -&gt; [城市 1, 城市 2]&nbsp;
城市 1 -&gt; [城市 0, 城市 2, 城市 3]&nbsp;
城市 2 -&gt; [城市 0, 城市 1, 城市 3]&nbsp;
城市 3 -&gt; [城市 1, 城市 2]&nbsp;
城市 0 和 3 在阈值距离 4 以内都有 2 个邻居城市，但是我们必须返回城市 3，因为它的编号最大。
</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1300-1399/1334.Find%20the%20City%20With%20the%20Smallest%20Number%20of%20Neighbors%20at%20a%20Threshold%20Distance/images/problem1334example0.png" style="width: 300px; height: 224px;" /></strong></p>

<pre>
<strong>输入：</strong>n = 5, edges = [[0,1,2],[0,4,8],[1,2,3],[1,4,2],[2,3,1],[3,4,1]], distanceThreshold = 2
<strong>输出：</strong>0
<strong>解释：</strong>城市分布图如上。&nbsp;
每个城市阈值距离 distanceThreshold = 2 内的邻居城市分别是：
城市 0 -&gt; [城市 1]&nbsp;
城市 1 -&gt; [城市 0, 城市 4]&nbsp;
城市 2 -&gt; [城市 3, 城市 4]&nbsp;
城市 3 -&gt; [城市 2, 城市 4]
城市 4 -&gt; [城市 1, 城市 2, 城市 3]&nbsp;
城市 0 在阈值距离 2 以内只有 1 个邻居城市。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 100</code></li>
	<li><code>1 &lt;= edges.length &lt;= n * (n - 1) / 2</code></li>
	<li><code>edges[i].length == 3</code></li>
	<li><code>0 &lt;= from<sub>i</sub> &lt; to<sub>i</sub> &lt; n</code></li>
	<li><code>1 &lt;= weight<sub>i</sub>,&nbsp;distanceThreshold &lt;= 10^4</code></li>
	<li>所有 <code>(from<sub>i</sub>, to<sub>i</sub>)</code>&nbsp;都是不同的。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：Dijkstra 算法

我们可以枚举每个城市 $i$ 作为起点，使用 Dijkstra 算法求出从 $i$ 到其他城市的最短距离，然后统计距离不超过阈值的城市个数，最后取最小的个数且编号最大的城市。

时间复杂度 $O(n^3)$，空间复杂度 $O(n^2)$。其中 $n$ 为城市个数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findTheCity(
        self, n: int, edges: List[List[int]], distanceThreshold: int
    ) -> int:
        def dijkstra(u: int) -> int:
            dist = [inf] * n
            dist[u] = 0
            vis = [False] * n
            for _ in range(n):
                k = -1
                for j in range(n):
                    if not vis[j] and (k == -1 or dist[k] > dist[j]):
                        k = j
                vis[k] = True
                for j in range(n):
                    # dist[j] = min(dist[j], dist[k] + g[k][j])
                    if dist[k] + g[k][j] < dist[j]:
                        dist[j] = dist[k] + g[k][j]
            return sum(d <= distanceThreshold for d in dist)

        g = [[inf] * n for _ in range(n)]
        for f, t, w in edges:
            g[f][t] = g[t][f] = w
        ans, cnt = n, inf
        for i in range(n - 1, -1, -1):
            if (t := dijkstra(i)) < cnt:
                cnt, ans = t, i
        return ans
```

#### Java

```java
class Solution {
    private int n;
    private int[][] g;
    private int[] dist;
    private boolean[] vis;
    private final int inf = 1 << 30;
    private int distanceThreshold;

    public int findTheCity(int n, int[][] edges, int distanceThreshold) {
        this.n = n;
        this.distanceThreshold = distanceThreshold;
        g = new int[n][n];
        dist = new int[n];
        vis = new boolean[n];
        for (var e : g) {
            Arrays.fill(e, inf);
        }
        for (var e : edges) {
            int f = e[0], t = e[1], w = e[2];
            g[f][t] = w;
            g[t][f] = w;
        }
        int ans = n, cnt = inf;
        for (int i = n - 1; i >= 0; --i) {
            int t = dijkstra(i);
            if (t < cnt) {
                cnt = t;
                ans = i;
            }
        }
        return ans;
    }

    private int dijkstra(int u) {
        Arrays.fill(dist, inf);
        Arrays.fill(vis, false);
        dist[u] = 0;
        for (int i = 0; i < n; ++i) {
            int k = -1;
            for (int j = 0; j < n; ++j) {
                if (!vis[j] && (k == -1 || dist[k] > dist[j])) {
                    k = j;
                }
            }
            vis[k] = true;
            for (int j = 0; j < n; ++j) {
                dist[j] = Math.min(dist[j], dist[k] + g[k][j]);
            }
        }
        int cnt = 0;
        for (int d : dist) {
            if (d <= distanceThreshold) {
                ++cnt;
            }
        }
        return cnt;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int g[n][n];
        int dist[n];
        bool vis[n];
        memset(g, 0x3f, sizeof(g));
        for (auto& e : edges) {
            int f = e[0], t = e[1], w = e[2];
            g[f][t] = g[t][f] = w;
        }
        auto dijkstra = [&](int u) {
            memset(dist, 0x3f, sizeof(dist));
            memset(vis, 0, sizeof(vis));
            dist[u] = 0;
            for (int i = 0; i < n; ++i) {
                int k = -1;
                for (int j = 0; j < n; ++j) {
                    if (!vis[j] && (k == -1 || dist[j] < dist[k])) {
                        k = j;
                    }
                }
                vis[k] = true;
                for (int j = 0; j < n; ++j) {
                    dist[j] = min(dist[j], dist[k] + g[k][j]);
                }
            }
            return count_if(dist, dist + n, [&](int d) { return d <= distanceThreshold; });
        };
        int ans = n, cnt = n + 1;
        for (int i = n - 1; ~i; --i) {
            int t = dijkstra(i);
            if (t < cnt) {
                cnt = t;
                ans = i;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func findTheCity(n int, edges [][]int, distanceThreshold int) int {
	g := make([][]int, n)
	dist := make([]int, n)
	vis := make([]bool, n)
	const inf int = 1e7
	for i := range g {
		g[i] = make([]int, n)
		for j := range g[i] {
			g[i][j] = inf
		}
	}
	for _, e := range edges {
		f, t, w := e[0], e[1], e[2]
		g[f][t], g[t][f] = w, w
	}

	dijkstra := func(u int) (cnt int) {
		for i := range vis {
			vis[i] = false
			dist[i] = inf
		}
		dist[u] = 0
		for i := 0; i < n; i++ {
			k := -1
			for j := 0; j < n; j++ {
				if !vis[j] && (k == -1 || dist[j] < dist[k]) {
					k = j
				}
			}
			vis[k] = true
			for j := 0; j < n; j++ {
				dist[j] = min(dist[j], dist[k]+g[k][j])
			}
		}
		for _, d := range dist {
			if d <= distanceThreshold {
				cnt++
			}
		}
		return
	}

	ans, cnt := n, inf
	for i := n - 1; i >= 0; i-- {
		if t := dijkstra(i); t < cnt {
			cnt = t
			ans = i
		}
	}
	return ans
}
```

#### TypeScript

```ts
function findTheCity(n: number, edges: number[][], distanceThreshold: number): number {
    const g: number[][] = Array.from({ length: n }, () => Array(n).fill(Infinity));
    const dist: number[] = Array(n).fill(Infinity);
    const vis: boolean[] = Array(n).fill(false);
    for (const [f, t, w] of edges) {
        g[f][t] = g[t][f] = w;
    }

    const dijkstra = (u: number): number => {
        dist.fill(Infinity);
        vis.fill(false);
        dist[u] = 0;
        for (let i = 0; i < n; ++i) {
            let k = -1;
            for (let j = 0; j < n; ++j) {
                if (!vis[j] && (k === -1 || dist[j] < dist[k])) {
                    k = j;
                }
            }
            vis[k] = true;
            for (let j = 0; j < n; ++j) {
                dist[j] = Math.min(dist[j], dist[k] + g[k][j]);
            }
        }
        return dist.filter(d => d <= distanceThreshold).length;
    };

    let ans = n;
    let cnt = Infinity;
    for (let i = n - 1; i >= 0; --i) {
        const t = dijkstra(i);
        if (t < cnt) {
            cnt = t;
            ans = i;
        }
    }

    return ans;
}
```

#### JavaScript

```js
function findTheCity(n, edges, distanceThreshold) {
    const g = Array.from({ length: n }, () => Array(n).fill(Infinity));
    const dist = Array(n).fill(Infinity);
    const vis = Array(n).fill(false);
    for (const [f, t, w] of edges) {
        g[f][t] = g[t][f] = w;
    }

    const dijkstra = u => {
        dist.fill(Infinity);
        vis.fill(false);
        dist[u] = 0;
        for (let i = 0; i < n; ++i) {
            let k = -1;
            for (let j = 0; j < n; ++j) {
                if (!vis[j] && (k === -1 || dist[j] < dist[k])) {
                    k = j;
                }
            }
            vis[k] = true;
            for (let j = 0; j < n; ++j) {
                dist[j] = Math.min(dist[j], dist[k] + g[k][j]);
            }
        }
        return dist.filter(d => d <= distanceThreshold).length;
    };

    let ans = n;
    let cnt = Infinity;
    for (let i = n - 1; i >= 0; --i) {
        const t = dijkstra(i);
        if (t < cnt) {
            cnt = t;
            ans = i;
        }
    }

    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：Floyd 算法

我们定义 $g[i][j]$ 表示城市 $i$ 到城市 $j$ 的最短距离，初始时 $g[i][j] = \infty$, $g[i][i] = 0$，然后我们遍历所有边，对于每条边 $(f, t, w)$，我们令 $g[f][t] = g[t][f] = w$。

接下来，我们用 Floyd 算法求出任意两点之间的最短距离。具体地，我们先枚举中间点 $k$，再枚举起点 $i$ 和终点 $j$，如果 $g[i][k] + g[k][j] \lt g[i][j]$，那么我们就用更短的距离 $g[i][k] + g[k][j]$ 更新 $g[i][j]$。

最后，我们枚举每个城市 $i$ 作为起点，统计距离不超过阈值的城市个数，最后取最小的个数且编号最大的城市。

时间复杂度 $O(n^3)$，空间复杂度 $O(n^2)$。其中 $n$ 为城市个数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findTheCity(
        self, n: int, edges: List[List[int]], distanceThreshold: int
    ) -> int:
        g = [[inf] * n for _ in range(n)]
        for f, t, w in edges:
            g[f][t] = g[t][f] = w

        for k in range(n):
            g[k][k] = 0
            for i in range(n):
                for j in range(n):
                    # g[i][j] = min(g[i][j], g[i][k] + g[k][j])
                    if g[i][k] + g[k][j] < g[i][j]:
                        g[i][j] = g[i][k] + g[k][j]

        ans, cnt = n, inf
        for i in range(n - 1, -1, -1):
            t = sum(d <= distanceThreshold for d in g[i])
            if t < cnt:
                cnt, ans = t, i
        return ans
```

#### Java

```java
class Solution {
    public int findTheCity(int n, int[][] edges, int distanceThreshold) {
        final int inf = 1 << 29;
        int[][] g = new int[n][n];
        for (var e : g) {
            Arrays.fill(e, inf);
        }
        for (var e : edges) {
            int f = e[0], t = e[1], w = e[2];
            g[f][t] = w;
            g[t][f] = w;
        }
        for (int k = 0; k < n; ++k) {
            g[k][k] = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    g[i][j] = Math.min(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }
        int ans = n, cnt = inf;
        for (int i = n - 1; i >= 0; --i) {
            int t = 0;
            for (int d : g[i]) {
                if (d <= distanceThreshold) {
                    ++t;
                }
            }
            if (t < cnt) {
                cnt = t;
                ans = i;
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
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int g[n][n];
        memset(g, 0x3f, sizeof(g));
        for (auto& e : edges) {
            int f = e[0], t = e[1], w = e[2];
            g[f][t] = g[t][f] = w;
        }
        for (int k = 0; k < n; ++k) {
            g[k][k] = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }
        int ans = n, cnt = n + 1;
        for (int i = n - 1; ~i; --i) {
            int t = count_if(g[i], g[i] + n, [&](int x) { return x <= distanceThreshold; });
            if (t < cnt) {
                cnt = t;
                ans = i;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func findTheCity(n int, edges [][]int, distanceThreshold int) int {
	g := make([][]int, n)
	const inf int = 1e7
	for i := range g {
		g[i] = make([]int, n)
		for j := range g[i] {
			g[i][j] = inf
		}
	}

	for _, e := range edges {
		f, t, w := e[0], e[1], e[2]
		g[f][t], g[t][f] = w, w
	}

	for k := 0; k < n; k++ {
		g[k][k] = 0
		for i := 0; i < n; i++ {
			for j := 0; j < n; j++ {
				g[i][j] = min(g[i][j], g[i][k]+g[k][j])
			}
		}
	}

	ans, cnt := n, n+1
	for i := n - 1; i >= 0; i-- {
		t := 0
		for _, x := range g[i] {
			if x <= distanceThreshold {
				t++
			}
		}
		if t < cnt {
			cnt, ans = t, i
		}
	}

	return ans
}
```

#### TypeScript

```ts
function findTheCity(n: number, edges: number[][], distanceThreshold: number): number {
    const g: number[][] = Array.from({ length: n }, () => Array(n).fill(Infinity));
    for (const [f, t, w] of edges) {
        g[f][t] = g[t][f] = w;
    }
    for (let k = 0; k < n; ++k) {
        g[k][k] = 0;
        for (let i = 0; i < n; ++i) {
            for (let j = 0; j < n; ++j) {
                g[i][j] = Math.min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }

    let ans = n,
        cnt = n + 1;
    for (let i = n - 1; i >= 0; --i) {
        const t = g[i].filter(x => x <= distanceThreshold).length;
        if (t < cnt) {
            cnt = t;
            ans = i;
        }
    }
    return ans;
}
```

#### JavaScript

```js
function findTheCity(n, edges, distanceThreshold) {
    const g = Array.from({ length: n }, () => Array(n).fill(Infinity));
    for (const [f, t, w] of edges) {
        g[f][t] = g[t][f] = w;
    }
    for (let k = 0; k < n; ++k) {
        g[k][k] = 0;
        for (let i = 0; i < n; ++i) {
            for (let j = 0; j < n; ++j) {
                g[i][j] = Math.min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }

    let ans = n,
        cnt = n + 1;
    for (let i = n - 1; i >= 0; --i) {
        const t = g[i].filter(x => x <= distanceThreshold).length;
        if (t < cnt) {
            cnt = t;
            ans = i;
        }
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### Solution 3

<!-- tabs:start -->

#### TypeScript

```ts
function findTheCity(n: number, edges: number[][], distanceThreshold: number): number {
    const MAX = Number.POSITIVE_INFINITY;
    const g = Array.from({ length: n }, () => new Map<number, number>());
    const dist: number[] = Array(n).fill(MAX);
    const vis: boolean[] = Array(n).fill(false);
    for (const [f, t, w] of edges) {
        g[f].set(t, w);
        g[t].set(f, w);
    }

    const dijkstra = (u: number): number => {
        dist.fill(MAX);
        vis.fill(false);
        dist[u] = 0;
        const pq = new MinPriorityQueue();
        pq.enqueue(u, 0);

        while (!pq.isEmpty()) {
            const u = pq.dequeue().element;
            if (vis[u]) continue;
            vis[u] = true;

            for (const [v, w] of g[u]) {
                if (vis[v]) continue;

                const wNext = dist[u] + w;
                if (wNext < dist[v]) {
                    dist[v] = wNext;
                    pq.enqueue(v, dist[v]);
                }
            }
        }

        return dist.filter(d => d <= distanceThreshold).length;
    };

    let ans = n;
    let cnt = MAX;
    for (let i = n - 1; i >= 0; --i) {
        const t = dijkstra(i);
        if (t < cnt) {
            cnt = t;
            ans = i;
        }
    }

    return ans;
}
```

#### JavaScript

```js
export function findTheCity(n, edges, distanceThreshold) {
    const MAX = Number.POSITIVE_INFINITY;
    const g = Array.from({ length: n }, () => new Map());
    const dist = Array(n).fill(MAX);
    const vis = Array(n).fill(false);
    for (const [f, t, w] of edges) {
        g[f].set(t, w);
        g[t].set(f, w);
    }

    const dijkstra = u => {
        dist.fill(MAX);
        vis.fill(false);
        dist[u] = 0;
        const pq = new MinPriorityQueue();
        pq.enqueue(u, 0);

        while (!pq.isEmpty()) {
            const u = pq.dequeue().element;
            if (vis[u]) continue;
            vis[u] = true;

            for (const [v, w] of g[u]) {
                if (vis[v]) continue;

                const wNext = dist[u] + w;
                if (wNext < dist[v]) {
                    dist[v] = wNext;
                    pq.enqueue(v, dist[v]);
                }
            }
        }

        return dist.filter(d => d <= distanceThreshold).length;
    };

    let ans = n;
    let cnt = MAX;
    for (let i = n - 1; i >= 0; --i) {
        const t = dijkstra(i);
        if (t < cnt) {
            cnt = t;
            ans = i;
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

# [1335. 工作计划的最低难度](https://leetcode.cn/problems/minimum-difficulty-of-a-job-schedule){#1335}

{{< tabs "1335" >}}

{{% tab "python" %}}
```python
class Solution:
    def minDifficulty(self, jobDifficulty: List[int], d: int) -> int:
        n = len(jobDifficulty)
        f = [[inf] * (d + 1) for _ in range(n + 1)]
        f[0][0] = 0
        for i in range(1, n + 1):
            for j in range(1, min(d + 1, i + 1)):
                mx = 0
                for k in range(i, 0, -1):
                    mx = max(mx, jobDifficulty[k - 1])
                    f[i][j] = min(f[i][j], f[k - 1][j - 1] + mx)
        return -1 if f[n][d] >= inf else f[n][d]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minDifficulty(int[] jobDifficulty, int d) {
        final int inf = 1 << 30;
        int n = jobDifficulty.length;
        int[][] f = new int[n + 1][d + 1];
        for (var g : f) {
            Arrays.fill(g, inf);
        }
        f[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= Math.min(d, i); ++j) {
                int mx = 0;
                for (int k = i; k > 0; --k) {
                    mx = Math.max(mx, jobDifficulty[k - 1]);
                    f[i][j] = Math.min(f[i][j], f[k - 1][j - 1] + mx);
                }
            }
        }
        return f[n][d] >= inf ? -1 : f[n][d];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        int f[n + 1][d + 1];
        memset(f, 0x3f, sizeof(f));
        f[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= min(d, i); ++j) {
                int mx = 0;
                for (int k = i; k; --k) {
                    mx = max(mx, jobDifficulty[k - 1]);
                    f[i][j] = min(f[i][j], f[k - 1][j - 1] + mx);
                }
            }
        }
        return f[n][d] == 0x3f3f3f3f ? -1 : f[n][d];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minDifficulty(jobDifficulty []int, d int) int {
	n := len(jobDifficulty)
	f := make([][]int, n+1)
	const inf = 1 << 30
	for i := range f {
		f[i] = make([]int, d+1)
		for j := range f[i] {
			f[i][j] = inf
		}
	}
	f[0][0] = 0
	for i := 1; i <= n; i++ {
		for j := 1; j <= min(d, i); j++ {
			mx := 0
			for k := i; k > 0; k-- {
				mx = max(mx, jobDifficulty[k-1])
				f[i][j] = min(f[i][j], f[k-1][j-1]+mx)
			}
		}
	}
	if f[n][d] == inf {
		return -1
	}
	return f[n][d]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minDifficulty(jobDifficulty: number[], d: number): number {
    const n = jobDifficulty.length;
    const inf = 1 << 30;
    const f: number[][] = new Array(n + 1).fill(0).map(() => new Array(d + 1).fill(inf));
    f[0][0] = 0;
    for (let i = 1; i <= n; ++i) {
        for (let j = 1; j <= Math.min(d, i); ++j) {
            let mx = 0;
            for (let k = i; k > 0; --k) {
                mx = Math.max(mx, jobDifficulty[k - 1]);
                f[i][j] = Math.min(f[i][j], f[k - 1][j - 1] + mx);
            }
        }
    }
    return f[n][d] < inf ? f[n][d] : -1;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你需要制定一份&nbsp;<code>d</code>&nbsp;天的工作计划表。工作之间存在依赖，要想执行第&nbsp;<code>i</code>&nbsp;项工作，你必须完成全部&nbsp;<code>j</code>&nbsp;项工作（&nbsp;<code>0 &lt;= j &lt; i</code>）。</p>

<p>你每天 <strong>至少</strong>&nbsp;需要完成一项任务。工作计划的总难度是这&nbsp;<code>d</code>&nbsp;天每一天的难度之和，而一天的工作难度是当天应该完成工作的最大难度。</p>

<p>给你一个整数数组&nbsp;<code>jobDifficulty</code>&nbsp;和一个整数&nbsp;<code>d</code>，分别代表工作难度和需要计划的天数。第&nbsp;<code>i</code>&nbsp;项工作的难度是&nbsp;<code>jobDifficulty[i]</code>。</p>

<p>返回整个工作计划的 <strong>最小难度</strong> 。如果无法制定工作计划，则返回&nbsp;<strong>-1&nbsp;</strong>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1300-1399/1335.Minimum%20Difficulty%20of%20a%20Job%20Schedule/images/untitled.png" style="height: 304px; width: 365px;"></p>

<pre><strong>输入：</strong>jobDifficulty = [6,5,4,3,2,1], d = 2
<strong>输出：</strong>7
<strong>解释：</strong>第一天，您可以完成前 5 项工作，总难度 = 6.
第二天，您可以完成最后一项工作，总难度 = 1.
计划表的难度 = 6 + 1 = 7 
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>jobDifficulty = [9,9,9], d = 4
<strong>输出：</strong>-1
<strong>解释：</strong>就算你每天完成一项工作，仍然有一天是空闲的，你无法制定一份能够满足既定工作时间的计划表。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>jobDifficulty = [1,1,1], d = 3
<strong>输出：</strong>3
<strong>解释：</strong>工作计划为每天一项工作，总难度为 3 。
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>jobDifficulty = [7,1,7,1,7,1], d = 3
<strong>输出：</strong>15
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>jobDifficulty = [11,111,22,222,33,333,44,444], d = 6
<strong>输出：</strong>843
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= jobDifficulty.length &lt;= 300</code></li>
	<li><code>0 &lt;=&nbsp;jobDifficulty[i] &lt;= 1000</code></li>
	<li><code>1 &lt;= d &lt;= 10</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i][j]$ 表示完成前 $i$ 项工作，且一共用了 $j$ 天的最小难度。初始时 $f[0][0] = 0$，其余 $f[i][j]$ 均为 $\infty$。

考虑第 $j$ 天的工作安排，我们可以枚举第 $j$ 天完成的工作 $[k,..i]$，那么有状态转移方程：

$$
f[i][j] = \min_{k \in [1,i]} \{f[k-1][j-1] + \max_{k \leq t \leq i} \{jobDifficulty[t-1]\}\}
$$

最终答案即为 $f[n][d]$。

时间复杂度 $O(n^2 \times d)$，空间复杂度 $O(n \times d)$。其中 $n$ 和 $d$ 分别为工作数量和需要计划的天数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minDifficulty(self, jobDifficulty: List[int], d: int) -> int:
        n = len(jobDifficulty)
        f = [[inf] * (d + 1) for _ in range(n + 1)]
        f[0][0] = 0
        for i in range(1, n + 1):
            for j in range(1, min(d + 1, i + 1)):
                mx = 0
                for k in range(i, 0, -1):
                    mx = max(mx, jobDifficulty[k - 1])
                    f[i][j] = min(f[i][j], f[k - 1][j - 1] + mx)
        return -1 if f[n][d] >= inf else f[n][d]
```

#### Java

```java
class Solution {
    public int minDifficulty(int[] jobDifficulty, int d) {
        final int inf = 1 << 30;
        int n = jobDifficulty.length;
        int[][] f = new int[n + 1][d + 1];
        for (var g : f) {
            Arrays.fill(g, inf);
        }
        f[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= Math.min(d, i); ++j) {
                int mx = 0;
                for (int k = i; k > 0; --k) {
                    mx = Math.max(mx, jobDifficulty[k - 1]);
                    f[i][j] = Math.min(f[i][j], f[k - 1][j - 1] + mx);
                }
            }
        }
        return f[n][d] >= inf ? -1 : f[n][d];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        int f[n + 1][d + 1];
        memset(f, 0x3f, sizeof(f));
        f[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= min(d, i); ++j) {
                int mx = 0;
                for (int k = i; k; --k) {
                    mx = max(mx, jobDifficulty[k - 1]);
                    f[i][j] = min(f[i][j], f[k - 1][j - 1] + mx);
                }
            }
        }
        return f[n][d] == 0x3f3f3f3f ? -1 : f[n][d];
    }
};
```

#### Go

```go
func minDifficulty(jobDifficulty []int, d int) int {
	n := len(jobDifficulty)
	f := make([][]int, n+1)
	const inf = 1 << 30
	for i := range f {
		f[i] = make([]int, d+1)
		for j := range f[i] {
			f[i][j] = inf
		}
	}
	f[0][0] = 0
	for i := 1; i <= n; i++ {
		for j := 1; j <= min(d, i); j++ {
			mx := 0
			for k := i; k > 0; k-- {
				mx = max(mx, jobDifficulty[k-1])
				f[i][j] = min(f[i][j], f[k-1][j-1]+mx)
			}
		}
	}
	if f[n][d] == inf {
		return -1
	}
	return f[n][d]
}
```

#### TypeScript

```ts
function minDifficulty(jobDifficulty: number[], d: number): number {
    const n = jobDifficulty.length;
    const inf = 1 << 30;
    const f: number[][] = new Array(n + 1).fill(0).map(() => new Array(d + 1).fill(inf));
    f[0][0] = 0;
    for (let i = 1; i <= n; ++i) {
        for (let j = 1; j <= Math.min(d, i); ++j) {
            let mx = 0;
            for (let k = i; k > 0; --k) {
                mx = Math.max(mx, jobDifficulty[k - 1]);
                f[i][j] = Math.min(f[i][j], f[k - 1][j - 1] + mx);
            }
        }
    }
    return f[n][d] < inf ? f[n][d] : -1;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1336. 每次访问的交易次数 🔒](https://leetcode.cn/problems/number-of-transactions-per-visit){#1336}

{{< tabs "1336" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH RECURSIVE
    S AS (
        SELECT 0 AS n
        UNION
        SELECT n + 1
        FROM S
        WHERE
            n < (
                SELECT MAX(cnt)
                FROM
                    (
                        SELECT COUNT(1) AS cnt
                        FROM Transactions
                        GROUP BY user_id, transaction_date
                    ) AS t
            )
    ),
    T AS (
        SELECT v.user_id, visit_date, IFNULL(cnt, 0) AS cnt
        FROM
            Visits AS v
            LEFT JOIN (
                SELECT user_id, transaction_date, COUNT(1) AS cnt
                FROM Transactions
                GROUP BY 1, 2
            ) AS t
                ON v.user_id = t.user_id AND v.visit_date = t.transaction_date
    )
SELECT n AS transactions_count, COUNT(user_id) AS visits_count
FROM
    S AS s
    LEFT JOIN T AS t ON s.n = t.cnt
GROUP BY n
ORDER BY n;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表: <code>Visits</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| user_id       | int     |
| visit_date    | date    |
+---------------+---------+
(user_id, visit_date) 是该表的主键(具有唯一值的列的组合)
该表的每行表示 user_id 在 visit_date 访问了银行
</pre>

<p>&nbsp;</p>

<p>表: <code>Transactions</code></p>

<pre>
+------------------+---------+
| Column Name      | Type    |
+------------------+---------+
| user_id          | int     |
| transaction_date | date    |
| amount           | int     |
+------------------+---------+
该表可能有重复行
该表的每一行表示 user_id 在 transaction_date 完成了一笔 amount 数额的交易
可以保证用户 (user) 在 transaction_date 访问了银行 (也就是说 Visits 表包含 (user_id, transaction_date) 行)
</pre>

<p>&nbsp;</p>

<p>银行想要得到银行客户在一次访问时的交易次数和相应的在一次访问时该交易次数的客户数量的图表</p>

<p>编写解决方案找出多少客户访问了银行但没有进行任何交易，多少客户访问了银行进行了一次交易等等</p>

<p>结果包含两列：</p>

<ul>
	<li><code>transactions_count：</code>&nbsp;客户在一次访问中的交易次数</li>
	<li><code>visits_count：</code> 在&nbsp;<code>transactions_count</code>&nbsp;交易次数下相应的一次访问时的客户数量</li>
</ul>

<p><code>transactions_count</code> 的值从&nbsp;<code>0</code>&nbsp;到所有用户一次访问中的&nbsp;<code>max(transactions_count)</code>&nbsp;</p>

<p>结果按&nbsp;<code>transactions_count</code>&nbsp;排序</p>

<p>下面是返回结果格式的例子：</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1300-1399/1336.Number%20of%20Transactions%20per%20Visit/images/chart.png" style="height:359px; width:600px" /></p>

<pre>
<code><strong>输入：</strong>
Visits</code> 表:
+---------+------------+
| user_id | visit_date |
+---------+------------+
| 1       | 2020-01-01 |
| 2       | 2020-01-02 |
| 12      | 2020-01-01 |
| 19      | 2020-01-03 |
| 1       | 2020-01-02 |
| 2       | 2020-01-03 |
| 1       | 2020-01-04 |
| 7       | 2020-01-11 |
| 9       | 2020-01-25 |
| 8       | 2020-01-28 |
+---------+------------+
<code>Transactions</code> 表:
+---------+------------------+--------+
| user_id | transaction_date | amount |
+---------+------------------+--------+
| 1       | 2020-01-02       | 120    |
| 2       | 2020-01-03       | 22     |
| 7       | 2020-01-11       | 232    |
| 1       | 2020-01-04       | 7      |
| 9       | 2020-01-25       | 33     |
| 9       | 2020-01-25       | 66     |
| 8       | 2020-01-28       | 1      |
| 9       | 2020-01-25       | 99     |
+---------+------------------+--------+
<strong>输出：</strong>
+--------------------+--------------+
| <code>transactions_count</code> | visits_count |
+--------------------+--------------+
| 0                  | 4            |
| 1                  | 5            |
| 2                  | 0            |
| 3                  | 1            |
+--------------------+--------------+
<strong>解释：</strong>为这个例子绘制的图表如上所示
* 对于 transactions_count = 0, visits 中 (1, "2020-01-01"), (2, "2020-01-02"), (12, "2020-01-01") 和 (19, "2020-01-03") 没有进行交易，所以 visits_count = 4 。
* 对于 transactions_count = 1, visits 中 (2, "2020-01-03"), (7, "2020-01-11"), (8, "2020-01-28"),&nbsp;(1, "2020-01-02") 和 (1, "2020-01-04") 进行了一次交易，所以 visits_count = 5 。
* 对于 transactions_count = 2, 没有客户访问银行进行了两次交易，所以 visits_count = 0 。
* 对于 transactions_count = 3, visits 中&nbsp;(9, "2020-01-25") 进行了三次交易，所以 visits_count = 1 。
* 对于 transactions_count &gt;= 4, 没有客户访问银行进行了超过3次交易，所以我们停止在 transactions_count = 3 。
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
WITH RECURSIVE
    S AS (
        SELECT 0 AS n
        UNION
        SELECT n + 1
        FROM S
        WHERE
            n < (
                SELECT MAX(cnt)
                FROM
                    (
                        SELECT COUNT(1) AS cnt
                        FROM Transactions
                        GROUP BY user_id, transaction_date
                    ) AS t
            )
    ),
    T AS (
        SELECT v.user_id, visit_date, IFNULL(cnt, 0) AS cnt
        FROM
            Visits AS v
            LEFT JOIN (
                SELECT user_id, transaction_date, COUNT(1) AS cnt
                FROM Transactions
                GROUP BY 1, 2
            ) AS t
                ON v.user_id = t.user_id AND v.visit_date = t.transaction_date
    )
SELECT n AS transactions_count, COUNT(user_id) AS visits_count
FROM
    S AS s
    LEFT JOIN T AS t ON s.n = t.cnt
GROUP BY n
ORDER BY n;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1337. 矩阵中战斗力最弱的 K 行](https://leetcode.cn/problems/the-k-weakest-rows-in-a-matrix){#1337}

{{< tabs "1337" >}}

{{% tab "python" %}}
```python
class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        m, n = len(mat), len(mat[0])
        ans = [n - bisect_right(row[::-1], 0) for row in mat]
        idx = list(range(m))
        idx.sort(key=lambda i: ans[i])
        return idx[:k]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] kWeakestRows(int[][] mat, int k) {
        int m = mat.length, n = mat[0].length;
        int[] res = new int[m];
        List<Integer> idx = new ArrayList<>();
        for (int i = 0; i < m; ++i) {
            idx.add(i);
            int[] row = mat[i];
            int left = 0, right = n;
            while (left < right) {
                int mid = (left + right) >> 1;
                if (row[mid] == 0) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            res[i] = left;
        }
        idx.sort(Comparator.comparingInt(a -> res[a]));
        int[] ans = new int[k];
        for (int i = 0; i < k; ++i) {
            ans[i] = idx.get(i);
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
    int search(vector<int>& m) {
        int l = 0;
        int h = m.size() - 1;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (m[mid] == 0)
                h = mid - 1;
            else
                l = mid + 1;
        }
        return l;
    }

    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> p;
        vector<int> res;
        for (int i = 0; i < mat.size(); i++) {
            int count = search(mat[i]);
            p.push_back({count, i});
        }
        sort(p.begin(), p.end());
        for (int i = 0; i < k; i++) {
            res.push_back(p[i].second);
        }
        return res;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func kWeakestRows(mat [][]int, k int) []int {
	m, n := len(mat), len(mat[0])
	res := make([]int, m)
	var idx []int
	for i, row := range mat {
		idx = append(idx, i)
		left, right := 0, n
		for left < right {
			mid := (left + right) >> 1
			if row[mid] == 0 {
				right = mid
			} else {
				left = mid + 1
			}
		}
		res[i] = left
	}
	sort.Slice(idx, func(i, j int) bool {
		return res[idx[i]] < res[idx[j]] || (res[idx[i]] == res[idx[j]] && idx[i] < idx[j])
	})
	return idx[:k]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function kWeakestRows(mat: number[][], k: number): number[] {
    let n = mat.length;
    let sumMap = mat.map((d, i) => [d.reduce((a, c) => a + c, 0), i]);
    let ans = [];
    // 冒泡排序
    for (let i = 0; i < k; i++) {
        for (let j = i; j < n; j++) {
            if (
                sumMap[j][0] < sumMap[i][0] ||
                (sumMap[j][0] == sumMap[i][0] && sumMap[i][1] > sumMap[j][1])
            ) {
                [sumMap[i], sumMap[j]] = [sumMap[j], sumMap[i]];
            }
        }
        ans.push(sumMap[i][1]);
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

<p>给你一个大小为 <code>m * n</code> 的矩阵 <code>mat</code>，矩阵由若干军人和平民组成，分别用 1 和 0 表示。</p>

<p>请你返回矩阵中战斗力最弱的 <code>k</code> 行的索引，按从最弱到最强排序。</p>

<p>如果第 <em><strong>i</strong></em> 行的军人数量少于第 <em><strong>j</strong></em> 行，或者两行军人数量相同但<em><strong> i</strong></em> 小于 <em><strong>j</strong></em>，那么我们认为第<em><strong> i </strong></em>行的战斗力比第<em><strong> j </strong></em>行弱。</p>

<p>军人 <strong>总是</strong> 排在一行中的靠前位置，也就是说 1 总是出现在 0 之前。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>mat = 
[[1,1,0,0,0],
 [1,1,1,1,0],
 [1,0,0,0,0],
 [1,1,0,0,0],
 [1,1,1,1,1]], 
k = 3
<strong>输出：</strong>[2,0,3]
<strong>解释：</strong>
每行中的军人数目：
行 0 -> 2 
行 1 -> 4 
行 2 -> 1 
行 3 -> 2 
行 4 -> 5 
从最弱到最强对这些行排序后得到 [2,0,3,1,4]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>mat = 
[[1,0,0,0],
 [1,1,1,1],
 [1,0,0,0],
 [1,0,0,0]], 
k = 2
<strong>输出：</strong>[0,2]
<strong>解释：</strong> 
每行中的军人数目：
行 0 -> 1 
行 1 -> 4 
行 2 -> 1 
行 3 -> 1 
从最弱到最强对这些行排序后得到 [0,2,3,1]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == mat.length</code></li>
	<li><code>n == mat[i].length</code></li>
	<li><code>2 <= n, m <= 100</code></li>
	<li><code>1 <= k <= m</code></li>
	<li><code>matrix[i][j]</code> 不是 0 就是 1</li>
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
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        m, n = len(mat), len(mat[0])
        ans = [n - bisect_right(row[::-1], 0) for row in mat]
        idx = list(range(m))
        idx.sort(key=lambda i: ans[i])
        return idx[:k]
```

#### Java

```java
class Solution {
    public int[] kWeakestRows(int[][] mat, int k) {
        int m = mat.length, n = mat[0].length;
        int[] res = new int[m];
        List<Integer> idx = new ArrayList<>();
        for (int i = 0; i < m; ++i) {
            idx.add(i);
            int[] row = mat[i];
            int left = 0, right = n;
            while (left < right) {
                int mid = (left + right) >> 1;
                if (row[mid] == 0) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            res[i] = left;
        }
        idx.sort(Comparator.comparingInt(a -> res[a]));
        int[] ans = new int[k];
        for (int i = 0; i < k; ++i) {
            ans[i] = idx.get(i);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int search(vector<int>& m) {
        int l = 0;
        int h = m.size() - 1;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (m[mid] == 0)
                h = mid - 1;
            else
                l = mid + 1;
        }
        return l;
    }

    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> p;
        vector<int> res;
        for (int i = 0; i < mat.size(); i++) {
            int count = search(mat[i]);
            p.push_back({count, i});
        }
        sort(p.begin(), p.end());
        for (int i = 0; i < k; i++) {
            res.push_back(p[i].second);
        }
        return res;
    }
};
```

#### Go

```go
func kWeakestRows(mat [][]int, k int) []int {
	m, n := len(mat), len(mat[0])
	res := make([]int, m)
	var idx []int
	for i, row := range mat {
		idx = append(idx, i)
		left, right := 0, n
		for left < right {
			mid := (left + right) >> 1
			if row[mid] == 0 {
				right = mid
			} else {
				left = mid + 1
			}
		}
		res[i] = left
	}
	sort.Slice(idx, func(i, j int) bool {
		return res[idx[i]] < res[idx[j]] || (res[idx[i]] == res[idx[j]] && idx[i] < idx[j])
	})
	return idx[:k]
}
```

#### TypeScript

```ts
function kWeakestRows(mat: number[][], k: number): number[] {
    let n = mat.length;
    let sumMap = mat.map((d, i) => [d.reduce((a, c) => a + c, 0), i]);
    let ans = [];
    // 冒泡排序
    for (let i = 0; i < k; i++) {
        for (let j = i; j < n; j++) {
            if (
                sumMap[j][0] < sumMap[i][0] ||
                (sumMap[j][0] == sumMap[i][0] && sumMap[i][1] > sumMap[j][1])
            ) {
                [sumMap[i], sumMap[j]] = [sumMap[j], sumMap[i]];
            }
        }
        ans.push(sumMap[i][1]);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1338. 数组大小减半](https://leetcode.cn/problems/reduce-array-size-to-the-half){#1338}

{{< tabs "1338" >}}

{{% tab "python" %}}
```python
class Solution:
    def minSetSize(self, arr: List[int]) -> int:
        cnt = Counter(arr)
        ans = m = 0
        for _, v in cnt.most_common():
            m += v
            ans += 1
            if m * 2 >= len(arr):
                break
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minSetSize(int[] arr) {
        int mx = 0;
        for (int x : arr) {
            mx = Math.max(mx, x);
        }
        int[] cnt = new int[mx + 1];
        for (int x : arr) {
            ++cnt[x];
        }
        Arrays.sort(cnt);
        int ans = 0;
        int m = 0;
        for (int i = mx;; --i) {
            if (cnt[i] > 0) {
                m += cnt[i];
                ++ans;
                if (m * 2 >= arr.length) {
                    return ans;
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
    int minSetSize(vector<int>& arr) {
        int mx = ranges::max(arr);
        int cnt[mx + 1];
        memset(cnt, 0, sizeof(cnt));
        for (int& x : arr) {
            ++cnt[x];
        }
        sort(cnt, cnt + mx + 1, greater<int>());
        int ans = 0;
        int m = 0;
        for (int& x : cnt) {
            if (x) {
                m += x;
                ++ans;
                if (m * 2 >= arr.size()) {
                    break;
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
func minSetSize(arr []int) (ans int) {
	mx := slices.Max(arr)
	cnt := make([]int, mx+1)
	for _, x := range arr {
		cnt[x]++
	}
	sort.Ints(cnt)
	for i, m := mx, 0; ; i-- {
		if cnt[i] > 0 {
			m += cnt[i]
			ans++
			if m >= len(arr)/2 {
				return
			}
		}
	}
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minSetSize(arr: number[]): number {
    const cnt = new Map<number, number>();
    for (const v of arr) {
        cnt.set(v, (cnt.get(v) ?? 0) + 1);
    }
    let [ans, m] = [0, 0];
    for (const v of Array.from(cnt.values()).sort((a, b) => b - a)) {
        m += v;
        ++ans;
        if (m * 2 >= arr.length) {
            break;
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

<p>给你一个整数数组&nbsp;<code>arr</code>。你可以从中选出一个整数集合，并删除这些整数在数组中的每次出现。</p>

<p>返回&nbsp;<strong>至少</strong>&nbsp;能删除数组中的一半整数的整数集合的最小大小。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>arr = [3,3,3,3,5,5,5,2,2,7]
<strong>输出：</strong>2
<strong>解释：</strong>选择 {3,7} 使得结果数组为 [5,5,5,2,2]、长度为 5（原数组长度的一半）。
大小为 2 的可行集合有 {3,5},{3,2},{5,2}。
选择 {2,7} 是不可行的，它的结果数组为 [3,3,3,3,5,5,5]，新数组长度大于原数组的二分之一。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>arr = [7,7,7,7,7,7]
<strong>输出：</strong>1
<strong>解释：</strong>我们只能选择集合 {7}，结果数组为空。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 10<sup>5</sup></code></li>
	<li><code>arr.length</code>&nbsp;为偶数</li>
	<li><code>1 &lt;= arr[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数 + 排序

我们可以用哈希表或数组 $cnt$ 统计数组 $\textit{arr}$ 中每个数字出现的次数，然后将 $cnt$ 中的数字从大到小排序，从大到小遍历 $\textit{cnt}$，每次遍历将当前数字 $x$ 加入答案，并将 $m$ 加上 $x$，如果 $m \geq \frac{n}{2}$，则返回答案。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $\textit{arr}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minSetSize(self, arr: List[int]) -> int:
        cnt = Counter(arr)
        ans = m = 0
        for _, v in cnt.most_common():
            m += v
            ans += 1
            if m * 2 >= len(arr):
                break
        return ans
```

#### Java

```java
class Solution {
    public int minSetSize(int[] arr) {
        int mx = 0;
        for (int x : arr) {
            mx = Math.max(mx, x);
        }
        int[] cnt = new int[mx + 1];
        for (int x : arr) {
            ++cnt[x];
        }
        Arrays.sort(cnt);
        int ans = 0;
        int m = 0;
        for (int i = mx;; --i) {
            if (cnt[i] > 0) {
                m += cnt[i];
                ++ans;
                if (m * 2 >= arr.length) {
                    return ans;
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
    int minSetSize(vector<int>& arr) {
        int mx = ranges::max(arr);
        int cnt[mx + 1];
        memset(cnt, 0, sizeof(cnt));
        for (int& x : arr) {
            ++cnt[x];
        }
        sort(cnt, cnt + mx + 1, greater<int>());
        int ans = 0;
        int m = 0;
        for (int& x : cnt) {
            if (x) {
                m += x;
                ++ans;
                if (m * 2 >= arr.size()) {
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
func minSetSize(arr []int) (ans int) {
	mx := slices.Max(arr)
	cnt := make([]int, mx+1)
	for _, x := range arr {
		cnt[x]++
	}
	sort.Ints(cnt)
	for i, m := mx, 0; ; i-- {
		if cnt[i] > 0 {
			m += cnt[i]
			ans++
			if m >= len(arr)/2 {
				return
			}
		}
	}
}
```

#### TypeScript

```ts
function minSetSize(arr: number[]): number {
    const cnt = new Map<number, number>();
    for (const v of arr) {
        cnt.set(v, (cnt.get(v) ?? 0) + 1);
    }
    let [ans, m] = [0, 0];
    for (const v of Array.from(cnt.values()).sort((a, b) => b - a)) {
        m += v;
        ++ans;
        if (m * 2 >= arr.length) {
            break;
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

# [1339. 分裂二叉树的最大乘积](https://leetcode.cn/problems/maximum-product-of-splitted-binary-tree){#1339}

{{< tabs "1339" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxProduct(self, root: Optional[TreeNode]) -> int:
        def sum(root: Optional[TreeNode]) -> int:
            if root is None:
                return 0
            return root.val + sum(root.left) + sum(root.right)

        def dfs(root: Optional[TreeNode]) -> int:
            if root is None:
                return 0
            t = root.val + dfs(root.left) + dfs(root.right)
            nonlocal ans, s
            if t < s:
                ans = max(ans, t * (s - t))
            return t

        mod = 10**9 + 7
        s = sum(root)
        ans = 0
        dfs(root)
        return ans % mod
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
    private long ans;
    private long s;

    public int maxProduct(TreeNode root) {
        final int mod = (int) 1e9 + 7;
        s = sum(root);
        dfs(root);
        return (int) (ans % mod);
    }

    private long dfs(TreeNode root) {
        if (root == null) {
            return 0;
        }
        long t = root.val + dfs(root.left) + dfs(root.right);
        if (t < s) {
            ans = Math.max(ans, t * (s - t));
        }
        return t;
    }

    private long sum(TreeNode root) {
        if (root == null) {
            return 0;
        }
        return root.val + sum(root.left) + sum(root.right);
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
    int maxProduct(TreeNode* root) {
        using ll = long long;
        ll ans = 0;
        const int mod = 1e9 + 7;

        function<ll(TreeNode*)> sum = [&](TreeNode* root) -> ll {
            if (!root) {
                return 0;
            }
            return root->val + sum(root->left) + sum(root->right);
        };

        ll s = sum(root);

        function<ll(TreeNode*)> dfs = [&](TreeNode* root) -> ll {
            if (!root) {
                return 0;
            }
            ll t = root->val + dfs(root->left) + dfs(root->right);
            if (t < s) {
                ans = max(ans, t * (s - t));
            }
            return t;
        };

        dfs(root);
        return ans % mod;
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
func maxProduct(root *TreeNode) (ans int) {
	const mod = 1e9 + 7
	var sum func(*TreeNode) int
	sum = func(root *TreeNode) int {
		if root == nil {
			return 0
		}
		return root.Val + sum(root.Left) + sum(root.Right)
	}
	s := sum(root)
	var dfs func(*TreeNode) int
	dfs = func(root *TreeNode) int {
		if root == nil {
			return 0
		}
		t := root.Val + dfs(root.Left) + dfs(root.Right)
		if t < s {
			ans = max(ans, t*(s-t))
		}
		return t
	}
	dfs(root)
	ans %= mod
	return
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

function maxProduct(root: TreeNode | null): number {
    const sum = (root: TreeNode | null): number => {
        if (!root) {
            return 0;
        }
        return root.val + sum(root.left) + sum(root.right);
    };
    const s = sum(root);
    let ans = 0;
    const mod = 1e9 + 7;
    const dfs = (root: TreeNode | null): number => {
        if (!root) {
            return 0;
        }
        const t = root.val + dfs(root.left) + dfs(root.right);
        if (t < s) {
            ans = Math.max(ans, t * (s - t));
        }
        return t;
    };
    dfs(root);
    return ans % mod;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一棵二叉树，它的根为&nbsp;<code>root</code> 。请你删除 1 条边，使二叉树分裂成两棵子树，且它们子树和的乘积尽可能大。</p>

<p>由于答案可能会很大，请你将结果对 10^9 + 7 取模后再返回。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1300-1399/1339.Maximum%20Product%20of%20Splitted%20Binary%20Tree/images/sample_1_1699.png" style="height: 200px; width: 495px;"></strong></p>

<pre><strong>输入：</strong>root = [1,2,3,4,5,6]
<strong>输出：</strong>110
<strong>解释：</strong>删除红色的边，得到 2 棵子树，和分别为 11 和 10 。它们的乘积是 110 （11*10）
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1300-1399/1339.Maximum%20Product%20of%20Splitted%20Binary%20Tree/images/sample_2_1699.png" style="height: 200px; width: 495px;"></p>

<pre><strong>输入：</strong>root = [1,null,2,3,4,null,null,5,6]
<strong>输出：</strong>90
<strong>解释：</strong>移除红色的边，得到 2 棵子树，和分别是 15 和 6 。它们的乘积为 90 （15*6）
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>root = [2,3,9,10,7,8,6,5,4,11,1]
<strong>输出：</strong>1025
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>root = [1,1]
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>每棵树最多有&nbsp;<code>50000</code>&nbsp;个节点，且至少有&nbsp;<code>2</code>&nbsp;个节点。</li>
	<li>每个节点的值在&nbsp;<code>[1, 10000]</code>&nbsp;之间。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：两次 DFS

我们可以用两次 DFS 来解决这个问题。

第一次，我们用一个 $sum(root)$ 函数递归求出整棵树所有节点的和，记为 $s$。

第二次，我们用一个 $dfs(root)$ 函数递归遍历每个节点，求出以当前节点为根的子树的节点和 $t$，那么当前节点与其父节点分裂后两棵子树的节点和分别为 $t$ 和 $s - t$，它们的乘积为 $t \times (s - t)$，我们遍历所有节点，求出乘积的最大值，即为答案。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是二叉树的节点数。

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
    def maxProduct(self, root: Optional[TreeNode]) -> int:
        def sum(root: Optional[TreeNode]) -> int:
            if root is None:
                return 0
            return root.val + sum(root.left) + sum(root.right)

        def dfs(root: Optional[TreeNode]) -> int:
            if root is None:
                return 0
            t = root.val + dfs(root.left) + dfs(root.right)
            nonlocal ans, s
            if t < s:
                ans = max(ans, t * (s - t))
            return t

        mod = 10**9 + 7
        s = sum(root)
        ans = 0
        dfs(root)
        return ans % mod
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
    private long ans;
    private long s;

    public int maxProduct(TreeNode root) {
        final int mod = (int) 1e9 + 7;
        s = sum(root);
        dfs(root);
        return (int) (ans % mod);
    }

    private long dfs(TreeNode root) {
        if (root == null) {
            return 0;
        }
        long t = root.val + dfs(root.left) + dfs(root.right);
        if (t < s) {
            ans = Math.max(ans, t * (s - t));
        }
        return t;
    }

    private long sum(TreeNode root) {
        if (root == null) {
            return 0;
        }
        return root.val + sum(root.left) + sum(root.right);
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
    int maxProduct(TreeNode* root) {
        using ll = long long;
        ll ans = 0;
        const int mod = 1e9 + 7;

        function<ll(TreeNode*)> sum = [&](TreeNode* root) -> ll {
            if (!root) {
                return 0;
            }
            return root->val + sum(root->left) + sum(root->right);
        };

        ll s = sum(root);

        function<ll(TreeNode*)> dfs = [&](TreeNode* root) -> ll {
            if (!root) {
                return 0;
            }
            ll t = root->val + dfs(root->left) + dfs(root->right);
            if (t < s) {
                ans = max(ans, t * (s - t));
            }
            return t;
        };

        dfs(root);
        return ans % mod;
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
func maxProduct(root *TreeNode) (ans int) {
	const mod = 1e9 + 7
	var sum func(*TreeNode) int
	sum = func(root *TreeNode) int {
		if root == nil {
			return 0
		}
		return root.Val + sum(root.Left) + sum(root.Right)
	}
	s := sum(root)
	var dfs func(*TreeNode) int
	dfs = func(root *TreeNode) int {
		if root == nil {
			return 0
		}
		t := root.Val + dfs(root.Left) + dfs(root.Right)
		if t < s {
			ans = max(ans, t*(s-t))
		}
		return t
	}
	dfs(root)
	ans %= mod
	return
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

function maxProduct(root: TreeNode | null): number {
    const sum = (root: TreeNode | null): number => {
        if (!root) {
            return 0;
        }
        return root.val + sum(root.left) + sum(root.right);
    };
    const s = sum(root);
    let ans = 0;
    const mod = 1e9 + 7;
    const dfs = (root: TreeNode | null): number => {
        if (!root) {
            return 0;
        }
        const t = root.val + dfs(root.left) + dfs(root.right);
        if (t < s) {
            ans = Math.max(ans, t * (s - t));
        }
        return t;
    };
    dfs(root);
    return ans % mod;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
