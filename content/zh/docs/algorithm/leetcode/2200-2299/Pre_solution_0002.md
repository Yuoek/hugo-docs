---
title: "2210_统计数组中峰和谷的数量"
date: 2025-10-08T18:39:07+08:00
weight: 2
tags: [位运算, 前缀和, 动态规划, 哈希表, 回溯, 字符串, 数学, 数组, 有序集合, 枚举, 栈, 模拟, 线段树, 贪心]
---

{{< markmap >}}
### [2210_统计数组中峰和谷的数量](#2210)
#### [数组](#2210)
### [2211_统计道路上的碰撞次数](#2211)
#### [栈](#2211)
#### [字符串](#2211)
#### [模拟](#2211)
### [2212_射箭比赛中的最大得分](#2212)
#### [位运算](#2212)
#### [数组](#2212)
#### [回溯](#2212)
#### [枚举](#2212)
### [2213_由单个字符重复的最长子字符串](#2213)
#### [线段树](#2213)
#### [数组](#2213)
#### [字符串](#2213)
#### [有序集合](#2213)
### [2214_通关游戏所需的最低生命值 🔒](#2214)
#### [贪心](#2214)
#### [数组](#2214)
### [2215_找出两数组的不同](#2215)
#### [数组](#2215)
#### [哈希表](#2215)
### [2216_美化数组的最少删除数](#2216)
#### [栈](#2216)
#### [贪心](#2216)
#### [数组](#2216)
### [2217_找到指定长度的回文数](#2217)
#### [数组](#2217)
#### [数学](#2217)
### [2218_从栈中取出 K 个硬币的最大面值和](#2218)
#### [数组](#2218)
#### [动态规划](#2218)
#### [前缀和](#2218)
### [2219_数组的最大总分 🔒](#2219)
#### [数组](#2219)
#### [前缀和](#2219)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2210_统计数组中峰和谷的数量
___
#### 数组
---
### 2211_统计道路上的碰撞次数
___
#### 栈
___
#### 字符串
___
#### 模拟
---
### 2212_射箭比赛中的最大得分
___
#### 位运算
___
#### 数组
___
#### 回溯
___
#### 枚举
---
### 2213_由单个字符重复的最长子字符串
___
#### 线段树
___
#### 数组
___
#### 字符串
___
#### 有序集合
---
### 2214_通关游戏所需的最低生命值 🔒
___
#### 贪心
___
#### 数组
---
### 2215_找出两数组的不同
___
#### 数组
___
#### 哈希表
---
### 2216_美化数组的最少删除数
___
#### 栈
___
#### 贪心
___
#### 数组
---
### 2217_找到指定长度的回文数
___
#### 数组
___
#### 数学
---
### 2218_从栈中取出 K 个硬币的最大面值和
___
#### 数组
___
#### 动态规划
___
#### 前缀和
---
### 2219_数组的最大总分 🔒
___
#### 数组
___
#### 前缀和
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 位运算 | 前缀和 | 动态规划 |
| 哈希表 | 回溯 | 字符串 |
| 数学 | 数组 | 有序集合 |
| 枚举 | 栈 | 模拟 |
| 线段树 | 贪心 |  |

# [2210. 统计数组中峰和谷的数量](https://leetcode.cn/problems/count-hills-and-valleys-in-an-array){#2210}

{{< tabs "2210" >}}

{{% tab "python" %}}
```python
class Solution:
    def countHillValley(self, nums: List[int]) -> int:
        ans = j = 0
        for i in range(1, len(nums) - 1):
            if nums[i] == nums[i + 1]:
                continue
            if nums[i] > nums[j] and nums[i] > nums[i + 1]:
                ans += 1
            if nums[i] < nums[j] and nums[i] < nums[i + 1]:
                ans += 1
            j = i
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countHillValley(int[] nums) {
        int ans = 0;
        for (int i = 1, j = 0; i < nums.length - 1; ++i) {
            if (nums[i] == nums[i + 1]) {
                continue;
            }
            if (nums[i] > nums[j] && nums[i] > nums[i + 1]) {
                ++ans;
            }
            if (nums[i] < nums[j] && nums[i] < nums[i + 1]) {
                ++ans;
            }
            j = i;
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
    int countHillValley(vector<int>& nums) {
        int ans = 0;
        for (int i = 1, j = 0; i < nums.size() - 1; ++i) {
            if (nums[i] == nums[i + 1]) {
                continue;
            }
            if (nums[i] > nums[j] && nums[i] > nums[i + 1]) {
                ++ans;
            }
            if (nums[i] < nums[j] && nums[i] < nums[i + 1]) {
                ++ans;
            }
            j = i;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countHillValley(nums []int) int {
	ans := 0
	for i, j := 1, 0; i < len(nums)-1; i++ {
		if nums[i] == nums[i+1] {
			continue
		}
		if nums[i] > nums[j] && nums[i] > nums[i+1] {
			ans++
		}
		if nums[i] < nums[j] && nums[i] < nums[i+1] {
			ans++
		}
		j = i
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countHillValley(nums: number[]): number {
    let ans = 0;
    for (let i = 1, j = 0; i < nums.length - 1; ++i) {
        if (nums[i] === nums[i + 1]) {
            continue;
        }
        if (nums[i] > nums[j] && nums[i] > nums[i + 1]) {
            ans++;
        }
        if (nums[i] < nums[j] && nums[i] < nums[i + 1]) {
            ans++;
        }
        j = i;
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn count_hill_valley(nums: Vec<i32>) -> i32 {
        let mut ans = 0;
        let mut j = 0;

        for i in 1..nums.len() - 1 {
            if nums[i] == nums[i + 1] {
                continue;
            }
            if nums[i] > nums[j] && nums[i] > nums[i + 1] {
                ans += 1;
            }
            if nums[i] < nums[j] && nums[i] < nums[i + 1] {
                ans += 1;
            }
            j = i;
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

<p>给你一个下标从 <strong>0</strong> 开始的整数数组 <code>nums</code> 。如果两侧距 <code>i</code> 最近的不相等邻居的值均小于 <code>nums[i]</code> ，则下标 <code>i</code> 是 <code>nums</code> 中，某个峰的一部分。类似地，如果两侧距 <code>i</code> 最近的不相等邻居的值均大于 <code>nums[i]</code> ，则下标 <code>i</code> 是 <code>nums</code> 中某个谷的一部分。对于相邻下标&nbsp;<code>i</code> 和 <code>j</code> ，如果&nbsp;<code>nums[i] == nums[j]</code> ， 则认为这两下标属于 <strong>同一个</strong> 峰或谷。</p>

<p>注意，要使某个下标所做峰或谷的一部分，那么它左右两侧必须 <strong>都</strong> 存在不相等邻居。</p>

<p>返回 <code>nums</code> 中峰和谷的数量。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,4,1,1,6,5]
<strong>输出：</strong>3
<strong>解释：</strong>
在下标 0 ：由于 2 的左侧不存在不相等邻居，所以下标 0 既不是峰也不是谷。
在下标 1 ：4 的最近不相等邻居是 2 和 1 。由于 4 &gt; 2 且 4 &gt; 1 ，下标 1 是一个峰。
在下标 2 ：1 的最近不相等邻居是 4 和 6 。由于 1 &lt; 4 且 1 &lt; 6 ，下标 2 是一个谷。
在下标 3 ：1 的最近不相等邻居是 4 和 6 。由于 1 &lt; 4 且 1 &lt; 6 ，下标 3 符合谷的定义，但需要注意它和下标 2 是同一个谷的一部分。
在下标 4 ：6 的最近不相等邻居是 1 和 5 。由于 6 &gt; 1 且 6 &gt; 5 ，下标 4 是一个峰。
在下标 5 ：由于 5 的右侧不存在不相等邻居，所以下标 5 既不是峰也不是谷。
共有 3 个峰和谷，所以返回 3 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [6,6,5,5,4,1]
<strong>输出：</strong>0
<strong>解释：</strong>
在下标 0 ：由于 6 的左侧不存在不相等邻居，所以下标 0 既不是峰也不是谷。
在下标 1 ：由于 6 的左侧不存在不相等邻居，所以下标 1 既不是峰也不是谷。
在下标 2 ：5 的最近不相等邻居是 6 和 4 。由于 5 &lt; 6 且 5 &gt; 4 ，下标 2 既不是峰也不是谷。
在下标 3 ：5 的最近不相等邻居是 6 和 4 。由于 5 &lt; 6 且 5 &gt; 4 ，下标 3 既不是峰也不是谷。
在下标 4 ：4 的最近不相等邻居是 5 和 1 。由于 4 &lt; 5 且 4 &gt; 1 ，下标 4 既不是峰也不是谷。
在下标 5 ：由于 1 的右侧不存在不相等邻居，所以下标 5 既不是峰也不是谷。
共有 0 个峰和谷，所以返回 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：遍历

我们初始化一个指针 $j$ 指向下标 $0$ 的位置，然后在 $[1, n-1]$ 的范围内遍历数组。对于每一个位置 $i$：

-   如果 $nums[i] = nums[i+1]$，则跳过。
-   否则，如果 $nums[i]$ 大于 $nums[j]$ 且 $nums[i]$ 大于 $nums[i+1]$，则 $i$ 是一个峰；如果 $nums[i]$ 小于 $nums[j]$ 且 $nums[i]$ 小于 $nums[i+1]$，则 $i$ 是一个谷。
-   然后，我们将 $j$ 更新为 $i$，继续遍历。

遍历结束后，我们就可以得到峰和谷的数量。

时间复杂度 $O(n)$，其中 $n$ 是数组的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countHillValley(self, nums: List[int]) -> int:
        ans = j = 0
        for i in range(1, len(nums) - 1):
            if nums[i] == nums[i + 1]:
                continue
            if nums[i] > nums[j] and nums[i] > nums[i + 1]:
                ans += 1
            if nums[i] < nums[j] and nums[i] < nums[i + 1]:
                ans += 1
            j = i
        return ans
```

#### Java

```java
class Solution {
    public int countHillValley(int[] nums) {
        int ans = 0;
        for (int i = 1, j = 0; i < nums.length - 1; ++i) {
            if (nums[i] == nums[i + 1]) {
                continue;
            }
            if (nums[i] > nums[j] && nums[i] > nums[i + 1]) {
                ++ans;
            }
            if (nums[i] < nums[j] && nums[i] < nums[i + 1]) {
                ++ans;
            }
            j = i;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int ans = 0;
        for (int i = 1, j = 0; i < nums.size() - 1; ++i) {
            if (nums[i] == nums[i + 1]) {
                continue;
            }
            if (nums[i] > nums[j] && nums[i] > nums[i + 1]) {
                ++ans;
            }
            if (nums[i] < nums[j] && nums[i] < nums[i + 1]) {
                ++ans;
            }
            j = i;
        }
        return ans;
    }
};
```

#### Go

```go
func countHillValley(nums []int) int {
	ans := 0
	for i, j := 1, 0; i < len(nums)-1; i++ {
		if nums[i] == nums[i+1] {
			continue
		}
		if nums[i] > nums[j] && nums[i] > nums[i+1] {
			ans++
		}
		if nums[i] < nums[j] && nums[i] < nums[i+1] {
			ans++
		}
		j = i
	}
	return ans
}
```

#### TypeScript

```ts
function countHillValley(nums: number[]): number {
    let ans = 0;
    for (let i = 1, j = 0; i < nums.length - 1; ++i) {
        if (nums[i] === nums[i + 1]) {
            continue;
        }
        if (nums[i] > nums[j] && nums[i] > nums[i + 1]) {
            ans++;
        }
        if (nums[i] < nums[j] && nums[i] < nums[i + 1]) {
            ans++;
        }
        j = i;
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn count_hill_valley(nums: Vec<i32>) -> i32 {
        let mut ans = 0;
        let mut j = 0;

        for i in 1..nums.len() - 1 {
            if nums[i] == nums[i + 1] {
                continue;
            }
            if nums[i] > nums[j] && nums[i] > nums[i + 1] {
                ans += 1;
            }
            if nums[i] < nums[j] && nums[i] < nums[i + 1] {
                ans += 1;
            }
            j = i;
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

# [2211. 统计道路上的碰撞次数](https://leetcode.cn/problems/count-collisions-on-a-road){#2211}

{{< tabs "2211" >}}

{{% tab "python" %}}
```python
class Solution:
    def countCollisions(self, directions: str) -> int:
        s = directions.lstrip("L").rstrip("R")
        return len(s) - s.count("S")
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countCollisions(String directions) {
        char[] s = directions.toCharArray();
        int n = s.length;
        int l = 0, r = n - 1;
        while (l < n && s[l] == 'L') {
            ++l;
        }
        while (r >= 0 && s[r] == 'R') {
            --r;
        }
        int ans = r - l + 1;
        for (int i = l; i <= r; ++i) {
            ans -= s[i] == 'S' ? 1 : 0;
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
    int countCollisions(string s) {
        int n = s.size();
        int l = 0, r = n - 1;
        while (l < n && s[l] == 'L') {
            ++l;
        }
        while (r >= 0 && s[r] == 'R') {
            --r;
        }
        return r - l + 1 - count(s.begin() + l, s.begin() + r + 1, 'S');
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countCollisions(directions string) int {
	s := strings.TrimRight(strings.TrimLeft(directions, "L"), "R")
	return len(s) - strings.Count(s, "S")
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countCollisions(directions: string): number {
    const n = directions.length;
    let [l, r] = [0, n - 1];
    while (l < n && directions[l] == 'L') {
        ++l;
    }
    while (r >= 0 && directions[r] == 'R') {
        --r;
    }
    let ans = r - l + 1;
    for (let i = l; i <= r; ++i) {
        if (directions[i] === 'S') {
            --ans;
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {string} directions
 * @return {number}
 */
var countCollisions = function (directions) {
    const n = directions.length;
    let [l, r] = [0, n - 1];
    while (l < n && directions[l] == 'L') {
        ++l;
    }
    while (r >= 0 && directions[r] == 'R') {
        --r;
    }
    let ans = r - l + 1;
    for (let i = l; i <= r; ++i) {
        if (directions[i] === 'S') {
            --ans;
        }
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

<p>在一条无限长的公路上有 <code>n</code> 辆汽车正在行驶。汽车按从左到右的顺序按从 <code>0</code> 到 <code>n - 1</code> 编号，每辆车都在一个 <strong>独特的</strong> 位置。</p>

<p>给你一个下标从 <strong>0</strong> 开始的字符串 <code>directions</code> ，长度为 <code>n</code> 。<code>directions[i]</code> 可以是 <code>'L'</code>、<code>'R'</code> 或 <code>'S'</code> 分别表示第 <code>i</code> 辆车是向 <strong>左</strong> 、向 <strong>右</strong> 或者 <strong>停留</strong> 在当前位置。每辆车移动时 <strong>速度相同</strong> 。</p>

<p>碰撞次数可以按下述方式计算：</p>

<ul>
	<li>当两辆移动方向&nbsp;<strong>相反</strong>&nbsp;的车相撞时，碰撞次数加 <code>2</code> 。</li>
	<li>当一辆移动的车和一辆静止的车相撞时，碰撞次数加 <code>1</code> 。</li>
</ul>

<p>碰撞发生后，涉及的车辆将无法继续移动并停留在碰撞位置。除此之外，汽车不能改变它们的状态或移动方向。</p>

<p>返回在这条道路上发生的 <strong>碰撞总次数</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>directions = "RLRSLL"
<strong>输出：</strong>5
<strong>解释：</strong>
将会在道路上发生的碰撞列出如下：
- 车 0 和车 1 会互相碰撞。由于它们按相反方向移动，碰撞数量变为 0 + 2 = 2 。
- 车 2 和车 3 会互相碰撞。由于 3 是静止的，碰撞数量变为 2 + 1 = 3 。
- 车 3 和车 4 会互相碰撞。由于 3 是静止的，碰撞数量变为 3 + 1 = 4 。
- 车 4 和车 5 会互相碰撞。在车 4 和车 3 碰撞之后，车 4 会待在碰撞位置，接着和车 5 碰撞。碰撞数量变为 4 + 1 = 5 。
因此，将会在道路上发生的碰撞总次数是 5 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>directions = "LLRR"
<strong>输出：</strong>0
<strong>解释：</strong>
不存在会发生碰撞的车辆。因此，将会在道路上发生的碰撞总次数是 0 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= directions.length &lt;= 10<sup>5</sup></code></li>
	<li><code>directions[i]</code> 的值为 <code>'L'</code>、<code>'R'</code> 或 <code>'S'</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：脑筋急转弯

根据题意，当两辆移动方向相反的车相撞时，碰撞次数加 $2$，即两辆车被撞停，答案加 $2$；当一辆移动的车和一辆静止的车相撞时，碰撞次数加 $1$，即一辆车被撞停，答案加 $1$。

而显然前缀的 $\textit{L}$ 和后缀的 $\textit{R}$ 是不会发生碰撞的，所以我们只需要统计中间不等于 $\textit{S}$ 的字符个数即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$ 或 $O(1)$。其中 $n$ 是字符串 $\textit{directions}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countCollisions(self, directions: str) -> int:
        s = directions.lstrip("L").rstrip("R")
        return len(s) - s.count("S")
```

#### Java

```java
class Solution {
    public int countCollisions(String directions) {
        char[] s = directions.toCharArray();
        int n = s.length;
        int l = 0, r = n - 1;
        while (l < n && s[l] == 'L') {
            ++l;
        }
        while (r >= 0 && s[r] == 'R') {
            --r;
        }
        int ans = r - l + 1;
        for (int i = l; i <= r; ++i) {
            ans -= s[i] == 'S' ? 1 : 0;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int countCollisions(string s) {
        int n = s.size();
        int l = 0, r = n - 1;
        while (l < n && s[l] == 'L') {
            ++l;
        }
        while (r >= 0 && s[r] == 'R') {
            --r;
        }
        return r - l + 1 - count(s.begin() + l, s.begin() + r + 1, 'S');
    }
};
```

#### Go

```go
func countCollisions(directions string) int {
	s := strings.TrimRight(strings.TrimLeft(directions, "L"), "R")
	return len(s) - strings.Count(s, "S")
}
```

#### TypeScript

```ts
function countCollisions(directions: string): number {
    const n = directions.length;
    let [l, r] = [0, n - 1];
    while (l < n && directions[l] == 'L') {
        ++l;
    }
    while (r >= 0 && directions[r] == 'R') {
        --r;
    }
    let ans = r - l + 1;
    for (let i = l; i <= r; ++i) {
        if (directions[i] === 'S') {
            --ans;
        }
    }
    return ans;
}
```

#### JavaScript

```js
/**
 * @param {string} directions
 * @return {number}
 */
var countCollisions = function (directions) {
    const n = directions.length;
    let [l, r] = [0, n - 1];
    while (l < n && directions[l] == 'L') {
        ++l;
    }
    while (r >= 0 && directions[r] == 'R') {
        --r;
    }
    let ans = r - l + 1;
    for (let i = l; i <= r; ++i) {
        if (directions[i] === 'S') {
            --ans;
        }
    }
    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2212. 射箭比赛中的最大得分](https://leetcode.cn/problems/maximum-points-in-an-archery-competition){#2212}

{{< tabs "2212" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumBobPoints(self, numArrows: int, aliceArrows: List[int]) -> List[int]:
        st = mx = 0
        m = len(aliceArrows)
        for mask in range(1, 1 << m):
            cnt = s = 0
            for i, x in enumerate(aliceArrows):
                if mask >> i & 1:
                    s += i
                    cnt += x + 1
            if cnt <= numArrows and s > mx:
                mx = s
                st = mask
        ans = [0] * m
        for i, x in enumerate(aliceArrows):
            if st >> i & 1:
                ans[i] = x + 1
                numArrows -= ans[i]
        ans[0] += numArrows
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] maximumBobPoints(int numArrows, int[] aliceArrows) {
        int st = 0, mx = 0;
        int m = aliceArrows.length;
        for (int mask = 1; mask < 1 << m; ++mask) {
            int cnt = 0, s = 0;
            for (int i = 0; i < m; ++i) {
                if ((mask >> i & 1) == 1) {
                    s += i;
                    cnt += aliceArrows[i] + 1;
                }
            }
            if (cnt <= numArrows && s > mx) {
                mx = s;
                st = mask;
            }
        }
        int[] ans = new int[m];
        for (int i = 0; i < m; ++i) {
            if ((st >> i & 1) == 1) {
                ans[i] = aliceArrows[i] + 1;
                numArrows -= ans[i];
            }
        }
        ans[0] += numArrows;
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        int st = 0, mx = 0;
        int m = aliceArrows.size();
        for (int mask = 1; mask < 1 << m; ++mask) {
            int cnt = 0, s = 0;
            for (int i = 0; i < m; ++i) {
                if (mask >> i & 1) {
                    s += i;
                    cnt += aliceArrows[i] + 1;
                }
            }
            if (cnt <= numArrows && s > mx) {
                mx = s;
                st = mask;
            }
        }
        vector<int> ans(m);
        for (int i = 0; i < m; ++i) {
            if (st >> i & 1) {
                ans[i] = aliceArrows[i] + 1;
                numArrows -= ans[i];
            }
        }
        ans[0] += numArrows;
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumBobPoints(numArrows int, aliceArrows []int) []int {
	st, mx := 0, 0
	m := len(aliceArrows)
	for mask := 1; mask < 1<<m; mask++ {
		cnt, s := 0, 0
		for i, x := range aliceArrows {
			if mask>>i&1 == 1 {
				s += i
				cnt += x + 1
			}
		}
		if cnt <= numArrows && s > mx {
			mx = s
			st = mask
		}
	}
	ans := make([]int, m)
	for i, x := range aliceArrows {
		if (st>>i)&1 == 1 {
			ans[i] = x + 1
			numArrows -= ans[i]
		}
	}
	ans[0] += numArrows
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumBobPoints(numArrows: number, aliceArrows: number[]): number[] {
    let [st, mx] = [0, 0];
    const m = aliceArrows.length;
    for (let mask = 1; mask < 1 << m; mask++) {
        let [cnt, s] = [0, 0];
        for (let i = 0; i < m; i++) {
            if ((mask >> i) & 1) {
                cnt += aliceArrows[i] + 1;
                s += i;
            }
        }
        if (cnt <= numArrows && s > mx) {
            mx = s;
            st = mask;
        }
    }
    const ans: number[] = Array(m).fill(0);
    for (let i = 0; i < m; i++) {
        if ((st >> i) & 1) {
            ans[i] = aliceArrows[i] + 1;
            numArrows -= ans[i];
        }
    }
    ans[0] += numArrows;
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn maximum_bob_points(num_arrows: i32, alice_arrows: Vec<i32>) -> Vec<i32> {
        let mut st = 0;
        let mut mx = 0;
        let m = alice_arrows.len();
        for mask in 1..(1 << m) {
            let mut cnt = 0;
            let mut s = 0;
            for i in 0..m {
                if (mask >> i) & 1 == 1 {
                    s += i as i32;
                    cnt += alice_arrows[i] + 1;
                }
            }
            if cnt <= num_arrows && s > mx {
                mx = s;
                st = mask;
            }
        }
        let mut ans = vec![0; m];
        let mut num_arrows = num_arrows;
        for i in 0..m {
            if (st >> i) & 1 == 1 {
                ans[i] = alice_arrows[i] + 1;
                num_arrows -= ans[i];
            }
        }
        ans[0] += num_arrows;
        ans
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number} numArrows
 * @param {number[]} aliceArrows
 * @return {number[]}
 */
var maximumBobPoints = function (numArrows, aliceArrows) {
    let [st, mx] = [0, 0];
    const m = aliceArrows.length;
    for (let mask = 1; mask < 1 << m; mask++) {
        let [cnt, s] = [0, 0];
        for (let i = 0; i < m; i++) {
            if ((mask >> i) & 1) {
                cnt += aliceArrows[i] + 1;
                s += i;
            }
        }
        if (cnt <= numArrows && s > mx) {
            mx = s;
            st = mask;
        }
    }
    const ans = Array(m).fill(0);
    for (let i = 0; i < m; i++) {
        if ((st >> i) & 1) {
            ans[i] = aliceArrows[i] + 1;
            numArrows -= ans[i];
        }
    }
    ans[0] += numArrows;
    return ans;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>Alice 和 Bob 是一场射箭比赛中的对手。比赛规则如下：</p>

<ol>
	<li>Alice 先射 <code>numArrows</code> 支箭，然后 Bob 也射 <code>numArrows</code> 支箭。</li>
	<li>分数按下述规则计算：
	<ol>
		<li>箭靶有若干整数计分区域，范围从 <code>0</code> 到 <code>11</code> （含 <code>0</code> 和 <code>11</code>）。</li>
		<li>箭靶上每个区域都对应一个得分 <code>k</code>（范围是 <code>0</code> 到 <code>11</code>），Alice 和 Bob 分别在得分 <code>k</code>&nbsp;区域射中&nbsp;<code>a<sub>k</sub></code> 和 <code>b<sub>k</sub></code> 支箭。如果 <code>a<sub>k</sub> &gt;= b<sub>k</sub></code> ，那么 Alice 得 <code>k</code> 分。如果 <code>a<sub>k</sub> &lt; b<sub>k</sub></code> ，则 Bob 得 <code>k</code> 分</li>
		<li>如果 <code>a<sub>k</sub> == b<sub>k</sub> == 0</code> ，那么无人得到 <code>k</code> 分。</li>
	</ol>
	</li>
</ol>

<ul>
	<li>
	<p>例如，Alice 和 Bob 都向计分为 <code>11</code> 的区域射 <code>2</code> 支箭，那么 Alice 得 <code>11</code> 分。如果 Alice 向计分为 <code>11</code> 的区域射 <code>0</code> 支箭，但 Bob 向同一个区域射 <code>2</code> 支箭，那么 Bob 得&nbsp;<code>11</code> 分。</p>
	</li>
</ul>

<p>给你整数 <code>numArrows</code> 和一个长度为 <code>12</code> 的整数数组 <code>aliceArrows</code> ，该数组表示 Alice 射中&nbsp;<code>0</code> 到 <code>11</code> 每个计分区域的箭数量。现在，Bob 想要尽可能 <strong>最大化</strong> 他所能获得的总分。</p>

<p>返回数组 <code>bobArrows</code><em> </em>，该数组表示 Bob 射中&nbsp;<code>0</code> 到 <code>11</code> <strong>每个</strong> 计分区域的箭数量。且 <code>bobArrows</code> 的总和应当等于 <code>numArrows</code> 。</p>

<p>如果存在多种方法都可以使 Bob 获得最大总分，返回其中 <strong>任意一种</strong> 即可。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2200-2299/2212.Maximum%20Points%20in%20an%20Archery%20Competition/images/1647744752-kQKrXw-image.png" style="width: 600px; height: 120px;" /></p>

<pre>
<strong>输入：</strong>numArrows = 9, aliceArrows = [1,1,0,1,0,0,2,1,0,1,2,0]
<strong>输出：</strong>[0,0,0,0,1,1,0,0,1,2,3,1]
<strong>解释：</strong>上表显示了比赛得分情况。
Bob 获得总分 4 + 5 + 8 + 9 + 10 + 11 = 47 。
可以证明 Bob 无法获得比 47 更高的分数。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2200-2299/2212.Maximum%20Points%20in%20an%20Archery%20Competition/images/1647744785-cMHzaC-image.png" style="width: 600px; height: 117px;" /></p>

<pre>
<strong>输入：</strong>numArrows = 3, aliceArrows = [0,0,1,0,0,0,0,0,0,0,0,2]
<strong>输出：</strong>[0,0,0,0,0,0,0,0,1,1,1,0]
<strong>解释：</strong>上表显示了比赛得分情况。
Bob 获得总分 8 + 9 + 10 = 27 。
可以证明 Bob 无法获得比 27 更高的分数。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= numArrows &lt;= 10<sup>5</sup></code></li>
	<li><code>aliceArrows.length == bobArrows.length == 12</code></li>
	<li><code>0 &lt;= aliceArrows[i], bobArrows[i] &lt;= numArrows</code></li>
	<li><code>sum(aliceArrows[i]) == numArrows</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二进制枚举

由于区域数目只有 $12$ 个，因此我们使用二进制枚举的方式，枚举 $\textit{Bob}$ 在哪些区域得分。用一个变量 $\textit{st}$ 表示 $\textit{Bob}$ 获得最大得分的方案，而 $\textit{mx}$ 表示 $\textit{Bob}$ 获得的最大得分。

我们在 $[1, 2^m)$ 的区间内枚举 $\textit{Bob}$ 的得分方案，其中 $m$ 是 $\textit{aliceArrows}$ 的长度。对于每一个方案，我们计算 $\textit{Bob}$ 的得分 $\textit{s}$ 以及射箭的数量 $\textit{cnt}$。如果 $\textit{cnt} \leq \textit{numArrows}$ 且 $\textit{s} > \textit{mx}$，我们就更新 $\textit{mx}$ 和 $\textit{st}$。

然后，我们根据 $\textit{st}$ 计算 $\textit{Bob}$ 的得分方案，如果最后还有剩余的射箭，我们将剩余的射箭分配给第一个区域，即下标为 $0$ 的区域。

时间复杂度 $O(2^m \times m)$，其中 $m$ 是 $\textit{aliceArrows}$ 的长度。忽略答案数组的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumBobPoints(self, numArrows: int, aliceArrows: List[int]) -> List[int]:
        st = mx = 0
        m = len(aliceArrows)
        for mask in range(1, 1 << m):
            cnt = s = 0
            for i, x in enumerate(aliceArrows):
                if mask >> i & 1:
                    s += i
                    cnt += x + 1
            if cnt <= numArrows and s > mx:
                mx = s
                st = mask
        ans = [0] * m
        for i, x in enumerate(aliceArrows):
            if st >> i & 1:
                ans[i] = x + 1
                numArrows -= ans[i]
        ans[0] += numArrows
        return ans
```

#### Java

```java
class Solution {
    public int[] maximumBobPoints(int numArrows, int[] aliceArrows) {
        int st = 0, mx = 0;
        int m = aliceArrows.length;
        for (int mask = 1; mask < 1 << m; ++mask) {
            int cnt = 0, s = 0;
            for (int i = 0; i < m; ++i) {
                if ((mask >> i & 1) == 1) {
                    s += i;
                    cnt += aliceArrows[i] + 1;
                }
            }
            if (cnt <= numArrows && s > mx) {
                mx = s;
                st = mask;
            }
        }
        int[] ans = new int[m];
        for (int i = 0; i < m; ++i) {
            if ((st >> i & 1) == 1) {
                ans[i] = aliceArrows[i] + 1;
                numArrows -= ans[i];
            }
        }
        ans[0] += numArrows;
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        int st = 0, mx = 0;
        int m = aliceArrows.size();
        for (int mask = 1; mask < 1 << m; ++mask) {
            int cnt = 0, s = 0;
            for (int i = 0; i < m; ++i) {
                if (mask >> i & 1) {
                    s += i;
                    cnt += aliceArrows[i] + 1;
                }
            }
            if (cnt <= numArrows && s > mx) {
                mx = s;
                st = mask;
            }
        }
        vector<int> ans(m);
        for (int i = 0; i < m; ++i) {
            if (st >> i & 1) {
                ans[i] = aliceArrows[i] + 1;
                numArrows -= ans[i];
            }
        }
        ans[0] += numArrows;
        return ans;
    }
};
```

#### Go

```go
func maximumBobPoints(numArrows int, aliceArrows []int) []int {
	st, mx := 0, 0
	m := len(aliceArrows)
	for mask := 1; mask < 1<<m; mask++ {
		cnt, s := 0, 0
		for i, x := range aliceArrows {
			if mask>>i&1 == 1 {
				s += i
				cnt += x + 1
			}
		}
		if cnt <= numArrows && s > mx {
			mx = s
			st = mask
		}
	}
	ans := make([]int, m)
	for i, x := range aliceArrows {
		if (st>>i)&1 == 1 {
			ans[i] = x + 1
			numArrows -= ans[i]
		}
	}
	ans[0] += numArrows
	return ans
}
```

#### TypeScript

```ts
function maximumBobPoints(numArrows: number, aliceArrows: number[]): number[] {
    let [st, mx] = [0, 0];
    const m = aliceArrows.length;
    for (let mask = 1; mask < 1 << m; mask++) {
        let [cnt, s] = [0, 0];
        for (let i = 0; i < m; i++) {
            if ((mask >> i) & 1) {
                cnt += aliceArrows[i] + 1;
                s += i;
            }
        }
        if (cnt <= numArrows && s > mx) {
            mx = s;
            st = mask;
        }
    }
    const ans: number[] = Array(m).fill(0);
    for (let i = 0; i < m; i++) {
        if ((st >> i) & 1) {
            ans[i] = aliceArrows[i] + 1;
            numArrows -= ans[i];
        }
    }
    ans[0] += numArrows;
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn maximum_bob_points(num_arrows: i32, alice_arrows: Vec<i32>) -> Vec<i32> {
        let mut st = 0;
        let mut mx = 0;
        let m = alice_arrows.len();
        for mask in 1..(1 << m) {
            let mut cnt = 0;
            let mut s = 0;
            for i in 0..m {
                if (mask >> i) & 1 == 1 {
                    s += i as i32;
                    cnt += alice_arrows[i] + 1;
                }
            }
            if cnt <= num_arrows && s > mx {
                mx = s;
                st = mask;
            }
        }
        let mut ans = vec![0; m];
        let mut num_arrows = num_arrows;
        for i in 0..m {
            if (st >> i) & 1 == 1 {
                ans[i] = alice_arrows[i] + 1;
                num_arrows -= ans[i];
            }
        }
        ans[0] += num_arrows;
        ans
    }
}
```

#### JavaScript

```js
/**
 * @param {number} numArrows
 * @param {number[]} aliceArrows
 * @return {number[]}
 */
var maximumBobPoints = function (numArrows, aliceArrows) {
    let [st, mx] = [0, 0];
    const m = aliceArrows.length;
    for (let mask = 1; mask < 1 << m; mask++) {
        let [cnt, s] = [0, 0];
        for (let i = 0; i < m; i++) {
            if ((mask >> i) & 1) {
                cnt += aliceArrows[i] + 1;
                s += i;
            }
        }
        if (cnt <= numArrows && s > mx) {
            mx = s;
            st = mask;
        }
    }
    const ans = Array(m).fill(0);
    for (let i = 0; i < m; i++) {
        if ((st >> i) & 1) {
            ans[i] = aliceArrows[i] + 1;
            numArrows -= ans[i];
        }
    }
    ans[0] += numArrows;
    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2213. 由单个字符重复的最长子字符串](https://leetcode.cn/problems/longest-substring-of-one-repeating-character){#2213}

{{< tabs "2213" >}}

{{% tab "python" %}}
```python
def max(a: int, b: int) -> int:
    return a if a > b else b


class Node:
    __slots__ = "l", "r", "lmx", "rmx", "mx"

    def __init__(self, l: int, r: int):
        self.l = l
        self.r = r
        self.lmx = self.rmx = self.mx = 1


class SegmentTree:
    __slots__ = "s", "tr"

    def __init__(self, s: str):
        self.s = list(s)
        n = len(s)
        self.tr: List[Node | None] = [None] * (n * 4)
        self.build(1, 1, n)

    def build(self, u: int, l: int, r: int):
        self.tr[u] = Node(l, r)
        if l == r:
            return
        mid = (l + r) // 2
        self.build(u << 1, l, mid)
        self.build(u << 1 | 1, mid + 1, r)
        self.pushup(u)

    def query(self, u: int, l: int, r: int) -> int:
        if self.tr[u].l >= l and self.tr[u].r <= r:
            return self.tr[u].mx
        mid = (self.tr[u].l + self.tr[u].r) // 2
        ans = 0
        if r <= mid:
            ans = self.query(u << 1, l, r)
        if l > mid:
            ans = max(ans, self.query(u << 1 | 1, l, r))
        return ans

    def modify(self, u: int, x: int, v: str):
        if self.tr[u].l == self.tr[u].r:
            self.s[x - 1] = v
            return
        mid = (self.tr[u].l + self.tr[u].r) // 2
        if x <= mid:
            self.modify(u << 1, x, v)
        else:
            self.modify(u << 1 | 1, x, v)
        self.pushup(u)

    def pushup(self, u: int):
        root, left, right = self.tr[u], self.tr[u << 1], self.tr[u << 1 | 1]
        root.lmx = left.lmx
        root.rmx = right.rmx
        root.mx = max(left.mx, right.mx)
        a, b = left.r - left.l + 1, right.r - right.l + 1
        if self.s[left.r - 1] == self.s[right.l - 1]:
            if left.lmx == a:
                root.lmx += right.lmx
            if right.rmx == b:
                root.rmx += left.rmx
            root.mx = max(root.mx, left.rmx + right.lmx)


class Solution:
    def longestRepeating(
        self, s: str, queryCharacters: str, queryIndices: List[int]
    ) -> List[int]:
        tree = SegmentTree(s)
        ans = []
        for x, v in zip(queryIndices, queryCharacters):
            tree.modify(1, x + 1, v)
            ans.append(tree.query(1, 1, len(s)))
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Node {
    int l, r;
    int lmx, rmx, mx;

    Node(int l, int r) {
        this.l = l;
        this.r = r;
        lmx = rmx = mx = 1;
    }
}

class SegmentTree {
    private char[] s;
    private Node[] tr;

    public SegmentTree(char[] s) {
        int n = s.length;
        this.s = s;
        tr = new Node[n << 2];
        build(1, 1, n);
    }

    public void build(int u, int l, int r) {
        tr[u] = new Node(l, r);
        if (l == r) {
            return;
        }
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }

    public void modify(int u, int x, char v) {
        if (tr[u].l == x && tr[u].r == x) {
            s[x - 1] = v;
            return;
        }
        int mid = (tr[u].l + tr[u].r) >> 1;
        if (x <= mid) {
            modify(u << 1, x, v);
        } else {
            modify(u << 1 | 1, x, v);
        }
        pushup(u);
    }

    public int query(int u, int l, int r) {
        if (tr[u].l >= l && tr[u].r <= r) {
            return tr[u].mx;
        }
        int mid = (tr[u].l + tr[u].r) >> 1;
        int ans = 0;
        if (r <= mid) {
            ans = query(u << 1, l, r);
        }
        if (l > mid) {
            ans = Math.max(ans, query(u << 1 | 1, l, r));
        }
        return ans;
    }

    private void pushup(int u) {
        Node root = tr[u];
        Node left = tr[u << 1], right = tr[u << 1 | 1];
        root.mx = Math.max(left.mx, right.mx);
        root.lmx = left.lmx;
        root.rmx = right.rmx;
        int a = left.r - left.l + 1;
        int b = right.r - right.l + 1;
        if (s[left.r - 1] == s[right.l - 1]) {
            if (left.lmx == a) {
                root.lmx += right.lmx;
            }
            if (right.rmx == b) {
                root.rmx += left.rmx;
            }
            root.mx = Math.max(root.mx, left.rmx + right.lmx);
        }
    }
}

class Solution {
    public int[] longestRepeating(String s, String queryCharacters, int[] queryIndices) {
        SegmentTree tree = new SegmentTree(s.toCharArray());
        int k = queryIndices.length;
        int[] ans = new int[k];
        int n = s.length();
        for (int i = 0; i < k; ++i) {
            int x = queryIndices[i] + 1;
            char v = queryCharacters.charAt(i);
            tree.modify(1, x, v);
            ans[i] = tree.query(1, 1, n);
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Node {
public:
    int l, r;
    int lmx, rmx, mx;

    Node(int l, int r)
        : l(l)
        , r(r)
        , lmx(1)
        , rmx(1)
        , mx(1) {}
};

class SegmentTree {
private:
    string s;
    vector<Node*> tr;

    void build(int u, int l, int r) {
        tr[u] = new Node(l, r);
        if (l == r) {
            return;
        }
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }

    void pushup(int u) {
        Node* root = tr[u];
        Node* left = tr[u << 1];
        Node* right = tr[u << 1 | 1];
        root->mx = max(left->mx, right->mx);
        root->lmx = left->lmx;
        root->rmx = right->rmx;
        int a = left->r - left->l + 1;
        int b = right->r - right->l + 1;
        if (s[left->r - 1] == s[right->l - 1]) {
            if (left->lmx == a) {
                root->lmx += right->lmx;
            }
            if (right->rmx == b) {
                root->rmx += left->rmx;
            }
            root->mx = max(root->mx, left->rmx + right->lmx);
        }
    }

public:
    SegmentTree(const string& s)
        : s(s) {
        int n = s.size();
        tr.resize(n * 4);
        build(1, 1, n);
    }

    void modify(int u, int x, char v) {
        if (tr[u]->l == x && tr[u]->r == x) {
            s[x - 1] = v;
            return;
        }
        int mid = (tr[u]->l + tr[u]->r) >> 1;
        if (x <= mid) {
            modify(u << 1, x, v);
        } else {
            modify(u << 1 | 1, x, v);
        }
        pushup(u);
    }

    int query(int u, int l, int r) {
        if (tr[u]->l >= l && tr[u]->r <= r) {
            return tr[u]->mx;
        }
        int mid = (tr[u]->l + tr[u]->r) >> 1;
        int ans = 0;
        if (r <= mid) {
            ans = query(u << 1, l, r);
        } else if (l > mid) {
            ans = max(ans, query(u << 1 | 1, l, r));
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        SegmentTree tree(s);
        int k = queryIndices.size();
        vector<int> ans(k);
        int n = s.size();
        for (int i = 0; i < k; ++i) {
            int x = queryIndices[i] + 1;
            char v = queryCharacters[i];
            tree.modify(1, x, v);
            ans[i] = tree.query(1, 1, n);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
type Node struct {
	l, r         int
	lmx, rmx, mx int
}

type SegmentTree struct {
	s  []byte
	tr []*Node
}

func NewNode(l, r int) *Node {
	return &Node{l: l, r: r, lmx: 1, rmx: 1, mx: 1}
}

func NewSegmentTree(s string) *SegmentTree {
	n := len(s)
	tree := &SegmentTree{s: []byte(s), tr: make([]*Node, n<<2)}
	tree.build(1, 1, n)
	return tree
}

func (tree *SegmentTree) build(u, l, r int) {
	tree.tr[u] = NewNode(l, r)
	if l == r {
		return
	}
	mid := (l + r) >> 1
	tree.build(u<<1, l, mid)
	tree.build(u<<1|1, mid+1, r)
	tree.pushup(u)
}

func (tree *SegmentTree) modify(u, x int, v byte) {
	if tree.tr[u].l == x && tree.tr[u].r == x {
		tree.s[x-1] = v
		return
	}
	mid := (tree.tr[u].l + tree.tr[u].r) >> 1
	if x <= mid {
		tree.modify(u<<1, x, v)
	} else {
		tree.modify(u<<1|1, x, v)
	}
	tree.pushup(u)
}

func (tree *SegmentTree) query(u, l, r int) int {
	if tree.tr[u].l >= l && tree.tr[u].r <= r {
		return tree.tr[u].mx
	}
	mid := (tree.tr[u].l + tree.tr[u].r) >> 1
	ans := 0
	if r <= mid {
		ans = tree.query(u<<1, l, r)
	} else if l > mid {
		ans = max(ans, tree.query(u<<1|1, l, r))
	} else {
		ans = max(tree.query(u<<1, l, r), tree.query(u<<1|1, l, r))
	}
	return ans
}

func (tree *SegmentTree) pushup(u int) {
	root := tree.tr[u]
	left := tree.tr[u<<1]
	right := tree.tr[u<<1|1]
	root.mx = max(left.mx, right.mx)
	root.lmx = left.lmx
	root.rmx = right.rmx
	a := left.r - left.l + 1
	b := right.r - right.l + 1
	if tree.s[left.r-1] == tree.s[right.l-1] {
		if left.lmx == a {
			root.lmx += right.lmx
		}
		if right.rmx == b {
			root.rmx += left.rmx
		}
		root.mx = max(root.mx, left.rmx+right.lmx)
	}
}

func longestRepeating(s string, queryCharacters string, queryIndices []int) (ans []int) {
	tree := NewSegmentTree(s)
	n := len(s)
	for i, v := range queryCharacters {
		x := queryIndices[i] + 1
		tree.modify(1, x, byte(v))
		ans = append(ans, tree.query(1, 1, n))
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class Node {
    l: number;
    r: number;
    lmx: number;
    rmx: number;
    mx: number;

    constructor(l: number, r: number) {
        this.l = l;
        this.r = r;
        this.lmx = 1;
        this.rmx = 1;
        this.mx = 1;
    }
}

class SegmentTree {
    private s: string[];
    private tr: Node[];

    constructor(s: string) {
        this.s = s.split('');
        this.tr = Array(s.length * 4)
            .fill(null)
            .map(() => new Node(0, 0));
        this.build(1, 1, s.length);
    }

    private build(u: number, l: number, r: number): void {
        this.tr[u] = new Node(l, r);
        if (l === r) {
            return;
        }
        const mid = (l + r) >> 1;
        this.build(u << 1, l, mid);
        this.build((u << 1) | 1, mid + 1, r);
        this.pushup(u);
    }

    public modify(u: number, x: number, v: string): void {
        if (this.tr[u].l === x && this.tr[u].r === x) {
            this.s[x - 1] = v;
            return;
        }
        const mid = (this.tr[u].l + this.tr[u].r) >> 1;
        if (x <= mid) {
            this.modify(u << 1, x, v);
        } else {
            this.modify((u << 1) | 1, x, v);
        }
        this.pushup(u);
    }

    public query(u: number, l: number, r: number): number {
        if (this.tr[u].l >= l && this.tr[u].r <= r) {
            return this.tr[u].mx;
        }
        const mid = (this.tr[u].l + this.tr[u].r) >> 1;
        let ans = 0;
        if (r <= mid) {
            ans = this.query(u << 1, l, r);
        } else if (l > mid) {
            ans = Math.max(ans, this.query((u << 1) | 1, l, r));
        } else {
            ans = Math.max(this.query(u << 1, l, r), this.query((u << 1) | 1, l, r));
        }
        return ans;
    }

    private pushup(u: number): void {
        const root = this.tr[u];
        const left = this.tr[u << 1];
        const right = this.tr[(u << 1) | 1];
        root.mx = Math.max(left.mx, right.mx);
        root.lmx = left.lmx;
        root.rmx = right.rmx;
        const a = left.r - left.l + 1;
        const b = right.r - right.l + 1;
        if (this.s[left.r - 1] === this.s[right.l - 1]) {
            if (left.lmx === a) {
                root.lmx += right.lmx;
            }
            if (right.rmx === b) {
                root.rmx += left.rmx;
            }
            root.mx = Math.max(root.mx, left.rmx + right.lmx);
        }
    }
}

function longestRepeating(s: string, queryCharacters: string, queryIndices: number[]): number[] {
    const tree = new SegmentTree(s);
    const k = queryIndices.length;
    const ans: number[] = new Array(k);
    const n = s.length;
    for (let i = 0; i < k; ++i) {
        const x = queryIndices[i] + 1;
        const v = queryCharacters[i];
        tree.modify(1, x, v);
        ans[i] = tree.query(1, 1, n);
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

<p>给你一个下标从 <strong>0</strong> 开始的字符串 <code>s</code> 。另给你一个下标从 <strong>0</strong> 开始、长度为 <code>k</code> 的字符串 <code>queryCharacters</code> ，一个下标从 <code>0</code> 开始、长度也是 <code>k</code> 的整数 <strong>下标</strong> 数组&nbsp;<code>queryIndices</code> ，这两个都用来描述 <code>k</code> 个查询。</p>

<p>第 <code>i</code> 个查询会将 <code>s</code> 中位于下标 <code>queryIndices[i]</code> 的字符更新为 <code>queryCharacters[i]</code> 。</p>

<p>返回一个长度为 <code>k</code> 的数组 <code>lengths</code> ，其中 <code>lengths[i]</code> 是在执行第 <code>i</code> 个查询 <strong>之后</strong> <code>s</code> 中仅由 <strong>单个字符重复</strong> 组成的 <strong>最长子字符串</strong> 的 <strong>长度</strong> <em>。</em></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "babacc", queryCharacters = "bcb", queryIndices = [1,3,3]
<strong>输出：</strong>[3,3,4]
<strong>解释：</strong>
- 第 1 次查询更新后 s = "<em>b<strong>b</strong>b</em>acc" 。由单个字符重复组成的最长子字符串是 "bbb" ，长度为 3 。
- 第 2 次查询更新后 s = "bbb<em><strong>c</strong>cc</em>" 。由单个字符重复组成的最长子字符串是 "bbb" 或 "ccc"，长度为 3 。
- 第 3 次查询更新后 s = "<em>bbb<strong>b</strong></em>cc" 。由单个字符重复组成的最长子字符串是 "bbbb" ，长度为 4 。
因此，返回 [3,3,4] 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "abyzz", queryCharacters = "aa", queryIndices = [2,1]
<strong>输出：</strong>[2,3]
<strong>解释：</strong>
- 第 1 次查询更新后 s = "ab<strong>a</strong><em>zz</em>" 。由单个字符重复组成的最长子字符串是 "zz" ，长度为 2 。
- 第 2 次查询更新后 s = "<em>a<strong>a</strong>a</em>zz" 。由单个字符重复组成的最长子字符串是 "aaa" ，长度为 3 。
因此，返回 [2,3] 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> 由小写英文字母组成</li>
	<li><code>k == queryCharacters.length == queryIndices.length</code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>5</sup></code></li>
	<li><code>queryCharacters</code> 由小写英文字母组成</li>
	<li><code>0 &lt;= queryIndices[i] &lt; s.length</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：线段树

线段树将整个区间分割为多个不连续的子区间，子区间的数量不超过 $\log(\textit{width})$。更新某个元素的值，只需要更新 $\log(\textit{width})$ 个区间，并且这些区间都包含在一个包含该元素的大区间内。区间修改时，需要使用**懒标记**保证效率。

-   线段树的每个节点代表一个区间；
-   线段树具有唯一的根节点，代表的区间是整个统计范围，如 $[1, n]$；
-   线段树的每个叶子节点代表一个长度为 $1$ 的元区间 $[x, x]$；
-   对于每个内部节点 $[l, r]$，它的左儿子是 $[l, mid]$，右儿子是 $[mid + 1, r]$, 其中 $mid = \frac{l + r}{2}$；

对于本题，线段树节点维护的信息有：

1. 前缀最长连续字符个数 $lmx$；
1. 后缀最长连续字符个数 $rmx$；
1. 区间最长连续字符个数 $mx$。
1. 区间左端点 $l$ 和右端点 $r$。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n \times \log n)$。其中 $n$ 是字符串 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
def max(a: int, b: int) -> int:
    return a if a > b else b


class Node:
    __slots__ = "l", "r", "lmx", "rmx", "mx"

    def __init__(self, l: int, r: int):
        self.l = l
        self.r = r
        self.lmx = self.rmx = self.mx = 1


class SegmentTree:
    __slots__ = "s", "tr"

    def __init__(self, s: str):
        self.s = list(s)
        n = len(s)
        self.tr: List[Node | None] = [None] * (n * 4)
        self.build(1, 1, n)

    def build(self, u: int, l: int, r: int):
        self.tr[u] = Node(l, r)
        if l == r:
            return
        mid = (l + r) // 2
        self.build(u << 1, l, mid)
        self.build(u << 1 | 1, mid + 1, r)
        self.pushup(u)

    def query(self, u: int, l: int, r: int) -> int:
        if self.tr[u].l >= l and self.tr[u].r <= r:
            return self.tr[u].mx
        mid = (self.tr[u].l + self.tr[u].r) // 2
        ans = 0
        if r <= mid:
            ans = self.query(u << 1, l, r)
        if l > mid:
            ans = max(ans, self.query(u << 1 | 1, l, r))
        return ans

    def modify(self, u: int, x: int, v: str):
        if self.tr[u].l == self.tr[u].r:
            self.s[x - 1] = v
            return
        mid = (self.tr[u].l + self.tr[u].r) // 2
        if x <= mid:
            self.modify(u << 1, x, v)
        else:
            self.modify(u << 1 | 1, x, v)
        self.pushup(u)

    def pushup(self, u: int):
        root, left, right = self.tr[u], self.tr[u << 1], self.tr[u << 1 | 1]
        root.lmx = left.lmx
        root.rmx = right.rmx
        root.mx = max(left.mx, right.mx)
        a, b = left.r - left.l + 1, right.r - right.l + 1
        if self.s[left.r - 1] == self.s[right.l - 1]:
            if left.lmx == a:
                root.lmx += right.lmx
            if right.rmx == b:
                root.rmx += left.rmx
            root.mx = max(root.mx, left.rmx + right.lmx)


class Solution:
    def longestRepeating(
        self, s: str, queryCharacters: str, queryIndices: List[int]
    ) -> List[int]:
        tree = SegmentTree(s)
        ans = []
        for x, v in zip(queryIndices, queryCharacters):
            tree.modify(1, x + 1, v)
            ans.append(tree.query(1, 1, len(s)))
        return ans
```

#### Java

```java
class Node {
    int l, r;
    int lmx, rmx, mx;

    Node(int l, int r) {
        this.l = l;
        this.r = r;
        lmx = rmx = mx = 1;
    }
}

class SegmentTree {
    private char[] s;
    private Node[] tr;

    public SegmentTree(char[] s) {
        int n = s.length;
        this.s = s;
        tr = new Node[n << 2];
        build(1, 1, n);
    }

    public void build(int u, int l, int r) {
        tr[u] = new Node(l, r);
        if (l == r) {
            return;
        }
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }

    public void modify(int u, int x, char v) {
        if (tr[u].l == x && tr[u].r == x) {
            s[x - 1] = v;
            return;
        }
        int mid = (tr[u].l + tr[u].r) >> 1;
        if (x <= mid) {
            modify(u << 1, x, v);
        } else {
            modify(u << 1 | 1, x, v);
        }
        pushup(u);
    }

    public int query(int u, int l, int r) {
        if (tr[u].l >= l && tr[u].r <= r) {
            return tr[u].mx;
        }
        int mid = (tr[u].l + tr[u].r) >> 1;
        int ans = 0;
        if (r <= mid) {
            ans = query(u << 1, l, r);
        }
        if (l > mid) {
            ans = Math.max(ans, query(u << 1 | 1, l, r));
        }
        return ans;
    }

    private void pushup(int u) {
        Node root = tr[u];
        Node left = tr[u << 1], right = tr[u << 1 | 1];
        root.mx = Math.max(left.mx, right.mx);
        root.lmx = left.lmx;
        root.rmx = right.rmx;
        int a = left.r - left.l + 1;
        int b = right.r - right.l + 1;
        if (s[left.r - 1] == s[right.l - 1]) {
            if (left.lmx == a) {
                root.lmx += right.lmx;
            }
            if (right.rmx == b) {
                root.rmx += left.rmx;
            }
            root.mx = Math.max(root.mx, left.rmx + right.lmx);
        }
    }
}

class Solution {
    public int[] longestRepeating(String s, String queryCharacters, int[] queryIndices) {
        SegmentTree tree = new SegmentTree(s.toCharArray());
        int k = queryIndices.length;
        int[] ans = new int[k];
        int n = s.length();
        for (int i = 0; i < k; ++i) {
            int x = queryIndices[i] + 1;
            char v = queryCharacters.charAt(i);
            tree.modify(1, x, v);
            ans[i] = tree.query(1, 1, n);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Node {
public:
    int l, r;
    int lmx, rmx, mx;

    Node(int l, int r)
        : l(l)
        , r(r)
        , lmx(1)
        , rmx(1)
        , mx(1) {}
};

class SegmentTree {
private:
    string s;
    vector<Node*> tr;

    void build(int u, int l, int r) {
        tr[u] = new Node(l, r);
        if (l == r) {
            return;
        }
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }

    void pushup(int u) {
        Node* root = tr[u];
        Node* left = tr[u << 1];
        Node* right = tr[u << 1 | 1];
        root->mx = max(left->mx, right->mx);
        root->lmx = left->lmx;
        root->rmx = right->rmx;
        int a = left->r - left->l + 1;
        int b = right->r - right->l + 1;
        if (s[left->r - 1] == s[right->l - 1]) {
            if (left->lmx == a) {
                root->lmx += right->lmx;
            }
            if (right->rmx == b) {
                root->rmx += left->rmx;
            }
            root->mx = max(root->mx, left->rmx + right->lmx);
        }
    }

public:
    SegmentTree(const string& s)
        : s(s) {
        int n = s.size();
        tr.resize(n * 4);
        build(1, 1, n);
    }

    void modify(int u, int x, char v) {
        if (tr[u]->l == x && tr[u]->r == x) {
            s[x - 1] = v;
            return;
        }
        int mid = (tr[u]->l + tr[u]->r) >> 1;
        if (x <= mid) {
            modify(u << 1, x, v);
        } else {
            modify(u << 1 | 1, x, v);
        }
        pushup(u);
    }

    int query(int u, int l, int r) {
        if (tr[u]->l >= l && tr[u]->r <= r) {
            return tr[u]->mx;
        }
        int mid = (tr[u]->l + tr[u]->r) >> 1;
        int ans = 0;
        if (r <= mid) {
            ans = query(u << 1, l, r);
        } else if (l > mid) {
            ans = max(ans, query(u << 1 | 1, l, r));
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        SegmentTree tree(s);
        int k = queryIndices.size();
        vector<int> ans(k);
        int n = s.size();
        for (int i = 0; i < k; ++i) {
            int x = queryIndices[i] + 1;
            char v = queryCharacters[i];
            tree.modify(1, x, v);
            ans[i] = tree.query(1, 1, n);
        }
        return ans;
    }
};
```

#### Go

```go
type Node struct {
	l, r         int
	lmx, rmx, mx int
}

type SegmentTree struct {
	s  []byte
	tr []*Node
}

func NewNode(l, r int) *Node {
	return &Node{l: l, r: r, lmx: 1, rmx: 1, mx: 1}
}

func NewSegmentTree(s string) *SegmentTree {
	n := len(s)
	tree := &SegmentTree{s: []byte(s), tr: make([]*Node, n<<2)}
	tree.build(1, 1, n)
	return tree
}

func (tree *SegmentTree) build(u, l, r int) {
	tree.tr[u] = NewNode(l, r)
	if l == r {
		return
	}
	mid := (l + r) >> 1
	tree.build(u<<1, l, mid)
	tree.build(u<<1|1, mid+1, r)
	tree.pushup(u)
}

func (tree *SegmentTree) modify(u, x int, v byte) {
	if tree.tr[u].l == x && tree.tr[u].r == x {
		tree.s[x-1] = v
		return
	}
	mid := (tree.tr[u].l + tree.tr[u].r) >> 1
	if x <= mid {
		tree.modify(u<<1, x, v)
	} else {
		tree.modify(u<<1|1, x, v)
	}
	tree.pushup(u)
}

func (tree *SegmentTree) query(u, l, r int) int {
	if tree.tr[u].l >= l && tree.tr[u].r <= r {
		return tree.tr[u].mx
	}
	mid := (tree.tr[u].l + tree.tr[u].r) >> 1
	ans := 0
	if r <= mid {
		ans = tree.query(u<<1, l, r)
	} else if l > mid {
		ans = max(ans, tree.query(u<<1|1, l, r))
	} else {
		ans = max(tree.query(u<<1, l, r), tree.query(u<<1|1, l, r))
	}
	return ans
}

func (tree *SegmentTree) pushup(u int) {
	root := tree.tr[u]
	left := tree.tr[u<<1]
	right := tree.tr[u<<1|1]
	root.mx = max(left.mx, right.mx)
	root.lmx = left.lmx
	root.rmx = right.rmx
	a := left.r - left.l + 1
	b := right.r - right.l + 1
	if tree.s[left.r-1] == tree.s[right.l-1] {
		if left.lmx == a {
			root.lmx += right.lmx
		}
		if right.rmx == b {
			root.rmx += left.rmx
		}
		root.mx = max(root.mx, left.rmx+right.lmx)
	}
}

func longestRepeating(s string, queryCharacters string, queryIndices []int) (ans []int) {
	tree := NewSegmentTree(s)
	n := len(s)
	for i, v := range queryCharacters {
		x := queryIndices[i] + 1
		tree.modify(1, x, byte(v))
		ans = append(ans, tree.query(1, 1, n))
	}
	return
}
```

#### TypeScript

```ts
class Node {
    l: number;
    r: number;
    lmx: number;
    rmx: number;
    mx: number;

    constructor(l: number, r: number) {
        this.l = l;
        this.r = r;
        this.lmx = 1;
        this.rmx = 1;
        this.mx = 1;
    }
}

class SegmentTree {
    private s: string[];
    private tr: Node[];

    constructor(s: string) {
        this.s = s.split('');
        this.tr = Array(s.length * 4)
            .fill(null)
            .map(() => new Node(0, 0));
        this.build(1, 1, s.length);
    }

    private build(u: number, l: number, r: number): void {
        this.tr[u] = new Node(l, r);
        if (l === r) {
            return;
        }
        const mid = (l + r) >> 1;
        this.build(u << 1, l, mid);
        this.build((u << 1) | 1, mid + 1, r);
        this.pushup(u);
    }

    public modify(u: number, x: number, v: string): void {
        if (this.tr[u].l === x && this.tr[u].r === x) {
            this.s[x - 1] = v;
            return;
        }
        const mid = (this.tr[u].l + this.tr[u].r) >> 1;
        if (x <= mid) {
            this.modify(u << 1, x, v);
        } else {
            this.modify((u << 1) | 1, x, v);
        }
        this.pushup(u);
    }

    public query(u: number, l: number, r: number): number {
        if (this.tr[u].l >= l && this.tr[u].r <= r) {
            return this.tr[u].mx;
        }
        const mid = (this.tr[u].l + this.tr[u].r) >> 1;
        let ans = 0;
        if (r <= mid) {
            ans = this.query(u << 1, l, r);
        } else if (l > mid) {
            ans = Math.max(ans, this.query((u << 1) | 1, l, r));
        } else {
            ans = Math.max(this.query(u << 1, l, r), this.query((u << 1) | 1, l, r));
        }
        return ans;
    }

    private pushup(u: number): void {
        const root = this.tr[u];
        const left = this.tr[u << 1];
        const right = this.tr[(u << 1) | 1];
        root.mx = Math.max(left.mx, right.mx);
        root.lmx = left.lmx;
        root.rmx = right.rmx;
        const a = left.r - left.l + 1;
        const b = right.r - right.l + 1;
        if (this.s[left.r - 1] === this.s[right.l - 1]) {
            if (left.lmx === a) {
                root.lmx += right.lmx;
            }
            if (right.rmx === b) {
                root.rmx += left.rmx;
            }
            root.mx = Math.max(root.mx, left.rmx + right.lmx);
        }
    }
}

function longestRepeating(s: string, queryCharacters: string, queryIndices: number[]): number[] {
    const tree = new SegmentTree(s);
    const k = queryIndices.length;
    const ans: number[] = new Array(k);
    const n = s.length;
    for (let i = 0; i < k; ++i) {
        const x = queryIndices[i] + 1;
        const v = queryCharacters[i];
        tree.modify(1, x, v);
        ans[i] = tree.query(1, 1, n);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2214. 通关游戏所需的最低生命值 🔒](https://leetcode.cn/problems/minimum-health-to-beat-game){#2214}

{{< tabs "2214" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumHealth(self, damage: List[int], armor: int) -> int:
        return sum(damage) - min(max(damage), armor) + 1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long minimumHealth(int[] damage, int armor) {
        long s = 0;
        int mx = damage[0];
        for (int v : damage) {
            s += v;
            mx = Math.max(mx, v);
        }
        return s - Math.min(mx, armor) + 1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    long long minimumHealth(vector<int>& damage, int armor) {
        long long s = 0;
        int mx = damage[0];
        for (int& v : damage) {
            s += v;
            mx = max(mx, v);
        }
        return s - min(mx, armor) + 1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumHealth(damage []int, armor int) int64 {
	var s int64
	var mx int
	for _, v := range damage {
		s += int64(v)
		mx = max(mx, v)
	}
	return s - int64(min(mx, armor)) + 1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumHealth(damage: number[], armor: number): number {
    let s = 0;
    let mx = 0;
    for (const v of damage) {
        mx = Math.max(mx, v);
        s += v;
    }
    return s - Math.min(mx, armor) + 1;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你正在玩一个有 <code>n</code> 个关卡的游戏，从 <code>0</code> 到 <code>n - 1</code>。给你一个&nbsp;<strong>下标从 0&nbsp;开始&nbsp;</strong>的整数数组 <code>damage</code>，其中 <code>damage[i]</code> 是你完成第 <code>i</code> 个关卡所损失的生命值。</p>

<p>你也会得到一个整数 <code>armor</code>。你最多只能在&nbsp;<strong>任何&nbsp;</strong>关卡使用&nbsp;<strong>一次&nbsp;</strong>护甲技能，这将保护你免受 <strong>最多</strong>&nbsp;<code>armor</code> 伤害。</p>

<p>你必须按顺序完成关卡，并且你的生命值必须一直&nbsp;<strong>大于</strong> <code>0</code> 才能通关。</p>

<p>返回<em>你开始通关所需的最低生命值。</em></p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> damage = [2,7,4,3], armor = 4
<strong>输出:</strong> 13
<strong>解释:</strong> 从 13 生命值开始通关游戏的最佳方法是:
第 1 回合，受到 2 点伤害。你还有 13 - 2 = 11 生命值。
第 2 回合，受到 7 点伤害。你还有 11 - 7 = 4 生命值。
第 3 回合，使用你的护甲保护你免受 4 点伤害。你有 4 - 0 = 4 生命值。
第 4 回合，受到 3 点伤害。你还有 4 - 3 = 1 生命值。
注意，13 是你开始时通关游戏所需的最低生命值。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> damage = [2,5,3,4], armor = 7
<strong>输出:</strong> 10
<strong>解释:</strong> 从 10 生命值开始通关游戏的最佳方法是:
第 1 回合，受到 2 点伤害。你还有 10 - 2 = 8 生命值。
第 2 回合，使用护甲保护自己免受 5 点伤害。你还有 8 - 0 = 8 生命值。
第 3 回合，受到 3 点伤害。你还有 8 - 3 = 5 生命值。
第 4 回合，受到 4 点伤害。你还有 5 - 4 = 1 生命值。
注意，10 是你开始通关所需的最低生命值。
</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入:</strong> damage = [3,3,3], armor = 0
<strong>输出:</strong> 10
<strong>解释:</strong> 从 10 生命值开始通关游戏的最佳方法是:
第 1 回合，受到 2 点伤害。你还有 10 - 3 = 7 生命值。
第 2 回合，受到 3 点伤害。你还有 7 - 3 = 4 生命值。
第 3 回合， 受到 3 点伤害。你还有 4 - 3 = 1 生命值。
注意你没有使用护甲技能。</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>n == damage.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= damage[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= armor &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心

我们可以贪心地选择在伤害值最大的回合中使用一次护甲技能，假设伤害值最大为 $\textit{mx}$，那么我们可以免受 $\min(\textit{mx}, \textit{armor})$ 的伤害，因此我们需要的最小生命值为 $\sum(\textit{damage}) - \min(\textit{mx}, \textit{armor}) + 1$。

时间复杂度 $O(n)$，其中 $n$ 为数组 $\textit{damage}$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumHealth(self, damage: List[int], armor: int) -> int:
        return sum(damage) - min(max(damage), armor) + 1
```

#### Java

```java
class Solution {
    public long minimumHealth(int[] damage, int armor) {
        long s = 0;
        int mx = damage[0];
        for (int v : damage) {
            s += v;
            mx = Math.max(mx, v);
        }
        return s - Math.min(mx, armor) + 1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long minimumHealth(vector<int>& damage, int armor) {
        long long s = 0;
        int mx = damage[0];
        for (int& v : damage) {
            s += v;
            mx = max(mx, v);
        }
        return s - min(mx, armor) + 1;
    }
};
```

#### Go

```go
func minimumHealth(damage []int, armor int) int64 {
	var s int64
	var mx int
	for _, v := range damage {
		s += int64(v)
		mx = max(mx, v)
	}
	return s - int64(min(mx, armor)) + 1
}
```

#### TypeScript

```ts
function minimumHealth(damage: number[], armor: number): number {
    let s = 0;
    let mx = 0;
    for (const v of damage) {
        mx = Math.max(mx, v);
        s += v;
    }
    return s - Math.min(mx, armor) + 1;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2215. 找出两数组的不同](https://leetcode.cn/problems/find-the-difference-of-two-arrays){#2215}

{{< tabs "2215" >}}

{{% tab "python" %}}
```python
class Solution:
    def findDifference(self, nums1: List[int], nums2: List[int]) -> List[List[int]]:
        s1, s2 = set(nums1), set(nums2)
        return [list(s1 - s2), list(s2 - s1)]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<List<Integer>> findDifference(int[] nums1, int[] nums2) {
        Set<Integer> s1 = convert(nums1);
        Set<Integer> s2 = convert(nums2);
        List<Integer> l1 = new ArrayList<>();
        List<Integer> l2 = new ArrayList<>();
        for (int v : s1) {
            if (!s2.contains(v)) {
                l1.add(v);
            }
        }
        for (int v : s2) {
            if (!s1.contains(v)) {
                l2.add(v);
            }
        }
        return List.of(l1, l2);
    }

    private Set<Integer> convert(int[] nums) {
        Set<Integer> s = new HashSet<>();
        for (int v : nums) {
            s.add(v);
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
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());
        vector<vector<int>> ans(2);
        for (int v : s1) {
            if (!s2.contains(v)) {
                ans[0].push_back(v);
            }
        }
        for (int v : s2) {
            if (!s1.contains(v)) {
                ans[1].push_back(v);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findDifference(nums1 []int, nums2 []int) [][]int {
	s1, s2 := make(map[int]bool), make(map[int]bool)
	for _, v := range nums1 {
		s1[v] = true
	}
	for _, v := range nums2 {
		s2[v] = true
	}
	ans := make([][]int, 2)
	for v := range s1 {
		if !s2[v] {
			ans[0] = append(ans[0], v)
		}
	}
	for v := range s2 {
		if !s1[v] {
			ans[1] = append(ans[1], v)
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findDifference(nums1: number[], nums2: number[]): number[][] {
    const s1: Set<number> = new Set(nums1);
    const s2: Set<number> = new Set(nums2);
    nums1.forEach(num => s2.delete(num));
    nums2.forEach(num => s1.delete(num));
    return [Array.from(s1), Array.from(s2)];
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashSet;
impl Solution {
    pub fn find_difference(nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<Vec<i32>> {
        vec![
            nums1
                .iter()
                .filter_map(|&v| if nums2.contains(&v) { None } else { Some(v) })
                .collect::<HashSet<i32>>()
                .into_iter()
                .collect(),
            nums2
                .iter()
                .filter_map(|&v| if nums1.contains(&v) { None } else { Some(v) })
                .collect::<HashSet<i32>>()
                .into_iter()
                .collect(),
        ]
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[][]}
 */
var findDifference = function (nums1, nums2) {
    const s1 = new Set(nums1);
    const s2 = new Set(nums2);
    nums1.forEach(num => s2.delete(num));
    nums2.forEach(num => s1.delete(num));
    return [Array.from(s1), Array.from(s2)];
};
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param Integer[] $nums1
     * @param Integer[] $nums2
     * @return Integer[][]
     */
    function findDifference($nums1, $nums2) {
        $s1 = array_flip($nums1);
        $s2 = array_flip($nums2);

        $diff1 = array_diff_key($s1, $s2);
        $diff2 = array_diff_key($s2, $s1);

        return [array_keys($diff1), array_keys($diff2)];
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个下标从 <code>0</code> 开始的整数数组 <code>nums1</code> 和 <code>nums2</code> ，请你返回一个长度为 <code>2</code> 的列表 <code>answer</code> ，其中：</p>

<ul>
	<li><code>answer[0]</code> 是 <code>nums1</code> 中所有<strong> 不 </strong>存在于 <code>nums2</code> 中的 <strong>不同</strong> 整数组成的列表。</li>
	<li><code>answer[1]</code> 是 <code>nums2</code> 中所有<strong> 不 </strong>存在于 <code>nums1</code> 中的 <strong>不同</strong> 整数组成的列表。</li>
</ul>

<p><strong>注意：</strong>列表中的整数可以按 <strong>任意</strong> 顺序返回。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums1 = [1,2,3], nums2 = [2,4,6]
<strong>输出：</strong>[[1,3],[4,6]]
<strong>解释：
</strong>对于 nums1 ，nums1[1] = 2 出现在 nums2 中下标 0 处，然而 nums1[0] = 1 和 nums1[2] = 3 没有出现在 nums2 中。因此，answer[0] = [1,3]。
对于 nums2 ，nums2[0] = 2 出现在 nums1 中下标 1 处，然而 nums2[1] = 4 和 nums2[2] = 6 没有出现在 nums2 中。因此，answer[1] = [4,6]。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums1 = [1,2,3,3], nums2 = [1,1,2,2]
<strong>输出：</strong>[[3],[]]
<strong>解释：
</strong>对于 nums1 ，nums1[2] 和 nums1[3] 没有出现在 nums2 中。由于 nums1[2] == nums1[3] ，二者的值只需要在 answer[0] 中出现一次，故 answer[0] = [3]。
nums2 中的每个整数都在 nums1 中出现，因此，answer[1] = [] 。 
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums1.length, nums2.length &lt;= 1000</code></li>
	<li><code>-1000 &lt;= nums1[i], nums2[i] &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

我们定义两个哈希表 $s1$ 和 $s2$ 分别存储数组 $nums1$ 和 $nums2$ 中的元素。然后遍历 $s1$ 中的每个元素，如果该元素不在 $s2$ 中，那么将其加入到答案的第一个列表中。同理，遍历 $s2$ 中的每个元素，如果该元素不在 $s1$ 中，那么将其加入到答案的第二个列表中。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findDifference(self, nums1: List[int], nums2: List[int]) -> List[List[int]]:
        s1, s2 = set(nums1), set(nums2)
        return [list(s1 - s2), list(s2 - s1)]
```

#### Java

```java
class Solution {
    public List<List<Integer>> findDifference(int[] nums1, int[] nums2) {
        Set<Integer> s1 = convert(nums1);
        Set<Integer> s2 = convert(nums2);
        List<Integer> l1 = new ArrayList<>();
        List<Integer> l2 = new ArrayList<>();
        for (int v : s1) {
            if (!s2.contains(v)) {
                l1.add(v);
            }
        }
        for (int v : s2) {
            if (!s1.contains(v)) {
                l2.add(v);
            }
        }
        return List.of(l1, l2);
    }

    private Set<Integer> convert(int[] nums) {
        Set<Integer> s = new HashSet<>();
        for (int v : nums) {
            s.add(v);
        }
        return s;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());
        vector<vector<int>> ans(2);
        for (int v : s1) {
            if (!s2.contains(v)) {
                ans[0].push_back(v);
            }
        }
        for (int v : s2) {
            if (!s1.contains(v)) {
                ans[1].push_back(v);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func findDifference(nums1 []int, nums2 []int) [][]int {
	s1, s2 := make(map[int]bool), make(map[int]bool)
	for _, v := range nums1 {
		s1[v] = true
	}
	for _, v := range nums2 {
		s2[v] = true
	}
	ans := make([][]int, 2)
	for v := range s1 {
		if !s2[v] {
			ans[0] = append(ans[0], v)
		}
	}
	for v := range s2 {
		if !s1[v] {
			ans[1] = append(ans[1], v)
		}
	}
	return ans
}
```

#### TypeScript

```ts
function findDifference(nums1: number[], nums2: number[]): number[][] {
    const s1: Set<number> = new Set(nums1);
    const s2: Set<number> = new Set(nums2);
    nums1.forEach(num => s2.delete(num));
    nums2.forEach(num => s1.delete(num));
    return [Array.from(s1), Array.from(s2)];
}
```

#### Rust

```rust
use std::collections::HashSet;
impl Solution {
    pub fn find_difference(nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<Vec<i32>> {
        vec![
            nums1
                .iter()
                .filter_map(|&v| if nums2.contains(&v) { None } else { Some(v) })
                .collect::<HashSet<i32>>()
                .into_iter()
                .collect(),
            nums2
                .iter()
                .filter_map(|&v| if nums1.contains(&v) { None } else { Some(v) })
                .collect::<HashSet<i32>>()
                .into_iter()
                .collect(),
        ]
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[][]}
 */
var findDifference = function (nums1, nums2) {
    const s1 = new Set(nums1);
    const s2 = new Set(nums2);
    nums1.forEach(num => s2.delete(num));
    nums2.forEach(num => s1.delete(num));
    return [Array.from(s1), Array.from(s2)];
};
```

#### PHP

```php
class Solution {
    /**
     * @param Integer[] $nums1
     * @param Integer[] $nums2
     * @return Integer[][]
     */
    function findDifference($nums1, $nums2) {
        $s1 = array_flip($nums1);
        $s2 = array_flip($nums2);

        $diff1 = array_diff_key($s1, $s2);
        $diff2 = array_diff_key($s2, $s1);

        return [array_keys($diff1), array_keys($diff2)];
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2216. 美化数组的最少删除数](https://leetcode.cn/problems/minimum-deletions-to-make-array-beautiful){#2216}

{{< tabs "2216" >}}

{{% tab "python" %}}
```python
class Solution:
    def minDeletion(self, nums: List[int]) -> int:
        n = len(nums)
        ans = i = 0
        while i < n:
            j = i + 1
            while j < n and nums[j] == nums[i]:
                j += 1
                ans += 1
            i = j + 1
        ans += (n - ans) % 2
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minDeletion(int[] nums) {
        int n = nums.length;
        int ans = 0;
        for (int i = 0; i < n;) {
            int j = i + 1;
            while (j < n && nums[j] == nums[i]) {
                ++j;
                ++ans;
            }
            i = j + 1;
        }
        ans += (n - ans) % 2;
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n;) {
            int j = i + 1;
            while (j < n && nums[j] == nums[i]) {
                ++j;
                ++ans;
            }
            i = j + 1;
        }
        ans += (n - ans) % 2;
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minDeletion(nums []int) (ans int) {
	n := len(nums)
	for i := 0; i < n; {
		j := i + 1
		for ; j < n && nums[j] == nums[i]; j++ {
			ans++
		}
		i = j + 1
	}
	ans += (n - ans) % 2
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minDeletion(nums: number[]): number {
    const n = nums.length;
    let ans = 0;
    for (let i = 0; i < n; ) {
        let j = i + 1;
        for (; j < n && nums[j] === nums[i]; ++j) {
            ++ans;
        }
        i = j + 1;
    }
    ans += (n - ans) % 2;
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn min_deletion(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut ans = 0;
        let mut i = 0;
        while i < n {
            let mut j = i + 1;
            while j < n && nums[j] == nums[i] {
                ans += 1;
                j += 1;
            }
            i = j + 1;
        }
        ans += (n - ans) % 2;
        ans as i32
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong> 开始的整数数组 <code>nums</code> ，如果满足下述条件，则认为数组 <code>nums</code> 是一个 <strong>美丽数组</strong> ：</p>

<ul>
	<li><code>nums.length</code> 为偶数</li>
	<li>对所有满足 <code>i % 2 == 0</code> 的下标 <code>i</code> ，<code>nums[i] != nums[i + 1]</code> 均成立</li>
</ul>

<p>注意，空数组同样认为是美丽数组。</p>

<p>你可以从 <code>nums</code> 中删除任意数量的元素。当你删除一个元素时，被删除元素右侧的所有元素将会向左移动一个单位以填补空缺，而左侧的元素将会保持 <strong>不变</strong> 。</p>

<p>返回使 <code>nums</code> 变为美丽数组所需删除的 <strong>最少</strong> 元素数目<em>。</em></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [1,1,2,3,5]
<strong>输出：</strong>1
<strong>解释：</strong>可以删除 <code>nums[0]</code> 或 <code>nums[1]</code> ，这样得到的 <code>nums</code> = [1,2,3,5] 是一个美丽数组。可以证明，要想使 nums 变为美丽数组，至少需要删除 1 个元素。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [1,1,2,2,3,3]
<strong>输出：</strong>2
<strong>解释：</strong>可以删除 <code>nums[0]</code> 和 <code>nums[5]</code> ，这样得到的 nums = [1,2,2,3] 是一个美丽数组。可以证明，要想使 nums 变为美丽数组，至少需要删除 2 个元素。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心

根据题目描述，我们知道，一个美丽数组有偶数个元素，且如果我们把这个数组中每相邻两个元素划分为一组，那么每一组中的两个元素都不相等。这意味着，组内的元素不能重复，但组与组之间的元素可以重复。

因此，我们考虑从左到右遍历数组，只要遇到相邻两个元素相等，我们就将其中的一个元素删除，即删除数加一；否则，我们可以保留这两个元素。

最后，我们判断删除后的数组长度是否为偶数，如果不是，则说明我们需要再删除一个元素，使得最终的数组长度为偶数。

时间复杂度 $O(n)$，其中 $n$ 是数组的长度。我们只需要遍历数组一次。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minDeletion(self, nums: List[int]) -> int:
        n = len(nums)
        i = ans = 0
        while i < n - 1:
            if nums[i] == nums[i + 1]:
                ans += 1
                i += 1
            else:
                i += 2
        ans += (n - ans) % 2
        return ans
```

#### Java

```java
class Solution {
    public int minDeletion(int[] nums) {
        int n = nums.length;
        int ans = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] == nums[i + 1]) {
                ++ans;
            } else {
                ++i;
            }
        }
        ans += (n - ans) % 2;
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] == nums[i + 1]) {
                ++ans;
            } else {
                ++i;
            }
        }
        ans += (n - ans) % 2;
        return ans;
    }
};
```

#### Go

```go
func minDeletion(nums []int) (ans int) {
	n := len(nums)
	for i := 0; i < n-1; i++ {
		if nums[i] == nums[i+1] {
			ans++
		} else {
			i++
		}
	}
	ans += (n - ans) % 2
	return
}
```

#### TypeScript

```ts
function minDeletion(nums: number[]): number {
    const n = nums.length;
    let ans = 0;
    for (let i = 0; i < n - 1; ++i) {
        if (nums[i] === nums[i + 1]) {
            ++ans;
        } else {
            ++i;
        }
    }
    ans += (n - ans) % 2;
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn min_deletion(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut ans = 0;
        let mut i = 0;
        while i < n - 1 {
            if nums[i] == nums[i + 1] {
                ans += 1;
                i += 1;
            } else {
                i += 2;
            }
        }
        ans += (n - ans) % 2;
        ans as i32
    }
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
    def minDeletion(self, nums: List[int]) -> int:
        n = len(nums)
        ans = i = 0
        while i < n:
            j = i + 1
            while j < n and nums[j] == nums[i]:
                j += 1
                ans += 1
            i = j + 1
        ans += (n - ans) % 2
        return ans
```

#### Java

```java
class Solution {
    public int minDeletion(int[] nums) {
        int n = nums.length;
        int ans = 0;
        for (int i = 0; i < n;) {
            int j = i + 1;
            while (j < n && nums[j] == nums[i]) {
                ++j;
                ++ans;
            }
            i = j + 1;
        }
        ans += (n - ans) % 2;
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n;) {
            int j = i + 1;
            while (j < n && nums[j] == nums[i]) {
                ++j;
                ++ans;
            }
            i = j + 1;
        }
        ans += (n - ans) % 2;
        return ans;
    }
};
```

#### Go

```go
func minDeletion(nums []int) (ans int) {
	n := len(nums)
	for i := 0; i < n; {
		j := i + 1
		for ; j < n && nums[j] == nums[i]; j++ {
			ans++
		}
		i = j + 1
	}
	ans += (n - ans) % 2
	return
}
```

#### TypeScript

```ts
function minDeletion(nums: number[]): number {
    const n = nums.length;
    let ans = 0;
    for (let i = 0; i < n; ) {
        let j = i + 1;
        for (; j < n && nums[j] === nums[i]; ++j) {
            ++ans;
        }
        i = j + 1;
    }
    ans += (n - ans) % 2;
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn min_deletion(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut ans = 0;
        let mut i = 0;
        while i < n {
            let mut j = i + 1;
            while j < n && nums[j] == nums[i] {
                ans += 1;
                j += 1;
            }
            i = j + 1;
        }
        ans += (n - ans) % 2;
        ans as i32
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2217. 找到指定长度的回文数](https://leetcode.cn/problems/find-palindrome-with-fixed-length){#2217}

{{< tabs "2217" >}}

{{% tab "python" %}}
```python
class Solution:
    def kthPalindrome(self, queries: List[int], intLength: int) -> List[int]:
        l = (intLength + 1) >> 1
        start, end = 10 ** (l - 1), 10**l - 1
        ans = []
        for q in queries:
            v = start + q - 1
            if v > end:
                ans.append(-1)
                continue
            s = str(v)
            s += s[::-1][intLength % 2 :]
            ans.append(int(s))
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long[] kthPalindrome(int[] queries, int intLength) {
        int n = queries.length;
        long[] ans = new long[n];
        int l = (intLength + 1) >> 1;
        long start = (long) Math.pow(10, l - 1);
        long end = (long) Math.pow(10, l) - 1;
        for (int i = 0; i < n; ++i) {
            long v = start + queries[i] - 1;
            if (v > end) {
                ans[i] = -1;
                continue;
            }
            String s = "" + v;
            s += new StringBuilder(s).reverse().substring(intLength % 2);
            ans[i] = Long.parseLong(s);
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
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        int l = (intLength + 1) >> 1;
        long long start = pow(10, l - 1), end = pow(10, l) - 1;
        vector<long long> ans;
        for (int& q : queries) {
            long long v = start + q - 1;
            if (v > end) {
                ans.push_back(-1);
                continue;
            }
            string s = to_string(v);
            string s1 = s;
            reverse(s1.begin(), s1.end());
            s += s1.substr(intLength % 2);
            ans.push_back(stoll(s));
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func kthPalindrome(queries []int, intLength int) []int64 {
	l := (intLength + 1) >> 1
	start, end := int(math.Pow10(l-1)), int(math.Pow10(l))-1
	var ans []int64
	for _, q := range queries {
		v := start + q - 1
		if v > end {
			ans = append(ans, -1)
			continue
		}
		t := v
		if intLength%2 == 1 {
			t /= 10
		}
		for t > 0 {
			v = v*10 + t%10
			t /= 10
		}
		ans = append(ans, int64(v))
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function kthPalindrome(queries: number[], intLength: number): number[] {
    const isOdd = intLength % 2 === 1;
    const bestNum = 10 ** ((intLength >> 1) + (isOdd ? 1 : 0) - 1);
    const max = bestNum * 9;
    return queries.map(v => {
        if (v > max) {
            return -1;
        }
        const num = bestNum + v - 1;
        return Number(
            num +
                (num + '')
                    .split('')
                    .reverse()
                    .slice(isOdd ? 1 : 0)
                    .join(''),
        );
    });
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn kth_palindrome(queries: Vec<i32>, int_length: i32) -> Vec<i64> {
        let is_odd = (int_length & 1) == 1;
        let best_num = i32::pow(10, (int_length / 2 + (if is_odd { 0 } else { -1 })) as u32);
        let max = best_num * 9;
        queries
            .iter()
            .map(|&num| {
                if num > max {
                    return -1;
                }
                let num = best_num + num - 1;
                format!(
                    "{}{}",
                    num,
                    num.to_string()
                        .chars()
                        .rev()
                        .skip(if is_odd { 1 } else { 0 })
                        .collect::<String>()
                )
                .parse()
                .unwrap()
            })
            .collect()
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组&nbsp;<code>queries</code>&nbsp;和一个 <strong>正</strong>&nbsp;整数&nbsp;<code>intLength</code>&nbsp;，请你返回一个数组&nbsp;<code>answer</code>&nbsp;，其中&nbsp;<code>answer[i]</code> 是长度为&nbsp;<code>intLength</code>&nbsp;的&nbsp;<strong>正回文数</strong> 中第<em>&nbsp;</em><code>queries[i]</code>&nbsp;小的数字，如果不存在这样的回文数，则为 <code>-1</code>&nbsp;。</p>

<p><strong>回文数</strong> 指的是从前往后和从后往前读一模一样的数字。回文数不能有前导 0 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>queries = [1,2,3,4,5,90], intLength = 3
<b>输出：</b>[101,111,121,131,141,999]
<strong>解释：</strong>
长度为 3 的最小回文数依次是：
101, 111, 121, 131, 141, 151, 161, 171, 181, 191, 202, ...
第 90 个长度为 3 的回文数是 999 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>queries = [2,4,6], intLength = 4
<b>输出：</b>[1111,1331,1551]
<strong>解释：</strong>
长度为 4 的前 6 个回文数是：
1001, 1111, 1221, 1331, 1441 和 1551 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= queries.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= queries[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= intLength&nbsp;&lt;= 15</code></li>
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
    def kthPalindrome(self, queries: List[int], intLength: int) -> List[int]:
        l = (intLength + 1) >> 1
        start, end = 10 ** (l - 1), 10**l - 1
        ans = []
        for q in queries:
            v = start + q - 1
            if v > end:
                ans.append(-1)
                continue
            s = str(v)
            s += s[::-1][intLength % 2 :]
            ans.append(int(s))
        return ans
```

#### Java

```java
class Solution {
    public long[] kthPalindrome(int[] queries, int intLength) {
        int n = queries.length;
        long[] ans = new long[n];
        int l = (intLength + 1) >> 1;
        long start = (long) Math.pow(10, l - 1);
        long end = (long) Math.pow(10, l) - 1;
        for (int i = 0; i < n; ++i) {
            long v = start + queries[i] - 1;
            if (v > end) {
                ans[i] = -1;
                continue;
            }
            String s = "" + v;
            s += new StringBuilder(s).reverse().substring(intLength % 2);
            ans[i] = Long.parseLong(s);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        int l = (intLength + 1) >> 1;
        long long start = pow(10, l - 1), end = pow(10, l) - 1;
        vector<long long> ans;
        for (int& q : queries) {
            long long v = start + q - 1;
            if (v > end) {
                ans.push_back(-1);
                continue;
            }
            string s = to_string(v);
            string s1 = s;
            reverse(s1.begin(), s1.end());
            s += s1.substr(intLength % 2);
            ans.push_back(stoll(s));
        }
        return ans;
    }
};
```

#### Go

```go
func kthPalindrome(queries []int, intLength int) []int64 {
	l := (intLength + 1) >> 1
	start, end := int(math.Pow10(l-1)), int(math.Pow10(l))-1
	var ans []int64
	for _, q := range queries {
		v := start + q - 1
		if v > end {
			ans = append(ans, -1)
			continue
		}
		t := v
		if intLength%2 == 1 {
			t /= 10
		}
		for t > 0 {
			v = v*10 + t%10
			t /= 10
		}
		ans = append(ans, int64(v))
	}
	return ans
}
```

#### TypeScript

```ts
function kthPalindrome(queries: number[], intLength: number): number[] {
    const isOdd = intLength % 2 === 1;
    const bestNum = 10 ** ((intLength >> 1) + (isOdd ? 1 : 0) - 1);
    const max = bestNum * 9;
    return queries.map(v => {
        if (v > max) {
            return -1;
        }
        const num = bestNum + v - 1;
        return Number(
            num +
                (num + '')
                    .split('')
                    .reverse()
                    .slice(isOdd ? 1 : 0)
                    .join(''),
        );
    });
}
```

#### Rust

```rust
impl Solution {
    pub fn kth_palindrome(queries: Vec<i32>, int_length: i32) -> Vec<i64> {
        let is_odd = (int_length & 1) == 1;
        let best_num = i32::pow(10, (int_length / 2 + (if is_odd { 0 } else { -1 })) as u32);
        let max = best_num * 9;
        queries
            .iter()
            .map(|&num| {
                if num > max {
                    return -1;
                }
                let num = best_num + num - 1;
                format!(
                    "{}{}",
                    num,
                    num.to_string()
                        .chars()
                        .rev()
                        .skip(if is_odd { 1 } else { 0 })
                        .collect::<String>()
                )
                .parse()
                .unwrap()
            })
            .collect()
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2218. 从栈中取出 K 个硬币的最大面值和](https://leetcode.cn/problems/maximum-value-of-k-coins-from-piles){#2218}

{{< tabs "2218" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxValueOfCoins(self, piles: List[List[int]], k: int) -> int:
        f = [0] * (k + 1)
        for nums in piles:
            s = list(accumulate(nums, initial=0))
            for j in range(k, -1, -1):
                for h, w in enumerate(s):
                    if j < h:
                        break
                    f[j] = max(f[j], f[j - h] + w)
        return f[k]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxValueOfCoins(List<List<Integer>> piles, int k) {
        int[] f = new int[k + 1];
        for (var nums : piles) {
            int[] s = new int[nums.size() + 1];
            for (int j = 1; j <= nums.size(); ++j) {
                s[j] = s[j - 1] + nums.get(j - 1);
            }
            for (int j = k; j >= 0; --j) {
                for (int h = 0; h < s.length && h <= j; ++h) {
                    f[j] = Math.max(f[j], f[j - h] + s[h]);
                }
            }
        }
        return f[k];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        vector<int> f(k + 1);
        for (auto& nums : piles) {
            vector<int> s(nums.size() + 1);
            for (int j = 1; j <= nums.size(); ++j) {
                s[j] = s[j - 1] + nums[j - 1];
            }
            for (int j = k; j >= 0; --j) {
                for (int h = 0; h < s.size() && h <= j; ++h) {
                    f[j] = max(f[j], f[j - h] + s[h]);
                }
            }
        }
        return f[k];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxValueOfCoins(piles [][]int, k int) int {
	f := make([]int, k+1)
	for _, nums := range piles {
		s := make([]int, len(nums)+1)
		for j := 1; j <= len(nums); j++ {
			s[j] = s[j-1] + nums[j-1]
		}
		for j := k; j >= 0; j-- {
			for h := 0; h < len(s) && h <= j; h++ {
				f[j] = max(f[j], f[j-h]+s[h])
			}
		}
	}
	return f[k]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxValueOfCoins(piles: number[][], k: number): number {
    const f: number[] = Array(k + 1).fill(0);
    for (const nums of piles) {
        const s: number[] = Array(nums.length + 1).fill(0);
        for (let j = 1; j <= nums.length; j++) {
            s[j] = s[j - 1] + nums[j - 1];
        }
        for (let j = k; j >= 0; j--) {
            for (let h = 0; h < s.length && h <= j; h++) {
                f[j] = Math.max(f[j], f[j - h] + s[h]);
            }
        }
    }
    return f[k];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>一张桌子上总共有 <code>n</code>&nbsp;个硬币 <b>栈</b>&nbsp;。每个栈有 <strong>正整数</strong>&nbsp;个带面值的硬币。</p>

<p>每一次操作中，你可以从任意一个栈的 <strong>顶部</strong>&nbsp;取出 1 个硬币，从栈中移除它，并放入你的钱包里。</p>

<p>给你一个列表&nbsp;<code>piles</code>&nbsp;，其中&nbsp;<code>piles[i]</code>&nbsp;是一个整数数组，分别表示第 <code>i</code>&nbsp;个栈里 <strong>从顶到底</strong>&nbsp;的硬币面值。同时给你一个正整数&nbsp;<code>k</code>&nbsp;，请你返回在&nbsp;<strong>恰好</strong>&nbsp;进行&nbsp;<code>k</code>&nbsp;次操作的前提下，你钱包里硬币面值之和&nbsp;<strong>最大为多少</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2200-2299/2218.Maximum%20Value%20of%20K%20Coins%20From%20Piles/images/e1.png" style="width: 600px; height: 243px;" /></p>

<pre>
<b>输入：</b>piles = [[1,100,3],[7,8,9]], k = 2
<b>输出：</b>101
<strong>解释：</strong>
上图展示了几种选择 k 个硬币的不同方法。
我们可以得到的最大面值为 101 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>piles = [[100],[100],[100],[100],[100],[100],[1,1,1,1,1,1,700]], k = 7
<b>输出：</b>706
<strong>解释：
</strong>如果我们所有硬币都从最后一个栈中取，可以得到最大面值和。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == piles.length</code></li>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
	<li><code>1 &lt;= piles[i][j] &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= k &lt;= sum(piles[i].length) &lt;= 2000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划（分组背包）

我们定义 $f[i][j]$ 表示从前 $i$ 组中取出 $j$ 个硬币的最大面值和，那么答案为 $f[n][k]$，其中 $n$ 为栈的数量。

对于第 $i$ 组，我们可以选择取前 $0$, $1$, $2$, $\cdots$, $k$ 个硬币。我们可以通过前缀和数组 $s$ 来快速计算出取前 $h$ 个硬币的面值和。

状态转移方程为：

$$
f[i][j] = \max(f[i][j], f[i - 1][j - h] + s[h])
$$

其中 $0 \leq h \leq j$，而 $s[h]$ 表示第 $i$ 组中取前 $h$ 个硬币的面值和。

时间复杂度 $O(k \times L)$，空间复杂度 $O(n \times k)$。其中 $L$ 为所有硬币的数量，而 $n$ 为栈的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxValueOfCoins(self, piles: List[List[int]], k: int) -> int:
        n = len(piles)
        f = [[0] * (k + 1) for _ in range(n + 1)]
        for i, nums in enumerate(piles, 1):
            s = list(accumulate(nums, initial=0))
            for j in range(k + 1):
                for h, w in enumerate(s):
                    if j < h:
                        break
                    f[i][j] = max(f[i][j], f[i - 1][j - h] + w)
        return f[n][k]
```

#### Java

```java
class Solution {
    public int maxValueOfCoins(List<List<Integer>> piles, int k) {
        int n = piles.size();
        int[][] f = new int[n + 1][k + 1];
        for (int i = 1; i <= n; i++) {
            List<Integer> nums = piles.get(i - 1);
            int[] s = new int[nums.size() + 1];
            s[0] = 0;
            for (int j = 1; j <= nums.size(); j++) {
                s[j] = s[j - 1] + nums.get(j - 1);
            }
            for (int j = 0; j <= k; j++) {
                for (int h = 0; h < s.length && h <= j; h++) {
                    f[i][j] = Math.max(f[i][j], f[i - 1][j - h] + s[h]);
                }
            }
        }
        return f[n][k];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector<vector<int>> f(n + 1, vector<int>(k + 1));
        for (int i = 1; i <= n; i++) {
            vector<int> nums = piles[i - 1];
            vector<int> s(nums.size() + 1);
            for (int j = 1; j <= nums.size(); j++) {
                s[j] = s[j - 1] + nums[j - 1];
            }
            for (int j = 0; j <= k; j++) {
                for (int h = 0; h < s.size() && h <= j; h++) {
                    f[i][j] = max(f[i][j], f[i - 1][j - h] + s[h]);
                }
            }
        }
        return f[n][k];
    }
};
```

#### Go

```go
func maxValueOfCoins(piles [][]int, k int) int {
	n := len(piles)
	f := make([][]int, n+1)
	for i := range f {
		f[i] = make([]int, k+1)
	}
	for i := 1; i <= n; i++ {
		nums := piles[i-1]
		s := make([]int, len(nums)+1)
		for j := 1; j <= len(nums); j++ {
			s[j] = s[j-1] + nums[j-1]
		}

		for j := 0; j <= k; j++ {
			for h, w := range s {
				if j < h {
					break
				}
				f[i][j] = max(f[i][j], f[i-1][j-h]+w)
			}
		}
	}
	return f[n][k]
}
```

#### TypeScript

```ts
function maxValueOfCoins(piles: number[][], k: number): number {
    const n = piles.length;
    const f: number[][] = Array.from({ length: n + 1 }, () => Array(k + 1).fill(0));
    for (let i = 1; i <= n; i++) {
        const nums = piles[i - 1];
        const s = Array(nums.length + 1).fill(0);
        for (let j = 1; j <= nums.length; j++) {
            s[j] = s[j - 1] + nums[j - 1];
        }
        for (let j = 0; j <= k; j++) {
            for (let h = 0; h < s.length && h <= j; h++) {
                f[i][j] = Math.max(f[i][j], f[i - 1][j - h] + s[h]);
            }
        }
    }
    return f[n][k];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：动态规划（空间优化）

我们可以发现，对于第 $i$ 组，我们只需要用到 $f[i - 1][j]$ 和 $f[i][j - h]$，因此我们可以将二维数组优化为一维数组。

时间复杂度 $O(k \times L)$，空间复杂度 $O(k)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxValueOfCoins(self, piles: List[List[int]], k: int) -> int:
        f = [0] * (k + 1)
        for nums in piles:
            s = list(accumulate(nums, initial=0))
            for j in range(k, -1, -1):
                for h, w in enumerate(s):
                    if j < h:
                        break
                    f[j] = max(f[j], f[j - h] + w)
        return f[k]
```

#### Java

```java
class Solution {
    public int maxValueOfCoins(List<List<Integer>> piles, int k) {
        int[] f = new int[k + 1];
        for (var nums : piles) {
            int[] s = new int[nums.size() + 1];
            for (int j = 1; j <= nums.size(); ++j) {
                s[j] = s[j - 1] + nums.get(j - 1);
            }
            for (int j = k; j >= 0; --j) {
                for (int h = 0; h < s.length && h <= j; ++h) {
                    f[j] = Math.max(f[j], f[j - h] + s[h]);
                }
            }
        }
        return f[k];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        vector<int> f(k + 1);
        for (auto& nums : piles) {
            vector<int> s(nums.size() + 1);
            for (int j = 1; j <= nums.size(); ++j) {
                s[j] = s[j - 1] + nums[j - 1];
            }
            for (int j = k; j >= 0; --j) {
                for (int h = 0; h < s.size() && h <= j; ++h) {
                    f[j] = max(f[j], f[j - h] + s[h]);
                }
            }
        }
        return f[k];
    }
};
```

#### Go

```go
func maxValueOfCoins(piles [][]int, k int) int {
	f := make([]int, k+1)
	for _, nums := range piles {
		s := make([]int, len(nums)+1)
		for j := 1; j <= len(nums); j++ {
			s[j] = s[j-1] + nums[j-1]
		}
		for j := k; j >= 0; j-- {
			for h := 0; h < len(s) && h <= j; h++ {
				f[j] = max(f[j], f[j-h]+s[h])
			}
		}
	}
	return f[k]
}
```

#### TypeScript

```ts
function maxValueOfCoins(piles: number[][], k: number): number {
    const f: number[] = Array(k + 1).fill(0);
    for (const nums of piles) {
        const s: number[] = Array(nums.length + 1).fill(0);
        for (let j = 1; j <= nums.length; j++) {
            s[j] = s[j - 1] + nums[j - 1];
        }
        for (let j = k; j >= 0; j--) {
            for (let h = 0; h < s.length && h <= j; h++) {
                f[j] = Math.max(f[j], f[j - h] + s[h]);
            }
        }
    }
    return f[k];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2219. 数组的最大总分 🔒](https://leetcode.cn/problems/maximum-sum-score-of-array){#2219}

{{< tabs "2219" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumSumScore(self, nums: List[int]) -> int:
        l, r = 0, sum(nums)
        ans = -inf
        for x in nums:
            l += x
            ans = max(ans, l, r)
            r -= x
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long maximumSumScore(int[] nums) {
        long l = 0, r = 0;
        for (int x : nums) {
            r += x;
        }
        long ans = Long.MIN_VALUE;
        for (int x : nums) {
            l += x;
            ans = Math.max(ans, Math.max(l, r));
            r -= x;
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
    long long maximumSumScore(vector<int>& nums) {
        long long l = 0, r = accumulate(nums.begin(), nums.end(), 0LL);
        long long ans = -1e18;
        for (int x : nums) {
            l += x;
            ans = max({ans, l, r});
            r -= x;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumSumScore(nums []int) int64 {
	l, r := 0, 0
	for _, x := range nums {
		r += x
	}
	ans := math.MinInt64
	for _, x := range nums {
		l += x
		ans = max(ans, max(l, r))
		r -= x
	}
	return int64(ans)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumSumScore(nums: number[]): number {
    let l = 0;
    let r = nums.reduce((a, b) => a + b, 0);
    let ans = -Infinity;
    for (const x of nums) {
        l += x;
        ans = Math.max(ans, l, r);
        r -= x;
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn maximum_sum_score(nums: Vec<i32>) -> i64 {
        let mut l = 0;
        let mut r: i64 = nums.iter().map(|&x| x as i64).sum();
        let mut ans = std::i64::MIN;
        for &x in &nums {
            l += x as i64;
            ans = ans.max(l).max(r);
            r -= x as i64;
        }
        ans
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var maximumSumScore = function (nums) {
    let l = 0;
    let r = nums.reduce((a, b) => a + b, 0);
    let ans = -Infinity;
    for (const x of nums) {
        l += x;
        ans = Math.max(ans, l, r);
        r -= x;
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

<p>给你一个下标从 <strong>0</strong> 开始的整数数组 <code>nums</code> ，数组长度为 <code>n</code> 。</p>

<p><code>nums</code> 在下标 <code>i</code> （<code>0 &lt;= i &lt; n</code>）处的 <strong>总分</strong> 等于下面两个分数中的 <strong>最大值</strong> ：</p>

<ul>
	<li><code>nums</code><strong> 前</strong> <code>i + 1</code> 个元素的总和</li>
	<li><code>nums</code> <strong>后</strong> <code>n - i</code> 个元素的总和</li>
</ul>

<p>返回数组 <code>nums</code> 在任一下标处能取得的 <strong>最大总分</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [4,3,-2,5]
<strong>输出：</strong>10
<strong>解释：</strong>
下标 0 处的最大总分是 max(4, 4 + 3 + -2 + 5) = max(4, 10) = 10 。
下标 1 处的最大总分是 max(4 + 3, 3 + -2 + 5) = max(7, 6) = 7 。
下标 2 处的最大总分是 max(4 + 3 + -2, -2 + 5) = max(5, 3) = 5 。
下标 3 处的最大总分是 max(4 + 3 + -2 + 5, 5) = max(10, 5) = 10 。
nums 可取得的最大总分是 10 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [-3,-5]
<strong>输出：</strong>-3
<strong>解释：</strong>
下标 0 处的最大总分是 max(-3, -3 + -5) = max(-3, -8) = -3 。
下标 1 处的最大总分是 max(-3 + -5, -5) = max(-8, -5) = -5 。
nums 可取得的最大总分是 -3 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>5</sup> &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前缀和

我们可以使用两个变量 $l$ 和 $r$ 分别表示数组的前缀和和后缀和，初始时 $l = 0$, $r = \sum_{i=0}^{n-1} \textit{nums}[i]$。

接下来，我们遍历数组 $\textit{nums}$，对于每个元素 $x$，我们将 $l$ 增加 $x$，并更新答案 $\textit{ans} = \max(\textit{ans}, l, r)$，然后将 $r$ 减少 $x$。

遍历结束后，返回答案 $\textit{ans}$ 即可。

时间复杂度 $O(n)$，其中 $n$ 是数组 $\textit{nums}$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumSumScore(self, nums: List[int]) -> int:
        l, r = 0, sum(nums)
        ans = -inf
        for x in nums:
            l += x
            ans = max(ans, l, r)
            r -= x
        return ans
```

#### Java

```java
class Solution {
    public long maximumSumScore(int[] nums) {
        long l = 0, r = 0;
        for (int x : nums) {
            r += x;
        }
        long ans = Long.MIN_VALUE;
        for (int x : nums) {
            l += x;
            ans = Math.max(ans, Math.max(l, r));
            r -= x;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long maximumSumScore(vector<int>& nums) {
        long long l = 0, r = accumulate(nums.begin(), nums.end(), 0LL);
        long long ans = -1e18;
        for (int x : nums) {
            l += x;
            ans = max({ans, l, r});
            r -= x;
        }
        return ans;
    }
};
```

#### Go

```go
func maximumSumScore(nums []int) int64 {
	l, r := 0, 0
	for _, x := range nums {
		r += x
	}
	ans := math.MinInt64
	for _, x := range nums {
		l += x
		ans = max(ans, max(l, r))
		r -= x
	}
	return int64(ans)
}
```

#### TypeScript

```ts
function maximumSumScore(nums: number[]): number {
    let l = 0;
    let r = nums.reduce((a, b) => a + b, 0);
    let ans = -Infinity;
    for (const x of nums) {
        l += x;
        ans = Math.max(ans, l, r);
        r -= x;
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn maximum_sum_score(nums: Vec<i32>) -> i64 {
        let mut l = 0;
        let mut r: i64 = nums.iter().map(|&x| x as i64).sum();
        let mut ans = std::i64::MIN;
        for &x in &nums {
            l += x as i64;
            ans = ans.max(l).max(r);
            r -= x as i64;
        }
        ans
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var maximumSumScore = function (nums) {
    let l = 0;
    let r = nums.reduce((a, b) => a + b, 0);
    let ans = -Infinity;
    for (const x of nums) {
        l += x;
        ans = Math.max(ans, l, r);
        r -= x;
    }
    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
